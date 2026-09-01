PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "Ghost! No!\n"
	.string "Kwaaah!$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "Where is the ghost?$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "I must have been dreaming…$"

PokemonTower_4F_Text_LaurelIntro::
	.string "Be cursed with me!\n"
	.string "Kwaaah!$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "What!$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "We can't determine the identity of\n"
	.string "the ghosts…$"

PokemonTower_4F_Text_JodyIntro::
	.string "Huhuhu…\n"
	.string "Beat me not!$"

PokemonTower_4F_Text_JodyDefeat::
	.string "Huh?\n"
	.string "Who? What?$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "May the departed POKéMON rest in\n"
	.string "peace…$"

