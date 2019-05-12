#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082FB63C:: @ 82FB63C
	.2byte 0x001a, 0x001f, 0x0024, 0x0029, 0x002e, 0x0033, 0x0038, 0x003d

	.align 2
gUnknown_082FB64C:: @ 82FB64C
	.2byte 0x0000, 0x0001, 0x0001, 0x0002

	.align 2
gUnknown_082FB654:: @ 82FB654
	.2byte 0x005f, 0x0066, 0x00e4, 0x0105

	.align 2
gUnknown_082FB65C:: @ 82FB65C
	.byte 0xfd, 0xfa, 0xf8, 0xf6, 0xf3, 0xf1, 0xef, 0xed
	.byte 0xeb, 0xe9, 0xe7, 0xe5, 0xe4, 0xe3, 0xe2, 0xe2
	.byte 0xe2, 0xe4, 0xe5, 0xe6, 0xe7, 0xe9, 0xea, 0xec
	.byte 0xee, 0xef, 0xf1, 0xf3, 0xf5, 0xf8, 0xfa, 0xfc
	.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.byte 0xfd, 0xfa, 0xf7, 0xf5, 0xf2, 0xf0, 0xee, 0xec
	.byte 0xea, 0xe8, 0xe6, 0xe4, 0xe3, 0xe2, 0xe2, 0xe4
	.byte 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf5
	.byte 0xf7, 0xfa, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.byte 0xfd, 0xfa, 0xf7, 0xf5, 0xf3, 0xf1, 0xef, 0xed
	.byte 0xeb, 0xe9, 0xe7, 0xe5, 0xe4, 0xe3, 0xe2, 0xe2
	.byte 0xe2, 0xe2, 0xe3, 0xe3, 0xe4, 0xe4, 0xe5, 0xe5
	.byte 0xe6, 0xe7, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2
	.byte 0xf4, 0xf5, 0xf7, 0xfa, 0xfc, 0xff, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FB6EC:: @ 82FB6EC
	.4byte 0x00000000, 0x00000000, 0x00000032, 0x00000064
	.4byte 0x000000c8, 0x000001f4

	.align 2
gUnknown_082FB704:: @ 82FB704
	.2byte 0x008a, 0x008d, 0x008e, 0x008f, 0x0090, 0x0091, 0x0092, 0x0093

	.align 2
gUnknown_082FB714:: @ 82FB714
	.4byte 0x00001388, 0x00000001, 0x00001f40, 0x00000002
	.4byte 0x00002ee0, 0x00000003, 0x00003e80, 0x00000004
	.4byte 0x00004e20, 0x00000005

	.align 2
gPkmnJumpPal1:: @ 82FB73C
	.incbin "graphics/link_games/pkmnjump_pal1.gbapal"

	.align 2
gPkmnJumpPal2:: @ 82FB75C
	.incbin "graphics/link_games/pkmnjump_pal2.gbapal"

	.align 2
gPkmnJumpRopeGfx1:: @ 82FB77C
	.incbin "graphics/link_games/pkmnjump_rope1.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx2:: @ 82FB89C
	.incbin "graphics/link_games/pkmnjump_rope2.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx3:: @ 82FBA70
	.incbin "graphics/link_games/pkmnjump_rope3.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx4:: @ 82FBBA0
	.incbin "graphics/link_games/pkmnjump_rope4.4bpp.lz"

	.align 2
gPkmnJumpStarGfx:: @ 82FBC9C
	.incbin "graphics/link_games/pkmnjump_star.4bpp.lz"

	.align 2
gUnknown_082FBE08:: @ 82FBE08
	obj_tiles gPkmnJumpRopeGfx1, 0x0600, 0x0005

	.align 2
	obj_tiles gPkmnJumpRopeGfx2, 0x0c00, 0x0006

	.align 2
	obj_tiles gPkmnJumpRopeGfx3, 0x0600, 0x0007

	.align 2
	obj_tiles gPkmnJumpRopeGfx4, 0x0600, 0x0008

	.align 2
	obj_tiles gPkmnJumpStarGfx, 0x0200, 0x000a

	.align 2
gUnknown_082FBE30:: @ 82FBE30
	obj_pal gPkmnJumpPal1, 0x0005

	.align 2
	obj_pal gPkmnJumpPal2, 0x0006

	.align 2
