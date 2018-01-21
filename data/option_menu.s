    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0855C604:: @ 855C604
	.incbin "graphics/interface/855C604.gbapal"
	.incbin "graphics/interface/855C624.bin"

gUnknown_0855C664:: @ 855C664
	.4byte gUnknown_085EE590
	.4byte gUnknown_085EE59B
	.4byte gUnknown_085EE5A8
	.4byte gUnknown_085EE5B5
	.4byte gUnknown_085EE5C8
	.4byte gUnknown_085EE5BB
	.4byte gUnknown_085EE5C1

gUnknown_0855C680:: @ 855C680
	window_template 1, 2, 1, 0x1A, 2, 1, 2
	window_template 0, 2, 5, 0x1A, 14, 1, 0x36
	null_window_template

gUnknown_0855C698:: @ 855C698
	.4byte 0x1E5
	.4byte 0x11F4

gUnknown_0855C6A0:: @ 855C6A0
	.2byte 0x7E51, 0
