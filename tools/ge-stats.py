import datetime
import errno
import functools
import getopt
import os
import re
import shlex
import socket
import subprocess
import sys
import time

"""
re-writing the original ge-stats py. - Ben Burns, Dec 18, 2021

The general approach is to scan for source files in the specified directories (*.s, *.c).
Each file is evaluated, and a list of assembly function definitions is generated.
The map file is then parsed, giving a list of all known functions.
Stats are then computed for asm functions out of all known functions.

The logic to determine whether a function has an assembly definition is rather simple.
It doesn't handle any c preprocessor macros, so the results are not guaranteed to
be accurate. If a line begins with the text "glabel" and is only followed by one
word, that is assumed to be an assembly function definition. For the purposes
of this script, any assembly definition for any ROM version will count against
the total.
"""

# lower case
__supported_versions = ['us', 'jp', 'eu']

# any function read from .map file exceeding this size will throw an exception
__invalid_func_length_size = 1000000

# attempt to filter out extra glabels that are not function definitions. This is for jump table entries
__re_jpt_label = re.compile(r"\.L[0-9a-fA-F]{8}")

# report output paths
__report_dir =      "tools" + os.path.sep + "report"
__report_bin =      __report_dir + os.path.sep + "report"
__report_template = __report_dir + os.path.sep + "template.html"
__report_out_us =   __report_dir + os.path.sep + "index.html"
__report_out_jp =   __report_dir + os.path.sep + "JPN.htm"
__report_out_eu =   __report_dir + os.path.sep + "EU.htm"

# default fallback if recently modified timestamps don't work
__mtime_fallback_filename = 'ge.u.z64'

class FunctionInfo:
    """
    Info about a function
    """
    def __init__(self, name: str):
        # function name
        self.name = name
        # flag to indicate if an asm function definition exists
        self.nonmatching = False
        # length of function as computed from map file
        self.length = 0
        # parent SourceFileContent
        self.parent = None

    def __str__(self):
        return self.name

    def __repr__(self):
        return self.name


class SourceFileContent:
    """
    Information about a source file
    """
    def __init__(self, path: str):
        # path to file
        self.path = path
        # list of all asm function definitions found in the file
        self.asm_functions = set()
        # list of FunctionInfo as parsed from map file
        self.all_functions = []

        if path.endswith(".c") or path.endswith(".s") or path.endswith(".o"):
            self.path_without_ext = path[:-2]
        else:
            self.path_without_ext = path

        # reference to SearchDir
        self.parent = None
        # last modified time, in seconds since epoch
        self.mtime = 0

    def __str__(self):
        return self.path

    def __repr__(self):
        return self.path

    def __eq__(self, other): 
        if not isinstance(other, SourceFileContent):
            # don't attempt to compare against unrelated types
            return NotImplemented

        return self.path == other.path

class SearchDir:
    """
    container to define search paramaters.
    """
    def __init__(self, path: str, recurse: bool, ignore = None, completed = None):
        """
        default constructor

        :param str path: folder path, relative to root where script is run. Should not
            contain leading or trailing slash.
        :param bool recurse: whether or not to recursively search contents of path.
        :param ignore: optional files to ignore. List of strings. This is an explicit list of
            files with any necessary folder prefix. Do not include leading slash. Wildcards
            are not supported.
        :param completed: optional files to mark as completed. List of strings. This is an
            explicit list of files with any necessary folder prefix. Do not include leading
            slash. Wildcards are not supported.
        """
        self.path = path
        self.recurse = not not recurse
        # (config option) ignored files won't be added to source files
        if ignore is None:
            ignore = []
        self.ignore = ignore
        # (config option) completed files won't have asm definitions added
        if completed is None:
            completed = []
        self.completed = completed

        # (runtime stat) count of functions found in/under this directory
        self.function_count = 0
        # (runtime stat) length in bytes for all functions found
        self.function_byte_count = 0
        # (runtime stat) count of non matching functions found in/under this directory
        self.nonmatching_count = 0
        # (runtime stat) length in bytes for all non matching functions found
        self.nonmatching_byte_count = 0
        # (runtime stat) count of found files
        self.file_count = 0
        # (runtime stat) count of found files with no asm definitions
        self.completed_file_count = 0

        # fix path seperator if this is run on windows os (visual only, it will still run...)
        self.path = self.path.replace('/', os.path.sep)

    def __str__(self):
        return self.path

    def __repr__(self):
        return self.path

    def __eq__(self, other): 
        if not isinstance(other, SearchDir):
            # don't attempt to compare against unrelated types
            return NotImplemented

        return self.path == other.path


