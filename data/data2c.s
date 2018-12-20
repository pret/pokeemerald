#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gBattleIntroSlideScanlineEffectParams:: @ 831AC70
	.4byte REG_BG3HOFS
	.4byte ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1
	.4byte 1

	.align 2
gUnknown_0831AC7C:: @ 831AC7C
	.4byte REG_BG3HOFS
	.4byte ((DMA_ENABLE | DMA_START_HBLANK | DMA_32BIT | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1
	.4byte 1

	.align 2
gUnknown_0831AC88:: @ 831AC88
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8038528

gText_ShedinjaJapaneseName:: @ 831ACA0
	.string "ヌケニン$" @ Nukenin
    
	.align 2
gUnknown_0831ACA8:: @ 831ACA8
	.2byte 0x0100
	.2byte 0xC000
	.2byte 0x0800

	.align 2
gUnknown_0831ACB0:: @ 831ACB0
	.2byte 0x0100
	.2byte 0xC000
	.2byte 0x2800

	.align 2
gUnknown_0831ACB8:: @ 831ACB8
	.2byte 0x0000, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_0831ACC0:: @ 831ACC0
	.4byte gUnknown_0831ACB8

	.align 2
gUnknown_0831ACC4:: @ 831ACC4
	.2byte 0xfff0, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000, 0x3c00, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_0831ACDC:: @ 831ACDC
	.4byte gUnknown_0831ACC4
