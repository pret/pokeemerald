DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Gorge your eyes on this!\p"
	.string "It's a Silk Scarf. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this Scarf is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "The Silk Scarf raises the power of\n"
	.string "Normal-type moves.\p"
	.string "It's a marvelous Scarf that will go\n"
	.string "with almost all Pokémon!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit Dewford?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about Brawly?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"

