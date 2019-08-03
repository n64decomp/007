#include "ultra64.h"
#include "hardware.h"


u32 osPiGetStatus(void){
  return HW_REG(PI_STATUS_REG);
}
