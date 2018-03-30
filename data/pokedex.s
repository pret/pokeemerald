	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

.macro unk_dex_struct texts, a2, a3, a4
	.4byte \texts
	.byte \a2, \a3, \a4
	.byte 0 @padding
.endm

.macro unk_dex_struct_2 text, a2, a3, a4, a5, a6, a7
	.4byte \text
	.byte \a2, \a3, \a4, \a5, \a6, \a7
	.2byte 0 @padding
.endm

.macro unk_dex_struct_3 text, a2, a3, a4
	.4byte \text
	.byte \a2, \a3, \a4
	.byte 0 @padding
.endm

	.align 2
gUnknown_0855D30C:: @ 855D30C
	.string "$"

@ 855D30D
	.include "data/text/pokedex_text.inc"

@ 856B5B0
	.include "data/pokedex_entries.inc"

	.align 2
gUnknown_0856E610:: @ 856E610
	.incbin "graphics/pokedex/black.gbapal"

	.align 2
gUnknown_0856E630:: @ 856E630
	.4byte 0x000030c8, 0x000000d1, 0x000010ea, 0x000020f3

	.align 2
gUnknown_0856E640:: @ 856E640
	window_template 0x02, 0x00, 0x00, 0x20, 0x14, 0x00, 0x0001
	window_template 0x02, 0x19, 0x08, 0x02, 0x02, 0x0f, 0x0281
	window_template 0x00, 0x00, 0x0c, 0x20, 0x07, 0x08, 0x0285
	window_template 0x02, 0x12, 0x03, 0x0a, 0x08, 0x09, 0x0365
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

	.align 2
gUnknown_0856E668:: @ 856E668
	.4byte 0x000020ea, 0x000030f7

	.align 2
gUnknown_0856E670:: @ 856E670
	window_template 0x02, 0x00, 0x00, 0x20, 0x14, 0x00, 0x0001
	window_template 0x02, 0x19, 0x08, 0x02, 0x02, 0x0f, 0x0281
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

sText_TenDashes2:: @ 856E688
	.string "----------$"

@ 856E694
	.include "data/graphics/pokemon/footprint_table.inc"

gUnknown_0856ED08:: @ 856ED08
	.byte 0x00, 0x00, 0x00, 0x00, 0xbb, 0x03, 0xd5, 0x03, 0xbe, 0x03, 0xd8, 0x03, 0xc1, 0x03, 0xdb, 0x03, 0xc4, 0x03, 0xde, 0x03, 0xc7, 0x03, 0xe1, 0x03, 0xca, 0x03, 0xe4, 0x03, 0xcd, 0x03, 0xe7, 0x03
	.byte 0xd0, 0x03, 0xea, 0x03, 0xd3, 0x02, 0xed, 0x02

gUnknown_0856ED30:: @ 856ED30
	unk_dex_struct_3 gUnknown_085E87A5, 0, 0, 5
	unk_dex_struct_3 gUnknown_085E87D6, 6, 0, 5
	unk_dex_struct_3 gUnknown_085E87EF, 12, 0, 5

gUnknown_0856ED48:: @ 856ED48
	unk_dex_struct_2 gUnknown_085E8840, 0, 2, 5, 5, 2, 12
	unk_dex_struct_2 gUnknown_085E887C, 0, 4, 5, 5, 4, 12
	unk_dex_struct_2 gUnknown_085E88A6, 0, 6, 5, 5, 6, 6
	unk_dex_struct_2 gUnknown_085E88A6, 0, 6, 5, 11, 6, 6
	unk_dex_struct_2 gUnknown_085E881F, 0, 8, 5, 5, 8, 12
	unk_dex_struct_2 gUnknown_085E8806, 0, 10, 5, 5, 10, 12
	unk_dex_struct_2 gUnknown_085E88C8, 0, 12, 5, 0, 0, 0

	.align 1
gUnknown_0856ED9C:: @ 856ED9C
	.2byte 0xffff, 0x01ff, 0xffff, 0x0200, 0x03ff, 0x0401, 0xff02, 0x0401, 0xffff, 0x0502, 0xffff, 0x0604, 0xffff, 0xff05

	.align 1
gUnknown_0856EDB8:: @ 856EDB8
	.2byte 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x05ff, 0xffff, 0x0604, 0xffff, 0xff05

	.align 1
gUnknown_0856EDD4:: @ 856EDD4
	.2byte 0xffff, 0x01ff, 0xffff, 0x0200, 0x03ff, 0x0401, 0xff02, 0x0401, 0xffff, 0x0602, 0xffff, 0xffff, 0xffff, 0xff04

	.align 1
gUnknown_0856EDF0:: @ 856EDF0
	.2byte 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x06ff, 0xffff, 0xffff, 0xffff, 0xff04

	.align 2
gUnknown_0856EE0C:: @ 856EE0C
	.4byte gUnknown_085E89A4
	.4byte gUnknown_085E88DF
	.4byte gUnknown_085E89BB
	.4byte gUnknown_085E88E9
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_0856EE24:: @ 856EE24
	.4byte gUnknown_085E89D4
	.4byte gUnknown_085E88F6
	.4byte gUnknown_085E8A02
	.4byte gUnknown_085E8905
	.4byte gUnknown_085E8A37
	.4byte gUnknown_085E8911
	.4byte gUnknown_085E8A73
	.4byte gUnknown_085E891F
	.4byte gUnknown_085E8AAF
	.4byte gUnknown_085E892D
	.4byte gUnknown_085E8AEA
	.4byte gUnknown_085E893A
	.4byte 0
	.4byte 0

gUnknown_0856EE5C:: @ 856EE5C
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8B26
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8948
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E894C
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8950
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8954
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8958
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E895C
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8960
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8964
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8968
	.4byte 0
	.4byte 0

gUnknown_0856EEB4:: @ 856EEB4
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8B26
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E896B
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E896F
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8974
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E897B
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8981
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8987
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E898D
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8994
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8999
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E899F
	.4byte 0
	.4byte 0

@ read from type table for each type except ???, entry is 7 byte of length
gUnknown_0856EF14:: @ 856EF14
	.4byte gUnknown_085E8B25
	.4byte gUnknown_085E8B35
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 0
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 7
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 14
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 21
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 28
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 35
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 42
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 49
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 56
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 70
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 77
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 84
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 91
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 98
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 105
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 112
	.4byte gUnknown_085E8B25
	.4byte gTypeNames + 119
	.4byte 0
	.4byte 0

gUnknown_0856EFAC:: @ 856EFAC
	.byte 0x00, 0x01

gUnknown_0856EFAE:: @ 856EFAE
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x05

gUnknown_0856EFB4:: @ 856EFB4
	.byte 0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x00, 0x00

	.align 2
gUnknown_0856EFC8:: @ 856EFC8
	unk_dex_struct gUnknown_0856EE5C, 6, 7, 10
	unk_dex_struct gUnknown_0856EEB4, 8, 9, 11
	unk_dex_struct gUnknown_0856EF14, 10,11, 18
	unk_dex_struct gUnknown_0856EF14, 12, 13, 18
	unk_dex_struct gUnknown_0856EE24, 4, 5, 6
	unk_dex_struct gUnknown_0856EE0C, 2, 3, 2

	.align 2
gUnknown_0856EFF8:: @ 856EFF8
	.4byte 0x000000c8, 0x000010d1, 0x000020ea, 0x000030f3

	.align 2
gUnknown_0856F008:: @ 856F008
	window_template 0x02, 0x00, 0x00, 0x20, 0x14, 0x00, 0x0001
	null_window_template