class StatResults:
    def __init__(self):
        # "now" starting point, modification times must be before this datetime.
        # Only applies to git log, OS modified time is unaffected.
        self.now = datetime.datetime.now()
        self.search_dirs = []
        # reference to SourceFileContent with highest mtime
        self.last_modified_file = None
        # status flag. Used to determine if last modified timestamps are valid.
        self.last_mtime_valid = False
        # count of all functions
        self.total_function_count = 0
        # length in bytes for all functions
        self.total_function_byte_count = 0
        # count of non matching functions
        self.total_nonmatching_count = 0
        # length in bytes for all non matching functions
        self.total_nonmatching_byte_count = 0
        # count of found files with no asm definitions
        self.total_completed_file_count = 0
        # list of SourceFileContent
        self.source_files = []



def mtime_os(file, now, qlocal = False):
    if not qlocal:
        print('using os')
    return int(os.path.getmtime(file))



def mtime_git(file, now, qlocal = False):
    if not qlocal:
        print('using git')
    try:
        date_str = now.strftime('%Y-%m-%dT%H:%M:%S%z')
        result = subprocess.run(['git', 'log', '-1', '--format=\"%ct\"', '--date=local', '--before=\"' + date_str + '\"', '--', file], stdout=subprocess.PIPE, universal_newlines=True)
    except:
        print ('fatal error reading git log history, maybe use OS modified time resolver, --mtime_os option. File: "' + file + '", date_str: "' + date_str + '"')
        sys.exit(7)

    log_out = result.stdout.strip().replace('"', '')
    if not log_out:
        return 0
    return int(log_out)


def process_source_files(search, stats: StatResults, mtime_resolver, qlocal = False):

    stats.search_dirs = search

    # regular expression: a line that starts with text "glabel", followed by
    # a single space, followed by (captured) anything that is not whitespace
    # one or more times, followed by end of line.
    p1 = re.compile(r"^glabel (\S+)$")

    # iterate each search location, looking inside source files for asm function definitions
    for s in search:
        if not os.path.isdir(s.path):
            print('fatal: directory not found:', s.path)
            sys.exit(3)

        for root, dir_names, filenames in os.walk(s.path):
            for filename in filenames:
                file = os.path.join(root, filename)

                if not (filename.lower().endswith(".c") or filename.lower().endswith(".s")):
                    continue

                if filename in s.ignore:
                    continue

                #print(file)

                sfc = SourceFileContent(file)

                sfc.asm_functions = set()
                sfc.parent = s
                sfc.mtime = mtime_resolver(file, stats.now, qlocal)
                import datetime

                x = datetime.datetime.fromtimestamp(sfc.mtime)
                if not qlocal:
                    print(sfc.path, ' = ', x.strftime('%c'))

                # The `completed` list is manually configured to specify which files should not be
                # counted against the total. This is done by simply not adding asm function
                # definitions into the asm_functions property.
                if filename not in s.completed:
                    with open(file) as fp:
                        # The "in" operator will be faster than regex here, but will include stuff
                        # we don't want. Do an initial pass with "in", then refine results with
                        # regex.
                        # The container is a hashset for cases where the function is
                        # declared multiple times (e.g., different versions)
                        file_glabel_lines = [line for line in fp.readlines() if "glabel" in line]
                        for line in file_glabel_lines:
                            r1 = p1.findall(line)
                            if r1 and len(r1) == 1 and not re.match(__re_jpt_label, r1[0]):
                                sfc.asm_functions.add(r1[0])

                stats.source_files.append(sfc)

            if not s.recurse:
                break

    return stats


