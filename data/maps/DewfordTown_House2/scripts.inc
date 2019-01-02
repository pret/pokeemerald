DewfordTown_House2_MapScripts:: @ 81FE22D
	.byte 0

DewfordTown_House2_EventScript_1FE22E:: @ 81FE22E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_1FE267
	msgbox DewfordTown_House2_Text_1FE27A, MSGBOX_DEFAULT
	giveitem_std ITEM_SILK_SCARF
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_House2_EventScript_1FE25D
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_1FE25D:: @ 81FE25D
	msgbox DewfordTown_House2_Text_1FE356, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_1FE267:: @ 81FE267
	msgbox DewfordTown_House2_Text_1FE3D1, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_1FE271:: @ 81FE271
	msgbox DewfordTown_House2_Text_1FE444, MSGBOX_NPC
	end

DewfordTown_House2_Text_1FE27A: @ 81FE27A
	.string "Gorge your eyes on this!\p"
	.string "It's a SILK SCARF. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_1FE356: @ 81FE356
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this SCARF is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

DewfordTown_House2_Text_1FE3D1: @ 81FE3D1
	.string "The SILK SCARF raises the power of\n"
	.string "NORMAL-type moves.\p"
	.string "It's a marvelous SCARF that will go\n"
	.string "with almost all POKéMON!$"

DewfordTown_House2_Text_1FE444: @ 81FE444
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit DEWFORD?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about BRAWLY?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"

