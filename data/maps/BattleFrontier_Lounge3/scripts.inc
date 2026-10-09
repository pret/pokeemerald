BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Wat wil je?\p"
	.string "Zie je niet dat we het druk hebben?\n"
	.string "Kan het niet later?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Hè?\n"
	.string "Jij ziet eruit als een sterke TRAINER.\p"
	.string "Heheh…\n"
	.string "Luister, ik heb een voorstel.\p"
	.string "We hebben hier een groepje en we\n"
	.string "spelen een spelletje over wat er in\l"
	.string "de BATTLE FRONTIER gebeurt.\p"
	.string "De regels zijn heel simpel.\p"
	.string "Eerst kiezen we een gebouw in\n"
	.string "de BATTLE FRONTIER.\p"
	.string "Dan kiest iedereen een andere TRAINER\n"
	.string "die daar meedoet, en we zetten\l"
	.string "GEVECHTSPUNTEN in.\p"
	.string "Wie op de TRAINER met het beste\n"
	.string "record zette, wint alle\l"
	.string "GEVECHTSPUNTEN in de pot.\p"
	.string "Klinkt simpel, hè?\n"
	.string "Nou, hoe dan ook…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "de ENKEL GEVECHT-KAMERS van de\l"
	.string "BATTLE TOWER.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "de DUBBEL GEVECHT-KAMERS van de\l"
	.string "BATTLE TOWER.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "de MULTI-GEVECHTSKAMERS van de\l"
	.string "BATTLE TOWER.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "het ENKEL GEVECHT-toernooi van de\l"
	.string "BATTLE DOME.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "het DUBBEL GEVECHT-toernooi van de\l"
	.string "BATTLE DOME.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "het WISSELGEVECHT Enkel-toernooi van\l"
	.string "de BATTLE FACTORY.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "het WISSELGEVECHT Dubbel-toernooi van\l"
	.string "de BATTLE FACTORY.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "de ENKEL GEVECHT-ZALEN van het\l"
	.string "BATTLE PALACE.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "de DUBBEL GEVECHT-ZALEN van het\l"
	.string "BATTLE PALACE.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "het KO-toernooi van de\l"
	.string "BATTLE ARENA.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "KEUZEGEVECHT van de BATTLE PIKE.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Ik zoek een TRAINER die meedoet aan\n"
	.string "GEVECHTSTOCHT van de\l"
	.string "BATTLE PYRAMID.\p"
	.string "Maar tot nu toe heb ik geen TRAINER\n"
	.string "gezien die wil winnen.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Jij profiteert er ook van.\n"
	.string "Dus, wat zeg je?\l"
	.string "Doe je voor mij mee aan dat toernooi?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Prima, perfect.\n"
	.string "Dus eh… Leen je me een paar van\l"
	.string "je GEVECHTSPUNTEN?\p"
	.string "Vertrouw me, ik bedank je er later\n"
	.string "voor.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Super, super!\n"
	.string "Hoeveel kun je me lenen?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh nee, nee, nee!\n"
	.string "Je hebt niet genoeg GEVECHTSPUNTEN!\p"
	.string "Doe niet zo flauw en verspil\n"
	.string "niet ieders tijd!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Heheh! Hartstikke bedankt!\n"
	.string "Nou, ga maar!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Ga snel naar de ENKEL GEVECHT-KAMERS\n"
	.string "van de BATTLE TOWER!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Ga snel naar de DUBBEL GEVECHT-KAMERS\n"
	.string "van de BATTLE TOWER!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Ga snel naar de MULTI-GEVECHTSKAMERS\n"
	.string "van de BATTLE TOWER!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Ga snel naar het ENKEL GEVECHT-\n"
	.string "toernooi van de BATTLE DOME!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Ga snel naar het DUBBEL GEVECHT-\n"
	.string "toernooi van de BATTLE DOME!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Ga snel naar het WISSELGEVECHT Enkel-\n"
	.string "toernooi van de BATTLE FACTORY!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Ga snel naar het WISSELGEVECHT Dubbel-\n"
	.string "toernooi van de BATTLE FACTORY!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Ga snel naar de ENKEL GEVECHT-ZALEN\n"
	.string "van het BATTLE PALACE!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Ga snel naar de DUBBEL GEVECHT-ZALEN\n"
	.string "van het BATTLE PALACE!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Ga snel naar het KO-toernooi\n"
	.string "van de BATTLE ARENA!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Ga snel naar KEUZEGEVECHT\n"
	.string "van de BATTLE PIKE!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Ga snel naar GEVECHTSTOCHT\n"
	.string "van de BATTLE PYRAMID!\p"
	.string "Je moet winnen!\n"
	.string "Verpest je kans niet!\l"
	.string "Onze toekomst hangt van je af!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, jij bent het…\n"
	.string "Goed geprobeerd…\p"
	.string "Het spijt me, maar ik kan je\n"
	.string "GEVECHTSPUNTEN niet teruggeven…\p"
	.string "Laten we ons daardoor de volgende keer\n"
	.string "extra inspannen!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh ja!\n"
	.string "Hallo, kampioen!\p"
	.string "Ik wist dat je het kon!\n"
	.string "Ik wist het!\l"
	.string "We zijn allebei grote winnaars!\p"
	.string "Ik geef je GEVECHTSPUNTEN terug\n"
	.string "en natuurlijk een extraatje van mij!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} krijgt\n"
	.string "{STR_VAR_1} GEVECHTSPUNTEN.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Heb je zin in nog een uitdaging,\n"
	.string "denk dan aan mij!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Geen zin?! Wees niet zo bang om\n"
	.string "een kans te wagen!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Ik zette weer op de verkeerde TRAINER!\p"
	.string "Misschien moet ik gewoon normaal\n"
	.string "vechten, zoals iedereen…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Die TRAINER…\p"
	.string "Hij is goed, maar hij raakt te snel in\n"
	.string "de war voor de BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hihi!\n"
	.string "Ik herken een winnaar als ik er een zie!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Die TRAINERS…\n"
	.string "Wat doen ze nou?\l"
	.string "Ze moeten meedoen aan uitdagingen.$"
