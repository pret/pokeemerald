	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0861F3EC:: @ 861F3EC
	.4byte sub_81C9298
	.4byte sub_81C941C
	.4byte sub_81C9924
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81C9298
	.4byte sub_81C941C
	.4byte sub_81C9940
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81C9338
	.4byte sub_81C941C
	.4byte sub_81C9940
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81C9368
	.4byte sub_81C941C
	.4byte sub_81C9940
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81C92CC
	.4byte sub_81C941C
	.4byte sub_81C9940
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81C9304
	.4byte sub_81C941C
	.4byte sub_81C9940
	.4byte sub_81C9990
	.4byte sub_81C99C0
	.4byte sub_81C9430
	.4byte sub_81C99D4
	.4byte sub_81CC4D4
	.4byte sub_81CC554
	.4byte sub_81CC5F4
	.4byte sub_81CC62C
	.4byte sub_81CC65C
	.4byte sub_81CC524
	.4byte sub_81CC670
	.4byte sub_81CCFD8
	.4byte sub_81CD070
	.4byte sub_81CDDD4
	.4byte sub_81CDE2C
	.4byte sub_81CDE64
	.4byte sub_81CD1C0
	.4byte sub_81CECA0
	.4byte sub_81CEF3C
	.4byte sub_81CEFDC
	.4byte sub_81CF330
	.4byte sub_81CF3A0
	.4byte sub_81CF3D0
	.4byte sub_81CEFF0
	.4byte sub_81CF3F8
	.4byte sub_81CD024
	.4byte sub_81CD070
	.4byte sub_81CDDD4
	.4byte sub_81CDE2C
	.4byte sub_81CDE64
	.4byte sub_81CD1C0
	.4byte sub_81CECA0
	.4byte sub_81CEF98
	.4byte sub_81CEFDC
	.4byte sub_81CF368
	.4byte sub_81CF3A0
	.4byte sub_81CF3D0
	.4byte sub_81CEFF0
	.4byte sub_81CF3F8
	.4byte sub_81CAAE8
	.4byte sub_81CAB24
	.4byte sub_81CB260
	.4byte sub_81CB29C
	.4byte sub_81CB2CC
	.4byte sub_81CAB38
	.4byte sub_81CB2E0
	.4byte sub_81CF9BC
	.4byte sub_81CFA34
	.4byte sub_81CFDD0
	.4byte sub_81CFE40
	.4byte sub_81CFE70
	.4byte sub_81CFA48
	.4byte sub_81CFE98
	.4byte sub_81D0450
	.4byte sub_81D04A0
	.4byte sub_81D0978
	.4byte sub_81D09B0
	.4byte sub_81D09E0
	.4byte sub_81D04B8
	.4byte sub_81D09F4
	.4byte sub_81CFA04
	.4byte sub_81CFA34
	.4byte sub_81CFE08
	.4byte sub_81CFE40
	.4byte sub_81CFE70
	.4byte sub_81CFA48
	.4byte sub_81CFE98
	
gUnknown_0861F590:: @ 861F590
	.incbin "baserom.gba", 0x61F590, 0x20
	
gUnknown_0861F5B0:: @ 861F5B0
	.incbin "baserom.gba", 0x61f5b0, 0x454

gUnknown_0861FA04:: @ 861FA04
	.incbin "baserom.gba", 0x61fa04, 0x4

gUnknown_0861FA08:: @ 861FA08
	.incbin "baserom.gba", 0x61fa08, 0x10

gUnknown_0861FA18:: @ 861FA18
	.4byte gUnknown_085EBED5
	.4byte gUnknown_085EBED9
	.4byte gUnknown_085EBEE9
	.4byte gUnknown_085EBEF9
	.4byte gUnknown_085EBF0E
	.4byte gUnknown_085EBF22
	.4byte gUnknown_085EBF39
	.4byte gUnknown_085EBF49
	.4byte gUnknown_085EBF57
	.4byte gUnknown_085EBF60
	.4byte gUnknown_085EBF73
	.4byte gUnknown_085EBF84

gUnknown_0861FA48:: @ 861FA48
	.incbin "baserom.gba", 0x61fa48, 0x4

gUnknown_0861FA4C:: @ 861FA4C
	obj_tiles gUnknown_0861F5B0, 0x1000, 0

gUnknown_0861FA54:: @ 861FA54
	obj_pal gUnknown_0861F590, 0
	obj_pal NULL, 0

