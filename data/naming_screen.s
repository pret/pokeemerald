	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0858BD78:: @ 858BD78
	.incbin "baserom.gba", 0x58bd78, 0x40

gUnknown_0858BDB8:: @ 858BDB8
@ replacing .incbin "baserom.gba", 0x0058bdb8, 0x10
.4byte 0x8273216
.4byte 0x8273256
.4byte 0x8273296
.4byte 0x82732d9

gUnknown_0858BDC8:: @ 858BDC8
@ replacing .incbin "baserom.gba", 0x0058bdc8, 0x38
.string "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!$"
.string "  "

gUnknown_0858BE00:: @ 858BE00
	.incbin "baserom.gba", 0x58be00, 0x10

gUnknown_0858BE10:: @ 858BE10
	.incbin "baserom.gba", 0x58be10, 0x30

gUnknown_0858BE40:: @ 858BE40
@ replacing .incbin "baserom.gba", 0x0058be40, 0x60
.string "abcdef .ghijkl ,mnopqrs tuvwxyz ABCDEF .GHIJKL ,MNOPQRS TUVWXYZ 01234   56789   !?♂♀/-  …“”‘’   "

gUnknown_0858BEA0:: @ 858BEA0
@ replacing .incbin "baserom.gba", 0x0058bea0, 0x3
.byte 0x08, 0x08, 0x06

gUnknown_0858BEA3:: @ 858BEA3
@ replacing .incbin "baserom.gba", 0x0058bea3, 0x18
.byte 0x00, 0x0c, 0x18, 0x38, 0x44, 0x50, 0x5c, 0x7b, 0x00, 0x0c, 0x18, 0x38, 0x44, 0x50, 0x5c, 0x7b, 0x00, 0x16, 0x2c, 0x42, 0x58, 0x6e, 0x00, 0x00

gUnknown_0858BEBB:: @ 858BEBB
@ replacing .incbin "baserom.gba", 0x0058bebb, 0x3
.byte 0x00, 0x02, 0x01

gUnknown_0858BEBE:: @ 858BEBE
@ replacing .incbin "baserom.gba", 0x0058bebe, 0x3
.byte 0x01, 0x00, 0x02

gUnknown_0858BEC1:: @ 858BEC1
@ replacing .incbin "baserom.gba", 0x0058bec1, 0x3
.byte 0x02, 0x01, 0x00

gUnknown_0858BEC4:: @ 858BEC4
@ replacing .incbin "baserom.gba", 0x0058bec4, 0x10
.4byte sub_80E37B4
.4byte sub_80E37DC
.4byte sub_80E3870
.4byte sub_80E3904

gUnknown_0858BED4:: @ 858BED4
@ replacing .incbin "baserom.gba", 0x0058bed4, 0x8
.2byte 0x0000, 0xfffc, 0xfffe, 0xffff

gUnknown_0858BEDC:: @ 858BEDC
@ replacing .incbin "baserom.gba", 0x0058bedc, 0x8
.2byte 0x0002, 0x0003, 0x0002, 0x0001

gUnknown_0858BEE4:: @ 858BEE4
@ replacing .incbin "baserom.gba", 0x0058bee4, 0x4
.byte 0x01, 0x02, 0x03, 0x00

gUnknown_0858BEE8:: @ 858BEE8
@ replacing .incbin "baserom.gba", 0x0058bee8, 0x10
.4byte sub_80E40AC
.4byte sub_80E4100
.4byte sub_80E4104
.4byte sub_80E4178

gUnknown_0858BEF8:: @ 858BEF8
@ replacing .incbin "baserom.gba", 0x0058bef8, 0x6
.2byte 0x0001, 0x0003, 0x0002

gUnknown_0858BEFE:: @ 858BEFE
@ replacing .incbin "baserom.gba", 0x0058befe, 0x6
.2byte 0x0004, 0x0006, 0x0005

gUnknown_0858BF04:: @ 858BF04
@ replacing .incbin "baserom.gba", 0x0058bf04, 0x14
.4byte TaskDummy2
.4byte sub_80E4384
.4byte sub_80E43E0
.4byte sub_80E4420
.4byte sub_80E447C

gUnknown_0858BF18:: @ 858BF18
@ replacing .incbin "baserom.gba", 0x0058bf18, 0x10
.4byte sub_80E450C
.4byte sub_80E4558
.4byte sub_80E4580
.4byte sub_80E45A4

gUnknown_0858BF28:: @ 858BF28
@ replacing .incbin "baserom.gba", 0x0058bf28, 0xc
.4byte sub_80E468C
.4byte sub_80E4692
.4byte sub_80E46E8

