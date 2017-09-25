@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0858AB24:: @ 858AB24
@ replacing .incbin "baserom.gba", 0x0058ab24, 0xac
	.2byte  50,  20
	.2byte  50,  20
	.2byte  50,  20
	.2byte  50,  20
	.2byte  50,  20
	.2byte  50,  30
	.2byte  50,  30
	.2byte  50,  30
	.2byte  50,  30
	.2byte  50,  30
	.2byte  60,  50
	.2byte  60,  50
	.2byte  60,  50
	.2byte  60,  50
	.2byte  60,  50
	.2byte  80,  70
	.2byte  80,  70
	.2byte  80,  70
	.2byte  80,  70
	.2byte  80,  70
	.2byte 100, 100
	.2byte 100, 100
	.2byte 100, 100
	.2byte 100, 100
	.2byte 100, 100
	.2byte 130, 150
	.2byte 130, 150
	.2byte 130, 150
	.2byte 130, 150
	.2byte 130, 150
	.2byte 160, 250
	.2byte 160, 250
	.2byte 160, 250
	.2byte 160, 250
	.2byte 160, 250
	.2byte 180, 500
	.2byte 180, 500
	.2byte 180, 500
	.2byte 180, 500
	.2byte 180, 500
	.2byte 200, 750
	.2byte 200, 750
	.2byte 150, 200

gBlankBerryTree:: @ 858ABD0
	.4byte 0x0, 0x0

