MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.\p"
	.string "Jij bent vast {PLAYER}.\n"
	.string "Er ligt hier een kaart voor je.$"

sText_AuroraTicketUseAtPort:
	.string "Hij lijkt bedoeld voor de haven\n"
	.string "van LILYCOVE CITY.\p"
	.string "Probeer het eens en kijk wat\n"
	.string "het is!$"

sText_AuroraTicketThankYou:
	.string "Bedankt voor het gebruik van het\n"
	.string "GEHEIM CADEAU-systeem.$"

sText_AuroraTicketBagFull:
	.string "Oh, sorry, {PLAYER}.\n"
	.string "Het BELANGRIJK-vak van je TAS is vol.\p"
	.string "Leg iets op je PC en kom dan\n"
	.string "terug hiervoor.$"
