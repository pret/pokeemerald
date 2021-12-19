EventScript_Questionnaire::
	lockall
	msgbox Questionnaire_Text_FillOut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Questionnaire_EventScript_Release
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartEmployeeObjectEventId
	goto_if_eq VAR_0x8004, 1, Questionnaire_EventScript_PlayerInputMysteryEventPhrase
	goto_if_eq VAR_0x8004, 2, Questionnaire_EventScript_PlayerInputMysteryGiftPhrase
	goto_if_eq VAR_RESULT, 0, Questionnaire_EventScript_Release
	goto_if_eq VAR_RESULT, 1, Questionnaire_EventScript_ThankYou
	end

Questionnaire_EventScript_PlayerInputMysteryEventPhrase::
	goto_if_unset FLAG_SYS_POKEDEX_GET, Questionnaire_EventScript_ThankYou
	goto_if_set FLAG_SYS_MYSTERY_EVENT_ENABLE, Questionnaire_EventScript_ThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Questionnaire_Text_YouKnowThoseWordsEvent, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	msgbox Questionnaire_Text_YouCanAccessMysteryEvent, MSGBOX_DEFAULT
	releaseall
	end

Questionnaire_EventScript_PlayerInputMysteryGiftPhrase::
	goto_if_unset FLAG_SYS_POKEDEX_GET, Questionnaire_EventScript_ThankYou
	goto_if_set FLAG_SYS_MYSTERY_GIFT_ENABLE, Questionnaire_EventScript_ThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Questionnaire_Text_YouKnowThoseWordsGift, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	msgbox Questionnaire_Text_YouCanAccessMysteryGift, MSGBOX_DEFAULT
	releaseall
	end

Questionnaire_EventScript_Release::
	releaseall
	end

Questionnaire_EventScript_ThankYou::
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	msgbox Questionnaire_Text_ThankYou, MSGBOX_DEFAULT
	releaseall
	end
