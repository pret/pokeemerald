	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085F5490:: @ 85F5490
	.incbin "baserom.gba", 0x5f5490, 0x4

gUnknown_085F5494:: @ 85F5494
	.incbin "baserom.gba", 0x5f5494, 0x4d40

gUnknown_085FA1D4:: @ 85FA1D4
	.incbin "baserom.gba", 0x5fa1d4, 0x4

gUnknown_085FA1D8:: @ 85FA1D8
	.incbin "baserom.gba", 0x5fa1d8, 0xff90

gUnknown_0860A168:: @ 860A168
	.incbin "baserom.gba", 0x60a168, 0x1b8

gUnknown_0860A320:: @ 860A320
	.incbin "baserom.gba", 0x60a320, 0x8c

gUnknown_0860A3AC:: @ 860A3AC
	.incbin "baserom.gba", 0x60a3ac, 0x30

gUnknown_0860A3DC:: @ 860A3DC
	.incbin "baserom.gba", 0x60a3dc, 0xd0