def apply_build_map(stats: StatResults, version: str):
    """
    This iterates over the build map file.
    It scans for the start of a `.text` definition indicating a new file.
    Then it parses each following line to get function names within the file
    until a new section is encountered.
    """
    version_code = version[0]
    map_file_path = 'build' + os.path.sep + 'ge007.' + version_code + '.map'

    infile = False
    prevromaddr = 0

    # regex:
    # a line that starts with text " .text", followed by any whitespace (at least one), then a 64 bit hex address.
    # the lower 32 bits of the address are captured in a group. Followed by any whitespace (at least one),
    # followed by a hex address (capturing everything after "0x"), followed by any whitespace (at least one).
    # It then matches a build path, based on version, capturing everything after the version and slash
    # up to the file extension, followed by end of line.
    p1 = re.compile(r"^ \.text\s+0x00000000([0-9a-f]{8})\s+0x([0-9a-f]+)\s+build\/" + re.escape(version_code) + r"\/([^\s]+)$")

    # regex to match subsequent lines after the above regex matches. This will
    # match any whitespace, then 64 bit address (capturing the lower 32 bits), then
    # any whitespace (at least one), then capture the remaining non-whitespace-text until end of line (in capture group).
    # That last capture group is the function name.
    p2 = re.compile(r"^\s+0x00000000([0-9a-f]{8})\s+(\S+)$")

    current_sfc = None
    current_fi = None

    with open(map_file_path, 'r') as map_file:
        lines = map_file.readlines()

        for line in lines:

            m1 = p1.findall(line)
            m2 = p2.findall(line)

            # m1 match means this is a new .text section (new file)
            if m1:
                filestart = int(m1[0][0], 16)
                filelen = int(m1[0][1], 16)
                # normalize paths
                segment = (m1[0][2]).replace('/', os.path.sep)
                infile = True
                prevromaddr = 0
                prevfuncname = None

                current_fi = None

                if segment.endswith(".c") or segment.endswith(".s") or segment.endswith(".o"):
                    segment_without_ext = segment[:-2]
                else:
                    segment_without_ext = segment

                # get the SourceFileContent container for this file listing
                current_sfc = next((x for x in stats.source_files if x.path_without_ext == segment_without_ext), None)
                # if there's no existing reference, that means this function is listed
                # in the map file but not found when searching directories previously.
                # In that case, this file/function should be ignored.
                if current_sfc is None:
                    infile = False

            elif infile and m2:
                romaddr = int(m2[0][0], 16)
                funcname = m2[0][1]

                if re.match(__re_jpt_label, funcname):
                    continue

                if current_sfc is None:
                    print('invalid state: current_sfc not set')
                    sys.exit(4)

                if current_fi is not None:
                    current_fi.length = romaddr - prevromaddr
                    if current_fi.length > __invalid_func_length_size:
                        raise ValueError("function length too large: " + str(funcname) + " len = " + str(current_fi.length))

                # get the function info for this function, or create a new one
                current_fi = next((x for x in current_sfc.all_functions if x.name == funcname), None)
                if current_fi is None:
                    current_fi = FunctionInfo(funcname)
                    current_fi.parent = current_sfc
                    # check to see if there was an asm definition for this function
                    if funcname in current_sfc.asm_functions:
                        current_fi.nonmatching = True
                    current_sfc.all_functions.append(current_fi)

                prevromaddr = romaddr
                prevfuncname = funcname

            elif infile:
                infile = False

                # this is a one line definition in the map file
                if current_fi is None:
                    current_fi = FunctionInfo(funcname)
                    current_fi.parent = current_sfc
                    # check to see if there was an asm definition for this function
                    if funcname in current_sfc.asm_functions:
                        current_fi.nonmatching = True
                    # since this is only one entry, use the entire size
                    current_fi.length = filelen
                    current_sfc.all_functions.append(current_fi)
                else:
                    current_fi.length = (filestart + filelen) - prevromaddr
                
                if current_fi.length > __invalid_func_length_size:
                    raise ValueError("function length too large: " + str(funcname) + " len = " + str(current_fi.length))



def percent_complete(num, den):
    if not (den > 0):
        return 1
    elif num == den:
        return 1

    frac = num / den
    
    if frac <= 0:
        return 0
    elif frac > 0 and frac < 0.01:
        return 0.01
    elif frac >= 0.01 and frac <= 0.99:
        return frac
    elif frac >= 0.99 and frac < 1:
        return 0.99
    
    raise ValueError("Can't compute percent complete: " + str(num) + " / " + str(den))


