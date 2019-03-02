BattleFrontier_BattleFactoryBattleRoom_MapScripts:: @ 825ADAB
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_MapScript1_25ADBB
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_MapScript2_25AE00
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_MapScript2_25AE31
	.byte 0

BattleFrontier_BattleFactoryBattleRoom_MapScript1_25ADBB: @ 825ADBB
	setvar VAR_0x8004, 5
	special CallFrontierUtilFunc
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE25
	compare VAR_RESULT, FEMALE
	call_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE2B
	setvar VAR_0x8004, 9
	special CallFrontierUtilFunc
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25ADF3
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_25ADF3:: @ 825ADF3
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_242170
	setobjectxyperm 2, 7, 9
	end

BattleFrontier_BattleFactoryBattleRoom_MapScript2_25AE00: @ 825AE00
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE0A
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE0A:: @ 825AE0A
	setvar VAR_TEMP_1, 1
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
	compare VAR_TEMP_F, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE24
	hideobjectat 2, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE24:: @ 825AE24
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE25:: @ 825AE25
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE2B:: @ 825AE2B
	setvar VAR_OBJ_GFX_ID_F, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleFactoryBattleRoom_MapScript2_25AE31: @ 825AE31
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE67
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE3B:: @ 825AE3B
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B1E2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, BattleFrontier_BattleFactoryBattleRoom_Movement_25B18B
	applymovement 8, BattleFrontier_BattleFactoryBattleRoom_Movement_25B17B
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_25B17B
	waitmovement 0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_25B1B4
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25AEA7
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE67:: @ 825AE67
	compare VAR_TEMP_F, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25AE3B
	applymovement 8, BattleFrontier_BattleFactoryBattleRoom_Movement_25B17B
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_25B17B
	waitmovement 0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_25B1B4
	setvar VAR_0x8004, 11
	special CallBattleFactoryFunction
	removeobject 2
	setobjectxyperm 2, 7, 1
	addobject 2
	applymovement 2, BattleFrontier_BattleFactoryBattleRoom_Movement_25B184
	waitmovement 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AEA7:: @ 825AEA7
	compare VAR_TEMP_F, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF9C
	setvar VAR_0x8004, 5
	special CallBattlePalaceFunction
	lockall
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF0F

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AEF8:: @ 825AEF8
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25AEF8:: @ 825AEF8
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25B190
@ 	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25B190

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF0F:: @ 825AF0F
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 3
	special CallBattleFactoryFunction
	compare VAR_RESULT, 9999
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF3E
	addvar VAR_RESULT, 1
	setorcopyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special CallBattleFactoryFunction

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF3E:: @ 825AF3E
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_241EBA

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF43:: @ 825AF43
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	switch VAR_RESULT
	case 7, BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF85
	setvar VAR_0x8006, 1
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 255, 8, 8
	waitstate

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF85:: @ 825AF85
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25B190

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF9C:: @ 825AF9C
	switch VAR_TEMP_F
	case 2, BattleFrontier_BattleFactoryBattleRoom_EventScript_25B051
	case 3, BattleFrontier_BattleFactoryBattleRoom_EventScript_25AFEF
	case 4, BattleFrontier_BattleFactoryBattleRoom_EventScript_25B07E
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25AFEF
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B1FB, MSGBOX_DEFAULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_25AFEF:: @ 825AFEF
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B3F1, MSGBOX_DEFAULT
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_25B0E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25B00C
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25AEF8

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B00C:: @ 825B00C
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25B105
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B42D, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleFactoryBattleRoom_Movement_25B182
	waitmovement 0
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleFactoryBattleRoom_Text_25B460
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B498, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25B105

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B051:: @ 825B051
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleFactoryBattleRoom_EventScript_25B07E
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B517, MSGBOX_DEFAULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B07E:: @ 825B07E
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B5CF, MSGBOX_DEFAULT
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_25B0E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25B09B
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25AEF8

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B09B:: @ 825B09B
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25B105
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B5E7, MSGBOX_DEFAULT
	waitmessage
	applymovement 8, BattleFrontier_BattleFactoryBattleRoom_Movement_25B182
	waitmovement 0
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleFactoryBattleRoom_Text_25B640
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_25B66D, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25B105

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B0E0:: @ 825B0E0
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B105:: @ 825B105
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 3
	special CallBattleFactoryFunction
	compare VAR_RESULT, 9999
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF3E
	addvar VAR_RESULT, 1
	setorcopyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special CallBattleFactoryFunction
	compare VAR_RESULT, 9999
	goto_if_eq BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF43
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special CallBattleFactoryFunction
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_25AF85
	end

