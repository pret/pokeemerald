#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 85CECB0
	.include "data/battle_frontier/battle_frontier_held_items.inc"

@ 85CED2E
	.include "data/battle_frontier/battle_frontier_trainer_mons.inc"

@ 85D5ACC
	.include "data/battle_frontier/battle_frontier_trainers.inc"

@ 85D97BC
	.include "data/battle_frontier/battle_frontier_mons.inc"

gUnknown_085DCEDC:: @ 85DCEDC
	.incbin "baserom.gba", 0x5dcedc, 0x1e

gUnknown_085DCEFA:: @ 85DCEFA
	.incbin "baserom.gba", 0x5dcefa, 0x14

gUnknown_085DCF0E:: @ 85DCF0E
	.incbin "baserom.gba", 0x5dcf0e, 0x1e

gUnknown_085DCF2C:: @ 85DCF2C
	.incbin "baserom.gba", 0x5dcf2c, 0x14

gUnknown_085DCF40:: @ 85DCF40
	.incbin "baserom.gba", 0x5dcf40, 0x5c0

gUnknown_085DD500:: @ 85DD500
	.incbin "baserom.gba", 0x5dd500, 0x190

gUnknown_085DD690:: @ 85DD690
	.incbin "baserom.gba", 0x5dd690, 0x40

gUnknown_085DD6D0:: @ 85DD6D0
	.incbin "baserom.gba", 0x5dd6d0, 0x5

gUnknown_085DD6D5:: @ 85DD6D5
	.incbin "baserom.gba", 0x5dd6d5, 0x7

gUnknown_085DD6DC:: @ 85DD6DC
	.incbin "baserom.gba", 0x5dd6dc, 0x30

@ 85DD70C
	.include "data/battle_frontier/slateport_battle_tent_trainer_mons.inc"

@ 85DDA14
	.include "data/battle_frontier/slateport_battle_tent_trainers.inc"

@ 85DE02C
	.include "data/battle_frontier/slateport_battle_tent_mons.inc"

@ 85DE48C
	.include "data/battle_frontier/verdanturf_battle_tent_trainer_mons.inc"

@ 85DE610
	.include "data/battle_frontier/verdanturf_battle_tent_trainers.inc"

@ 85DEC28
	.include "data/battle_frontier/verdanturf_battle_tent_mons.inc"

@ 85DEEF8
	.include "data/battle_frontier/fallarbor_battle_tent_trainer_mons.inc"

@ 85DF084
	.include "data/battle_frontier/fallarbor_battle_tent_trainers.inc"

@ 85DF69C
	.include "data/battle_frontier/fallarbor_battle_tent_mons.inc"

gUnknown_085DF96C:: @ 85DF96C
	.incbin "baserom.gba", 0x5df96c, 0x40

gUnknown_085DF9AC:: @ 85DF9AC
	.incbin "baserom.gba", 0x5df9ac, 0x20

gUnknown_085DF9CC:: @ 85DF9CC
	.incbin "baserom.gba", 0x5df9cc, 0x20

gUnknown_085DF9EC:: @ 85DF9EC
	.incbin "baserom.gba", 0x5df9ec, 0xa

gUnknown_085DF9F6:: @ 85DF9F6
	.incbin "baserom.gba", 0x5df9f6, 0x4

gUnknown_085DF9FA:: @ 85DF9FA
	.incbin "baserom.gba", 0x5df9fa, 0x20

gUnknown_085DFA1A:: @ 85DFA1A
	.incbin "baserom.gba", 0x5dfa1a, 0x28

gUnknown_085DFA42:: @ 85DFA42
	.incbin "baserom.gba", 0x5dfa42, 0x4

gUnknown_085DFA46:: @ 85DFA46
	.incbin "baserom.gba", 0x5dfa46, 0xc

gUnknown_085DFA52:: @ 85DFA52
	.incbin "baserom.gba", 0x5dfa52, 0xe
