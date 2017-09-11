@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082EC86C:: @ 82EC86C
	.incbin "graphics/interface/wireless_link.gbapal"

gUnknown_082EC88C:: @ 82EC88C
	.incbin "graphics/interface/wireless_link.4bpp.lz"

gUnknown_082ECD34:: @ 82ECD34
	.incbin "graphics/interface/wireless_link.bin.lz"

gUnknown_082ECF20:: @ 82ECF20
	.incbin "graphics/interface/link_test_digits.gbapal"

gUnknown_082ECF40:: @ 82ECF40
	.incbin "graphics/interface/link_test_digits.4bpp"

	.string "{HIGHLIGHT TRANSPARENT}{COLOR DARK_GREY}$"

	.align 2
gUnknown_082ED168:: @ 82ED168
	.incbin "graphics/interface/blank_1x2.4bpp"

gUnknown_082ED1A8:: @ 82ED1A8
	.4byte gUnknown_020228C4
	.4byte 0x000000C8
	.4byte gUnknown_020228C4
	.4byte 0x000000C8
	.4byte gUnknown_020228C4
	.4byte 0x00000064
	.4byte gUnknown_020228C4
	.4byte 0x000000DC
	.4byte gUnknown_020228C4
	.4byte 0x00000028

gUnknown_082ED1D0:: @ 82ED1D0
	.byte 0x8
	.byte 0xA
	.byte 0xC
	.byte 0xE

gUnknown_082ED1D4:: @ 82ED1D4
	.ascii "GameFreak inc."

	.align 2
gUnknown_082ED1E4:: @ 82ED1E4
	.ascii "TEST PRINT\nP0\nP1\nP2\nP3"

	.align 2
gUnknown_082ED1FC:: @ 82ED1FC BgTemplate
	.4byte 0x000001F8
	.4byte 0x00001081

gUnknown_082ED204:: @ 82ED204 WindowTemplate
	.byte  0x00
	.byte  0x00
	.byte  0x00
	.byte  0x1E
	.byte  0x05
	.byte  0x0F
	.2byte 0x0002
	
	.byte  0x00
	.byte  0x00
	.byte  0x06
	.byte  0x1E
	.byte  0x07
	.byte  0x0F
	.2byte 0x0098
	
	.byte  0x00
	.byte  0x00
	.byte  0x0D
	.byte  0x1E
	.byte  0x07
	.byte  0x0F
	.2byte 0x016A
	
	.byte  0xFF
	.byte  0x00
	.byte  0x00
	.byte  0x00
	.byte  0x00
	.byte  0x00
	.2byte 0x0000

gUnknown_082ED224:: @ 82ED224
	.byte 0x00, 0x01, 0x02, 0x00, 0xff, 0xfe, 0xff, 0x00

gWirelessLinkIconPalette:: @ 82ED22C
	.incbin "graphics/interface/wireless_link_icon.gbapal"

gWirelessLinkIconPic:: @ 82ED22C
	.incbin "graphics/interface/wireless_link_icon.4bpp.lz"

gUnknown_082ED370:: @ 82ED370
	.byte 0xff, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x37
	.byte 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f
	.byte 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47
	.byte 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f
	.byte 0x00, 0xab, 0xb5, 0xb6, 0xb1, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xb2, 0xf1, 0x00, 0xae, 0xad, 0xba
	.byte 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8
	.byte 0xa9, 0xaa, 0x00, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f
	.byte 0x00, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1
	.byte 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9
	.byte 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1
	.byte 0xd2, 0xd3, 0xd4, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6
	.byte 0x00, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb
	.byte 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3
	.byte 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb
	.byte 0xec, 0xed, 0xee, 0x2d, 0x2f, 0x30, 0x31, 0x32
	.byte 0x33, 0x34, 0x35, 0x36, 0x50, 0x00, 0x01, 0x02
	.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a
	.byte 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12
	.byte 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a
	.byte 0x1b, 0xad, 0xb3, 0xb4, 0x00, 0xaf, 0x7d, 0x7f
	.byte 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xa0
	.byte 0xae, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57
	.byte 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f
	.byte 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67
	.byte 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f
	.byte 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77
	.byte 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7e, 0xb0, 0xac
	.byte 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23
	.byte 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b
	.byte 0x2c, 0x2e, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c
	.byte 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94

gUnknown_082ED470:: @ 82ED470
	.byte 0x20, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c
	.byte 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94
	.byte 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c
	.byte 0x9d, 0x9e, 0x9f, 0xa0, 0xe0, 0xe1, 0xe2, 0xe3
	.byte 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb
	.byte 0xec, 0xed, 0xee, 0xef, 0xf0, 0x7b, 0xf1, 0x7c
	.byte 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x07
	.byte 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
	.byte 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17
	.byte 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
	.byte 0x84, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7
	.byte 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf
	.byte 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7
	.byte 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf
	.byte 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7
	.byte 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xa6, 0xdd, 0xa7
	.byte 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xf2
	.byte 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa
	.byte 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 0x01, 0x02, 0x03
	.byte 0x04, 0x05, 0x06, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f
	.byte 0xaf, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36
	.byte 0x37, 0x38, 0x39, 0x21, 0xdf, 0xa1, 0xb0, 0xa5
	.byte 0xde, 0x24, 0x2a, 0xa2, 0xa3, 0x22, 0x23, 0x20
	.byte 0xa4, 0x20, 0x2f, 0x41, 0x42, 0x43, 0x44, 0x45
	.byte 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d
	.byte 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55
	.byte 0x56, 0x57, 0x58, 0x59, 0x5a, 0x61, 0x62, 0x63
	.byte 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b
	.byte 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73
	.byte 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x20
	.byte 0x20, 0x2b, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00

gUnknown_082ED570:: @ 82ED570
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

gUnknown_082ED578:: @ 82ED578
	.2byte 0x0004, 0x0005, 0x0008, 0x0005, 0x000c, 0x0005, 0x0010, 0x000a
	.2byte 0x000c, 0x0005, 0x0008, 0x0005, 0xfffe, 0x0000

gUnknown_082ED594:: @ 82ED594
	.2byte 0x0004, 0x0005, 0x0008, 0x0005, 0x000c, 0x000a, 0x0008, 0x0005
	.2byte 0xfffe, 0x0000

gUnknown_082ED5A8:: @ 82ED5A8
	.2byte 0x0004, 0x0005, 0x0008, 0x0005, 0xfffe, 0x0000

gUnknown_082ED5B4:: @ 82ED5B4
	.2byte 0x0004, 0x000a, 0x0014, 0x000a, 0xfffe, 0x0000

gUnknown_082ED5C0:: @ 82ED5C0
	.2byte 0x0018, 0x000a, 0x0004, 0x000a, 0xfffe, 0x0000

gUnknown_082ED5CC:: @ 82ED5CC
	.4byte gUnknown_082ED578
	.4byte gUnknown_082ED594
	.4byte gUnknown_082ED5A8
	.4byte gUnknown_082ED5B4
	.4byte gUnknown_082ED5C0

gUnknown_082ED5E0:: @ 82ED5E0 struct CompressedSpriteSheet
	.4byte gWirelessLinkIconPic
	.2byte 0x0380 @ uncompressed size
	.2byte 0xD431 @ tag

gUnknown_082ED5E8:: @ 82ED5E8 struct SpritePalette
	.4byte gWirelessLinkIconPalette
	.2byte 0xD432 @ tag
	.2byte 0x0000 @ padding

gUnknown_082ED5F0:: @ 82ED5F0 struct SpriteTemplate
	.2byte 0xD431 @ tileTag
	.2byte 0xD432 @ paletteTag
	.4byte gUnknown_082ED570
	.4byte gUnknown_082ED5CC
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte SpriteCallbackDummy

gUnknown_082ED608:: @ 82ED608
	.byte 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00
	.byte 0x14, 0x2b, 0x02, 0x02, 0x22, 0x2b, 0x02, 0x02
	.byte 0x01, 0x00, 0x58, 0x02, 0x2c, 0x01, 0x00, 0x00

gUnknown_082ED620:: @ 82ED620
	.byte 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00

gUnknown_082ED628:: @ 82ED628
	.4byte 0x00000000, 0x00000001, 0x00000003, 0x00000007
	.4byte 0x0000000f, 0x0000001f, 0x0000003f, 0x0000007f
	.4byte 0x000000ff, 0x000001ff, 0x000003ff, 0x000007ff
	.4byte 0x00000fff, 0x00001fff, 0x00003fff, 0x00007fff
	.4byte 0x0000ffff, 0x0001ffff, 0x0003ffff, 0x0007ffff
	.4byte 0x000fffff, 0x001fffff, 0x003fffff, 0x007fffff
	.4byte 0x00ffffff

gUnknown_082ED68C:: @ 82ED68C
	.byte 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02
	.byte 0x03

gUnknown_082ED695:: @ 82ED695
	.byte 0x00, 0x01, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03
	.byte 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04

gUnknown_082ED6A5:: @ 82ED6A5
	.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x00, 0x00, 0x00

gUnknown_082ED6B8:: @ 82ED6B8
    .4byte gUnknown_020228C4
	.4byte 0x000000c8
	.4byte gUnknown_020228C4
	.4byte 0x000000c8
	.4byte gUnknown_020228C4
	.4byte 0x00000064
	.4byte gUnknown_020228C4
	.4byte 0x000000dc
    .4byte gUnknown_020228C4
	.4byte 0x00000028

gUnknown_082ED6E0:: @ 82ED6E0
	.2byte 0x0002, 0x7f7d, 0x0000, 0xffff

	.ascii "RFU WAIT"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU BOOT"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU ERROR"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU RESET"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU CONFIG"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU START"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU SC POLL"
	.byte 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU SP POLL"
	.byte 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU START"
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	.ascii "RFU SEND ERR"
	.byte 0x00, 0x00, 0x00
	
	.ascii "RFU CP POLL"
	.byte 0x00, 0x00, 0x00, 0x00
	
	.ascii "              "
	.byte 0x00, 0x00
	
	.ascii "RECOVER START "
	.byte 0x00, 0x00
	
	.ascii "DISSCONECT    "
	.byte 0x00, 0x00
	
	.ascii "RECOVER SUUSES"
	.byte 0x00, 0x00
	
	.ascii "RECOVER FAILED"
	.byte 0x00, 0x00

	.align 2
gUnknown_082ED7E0:: @ 82ED7E0
	.4byte sub_801084C
	.4byte sub_8010AAC
	.4byte sub_8010D0C

gUnknown_082ED7EC:: @ 82ED7EC
	.ascii "PokemonSioInfo"

	.align 2
gUnknown_082ED7FC:: @ 82ED7FC
	.ascii "LINK LOSS DISCONNECT!"

	.align 2
gUnknown_082ED814:: @ 82ED814
	.ascii "LINK LOSS RECOVERY NOW"

	.align 2
gUnknown_082ED82C:: @ 82ED82C
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00

gUnknown_082ED84B:: @ 82ED84B
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00

gUnknown_082ED85B:: @ 82ED85B
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x00, 0x20, 0x00, 0x2a, 0x00

gUnknown_082ED868:: @ 82ED868
	.asciz "NOWSLOT"
	
	.asciz "           "
	
	.asciz "CLOCK DRIFT"

	.asciz "BUSY SEND  "
	
	.asciz "CMD REJECT "
	
	.asciz "CLOCK SLAVE"
	
	.ascii "CHILD "
	
	.align 2
	.ascii "PARENT"
	
	.align 2
	.ascii "SEARCH"
	
	.align 2
gUnknown_082ED8C4:: @ 82ED8C4
	.string "$"

	.align 2
gUnknown_082ED8C8:: @ 82ED8C8
	.string ":$"

	.align 2
gUnknown_082ED8CC:: @ 82ED8CC
	.string "{UNK_CTRL_F907}$"

	.align 2
gUnknown_082ED8D0:: @ 82ED8D0
	.string "Please start over from the beginning.$"

	.align 2
gUnknown_082ED8F8:: @ 82ED8F8
	.string "The WIRELESS COMMUNICATION\nSYSTEM search has been canceled.$"

	.align 2
	.string "Awaiting communication\nfrom another player.$"

	.align 2
gUnknown_082ED960:: @ 82ED960
	.string "{STR_VAR_1}! Awaiting\ncommunication from another player.$"

gUnknown_082ED990:: @ 82ED990
	.string "{STR_VAR_1}! Awaiting link!\nPress START when everyone’s ready.$"
	
	.align 2
