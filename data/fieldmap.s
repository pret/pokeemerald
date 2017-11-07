    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08486EF8:: @ 8486EF8
@ replacing .incbin "baserom.gba", 0x00486ef8, 0x4
.4byte 0x00000000
