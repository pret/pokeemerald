	.align 2
gRoute101_LandMons:: @ 85507E4
	wild_mon SPECIES_WURMPLE, 2
	wild_mon SPECIES_POOCHYENA, 2
	wild_mon SPECIES_WURMPLE, 2
	wild_mon SPECIES_WURMPLE, 3
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_WURMPLE, 3
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_ZIGZAGOON, 2
	wild_mon SPECIES_ZIGZAGOON, 2
	wild_mon SPECIES_ZIGZAGOON, 3
	wild_mon SPECIES_ZIGZAGOON, 3

	.align 2
gRoute101_LandMonsInfo:: @ 8550814
	.4byte 20 @ encounter rate
	.4byte gRoute101_LandMons

	.align 2
gRoute102_LandMons:: @ 855081C
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_WURMPLE, 3
	wild_mon SPECIES_POOCHYENA, 4
	wild_mon SPECIES_WURMPLE, 4
	wild_mon SPECIES_LOTAD, 3
	wild_mon SPECIES_LOTAD, 4
	wild_mon SPECIES_ZIGZAGOON, 3
	wild_mon SPECIES_ZIGZAGOON, 3
	wild_mon SPECIES_ZIGZAGOON, 4
	wild_mon SPECIES_RALTS, 4
	wild_mon SPECIES_ZIGZAGOON, 4
	wild_mon SPECIES_SEEDOT, 3

	.align 2
gRoute102_LandMonsInfo:: @ 855084C
	.4byte 20 @ encounter rate
	.4byte gRoute102_LandMons

	.align 2
gRoute102_WaterMons:: @ 8550854
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_GOLDEEN, 20, 30

	.align 2
gRoute102_WaterMonsInfo:: @ 8550868
	.4byte 4 @ encounter rate
	.4byte gRoute102_WaterMons

	.align 2
gRoute102_FishingMons:: @ 8550870
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_CORPHISH, 10, 30
	wild_mon SPECIES_CORPHISH, 25, 30
	wild_mon SPECIES_CORPHISH, 30, 35
	wild_mon SPECIES_CORPHISH, 20, 25
	wild_mon SPECIES_CORPHISH, 35, 40
	wild_mon SPECIES_CORPHISH, 40, 45

	.align 2
gRoute102_FishingMonsInfo:: @ 8550898
	.4byte 30 @ encounter rate
	.4byte gRoute102_FishingMons

	.align 2
gRoute103_LandMons:: @ 85508A0
	wild_mon SPECIES_POOCHYENA, 2
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_POOCHYENA, 3
	wild_mon SPECIES_POOCHYENA, 4
	wild_mon SPECIES_WINGULL, 2
	wild_mon SPECIES_ZIGZAGOON, 3
	wild_mon SPECIES_ZIGZAGOON, 3
	wild_mon SPECIES_ZIGZAGOON, 4
	wild_mon SPECIES_WINGULL, 3
	wild_mon SPECIES_WINGULL, 3
	wild_mon SPECIES_WINGULL, 2
	wild_mon SPECIES_WINGULL, 4

	.align 2
gRoute103_LandMonsInfo:: @ 85508D0
	.4byte 20 @ encounter rate
	.4byte gRoute103_LandMons

	.align 2
gRoute103_WaterMons:: @ 85508D8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute103_WaterMonsInfo:: @ 85508EC
	.4byte 4 @ encounter rate
	.4byte gRoute103_WaterMons

	.align 2
gRoute103_FishingMons:: @ 85508F4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute103_FishingMonsInfo:: @ 855091C
	.4byte 30 @ encounter rate
	.4byte gRoute103_FishingMons

	.align 2
gRoute104_LandMons:: @ 8550924
	wild_mon SPECIES_POOCHYENA, 4
	wild_mon SPECIES_WURMPLE, 4
	wild_mon SPECIES_POOCHYENA, 5
	wild_mon SPECIES_MARILL, 5
	wild_mon SPECIES_MARILL, 4
	wild_mon SPECIES_POOCHYENA, 5
	wild_mon SPECIES_TAILLOW, 4
	wild_mon SPECIES_TAILLOW, 5
	wild_mon SPECIES_WINGULL, 4
	wild_mon SPECIES_WINGULL, 4
	wild_mon SPECIES_WINGULL, 3
	wild_mon SPECIES_WINGULL, 5

	.align 2
gRoute104_LandMonsInfo:: @ 8550954
	.4byte 20 @ encounter rate
	.4byte gRoute104_LandMons

	.align 2
gRoute104_WaterMons:: @ 855095C
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute104_WaterMonsInfo:: @ 8550970
	.4byte 4 @ encounter rate
	.4byte gRoute104_WaterMons

	.align 2
gRoute104_FishingMons:: @ 8550978
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 25, 30
	wild_mon SPECIES_MAGIKARP, 30, 35
	wild_mon SPECIES_MAGIKARP, 20, 25
	wild_mon SPECIES_MAGIKARP, 35, 40
	wild_mon SPECIES_MAGIKARP, 40, 45

	.align 2
gRoute104_FishingMonsInfo:: @ 85509A0
	.4byte 30 @ encounter rate
	.4byte gRoute104_FishingMons

	.align 2
gRoute105_WaterMons:: @ 85509A8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute105_WaterMonsInfo:: @ 85509BC
	.4byte 4 @ encounter rate
	.4byte gRoute105_WaterMons

	.align 2
gRoute105_FishingMons:: @ 85509C4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute105_FishingMonsInfo:: @ 85509EC
	.4byte 30 @ encounter rate
	.4byte gRoute105_FishingMons

	.align 2
gRoute110_LandMons:: @ 85509F4
	wild_mon SPECIES_POOCHYENA, 12
	wild_mon SPECIES_ELECTRIKE, 12
	wild_mon SPECIES_GULPIN, 12
	wild_mon SPECIES_ELECTRIKE, 13
	wild_mon SPECIES_MINUN, 13
	wild_mon SPECIES_ODDISH, 13
	wild_mon SPECIES_MINUN, 13
	wild_mon SPECIES_GULPIN, 13
	wild_mon SPECIES_WINGULL, 12
	wild_mon SPECIES_WINGULL, 12
	wild_mon SPECIES_PLUSLE, 12
	wild_mon SPECIES_PLUSLE, 13

	.align 2
gRoute110_LandMonsInfo:: @ 8550A24
	.4byte 20 @ encounter rate
	.4byte gRoute110_LandMons

	.align 2
gRoute110_WaterMons:: @ 8550A2C
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute110_WaterMonsInfo:: @ 8550A40
	.4byte 4 @ encounter rate
	.4byte gRoute110_WaterMons

	.align 2
gRoute110_FishingMons:: @ 8550A48
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute110_FishingMonsInfo:: @ 8550A70
	.4byte 30 @ encounter rate
	.4byte gRoute110_FishingMons

	.align 2
gRoute111_LandMons:: @ 8550A78
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 21
	wild_mon SPECIES_TRAPINCH, 21
	wild_mon SPECIES_BALTOY, 19
	wild_mon SPECIES_BALTOY, 21
	wild_mon SPECIES_SANDSHREW, 19
	wild_mon SPECIES_TRAPINCH, 19
	wild_mon SPECIES_BALTOY, 20
	wild_mon SPECIES_CACNEA, 20
	wild_mon SPECIES_CACNEA, 22
	wild_mon SPECIES_CACNEA, 22

	.align 2
gRoute111_LandMonsInfo:: @ 8550AA8
	.4byte 10 @ encounter rate
	.4byte gRoute111_LandMons

	.align 2
gRoute111_WaterMons:: @ 8550AB0
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_GOLDEEN, 20, 30

	.align 2
gRoute111_WaterMonsInfo:: @ 8550AC4
	.4byte 4 @ encounter rate
	.4byte gRoute111_WaterMons

	.align 2
gRoute111_RockSmashMons:: @ 8550ACC
	wild_mon SPECIES_GEODUDE, 10, 15
	wild_mon SPECIES_GEODUDE, 5, 10
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 15, 20

	.align 2
gRoute111_RockSmashMonsInfo:: @ 8550AE0
	.4byte 20 @ encounter rate
	.4byte gRoute111_RockSmashMons

	.align 2
gRoute111_FishingMons:: @ 8550AE8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_BARBOACH, 20, 25
	wild_mon SPECIES_BARBOACH, 35, 40
	wild_mon SPECIES_BARBOACH, 40, 45

	.align 2
gRoute111_FishingMonsInfo:: @ 8550B10
	.4byte 30 @ encounter rate
	.4byte gRoute111_FishingMons

	.align 2
gRoute112_LandMons:: @ 8550B18
	wild_mon SPECIES_NUMEL, 15
	wild_mon SPECIES_NUMEL, 15
	wild_mon SPECIES_MARILL, 15
	wild_mon SPECIES_NUMEL, 14
	wild_mon SPECIES_NUMEL, 14
	wild_mon SPECIES_MARILL, 14
	wild_mon SPECIES_NUMEL, 16
	wild_mon SPECIES_MARILL, 16
	wild_mon SPECIES_NUMEL, 16
	wild_mon SPECIES_NUMEL, 16
	wild_mon SPECIES_NUMEL, 16
	wild_mon SPECIES_NUMEL, 16

	.align 2
gRoute112_LandMonsInfo:: @ 8550B48
	.4byte 20 @ encounter rate
	.4byte gRoute112_LandMons

	.align 2
gRoute113_LandMons:: @ 8550B50
	wild_mon SPECIES_SPINDA, 15
	wild_mon SPECIES_SPINDA, 15
	wild_mon SPECIES_SLUGMA, 15
	wild_mon SPECIES_SPINDA, 14
	wild_mon SPECIES_SPINDA, 14
	wild_mon SPECIES_SLUGMA, 14
	wild_mon SPECIES_SPINDA, 16
	wild_mon SPECIES_SLUGMA, 16
	wild_mon SPECIES_SPINDA, 16
	wild_mon SPECIES_SKARMORY, 16
	wild_mon SPECIES_SPINDA, 16
	wild_mon SPECIES_SKARMORY, 16

	.align 2
gRoute113_LandMonsInfo:: @ 8550B80
	.4byte 20 @ encounter rate
	.4byte gRoute113_LandMons

	.align 2
gRoute114_LandMons:: @ 8550B88
	wild_mon SPECIES_SWABLU, 16
	wild_mon SPECIES_LOTAD, 16
	wild_mon SPECIES_SWABLU, 17
	wild_mon SPECIES_SWABLU, 15
	wild_mon SPECIES_LOTAD, 15
	wild_mon SPECIES_LOMBRE, 16
	wild_mon SPECIES_LOMBRE, 16
	wild_mon SPECIES_LOMBRE, 18
	wild_mon SPECIES_SEVIPER, 17
	wild_mon SPECIES_SEVIPER, 15
	wild_mon SPECIES_SEVIPER, 17
	wild_mon SPECIES_NUZLEAF, 15

	.align 2
gRoute114_LandMonsInfo:: @ 8550BB8
	.4byte 20 @ encounter rate
	.4byte gRoute114_LandMons

	.align 2
gRoute114_WaterMons:: @ 8550BC0
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_GOLDEEN, 20, 30

	.align 2
gRoute114_WaterMonsInfo:: @ 8550BD4
	.4byte 4 @ encounter rate
	.4byte gRoute114_WaterMons

	.align 2
gRoute114_RockSmashMons:: @ 8550BDC
	wild_mon SPECIES_GEODUDE, 10, 15
	wild_mon SPECIES_GEODUDE, 5, 10
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 15, 20

	.align 2
gRoute114_RockSmashMonsInfo:: @ 8550BF0
	.4byte 20 @ encounter rate
	.4byte gRoute114_RockSmashMons

	.align 2
gRoute114_FishingMons:: @ 8550BF8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_BARBOACH, 20, 25
	wild_mon SPECIES_BARBOACH, 35, 40
	wild_mon SPECIES_BARBOACH, 40, 45

	.align 2
gRoute114_FishingMonsInfo:: @ 8550C20
	.4byte 30 @ encounter rate
	.4byte gRoute114_FishingMons

	.align 2
gRoute116_LandMons:: @ 8550C28
	wild_mon SPECIES_POOCHYENA, 6
	wild_mon SPECIES_WHISMUR, 6
	wild_mon SPECIES_NINCADA, 6
	wild_mon SPECIES_ABRA, 7
	wild_mon SPECIES_NINCADA, 7
	wild_mon SPECIES_TAILLOW, 6
	wild_mon SPECIES_TAILLOW, 7
	wild_mon SPECIES_TAILLOW, 8
	wild_mon SPECIES_POOCHYENA, 7
	wild_mon SPECIES_POOCHYENA, 8
	wild_mon SPECIES_SKITTY, 7
	wild_mon SPECIES_SKITTY, 8

	.align 2
gRoute116_LandMonsInfo:: @ 8550C58
	.4byte 20 @ encounter rate
	.4byte gRoute116_LandMons

	.align 2
gRoute117_LandMons:: @ 8550C60
	wild_mon SPECIES_POOCHYENA, 13
	wild_mon SPECIES_ODDISH, 13
	wild_mon SPECIES_POOCHYENA, 14
	wild_mon SPECIES_ODDISH, 14
	wild_mon SPECIES_MARILL, 13
	wild_mon SPECIES_ODDISH, 13
	wild_mon SPECIES_ILLUMISE, 13
	wild_mon SPECIES_ILLUMISE, 13
	wild_mon SPECIES_ILLUMISE, 14
	wild_mon SPECIES_ILLUMISE, 14
	wild_mon SPECIES_VOLBEAT, 13
	wild_mon SPECIES_SEEDOT, 13

	.align 2
gRoute117_LandMonsInfo:: @ 8550C90
	.4byte 20 @ encounter rate
	.4byte gRoute117_LandMons

	.align 2
gRoute117_WaterMons:: @ 8550C98
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_GOLDEEN, 20, 30

	.align 2
gRoute117_WaterMonsInfo:: @ 8550CAC
	.4byte 4 @ encounter rate
	.4byte gRoute117_WaterMons

	.align 2
gRoute117_FishingMons:: @ 8550CB4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_CORPHISH, 10, 30
	wild_mon SPECIES_CORPHISH, 25, 30
	wild_mon SPECIES_CORPHISH, 30, 35
	wild_mon SPECIES_CORPHISH, 20, 25
	wild_mon SPECIES_CORPHISH, 35, 40
	wild_mon SPECIES_CORPHISH, 40, 45

	.align 2
gRoute117_FishingMonsInfo:: @ 8550CDC
	.4byte 30 @ encounter rate
	.4byte gRoute117_FishingMons

	.align 2
