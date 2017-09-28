	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 858C2B4
	.include "data/contest_moves.inc"

@ 858CDCC
	.include "data/contest_effects.inc"

@ A lookup table with a 1 for each combo starter ID and a 0 for ID 0,
@ which means "not a combo starter move".
gComboStarterLookupTable:: @ 858CE8C
	.byte 0
	.rept 62
	.byte 1
	.endr

	.align 2
@ 858CECC
	.include "data/contest_effect_function_table.inc"
