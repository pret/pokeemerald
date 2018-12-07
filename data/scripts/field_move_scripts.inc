PetalburgWoods_EventScript_2906BB:: @ 82906BB
Route103_EventScript_2906BB:: @ 82906BB
Route104_EventScript_2906BB:: @ 82906BB
Route110_TrickHousePuzzle1_EventScript_2906BB:: @ 82906BB
Route111_EventScript_2906BB:: @ 82906BB
Route116_EventScript_2906BB:: @ 82906BB
Route117_EventScript_2906BB:: @ 82906BB
Route118_EventScript_2906BB:: @ 82906BB
Route120_EventScript_2906BB:: @ 82906BB
Route121_EventScript_2906BB:: @ 82906BB
Route123_EventScript_2906BB:: @ 82906BB
	lockall
	checkflag FLAG_BADGE01_GET
	goto_if 0, Route103_EventScript_290721
	checkpartymove MOVE_CUT
	compare VAR_RESULT, 6
	goto_eq Route103_EventScript_290721
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_CUT
	msgbox Route103_Text_29072E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq Route103_EventScript_29072B
	msgbox Route103_Text_290771, MSGBOX_DEFAULT
	closemessage
	dofieldeffect 2
	waitstate
	goto Route103_EventScript_290710
	end

Route103_EventScript_290705:: @ 8290705
	lockall
	dofieldeffect 2
	waitstate
	goto Route103_EventScript_290710
	end

Route103_EventScript_290710:: @ 8290710
	applymovement VAR_LAST_TALKED, Route103_Movement_29071F
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Route103_Movement_29071F: @ 829071F
	cut_tree
	step_end

Route103_EventScript_290721:: @ 8290721
	msgbox Route103_Text_29077D, MSGBOX_DEFAULT
	releaseall
	end

Route103_EventScript_29072B:: @ 829072B
	closemessage
	releaseall
	end

Route103_Text_29072E: @ 829072E
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Route103_Text_290771: @ 8290771
Route111_Text_290771: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Route103_Text_29077D: @ 829077D
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

GraniteCave_B2F_EventScript_2907A6:: @ 82907A6
MirageTower_3F_EventScript_2907A6:: @ 82907A6
MirageTower_4F_EventScript_2907A6:: @ 82907A6
Route110_TrickHousePuzzle3_EventScript_2907A6:: @ 82907A6
Route111_EventScript_2907A6:: @ 82907A6
Route114_EventScript_2907A6:: @ 82907A6
Route115_EventScript_2907A6:: @ 82907A6
RusturfTunnel_EventScript_2907A6:: @ 82907A6
SafariZone_North_EventScript_2907A6:: @ 82907A6
SafariZone_Northeast_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room1_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room2_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room5_EventScript_2907A6:: @ 82907A6
VictoryRoad_B1F_EventScript_2907A6:: @ 82907A6
	lockall
	checkflag FLAG_BADGE03_GET
	goto_if 0, Route111_EventScript_29082D
	checkpartymove MOVE_ROCK_SMASH
	compare VAR_RESULT, 6
	goto_eq Route111_EventScript_29082D
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Route111_Text_29083A, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq Route111_EventScript_290837
	msgbox Route111_Text_290771, MSGBOX_DEFAULT
	closemessage
	dofieldeffect 37
	waitstate
	goto Route111_EventScript_2907FB
	end

Route111_EventScript_2907F0:: @ 82907F0
	lockall
	dofieldeffect 37
	waitstate
	goto Route111_EventScript_2907FB
	end

Route111_EventScript_2907FB:: @ 82907FB
	applymovement VAR_LAST_TALKED, Route111_Movement_29082B
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	compare VAR_RESULT, 1
	goto_eq Route111_EventScript_290829
	special RockSmashWildEncounter
	compare VAR_RESULT, 0
	goto_eq Route111_EventScript_290829
	waitstate
	releaseall
	end

Route111_EventScript_290829:: @ 8290829
	releaseall
	end

Route111_Movement_29082B: @ 829082B
	rock_smash_break
	step_end

Route111_EventScript_29082D:: @ 829082D
	msgbox Route111_Text_29087F, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_290837:: @ 8290837
	closemessage
	releaseall
	end

Route111_Text_29083A: @ 829083A
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Route111_Text_29087F: @ 829087F
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