gRoute118_LandMons:: @ 8550CE4
	wild_mon SPECIES_ZIGZAGOON, 24
	wild_mon SPECIES_ELECTRIKE, 24
	wild_mon SPECIES_ZIGZAGOON, 26
	wild_mon SPECIES_ELECTRIKE, 26
	wild_mon SPECIES_LINOONE, 26
	wild_mon SPECIES_MANECTRIC, 26
	wild_mon SPECIES_WINGULL, 25
	wild_mon SPECIES_WINGULL, 25
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 27
	wild_mon SPECIES_KECLEON, 25

	.align 2
gRoute118_LandMonsInfo:: @ 8550D14
	.4byte 20 @ encounter rate
	.4byte gRoute118_LandMons

	.align 2
gRoute118_WaterMons:: @ 8550D1C
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute118_WaterMonsInfo:: @ 8550D30
	.4byte 4 @ encounter rate
	.4byte gRoute118_WaterMons

	.align 2
gRoute118_FishingMons:: @ 8550D38
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_CARVANHA, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_CARVANHA, 30, 35
	wild_mon SPECIES_CARVANHA, 20, 25
	wild_mon SPECIES_CARVANHA, 35, 40
	wild_mon SPECIES_CARVANHA, 40, 45

	.align 2
gRoute118_FishingMonsInfo:: @ 8550D60
	.4byte 30 @ encounter rate
	.4byte gRoute118_FishingMons

	.align 2
gRoute124_WaterMons:: @ 8550D68
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute124_WaterMonsInfo:: @ 8550D7C
	.4byte 4 @ encounter rate
	.4byte gRoute124_WaterMons

	.align 2
gRoute124_FishingMons:: @ 8550D84
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute124_FishingMonsInfo:: @ 8550DAC
	.4byte 30 @ encounter rate
	.4byte gRoute124_FishingMons

	.align 2
gPetalburgWoods_LandMons:: @ 8550DB4
	wild_mon SPECIES_POOCHYENA, 5
	wild_mon SPECIES_WURMPLE, 5
	wild_mon SPECIES_SHROOMISH, 5
	wild_mon SPECIES_POOCHYENA, 6
	wild_mon SPECIES_SILCOON, 5
	wild_mon SPECIES_CASCOON, 5
	wild_mon SPECIES_WURMPLE, 6
	wild_mon SPECIES_SHROOMISH, 6
	wild_mon SPECIES_TAILLOW, 5
	wild_mon SPECIES_SLAKOTH, 5
	wild_mon SPECIES_TAILLOW, 6
	wild_mon SPECIES_SLAKOTH, 6

	.align 2
gPetalburgWoods_LandMonsInfo:: @ 8550DE4
	.4byte 20 @ encounter rate
	.4byte gPetalburgWoods_LandMons

	.align 2
gRusturfTunnel_LandMons:: @ 8550DEC
	wild_mon SPECIES_WHISMUR, 6
	wild_mon SPECIES_WHISMUR, 7
	wild_mon SPECIES_WHISMUR, 6
	wild_mon SPECIES_WHISMUR, 6
	wild_mon SPECIES_WHISMUR, 7
	wild_mon SPECIES_WHISMUR, 7
	wild_mon SPECIES_WHISMUR, 5
	wild_mon SPECIES_WHISMUR, 8
	wild_mon SPECIES_WHISMUR, 5
	wild_mon SPECIES_WHISMUR, 8
	wild_mon SPECIES_WHISMUR, 5
	wild_mon SPECIES_WHISMUR, 8

	.align 2
gRusturfTunnel_LandMonsInfo:: @ 8550E1C
	.4byte 10 @ encounter rate
	.4byte gRusturfTunnel_LandMons

	.align 2
gGraniteCave_1F_LandMons:: @ 8550E24
	wild_mon SPECIES_ZUBAT, 7
	wild_mon SPECIES_MAKUHITA, 8
	wild_mon SPECIES_MAKUHITA, 7
	wild_mon SPECIES_ZUBAT, 8
	wild_mon SPECIES_MAKUHITA, 9
	wild_mon SPECIES_ABRA, 8
	wild_mon SPECIES_MAKUHITA, 10
	wild_mon SPECIES_MAKUHITA, 6
	wild_mon SPECIES_GEODUDE, 7
	wild_mon SPECIES_GEODUDE, 8
	wild_mon SPECIES_GEODUDE, 6
	wild_mon SPECIES_GEODUDE, 9

	.align 2
gGraniteCave_1F_LandMonsInfo:: @ 8550E54
	.4byte 10 @ encounter rate
	.4byte gGraniteCave_1F_LandMons

	.align 2
gGraniteCave_B1F_LandMons:: @ 8550E5C
	wild_mon SPECIES_ZUBAT, 9
	wild_mon SPECIES_ARON, 10
	wild_mon SPECIES_ARON, 9
	wild_mon SPECIES_ARON, 11
	wild_mon SPECIES_ZUBAT, 10
	wild_mon SPECIES_ABRA, 9
	wild_mon SPECIES_MAKUHITA, 10
	wild_mon SPECIES_MAKUHITA, 11
	wild_mon SPECIES_SABLEYE, 10
	wild_mon SPECIES_SABLEYE, 10
	wild_mon SPECIES_SABLEYE, 9
	wild_mon SPECIES_SABLEYE, 11

	.align 2
gGraniteCave_B1F_LandMonsInfo:: @ 8550E8C
	.4byte 10 @ encounter rate
	.4byte gGraniteCave_B1F_LandMons

	.align 2
gMtPyre_1F_LandMons:: @ 8550E94
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24

	.align 2
gMtPyre_1F_LandMonsInfo:: @ 8550EC4
	.4byte 10 @ encounter rate
	.4byte gMtPyre_1F_LandMons

	.align 2
gVictoryRoad_1F_LandMons:: @ 8550ECC
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_HARIYAMA, 40
	wild_mon SPECIES_LAIRON, 40
	wild_mon SPECIES_LOUDRED, 40
	wild_mon SPECIES_ZUBAT, 36
	wild_mon SPECIES_MAKUHITA, 36
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_HARIYAMA, 38
	wild_mon SPECIES_ARON, 36
	wild_mon SPECIES_WHISMUR, 36
	wild_mon SPECIES_ARON, 36
	wild_mon SPECIES_WHISMUR, 36

	.align 2
gVictoryRoad_1F_LandMonsInfo:: @ 8550EFC
	.4byte 10 @ encounter rate
	.4byte gVictoryRoad_1F_LandMons

	.align 2
gSafariZone_South_LandMons:: @ 8550F04
	wild_mon SPECIES_ODDISH, 25
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_GIRAFARIG, 25
	wild_mon SPECIES_GIRAFARIG, 27
	wild_mon SPECIES_NATU, 25
	wild_mon SPECIES_DODUO, 25
	wild_mon SPECIES_GLOOM, 25
	wild_mon SPECIES_WOBBUFFET, 27
	wild_mon SPECIES_PIKACHU, 25
	wild_mon SPECIES_WOBBUFFET, 27
	wild_mon SPECIES_PIKACHU, 27
	wild_mon SPECIES_WOBBUFFET, 29

	.align 2
gSafariZone_South_LandMonsInfo:: @ 8550F34
	.4byte 25 @ encounter rate
	.4byte gSafariZone_South_LandMons

	.align 2
gUnderwater2_WaterMons:: @ 8550F3C
	wild_mon SPECIES_CLAMPERL, 20, 30
	wild_mon SPECIES_CHINCHOU, 20, 30
	wild_mon SPECIES_CLAMPERL, 30, 35
	wild_mon SPECIES_RELICANTH, 30, 35
	wild_mon SPECIES_RELICANTH, 30, 35

	.align 2
gUnderwater2_WaterMonsInfo:: @ 8550F50
	.4byte 4 @ encounter rate
	.4byte gUnderwater2_WaterMons

	.align 2
gAbandonedShip_Rooms_B1F_WaterMons:: @ 8550F58
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACRUEL, 30, 35

	.align 2
gAbandonedShip_Rooms_B1F_WaterMonsInfo:: @ 8550F6C
	.4byte 4 @ encounter rate
	.4byte gAbandonedShip_Rooms_B1F_WaterMons

	.align 2
gAbandonedShip_Rooms_B1F_FishingMons:: @ 8550F74
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_TENTACOOL, 25, 30
	wild_mon SPECIES_TENTACOOL, 30, 35
	wild_mon SPECIES_TENTACRUEL, 30, 35
	wild_mon SPECIES_TENTACRUEL, 25, 30
	wild_mon SPECIES_TENTACRUEL, 20, 25

	.align 2
gAbandonedShip_Rooms_B1F_FishingMonsInfo:: @ 8550F9C
	.4byte 20 @ encounter rate
	.4byte gAbandonedShip_Rooms_B1F_FishingMons

	.align 2
gGraniteCave_B2F_LandMons:: @ 8550FA4
	wild_mon SPECIES_ZUBAT, 10
	wild_mon SPECIES_ARON, 11
	wild_mon SPECIES_ARON, 10
	wild_mon SPECIES_ZUBAT, 11
	wild_mon SPECIES_ARON, 12
	wild_mon SPECIES_ABRA, 10
	wild_mon SPECIES_SABLEYE, 10
	wild_mon SPECIES_SABLEYE, 11
	wild_mon SPECIES_SABLEYE, 12
	wild_mon SPECIES_SABLEYE, 10
	wild_mon SPECIES_SABLEYE, 12
	wild_mon SPECIES_SABLEYE, 10

	.align 2
gGraniteCave_B2F_LandMonsInfo:: @ 8550FD4
	.4byte 10 @ encounter rate
	.4byte gGraniteCave_B2F_LandMons

	.align 2
gGraniteCave_B2F_RockSmashMons:: @ 8550FDC
	wild_mon SPECIES_GEODUDE, 10, 15
	wild_mon SPECIES_NOSEPASS, 10, 20
	wild_mon SPECIES_GEODUDE, 5, 10
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 15, 20

	.align 2
gGraniteCave_B2F_RockSmashMonsInfo:: @ 8550FF0
	.4byte 20 @ encounter rate
	.4byte gGraniteCave_B2F_RockSmashMons

	.align 2
gFieryPath_LandMons:: @ 8550FF8
	wild_mon SPECIES_NUMEL, 15
	wild_mon SPECIES_KOFFING, 15
	wild_mon SPECIES_NUMEL, 16
	wild_mon SPECIES_MACHOP, 15
	wild_mon SPECIES_TORKOAL, 15
	wild_mon SPECIES_SLUGMA, 15
	wild_mon SPECIES_KOFFING, 16
	wild_mon SPECIES_MACHOP, 16
	wild_mon SPECIES_TORKOAL, 14
	wild_mon SPECIES_TORKOAL, 16
	wild_mon SPECIES_GRIMER, 14
	wild_mon SPECIES_GRIMER, 14

	.align 2
gFieryPath_LandMonsInfo:: @ 8551028
	.4byte 10 @ encounter rate
	.4byte gFieryPath_LandMons

	.align 2
gMeteorFalls_B1F_2R_LandMons:: @ 8551030
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_BAGON, 30
	wild_mon SPECIES_SOLROCK, 35
	wild_mon SPECIES_BAGON, 35
	wild_mon SPECIES_SOLROCK, 37
	wild_mon SPECIES_BAGON, 25
	wild_mon SPECIES_SOLROCK, 39
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40

	.align 2
gMeteorFalls_B1F_2R_LandMonsInfo:: @ 8551060
	.4byte 10 @ encounter rate
	.4byte gMeteorFalls_B1F_2R_LandMons

	.align 2
gMeteorFalls_B1F_2R_WaterMons:: @ 8551068
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_SOLROCK, 25, 35
	wild_mon SPECIES_SOLROCK, 15, 25
	wild_mon SPECIES_SOLROCK, 5, 15

	.align 2
gMeteorFalls_B1F_2R_WaterMonsInfo:: @ 855107C
	.4byte 4 @ encounter rate
	.4byte gMeteorFalls_B1F_2R_WaterMons

	.align 2
gMeteorFalls_B1F_2R_FishingMons:: @ 8551084
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_WHISCASH, 30, 35
	wild_mon SPECIES_WHISCASH, 35, 40
	wild_mon SPECIES_WHISCASH, 40, 45

	.align 2
gMeteorFalls_B1F_2R_FishingMonsInfo:: @ 85510AC
	.4byte 30 @ encounter rate
	.4byte gMeteorFalls_B1F_2R_FishingMons

	.align 2
gJaggedPass_LandMons:: @ 85510B4
	wild_mon SPECIES_NUMEL, 21
	wild_mon SPECIES_NUMEL, 21
	wild_mon SPECIES_MACHOP, 21
	wild_mon SPECIES_NUMEL, 20
	wild_mon SPECIES_SPOINK, 20
	wild_mon SPECIES_MACHOP, 20
	wild_mon SPECIES_SPOINK, 21
	wild_mon SPECIES_MACHOP, 22
	wild_mon SPECIES_NUMEL, 22
	wild_mon SPECIES_SPOINK, 22
	wild_mon SPECIES_NUMEL, 22
	wild_mon SPECIES_SPOINK, 22

	.align 2
gJaggedPass_LandMonsInfo:: @ 85510E4
	.4byte 20 @ encounter rate
	.4byte gJaggedPass_LandMons

	.align 2
gRoute106_WaterMons:: @ 85510EC
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute106_WaterMonsInfo:: @ 8551100
	.4byte 4 @ encounter rate
	.4byte gRoute106_WaterMons

	.align 2
gRoute106_FishingMons:: @ 8551108
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute106_FishingMonsInfo:: @ 8551130
	.4byte 30 @ encounter rate
	.4byte gRoute106_FishingMons

	.align 2
gRoute107_WaterMons:: @ 8551138
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute107_WaterMonsInfo:: @ 855114C
	.4byte 4 @ encounter rate
	.4byte gRoute107_WaterMons

	.align 2
gRoute107_FishingMons:: @ 8551154
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute107_FishingMonsInfo:: @ 855117C
	.4byte 30 @ encounter rate
	.4byte gRoute107_FishingMons

	.align 2
gRoute108_WaterMons:: @ 8551184
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute108_WaterMonsInfo:: @ 8551198
	.4byte 4 @ encounter rate
	.4byte gRoute108_WaterMons

	.align 2
gRoute108_FishingMons:: @ 85511A0
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute108_FishingMonsInfo:: @ 85511C8
	.4byte 30 @ encounter rate
	.4byte gRoute108_FishingMons

	.align 2