gUnknown_082ED9C8:: @ 82ED9C8
	.string "シングルバトルを かいさいする$" @ "shingurubatoruwo kaisaisuru" ("hold a single battle" in Japanese)

	.align 2
gUnknown_082ED9D8:: @ 82ED9D8
	.string "ダブルバトルを かいさいする$" @ "daburubatoruwo kaisaisuru" ("hold a double battle" in Japanese)

	.align 2
gUnknown_082ED9E8:: @ 82ED9E8
	.string "マルチバトルを かいさいする$" @ "maruchibatoruwo kaisaisuru" ("hold a multi battle" in Japanese)

	.align 2
gUnknown_082ED9F8:: @ 82ED9F8
	.string "ポケモンこうかんを かいさいする$" @ "pokemonkoukanwo kaisaisuru" ("trade Pokémon" in Japanese)
	
	.align 2
gUnknown_082EDA0C:: @ 82EDA0C
	.string "チャットを かいさいする$" @ "chattowo kaisaisuru" ("chat" in Japanese)

	.align 2
gUnknown_082EDA1C:: @ 82EDA1C
	.string "ふしぎなカードをくばる$" @ "fushiginakaadowokubaru" ("distribute Wonder Card" in Japanese)

	.align 2
gUnknown_082EDA28:: @ 82EDA28
	.string "ふしぎなニュースをくばる$" @ "fushiginanyuusuwokubaru" ("distribute Mystery News" in Japanese)

	.align 2
	.string "ふしぎなできごとを かいさいする$" @ "fushiginadekigotowo kaisaisuru" ("hold a session of Mystery Event" in Japanese)

	.align 2
gUnknown_082EDA4C:: @ 82EDA4C
	.string "なわとびを かいさいする$" @ "nawatobiwo kaisaisuru" ("hold a session of Jump" in Japanese)

	.align 2
gUnknown_082EDA5C:: @ 82EDA5C
	.string "きのみマッシャーを かいさいする$" @ "kinomimassha-wo kaisaisuru" ("hold a session of Berry Masher" in Japanese)

	.align 2
gUnknown_082EDA70:: @ 82EDA70
	.string "きのみどりを かいさいする$" @ "kinomidoriwo kaisaisuru" ("hold a session of Berry Picking" in Japanese)

	.align 2
gUnknown_082EDA80:: @ 82EDA80
	.string "ぐるぐるこうかんを かいさいする$" @ "gurugurukoukanwo kaisaisuru" ("hold a session of Spin Trade" in Japanese)

	.align 2
gUnknown_082EDA94:: @ 82EDA94
	.string "ぐるぐるショップを かいさいする$" @ "gurugurushoppuwo kaisaisuru" ("hold a session of Spin Shop" in Japanese)

	.align 2
	.4byte gUnknown_082ED9C8
	.4byte gUnknown_082ED9D8
	.4byte gUnknown_082ED9E8
	.4byte gUnknown_082ED9F8
	.4byte gUnknown_082EDA0C
	.4byte gUnknown_082EDA1C
	.4byte gUnknown_082EDA28
	.4byte gUnknown_082EDA1C
	.4byte gUnknown_082EDA4C
	.4byte gUnknown_082EDA5C
	.4byte gUnknown_082EDA70
	.4byte gUnknown_082EDA70
	.4byte gUnknown_082EDA80
	.4byte gUnknown_082EDA94

gUnknown_082EDAE0:: @ 82EDAE0
	.string "1 player\nneeded.$"

gUnknown_082EDAF1:: @ 82EDAF1
	.string "2 players\nneeded.$"

gUnknown_082EDB03:: @ 82EDB03
	.string "3 players\nneeded.$"

gUnknown_082EDB15:: @ 82EDB15
	.string "4 players\nneeded.$"

gUnknown_082EDB27:: @ 82EDB27
	.string "2-PLAYER\nMODE$"

gUnknown_082EDB35:: @ 82EDB35
	.string "3-PLAYER\nMODE$"

gUnknown_082EDB43:: @ 82EDB43
	.string "4-PLAYER\nMODE$"
	
gUnknown_082EDB51:: @ 82EDB51
	.string "5-PLAYER\nMODE$"

	.align 2
gUnknown_082EDB60:: @ 82EDB60
	.4byte gUnknown_082EDAE0
	.4byte gUnknown_082EDB27
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDB03
	.4byte gUnknown_082EDAF1
	.4byte gUnknown_082EDAE0
	.4byte gUnknown_082EDB43
	.4byte NULL
	.4byte gUnknown_082EDAE0
	.4byte gUnknown_082EDB27
	.4byte gUnknown_082EDB35
	.4byte gUnknown_082EDB43
	.4byte gUnknown_082EDB51
	.4byte gUnknown_082EDAF1
	.4byte gUnknown_082EDAE0
	.4byte gUnknown_082EDB35
	.4byte gUnknown_082EDB43
	.4byte gUnknown_082EDB51
	.4byte gUnknown_082EDAE0
	.4byte gUnknown_082EDB27
	.4byte gUnknown_082EDB35
	.4byte gUnknown_082EDB43
	.4byte NULL

	.align 2
gUnknown_082EDBC4:: @ 82EDBC4
	.string "{UNK_CTRL_F801}CANCEL$"

	.align 2
	.string "ため\nさんかしゃ ぼしゅうちゅう です！$" @ "tame\nsankasha boshuuchuu desu!"

	.align 2
gUnknown_082EDBE8:: @ 82EDBE8
	.string "{STR_VAR_2} contacted you for\n{STR_VAR_1}. Accept?$"

	.align 2
gUnknown_082EDC0C:: @ 82EDC0C
	.string "{STR_VAR_2} contacted you.\nWill you share {STR_VAR_1}?$"

	.align 2
gUnknown_082EDC34:: @ 82EDC34
	.string "{STR_VAR_2} contacted you.\nAdd to the members?$"

	.align 2
gUnknown_082EDC5C:: @ 82EDC5C
	.string "{STR_VAR_1}!\nAre these members OK?$"

	.align 2
gUnknown_082EDC78:: @ 82EDC78
	.string "Cancel {STR_VAR_1} MODE\nwith these members?$"

	.align 2
gUnknown_082EDC9C:: @ 82EDC9C
	.string "An “OK” was sent\nto {STR_VAR_1}.$"

	.align 2
gUnknown_082EDCB4:: @ 82EDCB4
	.string "The other TRAINER doesn’t appear\nto be available now…\p$"

	.align 2
gUnknown_082EDCEC:: @ 82EDCEC
	.string "You can’t transmit with a TRAINER\nwho is too far away.\p$"

	.align 2
gUnknown_082EDD24:: @ 82EDD24
	.string "The other TRAINER(S) is/are not\nready yet.\p$"

	.align 2
gUnknown_082EDD50:: @ 82EDD50
	.4byte gUnknown_082EDCEC
	.4byte gUnknown_082EDD24

	.align 2
gUnknown_082EDD58:: @ 82EDD58
	.string "The {STR_VAR_1} MODE with\nthese members will be canceled.{PAUSE 60}$"

	.align 2
gUnknown_082EDD8C:: @ 82EDD8C
	.string "There is a member who can no\nlonger remain available.\p$"

	.align 2
gUnknown_082EDDC4:: @ 82EDDC4
	.4byte gUnknown_082EDCB4
	.4byte gUnknown_082EDD8C

	.align 2
gUnknown_082EDDCC:: @ 82EDDCC
	.string "The other TRAINER appears\nunavailable…\p$"

	.align 2
gUnknown_082EDDF4:: @ 82EDDF4
	.string "{STR_VAR_1} sent back an “OK”!$"

	.align 2
gUnknown_082EDE0C:: @ 82EDE0C
	.string "{STR_VAR_1} OK’d your registration as\na member.$"

	.align 2
gUnknown_082EDE34:: @ 82EDE34
	.string "{STR_VAR_1} replied, “No…”\p$"

	.align 2
gUnknown_082EDE48:: @ 82EDE48
	.string "{STR_VAR_1}!\nAwaiting other members!$"

	.align 2
gUnknown_082EDE64:: @ 82EDE64
	.string "Quit being a member?$"

	.align 2
gUnknown_082EDE7C:: @ 82EDE7C
	.string "You stopped being a member.\p$"

	.align 2
gUnknown_082EDE9C:: @ 82EDE9C
	.4byte NULL
	.4byte gUnknown_082EDD8C
	.4byte gUnknown_082EDDCC
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDE34
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDE7C

	.align 2
gUnknown_082EDEC4:: @ 82EDEC4
	.string "The WIRELESS COMMUNICATION\nSYSTEM link has been established.$"

	.align 2
gUnknown_082EDF04:: @ 82EDF04
	.string "The WIRELESS COMMUNICATION\nSYSTEM link has been dropped…$"

	.align 2
gUnknown_082EDF40:: @ 82EDF40
	.string "The link with your friend has been\ndropped…$"

	.align 2
gUnknown_082EDF6C:: @ 82EDF6C
	.string "{STR_VAR_1} replied, “No…”$"

	.align 2
gUnknown_082EDF80:: @ 82EDF80
	.4byte NULL
	.4byte gUnknown_082EDF40
	.4byte gUnknown_082EDF40
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDF6C
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_082EDFA8:: @ 82EDF80
	.string "Do you want the {STR_VAR_2}\nMODE?$"

	.align 2
gUnknown_082EDFC4:: @ 82EDFC4
	.string "Do you want the {STR_VAR_2}\nMODE?$"

	.align 2
	.4byte gUnknown_082EDFA8
	.4byte gUnknown_082EDFC4

	.align 2
	.string "Communicating…\nPlease wait.$"

	.align 2
gUnknown_082EE004:: @ 82EE004
	.string "Awaiting {STR_VAR_1}’s response about\nthe trade…$"

	.align 2
gUnknown_082EE02C:: @ 82EE02C
	.string "Communicating{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE098:: @ 82EE098
	.string "Communicating with {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE104:: @ 82EE104
	.string "Please wait a while{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE17C:: @ 82EE17C
	.4byte gUnknown_082EE02C
	.4byte gUnknown_082EE098
	.4byte gUnknown_082EE104

	.align 2
gUnknown_082EE188:: @ 82EE188
	.string "Hiya! Is there something that you\nwanted to do?$"

	.align 2
gUnknown_082EE1B8:: @ 82EE1B8
	.string "Hello!\nWould you like to do something?$"

	.align 2
gUnknown_082EE1E0:: @ 82EE1E0
	.string "{STR_VAR_1}: Hiya, we meet again!\nWhat are you up for this time?$"

	.align 2
gUnknown_082EE218:: @ 82EE218
	.string "{STR_VAR_1}: Oh! {PLAYER}, hello!\nWould you like to do something?$"

	.align 2
gUnknown_082EE24C:: @ 82EE24C
	.4byte gUnknown_082EE188
	.4byte gUnknown_082EE1B8
	.4byte gUnknown_082EE1E0
	.4byte gUnknown_082EE218

	.align 2
gUnknown_082EE25C:: @ 82EE25C
	.string "Want to do something?$"

	.align 2
gUnknown_082EE274:: @ 82EE274
	.string "Would you like to do something?$"

	.align 2
gUnknown_082EE294:: @ 82EE294
	.string "{STR_VAR_1}: What would you like to\ndo now?$"

	.align 2
	.string "{STR_VAR_1}: Want to do anything else?$"

	.align 2
	.4byte gUnknown_082EE25C
	.4byte gUnknown_082EE274
	.4byte gUnknown_082EE294
	.4byte gUnknown_082EE294

	.align 2
gUnknown_082EE2E8:: @ 82EE2E8
	.string "Somebody has contacted you.{PAUSE 60}$"

	.align 2
gUnknown_082EE308:: @ 82EE308
	.string "{STR_VAR_1} has contacted you.{PAUSE 60}$"
	
	.align 2
gUnknown_082EE324:: @ 82EE324
	.4byte gUnknown_082EE2E8
	.4byte gUnknown_082EE308

	.align 2
gUnknown_082EE32C:: @ 82EE32C
	.string "Awaiting a response from\nthe other TRAINER…$"
	
	.align 2
gUnknown_082EE358:: @ 82EE358
	.string "Awaiting a response from\n{STR_VAR_1}…$"

	.align 2
gUnknown_082EE378:: @ 82EE378
	.4byte gUnknown_082EE32C
	.4byte gUnknown_082EE358

	.align 2
gUnknown_082EE380:: @ 82EE380
	.string "The other TRAINER showed\nyou their TRAINER CARD.\pWould you like to show your\nTRAINER CARD?$"

	.align 2