gUnknown_082FBE40:: @ 82FBE40
	spr_template 0x0000, 0x0000, gUnknown_082FBEC8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_082FBE58:: @ 82FBE58
	.2byte 0x0060, 0x0060, 0x0060, 0x0072, 0x0078, 0x0078, 0x0078, 0x0072
	.2byte 0x0060, 0x0060, 0x0046, 0x0050, 0x0060, 0x0072, 0x0078, 0x0080
	.2byte 0x0078, 0x0072, 0x0060, 0x0050, 0x0032, 0x0048, 0x0060, 0x0072
	.2byte 0x0080, 0x0088, 0x0080, 0x0072, 0x0060, 0x0048, 0x002a, 0x0048
	.2byte 0x0060, 0x0072, 0x0080, 0x0088, 0x0080, 0x0072, 0x0060, 0x0048

gUnknown_082FBEA8:: @ 82FBEA8
	.2byte 0x0010, 0x0028, 0x0048, 0x0068, 0x0088, 0x00a8, 0x00c8, 0x00e0

	.align 2
gUnknown_082FBEB8:: @ 82FBEB8
	.4byte gUnknown_082FBF78
	.4byte gUnknown_082FBF90
	.4byte gUnknown_082FBFA8
	.4byte gUnknown_082FBFC0

	.align 2
gUnknown_082FBEC8:: @ 82FBED0
	.byte 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBED0:: @ 82FBED0
	.byte 0x00, 0x80, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBED8:: @ 82FBED8
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBEE0:: @ 82FBEE0
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBEE8:: @ 82FBEE8
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBEF0:: @ 82FBEF0
	.2byte 0x0008, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBEF8:: @ 82FBEF8
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF00:: @ 82FBF00
	.2byte 0x0018, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF08:: @ 82FBF08
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF10:: @ 82FBF10
	.2byte 0x0028, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF18:: @ 82FBF18
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF20:: @ 82FBF20
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF28:: @ 82FBF28
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF30:: @ 82FBF30
	.2byte 0x0030, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF38:: @ 82FBF38
	.2byte 0x0040, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF40:: @ 82FBF40
	.2byte 0x0050, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF48:: @ 82FBF48
	.4byte gUnknown_082FBEE8
	.4byte gUnknown_082FBEF0
	.4byte gUnknown_082FBEF8
	.4byte gUnknown_082FBF00
	.4byte gUnknown_082FBF08
	.4byte gUnknown_082FBF10

	.align 2
gUnknown_082FBF60:: @ 82FBF60
	.4byte gUnknown_082FBF18
	.4byte gUnknown_082FBF20
	.4byte gUnknown_082FBF28
	.4byte gUnknown_082FBF30
	.4byte gUnknown_082FBF38
	.4byte gUnknown_082FBF40

	.align 2
gUnknown_082FBF78:: @ 82FBF78
	spr_template 0x0005, 0x0005, gUnknown_082FBED0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBF90:: @ 82FBF90
	spr_template 0x0006, 0x0005, gUnknown_082FBED8, gUnknown_082FBF60, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFA8:: @ 82FBFA8
	spr_template 0x0007, 0x0005, gUnknown_082FBEE0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFC0:: @ 82FBFC0
	spr_template 0x0008, 0x0005, gUnknown_082FBEE0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFD8:: @ 82FBFD8
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_082FBFE0:: @ 82FBFE0
	.2byte 0x0000, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBFE8:: @ 82FBFE8
	.2byte 0x0000, 0x0004
	.2byte 0x0004, 0x0004
	.2byte 0x0008, 0x0004
	.2byte 0x000c, 0x0004
	.2byte 0xfffd, 0x0001
	.2byte 0x0000, 0x0004
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FC004:: @ 82FC004
	.4byte gUnknown_082FBFE0
	.4byte gUnknown_082FBFE8

	.align 2
gUnknown_082FC00C:: @ 82FC00C
	spr_template 0x000a, 0x0005, gUnknown_082FBFD8, gUnknown_082FC004, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gPkmnJumpPal3:: @ 82FC024
	.incbin "graphics/link_games/pkmnjump_pal3.gbapal"

	.align 2
gPkmnJumpBgPal:: @ 82FC044
	.incbin "graphics/link_games/pkmnjump_bg.gbapal"

	.align 2
gPkmnJumpBgGfx:: @ 82FC064
	.incbin "graphics/link_games/pkmnjump_bg.4bpp.lz"

	.align 2
