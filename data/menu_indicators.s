	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_086141FC:: @ 86141FC
	.incbin "baserom.gba", 0x6141fc, 0x48

gUnknown_08614244:: @ 8614244
	.incbin "baserom.gba", 0x614244, 0x18

gUnknown_0861425C:: @ 861425C
	.4byte 0x00000000

gUnknown_08614260:: @ 8614260
	.4byte 0x00100000

gUnknown_08614264:: @ 8614264
	.4byte 0x00200000

gUnknown_08614268:: @ 8614268
	.4byte 0x00300000

gUnknown_0861426C:: @ 861426C
	.4byte 0x00400000

gUnknown_08614270:: @ 8614270
	.4byte 0x00500000

gUnknown_08614274:: @ 8614274
	.4byte 0x00600000

gUnknown_08614278:: @ 8614278
	.4byte 0x00700000

gUnknown_0861427C:: @ 861427C
	.incbin "baserom.gba", 0x61427C, 0x14

gUnknown_08614290:: @ 8614290
	.incbin "baserom.gba", 0x614290, 0x18

gUnknown_086142A8:: @ 86142A8
	.incbin "baserom.gba", 0x6142a8, 0x20

gUnknown_086142C8:: @ 86142C8
	.incbin "baserom.gba", 0x6142c8, 0x70

gUnknown_08614338:: @ 8614338
	.incbin "baserom.gba", 0x614338, 0x40

gUnknown_08614378:: @ 8614378
	.incbin "baserom.gba", 0x614378, 0x44
