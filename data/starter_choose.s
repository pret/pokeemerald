	.include "asm/macros.inc"
	.include "constants/constants.inc"
	.include "include/constants/species.h"

	.section .rodata

	.align 2
gBirchBagGrassPal:: @ 85B0A00
	.incbin "graphics/misc/birch_bag.gbapal"
	.incbin "graphics/misc/birch_grass.gbapal"

	.align 2
gBirchBallarrow_Pal:: @ 85B0A40
	.incbin "graphics/misc/birch_ballarrow.gbapal"

	.align 2
gBirchCircle_Pal:: @ 85B0A60
	.incbin "graphics/misc/birch_circle.gbapal"

	.align 2
gBirchBagTilemap:: @ 85B0A80
	.incbin "graphics/misc/birch_bag_map.bin.lz"

	.align 2
gBirchGrassTilemap:: @ 85B0C0C
	.incbin "graphics/misc/birch_grass_map.bin.lz"

	.align 2
gBirchHelpGfx:: @ 85B0E04
	.incbin "graphics/misc/birch_help.4bpp.lz"

	.align 2
gUnknown_085B18AC:: @ 85B18AC
	.incbin "graphics/misc/birch_ballarrow.4bpp.lz"

	.align 2
gUnknown_085B1BCC:: @ 85B1BCC
	.incbin "graphics/misc/birch_circle.4bpp.lz"

	.align 2
gUnknown_085B1DCC:: @ 85B1DCC
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0e, 0x0200
	null_window_template

	.align 2
gUnknown_085B1DDC:: @ 85B1DDC
	window_template 0x00, 0x18, 0x09, 0x05, 0x04, 0x0e, 0x0260

	.align 2
gUnknown_085B1DE4:: @ 85B1DE4
	window_template 0x00, 0x00, 0x00, 0x0d, 0x04, 0x0e, 0x0274

sPokeballCoords:: @ 85B1DEC
	.byte 0x3c, 0x40, 0x78, 0x58, 0xb4, 0x40

gStarterChoose_LabelCoords:: @ 85B1DF2
	.byte 0x00, 0x09, 0x10, 0x0a, 0x08, 0x04

sStarterMon:: @ 85B1DF8
	.2byte SPECIES_TREECKO
	.2byte SPECIES_TORCHIC
	.2byte SPECIES_MUDKIP

	.align 2
gUnknown_085B1E00:: @ 85B1E00
	.4byte 0x000001f8, 0x00003072, 0x00001063

gUnknown_085B1E0C:: @ 85B1E0C
	.byte 0x00, 0x01, 0x03

	.align 2
gOamData_85B1E10:: @ 85B1E10
	.2byte 0x00a0, 0x8000, 0x0400, 0x0000

	.align 2
gOamData_85B1E18:: @ 85B1E18
	.2byte 0x00a0, 0x8000, 0x0400, 0x0000

	.align 2
gOamData_85B1E20:: @ 85B1E20
	.2byte 0x03a0, 0xc000, 0x0400, 0x0000

gUnknown_085B1E28:: @ 85B1E28
	.byte 0x3c, 0x20, 0x78, 0x38, 0xb4, 0x20, 0x00, 0x00

	.align 2
gSpriteAnim_85B1E30:: @ 85B1E30
	.2byte 0x0030, 0x001e, 0xffff, 0x0000

	.align 2
gSpriteAnim_85B1E38:: @ 85B1E38
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gSpriteAnim_85B1E40:: @ 85B1E40
	.2byte 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004, 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004
	.2byte 0x0000, 0x0020, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008, 0x0000, 0x0008, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008
	.2byte 0x0000, 0x0008, 0xfffe, 0x0000

	.align 2
gSpriteAnim_85B1E88:: @ 85B1E88
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_85B1E90:: @ 85B1E90
	.4byte gSpriteAnim_85B1E30

	.align 2
gSpriteAnimTable_85B1E94:: @ 85B1E94
	.4byte gSpriteAnim_85B1E38
	.4byte gSpriteAnim_85B1E40

	.align 2
gSpriteAnimTable_85B1E9C:: @ 85B1E9C
	.4byte gSpriteAnim_85B1E88

	.align 2
gSpriteAffineAnim_85B1EA0:: @ 85B1EA0
	.2byte 0x0010, 0x0010, 0x0000, 0x0000, 0x0010, 0x0010, 0x0f00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_85B1EB8:: @ 85B1EB8
	.2byte 0x0014, 0x0014, 0x0000, 0x0000, 0x0014, 0x0014, 0x0f00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085B1ED0:: @ 85B1ED0
	.4byte gSpriteAffineAnim_85B1EA0

	.align 2
gSpriteAffineAnimTable_85B1ED4:: @ 85B1ED4
	.4byte gSpriteAffineAnim_85B1EB8

	.align 2
gUnknown_085B1ED8:: @ 85B1ED8
	obj_tiles gUnknown_085B18AC, 0x0800, 0x1000
	null_obj_tiles

	.align 2
gUnknown_085B1EE8:: @ 85B1EE8
	obj_tiles gUnknown_085B1BCC, 0x0800, 0x1001
	null_obj_tiles

	.align 2
gUnknown_085B1EF8:: @ 85B1EF8
	obj_pal gBirchBallarrow_Pal, 0x1000
	obj_pal gBirchCircle_Pal, 0x1001
	null_obj_pal

	.align 2
sSpriteTemplate_Hand:: @ 85B1F10
	spr_template 0x1000, 0x1000, gOamData_85B1E10, gSpriteAnimTable_85B1E90, NULL, gDummySpriteAffineAnimTable, sub_81346DC

	.align 2
sSpriteTemplate_PokeBall:: @ 85B1F28
	spr_template 0x1000, 0x1000, gOamData_85B1E18, gSpriteAnimTable_85B1E94, NULL, gDummySpriteAffineAnimTable, sub_813473C

	.align 2
gUnknown_085B1F40:: @ 85B1F40
	spr_template 0x1001, 0x1001, gOamData_85B1E20, gSpriteAnimTable_85B1E9C, NULL, gSpriteAffineAnimTable_85B1ED4, StarterPokemonSpriteCallback
