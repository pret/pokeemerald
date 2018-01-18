#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

@ 85507E4
	.include "data/wild_mons.inc"

gBattlePyramidPlaceholders_1:: @ 55370C
	wild_mon SPECIES_BULBASAUR, 5
	wild_mon SPECIES_BULBASAUR, 5
	wild_mon SPECIES_BULBASAUR, 5
	wild_mon SPECIES_BULBASAUR, 5
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_CHARMANDER, 5
	
gBattlePyramidPlaceholders_1Info:: @ 55373C
	.4byte 4
	.4byte gBattlePyramidPlaceholders_1
	
gBattlePyramidPlaceholders_2:: @ 553744
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_IVYSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMANDER, 5
	
gBattlePyramidPlaceholders_2Info:: @ 553774
	.4byte 4
	.4byte gBattlePyramidPlaceholders_2
	
gBattlePyramidPlaceholders_3:: @ 55377C
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_VENUSAUR, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARIZARD, 5
	
gBattlePyramidPlaceholders_3Info:: @ 5537AC
	.4byte 4
	.4byte gBattlePyramidPlaceholders_3
	
gBattlePyramidPlaceholders_4:: @ 5537B4
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMANDER, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_SQUIRTLE, 5
	
gBattlePyramidPlaceholders_4Info:: @ 5537E4
	.4byte 4
	.4byte gBattlePyramidPlaceholders_4
	
gBattlePyramidPlaceholders_5:: @ 5537EC
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	
gBattlePyramidPlaceholders_5Info:: @ 55381C
	.4byte 4
	.4byte gBattlePyramidPlaceholders_5
	
gBattlePyramidPlaceholders_6:: @ 553824
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	
gBattlePyramidPlaceholders_6Info:: @ 553854
	.4byte 4
	.4byte gBattlePyramidPlaceholders_6

gBattlePyramidPlaceholders_7:: @ 55385C
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_WARTORTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_SQUIRTLE, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARIZARD, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	wild_mon SPECIES_CHARMELEON, 5
	
gBattlePyramidPlaceholders_7Info:: @ 55388C
	.4byte 8
	.4byte gBattlePyramidPlaceholders_7

gBattlePyramidWildMonHeaders:: @ 8553894
	.byte 0, 1
	.2byte 0
	.4byte gBattlePyramidPlaceholders_1Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 2
	.2byte 0
	.4byte gBattlePyramidPlaceholders_2Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 3
	.2byte 0
	.4byte gBattlePyramidPlaceholders_3Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 4
	.2byte 0
	.4byte gBattlePyramidPlaceholders_4Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 5
	.2byte 0
	.4byte gBattlePyramidPlaceholders_5Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 6
	.2byte 0
	.4byte gBattlePyramidPlaceholders_6Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 7
	.2byte 0
	.4byte gBattlePyramidPlaceholders_7Info
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.2byte 0xFFFF
	.2byte 0
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL
	
gBattlePikeMons_1:: @ 8553934
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_DUSCLOPS, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	
gBattlePikeMonsInfo_1:: @ 8553964
	.4byte 10
	.4byte gBattlePikeMons_1
	
gBattlePikeMons_2:: @ 855396C
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_ELECTRODE, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	
gBattlePikeMonsInfo_2:: @ 855399C
	.4byte 10
	.4byte gBattlePikeMons_2
	
gBattlePikeMons_3:: @ 85539A4
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_BRELOOM, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	
gBattlePikeMonsInfo_3:: @ 85539D4
	.4byte 10
	.4byte gBattlePikeMons_3
	
gBattlePikeMons_4:: @ 85539DC
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_WOBBUFFET, 5
	wild_mon SPECIES_SEVIPER, 5
	wild_mon SPECIES_MILOTIC, 5
	
gBattlePikeMonsInfo_4:: @ 8553A0C
	.4byte 10
	.4byte gBattlePikeMons_4

gBattlePikeWildMonHeaders:: @ 8553A14
	.byte 0, 1
	.2byte 0
	.4byte gBattlePikeMonsInfo_1
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 2
	.2byte 0
	.4byte gBattlePikeMonsInfo_2
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 3
	.2byte 0
	.4byte gBattlePikeMonsInfo_3
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.byte 0, 4
	.2byte 0
	.4byte gBattlePikeMonsInfo_4
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.2byte 0xFFFF
	.2byte 0
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte NULL

gWildFeebasRoute119Data:: @ 8553A78
	wild_mon SPECIES_FEEBAS, 20, 25

gRoute119WaterTileData:: @ 8553A7C
	.2byte 0, 0x2D, 0, 0x2E, 0x5B, 0x83, 0x5C, 0x8B, 0x12A, 0
