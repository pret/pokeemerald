	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082F0E10:: @ 82F0E10
	.byte 0x00, 0x02, 0x03
	.byte 0x00, 0x01, 0x02

	.align 2
gUnknown_082F0E18:: @ 82F0E18
	.byte 0x07, 0x04, 0x07, 0x00

	.align 2
gUnknown_082F0E1C:: @ 82F0E1C
	window_template 0x01, 0x01, 0x01, 0x19, 0x04, 0x02, 0x029C
	window_template 0x01, 0x01, 0x06, 0x1C, 0x08, 0x02, 0x01BC
	window_template 0x01, 0x01, 0x0E, 0x1C, 0x05, 0x02, 0x0130

	.align 2
gWonderCardBgPal1:: @ 82F0E34
	.incbin "graphics/wonder_transfers/wonder_card_1.gbapal"

	.align 2
gWonderCardBgPal2:: @ 82F0E54
	.incbin "graphics/wonder_transfers/wonder_card_2.gbapal"

	.align 2
gWonderCardBgPal3:: @ 82F0E74
	.incbin "graphics/wonder_transfers/wonder_card_3.gbapal"

	.align 2
gWonderCardBgPal4:: @ 82F0E94
	.incbin "graphics/wonder_transfers/wonder_card_4.gbapal"

	.align 2
gWonderCardBgPal5:: @ 82F0EB4
	.incbin "graphics/wonder_transfers/wonder_card_5.gbapal"

	.align 2
gWonderCardBgPal6:: @ 82F0ED4
	.incbin "graphics/wonder_transfers/wonder_card_6.gbapal"

	.align 2
gWonderCardBgPal7:: @ 82F0EF4
	.incbin "graphics/wonder_transfers/wonder_card_7.gbapal"

	.align 2
gWonderCardBgPal8:: @ 82F0F14
	.incbin "graphics/wonder_transfers/wonder_card_8.gbapal"

	.align 2
gWonderCardBgGfx1:: @ 82F0F34
	.incbin "graphics/wonder_transfers/wonder_card_1.4bpp.lz"

	.align 2
gWonderCardBgTilemap1:: @ 82F1030
	.incbin "graphics/wonder_transfers/wonder_card_1.bin.lz"

	.align 2
gWonderCardBgGfx2:: @ 82F1124
	.incbin "graphics/wonder_transfers/wonder_card_2.4bpp.lz"

	.align 2
gWonderCardBgTilemap2:: @ 82F1218
	.incbin "graphics/wonder_transfers/wonder_card_2.bin.lz"

	.align 2
gWonderCardBgGfx3:: @ 82F1300
	.incbin "graphics/wonder_transfers/wonder_card_3.4bpp.lz"

	.align 2
gWonderCardBgTilemap3:: @ 82F13D4
	.incbin "graphics/wonder_transfers/wonder_card_3.bin.lz"

	.align 2
gWonderCardBgGfx7:: @ 82F14A8
	.incbin "graphics/wonder_transfers/wonder_card_7.4bpp.lz"

	.align 2
gWonderCardBgTilemap7:: @ 82F16DC
	.incbin "graphics/wonder_transfers/wonder_card_7.bin.lz"

	.align 2
gWonderCardBgGfx8:: @ 82F1824
	.incbin "graphics/wonder_transfers/wonder_card_8.4bpp.lz"

	.align 2
gWonderCardBgTilemap8:: @ 82F1A54
	.incbin "graphics/wonder_transfers/wonder_card_8.bin.lz"

	.align 2
gWonderCardShadowPal1:: @ 82F1B9C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_1.gbapal"

	.align 2
gWonderCardShadowPal2:: @ 82F1BBC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_2.gbapal"

	.align 2
gWonderCardShadowPal3:: @ 82F1BDC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_3.gbapal"

	.align 2
gWonderCardShadowPal4:: @ 82F1BFC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_4.gbapal"

	.align 2
gWonderCardShadowPal5:: @ 82F1C1C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_5.gbapal"

	.align 2
gWonderCardShadowPal6:: @ 82F1C3C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_6.gbapal"

	.align 2
gWonderCardShadowPal7:: @ 82F1C5C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_7.gbapal"

	.align 2
gWonderCardShadowPal8:: @ 82F1C7C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_8.gbapal"

	.align 2
gWonderCardShadowGfx:: @ 82F1C9C
	.incbin "graphics/wonder_transfers/wonder_card_shadow.4bpp.lz"

	.align 2
gUnknown_082F1D00:: @ 82F1D00 struct CompressedSpriteSheet
	.4byte gWonderCardShadowGfx
	.2byte 0x0100
	.2byte 0x8000

	.align 2
gUnknown_082F1D08:: @ 82F1D08 struct SpritePalette
	.4byte gWonderCardShadowPal1
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal2
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal3
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal4
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal5
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal6
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal7
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal8
	.2byte 0x8000

	.align 2
gUnknown_082F1D48:: @ 82F1D48
	spr_template 0x8000, 0x8000, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F1D60:: @ 82F1D60
	.4byte 0x00000001, gWonderCardBgGfx1, gWonderCardBgTilemap1, gWonderCardBgPal1
	.4byte 0x00001001, gWonderCardBgGfx2, gWonderCardBgTilemap2, gWonderCardBgPal2
	.4byte 0x00002001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal3
	.4byte 0x00003001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal4
	.4byte 0x00004001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal5
	.4byte 0x00005001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal6
	.4byte 0x00006001, gWonderCardBgGfx7, gWonderCardBgTilemap7, gWonderCardBgPal7
	.4byte 0x00007001, gWonderCardBgGfx8, gWonderCardBgTilemap8, gWonderCardBgPal8

gUnknown_082F1DE0:: @ 82F1DE0
	.byte 0x00, 0x02, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00

gUnknown_082F1DE8:: @ 82F1DE8
	window_template 0x00, 0x01, 0x00, 0x1C, 0x03, 0x02, 0x02AC
	window_template 0x02, 0x01, 0x03, 0x1C, 0x14, 0x02, 0x007C

gUnknown_082F1DF8:: @ 82F1DF8
	.4byte 0x0318e802, 0x000098e8, 0x10000002, 0x00001000

	.align 2
gWonderNewsPal1:: @ 82F1E08
	.incbin "graphics/wonder_transfers/wonder_news_1.gbapal"

	.align 2
gWonderNewsPal7:: @ 82F1E28
	.incbin "graphics/wonder_transfers/wonder_news_7.gbapal"

	.align 2
gWonderNewsPal8:: @ 82F1E48
	.incbin "graphics/wonder_transfers/wonder_news_8.gbapal"

	.align 2
gWonderNewsGfx1:: @ 82F1E68
	.incbin "graphics/wonder_transfers/wonder_news_1.4bpp.lz"

	.align 2
gWonderNewsTilemap1:: @ 82F1EE8
	.incbin "graphics/wonder_transfers/wonder_news_1.bin.lz"

	.align 2
gWonderNewsGfx2:: @ 82F1FC4
	.incbin "graphics/wonder_transfers/wonder_news_2.4bpp.lz"

	.align 2
gWonderNewsTilemap2:: @ 82F1FF4
	.incbin "graphics/wonder_transfers/wonder_news_2.bin.lz"

	.align 2
gWonderNewsGfx3:: @ 82F20B4
	.incbin "graphics/wonder_transfers/wonder_news_3.4bpp.lz"

	.align 2
gWonderNewsTilemap3:: @ 82F2124
	.incbin "graphics/wonder_transfers/wonder_news_3.bin.lz"

	.align 2
gWonderNewsGfx7:: @ 82F21F0
	.incbin "graphics/wonder_transfers/wonder_news_7.4bpp.lz"

	.align 2
gWonderNewsTilemap7:: @ 82F2280
	.incbin "graphics/wonder_transfers/wonder_news_7.bin.lz"

	.align 2
gWonderNewsGfx8:: @ 82F235C
	.incbin "graphics/wonder_transfers/wonder_news_8.4bpp.lz"

	.align 2
gWonderNewsTilemap8:: @ 82F23EC
	.incbin "graphics/wonder_transfers/wonder_news_8.bin.lz"

	.align 2
gUnknown_082F24C8:: @ 82F24C8
	.4byte 0x00000001, gWonderNewsGfx1, gWonderNewsTilemap1, gWonderNewsPal1
	.4byte 0x00000001, gWonderNewsGfx2, gWonderNewsTilemap2, gWonderCardBgPal2
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal3
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal4
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal5
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal6
	.4byte 0x00000001, gWonderNewsGfx7, gWonderNewsTilemap7, gWonderNewsPal7
	.4byte 0x00000001, gWonderNewsGfx8, gWonderNewsTilemap8, gWonderNewsPal8