gUnknown_0861FA64:: @ 861FA64
	obj_tiles gUnknown_08DC87F8, 0xC00, 2

gUnknown_0861FA6C:: @ 861FA6C
	obj_tiles gUnknown_08DC864C, 0x20, 3
	obj_tiles gUnknown_08DC8208, 0x20, 1
	obj_tiles gUnknown_08DC8AA4, 0x20, 2
	obj_tiles gUnknown_08DC84AC, 0x20, 4
	obj_tiles gUnknown_08DC87F8, 0x20, 0
	obj_tiles gUnknown_08DC87F8, 0x40, 0

gUnknown_0861FA9C:: @ 861FA9C
	.4byte gUnknown_08DC8F64, 1
	.4byte gUnknown_08DC8C14, 1
	.4byte gUnknown_08DC8E64, 4
	.4byte gUnknown_08DC7FA0, 1
	.4byte gUnknown_08DC838C, 2
	.4byte gUnknown_08DC80DC, 0
	.4byte gUnknown_08DC8D50, 0
	
gUnknown_0861FAD4:: @ 861FAD4
	.2byte 0x0
	.2byte 0x8000
	.2byte 0x0
	.2byte 0x0
	
gUnknown_0861FADC::
	obj_image_anim_frame 0, 8
    obj_image_anim_frame 16, 8
    obj_image_anim_frame 32, 8
    obj_image_anim_frame 48, 8
    obj_image_anim_frame 64, 8
    obj_image_anim_frame 80, 8
    obj_image_anim_frame 96, 8
    obj_image_anim_frame 112, 8
    obj_image_anim_jump 0
	
gUnknown_0861FB00::
	.4byte gUnknown_0861FADC

gUnknown_0861FB04:: @ 861FB04
	spr_template 0, 0, gUnknown_0861FAD4, gUnknown_0861FB00, NULL, gDummySpriteAffineAnimTable, sub_81C7CB4 

gUnknown_0861FB1C::
	.2byte 0x4000
	.2byte 0xC000
	.2byte 0x400
	.2byte 0x0
	
gUnknown_0861FB24::
	.2byte 0x4000
	.2byte 0x8000
	.2byte 0x400
	.2byte 0x0
	
gUnknown_0861FB2C:: @ 861FB2C
	spr_template 2, 1, gUnknown_0861FB1C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_0861FB44:: @ 861FB44
	.incbin "baserom.gba", 0x61fb44, 0xa0

gUnknown_0861FBE4:: @ 861FBE4
	.incbin "baserom.gba", 0x61fbe4, 0x4

gUnknown_0861FBE8:: @ 861FBE8
	.incbin "baserom.gba", 0x61fbe8, 0xc

gUnknown_0861FBF4:: @ 861FBF4
	.incbin "baserom.gba", 0x61fbf4, 0x3

gUnknown_0861FBF7:: @ 861FBF7
	.incbin "baserom.gba", 0x61fbf7, 0x5

gUnknown_0861FBFC:: @ 861FBFC
	.incbin "baserom.gba", 0x61fbfc, 0x8

gUnknown_0861FC04:: @ 861FC04
	.incbin "baserom.gba", 0x61fc04, 0x18

gUnknown_0861FC1C:: @ 861FC1C
	.incbin "baserom.gba", 0x61fc1c, 0x20

gUnknown_0861FC3C:: @ 861FC3C
	.incbin "baserom.gba", 0x61fc3c, 0x18

gUnknown_0861FC54:: @ 861FC54
	.incbin "baserom.gba", 0x61fc54, 0x5

gUnknown_0861FC59:: @ 861FC59
	.incbin "baserom.gba", 0x61fc59, 0x1f

gUnknown_0861FC78:: @ 861FC78
	.incbin "baserom.gba", 0x61fc78, 0x2

gUnknown_0861FC7A:: @ 861FC7A
	.incbin "baserom.gba", 0x61fc7a, 0xc

gUnknown_0861FC86:: @ 861FC86
	.incbin "baserom.gba", 0x61fc86, 0x12

gUnknown_0861FC98:: @ 861FC98
	.incbin "baserom.gba", 0x61fc98, 0x14

gUnknown_0861FCAC:: @ 861FCAC
	.incbin "baserom.gba", 0x61fcac, 0xa0

