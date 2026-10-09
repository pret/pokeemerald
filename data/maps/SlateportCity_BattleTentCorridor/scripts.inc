SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Wil je een lekker tipje voor\n"
	.string "WEDSTRIJDEN?\p"
	.string "Gebruik je een bepaalde aanval na\n"
	.string "een andere aanval, dan krijg je\l"
	.string "soms extra aandacht.\p"
	.string "Als je weet wat je doet, scoor\n"
	.string "je hoog met je optreden.\p"
	.string "Natuurlijk kunnen tegenstanders\n"
	.string "je POKéMON proberen te storen.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mijn papa is WEDSTRIJD-JURY.\p"
	.string "Ik weet niet wat ik later moet\n"
	.string "worden: JURY of GYMLEIDER?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hé man, ik ben, zeg maar, super\n"
	.string "chagrijnig, weet je. Ik wilde\l"
	.string "gewoon weten waarom mijn POKéMON\l"
	.string "nooit won, weet je, hé?\p"
	.string "Dus ik gaf de JURY mijn mening,\n"
	.string "weet je, die is gratis.\p"
	.string "En hij wilde me niet horen, hé!\n"
	.string "Dus, zeg maar, echt balen, man!\p"
	.string "Hé, jij! Houd je mond, weet je?\n"
	.string "Pak dit maar, weet je!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Dat is, zeg maar, TM41, weet je?\n"
	.string "Hé, het is PESTEN, hoor je me?\p"
	.string "Het laat de ander dezelfde\n"
	.string "aanval niet twee keer na elkaar\l"
	.string "gebruiken, snap je?\p"
	.string "Hé, luister, ik ben jou niet\n"
	.string "aan het pesten, hoor!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC: Oh jee!\n"
	.string "Wat een prachtige POKéMON!\p"
	.string "Kom maar naar voren en doe mee\n"
	.string "aan onze mooie WEDSTRIJDEN!\p"
	.string "Je doet het goed! Dat weet ik zeker!\n"
	.string "Mijn ogen bedriegen me nooit!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JURY: Nou, hallo!\n"
	.string "Ik zie dat je een TRAINER bent!\p"
	.string "Dan moet je een POKéMON WEDSTRIJD\n"
	.string "niet missen!\p"
	.string "Haal een WEDSTRIJDPAS in VERDANTURF\n"
	.string "CITY en doe altijd mee!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "Het is tijd voor het optreden!\n"
	.string "Met wat begin ik?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Ze letten niet veel op het\n"
	.string "optreden van mijn POKéMON…\p"
	.string "Pff, die JURY snapt er niets van.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, hoi! Jij bent vast een echte fan,\n"
	.string "zo dicht bij de actie.\p"
	.string "Ik beloon je met een wijs advies.\p"
	.string "Als een aanval heel goed valt,\n"
	.string "wordt het publiek enthousiast.\p"
	.string "De POKéMON die dan optreedt als\n"
	.string "iedereen enthousiast is…\p"
	.string "Nou, dan gebeurt er vast\n"
	.string "iets goeds!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Ik kan dit niet! Ik ben banger\n"
	.string "dan mijn POKéMON.\p"
	.string "Ik tril en mijn hart bonst!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Een gevecht en een WEDSTRIJD zijn\n"
	.string "niet hetzelfde, maar wel gelijk.\p"
	.string "Je moet hard werken en geloven\n"
	.string "in de POKéMON die je hebt getraind.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Die POKéMON ziet er in topvorm uit,\n"
	.string "hè?\p"
	.string "Een POKéMON die het goed doet in\n"
	.string "de tweede ronde lijkt meer ontspannen\l"
	.string "bij het optreden.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Kijk nou toch eens naar dat zielige\n"
	.string "geval?\p"
	.string "Heh, mijn POKéMON is veel beter\n"
	.string "dan die hele groep!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Krijg je geen zin om mee te\n"
	.string "bewegen met POKéMON als ze een\l"
	.string "energiek optreden doen?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "POKéMON WEDSTRIJDEN\n"
	.string "HYPER NIVEAU PODIUM!$"

