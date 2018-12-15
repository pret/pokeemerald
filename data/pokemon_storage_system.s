	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata



	.align 2
gUnknown_0857B9BC:: @ 857B9BC
	.4byte sub_80CF0CC, 0
	.4byte sub_80CF5C4, 1
	.4byte sub_80CF7E4, 2
	.4byte sub_80CF8D8, 3
	.4byte NULL, 0

	.align 2
gHandCursorSpriteSheets:: @ 857B9E4
	obj_tiles gHandCursorTiles, 0x0800, 0x0000
	obj_tiles gHandCursorShadowTiles, 0x0080, 0x0001
	null_obj_tiles

	.align 2
gHandCursorSpritePalettes:: @ 857B9FC
	obj_pal gHandCursorPalette, 0xDAC7
	null_obj_pal

	.align 2
gOamData_857BA0C:: @ 857BA0C
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0400

	.align 2
gOamData_857BA14:: @ 857BA14
	.2byte 0x0000
	.2byte 0x4000
	.2byte 0x0400

	.align 2
gSpriteAnim_857BA1C:: @ 857BA1C
	obj_image_anim_frame 0, 30
	obj_image_anim_frame 16, 30
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_857BA28:: @ 857BA28
	obj_image_anim_frame 0, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_857BA30:: @ 857BA30
	obj_image_anim_frame 32, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_857BA38:: @ 857BA38
	obj_image_anim_frame 48, 5
	obj_image_anim_end

	.align 2
gSpriteAnimTable_857BA40:: @ 857BA40
	.4byte gSpriteAnim_857BA1C
	.4byte gSpriteAnim_857BA28
	.4byte gSpriteAnim_857BA30
	.4byte gSpriteAnim_857BA38

	.align 2
gSpriteTemplate_857BA50:: @ 857BA50
	spr_template 0, 0xDACA, gOamData_857BA0C, gSpriteAnimTable_857BA40, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteTemplate_857BA68:: @ 857BA68
	spr_template 1, 0xDACA, gOamData_857BA14, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80CFBF4

	.align 2
gUnknown_0857BA80:: @ 857BA80
	.4byte gPCText_Cancel
	.4byte gPCText_Store
	.4byte gPCText_Withdraw
	.4byte gPCText_Move
	.4byte gPCText_Shift
	.4byte gPCText_Place
	.4byte gPCText_Summary
	.4byte gPCText_Release
	.4byte gPCText_Mark
	.4byte gPCText_Jump
	.4byte gPCText_Wallpaper
	.4byte gPCText_Name
	.4byte gPCText_Take
	.4byte gPCText_Give
	.4byte gPCText_Give
	.4byte gPCText_Switch
	.4byte gPCText_Bag
	.4byte gPCText_Info
	.4byte gPCText_Scenery1
	.4byte gPCText_Scenery2
	.4byte gPCText_Scenery3
	.4byte gPCText_Etcetera
	.4byte gPCText_Friends
	.4byte gPCText_Forest
	.4byte gPCText_City
	.4byte gPCText_Desert
	.4byte gPCText_Savanna
	.4byte gPCText_Crag
	.4byte gPCText_Volcano
	.4byte gPCText_Snow
	.4byte gPCText_Cave
	.4byte gPCText_Beach
	.4byte gPCText_Seafloor
	.4byte gPCText_River
	.4byte gPCText_Sky
	.4byte gPCText_PolkaDot
	.4byte gPCText_Pokecenter
	.4byte gPCText_Machine
	.4byte gPCText_Simple

	.align 2
gUnknown_0857BB1C:: @ 857BB1C
	window_template 0x00, 0x0a, 0x03, 0x14, 0x12, 0x09, 0x000a

	.align 2
gUnknown_0857BB24:: @ 857BB24
	.incbin "graphics/pokemon_storage/unknown_frame.4bpp"

	.align 2
gOamData_857BBA4:: @ 857BBA4
	.2byte 0x0100, 0x8000, 0x0400, 0x0000

	.align 2
gSpriteAffineAnim_857BBAC:: @ 857BBAC
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BBBC:: @ 857BBBC
	.2byte 0x0058, 0x0058, 0x0000, 0x0000, 0x0005, 0x0005, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BBD4:: @ 857BBD4
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0xfffb, 0xfffb, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BBEC:: @ 857BBEC
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x000a, 0x000a, 0x0c00, 0x0000, 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BC0C:: @ 857BC0C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfff6, 0xfff6, 0x0c00, 0x0000, 0x0080, 0x0080, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BC2C:: @ 857BC2C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0xfffb, 0xfffb, 0x1000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857BC44:: @ 857BC44
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_857BC54:: @ 857BC54
	.4byte gSpriteAffineAnim_857BBAC
	.4byte gSpriteAffineAnim_857BBBC
	.4byte gSpriteAffineAnim_857BBD4
	.4byte gSpriteAffineAnim_857BBEC
	.4byte gSpriteAffineAnim_857BC0C
	.4byte gSpriteAffineAnim_857BC2C
	.4byte gSpriteAffineAnim_857BC44

	.align 2
gSpriteTemplate_857BC70:: @ 857BC70
	spr_template 0x0007, 0xdacb, gOamData_857BBA4, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_857BC54, SpriteCallbackDummy

gSpriteTemplate_857BC88:: @ 857BC88
	.2byte 0x0100, 0x0100, 0x0200, 0x0100, 0x0100, 0x0200, 0x0200, 0x0200, 0x0080, 0x0080, 0x0100, 0x0100, 0x0200, 0x0200, 0x0400, 0x0400

