	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0857173C:: @ 857173C
	.incbin "graphics/unknown/unknown_57173C.gbapal"

	.align 2
gUnknown_0857175C:: @ 857175C
	.incbin "graphics/pokemon_storage/box_selection_popup_center.4bpp"

	.align 2
gUnknown_08571F5C:: @ 8571F5C
	.incbin "graphics/pokemon_storage/box_selection_popup_sides.4bpp"

	.align 2
gUnknown_085720DC:: @ 85720DC
	.incbin "graphics/pokemon_storage/scrolling_bg.4bpp.lz"

	.align 2
gUnknown_08572174:: @ 8572174
	.incbin "graphics/pokemon_storage/scrolling_bg.bin.lz"

	.align 2
gUnknown_08572280:: @ 8572280
	.incbin "graphics/unknown/unknown_572280.gbapal"

	.align 2
gUnknown_085722A0:: @ 85722A0
	.incbin "graphics/unknown/unknown_5722A0.bin.lz"

	.align 1
gUnknown_0857239C:: @ 857239C
    .2byte 0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0111, 0x0112, 0x0113, 0x0114, 0x0115, 0x0116, 0x0117, 0x0118
    .2byte 0x2101, 0x2102, 0x2103, 0x2104, 0x2105, 0x2106, 0x2107, 0x2108, 0x2111, 0x2112, 0x2113, 0x2114, 0x2115, 0x2116, 0x2117, 0x2118

	.align 2
gUnknown_085723DC:: @ 85723DC
	.incbin "graphics/unknown/unknown_5723DC.gbapal"

	.align 2
gUnknown_085723FC:: @ 85723FC
	.incbin "graphics/unknown/unknown_5723FC.gbapal"

	.align 2
gUnknown_0857241C:: @ 857241C
	.incbin "graphics/unknown/unknown_57241C.gbapal"

	.align 2
gUnknown_0857243C:: @ 857243C
	.incbin "graphics/unknown/unknown_57243C.gbapal"

	.align 1
gUnknown_0857245C:: @ 857245C
	.2byte 0x014c, 0x014d, 0x014e, 0x014f, 0x0170, 0x0171, 0x0172, 0x0173, 0x0174, 0x015c, 0x015d, 0x015e, 0x015f, 0x0180, 0x0181, 0x0182
	.2byte 0x0183, 0x0184, 0x0175, 0x0176, 0x0177, 0x0178, 0x0179, 0x017a, 0x017b, 0x017c, 0x017d, 0x0185, 0x0186, 0x0187, 0x0188, 0x0189
	.2byte 0x018a, 0x018b, 0x018c, 0x018d

	.align 1
gUnknown_085724A4:: @ 85724A4
	.2byte 0x1140, 0x1141, 0x1141, 0x1142, 0x1150, 0x1151, 0x1151, 0x1152, 0x1160, 0x1161, 0x1161, 0x1162

	.align 1
gUnknown_085724BC:: @ 85724BC
	.2byte 0x1143, 0x1144, 0x1144, 0x1145, 0x1153, 0x1154, 0x1154, 0x1155, 0x1163, 0x1164, 0x1164, 0x1165

	.align 2
WaveformPalette:: @ 85724D4
	.incbin "graphics/pokemon_storage/waveform.gbapal"

	.align 2
WaveformTiles:: @ 85724F4
	.incbin "graphics/pokemon_storage/waveform.4bpp"

	.align 2
gUnknown_085726B4:: @ 85726B4
	.incbin "graphics/unused/unknown_5726B4.gbapal"

	.align 2
gUnknown_085726F4:: @ 85726F4
	.incbin "graphics/unknown/unknown_5726F4.gbapal"

	.align 2
gUnknown_08572714:: @ 8572714
	window_template 0x01, 0x00, 0x0b, 0x09, 0x07, 0x03, 0x00c0
	window_template 0x00, 0x0b, 0x11, 0x12, 0x02, 0x0f, 0x0014
	window_template 0x00, 0x00, 0x0d, 0x15, 0x07, 0x0f, 0x0014
	window_template_terminator

	.align 2
gUnknown_08572734:: @ 8572734
	.4byte 0x000001d0, 0x004011e5, 0x000023ba, 0x000031ff

	.align 2
gWaveformSpritePalette:: @ 8572744
	obj_pal WaveformPalette, 0xDACA

	.align 2
