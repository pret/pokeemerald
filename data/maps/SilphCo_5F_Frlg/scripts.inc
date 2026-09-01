SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "TEAM ROCKET is in an uproar over\n"
	.string "some intruder.\p"
	.string "That's you, right?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "TEAM ROCKET took off!\n"
	.string "You're our hero! Thank you!$"

SilphCo_5F_Text_Grunt1Intro::
	.string "I heard a kid was wandering\n"
	.string "around.$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "Boom!$"

SilphCo_5F_Text_Grunt1PostBattle::
	.string "It's not smart to pick a fight with\n"
	.string "TEAM ROCKET!$"

SilphCo_5F_Text_BeauIntro::
	.string "We study POKé BALL technology on\n"
	.string "this floor.$"

SilphCo_5F_Text_BeauDefeat::
	.string "Dang!\n"
	.string "Blast it!$"

SilphCo_5F_Text_BeauPostBattle::
	.string "We worked on the ultimate POKé\n"
	.string "BALL which would catch anything.$"

SilphCo_5F_Text_DaltonIntro::
	.string "Whaaat?\p"
	.string "There shouldn't be any children\n"
	.string "here!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "Oh, goodness!$"

SilphCo_5F_Text_DaltonPostBattle::
	.string "You're only on 5F.\n"
	.string "It's a long way to my BOSS!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "Show TEAM ROCKET a little respect!$"

SilphCo_5F_Text_Grunt2Defeat::
	.string "Cough…\n"
	.string "Cough…$"

SilphCo_5F_Text_Grunt2PostBattle::
	.string "Which reminds me.\p"
	.string "KOFFING evolves into WEEZING!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "It's a POKéMON REPORT!\p"
	.string "POKéMON LAB created PORYGON,\n"
	.string "the first virtual-reality POKéMON.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "It's a POKéMON REPORT!\p"
	.string "Over 350 POKéMON techniques have\n"
	.string "been confirmed.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "It's a POKéMON REPORT!\p"
	.string "Some POKéMON have been confirmed\n"
	.string "to evolve when they are traded.$"

SilphCo_5F_Text_FloorSign::
	.string "SILPH CO. HEAD OFFICE\n"
	.string "5F$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "Those thugs that took over our\n"
	.string "building…\p"
	.string "Their BOSS said he was looking for\n"
	.string "strong POKéMON.\p"
	.string "I hope our PRESIDENT managed to\n"
	.string "avoid trouble…$"
