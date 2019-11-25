@ To be populated with macros for CallBattleTowerFunc

	.macro battletower_getstreak
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_1
	setvar VAR_0x8005, 1
	special CallBattleTowerFunc
	.endm
