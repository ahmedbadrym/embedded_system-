MEMORY
{
    flash(rx) : ORIGIN = 0x00000000, LENGTH = 512M
    sram(rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
    .text :
    {
        _text_start = .;

        *(.vectors*)
        *(.text*)
        *(.rodata)

        _text_end = .;
    } > flash

    .data :
    {
        _s_data = .;
        *(.data)
     . = ALIGN(4);
        _e_data = .;
    } > sram AT > flash

    .bss :
    {
        _s_bss = .;
        *(.bss*)
        _e_bss = .;
            
    } > sram
}