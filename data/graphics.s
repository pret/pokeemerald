	.section gfx_data, "aw", %progbits

	.align 2
gBattleTextboxTiles:: @ 8C00000
	.incbin "graphics/interface/menu.4bpp.lz" @ menu window and arrows

	.align 2
gBattleTextboxPalette:: @ 8C004E0
	.incbin "graphics/interface/menu.gbapal.lz"

	.align 2
gBattleTextboxTilemap:: @ 8C00524
	.incbin "graphics/interface/menu_map.bin.lz"

@ 8C00750
	.include "data/graphics/pokemon/circled_question_mark_graphics.inc"

@ 8C00C10
	.incbin "graphics/unused/old_charmap.4bpp.lz" @ japanese table and bunch of stuff
	.incbin "graphics/unused/old_charmap.bin.lz"
	.incbin "graphics/unused/old_charmap.gbapal.lz"

	.align 2
gSmokescreenImpactTiles:: @ 8C01644
	.incbin "graphics/battle_anims/sprites/smokescreen_impact.4bpp.lz"

	.align 2
gSmokescreenImpactPalette:: @ 8C01724
	.incbin "graphics/battle_anims/sprites/smokescreen_impact.gbapal.lz"

	.align 2
gInterfaceGfx_PokeBall::
	.incbin "graphics/interface/ball/poke.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_PokeBall::
	.incbin "graphics/interface/ball/poke.gbapal.lz"

	.align 2
gInterfaceGfx_GreatBall::
	.incbin "graphics/interface/ball/great.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_GreatBall::
	.incbin "graphics/interface/ball/great.gbapal.lz"

	.align 2
gInterfaceGfx_SafariBall::
	.incbin "graphics/interface/ball/safari.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_SafariBall::
	.incbin "graphics/interface/ball/safari.gbapal.lz"

	.align 2
gInterfaceGfx_UltraBall::
	.incbin "graphics/interface/ball/ultra.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_UltraBall::
	.incbin "graphics/interface/ball/ultra.gbapal.lz"

	.align 2
gInterfaceGfx_MasterBall::
	.incbin "graphics/interface/ball/master.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_MasterBall::
	.incbin "graphics/interface/ball/master.gbapal.lz"

	.align 2
gInterfaceGfx_NetBall::
	.incbin "graphics/interface/ball/net.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_NetBall::
	.incbin "graphics/interface/ball/net.gbapal.lz"

	.align 2
gInterfaceGfx_DiveBall::
	.incbin "graphics/interface/ball/dive.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_DiveBall::
	.incbin "graphics/interface/ball/dive.gbapal.lz"

	.align 2
gInterfaceGfx_NestBall::
	.incbin "graphics/interface/ball/nest.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_NestBall::
	.incbin "graphics/interface/ball/nest.gbapal.lz"

	.align 2
gInterfaceGfx_RepeatBall::
	.incbin "graphics/interface/ball/repeat.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_RepeatBall::
	.incbin "graphics/interface/ball/repeat.gbapal.lz"

	.align 2
gInterfaceGfx_TimerBall::
	.incbin "graphics/interface/ball/timer.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_TimerBall::
	.incbin "graphics/interface/ball/timer.gbapal.lz"

	.align 2
gInterfaceGfx_LuxuryBall::
	.incbin "graphics/interface/ball/luxury.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_LuxuryBall::
	.incbin "graphics/interface/ball/luxury.gbapal.lz"

	.align 2
gInterfaceGfx_PremierBall::
	.incbin "graphics/interface/ball/premier.4bpp.lz" @ 0xBC

	.align 2
gInterfacePal_PremierBall::
	.incbin "graphics/interface/ball/premier.gbapal.lz"

	.align 2
gOpenPokeballGfx:: @ 8C02300
	.incbin "graphics/interface/ball_open.4bpp.lz"

	.align 2
gBlankGfxCompressed:: @ 8C0237C
	.incbin "graphics/interface/blank.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_146::
	.incbin "graphics/battle_anims/sprites/146.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_000::
	.incbin "graphics/battle_anims/sprites/000.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_003::
	.incbin "graphics/battle_anims/sprites/003.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_004::
	.incbin "graphics/battle_anims/sprites/004.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_005::
	.incbin "graphics/battle_anims/sprites/005.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_006::
	.incbin "graphics/battle_anims/sprites/006.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_115::
	.incbin "graphics/battle_anims/sprites/115.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_000::
	.incbin "graphics/battle_anims/sprites/000.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_003::
	.incbin "graphics/battle_anims/sprites/003.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_004::
	.incbin "graphics/battle_anims/sprites/004.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_005::
	.incbin "graphics/battle_anims/sprites/005.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_006::
	.incbin "graphics/battle_anims/sprites/006.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_161::
	.incbin "graphics/battle_anims/sprites/161.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_161::
	.incbin "graphics/battle_anims/sprites/161.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_007::
	.incbin "graphics/battle_anims/sprites/007.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_007::
	.incbin "graphics/battle_anims/sprites/007.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_008::
	.incbin "graphics/battle_anims/sprites/008.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_008::
	.incbin "graphics/battle_anims/sprites/008.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_010::
	.incbin "graphics/battle_anims/sprites/010.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_010::
	.incbin "graphics/battle_anims/sprites/010.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_009::
	.incbin "graphics/battle_anims/sprites/009.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_009::
	.incbin "graphics/battle_anims/sprites/009.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_011::
	.incbin "graphics/battle_anims/sprites/011.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_011::
	.incbin "graphics/battle_anims/sprites/011.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_012::
	.incbin "graphics/battle_anims/sprites/012.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_012::
	.incbin "graphics/battle_anims/sprites/012.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_152::
	.incbin "graphics/battle_anims/sprites/152.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_152::
	.incbin "graphics/battle_anims/sprites/152.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_013::
	.incbin "graphics/battle_anims/sprites/013.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_013::
	.incbin "graphics/battle_anims/sprites/013.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_015::
	.incbin "graphics/battle_anims/sprites/015.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_015::
	.incbin "graphics/battle_anims/sprites/015.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_016::
	.incbin "graphics/battle_anims/sprites/016.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_016::
	.incbin "graphics/battle_anims/sprites/016.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_017::
	.incbin "graphics/battle_anims/sprites/017.4bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C035B8.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_019::
	.incbin "graphics/battle_anims/sprites/019.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_019::
	.incbin "graphics/battle_anims/sprites/019.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_020::
	.incbin "graphics/battle_anims/sprites/020.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_020::
	.incbin "graphics/battle_anims/sprites/020.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_023::
	.incbin "graphics/battle_anims/sprites/023.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_023::
	.incbin "graphics/battle_anims/sprites/023.4bpp.lz"

	.align 2
	.incbin "graphics/unused/battle_anim_023.gbapal.lz"

	.align 2
	.incbin "graphics/unused/music_notes.4bpp.lz"
	
	.align 2
gBattleAnimSpritePalette_021::
	.incbin "graphics/battle_anims/sprites/021.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_021::
	.incbin "graphics/battle_anims/sprites/021.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_022::
	.incbin "graphics/battle_anims/sprites/022.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_025::
	.incbin "graphics/battle_anims/sprites/025.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_025::
	.incbin "graphics/battle_anims/sprites/025.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_024::
	.incbin "graphics/battle_anims/sprites/024.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_024::
	.incbin "graphics/battle_anims/sprites/024.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_031::
	.incbin "graphics/battle_anims/sprites/031.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_031::
	.incbin "graphics/battle_anims/sprites/031.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_032::
	.incbin "graphics/battle_anims/sprites/032.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_032::
	.incbin "graphics/battle_anims/sprites/032.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_026::
	.incbin "graphics/battle_anims/sprites/026.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_026::
	.incbin "graphics/battle_anims/sprites/026.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_027::
	.incbin "graphics/battle_anims/sprites/027.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_027::
	.incbin "graphics/battle_anims/sprites/027.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_028::
	.incbin "graphics/battle_anims/sprites/028.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_028::
	.incbin "graphics/battle_anims/sprites/028.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_029::
	.incbin "graphics/battle_anims/sprites/029.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_029::
	.incbin "graphics/battle_anims/sprites/029.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_030::
	.incbin "graphics/battle_anims/sprites/030.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_030::
	.incbin "graphics/battle_anims/sprites/030.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_033::
	.incbin "graphics/battle_anims/sprites/033.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_033::
	.incbin "graphics/battle_anims/sprites/033.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_034::
	.incbin "graphics/battle_anims/sprites/034.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_035::
	.incbin "graphics/battle_anims/sprites/035.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_036::
	.incbin "graphics/battle_anims/sprites/036.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_036::
	.incbin "graphics/battle_anims/sprites/036.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_037::
	.incbin "graphics/battle_anims/sprites/037.4bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C06D98.4bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C06D98.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C06D98_2.gbapal.lz"

@ old battle interface data, unused

	.align 2
	.incbin "graphics/unused/obi1.4bpp.lz"

	.align 2
	.incbin "graphics/unused/obi_palpak1.gbapal.lz" @ palettes 1-3

	.align 2
	.incbin "graphics/unused/old_pal4.gbapal.lz" @ 4 is by itself

	.align 2
	.incbin "graphics/unused/obi_palpak3.gbapal.lz" @ palettes 5-7

	.align 2
	.incbin "graphics/unused/obi2.4bpp.lz"

	.align 2
	.incbin "graphics/unused/old_battle_interface_tilemap.bin.lz"

	.align 2
gBattleAnimSpritePalette_038::
	.incbin "graphics/battle_anims/sprites/038.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_039::
	.incbin "graphics/battle_anims/sprites/039.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_038::
	.incbin "graphics/battle_anims/sprites/038.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_039::
	.incbin "graphics/battle_anims/sprites/039.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_040::
	.incbin "graphics/battle_anims/sprites/040.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_041::
	.incbin "graphics/battle_anims/sprites/041.4bpp.lz"

	@ why is this way up here?

	.align 2
gPartyMenuHpBar_Gfx::
	.incbin "graphics/interface/party_menu_hpbar.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_042::
	.incbin "graphics/battle_anims/sprites/042.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_042::
	.incbin "graphics/battle_anims/sprites/042.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_043::
	.incbin "graphics/battle_anims/sprites/043.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_043::
	.incbin "graphics/battle_anims/sprites/043.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_044::
	.incbin "graphics/battle_anims/sprites/044.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_044::
	.incbin "graphics/battle_anims/sprites/044.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_045::
	.incbin "graphics/battle_anims/sprites/045.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_045::
	.incbin "graphics/battle_anims/sprites/045.4bpp.lz"

	@ two unused window frames.

	.align 2
gUnknown_08C08F0C::
	.incbin "graphics/battle_interface/unused_window.4bpp.lz"

	.align 2
gUnknown_08C093C8::
	.incbin "graphics/battle_interface/unused_window.gbapal.lz"

	.align 2
gUnknown_08C093F0:: @ 8C093F0
	.incbin "graphics/interface/hp_numbers.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_046::
	.incbin "graphics/battle_anims/sprites/046.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_046::
	.incbin "graphics/battle_anims/sprites/046.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_047::
	.incbin "graphics/battle_anims/sprites/047.gbapal.lz"

	@ more unused windows
	.align 2
	.incbin "graphics/battle_interface/unused_window2.4bpp.lz"

	.align 2
	.incbin "graphics/battle_interface/unused_window2bar.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_048::
	.incbin "graphics/battle_anims/sprites/048.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_048::
	.incbin "graphics/battle_anims/sprites/048.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_049::
	.incbin "graphics/battle_anims/sprites/049.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_050::
	.incbin "graphics/battle_anims/sprites/050.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_050::
	.incbin "graphics/battle_anims/sprites/050.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_051::
	.incbin "graphics/battle_anims/sprites/051.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_052::
	.incbin "graphics/battle_anims/sprites/052.4bpp.lz"

	.align 2
	.incbin "graphics/unused/line_sketch.4bpp.lz" @ unused

	.align 2
	.incbin "graphics/unused/line_sketch.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_054::
	.incbin "graphics/battle_anims/sprites/054.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_054::
	.incbin "graphics/battle_anims/sprites/054.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_056::
	.incbin "graphics/battle_anims/sprites/056.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_056::
	.incbin "graphics/battle_anims/sprites/056.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_055::
	.incbin "graphics/battle_anims/sprites/055.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_057::
	.incbin "graphics/battle_anims/sprites/057.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_057::
	.incbin "graphics/battle_anims/sprites/057.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_058::
	.incbin "graphics/battle_anims/sprites/058.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_058::
	.incbin "graphics/battle_anims/sprites/058.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_059::
	.incbin "graphics/battle_anims/sprites/059.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_059::
	.incbin "graphics/battle_anims/sprites/059.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_060::
	.incbin "graphics/battle_anims/sprites/060.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_060::
	.incbin "graphics/battle_anims/sprites/060.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_061::
	.incbin "graphics/battle_anims/sprites/061.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_061::
	.incbin "graphics/battle_anims/sprites/061.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_062::
	.incbin "graphics/battle_anims/sprites/062.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_062::
	.incbin "graphics/battle_anims/sprites/062.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_063::
	.incbin "graphics/battle_anims/sprites/063.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_063::
	.incbin "graphics/battle_anims/sprites/063.gbapal.lz"

	.align 2
	.incbin "graphics/unused/metronome_hand_small.4bpp.lz" @ unused, was for metronome at one point

	.align 2
gBattleAnimSpritePalette_091::
	.incbin "graphics/battle_anims/sprites/091.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_065::
	.incbin "graphics/battle_anims/sprites/065.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_065::
	.incbin "graphics/battle_anims/sprites/065.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_066::
	.incbin "graphics/battle_anims/sprites/066.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_066::
	.incbin "graphics/battle_anims/sprites/066.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_070::
	.incbin "graphics/battle_anims/sprites/070.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_070::
	.incbin "graphics/battle_anims/sprites/070.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_071::
	.incbin "graphics/battle_anims/sprites/071.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_072::
	.incbin "graphics/battle_anims/sprites/072.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_072::
	.incbin "graphics/battle_anims/sprites/072.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_073::
	.incbin "graphics/battle_anims/sprites/073.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_073::
	.incbin "graphics/battle_anims/sprites/073.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_075::
	.incbin "graphics/battle_anims/sprites/075.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_075::
	.incbin "graphics/battle_anims/sprites/075.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_078::
	.incbin "graphics/battle_anims/sprites/078.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_078::
	.incbin "graphics/battle_anims/sprites/078.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_079::
	.incbin "graphics/battle_anims/sprites/079.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_080::
	.incbin "graphics/battle_anims/sprites/080.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_080::
	.incbin "graphics/battle_anims/sprites/080.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_081::
	.incbin "graphics/battle_anims/sprites/081.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_081::
	.incbin "graphics/battle_anims/sprites/081.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C0CA1C.bin"

	.align 2
	.incbin "graphics/unknown/unknown_C0CA40.bin"

	.align 2
	.incbin "graphics/unknown/unknown_C0CA64.bin"

	.align 2
	.incbin "graphics/unused/line_sketch_2.8bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C0CAE0.bin"

	.align 2
	.incbin "graphics/unused/line_sketch_2.bin.lz"

	.align 2
