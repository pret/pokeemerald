@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082FECFC:: @ 82FECFC
	.incbin "graphics/birch_speech/bg0.gbapal"
	.incbin "graphics/birch_speech/bg1.gbapal"

	.align 2
gBirchIntroShadowGfx:: @ 82FED3C
	.incbin "graphics/birch_speech/shadow.4bpp.lz"

	.align 2
gUnknown_082FEEF0:: @ 82FEEF0
	.incbin "graphics/birch_speech/map.bin.lz"

	.align 2
gUnknown_082FF018:: @ 82FF018
	.incbin "graphics/birch_speech/bg2.gbapal"

	.align 2
gUnknown_082FF028:: @ 82FF028
	.space 16

	.align 2
gUnknown_082FF038:: @ 82FF038
	window_template 0x00, 0x02, 0x01, 0x1a, 0x02, 0x0f, 0x0001
	window_template 0x00, 0x02, 0x05, 0x1a, 0x02, 0x0f, 0x0035

	.align 2
gUnknown_082FF048:: @ 82FF048
	window_template 0x00, 0x02, 0x01, 0x1a, 0x06, 0x0f, 0x0001
	window_template 0x00, 0x02, 0x09, 0x1a, 0x02, 0x0f, 0x009d
	window_template 0x00, 0x02, 0x0d, 0x1a, 0x02, 0x0f, 0x00d1
	window_template 0x00, 0x02, 0x11, 0x1a, 0x02, 0x0f, 0x0105
	window_template 0x00, 0x02, 0x15, 0x1a, 0x02, 0x0f, 0x0139

	.align 2
gUnknown_082FF070:: @ 82FF070
	window_template 0x00, 0x02, 0x0f, 0x1a, 0x04, 0x0f, 0x016d
	window_template_terminator

	.align 2
gUnknown_082FF080:: @ 82FF080
	window_template 0x00, 0x02, 0x0f, 0x1b, 0x04, 0x0f, 0x0001

	.align 2
gUnknown_082FF088:: @ 82FF088
	window_template 0x00, 0x03, 0x05, 0x06, 0x04, 0x0f, 0x006d
	window_template 0x00, 0x03, 0x02, 0x09, 0x0a, 0x0f, 0x0085
	window_template_terminator

	.align 2
gMainMenuBgPal:: @ 82FF0A0
	.incbin "graphics/misc/main_menu_bg.gbapal"

	.align 2
gMainMenuTextPal:: @ 82FF0C0
	.incbin "graphics/misc/main_menu_text.gbapal"

	.align 2
gUnknown_082FF0E0:: @ 82FF0E0
	.byte 0x0a, 0x0b, 0x0c

gUnknown_082FF0E3:: @ 82FF0E3
	.byte 0x0a, 0x01, 0x0c

	.align 2
gUnknown_082FF0E8:: @ 82FF0E8
	.4byte 0x000001e8, 0x00003071

	.align 2
gUnknown_082FF0F0:: @ 82FF0F0
	.4byte 0x000001ec

	.align 2
gUnknown_082FF0F4:: @ 82FF0F4
	.byte 0x02, 0x78, 0x08, 0x03, 0x78, 0x98, 0x03, 0x00, 0x04, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FF104:: @ 82FF104
	.2byte 0xfffe, 0xfffe, 0x3000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_082FF114:: @ 82FF114
	.4byte gUnknown_082FF104

	.align 2
gUnknown_082FF118:: @ 82FF118
	.4byte gText_BirchBoy, 0x00000000
	.4byte gText_BirchGirl, 0x00000000

	.align 2
gMalePresetNames:: @ 82FF128
	.4byte gText_DefaultNameStu
	.4byte gText_DefaultNameMilton
	.4byte gText_DefaultNameTom
	.4byte gText_DefaultNameKenny
	.4byte gText_DefaultNameReid
	.4byte gText_DefaultNameJude
	.4byte gText_DefaultNameJaxson
	.4byte gText_DefaultNameEaston
	.4byte gText_DefaultNameWalker
	.4byte gText_DefaultNameTeru
	.4byte gText_DefaultNameJohnny
	.4byte gText_DefaultNameBrett
	.4byte gText_DefaultNameSeth
	.4byte gText_DefaultNameTerry
	.4byte gText_DefaultNameCasey
	.4byte gText_DefaultNameDarren
	.4byte gText_DefaultNameLandon
	.4byte gText_DefaultNameCollin
	.4byte gText_DefaultNameStanley
	.4byte gText_DefaultNameQuincy

	.align 2
gFemalePresetNames:: @ 82FF178
	.4byte gText_DefaultNameKimmy
	.4byte gText_DefaultNameTiara
	.4byte gText_DefaultNameBella
	.4byte gText_DefaultNameJayla
	.4byte gText_DefaultNameAllie
	.4byte gText_DefaultNameLianna
	.4byte gText_DefaultNameSara
	.4byte gText_DefaultNameMonica
	.4byte gText_DefaultNameCamila
	.4byte gText_DefaultNameAubree
	.4byte gText_DefaultNameRuthie
	.4byte gText_DefaultNameHazel
	.4byte gText_DefaultNameNadine
	.4byte gText_DefaultNameTanja
	.4byte gText_DefaultNameYasmin
	.4byte gText_DefaultNameNicola
	.4byte gText_DefaultNameLillie
	.4byte gText_DefaultNameTerra
	.4byte gText_DefaultNameLucy
	.4byte gText_DefaultNameHalie
