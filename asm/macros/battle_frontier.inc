@ To be populated with macros for the Battle Frontier CallFacilityFunction specials


@ Frontier Util

.macro frontier_setlvlmode lvlmode:req
setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
setvar VAR_0x8005, 1
setvar VAR_0x8006, \lvlmode
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

.macro apprentice_3
setvar VAR_0x8004, APPRENTICE_FUNC_3
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
setvar VAR_0x8006, \tobuff
special CallApprenticeFunction
.endm

.macro apprentice_buffv  whichstringvar:req tobuff:req
setvar VAR_0x8004, APPRENTICE_FUNC_BUFFER_STRING
setvar VAR_0x8005, \whichstringvar
copyvar VAR_0x8006, \tobuff
special CallApprenticeFunction
.endm

.macro apprentice_setmove
setvar VAR_0x8004, APPRENTICE_FUNC_SET_MOVE
special CallApprenticeFunction
.endm

.macro apprentice_setfirstmon  monId:req
copyvar VAR_0x8005, \monId
setvar VAR_0x8004, APPRENTICE_FUNC_SET_FIRST_MON
special CallApprenticeFunction
.endm

.macro apprentice_openbag
setvar VAR_0x8004, APPRENTICE_FUNC_OPEN_BAG
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_setgfx
setvar VAR_0x8004, APPRENTICE_FUNC_SET_GFX
special CallApprenticeFunction
.endm

.macro apprentice_shouldleave
setvar VAR_0x8004, APPRENTICE_FUNC_SHOULD_LEAVE
special CallApprenticeFunction
.endm