gBattleAnimSpriteSheet_082::
	.incbin "graphics/battle_anims/sprites/082.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_082::
	.incbin "graphics/battle_anims/sprites/082.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_083::
	.incbin "graphics/battle_anims/sprites/083.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_084::
	.incbin "graphics/battle_anims/sprites/084.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_085::
	.incbin "graphics/battle_anims/sprites/085.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_086::
	.incbin "graphics/battle_anims/sprites/086.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_088::
	.incbin "graphics/battle_anims/sprites/088.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_089::
	.incbin "graphics/battle_anims/sprites/089.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_090::
	.incbin "graphics/battle_anims/sprites/090.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_092::
	.incbin "graphics/battle_anims/sprites/092.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_093::
	.incbin "graphics/battle_anims/sprites/093.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_094::
	.incbin "graphics/battle_anims/sprites/094.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_D0D2B4.bin.lz"

	.align 2
gBattleAnimSpritePalette_095::
	.incbin "graphics/battle_anims/sprites/095.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_096::
	.incbin "graphics/battle_anims/sprites/096.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_097::
	.incbin "graphics/battle_anims/sprites/097.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_100::
	.incbin "graphics/battle_anims/sprites/100.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_101::
	.incbin "graphics/battle_anims/sprites/101.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_103::
	.incbin "graphics/battle_anims/sprites/103.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_083::
	.incbin "graphics/battle_anims/sprites/083.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_084::
	.incbin "graphics/battle_anims/sprites/084.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_085::
	.incbin "graphics/battle_anims/sprites/085.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_086::
	.incbin "graphics/battle_anims/sprites/086.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_088::
	.incbin "graphics/battle_anims/sprites/088.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_089::
	.incbin "graphics/battle_anims/sprites/089.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_090::
	.incbin "graphics/battle_anims/sprites/090.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_091::
	.incbin "graphics/battle_anims/sprites/091.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_092::
	.incbin "graphics/battle_anims/sprites/092.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_093::
	.incbin "graphics/battle_anims/sprites/093.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_094::
	.incbin "graphics/battle_anims/sprites/094.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_095::
	.incbin "graphics/battle_anims/sprites/095.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_096::
	.incbin "graphics/battle_anims/sprites/096.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_097::
	.incbin "graphics/battle_anims/sprites/097.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_098::
	.incbin "graphics/battle_anims/sprites/098.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_100::
	.incbin "graphics/battle_anims/sprites/100.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_101::
	.incbin "graphics/battle_anims/sprites/101.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_102::
	.incbin "graphics/battle_anims/sprites/102.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_103::
	.incbin "graphics/battle_anims/sprites/103.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_104::
	.incbin "graphics/battle_anims/sprites/104.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_104::
	.incbin "graphics/battle_anims/sprites/104.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_105::
	.incbin "graphics/battle_anims/sprites/105.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_105::
	.incbin "graphics/battle_anims/sprites/105.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_106::
	.incbin "graphics/battle_anims/sprites/106.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_107::
	.incbin "graphics/battle_anims/sprites/107.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_107::
	.incbin "graphics/battle_anims/sprites/107.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_108::
	.incbin "graphics/battle_anims/sprites/108.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_109::
	.incbin "graphics/battle_anims/sprites/109.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_109::
	.incbin "graphics/battle_anims/sprites/109.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_110::
	.incbin "graphics/battle_anims/sprites/110.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_111::
	.incbin "graphics/battle_anims/sprites/111.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_111::
	.incbin "graphics/battle_anims/sprites/111.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_112::
	.incbin "graphics/battle_anims/sprites/112.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_112::
	.incbin "graphics/battle_anims/sprites/112.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_113::
	.incbin "graphics/battle_anims/sprites/113.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_113::
	.incbin "graphics/battle_anims/sprites/113.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_114::
	.incbin "graphics/battle_anims/sprites/114.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_114::
	.incbin "graphics/battle_anims/sprites/114.gbapal.lz"

	.align 2
	.incbin "graphics/unused/blue_frame.bin.lz" @  P1, P2, P3 and P4 tilemaps?

	.align 2
	.incbin "graphics/unused/redyellowgreen_frame.bin.lz"

	.align 2
	.incbin "graphics/unused/color_frames.4bpp.lz"

	.align 2
	.incbin "graphics/unused/color_frames.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_115::
	.incbin "graphics/battle_anims/sprites/115.4bpp.lz"

	.align 2
	.incbin "graphics/unused/water_splash.8bpp.lz"

	.align 2
	.incbin "graphics/unused/water_splash.bin.lz"

	.align 2
	.incbin "graphics/unused/water_splash.gbapal.lz"

	.align 2
	.incbin "graphics/unused/basic_frame.4bpp.lz"

	.align 2
	.incbin "graphics/unused/basic_frame.gbapal.lz"

	.align 2
	.incbin "graphics/unused/basic_frame.bin.lz"

    .align 2
gBattleInterface_BallStatusBarPal:: @ 8C11B9C
	.incbin "graphics/battle_interface/ball_status_bar.gbapal"

    .align 2
gBattleInterface_BallDisplayPal:: @ 8C11BBC
	.incbin "graphics/battle_interface/ball_display.gbapal"

    .align 2
gHealthboxElementsGfxTable:: @ 8C11BDC
	.incbin "graphics/battle_interface/hpbar.4bpp"
	.incbin "graphics/battle_interface/expbar.4bpp"
	.incbin "graphics/battle_interface/status_psn.4bpp"
	.incbin "graphics/battle_interface/status_par.4bpp"
	.incbin "graphics/battle_interface/status_slp.4bpp"
	.incbin "graphics/battle_interface/status_frz.4bpp"
	.incbin "graphics/battle_interface/status_brn.4bpp"
	.incbin "graphics/battle_interface/misc.4bpp"
	.incbin "graphics/battle_interface/hpbar_anim.4bpp"
	.incbin "graphics/battle_interface/misc_frameend.4bpp"

    .align 2
gBattleInterface_BallDisplayGfx:: @ 8C1241C
	.incbin "graphics/battle_interface/ball_display.4bpp"

    .align 2
gUnknown_08C1249C:: @ 8C1249C
	.incbin "graphics/battle_interface/ball_display_unused_extra.4bpp"
	.incbin "graphics/battle_interface/status2.4bpp" @ these three duplicate sets of graphics are for the opponent pokemon and are also for use in double battles. they use dynamic palettes so coloring them is an extreme headache and wont be done for now.
	.incbin "graphics/battle_interface/status3.4bpp"
	.incbin "graphics/battle_interface/status4.4bpp"
	.incbin "graphics/unknown/unknown_D12FEC.4bpp"
	.incbin "graphics/unknown/unknown_D1300C.4bpp"

	@ even more seemingly unused windows. lovely.
	.incbin "graphics/battle_interface/unused_window3.4bpp.lz"
	.incbin "graphics/battle_interface/unused_window4.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_116::
	.incbin "graphics/battle_anims/sprites/116.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_116::
	.incbin "graphics/battle_anims/sprites/116.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_117::
	.incbin "graphics/battle_anims/sprites/117.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_117::
	.incbin "graphics/battle_anims/sprites/117.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_118::
	.incbin "graphics/battle_anims/sprites/118.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_118::
	.incbin "graphics/battle_anims/sprites/118.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_119::
	.incbin "graphics/battle_anims/sprites/119.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_119::
	.incbin "graphics/battle_anims/sprites/119.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_120::
	.incbin "graphics/battle_anims/sprites/120.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_120::
	.incbin "graphics/battle_anims/sprites/120.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_121::
	.incbin "graphics/battle_anims/sprites/121.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_121::
	.incbin "graphics/battle_anims/sprites/121.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_122::
	.incbin "graphics/battle_anims/sprites/122.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_122::
	.incbin "graphics/battle_anims/sprites/122.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_123::
	.incbin "graphics/battle_anims/sprites/123.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_124::
	.incbin "graphics/battle_anims/sprites/124.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_124::
	.incbin "graphics/battle_anims/sprites/124.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_125::
	.incbin "graphics/battle_anims/sprites/125.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_125::
	.incbin "graphics/battle_anims/sprites/125.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_126::
	.incbin "graphics/battle_anims/sprites/126.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_126::
	.incbin "graphics/battle_anims/sprites/126.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_127::
	.incbin "graphics/battle_anims/sprites/127.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_127::
	.incbin "graphics/battle_anims/sprites/127.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_128::
	.incbin "graphics/battle_anims/sprites/128.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_128::
	.incbin "graphics/battle_anims/sprites/128.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_129::
	.incbin "graphics/battle_anims/sprites/129.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_130::
	.incbin "graphics/battle_anims/sprites/130.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_130::
	.incbin "graphics/battle_anims/sprites/130.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_131::
	.incbin "graphics/battle_anims/sprites/131.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_132::
	.incbin "graphics/battle_anims/sprites/132.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_132::
	.incbin "graphics/battle_anims/sprites/132.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_133::
	.incbin "graphics/battle_anims/sprites/133.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_133::
	.incbin "graphics/battle_anims/sprites/133.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_134::
	.incbin "graphics/battle_anims/sprites/134.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_076::
	.incbin "graphics/battle_anims/sprites/076.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_076::
	.incbin "graphics/battle_anims/sprites/076.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_077::
	.incbin "graphics/battle_anims/sprites/077.4bpp.lz"

	.align 2
	.incbin "graphics/unused/old_contest.4bpp.lz"

	.align 2
	.incbin "graphics/unused/old_contest.gbapal.lz"

	.align 2
	.incbin "graphics/unused/old_contest.bin.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C15BC0.bin.lz"

	.align 2
	.incbin "graphics/unused/old_contest_2.4bpp.lz"

	.align 2
gUnknown_08C16E90:: @ 8C16E90
	.incbin "graphics/unused/old_contest_2.gbapal.lz"

	.align 2
gUnknown_08C16FA8:: @ 8C16FA8
	.incbin "graphics/unused/old_contest_2.bin.lz"

	.align 2
gUnknown_08C17170:: @ 8C17170
	.incbin "graphics/unknown/unknown_C17170.bin.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C17410.bin.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C1751C.bin.lz"

	.align 2
gUnknown_08C17980:: @ 8C17980
	.incbin "graphics/unknown/unknown_C17980.bin.lz"

	.align 2
gUnknown_08C17AB0:: @ 8C17AB0
	.incbin "graphics/contest/misc.4bpp.lz"

	.align 2
gUnknown_08C1850C:: @ 8C1850C
	.incbin "graphics/contest/audience.4bpp.lz"

	.align 2
	.incbin "graphics/contest/faces.4bpp.lz"

	.align 2
gContestJudgeSymbolsGfx::
	.incbin "graphics/contest/judge_symbols.4bpp.lz"

	.align 2
gContest3Pal::
	.incbin "graphics/contest/judge_symbols.gbapal.lz"

	.align 2
gTiles_8C19450::
	.incbin "graphics/contest/heart.4bpp"

	.align 2
	.incbin "graphics/unknown/unknown_C19470.4bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_C19470.gbapal.lz"

	.align 2
gUnknown_08C19588:: @ 8C19588
	.incbin "graphics/contest/misc_2.4bpp.lz"

	.align 2
gUnknown_08C19EEC:: @ 8C19EEC
	.incbin "graphics/contest/misc_2_tilemap_1.bin.lz"

	.align 2
gUnknown_08C1A000:: @ 8C1A000
	.incbin "graphics/contest/misc_2_tilemap_2.bin.lz"

	.align 2
gUnknown_08C1A12C:: @ 8C1A12C
	.incbin "graphics/contest/misc_2_tilemap_3.bin.lz"

	.align 2
gUnknown_08C1A2B4:: @ 8C1A2B4
	.incbin "graphics/contest/misc_2.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_135::
	.incbin "graphics/battle_anims/sprites/135.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_135::
	.incbin "graphics/battle_anims/sprites/135.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_Particles::
	.incbin "graphics/battle_anims/sprites/particles.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_136::
	.incbin "graphics/battle_anims/sprites/136.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_136::
	.incbin "graphics/battle_anims/sprites/136.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_137::
	.incbin "graphics/battle_anims/sprites/137.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_139::
	.incbin "graphics/battle_anims/sprites/139.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_139::
	.incbin "graphics/battle_anims/sprites/139.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_145::
	.incbin "graphics/battle_anims/sprites/145.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_138::
	.incbin "graphics/battle_anims/sprites/138.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_140::
	.incbin "graphics/battle_anims/sprites/140.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_140::
	.incbin "graphics/battle_anims/sprites/140.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_141::
	.incbin "graphics/battle_anims/sprites/141.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_141::
	.incbin "graphics/battle_anims/sprites/141.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_142::
	.incbin "graphics/battle_anims/sprites/142.4bpp.lz"

	.align 2
	.incbin "graphics/unused/old_beatup.4bpp.lz"

	.align 2
	.incbin "graphics/unused/old_beatup.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_147::
	.incbin "graphics/battle_anims/sprites/147.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_147::
	.incbin "graphics/battle_anims/sprites/147.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_149::
	.incbin "graphics/battle_anims/sprites/149.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_148::
	.incbin "graphics/battle_anims/sprites/148.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_148::
	.incbin "graphics/battle_anims/sprites/148.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_259::
	.incbin "graphics/battle_anims/sprites/259.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_074::
	.incbin "graphics/battle_anims/sprites/074.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_074::
	.incbin "graphics/battle_anims/sprites/074.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_150::
	.incbin "graphics/battle_anims/sprites/150.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_150::
	.incbin "graphics/battle_anims/sprites/150.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_151::
	.incbin "graphics/battle_anims/sprites/151.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_153::
	.incbin "graphics/battle_anims/sprites/153.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_153::
	.incbin "graphics/battle_anims/sprites/153.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_154::
	.incbin "graphics/battle_anims/sprites/154.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_154::
	.incbin "graphics/battle_anims/sprites/154.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_155::
	.incbin "graphics/battle_anims/sprites/155.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_155::
	.incbin "graphics/battle_anims/sprites/155.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_156::
	.incbin "graphics/battle_anims/sprites/156.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_156::
	.incbin "graphics/battle_anims/sprites/156.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_157::
	.incbin "graphics/battle_anims/sprites/157.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_157::
	.incbin "graphics/battle_anims/sprites/157.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_158::
	.incbin "graphics/battle_anims/sprites/158.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_158::
	.incbin "graphics/battle_anims/sprites/158.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_159::
	.incbin "graphics/battle_anims/sprites/159.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_159::
	.incbin "graphics/battle_anims/sprites/159.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_160::
	.incbin "graphics/battle_anims/sprites/160.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_160::
	.incbin "graphics/battle_anims/sprites/160.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_144::
	.incbin "graphics/battle_anims/sprites/144.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_144::
	.incbin "graphics/battle_anims/sprites/144.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_D1C060.4bpp.lz"

	.align 2
	.incbin "graphics/unknown/unknown_D1C060.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_D1C060.bin.lz"

	.align 2
