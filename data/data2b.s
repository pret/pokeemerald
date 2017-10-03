@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2


gUnknown_082FECFC:: @ 82FECFC
	.incbin "baserom.gba", 0x2fecfc, 0x40

gUnknown_082FED3C:: @ 82FED3C
	.incbin "baserom.gba", 0x2fed3c, 0x1b4

gUnknown_082FEEF0:: @ 82FEEF0
	.incbin "baserom.gba", 0x2feef0, 0x128

gUnknown_082FF018:: @ 82FF018
	.incbin "baserom.gba", 0x2ff018, 0x2

gUnknown_082FF01A:: @ 82FF01A
	.incbin "baserom.gba", 0x2ff01a, 0xe

gUnknown_082FF028:: @ 82FF028
	.incbin "baserom.gba", 0x2ff028, 0x10

gUnknown_082FF038:: @ 82FF038
	.incbin "baserom.gba", 0x2ff038, 0x10

gUnknown_082FF048:: @ 82FF048
	.incbin "baserom.gba", 0x2ff048, 0x28

gUnknown_082FF070:: @ 82FF070
	.incbin "baserom.gba", 0x2ff070, 0x10

gUnknown_082FF080:: @ 82FF080
	.incbin "baserom.gba", 0x2ff080, 0x8

gUnknown_082FF088:: @ 82FF088
	.incbin "baserom.gba", 0x2ff088, 0x18

gUnknown_082FF0A0:: @ 82FF0A0
	.incbin "baserom.gba", 0x2ff0a0, 0x20

gUnknown_082FF0C0:: @ 82FF0C0
	.incbin "baserom.gba", 0x2ff0c0, 0x20

gUnknown_082FF0E0:: @ 82FF0E0
	.incbin "baserom.gba", 0x2ff0e0, 0x3

gUnknown_082FF0E3:: @ 82FF0E3
	.incbin "baserom.gba", 0x2ff0e3, 0x5

gUnknown_082FF0E8:: @ 82FF0E8
	.incbin "baserom.gba", 0x2ff0e8, 0x8

gUnknown_082FF0F0:: @ 82FF0F0
	.incbin "baserom.gba", 0x2ff0f0, 0x4

gUnknown_082FF0F4:: @ 82FF0F4
	.incbin "baserom.gba", 0x2ff0f4, 0x20

gUnknown_082FF114:: @ 82FF114
	.incbin "baserom.gba", 0x2ff114, 0x4

gUnknown_082FF118:: @ 82FF118
	.incbin "baserom.gba", 0x2ff118, 0x10

gUnknown_082FF128:: @ 82FF128
	.incbin "baserom.gba", 0x2ff128, 0x50

gUnknown_082FF178:: @ 82FF178
	.incbin "baserom.gba", 0x2ff178, 0x50

gUnknown_082FF1C8:: @ 82FF1C8
	.incbin "baserom.gba", 0x2ff1c8, 0x10

gUnknown_082FF1D8:: @ 82FF1D8
	.incbin "baserom.gba", 0x2ff1d8, 0x20

gUnknown_082FF1F8:: @ 82FF1F8
	.incbin "baserom.gba", 0x2ff1f8, 0x420

gUnknown_082FF618:: @ 82FF618
	.incbin "baserom.gba", 0x2ff618, 0x7c

gUnknown_082FF694:: @ 82FF694
	.incbin "baserom.gba", 0x2ff694, 0x2c

gUnknown_082FF6C0:: @ 82FF6C0
	.incbin "baserom.gba", 0x2ff6c0, 0x4c

gUnknown_082FF70C:: @ 82FF70C
	.incbin "baserom.gba", 0x2ff70c, 0x162c

gUnknown_08300D38:: @ 8300D38
	.incbin "baserom.gba", 0x300d38, 0x6e0

@ 8301418
	.include "data/graphics/pokemon/mon_still_front_pic_table.inc"

gUnknown_083021D8:: @ 83021D8
	.incbin "baserom.gba", 0x3021d8, 0x6e0

@ 83028B8
	.include "data/graphics/pokemon/mon_back_pic_table.inc"

@ 8303678
	.include "data/graphics/pokemon/mon_palette_table.inc"

@ 8304438
	.include "data/graphics/pokemon/mon_shiny_palette_table.inc"

@ 83051F8
	.incbin "baserom.gba", 0x3051f8, 0x174

gUnknown_0830536C:: @ 830536C
	.incbin "baserom.gba", 0x30536c, 0x174

gUnknown_083054E0:: @ 83054E0
	.incbin "baserom.gba", 0x3054e0, 0x174

@ 8305654
	.include "data/graphics/trainers/trainer_front_pic_table.inc"

@ 830593C
	.include "data/graphics/trainers/trainer_front_pic_palette_table.inc"

