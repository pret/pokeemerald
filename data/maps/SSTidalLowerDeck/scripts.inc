SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

.ifdef FRENCH
	.include "data/maps/SSTidalLowerDeck/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SSTidalLowerDeck/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SSTidalLowerDeck/text_es.inc"
.else
	.include "data/maps/SSTidalLowerDeck/text.inc"
.endif
.endif
.endif
