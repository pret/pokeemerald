SootopolisCity_House6_MapScripts:: @ 8226F5B
	.byte 0

SootopolisCity_House6_EventScript_Woman:: @ 8226F5C
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	call_if_eq SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll:: @ 8226F99
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll:: @ 8226FA3
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll:: @ 8226FAD
	bufferdecorationname 1, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll: @ 8226FC3
	.string "Hello! You're our first guest in\n"
	.string "a good while.\p"
	.string "You've brightened up my day, so I'll\n"
	.string "give you a big WAILMER DOLL.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt: @ 8227034
	.string "Take good care of it!$"

SootopolisCity_House6_Text_IllHoldItForYou: @ 822704A
	.string "Oh, you want it, but not right now?\n"
	.string "Okay, then I'll hold it for you.$"

SootopolisCity_House6_Text_DontWantThisDoll: @ 822708F
	.string "Are you sure?\n"
	.string "You don't want this DOLL?$"

SootopolisCity_House6_Text_LovePlushDolls: @ 82270B7
	.string "I love plush DOLLS!$"

