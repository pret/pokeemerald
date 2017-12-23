#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0860F13C:: @ 860F13C
	.incbin "graphics/unknown/unknown_60F13C.gbapal"

	.align 2
gUnknown_0860F15C:: @ 860F15C
	.incbin "graphics/unknown/unknown_60F15C.gbapal"

	.align 2
gUnknown_0860F17C:: @ 860F17C
	.incbin "graphics/unknown/unknown_60F17C.gbapal"

	.align 2
gUnknown_0860F1BC:: @ 860F1BC
	.incbin "graphics/unknown/unknown_60F1BC.4bpp"

	.align 2
gUnknown_0860F3BC:: @ 860F3BC
	.incbin "graphics/unknown/unknown_60F3BC.4bpp"

	.align 2
gUnknown_0860F43C:: @ 860F43C
	.incbin "graphics/unknown/unknown_60F43C.4bpp"

	.align 2
gUnknown_0860F53C:: @ 860F53C
	.incbin "graphics/unknown/unknown_60F53C.4bpp"

	.align 2
gUnknown_0860F63C:: @ 860F63C
	.incbin "graphics/unknown/unknown_60F63C.4bpp"

	.align 2
gUnknown_0860F6BC:: @ 860F6BC
	.incbin "graphics/unknown/unknown_60F6BC.4bpp"

	.align 2
gUnknown_0860F7BC:: @ 860F7BC
	.incbin "graphics/unknown/unknown_60F7BC.4bpp"

	.align 2
gUnknown_0860F83C:: @ 860F83C
	.incbin "graphics/unknown/unknown_60F83C.4bpp"

	.align 2
gUnknown_0860F93C:: @ 860F93C
	.incbin "graphics/unknown/unknown_60F93C.4bpp"

	.align 2
gUnknown_0860FA3C:: @ 860FA3C
	.incbin "graphics/unknown/unknown_60FA3C.4bpp"

	.align 2
gUnknown_0861023C:: @ 861023C
	.incbin "graphics/unknown/unknown_61023C.bin"

	.align 2
gUnknown_0861033C:: @ 861033C
	.incbin "graphics/unknown/unknown_61033C.4bpp"

	.align 2
gUnknown_0861039C:: @ 861039C
	.incbin "graphics/unknown/unknown_61039C.gbapal"

	.align 2
gUnknown_086103BC:: @ 86103BC
	obj_tiles gUnknown_0860F3BC, 0x0080, 0x0065
	obj_tiles gUnknown_0860F43C, 0x0100, 0x0066
	obj_tiles gUnknown_0860F53C, 0x0100, 0x0067
	obj_tiles gUnknown_0860FA3C, 0x0800, 0x006d
	null_obj_tiles

	.align 2
gUnknown_086103E4:: @ 86103E4
	obj_tiles gUnknown_085B18AC, 0x0800, 0x0064
	null_obj_tiles

	.align 2
gUnknown_086103F4:: @ 86103F4
	obj_pal gUnknown_0860F13C, 0x0064
	obj_pal gUnknown_0860F15C, 0x0065
	obj_pal gUnknown_0860F17C, 0x0066
	obj_pal gUnknown_0861039C, 0x0067
	null_obj_pal

	.align 2
gUnknown_0861041C:: @ 861041C
	.4byte sub_819BCCC
	.4byte sub_819BC30
	.4byte sub_819BCD0

	.align 2
gUnknown_08610428:: @ 8610428
	.4byte 0x00000180, 0x00003195, 0x000021bb

	.align 2
gUnknown_08610434:: @ 8610434
	window_template 0x00, 0x00, 0x02, 0x0c, 0x02, 0x0f, 0x0001
	window_template 0x00, 0x13, 0x02, 0x0b, 0x02, 0x0e, 0x0019
	window_template 0x00, 0x00, 0x0f, 0x14, 0x03, 0x0f, 0x002f
	window_template 0x00, 0x16, 0x0e, 0x08, 0x06, 0x0f, 0x006b
	window_template 0x00, 0x16, 0x0e, 0x08, 0x04, 0x0f, 0x009b
	window_template 0x00, 0x0f, 0x00, 0x0f, 0x02, 0x0f, 0x00bb
	window_template_terminator

	.align 1
gUnknown_0861046C:: @ 861046C
	.incbin "graphics/unknown/unknown_61046C.gbapal"

