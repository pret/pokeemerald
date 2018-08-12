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
gContestMiscGfx:: @ 8C17AB0
	.incbin "graphics/contest/misc.4bpp.lz"

	.align 2
gContestAudienceGfx:: @ 8C1850C
	.incbin "graphics/contest/audience.4bpp.lz"

	.align 2
gUnknown_08C19168::
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
gBattleAnimSpriteSheet_241:: @ 8C2D348
	.incbin "graphics/battle_anims/sprites/241.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_241:: @ 8C2D40C
	.incbin "graphics/battle_anims/sprites/241.gbapal.lz"

	.align 2
gContestConfetti_Gfx:: @ 8C2D428
	.incbin "graphics/misc/confetti.4bpp.lz"

	.align 2
gContestConfetti_Pal:: @ 8C2D548
	.incbin "graphics/misc/confetti.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_242:: @ 8C2D570
	.incbin "graphics/battle_anims/sprites/242.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_242:: @ 8C2D6AC
	.incbin "graphics/battle_anims/sprites/242.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_243:: @ 8C2D6D0
	.incbin "graphics/battle_anims/sprites/243.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_243:: @ 8C2D6F8
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
gTilesetAnims_BattleDomePals0_0:: @ 8D85640
	.incbin "graphics/battle_frontier/dome_anim1.gbapal"

	.align 2
gTilesetAnims_BattleDomePals0_1:: @ 8D85660
	.incbin "graphics/battle_frontier/dome_anim2.gbapal"

	.align 2
gTilesetAnims_BattleDomePals0_2:: @ 8D85680
	.incbin "graphics/battle_frontier/dome_anim3.gbapal"

	.align 2
gTilesetAnims_BattleDomePals0_3:: @ 8D856A0
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

	.align 2
gIntro1GameFreakTextFadePal:: @ 8D85C50
	.incbin "graphics/intro/intro1_text.gbapal" @ game freak text blue fade

	.align 2
gIntro2BrendanNoTurnPal:: @ 8D85CB0
	.incbin "graphics/intro/intro2_brendan_noturn.gbapal"

	.align 2
gIntro3BgPal:: @ 8D85CD0
	.incbin "graphics/intro/intro3.gbapal"

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
gIntro3GroudonGfx:: @ 8D88494
	.incbin "graphics/intro/intro3_groudon.8bpp.lz"

	.align 2
gIntro3GroudonTilemap:: @ 8D88D40
	.incbin "graphics/intro/intro3_groudon.bin.lz"

	.align 2
gIntro3KyogreGfx:: @ 8D89224
	.incbin "graphics/intro/intro3_kyogre.8bpp.lz"

	.align 2
gIntro3KyogreTilemap:: @ 8D89ABC
	.incbin "graphics/intro/intro3_kyogre.bin.lz"

	.align 2
gIntro3LegendBgGfx:: @ 8D89F7C
	.incbin "graphics/intro/legend_bg.4bpp.lz" @ groudon/kyogre/bg

	.align 2
gIntro3GroudonBgTilemap:: @ 8D8A818
	.incbin "graphics/intro/legend_bg1.bin.lz"

	.align 2
gIntro3KyogreBgTilemap:: @ 8D8A934
	.incbin "graphics/intro/legend_bg2.bin.lz"

	.align 2
gIntro3CloudsGfx:: @ 8D8AA54
	.incbin "graphics/intro/intro3_clouds.4bpp.lz"

	.align 2
gIntro3Clouds1Tilemap:: @ 8D8B180
	.incbin "graphics/intro/intro3_clouds1.bin.lz"

	.align 2
gIntro3Clouds2Tilemap:: @ 8D8B440
	.incbin "graphics/intro/intro3_clouds2.bin.lz"

	.align 2
gIntro3Clouds3Tilemap:: @ 8D8B6E8
	.incbin "graphics/intro/intro3_clouds3.bin.lz"

	.align 2
gIntro3LightningGfx:: @ 8D8B80C
	.incbin "graphics/intro/intro3_lightning.4bpp.lz"

	.align 2
gIntro3LightningPal:: @ 8D8BA54
	.incbin "graphics/intro/intro3_lightning.gbapal"

	.align 2
gIntro3RayquazaGfx:: @ 8D8BA74
	.incbin "graphics/intro/intro3_rayquaza.4bpp.lz"

	.align 2
gIntro3RayquazaTilemap:: @ 8D8C16C
	.incbin "graphics/intro/intro3_rayquaza.bin.lz"

	@ seems to be 2 unused tilemaps
	.align 2
	.incbin "graphics/unknown/unknown_D8C374.bin.lz"

	.align 2
	.incbin "graphics/unknown/unknown_D8C5C4.bin.lz"

	.align 2
gIntro3Clouds2Gfx:: @ 8D8C838
	.incbin "graphics/intro/intro3_clouds2.4bpp.lz" @ clouds 2, during the rayquaza flash

	.align 2
gIntro3Clouds4Tilemap:: @ 8D8CCC8
	.incbin "graphics/intro/intro3_clouds4.bin.lz" @ this is the tilemap for clouds 2, but clouds

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
gBattleAnimSpriteSheet_261::
	.incbin "graphics/battle_anims/sprites/261.4bpp.lz"

	.align 2
gUnknown_08D8D410:: @ 8D8D410
	.incbin "graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz"

	.align 2
gUnknown_08D8D58C:: @ 8D8D58C
	.incbin "graphics/battle_anims/backgrounds/sandstorm_brew.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_261:: @ 8E68580
	.incbin "graphics/battle_anims/sprites/261.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_260:: @ 8E685A8
	.incbin "graphics/battle_anims/sprites/260.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_260:: @ 8E68764
	.incbin "graphics/battle_anims/sprites/260.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_15:: @ 8E6877C
	.incbin "graphics/battle_anims/backgrounds/15.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_15:: @ 8E690EC
	.incbin "graphics/battle_anims/backgrounds/15.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_15:: @ 8E69110
	.incbin "graphics/battle_anims/backgrounds/15.bin.lz"

	.align 2
gBattleAnimSpriteSheet_262:: @ 8E69308
	.incbin "graphics/battle_anims/sprites/262.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_262:: @ 8E693DC
	.incbin "graphics/battle_anims/sprites/262.gbapal.lz"

	.align 2
gContestNextTurnGfx::
	.incbin "graphics/contest/nextturn.4bpp.lz"

	.align 2
gUnknown_08D8E9B4:: @ 8D8E9B4
	.incbin "graphics/contest/nextturn_numbers.4bpp"

	.align 2
gUnknown_08D8EA34:: @ 8D8EA34
	.incbin "graphics/contest/nextturn_random.4bpp"

	.align 2
gBattleAnimSpriteSheet_264:: @ 8E695B8
	.incbin "graphics/battle_anims/sprites/264.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_264:: @ 8E695D8
	.incbin "graphics/battle_anims/sprites/264.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_265:: @ 8E695F0
	.incbin "graphics/battle_anims/sprites/265.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_067:: @ 8E69608
	.incbin "graphics/battle_anims/sprites/067.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_068:: @ 8E69628
	.incbin "graphics/battle_anims/sprites/068.gbapal.lz"

	.align 2
gContestApplauseGfx:: @ 8D8EAE4
	.incbin "graphics/contest/applause.4bpp.lz"

	.align 2
gContestApplauseMeterGfx:: @ 8D8EC24
	.incbin "graphics/contest/applause_meter.4bpp"

	.align 2
gContestPal:: @ 8D8ECA4
	.incbin "graphics/contest/nextturn.gbapal"

	.align 2
gBattleAnimSpriteSheet_272:: @ 8E6982C
	.incbin "graphics/battle_anims/sprites/272.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_272:: @ 8E69A48
	.incbin "graphics/battle_anims/sprites/272.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_273:: @ 8E69A6C
	.incbin "graphics/battle_anims/sprites/273.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_269:: @ 8E69A94
	.incbin "graphics/battle_anims/sprites/269.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_269:: @ 8E69AE8
	.incbin "graphics/battle_anims/sprites/269.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_274:: @ 8E69B00
	.incbin "graphics/battle_anims/sprites/274.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_275:: @ 8E69C80
	.incbin "graphics/battle_anims/sprites/275.4bpp.lz"

	.align 2
gBattleAnimSpriteSheet_276:: @ 8E69DEC
	.incbin "graphics/battle_anims/sprites/276.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_274:: @ 8E69F54
	.incbin "graphics/battle_anims/sprites/274.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_17:: @ 8E69F7C
	.incbin "graphics/battle_anims/backgrounds/17.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_17:: @ 8E6A0D8
	.incbin "graphics/battle_anims/backgrounds/17.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_17:: @ 8E6A100
	.incbin "graphics/battle_anims/backgrounds/17.bin.lz"

	.align 2
gBattleAnimSpriteSheet_280:: @ 8E6A2E8
	.incbin "graphics/battle_anims/sprites/280.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_280:: @ 8E6A6E4
	.incbin "graphics/battle_anims/sprites/280.gbapal.lz"

	.align 2
gBattleAnimBackgroundImageMuddyWater_Pal:: @ 8D8FB9C
	.incbin "graphics/battle_anims/backgrounds/water_muddy.gbapal.lz"

	.align 2
gEnemyMonShadow_Gfx:: @ 8D8FBC0
	.incbin "graphics/battle_interface/enemy_mon_shadow.4bpp.lz"

	.align 2