gWaveformSpriteSheet:: @ 857274C
	obj_tiles WaveformTiles, 0x1C0, 5

gUnknown_08572754:: @ 8572754
	spr_template 2, 0xDAC6, gOamData_857286C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_0857276C:: @ 857276C
	.4byte gText_ExitFromBox, 0
	.4byte gText_WhatDoYouWantToDo, 0
	.4byte gText_PleasePickATheme, 0
	.4byte gText_PickTheWallpaper, 0
	.4byte gText_PkmnIsSelected, 1
	.4byte gText_JumpToWhichBox, 0
	.4byte gText_DepositInWhichBox, 0
	.4byte gText_PkmnWasDeposited, 1
	.4byte gText_BoxIsFull2, 0
	.4byte gText_ReleaseThisPokemon, 0
	.4byte gText_PkmnWasReleased, 4
	.4byte gText_ByeByePkmn, 6
	.4byte gText_MarkYourPkmn, 0
	.4byte gText_ThatsYourLastPkmn, 0
	.4byte gText_YourPartysFull, 0
	.4byte gText_YoureHoldingAPkmn, 0
	.4byte gText_WhichOneWillYouTake, 0
	.4byte gText_YouCantReleaseAnEgg, 0
	.4byte gText_ContinueBoxOperations, 0
	.4byte gText_PkmnCameBack, 1
	.4byte gText_WasItWorriedAboutYou, 0
	.4byte gText_FourEllipsesExclamation, 0
	.4byte gText_PleaseRemoveTheMail, 0
	.4byte gText_PkmnIsSelected, 7
	.4byte gText_GiveToAPkmn, 0
	.4byte gText_PlacedItemInBag, 7
	.4byte gText_BagIsFull2, 0
	.4byte gText_PutItemInBag, 0
	.4byte gText_ItemIsNowHeld, 7
	.4byte gText_ChangedToNewItem, 7
	.4byte gText_MailCantBeStored, 0

	.align 2
gUnknown_08572864:: @ 8572864
	window_template 0, 0x18, 0xB, 5, 4, 0xF, 0x5C

	.align 2
gOamData_857286C:: @ 857286C
	.2byte 0x0000
	.2byte 0xC000
	.2byte 0x0000

	.align 2
gOamData_8572874:: @ 8572874
	.2byte 0x4000
	.2byte 0x0000
	.2byte 0x0000

	.align 2
gSpriteAnim_857287C:: @ 857287C
	obj_image_anim_frame 0, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_8572884:: @ 8572884
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 6, 8
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_8572894:: @ 8572894
	obj_image_anim_frame 8, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_857289C:: @ 857289C
	obj_image_anim_frame 10, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 12, 8
	obj_image_anim_jump 0

	.align 2
gSpriteAnimTable_85728AC:: @ 85728AC
	.4byte gSpriteAnim_857287C
	.4byte gSpriteAnim_8572884
	.4byte gSpriteAnim_8572894
	.4byte gSpriteAnim_857289C

gUnknown_085728BC:: @ 85728BC
	spr_template 5, 0xDACA, gOamData_8572874, gSpriteAnimTable_85728AC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085728D4:: @ 85728D4
	spr_template 0x12, 0xDAC0, gOamData_85728EC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gOamData_85728EC:: @ 85728EC
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0000

	.align 2
gSpriteAffineAnim_85728F4:: @ 85728F4
	obj_rot_scal_anim_frame 0xFFFE, 0xFFFE, 0, 120
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnim_8572904:: @ 8572904
	obj_rot_scal_anim_frame 0x10, 0x10, 0, 0
	obj_rot_scal_anim_frame 0x10, 0x10, 0, 15
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_857291C:: @ 857291C
	.4byte gSpriteAffineAnim_85728F4
	.4byte gSpriteAffineAnim_8572904

	.align 2
gWallpaperPalettes_Forest:: @ 8572924
	.incbin "graphics/pokemon_storage/forest_frame.gbapal"
	.incbin "graphics/pokemon_storage/forest_bg.gbapal"

	.align 2
gWallpaperTiles_Forest: @ 8572964
	.incbin "graphics/pokemon_storage/forest.4bpp.lz"

	.align 2
gWallpaperTilemap_Forest:: @ 8572DE8
	.incbin "graphics/pokemon_storage/forest.bin.lz"

	.align 2
