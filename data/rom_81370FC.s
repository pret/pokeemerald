@ the fourth big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085B27C8:: @ 85B27C8
	.byte 0x01, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x02, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x03, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x05, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x06, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x07, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x08, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x09, 0x04, 0x01, 0x00
	.4byte sub_81375A8
	.byte 0x04, 0x01, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x02, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x03, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x05, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x06, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x07, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x08, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x04, 0x09, 0x00, 0x01
	.4byte sub_81373F0
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte NULL

	.align 2
gUnknown_085B2850:: @ 85B2850
	.incbin "graphics/unknown/unknown_5B2850.gbapal"

	.align 2
gUnknown_085B2870:: @ 85B2870
	.incbin "graphics/unknown/unknown_5B2870.gbapal"

	.align 2
gUnknown_085B2890:: @ 85B2890
	.incbin "graphics/unknown/unknown_5B2890.gbapal"

	.align 2
gUnknown_085B28A0:: @ 85B28A0
	.incbin "graphics/unknown/unknown_5B28A0.gbapal"

	.align 2
gUnknown_085B28B0:: @ 85B28B0
	.incbin "graphics/unknown/unknown_5B28B0.bin.lz"

	.align 2
gUnknown_085B2A90:: @ 85B2A90
	.incbin "graphics/unknown/unknown_5B2A90.4bpp.lz"

gUnknown_085B2B44:: @ 85B2B44
	.byte 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01

	.align 2
gUnknown_085B2B5C:: @ 85B2B5C
	.byte 0x07, 0x09, 0x08, 0x0a

	.align 2
gUnknown_085B2B60:: @ 85B2B60
	.byte 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0x00

gUnknown_085B2B68:: @ 85B2B68
	.byte 0x07, 0x16, 0x00, 0x00, 0x0b, 0x13, 0x00, 0x00, 0x0a, 0x10, 0x00, 0x00, 0x0f, 0x10, 0x00, 0x00

gUnknown_085B2B78:: @ 85B2B78
	.byte 0x00, 0x01, 0x01, 0x01, 0x01, 0x00

	.align 1
gUnknown_085B2B7E:: @ 85B2B7E
	.2byte 0x0218, 0x0219, 0x021a, 0x021b, 0x021c

gUnknown_085B2B88:: @ 85B2B88
	.byte 0x0c, 0x02, 0x04, 0x05, 0x01, 0x08, 0x07, 0x0b, 0x03, 0x0a, 0x09, 0x06

gUnknown_085B2B94:: @ 85B2B94
	.byte 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04, 0x05

gUnknown_085B2BA0:: @ 85B2BA0
	.byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05

	.align 2
gUnknown_085B2BAC:: @ 85B2BAC
	.byte 0x00, 0x15, 0x01, 0x08, 0x04, 0x0f, 0x08, 0x00

	.align 2
gElevatorFloorsTable:: @ 85B2BB4
	.4byte gText_B4F
	.4byte gText_B3F
	.4byte gText_B2F
	.4byte gText_B1F
	.4byte gText_1F
	.4byte gText_2F
	.4byte gText_3F
	.4byte gText_4F
	.4byte gText_5F
	.4byte gText_6F
	.4byte gText_7F
	.4byte gText_8F
	.4byte gText_9F
	.4byte gText_10F
	.4byte gText_11F
	.4byte gText_Rooftop

	.align 1
gUnknown_085B2BF4:: @ 85B2BF4
	.2byte 0x0329, 0x032a, 0x032b, 0x0331, 0x0332, 0x0333, 0x0339, 0x033a, 0x033b

	.align 1
gUnknown_085B2C06:: @ 85B2C06
	.2byte 0x0329, 0x032b, 0x032a, 0x0331, 0x0333, 0x0332, 0x0339, 0x033b, 0x033a

gUnknown_085B2C18:: @ 85B2C18
	.byte 0x08, 0x10, 0x18, 0x20, 0x26, 0x2e, 0x34, 0x38, 0x39

gUnknown_085B2C21:: @ 85B2C21
	.byte 0x03, 0x06, 0x09, 0x0c, 0x0f, 0x12, 0x15, 0x18, 0x1b

	.align 1
