	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_085A6B90:: @ 85A6B90
@ replacing .incbin "baserom.gba", 0x005a6b90, 0x20
    .align 2
    .byte 0x00, 0x01, 0x01, 0x12, 0x08, 0x0f
    .2byte 0x0001
    .align 2
    .byte 0x00, 0x01, 0x01, 0x0d, 0x12, 0x0d
    .2byte 0x0091
    .align 2
    .byte 0x00, 0x11, 0x01, 0x0c, 0x02, 0x0f
    .2byte 0x017b
    .align 2
    .byte 0x00, 0x10, 0x0d, 0x0d, 0x06, 0x0f
    .2byte 0x0193

gUnknown_085A6BB0:: @ 85A6BB0
@ replacing .incbin "baserom.gba", 0x005a6bb0, 0x20
	.2byte 0x532e, 0x7fff, 0x318c, 0x675a
	.2byte 0x739c, 0x6318, 0x0000, 0x77bd
	.2byte 0x6318, 0x4a52, 0x001f, 0x0016
	.2byte 0x631f, 0x7d4a, 0x58c6, 0x7f18

	.align 2
gUnknown_085A6BD0:: @ 85A6BD0
	.4byte 0x00000000
	.4byte sub_8127480
	.4byte sub_81274A0
	.2byte 0x0000, 0x0000
	.byte 0x00, 0x00, 0x08, 0x00
	.4byte 0x07003129

gUnknown_085A6BE8:: @ 85A6BE8
	.incbin "baserom.gba", 0x5a6be8, 0x5c8

gUnknown_085A71B0:: @ 85A71B0
	.incbin "baserom.gba", 0x5a71b0, 0xa0

gUnknown_085A7250:: @ 85A7250
	.incbin "baserom.gba", 0x5a7250, 0x3c

gUnknown_085A728C:: @ 85A728C
	.incbin "baserom.gba", 0x5a728c, 0x18

gUnknown_085A72A4:: @ 85A72A4
	.incbin "baserom.gba", 0x5a72a4, 0x18

gUnknown_085A72BC:: @ 85A72BC
	.incbin "baserom.gba", 0x5a72bc, 0x8

gUnknown_085A72C4:: @ 85A72C4
	.incbin "baserom.gba", 0x5a72c4, 0x8

gUnknown_085A72CC:: @ 85A72CC
	.incbin "baserom.gba", 0x5a72cc, 0x8

gUnknown_085A72D4:: @ 85A72D4
	.incbin "baserom.gba", 0x5a72d4, 0x10

gUnknown_085A72E4:: @ 85A72E4
	.incbin "baserom.gba", 0x5a72e4, 0x8

gUnknown_085A72EC:: @ 85A72EC
	.incbin "baserom.gba", 0x5a72ec, 0x8

gUnknown_085A72F4:: @ 85A72F4
	.incbin "baserom.gba", 0x5a72f4, 0x54

gUnknown_085A7348:: @ 85A7348
	.incbin "baserom.gba", 0x5a7348, 0x8

gUnknown_085A7350:: @ 85A7350
	.incbin "baserom.gba", 0x5a7350, 0x88

gUnknown_085A73D8:: @ 85A73D8
	.incbin "baserom.gba", 0x5a73d8, 0x8

gUnknown_085A73E0:: @ 85A73E0
	.incbin "baserom.gba", 0x5a73e0, 0x24

gUnknown_085A7404:: @ 85A7404
	.incbin "baserom.gba", 0x5a7404, 0x18

gUnknown_085A741C:: @ 85A741C
	.incbin "baserom.gba", 0x5a741c, 0x8
