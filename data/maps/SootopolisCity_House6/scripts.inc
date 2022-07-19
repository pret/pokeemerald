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
	.string "Bonjour! Vous êtes la première personne\n"
	.string "à venir chez nous depuis longtemps.\p"
	.string "Comme vous illuminez ma journée, je\n"
	.string "vous offre une grande POUPEE WAILMER.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Prenez-en soin!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, vous la voulez, mais pas maintenant?\n"
	.string "D’accord. Je vous la mets de côté.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "C’est sûr?\n"
	.string "Vous ne voulez pas de cette POUPEE?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "J’adore les POUPEE en peluche!$"

