.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "DOME DE COMBAT\n"
	.string "“La voie toute tracée vers la\l"
	.string "célébrité!”$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "USINE DE COMBAT\n"
	.string "“Nos POKéMON sont les plus forts!”$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "REPTILE DE COMBAT\n"
	.string "“Choisissez un des trois chemins!”$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Voici la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y amènent leurs\n"
	.string "meilleurs POKéMON pour participer à des\l"
	.string "matchs éliminatoires.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Bonjour, vous venez pour le ferry?\n"
	.string "Puis-je voir votre PASSE BATEAU?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} n’a pas de PASSE BATEAU…\p"
	.string "Je suis absolument désolée.\p"
	.string "Il vous faut un PASSE pour embarquer\n"
	.string "à bord du ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} montre son PASSE BATEAU.\p"
	.string "Parfait! Vous pouvez entrer!\p"
	.string "Où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "POIVRESSEL? C’est parti!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "NENUCRIQUE? C’est parti!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Revenez nous voir une autre fois!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Veuillez embarquer à bord du ferry et\n"
	.string "attendre le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Alors, où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Je suis meilleur que tous mes copains.\n"
	.string "Mais ici…\l"
	.string "Je suis nul!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Je veux aller à la TOUR DE COMBAT,\n"
	.string "mais je ne la trouve pas. Pourtant, j’ai\l"
	.string "une carte de la ZONE DE COMBAT.\p"
	.string "Cet endroit est vraiment immense!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Mon intention était de relever un défi\n"
	.string "dès mon arrivée ici.\p"
	.string "Mais en chemin, j’ai eu le mal de mer…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Tout le monde ne peut pas venir ici,\n"
	.string "tu sais.\p"
	.string "Seuls les DRESSEURS dont le talent\n"
	.string "a été reconnu sont ici.\p"
	.string "Beaucoup de DRESSEURS n’ont jamais\n"
	.string "entendu parler de la ZONE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Dis…\p"
	.string "Tu penses qu’on peut participer même si\n"
	.string "on n’a pas de POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Heu…\n"
	.string "Ben, c’est ce qu’on m’a dit.\p"
	.string "Enfin, je crois…\p"
	.string "Et tu te souviens de ce que m’a dit le\n"
	.string "colosse?\p"
	.string "Il m’a dit qu’il me prêterait des\n"
	.string "POKéMON!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "C’est l’USINE DE COMBAT.\n"
	.string "Tu peux y louer des POKéMON très forts.\p"
	.string "Mais au fait… Je me demande\n"
	.string "qui élève ces POKéMON de location!?!$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "J’ai peur d’aller au REPTILE DE COMBAT\n"
	.string "à cause de SEVIPER…\p"
	.string "Mais je ne suis pas venue ici pour rien!\n"
	.string "Je vais me battre!\l"
	.string "… J’ai peur…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Jouons à pierre, papier, ciseaux!\n"
	.string "Un, deux, trois!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Oui! J’ai gagné! Je vais relever le défi\n"
	.string "du REPTILE DE COMBAT!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, non…\n"
	.string "J’ai perdu.\p"
	.string "Ce n’est pas mon jour de chance.\n"
	.string "Je vais attendre demain pour relever le\l"
	.string "défi du REPTILE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Je suis persuadé que je suis la seule\n"
	.string "personne ici qui préfère la pêche aux\l"
	.string "combats.\p"
	.string "Comment? Il n’y a rien à pêcher ici?\n"
	.string "C’est dommage, c’est un bel endroit…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Aujourd’hui, je n’arrêterai de combattre\n"
	.string "que quand j’aurai un symbole!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Tu veux relever le défi du DOME DE\n"
	.string "COMBAT?\p"
	.string "Je te souhaite bonne chance.\n"
	.string "Ce serait amusant, si l’on se retrouvait\l"
	.string "face à face lors d’un combat.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Papy, par ici!\n"
	.string "Le DOME DE COMBAT est là!\l"
	.string "Vas-y, papy!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "C’est donc ça, le DOME DE COMBAT?\n"
	.string "Aucun GENTLEMAN ne pourra me battre!\p"
	.string "Mais où est l’entrée?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Il n’y a pas si longtemps, il n’y avait\n"
	.string "rien à cet endroit.\p"
	.string "Mais maintenant, regarde! Incroyable!\n"
	.string "Il faut que j’emmène ma mère ici.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Je suis enfin arrivée à la ZONE DE\n"
	.string "COMBAT!\p"
	.string "Mon physique avantageux et ma\n"
	.string "technique me feront sûrement gagner!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Miam, miam…\p"
	.string "On dirait que tout le monde est très\n"
	.string "fort ici.\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Miam, miam…\p"
	.string "Il y a un certain temps, j’ai rencontré\n"
	.string "cette femme au REPTILE DE COMBAT.\p"
	.string "Elle avait un regard effrayant, ça m’a\n"
	.string "fichu la frousse.\p"
	.string "Miam, miam…\p"
	.string "Elle m’a hurlé dessus: “Arrête de\n"
	.string "manger!” et s’est mise à rire!\p"
	.string "J’en ai eu la chair de poule…\n"
	.string "J’entends encore son rire…\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Non mais, écoute ce que tu dis!\n"
	.string "Ça ne veut rien dire, ça!\p"
	.string "Lors du dernier match, il m’a regardée\n"
	.string "et j’ai vu des étincelles dans ses yeux!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quoi???\n"
	.string "Pfft!\p"
	.string "Si je n’avais pas été assis à côté de\n"
	.string "toi, il ne t’aurait même pas regardée!\p"
	.string "Ce sont mes encouragements qui ont\n"
	.string "attiré le regard de la STAR DU DOME!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, chut!\n"
	.string "Mettez-la un peu en sourdine!\p"
	.string "Vous, les fans, vous devriez vous\n"
	.string "contenter des CHAMPION D’ARENE!\p"
	.string "La STAR DU DOME est à moi!\n"
	.string "C’est mon idole!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Ces gens qui se disputent là-bas…\p"
	.string "C’est dur à croire, mais ils étaient\n"
	.string "DRESSEURS, avant. Ils étaient bons.\p"
	.string "Ils avaient une force incroyable et ils\n"
	.string "étaient même célèbres!\p"
	.string "Mais ils se sont fait écraser par un\n"
	.string "DRESSEUR lors d’un tournoi.\p"
	.string "Leur défaite a été telle qu’ils ont été\n"
	.string "subjugués par lui.\p"
	.string "Maintenant, ce sont des fans.\n"
	.string "Ils vont au DOME DE COMBAT\l"
	.string "tous les jours pour l’encourager.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Il paraît que quelqu’un a vu un POKéMON\n"
	.string "avec une queue incroyablement\l"
	.string "longue dans la ZONE DE COMBAT.\p"
	.string "Il doit être adorable…\p"
	.string "Les défis peuvent bien attendre!\n"
	.string "Je vais tenter de trouver cette\l"
	.string "charmante créature!$"

