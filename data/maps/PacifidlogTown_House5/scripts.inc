PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

.ifdef ENGLISH
	.include "data/maps/PacifidlogTown_House5/text.inc"
.else
.ifdef FRENCH
	.include "data/maps/PacifidlogTown_House5/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/PacifidlogTown_House5/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/PacifidlogTown_House5/text_es.inc"
.endif
.endif
.endif
.endif
