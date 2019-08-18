AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_2380A7::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_23819D, AbandonedShip_Rooms2_1F_Text_2381DA, AbandonedShip_Rooms2_1F_Text_238257, AbandonedShip_Rooms2_1F_EventScript_2380D7
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_2380F0
	msgbox AbandonedShip_Rooms2_1F_Text_23820F, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380D7::
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_2380F0::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2383FF, AbandonedShip_Rooms2_1F_Text_238473, AbandonedShip_Rooms2_1F_Text_238509
	msgbox AbandonedShip_Rooms2_1F_Text_238491, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23810B::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_2382A4, AbandonedShip_Rooms2_1F_Text_2382F4, AbandonedShip_Rooms2_1F_Text_23836F, AbandonedShip_Rooms2_1F_EventScript_23813B
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_238154
	msgbox AbandonedShip_Rooms2_1F_Text_23830A, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_23813B::
	msgbox AbandonedShip_Rooms2_1F_Text_2383BB, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_238154::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_238556, AbandonedShip_Rooms2_1F_Text_2385F2, AbandonedShip_Rooms2_1F_Text_238668
	msgbox AbandonedShip_Rooms2_1F_Text_23860B, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_23816F::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_2386B4, AbandonedShip_Rooms2_1F_Text_2386E8
	msgbox AbandonedShip_Rooms2_1F_Text_238708, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_238186::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_23873F, AbandonedShip_Rooms2_1F_Text_238779
	msgbox AbandonedShip_Rooms2_1F_Text_2387A9, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_23819D:
	.string "중문: 보물을 찾고 있었더니\n"
	.string "트레이너를 발견!$"

AbandonedShip_Rooms2_1F_Text_2381DA:
	.string "중문: 보물을 찾고 있었더니\n"
	.string "트레이너를 발견!$"

AbandonedShip_Rooms2_1F_Text_23820F:
	.string "중문: 여기에 있다는 소문을 들었는데\n"
	.string "보물을 찾을 수 없네...\l"
	.string "벌써 누가 가져간 거 아닌가?$"

AbandonedShip_Rooms2_1F_Text_238257:
	.string "중문: 포켓몬 2마리가 없구나\n"
	.string "그럼 우리를 이길 수 없어!$"

AbandonedShip_Rooms2_1F_Text_2382A4:
	.string "소영: 어머? 보물을 찾고 있었는데\n"
	.string "트레이너를 발견했어요!$"

AbandonedShip_Rooms2_1F_Text_2382F4:
	.string "소영: 강하군요!$"

AbandonedShip_Rooms2_1F_Text_23830A:
	.string "소영: 이런 낡은 장소에 있는\n"
	.string "보물이란 무엇일까?\l"
	.string "뭐 어쨌든 뭘 살지를 정하고 있어$"

AbandonedShip_Rooms2_1F_Text_23836F:
	.string "소영: 어머?\n"
	.string "포켓몬 2마리가 아니군요?\l"
	.string "그럼 승부는 다음에 해야겠네요!$"

AbandonedShip_Rooms2_1F_Text_2383BB:
	.string "소영: 당신, 사람 짜증 나게 하는데\n"
	.string "재능이 있군요\p"
	.string "그러니 절 포켓내비에\n"
	.string "등록해 주셔야 겠어요$"

AbandonedShip_Rooms2_1F_Text_2383FF:
	.string "중문: 계속 보물을 찾고 있다 보니\n"
	.string "포켓몬도 강해졌다고-!\p"
	.string "살짝 상대해 줘$"

AbandonedShip_Rooms2_1F_Text_238473:
	.string "중문: 변함없이 강하군!$"

AbandonedShip_Rooms2_1F_Text_238491:
	.string "중문: 보물도 못 찾겠고\n"
	.string "포켓몬 승부도 져버렸으니\l"
	.string "이제 집에 돌아가고 싶다\p"
	.string "하지만 그런 말을 하면\n"
	.string "그녀가 화를 내니까...$"

AbandonedShip_Rooms2_1F_Text_238509:
	.string "중문: 포켓몬 2마리가 없구나\n"
	.string "그럼 우리를 이길 수 없어!$"

AbandonedShip_Rooms2_1F_Text_238556:
	.string "소영: 어머? 또 만났군요?!\n"
	.string "우리처럼 포기하지 않고\l"
	.string "보물을 찾고 있나보죠?!\p"
	.string "승부해서 진 쪽이\n"
	.string "먼저 포기하는 걸로 하지 않을래요?$"

AbandonedShip_Rooms2_1F_Text_2385F2:
	.string "소영: 또 져버렸어...$"

AbandonedShip_Rooms2_1F_Text_23860B:
	.string "소영: 더욱 포켓몬을 키워서\p"
	.string "보물을 찾아낼 때까지\n"
	.string "돌아가지 않을 거예요!$"

AbandonedShip_Rooms2_1F_Text_238668:
	.string "소영: 어머?\n"
	.string "포켓몬 2마리가 아니군요?\l"
	.string "그럼 승부는 다음에 해야겠네요!$"

AbandonedShip_Rooms2_1F_Text_2386B4:
	.string "난 수영은 잘 못하지만\n"
	.string "포켓몬 배틀은 잘하지!$"

AbandonedShip_Rooms2_1F_Text_2386E8:
	.string "이런\n"
	.string "포켓몬 배틀도 못하잖아$"

AbandonedShip_Rooms2_1F_Text_238708:
	.string "이 배에서\n"
	.string "맨발로 돌아다니는 건 좀 그래$"

AbandonedShip_Rooms2_1F_Text_23873F:
	.string "강인함과 상대에 대한 배려...\n"
	.string "그것이 트레이너의 보물이다!$"

AbandonedShip_Rooms2_1F_Text_238779:
	.string "너는 이미\n"
	.string "알고 있는 것 같구나$"

AbandonedShip_Rooms2_1F_Text_2387A9:
	.string "이 배 한 선원실에서\n"
	.string "반짝거리는 걸 본 것 같은데$"