gBattleAnimSpriteSheet_162::
	.incbin "graphics/battle_anims/sprites/162.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_162::
	.incbin "graphics/battle_anims/sprites/162.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_163::
	.incbin "graphics/battle_anims/sprites/163.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_163::
	.incbin "graphics/battle_anims/sprites/163.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_288::
	.incbin "graphics/battle_anims/sprites/288.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_164::
	.incbin "graphics/battle_anims/sprites/164.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_165::
	.incbin "graphics/battle_anims/sprites/165.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_166::
	.incbin "graphics/battle_anims/sprites/166.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_166::
	.incbin "graphics/battle_anims/sprites/166.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_167::
	.incbin "graphics/battle_anims/sprites/167.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_168::
	.incbin "graphics/battle_anims/sprites/168.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_169::
	.incbin "graphics/battle_anims/sprites/169.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_170::
	.incbin "graphics/battle_anims/sprites/170.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_171::
	.incbin "graphics/battle_anims/sprites/171.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_171::
	.incbin "graphics/battle_anims/sprites/171.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_172::
	.incbin "graphics/battle_anims/sprites/172.gbapal.lz"

	.align 2
gContestJudgeGfx::
	.incbin "graphics/contest/judge.4bpp.lz"

	.align 2
gContest2Pal:: @ 8C1C6B8
	.incbin "graphics/contest/judge.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_001::
	.incbin "graphics/battle_anims/sprites/001.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_001::
	.incbin "graphics/battle_anims/sprites/001.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_173::
	.incbin "graphics/battle_anims/sprites/173.4bpp.lz"

	.align 2
gBattleAnimBackgroundImage_00::
	.incbin "graphics/battle_anims/backgrounds/00.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_00::
	.incbin "graphics/battle_anims/backgrounds/00.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_00::
	.incbin "graphics/battle_anims/backgrounds/00.bin.lz"

	.align 2
gUnknown_08C1D0AC:: @ 8C1D0AC
	.incbin "graphics/battle_anims/masks/metal_shine.4bpp.lz"

	.align 2
gUnknown_08C1D1E8:: @ 8C1D1E8
	.incbin "graphics/battle_anims/masks/metal_shine.gbapal.lz"

	.align 2
gUnknown_08C1D210:: @ 8C1D210
	.incbin "graphics/battle_anims/masks/metal_shine.bin.lz"

	.align 2
	.incbin "graphics/unused/goosuto.4bpp.lz" @ ghost

	.align 2
	.incbin "graphics/unused/goosuto.gbapal.lz"

	.align 2
	.incbin "graphics/unused/goosuto.bin.lz"

	.align 2
gBattleAnimSpriteSheet_174::
	.incbin "graphics/battle_anims/sprites/174.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_174::
	.incbin "graphics/battle_anims/sprites/174.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_175::
	.incbin "graphics/battle_anims/sprites/175.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_175::
	.incbin "graphics/battle_anims/sprites/175.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_176::
	.incbin "graphics/battle_anims/sprites/176.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_176::
	.incbin "graphics/battle_anims/sprites/176.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_177::
	.incbin "graphics/battle_anims/sprites/177.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_177::
	.incbin "graphics/battle_anims/sprites/177.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_178::
	.incbin "graphics/battle_anims/sprites/178.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_178::
	.incbin "graphics/battle_anims/sprites/178.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_179::
	.incbin "graphics/battle_anims/sprites/179.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_179::
	.incbin "graphics/battle_anims/sprites/179.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_180::
	.incbin "graphics/battle_anims/sprites/180.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_181::
	.incbin "graphics/battle_anims/sprites/181.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_182::
	.incbin "graphics/battle_anims/sprites/182.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_182::
	.incbin "graphics/battle_anims/sprites/182.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_183::
	.incbin "graphics/battle_anims/sprites/183.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_183::
	.incbin "graphics/battle_anims/sprites/183.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_184::
	.incbin "graphics/battle_anims/sprites/184.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_184::
	.incbin "graphics/battle_anims/sprites/184.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_185::
	.incbin "graphics/battle_anims/sprites/185.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_185::
	.incbin "graphics/battle_anims/sprites/185.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_03::
	.incbin "graphics/battle_anims/backgrounds/03.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_03::
	.incbin "graphics/battle_anims/backgrounds/03.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_03::
	.incbin "graphics/battle_anims/backgrounds/03.bin.lz"

	.align 2
gBattleAnimSpriteSheet_187::
	.incbin "graphics/battle_anims/sprites/187.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_187::
	.incbin "graphics/battle_anims/sprites/187.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_186::
	.incbin "graphics/battle_anims/sprites/186.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_186::
	.incbin "graphics/battle_anims/sprites/186.gbapal.lz"

	.align 2
gUnknown_08C1F1C8:: @ 8C1F1C8
	.incbin "graphics/battle_interface/window.4bpp.lz"

	.align 2
gUnknown_08C1F46C:: @ 8C1F46C
	.incbin "graphics/battle_interface/window2.4bpp.lz"

	.align 2
gUnknown_08C1F5E8:: @ 8C1F5E8
	.incbin "graphics/battle_interface/window3.4bpp.lz"

	.align 2
gUnknown_08C1F76C:: @ 8C1F76C
	.incbin "graphics/battle_interface/window4.4bpp.lz"

	.align 2
gUnknown_08C1F8E8:: @ 8C1F8E8
	.incbin "graphics/battle_interface/window5.4bpp.lz"

	.align 2
	.incbin "graphics/unused/shadow.4bpp.lz"

	.align 2
	.incbin "graphics/unused/shadow.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_014::
	.incbin "graphics/battle_anims/sprites/014.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_014::
	.incbin "graphics/battle_anims/sprites/014.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_190::
	.incbin "graphics/battle_anims/sprites/190.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_190::
	.incbin "graphics/battle_anims/sprites/190.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_191::
	.incbin "graphics/battle_anims/sprites/191.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_191::
	.incbin "graphics/battle_anims/sprites/191.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_189::
	.incbin "graphics/battle_anims/sprites/189.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_189::
	.incbin "graphics/battle_anims/sprites/189.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_192::
	.incbin "graphics/battle_anims/sprites/192.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_192::
	.incbin "graphics/battle_anims/sprites/192.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_193::
	.incbin "graphics/battle_anims/sprites/193.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_193::
	.incbin "graphics/battle_anims/sprites/193.gbapal.lz"

	.align 2
gUnknown_08C20668:: @ 8C20668
	.incbin "graphics/battle_anims/masks/curse.4bpp.lz"

	.align 2
gUnknown_08C20684:: @ 8C20684
	.incbin "graphics/battle_anims/masks/curse.bin.lz"

	.align 2
gBattleAnimSpriteSheet_002:: @ 8D20B30
	.incbin "graphics/battle_anims/sprites/002.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_002:: @ 8D20C14
	.incbin "graphics/battle_anims/sprites/002.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_196:: @ 8D20C3C
	.incbin "graphics/battle_anims/sprites/196.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_196:: @ 8D20FE0
	.incbin "graphics/battle_anims/sprites/196.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_194:: @ 8D20FF8
	.incbin "graphics/battle_anims/sprites/194.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_194:: @ 8D21330
	.incbin "graphics/battle_anims/sprites/194.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_195:: @ 8D21358
	.incbin "graphics/battle_anims/sprites/195.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_195:: @ 8D21410
	.incbin "graphics/battle_anims/sprites/195.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_197:: @ 8D21430
	.incbin "graphics/battle_anims/sprites/197.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_197:: @ 8D215A0
	.incbin "graphics/battle_anims/sprites/197.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_198:: @ 8D215C8
	.incbin "graphics/battle_anims/sprites/198.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_198:: @ 8D219B8
	.incbin "graphics/battle_anims/sprites/198.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_199:: @ 8D219E0
	.incbin "graphics/battle_anims/sprites/199.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_199:: @ 8D21AA8
	.incbin "graphics/battle_anims/sprites/199.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_200:: @ 8D21AC4
	.incbin "graphics/battle_anims/sprites/200.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_200:: @ 8D21C04
	.incbin "graphics/battle_anims/sprites/200.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_201:: @ 8D21C20
	.incbin "graphics/battle_anims/sprites/201.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_201:: @ 8D22290
	.incbin "graphics/battle_anims/sprites/201.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_204:: @ 8D222B8
	.incbin "graphics/battle_anims/sprites/204.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_204:: @ 8D2242C
	.incbin "graphics/battle_anims/sprites/204.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_202:: @ 8D22454
	.incbin "graphics/battle_anims/sprites/202.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_202:: @ 8D225BC
	.incbin "graphics/battle_anims/sprites/202.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_203:: @ 8D225E0
	.incbin "graphics/battle_anims/sprites/203.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_203:: @ 8D2278C
	.incbin "graphics/battle_anims/sprites/203.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_206:: @ 8D227B0
	.incbin "graphics/battle_anims/sprites/206.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_206:: @ 8D229BC
	.incbin "graphics/battle_anims/sprites/206.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_205:: @ 8D22A50
	.incbin "graphics/battle_anims/sprites/205.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_205:: @ 8D22C84
	.incbin "graphics/battle_anims/sprites/205.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_207:: @ 8D22CA8
	.incbin "graphics/battle_anims/sprites/207.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_207:: @ 8D22D74
	.incbin "graphics/battle_anims/sprites/207.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_208:: @ 8D22D98
	.incbin "graphics/battle_anims/sprites/208.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_209:: @ 8D23188
	.incbin "graphics/battle_anims/sprites/209.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_209:: @ 8D23490
	.incbin "graphics/battle_anims/sprites/209.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_064:: @ 8D234B0
	.incbin "graphics/battle_anims/sprites/064.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_064:: @ 8D235A0
	.incbin "graphics/battle_anims/sprites/064.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_210:: @ 8D235C4
	.incbin "graphics/battle_anims/sprites/210.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_219:: @ 8D2362C
	.incbin "graphics/battle_anims/sprites/219.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_210:: @ 8D2364C
	.incbin "graphics/battle_anims/sprites/210.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_216:: @ 8D2366C
	.incbin "graphics/battle_anims/sprites/216.gbapal.lz"

	.align 2
gUnknown_08C232E0:: @ 8C232E0
	.incbin "graphics/battle_anims/backgrounds/attract.4bpp.lz"

	.align 2
gUnknown_08C23D50:: @ 8C23D50
	.incbin "graphics/battle_anims/backgrounds/attract.gbapal.lz"

	.align 2
gUnknown_08C23D78:: @ 8C23D78
	.incbin "graphics/battle_anims/backgrounds/attract.bin.lz"

	.align 2
gBattleAnimSpriteSheet_217:: @ 8D243A0
	.incbin "graphics/battle_anims/sprites/217.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_217:: @ 8D24408
	.incbin "graphics/battle_anims/sprites/217.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_212:: @ 8D24428
	.incbin "graphics/battle_anims/sprites/212.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_211:: @ 8D2465C
	.incbin "graphics/battle_anims/sprites/211.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_213:: @ 8D246AC
	.incbin "graphics/battle_anims/sprites/213.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_211:: @ 8D24918
	.incbin "graphics/battle_anims/sprites/211.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_214:: @ 8D2493C
	.incbin "graphics/battle_anims/sprites/214.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_215:: @ 8D24BCC
	.incbin "graphics/battle_anims/sprites/215.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_215:: @ 8D24D58
	.incbin "graphics/battle_anims/sprites/215.gbapal.lz"

	.align 2
gUnknown_08C249D0:: @ 8C249D0
	.incbin "graphics/battle_anims/backgrounds/scary_face.gbapal.lz"

	.align 2
gUnknown_08C249F8:: @ 8C249F8
	.incbin "graphics/battle_anims/backgrounds/scary_face.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_218:: @ 8D24FD4
	.incbin "graphics/battle_anims/sprites/218.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_218:: @ 8D24FFC
	.incbin "graphics/battle_anims/sprites/218.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_087:: @ 8D250A8
	.incbin "graphics/battle_anims/sprites/087.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_087:: @ 8D25100
	.incbin "graphics/battle_anims/sprites/087.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_018:: @ 8D25128
	.incbin "graphics/battle_anims/sprites/018.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_018:: @ 8D25164
	.incbin "graphics/battle_anims/sprites/018.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_220:: @ 8D25180
	.incbin "graphics/battle_anims/sprites/220.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_220:: @ 8D251A8
	.incbin "graphics/battle_anims/sprites/220.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_221:: @ 8D252D4
	.incbin "graphics/battle_anims/sprites/221.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_221:: @ 8D252F4
	.incbin "graphics/battle_anims/sprites/221.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_222:: @ 8D25558
	.incbin "graphics/battle_anims/sprites/222.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_222:: @ 8D25844
	.incbin "graphics/battle_anims/sprites/222.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_223:: @ 8D2586C
	.incbin "graphics/battle_anims/sprites/223.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_223:: @ 8D2588C
	.incbin "graphics/battle_anims/sprites/223.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_224:: @ 8D25B20
	.incbin "graphics/battle_anims/sprites/224.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_224:: @ 8D25B40
	.incbin "graphics/battle_anims/sprites/224.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_230:: @ 8D25C3C
	.incbin "graphics/battle_anims/sprites/230.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_230:: @ 8D25C64
	.incbin "graphics/battle_anims/sprites/230.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_228:: @ 8D25EA8
	.incbin "graphics/battle_anims/sprites/228.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_228:: @ 8D25EC8
	.incbin "graphics/battle_anims/sprites/228.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_04:: @ 8D25F70
	.incbin "graphics/battle_anims/backgrounds/04.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_04:: @ 8D25F98
	.incbin "graphics/battle_anims/backgrounds/04.4bpp.lz"

	.align 2
gBattleAnimBackgroundTilemap_04:: @ 8D26D04
	.incbin "graphics/battle_anims/backgrounds/04.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_05:: @ 8D27200
	.incbin "graphics/battle_anims/backgrounds/05.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_06:: @ 8D276D0
	.incbin "graphics/battle_anims/backgrounds/06.bin.lz"

	.align 2
gBattleAnimSpriteSheet_225:: @ 8D27B10
	.incbin "graphics/battle_anims/sprites/225.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_225:: @ 8D27C94
	.incbin "graphics/battle_anims/sprites/225.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_227:: @ 8D27CBC
	.incbin "graphics/battle_anims/sprites/227.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_226:: @ 8D27E04
	.incbin "graphics/battle_anims/sprites/226.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_226:: @ 8D27E90
	.incbin "graphics/battle_anims/sprites/226.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_229:: @ 8D27EB4
	.incbin "graphics/battle_anims/sprites/229.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_229:: @ 8D28070
	.incbin "graphics/battle_anims/sprites/229.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_099:: @ 8D28098
	.incbin "graphics/battle_anims/sprites/099.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_099:: @ 8D281B8
	.incbin "graphics/battle_anims/sprites/099.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_232:: @ 8D281E0
	.incbin "graphics/battle_anims/sprites/232.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_231:: @ 8D28718
	.incbin "graphics/battle_anims/sprites/231.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_231:: @ 8D28740
	.incbin "graphics/battle_anims/sprites/231.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_233:: @ 8D28910
	.incbin "graphics/battle_anims/sprites/233.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_233:: @ 8D28994
	.incbin "graphics/battle_anims/sprites/233.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_234:: @ 8D289BC
	.incbin "graphics/battle_anims/sprites/234.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_234:: @ 8D28B7C
	.incbin "graphics/battle_anims/sprites/234.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_238:: @ 8D28BA0
	.incbin "graphics/battle_anims/sprites/238.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_238:: @ 8D28C08
	.incbin "graphics/battle_anims/sprites/238.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_235:: @ 8D28C2C
	.incbin "graphics/battle_anims/sprites/235.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_235:: @ 8D28C7C
	.incbin "graphics/battle_anims/sprites/235.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_236:: @ 8D28C98
	.incbin "graphics/battle_anims/sprites/236.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_237:: @ 8D28CB4
	.incbin "graphics/battle_anims/sprites/237.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_07:: @ 8D28CD0
	.incbin "graphics/battle_anims/backgrounds/07.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_07:: @ 8D28E78
	.incbin "graphics/battle_anims/backgrounds/07.gbapal.lz"

	.align 2
