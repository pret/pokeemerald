@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2


@ 831C898
	.include "data/battle_moves.inc"

	@ 0x31d93c unreferenced unknown data
.byte 0x34, 0x00, 0x10, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00

@ 831D94C
	.include "data/pokedex_order.inc"

@ 831E2F0
	.include "data/spinda_spot_graphics.inc"

@ 831E380
	.include "data/item_effect_info.inc"

@ 831E818
	.include "data/nature_stat_table.inc"

@ 831E898
	.include "data/tm_hm_learnsets.inc"

@ 831F578
	.include "data/trainer_pic_indices.inc"

@ 831F5CA
	.include "data/trainer_class_name_indices.inc"

@ 831F61C
	.include "data/cry_id_table.inc"

@ 831F72C
	.include "data/experience_tables.inc"

@ 83203CC
	.include "data/base_stats.inc"

@ 83230DC
	.include "data/level_up_learnsets.inc"

@ 832531C
	.include "data/evolution_table.inc"

@ 832937C
	.include "data/level_up_learnset_pointers.inc"

gUnknown_083299EC:: @ 83299EC
	.incbin "baserom.gba", 0x3299ec, 0x19b

gUnknown_08329B87:: @ 8329B87
	.incbin "baserom.gba", 0x329b87, 0x19b

gUnknown_08329D22:: @ 8329D22
	.incbin "baserom.gba", 0x329d22, 0x4

gUnknown_08329D26:: @ 8329D26
	.incbin "baserom.gba", 0x329d26, 0x4

gUnknown_08329D2A:: @ 8329D2A
	.incbin "baserom.gba", 0x329d2a, 0x4

gStatStageRatios:: @ 8329D2E
	.incbin "baserom.gba", 0x329d2e, 0x1a

gUnknown_08329D48:: @ 8329D48
	.incbin "baserom.gba", 0x329d48, 0xc

gUnknown_08329D54:: @ 8329D54
	.incbin "baserom.gba", 0x329d54, 0x20

gHoldEffectToType:: @ 8329D74
	.incbin "baserom.gba", 0x329d74, 0x24

gUnknown_08329D98:: @ 8329D98
	.incbin "baserom.gba", 0x329d98, 0x60

gUnknown_08329DF8:: @ 8329DF8
	.incbin "baserom.gba", 0x329df8, 0xc0

gSecretBaseTrainerClasses:: @ 8329EB8
	.incbin "baserom.gba", 0x329eb8, 0xa

gUnknown_08329EC2:: @ 8329EC2
	.incbin "baserom.gba", 0x329ec2, 0x6

gUnknown_08329EC8:: @ 8329EC8
	.incbin "baserom.gba", 0x329ec8, 0x6

gUnknown_08329ECE:: @ 8329ECE
	.incbin "baserom.gba", 0x329ece, 0x1c

gUnknown_08329EEA:: @ 8329EEA
	.incbin "baserom.gba", 0x329eea, 0x12

gUnknown_08329EFC:: @ 8329EFC
	.incbin "baserom.gba", 0x329efc, 0x2

gUnknown_08329EFE:: @ 8329EFE
	.incbin "baserom.gba", 0x329efe, 0x2a

gUnknown_08329F28:: @ 8329F28
	.incbin "baserom.gba", 0x329f28, 0x18