BattleFrontier_BattleFactoryBattleRoom_Movement_25B17B: @ 825B17B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_25B182: @ 825B182
	walk_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_25B184: @ 825B184
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_25B18B: @ 825B18B
	walk_up
	walk_up
	walk_up
	face_left
	step_end

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B190:: @ 825B190
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25B190:: @ 825B190
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25B1AA
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 255, 4, 8
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_25B1AA:: @ 825B1AA
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 255, 14, 8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_25B1B4:: @ 825B1B4
	applymovement 1, Common_Movement_WalkInPlaceRight
	applymovement 3, Common_Movement_WalkInPlaceRight
	applymovement 4, Common_Movement_WalkInPlaceRight
	applymovement 5, Common_Movement_WalkInPlaceLeft
	applymovement 6, Common_Movement_WalkInPlaceLeft
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

BattleFrontier_BattleFactoryBattleRoom_Text_25B1E2: @ 825B1E2
	.string "Hey, hey!\n"
	.string "Get a move on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B1FB: @ 825B1FB
	.string "Hey, my name's NOLAND!\n"
	.string "I'm basically in charge of this place,\l"
	.string "which is why I'm the FACTORY HEAD!\p"
	.string "I had a look at your Battle Swap data.\p"
	.string "You seem to have the right idea,\n"
	.string "but you're still square in your head!\p"
	.string "Listen up, okay? Knowledge isn't only\n"
	.string "about reading books or doing desk work.\p"
	.string "Just doing that sort of thing…\n"
	.string "It may as well be useless!\p"
	.string "You have to experience things with\n"
	.string "your heart and your body, understand?\p"
	.string "I'll take you on under the same\n"
	.string "conditions as you.\p"
	.string "I'll be using rental POKéMON, too!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B3F1: @ 825B3F1
	.string "Shake out every last bit of your\n"
	.string "knowledge and bring it on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B42D: @ 825B42D
	.string "NOLAND: Smart going!\n"
	.string "Let's see your FRONTIER PASS.$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B460: @ 825B460
	.string "The Knowledge Symbol was embossed\n"
	.string "on the FRONTIER PASS!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B498: @ 825B498
	.string "Heh…\n"
	.string "You're a pretty bright spark…\p"
	.string "Next time, I'll come after you hard.\n"
	.string "No holds barred, understand?\p"
	.string "You keep up your studies!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B517: @ 825B517
	.string "NOLAND: Hey, hey! How's it going?\n"
	.string "You keeping up with your studies?\p"
	.string "…Oh?\p"
	.string "You've taken on a harder look than\n"
	.string "the last time I saw you.\p"
	.string "Now, this should be fun!\n"
	.string "I'm getting excited, hey!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B5CF: @ 825B5CF
	.string "All right!\n"
	.string "Bring it on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B5E7: @ 825B5E7
	.string "NOLAND: What the…\n"
	.string "You're getting out of my league!\p"
	.string "Sheesh!\n"
	.string "Let's see that FRONTIER PASS!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B640: @ 825B640
	.string "The Knowledge Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleFactoryBattleRoom_Text_25B66D: @ 825B66D
	.string "Pfft, man!\p"
	.string "That's absolutely the last time\n"
	.string "I lose to you!\p"
	.string "We have to do this again, hey?$"

