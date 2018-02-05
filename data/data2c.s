#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2

@ 831C898
	.include "data/battle_moves.inc"

@ 0x31d93c
@ unreferenced unknown data
	.byte 0x34, 0x00, 0x10, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00

@ 831D94C
	.include "data/pokedex_order.inc"