gBattleAnimBackgroundPalette_18:: @ 8D28EA0
	.incbin "graphics/battle_anims/backgrounds/18.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_07:: @ 8D28EC8
	.incbin "graphics/battle_anims/backgrounds/07.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_08:: @ 8D29058
	.incbin "graphics/battle_anims/backgrounds/08.bin.lz"

	.align 2
gBattleAnimBackgroundImage_20:: @ 8D291E4
	.incbin "graphics/battle_anims/backgrounds/20.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_20:: @ 8D29C0C
	.incbin "graphics/battle_anims/backgrounds/20.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_20:: @ 8D29C2C
	.incbin "graphics/battle_anims/backgrounds/20.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_09:: @ 8D29E30
	.incbin "graphics/battle_anims/backgrounds/09.bin.lz"

	.align 2
gBattleAnimBackgroundPalette_09:: @ 8D2A128
	.incbin "graphics/battle_anims/backgrounds/09.gbapal.lz"

	.align 2
gBattleAnimBackgroundPalette_22:: @ 8D2A148
	.incbin "graphics/battle_anims/backgrounds/22.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_09:: @ 8D2A168
	.incbin "graphics/battle_anims/backgrounds/09.4bpp.lz"

	.align 2
gBattleAnimBackgroundTilemap_10:: @ 8D2A6E8
	.incbin "graphics/battle_anims/backgrounds/10.bin.lz"

	.align 2
gUnknown_08C2A634:: @ 8C2A634
	.incbin "graphics/battle_anims/masks/morning_sun.4bpp.lz"

	.align 2
gUnknown_08C2A6D4:: @ 8C2A6D4
	.incbin "graphics/battle_anims/masks/morning_sun.gbapal.lz"

	.align 2
gUnknown_08C2A6EC:: @ 8C2A6EC
	.incbin "graphics/battle_anims/masks/morning_sun.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_12:: @ 8D2ABB4
	.incbin "graphics/battle_anims/backgrounds/12.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_13:: @ 8D2AE7C
	.incbin "graphics/battle_anims/backgrounds/13.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_14:: @ 8D2B178
	.incbin "graphics/battle_anims/backgrounds/14.bin.lz"

	.align 2
gBattleAnimBackgroundImage_12:: @ 8D2B408
	.incbin "graphics/battle_anims/backgrounds/12.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_12:: @ 8D2C170
	.incbin "graphics/battle_anims/backgrounds/12.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_11:: @ 8D2C190
	.incbin "graphics/battle_anims/backgrounds/11.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_11:: @ 8D2CB2C
	.incbin "graphics/battle_anims/backgrounds/11.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_11:: @ 8D2CB54
	.incbin "graphics/battle_anims/backgrounds/11.bin.lz"

	.align 2
gBattleAnimSpriteSheet_239:: @ 8D2CE4C
	.incbin "graphics/battle_anims/sprites/239.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_239:: @ 8D2CF30
	.incbin "graphics/battle_anims/sprites/239.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_143:: @ 8D2CF58
	.incbin "graphics/battle_anims/sprites/143.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_143:: @ 8D2D188
	.incbin "graphics/battle_anims/sprites/143.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_240:: @ 8D2D1A0
	.incbin "graphics/battle_anims/sprites/240.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_240:: @ 8D2D240
	.incbin "graphics/battle_anims/sprites/240.gbapal.lz"

	.align 2
gSubstituteDollPal:: @ 8C2CEBC
	.incbin "graphics/battle_anims/sprites/substitute.gbapal.lz"

	.align 2
gSubstituteDollGfx:: @ 8C2CEE0
	.incbin "graphics/battle_anims/sprites/substitute.4bpp.lz"

	.align 2
gSubstituteDollTilemap:: @ 8C2D120
	.incbin "graphics/battle_anims/sprites/substitute.bin.lz"

	.align 2
gUnknown_08C2D348:: @ 8C2D348
	.incbin "graphics/battle_anims/sprites/241.4bpp.lz"

	.align 2
gUnknown_08C2D40C:: @ 8C2D40C
	.incbin "graphics/battle_anims/sprites/241.gbapal.lz"

	.align 2
gContestConfetti_Gfx:: @ 8C2D428
	.incbin "graphics/misc/confetti.4bpp.lz"

	.align 2
gContestConfetti_Pal:: @ 8C2D548
	.incbin "graphics/misc/confetti.gbapal.lz"

	.align 2
gUnknown_08C2D570:: @ 8C2D570
	.incbin "graphics/battle_anims/sprites/242.4bpp.lz"

	.align 2
gUnknown_08C2D6AC:: @ 8C2D6AC
	.incbin "graphics/battle_anims/sprites/242.gbapal.lz"

	.align 2
gUnknown_08C2D6D0:: @ 8C2D6D0
	.incbin "graphics/battle_anims/sprites/243.4bpp.lz"

	.align 2
gUnknown_08C2D6F8:: @ 8C2D6F8
	.incbin "graphics/battle_anims/sprites/243.gbapal.lz"

	.align 2
gUnknown_08C2D720:: @ 8C2D720
	.incbin "graphics/battle_anims/masks/stat.4bpp.lz"

	.align 2
gUnknown_08C2D930:: @ 8C2D930
	.incbin "graphics/battle_anims/masks/stat_tilemap_1.bin.lz"

	.align 2
gUnknown_08C2DA4C:: @ 8C2DA4C
	.incbin "graphics/battle_anims/masks/stat_tilemap_2.bin.lz"

	.align 2
gUnknown_08C2DB68:: @ 8C2DB68
	.incbin "graphics/battle_anims/masks/stat1.gbapal.lz"

	.align 2
gUnknown_08C2DB88:: @ 8C2DB88
	.incbin "graphics/battle_anims/masks/stat2.gbapal.lz"

	.align 2
gUnknown_08C2DBA8:: @ 8C2DBA8
	.incbin "graphics/battle_anims/masks/stat3.gbapal.lz"

	.align 2
gUnknown_08C2DBC8:: @ 8C2DBC8
	.incbin "graphics/battle_anims/masks/stat4.gbapal.lz"

	.align 2
gUnknown_08C2DBE8:: @ 8C2DBE8
	.incbin "graphics/battle_anims/masks/stat5.gbapal.lz"

	.align 2
gUnknown_08C2DC08:: @ 8C2DC08
	.incbin "graphics/battle_anims/masks/stat6.gbapal.lz"

	.align 2
gUnknown_08C2DC28:: @ 8C2DC28
	.incbin "graphics/battle_anims/masks/stat7.gbapal.lz"

	.align 2
gUnknown_08C2DC48:: @ 8C2DC48
	.incbin "graphics/battle_anims/masks/stat8.gbapal.lz"

	.align 2
gUnknown_08C2DC68:: @ 8C2DC68
	.incbin "graphics/battle_anims/masks/cure_bubbles.4bpp.lz"

	.align 2
gUnknown_08C2DDA4:: @ 8C2DDA4
	.incbin "graphics/battle_anims/masks/cure_bubbles.gbapal.lz"

	.align 2
gUnknown_08C2DDC4:: @ 8C2DDC4
	.incbin "graphics/battle_anims/masks/cure_bubbles.bin.lz"

	.align 2
gBattleAnimSpritePalette_245:: @ 8D2E28C
	.incbin "graphics/battle_anims/sprites/245.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_245:: @ 8D2E2B4
	.incbin "graphics/battle_anims/sprites/245.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_246:: @ 8D2E458
	.incbin "graphics/battle_anims/sprites/246.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_244:: @ 8D2E900
	.incbin "graphics/battle_anims/sprites/244.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_244:: @ 8D2E9DC
	.incbin "graphics/battle_anims/sprites/244.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_247:: @ 8D2E9F8
	.incbin "graphics/battle_anims/sprites/247.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_053:: @ 8D2EBDC
	.incbin "graphics/battle_anims/sprites/053.4bpp.lz"

	.align 2
gUnknown_08C2EA50:: @ 8C2EA50
	.incbin "graphics/battle_anims/masks/unknown_C2EA50.4bpp.lz"

	.align 2
gUnknown_08C2EA9C:: @ 8C2EA9C
	.incbin "graphics/battle_anims/masks/unknown_C2EA50.bin.lz"

	.align 2
gBattleAnimSpriteSheet_248:: @ 8D2EF50
	.incbin "graphics/battle_anims/sprites/248.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_248:: @ 8D2EF68
	.incbin "graphics/battle_anims/sprites/248.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_249:: @ 8D2EF80
	.incbin "graphics/battle_anims/sprites/249.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_249:: @ 8D2EFD0
	.incbin "graphics/battle_anims/sprites/249.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_250:: @ 8D2EFF0
	.incbin "graphics/battle_anims/sprites/250.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_251:: @ 8D2F1E4
	.incbin "graphics/battle_anims/sprites/251.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_251:: @ 8D2F248
	.incbin "graphics/battle_anims/sprites/251.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_252:: @ 8D2F260
	.incbin "graphics/battle_anims/sprites/252.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_252:: @ 8D2F378
	.incbin "graphics/battle_anims/sprites/252.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_253:: @ 8D2F39C
	.incbin "graphics/battle_anims/sprites/253.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_253:: @ 8D2F578
	.incbin "graphics/battle_anims/sprites/253.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_254:: @ 8D2F5A0
	.incbin "graphics/battle_anims/sprites/254.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_254:: @ 8D2F6D8
	.incbin "graphics/battle_anims/sprites/254.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_255:: @ 8D2F700
	.incbin "graphics/battle_anims/sprites/255.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_255:: @ 8D2F778
	.incbin "graphics/battle_anims/sprites/255.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_258:: @ 8D2F78C
	.incbin "graphics/battle_anims/sprites/258.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_258:: @ 8D2F874
	.incbin "graphics/battle_anims/sprites/258.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_256:: @ 8D2F89C
	.incbin "graphics/battle_anims/sprites/256.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_256:: @ 8D2FC28
	.incbin "graphics/battle_anims/sprites/256.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_257:: @ 8D2FC50
	.incbin "graphics/battle_anims/sprites/257.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_257:: @ 8D2FD6C
	.incbin "graphics/battle_anims/sprites/257.gbapal.lz"

	.incbin "graphics/unknown/unknown_C2F9E0.gbapal.lz" @ likely a palette

@ 8C2FA08
	.include "data/graphics/pokemon/graphics.inc"

@ 8D51DC8
	.include "data/graphics/trainers/graphics.inc"

	.align 2
gMonIcon_QuestionMark:: @ 8D774D0
	.incbin "graphics/pokemon/icons/question_mark_icon.4bpp"

	.align 2
gMonFootprint_QuestionMark:: @ 8D778D0
	.incbin "graphics/pokemon/footprints/question_mark_footprint.1bpp"

	.align 2
gUnknown_08D778F0:: @ 8D778F0
	.incbin "graphics/battle_transitions/vs_frame.4bpp.lz"

	.align 2
gUnknown_08D779D8:: @ 8D779D8
	.incbin "graphics/battle_transitions/vs_frame.bin.lz"

	.align 2
gUnknown_08D77AE4:: @ 8D77AE4
	.incbin "graphics/battle_transitions/vs_frame.gbapal.lz"

	.align 2
gUnknown_08D77B0C:: @ 8D77B0C
	.incbin "graphics/battle_transitions/vs.4bpp.lz"

	.align 2
gBattleTerrainTiles_TallGrass:: @ 8D77D68
	.incbin "graphics/battle_terrain/tall_grass/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_TallGrass:: @ 8D78318
	.incbin "graphics/battle_terrain/tall_grass/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_TallGrass:: @ 8D78350
	.incbin "graphics/battle_terrain/tall_grass/map.bin.lz"

	.align 2
gBattleTerrainTiles_LongGrass:: @ 8D78600
	.incbin "graphics/battle_terrain/long_grass/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_LongGrass:: @ 8D78C78
	.incbin "graphics/battle_terrain/long_grass/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_LongGrass:: @ 8D78CB8
	.incbin "graphics/battle_terrain/long_grass/map.bin.lz"

	.align 2
gBattleTerrainTiles_Sand:: @ 8D78F68
	.incbin "graphics/battle_terrain/sand/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Sand:: @ 8D79560
	.incbin "graphics/battle_terrain/sand/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_Sand:: @ 8D795A8
	.incbin "graphics/battle_terrain/sand/map.bin.lz"

	.align 2
gBattleTerrainTiles_Underwater:: @ 8D79858
	.incbin "graphics/battle_terrain/underwater/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Underwater:: @ 8D79E10
	.incbin "graphics/battle_terrain/underwater/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_Underwater:: @ 8D79E58
	.incbin "graphics/battle_terrain/underwater/map.bin.lz"

	.align 2
gBattleTerrainTiles_Water:: @ 8D7A108
	.incbin "graphics/battle_terrain/water/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Water:: @ 8D7A6DC
	.incbin "graphics/battle_terrain/water/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_Water:: @ 8D7A720
	.incbin "graphics/battle_terrain/water/map.bin.lz"

	.align 2
gBattleTerrainTiles_PondWater:: @ 8D7A9D0
	.incbin "graphics/battle_terrain/pond_water/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_PondWater:: @ 8D7AF78
	.incbin "graphics/battle_terrain/pond_water/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_PondWater:: @ 8D7AFB8
	.incbin "graphics/battle_terrain/pond_water/map.bin.lz"

	.align 2
gBattleTerrainTiles_Rock:: @ 8D7B268
	.incbin "graphics/battle_terrain/rock/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Rock:: @ 8D7B828
	.incbin "graphics/battle_terrain/rock/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_Rock:: @ 8D7B864
	.incbin "graphics/battle_terrain/rock/map.bin.lz"

	.align 2
gBattleTerrainTiles_Cave:: @ 8D7BB14
	.incbin "graphics/battle_terrain/cave/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Cave:: @ 8D7C10C
	.incbin "graphics/battle_terrain/cave/palette.gbapal.lz"

	.align 2
gBattleTerrainTilemap_Cave:: @ 8D7C154
	.incbin "graphics/battle_terrain/cave/map.bin.lz"

	.align 2
gBattleTerrainPalette_Plain:: @ 8D7C404
	.incbin "graphics/battle_terrain/plain/palette.gbapal.lz"

	.align 2
