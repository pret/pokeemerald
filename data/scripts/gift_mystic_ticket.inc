MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Jij bent vast {PLAYER}.\n"
	.string "Er ligt hier een kaart voor je.$"

sText_MysticTicketUseAtPort:
	.string "Hij lijkt bedoeld voor de haven\n"
	.string "van LILYCOVE CITY.\p"
	.string "Probeer het eens en kijk wat\n"
	.string "het is!$"

sText_MysticTicketThankYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.$"

sText_MysticTicketBagFull:
	.string "Oh, sorry, {PLAYER}.\n"
	.string "Het BELANGRIJK-vak van je TAS is vol.\p"
	.string "Leg iets op je PC en kom dan\n"
	.string "terug hiervoor.$"
