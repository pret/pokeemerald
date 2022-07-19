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
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX::
	.string "A cette table, la mise minimum est\n"
	.string "de {STR_VAR_1}. Voulez-vous jouer?$"

Roulette_Text_NotEnoughCoins::
	.string "Vous n’avez pas assez de JETONS.$"

Roulette_Text_SpecialRateTable::
	.string "En ce moment, table à tarif spécial!$"

Roulette_Text_ControlsInstruction::
	.string "Placez votre mise avec la manette +\n"
	.string "et appuyez sur le bouton A.$"

Roulette_Text_ItsAHit::
	.string "Vous avez gagné!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Vous avez perdu!$"

Roulette_Text_YouveWonXCoins::
	.string "Vous avez gagné {STR_VAR_1} JETONS!$"

Roulette_Text_NoCoinsLeft::
	.string "Plus assez de JETONS…$"

Roulette_Text_KeepPlaying::
	.string "Continuer à jouer?$"

Roulette_Text_BoardWillBeCleared::
	.string "La ROULETTE va être relancée.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "You don’t have a COIN CASE.$"

Roulette_Text_CoinCaseIsFull::
	.string "Votre BOITE JETONS est pleine! On peut\n"
	.string "échanger vos JETONS contre des lots.$"