gWallpaperPalettes_City: @ 8572EC8
	.incbin "graphics/pokemon_storage/city_frame.gbapal"
	.incbin "graphics/pokemon_storage/city_bg.gbapal"

	.align 2
gWallpaperTiles_City: @ 8572F08
	.incbin "graphics/pokemon_storage/city.4bpp.lz"

	.align 2
gWallpaperTilemap_City: @ 8573220
	.incbin "graphics/pokemon_storage/city.bin.lz"

	.align 2
gWallpaperPalettes_Desert: @ 85732FC
	.incbin "graphics/pokemon_storage/desert_frame.gbapal"
	.incbin "graphics/pokemon_storage/desert_bg.gbapal"

	.align 2
gWallpaperTiles_Desert: @ 857333C
	.incbin "graphics/pokemon_storage/desert.4bpp.lz"

	.align 2
gWallpaperTilemap_Desert: @ 85736F0
	.incbin "graphics/pokemon_storage/desert.bin.lz"

	.align 2
gWallpaperPalettes_Savanna: @ 85737EC
	.incbin "graphics/pokemon_storage/savanna_frame.gbapal"
	.incbin "graphics/pokemon_storage/savanna_bg.gbapal"

	.align 2
gWallpaperTiles_Savanna: @ 857382C
	.incbin "graphics/pokemon_storage/savanna.4bpp.lz"

	.align 2
gWallpaperTilemap_Savanna: @ 8573C40
	.incbin "graphics/pokemon_storage/savanna.bin.lz"

	.align 2
gWallpaperPalettes_Crag: @ 8573D44
	.incbin "graphics/pokemon_storage/crag_frame.gbapal"
	.incbin "graphics/pokemon_storage/crag_bg.gbapal"

	.align 2
gWallpaperTiles_Crag: @ 8573D84
	.incbin "graphics/pokemon_storage/crag.4bpp.lz"

	.align 2
gWallpaperTilemap_Crag: @ 8574180
	.incbin "graphics/pokemon_storage/crag.bin.lz"

	.align 2
gWallpaperPalettes_Volcano: @ 8573D44
	.incbin "graphics/pokemon_storage/volcano_frame.gbapal"
	.incbin "graphics/pokemon_storage/volcano_bg.gbapal"

	.align 2
gWallpaperTiles_Volcano: @ 8573D84
	.incbin "graphics/pokemon_storage/volcano.4bpp.lz"

	.align 2
gWallpaperTilemap_Volcano: @ 85747A0
	.incbin "graphics/pokemon_storage/volcano.bin.lz"

	.align 2
gWallpaperPalettes_Snow: @ 85748DC
	.incbin "graphics/pokemon_storage/snow_frame.gbapal"
	.incbin "graphics/pokemon_storage/snow_bg.gbapal"

	.align 2
gWallpaperTiles_Snow: @ 857491C
	.incbin "graphics/pokemon_storage/snow.4bpp.lz"

	.align 2
gWallpaperTilemap_Snow: @ 8574D7C
	.incbin "graphics/pokemon_storage/snow.bin.lz"

	.align 2
gWallpaperPalettes_Cave: @ 8574E88
	.incbin "graphics/pokemon_storage/cave_frame.gbapal"
	.incbin "graphics/pokemon_storage/cave_bg.gbapal"

	.align 2
gWallpaperTiles_Cave: @ 8574EC8
	.incbin "graphics/pokemon_storage/cave.4bpp.lz"

	.align 2
gWallpaperTilemap_Cave: @ 85752A0
	.incbin "graphics/pokemon_storage/cave.bin.lz"

	.align 2
gWallpaperPalettes_Beach: @ 8575378
	.incbin "graphics/pokemon_storage/beach_frame.gbapal"
	.incbin "graphics/pokemon_storage/beach_bg.gbapal"

	.align 2
gWallpaperTiles_Beach: @ 85753B8
	.incbin "graphics/pokemon_storage/beach.4bpp.lz"

	.align 2
gWallpaperTilemap_Beach: @ 8575788
	.incbin "graphics/pokemon_storage/beach.bin.lz"

	.align 2
gWallpaperPalettes_Seafloor: @ 8575888
	.incbin "graphics/pokemon_storage/seafloor_frame.gbapal"
	.incbin "graphics/pokemon_storage/seafloor_bg.gbapal"

	.align 2
gWallpaperTiles_Seafloor: @ 85758C8
	.incbin "graphics/pokemon_storage/seafloor.4bpp.lz"

	.align 2
