	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

// pokenav_unk_4.s
gUnknown_08622510:: @ 8622510
	.incbin "graphics/pokenav/ui_matchcall.gbapal"

gUnknown_08622530:: @ 8622530
	.incbin "graphics/pokenav/ui_matchcall.4bpp.lz"

gUnknown_086225D4:: @ 86225D4
	.incbin "graphics/pokenav/ui_matchcall.bin.lz"

gUnknown_08622698:: @ 8622698
	.incbin "graphics/pokenav/arrow2.gbapal"
	
gUnknown_086226B8:: @ 86226B8
	.incbin "graphics/pokenav/arrow2.4bpp.lz"

gUnknown_086226E0:: @ 86226E0
	.incbin "graphics/pokenav/86226E0.gbapal"

gUnknown_08622700:: @ 8622700
	.incbin "graphics/pokenav/8622700.gbapal"

gUnknown_08622720:: @ 8622720
	.incbin "graphics/pokenav/pokeball_matchcall.gbapal"

gUnknown_08622760:: @ 8622760
	.incbin "graphics/pokenav/pokeball_matchcall.4bpp.lz"

gUnknown_0862278C:: @ 862278C
	.4byte 0x11FD
	.4byte 0x20206A

gUnknown_08622794:: @ 8622794
	.4byte 0x00003077

gUnknown_08622798:: @ 8622798
	.4byte NULL
	.4byte sub_81CB510
	.4byte sub_81CB588
	.4byte sub_81CB600
	.4byte sub_81CB678
	.4byte sub_81CB6F0
	.4byte sub_81CB734
	.4byte sub_81CB75C
	.4byte sub_81CB7A0
	.4byte sub_81CB824
	.4byte sub_81CB888
	.4byte sub_81CB93C
	.4byte sub_81CBAD4
	.4byte sub_81CB9C8
	.4byte sub_81CBA68
	.4byte sub_81CBB74

gUnknown_086227D8:: @ 86227D8
	window_template 2, 0, 5, 11, 2, 2, 16

gUnknown_086227E0:: @ 86227E0
	window_template 2, 0, 9, 11, 8, 2, 0x26

gUnknown_086227E8:: @ 86227E8
	.4byte gUnknown_085EC017
	.4byte gUnknown_085EC01C
	.4byte gUnknown_085EC022

gUnknown_086227F4:: @ 86227F4
	.string "·{PAUSE 0x04}·{PAUSE 0x04}·{PAUSE 0x04}·{PAUSE 0x04}·\p"
	.string "$"
	.align 2

gUnknown_08622808:: @ 8622808
	window_template 1, 1, 12, 0x1C, 4, 1, 10

gUnknown_08622810:: @ 8622810
	obj_tiles gUnknown_086226B8, 0x40, 7

gUnknown_08622818:: @ 8622818
	obj_pal gUnknown_08622698, 12
	null_obj_pal

gUnknown_08622828:: @ 8622828
	.2byte 0x8000
	.2byte 0x0
	.2byte 0x400
	.2byte 0x0

gUnknown_08622830:: @ 8622830
	spr_template 7, 12, gUnknown_08622828, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81CC34C

gUnknown_08622848:: @ 8622848
	.2byte 0x0
	.2byte 0xC000
	.2byte 0x400
	.2byte 0x0

gUnknown_08622850:: @ 8622850
	spr_template 8, 13, gUnknown_08622848, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

// pokenav_unk_5.s
gUnknown_08622868:: @ 8622868
	.incbin "graphics/pokenav/8622868.gbapal"

gUnknown_08622888:: @ 8622888
	.incbin "graphics/pokenav/zoom_tiles.4bpp.lz"

gUnknown_08622A7C:: @ 8622A7C
	 .incbin "graphics/pokenav/city_maps/lavaridge_0.bin.lz"

gUnknown_08622AC0:: @ 8622AC0
	 .incbin "graphics/pokenav/city_maps/fallarbor_0.bin.lz"

gUnknown_08622B08:: @ 8622B08
	 .incbin "graphics/pokenav/city_maps/fortree_0.bin.lz"

gUnknown_08622B58:: @ 8622B58
	 .incbin "graphics/pokenav/city_maps/slateport_0.bin.lz"

gUnknown_08622BB8:: @ 8622BB8
	 .incbin "graphics/pokenav/city_maps/slateport_1.bin.lz"

gUnknown_08622C04:: @ 8622C04
	 .incbin "graphics/pokenav/city_maps/rustboro_0.bin.lz"

