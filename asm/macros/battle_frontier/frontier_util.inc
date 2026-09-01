	@ Get the status (CHALLENGE_STATUS_*) of the current challenge and store the result in VAR_TEMP_CHALLENGE_STATUS
	.macro frontier_getstatus
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_STATUS
	special CallFrontierUtilFunc
	.endm

	@ Get the value of some FRONTIER_DATA_*. See GetFrontierData for the data types that can be retrieved
	.macro frontier_get data:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallFrontierUtilFunc
	.endm

	@ Set the value of some FRONTIER_DATA_*. Some data types do not need a val argument because the value is set directly from somewhere else. See SetFrontierData for the data types that can be set
	.macro frontier_set data:req, val=0xFFFF
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val == 0xFFFF
	@ no value provided
	.elseif \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallFrontierUtilFunc
	.endm

	@ Load the selected mons into gSelectedOrderFromParty and reduce the players party to these mons
	.macro frontier_setpartyorder partySize:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, \partySize
	special CallFrontierUtilFunc
	.endm

	@ Performs a soft reset
	.macro frontier_reset
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SOFT_RESET
	special CallFrontierUtilFunc
	.endm

	@ Loads gBattleFrontierTrainers into gFacilityTrainers
	.macro frontier_settrainers
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_TRAINERS
	special CallFrontierUtilFunc
	.endm

	@ Sets the selected party mons in the saveblock
	.macro frontier_saveparty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
	special CallFrontierUtilFunc
	.endm

	@ Shows the results window for the given facility and mode. Facilities with only 1 mode dont provide the mode argument
	.macro frontier_results facility:req, mode=0xFF
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESULTS_WINDOW
	setvar VAR_0x8005, \facility
	.if \mode != 0xFF
	setvar VAR_0x8006, \mode
	.endif
	special CallFrontierUtilFunc
	.endm

	@ Checks if the Battle Frontier TV special should air, and if so attempts to set it up
	.macro frontier_checkairshow
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_AIR_TV_SHOW
	special CallFrontierUtilFunc
	.endm

	@ Get the status of the Frontier Brain (Not ready, Silver/Gold streak before symbols, Silver/Gold streak after symbols)
	.macro frontier_getbrainstatus
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_BRAIN_STATUS
	special CallFrontierUtilFunc
	.endm

	@ TRUE if the opponent is a Frontier Brain, FALSE otherwise
	.macro frontier_isbrain
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_IS_BRAIN
	special CallFrontierUtilFunc
	.endm

	@ Awards battle points depending on the current challenge
	.macro frontier_givepoints
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_BATTLE_POINTS
	special CallFrontierUtilFunc
	.endm

	@ Returns 0-2 for the number of facility symbols the player has
	.macro frontier_getsymbols
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS
	special CallFrontierUtilFunc
	.endm

	@ Awards a frontier symbol depending on the current challenge
	.macro frontier_givesymbol
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL
	special CallFrontierUtilFunc
	.endm

	@ TRUE if the given battleType is set in gBattleTypeFlags, FALSE otherwise
	.macro frontier_isbattletype battleType:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_BATTLE_TYPE
	setvar VAR_0x8005, \battleType
	special CallFrontierUtilFunc
	.endm

	@ TRUE if there are insufficient eligible party mons to participate in the challenge, and buffers caught ineligible species to STR_VAR_1. FALSE otherwise. The return value is stored in VAR_0x8004 instead, and the current level mode is expected to be in VAR_RESULT
	.macro frontier_checkineligible
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_INELIGIBLE
	special CallFrontierUtilFunc
	.endm

	@ Validates the visiting E-Reader trainer. 0 if valid, 1 if not
	.macro frontier_checkvisittrainer
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_VISIT_TRAINER
	special CallFrontierUtilFunc
	.endm

	@ Increments the current win streak by 1
	.macro frontier_incrementstreak
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_INCREMENT_STREAK
	special CallFrontierUtilFunc
	.endm

	@ Resets the party held items to what they were upon entering the challenge
	.macro frontier_restorehelditems
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESTORE_HELD_ITEMS
	special CallFrontierUtilFunc
	.endm

	@ Move the recorded battle to save data
	.macro frontier_savebattle
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_BATTLE
	special CallFrontierUtilFunc
	.endm

	@ Buffer the name of gTrainerBattleParameter.params.opponentA in STR_VAR_1 (0) or STR_VAR_2 (1)
	.macro frontier_gettrainername stringVar:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_BUFFER_TRAINER_NAME
	.if \stringVar == STR_VAR_1
		setvar VAR_0x8005, 0
	.elseif \stringVar == STR_VAR_2
		setvar VAR_0x8005, 1
	.else
		setvar VAR_0x8005, \stringVar
	.endif
	special CallFrontierUtilFunc
	.endm

	@ If any moves were copied using Sketch during the challenge then restore them to Sketch
	.macro frontier_resetsketch
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESET_SKETCH_MOVES
	special CallFrontierUtilFunc
	.endm

	@ Set the object event gfx of the Frontier Brain for the current facility
	.macro frontier_setbrainobj
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_BRAIN_OBJECT
	special CallFrontierUtilFunc
	.endm
