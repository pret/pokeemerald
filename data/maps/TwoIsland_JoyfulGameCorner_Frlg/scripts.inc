TwoIsland_JoyfulGameCorner_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad_Frlg
	.byte 0

TwoIsland_JoyfulGameCorner_OnTransition::
	call_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos::
	setobjectxyperm LOCALID_JOYFUL_GAME_CORNER_DADDY, 6, 2
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	return

TwoIsland_JoyfulGameCorner_OnWarp::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

TwoIsland_JoyfulGameCorner_OnFrame::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 0, TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle
	textcolor NPC_TEXT_COLOR_FEMALE
	special GetPlayerBigGuyGirlString
	msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyPacing
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement LOCALID_PLAYER, TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	addobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, TwoIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt
	msgbox TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	fadedefaultbgm
	delay 60
	msgbox TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_THREE_ISLAND, 2
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

TwoIsland_JoyfulGameCorner_Movement_DaddyPacing::
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_faster_up
	delay_16
	step_end

TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy::
	walk_left
	walk_in_place_faster_right
	step_end

TwoIsland_JoyfulGameCorner_Movement_BikerLookAround::
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

TwoIsland_JoyfulGameCorner_EventScript_InfoMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_InfoMan2_Frlg
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon::
	msgbox TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
TwoIsland_JoyfulGameCorner_EventScript_LostellesDaddy::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_MinigameAttendant_Frlg
	goto_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3, TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite::
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_METEORITE
	msgbox TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone::
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	additem ITEM_MOON_STONE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	msgreceiveditem TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning::
	msgbox TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone::
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_Lostelle::
	lock
	faceplayer
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end

TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo::
	.string "Now, where's LOSTELLE gotten to\n"
	.string "today?\p"
	.string "She always brings me lunch every\n"
	.string "day right about now…$"

TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle::
	.string "Hm? You, there!\n"
	.string "Are you a friend of LOSTELLE's?\p"
	.string "Have you seen LOSTELLE around?\n"
	.string "I don't know where she might be.\l"
	.string "She should've been here long ago.\p"
	.string "LOSTELLE's a cutie - she got my\n"
	.string "looks - so what if someone…\p"
	.string "What if something's happened to\n"
	.string "my LOSTELLE?!\p"
	.string "Please, help me find her!\n"
	.string "Please go search THREE ISLAND!$"

TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland::
	.string "Hah? What is this GAME CORNER?\n"
	.string "How much sadder can this get?\p"
	.string "Those clowns…\p"
	.string "They said they'd be waiting on the\n"
	.string "island, so where are they?\p"
	.string "Hey, you! Is this the only THREE\n"
	.string "ISLAND around here?$"

TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt::
	.string "Try waking up before you crawl out\n"
	.string "of bed, you punk.\p"
	.string "This is TWO ISLAND!\p"
	.string "Move it! Get your filthy motorbike\n"
	.string "out of my place!$"

TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing::
	.string "Huh…\n"
	.string "Oh, oh, gotcha.\p"
	.string "Tch…\n"
	.string "These islands are confusing…$"

TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor::
	.string "Would you look at that?\n"
	.string "That punk scuffed up my floor.$"

TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland::
	.string "Hey, but listen! I'm begging you,\n"
	.string "you have to go to THREE ISLAND.\p"
	.string "If anything were to happen to my\n"
	.string "LOSTELLE…\p"
	.string "My place is the house with the red\n"
	.string "roof on THREE ISLAND.\p"
	.string "She may just show up late here,\n"
	.string "so I can't run off anywhere.\p"
	.string "That's why I have to get you to do\n"
	.string "me this big favor.$"

TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday::
	.string "I'm sorry.\n"
	.string "We're not running any games today.$"

TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon::
	.string "We'll get the games going soon\n"
	.string "for you!$"

TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle::
	.string "So you rescued LOSTELLE?\n"
	.string "How can I thank you?\p"
	.string "LOSTELLE, darling, forgive me!\p"
	.string "Daddy didn't know you were scared\n"
	.string "and in trouble!$"

TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy::
	.string "LOSTELLE: It's okay, Daddy.\n"
	.string "I got to be friends with {PLAYER}!$"

TwoIsland_JoyfulGameCorner_Text_ThisIsForMe::
	.string "Oh, what's that?\n"
	.string "You're saying that this is for me?\p"
	.string "How did you know that I love rare\n"
	.string "rocks and gems?\p"
	.string "You sure know how to make a guy\n"
	.string "happy.$"

TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy::
	.string "{PLAYER} handed the METEORITE\n"
	.string "to LOSTELLE's daddy.$"

TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill::
	.string "Oh, I see, this is from BILL!\n"
	.string "You have to thank him for me!\p"
	.string "You know, you've been fantastic.\n"
	.string "I want you to have this.$"

TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
	.string "{PLAYER} received a MOON STONE\n"
	.string "from LOSTELLE's daddy.$"

TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag::
	.string "Your BAG's not going to fit another\n"
	.string "thing…$"

TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning::
	.string "All right, I'll get the GAME CORNER\n"
	.string "running right away.\p"
	.string "You have to come visit with a\n"
	.string "friend.$"

TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool::
	.string "Listen, listen!\p"
	.string "Please show me you being cool\n"
	.string "again!$"