gUnknown_082EE3DC:: @ 82EE3DC
	.string "The other TRAINER challenges you\nto battle.\pWill you accept the battle\nchallenge?$"

	.align 2
gUnknown_082EE430:: @ 82EE430
	.string "The other TRAINER invites you\nto chat.\pWill you accept the chat\ninvitation?$"

	.align 2
gUnknown_082EE47C:: @ 82EE47C
	.string "There is an offer to trade your\nregistered Lv. {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}\pin exchange for a\nLv. {SPECIAL_F7 0x02} {SPECIAL_F7 0x03}.\pWill you accept this trade\noffer?$"

	.align 2
gUnknown_082EE4F0:: @ 82EE4F0
	.string "There is an offer to trade your\nregistered EGG.\lWill you accept this trade offer?$"

	.align 2
gUnknown_082EE544:: @ 82EE544
	.string "The chat has been dropped.\p$"

	.align 2
gUnknown_082EE560:: @ 82EE560
	.string "You declined the offer.\p$"

	.align 2
gUnknown_082EE57C:: @ 82EE57C
	.string "You declined the offer.\p$"

	.align 2
gUnknown_082EE598:: @ 82EE598
	.string "The chat was ended.\p$"

	.align 2
	.4byte gUnknown_082EE380
	.4byte gUnknown_082EE3DC
	.4byte gUnknown_082EE430
	.4byte gUnknown_082EE47C

	.align 2
gUnknown_082EE5C0:: @ 82EE5C0
	.string "Oh, hey! We’re in a chat right now.\nWant to join us?$"

	.align 2
gUnknown_082EE5F8:: @ 82EE5F8
	.string "{STR_VAR_1}: Hey, {PLAYER}!\nWe’re having a chat right now.\lWant to join us?$"

	.align 2
gUnknown_082EE638:: @ 82EE638
	.string "Oh, hi! We’re having a chat now.\nWould you like to join us?$"

	.align 2
gUnknown_082EE674:: @ 82EE674
	.string "{STR_VAR_1}: Oh, hi, {PLAYER}!\nWe’re having a chat now.\lWould you like to join us?$"

	.align 2
gUnknown_082EE6B8:: @ 82EE6B8
	.4byte gUnknown_082EE5C0
	.4byte gUnknown_082EE638
	.4byte gUnknown_082EE5F8
	.4byte gUnknown_082EE674

	.align 2
gUnknown_082EE6C8:: @ 82EE6C8
	.string "……\nThe TRAINER appears to be busy…\p$"

	.align 2
gUnknown_082EE6EC:: @ 82EE6EC
	.string "A battle, huh?\nAll right, just give me some time.$"

	.align 2
gUnknown_082EE720:: @ 82EE720
	.string "You want to chat, huh?\nSure, just wait a little.$"

	.align 2
gUnknown_082EE754:: @ 82EE754
	.string "Sure thing! As my “Greetings,”\nhere’s my TRAINER CARD.$"

	.align 2
gUnknown_082EE78C:: @ 82EE78C
	.string "A battle? Of course, but I need\ntime to get ready.$"

	.align 2
gUnknown_082EE7C0:: @ 82EE7C0
	.string "Did you want to chat?\nOkay, but please wait a moment.$"

	.align 2
gUnknown_082EE7F8:: @ 82EE7F8
	.string "As my introduction, I’ll show you\nmy TRAINER CARD.$"

	.align 2
gUnknown_082EE82C:: @ 82EE82C
	.4byte gUnknown_082EE6EC
	.4byte gUnknown_082EE720
	.4byte NULL
	.4byte gUnknown_082EE754
	.4byte gUnknown_082EE78C
	.4byte gUnknown_082EE7C0
	.4byte NULL
	.4byte gUnknown_082EE7F8

	.align 2
	.string "You want to chat, huh?\nSure, just wait a little.$"

	.align 2
gUnknown_082EE880:: @ 82EE880
	.string "Thanks for waiting!\nLet’s get our battle started!{PAUSE 60}$"

	.align 2
gUnknown_082EE8B8:: @ 82EE880
	.string "All right!\nLet’s chat!{PAUSE 60}$"

	.align 2
gUnknown_082EE8D4:: @ 82EE8D4
	.string "Sorry I made you wait!\nLet’s get started!{PAUSE 60}$"

	.align 2
gUnknown_082EE904:: @ 82EE904
	.string "Sorry I made you wait!\nLet’s chat.{PAUSE 60}$"

	.align 2
gUnknown_082EE92C:: @ 82EE92C
	.string "The trade will be started.{PAUSE 60}$"

	.align 2
gUnknown_082EE94C:: @ 82EE94C
	.string "The battle will be started.{PAUSE 60}$"

	.align 2
gUnknown_082EE96C:: @ 82EE96C
	.string "Entering the chat…{PAUSE 60}$"

	.align 2
gUnknown_082EE984:: @ 82EE984
	.4byte gUnknown_082EE94C
	.4byte gUnknown_082EE96C
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE94C
	.4byte gUnknown_082EE96C
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE880
	.4byte gUnknown_082EE8B8
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE8D4
	.4byte gUnknown_082EE904
	.4byte gUnknown_082EE92C

	.align 2
gUnknown_082EE9B4:: @ 82EE9B4
	.string "Sorry! My POKéMON don’t seem to\nbe feeling too well right now.\lLet me battle you another time.\p$"

	.align 2
gUnknown_082EEA14:: @ 82EEA14
	.string "I’m terribly sorry, but my POKéMON\naren’t feeling well…\pLet’s battle another time.\p$"

	.align 2
gUnknown_082EEA68:: @ 82EEA68
	.4byte gUnknown_082EE9B4
	.4byte gUnknown_082EEA14

	.align 2
gUnknown_082EEA70:: @ 82EEA70
	.string "Huh? My TRAINER CARD…\nWhere’d it go now?\lSorry! I’ll show you another time!\p$"

	.align 2
gUnknown_082EEAC0:: @ 82EEAC0
	.string "Oh? Now where did I put my\nTRAINER CARD?…\lSorry! I’ll show you later!\p$"

	.align 2
gUnknown_082EEB08:: @ 82EEB08
	.4byte gUnknown_082EEA70
	.4byte gUnknown_082EEAC0

	.align 2
gUnknown_082EEB10:: @ 82EEB10
	.string "If you want to do something with\nme, just give me a shout!\p$"

	.align 2
gUnknown_082EEB4C:: @ 82EEB4C
	.string "If you want to do something with\nme, don’t be shy.\p$"

	.align 2
gUnknown_082EEB80:: @ 82EEB80
	.4byte gUnknown_082EEB10
	.4byte gUnknown_082EEB4C

	.align 2
gUnknown_082EEB88:: @ 82EEB88
	.string "Whoops! Sorry, but I have to do\nsomething else.\lAnother time, okay?\p$"

	.align 2
gUnknown_082EEBD0:: @ 82EEBD0
	.string "If you want to battle, you need\ntwo POKéMON that are below\lLv. 30.\p$"

	.align 2
gUnknown_082EEC14:: @ 82EEC14
	.string "For a battle, you need two\nPOKéMON that are below Lv. 30.\p$"

	.align 2
gUnknown_082EEC50:: @ 82EEC50
	.string "Oh, all right.\nCome see me anytime, okay?\p$"

	.align 2
gUnknown_082EEC7C:: @ 82EEC7C
	.string "Oh…\nPlease come by anytime.\p$"

	.align 2
gUnknown_082EEC9C:: @ 82EEC9C
	.4byte gUnknown_082EEC50
	.4byte gUnknown_082EEC7C

	.align 2
gUnknown_082EECA4:: @ 82EECA4
	.string "Oh, sorry!\nI just can’t right this instant.\lLet’s chat another time.\p$"

	.align 2
gUnknown_082EECEC:: @ 82EECEC
	.string "Oh, I’m sorry.\nI have too much to do right now.\lLet’s chat some other time.\p$"

	.align 2
gUnknown_082EED3C:: @ 82EED3C
	.4byte gUnknown_082EECA4
	.4byte gUnknown_082EECEC

	.align 2
gUnknown_082EED44:: @ 82EED3C
	.string "Whoa!\nI can tell you’re pretty tough!\p$"

	.align 2
gUnknown_082EED6C:: @ 82EED6C
	.string "You used that move?\nThat’s good strategy!\p$"

	.align 2
gUnknown_082EED98:: @ 82EED98
	.string "Way to go!\nThat was an eye-opener!\p$"

	.align 2
gUnknown_082EEDBC:: @ 82EEDBC
	.string "Oh! How could you use that\nPOKéMON in that situation?\p$"

	.align 2
gUnknown_082EEDF4:: @ 82EEDF4
	.string "That POKéMON…\nIt’s been raised really well!\p$"

	.align 2
gUnknown_082EEE24:: @ 82EEE24
	.string "That’s it!\nThis is the right move now!\p$"

	.align 2
gUnknown_082EEE4C:: @ 82EEE4C
	.string "That’s awesome!\nYou can battle that way?\p$"

	.align 2
gUnknown_082EEE78:: @ 82EEE78
	.string "You have exquisite timing for\nswitching POKéMON!\p$"

	.align 2
gUnknown_082EEEAC:: @ 82EEEAC
	.4byte gUnknown_082EED44
	.4byte gUnknown_082EED6C
	.4byte gUnknown_082EED98
	.4byte gUnknown_082EEDBC
	.4byte gUnknown_082EEDF4
	.4byte gUnknown_082EEE24
	.4byte gUnknown_082EEE4C
	.4byte gUnknown_082EEE78

	.align 2
gUnknown_082EEECC:: @ 82EEECC
	.string "Oh, I see!\nThis is educational!\p$"

	.align 2
gUnknown_082EEEF0:: @ 82EEEF0
	.string "Don’t say anything funny anymore!\nI’m sore from laughing!\p$"

	.align 2
gUnknown_082EEF2C:: @ 82EEF2C
	.string "Oh?\nSomething like that happened.\p$"

	.align 2
gUnknown_082EEF50:: @ 82EEF50
	.string "Hmhm… What?\nSo is this what you’re saying?\p$"

	.align 2
gUnknown_082EEF7C:: @ 82EEF7C
	.string "Is that right?\nI didn’t know that.\p$"

	.align 2
gUnknown_082EEFA0:: @ 82EEFA0
	.string "Ahaha!\nWhat is that about?\p$"

	.align 2
gUnknown_082EEFBC:: @ 82EEFBC
	.string "Yes, that’s exactly it!\nThat’s what I meant.\p$"

	.align 2
gUnknown_082EEFEC:: @ 82EEFEC
	.string "In other words…\nYes! That’s right!\p$"

	.align 2
gUnknown_082EF010:: @ 82EF010
	.4byte gUnknown_082EEECC
	.4byte gUnknown_082EEEF0
	.4byte gUnknown_082EEF2C
	.4byte gUnknown_082EEF50
	.4byte gUnknown_082EEF7C
	.4byte gUnknown_082EEFA0
	.4byte gUnknown_082EEFBC
	.4byte gUnknown_082EEFEC

	.align 2
gUnknown_082EF030:: @ 82EF030
	.string "I’m just showing my TRAINER CARD\nas my way of greeting.\p$"

	.align 2
gUnknown_082EF06C:: @ 82EF06C
	.string "I hope I get to know you better!\p$"

	.align 2
gUnknown_082EF090:: @ 82EF010
	.string "We’re showing each other our\nTRAINER CARDS to get acquainted.\p$"

	.align 2
gUnknown_082EF0D0:: @ 82EF0D0
	.string "Glad to meet you.\nPlease don’t be a stranger!\p$"

	.align 2
gUnknown_082EF100:: @ 82EF100
	.4byte gUnknown_082EF030
	.4byte gUnknown_082EF06C
	.4byte gUnknown_082EF090
	.4byte gUnknown_082EF0D0

	.align 2
gUnknown_082EF110:: @ 82EF110
	.string "Yeahah!\nI really wanted this POKéMON!\p$"

	.align 2
gUnknown_082EF138:: @ 82EF138
	.string "Finally, a trade got me that\nPOKéMON I’d wanted a long time.\p$"

	.align 2
gUnknown_082EF178:: @ 82EF178
	.string "I’m trading POKéMON right now.\p$"

	.align 2
gUnknown_082EF198:: @ 82EF198
	.string "I finally got that POKéMON I\nwanted in a trade!\p$"

	.align 2
