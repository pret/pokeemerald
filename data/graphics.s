	.section gfx_data, "aw", %progbits

gBattleTextboxTiles:: @ 8C00000
	.incbin "baserom.gba", 0xc00000, 0x4e0

gBattleTextboxPalette:: @ 8C004E0
	.incbin "baserom.gba", 0xc004e0, 0x44

gBattleTextboxTilemap:: @ 8C00524
	.incbin "baserom.gba", 0xc00524, 0x22c

@ 8C00750
	.include "data/graphics/pokemon/circled_question_mark_graphics.inc"

@ 8C00C10
	.incbin "baserom.gba", 0xc00c10, 0xa34

gUnknown_08C01644:: @ 8C01644
	.incbin "baserom.gba", 0xc01644, 0xe0

gUnknown_08C01724:: @ 8C01724
	.incbin "baserom.gba", 0xc01724, 0x18

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
	.incbin "baserom.gba", 0xC019E0, 0xB4

	.align 2
gInterfacePal_UltraBall::
	.incbin "baserom.gba", 0xC01A94, 0x20

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

gOpenPokeballGfx:: @ 8C02300
	.incbin "baserom.gba", 0xc02300, 0x7c

gBlankGfxCompressed:: @ 8C0237C
	.incbin "baserom.gba", 0xc0237c, 0x7074

gUnknown_08C093F0:: @ 8C093F0
	.incbin "baserom.gba", 0xc093f0, 0x87ac

	.align 2
gBattleInterface_BallStatusBarPal:: @ 8C11B9C
	.incbin "graphics/battle_interface/ball_status_bar.gbapal"

	.align 2
gBattleInterface_BallDisplayPal:: @ 8C11BBC
	.incbin "graphics/battle_interface/ball_display.gbapal"

	.align 2
gHealthboxElementsGfxTable:: @ 8C11BDC
	.incbin "baserom.gba", 0xc11bdc, 0x840

	.align 2
gBattleInterface_BallDisplayGfx:: @ 8C1241C
	.incbin "graphics/battle_interface/ball_display.4bpp"

	.align 2
gUnknown_08C1249C:: @ 8C1249C
	.incbin "baserom.gba", 0xc1249c, 0x49f4

gUnknown_08C16E90:: @ 8C16E90
	.incbin "baserom.gba", 0xc16e90, 0x118

gUnknown_08C16FA8:: @ 8C16FA8
	.incbin "baserom.gba", 0xc16fa8, 0x1c8

gUnknown_08C17170:: @ 8C17170
	.incbin "baserom.gba", 0xc17170, 0x810

gUnknown_08C17980:: @ 8C17980
	.incbin "baserom.gba", 0xc17980, 0x130

gUnknown_08C17AB0:: @ 8C17AB0
	.incbin "baserom.gba", 0xc17ab0, 0xa5c

gUnknown_08C1850C:: @ 8C1850C
	.incbin "baserom.gba", 0xc1850c, 0xc5c

gUnknown_08C19168:: @ 8C19168
	.incbin "baserom.gba", 0xc19168, 0x11c

gContestJudgeSymbolsGfx:: @ 8C19284
	.incbin "baserom.gba", 0xc19284, 0x1a4

gContest3Pal:: @ 8C19428
	.incbin "baserom.gba", 0xc19428, 0x28

gUnknown_08C19450:: @ 8C19450
	.incbin "baserom.gba", 0xc19450, 0x138

gUnknown_08C19588:: @ 8C19588
	.incbin "baserom.gba", 0xc19588, 0x964

gUnknown_08C19EEC:: @ 8C19EEC
	.incbin "baserom.gba", 0xc19eec, 0x114

gUnknown_08C1A000:: @ 8C1A000
	.incbin "baserom.gba", 0xc1a000, 0x12c

gUnknown_08C1A12C:: @ 8C1A12C
	.incbin "baserom.gba", 0xc1a12c, 0x188

gUnknown_08C1A2B4:: @ 8C1A2B4
	.incbin "baserom.gba", 0xc1a2b4, 0x1DC

gUnknown_08C1A490:: @ 8C1A490
	.incbin "baserom.gba", 0xc1a490, 0xD4