def generate_default_stats(stats: StatResults):
    """
    Iterate each file, and each function in each file, to compute
    the total bytes/functions/files in each searchdir, and sum
    the totals for the entire search.
    """
    
    # track unique modification times
    seen_mtime = set()
    
    for file in stats.source_files:
        # if this file comes from the .map file and does not have the
        # parent association setup then it should be ignored.
        if file.parent is None:
            continue

        if stats.last_modified_file is None or stats.last_modified_file.mtime < file.mtime:
            stats.last_modified_file = file
        
        seen_mtime.add(file.mtime)

        for func in file.all_functions:
            file.parent.function_count += 1
            file.parent.function_byte_count += func.length
            stats.total_function_count += 1
            stats.total_function_byte_count += func.length

            if func.nonmatching:
                file.parent.nonmatching_count += 1
                file.parent.nonmatching_byte_count += func.length
                stats.total_nonmatching_count += 1
                stats.total_nonmatching_byte_count += func.length
        
        file.parent.file_count += 1

        if len(file.asm_functions) == 0:
            file.parent.completed_file_count += 1
            stats.total_completed_file_count += 1
            
    # More hacks to check for valid modification times.
    # 10 is an arbitrary number, but this says that if there are
    # at least 10 unique modification times, assume the timestamps
    # are valid. Otherwise this will fallbac kto show the default file.
    if len(seen_mtime) > 10:
        stats.last_mtime_valid = True

    # If it wasn't possible to determine recently modified file (i.e., github actions)
    # then fallback to "ge.u.z64"
    if not stats.last_mtime_valid:
        stats.last_modified_file = SourceFileContent(__mtime_fallback_filename)


def print_default_stats(stats: StatResults, version):

    print()
    print('~> Decomp Statistics for ' + version.upper() +' version')
    print('__________________________________________________________________')
    print()

    print('FILES')
    print('\trecently modified:')
    if stats.last_mtime_valid:
        recent_files = sorted(stats.source_files, key=lambda x: x.mtime, reverse=True)[:5]
        for rf in recent_files:
            print('\t\t' + rf.path)
    else:
        print('\t\t' + __mtime_fallback_filename)
    print()
    for s in stats.search_dirs:
        print('\t{:12}\t{:5,} / {:5,} \t{:6.2f}%'.format(s.path, int(s.completed_file_count), int(s.file_count), (percent_complete(s.completed_file_count, s.file_count) * 100)))
    print()
    print('\ttotal       \t{:5,} / {:5,} \t{:6.2f}%'.format(int(stats.total_completed_file_count), len(stats.source_files), (percent_complete(stats.total_completed_file_count, len(stats.source_files)) * 100)))
    print('__________________________________________________________________')
    print()

    print('FUNCTIONS')
    for s in stats.search_dirs:
        d_completed_func_count = s.function_count - s.nonmatching_count
        print('\t{:12}\t{:7,} / {:7,} \t{:6.2f}%'.format(s.path, int(d_completed_func_count), int(s.function_count), (percent_complete(d_completed_func_count, s.function_count) * 100)))
    print()
    print('\ttotal       \t{:7,} / {:7,} \t{:6.2f}%'.format(int(stats.total_nonmatching_count), int(stats.total_function_count), (percent_complete(stats.total_nonmatching_count, stats.total_function_count) * 100)))
    print('__________________________________________________________________')
    print()

    print('BYTES')
    for s in stats.search_dirs:
        d_completed_byte_count = s.function_byte_count - s.nonmatching_byte_count
        print('\t{:12}\t{:11,} / {:11,} \t{:6.2f}%'.format(s.path, int(d_completed_byte_count), int(s.function_byte_count), (percent_complete(d_completed_byte_count, s.function_byte_count) * 100)))
    print()
    completed_byte_count = stats.total_function_byte_count - stats.total_nonmatching_byte_count
    print('\ttotal       \t{:11,} / {:11,} \t{:6.2f}%'.format(int(completed_byte_count), int(stats.total_function_byte_count), (percent_complete(completed_byte_count, stats.total_function_byte_count) * 100)))
    print('__________________________________________________________________')
    print()



def print_non_matching_stats(stats: StatResults, version):
    """
    List all non matching functions. Sort by byte length.
    Print as csv of filename, function name, function length.
    """
    functions = []
    for file in stats.source_files:
        for func in file.all_functions:
            if func.nonmatching:
                functions.append(func)
    functions.sort(key=lambda x: x.length, reverse=True)
    try:
        print("filename, function, length")
        for f in functions:
            print(f.parent.path + ", " + f.name + ", " + str(f.length))
    except socket.error as e:
        if e.errno == errno.EPIPE:
            sys.exit(0)
        raise