gBattleInterface_BallStatusBarGfx:: @ 8D8FBF0
	.incbin "graphics/battle_interface/ball_status_bar.4bpp.lz"

	.align 2
gMonIcon_Egg:: @ 8D8FC74
	.incbin "graphics/pokemon/icons/egg_icon.4bpp"

	.align 2
gBattleAnimBackgroundImage_02:: @ 8E6ABDC
	.incbin "graphics/battle_anims/backgrounds/02.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_02:: @ 8E6B8A4
	.incbin "graphics/battle_anims/backgrounds/02.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_02:: @ 8E6B8C0
	.incbin "graphics/battle_anims/backgrounds/02.bin.lz"

	.align 2
gBattleAnimSpritePalette_287:: @ 8E6BBB4
	.incbin "graphics/battle_anims/sprites/287.gbapal.lz"

	.align 2
gBattleAnimBackgroundPalette_24:: @ 8E6BBDC
	.incbin "graphics/battle_anims/backgrounds/24.gbapal.lz"

	.align 2
	.incbin "graphics/unknown/unknown_E6BC04.bin.lz" @ TODO: rename

	.align 2
sBlenderCenterGfx:: @ 8D91598
	.incbin "graphics/berry_blender/center.8bpp.lz"

	.align 2
gUnknown_08D91DB8:: @ 8D91DB8
	.incbin "graphics/berry_blender/outer.4bpp.lz"

	.align 2
gUnknown_08D927EC:: @ 8D927EC
	.incbin "graphics/berry_blender/outer_map.bin.lz"

	.align 2
gBattleAnimBackgroundPalette_16:: @ 8E6D668
	.incbin "graphics/battle_anims/backgrounds/16.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_16:: @ 8E6D690
	.incbin "graphics/battle_anims/backgrounds/16.4bpp.lz"

	.align 2
gBattleAnimBackgroundTilemap_16:: @ 8E6D8F0
	.incbin "graphics/battle_anims/backgrounds/16.bin.lz"

	.align 2
gBattleAnimSpritePalette_277:: @ 8E6DA2C
	.incbin "graphics/battle_anims/sprites/277.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_277:: @ 8E6DA54
	.incbin "graphics/battle_anims/sprites/277.4bpp.lz"

	.align 2
gBattleAnimFogTilemap:: @ 8E6DE48
	.incbin "graphics/battle_anims/backgrounds/fog.bin.lz"

	.align 2
gBattleAnimSpritePalette_283:: @ 8E6DFC0
	.incbin "graphics/battle_anims/sprites/283.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_283:: @ 8E6DFDC
	.incbin "graphics/battle_anims/sprites/283.4bpp.lz"

	.align 2
gBattleAnimBackgroundTilemap_ScaryFacePlayer:: @ 8D93598
	.incbin "graphics/battle_anims/backgrounds/scary_face_player.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_ScaryFaceOpponent:: @ 8D9377C
	.incbin "graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz"

	.align 2
gBattleAnimBackgroundTilemap_ScaryFaceContest:: @ 8D93960
	.incbin "graphics/battle_anims/backgrounds/scary_face_contest.bin.lz"

	.align 2
gBattleAnimSpriteSheet_263:: @ 8E6E6AC
	.incbin "graphics/battle_anims/sprites/263.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_263:: @ 8E6E6EC
	.incbin "graphics/battle_anims/sprites/263.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_266:: @ 8E6E704
	.incbin "graphics/battle_anims/sprites/266.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_266:: @ 8E6E744
	.incbin "graphics/battle_anims/sprites/266.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_267:: @ 8E6E75C
	.incbin "graphics/battle_anims/sprites/267.gbapal.lz"

	.align 2
gBattleAnimSpritePalette_268:: @ 8E6E774
	.incbin "graphics/battle_anims/sprites/268.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_278:: @ 8E6E78C
	.incbin "graphics/battle_anims/sprites/278.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_278:: @ 8E6E998
	.incbin "graphics/battle_anims/sprites/278.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_279:: @ 8E6E9B4
	.incbin "graphics/battle_anims/sprites/279.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_279:: @ 8E6EA00
	.incbin "graphics/battle_anims/sprites/279.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_281:: @ 8E6EA1C
	.incbin "graphics/battle_anims/sprites/281.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_281:: @ 8E6EBA4
	.incbin "graphics/battle_anims/sprites/281.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_21:: @ 8E6EBC4
	.incbin "graphics/battle_anims/backgrounds/21.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_21:: @ 8E6EEB8
	.incbin "graphics/battle_anims/backgrounds/21.gbapal.lz"

	.align 2
gBattleAnimBackgroundTilemap_21:: @ 8E6EED4
	.incbin "graphics/battle_anims/backgrounds/21.bin.lz"

	.align 2
gBattleAnimSpriteSheet_284:: @ 8E6F1C0
	.incbin "graphics/battle_anims/sprites/284.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_284:: @ 8E6F53C
	.incbin "graphics/battle_anims/sprites/284.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_285:: @ 8E6F558
	.incbin "graphics/battle_anims/sprites/285.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_285:: @ 8E6F5F8
	.incbin "graphics/battle_anims/sprites/285.gbapal.lz"

	.align 2
gBattleAnimBackgroundImage_Surf:: @ 8D94AB8
	.incbin "graphics/battle_anims/backgrounds/water.4bpp.lz"

	.align 2
gBattleAnimBackgroundPalette_Surf:: @ 8D95DD8
	.incbin "graphics/battle_anims/backgrounds/water.gbapal.lz"

	.align 2
gUnknown_08D95E00:: @ 8D95E00
	.incbin "graphics/unknown/unknown_D95E00.bin.lz"

	.align 2
gUnknown_08D960D0:: @ 8D960D0
	.incbin "graphics/unknown/unknown_D960D0.bin.lz"

	.align 2
gUnknown_08D963A4:: @ 8D963A4
	.incbin "graphics/unknown/unknown_D963A4.bin.lz"

	.align 2
gBattleAnimSpritePalette_286:: @ 8E71200
	.incbin "graphics/battle_anims/sprites/286.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_188:: @ 8E71228
	.incbin "graphics/battle_anims/sprites/188.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_188:: @ 8E7133C
	.incbin "graphics/battle_anims/sprites/188.gbapal.lz"

	.align 2
gPartyMenuMisc_Gfx:: @ 8D967EC
	.incbin "graphics/interface/party_menu_misc.4bpp.lz"

	.align 2
gPartyMenuMisc_Pal:: @ 8D96AB4
	.incbin "graphics/interface/party_menu_misc.gbapal.lz"

	.align 2
gPartyMenuMisc_Tilemap:: @ 8D96BA0
	.incbin "graphics/interface/party_menu_misc.bin.lz"

	.align 2
gPartyMenuPokeball_Gfx:: @ 8D96CD8
	.incbin "graphics/interface/party_menu_pokeball.4bpp.lz"

	.align 2
gPartyMenuPokeballSmall_Gfx:: @ 8D96E58
	.incbin "graphics/interface/party_menu_pokeball_small.4bpp.lz" @ unused

	.align 2
gPartyMenuPokeball_Pal:: @ 8D96F6C
	.incbin "graphics/interface/party_menu_pokeball.gbapal.lz"

	.align 2
gStatusGfx_Icons:: @ 8D96F90
	.incbin "graphics/interface/status_icons.4bpp.lz"

	.align 2
gStatusPal_Icons:: @ 8D97188
	.incbin "graphics/interface/status_icons.gbapal.lz"

	.align 2
gMoveTypes_Gfx:: @ 8D971B0
	.incbin "graphics/types/move_types.4bpp.lz"

	.align 2
gMoveTypes_Pal:: @ 8D97B84
	.incbin "graphics/types/move_types.gbapal.lz"

	.align 2
gUnknown_08D97BEC:: @ 8D97BEC
	.incbin "graphics/interface/summary_frames.4bpp.lz"

	.align 2
gUnknown_08D97CF4:: @ 8D97CF4
	.incbin "graphics/interface/summary_frames.gbapal.lz"

	.align 2
gUnknown_08D97D0C:: @ 8D97D0C
	.incbin "graphics/interface/status_screen.4bpp.lz"

	.align 2
gUnknown_08D9853C:: @ 8D9853C
	.incbin "graphics/interface/status_screen.gbapal.lz"

	.align 2
gUnknown_08D9862C:: @ 8D9862C
	.incbin "graphics/interface/status_screen.bin.lz"

	.align 2
gUnknown_08D987FC:: @ 8D987FC
	.incbin "graphics/interface/status_tilemap1.bin.lz"

	.align 2
gUnknown_08D9898C:: @ 8D9898C
	.incbin "graphics/interface/status_tilemap2.bin.lz"

	.align 2
gUnknown_08D98B28:: @ 8D98B28
	.incbin "graphics/interface/status_tilemap3.bin.lz"

	.align 2
gUnknown_08D98CC8:: @ 8D98CC8
	.incbin "graphics/interface/status_tilemap0.bin.lz"

	.align 2
gBagMaleTiles:: @ 8E75024
	.incbin "graphics/misc/bag_male.4bpp.lz"

	.align 2
gBagFemaleTiles:: @ 8E75BA0
	.incbin "graphics/misc/bag_female.4bpp.lz"

	.align 2
gBagPalette:: @ 8E76700
	.incbin "graphics/misc/bag.gbapal.lz"

	.align 2