gUnknown_08610476:: @ 8610476
	.byte 0x00, 0x02, 0x00

gUnknown_08610479:: @ 8610479
	.byte 0x00, 0x04, 0x00

	.align 2
gUnknown_0861047C:: @ 861047C
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x0c, 0x00, 0x00

	.align 2
gUnknown_08610484:: @ 8610484
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x0c, 0x00, 0x00

	.align 2
gUnknown_0861048C:: @ 861048C
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_08610494:: @ 8610494
	.byte 0x00, 0x07, 0x00, 0xc0, 0x00, 0x00, 0x01, 0x00

	.align 2
gUnknown_0861049C:: @ 861049C
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_086104A4:: @ 86104A4
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_086104AC:: @ 86104AC
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_086104B4:: @ 86104B4
	.2byte 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004, 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004
	.2byte 0x0000, 0x0020, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008, 0x0000, 0x0008, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_086104FC:: @ 86104FC
	.4byte gUnknown_0861049C

	.align 2
gUnknown_08610500:: @ 8610500
	.4byte gUnknown_086104A4

	.align 2
gUnknown_08610504:: @ 8610504
	.4byte gUnknown_086104AC
	.4byte gUnknown_086104B4

	.align 2
gUnknown_0861050C:: @ 861050C
	.2byte 0x0005, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0010, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0020, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0040, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0080, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0100, 0x0005, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0861056C:: @ 861056C
	.2byte 0x0080, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0040, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0020, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0010, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0005, 0x0005, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_086105BC:: @ 86105BC
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_086105CC:: @ 86105CC
	.4byte gUnknown_0861050C
	.4byte gUnknown_0861056C
	.4byte gUnknown_086105BC

	.align 2
gUnknown_086105D8:: @ 86105D8
	spr_template 0x0064, 0x0064, gUnknown_0861047C, gUnknown_08610504, NULL, gDummySpriteAffineAnimTable, sub_819A44C

	.align 2
gUnknown_086105F0:: @ 86105F0
	spr_template 0x0065, 0x0066, gUnknown_08610484, gUnknown_086104FC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08610608:: @ 8610608
	spr_template 0x0066, 0x0066, gUnknown_0861048C, gUnknown_086104FC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08610620:: @ 8610620
	spr_template 0x0067, 0x0066, gUnknown_0861048C, gUnknown_086104FC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08610638:: @ 8610638
	spr_template 0x006d, 0x0067, gUnknown_08610494, gUnknown_08610500, NULL, gUnknown_086105CC, SpriteCallbackDummy

	.align 2
gUnknown_08610650:: @ 8610650
	obj_tiles gUnknown_0860F3BC, 0x0080, 0x0065
	obj_tiles gUnknown_0860F43C, 0x0100, 0x0066
	obj_tiles gUnknown_0860F53C, 0x0100, 0x0067
	obj_tiles gUnknown_0860F63C, 0x0080, 0x0068
	obj_tiles gUnknown_0860F6BC, 0x0100, 0x0069
	obj_tiles gUnknown_0860F7BC, 0x0100, 0x006a
	obj_tiles gUnknown_0860F83C, 0x0100, 0x006b
	obj_tiles gUnknown_0860F93C, 0x0100, 0x006c
	obj_tiles gUnknown_0860FA3C, 0x0800, 0x006d
	null_obj_tiles

	.align 2
gUnknown_086106A0:: @ 86106A0
	obj_tiles gUnknown_085B18AC, 0x0800, 0x0064
	null_obj_tiles

	.align 2
gUnknown_086106B0:: @ 86106B0
	obj_pal gUnknown_0860F13C, 0x0064
	obj_pal gUnknown_0860F15C, 0x0065
	obj_pal gUnknown_0860F17C, 0x0066
	obj_pal gUnknown_0861039C, 0x0067
	null_obj_pal

	.align 2
gUnknown_086106D8:: @ 86106D8
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x0c, 0x00, 0x00

	.align 2
gUnknown_086106E0:: @ 86106E0
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x0c, 0x00, 0x00

	.align 2
gUnknown_086106E8:: @ 86106E8
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_086106F0:: @ 86106F0
	.byte 0x00, 0x07, 0x00, 0xc0, 0x00, 0x00, 0x01, 0x00

	.align 2
