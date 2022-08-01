	@ Initialize the Battle Tower challenge
	.macro tower_init
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_INIT
	special CallBattleTowerFunc
	.endm

	@ Get the value of some TOWER_DATA_*. See GetTowerData for the data types that can be retrieved
	.macro tower_get data:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleTowerFunc
	.endm

	@ Set some TOWER_DATA_* to val. See SetTowerData for the data types that can be set
	.macro tower_set data:req, val=0xFFFF
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallBattleTowerFunc
	.endm

	@ Choose and set the gfx for the next opponent. Also used by Battle Tents
	.macro tower_setopponent
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT
	special CallBattleTowerFunc
	.endm

	@ Increments the battle number and returns the new one. Also clears E-Reader trainer if defeated, and saves the current win streak
	.macro tower_setbattlewon
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_BATTLE_WON
	special CallBattleTowerFunc
	.endm

	@ Try to award ribbons for completing 56th straight Battle Tower win. VAR_RESULT is TRUE if ribbons were awarded.
	.macro tower_giveribbons
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GIVE_RIBBONS
	special CallBattleTowerFunc
	.endm

	@ Save the game and set the challenge status
	.macro tower_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleTowerFunc
	.endm

	@ Buffer the opponent's easy chat intro speech to STR_VAR_4
	.macro tower_getopponentintro opponent:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GET_OPPONENT_INTRO
	setvar VAR_0x8005, \opponent
	special CallBattleTowerFunc
	.endm
	
	@ This acts like old tower_getopponentintro, but tower_getopponentintro was changed in the French version.
	.macro tower_getopponentintro2 opponent:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GET_OPPONENT_INTRO2
	setvar VAR_0x8005, \opponent
	special CallBattleTowerFunc
	.endm

	@ Load the parties, gfx, and other data (like Apprentice id) for the multi partner candidates
	.macro tower_loadpartners
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_LOAD_PARTNERS
	special CallBattleTowerFunc
	.endm

	@ Print message from potential multi partner. msgId is any PARTNER_MSGID_*
	.macro tower_dopartnermsg msgId:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_PARTNER_MSG
	setvar VAR_0x8005, \msgId
	special CallBattleTowerFunc
	.endm

	@ Receives/loads the opponent data for a link multi challenge. Returns 6 when finished, and finishes immediately if not doing a link multi battle.
	.macro tower_loadlinkopponents
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_LOAD_LINK_OPPONENTS
	special CallBattleTowerFunc
	.endm

	@ Attempts to close link connection. Used when finishing a link multi challenge.
	.macro tower_closelink
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_TRY_CLOSE_LINK
	special CallBattleTowerFunc
	.endm

	@ Set VAR_OBJ_GFX_ID_E to the gfx id of the selected multi partner
	.macro tower_setpartnergfx
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_PARTNER_GFX
	special CallBattleTowerFunc
	.endm

	@ Set the data used for the post-challenge Battle Tower interview
	.macro tower_setinterviewdata
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_INTERVIEW_DATA
	special CallBattleTowerFunc
	.endm
