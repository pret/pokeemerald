    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0
gUnknown_08339D3C:: @ 8339D3C
	.4byte 0xFFFFFF, 0xFFFFFFFF, 0x4B0, 0xE10, 0x4B0, 0x960, 0x32, 0x50, 0xFFFFFFD4, 0x2C

gUnknown_08339D64:: @ 8339D64
	.4byte 0, 0
	.4byte 0, 1
	.4byte 0, -1
	.4byte -1, 0
	.4byte 1, 0
	.4byte -1, 1
	.4byte 1, 1
	.4byte -1, -1
	.4byte 1, -1

gUnknown_08339DAC:: @ 8339DAC
	.4byte 0x1F8
	.4byte 0x11D1
	.4byte 0x21C2
	.4byte 0x31E3

gUnknown_08339DBC:: @ 8339DBC
	.4byte REG_WIN0H
	.4byte 0xa2600001
	.byte 1, 0

	.align 2
gUnknown_08339DC8:: @ 8339DC8
	.4byte sub_80879D8
	.4byte sub_80879F8
	.4byte sub_80879FC

gUnknown_08339DD4:: @ 8339DD4
	.4byte sub_8087A1C
	.4byte sub_8087A20
	.4byte sub_8087A20
	.4byte sub_8087A20
	.4byte sub_8087A20
	.4byte sub_8087A1C
	.4byte sub_8087A1C
	.4byte sub_8087A88
	.4byte sub_8087A88
	.4byte sub_8087A88
	.4byte sub_8087A88

gUnknown_08339E00:: @ 8339E00
	.4byte sub_8087AA0
	.4byte sub_8087AA8