gBagScreenMale_Pal:: @ 8D9A588
	.incbin "graphics/interface/bag_screen_male.gbapal.lz"

	.align 2
gBagScreenFemale_Pal:: @ 8D9A5D4
	.incbin "graphics/interface/bag_screen_female.gbapal.lz"

	.align 2
gBagScreen_Gfx:: @ 8D9A620
	.incbin "graphics/interface/bag_screen.4bpp.lz"

	.align 2
gUnknown_08D9A88C:: @ 8D9A88C
	.incbin "graphics/unknown/unknown_D9A88C.bin.lz"

	.align 2
gBattleFrontierGfx_PyramidBag:: @ 8D9A9EC
	.incbin "graphics/interface/bag_pyramid.4bpp.lz"

	.align 2
gUnknown_08D9ADD0:: @ 8D9ADD0
	.incbin "graphics/interface/bag_pyramid.gbapal.lz" @ female palette is first and male is second.

	.align 2
gUnknown_08D9AE04:: @ 8D9AE04
	.incbin "graphics/unknown/unknown_D9AE04.bin.lz" @ tilemap?

	.align 2
gUnknown_08D9AF44:: @ 8D9AF44
	.incbin "graphics/unknown/unknown_D9AF44.gbapal.lz"

	.align 2
gBagSwapLineGfx:: @ 8D9AF6C
	.incbin "graphics/interface/bag_swap.4bpp.lz"

	.align 2
gBagSwapLinePal:: @ 8D9AFAC
	.incbin "graphics/interface/bag_swap.gbapal.lz"

	.align 2
gBuyMenuFrame_Gfx:: @ 8D9AFBC
	.incbin "graphics/interface/mart_frame.4bpp.lz"

	.align 2
gMenuMoneyPal:: @ 8D9B0C8
	.incbin "graphics/interface/mart_frame.gbapal.lz"

	.align 2
gBuyMenuFrame_Tilemap:: @ 8D9B0F0
	.incbin "graphics/interface/mart_frame.bin.lz"

	.align 2
gMenuMoneyGfx:: @ 8D9B230
	.incbin "graphics/interface/money.4bpp.lz"

	.align 2
gMenuPokeblock_Gfx:: @ 8D9B2B4
	.incbin "graphics/interface/pokeblock_case_frame.4bpp.lz"

	.align 2
gMenuPokeblock_Pal:: @ 8D9B470
	.incbin "graphics/interface/pokeblock_case_frame.gbapal.lz"

	.align 2
gMenuPokeblockDevice_Gfx:: @ 8D9B4E0
	.incbin "graphics/interface/pokeblock_device.4bpp.lz"

	.align 2
gMenuPokeblockDevice_Pal:: @ 8D9B7A0
	.incbin "graphics/interface/pokeblock_device.gbapal.lz"

	.align 2
gMenuPokeblock_Tilemap:: @ 8D9B7C8
	.incbin "graphics/interface/pokeblock.bin.lz"

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

	.align 2
gUnknown_08D9BA44:: @ 8D9BA44
	.incbin "graphics/interface/pokeblock_feeding_bg_map.bin.lz"

	.align 2
gUnknown_08D9BB44:: @ 8D9BB44
	.incbin "graphics/interface/check_berry.4bpp.lz"

	.align 2
gUnknown_08D9BEF0:: @ 8D9BEF0
	.incbin "graphics/interface/check_berry.gbapal.lz"

	.align 2
gUnknown_08D9BF98:: @ 8D9BF98
	.incbin "graphics/interface/berry_tag.bin.lz"

	.align 2
gUnknown_08D9C13C:: @ 8D9C13C
	.incbin "graphics/interface/berry_tag_title.bin.lz"

	.align 2
gBerryCheckCircle_Gfx:: @ 8D9C24C
	.incbin "graphics/interface/check_berry_circle.4bpp.lz"

@ 8D9C3A8
	.include "data/graphics/berries/berry_graphics.inc"

	.align 2
gRaySceneGroudon_Gfx:: @ 8DA1E78
	.incbin "graphics/rayquaza_scene/groudon.4bpp.lz"

	.align 2
gRaySceneGroudon2_Gfx:: @ 8DA2A5C
	.incbin "graphics/rayquaza_scene/groudon_shoulder.4bpp.lz"

	.align 2
gRaySceneGroudon3_Gfx:: @ 8DA2B28
	.incbin "graphics/rayquaza_scene/groudon_claw.4bpp.lz"

	.align 2
gRaySceneKyogre_Gfx:: @ 8DA2D1C
	.incbin "graphics/rayquaza_scene/kyogre.4bpp.lz"

	.align 2
gRaySceneKyogre2_Gfx:: @ 8DA3250
	.incbin "graphics/rayquaza_scene/kyogre_shoulder.4bpp.lz"

	.align 2
gRaySceneKyogre3_Gfx:: @ 8DA32A4
	.incbin "graphics/rayquaza_scene/kyogre_fin.4bpp.lz"

	.align 2
gRaySceneGroudon_Pal:: @ 8DA3370
	.incbin "graphics/rayquaza_scene/groudon.gbapal.lz"

	.align 2
gRaySceneKyogre_Pal:: @ 8DA3398
	.incbin "graphics/rayquaza_scene/kyogre.gbapal.lz"

	.align 2
gRaySceneClouds_Gfx:: @ 8DA33C0
	.incbin "graphics/rayquaza_scene/clouds.4bpp.lz"

	.align 2
gRaySceneClouds_Pal:: @ 8DA37E8
	.incbin "graphics/rayquaza_scene/clouds.gbapal.lz" @ pal 1 clouds, pal 2 rain

	.align 2
gRaySceneClouds1_Tilemap:: @ 8DA3824
	.incbin "graphics/rayquaza_scene/clouds1.bin.lz"

	.align 2
gRaySceneClouds2_Tilemap:: @ 8DA3988
	.incbin "graphics/rayquaza_scene/clouds2.bin.lz"

	.align 2
gRaySceneClouds3_Tilemap:: @ 8DA3A88
	.incbin "graphics/rayquaza_scene/clouds3.bin.lz"

	.align 2
gRaySceneSmoke_Gfx:: @ 8DA3BC0
	.incbin "graphics/rayquaza_scene/smoke.4bpp.lz"

	.align 2
gRaySceneSmoke_Pal:: @ 8DA3C7C
	.incbin "graphics/rayquaza_scene/smoke.gbapal.lz"

	.align 2
gRaySceneRayquaza_Gfx:: @ 8DA3C94
	.incbin "graphics/rayquaza_scene/rayquaza.8bpp.lz"

	.align 2
gRaySceneRayquaza_Pal:: @ 8DA4DA8
	.incbin "graphics/rayquaza_scene/rayquaza.gbapal.lz"

	.align 2
gRaySceneRayquaza_Tilemap:: @ 8DA4DEC
	.incbin "graphics/rayquaza_scene/rayquaza.bin.lz"

	.align 2
gRaySceneOvercast_Gfx:: @ 8DA4F70
	.incbin "graphics/rayquaza_scene/overcast.4bpp.lz" @ uses pal 2 of gRaySceneRayquaza_Pal

	.align 2
gRaySceneOvercast_Tilemap:: @ 8DA60B8
	.incbin "graphics/rayquaza_scene/overcast.bin.lz"

	.align 2
gRaySceneRayquazaFly1_Gfx:: @ 8DA6440
	.incbin "graphics/rayquaza_scene/rayquaza_fly1.4bpp.lz"

	.align 2
gRaySceneRayquazaTail_Gfx:: @ 8DA68AC
	.incbin "graphics/rayquaza_scene/rayquaza_tail_fix.4bpp.lz" @ for some reason there are an extra 0xC bytes at the end of the original 4bpp, so in order to produce the correct lz, we have to cat the bytes at the end with a make rule. not sure why those bytes are there, it may have been a bug in Game Freak's software.

	.align 2
gRaySceneOvercast2_Gfx:: @ 8DA69BC
	.incbin "graphics/rayquaza_scene/overcast2.4bpp.lz"

	.align 2
gRaySceneRayquazaLight_Gfx:: @ 8DA7528
	.incbin "graphics/rayquaza_scene/rayquaza_light.4bpp.lz" @ uses pal 2 of gRaySceneOvercast2_Pal

	.align 2
gRaySceneOvercast2_Pal:: @ 8DA7744
	.incbin "graphics/rayquaza_scene/overcast2.gbapal.lz"

	.align 2
gRaySceneOvercast2_Tilemap:: @ 8DA7784
	.incbin "graphics/rayquaza_scene/overcast2.bin.lz"

	.align 2
gRaySceneRayquazaLight_Tilemap:: @ 8DA7AAC
	.incbin "graphics/rayquaza_scene/rayquaza_light.bin.lz"

	.align 2
gRaySceneChaseBg_Gfx:: @ 8DA7C30
	.incbin "graphics/rayquaza_scene/chase_bg.4bpp.lz"

	.align 2
gRaySceneChaseBg_Tilemap:: @ 8DA7D6C
	.incbin "graphics/rayquaza_scene/chase_bg.bin.lz"

	.align 2
gRaySceneChaseStreaks_Gfx:: @ 8DA7EAC
	.incbin "graphics/rayquaza_scene/chase_streaks.4bpp.lz"

	.align 2
gRaySceneChaseStreaks_Tilemap:: @ 8DA7FB4
	.incbin "graphics/rayquaza_scene/chase_streaks.bin.lz"

	.align 2