gUnknown_082EF1CC:: @ 82EF1CC
	.4byte gUnknown_082EF110
	.4byte gUnknown_082EF138
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EF178
	.4byte gUnknown_082EF198
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_082EF1EC:: @ 82EF1EC
	.string "{STR_VAR_1} checked the\nTRADING BOARD.\p$"

	.align 2
gUnknown_082EF20C:: @ 82EF20C
	.string "Welcome to the TRADING BOARD.\pYou may register your POKéMON\nand offer it up for a trade.\pWould you like to register one of\nyour POKéMON?$"

	.align 2
gUnknown_082EF298:: @ 82EF298
	.string "This TRADING BOARD is used for\noffering a POKéMON for a trade.\pAll you need to do is register a\nPOKéMON for a trade.\pAnother TRAINER may offer a party\nPOKéMON in return for the trade.\pWe hope you will register POKéMON\nand trade them with many, many\lother TRAINERS.\pWould you like to register one of\nyour POKéMON?$"

	.align 2
	.string "We have registered your POKéMON for\ntrade on the TRADING BOARD.\pThank you for using this service!\p$"

	.align 2
	.string "Nobody has registered any POKéMON\nfor trade on the TRADING BOARD.\p\n$"

	.align 2
gUnknown_082EF47C:: @ 82EF47C
	.string "Please choose the type of POKéMON\nthat you would like in the trade.\n$"

	.align 2
gUnknown_082EF4C4:: @ 82EF4C4
	.string "Which of your party POKéMON will\nyou offer in trade?\p$"

	.align 2
gUnknown_082EF4FC:: @ 82EF4FC
	.string "Registration has been canceled.\p$"

	.align 2
gUnknown_082EF520:: @ 82EF520
	.string "Registration has been completed.\p$"

	.align 2
gUnknown_082EF544:: @ 82EF544
	.string "The trade has been canceled.\p$"

	.align 2
gUnknown_082EF564:: @ 82EF564
	.string "Cancel the registration of your\nLv. {STR_VAR_2} {STR_VAR_1}?$"

	.align 2
gUnknown_082EF590:: @ 82EF590
	.string "Cancel the registration of your\nEGG?$"

	.align 2
gUnknown_082EF5B8:: @ 82EF5B8
	.string "The registration has been canceled.\p$"

	.align 2
	.string "TRAINERS wishing to make a trade\nwill be listed.$"

	.align 2
	.string "Please choose the TRAINER with whom\nyou would like to trade POKéMON.$"

	.align 2
gUnknown_082EF65C:: @ 82EF65C
	.string "Would you like to ask {STR_VAR_1} to\nmake a trade?$"

	.align 2
	.string "Awaiting a response from\nthe other TRAINER…$"

	.align 2
	.string "You have not registered a POKéMON\nfor trading.\p$"

	.align 2
gUnknown_082EF6E4:: @ 82EF6E4
	.string "You don’t have a {STR_VAR_2}-type\nPOKéMON that {STR_VAR_1} wants.\p$"

	.align 2
gUnknown_082EF718:: @ 82EF718
	.string "You don’t have an EGG that\n{STR_VAR_1} wants.\p$"

	.align 2
gUnknown_082EF740:: @ 82EF740
	.string "{STR_VAR_1} can’t make a trade for\nyour POKéMON right now.\p$"

	.align 2
gUnknown_082EF774:: @ 82EF774
	.string "You can’t make a trade for\n{STR_VAR_1}’s POKéMON right now.\p$"

	.align 2
	.4byte gUnknown_082EF740
	.4byte gUnknown_082EF774

	.align 2
gUnknown_082EF7B0:: @ 82EF7B0
	.string "Your trade offer was rejected.\p$"

	.align 2
gUnknown_082EF7D0:: @ 82EF7D0
	.string "EGG TRADE$"

	.align 2
gUnknown_082EF7DC:: @ 82EF7DC
	.string "{UNK_CTRL_F80A}CHOOSE  {UNK_CTRL_F800}JOIN  {UNK_CTRL_F801}CANCEL$"

	.align 2
gUnknown_082EF7F8:: @ 82EF7F8
	.string "Please choose a TRAINER.$"

	.align 2
gUnknown_082EF814:: @ 82EF814
	.string "Please choose a TRAINER for\na SINGLE BATTLE.$"

	.align 2
gUnknown_082EF844:: @ 82EF844
	.string "Please choose a TRAINER for\na DOUBLE BATTLE.$"

	.align 2
gUnknown_082EF874:: @ 82EF874
	.string "Please choose the LEADER\nfor a MULTI BATTLE.$"

	.align 2
gUnknown_082EF8A4:: @ 82EF8A4
	.string "Please choose the TRAINER to\ntrade with.$"

	.align 2
gUnknown_082EF8D0:: @ 82EF8D0
	.string "Please choose the TRAINER who is\nsharing WONDER CARDS.$"

	.align 2
gUnknown_082EF908:: @ 82EF908
	.string "Please choose the TRAINER who is\nsharing WONDER NEWS.$"

	.align 2
gUnknown_082EF940:: @ 82EF940
	.string "Jump with mini POKéMON!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF974:: @ 82EF974
	.string "BERRY CRUSH!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF99C:: @ 82EF974
	.string "DODRIO BERRY-PICKING!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF9CC:: @ 82EF9CC
	.string "BERRY BLENDER!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF9F8:: @ 82EF9F8
	.string "RECORD CORNER!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA24:: @ 82EFA24
	.string "COOLNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA50:: @ 82EFA50
	.string "BEAUTY CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA7C:: @ 82EFA7C
	.string "CUTENESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFAA8:: @ 82EFAA8
	.string "SMARTNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFAD8:: @ 82EFAD8
	.string "TOUGHNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB08:: @ 82EFB08
	.string "BATTLE TOWER LEVEL 50!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB3C:: @ 82EFB3C
	.string "BATTLE TOWER OPEN LEVEL!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB70:: @ 82EFB70
	.4byte gUnknown_082EF814
	.4byte gUnknown_082EF844
	.4byte gUnknown_082EF874
	.4byte gUnknown_082EF8A4
	.4byte gUnknown_082EF940
	.4byte gUnknown_082EF974
	.4byte gUnknown_082EF99C
	.4byte gUnknown_082EF8D0
	.4byte gUnknown_082EF908
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EF9F8
	.4byte gUnknown_082EF9CC
	.4byte NULL
	.4byte gUnknown_082EFA24
	.4byte gUnknown_082EFA50
	.4byte gUnknown_082EFA7C
	.4byte gUnknown_082EFAA8
	.4byte gUnknown_082EFAD8
	.4byte gUnknown_082EFB08
	.4byte gUnknown_082EFB3C

	.align 2
gUnknown_082EFBC8:: @ 82EFBC8
	.string "Searching for a WIRELESS\nCOMMUNICATION SYSTEM. Wait...$"

	.align 2
	.string "For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p$"

	.align 2
gUnknown_082EFC3C:: @ 82EFC3C
	.string "Awaiting {STR_VAR_1}’s response…$"

	.align 2
gUnknown_082EFC54:: @ 82EFC54
	.string "{STR_VAR_1} has been asked to register\nyou as a member. Please wait.$"

	.align 2
gUnknown_082EFC90:: @ 82EFC90
	.string "Awaiting a response from the\nWIRELESS COMMUNICATION SYSTEM.$"

	.align 2
	.string "Please wait for other TRAINERS to\ngather and get ready.$"

	.align 2
gUnknown_082EFD04:: @ 82EFD04
	.string "No CARDS appear to be shared \nright now.$"

	.align 2
gUnknown_082EFD30:: @ 82EFD30
	.string "No NEWS appears to be shared\nright now.$"

	.align 2
gUnknown_082EFD58:: @ 82EFD58
	.4byte gUnknown_082EFD04
	.4byte gUnknown_082EFD30

	.align 2
gUnknown_082EFD60:: @ 82EFD60
	.string "BATTLE$"

	.align 2
gUnknown_082EFD68:: @ 82EFD68
	.string "CHAT$"

	.align 2
gUnknown_082EFD70:: @ 82EFD70
	.string "GREETINGS$"

	.align 2
gUnknown_082EFD7C:: @ 82EFD7C
	.string "EXIT$"

	.align 2
gUnknown_082EFD84:: @ 82EFD84
	.string "EXIT$"

	.align 2
gUnknown_082EFD8C:: @ 82EFD8C
	.string "INFO$"

	.align 2
gUnknown_082EFD94:: @ 82EFD94
	.string "NAME{CLEAR_TO 0x3C}WANTED{CLEAR_TO 0x6E}OFFER{CLEAR_TO 0xC6}LV.$"

	.align 2
gUnknown_082EFDB0:: @ 82EFDB0
	.string "SINGLE BATTLE$"

	.align 2
gUnknown_082EFDC0:: @ 82EFDC0
	.string "DOUBLE BATTLE$"

	.align 2
gUnknown_082EFDD0:: @ 82EFDD0
	.string "MULTI BATTLE$"

	.align 2
gUnknown_082EFDE0:: @ 82EFDE0
	.string "POKéMON TRADES$"

	.align 2
gUnknown_082EFDF0:: @ 82EFDF0
	.string "CHAT$"

	.align 2
gUnknown_082EFDF8:: @ 82EFDF8
	.string "CARDS$"

	.align 2
gUnknown_082EFE00:: @ 82EFE00
	.string "WONDER CARDS$"

	.align 2
gUnknown_082EFE10:: @ 82EFE10
	.string "WONDER NEWS$"

	.align 2
gUnknown_082EFE1C:: @ 82EFE1C
	.string "POKéMON JUMP$"

	.align 2
gUnknown_082EFE2C:: @ 82EFE2C
	.string "BERRY CRUSH$"

	.align 2
gUnknown_082EFE38:: @ 82EFE38
	.string "BERRY-PICKING$"

	.align 2
gUnknown_082EFE48:: @ 82EFE48
	.string "SEARCH$"

	.align 2
gUnknown_082EFE50:: @ 82EFE50
	.string "BERRY BLENDER$"

	.align 2
gUnknown_082EFE60:: @ 82EFE60
	.string "RECORD CORNER$"

	.align 2
gUnknown_082EFE70:: @ 82EFE70
	.string "COOL CONTEST$"

	.align 2
gUnknown_082EFE80:: @ 82EFE80
	.string "BEAUTY CONTEST$"

	.align 2
gUnknown_082EFE90:: @ 82EFE90
	.string "CUTE CONTEST$"

	.align 2
gUnknown_082EFEA0:: @ 82EFEA0
	.string "SMART CONTEST$"

	.align 2
gUnknown_082EFEB0:: @ 82EFEB0
	.string "TOUGH CONTEST$"

	.align 2
gUnknown_082EFEC0:: @ 82EFEC0
	.string "BATTLE TOWER LV. 50$"

	.align 2
gUnknown_082EFED4:: @ 82EFED4
	.string "BATTLE TOWER OPEN LEVEL$"

	.align 2
gUnknown_082EFEEC:: @ 82EFEEC
	.string "It’s a NORMAL CARD.$"

	.align 2
gUnknown_082EFF00:: @ 82EFF00
	.string "It’s a BRONZE CARD!$"

	.align 2
gUnknown_082EFF14:: @ 82EFF14
	.string "It’s a COPPER CARD!$"

	.align 2
gUnknown_082EFF28:: @ 82EFF28
	.string "It’s a SILVER CARD!$"

	.align 2
gUnknown_082EFF3C:: @ 82EFF3C
	.string "It’s a GOLD CARD!$"

	.align 2
gUnknown_082EFF50:: @ 82EFF50
	.4byte gUnknown_082EFEEC
	.4byte gUnknown_082EFF00
	.4byte gUnknown_082EFF14
	.4byte gUnknown_082EFF28
	.4byte gUnknown_082EFF3C

gUnknown_082EFF64:: @ 82EFF64
	.string "This is {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}’s\nTRAINER CARD…\l{SPECIAL_F7 0x02}\pPOKéDEX: {SPECIAL_F7 0x03}\nTIME:    {SPECIAL_F7 0x04}:{SPECIAL_F7 0x05}\p$"

	.align 2
gUnknown_082EFFA4:: @ 82EFFA4
	.string "BATTLES: WINS: {SPECIAL_F7 0x00}  LOSSES: {SPECIAL_F7 0x02}\nTRADES: {SPECIAL_F7 0x03}\p“{SPECIAL_F7 0x04} {SPECIAL_F7 0x05}\n{SPECIAL_F7 0x06} {SPECIAL_F7 0x07}”\p$"

	.align 2
