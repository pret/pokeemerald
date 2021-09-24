FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious Azurill!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill:
	.string "Azurill: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged Flannery,\n"
	.string "the Leader of Lavaridge Gym?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the Elite Four in the\l"
	.string "Pokémon League at one point.\p"
	.string "It wouldn't surprise me to see Flannery\n"
	.string "become a great Trainer in her own\l"
	.string "right.$"

FallarborTown_Text_BattleTentSign:
	.string "Battle Tent Fallarbor Site\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign:
	.string "Fallarbor Town\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "Move Tutor's House\n"
	.string "“New moves taught to Pokémon.”$"