gRoute109_WaterMons:: @ 85511D0
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute109_WaterMonsInfo:: @ 85511E4
	.4byte 4 @ encounter rate
	.4byte gRoute109_WaterMons

	.align 2
gRoute109_FishingMons:: @ 85511EC
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute109_FishingMonsInfo:: @ 8551214
	.4byte 30 @ encounter rate
	.4byte gRoute109_FishingMons

	.align 2
gRoute115_LandMons:: @ 855121C
	wild_mon SPECIES_SWABLU, 23
	wild_mon SPECIES_TAILLOW, 23
	wild_mon SPECIES_SWABLU, 25
	wild_mon SPECIES_TAILLOW, 24
	wild_mon SPECIES_TAILLOW, 25
	wild_mon SPECIES_SWELLOW, 25
	wild_mon SPECIES_JIGGLYPUFF, 24
	wild_mon SPECIES_JIGGLYPUFF, 25
	wild_mon SPECIES_WINGULL, 24
	wild_mon SPECIES_WINGULL, 24
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 25

	.align 2
gRoute115_LandMonsInfo:: @ 855124C
	.4byte 20 @ encounter rate
	.4byte gRoute115_LandMons

	.align 2
gRoute115_WaterMons:: @ 8551254
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute115_WaterMonsInfo:: @ 8551268
	.4byte 4 @ encounter rate
	.4byte gRoute115_WaterMons

	.align 2
gRoute115_FishingMons:: @ 8551270
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute115_FishingMonsInfo:: @ 8551298
	.4byte 30 @ encounter rate
	.4byte gRoute115_FishingMons

	.align 2
gNewMauville_Inside_LandMons:: @ 85512A0
	wild_mon SPECIES_VOLTORB, 24
	wild_mon SPECIES_MAGNEMITE, 24
	wild_mon SPECIES_VOLTORB, 25
	wild_mon SPECIES_MAGNEMITE, 25
	wild_mon SPECIES_VOLTORB, 23
	wild_mon SPECIES_MAGNEMITE, 23
	wild_mon SPECIES_VOLTORB, 26
	wild_mon SPECIES_MAGNEMITE, 26
	wild_mon SPECIES_VOLTORB, 22
	wild_mon SPECIES_MAGNEMITE, 22
	wild_mon SPECIES_ELECTRODE, 26
	wild_mon SPECIES_MAGNETON, 26

	.align 2
gNewMauville_Inside_LandMonsInfo:: @ 85512D0
	.4byte 10 @ encounter rate
	.4byte gNewMauville_Inside_LandMons

	.align 2
gRoute119_LandMons:: @ 85512D8
	wild_mon SPECIES_ZIGZAGOON, 25
	wild_mon SPECIES_LINOONE, 25
	wild_mon SPECIES_ZIGZAGOON, 27
	wild_mon SPECIES_ODDISH, 25
	wild_mon SPECIES_LINOONE, 27
	wild_mon SPECIES_ODDISH, 26
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_ODDISH, 24
	wild_mon SPECIES_TROPIUS, 25
	wild_mon SPECIES_TROPIUS, 26
	wild_mon SPECIES_TROPIUS, 27
	wild_mon SPECIES_KECLEON, 25

	.align 2
gRoute119_LandMonsInfo:: @ 8551308
	.4byte 15 @ encounter rate
	.4byte gRoute119_LandMons

	.align 2
gRoute119_WaterMons:: @ 8551310
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute119_WaterMonsInfo:: @ 8551324
	.4byte 4 @ encounter rate
	.4byte gRoute119_WaterMons

	.align 2
gRoute119_FishingMons:: @ 855132C
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_CARVANHA, 10, 30
	wild_mon SPECIES_CARVANHA, 25, 30
	wild_mon SPECIES_CARVANHA, 30, 35
	wild_mon SPECIES_CARVANHA, 20, 25
	wild_mon SPECIES_CARVANHA, 35, 40
	wild_mon SPECIES_CARVANHA, 40, 45

	.align 2
gRoute119_FishingMonsInfo:: @ 8551354
	.4byte 30 @ encounter rate
	.4byte gRoute119_FishingMons

	.align 2
gRoute120_LandMons:: @ 855135C
	wild_mon SPECIES_POOCHYENA, 25
	wild_mon SPECIES_MIGHTYENA, 25
	wild_mon SPECIES_MIGHTYENA, 27
	wild_mon SPECIES_ODDISH, 25
	wild_mon SPECIES_MARILL, 25
	wild_mon SPECIES_ODDISH, 26
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_MARILL, 27
	wild_mon SPECIES_ABSOL, 25
	wild_mon SPECIES_ABSOL, 27
	wild_mon SPECIES_KECLEON, 25
	wild_mon SPECIES_SEEDOT, 25

	.align 2
gRoute120_LandMonsInfo:: @ 855138C
	.4byte 20 @ encounter rate
	.4byte gRoute120_LandMons

	.align 2
gRoute120_WaterMons:: @ 8551394
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_GOLDEEN, 20, 30

	.align 2
gRoute120_WaterMonsInfo:: @ 85513A8
	.4byte 4 @ encounter rate
	.4byte gRoute120_WaterMons

	.align 2
gRoute120_FishingMons:: @ 85513B0
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_BARBOACH, 20, 25
	wild_mon SPECIES_BARBOACH, 35, 40
	wild_mon SPECIES_BARBOACH, 40, 45

	.align 2
gRoute120_FishingMonsInfo:: @ 85513D8
	.4byte 30 @ encounter rate
	.4byte gRoute120_FishingMons

	.align 2
gRoute121_LandMons:: @ 85513E0
	wild_mon SPECIES_POOCHYENA, 26
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_MIGHTYENA, 26
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_MIGHTYENA, 28
	wild_mon SPECIES_ODDISH, 26
	wild_mon SPECIES_ODDISH, 28
	wild_mon SPECIES_GLOOM, 28
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 27
	wild_mon SPECIES_WINGULL, 28
	wild_mon SPECIES_KECLEON, 25

	.align 2
gRoute121_LandMonsInfo:: @ 8551410
	.4byte 20 @ encounter rate
	.4byte gRoute121_LandMons

	.align 2
gRoute121_WaterMons:: @ 8551418
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute121_WaterMonsInfo:: @ 855142C
	.4byte 4 @ encounter rate
	.4byte gRoute121_WaterMons

	.align 2
gRoute121_FishingMons:: @ 8551434
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute121_FishingMonsInfo:: @ 855145C
	.4byte 30 @ encounter rate
	.4byte gRoute121_FishingMons

	.align 2
gRoute122_WaterMons:: @ 8551464
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute122_WaterMonsInfo:: @ 8551478
	.4byte 4 @ encounter rate
	.4byte gRoute122_WaterMons

	.align 2
gRoute122_FishingMons:: @ 8551480
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute122_FishingMonsInfo:: @ 85514A8
	.4byte 30 @ encounter rate
	.4byte gRoute122_FishingMons

	.align 2
gRoute123_LandMons:: @ 85514B0
	wild_mon SPECIES_POOCHYENA, 26
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_MIGHTYENA, 26
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_MIGHTYENA, 28
	wild_mon SPECIES_ODDISH, 26
	wild_mon SPECIES_ODDISH, 28
	wild_mon SPECIES_GLOOM, 28
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 27
	wild_mon SPECIES_WINGULL, 28
	wild_mon SPECIES_KECLEON, 25

	.align 2
gRoute123_LandMonsInfo:: @ 85514E0
	.4byte 20 @ encounter rate
	.4byte gRoute123_LandMons

	.align 2
gRoute123_WaterMons:: @ 85514E8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute123_WaterMonsInfo:: @ 85514FC
	.4byte 4 @ encounter rate
	.4byte gRoute123_WaterMons

	.align 2
gRoute123_FishingMons:: @ 8551504
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute123_FishingMonsInfo:: @ 855152C
	.4byte 30 @ encounter rate
	.4byte gRoute123_FishingMons

	.align 2
gMtPyre_2F_LandMons:: @ 8551534
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24

	.align 2
gMtPyre_2F_LandMonsInfo:: @ 8551564
	.4byte 10 @ encounter rate
	.4byte gMtPyre_2F_LandMons

	.align 2
gMtPyre_3F_LandMons:: @ 855156C
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24

	.align 2
gMtPyre_3F_LandMonsInfo:: @ 855159C
	.4byte 10 @ encounter rate
	.4byte gMtPyre_3F_LandMons

	.align 2
gMtPyre_4F_LandMons:: @ 85515A4
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 25
	wild_mon SPECIES_DUSKULL, 29

	.align 2
gMtPyre_4F_LandMonsInfo:: @ 85515D4
	.4byte 10 @ encounter rate
	.4byte gMtPyre_4F_LandMons

	.align 2
gMtPyre_5F_LandMons:: @ 85515DC
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 25
	wild_mon SPECIES_DUSKULL, 29

	.align 2
gMtPyre_5F_LandMonsInfo:: @ 855160C
	.4byte 10 @ encounter rate
	.4byte gMtPyre_5F_LandMons

	.align 2
gMtPyre_6F_LandMons:: @ 8551614
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_SHUPPET, 23
	wild_mon SPECIES_SHUPPET, 22
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 27
	wild_mon SPECIES_DUSKULL, 25
	wild_mon SPECIES_DUSKULL, 29

	.align 2
gMtPyre_6F_LandMonsInfo:: @ 8551644
	.4byte 10 @ encounter rate
	.4byte gMtPyre_6F_LandMons

	.align 2
gMtPyre_Exterior_LandMons:: @ 855164C
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_VULPIX, 29
	wild_mon SPECIES_VULPIX, 27
	wild_mon SPECIES_VULPIX, 29
	wild_mon SPECIES_VULPIX, 25
	wild_mon SPECIES_WINGULL, 27
	wild_mon SPECIES_WINGULL, 27
	wild_mon SPECIES_WINGULL, 26
	wild_mon SPECIES_WINGULL, 28

	.align 2
gMtPyre_Exterior_LandMonsInfo:: @ 855167C
	.4byte 10 @ encounter rate
	.4byte gMtPyre_Exterior_LandMons

	.align 2
gMtPyre_Summit_LandMons:: @ 8551684
	wild_mon SPECIES_SHUPPET, 28
	wild_mon SPECIES_SHUPPET, 29
	wild_mon SPECIES_SHUPPET, 27
	wild_mon SPECIES_SHUPPET, 26
	wild_mon SPECIES_SHUPPET, 30
	wild_mon SPECIES_SHUPPET, 25
	wild_mon SPECIES_SHUPPET, 24
	wild_mon SPECIES_DUSKULL, 28
	wild_mon SPECIES_DUSKULL, 26
	wild_mon SPECIES_DUSKULL, 30
	wild_mon SPECIES_CHIMECHO, 28
	wild_mon SPECIES_CHIMECHO, 28

	.align 2
gMtPyre_Summit_LandMonsInfo:: @ 85516B4
	.4byte 10 @ encounter rate
	.4byte gMtPyre_Summit_LandMons

	.align 2
gGraniteCave_StevensRoom_LandMons:: @ 85516BC
	wild_mon SPECIES_ZUBAT, 7
	wild_mon SPECIES_MAKUHITA, 8
	wild_mon SPECIES_MAKUHITA, 7
	wild_mon SPECIES_ZUBAT, 8
	wild_mon SPECIES_MAKUHITA, 9
	wild_mon SPECIES_ABRA, 8
	wild_mon SPECIES_MAKUHITA, 10
	wild_mon SPECIES_MAKUHITA, 6
	wild_mon SPECIES_ARON, 7
	wild_mon SPECIES_ARON, 8
	wild_mon SPECIES_ARON, 7
	wild_mon SPECIES_ARON, 8

	.align 2
gGraniteCave_StevensRoom_LandMonsInfo:: @ 85516EC
	.4byte 10 @ encounter rate
	.4byte gGraniteCave_StevensRoom_LandMons

	.align 2
gRoute125_WaterMons:: @ 85516F4
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute125_WaterMonsInfo:: @ 8551708
	.4byte 4 @ encounter rate
	.4byte gRoute125_WaterMons

	.align 2
gRoute125_FishingMons:: @ 8551710
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute125_FishingMonsInfo:: @ 8551738
	.4byte 30 @ encounter rate
	.4byte gRoute125_FishingMons

	.align 2
gRoute126_WaterMons:: @ 8551740
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute126_WaterMonsInfo:: @ 8551754
	.4byte 4 @ encounter rate
	.4byte gRoute126_WaterMons

	.align 2
gRoute126_FishingMons:: @ 855175C
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute126_FishingMonsInfo:: @ 8551784
	.4byte 30 @ encounter rate
	.4byte gRoute126_FishingMons

	.align 2
gRoute127_WaterMons:: @ 855178C
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute127_WaterMonsInfo:: @ 85517A0
	.4byte 4 @ encounter rate
	.4byte gRoute127_WaterMons

	.align 2
gRoute127_FishingMons:: @ 85517A8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute127_FishingMonsInfo:: @ 85517D0
	.4byte 30 @ encounter rate
	.4byte gRoute127_FishingMons

	.align 2
gRoute128_WaterMons:: @ 85517D8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute128_WaterMonsInfo:: @ 85517EC
	.4byte 4 @ encounter rate
	.4byte gRoute128_WaterMons

	.align 2
gRoute128_FishingMons:: @ 85517F4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_LUVDISC, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_LUVDISC, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_CORSOLA, 30, 35
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute128_FishingMonsInfo:: @ 855181C
	.4byte 30 @ encounter rate
	.4byte gRoute128_FishingMons

	.align 2
gRoute129_WaterMons:: @ 8551824
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_WAILORD, 25, 30

	.align 2
gRoute129_WaterMonsInfo:: @ 8551838
	.4byte 4 @ encounter rate
	.4byte gRoute129_WaterMons

	.align 2
gRoute129_FishingMons:: @ 8551840
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute129_FishingMonsInfo:: @ 8551868
	.4byte 30 @ encounter rate
	.4byte gRoute129_FishingMons

	.align 2
gRoute130_LandMons:: @ 8551870
	wild_mon SPECIES_WYNAUT, 30
	wild_mon SPECIES_WYNAUT, 35
	wild_mon SPECIES_WYNAUT, 25
	wild_mon SPECIES_WYNAUT, 40
	wild_mon SPECIES_WYNAUT, 20
	wild_mon SPECIES_WYNAUT, 45
	wild_mon SPECIES_WYNAUT, 15
	wild_mon SPECIES_WYNAUT, 50
	wild_mon SPECIES_WYNAUT, 10
	wild_mon SPECIES_WYNAUT, 5
	wild_mon SPECIES_WYNAUT, 10
	wild_mon SPECIES_WYNAUT, 5

	.align 2