gPkmnJumpBgTilemap:: @ 82FC290
	.incbin "graphics/link_games/pkmnjump_bg.bin.lz"

	.align 2
gPkmnJumpVenusaurPal:: @ 82FC440
	.incbin "graphics/link_games/pkmnjump_venusaur.gbapal"

	.align 2
gPkmnJumpVenusaurGfx:: @ 82FC460
	.incbin "graphics/link_games/pkmnjump_venusaur.4bpp.lz"

	.align 2
gPkmnJumpVenusaurTilemap:: @ 82FCDB0
	.incbin "graphics/link_games/pkmnjump_venusaur.bin.lz"

	.align 2
gPkmnJumpResultsPal:: @ 82FD168
	.incbin "graphics/link_games/pkmnjump_results.gbapal"

	.align 2
gPkmnJumpResultsGfx:: @ 82FD188
	.incbin "graphics/link_games/pkmnjump_results.4bpp.lz"

	.align 2
gPkmnJumpResultsTilemap:: @ 82FDC38
	.incbin "graphics/link_games/pkmnjump_results.bin.lz"

	.align 2
gUnknown_082FE164:: @ 82FE164 struct BgTemplate
	.4byte 0x000001b0, 0x000025e6, 0x000016c9, 0x000031df

	.align 2
gUnknown_082FE174:: @ 82FE174
	window_template 0x00, 0x13, 0x00, 0x06, 0x02, 0x02, 0x0013
	window_template 0x00, 0x08, 0x00, 0x06, 0x02, 0x02, 0x001f
	null_window_template

	.align 2
gUnknown_082FE18C:: @ 82FE18C
	.4byte 0x00000000, sub_802D150
	.4byte 0x00000001, sub_802D2E4
	.4byte 0x00000002, sub_802D350
	.4byte 0x00000003, sub_802D3BC
	.4byte 0x00000004, sub_802D448
	.4byte 0x00000005, sub_802D4F4
	.4byte 0x00000006, sub_802D598
	.4byte 0x00000007, sub_802D5E4
	.4byte 0x00000009, sub_802D72C
	.4byte 0x00000008, sub_802D688

	.align 2
gUnknown_082FE1DC:: @ 82FE1DC
	.byte 0x00, 0x02, 0x03

gUnknown_082FE1DF:: @ 82FE1DF
	.byte 0x02, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
	.byte 0x00, 0x02, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FE1EC:: @ 82FE1EC
	obj_tiles gUnknown_082FF1F8, 0x0000, 0x0320

	.align 2
gUnknown_082FE1F4:: @ 82FE1F4
	obj_pal gUnknown_082FF1D8, 0x0320

	.align 2
gUnknown_082FE1FC:: @ 82FE1FC
	.2byte 0x0006, 0x0008, 0x0010, 0x0008

	.align 2
gUnknown_082FE204:: @ 82FE204
	.2byte 0x0006, 0x0008, 0x000b, 0x0006, 0x0010, 0x0008

	.align 2
gUnknown_082FE210:: @ 82FE210
	.2byte 0x0002, 0x0006, 0x0006, 0x0008, 0x0010, 0x0008, 0x0014, 0x0006

	.align 2
gUnknown_082FE220:: @ 82FE220
	.2byte 0x0002, 0x0006, 0x0006, 0x0008, 0x000b, 0x0006
	.2byte 0x0010, 0x0008, 0x0014, 0x0006

	.align 2
gUnknown_082FE234:: @ 82FE234
	.4byte gUnknown_082FE1FC
	.4byte gUnknown_082FE204
	.4byte gUnknown_082FE210
	.4byte gUnknown_082FE220

	.align 2
gUnknown_082FE244:: @ 82FE244
	.2byte 0x0058, 0x0098

gUnknown_082FE248:: @ 82FE248
	.2byte 0x0058, 0x0078, 0x0098

gUnknown_082FE24E:: @ 82FE24E
	.2byte 0x0038, 0x0058, 0x0098, 0x00b8

gUnknown_082FE256:: @ 82FE256
	.2byte 0x0038, 0x0058, 0x0078, 0x0098, 0x00b8

	.align 2
gUnknown_082FE260:: @ 82FE260
	.4byte gUnknown_082FE244
	.4byte gUnknown_082FE248
	.4byte gUnknown_082FE24E
	.4byte gUnknown_082FE256

	.align 2
gUnknown_082FE270:: @ 82FE270
	.4byte 0x1c010100, 0x00010f09

	.align 2
