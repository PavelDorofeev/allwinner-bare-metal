#include <stdint.h>

void mmu_init() {

  // Disable MMU
  asm("ldr r8, =0x0;    mcr p15, 0, r8, c1, c0, 0;" : : : "r8");

  // Populate the pagetable
  int n;
  for(n=0;n<4096;n++)
  {
    *(volatile uint32_t *)(0x4000 + n*4) = (n<<20) | (0<<12) | (3<<10) | (0<<2) | 2;
  }

  // Set up the pagetable
  asm("ldr r8, =0x4000; mcr p15, 0, r8, c2, c0, 0" : : : "r8");
  asm("ldr r8, =0x0;    mcr p15, 0, r8, c2, c0, 2" : : : "r8");
  asm("ldr r8, =0x3;    mcr p15, 0, r8, c3, c0, 0" : : : "r8");

  // Enable MMU
  asm(
    "ldr r8, =0x0;"
    "MCR p15, 0, r8, c8, C3, 0;"
    "MCR p15, 0, r8, c8, C5, 0;"
    "MCR p15, 0, r8, c8, C6, 0;"
    "MCR p15, 0, r8, c8, C7, 0;"
    "mcr p15, 0, r8, c12, c0, 0;"

    "ldr r8, =0x1005;"
    "mcr p15, 0, r8, c1, c0, 0;"
    : : : "r8");

}