gUnknown_0861FD4C:: @ 861FD4C
	.incbin "baserom.gba", 0x61fd4c, 0x20

gUnknown_0861FD6C:: @ 861FD6C
	.incbin "baserom.gba", 0x61fd6c, 0x288

gUnknown_0861FFF4:: @ 861FFF4
	.incbin "baserom.gba", 0x61fff4, 0x1a0

gUnknown_08620194:: @ 8620194
	.incbin "baserom.gba", 0x620194, 0xc

gUnknown_086201A0:: @ 86201A0
	.incbin "baserom.gba", 0x6201a0, 0x24

gUnknown_086201C4:: @ 86201C4
	.incbin "baserom.gba", 0x6201c4, 0x10

gUnknown_086201D4:: @ 86201D4
	.incbin "baserom.gba", 0x6201d4, 0x6c

gUnknown_08620240:: @ 8620240
	.incbin "baserom.gba", 0x620240, 0x4

gUnknown_08620244:: @ 8620244
	.incbin "baserom.gba", 0x620244, 0x88

gUnknown_086202CC:: @ 86202CC
	.incbin "baserom.gba", 0x6202cc, 0x8

gUnknown_086202D4:: @ 86202D4
	.incbin "baserom.gba", 0x6202d4, 0x38

gUnknown_0862030C:: @ 862030C
	.incbin "baserom.gba", 0x62030c, 0x3

gUnknown_0862030F:: @ 862030F
	.incbin "baserom.gba", 0x62030f, 0x3d

gUnknown_0862034C:: @ 862034C
	.incbin "baserom.gba", 0x62034c, 0x20

gUnknown_0862036C:: @ 862036C
	.incbin "baserom.gba", 0x62036c, 0x18

gUnknown_08620384:: @ 8620384
	.incbin "baserom.gba", 0x620384, 0x1ca4

gUnknown_08622028:: @ 8622028
	.incbin "baserom.gba", 0x622028, 0x4e0

gUnknown_08622508:: @ 8622508
	.incbin "baserom.gba", 0x622508, 0x2

gUnknown_0862250A:: @ 862250A
	.incbin "baserom.gba", 0x62250a, 0x6

gUnknown_08622510:: @ 8622510
	.incbin "baserom.gba", 0x622510, 0x20

gUnknown_08622530:: @ 8622530
	.incbin "baserom.gba", 0x622530, 0xa4

gUnknown_086225D4:: @ 86225D4
	.incbin "baserom.gba", 0x6225d4, 0x10c

gUnknown_086226E0:: @ 86226E0
	.incbin "baserom.gba", 0x6226e0, 0x20

gUnknown_08622700:: @ 8622700
	.incbin "baserom.gba", 0x622700, 0x20

gUnknown_08622720:: @ 8622720
	.incbin "baserom.gba", 0x622720, 0x40

gUnknown_08622760:: @ 8622760
	.incbin "baserom.gba", 0x622760, 0x2c

gUnknown_0862278C:: @ 862278C
	.incbin "baserom.gba", 0x62278c, 0x8

gUnknown_08622794:: @ 8622794
	.incbin "baserom.gba", 0x622794, 0x4

gUnknown_08622798:: @ 8622798
	.4byte NULL
	.4byte sub_81CB510
	.4byte sub_81CB588
	.4byte sub_81CB600
	.4byte sub_81CB678
	.4byte sub_81CB6F0
	.4byte sub_81CB734
	.4byte sub_81CB75C
	.4byte sub_81CB7A0
	.4byte sub_81CB824
	.4byte sub_81CB888
	.4byte sub_81CB93C
	.4byte sub_81CBAD4
	.4byte sub_81CB9C8
	.4byte sub_81CBA68
	.4byte sub_81CBB74

gUnknown_086227D8:: @ 86227D8
	.incbin "baserom.gba", 0x6227d8, 0x8

gUnknown_086227E0:: @ 86227E0
	.incbin "baserom.gba", 0x6227e0, 0x8

gUnknown_086227E8:: @ 86227E8
	.incbin "baserom.gba", 0x6227e8, 0xc

gUnknown_086227F4:: @ 86227F4
	.incbin "baserom.gba", 0x6227f4, 0x14

gUnknown_08622808:: @ 8622808
	.incbin "baserom.gba", 0x622808, 0x8

gUnknown_08622810:: @ 8622810
	.incbin "baserom.gba", 0x622810, 0x8