gUnknown_0858ABD8:: @ 858ABD8
@ replacing .incbin "baserom.gba", 0x0058abd8, 0xb88
    .4byte gUnknown_085ead37, 0
    .4byte gUnknown_085ead41, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085ead67, 0
    .4byte gUnknown_085ead6d, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085ead72, 0
    .4byte gUnknown_085ead84, 0
    .4byte gUnknown_085ead96, 0
    .4byte gText_Cancel2, 0
    .4byte gUnknown_085EADA4, 0
    .4byte gUnknown_085EADB5, 0
    .4byte gUnknown_085EADC4, 0
    .4byte gUnknown_085EADD5, 0
    .4byte gUnknown_085EADE7, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eadf9, 0
    .4byte gUnknown_085eae04, 0
    .4byte gUnknown_085eae12, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eadf9, 0
    .4byte gUnknown_085eae04, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085e8ccb, 0
    .4byte gUnknown_085eae12, 0
    .4byte gUnknown_085eae1b, 0
    .4byte gText_Cancel2, 0
    .4byte gUnknown_085eae27, 0
    .4byte gUnknown_085eae2c, 0
    .4byte gUnknown_085eae31, 0
    .4byte gUnknown_085eae35, 0
    .4byte gUnknown_085eae39, 0
    .4byte gUnknown_085eae3d, 0
    .4byte gUnknown_085eae41, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085ead5f, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eae53, 0
    .4byte gUnknown_085eae5a, 0
    .4byte gText_Yes, 0
    .4byte gText_No, 0
    .4byte gUnknown_085ead6d, 0
    .4byte gUnknown_085eaea2, 0
    .4byte gUnknown_085eaeac, 0
    .4byte gText_Exit, 0
    .4byte gText_Lv50, 0
    .4byte gText_OpenLevel, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_0027ecbc, 0
    .4byte gUnknown_0027ecc3, 0
    .4byte gUnknown_0027eccd, 0
    .4byte gUnknown_0027ecd5, 0
    .4byte gUnknown_0027ecdd, 0
    .4byte gUnknown_0027ece3, 0
    .4byte gUnknown_0027eceb, 0
    .4byte gUnknown_0027ecf2, 0
    .4byte gUnknown_0027ecf8, 0
    .4byte gUnknown_0027ed00, 0
    .4byte gUnknown_0027ed06, 0
    .4byte gUnknown_0027ed10, 0
    .4byte gUnknown_0027ed18, 0
    .4byte gUnknown_0027ed22, 0
    .4byte gUnknown_0027ed2c, 0
    .4byte gUnknown_0027ed36, 0
    .4byte gUnknown_0027ed40, 0
    .4byte gUnknown_0027ed46, 0
    .4byte gUnknown_0027ed4f, 0
    .4byte gUnknown_0027ed59, 0
    .4byte gUnknown_0027ed65, 0
    .4byte gUnknown_0027ed70, 0
    .4byte gUnknown_0027ed74, 0
    .4byte gUnknown_0027ed78, 0
    .4byte gUnknown_0027ed80, 0
    .4byte gUnknown_0027ed95, 0
    .4byte gUnknown_0027edaa, 0
    .4byte gUnknown_0027edb5, 0
    .4byte gUnknown_0027edba, 0
    .4byte gUnknown_0027edc1, 0
    .4byte gUnknown_0027edc9, 0
    .4byte gUnknown_0027edd5, 0
    .4byte gUnknown_0027ede4, 0
    .4byte gUnknown_0027edf0, 0
    .4byte gUnknown_0027edf5, 0
    .4byte gUnknown_0027edf7, 0
    .4byte gUnknown_0027edf9, 0
    .4byte gUnknown_0027edfb, 0
    .4byte gUnknown_0027edfd, 0
    .4byte gUnknown_0027edff, 0
    .4byte gUnknown_0027ee01, 0
    .4byte gUnknown_0027ee03, 0
    .4byte gUnknown_0027ee05, 0
    .4byte gUnknown_0027ee07, 0
    .4byte gUnknown_0027ee09, 0
    .4byte gUnknown_085eaec3, 0
    .4byte gUnknown_085eaed6, 0
    .4byte gUnknown_085eaee6, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eaef6, 0
    .4byte gUnknown_085eaf02, 0
    .4byte gUnknown_085eaf0e, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eaf1b, 0
    .4byte gUnknown_085eaf24, 0
    .4byte gUnknown_085eaf2f, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eaf34, 0
    .4byte gUnknown_085eaf3e, 0
    .4byte gUnknown_085eaf4b, 0
    .4byte gUnknown_085eaf58, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eaf65, 0
    .4byte gUnknown_085eaf70, 0
    .4byte gUnknown_085eaf7d, 0
    .4byte gUnknown_085eaf87, 0
    .4byte gUnknown_085eaf93, 0
    .4byte gUnknown_085eaf9f, 0
    .4byte gUnknown_085eafab, 0
    .4byte gText_Cancel2, 0
    .4byte gUnknown_085eafb6, 0
    .4byte gUnknown_085eafcf, 0
    .4byte gUnknown_085eafe8, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb089, 0
    .4byte gUnknown_085eb09c, 0
    .4byte gUnknown_085eb0af, 0
    .4byte gUnknown_085eb0c2, 0
    .4byte gUnknown_085eb0d5, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb002, 0
    .4byte gUnknown_085eb017, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb02a, 0
    .4byte gUnknown_085eb034, 0
    .4byte gUnknown_085eb79b, 0
    .4byte gUnknown_085eb06e, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb7a9, 0
    .4byte gUnknown_085eb79b, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb07e, 0
    .4byte gUnknown_085eb084, 0
    .4byte gUnknown_085eb79b, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb676, 0
    .4byte gUnknown_085eb673, 0
    .4byte gUnknown_085eb670, 0
    .4byte gUnknown_085eb66d, 0
    .4byte gUnknown_085eb66a, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb057, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb057, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb057, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb057, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb057, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb057, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb057, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb040, 0
    .4byte gUnknown_085eb04a, 0
    .4byte gUnknown_085eb057, 0
    .4byte gUnknown_085eb062, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb1a0, 0
    .4byte gUnknown_085eb1a9, 0
    .4byte gUnknown_085eb1b6, 0
    .4byte gUnknown_085eb5bc, 0
    .4byte gUnknown_085eb5c3, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085eb1a0, 0
    .4byte gUnknown_085eb1a9, 0
    .4byte gUnknown_085eb1b6, 0
    .4byte gUnknown_085eb5c3, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085eb29a, 0
    .4byte gUnknown_085eb2a3, 0
    .4byte gUnknown_085eb372, 0
    .4byte gUnknown_085eb37f, 0
    .4byte gUnknown_085eb389, 0
    .4byte gText_Exit, 0
    .4byte gText_Yes, 0
    .4byte gText_No, 0
    .4byte gUnknown_085ead6d, 0
    .4byte gUnknown_085eae6e, 0
    .4byte gUnknown_085eae7c, 0
    .4byte gUnknown_085eae8a, 0
    .4byte gUnknown_085ead6d, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb372, 0
    .4byte gUnknown_085eb37f, 0
    .4byte gUnknown_085eb397, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb372, 0
    .4byte gUnknown_085eb37f, 0
    .4byte gUnknown_085eb389, 0
    .4byte gUnknown_085eb397, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb372, 0
    .4byte gUnknown_085eb37f, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb3a4, 0
    .4byte gUnknown_085eb3b1, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb3d4, 0
    .4byte gUnknown_085eb3c6, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb1c5, 0
    .4byte gUnknown_085eb1d1, 0
    .4byte gUnknown_085eb1dc, 0
    .4byte gUnknown_085eb1e7, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb212, 0
    .4byte gUnknown_085eb21d, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb227, 0
    .4byte gUnknown_085eb234, 0
    .4byte gUnknown_085eb241, 0
    .4byte gText_Cancel2, 0
    .4byte gUnknown_085eb24e, 0
    .4byte gUnknown_085eb255, 0
    .4byte gText_Exit, 0
    .4byte gText_MenuOptionPokedex, 0
    .4byte gText_MenuOptionPokemon, 0
    .4byte gText_MenuOptionBag, 0
    .4byte gText_MenuOptionPokenav, 0
    .4byte gUnknown_085eb278, 0
    .4byte gText_MenuOptionSave, 0
    .4byte gText_MenuOptionOption, 0
    .4byte gText_MenuOptionExit, 0
    .4byte gUnknown_085eb28a, 0
    .4byte gUnknown_085eb290, 0
    .4byte gUnknown_085eb295, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb2ad, 0
    .4byte gUnknown_085eb2bd, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb2ad, 0
    .4byte gUnknown_085eb2ca, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb2bd, 0
    .4byte gUnknown_085eb2ca, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb2ad, 0
    .4byte gUnknown_085eb2bd, 0
    .4byte gUnknown_085eb2ca, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb2e4, 0
    .4byte gUnknown_085eb2f0, 0
    .4byte gText_Exit, 0
    .4byte gText_Yes, 0
    .4byte gUnknown_085eb2fc, 0
    .4byte gUnknown_085eb3df, 0
    .4byte gUnknown_085eb3ea, 0
    .4byte gUnknown_085eb3f1, 0
    .4byte gUnknown_085eb3fc, 0
    .4byte gUnknown_085eb40a, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb415, 0
    .4byte gUnknown_085eb41d, 0
    .4byte gUnknown_085eb424, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb45c, 0
    .4byte gUnknown_085eb469, 0
    .4byte gUnknown_085eb475, 0
    .4byte gUnknown_085eb482, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb42f, 0
    .4byte gUnknown_085eb43a, 0
    .4byte gUnknown_085eb444, 0
    .4byte gUnknown_085eb451, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb48e, 0
    .4byte gUnknown_085eb496, 0
    .4byte gUnknown_085eb4a3, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb4ad, 0
    .4byte gUnknown_085eb4b9, 0
    .4byte gUnknown_085eb4c7, 0
    .4byte gUnknown_085eb4d4, 0
    .4byte gUnknown_085eb4e0, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb4eb, 0
    .4byte gUnknown_085eb4f9, 0
    .4byte gUnknown_085eb508, 0
    .4byte gUnknown_085eb516, 0
    .4byte gUnknown_085eb523, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb532, 0
    .4byte gUnknown_085eb543, 0
    .4byte gUnknown_085eb555, 0
    .4byte gUnknown_085eb563, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb56e, 0
    .4byte gUnknown_085eb57e, 0
    .4byte gUnknown_085eb589, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb5b6, 0
    .4byte gUnknown_085eb5bc, 0
    .4byte gUnknown_085eb5c3, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085eb5b6, 0
    .4byte gUnknown_085eb5c3, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085eb5b6, 0
    .4byte gUnknown_085eb5bc, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085eb5b6, 0
    .4byte gUnknown_085eb5c8, 0
    .4byte gUnknown_085ee14b, 0
    .4byte gUnknown_085ee14f, 0
    .4byte gUnknown_085eb2ff, 0
    .4byte gUnknown_085eb310, 0
    .4byte gUnknown_085eb317, 0
    .4byte gUnknown_085eb31f, 0
    .4byte gUnknown_085eb7b8, 0
    .4byte gUnknown_085eb7c7, 0
    .4byte gUnknown_085eb7d0, 0
    .4byte gUnknown_085eb7db, 0
    .4byte gUnknown_085eb4ad, 0
    .4byte gUnknown_085eb4b9, 0
    .4byte gUnknown_085eb4c7, 0
    .4byte gUnknown_085eb4d4, 0
    .4byte gUnknown_085eb597, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb5a6, 0
    .4byte gUnknown_085eb45c, 0
    .4byte gUnknown_085eb469, 0
    .4byte gUnknown_085eb475, 0
    .4byte gUnknown_085eb482, 0
    .4byte gText_Exit, 0
    .4byte gUnknown_085eb32d, 0
    .4byte gUnknown_085eb33e, 0
    .4byte gUnknown_085eb350, 0
    .4byte gUnknown_085eb361, 0
    .4byte gText_Exit, 0
    .4byte gText_Exit, 0

