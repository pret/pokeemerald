	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085E7088:: @ 85E7088
	.incbin "graphics/misc/diploma.gbapal"
    .incbin "graphics/misc/diploma2.gbapal"

gUnknown_085E70C8:: @ 85E70C8
	.incbin "graphics/misc/diploma.bin.lz"

gUnknown_085E7804:: @ 85E7804
	.incbin "graphics/misc/diploma.4bpp.lz"

gUnknown_085E81FC:: @ 85E81FC
.4byte 0x000001f4, 0x00001261

gUnknown_085E8204:: @ 85E8204
window_template 0x00, 0x05, 0x02, 0x14, 0x10, 0x0f, 0x0001 
window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

gUnknown_085E8214:: @ 85E8214
.byte 0x00, 0x02, 0x03, 0x00