gUnknown_085B2C2A:: @ 85B2C2A
	.2byte 0x0202, 0x0301, 0x0405, 0x0504, 0x0604, 0x0700, 0x0804, 0x090b, 0x0a05, 0x0b05, 0x0c02, 0x0d06, 0x0e03, 0x0f02, 0x100c, 0x100a
	.2byte 0x1a35, 0x193c, 0xffff

	.align 2
gUnknown_085B2C50:: @ 85B2C50
	.4byte BattleFrontier_Lounge2_Text_260971
	.4byte BattleFrontier_Lounge2_Text_260A1E
	.4byte BattleFrontier_Lounge2_Text_260AE7
	.4byte BattleFrontier_Lounge2_Text_2619AC
	.4byte BattleFrontier_Lounge2_Text_261A91
	.4byte BattleFrontier_Lounge2_Text_261B0C
	.4byte BattleFrontier_Lounge2_Text_261B95
	.4byte BattleFrontier_Lounge2_Text_261B95
	.4byte BattleFrontier_Lounge2_Text_261B95
	.4byte BattleFrontier_Lounge2_Text_261C1A
	.4byte BattleFrontier_Lounge2_Text_261C1A
	.4byte BattleFrontier_Lounge2_Text_261C1A
	.4byte BattleFrontier_Lounge2_Text_260BC4
	.4byte BattleFrontier_Lounge2_Text_260C6D
	.4byte BattleFrontier_Lounge2_Text_260D3A
	.4byte BattleFrontier_Lounge2_Text_260E1E
	.4byte BattleFrontier_Lounge2_Text_260EC7
	.4byte BattleFrontier_Lounge2_Text_260F74
	.4byte BattleFrontier_Lounge2_Text_2614E6
	.4byte BattleFrontier_Lounge2_Text_261591
	.4byte BattleFrontier_Lounge2_Text_26166F
	.4byte BattleFrontier_Lounge2_Text_261282
	.4byte BattleFrontier_Lounge2_Text_261329
	.4byte BattleFrontier_Lounge2_Text_261403
	.4byte BattleFrontier_Lounge2_Text_261026
	.4byte BattleFrontier_Lounge2_Text_2610CC
	.4byte BattleFrontier_Lounge2_Text_261194
	.4byte BattleFrontier_Lounge2_Text_26174D
	.4byte BattleFrontier_Lounge2_Text_2617F9
	.4byte BattleFrontier_Lounge2_Text_2618C4

gUnknown_085B2CC8:: @ 85B2CC8
	.byte 0x15, 0x38, 0x15, 0x23, 0xff, 0xff, 0xff, 0xff, 0x02, 0x04, 0x07, 0x15, 0x07, 0x15, 0x0e, 0x1c, 0x0d, 0x70, 0x07, 0x38

	.align 1
gUnknown_085B2CDC:: @ 85B2CDC
	.2byte 0x0007, 0x000e, 0x0015, 0x001c, 0x0023, 0x0031, 0x003f, 0x004d, 0x005b, 0x0000

	.align 2