gUnknown_086106F8:: @ 86106F8
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08610700:: @ 8610700
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_08610708:: @ 8610708
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_08610710:: @ 8610710
	.2byte 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004, 0x0010, 0x0004, 0x0000, 0x0004, 0x0020, 0x0004, 0x0000, 0x0004
	.2byte 0x0000, 0x0020, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008, 0x0000, 0x0008, 0x0010, 0x0008, 0x0000, 0x0008, 0x0020, 0x0008
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_08610758:: @ 8610758
	.4byte gUnknown_086106F8

	.align 2
gUnknown_0861075C:: @ 861075C
	.4byte gUnknown_08610700

	.align 2
gUnknown_08610760:: @ 8610760
	.4byte gUnknown_08610708
	.4byte gUnknown_08610710

	.align 2
gUnknown_08610768:: @ 8610768
	.2byte 0x0005, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0010, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0020, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0040, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0080, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0100, 0x0005, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_086107C8:: @ 86107C8
	.2byte 0x0080, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0040, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0020, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0010, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000
	.2byte 0x0005, 0x0005, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08610818:: @ 8610818
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08610828:: @ 8610828
	.4byte gUnknown_08610768
	.4byte gUnknown_086107C8
	.4byte gUnknown_08610818

	.align 2
gUnknown_08610834:: @ 8610834
	spr_template 0x0064, 0x0064, gUnknown_086106D8, gUnknown_08610760, NULL, gDummySpriteAffineAnimTable, sub_819A44C

	.align 2
gUnknown_0861084C:: @ 861084C
	spr_template 0x0065, 0x0066, gUnknown_086106E0, gUnknown_08610758, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08610864:: @ 8610864
	spr_template 0x0066, 0x0066, gUnknown_086106E8, gUnknown_08610758, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0861087C:: @ 861087C
	spr_template 0x0067, 0x0066, gUnknown_086106E8, gUnknown_08610758, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08610894:: @ 8610894
	spr_template 0x006d, 0x0067, gUnknown_086106F0, gUnknown_0861075C, NULL, gUnknown_08610828, SpriteCallbackDummy

	.align 2
gUnknown_086108AC:: @ 86108AC
	.4byte sub_819F114
	.4byte sub_819F0CC
	.4byte sub_819F134

	.align 2
gUnknown_086108B8:: @ 86108B8
	.4byte 0x00001180, 0x00003195, 0x000001aa, 0x000021bb

	.align 2
gUnknown_086108C8:: @ 86108C8
	window_template 0x00, 0x00, 0x02, 0x0c, 0x02, 0x0f, 0x0001
	window_template 0x02, 0x13, 0x02, 0x0b, 0x02, 0x0e, 0x0019
	window_template 0x00, 0x00, 0x0f, 0x14, 0x03, 0x0f, 0x002f
	window_template 0x00, 0x15, 0x0e, 0x09, 0x06, 0x0f, 0x006b
	window_template 0x00, 0x16, 0x0e, 0x08, 0x04, 0x0f, 0x00a1
	window_template 0x02, 0x15, 0x0f, 0x09, 0x05, 0x0e, 0x006b
	window_template 0x02, 0x0a, 0x02, 0x04, 0x02, 0x0e, 0x00c1
	window_template 0x00, 0x13, 0x02, 0x0b, 0x02, 0x0f, 0x00c9
	window_template 0x00, 0x0f, 0x00, 0x0f, 0x02, 0x0f, 0x00df
	window_template_terminator

gUnknown_08610918:: @ 8610918
	.byte 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00, 0x00, 0x1f, 0x00

gUnknown_08610922:: @ 8610922
	.byte 0x00, 0x02, 0x00

gUnknown_08610925:: @ 8610925
	.byte 0x00, 0x04, 0x00

	.align 2
gUnknown_08610928:: @ 8610928
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000003, sub_819F1AC

	.align 2
gUnknown_08610948:: @ 8610948
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000001, sub_819F20C
	.4byte 0x00000002, sub_819F1DC
	.4byte 0x00000003, sub_819F1AC

	.align 2 @ struct, eight bytes x6 for names in different languages, then 0x28 more bytes of data
gUnknown_08610970:: @ 8610970
	.incbin "baserom.gba", 0x610970, 0x580

	.align 2
gUnknown_08610EF0:: @ 8610EF0
	.incbin "baserom.gba", 0x610ef0, 0x100