gWallpaperTilemap_Seafloor: @ 8575BC4
	.incbin "graphics/pokemon_storage/seafloor.bin.lz"

	.align 2
gWallpaperPalettes_River: @ 8575CD8
	.incbin "graphics/pokemon_storage/river_frame.gbapal"
	.incbin "graphics/pokemon_storage/river_bg.gbapal"

	.align 2
gWallpaperTiles_River: @ 8575D18
	.incbin "graphics/pokemon_storage/river.4bpp.lz"

	.align 2
gWallpaperTilemap_River: @ 8576100
	.incbin "graphics/pokemon_storage/river.bin.lz"

	.align 2
gWallpaperPalettes_Sky: @ 85761F8
	.incbin "graphics/pokemon_storage/sky_frame.gbapal"
	.incbin "graphics/pokemon_storage/sky_bg.gbapal"

	.align 2
gWallpaperTiles_Sky: @ 8576238
	.incbin "graphics/pokemon_storage/sky.4bpp.lz"

	.align 2
gWallpaperTilemap_Sky: @ 85765C0
	.incbin "graphics/pokemon_storage/sky.bin.lz"

	.align 2
gWallpaperPalettes_Bubbles: @ 85766B0
	.incbin "graphics/pokemon_storage/bubbles_frame.gbapal"
	.incbin "graphics/pokemon_storage/bubbles_bg.gbapal"

	.align 2
gWallpaperTiles_Bubbles: @ 85766F0
	.incbin "graphics/pokemon_storage/bubbles.4bpp.lz"

	.align 2
gWallpaperTilemap_Bubbles: @ 85769B8
	.incbin "graphics/pokemon_storage/bubbles.bin.lz"

	.align 2
gWallpaperPalettes_Pokecenter: @ 8576AB8
	.incbin "graphics/pokemon_storage/pokecenter_frame.gbapal"
	.incbin "graphics/pokemon_storage/pokecenter_bg.gbapal"

	.align 2
gWallpaperTiles_Pokecenter: @ 8576AF8
	.incbin "graphics/pokemon_storage/pokecenter.4bpp.lz"

	.align 2
gWallpaperTilemap_Pokecenter: @ 8576D74
	.incbin "graphics/pokemon_storage/pokecenter.bin.lz"

	.align 2
gWallpaperPalettes_Machine: @ 8576E74
	.incbin "graphics/pokemon_storage/machine_frame.gbapal"
	.incbin "graphics/pokemon_storage/machine_bg.gbapal"

	.align 2
gWallpaperTiles_Machine: @ 8576EB4
	.incbin "graphics/pokemon_storage/machine.4bpp.lz"

	.align 2
gWallpaperTilemap_Machine: @ 8577108
	.incbin "graphics/pokemon_storage/machine.bin.lz"

	.align 2
gWallpaperPalettes_Plain: @ 85771CC
	.incbin "graphics/pokemon_storage/plain_frame.gbapal"
	.incbin "graphics/pokemon_storage/plain_bg.gbapal"

	.align 2
gWallpaperTiles_Plain: @ 857720C
	.incbin "graphics/pokemon_storage/plain.4bpp.lz"

	.align 2
gWallpaperTilemap_Plain: @ 857732C
	.incbin "graphics/pokemon_storage/plain.bin.lz"

@ 12×18 tilemap
	.incbin "graphics/unused/tilemap_5773C4.bin"

	.align 1
gUnknown_08577574:: @ 8577574
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF
	.2byte 0x1CE7, 0x7FFF

	.align 2