gUnknown_08C1A564:: @ 8C1A564
	.incbin "baserom.gba", 0xc1a564, 0x1E80

gContestJudgeGfx:: @ 8C1C3E4
	.incbin "baserom.gba", 0xc1c3e4, 0x2d4

gUnknown_08C1C6B8:: @ 8C1C6B8
	.incbin "baserom.gba", 0xc1c6b8, 0x9f4

gUnknown_08C1D0AC:: @ 8C1D0AC
	.incbin "baserom.gba", 0xc1d0ac, 0x13c

gUnknown_08C1D1E8:: @ 8C1D1E8
	.incbin "baserom.gba", 0xc1d1e8, 0x28

gUnknown_08C1D210:: @ 8C1D210
	.incbin "baserom.gba", 0xc1d210, 0x1fb8

gUnknown_08C1F1C8:: @ 8C1F1C8
	.incbin "baserom.gba", 0xc1f1c8, 0x2a4

gUnknown_08C1F46C:: @ 8C1F46C
	.incbin "baserom.gba", 0xc1f46c, 0x17c

gUnknown_08C1F5E8:: @ 8C1F5E8
	.incbin "baserom.gba", 0xc1f5e8, 0x184

gUnknown_08C1F76C:: @ 8C1F76C
	.incbin "baserom.gba", 0xc1f76c, 0x17c

gUnknown_08C1F8E8:: @ 8C1F8E8
	.incbin "baserom.gba", 0xc1f8e8, 0xd80

gUnknown_08C20668:: @ 8C20668
	.incbin "baserom.gba", 0xc20668, 0x1c

gUnknown_08C20684:: @ 8C20684
	.incbin "baserom.gba", 0xc20684, 0x1f8c

gUnknown_08C22610:: @ 8C22610
	.incbin "baserom.gba", 0xc22610, 0xcd0

gUnknown_08C232E0:: @ 8C232E0
	.incbin "baserom.gba", 0xc232e0, 0xa70

gUnknown_08C23D50:: @ 8C23D50
	.incbin "baserom.gba", 0xc23d50, 0x28

gUnknown_08C23D78:: @ 8C23D78
	.incbin "baserom.gba", 0xc23d78, 0xc58

gUnknown_08C249D0:: @ 8C249D0
	.incbin "baserom.gba", 0xc249d0, 0x28

gUnknown_08C249F8:: @ 8C249F8
	.incbin "baserom.gba", 0xc249f8, 0x5c3c

gUnknown_08C2A634:: @ 8C2A634
	.incbin "baserom.gba", 0xc2a634, 0xa0

gUnknown_08C2A6D4:: @ 8C2A6D4
	.incbin "baserom.gba", 0xc2a6d4, 0x18

gUnknown_08C2A6EC:: @ 8C2A6EC
	.incbin "baserom.gba", 0xc2a6ec, 0x27d0

gSubstituteDollPal:: @ 8C2CEBC
	.incbin "baserom.gba", 0xc2cebc, 0x24

gSubstituteDollGfx:: @ 8C2CEE0
	.incbin "baserom.gba", 0xc2cee0, 0x240

gSubstituteDollTilemap:: @ 8C2D120
	.incbin "baserom.gba", 0xc2d120, 552

gUnknown_08C2D348:: @ 8C2D348
	.incbin "baserom.gba", 0xC2D348, 196

gUnknown_08C2D40C:: @ 8C2D40C
	.incbin "baserom.gba", 0xC2D40C, 28

gContestConfetti_Gfx:: @ 8C2D428
	.incbin "baserom.gba", 0xC2D428, 288

gContestConfetti_Pal:: @ 8C2D548
	.incbin "baserom.gba", 0xC2D548, 40

gUnknown_08C2D570:: @ 8C2D570
	.incbin "baserom.gba", 0xC2D570, 316

gUnknown_08C2D6AC:: @ 8C2D6AC
	.incbin "baserom.gba", 0xC2D6AC, 36

gUnknown_08C2D6D0:: @ 8C2D6D0
	.incbin "baserom.gba", 0xC2D6D0, 40

