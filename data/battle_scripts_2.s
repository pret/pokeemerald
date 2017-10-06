	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattlescriptsForBallThrow:: @ 82DBD08
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD7E
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68
	.4byte gUnknown_082DBD68

	.align 2
gUnknown_082DBD3C:: @ 82DBD3C
	.4byte gUnknown_082DBE12
	.4byte gUnknown_082DBE1C
	.4byte gUnknown_082DBE1C
	.4byte gUnknown_082DBE4B
	.4byte gUnknown_082DBE6F
	.4byte gUnknown_082DBE91

	.align 2
gBattlescriptsForRunningByItem:: @ 82DBD54
	.4byte BattleScript_RunByUsingItem

	.align 2
gBattlescriptsForSafariActions:: @ 82DBD58
	.4byte gUnknown_082DBEBD
	.4byte gUnknown_082DBEC4
	.4byte gUnknown_082DBECD
	.4byte gUnknown_082DBEE3

gUnknown_082DBD68:: @ 82DBD68
	.incbin "baserom.gba", 0x2dbd68, 0x16

gUnknown_082DBD7E:: @ 82DBD7E
	.incbin "baserom.gba", 0x2dbd7e, 0x6

BattleScript_SuccessBallThrow:: @ 82DBD84
	.incbin "baserom.gba", 0x2dbd84, 0x46

BattleScript_WallyBallThrow:: @ 82DBDCA
	.incbin "baserom.gba", 0x2dbdca, 0xa

BattleScript_ShakeBallThrow:: @ 82DBDD4
	.incbin "baserom.gba", 0x2dbdd4, 0x2e

BattleScript_TrainerBallBlock:: @ 82DBE02
	.incbin "baserom.gba", 0x2dbe02, 0x10

gUnknown_082DBE12:: @ 82DBE12
	.incbin "baserom.gba", 0x2dbe12, 0xa

gUnknown_082DBE1C:: @ 82DBE1C
	.incbin "baserom.gba", 0x2dbe1c, 0x2f

gUnknown_082DBE4B:: @ 82DBE4B
	.incbin "baserom.gba", 0x2dbe4b, 0x24

gUnknown_082DBE6F:: @ 82DBE6F
	.incbin "baserom.gba", 0x2dbe6f, 0x22

gUnknown_082DBE91:: @ 82DBE91
	.incbin "baserom.gba", 0x2dbe91, 0x22

BattleScript_RunByUsingItem:: @ 82DBEB3
	.incbin "baserom.gba", 0x2dbeb3, 0xA

gUnknown_082DBEBD:: @ 82DBEBD
	.incbin "baserom.gba", 0x2dbebd, 0x7

gUnknown_082DBEC4:: @ 82DBEC4
	.incbin "baserom.gba", 0x2dbec4, 0x9

gUnknown_082DBECD:: @ 82DBECD
	.incbin "baserom.gba", 0x2dbecd, 0x16

gUnknown_082DBEE3:: @ 82DBEE3
	.incbin "baserom.gba", 0x2dbee3, 0x15