gWallpaperTable:: @ 85775B8
	@ Forest
	.4byte gWallpaperTiles_Forest
	.4byte gWallpaperTilemap_Forest
	.4byte gWallpaperPalettes_Forest

	@ City
	.4byte gWallpaperTiles_City
	.4byte gWallpaperTilemap_City
	.4byte gWallpaperPalettes_City

	@ Desert
	.4byte gWallpaperTiles_Desert
	.4byte gWallpaperTilemap_Desert
	.4byte gWallpaperPalettes_Desert

	@ Savanna
	.4byte gWallpaperTiles_Savanna
	.4byte gWallpaperTilemap_Savanna
	.4byte gWallpaperPalettes_Savanna

	@ Crag
	.4byte gWallpaperTiles_Crag
	.4byte gWallpaperTilemap_Crag
	.4byte gWallpaperPalettes_Crag

	@ Volcano
	.4byte gWallpaperTiles_Volcano
	.4byte gWallpaperTilemap_Volcano
	.4byte gWallpaperPalettes_Volcano

	@ Snow
	.4byte gWallpaperTiles_Snow
	.4byte gWallpaperTilemap_Snow
	.4byte gWallpaperPalettes_Snow

	@ Cave
	.4byte gWallpaperTiles_Cave
	.4byte gWallpaperTilemap_Cave
	.4byte gWallpaperPalettes_Cave

	@ Beach
	.4byte gWallpaperTiles_Beach
	.4byte gWallpaperTilemap_Beach
	.4byte gWallpaperPalettes_Beach

	@ Seafloor
	.4byte gWallpaperTiles_Seafloor
	.4byte gWallpaperTilemap_Seafloor
	.4byte gWallpaperPalettes_Seafloor

	@ River
	.4byte gWallpaperTiles_River
	.4byte gWallpaperTilemap_River
	.4byte gWallpaperPalettes_River

	@ Sky
	.4byte gWallpaperTiles_Sky
	.4byte gWallpaperTilemap_Sky
	.4byte gWallpaperPalettes_Sky

	@ Bubbles
	.4byte gWallpaperTiles_Bubbles
	.4byte gWallpaperTilemap_Bubbles
	.4byte gWallpaperPalettes_Bubbles

	@ Pokecenter
	.4byte gWallpaperTiles_Pokecenter
	.4byte gWallpaperTilemap_Pokecenter
	.4byte gWallpaperPalettes_Pokecenter

	@ Machine
	.4byte gWallpaperTiles_Machine
	.4byte gWallpaperTilemap_Machine
	.4byte gWallpaperPalettes_Machine

	@ Plain
	.4byte gWallpaperTiles_Plain
	.4byte gWallpaperTilemap_Plain
	.4byte gWallpaperPalettes_Plain

	.align 2
PCGfx_Arrow: @ 8577678
	.incbin "graphics/pokemon_storage/arrow.4bpp"

	.align 2
gWallpaperPalettes_Zigzagoon:: @ 85776F8
	.incbin "graphics/pokemon_storage/friends_frame1.gbapal"
	.incbin "graphics/pokemon_storage/zigzagoon_bg.gbapal"

	.align 2
gWallpaperTiles_Zigzagoon: @ 8577738
	.incbin "graphics/pokemon_storage/zigzagoon.4bpp.lz"

	.align 2
gWallpaperTilemap_Zigzagoon: @ 857792C
	.incbin "graphics/pokemon_storage/zigzagoon.bin.lz"

	.align 2
gWallpaperPalettes_Screen:: @ 8577A44
	.incbin "graphics/pokemon_storage/friends_frame1.gbapal"
	.incbin "graphics/pokemon_storage/screen_bg.gbapal"

	.align 2
gWallpaperTiles_Screen: @ 8577A84
	.incbin "graphics/pokemon_storage/screen.4bpp.lz"

	.align 2
gWallpaperTilemap_Screen: @ 8577D00
	.incbin "graphics/pokemon_storage/screen.bin.lz"

	.align 2
gWallpaperPalettes_Diagonal:: @ 8577E2C
	.incbin "graphics/pokemon_storage/friends_frame1.gbapal"
	.incbin "graphics/pokemon_storage/diagonal_bg.gbapal"

	.align 2
gWallpaperTiles_Diagonal: @ 8577E6C
	.incbin "graphics/pokemon_storage/diagonal.4bpp.lz"

	.align 2
gWallpaperTilemap_Diagonal: @ 8578058
	.incbin "graphics/pokemon_storage/diagonal.bin.lz"

	.align 2
gWallpaperPalettes_Block:: @ 8578148
	.incbin "graphics/pokemon_storage/block_bg.gbapal"
	.incbin "graphics/pokemon_storage/block_bg.gbapal"

	.align 2
gWallpaperTiles_Block: @ 8578188
	.incbin "graphics/pokemon_storage/block.4bpp.lz"

	.align 2
gWallpaperTilemap_Block: @ 8578358
	.incbin "graphics/pokemon_storage/block.bin.lz"

	.align 2
gWallpaperPalettes_PokeCenter2:: @ 8578450
	.incbin "graphics/pokemon_storage/pokecenter2_bg.gbapal"
	.incbin "graphics/pokemon_storage/pokecenter2_bg.gbapal"

	.align 2