gUnknown_08610FF0:: @ 8610FF0
	.incbin "baserom.gba", 0x610ff0, 0x80

gUnknown_08611070:: @ 8611070
	.incbin "baserom.gba", 0x611070, 0x140

gUnknown_086111B0:: @ 86111B0
	.incbin "baserom.gba", 0x6111b0, 0x80

gUnknown_08611230:: @ 8611230
	.incbin "baserom.gba", 0x611230, 0x80

gUnknown_086112B0:: @ 86112B0
	.incbin "baserom.gba", 0x6112b0, 0x80

gUnknown_08611330:: @ 8611330
	.incbin "baserom.gba", 0x611330, 0x40

gUnknown_08611370:: @ 8611370
	.incbin "baserom.gba", 0x611370, 0x163

gUnknown_086114D3:: @ 86114D3
	.incbin "baserom.gba", 0x6114d3, 0xd

gUnknown_086114E0:: @ 86114E0
	.incbin "baserom.gba", 0x6114e0, 0x68

gUnknown_08611548:: @ 8611548
	.incbin "baserom.gba", 0x611548, 0x8

gUnknown_08611550:: @ 8611550
	.incbin "baserom.gba", 0x611550, 0x1c

gUnknown_0861156C:: @ 861156C
	.incbin "baserom.gba", 0x61156c, 0xc

gUnknown_08611578:: @ 8611578
	.incbin "baserom.gba", 0x611578, 0x33c

gUnknown_086118B4:: @ 86118B4
	.incbin "baserom.gba", 0x6118b4, 0x348

gUnknown_08611BFC:: @ 8611BFC
	.incbin "baserom.gba", 0x611bfc, 0x1c

gUnknown_08611C18:: @ 8611C18
	.incbin "baserom.gba", 0x611c18, 0x5c

gUnknown_08611C74:: @ 8611C74
	.incbin "baserom.gba", 0x611c74, 0x8

gUnknown_08611C7C:: @ 8611C7C
	.incbin "baserom.gba", 0x611c7c, 0x8

gUnknown_08611C84:: @ 8611C84
	.incbin "baserom.gba", 0x611c84, 0x8

gUnknown_08611C8C:: @ 8611C8C
	.incbin "baserom.gba", 0x611c8c, 0xe

gUnknown_08611C9A:: @ 8611C9A
	.incbin "baserom.gba", 0x611c9a, 0x16

gUnknown_08611CB0:: @ 8611CB0
	.incbin "baserom.gba", 0x611cb0, 0x50

gUnknown_08611D00:: @ 8611D00
	.incbin "baserom.gba", 0x611d00, 0x8

gUnknown_08611D08:: @ 8611D08
	.incbin "baserom.gba", 0x611d08, 0x28

gUnknown_08611D30:: @ 8611D30
	.incbin "baserom.gba", 0x611d30, 0x80

gUnknown_08611DB0:: @ 8611DB0
	.incbin "baserom.gba", 0x611db0, 0x8

gUnknown_08611DB8:: @ 8611DB8
	.incbin "baserom.gba", 0x611db8, 0x8

@ 8611DC0
	.include "data/battle_frontier/battle_arena_move_mind_ratings.inc"

	.align 2
@ 8611F24
	.incbin "baserom.gba", 0x611f24, 0x38

gUnknown_08611F5C:: @ 8611F5C
	.incbin "baserom.gba", 0x611f5c, 0x18

gUnknown_08611F74:: @ 8611F74
	.incbin "baserom.gba", 0x611f74, 0x10

gUnknown_08611F84:: @ 8611F84
	.incbin "baserom.gba", 0x611f84, 0x1c

gUnknown_08611FA0:: @ 8611FA0
	.incbin "baserom.gba", 0x611fa0, 0xc

gUnknown_08611FAC:: @ 8611FAC
	.incbin "baserom.gba", 0x611fac, 0x14

@ 8611FC0
	.include "data/battle_frontier/battle_factory_style_move_lists.inc"

gUnknown_08612120:: @ 8612120
	.incbin "baserom.gba", 0x612120, 0x44

gUnknown_08612164:: @ 8612164
	.incbin "baserom.gba", 0x612164, 0x10

gUnknown_08612174:: @ 8612174
	.incbin "baserom.gba", 0x612174, 0x10

