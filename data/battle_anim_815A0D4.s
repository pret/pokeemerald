	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085CE004:: @ 85CE004
	.2byte 0x0000, 0x0004, 0x0010, 0x0004
	.2byte 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE01C:: @ 85CE01C
	.4byte gUnknown_085CE004

	.align 2
gUnknown_085CE020:: @ 85CE020
	spr_template 0x2799, 0x2799, gUnknown_08524A34, gUnknown_085CE01C, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
	spr_template 0x2720, 0x2720, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A0D4

	.align 2
	spr_template 0x2721, 0x2721, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A78AC

	.align 2
gUnknown_085CE068:: @ 85CE068
	.2byte 0x0000, 0x0028, 0x0010, 0x0008
	.2byte 0x0020, 0x0028, 0xffff, 0x0000

	.align 2
gUnknown_085CE078:: @ 85CE078
	.4byte gUnknown_085CE068

	.align 2
gUnknown_085CE07C:: @ 85CE07C
	spr_template 0x27ce, 0x27ce, gUnknown_08524914, gUnknown_085CE078, NULL, gDummySpriteAffineAnimTable, sub_80A77C8

	.align 2
	spr_template 0x27cf, 0x27cf, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A1B0

	.align 2
	spr_template 0x27cd, 0x27cd, gUnknown_08524974, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A254

	.align 2
gUnknown_085CE0C4:: @ 85CE0C4
	.2byte 0x0180, 0x0180, 0x0000, 0x0000
	.2byte 0xffe0, 0x0018, 0x0500, 0x0000
	.2byte 0x0018, 0xffe0, 0x0500, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085CE0E4:: @ 85CE0E4
	.2byte 0x0030, 0x0030, 0x0000, 0x0000
	.2byte 0x0020, 0x0020, 0x0600, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE0FC:: @ 85CE0FC
	.4byte gUnknown_085CE0C4
	.4byte gUnknown_085CE0E4

	.align 2
gUnknown_085CE104:: @ 85CE104
	spr_template 0x27cb, 0x27cb, gUnknown_08524AFC, gDummySpriteAnimTable, NULL, gUnknown_085CE0FC, sub_815A2F0

	.align 2
	spr_template 0x27a8, 0x27a8, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815A6C4

	.align 2
gUnknown_085CE134:: @ 85CE134
	.2byte 0x0000, 0x0003, 0x0010, 0x0003
	.2byte 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE14C:: @ 85CE14C
	.4byte gUnknown_085CE134

	.align 2
gUnknown_085CE150:: @ 85CE150
	spr_template 0x272b, 0x272b, gUnknown_08524914, gUnknown_085CE14C, NULL, gDummySpriteAffineAnimTable, sub_815A7B0

	.align 2
gUnknown_085CE168:: @ 85CE168
	.2byte 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE170:: @ 85CE170
	.4byte gUnknown_085CE168

	.align 2
gUnknown_085CE174:: @ 85CE174
	.2byte 0xfff9, 0xfff9, 0x10fd, 0x0000
	.2byte 0x0007, 0x0007, 0x1003, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE18C:: @ 85CE18C
	.4byte gUnknown_085CE174

	.align 2
gUnknown_085CE190:: @ 85CE190
	spr_template 0x27f4, 0x27f4, gUnknown_08524974, gUnknown_085CE170, NULL, gUnknown_085CE18C, sub_815A7EC

	.align 2
gUnknown_085CE1A8:: @ 85CE1A8
	.2byte 0x0000, 0x0008, 0x0010, 0x0010, 0x0020, 0x0004, 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE1BC:: @ 85CE1BC
	.4byte gUnknown_085CE1A8

	.align 2
gUnknown_085CE1C0:: @ 85CE1C0
	.2byte 0x0200, 0x0200, 0x0000, 0x0000
	.2byte 0xffe0, 0xffe0, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE1D8:: @ 85CE1D8
	.4byte gUnknown_085CE1C0

	.align 2
