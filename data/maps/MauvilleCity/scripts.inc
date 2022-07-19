.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM24
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM24_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "TONTON: C’est grâce aux POKéMON\n"
	.string "que ce garçon a retrouvé la pêche…\p"
	.string "Mais il l’a même un peu trop maintenant…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "TIMMY: Oh, TONTON, s’il te plaît.\p"
	.string "Je veux me battre dans cette ARENE\n"
	.string "pour voir à quel point j’ai progressé.\p"
	.string "S’il te plaît! Je peux?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "TONTON: Attends, TIMMY.\p"
	.string "Depuis que tu as commencé à vivre avec\n"
	.string "ton POKéMON, tu es devenu plus fort.\p"
	.string "Mais tu ne trouves pas que combattre\n"
	.string "dans une ARENE est un peu prématuré?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "TIMMY: Pas du tout.\p"
	.string "Quand je suis avec mon TARSAL,\n"
	.string "on peut battre n’importe qui!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "TIMMY: Oh! Salut, {PLAYER}!\p"
	.string "Je suis devenu bien plus fort depuis\n"
	.string "notre dernière rencontre.\p"
	.string "{PLAYER}, je veux que mon oncle et toi\n"
	.string "compreniez ça.\p"
	.string "{PLAYER}, tu acceptes de te battre\n"
	.string "contre moi?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "TIMMY: Oh… Si tu n’acceptes pas de\n"
	.string "m’affronter, mon oncle ne pourra pas\l"
	.string "voir que je suis devenu vraiment fort.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "TONTON: {PLAYER}{KUN}.\n"
	.string "De la part de TIMMY, je peux te\l"
	.string "demander de l’affronter juste une fois?\p"
	.string "Vu l’état dans lequel il est, je ne pense\n"
	.string "pas qu’il reviendra à la raison.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "TIMMY: {PLAYER}, s’il te plaît!\n"
	.string "Bats-toi contre moi, je t’en supplie.$"

MauvilleCity_Text_WallyHereICome:
	.string "TIMMY: Merci, {PLAYER}.\p"
	.string "OK. J’arrive!$"

MauvilleCity_Text_WallyDefeat:
	.string "TIMMY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "J’ai perdu…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "TIMMY: TONTON…\n"
	.string "Je vais rentrer à VERGAZON…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "Merci, {PLAYER}.\n"
	.string "C’est dur d’être DRESSEUR, hein?\p"
	.string "Il ne suffit pas d’avoir des POKéMON\n"
	.string "et de les envoyer au combat. C’est pas\l"
	.string "ça être un vrai DRESSEUR.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "TONTON: TIMMY, ce n’est pas la peine\n"
	.string "d’être aussi dur avec toi-même.\p"
	.string "Rien ne t’empêche de devenir encore\n"
	.string "plus fort!\p"
	.string "Allez viens, rentrons chez nous.\n"
	.string "Tout le monde t’attend.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "TONTON: {PLAYER}{KUN}, je viens juste de\n"
	.string "réaliser que tu dois être le DRESSEUR\l"
	.string "qui a gardé un œil sur TIMMY quand il\l"
	.string "a attrapé son POKéMON.\p"
	.string "Pourquoi ne viendrais-tu pas nous voir\n"
	.string "à VERGAZON un de ces jours?\p"
	.string "Ça ferait sûrement plaisir à TIMMY.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "TIMMY: Oh, bonjour, {PLAYER}!\p"
	.string "Je voulais juste te dire que mon\n"
	.string "oncle m’a acheté un POKéNAV!\p"
	.string "Je peux t’appeler quand je veux!\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic!$"