gBattleTerrainTiles_Building:: @ 8D7C440
	.incbin "graphics/battle_terrain/building/tiles.4bpp.lz"

	.align 2
gBattleTerrainPalette_Frontier:: @ 8D7C9EC
	.incbin "graphics/battle_terrain/stadium/battle_frontier.gbapal.lz" @ this is also used for link battles

	.align 2
gBattleTerrainTilemap_Building:: @ 8D7CA28
	.incbin "graphics/battle_terrain/building/map.bin.lz"

	.align 2
gBattleTerrainTiles_Stadium:: @ 8D7CCD8
	.incbin "graphics/battle_terrain/stadium/tiles.4bpp.lz"

	.align 2
gBattleTerrainTilemap_Stadium:: @ 8D7D2E0
	.incbin "graphics/battle_terrain/stadium/map.bin.lz"

	.align 2
gBattleTerrainTiles_Rayquaza:: @ 8D7D590
	.incbin "graphics/battle_terrain/sky/tiles.4bpp.lz"

	.align 2
gBattleTerrainTilemap_Rayquaza:: @ 8D7DC04
	.incbin "graphics/battle_terrain/sky/map.bin.lz"

	.align 2
gBattleTerrainPalette_Building:: @ 8D7DEB4
	.incbin "graphics/battle_terrain/building/palette.gbapal.lz"

	.align 2
gBattleTerrainPalette_Kyogre:: @ 8D7DEF4
	.incbin "graphics/battle_terrain/water/kyogre.gbapal.lz"

	.align 2
gBattleTerrainPalette_Groudon:: @ 8D7DF30
	.incbin "graphics/battle_terrain/cave/groudon.gbapal.lz"

	.align 2
gBattleTerrainPalette_BuildingGym:: @ 8D7DF88
	.incbin "graphics/battle_terrain/building/palette2.gbapal.lz"

	.align 2
gBattleTerrainPalette_BuildingLeader:: @ 8D7DFC4
	.incbin "graphics/battle_terrain/building/palette3.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumAqua:: @ 8D7E000
	.incbin "graphics/battle_terrain/stadium/palette1.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumMagma:: @ 8D7E060
	.incbin "graphics/battle_terrain/stadium/palette2.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumSidney:: @ 8D7E0CC
	.incbin "graphics/battle_terrain/stadium/palette3.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumPhoebe:: @ 8D7E11C
	.incbin "graphics/battle_terrain/stadium/palette4.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumGlacia:: @ 8D7E164
	.incbin "graphics/battle_terrain/stadium/palette5.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumDrake:: @ 8D7E1A8
	.incbin "graphics/battle_terrain/stadium/palette6.gbapal.lz"

	.align 2
gBattleTerrainPalette_StadiumWallace:: @ 8D7E1F8
	.incbin "graphics/battle_terrain/stadium/palette7.gbapal.lz"

	.align 2
gBattleTerrainPalette_Rayquaza:: @ 8D7E234
	.incbin "graphics/battle_terrain/sky/palette.gbapal.lz"

	.align 2
gBattleTerrainAnimTiles_TallGrass:: @ 8D7E280
	.incbin "graphics/battle_terrain/tall_grass/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_TallGrass:: @ 8D7E808
	.incbin "graphics/battle_terrain/tall_grass/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_LongGrass:: @ 8D7E9C4
	.incbin "graphics/battle_terrain/long_grass/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_LongGrass:: @ 8D7F0D4
	.incbin "graphics/battle_terrain/long_grass/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Sand:: @ 8D7F30C
	.incbin "graphics/battle_terrain/sand/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Sand:: @ 8D7F850
	.incbin "graphics/battle_terrain/sand/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Underwater:: @ 8D7F9F8
	.incbin "graphics/battle_terrain/underwater/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Underwater:: @ 8D7FEC4
	.incbin "graphics/battle_terrain/underwater/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Water:: @ 8D80054
	.incbin "graphics/battle_terrain/water/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Water:: @ 8D80660
	.incbin "graphics/battle_terrain/water/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_PondWater:: @ 8D80804
	.incbin "graphics/battle_terrain/pond_water/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_PondWater:: @ 8D80D50
	.incbin "graphics/battle_terrain/pond_water/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Rock:: @ 8D80E9C
	.incbin "graphics/battle_terrain/rock/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Rock:: @ 8D8147C
	.incbin "graphics/battle_terrain/rock/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Cave:: @ 8D81610
	.incbin "graphics/battle_terrain/cave/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Cave:: @ 8D81E2C
	.incbin "graphics/battle_terrain/cave/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Building:: @ 8D820D4
	.incbin "graphics/battle_terrain/building/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Building:: @ 8D824E4
	.incbin "graphics/battle_terrain/building/anim_map.bin.lz"

	.align 2
gBattleTerrainAnimTiles_Rayquaza:: @ 8D82608
	.incbin "graphics/battle_terrain/sky/anim_tiles.4bpp.lz"

	.align 2
gBattleTerrainAnimTilemap_Rayquaza:: @ 8D82C70
	.incbin "graphics/battle_terrain/sky/anim_map.bin.lz"

	.align 2
gUnknown_08D82F10:: @ 8D82F10
	.incbin "graphics/battle_frontier/tourney_bg.4bpp.lz"

	.align 2
gUnknown_08D834FC:: @ 8D834FC
	.incbin "graphics/battle_frontier/tourney_line.4bpp.lz" @ the red glow mask for the tourney advancement lines

	.align 2
gUnknown_08D83900:: @ 8D83900
	.incbin "graphics/unknown/unknown_D83900.bin.lz" @ tilemaps likely

	.align 2
gUnknown_08D83B2C:: @ 8D83B2C
	.incbin "graphics/unknown/unknown_D83B2C.bin.lz"

	.align 2
gUnknown_08D83C3C:: @ 8D83C3C
	.incbin "graphics/unknown/unknown_D83C3C.bin.lz"

	.align 2
gUnknown_08D83D50:: @ 8D83D50
	.incbin "graphics/battle_frontier/misc1.4bpp.lz"

	.align 2
gUnknown_08D84970:: @ 8D84970
	.incbin "graphics/unknown/unknown_D84970.bin.lz"

	.align 2
gUnknown_08D84F00:: @ 8D84F00
	.incbin "graphics/unknown/unknown_D84F00.bin.lz"

	.align 2
gBattleFrontierGfx_DomeOptions:: @ 8D85058
	.incbin "graphics/battle_frontier/options.4bpp.lz"

	.align 2
gUnknown_08D85358:: @ 8D85358
	.incbin "graphics/battle_frontier/options_pal1.gbapal.lz"

	.align 2
gUnknown_08D85444:: @ 8D85444
	.incbin "graphics/battle_frontier/options_pal2.gbapal.lz" @ pokeball pal

	.align 2
gUnknown_08D854C8:: @ 8D854C8
	.incbin "graphics/battle_frontier/options_pal3.gbapal.lz" @ arrow pal

	.align 2
gUnknown_08D854E8:: @ 8D854E8
	.incbin "graphics/battle_frontier/symbols.4bpp.lz"

	.align 2
gUnknown_08D855E8:: @ 8D855E8
	.incbin "graphics/battle_frontier/symbols.gbapal.lz"

	.align 2
gUnknown_08D85600:: @ 8D85600
	.incbin "graphics/battle_frontier/text.gbapal.lz" @ text palette for frontier text.

	.align 2
gUnknown_08D85620:: @ 8D85620
	.incbin "graphics/battle_frontier/text_pp.gbapal" @ text palette for PP text

	@ dome anim pals

	.align 2
gUnknown_08D85640:: @ 8D85640
	.incbin "graphics/battle_frontier/dome_anim1.gbapal"

	.align 2
gUnknown_08D85660:: @ 8D85660
	.incbin "graphics/battle_frontier/dome_anim2.gbapal"

	.align 2
gUnknown_08D85680:: @ 8D85680
	.incbin "graphics/battle_frontier/dome_anim3.gbapal"

	.align 2
gUnknown_08D856A0:: @ 8D856A0
	.incbin "graphics/battle_frontier/dome_anim4.gbapal"

	@ 8D856C0
	.2byte 0x013F, 0x0119, 0x0113, 0x010E @ unused?

	.align 2
gUnknown_08D856C8:: @ 8D856C8
	.incbin "graphics/battle_frontier/pyramid_light.gbapal" @ unfaded pal for the player light in battle pyramid

	.align 2
gUnknown_08D857A8:: @ 8D857A8
	.incbin "graphics/battle_frontier/battle_tilemap1.bin.lz"

	.align 2
gUnknown_08D85A1C:: @ 8D85A1C
	.incbin "graphics/battle_frontier/battle_tilemap2.bin.lz"

gUnknown_08D85C50:: @ 8D85C50
	.incbin "baserom.gba", 0xd85c50, 0x60

	.align 2
gIntro2BrendanNoTurnPal:: @ 8D85CB0
	.incbin "graphics/intro/intro2_brendan_noturn.gbapal"

	.align 2
gUnknown_08D85CD0:: @ 8D85CD0
	.incbin "baserom.gba", 0xd85cd0, 0x182

gUnknown_08D85E52:: @ 8D85E52
	.incbin "baserom.gba", 0xd85e52, 0x20

gUnknown_08D85E72:: @ 8D85E72
	.incbin "baserom.gba", 0xd85e72, 0xa

gUnknown_08D85E7C:: @ 8D85E7C
	.incbin "baserom.gba", 0xd85e7c, 0x54

	.align 2
gIntro2VolbeatPal:: @ 8D85ED0
	.incbin "graphics/intro/intro2_volbeat.gbapal"

	.align 2
gIntro2TorchicPal:: @ 8D85EF0
	.incbin "graphics/intro/intro2_torchic.gbapal"

	.align 2
gIntro2ManectricPal:: @ 8D85ED0
	.incbin "graphics/intro/intro2_manectric.gbapal"

	.align 2
gIntro2FlygonPal:: @ 8D85F30
	.incbin "graphics/intro/intro2_flygon.gbapal"

	.align 2
gIntro2VolbeatGfx:: @ 8D85F50
	.incbin "graphics/intro/intro2_volbeat.4bpp.lz"

	.align 2
gIntro2TorchicGfx:: @ 8D86130
	.incbin "graphics/intro/intro2_torchic.4bpp.lz"

	.align 2
gIntro2ManectricGfx:: @ 8D86550
	.incbin "graphics/intro/intro2_manectric.4bpp.lz"

	.align 2
gIntro2FlygonGfx:: @ 8D8702C
	.incbin "graphics/intro/intro2_flygon.4bpp.lz"

	.align 2
gIntro2BrendanNoTurnGfx:: @ 8D87568
	.incbin "graphics/intro/intro2_brendan_noturn.4bpp.lz"

	.align 2
gIntro2MayNoTurnGfx:: @ 8D87CA4
	.incbin "graphics/intro/intro2_may_noturn.4bpp.lz"

	.align 2
gUnknown_08D88494:: @ 8D88494
	.incbin "baserom.gba", 0xd88494, 0x8ac

gUnknown_08D88D40:: @ 8D88D40
	.incbin "baserom.gba", 0xd88d40, 0x4e4

gUnknown_08D89224:: @ 8D89224
	.incbin "baserom.gba", 0xd89224, 0x898

gUnknown_08D89ABC:: @ 8D89ABC
	.incbin "baserom.gba", 0xd89abc, 0x4c0

gUnknown_08D89F7C:: @ 8D89F7C
	.incbin "baserom.gba", 0xd89f7c, 0x89c

gUnknown_08D8A818:: @ 8D8A818
	.incbin "baserom.gba", 0xd8a818, 0x11c

gUnknown_08D8A934:: @ 8D8A934
	.incbin "baserom.gba", 0xd8a934, 0x120

gUnknown_08D8AA54:: @ 8D8AA54
	.incbin "baserom.gba", 0xd8aa54, 0x72c

gUnknown_08D8B180:: @ 8D8B180
	.incbin "baserom.gba", 0xd8b180, 0x2c0

gUnknown_08D8B440:: @ 8D8B440
	.incbin "baserom.gba", 0xd8b440, 0x2a8

gUnknown_08D8B6E8:: @ 8D8B6E8
	.incbin "baserom.gba", 0xd8b6e8, 0x124

	.align 2
gIntro3LightningGfx:: @ 8D8B80C
	.incbin "graphics/intro/intro3_lightning.4bpp.lz"

	.align 2
gIntro3LightningPal:: @ 8D8BA54
	.incbin "graphics/intro/intro3_lightning.gbapal"

	.align 2
gUnknown_08D8BA74:: @ 8D8BA74
	.incbin "baserom.gba", 0xd8ba74, 0x6f8

gUnknown_08D8C16C:: @ 8D8C16C
	.incbin "baserom.gba", 0xd8c16c, 0x6cc

gUnknown_08D8C838:: @ 8D8C838
	.incbin "baserom.gba", 0xd8c838, 0x490

gUnknown_08D8CCC8:: @ 8D8CCC8
	.incbin "baserom.gba", 0xd8ccc8, 0x27c

	.align 2
gIntro2BubblesGfx:: @ 8D8CF44
	.incbin "graphics/intro/intro2_bubbles.4bpp.lz"

	.align 2
gIntro2BubblesPal:: @ 8D8D110
	.incbin "graphics/intro/intro2_bubbles.gbapal"

	.align 2
gIntro1FlygonGfx:: @ 8D8D130
	.incbin "graphics/intro/intro1_flygon.4bpp.lz"

	.align 2
gIntro1SparkleGfx:: @ 8D8D208
	.incbin "graphics/intro/intro1_sparkle.4bpp.lz"

	.align 2
	.incbin "baserom.gba", 0xd8d2a4, 0x16c

gUnknown_08D8D410:: @ 8D8D410
	.incbin "baserom.gba", 0xd8d410, 0x17c

gUnknown_08D8D58C:: @ 8D8D58C
	.incbin "baserom.gba", 0xd8d58c, 0x52c

gUnknown_08D8DAB8:: @ 8D8DAB8
	.incbin "baserom.gba", 0xd8dab8, 0xefc

gUnknown_08D8E9B4:: @ 8D8E9B4
	.incbin "baserom.gba", 0xd8e9b4, 0x80

gUnknown_08D8EA34:: @ 8D8EA34
	.incbin "baserom.gba", 0xd8ea34, 0x1f0

gUnknown_08D8EC24:: @ 8D8EC24
	.incbin "baserom.gba", 0xd8ec24, 0xf78

gUnknown_08D8FB9C:: @ 8D8FB9C
	.incbin "baserom.gba", 0xd8fb9c, 0x24

gUnknown_08D8FBC0:: @ 8D8FBC0
	.incbin "baserom.gba", 0xd8fbc0, 0x30

	.align 2
gBattleInterface_BallStatusBarGfx:: @ 8D8FBF0
	.incbin "graphics/battle_interface/ball_status_bar.4bpp.lz"

	.align 2
gMonIcon_Egg:: @ 8D8FC74
	.incbin "graphics/pokemon/icons/egg_icon.4bpp"

	.incbin "baserom.gba", 0xd90074, 0x1524

sBlenderCenterGfx:: @ 8D91598
	.incbin "baserom.gba", 0xd91598, 0x820