FieryPath_EventScript_2908BA:: @ 82908BA
MagmaHideout_1F_EventScript_2908BA:: @ 82908BA
Route110_TrickHousePuzzle4_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room1_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room2_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room3_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room5_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room8_EventScript_2908BA:: @ 82908BA
ShoalCave_LowTideLowerRoom_EventScript_2908BA:: @ 82908BA
VictoryRoad_B1F_EventScript_2908BA:: @ 82908BA
	lockall
	checkflag FLAG_BADGE04_GET
	goto_if 0, FieryPath_EventScript_290915
	checkflag FLAG_SYS_USE_STRENGTH
	goto_eq FieryPath_EventScript_29091F
	checkpartymove MOVE_STRENGTH
	compare VAR_RESULT, 6
	goto_eq FieryPath_EventScript_290915
	setfieldeffectargument 0, VAR_RESULT
	msgbox FieryPath_Text_29092C, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq FieryPath_EventScript_290929
	closemessage
	dofieldeffect 40
	waitstate
	goto FieryPath_EventScript_290908
	end

FieryPath_EventScript_2908FD:: @ 82908FD
	lockall
	dofieldeffect 40
	waitstate
	goto FieryPath_EventScript_290908
	end

FieryPath_EventScript_290908:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox FieryPath_Text_29098C, MSGBOX_DEFAULT
	releaseall
	end

FieryPath_EventScript_290915:: @ 8290915
	msgbox FieryPath_Text_2909D6, MSGBOX_DEFAULT
	releaseall
	end

FieryPath_EventScript_29091F:: @ 829091F
	msgbox FieryPath_Text_290A16, MSGBOX_DEFAULT
	releaseall
	end

FieryPath_EventScript_290929:: @ 8290929
	closemessage
	releaseall
	end

FieryPath_Text_29092C: @ 829092C
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

FieryPath_Text_29098C: @ 829098C
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

FieryPath_Text_2909D6: @ 82909D6
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

FieryPath_Text_290A16: @ 8290A16
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall:: @ 8290A49
	lockall
	checkpartymove MOVE_WATERFALL
	compare VAR_RESULT, 6
	goto_eq EventScript_290A84
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_290AC3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq EventScript_290A8C
	msgbox Text_290AFC, MSGBOX_DEFAULT
	dofieldeffect 43
	goto EventScript_290A8C

EventScript_CannotUseWaterfall:: @ 8290A83
	lockall

EventScript_290A84:: @ 8290A84
	msgbox Text_290A8E, MSGBOX_DEFAULT

EventScript_290A8C:: @ 8290A8C
	releaseall
	end

Text_290A8E: @ 8290A8E
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_290AC3: @ 8290AC3
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_290AFC: @ 8290AFC
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive:: @ 8290B0F
	lockall
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, 6
	goto_eq EventScript_290B4E
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_290BE8, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq EventScript_290B58
	msgbox Text_290C1A, MSGBOX_DEFAULT
	dofieldeffect 44
	goto EventScript_290B58
	end

EventScript_290B4E:: @ 8290B4E
	msgbox Text_290BAA, MSGBOX_DEFAULT
	releaseall
	end

EventScript_290B58:: @ 8290B58
	releaseall
	end

EventScript_UseDiveUnderwater:: @ 8290B5A
	lockall
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, 6
	goto_eq EventScript_290B99
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_290C6E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_eq EventScript_290BA8
	msgbox Text_290C1A, MSGBOX_DEFAULT
	dofieldeffect 44
	goto EventScript_290BA8
	end

EventScript_290B99:: @ 8290B99
	lockall
	msgbox Text_290C28, MSGBOX_DEFAULT
	goto EventScript_290BA8
	end

EventScript_290BA8:: @ 8290BA8
	releaseall
	end

Text_290BAA: @ 8290BAA
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_290BE8: @ 8290BE8
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_290C1A: @ 8290C1A
	.string "{STR_VAR_1} used DIVE.$"

Text_290C28: @ 8290C28
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_290C6E: @ 8290C6E
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

EventScript_290CAE:: @ 8290CAE
	msgbox Text_290CB7, MSGBOX_SIGN
	end

Text_290CB7: @ 8290CB7
	.string "Looks like there's nothing here…$"