gUnknown_0858B760:: @ 858B760
	.incbin "baserom.gba", 0x58b760, 0x390

gUnknown_0858BAF0:: @ 858BAF0
	.incbin "baserom.gba", 0x58baf0, 0x78

gUnknown_0858BB68:: @ 858BB68
	.incbin "baserom.gba", 0x58bb68, 0x8

gUnknown_0858BB70:: @ 858BB70
	.incbin "baserom.gba", 0x58bb70, 0x10

gUnknown_0858BB80:: @ 858BB80
	.incbin "baserom.gba", 0x58bb80, 0x1c

gUnknown_0858BB9C:: @ 858BB9C
	.incbin "baserom.gba", 0x58bb9c, 0x10

gUnknown_0858BBAC:: @ 858BBAC
	.incbin "baserom.gba", 0x58bbac, 0x10

gUnknown_0858BBBC:: @ 858BBBC
	.incbin "baserom.gba", 0x58bbbc, 0x10

gUnknown_0858BBCC:: @ 858BBCC
	.incbin "baserom.gba", 0x58bbcc, 0x14

gUnknown_0858BBE0:: @ 858BBE0
	.incbin "baserom.gba", 0x58bbe0, 0xc

gUnknown_0858BBEC:: @ 858BBEC
	.incbin "baserom.gba", 0x58bbec, 0x18c

