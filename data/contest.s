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
	.4byte 0x827d5c1
	.4byte 0x827d5dc
	.4byte 0x827d600
	.4byte 0x827d612
	.4byte 0x827d612
	.4byte 0x827d62d
	.4byte 0x827d654
	.4byte 0x827d67e
	.4byte 0x827d69c
	.4byte 0x827d6ba
	.4byte 0x827d6e5
	.4byte 0x827d706
	.4byte 0x827d71d

gUnknown_08587D90:: @ 8587D90
	.4byte 0x827d743
	.4byte 0x827d764
	.4byte 0x827d785
	.4byte 0x827d7a5
	.4byte 0x827d7c8
	.4byte 0x827d7e8
	.4byte 0x827d831
	.4byte 0x827d855
	.4byte 0x827d830
	.4byte 0x827d872
	.4byte 0x827d88f
	.4byte 0x827d8b5
	.4byte 0x827d8e4
	.4byte 0x827d8fe
	.4byte 0x827d926
	.4byte 0x827d947
	.4byte 0x827d961
	.4byte 0x827d986
	.4byte 0x827d9b1
	.4byte 0x827d9d9
	.4byte 0x827da03
	.4byte 0x827da31
	.4byte 0x827da5b
	.4byte 0x827da85
	.4byte 0x827dab2
	.4byte 0x827dada
	.4byte 0x827db03
	.4byte 0x827d830
	.4byte 0x827d830
	.4byte 0x827d830
	.4byte 0x827db1f
	.4byte 0x827db4e

gUnknown_08587E10:: @ 8587E10
	.4byte 0x827db75
	.4byte 0x827dbb0
	.4byte 0x827dbe0
	.4byte 0x827dc0f
	.4byte 0x827dc45
	.4byte 0x827dc7c
	.4byte 0x827dcb4
	.4byte 0x827dce7
	.4byte 0x827dd12
	.4byte 0x827dd3d
	.4byte 0x827dd6f
	.4byte 0x827dd8e
	.4byte 0x827ddc7
	.4byte 0x827ddf2
	.4byte 0x827de14
	.4byte 0x827de44
	.4byte 0x827de73
	.4byte 0x827dea5
	.4byte 0x827ded9
	.4byte 0x827df02
	.4byte 0x827df3a
	.4byte 0x827df63
	.4byte 0x827df8c
	.4byte 0x827dfb8
	.4byte 0x827dfe2
	.4byte 0x827e00c
	.4byte 0x827e02f
	.4byte 0x827e05f
	.4byte 0x827e08b
	.4byte 0x827e0b5
	.4byte 0x827e0dd
	.4byte 0x827e107
	.4byte 0x827e143
	.4byte 0x827e17f
	.4byte 0x827e1bb
	.4byte 0x827e1f3
	.4byte 0x827e220
	.4byte 0x827e254
	.4byte 0x827e289
	.4byte 0x827e2c5
	.4byte 0x827e2fe
	.4byte 0x827e32e
	.4byte 0x827e35b
	.4byte 0x827e38d
	.4byte 0x827e3c1
	.4byte 0x827e3eb
	.4byte 0x827e416
	.4byte 0x827e448
	.4byte 0x827e473
	.4byte 0x827e4a6
	.4byte 0x827e4d5
	.4byte 0x827e504
	.4byte 0x827e531
	.4byte 0x827e55a
	.4byte 0x827e5b2
	.4byte 0x827e5d0
	.4byte 0x827e606
	.4byte 0x827e638
	.4byte 0x827e658
	.4byte 0x827e68b
	.4byte 0x827e6c4
	.4byte 0x827e7ba

gUnknown_08587F08:: @ 8587F08
	.4byte 0x827e85f
	.4byte 0x827e868
	.4byte 0x827e86f
	.4byte 0x827e878
	.4byte 0x827e882

gUnknown_08587F1C:: @ 8587F1C
	.4byte 0x827e894
	.4byte 0x827e89e
	.4byte 0x827e8aa
	.4byte 0x827e8b4
	.4byte 0x827e8bf
	.4byte 0x827e8ca

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

