	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	


gUnknown_08625AD0:: @ 8625AD0
	.2byte 0
	.2byte 0x4000
	.2byte 0
	.2byte 0
	
gUnknown_08625AD8:: @ 8625AD8
	.2byte 0
	.2byte 5
	.2byte 4
	.2byte 5
	
gUnknown_08625AE0:: @ 8625AE0
	.2byte 8
	.2byte 5
	.2byte 12
	.2byte 5
	
gUnknown_08625AE8:: @ 8625AE8
	.2byte 16
	.2byte 5
	.2byte 20
	.2byte 5
	
gUnknown_08625AF0:: @ 8625AF0
	.2byte 24
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_08625AF8:: @ 8625AF8
	.4byte gUnknown_08625AD8
	.4byte gUnknown_08625AE0
	
gUnknown_08625B00:: @ 8625B00
	.4byte gUnknown_08625AE8
	.4byte gUnknown_08625AF0
	
gUnknown_08625B08:: @ 8625B08
	.4byte gUnknown_08625AF8
	.4byte gUnknown_08625B00
	.4byte gUnknown_08625B08

gUnknown_08625B14:: @ 8625B14
	spr_template 0x68, 0x68, gUnknown_08625AD0, gUnknown_08625AF8, NULL gDummySpriteAffineAnimTable, sub_81D3564

gUnknown_08625B2C:: @ 8625B2C
	.2byte 0, 0xFFDD
	.2byte 20, 0xFFE4
	.2byte 33, 0xFFF6
	.2byte 33, 10
	.2byte 20, 28
	.2byte 0, 35
	.2byte 0xFFEC, 28
	.2byte 0xFFDF, 10
	.2byte 0xFFDF, 0xFFF6
	.2byte 0xFFEC, 0xFFE4

gUnknown_08625B54:: @ 8625B54
	.4byte gUnknown_085EEA46
	.4byte gUnknown_085EEA4E
	.4byte gUnknown_085EEA55
	.4byte gUnknown_085EEA63
	.4byte gUnknown_085EEA6B
	.4byte gUnknown_085EEA5D
