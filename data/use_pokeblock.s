	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	
gUnknown_085DFA60:: @ 85DFA60
	.incbin "baserom.gba", 0x5dfa60, 0x20

gUnknown_085DFA80:: @ 85DFA80
	.incbin "baserom.gba", 0x5dfa80, 0xe0

gUnknown_085DFB60:: @ 85DFB60
	.incbin "baserom.gba", 0x5dfb60, 0xac

gUnknown_085DFC0C:: @ 85DFC0C
	.incbin "baserom.gba", 0x5dfc0c, 0xa4

gUnknown_085DFCB0:: @ 85DFCB0
	.incbin "baserom.gba", 0x5dfcb0, 0x14

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
	window_template_terminator

sUsePokeblockYesNoWinTemplate:: @ 85DFCFC
	window_template 0, 0x18, 0xB, 5, 4, 0xF, 0x83

sContestStatNames:: @ 85DFD04
	.4byte gText_Coolness
	.4byte gText_Toughness
	.4byte gText_Smartness
	.4byte gText_Cuteness
	.4byte gText_Beauty3

gUnknown_085DFD18:: @ 85DFD18
	obj_tiles gUnknown_08DCCD5C, 0x200, 0

gUnknown_085DFD20:: @ 85DFD20
	obj_pal gUnknown_08DCCD3C, 0

gUnknown_085DFD28:: @ 85DFD28
	.incbin "baserom.gba", 0x5dfd28, 0x34

gUnknown_085DFD5C:: @ 85DFD5C
	.incbin "baserom.gba", 0x5dfd5c, 0x44

gUnknown_085DFDA0:: @ 85DFDA0
	.incbin "baserom.gba", 0x5dfda0, 0x18

gUnknown_085DFDB8:: @ 85DFDB8
	.4byte gUnknown_08DCCB98
	.4byte 1
