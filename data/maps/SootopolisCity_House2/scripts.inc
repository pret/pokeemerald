SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "Op de top liggen twee bollen naast\n"
	.string "elkaar. Wist je dat?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Ja, twee bollen naast elkaar…\p"
	.string "Die twee samen zien…\n"
	.string "Het is op de een of andere\l"
	.string "manier rustgevend…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Echt waar?\n"
	.string "Misschien moet je eens gaan kijken…$"