def bytes_to_words(b):
    return (int(b) >> 2) << 2


def generate_report(stats: StatResults, version):
    """
    Send values over to the c report app.
    Arguments must be added in the following order:
    
        note: changing from "libultra" to "libultrare"

        SRC_DIR:              int, size in 32-bit words of completed functions, in src/ directory
	    SRC_DIR_MAX:          int, size in 32-bit words of all tracked functions, in src/ directory
	    GAME_DIR:             int, size in 32-bit words of completed functions, in src/game/ directory
	    GAME_DIR_MAX:         int, size in 32-bit words of all tracked functions, in src/game/ directory
	    INFLATE_DIR:          int, size in 32-bit words of completed functions, in src/inflate/ directory
	    INFLATE_DIR_MAX:      int, size in 32-bit words of all tracked functions, in src/inflate/ directory
	    LIBULTRA_DIR:         int, size in 32-bit words of completed functions, in src/libultrare/ directory
	    LIBULTRA_DIR_MAX:     int, size in 32-bit words of all tracked functions, in src/libultrare/ directory
	    DECOMPILED_WORDS:     int, size in 32-bit words of all completed functions
	    DECOMPILED_WORDS_MAX: int, size in 32-bit words of all tracked functions
	    DECOMPILED_FILES:     int, count of all fully completed files
	    DECOMPILED_FILES_MAX: int, count of all tracked files
	    HTML_TEMPLATE:        string: path to html template input file
	    HTML_OUTPUT:          string: path to generated html file
	    LAST_MODIFIED_FILE:   string: name of last modified file
	    LOG_LEVEL:            int (enum): LOG_MIN = 0, LOG_DEF, LOG_MAX

    """

    sd = next((x for x in stats.search_dirs if x.path == 'src'), None)
    if sd is None:
        raise ValueError('Could not find "src" SearchDir')
    src_dir = bytes_to_words(sd.function_byte_count - sd.nonmatching_byte_count)
    src_dir_max = bytes_to_words(sd.function_byte_count)

    sd = next((x for x in stats.search_dirs if x.path == 'src/game'), None)
    if sd is None:
        raise ValueError('Could not find "src/game" SearchDir')
    game_dir = bytes_to_words(sd.function_byte_count - sd.nonmatching_byte_count)
    game_dir_max = bytes_to_words(sd.function_byte_count)

    sd = next((x for x in stats.search_dirs if x.path == 'src/inflate'), None)
    if sd is None:
        raise ValueError('Could not find "src/inflate" SearchDir')
    inflate_dir = bytes_to_words(sd.function_byte_count - sd.nonmatching_byte_count)
    inflate_dir_max = bytes_to_words(sd.function_byte_count)

    # note: libultrare
    sd = next((x for x in stats.search_dirs if x.path == 'src/libultrare'), None)
    if sd is None:
        raise ValueError('Could not find "src/libultrare" SearchDir')
    libultrare_dir = bytes_to_words(sd.function_byte_count - sd.nonmatching_byte_count)
    libultrare_dir_max = bytes_to_words(sd.function_byte_count)

    decompiled_words = bytes_to_words(stats.total_function_byte_count - stats.total_nonmatching_byte_count)
    decompiled_words_max = bytes_to_words(stats.total_function_byte_count)

    decompiled_files = stats.total_completed_file_count
    decompiled_files_max = len(stats.source_files)

    if version == 'us':
        html_output = __report_out_us
    elif version == 'jp':
        html_output = __report_out_jp
    elif version == 'eu':
        html_output = __report_out_eu
    else:
        print('fatal: version', version, 'not supported! Supported versions are: ', ', '.join(__supported_versions))
        sys.exit(2)

    printstring = __report_bin + ' ' + \
        str(src_dir) + ' ' + \
        str(src_dir_max) + ' ' + \
        str(game_dir) + ' ' + \
        str(game_dir_max) + ' ' + \
        str(inflate_dir) + ' ' + \
        str(inflate_dir_max) + ' ' + \
        str(libultrare_dir) + ' ' + \
        str(libultrare_dir_max) + ' ' + \
        str(decompiled_words) + ' ' + \
        str(decompiled_words_max) + ' ' + \
        str(decompiled_files) + ' ' + \
        str(decompiled_files_max) + ' ' + \
        __report_template + ' ' + \
        html_output + ' ' + \
        stats.last_modified_file.path + ' ' + \
        '0'

    subprocess.Popen(printstring.split()) 


