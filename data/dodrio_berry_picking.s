	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata



	.align 2
gUnknown_082FB3DC:: @ 82FB3DC
	.4byte gText_1Colon
	.4byte gText_2Colon
	.4byte gText_3Colon
	.4byte gText_4Colon
	.4byte gText_5Colon

	.align 2
gUnknown_082FB3F0:: @ 82FB3F0
	.2byte 0x005c, 0x0084, 0x00ac, 0x00d4

gUnknown_082FB3F8:: @ 82FB3F8
	.2byte 0x0021, 0x0031, 0x0041, 0x0051, 0x0061

gUnknown_082FB402:: @ 82FB402
	.2byte 0x0011, 0x0021, 0x0031, 0x0041, 0x0051

	.align 2
gUnknown_082FB40C:: @ 82FB40C
	.4byte 0x00000000, sub_8029338
	.4byte 0x00000001, sub_8029440
	.4byte 0x00000002, sub_802988C
	.4byte 0x00000003, sub_802A010
	.4byte 0x00000004, sub_802A380
	.4byte 0x00000005, sub_802A454
	.4byte 0x00000006, sub_802A534
	.4byte 0x00000007, sub_802A588
	.4byte 0x00000008, unused_0
	.4byte 0x00000009, nullsub_16

	.align 2
gUnknown_082FB45C:: @ 82FB45C
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00
