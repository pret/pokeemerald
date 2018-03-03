	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2, 0
gUnknown_0862AD54:: @ 862AD54
	.incbin "graphics/battle_transitions/frontier_transition.4bpp.lz"

gUnknown_0862AF30:: @ 862AF30
	.incbin "graphics/battle_transitions/frontier_transition.bin"

gUnknown_0862B0DC:: @ 862B0DC
	.incbin "graphics/battle_transitions/frontier_transition_circles.4bpp.lz"

gUnknown_0862B53C:: @ 862B53C
	.incbin "graphics/battle_transitions/frontier_transition.gbapal"
	.space 0x1c0