gUnknown_08D91DB8:: @ 8D91DB8
	.incbin "baserom.gba", 0xd91db8, 0xa34

gUnknown_08D927EC:: @ 8D927EC
	.incbin "baserom.gba", 0xd927ec, 0xaf4

gUnknown_08D932E0:: @ 8D932E0
	.incbin "baserom.gba", 0xd932e0, 0x2b8

gUnknown_08D93598:: @ 8D93598
	.incbin "baserom.gba", 0xd93598, 0x1e4

gUnknown_08D9377C:: @ 8D9377C
	.incbin "baserom.gba", 0xd9377c, 0x1e4

gUnknown_08D93960:: @ 8D93960
	.incbin "baserom.gba", 0xd93960, 0x1158

gUnknown_08D94AB8:: @ 8D94AB8
	.incbin "baserom.gba", 0xd94ab8, 0x1320

gUnknown_08D95DD8:: @ 8D95DD8
	.incbin "baserom.gba", 0xd95dd8, 0x28

gUnknown_08D95E00:: @ 8D95E00
	.incbin "baserom.gba", 0xd95e00, 0x2d0

gUnknown_08D960D0:: @ 8D960D0
	.incbin "baserom.gba", 0xd960d0, 0x2d4

gUnknown_08D963A4:: @ 8D963A4
	.incbin "baserom.gba", 0xd963a4, 0x448

gUnknown_08D967EC:: @ 8D967EC
	.incbin "baserom.gba", 0xd967ec, 0x2c8

gUnknown_08D96AB4:: @ 8D96AB4
	.incbin "baserom.gba", 0xd96ab4, 0xec

gUnknown_08D96BA0:: @ 8D96BA0
	 .incbin "baserom.gba", 0xd96ba0, 0x138

gUnknown_08D96CD8:: @ 8D96CD8
	 .incbin "baserom.gba", 0xd96cd8, 0x294

gUnknown_08D96F6C:: @ 8D96F6C
	 .incbin "baserom.gba", 0xd96f6c, 0x24

gUnknown_08D96F90:: @ 8D96F90
	 .incbin "baserom.gba", 0xd96f90, 0x1F8

gUnknown_08D97188:: @ 8D97188
	 .incbin "baserom.gba", 0xd97188, 0x28

gUnknown_08D971B0:: @ 8D971B0
	 .incbin "baserom.gba", 0xd971b0, 0x9D4

gUnknown_08D97B84:: @ 8D97B84
	 .incbin "baserom.gba", 0xd97b84, 0x68

gUnknown_08D97BEC:: @ 8D97BEC
	 .incbin "baserom.gba", 0xd97bec, 0x108

gUnknown_08D97CF4:: @ 8D97CF4
	 .incbin "baserom.gba", 0xd97cf4, 0x18

gUnknown_08D97D0C:: @ 8D97D0C
	.incbin "baserom.gba", 0xd97d0c, 0x830

gUnknown_08D9853C:: @ 8D9853C
	.incbin "baserom.gba", 0xd9853c, 0xf0

gUnknown_08D9862C:: @ 8D9862C
	.incbin "baserom.gba", 0xd9862c, 0x1d0

gUnknown_08D987FC:: @ 8D987FC
	.incbin "baserom.gba", 0xd987fc, 0x190

gUnknown_08D9898C:: @ 8D9898C
	.incbin "baserom.gba", 0xd9898c, 0x19c

gUnknown_08D98B28:: @ 8D98B28
	.incbin "baserom.gba", 0xd98b28, 0x1a0

gUnknown_08D98CC8:: @ 8D98CC8
	.incbin "baserom.gba", 0xd98cc8, 0x18c0

gUnknown_08D9A588:: @ 8D9A588
	.incbin "baserom.gba", 0xd9a588, 0x4c

gUnknown_08D9A5D4:: @ 8D9A5D4
	.incbin "baserom.gba", 0xd9a5d4, 0x4c

gUnknown_08D9A620:: @ 8D9A620
	.incbin "baserom.gba", 0xd9a620, 0x26c

gUnknown_08D9A88C:: @ 8D9A88C
	.incbin "baserom.gba", 0xd9a88c, 0x544

gUnknown_08D9ADD0:: @ 8D9ADD0
	.incbin "baserom.gba", 0xd9add0, 0x34

gUnknown_08D9AE04:: @ 8D9AE04
	.incbin "baserom.gba", 0xd9ae04, 0x140

gUnknown_08D9AF44:: @ 8D9AF44
	.incbin "baserom.gba", 0xd9af44, 0x78

gBuyMenuFrame_Gfx:: @ 8D9AFBC
	.incbin "baserom.gba", 0xd9afbc, 0x10c

gMenuMoneyPal:: @ 8D9B0C8
	.incbin "baserom.gba", 0xd9b0c8, 0x28

gBuyMenuFrame_Tilemap:: @ 8D9B0F0
	.incbin "baserom.gba", 0xd9b0f0, 0x140

gMenuMoneyGfx:: @ 8D9B230
	.incbin "baserom.gba", 0xd9b230, 0x84

gMenuPokeblock_Gfx:: @ 8D9B2B4
	.incbin "baserom.gba", 0xd9b2b4, 0x1bc

gMenuPokeblock_Pal:: @ 8D9B470
	.incbin "baserom.gba", 0xd9b470, 0x70

gMenuPokeblockDevice_Gfx:: @ 8D9B4E0
	.incbin "baserom.gba", 0xd9b4e0, 0x2c0

gMenuPokeblockDevice_Pal:: @ 8D9B7A0
	.incbin "baserom.gba", 0xd9b7a0, 0x28

gMenuPokeblock_Tilemap:: @ 8D9B7C8
	.incbin "baserom.gba", 0xd9b7c8, 0x148

	.align 2
gPokeblock_Gfx::
	.incbin "graphics/pokeblock/pokeblock.4bpp.lz"

	.align 2
gPokeblockRed_Pal::
	.incbin "graphics/pokeblock/red.gbapal.lz"

	.align 2
gPokeblockBlue_Pal::
	.incbin "graphics/pokeblock/blue.gbapal.lz"

	.align 2
gPokeblockPink_Pal::
	.incbin "graphics/pokeblock/pink.gbapal.lz"

	.align 2
gPokeblockGreen_Pal::
	.incbin "graphics/pokeblock/green.gbapal.lz"

	.align 2
gPokeblockYellow_Pal::
	.incbin "graphics/pokeblock/yellow.gbapal.lz"

	.align 2
gPokeblockPurple_Pal::
	.incbin "graphics/pokeblock/purple.gbapal.lz"

	.align 2
gPokeblockIndigo_Pal::
	.incbin "graphics/pokeblock/indigo.gbapal.lz"

	.align 2
gPokeblockBrown_Pal::
	.incbin "graphics/pokeblock/brown.gbapal.lz"

	.align 2
gPokeblockLiteBlue_Pal::
	.incbin "graphics/pokeblock/liteblue.gbapal.lz"

	.align 2
gPokeblockOlive_Pal::
	.incbin "graphics/pokeblock/olive.gbapal.lz"

	.align 2
gPokeblockGray_Pal::
	.incbin "graphics/pokeblock/gray.gbapal.lz"

	.align 2
gPokeblockBlack_Pal::
	.incbin "graphics/pokeblock/black.gbapal.lz"

	.align 2
gPokeblockWhite_Pal::
	.incbin "graphics/pokeblock/white.gbapal.lz"

	.align 2
gPokeblockGold_Pal::
	.incbin "graphics/pokeblock/gold.gbapal.lz"

gUnknown_08D9BA44:: @ 8D9BA44
	.incbin "baserom.gba", 0xd9ba44, 0x100

gUnknown_08D9BB44:: @ 8D9BB44
	.incbin "baserom.gba", 0xd9bb44, 0x3ac

gUnknown_08D9BEF0:: @ 8D9BEF0
	.incbin "baserom.gba", 0xd9bef0, 0xa8

gUnknown_08D9BF98:: @ 8D9BF98
	.incbin "baserom.gba", 0xd9bf98, 0x1a4

gUnknown_08D9C13C:: @ 8D9C13C
	.incbin "baserom.gba", 0xd9c13c, 0x26c

@ 8D9C3A8
	.include "data/graphics/berries/berry_graphics.inc"

gUnknown_08DA1E78:: @ 8DA1E78
	.incbin "baserom.gba", 0xda1e78, 0xBE4

gUnknown_08DA2A5C:: @ 8DA2A5C
	.incbin "baserom.gba", 0xDA2A5C, 0xCC

gUnknown_08DA2B28:: @ 8DA2B28
	.incbin "baserom.gba", 0xDA2B28, 0x1F4

gUnknown_08DA2D1C:: @ 8DA2D1C
	.incbin "baserom.gba", 0xDA2D1C, 0x534

gUnknown_08DA3250:: @ 8DA3250
	.incbin "baserom.gba", 0xDA3250, 0x54

gUnknown_08DA32A4:: @ 8DA32A4
	.incbin "baserom.gba", 0xDA32A4, 0xCC

gUnknown_08DA3370:: @ 8DA3370
	.incbin "baserom.gba", 0xDA3370, 0x28

gUnknown_08DA3398:: @ 8DA3398
	.incbin "baserom.gba", 0xDA3398, 0x28

gUnknown_08DA33C0:: @ 8DA33C0
	.incbin "baserom.gba", 0xda33c0, 0x428

gUnknown_08DA37E8:: @ 8DA37E8
	.incbin "baserom.gba", 0xda37e8, 0x3c

gUnknown_08DA3824:: @ 8DA3824
	.incbin "baserom.gba", 0xda3824, 0x164

gUnknown_08DA3988:: @ 8DA3988
	.incbin "baserom.gba", 0xda3988, 0x100

gUnknown_08DA3A88:: @ 8DA3A88
	.incbin "baserom.gba", 0xda3a88, 0x138

gUnknown_08DA3BC0:: @ 8DA3BC0
	.incbin "baserom.gba", 0xDA3BC0, 0xBC

gUnknown_08DA3C7C:: @ 8DA3C7C
	.incbin "baserom.gba", 0xDA3C7C, 0x18

gUnknown_08DA3C94:: @ 8DA3C94
	.incbin "baserom.gba", 0xda3c94, 0x1114

gUnknown_08DA4DA8:: @ 8DA4DA8
	.incbin "baserom.gba", 0xda4da8, 0x44

gUnknown_08DA4DEC:: @ 8DA4DEC
	.incbin "baserom.gba", 0xda4dec, 0x184

gUnknown_08DA4F70:: @ 8DA4F70
	.incbin "baserom.gba", 0xda4f70, 0x1148

gUnknown_08DA60B8:: @ 8DA60B8
	.incbin "baserom.gba", 0xda60b8, 0x388

gUnknown_08DA6440:: @ 8DA6440
	.incbin "baserom.gba", 0xDA6440, 0x46C

gUnknown_08DA68AC:: @ 8DA68AC
	.incbin "baserom.gba", 0xDA68AC, 0x110

gUnknown_08DA69BC:: @ 8DA69BC
	.incbin "baserom.gba", 0xda69bc, 0xb6c

gUnknown_08DA7528:: @ 8DA7528
	.incbin "baserom.gba", 0xda7528, 0x21c

gUnknown_08DA7744:: @ 8DA7744
	.incbin "baserom.gba", 0xda7744, 0x40

gUnknown_08DA7784:: @ 8DA7784
	.incbin "baserom.gba", 0xda7784, 0x328

gUnknown_08DA7AAC:: @ 8DA7AAC
	.incbin "baserom.gba", 0xda7aac, 0x184

gUnknown_08DA7C30:: @ 8DA7C30
	.incbin "baserom.gba", 0xda7c30, 0x13c

gUnknown_08DA7D6C:: @ 8DA7D6C
	.incbin "baserom.gba", 0xda7d6c, 0x140

gUnknown_08DA7EAC:: @ 8DA7EAC
	.incbin "baserom.gba", 0xda7eac, 0x108

gUnknown_08DA7FB4:: @ 8DA7FB4
	.incbin "baserom.gba", 0xda7fb4, 0x108

gUnknown_08DA80BC:: @ 8DA80BC
	.incbin "baserom.gba", 0xda80bc, 0xa84

gUnknown_08DA8B40:: @ 8DA8B40
	.incbin "baserom.gba", 0xda8b40, 0x22c

gUnknown_08DA8D6C:: @ 8DA8D6C
	.incbin "baserom.gba", 0xda8d6c, 0x118

gUnknown_08DA8E84:: @ 8DA8E84
	.incbin "baserom.gba", 0xda8e84, 0x54

gUnknown_08DA8ED8:: @ 8DA8ED8
	.incbin "baserom.gba", 0xDA8ED8, 0x798

gUnknown_08DA9670:: @ 8DA9670
	.incbin "baserom.gba", 0xDA9670, 0x44

gUnknown_08DA96B4:: @ 8DA96B4
	.incbin "baserom.gba", 0xDA96B4, 0x248

gUnknown_08DA98FC:: @ 8DA98FC
	.incbin "baserom.gba", 0xDA98FC, 0xCA8

gUnknown_08DAA5A4:: @ 8DAA5A4
	.incbin "baserom.gba", 0xDAA5A4, 0x1F0

gUnknown_08DAA794:: @ 8DAA794
	.incbin "baserom.gba", 0xDAA794, 0x98

gUnknown_08DAA82C:: @ 8DAA82C
	.incbin "baserom.gba", 0xDAA82C, 0x28

gUnknown_08DAA854:: @ 8DAA854
	.incbin "baserom.gba", 0xDAA854, 0x28

gUnknown_08DAA87C:: @ 8DAA87C
	.incbin "baserom.gba", 0xDAA87C, 0x28

gUnknown_08DAA8A4:: @ 8DAA8A4
	.incbin "baserom.gba", 0xDAA8A4, 0x10

gUnknown_08DAA8B4:: @ 8DAA8B4
	.incbin "baserom.gba", 0xdaa8b4, 0x270

gUnknown_08DAAB24:: @ 8DAAB24
	.incbin "baserom.gba", 0xdaab24, 0xf8

gUnknown_08DAAC1C:: @ 8DAAC1C
	.incbin "baserom.gba", 0xdaac1c, 0x238

gUnknown_08DAAE54:: @ 8DAAE54
	.incbin "baserom.gba", 0xdaae54, 0x144

gUnknown_08DAAF98:: @ 8DAAF98
	.incbin "baserom.gba", 0xdaaf98, 0x54

gUnknown_08DAAFEC:: @ 8DAAFEC
	.incbin "baserom.gba", 0xdaafec, 0x6c

@ 8DAB058
	.include "data/graphics/items/item_graphics.inc"

@ 8DB7AA0
	.include "data/graphics/decorations/decoration_graphics.inc"

@ 8DBA14C
	.incbin "baserom.gba", 0xdba14c, 0x3cc

gUnknown_08DBA518:: @ 8DBA518
	.incbin "baserom.gba", 0xdba518, 0x80

	.align 2
gCableCar_Pal:: @ 8DBA598
	.incbin "graphics/misc/cable_car.gbapal"

	.align 2
