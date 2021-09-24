SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_House3_EventScript_HaveFans
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
	.string "You're a Pokémon Trainer, aren't you?\p"
	.string "Sootopolis's Juan has many fans.\n"
	.string "Even more than his student Wallace!\p"
	.string "Do you have any?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, then you must be pretty strong.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, dear…\n"
	.string "That's a little lonesome.\p"
	.string "Try working a little harder to get\n"
	.string "a fan following.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Dedicated fans come over from even\n"
	.string "outside of Hoenn.\p"
	.string "It was really wild when I went to the\n"
	.string "Trainer Fan Club in Lilycove.$"