gUnknown_082EFFDC:: @ 82EFFDC
	.string "{SPECIAL_F7 0x01}: Glad to have met you!{PAUSE 60}$"

	.align 2
gUnknown_082EFFFC:: @ 82EFFFC
	.string "{SPECIAL_F7 0x01}: Glad to meet you!{PAUSE 60}$"

	.align 2
gUnknown_082F0018:: @ 82F0018
	.4byte gUnknown_082EFFDC
	.4byte gUnknown_082EFFFC

	.align 2
gUnknown_082F0020:: @ 82F0020
	.string "Finished checking {SPECIAL_F7 0x01}’s\nTRAINER CARD.{PAUSE 60}$"

	.align 2
gUnknown_082F0048:: @ 82F0048
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082EFDB0
	.4byte gUnknown_082EFDC0
	.4byte gUnknown_082EFDD0
	.4byte gUnknown_082EFDE0
	.4byte gUnknown_082EFDF0
	.4byte gUnknown_082EFE00
	.4byte gUnknown_082EFE10
	.4byte gUnknown_082EFDF8
	.4byte gUnknown_082EFE1C
	.4byte gUnknown_082EFE2C
	.4byte gUnknown_082EFE38
	.4byte gUnknown_082EFE48
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082EFED4
	.4byte gUnknown_082EFE60
	.4byte gUnknown_082EFE50
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082ED8C4
	.4byte gUnknown_082EFE00
	.4byte gUnknown_082EFE10
	.4byte gUnknown_082EFE70
	.4byte gUnknown_082EFE80
	.4byte gUnknown_082EFE90
	.4byte gUnknown_082EFEA0
	.4byte gUnknown_082EFEB0
	.4byte gUnknown_082EFEC0

	.align 2
gUnknown_082F00BC:: @ 82F00BC
	window_template 0x00, 0x00, 0x00, 0x1E, 0x02, 0x0F, 0x0008

	.align 2
gUnknown_082F00C4:: @ 82F00C4
	.byte 0x01, 0x02, 0x00, 0x00
	.byte 0x02, 0x02, 0x00, 0x00
	.byte 0x03, 0x04, 0x00, 0x00
	.byte 0x04, 0x02, 0x00, 0x00
	.byte 0x09, 0x25, 0x00, 0x00
	.byte 0x0a, 0x25, 0x00, 0x00
	.byte 0x0b, 0x35, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x0f, 0x24, 0x00, 0x00
	.byte 0x10, 0x24, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x17, 0x24, 0x00, 0x00
	.byte 0x18, 0x24, 0x00, 0x00
	.byte 0x19, 0x24, 0x00, 0x00
	.byte 0x1a, 0x24, 0x00, 0x00
	.byte 0x1b, 0x24, 0x00, 0x00
	.byte 0x1c, 0x02, 0x00, 0x00
	.byte 0x0e, 0x02, 0x00, 0x00

	.align 2
gUnknown_082F011C:: @ 82F011C
	window_template 0x00, 0x01, 0x03, 0x0d, 0x08, 0x0f, 0x0044

	.align 2
gUnknown_082F0124:: @ 82F0124
	window_template 0x00, 0x01, 0x03, 0x0d, 0x0a, 0x0f, 0x0044

	.align 2
gUnknown_082F012C:: @ 82F012C
	window_template 0x00, 0x10, 0x03, 0x07, 0x04, 0x0f, 0x00c6

	.align 2
gUnknown_082F0134:: @ 82F0134
	.4byte gUnknown_082ED8C4
	.4byte 0x00000000
	.4byte gUnknown_082ED8C4
	.4byte 0x00000001
	.4byte gUnknown_082ED8C4
	.4byte 0x00000002
	.4byte gUnknown_082ED8C4
	.4byte 0x00000003
	.4byte gUnknown_082ED8C4
	.4byte 0x00000004

	.align 2
gUnknown_082F015C:: @ 82F015C struct ListMenuTemplate
	.4byte gUnknown_082F0134
	.4byte NULL
	.4byte sub_8013278
	.byte 0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x21, 0x31, 0x00, 0x41

	.align 2
gUnknown_082F0174:: @ 82F0174
	window_template 0x00, 0x01, 0x03, 0x11, 0x0a, 0x0f, 0x0044

	.align 2
gUnknown_082F017C:: @ 82F017C
	window_template 0x00, 0x14, 0x03, 0x07, 0x04, 0x0f, 0x00ee

	.align 2
gUnknown_082F0184:: @ 82F0184
	.4byte gUnknown_082ED8C4, 0x00000000
	.4byte gUnknown_082ED8C4, 0x00000001
	.4byte gUnknown_082ED8C4, 0x00000002
	.4byte gUnknown_082ED8C4, 0x00000003
	.4byte gUnknown_082ED8C4, 0x00000004
	.4byte gUnknown_082ED8C4, 0x00000005
	.4byte gUnknown_082ED8C4, 0x00000006
	.4byte gUnknown_082ED8C4, 0x00000007
	.4byte gUnknown_082ED8C4, 0x00000008
	.4byte gUnknown_082ED8C4, 0x00000009
	.4byte gUnknown_082ED8C4, 0x0000000a
	.4byte gUnknown_082ED8C4, 0x0000000b
	.4byte gUnknown_082ED8C4, 0x0000000c
	.4byte gUnknown_082ED8C4, 0x0000000d
	.4byte gUnknown_082ED8C4, 0x0000000e
	.4byte gUnknown_082ED8C4, 0x0000000f

	.align 2
gUnknown_082F0204:: @ 82F0204 struct ListMenuTemplate
	.4byte gUnknown_082F0184
	.4byte sub_81AF078
	.4byte sub_8013DF4
	.byte 0x10, 0x00, 0x05, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x40, 0x01

	.align 2
gUnknown_082F021C:: @ 82F021C
	window_template 0x00, 0x14, 0x05, 0x10, 0x08, 0x0f, 0x0001
	
	.align 2
gUnknown_082F0224:: @ 82F0224
	.4byte gUnknown_082EFD70, 0x00000208
	.4byte gUnknown_082EFD60, 0x00000241
	.4byte gUnknown_082EFD68, 0x00000245
	.4byte gUnknown_082EFD7C, 0x00000040

	.align 2
gUnknown_082F0244:: @ 82F0244 struct ListMenuTemplate
	.4byte gUnknown_082F0224
	.byte 0x79, 0xf0, 0x1a, 0x08
	.4byte NULL
	.byte 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F025C:: @ 82F025C
	window_template 0x00, 0x12, 0x07, 0x10, 0x06, 0x0f, 0x0001

gUnknown_082F0264:: @ 82F0264
	.4byte gUnknown_085EA333, 0x00000001
	.4byte gUnknown_082EFD8C, 0x00000002
	.4byte gUnknown_082EFD7C, 0x00000003

	.align 2
gUnknown_082F027C:: @ 82F027C
	.4byte gUnknown_082F0264
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0294:: @ 82F0294
	window_template 0x00, 0x14, 0x01, 0x10, 0x0c, 0x0f, 0x0001

	.align 2
gUnknown_082F029C:: @ 82F029C
	.4byte gTypeNames, 0x00000000 @ NORMAL
	.4byte gTypeNames+0x46, 0x0000000a @ FIRE
	.4byte gTypeNames+0x4D, 0x0000000b @ WATER
	.4byte gTypeNames+0x5B, 0x0000000d @ ELECTR
	.4byte gTypeNames+0x54, 0x0000000c @ GRASS
	.4byte gTypeNames+0x69, 0x0000000f @ ICE
	.4byte gTypeNames+0x1C, 0x00000004 @ GROUND
	.4byte gTypeNames+0x23, 0x00000005 @ ROCK
	.4byte gTypeNames+0x0E, 0x00000002 @ FLYING
	.4byte gTypeNames+0x62, 0x0000000e @ PSYCHC
	.4byte gTypeNames+0x07, 0x00000001 @ FIGHT
	.4byte gTypeNames+0x15, 0x00000003 @ POISON
	.4byte gTypeNames+0x2A, 0x00000006 @ BUG
	.4byte gTypeNames+0x31, 0x00000007 @ GHOST
	.4byte gTypeNames+0x70, 0x00000010 @ DRAGON
	.4byte gTypeNames+0x38, 0x00000008 @ STEEL
	.4byte gTypeNames+0x77, 0x00000011 @ DARK
	.4byte gUnknown_082EFD7C, 0x00000012 @ EXIT

	.align 2
gUnknown_082F032C:: @ 82F032C
	.4byte gUnknown_082F029C
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x12, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0344:: @ 82F0344
	window_template 0x00, 0x01, 0x01, 0x1c, 0x02, 0x0d, 0x0001

	.align 2
gUnknown_082F034C:: @ 82F034C
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0c, 0x0d, 0x0039

	.align 2
gUnknown_082F0354:: @ 82F0354
	.4byte gUnknown_082ED8C4, 0xfffffffd
	.4byte gUnknown_082ED8C4, 0x00000000
	.4byte gUnknown_082ED8C4, 0x00000001
	.4byte gUnknown_082ED8C4, 0x00000002
	.4byte gUnknown_082ED8C4, 0x00000003
	.4byte gUnknown_082ED8C4, 0x00000004
	.4byte gUnknown_082ED8C4, 0x00000005
	.4byte gUnknown_082ED8C4, 0x00000006
	.4byte gUnknown_082ED8C4, 0x00000007
	.4byte gUnknown_082EFD84, 0x00000008
	
	.align 2
gUnknown_082F03A4:: @ 82F03A4
	.4byte gUnknown_082F0354
	.4byte sub_81AF078
	.4byte sub_8017BE8
	.byte 0x0a, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0xe1, 0xdf, 0x00, 0x01

	.align 2
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0c, 0x0d, 0x0039
	
	.align 2
gUnknown_082F03C4:: @ 82F03C4
	.4byte gUnknown_082ED8C4, 0x00000000
	.4byte gUnknown_082ED8C4, 0x00000001
	.4byte gUnknown_082ED8C4, 0x00000002
	.4byte gUnknown_082ED8C4, 0x00000003
	.4byte gUnknown_082ED8C4, 0x00000004
	.4byte gUnknown_082ED8C4, 0x00000005
	.4byte gUnknown_082ED8C4, 0x00000006
	.4byte gUnknown_082ED8C4, 0x00000007
	.4byte gUnknown_082ED8C4, 0x00000008
	.4byte gUnknown_082ED8C4, 0x00000009
	.4byte gUnknown_082ED8C4, 0x0000000a
	.4byte gUnknown_082ED8C4, 0x0000000b
	.4byte gUnknown_082ED8C4, 0x0000000c
	.4byte gUnknown_082ED8C4, 0x0000000d
	.4byte gUnknown_082ED8C4, 0x0000000e
	.4byte gUnknown_082ED8C4, 0x0000000f

	.align 2
	.4byte gUnknown_082F03C4
	.4byte sub_81AF078
	.4byte nullsub_14
	.byte 0x10, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x40, 0x01
	
	.align 2
gUnknown_082F045C:: @ 82F045C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F0474:: @ 82F0474
	.byte 0x01, 0xff

	.align 2
gUnknown_082F0478:: @ 82F0478
	.byte 0x02, 0xff

	.align 2
gUnknown_082F047C:: @ 82F047C
	.byte 0x03, 0xff

	.align 2
gUnknown_082F0480:: @ 82F0480
	.byte 0x04, 0xff

	.align 2
gUnknown_082F0484:: @ 82F0484
	.byte 0x09, 0xff

	.align 2
gUnknown_082F0488:: @ 82F0488
	.byte 0x0a, 0xff

	.align 2
gUnknown_082F048C:: @ 82F048C
	.byte 0x0b, 0xff

	.align 2
gUnknown_082F0490:: @ 82F0490
	.byte 0x15, 0xff

	.align 2
gUnknown_082F0494:: @ 82F0494
	.byte 0x16, 0xff

	.align 2
gUnknown_082F0498:: @ 82F0498
	.byte 0x40, 0x41, 0x44, 0x45, 0x48, 0x51, 0x52, 0x53, 0x54, 0xff

	.align 2
gUnknown_082F04A4:: @ 82F04A4
	.byte 0x0c, 0xff

	.align 2
gUnknown_082F04A8:: @ 82F04A8
	.byte 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x15, 0x16, 0x0d, 0xff

	.align 2
gUnknown_082F04B4:: @ 82F04B4
	.byte 0x0f, 0xff

	.align 2
gUnknown_082F04B8:: @ 82F04B8
	.byte 0x10, 0xff

	.align 2