gRaySceneRayquazaChase_Gfx:: @ 8DA80BC
	.incbin "graphics/rayquaza_scene/rayquaza_chase.4bpp.lz"

	.align 2
gRayChaseRayquazaChase_Tilemap:: @ 8DA8B40
	.incbin "graphics/rayquaza_scene/rayquaza_chase.bin.lz"

	.align 2
gRayChaseRayquazaChase2_Tilemap:: @ 8DA8D6C
	.incbin "graphics/rayquaza_scene/rayquaza_chase2.bin.lz"

	.align 2
gRaySceneChase_Pal:: @ 8DA8E84
	.incbin "graphics/rayquaza_scene/chase.gbapal.lz"

	.align 2
gRaySceneGroudonLeft_Gfx:: @ 8DA8ED8
	.incbin "graphics/rayquaza_scene/groudon_left.4bpp.lz"

	.align 2
gRaySceneGroudonTail_Gfx:: @ 8DA9670
	.incbin "graphics/rayquaza_scene/groudon_tail.4bpp.lz"

	.align 2
gRaySceneKyogreRight_Gfx:: @ 8DA96B4
	.incbin "graphics/rayquaza_scene/kyogre_right.4bpp.lz"

	.align 2
gRaySceneRayquazaHover_Gfx:: @ 8DA98FC
	.incbin "graphics/rayquaza_scene/rayquaza_hover.4bpp.lz"

	.align 2
gRaySceneRayquazaFlyIn_Gfx:: @ 8DAA5A4
	.incbin "graphics/rayquaza_scene/rayquaza_flyin.4bpp.lz"

	.align 2
gRaySceneSplash_Gfx:: @ 8DAA794
	.incbin "graphics/rayquaza_scene/splash.4bpp.lz"

	.align 2
gRaySceneGroudonLeft_Pal:: @ 8DAA82C
	.incbin "graphics/rayquaza_scene/groudon_left.gbapal.lz"

	.align 2
gRaySceneKyogreRight_Pal:: @ 8DAA854
	.incbin "graphics/rayquaza_scene/kyogre_right.gbapal.lz"

	.align 2
gRaySceneRayquazaHover_Pal:: @ 8DAA87C
	.incbin "graphics/rayquaza_scene/rayquaza_hover.gbapal.lz"

	.align 2
gRaySceneSplash_Pal:: @ 8DAA8A4
	.incbin "graphics/rayquaza_scene/splash.gbapal.lz"

	.align 2
gRaySceneHushBg_Gfx:: @ 8DAA8B4
	.incbin "graphics/rayquaza_scene/hush_bg.4bpp.lz"

	.align 2
gRaySceneHushRing_Gfx:: @ 8DAAB24
	.incbin "graphics/rayquaza_scene/hush_ring.8bpp.lz"

	.align 2
gRaySceneHushBg_Tilemap:: @ 8DAAC1C
	.incbin "graphics/rayquaza_scene/hush_bg.bin.lz"

	.align 2
gRaySceneHushRing_Tilemap:: @ 8DAAE54
	.incbin "graphics/rayquaza_scene/hush_ring.bin.lz"

	.align 2
gRaySceneHushRing_Map:: @ 8DAAF98
	.incbin "graphics/rayquaza_scene/hush_ring_map.bin.lz"

	.align 2
gRaySceneHushBg_Pal:: @ 8DAAFEC
	.incbin "graphics/rayquaza_scene/hush_bg.gbapal.lz"

@ 8DAB058
	.include "data/graphics/items/item_graphics.inc"

@ 8DB7AA0
	.include "data/graphics/decorations/decoration_graphics.inc"

	.align 2
gBattleAnimSpritePalette_282:: @ 8E7E7D0
	.incbin "graphics/battle_anims/sprites/282.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_282:: @ 8E7E7F8
	.incbin "graphics/battle_anims/sprites/282.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_270:: @ 8E7E9E0
	.incbin "graphics/battle_anims/sprites/270.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_270:: @ 8E7E9FC
	.incbin "graphics/battle_anims/sprites/270.4bpp.lz"

	.align 2
gBattleAnimSpritePalette_271:: @ 8E7EB24
	.incbin "graphics/battle_anims/sprites/271.gbapal.lz"

	.align 2
gBattleAnimSpriteSheet_271:: @ 8E7EB3C
	.incbin "graphics/battle_anims/sprites/271.4bpp.lz"

	.align 2
gUnknown_08DBA518:: @ 8DBA518
	.incbin "graphics/misc/cable_car_bg.gbapal"

	.align 2
gCableCar_Pal:: @ 8DBA598
	.incbin "graphics/misc/cable_car.gbapal"

	.align 2
gUnknown_08DBA5B8:: @ 8DBA5B8
	.incbin "graphics/misc/cable_car_bg.4bpp.lz"

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
gRouletteMenuTiles:: @ 8DBC2E8
	.incbin "graphics/roulette/window.4bpp.lz"

	.align 2
gRouletteWheelTiles::
	.incbin "graphics/roulette/wheel.8bpp.lz"

	.align 2
gRouletteCenter_Gfx::
	.incbin "graphics/roulette/center.4bpp.lz"

	.align 2
gRouletteHeadersTiles:: @ 8E824BC
	.incbin "graphics/roulette/headers.4bpp.lz"

	.align 2
gRouletteCreditTiles:: @ 8E82AE0
	.incbin "graphics/roulette/credit.4bpp.lz"

	.align 2
gRouletteNumbersTiles:: @ 8E82C30
	.incbin "graphics/roulette/numbers.4bpp.lz"

	.align 2
gRouletteMultiplierTiles:: @ 8E82D14
	.incbin "graphics/roulette/multiplier.4bpp.lz"

	.align 2
gMailPalette_Orange:: @ 0x08DBE818
	.incbin "graphics/mail/orange/palette.gbapal"

	.align 2
gMailPalette_Harbor:: @ 0x08DBE838
	.incbin "graphics/mail/harbor/palette.gbapal"

	.align 2
gMailPalette_Glitter:: @ 0x08DBE858
	.incbin "graphics/mail/glitter/palette.gbapal"

	.align 2
gMailPalette_Mech:: @ 0x08DBE878
	.incbin "graphics/mail/mech/palette.gbapal"

	.align 2
gMailPalette_Wood:: @ 0x08DBE898
	.incbin "graphics/mail/wood/palette.gbapal"

	.align 2
gMailPalette_Wave:: @ 0x08DBE8B8
	.incbin "graphics/mail/wave/palette.gbapal"

	.align 2
gMailPalette_Bead:: @ 0x08DBE8D8
	.incbin "graphics/mail/bead/palette.gbapal"

	.align 2
gMailPalette_Shadow:: @ 0x08DBE8F8
	.incbin "graphics/mail/shadow/palette.gbapal"

	.align 2
gMailPalette_Tropic:: @ 0x08DBE918
	.incbin "graphics/mail/tropic/palette.gbapal"

	.align 2
gMailPalette_Dream:: @ 0x08DBE938
	.incbin "graphics/mail/dream/palette.gbapal"

	.align 2
gMailPalette_Fab:: @ 0x08DBE958
	.incbin "graphics/mail/fab/palette.gbapal"

	.align 2
gMailPalette_Retro:: @ 0x08DBE978
	.incbin "graphics/mail/retro/palette.gbapal"

	.align 2
gMailTiles_Orange:: @ 0x08DBE998
	.incbin "graphics/mail/orange/tiles.4bpp.lz"

	.align 2
gMailTiles_Harbor:: @ 0x08DBEB38
	.incbin "graphics/mail/harbor/tiles.4bpp.lz"

	.align 2
gMailTiles_Glitter:: @ 0x08DBEC74
	.incbin "graphics/mail/glitter/tiles.4bpp.lz"

	.align 2
gMailTiles_Mech:: @ 0x08DBEE84
	.incbin "graphics/mail/mech/tiles.4bpp.lz"

	.align 2
gMailTiles_Wood:: @ 0x08DBEF5C
	.incbin "graphics/mail/wood/tiles.4bpp.lz"

	.align 2
gMailTiles_Wave:: @ 0x08DBF154
	.incbin "graphics/mail/wave/tiles.4bpp.lz"

	.align 2
gMailTiles_Bead:: @ 0x08DBF2D4
	.incbin "graphics/mail/bead/tiles.4bpp.lz"

	.align 2
gMailTiles_Shadow:: @ 0x08DBF37C
	.incbin "graphics/mail/shadow/tiles.4bpp.lz"

	.align 2
gMailTiles_Tropic:: @ 0x08DBF50C
	.incbin "graphics/mail/tropic/tiles.4bpp.lz"

	.align 2
gMailTiles_Dream:: @ 0x08DBF64C
	.incbin "graphics/mail/dream/tiles.4bpp.lz"

	.align 2
gMailTiles_Fab:: @ 0x08DBF7B4
	.incbin "graphics/mail/fab/tiles.4bpp.lz"

	.align 2
gMailTiles_Retro:: @ 0x08DBF904
	.incbin "graphics/mail/retro/tiles.4bpp.lz"

	.align 2
gMailTilemap_Orange:: @ 0x08DBFBA4
	.incbin "graphics/mail/orange/map.bin.lz"

	.align 2
gMailTilemap_Harbor:: @ 0x08DBFC7C
	.incbin "graphics/mail/harbor/map.bin.lz"

	.align 2