gUnknown_08622818:: @ 8622818
	.incbin "baserom.gba", 0x622818, 0x18

gUnknown_08622830:: @ 8622830
	.incbin "baserom.gba", 0x622830, 0x20

gUnknown_08622850:: @ 8622850
	.incbin "baserom.gba", 0x622850, 0x18

gUnknown_08622868:: @ 8622868
	.incbin "baserom.gba", 0x622868, 0x20

gUnknown_08622888:: @ 8622888
     .incbin "baserom.gba", 0x622888, 0x1F4

gUnknown_08622A7C:: @ 8622A7C
     .incbin "baserom.gba", 0x622a7c, 0x44

gUnknown_08622AC0:: @ 8622AC0
     .incbin "baserom.gba", 0x622ac0, 0x48

gUnknown_08622B08:: @ 8622B08
     .incbin "baserom.gba", 0x622b08, 0x50

gUnknown_08622B58:: @ 8622B58
     .incbin "baserom.gba", 0x622b58, 0x60

gUnknown_08622BB8:: @ 8622BB8
     .incbin "baserom.gba", 0x622bb8, 0x4C

gUnknown_08622C04:: @ 8622C04
     .incbin "baserom.gba", 0x622c04, 0x54

gUnknown_08622C58:: @ 8622C58
     .incbin "baserom.gba", 0x622c58, 0x54

gUnknown_08622CAC:: @ 8622CAC
     .incbin "baserom.gba", 0x622cac, 0x40

gUnknown_08622CEC:: @ 8622CEC
     .incbin "baserom.gba", 0x622cec, 0x58

gUnknown_08622D44:: @ 8622D44
     .incbin "baserom.gba", 0x622d44, 0x54

gUnknown_08622D98:: @ 8622D98
     .incbin "baserom.gba", 0x622d98, 0x30

gUnknown_08622DC8:: @ 8622DC8
     .incbin "baserom.gba", 0x622dc8, 0x4C

gUnknown_08622E14:: @ 8622E14
     .incbin "baserom.gba", 0x622e14, 0x58

gUnknown_08622E6C:: @ 8622E6C
     .incbin "baserom.gba", 0x622e6c, 0x30

gUnknown_08622E9C:: @ 8622E9C
     .incbin "baserom.gba", 0x622e9c, 0x38

gUnknown_08622ED4:: @ 8622ED4
     .incbin "baserom.gba", 0x622ed4, 0x40

gUnknown_08622F14:: @ 8622F14
     .incbin "baserom.gba", 0x622f14, 0x48

gUnknown_08622F5C:: @ 8622F5C
     .incbin "baserom.gba", 0x622f5c, 0x44

gUnknown_08622FA0:: @ 8622FA0
     .incbin "baserom.gba", 0x622fa0, 0x38

gUnknown_08622FD8:: @ 8622FD8
     .incbin "baserom.gba", 0x622fd8, 0x48

gUnknown_08623020:: @ 8623020
     .incbin "baserom.gba", 0x623020, 0x5C

gUnknown_0862307C:: @ 862307C
     .incbin "baserom.gba", 0x62307c, 0x5C

gUnknown_086230D8:: @ 86230D8
	.incbin "baserom.gba", 0x6230d8, 0xc

gUnknown_086230E4:: @ 86230E4
	.4byte NULL
	.4byte sub_81CC848
	.4byte sub_81CC878
	.4byte sub_81CC8D8
	.4byte sub_81CC95C

gUnknown_086230F8:: @ 86230F8
	obj_tiles gUnknown_08DC9208, 0x800, 6

gUnknown_08623100:: @ 8623100
	obj_pal gUnknown_08DC91E8, 11
	obj_pal NULL, 0

gUnknown_08623110:: @ 8623110
	.incbin "baserom.gba", 0x623110, 0x8

