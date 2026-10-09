Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "De minimale inzet aan deze tafel\n"
	.string "is {STR_VAR_1}. Wil je spelen?$"

Roulette_Text_NotEnoughCoins::
	.string "Je hebt niet genoeg MUNTEN.$"

Roulette_Text_SpecialRateTable::
	.string "Nu een tafel met speciaal tarief!$"

Roulette_Text_ControlsInstruction::
	.string "Zet in met de + Control Pad\n"
	.string "en druk dan op de A-knop.$"

Roulette_Text_ItsAHit::
	.string "Raak!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Mis!$"

Roulette_Text_YouveWonXCoins::
	.string "Je wint {STR_VAR_1} MUNTEN!$"

Roulette_Text_NoCoinsLeft::
	.string "Geen MUNTEN meer…$"

Roulette_Text_KeepPlaying::
	.string "Verder spelen?$"

Roulette_Text_BoardWillBeCleared::
	.string "Het ROULETTE-bord wordt leeggemaakt.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Je hebt geen MUNTENDOOS.$"

Roulette_Text_CoinCaseIsFull::
	.string "Je MUNTENDOOS is vol!\n"
	.string "MUNTEN kun je ruilen voor prijzen.$"