gMailTilemap_Glitter:: @ 0x08DBFD5C
	.incbin "graphics/mail/glitter/map.bin.lz"

	.align 2
gMailTilemap_Mech:: @ 0x08DBFE68
	.incbin "graphics/mail/mech/map.bin.lz"

	.align 2
gMailTilemap_Wood:: @ 0x08DBFF44
	.incbin "graphics/mail/wood/map.bin.lz"

	.align 2
gMailTilemap_Wave:: @ 0x08DC0034
	.incbin "graphics/mail/wave/map.bin.lz"

	.align 2
gMailTilemap_Bead:: @ 0x08DC0114
	.incbin "graphics/mail/bead/map.bin.lz"

	.align 2
gMailTilemap_Shadow:: @ 0x08DC01F4
	.incbin "graphics/mail/shadow/map.bin.lz"

	.align 2
gMailTilemap_Tropic:: @ 0x08DC0300
	.incbin "graphics/mail/tropic/map.bin.lz"

	.align 2
gMailTilemap_Dream:: @ 0x08DC03F0
	.incbin "graphics/mail/dream/map.bin.lz"

	.align 2
gMailTilemap_Fab:: @ 0x08DC04E8
	.incbin "graphics/mail/fab/map.bin.lz"

	.align 2
gMailTilemap_Retro:: @ 0x08DC0600
	.incbin "graphics/mail/retro/map.bin.lz"

	.align 2
gFrontierFactorySelectMenu_Pal:: @ 8DC0714
	.incbin "graphics/battle_frontier/factory_menu1.gbapal"
	.incbin "graphics/battle_frontier/factory_menu2.gbapal"

	.align 2
gFrontierFactorySelectMenu_Gfx:: @ 8DC0754
	.incbin "graphics/battle_frontier/factory_menu1.4bpp"
	.incbin "graphics/battle_frontier/factory_menu2.4bpp"

	.align 2
gFrontierFactorySelectMenu_Tilemap:: @ 8DC0B94
	.incbin "graphics/battle_frontier/factory_menu.bin"

	.align 2
gFrontierPassMedals_Gfx:: @ 8DC1394
	.incbin "graphics/frontier_pass/medals.4bpp.lz" @ battle frontier medals

	.align 2
gFrontierPassCursor_Pal:: @ 8DC1674
	.incbin "graphics/frontier_pass/cursor.gbapal" @ frontier pass cursor pal

	.align 2
gFrontierPassMapCursor_Pal:: @ 8DC1694
	.incbin "graphics/frontier_pass/map_cursor.gbapal" @ frontier pass map cursor pal

	.align 2
gFrontierPassMedalsSilver_Pal:: @ 8DC16B4
	.incbin "graphics/frontier_pass/silver.gbapal"

	.align 2
gFrontierPassMedalsGold_Pal:: @ 8DC16D4
	.incbin "graphics/frontier_pass/gold.gbapal"

	.align 2
gPokedexText_Pal:: @ 8DC16F4
	.incbin "graphics/pokedex/text.gbapal"

	.align 2
gPokedexCaughtScreenFade_Pal:: @ 8DC1756
	.incbin "graphics/pokedex/fade.gbapal"

	.align 2
gPokedexHoennBg_Pal:: @ 8DC17B6
	.incbin "graphics/pokedex/hoenn_bg.gbapal"

	.align 2
gPokedexNationalBg_Pal:: @ 8DC1876
	.incbin "graphics/pokedex/national_bg.gbapal"

	.align 2
gPokedexMenu_Gfx:: @ 8DC1934
	.incbin "graphics/pokedex/menu.4bpp.lz"

	.align 2
gPokedexMenu2_Gfx:: @ 8DC234C
	.incbin "graphics/pokedex/menu2.4bpp.lz"

	.align 2
	.incbin "graphics/pokedex/noball_unused.4bpp.lz" @ unused

	@ these are a series of 9 tilemaps used for something pokedex related.

	.align 2
gUnknown_08DC2A08:: @ 8DC2A08
	.incbin "graphics/pokedex/tilemap1.bin.lz"

	.align 2
gUnknown_08DC2B1C:: @ 8DC2B1C
	.incbin "graphics/pokedex/tilemap2.bin.lz"

	.align 2
gUnknown_08DC2C5C:: @ 8DC2C5C
	.incbin "graphics/pokedex/tilemap3.bin.lz"

	.align 2
gUnknown_08DC2DAC:: @ 8DC2DAC
	.incbin "graphics/pokedex/tilemap4.bin.lz"

	.align 2
gUnknown_08DC2E6C:: @ 8DC2E6C
	.incbin "graphics/pokedex/tilemap5.bin.lz"

	.align 2
gUnknown_08DC2F5C:: @ 8DC2F5C
	.incbin "graphics/pokedex/tilemap6.bin.lz"

	.align 2
gUnknown_08DC2FEC:: @ 8DC2FEC
	.incbin "graphics/pokedex/tilemap7.bin.lz"

	.align 2
gUnknown_08DC3080:: @ 8DC3080
	.incbin "graphics/pokedex/tilemap8.bin.lz"

	.align 2
gUnknown_08DC3198:: @ 8DC3198
	.incbin "graphics/pokedex/tilemap9.bin.lz" @ all tilemaps

	.align 2
gPokedexSearchMenu_Pal:: @ 8DC3284
	.incbin "graphics/pokedex/search_menu.gbapal"

	.align 2
gPokedexSearchMenu_Gfx:: @ 8DC3304
	.incbin "graphics/pokedex/search_menu.4bpp.lz"

	.align 2
gPokedexSearch1_Tilemap:: @ 8DC3870
	.incbin "graphics/pokedex/search1.bin.lz"

	.align 2
gPokedexSearch2_Tilemap:: @ 8DC3A0C
	.incbin "graphics/pokedex/search2.bin.lz"

	.align 2
gSummaryScreenPowAcc_Tilemap:: @ 8DC3B94
	.incbin "graphics/interface/powacc_tilemap.bin" @ pow/acc tilemap

	.align 2
gUnknown_08DC3C34:: @ 8DC3C34
	.incbin "graphics/interface/unk_tilemap.bin" @ probably trade summary screen related? cant check

	.align 2
gSummaryScreenWindow_Tilemap:: @ 8DC3CD4
	.incbin "graphics/interface/summary.bin"

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
gPokedexAreaScreenAreaUnknown_Pal:: @ 8DC4120
	.incbin "graphics/pokedex/area_unknown.gbapal"

	.align 2
gPokedexAreaScreenAreaUnknown_Gfx:: @ 8DC4140
	.incbin "graphics/pokedex/area_unknown.4bpp.lz"

	@ seems to be fire red leftovers, but the menu elements is reused in the item menu for TM descriptions.

	.align 2
gFireRedMenuElements1_Pal:: @ 8DC4318
	.incbin "graphics/interface_fr/menu1.gbapal"

	.align 2
gFireRedMenuElements2_Pal:: @ 8DC4338
	.incbin "graphics/interface_fr/menu2.gbapal"

	.align 2
gFireRedMenuElements3_Pal:: @ 8DC4358
	.incbin "graphics/interface_fr/menu3.gbapal"

	.align 2
gFireRedMenuElements_Gfx:: @ 8DC4378
	.incbin "graphics/interface_fr/menu.4bpp" @ the types are reused for item menu

	.align 2
gBagMenuHMIcon_Gfx:: @ 8DC6378
	.incbin "graphics/interface/hm.4bpp"

	@ contest link stuff, appears to be a set of tilemaps

	.align 2
gUnknown_08DC63F8:: @ 8DC63F8
	.incbin "graphics/contest/clink_tilemap1.bin"

	.align 2
gUnknown_08DC6420:: @ 8DC6420
	.incbin "graphics/contest/clink_tilemap2.bin"

	.align 2
gUnknown_08DC6448:: @ 8DC6448
	.incbin "graphics/contest/clink_tilemap3.bin"

	.align 2
gUnknown_08DC6470:: @ 8DC6470
	.incbin "graphics/contest/clink_tilemap4.bin"

	.align 2
gUnknown_08DC6498:: @ 8DC6498
	.incbin "graphics/contest/clink_tilemap5.bin"

	.align 2
gUnknown_08DC64AC:: @ 8DC64AC
	.incbin "graphics/contest/clink_tilemap6.bin"

	.align 2
gUnknown_08DC64C0:: @ 8DC64C0
	.incbin "graphics/contest/clink_tilemap7.bin"

	.align 2
gUnknown_08DC64D4:: @ 8DC64D4
	.incbin "graphics/contest/clink_tilemap8.bin"

	.align 2
gUnknown_08DC64E8:: @ 8DC64E8
	.incbin "graphics/contest/clink_tilemap9.bin"

	.align 2
gUnknown_08DC64FC:: @ 8DC64FC
	.incbin "graphics/contest/clink_tilemap10.bin"

	.align 2
gUnknown_08DC6510:: @ 8DC6510
	.incbin "graphics/contest/clink_tilemap11.bin"

	@ pokenav

	.align 2
gPokenavCondition_Pal:: @ 8DC6528
	.incbin "graphics/pokenav/condition.gbapal"

	.align 2
gPokenavCondition_Gfx:: @ 8DC6548
	.incbin "graphics/pokenav/condition.4bpp.lz"

	.align 2
