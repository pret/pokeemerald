LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "Do you believe in ghosts?$"

LavenderTown_Text_SoThereAreBelievers::
	.string "Really?\n"
	.string "So there are believers…$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "Hahaha, I guess not.\p"
	.string "That white hand on your shoulder…\n"
	.string "I'm just imagining it.$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "This town is known as the grave\n"
	.string "site of POKéMON.\p"
	.string "Memorial services are held in\n"
	.string "POKéMON TOWER.$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "Ghosts appeared in POKéMON TOWER.\p"
	.string "I think they're the spirits of\n"
	.string "POKéMON that the ROCKETS killed.$"

LavenderTown_Text_TownSign::
	.string "LAVENDER TOWN\n"
	.string "The Noble Purple Town$"

LavenderTown_Text_SilphScopeNotice::
	.string "New SILPH SCOPE!\n"
	.string "Make the Invisible Plain to See!\p"
	.string "SILPH CO.$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "LAVENDER VOLUNTEER\n"
	.string "POKéMON HOUSE$"

LavenderTown_Text_PokemonTowerSign::
	.string "POKéMON TOWER\n"
	.string "Becalm the Spirits of POKéMON$"

