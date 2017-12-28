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
gCaveTransitionPalette_White:: @ 85B2850
	.incbin "graphics/misc/cave_transition_white.gbapal"

	.align 2
gCaveTransitionPalette_Black:: @ 85B2870
	.incbin "graphics/misc/cave_transition_black.gbapal"

	.align 2
gUnknown_085B2890:: @ 85B2890
	.incbin "graphics/misc/85B2890.gbapal"

	.align 2
gUnknown_085B28A0:: @ 85B28A0
	.incbin "graphics/misc/85B28A0.gbapal"

	.align 2
gCaveTransitionTilemap:: @ 85B28B0
	.incbin "graphics/misc/cave_transition_map.bin.lz"

	.align 2
gCaveTransitionTiles:: @ 85B2A90
	.incbin "graphics/misc/cave_transition.4bpp.lz"