gUnknown_08DBA5B8:: @ 8DBA5B8
	.incbin "baserom.gba", 0xdba5b8, 0x19d8

	.align 2
gCableCar_Gfx:: @ 8DBBF90
	.incbin "graphics/misc/cable_car.4bpp.lz"

	.align 2
gCableCarDoor_Gfx:: @ 8DBC290
	.incbin "graphics/misc/cable_car_door.4bpp.lz"

	.align 2
gCableCarCord_Gfx:: @ 8DBC2C0
	.incbin "graphics/misc/cable_car_cord.4bpp.lz"

	.align 2
gUnknown_08DBC2E8:: @ 8DBC2E8
	.incbin "baserom.gba", 0xdbc2e8, 0x72c

gUnknown_08DBCA14:: @ 0x08DBCA14
	.incbin "baserom.gba", 0xdbca14, 0x1e04

gUnknown_08DBE818:: @ 0x08DBE818
	.incbin "baserom.gba", 0xdbe818, 0x20

gUnknown_08DBE838:: @ 0x08DBE838
	.incbin "baserom.gba", 0xdbe838, 0x20

gUnknown_08DBE858:: @ 0x08DBE858
	.incbin "baserom.gba", 0xdbe858, 0x20

gUnknown_08DBE878:: @ 0x08DBE878
	.incbin "baserom.gba", 0xdbe878, 0x20

gUnknown_08DBE898:: @ 0x08DBE898
	.incbin "baserom.gba", 0xdbe898, 0x20

gUnknown_08DBE8B8:: @ 0x08DBE8B8
	.incbin "baserom.gba", 0xdbe8b8, 0x20

gUnknown_08DBE8D8:: @ 0x08DBE8D8
	.incbin "baserom.gba", 0xdbe8d8, 0x20

gUnknown_08DBE8F8:: @ 0x08DBE8F8
	.incbin "baserom.gba", 0xdbe8f8, 0x20

gUnknown_08DBE918:: @ 0x08DBE918
	.incbin "baserom.gba", 0xdbe918, 0x20

gUnknown_08DBE938:: @ 0x08DBE938
	.incbin "baserom.gba", 0xdbe938, 0x20

gUnknown_08DBE958:: @ 0x08DBE958
	.incbin "baserom.gba", 0xdbe958, 0x20

gUnknown_08DBE978:: @ 0x08DBE978
	.incbin "baserom.gba", 0xdbe978, 0x20

gUnknown_08DBE998:: @ 0x08DBE998
	.incbin "baserom.gba", 0xdbe998, 0x1a0

gUnknown_08DBEB38:: @ 0x08DBEB38
	.incbin "baserom.gba", 0xdbeb38, 0x13c

gUnknown_08DBEC74:: @ 0x08DBEC74
	.incbin "baserom.gba", 0xdbec74, 0x210

gUnknown_08DBEE84:: @ 0x08DBEE84
	.incbin "baserom.gba", 0xdbee84, 0xd8

gUnknown_08DBEF5C:: @ 0x08DBEF5C
	.incbin "baserom.gba", 0xdbef5c, 0x1f8

gUnknown_08DBF154:: @ 0x08DBF154
	.incbin "baserom.gba", 0xdbf154, 0x180

gUnknown_08DBF2D4:: @ 0x08DBF2D4
	.incbin "baserom.gba", 0xdbf2d4, 0xa8

gUnknown_08DBF37C:: @ 0x08DBF37C
	.incbin "baserom.gba", 0xdbf37c, 0x190

gUnknown_08DBF50C:: @ 0x08DBF50C
	.incbin "baserom.gba", 0xdbf50c, 0x140

gUnknown_08DBF64C:: @ 0x08DBF64C
	.incbin "baserom.gba", 0xdbf64c, 0x168

gUnknown_08DBF7B4:: @ 0x08DBF7B4
	.incbin "baserom.gba", 0xdbf7b4, 0x150

gUnknown_08DBF904:: @ 0x08DBF904
	.incbin "baserom.gba", 0xdbf904, 0x2a0

gUnknown_08DBFBA4:: @ 0x08DBFBA4
	.incbin "baserom.gba", 0xdbfba4, 0xd8

gUnknown_08DBFC7C:: @ 0x08DBFC7C
	.incbin "baserom.gba", 0xdbfc7c, 0xe0

gUnknown_08DBFD5C:: @ 0x08DBFD5C
	.incbin "baserom.gba", 0xdbfd5c, 0x10c

gUnknown_08DBFE68:: @ 0x08DBFE68
	.incbin "baserom.gba", 0xdbfe68, 0xdc

gUnknown_08DBFF44:: @ 0x08DBFF44
	.incbin "baserom.gba", 0xdbff44, 0xf0

gUnknown_08DC0034:: @ 0x08DC0034
	.incbin "baserom.gba", 0xdc0034, 0xe0

gUnknown_08DC0114:: @ 0x08DC0114
	.incbin "baserom.gba", 0xdc0114, 0xe0

gUnknown_08DC01F4:: @ 0x08DC01F4
	.incbin "baserom.gba", 0xdc01f4, 0x10c

gUnknown_08DC0300:: @ 0x08DC0300
	.incbin "baserom.gba", 0xdc0300, 0xf0

gUnknown_08DC03F0:: @ 0x08DC03F0
	.incbin "baserom.gba", 0xdc03f0, 0xf8

gUnknown_08DC04E8:: @ 0x08DC04E8
	.incbin "baserom.gba", 0xdc04e8, 0x118

gUnknown_08DC0600:: @ 0x08DC0600
	.incbin "baserom.gba", 0xdc0600, 0x114

gUnknown_08DC0714:: @ 8DC0714
	.incbin "baserom.gba", 0xdc0714, 0x40

gUnknown_08DC0754:: @ 8DC0754
	.incbin "baserom.gba", 0xdc0754, 0x440

gUnknown_08DC0B94:: @ 8DC0B94
	 .incbin "baserom.gba", 0xdc0b94, 0x800

gUnknown_08DC1394:: @ 8DC1394
	 .incbin "baserom.gba", 0xdc1394, 0x2E0

gUnknown_08DC1674:: @ 8DC1674
	 .incbin "baserom.gba", 0xdc1674, 0x20

gUnknown_08DC1694:: @ 8DC1694
	 .incbin "baserom.gba", 0xdc1694, 0x20

gUnknown_08DC16B4:: @ 8DC16B4
	 .incbin "baserom.gba", 0xdc16b4, 0x20

gUnknown_08DC16D4:: @ 8DC16D4
	 .incbin "baserom.gba", 0xdc16d4, 0x20

gUnknown_08DC16F4:: @ 8DC16F4
	 .incbin "baserom.gba", 0xdc16f4, 0x62

gUnknown_08DC1756:: @ 8DC1756
	.incbin "baserom.gba", 0xdc1756, 0x60

gUnknown_08DC17B6:: @ 8DC17B6
	.incbin "baserom.gba", 0xdc17b6, 0xc0

gUnknown_08DC1876:: @ 8DC1876
	.incbin "baserom.gba", 0xdc1876, 0xbe

gUnknown_08DC1934:: @ 8DC1934
	.incbin "baserom.gba", 0xdc1934, 0xA18

gUnknown_08DC234C:: @ 8DC234C
	.incbin "baserom.gba", 0xDC234C, 0x6BC

gUnknown_08DC2A08:: @ 8DC2A08
	.incbin "baserom.gba", 0xdc2a08, 0x114

gUnknown_08DC2B1C:: @ 8DC2B1C
	.incbin "baserom.gba", 0xdc2b1c, 0x140

gUnknown_08DC2C5C:: @ 8DC2C5C
	.incbin "baserom.gba", 0xdc2c5c, 0x150

gUnknown_08DC2DAC:: @ 8DC2DAC
	.incbin "baserom.gba", 0xdc2dac, 0xc0

gUnknown_08DC2E6C:: @ 8DC2E6C
	.incbin "baserom.gba", 0xdc2e6c, 0xf0

gUnknown_08DC2F5C:: @ 8DC2F5C
	.incbin "baserom.gba", 0xdc2f5c, 0x90

gUnknown_08DC2FEC:: @ 8DC2FEC
	.incbin "baserom.gba", 0xdc2fec, 0x94

gUnknown_08DC3080:: @ 8DC3080
	.incbin "baserom.gba", 0xdc3080, 0x118

gUnknown_08DC3198:: @ 8DC3198
	.incbin "baserom.gba", 0xdc3198, 0xee

gUnknown_08DC3286:: @ 8DC3286
	.incbin "baserom.gba", 0xdc3286, 0x7e

gUnknown_08DC3304:: @ 8DC3304
	.incbin "baserom.gba", 0xdc3304, 0x56c

gUnknown_08DC3870:: @ 8DC3870
	.incbin "baserom.gba", 0xdc3870, 0x19c

gUnknown_08DC3A0C:: @ 8DC3A0C
	.incbin "baserom.gba", 0xdc3a0c, 0x2c8

gUnknown_08DC3CD4:: @ 8DC3CD4
	.incbin "baserom.gba", 0xdc3cd4, 0x80

	.align 2
gIntroCopyright_Pal:: @ 8DC3D54
	.incbin "graphics/intro/copyright.gbapal"

	.align 2
gIntroCopyright_Gfx:: @ 8DC3D74
	.incbin "graphics/intro/copyright.4bpp.lz"

	.align 2
gIntroCopyright_Tilemap:: @ 8DC3FD4
	.incbin "graphics/intro/copyright.bin.lz"

	.align 2
gUnknown_08DC4120:: @ 8DC4120
	.incbin "baserom.gba", 0xdc4120, 0x20

gUnknown_08DC4140:: @ 8DC4140
	.incbin "baserom.gba", 0xdc4140, 0x1d8

gUnknown_08DC4318:: @ 8DC4318
	.incbin "baserom.gba", 0xdc4318, 0x20

gUnknown_08DC4338:: @ 8DC4338
	.incbin "baserom.gba", 0xdc4338, 0x20

gUnknown_08DC4358:: @ 8DC4358
	.incbin "baserom.gba", 0xdc4358, 0x20

gUnknown_08DC4378:: @ 8DC4378
	.incbin "baserom.gba", 0xdc4378, 0x2000

gUnknown_08DC6378:: @ 8DC6378
	.incbin "baserom.gba", 0xdc6378, 0x80

gUnknown_08DC63F8:: @ 8DC63F8
	.incbin "baserom.gba", 0xdc63f8, 0x28

gUnknown_08DC6420:: @ 8DC6420
	.incbin "baserom.gba", 0xdc6420, 0x28

gUnknown_08DC6448:: @ 8DC6448
	.incbin "baserom.gba", 0xdc6448, 0x28

gUnknown_08DC6470:: @ 8DC6470
	.incbin "baserom.gba", 0xdc6470, 0x28

gUnknown_08DC6498:: @ 8DC6498
	.incbin "baserom.gba", 0xdc6498, 0x14

gUnknown_08DC64AC:: @ 8DC64AC
	.incbin "baserom.gba", 0xdc64ac, 0x14

gUnknown_08DC64C0:: @ 8DC64C0
	.incbin "baserom.gba", 0xdc64c0, 0x14

gUnknown_08DC64D4:: @ 8DC64D4
	.incbin "baserom.gba", 0xdc64d4, 0x14

gUnknown_08DC64E8:: @ 8DC64E8
	.incbin "baserom.gba", 0xdc64e8, 0x14

gUnknown_08DC64FC:: @ 8DC64FC
	.incbin "baserom.gba", 0xdc64fc, 0x14

gUnknown_08DC6510:: @ 8DC6510
	.incbin "baserom.gba", 0xdc6510, 0x18

gUnknown_08DC6528:: @ 8DC6528
	.incbin "baserom.gba", 0xdc6528, 0x20

gUnknown_08DC6548:: @ 8DC6548
	.incbin "baserom.gba", 0xdc6548, 0x8b4

gUnknown_08DC6DFC:: @ 8DC6DFC
	.incbin "baserom.gba", 0xdc6dfc, 0x274

gUnknown_08DC7070:: @ 8DC7070
	.incbin "baserom.gba", 0xdc7070, 0xaf0

gUnknown_08DC7B60:: @ 8DC7B60
	.incbin "baserom.gba", 0xdc7b60, 0x20

gUnknown_08DC7B80:: @ 8DC7B80
	.incbin "baserom.gba", 0xdc7b80, 0x204

gUnknown_08DC7D84:: @ 8DC7D84
	.incbin "baserom.gba", 0xdc7d84, 0x17c

gUnknown_08DC7F00:: @ 8DC7F00
	 .incbin "baserom.gba", 0xdc7f00, 0xA0

gUnknown_08DC7FA0:: @ 8DC7FA0
	 .incbin "baserom.gba", 0xdc7fa0, 0x13C

gUnknown_08DC80DC:: @ 8DC80DC
	 .incbin "baserom.gba", 0xdc80dc, 0x12C

gUnknown_08DC8208:: @ 8DC8208
	 .incbin "baserom.gba", 0xdc8208, 0x184

gUnknown_08DC838C:: @ 8DC838C
	 .incbin "baserom.gba", 0xdc838c, 0x120

gUnknown_08DC84AC:: @ 8DC84AC
	 .incbin "baserom.gba", 0xdc84ac, 0x1A0

gUnknown_08DC864C:: @ 8DC864C
	 .incbin "baserom.gba", 0xdc864c, 0x1AC

gUnknown_08DC87F8:: @ 8DC87F8
	 .incbin "baserom.gba", 0xdc87f8, 0x2AC

gUnknown_08DC8AA4:: @ 8DC8AA4
	 .incbin "baserom.gba", 0xdc8aa4, 0x170

gUnknown_08DC8C14:: @ 8DC8C14
	 .incbin "baserom.gba", 0xdc8c14, 0x13C

gUnknown_08DC8D50:: @ 8DC8D50
	 .incbin "baserom.gba", 0xdc8d50, 0x114

gUnknown_08DC8E64:: @ 8DC8E64
	 .incbin "baserom.gba", 0xdc8e64, 0x100

gUnknown_08DC8F64:: @ 8DC8F64
	 .incbin "baserom.gba", 0xdc8f64, 0x15C

gUnknown_08DC90C0:: @ 8DC90C0
	.incbin "baserom.gba", 0xdc90c0, 0x20

gUnknown_08DC90E0:: @ 8DC90E0
	.incbin "baserom.gba", 0xdc90e0, 0x50

gUnknown_08DC9130:: @ 8DC9130
	.incbin "baserom.gba", 0xdc9130, 0xb8

gUnknown_08DC91E8:: @ 8DC91E8
	 .incbin "baserom.gba", 0xdc91e8, 0x20

gUnknown_08DC9208:: @ 8DC9208
	 .incbin "baserom.gba", 0xdc9208, 0x400

gUnknown_08DC9608:: @ 8DC9608
	.incbin "baserom.gba", 0xdc9608, 0x20

gUnknown_08DC9628:: @ 8DC9628
	.incbin "baserom.gba", 0xdc9628, 0x320

gBerryBlenderMiscPalette:: @ 8DCAB88
	.incbin "graphics/berry_blender/misc.gbapal"