gUnknown_082F04BC:: @ 82F04BC
	.byte 0x17, 0xff

	.align 2
gUnknown_082F04C0:: @ 82F04C0
	.byte 0x18, 0xff

	.align 2
gUnknown_082F04C4:: @ 82F04C4
	.byte 0x19, 0xff

	.align 2
gUnknown_082F04C8:: @ 82F04C8
	.byte 0x1a, 0xff

	.align 2
gUnknown_082F04CC:: @ 82F04CC
	.byte 0x1b, 0xff

	.align 2
gUnknown_082F04D0:: @ 82F04D0
	.byte 0x1c, 0xff

	.align 2
gUnknown_082F04D4:: @ 82F04D4
	.byte 0x0e, 0xff

	.align 2
gUnknown_082F04D8:: @ 82F04D8
	.4byte gUnknown_082F0474
	.4byte gUnknown_082F0478
	.4byte gUnknown_082F047C
	.4byte gUnknown_082F0480
	.4byte gUnknown_082F0484
	.4byte gUnknown_082F0488
	.4byte gUnknown_082F048C
	.4byte gUnknown_082F0490
	.4byte gUnknown_082F0494
	.4byte gUnknown_082F0498
	.4byte gUnknown_082F04A4
	.4byte gUnknown_082F04A8
	.4byte gUnknown_082F04B4
	.4byte gUnknown_082F04B8
	.4byte NULL
	.4byte gUnknown_082F04BC
	.4byte gUnknown_082F04C0
	.4byte gUnknown_082F04C4
	.4byte gUnknown_082F04C8
	.4byte gUnknown_082F04CC
	.4byte gUnknown_082F04D0
	.4byte gUnknown_082F04D4

	.align 2
gUnknown_082F0530:: @ 82F0530
	.byte 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x15
	.byte 0x16, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x00, 0x17
	.byte 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x0e, 0x00, 0x00

	.align 2
gUnknown_082F0548:: @ 82F0548
	.incbin "graphics/interface/test_textbox.gbapal"

	.align 2
gUnknown_082F0568:: @ 82F0568
	.incbin "graphics/interface/test_textbox.4bpp.lz"

	.align 2
gUnknown_082F0598:: @ 82F0598 struct BgTemplate
	.4byte 0x000000f8
	.4byte 0x000010e1
	.4byte 0x000020d2
	.4byte 0x000030c3

	.align 2
gUnknown_082F05A8:: @ 82F05A8
	window_template 0x00, 0x00, 0x00, 0x1e, 0x02, 0x0c, 0x0013
	window_template 0x00, 0x01, 0x0f, 0x1c, 0x04, 0x0c, 0x004f
	window_template 0x00, 0x00, 0x0f, 0x1e, 0x05, 0x0d, 0x004f
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

	.align 2
gUnknown_082F05C8:: @ 82F05C8
	window_template 0x00, 0x01, 0x0f, 0x1c, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05D0:: @ 82F05D0
	window_template 0x00, 0x01, 0x0f, 0x14, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05D8:: @ 82F05D8
	window_template 0x00, 0x01, 0x0f, 0x13, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05E0:: @ 82F05E0
	window_template 0x00, 0x08, 0x06, 0x0e, 0x06, 0x0c, 0x0155

	.align 2
gUnknown_082F05E8:: @ 82F05E8
	window_template 0x00, 0x17, 0x0f, 0x06, 0x04, 0x0c, 0x0155

	.align 2
gUnknown_082F05F0:: @ 82F05F0
	window_template 0x00, 0x16, 0x0b, 0x07, 0x08, 0x0c, 0x0155

	.align 2
gUnknown_082F05F8:: @ 82F05F8
	window_template 0x00, 0x16, 0x0d, 0x07, 0x06, 0x0c, 0x0155

	.align 2
gUnknown_082F0600:: @ 82F0600
	window_template 0x00, 0x16, 0x0f, 0x07, 0x04, 0x0c, 0x0155

	.align 2
gUnknown_082F0608:: @ 82F0608
	.4byte gUnknown_085EEDEC, 0x00000000
	.4byte gUnknown_085EEDFC, 0x00000001
	.4byte gUnknown_085EEE28, 0xfffffffe

	.align 2
gUnknown_082F0620:: @ 82F0620
	.4byte gUnknown_085EEE08, 0x00000000
	.4byte gUnknown_085EEE20, 0x00000001
	.4byte gUnknown_085E8CF7, 0xfffffffe

	.align 2
gUnknown_082F0638:: @ 82F0638 struct ListMenuTemplate
	.4byte NULL
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0650:: @ 82F0650
	.4byte gUnknown_085EEE30, 0x00000000
	.4byte gUnknown_085EEE38, 0x00000001
	.4byte gUnknown_085EEE40, 0x00000002
	.4byte gUnknown_085E8CF7, 0xfffffffe

	.align 2
gUnknown_082F0670:: @ 82F0670
	.4byte gUnknown_085EEE30, 0x00000000
	.4byte gUnknown_085EEE40, 0x00000002
	.4byte gUnknown_085E8CF7, 0xfffffffe

	.align 2
gUnknown_082F0688:: @ 82F0688
	.4byte gUnknown_085EEE30, 0x00000000
	.4byte gUnknown_085EEE38, 0x00000001
	.4byte gUnknown_085E8CF7, 0xfffffffe

	.align 2
gUnknown_082F06A0:: @ 82F06A0
	.4byte gUnknown_085EEE30, 0x00000000
	.4byte gUnknown_085E8CF7, 0xfffffffe

	.align 2
gUnknown_082F06B0:: @ 82F06B0 struct ListMenuTemplate
	.4byte gUnknown_082F0650
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06C8:: @ 82F06C8
	.4byte gUnknown_082F0670
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06E0:: @ 82F06E0
	.4byte gUnknown_082F0688
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06F8:: @ 82F06F8
	.4byte gUnknown_082F06A0
	.4byte sub_81AF078
	.4byte NULL
	.byte 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
	.4byte gUnknown_085EEE48
	.4byte gUnknown_085EEE8C
	.4byte gUnknown_085EEEB8
	.4byte gUnknown_085EEED4

	.align 2
gUnknown_082F0720:: @ 82F0720 struct TextColor
	.byte 0x00, 0x01, 0x02
	
	.align 2
	.byte 0x00, 0x01, 0x02

	.align 2
gUnknown_082F0728:: @ 82F0728 struct TextColor
	.byte 0x01, 0x02, 0x03

	.align 2
gUnknown_082F072C:: @ 82F072C
	.byte 0x21, 0x2c, 0x1f, 0x23, 0x25, 0x24, 0x41, 0x42
	.byte 0x00, 0x00, 0x22, 0x28, 0x20, 0x2f, 0x2f, 0x0e
	.byte 0x14, 0x2d, 0x00, 0x00

	.align 2
gUnknown_082F0740:: @ 82F0740
	.2byte 0x0004, 0x0006, 0x000d, 0x0008
	.2byte 0x000a, 0x0006, 0x0001, 0x0008
	.2byte 0x000d, 0x0004, 0x0007, 0x0004
	.2byte 0x0001, 0x0004, 0x0007, 0x0008

	.align 2
gUnknown_082F0760:: @ 82F0760
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0xff, 0xff, 0x00
	.byte 0x00, 0x01

gUnknown_082F076A:: @ 82F076A
	.byte 0x00, 0x02, 0x01, 0x04, 0x03

gUnknown_082F076F:: @ 82F076F
	.byte 0x01, 0x03, 0x01, 0x04, 0x02

gUnknown_082F0774:: @ 82F0774
	.byte 0x09, 0x08, 0x07, 0x02, 0x06, 0x05, 0x04, 0x03
	.byte 0xbf, 0x02, 0xc0, 0x02, 0xc1, 0x02, 0xc2, 0x02
	.byte 0xc3, 0x02, 0xc4, 0x02, 0xc5, 0x02, 0xc6, 0x02

gUnknown_082F078C:: @ 82F078C
	.byte 0x9c, 0xfe

gUnknown_082F078E:: @ 82F078E
	.byte 0x9d, 0xfe

	.align 2
gUnknown_082F0790:: @ 82F0790
	.incbin "graphics/interface/wireless_info_screen.gbapal"

	.align 2
gUnknown_082F0990:: @ 82F0990
	.incbin "graphics/interface/wireless_info_screen.4bpp.lz"

	.align 2
gUnknown_082F0BA0:: @ 82F0BA0
	.incbin "graphics/interface/wireless_info_screen.bin.lz"

	.align 2
gUnknown_082F0D34:: @ 82F0D34
	.4byte 0x000001f8
    .4byte 0x00001081

	.align 2
gUnknown_082F0D3C:: @ 82F0D3C
	window_template 0x00, 0x03, 0x00, 0x18, 0x03, 0x0f, 0x0001
	window_template 0x00, 0x03, 0x04, 0x15, 0x0f, 0x0f, 0x0049
	window_template 0x00, 0x18, 0x04, 0x03, 0x0f, 0x0f, 0x0184
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

	.align 2
gUnknown_082F0D5C:: @ 82F0D5C
	.4byte gUnknown_085EED41
	.4byte gUnknown_085EED5F
	.4byte gUnknown_085EED6F
	.4byte gUnknown_085EED80
	.4byte gUnknown_085EED9A

	.align 2
gUnknown_082F0D70:: @ 82F0D70
	.byte 0x01, 0x01, 0x02, 0x02, 0x01, 0x02, 0x03, 0x01
	.byte 0x04, 0x04, 0x00, 0x02, 0x06, 0x03, 0x02, 0x07
	.byte 0x03, 0x02, 0x09, 0x03, 0x00, 0x0a, 0x03, 0x00
	.byte 0x0b, 0x03, 0x00, 0x0c, 0xff, 0x00, 0x0d, 0x00
	.byte 0x00, 0x10, 0x03, 0x00, 0x0f, 0x03, 0x00, 0x40
	.byte 0x02, 0x01, 0x41, 0x02, 0x02, 0x44, 0x02, 0x02
	.byte 0x45, 0x02, 0x00, 0x48, 0x02, 0x02, 0x54, 0x02
	.byte 0x01, 0x53, 0x02, 0x02, 0x51, 0x02, 0x01, 0x52
	.byte 0x02, 0x01, 0x15, 0x03, 0x02, 0x16, 0x03, 0x02
	.byte 0x17, 0x03, 0x00, 0x18, 0x03, 0x00, 0x19, 0x03
	.byte 0x00, 0x1a, 0x03, 0x00, 0x1b, 0x03, 0x00, 0x1c
	.byte 0x01, 0x02, 0x0e, 0x01, 0x02, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F0DD0:: @ 82F0DD0
	.4byte 0x000001FC

	.align 2
gUnknown_082F0DD4:: @ 82F0DD4
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0e, 0x0014
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

	.align 2
gUnknown_082F0DE4:: @ 82F0DE4
	.byte 0x01, 0x02, 0x03

	.align 2
gUnknown_082F0DE8:: @ 82F0DE8
	.2byte 0x013a, 0x013b, 0x013c, 0x013d, 0x013e, 0x013f, 0x0140, 0x0141
	.2byte 0x0142, 0x0143, 0x0144, 0x0145, 0x0146, 0x0147, 0x0148, 0x0149
	.2byte 0x014a, 0x014b, 0x014c, 0x014d

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
gUnknown_082F0E34:: @ 82F0E34
	.incbin "graphics/interface/wonder_card_1.gbapal"

	.align 2
gUnknown_082F0E54:: @ 82F0E54
	.incbin "graphics/interface/wonder_card_2.gbapal"

	.align 2
gUnknown_082F0E74:: @ 82F0E74
	.incbin "graphics/interface/wonder_card_3.gbapal"

	.align 2
gUnknown_082F0E94:: @ 82F0E94
	.incbin "graphics/interface/wonder_card_4.gbapal"

	.align 2
gUnknown_082F0EB4:: @ 82F0EB4
	.incbin "graphics/interface/wonder_card_5.gbapal"

	.align 2
gUnknown_082F0ED4:: @ 82F0ED4
	.incbin "graphics/interface/wonder_card_6.gbapal"

	.align 2
gUnknown_082F0EF4:: @ 82F0EF4
	.incbin "graphics/interface/wonder_card_7.gbapal"

	.align 2
gUnknown_082F0F14:: @ 82F0F14
	.incbin "graphics/interface/wonder_card_8.gbapal"

	.align 2
gUnknown_082F0F34:: @ 82F0F34
	.incbin "graphics/interface/wonder_card_1.4bpp.lz"

	.align 2