gUnknown_08623118:: @ 8623118
	.4byte 0, gUnknown_08622E6C 
	.4byte 1, gUnknown_08622D98
	.4byte 2, gUnknown_08622E9C
	.4byte 3, gUnknown_08622A7C
	.4byte 4, gUnknown_08622AC0
	.4byte 5, gUnknown_08622FA0
	.4byte 6, gUnknown_08622CAC
	.4byte 7, gUnknown_0862307C
	.4byte 8, gUnknown_08622B58
	.4byte 0x10008, gUnknown_08622BB8
	.4byte 9, gUnknown_08622D44
	.4byte 0x10009, gUnknown_08622CEC
	.4byte 0xA, gUnknown_08622C04
	.4byte 0x1000A, gUnknown_08622C58
	.4byte 0xB, gUnknown_08622B08
	.4byte 0xC, gUnknown_08622E14
	.4byte 0x1000C, gUnknown_08622DC8
	.4byte 0xD, gUnknown_08623020
	.4byte 0x1000D, gUnknown_08622FD8
	.4byte 0xE, gUnknown_08622ED4
	.4byte 0xF, gUnknown_08622F14
	.4byte 0x1000F, gUnknown_08622F5C
	
gUnknown_086231C8:: @ 86231C8
	.2byte 0x4000
	.2byte 0x4000
	.2byte 0x400
	.2byte 0x0

gUnknown_086231D0:: @ 86231D0
	spr_template 6, 11, gUnknown_086231C8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81CCEF4

gUnknown_086231E8:: @ 86231E8
	.incbin "baserom.gba", 0x6231e8, 0x20

gUnknown_08623208:: @ 8623208
	.incbin "baserom.gba", 0x623208, 0x20

gUnknown_08623228:: @ 8623228
	.incbin "baserom.gba", 0x623228, 0x14

gUnknown_0862323C:: @ 862323C
	.incbin "baserom.gba", 0x62323c, 0xfc

gUnknown_08623338:: @ 8623338
	.incbin "baserom.gba", 0x623338, 0x20

gUnknown_08623358:: @ 8623358
	.incbin "baserom.gba", 0x623358, 0xc

gUnknown_08623364:: @ 8623364
	.incbin "baserom.gba", 0x623364, 0x8

gUnknown_0862336C:: @ 862336C
	.incbin "baserom.gba", 0x62336c, 0x8

gUnknown_08623374:: @ 8623374
	.incbin "baserom.gba", 0x623374, 0x8

gUnknown_0862337C:: @ 862337C
	.incbin "baserom.gba", 0x62337c, 0x8

gUnknown_08623384:: @ 8623384
	.4byte NULL
	.4byte sub_81CE37C
	.4byte sub_81CE2D0
	.4byte sub_81CE4D8
	.4byte sub_81CE5E4
	.4byte sub_81CE6BC
	.4byte sub_81CE700

gUnknown_086233A0:: @ 86233A0
	.incbin "baserom.gba", 0x6233a0, 0x14

gUnknown_086233B4:: @ 86233B4
	.incbin "baserom.gba", 0x6233b4, 0x10

gUnknown_086233C4:: @ 86233C4
	.incbin "baserom.gba", 0x6233c4, 0x20

gUnknown_086233E4:: @ 86233E4
	.incbin "baserom.gba", 0x6233e4, 0xc8

gUnknown_086234AC:: @ 86234AC
	.incbin "baserom.gba", 0x6234ac, 0xc4

gUnknown_08623570:: @ 8623570
	.incbin "baserom.gba", 0x623570, 0x20

gUnknown_08623590:: @ 8623590
	.incbin "baserom.gba", 0x623590, 0x4

gUnknown_08623594:: @ 8623594
	.incbin "baserom.gba", 0x623594, 0x4

gUnknown_08623598:: @ 8623598
	.4byte NULL
	.4byte sub_81CF578
	.4byte sub_81CF5F0
	.4byte sub_81CF668
	.4byte sub_81CF6E0
	.4byte sub_81CF758
	.4byte sub_81CF798

gUnknown_086235B4:: @ 86235B4
	.incbin "baserom.gba", 0x6235b4, 0x8

gUnknown_086235BC:: @ 86235BC
	.incbin "baserom.gba", 0x6235bc, 0xc

gUnknown_086235C8:: @ 86235C8
	.incbin "baserom.gba", 0x6235c8, 0xc

gUnknown_086235D4:: @ 86235D4
	.incbin "baserom.gba", 0x6235d4, 0x4

gUnknown_086235D8:: @ 86235D8
	.incbin "baserom.gba", 0x6235d8, 0xc

gUnknown_086235E4:: @ 86235E4
	.incbin "baserom.gba", 0x6235e4, 0x20

gUnknown_08623604:: @ 8623604
	.incbin "baserom.gba", 0x623604, 0xc8