gBerryBlenderArrowPalette:: @ 8DC9948
	.incbin "graphics/berry_blender/arrow.gbapal"

gUnknown_8DC9988:: @ 8DC9988
	.incbin "baserom.gba", 0xdc9988, 0x200

	.align 2
gBerryBlenderMarubatsuTiles:: @ 8DC9B88
	.incbin "graphics/berry_blender/marubatsu.4bpp"

	.align 2
gBerryBlenderParticlesTiles:: @ 8E90818
	.incbin "graphics/berry_blender/particles.4bpp"

	.space 0x120

	.align 2
gBerryBlenderCountdownNumbersTiles:: @ 8DC9F88
	.incbin "graphics/berry_blender/countdown_numbers.4bpp"

	.align 2
gBerryBlenderStartTiles:: @ 8DCA588
	.incbin "graphics/berry_blender/start.4bpp"

	.space 0x200

   .align 2
gBerryBlenderArrowTiles:: @ 8DCAB88
	.incbin "graphics/berry_blender/arrow.4bpp"

gUnknown_08DCB388:: @ 8DCB388
	.incbin "baserom.gba", 0xdcb388, 0xA28

gUnknown_08DCBDB0:: @ 8DCBDB0
	.incbin "baserom.gba", 0xdcbdb0, 0x20

gUnknown_08DCBDD0:: @ 8DCBDD0
	.incbin "baserom.gba", 0xdcbdd0, 0x140

gUnknown_08DCBF10:: @ 8DCBF10
	.incbin "baserom.gba", 0xdcbf10, 0x10c

gUnknown_08DCC01C:: @ 8DCC01C
	.incbin "baserom.gba", 0xdcc01c, 0x20

gUnknown_08DCC03C:: @ 8DCC03C
	.incbin "baserom.gba", 0xdcc03c, 0x20

gUnknown_08DCC05C:: @ 8DCC05C
	.incbin "baserom.gba", 0xdcc05c, 0x5ec

gUnknown_08DCC648:: @ 8DCC648
	.incbin "baserom.gba", 0xdcc648, 0x2c0

gUnknown_08DCC908:: @ 8DCC908
	 .incbin "baserom.gba", 0xdcc908, 0x290

gUnknown_08DCCB98:: @ 8DCCB98
	 .incbin "baserom.gba", 0xdccb98, 0x20

gUnknown_08DCCBB8:: @ 8DCCBB8
	 .incbin "baserom.gba", 0xdccbb8, 0x184

gUnknown_08DCCD3C:: @ 8DCCD3C
	 .incbin "baserom.gba", 0xdccd3c, 0x20

gUnknown_08DCCD5C:: @ 8DCCD5C
	 .incbin "baserom.gba", 0xdccd5c, 0x200

gUnknown_08DCCF5C:: @ 8DCCF5C
	.incbin "baserom.gba", 0xdccf5c, 0x20

gUnknown_08DCCF7C:: @ 8DCCF7C
	.incbin "baserom.gba", 0xdccf7c, 0x8a0

gUnknown_08DCD81C:: @ 8DCD81C
	.incbin "baserom.gba", 0xdcd81c, 0x214

gUnknown_08DCDA30:: @ 8DCDA30
	.incbin "baserom.gba", 0xdcda30, 0x60

gUnknown_08DCDA90:: @ 8DCDA90
	.incbin "baserom.gba", 0xdcda90, 0xa0

gUnknown_08DCDB30:: @ 8DCDB30
	.incbin "baserom.gba", 0xdcdb30, 0xc40

gUnknown_08DCE770:: @ 8DCE770
	.incbin "baserom.gba", 0xdce770, 0x500

gUnknown_08DCEC70:: @ 8DCEC70
	.incbin "baserom.gba", 0xdcec70, 0x13e0

gUnknown_08DD0050:: @ 8DD0050
	 .incbin "baserom.gba", 0xdd0050, 0x1A08

gUnknown_08DD1A58:: @ 8DD1A58
	 .incbin "baserom.gba", 0xdd1a58, 0x60

gUnknown_08DD1AB8:: @ 8DD1AB8
	 .incbin "baserom.gba", 0xdd1ab8, 0x4C0

gUnknown_08DD1F78:: @ 8DD1F78
	 .incbin "baserom.gba", 0xdd1f78, 0x98

gUnknown_08DD2010:: @ 8DD2010
	 .incbin "baserom.gba", 0xdd2010, 0x1A0

gUnknown_08DD21B0:: @ 8DD21B0
	 .incbin "baserom.gba", 0xdd21b0, 0xDC

gUnknown_08DD228C:: @ 8DD228C
	 .incbin "baserom.gba", 0xdd228c, 0x180

gUnknown_08DD240C:: @ 8DD240C
	 .incbin "baserom.gba", 0xdd240c, 0x60

gUnknown_08DD246C:: @ 8DD246C
	.incbin "baserom.gba", 0xdd246c, 0x674

gUnknown_08DD2AE0:: @ 8DD2AE0
	.incbin "baserom.gba", 0xdd2ae0, 0x98

gUnknown_08DD2B78:: @ 8DD2B78
	.incbin "baserom.gba", 0xdd2b78, 0x1b8

gUnknown_08DD2D30:: @ 8DD2D30
	.incbin "baserom.gba", 0xdd2d30, 0x12c

gUnknown_08DD2E5C:: @ 8DD2E5C
	.incbin "baserom.gba", 0xdd2e5c, 0x18c

gUnknown_08DD2FE8:: @ 8DD2FE8
	.incbin "baserom.gba", 0xdd2fe8, 0x6c0

gUnknown_08DD36A8:: @ 8DD36A8
	.incbin "baserom.gba", 0xdd36a8, 0x20

gUnknown_08DD36C8:: @ 8DD36C8
	.incbin "baserom.gba", 0xdd36c8, 0xb0

gUnknown_08DD3778:: @ 8DD3778
	.incbin "baserom.gba", 0xdd3778, 0xc0

gUnknown_08DD3838:: @ 8DD3838
	.incbin "baserom.gba", 0xdd3838, 0xd0c

gUnknown_08DD4544:: @ 8DD4544
	.incbin "baserom.gba", 0xdd4544, 0xdc

gUnknown_08DD4620:: @ 8DD4620
	.incbin "baserom.gba", 0xdd4620, 0xc0

gUnknown_08DD46E0:: @ 8DD46E0
	.incbin "baserom.gba", 0xdd46e0, 0xc0

gUnknown_08DD47A0:: @ 8DD47A0
	.incbin "baserom.gba", 0xdd47a0, 0xc0

gUnknown_08DD4860:: @ 8DD4860
	.incbin "baserom.gba", 0xdd4860, 0x20

gUnknown_08DD4880:: @ 8DD4880
	.incbin "baserom.gba", 0xdd4880, 0x238

gUnknown_08DD4AB8:: @ 8DD4AB8
	.incbin "baserom.gba", 0xdd4ab8, 0xf8

gUnknown_08DD4BB0:: @ 8DD4BB0
	.incbin "baserom.gba", 0xdd4bb0, 0x20

gUnknown_08DD4BD0:: @ 8DD4BD0
	.incbin "baserom.gba", 0xdd4bd0, 0x20

gUnknown_08DD4BF0:: @ 8DD4BF0
	.incbin "baserom.gba", 0xdd4bf0, 0x5c

gUnknown_08DD4C4C:: @ 8DD4C4C
	.incbin "baserom.gba", 0xdd4c4c, 0xac

	.align 2
gUnknown_08DD4CF8:: @ 8DD4CF8
	.incbin "graphics/interface/unk_change_case.4bpp.lz"

	.align 2
gTilesetPalettes_General:: @ 8DD4E10
	.incbin "data/tilesets/primary/general/palettes/00.gbapal"
	.incbin "data/tilesets/primary/general/palettes/01.gbapal"
	.incbin "data/tilesets/primary/general/palettes/02.gbapal"
	.incbin "data/tilesets/primary/general/palettes/03.gbapal"
	.incbin "data/tilesets/primary/general/palettes/04.gbapal"
	.incbin "data/tilesets/primary/general/palettes/05.gbapal"
	.incbin "data/tilesets/primary/general/palettes/06.gbapal"
	.incbin "data/tilesets/primary/general/palettes/07.gbapal"
	.incbin "data/tilesets/primary/general/palettes/08.gbapal"
	.incbin "data/tilesets/primary/general/palettes/09.gbapal"
	.incbin "data/tilesets/primary/general/palettes/10.gbapal"
	.incbin "data/tilesets/primary/general/palettes/11.gbapal"
	.incbin "data/tilesets/primary/general/palettes/12.gbapal"
	.incbin "data/tilesets/primary/general/palettes/13.gbapal"
	.incbin "data/tilesets/primary/general/palettes/14.gbapal"
	.incbin "data/tilesets/primary/general/palettes/15.gbapal"

	.align 2
gTilesetTiles_General:: @ 8DD5010
	.incbin "data/tilesets/primary/general/tiles.4bpp.lz"

@ 8DD72E0
	.incbin "baserom.gba", 0xdd72e0, 0x20

gUnknown_08DD7300:: @ 8DD7300
	.incbin "baserom.gba", 0xdd7300, 0x60

gUnknown_08DD7360:: @ 8DD7360
	.incbin "baserom.gba", 0xdd7360, 0x1420

gUnknown_08DD8780:: @ 8DD8780
	.incbin "baserom.gba", 0xdd8780, 0x40

gUnknown_08DD87C0:: @ 8DD87C0
	.incbin "baserom.gba", 0xdd87c0, 0x720

gUnknown_08DD8EE0:: @ 8DD8EE0
	.incbin "baserom.gba", 0xdd8ee0, 0x1a0

gUnknown_08DD9080:: @ 8DD9080
	.incbin "baserom.gba", 0xdd9080, 0x60

gUnknown_08DD90E0:: @ 8DD90E0
	.incbin "baserom.gba", 0xdd90e0, 0x638

gUnknown_08DD9718:: @ 8DD9718
	.incbin "baserom.gba", 0xdd9718, 0x15c

gUnknown_08DD9874:: @ 8DD9874
	.incbin "baserom.gba", 0xdd9874, 0x40

gUnknown_08DD98B4:: @ 8DD98B4
	.incbin "baserom.gba", 0xdd98b4, 0x5a4

gUnknown_08DD9E58:: @ 8DD9E58
	.incbin "baserom.gba", 0xdd9e58, 0x194

gUnknown_08DD9FEC:: @ 8DD9FEC
	.incbin "baserom.gba", 0xdd9fec, 0x40

gUnknown_08DDA02C:: @ 8DDA02C
	.incbin "baserom.gba", 0xdda02c, 0x610

gUnknown_08DDA63C:: @ 8DDA63C
	.incbin "baserom.gba", 0xdda63c, 0x1c4

gUnknown_08DDA800:: @ 8DDA800
	.incbin "baserom.gba", 0xdda800, 0x40

gUnknown_08DDA840:: @ 8DDA840
	.incbin "baserom.gba", 0xdda840, 0x600

gUnknown_08DDAE40:: @ 8DDAE40
	.incbin "baserom.gba", 0xddae40, 0x1a0

gUnknown_08DDAFE0:: @ 8DDAFE0
	.incbin "baserom.gba", 0xddafe0, 0x40

gUnknown_08DDB020:: @ 8DDB020
	.incbin "baserom.gba", 0xddb020, 0x2a4

gUnknown_08DDB2C4:: @ 8DDB2C4
	.incbin "baserom.gba", 0xddb2c4, 0x120

gUnknown_08DDB3E4:: @ 8DDB3E4
	.incbin "baserom.gba", 0xddb3e4, 0x80

gUnknown_08DDB464:: @ 8DDB464
	.incbin "baserom.gba", 0xddb464, 0x1aa0

gUnknown_08DDCF04:: @ 8DDCF04
	.incbin "baserom.gba", 0xddcf04, 0x800

gUnknown_08DDD704:: @ 8DDD704
	.incbin "baserom.gba", 0xddd704, 0x24

gUnknown_08DDD728:: @ 8DDD728
	.incbin "baserom.gba", 0xddd728, 0x20

gUnknown_08DDD748:: @ 8DDD748
	.incbin "baserom.gba", 0xddd748, 0x8c8

gUnknown_08DDE010:: @ 8DDE010
	.incbin "baserom.gba", 0xdde010, 0x20

gUnknown_08DDE030:: @ 8DDE030
	.incbin "baserom.gba", 0xdde030, 0xfc

gUnknown_08DDE12C:: @ 8DDE12C
	.incbin "baserom.gba", 0xdde12c, 0xcc

	.align 2
gMonIconPalettes:: @ 8DDE1F8
	.incbin "graphics/pokemon/icon_palettes/icon_palette_0.gbapal"
	.incbin "graphics/pokemon/icon_palettes/icon_palette_1.gbapal"
	.incbin "graphics/pokemon/icon_palettes/icon_palette_2.gbapal"

	.align 2
gTitleScreenBgPalettes:: @ 8DDE258
	.incbin "graphics/title_screen/pokemon_logo.gbapal"
	.incbin "graphics/title_screen/rayquaza_and_clouds.gbapal"

	.align 2
gTitleScreenEmeraldVersionPal:: @ 8DDE438
	.incbin "graphics/title_screen/emerald_version.gbapal"

	.align 2
gUnknown_08DDE458:: @ 8DDE458
	.incbin "baserom.gba", 0xdde458, 0x238

gTitleScreenPokemonLogoGfx:: @ 8DDE690
	.incbin "graphics/title_screen/pokemon_logo.8bpp.lz"

	.align 2
gTitleScreenEmeraldVersionGfx:: @ 8DDFD94
	.incbin "graphics/title_screen/emerald_version.8bpp.lz"

	.align 2
gTitleScreenPressStartPal:: @ 8DE03C8
	.incbin "graphics/title_screen/press_start.gbapal"

	.align 2
gTitleScreenPressStartGfx:: @ 8DE03E8
	.incbin "graphics/title_screen/press_start.4bpp.lz"

	.align 2
gUnknown_08DE0644:: @ 8DE0644
	.incbin "baserom.gba", 0xde0644, 0x184

gUnknown_08DE07C8:: @ 8DE07C8
	.incbin "baserom.gba", 0xde07c8, 0x100

gUnknown_08DE08C8:: @ 8DE08C8
	.incbin "baserom.gba", 0xde08c8, 0x17bc

gUnknown_08DE2084:: @ 8DE2084
	.incbin "baserom.gba", 0xde2084, 0xfdc

gUnknown_08DE3060:: @ 8DE3060
	.incbin "baserom.gba", 0xde3060, 0x2f0

gUnknown_08DE3350:: @ 8DE3350
	.incbin "baserom.gba", 0xde3350, 0x24

gUnknown_08DE3374:: @ 8DE3374
	.incbin "baserom.gba", 0xde3374, 0x24

gUnknown_08DE3398:: @ 8DE3398
	.incbin "baserom.gba", 0xde3398, 0x120

gUnknown_08DE34B8:: @ 8DE34B8
	.incbin "baserom.gba", 0xde34b8, 0xb1c

gUnknown_08DE3FD4:: @ 8DE3FD4
	.incbin "baserom.gba", 0xde3fd4