gWallpaperTiles_PokeCenter2: @ 8578490
	.incbin "graphics/pokemon_storage/pokecenter2.4bpp.lz"

	.align 2
gWallpaperTilemap_PokeCenter2: @ 85786D0
	.incbin "graphics/pokemon_storage/pokecenter2.bin.lz"

	.align 2
gWallpaperPalettes_Frame:: @ 85787E4
	.incbin "graphics/pokemon_storage/frame_bg.gbapal"
	.incbin "graphics/pokemon_storage/frame_bg.gbapal"

	.align 2
gWallpaperTiles_Frame: @ 8578824
	.incbin "graphics/pokemon_storage/frame.4bpp.lz"

	.align 2
gWallpaperTilemap_Frame: @ 8578A34
	.incbin "graphics/pokemon_storage/frame.bin.lz"

	.align 2
gWallpaperPalettes_Blank:: @ 8578B48
	.incbin "graphics/pokemon_storage/friends_frame1.gbapal"
	.incbin "graphics/pokemon_storage/zigzagoon_bg.gbapal"

	.align 2
gWallpaperTiles_Blank: @ 8578B88
	.incbin "graphics/pokemon_storage/blank.4bpp.lz"

	.align 2
gWallpaperTilemap_Blank: @ 8578D34
	.incbin "graphics/pokemon_storage/blank.bin.lz"

	.align 2
gWallpaperPalettes_Circles:: @ 8578E10
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/circles_bg.gbapal"

	.align 2
gWallpaperTiles_Circles: @ 8578E50
	.incbin "graphics/pokemon_storage/circles.4bpp.lz"

	.align 2
gWallpaperTilemap_Circles: @ 85790A4
	.incbin "graphics/pokemon_storage/circles.bin.lz"

	.align 2
gWallpaperPalettes_Azumarill:: @ 85791A0
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/azumarill_bg.gbapal"

	.align 2
gWallpaperTiles_Azumarill: @ 85791E0
	.incbin "graphics/pokemon_storage/azumarill.4bpp.lz"

	.align 2
gWallpaperTilemap_Azumarill: @ 85793CC
	.incbin "graphics/pokemon_storage/azumarill.bin.lz"

	.align 2
gWallpaperPalettes_Pikachu:: @ 85794C4
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/pikachu_bg.gbapal"

	.align 2
gWallpaperTiles_Pikachu: @ 8579504
	.incbin "graphics/pokemon_storage/pikachu.4bpp.lz"

	.align 2
gWallpaperTilemap_Pikachu: @ 8579738
	.incbin "graphics/pokemon_storage/pikachu.bin.lz"

	.align 2
gWallpaperPalettes_Legendary:: @ 8579860
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/legendary_bg.gbapal"

	.align 2
gWallpaperTiles_Legendary: @ 85798A0
	.incbin "graphics/pokemon_storage/legendary.4bpp.lz"

	.align 2
gWallpaperTilemap_Legendary: @ 8579B80
	.incbin "graphics/pokemon_storage/legendary.bin.lz"

	.align 2
gWallpaperPalettes_Dusclops:: @ 8579CC4
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/dusclops_bg.gbapal"

	.align 2
gWallpaperTiles_Dusclops: @ 8579D04
	.incbin "graphics/pokemon_storage/dusclops.4bpp.lz"

	.align 2
gWallpaperTilemap_Dusclops: @ 8579F50
	.incbin "graphics/pokemon_storage/dusclops.bin.lz"

	.align 2
gWallpaperPalettes_Ludicolo:: @ 857A048
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/ludicolo_bg.gbapal"

	.align 2
gWallpaperTiles_Ludicolo: @ 857A088
	.incbin "graphics/pokemon_storage/ludicolo.4bpp.lz"

	.align 2
gWallpaperTilemap_Ludicolo: @ 857A348
	.incbin "graphics/pokemon_storage/ludicolo.bin.lz"

	.align 2
gWallpaperPalettes_Whiscash:: @ 857A468
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/whiscash_bg.gbapal"

	.align 2
gWallpaperTiles_Whiscash: @ 857A4A8
	.incbin "graphics/pokemon_storage/whiscash.4bpp.lz"

	.align 2
gWallpaperTilemap_Whiscash: @ 857A6F0
	.incbin "graphics/pokemon_storage/whiscash.bin.lz"

	.align 2
