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
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…\n"
	.string "Qu’est-ce que tu veux?\p"
	.string "Nous sommes occupés.\n"
	.string "Tu ne peux pas revenir plus tard?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…\n"
	.string "Tu as l’air d’être un bon DRESSEUR.\p"
	.string "Hé, hé…\n"
	.string "J’ai quelque chose à te proposer.\p"
	.string "On est un petit groupe et on joue\n"
	.string "à un petit jeu ici. On mise sur ce qui\l"
	.string "se passe à la ZONE DE COMBAT.\p"
	.string "Les règles sont simples.\p"
	.string "D’abord, on choisit un des bâtiments\n"
	.string "de la ZONE DE COMBAT.\p"
	.string "Ensuite, on choisit chacun un DRESSEUR\n"
	.string "qui relève le défi de ce bâtiment et on\l"
	.string "mise des POINTS DE COMBAT dessus.\p"
	.string "Celui qui a misé sur le DRESSEUR qui\n"
	.string "fait le meilleur score récolte tous les\l"
	.string "POINTS DE COMBAT mis en jeu.\p"
	.string "Plutôt simple, non?\n"
	.string "De toute façon…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT SOLO\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT DUO\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des SALLES DE COMBAT MULTI\l"
	.string "de la TOUR DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\l"
	.string "SOLO du DOME DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\l"
	.string "DUO du DOME DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ECHANGE SOLO de l’USINE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ECHANGE DUO de l’USINE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des HALLS DE COMBAT SOLO\l"
	.string "du PALACE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Je cherche un DRESSEUR qui va relever\n"
	.string "le défi des HALLS DE COMBAT DUO\l"
	.string "du PALACE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI K.O. du\l"
	.string "DOJO DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT HASARD\l"
	.string "au REPTILE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT QUETE\l"
	.string "dans la PYRAMIDE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul DRESSEUR\n"
	.string "à la hauteur.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Bien sûr, tu ne feras pas ça pour rien.\n"
	.string "Qu’est-ce que tu en dis?\l"
	.string "Tu veux bien être ce DRESSEUR?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Très bien. Parfait.\n"
	.string "Heu… Tu veux bien me prêter\l"
	.string "quelques POINTS DE COMBAT?\p"
	.string "Fais-moi confiance, je te remercierai\n"
	.string "comme il se doit.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Super!\n"
	.string "Combien tu peux me prêter?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Non mais!\n"
	.string "Tu n’as pas assez de POINTS DE COMBAT!\p"
	.string "Ça t’amuse de faire perdre leur temps\n"
	.string "aux honnêtes gens?$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Hé, hé! Merci bien!\n"
	.string "C’est parti!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Vite, les SALLES DE COMBAT SOLO\n"
	.string "de la TOUR DE COMBAT t’attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Vite, les SALLES DE COMBAT DUO\n"
	.string "de la TOUR DE COMBAT t’attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Vite, les SALLES DE COMBAT MULTI\n"
	.string "de la TOUR DE COMBAT t’attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Vite, le TOURNOI DE COMBAT SOLO\n"
	.string "du DOME DE COMBAT t’attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Vite, le TOURNOI DE COMBAT DUO\n"
	.string "du DOME DE COMBAT t’attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "SOLO de l’USINE DE COMBAT t’attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "DUO de l’USINE DE COMBAT t’attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Vite, les HALLS DE COMBAT SOLO\n"
	.string "du PALACE DE COMBAT t’attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Vite, les HALLS DE COMBAT DUO\n"
	.string "du PALACE DE COMBAT t’attendent!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Vite, le TOURNOI K.O. du DOJO DE\n"
	.string "COMBAT t’attend!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Vite, le défi du COMBAT HASARD\n"
	.string "t’attend au REPTILE DE COMBAT!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Vite, le défi du COMBAT QUETE\n"
	.string "t’attend dans la PYRAMIDE DE COMBAT!\p"
	.string "Tu dois gagner!\n"
	.string "Je compte sur toi!\l"
	.string "Notre avenir à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, c’est toi…\n"
	.string "C’était bien tenté…\p"
	.string "Malheureusement, je ne peux pas te\n"
	.string "rendre ce que tu m’as prêté…\p"
	.string "Ça nous apprendra à faire plus\n"
	.string "attention la prochaine fois!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Bravo!\n"
	.string "Tu as été formidable!\p"
	.string "Je le savais!\n"
	.string "Je te faisais confiance!\l"
	.string "On est les meilleurs!\p"
	.string "Je te rends ce que tu m’as prêté avec\n"
	.string "un petit extra!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} reçoit\n"
	.string "{STR_VAR_1} POINTS DE COMBAT.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si tu as envie de relever un autre\n"
	.string "défi, pense à moi!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Ça ne t’intéresse pas?\n"
	.string "Penses-y, au moins!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "J’ai encore misé sur le mauvais\n"
	.string "DRESSEUR!\p"
	.string "Je crois que je devrais arrêter ces\n"
	.string "bêtises…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Ce DRESSEUR…\p"
	.string "Il est bon, mais il n’a pas les nerfs\n"
	.string "assez solides pour le DOME DE COMBAT…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hi, hi, hi!\n"
	.string "Je sais reconnaître un gagnant!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Ces DRESSEURS…\n"
	.string "Mais que font-ils?\l"
	.string "Ils devraient aller se battre.$"