gRoute130_LandMonsInfo:: @ 85518A0
	.4byte 20 @ encounter rate
	.4byte gRoute130_LandMons

	.align 2
gRoute130_WaterMons:: @ 85518A8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute130_WaterMonsInfo:: @ 85518BC
	.4byte 4 @ encounter rate
	.4byte gRoute130_WaterMons

	.align 2
gRoute130_FishingMons:: @ 85518C4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute130_FishingMonsInfo:: @ 85518EC
	.4byte 30 @ encounter rate
	.4byte gRoute130_FishingMons

	.align 2
gRoute131_WaterMons:: @ 85518F4
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute131_WaterMonsInfo:: @ 8551908
	.4byte 4 @ encounter rate
	.4byte gRoute131_WaterMons

	.align 2
gRoute131_FishingMons:: @ 8551910
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute131_FishingMonsInfo:: @ 8551938
	.4byte 30 @ encounter rate
	.4byte gRoute131_FishingMons

	.align 2
gRoute132_WaterMons:: @ 8551940
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute132_WaterMonsInfo:: @ 8551954
	.4byte 4 @ encounter rate
	.4byte gRoute132_WaterMons

	.align 2
gRoute132_FishingMons:: @ 855195C
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_HORSEA, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute132_FishingMonsInfo:: @ 8551984
	.4byte 30 @ encounter rate
	.4byte gRoute132_FishingMons

	.align 2
gRoute133_WaterMons:: @ 855198C
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute133_WaterMonsInfo:: @ 85519A0
	.4byte 4 @ encounter rate
	.4byte gRoute133_WaterMons

	.align 2
gRoute133_FishingMons:: @ 85519A8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_HORSEA, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute133_FishingMonsInfo:: @ 85519D0
	.4byte 30 @ encounter rate
	.4byte gRoute133_FishingMons

	.align 2
gRoute134_WaterMons:: @ 85519D8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gRoute134_WaterMonsInfo:: @ 85519EC
	.4byte 4 @ encounter rate
	.4byte gRoute134_WaterMons

	.align 2
gRoute134_FishingMons:: @ 85519F4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_HORSEA, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gRoute134_FishingMonsInfo:: @ 8551A1C
	.4byte 30 @ encounter rate
	.4byte gRoute134_FishingMons

	.align 2
gAbandonedShip_HiddenFloorCorridors_WaterMons:: @ 8551A24
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_TENTACRUEL, 30, 35

	.align 2
gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo:: @ 8551A38
	.4byte 4 @ encounter rate
	.4byte gAbandonedShip_HiddenFloorCorridors_WaterMons

	.align 2
gAbandonedShip_HiddenFloorCorridors_FishingMons:: @ 8551A40
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_TENTACOOL, 25, 30
	wild_mon SPECIES_TENTACOOL, 30, 35
	wild_mon SPECIES_TENTACRUEL, 30, 35
	wild_mon SPECIES_TENTACRUEL, 25, 30
	wild_mon SPECIES_TENTACRUEL, 20, 25

	.align 2
gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo:: @ 8551A68
	.4byte 20 @ encounter rate
	.4byte gAbandonedShip_HiddenFloorCorridors_FishingMons

	.align 2
gSeafloorCavern_Room1_LandMons:: @ 8551A70
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room1_LandMonsInfo:: @ 8551AA0
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room1_LandMons

	.align 2
gSeafloorCavern_Room2_LandMons:: @ 8551AA8
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room2_LandMonsInfo:: @ 8551AD8
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room2_LandMons

	.align 2
gSeafloorCavern_Room3_LandMons:: @ 8551AE0
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room3_LandMonsInfo:: @ 8551B10
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room3_LandMons

	.align 2
gSeafloorCavern_Room4_LandMons:: @ 8551B18
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room4_LandMonsInfo:: @ 8551B48
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room4_LandMons

	.align 2
gSeafloorCavern_Room5_LandMons:: @ 8551B50
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room5_LandMonsInfo:: @ 8551B80
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room5_LandMons

	.align 2
gSeafloorCavern_Room6_LandMons:: @ 8551B88
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room6_LandMonsInfo:: @ 8551BB8
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room6_LandMons

	.align 2
gSeafloorCavern_Room6_WaterMons:: @ 8551BC0
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_ZUBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35

	.align 2
gSeafloorCavern_Room6_WaterMonsInfo:: @ 8551BD4
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room6_WaterMons

	.align 2
gSeafloorCavern_Room6_FishingMons:: @ 8551BDC
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gSeafloorCavern_Room6_FishingMonsInfo:: @ 8551C04
	.4byte 10 @ encounter rate
	.4byte gSeafloorCavern_Room6_FishingMons

	.align 2
gSeafloorCavern_Room7_LandMons:: @ 8551C0C
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room7_LandMonsInfo:: @ 8551C3C
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room7_LandMons

	.align 2
gSeafloorCavern_Room7_WaterMons:: @ 8551C44
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_ZUBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35

	.align 2
gSeafloorCavern_Room7_WaterMonsInfo:: @ 8551C58
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room7_WaterMons

	.align 2
gSeafloorCavern_Room7_FishingMons:: @ 8551C60
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gSeafloorCavern_Room7_FishingMonsInfo:: @ 8551C88
	.4byte 10 @ encounter rate
	.4byte gSeafloorCavern_Room7_FishingMons

	.align 2
gSeafloorCavern_Room8_LandMons:: @ 8551C90
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gSeafloorCavern_Room8_LandMonsInfo:: @ 8551CC0
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Room8_LandMons

	.align 2
gSeafloorCavern_Entrance_WaterMons:: @ 8551CC8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_ZUBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35

	.align 2
gSeafloorCavern_Entrance_WaterMonsInfo:: @ 8551CDC
	.4byte 4 @ encounter rate
	.4byte gSeafloorCavern_Entrance_WaterMons

	.align 2
gSeafloorCavern_Entrance_FishingMons:: @ 8551CE4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gSeafloorCavern_Entrance_FishingMonsInfo:: @ 8551D0C
	.4byte 10 @ encounter rate
	.4byte gSeafloorCavern_Entrance_FishingMons

	.align 2
gCaveOfOrigin_Entrance_LandMons:: @ 8551D14
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_ZUBAT, 29
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_ZUBAT, 35
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gCaveOfOrigin_Entrance_LandMonsInfo:: @ 8551D44
	.4byte 4 @ encounter rate
	.4byte gCaveOfOrigin_Entrance_LandMons

	.align 2
gCaveOfOrigin_1F_LandMons:: @ 8551D4C
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SABLEYE, 30
	wild_mon SPECIES_SABLEYE, 32
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gCaveOfOrigin_1F_LandMonsInfo:: @ 8551D7C
	.4byte 4 @ encounter rate
	.4byte gCaveOfOrigin_1F_LandMons

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap1_LandMons:: @ 8551D84
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SABLEYE, 30
	wild_mon SPECIES_SABLEYE, 32
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo:: @ 8551DB4
	.4byte 4 @ encounter rate
	.4byte gCaveOfOrigin_UnusedRubySapphireMap1_LandMons

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap2_LandMons:: @ 8551DBC
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SABLEYE, 30
	wild_mon SPECIES_SABLEYE, 32
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo:: @ 8551DEC
	.4byte 4 @ encounter rate
	.4byte gCaveOfOrigin_UnusedRubySapphireMap2_LandMons

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap3_LandMons:: @ 8551DF4
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_ZUBAT, 31
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SABLEYE, 30
	wild_mon SPECIES_SABLEYE, 32
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_ZUBAT, 33
	wild_mon SPECIES_ZUBAT, 34
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 36

	.align 2
gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo:: @ 8551E24
	.4byte 4 @ encounter rate
	.4byte gCaveOfOrigin_UnusedRubySapphireMap3_LandMons

	.align 2
gNewMauville_Entrance_LandMons:: @ 8551E2C
	wild_mon SPECIES_VOLTORB, 24
	wild_mon SPECIES_MAGNEMITE, 24
	wild_mon SPECIES_VOLTORB, 25
	wild_mon SPECIES_MAGNEMITE, 25
	wild_mon SPECIES_VOLTORB, 23
	wild_mon SPECIES_MAGNEMITE, 23
	wild_mon SPECIES_VOLTORB, 26
	wild_mon SPECIES_MAGNEMITE, 26
	wild_mon SPECIES_VOLTORB, 22
	wild_mon SPECIES_MAGNEMITE, 22
	wild_mon SPECIES_VOLTORB, 22
	wild_mon SPECIES_MAGNEMITE, 22

	.align 2
gNewMauville_Entrance_LandMonsInfo:: @ 8551E5C
	.4byte 10 @ encounter rate
	.4byte gNewMauville_Entrance_LandMons

	.align 2
gSafariZone_Southwest_LandMons:: @ 8551E64
	wild_mon SPECIES_ODDISH, 25
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_GIRAFARIG, 25
	wild_mon SPECIES_GIRAFARIG, 27
	wild_mon SPECIES_NATU, 25
	wild_mon SPECIES_DODUO, 27
	wild_mon SPECIES_GLOOM, 25
	wild_mon SPECIES_WOBBUFFET, 27
	wild_mon SPECIES_PIKACHU, 25
	wild_mon SPECIES_WOBBUFFET, 27
	wild_mon SPECIES_PIKACHU, 27
	wild_mon SPECIES_WOBBUFFET, 29

	.align 2
gSafariZone_Southwest_LandMonsInfo:: @ 8551E94
	.4byte 25 @ encounter rate
	.4byte gSafariZone_Southwest_LandMons

	.align 2
gSafariZone_Southwest_WaterMons:: @ 8551E9C
	wild_mon SPECIES_PSYDUCK, 20, 30
	wild_mon SPECIES_PSYDUCK, 20, 30
	wild_mon SPECIES_PSYDUCK, 30, 35
	wild_mon SPECIES_PSYDUCK, 30, 35
	wild_mon SPECIES_PSYDUCK, 30, 35

	.align 2
gSafariZone_Southwest_WaterMonsInfo:: @ 8551EB0
	.4byte 9 @ encounter rate
	.4byte gSafariZone_Southwest_WaterMons

	.align 2
gSafariZone_Southwest_FishingMons:: @ 8551EB8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 25
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_GOLDEEN, 25, 30
	wild_mon SPECIES_GOLDEEN, 30, 35
	wild_mon SPECIES_SEAKING, 30, 35
	wild_mon SPECIES_SEAKING, 35, 40
	wild_mon SPECIES_SEAKING, 25, 30

	.align 2
gSafariZone_Southwest_FishingMonsInfo:: @ 8551EE0
	.4byte 35 @ encounter rate
	.4byte gSafariZone_Southwest_FishingMons

	.align 2
gSafariZone_North_LandMons:: @ 8551EE8
	wild_mon SPECIES_PHANPY, 27
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_PHANPY, 29
	wild_mon SPECIES_ODDISH, 29
	wild_mon SPECIES_NATU, 27
	wild_mon SPECIES_GLOOM, 29
	wild_mon SPECIES_GLOOM, 31
	wild_mon SPECIES_NATU, 29
	wild_mon SPECIES_XATU, 29
	wild_mon SPECIES_HERACROSS, 27
	wild_mon SPECIES_XATU, 31
	wild_mon SPECIES_HERACROSS, 29

	.align 2
gSafariZone_North_LandMonsInfo:: @ 8551F18
	.4byte 25 @ encounter rate
	.4byte gSafariZone_North_LandMons

	.align 2
gSafariZone_North_RockSmashMons:: @ 8551F20
	wild_mon SPECIES_GEODUDE, 10, 15
	wild_mon SPECIES_GEODUDE, 5, 10
	wild_mon SPECIES_GEODUDE, 15, 20
	wild_mon SPECIES_GEODUDE, 20, 25
	wild_mon SPECIES_GEODUDE, 25, 30

	.align 2
gSafariZone_North_RockSmashMonsInfo:: @ 8551F34
	.4byte 25 @ encounter rate
	.4byte gSafariZone_North_RockSmashMons

	.align 2
gSafariZone_Northwest_LandMons:: @ 8551F3C
	wild_mon SPECIES_RHYHORN, 27
	wild_mon SPECIES_ODDISH, 27
	wild_mon SPECIES_RHYHORN, 29
	wild_mon SPECIES_ODDISH, 29
	wild_mon SPECIES_DODUO, 27
	wild_mon SPECIES_GLOOM, 29
	wild_mon SPECIES_GLOOM, 31
	wild_mon SPECIES_DODUO, 29
	wild_mon SPECIES_DODRIO, 29
	wild_mon SPECIES_PINSIR, 27
	wild_mon SPECIES_DODRIO, 31
	wild_mon SPECIES_PINSIR, 29

	.align 2
gSafariZone_Northwest_LandMonsInfo:: @ 8551F6C
	.4byte 25 @ encounter rate
	.4byte gSafariZone_Northwest_LandMons

	.align 2
gSafariZone_Northwest_WaterMons:: @ 8551F74
	wild_mon SPECIES_PSYDUCK, 20, 30
	wild_mon SPECIES_PSYDUCK, 20, 30
	wild_mon SPECIES_PSYDUCK, 30, 35
	wild_mon SPECIES_GOLDUCK, 30, 35
	wild_mon SPECIES_GOLDUCK, 25, 40

	.align 2
gSafariZone_Northwest_WaterMonsInfo:: @ 8551F88
	.4byte 9 @ encounter rate
	.4byte gSafariZone_Northwest_WaterMons

	.align 2
gSafariZone_Northwest_FishingMons:: @ 8551F90
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 25
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_GOLDEEN, 25, 30
	wild_mon SPECIES_GOLDEEN, 30, 35
	wild_mon SPECIES_SEAKING, 30, 35
	wild_mon SPECIES_SEAKING, 35, 40
	wild_mon SPECIES_SEAKING, 25, 30

	.align 2
gSafariZone_Northwest_FishingMonsInfo:: @ 8551FB8
	.4byte 35 @ encounter rate
	.4byte gSafariZone_Northwest_FishingMons

	.align 2
gVictoryRoad_B1F_LandMons:: @ 8551FC0
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_HARIYAMA, 40
	wild_mon SPECIES_LAIRON, 40
	wild_mon SPECIES_LAIRON, 40
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_HARIYAMA, 38
	wild_mon SPECIES_GOLBAT, 42
	wild_mon SPECIES_HARIYAMA, 42
	wild_mon SPECIES_LAIRON, 42
	wild_mon SPECIES_MAWILE, 38
	wild_mon SPECIES_LAIRON, 42
	wild_mon SPECIES_MAWILE, 38

	.align 2
