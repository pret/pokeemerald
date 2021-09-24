.set LOCALID_ATTENDANT, 1

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
	compare VAR_0x8006, 1
	goto_if_ne SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	compare VAR_0x8006, 1
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	compare VAR_0x8006, 2
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 255, 4, 4
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
	compare VAR_RESULT, 1
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	compare VAR_RESULT, 2
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
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
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
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
	walk_in_place_fastest_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Want a tasty little bit of advice\n"
	.string "for Contests?\p"
	.string "Using a certain move after another\n"
	.string "certain kind of move sometimes gets\l"
	.string "you extra attention.\p"
	.string "If you know what you're doing,\n"
	.string "you can score big in appeal.\p"
	.string "Of course, your opponents might try\n"
	.string "disrupting your Pokémon's showing.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "My papa, he's a Contest Judge.\p"
	.string "I wonder what I should be when I\n"
	.string "grow up, a Judge or a Gym Leader?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hey, man, I'm like majorly cheesed,\n"
	.string "you know. Like, you know, I just\l"
	.string "wanted to know why my Pokémon\l"
	.string "never won, you know, like, hey?\p"
	.string "So, like, I gave the Judge my two\n"
	.string "cents, you know, they're free.\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's Torment, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC: Oh, my, my!\n"
	.string "Now isn't that a dandy of a Pokémon?\p"
	.string "Please! Do step right up and take\n"
	.string "part in our splendid Contests!\p"
	.string "You'll do well! I'm sure of it!\n"
	.string "My eyes have never failed me!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "Judge: Well, hello there!\n"
	.string "I see that you're a Trainer!\p"
	.string "Then, it just wouldn't do for you\n"
	.string "to miss a Pokémon Contest!\p"
	.string "Get a Contest Pass in Verdanturf\n"
	.string "City and enter anytime!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "It's appeal time!\n"
	.string "What should I lead with?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "They didn't pay much attention to\n"
	.string "my Pokémon's appeal…\p"
	.string "Humph, that Judge, he doesn't know\n"
	.string "a good thing when he sees it.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, hi! You must be a serious fan to get\n"
	.string "this close to the action.\p"
	.string "I'll reward your enthusiasm with\n"
	.string "this sage advice.\p"
	.string "If a move goes over really well,\n"
	.string "the audience will get excited.\p"
	.string "The Pokémon that makes its appeal\n"
	.string "right when everyone's excited…\p"
	.string "Well, you'd think something good has\n"
	.string "to happen!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "I can't do this! I'm more freaked out\n"
	.string "than my Pokémon.\p"
	.string "I'm shivering and my heart is racing!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "A battle and a Contest aren't the\n"
	.string "same, but they are alike, too.\p"
	.string "You need to work hard and believe\n"
	.string "in the Pokémon you've raised.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "That Pokémon looks like it's on top\n"
	.string "of its game, huh?\p"
	.string "A Pokémon that does good in the\n"
	.string "secondary judging seems to be more\l"
	.string "relaxed when it's doing appeals.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Will you look at that sorry sight?\p"
	.string "Heh, my Pokémon's absolutely better\n"
	.string "than that lot!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Don't you get the urge to move with\n"
	.string "Pokémon if they're putting on an\l"
	.string "energetic appeal?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "Pokémon Contests\n"
	.string "Hyper Rank Stage!$"