def print_help():
    print('Usage: python3 ge-stats2.py [OPTION]')
    print('Generate Decompilation Stats for Goldeneye 007')
    print('Example: python3 ge-stats2.py --version us')
    print(' ')
    print('  This script expects to be run from the root directory. There must be')
    print('  a map file in ./build/ge007.u.map (or equivalent version). Source files')
    print('  must be located in a folder in the root directory.')
    print(' ')
    print('  This script does not attempt to parse preprocessor definitions and')
    print('  ignores version differences in source files. For the purposes of these')
    print('  stats, any version with an asm definition of a function will count')
    print('  against completion. However, a version is still required to specify')
    print('  which build map to reference against.')
    print(' ')
    print('Options:')
    print('  -v, --version=CODE     generate decomp stats for version CODE (us, jp, or eu). Default is us')
    print('  -r, --report           generate html report using report tool')
    print('  -n, --non_matching     print csv of all non matching function definitions')
    print('  --mtime_os             use OS last modified time instead of git log')
    print('  -h, --help             display this help text and exit')
    print('  --qlocal               quiet "local" version. Disable all the extra print statements included for github actions.')

def main():
    # default to US version
    version = 'us'
    run_report = False
    print_method = 'default'
    mtime_use_os = False
    qlocal = False

    if (len(sys.argv) > 1):
        arguments, values = getopt.getopt(sys.argv[1:], "hv:rn", ["help", "version=", "report", "non_matching", "mtime_os", "qlocal"])

        for current_argument, current_value in arguments:
            if current_argument in ("-h", "--help"):
                print_help()
                sys.exit()
            elif current_argument in ("-v", "--version"):
                version = current_value.lower()
            elif current_argument in ("-r", "--report"):
                run_report = True
            elif current_argument in ("-n", "--non_matching"):
                print_method = 'non_matching'
            elif current_argument in ("--mtime_os"):
                mtime_use_os = True
            elif current_argument in ("--qlocal"):
                qlocal = True

    if version not in __supported_versions:
        print('fatal: version', version, 'not supported! Supported versions are: ', ', '.join(__supported_versions))
        sys.exit(2)

    if run_report:
        if not os.path.isfile(__report_bin):
            print('fatal: file not found: ' + __report_bin)
            sys.exit(6)

    # if this is just getting status on nonmatching files, ignore modified time lookup.
    if print_method == 'non_matching' and not run_report:
        mtime_use_os = True

    if not qlocal:
        print(subprocess.run(['git', 'diff', 'origin/master', '--name-only', '"@{10 minutes ago}"']).stdout)
    # Default to using git log to get the file's modified date.
    # Git log will be much slower, but cloning a new repo (i.e., github actions online)
    # will reset all the modified timestamps to the same value, so will need to
    # resolve the last modified time from git history.
    mtime_resolver = mtime_os
    if not mtime_use_os:
        if os.path.isdir('.git'):
            mtime_resolver = mtime_git
        else:
            # ok, do one last check (for github actions)
            try:
                result = subprocess.run(['git', 'log', '-1', '--format=\"%ct\"', '--', 'readme.md'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
                if result.returncode == 0:
                    mtime_resolver = mtime_git
            except:
                pass
    
    # files to count as complete, in src/ directory
    src_completed_list = [
        '_start.s',
        'aspboot.s',
        'bootcode.s',
        'getra.s',
        'gspboot.s',
        'osMapTLB.s',
        'rom_header.s',
        'rspboot.s',
        'tlb_hardwire.s',
        'tlb_resolve.s']

    search = []
    search.append(SearchDir('src', False, completed=src_completed_list))
    search.append(SearchDir('src/game', False))
    search.append(SearchDir('src/inflate', False))
    search.append(SearchDir('src/libultrare', True))

    stats = StatResults()

    process_source_files(search, stats, mtime_resolver, qlocal)
    apply_build_map(stats, version)
    generate_default_stats(stats)

    if print_method == 'default':
        print_default_stats(stats, version)
    elif print_method == 'non_matching':
        print_non_matching_stats(stats, version)

    if run_report:
        generate_report(stats, version)

if __name__ == '__main__':
    #start_time = time.time()
    main()
    #print("--- %s seconds ---" % (time.time() - start_time))
