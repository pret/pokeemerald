	@ Initialize the Battle Arena challenge
	.macro arena_init
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_INIT
	special CallBattleArenaFunction
	.endm

	@ Unused. Get the value of some ARENA_DATA_*. See GetArenaData for the data types that can be retrieved
	.macro arena_get data:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleArenaFunction
	.endm

	@ Set some ARENA_DATA_* to val. See SetArenaData for the data types that can be set
	.macro arena_set data:req, val:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattleArenaFunction
	.endm

	@ Save the game and set the challenge status
	.macro arena_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleArenaFunction
	.endm

	@ Unused. Set the prize item to give from one of two lists of possible prizes, depending on streak.
	.macro arena_setprize
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SET_PRIZE
	special CallBattleArenaFunction
	.endm

	@ Unused. Give the set prize item to the player. TRUE if room in Bag for prize, FALSE otherwise
	.macro arena_giveprize
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_GIVE_PRIZE
	special CallBattleArenaFunction
	.endm

	@ Buffer the opponents name to STR_VAR_1
	.macro arena_gettrainername
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_GET_TRAINER_NAME
	special CallBattleArenaFunction
	.endm
