MauvilleCity_GameCorner_EventScript_2A5AB1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 0
	getpricereduction 2
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5ADF:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 1
	getpricereduction 2
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5B0D:: @ 82A5B0D
	special PlayRoulette
	waitstate
	end
	
gUnknown_082A5B12::
	.string "여기는 레이트 {STR_VAR_1}의 룰렛입니다\n"
	.string "룰렛으로 즐기겠습니까?$"

gUnknown_082A5B4E::
	.string "동전이 없습니다$"

gUnknown_082A5B6B::
	.string "오늘 이 테이블은\n레이트 업!$"

gUnknown_082A5B89::
	.string "배팅할 곳을 십자 버튼으로 선택하고\n"
	.string "A 버튼으로 결정합니다$"

gUnknown_082A5BCB::
	.string "당첨-!$"

gUnknown_082A5BD7::
	.string "대당첨!!$"

gUnknown_082A5BE0::
	.string "꽝…$"

gUnknown_082A5BEF::
	.string "동전 {STR_VAR_1}개를 얻습니다!$"

gUnknown_082A5C04::
	.string "동전이 다 떨어졌다…$"

gUnknown_082A5C13::
	.string "계속해서 즐기겠습니까?$"

gUnknown_082A5C21::
	.string "테이블 위의 구슬들을\n리셋합니다$"

gUnknown_082A5C45::
	.string "동전케이스를 가지고 있지 않습니다$"

gUnknown_082A5C61::
	.string "동전이 가득 찼습니다!\n"
	.string "경품과 교환해 주십시오$"