gUnknown_085CE1DC:: @ 85CE1DC
	spr_template 0x27d0, 0x27d0, gUnknown_085249D4, gUnknown_085CE1BC, NULL, gUnknown_085CE1D8, sub_815A8AC

	.align 2
gUnknown_085CE1F4:: @ 85CE1F4
	.2byte 0x0000, 0x0180, 0x0000, 0x0000
	.2byte 0x0010, 0x0000, 0x1400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE20C:: @ 85CE20C
	.2byte 0x0140, 0x0180, 0x0000, 0x0000
	.2byte 0xfff0, 0x0000, 0x1300, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE224:: @ 85CE224
	.4byte gUnknown_085CE1F4
	.4byte gUnknown_085CE20C

	.align 2
gUnknown_085CE22C:: @ 85CE22C
	spr_template 0x27f3, 0x27f3, gUnknown_085249DC, gDummySpriteAnimTable, NULL, gUnknown_085CE224, sub_815A934

	.align 2
	spr_template 0x2807, 0x2807, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815AAA4

	.align 2
	spr_template 0x2807, 0x2807, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_815ABD0

	.align 2
gUnknown_085CE274:: @ 85CE274
	.2byte 0x0000, 0x0002, 0x0008, 0x0002
	.2byte 0x0010, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_085CE284:: @ 85CE284
	.4byte gUnknown_085CE274

	.align 2
gUnknown_085CE288:: @ 85CE288
	spr_template 0x27f5, 0x27f5, gUnknown_08524934, gUnknown_085CE284, NULL, gDummySpriteAffineAnimTable, sub_815ACD0
	
gUnknown_085CE2A0:: @ 85CE2A0
	.incbin "baserom.gba", 0x5ce2a0, 0xb0

gUnknown_085CE350:: @ 85CE350
	.incbin "baserom.gba", 0x5ce350, 0x38

gUnknown_085CE388:: @ 85CE388
	.incbin "baserom.gba", 0x5ce388, 0x18

gUnknown_085CE3A0:: @ 85CE3A0
	.incbin "baserom.gba", 0x5ce3a0, 0x18

gUnknown_085CE3B8:: @ 85CE3B8
	.incbin "baserom.gba", 0x5ce3b8, 0x28

gUnknown_085CE3E0:: @ 85CE3E0
	.incbin "baserom.gba", 0x5ce3e0, 0x50

gUnknown_085CE430:: @ 85CE430
	.incbin "baserom.gba", 0x5ce430, 0x30

gUnknown_085CE460:: @ 85CE460
	.incbin "baserom.gba", 0x5ce460, 0x2c

gUnknown_085CE48C:: @ 85CE48C
	.incbin "baserom.gba", 0x5ce48c, 0x18

gUnknown_085CE4A4:: @ 85CE4A4
	.incbin "baserom.gba", 0x5ce4a4, 0x4

gUnknown_085CE4A8:: @ 85CE4A8
	.incbin "baserom.gba", 0x5ce4a8, 0x8

gUnknown_085CE4B0:: @ 85CE4B0
	.incbin "baserom.gba", 0x5ce4b0, 0x140

gUnknown_085CE5F0:: @ 85CE5F0
	.incbin "baserom.gba", 0x5ce5f0, 0x15c

gUnknown_085CE74C:: @ 85CE74C
	.incbin "baserom.gba", 0x5ce74c, 0x20

gUnknown_085CE76C:: @ 85CE76C
	.incbin "baserom.gba", 0x5ce76c, 0x18

gUnknown_085CE784:: @ 85CE784
	.incbin "baserom.gba", 0x5ce784, 0x68

gUnknown_085CE7EC:: @ 85CE7EC
	.incbin "baserom.gba", 0x5ce7ec, 0x60

gUnknown_085CE84C:: @ 85CE84C
	.incbin "baserom.gba", 0x5ce84c, 0x30

gUnknown_085CE87C:: @ 85CE87C
	.incbin "baserom.gba", 0x5ce87c, 0x14c

gUnknown_085CE9C8:: @ 85CE9C8
	.incbin "baserom.gba", 0x5ce9c8, 0x1e8