gWallpaperIcon_Aqua: @ 857A81C
	.incbin "graphics/pokemon_storage/aqua_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Heart: @ 857A860
	.incbin "graphics/pokemon_storage/heart_icon.4bpp.lz"

	.align 2
gWallpaperIcon_FiveStar: @ 857A89C
	.incbin "graphics/pokemon_storage/five_star_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Brick: @ 857A8DC
	.incbin "graphics/pokemon_storage/brick_icon.4bpp.lz"

	.align 2
gWallpaperIcon_FourStar: @ 857A904
	.incbin "graphics/pokemon_storage/four_star_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Asterisk: @ 857A940
	.incbin "graphics/pokemon_storage/asterisk_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Dot: @ 857A990
	.incbin "graphics/pokemon_storage/dot_icon.4bpp.lz"

	.align 2
gWallpaperIcon_LineCircle: @ 857A9C0
	.incbin "graphics/pokemon_storage/line_circle_icon.4bpp.lz"

	.align 2
gWallpaperIcon_PokeBall: @ 857A9EC
	.incbin "graphics/pokemon_storage/pokeball_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Maze: @ 857AA38
	.incbin "graphics/pokemon_storage/maze_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Footprint: @ 857AA7C
	.incbin "graphics/pokemon_storage/footprint_icon.4bpp.lz"

	.align 2
gWallpaperIcon_BigAsterisk: @ 857AAC4
	.incbin "graphics/pokemon_storage/big_asterisk_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Circle: @ 857AB08
	.incbin "graphics/pokemon_storage/circle_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Koffing: @ 857AB48
	.incbin "graphics/pokemon_storage/koffing_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Ribbon: @ 857AB98
	.incbin "graphics/pokemon_storage/ribbon_icon.4bpp.lz"

	.align 2
gWallpaperIcon_FourCircles: @ 857AC00
	.incbin "graphics/pokemon_storage/four_circles_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Lotad: @ 857AC30
	.incbin "graphics/pokemon_storage/lotad_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Crystal: @ 857AC74
	.incbin "graphics/pokemon_storage/crystal_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Pichu: @ 857ACBC
	.incbin "graphics/pokemon_storage/pichu_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Diglett: @ 857ACF4
	.incbin "graphics/pokemon_storage/diglett_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Luvdisc: @ 857AD44
	.incbin "graphics/pokemon_storage/luvdisc_icon.4bpp.lz"

	.align 2
gWallpaperIcon_StarInCircle: @ 857AD88
	.incbin "graphics/pokemon_storage/star_in_circle_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Spinda: @ 857ADCC
	.incbin "graphics/pokemon_storage/spinda_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Latis: @ 857AE20
	.incbin "graphics/pokemon_storage/latis_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Minun: @ 857AE64
	.incbin "graphics/pokemon_storage/minun_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Togepi: @ 857AEAC
	.incbin "graphics/pokemon_storage/togepi_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Magma: @ 857AF08
	.incbin "graphics/pokemon_storage/magma_icon.4bpp.lz"

	.align 2
gUnknown_0857AF44:: @ 857AF44
	.4byte gWallpaperTiles_Zigzagoon, gWallpaperTilemap_Zigzagoon, gWallpaperPalettes_Zigzagoon
	.4byte gWallpaperTiles_Screen, gWallpaperTilemap_Screen, gWallpaperPalettes_Screen
	.4byte gWallpaperTiles_Horizontal, gWallpaperTilemap_Horizontal, gWallpaperPalettes_Horizontal
	.4byte gWallpaperTiles_Diagonal, gWallpaperTilemap_Diagonal, gWallpaperPalettes_Diagonal
	.4byte gWallpaperTiles_Block, gWallpaperTilemap_Block, gWallpaperPalettes_Block
	.4byte gWallpaperTiles_Ribbon, gWallpaperTilemap_Ribbon, gWallpaperPalettes_Ribbon
	.4byte gWallpaperTiles_PokeCenter2, gWallpaperTilemap_PokeCenter2, gWallpaperPalettes_PokeCenter2
	.4byte gWallpaperTiles_Frame, gWallpaperTilemap_Frame, gWallpaperPalettes_Frame
	.4byte gWallpaperTiles_Blank, gWallpaperTilemap_Blank, gWallpaperPalettes_Blank
	.4byte gWallpaperTiles_Circles, gWallpaperTilemap_Circles, gWallpaperPalettes_Circles
	.4byte gWallpaperTiles_Azumarill, gWallpaperTilemap_Azumarill, gWallpaperPalettes_Azumarill
	.4byte gWallpaperTiles_Pikachu, gWallpaperTilemap_Pikachu, gWallpaperPalettes_Pikachu
	.4byte gWallpaperTiles_Legendary, gWallpaperTilemap_Legendary, gWallpaperPalettes_Legendary
	.4byte gWallpaperTiles_Dusclops, gWallpaperTilemap_Dusclops, gWallpaperPalettes_Dusclops
	.4byte gWallpaperTiles_Ludicolo, gWallpaperTilemap_Ludicolo, gWallpaperPalettes_Ludicolo
	.4byte gWallpaperTiles_Whiscash, gWallpaperTilemap_Whiscash, gWallpaperPalettes_Whiscash

	.align 2
