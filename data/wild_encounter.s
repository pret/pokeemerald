#include "constants/species.h"
    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

@ 85507E4
	.include "data/wild_mons.inc"

	.incbin "baserom.gba", 0x55370c, 0x188

gBattlePyramidWildMonHeaders:: @ 8553894
	.incbin "baserom.gba", 0x553894, 0x180

gBattlePikeWildMonHeaders:: @ 8553A14
	.incbin "baserom.gba", 0x553a14, 0x64

gWildFeebasRoute119Data:: @ 8553A78
	.incbin "baserom.gba", 0x553a78, 0x4

gRoute119WaterTileData:: @ 8553A7C
	.incbin "baserom.gba", 0x553a7c, 0x14
