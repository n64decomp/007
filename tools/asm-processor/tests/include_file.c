GLOBAL_ASM("tests/include_file_1.s")
#pragma GLOBAL_ASM("tests/include_file_2.s")
INCLUDE_ASM("tests", include_file_3);
INCLUDE_RODATA("tests/", include_file_4);
#if 0
GLOBAL_ASM("tests/nonexisting.s");
INCLUDE_ASM("tests", nonexisting);
#endif
