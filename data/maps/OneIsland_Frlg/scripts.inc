OneIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_OnFrame
	.byte 0

OneIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ONE_ISLAND
	end

OneIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 2, OneIsland_EventScript_EnterOneIslandFirstTime
	.2byte 0

OneIsland_EventScript_EnterOneIslandFirstTime::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerExitHarbor
	waitmovement 0
	msgbox OneIsland_Text_BillLetsGoSeeCelio
	closemessage
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillWalkToPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerWalkToPokeCenter
	waitmovement 0
	opendoor 14, 5
	waitdooranim
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillEnterPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerEnterPokeCenter
	waitmovement 0
	closedoor 14, 5
	waitdooranim
	removeobject LOCALID_ONE_ISLAND_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 3
	warp MAP_ONE_ISLAND_POKEMON_CENTER_1F, 9, 9
	waitstate
	releaseall
	end

	.macro walk_to_pokecenter
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	.endm

OneIsland_Movement_PlayerWalkToPokeCenter::
	walk_up
	walk_to_pokecenter
	step_end

OneIsland_Movement_PlayerEnterPokeCenter::
	walk_up
	walk_up
	set_invisible
	step_end

OneIsland_Movement_PlayerExitHarbor::
	walk_up
	step_end

OneIsland_Movement_BillWalkToPokeCenter::
	walk_to_pokecenter
	walk_up
	step_end

OneIsland_Movement_BillEnterPokeCenter::
	walk_up
	set_invisible
	step_end

OneIsland_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_EventScript_OldManLinkHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_EventScript_OldManLinkKanto
	msgbox OneIsland_Text_LuckyToHaveCelioHere
	release
	end

OneIsland_EventScript_OldManLinkKanto::
	msgbox OneIsland_Text_HavePCLinkageWithKanto
	release
	end

OneIsland_EventScript_OldManLinkHoenn::
	msgbox OneIsland_Text_HavePCLinkageWithHoenn
	release
	end

OneIsland_EventScript_BaldingMan::
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

OneIsland_EventScript_IslandSign::
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end

OneIsland_EventScript_PokemonNetCenterSign::
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end

OneIsland_Text_BillLetsGoSeeCelio::
	.string "BILL: Here we are!\n"
	.string "This is ONE ISLAND.\p"
	.string "There are several islands around\n"
	.string "here, and this is one of them.\p"
	.string "My friend CELIO sent the boat to\n"
	.string "fetch me here.\p"
	.string "He's in charge of the island's PC\n"
	.string "network by his lonesome.\p"
	.string "…Why am I telling you this now?\n"
	.string "Let's just go see CELIO!$"

Text_WhereDoYouWantToSail::
	.string "Ahoy, there!\n"
	.string "Where do you want to sail?$"

OneIsland_Text_LuckyToHaveCelioHere::
	.string "Here we are on an island smack in\n"
	.string "the middle of nowhere.\p"
	.string "We're lucky to have an upstanding\n"
	.string "young man like CELIO here.\p"
	.string "My granddaughter was in a tizzy\n"
	.string "over CELIO's friend.\p"
	.string "Something about a famous\n"
	.string "POKéMANIAC?\p"
	.string "I'm not sure what that means, but\n"
	.string "CELIO is quite the man!$"

OneIsland_Text_HavePCLinkageWithKanto::
	.string "My granddaughter was in a tizzy\n"
	.string "over a new breakthrough.\p"
	.string "She said we now have PC linkage\n"
	.string "with people in KANTO.\p"
	.string "I'm not sure what that means, but\n"
	.string "CELIO is quite the man!$"

OneIsland_Text_HavePCLinkageWithHoenn::
	.string "My granddaughter was in a tizzy\n"
	.string "over a new breakthrough.\p"
	.string "She said we finally have PC linkage\n"
	.string "with people in HOENN.\p"
	.string "I'm not sure what that means, but\n"
	.string "CELIO is quite the man.\p"
	.string "He would make a fine husband for\n"
	.string "my granddaughter!$"

OneIsland_Text_IslandSign::
	.string "ONE ISLAND\n"
	.string "Friends Gather at Knot Island$"

OneIsland_Text_PokemonNetCenterSign::
	.string "Expanding the POKéMON World!\n"
	.string "POKéMON NET CENTER$"

@ Unused
OneIsland_Text_ReturnToCinnabar::
	.string "グレンタウンに　もどりますか？$"

OneIsland_Text_IsntWarmClimateHereGreat::
	.string "Hi, sight-seeing, are you?\n"
	.string "Isn't the warm climate here great?$"

