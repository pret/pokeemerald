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
	.string "Kijk hier eens naar!\p"
	.string "Dit is een ZIJDEN SJAAL. Dat is\n"
	.string "het nieuwste van het nieuwste!\p"
	.string "O, ik zie je ogen al stralen!\n"
	.string "Jij snapt mijn stijl!\p"
	.string "O, wat ben jij leuk!\n"
	.string "Alsjeblieft. Hij is voor jou!$"

DewfordTown_House2_Text_NoRoom:
	.string "O, je hebt geen plek meer?\p"
	.string "Luister goed: deze SJAAL moet je\n"
	.string "hebben! Ik zou al mijn spullen\l"
	.string "ervoor verkopen!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "De ZIJDEN SJAAL maakt\n"
	.string "NORMAAL-aanvallen sterker.\p"
	.string "Het is een prachtige SJAAL die bij\n"
	.string "bijna alle POKéMON past!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wauw, ben je echt over zee naar\n"
	.string "DEWFORD gekomen?\p"
	.string "Kwam je misschien omdat je over\n"
	.string "BRAWLY had gehoord?\p"
	.string "Hij is zo cool…\n"
	.string "Iedereen vindt hem geweldig.$"