gUnknown_0858BD78:: @ 858BD78
	.incbin "baserom.gba", 0x58bd78, 0x40

gUnknown_0858BDB8:: @ 858BDB8
	.incbin "baserom.gba", 0x58bdb8, 0x10

gUnknown_0858BDC8:: @ 858BDC8
	.incbin "baserom.gba", 0x58bdc8, 0x38

gUnknown_0858BE00:: @ 858BE00
	.incbin "baserom.gba", 0x58be00, 0x10

gUnknown_0858BE10:: @ 858BE10
	.incbin "baserom.gba", 0x58be10, 0x30

gUnknown_0858BE40:: @ 858BE40
	.incbin "baserom.gba", 0x58be40, 0x60

gUnknown_0858BEA0:: @ 858BEA0
	.incbin "baserom.gba", 0x58bea0, 0x3

gUnknown_0858BEA3:: @ 858BEA3
	.incbin "baserom.gba", 0x58bea3, 0x18

gUnknown_0858BEBB:: @ 858BEBB
	.incbin "baserom.gba", 0x58bebb, 0x3

gUnknown_0858BEBE:: @ 858BEBE
	.incbin "baserom.gba", 0x58bebe, 0x3

gUnknown_0858BEC1:: @ 858BEC1
	.incbin "baserom.gba", 0x58bec1, 0x3

