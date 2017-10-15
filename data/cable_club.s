    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

	.align 2
gUnknown_08550594:: @ 8550594
	window_template 0x00, 0x10, 0x0b, 0x0b, 0x02, 0x0f, 0x0125

	.align 2
gUnknown_0855059C:: @ 855059C
	.4byte gText_BronzeCard
	.4byte gText_CopperCard
	.4byte gText_SilverCard
	.4byte gText_GoldCard
