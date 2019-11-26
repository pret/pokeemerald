@ To be populated with macros for CallBattlePikeFunction

	.macro battlepike_getstreak
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_DATA
	setvar VAR_0x8005, 1
	special CallBattlePikeFunction
	.endm

	.macro battlepike_setstreak streak:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_DATA
	setvar VAR_0x8005, 1
	.if \streak >= VARS_START
	copyvar VAR_0x8006, \streak
	.else
	setvar VAR_0x8006, \streak
	.endif
	special CallBattlePikeFunction
	.endm

	.macro battlepike_isfinalroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_IS_FINAL_ROOM
	special CallBattlePikeFunction
	.endm

	.macro battlepike_setroomobjects
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_ROOM_OBJECTS
	special CallBattlePikeFunction
	.endm

	.macro battlepike_getroomtype
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_TYPE
	special CallBattlePikeFunction
	.endm

	.macro battlepike_setnextroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_ROOM_TYPE
	special CallBattlePikeFunction
	.endm

	.macro battlepike_gethint
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_TYPE_HINT
	special CallBattlePikeFunction
	.endm

	.macro battlepike_nohealing set:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_HEALING_ROOMS_DISABLED
	setvar VAR_0x8005, \set
	special CallBattlePikeFunction
	.endm

	.macro battlepike_ispartyfullhealth
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_IS_PARTY_FULL_HEALTH
	special CallBattlePikeFunction
	.endm
