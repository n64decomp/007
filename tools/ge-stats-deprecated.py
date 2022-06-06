import re
import os
import sys
import subprocess
import shlex
import getopt


# --------------------------
# Read Map File and return
# all function lenghts
# --------------------------
def parse_map(version):

    if version not in ("us", "jp"):
        print('fatal: version', version, 'not supported!')
        sys.exit(2)
    
    version_code = version[0]

    infile = False
    prevromaddr = 0
    lengths = {}

    p1 = re.compile(r"^ \.text\s+0x00000000([0-9a-f]{8})\s+0x([0-9a-f]+)\s+build\/" + re.escape(version_code) + r"\/(.*)\/\S+.\w$")
    p2 = re.compile(r"\s+0x00000000([0-9a-f]{8})\s+(\S+)$")

    map_file = open('build/ge007.' + version_code + '.map', 'r')
    lines = map_file.readlines()

    for line in lines:

        m1 = p1.findall(line)
        m2 = p2.findall(line)

        if m1:
            filestart = int(m1[0][0], 16)
            filelen = int(m1[0][1], 16)
            segment = m1[0][2]
            infile = True
            prevromaddr = 0
            prevfuncname = None

            if segment not in lengths.keys():
                lengths[segment] = {}

        elif infile and m2:
            romaddr = int(m2[0][0], 16)
            funcname = m2[0][1]

            if prevfuncname:
                lengths[segment][prevfuncname] = romaddr - prevromaddr

            prevromaddr = romaddr
            prevfuncname = funcname

        elif infile:
            infile = False

            if prevfuncname:
                lengths[segment][prevfuncname] = (filestart + filelen) - prevromaddr

    return lengths

# --------------------------
# Find and return all
# ASM Function names that still
# exists in Source Files 
# Only scans for C and S files
# --------------------------
def find_asm_functions(version):
    
    p1 = re.compile(r"^glabel (\S+)$")
    p2 = re.compile(r"^#ifdef VERSION_(\S+)$")
    p3 = re.compile(r"^#endif$")

    asm_functions = []
    version = version.upper()
    func_version = None

    for root, dirs, files in os.walk('src'):
        for file in files:
            if file.endswith(".c") or file.endswith(".s"):
                func_version = None
                with open(os.path.join(root, file)) as _file:
                    for i, line in enumerate(_file.readlines()):  
                        
                        m1 = p1.findall(line)
                        m2 = p2.findall(line)
                        m3 = p3.findall(line)

                        # Found an #endif command
                        if m3: 
                            func_version = None

                        # Found a version definition
                        elif m2:
                            func_version = m2[0]

                        # Found an asm function
                        elif m1:
                            if not func_version or (func_version == version):
                                asm_functions.append(m1[0])
                            
                            func_version = None

    return asm_functions

# --------------------------
# Find and return the number of completed files
# Only scans for C and S files
# --------------------------
def find_files_completed():
    
    p = re.compile(r"^glabel (\S+)$")
    files_complete = {}

    files_complete['completed'] = 0
    files_complete['total'] = 0

    for root, dirs, files in os.walk('src'):
        for file in files:
            if file.endswith(".c") or file.endswith(".s"):
                with open(os.path.join(root, file)) as _file:
                    
                    completed = True
                    files_complete['total'] += 1
                    
                    for i, line in enumerate(_file.readlines()):
                        if p.findall(line):
                            completed = False
                            break
                    
                    if completed:
                        files_complete['completed'] += 1

    return files_complete

# --------------------------
# Find and return the Name of most recent file
# Only scans for C and S files
# --------------------------
def find_last_modified_file():
    lastdate = 0
    lastname = ''
    timestamp = 0

    for root, dirs, files in os.walk('src'):
        for file in files:
            if file.endswith(".c") or file.endswith(".s"):
                _file = os.path.join(root, file)

                result = subprocess.run(['git', 'log', '-1', '--format=\"%ct\"', '--', _file], stdout=subprocess.PIPE, universal_newlines=True)

                timestamp = int(result.stdout.rstrip().replace('"', ''))

                if timestamp > lastdate:
                    lastdate = timestamp
                    lastname = _file

    return lastname

