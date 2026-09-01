CinnabarIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	faceplayer
	msgbox CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail
	msgbox CinnabarIsland_PokemonCenter_1F_Text_LetsGo
	closemessage
	playbgm MUS_FOLLOW_ME, 1
	savebgm MUS_FOLLOW_ME
	setflag FLAG_DONT_TRANSITION_MUSIC
	setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
	delay 20
	call_if_eq VAR_FACING, DIR_SOUTH, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth
	call_if_eq VAR_FACING, DIR_EAST, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast
	call_if_eq VAR_FACING, DIR_WEST, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest
	removeobject LOCALID_CINNABAR_POKEMON_CENTER_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1
	clearflag FLAG_HIDE_CINNABAR_BILL
	warp MAP_CINNABAR_ISLAND, 14, 11
	waitstate
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet
	release
	end

CinnabarIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast::
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast::
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_8
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
	.string "I came to visit the CINNABAR GYM,\n"
	.string "but the door is locked tight.\p"
	.string "There should be a key for it\n"
	.string "somewhere.\p"
	.string "Could it be in that burned-out\n"
	.string "mansion?\p"
	.string "The GYM LEADER's friend used to\n"
	.string "live there, they say.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
	.string "Do you have lots of friends?\p"
	.string "Linking up with the usual friends\n"
	.string "is fun, of course.\p"
	.string "But how about visiting the\n"
	.string "UNION ROOM every so often?\p"
	.string "Who knows, you may end up making\n"
	.string "new friends.\p"
	.string "I think it would be worth your time\n"
	.string "to check the UNION ROOM.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
	.string "POKéMON can still learn techniques\n"
	.string "after canceling evolution.\p"
	.string "Evolution can wait until new moves\n"
	.string "have been learned.$"

CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland::
	.string "BILL: Hey, you kept me waiting!\n"
	.string "Ready to set sail to ONE ISLAND?$"

CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet::
	.string "Oh, you're still not done yet?$"

CinnabarIsland_PokemonCenter_1F_Text_LetsGo::
	.string "Well, that's it.\n"
	.string "Let's go!$"