gUnknown_085B2CF0:: @ 85B2CF0
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_BlueFlute
	.4byte gText_YellowFlute
	.4byte gText_RedFlute
	.4byte gText_WhiteFlute
	.4byte gText_BlackFlute
	.4byte gText_PrettyChair
	.4byte gText_PrettyDesk
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_0Pts
	.4byte gText_10Pts
	.4byte gText_20Pts
	.4byte gText_30Pts
	.4byte gText_40Pts
	.4byte gText_50Pts
	.4byte gText_60Pts
	.4byte gText_70Pts
	.4byte gText_80Pts
	.4byte gText_90Pts
	.4byte gText_100Pts
	.4byte gText_QuestionMark
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_KissPoster16BP
	.4byte gText_KissCushion32BP
	.4byte gText_SmoochumDoll32BP
	.4byte gText_TogepiDoll48BP
	.4byte gText_MeowthDoll48BP
	.4byte gText_ClefairyDoll48BP
	.4byte gText_DittoDoll48BP
	.4byte gText_CyndaquilDoll80BP
	.4byte gText_ChikoritaDoll80BP
	.4byte gText_TotodileDoll80BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_LaprasDoll128BP
	.4byte gText_SnorlaxDoll128BP
	.4byte gText_VenusaurDoll256BP
	.4byte gText_CharizardDoll256BP
	.4byte gText_BlastoiseDoll256BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_Protein1BP
	.4byte gText_Calcium1BP
	.4byte gText_Iron1BP
	.4byte gText_Zinc1BP
	.4byte gText_Carbos1BP
	.4byte gText_HpUp1BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_Leftovers48BP
	.4byte gText_WhiteHerb48BP
	.4byte gText_QuickClaw48BP
	.4byte gText_MentalHerb48BP
	.4byte gText_BrightPowder64BP
	.4byte gText_ChoiceBand64BP
	.4byte gText_KingsRock64BP
	.4byte gText_FocusBand64BP
	.4byte gText_ScopeLens64BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_EnergyPowder50
	.4byte gText_EnergyRoot80
	.4byte gText_HealPowder50
	.4byte gText_RevivalHerb300
	.4byte gText_Protein1000
	.4byte gText_Iron1000
	.4byte gText_Carbos1000
	.4byte gText_Calcium1000
	.4byte gText_Zinc1000
	.4byte gText_HPUp1000
	.4byte gText_PPUp3000
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_BattleTower2
	.4byte gText_BattleDome
	.4byte gText_BattlePalace
	.4byte gText_BattleArena
	.4byte gText_BattleFactory
	.4byte gText_BattlePike
	.4byte gText_BattlePyramid
	.4byte gText_RankingHall
	.4byte gText_ExchangeService
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_Softboiled16BP
	.4byte gText_SeismicToss24BP
	.4byte gText_DreamEater24BP
	.4byte gText_MegaPunch24BP
	.4byte gText_MegaKick48BP
	.4byte gText_BodySlam48BP
	.4byte gText_RockSlide48BP
	.4byte gText_Counter48BP
	.4byte gText_ThunderWave48BP
	.4byte gText_SwordsDance48BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_DefenseCurl16BP
	.4byte gText_Snore24BP
	.4byte gText_MudSlap24BP
	.4byte gText_Swift24BP
	.4byte gText_IcyWind24BP
	.4byte gText_Endure48BP
	.4byte gText_PsychUp48BP
	.4byte gText_IcePunch48BP
	.4byte gText_ThunderPunch48BP
	.4byte gText_FirePunch48BP
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_SlateportCity
	.4byte gText_BattleFrontier
	.4byte gText_SouthernIsland
	.4byte gText_NavelRock
	.4byte gText_BirthIsland
	.4byte gText_FarawayIsland
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.4byte gText_BattleTrainers
	.4byte gText_BattleBasics
	.4byte gText_PokemonNature
	.4byte gText_PokemonMoves
	.4byte gText_Underpowered
	.4byte gText_WhenInDanger
	.4byte gText_Exit
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_085B3030:: @ 85B3030
	.4byte 0x03000002, 0x00000000, 0x07d00000, 0x00000064

	.align 2
gUnknown_085B3040:: @ 85B3040
	.4byte BattleFrontier_Lounge5_Text_26468D
	.4byte BattleFrontier_Lounge5_Text_2646E5
	.4byte BattleFrontier_Lounge5_Text_264741
	.4byte BattleFrontier_Lounge5_Text_2647A4
	.4byte BattleFrontier_Lounge5_Text_2647FC
	.4byte BattleFrontier_Lounge5_Text_264858
	.4byte BattleFrontier_Lounge5_Text_2648BE
	.4byte BattleFrontier_Lounge5_Text_264916
	.4byte BattleFrontier_Lounge5_Text_264972
	.4byte BattleFrontier_Lounge5_Text_2649D5
	.4byte BattleFrontier_Lounge5_Text_264A3F
	.4byte BattleFrontier_Lounge5_Text_264A9B
	.4byte BattleFrontier_Lounge5_Text_264AF3
	.4byte BattleFrontier_Lounge5_Text_264B5D
	.4byte BattleFrontier_Lounge5_Text_2648BE
	.4byte BattleFrontier_Lounge5_Text_264BC3
	.4byte BattleFrontier_Lounge5_Text_264C36
	.4byte BattleFrontier_Lounge5_Text_2648BE
	.4byte BattleFrontier_Lounge5_Text_264C95
	.4byte BattleFrontier_Lounge5_Text_264D01
	.4byte BattleFrontier_Lounge5_Text_264D6B
	.4byte BattleFrontier_Lounge5_Text_264DD7
	.4byte BattleFrontier_Lounge5_Text_264E33
	.4byte BattleFrontier_Lounge5_Text_264E8F
	.4byte BattleFrontier_Lounge5_Text_2648BE

	.align 2
