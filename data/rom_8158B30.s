	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata


gUnknown_085CE2A0:: @ 85CE2A0
	.incbin "baserom.gba", 0x5ce2a0, 0xb0

gUnknown_085CE350:: @ 85CE350
	.incbin "baserom.gba", 0x5ce350, 0x38

gUnknown_085CE388:: @ 85CE388
	.incbin "baserom.gba", 0x5ce388, 0x18

gUnknown_085CE3A0:: @ 85CE3A0
	.incbin "baserom.gba", 0x5ce3a0, 0x18

gUnknown_085CE3B8:: @ 85CE3B8
	.incbin "baserom.gba", 0x5ce3b8, 0x28

gUnknown_085CE3E0:: @ 85CE3E0
	.incbin "baserom.gba", 0x5ce3e0, 0x50

gUnknown_085CE430:: @ 85CE430
	.incbin "baserom.gba", 0x5ce430, 0x30

gUnknown_085CE460:: @ 85CE460
	.incbin "baserom.gba", 0x5ce460, 0x2c

gUnknown_085CE48C:: @ 85CE48C
	.incbin "baserom.gba", 0x5ce48c, 0x18

gUnknown_085CE4A4:: @ 85CE4A4
	.incbin "baserom.gba", 0x5ce4a4, 0x4

gUnknown_085CE4A8:: @ 85CE4A8
	.incbin "baserom.gba", 0x5ce4a8, 0x8

gUnknown_085CE4B0:: @ 85CE4B0
	.incbin "baserom.gba", 0x5ce4b0, 0x140

gUnknown_085CE5F0:: @ 85CE5F0
	.incbin "baserom.gba", 0x5ce5f0, 0x15c

gUnknown_085CE74C:: @ 85CE74C
	.incbin "baserom.gba", 0x5ce74c, 0x20

gUnknown_085CE76C:: @ 85CE76C
	.incbin "baserom.gba", 0x5ce76c, 0x18

gUnknown_085CE784:: @ 85CE784
	.incbin "baserom.gba", 0x5ce784, 0x68

gUnknown_085CE7EC:: @ 85CE7EC
	.incbin "baserom.gba", 0x5ce7ec, 0x60

gUnknown_085CE84C:: @ 85CE84C
	.incbin "baserom.gba", 0x5ce84c, 0x30

gUnknown_085CE87C:: @ 85CE87C
	.incbin "baserom.gba", 0x5ce87c, 0x14c

gUnknown_085CE9C8:: @ 85CE9C8
	.incbin "baserom.gba", 0x5ce9c8, 0x1e8

gUnknown_085CEBB0:: @ 85CEBB0
	.incbin "baserom.gba", 0x5cebb0, 0x8

gUnknown_085CEBB8:: @ 85CEBB8
	.incbin "baserom.gba", 0x5cebb8, 0x8

gUnknown_085CEBC0:: @ 85CEBC0
	.incbin "baserom.gba", 0x5cebc0, 0x10

gUnknown_085CEBD0:: @ 85CEBD0
	.incbin "baserom.gba", 0x5cebd0, 0x40

gUnknown_085CEC10:: @ 85CEC10
	.incbin "baserom.gba", 0x5cec10, 0x18

gUnknown_085CEC28:: @ 85CEC28
	.incbin "baserom.gba", 0x5cec28, 0x8

sRoamerLocations:: @ 85CEC30
	.incbin "baserom.gba", 0x5cec30, 0x80

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

gUnknown_085DFA60:: @ 85DFA60
	.incbin "baserom.gba", 0x5dfa60, 0x20

gUnknown_085DFA80:: @ 85DFA80
	.incbin "baserom.gba", 0x5dfa80, 0xe0

gUnknown_085DFB60:: @ 85DFB60
	.incbin "baserom.gba", 0x5dfb60, 0xac

gUnknown_085DFC0C:: @ 85DFC0C
	.incbin "baserom.gba", 0x5dfc0c, 0xa4

gUnknown_085DFCB0:: @ 85DFCB0
	.incbin "baserom.gba", 0x5dfcb0, 0x14

gUnknown_085DFCC4:: @ 85DFCC4
	.incbin "baserom.gba", 0x5dfcc4, 0x5

gUnknown_085DFCC9:: @ 85DFCC9
	.incbin "baserom.gba", 0x5dfcc9, 0x3

gUnknown_085DFCCC:: @ 85DFCCC
	.incbin "baserom.gba", 0x5dfccc, 0x10

gUnknown_085DFCDC:: @ 85DFCDC
	.incbin "baserom.gba", 0x5dfcdc, 0x20

gUnknown_085DFCFC:: @ 85DFCFC
	.incbin "baserom.gba", 0x5dfcfc, 0x8

gUnknown_085DFD04:: @ 85DFD04
	.incbin "baserom.gba", 0x5dfd04, 0x14

gUnknown_085DFD18:: @ 85DFD18
	.incbin "baserom.gba", 0x5dfd18, 0x8

gUnknown_085DFD20:: @ 85DFD20
	.incbin "baserom.gba", 0x5dfd20, 0x8

gUnknown_085DFD28:: @ 85DFD28
	.incbin "baserom.gba", 0x5dfd28, 0x34

gUnknown_085DFD5C:: @ 85DFD5C
	.incbin "baserom.gba", 0x5dfd5c, 0x44

gUnknown_085DFDA0:: @ 85DFDA0
	.incbin "baserom.gba", 0x5dfda0, 0x18

gUnknown_085DFDB8:: @ 85DFDB8
	.incbin "baserom.gba", 0x5dfdb8, 0x8