gUnknown_082FE278:: @ 82FE278
	.4byte gText_JumpsInARow
	.4byte gText_BestScore2
	.4byte gText_ExcellentsInARow

	.align 2
gPkmnJump321StartPal1:: @ 82FE284
	.incbin "graphics/link_games/pkmnjump_321start1.gbapal"

	.align 2
gPkmnJump321StartGfx1:: @ 82FE2A4
	.incbin "graphics/link_games/pkmnjump_321start1.4bpp.lz"

	.align 2
gUnknown_082FE6C8:: @ 82FE6C8
	obj_tiles gPkmnJump321StartGfx1, 0x0c00, 0x2000
	null_obj_tiles

	.align 2
gUnknown_082FE6D8:: @ 82FE6D8
	obj_pal gPkmnJump321StartPal1, 0x2000
    null_obj_pal

	.align 2
gUnknown_082FE6E8:: @ 82FE6E8
	.2byte 0x0000, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE6F0:: @ 82FE6F0
	.2byte 0x0010, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE6F8:: @ 82FE6F8
	.2byte 0x0020, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE700:: @ 82FE700
	.2byte 0x0040, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE708:: @ 82FE708
	.2byte 0x0030, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE710:: @ 82FE710
	.2byte 0x0050, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE718:: @ 82FE718
	.4byte gUnknown_082FE6E8
	.4byte gUnknown_082FE6F0
	.4byte gUnknown_082FE6F8
	.4byte gUnknown_082FE700
	.4byte gUnknown_082FE708
	.4byte gUnknown_082FE710

	.align 2
gUnknown_082FE730:: @ 82FE730
	spr_template 0x2000, 0x2000, gUnknown_08524914, gUnknown_082FE718, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FE748:: @ 82FE748
	.4byte sub_802E83C
	.4byte sub_802E8C8
	.4byte sub_802EA50
	.4byte sub_802EAB0

	.align 2
gPkmnJump321StartPal2:: @ 82FE758
	.incbin "graphics/link_games/pkmnjump_321start2.gbapal"

	.align 2
gPkmnJump321StartGfx2:: @ 82FE778
	.incbin "graphics/link_games/pkmnjump_321start2.4bpp.lz"

	.align 2
gUnknown_082FEBCC:: @ 82FEBCC
	obj_tiles gPkmnJump321StartGfx2, 0x0e00, 0x0000

	.align 2
gUnknown_082FEBD4:: @ 82FEBD4
	obj_pal gPkmnJump321StartPal2, 0x0000

	.align 2
gUnknown_082FEBDC:: @ 82FEBDC
	.byte 0x00, 0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FEBE4:: @ 82FEBE4
	.byte 0x00, 0x40, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FEBEC:: @ 82FEBEC
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEBF4:: @ 82FEBF4
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEBFC:: @ 82FEBFC
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC04:: @ 82FEC04
	.4byte gUnknown_082FEBEC
	.4byte gUnknown_082FEBF4
	.4byte gUnknown_082FEBFC

	.align 2
gUnknown_082FEC10:: @ 82FEC10
	.2byte 0x0030, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC18:: @ 82FEC18
	.2byte 0x0050, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC20:: @ 82FEC20
	.4byte gUnknown_082FEC10
	.4byte gUnknown_082FEC18

	.align 2
gUnknown_082FEC28:: @ 82FEC28
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC38:: @ 82FEC38
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x0010, 0xfff0
	.2byte 0x0800, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC50:: @ 82FEC50
	.2byte 0xffee, 0x0012
	.2byte 0x0800, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC60:: @ 82FEC60
	.2byte 0x0006, 0xfffa
	.2byte 0x0800, 0x0000
	.2byte 0xfffc, 0x0004
	.2byte 0x0800, 0x0000
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC80:: @ 82FEC80
	.4byte gUnknown_082FEC28
	.4byte gUnknown_082FEC38
	.4byte gUnknown_082FEC50
	.4byte gUnknown_082FEC60

gUnknown_082FEC90:: @ 82FEC90
	spr_template 0x0000, 0x0000, gUnknown_082FEBDC, gUnknown_082FEC04, NULL, gUnknown_082FEC80, SpriteCallbackDummy

gUnknown_082FECA8:: @ 82FECA8
	spr_template 0x0000, 0x0000, gUnknown_082FEBE4, gUnknown_082FEC20, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
