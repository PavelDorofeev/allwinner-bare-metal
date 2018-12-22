#include "system.h"

void udelay(uint32_t d) {
  for(int n=0;n<d*228;n++) asm("NOP");
}

void reboot(uint32_t seconds) {
  WDOG0_MODE_REG = (seconds << 3) | 3;
}