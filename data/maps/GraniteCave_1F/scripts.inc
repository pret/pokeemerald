GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

.ifdef FRENCH
	.include "data/maps/GraniteCave_1F/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/GraniteCave_1F/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/GraniteCave_1F/text_es.inc"
.else
	.include "data/maps/GraniteCave_1F/text.inc"
.endif
.endif
.endif