gUnknown_082F1030:: @ 82F1030
	.incbin "graphics/interface/wonder_card_1.bin.lz"

	.align 2
gUnknown_082F1124:: @ 82F1124
	.incbin "graphics/interface/wonder_card_2.4bpp.lz"

	.align 2
gUnknown_082F1218:: @ 82F1218
	.incbin "graphics/interface/wonder_card_2.bin.lz"

	.align 2
gUnknown_082F1300:: @ 82F1300
	.incbin "graphics/interface/wonder_card_3.4bpp.lz"

	.align 2
gUnknown_082F13D4:: @ 82F13D4
	.incbin "graphics/interface/wonder_card_3.bin.lz"
	
	.align 2
gUnknown_082F14A8:: @ 82F14A8
	.incbin "graphics/interface/wonder_card_7.4bpp.lz"

	.align 2
gUnknown_082F16DC:: @ 82F16DC
	.incbin "graphics/interface/wonder_card_7.bin.lz"
	
	.align 2
gUnknown_082F1824:: @ 82F1824
	.incbin "graphics/interface/wonder_card_8.4bpp.lz"

	.align 2
gUnknown_082F1A54:: @ 82F1A54
	.incbin "graphics/interface/wonder_card_8.bin.lz"

	.align 2
gUnknown_082F1B9C:: @ 82F1B9C
	.incbin "graphics/interface/wonder_card_shadow_1.gbapal"

	.align 2
gUnknown_082F1BBC:: @ 82F1BBC
	.incbin "graphics/interface/wonder_card_shadow_2.gbapal"

	.align 2
gUnknown_082F1BDC:: @ 82F1BDC
	.incbin "graphics/interface/wonder_card_shadow_3.gbapal"

	.align 2
gUnknown_082F1BFC:: @ 82F1BFC
	.incbin "graphics/interface/wonder_card_shadow_4.gbapal"

	.align 2
gUnknown_082F1C1C:: @ 82F1C1C
	.incbin "graphics/interface/wonder_card_shadow_5.gbapal"

	.align 2
gUnknown_082F1C3C:: @ 82F1C3C
	.incbin "graphics/interface/wonder_card_shadow_6.gbapal"

	.align 2
gUnknown_082F1C5C:: @ 82F1C5C
	.incbin "graphics/interface/wonder_card_shadow_7.gbapal"

	.align 2
gUnknown_082F1C7C:: @ 82F1C7C
	.incbin "graphics/interface/wonder_card_shadow_8.gbapal"
	
	.align 2
gUnknown_082F1C9C:: @ 82F1C9C
	.incbin "graphics/interface/wonder_card_shadow.4bpp.lz"

	.align 2
gUnknown_082F1D00:: @ 82F1D00 struct CompressedSpriteSheet
	.4byte gUnknown_082F1C9C
	.2byte 0x0100
	.2byte 0x8000

	.align 2
gUnknown_082F1D08:: @ 82F1D08 struct SpritePalette
	.4byte gUnknown_082F1B9C
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1BBC
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1BDC
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1BFC
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1C1C
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1C3C
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1C5C
	.2byte 0x8000
	
	.align 2
	.4byte gUnknown_082F1C7C
	.2byte 0x8000

	.align 2
gUnknown_082F1D48:: @ 82F1D48 struct SpriteTemplate
	.2byte 0x8000
	.2byte 0x8000
	.4byte gUnknown_08524934
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte SpriteCallbackDummy

	.align 2
gUnknown_082F1D60:: @ 82F1D60
	.4byte 0x00000001, gUnknown_082F0F34, gUnknown_082F1030, gUnknown_082F0E34
	.4byte 0x00001001, gUnknown_082F1124, gUnknown_082F1218, gUnknown_082F0E54
	.4byte 0x00002001, gUnknown_082F1300, gUnknown_082F13D4, gUnknown_082F0E74
	.4byte 0x00003001, gUnknown_082F1300, gUnknown_082F13D4, gUnknown_082F0E94
	.4byte 0x00004001, gUnknown_082F1300, gUnknown_082F13D4, gUnknown_082F0EB4
	.4byte 0x00005001, gUnknown_082F1300, gUnknown_082F13D4, gUnknown_082F0ED4
	.4byte 0x00006001, gUnknown_082F14A8, gUnknown_082F16DC, gUnknown_082F0EF4
	.4byte 0x00007001, gUnknown_082F1824, gUnknown_082F1A54, gUnknown_082F0F14

gUnknown_082F1DE0:: @ 82F1DE0
	.incbin "baserom.gba", 0x2f1de0, 0x8

gUnknown_082F1DE8:: @ 82F1DE8
	.incbin "baserom.gba", 0x2f1de8, 0x10

gUnknown_082F1DF8:: @ 82F1DF8
	.incbin "baserom.gba", 0x2f1df8, 0x6d0

gUnknown_082F24C8:: @ 82F24C8
	.incbin "baserom.gba", 0x2f24c8, 0x80

gUnknown_082F2548:: @ 82F2548
	.incbin "baserom.gba", 0x2f2548, 0x14

gUnknown_082F255C:: @ 82F255C
	.incbin "baserom.gba", 0x2f255c, 0x3c

gUnknown_082F2598:: @ 82F2598
	.incbin "baserom.gba", 0x2f2598, 0x3f4

gUnknown_082F298C:: @ 82F298C
	.incbin "baserom.gba", 0x2f298c, 0x60

gUnknown_082F29EC:: @ 82F29EC
	.incbin "baserom.gba", 0x2f29ec, 0x90

gUnknown_082F2A7C:: @ 82F2A7C
	.incbin "baserom.gba", 0x2f2a7c, 0x28

gUnknown_082F2AA4:: @ 82F2AA4
	.incbin "baserom.gba", 0x2f2aa4, 0x4

gUnknown_082F2AA8:: @ 82F2AA8
	.incbin "baserom.gba", 0x2f2aa8, 0x100

gUnknown_082F2BA8:: @ 82F2BA8
	.incbin "baserom.gba", 0x2f2ba8, 0x78

gUnknown_082F2C20:: @ 82F2C20
	.incbin "baserom.gba", 0x2f2c20, 0x20

gUnknown_082F2C40:: @ 82F2C40
	.incbin "baserom.gba", 0x2f2c40, 0x20

gUnknown_082F2C60:: @ 82F2C60
	.incbin "baserom.gba", 0x2f2c60, 0x10

gUnknown_082F2C70:: @ 82F2C70
	.incbin "baserom.gba", 0x2f2c70, 0x28

gUnknown_082F2C98:: @ 82F2C98
	.incbin "baserom.gba", 0x2f2c98, 0xa8

gUnknown_082F2D40:: @ 82F2D40
	.incbin "baserom.gba", 0x2f2d40, 0x84

gUnknown_082F2DC4:: @ 82F2DC4
	.incbin "baserom.gba", 0x2f2dc4, 0x4

gUnknown_082F2DC8:: @ 82F2DC8
	.incbin "baserom.gba", 0x2f2dc8, 0x2a

gUnknown_082F2DF2:: @ 82F2DF2
	.incbin "baserom.gba", 0x2f2df2, 0x342

gUnknown_082F3134:: @ 82F3134
	.incbin "baserom.gba", 0x2f3134, 0x28

gUnknown_082F315C:: @ 82F315C
	.incbin "baserom.gba", 0x2f315c, 0x40

gUnknown_082F319C:: @ 82F319C
	.incbin "baserom.gba", 0x2f319c, 0x20

gUnknown_082F31BC:: @ 82F31BC
	.incbin "baserom.gba", 0x2f31bc, 0x18

gUnknown_082F31D4:: @ 82F31D4
	.incbin "baserom.gba", 0x2f31d4, 0x58

gUnknown_082F322C:: @ 82F322C
	.incbin "baserom.gba", 0x2f322c, 0x18

gUnknown_082F3244:: @ 82F3244
	.incbin "baserom.gba", 0x2f3244, 0x18

gUnknown_082F325C:: @ 82F325C
	.incbin "baserom.gba", 0x2f325c, 0x8

gUnknown_082F3264:: @ 82F3264
	.incbin "baserom.gba", 0x2f3264, 0x8

gUnknown_082F326C:: @ 82F326C
	.incbin "baserom.gba", 0x2f326c, 0x24

gUnknown_082F3290:: @ 82F3290
	.incbin "baserom.gba", 0x2f3290, 0x14

gUnknown_082F32A4:: @ 82F32A4
	.incbin "baserom.gba", 0x2f32a4, 0x24

gUnknown_082F32C8:: @ 82F32C8
	.incbin "baserom.gba", 0x2f32c8, 0x4

gUnknown_082F32CC:: @ 82F32CC
	.incbin "baserom.gba", 0x2f32cc, 0xc

gUnknown_082F32D8:: @ 82F32D8
	.incbin "baserom.gba", 0x2f32d8, 0x3

gUnknown_082F32DB:: @ 82F32DB
	.incbin "baserom.gba", 0x2f32db, 0x3

gUnknown_082F32DE:: @ 82F32DE
	.incbin "baserom.gba", 0x2f32de, 0x3

gUnknown_082F32E1:: @ 82F32E1
	.incbin "baserom.gba", 0x2f32e1, 0x6

gUnknown_082F32E7:: @ 82F32E7
	.incbin "baserom.gba", 0x2f32e7, 0x5

gUnknown_082F32EC:: @ 82F32EC
	.incbin "baserom.gba", 0x2f32ec, 0x8

gUnknown_082F32F4:: @ 82F32F4
	.incbin "baserom.gba", 0x2f32f4, 0x50

gUnknown_082F3344:: @ 82F3344
	.incbin "baserom.gba", 0x2f3344, 0x8

gUnknown_082F334C:: @ 82F334C
	.incbin "baserom.gba", 0x2f334c, 0x940

gUnknown_082F3C8C:: @ 82F3C8C
	.incbin "baserom.gba", 0x2f3c8c, 0x130

gUnknown_082F3DBC:: @ 82F3DBC
	.incbin "baserom.gba", 0x2f3dbc, 0x198

gUnknown_082F3F54:: @ 82F3F54
	.incbin "baserom.gba", 0x2f3f54, 0x228

gUnknown_082F417C:: @ 82F417C
	.incbin "baserom.gba", 0x2f417c, 0x14

gUnknown_082F4190:: @ 82F4190
	.incbin "baserom.gba", 0x2f4190, 0x3c

gUnknown_082F41CC:: @ 82F41CC
	.incbin "baserom.gba", 0x2f41cc, 0x1

gUnknown_082F41CD:: @ 82F41CD
	.incbin "baserom.gba", 0x2f41cd, 0x5

gUnknown_082F41D2:: @ 82F41D2
	.incbin "baserom.gba", 0x2f41d2, 0x1

gUnknown_082F41D3:: @ 82F41D3
	.incbin "baserom.gba", 0x2f41d3, 0x15

gUnknown_082F41E8:: @ 82F41E8
	.incbin "baserom.gba", 0x2f41e8, 0xc

gUnknown_082F41F4:: @ 82F41F4
	.incbin "baserom.gba", 0x2f41f4, 0x28

gUnknown_082F421C:: @ 82F421C
	.incbin "baserom.gba", 0x2f421c, 0xf0

gUnknown_082F430C:: @ 82F430C
	.incbin "baserom.gba", 0x2f430c, 0x18

gUnknown_082F4324:: @ 82F4324
	.incbin "baserom.gba", 0x2f4324, 0x18

gUnknown_082F433C:: @ 82F433C
	.incbin "baserom.gba", 0x2f433c, 0x18

gUnknown_082F4354:: @ 82F4354
	.incbin "baserom.gba", 0x2f4354, 0x18

gUnknown_082F436C:: @ 82F436C
	.incbin "baserom.gba", 0x2f436c, 0x18

gUnknown_082F4384:: @ 82F4384
	.incbin "baserom.gba", 0x2f4384, 0x30

gUnknown_082F43B4:: @ 82F43B4
	.incbin "baserom.gba", 0x2f43b4, 0x18

gUnknown_082F43CC:: @ 82F43CC
	.incbin "baserom.gba", 0x2f43cc, 0x68

gUnknown_082F4434:: @ 82F4434
	.incbin "baserom.gba", 0x2f4434, 0x10

gUnknown_082F4444:: @ 82F4444
	.incbin "baserom.gba", 0x2f4444, 0x4

gUnknown_082F4448:: @ 82F4448
	.incbin "baserom.gba", 0x2f4448, 0x54