gUnknown_086236CC:: @ 86236CC
	.incbin "baserom.gba", 0x6236cc, 0xc4

gUnknown_08623790:: @ 8623790
	.incbin "baserom.gba", 0x623790, 0x20

gUnknown_086237B0:: @ 86237B0
	.incbin "baserom.gba", 0x6237b0, 0x4

gUnknown_086237B4:: @ 86237B4
	.incbin "baserom.gba", 0x6237b4, 0x4

gUnknown_086237B8:: @ 86237B8
	.incbin "baserom.gba", 0x6237b8, 0x1c

gUnknown_086237D4:: @ 86237D4
	.incbin "baserom.gba", 0x6237d4, 0x8

gUnknown_086237DC:: @ 86237DC
	.incbin "baserom.gba", 0x6237dc, 0xc

gUnknown_086237E8:: @ 86237E8
	.incbin "baserom.gba", 0x6237e8, 0xc

gUnknown_086237F4:: @ 86237F4
	.incbin "baserom.gba", 0x6237f4, 0x4

gUnknown_086237F8:: @ 86237F8
	.incbin "baserom.gba", 0x6237f8, 0x44

@ 862383C
	.include "data/text/ribbon_descriptions.inc"

@ 8623A74
	.include "data/text/gift_ribbon_descriptions.inc"

gUnknown_08623FF8:: @ 8623FF8
     .incbin "baserom.gba", 0x623ff8, 0x20

gUnknown_08624018:: @ 8624018
     .incbin "baserom.gba", 0x624018, 0x20

gUnknown_08624038:: @ 8624038
     .incbin "baserom.gba", 0x624038, 0x20

gUnknown_08624058:: @ 8624058
     .incbin "baserom.gba", 0x624058, 0x20

gUnknown_08624078:: @ 8624078
     .incbin "baserom.gba", 0x624078, 0x20

gUnknown_08624098:: @ 8624098
     .incbin "baserom.gba", 0x624098, 0x20

gUnknown_086240B8:: @ 86240B8
     .incbin "baserom.gba", 0x6240b8, 0x1C8

gUnknown_08624280:: @ 8624280
     .incbin "baserom.gba", 0x624280, 0x918

gUnknown_08624B98:: @ 8624B98
	.incbin "baserom.gba", 0x624b98, 0x8

gUnknown_08624BA0:: @ 8624BA0
	.incbin "baserom.gba", 0x624ba0, 0x18

gUnknown_08624BB8:: @ 8624BB8
	.incbin "baserom.gba", 0x624bb8, 0x8

gUnknown_08624BC0:: @ 8624BC0
	.incbin "baserom.gba", 0x624bc0, 0x4

gUnknown_08624BC4:: @ 8624BC4
	.incbin "baserom.gba", 0x624bc4, 0x8

gUnknown_08624BCC:: @ 8624BCC
	.incbin "baserom.gba", 0x624bcc, 0xc

gUnknown_08624BD8:: @ 8624BD8
	.incbin "baserom.gba", 0x624bd8, 0xc

gUnknown_08624BE4:: @ 8624BE4
	.incbin "baserom.gba", 0x624be4, 0x4

gUnknown_08624BE8:: @ 8624BE8
	.incbin "baserom.gba", 0x624be8, 0x10

gUnknown_08624BF8:: @ 8624BF8
	.incbin "baserom.gba", 0x624bf8, 0x80

gUnknown_08624C78:: @ 8624C78
	obj_tiles gUnknown_08624280, 0x1800, 9

gUnknown_08624C80:: @ 8624C80
	obj_pal gUnknown_08623FF8, 15
	obj_pal gUnknown_08624018, 16
	obj_pal gUnknown_08624038, 17
	obj_pal gUnknown_08624058, 18
	obj_pal gUnknown_08624078, 19
	obj_pal NULL, 0

gUnknown_08624CB0:: @ 8624CB0
	.incbin "baserom.gba", 0x624cb0, 0x54
	
gUnknown_08624D04:: @ 8624D04
     .incbin "baserom.gba", 0x624d04, 0x78

gUnknown_08624D7C:: @ 8624D7C
     .incbin "baserom.gba", 0x624d7c, 0x60

gUnknown_08624DDC:: @ 8624DDC
     .incbin "baserom.gba", 0x624ddc, 0x14

gUnknown_08624DF0:: @ 8624DF0
     .incbin "baserom.gba", 0x624df0, 0x2C

