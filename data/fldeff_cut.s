    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0857C608:: @ 857C608
	.incbin "baserom.gba", 0x57c608, 0x2

gUnknown_0857C60A:: @ 857C60A
	.incbin "baserom.gba", 0x57c60a, 0x5a

	.align 2
gFieldEffectObjectPaletteInfo6:: @ 857C664
	obj_pal gFieldEffectObjectPalette6, 0x1000

gUnknown_0857C66C:: @ 857C66C
	.incbin "baserom.gba", 0x57c66c, 0x18
