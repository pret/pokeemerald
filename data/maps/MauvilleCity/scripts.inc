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
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
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
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
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
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
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
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
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
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
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
	.string "OOM: Door POKéMON heeft deze jongen\n"
	.string "veel meer energie gekregen…\l"
	.string "Maar nu is hij een beetje té druk…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Ah, OOM, alsjeblieft?\p"
	.string "Ik wil deze GYM uitdagen. Dan zie ik\n"
	.string "hoeveel beter ik ben geworden.\p"
	.string "Alsjeblieft? Mag het?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "OOM: Wacht even, WALLY.\p"
	.string "Sinds je met POKéMON leeft,\n"
	.string "ben je veel sterker geworden.\p"
	.string "Maar is het niet te vroeg om\n"
	.string "meteen een GYM uit te dagen?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Het is niet te vroeg.\p"
	.string "Als RALTS en ik samenwerken,\n"
	.string "kunnen we iedereen verslaan!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Oh! Hoi, {PLAYER}!\p"
	.string "Ik ben veel sterker geworden sinds\n"
	.string "we elkaar zagen.\p"
	.string "{PLAYER}, ik wil dat jij en mijn OOM\n"
	.string "dat snappen.\p"
	.string "{PLAYER}, wil je alsjeblieft\n"
	.string "tegen me vechten?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Oh… Als je niet tegen me vecht,\n"
	.string "{PLAYER}, weet mijn OOM niet dat ik\l"
	.string "echt sterk ben geworden.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "OOM: {PLAYER}{KUN}, toch?\n"
	.string "Mag ik je iets vragen voor WALLY?\l"
	.string "Wil je één keer tegen hem vechten?\p"
	.string "Zo als hij nu is, luistert hij\n"
	.string "toch niet naar mij.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, alsjeblieft!\n"
	.string "Vecht tegen me, alsjeblieft.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, dank je wel.\p"
	.string "Oké… Daar ga ik!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Ik heb verloren…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: OOM…\n"
	.string "Ik ga terug naar VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, dank je wel.\n"
	.string "TRAINER zijn is moeilijk, hè?\p"
	.string "Het is niet genoeg om POKéMON te\n"
	.string "hebben en ze te laten vechten.\l"
	.string "Zo word je geen echte TRAINER.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "OOM: WALLY, je hoeft niet zo\n"
	.string "somber te zijn.\p"
	.string "Niets houdt je tegen om steeds\n"
	.string "sterker te worden.\p"
	.string "Kom, we gaan naar huis.\n"
	.string "Iedereen wacht op je.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "OOM: {PLAYER}{KUN}, nu snap ik het pas.\n"
	.string "Jij bent die TRAINER die op WALLY\l"
	.string "heeft gelet toen hij zijn eerste\l"
	.string "POKéMON ving.\p"
	.string "Kom ons eens opzoeken in\n"
	.string "VERDANTURF.\l"
	.string "WALLY zou dat vast leuk vinden.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Biep!\p"
	.string "WALLY: Oh, hallo, {PLAYER}!\p"
	.string "Ik wilde je even vertellen dat\n"
	.string "mijn oom een POKéNAV voor me kocht!\p"
	.string "Nu kan ik je altijd bellen,\n"
	.string "{PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY staat nu\n"
	.string "in de POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe…\n"
	.string "Ik heb dat gevecht gezien!\p"
	.string "Jij bent bevriend met die jongen\n"
	.string "WALLY, toch?\p"
	.string "Maar je hield je niet in en je\n"
	.string "versloeg hem echt goed.\p"
	.string "Ja! Zo hoort een echt\n"
	.string "POKéMON-gevecht te zijn!\p"
	.string "Ik vind zulke TRAINERS geweldig!\p"
	.string "… … … … … …\n"
	.string "Ik ga je aanmoedigen!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "Jij zit vol energie, zie ik!\l"
	.string "Dat is goed, wahahahaha!\p"
	.string "Prima! Ik heb besloten!\n"
	.string "{PLAYER}{KUN}, wil je me helpen?\p"
	.string "MAUVILLE CITY heeft een deel onder\n"
	.string "de grond. Dat heet NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, wil jij daarheen gaan en\n"
	.string "de GENERATOR uitzetten?\p"
	.string "De GENERATOR doet een beetje gek.\n"
	.string "Het wordt gevaarlijk.\p"
	.string "Hier, dit is de SLEUTEL voor\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Maak je geen zorgen.\n"
	.string "Dit is makkelijk voor jou.\p"
	.string "De ingang van NEW MAUVILLE is vlakbij.\n"
	.string "Je kunt erheen SURFEN vanaf ROUTE 110.\p"
	.string "Zo, dat is geregeld. Ik vertrouw op je!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Ik wist het, {PLAYER}{KUN}! Ik wist dat\n"
	.string "jij de goede keus was!\p"
	.string "Als bedankje krijg je een TM met\n"
	.string "DONDERFLITS!\p"
	.string "Hier, je hebt het verdiend!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Ik vind het geweldig als de jeugd\n"
	.string "zelf de leiding neemt!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Weet je, POKéMON-gevechten en zo\n"
	.string "zijn best stoer…\p"
	.string "Maar als je POKéMON gewond raakt,\n"
	.string "moet je goed voor hem zorgen.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "De wegen van deze stad gaan naar\n"
	.string "het noorden, zuiden, oosten en westen.\p"
	.string "Daarom komen hier allerlei\n"
	.string "mensen langs.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Ben je al bij RYDEL'S CYCLES\n"
	.string "geweest?\p"
	.string "RYDEL, de eigenaar, is een heel\n"
	.string "aardige en gulle man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Ook als je op een FIETS zit,\n"
	.string "kunnen wilde POKéMON je aanvallen.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "“De vrolijke, stralende stad!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEIDER: WATTSON\l"
	.string "“De man die vrolijk vonkt!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Rij over grind en voel het in\n"
	.string "je hart!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "“De speelplek voor iedereen!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hoi, kijk jij wel eens TV?\p"
	.string "Er zijn veel leuke nieuwe\n"
	.string "programma's bijgekomen.\p"
	.string "TV is zo leuk. Ik zag mijn vrienden\n"
	.string "opeens op TV!\p"
	.string "En soms zetten ze je op TV\n"
	.string "zonder dat je het weet.\p"
	.string "Ik wil ook wel eens op TV komen.\p"
	.string "Daarom moet je TV kijken\n"
	.string "wanneer je maar kunt.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hoi, kijk je wel eens TV?$"