gUnknown_0857B004:: @ 857B004
    .4byte gWallpaperIcon_Aqua
    .4byte gWallpaperIcon_Heart
    .4byte gWallpaperIcon_FiveStar
    .4byte gWallpaperIcon_Brick
    .4byte gWallpaperIcon_FourStar
    .4byte gWallpaperIcon_Asterisk
    .4byte gWallpaperIcon_Dot
    .4byte gWallpaperIcon_Cross
    .4byte gWallpaperIcon_LineCircle
    .4byte gWallpaperIcon_PokeBall
    .4byte gWallpaperIcon_Maze
    .4byte gWallpaperIcon_Footprint
    .4byte gWallpaperIcon_BigAsterisk
    .4byte gWallpaperIcon_Circle
    .4byte gWallpaperIcon_Koffing
    .4byte gWallpaperIcon_Ribbon
    .4byte gWallpaperIcon_Bolt
    .4byte gWallpaperIcon_FourCircles
    .4byte gWallpaperIcon_Lotad
    .4byte gWallpaperIcon_Crystal
    .4byte gWallpaperIcon_Pichu
    .4byte gWallpaperIcon_Diglett
    .4byte gWallpaperIcon_Luvdisc
    .4byte gWallpaperIcon_StarInCircle
    .4byte gWallpaperIcon_Spinda
    .4byte gWallpaperIcon_Latis
    .4byte gWallpaperIcon_Plusle
    .4byte gWallpaperIcon_Minun
    .4byte gWallpaperIcon_Togepi
    .4byte gWallpaperIcon_Magma

	.align 2
gUnknown_0857B07C:: @ 857B07C
	.incbin "baserom.gba", 0x57b07C, 0x4

	.align 2
gUnknown_0857B080:: @ 857B080
	.incbin "baserom.gba", 0x57b080, 0x28

gUnknown_0857B0A8:: @ 857B0A8
	.incbin "baserom.gba", 0x57b0a8, 0x38

gUnknown_0857B0E0:: @ 857B0E0
	.incbin "baserom.gba", 0x57b0e0, 0x8b8

gUnknown_0857B998:: @ 857B998
	.incbin "baserom.gba", 0x57b998, 0xc

gUnknown_0857B9A4:: @ 857B9A4
	.incbin "baserom.gba", 0x57b9a4, 0x18

gUnknown_0857B9BC:: @ 857B9BC
	.incbin "baserom.gba", 0x57b9bc, 0x28

gUnknown_0857B9E4:: @ 857B9E4
	.incbin "baserom.gba", 0x57b9e4, 0x18

gUnknown_0857B9FC:: @ 857B9FC
	.incbin "baserom.gba", 0x57b9fc, 0x54

gUnknown_0857BA50:: @ 857BA50
	.incbin "baserom.gba", 0x57ba50, 0x18

gUnknown_0857BA68:: @ 857BA68
	.incbin "baserom.gba", 0x57ba68, 0x18

gUnknown_0857BA80:: @ 857BA80
	.incbin "baserom.gba", 0x57ba80, 0x9c

gUnknown_0857BB1C:: @ 857BB1C
	.incbin "baserom.gba", 0x57bb1c, 0x8

gUnknown_0857BB24:: @ 857BB24
	.incbin "baserom.gba", 0x57bb24, 0x14c

gUnknown_0857BC70:: @ 857BC70
	.incbin "baserom.gba", 0x57bc70, 0x18

gUnknown_0857BC88:: @ 857BC88
	.incbin "baserom.gba", 0x57bc88, 0x20