gUnknown_085B30A4:: @ 85B30A4
	.4byte BattleFrontier_Lounge3_Text_262261
	.4byte BattleFrontier_Lounge3_Text_26230D
	.4byte BattleFrontier_Lounge3_Text_2623B9
	.4byte BattleFrontier_Lounge3_Text_262464
	.4byte BattleFrontier_Lounge3_Text_26250E
	.4byte BattleFrontier_Lounge3_Text_2625B8
	.4byte BattleFrontier_Lounge3_Text_26266A
	.4byte BattleFrontier_Lounge3_Text_26271C
	.4byte BattleFrontier_Lounge3_Text_2627C9
	.4byte BattleFrontier_Lounge3_Text_262876
	.4byte BattleFrontier_Lounge3_Text_26291A
	.4byte BattleFrontier_Lounge3_Text_2629BC

	.align 2
gUnknown_085B30D4:: @ 85B30D4
	.4byte BattleFrontier_Lounge3_Text_262C04
	.4byte BattleFrontier_Lounge3_Text_262C90
	.4byte BattleFrontier_Lounge3_Text_262D1C
	.4byte BattleFrontier_Lounge3_Text_262DA7
	.4byte BattleFrontier_Lounge3_Text_262E34
	.4byte BattleFrontier_Lounge3_Text_262EC1
	.4byte BattleFrontier_Lounge3_Text_262F56
	.4byte BattleFrontier_Lounge3_Text_262FEB
	.4byte BattleFrontier_Lounge3_Text_263078
	.4byte BattleFrontier_Lounge3_Text_263105
	.4byte BattleFrontier_Lounge3_Text_26318C
	.4byte BattleFrontier_Lounge3_Text_263211

	.align 1
gUnknown_085B3104:: @ 85B3104
	.2byte 0x0000, 0x0001, 0x0002, 0x0100, 0x0101, 0x0400, 0x0401, 0x0200, 0x0201, 0x0300, 0x0500, 0x0600

	.align 2
gUnknown_085B311C:: @ 85B311C
	window_template 0x00, 0x01, 0x01, 0x06, 0x02, 0x0f, 0x0008

	.align 2
gUnknown_085B3124:: @ 85B3124
	window_template 0x00, 0x02, 0x09, 0x04, 0x04, 0x0f, 0x0014

	.align 1
gUnknown_085B312C:: @ 85B312C
	.2byte 0x004b, 0x0067, 0x0057, 0x004f, 0x0054, 0x0055, 0x0056, 0x0050, 0x0051, 0x0052, 0xffff

	.align 1
gUnknown_085B3142:: @ 85B3142
	.2byte 0x0071, 0x006f, 0x0072, 0x0073, 0x0074, 0xffff

	.align 1
gUnknown_085B314E:: @ 85B314E
	.2byte 0x0040, 0x0043, 0x0041, 0x0046, 0x0042, 0x003f, 0xffff

	.align 1
gUnknown_085B315C:: @ 85B315C
	.2byte 0x00c8, 0x00b4, 0x00b7, 0x00b9, 0x00b3, 0x00ba, 0x00bb, 0x00c4, 0x00c6, 0xffff

	.align 2
gUnknown_085B3170:: @ 85B3170
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2601AA
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2601D0
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260201
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26022F
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26025B
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260287
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2602B5
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2602E0
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26030F
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26033E
	.4byte gText_Exit

	.align 2
gUnknown_085B319C:: @ 85B319C
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C
	.4byte gText_Exit

	.align 2
gUnknown_085B31B4:: @ 85B31B4
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260397
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2603BE
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2603E6
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26040E
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260436
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26045C
	.4byte gText_Exit

	.align 2
gUnknown_085B31D0:: @ 85B31D0
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26047A
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2604AC
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2604D8
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_26050F
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260542
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260575
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2605A8
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_2605E2
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_Text_260613
	.4byte gText_Exit

	.align 1
gUnknown_085B31F8:: @ 85B31F8
	.2byte 0x0087, 0x0045, 0x008a, 0x0005, 0x0019, 0x0022, 0x009d, 0x0044, 0x0056, 0x000e

	.align 1
gUnknown_085B320C:: @ 85B320C
	.2byte 0x006f, 0x00ad, 0x00bd, 0x0081, 0x00c4, 0x00cb, 0x00f4, 0x0008, 0x0009, 0x0007

	.align 2
