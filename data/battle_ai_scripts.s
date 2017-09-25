	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattleAI_ScriptsTable:: @ 82DBEF8
	.4byte gBattleScript_82DBF78
	.4byte gBattleScript_82DDE3F
	.4byte gBattleScript_82DC7B0
	.4byte gBattleScript_82DDE71
	.4byte gBattleScript_82DDEDD
	.4byte gBattleScript_82DDEC8
	.4byte gBattleScript_82DDF09
	.4byte gBattleScript_82DDFB4
	.4byte gBattleScript_82DE193
	.4byte gBattleScript_82DE2ED
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE34E
	.4byte gBattleScript_82DE309
	.4byte gBattleScript_82DE337
	.4byte gBattleScript_82DE33E

gBattleScript_82DBF78:: @ 82DBF78
	.incbin "baserom.gba", 0x2dbf78, 0x838

gBattleScript_82DC7B0:: @ 82DC7B0
	.incbin "baserom.gba", 0x2dc7b0, 0x168F

gBattleScript_82DDE3F:: @ 82DDE3F
	.incbin "baserom.gba", 0x2dde3f, 0x32

gBattleScript_82DDE71:: @ 82DDE71
	.incbin "baserom.gba", 0x2dde71, 0x57

gBattleScript_82DDEC8:: @ 82DDEC8
	.incbin "baserom.gba", 0x2ddec8, 0x15

gBattleScript_82DDEDD:: @ 82DDEDD
	.incbin "baserom.gba", 0x2ddedd, 0x2c

gBattleScript_82DDF09:: @ 82DDF09
	.incbin "baserom.gba", 0x2ddf09, 0xab

gBattleScript_82DDFB4:: @ 82DDFB4
	.incbin "baserom.gba", 0x2ddfb4, 0x1df

gBattleScript_82DE193:: @ 82DE193
	.incbin "baserom.gba", 0x2de193, 0x15a

gBattleScript_82DE2ED:: @ 82DE2ED
	.incbin "baserom.gba", 0x2de2ed, 0x1c

gBattleScript_82DE309:: @ 82DE309
	.incbin "baserom.gba", 0x2de309, 0x2e

gBattleScript_82DE337:: @ 82DE337
	.incbin "baserom.gba", 0x2de337, 0x7

gBattleScript_82DE33E:: @ 82DE33E
	.incbin "baserom.gba", 0x2de33e, 0x10

gBattleScript_82DE34E:: @ 82DE34E
	.incbin "baserom.gba", 0x2de34e, 0x2
