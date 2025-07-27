MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

.ifdef FRENCH
sText_MysteryGiftOldSeaMapForYou:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Vous devez être {PLAYER}.\n"
	.string "Il y a une VIEILLECARTE pour vous.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Elle peut être utilisée au port de\n"
	.string "NENUCRIQUE.\p"
	.string "Essayez-la pour voir de quoi \n"
	.string "il s’agit.$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, je regrette, {PLAYER}. La POCHE\n"
	.string "OBJ. RARES du SAC est pleine.\p"
	.string "Faites de la place dans votre SAC\n"
	.string "et revenez me voir.$"
.else
.ifdef ITALIAN
sText_MysteryGiftOldSeaMapForYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Tu sei {PLAYER}, vero? Ho qui\n"
	.string "una MAPPA STINTA per te.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Dovrebbe servirti allo scalo di\n"
	.string "PORTO ALGHEPOLI.\p"
	.string "Ti conviene andare a vedere\n"
	.string "di persona.$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, mi spiace. La TASCA STRUMENTI\n"
	.string "BASE del tuo ZAINO è piena.\p"
	.string "Torna a trovarmi dopo aver\n"
	.string "depositato qualcosa nel PC.$"
.else
.ifdef SPANISH
sText_MysteryGiftOldSeaMapForYou:
	.string "Gracias por usar el sistema\n"
	.string "del REGALO MISTERIOSO.\p"
	.string "Debes de ser {PLAYER}, ¿no?\p"
	.string "Pues tenemos una CARTA MARINA para ti.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Parece que puedes usarlo en el\n"
	.string "puerto de CIUDAD CALAGUA.\p"
	.string "¿Por qué no curioseas un poco\n"
	.string "para ver de qué va la cosa?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Gracias por usar el sistema\n"
	.string "del REGALO MISTERIOSO.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Lo siento, {PLAYER}. El BOLSILLO\n"
	.string "de los OBJETOS CLAVE está lleno.\p"
	.string "Guarda algo en el PC y vuelve más\n"
	.string "tarde.$"

.else @ENGLISH
sText_MysteryGiftOldSeaMapForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Let me confirm--you are {PLAYER}?\p"
	.string "We received this OLD SEA MAP\n"
	.string "addressed to you.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
.endif
.endif
.endif
