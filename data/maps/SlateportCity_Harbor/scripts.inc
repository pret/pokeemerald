SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applywaitmovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applywaitmovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applywaitmovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applywaitmovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applywaitmovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applywaitmovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applywaitmovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Pardon?\n"
	.string "Zoek je een boot?\p"
	.string "Sorry, de veerboot vaart\n"
	.string "op dit moment niet…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Hallo, kom je voor de veerboot?\n"
	.string "Mag ik je KAARTJE zien?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} heeft geen KAARTJE…\p"
	.string "Het spijt me heel erg.\p"
	.string "Je hebt een KAARTJE nodig om\n"
	.string "op de veerboot te stappen.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} laat het KAARTJE zien.\p"
	.string "Prima! Meer heb je niet nodig!\p"
	.string "En waar wil je naartoe?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Vaar een andere keer met ons mee!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "Dus naar LILYCOVE CITY!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "Dus naar de BATTLE FRONTIER!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Stap maar in de veerboot en wacht\n"
	.string "tot hij vertrekt.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Waar wil je dan naartoe?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Een reis naar de bodem van de zee…\n"
	.string "Hoe zou dat zijn?\p"
	.string "Ik wil ooit ook zo diep\n"
	.string "onder water gaan.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Om veilig te varen, moeten we\n"
	.string "alles over het weer weten!\p"
	.string "Over het weer gesproken: ik hoorde\n"
	.string "iets van iemand van het\l"
	.string "WEATHER INSTITUTE.\p"
	.string "Hij zei dat er overal raar weer\n"
	.string "is gezien!\p"
	.string "Ga eens naar het WEATHER INSTITUTE\n"
	.string "en vraag het na!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Ik wilde met CAPT. STERN mee om\n"
	.string "de zeebodem te onderzoeken.\p"
	.string "Maar de duikboot is te klein\n"
	.string "voor mij.\p"
	.string "Als ik me erin perste, was er\n"
	.string "geen plek meer voor de KAPITEIN…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "CAPT. STERN: Die boeven…\p"
	.string "Dat zijn dezelfde die in het MUSEUM\n"
	.string "het DEVONPAKKET wilden stelen.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ARCHIE: Oh?\n"
	.string "Jij weer…\p"
	.string "Je bent ons tot hier gevolgd.\n"
	.string "Dat moet ik je nageven.\p"
	.string "Maar nu…\n"
	.string "Niemand kan ons stoppen! Niemand!\p"
	.string "Of volg je ons terug naar onze\n"
	.string "SCHUILPLAATS in LILYCOVE CITY?\p"
	.string "Fwahahahaha…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "CAPT. STERN: Waarom…\p"
	.string "Waarom steelt TEAM AQUA mijn\n"
	.string "SUBMARINE EXPLORER 1?\p"
	.string "Ze zijn toch niet uit op de slapende\n"
	.string "POKéMON op de bodem van de zee…\p"
	.string "Maar ook als ik ze achterna ga,\n"
	.string "maak ik geen kans tegen ze…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "CAPT. STERN: O, {PLAYER}{KUN}…\p"
	.string "Dus… TEAM AQUA was al weg voor\n"
	.string "jij ze kon stoppen…\p"
	.string "Nee, geef jezelf niet de schuld.\n"
	.string "Het is niet jouw fout.\p"
	.string "Een duikboot pakken…\n"
	.string "Dat kan bijna niemand.\p"
	.string "Je hebt een POKéMON nodig\n"
	.string "die DUIKEN kent…\p"
	.string "Misschien als je naar\n"
	.string "MOSSDEEP CITY gaat…\p"
	.string "Daar wonen veel duikers.\n"
	.string "Misschien leert iemand het je…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "CAPT. STERN: Een duikboot pakken…\n"
	.string "Dat kan echt niet.\p"
	.string "Je hebt een POKéMON nodig\n"
	.string "die DUIKEN kent…\p"
	.string "Misschien als je naar\n"
	.string "MOSSDEEP CITY gaat…\p"
	.string "Daar wonen veel duikers.\n"
	.string "Misschien leert iemand het je…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "CAPT. STERN: O ja.\n"
	.string "MR. BRINEY kwam naar onze SCHEEPSWERF.\p"
	.string "De veerboot is nu bijna\n"
	.string "klaar!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
	.string "De veerboot S.S. TIDAL is\n"
	.string "eindelijk klaar!\p"
	.string "Dat was nooit gelukt zonder\n"
	.string "je vriend MR. BRINEY.\p"
	.string "Maak er maar een kort tochtje mee!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "CAPT. STERN: Oh?\n"
	.string "{PLAYER}{KUN}, wat heb jij daar…\p"
	.string "Dat is een SCANNER! Die zou ons\n"
	.string "flink helpen bij ons onderzoek.\p"
	.string "{PLAYER}{KUN}, wil je je SCANNER\n"
	.string "ruilen voor iets?\p"
	.string "Bijvoorbeeld voor mijn DIEPZEETAND\n"
	.string "of mijn DIEPZEESCHUB?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "CAPT. STERN: Weet je het zeker?\n"
	.string "Jij hebt er niks aan, {PLAYER}{KUN}…\p"
	.string "Nou, goed dan. Wil je je SCANNER\n"
	.string "toch ruilen, zeg het maar.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "CAPT. STERN: Dus je ruilt hem voor\n"
	.string "mijn DIEPZEETAND?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "CAPT. STERN: Dus je ruilt hem voor\n"
	.string "mijn DIEPZEESCHUB?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "CAPT. STERN: Welke wil je?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} geeft de SCANNER aan\n"
	.string "CAPT. STERN.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "CAPT. STERN: Bedankt, {PLAYER}{KUN}!\n"
	.string "Dit helpt ons onderzoek enorm!$"
