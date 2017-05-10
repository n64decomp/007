include "bg.asm"
include "chr.asm"
include "g_items.asm"
include "props.asm"
include "Tbg.asm"
include "brief.asm"
include "setup.asm"
include "text.asm"

ob_end:
insert ob_end.seg, "ob_end.seg", (origin() - $008f7de0)