gPokenavCondition_Tilemap:: @ 8DC6DFC
	.incbin "graphics/pokenav/condition.bin.lz"

	.align 2
gPokenavOptions_Tilemap:: @ 8DC7070
	.incbin "graphics/pokenav/options/options.bin"

	.align 2
gPokenavOptions_Gfx::
	.incbin "graphics/pokenav/options/options.4bpp.lz"

	.align 2
gPokenavOptions_Pal::
	.incbin "graphics/pokenav/options/options.gbapal"

	.align 2
gPokenavHeader_Pal:: @ 8DC7B60
	.incbin "graphics/pokenav/header.gbapal"

	.align 2
gPokenavHeader_Gfx:: @ 8DC7B80
	.incbin "graphics/pokenav/header.4bpp.lz" @ TODO: use width 9 and makefile rule for cleanliness, make wasnt behaving, didnt want to apply num_tiles to this

	.align 2
gPokenavHeader_Tilemap:: @ 8DC7D84
	.incbin "graphics/pokenav/header.bin.lz"

	.align 2
gPokenavLeftHeader_Pal:: @ 8DC7F00
	.incbin "graphics/pokenav/left_headers/palette.gbapal"

	.align 2
gPokenavLeftHeaderBeauty_Gfx:: @ 8DC7FA0
	.incbin "graphics/pokenav/left_headers/beauty.4bpp.lz"

	.align 2
gPokenavLeftHeaderSmart_Gfx:: @ 8DC80DC
	.incbin "graphics/pokenav/left_headers/smart.4bpp.lz"

	.align 2
gPokenavLeftHeaderCondition_Gfx:: @ 8DC8208
	.incbin "graphics/pokenav/left_headers/condition.4bpp.lz"

	.align 2
gPokenavLeftHeaderCute_Gfx:: @ 8DC838C
	.incbin "graphics/pokenav/left_headers/cute.4bpp.lz"

	.align 2
gPokenavLeftHeaderMatchCall_Gfx:: @ 8DC84AC
	.incbin "graphics/pokenav/left_headers/match_call.4bpp.lz"

	.align 2
gPokenavLeftHeaderMainMenu_Gfx:: @ 8DC864C
	.incbin "graphics/pokenav/left_headers/main_menu.4bpp.lz"

	.align 2
gPokenavLeftHeaderHoennMap_Gfx:: @ 8DC87F8
	.incbin "graphics/pokenav/left_headers/hoenn_map.4bpp.lz"

	.align 2
gPokenavLeftHeaderRibbons_Gfx:: @ 8DC8AA4
	.incbin "graphics/pokenav/left_headers/ribbons.4bpp.lz"

	.align 2
gPokenavLeftHeaderSearch_Gfx:: @ 8DC8C14
	.incbin "graphics/pokenav/left_headers/search.4bpp.lz"

	.align 2
gPokenavLeftHeaderTough_Gfx:: @ 8DC8D50
	.incbin "graphics/pokenav/left_headers/tough.4bpp.lz"

	.align 2
gPokenavLeftHeaderCool_Gfx:: @ 8DC8E64
	.incbin "graphics/pokenav/left_headers/cool.4bpp.lz"

	.align 2
gPokenavLeftHeaderParty_Gfx:: @ 8DC8F64
	.incbin "graphics/pokenav/left_headers/party.4bpp.lz"

	.align 2
gPokenavMessageBox_Pal:: @ 8DC90C0
	.incbin "graphics/pokenav/message.gbapal"

	.align 2
gPokenavMessageBox_Gfx:: @ 8DC90E0
	.incbin "graphics/pokenav/message.4bpp.lz"

	.align 2
gPokenavMessageBox_Tilemap:: @ 8DC9130
	.incbin "graphics/pokenav/message.bin.lz"

	.align 2
gHoennMapZoomIcons_Pal:: @ 8DC91E8
	.incbin "graphics/pokenav/zoom.gbapal"

	.align 2
gHoennMapZoomIcons_Gfx:: @ 8DC9208
	.incbin "graphics/pokenav/zoom.4bpp.lz"

	.align 2
gPokenavConditionCancel_Pal::
	.incbin "graphics/pokenav/cancel.gbapal"

	.align 2
gPokenavConditionCancel_Gfx::
	.incbin "graphics/pokenav/cancel.4bpp"

	.align 2
gPokenavConditionMarker_Pal:: @ 8DC9608
	.incbin "graphics/pokenav/marker.gbapal"

	.align 2
gPokenavConditionMarker_Gfx:: @ 8DC9628
	.incbin "graphics/pokenav/marker.4bpp"

	.align 2
gBerryBlenderMiscPalette:: @ 8DCAB88
	.incbin "graphics/berry_blender/misc.gbapal"

	.align 2
gBerryBlenderArrowPalette:: @ 8DC9948
	.incbin "graphics/berry_blender/arrow.gbapal"

	.align 2
gBerryBlenderBetaArrow_Gfx:: @ 8DC9988
	.incbin "graphics/berry_blender/arrow_old.4bpp" @ unused

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

	.space 0x2C0

	.align 2
gEasyChatCursor_Pal:: @ 8DCB648
	.incbin "graphics/easy_chat/cursor.gbapal"

	.align 2
gEasyChatCursor_Gfx:: @ 8DCB668
	.incbin "graphics/easy_chat/cursor.4bpp.lz"

	.align 2
gEasyChatRightWindow_Pal:: @ 8DCB86C
	.incbin "graphics/easy_chat/rwindow.gbapal"

	.align 2
gEasyChatRightWindow_Gfx:: @ 8DCB88C
	.incbin "graphics/easy_chat/rwindow.4bpp.lz"

	.align 2
gEasyChatMode_Gfx:: @ 8DCBAB0
	.incbin "graphics/easy_chat/mode.4bpp.lz"

	.align 2
gEasyChatMode_Pal:: @ 8DCBDB0
	.incbin "graphics/easy_chat/mode.gbapal"

	.align 2
gEasyChatWindow_Gfx:: @ 8DCBDD0
	.incbin "graphics/easy_chat/window.4bpp.lz" @ uses mode pal

	.align 2
gEasyChatWindow_Tilemap:: @ 8DCBF10
	.incbin "graphics/easy_chat/window.bin.lz"

	.align 2
gWallclockMale_Pal:: @ 8DCC01C
	.incbin "graphics/interface/wallclock_male.gbapal"

	.align 2
gWallclockFemale_Pal:: @ 8DCC03C
	.incbin "graphics/interface/wallclock_female.gbapal"

	.align 2
gWallclock_Gfx:: @ 8DCC05C
	.incbin "graphics/interface/wallclock.4bpp.lz"

	.align 2
gUnknown_08DCC648:: @ 8DCC648
	.incbin "graphics/interface/wallclock1.bin.lz"

	.align 2
gUnknown_08DCC908:: @ 8DCC908
	.incbin "graphics/interface/wallclock2.bin.lz"

	.align 2
gUsePokeblockCondition_Pal:: @ 8DCCB98
	.incbin "graphics/pokeblock/use_screen/condition.gbapal"

	.align 2
gUsePokeblockCondition_Gfx:: @ 8DCCBB8
	.incbin "graphics/pokeblock/use_screen/condition.4bpp.lz"

	.align 2
gUsePokeblockUpDown_Pal:: @ 8DCCD3C
	.incbin "graphics/pokeblock/use_screen/updown.gbapal"

	.align 2
gUsePokeblockUpDown_Gfx:: @ 8DCCD5C
	.incbin "graphics/pokeblock/use_screen/updown.4bpp"

	.align 2
gUsePokeblockGraph_Pal:: @ 8DCCF5C
	.incbin "graphics/pokeblock/use_screen/graph.gbapal"

	.align 2
gUsePokeblockGraph_Gfx:: @ 8DCCF7C
	.incbin "graphics/pokeblock/use_screen/graph.4bpp.lz"

	.align 2
gUsePokeblockGraph_Tilemap:: @ 8DCD81C
	.incbin "graphics/pokeblock/use_screen/graph.bin.lz"

	.align 2
gUsePokeblockNatureWin_Pal:: @ 8DCDA30
	.incbin "graphics/pokeblock/use_screen/nature.gbapal"

	@ slot machine

	.align 2
gSlotMachineMenu_Pal:: @ 8DCDA90
	.incbin "graphics/slot_machine/menu.gbapal"

	.align 2
gSlotMachineMenu_Gfx:: @ 8DCDB30
	.incbin "graphics/slot_machine/menu.4bpp.lz"

	.align 2
gSlotMachineMenu_Tilemap:: @ 8DCE770
	.incbin "graphics/slot_machine/menu.bin"

	.align 2
gUnknown_08DCEC70:: @ 8DCEC70
	.incbin "graphics/slot_machine/slots_layout.bin"

	.align 2
gUnknown_08DCF170::
	.incbin "graphics/slot_machine/reel_symbols/1.gbapal"

	.align 2
gUnknown_08DCF190::
	.incbin "graphics/slot_machine/reel_pikachu.gbapal"

	.align 2
gUnknown_08DCF1B0::
	.incbin "graphics/slot_machine/shadow.gbapal"

	.align 2
gSlotMachineReelTime_Pal::
	.incbin "graphics/slot_machine/reel_time.gbapal"

	.align 2
gUnknown_08DCF1F0::
	.incbin "graphics/slot_machine/smoke.gbapal" @ also duck and pika aura

	.align 2
