@ TODO: Add explanatory comments to macros

	@
	.macro pike_setnextroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_ROOM_TYPE
	special CallBattlePikeFunction
	.endm

	@ Get the value of some PIKE_DATA_*. See GetBattlePikeData for the data types that can be retrieved
	.macro pike_get data:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattlePikeFunction
	.endm

	@ Set some PIKE_DATA_* to val. See SetBattlePikeData for the data types that can be set
	.macro pike_set data:req, val:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_isfinalroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_IS_FINAL_ROOM
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_setroomobjects
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_ROOM_OBJECTS
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_getroomtype
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_TYPE
	special CallBattlePikeFunction
	.endm

	@ Sets a bool that's never read
	.macro pike_inwildmonroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_IN_WILD_MON_ROOM
	special CallBattlePikeFunction
	.endm

	@ Clears a bool that's never read
	.macro pike_exitwildmonroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_CLEAR_IN_WILD_MON_ROOM
	special CallBattlePikeFunction
	.endm

	@ Save the game and set the challenge status
	.macro pike_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_getstatus
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_STATUS
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_getstatusmon
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_STATUS_MON
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_healonetwomons
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_HEAL_ONE_TWO_MONS
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_getnpcmsg
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_BUFFER_NPC_MSG
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_fadescreen
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_STATUS_SCREEN_FADE
	special CallBattlePikeFunction
	.endm

	@ TRUE if the player is currently in a Battle Pike challenge map
	.macro pike_inchallenge
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_IS_IN
	special CallBattlePikeFunction
	.endm

	@ TRUE if its the Pike Queens room
	.macro pike_sethintroom
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_HINT_ROOM
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_gethintroomid
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_HINT_ROOM_ID
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_gethint
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_ROOM_TYPE_HINT
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_cleartrainerids
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_CLEAR_TRAINER_IDS
	special CallBattlePikeFunction
	.endm

	@ 
	.macro pike_gettrainerintro trainer:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_TRAINER_INTRO
	setvar VAR_0x8005, \trainer
	special CallBattlePikeFunction
	.endm

	@ Get the status of the Pike Queen (Not ready, Silver/Gold streak before symbols, Silver/Gold streak after symbols)
	.macro pike_getbrainstatus
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_GET_QUEEN_FIGHT_TYPE
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_prequeenheal
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_HEAL_MONS_BEFORE_QUEEN
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_nohealing set:req
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SET_HEAL_ROOMS_DISABLED
	setvar VAR_0x8005, \set
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_ispartyfullhealth
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_IS_PARTY_FULL_HEALTH
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_savehelditems
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_SAVE_HELD_ITEMS
	special CallBattlePikeFunction
	.endm

	@
	.macro pike_resethelditems
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_RESET_HELD_ITEMS
	special CallBattlePikeFunction
	.endm

	@ Initialize the Battle Pike challenge
	.macro pike_init
	setvar VAR_0x8004, BATTLE_PIKE_FUNC_INIT
	special CallBattlePikeFunction
	.endm
