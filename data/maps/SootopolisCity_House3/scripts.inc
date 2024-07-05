SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

.ifdef FRENCH
	.include "data/maps/SootopolisCity_House3/text_fr.inc"
.else
.ifdef ITALIAN
	.include "data/maps/SootopolisCity_House3/text_it.inc"
.else
.ifdef SPANISH
	.include "data/maps/SootopolisCity_House3/text_es.inc"
.else
	.include "data/maps/SootopolisCity_House3/text.inc"
.endif
.endif
.endif