@ 8305C24
	.incbin "baserom.gba", 0x305c24, 0xe8

gUnknown_08305D0C:: @ 8305D0C
	.incbin "baserom.gba", 0x305d0c, 0x20

gUnknown_08305D2C:: @ 8305D2C
	.incbin "baserom.gba", 0x305d2c, 0x20

@ 8305D4C
	.include "data/graphics/trainers/trainer_back_pic_table.inc"

@ 8305D8C
	.include "data/graphics/trainers/trainer_back_pic_palette_table.inc"

gUnknown_08305DCC:: @ 8305DCC
	.incbin "baserom.gba", 0x305dcc, 0x3ce0

gUnknown_08309AAC:: @ 8309AAC
	.incbin "baserom.gba", 0x309aac, 0x6e0

@ 830A18C
	.include "data/graphics/pokemon/mon_front_pic_table.inc"

@ 830AF4C
	.incbin "baserom.gba", 0x30af4c, 0x6e0

@ 830B62C
	.include "data/trainer_parties.inc"

@ 830FCD4
	.include "data/text/trainer_class_names.inc"

@ 8310030
	.include "data/trainers.inc"

@ 83185C8
	.include "data/text/species_names.inc"

@ 831977C
	.include "data/text/move_names.inc"

	.incbin "baserom.gba", 0x31a983, 0x4d

gUnknown_0831A9D0:: @ 831A9D0
	.incbin "baserom.gba", 0x31a9d0, 0x18

gUnknown_0831A9E8:: @ 831A9E8
	.incbin "baserom.gba", 0x31a9e8, 0x18

gUnknown_0831AA00:: @ 831AA00
	.incbin "baserom.gba", 0x31aa00, 0x8

gUnknown_0831AA08:: @ 831AA08
	.incbin "baserom.gba", 0x31aa08, 0x198

gUnknown_0831ABA0:: @ 831ABA0
	.incbin "baserom.gba", 0x31aba0, 0x8

gUnknown_0831ABA8:: @ 831ABA8
	.incbin "baserom.gba", 0x31aba8, 0xc8

gUnknown_0831AC70:: @ 831AC70
	.incbin "baserom.gba", 0x31ac70, 0x18

gUnknown_0831AC88:: @ 831AC88
	.incbin "baserom.gba", 0x31ac88, 0x18

gUnknown_0831ACA0:: @ 831ACA0
	.incbin "baserom.gba", 0x31aca0, 0x40

gUnknown_0831ACE0:: @ 831ACE0
	.incbin "baserom.gba", 0x31ace0, 0x8

gTypeEffectiveness:: @ 831ACE8
	.incbin "baserom.gba", 0x31ace8, 0x150

@ 831AE38
	.include "data/text/type_names.inc"

	.align 2
gTrainerMoneyTable:: @ 831AEB8
	.incbin "baserom.gba", 0x31aeb8, 0xe0

@ 831AF98
	.include "data/text/ability_descriptions.inc"

@ 831B6DB
	.include "data/text/ability_names.inc"

@ 831BAD4
	.include "data/text/ability_description_pointers.inc"

gUnknown_0831BC0C:: @ 831BC0C
	.incbin "baserom.gba", 0x31bc0c, 0x38

gUnknown_0831BC44:: @ 831BC44
	.incbin "baserom.gba", 0x31bc44, 0x2c

gStatusConditionString_PoisonJpn:: @ 831BC70
	.incbin "baserom.gba", 0x31bc70, 0x8

gStatusConditionString_SleepJpn:: @ 831BC78
	.incbin "baserom.gba", 0x31bc78, 0x8

gStatusConditionString_ParalysisJpn:: @ 831BC80
	.incbin "baserom.gba", 0x31bc80, 0x8

gStatusConditionString_BurnJpn:: @ 831BC88
	.incbin "baserom.gba", 0x31bc88, 0x8

gStatusConditionString_IceJpn:: @ 831BC90
	.incbin "baserom.gba", 0x31bc90, 0x8

gStatusConditionString_ConfusionJpn:: @ 831BC98
	.incbin "baserom.gba", 0x31bc98, 0x8

gStatusConditionString_LoveJpn:: @ 831BCA0
	.incbin "baserom.gba", 0x31bca0, 0x8

gUnknown_0831BCA8:: @ 831BCA8
	.incbin "baserom.gba", 0x31bca8, 0x38

gUnknown_0831BCE0:: @ 831BCE0
	.incbin "baserom.gba", 0x31bce0, 0xf

gUnknown_0831BCEF:: @ 831BCEF
	.incbin "baserom.gba", 0x31bcef, 0x4

gUnknown_0831BCF3:: @ 831BCF3
	.incbin "baserom.gba", 0x31bcf3, 0x5

gSoundMovesTable:: @ 831BCF8
	.incbin "baserom.gba", 0x31bcf8, 0x18

