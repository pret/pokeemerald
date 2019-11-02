AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_237A93::
	msgbox AbandonedShip_Rooms_1F_Text_237B15, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_237A9C::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_237D0C, AbandonedShip_Rooms_1F_Text_237D2A
	msgbox AbandonedShip_Rooms_1F_Text_237D41, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_237AB3::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_237B76, AbandonedShip_Rooms_1F_Text_237BB8, AbandonedShip_Rooms_1F_EventScript_237ADF
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms_1F_EventScript_237AFE
	msgbox AbandonedShip_Rooms_1F_Text_237BDB, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_237ADF::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_237C2A, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_237AFE::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_237C69, AbandonedShip_Rooms_1F_Text_237CB2
	msgbox AbandonedShip_Rooms_1F_Text_237CC9, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_237B15:
	.string "이런 장소는 희귀하니\n"
	.string "견학을 하고 있다네\p"
	.string "흠흠...\n"
	.string "다른 방도 있는 것 같군$"

AbandonedShip_Rooms_1F_Text_237B76:
	.string "여기서 뭐 하는 거지?\n"
	.string "호기심이 많은 아이구나!$"

AbandonedShip_Rooms_1F_Text_237BB8:
	.string "호기심도 많고 강하잖아...$"

AbandonedShip_Rooms_1F_Text_237BDB:
	.string "문 옆에 계신 신사분...\p"
	.string "견학하러 왔다고는 하는데\n"
	.string "아무래도 꿍꿍이가 있는 것 같아$"

AbandonedShip_Rooms_1F_Text_237C2A:
	.string "넌 정말 강한 트레이너구나!\n"
	.string "기념으로 등록해줘!$"

AbandonedShip_Rooms_1F_Text_237C69:
	.string "여기서 또 뭐 하는 거지?\n"
	.string "여전히 호기심이 많은 아이구나!$"

AbandonedShip_Rooms_1F_Text_237CB2:
	.string "여전히 호기심도 많고 강하잖아$"

AbandonedShip_Rooms_1F_Text_237CC9:
	.string "저 신사분 확실히 꿍꿍이가 있어!\n"
	.string "너무 수상하게 행동한다니까!$"

AbandonedShip_Rooms_1F_Text_237D0C:
	.string "으악!\n"
	.string "걸렸다! ...응?$"

AbandonedShip_Rooms_1F_Text_237D2A:
	.string "우리 엄마가 아니잖아$"

AbandonedShip_Rooms_1F_Text_237D41:
	.string "사고 쳐서 도망쳐온 거니까\n"
	.string "우리 엄마한테는 비밀이야$"

