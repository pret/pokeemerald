SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Hallo! Jij bent sinds lange tijd\n"
	.string "onze eerste gast.\p"
	.string "Je maakt mijn dag mooier, dus ik\n"
	.string "geef je een grote WAILMER-POP.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Zorg er goed voor!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, je wilt hem, maar nu niet?\n"
	.string "Oké, dan bewaar ik hem voor je.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Weet je het zeker?\n"
	.string "Je wilt deze POP niet?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Ik hou van pluchen POPPEN!$"

