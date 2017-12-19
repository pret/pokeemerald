    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08587A6C:: @ 8587A6C
	.byte 0x24, 0x4c, 0x74, 0x9c

gUnknown_08587A70:: @ 8587A70
	.byte 0x24, 0x4c, 0x74, 0x9c

gUnknown_08587A74:: @ 8587A74
	.incbin "baserom.gba", 0x587a74, 0x5c

gUnknown_08587AD0:: @ 8587AD0
	.incbin "baserom.gba", 0x587ad0, 0x18

gUnknown_08587AE8:: @ 8587AE8
	.incbin "baserom.gba", 0x587ae8, 0x20

gUnknown_08587B08:: @ 8587B08
	.incbin "baserom.gba", 0x587b08, 0x10

gUnknown_08587B18:: @ 8587B18
	.incbin "baserom.gba", 0x587b18, 0x68

gUnknown_08587B80:: @ 8587B80
	.incbin "baserom.gba", 0x587b80, 0x30

gUnknown_08587BB0:: @ 8587BB0
	.incbin "baserom.gba", 0x587bb0, 0x8

gUnknown_08587BB8:: @ 8587BB8
	.incbin "baserom.gba", 0x587bb8, 0x10

gUnknown_08587BC8:: @ 8587BC8
	.incbin "baserom.gba", 0x587bc8, 0x20

gUnknown_08587BE8:: @ 8587BE8
	.incbin "baserom.gba", 0x587be8, 0x18

gUnknown_08587C00:: @ 8587C00
	.incbin "baserom.gba", 0x587c00, 0x8

gUnknown_08587C08:: @ 8587C08
	.incbin "baserom.gba", 0x587c08, 0x8

gUnknown_08587C10:: @ 8587C10
	.incbin "baserom.gba", 0x587c10, 0x8

gUnknown_08587C18:: @ 8587C18
	.incbin "baserom.gba", 0x587c18, 0x18

gUnknown_08587C30:: @ 8587C30
	.incbin "baserom.gba", 0x587c30, 0x20

@ 8587C50
	.include "data/text/contest_text_pointers.inc"

@ 8587D5C
	.4byte gText_0827D5C1
	.4byte gText_0827D5DC
	.4byte gText_0827D600
	.4byte gText_0827D612
	.4byte gText_0827D612
	.4byte gText_0827D62D
	.4byte gText_0827D654
	.4byte gText_0827D67E
	.4byte gText_0827D69C
	.4byte gText_0827D6BA
	.4byte gText_0827D6E5
	.4byte gText_0827D706
	.4byte gText_0827D71D

gUnknown_08587D90:: @ 8587D90
	.4byte gText_0827D743
	.4byte gText_0827D764
	.4byte gText_0827D785
	.4byte gText_0827D7A5
	.4byte gText_0827D7C8
	.4byte gText_0827D7E8
	.4byte gText_0827D831
	.4byte gText_0827D855
	.4byte gText_0827D830
	.4byte gText_0827D872
	.4byte gText_0827D88F
	.4byte gText_0827D8B5
	.4byte gText_0827D8E4
	.4byte gText_0827D8FE
	.4byte gText_0827D926
	.4byte gText_0827D947
	.4byte gText_0827D961
	.4byte gText_0827D986
	.4byte gText_0827D9B1
	.4byte gText_0827D9D9
	.4byte gText_0827DA03
	.4byte gText_0827DA31
	.4byte gText_0827DA5B
	.4byte gText_0827DA85
	.4byte gText_0827DAB2
	.4byte gText_0827DADA
	.4byte gText_0827DB03
	.4byte gText_0827D830
	.4byte gText_0827D830
	.4byte gText_0827D830
	.4byte gText_0827DB1F
	.4byte gText_0827DB4E

gUnknown_08587E10:: @ 8587E10
	.4byte gText_827DB75
	.4byte gText_827DBB0
	.4byte gText_827DBE0
	.4byte gText_827DC0F
	.4byte gText_827DC45
	.4byte gText_827DC7C
	.4byte gText_827DCB4
	.4byte gText_827DCE7
	.4byte gText_827DD12
	.4byte gText_827DD3D
	.4byte gText_827DD6F
	.4byte gText_827DD8E
	.4byte gText_827DDC7
	.4byte gText_827DDF2
	.4byte gText_827DE14
	.4byte gText_827DE44
	.4byte gText_827DE73
	.4byte gText_827DEA5
	.4byte gText_827DED9
	.4byte gText_827DF02
	.4byte gText_827DF3A
	.4byte gText_827DF63
	.4byte gText_827DF8C
	.4byte gText_827DFB8
	.4byte gText_827DFE2
	.4byte gText_827E00C
	.4byte gText_827E02F
	.4byte gText_827E05F
	.4byte gText_827E08B
	.4byte gText_827E0B5
	.4byte gText_827E0DD
	.4byte gText_827E107
	.4byte gText_827E143
	.4byte gText_827E17F
	.4byte gText_827E1BB
	.4byte gText_827E1F3
	.4byte gText_827E220
	.4byte gText_827E254
	.4byte gText_827E289
	.4byte gText_827E2C5
	.4byte gText_0827E2FE
	.4byte gText_0827E32E
	.4byte gText_0827E35B
	.4byte gText_0827E38D
	.4byte gText_0827E3C1
	.4byte gText_0827E3EB
	.4byte gText_0827E416
	.4byte gText_0827E448
	.4byte gText_0827E473
	.4byte gText_0827E4A6
	.4byte gText_0827E4D5
	.4byte gText_0827E504
	.4byte gText_0827E531
	.4byte gText_0827E55A
	.4byte gText_0827E5B2
	.4byte gText_0827E5D0
	.4byte gText_0827E606
	.4byte gText_0827E638
	.4byte gText_0827E658
	.4byte gText_0827E68B
	.4byte gText_0827E6C4
	.4byte gText_0827E7BA

gUnknown_08587F08:: @ 8587F08
	.4byte gText_0827E85F
	.4byte gText_0827E868
	.4byte gText_0827E86F
	.4byte gText_0827E878
	.4byte gText_0827E882

gUnknown_08587F1C:: @ 8587F1C
	.4byte gText_0827E894
	.4byte gText_0827E89E
	.4byte gText_0827E8AA
	.4byte gText_0827E8B4
	.4byte gText_0827E8BF
	.4byte gText_0827E8CA

gUnknown_08587F34:: @ 8587F34
	.incbin "baserom.gba", 0x587f34, 0x10

gUnknown_08587F44:: @ 8587F44
	.incbin "baserom.gba", 0x587f44, 0x60

gUnknown_08587FA4:: @ 8587FA4
	.incbin "baserom.gba", 0x587fa4, 0x100

gUnknown_085880A4:: @ 85880A4
	.incbin "baserom.gba", 0x5880a4, 0x1740

gUnknown_085897E4:: @ 85897E4
	.incbin "baserom.gba", 0x005897e4, 0xc0

gUnknown_085898A4:: @ 85898A4
	.incbin "baserom.gba", 0x5898a4, 0x60

gUnknown_08589904:: @ 8589904
	.incbin "baserom.gba", 0x589904, 0x20

gUnknown_08589924:: @ 8589924
	.incbin "baserom.gba", 0x589924, 0x68

gUnknown_0858998C:: @ 858998C
	.incbin "baserom.gba", 0x58998c, 0x60

gUnknown_085899EC:: @ 85899EC
	.incbin "baserom.gba", 0x5899ec, 0x1c