gUnknown_0858BF34:: @ 858BF34
	.incbin "baserom.gba", 0x58bf34, 0xa

gUnknown_0858BF3E:: @ 858BF3E
	.incbin "baserom.gba", 0x58bf3e, 0xa

gUnknown_0858BF48:: @ 858BF48
	.incbin "baserom.gba", 0x58bf48, 0x8

gUnknown_0858BF50:: @ 858BF50
	.incbin "baserom.gba", 0x58bf50, 0x8

gUnknown_0858BF58:: @ 858BF58
@ replacing .incbin "baserom.gba", 0x0058bf58, 0x14
.4byte sub_80E4894
.4byte sub_80E4894
.4byte sub_80E48E8
.4byte sub_80E48E8
.4byte sub_80E4894

gUnknown_0858BF6C:: @ 858BF6C
@ replacing .incbin "baserom.gba", 0x0058bf6c, 0x8
.4byte TaskDummy3
.4byte sub_80E49BC

gUnknown_0858BF74:: @ 858BF74
	.incbin "baserom.gba", 0x58bf74, 0x14

gUnknown_0858BF88:: @ 858BF88
@ replacing .incbin "baserom.gba", 0x0058bf88, 0x4
.byte 0xee, 0xdd, 0xff, 0x00

gUnknown_0858BF8C:: @ 858BF8C
@ replacing .incbin "baserom.gba", 0x0058bf8c, 0xc
.4byte 0x858bf80
.4byte 0x858bf7c
.4byte 0x858bf84

gUnknown_0858BF98:: @ 858BF98
@ replacing .incbin "baserom.gba", 0x0058bf98, 0xc
.4byte 0x8dd4620
.4byte 0x8dd46e0
.4byte 0x8dd47a0

gUnknown_0858BFA4:: @ 858BFA4
	.incbin "baserom.gba", 0x58bfa4, 0x34

gUnknown_0858BFD8:: @ 858BFD8
@ replacing .incbin "baserom.gba", 0x0058bfd8, 0x14
.4byte 0x858bfa8
.4byte 0x858bfb4
.4byte 0x858bfc0
.4byte 0x858bfc0
.4byte 0x858bfcc

gUnknown_0858BFEC:: @ 858BFEC
	.incbin "baserom.gba", 0x58bfec, 0x64
	
gUnknown_0858C050:: @ 858C050
	.incbin "baserom.gba", 0x58c050, 0x8

gUnknown_0858C058:: @ 858C058
	.incbin "baserom.gba", 0x58c058, 0x18

gUnknown_0858C070:: @ 858C070
	.incbin "baserom.gba", 0x58c070, 0x8

gUnknown_0858C078:: @ 858C078
	.incbin "baserom.gba", 0x58c078, 0x48

gUnknown_0858C0C0:: @ 858C0C0
	.incbin "baserom.gba", 0x58c0c0, 0x18

gUnknown_0858C0D8:: @ 858C0D8
	.incbin "baserom.gba", 0x58c0d8, 0x18

gUnknown_0858C0F0:: @ 858C0F0
	.incbin "baserom.gba", 0x58c0f0, 0x18

gUnknown_0858C108:: @ 858C108
	.incbin "baserom.gba", 0x58c108, 0x18

gUnknown_0858C120:: @ 858C120
	.incbin "baserom.gba", 0x58c120, 0x18

gUnknown_0858C138:: @ 858C138
	.incbin "baserom.gba", 0x58c138, 0x18

gUnknown_0858C150:: @ 858C150
	.incbin "baserom.gba", 0x58c150, 0x18

gUnknown_0858C168:: @ 858C168
	.incbin "baserom.gba", 0x58c168, 0x18

gUnknown_0858C180:: @ 858C180
	.incbin "baserom.gba", 0x58c180, 0x18

gUnknown_0858C198:: @ 858C198
@ replacing .incbin "baserom.gba", 0x0058c198, 0x30
.4byte 0x862b88d
.4byte 0x862b8ae
.4byte 0x862b8cf
.4byte 0x862b8f0
.4byte 0x862b911
.4byte 0x862b932
.4byte 0x862b953
.4byte 0x862b974
.4byte 0x862b995
.4byte 0x862b9ae
.4byte 0x862b9c7
.4byte 0x862b9e0

gUnknown_0858C1C8:: @ 858C1C8
	.incbin "baserom.gba", 0x58c1c8, 0x68

gUnknown_0858C230:: @ 858C230
	.incbin "baserom.gba", 0x58c230, 0x48