# --------------------------
# Calculate the decomp stats
# on each folder
# --------------------------
def do_stats(version, map_file, analyse_folders):

    asm_functions = find_asm_functions(version)
    segments = {}

    for folder in analyse_folders:

        segments[folder] = {}
        segments[folder]['done'] = 0
        segments[folder]['left'] = 0
        segments[folder]['total'] = 0
        
        num_done = 0
        num_left = 0

        for function in map_file[folder]:
            if function in asm_functions:
                num_left += map_file[folder][function]
            else:
                num_done += map_file[folder][function]
        
        segments[folder]['done'] = num_done / 4
        segments[folder]['left'] = num_left / 4
        segments[folder]['total'] = segments[folder]['done'] + segments[folder]['left']

    return segments

def generate_report(segments, files_completed, last_modified_file, Ver):
    printstring = "./tools/report/report "

    totals = {}
    totals['done'] = 0
    totals['total'] = 0

    for key in segments.keys():
        printstring = printstring + str(segments[key]['done']) + ' ' + str(segments[key]['total']) + ' '
        totals['done'] += segments[key]['done']
        totals['total'] += segments[key]['total']

    printstring = printstring + str(totals['done']) + ' ' + str(totals['total']) + ' '
    printstring = printstring + str(files_completed['completed']) + ' ' + str(files_completed['total']) + ' '
    printstring = printstring + './tools/report/template.html '
    if Ver.upper() in ("US"):
        printstring = printstring + './tools/report/index.html ' + last_modified_file + ' 0'
    elif Ver.upper() in ("JP"):
        printstring = printstring + './tools/report/JPN.htm ' + last_modified_file + ' 0'
    else:
        printstring = printstring + './tools/report/index.html ' + last_modified_file + ' 0'
    subprocess.Popen(printstring.split()) 

def print_stats(version, segments, files_completed, last_modified_file):
    totals = {}
    totals['done'] = 0
    totals['total'] = 0

    print()
    print('~> Decomp Statistics for ' + version.upper() +' version')
    print('__________________________________________________________________')
    print()

    print('FILES')
    print('\tlast modified file\t' + last_modified_file )
    print('\ttotal files\t{:10,} / {:,} \t{:.2f}%'.format(int(files_completed['completed']), int(files_completed['total']), (files_completed['completed'] / files_completed['total'] * 100)))
    
    print('__________________________________________________________________')
    print()

    print('WORDS')
    for key in segments.keys():
        print('\t{:10}\t{:10,} / {:,} \t{:.2f}%'.format(key, int(segments[key]['done']), int(segments[key]['total']), (segments[key]['done'] / segments[key]['total'] * 100)))
        totals['done'] += segments[key]['done']
        totals['total'] += segments[key]['total']

    print('\t----------------------------------------------------------')
    print('\tTOTAL\t\t{:10,} / {:,} \t{:.2f}%'.format(int(totals['done']), int(totals['total']), (totals['done'] / totals['total'] * 100)))
    print('__________________________________________________________________')
    print()

def print_help():
    print('Usage: python3 ge-stats.py [OPTION]')
    print('Generate Decompilation Stats for Goldeneye 007')
    print('Example: python3 ge-stats.py --version us')
    print(' ')
    print('Options:')
    print('  -v, --version=CODE     generate decomp stats for version CODE (us or jp). Default is us')
    print('  -r, --report           generate html report using report tool')
    print('  -h, --help             display this help text and exit')

def main():

    version = 'us'
    run_report = False

    if (len(sys.argv) > 1):
        arguments, values = getopt.getopt(sys.argv[1:], "hv:r", ["help", "version=", "report"])

        for current_argument, current_value in arguments:
            if current_argument in ("-h", "--help"):
                print_help()
                sys.exit()
            elif current_argument in ("-v", "--version"):
                version = current_value
            elif current_argument in ("-r", "--report"):
                run_report = True

    files_completed = find_files_completed()

    last_modified_file = find_last_modified_file()
    
    map_file = parse_map(version)
    
    folders = ['src', 'src/game', 'src/inflate', 'src/libultra']
    
    segments = do_stats(version, map_file, folders)

    print_stats(version, segments, files_completed, last_modified_file)

    if run_report:
        generate_report(segments, files_completed, last_modified_file, version)

if __name__ == '__main__':
    main()
