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

.ifdef FRENCH
sText_MysticTicketForYou:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Vous devez être {PLAYER}.\n"
	.string "Il y a un ticket pour vous.$"

sText_MysticTicketUseAtPort:
	.string "Il peut être utilisé au port de\n"
	.string "NENUCRIQUE.\p"
	.string "Essayez-le pour voir de quoi \n"
	.string "il s’agit.$"

sText_MysticTicketThankYou:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.$"

sText_MysticTicketBagFull:
	.string "Oh, je regrette, {PLAYER}. La POCHE\n"
	.string "OBJ. RARES du SAC est pleine.\p"
	.string "Faites de la place dans votre SAC\n"
	.string "et revenez me voir.$"
.else
.ifdef ITALIAN
sText_MysticTicketForYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Tu sei {PLAYER}, vero? Ho qui\n"
	.string "un biglietto per te.$"

sText_MysticTicketUseAtPort:
	.string "Dovrebbe servirti allo scalo di\n"
	.string "PORTO ALGHEPOLI.\p"
	.string "Ti conviene andare a vedere\n"
	.string "di persona.$"

sText_MysticTicketThankYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.$"

sText_MysticTicketBagFull:
	.string "Oh, mi spiace. La TASCA STRUMENTI\n"
	.string "BASE del tuo ZAINO è piena.\p"
	.string "Torna a trovarmi dopo aver\n"
	.string "depositato qualcosa nel PC.$"
.else @ENGLISH
sText_MysticTicketForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "You must be {PLAYER}.\n"
	.string "There is a ticket here for you.$"

sText_MysticTicketUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_MysticTicketThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_MysticTicketBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
.endif
.endif
