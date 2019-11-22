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

@ Apprentice
