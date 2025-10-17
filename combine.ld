MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 2M - 128k
}

SECTIONS
{
  /* Place the bootloader at the start */
  .bootloader 0x08000000 : 
  {
    KEEP(*(.bootloader))
  } > FLASH

  /* Reserve 1 KB at 0x08020000 for configbl (size + CRC + padding) */
  .configbl  0x08020000 :
  {
    KEEP(*(.configbl))
  } > FLASH

  /* Place the application at the specified offset */
  .application 0x08020400 : 
  {
    KEEP(*(.application))
  } > FLASH
}