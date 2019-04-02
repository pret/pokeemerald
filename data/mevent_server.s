	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gText_CanceledReadingCard:: @ 82F257C
	.string "Canceled reading\nthe Card.$"

	.align 2
gUnknown_082F2598:: @ 82F2598
	.4byte  2, 16
	.4byte  4, 0

	.align 2
gUnknown_082F25A8:: @ 82F25A8
	.4byte  8, 0
	.4byte  3, 0
	.4byte  2, 16
	.4byte  4, 0

	.align 2
gUnknown_082F25C8:: @ 82F25C8
	.4byte 20, 0
	.4byte  1, 10

	.align 2
gUnknown_082F25D8:: @ 82F25D8
	.4byte 20, 0
	.4byte  1, 11

	.align 2
gUnknown_082F25E8:: @ 82F25E8
	.4byte 20, 0
	.4byte  1, 0

	.align 2
gUnknown_082F25F8:: @ 82F25F8
	.4byte  2, 22
	.4byte 10, 0
	.4byte  2, 25
	.4byte 17, 0
	.4byte 20, 0
	.4byte  1, 2

	.align 2
gUnknown_082F2628:: @ 82F2628
	.4byte  2, 23
	.4byte  9, 0
	.4byte  3, 0
	.4byte  2, 16
	.4byte  4, 0

	.align 2
gUnknown_082F2650:: @ 82F2650
	.4byte 20, 0
	.4byte  1, 7

	.align 2
gUnknown_082F2660:: @ 82F2660
	.4byte 20, 0
	.4byte  1, 3

	.align 2
gUnknown_082F2670:: @ 82F2670
	.4byte 13, 0
	.4byte 14, 0
	.4byte  3, 0
	.4byte  2, 16
	.4byte  4, 0

	.align 2
gUnknown_082F2698:: @ 82F2698
	.4byte 20, 0
	.4byte  1, 9

	.align 2
gUnknown_082F26A8:: @ 82F26A8
	.4byte 20, 0
	.4byte  1, 5

	.align 2
gUnknown_082F26B8:: @ 82F26B8
	.4byte  2, 21
	.4byte 12, 0
	.4byte 20, 0
	.4byte  1, 14
	.4byte  2, 21
	.4byte 12, 0
	.4byte 20, 0
	.4byte  1, 13

	.align 2
gUnknown_082F26F8:: @ 82F26F8
    .4byte 18, 0x10, gUnknown_082F25C8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x0a, NULL
	.4byte 18, 0x10, gUnknown_082F25D8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x0b, NULL
	.4byte 18, 0x10, gUnknown_082F2698
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x09, NULL

	.align 2
gUnknown_082F2788:: @ 82F2788
	.4byte 18, 0x20, gUnknown_082F26B8
	.4byte  1, 0x00, NULL
	.4byte 20, 0x1b, gText_CanceledReadingCard
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x09, NULL

	.align 2
gUnknown_082F27D0:: @ 82F27D0
	.4byte 18, 0x10, gUnknown_082F2650
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x07, NULL

	.align 2
gUnknown_082F2800:: @ 82F2800
	.4byte 18, 0x28, gUnknown_082F2628
	.4byte  1, 0x00, NULL
	.4byte 14, 0x00, NULL
	.4byte  1, 0x00, NULL
	.4byte  2, 0x13, NULL
	.4byte  8, 0x00, NULL
	.4byte  4, 0x01, gUnknown_082F27D0
	.4byte 18, 0x10, gUnknown_082F2660
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x03, NULL

	.align 2
gUnknown_082F2884:: @ 82F2884
	.4byte 18, 0x30, gUnknown_082F25F8
	.4byte  1, 0x00, NULL
	.4byte 13, 0x00, NULL
	.4byte  1, 0x00, NULL
	.4byte 15, 0x00, NULL
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x02, NULL

	.align 2
gUnknown_082F28E4:: @ 82F28E4
	.4byte 18, 0x28, gUnknown_082F2670
	.4byte  1, 0x00, NULL
	.4byte  2, 0x13, NULL
	.4byte  8, 0x00, NULL
	.4byte  4, 0x00, gUnknown_082F2884
	.4byte  3, 0x00, gUnknown_082F2788

	.align 2
gUnknown_082F292C:: @ 82F292C
	.4byte 18, 0x10, gUnknown_082F26A8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x05, NULL
	.4byte 18, 0x10, gUnknown_082F25E8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x14, NULL
	.4byte  0, 0x00, NULL

	.align 2
s_mevent_wonder_news:: @ 82F298C
	.4byte 27, 0x00, NULL
	.4byte 18, 0x20, gUnknown_082F25A8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x11, NULL
	.4byte  5, 0x00, NULL
	.4byte 30, 0x00, NULL
	.4byte  4, 0x00, gUnknown_082F26F8
	.4byte  3, 0x00, gUnknown_082F2800

	.align 2
s_mevent_wonder_card:: @ 82F29EC
	.4byte 26, 0x00, NULL
	.4byte 28, 0x00, NULL
	.4byte 18, 0x20, gUnknown_082F25A8
	.4byte  1, 0x00, NULL
	.4byte  2, 0x11, NULL
	.4byte  5, 0x00, NULL
	.4byte  6, 0x00, NULL
	.4byte  4, 0x00, gUnknown_082F26F8
	.4byte  7, 0x00, NULL
	.4byte  4, 0x02, gUnknown_082F28E4
	.4byte  4, 0x00, gUnknown_082F2884
	.4byte  3, 0x00, gUnknown_082F292C
