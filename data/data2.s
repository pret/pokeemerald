; the second big chunk of data

	.align 2, 0

gUnknown_82E9530: ; 82E9530
	.byte 3

gUnknown_82E9531: ; 82E9531
	.byte 2

	.align 2, 0

; compile time
	.asciz "2005 02 21 11:10"

	.align 2, 0

gRomInterruptTable: ; 82E9548
	.4byte irq_vcount+1
	.4byte irq_serial+1
	.4byte irq_timer3+1
	.4byte irq_hblank+1
	.4byte irq_vblank+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1

gBgConfigZeroValue: ; 82E9580
	.4byte 0

gDummyWindowTemplate: ; 82E9584
	window_template -1, 0, 0, 0, 0, 0, 0

gFontHalfRowOffsets: ; 82E958C
	.byte 0x00,0x01,0x02,0x00,0x03,0x04,0x05,0x03,0x06,0x07,0x08,0x06,0x00,0x01,0x02,0x00
	.byte 0x09,0x0a,0x0b,0x09,0x0c,0x0d,0x0e,0x0c,0x0f,0x10,0x11,0x0f,0x09,0x0a,0x0b,0x09
	.byte 0x12,0x13,0x14,0x12,0x15,0x16,0x17,0x15,0x18,0x19,0x1a,0x18,0x12,0x13,0x14,0x12
	.byte 0x00,0x01,0x02,0x00,0x03,0x04,0x05,0x03,0x06,0x07,0x08,0x06,0x00,0x01,0x02,0x00
	.byte 0x1b,0x1c,0x1d,0x1b,0x1e,0x1f,0x20,0x1e,0x21,0x22,0x23,0x21,0x1b,0x1c,0x1d,0x1b
	.byte 0x24,0x25,0x26,0x24,0x27,0x28,0x29,0x27,0x2a,0x2b,0x2c,0x2a,0x24,0x25,0x26,0x24
	.byte 0x2d,0x2e,0x2f,0x2d,0x30,0x31,0x32,0x30,0x33,0x34,0x35,0x33,0x2d,0x2e,0x2f,0x2d
	.byte 0x1b,0x1c,0x1d,0x1b,0x1e,0x1f,0x20,0x1e,0x21,0x22,0x23,0x21,0x1b,0x1c,0x1d,0x1b
	.byte 0x36,0x37,0x38,0x36,0x39,0x3a,0x3b,0x39,0x3c,0x3d,0x3e,0x3c,0x36,0x37,0x38,0x36
	.byte 0x3f,0x40,0x41,0x3f,0x42,0x43,0x44,0x42,0x45,0x46,0x47,0x45,0x3f,0x40,0x41,0x3f
	.byte 0x48,0x49,0x4a,0x48,0x4b,0x4c,0x4d,0x4b,0x4e,0x4f,0x50,0x4e,0x48,0x49,0x4a,0x48
	.byte 0x36,0x37,0x38,0x36,0x39,0x3a,0x3b,0x39,0x3c,0x3d,0x3e,0x3c,0x36,0x37,0x38,0x36
	.byte 0x00,0x01,0x02,0x00,0x03,0x04,0x05,0x03,0x06,0x07,0x08,0x06,0x00,0x01,0x02,0x00
	.byte 0x09,0x0a,0x0b,0x09,0x0c,0x0d,0x0e,0x0c,0x0f,0x10,0x11,0x0f,0x09,0x0a,0x0b,0x09
	.byte 0x12,0x13,0x14,0x12,0x15,0x16,0x17,0x15,0x18,0x19,0x1a,0x18,0x12,0x13,0x14,0x12
	.byte 0x00,0x01,0x02,0x00,0x03,0x04,0x05,0x03,0x06,0x07,0x08,0x06,0x00,0x01,0x02,0x00

gDownArrowTiles: ; 82E968C
	.incbin "base_emerald.gba", 0x2e968c, 0xc0

gDarkDownArrowTiles: ; 82E974C
	.incbin "base_emerald.gba", 0x2e974c, 0xc0

; Seemingly unreferenced data. It contains some kind of arrow graphics.
	.incbin "base_emerald.gba", 0x2e980c, 0x500

gDownArrowYCoords: ; 82E9D0C
	.byte 0, 1, 2, 1

gWindowVerticalScrollSpeeds: ; 82E9D10
	.byte 1, 2, 4, 0

gGlyphWidthFuncs: ; 82E9D14
	glyph_width_func 0, GetGlyphWidthFont0+1
	glyph_width_func 1, GetGlyphWidthFont1+1
	glyph_width_func 2, GetGlyphWidthFont2+1
	glyph_width_func 3, GetGlyphWidthFont2+1
	glyph_width_func 4, GetGlyphWidthFont2+1
	glyph_width_func 5, GetGlyphWidthFont2+1
	glyph_width_func 6, GetGlyphWidthFont6+1
	glyph_width_func 7, GetGlyphWidthFont7+1
	glyph_width_func 8, GetGlyphWidthFont8+1

gKeypadIcons: ; 82E9D5C
	keypad_icon  0x0,  8, 12
	keypad_icon  0x1,  8, 12
	keypad_icon  0x2, 16, 12
	keypad_icon  0x4, 16, 12
	keypad_icon  0x6, 24, 12
	keypad_icon  0x9, 24, 12
	keypad_icon  0xC,  8, 12
	keypad_icon  0xD,  8, 12
	keypad_icon  0xE,  8, 12
	keypad_icon  0xF,  8, 12
	keypad_icon 0x20,  8, 12
	keypad_icon 0x21,  8, 12
	keypad_icon 0x22,  8, 12

gKeypadIconTiles: ; 82E9D90
	.incbin "base_emerald.gba", 0x2e9d90, 0x800

gFontInfos: ; 82EA590
	font_info Font0Func+1, 5, 12, 0, 0, 2,  3, 1
	font_info Font1Func+1, 6, 16, 0, 0, 2,  3, 1
	font_info Font2Func+1, 6, 14, 0, 0, 2,  3, 1
	font_info Font3Func+1, 6, 14, 0, 0, 2,  3, 1
	font_info Font4Func+1, 6, 14, 0, 0, 2,  3, 1
	font_info Font5Func+1, 6, 14, 0, 0, 2,  3, 1
	font_info Font6Func+1, 8, 16, 0, 8, 2,  3, 1
	font_info Font7Func+1, 5, 16, 0, 0, 2,  3, 1
	font_info Font8Func+1, 5,  8, 0, 0, 2,  3, 1
	font_info           0, 8,  8, 0, 0, 1, 15, 2

gMenuCursorDimensions: ; 82EA608
	.byte 8, 12
	.byte 8, 15
	.byte 8, 14
	.byte 8, 14
	.byte 8, 14
	.byte 8, 14
	.byte 8, 16
	.byte 8, 15
	.byte 8,  8
	.byte 0,  0 

gFont9JapaneseGlyphs: ; 82EA61C
	.incbin "base_emerald.gba", 0x2ea61c, 0x2000

; Unreferenced data. This also comes before the gpu_bg.s data in Ruby and seems
; to be unreferenced there too.
	.incbin "base_emerald.gba", 0x2ec61c, 0x18

gUnknown_082EC634: ; 82EC634
	.incbin "base_emerald.gba", 0x2ec634, 0x18

gUnknown_082EC64C: ; 82EC64C
	.incbin "base_emerald.gba", 0x2ec64c, 0x44

gUnknown_082EC690: ; 82EC690
	.incbin "base_emerald.gba", 0x2ec690, 0xc

gUnknown_082EC69C: ; 82EC69C
	.incbin "base_emerald.gba", 0x2ec69c, 0xc

gUnknown_082EC6A8: ; 82EC6A8
	.incbin "base_emerald.gba", 0x2ec6a8, 0x4

gUnknown_082EC6AC: ; 82EC6AC
	.incbin "base_emerald.gba", 0x2ec6ac, 0x18

gUnknown_082EC6C4: ; 82EC6C4
	.incbin "base_emerald.gba", 0x2ec6c4, 0x8

gUnknown_082EC6CC: ; 82EC6CC
	.incbin "base_emerald.gba", 0x2ec6cc, 0x8

gUnknown_082EC6D4: ; 82EC6D4
	.incbin "base_emerald.gba", 0x2ec6d4, 0x10

gUnknown_082EC6E4: ; 82EC6E4
	.incbin "base_emerald.gba", 0x2ec6e4, 0x10

gUnknown_082EC6F4: ; 82EC6F4
	.incbin "base_emerald.gba", 0x2ec6f4, 0x60

gUnknown_082EC754: ; 82EC754
	.incbin "base_emerald.gba", 0x2ec754, 0x70

gUnknown_82EC7C4: ; 82EC7C4
	.2byte 0x0100
	.2byte 0x0200
	.2byte 0x0400
	.2byte 0x0800

gUnknown_82EC7CC: ; 82EC7CC
	.2byte 0x0001
	.2byte 0x0002
	.2byte 0x0004
	.2byte 0x0008

gUnknown_082EC7D4: ; 82EC7D4
	.incbin "base_emerald.gba", 0x2ec7d4, 0x10

gUnknown_082EC7E4: ; 82EC7E4
	.incbin "base_emerald.gba", 0x2ec7e4, 0x28

gUnknown_082EC80C: ; 82EC80C
	.incbin "base_emerald.gba", 0x2ec80c, 0x4

gUnknown_082EC810: ; 82EC810
	.incbin "base_emerald.gba", 0x2ec810, 0x8

gUnknown_082EC818: ; 82EC818
	.incbin "base_emerald.gba", 0x2ec818, 0x38

gUnknown_082EC850: ; 82EC850
	.incbin "base_emerald.gba", 0x2ec850, 0x1c

gUnknown_082EC86C: ; 82EC86C
	.incbin "base_emerald.gba", 0x2ec86c, 0x20

gUnknown_082EC88C: ; 82EC88C
	.incbin "base_emerald.gba", 0x2ec88c, 0x4a8

gUnknown_082ECD34: ; 82ECD34
	.incbin "base_emerald.gba", 0x2ecd34, 0x1ec

gUnknown_082ECF20: ; 82ECF20
	.incbin "base_emerald.gba", 0x2ecf20, 0x20

gUnknown_082ECF40: ; 82ECF40
	.incbin "base_emerald.gba", 0x2ecf40, 0x228

gUnknown_082ED168: ; 82ED168
	.incbin "base_emerald.gba", 0x2ed168, 0x40

gUnknown_082ED1A8: ; 82ED1A8
	.incbin "base_emerald.gba", 0x2ed1a8, 0x28

gUnknown_082ED1D0: ; 82ED1D0
	.incbin "base_emerald.gba", 0x2ed1d0, 0x4

gUnknown_082ED1D4: ; 82ED1D4
	.incbin "base_emerald.gba", 0x2ed1d4, 0x10

gUnknown_082ED1E4: ; 82ED1E4
	.incbin "base_emerald.gba", 0x2ed1e4, 0x18

gUnknown_082ED1FC: ; 82ED1FC
	.incbin "base_emerald.gba", 0x2ed1fc, 0x8

gUnknown_082ED204: ; 82ED204
	.incbin "base_emerald.gba", 0x2ed204, 0x20

gUnknown_082ED224: ; 82ED224
	.incbin "base_emerald.gba", 0x2ed224, 0x14c

gUnknown_082ED370: ; 82ED370
	.incbin "base_emerald.gba", 0x2ed370, 0x100

gUnknown_082ED470: ; 82ED470
	.incbin "base_emerald.gba", 0x2ed470, 0x100

gUnknown_082ED570: ; 82ED570
	.incbin "base_emerald.gba", 0x2ed570, 0x70

gUnknown_082ED5E0: ; 82ED5E0
	.incbin "base_emerald.gba", 0x2ed5e0, 0x8

gUnknown_082ED5E8: ; 82ED5E8
	.incbin "base_emerald.gba", 0x2ed5e8, 0x8

gUnknown_082ED5F0: ; 82ED5F0
	.incbin "base_emerald.gba", 0x2ed5f0, 0x18

gUnknown_082ED608: ; 82ED608
	.incbin "base_emerald.gba", 0x2ed608, 0x18

gUnknown_082ED620: ; 82ED620
	.incbin "base_emerald.gba", 0x2ed620, 0x8

gUnknown_082ED628: ; 82ED628
	.incbin "base_emerald.gba", 0x2ed628, 0x64

gUnknown_082ED68C: ; 82ED68C
	.incbin "base_emerald.gba", 0x2ed68c, 0x9

gUnknown_082ED695: ; 82ED695
	.incbin "base_emerald.gba", 0x2ed695, 0x10

gUnknown_082ED6A5: ; 82ED6A5
	.incbin "base_emerald.gba", 0x2ed6a5, 0x13

gUnknown_082ED6B8: ; 82ED6B8
	.incbin "base_emerald.gba", 0x2ed6b8, 0x28

gUnknown_082ED6E0: ; 82ED6E0
	.incbin "base_emerald.gba", 0x2ed6e0, 0x100

gUnknown_082ED7E0: ; 82ED7E0
	.incbin "base_emerald.gba", 0x2ed7e0, 0xc

gUnknown_082ED7EC: ; 82ED7EC
	.incbin "base_emerald.gba", 0x2ed7ec, 0x10

gUnknown_082ED7FC: ; 82ED7FC
	.incbin "base_emerald.gba", 0x2ed7fc, 0x18

gUnknown_082ED814: ; 82ED814
	.incbin "base_emerald.gba", 0x2ed814, 0x18

gUnknown_082ED82C: ; 82ED82C
	.incbin "base_emerald.gba", 0x2ed82c, 0x1f

gUnknown_082ED84B: ; 82ED84B
	.incbin "base_emerald.gba", 0x2ed84b, 0x10

gUnknown_082ED85B: ; 82ED85B
	.incbin "base_emerald.gba", 0x2ed85b, 0xd

gUnknown_082ED868: ; 82ED868
	.incbin "base_emerald.gba", 0x2ed868, 0x60

gUnknown_082ED8C8: ; 82ED8C8
	.incbin "base_emerald.gba", 0x2ed8c8, 0x4

gUnknown_082ED8CC: ; 82ED8CC
	.incbin "base_emerald.gba", 0x2ed8cc, 0x4

gUnknown_082ED8D0: ; 82ED8D0
	.incbin "base_emerald.gba", 0x2ed8d0, 0x28

gUnknown_082ED8F8: ; 82ED8F8
	.incbin "base_emerald.gba", 0x2ed8f8, 0x68

gUnknown_082ED960: ; 82ED960
	.incbin "base_emerald.gba", 0x2ed960, 0x30

gUnknown_082ED990: ; 82ED990
	.incbin "base_emerald.gba", 0x2ed990, 0x1d0

gUnknown_082EDB60: ; 82EDB60
	.incbin "base_emerald.gba", 0x2edb60, 0x64

gUnknown_082EDBC4: ; 82EDBC4
	.incbin "base_emerald.gba", 0x2edbc4, 0x24

gUnknown_082EDBE8: ; 82EDBE8
	.incbin "base_emerald.gba", 0x2edbe8, 0x24

gUnknown_082EDC0C: ; 82EDC0C
	.incbin "base_emerald.gba", 0x2edc0c, 0x28

gUnknown_082EDC34: ; 82EDC34
	.incbin "base_emerald.gba", 0x2edc34, 0x28

gUnknown_082EDC5C: ; 82EDC5C
	.incbin "base_emerald.gba", 0x2edc5c, 0x1c

gUnknown_082EDC78: ; 82EDC78
	.incbin "base_emerald.gba", 0x2edc78, 0x24

gUnknown_082EDC9C: ; 82EDC9C
	.incbin "base_emerald.gba", 0x2edc9c, 0xb4

gUnknown_082EDD50: ; 82EDD50
	.incbin "base_emerald.gba", 0x2edd50, 0x8

gUnknown_082EDD58: ; 82EDD58
	.incbin "base_emerald.gba", 0x2edd58, 0x6c

gUnknown_082EDDC4: ; 82EDDC4
	.incbin "base_emerald.gba", 0x2eddc4, 0x30

gUnknown_082EDDF4: ; 82EDDF4
	.incbin "base_emerald.gba", 0x2eddf4, 0x18

gUnknown_082EDE0C: ; 82EDE0C
	.incbin "base_emerald.gba", 0x2ede0c, 0x3c

gUnknown_082EDE48: ; 82EDE48
	.incbin "base_emerald.gba", 0x2ede48, 0x1c

gUnknown_082EDE64: ; 82EDE64
	.incbin "base_emerald.gba", 0x2ede64, 0x38

gUnknown_082EDE9C: ; 82EDE9C
	.incbin "base_emerald.gba", 0x2ede9c, 0x28

gUnknown_082EDEC4: ; 82EDEC4
	.incbin "base_emerald.gba", 0x2edec4, 0x40

gUnknown_082EDF04: ; 82EDF04
	.incbin "base_emerald.gba", 0x2edf04, 0x3c

gUnknown_082EDF40: ; 82EDF40
	.incbin "base_emerald.gba", 0x2edf40, 0x40

gUnknown_082EDF80: ; 82EDF80
	.incbin "base_emerald.gba", 0x2edf80, 0x84

gUnknown_082EE004: ; 82EE004
	.incbin "base_emerald.gba", 0x2ee004, 0x178

gUnknown_082EE17C: ; 82EE17C
	.incbin "base_emerald.gba", 0x2ee17c, 0xd0

gUnknown_082EE24C: ; 82EE24C
	.incbin "base_emerald.gba", 0x2ee24c, 0xd8

gUnknown_082EE324: ; 82EE324
	.incbin "base_emerald.gba", 0x2ee324, 0x54

gUnknown_082EE378: ; 82EE378
	.incbin "base_emerald.gba", 0x2ee378, 0x8

gUnknown_082EE380: ; 82EE380
	.incbin "base_emerald.gba", 0x2ee380, 0x5c

gUnknown_082EE3DC: ; 82EE3DC
	.incbin "base_emerald.gba", 0x2ee3dc, 0x54

gUnknown_082EE430: ; 82EE430
	.incbin "base_emerald.gba", 0x2ee430, 0x4c

gUnknown_082EE47C: ; 82EE47C
	.incbin "base_emerald.gba", 0x2ee47c, 0x74

gUnknown_082EE4F0: ; 82EE4F0
	.incbin "base_emerald.gba", 0x2ee4f0, 0x54

gUnknown_082EE544: ; 82EE544
	.incbin "base_emerald.gba", 0x2ee544, 0x1c

gUnknown_082EE560: ; 82EE560
	.incbin "base_emerald.gba", 0x2ee560, 0x1c

gUnknown_082EE57C: ; 82EE57C
	.incbin "base_emerald.gba", 0x2ee57c, 0x1c

gUnknown_082EE598: ; 82EE598
	.incbin "base_emerald.gba", 0x2ee598, 0x120

gUnknown_082EE6B8: ; 82EE6B8
	.incbin "base_emerald.gba", 0x2ee6b8, 0x10

gUnknown_082EE6C8: ; 82EE6C8
	.incbin "base_emerald.gba", 0x2ee6c8, 0x164

gUnknown_082EE82C: ; 82EE82C
	.incbin "base_emerald.gba", 0x2ee82c, 0x158

gUnknown_082EE984: ; 82EE984
	.incbin "base_emerald.gba", 0x2ee984, 0xe4

gUnknown_082EEA68: ; 82EEA68
	.incbin "base_emerald.gba", 0x2eea68, 0xa0

gUnknown_082EEB08: ; 82EEB08
	.incbin "base_emerald.gba", 0x2eeb08, 0x78

gUnknown_082EEB80: ; 82EEB80
	.incbin "base_emerald.gba", 0x2eeb80, 0x8

gUnknown_082EEB88: ; 82EEB88
	.incbin "base_emerald.gba", 0x2eeb88, 0x48

gUnknown_082EEBD0: ; 82EEBD0
	.incbin "base_emerald.gba", 0x2eebd0, 0x44

gUnknown_082EEC14: ; 82EEC14
	.incbin "base_emerald.gba", 0x2eec14, 0x88

gUnknown_082EEC9C: ; 82EEC9C
	.incbin "base_emerald.gba", 0x2eec9c, 0xa0

gUnknown_082EED3C: ; 82EED3C
	.incbin "base_emerald.gba", 0x2eed3c, 0x170

gUnknown_082EEEAC: ; 82EEEAC
	.incbin "base_emerald.gba", 0x2eeeac, 0x164

gUnknown_082EF010: ; 82EF010
	.incbin "base_emerald.gba", 0x2ef010, 0xf0

gUnknown_082EF100: ; 82EF100
	.incbin "base_emerald.gba", 0x2ef100, 0xcc

gUnknown_082EF1CC: ; 82EF1CC
	.incbin "base_emerald.gba", 0x2ef1cc, 0x20

gUnknown_082EF1EC: ; 82EF1EC
	.incbin "base_emerald.gba", 0x2ef1ec, 0x20

gUnknown_082EF20C: ; 82EF20C
	.incbin "base_emerald.gba", 0x2ef20c, 0x8c

gUnknown_082EF298: ; 82EF298
	.incbin "base_emerald.gba", 0x2ef298, 0x1e4

gUnknown_082EF47C: ; 82EF47C
	.incbin "base_emerald.gba", 0x2ef47c, 0x48

gUnknown_082EF4C4: ; 82EF4C4
	.incbin "base_emerald.gba", 0x2ef4c4, 0x38

gUnknown_082EF4FC: ; 82EF4FC
	.incbin "base_emerald.gba", 0x2ef4fc, 0x24

gUnknown_082EF520: ; 82EF520
	.incbin "base_emerald.gba", 0x2ef520, 0x24

gUnknown_082EF544: ; 82EF544
	.incbin "base_emerald.gba", 0x2ef544, 0x20

gUnknown_082EF564: ; 82EF564
	.incbin "base_emerald.gba", 0x2ef564, 0x2c

gUnknown_082EF590: ; 82EF590
	.incbin "base_emerald.gba", 0x2ef590, 0x28

gUnknown_082EF5B8: ; 82EF5B8
	.incbin "base_emerald.gba", 0x2ef5b8, 0xa4

gUnknown_082EF65C: ; 82EF65C
	.incbin "base_emerald.gba", 0x2ef65c, 0x88

gUnknown_082EF6E4: ; 82EF6E4
	.incbin "base_emerald.gba", 0x2ef6e4, 0x34

gUnknown_082EF718: ; 82EF718
	.incbin "base_emerald.gba", 0x2ef718, 0x98

gUnknown_082EF7B0: ; 82EF7B0
	.incbin "base_emerald.gba", 0x2ef7b0, 0x20

gUnknown_082EF7D0: ; 82EF7D0
	.incbin "base_emerald.gba", 0x2ef7d0, 0xc

gUnknown_082EF7DC: ; 82EF7DC
	.incbin "base_emerald.gba", 0x2ef7dc, 0x1c

gUnknown_082EF7F8: ; 82EF7F8
	.incbin "base_emerald.gba", 0x2ef7f8, 0x378

gUnknown_082EFB70: ; 82EFB70
	.incbin "base_emerald.gba", 0x2efb70, 0x58

gUnknown_082EFBC8: ; 82EFBC8
	.incbin "base_emerald.gba", 0x2efbc8, 0x74

gUnknown_082EFC3C: ; 82EFC3C
	.incbin "base_emerald.gba", 0x2efc3c, 0x18

gUnknown_082EFC54: ; 82EFC54
	.incbin "base_emerald.gba", 0x2efc54, 0x3c

gUnknown_082EFC90: ; 82EFC90
	.incbin "base_emerald.gba", 0x2efc90, 0xc8

gUnknown_082EFD58: ; 82EFD58
	.incbin "base_emerald.gba", 0x2efd58, 0x3c

gUnknown_082EFD94: ; 82EFD94
	.incbin "base_emerald.gba", 0x2efd94, 0x1bc

gUnknown_082EFF50: ; 82EFF50
	.incbin "base_emerald.gba", 0x2eff50, 0x14

gUnknown_082EFF64: ; 82EFF64
	.incbin "base_emerald.gba", 0x2eff64, 0x40

gUnknown_082EFFA4: ; 82EFFA4
	.incbin "base_emerald.gba", 0x2effa4, 0x74

gUnknown_082F0018: ; 82F0018
	.incbin "base_emerald.gba", 0x2f0018, 0x8

gUnknown_082F0020: ; 82F0020
	.incbin "base_emerald.gba", 0x2f0020, 0x28

gUnknown_082F0048: ; 82F0048
	.incbin "base_emerald.gba", 0x2f0048, 0x74

gUnknown_082F00BC: ; 82F00BC
	.incbin "base_emerald.gba", 0x2f00bc, 0x8

gUnknown_082F00C4: ; 82F00C4
	.incbin "base_emerald.gba", 0x2f00c4, 0x58

gUnknown_082F011C: ; 82F011C
	.incbin "base_emerald.gba", 0x2f011c, 0x8

gUnknown_082F0124: ; 82F0124
	.incbin "base_emerald.gba", 0x2f0124, 0x8

gUnknown_082F012C: ; 82F012C
	.incbin "base_emerald.gba", 0x2f012c, 0x30

gUnknown_082F015C: ; 82F015C
	.incbin "base_emerald.gba", 0x2f015c, 0x18

gUnknown_082F0174: ; 82F0174
	.incbin "base_emerald.gba", 0x2f0174, 0x8

gUnknown_082F017C: ; 82F017C
	.incbin "base_emerald.gba", 0x2f017c, 0x88

gUnknown_082F0204: ; 82F0204
	.incbin "base_emerald.gba", 0x2f0204, 0x18

gUnknown_082F021C: ; 82F021C
	.incbin "base_emerald.gba", 0x2f021c, 0x28

gUnknown_082F0244: ; 82F0244
	.incbin "base_emerald.gba", 0x2f0244, 0x18

gUnknown_082F025C: ; 82F025C
	.incbin "base_emerald.gba", 0x2f025c, 0x20

gUnknown_082F027C: ; 82F027C
	.incbin "base_emerald.gba", 0x2f027c, 0x18

gUnknown_082F0294: ; 82F0294
	.incbin "base_emerald.gba", 0x2f0294, 0x98

gUnknown_082F032C: ; 82F032C
	.incbin "base_emerald.gba", 0x2f032c, 0x18

gUnknown_082F0344: ; 82F0344
	.incbin "base_emerald.gba", 0x2f0344, 0x8

gUnknown_082F034C: ; 82F034C
	.incbin "base_emerald.gba", 0x2f034c, 0x58

gUnknown_082F03A4: ; 82F03A4
	.incbin "base_emerald.gba", 0x2f03a4, 0xb8

gUnknown_082F045C: ; 82F045C
	.incbin "base_emerald.gba", 0x2f045c, 0x7c

gUnknown_082F04D8: ; 82F04D8
	.incbin "base_emerald.gba", 0x2f04d8, 0x58

gUnknown_082F0530: ; 82F0530
	.incbin "base_emerald.gba", 0x2f0530, 0x18

gUnknown_082F0548: ; 82F0548
	.incbin "base_emerald.gba", 0x2f0548, 0x20

gUnknown_082F0568: ; 82F0568
	.incbin "base_emerald.gba", 0x2f0568, 0x30

gUnknown_082F0598: ; 82F0598
	.incbin "base_emerald.gba", 0x2f0598, 0x10

gUnknown_082F05A8: ; 82F05A8
	.incbin "base_emerald.gba", 0x2f05a8, 0x20

gUnknown_082F05C8: ; 82F05C8
	.incbin "base_emerald.gba", 0x2f05c8, 0x8

gUnknown_082F05D0: ; 82F05D0
	.incbin "base_emerald.gba", 0x2f05d0, 0x8

gUnknown_082F05D8: ; 82F05D8
	.incbin "base_emerald.gba", 0x2f05d8, 0x8

gUnknown_082F05E0: ; 82F05E0
	.incbin "base_emerald.gba", 0x2f05e0, 0x8

gUnknown_082F05E8: ; 82F05E8
	.incbin "base_emerald.gba", 0x2f05e8, 0x8

gUnknown_082F05F0: ; 82F05F0
	.incbin "base_emerald.gba", 0x2f05f0, 0x8

gUnknown_082F05F8: ; 82F05F8
	.incbin "base_emerald.gba", 0x2f05f8, 0x8

gUnknown_082F0600: ; 82F0600
	.incbin "base_emerald.gba", 0x2f0600, 0x8

gUnknown_082F0608: ; 82F0608
	.incbin "base_emerald.gba", 0x2f0608, 0x18

gUnknown_082F0620: ; 82F0620
	.incbin "base_emerald.gba", 0x2f0620, 0x18

gUnknown_082F0638: ; 82F0638
	.incbin "base_emerald.gba", 0x2f0638, 0x78

gUnknown_082F06B0: ; 82F06B0
	.incbin "base_emerald.gba", 0x2f06b0, 0x18

gUnknown_082F06C8: ; 82F06C8
	.incbin "base_emerald.gba", 0x2f06c8, 0x18

gUnknown_082F06E0: ; 82F06E0
	.incbin "base_emerald.gba", 0x2f06e0, 0x18

gUnknown_082F06F8: ; 82F06F8
	.incbin "base_emerald.gba", 0x2f06f8, 0x28

gUnknown_082F0720: ; 82F0720
	.incbin "base_emerald.gba", 0x2f0720, 0x8

gUnknown_082F0728: ; 82F0728
	.incbin "base_emerald.gba", 0x2f0728, 0x4

gUnknown_082F072C: ; 82F072C
	.incbin "base_emerald.gba", 0x2f072c, 0x14

gUnknown_082F0740: ; 82F0740
	.incbin "base_emerald.gba", 0x2f0740, 0x20

gUnknown_082F0760: ; 82F0760
	.incbin "base_emerald.gba", 0x2f0760, 0xa

gUnknown_082F076A: ; 82F076A
	.incbin "base_emerald.gba", 0x2f076a, 0x5

gUnknown_082F076F: ; 82F076F
	.incbin "base_emerald.gba", 0x2f076f, 0x5

gUnknown_082F0774: ; 82F0774
	.incbin "base_emerald.gba", 0x2f0774, 0x18

gUnknown_082F078C: ; 82F078C
	.incbin "base_emerald.gba", 0x2f078c, 0x2

gUnknown_082F078E: ; 82F078E
	.incbin "base_emerald.gba", 0x2f078e, 0x2

gUnknown_082F0790: ; 82F0790
	.incbin "base_emerald.gba", 0x2f0790, 0x200

gUnknown_082F0990: ; 82F0990
	.incbin "base_emerald.gba", 0x2f0990, 0x210

gUnknown_082F0BA0: ; 82F0BA0
	.incbin "base_emerald.gba", 0x2f0ba0, 0x194

gUnknown_082F0D34: ; 82F0D34
	.incbin "base_emerald.gba", 0x2f0d34, 0x8

gUnknown_082F0D3C: ; 82F0D3C
	.incbin "base_emerald.gba", 0x2f0d3c, 0x20

gUnknown_082F0D5C: ; 82F0D5C
	.incbin "base_emerald.gba", 0x2f0d5c, 0x14

gUnknown_082F0D70: ; 82F0D70
	.incbin "base_emerald.gba", 0x2f0d70, 0x60

gUnknown_082F0DD0: ; 82F0DD0
	.incbin "base_emerald.gba", 0x2f0dd0, 0x4

gUnknown_082F0DD4: ; 82F0DD4
	.incbin "base_emerald.gba", 0x2f0dd4, 0x10

gUnknown_082F0DE4: ; 82F0DE4
	.incbin "base_emerald.gba", 0x2f0de4, 0x4

gUnknown_082F0DE8: ; 82F0DE8
	.incbin "base_emerald.gba", 0x2f0de8, 0x28

gUnknown_082F0E10: ; 82F0E10
	.incbin "base_emerald.gba", 0x2f0e10, 0x8

gUnknown_082F0E18: ; 82F0E18
	.incbin "base_emerald.gba", 0x2f0e18, 0x4

gUnknown_082F0E1C: ; 82F0E1C
	.incbin "base_emerald.gba", 0x2f0e1c, 0xee4

gUnknown_082F1D00: ; 82F1D00
	.incbin "base_emerald.gba", 0x2f1d00, 0x8

gUnknown_082F1D08: ; 82F1D08
	.incbin "base_emerald.gba", 0x2f1d08, 0x40

gUnknown_082F1D48: ; 82F1D48
	.incbin "base_emerald.gba", 0x2f1d48, 0x18

gUnknown_082F1D60: ; 82F1D60
	.incbin "base_emerald.gba", 0x2f1d60, 0x80

gUnknown_082F1DE0: ; 82F1DE0
	.incbin "base_emerald.gba", 0x2f1de0, 0x8

gUnknown_082F1DE8: ; 82F1DE8
	.incbin "base_emerald.gba", 0x2f1de8, 0x10

gUnknown_082F1DF8: ; 82F1DF8
	.incbin "base_emerald.gba", 0x2f1df8, 0x6d0

gUnknown_082F24C8: ; 82F24C8
	.incbin "base_emerald.gba", 0x2f24c8, 0x80

gUnknown_082F2548: ; 82F2548
	.incbin "base_emerald.gba", 0x2f2548, 0x14

gUnknown_082F255C: ; 82F255C
	.incbin "base_emerald.gba", 0x2f255c, 0x3c

gUnknown_082F2598: ; 82F2598
	.incbin "base_emerald.gba", 0x2f2598, 0x3f4

gUnknown_082F298C: ; 82F298C
	.incbin "base_emerald.gba", 0x2f298c, 0x60

gUnknown_082F29EC: ; 82F29EC
	.incbin "base_emerald.gba", 0x2f29ec, 0x90

gUnknown_082F2A7C: ; 82F2A7C
	.incbin "base_emerald.gba", 0x2f2a7c, 0x28

gUnknown_082F2AA4: ; 82F2AA4
	.incbin "base_emerald.gba", 0x2f2aa4, 0x4

gUnknown_082F2AA8: ; 82F2AA8
	.incbin "base_emerald.gba", 0x2f2aa8, 0x100

gUnknown_082F2BA8: ; 82F2BA8
	.incbin "base_emerald.gba", 0x2f2ba8, 0x78

gUnknown_082F2C20: ; 82F2C20
	.incbin "base_emerald.gba", 0x2f2c20, 0x20

gUnknown_082F2C40: ; 82F2C40
	.incbin "base_emerald.gba", 0x2f2c40, 0x20

gUnknown_082F2C60: ; 82F2C60
	.incbin "base_emerald.gba", 0x2f2c60, 0x10

gUnknown_082F2C70: ; 82F2C70
	.incbin "base_emerald.gba", 0x2f2c70, 0x28

gUnknown_082F2C98: ; 82F2C98
	.incbin "base_emerald.gba", 0x2f2c98, 0xa8

gUnknown_082F2D40: ; 82F2D40
	.incbin "base_emerald.gba", 0x2f2d40, 0x84

gUnknown_082F2DC4: ; 82F2DC4
	.incbin "base_emerald.gba", 0x2f2dc4, 0x4

gUnknown_082F2DC8: ; 82F2DC8
	.incbin "base_emerald.gba", 0x2f2dc8, 0x2a

gUnknown_082F2DF2: ; 82F2DF2
	.incbin "base_emerald.gba", 0x2f2df2, 0x342

gUnknown_082F3134: ; 82F3134
	.incbin "base_emerald.gba", 0x2f3134, 0x28

gUnknown_082F315C: ; 82F315C
	.incbin "base_emerald.gba", 0x2f315c, 0x40

gUnknown_082F319C: ; 82F319C
	.incbin "base_emerald.gba", 0x2f319c, 0x20

gUnknown_082F31BC: ; 82F31BC
	.incbin "base_emerald.gba", 0x2f31bc, 0x18

gUnknown_082F31D4: ; 82F31D4
	.incbin "base_emerald.gba", 0x2f31d4, 0x58

gUnknown_082F322C: ; 82F322C
	.incbin "base_emerald.gba", 0x2f322c, 0x18

gUnknown_082F3244: ; 82F3244
	.incbin "base_emerald.gba", 0x2f3244, 0x18

gUnknown_082F325C: ; 82F325C
	.incbin "base_emerald.gba", 0x2f325c, 0x8

gUnknown_082F3264: ; 82F3264
	.incbin "base_emerald.gba", 0x2f3264, 0x8

gUnknown_082F326C: ; 82F326C
	.incbin "base_emerald.gba", 0x2f326c, 0x24

gUnknown_082F3290: ; 82F3290
	.incbin "base_emerald.gba", 0x2f3290, 0x14

gUnknown_082F32A4: ; 82F32A4
	.incbin "base_emerald.gba", 0x2f32a4, 0x24

gUnknown_082F32C8: ; 82F32C8
	.incbin "base_emerald.gba", 0x2f32c8, 0x4

gUnknown_082F32CC: ; 82F32CC
	.incbin "base_emerald.gba", 0x2f32cc, 0xc

gUnknown_082F32D8: ; 82F32D8
	.incbin "base_emerald.gba", 0x2f32d8, 0x3

gUnknown_082F32DB: ; 82F32DB
	.incbin "base_emerald.gba", 0x2f32db, 0x3

gUnknown_082F32DE: ; 82F32DE
	.incbin "base_emerald.gba", 0x2f32de, 0x3

gUnknown_082F32E1: ; 82F32E1
	.incbin "base_emerald.gba", 0x2f32e1, 0x6

gUnknown_082F32E7: ; 82F32E7
	.incbin "base_emerald.gba", 0x2f32e7, 0x5

gUnknown_082F32EC: ; 82F32EC
	.incbin "base_emerald.gba", 0x2f32ec, 0x8

gUnknown_082F32F4: ; 82F32F4
	.incbin "base_emerald.gba", 0x2f32f4, 0x50

gUnknown_082F3344: ; 82F3344
	.incbin "base_emerald.gba", 0x2f3344, 0x8

gUnknown_082F334C: ; 82F334C
	.incbin "base_emerald.gba", 0x2f334c, 0x940

gUnknown_082F3C8C: ; 82F3C8C
	.incbin "base_emerald.gba", 0x2f3c8c, 0x130

gUnknown_082F3DBC: ; 82F3DBC
	.incbin "base_emerald.gba", 0x2f3dbc, 0x198

gUnknown_082F3F54: ; 82F3F54
	.incbin "base_emerald.gba", 0x2f3f54, 0x228

gUnknown_082F417C: ; 82F417C
	.incbin "base_emerald.gba", 0x2f417c, 0x14

gUnknown_082F4190: ; 82F4190
	.incbin "base_emerald.gba", 0x2f4190, 0x3c

gUnknown_082F41CC: ; 82F41CC
	.incbin "base_emerald.gba", 0x2f41cc, 0x1

gUnknown_082F41CD: ; 82F41CD
	.incbin "base_emerald.gba", 0x2f41cd, 0x5

gUnknown_082F41D2: ; 82F41D2
	.incbin "base_emerald.gba", 0x2f41d2, 0x1

gUnknown_082F41D3: ; 82F41D3
	.incbin "base_emerald.gba", 0x2f41d3, 0x15

gUnknown_082F41E8: ; 82F41E8
	.incbin "base_emerald.gba", 0x2f41e8, 0xc

gUnknown_082F41F4: ; 82F41F4
	.incbin "base_emerald.gba", 0x2f41f4, 0x28

gUnknown_082F421C: ; 82F421C
	.incbin "base_emerald.gba", 0x2f421c, 0xf0

gUnknown_082F430C: ; 82F430C
	.incbin "base_emerald.gba", 0x2f430c, 0x18

gUnknown_082F4324: ; 82F4324
	.incbin "base_emerald.gba", 0x2f4324, 0x18

gUnknown_082F433C: ; 82F433C
	.incbin "base_emerald.gba", 0x2f433c, 0x18

gUnknown_082F4354: ; 82F4354
	.incbin "base_emerald.gba", 0x2f4354, 0x18

gUnknown_082F436C: ; 82F436C
	.incbin "base_emerald.gba", 0x2f436c, 0x18

gUnknown_082F4384: ; 82F4384
	.incbin "base_emerald.gba", 0x2f4384, 0x30

gUnknown_082F43B4: ; 82F43B4
	.incbin "base_emerald.gba", 0x2f43b4, 0x18

gUnknown_082F43CC: ; 82F43CC
	.incbin "base_emerald.gba", 0x2f43cc, 0x68

gUnknown_082F4434: ; 82F4434
	.incbin "base_emerald.gba", 0x2f4434, 0x10

gUnknown_082F4444: ; 82F4444
	.incbin "base_emerald.gba", 0x2f4444, 0x4

gUnknown_082F4448: ; 82F4448
	.incbin "base_emerald.gba", 0x2f4448, 0x54

gUnknown_082F449C: ; 82F449C
	.incbin "base_emerald.gba", 0x2f449c, 0x113

gUnknown_082F45AF: ; 82F45AF
	.incbin "base_emerald.gba", 0x2f45af, 0x4b

gUnknown_082F45FA: ; 82F45FA
	.incbin "base_emerald.gba", 0x2f45fa, 0x4e

gUnknown_082F4648: ; 82F4648
	.incbin "base_emerald.gba", 0x2f4648, 0x37

gUnknown_082F467F: ; 82F467F
	.incbin "base_emerald.gba", 0x2f467f, 0x3409

gUnknown_082F7A88: ; 82F7A88
	.incbin "base_emerald.gba", 0x2f7a88, 0xc

gUnknown_082F7A94: ; 82F7A94
	.incbin "base_emerald.gba", 0x2f7a94, 0x8

gUnknown_082F7A9C: ; 82F7A9C
	.incbin "base_emerald.gba", 0x2f7a9c, 0x8

gUnknown_082F7AA4: ; 82F7AA4
	.incbin "base_emerald.gba", 0x2f7aa4, 0x20

gUnknown_082F7AC4: ; 82F7AC4
	.incbin "base_emerald.gba", 0x2f7ac4, 0x30

gUnknown_082F7AF4: ; 82F7AF4
	.incbin "base_emerald.gba", 0x2f7af4, 0x30

gUnknown_082F7B24: ; 82F7B24
	.incbin "base_emerald.gba", 0x2f7b24, 0x8

gUnknown_082F7B2C: ; 82F7B2C
	.incbin "base_emerald.gba", 0x2f7b2c, 0x8

gUnknown_082F7B34: ; 82F7B34
	.incbin "base_emerald.gba", 0x2f7b34, 0xc

gUnknown_082F7B40: ; 82F7B40
	.incbin "base_emerald.gba", 0x2f7b40, 0x4

gUnknown_082F7B44: ; 82F7B44
	.incbin "base_emerald.gba", 0x2f7b44, 0x6

gUnknown_082F7B4A: ; 82F7B4A
	.incbin "base_emerald.gba", 0x2f7b4a, 0x6

gUnknown_082F7B50: ; 82F7B50
	.incbin "base_emerald.gba", 0x2f7b50, 0x40

gUnknown_082F7B90: ; 82F7B90
	.incbin "base_emerald.gba", 0x2f7b90, 0x14

gUnknown_082F7BA4: ; 82F7BA4
	.incbin "base_emerald.gba", 0x2f7ba4, 0x18

gUnknown_082F7BBC: ; 82F7BBC
	.incbin "base_emerald.gba", 0x2f7bbc, 0x10

gUnknown_082F7BCC: ; 82F7BCC
	.incbin "base_emerald.gba", 0x2f7bcc, 0x8

gUnknown_082F7BD4: ; 82F7BD4
	.incbin "base_emerald.gba", 0x2f7bd4, 0x10

gUnknown_082F7BE4: ; 82F7BE4
	.incbin "base_emerald.gba", 0x2f7be4, 0x8

gUnknown_082F7BEC: ; 82F7BEC
	.incbin "base_emerald.gba", 0x2f7bec, 0x204

gUnknown_082F7DF0: ; 82F7DF0
	.incbin "base_emerald.gba", 0x2f7df0, 0xc0

gUnknown_082F7EB0: ; 82F7EB0
	.incbin "base_emerald.gba", 0x2f7eb0, 0x1d4

gUnknown_082F8084: ; 82F8084
	.incbin "base_emerald.gba", 0x2f8084, 0x890

gUnknown_082F8914: ; 82F8914
	.incbin "base_emerald.gba", 0x2f8914, 0xdcc

gUnknown_082F96E0: ; 82F96E0
	.incbin "base_emerald.gba", 0x2f96e0, 0x94

gUnknown_082F9774: ; 82F9774
	.incbin "base_emerald.gba", 0x2f9774, 0x148

gUnknown_082F98BC: ; 82F98BC
	.incbin "base_emerald.gba", 0x2f98bc, 0x121c

gUnknown_082FAAD8: ; 82FAAD8
	.incbin "base_emerald.gba", 0x2faad8, 0x26c

gUnknown_082FAD44: ; 82FAD44
	.incbin "base_emerald.gba", 0x2fad44, 0x250

gUnknown_082FAF94: ; 82FAF94
	.incbin "base_emerald.gba", 0x2faf94, 0x24c

gUnknown_082FB1E0: ; 82FB1E0
	.incbin "base_emerald.gba", 0x2fb1e0, 0x48

gUnknown_082FB228: ; 82FB228
	.incbin "base_emerald.gba", 0x2fb228, 0xb0

gUnknown_082FB2D8: ; 82FB2D8
	.incbin "base_emerald.gba", 0x2fb2d8, 0x8

gUnknown_082FB2E0: ; 82FB2E0
	.incbin "base_emerald.gba", 0x2fb2e0, 0x8

gUnknown_082FB2E8: ; 82FB2E8
	.incbin "base_emerald.gba", 0x2fb2e8, 0x8

gUnknown_082FB2F0: ; 82FB2F0
	.incbin "base_emerald.gba", 0x2fb2f0, 0x24

gUnknown_082FB314: ; 82FB314
	.incbin "base_emerald.gba", 0x2fb314, 0x8

gUnknown_082FB31C: ; 82FB31C
	.incbin "base_emerald.gba", 0x2fb31c, 0x8

gUnknown_082FB324: ; 82FB324
	.incbin "base_emerald.gba", 0x2fb324, 0x18

gUnknown_082FB33C: ; 82FB33C
	.incbin "base_emerald.gba", 0x2fb33c, 0x18

gUnknown_082FB354: ; 82FB354
	.incbin "base_emerald.gba", 0x2fb354, 0x2

gUnknown_082FB356: ; 82FB356
	.incbin "base_emerald.gba", 0x2fb356, 0xa

gUnknown_082FB360: ; 82FB360
	.incbin "base_emerald.gba", 0x2fb360, 0x8

gUnknown_082FB368: ; 82FB368
	.incbin "base_emerald.gba", 0x2fb368, 0x18

gUnknown_082FB380: ; 82FB380
	.incbin "base_emerald.gba", 0x2fb380, 0x3

gUnknown_082FB383: ; 82FB383
	.incbin "base_emerald.gba", 0x2fb383, 0x45

gUnknown_082FB3C8: ; 82FB3C8
	.incbin "base_emerald.gba", 0x2fb3c8, 0x14

gUnknown_082FB3DC: ; 82FB3DC
	.incbin "base_emerald.gba", 0x2fb3dc, 0x14

gUnknown_082FB3F0: ; 82FB3F0
	.incbin "base_emerald.gba", 0x2fb3f0, 0x8

gUnknown_082FB3F8: ; 82FB3F8
	.incbin "base_emerald.gba", 0x2fb3f8, 0xa

gUnknown_082FB402: ; 82FB402
	.incbin "base_emerald.gba", 0x2fb402, 0xa

gUnknown_082FB40C: ; 82FB40C
	.incbin "base_emerald.gba", 0x2fb40c, 0x50

gUnknown_082FB45C: ; 82FB45C
	.incbin "base_emerald.gba", 0x2fb45c, 0x8

gUnknown_082FB464: ; 82FB464
	.incbin "base_emerald.gba", 0x2fb464, 0x190

gUnknown_082FB5F4: ; 82FB5F4
	.incbin "base_emerald.gba", 0x2fb5f4, 0x24

gUnknown_082FB618: ; 82FB618
	.incbin "base_emerald.gba", 0x2fb618, 0x24

gUnknown_082FB63C: ; 82FB63C
	.incbin "base_emerald.gba", 0x2fb63c, 0x10

gUnknown_082FB64C: ; 82FB64C
	.incbin "base_emerald.gba", 0x2fb64c, 0x8

gUnknown_082FB654: ; 82FB654
	.incbin "base_emerald.gba", 0x2fb654, 0x8

gUnknown_082FB65C: ; 82FB65C
	.incbin "base_emerald.gba", 0x2fb65c, 0x90

gUnknown_082FB6EC: ; 82FB6EC
	.incbin "base_emerald.gba", 0x2fb6ec, 0x18

gUnknown_082FB704: ; 82FB704
	.incbin "base_emerald.gba", 0x2fb704, 0x10

gUnknown_082FB714: ; 82FB714
	.incbin "base_emerald.gba", 0x2fb714, 0x6f4

gUnknown_082FBE08: ; 82FBE08
	.incbin "base_emerald.gba", 0x2fbe08, 0x28

gUnknown_082FBE30: ; 82FBE30
	.incbin "base_emerald.gba", 0x2fbe30, 0x10

gUnknown_082FBE40: ; 82FBE40
	.incbin "base_emerald.gba", 0x2fbe40, 0x18

gUnknown_082FBE58: ; 82FBE58
	.incbin "base_emerald.gba", 0x2fbe58, 0x50

gUnknown_082FBEA8: ; 82FBEA8
	.incbin "base_emerald.gba", 0x2fbea8, 0x10

gUnknown_082FBEB8: ; 82FBEB8
	.incbin "base_emerald.gba", 0x2fbeb8, 0x154

gUnknown_082FC00C: ; 82FC00C
	.incbin "base_emerald.gba", 0x2fc00c, 0x18

gUnknown_082FC024: ; 82FC024
	.incbin "base_emerald.gba", 0x2fc024, 0x20

gUnknown_082FC044: ; 82FC044
	.incbin "base_emerald.gba", 0x2fc044, 0x20

gUnknown_082FC064: ; 82FC064
	.incbin "base_emerald.gba", 0x2fc064, 0x22c

gUnknown_082FC290: ; 82FC290
	.incbin "base_emerald.gba", 0x2fc290, 0x1b0

gUnknown_082FC440: ; 82FC440
	.incbin "base_emerald.gba", 0x2fc440, 0x20

gUnknown_082FC460: ; 82FC460
	.incbin "base_emerald.gba", 0x2fc460, 0x950

gUnknown_082FCDB0: ; 82FCDB0
	.incbin "base_emerald.gba", 0x2fcdb0, 0x3b8

gUnknown_082FD168: ; 82FD168
	.incbin "base_emerald.gba", 0x2fd168, 0x20

gUnknown_082FD188: ; 82FD188
	.incbin "base_emerald.gba", 0x2fd188, 0xab0

gUnknown_082FDC38: ; 82FDC38
	.incbin "base_emerald.gba", 0x2fdc38, 0x52c

gUnknown_082FE164: ; 82FE164
	.incbin "base_emerald.gba", 0x2fe164, 0x10

gUnknown_082FE174: ; 82FE174
	.incbin "base_emerald.gba", 0x2fe174, 0x18

gUnknown_082FE18C: ; 82FE18C
	.incbin "base_emerald.gba", 0x2fe18c, 0x50

gUnknown_082FE1DC: ; 82FE1DC
	.incbin "base_emerald.gba", 0x2fe1dc, 0x3

gUnknown_082FE1DF: ; 82FE1DF
	.incbin "base_emerald.gba", 0x2fe1df, 0xd

gUnknown_082FE1EC: ; 82FE1EC
	.incbin "base_emerald.gba", 0x2fe1ec, 0x8

gUnknown_082FE1F4: ; 82FE1F4
	.incbin "base_emerald.gba", 0x2fe1f4, 0x40

gUnknown_082FE234: ; 82FE234
	.incbin "base_emerald.gba", 0x2fe234, 0x2c

gUnknown_082FE260: ; 82FE260
	.incbin "base_emerald.gba", 0x2fe260, 0x10

gUnknown_082FE270: ; 82FE270
	.incbin "base_emerald.gba", 0x2fe270, 0x8

gUnknown_082FE278: ; 82FE278
	.incbin "base_emerald.gba", 0x2fe278, 0x450

gUnknown_082FE6C8: ; 82FE6C8
	.incbin "base_emerald.gba", 0x2fe6c8, 0x10

gUnknown_082FE6D8: ; 82FE6D8
	.incbin "base_emerald.gba", 0x2fe6d8, 0x58

gUnknown_082FE730: ; 82FE730
	.incbin "base_emerald.gba", 0x2fe730, 0x18

gUnknown_082FE748: ; 82FE748
	.incbin "base_emerald.gba", 0x2fe748, 0x484

gUnknown_082FEBCC: ; 82FEBCC
	.incbin "base_emerald.gba", 0x2febcc, 0x8

gUnknown_082FEBD4: ; 82FEBD4
	.incbin "base_emerald.gba", 0x2febd4, 0xbc

gUnknown_082FEC90: ; 82FEC90
	.incbin "base_emerald.gba", 0x2fec90, 0x18

gUnknown_082FECA8: ; 82FECA8
	.incbin "base_emerald.gba", 0x2feca8, 0x18

gUnknown_082FECC0: ; 82FECC0
	.incbin "base_emerald.gba", 0x2fecc0, 0xc

gUnknown_082FECCC: ; 82FECCC
	.incbin "base_emerald.gba", 0x2feccc, 0x30

gUnknown_082FECFC: ; 82FECFC
	.incbin "base_emerald.gba", 0x2fecfc, 0x40

gUnknown_082FED3C: ; 82FED3C
	.incbin "base_emerald.gba", 0x2fed3c, 0x1b4

gUnknown_082FEEF0: ; 82FEEF0
	.incbin "base_emerald.gba", 0x2feef0, 0x128

gUnknown_082FF018: ; 82FF018
	.incbin "base_emerald.gba", 0x2ff018, 0x2

gUnknown_082FF01A: ; 82FF01A
	.incbin "base_emerald.gba", 0x2ff01a, 0xe

gUnknown_082FF028: ; 82FF028
	.incbin "base_emerald.gba", 0x2ff028, 0x10

gUnknown_082FF038: ; 82FF038
	.incbin "base_emerald.gba", 0x2ff038, 0x10

gUnknown_082FF048: ; 82FF048
	.incbin "base_emerald.gba", 0x2ff048, 0x28

gUnknown_082FF070: ; 82FF070
	.incbin "base_emerald.gba", 0x2ff070, 0x10

gUnknown_082FF080: ; 82FF080
	.incbin "base_emerald.gba", 0x2ff080, 0x8

gUnknown_082FF088: ; 82FF088
	.incbin "base_emerald.gba", 0x2ff088, 0x18

gUnknown_082FF0A0: ; 82FF0A0
	.incbin "base_emerald.gba", 0x2ff0a0, 0x20

gUnknown_082FF0C0: ; 82FF0C0
	.incbin "base_emerald.gba", 0x2ff0c0, 0x20

gUnknown_082FF0E0: ; 82FF0E0
	.incbin "base_emerald.gba", 0x2ff0e0, 0x3

gUnknown_082FF0E3: ; 82FF0E3
	.incbin "base_emerald.gba", 0x2ff0e3, 0x5

gUnknown_082FF0E8: ; 82FF0E8
	.incbin "base_emerald.gba", 0x2ff0e8, 0x8

gUnknown_082FF0F0: ; 82FF0F0
	.incbin "base_emerald.gba", 0x2ff0f0, 0x4

gUnknown_082FF0F4: ; 82FF0F4
	.incbin "base_emerald.gba", 0x2ff0f4, 0x20

gUnknown_082FF114: ; 82FF114
	.incbin "base_emerald.gba", 0x2ff114, 0x4

gUnknown_082FF118: ; 82FF118
	.incbin "base_emerald.gba", 0x2ff118, 0x10

gUnknown_082FF128: ; 82FF128
	.incbin "base_emerald.gba", 0x2ff128, 0x50

gUnknown_082FF178: ; 82FF178
	.incbin "base_emerald.gba", 0x2ff178, 0x50

gUnknown_082FF1C8: ; 82FF1C8
	.incbin "base_emerald.gba", 0x2ff1c8, 0x450

gUnknown_082FF618: ; 82FF618
	.incbin "base_emerald.gba", 0x2ff618, 0x7c

gUnknown_082FF694: ; 82FF694
	.incbin "base_emerald.gba", 0x2ff694, 0x2c

gUnknown_082FF6C0: ; 82FF6C0
	.incbin "base_emerald.gba", 0x2ff6c0, 0x4c

gUnknown_082FF70C: ; 82FF70C
	.incbin "base_emerald.gba", 0x2ff70c, 0x162c

gUnknown_08300D38: ; 8300D38
	.incbin "base_emerald.gba", 0x300d38, 0x6e0

gUnknown_08301418: ; 8301418
	.incbin "base_emerald.gba", 0x301418, 0xdc0

gUnknown_083021D8: ; 83021D8
	.incbin "base_emerald.gba", 0x3021d8, 0x6e0

gUnknown_083028B8: ; 83028B8
	.incbin "base_emerald.gba", 0x3028b8, 0xdc0

gUnknown_08303678: ; 8303678
	.incbin "base_emerald.gba", 0x303678, 0xdc0

gUnknown_08304438: ; 8304438
	.incbin "base_emerald.gba", 0x304438, 0xf34

gUnknown_0830536C: ; 830536C
	.incbin "base_emerald.gba", 0x30536c, 0x174

gUnknown_083054E0: ; 83054E0
	.incbin "base_emerald.gba", 0x3054e0, 0x174

gUnknown_08305654: ; 8305654
	.incbin "base_emerald.gba", 0x305654, 0x2e8

gUnknown_0830593C: ; 830593C
	.incbin "base_emerald.gba", 0x30593c, 0x3d0

gUnknown_08305D0C: ; 8305D0C
	.incbin "base_emerald.gba", 0x305d0c, 0x20

gUnknown_08305D2C: ; 8305D2C
	.incbin "base_emerald.gba", 0x305d2c, 0x20

gUnknown_08305D4C: ; 8305D4C
	.incbin "base_emerald.gba", 0x305d4c, 0x40

gUnknown_08305D8C: ; 8305D8C
	.incbin "base_emerald.gba", 0x305d8c, 0x40

gUnknown_08305DCC: ; 8305DCC
	.incbin "base_emerald.gba", 0x305dcc, 0x3ce0

gUnknown_08309AAC: ; 8309AAC
	.incbin "base_emerald.gba", 0x309aac, 0x6e0

gUnknown_0830A18C: ; 830A18C
	.incbin "base_emerald.gba", 0x30a18c, 0x5b48

; 830FCD4
	.include "data/text/trainer_class_names.s"

	.align 2, 0

gUnknown_08310030: ; 8310030
	.incbin "base_emerald.gba", 0x310030, 0x4

gUnknown_08310034: ; 8310034
	.incbin "base_emerald.gba", 0x310034, 0xc

gUnknown_08310040: ; 8310040
	.incbin "base_emerald.gba", 0x310040, 0x7d94

gUnknown_08317DD4: ; 8317DD4
	.incbin "base_emerald.gba", 0x317dd4, 0x50

gUnknown_08317E24: ; 8317E24
	.incbin "base_emerald.gba", 0x317e24, 0x7a4

; 83185C8
	.include "data/text/species_names.s"

; 831977C
	.include "data/text/move_names.s"

	.incbin "base_emerald.gba", 0x31a983, 0x4d

gUnknown_0831A9D0: ; 831A9D0
	.incbin "base_emerald.gba", 0x31a9d0, 0x18

gUnknown_0831A9E8: ; 831A9E8
	.incbin "base_emerald.gba", 0x31a9e8, 0x18

gUnknown_0831AA00: ; 831AA00
	.incbin "base_emerald.gba", 0x31aa00, 0x8

gUnknown_0831AA08: ; 831AA08
	.incbin "base_emerald.gba", 0x31aa08, 0x198

gUnknown_0831ABA0: ; 831ABA0
	.incbin "base_emerald.gba", 0x31aba0, 0x8

gUnknown_0831ABA8: ; 831ABA8
	.incbin "base_emerald.gba", 0x31aba8, 0xc8

gUnknown_0831AC70: ; 831AC70
	.incbin "base_emerald.gba", 0x31ac70, 0x18

gUnknown_0831AC88: ; 831AC88
	.incbin "base_emerald.gba", 0x31ac88, 0x18

gUnknown_0831ACA0: ; 831ACA0
	.incbin "base_emerald.gba", 0x31aca0, 0x40

gUnknown_0831ACE0: ; 831ACE0
	.incbin "base_emerald.gba", 0x31ace0, 0x8

gUnknown_0831ACE8: ; 831ACE8
	.incbin "base_emerald.gba", 0x31ace8, 0x150

; 831AE38
	.include "data/text/type_names.s"

	.align 2, 0

gUnknown_0831AEB8: ; 831AEB8
	.incbin "base_emerald.gba", 0x31aeb8, 0xe0

; 831AF98
	.include "data/text/ability_descriptions.s"

; 831B6DB
	.include "data/text/ability_names.s"

; 831BAD4
	.include "data/text/ability_description_pointers.s"

gUnknown_0831BC0C: ; 831BC0C
	.incbin "base_emerald.gba", 0x31bc0c, 0x38

gUnknown_0831BC44: ; 831BC44
	.incbin "base_emerald.gba", 0x31bc44, 0x2c

gUnknown_0831BC70: ; 831BC70
	.incbin "base_emerald.gba", 0x31bc70, 0x8

gUnknown_0831BC78: ; 831BC78
	.incbin "base_emerald.gba", 0x31bc78, 0x8

gUnknown_0831BC80: ; 831BC80
	.incbin "base_emerald.gba", 0x31bc80, 0x8

gUnknown_0831BC88: ; 831BC88
	.incbin "base_emerald.gba", 0x31bc88, 0x8

gUnknown_0831BC90: ; 831BC90
	.incbin "base_emerald.gba", 0x31bc90, 0x8

gUnknown_0831BC98: ; 831BC98
	.incbin "base_emerald.gba", 0x31bc98, 0x8

gUnknown_0831BCA0: ; 831BCA0
	.incbin "base_emerald.gba", 0x31bca0, 0x8

gUnknown_0831BCA8: ; 831BCA8
	.incbin "base_emerald.gba", 0x31bca8, 0x38

gUnknown_0831BCE0: ; 831BCE0
	.incbin "base_emerald.gba", 0x31bce0, 0xf

gUnknown_0831BCEF: ; 831BCEF
	.incbin "base_emerald.gba", 0x31bcef, 0x4

gUnknown_0831BCF3: ; 831BCF3
	.incbin "base_emerald.gba", 0x31bcf3, 0x5

gUnknown_0831BCF8: ; 831BCF8
	.incbin "base_emerald.gba", 0x31bcf8, 0x18

gUnknown_0831BD10: ; 831BD10
	.incbin "base_emerald.gba", 0x31bd10, 0x3e4

gUnknown_0831C0F4: ; 831C0F4
	.incbin "base_emerald.gba", 0x31c0f4, 0x34

gUnknown_0831C128: ; 831C128
	.incbin "base_emerald.gba", 0x31c128, 0xc

gUnknown_0831C134: ; 831C134
	.incbin "base_emerald.gba", 0x31c134, 0xf0

gUnknown_0831C224: ; 831C224
	.incbin "base_emerald.gba", 0x31c224, 0xa4

gUnknown_0831C2C8: ; 831C2C8
	.incbin "base_emerald.gba", 0x31c2c8, 0x20

gUnknown_0831C2E8: ; 831C2E8
	.incbin "base_emerald.gba", 0x31c2e8, 0xd8

gUnknown_0831C3C0: ; 831C3C0
	.incbin "base_emerald.gba", 0x31c3c0, 0x18

gUnknown_0831C3D8: ; 831C3D8
	.incbin "base_emerald.gba", 0x31c3d8, 0x8

gUnknown_0831C3E0: ; 831C3E0
	.incbin "base_emerald.gba", 0x31c3e0, 0x28

gUnknown_0831C408: ; 831C408
	.incbin "base_emerald.gba", 0x31c408, 0xc

gUnknown_0831C414: ; 831C414
	.incbin "base_emerald.gba", 0x31c414, 0x14

gUnknown_0831C428: ; 831C428
	.incbin "base_emerald.gba", 0x31c428, 0x18

gUnknown_0831C440: ; 831C440
	.incbin "base_emerald.gba", 0x31c440, 0x24

gUnknown_0831C464: ; 831C464
	.incbin "base_emerald.gba", 0x31c464, 0x16

gUnknown_0831C47A: ; 831C47A
	.incbin "base_emerald.gba", 0x31c47a, 0x9

gUnknown_0831C483: ; 831C483
	.incbin "base_emerald.gba", 0x31c483, 0xa

gUnknown_0831C48D: ; 831C48D
	.incbin "base_emerald.gba", 0x31c48d, 0x7

gUnknown_0831C494: ; 831C494
	.incbin "base_emerald.gba", 0x31c494, 0x64

gUnknown_0831C4F8: ; 831C4F8
	.incbin "base_emerald.gba", 0x31c4f8, 0x1c

gUnknown_0831C514: ; 831C514
	.incbin "base_emerald.gba", 0x31c514, 0xe4

gUnknown_0831C5F8: ; 831C5F8
	.incbin "base_emerald.gba", 0x31c5f8, 0xc

gUnknown_0831C604: ; 831C604
	.incbin "base_emerald.gba", 0x31c604, 0x1c

gUnknown_0831C620: ; 831C620
	.incbin "base_emerald.gba", 0x31c620, 0x8

gUnknown_0831C628: ; 831C628
	.incbin "base_emerald.gba", 0x31c628, 0x60

gUnknown_0831C688: ; 831C688
	.incbin "base_emerald.gba", 0x31c688, 0x18

gUnknown_0831C6A0: ; 831C6A0
	.incbin "base_emerald.gba", 0x31c6a0, 0x10

gUnknown_0831C6B0: ; 831C6B0
	.incbin "base_emerald.gba", 0x31c6b0, 0x18

gUnknown_0831C6C8: ; 831C6C8
	.incbin "base_emerald.gba", 0x31c6c8, 0xec

gUnknown_0831C7B4: ; 831C7B4
	.incbin "base_emerald.gba", 0x31c7b4, 0xe4

gUnknown_0831C898: ; 831C898
	.incbin "base_emerald.gba", 0x31c898, 0x4

gUnknown_0831C89C: ; 831C89C
	.incbin "base_emerald.gba", 0x31c89c, 0x10b0

	.include "data/pokedex_order.s"

	.align 2, 0

gUnknown_0831E2F0: ; 831E2F0
	.incbin "base_emerald.gba", 0x31e2f0, 0x2

gUnknown_0831E2F2: ; 831E2F2
	.incbin "base_emerald.gba", 0x31e2f2, 0x29a

gUnknown_0831E58C: ; 831E58C
	.incbin "base_emerald.gba", 0x31e58c, 0x28c

gUnknown_0831E818: ; 831E818
	.incbin "base_emerald.gba", 0x31e818, 0x80

gUnknown_0831E898: ; 831E898
	.incbin "base_emerald.gba", 0x31e898, 0xce0

gUnknown_0831F578: ; 831F578
	.incbin "base_emerald.gba", 0x31f578, 0x52

gUnknown_0831F5CA: ; 831F5CA
	.incbin "base_emerald.gba", 0x31f5ca, 0x52

gUnknown_0831F61C: ; 831F61C
	.incbin "base_emerald.gba", 0x31f61c, 0x110

; 831F72C
	.include "data/experience_tables.s"

gUnknown_083203CC: ; 83203CC
	.incbin "base_emerald.gba", 0x3203cc, 0xc

gUnknown_083203D8: ; 83203D8
	.incbin "base_emerald.gba", 0x3203d8, 0x2

gUnknown_083203DA: ; 83203DA
	.incbin "base_emerald.gba", 0x3203da, 0x3

gUnknown_083203DD: ; 83203DD
	.incbin "base_emerald.gba", 0x3203dd, 0x4f3f

gUnknown_0832531C: ; 832531C
	.incbin "base_emerald.gba", 0x32531c, 0x4060

gUnknown_0832937C: ; 832937C
	.incbin "base_emerald.gba", 0x32937c, 0x670

gUnknown_083299EC: ; 83299EC
	.incbin "base_emerald.gba", 0x3299ec, 0x19b

gUnknown_08329B87: ; 8329B87
	.incbin "base_emerald.gba", 0x329b87, 0x19b

gUnknown_08329D22: ; 8329D22
	.incbin "base_emerald.gba", 0x329d22, 0x4

gUnknown_08329D26: ; 8329D26
	.incbin "base_emerald.gba", 0x329d26, 0x4

gUnknown_08329D2A: ; 8329D2A
	.incbin "base_emerald.gba", 0x329d2a, 0x4

gUnknown_08329D2E: ; 8329D2E
	.incbin "base_emerald.gba", 0x329d2e, 0x1a

gUnknown_08329D48: ; 8329D48
	.incbin "base_emerald.gba", 0x329d48, 0xc

gUnknown_08329D54: ; 8329D54
	.incbin "base_emerald.gba", 0x329d54, 0x20

gUnknown_08329D74: ; 8329D74
	.incbin "base_emerald.gba", 0x329d74, 0x24

gUnknown_08329D98: ; 8329D98
	.incbin "base_emerald.gba", 0x329d98, 0x60

gUnknown_08329DF8: ; 8329DF8
	.incbin "base_emerald.gba", 0x329df8, 0xc0

gUnknown_08329EB8: ; 8329EB8
	.incbin "base_emerald.gba", 0x329eb8, 0xa

gUnknown_08329EC2: ; 8329EC2
	.incbin "base_emerald.gba", 0x329ec2, 0x6

gUnknown_08329EC8: ; 8329EC8
	.incbin "base_emerald.gba", 0x329ec8, 0x6

gUnknown_08329ECE: ; 8329ECE
	.incbin "base_emerald.gba", 0x329ece, 0x1c

gUnknown_08329EEA: ; 8329EEA
	.incbin "base_emerald.gba", 0x329eea, 0x12

gUnknown_08329EFC: ; 8329EFC
	.incbin "base_emerald.gba", 0x329efc, 0x2

gUnknown_08329EFE: ; 8329EFE
	.incbin "base_emerald.gba", 0x329efe, 0x2a

gUnknown_08329F28: ; 8329F28
	.incbin "base_emerald.gba", 0x329f28, 0x18

gUnknown_08329F40: ; 8329F40
	.incbin "base_emerald.gba", 0x329f40, 0x280

gUnknown_0832A1C0: ; 832A1C0
	.incbin "base_emerald.gba", 0x32a1c0, 0x168

gUnknown_0832A328: ; 832A328
	.incbin "base_emerald.gba", 0x32a328, 0x80

gUnknown_0832A3A8: ; 832A3A8
	.incbin "base_emerald.gba", 0x32a3a8, 0x18

gUnknown_0832A3C0: ; 832A3C0
	.incbin "base_emerald.gba", 0x32a3c0, 0x18

gUnknown_0832A3D8: ; 832A3D8
	.incbin "base_emerald.gba", 0x32a3d8, 0xa00

gUnknown_0832ADD8: ; 832ADD8
	.incbin "base_emerald.gba", 0x32add8, 0x8e8

gUnknown_0832B6C0: ; 832B6C0
	.incbin "base_emerald.gba", 0x32b6c0, 0x20

gUnknown_0832B6E0: ; 832B6E0
	.incbin "base_emerald.gba", 0x32b6e0, 0x18

gUnknown_0832B6F8: ; 832B6F8
	.incbin "base_emerald.gba", 0x32b6f8, 0x10

gUnknown_0832B708: ; 832B708
	.incbin "base_emerald.gba", 0x32b708, 0x8dc

gUnknown_0832BFE4: ; 832BFE4
	.incbin "base_emerald.gba", 0x32bfe4, 0x8

gUnknown_0832BFEC: ; 832BFEC
	.incbin "base_emerald.gba", 0x32bfec, 0x8

gUnknown_0832BFF4: ; 832BFF4
	.incbin "base_emerald.gba", 0x32bff4, 0x8

gUnknown_0832BFFC: ; 832BFFC
	.incbin "base_emerald.gba", 0x32bffc, 0x50

gUnknown_0832C04C: ; 832C04C
	.incbin "base_emerald.gba", 0x32c04c, 0x18

gUnknown_0832C064: ; 832C064
	.incbin "base_emerald.gba", 0x32c064, 0x8

gUnknown_0832C06C: ; 832C06C
	.incbin "base_emerald.gba", 0x32c06c, 0x10

gUnknown_0832C07C: ; 832C07C
	.incbin "base_emerald.gba", 0x32c07c, 0x8

gUnknown_0832C084: ; 832C084
	.incbin "base_emerald.gba", 0x32c084, 0x4c

gUnknown_0832C0D0: ; 832C0D0
	.incbin "base_emerald.gba", 0x32c0d0, 0x8

gUnknown_0832C0D8: ; 832C0D8
	.incbin "base_emerald.gba", 0x32c0d8, 0x8

gUnknown_0832C0E0: ; 832C0E0
	.incbin "base_emerald.gba", 0x32c0e0, 0x8

gUnknown_0832C0E8: ; 832C0E8
	.incbin "base_emerald.gba", 0x32c0e8, 0x8

gUnknown_0832C0F0: ; 832C0F0
	.incbin "base_emerald.gba", 0x32c0f0, 0x8

gUnknown_0832C0F8: ; 832C0F8
	.incbin "base_emerald.gba", 0x32c0f8, 0x8

gUnknown_0832C100: ; 832C100
	.incbin "base_emerald.gba", 0x32c100, 0x8

gUnknown_0832C108: ; 832C108
	.incbin "base_emerald.gba", 0x32c108, 0x20

gUnknown_0832C128: ; 832C128
	.incbin "base_emerald.gba", 0x32c128, 0x18

gUnknown_0832C140: ; 832C140
	.incbin "base_emerald.gba", 0x32c140, 0x30

gUnknown_0832C170: ; 832C170
	.incbin "base_emerald.gba", 0x32c170, 0x30

gUnknown_0832C1A0: ; 832C1A0
	.incbin "base_emerald.gba", 0x32c1a0, 0x20

gUnknown_0832C1C0: ; 832C1C0
	.incbin "base_emerald.gba", 0x32c1c0, 0xcc

gUnknown_0832C28C: ; 832C28C
	.incbin "base_emerald.gba", 0x32c28c, 0x38

gUnknown_0832C2C4: ; 832C2C4
	.incbin "base_emerald.gba", 0x32c2c4, 0x8

gUnknown_0832C2CC: ; 832C2CC
	.incbin "base_emerald.gba", 0x32c2cc, 0x68

gUnknown_0832C334: ; 832C334
	.incbin "base_emerald.gba", 0x32c334, 0x8

gUnknown_0832C33C: ; 832C33C
	.incbin "base_emerald.gba", 0x32c33c, 0x8

gUnknown_0832C344: ; 832C344
	.incbin "base_emerald.gba", 0x32c344, 0x8

gUnknown_0832C34C: ; 832C34C
	.incbin "base_emerald.gba", 0x32c34c, 0x18

gUnknown_0832C364: ; 832C364
	.incbin "base_emerald.gba", 0x32c364, 0x30

gUnknown_0832C394: ; 832C394
	.incbin "base_emerald.gba", 0x32c394, 0x30

gUnknown_0832C3C4: ; 832C3C4
	.incbin "base_emerald.gba", 0x32c3c4, 0x14

gUnknown_0832C3D8: ; 832C3D8
	.incbin "base_emerald.gba", 0x32c3d8, 0x14

gUnknown_0832C3EC: ; 832C3EC
	.incbin "base_emerald.gba", 0x32c3ec, 0xc

gUnknown_0832C3F8: ; 832C3F8
	.incbin "base_emerald.gba", 0x32c3f8, 0x8

gUnknown_0832C400: ; 832C400
	.incbin "base_emerald.gba", 0x32c400, 0x60

gUnknown_0832C460: ; 832C460
	.incbin "base_emerald.gba", 0x32c460, 0x128

gUnknown_0832C588: ; 832C588
	.incbin "base_emerald.gba", 0x32c588, 0x138

gUnknown_0832C6C0: ; 832C6C0
	.incbin "base_emerald.gba", 0x32c6c0, 0x1fe

gUnknown_0832C8BE: ; 832C8BE
	.incbin "base_emerald.gba", 0x32c8be, 0x1fe

gUnknown_0832CABC: ; 832CABC
	.incbin "base_emerald.gba", 0x32cabc, 0x800

gUnknown_0832D2BC: ; 832D2BC
	.incbin "base_emerald.gba", 0x32d2bc, 0x800

gUnknown_0832DABC: ; 832DABC
	.incbin "base_emerald.gba", 0x32dabc, 0xb

gUnknown_0832DAC7: ; 832DAC7
	.incbin "base_emerald.gba", 0x32dac7, 0x2

gUnknown_0832DAC9: ; 832DAC9
	.incbin "base_emerald.gba", 0x32dac9, 0x2

gUnknown_0832DACB: ; 832DACB
	.incbin "base_emerald.gba", 0x32dacb, 0x7

gUnknown_0832DAD2: ; 832DAD2
	.incbin "base_emerald.gba", 0x32dad2, 0xd

gUnknown_0832DADF: ; 832DADF
	.incbin "base_emerald.gba", 0x32dadf, 0x6

gUnknown_0832DAE5: ; 832DAE5
	.incbin "base_emerald.gba", 0x32dae5, 0x157

gUnknown_0832DC3C: ; 832DC3C
	.incbin "base_emerald.gba", 0x32dc3c, 0x8

gUnknown_0832DC44: ; 832DC44
	.incbin "base_emerald.gba", 0x32dc44, 0x50

gUnknown_0832DC94: ; 832DC94
	.incbin "base_emerald.gba", 0x32dc94, 0x18

gUnknown_0832DCAC: ; 832DCAC
	.incbin "base_emerald.gba", 0x32dcac, 0x38

gUnknown_0832DCE4: ; 832DCE4
	.incbin "base_emerald.gba", 0x32dce4, 0x8

gUnknown_0832DCEC: ; 832DCEC
	.incbin "base_emerald.gba", 0x32dcec, 0x138

gUnknown_0832DE24: ; 832DE24
	.incbin "base_emerald.gba", 0x32de24, 0x1a

gUnknown_0832DE3E: ; 832DE3E
	.incbin "base_emerald.gba", 0x32de3e, 0x18

gUnknown_0832DE56: ; 832DE56
	.incbin "base_emerald.gba", 0x32de56, 0x3e

gUnknown_0832DE94: ; 832DE94
	.incbin "base_emerald.gba", 0x32de94, 0x18

gUnknown_0832DEAC: ; 832DEAC
	.incbin "base_emerald.gba", 0x32deac, 0x10

gUnknown_0832DEBC: ; 832DEBC
	.incbin "base_emerald.gba", 0x32debc, 0x24

gUnknown_0832DEE0: ; 832DEE0
	.incbin "base_emerald.gba", 0x32dee0, 0x4

gUnknown_0832DEE4: ; 832DEE4
	.incbin "base_emerald.gba", 0x32dee4, 0x10

gUnknown_0832DEF4: ; 832DEF4
	.incbin "base_emerald.gba", 0x32def4, 0x98

gUnknown_0832DF8C: ; 832DF8C
	.incbin "base_emerald.gba", 0x32df8c, 0x8

gUnknown_0832DF94: ; 832DF94
	.incbin "base_emerald.gba", 0x32df94, 0x5

gUnknown_0832DF99: ; 832DF99
	.incbin "base_emerald.gba", 0x32df99, 0x2027

gUnknown_0832FFC0: ; 832FFC0
	.incbin "base_emerald.gba", 0x32ffc0, 0x1fa0

gUnknown_08331F60: ; 8331F60
	.incbin "base_emerald.gba", 0x331f60, 0x1000

gUnknown_08332F60: ; 8332F60
	.incbin "base_emerald.gba", 0x332f60, 0x2840

gUnknown_083357A0: ; 83357A0
	.incbin "base_emerald.gba", 0x3357a0, 0x100

gUnknown_083358A0: ; 83358A0
	.incbin "base_emerald.gba", 0x3358a0, 0x100

gUnknown_083359A0: ; 83359A0
	.incbin "base_emerald.gba", 0x3359a0, 0x1000

gUnknown_083369A0: ; 83369A0
	.incbin "base_emerald.gba", 0x3369a0, 0x1000

gUnknown_083379A0: ; 83379A0
	.incbin "base_emerald.gba", 0x3379a0, 0x100

gUnknown_08337AA0: ; 8337AA0
	.incbin "base_emerald.gba", 0x337aa0, 0x200

gUnknown_08337CA0: ; 8337CA0
	.incbin "base_emerald.gba", 0x337ca0, 0x200

gUnknown_08337EA0: ; 8337EA0
	.incbin "base_emerald.gba", 0x337ea0, 0x20

gUnknown_08337EC0: ; 8337EC0
	.incbin "base_emerald.gba", 0x337ec0, 0x690

gUnknown_08338550: ; 8338550
	.incbin "base_emerald.gba", 0x338550, 0x7c8

gUnknown_08338D18: ; 8338D18
	.incbin "base_emerald.gba", 0x338d18, 0x8

gUnknown_08338D20: ; 8338D20
	.incbin "base_emerald.gba", 0x338d20, 0x8

gUnknown_08338D28: ; 8338D28
	.incbin "base_emerald.gba", 0x338d28, 0x48

gUnknown_08338D70: ; 8338D70
	.incbin "base_emerald.gba", 0x338d70, 0x8

gUnknown_08338D78: ; 8338D78
	.incbin "base_emerald.gba", 0x338d78, 0x8

gUnknown_08338D80: ; 8338D80
	.incbin "base_emerald.gba", 0x338d80, 0x8

gUnknown_08338D88: ; 8338D88
	.incbin "base_emerald.gba", 0x338d88, 0x38

gUnknown_08338DC0: ; 8338DC0
	.incbin "base_emerald.gba", 0x338dc0, 0x8

gUnknown_08338DC8: ; 8338DC8
	.incbin "base_emerald.gba", 0x338dc8, 0x2c

gUnknown_08338DF4: ; 8338DF4
	.incbin "base_emerald.gba", 0x338df4, 0x8

gUnknown_08338DFC: ; 8338DFC
	.incbin "base_emerald.gba", 0x338dfc, 0x70

gUnknown_08338E6C: ; 8338E6C
	.incbin "base_emerald.gba", 0x338e6c, 0x8

gUnknown_08338E74: ; 8338E74
	.incbin "base_emerald.gba", 0x338e74, 0x18

gUnknown_08338E8C: ; 8338E8C
	.incbin "base_emerald.gba", 0x338e8c, 0x18

gUnknown_08338EA4: ; 8338EA4
	.incbin "base_emerald.gba", 0x338ea4, 0x28

gUnknown_08338ECC: ; 8338ECC
	.incbin "base_emerald.gba", 0x338ecc, 0x4

gUnknown_08338ED0: ; 8338ED0
	.incbin "base_emerald.gba", 0x338ed0, 0xf0

gUnknown_08338FC0: ; 8338FC0
	.incbin "base_emerald.gba", 0x338fc0, 0x3c

gUnknown_08338FFC: ; 8338FFC
	.incbin "base_emerald.gba", 0x338ffc, 0x10

gUnknown_0833900C: ; 833900C
	.incbin "base_emerald.gba", 0x33900c, 0x8

gUnknown_08339014: ; 8339014
	.incbin "base_emerald.gba", 0x339014, 0x10

gUnknown_08339024: ; 8339024
	.incbin "base_emerald.gba", 0x339024, 0x6c

gUnknown_08339090: ; 8339090
	.incbin "base_emerald.gba", 0x339090, 0x44

gUnknown_083390D4: ; 83390D4
	.incbin "base_emerald.gba", 0x3390d4, 0x20

gUnknown_083390F4: ; 83390F4
	.incbin "base_emerald.gba", 0x3390f4, 0x400

gUnknown_083394F4: ; 83394F4
	.incbin "base_emerald.gba", 0x3394f4, 0x246

gUnknown_0833973A: ; 833973A
	.incbin "base_emerald.gba", 0x33973a, 0x61

gUnknown_0833979B: ; 833979B
	.incbin "base_emerald.gba", 0x33979b, 0x2

gUnknown_0833979D: ; 833979D
	.incbin "base_emerald.gba", 0x33979d, 0x33

gUnknown_083397D0: ; 83397D0
	.incbin "base_emerald.gba", 0x3397d0, 0x4a

gUnknown_0833981A: ; 833981A
	.incbin "base_emerald.gba", 0x33981a, 0x17

gUnknown_08339831: ; 8339831
	.incbin "base_emerald.gba", 0x339831, 0x27

gUnknown_08339858: ; 8339858
	.incbin "base_emerald.gba", 0x339858, 0x3e

gUnknown_08339896: ; 8339896
	.incbin "base_emerald.gba", 0x339896, 0x1a

gUnknown_083398B0: ; 83398B0
	.incbin "base_emerald.gba", 0x3398b0, 0x2d

gUnknown_083398DD: ; 83398DD
	.incbin "base_emerald.gba", 0x3398dd, 0x18

gUnknown_083398F5: ; 83398F5
	.incbin "base_emerald.gba", 0x3398f5, 0x1f

gUnknown_08339914: ; 8339914
	.incbin "base_emerald.gba", 0x339914, 0x7

gUnknown_0833991B: ; 833991B
	.incbin "base_emerald.gba", 0x33991b, 0x6

gUnknown_08339921: ; 8339921
	.incbin "base_emerald.gba", 0x339921, 0x7

gUnknown_08339928: ; 8339928
	.incbin "base_emerald.gba", 0x339928, 0x6

gUnknown_0833992E: ; 833992E
	.incbin "base_emerald.gba", 0x33992e, 0xe

gUnknown_0833993C: ; 833993C
	.incbin "base_emerald.gba", 0x33993c, 0x5

gUnknown_08339941: ; 8339941
	.incbin "base_emerald.gba", 0x339941, 0x2

gUnknown_08339943: ; 8339943
	.incbin "base_emerald.gba", 0x339943, 0x4

gUnknown_08339947: ; 8339947
	.incbin "base_emerald.gba", 0x339947, 0x8

gUnknown_0833994F: ; 833994F
	.incbin "base_emerald.gba", 0x33994f, 0xe

gUnknown_0833995D: ; 833995D
	.incbin "base_emerald.gba", 0x33995d, 0x13

gUnknown_08339970: ; 8339970
	.incbin "base_emerald.gba", 0x339970, 0x4

gUnknown_08339974: ; 8339974
	.incbin "base_emerald.gba", 0x339974, 0xc

gUnknown_08339980: ; 8339980
	.incbin "base_emerald.gba", 0x339980, 0x38

gUnknown_083399B8: ; 83399B8
	.incbin "base_emerald.gba", 0x3399b8, 0x8

gUnknown_083399C0: ; 83399C0
	.incbin "base_emerald.gba", 0x3399c0, 0x8

gUnknown_083399C8: ; 83399C8
	.incbin "base_emerald.gba", 0x3399c8, 0x8

gUnknown_083399D0: ; 83399D0
	.incbin "base_emerald.gba", 0x3399d0, 0xc

gUnknown_083399DC: ; 83399DC
	.incbin "base_emerald.gba", 0x3399dc, 0x8

gUnknown_083399E4: ; 83399E4
	.incbin "base_emerald.gba", 0x3399e4, 0x3

gUnknown_083399E7: ; 83399E7
	.incbin "base_emerald.gba", 0x3399e7, 0x5

gUnknown_083399EC: ; 83399EC
	.incbin "base_emerald.gba", 0x3399ec, 0xd4

gUnknown_08339AC0: ; 8339AC0
	.incbin "base_emerald.gba", 0x339ac0, 0x8

gUnknown_08339AC8: ; 8339AC8
	.incbin "base_emerald.gba", 0x339ac8, 0x8

gUnknown_08339AD0: ; 8339AD0
	.incbin "base_emerald.gba", 0x339ad0, 0x8

gUnknown_08339AD8: ; 8339AD8
	.incbin "base_emerald.gba", 0x339ad8, 0x60

gUnknown_08339B38: ; 8339B38
	.incbin "base_emerald.gba", 0x339b38, 0x8

gUnknown_08339B40: ; 8339B40
	.incbin "base_emerald.gba", 0x339b40, 0x98

gUnknown_08339BD8: ; 8339BD8
	.incbin "base_emerald.gba", 0x339bd8, 0x8

gUnknown_08339BE0: ; 8339BE0
	.incbin "base_emerald.gba", 0x339be0, 0x44

gUnknown_08339C24: ; 8339C24
	.incbin "base_emerald.gba", 0x339c24, 0x8

gUnknown_08339C2C: ; 8339C2C
	.incbin "base_emerald.gba", 0x339c2c, 0x2c

gUnknown_08339C58: ; 8339C58
	.incbin "base_emerald.gba", 0x339c58, 0x8

gUnknown_08339C60: ; 8339C60
	.incbin "base_emerald.gba", 0x339c60, 0x18

gUnknown_08339C78: ; 8339C78
	.incbin "base_emerald.gba", 0x339c78, 0x28

gUnknown_08339CA0: ; 8339CA0
	.incbin "base_emerald.gba", 0x339ca0, 0x1e

gUnknown_08339CBE: ; 8339CBE
	.incbin "base_emerald.gba", 0x339cbe, 0x5

gUnknown_08339CC3: ; 8339CC3
	.incbin "base_emerald.gba", 0x339cc3, 0x5

gUnknown_08339CC8: ; 8339CC8
	.incbin "base_emerald.gba", 0x339cc8, 0x4c

gUnknown_08339D14: ; 8339D14
	.incbin "base_emerald.gba", 0x339d14, 0x8

gUnknown_08339D1C: ; 8339D1C
	.incbin "base_emerald.gba", 0x339d1c, 0x20

gUnknown_08339D3C: ; 8339D3C
	.incbin "base_emerald.gba", 0x339d3c, 0x28

gUnknown_08339D64: ; 8339D64
	.incbin "base_emerald.gba", 0x339d64, 0x48

gUnknown_08339DAC: ; 8339DAC
	.incbin "base_emerald.gba", 0x339dac, 0x10

gUnknown_08339DBC: ; 8339DBC
	.incbin "base_emerald.gba", 0x339dbc, 0xc

gUnknown_08339DC8: ; 8339DC8
	.incbin "base_emerald.gba", 0x339dc8, 0xc

gUnknown_08339DD4: ; 8339DD4
	.incbin "base_emerald.gba", 0x339dd4, 0x2c

gUnknown_08339E00: ; 8339E00
	.incbin "base_emerald.gba", 0x339e00, 0xa5e74

gUnknown_083DFC74: ; 83DFC74
	.incbin "base_emerald.gba", 0x3dfc74, 0x4

gUnknown_083DFC78: ; 83DFC78
	.incbin "base_emerald.gba", 0x3dfc78, 0xa215c

gUnknown_08481DD4: ; 8481DD4
	.incbin "base_emerald.gba", 0x481dd4, 0x47a4

gUnknown_08486578: ; 8486578
	.incbin "base_emerald.gba", 0x486578, 0x980

gUnknown_08486EF8: ; 8486EF8
	.incbin "base_emerald.gba", 0x486ef8, 0x4

gUnknown_08486EFC: ; 8486EFC
	.incbin "base_emerald.gba", 0x486efc, 0x10090

gUnknown_08496F8C: ; 8496F8C
	.incbin "base_emerald.gba", 0x496f8c, 0x14

gUnknown_08496FA0: ; 8496FA0
	.incbin "base_emerald.gba", 0x496fa0, 0x14

gUnknown_08496FB4: ; 8496FB4
	.incbin "base_emerald.gba", 0x496fb4, 0x1c0

gUnknown_08497174: ; 8497174
	.incbin "base_emerald.gba", 0x497174, 0x288

gUnknown_084973FC: ; 84973FC
	.incbin "base_emerald.gba", 0x4973fc, 0x48

gUnknown_08497444: ; 8497444
	.incbin "base_emerald.gba", 0x497444, 0x4c

gUnknown_08497490: ; 8497490
	.incbin "base_emerald.gba", 0x497490, 0xc

gUnknown_0849749C: ; 849749C
	.incbin "base_emerald.gba", 0x49749c, 0x14

gUnknown_084974B0: ; 84974B0
	.incbin "base_emerald.gba", 0x4974b0, 0x8

gUnknown_084974B8: ; 84974B8
	.incbin "base_emerald.gba", 0x4974b8, 0x20

gUnknown_084974D8: ; 84974D8
	.incbin "base_emerald.gba", 0x4974d8, 0x10

gUnknown_084974E8: ; 84974E8
	.incbin "base_emerald.gba", 0x4974e8, 0x10

gUnknown_084974F8: ; 84974F8
	.incbin "base_emerald.gba", 0x4974f8, 0x10

gUnknown_08497508: ; 8497508
	.incbin "base_emerald.gba", 0x497508, 0x2

gUnknown_0849750A: ; 849750A
	.incbin "base_emerald.gba", 0x49750a, 0x2

gUnknown_0849750C: ; 849750C
	.incbin "base_emerald.gba", 0x49750c, 0x14

gUnknown_08497520: ; 8497520
	.incbin "base_emerald.gba", 0x497520, 0x10

gUnknown_08497530: ; 8497530
	.incbin "base_emerald.gba", 0x497530, 0xc

gUnknown_0849753C: ; 849753C
	.incbin "base_emerald.gba", 0x49753c, 0x4

gUnknown_08497540: ; 8497540
	.incbin "base_emerald.gba", 0x497540, 0x10

gUnknown_08497550: ; 8497550
	.incbin "base_emerald.gba", 0x497550, 0x4

gUnknown_08497554: ; 8497554
	.incbin "base_emerald.gba", 0x497554, 0x8

gUnknown_0849755C: ; 849755C
	.incbin "base_emerald.gba", 0x49755c, 0x40

gUnknown_0849759C: ; 849759C
	.incbin "base_emerald.gba", 0x49759c, 0x6

gUnknown_084975A2: ; 84975A2
	.incbin "base_emerald.gba", 0x4975a2, 0x6

gUnknown_084975A8: ; 84975A8
	.incbin "base_emerald.gba", 0x4975a8, 0x2

gUnknown_084975AA: ; 84975AA
	.incbin "base_emerald.gba", 0x4975aa, 0x6

gUnknown_084975B0: ; 84975B0
	.incbin "base_emerald.gba", 0x4975b0, 0xc

gUnknown_084975BC: ; 84975BC
	.incbin "base_emerald.gba", 0x4975bc, 0x8

gUnknown_084975C4: ; 84975C4
	.incbin "base_emerald.gba", 0x4975c4, 0x10

gUnknown_084975D4: ; 84975D4
	.incbin "base_emerald.gba", 0x4975d4, 0x18

gUnknown_084975EC: ; 84975EC
	.incbin "base_emerald.gba", 0x4975ec, 0x120c

gUnknown_084987F8: ; 84987F8
	.incbin "base_emerald.gba", 0x4987f8, 0x1220

gUnknown_08499A18: ; 8499A18
	.incbin "base_emerald.gba", 0x499a18, 0xa860

gUnknown_084A4278: ; 84A4278
	.incbin "base_emerald.gba", 0x4a4278, 0x1240

gUnknown_084A54B8: ; 84A54B8
	.incbin "base_emerald.gba", 0x4a54b8, 0x5ff80

gUnknown_08505438: ; 8505438
	.incbin "base_emerald.gba", 0x505438, 0x144

gUnknown_0850557C: ; 850557C
	.incbin "base_emerald.gba", 0x50557c, 0x51

gUnknown_085055CD: ; 85055CD
	.incbin "base_emerald.gba", 0x5055cd, 0x53

gUnknown_08505620: ; 8505620
	.incbin "base_emerald.gba", 0x505620, 0x3bc

gUnknown_085059DC: ; 85059DC
	.incbin "base_emerald.gba", 0x5059dc, 0x1c

gUnknown_085059F8: ; 85059F8
	.incbin "base_emerald.gba", 0x5059f8, 0x3ab4

gUnknown_085094AC: ; 85094AC
	.incbin "base_emerald.gba", 0x5094ac, 0x271c

gUnknown_0850BBC8: ; 850BBC8
	.incbin "base_emerald.gba", 0x50bbc8, 0x138

gUnknown_0850BD00: ; 850BD00
	.incbin "base_emerald.gba", 0x50bd00, 0x78

gUnknown_0850BD78: ; 850BD78
	.incbin "base_emerald.gba", 0x50bd78, 0xc0

gUnknown_0850BE38: ; 850BE38
	.incbin "base_emerald.gba", 0x50be38, 0x978

gUnknown_0850C7B0: ; 850C7B0
	.incbin "base_emerald.gba", 0x50c7b0, 0xac

gUnknown_0850C85C: ; 850C85C
	.incbin "base_emerald.gba", 0x50c85c, 0xac

gUnknown_0850C908: ; 850C908
	.incbin "base_emerald.gba", 0x50c908, 0xc0

gUnknown_0850C9C8: ; 850C9C8
	.incbin "base_emerald.gba", 0x50c9c8, 0xd14

gUnknown_0850D6DC: ; 850D6DC
	.incbin "base_emerald.gba", 0x50d6dc, 0x10

gUnknown_0850D6EC: ; 850D6EC
	.incbin "base_emerald.gba", 0x50d6ec, 0x8

gUnknown_0850D6F4: ; 850D6F4
	.incbin "base_emerald.gba", 0x50d6f4, 0x1c

gUnknown_0850D710: ; 850D710
	.incbin "base_emerald.gba", 0x50d710, 0x4

gUnknown_0850D714: ; 850D714
	.incbin "base_emerald.gba", 0x50d714, 0x2c

gUnknown_0850D740: ; 850D740
	.incbin "base_emerald.gba", 0x50d740, 0x14

gUnknown_0850D754: ; 850D754
	.incbin "base_emerald.gba", 0x50d754, 0x1c

gUnknown_0850D770: ; 850D770
	.incbin "base_emerald.gba", 0x50d770, 0x4

gUnknown_0850D774: ; 850D774
	.incbin "base_emerald.gba", 0x50d774, 0x1c

gUnknown_0850D790: ; 850D790
	.incbin "base_emerald.gba", 0x50d790, 0x4

gUnknown_0850D794: ; 850D794
	.incbin "base_emerald.gba", 0x50d794, 0xc

gUnknown_0850D7A0: ; 850D7A0
	.incbin "base_emerald.gba", 0x50d7a0, 0x14

gUnknown_0850D7B4: ; 850D7B4
	.incbin "base_emerald.gba", 0x50d7b4, 0x14

gUnknown_0850D7C8: ; 850D7C8
	.incbin "base_emerald.gba", 0x50d7c8, 0x14

gUnknown_0850D7DC: ; 850D7DC
	.incbin "base_emerald.gba", 0x50d7dc, 0x14

gUnknown_0850D7F0: ; 850D7F0
	.incbin "base_emerald.gba", 0x50d7f0, 0x4

gUnknown_0850D7F4: ; 850D7F4
	.incbin "base_emerald.gba", 0x50d7f4, 0x14

gUnknown_0850D808: ; 850D808
	.incbin "base_emerald.gba", 0x50d808, 0x4

gUnknown_0850D80C: ; 850D80C
	.incbin "base_emerald.gba", 0x50d80c, 0x14

gUnknown_0850D820: ; 850D820
	.incbin "base_emerald.gba", 0x50d820, 0x4

gUnknown_0850D824: ; 850D824
	.incbin "base_emerald.gba", 0x50d824, 0x14

gUnknown_0850D838: ; 850D838
	.incbin "base_emerald.gba", 0x50d838, 0x4

gUnknown_0850D83C: ; 850D83C
	.incbin "base_emerald.gba", 0x50d83c, 0x14

gUnknown_0850D850: ; 850D850
	.incbin "base_emerald.gba", 0x50d850, 0x4

gUnknown_0850D854: ; 850D854
	.incbin "base_emerald.gba", 0x50d854, 0x14

gUnknown_0850D868: ; 850D868
	.incbin "base_emerald.gba", 0x50d868, 0x4

gUnknown_0850D86C: ; 850D86C
	.incbin "base_emerald.gba", 0x50d86c, 0x14

gUnknown_0850D880: ; 850D880
	.incbin "base_emerald.gba", 0x50d880, 0x4

gUnknown_0850D884: ; 850D884
	.incbin "base_emerald.gba", 0x50d884, 0x14

gUnknown_0850D898: ; 850D898
	.incbin "base_emerald.gba", 0x50d898, 0x4

gUnknown_0850D89C: ; 850D89C
	.incbin "base_emerald.gba", 0x50d89c, 0x10

gUnknown_0850D8AC: ; 850D8AC
	.incbin "base_emerald.gba", 0x50d8ac, 0x8

gUnknown_0850D8B4: ; 850D8B4
	.incbin "base_emerald.gba", 0x50d8b4, 0x10

gUnknown_0850D8C4: ; 850D8C4
	.incbin "base_emerald.gba", 0x50d8c4, 0x8

gUnknown_0850D8CC: ; 850D8CC
	.incbin "base_emerald.gba", 0x50d8cc, 0x10

gUnknown_0850D8DC: ; 850D8DC
	.incbin "base_emerald.gba", 0x50d8dc, 0xc

gUnknown_0850D8E8: ; 850D8E8
	.incbin "base_emerald.gba", 0x50d8e8, 0x4

gUnknown_0850D8EC: ; 850D8EC
	.incbin "base_emerald.gba", 0x50d8ec, 0xc

gUnknown_0850D8F8: ; 850D8F8
	.incbin "base_emerald.gba", 0x50d8f8, 0x4

gUnknown_0850D8FC: ; 850D8FC
	.incbin "base_emerald.gba", 0x50d8fc, 0xc

gUnknown_0850D908: ; 850D908
	.incbin "base_emerald.gba", 0x50d908, 0x4

gUnknown_0850D90C: ; 850D90C
	.incbin "base_emerald.gba", 0x50d90c, 0xc

gUnknown_0850D918: ; 850D918
	.incbin "base_emerald.gba", 0x50d918, 0x4

gUnknown_0850D91C: ; 850D91C
	.incbin "base_emerald.gba", 0x50d91c, 0xc

gUnknown_0850D928: ; 850D928
	.incbin "base_emerald.gba", 0x50d928, 0x4

gUnknown_0850D92C: ; 850D92C
	.incbin "base_emerald.gba", 0x50d92c, 0xc

gUnknown_0850D938: ; 850D938
	.incbin "base_emerald.gba", 0x50d938, 0x4

gUnknown_0850D93C: ; 850D93C
	.incbin "base_emerald.gba", 0x50d93c, 0xc

gUnknown_0850D948: ; 850D948
	.incbin "base_emerald.gba", 0x50d948, 0xc

gUnknown_0850D954: ; 850D954
	.incbin "base_emerald.gba", 0x50d954, 0x4

gUnknown_0850D958: ; 850D958
	.incbin "base_emerald.gba", 0x50d958, 0xc

gUnknown_0850D964: ; 850D964
	.incbin "base_emerald.gba", 0x50d964, 0x4

gUnknown_0850D968: ; 850D968
	.incbin "base_emerald.gba", 0x50d968, 0xc

gUnknown_0850D974: ; 850D974
	.incbin "base_emerald.gba", 0x50d974, 0x4

gUnknown_0850D978: ; 850D978
	.incbin "base_emerald.gba", 0x50d978, 0xc

gUnknown_0850D984: ; 850D984
	.incbin "base_emerald.gba", 0x50d984, 0x4

gUnknown_0850D988: ; 850D988
	.incbin "base_emerald.gba", 0x50d988, 0xc

gUnknown_0850D994: ; 850D994
	.incbin "base_emerald.gba", 0x50d994, 0x4

gUnknown_0850D998: ; 850D998
	.incbin "base_emerald.gba", 0x50d998, 0xc

gUnknown_0850D9A4: ; 850D9A4
	.incbin "base_emerald.gba", 0x50d9a4, 0x4

gUnknown_0850D9A8: ; 850D9A8
	.incbin "base_emerald.gba", 0x50d9a8, 0xc

gUnknown_0850D9B4: ; 850D9B4
	.incbin "base_emerald.gba", 0x50d9b4, 0x4

gUnknown_0850D9B8: ; 850D9B8
	.incbin "base_emerald.gba", 0x50d9b8, 0xc

gUnknown_0850D9C4: ; 850D9C4
	.incbin "base_emerald.gba", 0x50d9c4, 0x4

gUnknown_0850D9C8: ; 850D9C8
	.incbin "base_emerald.gba", 0x50d9c8, 0xc

gUnknown_0850D9D4: ; 850D9D4
	.incbin "base_emerald.gba", 0x50d9d4, 0x4

gUnknown_0850D9D8: ; 850D9D8
	.incbin "base_emerald.gba", 0x50d9d8, 0xc

gUnknown_0850D9E4: ; 850D9E4
	.incbin "base_emerald.gba", 0x50d9e4, 0x4

gUnknown_0850D9E8: ; 850D9E8
	.incbin "base_emerald.gba", 0x50d9e8, 0xc

gUnknown_0850D9F4: ; 850D9F4
	.incbin "base_emerald.gba", 0x50d9f4, 0x4

gUnknown_0850D9F8: ; 850D9F8
	.incbin "base_emerald.gba", 0x50d9f8, 0xc

gUnknown_0850DA04: ; 850DA04
	.incbin "base_emerald.gba", 0x50da04, 0x4

gUnknown_0850DA08: ; 850DA08
	.incbin "base_emerald.gba", 0x50da08, 0xc

gUnknown_0850DA14: ; 850DA14
	.incbin "base_emerald.gba", 0x50da14, 0x4

gUnknown_0850DA18: ; 850DA18
	.incbin "base_emerald.gba", 0x50da18, 0xc

gUnknown_0850DA24: ; 850DA24
	.incbin "base_emerald.gba", 0x50da24, 0x4

gUnknown_0850DA28: ; 850DA28
	.incbin "base_emerald.gba", 0x50da28, 0xc

gUnknown_0850DA34: ; 850DA34
	.incbin "base_emerald.gba", 0x50da34, 0x4

gUnknown_0850DA38: ; 850DA38
	.incbin "base_emerald.gba", 0x50da38, 0xc

gUnknown_0850DA44: ; 850DA44
	.incbin "base_emerald.gba", 0x50da44, 0x4

gUnknown_0850DA48: ; 850DA48
	.incbin "base_emerald.gba", 0x50da48, 0xc

gUnknown_0850DA54: ; 850DA54
	.incbin "base_emerald.gba", 0x50da54, 0x4

gUnknown_0850DA58: ; 850DA58
	.incbin "base_emerald.gba", 0x50da58, 0xc

gUnknown_0850DA64: ; 850DA64
	.incbin "base_emerald.gba", 0x50da64, 0x2c

gUnknown_0850DA90: ; 850DA90
	.incbin "base_emerald.gba", 0x50da90, 0xc

gUnknown_0850DA9C: ; 850DA9C
	.incbin "base_emerald.gba", 0x50da9c, 0x4

gUnknown_0850DAA0: ; 850DAA0
	.incbin "base_emerald.gba", 0x50daa0, 0x8

gUnknown_0850DAA8: ; 850DAA8
	.incbin "base_emerald.gba", 0x50daa8, 0x8

gUnknown_0850DAB0: ; 850DAB0
	.incbin "base_emerald.gba", 0x50dab0, 0x8

gUnknown_0850DAB8: ; 850DAB8
	.incbin "base_emerald.gba", 0x50dab8, 0x8

gUnknown_0850DAC0: ; 850DAC0
	.incbin "base_emerald.gba", 0x50dac0, 0xc

gUnknown_0850DACC: ; 850DACC
	.incbin "base_emerald.gba", 0x50dacc, 0x9

gUnknown_0850DAD5: ; 850DAD5
	.incbin "base_emerald.gba", 0x50dad5, 0x9

gUnknown_0850DADE: ; 850DADE
	.incbin "base_emerald.gba", 0x50dade, 0x9

gUnknown_0850DAE7: ; 850DAE7
	.incbin "base_emerald.gba", 0x50dae7, 0x9

gUnknown_0850DAF0: ; 850DAF0
	.incbin "base_emerald.gba", 0x50daf0, 0x9

gUnknown_0850DAF9: ; 850DAF9
	.incbin "base_emerald.gba", 0x50daf9, 0x9

gUnknown_0850DB02: ; 850DB02
	.incbin "base_emerald.gba", 0x50db02, 0x9

gUnknown_0850DB0B: ; 850DB0B
	.incbin "base_emerald.gba", 0x50db0b, 0x9

gUnknown_0850DB14: ; 850DB14
	.incbin "base_emerald.gba", 0x50db14, 0x9

gUnknown_0850DB1D: ; 850DB1D
	.incbin "base_emerald.gba", 0x50db1d, 0x9

gUnknown_0850DB26: ; 850DB26
	.incbin "base_emerald.gba", 0x50db26, 0x9

gUnknown_0850DB2F: ; 850DB2F
	.incbin "base_emerald.gba", 0x50db2f, 0x9

gUnknown_0850DB38: ; 850DB38
	.incbin "base_emerald.gba", 0x50db38, 0x9

gUnknown_0850DB41: ; 850DB41
	.incbin "base_emerald.gba", 0x50db41, 0x9

gUnknown_0850DB4A: ; 850DB4A
	.incbin "base_emerald.gba", 0x50db4a, 0x9

gUnknown_0850DB53: ; 850DB53
	.incbin "base_emerald.gba", 0x50db53, 0x9

gUnknown_0850DB5C: ; 850DB5C
	.incbin "base_emerald.gba", 0x50db5c, 0x10

gUnknown_0850DB6C: ; 850DB6C
	.incbin "base_emerald.gba", 0x50db6c, 0x10

gUnknown_0850DB7C: ; 850DB7C
	.incbin "base_emerald.gba", 0x50db7c, 0x24

gUnknown_0850DBA0: ; 850DBA0
	.incbin "base_emerald.gba", 0x50dba0, 0x5

gUnknown_0850DBA5: ; 850DBA5
	.incbin "base_emerald.gba", 0x50dba5, 0x5

gUnknown_0850DBAA: ; 850DBAA
	.incbin "base_emerald.gba", 0x50dbaa, 0x5

gUnknown_0850DBAF: ; 850DBAF
	.incbin "base_emerald.gba", 0x50dbaf, 0x5

gUnknown_0850DBB4: ; 850DBB4
	.incbin "base_emerald.gba", 0x50dbb4, 0x5

gUnknown_0850DBB9: ; 850DBB9
	.incbin "base_emerald.gba", 0x50dbb9, 0x5

gUnknown_0850DBBE: ; 850DBBE
	.incbin "base_emerald.gba", 0x50dbbe, 0x5

gUnknown_0850DBC3: ; 850DBC3
	.incbin "base_emerald.gba", 0x50dbc3, 0x5

gUnknown_0850DBC8: ; 850DBC8
	.incbin "base_emerald.gba", 0x50dbc8, 0x5

gUnknown_0850DBCD: ; 850DBCD
	.incbin "base_emerald.gba", 0x50dbcd, 0x5

gUnknown_0850DBD2: ; 850DBD2
	.incbin "base_emerald.gba", 0x50dbd2, 0x5

gUnknown_0850DBD7: ; 850DBD7
	.incbin "base_emerald.gba", 0x50dbd7, 0x5

gUnknown_0850DBDC: ; 850DBDC
	.incbin "base_emerald.gba", 0x50dbdc, 0x5

gUnknown_0850DBE1: ; 850DBE1
	.incbin "base_emerald.gba", 0x50dbe1, 0x5

gUnknown_0850DBE6: ; 850DBE6
	.incbin "base_emerald.gba", 0x50dbe6, 0x5

gUnknown_0850DBEB: ; 850DBEB
	.incbin "base_emerald.gba", 0x50dbeb, 0x5

gUnknown_0850DBF0: ; 850DBF0
	.incbin "base_emerald.gba", 0x50dbf0, 0x5

gUnknown_0850DBF5: ; 850DBF5
	.incbin "base_emerald.gba", 0x50dbf5, 0x5

gUnknown_0850DBFA: ; 850DBFA
	.incbin "base_emerald.gba", 0x50dbfa, 0x5

gUnknown_0850DBFF: ; 850DBFF
	.incbin "base_emerald.gba", 0x50dbff, 0x5

gUnknown_0850DC04: ; 850DC04
	.incbin "base_emerald.gba", 0x50dc04, 0x5

gUnknown_0850DC09: ; 850DC09
	.incbin "base_emerald.gba", 0x50dc09, 0x5

gUnknown_0850DC0E: ; 850DC0E
	.incbin "base_emerald.gba", 0x50dc0e, 0x5

gUnknown_0850DC13: ; 850DC13
	.incbin "base_emerald.gba", 0x50dc13, 0x5

gUnknown_0850DC18: ; 850DC18
	.incbin "base_emerald.gba", 0x50dc18, 0x5

gUnknown_0850DC1D: ; 850DC1D
	.incbin "base_emerald.gba", 0x50dc1d, 0x5

gUnknown_0850DC22: ; 850DC22
	.incbin "base_emerald.gba", 0x50dc22, 0x5

gUnknown_0850DC27: ; 850DC27
	.incbin "base_emerald.gba", 0x50dc27, 0x8

gUnknown_0850DC2F: ; 850DC2F
	.incbin "base_emerald.gba", 0x50dc2f, 0x10

gUnknown_0850DC3F: ; 850DC3F
	.incbin "base_emerald.gba", 0x50dc3f, 0x11

gUnknown_0850DC50: ; 850DC50
	.incbin "base_emerald.gba", 0x50dc50, 0x298

gUnknown_0850DEE8: ; 850DEE8
	.incbin "base_emerald.gba", 0x50dee8, 0xd4

gUnknown_0850DFBC: ; 850DFBC
	.incbin "base_emerald.gba", 0x50dfbc, 0x6

gUnknown_0850DFC2: ; 850DFC2
	.incbin "base_emerald.gba", 0x50dfc2, 0x61a

gUnknown_0850E5DC: ; 850E5DC
	.incbin "base_emerald.gba", 0x50e5dc, 0x8

gUnknown_0850E5E4: ; 850E5E4
	.incbin "base_emerald.gba", 0x50e5e4, 0x18

gUnknown_0850E5FC: ; 850E5FC
	.incbin "base_emerald.gba", 0x50e5fc, 0x18

gUnknown_0850E614: ; 850E614
	.incbin "base_emerald.gba", 0x50e614, 0x10

gUnknown_0850E624: ; 850E624
	.incbin "base_emerald.gba", 0x50e624, 0x10

gUnknown_0850E634: ; 850E634
	.incbin "base_emerald.gba", 0x50e634, 0x10

gUnknown_0850E644: ; 850E644
	.incbin "base_emerald.gba", 0x50e644, 0x10

gUnknown_0850E654: ; 850E654
	.incbin "base_emerald.gba", 0x50e654, 0xc

gUnknown_0850E660: ; 850E660
	.incbin "base_emerald.gba", 0x50e660, 0x4

gUnknown_0850E664: ; 850E664
	.incbin "base_emerald.gba", 0x50e664, 0x10

gUnknown_0850E674: ; 850E674
	.incbin "base_emerald.gba", 0x50e674, 0xe0

gUnknown_0850E754: ; 850E754
	.incbin "base_emerald.gba", 0x50e754, 0x14

gUnknown_0850E768: ; 850E768
	.incbin "base_emerald.gba", 0x50e768, 0xa

gUnknown_0850E772: ; 850E772
	.incbin "base_emerald.gba", 0x50e772, 0x48

gUnknown_0850E7BA: ; 850E7BA
	.incbin "base_emerald.gba", 0x50e7ba, 0x7a

gUnknown_0850E834: ; 850E834
	.incbin "base_emerald.gba", 0x50e834, 0xc

gUnknown_0850E840: ; 850E840
	.incbin "base_emerald.gba", 0x50e840, 0x6

gUnknown_0850E846: ; 850E846
	.incbin "base_emerald.gba", 0x50e846, 0x4

gUnknown_0850E84A: ; 850E84A
	.incbin "base_emerald.gba", 0x50e84a, 0x6

gUnknown_0850E850: ; 850E850
	.incbin "base_emerald.gba", 0x50e850, 0x2c

gUnknown_0850E87C: ; 850E87C
	.incbin "base_emerald.gba", 0x50e87c, 0x1680

gUnknown_0850FEFC: ; 850FEFC
	.incbin "base_emerald.gba", 0x50fefc, 0x280

gUnknown_0851017C: ; 851017C
	.incbin "base_emerald.gba", 0x51017c, 0xa0

gUnknown_0851021C: ; 851021C
	.incbin "base_emerald.gba", 0x51021c, 0xa0

gUnknown_085102BC: ; 85102BC
	.incbin "base_emerald.gba", 0x5102bc, 0x4

gUnknown_085102C0: ; 85102C0
	.incbin "base_emerald.gba", 0x5102c0, 0x14

gUnknown_085102D4: ; 85102D4
	.incbin "base_emerald.gba", 0x5102d4, 0xc

gUnknown_085102E0: ; 85102E0
	.incbin "base_emerald.gba", 0x5102e0, 0x68

gUnknown_08510348: ; 8510348
	.incbin "base_emerald.gba", 0x510348, 0x20

gUnknown_08510368: ; 8510368
	.incbin "base_emerald.gba", 0x510368, 0x20

gUnknown_08510388: ; 8510388
	.incbin "base_emerald.gba", 0x510388, 0x20

gUnknown_085103A8: ; 85103A8
	.incbin "base_emerald.gba", 0x5103a8, 0x20

gUnknown_085103C8: ; 85103C8
	.incbin "base_emerald.gba", 0x5103c8, 0x34

gUnknown_085103FC: ; 85103FC
	.incbin "base_emerald.gba", 0x5103fc, 0x8

gUnknown_08510404: ; 8510404
	.incbin "base_emerald.gba", 0x510404, 0x4

gUnknown_08510408: ; 8510408
	.incbin "base_emerald.gba", 0x510408, 0x14

gUnknown_0851041C: ; 851041C
	.incbin "base_emerald.gba", 0x51041c, 0x4

gUnknown_08510420: ; 8510420
	.incbin "base_emerald.gba", 0x510420, 0xa4

gUnknown_085104C4: ; 85104C4
	.incbin "base_emerald.gba", 0x5104c4, 0x2c

gUnknown_085104F0: ; 85104F0
	.incbin "base_emerald.gba", 0x5104f0, 0x18

gUnknown_08510508: ; 8510508
	.incbin "base_emerald.gba", 0x510508, 0x8

gUnknown_08510510: ; 8510510
	.incbin "base_emerald.gba", 0x510510, 0x20

gUnknown_08510530: ; 8510530
	.incbin "base_emerald.gba", 0x510530, 0x8

gUnknown_08510538: ; 8510538
	.incbin "base_emerald.gba", 0x510538, 0x8

gUnknown_08510540: ; 8510540
	.incbin "base_emerald.gba", 0x510540, 0x68

gUnknown_085105A8: ; 85105A8
	.incbin "base_emerald.gba", 0x5105a8, 0x4

gUnknown_085105AC: ; 85105AC
	.incbin "base_emerald.gba", 0x5105ac, 0x10

gUnknown_085105BC: ; 85105BC
	.incbin "base_emerald.gba", 0x5105bc, 0x1a8

gUnknown_08510764: ; 8510764
	.incbin "base_emerald.gba", 0x510764, 0xb60

gUnknown_085112C4: ; 85112C4
	.incbin "base_emerald.gba", 0x5112c4, 0x908

gUnknown_08511BCC: ; 8511BCC
	.incbin "base_emerald.gba", 0x511bcc, 0x9a8

gUnknown_08512574: ; 8512574
	.incbin "base_emerald.gba", 0x512574, 0x8e0

gUnknown_08512E54: ; 8512E54
	.incbin "base_emerald.gba", 0x512e54, 0x320

gUnknown_08513174: ; 8513174
	.incbin "base_emerald.gba", 0x513174, 0x510

gUnknown_08513684: ; 8513684
	.incbin "base_emerald.gba", 0x513684, 0x210

gUnknown_08513894: ; 8513894
	.incbin "base_emerald.gba", 0x513894, 0xb50

gUnknown_085143E4: ; 85143E4
	.incbin "base_emerald.gba", 0x5143e4, 0x210

gUnknown_085145F4: ; 85145F4
	.incbin "base_emerald.gba", 0x5145f4, 0x810

gUnknown_08514E04: ; 8514E04
	.incbin "base_emerald.gba", 0x514e04, 0x540

gUnknown_08515344: ; 8515344
	.incbin "base_emerald.gba", 0x515344, 0x20

gUnknown_08515364: ; 8515364
	.incbin "base_emerald.gba", 0x515364, 0x20

gUnknown_08515384: ; 8515384
	.incbin "base_emerald.gba", 0x515384, 0x30

gUnknown_085153B4: ; 85153B4
	.incbin "base_emerald.gba", 0x5153b4, 0x30

gUnknown_085153E4: ; 85153E4
	.incbin "base_emerald.gba", 0x5153e4, 0x10

gUnknown_085153F4: ; 85153F4
	.incbin "base_emerald.gba", 0x5153f4, 0x410

gUnknown_08515804: ; 8515804
	.incbin "base_emerald.gba", 0x515804, 0x20

gUnknown_08515824: ; 8515824
	.incbin "base_emerald.gba", 0x515824, 0x140

gUnknown_08515964: ; 8515964
	.incbin "base_emerald.gba", 0x515964, 0x428

gUnknown_08515D8C: ; 8515D8C
	.incbin "base_emerald.gba", 0x515d8c, 0x430

gUnknown_085161BC: ; 85161BC
	.incbin "base_emerald.gba", 0x5161bc, 0x20

gUnknown_085161DC: ; 85161DC
	.incbin "base_emerald.gba", 0x5161dc, 0x320

gUnknown_085164FC: ; 85164FC
	.incbin "base_emerald.gba", 0x5164fc, 0x310

gUnknown_0851680C: ; 851680C
	.incbin "base_emerald.gba", 0x51680c, 0x310

gUnknown_08516B1C: ; 8516B1C
	.incbin "base_emerald.gba", 0x516b1c, 0x210

gUnknown_08516D2C: ; 8516D2C
	.incbin "base_emerald.gba", 0x516d2c, 0x110

gUnknown_08516E3C: ; 8516E3C
	.incbin "base_emerald.gba", 0x516e3c, 0xc08

gUnknown_08517A44: ; 8517A44
	.incbin "base_emerald.gba", 0x517a44, 0xc

gUnknown_08517A50: ; 8517A50
	.incbin "base_emerald.gba", 0x517a50, 0x1ac

gUnknown_08517BFC: ; 8517BFC
	.incbin "base_emerald.gba", 0x517bfc, 0x10

gUnknown_08517C0C: ; 8517C0C
	.incbin "base_emerald.gba", 0x517c0c, 0x428

gUnknown_08518034: ; 8518034
	.incbin "base_emerald.gba", 0x518034, 0x268

gUnknown_0851829C: ; 851829C
	.incbin "base_emerald.gba", 0x51829c, 0x8028

gUnknown_085202C4: ; 85202C4
	.incbin "base_emerald.gba", 0x5202c4, 0x45a0

gUnknown_08524864: ; 8524864
	.incbin "base_emerald.gba", 0x524864, 0xc

gUnknown_08524870: ; 8524870
	.incbin "base_emerald.gba", 0x524870, 0xc

gUnknown_0852487C: ; 852487C
	.incbin "base_emerald.gba", 0x52487c, 0x10

gUnknown_0852488C: ; 852488C
	.incbin "base_emerald.gba", 0x52488c, 0x10

gUnknown_0852489C: ; 852489C
	.incbin "base_emerald.gba", 0x52489c, 0x20

gUnknown_085248BC: ; 85248BC
	.incbin "base_emerald.gba", 0x5248bc, 0x288

gUnknown_08524B44: ; 8524B44
	.incbin "base_emerald.gba", 0x524b44, 0x1d0

gUnknown_08524D14: ; 8524D14
	.incbin "base_emerald.gba", 0x524d14, 0x270

gUnknown_08524F84: ; 8524F84
	.incbin "base_emerald.gba", 0x524f84, 0x308

gUnknown_0852528C: ; 852528C
	.incbin "base_emerald.gba", 0x52528c, 0x120

gUnknown_085253AC: ; 85253AC
	.incbin "base_emerald.gba", 0x5253ac, 0x270

gUnknown_0852561C: ; 852561C
	.incbin "base_emerald.gba", 0x52561c, 0x270

gUnknown_0852588C: ; 852588C
	.incbin "base_emerald.gba", 0x52588c, 0x308

gUnknown_08525B94: ; 8525B94
	.incbin "base_emerald.gba", 0x525b94, 0x120

gUnknown_08525CB4: ; 8525CB4
	.incbin "base_emerald.gba", 0x525cb4, 0xa0

gUnknown_08525D54: ; 8525D54
	.incbin "base_emerald.gba", 0x525d54, 0x144

gUnknown_08525E98: ; 8525E98
	.incbin "base_emerald.gba", 0x525e98, 0xc0

gUnknown_08525F58: ; 8525F58
	.incbin "base_emerald.gba", 0x525f58, 0x20

gUnknown_08525F78: ; 8525F78
	.incbin "base_emerald.gba", 0x525f78, 0x10

gUnknown_08525F88: ; 8525F88
	.incbin "base_emerald.gba", 0x525f88, 0x4

gUnknown_08525F8C: ; 8525F8C
	.incbin "base_emerald.gba", 0x525f8c, 0x4

gUnknown_08525F90: ; 8525F90
	.incbin "base_emerald.gba", 0x525f90, 0x30

gUnknown_08525FC0: ; 8525FC0
	.incbin "base_emerald.gba", 0x525fc0, 0x18f80

gUnknown_0853EF40: ; 853EF40
	.incbin "base_emerald.gba", 0x53ef40, 0x8

gUnknown_0853EF48: ; 853EF48
	.incbin "base_emerald.gba", 0x53ef48, 0x18

gUnknown_0853EF60: ; 853EF60
	.incbin "base_emerald.gba", 0x53ef60, 0xf8

gUnknown_0853F058: ; 853F058
	.incbin "base_emerald.gba", 0x53f058, 0x7e4

gUnknown_0853F83C: ; 853F83C
	.incbin "base_emerald.gba", 0x53f83c, 0x450

gUnknown_0853FC8C: ; 853FC8C
	.incbin "base_emerald.gba", 0x53fc8c, 0x2e4

gUnknown_0853FF70: ; 853FF70
	.incbin "base_emerald.gba", 0x53ff70, 0xa8

gUnknown_08540018: ; 8540018
	.incbin "base_emerald.gba", 0x540018, 0x18

gUnknown_08540030: ; 8540030
	.incbin "base_emerald.gba", 0x540030, 0x18

gUnknown_08540048: ; 8540048
	.incbin "base_emerald.gba", 0x540048, 0x90

gUnknown_085400D8: ; 85400D8
	.incbin "base_emerald.gba", 0x5400d8, 0x18

gUnknown_085400F0: ; 85400F0
	.incbin "base_emerald.gba", 0x5400f0, 0x10

gUnknown_08540100: ; 8540100
	.incbin "base_emerald.gba", 0x540100, 0x24

gUnknown_08540124: ; 8540124
	.incbin "base_emerald.gba", 0x540124, 0x18

gUnknown_0854013C: ; 854013C
	.incbin "base_emerald.gba", 0x54013c, 0x10

gUnknown_0854014C: ; 854014C
	.incbin "base_emerald.gba", 0x54014c, 0xc000

gUnknown_0854C14C: ; 854C14C
	.incbin "base_emerald.gba", 0x54c14c, 0x4

gUnknown_0854C150: ; 854C150
	.incbin "base_emerald.gba", 0x54c150, 0xf0

gUnknown_0854C240: ; 854C240
	.incbin "base_emerald.gba", 0x54c240, 0x10

gUnknown_0854C250: ; 854C250
	.incbin "base_emerald.gba", 0x54c250, 0x20

gUnknown_0854C270: ; 854C270
	.incbin "base_emerald.gba", 0x54c270, 0x20

gUnknown_0854C290: ; 854C290
	.incbin "base_emerald.gba", 0x54c290, 0x20

gUnknown_0854C2B0: ; 854C2B0
	.incbin "base_emerald.gba", 0x54c2b0, 0x820

gUnknown_0854CAD0: ; 854CAD0
	.incbin "base_emerald.gba", 0x54cad0, 0x3080

gUnknown_0854FB50: ; 854FB50
	.incbin "base_emerald.gba", 0x54fb50, 0xc

gUnknown_0854FB5C: ; 854FB5C
	.incbin "base_emerald.gba", 0x54fb5c, 0x1c

gUnknown_0854FB78: ; 854FB78
	.incbin "base_emerald.gba", 0x54fb78, 0x18

gUnknown_0854FB90: ; 854FB90
	.incbin "base_emerald.gba", 0x54fb90, 0x9c

gUnknown_0854FC2C: ; 854FC2C
	.incbin "base_emerald.gba", 0x54fc2c, 0x18

gUnknown_0854FC44: ; 854FC44
	.incbin "base_emerald.gba", 0x54fc44, 0x8

gUnknown_0854FC4C: ; 854FC4C
	.incbin "base_emerald.gba", 0x54fc4c, 0x8

gUnknown_0854FC54: ; 854FC54
	.incbin "base_emerald.gba", 0x54fc54, 0x38

gUnknown_0854FC8C: ; 854FC8C
	.incbin "base_emerald.gba", 0x54fc8c, 0x8c

gUnknown_0854FD18: ; 854FD18
	.incbin "base_emerald.gba", 0x54fd18, 0x18

gUnknown_0854FD30: ; 854FD30
	.incbin "base_emerald.gba", 0x54fd30, 0x8

gUnknown_0854FD38: ; 854FD38
	.incbin "base_emerald.gba", 0x54fd38, 0x20

gUnknown_0854FD58: ; 854FD58
	.incbin "base_emerald.gba", 0x54fd58, 0x18

gUnknown_0854FD70: ; 854FD70
	.incbin "base_emerald.gba", 0x54fd70, 0x1c

gUnknown_0854FD8C: ; 854FD8C
	.incbin "base_emerald.gba", 0x54fd8c, 0x38

gUnknown_0854FDC4: ; 854FDC4
	.incbin "base_emerald.gba", 0x54fdc4, 0x18

gUnknown_0854FDDC: ; 854FDDC
	.incbin "base_emerald.gba", 0x54fddc, 0x8

gUnknown_0854FDE4: ; 854FDE4
	.incbin "base_emerald.gba", 0x54fde4, 0xc

gUnknown_0854FDF0: ; 854FDF0
	.incbin "base_emerald.gba", 0x54fdf0, 0x8

gUnknown_0854FDF8: ; 854FDF8
	.incbin "base_emerald.gba", 0x54fdf8, 0x8

gUnknown_0854FE00: ; 854FE00
	.incbin "base_emerald.gba", 0x54fe00, 0x44

gUnknown_0854FE44: ; 854FE44
	.incbin "base_emerald.gba", 0x54fe44, 0x18

gUnknown_0854FE5C: ; 854FE5C
	.incbin "base_emerald.gba", 0x54fe5c, 0x4

gUnknown_0854FE60: ; 854FE60
	.incbin "base_emerald.gba", 0x54fe60, 0x4

gUnknown_0854FE64: ; 854FE64
	.incbin "base_emerald.gba", 0x54fe64, 0x14

gUnknown_0854FE78: ; 854FE78
	.incbin "base_emerald.gba", 0x54fe78, 0x4

gUnknown_0854FE7C: ; 854FE7C
	.incbin "base_emerald.gba", 0x54fe7c, 0xc

gUnknown_0854FE88: ; 854FE88
	.incbin "base_emerald.gba", 0x54fe88, 0x8

gUnknown_0854FE90: ; 854FE90
	.incbin "base_emerald.gba", 0x54fe90, 0x8

gUnknown_0854FE98: ; 854FE98
	.incbin "base_emerald.gba", 0x54fe98, 0xc

gUnknown_0854FEA4: ; 854FEA4
	.incbin "base_emerald.gba", 0x54fea4, 0x3

gUnknown_0854FEA7: ; 854FEA7
	.incbin "base_emerald.gba", 0x54fea7, 0x5

gUnknown_0854FEAC: ; 854FEAC
	.incbin "base_emerald.gba", 0x54feac, 0x48

gUnknown_0854FEF4: ; 854FEF4
	.incbin "base_emerald.gba", 0x54fef4, 0x48

gUnknown_0854FF3C: ; 854FF3C
	.incbin "base_emerald.gba", 0x54ff3c, 0x48

gUnknown_0854FF84: ; 854FF84
	.incbin "base_emerald.gba", 0x54ff84, 0x48

gUnknown_0854FFCC: ; 854FFCC
	.incbin "base_emerald.gba", 0x54ffcc, 0x48

gUnknown_08550014: ; 8550014
	.incbin "base_emerald.gba", 0x550014, 0x48

gUnknown_0855005C: ; 855005C
	.incbin "base_emerald.gba", 0x55005c, 0x48

gUnknown_085500A4: ; 85500A4
	.incbin "base_emerald.gba", 0x5500a4, 0x4e0

gUnknown_08550584: ; 8550584
	.incbin "base_emerald.gba", 0x550584, 0x10

gUnknown_08550594: ; 8550594
	.incbin "base_emerald.gba", 0x550594, 0x8

gUnknown_0855059C: ; 855059C
	.incbin "base_emerald.gba", 0x55059c, 0x190

gUnknown_0855072C: ; 855072C
	.incbin "base_emerald.gba", 0x55072c, 0x10

gUnknown_0855073C: ; 855073C
	.incbin "base_emerald.gba", 0x55073c, 0x30

gUnknown_0855076C: ; 855076C
	.incbin "base_emerald.gba", 0x55076c, 0x48

gUnknown_085507B4: ; 85507B4
	.incbin "base_emerald.gba", 0x5507b4, 0x18

gUnknown_085507CC: ; 85507CC
	.incbin "base_emerald.gba", 0x5507cc, 0x257c

gUnknown_08552D48: ; 8552D48
	.incbin "base_emerald.gba", 0x552d48, 0xb4c

gUnknown_08553894: ; 8553894
	.incbin "base_emerald.gba", 0x553894, 0x180

gUnknown_08553A14: ; 8553A14
	.incbin "base_emerald.gba", 0x553a14, 0x64

gUnknown_08553A78: ; 8553A78
	.incbin "base_emerald.gba", 0x553a78, 0x4

gUnknown_08553A7C: ; 8553A7C
	.incbin "base_emerald.gba", 0x553a7c, 0x73d4

gUnknown_0855AE50: ; 855AE50
	.incbin "base_emerald.gba", 0x55ae50, 0x200

gUnknown_0855B050: ; 855B050
	.incbin "base_emerald.gba", 0x55b050, 0x20

gUnknown_0855B070: ; 855B070
	.incbin "base_emerald.gba", 0x55b070, 0x280

gUnknown_0855B2F0: ; 855B2F0
	.incbin "base_emerald.gba", 0x55b2f0, 0x80

gUnknown_0855B370: ; 855B370
	.incbin "base_emerald.gba", 0x55b370, 0x20

gUnknown_0855B390: ; 855B390
	.incbin "base_emerald.gba", 0x55b390, 0x280

gUnknown_0855B610: ; 855B610
	.incbin "base_emerald.gba", 0x55b610, 0x20

gUnknown_0855B630: ; 855B630
	.incbin "base_emerald.gba", 0x55b630, 0xbc0

gUnknown_0855C1F0: ; 855C1F0
	.incbin "base_emerald.gba", 0x55c1f0, 0x20

gUnknown_0855C210: ; 855C210
	.incbin "base_emerald.gba", 0x55c210, 0x20

gUnknown_0855C230: ; 855C230
	.incbin "base_emerald.gba", 0x55c230, 0x14

gUnknown_0855C244: ; 855C244
	.incbin "base_emerald.gba", 0x55c244, 0x68

gUnknown_0855C2AC: ; 855C2AC
	.incbin "base_emerald.gba", 0x55c2ac, 0x18

gUnknown_0855C2C4: ; 855C2C4
	.incbin "base_emerald.gba", 0x55c2c4, 0x40

gUnknown_0855C304: ; 855C304
	.incbin "base_emerald.gba", 0x55c304, 0x18

gUnknown_0855C31C: ; 855C31C
	.incbin "base_emerald.gba", 0x55c31c, 0x18

gUnknown_0855C334: ; 855C334
	.incbin "base_emerald.gba", 0x55c334, 0x18

gUnknown_0855C34C: ; 855C34C
	.incbin "base_emerald.gba", 0x55c34c, 0x18

gUnknown_0855C364: ; 855C364
	.incbin "base_emerald.gba", 0x55c364, 0x10

gUnknown_0855C374: ; 855C374
	.incbin "base_emerald.gba", 0x55c374, 0x10

gUnknown_0855C384: ; 855C384
	.incbin "base_emerald.gba", 0x55c384, 0x20

gUnknown_0855C3A4: ; 855C3A4
	.incbin "base_emerald.gba", 0x55c3a4, 0x18

gUnknown_0855C3BC: ; 855C3BC
	.incbin "base_emerald.gba", 0x55c3bc, 0x4

gUnknown_0855C3C0: ; 855C3C0
	.incbin "base_emerald.gba", 0x55c3c0, 0x4

gUnknown_0855C3C4: ; 855C3C4
	.incbin "base_emerald.gba", 0x55c3c4, 0x4

gUnknown_0855C3C8: ; 855C3C8
	.incbin "base_emerald.gba", 0x55c3c8, 0x1c

gUnknown_0855C3E4: ; 855C3E4
	.incbin "base_emerald.gba", 0x55c3e4, 0x18

gUnknown_0855C3FC: ; 855C3FC
	.incbin "base_emerald.gba", 0x55c3fc, 0x1c

gUnknown_0855C418: ; 855C418
	.incbin "base_emerald.gba", 0x55c418, 0x14

gUnknown_0855C42C: ; 855C42C
	.incbin "base_emerald.gba", 0x55c42c, 0xc

gUnknown_0855C438: ; 855C438
	.incbin "base_emerald.gba", 0x55c438, 0x18

gUnknown_0855C450: ; 855C450
	.incbin "base_emerald.gba", 0x55c450, 0x10

gUnknown_0855C460: ; 855C460
	.incbin "base_emerald.gba", 0x55c460, 0x14

gUnknown_0855C474: ; 855C474
	.incbin "base_emerald.gba", 0x55c474, 0x8

gUnknown_0855C47C: ; 855C47C
	.incbin "base_emerald.gba", 0x55c47c, 0x8

gUnknown_0855C484: ; 855C484
	.incbin "base_emerald.gba", 0x55c484, 0x8

gUnknown_0855C48C: ; 855C48C
	.incbin "base_emerald.gba", 0x55c48c, 0x10

gUnknown_0855C49C: ; 855C49C
	.incbin "base_emerald.gba", 0x55c49c, 0xc

gUnknown_0855C4A8: ; 855C4A8
	.incbin "base_emerald.gba", 0x55c4a8, 0x1c

gUnknown_0855C4C4: ; 855C4C4
	.incbin "base_emerald.gba", 0x55c4c4, 0x1c

gUnknown_0855C4E0: ; 855C4E0
	.incbin "base_emerald.gba", 0x55c4e0, 0x14

gUnknown_0855C4F4: ; 855C4F4
	.incbin "base_emerald.gba", 0x55c4f4, 0x54

gUnknown_0855C548: ; 855C548
	.incbin "base_emerald.gba", 0x55c548, 0x8

gUnknown_0855C550: ; 855C550
	.incbin "base_emerald.gba", 0x55c550, 0x1c

gUnknown_0855C56C: ; 855C56C
	.incbin "base_emerald.gba", 0x55c56c, 0x24

gUnknown_0855C590: ; 855C590
	.incbin "base_emerald.gba", 0x55c590, 0x5c

gUnknown_0855C5EC: ; 855C5EC
	.incbin "base_emerald.gba", 0x55c5ec, 0x18

gUnknown_0855C604: ; 855C604
	.incbin "base_emerald.gba", 0x55c604, 0x60

gUnknown_0855C664: ; 855C664
	.incbin "base_emerald.gba", 0x55c664, 0x1c

gUnknown_0855C680: ; 855C680
	.incbin "base_emerald.gba", 0x55c680, 0x18

gUnknown_0855C698: ; 855C698
	.incbin "base_emerald.gba", 0x55c698, 0x8

gUnknown_0855C6A0: ; 855C6A0
	.incbin "base_emerald.gba", 0x55c6a0, 0x4

gUnknown_0855C6A4: ; 855C6A4
	.incbin "base_emerald.gba", 0x55c6a4, 0x336

gUnknown_0855C9DA: ; 855C9DA
	.incbin "base_emerald.gba", 0x55c9da, 0x304

gUnknown_0855CCDE: ; 855CCDE
	.incbin "base_emerald.gba", 0x55ccde, 0x4b6

gUnknown_0855D194: ; 855D194
	.incbin "base_emerald.gba", 0x55d194, 0x18

gUnknown_0855D1AC: ; 855D1AC
	.incbin "base_emerald.gba", 0x55d1ac, 0x18

gUnknown_0855D1C4: ; 855D1C4
	.incbin "base_emerald.gba", 0x55d1c4, 0x18

gUnknown_0855D1DC: ; 855D1DC
	.incbin "base_emerald.gba", 0x55d1dc, 0x18

gUnknown_0855D1F4: ; 855D1F4
	.incbin "base_emerald.gba", 0x55d1f4, 0x18

gUnknown_0855D20C: ; 855D20C
	.incbin "base_emerald.gba", 0x55d20c, 0x18

gUnknown_0855D224: ; 855D224
	.incbin "base_emerald.gba", 0x55d224, 0x18

gUnknown_0855D23C: ; 855D23C
	.incbin "base_emerald.gba", 0x55d23c, 0x18

gUnknown_0855D254: ; 855D254
	.incbin "base_emerald.gba", 0x55d254, 0x18

gUnknown_0855D26C: ; 855D26C
	.incbin "base_emerald.gba", 0x55d26c, 0x10

gUnknown_0855D27C: ; 855D27C
	.incbin "base_emerald.gba", 0x55d27c, 0x10

gUnknown_0855D28C: ; 855D28C
	.incbin "base_emerald.gba", 0x55d28c, 0x5

gUnknown_0855D291: ; 855D291
	.incbin "base_emerald.gba", 0x55d291, 0x7

gUnknown_0855D298: ; 855D298
	.incbin "base_emerald.gba", 0x55d298, 0x10

gUnknown_0855D2A8: ; 855D2A8
	.incbin "base_emerald.gba", 0x55d2a8, 0x10

gUnknown_0855D2B8: ; 855D2B8
	.incbin "base_emerald.gba", 0x55d2b8, 0x6

gUnknown_0855D2BE: ; 855D2BE
	.incbin "base_emerald.gba", 0x55d2be, 0x40

gUnknown_0855D2FE: ; 855D2FE
	.incbin "base_emerald.gba", 0x55d2fe, 0xe

gUnknown_0855D30C: ; 855D30C
	.charmapstr "$"

; 855D30D
	.include "data/text/pokedex_text.s"

; 856B5B0
	.include "data/pokedex_entries.s"

gUnknown_0856E610: ; 856E610
	.incbin "base_emerald.gba", 0x56e610, 0x20

gUnknown_0856E630: ; 856E630
	.incbin "base_emerald.gba", 0x56e630, 0x10

gUnknown_0856E640: ; 856E640
	.incbin "base_emerald.gba", 0x56e640, 0x28

gUnknown_0856E668: ; 856E668
	.incbin "base_emerald.gba", 0x56e668, 0x8

gUnknown_0856E670: ; 856E670
	.incbin "base_emerald.gba", 0x56e670, 0x18

gUnknown_0856E688: ; 856E688
	.incbin "base_emerald.gba", 0x56e688, 0xc

gUnknown_0856E694: ; 856E694
	.incbin "base_emerald.gba", 0x56e694, 0x674

gUnknown_0856ED08: ; 856ED08
	.incbin "base_emerald.gba", 0x56ed08, 0x28

gUnknown_0856ED30: ; 856ED30
	.incbin "base_emerald.gba", 0x56ed30, 0x18

gUnknown_0856ED48: ; 856ED48
	.incbin "base_emerald.gba", 0x56ed48, 0x54

gUnknown_0856ED9C: ; 856ED9C
	.incbin "base_emerald.gba", 0x56ed9c, 0x1c

gUnknown_0856EDB8: ; 856EDB8
	.incbin "base_emerald.gba", 0x56edb8, 0x1c

gUnknown_0856EDD4: ; 856EDD4
	.incbin "base_emerald.gba", 0x56edd4, 0x1c

gUnknown_0856EDF0: ; 856EDF0
	.incbin "base_emerald.gba", 0x56edf0, 0x1c

gUnknown_0856EE0C: ; 856EE0C
	.incbin "base_emerald.gba", 0x56ee0c, 0x18

gUnknown_0856EE24: ; 856EE24
	.incbin "base_emerald.gba", 0x56ee24, 0x38

gUnknown_0856EE5C: ; 856EE5C
	.incbin "base_emerald.gba", 0x56ee5c, 0x58

gUnknown_0856EEB4: ; 856EEB4
	.incbin "base_emerald.gba", 0x56eeb4, 0x60

gUnknown_0856EF14: ; 856EF14
	.incbin "base_emerald.gba", 0x56ef14, 0x98

gUnknown_0856EFAC: ; 856EFAC
	.incbin "base_emerald.gba", 0x56efac, 0x2

gUnknown_0856EFAE: ; 856EFAE
	.incbin "base_emerald.gba", 0x56efae, 0x6

gUnknown_0856EFB4: ; 856EFB4
	.incbin "base_emerald.gba", 0x56efb4, 0x14

gUnknown_0856EFC8: ; 856EFC8
	.incbin "base_emerald.gba", 0x56efc8, 0x30

gUnknown_0856EFF8: ; 856EFF8
	.incbin "base_emerald.gba", 0x56eff8, 0x10

gUnknown_0856F008: ; 856F008
	.incbin "base_emerald.gba", 0x56f008, 0x10

gUnknown_0856F018: ; 856F018
	.incbin "base_emerald.gba", 0x56f018, 0x494

gUnknown_0856F4AC: ; 856F4AC
	.incbin "base_emerald.gba", 0x56f4ac, 0x20

gUnknown_0856F4CC: ; 856F4CC
	.incbin "base_emerald.gba", 0x56f4cc, 0x20

gUnknown_0856F4EC: ; 856F4EC
	.incbin "base_emerald.gba", 0x56f4ec, 0x20

gUnknown_0856F50C: ; 856F50C
	.incbin "base_emerald.gba", 0x56f50c, 0x20

gUnknown_0856F52C: ; 856F52C
	.incbin "base_emerald.gba", 0x56f52c, 0x20

gUnknown_0856F54C: ; 856F54C
	.incbin "base_emerald.gba", 0x56f54c, 0x20

gUnknown_0856F56C: ; 856F56C
	.incbin "base_emerald.gba", 0x56f56c, 0x20

gUnknown_0856F58C: ; 856F58C
	.incbin "base_emerald.gba", 0x56f58c, 0x20

gUnknown_0856F5AC: ; 856F5AC
	.incbin "base_emerald.gba", 0x56f5ac, 0x20

gUnknown_0856F5CC: ; 856F5CC
	.incbin "base_emerald.gba", 0x56f5cc, 0x248

gUnknown_0856F814: ; 856F814
	.incbin "base_emerald.gba", 0x56f814, 0x2a0

gUnknown_0856FAB4: ; 856FAB4
	.incbin "base_emerald.gba", 0x56fab4, 0x10

gUnknown_0856FAC4: ; 856FAC4
	.incbin "base_emerald.gba", 0x56fac4, 0x20

gUnknown_0856FAE4: ; 856FAE4
	.incbin "base_emerald.gba", 0x56fae4, 0x14

gUnknown_0856FAF8: ; 856FAF8
	.incbin "base_emerald.gba", 0x56faf8, 0x14

gUnknown_0856FB0C: ; 856FB0C
	.incbin "base_emerald.gba", 0x56fb0c, 0x3

gUnknown_0856FB0F: ; 856FB0F
	.incbin "base_emerald.gba", 0x56fb0f, 0x9

gUnknown_0856FB18: ; 856FB18
	.incbin "base_emerald.gba", 0x56fb18, 0x8

gUnknown_0856FB20: ; 856FB20
	.incbin "base_emerald.gba", 0x56fb20, 0x8

gUnknown_0856FB28: ; 856FB28
	.incbin "base_emerald.gba", 0x56fb28, 0x18

gUnknown_0856FB40: ; 856FB40
	.incbin "base_emerald.gba", 0x56fb40, 0x8

gUnknown_0856FB48: ; 856FB48
	.incbin "base_emerald.gba", 0x56fb48, 0x2

gUnknown_0856FB4A: ; 856FB4A
	.incbin "base_emerald.gba", 0x56fb4a, 0x2

gUnknown_0856FB4C: ; 856FB4C
	.incbin "base_emerald.gba", 0x56fb4c, 0x9

gUnknown_0856FB55: ; 856FB55
	.incbin "base_emerald.gba", 0x56fb55, 0x2

gUnknown_0856FB57: ; 856FB57
	.incbin "base_emerald.gba", 0x56fb57, 0x5

gUnknown_0856FB5C: ; 856FB5C
	.incbin "base_emerald.gba", 0x56fb5c, 0xc

gUnknown_0856FB68: ; 856FB68
	.incbin "base_emerald.gba", 0x56fb68, 0x6

gUnknown_0856FB6E: ; 856FB6E
	.incbin "base_emerald.gba", 0x56fb6e, 0x6

gUnknown_0856FB74: ; 856FB74
	.incbin "base_emerald.gba", 0x56fb74, 0x4

gUnknown_0856FB78: ; 856FB78
	.incbin "base_emerald.gba", 0x56fb78, 0x44

gUnknown_0856FBBC: ; 856FBBC
	.incbin "base_emerald.gba", 0x56fbbc, 0x1244

gUnknown_08570E00: ; 8570E00
	.incbin "base_emerald.gba", 0x570e00, 0x260

gUnknown_08571060: ; 8571060
	.incbin "base_emerald.gba", 0x571060, 0x260

gUnknown_085712C0: ; 85712C0
	.incbin "base_emerald.gba", 0x5712c0, 0x38

gUnknown_085712F8: ; 85712F8
	.incbin "base_emerald.gba", 0x5712f8, 0xe8

gUnknown_085713E0: ; 85713E0
	.incbin "base_emerald.gba", 0x5713e0, 0x8

gUnknown_085713E8: ; 85713E8
	.incbin "base_emerald.gba", 0x5713e8, 0xc

gUnknown_085713F4: ; 85713F4
	.incbin "base_emerald.gba", 0x5713f4, 0xc

gUnknown_08571400: ; 8571400
	.incbin "base_emerald.gba", 0x571400, 0x28

gUnknown_08571428: ; 8571428
	.incbin "base_emerald.gba", 0x571428, 0x20

gUnknown_08571448: ; 8571448
	.incbin "base_emerald.gba", 0x571448, 0x3

gUnknown_0857144B: ; 857144B
	.incbin "base_emerald.gba", 0x57144b, 0x3

gUnknown_0857144E: ; 857144E
	.incbin "base_emerald.gba", 0x57144e, 0x6

gUnknown_08571454: ; 8571454
	.incbin "base_emerald.gba", 0x571454, 0x68

gUnknown_085714BC: ; 85714BC
	.incbin "base_emerald.gba", 0x5714bc, 0x18

gUnknown_085714D4: ; 85714D4
	.incbin "base_emerald.gba", 0x5714d4, 0x10

gUnknown_085714E4: ; 85714E4
	.incbin "base_emerald.gba", 0x5714e4, 0xd0

gUnknown_085715B4: ; 85715B4
	.incbin "base_emerald.gba", 0x5715b4, 0x30

gUnknown_085715E4: ; 85715E4
	.incbin "base_emerald.gba", 0x5715e4, 0x18

gUnknown_085715FC: ; 85715FC
	.incbin "base_emerald.gba", 0x5715fc, 0x18

gUnknown_08571614: ; 8571614
	.incbin "base_emerald.gba", 0x571614, 0x3c

gUnknown_08571650: ; 8571650
	.incbin "base_emerald.gba", 0x571650, 0x70

gUnknown_085716C0: ; 85716C0
	.incbin "base_emerald.gba", 0x5716c0, 0x28

gUnknown_085716E8: ; 85716E8
	.incbin "base_emerald.gba", 0x5716e8, 0x28

gUnknown_08571710: ; 8571710
	.incbin "base_emerald.gba", 0x571710, 0x24

gUnknown_08571734: ; 8571734
	.incbin "base_emerald.gba", 0x571734, 0x3

gUnknown_08571737: ; 8571737
	.incbin "base_emerald.gba", 0x571737, 0x5

gUnknown_0857173C: ; 857173C
	.incbin "base_emerald.gba", 0x57173c, 0x20

gUnknown_0857175C: ; 857175C
	.incbin "base_emerald.gba", 0x57175c, 0x800

gUnknown_08571F5C: ; 8571F5C
	.incbin "base_emerald.gba", 0x571f5c, 0x180

gUnknown_085720DC: ; 85720DC
	.incbin "base_emerald.gba", 0x5720dc, 0x98

gUnknown_08572174: ; 8572174
	.incbin "base_emerald.gba", 0x572174, 0x12c

gUnknown_085722A0: ; 85722A0
	.incbin "base_emerald.gba", 0x5722a0, 0xfc

gUnknown_0857239C: ; 857239C
	.incbin "base_emerald.gba", 0x57239c, 0x40

gUnknown_085723DC: ; 85723DC
	.incbin "base_emerald.gba", 0x5723dc, 0x20

gUnknown_085723FC: ; 85723FC
	.incbin "base_emerald.gba", 0x5723fc, 0x20

gUnknown_0857241C: ; 857241C
	.incbin "base_emerald.gba", 0x57241c, 0x20

gUnknown_0857243C: ; 857243C
	.incbin "base_emerald.gba", 0x57243c, 0x20

gUnknown_0857245C: ; 857245C
	.incbin "base_emerald.gba", 0x57245c, 0x48

gUnknown_085724A4: ; 85724A4
	.incbin "base_emerald.gba", 0x5724a4, 0x18

gUnknown_085724BC: ; 85724BC
	.incbin "base_emerald.gba", 0x5724bc, 0x238

gUnknown_085726F4: ; 85726F4
	.incbin "base_emerald.gba", 0x5726f4, 0x20

gUnknown_08572714: ; 8572714
	.incbin "base_emerald.gba", 0x572714, 0x20

gUnknown_08572734: ; 8572734
	.incbin "base_emerald.gba", 0x572734, 0x10

gUnknown_08572744: ; 8572744
	.incbin "base_emerald.gba", 0x572744, 0x8

gUnknown_0857274C: ; 857274C
	.incbin "base_emerald.gba", 0x57274c, 0x8

gUnknown_08572754: ; 8572754
	.incbin "base_emerald.gba", 0x572754, 0x18

gUnknown_0857276C: ; 857276C
	.incbin "base_emerald.gba", 0x57276c, 0xf8

gUnknown_08572864: ; 8572864
	.incbin "base_emerald.gba", 0x572864, 0x58

gUnknown_085728BC: ; 85728BC
	.incbin "base_emerald.gba", 0x5728bc, 0x18

gUnknown_085728D4: ; 85728D4
	.incbin "base_emerald.gba", 0x5728d4, 0x48

gUnknown_0857291C: ; 857291C
	.incbin "base_emerald.gba", 0x57291c, 0x4c58

gUnknown_08577574: ; 8577574
	.incbin "base_emerald.gba", 0x577574, 0x44

gUnknown_085775B8: ; 85775B8
	.incbin "base_emerald.gba", 0x5775b8, 0x398c

gUnknown_0857AF44: ; 857AF44
	.incbin "base_emerald.gba", 0x57af44, 0xc0

gUnknown_0857B004: ; 857B004
	.incbin "base_emerald.gba", 0x57b004, 0x7c

gUnknown_0857B080: ; 857B080
	.incbin "base_emerald.gba", 0x57b080, 0x28

gUnknown_0857B0A8: ; 857B0A8
	.incbin "base_emerald.gba", 0x57b0a8, 0x38

gUnknown_0857B0E0: ; 857B0E0
	.incbin "base_emerald.gba", 0x57b0e0, 0x8b8

gUnknown_0857B998: ; 857B998
	.incbin "base_emerald.gba", 0x57b998, 0xc

gUnknown_0857B9A4: ; 857B9A4
	.incbin "base_emerald.gba", 0x57b9a4, 0x18

gUnknown_0857B9BC: ; 857B9BC
	.incbin "base_emerald.gba", 0x57b9bc, 0x28

gUnknown_0857B9E4: ; 857B9E4
	.incbin "base_emerald.gba", 0x57b9e4, 0x18

gUnknown_0857B9FC: ; 857B9FC
	.incbin "base_emerald.gba", 0x57b9fc, 0x54

gUnknown_0857BA50: ; 857BA50
	.incbin "base_emerald.gba", 0x57ba50, 0x18

gUnknown_0857BA68: ; 857BA68
	.incbin "base_emerald.gba", 0x57ba68, 0x18

gUnknown_0857BA80: ; 857BA80
	.incbin "base_emerald.gba", 0x57ba80, 0x9c

gUnknown_0857BB1C: ; 857BB1C
	.incbin "base_emerald.gba", 0x57bb1c, 0x8

gUnknown_0857BB24: ; 857BB24
	.incbin "base_emerald.gba", 0x57bb24, 0x14c

gUnknown_0857BC70: ; 857BC70
	.incbin "base_emerald.gba", 0x57bc70, 0x18

gUnknown_0857BC88: ; 857BC88
	.incbin "base_emerald.gba", 0x57bc88, 0x20

gUnknown_0857BCA8: ; 857BCA8
	.incbin "base_emerald.gba", 0x57bca8, 0x6e0

gUnknown_0857C388: ; 857C388
	.incbin "base_emerald.gba", 0x57c388, 0x1b8

gUnknown_0857C540: ; 857C540
	.incbin "base_emerald.gba", 0x57c540, 0x30

gUnknown_0857C570: ; 857C570
	.incbin "base_emerald.gba", 0x57c570, 0x44

gUnknown_0857C5B4: ; 857C5B4
	.incbin "base_emerald.gba", 0x57c5b4, 0x34

gUnknown_0857C5E8: ; 857C5E8
	.incbin "base_emerald.gba", 0x57c5e8, 0x8

gUnknown_0857C5F0: ; 857C5F0
	.incbin "base_emerald.gba", 0x57c5f0, 0x18

gUnknown_0857C608: ; 857C608
	.incbin "base_emerald.gba", 0x57c608, 0x2

gUnknown_0857C60A: ; 857C60A
	.incbin "base_emerald.gba", 0x57c60a, 0x62

gUnknown_0857C66C: ; 857C66C
	.incbin "base_emerald.gba", 0x57c66c, 0x18

gUnknown_0857C684: ; 857C684
	.incbin "base_emerald.gba", 0x57c684, 0x1680

gUnknown_0857DD04: ; 857DD04
	.incbin "base_emerald.gba", 0x57dd04, 0x1680

gUnknown_0857F384: ; 857F384
	.incbin "base_emerald.gba", 0x57f384, 0xc0

gUnknown_0857F444: ; 857F444
	.incbin "base_emerald.gba", 0x57f444, 0x20

gUnknown_0857F464: ; 857F464
	.incbin "base_emerald.gba", 0x57f464, 0xe0

gUnknown_0857F544: ; 857F544
	.incbin "base_emerald.gba", 0x57f544, 0x5f0

gUnknown_0857FB34: ; 857FB34
	.incbin "base_emerald.gba", 0x57fb34, 0x8

gUnknown_0857FB3C: ; 857FB3C
	.incbin "base_emerald.gba", 0x57fb3c, 0x8

gUnknown_0857FB44: ; 857FB44
	.incbin "base_emerald.gba", 0x57fb44, 0x8

gUnknown_0857FB4C: ; 857FB4C
	.incbin "base_emerald.gba", 0x57fb4c, 0x4c

gUnknown_0857FB98: ; 857FB98
	.incbin "base_emerald.gba", 0x57fb98, 0x4

gUnknown_0857FB9C: ; 857FB9C
	.incbin "base_emerald.gba", 0x57fb9c, 0x4

gUnknown_0857FBA0: ; 857FBA0
	.incbin "base_emerald.gba", 0x57fba0, 0x8

gUnknown_0857FBA8: ; 857FBA8
	.incbin "base_emerald.gba", 0x57fba8, 0x8

gUnknown_0857FBB0: ; 857FBB0
	.incbin "base_emerald.gba", 0x57fbb0, 0x3c

gUnknown_0857FBEC: ; 857FBEC
	.incbin "base_emerald.gba", 0x57fbec, 0x90

gUnknown_0857FC7C: ; 857FC7C
	.incbin "base_emerald.gba", 0x57fc7c, 0x18

gUnknown_0857FC94: ; 857FC94
	.incbin "base_emerald.gba", 0x57fc94, 0x158

gUnknown_0857FDEC: ; 857FDEC
	.incbin "base_emerald.gba", 0x57fdec, 0x8

gUnknown_0857FDF4: ; 857FDF4
	.incbin "base_emerald.gba", 0x57fdf4, 0x1c

gUnknown_0857FE10: ; 857FE10
	.incbin "base_emerald.gba", 0x57fe10, 0x3b90

gUnknown_085839A0: ; 85839A0
	.incbin "base_emerald.gba", 0x5839a0, 0x40cc

gUnknown_08587A6C: ; 8587A6C
	.incbin "base_emerald.gba", 0x587a6c, 0x4

gUnknown_08587A70: ; 8587A70
	.incbin "base_emerald.gba", 0x587a70, 0x4

gUnknown_08587A74: ; 8587A74
	.incbin "base_emerald.gba", 0x587a74, 0x5c

gUnknown_08587AD0: ; 8587AD0
	.incbin "base_emerald.gba", 0x587ad0, 0x18

gUnknown_08587AE8: ; 8587AE8
	.incbin "base_emerald.gba", 0x587ae8, 0x20

gUnknown_08587B08: ; 8587B08
	.incbin "base_emerald.gba", 0x587b08, 0x10

gUnknown_08587B18: ; 8587B18
	.incbin "base_emerald.gba", 0x587b18, 0x68

gUnknown_08587B80: ; 8587B80
	.incbin "base_emerald.gba", 0x587b80, 0x30

gUnknown_08587BB0: ; 8587BB0
	.incbin "base_emerald.gba", 0x587bb0, 0x8

gUnknown_08587BB8: ; 8587BB8
	.incbin "base_emerald.gba", 0x587bb8, 0x10

gUnknown_08587BC8: ; 8587BC8
	.incbin "base_emerald.gba", 0x587bc8, 0x20

gUnknown_08587BE8: ; 8587BE8
	.incbin "base_emerald.gba", 0x587be8, 0x18

gUnknown_08587C00: ; 8587C00
	.incbin "base_emerald.gba", 0x587c00, 0x8

gUnknown_08587C08: ; 8587C08
	.incbin "base_emerald.gba", 0x587c08, 0x8

gUnknown_08587C10: ; 8587C10
	.incbin "base_emerald.gba", 0x587c10, 0x8

gUnknown_08587C18: ; 8587C18
	.incbin "base_emerald.gba", 0x587c18, 0x18

gUnknown_08587C30: ; 8587C30
	.incbin "base_emerald.gba", 0x587c30, 0x20

gUnknown_08587C50: ; 8587C50
	.incbin "base_emerald.gba", 0x587c50, 0xf8

gUnknown_08587D48: ; 8587D48
	.incbin "base_emerald.gba", 0x587d48, 0x48

gUnknown_08587D90: ; 8587D90
	.incbin "base_emerald.gba", 0x587d90, 0x80

gUnknown_08587E10: ; 8587E10
	.incbin "base_emerald.gba", 0x587e10, 0xf8

gUnknown_08587F08: ; 8587F08
	.incbin "base_emerald.gba", 0x587f08, 0x14

gUnknown_08587F1C: ; 8587F1C
	.incbin "base_emerald.gba", 0x587f1c, 0x18

gUnknown_08587F34: ; 8587F34
	.incbin "base_emerald.gba", 0x587f34, 0x10

gUnknown_08587F44: ; 8587F44
	.incbin "base_emerald.gba", 0x587f44, 0x60

gUnknown_08587FA4: ; 8587FA4
	.incbin "base_emerald.gba", 0x587fa4, 0x100

gUnknown_085880A4: ; 85880A4
	.incbin "base_emerald.gba", 0x5880a4, 0x1740

gUnknown_085897E4: ; 85897E4
	.incbin "base_emerald.gba", 0x5897e4, 0xc0

gUnknown_085898A4: ; 85898A4
	.incbin "base_emerald.gba", 0x5898a4, 0x60

gUnknown_08589904: ; 8589904
	.incbin "base_emerald.gba", 0x589904, 0x20

gUnknown_08589924: ; 8589924
	.incbin "base_emerald.gba", 0x589924, 0x68

gUnknown_0858998C: ; 858998C
	.incbin "base_emerald.gba", 0x58998c, 0x60

gUnknown_085899EC: ; 85899EC
	.incbin "base_emerald.gba", 0x5899ec, 0x1c

gUnknown_08589A08: ; 8589A08
	.incbin "base_emerald.gba", 0x589a08, 0x8

gUnknown_08589A10: ; 8589A10
	.incbin "base_emerald.gba", 0x589a10, 0x18

gUnknown_08589A28: ; 8589A28
	.incbin "base_emerald.gba", 0x589a28, 0x10

gUnknown_08589A38: ; 8589A38
	.incbin "base_emerald.gba", 0x589a38, 0x10

gUnknown_08589A48: ; 8589A48
	.incbin "base_emerald.gba", 0x589a48, 0x18

gUnknown_08589A60: ; 8589A60
	.incbin "base_emerald.gba", 0x589a60, 0x10

gUnknown_08589A70: ; 8589A70
	.incbin "base_emerald.gba", 0x589a70, 0x38

gUnknown_08589AA8: ; 8589AA8
	.incbin "base_emerald.gba", 0x589aa8, 0x8

gUnknown_08589AB0: ; 8589AB0
	.incbin "base_emerald.gba", 0x589ab0, 0x3

gUnknown_08589AB3: ; 8589AB3
	.incbin "base_emerald.gba", 0x589ab3, 0x7

gUnknown_08589ABA: ; 8589ABA
	.incbin "base_emerald.gba", 0x589aba, 0x6

gUnknown_08589AC0: ; 8589AC0
	.incbin "base_emerald.gba", 0x589ac0, 0x6

gUnknown_08589AC6: ; 8589AC6
	.incbin "base_emerald.gba", 0x589ac6, 0x6

gUnknown_08589ACC: ; 8589ACC
	.incbin "base_emerald.gba", 0x589acc, 0x6

gUnknown_08589AD2: ; 8589AD2
	.incbin "base_emerald.gba", 0x589ad2, 0x6

gUnknown_08589AD8: ; 8589AD8
	.incbin "base_emerald.gba", 0x589ad8, 0x6

gUnknown_08589ADE: ; 8589ADE
	.incbin "base_emerald.gba", 0x589ade, 0xb76

gUnknown_0858A654: ; 858A654
	.incbin "base_emerald.gba", 0x58a654, 0x1c

gUnknown_0858A670: ; 858A670
	.incbin "base_emerald.gba", 0x58a670, 0x4b4

gUnknown_0858AB24: ; 858AB24
	.incbin "base_emerald.gba", 0x58ab24, 0xac

gUnknown_0858ABD0: ; 858ABD0
	.incbin "base_emerald.gba", 0x58abd0, 0xb90

gUnknown_0858B760: ; 858B760
	.incbin "base_emerald.gba", 0x58b760, 0x390

gUnknown_0858BAF0: ; 858BAF0
	.incbin "base_emerald.gba", 0x58baf0, 0x78

gUnknown_0858BB68: ; 858BB68
	.incbin "base_emerald.gba", 0x58bb68, 0x8

gUnknown_0858BB70: ; 858BB70
	.incbin "base_emerald.gba", 0x58bb70, 0x10

gUnknown_0858BB80: ; 858BB80
	.incbin "base_emerald.gba", 0x58bb80, 0x1c

gUnknown_0858BB9C: ; 858BB9C
	.incbin "base_emerald.gba", 0x58bb9c, 0x10

gUnknown_0858BBAC: ; 858BBAC
	.incbin "base_emerald.gba", 0x58bbac, 0x10

gUnknown_0858BBBC: ; 858BBBC
	.incbin "base_emerald.gba", 0x58bbbc, 0x10

gUnknown_0858BBCC: ; 858BBCC
	.incbin "base_emerald.gba", 0x58bbcc, 0x14

gUnknown_0858BBE0: ; 858BBE0
	.incbin "base_emerald.gba", 0x58bbe0, 0xc

gUnknown_0858BBEC: ; 858BBEC
	.incbin "base_emerald.gba", 0x58bbec, 0x18c

gUnknown_0858BD78: ; 858BD78
	.incbin "base_emerald.gba", 0x58bd78, 0x40

gUnknown_0858BDB8: ; 858BDB8
	.incbin "base_emerald.gba", 0x58bdb8, 0x10

gUnknown_0858BDC8: ; 858BDC8
	.incbin "base_emerald.gba", 0x58bdc8, 0x38

gUnknown_0858BE00: ; 858BE00
	.incbin "base_emerald.gba", 0x58be00, 0x10

gUnknown_0858BE10: ; 858BE10
	.incbin "base_emerald.gba", 0x58be10, 0x30

gUnknown_0858BE40: ; 858BE40
	.incbin "base_emerald.gba", 0x58be40, 0x60

gUnknown_0858BEA0: ; 858BEA0
	.incbin "base_emerald.gba", 0x58bea0, 0x3

gUnknown_0858BEA3: ; 858BEA3
	.incbin "base_emerald.gba", 0x58bea3, 0x18

gUnknown_0858BEBB: ; 858BEBB
	.incbin "base_emerald.gba", 0x58bebb, 0x3

gUnknown_0858BEBE: ; 858BEBE
	.incbin "base_emerald.gba", 0x58bebe, 0x3

gUnknown_0858BEC1: ; 858BEC1
	.incbin "base_emerald.gba", 0x58bec1, 0x3

gUnknown_0858BEC4: ; 858BEC4
	.incbin "base_emerald.gba", 0x58bec4, 0x10

gUnknown_0858BED4: ; 858BED4
	.incbin "base_emerald.gba", 0x58bed4, 0x8

gUnknown_0858BEDC: ; 858BEDC
	.incbin "base_emerald.gba", 0x58bedc, 0x8

gUnknown_0858BEE4: ; 858BEE4
	.incbin "base_emerald.gba", 0x58bee4, 0x4

gUnknown_0858BEE8: ; 858BEE8
	.incbin "base_emerald.gba", 0x58bee8, 0x10

gUnknown_0858BEF8: ; 858BEF8
	.incbin "base_emerald.gba", 0x58bef8, 0x6

gUnknown_0858BEFE: ; 858BEFE
	.incbin "base_emerald.gba", 0x58befe, 0x6

gUnknown_0858BF04: ; 858BF04
	.incbin "base_emerald.gba", 0x58bf04, 0x14

gUnknown_0858BF18: ; 858BF18
	.incbin "base_emerald.gba", 0x58bf18, 0x10

gUnknown_0858BF28: ; 858BF28
	.incbin "base_emerald.gba", 0x58bf28, 0xc

gUnknown_0858BF34: ; 858BF34
	.incbin "base_emerald.gba", 0x58bf34, 0xa

gUnknown_0858BF3E: ; 858BF3E
	.incbin "base_emerald.gba", 0x58bf3e, 0xa

gUnknown_0858BF48: ; 858BF48
	.incbin "base_emerald.gba", 0x58bf48, 0x8

gUnknown_0858BF50: ; 858BF50
	.incbin "base_emerald.gba", 0x58bf50, 0x8

gUnknown_0858BF58: ; 858BF58
	.incbin "base_emerald.gba", 0x58bf58, 0x14

gUnknown_0858BF6C: ; 858BF6C
	.incbin "base_emerald.gba", 0x58bf6c, 0x8

gUnknown_0858BF74: ; 858BF74
	.incbin "base_emerald.gba", 0x58bf74, 0x14

gUnknown_0858BF88: ; 858BF88
	.incbin "base_emerald.gba", 0x58bf88, 0x4

gUnknown_0858BF8C: ; 858BF8C
	.incbin "base_emerald.gba", 0x58bf8c, 0xc

gUnknown_0858BF98: ; 858BF98
	.incbin "base_emerald.gba", 0x58bf98, 0xc

gUnknown_0858BFA4: ; 858BFA4
	.incbin "base_emerald.gba", 0x58bfa4, 0x34

gUnknown_0858BFD8: ; 858BFD8
	.incbin "base_emerald.gba", 0x58bfd8, 0x78

gUnknown_0858C050: ; 858C050
	.incbin "base_emerald.gba", 0x58c050, 0x8

gUnknown_0858C058: ; 858C058
	.incbin "base_emerald.gba", 0x58c058, 0x18

gUnknown_0858C070: ; 858C070
	.incbin "base_emerald.gba", 0x58c070, 0x8

gUnknown_0858C078: ; 858C078
	.incbin "base_emerald.gba", 0x58c078, 0x48

gUnknown_0858C0C0: ; 858C0C0
	.incbin "base_emerald.gba", 0x58c0c0, 0x18

gUnknown_0858C0D8: ; 858C0D8
	.incbin "base_emerald.gba", 0x58c0d8, 0x18

gUnknown_0858C0F0: ; 858C0F0
	.incbin "base_emerald.gba", 0x58c0f0, 0x18

gUnknown_0858C108: ; 858C108
	.incbin "base_emerald.gba", 0x58c108, 0x18

gUnknown_0858C120: ; 858C120
	.incbin "base_emerald.gba", 0x58c120, 0x18

gUnknown_0858C138: ; 858C138
	.incbin "base_emerald.gba", 0x58c138, 0x18

gUnknown_0858C150: ; 858C150
	.incbin "base_emerald.gba", 0x58c150, 0x18

gUnknown_0858C168: ; 858C168
	.incbin "base_emerald.gba", 0x58c168, 0x18

gUnknown_0858C180: ; 858C180
	.incbin "base_emerald.gba", 0x58c180, 0x18

gUnknown_0858C198: ; 858C198
	.incbin "base_emerald.gba", 0x58c198, 0x30

gUnknown_0858C1C8: ; 858C1C8
	.incbin "base_emerald.gba", 0x58c1c8, 0x68

gUnknown_0858C230: ; 858C230
	.incbin "base_emerald.gba", 0x58c230, 0x5c

gUnknown_0858C28C: ; 858C28C
	.incbin "base_emerald.gba", 0x58c28c, 0x18

gUnknown_0858C2A4: ; 858C2A4
	.incbin "base_emerald.gba", 0x58c2a4, 0x8

gUnknown_0858C2AC: ; 858C2AC
	.incbin "base_emerald.gba", 0x58c2ac, 0x8

gUnknown_0858C2B4: ; 858C2B4
	.incbin "base_emerald.gba", 0x58c2b4, 0xb18

gUnknown_0858CDCC: ; 858CDCC
	.incbin "base_emerald.gba", 0x58cdcc, 0xc0

gUnknown_0858CE8C: ; 858CE8C
	.incbin "base_emerald.gba", 0x58ce8c, 0x40

gUnknown_0858CECC: ; 858CECC
	.incbin "base_emerald.gba", 0x58cecc, 0xc0

gUnknown_0858CF8C: ; 858CF8C
	.incbin "base_emerald.gba", 0x58cf8c, 0x2

gUnknown_0858CF8E: ; 858CF8E
	.incbin "base_emerald.gba", 0x58cf8e, 0x6

gUnknown_0858CF94: ; 858CF94
	.incbin "base_emerald.gba", 0x58cf94, 0x24

gUnknown_0858CFB8: ; 858CFB8
	.incbin "base_emerald.gba", 0x58cfb8, 0x6

gUnknown_0858CFBE: ; 858CFBE
	.incbin "base_emerald.gba", 0x58cfbe, 0xe

gUnknown_0858CFCC: ; 858CFCC
	.incbin "base_emerald.gba", 0x58cfcc, 0x1c

gUnknown_0858CFE8: ; 858CFE8
	.incbin "base_emerald.gba", 0x58cfe8, 0x60

gUnknown_0858D048: ; 858D048
	.incbin "base_emerald.gba", 0x58d048, 0x10

gUnknown_0858D058: ; 858D058
	.incbin "base_emerald.gba", 0x58d058, 0x8

gUnknown_0858D060: ; 858D060
	.incbin "base_emerald.gba", 0x58d060, 0xc

gUnknown_0858D06C: ; 858D06C
	.incbin "base_emerald.gba", 0x58d06c, 0x10

gUnknown_0858D07C: ; 858D07C
	.incbin "base_emerald.gba", 0x58d07c, 0x18

gUnknown_0858D094: ; 858D094
	.incbin "base_emerald.gba", 0x58d094, 0x3c

gUnknown_0858D0D0: ; 858D0D0
	.incbin "base_emerald.gba", 0x58d0d0, 0xe

gUnknown_0858D0DE: ; 858D0DE
	.incbin "base_emerald.gba", 0x58d0de, 0xe

gUnknown_0858D0EC: ; 858D0EC
	.incbin "base_emerald.gba", 0x58d0ec, 0x1c

gUnknown_0858D108: ; 858D108
	.incbin "base_emerald.gba", 0x58d108, 0x14

gUnknown_0858D11C: ; 858D11C
	.incbin "base_emerald.gba", 0x58d11c, 0x14

gUnknown_0858D130: ; 858D130
	.incbin "base_emerald.gba", 0x58d130, 0x14

gUnknown_0858D144: ; 858D144
	.incbin "base_emerald.gba", 0x58d144, 0xc

gUnknown_0858D150: ; 858D150
	.incbin "base_emerald.gba", 0x58d150, 0x20

gUnknown_0858D170: ; 858D170
	.incbin "base_emerald.gba", 0x58d170, 0x18

gUnknown_0858D188: ; 858D188
	.incbin "base_emerald.gba", 0x58d188, 0x14

gUnknown_0858D19C: ; 858D19C
	.incbin "base_emerald.gba", 0x58d19c, 0x4

gUnknown_0858D1A0: ; 858D1A0
	.incbin "base_emerald.gba", 0x58d1a0, 0x30

gUnknown_0858D1D0: ; 858D1D0
	.incbin "base_emerald.gba", 0x58d1d0, 0x34

gUnknown_0858D204: ; 858D204
	.incbin "base_emerald.gba", 0x58d204, 0x24

gUnknown_0858D228: ; 858D228
	.incbin "base_emerald.gba", 0x58d228, 0x18

gUnknown_0858D240: ; 858D240
	.incbin "base_emerald.gba", 0x58d240, 0x3c

gUnknown_0858D27C: ; 858D27C
	.incbin "base_emerald.gba", 0x58d27c, 0x84

gUnknown_0858D300: ; 858D300
	.incbin "base_emerald.gba", 0x58d300, 0x20

gUnknown_0858D320: ; 858D320
	.incbin "base_emerald.gba", 0x58d320, 0x18

gUnknown_0858D338: ; 858D338
	.incbin "base_emerald.gba", 0x58d338, 0x4c

gUnknown_0858D384: ; 858D384
	.incbin "base_emerald.gba", 0x58d384, 0x10

gUnknown_0858D394: ; 858D394
	.incbin "base_emerald.gba", 0x58d394, 0x1c

gUnknown_0858D3B0: ; 858D3B0
	.incbin "base_emerald.gba", 0x58d3b0, 0x8

gUnknown_0858D3B8: ; 858D3B8
	.incbin "base_emerald.gba", 0x58d3b8, 0xc

gUnknown_0858D3C4: ; 858D3C4
	.incbin "base_emerald.gba", 0x58d3c4, 0x2c

gUnknown_0858D3F0: ; 858D3F0
	.incbin "base_emerald.gba", 0x58d3f0, 0x1c

gUnknown_0858D40C: ; 858D40C
	.incbin "base_emerald.gba", 0x58d40c, 0xc

gUnknown_0858D418: ; 858D418
	.incbin "base_emerald.gba", 0x58d418, 0x10

gUnknown_0858D428: ; 858D428
	.incbin "base_emerald.gba", 0x58d428, 0x34

gUnknown_0858D45C: ; 858D45C
	.incbin "base_emerald.gba", 0x58d45c, 0x38

gUnknown_0858D494: ; 858D494
	.incbin "base_emerald.gba", 0x58d494, 0x4

gUnknown_0858D498: ; 858D498
	.incbin "base_emerald.gba", 0x58d498, 0x1c

gUnknown_0858D4B4: ; 858D4B4
	.incbin "base_emerald.gba", 0x58d4b4, 0x30

gUnknown_0858D4E4: ; 858D4E4
	.incbin "base_emerald.gba", 0x58d4e4, 0x40

gUnknown_0858D524: ; 858D524
	.incbin "base_emerald.gba", 0x58d524, 0x4c

gUnknown_0858D570: ; 858D570
	.incbin "base_emerald.gba", 0x58d570, 0x24

gUnknown_0858D594: ; 858D594
	.incbin "base_emerald.gba", 0x58d594, 0xac

gUnknown_0858D640: ; 858D640
	.incbin "base_emerald.gba", 0x58d640, 0x2c

gUnknown_0858D66C: ; 858D66C
	.incbin "base_emerald.gba", 0x58d66c, 0x24

gUnknown_0858D690: ; 858D690
	.incbin "base_emerald.gba", 0x58d690, 0x20

gUnknown_0858D6B0: ; 858D6B0
	.incbin "base_emerald.gba", 0x58d6b0, 0x20

gUnknown_0858D6D0: ; 858D6D0
	.incbin "base_emerald.gba", 0x58d6d0, 0x128

gUnknown_0858D7F8: ; 858D7F8
	.incbin "base_emerald.gba", 0x58d7f8, 0x18

gUnknown_0858D810: ; 858D810
	.incbin "base_emerald.gba", 0x58d810, 0x40

gUnknown_0858D850: ; 858D850
	.incbin "base_emerald.gba", 0x58d850, 0x10

gUnknown_0858D860: ; 858D860
	.incbin "base_emerald.gba", 0x58d860, 0x18

gUnknown_0858D878: ; 858D878
	.incbin "base_emerald.gba", 0x58d878, 0x8

gUnknown_0858D880: ; 858D880
	.incbin "base_emerald.gba", 0x58d880, 0x8

gUnknown_0858D888: ; 858D888
	.incbin "base_emerald.gba", 0x58d888, 0x10

gUnknown_0858D898: ; 858D898
	.incbin "base_emerald.gba", 0x58d898, 0x30

gUnknown_0858D8C8: ; 858D8C8
	.incbin "base_emerald.gba", 0x58d8c8, 0x18

gUnknown_0858D8E0: ; 858D8E0
	.incbin "base_emerald.gba", 0x58d8e0, 0x8

gUnknown_0858D8E8: ; 858D8E8
	.incbin "base_emerald.gba", 0x58d8e8, 0x4

gUnknown_0858D8EC: ; 858D8EC
	.incbin "base_emerald.gba", 0x58d8ec, 0x4

gUnknown_0858D8F0: ; 858D8F0
	.incbin "base_emerald.gba", 0x58d8f0, 0x80

gUnknown_0858D970: ; 858D970
	.incbin "base_emerald.gba", 0x58d970, 0xc90

gUnknown_0858E600: ; 858E600
	.incbin "base_emerald.gba", 0x58e600, 0x18

gUnknown_0858E618: ; 858E618
	.incbin "base_emerald.gba", 0x58e618, 0x18

gUnknown_0858E630: ; 858E630
	.incbin "base_emerald.gba", 0x58e630, 0x5c

gUnknown_0858E68C: ; 858E68C
	.incbin "base_emerald.gba", 0x58e68c, 0x1d8

gUnknown_0858E864: ; 858E864
	.incbin "base_emerald.gba", 0x58e864, 0x1c

gUnknown_0858E880: ; 858E880
	.incbin "base_emerald.gba", 0x58e880, 0x18

gUnknown_0858E898: ; 858E898
	.incbin "base_emerald.gba", 0x58e898, 0x13

gUnknown_0858E8AB: ; 858E8AB
	.incbin "base_emerald.gba", 0x58e8ab, 0x2

gUnknown_0858E8AD: ; 858E8AD
	.incbin "base_emerald.gba", 0x58e8ad, 0x3

gUnknown_0858E8B0: ; 858E8B0
	.incbin "base_emerald.gba", 0x58e8b0, 0x40

gUnknown_0858E8F0: ; 858E8F0
	.incbin "base_emerald.gba", 0x58e8f0, 0x3468

gUnknown_08591D58: ; 8591D58
	.incbin "base_emerald.gba", 0x591d58, 0x270

gUnknown_08591FC8: ; 8591FC8
	.incbin "base_emerald.gba", 0x591fc8, 0x18

gUnknown_08591FE0: ; 8591FE0
	.incbin "base_emerald.gba", 0x591fe0, 0x18

gUnknown_08591FF8: ; 8591FF8
	.incbin "base_emerald.gba", 0x591ff8, 0x10

gUnknown_08592008: ; 8592008
	.incbin "base_emerald.gba", 0x592008, 0x10

gUnknown_08592018: ; 8592018
	.incbin "base_emerald.gba", 0x592018, 0x10

gUnknown_08592028: ; 8592028
	.incbin "base_emerald.gba", 0x592028, 0x10

gUnknown_08592038: ; 8592038
	.incbin "base_emerald.gba", 0x592038, 0x20

gUnknown_08592058: ; 8592058
	.incbin "base_emerald.gba", 0x592058, 0x20

gUnknown_08592078: ; 8592078
	.incbin "base_emerald.gba", 0x592078, 0x60

gUnknown_085920D8: ; 85920D8
	.incbin "base_emerald.gba", 0x5920d8, 0xc

gUnknown_085920E4: ; 85920E4
	.incbin "base_emerald.gba", 0x5920e4, 0x4

gUnknown_085920E8: ; 85920E8
	.incbin "base_emerald.gba", 0x5920e8, 0x128

gUnknown_08592210: ; 8592210
	.incbin "base_emerald.gba", 0x592210, 0x4f0

gUnknown_08592700: ; 8592700
	.incbin "base_emerald.gba", 0x592700, 0x78

gUnknown_08592778: ; 8592778
	.incbin "base_emerald.gba", 0x592778, 0x100

gUnknown_08592878: ; 8592878
	.incbin "base_emerald.gba", 0x592878, 0x458

gUnknown_08592CD0: ; 8592CD0
	.incbin "base_emerald.gba", 0x592cd0, 0x1ec

gUnknown_08592EBC: ; 8592EBC
	.incbin "base_emerald.gba", 0x592ebc, 0x30

gUnknown_08592EEC: ; 8592EEC
	.incbin "base_emerald.gba", 0x592eec, 0x134

gUnknown_08593020: ; 8593020
	.incbin "base_emerald.gba", 0x593020, 0xf4

gUnknown_08593114: ; 8593114
	.incbin "base_emerald.gba", 0x593114, 0x29c

gUnknown_085933B0: ; 85933B0
	.incbin "base_emerald.gba", 0x5933b0, 0xf0

gUnknown_085934A0: ; 85934A0
	.incbin "base_emerald.gba", 0x5934a0, 0x148

gUnknown_085935E8: ; 85935E8
	.incbin "base_emerald.gba", 0x5935e8, 0x20

gUnknown_08593608: ; 8593608
	.incbin "base_emerald.gba", 0x593608, 0x9c

gUnknown_085936A4: ; 85936A4
	.incbin "base_emerald.gba", 0x5936a4, 0x20c

gUnknown_085938B0: ; 85938B0
	.incbin "base_emerald.gba", 0x5938b0, 0x2c

gUnknown_085938DC: ; 85938DC
	.incbin "base_emerald.gba", 0x5938dc, 0x18

gUnknown_085938F4: ; 85938F4
	.incbin "base_emerald.gba", 0x5938f4, 0x5c

gUnknown_08593950: ; 8593950
	.incbin "base_emerald.gba", 0x593950, 0x38

gUnknown_08593988: ; 8593988
	.incbin "base_emerald.gba", 0x593988, 0x210

gUnknown_08593B98: ; 8593B98
	.incbin "base_emerald.gba", 0x593b98, 0x1488

gUnknown_08595020: ; 8595020
	.incbin "base_emerald.gba", 0x595020, 0x248

gUnknown_08595268: ; 8595268
	.incbin "base_emerald.gba", 0x595268, 0xa8

gUnknown_08595310: ; 8595310
	.incbin "base_emerald.gba", 0x595310, 0x2a4

gUnknown_085955B4: ; 85955B4
	.incbin "base_emerald.gba", 0x5955b4, 0x18

gUnknown_085955CC: ; 85955CC
	.incbin "base_emerald.gba", 0x5955cc, 0x2

gUnknown_085955CE: ; 85955CE
	.incbin "base_emerald.gba", 0x5955ce, 0xb6

gUnknown_08595684: ; 8595684
	.incbin "base_emerald.gba", 0x595684, 0x10

gUnknown_08595694: ; 8595694
	.incbin "base_emerald.gba", 0x595694, 0x2c

gUnknown_085956C0: ; 85956C0
	.incbin "base_emerald.gba", 0x5956c0, 0x168

gUnknown_08595828: ; 8595828
	.incbin "base_emerald.gba", 0x595828, 0x18

gUnknown_08595840: ; 8595840
	.incbin "base_emerald.gba", 0x595840, 0x18

gUnknown_08595858: ; 8595858
	.incbin "base_emerald.gba", 0x595858, 0x50

gUnknown_085958A8: ; 85958A8
	.incbin "base_emerald.gba", 0x5958a8, 0x158

gUnknown_08595A00: ; 8595A00
	.incbin "base_emerald.gba", 0x595a00, 0x30

gUnknown_08595A30: ; 8595A30
	.incbin "base_emerald.gba", 0x595a30, 0x138

gUnknown_08595B68: ; 8595B68
	.incbin "base_emerald.gba", 0x595b68, 0xf4

gUnknown_08595C5C: ; 8595C5C
	.incbin "base_emerald.gba", 0x595c5c, 0x2c

gUnknown_08595C88: ; 8595C88
	.incbin "base_emerald.gba", 0x595c88, 0x2c

gUnknown_08595CB4: ; 8595CB4
	.incbin "base_emerald.gba", 0x595cb4, 0x78

gUnknown_08595D2C: ; 8595D2C
	.incbin "base_emerald.gba", 0x595d2c, 0xa14

gUnknown_08596740: ; 8596740
	.incbin "base_emerald.gba", 0x596740, 0x1c

gUnknown_0859675C: ; 859675C
	.incbin "base_emerald.gba", 0x59675c, 0x20

gUnknown_0859677C: ; 859677C
	.incbin "base_emerald.gba", 0x59677c, 0x18

gUnknown_08596794: ; 8596794
	.incbin "base_emerald.gba", 0x596794, 0xd0

gUnknown_08596864: ; 8596864
	.incbin "base_emerald.gba", 0x596864, 0x35c

gUnknown_08596BC0: ; 8596BC0
	.incbin "base_emerald.gba", 0x596bc0, 0x50

gUnknown_08596C10: ; 8596C10
	.incbin "base_emerald.gba", 0x596c10, 0x18

gUnknown_08596C28: ; 8596C28
	.incbin "base_emerald.gba", 0x596c28, 0x18

gUnknown_08596C40: ; 8596C40
	.incbin "base_emerald.gba", 0x596c40, 0x178

gUnknown_08596DB8: ; 8596DB8
	.incbin "base_emerald.gba", 0x596db8, 0x78

gUnknown_08596E30: ; 8596E30
	.incbin "base_emerald.gba", 0x596e30, 0x528

gUnknown_08597358: ; 8597358
	.incbin "base_emerald.gba", 0x597358, 0x30

gUnknown_08597388: ; 8597388
	.incbin "base_emerald.gba", 0x597388, 0x60

gUnknown_085973E8: ; 85973E8
	.incbin "base_emerald.gba", 0x5973e8, 0x30

gUnknown_08597418: ; 8597418
	.incbin "base_emerald.gba", 0x597418, 0x2

gUnknown_0859741A: ; 859741A
	.incbin "base_emerald.gba", 0x59741a, 0x4

gUnknown_0859741E: ; 859741E
	.incbin "base_emerald.gba", 0x59741e, 0x6

gUnknown_08597424: ; 8597424
	.incbin "base_emerald.gba", 0x597424, 0x28

gUnknown_0859744C: ; 859744C
	.incbin "base_emerald.gba", 0x59744c, 0x10

gUnknown_0859745C: ; 859745C
	.incbin "base_emerald.gba", 0x59745c, 0xc

gUnknown_08597468: ; 8597468
	.incbin "base_emerald.gba", 0x597468, 0x34

gUnknown_0859749C: ; 859749C
	.incbin "base_emerald.gba", 0x59749c, 0x1c

gUnknown_085974B8: ; 85974B8
	.incbin "base_emerald.gba", 0x5974b8, 0x8

gUnknown_085974C0: ; 85974C0
	.incbin "base_emerald.gba", 0x5974c0, 0x70

gUnknown_08597530: ; 8597530
	.incbin "base_emerald.gba", 0x597530, 0x20

gUnknown_08597550: ; 8597550
	.incbin "base_emerald.gba", 0x597550, 0x1f8

gUnknown_08597748: ; 8597748
	.incbin "base_emerald.gba", 0x597748, 0x1c

gUnknown_08597764: ; 8597764
	.incbin "base_emerald.gba", 0x597764, 0x8

gUnknown_0859776C: ; 859776C
	.incbin "base_emerald.gba", 0x59776c, 0x3a8

gUnknown_08597B14: ; 8597B14
	.incbin "base_emerald.gba", 0x597b14, 0x20

gUnknown_08597B34: ; 8597B34
	.incbin "base_emerald.gba", 0x597b34, 0x20

gUnknown_08597B54: ; 8597B54
	.incbin "base_emerald.gba", 0x597b54, 0xc8

gUnknown_08597C1C: ; 8597C1C
	.incbin "base_emerald.gba", 0x597c1c, 0x8

gUnknown_08597C24: ; 8597C24
	.incbin "base_emerald.gba", 0x597c24, 0xc

gUnknown_08597C30: ; 8597C30
	.incbin "base_emerald.gba", 0x597c30, 0x24

gUnknown_08597C54: ; 8597C54
	.incbin "base_emerald.gba", 0x597c54, 0x10

gUnknown_08597C64: ; 8597C64
	.incbin "base_emerald.gba", 0x597c64, 0x20

gUnknown_08597C84: ; 8597C84
	.incbin "base_emerald.gba", 0x597c84, 0x8

gUnknown_08597C8C: ; 8597C8C
	.incbin "base_emerald.gba", 0x597c8c, 0x4

gUnknown_08597C90: ; 8597C90
	.incbin "base_emerald.gba", 0x597c90, 0x10

gUnknown_08597CA0: ; 8597CA0
	.incbin "base_emerald.gba", 0x597ca0, 0x20

gUnknown_08597CC0: ; 8597CC0
	.incbin "base_emerald.gba", 0x597cc0, 0x28

gUnknown_08597CE8: ; 8597CE8
	.incbin "base_emerald.gba", 0x597ce8, 0x20

gUnknown_08597D08: ; 8597D08
	.incbin "base_emerald.gba", 0x597d08, 0x10

gUnknown_08597D18: ; 8597D18
	.incbin "base_emerald.gba", 0x597d18, 0x50

gUnknown_08597D68: ; 8597D68
	.incbin "base_emerald.gba", 0x597d68, 0x68

gUnknown_08597DD0: ; 8597DD0
	.incbin "base_emerald.gba", 0x597dd0, 0x20

gUnknown_08597DF0: ; 8597DF0
	.incbin "base_emerald.gba", 0x597df0, 0x40

gUnknown_08597E30: ; 8597E30
	.incbin "base_emerald.gba", 0x597e30, 0x18

gUnknown_08597E48: ; 8597E48
	.incbin "base_emerald.gba", 0x597e48, 0x18

gUnknown_08597E60: ; 8597E60
	.incbin "base_emerald.gba", 0x597e60, 0xc

gUnknown_08597E6C: ; 8597E6C
	.incbin "base_emerald.gba", 0x597e6c, 0x5198

gUnknown_0859D004: ; 859D004
	.incbin "base_emerald.gba", 0x59d004, 0x1468

gUnknown_0859E46C: ; 859E46C
	.incbin "base_emerald.gba", 0x59e46c, 0x168

gUnknown_0859E5D4: ; 859E5D4
	.incbin "base_emerald.gba", 0x59e5d4, 0x58

gUnknown_0859E62C: ; 859E62C
	.incbin "base_emerald.gba", 0x59e62c, 0x8

gUnknown_0859E634: ; 859E634
	.incbin "base_emerald.gba", 0x59e634, 0xc

gUnknown_0859E640: ; 859E640
	.incbin "base_emerald.gba", 0x59e640, 0xc

gUnknown_0859E64C: ; 859E64C
	.incbin "base_emerald.gba", 0x59e64c, 0xc

gUnknown_0859E658: ; 859E658
	.incbin "base_emerald.gba", 0x59e658, 0x4

gUnknown_0859E65C: ; 859E65C
	.incbin "base_emerald.gba", 0x59e65c, 0x20

gUnknown_0859E67C: ; 859E67C
	.incbin "base_emerald.gba", 0x59e67c, 0x800

gUnknown_0859EE7C: ; 859EE7C
	.incbin "base_emerald.gba", 0x59ee7c, 0x8

gUnknown_0859EE84: ; 859EE84
	.incbin "base_emerald.gba", 0x59ee84, 0x58

gUnknown_0859EEDC: ; 859EEDC
	.incbin "base_emerald.gba", 0x59eedc, 0x38

gUnknown_0859EF14: ; 859EF14
	.incbin "base_emerald.gba", 0x59ef14, 0x8

gUnknown_0859EF1C: ; 859EF1C
	.incbin "base_emerald.gba", 0x59ef1c, 0x88

gUnknown_0859EFA4: ; 859EFA4
	.incbin "base_emerald.gba", 0x59efa4, 0x40

gUnknown_0859EFE4: ; 859EFE4
	.incbin "base_emerald.gba", 0x59efe4, 0xc

gUnknown_0859EFF0: ; 859EFF0
	.incbin "base_emerald.gba", 0x59eff0, 0x20

gUnknown_0859F010: ; 859F010
	.incbin "base_emerald.gba", 0x59f010, 0x20

gUnknown_0859F030: ; 859F030
	.incbin "base_emerald.gba", 0x59f030, 0x18

gUnknown_0859F048: ; 859F048
	.incbin "base_emerald.gba", 0x59f048, 0x230

gUnknown_0859F278: ; 859F278
	.incbin "base_emerald.gba", 0x59f278, 0x10

gUnknown_0859F288: ; 859F288
	.incbin "base_emerald.gba", 0x59f288, 0x8

gUnknown_0859F290: ; 859F290
	.incbin "base_emerald.gba", 0x59f290, 0xc

gUnknown_0859F29C: ; 859F29C
	.incbin "base_emerald.gba", 0x59f29c, 0x10

gUnknown_0859F2AC: ; 859F2AC
	.incbin "base_emerald.gba", 0x59f2ac, 0x4

gUnknown_0859F2B0: ; 859F2B0
	.incbin "base_emerald.gba", 0x59f2b0, 0x8

gUnknown_0859F2B8: ; 859F2B8
	.incbin "base_emerald.gba", 0x59f2b8, 0xfc

gUnknown_0859F3B4: ; 859F3B4
	.incbin "base_emerald.gba", 0x59f3b4, 0xa4

gUnknown_0859F458: ; 859F458
	.incbin "base_emerald.gba", 0x59f458, 0xbc

gUnknown_0859F514: ; 859F514
	.incbin "base_emerald.gba", 0x59f514, 0x8

gUnknown_0859F51C: ; 859F51C
	.incbin "base_emerald.gba", 0x59f51c, 0x8

gUnknown_0859F524: ; 859F524
	.incbin "base_emerald.gba", 0x59f524, 0x10

gUnknown_0859F534: ; 859F534
	.incbin "base_emerald.gba", 0x59f534, 0x8

gUnknown_0859F53C: ; 859F53C
	.incbin "base_emerald.gba", 0x59f53c, 0xd0

gUnknown_0859F60C: ; 859F60C
	.incbin "base_emerald.gba", 0x59f60c, 0x44

gUnknown_0859F650: ; 859F650
	.incbin "base_emerald.gba", 0x59f650, 0xec

gUnknown_0859F73C: ; 859F73C
	.incbin "base_emerald.gba", 0x59f73c, 0x40

gUnknown_0859F77C: ; 859F77C
	.incbin "base_emerald.gba", 0x59f77c, 0xd64

gUnknown_085A04E0: ; 85A04E0
	.incbin "base_emerald.gba", 0x5a04e0, 0x34c

gUnknown_085A082C: ; 85A082C
	.incbin "base_emerald.gba", 0x5a082c, 0x20

gUnknown_085A084C: ; 85A084C
	.incbin "base_emerald.gba", 0x5a084c, 0x80

gUnknown_085A08CC: ; 85A08CC
	.incbin "base_emerald.gba", 0x5a08cc, 0x20

gUnknown_085A08EC: ; 85A08EC
	.incbin "base_emerald.gba", 0x5a08ec, 0x80

gUnknown_085A096C: ; 85A096C
	.incbin "base_emerald.gba", 0x5a096c, 0xb10

gUnknown_085A147C: ; 85A147C
	.incbin "base_emerald.gba", 0x5a147c, 0x6a8

gUnknown_085A1B24: ; 85A1B24
	.incbin "base_emerald.gba", 0x5a1b24, 0x60

gUnknown_085A1B84: ; 85A1B84
	.incbin "base_emerald.gba", 0x5a1b84, 0x6

gUnknown_085A1B8A: ; 85A1B8A
	.incbin "base_emerald.gba", 0x5a1b8a, 0x22

gUnknown_085A1BAC: ; 85A1BAC
	.incbin "base_emerald.gba", 0x5a1bac, 0x20

gUnknown_085A1BCC: ; 85A1BCC
	.incbin "base_emerald.gba", 0x5a1bcc, 0x34

gUnknown_085A1C00: ; 85A1C00
	.incbin "base_emerald.gba", 0x5a1c00, 0x8

gUnknown_085A1C08: ; 85A1C08
	.incbin "base_emerald.gba", 0x5a1c08, 0x18

gUnknown_085A1C20: ; 85A1C20
	.incbin "base_emerald.gba", 0x5a1c20, 0x10

gUnknown_085A1C30: ; 85A1C30
	.incbin "base_emerald.gba", 0x5a1c30, 0x4

gUnknown_085A1C34: ; 85A1C34
	.incbin "base_emerald.gba", 0x5a1c34, 0x4

gUnknown_085A1C38: ; 85A1C38
	.incbin "base_emerald.gba", 0x5a1c38, 0x20

gUnknown_085A1C58: ; 85A1C58
	.incbin "base_emerald.gba", 0x5a1c58, 0x38

gUnknown_085A1C90: ; 85A1C90
	.incbin "base_emerald.gba", 0x5a1c90, 0xd8

gUnknown_085A1D68: ; 85A1D68
	.incbin "base_emerald.gba", 0x5a1d68, 0xd4

gUnknown_085A1E3C: ; 85A1E3C
	.incbin "base_emerald.gba", 0x5a1e3c, 0xa0

gUnknown_085A1EDC: ; 85A1EDC
	.incbin "base_emerald.gba", 0x5a1edc, 0x8

gUnknown_085A1EE4: ; 85A1EE4
	.incbin "base_emerald.gba", 0x5a1ee4, 0xc

gUnknown_085A1EF0: ; 85A1EF0
	.incbin "base_emerald.gba", 0x5a1ef0, 0x20

gUnknown_085A1F10: ; 85A1F10
	.incbin "base_emerald.gba", 0x5a1f10, 0x8

gUnknown_085A1F18: ; 85A1F18
	.incbin "base_emerald.gba", 0x5a1f18, 0x64

gUnknown_085A1F7C: ; 85A1F7C
	.incbin "base_emerald.gba", 0x5a1f7c, 0x18

gUnknown_085A1F94: ; 85A1F94
	.incbin "base_emerald.gba", 0x5a1f94, 0x3c74

gUnknown_085A5C08: ; 85A5C08
	.incbin "base_emerald.gba", 0x5a5c08, 0x1

gUnknown_085A5C09: ; 85A5C09
	.incbin "base_emerald.gba", 0x5a5c09, 0x1b

gUnknown_085A5C24: ; 85A5C24
	.incbin "base_emerald.gba", 0x5a5c24, 0xf04

gUnknown_085A6B28: ; 85A6B28
	.incbin "base_emerald.gba", 0x5a6b28, 0x20

gUnknown_085A6B48: ; 85A6B48
	.incbin "base_emerald.gba", 0x5a6b48, 0x20

gUnknown_085A6B68: ; 85A6B68
	.incbin "base_emerald.gba", 0x5a6b68, 0x10

gUnknown_085A6B78: ; 85A6B78
	.incbin "base_emerald.gba", 0x5a6b78, 0x18

gUnknown_085A6B90: ; 85A6B90
	.incbin "base_emerald.gba", 0x5a6b90, 0x20

gUnknown_085A6BB0: ; 85A6BB0
	.incbin "base_emerald.gba", 0x5a6bb0, 0x20

gUnknown_085A6BD0: ; 85A6BD0
	.incbin "base_emerald.gba", 0x5a6bd0, 0x18

gUnknown_085A6BE8: ; 85A6BE8
	.incbin "base_emerald.gba", 0x5a6be8, 0x5c8

gUnknown_085A71B0: ; 85A71B0
	.incbin "base_emerald.gba", 0x5a71b0, 0xa0

gUnknown_085A7250: ; 85A7250
	.incbin "base_emerald.gba", 0x5a7250, 0x3c

gUnknown_085A728C: ; 85A728C
	.incbin "base_emerald.gba", 0x5a728c, 0x18

gUnknown_085A72A4: ; 85A72A4
	.incbin "base_emerald.gba", 0x5a72a4, 0x18

gUnknown_085A72BC: ; 85A72BC
	.incbin "base_emerald.gba", 0x5a72bc, 0x8

gUnknown_085A72C4: ; 85A72C4
	.incbin "base_emerald.gba", 0x5a72c4, 0x8

gUnknown_085A72CC: ; 85A72CC
	.incbin "base_emerald.gba", 0x5a72cc, 0x8

gUnknown_085A72D4: ; 85A72D4
	.incbin "base_emerald.gba", 0x5a72d4, 0x10

gUnknown_085A72E4: ; 85A72E4
	.incbin "base_emerald.gba", 0x5a72e4, 0x8

gUnknown_085A72EC: ; 85A72EC
	.incbin "base_emerald.gba", 0x5a72ec, 0x8

gUnknown_085A72F4: ; 85A72F4
	.incbin "base_emerald.gba", 0x5a72f4, 0x54

gUnknown_085A7348: ; 85A7348
	.incbin "base_emerald.gba", 0x5a7348, 0x8

gUnknown_085A7350: ; 85A7350
	.incbin "base_emerald.gba", 0x5a7350, 0x88

gUnknown_085A73D8: ; 85A73D8
	.incbin "base_emerald.gba", 0x5a73d8, 0x8

gUnknown_085A73E0: ; 85A73E0
	.incbin "base_emerald.gba", 0x5a73e0, 0x24

gUnknown_085A7404: ; 85A7404
	.incbin "base_emerald.gba", 0x5a7404, 0x18

gUnknown_085A741C: ; 85A741C
	.incbin "base_emerald.gba", 0x5a741c, 0x8

gUnknown_085A7424: ; 85A7424
	.incbin "base_emerald.gba", 0x5a7424, 0x10

gUnknown_085A7434: ; 85A7434
	.incbin "base_emerald.gba", 0x5a7434, 0x10

gUnknown_085A7444: ; 85A7444
	.incbin "base_emerald.gba", 0x5a7444, 0x8

gUnknown_085A744C: ; 85A744C
	.incbin "base_emerald.gba", 0x5a744c, 0x4

gUnknown_085A7450: ; 85A7450
	.incbin "base_emerald.gba", 0x5a7450, 0x74

gUnknown_085A74C4: ; 85A74C4
	.incbin "base_emerald.gba", 0x5a74c4, 0xc

gUnknown_085A74D0: ; 85A74D0
	.incbin "base_emerald.gba", 0x5a74d0, 0x14

gUnknown_085A74E4: ; 85A74E4
	.incbin "base_emerald.gba", 0x5a74e4, 0xc

gUnknown_085A74F0: ; 85A74F0
	.incbin "base_emerald.gba", 0x5a74f0, 0xc

gUnknown_085A74FC: ; 85A74FC
	.incbin "base_emerald.gba", 0x5a74fc, 0xc

gUnknown_085A7508: ; 85A7508
	.incbin "base_emerald.gba", 0x5a7508, 0xc

gUnknown_085A7514: ; 85A7514
	.incbin "base_emerald.gba", 0x5a7514, 0xc

gUnknown_085A7520: ; 85A7520
	.incbin "base_emerald.gba", 0x5a7520, 0xc

gUnknown_085A752C: ; 85A752C
	.incbin "base_emerald.gba", 0x5a752c, 0xc

gUnknown_085A7538: ; 85A7538
	.incbin "base_emerald.gba", 0x5a7538, 0xc

gUnknown_085A7544: ; 85A7544
	.incbin "base_emerald.gba", 0x5a7544, 0xc

gUnknown_085A7550: ; 85A7550
	.incbin "base_emerald.gba", 0x5a7550, 0x8

gUnknown_085A7558: ; 85A7558
	.incbin "base_emerald.gba", 0x5a7558, 0x10

gUnknown_085A7568: ; 85A7568
	.incbin "base_emerald.gba", 0x5a7568, 0x2

gUnknown_085A756A: ; 85A756A
	.incbin "base_emerald.gba", 0x5a756a, 0xa

gUnknown_085A7574: ; 85A7574
	.incbin "base_emerald.gba", 0x5a7574, 0x4c

gUnknown_085A75C0: ; 85A75C0
	.incbin "base_emerald.gba", 0x5a75c0, 0x4

gUnknown_085A75C4: ; 85A75C4
	.incbin "base_emerald.gba", 0x5a75c4, 0x8

gUnknown_085A75CC: ; 85A75CC
	.incbin "base_emerald.gba", 0x5a75cc, 0x8

gUnknown_085A75D4: ; 85A75D4
	.incbin "base_emerald.gba", 0x5a75d4, 0x3c

gUnknown_085A7610: ; 85A7610
	.incbin "base_emerald.gba", 0x5a7610, 0x4

gUnknown_085A7614: ; 85A7614
	.incbin "base_emerald.gba", 0x5a7614, 0x2

gUnknown_085A7616: ; 85A7616
	.incbin "base_emerald.gba", 0x5a7616, 0x8

gUnknown_085A761E: ; 85A761E
	.incbin "base_emerald.gba", 0x5a761e, 0x8

gUnknown_085A7626: ; 85A7626
	.incbin "base_emerald.gba", 0x5a7626, 0x8

gUnknown_085A762E: ; 85A762E
	.incbin "base_emerald.gba", 0x5a762e, 0x10

gUnknown_085A763E: ; 85A763E
	.incbin "base_emerald.gba", 0x5a763e, 0x10

gUnknown_085A764E: ; 85A764E
	.incbin "base_emerald.gba", 0x5a764e, 0x10

gUnknown_085A765E: ; 85A765E
	.incbin "base_emerald.gba", 0x5a765e, 0x10

gUnknown_085A766E: ; 85A766E
	.incbin "base_emerald.gba", 0x5a766e, 0x3f

gUnknown_085A76AD: ; 85A76AD
	.incbin "base_emerald.gba", 0x5a76ad, 0x7

gUnknown_085A76B4: ; 85A76B4
	.incbin "base_emerald.gba", 0x5a76b4, 0xc

gUnknown_085A76C0: ; 85A76C0
	.incbin "base_emerald.gba", 0x5a76c0, 0x12

gUnknown_085A76D2: ; 85A76D2
	.incbin "base_emerald.gba", 0x5a76d2, 0x12

gUnknown_085A76E4: ; 85A76E4
	.incbin "base_emerald.gba", 0x5a76e4, 0x1e

gUnknown_085A7702: ; 85A7702
	.incbin "base_emerald.gba", 0x5a7702, 0x66

gUnknown_085A7768: ; 85A7768
	.incbin "base_emerald.gba", 0x5a7768, 0x66

gUnknown_085A77CE: ; 85A77CE
	.incbin "base_emerald.gba", 0x5a77ce, 0xa

gUnknown_085A77D8: ; 85A77D8
	.incbin "base_emerald.gba", 0x5a77d8, 0x14

gUnknown_085A77EC: ; 85A77EC
	.incbin "base_emerald.gba", 0x5a77ec, 0xa

gUnknown_085A77F6: ; 85A77F6
	.incbin "base_emerald.gba", 0x5a77f6, 0x8

gUnknown_085A77FE: ; 85A77FE
	.incbin "base_emerald.gba", 0x5a77fe, 0x6

gUnknown_085A7804: ; 85A7804
	.incbin "base_emerald.gba", 0x5a7804, 0xa

gUnknown_085A780E: ; 85A780E
	.incbin "base_emerald.gba", 0x5a780e, 0x8

gUnknown_085A7816: ; 85A7816
	.incbin "base_emerald.gba", 0x5a7816, 0x12

gUnknown_085A7828: ; 85A7828
	.incbin "base_emerald.gba", 0x5a7828, 0x12

gUnknown_085A783A: ; 85A783A
	.incbin "base_emerald.gba", 0x5a783a, 0x8e

gUnknown_085A78C8: ; 85A78C8
	.incbin "base_emerald.gba", 0x5a78c8, 0x13c

gUnknown_085A7A04: ; 85A7A04
	.incbin "base_emerald.gba", 0x5a7a04, 0x1c

gUnknown_085A7A20: ; 85A7A20
	.incbin "base_emerald.gba", 0x5a7a20, 0x2c0

gUnknown_085A7CE0: ; 85A7CE0
	.incbin "base_emerald.gba", 0x5a7ce0, 0x18

gUnknown_085A7CF8: ; 85A7CF8
	.incbin "base_emerald.gba", 0x5a7cf8, 0x18

gUnknown_085A7D10: ; 85A7D10
	.incbin "base_emerald.gba", 0x5a7d10, 0x18

gUnknown_085A7D28: ; 85A7D28
	.incbin "base_emerald.gba", 0x5a7d28, 0x18

gUnknown_085A7D40: ; 85A7D40
	.incbin "base_emerald.gba", 0x5a7d40, 0x18

gUnknown_085A7D58: ; 85A7D58
	.incbin "base_emerald.gba", 0x5a7d58, 0x18

gUnknown_085A7D70: ; 85A7D70
	.incbin "base_emerald.gba", 0x5a7d70, 0x18

gUnknown_085A7D88: ; 85A7D88
	.incbin "base_emerald.gba", 0x5a7d88, 0x18

gUnknown_085A7DA0: ; 85A7DA0
	.incbin "base_emerald.gba", 0x5a7da0, 0x18

gUnknown_085A7DB8: ; 85A7DB8
	.incbin "base_emerald.gba", 0x5a7db8, 0x18

gUnknown_085A7DD0: ; 85A7DD0
	.incbin "base_emerald.gba", 0x5a7dd0, 0x18

gUnknown_085A7DE8: ; 85A7DE8
	.incbin "base_emerald.gba", 0x5a7de8, 0x18

gUnknown_085A7E00: ; 85A7E00
	.incbin "base_emerald.gba", 0x5a7e00, 0x18

gUnknown_085A7E18: ; 85A7E18
	.incbin "base_emerald.gba", 0x5a7e18, 0x18

gUnknown_085A7E30: ; 85A7E30
	.incbin "base_emerald.gba", 0x5a7e30, 0x168

gUnknown_085A7F98: ; 85A7F98
	.incbin "base_emerald.gba", 0x5a7f98, 0x28

gUnknown_085A7FC0: ; 85A7FC0
	.incbin "base_emerald.gba", 0x5a7fc0, 0x20

gUnknown_085A7FE0: ; 85A7FE0
	.incbin "base_emerald.gba", 0x5a7fe0, 0x14

gUnknown_085A7FF4: ; 85A7FF4
	.incbin "base_emerald.gba", 0x5a7ff4, 0x1c

gUnknown_085A8010: ; 85A8010
	.incbin "base_emerald.gba", 0x5a8010, 0x18

gUnknown_085A8028: ; 85A8028
	.incbin "base_emerald.gba", 0x5a8028, 0x14

gUnknown_085A803C: ; 85A803C
	.incbin "base_emerald.gba", 0x5a803c, 0x228

gUnknown_085A8264: ; 85A8264
	.incbin "base_emerald.gba", 0x5a8264, 0x68

gUnknown_085A82CC: ; 85A82CC
	.incbin "base_emerald.gba", 0x5a82cc, 0x68

gUnknown_085A8334: ; 85A8334
	.incbin "base_emerald.gba", 0x5a8334, 0xb0

gUnknown_085A83E4: ; 85A83E4
	.incbin "base_emerald.gba", 0x5a83e4, 0x24

gUnknown_085A8408: ; 85A8408
	.incbin "base_emerald.gba", 0x5a8408, 0x14

gUnknown_085A841C: ; 85A841C
	.incbin "base_emerald.gba", 0x5a841c, 0x14

gUnknown_085A8430: ; 85A8430
	.incbin "base_emerald.gba", 0x5a8430, 0x5

gUnknown_085A8435: ; 85A8435
	.incbin "base_emerald.gba", 0x5a8435, 0x6

gUnknown_085A843B: ; 85A843B
	.incbin "base_emerald.gba", 0x5a843b, 0x65

gUnknown_085A84A0: ; 85A84A0
	.incbin "base_emerald.gba", 0x5a84a0, 0xc

gUnknown_085A84AC: ; 85A84AC
	.incbin "base_emerald.gba", 0x5a84ac, 0x64

gUnknown_085A8510: ; 85A8510
	.incbin "base_emerald.gba", 0x5a8510, 0x10

gUnknown_085A8520: ; 85A8520
	.incbin "base_emerald.gba", 0x5a8520, 0x4

gUnknown_085A8524: ; 85A8524
	.incbin "base_emerald.gba", 0x5a8524, 0x20

gUnknown_085A8544: ; 85A8544
	.incbin "base_emerald.gba", 0x5a8544, 0x48

gUnknown_085A858C: ; 85A858C
	.incbin "base_emerald.gba", 0x5a858c, 0x1154

gUnknown_085A96E0: ; 85A96E0
	.incbin "base_emerald.gba", 0x5a96e0, 0x1b8

gUnknown_085A9898: ; 85A9898
	.incbin "base_emerald.gba", 0x5a9898, 0x4

gUnknown_085A989C: ; 85A989C
	.incbin "base_emerald.gba", 0x5a989c, 0x200

gUnknown_085A9A9C: ; 85A9A9C
	.incbin "base_emerald.gba", 0x5a9a9c, 0x1084

gUnknown_085AAB20: ; 85AAB20
	.incbin "base_emerald.gba", 0x5aab20, 0xc30

gUnknown_085AB750: ; 85AB750
	.incbin "base_emerald.gba", 0x5ab750, 0xb38

gUnknown_085AC288: ; 85AC288
	.incbin "base_emerald.gba", 0x5ac288, 0xfb8

gUnknown_085AD240: ; 85AD240
	.incbin "base_emerald.gba", 0x5ad240, 0x1130

gUnknown_085AE370: ; 85AE370
	.incbin "base_emerald.gba", 0x5ae370, 0x604

gUnknown_085AE974: ; 85AE974
	.incbin "base_emerald.gba", 0x5ae974, 0x50c

gUnknown_085AEE80: ; 85AEE80
	.incbin "base_emerald.gba", 0x5aee80, 0x50c

gUnknown_085AF38C: ; 85AF38C
	.incbin "base_emerald.gba", 0x5af38c, 0x50c

gUnknown_085AF898: ; 85AF898
	.incbin "base_emerald.gba", 0x5af898, 0x50c

gUnknown_085AFDA4: ; 85AFDA4
	.incbin "base_emerald.gba", 0x5afda4, 0x50c

gUnknown_085B02B0: ; 85B02B0
	.incbin "base_emerald.gba", 0x5b02b0, 0x524

gUnknown_085B07D4: ; 85B07D4
	.incbin "base_emerald.gba", 0x5b07d4, 0x14

gUnknown_085B07E8: ; 85B07E8
	.incbin "base_emerald.gba", 0x5b07e8, 0x4

gUnknown_085B07EC: ; 85B07EC
	.incbin "base_emerald.gba", 0x5b07ec, 0x8

gUnknown_085B07F4: ; 85B07F4
	.incbin "base_emerald.gba", 0x5b07f4, 0x3c

gUnknown_085B0830: ; 85B0830
	.incbin "base_emerald.gba", 0x5b0830, 0x8

gUnknown_085B0838: ; 85B0838
	.incbin "base_emerald.gba", 0x5b0838, 0x4

gUnknown_085B083C: ; 85B083C
	.incbin "base_emerald.gba", 0x5b083c, 0x18c

gUnknown_085B09C8: ; 85B09C8
	.incbin "base_emerald.gba", 0x5b09c8, 0x1c

gUnknown_085B09E4: ; 85B09E4
	.incbin "base_emerald.gba", 0x5b09e4, 0x10

gUnknown_085B09F4: ; 85B09F4
	.incbin "base_emerald.gba", 0x5b09f4, 0x4

gUnknown_085B09F8: ; 85B09F8
	.incbin "base_emerald.gba", 0x5b09f8, 0x8

gUnknown_085B0A00: ; 85B0A00
	.incbin "base_emerald.gba", 0x5b0a00, 0x2

gUnknown_085B0A02: ; 85B0A02
	.incbin "base_emerald.gba", 0x5b0a02, 0x7e

gUnknown_085B0A80: ; 85B0A80
	.incbin "base_emerald.gba", 0x5b0a80, 0x18c

gUnknown_085B0C0C: ; 85B0C0C
	.incbin "base_emerald.gba", 0x5b0c0c, 0x1f8

gUnknown_085B0E04: ; 85B0E04
	.incbin "base_emerald.gba", 0x5b0e04, 0xfc8

gUnknown_085B1DCC: ; 85B1DCC
	.incbin "base_emerald.gba", 0x5b1dcc, 0x10

gUnknown_085B1DDC: ; 85B1DDC
	.incbin "base_emerald.gba", 0x5b1ddc, 0x8

gUnknown_085B1DE4: ; 85B1DE4
	.incbin "base_emerald.gba", 0x5b1de4, 0x8

gUnknown_085B1DEC: ; 85B1DEC
	.incbin "base_emerald.gba", 0x5b1dec, 0x6

gUnknown_085B1DF2: ; 85B1DF2
	.incbin "base_emerald.gba", 0x5b1df2, 0x6

gUnknown_085B1DF8: ; 85B1DF8
	.incbin "base_emerald.gba", 0x5b1df8, 0x8

gUnknown_085B1E00: ; 85B1E00
	.incbin "base_emerald.gba", 0x5b1e00, 0xc

gUnknown_085B1E0C: ; 85B1E0C
	.incbin "base_emerald.gba", 0x5b1e0c, 0x1c

gUnknown_085B1E28: ; 85B1E28
	.incbin "base_emerald.gba", 0x5b1e28, 0xa8

gUnknown_085B1ED0: ; 85B1ED0
	.incbin "base_emerald.gba", 0x5b1ed0, 0x8

gUnknown_085B1ED8: ; 85B1ED8
	.incbin "base_emerald.gba", 0x5b1ed8, 0x10

gUnknown_085B1EE8: ; 85B1EE8
	.incbin "base_emerald.gba", 0x5b1ee8, 0x10

gUnknown_085B1EF8: ; 85B1EF8
	.incbin "base_emerald.gba", 0x5b1ef8, 0x18

gUnknown_085B1F10: ; 85B1F10
	.incbin "base_emerald.gba", 0x5b1f10, 0x18

gUnknown_085B1F28: ; 85B1F28
	.incbin "base_emerald.gba", 0x5b1f28, 0x18

gUnknown_085B1F40: ; 85B1F40
	.incbin "base_emerald.gba", 0x5b1f40, 0x294

gUnknown_085B21D4: ; 85B21D4
	.incbin "base_emerald.gba", 0x5b21d4, 0x8

gUnknown_085B21DC: ; 85B21DC
	.incbin "base_emerald.gba", 0x5b21dc, 0x18

gUnknown_085B21F4: ; 85B21F4
	.incbin "base_emerald.gba", 0x5b21f4, 0x8

gUnknown_085B21FC: ; 85B21FC
	.incbin "base_emerald.gba", 0x5b21fc, 0xc

gUnknown_085B2208: ; 85B2208
	.incbin "base_emerald.gba", 0x5b2208, 0x10

gUnknown_085B2218: ; 85B2218
	.incbin "base_emerald.gba", 0x5b2218, 0x38

gUnknown_085B2250: ; 85B2250
	.incbin "base_emerald.gba", 0x5b2250, 0x18

gUnknown_085B2268: ; 85B2268
	.incbin "base_emerald.gba", 0x5b2268, 0x38

gUnknown_085B22A0: ; 85B22A0
	.incbin "base_emerald.gba", 0x5b22a0, 0x18

gUnknown_085B22B8: ; 85B22B8
	.incbin "base_emerald.gba", 0x5b22b8, 0x18

gUnknown_085B22D0: ; 85B22D0
	.incbin "base_emerald.gba", 0x5b22d0, 0x2d0

gUnknown_085B25A0: ; 85B25A0
	.incbin "base_emerald.gba", 0x5b25a0, 0x80

gUnknown_085B2620: ; 85B2620
	.incbin "base_emerald.gba", 0x5b2620, 0xc

gUnknown_085B262C: ; 85B262C
	.incbin "base_emerald.gba", 0x5b262c, 0x3c

gUnknown_085B2668: ; 85B2668
	.incbin "base_emerald.gba", 0x5b2668, 0x30

gUnknown_085B2698: ; 85B2698
	.incbin "base_emerald.gba", 0x5b2698, 0x3

gUnknown_085B269B: ; 85B269B
	.incbin "base_emerald.gba", 0x5b269b, 0x2

gUnknown_085B269D: ; 85B269D
	.incbin "base_emerald.gba", 0x5b269d, 0x2

gUnknown_085B269F: ; 85B269F
	.incbin "base_emerald.gba", 0x5b269f, 0x5

gUnknown_085B26A4: ; 85B26A4
	.incbin "base_emerald.gba", 0x5b26a4, 0x4c

gUnknown_085B26F0: ; 85B26F0
	.incbin "base_emerald.gba", 0x5b26f0, 0x4

gUnknown_085B26F4: ; 85B26F4
	.incbin "base_emerald.gba", 0x5b26f4, 0x8

gUnknown_085B26FC: ; 85B26FC
	.incbin "base_emerald.gba", 0x5b26fc, 0x8

gUnknown_085B2704: ; 85B2704
	.incbin "base_emerald.gba", 0x5b2704, 0x18

gUnknown_085B271C: ; 85B271C
	.incbin "base_emerald.gba", 0x5b271c, 0x4

gUnknown_085B2720: ; 85B2720
	.incbin "base_emerald.gba", 0x5b2720, 0x28

gUnknown_085B2748: ; 85B2748
	.incbin "base_emerald.gba", 0x5b2748, 0x60

gUnknown_085B27A8: ; 85B27A8
	.incbin "base_emerald.gba", 0x5b27a8, 0x8

gUnknown_085B27B0: ; 85B27B0
	.incbin "base_emerald.gba", 0x5b27b0, 0x18

gUnknown_085B27C8: ; 85B27C8
	.incbin "base_emerald.gba", 0x5b27c8, 0x88

gUnknown_085B2850: ; 85B2850
	.incbin "base_emerald.gba", 0x5b2850, 0x20

gUnknown_085B2870: ; 85B2870
	.incbin "base_emerald.gba", 0x5b2870, 0x20

gUnknown_085B2890: ; 85B2890
	.incbin "base_emerald.gba", 0x5b2890, 0x10

gUnknown_085B28A0: ; 85B28A0
	.incbin "base_emerald.gba", 0x5b28a0, 0x10

gUnknown_085B28B0: ; 85B28B0
	.incbin "base_emerald.gba", 0x5b28b0, 0x1e0

gUnknown_085B2A90: ; 85B2A90
	.incbin "base_emerald.gba", 0x5b2a90, 0xb4

gUnknown_085B2B44: ; 85B2B44
	.incbin "base_emerald.gba", 0x5b2b44, 0x18

gUnknown_085B2B5C: ; 85B2B5C
	.incbin "base_emerald.gba", 0x5b2b5c, 0x4

gUnknown_085B2B60: ; 85B2B60
	.incbin "base_emerald.gba", 0x5b2b60, 0x8

gUnknown_085B2B68: ; 85B2B68
	.incbin "base_emerald.gba", 0x5b2b68, 0x10

gUnknown_085B2B78: ; 85B2B78
	.incbin "base_emerald.gba", 0x5b2b78, 0x6

gUnknown_085B2B7E: ; 85B2B7E
	.incbin "base_emerald.gba", 0x5b2b7e, 0xa

gUnknown_085B2B88: ; 85B2B88
	.incbin "base_emerald.gba", 0x5b2b88, 0xc

gUnknown_085B2B94: ; 85B2B94
	.incbin "base_emerald.gba", 0x5b2b94, 0xc

gUnknown_085B2BA0: ; 85B2BA0
	.incbin "base_emerald.gba", 0x5b2ba0, 0xc

gUnknown_085B2BAC: ; 85B2BAC
	.incbin "base_emerald.gba", 0x5b2bac, 0x8

gUnknown_085B2BB4: ; 85B2BB4
	.incbin "base_emerald.gba", 0x5b2bb4, 0x40

gUnknown_085B2BF4: ; 85B2BF4
	.incbin "base_emerald.gba", 0x5b2bf4, 0x12

gUnknown_085B2C06: ; 85B2C06
	.incbin "base_emerald.gba", 0x5b2c06, 0x12

gUnknown_085B2C18: ; 85B2C18
	.incbin "base_emerald.gba", 0x5b2c18, 0x9

gUnknown_085B2C21: ; 85B2C21
	.incbin "base_emerald.gba", 0x5b2c21, 0x9

gUnknown_085B2C2A: ; 85B2C2A
	.incbin "base_emerald.gba", 0x5b2c2a, 0x26

gUnknown_085B2C50: ; 85B2C50
	.incbin "base_emerald.gba", 0x5b2c50, 0x78

gUnknown_085B2CC8: ; 85B2CC8
	.incbin "base_emerald.gba", 0x5b2cc8, 0x14

gUnknown_085B2CDC: ; 85B2CDC
	.incbin "base_emerald.gba", 0x5b2cdc, 0x14

gUnknown_085B2CF0: ; 85B2CF0
	.incbin "base_emerald.gba", 0x5b2cf0, 0x340

gUnknown_085B3030: ; 85B3030
	.incbin "base_emerald.gba", 0x5b3030, 0x10

gUnknown_085B3040: ; 85B3040
	.incbin "base_emerald.gba", 0x5b3040, 0x64

gUnknown_085B30A4: ; 85B30A4
	.incbin "base_emerald.gba", 0x5b30a4, 0x30

gUnknown_085B30D4: ; 85B30D4
	.incbin "base_emerald.gba", 0x5b30d4, 0x30

gUnknown_085B3104: ; 85B3104
	.incbin "base_emerald.gba", 0x5b3104, 0x18

gUnknown_085B311C: ; 85B311C
	.incbin "base_emerald.gba", 0x5b311c, 0x8

gUnknown_085B3124: ; 85B3124
	.incbin "base_emerald.gba", 0x5b3124, 0x8

gUnknown_085B312C: ; 85B312C
	.incbin "base_emerald.gba", 0x5b312c, 0x16

gUnknown_085B3142: ; 85B3142
	.incbin "base_emerald.gba", 0x5b3142, 0xc

gUnknown_085B314E: ; 85B314E
	.incbin "base_emerald.gba", 0x5b314e, 0xe

gUnknown_085B315C: ; 85B315C
	.incbin "base_emerald.gba", 0x5b315c, 0x14

gUnknown_085B3170: ; 85B3170
	.incbin "base_emerald.gba", 0x5b3170, 0x2c

gUnknown_085B319C: ; 85B319C
	.incbin "base_emerald.gba", 0x5b319c, 0x18

gUnknown_085B31B4: ; 85B31B4
	.incbin "base_emerald.gba", 0x5b31b4, 0x1c

gUnknown_085B31D0: ; 85B31D0
	.incbin "base_emerald.gba", 0x5b31d0, 0x28

gUnknown_085B31F8: ; 85B31F8
	.incbin "base_emerald.gba", 0x5b31f8, 0x14

gUnknown_085B320C: ; 85B320C
	.incbin "base_emerald.gba", 0x5b320c, 0x14

gUnknown_085B3220: ; 85B3220
	.incbin "base_emerald.gba", 0x5b3220, 0x8

gUnknown_085B3228: ; 85B3228
	.incbin "base_emerald.gba", 0x5b3228, 0x2c

gUnknown_085B3254: ; 85B3254
	.incbin "base_emerald.gba", 0x5b3254, 0x2c

gUnknown_085B3280: ; 85B3280
	.incbin "base_emerald.gba", 0x5b3280, 0x160

gUnknown_085B33E0: ; 85B33E0
	.incbin "base_emerald.gba", 0x5b33e0, 0x16

gUnknown_085B33F6: ; 85B33F6
	.incbin "base_emerald.gba", 0x5b33f6, 0xa

gUnknown_085B3400: ; 85B3400
	.incbin "base_emerald.gba", 0x5b3400, 0x10

gUnknown_085B3410: ; 85B3410
	.incbin "base_emerald.gba", 0x5b3410, 0x10

gUnknown_085B3420: ; 85B3420
	.incbin "base_emerald.gba", 0x5b3420, 0x24

gUnknown_085B3444: ; 85B3444
	.incbin "base_emerald.gba", 0x5b3444, 0x2c

gUnknown_085B3470: ; 85B3470
	.incbin "base_emerald.gba", 0x5b3470, 0x4

gUnknown_085B3474: ; 85B3474
	.incbin "base_emerald.gba", 0x5b3474, 0x8

gUnknown_085B347C: ; 85B347C
	.incbin "base_emerald.gba", 0x5b347c, 0x8

gUnknown_085B3484: ; 85B3484
	.incbin "base_emerald.gba", 0x5b3484, 0xc0

gUnknown_085B3544: ; 85B3544
	.incbin "base_emerald.gba", 0x5b3544, 0x20

gUnknown_085B3564: ; 85B3564
	.incbin "base_emerald.gba", 0x5b3564, 0x800

gUnknown_085B3D64: ; 85B3D64
	.incbin "base_emerald.gba", 0x5b3d64, 0x8

gUnknown_085B3D6C: ; 85B3D6C
	.incbin "base_emerald.gba", 0x5b3d6c, 0x10

gUnknown_085B3D7C: ; 85B3D7C
	.incbin "base_emerald.gba", 0x5b3d7c, 0x8

gUnknown_085B3D84: ; 85B3D84
	.incbin "base_emerald.gba", 0x5b3d84, 0x8

gUnknown_085B3D8C: ; 85B3D8C
	.incbin "base_emerald.gba", 0x5b3d8c, 0x8

gUnknown_085B3D94: ; 85B3D94
	.incbin "base_emerald.gba", 0x5b3d94, 0x20

gUnknown_085B3DB4: ; 85B3DB4
	.incbin "base_emerald.gba", 0x5b3db4, 0x134

gUnknown_085B3EE8: ; 85B3EE8
	.incbin "base_emerald.gba", 0x5b3ee8, 0x2

gUnknown_085B3EEA: ; 85B3EEA
	.incbin "base_emerald.gba", 0x5b3eea, 0x6

gUnknown_085B3EF0: ; 85B3EF0
	.incbin "base_emerald.gba", 0x5b3ef0, 0xc

gUnknown_085B3EFC: ; 85B3EFC
	.incbin "base_emerald.gba", 0x5b3efc, 0x1c

gUnknown_085B3F18: ; 85B3F18
	.incbin "base_emerald.gba", 0x5b3f18, 0x100

gUnknown_085B4018: ; 85B4018
	.incbin "base_emerald.gba", 0x5b4018, 0x4

gUnknown_085B401C: ; 85B401C
	.incbin "base_emerald.gba", 0x5b401c, 0x8

gUnknown_085B4024: ; 85B4024
	.incbin "base_emerald.gba", 0x5b4024, 0x10

gUnknown_085B4034: ; 85B4034
	.incbin "base_emerald.gba", 0x5b4034, 0xb8

gUnknown_085B40EC: ; 85B40EC
	.incbin "base_emerald.gba", 0x5b40ec, 0x10

gUnknown_085B40FC: ; 85B40FC
	.incbin "base_emerald.gba", 0x5b40fc, 0x38

gUnknown_085B4134: ; 85B4134
	.incbin "base_emerald.gba", 0x5b4134, 0x6f8

gUnknown_085B482C: ; 85B482C
	.incbin "base_emerald.gba", 0x5b482c, 0x4e4

gUnknown_085B4D10: ; 85B4D10
	.incbin "base_emerald.gba", 0x5b4d10, 0x4d4

gUnknown_085B51E4: ; 85B51E4
	.incbin "base_emerald.gba", 0x5b51e4, 0x6a0

gUnknown_085B5884: ; 85B5884
	.incbin "base_emerald.gba", 0x5b5884, 0x40

gUnknown_085B58C4: ; 85B58C4
	.incbin "base_emerald.gba", 0x5b58c4, 0x5

gUnknown_085B58C9: ; 85B58C9
	.incbin "base_emerald.gba", 0x5b58c9, 0x10

gUnknown_085B58D9: ; 85B58D9
	.incbin "base_emerald.gba", 0x5b58d9, 0x323

gUnknown_085B5BFC: ; 85B5BFC
	.incbin "base_emerald.gba", 0x5b5bfc, 0x200

gUnknown_085B5DFC: ; 85B5DFC
	.incbin "base_emerald.gba", 0x5b5dfc, 0x1a4

gUnknown_085B5FA0: ; 85B5FA0
	.incbin "base_emerald.gba", 0x5b5fa0, 0x1a0

gUnknown_085B6140: ; 85B6140
	.incbin "base_emerald.gba", 0x5b6140, 0xc

gUnknown_085B614C: ; 85B614C
	.incbin "base_emerald.gba", 0x5b614c, 0x8

gUnknown_085B6154: ; 85B6154
	.incbin "base_emerald.gba", 0x5b6154, 0xc

gUnknown_085B6160: ; 85B6160
	.incbin "base_emerald.gba", 0x5b6160, 0x184

gUnknown_085B62E4: ; 85B62E4
	.incbin "base_emerald.gba", 0x5b62e4, 0x4

gUnknown_085B62E8: ; 85B62E8
	.incbin "base_emerald.gba", 0x5b62e8, 0x5c

gUnknown_085B6344: ; 85B6344
	.incbin "base_emerald.gba", 0x5b6344, 0x4

gUnknown_085B6348: ; 85B6348
	.incbin "base_emerald.gba", 0x5b6348, 0x40

gUnknown_085B6388: ; 85B6388
	.incbin "base_emerald.gba", 0x5b6388, 0x68

gUnknown_085B63F0: ; 85B63F0
	.incbin "base_emerald.gba", 0x5b63f0, 0x18

gUnknown_085B6408: ; 85B6408
	.incbin "base_emerald.gba", 0x5b6408, 0x8

gUnknown_085B6410: ; 85B6410
	.incbin "base_emerald.gba", 0x5b6410, 0x8

gUnknown_085B6418: ; 85B6418
	.incbin "base_emerald.gba", 0x5b6418, 0x6

gUnknown_085B641E: ; 85B641E
	.incbin "base_emerald.gba", 0x5b641e, 0x4

gUnknown_085B6422: ; 85B6422
	.incbin "base_emerald.gba", 0x5b6422, 0xa

gUnknown_085B642C: ; 85B642C
	.incbin "base_emerald.gba", 0x5b642c, 0x10

gUnknown_085B643C: ; 85B643C
	.incbin "base_emerald.gba", 0x5b643c, 0xc

gUnknown_085B6448: ; 85B6448
	.incbin "base_emerald.gba", 0x5b6448, 0xf3c

gUnknown_085B7384: ; 85B7384
	.incbin "base_emerald.gba", 0x5b7384, 0x98

gUnknown_085B741C: ; 85B741C
	.incbin "base_emerald.gba", 0x5b741c, 0x6c

gUnknown_085B7488: ; 85B7488
	.incbin "base_emerald.gba", 0x5b7488, 0x8

gUnknown_085B7490: ; 85B7490
	.incbin "base_emerald.gba", 0x5b7490, 0x78

gUnknown_085B7508: ; 85B7508
	.incbin "base_emerald.gba", 0x5b7508, 0x60

gUnknown_085B7568: ; 85B7568
	.incbin "base_emerald.gba", 0x5b7568, 0x48

gUnknown_085B75B0: ; 85B75B0
	.incbin "base_emerald.gba", 0x5b75b0, 0x60

gUnknown_085B7610: ; 85B7610
	.incbin "base_emerald.gba", 0x5b7610, 0x140

gUnknown_085B7750: ; 85B7750
	.incbin "base_emerald.gba", 0x5b7750, 0x94

gUnknown_085B77E4: ; 85B77E4
	.incbin "base_emerald.gba", 0x5b77e4, 0x18

gUnknown_085B77FC: ; 85B77FC
	.incbin "base_emerald.gba", 0x5b77fc, 0x18

gUnknown_085B7814: ; 85B7814
	.incbin "base_emerald.gba", 0x5b7814, 0x18

gUnknown_085B782C: ; 85B782C
	.incbin "base_emerald.gba", 0x5b782c, 0x18

gUnknown_085B7844: ; 85B7844
	.incbin "base_emerald.gba", 0x5b7844, 0x20

gUnknown_085B7864: ; 85B7864
	.incbin "base_emerald.gba", 0x5b7864, 0xc4

gUnknown_085B7928: ; 85B7928
	.incbin "base_emerald.gba", 0x5b7928, 0x20

gUnknown_085B7948: ; 85B7948
	.incbin "base_emerald.gba", 0x5b7948, 0x8

gUnknown_085B7950: ; 85B7950
	.incbin "base_emerald.gba", 0x5b7950, 0x28

gUnknown_085B7978: ; 85B7978
	.incbin "base_emerald.gba", 0x5b7978, 0x80

gUnknown_085B79F8: ; 85B79F8
	.incbin "base_emerald.gba", 0x5b79f8, 0x18

gUnknown_085B7A10: ; 85B7A10
	.incbin "base_emerald.gba", 0x5b7a10, 0x30

gUnknown_085B7A40: ; 85B7A40
	.incbin "base_emerald.gba", 0x5b7a40, 0x7c

gUnknown_085B7ABC: ; 85B7ABC
	.incbin "base_emerald.gba", 0x5b7abc, 0x30

gUnknown_085B7AEC: ; 85B7AEC
	.incbin "base_emerald.gba", 0x5b7aec, 0x18

gUnknown_085B7B04: ; 85B7B04
	.incbin "base_emerald.gba", 0x5b7b04, 0x6

gUnknown_085B7B0A: ; 85B7B0A
	.incbin "base_emerald.gba", 0x5b7b0a, 0x8

gUnknown_085B7B12: ; 85B7B12
	.incbin "base_emerald.gba", 0x5b7b12, 0x8

gUnknown_085B7B1A: ; 85B7B1A
	.incbin "base_emerald.gba", 0x5b7b1a, 0x14

gUnknown_085B7B2E: ; 85B7B2E
	.incbin "base_emerald.gba", 0x5b7b2e, 0x18

gUnknown_085B7B46: ; 85B7B46
	.incbin "base_emerald.gba", 0x5b7b46, 0x2

gUnknown_085B7B48: ; 85B7B48
	.incbin "base_emerald.gba", 0x5b7b48, 0x8d0

gUnknown_085B8418: ; 85B8418
	.incbin "base_emerald.gba", 0x5b8418, 0x20

gUnknown_085B8438: ; 85B8438
	.incbin "base_emerald.gba", 0x5b8438, 0x338

gUnknown_085B8770: ; 85B8770
	.incbin "base_emerald.gba", 0x5b8770, 0x480

gUnknown_085B8BF0: ; 85B8BF0
	.incbin "base_emerald.gba", 0x5b8bf0, 0x20

gUnknown_085B8C10: ; 85B8C10
	.incbin "base_emerald.gba", 0x5b8c10, 0x20

gUnknown_085B8C30: ; 85B8C30
	.incbin "base_emerald.gba", 0x5b8c30, 0x2

gUnknown_085B8C32: ; 85B8C32
	.incbin "base_emerald.gba", 0x5b8c32, 0x36

gUnknown_085B8C68: ; 85B8C68
	.incbin "base_emerald.gba", 0x5b8c68, 0x18

gUnknown_085B8C80: ; 85B8C80
	.incbin "base_emerald.gba", 0x5b8c80, 0x10

gUnknown_085B8C90: ; 85B8C90
	.incbin "base_emerald.gba", 0x5b8c90, 0x528

gUnknown_085B91B8: ; 85B91B8
	.incbin "base_emerald.gba", 0x5b91b8, 0x178

gUnknown_085B9330: ; 85B9330
	.incbin "base_emerald.gba", 0x5b9330, 0x580

gUnknown_085B98B0: ; 85B98B0
	.incbin "base_emerald.gba", 0x5b98b0, 0x240

gUnknown_085B9AF0: ; 85B9AF0
	.incbin "base_emerald.gba", 0x5b9af0, 0x11e0

gUnknown_085BACD0: ; 85BACD0
	.incbin "base_emerald.gba", 0x5bacd0, 0x1e0

gUnknown_085BAEB0: ; 85BAEB0
	.incbin "base_emerald.gba", 0x5baeb0, 0x20

gUnknown_085BAED0: ; 85BAED0
	.incbin "base_emerald.gba", 0x5baed0, 0x378

gUnknown_085BB248: ; 85BB248
	.incbin "base_emerald.gba", 0x5bb248, 0x25c

gUnknown_085BB4A4: ; 85BB4A4
	.incbin "base_emerald.gba", 0x5bb4a4, 0x48c

gUnknown_085BB930: ; 85BB930
	.incbin "base_emerald.gba", 0x5bb930, 0x2e4

gUnknown_085BBC14: ; 85BBC14
	.incbin "base_emerald.gba", 0x5bbc14, 0x6a0

gUnknown_085BC2B4: ; 85BC2B4
	.incbin "base_emerald.gba", 0x5bc2b4, 0x20

gUnknown_085BC2D4: ; 85BC2D4
	.incbin "base_emerald.gba", 0x5bc2d4, 0x20

gUnknown_085BC2F4: ; 85BC2F4
	.incbin "base_emerald.gba", 0x5bc2f4, 0x20

gUnknown_085BC314: ; 85BC314
	.incbin "base_emerald.gba", 0x5bc314, 0x800

gUnknown_085BCB14: ; 85BCB14
	.incbin "base_emerald.gba", 0x5bcb14, 0x800

gUnknown_085BD314: ; 85BD314
	.incbin "base_emerald.gba", 0x5bd314, 0x820

gUnknown_085BDB34: ; 85BDB34
	.incbin "base_emerald.gba", 0x5bdb34, 0x6b4

gUnknown_085BE1E8: ; 85BE1E8
	.incbin "base_emerald.gba", 0x5be1e8, 0x334

gUnknown_085BE51C: ; 85BE51C
	.incbin "base_emerald.gba", 0x5be51c, 0x56c

gUnknown_085BEA88: ; 85BEA88
	.incbin "base_emerald.gba", 0x5bea88, 0x318

gUnknown_085BEDA0: ; 85BEDA0
	.incbin "base_emerald.gba", 0x5beda0, 0x140

gUnknown_085BEEE0: ; 85BEEE0
	.incbin "base_emerald.gba", 0x5beee0, 0x1c0

gUnknown_085BF0A0: ; 85BF0A0
	.incbin "base_emerald.gba", 0x5bf0a0, 0x200

gUnknown_085BF2A0: ; 85BF2A0
	.incbin "base_emerald.gba", 0x5bf2a0, 0x200

gUnknown_085BF4A0: ; 85BF4A0
	.incbin "base_emerald.gba", 0x5bf4a0, 0xa0

gUnknown_085BF540: ; 85BF540
	.incbin "base_emerald.gba", 0x5bf540, 0x160

gUnknown_085BF6A0: ; 85BF6A0
	.incbin "base_emerald.gba", 0x5bf6a0, 0x7540

gUnknown_085C6BE0: ; 85C6BE0
	.incbin "base_emerald.gba", 0x5c6be0, 0x1000

gUnknown_085C7BE0: ; 85C7BE0
	.incbin "base_emerald.gba", 0x5c7be0, 0x20

gUnknown_085C7C00: ; 85C7C00
	.incbin "base_emerald.gba", 0x5c7c00, 0x68c

gUnknown_085C828C: ; 85C828C
	.incbin "base_emerald.gba", 0x5c828c, 0x2ec

gUnknown_085C8578: ; 85C8578
	.incbin "base_emerald.gba", 0x5c8578, 0x20

gUnknown_085C8598: ; 85C8598
	.incbin "base_emerald.gba", 0x5c8598, 0x15c

gUnknown_085C86F4: ; 85C86F4
	.incbin "base_emerald.gba", 0x5c86f4, 0x100

gUnknown_085C87F4: ; 85C87F4
	.incbin "base_emerald.gba", 0x5c87f4, 0xb0

gUnknown_085C88A4: ; 85C88A4
	.incbin "base_emerald.gba", 0x5c88a4, 0x84

gUnknown_085C8928: ; 85C8928
	.incbin "base_emerald.gba", 0x5c8928, 0x20

gUnknown_085C8948: ; 85C8948
	.incbin "base_emerald.gba", 0x5c8948, 0xa8

gUnknown_085C89F0: ; 85C89F0
	.incbin "base_emerald.gba", 0x5c89f0, 0xa8

gUnknown_085C8A98: ; 85C8A98
	.incbin "base_emerald.gba", 0x5c8a98, 0x10

gUnknown_085C8AA8: ; 85C8AA8
	.incbin "base_emerald.gba", 0x5c8aa8, 0xc

gUnknown_085C8AB4: ; 85C8AB4
	.incbin "base_emerald.gba", 0x5c8ab4, 0x8

gUnknown_085C8ABC: ; 85C8ABC
	.incbin "base_emerald.gba", 0x5c8abc, 0x8

gUnknown_085C8AC4: ; 85C8AC4
	.incbin "base_emerald.gba", 0x5c8ac4, 0x1c

gUnknown_085C8AE0: ; 85C8AE0
	.incbin "base_emerald.gba", 0x5c8ae0, 0x1c

gUnknown_085C8AFC: ; 85C8AFC
	.incbin "base_emerald.gba", 0x5c8afc, 0x18

gUnknown_085C8B14: ; 85C8B14
	.incbin "base_emerald.gba", 0x5c8b14, 0x18

gUnknown_085C8B2C: ; 85C8B2C
	.incbin "base_emerald.gba", 0x5c8b2c, 0x18

gUnknown_085C8B44: ; 85C8B44
	.incbin "base_emerald.gba", 0x5c8b44, 0x18

gUnknown_085C8B5C: ; 85C8B5C
	.incbin "base_emerald.gba", 0x5c8b5c, 0x20

gUnknown_085C8B7C: ; 85C8B7C
	.incbin "base_emerald.gba", 0x5c8b7c, 0xc

gUnknown_085C8B88: ; 85C8B88
	.incbin "base_emerald.gba", 0x5c8b88, 0x4

gUnknown_085C8B8C: ; 85C8B8C
	.incbin "base_emerald.gba", 0x5c8b8c, 0xa

gUnknown_085C8B96: ; 85C8B96
	.incbin "base_emerald.gba", 0x5c8b96, 0x6

gUnknown_085C8B9C: ; 85C8B9C
	.incbin "base_emerald.gba", 0x5c8b9c, 0x1c

gUnknown_085C8BB8: ; 85C8BB8
	.incbin "base_emerald.gba", 0x5c8bb8, 0x8

gUnknown_085C8BC0: ; 85C8BC0
	.incbin "base_emerald.gba", 0x5c8bc0, 0xc

gUnknown_085C8BCC: ; 85C8BCC
	.incbin "base_emerald.gba", 0x5c8bcc, 0x28

gUnknown_085C8BF4: ; 85C8BF4
	.incbin "base_emerald.gba", 0x5c8bf4, 0x6

gUnknown_085C8BFA: ; 85C8BFA
	.incbin "base_emerald.gba", 0x5c8bfa, 0x14

gUnknown_085C8C0E: ; 85C8C0E
	.incbin "base_emerald.gba", 0x5c8c0e, 0x16

gUnknown_085C8C24: ; 85C8C24
	.incbin "base_emerald.gba", 0x5c8c24, 0x1c

gUnknown_085C8C40: ; 85C8C40
	.incbin "base_emerald.gba", 0x5c8c40, 0x4

gUnknown_085C8C44: ; 85C8C44
	.incbin "base_emerald.gba", 0x5c8c44, 0x4

gUnknown_085C8C48: ; 85C8C48
	.incbin "base_emerald.gba", 0x5c8c48, 0xc

gUnknown_085C8C54: ; 85C8C54
	.incbin "base_emerald.gba", 0x5c8c54, 0x10

gUnknown_085C8C64: ; 85C8C64
	.incbin "base_emerald.gba", 0x5c8c64, 0x2

gUnknown_085C8C66: ; 85C8C66
	.incbin "base_emerald.gba", 0x5c8c66, 0x6

gUnknown_085C8C6C: ; 85C8C6C
	.incbin "base_emerald.gba", 0x5c8c6c, 0xc

gUnknown_085C8C78: ; 85C8C78
	.incbin "base_emerald.gba", 0x5c8c78, 0x8

gUnknown_085C8C80: ; 85C8C80
	.incbin "base_emerald.gba", 0x5c8c80, 0x4

gUnknown_085C8C84: ; 85C8C84
	.incbin "base_emerald.gba", 0x5c8c84, 0xb4

gUnknown_085C8D38: ; 85C8D38
	.incbin "base_emerald.gba", 0x5c8d38, 0x8

gUnknown_085C8D40: ; 85C8D40
	.incbin "base_emerald.gba", 0x5c8d40, 0x20

gUnknown_085C8D60: ; 85C8D60
	.incbin "base_emerald.gba", 0x5c8d60, 0x2c

gUnknown_085C8D8C: ; 85C8D8C
	.incbin "base_emerald.gba", 0x5c8d8c, 0x14

gUnknown_085C8DA0: ; 85C8DA0
	.incbin "base_emerald.gba", 0x5c8da0, 0x10

gUnknown_085C8DB0: ; 85C8DB0
	.incbin "base_emerald.gba", 0x5c8db0, 0xc

gUnknown_085C8DBC: ; 85C8DBC
	.incbin "base_emerald.gba", 0x5c8dbc, 0x14

gUnknown_085C8DD0: ; 85C8DD0
	.incbin "base_emerald.gba", 0x5c8dd0, 0x46

gUnknown_085C8E16: ; 85C8E16
	.incbin "base_emerald.gba", 0x5c8e16, 0xe

gUnknown_085C8E24: ; 85C8E24
	.incbin "base_emerald.gba", 0x5c8e24, 0x44

gUnknown_085C8E68: ; 85C8E68
	.incbin "base_emerald.gba", 0x5c8e68, 0x6c

gUnknown_085C8ED4: ; 85C8ED4
	.incbin "base_emerald.gba", 0x5c8ed4, 0x108

gUnknown_085C8FDC: ; 85C8FDC
	.incbin "base_emerald.gba", 0x5c8fdc, 0x14

gUnknown_085C8FF0: ; 85C8FF0
	.incbin "base_emerald.gba", 0x5c8ff0, 0x30

gUnknown_085C9020: ; 85C9020
	.incbin "base_emerald.gba", 0x5c9020, 0x4b0

gUnknown_085C94D0: ; 85C94D0
	.incbin "base_emerald.gba", 0x5c94d0, 0x500

gUnknown_085C99D0: ; 85C99D0
	.incbin "base_emerald.gba", 0x5c99d0, 0x18

gUnknown_085C99E8: ; 85C99E8
	.incbin "base_emerald.gba", 0x5c99e8, 0x10

gUnknown_085C99F8: ; 85C99F8
	.incbin "base_emerald.gba", 0x5c99f8, 0x10

gUnknown_085C9A08: ; 85C9A08
	.incbin "base_emerald.gba", 0x5c9a08, 0x14

gUnknown_085C9A1C: ; 85C9A1C
	.incbin "base_emerald.gba", 0x5c9a1c, 0x14

gUnknown_085C9A30: ; 85C9A30
	.incbin "base_emerald.gba", 0x5c9a30, 0x23

gUnknown_085C9A53: ; 85C9A53
	.incbin "base_emerald.gba", 0x5c9a53, 0x41

gUnknown_085C9A94: ; 85C9A94
	.incbin "base_emerald.gba", 0x5c9a94, 0x990

gUnknown_085CA424: ; 85CA424
	.incbin "base_emerald.gba", 0x5ca424, 0x35

gUnknown_085CA459: ; 85CA459
	.incbin "base_emerald.gba", 0x5ca459, 0xe48

gUnknown_085CB2A1: ; 85CB2A1
	.incbin "base_emerald.gba", 0x5cb2a1, 0xe9

gUnknown_085CB38A: ; 85CB38A
	.incbin "base_emerald.gba", 0x5cb38a, 0x20

gUnknown_085CB3AA: ; 85CB3AA
	.incbin "base_emerald.gba", 0x5cb3aa, 0x120

gUnknown_085CB4CA: ; 85CB4CA
	.incbin "base_emerald.gba", 0x5cb4ca, 0x5a

gUnknown_085CB524: ; 85CB524
	.incbin "base_emerald.gba", 0x5cb524, 0x14

gUnknown_085CB538: ; 85CB538
	.incbin "base_emerald.gba", 0x5cb538, 0x17

gUnknown_085CB54F: ; 85CB54F
	.incbin "base_emerald.gba", 0x5cb54f, 0x18

gUnknown_085CB567: ; 85CB567
	.incbin "base_emerald.gba", 0x5cb567, 0x1a

gUnknown_085CB581: ; 85CB581
	.incbin "base_emerald.gba", 0x5cb581, 0x25

gUnknown_085CB5A6: ; 85CB5A6
	.incbin "base_emerald.gba", 0x5cb5a6, 0x2c

gUnknown_085CB5D2: ; 85CB5D2
	.incbin "base_emerald.gba", 0x5cb5d2, 0xd

gUnknown_085CB5DF: ; 85CB5DF
	.incbin "base_emerald.gba", 0x5cb5df, 0x44f

gUnknown_085CBA2E: ; 85CBA2E
	.incbin "base_emerald.gba", 0x5cba2e, 0x119

gUnknown_085CBB47: ; 85CBB47
	.incbin "base_emerald.gba", 0x5cbb47, 0x13

gUnknown_085CBB5A: ; 85CBB5A
	.incbin "base_emerald.gba", 0x5cbb5a, 0x13

gUnknown_085CBB6D: ; 85CBB6D
	.incbin "base_emerald.gba", 0x5cbb6d, 0x15

gUnknown_085CBB82: ; 85CBB82
	.incbin "base_emerald.gba", 0x5cbb82, 0x1a

gUnknown_085CBB9C: ; 85CBB9C
	.incbin "base_emerald.gba", 0x5cbb9c, 0x1d

gUnknown_085CBBB9: ; 85CBBB9
	.incbin "base_emerald.gba", 0x5cbbb9, 0x14

gUnknown_085CBBCD: ; 85CBBCD
	.incbin "base_emerald.gba", 0x5cbbcd, 0x1a

gUnknown_085CBBE7: ; 85CBBE7
	.incbin "base_emerald.gba", 0x5cbbe7, 0x13

gUnknown_085CBBFA: ; 85CBBFA
	.incbin "base_emerald.gba", 0x5cbbfa, 0x1a

gUnknown_085CBC14: ; 85CBC14
	.incbin "base_emerald.gba", 0x5cbc14, 0x13

gUnknown_085CBC27: ; 85CBC27
	.incbin "base_emerald.gba", 0x5cbc27, 0x10

gUnknown_085CBC37: ; 85CBC37
	.incbin "base_emerald.gba", 0x5cbc37, 0x17

gUnknown_085CBC4E: ; 85CBC4E
	.incbin "base_emerald.gba", 0x5cbc4e, 0x20

gUnknown_085CBC6E: ; 85CBC6E
	.incbin "base_emerald.gba", 0x5cbc6e, 0x10

gUnknown_085CBC7E: ; 85CBC7E
	.incbin "base_emerald.gba", 0x5cbc7e, 0x10

gUnknown_085CBC8E: ; 85CBC8E
	.incbin "base_emerald.gba", 0x5cbc8e, 0x8

gUnknown_085CBC96: ; 85CBC96
	.incbin "base_emerald.gba", 0x5cbc96, 0xf

gUnknown_085CBCA5: ; 85CBCA5
	.incbin "base_emerald.gba", 0x5cbca5, 0x8

gUnknown_085CBCAD: ; 85CBCAD
	.incbin "base_emerald.gba", 0x5cbcad, 0xb

gUnknown_085CBCB8: ; 85CBCB8
	.incbin "base_emerald.gba", 0x5cbcb8, 0xf

gUnknown_085CBCC7: ; 85CBCC7
	.incbin "base_emerald.gba", 0x5cbcc7, 0x1e

gUnknown_085CBCE5: ; 85CBCE5
	.incbin "base_emerald.gba", 0x5cbce5, 0x18

gUnknown_085CBCFD: ; 85CBCFD
	.incbin "base_emerald.gba", 0x5cbcfd, 0x1e

gUnknown_085CBD1B: ; 85CBD1B
	.incbin "base_emerald.gba", 0x5cbd1b, 0xf

gUnknown_085CBD2A: ; 85CBD2A
	.incbin "base_emerald.gba", 0x5cbd2a, 0x13

gUnknown_085CBD3D: ; 85CBD3D
	.incbin "base_emerald.gba", 0x5cbd3d, 0x15

gUnknown_085CBD52: ; 85CBD52
	.incbin "base_emerald.gba", 0x5cbd52, 0x13

gUnknown_085CBD65: ; 85CBD65
	.incbin "base_emerald.gba", 0x5cbd65, 0x10

gUnknown_085CBD75: ; 85CBD75
	.incbin "base_emerald.gba", 0x5cbd75, 0x10

gUnknown_085CBD85: ; 85CBD85
	.incbin "base_emerald.gba", 0x5cbd85, 0x6

gUnknown_085CBD8B: ; 85CBD8B
	.incbin "base_emerald.gba", 0x5cbd8b, 0x6

gUnknown_085CBD91: ; 85CBD91
	.incbin "base_emerald.gba", 0x5cbd91, 0x4

gUnknown_085CBD95: ; 85CBD95
	.incbin "base_emerald.gba", 0x5cbd95, 0x5

gUnknown_085CBD9A: ; 85CBD9A
	.incbin "base_emerald.gba", 0x5cbd9a, 0x4

gUnknown_085CBD9E: ; 85CBD9E
	.incbin "base_emerald.gba", 0x5cbd9e, 0x5

gUnknown_085CBDA3: ; 85CBDA3
	.incbin "base_emerald.gba", 0x5cbda3, 0x4

gUnknown_085CBDA7: ; 85CBDA7
	.incbin "base_emerald.gba", 0x5cbda7, 0x5

gUnknown_085CBDAC: ; 85CBDAC
	.incbin "base_emerald.gba", 0x5cbdac, 0xb

gUnknown_085CBDB7: ; 85CBDB7
	.incbin "base_emerald.gba", 0x5cbdb7, 0x2

gUnknown_085CBDB9: ; 85CBDB9
	.incbin "base_emerald.gba", 0x5cbdb9, 0x2

gUnknown_085CBDBB: ; 85CBDBB
	.incbin "base_emerald.gba", 0x5cbdbb, 0x2

gUnknown_085CBDBD: ; 85CBDBD
	.incbin "base_emerald.gba", 0x5cbdbd, 0x2

gUnknown_085CBDBF: ; 85CBDBF
	.incbin "base_emerald.gba", 0x5cbdbf, 0x41

gUnknown_085CBE00: ; 85CBE00
	.incbin "base_emerald.gba", 0x5cbe00, 0x6c

gUnknown_085CBE6C: ; 85CBE6C
	.incbin "base_emerald.gba", 0x5cbe6c, 0x1a9

gUnknown_085CC015: ; 85CC015
	.incbin "base_emerald.gba", 0x5cc015, 0xa

gUnknown_085CC01F: ; 85CC01F
	.incbin "base_emerald.gba", 0x5cc01f, 0x81

gUnknown_085CC0A0: ; 85CC0A0
	.incbin "base_emerald.gba", 0x5cc0a0, 0xd

gUnknown_085CC0AD: ; 85CC0AD
	.incbin "base_emerald.gba", 0x5cc0ad, 0x191

gUnknown_085CC23E: ; 85CC23E
	.incbin "base_emerald.gba", 0x5cc23e, 0x32

gUnknown_085CC270: ; 85CC270
	.incbin "base_emerald.gba", 0x5cc270, 0x5c4

gUnknown_085CC834: ; 85CC834
	.incbin "base_emerald.gba", 0x5cc834, 0x14e

gUnknown_085CC982: ; 85CC982
	.incbin "base_emerald.gba", 0x5cc982, 0xe

gUnknown_085CC990: ; 85CC990
	.incbin "base_emerald.gba", 0x5cc990, 0x16

gUnknown_085CC9A6: ; 85CC9A6
	.incbin "base_emerald.gba", 0x5cc9a6, 0x2d

gUnknown_085CC9D3: ; 85CC9D3
	.incbin "base_emerald.gba", 0x5cc9d3, 0x1b

gUnknown_085CC9EE: ; 85CC9EE
	.incbin "base_emerald.gba", 0x5cc9ee, 0x5

gUnknown_085CC9F3: ; 85CC9F3
	.incbin "base_emerald.gba", 0x5cc9f3, 0x11

gUnknown_085CCA04: ; 85CCA04
	.incbin "base_emerald.gba", 0x5cca04, 0x11

gUnknown_085CCA15: ; 85CCA15
	.incbin "base_emerald.gba", 0x5cca15, 0x14

gUnknown_085CCA29: ; 85CCA29
	.incbin "base_emerald.gba", 0x5cca29, 0x11

gUnknown_085CCA3A: ; 85CCA3A
	.incbin "base_emerald.gba", 0x5cca3a, 0x1a

gUnknown_085CCA54: ; 85CCA54
	.incbin "base_emerald.gba", 0x5cca54, 0x1b

gUnknown_085CCA6F: ; 85CCA6F
	.incbin "base_emerald.gba", 0x5cca6f, 0x4

gUnknown_085CCA73: ; 85CCA73
	.incbin "base_emerald.gba", 0x5cca73, 0x48

gUnknown_085CCABB: ; 85CCABB
	.incbin "base_emerald.gba", 0x5ccabb, 0xf

gUnknown_085CCACA: ; 85CCACA
	.incbin "base_emerald.gba", 0x5ccaca, 0x62

gUnknown_085CCB2C: ; 85CCB2C
	.incbin "base_emerald.gba", 0x5ccb2c, 0x10

gUnknown_085CCB3C: ; 85CCB3C
	.incbin "base_emerald.gba", 0x5ccb3c, 0x3d

gUnknown_085CCB79: ; 85CCB79
	.incbin "base_emerald.gba", 0x5ccb79, 0x6

gUnknown_085CCB7F: ; 85CCB7F
	.incbin "base_emerald.gba", 0x5ccb7f, 0x3

gUnknown_085CCB82: ; 85CCB82
	.incbin "base_emerald.gba", 0x5ccb82, 0x2

gUnknown_085CCB84: ; 85CCB84
	.incbin "base_emerald.gba", 0x5ccb84, 0x2

gUnknown_085CCB86: ; 85CCB86
	.incbin "base_emerald.gba", 0x5ccb86, 0x2

gUnknown_085CCB88: ; 85CCB88
	.incbin "base_emerald.gba", 0x5ccb88, 0x4

gUnknown_085CCB8C: ; 85CCB8C
	.incbin "base_emerald.gba", 0x5ccb8c, 0x4

gUnknown_085CCB90: ; 85CCB90
	.incbin "base_emerald.gba", 0x5ccb90, 0x8

gUnknown_085CCB98: ; 85CCB98
	.incbin "base_emerald.gba", 0x5ccb98, 0x6

gUnknown_085CCB9E: ; 85CCB9E
	.incbin "base_emerald.gba", 0x5ccb9e, 0x7

gUnknown_085CCBA5: ; 85CCBA5
	.incbin "base_emerald.gba", 0x5ccba5, 0x8

gUnknown_085CCBAD: ; 85CCBAD
	.incbin "base_emerald.gba", 0x5ccbad, 0x8

gUnknown_085CCBB5: ; 85CCBB5
	.incbin "base_emerald.gba", 0x5ccbb5, 0x4

gUnknown_085CCBB9: ; 85CCBB9
	.incbin "base_emerald.gba", 0x5ccbb9, 0x3

gUnknown_085CCBBC: ; 85CCBBC
	.incbin "base_emerald.gba", 0x5ccbbc, 0x132

gUnknown_085CCCEE: ; 85CCCEE
	.incbin "base_emerald.gba", 0x5cccee, 0x32

gUnknown_085CCD20: ; 85CCD20
	.incbin "base_emerald.gba", 0x5ccd20, 0x92

gUnknown_085CCDB2: ; 85CCDB2
	.incbin "base_emerald.gba", 0x5ccdb2, 0x3

gUnknown_085CCDB5: ; 85CCDB5
	.incbin "base_emerald.gba", 0x5ccdb5, 0x3

gUnknown_085CCDB8: ; 85CCDB8
	.incbin "base_emerald.gba", 0x5ccdb8, 0x3

gUnknown_085CCDBB: ; 85CCDBB
	.incbin "base_emerald.gba", 0x5ccdbb, 0x5

gUnknown_085CCDC0: ; 85CCDC0
	.incbin "base_emerald.gba", 0x5ccdc0, 0x6

gUnknown_085CCDC6: ; 85CCDC6
	.incbin "base_emerald.gba", 0x5ccdc6, 0x5

gUnknown_085CCDCB: ; 85CCDCB
	.incbin "base_emerald.gba", 0x5ccdcb, 0x13

gUnknown_085CCDDE: ; 85CCDDE
	.incbin "base_emerald.gba", 0x5ccdde, 0x26

gUnknown_085CCE04: ; 85CCE04
	.incbin "base_emerald.gba", 0x5cce04, 0x13

gUnknown_085CCE17: ; 85CCE17
	.incbin "base_emerald.gba", 0x5cce17, 0x21

gUnknown_085CCE38: ; 85CCE38
	.incbin "base_emerald.gba", 0x5cce38, 0x1b

gUnknown_085CCE53: ; 85CCE53
	.incbin "base_emerald.gba", 0x5cce53, 0x375

gUnknown_085CD1C8: ; 85CD1C8
	.incbin "base_emerald.gba", 0x5cd1c8, 0x84

gUnknown_085CD24C: ; 85CD24C
	.incbin "base_emerald.gba", 0x5cd24c, 0x1b

gUnknown_085CD267: ; 85CD267
	.incbin "base_emerald.gba", 0x5cd267, 0x28

gUnknown_085CD28F: ; 85CD28F
	.incbin "base_emerald.gba", 0x5cd28f, 0x3c

gUnknown_085CD2CB: ; 85CD2CB
	.incbin "base_emerald.gba", 0x5cd2cb, 0x36

gUnknown_085CD301: ; 85CD301
	.incbin "base_emerald.gba", 0x5cd301, 0x17

gUnknown_085CD318: ; 85CD318
	.incbin "base_emerald.gba", 0x5cd318, 0x1e

gUnknown_085CD336: ; 85CD336
	.incbin "base_emerald.gba", 0x5cd336, 0xec

gUnknown_085CD422: ; 85CD422
	.incbin "base_emerald.gba", 0x5cd422, 0x23e

gUnknown_085CD660: ; 85CD660
	.incbin "base_emerald.gba", 0x5cd660, 0x8

gUnknown_085CD668: ; 85CD668
	.incbin "base_emerald.gba", 0x5cd668, 0x4

gUnknown_085CD66C: ; 85CD66C
	.incbin "base_emerald.gba", 0x5cd66c, 0x10

gUnknown_085CD67C: ; 85CD67C
	.incbin "base_emerald.gba", 0x5cd67c, 0x158

gUnknown_085CD7D4: ; 85CD7D4
	.incbin "base_emerald.gba", 0x5cd7d4, 0x184

gUnknown_085CD958: ; 85CD958
	.incbin "base_emerald.gba", 0x5cd958, 0x1c4

gUnknown_085CDB1C: ; 85CDB1C
	.incbin "base_emerald.gba", 0x5cdb1c, 0x14

gUnknown_085CDB30: ; 85CDB30
	.incbin "base_emerald.gba", 0x5cdb30, 0x24

gUnknown_085CDB54: ; 85CDB54
	.incbin "base_emerald.gba", 0x5cdb54, 0x20

gUnknown_085CDB74: ; 85CDB74
	.incbin "base_emerald.gba", 0x5cdb74, 0x28

gUnknown_085CDB9C: ; 85CDB9C
	.incbin "base_emerald.gba", 0x5cdb9c, 0x30

gUnknown_085CDBCC: ; 85CDBCC
	.incbin "base_emerald.gba", 0x5cdbcc, 0x18

gUnknown_085CDBE4: ; 85CDBE4
	.incbin "base_emerald.gba", 0x5cdbe4, 0x2

gUnknown_085CDBE6: ; 85CDBE6
	.incbin "base_emerald.gba", 0x5cdbe6, 0x4

gUnknown_085CDBEA: ; 85CDBEA
	.incbin "base_emerald.gba", 0x5cdbea, 0x8

gUnknown_085CDBF2: ; 85CDBF2
	.incbin "base_emerald.gba", 0x5cdbf2, 0x6

gUnknown_085CDBF8: ; 85CDBF8
	.incbin "base_emerald.gba", 0x5cdbf8, 0x8

gUnknown_085CDC00: ; 85CDC00
	.incbin "base_emerald.gba", 0x5cdc00, 0x38

gUnknown_085CDC38: ; 85CDC38
	.incbin "base_emerald.gba", 0x5cdc38, 0x6

gUnknown_085CDC3E: ; 85CDC3E
	.incbin "base_emerald.gba", 0x5cdc3e, 0x4

gUnknown_085CDC42: ; 85CDC42
	.incbin "base_emerald.gba", 0x5cdc42, 0xa

gUnknown_085CDC4C: ; 85CDC4C
	.incbin "base_emerald.gba", 0x5cdc4c, 0x8

gUnknown_085CDC54: ; 85CDC54
	.incbin "base_emerald.gba", 0x5cdc54, 0xc

gUnknown_085CDC60: ; 85CDC60
	.incbin "base_emerald.gba", 0x5cdc60, 0xa

gUnknown_085CDC6A: ; 85CDC6A
	.incbin "base_emerald.gba", 0x5cdc6a, 0x96

gUnknown_085CDD00: ; 85CDD00
	.incbin "base_emerald.gba", 0x5cdd00, 0x220

gUnknown_085CDF20: ; 85CDF20
	.incbin "base_emerald.gba", 0x5cdf20, 0x380

gUnknown_085CE2A0: ; 85CE2A0
	.incbin "base_emerald.gba", 0x5ce2a0, 0xb0

gUnknown_085CE350: ; 85CE350
	.incbin "base_emerald.gba", 0x5ce350, 0x38

gUnknown_085CE388: ; 85CE388
	.incbin "base_emerald.gba", 0x5ce388, 0x18

gUnknown_085CE3A0: ; 85CE3A0
	.incbin "base_emerald.gba", 0x5ce3a0, 0x18

gUnknown_085CE3B8: ; 85CE3B8
	.incbin "base_emerald.gba", 0x5ce3b8, 0x28

gUnknown_085CE3E0: ; 85CE3E0
	.incbin "base_emerald.gba", 0x5ce3e0, 0x50

gUnknown_085CE430: ; 85CE430
	.incbin "base_emerald.gba", 0x5ce430, 0x30

gUnknown_085CE460: ; 85CE460
	.incbin "base_emerald.gba", 0x5ce460, 0x2c

gUnknown_085CE48C: ; 85CE48C
	.incbin "base_emerald.gba", 0x5ce48c, 0x18

gUnknown_085CE4A4: ; 85CE4A4
	.incbin "base_emerald.gba", 0x5ce4a4, 0x4

gUnknown_085CE4A8: ; 85CE4A8
	.incbin "base_emerald.gba", 0x5ce4a8, 0x8

gUnknown_085CE4B0: ; 85CE4B0
	.incbin "base_emerald.gba", 0x5ce4b0, 0x140

gUnknown_085CE5F0: ; 85CE5F0
	.incbin "base_emerald.gba", 0x5ce5f0, 0x15c

gUnknown_085CE74C: ; 85CE74C
	.incbin "base_emerald.gba", 0x5ce74c, 0x20

gUnknown_085CE76C: ; 85CE76C
	.incbin "base_emerald.gba", 0x5ce76c, 0x18

gUnknown_085CE784: ; 85CE784
	.incbin "base_emerald.gba", 0x5ce784, 0x68

gUnknown_085CE7EC: ; 85CE7EC
	.incbin "base_emerald.gba", 0x5ce7ec, 0x60

gUnknown_085CE84C: ; 85CE84C
	.incbin "base_emerald.gba", 0x5ce84c, 0x30

gUnknown_085CE87C: ; 85CE87C
	.incbin "base_emerald.gba", 0x5ce87c, 0x14c

gUnknown_085CE9C8: ; 85CE9C8
	.incbin "base_emerald.gba", 0x5ce9c8, 0x1e8

gUnknown_085CEBB0: ; 85CEBB0
	.incbin "base_emerald.gba", 0x5cebb0, 0x8

gUnknown_085CEBB8: ; 85CEBB8
	.incbin "base_emerald.gba", 0x5cebb8, 0x8

gUnknown_085CEBC0: ; 85CEBC0
	.incbin "base_emerald.gba", 0x5cebc0, 0x10

gUnknown_085CEBD0: ; 85CEBD0
	.incbin "base_emerald.gba", 0x5cebd0, 0x40

gUnknown_085CEC10: ; 85CEC10
	.incbin "base_emerald.gba", 0x5cec10, 0x18

gUnknown_085CEC28: ; 85CEC28
	.incbin "base_emerald.gba", 0x5cec28, 0x8

gUnknown_085CEC30: ; 85CEC30
	.incbin "base_emerald.gba", 0x5cec30, 0x80

gUnknown_085CECB0: ; 85CECB0
	.incbin "base_emerald.gba", 0x5cecb0, 0x6e1c

gUnknown_085D5ACC: ; 85D5ACC
	.incbin "base_emerald.gba", 0x5d5acc, 0x3cf0

gUnknown_085D97BC: ; 85D97BC
	.incbin "base_emerald.gba", 0x5d97bc, 0x3720

gUnknown_085DCEDC: ; 85DCEDC
	.incbin "base_emerald.gba", 0x5dcedc, 0x1e

gUnknown_085DCEFA: ; 85DCEFA
	.incbin "base_emerald.gba", 0x5dcefa, 0x14

gUnknown_085DCF0E: ; 85DCF0E
	.incbin "base_emerald.gba", 0x5dcf0e, 0x1e

gUnknown_085DCF2C: ; 85DCF2C
	.incbin "base_emerald.gba", 0x5dcf2c, 0x14

gUnknown_085DCF40: ; 85DCF40
	.incbin "base_emerald.gba", 0x5dcf40, 0x5c0

gUnknown_085DD500: ; 85DD500
	.incbin "base_emerald.gba", 0x5dd500, 0x190

gUnknown_085DD690: ; 85DD690
	.incbin "base_emerald.gba", 0x5dd690, 0x40

gUnknown_085DD6D0: ; 85DD6D0
	.incbin "base_emerald.gba", 0x5dd6d0, 0x5

gUnknown_085DD6D5: ; 85DD6D5
	.incbin "base_emerald.gba", 0x5dd6d5, 0x7

gUnknown_085DD6DC: ; 85DD6DC
	.incbin "base_emerald.gba", 0x5dd6dc, 0x338

gUnknown_085DDA14: ; 85DDA14
	.incbin "base_emerald.gba", 0x5dda14, 0x618

gUnknown_085DE02C: ; 85DE02C
	.incbin "base_emerald.gba", 0x5de02c, 0x5e4

gUnknown_085DE610: ; 85DE610
	.incbin "base_emerald.gba", 0x5de610, 0x618

gUnknown_085DEC28: ; 85DEC28
	.incbin "base_emerald.gba", 0x5dec28, 0x45c

gUnknown_085DF084: ; 85DF084
	.incbin "base_emerald.gba", 0x5df084, 0x618

gUnknown_085DF69C: ; 85DF69C
	.incbin "base_emerald.gba", 0x5df69c, 0x2d0

gUnknown_085DF96C: ; 85DF96C
	.incbin "base_emerald.gba", 0x5df96c, 0x40

gUnknown_085DF9AC: ; 85DF9AC
	.incbin "base_emerald.gba", 0x5df9ac, 0x20

gUnknown_085DF9CC: ; 85DF9CC
	.incbin "base_emerald.gba", 0x5df9cc, 0x20

gUnknown_085DF9EC: ; 85DF9EC
	.incbin "base_emerald.gba", 0x5df9ec, 0xa

gUnknown_085DF9F6: ; 85DF9F6
	.incbin "base_emerald.gba", 0x5df9f6, 0x4

gUnknown_085DF9FA: ; 85DF9FA
	.incbin "base_emerald.gba", 0x5df9fa, 0x20

gUnknown_085DFA1A: ; 85DFA1A
	.incbin "base_emerald.gba", 0x5dfa1a, 0x28

gUnknown_085DFA42: ; 85DFA42
	.incbin "base_emerald.gba", 0x5dfa42, 0x4

gUnknown_085DFA46: ; 85DFA46
	.incbin "base_emerald.gba", 0x5dfa46, 0xc

gUnknown_085DFA52: ; 85DFA52
	.incbin "base_emerald.gba", 0x5dfa52, 0xe

gUnknown_085DFA60: ; 85DFA60
	.incbin "base_emerald.gba", 0x5dfa60, 0x20

gUnknown_085DFA80: ; 85DFA80
	.incbin "base_emerald.gba", 0x5dfa80, 0xe0

gUnknown_085DFB60: ; 85DFB60
	.incbin "base_emerald.gba", 0x5dfb60, 0xac

gUnknown_085DFC0C: ; 85DFC0C
	.incbin "base_emerald.gba", 0x5dfc0c, 0xa4

gUnknown_085DFCB0: ; 85DFCB0
	.incbin "base_emerald.gba", 0x5dfcb0, 0x14

gUnknown_085DFCC4: ; 85DFCC4
	.incbin "base_emerald.gba", 0x5dfcc4, 0x5

gUnknown_085DFCC9: ; 85DFCC9
	.incbin "base_emerald.gba", 0x5dfcc9, 0x3

gUnknown_085DFCCC: ; 85DFCCC
	.incbin "base_emerald.gba", 0x5dfccc, 0x10

gUnknown_085DFCDC: ; 85DFCDC
	.incbin "base_emerald.gba", 0x5dfcdc, 0x20

gUnknown_085DFCFC: ; 85DFCFC
	.incbin "base_emerald.gba", 0x5dfcfc, 0x8

gUnknown_085DFD04: ; 85DFD04
	.incbin "base_emerald.gba", 0x5dfd04, 0x14

gUnknown_085DFD18: ; 85DFD18
	.incbin "base_emerald.gba", 0x5dfd18, 0x8

gUnknown_085DFD20: ; 85DFD20
	.incbin "base_emerald.gba", 0x5dfd20, 0x8

gUnknown_085DFD28: ; 85DFD28
	.incbin "base_emerald.gba", 0x5dfd28, 0x34

gUnknown_085DFD5C: ; 85DFD5C
	.incbin "base_emerald.gba", 0x5dfd5c, 0x44

gUnknown_085DFDA0: ; 85DFDA0
	.incbin "base_emerald.gba", 0x5dfda0, 0x18

gUnknown_085DFDB8: ; 85DFDB8
	.incbin "base_emerald.gba", 0x5dfdb8, 0x8

gUnknown_085DFDC0: ; 85DFDC0
	.incbin "base_emerald.gba", 0x5dfdc0, 0xe4

gUnknown_085DFEA4: ; 85DFEA4
	.incbin "base_emerald.gba", 0x5dfea4, 0x10

gUnknown_085DFEB4: ; 85DFEB4
	.incbin "base_emerald.gba", 0x5dfeb4, 0x20

gUnknown_085DFED4: ; 85DFED4
	.incbin "base_emerald.gba", 0x5dfed4, 0x4

gUnknown_085DFED8: ; 85DFED8
	.incbin "base_emerald.gba", 0x5dfed8, 0x4

gUnknown_085DFEDC: ; 85DFEDC
	.incbin "base_emerald.gba", 0x5dfedc, 0x20

gUnknown_085DFEFC: ; 85DFEFC
	.incbin "base_emerald.gba", 0x5dfefc, 0x8

gUnknown_085DFF04: ; 85DFF04
	.incbin "base_emerald.gba", 0x5dff04, 0x20

gUnknown_085DFF24: ; 85DFF24
	.incbin "base_emerald.gba", 0x5dff24, 0x18

gUnknown_085DFF3C: ; 85DFF3C
	.incbin "base_emerald.gba", 0x5dff3c, 0x8

gUnknown_085DFF44: ; 85DFF44
	.incbin "base_emerald.gba", 0x5dff44, 0x18

gUnknown_085DFF5C: ; 85DFF5C
	.incbin "base_emerald.gba", 0x5dff5c, 0x28

gUnknown_085DFF84: ; 85DFF84
	.incbin "base_emerald.gba", 0x5dff84, 0x8

gUnknown_085DFF8C: ; 85DFF8C
	.incbin "base_emerald.gba", 0x5dff8c, 0x638

gUnknown_085E05C4: ; 85E05C4
	.incbin "base_emerald.gba", 0x5e05c4, 0x200

gUnknown_085E07C4: ; 85E07C4
	.incbin "base_emerald.gba", 0x5e07c4, 0x3b4

gUnknown_085E0B78: ; 85E0B78
	.incbin "base_emerald.gba", 0x5e0b78, 0x334

gUnknown_085E0EAC: ; 85E0EAC
	.incbin "base_emerald.gba", 0x5e0eac, 0x2f0

gUnknown_085E119C: ; 85E119C
	.incbin "base_emerald.gba", 0x5e119c, 0x218

gUnknown_085E13B4: ; 85E13B4
	.incbin "base_emerald.gba", 0x5e13b4, 0x2170

gUnknown_085E3524: ; 85E3524
	.incbin "base_emerald.gba", 0x5e3524, 0x200

gUnknown_085E3724: ; 85E3724
	.incbin "base_emerald.gba", 0x5e3724, 0x130

gUnknown_085E3854: ; 85E3854
	.incbin "base_emerald.gba", 0x5e3854, 0x1220

gUnknown_085E4A74: ; 85E4A74
	.incbin "base_emerald.gba", 0x5e4a74, 0x10

gUnknown_085E4A84: ; 85E4A84
	.incbin "base_emerald.gba", 0x5e4a84, 0x34

gUnknown_085E4AB8: ; 85E4AB8
	.incbin "base_emerald.gba", 0x5e4ab8, 0x18

gUnknown_085E4AD0: ; 85E4AD0
	.incbin "base_emerald.gba", 0x5e4ad0, 0x18

gUnknown_085E4AE8: ; 85E4AE8
	.incbin "base_emerald.gba", 0x5e4ae8, 0x20

gUnknown_085E4B08: ; 85E4B08
	.incbin "base_emerald.gba", 0x5e4b08, 0x38

gUnknown_085E4B40: ; 85E4B40
	.incbin "base_emerald.gba", 0x5e4b40, 0x64

gUnknown_085E4BA4: ; 85E4BA4
	.incbin "base_emerald.gba", 0x5e4ba4, 0x38

gUnknown_085E4BDC: ; 85E4BDC
	.incbin "base_emerald.gba", 0x5e4bdc, 0x18

gUnknown_085E4BF4: ; 85E4BF4
	.incbin "base_emerald.gba", 0x5e4bf4, 0x10

gUnknown_085E4C04: ; 85E4C04
	.incbin "base_emerald.gba", 0x5e4c04, 0x48

gUnknown_085E4C4C: ; 85E4C4C
	.incbin "base_emerald.gba", 0x5e4c4c, 0x18

gUnknown_085E4C64: ; 85E4C64
	.incbin "base_emerald.gba", 0x5e4c64, 0x24

gUnknown_085E4C88: ; 85E4C88
	.incbin "base_emerald.gba", 0x5e4c88, 0x10

gUnknown_085E4C98: ; 85E4C98
	.incbin "base_emerald.gba", 0x5e4c98, 0x10

gUnknown_085E4CA8: ; 85E4CA8
	.incbin "base_emerald.gba", 0x5e4ca8, 0x6c

gUnknown_085E4D14: ; 85E4D14
	.incbin "base_emerald.gba", 0x5e4d14, 0x50

gUnknown_085E4D64: ; 85E4D64
	.incbin "base_emerald.gba", 0x5e4d64, 0x60

gUnknown_085E4DC4: ; 85E4DC4
	.incbin "base_emerald.gba", 0x5e4dc4, 0xd0

gUnknown_085E4E94: ; 85E4E94
	.incbin "base_emerald.gba", 0x5e4e94, 0xb4

gUnknown_085E4F48: ; 85E4F48
	.incbin "base_emerald.gba", 0x5e4f48, 0x14

gUnknown_085E4F5C: ; 85E4F5C
	.incbin "base_emerald.gba", 0x5e4f5c, 0x30

gUnknown_085E4F8C: ; 85E4F8C
	.incbin "base_emerald.gba", 0x5e4f8c, 0x18

gUnknown_085E4FA4: ; 85E4FA4
	.incbin "base_emerald.gba", 0x5e4fa4, 0x20

gUnknown_085E4FC4: ; 85E4FC4
	.incbin "base_emerald.gba", 0x5e4fc4, 0x18

gUnknown_085E4FDC: ; 85E4FDC
	.incbin "base_emerald.gba", 0x5e4fdc, 0x10

gUnknown_085E4FEC: ; 85E4FEC
	.incbin "base_emerald.gba", 0x5e4fec, 0x10

gUnknown_085E4FFC: ; 85E4FFC
	.incbin "base_emerald.gba", 0x5e4ffc, 0x34

gUnknown_085E5030: ; 85E5030
	.incbin "base_emerald.gba", 0x5e5030, 0x18

gUnknown_085E5048: ; 85E5048
	.incbin "base_emerald.gba", 0x5e5048, 0x10

gUnknown_085E5058: ; 85E5058
	.incbin "base_emerald.gba", 0x5e5058, 0x10

gUnknown_085E5068: ; 85E5068
	.incbin "base_emerald.gba", 0x5e5068, 0x8

gUnknown_085E5070: ; 85E5070
	.incbin "base_emerald.gba", 0x5e5070, 0x18

gUnknown_085E5088: ; 85E5088
	.incbin "base_emerald.gba", 0x5e5088, 0xc

gUnknown_085E5094: ; 85E5094
	.incbin "base_emerald.gba", 0x5e5094, 0x60

gUnknown_085E50F4: ; 85E50F4
	.incbin "base_emerald.gba", 0x5e50f4, 0xc0

gUnknown_085E51B4: ; 85E51B4
	.incbin "base_emerald.gba", 0x5e51b4, 0xc

gUnknown_085E51C0: ; 85E51C0
	.incbin "base_emerald.gba", 0x5e51c0, 0x30

gUnknown_085E51F0: ; 85E51F0
	.incbin "base_emerald.gba", 0x5e51f0, 0x60

gUnknown_085E5250: ; 85E5250
	.incbin "base_emerald.gba", 0x5e5250, 0xc0

gUnknown_085E5310: ; 85E5310
	.incbin "base_emerald.gba", 0x5e5310, 0x64

gUnknown_085E5374: ; 85E5374
	.incbin "base_emerald.gba", 0x5e5374, 0xc

gUnknown_085E5380: ; 85E5380
	.incbin "base_emerald.gba", 0x5e5380, 0x8

gUnknown_085E5388: ; 85E5388
	.incbin "base_emerald.gba", 0x5e5388, 0x4

gUnknown_085E538C: ; 85E538C
	.incbin "base_emerald.gba", 0x5e538c, 0x8

gUnknown_085E5394: ; 85E5394
	.incbin "base_emerald.gba", 0x5e5394, 0x10

gUnknown_085E53A4: ; 85E53A4
	.incbin "base_emerald.gba", 0x5e53a4, 0x10

gUnknown_085E53B4: ; 85E53B4
	.incbin "base_emerald.gba", 0x5e53b4, 0x6

gUnknown_085E53BA: ; 85E53BA
	.incbin "base_emerald.gba", 0x5e53ba, 0x2a

gUnknown_085E53E4: ; 85E53E4
	.incbin "base_emerald.gba", 0x5e53e4, 0x18

gUnknown_085E53FC: ; 85E53FC
	.incbin "base_emerald.gba", 0x5e53fc, 0xd4

gUnknown_085E54D0: ; 85E54D0
	.incbin "base_emerald.gba", 0x5e54d0, 0x18

gUnknown_085E54E8: ; 85E54E8
	.incbin "base_emerald.gba", 0x5e54e8, 0x20

gUnknown_085E5508: ; 85E5508
	.incbin "base_emerald.gba", 0x5e5508, 0x1cc

gUnknown_085E56D4: ; 85E56D4
	.incbin "base_emerald.gba", 0x5e56d4, 0x1c

gUnknown_085E56F0: ; 85E56F0
	.incbin "base_emerald.gba", 0x5e56f0, 0x80

gUnknown_085E5770: ; 85E5770
	.incbin "base_emerald.gba", 0x5e5770, 0x43c

gUnknown_085E5BAC: ; 85E5BAC
	.incbin "base_emerald.gba", 0x5e5bac, 0xf

gUnknown_085E5BBB: ; 85E5BBB
	.incbin "base_emerald.gba", 0x5e5bbb, 0xf

gUnknown_085E5BCA: ; 85E5BCA
	.incbin "base_emerald.gba", 0x5e5bca, 0xf

gUnknown_085E5BD9: ; 85E5BD9
	.incbin "base_emerald.gba", 0x5e5bd9, 0xf

gUnknown_085E5BE8: ; 85E5BE8
	.incbin "base_emerald.gba", 0x5e5be8, 0xf0c

gUnknown_085E6AF4: ; 85E6AF4
	.incbin "base_emerald.gba", 0x5e6af4, 0x474

gUnknown_085E6F68: ; 85E6F68
	.incbin "base_emerald.gba", 0x5e6f68, 0x4

gUnknown_085E6F6C: ; 85E6F6C
	.incbin "base_emerald.gba", 0x5e6f6c, 0x10

gUnknown_085E6F7C: ; 85E6F7C
	.incbin "base_emerald.gba", 0x5e6f7c, 0x54

gUnknown_085E6FD0: ; 85E6FD0
	.incbin "base_emerald.gba", 0x5e6fd0, 0x40

gUnknown_085E7010: ; 85E7010
	.incbin "base_emerald.gba", 0x5e7010, 0xc

gUnknown_085E701C: ; 85E701C
	.incbin "base_emerald.gba", 0x5e701c, 0x10

gUnknown_085E702C: ; 85E702C
	.incbin "base_emerald.gba", 0x5e702c, 0x3c

gUnknown_085E7068: ; 85E7068
	.incbin "base_emerald.gba", 0x5e7068, 0x18

gUnknown_085E7080: ; 85E7080
	.incbin "base_emerald.gba", 0x5e7080, 0x8

gUnknown_085E7088: ; 85E7088
	.incbin "base_emerald.gba", 0x5e7088, 0x40

gUnknown_085E70C8: ; 85E70C8
	.incbin "base_emerald.gba", 0x5e70c8, 0x73c

gUnknown_085E7804: ; 85E7804
	.incbin "base_emerald.gba", 0x5e7804, 0x9f8

gUnknown_085E81FC: ; 85E81FC
	.incbin "base_emerald.gba", 0x5e81fc, 0x8

gUnknown_085E8204: ; 85E8204
	.incbin "base_emerald.gba", 0x5e8204, 0x10

gUnknown_085E8214: ; 85E8214
	.incbin "base_emerald.gba", 0x5e8214, 0x4

gUnknown_085E8218: ; 85E8218
	.incbin "base_emerald.gba", 0x5e8218, 0x1

gUnknown_085E8219: ; 85E8219
	.incbin "base_emerald.gba", 0x5e8219, 0x1

gUnknown_085E821A: ; 85E821A
	.incbin "base_emerald.gba", 0x5e821a, 0xf

gUnknown_085E8229: ; 85E8229
	.incbin "base_emerald.gba", 0x5e8229, 0x8

gUnknown_085E8231: ; 85E8231
	.incbin "base_emerald.gba", 0x5e8231, 0x5

gUnknown_085E8236: ; 85E8236
	.incbin "base_emerald.gba", 0x5e8236, 0x6

gUnknown_085E823C: ; 85E823C
	.incbin "base_emerald.gba", 0x5e823c, 0x7

gUnknown_085E8243: ; 85E8243
	.incbin "base_emerald.gba", 0x5e8243, 0x6

gUnknown_085E8249: ; 85E8249
	.incbin "base_emerald.gba", 0x5e8249, 0x7

gUnknown_085E8250: ; 85E8250
	.incbin "base_emerald.gba", 0x5e8250, 0x8

gUnknown_085E8258: ; 85E8258
	.incbin "base_emerald.gba", 0x5e8258, 0x8

gUnknown_085E8260: ; 85E8260
	.incbin "base_emerald.gba", 0x5e8260, 0x4

gUnknown_085E8264: ; 85E8264
	.incbin "base_emerald.gba", 0x5e8264, 0x4

gUnknown_085E8268: ; 85E8268
	.incbin "base_emerald.gba", 0x5e8268, 0x14

gUnknown_085E827C: ; 85E827C
	.incbin "base_emerald.gba", 0x5e827c, 0x9

gUnknown_085E8285: ; 85E8285
	.incbin "base_emerald.gba", 0x5e8285, 0x9

gUnknown_085E828E: ; 85E828E
	.incbin "base_emerald.gba", 0x5e828e, 0x7

gUnknown_085E8295: ; 85E8295
	.incbin "base_emerald.gba", 0x5e8295, 0xd

gUnknown_085E82A2: ; 85E82A2
	.incbin "base_emerald.gba", 0x5e82a2, 0xd

gUnknown_085E82AF: ; 85E82AF
	.incbin "base_emerald.gba", 0x5e82af, 0xf

gUnknown_085E82BE: ; 85E82BE
	.incbin "base_emerald.gba", 0x5e82be, 0x27

gUnknown_085E82E5: ; 85E82E5
	.incbin "base_emerald.gba", 0x5e82e5, 0x43

gUnknown_085E8328: ; 85E8328
	.incbin "base_emerald.gba", 0x5e8328, 0x9a

gUnknown_085E83C2: ; 85E83C2
	.incbin "base_emerald.gba", 0x5e83c2, 0x43

gUnknown_085E8405: ; 85E8405
	.incbin "base_emerald.gba", 0x5e8405, 0x3b

gUnknown_085E8440: ; 85E8440
	.incbin "base_emerald.gba", 0x5e8440, 0x13

gUnknown_085E8453: ; 85E8453
	.incbin "base_emerald.gba", 0x5e8453, 0x7b

gUnknown_085E84CE: ; 85E84CE
	.incbin "base_emerald.gba", 0x5e84ce, 0x8e

gUnknown_085E855C: ; 85E855C
	.incbin "base_emerald.gba", 0x5e855c, 0x18

gUnknown_085E8574: ; 85E8574
	.incbin "base_emerald.gba", 0x5e8574, 0x14

gUnknown_085E8588: ; 85E8588
	.incbin "base_emerald.gba", 0x5e8588, 0x10a

gUnknown_085E8692: ; 85E8692
	.incbin "base_emerald.gba", 0x5e8692, 0x26

gUnknown_085E86B8: ; 85E86B8
	.incbin "base_emerald.gba", 0x5e86b8, 0xe

gUnknown_085E86C6: ; 85E86C6
	.incbin "base_emerald.gba", 0x5e86c6, 0xa

gUnknown_085E86D0: ; 85E86D0
	.incbin "base_emerald.gba", 0x5e86d0, 0x4b

gUnknown_085E871B: ; 85E871B
	.incbin "base_emerald.gba", 0x5e871b, 0x8

gUnknown_085E8723: ; 85E8723
	.incbin "base_emerald.gba", 0x5e8723, 0x12

gUnknown_085E8735: ; 85E8735
	.incbin "base_emerald.gba", 0x5e8735, 0x20

gUnknown_085E8755: ; 85E8755
	.incbin "base_emerald.gba", 0x5e8755, 0x3

gUnknown_085E8758: ; 85E8758
	.incbin "base_emerald.gba", 0x5e8758, 0x3

gUnknown_085E875B: ; 85E875B
	.incbin "base_emerald.gba", 0x5e875b, 0x18

gUnknown_085E8773: ; 85E8773
	.incbin "base_emerald.gba", 0x5e8773, 0x12

gUnknown_085E8785: ; 85E8785
	.incbin "base_emerald.gba", 0x5e8785, 0x3b5

gUnknown_085E8B3A: ; 85E8B3A
	.incbin "base_emerald.gba", 0x5e8b3a, 0x4

gUnknown_085E8B3E: ; 85E8B3E
	.incbin "base_emerald.gba", 0x5e8b3e, 0x9e

gUnknown_085E8BDC: ; 85E8BDC
	.incbin "base_emerald.gba", 0x5e8bdc, 0x24

gUnknown_085E8C00: ; 85E8C00
	.incbin "base_emerald.gba", 0x5e8c00, 0x14

gUnknown_085E8C14: ; 85E8C14
	.incbin "base_emerald.gba", 0x5e8c14, 0x22

gUnknown_085E8C36: ; 85E8C36
	.incbin "base_emerald.gba", 0x5e8c36, 0x5

gUnknown_085E8C3B: ; 85E8C3B
	.incbin "base_emerald.gba", 0x5e8c3b, 0xd

gUnknown_085E8C48: ; 85E8C48
	.incbin "base_emerald.gba", 0x5e8c48, 0x5

gUnknown_085E8C4D: ; 85E8C4D
	.incbin "base_emerald.gba", 0x5e8c4d, 0x6

gUnknown_085E8C53: ; 85E8C53
	.incbin "base_emerald.gba", 0x5e8c53, 0x3d

gUnknown_085E8C90: ; 85E8C90
	.incbin "base_emerald.gba", 0x5e8c90, 0x24

gUnknown_085E8CB4: ; 85E8CB4
	.incbin "base_emerald.gba", 0x5e8cb4, 0x2f

gUnknown_085E8CE3: ; 85E8CE3
	.incbin "base_emerald.gba", 0x5e8ce3, 0xd

gUnknown_085E8CF0: ; 85E8CF0
	.incbin "base_emerald.gba", 0x5e8cf0, 0x7

gUnknown_085E8CF7: ; 85E8CF7
	.incbin "base_emerald.gba", 0x5e8cf7, 0xc

gUnknown_085E8D03: ; 85E8D03
	.incbin "base_emerald.gba", 0x5e8d03, 0x23

gUnknown_085E8D26: ; 85E8D26
	.incbin "base_emerald.gba", 0x5e8d26, 0xe

gUnknown_085E8D34: ; 85E8D34
	.incbin "base_emerald.gba", 0x5e8d34, 0x4

gUnknown_085E8D38: ; 85E8D38
	.incbin "base_emerald.gba", 0x5e8d38, 0x6

gUnknown_085E8D3E: ; 85E8D3E
	.incbin "base_emerald.gba", 0x5e8d3e, 0x2

gUnknown_085E8D40: ; 85E8D40
	.incbin "base_emerald.gba", 0x5e8d40, 0x2

gUnknown_085E8D42: ; 85E8D42
	.incbin "base_emerald.gba", 0x5e8d42, 0x3

gUnknown_085E8D45: ; 85E8D45
	.incbin "base_emerald.gba", 0x5e8d45, 0x4

gUnknown_085E8D49: ; 85E8D49
	.incbin "base_emerald.gba", 0x5e8d49, 0x2

gUnknown_085E8D4B: ; 85E8D4B
	.incbin "base_emerald.gba", 0x5e8d4b, 0x2

gUnknown_085E8D4D: ; 85E8D4D
	.incbin "base_emerald.gba", 0x5e8d4d, 0x2

gUnknown_085E8D4F: ; 85E8D4F
	.incbin "base_emerald.gba", 0x5e8d4f, 0xa

gUnknown_085E8D59: ; 85E8D59
	.incbin "base_emerald.gba", 0x5e8d59, 0x5

gUnknown_085E8D5E: ; 85E8D5E
	.incbin "base_emerald.gba", 0x5e8d5e, 0x2

gUnknown_085E8D60: ; 85E8D60
	.incbin "base_emerald.gba", 0x5e8d60, 0x2

gUnknown_085E8D62: ; 85E8D62
	.incbin "base_emerald.gba", 0x5e8d62, 0x1e

gUnknown_085E8D80: ; 85E8D80
	.incbin "base_emerald.gba", 0x5e8d80, 0x20

gUnknown_085E8DA0: ; 85E8DA0
	.incbin "base_emerald.gba", 0x5e8da0, 0xb

gUnknown_085E8DAB: ; 85E8DAB
	.incbin "base_emerald.gba", 0x5e8dab, 0x9

gUnknown_085E8DB4: ; 85E8DB4
	.incbin "base_emerald.gba", 0x5e8db4, 0xa

gUnknown_085E8DBE: ; 85E8DBE
	.incbin "base_emerald.gba", 0x5e8dbe, 0x10

gUnknown_085E8DCE: ; 85E8DCE
	.incbin "base_emerald.gba", 0x5e8dce, 0x1b

gUnknown_085E8DE9: ; 85E8DE9
	.incbin "base_emerald.gba", 0x5e8de9, 0x15

gUnknown_085E8DFE: ; 85E8DFE
	.incbin "base_emerald.gba", 0x5e8dfe, 0x13

gUnknown_085E8E11: ; 85E8E11
	.incbin "base_emerald.gba", 0x5e8e11, 0x16

gUnknown_085E8E27: ; 85E8E27
	.incbin "base_emerald.gba", 0x5e8e27, 0x1b

gUnknown_085E8E42: ; 85E8E42
	.incbin "base_emerald.gba", 0x5e8e42, 0x18

gUnknown_085E8E5A: ; 85E8E5A
	.incbin "base_emerald.gba", 0x5e8e5a, 0x14

gUnknown_085E8E6E: ; 85E8E6E
	.incbin "base_emerald.gba", 0x5e8e6e, 0x20

gUnknown_085E8E8E: ; 85E8E8E
	.incbin "base_emerald.gba", 0x5e8e8e, 0x2b

gUnknown_085E8EB9: ; 85E8EB9
	.incbin "base_emerald.gba", 0x5e8eb9, 0x27

gUnknown_085E8EE0: ; 85E8EE0
	.incbin "base_emerald.gba", 0x5e8ee0, 0x19

gUnknown_085E8EF9: ; 85E8EF9
	.incbin "base_emerald.gba", 0x5e8ef9, 0x15

gUnknown_085E8F0E: ; 85E8F0E
	.incbin "base_emerald.gba", 0x5e8f0e, 0x23

gUnknown_085E8F31: ; 85E8F31
	.incbin "base_emerald.gba", 0x5e8f31, 0x3d

gUnknown_085E8F6E: ; 85E8F6E
	.incbin "base_emerald.gba", 0x5e8f6e, 0x25

gUnknown_085E8F93: ; 85E8F93
	.incbin "base_emerald.gba", 0x5e8f93, 0x48

gUnknown_085E8FDB: ; 85E8FDB
	.incbin "base_emerald.gba", 0x5e8fdb, 0x27

gUnknown_085E9002: ; 85E9002
	.incbin "base_emerald.gba", 0x5e9002, 0x24

gUnknown_085E9026: ; 85E9026
	.incbin "base_emerald.gba", 0x5e9026, 0x11

gUnknown_085E9037: ; 85E9037
	.incbin "base_emerald.gba", 0x5e9037, 0x10

gUnknown_085E9047: ; 85E9047
	.incbin "base_emerald.gba", 0x5e9047, 0x11

gUnknown_085E9058: ; 85E9058
	.incbin "base_emerald.gba", 0x5e9058, 0x28

gUnknown_085E9080: ; 85E9080
	.incbin "base_emerald.gba", 0x5e9080, 0x12

gUnknown_085E9092: ; 85E9092
	.incbin "base_emerald.gba", 0x5e9092, 0x34

gUnknown_085E90C6: ; 85E90C6
	.incbin "base_emerald.gba", 0x5e90c6, 0x2e

gUnknown_085E90F4: ; 85E90F4
	.incbin "base_emerald.gba", 0x5e90f4, 0x31

gUnknown_085E9125: ; 85E9125
	.incbin "base_emerald.gba", 0x5e9125, 0x13

gUnknown_085E9138: ; 85E9138
	.incbin "base_emerald.gba", 0x5e9138, 0x48

gUnknown_085E9180: ; 85E9180
	.incbin "base_emerald.gba", 0x5e9180, 0x30

gUnknown_085E91B0: ; 85E91B0
	.incbin "base_emerald.gba", 0x5e91b0, 0x10

gUnknown_085E91C0: ; 85E91C0
	.incbin "base_emerald.gba", 0x5e91c0, 0x3c

gUnknown_085E91FC: ; 85E91FC
	.incbin "base_emerald.gba", 0x5e91fc, 0x14

gUnknown_085E9210: ; 85E9210
	.incbin "base_emerald.gba", 0x5e9210, 0xa

gUnknown_085E921A: ; 85E921A
	.incbin "base_emerald.gba", 0x5e921a, 0xb

gUnknown_085E9225: ; 85E9225
	.incbin "base_emerald.gba", 0x5e9225, 0x7

gUnknown_085E922C: ; 85E922C
	.incbin "base_emerald.gba", 0x5e922c, 0x7

gUnknown_085E9233: ; 85E9233
	.incbin "base_emerald.gba", 0x5e9233, 0x30

gUnknown_085E9263: ; 85E9263
	.incbin "base_emerald.gba", 0x5e9263, 0x8

gUnknown_085E926B: ; 85E926B
	.incbin "base_emerald.gba", 0x5e926b, 0xb2

gUnknown_085E931D: ; 85E931D
	.incbin "base_emerald.gba", 0x5e931d, 0x6

gUnknown_085E9323: ; 85E9323
	.incbin "base_emerald.gba", 0x5e9323, 0x4

gUnknown_085E9327: ; 85E9327
	.incbin "base_emerald.gba", 0x5e9327, 0x6

gUnknown_085E932D: ; 85E932D
	.incbin "base_emerald.gba", 0x5e932d, 0x7

gUnknown_085E9334: ; 85E9334
	.incbin "base_emerald.gba", 0x5e9334, 0x10

gUnknown_085E9344: ; 85E9344
	.incbin "base_emerald.gba", 0x5e9344, 0xb

gUnknown_085E934F: ; 85E934F
	.incbin "base_emerald.gba", 0x5e934f, 0x4

gUnknown_085E9353: ; 85E9353
	.incbin "base_emerald.gba", 0x5e9353, 0x14

gUnknown_085E9367: ; 85E9367
	.incbin "base_emerald.gba", 0x5e9367, 0x18

gUnknown_085E937F: ; 85E937F
	.incbin "base_emerald.gba", 0x5e937f, 0x11

gUnknown_085E9390: ; 85E9390
	.incbin "base_emerald.gba", 0x5e9390, 0x19

gUnknown_085E93A9: ; 85E93A9
	.incbin "base_emerald.gba", 0x5e93a9, 0x2c

gUnknown_085E93D5: ; 85E93D5
	.incbin "base_emerald.gba", 0x5e93d5, 0xb

gUnknown_085E93E0: ; 85E93E0
	.incbin "base_emerald.gba", 0x5e93e0, 0xf

gUnknown_085E93EF: ; 85E93EF
	.incbin "base_emerald.gba", 0x5e93ef, 0x28

gUnknown_085E9417: ; 85E9417
	.incbin "base_emerald.gba", 0x5e9417, 0x28

gUnknown_085E943F: ; 85E943F
	.incbin "base_emerald.gba", 0x5e943f, 0x29

gUnknown_085E9468: ; 85E9468
	.incbin "base_emerald.gba", 0x5e9468, 0x2b

gUnknown_085E9493: ; 85E9493
	.incbin "base_emerald.gba", 0x5e9493, 0x32

gUnknown_085E94C5: ; 85E94C5
	.incbin "base_emerald.gba", 0x5e94c5, 0x22

gUnknown_085E94E7: ; 85E94E7
	.incbin "base_emerald.gba", 0x5e94e7, 0x29

gUnknown_085E9510: ; 85E9510
	.incbin "base_emerald.gba", 0x5e9510, 0x29

gUnknown_085E9539: ; 85E9539
	.incbin "base_emerald.gba", 0x5e9539, 0x1f

gUnknown_085E9558: ; 85E9558
	.incbin "base_emerald.gba", 0x5e9558, 0x27

gUnknown_085E957F: ; 85E957F
	.incbin "base_emerald.gba", 0x5e957f, 0x1c

gUnknown_085E959B: ; 85E959B
	.incbin "base_emerald.gba", 0x5e959b, 0x2c

gUnknown_085E95C7: ; 85E95C7
	.incbin "base_emerald.gba", 0x5e95c7, 0x23

gUnknown_085E95EA: ; 85E95EA
	.incbin "base_emerald.gba", 0x5e95ea, 0x25

gUnknown_085E960F: ; 85E960F
	.incbin "base_emerald.gba", 0x5e960f, 0x20

gUnknown_085E962F: ; 85E962F
	.incbin "base_emerald.gba", 0x5e962f, 0x25

gUnknown_085E9654: ; 85E9654
	.incbin "base_emerald.gba", 0x5e9654, 0x23

gUnknown_085E9677: ; 85E9677
	.incbin "base_emerald.gba", 0x5e9677, 0x25

gUnknown_085E969C: ; 85E969C
	.incbin "base_emerald.gba", 0x5e969c, 0x47

gUnknown_085E96E3: ; 85E96E3
	.incbin "base_emerald.gba", 0x5e96e3, 0x3

gUnknown_085E96E6: ; 85E96E6
	.incbin "base_emerald.gba", 0x5e96e6, 0x8

gUnknown_085E96EE: ; 85E96EE
	.incbin "base_emerald.gba", 0x5e96ee, 0x8

gUnknown_085E96F6: ; 85E96F6
	.incbin "base_emerald.gba", 0x5e96f6, 0x1c

gUnknown_085E9712: ; 85E9712
	.incbin "base_emerald.gba", 0x5e9712, 0x26

gUnknown_085E9738: ; 85E9738
	.incbin "base_emerald.gba", 0x5e9738, 0x1c

gUnknown_085E9754: ; 85E9754
	.incbin "base_emerald.gba", 0x5e9754, 0x1b

gUnknown_085E976F: ; 85E976F
	.incbin "base_emerald.gba", 0x5e976f, 0x20

gUnknown_085E978F: ; 85E978F
	.incbin "base_emerald.gba", 0x5e978f, 0x23

gUnknown_085E97B2: ; 85E97B2
	.incbin "base_emerald.gba", 0x5e97b2, 0x33

gUnknown_085E97E5: ; 85E97E5
	.incbin "base_emerald.gba", 0x5e97e5, 0x17

gUnknown_085E97FC: ; 85E97FC
	.incbin "base_emerald.gba", 0x5e97fc, 0x34

gUnknown_085E9830: ; 85E9830
	.incbin "base_emerald.gba", 0x5e9830, 0x25

gUnknown_085E9855: ; 85E9855
	.incbin "base_emerald.gba", 0x5e9855, 0x22

gUnknown_085E9877: ; 85E9877
	.incbin "base_emerald.gba", 0x5e9877, 0x20

gUnknown_085E9897: ; 85E9897
	.incbin "base_emerald.gba", 0x5e9897, 0x1d

gUnknown_085E98B4: ; 85E98B4
	.incbin "base_emerald.gba", 0x5e98b4, 0x38

gUnknown_085E98EC: ; 85E98EC
	.incbin "base_emerald.gba", 0x5e98ec, 0x2f

gUnknown_085E991B: ; 85E991B
	.incbin "base_emerald.gba", 0x5e991b, 0x1f

gUnknown_085E993A: ; 85E993A
	.incbin "base_emerald.gba", 0x5e993a, 0x46

gUnknown_085E9980: ; 85E9980
	.incbin "base_emerald.gba", 0x5e9980, 0x1d

gUnknown_085E999D: ; 85E999D
	.incbin "base_emerald.gba", 0x5e999d, 0x1b

gUnknown_085E99B8: ; 85E99B8
	.incbin "base_emerald.gba", 0x5e99b8, 0x23

gUnknown_085E99DB: ; 85E99DB
	.incbin "base_emerald.gba", 0x5e99db, 0x2d

gUnknown_085E9A08: ; 85E9A08
	.incbin "base_emerald.gba", 0x5e9a08, 0x38

gUnknown_085E9A40: ; 85E9A40
	.incbin "base_emerald.gba", 0x5e9a40, 0x29

gUnknown_085E9A69: ; 85E9A69
	.incbin "base_emerald.gba", 0x5e9a69, 0x3c

gUnknown_085E9AA5: ; 85E9AA5
	.incbin "base_emerald.gba", 0x5e9aa5, 0xf

gUnknown_085E9AB4: ; 85E9AB4
	.incbin "base_emerald.gba", 0x5e9ab4, 0x35

gUnknown_085E9AE9: ; 85E9AE9
	.incbin "base_emerald.gba", 0x5e9ae9, 0x74

gUnknown_085E9B5D: ; 85E9B5D
	.incbin "base_emerald.gba", 0x5e9b5d, 0x19

gUnknown_085E9B76: ; 85E9B76
	.incbin "base_emerald.gba", 0x5e9b76, 0x20

gUnknown_085E9B96: ; 85E9B96
	.incbin "base_emerald.gba", 0x5e9b96, 0x22

gUnknown_085E9BB8: ; 85E9BB8
	.incbin "base_emerald.gba", 0x5e9bb8, 0x48

gUnknown_085E9C00: ; 85E9C00
	.incbin "base_emerald.gba", 0x5e9c00, 0x17

gUnknown_085E9C17: ; 85E9C17
	.incbin "base_emerald.gba", 0x5e9c17, 0x27

gUnknown_085E9C3E: ; 85E9C3E
	.incbin "base_emerald.gba", 0x5e9c3e, 0x21

gUnknown_085E9C5F: ; 85E9C5F
	.incbin "base_emerald.gba", 0x5e9c5f, 0x1d

gUnknown_085E9C7C: ; 85E9C7C
	.incbin "base_emerald.gba", 0x5e9c7c, 0xe

gUnknown_085E9C8A: ; 85E9C8A
	.incbin "base_emerald.gba", 0x5e9c8a, 0x18

gUnknown_085E9CA2: ; 85E9CA2
	.incbin "base_emerald.gba", 0x5e9ca2, 0x15

gUnknown_085E9CB7: ; 85E9CB7
	.incbin "base_emerald.gba", 0x5e9cb7, 0x29

gUnknown_085E9CE0: ; 85E9CE0
	.incbin "base_emerald.gba", 0x5e9ce0, 0x15

gUnknown_085E9CF5: ; 85E9CF5
	.incbin "base_emerald.gba", 0x5e9cf5, 0x15

gUnknown_085E9D0A: ; 85E9D0A
	.incbin "base_emerald.gba", 0x5e9d0a, 0x1b

gUnknown_085E9D25: ; 85E9D25
	.incbin "base_emerald.gba", 0x5e9d25, 0x20

gUnknown_085E9D45: ; 85E9D45
	.incbin "base_emerald.gba", 0x5e9d45, 0x28

gUnknown_085E9D6D: ; 85E9D6D
	.incbin "base_emerald.gba", 0x5e9d6d, 0x23

gUnknown_085E9D90: ; 85E9D90
	.incbin "base_emerald.gba", 0x5e9d90, 0x2e

gUnknown_085E9DBE: ; 85E9DBE
	.incbin "base_emerald.gba", 0x5e9dbe, 0x23

gUnknown_085E9DE1: ; 85E9DE1
	.incbin "base_emerald.gba", 0x5e9de1, 0x1f

gUnknown_085E9E00: ; 85E9E00
	.incbin "base_emerald.gba", 0x5e9e00, 0x14

gUnknown_085E9E14: ; 85E9E14
	.incbin "base_emerald.gba", 0x5e9e14, 0x2da

gUnknown_085EA0EE: ; 85EA0EE
	.incbin "base_emerald.gba", 0x5ea0ee, 0x22

gUnknown_085EA110: ; 85EA110
	.incbin "base_emerald.gba", 0x5ea110, 0x16

gUnknown_085EA126: ; 85EA126
	.incbin "base_emerald.gba", 0x5ea126, 0x13

gUnknown_085EA139: ; 85EA139
	.incbin "base_emerald.gba", 0x5ea139, 0x1c

gUnknown_085EA155: ; 85EA155
	.incbin "base_emerald.gba", 0x5ea155, 0x16

gUnknown_085EA16B: ; 85EA16B
	.incbin "base_emerald.gba", 0x5ea16b, 0x2b

gUnknown_085EA196: ; 85EA196
	.incbin "base_emerald.gba", 0x5ea196, 0x34

gUnknown_085EA1CA: ; 85EA1CA
	.incbin "base_emerald.gba", 0x5ea1ca, 0x3

gUnknown_085EA1CD: ; 85EA1CD
	.incbin "base_emerald.gba", 0x5ea1cd, 0x1b

gUnknown_085EA1E8: ; 85EA1E8
	.incbin "base_emerald.gba", 0x5ea1e8, 0x28

gUnknown_085EA210: ; 85EA210
	.incbin "base_emerald.gba", 0x5ea210, 0x24

gUnknown_085EA234: ; 85EA234
	.incbin "base_emerald.gba", 0x5ea234, 0x108

gUnknown_085EA33C: ; 85EA33C
	.incbin "base_emerald.gba", 0x5ea33c, 0x7

gUnknown_085EA343: ; 85EA343
	.incbin "base_emerald.gba", 0x5ea343, 0x8

gUnknown_085EA34B: ; 85EA34B
	.incbin "base_emerald.gba", 0x5ea34b, 0x8

gUnknown_085EA353: ; 85EA353
	.incbin "base_emerald.gba", 0x5ea353, 0x8

gUnknown_085EA35B: ; 85EA35B
	.incbin "base_emerald.gba", 0x5ea35b, 0x6

gUnknown_085EA361: ; 85EA361
	.incbin "base_emerald.gba", 0x5ea361, 0x4

gUnknown_085EA365: ; 85EA365
	.incbin "base_emerald.gba", 0x5ea365, 0x4

gUnknown_085EA369: ; 85EA369
	.incbin "base_emerald.gba", 0x5ea369, 0xf

gUnknown_085EA378: ; 85EA378
	.incbin "base_emerald.gba", 0x5ea378, 0x6

gUnknown_085EA37E: ; 85EA37E
	.incbin "base_emerald.gba", 0x5ea37e, 0x6

gUnknown_085EA384: ; 85EA384
	.incbin "base_emerald.gba", 0x5ea384, 0x9

gUnknown_085EA38D: ; 85EA38D
	.incbin "base_emerald.gba", 0x5ea38d, 0x7

gUnknown_085EA394: ; 85EA394
	.incbin "base_emerald.gba", 0x5ea394, 0x4

gUnknown_085EA398: ; 85EA398
	.incbin "base_emerald.gba", 0x5ea398, 0x7

gUnknown_085EA39F: ; 85EA39F
	.incbin "base_emerald.gba", 0x5ea39f, 0xc

gUnknown_085EA3AB: ; 85EA3AB
	.incbin "base_emerald.gba", 0x5ea3ab, 0x9

gUnknown_085EA3B4: ; 85EA3B4
	.incbin "base_emerald.gba", 0x5ea3b4, 0xc

gUnknown_085EA3C0: ; 85EA3C0
	.incbin "base_emerald.gba", 0x5ea3c0, 0x8

gUnknown_085EA3C8: ; 85EA3C8
	.incbin "base_emerald.gba", 0x5ea3c8, 0x7

gUnknown_085EA3CF: ; 85EA3CF
	.incbin "base_emerald.gba", 0x5ea3cf, 0xd

gUnknown_085EA3DC: ; 85EA3DC
	.incbin "base_emerald.gba", 0x5ea3dc, 0xf

gUnknown_085EA3EB: ; 85EA3EB
	.incbin "base_emerald.gba", 0x5ea3eb, 0xd

gUnknown_085EA3F8: ; 85EA3F8
	.incbin "base_emerald.gba", 0x5ea3f8, 0xe

gUnknown_085EA406: ; 85EA406
	.incbin "base_emerald.gba", 0x5ea406, 0x5

gUnknown_085EA40B: ; 85EA40B
	.incbin "base_emerald.gba", 0x5ea40b, 0x37

gUnknown_085EA442: ; 85EA442
	.incbin "base_emerald.gba", 0x5ea442, 0x33

gUnknown_085EA475: ; 85EA475
	.incbin "base_emerald.gba", 0x5ea475, 0x2d

gUnknown_085EA4A2: ; 85EA4A2
	.incbin "base_emerald.gba", 0x5ea4a2, 0x29

gUnknown_085EA4CB: ; 85EA4CB
	.incbin "base_emerald.gba", 0x5ea4cb, 0x21

gUnknown_085EA4EC: ; 85EA4EC
	.incbin "base_emerald.gba", 0x5ea4ec, 0x2a

gUnknown_085EA516: ; 85EA516
	.incbin "base_emerald.gba", 0x5ea516, 0x2e

gUnknown_085EA544: ; 85EA544
	.incbin "base_emerald.gba", 0x5ea544, 0x26

gUnknown_085EA56A: ; 85EA56A
	.incbin "base_emerald.gba", 0x5ea56a, 0x3e

gUnknown_085EA5A8: ; 85EA5A8
	.incbin "base_emerald.gba", 0x5ea5a8, 0x33

gUnknown_085EA5DB: ; 85EA5DB
	.incbin "base_emerald.gba", 0x5ea5db, 0x10

gUnknown_085EA5EB: ; 85EA5EB
	.incbin "base_emerald.gba", 0x5ea5eb, 0x2c

gUnknown_085EA617: ; 85EA617
	.incbin "base_emerald.gba", 0x5ea617, 0x30

gUnknown_085EA647: ; 85EA647
	.incbin "base_emerald.gba", 0x5ea647, 0x31

gUnknown_085EA678: ; 85EA678
	.incbin "base_emerald.gba", 0x5ea678, 0x33

gUnknown_085EA6AB: ; 85EA6AB
	.incbin "base_emerald.gba", 0x5ea6ab, 0x2c

gUnknown_085EA6D7: ; 85EA6D7
	.incbin "base_emerald.gba", 0x5ea6d7, 0x2b

gUnknown_085EA702: ; 85EA702
	.incbin "base_emerald.gba", 0x5ea702, 0x2d

gUnknown_085EA72F: ; 85EA72F
	.incbin "base_emerald.gba", 0x5ea72f, 0x8

gUnknown_085EA737: ; 85EA737
	.incbin "base_emerald.gba", 0x5ea737, 0x2b

gUnknown_085EA762: ; 85EA762
	.incbin "base_emerald.gba", 0x5ea762, 0x23

gUnknown_085EA785: ; 85EA785
	.incbin "base_emerald.gba", 0x5ea785, 0x43

gUnknown_085EA7C8: ; 85EA7C8
	.incbin "base_emerald.gba", 0x5ea7c8, 0x75

gUnknown_085EA83D: ; 85EA83D
	.incbin "base_emerald.gba", 0x5ea83d, 0x4e

gUnknown_085EA88B: ; 85EA88B
	.incbin "base_emerald.gba", 0x5ea88b, 0x5

gUnknown_085EA890: ; 85EA890
	.incbin "base_emerald.gba", 0x5ea890, 0x7

gUnknown_085EA897: ; 85EA897
	.incbin "base_emerald.gba", 0x5ea897, 0xf

gUnknown_085EA8A6: ; 85EA8A6
	.incbin "base_emerald.gba", 0x5ea8a6, 0x19

gUnknown_085EA8BF: ; 85EA8BF
	.incbin "base_emerald.gba", 0x5ea8bf, 0x13

gUnknown_085EA8D2: ; 85EA8D2
	.incbin "base_emerald.gba", 0x5ea8d2, 0x18

gUnknown_085EA8EA: ; 85EA8EA
	.incbin "base_emerald.gba", 0x5ea8ea, 0x47

gUnknown_085EA931: ; 85EA931
	.incbin "base_emerald.gba", 0x5ea931, 0x7d

gUnknown_085EA9AE: ; 85EA9AE
	.incbin "base_emerald.gba", 0x5ea9ae, 0x32

gUnknown_085EA9E0: ; 85EA9E0
	.incbin "base_emerald.gba", 0x5ea9e0, 0x34

gUnknown_085EAA14: ; 85EAA14
	.incbin "base_emerald.gba", 0x5eaa14, 0x29

gUnknown_085EAA3D: ; 85EAA3D
	.incbin "base_emerald.gba", 0x5eaa3d, 0x25

gUnknown_085EAA62: ; 85EAA62
	.incbin "base_emerald.gba", 0x5eaa62, 0x1f

gUnknown_085EAA81: ; 85EAA81
	.incbin "base_emerald.gba", 0x5eaa81, 0x22

gUnknown_085EAAA3: ; 85EAAA3
	.incbin "base_emerald.gba", 0x5eaaa3, 0x22

gUnknown_085EAAC5: ; 85EAAC5
	.incbin "base_emerald.gba", 0x5eaac5, 0x27

gUnknown_085EAAEC: ; 85EAAEC
	.incbin "base_emerald.gba", 0x5eaaec, 0x62

gUnknown_085EAB4E: ; 85EAB4E
	.incbin "base_emerald.gba", 0x5eab4e, 0x15

gUnknown_085EAB63: ; 85EAB63
	.incbin "base_emerald.gba", 0x5eab63, 0xe

gUnknown_085EAB71: ; 85EAB71
	.incbin "base_emerald.gba", 0x5eab71, 0x60

gUnknown_085EABD1: ; 85EABD1
	.incbin "base_emerald.gba", 0x5eabd1, 0x16

gUnknown_085EABE7: ; 85EABE7
	.incbin "base_emerald.gba", 0x5eabe7, 0x22

gUnknown_085EAC09: ; 85EAC09
	.incbin "base_emerald.gba", 0x5eac09, 0x19

gUnknown_085EAC22: ; 85EAC22
	.incbin "base_emerald.gba", 0x5eac22, 0x29

gUnknown_085EAC4B: ; 85EAC4B
	.incbin "base_emerald.gba", 0x5eac4b, 0x18

gUnknown_085EAC63: ; 85EAC63
	.incbin "base_emerald.gba", 0x5eac63, 0x2a

gUnknown_085EAC8D: ; 85EAC8D
	.incbin "base_emerald.gba", 0x5eac8d, 0x28

gUnknown_085EACB5: ; 85EACB5
	.incbin "base_emerald.gba", 0x5eacb5, 0x13

gUnknown_085EACC8: ; 85EACC8
	.incbin "base_emerald.gba", 0x5eacc8, 0x3c

gUnknown_085EAD04: ; 85EAD04
	.incbin "base_emerald.gba", 0x5ead04, 0x4

gUnknown_085EAD08: ; 85EAD08
	.incbin "base_emerald.gba", 0x5ead08, 0x4

gUnknown_085EAD0C: ; 85EAD0C
	.incbin "base_emerald.gba", 0x5ead0c, 0x8

gUnknown_085EAD14: ; 85EAD14
	.incbin "base_emerald.gba", 0x5ead14, 0x7

gUnknown_085EAD1B: ; 85EAD1B
	.incbin "base_emerald.gba", 0x5ead1b, 0x7

gUnknown_085EAD22: ; 85EAD22
	.incbin "base_emerald.gba", 0x5ead22, 0x7

gUnknown_085EAD29: ; 85EAD29
	.incbin "base_emerald.gba", 0x5ead29, 0x7

gUnknown_085EAD30: ; 85EAD30
	.incbin "base_emerald.gba", 0x5ead30, 0x132

gUnknown_085EAE62: ; 85EAE62
	.incbin "base_emerald.gba", 0x5eae62, 0x4

gUnknown_085EAE66: ; 85EAE66
	.incbin "base_emerald.gba", 0x5eae66, 0x4b

gUnknown_085EAEB1: ; 85EAEB1
	.incbin "base_emerald.gba", 0x5eaeb1, 0x7

gUnknown_085EAEB8: ; 85EAEB8
	.incbin "base_emerald.gba", 0x5eaeb8, 0x230

gUnknown_085EB0E8: ; 85EB0E8
	.incbin "base_emerald.gba", 0x5eb0e8, 0x5

gUnknown_085EB0ED: ; 85EB0ED
	.incbin "base_emerald.gba", 0x5eb0ed, 0x7

gUnknown_085EB0F4: ; 85EB0F4
	.incbin "base_emerald.gba", 0x5eb0f4, 0x5

gUnknown_085EB0F9: ; 85EB0F9
	.incbin "base_emerald.gba", 0x5eb0f9, 0x6

gUnknown_085EB0FF: ; 85EB0FF
	.incbin "base_emerald.gba", 0x5eb0ff, 0x6a

gUnknown_085EB169: ; 85EB169
	.incbin "base_emerald.gba", 0x5eb169, 0xd

gUnknown_085EB176: ; 85EB176
	.incbin "base_emerald.gba", 0x5eb176, 0xd

gUnknown_085EB183: ; 85EB183
	.incbin "base_emerald.gba", 0x5eb183, 0x8

gUnknown_085EB18B: ; 85EB18B
	.incbin "base_emerald.gba", 0x5eb18b, 0xd

gUnknown_085EB198: ; 85EB198
	.incbin "base_emerald.gba", 0x5eb198, 0xc4

gUnknown_085EB25C: ; 85EB25C
	.incbin "base_emerald.gba", 0x5eb25c, 0x8

gUnknown_085EB264: ; 85EB264
	.incbin "base_emerald.gba", 0x5eb264, 0x8

gUnknown_085EB26C: ; 85EB26C
	.incbin "base_emerald.gba", 0x5eb26c, 0x4

gUnknown_085EB270: ; 85EB270
	.incbin "base_emerald.gba", 0x5eb270, 0x9

gUnknown_085EB279: ; 85EB279
	.incbin "base_emerald.gba", 0x5eb279, 0x5

gUnknown_085EB27E: ; 85EB27E
	.incbin "base_emerald.gba", 0x5eb27e, 0x7

gUnknown_085EB285: ; 85EB285
	.incbin "base_emerald.gba", 0x5eb285, 0x34a

gUnknown_085EB5CF: ; 85EB5CF
	.incbin "base_emerald.gba", 0x5eb5cf, 0xb

gUnknown_085EB5DA: ; 85EB5DA
	.incbin "base_emerald.gba", 0x5eb5da, 0xb

gUnknown_085EB5E5: ; 85EB5E5
	.incbin "base_emerald.gba", 0x5eb5e5, 0x9

gUnknown_085EB5EE: ; 85EB5EE
	.incbin "base_emerald.gba", 0x5eb5ee, 0xb

gUnknown_085EB5F9: ; 85EB5F9
	.incbin "base_emerald.gba", 0x5eb5f9, 0x8

gUnknown_085EB601: ; 85EB601
	.incbin "base_emerald.gba", 0x5eb601, 0x9

gUnknown_085EB60A: ; 85EB60A
	.incbin "base_emerald.gba", 0x5eb60a, 0x4

gUnknown_085EB60E: ; 85EB60E
	.incbin "base_emerald.gba", 0x5eb60e, 0x97

gUnknown_085EB6A5: ; 85EB6A5
	.incbin "base_emerald.gba", 0x5eb6a5, 0x8

gUnknown_085EB6AD: ; 85EB6AD
	.incbin "base_emerald.gba", 0x5eb6ad, 0x13d

gUnknown_085EB7EA: ; 85EB7EA
	.incbin "base_emerald.gba", 0x5eb7ea, 0x49f

gUnknown_085EBC89: ; 85EBC89
	.incbin "base_emerald.gba", 0x5ebc89, 0x24

gUnknown_085EBCAD: ; 85EBCAD
	.incbin "base_emerald.gba", 0x5ebcad, 0x14

gUnknown_085EBCC1: ; 85EBCC1
	.incbin "base_emerald.gba", 0x5ebcc1, 0x89

gUnknown_085EBD4A: ; 85EBD4A
	.incbin "base_emerald.gba", 0x5ebd4a, 0x115

gUnknown_085EBE5F: ; 85EBE5F
	.incbin "base_emerald.gba", 0x5ebe5f, 0xf

gUnknown_085EBE6E: ; 85EBE6E
	.incbin "base_emerald.gba", 0x5ebe6e, 0x11f

gUnknown_085EBF8D: ; 85EBF8D
	.incbin "base_emerald.gba", 0x5ebf8d, 0x8

gUnknown_085EBF95: ; 85EBF95
	.incbin "base_emerald.gba", 0x5ebf95, 0x39

gUnknown_085EBFCE: ; 85EBFCE
	.incbin "base_emerald.gba", 0x5ebfce, 0x9

gUnknown_085EBFD7: ; 85EBFD7
	.incbin "base_emerald.gba", 0x5ebfd7, 0x38

gUnknown_085EC00F: ; 85EC00F
	.incbin "base_emerald.gba", 0x5ec00f, 0x1a

gUnknown_085EC029: ; 85EC029
	.incbin "base_emerald.gba", 0x5ec029, 0x7

gUnknown_085EC030: ; 85EC030
	.incbin "base_emerald.gba", 0x5ec030, 0x376

gUnknown_085EC3A6: ; 85EC3A6
	.incbin "base_emerald.gba", 0x5ec3a6, 0xe

gUnknown_085EC3B4: ; 85EC3B4
	.incbin "base_emerald.gba", 0x5ec3b4, 0x5c

gUnknown_085EC410: ; 85EC410
	.incbin "base_emerald.gba", 0x5ec410, 0x1f

gUnknown_085EC42F: ; 85EC42F
	.incbin "base_emerald.gba", 0x5ec42f, 0x9a

gUnknown_085EC4C9: ; 85EC4C9
	.incbin "base_emerald.gba", 0x5ec4c9, 0x20

gUnknown_085EC4E9: ; 85EC4E9
	.incbin "base_emerald.gba", 0x5ec4e9, 0x37

gUnknown_085EC520: ; 85EC520
	.incbin "base_emerald.gba", 0x5ec520, 0x152

gUnknown_085EC672: ; 85EC672
	.incbin "base_emerald.gba", 0x5ec672, 0x16

gUnknown_085EC688: ; 85EC688
	.incbin "base_emerald.gba", 0x5ec688, 0x20

gUnknown_085EC6A8: ; 85EC6A8
	.incbin "base_emerald.gba", 0x5ec6a8, 0xa

gUnknown_085EC6B2: ; 85EC6B2
	.incbin "base_emerald.gba", 0x5ec6b2, 0x54

gUnknown_085EC706: ; 85EC706
	.incbin "base_emerald.gba", 0x5ec706, 0x21

gUnknown_085EC727: ; 85EC727
	.incbin "base_emerald.gba", 0x5ec727, 0x1c

gUnknown_085EC743: ; 85EC743
	.incbin "base_emerald.gba", 0x5ec743, 0xf

gUnknown_085EC752: ; 85EC752
	.incbin "base_emerald.gba", 0x5ec752, 0x13

gUnknown_085EC765: ; 85EC765
	.incbin "base_emerald.gba", 0x5ec765, 0x3b

gUnknown_085EC7A0: ; 85EC7A0
	.incbin "base_emerald.gba", 0x5ec7a0, 0x41

gUnknown_085EC7E1: ; 85EC7E1
	.incbin "base_emerald.gba", 0x5ec7e1, 0xe

gUnknown_085EC7EF: ; 85EC7EF
	.incbin "base_emerald.gba", 0x5ec7ef, 0x11

gUnknown_085EC800: ; 85EC800
	.incbin "base_emerald.gba", 0x5ec800, 0x16

gUnknown_085EC816: ; 85EC816
	.incbin "base_emerald.gba", 0x5ec816, 0x59

gUnknown_085EC86F: ; 85EC86F
	.incbin "base_emerald.gba", 0x5ec86f, 0x65

gUnknown_085EC8D4: ; 85EC8D4
	.incbin "base_emerald.gba", 0x5ec8d4, 0x43

gUnknown_085EC917: ; 85EC917
	.incbin "base_emerald.gba", 0x5ec917, 0x38

gUnknown_085EC94F: ; 85EC94F
	.incbin "base_emerald.gba", 0x5ec94f, 0x53

gUnknown_085EC9A2: ; 85EC9A2
	.incbin "base_emerald.gba", 0x5ec9a2, 0x30

gUnknown_085EC9D2: ; 85EC9D2
	.incbin "base_emerald.gba", 0x5ec9d2, 0x6

gUnknown_085EC9D8: ; 85EC9D8
	.incbin "base_emerald.gba", 0x5ec9d8, 0xc

gUnknown_085EC9E4: ; 85EC9E4
	.incbin "base_emerald.gba", 0x5ec9e4, 0x8

gUnknown_085EC9EC: ; 85EC9EC
	.incbin "base_emerald.gba", 0x5ec9ec, 0x21

gUnknown_085ECA0D: ; 85ECA0D
	.incbin "base_emerald.gba", 0x5eca0d, 0x15

gUnknown_085ECA22: ; 85ECA22
	.incbin "base_emerald.gba", 0x5eca22, 0x16

gUnknown_085ECA38: ; 85ECA38
	.incbin "base_emerald.gba", 0x5eca38, 0x17

gUnknown_085ECA4F: ; 85ECA4F
	.incbin "base_emerald.gba", 0x5eca4f, 0x3b

gUnknown_085ECA8A: ; 85ECA8A
	.incbin "base_emerald.gba", 0x5eca8a, 0x10

gUnknown_085ECA9A: ; 85ECA9A
	.incbin "base_emerald.gba", 0x5eca9a, 0xd

gUnknown_085ECAA7: ; 85ECAA7
	.incbin "base_emerald.gba", 0x5ecaa7, 0x31

gUnknown_085ECAD8: ; 85ECAD8
	.incbin "base_emerald.gba", 0x5ecad8, 0x34

gUnknown_085ECB0C: ; 85ECB0C
	.incbin "base_emerald.gba", 0x5ecb0c, 0x6

gUnknown_085ECB12: ; 85ECB12
	.incbin "base_emerald.gba", 0x5ecb12, 0x9

gUnknown_085ECB1B: ; 85ECB1B
	.incbin "base_emerald.gba", 0x5ecb1b, 0x5

gUnknown_085ECB20: ; 85ECB20
	.incbin "base_emerald.gba", 0x5ecb20, 0xa

gUnknown_085ECB2A: ; 85ECB2A
	.incbin "base_emerald.gba", 0x5ecb2a, 0xa

gUnknown_085ECB34: ; 85ECB34
	.incbin "base_emerald.gba", 0x5ecb34, 0x6

gUnknown_085ECB3A: ; 85ECB3A
	.incbin "base_emerald.gba", 0x5ecb3a, 0x4

gUnknown_085ECB3E: ; 85ECB3E
	.incbin "base_emerald.gba", 0x5ecb3e, 0xa

gUnknown_085ECB48: ; 85ECB48
	.incbin "base_emerald.gba", 0x5ecb48, 0x6

gUnknown_085ECB4E: ; 85ECB4E
	.incbin "base_emerald.gba", 0x5ecb4e, 0x4

gUnknown_085ECB52: ; 85ECB52
	.incbin "base_emerald.gba", 0x5ecb52, 0x6

gUnknown_085ECB58: ; 85ECB58
	.incbin "base_emerald.gba", 0x5ecb58, 0x7

gUnknown_085ECB5F: ; 85ECB5F
	.incbin "base_emerald.gba", 0x5ecb5f, 0x5

gUnknown_085ECB64: ; 85ECB64
	.incbin "base_emerald.gba", 0x5ecb64, 0x7

gUnknown_085ECB6B: ; 85ECB6B
	.incbin "base_emerald.gba", 0x5ecb6b, 0x7

gUnknown_085ECB72: ; 85ECB72
	.incbin "base_emerald.gba", 0x5ecb72, 0x8

gUnknown_085ECB7A: ; 85ECB7A
	.incbin "base_emerald.gba", 0x5ecb7a, 0x6

gUnknown_085ECB80: ; 85ECB80
	.incbin "base_emerald.gba", 0x5ecb80, 0x7

gUnknown_085ECB87: ; 85ECB87
	.incbin "base_emerald.gba", 0x5ecb87, 0x3d6

gUnknown_085ECF5D: ; 85ECF5D
	.incbin "base_emerald.gba", 0x5ecf5d, 0xe

gUnknown_085ECF6B: ; 85ECF6B
	.incbin "base_emerald.gba", 0x5ecf6b, 0x6

gUnknown_085ECF71: ; 85ECF71
	.incbin "base_emerald.gba", 0x5ecf71, 0x7

gUnknown_085ECF78: ; 85ECF78
	.incbin "base_emerald.gba", 0x5ecf78, 0x6

gUnknown_085ECF7E: ; 85ECF7E
	.incbin "base_emerald.gba", 0x5ecf7e, 0x8

gUnknown_085ECF86: ; 85ECF86
	.incbin "base_emerald.gba", 0x5ecf86, 0x8

gUnknown_085ECF8E: ; 85ECF8E
	.incbin "base_emerald.gba", 0x5ecf8e, 0x1

gUnknown_085ECF8F: ; 85ECF8F
	.incbin "base_emerald.gba", 0x5ecf8f, 0xa

gUnknown_085ECF99: ; 85ECF99
	.incbin "base_emerald.gba", 0x5ecf99, 0xd

gUnknown_085ECFA6: ; 85ECFA6
	.incbin "base_emerald.gba", 0x5ecfa6, 0x12

gUnknown_085ECFB8: ; 85ECFB8
	.incbin "base_emerald.gba", 0x5ecfb8, 0x35

gUnknown_085ECFED: ; 85ECFED
	.incbin "base_emerald.gba", 0x5ecfed, 0x23

gUnknown_085ED010: ; 85ED010
	.incbin "base_emerald.gba", 0x5ed010, 0xf

gUnknown_085ED01F: ; 85ED01F
	.incbin "base_emerald.gba", 0x5ed01f, 0x17

gUnknown_085ED036: ; 85ED036
	.incbin "base_emerald.gba", 0x5ed036, 0xc

gUnknown_085ED042: ; 85ED042
	.incbin "base_emerald.gba", 0x5ed042, 0x43

gUnknown_085ED085: ; 85ED085
	.incbin "base_emerald.gba", 0x5ed085, 0x11

gUnknown_085ED096: ; 85ED096
	.incbin "base_emerald.gba", 0x5ed096, 0x9

gUnknown_085ED09F: ; 85ED09F
	.incbin "base_emerald.gba", 0x5ed09f, 0x17

gUnknown_085ED0B6: ; 85ED0B6
	.incbin "base_emerald.gba", 0x5ed0b6, 0x12

gUnknown_085ED0C8: ; 85ED0C8
	.incbin "base_emerald.gba", 0x5ed0c8, 0xb

gUnknown_085ED0D3: ; 85ED0D3
	.incbin "base_emerald.gba", 0x5ed0d3, 0xd

gUnknown_085ED0E0: ; 85ED0E0
	.incbin "base_emerald.gba", 0x5ed0e0, 0xb3

gUnknown_085ED193: ; 85ED193
	.incbin "base_emerald.gba", 0x5ed193, 0x5

gUnknown_085ED198: ; 85ED198
	.incbin "base_emerald.gba", 0x5ed198, 0x8

gUnknown_085ED1A0: ; 85ED1A0
	.incbin "base_emerald.gba", 0x5ed1a0, 0x7

gUnknown_085ED1A7: ; 85ED1A7
	.incbin "base_emerald.gba", 0x5ed1a7, 0x4

gUnknown_085ED1AB: ; 85ED1AB
	.incbin "base_emerald.gba", 0x5ed1ab, 0x7

gUnknown_085ED1B2: ; 85ED1B2
	.incbin "base_emerald.gba", 0x5ed1b2, 0x3

gUnknown_085ED1B5: ; 85ED1B5
	.incbin "base_emerald.gba", 0x5ed1b5, 0x3

gUnknown_085ED1B8: ; 85ED1B8
	.incbin "base_emerald.gba", 0x5ed1b8, 0x18

gUnknown_085ED1D0: ; 85ED1D0
	.incbin "base_emerald.gba", 0x5ed1d0, 0x19

gUnknown_085ED1E9: ; 85ED1E9
	.incbin "base_emerald.gba", 0x5ed1e9, 0x11

gUnknown_085ED1FA: ; 85ED1FA
	.incbin "base_emerald.gba", 0x5ed1fa, 0xd

gUnknown_085ED207: ; 85ED207
	.incbin "base_emerald.gba", 0x5ed207, 0x17

gUnknown_085ED21E: ; 85ED21E
	.incbin "base_emerald.gba", 0x5ed21e, 0xa

gUnknown_085ED228: ; 85ED228
	.incbin "base_emerald.gba", 0x5ed228, 0x6

gUnknown_085ED22E: ; 85ED22E
	.incbin "base_emerald.gba", 0x5ed22e, 0x5

gUnknown_085ED233: ; 85ED233
	.incbin "base_emerald.gba", 0x5ed233, 0x5

gUnknown_085ED238: ; 85ED238
	.incbin "base_emerald.gba", 0x5ed238, 0x71

gUnknown_085ED2A9: ; 85ED2A9
	.incbin "base_emerald.gba", 0x5ed2a9, 0x14

gUnknown_085ED2BD: ; 85ED2BD
	.incbin "base_emerald.gba", 0x5ed2bd, 0x152

gUnknown_085ED40F: ; 85ED40F
	.incbin "base_emerald.gba", 0x5ed40f, 0x6

gUnknown_085ED415: ; 85ED415
	.incbin "base_emerald.gba", 0x5ed415, 0x8

gUnknown_085ED41D: ; 85ED41D
	.incbin "base_emerald.gba", 0x5ed41d, 0x6

gUnknown_085ED423: ; 85ED423
	.incbin "base_emerald.gba", 0x5ed423, 0x7

gUnknown_085ED42A: ; 85ED42A
	.incbin "base_emerald.gba", 0x5ed42a, 0x6

gUnknown_085ED430: ; 85ED430
	.incbin "base_emerald.gba", 0x5ed430, 0x4

gUnknown_085ED434: ; 85ED434
	.incbin "base_emerald.gba", 0x5ed434, 0x6

gUnknown_085ED43A: ; 85ED43A
	.incbin "base_emerald.gba", 0x5ed43a, 0x6

gUnknown_085ED440: ; 85ED440
	.incbin "base_emerald.gba", 0x5ed440, 0xa

gUnknown_085ED44A: ; 85ED44A
	.incbin "base_emerald.gba", 0x5ed44a, 0x15b

gUnknown_085ED5A5: ; 85ED5A5
	.incbin "base_emerald.gba", 0x5ed5a5, 0x19

gUnknown_085ED5BE: ; 85ED5BE
	.incbin "base_emerald.gba", 0x5ed5be, 0x216

gUnknown_085ED7D4: ; 85ED7D4
	.incbin "base_emerald.gba", 0x5ed7d4, 0xc

gUnknown_085ED7E0: ; 85ED7E0
	.incbin "base_emerald.gba", 0x5ed7e0, 0x28

gUnknown_085ED808: ; 85ED808
	.incbin "base_emerald.gba", 0x5ed808, 0x8

gUnknown_085ED810: ; 85ED810
	.incbin "base_emerald.gba", 0x5ed810, 0x10

gUnknown_085ED820: ; 85ED820
	.incbin "base_emerald.gba", 0x5ed820, 0xc

gUnknown_085ED82C: ; 85ED82C
	.incbin "base_emerald.gba", 0x5ed82c, 0x4

gUnknown_085ED830: ; 85ED830
	.incbin "base_emerald.gba", 0x5ed830, 0x8

gUnknown_085ED838: ; 85ED838
	.incbin "base_emerald.gba", 0x5ed838, 0x8

gUnknown_085ED840: ; 85ED840
	.incbin "base_emerald.gba", 0x5ed840, 0x8

gUnknown_085ED848: ; 85ED848
	.incbin "base_emerald.gba", 0x5ed848, 0x8

gUnknown_085ED850: ; 85ED850
	.incbin "base_emerald.gba", 0x5ed850, 0xc

gUnknown_085ED85C: ; 85ED85C
	.incbin "base_emerald.gba", 0x5ed85c, 0x4

gUnknown_085ED860: ; 85ED860
	.incbin "base_emerald.gba", 0x5ed860, 0x18

gUnknown_085ED878: ; 85ED878
	.incbin "base_emerald.gba", 0x5ed878, 0x58

gUnknown_085ED8D0: ; 85ED8D0
	.incbin "base_emerald.gba", 0x5ed8d0, 0xc

gUnknown_085ED8DC: ; 85ED8DC
	.incbin "base_emerald.gba", 0x5ed8dc, 0x18

gUnknown_085ED8F4: ; 85ED8F4
	.incbin "base_emerald.gba", 0x5ed8f4, 0xb

gUnknown_085ED8FF: ; 85ED8FF
	.incbin "base_emerald.gba", 0x5ed8ff, 0xf

gUnknown_085ED90E: ; 85ED90E
	.incbin "base_emerald.gba", 0x5ed90e, 0xe

gUnknown_085ED91C: ; 85ED91C
	.incbin "base_emerald.gba", 0x5ed91c, 0x3a7

gUnknown_085EDCC3: ; 85EDCC3
	.incbin "base_emerald.gba", 0x5edcc3, 0x7

gUnknown_085EDCCA: ; 85EDCCA
	.incbin "base_emerald.gba", 0x5edcca, 0x5

gUnknown_085EDCCF: ; 85EDCCF
	.incbin "base_emerald.gba", 0x5edccf, 0x8

gUnknown_085EDCD7: ; 85EDCD7
	.incbin "base_emerald.gba", 0x5edcd7, 0x7

gUnknown_085EDCDE: ; 85EDCDE
	.incbin "base_emerald.gba", 0x5edcde, 0x7

gUnknown_085EDCE5: ; 85EDCE5
	.incbin "base_emerald.gba", 0x5edce5, 0x64

gUnknown_085EDD49: ; 85EDD49
	.incbin "base_emerald.gba", 0x5edd49, 0x22

gUnknown_085EDD6B: ; 85EDD6B
	.incbin "base_emerald.gba", 0x5edd6b, 0x1b

gUnknown_085EDD86: ; 85EDD86
	.incbin "base_emerald.gba", 0x5edd86, 0x15

gUnknown_085EDD9B: ; 85EDD9B
	.incbin "base_emerald.gba", 0x5edd9b, 0x22

gUnknown_085EDDBD: ; 85EDDBD
	.incbin "base_emerald.gba", 0x5eddbd, 0x25

gUnknown_085EDDE2: ; 85EDDE2
	.incbin "base_emerald.gba", 0x5edde2, 0x19

gUnknown_085EDDFB: ; 85EDDFB
	.incbin "base_emerald.gba", 0x5eddfb, 0x1d

gUnknown_085EDE18: ; 85EDE18
	.incbin "base_emerald.gba", 0x5ede18, 0x14

gUnknown_085EDE2C: ; 85EDE2C
	.incbin "base_emerald.gba", 0x5ede2c, 0x31

gUnknown_085EDE5D: ; 85EDE5D
	.incbin "base_emerald.gba", 0x5ede5d, 0x8

gUnknown_085EDE65: ; 85EDE65
	.incbin "base_emerald.gba", 0x5ede65, 0x17

gUnknown_085EDE7C: ; 85EDE7C
	.incbin "base_emerald.gba", 0x5ede7c, 0x8

gUnknown_085EDE84: ; 85EDE84
	.incbin "base_emerald.gba", 0x5ede84, 0x9

gUnknown_085EDE8D: ; 85EDE8D
	.incbin "base_emerald.gba", 0x5ede8d, 0x46

gUnknown_085EDED3: ; 85EDED3
	.incbin "base_emerald.gba", 0x5eded3, 0x21

gUnknown_085EDEF4: ; 85EDEF4
	.incbin "base_emerald.gba", 0x5edef4, 0x1d

gUnknown_085EDF11: ; 85EDF11
	.incbin "base_emerald.gba", 0x5edf11, 0x19

gUnknown_085EDF2A: ; 85EDF2A
	.incbin "base_emerald.gba", 0x5edf2a, 0x14

gUnknown_085EDF3E: ; 85EDF3E
	.incbin "base_emerald.gba", 0x5edf3e, 0x31

gUnknown_085EDF6F: ; 85EDF6F
	.incbin "base_emerald.gba", 0x5edf6f, 0x17

gUnknown_085EDF86: ; 85EDF86
	.incbin "base_emerald.gba", 0x5edf86, 0x1a

gUnknown_085EDFA0: ; 85EDFA0
	.incbin "base_emerald.gba", 0x5edfa0, 0x4

gUnknown_085EDFA4: ; 85EDFA4
	.incbin "base_emerald.gba", 0x5edfa4, 0x4

gUnknown_085EDFA8: ; 85EDFA8
	.incbin "base_emerald.gba", 0x5edfa8, 0x4

gUnknown_085EDFAC: ; 85EDFAC
	.incbin "base_emerald.gba", 0x5edfac, 0x4

gUnknown_085EDFB0: ; 85EDFB0
	.incbin "base_emerald.gba", 0x5edfb0, 0xf

gUnknown_085EDFBF: ; 85EDFBF
	.incbin "base_emerald.gba", 0x5edfbf, 0xa

gUnknown_085EDFC9: ; 85EDFC9
	.incbin "base_emerald.gba", 0x5edfc9, 0xd

gUnknown_085EDFD6: ; 85EDFD6
	.incbin "base_emerald.gba", 0x5edfd6, 0x1f

gUnknown_085EDFF5: ; 85EDFF5
	.incbin "base_emerald.gba", 0x5edff5, 0x1f

gUnknown_085EE014: ; 85EE014
	.incbin "base_emerald.gba", 0x5ee014, 0x48

gUnknown_085EE05C: ; 85EE05C
	.incbin "base_emerald.gba", 0x5ee05c, 0xf

gUnknown_085EE06B: ; 85EE06B
	.incbin "base_emerald.gba", 0x5ee06b, 0x2c

gUnknown_085EE097: ; 85EE097
	.incbin "base_emerald.gba", 0x5ee097, 0xc

gUnknown_085EE0A3: ; 85EE0A3
	.incbin "base_emerald.gba", 0x5ee0a3, 0x1c

gUnknown_085EE0BF: ; 85EE0BF
	.incbin "base_emerald.gba", 0x5ee0bf, 0x1d

gUnknown_085EE0DC: ; 85EE0DC
	.incbin "base_emerald.gba", 0x5ee0dc, 0x1e

gUnknown_085EE0FA: ; 85EE0FA
	.incbin "base_emerald.gba", 0x5ee0fa, 0xd

gUnknown_085EE107: ; 85EE107
	.incbin "base_emerald.gba", 0x5ee107, 0x19

gUnknown_085EE120: ; 85EE120
	.incbin "base_emerald.gba", 0x5ee120, 0xd

gUnknown_085EE12D: ; 85EE12D
	.incbin "base_emerald.gba", 0x5ee12d, 0x2b

gUnknown_085EE158: ; 85EE158
	.incbin "base_emerald.gba", 0x5ee158, 0x20

gUnknown_085EE178: ; 85EE178
	.incbin "base_emerald.gba", 0x5ee178, 0x20

gUnknown_085EE198: ; 85EE198
	.incbin "base_emerald.gba", 0x5ee198, 0x1f

gUnknown_085EE1B7: ; 85EE1B7
	.incbin "base_emerald.gba", 0x5ee1b7, 0x24

gUnknown_085EE1DB: ; 85EE1DB
	.incbin "base_emerald.gba", 0x5ee1db, 0x23

gUnknown_085EE1FE: ; 85EE1FE
	.incbin "base_emerald.gba", 0x5ee1fe, 0x23

gUnknown_085EE221: ; 85EE221
	.incbin "base_emerald.gba", 0x5ee221, 0x20

gUnknown_085EE241: ; 85EE241
	.incbin "base_emerald.gba", 0x5ee241, 0x20

gUnknown_085EE261: ; 85EE261
	.incbin "base_emerald.gba", 0x5ee261, 0x1b

gUnknown_085EE27C: ; 85EE27C
	.incbin "base_emerald.gba", 0x5ee27c, 0x1c

gUnknown_085EE298: ; 85EE298
	.incbin "base_emerald.gba", 0x5ee298, 0x20

gUnknown_085EE2B8: ; 85EE2B8
	.incbin "base_emerald.gba", 0x5ee2b8, 0x20

gUnknown_085EE2D8: ; 85EE2D8
	.incbin "base_emerald.gba", 0x5ee2d8, 0x1a

gUnknown_085EE2F2: ; 85EE2F2
	.incbin "base_emerald.gba", 0x5ee2f2, 0x7

gUnknown_085EE2F9: ; 85EE2F9
	.incbin "base_emerald.gba", 0x5ee2f9, 0x9

gUnknown_085EE302: ; 85EE302
	.incbin "base_emerald.gba", 0x5ee302, 0xf

gUnknown_085EE311: ; 85EE311
	.incbin "base_emerald.gba", 0x5ee311, 0x8

gUnknown_085EE319: ; 85EE319
	.incbin "base_emerald.gba", 0x5ee319, 0x7

gUnknown_085EE320: ; 85EE320
	.incbin "base_emerald.gba", 0x5ee320, 0x6

gUnknown_085EE326: ; 85EE326
	.incbin "base_emerald.gba", 0x5ee326, 0xc

gUnknown_085EE332: ; 85EE332
	.incbin "base_emerald.gba", 0x5ee332, 0x6

gUnknown_085EE338: ; 85EE338
	.incbin "base_emerald.gba", 0x5ee338, 0x11

gUnknown_085EE349: ; 85EE349
	.incbin "base_emerald.gba", 0x5ee349, 0x12

gUnknown_085EE35B: ; 85EE35B
	.incbin "base_emerald.gba", 0x5ee35b, 0x12

gUnknown_085EE36D: ; 85EE36D
	.incbin "base_emerald.gba", 0x5ee36d, 0x14

gUnknown_085EE381: ; 85EE381
	.incbin "base_emerald.gba", 0x5ee381, 0x11

gUnknown_085EE392: ; 85EE392
	.incbin "base_emerald.gba", 0x5ee392, 0xa

gUnknown_085EE39C: ; 85EE39C
	.incbin "base_emerald.gba", 0x5ee39c, 0x88

gUnknown_085EE424: ; 85EE424
	.incbin "base_emerald.gba", 0x5ee424, 0x9

gUnknown_085EE42D: ; 85EE42D
	.incbin "base_emerald.gba", 0x5ee42d, 0x22

gUnknown_085EE44F: ; 85EE44F
	.incbin "base_emerald.gba", 0x5ee44f, 0x24

gUnknown_085EE473: ; 85EE473
	.incbin "base_emerald.gba", 0x5ee473, 0x1e

gUnknown_085EE491: ; 85EE491
	.incbin "base_emerald.gba", 0x5ee491, 0x7

gUnknown_085EE498: ; 85EE498
	.incbin "base_emerald.gba", 0x5ee498, 0x2

gUnknown_085EE49A: ; 85EE49A
	.incbin "base_emerald.gba", 0x5ee49a, 0xa

gUnknown_085EE4A4: ; 85EE4A4
	.incbin "base_emerald.gba", 0x5ee4a4, 0x53

gUnknown_085EE4F7: ; 85EE4F7
	.incbin "base_emerald.gba", 0x5ee4f7, 0x15

gUnknown_085EE50C: ; 85EE50C
	.incbin "base_emerald.gba", 0x5ee50c, 0x47

gUnknown_085EE553: ; 85EE553
	.incbin "base_emerald.gba", 0x5ee553, 0x1f

gUnknown_085EE572: ; 85EE572
	.incbin "base_emerald.gba", 0x5ee572, 0x17

gUnknown_085EE589: ; 85EE589
	.incbin "base_emerald.gba", 0x5ee589, 0x4b

gUnknown_085EE5D4: ; 85EE5D4
	.incbin "base_emerald.gba", 0x5ee5d4, 0xb

gUnknown_085EE5DF: ; 85EE5DF
	.incbin "base_emerald.gba", 0x5ee5df, 0xa

gUnknown_085EE5E9: ; 85EE5E9
	.incbin "base_emerald.gba", 0x5ee5e9, 0xb

gUnknown_085EE5F4: ; 85EE5F4
	.incbin "base_emerald.gba", 0x5ee5f4, 0x9

gUnknown_085EE5FD: ; 85EE5FD
	.incbin "base_emerald.gba", 0x5ee5fd, 0xa

gUnknown_085EE607: ; 85EE607
	.incbin "base_emerald.gba", 0x5ee607, 0xc

gUnknown_085EE613: ; 85EE613
	.incbin "base_emerald.gba", 0x5ee613, 0xa

gUnknown_085EE61D: ; 85EE61D
	.incbin "base_emerald.gba", 0x5ee61d, 0xb

gUnknown_085EE628: ; 85EE628
	.incbin "base_emerald.gba", 0x5ee628, 0xd

gUnknown_085EE635: ; 85EE635
	.incbin "base_emerald.gba", 0x5ee635, 0xb

gUnknown_085EE640: ; 85EE640
	.incbin "base_emerald.gba", 0x5ee640, 0x7

gUnknown_085EE647: ; 85EE647
	.incbin "base_emerald.gba", 0x5ee647, 0xd

gUnknown_085EE654: ; 85EE654
	.incbin "base_emerald.gba", 0x5ee654, 0x9

gUnknown_085EE65D: ; 85EE65D
	.incbin "base_emerald.gba", 0x5ee65d, 0xa

gUnknown_085EE667: ; 85EE667
	.incbin "base_emerald.gba", 0x5ee667, 0x23

gUnknown_085EE68A: ; 85EE68A
	.incbin "base_emerald.gba", 0x5ee68a, 0x4

gUnknown_085EE68E: ; 85EE68E
	.incbin "base_emerald.gba", 0x5ee68e, 0x2

gUnknown_085EE690: ; 85EE690
	.incbin "base_emerald.gba", 0x5ee690, 0x6f

gUnknown_085EE6FF: ; 85EE6FF
	.incbin "base_emerald.gba", 0x5ee6ff, 0x17

gUnknown_085EE716: ; 85EE716
	.incbin "base_emerald.gba", 0x5ee716, 0x4f

gUnknown_085EE765: ; 85EE765
	.incbin "base_emerald.gba", 0x5ee765, 0x23

gUnknown_085EE788: ; 85EE788
	.incbin "base_emerald.gba", 0x5ee788, 0x37

gUnknown_085EE7BF: ; 85EE7BF
	.incbin "base_emerald.gba", 0x5ee7bf, 0xf

gUnknown_085EE7CE: ; 85EE7CE
	.incbin "base_emerald.gba", 0x5ee7ce, 0x3c

gUnknown_085EE80A: ; 85EE80A
	.incbin "base_emerald.gba", 0x5ee80a, 0x1d

gUnknown_085EE827: ; 85EE827
	.incbin "base_emerald.gba", 0x5ee827, 0x28

gUnknown_085EE84F: ; 85EE84F
	.incbin "base_emerald.gba", 0x5ee84f, 0x6

gUnknown_085EE855: ; 85EE855
	.incbin "base_emerald.gba", 0x5ee855, 0x9

gUnknown_085EE85E: ; 85EE85E
	.incbin "base_emerald.gba", 0x5ee85e, 0x93

gUnknown_085EE8F1: ; 85EE8F1
	.incbin "base_emerald.gba", 0x5ee8f1, 0x6

gUnknown_085EE8F7: ; 85EE8F7
	.incbin "base_emerald.gba", 0x5ee8f7, 0xc

gUnknown_085EE903: ; 85EE903
	.incbin "base_emerald.gba", 0x5ee903, 0x1b

gUnknown_085EE91E: ; 85EE91E
	.incbin "base_emerald.gba", 0x5ee91e, 0x15

gUnknown_085EE933: ; 85EE933
	.incbin "base_emerald.gba", 0x5ee933, 0xf

gUnknown_085EE942: ; 85EE942
	.incbin "base_emerald.gba", 0x5ee942, 0x17

gUnknown_085EE959: ; 85EE959
	.incbin "base_emerald.gba", 0x5ee959, 0xd

gUnknown_085EE966: ; 85EE966
	.incbin "base_emerald.gba", 0x5ee966, 0x11

gUnknown_085EE977: ; 85EE977
	.incbin "base_emerald.gba", 0x5ee977, 0xcb

gUnknown_085EEA42: ; 85EEA42
	.incbin "base_emerald.gba", 0x5eea42, 0x31

gUnknown_085EEA73: ; 85EEA73
	.incbin "base_emerald.gba", 0x5eea73, 0x3

gUnknown_085EEA76: ; 85EEA76
	.incbin "base_emerald.gba", 0x5eea76, 0x2

gUnknown_085EEA78: ; 85EEA78
	.incbin "base_emerald.gba", 0x5eea78, 0x6

gUnknown_085EEA7E: ; 85EEA7E
	.incbin "base_emerald.gba", 0x5eea7e, 0x10

gUnknown_085EEA8E: ; 85EEA8E
	.incbin "base_emerald.gba", 0x5eea8e, 0x68

gUnknown_085EEAF6: ; 85EEAF6
	.incbin "base_emerald.gba", 0x5eeaf6, 0x15

gUnknown_085EEB0B: ; 85EEB0B
	.incbin "base_emerald.gba", 0x5eeb0b, 0x73

gUnknown_085EEB7E: ; 85EEB7E
	.incbin "base_emerald.gba", 0x5eeb7e, 0x34

gUnknown_085EEBB2: ; 85EEBB2
	.incbin "base_emerald.gba", 0x5eebb2, 0xf

gUnknown_085EEBC1: ; 85EEBC1
	.incbin "base_emerald.gba", 0x5eebc1, 0x1a

gUnknown_085EEBDB: ; 85EEBDB
	.incbin "base_emerald.gba", 0x5eebdb, 0x1b

gUnknown_085EEBF6: ; 85EEBF6
	.incbin "base_emerald.gba", 0x5eebf6, 0x1a

gUnknown_085EEC10: ; 85EEC10
	.incbin "base_emerald.gba", 0x5eec10, 0x5

gUnknown_085EEC15: ; 85EEC15
	.incbin "base_emerald.gba", 0x5eec15, 0x8

gUnknown_085EEC1D: ; 85EEC1D
	.incbin "base_emerald.gba", 0x5eec1d, 0x7

gUnknown_085EEC24: ; 85EEC24
	.incbin "base_emerald.gba", 0x5eec24, 0x9

gUnknown_085EEC2D: ; 85EEC2D
	.incbin "base_emerald.gba", 0x5eec2d, 0x1c

gUnknown_085EEC49: ; 85EEC49
	.incbin "base_emerald.gba", 0x5eec49, 0x4

gUnknown_085EEC4D: ; 85EEC4D
	.incbin "base_emerald.gba", 0x5eec4d, 0x3

gUnknown_085EEC50: ; 85EEC50
	.incbin "base_emerald.gba", 0x5eec50, 0x16

gUnknown_085EEC66: ; 85EEC66
	.incbin "base_emerald.gba", 0x5eec66, 0xd

gUnknown_085EEC73: ; 85EEC73
	.incbin "base_emerald.gba", 0x5eec73, 0x18

gUnknown_085EEC8B: ; 85EEC8B
	.incbin "base_emerald.gba", 0x5eec8b, 0x1a

gUnknown_085EECA5: ; 85EECA5
	.incbin "base_emerald.gba", 0x5eeca5, 0x5

gUnknown_085EECAA: ; 85EECAA
	.incbin "base_emerald.gba", 0x5eecaa, 0x8

gUnknown_085EECB2: ; 85EECB2
	.incbin "base_emerald.gba", 0x5eecb2, 0x9

gUnknown_085EECBB: ; 85EECBB
	.incbin "base_emerald.gba", 0x5eecbb, 0xf

gUnknown_085EECCA: ; 85EECCA
	.incbin "base_emerald.gba", 0x5eecca, 0x4

gUnknown_085EECCE: ; 85EECCE
	.incbin "base_emerald.gba", 0x5eecce, 0x3

gUnknown_085EECD1: ; 85EECD1
	.incbin "base_emerald.gba", 0x5eecd1, 0xc

gUnknown_085EECDD: ; 85EECDD
	.incbin "base_emerald.gba", 0x5eecdd, 0x13

gUnknown_085EECF0: ; 85EECF0
	.incbin "base_emerald.gba", 0x5eecf0, 0x1a

gUnknown_085EED0A: ; 85EED0A
	.incbin "base_emerald.gba", 0x5eed0a, 0x1a

gUnknown_085EED24: ; 85EED24
	.incbin "base_emerald.gba", 0x5eed24, 0x2

gUnknown_085EED26: ; 85EED26
	.incbin "base_emerald.gba", 0x5eed26, 0x7

gUnknown_085EED2D: ; 85EED2D
	.incbin "base_emerald.gba", 0x5eed2d, 0x7

gUnknown_085EED34: ; 85EED34
	.incbin "base_emerald.gba", 0x5eed34, 0x8

gUnknown_085EED3C: ; 85EED3C
	.incbin "base_emerald.gba", 0x5eed3c, 0x1b4

gUnknown_085EEEF0: ; 85EEEF0
	.incbin "base_emerald.gba", 0x5eeef0, 0x3c

gUnknown_085EEF2C: ; 85EEF2C
	.incbin "base_emerald.gba", 0x5eef2c, 0x3c

gUnknown_085EEF68: ; 85EEF68
	.incbin "base_emerald.gba", 0x5eef68, 0x2c

gUnknown_085EEF94: ; 85EEF94
	.incbin "base_emerald.gba", 0x5eef94, 0x54

gUnknown_085EEFE8: ; 85EEFE8
	.incbin "base_emerald.gba", 0x5eefe8, 0x10

gUnknown_085EEFF8: ; 85EEFF8
	.incbin "base_emerald.gba", 0x5eeff8, 0x1c

gUnknown_085EF014: ; 85EF014
	.incbin "base_emerald.gba", 0x5ef014, 0x18

gUnknown_085EF02C: ; 85EF02C
	.incbin "base_emerald.gba", 0x5ef02c, 0x24

gUnknown_085EF050: ; 85EF050
	.incbin "base_emerald.gba", 0x5ef050, 0x34

gUnknown_085EF084: ; 85EF084
	.incbin "base_emerald.gba", 0x5ef084, 0x44

gUnknown_085EF0C8: ; 85EF0C8
	.incbin "base_emerald.gba", 0x5ef0c8, 0x2c

gUnknown_085EF0F4: ; 85EF0F4
	.incbin "base_emerald.gba", 0x5ef0f4, 0x30

gUnknown_085EF124: ; 85EF124
	.incbin "base_emerald.gba", 0x5ef124, 0x28

gUnknown_085EF14C: ; 85EF14C
	.incbin "base_emerald.gba", 0x5ef14c, 0x2c

gUnknown_085EF178: ; 85EF178
	.incbin "base_emerald.gba", 0x5ef178, 0x20

gUnknown_085EF198: ; 85EF198
	.incbin "base_emerald.gba", 0x5ef198, 0x1c

gUnknown_085EF1B4: ; 85EF1B4
	.incbin "base_emerald.gba", 0x5ef1b4, 0x24

gUnknown_085EF1D8: ; 85EF1D8
	.incbin "base_emerald.gba", 0x5ef1d8, 0x28

gUnknown_085EF200: ; 85EF200
	.incbin "base_emerald.gba", 0x5ef200, 0x1c

gUnknown_085EF21C: ; 85EF21C
	.incbin "base_emerald.gba", 0x5ef21c, 0x28

gUnknown_085EF244: ; 85EF244
	.incbin "base_emerald.gba", 0x5ef244, 0x3c

gUnknown_085EF280: ; 85EF280
	.incbin "base_emerald.gba", 0x5ef280, 0x34

gUnknown_085EF2B4: ; 85EF2B4
	.incbin "base_emerald.gba", 0x5ef2b4, 0x30

gUnknown_085EF2E4: ; 85EF2E4
	.incbin "base_emerald.gba", 0x5ef2e4, 0x18

gUnknown_085EF2FC: ; 85EF2FC
	.incbin "base_emerald.gba", 0x5ef2fc, 0x34

gUnknown_085EF330: ; 85EF330
	.incbin "base_emerald.gba", 0x5ef330, 0x30

gUnknown_085EF360: ; 85EF360
	.incbin "base_emerald.gba", 0x5ef360, 0x1c

gUnknown_085EF37C: ; 85EF37C
	.incbin "base_emerald.gba", 0x5ef37c, 0x20

gUnknown_085EF39C: ; 85EF39C
	.incbin "base_emerald.gba", 0x5ef39c, 0x28

gUnknown_085EF3C4: ; 85EF3C4
	.incbin "base_emerald.gba", 0x5ef3c4, 0x2c

gUnknown_085EF3F0: ; 85EF3F0
	.incbin "base_emerald.gba", 0x5ef3f0, 0x20

gUnknown_085EF410: ; 85EF410
	.incbin "base_emerald.gba", 0x5ef410, 0x1c

gUnknown_085EF42C: ; 85EF42C
	.incbin "base_emerald.gba", 0x5ef42c, 0x34

gUnknown_085EF460: ; 85EF460
	.incbin "base_emerald.gba", 0x5ef460, 0x34

gUnknown_085EF494: ; 85EF494
	.incbin "base_emerald.gba", 0x5ef494, 0x30

gUnknown_085EF4C4: ; 85EF4C4
	.incbin "base_emerald.gba", 0x5ef4c4, 0x2c

gUnknown_085EF4F0: ; 85EF4F0
	.incbin "base_emerald.gba", 0x5ef4f0, 0x30

gUnknown_085EF520: ; 85EF520
	.incbin "base_emerald.gba", 0x5ef520, 0x3c

gUnknown_085EF55C: ; 85EF55C
	.incbin "base_emerald.gba", 0x5ef55c, 0x28

gUnknown_085EF584: ; 85EF584
	.incbin "base_emerald.gba", 0x5ef584, 0x38

gUnknown_085EF5BC: ; 85EF5BC
	.incbin "base_emerald.gba", 0x5ef5bc, 0x24

gUnknown_085EF5E0: ; 85EF5E0
	.incbin "base_emerald.gba", 0x5ef5e0, 0x2c

gUnknown_085EF60C: ; 85EF60C
	.incbin "base_emerald.gba", 0x5ef60c, 0x24

gUnknown_085EF630: ; 85EF630
	.incbin "base_emerald.gba", 0x5ef630, 0x24

gUnknown_085EF654: ; 85EF654
	.incbin "base_emerald.gba", 0x5ef654, 0x10

gUnknown_085EF664: ; 85EF664
	.incbin "base_emerald.gba", 0x5ef664, 0x14

gUnknown_085EF678: ; 85EF678
	.incbin "base_emerald.gba", 0x5ef678, 0x15

gUnknown_085EF68D: ; 85EF68D
	.incbin "base_emerald.gba", 0x5ef68d, 0x14

gUnknown_085EF6A1: ; 85EF6A1
	.incbin "base_emerald.gba", 0x5ef6a1, 0x1c

gUnknown_085EF6BD: ; 85EF6BD
	.incbin "base_emerald.gba", 0x5ef6bd, 0x15

gUnknown_085EF6D2: ; 85EF6D2
	.incbin "base_emerald.gba", 0x5ef6d2, 0x17

gUnknown_085EF6E9: ; 85EF6E9
	.incbin "base_emerald.gba", 0x5ef6e9, 0xf

gUnknown_085EF6F8: ; 85EF6F8
	.incbin "base_emerald.gba", 0x5ef6f8, 0x18

gUnknown_085EF710: ; 85EF710
	.incbin "base_emerald.gba", 0x5ef710, 0x24

gUnknown_085EF734: ; 85EF734
	.incbin "base_emerald.gba", 0x5ef734, 0x1c

gUnknown_085EF750: ; 85EF750
	.incbin "base_emerald.gba", 0x5ef750, 0x131

gUnknown_085EF881: ; 85EF881
	.incbin "base_emerald.gba", 0x5ef881, 0x2

gUnknown_085EF883: ; 85EF883
	.incbin "base_emerald.gba", 0x5ef883, 0x5

gUnknown_085EF888: ; 85EF888
	.incbin "base_emerald.gba", 0x5ef888, 0x2

gUnknown_085EF88A: ; 85EF88A
	.incbin "base_emerald.gba", 0x5ef88a, 0xb

gUnknown_085EF895: ; 85EF895
	.incbin "base_emerald.gba", 0x5ef895, 0xe

gUnknown_085EF8A3: ; 85EF8A3
	.incbin "base_emerald.gba", 0x5ef8a3, 0x1f

gUnknown_085EF8C2: ; 85EF8C2
	.incbin "base_emerald.gba", 0x5ef8c2, 0x18

gUnknown_085EF8DA: ; 85EF8DA
	.incbin "base_emerald.gba", 0x5ef8da, 0xa

gUnknown_085EF8E4: ; 85EF8E4
	.incbin "base_emerald.gba", 0x5ef8e4, 0xf

gUnknown_085EF8F3: ; 85EF8F3
	.incbin "base_emerald.gba", 0x5ef8f3, 0x6d

gUnknown_085EF960: ; 85EF960
	.incbin "base_emerald.gba", 0x5ef960, 0x19

gUnknown_085EF979: ; 85EF979
	.incbin "base_emerald.gba", 0x5ef979, 0x2d

gUnknown_085EF9A6: ; 85EF9A6
	.incbin "base_emerald.gba", 0x5ef9a6, 0x40

gUnknown_085EF9E6: ; 85EF9E6
	.incbin "base_emerald.gba", 0x5ef9e6, 0x2a

gUnknown_085EFA10: ; 85EFA10
	.incbin "base_emerald.gba", 0x5efa10, 0x21

gUnknown_085EFA31: ; 85EFA31
	.incbin "base_emerald.gba", 0x5efa31, 0xd

gUnknown_085EFA3E: ; 85EFA3E
	.incbin "base_emerald.gba", 0x5efa3e, 0x14

gUnknown_085EFA52: ; 85EFA52
	.incbin "base_emerald.gba", 0x5efa52, 0x4

gUnknown_085EFA56: ; 85EFA56
	.incbin "base_emerald.gba", 0x5efa56, 0x7

gUnknown_085EFA5D: ; 85EFA5D
	.incbin "base_emerald.gba", 0x5efa5d, 0xa

gUnknown_085EFA67: ; 85EFA67
	.incbin "base_emerald.gba", 0x5efa67, 0x7

gUnknown_085EFA6E: ; 85EFA6E
	.incbin "base_emerald.gba", 0x5efa6e, 0x21

gUnknown_085EFA8F: ; 85EFA8F
	.incbin "base_emerald.gba", 0x5efa8f, 0x1b

gUnknown_085EFAAA: ; 85EFAAA
	.incbin "base_emerald.gba", 0x5efaaa, 0x1c

gUnknown_085EFAC6: ; 85EFAC6
	.incbin "base_emerald.gba", 0x5efac6, 0x1a

gUnknown_085EFAE0: ; 85EFAE0
	.incbin "base_emerald.gba", 0x5efae0, 0x8

gUnknown_085EFAE8: ; 85EFAE8
	.incbin "base_emerald.gba", 0x5efae8, 0xea

gUnknown_085EFBD2: ; 85EFBD2
	.incbin "base_emerald.gba", 0x5efbd2, 0x3a

gUnknown_085EFC0C: ; 85EFC0C
	.incbin "base_emerald.gba", 0x5efc0c, 0x1b

gUnknown_085EFC27: ; 85EFC27
	.incbin "base_emerald.gba", 0x5efc27, 0xad

gUnknown_085EFCD4: ; 85EFCD4
	.incbin "base_emerald.gba", 0x5efcd4, 0xb

gUnknown_085EFCDF: ; 85EFCDF
	.incbin "base_emerald.gba", 0x5efcdf, 0x6

gUnknown_085EFCE5: ; 85EFCE5
	.incbin "base_emerald.gba", 0x5efce5, 0xb

gUnknown_085EFCF0: ; 85EFCF0
	.incbin "base_emerald.gba", 0x5efcf0, 0x10

gUnknown_085EFD00: ; 85EFD00
	.incbin "base_emerald.gba", 0x5efd00, 0x20

gUnknown_085EFD20: ; 85EFD20
	.incbin "base_emerald.gba", 0x5efd20, 0x8

gUnknown_085EFD28: ; 85EFD28
	.incbin "base_emerald.gba", 0x5efd28, 0x28

gUnknown_085EFD50: ; 85EFD50
	.incbin "base_emerald.gba", 0x5efd50, 0x14

gUnknown_085EFD64: ; 85EFD64
	.incbin "base_emerald.gba", 0x5efd64, 0x4

gUnknown_085EFD68: ; 85EFD68
	.incbin "base_emerald.gba", 0x5efd68, 0x18

gUnknown_085EFD80: ; 85EFD80
	.incbin "base_emerald.gba", 0x5efd80, 0x8

gUnknown_085EFD88: ; 85EFD88
	.incbin "base_emerald.gba", 0x5efd88, 0xc

gUnknown_085EFD94: ; 85EFD94
	.incbin "base_emerald.gba", 0x5efd94, 0x8

gUnknown_085EFD9C: ; 85EFD9C
	.incbin "base_emerald.gba", 0x5efd9c, 0x8

gUnknown_085EFDA4: ; 85EFDA4
	.incbin "base_emerald.gba", 0x5efda4, 0x8

gUnknown_085EFDAC: ; 85EFDAC
	.incbin "base_emerald.gba", 0x5efdac, 0x18

gUnknown_085EFDC4: ; 85EFDC4
	.incbin "base_emerald.gba", 0x5efdc4, 0x20

gUnknown_085EFDE4: ; 85EFDE4
	.incbin "base_emerald.gba", 0x5efde4, 0x90

gUnknown_085EFE74: ; 85EFE74
	.incbin "base_emerald.gba", 0x5efe74, 0x48

gUnknown_085EFEBC: ; 85EFEBC
	.incbin "base_emerald.gba", 0x5efebc, 0x32

gUnknown_085EFEEE: ; 85EFEEE
	.incbin "base_emerald.gba", 0x5efeee, 0x12

gUnknown_085EFF00: ; 85EFF00
	.incbin "base_emerald.gba", 0x5eff00, 0x5fc

gUnknown_085F04FC: ; 85F04FC
	.incbin "base_emerald.gba", 0x5f04fc, 0x54

gUnknown_085F0550: ; 85F0550
	.incbin "base_emerald.gba", 0x5f0550, 0x8

gUnknown_085F0558: ; 85F0558
	.incbin "base_emerald.gba", 0x5f0558, 0x10

gUnknown_085F0568: ; 85F0568
	.incbin "base_emerald.gba", 0x5f0568, 0x48

gUnknown_085F05B0: ; 85F05B0
	.incbin "base_emerald.gba", 0x5f05b0, 0xb4

gUnknown_085F0664: ; 85F0664
	.incbin "base_emerald.gba", 0x5f0664, 0x4

gUnknown_085F0668: ; 85F0668
	.incbin "base_emerald.gba", 0x5f0668, 0x4

gUnknown_085F066C: ; 85F066C
	.incbin "base_emerald.gba", 0x5f066c, 0x34

gUnknown_085F06A0: ; 85F06A0
	.incbin "base_emerald.gba", 0x5f06a0, 0x8

gUnknown_085F06A8: ; 85F06A8
	.incbin "base_emerald.gba", 0x5f06a8, 0x18

gUnknown_085F06C0: ; 85F06C0
	.incbin "base_emerald.gba", 0x5f06c0, 0x8

gUnknown_085F06C8: ; 85F06C8
	.incbin "base_emerald.gba", 0x5f06c8, 0x10

gUnknown_085F06D8: ; 85F06D8
	.incbin "base_emerald.gba", 0x5f06d8, 0x8

gUnknown_085F06E0: ; 85F06E0
	.incbin "base_emerald.gba", 0x5f06e0, 0x20

gUnknown_085F0700: ; 85F0700
	.incbin "base_emerald.gba", 0x5f0700, 0x20

gUnknown_085F0720: ; 85F0720
	.incbin "base_emerald.gba", 0x5f0720, 0x20

gUnknown_085F0740: ; 85F0740
	.incbin "base_emerald.gba", 0x5f0740, 0x480

gUnknown_085F0BC0: ; 85F0BC0
	.incbin "base_emerald.gba", 0x5f0bc0, 0x13c

gUnknown_085F0CFC: ; 85F0CFC
	.incbin "base_emerald.gba", 0x5f0cfc, 0x60

gUnknown_085F0D5C: ; 85F0D5C
	.incbin "base_emerald.gba", 0x5f0d5c, 0x60

gUnknown_085F0DBC: ; 85F0DBC
	.incbin "base_emerald.gba", 0x5f0dbc, 0x5dc

gUnknown_085F1398: ; 85F1398
	.incbin "base_emerald.gba", 0x5f1398, 0x2d0

gUnknown_085F1668: ; 85F1668
	.incbin "base_emerald.gba", 0x5f1668, 0x20

gUnknown_085F1688: ; 85F1688
	.incbin "base_emerald.gba", 0x5f1688, 0x20

gUnknown_085F16A8: ; 85F16A8
	.incbin "base_emerald.gba", 0x5f16a8, 0x13c

gUnknown_085F17E4: ; 85F17E4
	.incbin "base_emerald.gba", 0x5f17e4, 0x20

gUnknown_085F1804: ; 85F1804
	.incbin "base_emerald.gba", 0x5f1804, 0x20

gUnknown_085F1824: ; 85F1824
	.incbin "base_emerald.gba", 0x5f1824, 0x688

gUnknown_085F1EAC: ; 85F1EAC
	.incbin "base_emerald.gba", 0x5f1eac, 0x304

gUnknown_085F21B0: ; 85F21B0
	.incbin "base_emerald.gba", 0x5f21b0, 0x16c

gUnknown_085F231C: ; 85F231C
	.incbin "base_emerald.gba", 0x5f231c, 0x40

gUnknown_085F235C: ; 85F235C
	.incbin "base_emerald.gba", 0x5f235c, 0x1ec

gUnknown_085F2548: ; 85F2548
	.incbin "base_emerald.gba", 0x5f2548, 0x20

gUnknown_085F2568: ; 85F2568
	.incbin "base_emerald.gba", 0x5f2568, 0x2ae4

gUnknown_085F504C: ; 85F504C
	.incbin "base_emerald.gba", 0x5f504c, 0x18

gUnknown_085F5064: ; 85F5064
	.incbin "base_emerald.gba", 0x5f5064, 0x30

gUnknown_085F5094: ; 85F5094
	.incbin "base_emerald.gba", 0x5f5094, 0x10

gUnknown_085F50A4: ; 85F50A4
	.incbin "base_emerald.gba", 0x5f50a4, 0x48

gUnknown_085F50EC: ; 85F50EC
	.incbin "base_emerald.gba", 0x5f50ec, 0x28

gUnknown_085F5114: ; 85F5114
	.incbin "base_emerald.gba", 0x5f5114, 0xc

gUnknown_085F5120: ; 85F5120
	.incbin "base_emerald.gba", 0x5f5120, 0x60

gUnknown_085F5180: ; 85F5180
	.incbin "base_emerald.gba", 0x5f5180, 0x18

gUnknown_085F5198: ; 85F5198
	.incbin "base_emerald.gba", 0x5f5198, 0x4

gUnknown_085F519C: ; 85F519C
	.incbin "base_emerald.gba", 0x5f519c, 0x50

gUnknown_085F51EC: ; 85F51EC
	.incbin "base_emerald.gba", 0x5f51ec, 0x18

gUnknown_085F5204: ; 85F5204
	.incbin "base_emerald.gba", 0x5f5204, 0x38

gUnknown_085F523C: ; 85F523C
	.incbin "base_emerald.gba", 0x5f523c, 0x18

gUnknown_085F5254: ; 85F5254
	.incbin "base_emerald.gba", 0x5f5254, 0x38

gUnknown_085F528C: ; 85F528C
	.incbin "base_emerald.gba", 0x5f528c, 0x18

gUnknown_085F52A4: ; 85F52A4
	.incbin "base_emerald.gba", 0x5f52a4, 0x18

gUnknown_085F52BC: ; 85F52BC
	.incbin "base_emerald.gba", 0x5f52bc, 0x10

gUnknown_085F52CC: ; 85F52CC
	.incbin "base_emerald.gba", 0x5f52cc, 0x10

gUnknown_085F52DC: ; 85F52DC
	.incbin "base_emerald.gba", 0x5f52dc, 0x20

gUnknown_085F52FC: ; 85F52FC
	.incbin "base_emerald.gba", 0x5f52fc, 0x10

gUnknown_085F530C: ; 85F530C
	.incbin "base_emerald.gba", 0x5f530c, 0x28

gUnknown_085F5334: ; 85F5334
	.incbin "base_emerald.gba", 0x5f5334, 0x10

gUnknown_085F5344: ; 85F5344
	.incbin "base_emerald.gba", 0x5f5344, 0x10

gUnknown_085F5354: ; 85F5354
	.incbin "base_emerald.gba", 0x5f5354, 0x30

gUnknown_085F5384: ; 85F5384
	.incbin "base_emerald.gba", 0x5f5384, 0x28

gUnknown_085F53AC: ; 85F53AC
	.incbin "base_emerald.gba", 0x5f53ac, 0x10

gUnknown_085F53BC: ; 85F53BC
	.incbin "base_emerald.gba", 0x5f53bc, 0x50

gUnknown_085F540C: ; 85F540C
	.incbin "base_emerald.gba", 0x5f540c, 0x10

gUnknown_085F541C: ; 85F541C
	.incbin "base_emerald.gba", 0x5f541c, 0x24

gUnknown_085F5440: ; 85F5440
	.incbin "base_emerald.gba", 0x5f5440, 0x18

gUnknown_085F5458: ; 85F5458
	.incbin "base_emerald.gba", 0x5f5458, 0x38

gUnknown_085F5490: ; 85F5490
	.incbin "base_emerald.gba", 0x5f5490, 0x4

gUnknown_085F5494: ; 85F5494
	.incbin "base_emerald.gba", 0x5f5494, 0x4d40

gUnknown_085FA1D4: ; 85FA1D4
	.incbin "base_emerald.gba", 0x5fa1d4, 0x4

gUnknown_085FA1D8: ; 85FA1D8
	.incbin "base_emerald.gba", 0x5fa1d8, 0xff90

gUnknown_0860A168: ; 860A168
	.incbin "base_emerald.gba", 0x60a168, 0x1b8

gUnknown_0860A320: ; 860A320
	.incbin "base_emerald.gba", 0x60a320, 0x8c

gUnknown_0860A3AC: ; 860A3AC
	.incbin "base_emerald.gba", 0x60a3ac, 0x30

gUnknown_0860A3DC: ; 860A3DC
	.incbin "base_emerald.gba", 0x60a3dc, 0xd0

gUnknown_0860A4AC: ; 860A4AC
	.incbin "base_emerald.gba", 0x60a4ac, 0x388

gUnknown_0860A834: ; 860A834
	.incbin "base_emerald.gba", 0x60a834, 0x70

gUnknown_0860A8A4: ; 860A8A4
	.incbin "base_emerald.gba", 0x60a8a4, 0x24

gUnknown_0860A8C8: ; 860A8C8
	.incbin "base_emerald.gba", 0x60a8c8, 0x19c

gUnknown_0860AA64: ; 860AA64
	.incbin "base_emerald.gba", 0x60aa64, 0x1c

gUnknown_0860AA80: ; 860AA80
	.incbin "base_emerald.gba", 0x60aa80, 0x8

gUnknown_0860AA88: ; 860AA88
	.incbin "base_emerald.gba", 0x60aa88, 0x25c

gUnknown_0860ACE4: ; 860ACE4
	.incbin "base_emerald.gba", 0x60ace4, 0x4b

gUnknown_0860AD2F: ; 860AD2F
	.incbin "base_emerald.gba", 0x60ad2f, 0x39

gUnknown_0860AD68: ; 860AD68
	.incbin "base_emerald.gba", 0x60ad68, 0x8

gUnknown_0860AD70: ; 860AD70
	.incbin "base_emerald.gba", 0x60ad70, 0x1e

gUnknown_0860AD8E: ; 860AD8E
	.incbin "base_emerald.gba", 0x60ad8e, 0x30

gUnknown_0860ADBE: ; 860ADBE
	.incbin "base_emerald.gba", 0x60adbe, 0xbe

gUnknown_0860AE7C: ; 860AE7C
	.incbin "base_emerald.gba", 0x60ae7c, 0xc

gUnknown_0860AE88: ; 860AE88
	.incbin "base_emerald.gba", 0x60ae88, 0x8

gUnknown_0860AE90: ; 860AE90
	.incbin "base_emerald.gba", 0x60ae90, 0xe4

gUnknown_0860AF74: ; 860AF74
	.incbin "base_emerald.gba", 0x60af74, 0xe4

gUnknown_0860B058: ; 860B058
	.incbin "base_emerald.gba", 0x60b058, 0xc

gUnknown_0860B064: ; 860B064
	.incbin "base_emerald.gba", 0x60b064, 0x8

gUnknown_0860B06C: ; 860B06C
	.incbin "base_emerald.gba", 0x60b06c, 0x8

gUnknown_0860B074: ; 860B074
	.incbin "base_emerald.gba", 0x60b074, 0xa

gUnknown_0860B07E: ; 860B07E
	.incbin "base_emerald.gba", 0x60b07e, 0x126

gUnknown_0860B1A4: ; 860B1A4
	.incbin "base_emerald.gba", 0x60b1a4, 0x40

gUnknown_0860B1E4: ; 860B1E4
	.incbin "base_emerald.gba", 0x60b1e4, 0x20

gUnknown_0860B204: ; 860B204
	.incbin "base_emerald.gba", 0x60b204, 0x20

gUnknown_0860B224: ; 860B224
	.incbin "base_emerald.gba", 0x60b224, 0xc8

gUnknown_0860B2EC: ; 860B2EC
	.incbin "base_emerald.gba", 0x60b2ec, 0x18

gUnknown_0860B304: ; 860B304
	.incbin "base_emerald.gba", 0x60b304, 0xc

gUnknown_0860B310: ; 860B310
	.incbin "base_emerald.gba", 0x60b310, 0x14

gUnknown_0860B324: ; 860B324
	.incbin "base_emerald.gba", 0x60b324, 0x14

gUnknown_0860B338: ; 860B338
	.incbin "base_emerald.gba", 0x60b338, 0x14

gUnknown_0860B34C: ; 860B34C
	.incbin "base_emerald.gba", 0x60b34c, 0xc

gUnknown_0860B358: ; 860B358
	.incbin "base_emerald.gba", 0x60b358, 0x1630

gUnknown_0860C988: ; 860C988
	.incbin "base_emerald.gba", 0x60c988, 0x269

gUnknown_0860CBF1: ; 860CBF1
	.incbin "base_emerald.gba", 0x60cbf1, 0x283

gUnknown_0860CE74: ; 860CE74
	.incbin "base_emerald.gba", 0x60ce74, 0x10

gUnknown_0860CE84: ; 860CE84
	.incbin "base_emerald.gba", 0x60ce84, 0x10

gUnknown_0860CE94: ; 860CE94
	.incbin "base_emerald.gba", 0x60ce94, 0x20

gUnknown_0860CEB4: ; 860CEB4
	.incbin "base_emerald.gba", 0x60ceb4, 0x90

gUnknown_0860CF44: ; 860CF44
	.incbin "base_emerald.gba", 0x60cf44, 0xc

gUnknown_0860CF50: ; 860CF50
	.incbin "base_emerald.gba", 0x60cf50, 0x58

gUnknown_0860CFA8: ; 860CFA8
	.incbin "base_emerald.gba", 0x60cfa8, 0x30

gUnknown_0860CFD8: ; 860CFD8
	.incbin "base_emerald.gba", 0x60cfd8, 0x30

gUnknown_0860D008: ; 860D008
	.incbin "base_emerald.gba", 0x60d008, 0x48

gUnknown_0860D050: ; 860D050
	.incbin "base_emerald.gba", 0x60d050, 0x18

gUnknown_0860D068: ; 860D068
	.incbin "base_emerald.gba", 0x60d068, 0x18

gUnknown_0860D080: ; 860D080
	.incbin "base_emerald.gba", 0x60d080, 0x10

gUnknown_0860D090: ; 860D090
	.incbin "base_emerald.gba", 0x60d090, 0x5c

gUnknown_0860D0EC: ; 860D0EC
	.incbin "base_emerald.gba", 0x60d0ec, 0x10

gUnknown_0860D0FC: ; 860D0FC
	.incbin "base_emerald.gba", 0x60d0fc, 0x10

gUnknown_0860D10C: ; 860D10C
	.incbin "base_emerald.gba", 0x60d10c, 0x40

gUnknown_0860D14C: ; 860D14C
	.incbin "base_emerald.gba", 0x60d14c, 0x10

gUnknown_0860D15C: ; 860D15C
	.incbin "base_emerald.gba", 0x60d15c, 0x40

gUnknown_0860D19C: ; 860D19C
	.incbin "base_emerald.gba", 0x60d19c, 0x4

gUnknown_0860D1A0: ; 860D1A0
	.incbin "base_emerald.gba", 0x60d1a0, 0x20

gUnknown_0860D1C0: ; 860D1C0
	.incbin "base_emerald.gba", 0x60d1c0, 0x10

gUnknown_0860D1D0: ; 860D1D0
	.incbin "base_emerald.gba", 0x60d1d0, 0x44

gUnknown_0860D214: ; 860D214
	.incbin "base_emerald.gba", 0x60d214, 0x80

gUnknown_0860D294: ; 860D294
	.incbin "base_emerald.gba", 0x60d294, 0xac

gUnknown_0860D340: ; 860D340
	.incbin "base_emerald.gba", 0x60d340, 0x3

gUnknown_0860D343: ; 860D343
	.incbin "base_emerald.gba", 0x60d343, 0x3

gUnknown_0860D346: ; 860D346
	.incbin "base_emerald.gba", 0x60d346, 0x3

gUnknown_0860D349: ; 860D349
	.incbin "base_emerald.gba", 0x60d349, 0x7

gUnknown_0860D350: ; 860D350
	.incbin "base_emerald.gba", 0x60d350, 0x3c

gUnknown_0860D38C: ; 860D38C
	.incbin "base_emerald.gba", 0x60d38c, 0x1c

gUnknown_0860D3A8: ; 860D3A8
	.incbin "base_emerald.gba", 0x60d3a8, 0x3

gUnknown_0860D3AB: ; 860D3AB
	.incbin "base_emerald.gba", 0x60d3ab, 0x3

gUnknown_0860D3AE: ; 860D3AE
	.incbin "base_emerald.gba", 0x60d3ae, 0x3

gUnknown_0860D3B1: ; 860D3B1
	.incbin "base_emerald.gba", 0x60d3b1, 0x3

gUnknown_0860D3B4: ; 860D3B4
	.incbin "base_emerald.gba", 0x60d3b4, 0x10

gUnknown_0860D3C4: ; 860D3C4
	.incbin "base_emerald.gba", 0x60d3c4, 0x2

gUnknown_0860D3C6: ; 860D3C6
	.incbin "base_emerald.gba", 0x60d3c6, 0x2b

gUnknown_0860D3F1: ; 860D3F1
	.incbin "base_emerald.gba", 0x60d3f1, 0x1

gUnknown_0860D3F2: ; 860D3F2
	.incbin "base_emerald.gba", 0x60d3f2, 0x1f

gUnknown_0860D411: ; 860D411
	.incbin "base_emerald.gba", 0x60d411, 0x8ff

gUnknown_0860DD10: ; 860DD10
	.incbin "base_emerald.gba", 0x60dd10, 0x100

gUnknown_0860DE10: ; 860DE10
	.incbin "base_emerald.gba", 0x60de10, 0x40

gUnknown_0860DE50: ; 860DE50
	.incbin "base_emerald.gba", 0x60de50, 0x28

gUnknown_0860DE78: ; 860DE78
	.incbin "base_emerald.gba", 0x60de78, 0xc

gUnknown_0860DE84: ; 860DE84
	.incbin "base_emerald.gba", 0x60de84, 0x14

gUnknown_0860DE98: ; 860DE98
	.incbin "base_emerald.gba", 0x60de98, 0x10

gUnknown_0860DEA8: ; 860DEA8
	.incbin "base_emerald.gba", 0x60dea8, 0x10

gUnknown_0860DEB8: ; 860DEB8
	.incbin "base_emerald.gba", 0x60deb8, 0xb68

gUnknown_0860EA20: ; 860EA20
	.incbin "base_emerald.gba", 0x60ea20, 0xc

gUnknown_0860EA2C: ; 860EA2C
	.incbin "base_emerald.gba", 0x60ea2c, 0x8

gUnknown_0860EA34: ; 860EA34
	.incbin "base_emerald.gba", 0x60ea34, 0x18

gUnknown_0860EA4C: ; 860EA4C
	.incbin "base_emerald.gba", 0x60ea4c, 0x20

gUnknown_0860EA6C: ; 860EA6C
	.incbin "base_emerald.gba", 0x60ea6c, 0x100

gUnknown_0860EB6C: ; 860EB6C
	.incbin "base_emerald.gba", 0x60eb6c, 0x20

gUnknown_0860EB8C: ; 860EB8C
	.incbin "base_emerald.gba", 0x60eb8c, 0x3e4

gUnknown_0860EF70: ; 860EF70
	.incbin "base_emerald.gba", 0x60ef70, 0x8

gUnknown_0860EF78: ; 860EF78
	.incbin "base_emerald.gba", 0x60ef78, 0x20

gUnknown_0860EF98: ; 860EF98
	.incbin "base_emerald.gba", 0x60ef98, 0x8

gUnknown_0860EFA0: ; 860EFA0
	.incbin "base_emerald.gba", 0x60efa0, 0xc

gUnknown_0860EFAC: ; 860EFAC
	.incbin "base_emerald.gba", 0x60efac, 0x18

gUnknown_0860EFC4: ; 860EFC4
	.incbin "base_emerald.gba", 0x60efc4, 0x30

gUnknown_0860EFF4: ; 860EFF4
	.incbin "base_emerald.gba", 0x60eff4, 0x1c

gUnknown_0860F010: ; 860F010
	.incbin "base_emerald.gba", 0x60f010, 0x10

gUnknown_0860F020: ; 860F020
	.incbin "base_emerald.gba", 0x60f020, 0x54

gUnknown_0860F074: ; 860F074
	.incbin "base_emerald.gba", 0x60f074, 0x20

gUnknown_0860F094: ; 860F094
	.incbin "base_emerald.gba", 0x60f094, 0x4

gUnknown_0860F098: ; 860F098
	.incbin "base_emerald.gba", 0x60f098, 0x10

gUnknown_0860F0A8: ; 860F0A8
	.incbin "base_emerald.gba", 0x60f0a8, 0x8

gUnknown_0860F0B0: ; 860F0B0
	.incbin "base_emerald.gba", 0x60f0b0, 0x20

gUnknown_0860F0D0: ; 860F0D0
	.incbin "base_emerald.gba", 0x60f0d0, 0x4

gUnknown_0860F0D4: ; 860F0D4
	.incbin "base_emerald.gba", 0x60f0d4, 0x68

gUnknown_0860F13C: ; 860F13C
	.incbin "base_emerald.gba", 0x60f13c, 0x1100

gUnknown_0861023C: ; 861023C
	.incbin "base_emerald.gba", 0x61023c, 0x100

gUnknown_0861033C: ; 861033C
	.incbin "base_emerald.gba", 0x61033c, 0x60

gUnknown_0861039C: ; 861039C
	.incbin "base_emerald.gba", 0x61039c, 0x20

gUnknown_086103BC: ; 86103BC
	.incbin "base_emerald.gba", 0x6103bc, 0x28

gUnknown_086103E4: ; 86103E4
	.incbin "base_emerald.gba", 0x6103e4, 0x10

gUnknown_086103F4: ; 86103F4
	.incbin "base_emerald.gba", 0x6103f4, 0x28

gUnknown_0861041C: ; 861041C
	.incbin "base_emerald.gba", 0x61041c, 0xc

gUnknown_08610428: ; 8610428
	.incbin "base_emerald.gba", 0x610428, 0xc

gUnknown_08610434: ; 8610434
	.incbin "base_emerald.gba", 0x610434, 0x38

gUnknown_0861046C: ; 861046C
	.incbin "base_emerald.gba", 0x61046c, 0xa

gUnknown_08610476: ; 8610476
	.incbin "base_emerald.gba", 0x610476, 0x3

gUnknown_08610479: ; 8610479
	.incbin "base_emerald.gba", 0x610479, 0x15f

gUnknown_086105D8: ; 86105D8
	.incbin "base_emerald.gba", 0x6105d8, 0x18

gUnknown_086105F0: ; 86105F0
	.incbin "base_emerald.gba", 0x6105f0, 0x18

gUnknown_08610608: ; 8610608
	.incbin "base_emerald.gba", 0x610608, 0x18

gUnknown_08610620: ; 8610620
	.incbin "base_emerald.gba", 0x610620, 0x18

gUnknown_08610638: ; 8610638
	.incbin "base_emerald.gba", 0x610638, 0x18

gUnknown_08610650: ; 8610650
	.incbin "base_emerald.gba", 0x610650, 0x50

gUnknown_086106A0: ; 86106A0
	.incbin "base_emerald.gba", 0x6106a0, 0x10

gUnknown_086106B0: ; 86106B0
	.incbin "base_emerald.gba", 0x6106b0, 0x184

gUnknown_08610834: ; 8610834
	.incbin "base_emerald.gba", 0x610834, 0x18

gUnknown_0861084C: ; 861084C
	.incbin "base_emerald.gba", 0x61084c, 0x18

gUnknown_08610864: ; 8610864
	.incbin "base_emerald.gba", 0x610864, 0x18

gUnknown_0861087C: ; 861087C
	.incbin "base_emerald.gba", 0x61087c, 0x18

gUnknown_08610894: ; 8610894
	.incbin "base_emerald.gba", 0x610894, 0x18

gUnknown_086108AC: ; 86108AC
	.incbin "base_emerald.gba", 0x6108ac, 0xc

gUnknown_086108B8: ; 86108B8
	.incbin "base_emerald.gba", 0x6108b8, 0x10

gUnknown_086108C8: ; 86108C8
	.incbin "base_emerald.gba", 0x6108c8, 0x50

gUnknown_08610918: ; 8610918
	.incbin "base_emerald.gba", 0x610918, 0xa

gUnknown_08610922: ; 8610922
	.incbin "base_emerald.gba", 0x610922, 0x3

gUnknown_08610925: ; 8610925
	.incbin "base_emerald.gba", 0x610925, 0x3

gUnknown_08610928: ; 8610928
	.incbin "base_emerald.gba", 0x610928, 0x20

gUnknown_08610948: ; 8610948
	.incbin "base_emerald.gba", 0x610948, 0x28

gUnknown_08610970: ; 8610970
	.incbin "base_emerald.gba", 0x610970, 0x34

gUnknown_086109A4: ; 86109A4
	.incbin "base_emerald.gba", 0x6109a4, 0x16

gUnknown_086109BA: ; 86109BA
	.incbin "base_emerald.gba", 0x6109ba, 0x536

gUnknown_08610EF0: ; 8610EF0
	.incbin "base_emerald.gba", 0x610ef0, 0x100

gUnknown_08610FF0: ; 8610FF0
	.incbin "base_emerald.gba", 0x610ff0, 0x80

gUnknown_08611070: ; 8611070
	.incbin "base_emerald.gba", 0x611070, 0x140

gUnknown_086111B0: ; 86111B0
	.incbin "base_emerald.gba", 0x6111b0, 0x80

gUnknown_08611230: ; 8611230
	.incbin "base_emerald.gba", 0x611230, 0x80

gUnknown_086112B0: ; 86112B0
	.incbin "base_emerald.gba", 0x6112b0, 0x80

gUnknown_08611330: ; 8611330
	.incbin "base_emerald.gba", 0x611330, 0x40

gUnknown_08611370: ; 8611370
	.incbin "base_emerald.gba", 0x611370, 0x163

gUnknown_086114D3: ; 86114D3
	.incbin "base_emerald.gba", 0x6114d3, 0xd

gUnknown_086114E0: ; 86114E0
	.incbin "base_emerald.gba", 0x6114e0, 0x68

gUnknown_08611548: ; 8611548
	.incbin "base_emerald.gba", 0x611548, 0x8

gUnknown_08611550: ; 8611550
	.incbin "base_emerald.gba", 0x611550, 0x1c

gUnknown_0861156C: ; 861156C
	.incbin "base_emerald.gba", 0x61156c, 0xc

gUnknown_08611578: ; 8611578
	.incbin "base_emerald.gba", 0x611578, 0x33c

gUnknown_086118B4: ; 86118B4
	.incbin "base_emerald.gba", 0x6118b4, 0x348

gUnknown_08611BFC: ; 8611BFC
	.incbin "base_emerald.gba", 0x611bfc, 0x1c

gUnknown_08611C18: ; 8611C18
	.incbin "base_emerald.gba", 0x611c18, 0x5c

gUnknown_08611C74: ; 8611C74
	.incbin "base_emerald.gba", 0x611c74, 0x8

gUnknown_08611C7C: ; 8611C7C
	.incbin "base_emerald.gba", 0x611c7c, 0x8

gUnknown_08611C84: ; 8611C84
	.incbin "base_emerald.gba", 0x611c84, 0x8

gUnknown_08611C8C: ; 8611C8C
	.incbin "base_emerald.gba", 0x611c8c, 0xe

gUnknown_08611C9A: ; 8611C9A
	.incbin "base_emerald.gba", 0x611c9a, 0x16

gUnknown_08611CB0: ; 8611CB0
	.incbin "base_emerald.gba", 0x611cb0, 0x50

gUnknown_08611D00: ; 8611D00
	.incbin "base_emerald.gba", 0x611d00, 0x8

gUnknown_08611D08: ; 8611D08
	.incbin "base_emerald.gba", 0x611d08, 0x28

gUnknown_08611D30: ; 8611D30
	.incbin "base_emerald.gba", 0x611d30, 0x80

gUnknown_08611DB0: ; 8611DB0
	.incbin "base_emerald.gba", 0x611db0, 0x8

gUnknown_08611DB8: ; 8611DB8
	.incbin "base_emerald.gba", 0x611db8, 0x8

gUnknown_08611DC0: ; 8611DC0
	.incbin "base_emerald.gba", 0x611dc0, 0x19c

gUnknown_08611F5C: ; 8611F5C
	.incbin "base_emerald.gba", 0x611f5c, 0x18

gUnknown_08611F74: ; 8611F74
	.incbin "base_emerald.gba", 0x611f74, 0x10

gUnknown_08611F84: ; 8611F84
	.incbin "base_emerald.gba", 0x611f84, 0x1c

gUnknown_08611FA0: ; 8611FA0
	.incbin "base_emerald.gba", 0x611fa0, 0xc

gUnknown_08611FAC: ; 8611FAC
	.incbin "base_emerald.gba", 0x611fac, 0x14

gUnknown_08611FC0: ; 8611FC0
	.incbin "base_emerald.gba", 0x611fc0, 0x144

gUnknown_08612104: ; 8612104
	.incbin "base_emerald.gba", 0x612104, 0x1c

gUnknown_08612120: ; 8612120
	.incbin "base_emerald.gba", 0x612120, 0x44

gUnknown_08612164: ; 8612164
	.incbin "base_emerald.gba", 0x612164, 0x10

gUnknown_08612174: ; 8612174
	.incbin "base_emerald.gba", 0x612174, 0x10

gUnknown_08612184: ; 8612184
	.incbin "base_emerald.gba", 0x612184, 0x10

gUnknown_08612194: ; 8612194
	.incbin "base_emerald.gba", 0x612194, 0x180

gUnknown_08612314: ; 8612314
	.incbin "base_emerald.gba", 0x612314, 0x8

gUnknown_0861231C: ; 861231C
	.incbin "base_emerald.gba", 0x61231c, 0xc8

gUnknown_086123E4: ; 86123E4
	.incbin "base_emerald.gba", 0x6123e4, 0x1f8

gUnknown_086125DC: ; 86125DC
	.incbin "base_emerald.gba", 0x6125dc, 0x1c

gUnknown_086125F8: ; 86125F8
	.incbin "base_emerald.gba", 0x6125f8, 0x74

gUnknown_0861266C: ; 861266C
	.incbin "base_emerald.gba", 0x61266c, 0x9

gUnknown_08612675: ; 8612675
	.incbin "base_emerald.gba", 0x612675, 0x13

gUnknown_08612688: ; 8612688
	.incbin "base_emerald.gba", 0x612688, 0x8

gUnknown_08612690: ; 8612690
	.incbin "base_emerald.gba", 0x612690, 0x8

gUnknown_08612698: ; 8612698
	.incbin "base_emerald.gba", 0x612698, 0x4

gUnknown_0861269C: ; 861269C
	.incbin "base_emerald.gba", 0x61269c, 0x4

gUnknown_086126A0: ; 86126A0
	.incbin "base_emerald.gba", 0x6126a0, 0x4

gUnknown_086126A4: ; 86126A4
	.incbin "base_emerald.gba", 0x6126a4, 0x4

gUnknown_086126A8: ; 86126A8
	.incbin "base_emerald.gba", 0x6126a8, 0x2

gUnknown_086126AA: ; 86126AA
	.incbin "base_emerald.gba", 0x6126aa, 0x2

gUnknown_086126AC: ; 86126AC
	.incbin "base_emerald.gba", 0x6126ac, 0x2

gUnknown_086126AE: ; 86126AE
	.incbin "base_emerald.gba", 0x6126ae, 0x782

gUnknown_08612E30: ; 8612E30
	.incbin "base_emerald.gba", 0x612e30, 0x7d0

gUnknown_08613600: ; 8613600
	.incbin "base_emerald.gba", 0x613600, 0x50

gUnknown_08613650: ; 8613650
	.incbin "base_emerald.gba", 0x613650, 0x5

gUnknown_08613655: ; 8613655
	.incbin "base_emerald.gba", 0x613655, 0xfb

gUnknown_08613750: ; 8613750
	.incbin "base_emerald.gba", 0x613750, 0x44

gUnknown_08613794: ; 8613794
	.incbin "base_emerald.gba", 0x613794, 0x8

gUnknown_0861379C: ; 861379C
	.incbin "base_emerald.gba", 0x61379c, 0x190

gUnknown_0861392C: ; 861392C
	.incbin "base_emerald.gba", 0x61392c, 0x190

gUnknown_08613ABC: ; 8613ABC
	.incbin "base_emerald.gba", 0x613abc, 0x7e

gUnknown_08613B3A: ; 8613B3A
	.incbin "base_emerald.gba", 0x613b3a, 0xa

gUnknown_08613B44: ; 8613B44
	.incbin "base_emerald.gba", 0x613b44, 0xd8

gUnknown_08613C1C: ; 8613C1C
	.incbin "base_emerald.gba", 0x613c1c, 0x2a4

gUnknown_08613EC0: ; 8613EC0
	.incbin "base_emerald.gba", 0x613ec0, 0x18

gUnknown_08613ED8: ; 8613ED8
	.incbin "base_emerald.gba", 0x613ed8, 0x8

gUnknown_08613EE0: ; 8613EE0
	.incbin "base_emerald.gba", 0x613ee0, 0x48

gUnknown_08613F28: ; 8613F28
	.incbin "base_emerald.gba", 0x613f28, 0xc

gUnknown_08613F34: ; 8613F34
	.incbin "base_emerald.gba", 0x613f34, 0x12

gUnknown_08613F46: ; 8613F46
	.incbin "base_emerald.gba", 0x613f46, 0x40

gUnknown_08613F86: ; 8613F86
	.incbin "base_emerald.gba", 0x613f86, 0xa

gUnknown_08613F90: ; 8613F90
	.incbin "base_emerald.gba", 0x613f90, 0xc

gUnknown_08613F9C: ; 8613F9C
	.incbin "base_emerald.gba", 0x613f9c, 0x18

gUnknown_08613FB4: ; 8613FB4
	.incbin "base_emerald.gba", 0x613fb4, 0x78

gUnknown_0861402C: ; 861402C
	.incbin "base_emerald.gba", 0x61402c, 0x4

gUnknown_08614030: ; 8614030
	.incbin "base_emerald.gba", 0x614030, 0x4

gUnknown_08614034: ; 8614034
	.incbin "base_emerald.gba", 0x614034, 0x4

gUnknown_08614038: ; 8614038
	.incbin "base_emerald.gba", 0x614038, 0x4

gUnknown_0861403C: ; 861403C
	.incbin "base_emerald.gba", 0x61403c, 0x6

gUnknown_08614042: ; 8614042
	.incbin "base_emerald.gba", 0x614042, 0x2

gUnknown_08614044: ; 8614044
	.incbin "base_emerald.gba", 0x614044, 0x2

gUnknown_08614046: ; 8614046
	.incbin "base_emerald.gba", 0x614046, 0x1

gUnknown_08614047: ; 8614047
	.incbin "base_emerald.gba", 0x614047, 0x4

gUnknown_0861404B: ; 861404B
	.incbin "base_emerald.gba", 0x61404b, 0x2

gUnknown_0861404D: ; 861404D
	.incbin "base_emerald.gba", 0x61404d, 0x2

gUnknown_0861404F: ; 861404F
	.incbin "base_emerald.gba", 0x61404f, 0x5

gUnknown_08614054: ; 8614054
	.incbin "base_emerald.gba", 0x614054, 0x30

gUnknown_08614084: ; 8614084
	.incbin "base_emerald.gba", 0x614084, 0x8

gUnknown_0861408C: ; 861408C
	.incbin "base_emerald.gba", 0x61408c, 0x8

gUnknown_08614094: ; 8614094
	.incbin "base_emerald.gba", 0x614094, 0x10

gUnknown_086140A4: ; 86140A4
	.incbin "base_emerald.gba", 0x6140a4, 0xc0

gUnknown_08614164: ; 8614164
	.incbin "base_emerald.gba", 0x614164, 0x10

gUnknown_08614174: ; 8614174
	.incbin "base_emerald.gba", 0x614174, 0x38

gUnknown_086141AC: ; 86141AC
	.incbin "base_emerald.gba", 0x6141ac, 0x50

gUnknown_086141FC: ; 86141FC
	.incbin "base_emerald.gba", 0x6141fc, 0x48

gUnknown_08614244: ; 8614244
	.incbin "base_emerald.gba", 0x614244, 0x18

gUnknown_0861425C: ; 861425C
	.incbin "base_emerald.gba", 0x61425c, 0x4

gUnknown_08614260: ; 8614260
	.incbin "base_emerald.gba", 0x614260, 0x4

gUnknown_08614264: ; 8614264
	.incbin "base_emerald.gba", 0x614264, 0x4

gUnknown_08614268: ; 8614268
	.incbin "base_emerald.gba", 0x614268, 0x4

gUnknown_0861426C: ; 861426C
	.incbin "base_emerald.gba", 0x61426c, 0x4

gUnknown_08614270: ; 8614270
	.incbin "base_emerald.gba", 0x614270, 0x4

gUnknown_08614274: ; 8614274
	.incbin "base_emerald.gba", 0x614274, 0x4

gUnknown_08614278: ; 8614278
	.incbin "base_emerald.gba", 0x614278, 0x18

gUnknown_08614290: ; 8614290
	.incbin "base_emerald.gba", 0x614290, 0x18

gUnknown_086142A8: ; 86142A8
	.incbin "base_emerald.gba", 0x6142a8, 0x20

gUnknown_086142C8: ; 86142C8
	.incbin "base_emerald.gba", 0x6142c8, 0x70

gUnknown_08614338: ; 8614338
	.incbin "base_emerald.gba", 0x614338, 0x40

gUnknown_08614378: ; 8614378
	.incbin "base_emerald.gba", 0x614378, 0x44

gUnknown_086143BC: ; 86143BC
	.incbin "base_emerald.gba", 0x6143bc, 0x4e

gUnknown_0861440A: ; 861440A
	.incbin "base_emerald.gba", 0x61440a, 0x4

gUnknown_0861440E: ; 861440E
	.incbin "base_emerald.gba", 0x61440e, 0x2

gUnknown_08614410: ; 8614410
	.incbin "base_emerald.gba", 0x614410, 0xbe4

gUnknown_08614FF4: ; 8614FF4
	.incbin "base_emerald.gba", 0x614ff4, 0x18

gUnknown_0861500C: ; 861500C
	.incbin "base_emerald.gba", 0x61500c, 0x3c

gUnknown_08615048: ; 8615048
	.incbin "base_emerald.gba", 0x615048, 0x670

gUnknown_086156B8: ; 86156B8
	.incbin "base_emerald.gba", 0x6156b8, 0x2c

gUnknown_086156E4: ; 86156E4
	.incbin "base_emerald.gba", 0x6156e4, 0x20

gUnknown_08615704: ; 8615704
	.incbin "base_emerald.gba", 0x615704, 0xc0

gUnknown_086157C4: ; 86157C4
	.incbin "base_emerald.gba", 0x6157c4, 0x1c

gUnknown_086157E0: ; 86157E0
	.incbin "base_emerald.gba", 0x6157e0, 0x1c

gUnknown_086157FC: ; 86157FC
	.incbin "base_emerald.gba", 0x6157fc, 0x14

gUnknown_08615810: ; 8615810
	.incbin "base_emerald.gba", 0x615810, 0x40

gUnknown_08615850: ; 8615850
	.incbin "base_emerald.gba", 0x615850, 0x40

gUnknown_08615890: ; 8615890
	.incbin "base_emerald.gba", 0x615890, 0x40

gUnknown_086158D0: ; 86158D0
	.incbin "base_emerald.gba", 0x6158d0, 0x38

gUnknown_08615908: ; 8615908
	.incbin "base_emerald.gba", 0x615908, 0x8

gUnknown_08615910: ; 8615910
	.incbin "base_emerald.gba", 0x615910, 0x8

gUnknown_08615918: ; 8615918
	.incbin "base_emerald.gba", 0x615918, 0x8

gUnknown_08615920: ; 8615920
	.incbin "base_emerald.gba", 0x615920, 0x8

gUnknown_08615928: ; 8615928
	.incbin "base_emerald.gba", 0x615928, 0x8

gUnknown_08615930: ; 8615930
	.incbin "base_emerald.gba", 0x615930, 0x8

gUnknown_08615938: ; 8615938
	.incbin "base_emerald.gba", 0x615938, 0x8

gUnknown_08615940: ; 8615940
	.incbin "base_emerald.gba", 0x615940, 0x8

gUnknown_08615948: ; 8615948
	.incbin "base_emerald.gba", 0x615948, 0x8

gUnknown_08615950: ; 8615950
	.incbin "base_emerald.gba", 0x615950, 0x8

gUnknown_08615958: ; 8615958
	.incbin "base_emerald.gba", 0x615958, 0x8

gUnknown_08615960: ; 8615960
	.incbin "base_emerald.gba", 0x615960, 0x8

gUnknown_08615968: ; 8615968
	.incbin "base_emerald.gba", 0x615968, 0x8

gUnknown_08615970: ; 8615970
	.incbin "base_emerald.gba", 0x615970, 0x18

gUnknown_08615988: ; 8615988
	.incbin "base_emerald.gba", 0x615988, 0x46

gUnknown_086159CE: ; 86159CE
	.incbin "base_emerald.gba", 0x6159ce, 0x46

gUnknown_08615A14: ; 8615A14
	.incbin "base_emerald.gba", 0x615a14, 0x36

gUnknown_08615A4A: ; 8615A4A
	.incbin "base_emerald.gba", 0x615a4a, 0x36

gUnknown_08615A80: ; 8615A80
	.incbin "base_emerald.gba", 0x615a80, 0x36

gUnknown_08615AB6: ; 8615AB6
	.incbin "base_emerald.gba", 0x615ab6, 0x2

gUnknown_08615AB8: ; 8615AB8
	.incbin "base_emerald.gba", 0x615ab8, 0x2

gUnknown_08615ABA: ; 8615ABA
	.incbin "base_emerald.gba", 0x615aba, 0x3

gUnknown_08615ABD: ; 8615ABD
	.incbin "base_emerald.gba", 0x615abd, 0x3

gUnknown_08615AC0: ; 8615AC0
	.incbin "base_emerald.gba", 0x615ac0, 0x3

gUnknown_08615AC3: ; 8615AC3
	.incbin "base_emerald.gba", 0x615ac3, 0x2

gUnknown_08615AC5: ; 8615AC5
	.incbin "base_emerald.gba", 0x615ac5, 0x2

gUnknown_08615AC7: ; 8615AC7
	.incbin "base_emerald.gba", 0x615ac7, 0x2

gUnknown_08615AC9: ; 8615AC9
	.incbin "base_emerald.gba", 0x615ac9, 0x2

gUnknown_08615ACB: ; 8615ACB
	.incbin "base_emerald.gba", 0x615acb, 0x2

gUnknown_08615ACD: ; 8615ACD
	.incbin "base_emerald.gba", 0x615acd, 0x3

gUnknown_08615AD0: ; 8615AD0
	.incbin "base_emerald.gba", 0x615ad0, 0x3

gUnknown_08615AD3: ; 8615AD3
	.incbin "base_emerald.gba", 0x615ad3, 0x3

gUnknown_08615AD6: ; 8615AD6
	.incbin "base_emerald.gba", 0x615ad6, 0x3

gUnknown_08615AD9: ; 8615AD9
	.incbin "base_emerald.gba", 0x615ad9, 0x3

gUnknown_08615ADC: ; 8615ADC
	.incbin "base_emerald.gba", 0x615adc, 0x3

gUnknown_08615ADF: ; 8615ADF
	.incbin "base_emerald.gba", 0x615adf, 0x3

gUnknown_08615AE2: ; 8615AE2
	.incbin "base_emerald.gba", 0x615ae2, 0x3

gUnknown_08615AE5: ; 8615AE5
	.incbin "base_emerald.gba", 0x615ae5, 0x3

gUnknown_08615AE8: ; 8615AE8
	.incbin "base_emerald.gba", 0x615ae8, 0x3

gUnknown_08615AEB: ; 8615AEB
	.incbin "base_emerald.gba", 0x615aeb, 0x3

gUnknown_08615AEE: ; 8615AEE
	.incbin "base_emerald.gba", 0x615aee, 0x3

gUnknown_08615AF1: ; 8615AF1
	.incbin "base_emerald.gba", 0x615af1, 0x3

gUnknown_08615AF4: ; 8615AF4
	.incbin "base_emerald.gba", 0x615af4, 0x6c

gUnknown_08615B60: ; 8615B60
	.incbin "base_emerald.gba", 0x615b60, 0xa8

gUnknown_08615C08: ; 8615C08
	.incbin "base_emerald.gba", 0x615c08, 0x130

gUnknown_08615D38: ; 8615D38
	.incbin "base_emerald.gba", 0x615d38, 0x38

gUnknown_08615D70: ; 8615D70
	.incbin "base_emerald.gba", 0x615d70, 0xe

gUnknown_08615D7E: ; 8615D7E
	.incbin "base_emerald.gba", 0x615d7e, 0x1e

gUnknown_08615D9C: ; 8615D9C
	.incbin "base_emerald.gba", 0x615d9c, 0x70

gUnknown_08615E0C: ; 8615E0C
	.incbin "base_emerald.gba", 0x615e0c, 0xa4

gUnknown_08615EB0: ; 8615EB0
	.incbin "base_emerald.gba", 0x615eb0, 0x8

gUnknown_08615EB8: ; 8615EB8
	.incbin "base_emerald.gba", 0x615eb8, 0x8

gUnknown_08615EC0: ; 8615EC0
	.incbin "base_emerald.gba", 0x615ec0, 0x38

gUnknown_08615EF8: ; 8615EF8
	.incbin "base_emerald.gba", 0x615ef8, 0x8

gUnknown_08615F00: ; 8615F00
	.incbin "base_emerald.gba", 0x615f00, 0x8

gUnknown_08615F08: ; 8615F08
	.incbin "base_emerald.gba", 0x615f08, 0x68

gUnknown_08615F70: ; 8615F70
	.incbin "base_emerald.gba", 0x615f70, 0x8

gUnknown_08615F78: ; 8615F78
	.incbin "base_emerald.gba", 0x615f78, 0x80

gUnknown_08615FF8: ; 8615FF8
	.incbin "base_emerald.gba", 0x615ff8, 0x8

gUnknown_08616000: ; 8616000
	.incbin "base_emerald.gba", 0x616000, 0x8

gUnknown_08616008: ; 8616008
	.incbin "base_emerald.gba", 0x616008, 0x18

gUnknown_08616020: ; 8616020
	.incbin "base_emerald.gba", 0x616020, 0x20

gUnknown_08616040: ; 8616040
	.incbin "base_emerald.gba", 0x616040, 0x74

gUnknown_086160B4: ; 86160B4
	.incbin "base_emerald.gba", 0x6160b4, 0x20

gUnknown_086160D4: ; 86160D4
	.incbin "base_emerald.gba", 0x6160d4, 0x4

gUnknown_086160D8: ; 86160D8
	.incbin "base_emerald.gba", 0x6160d8, 0x1c

gUnknown_086160F4: ; 86160F4
	.incbin "base_emerald.gba", 0x6160f4, 0x4

gUnknown_086160F8: ; 86160F8
	.incbin "base_emerald.gba", 0x6160f8, 0x28

gUnknown_08616120: ; 8616120
	.incbin "base_emerald.gba", 0x616120, 0x4

gUnknown_08616124: ; 8616124
	.incbin "base_emerald.gba", 0x616124, 0x4

gFont6BrailleGlyphs: ; 8616128
	.incbin "base_emerald.gba", 0x616128, 0x1000

gUnknown_08617128: ; 8617128
	.incbin "base_emerald.gba", 0x617128, 0x48

gUnknown_08617170: ; 8617170
	.incbin "base_emerald.gba", 0x617170, 0x104

gUnknown_08617274: ; 8617274
	.incbin "base_emerald.gba", 0x617274, 0x920

gUnknown_08617B94: ; 8617B94
	.incbin "base_emerald.gba", 0x617b94, 0xb0

gUnknown_08617C44: ; 8617C44
	.incbin "base_emerald.gba", 0x617c44, 0x120

gUnknown_08617D64: ; 8617D64
	.incbin "base_emerald.gba", 0x617d64, 0x30

gUnknown_08617D94: ; 8617D94
	.incbin "base_emerald.gba", 0x617d94, 0x10

gUnknown_08617DA4: ; 8617DA4
	.incbin "base_emerald.gba", 0x617da4, 0x5c

gUnknown_08617E00: ; 8617E00
	.incbin "base_emerald.gba", 0x617e00, 0x18

gUnknown_08617E18: ; 8617E18
	.incbin "base_emerald.gba", 0x617e18, 0x1c

gUnknown_08617E34: ; 8617E34
	.incbin "base_emerald.gba", 0x617e34, 0x2c

gUnknown_08617E60: ; 8617E60
	.incbin "base_emerald.gba", 0x617e60, 0x18

gUnknown_08617E78: ; 8617E78
	.incbin "base_emerald.gba", 0x617e78, 0x15

gUnknown_08617E8D: ; 8617E8D
	.incbin "base_emerald.gba", 0x617e8d, 0xe

gUnknown_08617E9B: ; 8617E9B
	.incbin "base_emerald.gba", 0x617e9b, 0x26d

gUnknown_08618108: ; 8618108
	.incbin "base_emerald.gba", 0x618108, 0x8

gUnknown_08618110: ; 8618110
	.incbin "base_emerald.gba", 0x618110, 0x28

gUnknown_08618138: ; 8618138
	.incbin "base_emerald.gba", 0x618138, 0x20

gUnknown_08618158: ; 8618158
	.incbin "base_emerald.gba", 0x618158, 0x3

gUnknown_0861815B: ; 861815B
	.incbin "base_emerald.gba", 0x61815b, 0x5

gUnknown_08618160: ; 8618160
	.incbin "base_emerald.gba", 0x618160, 0x18

gUnknown_08618178: ; 8618178
	.incbin "base_emerald.gba", 0x618178, 0x49

; 86181C1
	.include "data/text/move_descriptions.s"

; 861CAAC
	.include "data/text/nature_names.s"

gUnknown_0861CBB4: ; 861CBB4
	.incbin "base_emerald.gba", 0x61cbb4, 0x38

gUnknown_0861CBEC: ; 861CBEC
	.incbin "base_emerald.gba", 0x61cbec, 0xc

gUnknown_0861CBF8: ; 861CBF8
	.incbin "base_emerald.gba", 0x61cbf8, 0xc

gUnknown_0861CC04: ; 861CC04
	.incbin "base_emerald.gba", 0x61cc04, 0xc

gUnknown_0861CC10: ; 861CC10
	.incbin "base_emerald.gba", 0x61cc10, 0xc

gUnknown_0861CC1C: ; 861CC1C
	.incbin "base_emerald.gba", 0x61cc1c, 0x8

gUnknown_0861CC24: ; 861CC24
	.incbin "base_emerald.gba", 0x61cc24, 0xa8

gUnknown_0861CCCC: ; 861CCCC
	.incbin "base_emerald.gba", 0x61cccc, 0x20

gUnknown_0861CCEC: ; 861CCEC
	.incbin "base_emerald.gba", 0x61ccec, 0x28

gUnknown_0861CD14: ; 861CD14
	.incbin "base_emerald.gba", 0x61cd14, 0x18

gUnknown_0861CD2C: ; 861CD2C
	.incbin "base_emerald.gba", 0x61cd2c, 0xa7

gUnknown_0861CDD3: ; 861CDD3
	.incbin "base_emerald.gba", 0x61cdd3, 0x81

gUnknown_0861CE54: ; 861CE54
	.incbin "base_emerald.gba", 0x61ce54, 0x10

gUnknown_0861CE64: ; 861CE64
	.incbin "base_emerald.gba", 0x61ce64, 0x10

gUnknown_0861CE74: ; 861CE74
	.incbin "base_emerald.gba", 0x61ce74, 0x7

gUnknown_0861CE7B: ; 861CE7B
	.incbin "base_emerald.gba", 0x61ce7b, 0x7

gUnknown_0861CE82: ; 861CE82
	.incbin "base_emerald.gba", 0x61ce82, 0xc

gUnknown_0861CE8E: ; 861CE8E
	.incbin "base_emerald.gba", 0x61ce8e, 0x9

gUnknown_0861CE97: ; 861CE97
	.incbin "base_emerald.gba", 0x61ce97, 0x125

gUnknown_0861CFBC: ; 861CFBC
	.incbin "base_emerald.gba", 0x61cfbc, 0x8

gUnknown_0861CFC4: ; 861CFC4
	.incbin "base_emerald.gba", 0x61cfc4, 0x18

gUnknown_0861CFDC: ; 861CFDC
	.incbin "base_emerald.gba", 0x61cfdc, 0x98

gUnknown_0861D074: ; 861D074
	.incbin "base_emerald.gba", 0x61d074, 0x8

gUnknown_0861D07C: ; 861D07C
	.incbin "base_emerald.gba", 0x61d07c, 0x8

gUnknown_0861D084: ; 861D084
	.incbin "base_emerald.gba", 0x61d084, 0x74

gUnknown_0861D0F8: ; 861D0F8
	.incbin "base_emerald.gba", 0x61d0f8, 0x8

gUnknown_0861D100: ; 861D100
	.incbin "base_emerald.gba", 0x61d100, 0x8

gUnknown_0861D108: ; 861D108
	.incbin "base_emerald.gba", 0x61d108, 0x18

gUnknown_0861D120: ; 861D120
	.incbin "base_emerald.gba", 0x61d120, 0x20

gUnknown_0861D140: ; 861D140
	.incbin "base_emerald.gba", 0x61d140, 0x60

gUnknown_0861D1A0: ; 861D1A0
	.incbin "base_emerald.gba", 0x61d1a0, 0xd54

gUnknown_0861DEF4: ; 861DEF4
	.incbin "base_emerald.gba", 0x61def4, 0x314

gUnknown_0861E208: ; 861E208
	.incbin "base_emerald.gba", 0x61e208, 0xd5c

gUnknown_0861EF64: ; 861EF64
	.incbin "base_emerald.gba", 0x61ef64, 0x350

gUnknown_0861F2B4: ; 861F2B4
	.incbin "base_emerald.gba", 0x61f2b4, 0xc

gUnknown_0861F2C0: ; 861F2C0
	.incbin "base_emerald.gba", 0x61f2c0, 0x18

gUnknown_0861F2D8: ; 861F2D8
	.incbin "base_emerald.gba", 0x61f2d8, 0x30

gUnknown_0861F308: ; 861F308
	.incbin "base_emerald.gba", 0x61f308, 0x4

gUnknown_0861F30C: ; 861F30C
	.incbin "base_emerald.gba", 0x61f30c, 0x2

gUnknown_0861F30E: ; 861F30E
	.incbin "base_emerald.gba", 0x61f30e, 0x2

gUnknown_0861F310: ; 861F310
	.incbin "base_emerald.gba", 0x61f310, 0x4

gUnknown_0861F314: ; 861F314
	.incbin "base_emerald.gba", 0x61f314, 0x8

gUnknown_0861F31C: ; 861F31C
	.incbin "base_emerald.gba", 0x61f31c, 0xc

gUnknown_0861F328: ; 861F328
	.incbin "base_emerald.gba", 0x61f328, 0x28

gUnknown_0861F350: ; 861F350
	.incbin "base_emerald.gba", 0x61f350, 0x20

gUnknown_0861F370: ; 861F370
	.incbin "base_emerald.gba", 0x61f370, 0x5c

gUnknown_0861F3CC: ; 861F3CC
	.incbin "base_emerald.gba", 0x61f3cc, 0x8

gUnknown_0861F3D4: ; 861F3D4
	.incbin "base_emerald.gba", 0x61f3d4, 0x18

gUnknown_0861F3EC: ; 861F3EC
	.incbin "base_emerald.gba", 0x61f3ec, 0x618

gUnknown_0861FA04: ; 861FA04
	.incbin "base_emerald.gba", 0x61fa04, 0x4

gUnknown_0861FA08: ; 861FA08
	.incbin "base_emerald.gba", 0x61fa08, 0x10

gUnknown_0861FA18: ; 861FA18
	.incbin "base_emerald.gba", 0x61fa18, 0x30

gUnknown_0861FA48: ; 861FA48
	.incbin "base_emerald.gba", 0x61fa48, 0x4

gUnknown_0861FA4C: ; 861FA4C
	.incbin "base_emerald.gba", 0x61fa4c, 0x8

gUnknown_0861FA54: ; 861FA54
	.incbin "base_emerald.gba", 0x61fa54, 0x10

gUnknown_0861FA64: ; 861FA64
	.incbin "base_emerald.gba", 0x61fa64, 0x8

gUnknown_0861FA6C: ; 861FA6C
	.incbin "base_emerald.gba", 0x61fa6c, 0x30

gUnknown_0861FA9C: ; 861FA9C
	.incbin "base_emerald.gba", 0x61fa9c, 0x68

gUnknown_0861FB04: ; 861FB04
	.incbin "base_emerald.gba", 0x61fb04, 0x28

gUnknown_0861FB2C: ; 861FB2C
	.incbin "base_emerald.gba", 0x61fb2c, 0x18

gUnknown_0861FB44: ; 861FB44
	.incbin "base_emerald.gba", 0x61fb44, 0xa0

gUnknown_0861FBE4: ; 861FBE4
	.incbin "base_emerald.gba", 0x61fbe4, 0x4

gUnknown_0861FBE8: ; 861FBE8
	.incbin "base_emerald.gba", 0x61fbe8, 0xc

gUnknown_0861FBF4: ; 861FBF4
	.incbin "base_emerald.gba", 0x61fbf4, 0x3

gUnknown_0861FBF7: ; 861FBF7
	.incbin "base_emerald.gba", 0x61fbf7, 0x5

gUnknown_0861FBFC: ; 861FBFC
	.incbin "base_emerald.gba", 0x61fbfc, 0x8

gUnknown_0861FC04: ; 861FC04
	.incbin "base_emerald.gba", 0x61fc04, 0x18

gUnknown_0861FC1C: ; 861FC1C
	.incbin "base_emerald.gba", 0x61fc1c, 0x20

gUnknown_0861FC3C: ; 861FC3C
	.incbin "base_emerald.gba", 0x61fc3c, 0x18

gUnknown_0861FC54: ; 861FC54
	.incbin "base_emerald.gba", 0x61fc54, 0x5

gUnknown_0861FC59: ; 861FC59
	.incbin "base_emerald.gba", 0x61fc59, 0x1f

gUnknown_0861FC78: ; 861FC78
	.incbin "base_emerald.gba", 0x61fc78, 0x2

gUnknown_0861FC7A: ; 861FC7A
	.incbin "base_emerald.gba", 0x61fc7a, 0xc

gUnknown_0861FC86: ; 861FC86
	.incbin "base_emerald.gba", 0x61fc86, 0x12

gUnknown_0861FC98: ; 861FC98
	.incbin "base_emerald.gba", 0x61fc98, 0x14

gUnknown_0861FCAC: ; 861FCAC
	.incbin "base_emerald.gba", 0x61fcac, 0xa0

gUnknown_0861FD4C: ; 861FD4C
	.incbin "base_emerald.gba", 0x61fd4c, 0x20

gUnknown_0861FD6C: ; 861FD6C
	.incbin "base_emerald.gba", 0x61fd6c, 0x288

gUnknown_0861FFF4: ; 861FFF4
	.incbin "base_emerald.gba", 0x61fff4, 0x1a0

gUnknown_08620194: ; 8620194
	.incbin "base_emerald.gba", 0x620194, 0xc

gUnknown_086201A0: ; 86201A0
	.incbin "base_emerald.gba", 0x6201a0, 0x24

gUnknown_086201C4: ; 86201C4
	.incbin "base_emerald.gba", 0x6201c4, 0x10

gUnknown_086201D4: ; 86201D4
	.incbin "base_emerald.gba", 0x6201d4, 0x6c

gUnknown_08620240: ; 8620240
	.incbin "base_emerald.gba", 0x620240, 0x4

gUnknown_08620244: ; 8620244
	.incbin "base_emerald.gba", 0x620244, 0x88

gUnknown_086202CC: ; 86202CC
	.incbin "base_emerald.gba", 0x6202cc, 0x8

gUnknown_086202D4: ; 86202D4
	.incbin "base_emerald.gba", 0x6202d4, 0x38

gUnknown_0862030C: ; 862030C
	.incbin "base_emerald.gba", 0x62030c, 0x3

gUnknown_0862030F: ; 862030F
	.incbin "base_emerald.gba", 0x62030f, 0x3d

gUnknown_0862034C: ; 862034C
	.incbin "base_emerald.gba", 0x62034c, 0x20

gUnknown_0862036C: ; 862036C
	.incbin "base_emerald.gba", 0x62036c, 0x18

gUnknown_08620384: ; 8620384
	.incbin "base_emerald.gba", 0x620384, 0x1ca4

gUnknown_08622028: ; 8622028
	.incbin "base_emerald.gba", 0x622028, 0x4e0

gUnknown_08622508: ; 8622508
	.incbin "base_emerald.gba", 0x622508, 0x2

gUnknown_0862250A: ; 862250A
	.incbin "base_emerald.gba", 0x62250a, 0x6

gUnknown_08622510: ; 8622510
	.incbin "base_emerald.gba", 0x622510, 0x20

gUnknown_08622530: ; 8622530
	.incbin "base_emerald.gba", 0x622530, 0xa4

gUnknown_086225D4: ; 86225D4
	.incbin "base_emerald.gba", 0x6225d4, 0x10c

gUnknown_086226E0: ; 86226E0
	.incbin "base_emerald.gba", 0x6226e0, 0x20

gUnknown_08622700: ; 8622700
	.incbin "base_emerald.gba", 0x622700, 0x20

gUnknown_08622720: ; 8622720
	.incbin "base_emerald.gba", 0x622720, 0x40

gUnknown_08622760: ; 8622760
	.incbin "base_emerald.gba", 0x622760, 0x2c

gUnknown_0862278C: ; 862278C
	.incbin "base_emerald.gba", 0x62278c, 0x8

gUnknown_08622794: ; 8622794
	.incbin "base_emerald.gba", 0x622794, 0x4

gUnknown_08622798: ; 8622798
	.incbin "base_emerald.gba", 0x622798, 0x40

gUnknown_086227D8: ; 86227D8
	.incbin "base_emerald.gba", 0x6227d8, 0x8

gUnknown_086227E0: ; 86227E0
	.incbin "base_emerald.gba", 0x6227e0, 0x8

gUnknown_086227E8: ; 86227E8
	.incbin "base_emerald.gba", 0x6227e8, 0xc

gUnknown_086227F4: ; 86227F4
	.incbin "base_emerald.gba", 0x6227f4, 0x14

gUnknown_08622808: ; 8622808
	.incbin "base_emerald.gba", 0x622808, 0x8

gUnknown_08622810: ; 8622810
	.incbin "base_emerald.gba", 0x622810, 0x8

gUnknown_08622818: ; 8622818
	.incbin "base_emerald.gba", 0x622818, 0x18

gUnknown_08622830: ; 8622830
	.incbin "base_emerald.gba", 0x622830, 0x20

gUnknown_08622850: ; 8622850
	.incbin "base_emerald.gba", 0x622850, 0x18

gUnknown_08622868: ; 8622868
	.incbin "base_emerald.gba", 0x622868, 0x20

gUnknown_08622888: ; 8622888
	.incbin "base_emerald.gba", 0x622888, 0x850

gUnknown_086230D8: ; 86230D8
	.incbin "base_emerald.gba", 0x6230d8, 0xc

gUnknown_086230E4: ; 86230E4
	.incbin "base_emerald.gba", 0x6230e4, 0x14

gUnknown_086230F8: ; 86230F8
	.incbin "base_emerald.gba", 0x6230f8, 0x8

gUnknown_08623100: ; 8623100
	.incbin "base_emerald.gba", 0x623100, 0x10

gUnknown_08623110: ; 8623110
	.incbin "base_emerald.gba", 0x623110, 0x8

gUnknown_08623118: ; 8623118
	.incbin "base_emerald.gba", 0x623118, 0xb8

gUnknown_086231D0: ; 86231D0
	.incbin "base_emerald.gba", 0x6231d0, 0x18

gUnknown_086231E8: ; 86231E8
	.incbin "base_emerald.gba", 0x6231e8, 0x20

gUnknown_08623208: ; 8623208
	.incbin "base_emerald.gba", 0x623208, 0x20

gUnknown_08623228: ; 8623228
	.incbin "base_emerald.gba", 0x623228, 0x14

gUnknown_0862323C: ; 862323C
	.incbin "base_emerald.gba", 0x62323c, 0xfc

gUnknown_08623338: ; 8623338
	.incbin "base_emerald.gba", 0x623338, 0x20

gUnknown_08623358: ; 8623358
	.incbin "base_emerald.gba", 0x623358, 0xc

gUnknown_08623364: ; 8623364
	.incbin "base_emerald.gba", 0x623364, 0x8

gUnknown_0862336C: ; 862336C
	.incbin "base_emerald.gba", 0x62336c, 0x8

gUnknown_08623374: ; 8623374
	.incbin "base_emerald.gba", 0x623374, 0x8

gUnknown_0862337C: ; 862337C
	.incbin "base_emerald.gba", 0x62337c, 0x8

gUnknown_08623384: ; 8623384
	.incbin "base_emerald.gba", 0x623384, 0x1c

gUnknown_086233A0: ; 86233A0
	.incbin "base_emerald.gba", 0x6233a0, 0x14

gUnknown_086233B4: ; 86233B4
	.incbin "base_emerald.gba", 0x6233b4, 0x10

gUnknown_086233C4: ; 86233C4
	.incbin "base_emerald.gba", 0x6233c4, 0x20

gUnknown_086233E4: ; 86233E4
	.incbin "base_emerald.gba", 0x6233e4, 0xc8

gUnknown_086234AC: ; 86234AC
	.incbin "base_emerald.gba", 0x6234ac, 0xc4

gUnknown_08623570: ; 8623570
	.incbin "base_emerald.gba", 0x623570, 0x20

gUnknown_08623590: ; 8623590
	.incbin "base_emerald.gba", 0x623590, 0x4

gUnknown_08623594: ; 8623594
	.incbin "base_emerald.gba", 0x623594, 0x4

gUnknown_08623598: ; 8623598
	.incbin "base_emerald.gba", 0x623598, 0x1c

gUnknown_086235B4: ; 86235B4
	.incbin "base_emerald.gba", 0x6235b4, 0x8

gUnknown_086235BC: ; 86235BC
	.incbin "base_emerald.gba", 0x6235bc, 0xc

gUnknown_086235C8: ; 86235C8
	.incbin "base_emerald.gba", 0x6235c8, 0xc

gUnknown_086235D4: ; 86235D4
	.incbin "base_emerald.gba", 0x6235d4, 0x4

gUnknown_086235D8: ; 86235D8
	.incbin "base_emerald.gba", 0x6235d8, 0xc

gUnknown_086235E4: ; 86235E4
	.incbin "base_emerald.gba", 0x6235e4, 0x20

gUnknown_08623604: ; 8623604
	.incbin "base_emerald.gba", 0x623604, 0xc8

gUnknown_086236CC: ; 86236CC
	.incbin "base_emerald.gba", 0x6236cc, 0xc4

gUnknown_08623790: ; 8623790
	.incbin "base_emerald.gba", 0x623790, 0x20

gUnknown_086237B0: ; 86237B0
	.incbin "base_emerald.gba", 0x6237b0, 0x4

gUnknown_086237B4: ; 86237B4
	.incbin "base_emerald.gba", 0x6237b4, 0x4

gUnknown_086237B8: ; 86237B8
	.incbin "base_emerald.gba", 0x6237b8, 0x1c

gUnknown_086237D4: ; 86237D4
	.incbin "base_emerald.gba", 0x6237d4, 0x8

gUnknown_086237DC: ; 86237DC
	.incbin "base_emerald.gba", 0x6237dc, 0xc

gUnknown_086237E8: ; 86237E8
	.incbin "base_emerald.gba", 0x6237e8, 0xc

gUnknown_086237F4: ; 86237F4
	.incbin "base_emerald.gba", 0x6237f4, 0x4

gUnknown_086237F8: ; 86237F8
	.incbin "base_emerald.gba", 0x6237f8, 0x44

; 862383C
	.include "data/text/ribbon_descriptions.s"

; 8623A74
	.include "data/text/gift_ribbon_descriptions.s"

gUnknown_08623FF8: ; 8623FF8
	.incbin "base_emerald.gba", 0x623ff8, 0xa0

gUnknown_08624098: ; 8624098
	.incbin "base_emerald.gba", 0x624098, 0x20

gUnknown_086240B8: ; 86240B8
	.incbin "base_emerald.gba", 0x6240b8, 0xae0

gUnknown_08624B98: ; 8624B98
	.incbin "base_emerald.gba", 0x624b98, 0x8

gUnknown_08624BA0: ; 8624BA0
	.incbin "base_emerald.gba", 0x624ba0, 0x18

gUnknown_08624BB8: ; 8624BB8
	.incbin "base_emerald.gba", 0x624bb8, 0x8

gUnknown_08624BC0: ; 8624BC0
	.incbin "base_emerald.gba", 0x624bc0, 0x4

gUnknown_08624BC4: ; 8624BC4
	.incbin "base_emerald.gba", 0x624bc4, 0x8

gUnknown_08624BCC: ; 8624BCC
	.incbin "base_emerald.gba", 0x624bcc, 0xc

gUnknown_08624BD8: ; 8624BD8
	.incbin "base_emerald.gba", 0x624bd8, 0xc

gUnknown_08624BE4: ; 8624BE4
	.incbin "base_emerald.gba", 0x624be4, 0x4

gUnknown_08624BE8: ; 8624BE8
	.incbin "base_emerald.gba", 0x624be8, 0x10

gUnknown_08624BF8: ; 8624BF8
	.incbin "base_emerald.gba", 0x624bf8, 0x80

gUnknown_08624C78: ; 8624C78
	.incbin "base_emerald.gba", 0x624c78, 0x8

gUnknown_08624C80: ; 8624C80
	.incbin "base_emerald.gba", 0x624c80, 0x84

gUnknown_08624D04: ; 8624D04
	.incbin "base_emerald.gba", 0x624d04, 0x5a4

gUnknown_086252A8: ; 86252A8
	.incbin "base_emerald.gba", 0x6252a8, 0x54

gUnknown_086252FC: ; 86252FC
	.incbin "base_emerald.gba", 0x6252fc, 0x14

gUnknown_08625310: ; 8625310
	.incbin "base_emerald.gba", 0x625310, 0x14

gUnknown_08625324: ; 8625324
	.incbin "base_emerald.gba", 0x625324, 0x14

gUnknown_08625338: ; 8625338
	.incbin "base_emerald.gba", 0x625338, 0x14

gUnknown_0862534C: ; 862534C
	.incbin "base_emerald.gba", 0x62534c, 0x14

gUnknown_08625360: ; 8625360
	.incbin "base_emerald.gba", 0x625360, 0x14

gUnknown_08625374: ; 8625374
	.incbin "base_emerald.gba", 0x625374, 0x14

gUnknown_08625388: ; 8625388
	.incbin "base_emerald.gba", 0x625388, 0x60

gUnknown_086253E8: ; 86253E8
	.incbin "base_emerald.gba", 0x6253e8, 0x18

gUnknown_08625400: ; 8625400
	.incbin "base_emerald.gba", 0x625400, 0x3

gUnknown_08625403: ; 8625403
	.incbin "base_emerald.gba", 0x625403, 0x1

gUnknown_08625404: ; 8625404
	.incbin "base_emerald.gba", 0x625404, 0xc

gUnknown_08625410: ; 8625410
	.incbin "base_emerald.gba", 0x625410, 0x100

gUnknown_08625510: ; 8625510
	.incbin "base_emerald.gba", 0x625510, 0x30

gUnknown_08625540: ; 8625540
	.incbin "base_emerald.gba", 0x625540, 0x8

gUnknown_08625548: ; 8625548
	.incbin "base_emerald.gba", 0x625548, 0x500

gUnknown_08625A48: ; 8625A48
	.incbin "base_emerald.gba", 0x625a48, 0x8

gUnknown_08625A50: ; 8625A50
	.incbin "base_emerald.gba", 0x625a50, 0x18

gUnknown_08625A68: ; 8625A68
	.incbin "base_emerald.gba", 0x625a68, 0x8

gUnknown_08625A70: ; 8625A70
	.incbin "base_emerald.gba", 0x625a70, 0x20

gUnknown_08625A90: ; 8625A90
	.incbin "base_emerald.gba", 0x625a90, 0x18

gUnknown_08625AA8: ; 8625AA8
	.incbin "base_emerald.gba", 0x625aa8, 0x18

gUnknown_08625AC0: ; 8625AC0
	.incbin "base_emerald.gba", 0x625ac0, 0x8

gUnknown_08625AC8: ; 8625AC8
	.incbin "base_emerald.gba", 0x625ac8, 0x4c

gUnknown_08625B14: ; 8625B14
	.incbin "base_emerald.gba", 0x625b14, 0x18

gUnknown_08625B2C: ; 8625B2C
	.incbin "base_emerald.gba", 0x625b2c, 0x28

gUnknown_08625B54: ; 8625B54
	.incbin "base_emerald.gba", 0x625b54, 0x18

gUnknown_08625B6C: ; 8625B6C
	.incbin "base_emerald.gba", 0x625b6c, 0x520

gUnknown_0862608C: ; 862608C
	.incbin "base_emerald.gba", 0x62608c, 0x2

gUnknown_0862608E: ; 862608E
	.incbin "base_emerald.gba", 0x62608e, 0x4326

gUnknown_0862A3B4: ; 862A3B4
	.incbin "base_emerald.gba", 0x62a3b4, 0x218

gUnknown_0862A5CC: ; 862A5CC
	.incbin "base_emerald.gba", 0x62a5cc, 0x8

gUnknown_0862A5D4: ; 862A5D4
	.incbin "base_emerald.gba", 0x62a5d4, 0x20

gUnknown_0862A5F4: ; 862A5F4
	.incbin "base_emerald.gba", 0x62a5f4, 0x4

gUnknown_0862A5F8: ; 862A5F8
	.incbin "base_emerald.gba", 0x62a5f8, 0x20

gUnknown_0862A618: ; 862A618
	.incbin "base_emerald.gba", 0x62a618, 0x48

gUnknown_0862A660: ; 862A660
	.incbin "base_emerald.gba", 0x62a660, 0x10

gUnknown_0862A670: ; 862A670
	.incbin "base_emerald.gba", 0x62a670, 0x18

gUnknown_0862A688: ; 862A688
	.incbin "base_emerald.gba", 0x62a688, 0x10

gUnknown_0862A698: ; 862A698
	.incbin "base_emerald.gba", 0x62a698, 0x8

gUnknown_0862A6A0: ; 862A6A0
	.incbin "base_emerald.gba", 0x62a6a0, 0x8c

gUnknown_0862A72C: ; 862A72C
	.incbin "base_emerald.gba", 0x62a72c, 0x24

gUnknown_0862A750: ; 862A750
	.incbin "base_emerald.gba", 0x62a750, 0x24

gUnknown_0862A774: ; 862A774
	.incbin "base_emerald.gba", 0x62a774, 0xa8

gUnknown_0862A81C: ; 862A81C
	.incbin "base_emerald.gba", 0x62a81c, 0x30

gUnknown_0862A84C: ; 862A84C
	.incbin "base_emerald.gba", 0x62a84c, 0x18

gUnknown_0862A864: ; 862A864
	.incbin "base_emerald.gba", 0x62a864, 0x18

gUnknown_0862A87C: ; 862A87C
	.incbin "base_emerald.gba", 0x62a87c, 0xc

gUnknown_0862A888: ; 862A888
	.incbin "base_emerald.gba", 0x62a888, 0x3c

gUnknown_0862A8C4: ; 862A8C4
	.incbin "base_emerald.gba", 0x62a8c4, 0x8

gUnknown_0862A8CC: ; 862A8CC
	.incbin "base_emerald.gba", 0x62a8cc, 0x8

gUnknown_0862A8D4: ; 862A8D4
	.incbin "base_emerald.gba", 0x62a8d4, 0x24

gUnknown_0862A8F8: ; 862A8F8
	.incbin "base_emerald.gba", 0x62a8f8, 0x8

gUnknown_0862A900: ; 862A900
	.incbin "base_emerald.gba", 0x62a900, 0x24

gUnknown_0862A924: ; 862A924
	.incbin "base_emerald.gba", 0x62a924, 0x8

gUnknown_0862A92C: ; 862A92C
	.incbin "base_emerald.gba", 0x62a92c, 0xa8

gUnknown_0862A9D4: ; 862A9D4
	.incbin "base_emerald.gba", 0x62a9d4, 0x8

gUnknown_0862A9DC: ; 862A9DC
	.incbin "base_emerald.gba", 0x62a9dc, 0x8

gUnknown_0862A9E4: ; 862A9E4
	.incbin "base_emerald.gba", 0x62a9e4, 0x30

gUnknown_0862AA14: ; 862AA14
	.incbin "base_emerald.gba", 0x62aa14, 0x8

gUnknown_0862AA1C: ; 862AA1C
	.incbin "base_emerald.gba", 0x62aa1c, 0x18

gUnknown_0862AA34: ; 862AA34
	.incbin "base_emerald.gba", 0x62aa34, 0x8

gUnknown_0862AA3C: ; 862AA3C
	.incbin "base_emerald.gba", 0x62aa3c, 0x18

gUnknown_0862AA54: ; 862AA54
	.incbin "base_emerald.gba", 0x62aa54, 0x3c

gUnknown_0862AA90: ; 862AA90
	.incbin "base_emerald.gba", 0x62aa90, 0x8

gUnknown_0862AA98: ; 862AA98
	.incbin "base_emerald.gba", 0x62aa98, 0x8

gUnknown_0862AAA0: ; 862AAA0
	.incbin "base_emerald.gba", 0x62aaa0, 0x18

gUnknown_0862AAB8: ; 862AAB8
	.incbin "base_emerald.gba", 0x62aab8, 0x14

gUnknown_0862AACC: ; 862AACC
	.incbin "base_emerald.gba", 0x62aacc, 0x30

gUnknown_0862AAFC: ; 862AAFC
	.incbin "base_emerald.gba", 0x62aafc, 0x8

gUnknown_0862AB04: ; 862AB04
	.incbin "base_emerald.gba", 0x62ab04, 0x8

gUnknown_0862AB0C: ; 862AB0C
	.incbin "base_emerald.gba", 0x62ab0c, 0x8

gUnknown_0862AB14: ; 862AB14
	.incbin "base_emerald.gba", 0x62ab14, 0x18

gUnknown_0862AB2C: ; 862AB2C
	.incbin "base_emerald.gba", 0x62ab2c, 0x18

gUnknown_0862AB44: ; 862AB44
	.incbin "base_emerald.gba", 0x62ab44, 0xe4

gUnknown_0862AC28: ; 862AC28
	.incbin "base_emerald.gba", 0x62ac28, 0x8

gUnknown_0862AC30: ; 862AC30
	.incbin "base_emerald.gba", 0x62ac30, 0x8

gUnknown_0862AC38: ; 862AC38
	.incbin "base_emerald.gba", 0x62ac38, 0x8

gUnknown_0862AC40: ; 862AC40
	.incbin "base_emerald.gba", 0x62ac40, 0x8

gUnknown_0862AC48: ; 862AC48
	.incbin "base_emerald.gba", 0x62ac48, 0x8

gUnknown_0862AC50: ; 862AC50
	.incbin "base_emerald.gba", 0x62ac50, 0x8

gUnknown_0862AC58: ; 862AC58
	.incbin "base_emerald.gba", 0x62ac58, 0x8

gUnknown_0862AC60: ; 862AC60
	.incbin "base_emerald.gba", 0x62ac60, 0x8

gUnknown_0862AC68: ; 862AC68
	.incbin "base_emerald.gba", 0x62ac68, 0x8

gUnknown_0862AC70: ; 862AC70
	.incbin "base_emerald.gba", 0x62ac70, 0x8

gUnknown_0862AC78: ; 862AC78
	.incbin "base_emerald.gba", 0x62ac78, 0x18

gUnknown_0862AC90: ; 862AC90
	.incbin "base_emerald.gba", 0x62ac90, 0x18

gUnknown_0862ACA8: ; 862ACA8
	.incbin "base_emerald.gba", 0x62aca8, 0x18

gUnknown_0862ACC0: ; 862ACC0
	.incbin "base_emerald.gba", 0x62acc0, 0x18

gUnknown_0862ACD8: ; 862ACD8
	.incbin "base_emerald.gba", 0x62acd8, 0x18

gUnknown_0862ACF0: ; 862ACF0
	.incbin "base_emerald.gba", 0x62acf0, 0x18

gUnknown_0862AD08: ; 862AD08
	.incbin "base_emerald.gba", 0x62ad08, 0xc

gUnknown_0862AD14: ; 862AD14
	.incbin "base_emerald.gba", 0x62ad14, 0x20

gUnknown_0862AD34: ; 862AD34
	.incbin "base_emerald.gba", 0x62ad34, 0x10

gUnknown_0862AD44: ; 862AD44
	.incbin "base_emerald.gba", 0x62ad44, 0x10

gUnknown_0862AD54: ; 862AD54
	.incbin "base_emerald.gba", 0x62ad54, 0x1dc

gUnknown_0862AF30: ; 862AF30
	.incbin "base_emerald.gba", 0x62af30, 0x60c

gUnknown_0862B53C: ; 862B53C
	.incbin "base_emerald.gba", 0x62b53c, 0x1e8

gUnknown_0862B724: ; 862B724
	.incbin "base_emerald.gba", 0x62b724, 0x8

gUnknown_0862B72C: ; 862B72C
	.incbin "base_emerald.gba", 0x62b72c, 0x2c

gUnknown_0862B758: ; 862B758
	.incbin "base_emerald.gba", 0x62b758, 0x18

gUnknown_0862B770: ; 862B770
	.incbin "base_emerald.gba", 0x62b770, 0x14

gUnknown_0862B784: ; 862B784
	.incbin "base_emerald.gba", 0x62b784, 0x14

gUnknown_0862B798: ; 862B798
	.incbin "base_emerald.gba", 0x62b798, 0x14

gUnknown_0862B7AC: ; 862B7AC
	.incbin "base_emerald.gba", 0x62b7ac, 0x14

gUnknown_0862B7C0: ; 862B7C0
	.incbin "base_emerald.gba", 0x62b7c0, 0x14

gUnknown_0862B7D4: ; 862B7D4
	.incbin "base_emerald.gba", 0x62b7d4, 0x14

gUnknown_0862B7E8: ; 862B7E8
	.incbin "base_emerald.gba", 0x62b7e8, 0x14

gUnknown_0862B7FC: ; 862B7FC
	.incbin "base_emerald.gba", 0x62b7fc, 0x2e8

gFont8LatinGlyphs: ; 862BAE4
	.incbin "base_emerald.gba", 0x62bae4, 0x8000

gFont8LatinGlyphWidths: ; 8633AE4
	.incbin "base_emerald.gba", 0x633ae4, 0x200

gFont0LatinGlyphs: ; 8633CE4
	.incbin "base_emerald.gba", 0x633ce4, 0x8000

gFont0LatinGlyphWidths: ; 863BCE4
	.incbin "base_emerald.gba", 0x63bce4, 0x200

gFont7LatinGlyphs: ; 863BEE4
	.incbin "base_emerald.gba", 0x63bee4, 0x8000

gFont7LatinGlyphWidths: ; 8643EE4
	.incbin "base_emerald.gba", 0x643ee4, 0x200

gFont2LatinGlyphs: ; 86440E4
	.incbin "base_emerald.gba", 0x6440e4, 0x8000

gFont2LatinGlyphWidths: ; 864C0E4
	.incbin "base_emerald.gba", 0x64c0e4, 0x200

gFont1LatinGlyphs: ; 864C2E4
	.incbin "base_emerald.gba", 0x64c2e4, 0x8000

gFont1LatinGlyphWidths: ; 86542E4
	.incbin "base_emerald.gba", 0x6542e4, 0x200

gFont0JapaneseGlyphs: ; 86544E4
	.incbin "base_emerald.gba", 0x6544e4, 0x4000

gFont1JapaneseGlyphs: ; 86584E4
	.incbin "base_emerald.gba", 0x6584e4, 0x4000

gUnusedFullwidthJapaneseFontGlyphs: ; 865C4E4
	.incbin "base_emerald.gba", 0x65c4e4, 0x8000

gUnusedFullwidthJapaneseFontGlyphWidths: ; 86644E4
	.incbin "base_emerald.gba", 0x6644e4, 0x200

gUnusedFullwidthJapaneseFont2Glyphs: ; 86646E4
	.incbin "base_emerald.gba", 0x6646e4, 0x8000

gUnusedFullwidthJapaneseFont2GlyphWidths: ; 866C6E4
	.incbin "base_emerald.gba", 0x66c6e4, 0x200

gFont2JapaneseGlyphs: ; 866C8E4
	.incbin "base_emerald.gba", 0x66c8e4, 0x8000
	
gFont2JapaneseGlyphWidths: ; 86748E4
	.incbin "base_emerald.gba", 0x6748e4, 0x200

gUnknown_08674AE4: ; 8674AE4
	.incbin "base_emerald.gba", 0x674ae4, 0x32

gUnknown_08674B16: ; 8674B16
	.incbin "base_emerald.gba", 0x674b16, 0x2c

gUnknown_08674B42: ; 8674B42
	.incbin "base_emerald.gba", 0x674b42, 0x28

gUnknown_08674B6A: ; 8674B6A
	.incbin "base_emerald.gba", 0x674b6a, 0x34

gUnknown_08674B9E: ; 8674B9E
	.incbin "base_emerald.gba", 0x674b9e, 0x36

gUnknown_08674BD4: ; 8674BD4
	.incbin "base_emerald.gba", 0x674bd4, 0x1c

gUnknown_08674BF0: ; 8674BF0
	.incbin "base_emerald.gba", 0x674bf0, 0x12

gUnknown_08674C02: ; 8674C02
	.incbin "base_emerald.gba", 0x674c02, 0x2f

gUnknown_08674C31: ; 8674C31
	.incbin "base_emerald.gba", 0x674c31, 0x55

gUnknown_08674C86: ; 8674C86
	.incbin "base_emerald.gba", 0x674c86, 0xd5a

gUnknown_086759E0: ; 86759E0
	.incbin "base_emerald.gba", 0x6759e0, 0x90

gUnknown_08675A70: ; 8675A70
	.incbin "base_emerald.gba", 0x675a70, 0x10

gUnknown_08675A80: ; 8675A80
	.incbin "base_emerald.gba", 0x675a80, 0xb4

gUnknown_08675B34: ; 8675B34
	.incbin "base_emerald.gba", 0x675b34, 0x30

gUnknown_08675B64: ; 8675B64
	.incbin "base_emerald.gba", 0x675b64, 0x18

gUnknown_08675B7C: ; 8675B7C
	.incbin "base_emerald.gba", 0x675b7c, 0x84

gUnknown_08675C00: ; 8675C00
	.incbin "base_emerald.gba", 0x675c00, 0x18

gUnknown_08675C18: ; 8675C18
	.incbin "base_emerald.gba", 0x675c18, 0x3c

gUnknown_08675C54: ; 8675C54
	.incbin "base_emerald.gba", 0x675c54, 0x10

gUnknown_08675C64: ; 8675C64
	.incbin "base_emerald.gba", 0x675c64, 0x34

gUnknown_08675C98: ; 8675C98
	.incbin "base_emerald.gba", 0x675c98, 0x34

gUnknown_08675CCC: ; 8675CCC
	.incbin "base_emerald.gba", 0x675ccc, 0x28028

gUnknown_0869DCF4: ; 869DCF4
	.incbin "base_emerald.gba", 0x69dcf4, 0x600

gUnknown_0869E2F4: ; 869E2F4
	.incbin "base_emerald.gba", 0x69e2f4, 0x600

gUnknown_0869E8F4: ; 869E8F4
	.incbin "base_emerald.gba", 0x69e8f4, 0x600

gUnknown_0869EEF4: ; 869EEF4
	.incbin "base_emerald.gba", 0x69eef4, 0x30

gUnknown_0869EF24: ; 869EF24
	.incbin "base_emerald.gba", 0x69ef24, 0x600

gUnknown_0869F524: ; 869F524
	.incbin "base_emerald.gba", 0x69f524, 0x600

gUnknown_0869FB24: ; 869FB24
	.incbin "base_emerald.gba", 0x69fb24, 0x600

gUnknown_086A0124: ; 86A0124
	.incbin "base_emerald.gba", 0x6a0124, 0x1489c

gUnknown_086B49C0: ; 86B49C0
	.incbin "base_emerald.gba", 0x6b49c0, 0x30

gUnknown_086B49F0: ; 86B49F0
	.incbin "base_emerald.gba", 0x6b49f0, 0x2ee6e0

gUnknown_089A30D0: ; 89A30D0
	.incbin "base_emerald.gba", 0x9a30d0, 0x150

gUnknown_089A3220: ; 89A3220
	.incbin "base_emerald.gba", 0x9a3220, 0x2c

gUnknown_089A324C: ; 89A324C
	.incbin "base_emerald.gba", 0x9a324c, 0xc

gUnknown_089A3258: ; 89A3258
	.incbin "base_emerald.gba", 0x9a3258, 0x18

gUnknown_089A3270: ; 89A3270
	.incbin "base_emerald.gba", 0x9a3270, 0x100

gUnknown_089A3370: ; 89A3370
	.incbin "base_emerald.gba", 0x9a3370, 0x100

gUnknown_089A3470: ; 89A3470
	.incbin "base_emerald.gba", 0x9a3470, 0x30e0

gUnknown_089A6550: ; 89A6550
	.incbin "base_emerald.gba", 0x9a6550, 0xc0

gUnknown_089A6610: ; 89A6610
	.incbin "base_emerald.gba", 0x9a6610, 0x3b34

gUnknown_089AA144: ; 89AA144
	.incbin "base_emerald.gba", 0x9aa144, 0x255ebc

gUnknown_08C00000: ; 8C00000
	.incbin "base_emerald.gba", 0xc00000, 0x4e0

gUnknown_08C004E0: ; 8C004E0
	.incbin "base_emerald.gba", 0xc004e0, 0x44

gUnknown_08C00524: ; 8C00524
	.incbin "base_emerald.gba", 0xc00524, 0x1ddc

gUnknown_08C02300: ; 8C02300
	.incbin "base_emerald.gba", 0xc02300, 0x70f0

gUnknown_08C093F0: ; 8C093F0
	.incbin "base_emerald.gba", 0xc093f0, 0x87ec

gUnknown_08C11BDC: ; 8C11BDC
	.incbin "base_emerald.gba", 0xc11bdc, 0x52b4

gUnknown_08C16E90: ; 8C16E90
	.incbin "base_emerald.gba", 0xc16e90, 0x118

gUnknown_08C16FA8: ; 8C16FA8
	.incbin "base_emerald.gba", 0xc16fa8, 0x1c8

gUnknown_08C17170: ; 8C17170
	.incbin "base_emerald.gba", 0xc17170, 0x810

gUnknown_08C17980: ; 8C17980
	.incbin "base_emerald.gba", 0xc17980, 0x130

gUnknown_08C17AB0: ; 8C17AB0
	.incbin "base_emerald.gba", 0xc17ab0, 0xa5c

gUnknown_08C1850C: ; 8C1850C
	.incbin "base_emerald.gba", 0xc1850c, 0x107c

gUnknown_08C19588: ; 8C19588
	.incbin "base_emerald.gba", 0xc19588, 0x964

gUnknown_08C19EEC: ; 8C19EEC
	.incbin "base_emerald.gba", 0xc19eec, 0x114

gUnknown_08C1A000: ; 8C1A000
	.incbin "base_emerald.gba", 0xc1a000, 0x12c

gUnknown_08C1A12C: ; 8C1A12C
	.incbin "base_emerald.gba", 0xc1a12c, 0x188

gUnknown_08C1A2B4: ; 8C1A2B4
	.incbin "base_emerald.gba", 0xc1a2b4, 0x2404

gUnknown_08C1C6B8: ; 8C1C6B8
	.incbin "base_emerald.gba", 0xc1c6b8, 0x9f4

gUnknown_08C1D0AC: ; 8C1D0AC
	.incbin "base_emerald.gba", 0xc1d0ac, 0x13c

gUnknown_08C1D1E8: ; 8C1D1E8
	.incbin "base_emerald.gba", 0xc1d1e8, 0x28

gUnknown_08C1D210: ; 8C1D210
	.incbin "base_emerald.gba", 0xc1d210, 0x3458

gUnknown_08C20668: ; 8C20668
	.incbin "base_emerald.gba", 0xc20668, 0x1c

gUnknown_08C20684: ; 8C20684
	.incbin "base_emerald.gba", 0xc20684, 0x1f8c

gUnknown_08C22610: ; 8C22610
	.incbin "base_emerald.gba", 0xc22610, 0xcd0

gUnknown_08C232E0: ; 8C232E0
	.incbin "base_emerald.gba", 0xc232e0, 0xa70

gUnknown_08C23D50: ; 8C23D50
	.incbin "base_emerald.gba", 0xc23d50, 0x28

gUnknown_08C23D78: ; 8C23D78
	.incbin "base_emerald.gba", 0xc23d78, 0xc58

gUnknown_08C249D0: ; 8C249D0
	.incbin "base_emerald.gba", 0xc249d0, 0x28

gUnknown_08C249F8: ; 8C249F8
	.incbin "base_emerald.gba", 0xc249f8, 0x5c3c

gUnknown_08C2A634: ; 8C2A634
	.incbin "base_emerald.gba", 0xc2a634, 0xa0

gUnknown_08C2A6D4: ; 8C2A6D4
	.incbin "base_emerald.gba", 0xc2a6d4, 0x18

gUnknown_08C2A6EC: ; 8C2A6EC
	.incbin "base_emerald.gba", 0xc2a6ec, 0x27d0

gUnknown_08C2CEBC: ; 8C2CEBC
	.incbin "base_emerald.gba", 0xc2cebc, 0x24

gUnknown_08C2CEE0: ; 8C2CEE0
	.incbin "base_emerald.gba", 0xc2cee0, 0x240

gUnknown_08C2D120: ; 8C2D120
	.incbin "base_emerald.gba", 0xc2d120, 0x600

gUnknown_08C2D720: ; 8C2D720
	.incbin "base_emerald.gba", 0xc2d720, 0x210

gUnknown_08C2D930: ; 8C2D930
	.incbin "base_emerald.gba", 0xc2d930, 0x11c

gUnknown_08C2DA4C: ; 8C2DA4C
	.incbin "base_emerald.gba", 0xc2da4c, 0x11c

gUnknown_08C2DB68: ; 8C2DB68
	.incbin "base_emerald.gba", 0xc2db68, 0x20

gUnknown_08C2DB88: ; 8C2DB88
	.incbin "base_emerald.gba", 0xc2db88, 0x20

gUnknown_08C2DBA8: ; 8C2DBA8
	.incbin "base_emerald.gba", 0xc2dba8, 0x20

gUnknown_08C2DBC8: ; 8C2DBC8
	.incbin "base_emerald.gba", 0xc2dbc8, 0x20

gUnknown_08C2DBE8: ; 8C2DBE8
	.incbin "base_emerald.gba", 0xc2dbe8, 0x20

gUnknown_08C2DC08: ; 8C2DC08
	.incbin "base_emerald.gba", 0xc2dc08, 0x20

gUnknown_08C2DC28: ; 8C2DC28
	.incbin "base_emerald.gba", 0xc2dc28, 0x20

gUnknown_08C2DC48: ; 8C2DC48
	.incbin "base_emerald.gba", 0xc2dc48, 0x20

gUnknown_08C2DC68: ; 8C2DC68
	.incbin "base_emerald.gba", 0xc2dc68, 0x13c

gUnknown_08C2DDA4: ; 8C2DDA4
	.incbin "base_emerald.gba", 0xc2dda4, 0x20

gUnknown_08C2DDC4: ; 8C2DDC4
	.incbin "base_emerald.gba", 0xc2ddc4, 0xc8c

gUnknown_08C2EA50: ; 8C2EA50
	.incbin "base_emerald.gba", 0xc2ea50, 0x4c

gUnknown_08C2EA9C: ; 8C2EA9C
	.incbin "base_emerald.gba", 0xc2ea9c, 0x11564

gUnknown_08C40000: ; 8C40000
	.incbin "base_emerald.gba", 0xc40000, 0x10000

gUnknown_08C50000: ; 8C50000
	.incbin "base_emerald.gba", 0xc50000, 0x1278f0

gUnknown_08D778F0: ; 8D778F0
	.incbin "base_emerald.gba", 0xd778f0, 0xe8

gUnknown_08D779D8: ; 8D779D8
	.incbin "base_emerald.gba", 0xd779d8, 0x10c

gUnknown_08D77AE4: ; 8D77AE4
	.incbin "base_emerald.gba", 0xd77ae4, 0x28

gUnknown_08D77B0C: ; 8D77B0C
	.incbin "base_emerald.gba", 0xd77b0c, 0x25fc

gUnknown_08D7A108: ; 8D7A108
	.incbin "base_emerald.gba", 0xd7a108, 0x618

gUnknown_08D7A720: ; 8D7A720
	.incbin "base_emerald.gba", 0xd7a720, 0x13f4

gUnknown_08D7BB14: ; 8D7BB14
	.incbin "base_emerald.gba", 0xd7bb14, 0x640

gUnknown_08D7C154: ; 8D7C154
	.incbin "base_emerald.gba", 0xd7c154, 0x2ec

gUnknown_08D7C440: ; 8D7C440
	.incbin "base_emerald.gba", 0xd7c440, 0x5ac

gUnknown_08D7C9EC: ; 8D7C9EC
	.incbin "base_emerald.gba", 0xd7c9ec, 0x3c

gUnknown_08D7CA28: ; 8D7CA28
	.incbin "base_emerald.gba", 0xd7ca28, 0x2b0

gUnknown_08D7CCD8: ; 8D7CCD8
	.incbin "base_emerald.gba", 0xd7ccd8, 0x608

gUnknown_08D7D2E0: ; 8D7D2E0
	.incbin "base_emerald.gba", 0xd7d2e0, 0x2b0

gUnknown_08D7D590: ; 8D7D590
	.incbin "base_emerald.gba", 0xd7d590, 0x674

gUnknown_08D7DC04: ; 8D7DC04
	.incbin "base_emerald.gba", 0xd7dc04, 0x2f0

gUnknown_08D7DEF4: ; 8D7DEF4
	.incbin "base_emerald.gba", 0xd7def4, 0x3c

gUnknown_08D7DF30: ; 8D7DF30
	.incbin "base_emerald.gba", 0xd7df30, 0x58

gUnknown_08D7DF88: ; 8D7DF88
	.incbin "base_emerald.gba", 0xd7df88, 0x3c

gUnknown_08D7DFC4: ; 8D7DFC4
	.incbin "base_emerald.gba", 0xd7dfc4, 0x3c

gUnknown_08D7E000: ; 8D7E000
	.incbin "base_emerald.gba", 0xd7e000, 0x60

gUnknown_08D7E060: ; 8D7E060
	.incbin "base_emerald.gba", 0xd7e060, 0x6c

gUnknown_08D7E0CC: ; 8D7E0CC
	.incbin "base_emerald.gba", 0xd7e0cc, 0x50

gUnknown_08D7E11C: ; 8D7E11C
	.incbin "base_emerald.gba", 0xd7e11c, 0x48

gUnknown_08D7E164: ; 8D7E164
	.incbin "base_emerald.gba", 0xd7e164, 0x44

gUnknown_08D7E1A8: ; 8D7E1A8
	.incbin "base_emerald.gba", 0xd7e1a8, 0x50

gUnknown_08D7E1F8: ; 8D7E1F8
	.incbin "base_emerald.gba", 0xd7e1f8, 0x3c

gUnknown_08D7E234: ; 8D7E234
	.incbin "base_emerald.gba", 0xd7e234, 0x17c4

gUnknown_08D7F9F8: ; 8D7F9F8
	.incbin "base_emerald.gba", 0xd7f9f8, 0x4cc

gUnknown_08D7FEC4: ; 8D7FEC4
	.incbin "base_emerald.gba", 0xd7fec4, 0x174c

gUnknown_08D81610: ; 8D81610
	.incbin "base_emerald.gba", 0xd81610, 0x81c

gUnknown_08D81E2C: ; 8D81E2C
	.incbin "base_emerald.gba", 0xd81e2c, 0x2a8

gUnknown_08D820D4: ; 8D820D4
	.incbin "base_emerald.gba", 0xd820d4, 0x410

gUnknown_08D824E4: ; 8D824E4
	.incbin "base_emerald.gba", 0xd824e4, 0x124

gUnknown_08D82608: ; 8D82608
	.incbin "base_emerald.gba", 0xd82608, 0x668

gUnknown_08D82C70: ; 8D82C70
	.incbin "base_emerald.gba", 0xd82c70, 0x2a0

gUnknown_08D82F10: ; 8D82F10
	.incbin "base_emerald.gba", 0xd82f10, 0x5ec

gUnknown_08D834FC: ; 8D834FC
	.incbin "base_emerald.gba", 0xd834fc, 0x404

gUnknown_08D83900: ; 8D83900
	.incbin "base_emerald.gba", 0xd83900, 0x22c

gUnknown_08D83B2C: ; 8D83B2C
	.incbin "base_emerald.gba", 0xd83b2c, 0x110

gUnknown_08D83C3C: ; 8D83C3C
	.incbin "base_emerald.gba", 0xd83c3c, 0x114

gUnknown_08D83D50: ; 8D83D50
	.incbin "base_emerald.gba", 0xd83d50, 0xc20

gUnknown_08D84970: ; 8D84970
	.incbin "base_emerald.gba", 0xd84970, 0x590

gUnknown_08D84F00: ; 8D84F00
	.incbin "base_emerald.gba", 0xd84f00, 0x458

gUnknown_08D85358: ; 8D85358
	.incbin "base_emerald.gba", 0xd85358, 0xec

gUnknown_08D85444: ; 8D85444
	.incbin "base_emerald.gba", 0xd85444, 0x84

gUnknown_08D854C8: ; 8D854C8
	.incbin "base_emerald.gba", 0xd854c8, 0x120

gUnknown_08D855E8: ; 8D855E8
	.incbin "base_emerald.gba", 0xd855e8, 0x18

gUnknown_08D85600: ; 8D85600
	.incbin "base_emerald.gba", 0xd85600, 0x20

gUnknown_08D85620: ; 8D85620
	.incbin "base_emerald.gba", 0xd85620, 0xa8

gUnknown_08D856C8: ; 8D856C8
	.incbin "base_emerald.gba", 0xd856c8, 0xe0

gUnknown_08D857A8: ; 8D857A8
	.incbin "base_emerald.gba", 0xd857a8, 0x274

gUnknown_08D85A1C: ; 8D85A1C
	.incbin "base_emerald.gba", 0xd85a1c, 0x234

gUnknown_08D85C50: ; 8D85C50
	.incbin "base_emerald.gba", 0xd85c50, 0x80

gUnknown_08D85CD0: ; 8D85CD0
	.incbin "base_emerald.gba", 0xd85cd0, 0x182

gUnknown_08D85E52: ; 8D85E52
	.incbin "base_emerald.gba", 0xd85e52, 0x20

gUnknown_08D85E72: ; 8D85E72
	.incbin "base_emerald.gba", 0xd85e72, 0xa

gUnknown_08D85E7C: ; 8D85E7C
	.incbin "base_emerald.gba", 0xd85e7c, 0x2618

gUnknown_08D88494: ; 8D88494
	.incbin "base_emerald.gba", 0xd88494, 0x8ac

gUnknown_08D88D40: ; 8D88D40
	.incbin "base_emerald.gba", 0xd88d40, 0x4e4

gUnknown_08D89224: ; 8D89224
	.incbin "base_emerald.gba", 0xd89224, 0x898

gUnknown_08D89ABC: ; 8D89ABC
	.incbin "base_emerald.gba", 0xd89abc, 0x4c0

gUnknown_08D89F7C: ; 8D89F7C
	.incbin "base_emerald.gba", 0xd89f7c, 0x89c

gUnknown_08D8A818: ; 8D8A818
	.incbin "base_emerald.gba", 0xd8a818, 0x11c

gUnknown_08D8A934: ; 8D8A934
	.incbin "base_emerald.gba", 0xd8a934, 0x120

gUnknown_08D8AA54: ; 8D8AA54
	.incbin "base_emerald.gba", 0xd8aa54, 0x72c

gUnknown_08D8B180: ; 8D8B180
	.incbin "base_emerald.gba", 0xd8b180, 0x2c0

gUnknown_08D8B440: ; 8D8B440
	.incbin "base_emerald.gba", 0xd8b440, 0x2a8

gUnknown_08D8B6E8: ; 8D8B6E8
	.incbin "base_emerald.gba", 0xd8b6e8, 0x38c

gUnknown_08D8BA74: ; 8D8BA74
	.incbin "base_emerald.gba", 0xd8ba74, 0x6f8

gUnknown_08D8C16C: ; 8D8C16C
	.incbin "base_emerald.gba", 0xd8c16c, 0x6cc

gUnknown_08D8C838: ; 8D8C838
	.incbin "base_emerald.gba", 0xd8c838, 0x490

gUnknown_08D8CCC8: ; 8D8CCC8
	.incbin "base_emerald.gba", 0xd8ccc8, 0x748

gUnknown_08D8D410: ; 8D8D410
	.incbin "base_emerald.gba", 0xd8d410, 0x17c

gUnknown_08D8D58C: ; 8D8D58C
	.incbin "base_emerald.gba", 0xd8d58c, 0x52c

gUnknown_08D8DAB8: ; 8D8DAB8
	.incbin "base_emerald.gba", 0xd8dab8, 0xefc

gUnknown_08D8E9B4: ; 8D8E9B4
	.incbin "base_emerald.gba", 0xd8e9b4, 0x80

gUnknown_08D8EA34: ; 8D8EA34
	.incbin "base_emerald.gba", 0xd8ea34, 0x1f0

gUnknown_08D8EC24: ; 8D8EC24
	.incbin "base_emerald.gba", 0xd8ec24, 0xf78

gUnknown_08D8FB9C: ; 8D8FB9C
	.incbin "base_emerald.gba", 0xd8fb9c, 0x19fc

gUnknown_08D91598: ; 8D91598
	.incbin "base_emerald.gba", 0xd91598, 0x820

gUnknown_08D91DB8: ; 8D91DB8
	.incbin "base_emerald.gba", 0xd91db8, 0xa34

gUnknown_08D927EC: ; 8D927EC
	.incbin "base_emerald.gba", 0xd927ec, 0xaf4

gUnknown_08D932E0: ; 8D932E0
	.incbin "base_emerald.gba", 0xd932e0, 0x2b8

gUnknown_08D93598: ; 8D93598
	.incbin "base_emerald.gba", 0xd93598, 0x1e4

gUnknown_08D9377C: ; 8D9377C
	.incbin "base_emerald.gba", 0xd9377c, 0x1e4

gUnknown_08D93960: ; 8D93960
	.incbin "base_emerald.gba", 0xd93960, 0x1158

gUnknown_08D94AB8: ; 8D94AB8
	.incbin "base_emerald.gba", 0xd94ab8, 0x1320

gUnknown_08D95DD8: ; 8D95DD8
	.incbin "base_emerald.gba", 0xd95dd8, 0x28

gUnknown_08D95E00: ; 8D95E00
	.incbin "base_emerald.gba", 0xd95e00, 0x2d0

gUnknown_08D960D0: ; 8D960D0
	.incbin "base_emerald.gba", 0xd960d0, 0x2d4

gUnknown_08D963A4: ; 8D963A4
	.incbin "base_emerald.gba", 0xd963a4, 0x448

gUnknown_08D967EC: ; 8D967EC
	.incbin "base_emerald.gba", 0xd967ec, 0x2c8

gUnknown_08D96AB4: ; 8D96AB4
	.incbin "base_emerald.gba", 0xd96ab4, 0xec

gUnknown_08D96BA0: ; 8D96BA0
	.incbin "base_emerald.gba", 0xd96ba0, 0xfe4

gUnknown_08D97B84: ; 8D97B84
	.incbin "base_emerald.gba", 0xd97b84, 0x188

gUnknown_08D97D0C: ; 8D97D0C
	.incbin "base_emerald.gba", 0xd97d0c, 0x830

gUnknown_08D9853C: ; 8D9853C
	.incbin "base_emerald.gba", 0xd9853c, 0xf0

gUnknown_08D9862C: ; 8D9862C
	.incbin "base_emerald.gba", 0xd9862c, 0x1d0

gUnknown_08D987FC: ; 8D987FC
	.incbin "base_emerald.gba", 0xd987fc, 0x190

gUnknown_08D9898C: ; 8D9898C
	.incbin "base_emerald.gba", 0xd9898c, 0x19c

gUnknown_08D98B28: ; 8D98B28
	.incbin "base_emerald.gba", 0xd98b28, 0x1a0

gUnknown_08D98CC8: ; 8D98CC8
	.incbin "base_emerald.gba", 0xd98cc8, 0x18c0

gUnknown_08D9A588: ; 8D9A588
	.incbin "base_emerald.gba", 0xd9a588, 0x4c

gUnknown_08D9A5D4: ; 8D9A5D4
	.incbin "base_emerald.gba", 0xd9a5d4, 0x4c

gUnknown_08D9A620: ; 8D9A620
	.incbin "base_emerald.gba", 0xd9a620, 0x26c

gUnknown_08D9A88C: ; 8D9A88C
	.incbin "base_emerald.gba", 0xd9a88c, 0x544

gUnknown_08D9ADD0: ; 8D9ADD0
	.incbin "base_emerald.gba", 0xd9add0, 0x34

gUnknown_08D9AE04: ; 8D9AE04
	.incbin "base_emerald.gba", 0xd9ae04, 0x140

gUnknown_08D9AF44: ; 8D9AF44
	.incbin "base_emerald.gba", 0xd9af44, 0x78

gUnknown_08D9AFBC: ; 8D9AFBC
	.incbin "base_emerald.gba", 0xd9afbc, 0x10c

gUnknown_08D9B0C8: ; 8D9B0C8
	.incbin "base_emerald.gba", 0xd9b0c8, 0x28

gUnknown_08D9B0F0: ; 8D9B0F0
	.incbin "base_emerald.gba", 0xd9b0f0, 0x1c4

gUnknown_08D9B2B4: ; 8D9B2B4
	.incbin "base_emerald.gba", 0xd9b2b4, 0x1bc

gUnknown_08D9B470: ; 8D9B470
	.incbin "base_emerald.gba", 0xd9b470, 0x358

gUnknown_08D9B7C8: ; 8D9B7C8
	.incbin "base_emerald.gba", 0xd9b7c8, 0x27c

gUnknown_08D9BA44: ; 8D9BA44
	.incbin "base_emerald.gba", 0xd9ba44, 0x100

gUnknown_08D9BB44: ; 8D9BB44
	.incbin "base_emerald.gba", 0xd9bb44, 0x3ac

gUnknown_08D9BEF0: ; 8D9BEF0
	.incbin "base_emerald.gba", 0xd9bef0, 0xa8

gUnknown_08D9BF98: ; 8D9BF98
	.incbin "base_emerald.gba", 0xd9bf98, 0x1a4

gUnknown_08D9C13C: ; 8D9C13C
	.incbin "base_emerald.gba", 0xd9c13c, 0x7284

gUnknown_08DA33C0: ; 8DA33C0
	.incbin "base_emerald.gba", 0xda33c0, 0x428

gUnknown_08DA37E8: ; 8DA37E8
	.incbin "base_emerald.gba", 0xda37e8, 0x3c

gUnknown_08DA3824: ; 8DA3824
	.incbin "base_emerald.gba", 0xda3824, 0x164

gUnknown_08DA3988: ; 8DA3988
	.incbin "base_emerald.gba", 0xda3988, 0x100

gUnknown_08DA3A88: ; 8DA3A88
	.incbin "base_emerald.gba", 0xda3a88, 0x20c

gUnknown_08DA3C94: ; 8DA3C94
	.incbin "base_emerald.gba", 0xda3c94, 0x1114

gUnknown_08DA4DA8: ; 8DA4DA8
	.incbin "base_emerald.gba", 0xda4da8, 0x44

gUnknown_08DA4DEC: ; 8DA4DEC
	.incbin "base_emerald.gba", 0xda4dec, 0x184

gUnknown_08DA4F70: ; 8DA4F70
	.incbin "base_emerald.gba", 0xda4f70, 0x1148

gUnknown_08DA60B8: ; 8DA60B8
	.incbin "base_emerald.gba", 0xda60b8, 0x904

gUnknown_08DA69BC: ; 8DA69BC
	.incbin "base_emerald.gba", 0xda69bc, 0xb6c

gUnknown_08DA7528: ; 8DA7528
	.incbin "base_emerald.gba", 0xda7528, 0x21c

gUnknown_08DA7744: ; 8DA7744
	.incbin "base_emerald.gba", 0xda7744, 0x40

gUnknown_08DA7784: ; 8DA7784
	.incbin "base_emerald.gba", 0xda7784, 0x328

gUnknown_08DA7AAC: ; 8DA7AAC
	.incbin "base_emerald.gba", 0xda7aac, 0x184

gUnknown_08DA7C30: ; 8DA7C30
	.incbin "base_emerald.gba", 0xda7c30, 0x13c

gUnknown_08DA7D6C: ; 8DA7D6C
	.incbin "base_emerald.gba", 0xda7d6c, 0x140

gUnknown_08DA7EAC: ; 8DA7EAC
	.incbin "base_emerald.gba", 0xda7eac, 0x108

gUnknown_08DA7FB4: ; 8DA7FB4
	.incbin "base_emerald.gba", 0xda7fb4, 0x108

gUnknown_08DA80BC: ; 8DA80BC
	.incbin "base_emerald.gba", 0xda80bc, 0xa84

gUnknown_08DA8B40: ; 8DA8B40
	.incbin "base_emerald.gba", 0xda8b40, 0x22c

gUnknown_08DA8D6C: ; 8DA8D6C
	.incbin "base_emerald.gba", 0xda8d6c, 0x118

gUnknown_08DA8E84: ; 8DA8E84
	.incbin "base_emerald.gba", 0xda8e84, 0x1a30

gUnknown_08DAA8B4: ; 8DAA8B4
	.incbin "base_emerald.gba", 0xdaa8b4, 0x270

gUnknown_08DAAB24: ; 8DAAB24
	.incbin "base_emerald.gba", 0xdaab24, 0xf8

gUnknown_08DAAC1C: ; 8DAAC1C
	.incbin "base_emerald.gba", 0xdaac1c, 0x238

gUnknown_08DAAE54: ; 8DAAE54
	.incbin "base_emerald.gba", 0xdaae54, 0x144

gUnknown_08DAAF98: ; 8DAAF98
	.incbin "base_emerald.gba", 0xdaaf98, 0x54

gUnknown_08DAAFEC: ; 8DAAFEC
	.incbin "base_emerald.gba", 0xdaafec, 0xf52c

gUnknown_08DBA518: ; 8DBA518
	.incbin "base_emerald.gba", 0xdba518, 0xa0

gUnknown_08DBA5B8: ; 8DBA5B8
	.incbin "base_emerald.gba", 0xdba5b8, 0x1d30

gUnknown_08DBC2E8: ; 8DBC2E8
	.incbin "base_emerald.gba", 0xdbc2e8, 0x72c

gUnknown_08DBCA14: ; 8DBCA14
	.incbin "base_emerald.gba", 0xdbca14, 0x3d00

gUnknown_08DC0714: ; 8DC0714
	.incbin "base_emerald.gba", 0xdc0714, 0x40

gUnknown_08DC0754: ; 8DC0754
	.incbin "base_emerald.gba", 0xdc0754, 0x440

gUnknown_08DC0B94: ; 8DC0B94
	.incbin "base_emerald.gba", 0xdc0b94, 0xb62

gUnknown_08DC16F6: ; 8DC16F6
	.incbin "base_emerald.gba", 0xdc16f6, 0x60

gUnknown_08DC1756: ; 8DC1756
	.incbin "base_emerald.gba", 0xdc1756, 0x60

gUnknown_08DC17B6: ; 8DC17B6
	.incbin "base_emerald.gba", 0xdc17b6, 0xc0

gUnknown_08DC1876: ; 8DC1876
	.incbin "base_emerald.gba", 0xdc1876, 0xbe

gUnknown_08DC1934: ; 8DC1934
	.incbin "base_emerald.gba", 0xdc1934, 0x10d4

gUnknown_08DC2A08: ; 8DC2A08
	.incbin "base_emerald.gba", 0xdc2a08, 0x114

gUnknown_08DC2B1C: ; 8DC2B1C
	.incbin "base_emerald.gba", 0xdc2b1c, 0x140

gUnknown_08DC2C5C: ; 8DC2C5C
	.incbin "base_emerald.gba", 0xdc2c5c, 0x150

gUnknown_08DC2DAC: ; 8DC2DAC
	.incbin "base_emerald.gba", 0xdc2dac, 0xc0

gUnknown_08DC2E6C: ; 8DC2E6C
	.incbin "base_emerald.gba", 0xdc2e6c, 0xf0

gUnknown_08DC2F5C: ; 8DC2F5C
	.incbin "base_emerald.gba", 0xdc2f5c, 0x90

gUnknown_08DC2FEC: ; 8DC2FEC
	.incbin "base_emerald.gba", 0xdc2fec, 0x94

gUnknown_08DC3080: ; 8DC3080
	.incbin "base_emerald.gba", 0xdc3080, 0x118

gUnknown_08DC3198: ; 8DC3198
	.incbin "base_emerald.gba", 0xdc3198, 0xee

gUnknown_08DC3286: ; 8DC3286
	.incbin "base_emerald.gba", 0xdc3286, 0x7e

gUnknown_08DC3304: ; 8DC3304
	.incbin "base_emerald.gba", 0xdc3304, 0x56c

gUnknown_08DC3870: ; 8DC3870
	.incbin "base_emerald.gba", 0xdc3870, 0x19c

gUnknown_08DC3A0C: ; 8DC3A0C
	.incbin "base_emerald.gba", 0xdc3a0c, 0x2c8

gUnknown_08DC3CD4: ; 8DC3CD4
	.incbin "base_emerald.gba", 0xdc3cd4, 0x80

gUnknown_08DC3D54: ; 8DC3D54
	.incbin "base_emerald.gba", 0xdc3d54, 0x20

gUnknown_08DC3D74: ; 8DC3D74
	.incbin "base_emerald.gba", 0xdc3d74, 0x260

gUnknown_08DC3FD4: ; 8DC3FD4
	.incbin "base_emerald.gba", 0xdc3fd4, 0x16c

gUnknown_08DC4140: ; 8DC4140
	.incbin "base_emerald.gba", 0xdc4140, 0x1d8

gUnknown_08DC4318: ; 8DC4318
	.incbin "base_emerald.gba", 0xdc4318, 0x20

gUnknown_08DC4338: ; 8DC4338
	.incbin "base_emerald.gba", 0xdc4338, 0x20

gUnknown_08DC4358: ; 8DC4358
	.incbin "base_emerald.gba", 0xdc4358, 0x20

gUnknown_08DC4378: ; 8DC4378
	.incbin "base_emerald.gba", 0xdc4378, 0x2000

gUnknown_08DC6378: ; 8DC6378
	.incbin "base_emerald.gba", 0xdc6378, 0x80

gUnknown_08DC63F8: ; 8DC63F8
	.incbin "base_emerald.gba", 0xdc63f8, 0x28

gUnknown_08DC6420: ; 8DC6420
	.incbin "base_emerald.gba", 0xdc6420, 0x28

gUnknown_08DC6448: ; 8DC6448
	.incbin "base_emerald.gba", 0xdc6448, 0x28

gUnknown_08DC6470: ; 8DC6470
	.incbin "base_emerald.gba", 0xdc6470, 0x28

gUnknown_08DC6498: ; 8DC6498
	.incbin "base_emerald.gba", 0xdc6498, 0x14

gUnknown_08DC64AC: ; 8DC64AC
	.incbin "base_emerald.gba", 0xdc64ac, 0x14

gUnknown_08DC64C0: ; 8DC64C0
	.incbin "base_emerald.gba", 0xdc64c0, 0x14

gUnknown_08DC64D4: ; 8DC64D4
	.incbin "base_emerald.gba", 0xdc64d4, 0x14

gUnknown_08DC64E8: ; 8DC64E8
	.incbin "base_emerald.gba", 0xdc64e8, 0x14

gUnknown_08DC64FC: ; 8DC64FC
	.incbin "base_emerald.gba", 0xdc64fc, 0x14

gUnknown_08DC6510: ; 8DC6510
	.incbin "base_emerald.gba", 0xdc6510, 0x18

gUnknown_08DC6528: ; 8DC6528
	.incbin "base_emerald.gba", 0xdc6528, 0x20

gUnknown_08DC6548: ; 8DC6548
	.incbin "base_emerald.gba", 0xdc6548, 0x8b4

gUnknown_08DC6DFC: ; 8DC6DFC
	.incbin "base_emerald.gba", 0xdc6dfc, 0x274

gUnknown_08DC7070: ; 8DC7070
	.incbin "base_emerald.gba", 0xdc7070, 0xaf0

gUnknown_08DC7B60: ; 8DC7B60
	.incbin "base_emerald.gba", 0xdc7b60, 0x20

gUnknown_08DC7B80: ; 8DC7B80
	.incbin "base_emerald.gba", 0xdc7b80, 0x204

gUnknown_08DC7D84: ; 8DC7D84
	.incbin "base_emerald.gba", 0xdc7d84, 0x17c

gUnknown_08DC7F00: ; 8DC7F00
	.incbin "base_emerald.gba", 0xdc7f00, 0x11c0

gUnknown_08DC90C0: ; 8DC90C0
	.incbin "base_emerald.gba", 0xdc90c0, 0x20

gUnknown_08DC90E0: ; 8DC90E0
	.incbin "base_emerald.gba", 0xdc90e0, 0x50

gUnknown_08DC9130: ; 8DC9130
	.incbin "base_emerald.gba", 0xdc9130, 0xb8

gUnknown_08DC91E8: ; 8DC91E8
	.incbin "base_emerald.gba", 0xdc91e8, 0x420

gUnknown_08DC9608: ; 8DC9608
	.incbin "base_emerald.gba", 0xdc9608, 0x20

gUnknown_08DC9628: ; 8DC9628
	.incbin "base_emerald.gba", 0xdc9628, 0x2788

gUnknown_08DCBDB0: ; 8DCBDB0
	.incbin "base_emerald.gba", 0xdcbdb0, 0x20

gUnknown_08DCBDD0: ; 8DCBDD0
	.incbin "base_emerald.gba", 0xdcbdd0, 0x140

gUnknown_08DCBF10: ; 8DCBF10
	.incbin "base_emerald.gba", 0xdcbf10, 0x10c

gUnknown_08DCC01C: ; 8DCC01C
	.incbin "base_emerald.gba", 0xdcc01c, 0x20

gUnknown_08DCC03C: ; 8DCC03C
	.incbin "base_emerald.gba", 0xdcc03c, 0x20

gUnknown_08DCC05C: ; 8DCC05C
	.incbin "base_emerald.gba", 0xdcc05c, 0x5ec

gUnknown_08DCC648: ; 8DCC648
	.incbin "base_emerald.gba", 0xdcc648, 0x2c0

gUnknown_08DCC908: ; 8DCC908
	.incbin "base_emerald.gba", 0xdcc908, 0x2b0

gUnknown_08DCCBB8: ; 8DCCBB8
	.incbin "base_emerald.gba", 0xdccbb8, 0x3a4

gUnknown_08DCCF5C: ; 8DCCF5C
	.incbin "base_emerald.gba", 0xdccf5c, 0x20

gUnknown_08DCCF7C: ; 8DCCF7C
	.incbin "base_emerald.gba", 0xdccf7c, 0x8a0

gUnknown_08DCD81C: ; 8DCD81C
	.incbin "base_emerald.gba", 0xdcd81c, 0x214

gUnknown_08DCDA30: ; 8DCDA30
	.incbin "base_emerald.gba", 0xdcda30, 0x60

gUnknown_08DCDA90: ; 8DCDA90
	.incbin "base_emerald.gba", 0xdcda90, 0xa0

gUnknown_08DCDB30: ; 8DCDB30
	.incbin "base_emerald.gba", 0xdcdb30, 0xc40

gUnknown_08DCE770: ; 8DCE770
	.incbin "base_emerald.gba", 0xdce770, 0x500

gUnknown_08DCEC70: ; 8DCEC70
	.incbin "base_emerald.gba", 0xdcec70, 0x13e0

gUnknown_08DD0050: ; 8DD0050
	.incbin "base_emerald.gba", 0xdd0050, 0x1a68

gUnknown_08DD1AB8: ; 8DD1AB8
	.incbin "base_emerald.gba", 0xdd1ab8, 0x4c0

gUnknown_08DD1F78: ; 8DD1F78
	.incbin "base_emerald.gba", 0xdd1f78, 0x98

gUnknown_08DD2010: ; 8DD2010
	.incbin "base_emerald.gba", 0xdd2010, 0x1a0

gUnknown_08DD21B0: ; 8DD21B0
	.incbin "base_emerald.gba", 0xdd21b0, 0xdc

gUnknown_08DD228C: ; 8DD228C
	.incbin "base_emerald.gba", 0xdd228c, 0x1e0

gUnknown_08DD246C: ; 8DD246C
	.incbin "base_emerald.gba", 0xdd246c, 0x674

gUnknown_08DD2AE0: ; 8DD2AE0
	.incbin "base_emerald.gba", 0xdd2ae0, 0x98

gUnknown_08DD2B78: ; 8DD2B78
	.incbin "base_emerald.gba", 0xdd2b78, 0x1b8

gUnknown_08DD2D30: ; 8DD2D30
	.incbin "base_emerald.gba", 0xdd2d30, 0x12c

gUnknown_08DD2E5C: ; 8DD2E5C
	.incbin "base_emerald.gba", 0xdd2e5c, 0x18c

gUnknown_08DD2FE8: ; 8DD2FE8
	.incbin "base_emerald.gba", 0xdd2fe8, 0x6c0

gUnknown_08DD36A8: ; 8DD36A8
	.incbin "base_emerald.gba", 0xdd36a8, 0x20

gUnknown_08DD36C8: ; 8DD36C8
	.incbin "base_emerald.gba", 0xdd36c8, 0xb0

gUnknown_08DD3778: ; 8DD3778
	.incbin "base_emerald.gba", 0xdd3778, 0xc0

gUnknown_08DD3838: ; 8DD3838
	.incbin "base_emerald.gba", 0xdd3838, 0xd0c

gUnknown_08DD4544: ; 8DD4544
	.incbin "base_emerald.gba", 0xdd4544, 0xdc

gUnknown_08DD4620: ; 8DD4620
	.incbin "base_emerald.gba", 0xdd4620, 0xc0

gUnknown_08DD46E0: ; 8DD46E0
	.incbin "base_emerald.gba", 0xdd46e0, 0x180

gUnknown_08DD4860: ; 8DD4860
	.incbin "base_emerald.gba", 0xdd4860, 0x20

gUnknown_08DD4880: ; 8DD4880
	.incbin "base_emerald.gba", 0xdd4880, 0x238

gUnknown_08DD4AB8: ; 8DD4AB8
	.incbin "base_emerald.gba", 0xdd4ab8, 0xf8

gUnknown_08DD4BB0: ; 8DD4BB0
	.incbin "base_emerald.gba", 0xdd4bb0, 0x20

gUnknown_08DD4BD0: ; 8DD4BD0
	.incbin "base_emerald.gba", 0xdd4bd0, 0x20

gUnknown_08DD4BF0: ; 8DD4BF0
	.incbin "base_emerald.gba", 0xdd4bf0, 0x5c

gUnknown_08DD4C4C: ; 8DD4C4C
	.incbin "base_emerald.gba", 0xdd4c4c, 0x26b4

gUnknown_08DD7300: ; 8DD7300
	.incbin "base_emerald.gba", 0xdd7300, 0x60

gUnknown_08DD7360: ; 8DD7360
	.incbin "base_emerald.gba", 0xdd7360, 0x4084

gUnknown_08DDB3E4: ; 8DDB3E4
	.incbin "base_emerald.gba", 0xddb3e4, 0x80

gUnknown_08DDB464: ; 8DDB464
	.incbin "base_emerald.gba", 0xddb464, 0x1aa0

gUnknown_08DDCF04: ; 8DDCF04
	.incbin "base_emerald.gba", 0xddcf04, 0x800

gUnknown_08DDD704: ; 8DDD704
	.incbin "base_emerald.gba", 0xddd704, 0x24

gUnknown_08DDD728: ; 8DDD728
	.incbin "base_emerald.gba", 0xddd728, 0x20

gUnknown_08DDD748: ; 8DDD748
	.incbin "base_emerald.gba", 0xddd748, 0x8c8

gUnknown_08DDE010: ; 8DDE010
	.incbin "base_emerald.gba", 0xdde010, 0x20

gUnknown_08DDE030: ; 8DDE030
	.incbin "base_emerald.gba", 0xdde030, 0xfc

gUnknown_08DDE12C: ; 8DDE12C
	.incbin "base_emerald.gba", 0xdde12c, 0xcc

gUnknown_08DDE1F8: ; 8DDE1F8
	.incbin "base_emerald.gba", 0xdde1f8, 0x60

gUnknown_08DDE258: ; 8DDE258
	.incbin "base_emerald.gba", 0xdde258, 0x1e0

gUnknown_08DDE438: ; 8DDE438
	.incbin "base_emerald.gba", 0xdde438, 0x20

gUnknown_08DDE458: ; 8DDE458
	.incbin "base_emerald.gba", 0xdde458, 0x238

gUnknown_08DDE690: ; 8DDE690
	.incbin "base_emerald.gba", 0xdde690, 0x1fb4

gUnknown_08DE0644: ; 8DE0644
	.incbin "base_emerald.gba", 0xde0644, 0x184

gUnknown_08DE07C8: ; 8DE07C8
	.incbin "base_emerald.gba", 0xde07c8, 0x100

gUnknown_08DE08C8: ; 8DE08C8
	.incbin "base_emerald.gba", 0xde08c8, 0x17bc

gUnknown_08DE2084: ; 8DE2084
	.incbin "base_emerald.gba", 0xde2084, 0xfdc

gUnknown_08DE3060: ; 8DE3060
	.incbin "base_emerald.gba", 0xde3060, 0x2f0

gUnknown_08DE3350: ; 8DE3350
	.incbin "base_emerald.gba", 0xde3350, 0x24

gUnknown_08DE3374: ; 8DE3374
	.incbin "base_emerald.gba", 0xde3374, 0x24

gUnknown_08DE3398: ; 8DE3398
	.incbin "base_emerald.gba", 0xde3398, 0x120

gUnknown_08DE34B8: ; 8DE34B8
	.incbin "base_emerald.gba", 0xde34b8, 0xb1c

gUnknown_08DE3FD4: ; 8DE3FD4
	.incbin "base_emerald.gba", 0xde3fd4