gVictoryRoad_B1F_LandMonsInfo:: @ 8551FF0
	.4byte 10 @ encounter rate
	.4byte gVictoryRoad_B1F_LandMons

	.align 2
gVictoryRoad_B1F_RockSmashMons:: @ 8551FF8
	wild_mon SPECIES_GRAVELER, 30, 40
	wild_mon SPECIES_GEODUDE, 30, 40
	wild_mon SPECIES_GRAVELER, 35, 40
	wild_mon SPECIES_GRAVELER, 35, 40
	wild_mon SPECIES_GRAVELER, 35, 40

	.align 2
gVictoryRoad_B1F_RockSmashMonsInfo:: @ 855200C
	.4byte 20 @ encounter rate
	.4byte gVictoryRoad_B1F_RockSmashMons

	.align 2
gVictoryRoad_B2F_LandMons:: @ 8552014
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_SABLEYE, 40
	wild_mon SPECIES_LAIRON, 40
	wild_mon SPECIES_LAIRON, 40
	wild_mon SPECIES_GOLBAT, 42
	wild_mon SPECIES_SABLEYE, 42
	wild_mon SPECIES_GOLBAT, 44
	wild_mon SPECIES_SABLEYE, 44
	wild_mon SPECIES_LAIRON, 42
	wild_mon SPECIES_MAWILE, 42
	wild_mon SPECIES_LAIRON, 44
	wild_mon SPECIES_MAWILE, 44

	.align 2
gVictoryRoad_B2F_LandMonsInfo:: @ 8552044
	.4byte 10 @ encounter rate
	.4byte gVictoryRoad_B2F_LandMons

	.align 2
gVictoryRoad_B2F_WaterMons:: @ 855204C
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 25, 30
	wild_mon SPECIES_GOLBAT, 35, 40
	wild_mon SPECIES_GOLBAT, 35, 40
	wild_mon SPECIES_GOLBAT, 35, 40

	.align 2
gVictoryRoad_B2F_WaterMonsInfo:: @ 8552060
	.4byte 4 @ encounter rate
	.4byte gVictoryRoad_B2F_WaterMons

	.align 2
gVictoryRoad_B2F_FishingMons:: @ 8552068
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_WHISCASH, 30, 35
	wild_mon SPECIES_WHISCASH, 35, 40
	wild_mon SPECIES_WHISCASH, 40, 45

	.align 2
gVictoryRoad_B2F_FishingMonsInfo:: @ 8552090
	.4byte 30 @ encounter rate
	.4byte gVictoryRoad_B2F_FishingMons

	.align 2
gMeteorFalls_1F_1R_LandMons:: @ 8552098
	wild_mon SPECIES_ZUBAT, 16
	wild_mon SPECIES_ZUBAT, 17
	wild_mon SPECIES_ZUBAT, 18
	wild_mon SPECIES_ZUBAT, 15
	wild_mon SPECIES_ZUBAT, 14
	wild_mon SPECIES_SOLROCK, 16
	wild_mon SPECIES_SOLROCK, 18
	wild_mon SPECIES_SOLROCK, 14
	wild_mon SPECIES_ZUBAT, 19
	wild_mon SPECIES_ZUBAT, 20
	wild_mon SPECIES_ZUBAT, 19
	wild_mon SPECIES_ZUBAT, 20

	.align 2
gMeteorFalls_1F_1R_LandMonsInfo:: @ 85520C8
	.4byte 10 @ encounter rate
	.4byte gMeteorFalls_1F_1R_LandMons

	.align 2
gMeteorFalls_1F_1R_WaterMons:: @ 85520D0
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_ZUBAT, 30, 35
	wild_mon SPECIES_SOLROCK, 25, 35
	wild_mon SPECIES_SOLROCK, 15, 25
	wild_mon SPECIES_SOLROCK, 5, 15

	.align 2
gMeteorFalls_1F_1R_WaterMonsInfo:: @ 85520E4
	.4byte 4 @ encounter rate
	.4byte gMeteorFalls_1F_1R_WaterMons

	.align 2
gMeteorFalls_1F_1R_FishingMons:: @ 85520EC
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_BARBOACH, 20, 25
	wild_mon SPECIES_BARBOACH, 35, 40
	wild_mon SPECIES_BARBOACH, 40, 45

	.align 2
gMeteorFalls_1F_1R_FishingMonsInfo:: @ 8552114
	.4byte 30 @ encounter rate
	.4byte gMeteorFalls_1F_1R_FishingMons

	.align 2
gMeteorFalls_1F_2R_LandMons:: @ 855211C
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_SOLROCK, 35
	wild_mon SPECIES_SOLROCK, 33
	wild_mon SPECIES_SOLROCK, 37
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SOLROCK, 39
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40

	.align 2
gMeteorFalls_1F_2R_LandMonsInfo:: @ 855214C
	.4byte 10 @ encounter rate
	.4byte gMeteorFalls_1F_2R_LandMons

	.align 2
gMeteorFalls_1F_2R_WaterMons:: @ 8552154
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_SOLROCK, 25, 35
	wild_mon SPECIES_SOLROCK, 15, 25
	wild_mon SPECIES_SOLROCK, 5, 15

	.align 2
gMeteorFalls_1F_2R_WaterMonsInfo:: @ 8552168
	.4byte 4 @ encounter rate
	.4byte gMeteorFalls_1F_2R_WaterMons

	.align 2
gMeteorFalls_1F_2R_FishingMons:: @ 8552170
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_WHISCASH, 30, 35
	wild_mon SPECIES_WHISCASH, 35, 40
	wild_mon SPECIES_WHISCASH, 40, 45

	.align 2
gMeteorFalls_1F_2R_FishingMonsInfo:: @ 8552198
	.4byte 30 @ encounter rate
	.4byte gMeteorFalls_1F_2R_FishingMons

	.align 2
gMeteorFalls_B1F_1R_LandMons:: @ 85521A0
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_SOLROCK, 35
	wild_mon SPECIES_SOLROCK, 33
	wild_mon SPECIES_SOLROCK, 37
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SOLROCK, 39
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40

	.align 2
gMeteorFalls_B1F_1R_LandMonsInfo:: @ 85521D0
	.4byte 10 @ encounter rate
	.4byte gMeteorFalls_B1F_1R_LandMons

	.align 2
gMeteorFalls_B1F_1R_WaterMons:: @ 85521D8
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_GOLBAT, 30, 35
	wild_mon SPECIES_SOLROCK, 25, 35
	wild_mon SPECIES_SOLROCK, 15, 25
	wild_mon SPECIES_SOLROCK, 5, 15

	.align 2
gMeteorFalls_B1F_1R_WaterMonsInfo:: @ 85521EC
	.4byte 4 @ encounter rate
	.4byte gMeteorFalls_B1F_1R_WaterMons

	.align 2
gMeteorFalls_B1F_1R_FishingMons:: @ 85521F4
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_BARBOACH, 10, 30
	wild_mon SPECIES_BARBOACH, 25, 30
	wild_mon SPECIES_BARBOACH, 30, 35
	wild_mon SPECIES_WHISCASH, 30, 35
	wild_mon SPECIES_WHISCASH, 35, 40
	wild_mon SPECIES_WHISCASH, 40, 45

	.align 2
gMeteorFalls_B1F_1R_FishingMonsInfo:: @ 855221C
	.4byte 30 @ encounter rate
	.4byte gMeteorFalls_B1F_1R_FishingMons

	.align 2
gShoalCave_LowTideStairsRoom_LandMons:: @ 8552224
	wild_mon SPECIES_ZUBAT, 26
	wild_mon SPECIES_SPHEAL, 26
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_SPHEAL, 28
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_SPHEAL, 30
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32

	.align 2
gShoalCave_LowTideStairsRoom_LandMonsInfo:: @ 8552254
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideStairsRoom_LandMons

	.align 2
gShoalCave_LowTideLowerRoom_LandMons:: @ 855225C
	wild_mon SPECIES_ZUBAT, 26
	wild_mon SPECIES_SPHEAL, 26
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_SPHEAL, 28
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_SPHEAL, 30
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32

	.align 2
gShoalCave_LowTideLowerRoom_LandMonsInfo:: @ 855228C
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideLowerRoom_LandMons

	.align 2
gShoalCave_LowTideInnerRoom_LandMons:: @ 8552294
	wild_mon SPECIES_ZUBAT, 26
	wild_mon SPECIES_SPHEAL, 26
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_SPHEAL, 28
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_SPHEAL, 30
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32

	.align 2
gShoalCave_LowTideInnerRoom_LandMonsInfo:: @ 85522C4
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideInnerRoom_LandMons

	.align 2
gShoalCave_LowTideInnerRoom_WaterMons:: @ 85522CC
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_SPHEAL, 25, 30
	wild_mon SPECIES_SPHEAL, 25, 30
	wild_mon SPECIES_SPHEAL, 25, 35

	.align 2
gShoalCave_LowTideInnerRoom_WaterMonsInfo:: @ 85522E0
	.4byte 4 @ encounter rate
	.4byte gShoalCave_LowTideInnerRoom_WaterMons

	.align 2
gShoalCave_LowTideInnerRoom_FishingMons:: @ 85522E8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gShoalCave_LowTideInnerRoom_FishingMonsInfo:: @ 8552310
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideInnerRoom_FishingMons

	.align 2
gShoalCave_LowTideEntranceRoom_LandMons:: @ 8552318
	wild_mon SPECIES_ZUBAT, 26
	wild_mon SPECIES_SPHEAL, 26
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_SPHEAL, 28
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_SPHEAL, 30
	wild_mon SPECIES_ZUBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SPHEAL, 32

	.align 2
gShoalCave_LowTideEntranceRoom_LandMonsInfo:: @ 8552348
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideEntranceRoom_LandMons

	.align 2
gShoalCave_LowTideEntranceRoom_WaterMons:: @ 8552350
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_ZUBAT, 5, 35
	wild_mon SPECIES_SPHEAL, 25, 30
	wild_mon SPECIES_SPHEAL, 25, 30
	wild_mon SPECIES_SPHEAL, 25, 35

	.align 2
gShoalCave_LowTideEntranceRoom_WaterMonsInfo:: @ 8552364
	.4byte 4 @ encounter rate
	.4byte gShoalCave_LowTideEntranceRoom_WaterMons

	.align 2
gShoalCave_LowTideEntranceRoom_FishingMons:: @ 855236C
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gShoalCave_LowTideEntranceRoom_FishingMonsInfo:: @ 8552394
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideEntranceRoom_FishingMons

	.align 2
gLilycoveCity_WaterMons:: @ 855239C
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gLilycoveCity_WaterMonsInfo:: @ 85523B0
	.4byte 4 @ encounter rate
	.4byte gLilycoveCity_WaterMons

	.align 2
gLilycoveCity_FishingMons:: @ 85523B8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_STARYU, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gLilycoveCity_FishingMonsInfo:: @ 85523E0
	.4byte 10 @ encounter rate
	.4byte gLilycoveCity_FishingMons

	.align 2
gDewfordTown_WaterMons:: @ 85523E8
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gDewfordTown_WaterMonsInfo:: @ 85523FC
	.4byte 4 @ encounter rate
	.4byte gDewfordTown_WaterMons

	.align 2
gDewfordTown_FishingMons:: @ 8552404
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gDewfordTown_FishingMonsInfo:: @ 855242C
	.4byte 10 @ encounter rate
	.4byte gDewfordTown_FishingMons

	.align 2
gSlateportCity_WaterMons:: @ 8552434
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gSlateportCity_WaterMonsInfo:: @ 8552448
	.4byte 4 @ encounter rate
	.4byte gSlateportCity_WaterMons

	.align 2
gSlateportCity_FishingMons:: @ 8552450
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 20, 25
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gSlateportCity_FishingMonsInfo:: @ 8552478
	.4byte 10 @ encounter rate
	.4byte gSlateportCity_FishingMons

	.align 2
gMossdeepCity_WaterMons:: @ 8552480
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gMossdeepCity_WaterMonsInfo:: @ 8552494
	.4byte 4 @ encounter rate
	.4byte gMossdeepCity_WaterMons

	.align 2
gMossdeepCity_FishingMons:: @ 855249C
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gMossdeepCity_FishingMonsInfo:: @ 85524C4
	.4byte 10 @ encounter rate
	.4byte gMossdeepCity_FishingMons

	.align 2
gPacifidlogTown_WaterMons:: @ 85524CC
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gPacifidlogTown_WaterMonsInfo:: @ 85524E0
	.4byte 4 @ encounter rate
	.4byte gPacifidlogTown_WaterMons

	.align 2
gPacifidlogTown_FishingMons:: @ 85524E8
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_TENTACOOL, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_SHARPEDO, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_WAILMER, 25, 30
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gPacifidlogTown_FishingMonsInfo:: @ 8552510
	.4byte 10 @ encounter rate
	.4byte gPacifidlogTown_FishingMons

	.align 2
gEverGrandeCity_WaterMons:: @ 8552518
	wild_mon SPECIES_TENTACOOL, 5, 35
	wild_mon SPECIES_WINGULL, 10, 30
	wild_mon SPECIES_WINGULL, 15, 25
	wild_mon SPECIES_PELIPPER, 25, 30
	wild_mon SPECIES_PELIPPER, 25, 30

	.align 2
gEverGrandeCity_WaterMonsInfo:: @ 855252C
	.4byte 4 @ encounter rate
	.4byte gEverGrandeCity_WaterMons

	.align 2
gEverGrandeCity_FishingMons:: @ 8552534
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_LUVDISC, 10, 30
	wild_mon SPECIES_WAILMER, 10, 30
	wild_mon SPECIES_LUVDISC, 30, 35
	wild_mon SPECIES_WAILMER, 30, 35
	wild_mon SPECIES_CORSOLA, 30, 35
	wild_mon SPECIES_WAILMER, 35, 40
	wild_mon SPECIES_WAILMER, 40, 45

	.align 2
gEverGrandeCity_FishingMonsInfo:: @ 855255C
	.4byte 10 @ encounter rate
	.4byte gEverGrandeCity_FishingMons

	.align 2
gPetalburgCity_WaterMons:: @ 8552564
	wild_mon SPECIES_MARILL, 20, 30
	wild_mon SPECIES_MARILL, 10, 20
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_MARILL, 5, 10
	wild_mon SPECIES_MARILL, 5, 10

	.align 2
