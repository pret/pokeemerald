@ the fourth big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gPokeblockFlavorCompatibilityTable:: @ 85B25A0
	.incbin "baserom.gba", 0x5b25a0, 0x80

gUnknown_085B2620:: @ 85B2620
	.incbin "baserom.gba", 0x5b2620, 0xc

gPokeblockNames:: @ 85B262C
	.incbin "baserom.gba", 0x5b262c, 0x3c

gUnknown_085B2668:: @ 85B2668
	.incbin "baserom.gba", 0x5b2668, 0x30

gUnknown_085B2698:: @ 85B2698
	.incbin "baserom.gba", 0x5b2698, 0x3

gUnknown_085B269B:: @ 85B269B
	.incbin "baserom.gba", 0x5b269b, 0x2

gUnknown_085B269D:: @ 85B269D
	.incbin "baserom.gba", 0x5b269d, 0x2

gUnknown_085B269F:: @ 85B269F
	.incbin "baserom.gba", 0x5b269f, 0x5

gUnknown_085B26A4:: @ 85B26A4
	.incbin "baserom.gba", 0x5b26a4, 0x4c

gUnknown_085B26F0:: @ 85B26F0
	.incbin "baserom.gba", 0x5b26f0, 0x4

gPokeblockCase_SpriteSheet:: @ 85B26F4
	.incbin "baserom.gba", 0x5b26f4, 0x8

gPokeblockCase_SpritePal:: @ 85B26FC
	.incbin "baserom.gba", 0x5b26fc, 0x8

gUnknown_085B2704:: @ 85B2704
	.incbin "baserom.gba", 0x5b2704, 0x18

gUnknown_085B271C:: @ 85B271C
	.incbin "baserom.gba", 0x5b271c, 0x4

gUnknown_085B2720:: @ 85B2720
	.incbin "baserom.gba", 0x5b2720, 0x28
