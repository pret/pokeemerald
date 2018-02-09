#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2

@ 83299EC
	.include "data/graphics/pokemon/front_anim_ids_table.inc"

@ 8329B87
	.include "data/graphics/pokemon/animation_delay_table.inc"

	.align 1
gUnknown_08329D22:: @ 8329D22
@ Masks for getting PP Up count, also PP Max values
	.byte 0x03, 0x0c, 0x30, 0xc0

	.align 1
gUnknown_08329D26:: @ 8329D26
@ Masks for setting PP Up count
	.byte 0xfc, 0xf3, 0xcf, 0x3f

	.align 1
gUnknown_08329D2A:: @ 8329D2A
@ Values added to PP Up count
	.byte 0x01, 0x04, 0x10, 0x40

	.align 1
gStatStageRatios:: @ 8329D2E
	.byte 0x0a, 0x28
	.byte 0x0a, 0x23
	.byte 0x0a, 0x1e
	.byte 0x0a, 0x19
	.byte 0x0a, 0x14
	.byte 0x0a, 0x0f
	.byte 0x0a, 0x0a
	.byte 0x0f, 0x0a
	.byte 0x14, 0x0a
	.byte 0x19, 0x0a
	.byte 0x1e, 0x0a
	.byte 0x23, 0x0a
	.byte 0x28, 0x0a

	.align 1
gUnknown_08329D48:: @ 8329D48
	.2byte 0x0032, 0x005f, 0x005a, 0x00b4, 0x005f, 0x005a

	.align 1
gUnknown_08329D54:: @ 8329D54
	.2byte 0x0003, 0x000a, 0x001b, 0x002b, 0x001e, 0x0043, 0x0042, 0x0019
	.2byte 0x0012, 0x000c, 0x001c, 0x0047, 0x001f, 0x0036, 0x0002, 0x0014

	.align 1
gHoldEffectToType:: @ 8329D74
	.byte 0x1f, 0x06
	.byte 0x2a, 0x08
	.byte 0x2e, 0x04
	.byte 0x2f, 0x05
	.byte 0x30, 0x0c
	.byte 0x31, 0x11
	.byte 0x32, 0x01
	.byte 0x33, 0x0d
	.byte 0x34, 0x0b
	.byte 0x35, 0x02
	.byte 0x36, 0x03
	.byte 0x37, 0x0f
	.byte 0x38, 0x07
	.byte 0x39, 0x0e
	.byte 0x3a, 0x0a
	.byte 0x3b, 0x10
	.byte 0x3c, 0x00
	.byte 0x00, 0x00

	.align 2
gUnknown_08329D98:: @ 8329D98
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF3A8, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACA8, NULL, gUnknown_082FF3C8, gUnknown_082FF694, oac_poke_opponent
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF3E8, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACA8, NULL, gUnknown_082FF408, gUnknown_082FF694, oac_poke_opponent

	.align 2
gUnknown_08329DF8:: @ 8329DF8
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF428, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF448, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF468, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF490, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF4B8, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF4D8, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF4F8, gUnknown_082FF618, sub_8039BB4
	spr_template 0xffff, 0x0000, gUnknown_0831ACB0, NULL, gUnknown_082FF518, gUnknown_082FF618, sub_8039BB4

gSecretBaseTrainerClasses:: @ 8329EB8
	.byte FACILITY_CLASS_YOUNGSTER, FACILITY_CLASS_BUG_CATCHER, FACILITY_CLASS_RICH_BOY, FACILITY_CLASS_CAMPER, FACILITY_CLASS_COOLTRAINER_1
	.byte FACILITY_CLASS_LASS, FACILITY_CLASS_SCHOOL_KID_2, FACILITY_CLASS_LADY, FACILITY_CLASS_PICNICKER, FACILITY_CLASS_COOLTRAINER_2

gUnknown_08329EC2:: @ 8329EC2
	.byte 0x1a, 0x1b, 0x1c, 0x1d, 0x1f, 0x1e

gUnknown_08329EC8:: @ 8329EC8
	.byte 1, 1, 3, 2, 4, 6

gUnknown_08329ECE:: @ 8329ECE
@ Happiness deltas
	.byte 0x05, 0x03, 0x02
	.byte 0x05, 0x03, 0x02
	.byte 0x01, 0x01, 0x00
	.byte 0x03, 0x02, 0x01
	.byte 0x01, 0x01, 0x00
	.byte 0x01, 0x01, 0x01
	.byte 0xff, 0xff, 0xff
	.byte 0xfb, 0xfb, 0xf6
	.byte 0xfb, 0xfb, 0xf6

	.align 1
gHMMoves:: @ 8329EEA
	.2byte MOVE_CUT
	.2byte MOVE_FLY
	.2byte MOVE_SURF
	.2byte MOVE_STRENGTH
	.2byte MOVE_FLASH
	.2byte MOVE_ROCK_SMASH
	.2byte MOVE_WATERFALL
	.2byte MOVE_DIVE
	.2byte 0xffff

	.align 1
gAlteringCaveWildMonHeldItems:: @ 8329EFC
	.2byte 0, ITEM_NONE
	.2byte SPECIES_MAREEP,		ITEM_GANLON_BERRY
	.2byte SPECIES_PINECO,		ITEM_APICOT_BERRY
	.2byte SPECIES_HOUNDOUR,	ITEM_BIG_MUSHROOM
	.2byte SPECIES_TEDDIURSA,	ITEM_PETAYA_BERRY
	.2byte SPECIES_AIPOM,		ITEM_BERRY_JUICE
	.2byte SPECIES_SHUCKLE,		ITEM_BERRY_JUICE
	.2byte SPECIES_STANTLER,	ITEM_PETAYA_BERRY
	.2byte SPECIES_SMEARGLE,	ITEM_SALAC_BERRY

	.align 2
gUnknown_08329F20:: @ 8329F20
	.byte 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_08329F28:: @ 8329F28
	spr_template 0xffff, 0xffff, gUnknown_08329F20, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