gUnknown_08DCF210::
	.incbin "graphics/slot_machine/reel_time_explosion/0.gbapal"

	.align 2
gUnknown_08DCF230::
	.incbin "graphics/slot_machine/spr6.gbapal" @ huh?

	.align 2
gSlotMachineReelSymbol1Tiles:: @ 8DCF250
	.incbin "graphics/slot_machine/reel_symbols/1.4bpp"

	.align 2
gSlotMachineReelSymbol2Tiles::
	.incbin "graphics/slot_machine/reel_symbols/2.4bpp"

	.align 2
gSlotMachineReelSymbol3Tiles::
	.incbin "graphics/slot_machine/reel_symbols/3.4bpp"

	.align 2
gSlotMachineReelSymbol4Tiles::
	.incbin "graphics/slot_machine/reel_symbols/4.4bpp"

	.align 2
gSlotMachineReelSymbol5Tiles::
	.incbin "graphics/slot_machine/reel_symbols/5.4bpp"

	.align 2
gSlotMachineReelSymbol6Tiles::
	.incbin "graphics/slot_machine/reel_symbols/6.4bpp"

	.align 2
gSlotMachineReelSymbol7Tiles::
	.incbin "graphics/slot_machine/reel_symbols/7.4bpp"

	.align 2
gSlotMachineReelTime_Gfx:: @ 8DD0050
	.incbin "graphics/slot_machine/reel_time.4bpp.lz"

	.align 2
gSlotMachineNumber0Tiles::
	.incbin "graphics/slot_machine/numbers/0.4bpp"

	.align 2
gSlotMachineNumber1Tiles::
	.incbin "graphics/slot_machine/numbers/1.4bpp"

	.align 2
gSlotMachineNumber2Tiles::
	.incbin "graphics/slot_machine/numbers/2.4bpp"

	.align 2
gSlotMachineNumber3Tiles::
	.incbin "graphics/slot_machine/numbers/3.4bpp"

	.align 2
gSlotMachineNumber4Tiles::
	.incbin "graphics/slot_machine/numbers/4.4bpp"

	.align 2
gSlotMachineNumber5Tiles::
	.incbin "graphics/slot_machine/numbers/5.4bpp"

	.align 2
gSlotMachineNumber6Tiles::
	.incbin "graphics/slot_machine/numbers/6.4bpp"

	.align 2
gSlotMachineNumber7Tiles::
	.incbin "graphics/slot_machine/numbers/7.4bpp"

	.align 2
gSlotMachineNumber8Tiles::
	.incbin "graphics/slot_machine/numbers/8.4bpp"

	.align 2
gSlotMachineNumber9Tiles::
	.incbin "graphics/slot_machine/numbers/9.4bpp"

	.align 2
gSlotMachineReelTimeBolt::
	.incbin "graphics/slot_machine/bolt.4bpp"

	.align 2
gSlotMachineReelTimeDuck::
	.incbin "graphics/slot_machine/duck.4bpp"

	.align 2
gSlotMachineReelTimeSmoke::
	.incbin "graphics/slot_machine/smoke.4bpp"

	.align 2
gSlotMachineReelTimeNumber0::
	.incbin "graphics/slot_machine/reel_time_numbers/0.4bpp"

	.align 2
gSlotMachineReelTimeNumber1::
	.incbin "graphics/slot_machine/reel_time_numbers/1.4bpp"

	.align 2
gSlotMachineReelTimeNumber2::
	.incbin "graphics/slot_machine/reel_time_numbers/2.4bpp"

	.align 2
gSlotMachineReelTimeNumber3::
	.incbin "graphics/slot_machine/reel_time_numbers/3.4bpp"

	.align 2
gSlotMachineReelTimeNumber4::
	.incbin "graphics/slot_machine/reel_time_numbers/4.4bpp"

	.align 2
gSlotMachineReelTimeNumber5::
	.incbin "graphics/slot_machine/reel_time_numbers/5.4bpp"

	.align 2
gSlotMachineReelTimeLargeBolt0::
	.incbin "graphics/slot_machine/large_bolt/0.4bpp"

	.align 2
gSlotMachineReelTimeLargeBolt1::
	.incbin "graphics/slot_machine/large_bolt/1.4bpp"

	.align 2
gSlotMachineReelTimeExplosion0::
	.incbin "graphics/slot_machine/reel_time_explosion/0.4bpp"

	.align 2
gSlotMachineReelTimeExplosion1::
	.incbin "graphics/slot_machine/reel_time_explosion/1.4bpp"

	.align 2
gSlotMachineReelTimeShadow::
	.incbin "graphics/slot_machine/shadow.4bpp"

	.align 2
gSlotMachineReelTimePikaAura::
	.incbin "graphics/slot_machine/pika_aura.4bpp"

	.align 2
gUnknown_08DD19F8::
	.incbin "graphics/unknown/unknown_DD19F8.bin" @ might be a palette?

	.align 2
gUnknown_08DD1A18::
	.incbin "graphics/unknown/unknown_DD1A18.4bpp"

	@ trainer card

	.align 2
gEmeraldTrainerCard0Star_Pal:: @ 8DD1A58
	.incbin "graphics/trainer_card/0star.gbapal"

	.align 2
gEmeraldTrainerCard_Gfx:: @ 8DD1AB8
	.incbin "graphics/trainer_card/card.4bpp.lz"

	@ what are these? lz compressed files used for something, cant tell if tilemaps

	.align 2
gUnknown_08DD1F78:: @ 8DD1F78
	.incbin "graphics/unknown/unknown_DD1F78.bin.lz"

	.align 2
gUnknown_08DD2010:: @ 8DD2010
	.incbin "graphics/unknown/unknown_DD2010.bin.lz"

	.align 2
gUnknown_08DD21B0:: @ 8DD21B0
	.incbin "graphics/unknown/unknown_DD21B0.bin.lz"

	.align 2
gUnknown_08DD228C:: @ 8DD228C
	.incbin "graphics/unknown/unknown_DD228C.bin.lz"

	.align 2
gFireRedTrainerCard0Star_Pal:: @ 8DD240C
	.incbin "graphics/trainer_card/0star_fr.gbapal"

	.align 2
gFireRedTrainerCard_Gfx:: @ 8DD246C
	.incbin "graphics/trainer_card/card_fr.4bpp.lz"

	@ more of these weird compressed files, probably for the FR trainer card

	.align 2
gUnknown_08DD2AE0:: @ 8DD2AE0
	.incbin "graphics/unknown/unknown_DD2AE0.bin.lz"

	.align 2
gUnknown_08DD2B78:: @ 8DD2B78
	.incbin "graphics/unknown/unknown_DD2B78.bin.lz"

	.align 2
gUnknown_08DD2D30:: @ 8DD2D30
	.incbin "graphics/unknown/unknown_DD2D30.bin.lz"

	.align 2
gUnknown_08DD2E5C:: @ 8DD2E5C
	.incbin "graphics/unknown/unknown_DD2E5C.bin.lz"

	@ pokemon storage system

	.align 2
gPSSMenu_Gfx:: @ 8DD2FE8
	.incbin "graphics/pokemon_storage/menu.4bpp.lz"

	.align 2
gPSSMenu_Pal:: @ 8DD36A8
	.incbin "graphics/pokemon_storage/menu.gbapal" @ pal for the options in the gfx

	.align 2
gUnknown_08DD36C8:: @ 8DD36C8
	.incbin "graphics/unknown/unknown_DD36C8.bin.lz"

	@ naming screen

	.align 2
gNamingScreenMenu_Pal:: @ 8DD3778
	.incbin "graphics/naming_screen/menu.gbapal"

	.align 2
gNamingScreenMenu_Gfx:: @ 8DD3838
	.incbin "graphics/naming_screen/menu.4bpp.lz"

	.align 2
gNamingScreenRWindow_Gfx:: @ 8DD3A04
	.incbin "graphics/naming_screen/rwindow.4bpp"

	.align 2
gNamingScreenROptions_Gfx:: @ 8DD4044
	.incbin "graphics/naming_screen/roptions.4bpp"

	.align 2
gNamingScreenCursor_Gfx:: @ 8DD4224
	.incbin "graphics/naming_screen/cursor.4bpp"

	.align 2
gNamingScreenKeyboardButton_Gfx:: @ 8DD43E4
	.incbin "graphics/naming_screen/keyboard_button.4bpp"

	.align 2
gNamingScreenRightPointingTriangleTiles:: @ 8DD4504
	.incbin "graphics/naming_screen/right_pointing_triangle.4bpp"

	.align 2
gNamingScreenUnderscoreTiles:: @ 8DD4524
	.incbin "graphics/naming_screen/underscore.4bpp"

	.align 2
gUnknown_08DD4544:: @ 8DD4544
	.incbin "graphics/unknown/unknown_DD4544.bin.lz"

	.align 2
gUnknown_08DD4620:: @ 8DD4620
	.incbin "graphics/unknown/unknown_DD4620.bin.lz"

	.align 2
gUnknown_08DD46E0:: @ 8DD46E0
	.incbin "graphics/unknown/unknown_DD46E0.bin.lz"

	.align 2
gUnknown_08DD47A0:: @ 8DD47A0
	.incbin "graphics/unknown/unknown_DD47A0.bin.lz"

	@ link

	.align 2
gLinkMiscMenu_Pal:: @ 8DD4860
	.incbin "graphics/link/misc.gbapal"

	.align 2
