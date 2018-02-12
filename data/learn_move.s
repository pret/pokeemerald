	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	
gUnknown_085CE9F8:: @ 85CE9F8
	.incbin "graphics/interface/ui_learn_move.gbapal"

gUnknown_085CEA18:: @ 85CEA18
	.incbin "graphics/interface/ui_learn_move.4bpp"
	
gUnknown_085CEB98:: @ 85CEB98
	.2byte 0
	.2byte 0
	.2byte 0
	.2byte 0
	.2byte 0x8000
	.2byte 0
	.2byte 0
	.2byte 0
	.2byte 0x4000
	.2byte 0
	.2byte 0
	.2byte 0

gUnknown_085CEBB0:: @ 85CEBB0
	obj_tiles gUnknown_085CEA18, 0x180, 0x1595

gUnknown_085CEBB8:: @ 85CEBB8
	obj_pal gUnknown_085CE9F8, 0x1596

gUnknown_085CEBC0:: @ 85CEBC0
	.byte 0
	.byte 0x1B
	.byte 16
	.byte 1
	.byte 0x75
	.byte 16
	.2byte 0xFFFF
	.2byte 0xFFFF
	.2byte 0x14CD
	.2byte 0x14CD
	.byte 0, 0

gUnknown_085CEBD0:: @ 85CEBD0
	.byte 2
	.byte 0xC0
	.byte 8
	.byte 3
	.byte 0xC0
	.byte 0x68
	.2byte 0
	.2byte 0
	.2byte 0x1531
	.2byte 0x1531
	.byte 0, 0

gUnknown_085CEBE0:: @ 85CEBE0
	.2byte 8
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_085CEBE8:: @ 85CEBE8
	.2byte 9
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_085CEBF0:: @ 85CEBF0
	.2byte 10
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_085CEBF8:: @ 85CEBF8
	.2byte 11
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_085CEC00:: @ 85CEC00
	.4byte gUnknown_085CEBE0
	.4byte gUnknown_085CEBE8
	.4byte gUnknown_085CEBF0
	.4byte gUnknown_085CEBF8
	
gUnknown_085CEC10:: @ 85CEC10
	spr_template 0x1595, 0x1596, gUnknown_085CEB98, gUnknown_085CEC00, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_085CEC28:: @ 85CEC28
	.4byte 0x1F0
	.4byte 0x11E1
