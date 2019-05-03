PacifidlogTown_PokemonCenter_1F_MapScripts:: @ 82034A7
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition: @ 82034B2
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034B6:: @ 82034B6
	setvar VAR_0x800B, 1
	call PacifidlogTown_PokemonCenter_1F_EventScript_27191E
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034C4:: @ 82034C4
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2034DF, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034CD:: @ 82034CD
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20350F, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2034D6:: @ 82034D6
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20356F, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_2034DF: @ 82034DF
	.string "What color is your TRAINER CARD?\n"
	.string "Mine's copper!$"

PacifidlogTown_PokemonCenter_1F_Text_20350F: @ 820350F
	.string "PACIFIDLOG TOWN floats on top of\n"
	.string "a colony of CORSOLA.\p"
	.string "If I told you that, would you believe\n"
	.string "me?$"

PacifidlogTown_PokemonCenter_1F_Text_20356F: @ 820356F
	.string "The ancestors of the people in\n"
	.string "PACIFIDLOG were said to have been\l"
	.string "born on boats and then lived and died \l"
	.string "aboard them.\p"
	.string "I understand that they lived that way\n"
	.string "because they were searching for\l"
	.string "something.$"

