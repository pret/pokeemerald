MysteryGiftScript_StampCard::
	setvaddress MysteryGiftScript_StampCard
	setorcopyvar VAR_RESULT, GET_MAX_STAMPS
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	setorcopyvar VAR_RESULT, GET_NUM_STAMPS
	specialvar VAR_0x8009, GetMysteryGiftCardStat
	subvar VAR_0x8008, VAR_0x8009
	buffernumberstring STR_VAR_1, VAR_0x8008
	lock
	faceplayer
	vmessage sText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

.ifdef FRENCH
sText_MysteryGiftStampCard:
	.string "Merci d’utiliser le système\n"
	.string "CARTE TAMPON.\p"
	.string "Il vous en faut {STR_VAR_1} de plus pour\n"
	.string "remplir complètement la carte.$"
.else
.ifdef ITALIAN
sText_MysteryGiftStampCard:
	.string "Grazie per usare il Sistema SCHEDA\n"
	.string "BOLLINI.\p"
	.string "Il numero di BOLLINI che ancora ti\n"
	.string "serve per completare la SCHEDA\l"
	.string "è {STR_VAR_1}.$"
.else @ENGLISH
sText_MysteryGiftStampCard:
	.string "Thank you for using the STAMP CARD\n"
	.string "System.\p"
	.string "You have {STR_VAR_1} more to collect to\n"
	.string "fill your STAMP CARD.$"
.endif
.endif
