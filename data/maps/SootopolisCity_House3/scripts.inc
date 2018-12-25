SootopolisCity_House3_MapScripts:: @ 8226B71
	.byte 0

SootopolisCity_House3_EventScript_226B72:: @ 8226B72
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_226BA4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_House3_EventScript_226B91
	msgbox SootopolisCity_House3_Text_226C44, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_226B91:: @ 8226B91
	msgbox SootopolisCity_House3_Text_226C20, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_226B9B:: @ 8226B9B
	msgbox SootopolisCity_House3_Text_226C9C, MSGBOX_NPC
	end

SootopolisCity_House3_Text_226BA4: @ 8226BA4
	.string "You're a POKéMON TRAINER, aren't you?\p"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
	.string "Even more than his student WALLACE!\p"
	.string "Do you have any?$"

SootopolisCity_House3_Text_226C20: @ 8226C20
	.string "Oh, then you must be pretty strong.$"

SootopolisCity_House3_Text_226C44: @ 8226C44
	.string "Oh, dear…\n"
	.string "That's a little lonesome.\p"
	.string "Try working a little harder to get\n"
	.string "a fan following.$"

SootopolisCity_House3_Text_226C9C: @ 8226C9C
	.string "Dedicated fans come over from even\n"
	.string "outside of HOENN.\p"
	.string "It was really wild when I went to the\n"
	.string "TRAINER FAN CLUB in LILYCOVE.$"

