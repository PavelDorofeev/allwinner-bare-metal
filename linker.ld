SECTIONS
{
  . = 0x4e000000;
  .text : {
    boot.o(.text)
    *(.text)
  }
  .bss : {
    _bstart1 = . ;
    *(.bss); *(COMMON);
    _bend1 = . ;
  }
  .data :  {
    *(.data)
  }
  .uncached 0x50000000 : {
    _bstart2 = . ;
    *(UNCACHED);
    _bend2 = . ;
  }
}