gPetalburgCity_WaterMonsInfo:: @ 8552578
	.4byte 1 @ encounter rate
	.4byte gPetalburgCity_WaterMons

	.align 2
gPetalburgCity_FishingMons:: @ 8552580
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_GOLDEEN, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_GOLDEEN, 10, 30
	wild_mon SPECIES_CORPHISH, 10, 30
	wild_mon SPECIES_CORPHISH, 25, 30
	wild_mon SPECIES_CORPHISH, 30, 35
	wild_mon SPECIES_CORPHISH, 20, 25
	wild_mon SPECIES_CORPHISH, 35, 40
	wild_mon SPECIES_CORPHISH, 40, 45

	.align 2
gPetalburgCity_FishingMonsInfo:: @ 85525A8
	.4byte 10 @ encounter rate
	.4byte gPetalburgCity_FishingMons

	.align 2
gUnderwater1_WaterMons:: @ 85525B0
	wild_mon SPECIES_CLAMPERL, 20, 30
	wild_mon SPECIES_CHINCHOU, 20, 30
	wild_mon SPECIES_CLAMPERL, 30, 35
	wild_mon SPECIES_RELICANTH, 30, 35
	wild_mon SPECIES_RELICANTH, 30, 35

	.align 2
gUnderwater1_WaterMonsInfo:: @ 85525C4
	.4byte 4 @ encounter rate
	.4byte gUnderwater1_WaterMons

	.align 2
gShoalCave_LowTideIceRoom_LandMons:: @ 85525CC
	wild_mon SPECIES_ZUBAT, 26
	wild_mon SPECIES_SPHEAL, 26
	wild_mon SPECIES_ZUBAT, 28
	wild_mon SPECIES_SPHEAL, 28
	wild_mon SPECIES_ZUBAT, 30
	wild_mon SPECIES_SPHEAL, 30
	wild_mon SPECIES_SNORUNT, 26
	wild_mon SPECIES_SPHEAL, 32
	wild_mon SPECIES_GOLBAT, 30
	wild_mon SPECIES_SNORUNT, 28
	wild_mon SPECIES_GOLBAT, 32
	wild_mon SPECIES_SNORUNT, 30

	.align 2
gShoalCave_LowTideIceRoom_LandMonsInfo:: @ 85525FC
	.4byte 10 @ encounter rate
	.4byte gShoalCave_LowTideIceRoom_LandMons

	.align 2
gSkyPillar_1F_LandMons:: @ 8552604
	wild_mon SPECIES_SABLEYE, 33
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_BANETTE, 37
	wild_mon SPECIES_BANETTE, 38
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_CLAYDOL, 37
	wild_mon SPECIES_CLAYDOL, 38
	wild_mon SPECIES_CLAYDOL, 37
	wild_mon SPECIES_CLAYDOL, 38

	.align 2
gSkyPillar_1F_LandMonsInfo:: @ 8552634
	.4byte 10 @ encounter rate
	.4byte gSkyPillar_1F_LandMons

	.align 2
gSootopolisCity_WaterMons:: @ 855263C
	wild_mon SPECIES_MAGIKARP, 5, 35
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 15, 25
	wild_mon SPECIES_MAGIKARP, 25, 30
	wild_mon SPECIES_MAGIKARP, 25, 30

	.align 2
gSootopolisCity_WaterMonsInfo:: @ 8552650
	.4byte 1 @ encounter rate
	.4byte gSootopolisCity_WaterMons

	.align 2
gSootopolisCity_FishingMons:: @ 8552658
	wild_mon SPECIES_MAGIKARP, 5, 10
	wild_mon SPECIES_TENTACOOL, 5, 10
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 10, 30
	wild_mon SPECIES_MAGIKARP, 30, 35
	wild_mon SPECIES_MAGIKARP, 30, 35
	wild_mon SPECIES_GYARADOS, 35, 40
	wild_mon SPECIES_GYARADOS, 35, 45
	wild_mon SPECIES_GYARADOS, 5, 45

	.align 2
gSootopolisCity_FishingMonsInfo:: @ 8552680
	.4byte 10 @ encounter rate
	.4byte gSootopolisCity_FishingMons

	.align 2
gSkyPillar_3F_LandMons:: @ 8552688
	wild_mon SPECIES_SABLEYE, 33
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_BANETTE, 37
	wild_mon SPECIES_BANETTE, 38
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_CLAYDOL, 37
	wild_mon SPECIES_CLAYDOL, 38
	wild_mon SPECIES_CLAYDOL, 37
	wild_mon SPECIES_CLAYDOL, 38

	.align 2
gSkyPillar_3F_LandMonsInfo:: @ 85526B8
	.4byte 10 @ encounter rate
	.4byte gSkyPillar_3F_LandMons

	.align 2
gSkyPillar_5F_LandMons:: @ 85526C0
	wild_mon SPECIES_SABLEYE, 33
	wild_mon SPECIES_GOLBAT, 34
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SABLEYE, 34
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_BANETTE, 37
	wild_mon SPECIES_BANETTE, 38
	wild_mon SPECIES_CLAYDOL, 36
	wild_mon SPECIES_CLAYDOL, 37
	wild_mon SPECIES_ALTARIA, 38
	wild_mon SPECIES_ALTARIA, 39
	wild_mon SPECIES_ALTARIA, 39

	.align 2
gSkyPillar_5F_LandMonsInfo:: @ 85526F0
	.4byte 10 @ encounter rate
	.4byte gSkyPillar_5F_LandMons

	.align 2
gSafariZone_Southeast_LandMons:: @ 85526F8
	wild_mon SPECIES_SUNKERN, 33
	wild_mon SPECIES_MAREEP, 34
	wild_mon SPECIES_SUNKERN, 35
	wild_mon SPECIES_MAREEP, 36
	wild_mon SPECIES_AIPOM, 34
	wild_mon SPECIES_SPINARAK, 33
	wild_mon SPECIES_HOOTHOOT, 35
	wild_mon SPECIES_SNUBBULL, 34
	wild_mon SPECIES_STANTLER, 36
	wild_mon SPECIES_GLIGAR, 37
	wild_mon SPECIES_STANTLER, 39
	wild_mon SPECIES_GLIGAR, 40

	.align 2
gSafariZone_Southeast_LandMonsInfo:: @ 8552728
	.4byte 25 @ encounter rate
	.4byte gSafariZone_Southeast_LandMons

	.align 2
gSafariZone_Southeast_WaterMons:: @ 8552730
	wild_mon SPECIES_WOOPER, 25, 30
	wild_mon SPECIES_MARILL, 25, 30
	wild_mon SPECIES_MARILL, 25, 30
	wild_mon SPECIES_MARILL, 30, 35
	wild_mon SPECIES_QUAGSIRE, 35, 40

	.align 2
gSafariZone_Southeast_WaterMonsInfo:: @ 8552744
	.4byte 9 @ encounter rate
	.4byte gSafariZone_Southeast_WaterMons

	.align 2
gSafariZone_Southeast_FishingMons:: @ 855274C
	wild_mon SPECIES_MAGIKARP, 25, 30
	wild_mon SPECIES_GOLDEEN, 25, 30
	wild_mon SPECIES_MAGIKARP, 25, 30
	wild_mon SPECIES_GOLDEEN, 25, 30
	wild_mon SPECIES_REMORAID, 30, 35
	wild_mon SPECIES_GOLDEEN, 25, 30
	wild_mon SPECIES_REMORAID, 25, 30
	wild_mon SPECIES_REMORAID, 30, 35
	wild_mon SPECIES_REMORAID, 30, 35
	wild_mon SPECIES_OCTILLERY, 35, 40

	.align 2
gSafariZone_Southeast_FishingMonsInfo:: @ 8552774
	.4byte 35 @ encounter rate
	.4byte gSafariZone_Southeast_FishingMons

	.align 2
gSafariZone_Northeast_LandMons:: @ 855277C
	wild_mon SPECIES_AIPOM, 33
	wild_mon SPECIES_TEDDIURSA, 34
	wild_mon SPECIES_AIPOM, 35
	wild_mon SPECIES_TEDDIURSA, 36
	wild_mon SPECIES_SUNKERN, 34
	wild_mon SPECIES_LEDYBA, 33
	wild_mon SPECIES_HOOTHOOT, 35
	wild_mon SPECIES_PINECO, 34
	wild_mon SPECIES_HOUNDOUR, 36
	wild_mon SPECIES_MILTANK, 37
	wild_mon SPECIES_HOUNDOUR, 39
	wild_mon SPECIES_MILTANK, 40

	.align 2
gSafariZone_Northeast_LandMonsInfo:: @ 85527AC
	.4byte 25 @ encounter rate
	.4byte gSafariZone_Northeast_LandMons

	.align 2
gSafariZone_Northeast_RockSmashMons:: @ 85527B4
	wild_mon SPECIES_SHUCKLE, 25, 30
	wild_mon SPECIES_SHUCKLE, 20, 25
	wild_mon SPECIES_SHUCKLE, 30, 35
	wild_mon SPECIES_SHUCKLE, 30, 35
	wild_mon SPECIES_SHUCKLE, 35, 40

	.align 2
gSafariZone_Northeast_RockSmashMonsInfo:: @ 85527C8
	.4byte 25 @ encounter rate
	.4byte gSafariZone_Northeast_RockSmashMons

	.align 2
gMagmaHideout_1F_LandMons:: @ 85527D0
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_1F_LandMonsInfo:: @ 8552800
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_1F_LandMons

	.align 2
gMagmaHideout_2F_1R_LandMons:: @ 8552808
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_2F_1R_LandMonsInfo:: @ 8552838
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_2F_1R_LandMons

	.align 2
gMagmaHideout_2F_2R_LandMons:: @ 8552840
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_2F_2R_LandMonsInfo:: @ 8552870
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_2F_2R_LandMons

	.align 2
gMagmaHideout_3F_1R_LandMons:: @ 8552878
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_3F_1R_LandMonsInfo:: @ 85528A8
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_3F_1R_LandMons

	.align 2
gMagmaHideout_3F_2R_LandMons:: @ 85528B0
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_3F_2R_LandMonsInfo:: @ 85528E0
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_3F_2R_LandMons

	.align 2
gMagmaHideout_4F_LandMons:: @ 85528E8
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_4F_LandMonsInfo:: @ 8552918
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_4F_LandMons

	.align 2
gMagmaHideout_3F_3R_LandMons:: @ 8552920
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_3F_3R_LandMonsInfo:: @ 8552950
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_3F_3R_LandMons

	.align 2
gMagmaHideout_2F_3R_LandMons:: @ 8552958
	wild_mon SPECIES_GEODUDE, 27
	wild_mon SPECIES_TORKOAL, 28
	wild_mon SPECIES_GEODUDE, 28
	wild_mon SPECIES_TORKOAL, 30
	wild_mon SPECIES_GEODUDE, 29
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GEODUDE, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 30
	wild_mon SPECIES_GRAVELER, 31
	wild_mon SPECIES_GRAVELER, 32
	wild_mon SPECIES_GRAVELER, 33

	.align 2
gMagmaHideout_2F_3R_LandMonsInfo:: @ 8552988
	.4byte 10 @ encounter rate
	.4byte gMagmaHideout_2F_3R_LandMons

	.align 2
gMirageTower_1F_LandMons:: @ 8552990
	wild_mon SPECIES_SANDSHREW, 21
	wild_mon SPECIES_TRAPINCH, 21
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 22
	wild_mon SPECIES_TRAPINCH, 22
	wild_mon SPECIES_SANDSHREW, 23
	wild_mon SPECIES_TRAPINCH, 23
	wild_mon SPECIES_SANDSHREW, 24
	wild_mon SPECIES_TRAPINCH, 24

	.align 2
gMirageTower_1F_LandMonsInfo:: @ 85529C0
	.4byte 10 @ encounter rate
	.4byte gMirageTower_1F_LandMons

	.align 2
gMirageTower_2F_LandMons:: @ 85529C8
	wild_mon SPECIES_SANDSHREW, 21
	wild_mon SPECIES_TRAPINCH, 21
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 22
	wild_mon SPECIES_TRAPINCH, 22
	wild_mon SPECIES_SANDSHREW, 23
	wild_mon SPECIES_TRAPINCH, 23
	wild_mon SPECIES_SANDSHREW, 24
	wild_mon SPECIES_TRAPINCH, 24

	.align 2
gMirageTower_2F_LandMonsInfo:: @ 85529F8
	.4byte 10 @ encounter rate
	.4byte gMirageTower_2F_LandMons

	.align 2
gMirageTower_3F_LandMons:: @ 8552A00
	wild_mon SPECIES_SANDSHREW, 21
	wild_mon SPECIES_TRAPINCH, 21
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 22
	wild_mon SPECIES_TRAPINCH, 22
	wild_mon SPECIES_SANDSHREW, 23
	wild_mon SPECIES_TRAPINCH, 23
	wild_mon SPECIES_SANDSHREW, 24
	wild_mon SPECIES_TRAPINCH, 24

	.align 2
gMirageTower_3F_LandMonsInfo:: @ 8552A30
	.4byte 10 @ encounter rate
	.4byte gMirageTower_3F_LandMons

	.align 2
gMirageTower_4F_LandMons:: @ 8552A38
	wild_mon SPECIES_SANDSHREW, 21
	wild_mon SPECIES_TRAPINCH, 21
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 20
	wild_mon SPECIES_TRAPINCH, 20
	wild_mon SPECIES_SANDSHREW, 22
	wild_mon SPECIES_TRAPINCH, 22
	wild_mon SPECIES_SANDSHREW, 23
	wild_mon SPECIES_TRAPINCH, 23
	wild_mon SPECIES_SANDSHREW, 24
	wild_mon SPECIES_TRAPINCH, 24

	.align 2
gMirageTower_4F_LandMonsInfo:: @ 8552A68
	.4byte 10 @ encounter rate
	.4byte gMirageTower_4F_LandMons

	.align 2
gDesertUnderpass_LandMons:: @ 8552A70
	wild_mon SPECIES_DITTO, 38
	wild_mon SPECIES_WHISMUR, 35
	wild_mon SPECIES_DITTO, 40
	wild_mon SPECIES_LOUDRED, 40
	wild_mon SPECIES_DITTO, 41
	wild_mon SPECIES_WHISMUR, 36
	wild_mon SPECIES_LOUDRED, 38
	wild_mon SPECIES_DITTO, 42
	wild_mon SPECIES_WHISMUR, 38
	wild_mon SPECIES_DITTO, 43
	wild_mon SPECIES_LOUDRED, 44
	wild_mon SPECIES_DITTO, 45

	.align 2
