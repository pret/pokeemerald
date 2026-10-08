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

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Jij bent een POKéMON TRAINER, hè?\p"
	.string "JUAN van SOOTOPOLIS heeft veel fans.\n"
	.string "Meer dan zijn leerling WALLACE!\p"
	.string "Heb jij ze?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, dan ben je vast best sterk.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh jee…\n"
	.string "Dat is een beetje eenzaam.\p"
	.string "Probeer wat harder te werken om\n"
	.string "fans te krijgen.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Trouwe fans komen zelfs van\n"
	.string "buiten HOENN.\p"
	.string "Het was echt wild toen ik bij de\n"
	.string "TRAINER FANCLUB in LILYCOVE was.$"