gUnknown_08624E1C:: @ 8624E1C
     .incbin "baserom.gba", 0x624e1c, 0x50

gUnknown_08624E6C:: @ 8624E6C
     .incbin "baserom.gba", 0x624e6c, 0x90

gUnknown_08624EFC:: @ 8624EFC
     .incbin "baserom.gba", 0x624efc, 0x90

gUnknown_08624F8C:: @ 8624F8C
     .incbin "baserom.gba", 0x624f8c, 0x60

gUnknown_08624FEC:: @ 8624FEC
     .incbin "baserom.gba", 0x624fec, 0x54

gUnknown_08625040:: @ 8625040
     .incbin "baserom.gba", 0x625040, 0x38

gUnknown_08625078:: @ 8625078
     .incbin "baserom.gba", 0x625078, 0x3C

gUnknown_086250B4:: @ 86250B4
     .incbin "baserom.gba", 0x6250b4, 0x3C

gUnknown_086250F0:: @ 86250F0
     .incbin "baserom.gba", 0x6250f0, 0x3C

gUnknown_0862512C:: @ 862512C
     .incbin "baserom.gba", 0x62512c, 0x3C

gUnknown_08625168:: @ 8625168
     .incbin "baserom.gba", 0x625168, 0x3C

gUnknown_086251A4:: @ 86251A4
     .incbin "baserom.gba", 0x6251a4, 0x3C

gUnknown_086251E0:: @ 86251E0
     .incbin "baserom.gba", 0x6251e0, 0x24

gUnknown_08625204:: @ 8625204
     .incbin "baserom.gba", 0x625204, 0x24

gUnknown_08625228:: @ 8625228
     .incbin "baserom.gba", 0x625228, 0x24

gUnknown_0862524C:: @ 862524C
     .incbin "baserom.gba", 0x62524c, 0x24

gUnknown_08625270:: @ 8625270
     .incbin "baserom.gba", 0x625270, 0x24

gUnknown_08625294:: @ 8625294
     .incbin "baserom.gba", 0x625294, 0x14

gUnknown_086252A8:: @ 86252A8
	.4byte gUnknown_08624D7C
    .4byte gUnknown_08624DF0
    .4byte gUnknown_08624F8C
    .4byte gUnknown_08624EFC
    .4byte gUnknown_08624FEC
    .4byte gUnknown_08624DDC
    .4byte gUnknown_08624E1C
    .4byte gUnknown_08624E6C
    .4byte gUnknown_08625040
    .4byte gUnknown_08625078
    .4byte gUnknown_086250B4
    .4byte gUnknown_086250F0
    .4byte gUnknown_0862512C
    .4byte gUnknown_08625168
    .4byte gUnknown_086251A4
    .4byte gUnknown_086251E0
    .4byte gUnknown_08625204
    .4byte gUnknown_08625228
    .4byte gUnknown_0862524C
    .4byte gUnknown_08625270
    .4byte gUnknown_08625294

gUnknown_086252FC:: @ 86252FC
	.4byte sub_81D1628
	.4byte sub_81D164C
	.4byte sub_81D1670
	.4byte sub_81D1694
	.4byte sub_81D16CC

gUnknown_08625310:: @ 8625310
	.4byte sub_81D1714
	.4byte sub_81D1718
	.4byte sub_81D171C
	.4byte sub_81D1750
	.4byte sub_81D1754

gUnknown_08625324:: @ 8625324
	.4byte sub_81D178C
	.4byte sub_81D1790
	.4byte sub_81D17C0
	.4byte sub_81D17E0
	.4byte sub_81D17E4

gUnknown_08625338:: @ 8625338
	.incbin "baserom.gba", 0x625338, 0x14

gUnknown_0862534C:: @ 862534C
	.incbin "baserom.gba", 0x62534c, 0x14

gUnknown_08625360:: @ 8625360
	.incbin "baserom.gba", 0x625360, 0x14

gUnknown_08625374:: @ 8625374
	.incbin "baserom.gba", 0x625374, 0x14

gUnknown_08625388:: @ 8625388
	.incbin "baserom.gba", 0x625388, 0x60

gUnknown_086253E8:: @ 86253E8
	.incbin "baserom.gba", 0x6253e8, 0x18

gUnknown_08625400:: @ 8625400
	.incbin "baserom.gba", 0x625400, 0x3

