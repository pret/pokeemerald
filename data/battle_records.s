
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085B3484:: @ 85B3484
	.incbin "graphics/unknown/unknown_5B3484.4bpp"

	.align 2
gUnknown_085B3544:: @ 85B3544
	.incbin "graphics/unknown/unknown_5B3484.gbapal"

	.align 2
gUnknown_085B3564:: @ 85B3564
	.incbin "graphics/unknown/unknown_5B3564.bin"

	.align 2
gUnknown_085B3D64:: @ 85B3D64
	.4byte 0x000001f0, 0x000031e7

	.align 2
gUnknown_085B3D6C:: @ 85B3D6C
	window_template 0x00, 0x02, 0x01, 0x1a, 0x12, 0x0f, 0x0014
	null_window_template

	.align 2
gUnknown_085B3D7C:: @ 85B3D7C
	window_template 0x00, 0x02, 0x01, 0x1a, 0x11, 0x0f, 0x0001

gUnknown_085B3D84:: @ 85B3D84
	.string "-------$"

gUnknown_085B3D8C:: @ 85B3D8C
	.string "----$"

