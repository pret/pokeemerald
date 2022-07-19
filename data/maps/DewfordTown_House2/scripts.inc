DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
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
	.string "Regarde-moi cette merveille!\p"
	.string "C’est un MOUCH. SOIE. C’est à la pointe\n"
	.string "de la mode!\p"
	.string "Oh, je vois une lueur dans tes yeux!\n"
	.string "Mon style éblouissant te plaît!\p"
	.string "Oh, tu me fais plaisir!\n"
	.string "Tiens, voilà. Je te le donne!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, tu n’as plus de place?\p"
	.string "Bon, écoute-moi bien, cet objet est\n"
	.string "indispensable! Il vaut bien tous les\l"
	.string "objets que j’ai sur moi.$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Le MOUCH. SOIE augmente la puissance\n"
	.string "des attaques de type NORMAL.\p"
	.string "C’est un MOUCHOIR merveilleux assorti à\n"
	.string "presque tous les POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Ouah, tu as franchi la mer pour\n"
	.string "venir visiter MYOKARA?\p"
	.string "Tu es peut-être ici parce que tu\n"
	.string "as entendu parler de BASTIEN?\p"
	.string "Il est super cool…\n"
	.string "Tout le monde l’adore.$"

