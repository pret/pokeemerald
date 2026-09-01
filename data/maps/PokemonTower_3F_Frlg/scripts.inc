PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
	.string "Urrg… Awaa…\n"
	.string "Huhu… Graa…$"

PokemonTower_3F_Text_HopeDefeat::
	.string "Hwa!\n"
	.string "I'm saved!$"

PokemonTower_3F_Text_HopePostBattle::
	.string "The ghosts can be identified by\n"
	.string "the SILPH SCOPE.$"

PokemonTower_3F_Text_CarlyIntro::
	.string "Kekeke…\n"
	.string "Kwaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
	.string "Hmm?\n"
	.string "What am I doing?$"

PokemonTower_3F_Text_CarlyPostBattle::
	.string "Sorry!\n"
	.string "I was possessed!$"

PokemonTower_3F_Text_PatriciaIntro::
	.string "Be gone!\n"
	.string "Malevolent spirit!$"

PokemonTower_3F_Text_PatriciaDefeat::
	.string "Whew!\n"
	.string "The spirit left!$"

PokemonTower_3F_Text_PatriciaPostBattle::
	.string "The others above…\n"
	.string "They must have been possessed.$"