gDesertUnderpass_LandMonsInfo:: @ 8552AA0
	.4byte 10 @ encounter rate
	.4byte gDesertUnderpass_LandMons

	.align 2
gArtisanCave_B1F_LandMons:: @ 8552AA8
	wild_mon SPECIES_SMEARGLE, 40
	wild_mon SPECIES_SMEARGLE, 41
	wild_mon SPECIES_SMEARGLE, 42
	wild_mon SPECIES_SMEARGLE, 43
	wild_mon SPECIES_SMEARGLE, 44
	wild_mon SPECIES_SMEARGLE, 45
	wild_mon SPECIES_SMEARGLE, 46
	wild_mon SPECIES_SMEARGLE, 47
	wild_mon SPECIES_SMEARGLE, 48
	wild_mon SPECIES_SMEARGLE, 49
	wild_mon SPECIES_SMEARGLE, 50
	wild_mon SPECIES_SMEARGLE, 50

	.align 2
gArtisanCave_B1F_LandMonsInfo:: @ 8552AD8
	.4byte 10 @ encounter rate
	.4byte gArtisanCave_B1F_LandMons

	.align 2
gArtisanCave_1F_LandMons:: @ 8552AE0
	wild_mon SPECIES_SMEARGLE, 40
	wild_mon SPECIES_SMEARGLE, 41
	wild_mon SPECIES_SMEARGLE, 42
	wild_mon SPECIES_SMEARGLE, 43
	wild_mon SPECIES_SMEARGLE, 44
	wild_mon SPECIES_SMEARGLE, 45
	wild_mon SPECIES_SMEARGLE, 46
	wild_mon SPECIES_SMEARGLE, 47
	wild_mon SPECIES_SMEARGLE, 48
	wild_mon SPECIES_SMEARGLE, 49
	wild_mon SPECIES_SMEARGLE, 50
	wild_mon SPECIES_SMEARGLE, 50

	.align 2
gArtisanCave_1F_LandMonsInfo:: @ 8552B10
	.4byte 10 @ encounter rate
	.4byte gArtisanCave_1F_LandMons

	.align 2
gAlteringCave1_LandMons:: @ 8552B18
	wild_mon SPECIES_ZUBAT, 10
	wild_mon SPECIES_ZUBAT, 12
	wild_mon SPECIES_ZUBAT, 8
	wild_mon SPECIES_ZUBAT, 14
	wild_mon SPECIES_ZUBAT, 10
	wild_mon SPECIES_ZUBAT, 12
	wild_mon SPECIES_ZUBAT, 16
	wild_mon SPECIES_ZUBAT, 6
	wild_mon SPECIES_ZUBAT, 8
	wild_mon SPECIES_ZUBAT, 14
	wild_mon SPECIES_ZUBAT, 8
	wild_mon SPECIES_ZUBAT, 14

	.align 2
gAlteringCave1_LandMonsInfo:: @ 8552B48
	.4byte 7 @ encounter rate
	.4byte gAlteringCave1_LandMons

	.align 2
gAlteringCave2_LandMons:: @ 8552B50
	wild_mon SPECIES_MAREEP, 7
	wild_mon SPECIES_MAREEP, 9
	wild_mon SPECIES_MAREEP, 5
	wild_mon SPECIES_MAREEP, 11
	wild_mon SPECIES_MAREEP, 7
	wild_mon SPECIES_MAREEP, 9
	wild_mon SPECIES_MAREEP, 13
	wild_mon SPECIES_MAREEP, 3
	wild_mon SPECIES_MAREEP, 5
	wild_mon SPECIES_MAREEP, 11
	wild_mon SPECIES_MAREEP, 5
	wild_mon SPECIES_MAREEP, 11

	.align 2
gAlteringCave2_LandMonsInfo:: @ 8552B80
	.4byte 7 @ encounter rate
	.4byte gAlteringCave2_LandMons

	.align 2
gAlteringCave3_LandMons:: @ 8552B88
	wild_mon SPECIES_PINECO, 23
	wild_mon SPECIES_PINECO, 25
	wild_mon SPECIES_PINECO, 22
	wild_mon SPECIES_PINECO, 27
	wild_mon SPECIES_PINECO, 23
	wild_mon SPECIES_PINECO, 25
	wild_mon SPECIES_PINECO, 29
	wild_mon SPECIES_PINECO, 19
	wild_mon SPECIES_PINECO, 21
	wild_mon SPECIES_PINECO, 27
	wild_mon SPECIES_PINECO, 21
	wild_mon SPECIES_PINECO, 27

	.align 2
gAlteringCave3_LandMonsInfo:: @ 8552BB8
	.4byte 7 @ encounter rate
	.4byte gAlteringCave3_LandMons

	.align 2
gAlteringCave4_LandMons:: @ 8552BC0
	wild_mon SPECIES_HOUNDOUR, 16
	wild_mon SPECIES_HOUNDOUR, 18
	wild_mon SPECIES_HOUNDOUR, 14
	wild_mon SPECIES_HOUNDOUR, 20
	wild_mon SPECIES_HOUNDOUR, 16
	wild_mon SPECIES_HOUNDOUR, 18
	wild_mon SPECIES_HOUNDOUR, 22
	wild_mon SPECIES_HOUNDOUR, 12
	wild_mon SPECIES_HOUNDOUR, 14
	wild_mon SPECIES_HOUNDOUR, 20
	wild_mon SPECIES_HOUNDOUR, 14
	wild_mon SPECIES_HOUNDOUR, 20

	.align 2
gAlteringCave4_LandMonsInfo:: @ 8552BF0
	.4byte 7 @ encounter rate
	.4byte gAlteringCave4_LandMons

	.align 2
gAlteringCave5_LandMons:: @ 8552BF8
	wild_mon SPECIES_TEDDIURSA, 10
	wild_mon SPECIES_TEDDIURSA, 12
	wild_mon SPECIES_TEDDIURSA, 8
	wild_mon SPECIES_TEDDIURSA, 14
	wild_mon SPECIES_TEDDIURSA, 10
	wild_mon SPECIES_TEDDIURSA, 12
	wild_mon SPECIES_TEDDIURSA, 16
	wild_mon SPECIES_TEDDIURSA, 6
	wild_mon SPECIES_TEDDIURSA, 8
	wild_mon SPECIES_TEDDIURSA, 14
	wild_mon SPECIES_TEDDIURSA, 8
	wild_mon SPECIES_TEDDIURSA, 14

	.align 2
gAlteringCave5_LandMonsInfo:: @ 8552C28
	.4byte 7 @ encounter rate
	.4byte gAlteringCave5_LandMons

	.align 2
gAlteringCave6_LandMons:: @ 8552C30
	wild_mon SPECIES_AIPOM, 22
	wild_mon SPECIES_AIPOM, 24
	wild_mon SPECIES_AIPOM, 20
	wild_mon SPECIES_AIPOM, 26
	wild_mon SPECIES_AIPOM, 22
	wild_mon SPECIES_AIPOM, 24
	wild_mon SPECIES_AIPOM, 28
	wild_mon SPECIES_AIPOM, 18
	wild_mon SPECIES_AIPOM, 20
	wild_mon SPECIES_AIPOM, 26
	wild_mon SPECIES_AIPOM, 20
	wild_mon SPECIES_AIPOM, 26

	.align 2
gAlteringCave6_LandMonsInfo:: @ 8552C60
	.4byte 7 @ encounter rate
	.4byte gAlteringCave6_LandMons

	.align 2
gAlteringCave7_LandMons:: @ 8552C68
	wild_mon SPECIES_SHUCKLE, 22
	wild_mon SPECIES_SHUCKLE, 24
	wild_mon SPECIES_SHUCKLE, 20
	wild_mon SPECIES_SHUCKLE, 26
	wild_mon SPECIES_SHUCKLE, 22
	wild_mon SPECIES_SHUCKLE, 24
	wild_mon SPECIES_SHUCKLE, 28
	wild_mon SPECIES_SHUCKLE, 18
	wild_mon SPECIES_SHUCKLE, 20
	wild_mon SPECIES_SHUCKLE, 26
	wild_mon SPECIES_SHUCKLE, 20
	wild_mon SPECIES_SHUCKLE, 26

	.align 2
gAlteringCave7_LandMonsInfo:: @ 8552C98
	.4byte 7 @ encounter rate
	.4byte gAlteringCave7_LandMons

	.align 2
gAlteringCave8_LandMons:: @ 8552CA0
	wild_mon SPECIES_STANTLER, 22
	wild_mon SPECIES_STANTLER, 24
	wild_mon SPECIES_STANTLER, 20
	wild_mon SPECIES_STANTLER, 26
	wild_mon SPECIES_STANTLER, 22
	wild_mon SPECIES_STANTLER, 24
	wild_mon SPECIES_STANTLER, 28
	wild_mon SPECIES_STANTLER, 18
	wild_mon SPECIES_STANTLER, 20
	wild_mon SPECIES_STANTLER, 26
	wild_mon SPECIES_STANTLER, 20
	wild_mon SPECIES_STANTLER, 26

	.align 2
gAlteringCave8_LandMonsInfo:: @ 8552CD0
	.4byte 7 @ encounter rate
	.4byte gAlteringCave8_LandMons

	.align 2
gAlteringCave9_LandMons:: @ 8552CD8
	wild_mon SPECIES_SMEARGLE, 22
	wild_mon SPECIES_SMEARGLE, 24
	wild_mon SPECIES_SMEARGLE, 20
	wild_mon SPECIES_SMEARGLE, 26
	wild_mon SPECIES_SMEARGLE, 22
	wild_mon SPECIES_SMEARGLE, 24
	wild_mon SPECIES_SMEARGLE, 28
	wild_mon SPECIES_SMEARGLE, 18
	wild_mon SPECIES_SMEARGLE, 20
	wild_mon SPECIES_SMEARGLE, 26
	wild_mon SPECIES_SMEARGLE, 20
	wild_mon SPECIES_SMEARGLE, 26

	.align 2
gAlteringCave9_LandMonsInfo:: @ 8552D08
	.4byte 7 @ encounter rate
	.4byte gAlteringCave9_LandMons

	.align 2
gMeteorFalls_StevensCave_LandMons:: @ 8552D10
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_GOLBAT, 33
	wild_mon SPECIES_SOLROCK, 35
	wild_mon SPECIES_SOLROCK, 33
	wild_mon SPECIES_SOLROCK, 37
	wild_mon SPECIES_GOLBAT, 35
	wild_mon SPECIES_SOLROCK, 39
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40
	wild_mon SPECIES_GOLBAT, 38
	wild_mon SPECIES_GOLBAT, 40

	.align 2
gMeteorFalls_StevensCave_LandMonsInfo:: @ 8552D40
	.4byte 10 @ encounter rate
	.4byte gMeteorFalls_StevensCave_LandMons

	.align 2