gUnknown_082F449C:: @ 82F449C
	.incbin "baserom.gba", 0x2f449c, 0x113

gUnknown_082F45AF:: @ 82F45AF
	.incbin "baserom.gba", 0x2f45af, 0x4b

gUnknown_082F45FA:: @ 82F45FA
	.incbin "baserom.gba", 0x2f45fa, 0x4e

gUnknown_082F4648:: @ 82F4648
	.incbin "baserom.gba", 0x2f4648, 0x37

gUnknown_082F467F:: @ 82F467F
	.incbin "baserom.gba", 0x2f467f, 0x3409

gUnknown_082F7A88:: @ 82F7A88
	.incbin "baserom.gba", 0x2f7a88, 0xc

gUnknown_082F7A94:: @ 82F7A94
	.incbin "baserom.gba", 0x2f7a94, 0x8

gUnknown_082F7A9C:: @ 82F7A9C
	.incbin "baserom.gba", 0x2f7a9c, 0x8

gUnknown_082F7AA4:: @ 82F7AA4
	.incbin "baserom.gba", 0x2f7aa4, 0x20

gUnknown_082F7AC4:: @ 82F7AC4
	.incbin "baserom.gba", 0x2f7ac4, 0x30

gUnknown_082F7AF4:: @ 82F7AF4
	.incbin "baserom.gba", 0x2f7af4, 0x30

gUnknown_082F7B24:: @ 82F7B24
	.incbin "baserom.gba", 0x2f7b24, 0x8

gUnknown_082F7B2C:: @ 82F7B2C
	.incbin "baserom.gba", 0x2f7b2c, 0x8

gUnknown_082F7B34:: @ 82F7B34
	.incbin "baserom.gba", 0x2f7b34, 0xc

gUnknown_082F7B40:: @ 82F7B40
	.incbin "baserom.gba", 0x2f7b40, 0x4

gUnknown_082F7B44:: @ 82F7B44
	.incbin "baserom.gba", 0x2f7b44, 0x6

gUnknown_082F7B4A:: @ 82F7B4A
	.incbin "baserom.gba", 0x2f7b4a, 0x6

gUnknown_082F7B50:: @ 82F7B50
	.incbin "baserom.gba", 0x2f7b50, 0x40

gUnknown_082F7B90:: @ 82F7B90
	.incbin "baserom.gba", 0x2f7b90, 0x14

gUnknown_082F7BA4:: @ 82F7BA4
	.incbin "baserom.gba", 0x2f7ba4, 0x18

gUnknown_082F7BBC:: @ 82F7BBC
	.incbin "baserom.gba", 0x2f7bbc, 0x10

gUnknown_082F7BCC:: @ 82F7BCC
	.incbin "baserom.gba", 0x2f7bcc, 0x8

gUnknown_082F7BD4:: @ 82F7BD4
	.incbin "baserom.gba", 0x2f7bd4, 0x10

gUnknown_082F7BE4:: @ 82F7BE4
	.incbin "baserom.gba", 0x2f7be4, 0x8

gUnknown_082F7BEC:: @ 82F7BEC
	.incbin "baserom.gba", 0x2f7bec, 0x204

gUnknown_082F7DF0:: @ 82F7DF0
	.incbin "baserom.gba", 0x2f7df0, 0xc0

gUnknown_082F7EB0:: @ 82F7EB0
	.incbin "baserom.gba", 0x2f7eb0, 0x1d4

gUnknown_082F8084:: @ 82F8084
	.incbin "baserom.gba", 0x2f8084, 0x890

gUnknown_082F8914:: @ 82F8914
	.incbin "baserom.gba", 0x2f8914, 0xdcc

gUnknown_082F96E0:: @ 82F96E0
	.incbin "baserom.gba", 0x2f96e0, 0x94

gUnknown_082F9774:: @ 82F9774
	.incbin "baserom.gba", 0x2f9774, 0x148

gUnknown_082F98BC:: @ 82F98BC
	.incbin "baserom.gba", 0x2f98bc, 0x121c

gUnknown_082FAAD8:: @ 82FAAD8
	.incbin "baserom.gba", 0x2faad8, 0x26c

gUnknown_082FAD44:: @ 82FAD44
	.incbin "baserom.gba", 0x2fad44, 0x250

gUnknown_082FAF94:: @ 82FAF94
	.incbin "baserom.gba", 0x2faf94, 0x24c

gUnknown_082FB1E0:: @ 82FB1E0
	.incbin "baserom.gba", 0x2fb1e0, 0x48

gUnknown_082FB228:: @ 82FB228
	.incbin "baserom.gba", 0x2fb228, 0xb0

gUnknown_082FB2D8:: @ 82FB2D8
	.incbin "baserom.gba", 0x2fb2d8, 0x8

gUnknown_082FB2E0:: @ 82FB2E0
	.incbin "baserom.gba", 0x2fb2e0, 0x8

gUnknown_082FB2E8:: @ 82FB2E8
	.incbin "baserom.gba", 0x2fb2e8, 0x8

gUnknown_082FB2F0:: @ 82FB2F0
	.incbin "baserom.gba", 0x2fb2f0, 0x24

gUnknown_082FB314:: @ 82FB314
	.incbin "baserom.gba", 0x2fb314, 0x8

gUnknown_082FB31C:: @ 82FB31C
	.incbin "baserom.gba", 0x2fb31c, 0x8

gUnknown_082FB324:: @ 82FB324
	.incbin "baserom.gba", 0x2fb324, 0x18

gUnknown_082FB33C:: @ 82FB33C
	.incbin "baserom.gba", 0x2fb33c, 0x18

gUnknown_082FB354:: @ 82FB354
	.incbin "baserom.gba", 0x2fb354, 0x2

gUnknown_082FB356:: @ 82FB356
	.incbin "baserom.gba", 0x2fb356, 0xa

gUnknown_082FB360:: @ 82FB360
	.incbin "baserom.gba", 0x2fb360, 0x8

gUnknown_082FB368:: @ 82FB368
	.incbin "baserom.gba", 0x2fb368, 0x18

gUnknown_082FB380:: @ 82FB380
	.incbin "baserom.gba", 0x2fb380, 0x3

gUnknown_082FB383:: @ 82FB383
	.incbin "baserom.gba", 0x2fb383, 0x45

gUnknown_082FB3C8:: @ 82FB3C8
	.incbin "baserom.gba", 0x2fb3c8, 0x14

gUnknown_082FB3DC:: @ 82FB3DC
	.incbin "baserom.gba", 0x2fb3dc, 0x14

gUnknown_082FB3F0:: @ 82FB3F0
	.incbin "baserom.gba", 0x2fb3f0, 0x8

gUnknown_082FB3F8:: @ 82FB3F8
	.incbin "baserom.gba", 0x2fb3f8, 0xa

gUnknown_082FB402:: @ 82FB402
	.incbin "baserom.gba", 0x2fb402, 0xa

gUnknown_082FB40C:: @ 82FB40C
	.incbin "baserom.gba", 0x2fb40c, 0x50

gUnknown_082FB45C:: @ 82FB45C
	.incbin "baserom.gba", 0x2fb45c, 0x8

gUnknown_082FB464:: @ 82FB464
	.incbin "baserom.gba", 0x2fb464, 0x190

gUnknown_082FB5F4:: @ 82FB5F4
	.incbin "baserom.gba", 0x2fb5f4, 0x24

gUnknown_082FB618:: @ 82FB618
	.incbin "baserom.gba", 0x2fb618, 0x24

gUnknown_082FB63C:: @ 82FB63C
	.incbin "baserom.gba", 0x2fb63c, 0x10

gUnknown_082FB64C:: @ 82FB64C
	.incbin "baserom.gba", 0x2fb64c, 0x8

gUnknown_082FB654:: @ 82FB654
	.incbin "baserom.gba", 0x2fb654, 0x8

gUnknown_082FB65C:: @ 82FB65C
	.incbin "baserom.gba", 0x2fb65c, 0x90

gUnknown_082FB6EC:: @ 82FB6EC
	.incbin "baserom.gba", 0x2fb6ec, 0x18

gUnknown_082FB704:: @ 82FB704
	.incbin "baserom.gba", 0x2fb704, 0x10

gUnknown_082FB714:: @ 82FB714
	.incbin "baserom.gba", 0x2fb714, 0x6f4

gUnknown_082FBE08:: @ 82FBE08
	.incbin "baserom.gba", 0x2fbe08, 0x28

gUnknown_082FBE30:: @ 82FBE30
	.incbin "baserom.gba", 0x2fbe30, 0x10

gUnknown_082FBE40:: @ 82FBE40
	.incbin "baserom.gba", 0x2fbe40, 0x18

gUnknown_082FBE58:: @ 82FBE58
	.incbin "baserom.gba", 0x2fbe58, 0x50

gUnknown_082FBEA8:: @ 82FBEA8
	.incbin "baserom.gba", 0x2fbea8, 0x10

gUnknown_082FBEB8:: @ 82FBEB8
	.incbin "baserom.gba", 0x2fbeb8, 0x154

gUnknown_082FC00C:: @ 82FC00C
	.incbin "baserom.gba", 0x2fc00c, 0x18

gUnknown_082FC024:: @ 82FC024
	.incbin "baserom.gba", 0x2fc024, 0x20

gUnknown_082FC044:: @ 82FC044
	.incbin "baserom.gba", 0x2fc044, 0x20

gUnknown_082FC064:: @ 82FC064
	.incbin "baserom.gba", 0x2fc064, 0x22c

gUnknown_082FC290:: @ 82FC290
	.incbin "baserom.gba", 0x2fc290, 0x1b0

gUnknown_082FC440:: @ 82FC440
	.incbin "baserom.gba", 0x2fc440, 0x20

gUnknown_082FC460:: @ 82FC460
	.incbin "baserom.gba", 0x2fc460, 0x950

gUnknown_082FCDB0:: @ 82FCDB0
	.incbin "baserom.gba", 0x2fcdb0, 0x3b8

gUnknown_082FD168:: @ 82FD168
	.incbin "baserom.gba", 0x2fd168, 0x20

gUnknown_082FD188:: @ 82FD188
	.incbin "baserom.gba", 0x2fd188, 0xab0

gUnknown_082FDC38:: @ 82FDC38
	.incbin "baserom.gba", 0x2fdc38, 0x52c

gUnknown_082FE164:: @ 82FE164
	.incbin "baserom.gba", 0x2fe164, 0x10

gUnknown_082FE174:: @ 82FE174
	.incbin "baserom.gba", 0x2fe174, 0x18

gUnknown_082FE18C:: @ 82FE18C
	.incbin "baserom.gba", 0x2fe18c, 0x50

gUnknown_082FE1DC:: @ 82FE1DC
	.incbin "baserom.gba", 0x2fe1dc, 0x3

gUnknown_082FE1DF:: @ 82FE1DF
	.incbin "baserom.gba", 0x2fe1df, 0xd

gUnknown_082FE1EC:: @ 82FE1EC
	.incbin "baserom.gba", 0x2fe1ec, 0x8

gUnknown_082FE1F4:: @ 82FE1F4
	.incbin "baserom.gba", 0x2fe1f4, 0x40

gUnknown_082FE234:: @ 82FE234
	.incbin "baserom.gba", 0x2fe234, 0x2c

gUnknown_082FE260:: @ 82FE260
	.incbin "baserom.gba", 0x2fe260, 0x10

gUnknown_082FE270:: @ 82FE270
	.incbin "baserom.gba", 0x2fe270, 0x8

gUnknown_082FE278:: @ 82FE278
	.incbin "baserom.gba", 0x2fe278, 0x450

gUnknown_082FE6C8:: @ 82FE6C8
	.incbin "baserom.gba", 0x2fe6c8, 0x10

gUnknown_082FE6D8:: @ 82FE6D8
	.incbin "baserom.gba", 0x2fe6d8, 0x58

gUnknown_082FE730:: @ 82FE730
	.incbin "baserom.gba", 0x2fe730, 0x18

gUnknown_082FE748:: @ 82FE748
	.incbin "baserom.gba", 0x2fe748, 0x484

gUnknown_082FEBCC:: @ 82FEBCC
	.incbin "baserom.gba", 0x2febcc, 0x8

gUnknown_082FEBD4:: @ 82FEBD4
	.incbin "baserom.gba", 0x2febd4, 0xbc

gUnknown_082FEC90:: @ 82FEC90
	.incbin "baserom.gba", 0x2fec90, 0x18

gUnknown_082FECA8:: @ 82FECA8
	.incbin "baserom.gba", 0x2feca8, 0x18

