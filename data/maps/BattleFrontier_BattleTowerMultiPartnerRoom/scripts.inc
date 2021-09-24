.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_ne BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Please find a partner from out of\n"
	.string "the Trainers gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, you have not found a partner\n"
	.string "for your tag team.\p"
	.string "Would you like to quit looking and\n"
	.string "return to the reception counter?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Then, please find a partner from\n"
	.string "the Trainers gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "Multi Battle Room.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "On {STR_VAR_1}'s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Thank you!\n"
	.string "I'll go register right now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Thank you very much!\n"
	.string "I'll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
	.string "Snivel…\p"
	.string "I'm sorry!\n"
	.string "This tension is making me cry…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} advised me, so I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Snivel…\n"
	.string "Please, please team up with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "I'll go register right away.\n"
	.string "Please don't go away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, b-but…\n"
	.string "Sob… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hi, there! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} recommended my crew.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what I have! Cool, huh?\p"
	.string "So come on!\n"
	.string "Let's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay! Great!\n"
	.string "Okay, I'll go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, why?\n"
	.string "I wanted to team up, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the famous {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "I looked to {STR_VAR_3} for advice.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's my pair.\p"
	.string "Please, will you join me in\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Thank you!\n"
	.string "I'll register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, I had been hoping to join\n"
	.string "you in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um… I'm sincerely happy that you\n"
	.string "would take the time to talk to me.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gave me advice.\n"
	.string "I'm very grateful for it.\p"
	.string "I have a team of one {STR_VAR_2}\n"
	.string "with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I'm asking a lot…\p"
	.string "I don't think you'll be willing to,\n"
	.string "but may I join you as a partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Really? I can't believe it!\n"
	.string "I can't believe you'll let me join you!\l"
	.string "I… I won't let you down!\p"
	.string "Um… If it's really okay, I'll go register\n"
	.string "right this instant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "I didn't think I was good enough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hi, I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} told me that it would be\n"
	.string "good to make this team:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "and one {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}.\p"
	.string "Not bad, huh?\n"
	.string "Want me to team up with you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Okay, glad to join you!\n"
	.string "I hope you won't mess things up for me!\l"
	.string "I'll do my registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Huh? Why did you turn me down?\n"
	.string "You're no judge of character!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "I'm {STR_VAR_3} and I'm a Triathlete.\n"
	.string "I'm busy every day what with jogging,\l"
	.string "training, and rapping.\p"
	.string "I also happen to be {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "This is what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of effort into raising\n"
	.string "them, even though I'm busy.\p"
	.string "Let's form a tag team\n"
	.string "and give it a go!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Thanks, that's the spirit!\n"
	.string "Hang tight while I go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "I took time from my busy schedule\n"
	.string "to be here! Give me a break!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hi!\n"
	.string "How's it going?\p"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Listen, listen! You have to hear about\n"
	.string "the Pokémon {STR_VAR_3} recommended.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Of course I raised them superbly!\p"
	.string "So, want to team up?\n"
	.string "I'm sure it'll be a great combo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, I think this will be fun!\n"
	.string "I'll go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, you're mean!\n"
	.string "I come recommended, you know.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Please let me introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I serve as {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "I sought the sage advice of\n"
	.string "{STR_VAR_3} and raised my team\l"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please agree to a tag team with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… I'm delighted!\n"
	.string "I promise to give you my best!\p"
	.string "Of course I will register us!\n"
	.string "Please wait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "I had been hoping to join you,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! You spoke to me!\n"
	.string "I… I'm overjoyed!\p"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "On {STR_VAR_3}'s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can you grant me my wish?\n"
	.string "I want to be your tag-team partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! I… I feel giddy!\n"
	.string "Thank you so much!\l"
	.string "I'll go register us right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Don't you feel any pity?\n"
	.string "But that makes you cooler…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3}'s my name, hello, hello!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Good stuff, huh?\n"
	.string "You'll partner with me, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Okay, excellent!\n"
	.string "I'll get the registration done quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "You're a calculating one, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hey! There's big trouble! This is\n"
	.string "the Battle Tower's last day!\p"
	.string "… … … … … …\n"
	.string "I'm only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
	.string "Actually, I'm no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gave me some advice.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I've got ten of each kind!\l"
	.string "Actually, just one of each!\p"
	.string "How about it?\n"
	.string "Want to try tag battles with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yippee!\n"
	.string "I'll give you a Pokémon as my thanks!\p"
	.string "Just joking! But I will really go do\n"
	.string "the registration, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, that's so cold! I'll have to wreck\n"
	.string "the Battle Tower for that!\p"
	.string "Of course I won't!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
	.string "Pokémon, I be controllin'!\p"
	.string "I'm {STR_VAR_3} the rappin' Sailor.\n"
	.string "Don't be mistakin' me for no wailer!\p"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Me, you shouldn't be quick to dismiss!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, put together my team of pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our meeting we should commemorate,\n"
	.string "with a tag-team victory to celebrate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hey, hey, I like your style!\n"
	.string "Our registration, I will go file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
	.string "If I may be so bold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo!\n"
	.string "Oh, don't run! I was just having fun!\p"
	.string "Howdy! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} told me what to do.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did choose.\p"
	.string "So, what do you say?\n"
	.string "Come on, make my day!\p"
	.string "Please, I'm begging you!\n"
	.string "Let me join you, don't leave me blue!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeahah! Luck is with me!\n"
	.string "It sure makes me happy!\p"
	.string "Before we go join the fray,\n"
	.string "I'll go register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "You're turning me down?\n"
	.string "{PLAYER}, you're making me frown!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Cough!\p"
	.string "Oh, sorry, I have a cold.\n"
	.string "My Pokémon are fine, though.\p"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Cough!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "I took {STR_VAR_3}'s advice to heart\n"
	.string "and put together my team of\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I trained them every day,\n"
	.string "even in wind and rain.\p"
	.string "That's why I have this cold,\n"
	.string "I think.\p"
	.string "That's what I'm about.\n"
	.string "Want to be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Thanks, I appreciate this!\n"
	.string "Cough, cough!\l"
	.string "Hang on while I go register.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, you won't?\n"
	.string "{PLAYER}, I think we'd make a good pair.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hello!\n"
	.string "This is nerve-racking.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} said this team'll be good--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I'm feeling self-conscious about this,\n"
	.string "but will you let me join you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, gee, thank you!\n"
	.string "I feel bashful, but I'll do my best!\p"
	.string "I'll go get the registration done.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, please don't say no!\n"
	.string "I feel self-conscious enough already…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "I am {STR_VAR_3}, and that's no lie.\n"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} recommended my team.\p"
	.string "Since the advice sounded sincere,\n"
	.string "I decided to bring with me\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I would like you to accept\n"
	.string "me as your tag-team partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "You really will accept me?\n"
	.string "It would be too terrible otherwise.\p"
	.string "But since you've agreed, this is fine.\n"
	.string "I shall go register the both of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "I'm {STR_VAR_1}, and I'm a Lass!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "What I have are one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "Those are what I have with me.\p"
	.string "Will you be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Thank you!\n"
	.string "I'll go do the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "You don't want to be my partner?\n"
	.string "You'll regret it later!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hello!\p"
	.string "I'm Youngster {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Want to know what I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You'll be my tag-team partner,\n"
	.string "won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay!\n"
	.string "I'll go and register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aww! If you'd form a tag team with\n"
	.string "my Pokémon, we'd be unstoppable!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo!\n"
	.string "I'm Hiker {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Know what I have with me?\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Sounds good, eh?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo!\n"
	.string "I'll go do the registering, then.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "I would've liked to battle with you\n"
	.string "at my side.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a Beauty!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Do you know what I've been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Want to make a tag team together?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Wonderful!\n"
	.string "I'll get the registration done now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "How disappointing!\p"
	.string "We two together--we would've been\n"
	.string "the best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\p"
	.string "You know who I am?\n"
	.string "I'm {STR_VAR_1} the Fisherman!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "I've got with me a team of one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, how about it?\n"
	.string "Will you battle at my side?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Good, good!\n"
	.string "Leave it up to me!\p"
	.string "I'll go and register us now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "We matched up perfectly, too…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Glad to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a Lady.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "For I wish to have you as my partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "I'm sure that you will regret not\n"
	.string "having me as your partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "I'm Triathlete {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "What I have…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That's my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Gee, thanks!\n"
	.string "I'll go register at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "We two together, we would've been\n"
	.string "tough for certain!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya!\n"
	.string "I'm Bug Catcher {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Check out what I have!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Gotcha!\p"
	.string "I'll go do the registration stuff\n"
	.string "at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, my Pokémon are awesome.\n"
	.string "I hope you won't regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Good day!\n"
	.string "I'm School Kid {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "What I've been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don't you think?\n"
	.string "Would you care to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Thank you very much!\n"
	.string "I'll get done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "That's too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Let me tell you who I am!\n"
	.string "I'm Rich Boy {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Guess what I got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I'm willing to offer you the chance\n"
	.string "to be in a tag team with me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Smart move!\p"
	.string "I'll finish up the registration\n"
	.string "process quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "You'd turn me of all people down?\n"
	.string "You'll regret that decision for sure!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "I am Black Belt {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "I will go register forthwith!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "I see… I hope for an opportunity\n"
	.string "the next time we meet…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hi, there!\n"
	.string "I'm {STR_VAR_1}, and I'm a Tuber!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "I'll tell you what I have.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "May I please be on your tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Thank you!\n"
	.string "I'll go register us now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "If we'd become partners, we could\n"
	.string "have been so strong!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Greetings…\n"
	.string "I am Hex Maniac {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "I thank you…\n"
	.string "I shall register us…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "I so longed to join you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "How do you do? I'm {STR_VAR_1},\n"
	.string "and I'm a Pokémon Breeder!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "I'm raising a couple good ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Feel like making a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Thank you kindly!\p"
	.string "I'll go take care of the registration\n"
	.string "stuff, so you wait right here!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "I was looking forward to being\n"
	.string "your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Well, hello!\n"
	.string "I'm Triathlete {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Want to know what I run with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Want to be in a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Good going!\p"
	.string "I'll be quick and get the registration\n"
	.string "all done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "You and me, we would've been tops.\n"
	.string "It's too bad…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hey, there! My name's {STR_VAR_1}!\n"
	.string "I'm a Triathlete!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "I go on runs with my durable team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, huh?\n"
	.string "We should be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "All right!\n"
	.string "I'll go register in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "I really wanted to battle as your\n"
	.string "tag-team partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "I'm Battle Girl {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "I've been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Do you like that combo?\n"
	.string "How about you and me join up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Why, thanks!\p"
	.string "I'll get the registration done\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "With you, I thought we could form\n"
	.string "the ultimate tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "I'm Triathlete {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "I've been running with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be in a tag team.\n"
	.string "Wouldn't that be great?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Thank you!\p"
	.string "I'll go register us, and that's\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, that's too bad. We would've been\n"
	.string "the toughest tag team around!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Me?\n"
	.string "I'm Tuber {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "What do I have with me?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Hey?\n"
	.string "You'll team up with me, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Okay!\p"
	.string "I'll go register!\n"
	.string "Let's be excellent together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "My Pokémon are tough for sure…\n"
	.string "It's too bad you don't want to team up.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey!\n"
	.string "Call me Guitarist {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Check out my entourage!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yay-hey! Pretty wild, huh?\n"
	.string "We'll have to do a duet in a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hey! Right on!\n"
	.string "I'll do that registration stuff now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "My Pokémon rock hard!\n"
	.string "You'll be sorry, I tell you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Pleased to meet you.\n"
	.string "I am {STR_VAR_1}, a Gentleman.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "May I ask you to join me in a tag-team\n"
	.string "partnership arrangement?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, I thank you for your trust.\n"
	.string "I shall be done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hello, I'm {STR_VAR_1},\n"
	.string "and I'm a Pokéfan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "I have with me now one {STR_VAR_2}\n"
	.string "that knows the move {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Do you like what you see?\n"
	.string "Why don't you be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Thank you!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "My Pokémon are top grade…\n"
	.string "It's too bad you can't appreciate that.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and an Expert am I!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "The Pokémon that I've toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What say you to a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "I shall register us right away!\l"
	.string "Let us both do our best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "I will hope that your choice is\n"
	.string "indeed correct…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hello, hello.\n"
	.string "I'm {STR_VAR_1}, and I'm an Expert.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "I've raised my Pokémon thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're what I have.\p"
	.string "Wouldn't you like to team up with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Good, good.\n"
	.string "I'll see to the registration right away.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Perhaps we can form a team the next\n"
	.string "time we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "I'm Dragon Tamer {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "The team I've been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Want to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Okay, I'll give it my best!\n"
	.string "I'll go register now, all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "You're not going to find many tougher\n"
	.string "partners than me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "I'm Bird Keeper {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "What Pokémon do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Great, thanks!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "My Pokémon and I are strong.\n"
	.string "What a letdown.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "I'm Ninja Boy {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "My Pokémon team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let's be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay!\n"
	.string "Let me go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "You'll regret not having my tough\n"
	.string "Pokémon on your side!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hello!\n"
	.string "I'm Parasol Lady {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren't they nice?\n"
	.string "Care to join us in a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Thanks a bunch!\p"
	.string "I'll go register at the counter.\n"
	.string "Let's not disappoint each other!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "My Pokémon are tremendously strong.\n"
	.string "How disappointing…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hello.\n"
	.string "I'm {STR_VAR_1}, and I'm a Bug Maniac!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "I have found my Pokémon, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won't be long with the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "With the Pokémon I found, we wouldn't\n"
	.string "have lost…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoy, there!\n"
	.string "I'm Sailor {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you're not going to turn\n"
	.string "me down. We will team up, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "I didn't expect any less!\n"
	.string "I'll go register now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "We would've stormed through\n"
	.string "the opposition! Too bad!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hi, I'm {STR_VAR_1}.\n"
	.string "I'm a Collector.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, huh?\n"
	.string "We should be in a team together.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, yeah!\p"
	.string "Well, let's not waste any time.\n"
	.string "I'll go register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Well, that's upsetting.\n"
	.string "You don't appreciate my Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Howdy, I'm {STR_VAR_1}.\n"
	.string "I'm a Pokémon Ranger.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don't you think we'd make an impressive\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "That's super!\n"
	.string "I'll deal with the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Next time, choose my Pokémon,\n"
	.string "will you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "My name's {STR_VAR_1}.\n"
	.string "I'm a Pokémon Ranger!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Let me tell you about my team. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "We'll be at our best!\n"
	.string "I'll get the registration done quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "I hope you'll choose my Pokémon\n"
	.string "next time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
	.string "I consider myself an Aroma Lady.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they strike your fancy.\n"
	.string "Would you care to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "I'm honored by your acceptance.\n"
	.string "I will go register right this instant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "It would be wonderful if we could form\n"
	.string "a tag team the next time we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Want to know who I am?\n"
	.string "I'm {STR_VAR_1}, the Ruin Maniac!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "The Pokémon that I have with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh?\n"
	.string "How about you and I partner up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "That's a sound decision!\n"
	.string "I'll go do the registration paperwork.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "I think my Pokémon are tough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "I'm Cooltrainer {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "The Pokémon I have right now are one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Cool, huh?\p"
	.string "Don't you think it'd be pretty cool\n"
	.string "if we made a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool!\n"
	.string "I'll go do the registration in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "I thought that we'd make just\n"
	.string "the greatest team ever.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "I'm Cooltrainer {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "The team I've been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound okay?\n"
	.string "How about we become tag partners?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Sounds A-OK!\n"
	.string "I'd better do the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "I was thinking how we would be\n"
	.string "one tough team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo!\n"
	.string "I'm {STR_VAR_1}, the Pokémaniac!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what!\p"
	.string "Let's do it!\n"
	.string "We'll stomp around as a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Good call!\n"
	.string "I'll register the both of us!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "My Pokémon are brutal!\n"
	.string "It's not my fault if you regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo, there!\n"
	.string "I'm KIndler {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what do you say?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "All right!\n"
	.string "I'll get on with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promise you'll partner up with me\n"
	.string "the next time we run into each other.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "I'm {STR_VAR_1}, and I'm a Camper!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "I've been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it'd be fun to team up?\n"
	.string "I bet it would be!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah!\n"
	.string "Off I go to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Next time, okay?\n"
	.string "I want to be on your team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a Picnicker!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "The Pokémon I've been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Why, thank you!\n"
	.string "I will do the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "It would be nice if I could join you\n"
	.string "some other time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "I'm Psychic {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "The twosome I've been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Would you like to form a tag team\n"
	.string "with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Sure thing!\n"
	.string "I'll take care of the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "If we meet again, that's when I'd like\n"
	.string "to team up with you.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "I'm {STR_VAR_1}.\n"
	.string "I'm a Psychic.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're my disciples.\p"
	.string "Doesn't the idea of forming a tag-team\n"
	.string "partnership intrigue you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Thank you.\n"
	.string "I'll go deal with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "I hope there will be another chance\n"
	.string "to forge an alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "I'm School Kid {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my Pokémon pair.\p"
	.string "May I please be your partner on\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, thank you!\n"
	.string "I'll register at the counter right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Please?\n"
	.string "May I join you the next time?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hiya! The name's {STR_VAR_1}!\n"
	.string "I'm a Pokémon Breeder!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "The Pokémon I've raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound interesting?\n"
	.string "How about we form a tag team, then?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "All righty!\n"
	.string "You leave the registration to me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "You have to team up with me next time,\n"
	.string "all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
	.string "that I am a Pokéfan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "The darling Pokémon I've raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren't they just the cutest?\n"
	.string "We ought to make a team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Thank you, dear!\n"
	.string "I'll be on my way to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "My darling Pokémon are the best,\n"
	.string "I'll have you know. How annoying!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hi, I'm Swimmer {STR_VAR_1}.$"
	

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I've trained.\p"
	.string "You and me, let's make a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "That's cool!\n"
	.string "I'll register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "If we meet again, you owe me\n"
	.string "a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "What's happening?\n"
	.string "I'm {STR_VAR_1}, and I'm a Triathlete.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "I got a couple decent Pokémon.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It'd be neat if we made a tag team\n"
	.string "together, so how about it?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Right on!\n"
	.string "You wait while I register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "I expect you'll let me join you\n"
	.string "next time, how's that?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "I'm the Triathlete {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That's my pair.\p"
	.string "What do you think?\n"
	.string "We'd make a good team, I'd say.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "I like that answer!\n"
	.string "I'll get done with registration fast!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "You'll give me another chance to form\n"
	.string "a partnership, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hi, there! Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a Swimmer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Check out what I've been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, huh?\n"
	.string "It'd be sweet to form a team, too!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Much obliged!\n"
	.string "I'll get this registration thing done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "If we meet again, you have to team up\n"
	.string "with me. You'll do that, right?$"

