### test files readme ###

This is a tool suite to identify discrepancies between builds. It will extract relevant sections from ELF binary and compare against known good md5. The purpose is to help identify where the build is failing to match.

### Quick start ###

    ./test_files.sh -i ge007.u-test_basis.csv

### Overview ###

This consists of two bash scripts:

    make_test_files_basis.sh
    test_files.sh

The first is used to generate a list of md5 checksums. This should only be used if a new build is added, or you want to generate checksums against a particular variant.

### Making test file ###

Output format is simple csv, one entry per line. Each line is a 32 character md5, the name of section extracted from ELF binary, and path to file relative from repo root (where this script is).

Escaped csv, quotes or commas in filenames are not supported.

The script iterates the following build directories, looking for `.o` files:

- src/
- src/game
- assets/obseg/bg
- assets/obseg/brief
- assets/obseg/setup
- assets/obseg/stan
- assets/obseg/text

For source files, the following ELF sections are extracted:

- .text
- .code
- .bss
- .data
- .rodata

For asset files, the following ELF sections are extracted:

- .bss
- .data
- .rodata

The supported versions have already had the md5 checksums extracted from known good builds. These files are:

- ge007.u-test_basis.csv
- ge007.j-test_basis.csv
- ge007.e-test_basis.csv

**build test file example**

    ./make_test_files_basis.sh -v u -o ge007.u-test_basis.csv
    ./make_test_files_basis.sh -v j -o ge007.j-test_basis.csv
    ./make_test_files_basis.sh -v e -o ge007.e-test_basis.csv

### Testing build ###

A build can be compared against a test file by running `./test_files.sh`. The input file is required. This will This lists the path to the build object files. Example

    ./test_files.sh -i ge007.u-test_basis.csv

This lists each section and file as it is tested. You should see output like

    ...
    pass: section'.bss' build/u/assets/obseg/text/LsiloJ.o
    pass: section'.data' build/u/assets/obseg/text/LsiloJ.o
    pass: section'.rodata' build/u/assets/obseg/text/LsiloJ.o
    pass: section'.bss' build/u/assets/obseg/text/LstatE.o
    pass: section'.data' build/u/assets/obseg/text/LstatE.o
    ...

The output stops on the first failure. Use option `-c` to continue on mismatch.

### Examples ###

**Rename function**:

Modify `src/game/bg.c` method `bgRectIsInside` (an unreferenced method).

*result*: all files pass.

**Change function**:

Modify `src/game/bg.c` method `bgRectIsInside` (an unreferenced method) to return a different value. Rebuild the project and test.

*result*: Test script should stop with a message similar to the following:

    checksums differ, section'.text', file: 'build/u/src/game/bg.o'. Actual=[6747949109773c07983a2584101ef214], expected=[0a3e9300d0406ae8036a97b5596f3f5c]

**change .rodata**

Modify `src/fr.c` method `indyGrabJpg16bit` and change one of the printf strings:

    sprintf(buffer, "zzzgrab.%d.jpeg", *pgrabnum);

*result*: Test script should stop with a message similar to the following:

    checksums differ, section'.rodata', file: 'build/u/src/fr.o'. Actual=[9e108ace3e0dab31c819d22ed1d063b9], expected=[94e2bec0d83b53385ba626feb3005cb4]

**Change setup file**

Modify `assets/obseg/setup/Ump_setupcaveZ.c` padlist and change one of the float variables. Here is modifying the first entry in the array:

    { {1.0f, -726.0f, -378.0f}, {0.0f, 1.0f, 0.0f}, {-2e-06, 0.0f, 1.0f}, "p1884a", 0 },

*result*: Test script should stop with a message similar to the following:

    checksums differ, section'.data', file: 'build/u/assets/obseg/setup/Ump_setupcaveZ.o'. Actual=[1dd1b59ed38408ba67b6616f9194c6d9], expected=[9caabe90e7f9b62668b607b286e14738]
