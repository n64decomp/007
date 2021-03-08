#include "ultra64.h"
#include "game/image.h"

void set_mt_tex_alloc(void)
{  
  dword_CODE_bss_8008D090 = 0;

  if (tokenFind(1, "-mt"))
  {
    bytes = strtol(tokenFind(1, "-mt"), 0x0, 0) << 10;
  }

  sub_GAME_7F0CBAF4(&ptr_texture_alloc_start, mempAllocBytesInBank(bytes, 4), bytes);
}