gUnknown_0858BEC4:: @ 858BEC4
	.incbin "baserom.gba", 0x58bec4, 0x10

gUnknown_0858BED4:: @ 858BED4
	.incbin "baserom.gba", 0x58bed4, 0x8

gUnknown_0858BEDC:: @ 858BEDC
	.incbin "baserom.gba", 0x58bedc, 0x8

gUnknown_0858BEE4:: @ 858BEE4
	.incbin "baserom.gba", 0x58bee4, 0x4

gUnknown_0858BEE8:: @ 858BEE8
	.incbin "baserom.gba", 0x58bee8, 0x10

gUnknown_0858BEF8:: @ 858BEF8
	.incbin "baserom.gba", 0x58bef8, 0x6

gUnknown_0858BEFE:: @ 858BEFE
	.incbin "baserom.gba", 0x58befe, 0x6

gUnknown_0858BF04:: @ 858BF04
	.incbin "baserom.gba", 0x58bf04, 0x14

gUnknown_0858BF18:: @ 858BF18
	.incbin "baserom.gba", 0x58bf18, 0x10

gUnknown_0858BF28:: @ 858BF28
	.incbin "baserom.gba", 0x58bf28, 0xc

gUnknown_0858BF34:: @ 858BF34
	.incbin "baserom.gba", 0x58bf34, 0xa

gUnknown_0858BF3E:: @ 858BF3E
	.incbin "baserom.gba", 0x58bf3e, 0xa

gUnknown_0858BF48:: @ 858BF48
	.incbin "baserom.gba", 0x58bf48, 0x8

gUnknown_0858BF50:: @ 858BF50
	.incbin "baserom.gba", 0x58bf50, 0x8

gUnknown_0858BF58:: @ 858BF58
	.incbin "baserom.gba", 0x58bf58, 0x14

gUnknown_0858BF6C:: @ 858BF6C
	.incbin "baserom.gba", 0x58bf6c, 0x8

gUnknown_0858BF74:: @ 858BF74
	.incbin "baserom.gba", 0x58bf74, 0x14

gUnknown_0858BF88:: @ 858BF88
	.incbin "baserom.gba", 0x58bf88, 0x4

gUnknown_0858BF8C:: @ 858BF8C
	.incbin "baserom.gba", 0x58bf8c, 0xc

gUnknown_0858BF98:: @ 858BF98
	.incbin "baserom.gba", 0x58bf98, 0xc

gUnknown_0858BFA4:: @ 858BFA4
	.incbin "baserom.gba", 0x58bfa4, 0x34

gUnknown_0858BFD8:: @ 858BFD8
	.incbin "baserom.gba", 0x58bfd8, 0x78

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
	.incbin "baserom.gba", 0x58c198, 0x30

gUnknown_0858C1C8:: @ 858C1C8
	.incbin "baserom.gba", 0x58c1c8, 0x68

gUnknown_0858C230:: @ 858C230
	.incbin "baserom.gba", 0x58c230, 0x5c

gUnknown_0858C28C:: @ 858C28C
	.incbin "baserom.gba", 0x58c28c, 0x18

gUnknown_0858C2A4:: @ 858C2A4
	.incbin "baserom.gba", 0x58c2a4, 0x8

gUnknown_0858C2AC:: @ 858C2AC
	.incbin "baserom.gba", 0x58c2ac, 0x8

@ 858C2B4
	.include "data/contest_moves.inc"

@ 858CDCC
	.include "data/contest_effects.inc"

@ A lookup table with a 1 for each combo starter ID and a 0 for ID 0,
@ which means "not a combo starter move".
gComboStarterLookupTable:: @ 858CE8C
	.byte 0
	.rept 62
	.byte 1
	.endr

	.align 2