gLinkMiscMenu_Gfx:: @ 8DD4880
	.incbin "graphics/link/misc.4bpp.lz" @ dont know where this is used

	.align 2
gLinkMiscMenu_Tilemap:: @ 8DD4AB8
	.incbin "graphics/link/misc.bin.lz"

	.align 2
gUnknown_08DD4BB0:: @ 8DD4BB0
	.incbin "graphics/link/link1.gbapal"

	.align 2
gUnknown_08DD4BD0:: @ 8DD4BD0
	.incbin "graphics/link/link2.gbapal"

	.align 2
gUnknown_08DD4BF0:: @ 8DD4BF0
	.incbin "graphics/link/link_winedge.4bpp.lz"

	.align 2
gUnknown_08DD4C4C:: @ 8DD4C4C
	.incbin "graphics/link/link_winedge.bin.lz"

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

	@ trade/egg hatch

	.align 2
gTradeGba_Pal:: @ 8DD72E0
	.incbin "graphics/link/gba.gbapal"

	.align 2
gTradeGba2_Pal:: @ 8DD7300
	.incbin "graphics/link/gba_pal2.gbapal" @ used for in-game trade GBA?

	.align 2
gTradeGba_Gfx:: @ 8DD7360
	.incbin "graphics/link/gba.4bpp"

	@ 8DD8760
	.space 0x20 @ blank palette??

	@ berry fix program

	.align 2
gBerryFixGameboy_Pal:: @ 8DD8780
	.incbin "graphics/berry_fix/gba_small.gbapal"

	.align 2
gBerryFixGameboy_Gfx:: @ 8DD87C0
	.incbin "graphics/berry_fix/gba_small.4bpp.lz"

	.align 2
gBerryFixGameboy_Tilemap:: @ 8DD8EE0
	.incbin "graphics/berry_fix/gba_small.bin.lz"

	.align 2
gBerryFixGameboyLogo_Pal:: @ 8DD9080
	.incbin "graphics/berry_fix/logo.gbapal"

	.align 2
gBerryFixGameboyLogo_Gfx:: @ 8DD90E0
	.incbin "graphics/berry_fix/logo.4bpp.lz"

	.align 2
gBerryFixGameboyLogo_Tilemap:: @ 8DD9718
	.incbin "graphics/berry_fix/logo.bin.lz"

	.align 2
gBerryFixGbaTransfer_Pal:: @ 8DD9874
	.incbin "graphics/berry_fix/gba_transfer.gbapal"

	.align 2
gBerryFixGbaTransfer_Gfx:: @ 8DD98B4
	.incbin "graphics/berry_fix/gba_transfer.4bpp.lz"

	.align 2
gBerryFixGbaTransfer_Tilemap:: @ 8DD9E58
	.incbin "graphics/berry_fix/gba_transfer.bin.lz"

	.align 2
gBerryFixGbaTransferHighlight_Pal:: @ 8DD9FEC
	.incbin "graphics/berry_fix/gba_transfer_highlight.gbapal"

	.align 2
gBerryFixGbaTransferHighlight_Gfx:: @ 8DDA02C
	.incbin "graphics/berry_fix/gba_transfer_highlight.4bpp.lz"

	.align 2
gBerryFixGbaTransferHighlight_Tilemap:: @ 8DDA63C
	.incbin "graphics/berry_fix/gba_transfer_highlight.bin.lz"

	.align 2
gBerryFixGbaTransferError_Pal:: @ 8DDA800
	.incbin "graphics/berry_fix/gba_transfer_error.gbapal"

	.align 2
gBerryFixGbaTransferError_Gfx:: @ 8DDA840
	.incbin "graphics/berry_fix/gba_transfer_error.4bpp.lz"

	.align 2
gBerryFixGbaTransferError_Tilemap:: @ 8DDAE40
	.incbin "graphics/berry_fix/gba_transfer_error.bin.lz"

	.align 2
gBerryFixWindow_Pal:: @ 8DDAFE0
	.incbin "graphics/berry_fix/window.gbapal"

	.align 2
gBerryFixWindow_Gfx:: @ 8DDB020
	.incbin "graphics/berry_fix/window.4bpp.lz" @ why the absurd length?

	.align 2
gBerryFixWindow_Tilemap:: @ 8DDB2C4
	.incbin "graphics/berry_fix/window.bin.lz"

	@ more trade stuff?

	.align 2
gUnknown_08DDB3E4:: @ 8DDB3E4
	.incbin "graphics/trade/menu.gbapal"

	.align 2
gUnknown_08DDB444:: @ 8DDB444
	.incbin "graphics/unknown/unknown_DDB444.gbapal"

	.align 2
gUnknown_08DDB464:: @ 8DDB464
	.incbin "graphics/trade/menu.4bpp"

	.align 2
gUnknown_08DDC6E4:: @ 8DDC6E4
	.incbin "graphics/trade/buttons.4bpp"

	.align 2
	.incbin "graphics/unused/unused_DDCEE4.bin" @ unused

	.align 2
gUnknown_08DDCF04:: @ 8DDCF04
	.incbin "graphics/unknown/unknown_DDCF04.bin" @ tilemap

	.align 2
gUnknown_08DDD704:: @ 8DDD704
	.incbin "graphics/unknown/unknown_DDD704.bin" @ textbox tilemap??

	.align 2
gMessageBox_Pal:: @ 8DDD728
	.incbin "graphics/text_window/message_box.gbapal"

	.align 2
gMessageBox_Gfx:: @ 8DDD748
	.incbin "graphics/text_window/message_box.4bpp"

	.align 2
gWallpaperIcon_Cross::
	.incbin "graphics/pokemon_storage/cross_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Bolt::
	.incbin "graphics/pokemon_storage/bolt_icon.4bpp.lz"

	.align 2
gWallpaperIcon_Plusle::
	.incbin "graphics/pokemon_storage/plusle_icon.4bpp.lz"

	.align 2
gWallpaperPalettes_Horizontal:: @ 8DDD950
	.incbin "graphics/pokemon_storage/friends_frame2.gbapal"
	.incbin "graphics/pokemon_storage/horizontal_bg.gbapal"

	.align 2
gWallpaperTiles_Horizontal:: @ 8DDD990
	.incbin "graphics/pokemon_storage/horizontal.4bpp.lz"

	.align 2
gWallpaperTilemap_Horizontal:: @ 8DDDB80
	.incbin "graphics/pokemon_storage/horizontal.bin.lz"

	.align 2
gWallpaperPalettes_Ribbon:: @ 8DDDC8C
	.incbin "graphics/pokemon_storage/ribbon_frame.gbapal"
	.incbin "graphics/pokemon_storage/ribbon_bg.gbapal"

	.align 2
gWallpaperTiles_Ribbon:: @ 8DDDCCC
	.incbin "graphics/pokemon_storage/ribbon.4bpp.lz"

	.align 2
gWallpaperTilemap_Ribbon:: @ 8DDDEDC
	.incbin "graphics/pokemon_storage/ribbon.bin.lz"

	@ pokenav

	.align 2
gUnknown_08DDE010:: @ 8DDE010
	.incbin "graphics/pokenav/ribbons.gbapal"

	.align 2
gUnknown_08DDE030:: @ 8DDE030
	.incbin "graphics/pokenav/ribbons.4bpp.lz"

	.align 2
gUnknown_08DDE12C:: @ 8DDE12C
	.incbin "graphics/pokenav/ribbons.bin.lz"

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
	.incbin "graphics/title_screen/title_screen1.bin.lz"

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
	.incbin "graphics/title_screen/title_screen2.bin.lz"

	@ more trainer card stuff

	.align 2
gUnknown_08DE07C8:: @ 8DE07C8
	.incbin "graphics/frontier_pass/tiles.gbapal" @ size in LoadPalette calls is reported as 0xD0 << 1, which is 0x1A0, but palette is only 0x100 bytes long so it loads garbage as well

	.align 2
gUnknown_08DE08C8:: @ 8DE08C8
	.incbin "graphics/frontier_pass/tiles.4bpp.lz"

	.align 2
gUnknown_08DE2084:: @ 8DE2084
	.incbin "graphics/frontier_pass/tiles2.8bpp.lz"

	.align 2
gUnknown_08DE3060:: @ 8DE3060
	.incbin "graphics/frontier_pass/tiles.bin.lz"

	.align 2
gUnknown_08DE3350:: @ 8DE3350
	.incbin "graphics/frontier_pass/tilemap1.bin"

	.align 2
gUnknown_08DE3374:: @ 8DE3374
	.incbin "graphics/frontier_pass/tilemap2.bin"

	@ berry crusher

	.align 2
gUnknown_08DE3398:: @ 8DE3398
	.incbin "graphics/berry_crusher/tiles.gbapal"

	.align 2
gUnknown_08DE34B8:: @ 8DE34B8
	.incbin "graphics/berry_crusher/tiles.4bpp.lz"

	.align 2
gUnknown_08DE3FD4:: @ 8DE3FD4
	.incbin "graphics/berry_crusher/tiles.bin.lz"

	@ random garbage at the end. why, game freak?
	.space 0x54BAC
	.byte 0x0D, 0x00, 0x58, 0x02 @ why?
	@ E38BC8
	.space 0x1145
	.byte 0x02 @ whyyyyy?
	.space 0x3242
	.byte 0x40 @ WHYYYYYYYY
	.space 0x13
