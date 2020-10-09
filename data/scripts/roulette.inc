Roulette_EventScript_Table1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, FALSE
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpricereduction POKENEWS_GAME_CORNER
	compare VAR_RESULT, FALSE
	goto_if_eq Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play:: @ 82A5B0D
	special PlayRoulette
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX:: @ 82A5B12
	.string "The minimum wager at this table\n"
	.string "is {STR_VAR_1}. Do you want to play?$"

Roulette_Text_NotEnoughCoins:: @ 82A5B4E
	.string "You don't have enough COINS.$"

Roulette_Text_SpecialRateTable:: @ 82A5B6B
	.string "Special rate table right now!$"

Roulette_Text_ControlsInstruction:: @ 82A5B89
	.string "Place your wager with the + Control\n"
	.string "Pad, then press the A Button.$"

Roulette_Text_ItsAHit:: @ 82A5BCB
	.string "It's a hit!$"

Roulette_Text_Jackpot:: @ 82A5BD7
	.string "Jackpot!$"

Roulette_Text_NothingDoing:: @ 82A5BE0
	.string "Nothing doing!$"

Roulette_Text_YouveWonXCoins:: @ 82A5BEF
	.string "You've won {STR_VAR_1} COINS!$"

Roulette_Text_NoCoinsLeft:: @ 82A5C04
	.string "No COINS left…$"

Roulette_Text_KeepPlaying:: @ 82A5C13
	.string "Keep playing?$"

Roulette_Text_BoardWillBeCleared:: @ 82A5C21
	.string "The ROULETTE board will be cleared.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase:: @ 82A5C45
	.string "You don't have a COIN CASE.$"

Roulette_Text_CoinCaseIsFull:: @ 82A5C61
	.string "Your COIN CASE is full!\n"
	.string "Coins can be exchanged for prizes.$"