@ 858CECC
	.include "data/contest_effect_function_table.inc"

gUnknown_0858CF8C:: @ 858CF8C
	.incbin "baserom.gba", 0x58cf8c, 0x2

gUnknown_0858CF8E:: @ 858CF8E
	.incbin "baserom.gba", 0x58cf8e, 0x6

gUnknown_0858CF94:: @ 858CF94
	.incbin "baserom.gba", 0x58cf94, 0x24

gUnknown_0858CFB8:: @ 858CFB8
	.incbin "baserom.gba", 0x58cfb8, 0x6

gUnknown_0858CFBE:: @ 858CFBE
	.incbin "baserom.gba", 0x58cfbe, 0xe

gUnknown_0858CFCC:: @ 858CFCC
	.incbin "baserom.gba", 0x58cfcc, 0x1c

gUnknown_0858CFE8:: @ 858CFE8
	.incbin "baserom.gba", 0x58cfe8, 0x60

gUnknown_0858D048:: @ 858D048
	.incbin "baserom.gba", 0x58d048, 0x10

gUnknown_0858D058:: @ 858D058
	.incbin "baserom.gba", 0x58d058, 0x8

gUnknown_0858D060:: @ 858D060
	.incbin "baserom.gba", 0x58d060, 0xc

gUnknown_0858D06C:: @ 858D06C
	.incbin "baserom.gba", 0x58d06c, 0x10

gUnknown_0858D07C:: @ 858D07C
	.incbin "baserom.gba", 0x58d07c, 0x18

gUnknown_0858D094:: @ 858D094
	.incbin "baserom.gba", 0x58d094, 0x3c

gUnknown_0858D0D0:: @ 858D0D0
	.incbin "baserom.gba", 0x58d0d0, 0xe

gUnknown_0858D0DE:: @ 858D0DE
	.incbin "baserom.gba", 0x58d0de, 0xe

gUnknown_0858D0EC:: @ 858D0EC
	.incbin "baserom.gba", 0x58d0ec, 0x1c

gUnknown_0858D108:: @ 858D108
	.incbin "baserom.gba", 0x58d108, 0x14

gUnknown_0858D11C:: @ 858D11C
	.incbin "baserom.gba", 0x58d11c, 0x14

gUnknown_0858D130:: @ 858D130
	.incbin "baserom.gba", 0x58d130, 0x14

gUnknown_0858D144:: @ 858D144
	.incbin "baserom.gba", 0x58d144, 0xc

gUnknown_0858D150:: @ 858D150
	.incbin "baserom.gba", 0x58d150, 0x20

gUnknown_0858D170:: @ 858D170
	.incbin "baserom.gba", 0x58d170, 0x18

gUnknown_0858D188:: @ 858D188
	.incbin "baserom.gba", 0x58d188, 0x14

gUnknown_0858D19C:: @ 858D19C
	.incbin "baserom.gba", 0x58d19c, 0x4

gUnknown_0858D1A0:: @ 858D1A0
	.incbin "baserom.gba", 0x58d1a0, 0x30

gUnknown_0858D1D0:: @ 858D1D0
	.incbin "baserom.gba", 0x58d1d0, 0x34

gUnknown_0858D204:: @ 858D204
	.incbin "baserom.gba", 0x58d204, 0x24

gUnknown_0858D228:: @ 858D228
	.incbin "baserom.gba", 0x58d228, 0x18

gUnknown_0858D240:: @ 858D240
	.incbin "baserom.gba", 0x58d240, 0x3c

gUnknown_0858D27C:: @ 858D27C
	.incbin "baserom.gba", 0x58d27c, 0x84

gUnknown_0858D300:: @ 858D300
	.incbin "baserom.gba", 0x58d300, 0x20

gUnknown_0858D320:: @ 858D320
	.incbin "baserom.gba", 0x58d320, 0x18

gUnknown_0858D338:: @ 858D338
	.incbin "baserom.gba", 0x58d338, 0x4c