gUnknown_085B3220:: @ 85B3220
	window_template 0x00, 0x01, 0x07, 0x0c, 0x06, 0x0f, 0x001c

	.align 2
gUnknown_085B3228:: @ 85B3228
	.4byte BattleFrontier_Lounge7_Text_265E30
	.4byte BattleFrontier_Lounge7_Text_265E5B
	.4byte BattleFrontier_Lounge7_Text_265E8A
	.4byte BattleFrontier_Lounge7_Text_265EC0
	.4byte BattleFrontier_Lounge7_Text_265EED
	.4byte BattleFrontier_Lounge7_Text_265F1C
	.4byte BattleFrontier_Lounge7_Text_265F47
	.4byte BattleFrontier_Lounge7_Text_265F77
	.4byte BattleFrontier_Lounge7_Text_265FAA
	.4byte BattleFrontier_Lounge7_Text_265FDD
	.4byte gText_Exit

	.align 2
gUnknown_085B3254:: @ 85B3254
	.4byte BattleFrontier_Lounge7_Text_26600A
	.4byte BattleFrontier_Lounge7_Text_26603E
	.4byte BattleFrontier_Lounge7_Text_266070
	.4byte BattleFrontier_Lounge7_Text_2660A6
	.4byte BattleFrontier_Lounge7_Text_2660D0
	.4byte BattleFrontier_Lounge7_Text_2660FF
	.4byte BattleFrontier_Lounge7_Text_26612D
	.4byte BattleFrontier_Lounge7_Text_26615F
	.4byte BattleFrontier_Lounge7_Text_266185
	.4byte BattleFrontier_Lounge7_Text_2661B5
	.4byte gText_Exit

	.align 2
gUnknown_085B3280:: @ 85B3280
	.incbin "graphics/unknown/unknown_5B3280.gbapal"

gUnknown_085B33E0:: @ 85B33E0
	.byte 0x0f, 0x0c, 0x0b, 0x0e, 0x0f, 0x08, 0x13, 0x0e, 0x0c, 0x0b, 0x12, 0x0b, 0x0f, 0x0e, 0x0b, 0x0e, 0x13, 0x0e, 0x0f, 0x0f, 0x0f, 0x0a

gUnknown_085B33F6:: @ 85B33F6
	.byte 0x04, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x06, 0x03, 0x03

gUnknown_085B3400:: @ 85B3400
	.byte 0x1d, 0x1d, 0x1e, 0x1e, 0x1f, 0x1f, 0x21, 0x21, 0x14, 0x14, 0x28, 0x28, 0x2a, 0x2a, 0x2c, 0x2c

gUnknown_085B3410:: @ 85B3410
	.byte 0x1d, 0x1d, 0x1e, 0x1e, 0x1f, 0x1f, 0x21, 0x21, 0x14, 0x14, 0x28, 0x28, 0x2a, 0x2a, 0x2c, 0x2c

gUnknown_085B3420:: @ 85B3420
	.byte 0x02, 0x04, 0x01, 0x04, 0x04, 0x01, 0x05, 0x00, 0x01, 0x06, 0x03, 0x01, 0x08, 0x06, 0x01, 0x09, 0x0d, 0x01, 0x0a, 0x07, 0x01, 0x0b, 0x07, 0x01, 0x0c, 0x04, 0x01, 0x0e, 0x05, 0x01, 0x0f, 0x04
	.byte 0x01, 0x1a, 0x37, 0x01

	.align 1
gUnknown_085B3444:: @ 85B3444
	.2byte 0x0202, 0x0301, 0x0405, 0x0504, 0x0604, 0x0700, 0x0804, 0x090b, 0x0a05, 0x0b05, 0x0c02, 0x0d06, 0x0e03, 0x0f02, 0x100c, 0x100a
	.2byte 0x1a35, 0x1918, 0x1919, 0x191a, 0x191b, 0xffff

gUnknown_085B3470:: @ 85B3470
	.byte 0x02, 0x01, 0x02, 0x01

gUnknown_085B3474:: @ 85B3474
	.byte 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f

gUnknown_085B347C:: @ 85B347C
	.byte 0x08, 0x0d, 0x0e, 0x0b, 0x0a, 0x0c, 0x0f, 0x09