gUnknown_08C2D6F8:: @ 8C2D6F8
	.incbin "baserom.gba", 0xC2D6F8, 40

gUnknown_08C2D720:: @ 8C2D720
	.incbin "baserom.gba", 0xc2d720, 0x210

gUnknown_08C2D930:: @ 8C2D930
	.incbin "baserom.gba", 0xc2d930, 0x11c

gUnknown_08C2DA4C:: @ 8C2DA4C
	.incbin "baserom.gba", 0xc2da4c, 0x11c

gUnknown_08C2DB68:: @ 8C2DB68
	.incbin "baserom.gba", 0xc2db68, 0x20

gUnknown_08C2DB88:: @ 8C2DB88
	.incbin "baserom.gba", 0xc2db88, 0x20

gUnknown_08C2DBA8:: @ 8C2DBA8
	.incbin "baserom.gba", 0xc2dba8, 0x20

gUnknown_08C2DBC8:: @ 8C2DBC8
	.incbin "baserom.gba", 0xc2dbc8, 0x20

gUnknown_08C2DBE8:: @ 8C2DBE8
	.incbin "baserom.gba", 0xc2dbe8, 0x20

gUnknown_08C2DC08:: @ 8C2DC08
	.incbin "baserom.gba", 0xc2dc08, 0x20

gUnknown_08C2DC28:: @ 8C2DC28
	.incbin "baserom.gba", 0xc2dc28, 0x20

gUnknown_08C2DC48:: @ 8C2DC48
	.incbin "baserom.gba", 0xc2dc48, 0x20

gUnknown_08C2DC68:: @ 8C2DC68
	.incbin "baserom.gba", 0xc2dc68, 0x13c

gUnknown_08C2DDA4:: @ 8C2DDA4
	.incbin "baserom.gba", 0xc2dda4, 0x20

gUnknown_08C2DDC4:: @ 8C2DDC4
	.incbin "baserom.gba", 0xc2ddc4, 0xc8c

gUnknown_08C2EA50:: @ 8C2EA50
	.incbin "baserom.gba", 0xc2ea50, 0x4c

gUnknown_08C2EA9C:: @ 8C2EA9C
	.incbin "baserom.gba", 0xc2ea9c, 0xf6c

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

gUnknown_08D778F0:: @ 8D778F0
	.incbin "baserom.gba", 0xd778f0, 0xe8

gUnknown_08D779D8:: @ 8D779D8
	.incbin "baserom.gba", 0xd779d8, 0x10c

gUnknown_08D77AE4:: @ 8D77AE4
	.incbin "baserom.gba", 0xd77ae4, 0x28

gUnknown_08D77B0C:: @ 8D77B0C
	.incbin "baserom.gba", 0xd77b0c, 0x25c

gBattleTerrainTiles_TallGrass:: @ 8D77D68
	.incbin "baserom.gba", 0xd77d68, 0x5b0

gBattleTerrainPalette_TallGrass:: @ 8D78318
	.incbin "baserom.gba", 0xd78318, 0x38

gBattleTerrainTilemap_TallGrass:: @ 8D78350
	.incbin "baserom.gba", 0xd78350, 0x2b0

gBattleTerrainTiles_LongGrass:: @ 8D78600
	.incbin "baserom.gba", 0xd78600, 0x678

gBattleTerrainPalette_LongGrass:: @ 8D78C78
	.incbin "baserom.gba", 0xd78C78, 0x40

gBattleTerrainTilemap_LongGrass:: @ 8D78CB8
	.incbin "baserom.gba", 0xd78CB8, 0x2b0

gBattleTerrainTiles_Sand:: @ 8D78F68
	.incbin "baserom.gba", 0xd78f68, 0x5f8

gBattleTerrainPalette_Sand:: @ 8D79560
	.incbin "baserom.gba", 0xd79560, 0x48

gBattleTerrainTilemap_Sand:: @ 8D795A8
	.incbin "baserom.gba", 0xd795A8, 0x2b0

gBattleTerrainTiles_Underwater:: @ 8D79858
	.incbin "baserom.gba", 0xd79858, 0x5b8

