	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	
gUnknown_08625560:: @ 8625560
	.incbin "graphics/pokenav/pokeball.4bpp"

gUnknown_08625660:: @ 8625660
	.incbin "graphics/pokenav/pokeball_placeholder.4bpp"
	
gUnknown_08625680:: @ 8625680
	.incbin "graphics/pokenav/sparkle.gbapal"
	
gUnknown_086256A0:: @ 86255A0
	.incbin "graphics/pokenav/sparkle.4bpp"
	
gUnknown_08625A20:: @ 8625A20
	.2byte 0
	.2byte 0xC000
	.2byte 0x400
	.2byte 0
	
gUnknown_08625A28:: @ 8625A28
	.2byte 0
	.2byte 0x4000
	.2byte 0x800
	.2byte 0
	
gUnknown_08625A30:: @ 8625A30
	.2byte 0
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_08625A38:: @ 8625A38
	.2byte 4
	.2byte 5
	.2byte 0xFFFF
	.2byte 0
	
gUnknown_08625A40:: @ 8625A40
	.4byte gUnknown_08625A30
	.4byte gUnknown_08625A38

gUnknown_08625A48:: @ 8625A48
	.4byte NULL
	.4byte 0x640800

gUnknown_08625A50:: @ 8625A50
	spr_template 0x64, 0x64, gUnknown_08625A20, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_08625A68:: @ 8625A68
	.4byte NULL
	.4byte 0x64

gUnknown_08625A70:: @ 8625A70
	.4byte gUnknown_08625560
	.byte 0, 1, 0x65, 0
	.4byte gUnknown_08625660
	.2byte 0x20, 0x67
	.4byte gPokenavConditionCancel_Gfx
	.byte 0, 1, 0x66, 0
	.4byte NULL, NULL

gUnknown_08625A90:: @ 8625A90
	.4byte gPokenavConditionCancel_Pal + 0x0
	.byte 0x65, 0, 0, 0
	.4byte gPokenavConditionCancel_Pal + 0x20
	.byte 0x66, 0, 0, 0
	.4byte NULL, NULL

gUnknown_08625AA8:: @ 8625AA8
	spr_template 0x65, 0x65, gUnknown_08625A28, gUnknown_08625A40, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_08625AC0:: @ 8625AC0
	.4byte gUnknown_086256A0
	.byte 0x80, 3, 0x68, 0

gUnknown_08625AC8:: @ 8625AC8
	.4byte gUnknown_08625680
	.byte 0x68, 0, 0, 0
	
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
