@ Frontier Util

.macro frontier_checkoutcome
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_STATUS
special CallFrontierUtilFunc
.endm

.macro frontier_getchallengestatus
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
setvar VAR_0x8005, 0
special CallFrontierUtilFunc
.endm

.macro frontier_setchallengestatus status:req
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA
setvar VAR_0x8005, 0
setvar VAR_0x8006, \status
special CallFrontierUtilFunc
.endm

.macro frontier_getlvlmode
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
setvar VAR_0x8005, 1
special CallFrontierUtilFunc
.endm

.macro frontier_setlvlmode lvlmode:req
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA
setvar VAR_0x8005, 1
setvar VAR_0x8006, \lvlmode
special CallFrontierUtilFunc
.endm

.macro frontier_getbattlenum
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
setvar VAR_0x8005, 2
special CallFrontierUtilFunc
.endm

.macro frontier_setbattlenum battleNum:req
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA
setvar VAR_0x8005, 2
copyvar VAR_0x8006, \battleNum
special CallFrontierUtilFunc
.endm

.macro frontier_getbattleoutcome
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
setvar VAR_0x8005, 5
special CallFrontierUtilFunc
.endm

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

.macro frontier_loadselectedmons
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_LOAD_SELECTED_PARTY
setvar VAR_0x8005, FRONTIER_PARTY_SIZE
special CallFrontierUtilFunc
.endm

@ Facilities with only 1 mode dont provide the mode argument
.macro frontier_results facility:req, mode=0xFF
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESULTS_WINDOW
setvar VAR_0x8005, \facility
.if \mode != 0xFF
setvar VAR_0x8006, \mode
.endif
special CallFrontierUtilFunc
.endm

.macro frontier_getbrainstatus
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_BRAIN_STATUS
special CallFrontierUtilFunc
.endm

.macro frontier_resetsketch
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESET_SKETCH_MOVES
special CallFrontierUtilFunc
.endm


@ Battle Tower

.macro battletower_getstreak
setvar VAR_0x8004, BATTLE_TOWER_FUNC_1
setvar VAR_0x8005, 1
special CallBattleTowerFunc
.endm


@ Battle Dome


@ Battle Palace


@ Battle Arena


@ Battle Factory


@ Battle Pike

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

@ Battle Pyramid

@ Battle Tent

@ Trainer Hill

@ Apprentice

.macro apprentice_gavelvlmode
setvar VAR_0x8004, APPRENTICE_FUNC_GAVE_LVLMODE
special CallApprenticeFunction
.endm

.macro apprentice_setlvlmode lvlmode:req
setvar VAR_0x8004, APPRENTICE_FUNC_SET_LVLMODE
setorcopyvar VAR_0x8005, \lvlmode
addvar VAR_0x8005, 1
special CallApprenticeFunction
.endm

.macro apprentice_answeredquestion
setvar VAR_0x8004, APPRENTICE_FUNC_ANSWERED_QUESTION
special CallApprenticeFunction
.endm

.macro apprentice_menu  which:req
setvar VAR_0x8004, APPRENTICE_FUNC_MENU
setvar VAR_0x8005, \which
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_shufflespecies
setvar VAR_0x8004, APPRENTICE_FUNC_SHUFFLE_SPECIES
special CallApprenticeFunction
.endm

.macro apprentice_randomizequestions
setvar VAR_0x8004, APPRENTICE_FUNC_RANDOMIZE_QUESTIONS
special CallApprenticeFunction
.endm

.macro apprentice_msg  waitbuttonpress:req, which:req
setvar VAR_0x8004, APPRENTICE_FUNC_PRINT_MSG
setvar VAR_0x8005, \waitbuttonpress
setvar VAR_0x8006, \which
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_reset
setvar VAR_0x8004, APPRENTICE_FUNC_RESET
special CallApprenticeFunction
.endm

.macro apprentice_shouldcheckgone
setvar VAR_0x8004, APPRENTICE_FUNC_CHECK_GONE
special CallApprenticeFunction
.endm

.macro apprentice_getquestion
setvar VAR_0x8004, APPRENTICE_FUNC_GET_QUESTION
special CallApprenticeFunction
.endm

.macro apprentice_getnumpartymons
setvar VAR_0x8004, APPRENTICE_FUNC_GET_NUM_PARTY_MONS
special CallApprenticeFunction
.endm

.macro apprentice_setpartymon  slot:req
copyvar VAR_0x8006, \slot
setvar VAR_0x8004, APPRENTICE_FUNC_SET_PARTY_MON
special CallApprenticeFunction
.endm

.macro apprentice_initquestion  which:req
setvar VAR_0x8004, APPRENTICE_FUNC_INIT_QUESTION_DATA
setvar VAR_0x8005, \which
special CallApprenticeFunction
.endm

.macro apprentice_freequestion
setvar VAR_0x8004, APPRENTICE_FUNC_FREE_QUESTION_DATA
special CallApprenticeFunction
.endm

.macro apprentice_buff  whichstringvar:req, tobuff:req
setvar VAR_0x8004, APPRENTICE_FUNC_BUFFER_STRING
setvar VAR_0x8005, \whichstringvar
.if \tobuff >= VARS_START
copyvar VAR_0x8006, \tobuff
.else
setvar VAR_0x8006, \tobuff
.endif
special CallApprenticeFunction
.endm

.macro apprentice_setmove
setvar VAR_0x8004, APPRENTICE_FUNC_SET_MOVE
special CallApprenticeFunction
.endm

.macro apprentice_setleadmon  monId:req
copyvar VAR_0x8005, \monId
setvar VAR_0x8004, APPRENTICE_FUNC_SET_LEAD_MON
special CallApprenticeFunction
.endm

.macro apprentice_openbag
setvar VAR_0x8004, APPRENTICE_FUNC_OPEN_BAG
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_trysetitem
setvar VAR_0x8004, APPRENTICE_FUNC_TRY_SET_HELD_ITEM
special CallApprenticeFunction
.endm

.macro apprentice_save
setvar VAR_0x8004, APPRENTICE_FUNC_SAVE
special CallApprenticeFunction
.endm

.macro apprentice_setgfx
setvar VAR_0x8004, APPRENTICE_FUNC_SET_GFX
special CallApprenticeFunction
.endm

.macro apprentice_shouldleave
setvar VAR_0x8004, APPRENTICE_FUNC_SHOULD_LEAVE
special CallApprenticeFunction
.endm

.macro apprentice_shiftsaved
setvar VAR_0x8004, APPRENTICE_FUNC_SHIFT_SAVED
special CallApprenticeFunction
.endm
