	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

// pokenav_unk_5.s








// pokenav_unk_6.s
// <none>

// pokenav_unk_7.s
gUnknown_086231E8:: @ 86231E8
	.incbin "graphics/pokenav/86231E8.gbapal"

gUnknown_08623208:: @ 8623208
	.incbin "graphics/pokenav/8623208.gbapal"

gUnknown_08623228:: @ 8623228
	.incbin "graphics/pokenav/8623228.4bpp.lz"

gUnknown_0862323C:: @ 862323C
	.incbin "graphics/pokenav/862323C.bin.lz"

gUnknown_08623338:: @ 8623338
	.incbin "graphics/pokenav/8623338.gbapal"

gUnknown_08623358:: @ 8623358
	.4byte 0x11F5
	.4byte 0x21DE
	.4byte 0x31EB

gUnknown_08623364:: @ 8623364
	window_template 1, 13, 1, 13, 4, 15, 2

gUnknown_0862336C:: @ 862336C
	window_template 1, 1, 6, 7, 2, 15, 0x36

gUnknown_08623374:: @ 8623374
	window_template 1, 1, 0x1C, 5, 2, 15, 0x44

gUnknown_0862337C:: @ 862337C
	window_template 1, 13, 0x1C, 3, 2, 15, 0x44

// pokenav_unk_8.s
gUnknown_08623384:: @ 8623384
	.4byte NULL
	.4byte sub_81CE37C
	.4byte sub_81CE2D0
	.4byte sub_81CE4D8
	.4byte sub_81CE5E4
	.4byte sub_81CE6BC
	.4byte sub_81CE700

gUnknown_086233A0:: @ 86233A0
	.4byte 0x16, 0x17, 0x18, 0x21, 0x2F

gUnknown_086233B4:: @ 86233B4
	.4byte sub_81CF134
	.4byte sub_81CF1C4
	.4byte sub_81CF1D8
	.4byte sub_81CF278

gUnknown_086233C4:: @ 86233C4
	.incbin "graphics/pokenav/condition_search2.gbapal"

gUnknown_086233E4:: @ 86233E4
	.incbin "graphics/pokenav/condition_search2.4bpp.lz"

gUnknown_086234AC:: @ 86234AC
	.incbin "graphics/pokenav/condition_search2.bin.lz"

gUnknown_08623570:: @ 8623570
	.incbin "graphics/pokenav/8623570.gbapal"

gUnknown_08623590:: @ 8623590
	.4byte 0x2065

gUnknown_08623594:: @ 8623594
	.4byte 0x307A

gUnknown_08623598:: @ 8623598
	.4byte NULL
	.4byte sub_81CF578
	.4byte sub_81CF5F0
	.4byte sub_81CF668
	.4byte sub_81CF6E0
	.4byte sub_81CF758
	.4byte sub_81CF798

gUnknown_086235B4:: @ 86235B4
	window_template 1, 1, 6, 7, 2, 1, 20

gUnknown_086235BC:: @ 86235BC
	.string "{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}$"
	.align 2

gUnknown_086235C8:: @ 86235C8
	.string "{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}$"
	.align 2

gUnknown_086235D4:: @ 86235D4
	.string "{UNK_SPACER}$"
	.align 2

// pokenav_unk_9.s
gUnknown_086235D8:: @ 86235D8
	.4byte sub_81CFB8C
	.4byte sub_81CFC2C
	.4byte sub_81CFC40

gUnknown_086235E4:: @ 86235E4
	.incbin "graphics/pokenav/ui_ribbons.gbapal"

gUnknown_08623604:: @ 8623604
	.incbin "graphics/pokenav/ui_ribbons.4bpp.lz"

gUnknown_086236CC:: @ 86236CC
	.incbin "graphics/pokenav/ui_ribbons.bin.lz"

gUnknown_08623790:: @ 8623790
	.incbin "graphics/pokenav/8623790.gbapal"

gUnknown_086237B0:: @ 86237B0
	.4byte 0x2065

gUnknown_086237B4:: @ 86237B4
	.4byte 0x307A

gUnknown_086237B8:: @ 86237B8
	.4byte NULL
	.4byte sub_81CFFFC
	.4byte sub_81D0074
	.4byte sub_81D00EC
	.4byte sub_81D0164
	.4byte sub_81D01DC
	.4byte sub_81D021C

gUnknown_086237D4:: @ 86237D4
	window_template 1, 1, 6, 7, 2, 1, 20

gUnknown_086237DC:: @ 86237DC
	.string "{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}$"
	.align 2

gUnknown_086237E8:: @ 86237E8
	.string "{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}$"
	.align 2

gUnknown_086237F4:: @ 86237F4
	.string "{UNK_SPACER}$"
	.align 2

// pokenav_unk_10.s
gUnknown_086237F8:: @ 86237F8
	.byte 1, 1, 0, 0
	.byte 3, 4, 1, 0
	.byte 3, 4, 5, 0
	.byte 3, 4, 9, 0
	.byte 3, 4, 13, 0
	.byte 3, 4, 17, 0
	.byte 1, 1, 21, 0
	.byte 1, 1, 22, 0
	.byte 1, 1, 23, 0
	.byte 1, 1, 24, 0
	.byte 1, 1, 25, 1
	.byte 1, 1, 26, 1
	.byte 1, 1, 27, 1
	.byte 1, 1, 28, 1
	.byte 1, 1, 29, 1
	.byte 1, 1, 30, 1
	.byte 1, 1, 31, 1

@ 862383C
	.include "data/text/ribbon_descriptions.inc"

@ 8623A74
	.include "data/text/gift_ribbon_descriptions.inc"

gUnknown_08623FF8:: @ 8623FF8
	 .incbin "graphics/pokenav/ribbons_icon1.gbapal"

gUnknown_08624018:: @ 8624018
	 .incbin "graphics/pokenav/ribbons_icon2.gbapal"

gUnknown_08624038:: @ 8624038
	 .incbin "graphics/pokenav/ribbons_icon3.gbapal"

gUnknown_08624058:: @ 8624058
	 .incbin "graphics/pokenav/ribbons_icon4.gbapal"

gUnknown_08624078:: @ 8624078
	 .incbin "graphics/pokenav/ribbons_icon5.gbapal"

gUnknown_08624098:: @ 8624098
	 .incbin "graphics/pokenav/8624098.gbapal"

gUnknown_086240B8:: @ 86240B8
	 .incbin "graphics/pokenav/ribbons_icon.4bpp.lz"

gUnknown_08624280:: @ 8624280
	 .incbin "graphics/pokenav/ribbons_icon_big.4bpp.lz"

gUnknown_08624B98:: @ 8624B98
	.4byte 0x107D
	.4byte 0x2066

gUnknown_08624BA0:: @ 8624BA0
	.4byte NULL
	.4byte sub_81D0C84
	.4byte sub_81D0D2C
	.4byte sub_81D0D8C
	.4byte sub_81D0E00
	.4byte sub_81D0C54
