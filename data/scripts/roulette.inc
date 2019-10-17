Roulette_EventScript_Table1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, 0
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, 128
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, 0
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, 128
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play:: @ 82A5B0D
	special PlayRoulette
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX::
	.string "여기는 레이트 {STR_VAR_1}의 룰렛입니다\n"
	.string "룰렛으로 즐기겠습니까?$"

Roulette_Text_NotEnoughCoins::
	.string "동전이 없습니다$"

Roulette_Text_SpecialRateTable::
	.string "오늘 이 테이블은\n레이트 업!$"

Roulette_Text_ControlsInstruction::
	.string "배팅할 곳을 십자 버튼으로 선택하고\n"
	.string "A 버튼으로 결정합니다$"

Roulette_Text_ItsAHit::
	.string "당첨-!$"

Roulette_Text_Jackpot::
	.string "대당첨!!$"

Roulette_Text_NothingDoing::
	.string "꽝…$"

Roulette_Text_YouveWonXCoins::
	.string "동전 {STR_VAR_1}개를 얻습니다!$"

Roulette_Text_NoCoinsLeft::
	.string "동전이 다 떨어졌다…$"

Roulette_Text_KeepPlaying::
	.string "계속해서 즐기겠습니까?$"

Roulette_Text_BoardWillBeCleared::
	.string "테이블 위의 구슬들을\n리셋합니다$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "동전케이스를 가지고 있지 않습니다$"

Roulette_Text_CoinCaseIsFull::
	.string "동전이 가득 찼습니다!\n"
	.string "경품과 교환해 주십시오$"