gBattleTerrainPalette_Underwater:: @ 8D79E10
	.incbin "baserom.gba", 0xd79E10, 0x48

gBattleTerrainTilemap_Underwater:: @ 8D79E58
	.incbin "baserom.gba", 0xd79e58, 0x2b0

gBattleTerrainTiles_Water:: @ 8D7A108
	.incbin "baserom.gba", 0xd7a108, 0x5d4

gBattleTerrainPalette_Water:: @ 8D7A6DC
	.incbin "baserom.gba", 0xd7a6DC, 0x44

gBattleTerrainTilemap_Water:: @ 8D7A720
	.incbin "baserom.gba", 0xd7a720, 0x2b0

gBattleTerrainTiles_PondWater:: @ 8D7A9D0
	.incbin "baserom.gba", 0xd7a9D0, 0x5a8

gBattleTerrainPalette_PondWater:: @ 8D7AF78
	.incbin "baserom.gba", 0xd7af78, 0x40

gBattleTerrainTilemap_PondWater:: @ 8D7AFB8
	.incbin "baserom.gba", 0xd7aFB8, 0x2b0

gBattleTerrainTiles_Rock:: @ 8D7B268
	.incbin "baserom.gba", 0xd7b268, 0x5c0

gBattleTerrainPalette_Rock:: @ 8D7B828
	.incbin "baserom.gba", 0xd7b828, 0x3c

gBattleTerrainTilemap_Rock:: @ 8D7B864
	.incbin "baserom.gba", 0xd7b864, 0x2b0

gBattleTerrainTiles_Cave:: @ 8D7BB14
	.incbin "baserom.gba", 0xd7bb14, 0x5f8

gBattleTerrainPalette_Cave:: @ 8D7C10C
	.incbin "baserom.gba", 0xd7c10c, 0x48

gBattleTerrainTilemap_Cave:: @ 8D7C154
	.incbin "baserom.gba", 0xd7c154, 0x2b0

gBattleTerrainPalette_Plain:: @ 8D7C404
	.incbin "baserom.gba", 0xd7c404, 0x3c

gBattleTerrainTiles_Building:: @ 8D7C440
	.incbin "baserom.gba", 0xd7c440, 0x5ac

gBattleTerrainPalette_Frontier:: @ 8D7C9EC
	.incbin "baserom.gba", 0xd7c9ec, 0x3c

gBattleTerrainTilemap_Building:: @ 8D7CA28
	.incbin "baserom.gba", 0xd7ca28, 0x2b0

gBattleTerrainTiles_Stadium:: @ 8D7CCD8
	.incbin "baserom.gba", 0xd7ccd8, 0x608

gBattleTerrainTilemap_Stadium:: @ 8D7D2E0
	.incbin "baserom.gba", 0xd7d2e0, 0x2b0

gBattleTerrainTiles_Rayquaza:: @ 8D7D590
	.incbin "baserom.gba", 0xd7d590, 0x674

gBattleTerrainTilemap_Rayquaza:: @ 8D7DC04
	.incbin "baserom.gba", 0xd7dc04, 0x2b0

gBattleTerrainPalette_Building:: @ 8D7DEB4
	.incbin "baserom.gba", 0xd7deb4, 0x40

gBattleTerrainPalette_Kyogre:: @ 8D7DEF4
	.incbin "baserom.gba", 0xd7def4, 0x3c

gBattleTerrainPalette_Groudon:: @ 8D7DF30
	.incbin "baserom.gba", 0xd7df30, 0x58

gBattleTerrainPalette_BuildingGym:: @ 8D7DF88
	.incbin "baserom.gba", 0xd7df88, 0x3c

gBattleTerrainPalette_BuildingLeader:: @ 8D7DFC4
	.incbin "baserom.gba", 0xd7dfc4, 0x3c

gBattleTerrainPalette_StadiumAqua:: @ 8D7E000
	.incbin "baserom.gba", 0xd7e000, 0x60

gBattleTerrainPalette_StadiumMagma:: @ 8D7E060
	.incbin "baserom.gba", 0xd7e060, 0x6c

