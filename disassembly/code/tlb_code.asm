base origin()
seg_tlbcode_start:
base $7F000000
tlb_code_vaddr_start:

insert binarytlbcode, "tlb_code.bin", (origin() - $34B30)

tlb_code_vaddr_end:
base origin()
seg_tlbcode_end:

variable seg_tlbcode_size(seg_tlbcode_end-seg_tlbcode_start)