gUnknown_0858D384:: @ 858D384
	.incbin "baserom.gba", 0x58d384, 0x10

gUnknown_0858D394:: @ 858D394
	.incbin "baserom.gba", 0x58d394, 0x1c

gUnknown_0858D3B0:: @ 858D3B0
	.incbin "baserom.gba", 0x58d3b0, 0x8

gUnknown_0858D3B8:: @ 858D3B8
	.incbin "baserom.gba", 0x58d3b8, 0xc

gUnknown_0858D3C4:: @ 858D3C4
	.incbin "baserom.gba", 0x58d3c4, 0x2c

gUnknown_0858D3F0:: @ 858D3F0
	.incbin "baserom.gba", 0x58d3f0, 0x1c

gUnknown_0858D40C:: @ 858D40C
	.incbin "baserom.gba", 0x58d40c, 0xc

gUnknown_0858D418:: @ 858D418
	.incbin "baserom.gba", 0x58d418, 0x10

gUnknown_0858D428:: @ 858D428
	.incbin "baserom.gba", 0x58d428, 0x34

gUnknown_0858D45C:: @ 858D45C
	.incbin "baserom.gba", 0x58d45c, 0x38

gUnknown_0858D494:: @ 858D494
	.incbin "baserom.gba", 0x58d494, 0x4

gUnknown_0858D498:: @ 858D498
	.incbin "baserom.gba", 0x58d498, 0x1c

gUnknown_0858D4B4:: @ 858D4B4
	.incbin "baserom.gba", 0x58d4b4, 0x30

gUnknown_0858D4E4:: @ 858D4E4
	.incbin "baserom.gba", 0x58d4e4, 0x40

gUnknown_0858D524:: @ 858D524
	.incbin "baserom.gba", 0x58d524, 0x4c

gUnknown_0858D570:: @ 858D570
	.incbin "baserom.gba", 0x58d570, 0x24

gUnknown_0858D594:: @ 858D594
	.incbin "baserom.gba", 0x58d594, 0xac

gUnknown_0858D640:: @ 858D640
	.incbin "baserom.gba", 0x58d640, 0x2c

gUnknown_0858D66C:: @ 858D66C
	.incbin "baserom.gba", 0x58d66c, 0x24

gUnknown_0858D690:: @ 858D690
	.incbin "baserom.gba", 0x58d690, 0x20

gUnknown_0858D6B0:: @ 858D6B0
	.incbin "baserom.gba", 0x58d6b0, 0x20

gUnknown_0858D6D0:: @ 858D6D0
	.incbin "baserom.gba", 0x58d6d0, 0x128

gUnknown_0858D7F8:: @ 858D7F8
	.incbin "baserom.gba", 0x58d7f8, 0x18

gUnknown_0858D810:: @ 858D810
	.incbin "baserom.gba", 0x58d810, 0x40

gUnknown_0858D850:: @ 858D850
	.incbin "baserom.gba", 0x58d850, 0x10

gUnknown_0858D860:: @ 858D860
	.incbin "baserom.gba", 0x58d860, 0x18

gUnknown_0858D878:: @ 858D878
	.incbin "baserom.gba", 0x58d878, 0x8

gUnknown_0858D880:: @ 858D880
	.incbin "baserom.gba", 0x58d880, 0x8

gUnknown_0858D888:: @ 858D888
	.incbin "baserom.gba", 0x58d888, 0x10

gUnknown_0858D898:: @ 858D898
	.incbin "baserom.gba", 0x58d898, 0x30

gUnknown_0858D8C8:: @ 858D8C8
	.incbin "baserom.gba", 0x58d8c8, 0x18

gUnknown_0858D8E0:: @ 858D8E0
	.incbin "baserom.gba", 0x58d8e0, 0x8

gUnknown_0858D8E8:: @ 858D8E8
	.incbin "baserom.gba", 0x58d8e8, 0x4

gUnknown_0858D8EC:: @ 858D8EC
	.incbin "baserom.gba", 0x58d8ec, 0x4