gUnknown_08625403:: @ 8625403
	.incbin "baserom.gba", 0x625403, 0x1

gUnknown_08625404:: @ 8625404
	.incbin "baserom.gba", 0x625404, 0xc

gUnknown_08625410:: @ 8625410
	.incbin "baserom.gba", 0x625410, 0x100

gUnknown_08625510:: @ 8625510
	.incbin "baserom.gba", 0x625510, 0x30

gUnknown_08625540:: @ 8625540
	.incbin "baserom.gba", 0x625540, 0x8

gUnknown_08625548:: @ 8625548
	.incbin "baserom.gba", 0x625548, 0x500

gUnknown_08625A48:: @ 8625A48
	.incbin "baserom.gba", 0x625a48, 0x8

gUnknown_08625A50:: @ 8625A50
	.incbin "baserom.gba", 0x625a50, 0x18

gUnknown_08625A68:: @ 8625A68
	.incbin "baserom.gba", 0x625a68, 0x8

gUnknown_08625A70:: @ 8625A70
	.incbin "baserom.gba", 0x625a70, 0x20

gUnknown_08625A90:: @ 8625A90
	.incbin "baserom.gba", 0x625a90, 0x18

gUnknown_08625AA8:: @ 8625AA8
	.incbin "baserom.gba", 0x625aa8, 0x18

gUnknown_08625AC0:: @ 8625AC0
	.incbin "baserom.gba", 0x625ac0, 0x8

gUnknown_08625AC8:: @ 8625AC8
	.incbin "baserom.gba", 0x625ac8, 0x4c

gUnknown_08625B14:: @ 8625B14
	.incbin "baserom.gba", 0x625b14, 0x18

gUnknown_08625B2C:: @ 8625B2C
	.incbin "baserom.gba", 0x625b2c, 0x28

gUnknown_08625B54:: @ 8625B54
	.4byte gUnknown_085EEA46
	.4byte gUnknown_085EEA4E
	.4byte gUnknown_085EEA55
	.4byte gUnknown_085EEA63
	.4byte gUnknown_085EEA6B
	.4byte gUnknown_085EEA5D

gUnknown_08625B6C:: @ 8625B6C
	.incbin "baserom.gba", 0x625b6c, 0x520

gUnknown_0862608C:: @ 862608C
	.incbin "baserom.gba", 0x62608c, 0x2

gUnknown_0862608E:: @ 862608E
	.incbin "baserom.gba", 0x62608e, 0x4326

gUnknown_0862A3B4:: @ 862A3B4
	.incbin "baserom.gba", 0x62a3b4, 0x218

gUnknown_0862A5CC:: @ 862A5CC
	.incbin "baserom.gba", 0x62a5cc, 0x8

gUnknown_0862A5D4:: @ 862A5D4
	.incbin "baserom.gba", 0x62a5d4, 0x20

gUnknown_0862A5F4:: @ 862A5F4
	.incbin "baserom.gba", 0x62a5f4, 0x4

gUnknown_0862A5F8:: @ 862A5F8
	.incbin "baserom.gba", 0x62a5f8, 0x20

gUnknown_0862A618:: @ 862A618
	.4byte sub_81D581C
	.4byte sub_81D58D8
	.4byte sub_81D5924
	.4byte sub_81D59D0
	.4byte sub_81D5A70
	.4byte sub_81D5AB4
	.4byte sub_81D5AD0
	.4byte sub_81D5B2C
	.4byte sub_81D5BBC
	.4byte sub_81D5C00
	.4byte sub_81D5C5C
	.4byte sub_81D62B4
	.4byte sub_81D64AC
	.4byte sub_81D64DC
	.4byte sub_81D64FC
	.4byte sub_81D6518
	.4byte sub_81D6568
	.4byte sub_81D65A0

gUnknown_0862A660:: @ 862A660
	.4byte gUnknown_085EB32D
	.4byte gUnknown_085EB33E
	.4byte gUnknown_085EB350
	.4byte gUnknown_085EB361

gUnknown_0862A670:: @ 862A670
	.incbin "baserom.gba", 0x62a670, 0x18

gUnknown_0862A688:: @ 862A688
	.incbin "baserom.gba", 0x62a688, 0x10

gUnknown_0862A698:: @ 862A698
	.incbin "baserom.gba", 0x62a698, 0x8
