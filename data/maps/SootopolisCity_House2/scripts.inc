SootopolisCity_House2_MapScripts:: @ 8226A76
	.byte 0

SootopolisCity_House2_EventScript_226A77:: @ 8226A77
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_226AAB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq SootopolisCity_House2_EventScript_226A99
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_House2_EventScript_226AA2
	release
	end

SootopolisCity_House2_EventScript_226A99:: @ 8226A99
	msgbox SootopolisCity_House2_Text_226AF1, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_226AA2:: @ 8226AA2
	msgbox SootopolisCity_House2_Text_226B41, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_226AAB: @ 8226AAB
	.string "MT. PYRE…\p"
	.string "At its peak are two orbs placed side\n"
	.string "by side. Did you know?$"

SootopolisCity_House2_Text_226AF1: @ 8226AF1
	.string "Yes, two orbs side by side…\p"
	.string "The sight of them together…\n"
	.string "It is somehow soothing…$"

SootopolisCity_House2_Text_226B41: @ 8226B41
	.string "Is that so?\n"
	.string "Perhaps you ought to visit and see…$"