gBattleTerrainPalette_StadiumSidney:: @ 8D7E0CC
	.incbin "baserom.gba", 0xd7e0cc, 0x50

gBattleTerrainPalette_StadiumPhoebe:: @ 8D7E11C
	.incbin "baserom.gba", 0xd7e11c, 0x48

gBattleTerrainPalette_StadiumGlacia:: @ 8D7E164
	.incbin "baserom.gba", 0xd7e164, 0x44

gBattleTerrainPalette_StadiumDrake:: @ 8D7E1A8
	.incbin "baserom.gba", 0xd7e1a8, 0x50

gBattleTerrainPalette_StadiumWallace:: @ 8D7E1F8
	.incbin "baserom.gba", 0xd7e1f8, 0x3c

gBattleTerrainPalette_Rayquaza:: @ 8D7E234
	.incbin "baserom.gba", 0xd7e234, 0x4c

gBattleTerrainAnimTiles_TallGrass:: @ 8D7E280
	.incbin "baserom.gba", 0xd7e280, 0x588

gBattleTerrainAnimTilemap_TallGrass:: @ 8D7E808
	.incbin "baserom.gba", 0xd7e808, 0x1bc

gBattleTerrainAnimTiles_LongGrass:: @ 8D7E9C4
	.incbin "baserom.gba", 0xd7e9C4, 0x710

gBattleTerrainAnimTilemap_LongGrass:: @ 8D7F0D4
	.incbin "baserom.gba", 0xd7F0D4, 0x238

gBattleTerrainAnimTiles_Sand:: @ 8D7F30C
	.incbin "baserom.gba", 0xd7F30c, 0x544

gBattleTerrainAnimTilemap_Sand:: @ 8D7F850
	.incbin "baserom.gba", 0xd7F850, 0x1a8

gBattleTerrainAnimTiles_Underwater:: @ 8D7F9F8
	.incbin "baserom.gba", 0xd7f9f8, 0x4cc

gBattleTerrainAnimTilemap_Underwater:: @ 8D7FEC4
	.incbin "baserom.gba", 0xd7fec4, 0x190

gBattleTerrainAnimTiles_Water:: @ 8D80054
	.incbin "baserom.gba", 0xd80054, 0x60c

gBattleTerrainAnimTilemap_Water:: @ 8D80660
	.incbin "baserom.gba", 0xd80660, 0x1a4

gBattleTerrainAnimTiles_PondWater:: @ 8D80804
	.incbin "baserom.gba", 0xd80804, 0x54c

gBattleTerrainAnimTilemap_PondWater:: @ 8D80D50
	.incbin "baserom.gba", 0xd80d50, 0x14C

gBattleTerrainAnimTiles_Rock:: @ 8D80E9C
	.incbin "baserom.gba", 0xd80e9c, 0x5e0

gBattleTerrainAnimTilemap_Rock:: @ 8D8147C
	.incbin "baserom.gba", 0xd8147C, 0x194

gBattleTerrainAnimTiles_Cave:: @ 8D81610
	.incbin "baserom.gba", 0xd81610, 0x81c

gBattleTerrainAnimTilemap_Cave:: @ 8D81E2C
	.incbin "baserom.gba", 0xd81e2c, 0x2a8

gBattleTerrainAnimTiles_Building:: @ 8D820D4
	.incbin "baserom.gba", 0xd820d4, 0x410

gBattleTerrainAnimTilemap_Building:: @ 8D824E4
	.incbin "baserom.gba", 0xd824e4, 0x124

gBattleTerrainAnimTiles_Rayquaza:: @ 8D82608
	.incbin "baserom.gba", 0xd82608, 0x668

gBattleTerrainAnimTilemap_Rayquaza:: @ 8D82C70
	.incbin "baserom.gba", 0xd82c70, 0x2a0

gUnknown_08D82F10:: @ 8D82F10
	.incbin "baserom.gba", 0xd82f10, 0x5ec

gUnknown_08D834FC:: @ 8D834FC
	.incbin "baserom.gba", 0xd834fc, 0x404

gUnknown_08D83900:: @ 8D83900
	.incbin "baserom.gba", 0xd83900, 0x22c

