__sdram_base__           = ORIGIN(sdram);
__sdram_size__           = LENGTH(sdram);
__sdram_end__            = __sdram_base__ + __sdram_size__;
__config_base__		= ORIGIN(config);
__config_size__		= LENGTH(config);
__config_end__		= __config_base__ + __config_size__;

SECTIONS
{
    .sdram_init : ALIGN(4)
    {
        __sdram_init_text__ = LOADADDR(.sdram_init);
        __sdram_init__ = .;
        KEEP(*(.sdram_init))
        KEEP(*(.sdram_init.*))
        . = ALIGN(4);
    } > sdram AT > RAM_INIT_FLASH_LMA

    .sdram (NOLOAD) : ALIGN(4)
    {
        __sdram_clear__ = .;
        *(.sdram_clear)
        *(.sdram_clear.*)
        . = ALIGN(4);
        __sdram_noinit__ = .;
        *(.sdram)
        *(.sdram.*)
        . = ALIGN(4);
        __sdram_free__ = .;
    } > sdram
}