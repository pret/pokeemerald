	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	
.align 4

gUnknown_085DFA60:: @ 85DFA60
	.incbin "graphics/interface/85DFA60.bin"

gUnknown_085DFA80:: @ 85DFA80
	.incbin "graphics/interface/85DFA80.4bpp"

gUnknown_085DFB60:: @ 85DFB60
	.incbin "graphics/interface/85DFB60.bin"

gUnknown_085DFC0C:: @ 85DFC0C
	.incbin "graphics/interface/85DFC0C.bin"

gUnknown_085DFCB0:: @ 85DFCB0
	.4byte 22, 47, 33, 24, 23

gUnknown_085DFCC4:: @ 85DFCC4
	.byte 0, 4, 3, 2, 1

gUnknown_085DFCC9:: @ 85DFCC9
	.byte 0, 8, 1

gUnknown_085DFCCC:: @ 85DFCCC
	.4byte 0x1F8
	.4byte 0x31E1
	.4byte 0x4021DF
	.4byte 0x1172

gUnknown_085DFCDC:: @ 85DFCDC
	window_template 0, 0xD, 1, 0xD, 4, 0xF, 1
	window_template 0, 0, 0xE, 0xB, 2, 0xF, 0x35
	window_template 0, 1, 0x11, 0x1C, 2, 0xF, 0x4B
	null_window_template

sUsePokeblockYesNoWinTemplate:: @ 85DFCFC
	window_template 0, 0x18, 0xB, 5, 4, 0xF, 0x83

sContestStatNames:: @ 85DFD04
	.4byte gText_Coolness
	.4byte gText_Toughness
	.4byte gText_Smartness
	.4byte gText_Cuteness
	.4byte gText_Beauty3

gSpriteSheet_ConditionUpDown:: @ 85DFD18
	obj_tiles gUsePokeblockUpDown_Gfx, 0x200, 0

gSpritePalette_ConditionUpDown:: @ 85DFD20
	obj_pal gUsePokeblockUpDown_Pal, 0

gUnknown_085DFD28:: @ 85DFD28
	.2byte 0x9c, 0x24
	.2byte 0x75, 0x3b
	.2byte 0x75, 0x76
	.2byte 0xc5, 0x76
	.2byte 0xc5, 0x3b
	
gUnknown_085DFD3C:: @ 85DFD3C
	.2byte 0x4000
	.2byte 0x8000
	.2byte 0x400
	.2byte 0
	
gUnknown_085DFD44:: @ 85DFD44
	obj_image_anim_frame 0, 5
	obj_image_anim_end
	
gUnknown_085DFD4C:: @ 85DFD4C
	obj_image_anim_frame 8, 5
	obj_image_anim_end
	
gUnknown_085DFD54:: @ 85DFD54
	.4byte gUnknown_085DFD44
	.4byte gUnknown_085DFD4C

gSpriteTemplate_085DFD5C:: @ 85DFD5C
	spr_template 0, 0, gUnknown_085DFD3C, gUnknown_085DFD54, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
	
gUnknown_085DFD74:: @ 85DFD74
	.2byte 0x4000
	.2byte 0xC000
	.2byte 0x400
	.2byte 0
	
gUnknown_085DFD7C:: @ 85DFD7C
	obj_image_anim_frame 0, 5
	obj_image_anim_end

gUnknown_085DFD84:: @ 85DFD84
	obj_image_anim_frame 32, 5
	obj_image_anim_end

gUnknown_085DFD8C:: @ 85DFD8C
	obj_image_anim_frame 64, 5
	obj_image_anim_end
	
gUnknown_085DFD94:: @ 85DFD94
	.4byte gUnknown_085DFD7C
	.4byte gUnknown_085DFD84
	.4byte gUnknown_085DFD8C

gUnknown_085DFDA0:: @ 85DFDA0
	spr_template 1, 1, gUnknown_085DFD74, gUnknown_085DFD94, NULL, gDummySpriteAffineAnimTable, sub_8168374

gUnknown_085DFDB8:: @ 85DFDB8
	.4byte gUsePokeblockCondition_Pal
	.4byte 1