MauvilleCity_Text_RegisteredWally:
	.string "Vous avez enregistré TIMMY dans\n"
	.string "le POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Héhé…\n"
	.string "J’ai assisté à ton combat!\p"
	.string "TIMMY et toi êtes amis, n’est-ce pas?\p"
	.string "Mais tu n’as pourtant pas retenu tes\n"
	.string "coups et tu l’as battu magistralement!\p"
	.string "C’est ça que j’aime dans les combats\n"
	.string "de POKéMON!\p"
	.string "J’adore les DRESSEURS comme toi!\p"
	.string "… … … … … …\p"
	.string "Tu peux compter sur moi pour\n"
	.string "t’encourager!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "VOLTERE: Oh, {PLAYER}{KUN}!\p"
	.string "Tu sembles avoir beaucoup d’entrain!\n"
	.string "C’est une bonne chose, ah, ah, ah!\p"
	.string "Bien! J’ai pris une décision!\n"
	.string "J’ai une faveur à te demander, {PLAYER}{KUN}!\p"
	.string "LAVANDIA comprend une partie\n"
	.string "souterraine appelée NEW LAVANDIA.\p"
	.string "{PLAYER}{KUN}, j’aimerais que tu t’y rendes et\n"
	.string "que tu éteignes le GENERATEUR.\p"
	.string "Le GENERATEUR fonctionne un peu\n"
	.string "bizarrement. Ça devient dangereux.\p"
	.string "Tiens, voilà la CLE pour pouvoir\n"
	.string "entrer dans NEW LAVANDIA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "VOLTERE: Ne t’inquiète pas pour ça.\n"
	.string "Ce ne sera pas trop dur pour toi.\p"
	.string "Pour arriver à NEW LAVANDIA, un peu de\n"
	.string "SURF au bout de la ROUTE 110 suffira.\p"
	.string "C’est tout. Alors tu as ma confiance!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "VOLTERE: Wahahahaha!\p"
	.string "Je l’savais, {PLAYER}{KUN}! Je savais que\n"
	.string "j’avais raison en m’adressant à toi!\p"
	.string "Voilà ma façon de te remercier: une CT\n"
	.string "contenant TONNERRE!\p"
	.string "Allez, tu l’as bien méritée!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "VOLTERE: Wahahahaha!\p"
	.string "Je suis très content de voir les jeunes\n"
	.string "avancer et prendre les choses en main.$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Tu sais, c’est bien gentil d’envoyer les\n"
	.string "POKéMON au combat…\p"
	.string "Mais si un de tes POKéMON est blessé, tu\n"
	.string "dois le soigner pour qu’il soit en forme.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Les routes de cette ville s’étendent du\n"
	.string "nord au sud et d’est en ouest.\p"
	.string "Alors ici, les gens viennent de partout.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Tu connais les CYCLES RODOLPHE?\p"
	.string "RODOLPHE, le propriétaire, est un homme\n"
	.string "très généreux.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Même si tu es sur ton VELO, les\n"
	.string "POKéMON peuvent te sauter dessus.$"

MauvilleCity_Text_CitySign:
	.string "LAVANDIA\n"
	.string "“La brillante ville du fun!”$"

MauvilleCity_Text_GymSign:
	.string "ARENE POKéMON de LAVANDIA\n"
	.string "CHAMPION: VOLTERE\l"
	.string "“Un homme électrifiant!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Roule sur le gravier et remets\n"
	.string "tes idées en place!”\l"
	.string "CYCLES RODOLPHE$"

MauvilleCity_Text_GameCornerSign:
	.string "“La salle de jeux pour tous!”\n"
	.string "CASINO DE LAVANDIA$"

MauvilleCity_Text_ExplainTV:
	.string "Salut, ça t’arrive de regarder\n"
	.string "la télé?\p"
	.string "Plusieurs nouvelles émissions très\n"
	.string "sympas ont récemment été\l"
	.string "programmées.\p"
	.string "C’est sympa. J’ai vu mes amis à la télé\n"
	.string "alors que je ne m’y attendais pas.\p"
	.string "Quelquefois, ils te font même passer\n"
	.string "à la télé sans te le dire.\p"
	.string "J’espère que je passerai moi aussi\n"
	.string "à la télé un jour.\p"
	.string "Tu vois, tu devrais regarder la télé\n"
	.string "le plus souvent possible.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Salut! T’as regardé la télé?$"
