PokemonTower_5F_Frlg_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
	.string "Come, child!\n"
	.string "I have purified this space.\l"
	.string "You can rest here.$"

PokemonTower_5F_Text_TammyIntro::
	.string "Give…me…\n"
	.string "your…all…$"

PokemonTower_5F_Text_TammyDefeat::
	.string "Gasp!$"

PokemonTower_5F_Text_TammyPostBattle::
	.string "I was under possession.$"

PokemonTower_5F_Text_RuthIntro::
	.string "You…shall…\n"
	.string "join…us…$"

PokemonTower_5F_Text_RuthDefeat::
	.string "What a nightmare!$"

PokemonTower_5F_Text_RuthPostBattle::
	.string "I was possessed.$"

PokemonTower_5F_Text_KarinaIntro::
	.string "Zombies!$"

PokemonTower_5F_Text_KarinaDefeat::
	.string "Ha?$"

PokemonTower_5F_Text_KarinaPostBattle::
	.string "I regained my senses.$"

PokemonTower_5F_Text_JanaeIntro::
	.string "Urgah…\n"
	.string "Urff…$"

PokemonTower_5F_Text_JanaeDefeat::
	.string "Whoo!$"

PokemonTower_5F_Text_JanaePostBattle::
	.string "I fell to evil spirits despite my\n"
	.string "training in the mountains…$"

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
	.string "Entered the purified and protected\n"
	.string "zone.\p"
	.string "{PLAYER}'s POKéMON were fully\n"
	.string "healed.$"

