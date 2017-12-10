	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2

sPokeblocksPals:: @ 85F0568
	.incbin "baserom.gba", 0x5f0568, 0x48

sSpriteAffineAnimTable_85F05B0:: @ 85F05B0
	.incbin "baserom.gba", 0x5f05b0, 0xb4

sSpriteAffineAnimTable_85F0664:: @ 85F0664
	.incbin "baserom.gba", 0x5f0664, 0x4

sSpriteAffineAnimTable_85F0668:: @ 85F0668
	.incbin "baserom.gba", 0x5f0668, 0x4

sSpriteAffineAnimTable_85F066C:: @ 85F066C
	.incbin "baserom.gba", 0x5f066c, 0x34

gPokeblock_SpriteSheet:: @ 85F06A0
	.incbin "baserom.gba", 0x5f06a0, 0x8

sThrownPokeblockSpriteTemplate:: @ 85F06A8
	.incbin "baserom.gba", 0x5f06a8, 0x18