gWildMonHeaders:: @ 8552D48
	map ROUTE_101
	.2byte 0 @ padding
	.4byte gRoute101_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_102
	.2byte 0 @ padding
	.4byte gRoute102_LandMonsInfo
	.4byte gRoute102_WaterMonsInfo
	.4byte NULL
	.4byte gRoute102_FishingMonsInfo

	map ROUTE_103
	.2byte 0 @ padding
	.4byte gRoute103_LandMonsInfo
	.4byte gRoute103_WaterMonsInfo
	.4byte NULL
	.4byte gRoute103_FishingMonsInfo

	map ROUTE_104
	.2byte 0 @ padding
	.4byte gRoute104_LandMonsInfo
	.4byte gRoute104_WaterMonsInfo
	.4byte NULL
	.4byte gRoute104_FishingMonsInfo

	map ROUTE_105
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute105_WaterMonsInfo
	.4byte NULL
	.4byte gRoute105_FishingMonsInfo

	map ROUTE_110
	.2byte 0 @ padding
	.4byte gRoute110_LandMonsInfo
	.4byte gRoute110_WaterMonsInfo
	.4byte NULL
	.4byte gRoute110_FishingMonsInfo

	map ROUTE_111
	.2byte 0 @ padding
	.4byte gRoute111_LandMonsInfo
	.4byte gRoute111_WaterMonsInfo
	.4byte gRoute111_RockSmashMonsInfo
	.4byte gRoute111_FishingMonsInfo

	map ROUTE_112
	.2byte 0 @ padding
	.4byte gRoute112_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_113
	.2byte 0 @ padding
	.4byte gRoute113_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_114
	.2byte 0 @ padding
	.4byte gRoute114_LandMonsInfo
	.4byte gRoute114_WaterMonsInfo
	.4byte gRoute114_RockSmashMonsInfo
	.4byte gRoute114_FishingMonsInfo

	map ROUTE_116
	.2byte 0 @ padding
	.4byte gRoute116_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_117
	.2byte 0 @ padding
	.4byte gRoute117_LandMonsInfo
	.4byte gRoute117_WaterMonsInfo
	.4byte NULL
	.4byte gRoute117_FishingMonsInfo

	map ROUTE_118
	.2byte 0 @ padding
	.4byte gRoute118_LandMonsInfo
	.4byte gRoute118_WaterMonsInfo
	.4byte NULL
	.4byte gRoute118_FishingMonsInfo

	map ROUTE_124
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute124_WaterMonsInfo
	.4byte NULL
	.4byte gRoute124_FishingMonsInfo

	map PETALBURG_WOODS
	.2byte 0 @ padding
	.4byte gPetalburgWoods_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map RUSTURF_TUNNEL
	.2byte 0 @ padding
	.4byte gRusturfTunnel_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map GRANITE_CAVE_1F
	.2byte 0 @ padding
	.4byte gGraniteCave_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map GRANITE_CAVE_B1F
	.2byte 0 @ padding
	.4byte gGraniteCave_B1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_1F
	.2byte 0 @ padding
	.4byte gMtPyre_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map VICTORY_ROAD_1F
	.2byte 0 @ padding
	.4byte gVictoryRoad_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SAFARI_ZONE_SOUTH
	.2byte 0 @ padding
	.4byte gSafariZone_South_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map UNDERWATER_2
	.2byte 0 @ padding
	.4byte NULL
	.4byte gUnderwater2_WaterMonsInfo
	.4byte NULL
	.4byte NULL

	map ABANDONED_SHIP_ROOMS_B1F
	.2byte 0 @ padding
	.4byte NULL
	.4byte gAbandonedShip_Rooms_B1F_WaterMonsInfo
	.4byte NULL
	.4byte gAbandonedShip_Rooms_B1F_FishingMonsInfo

	map GRANITE_CAVE_B2F
	.2byte 0 @ padding
	.4byte gGraniteCave_B2F_LandMonsInfo
	.4byte NULL
	.4byte gGraniteCave_B2F_RockSmashMonsInfo
	.4byte NULL

	map FIERY_PATH
	.2byte 0 @ padding
	.4byte gFieryPath_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map METEOR_FALLS_B1F_2R
	.2byte 0 @ padding
	.4byte gMeteorFalls_B1F_2R_LandMonsInfo
	.4byte gMeteorFalls_B1F_2R_WaterMonsInfo
	.4byte NULL
	.4byte gMeteorFalls_B1F_2R_FishingMonsInfo

	map JAGGED_PASS
	.2byte 0 @ padding
	.4byte gJaggedPass_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_106
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute106_WaterMonsInfo
	.4byte NULL
	.4byte gRoute106_FishingMonsInfo

	map ROUTE_107
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute107_WaterMonsInfo
	.4byte NULL
	.4byte gRoute107_FishingMonsInfo

	map ROUTE_108
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute108_WaterMonsInfo
	.4byte NULL
	.4byte gRoute108_FishingMonsInfo

	map ROUTE_109
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute109_WaterMonsInfo
	.4byte NULL
	.4byte gRoute109_FishingMonsInfo

	map ROUTE_115
	.2byte 0 @ padding
	.4byte gRoute115_LandMonsInfo
	.4byte gRoute115_WaterMonsInfo
	.4byte NULL
	.4byte gRoute115_FishingMonsInfo

	map NEW_MAUVILLE_INSIDE
	.2byte 0 @ padding
	.4byte gNewMauville_Inside_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_119
	.2byte 0 @ padding
	.4byte gRoute119_LandMonsInfo
	.4byte gRoute119_WaterMonsInfo
	.4byte NULL
	.4byte gRoute119_FishingMonsInfo

	map ROUTE_120
	.2byte 0 @ padding
	.4byte gRoute120_LandMonsInfo
	.4byte gRoute120_WaterMonsInfo
	.4byte NULL
	.4byte gRoute120_FishingMonsInfo

	map ROUTE_121
	.2byte 0 @ padding
	.4byte gRoute121_LandMonsInfo
	.4byte gRoute121_WaterMonsInfo
	.4byte NULL
	.4byte gRoute121_FishingMonsInfo

	map ROUTE_122
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute122_WaterMonsInfo
	.4byte NULL
	.4byte gRoute122_FishingMonsInfo

	map ROUTE_123
	.2byte 0 @ padding
	.4byte gRoute123_LandMonsInfo
	.4byte gRoute123_WaterMonsInfo
	.4byte NULL
	.4byte gRoute123_FishingMonsInfo

	map MT_PYRE_2F
	.2byte 0 @ padding
	.4byte gMtPyre_2F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_3F
	.2byte 0 @ padding
	.4byte gMtPyre_3F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_4F
	.2byte 0 @ padding
	.4byte gMtPyre_4F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_5F
	.2byte 0 @ padding
	.4byte gMtPyre_5F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_6F
	.2byte 0 @ padding
	.4byte gMtPyre_6F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_EXTERIOR
	.2byte 0 @ padding
	.4byte gMtPyre_Exterior_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MT_PYRE_SUMMIT
	.2byte 0 @ padding
	.4byte gMtPyre_Summit_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map GRANITE_CAVE_STEVENS_ROOM
	.2byte 0 @ padding
	.4byte gGraniteCave_StevensRoom_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ROUTE_125
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute125_WaterMonsInfo
	.4byte NULL
	.4byte gRoute125_FishingMonsInfo

	map ROUTE_126
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute126_WaterMonsInfo
	.4byte NULL
	.4byte gRoute126_FishingMonsInfo

	map ROUTE_127
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute127_WaterMonsInfo
	.4byte NULL
	.4byte gRoute127_FishingMonsInfo

	map ROUTE_128
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute128_WaterMonsInfo
	.4byte NULL
	.4byte gRoute128_FishingMonsInfo

	map ROUTE_129
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute129_WaterMonsInfo
	.4byte NULL
	.4byte gRoute129_FishingMonsInfo

	map ROUTE_130
	.2byte 0 @ padding
	.4byte gRoute130_LandMonsInfo
	.4byte gRoute130_WaterMonsInfo
	.4byte NULL
	.4byte gRoute130_FishingMonsInfo

	map ROUTE_131
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute131_WaterMonsInfo
	.4byte NULL
	.4byte gRoute131_FishingMonsInfo

	map ROUTE_132
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute132_WaterMonsInfo
	.4byte NULL
	.4byte gRoute132_FishingMonsInfo

	map ROUTE_133
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute133_WaterMonsInfo
	.4byte NULL
	.4byte gRoute133_FishingMonsInfo

	map ROUTE_134
	.2byte 0 @ padding
	.4byte NULL
	.4byte gRoute134_WaterMonsInfo
	.4byte NULL
	.4byte gRoute134_FishingMonsInfo

	map ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
	.2byte 0 @ padding
	.4byte NULL
	.4byte gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo
	.4byte NULL
	.4byte gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo

	map SEAFLOOR_CAVERN_ROOM_1
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room1_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ROOM_2
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room2_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ROOM_3
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room3_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ROOM_4
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room4_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ROOM_5
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room5_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ROOM_6
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room6_LandMonsInfo
	.4byte gSeafloorCavern_Room6_WaterMonsInfo
	.4byte NULL
	.4byte gSeafloorCavern_Room6_FishingMonsInfo

	map SEAFLOOR_CAVERN_ROOM_7
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room7_LandMonsInfo
	.4byte gSeafloorCavern_Room7_WaterMonsInfo
	.4byte NULL
	.4byte gSeafloorCavern_Room7_FishingMonsInfo

	map SEAFLOOR_CAVERN_ROOM_8
	.2byte 0 @ padding
	.4byte gSeafloorCavern_Room8_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SEAFLOOR_CAVERN_ENTRANCE
	.2byte 0 @ padding
	.4byte NULL
	.4byte gSeafloorCavern_Entrance_WaterMonsInfo
	.4byte NULL
	.4byte gSeafloorCavern_Entrance_FishingMonsInfo

	map CAVE_OF_ORIGIN_ENTRANCE
	.2byte 0 @ padding
	.4byte gCaveOfOrigin_Entrance_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map CAVE_OF_ORIGIN_1F
	.2byte 0 @ padding
	.4byte gCaveOfOrigin_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP_1
	.2byte 0 @ padding
	.4byte gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP_2
	.2byte 0 @ padding
	.4byte gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP_3
	.2byte 0 @ padding
	.4byte gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map NEW_MAUVILLE_ENTRANCE
	.2byte 0 @ padding
	.4byte gNewMauville_Entrance_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SAFARI_ZONE_SOUTHWEST
	.2byte 0 @ padding
	.4byte gSafariZone_Southwest_LandMonsInfo
	.4byte gSafariZone_Southwest_WaterMonsInfo
	.4byte NULL
	.4byte gSafariZone_Southwest_FishingMonsInfo

	map SAFARI_ZONE_NORTH
	.2byte 0 @ padding
	.4byte gSafariZone_North_LandMonsInfo
	.4byte NULL
	.4byte gSafariZone_North_RockSmashMonsInfo
	.4byte NULL

	map SAFARI_ZONE_NORTHWEST
	.2byte 0 @ padding
	.4byte gSafariZone_Northwest_LandMonsInfo
	.4byte gSafariZone_Northwest_WaterMonsInfo
	.4byte NULL
	.4byte gSafariZone_Northwest_FishingMonsInfo

	map VICTORY_ROAD_B1F
	.2byte 0 @ padding
	.4byte gVictoryRoad_B1F_LandMonsInfo
	.4byte NULL
	.4byte gVictoryRoad_B1F_RockSmashMonsInfo
	.4byte NULL

	map VICTORY_ROAD_B2F
	.2byte 0 @ padding
	.4byte gVictoryRoad_B2F_LandMonsInfo
	.4byte gVictoryRoad_B2F_WaterMonsInfo
	.4byte NULL
	.4byte gVictoryRoad_B2F_FishingMonsInfo

	map METEOR_FALLS_1F_1R
	.2byte 0 @ padding
	.4byte gMeteorFalls_1F_1R_LandMonsInfo
	.4byte gMeteorFalls_1F_1R_WaterMonsInfo
	.4byte NULL
	.4byte gMeteorFalls_1F_1R_FishingMonsInfo

	map METEOR_FALLS_1F_2R
	.2byte 0 @ padding
	.4byte gMeteorFalls_1F_2R_LandMonsInfo
	.4byte gMeteorFalls_1F_2R_WaterMonsInfo
	.4byte NULL
	.4byte gMeteorFalls_1F_2R_FishingMonsInfo

	map METEOR_FALLS_B1F_1R
	.2byte 0 @ padding
	.4byte gMeteorFalls_B1F_1R_LandMonsInfo
	.4byte gMeteorFalls_B1F_1R_WaterMonsInfo
	.4byte NULL
	.4byte gMeteorFalls_B1F_1R_FishingMonsInfo

	map SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM
	.2byte 0 @ padding
	.4byte gShoalCave_LowTideStairsRoom_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SHOAL_CAVE_LOW_TIDE_LOWER_ROOM
	.2byte 0 @ padding
	.4byte gShoalCave_LowTideLowerRoom_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	.2byte 0 @ padding
	.4byte gShoalCave_LowTideInnerRoom_LandMonsInfo
	.4byte gShoalCave_LowTideInnerRoom_WaterMonsInfo
	.4byte NULL
	.4byte gShoalCave_LowTideInnerRoom_FishingMonsInfo

	map SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
	.2byte 0 @ padding
	.4byte gShoalCave_LowTideEntranceRoom_LandMonsInfo
	.4byte gShoalCave_LowTideEntranceRoom_WaterMonsInfo
	.4byte NULL
	.4byte gShoalCave_LowTideEntranceRoom_FishingMonsInfo

	map LILYCOVE_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gLilycoveCity_WaterMonsInfo
	.4byte NULL
	.4byte gLilycoveCity_FishingMonsInfo

	map DEWFORD_TOWN
	.2byte 0 @ padding
	.4byte NULL
	.4byte gDewfordTown_WaterMonsInfo
	.4byte NULL
	.4byte gDewfordTown_FishingMonsInfo

	map SLATEPORT_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gSlateportCity_WaterMonsInfo
	.4byte NULL
	.4byte gSlateportCity_FishingMonsInfo

	map MOSSDEEP_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gMossdeepCity_WaterMonsInfo
	.4byte NULL
	.4byte gMossdeepCity_FishingMonsInfo

	map PACIFIDLOG_TOWN
	.2byte 0 @ padding
	.4byte NULL
	.4byte gPacifidlogTown_WaterMonsInfo
	.4byte NULL
	.4byte gPacifidlogTown_FishingMonsInfo

	map EVER_GRANDE_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gEverGrandeCity_WaterMonsInfo
	.4byte NULL
	.4byte gEverGrandeCity_FishingMonsInfo

	map PETALBURG_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gPetalburgCity_WaterMonsInfo
	.4byte NULL
	.4byte gPetalburgCity_FishingMonsInfo

	map UNDERWATER_1
	.2byte 0 @ padding
	.4byte NULL
	.4byte gUnderwater1_WaterMonsInfo
	.4byte NULL
	.4byte NULL

	map SHOAL_CAVE_LOW_TIDE_ICE_ROOM
	.2byte 0 @ padding
	.4byte gShoalCave_LowTideIceRoom_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SKY_PILLAR_1F
	.2byte 0 @ padding
	.4byte gSkyPillar_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SOOTOPOLIS_CITY
	.2byte 0 @ padding
	.4byte NULL
	.4byte gSootopolisCity_WaterMonsInfo
	.4byte NULL
	.4byte gSootopolisCity_FishingMonsInfo

	map SKY_PILLAR_3F
	.2byte 0 @ padding
	.4byte gSkyPillar_3F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SKY_PILLAR_5F
	.2byte 0 @ padding
	.4byte gSkyPillar_5F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map SAFARI_ZONE_SOUTHEAST
	.2byte 0 @ padding
	.4byte gSafariZone_Southeast_LandMonsInfo
	.4byte gSafariZone_Southeast_WaterMonsInfo
	.4byte NULL
	.4byte gSafariZone_Southeast_FishingMonsInfo

	map SAFARI_ZONE_NORTHEAST
	.2byte 0 @ padding
	.4byte gSafariZone_Northeast_LandMonsInfo
	.4byte NULL
	.4byte gSafariZone_Northeast_RockSmashMonsInfo
	.4byte NULL

	map MAGMA_HIDEOUT_1F
	.2byte 0 @ padding
	.4byte gMagmaHideout_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_2F_1R
	.2byte 0 @ padding
	.4byte gMagmaHideout_2F_1R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_2F_2R
	.2byte 0 @ padding
	.4byte gMagmaHideout_2F_2R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_3F_1R
	.2byte 0 @ padding
	.4byte gMagmaHideout_3F_1R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_3F_2R
	.2byte 0 @ padding
	.4byte gMagmaHideout_3F_2R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_4F
	.2byte 0 @ padding
	.4byte gMagmaHideout_4F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_3F_3R
	.2byte 0 @ padding
	.4byte gMagmaHideout_3F_3R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MAGMA_HIDEOUT_2F_3R
	.2byte 0 @ padding
	.4byte gMagmaHideout_2F_3R_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MIRAGE_TOWER_1F
	.2byte 0 @ padding
	.4byte gMirageTower_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MIRAGE_TOWER_2F
	.2byte 0 @ padding
	.4byte gMirageTower_2F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MIRAGE_TOWER_3F
	.2byte 0 @ padding
	.4byte gMirageTower_3F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map MIRAGE_TOWER_4F
	.2byte 0 @ padding
	.4byte gMirageTower_4F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map DESERT_UNDERPASS
	.2byte 0 @ padding
	.4byte gDesertUnderpass_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ARTISAN_CAVE_B1F
	.2byte 0 @ padding
	.4byte gArtisanCave_B1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ARTISAN_CAVE_1F
	.2byte 0 @ padding
	.4byte gArtisanCave_1F_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave1_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave2_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave3_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave4_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave5_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave6_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave7_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave8_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map ALTERING_CAVE
	.2byte 0 @ padding
	.4byte gAlteringCave9_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	map METEOR_FALLS_STEVENS_CAVE
	.2byte 0 @ padding
	.4byte gMeteorFalls_StevensCave_LandMonsInfo
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.byte -1
	.byte -1
	.2byte 0 @ padding
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