gUnknown_08612184:: @ 8612184
	.incbin "baserom.gba", 0x612184, 0x10

gUnknown_08612194:: @ 8612194
	.incbin "baserom.gba", 0x612194, 0x180

gUnknown_08612314:: @ 8612314
	.incbin "baserom.gba", 0x612314, 0x8

gUnknown_0861231C:: @ 861231C
	.incbin "baserom.gba", 0x61231c, 0xc8

gUnknown_086123E4:: @ 86123E4
	.incbin "baserom.gba", 0x6123e4, 0x1f8

gUnknown_086125DC:: @ 86125DC
	.incbin "baserom.gba", 0x6125dc, 0x1c

gUnknown_086125F8:: @ 86125F8
	.incbin "baserom.gba", 0x6125f8, 0x74

gUnknown_0861266C:: @ 861266C
	.incbin "baserom.gba", 0x61266c, 0x9

gUnknown_08612675:: @ 8612675
	.incbin "baserom.gba", 0x612675, 0x13

gUnknown_08612688:: @ 8612688
	.incbin "baserom.gba", 0x612688, 0x8

gUnknown_08612690:: @ 8612690
	.incbin "baserom.gba", 0x612690, 0x8

gUnknown_08612698:: @ 8612698
	.incbin "baserom.gba", 0x612698, 0x4

gUnknown_0861269C:: @ 861269C
	.incbin "baserom.gba", 0x61269c, 0x4

gUnknown_086126A0:: @ 86126A0
	.incbin "baserom.gba", 0x6126a0, 0x4

gUnknown_086126A4:: @ 86126A4
	.incbin "baserom.gba", 0x6126a4, 0x4

gUnknown_086126A8:: @ 86126A8
	.incbin "baserom.gba", 0x6126a8, 0x2

gUnknown_086126AA:: @ 86126AA
	.incbin "baserom.gba", 0x6126aa, 0x2

gUnknown_086126AC:: @ 86126AC
	.incbin "baserom.gba", 0x6126ac, 0x2

gUnknown_086126AE:: @ 86126AE
	.incbin "baserom.gba", 0x6126ae, 0x2

@ 86126B0
	.include "data/battle_frontier/battle_pyramid_level_50_wild_mons.inc"

@ 8612E80
	.include "data/battle_frontier/battle_pyramid_open_level_wild_mons.inc"

gUnknown_08613650:: @ 8613650
	.incbin "baserom.gba", 0x613650, 0x5

gUnknown_08613655:: @ 8613655
	.incbin "baserom.gba", 0x613655, 0xfb

gUnknown_08613750:: @ 8613750
	.incbin "baserom.gba", 0x613750, 0x44

gUnknown_08613794:: @ 8613794
	.incbin "baserom.gba", 0x613794, 0x8

gUnknown_0861379C:: @ 861379C
	.incbin "baserom.gba", 0x61379c, 0x190

gUnknown_0861392C:: @ 861392C
	.incbin "baserom.gba", 0x61392c, 0x190

gUnknown_08613ABC:: @ 8613ABC
	.incbin "baserom.gba", 0x613abc, 0x7e

gUnknown_08613B3A:: @ 8613B3A
	.incbin "baserom.gba", 0x613b3a, 0xa

gUnknown_08613B44:: @ 8613B44
	.incbin "baserom.gba", 0x613b44, 0xd8

gUnknown_08613C1C:: @ 8613C1C
	.incbin "baserom.gba", 0x613c1c, 0x2a4

gUnknown_08613EC0:: @ 8613EC0
	.incbin "baserom.gba", 0x613ec0, 0x18

gUnknown_08613ED8:: @ 8613ED8
	.incbin "baserom.gba", 0x613ed8, 0x8

gUnknown_08613EE0:: @ 8613EE0
	.incbin "baserom.gba", 0x613ee0, 0x48

gUnknown_08613F28:: @ 8613F28
	.incbin "baserom.gba", 0x613f28, 0xc

gUnknown_08613F34:: @ 8613F34
	.incbin "baserom.gba", 0x613f34, 0x12

gUnknown_08613F46:: @ 8613F46
	.incbin "baserom.gba", 0x613f46, 0x40

gUnknown_08613F86:: @ 8613F86
	.incbin "baserom.gba", 0x613f86, 0xa
