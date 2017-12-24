	.include "asm/macros.inc"
	.include "constants/constants.inc"
	.include "include/constants/species.h"

	.section .rodata

gBirchBagGrassPal:: @ 85B0A00
	.incbin "baserom.gba", 0x5b0a00, 0x80

gBirchBagTilemap:: @ 85B0A80
	.incbin "baserom.gba", 0x5b0a80, 0x18c

gBirchGrassTilemap:: @ 85B0C0C
	.incbin "baserom.gba", 0x5b0c0c, 0x1f8

gBirchHelpGfx:: @ 85B0E04
	.incbin "baserom.gba", 0x5b0e04, 0xfc8

gUnknown_085B1DCC:: @ 85B1DCC
	.incbin "baserom.gba", 0x5b1dcc, 0x10

gUnknown_085B1DDC:: @ 85B1DDC
	.incbin "baserom.gba", 0x5b1ddc, 0x8

gUnknown_085B1DE4:: @ 85B1DE4
	.incbin "baserom.gba", 0x5b1de4, 0x8

sPokeballCoords:: @ 85B1DEC
	.incbin "baserom.gba", 0x5b1dec, 0x6

gStarterChoose_LabelCoords:: @ 85B1DF2
	.incbin "baserom.gba", 0x5b1df2, 0x6

sStarterMon:: @ 85B1DF8
	.2byte SPECIES_TREECKO
	.2byte SPECIES_TORCHIC
	.2byte SPECIES_MUDKIP

.align 2
gUnknown_085B1E00:: @ 85B1E00
	.incbin "baserom.gba", 0x5b1e00, 0xc

gUnknown_085B1E0C:: @ 85B1E0C
	.incbin "baserom.gba", 0x5b1e0c, 0x1c

gUnknown_085B1E28:: @ 85B1E28
	.incbin "baserom.gba", 0x5b1e28, 0xa8

gUnknown_085B1ED0:: @ 85B1ED0
	.incbin "baserom.gba", 0x5b1ed0, 0x8

gUnknown_085B1ED8:: @ 85B1ED8
	.incbin "baserom.gba", 0x5b1ed8, 0x10

gUnknown_085B1EE8:: @ 85B1EE8
	.incbin "baserom.gba", 0x5b1ee8, 0x10

gUnknown_085B1EF8:: @ 85B1EF8
	.incbin "baserom.gba", 0x5b1ef8, 0x18

sSpriteTemplate_Hand:: @ 85B1F10
	.incbin "baserom.gba", 0x5b1f10, 0x18

sSpriteTemplate_PokeBall:: @ 85B1F28
	.incbin "baserom.gba", 0x5b1f28, 0x18

gUnknown_085B1F40:: @ 85B1F40
	.incbin "baserom.gba", 0x5b1f40, 0x18
