@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata


gMoveEffectBS_Ptrs:: @ 831C224
	.incbin "baserom.gba", 0x31c224, 0xa4

gUnknown_0831C2C8:: @ 831C2C8
	.incbin "baserom.gba", 0x31c2c8, 0x20

gUnknown_0831C2E8:: @ 831C2E8
	.incbin "baserom.gba", 0x31c2e8, 0xd8

gUnknown_0831C3C0:: @ 831C3C0
	.incbin "baserom.gba", 0x31c3c0, 0x18

sProtectSuccessRates:: @ 831C3D8
	.incbin "baserom.gba", 0x31c3d8, 0x8

gUnknown_0831C3E0:: @ 831C3E0
	.incbin "baserom.gba", 0x31c3e0, 0x28

gUnknown_0831C408:: @ 831C408
	.incbin "baserom.gba", 0x31c408, 0xc

gUnknown_0831C414:: @ 831C414
	.incbin "baserom.gba", 0x31c414, 0x14

gUnknown_0831C428:: @ 831C428
	.incbin "baserom.gba", 0x31c428, 0x18

@ 831C440
	.include "data/pickup_items.inc"

sTerrainToType:: @ 831C483
	.incbin "baserom.gba", 0x31c483, 0xa

sBallCatchBonuses:: @ 831C48D
	.incbin "baserom.gba", 0x31c48d, 0x7

gUnknown_0831C494:: @ 831C494
	.incbin "baserom.gba", 0x31c494, 0x64

gUnknown_0831C4F8:: @ 831C4F8
	.incbin "baserom.gba", 0x31c4f8, 0x1c