gUnknown_08D83B2C:: @ 8D83B2C
	.incbin "baserom.gba", 0xd83b2c, 0x110

gUnknown_08D83C3C:: @ 8D83C3C
	.incbin "baserom.gba", 0xd83c3c, 0x114

gUnknown_08D83D50:: @ 8D83D50
	.incbin "baserom.gba", 0xd83d50, 0xc20

gUnknown_08D84970:: @ 8D84970
	.incbin "baserom.gba", 0xd84970, 0x590

gUnknown_08D84F00:: @ 8D84F00
	.incbin "baserom.gba", 0xd84f00, 0x158

gUnknown_08D85058:: @ 8D85058
	.incbin "baserom.gba", 0xd85058, 0x300

gUnknown_08D85358:: @ 8D85358
	.incbin "baserom.gba", 0xd85358, 0xec

gUnknown_08D85444:: @ 8D85444
	.incbin "baserom.gba", 0xd85444, 0x84

gUnknown_08D854C8:: @ 8D854C8
	.incbin "baserom.gba", 0xd854c8, 0x20

gUnknown_08D854E8:: @ 8D854E8
	.incbin "baserom.gba", 0xd854E8, 0x100

gUnknown_08D855E8:: @ 8D855E8
	.incbin "baserom.gba", 0xd855e8, 0x18

gUnknown_08D85600:: @ 8D85600
	.incbin "baserom.gba", 0xd85600, 0x20

gUnknown_08D85620:: @ 8D85620
	.incbin "baserom.gba", 0xd85620, 0x20

gUnknown_08D85640:: @ 8D85640
	.incbin "baserom.gba", 0xd85640, 0x20

gUnknown_08D85660:: @ 8D85660
	.incbin "baserom.gba", 0xd85660, 0x20

gUnknown_08D85680:: @ 8D85680
	.incbin "baserom.gba", 0xd85680, 0x20

gUnknown_08D856A0:: @ 8D856A0
	.incbin "baserom.gba", 0xd856a0, 0x28

gUnknown_08D856C8:: @ 8D856C8
	.incbin "baserom.gba", 0xd856c8, 0xe0

gUnknown_08D857A8:: @ 8D857A8
	.incbin "baserom.gba", 0xd857a8, 0x274

gUnknown_08D85A1C:: @ 8D85A1C
	.incbin "baserom.gba", 0xd85a1c, 0x234

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
	.incbin "baserom.gba", 0xd8dab8, 0xe84

gContestNextTurnGfx:: @ 8D8E93C
	.incbin "baserom.gba", 0xd8e93c, 0x78

gUnknown_08D8E9B4:: @ 8D8E9B4
	.incbin "baserom.gba", 0xd8e9b4, 0x80

gUnknown_08D8EA34:: @ 8D8EA34
	.incbin "baserom.gba", 0xd8ea34, 0xb0

gContestApplauseGfx:: @ 8D8EAE4
	.incbin "baserom.gba", 0xd8eaE4, 0x140

gUnknown_08D8EC24:: @ 8D8EC24
	.incbin "baserom.gba", 0xd8ec24, 0x80

gContestPal:: @ 8D8ECA4
	.incbin "baserom.gba", 0xd8eca4, 0xef8

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

	.align 2
gRouletteWheelTiles:: @ 0x08DBCA14
	.incbin "graphics/roulette/wheel.8bpp.lz"

	.align 2
gRouletteCenter_Gfx:: @ 0x08DBDABC
	.incbin "graphics/roulette/center.4bpp.lz"

	.align 2
gRouletteHeadersTiles:: @ 0x08DBDE38
	.incbin "graphics/roulette/headers.4bpp.lz"

	.align 2
gRouletteCreditTiles:: @ 0x08DBE45C
	.incbin "graphics/roulette/credit.4bpp.lz"

	.align 2
gRouletteNumbersTiles:: @ 0x08DBE5AC
	.incbin "graphics/roulette/numbers.4bpp.lz"

	.align 2
gRouletteMultiplierTiles:: @ 0x08DBE690
	.incbin "graphics/roulette/multiplier.4bpp.lz"

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
