#include "constants/map_objects.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
gUnknown_085CD66C:: @ 85CD66C
    .4byte 0x000011c0, 0x000021d1, 0x000031e2, 0x000001f3

    .align 2
gCableCarMtChimneyTilemap:: @ 85CD67C
	.incbin "graphics/misc/cable_car_mt_chimney_map.bin.lz"

    .align 2
gCableCarTreeTilemap:: @ 85CD7D4
	.incbin "graphics/misc/cable_car_tree_map.bin.lz"

    .align 2
gCableCarMountainTilemap:: @ 85CD958
	.incbin "graphics/misc/cable_car_mountain_map.bin.lz"

    .align 2
gCableCarPylonHookTilemapEntries:: @ 85CDB1C
	.2byte 0x3000
	.2byte 0x3001
	.2byte 0x3002
	.2byte 0x3003
	.2byte 0x3004
	.2byte 0x3005
	.2byte 0x3006
	.2byte 0x3007
	.2byte 0x3008
	.2byte 0x3009

    .align 2
gCableCarPylonStemTilemap:: @ 85CDB30
	.incbin "graphics/misc/cable_car_pylon_stem_map.bin.lz"

	.align 2
gUnknown_085CDB54:: @ 85CDB54
	obj_tiles gCableCar_Gfx, 0x800, 1
	obj_tiles gCableCarDoor_Gfx, 0x40, 2
	obj_tiles gCableCarCord_Gfx, 0x80, 3
    null_obj_tiles

	.align 2
gUnknown_085CDB74:: @ 85CDB74
	obj_pal gCableCar_Pal, 1
	null_obj_pal

	.align 2
gOamData_85CDB84:: @ 85CDB84
	.2byte 0x0300
	.2byte 0xC000
	.2byte 0x0800

	.align 2
gOamData_85CDB8C:: @ 85CDB8C
	.2byte 0x4300
	.2byte 0x0000
	.2byte 0x0800

	.align 2
gOamData_85CDB94:: @ 85CDB94
	.2byte 0x0300
	.2byte 0x4000
	.2byte 0x0800

	.align 2
gSpriteTemplate_85CDB9C:: @ 85CDB9C
	spr_template 1, 1, gOamData_85CDB84, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8150868

	.align 2
gSpriteTemplate_85CDBB4:: @ 85CDBB4
	spr_template 2, 1, gOamData_85CDB8C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8150868

	.align 2
gSpriteTemplate_85CDBCC:: @ 85CDBCC
	spr_template 3, 1, gOamData_85CDB94, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, nullsub_58

gCableCarPlayerGraphicsIDs:: @ 85CDBE4
	.byte MAP_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	.byte MAP_OBJ_GFX_RIVAL_MAY_NORMAL

gMtChimneyHikerGraphicsIDs:: @ 85CDBE6
	.byte MAP_OBJ_GFX_HIKER
	.byte MAP_OBJ_GFX_CAMPER
	.byte MAP_OBJ_GFX_PICNICKER
	.byte MAP_OBJ_GFX_ZIGZAGOON_1 @ not used

	.align 1
gMtChimneyHikerCoords:: @ 85CDBEA
	.2byte   0,  80
	.2byte 240, 146

gMtChimneyHikerMovementDelayTable:: @ 85CDBF2
	.byte   0
	.byte  60
	.byte 120
	.byte 170

	.align 2
gUnknown_085CDBF8:: @ 85CDBF8
	.4byte sub_8150A68
	.4byte sub_8150AF4
