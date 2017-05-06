base $7F000000
tlb_code_start:

insert binarytlbcode, "tlb_code.bin", (origin() - $34B30)
tlb_code_end:
