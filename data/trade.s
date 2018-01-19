	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0832C6A8:: @ 832C6A8
	.4byte 0x00000f2c, 0x00003d88, 0x0000001c, 0x00000024, 0x00000064, 0x00000528

	.align 1
gTradeMovesBoxTilemap:: @ 832C6C0
	.incbin "graphics/trade/moves_box_map.bin"

	.align 1
gTradePartyBoxTilemap:: @ 832C8BE
	.incbin "graphics/trade/party_box_map.bin"

	.align 1
gTradeStripesBG2Tilemap:: @ 832CABC
	.incbin "graphics/trade/stripes_bg2_map.bin"

	.align 1
gTradeStripesBG3Tilemap:: @ 832D2BC
	.incbin "graphics/trade/stripes_bg3_map.bin"

gUnknown_0832DABC:: @ 832DABC
	.string "$"

	.string "{COLOR WHITE}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}$"

gText_MaleSymbol4:: @ 832DAC7
	.string "♂$"

gText_FemaleSymbol4:: @ 832DAC9
	.string "♀$"

gText_GenderlessSymbol:: @ 832DACB
	.string "$"

	.string " MOVE$"

gUnknown_0832DAD2:: @ 832DAD2
	.string "\n$"

	.string "/$"

	.string "Lv. $"

	.string "---$"

gUnknown_0832DADF:: @ 832DADF
	.string "????$"

	.string "$"

gUnknown_0832DAE5:: @ 832DAE5
	.string "Is this trade okay?$"

	.string "CANCEL$"

	.string "Choose a POKéMON.$"

	.string "SUMMARY$"

	.string "TRADE$"

	.string "Cancel trade?$"

	.string "Bボタン　で　もどります$"

	.string "SUMMARY$"

	.string "TRADE$"

	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Communication standby…\nPlease wait.$"

	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}The trade has\nbeen canceled.$"

	.string "That’s your only\nPOKéMON for battle.$"

	.string "{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Waiting for your friend\nto finish…$"

	.string "Your friend wants\nto trade POKéMON.$"

	.align 2
gOamData_832DC14:: @ 832DC14
	.2byte 0x4000, 0x8000, 0x0400, 0x0000

	.align 2
gOamData_832DC1C:: @ 832DC1C
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_832DC24:: @ 832DC24
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC2C:: @ 832DC2C
	.2byte 0x0020, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_832DC34:: @ 832DC34
	.4byte gSpriteAnim_832DC24
	.4byte gSpriteAnim_832DC2C

	.align 2
gUnknown_0832DC3C:: @ 832DC3C
	obj_tiles gUnknown_08DDC6E4, 0x0800, 0x012c

	.align 2
gUnknown_0832DC44:: @ 832DC44
	obj_pal gUnknown_08DDB444, 0x0929

	.align 2
gSpriteAnim_832DC4C:: @ 832DC4C
	.2byte 0x0000, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC54:: @ 832DC54
	.2byte 0x0008, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC5C:: @ 832DC5C
	.2byte 0x0010, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC64:: @ 832DC64
	.2byte 0x0018, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC6C:: @ 832DC6C
	.2byte 0x0020, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnim_832DC74:: @ 832DC74
	.2byte 0x0028, 0x0005, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_832DC7C:: @ 832DC7C
	.4byte gSpriteAnim_832DC4C
	.4byte gSpriteAnim_832DC54
	.4byte gSpriteAnim_832DC5C
	.4byte gSpriteAnim_832DC64
	.4byte gSpriteAnim_832DC6C
	.4byte gSpriteAnim_832DC74

	.align 2
gSpriteTemplate_832DC94:: @ 832DC94
	spr_template 0x012c, 0x0929, gOamData_832DC1C, gSpriteAnimTable_832DC34, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteTemplate_832DCAC:: @ 832DCAC
	.incbin "baserom.gba", 0x32dcac, 0x18

	.align 2
TradeScreenTextPalette:: @ 832DCC4
	.incbin "graphics/trade/text.gbapal"

gSpritePalette_TradeScreenText:: @ 832DCE4
	.incbin "baserom.gba", 0x32dce4, 0x8

gUnknown_0832DCEC:: @ 832DCEC
	.incbin "baserom.gba", 0x32dcec, 0x138

gUnknown_0832DE24:: @ 832DE24
	.incbin "baserom.gba", 0x32de24, 0x1a

gUnknown_0832DE3E:: @ 832DE3E
	.incbin "baserom.gba", 0x32de3e, 0x18

gUnknown_0832DE56:: @ 832DE56
	.incbin "baserom.gba", 0x32de56, 0x3e

	.align 2
gUnknown_0832DE94:: @ 832DE94
	.incbin "baserom.gba", 0x32de94, 0x18

gUnknown_0832DEAC:: @ 832DEAC
	.incbin "baserom.gba", 0x32deac, 0x10

gUnknown_0832DEBC:: @ 832DEBC
	.incbin "baserom.gba", 0x32debc, 0x24

gUnknown_0832DEE0:: @ 832DEE0
	.incbin "baserom.gba", 0x32dee0, 0x4

gUnknown_0832DEE4:: @ 832DEE4
	.incbin "baserom.gba", 0x32dee4, 0x10

gUnknown_0832DEF4:: @ 832DEF4
	.incbin "baserom.gba", 0x32def4, 0x98

gUnknown_0832DF8C:: @ 832DF8C
	.incbin "baserom.gba", 0x32df8c, 0x8

gUnknown_0832DF94:: @ 832DF94
	.incbin "baserom.gba", 0x32df94, 0x5

gUnknown_0832DF99:: @ 832DF99
	.incbin "baserom.gba", 0x32df99, 0x2027

gUnknown_0832FFC0:: @ 832FFC0
	.incbin "baserom.gba", 0x32ffc0, 0x1fa0

gUnknown_08331F60:: @ 8331F60
	.incbin "baserom.gba", 0x331f60, 0x1000

gUnknown_08332F60:: @ 8332F60
	.incbin "baserom.gba", 0x332f60, 0x2840

gUnknown_083357A0:: @ 83357A0
	.incbin "baserom.gba", 0x3357a0, 0x100

gUnknown_083358A0:: @ 83358A0
	.incbin "baserom.gba", 0x3358a0, 0x100

gUnknown_083359A0:: @ 83359A0
	.incbin "baserom.gba", 0x3359a0, 0x1000

gUnknown_083369A0:: @ 83369A0
	.incbin "baserom.gba", 0x3369a0, 0x1000

gUnknown_083379A0:: @ 83379A0
	.incbin "baserom.gba", 0x3379a0, 0x100

gUnknown_08337AA0:: @ 8337AA0
	.incbin "baserom.gba", 0x337aa0, 0x200

gUnknown_08337CA0:: @ 8337CA0
	.incbin "baserom.gba", 0x337ca0, 0x200

gUnknown_08337EA0:: @ 8337EA0
	.incbin "baserom.gba", 0x337ea0, 0x20

gUnknown_08337EC0:: @ 8337EC0
	.incbin "baserom.gba", 0x337ec0, 0x690

gUnknown_08338550:: @ 8338550
	.incbin "baserom.gba", 0x338550, 0x7c8

gUnknown_08338D18:: @ 8338D18
	.incbin "baserom.gba", 0x338d18, 0x8

gUnknown_08338D20:: @ 8338D20
	.incbin "baserom.gba", 0x338d20, 0x8

gUnknown_08338D28:: @ 8338D28
	.incbin "baserom.gba", 0x338d28, 0x48

gUnknown_08338D70:: @ 8338D70
	.incbin "baserom.gba", 0x338d70, 0x8

gUnknown_08338D78:: @ 8338D78
	.incbin "baserom.gba", 0x338d78, 0x8

gUnknown_08338D80:: @ 8338D80
	.incbin "baserom.gba", 0x338d80, 0x8

gUnknown_08338D88:: @ 8338D88
	.incbin "baserom.gba", 0x338d88, 0x38

gUnknown_08338DC0:: @ 8338DC0
	.incbin "baserom.gba", 0x338dc0, 0x8

gUnknown_08338DC8:: @ 8338DC8
	.incbin "baserom.gba", 0x338dc8, 0x2c

gUnknown_08338DF4:: @ 8338DF4
	.incbin "baserom.gba", 0x338df4, 0x8

gUnknown_08338DFC:: @ 8338DFC
	.incbin "baserom.gba", 0x338dfc, 0x70

gUnknown_08338E6C:: @ 8338E6C
	.incbin "baserom.gba", 0x338e6c, 0x8

gUnknown_08338E74:: @ 8338E74
	.incbin "baserom.gba", 0x338e74, 0x18

gUnknown_08338E8C:: @ 8338E8C
	.incbin "baserom.gba", 0x338e8c, 0x18

gUnknown_08338EA4:: @ 8338EA4
	.incbin "baserom.gba", 0x338ea4, 0x28

gUnknown_08338ECC:: @ 8338ECC
	.incbin "baserom.gba", 0x338ecc, 0x4

gUnknown_08338ED0:: @ 8338ED0
	.incbin "baserom.gba", 0x338ed0, 0xf0

gUnknown_08338FC0:: @ 8338FC0
	.incbin "baserom.gba", 0x338fc0, 0x3c

gUnknown_08338FFC:: @ 8338FFC
	.incbin "baserom.gba", 0x338ffc, 0x10

gUnknown_0833900C:: @ 833900C
	.incbin "baserom.gba", 0x33900c, 0x8

gUnknown_08339014:: @ 8339014
	.incbin "baserom.gba", 0x339014, 0x10

gUnknown_08339024:: @ 8339024
	.incbin "baserom.gba", 0x339024, 0x6c

gUnknown_08339090:: @ 8339090
	.incbin "baserom.gba", 0x339090, 0x44