gUnknown_08622C58:: @ 8622C58
	 .incbin "graphics/pokenav/city_maps/rustboro_1.bin.lz"

gUnknown_08622CAC:: @ 8622CAC
	 .incbin "graphics/pokenav/city_maps/pacifidlog_0.bin.lz"

gUnknown_08622CEC:: @ 8622CEC
	 .incbin "graphics/pokenav/city_maps/mauville_0.bin.lz"

gUnknown_08622D44:: @ 8622D44
	 .incbin "graphics/pokenav/city_maps/mauville_1.bin.lz"

gUnknown_08622D98:: @ 8622D98
	 .incbin "graphics/pokenav/city_maps/oldale_0.bin.lz"

gUnknown_08622DC8:: @ 8622DC8
	 .incbin "graphics/pokenav/city_maps/lilycove_0.bin.lz"

gUnknown_08622E14:: @ 8622E14
	 .incbin "graphics/pokenav/city_maps/lilycove_1.bin.lz"

gUnknown_08622E6C:: @ 8622E6C
	 .incbin "graphics/pokenav/city_maps/littleroot_0.bin.lz"

gUnknown_08622E9C:: @ 8622E9C
	 .incbin "graphics/pokenav/city_maps/dewford_0.bin.lz"

gUnknown_08622ED4:: @ 8622ED4
	 .incbin "graphics/pokenav/city_maps/sootopolis_0.bin.lz"

gUnknown_08622F14:: @ 8622F14
	 .incbin "graphics/pokenav/city_maps/ever_grande_0.bin.lz"

gUnknown_08622F5C:: @ 8622F5C
	 .incbin "graphics/pokenav/city_maps/ever_grande_1.bin.lz"

gUnknown_08622FA0:: @ 8622FA0
	 .incbin "graphics/pokenav/city_maps/verdanturf_0.bin.lz"

gUnknown_08622FD8:: @ 8622FD8
	 .incbin "graphics/pokenav/city_maps/mossdeep_0.bin.lz"

gUnknown_08623020:: @ 8623020
	 .incbin "graphics/pokenav/city_maps/mossdeep_1.bin.lz"

gUnknown_0862307C:: @ 862307C
	 .incbin "graphics/pokenav/city_maps/petalburg_0.bin.lz"

gUnknown_086230D8:: @ 86230D8
	.4byte 0x11F5
	.4byte 0x206A
	.4byte 0x3402

gUnknown_086230E4:: @ 86230E4
	.4byte NULL
	.4byte sub_81CC848
	.4byte sub_81CC878
	.4byte sub_81CC8D8
	.4byte sub_81CC95C

gUnknown_086230F8:: @ 86230F8
	obj_tiles gHoennMapZoomIcons_Gfx, 0x800, 6

gUnknown_08623100:: @ 8623100
	obj_pal gHoennMapZoomIcons_Pal, 11
	null_obj_pal

gUnknown_08623110:: @ 8623110
	.byte 1
	.byte 17
	.byte 4
	.byte 12
	.byte 13
	.byte 1
	.2byte 0x4C

gUnknown_08623118:: @ 8623118
	.4byte 0, gUnknown_08622E6C 
	.4byte 1, gUnknown_08622D98
	.4byte 2, gUnknown_08622E9C
	.4byte 3, gUnknown_08622A7C
	.4byte 4, gUnknown_08622AC0
	.4byte 5, gUnknown_08622FA0
	.4byte 6, gUnknown_08622CAC
	.4byte 7, gUnknown_0862307C
	.4byte 8, gUnknown_08622B58
	.4byte 0x10008, gUnknown_08622BB8
	.4byte 9, gUnknown_08622D44
	.4byte 0x10009, gUnknown_08622CEC
	.4byte 0xA, gUnknown_08622C04
	.4byte 0x1000A, gUnknown_08622C58
	.4byte 0xB, gUnknown_08622B08
	.4byte 0xC, gUnknown_08622E14
	.4byte 0x1000C, gUnknown_08622DC8
	.4byte 0xD, gUnknown_08623020
	.4byte 0x1000D, gUnknown_08622FD8
	.4byte 0xE, gUnknown_08622ED4
	.4byte 0xF, gUnknown_08622F14
	.4byte 0x1000F, gUnknown_08622F5C

gUnknown_086231C8:: @ 86231C8
	.2byte 0x4000
	.2byte 0x4000
	.2byte 0x400
	.2byte 0x0

gUnknown_086231D0:: @ 86231D0
	spr_template 6, 11, gUnknown_086231C8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_81CCEF4

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
