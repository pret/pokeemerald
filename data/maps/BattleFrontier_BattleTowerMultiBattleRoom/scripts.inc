BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8243D92
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7: @ 8243DA7
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_RESTORE_PARTY
	special CallBattlePyramidFunction
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0: @ 8243DB0
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_10
	special CallBattleTowerFunc
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA:: @ 8243DDA
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, EVENT_OBJ_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, EVENT_OBJ_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm 1, 10, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14: @ 8243E14
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E:: @ 8243E1E
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23: @ 8243E23
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35:: @ 8243E35
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41:: @ 8243E41
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77
	waitmovement 0
	copyobjectxytoperm 1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244056, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75: @ 8243E75
	walk_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77: @ 8243E77
	walk_left
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E7A:: @ 8243E7A
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_244094
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D:: @ 8243E9D
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5:: @ 8243EB5
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244149, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4:: @ 8243EE4
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EF6: @ 8243EF6
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F08: @ 8243F08
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A: @ 8243F1A
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E: @ 8243F1E
	walk_right
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22: @ 8243F22
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26: @ 8243F26
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F29:: @ 8243F29
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36:: @ 8243F36
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_11
	setvar VAR_0x8005, 0
	special CallBattleTowerFunc
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_11
	setvar VAR_0x8005, 1
	special CallBattleTowerFunc
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_11
	setvar VAR_0x8005, 2
	special CallBattleTowerFunc
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_11
	setvar VAR_0x8005, 3
	special CallBattleTowerFunc
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_SOUTH
	call_if_ne BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3:: @ 8243FC3
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_11
	setvar VAR_0x8005, 4
	special CallBattleTowerFunc
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4:: @ 8243FD4
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF:: @ 8243FDF
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FEA: @ 8243FEA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2: @ 8243FF2
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FFB:: @ 8243FFB
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244008:: @ 8244008
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244015:: @ 8244015
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244022:: @ 8244022
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24402F:: @ 824402F
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24403C:: @ 824403C
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244049:: @ 8244049
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_Text_244056: @ 8244056
	.string "Please find a partner from out of\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244094: @ 8244094
	.string "{PLAYER}, you have not found a partner\n"
	.string "for your tag team.\p"
	.string "Would you like to quit looking and\n"
	.string "return to the reception counter?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C: @ 824410C
	.string "Then, please find a partner from\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244149:: @ 8244149
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "MULTI BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24419A:: @ 824419A
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2441CA:: @ 82441CA
	.string "On {STR_VAR_1}'s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2441F7:: @ 82441F7
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24422E:: @ 824422E
	.string "Thank you!\n"
	.string "I'll go register right now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244255:: @ 8244255
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244286:: @ 8244286
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2442B2:: @ 82442B2
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2442E4:: @ 82442E4
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let's form a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244313:: @ 8244313
	.string "Thank you very much!\n"
	.string "I'll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244350:: @ 8244350
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244383:: @ 8244383
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
	.string "Snivel…\p"
	.string "I'm sorry!\n"
	.string "This tension is making me cry…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2443E7:: @ 82443E7
	.string "{STR_VAR_3} advised me, so I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244413:: @ 8244413
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Snivel…\n"
	.string "Please, please team up with me!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24444B:: @ 824444B
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "I'll go register right away.\n"
	.string "Please don't go away!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2444D6:: @ 82444D6
	.string "Oh, b-but…\n"
	.string "Sob… Waaaaah!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2444EF:: @ 82444EF
	.string "Hi, there! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24451E:: @ 824451E
	.string "{STR_VAR_3} recommended my crew.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244549:: @ 8244549
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what I have! Cool, huh?\p"
	.string "So come on!\n"
	.string "Let's form a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24459B:: @ 824459B
	.string "Yay! Great!\n"
	.string "Okay, I'll go register, okay?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2445C5:: @ 82445C5
	.string "Aww, why?\n"
	.string "I wanted to team up, {PLAYER}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2445E8:: @ 82445E8
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the famous {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244618:: @ 8244618
	.string "I looked to {STR_VAR_3} for advice.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244643:: @ 8244643
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's my pair.\p"
	.string "Please, will you join me in\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24468F:: @ 824468F
	.string "Thank you!\n"
	.string "I'll register right away!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2446B4:: @ 82446B4
	.string "{PLAYER}, I had been hoping to join\n"
	.string "you in a tag team…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2446E5:: @ 82446E5
	.string "Um… I'm sincerely happy that you\n"
	.string "would take the time to talk to me.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24474D:: @ 824474D
	.string "{STR_VAR_3} gave me advice.\n"
	.string "I'm very grateful for it.\p"
	.string "I have a team of one {STR_VAR_2}\n"
	.string "with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24479E:: @ 824479E
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I'm asking a lot…\p"
	.string "I don't think you'll be willing to,\n"
	.string "but may I join you as a partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24480C:: @ 824480C
	.string "Really? I can't believe it!\n"
	.string "I can't believe you'll let me join you!\l"
	.string "I… I won't let you down!\p"
	.string "Um… If it's really okay, I'll go register\n"
	.string "right this instant!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448A7:: @ 82448A7
	.string "Oh…\n"
	.string "I didn't think I was good enough…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448CD:: @ 82448CD
	.string "Hi, I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2448F5:: @ 82448F5
	.string "{STR_VAR_3} told me that it would be\n"
	.string "good to make this team:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244939:: @ 8244939
	.string "and one {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}.\p"
	.string "Not bad, huh?\n"
	.string "Want me to team up with you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244989:: @ 8244989
	.string "Okay, glad to join you!\n"
	.string "I hope you won't mess things up for me!\l"
	.string "I'll do my registration now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2449E6:: @ 82449E6
	.string "Huh? Why did you turn me down?\n"
	.string "You're no judge of character!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244A23:: @ 8244A23
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
	.string "I'm busy every day what with jogging,\l"
	.string "training, and rapping.\p"
	.string "I also happen to be {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244AA9:: @ 8244AA9
	.string "This is what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244AD6:: @ 8244AD6
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of effort into raising\n"
	.string "them, even though I'm busy.\p"
	.string "Let's form a tag team\n"
	.string "and give it a go!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244B52:: @ 8244B52
	.string "Thanks, that's the spirit!\n"
	.string "Hang tight while I go register, okay?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244B93:: @ 8244B93
	.string "I took time from my busy schedule\n"
	.string "to be here! Give me a break!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244BD2:: @ 8244BD2
	.string "Hi!\n"
	.string "How's it going?\p"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244C18:: @ 8244C18
	.string "Listen, listen! You have to hear about\n"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244C6E:: @ 8244C6E
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Of course I raised them superbly!\p"
	.string "So, want to team up?\n"
	.string "I'm sure it'll be a great combo!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244CD6:: @ 8244CD6
	.string "Yay, I think this will be fun!\n"
	.string "I'll go register!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D07:: @ 8244D07
	.string "Oh, you're mean!\n"
	.string "I come recommended, you know.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D36:: @ 8244D36
	.string "Please let me introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I serve as {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244D82:: @ 8244D82
	.string "I sought the sage advice of\n"
	.string "{STR_VAR_3} and raised my team\l"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244DC6:: @ 8244DC6
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please agree to a tag team with me!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244DFE:: @ 8244DFE
	.string "Oh… I'm delighted!\n"
	.string "I promise to give you my best!\p"
	.string "Of course I will register us!\n"
	.string "Please wait!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244E5B:: @ 8244E5B
	.string "I had been hoping to join you,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244E7E:: @ 8244E7E
	.string "Eek! You spoke to me!\n"
	.string "I… I'm overjoyed!\p"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244ECA:: @ 8244ECA
	.string "On {STR_VAR_3}'s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244EF4:: @ 8244EF4
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can you grant me my wish?\n"
	.string "I want to be your tag-team partner!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244F4F:: @ 8244F4F
	.string "Eek! I… I feel giddy!\n"
	.string "Thank you so much!\l"
	.string "I'll go register us right away!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244F98:: @ 8244F98
	.string "Waaah! Don't you feel any pity?\n"
	.string "But that makes you cooler…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_244FD3:: @ 8244FD3
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3}'s my name, hello, hello!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245013:: @ 8245013
	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24503D:: @ 824503D
	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Good stuff, huh?\n"
	.string "You'll partner with me, won't you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245087:: @ 8245087
	.string "Okay, excellent!\n"
	.string "I'll get the registration done quickly!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2450C0:: @ 82450C0
	.string "Gwaaah!\n"
	.string "You're a calculating one, {PLAYER}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2450E6:: @ 82450E6
	.string "Hey! There's big trouble! This is\n"
	.string "the BATTLE TOWER's last day!\p"
	.string "… … … … … …\n"
	.string "I'm only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
	.string "Actually, I'm no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245196:: @ 8245196
	.string "{STR_VAR_3} gave me some advice.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2451BD:: @ 82451BD
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I've got ten of each kind!\l"
	.string "Actually, just one of each!\p"
	.string "How about it?\n"
	.string "Want to try tag battles with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24522F:: @ 824522F
	.string "Yippee!\n"
	.string "I'll give you a POKéMON as my thanks!\p"
	.string "Just joking! But I will really go do\n"
	.string "the registration, okay?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24529A:: @ 824529A
	.string "Oh, that's so cold! I'll have to wreck\n"
	.string "the BATTLE TOWER for that!\p"
	.string "Of course I won't!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2452EF:: @ 82452EF
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
	.string "POKéMON, I be controllin'!\p"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
	.string "Don't be mistakin' me for no wailer!\p"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Me, you shouldn't be quick to dismiss!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2453B4:: @ 82453B4
	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, put together my team of pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245406:: @ 8245406
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our meeting we should commemorate,\n"
	.string "with a tag-team victory to celebrate!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245464:: @ 8245464
	.string "Hey, hey, I like your style!\n"
	.string "Our registration, I will go file!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2454A3:: @ 82454A3
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
	.string "If I may be so bold!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2454D6:: @ 82454D6
	.string "Yippee-yahoo!\n"
	.string "Oh, don't run! I was just having fun!\p"
	.string "Howdy! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245535:: @ 8245535
	.string "{STR_VAR_3} told me what to do.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24555F:: @ 824555F
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did choose.\p"
	.string "So, what do you say?\n"
	.string "Come on, make my day!\p"
	.string "Please, I'm begging you!\n"
	.string "Let me join you, don't leave me blue!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2455EC:: @ 82455EC
	.string "Yeahah! Luck is with me!\n"
	.string "It sure makes me happy!\p"
	.string "Before we go join the fray,\n"
	.string "I'll go register right away!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245656:: @ 8245656
	.string "You're turning me down?\n"
	.string "{PLAYER}, you're making me frown!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24568A:: @ 824568A
	.string "Cough!\p"
	.string "Oh, sorry, I have a cold.\n"
	.string "My POKéMON are fine, though.\p"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Cough!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2456F5:: @ 82456F5
	.string "I took {STR_VAR_3}'s advice to heart\n"
	.string "and put together my team of\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245740:: @ 8245740
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I trained them every day,\n"
	.string "even in wind and rain.\p"
	.string "That's why I have this cold,\n"
	.string "I think.\p"
	.string "That's what I'm about.\n"
	.string "Want to be my tag partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2457D9:: @ 82457D9
	.string "Thanks, I appreciate this!\n"
	.string "Cough, cough!\l"
	.string "Hang on while I go register.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24581F:: @ 824581F
	.string "Oh, you won't?\n"
	.string "{PLAYER}, I think we'd make a good pair.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245851:: @ 8245851
	.string "Oh, hello!\n"
	.string "This is nerve-racking.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24589C:: @ 824589C
	.string "{STR_VAR_3} said this team'll be good--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2458CE:: @ 82458CE
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I'm feeling self-conscious about this,\n"
	.string "but will you let me join you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245923:: @ 8245923
	.string "Oh, gee, thank you!\n"
	.string "I feel bashful, but I'll do my best!\p"
	.string "I'll go get the registration done.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24597F:: @ 824597F
	.string "Oh, please don't say no!\n"
	.string "I feel self-conscious enough already…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2459BE:: @ 82459BE
	.string "I am {STR_VAR_3}, and that's no lie.\n"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2459F7:: @ 82459F7
	.string "{STR_VAR_3} recommended my team.\p"
	.string "Since the advice sounded sincere,\n"
	.string "I decided to bring with me\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245A5F:: @ 8245A5F
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I would like you to accept\n"
	.string "me as your tag-team partner.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245AB4:: @ 8245AB4
	.string "You really will accept me?\n"
	.string "It would be too terrible otherwise.\p"
	.string "But since you've agreed, this is fine.\n"
	.string "I shall go register the both of us.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B3E:: @ 8245B3E
	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B79:: @ 8245B79
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245B91:: @ 8245B91
	.string "What I have are one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and one$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245BBD:: @ 8245BBD
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "Those are what I have with me.\p"
	.string "Will you be my partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C05:: @ 8245C05
	.string "Thank you!\n"
	.string "I'll go do the registration!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C2D:: @ 8245C2D
	.string "You don't want to be my partner?\n"
	.string "You'll regret it later!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C66:: @ 8245C66
	.string "Hello!\p"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245C7F:: @ 8245C7F
	.string "Want to know what I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245CAC:: @ 8245CAC
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You'll be my tag-team partner,\n"
	.string "won't you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245CE6:: @ 8245CE6
	.string "Yay!\n"
	.string "I'll go and register, okay?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D07:: @ 8245D07
	.string "Aww! If you'd form a tag team with\n"
	.string "my POKéMON, we'd be unstoppable!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D4B:: @ 8245D4B
	.string "Yahoo!\n"
	.string "I'm HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D60:: @ 8245D60
	.string "Know what I have with me?\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245D8D:: @ 8245D8D
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Sounds good, eh?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245DC7:: @ 8245DC7
	.string "Yahoo!\n"
	.string "I'll go do the registering, then.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245DF0:: @ 8245DF0
	.string "I would've liked to battle with you\n"
	.string "at my side.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E20:: @ 8245E20
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E41:: @ 8245E41
	.string "Do you know what I've been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245E78:: @ 8245E78
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Want to make a tag team together?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245EBD:: @ 8245EBD
	.string "Wonderful!\n"
	.string "I'll get the registration done now!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245EEC:: @ 8245EEC
	.string "How disappointing!\p"
	.string "We two together--we would've been\n"
	.string "the best!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F2B:: @ 8245F2B
	.string "Yo!\p"
	.string "You know who I am?\n"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F58:: @ 8245F58
	.string "I've got with me a team of one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245F87:: @ 8245F87
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, how about it?\n"
	.string "Will you battle at my side?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_245FC6:: @ 8245FC6
	.string "Good, good!\n"
	.string "Leave it up to me!\p"
	.string "I'll go and register us now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246002:: @ 8246002
	.string "We matched up perfectly, too…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246020:: @ 8246020
	.string "Glad to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a LADY.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246051:: @ 8246051
	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246082:: @ 8246082
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "For I wish to have you as my partner.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2460D5:: @ 82460D5
	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24610D:: @ 824610D
	.string "I'm sure that you will regret not\n"
	.string "having me as your partner.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24614A:: @ 824614A
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24615D:: @ 824615D
	.string "What I have…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24617D:: @ 824617D
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That's my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2461C7:: @ 82461C7
	.string "Gee, thanks!\n"
	.string "I'll go register at the counter.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2461F5:: @ 82461F5
	.string "We two together, we would've been\n"
	.string "tough for certain!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24622A:: @ 824622A
	.string "Hiya!\n"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246244:: @ 8246244
	.string "Check out what I have!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24626E:: @ 824626E
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you want to form a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2462AA:: @ 82462AA
	.string "Gotcha!\p"
	.string "I'll go do the registration stuff\n"
	.string "at the counter.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2462E4:: @ 82462E4
	.string "Aww, my POKéMON are awesome.\n"
	.string "I hope you won't regret this!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24631F:: @ 824631F
	.string "Good day!\n"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24633C:: @ 824633C
	.string "What I've been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24636B:: @ 824636B
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don't you think?\n"
	.string "Would you care to form a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2463C5:: @ 82463C5
	.string "Thank you very much!\n"
	.string "I'll get done with the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2463FF:: @ 82463FF
	.string "That's too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246449:: @ 8246449
	.string "Yo! Let me tell you who I am!\n"
	.string "I'm RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246478:: @ 8246478
	.string "Guess what I got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24649D:: @ 824649D
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I'm willing to offer you the chance\n"
	.string "to be in a tag team with me.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2464EE:: @ 82464EE
	.string "Smart move!\p"
	.string "I'll finish up the registration\n"
	.string "process quick!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246529:: @ 8246529
	.string "You'd turn me of all people down?\n"
	.string "You'll regret that decision for sure!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246571:: @ 8246571
	.string "Hiyah!\n"
	.string "I am BLACK BELT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24658C:: @ 824658C
	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2465B5:: @ 82465B5
	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246605:: @ 8246605
	.string "Hiyah!\n"
	.string "I will go register forthwith!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24662A:: @ 824662A
	.string "I see… I hope for an opportunity\n"
	.string "the next time we meet…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246662:: @ 8246662
	.string "Hi, there!\n"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246686:: @ 8246686
	.string "I'll tell you what I have.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2466B4:: @ 82466B4
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "May I please be on your tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2466E6:: @ 82466E6
	.string "Thank you!\n"
	.string "I'll go register us now!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24670A:: @ 824670A
	.string "If we'd become partners, we could\n"
	.string "have been so strong!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246741:: @ 8246741
	.string "Greetings…\n"
	.string "I am HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246760:: @ 8246760
	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246791:: @ 8246791
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467C4:: @ 82467C4
	.string "I thank you…\n"
	.string "I shall register us…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467E6:: @ 82467E6
	.string "I so longed to join you…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2467FF:: @ 82467FF
	.string "How do you do? I'm {STR_VAR_1},\n"
	.string "and I'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246831:: @ 8246831
	.string "I'm raising a couple good ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246864:: @ 8246864
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Feel like making a tag team with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2468A7:: @ 82468A7
	.string "Thank you kindly!\p"
	.string "I'll go take care of the registration\n"
	.string "stuff, so you wait right here!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2468FE:: @ 82468FE
	.string "I was looking forward to being\n"
	.string "your partner…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24692B:: @ 824692B
	.string "Well, hello!\n"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24694B:: @ 824694B
	.string "Want to know what I run with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24697C:: @ 824697C
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Want to be in a tag team with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2469B4:: @ 82469B4
	.string "Good going!\p"
	.string "I'll be quick and get the registration\n"
	.string "all done!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2469F1:: @ 82469F1
	.string "You and me, we would've been tops.\n"
	.string "It's too bad…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A22:: @ 8246A22
	.string "Hey, there! My name's {STR_VAR_1}!\n"
	.string "I'm a TRIATHLETE!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A4E:: @ 8246A4E
	.string "I go on runs with my durable team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246A85:: @ 8246A85
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, huh?\n"
	.string "We should be in a tag team together!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246ACF:: @ 8246ACF
	.string "All right!\n"
	.string "I'll go register in a flash!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246AF7:: @ 8246AF7
	.string "I really wanted to battle as your\n"
	.string "tag-team partner…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B2B:: @ 8246B2B
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B3F:: @ 8246B3F
	.string "I've been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246B6B:: @ 8246B6B
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Do you like that combo?\n"
	.string "How about you and me join up?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246BB2:: @ 8246BB2
	.string "Why, thanks!\p"
	.string "I'll get the registration done\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246BE9:: @ 8246BE9
	.string "With you, I thought we could form\n"
	.string "the ultimate tag team…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C22:: @ 8246C22
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C35:: @ 8246C35
	.string "I've been running with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246C6C:: @ 8246C6C
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be in a tag team.\n"
	.string "Wouldn't that be great?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246CB3:: @ 8246CB3
	.string "Thank you!\p"
	.string "I'll go register us, and that's\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246CE9:: @ 8246CE9
	.string "Aww, that's too bad. We would've been\n"
	.string "the toughest tag team around!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D2D:: @ 8246D2D
	.string "Me?\n"
	.string "I'm TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D3F:: @ 8246D3F
	.string "What do I have with me?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D6A:: @ 8246D6A
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Hey?\n"
	.string "You'll team up with me, right?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246D9E:: @ 8246D9E
	.string "Okay!\p"
	.string "I'll go register!\n"
	.string "Let's be excellent together!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246DD3:: @ 8246DD3
	.string "My POKéMON are tough for sure…\n"
	.string "It's too bad you don't want to team up.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E1A:: @ 8246E1A
	.string "Yay-hey!\n"
	.string "Call me GUITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E39:: @ 8246E39
	.string "Check out my entourage!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246E64:: @ 8246E64
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yay-hey! Pretty wild, huh?\n"
	.string "We'll have to do a duet in a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246EB6:: @ 8246EB6
	.string "Yay-hey! Right on!\n"
	.string "I'll do that registration stuff now!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246EEE:: @ 8246EEE
	.string "My POKéMON rock hard!\n"
	.string "You'll be sorry, I tell you!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F21:: @ 8246F21
	.string "Pleased to meet you.\n"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F4C:: @ 8246F4C
	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246F7B:: @ 8246F7B
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "May I ask you to join me in a tag-team\n"
	.string "partnership arrangement?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_246FCC:: @ 8246FCC
	.string "Ah, I thank you for your trust.\n"
	.string "I shall be done with the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247013:: @ 8247013
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24705B:: @ 824705B
	.string "Hello, I'm {STR_VAR_1},\n"
	.string "and I'm a POKéFAN.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24707D:: @ 824707D
	.string "I have with me now one {STR_VAR_2}\n"
	.string "that knows the move {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2470B2:: @ 82470B2
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Do you like what you see?\n"
	.string "Why don't you be my tag partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2470FD:: @ 82470FD
	.string "Thank you!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24712A:: @ 824712A
	.string "My POKéMON are top grade…\n"
	.string "It's too bad you can't appreciate that.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24716C:: @ 824716C
	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24718D:: @ 824718D
	.string "The POKéMON that I've toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2471C7:: @ 82471C7
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What say you to a tag team with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2471FB:: @ 82471FB
	.string "Hm!\n"
	.string "I shall register us right away!\l"
	.string "Let us both do our best!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247238:: @ 8247238
	.string "I will hope that your choice is\n"
	.string "indeed correct…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247268:: @ 8247268
	.string "Hello, hello.\n"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247291:: @ 8247291
	.string "I've raised my POKéMON thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2472C7:: @ 82472C7
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're what I have.\p"
	.string "Wouldn't you like to team up with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247313:: @ 8247313
	.string "Good, good.\n"
	.string "I'll see to the registration right away.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247348:: @ 8247348
	.string "Perhaps we can form a team the next\n"
	.string "time we meet.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24737A:: @ 824737A
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24738F:: @ 824738F
	.string "The team I've been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2473C6:: @ 82473C6
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Want to be my partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2473FB:: @ 82473FB
	.string "Okay, I'll give it my best!\n"
	.string "I'll go register now, all right?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247438:: @ 8247438
	.string "You're not going to find many tougher\n"
	.string "partners than me!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247470:: @ 8247470
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247484:: @ 8247484
	.string "What POKéMON do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2474AF:: @ 82474AF
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2474EC:: @ 82474EC
	.string "Great, thanks!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24751D:: @ 824751D
	.string "My POKéMON and I are strong.\n"
	.string "What a letdown.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24754A:: @ 824754A
	.string "I'm NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24755C:: @ 824755C
	.string "My POKéMON team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24758B:: @ 824758B
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let's be in a tag team together!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2475BC:: @ 82475BC
	.string "Yay!\n"
	.string "Let me go register!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2475D5:: @ 82475D5
	.string "You'll regret not having my tough\n"
	.string "POKéMON on your side!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24760D:: @ 824760D
	.string "Hello!\n"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247629:: @ 8247629
	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247655:: @ 8247655
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren't they nice?\n"
	.string "Care to join us in a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24769B:: @ 824769B
	.string "Thanks a bunch!\p"
	.string "I'll go register at the counter.\n"
	.string "Let's not disappoint each other!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2476ED:: @ 82476ED
	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247724:: @ 8247724
	.string "Hello.\n"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247749:: @ 8247749
	.string "I have found my POKéMON, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24777A:: @ 824777A
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2477CE:: @ 82477CE
	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won't be long with the registration!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247807:: @ 8247807
	.string "With the POKéMON I found, we wouldn't\n"
	.string "have lost…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247838:: @ 8247838
	.string "Ahoy, there!\n"
	.string "I'm SAILOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247854:: @ 8247854
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247889:: @ 8247889
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you're not going to turn\n"
	.string "me down. We will team up, right?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2478DD:: @ 82478DD
	.string "I didn't expect any less!\n"
	.string "I'll go register now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24790D:: @ 824790D
	.string "We would've stormed through\n"
	.string "the opposition! Too bad!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247942:: @ 8247942
	.string "Hi, I'm {STR_VAR_1}.\n"
	.string "I'm a COLLECTOR.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24795F:: @ 824795F
	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247991:: @ 8247991
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, huh?\n"
	.string "We should be in a team together.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2479CE:: @ 82479CE
	.string "Oh, yeah!\p"
	.string "Well, let's not waste any time.\n"
	.string "I'll go register the two of us.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A18:: @ 8247A18
	.string "Well, that's upsetting.\n"
	.string "You don't appreciate my POKéMON.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A51:: @ 8247A51
	.string "Howdy, I'm {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247A76:: @ 8247A76
	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247AA1:: @ 8247AA1
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don't you think we'd make an impressive\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247AE3:: @ 8247AE3
	.string "That's super!\n"
	.string "I'll deal with the registration now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B16:: @ 8247B16
	.string "Next time, choose my POKéMON,\n"
	.string "will you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B3E:: @ 8247B3E
	.string "My name's {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B62:: @ 8247B62
	.string "Let me tell you about my team. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247B9B:: @ 8247B9B
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247BE7:: @ 8247BE7
	.string "We'll be at our best!\n"
	.string "I'll get the registration done quick!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C23:: @ 8247C23
	.string "I hope you'll choose my POKéMON\n"
	.string "next time.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C4E:: @ 8247C4E
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
	.string "I consider myself an AROMA LADY.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247C8C:: @ 8247C8C
	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247CB2:: @ 8247CB2
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they strike your fancy.\n"
	.string "Would you care to be my partner?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D07:: @ 8247D07
	.string "I'm honored by your acceptance.\n"
	.string "I will go register right this instant.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D4E:: @ 8247D4E
	.string "It would be wonderful if we could form\n"
	.string "a tag team the next time we meet.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247D97:: @ 8247D97
	.string "Want to know who I am?\n"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247DC7:: @ 8247DC7
	.string "The POKéMON that I have with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247DFE:: @ 8247DFE
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh?\n"
	.string "How about you and I partner up?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247E3E:: @ 8247E3E
	.string "That's a sound decision!\n"
	.string "I'll go do the registration paperwork.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247E7E:: @ 8247E7E
	.string "Hmm…\n"
	.string "I think my POKéMON are tough…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EA1:: @ 8247EA1
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EB5:: @ 8247EB5
	.string "The POKéMON I have right now are one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247EE9:: @ 8247EE9
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Cool, huh?\p"
	.string "Don't you think it'd be pretty cool\n"
	.string "if we made a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247F3F:: @ 8247F3F
	.string "Cool!\n"
	.string "I'll go do the registration in a flash!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247F6D:: @ 8247F6D
	.string "I thought that we'd make just\n"
	.string "the greatest team ever.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FA3:: @ 8247FA3
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FB7:: @ 8247FB7
	.string "The team I've been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_247FE9:: @ 8247FE9
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound okay?\n"
	.string "How about we become tag partners?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248031:: @ 8248031
	.string "Sounds A-OK!\n"
	.string "I'd better do the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24805E:: @ 824805E
	.string "I was thinking how we would be\n"
	.string "one tough team…$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24808D:: @ 824808D
	.string "Heyo!\n"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2480AB:: @ 82480AB
	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2480DC:: @ 82480DC
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what!\p"
	.string "Let's do it!\n"
	.string "We'll stomp around as a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248128:: @ 8248128
	.string "Good call!\n"
	.string "I'll register the both of us!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248151:: @ 8248151
	.string "My POKéMON are brutal!\n"
	.string "It's not my fault if you regret this!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24818E:: @ 824818E
	.string "Yo, there!\n"
	.string "I'm KINDLER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2481A9:: @ 82481A9
	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2481E1:: @ 82481E1
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what do you say?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248221:: @ 8248221
	.string "All right!\n"
	.string "I'll get on with the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24824F:: @ 824824F
	.string "Promise you'll partner up with me\n"
	.string "the next time we run into each other.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248297:: @ 8248297
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2482B1:: @ 82482B1
	.string "I've been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2482DC:: @ 82482DC
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it'd be fun to team up?\n"
	.string "I bet it would be!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248321:: @ 8248321
	.string "Yeah!\n"
	.string "Off I go to register!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24833D:: @ 824833D
	.string "Next time, okay?\n"
	.string "I want to be on your team.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248369:: @ 8248369
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24838D:: @ 824838D
	.string "The POKéMON I've been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2483C1:: @ 82483C1
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248401:: @ 8248401
	.string "Why, thank you!\n"
	.string "I will do the registration now.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248431:: @ 8248431
	.string "It would be nice if I could join you\n"
	.string "some other time.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248467:: @ 8248467
	.string "I'm PSYCHIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248477:: @ 8248477
	.string "The twosome I've been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2484AC:: @ 82484AC
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Would you like to form a tag team\n"
	.string "with me?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2484E7:: @ 82484E7
	.string "Sure thing!\n"
	.string "I'll take care of the registration!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248517:: @ 8248517
	.string "If we meet again, that's when I'd like\n"
	.string "to team up with you.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248553:: @ 8248553
	.string "I'm {STR_VAR_1}.\n"
	.string "I'm a PSYCHIC.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24856A:: @ 824856A
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24857D:: @ 824857D
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're my disciples.\p"
	.string "Doesn't the idea of forming a tag-team\n"
	.string "partnership intrigue you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2485E5:: @ 82485E5
	.string "Thank you.\n"
	.string "I'll go deal with the registration.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248614:: @ 8248614
	.string "I hope there will be another chance\n"
	.string "to forge an alliance.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24864E:: @ 824864E
	.string "I'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248661:: @ 8248661
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248671:: @ 8248671
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
	.string "May I please be your partner on\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2486C6:: @ 82486C6
	.string "Ooh, thank you!\n"
	.string "I'll register at the counter right away!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2486FF:: @ 82486FF
	.string "Please?\n"
	.string "May I join you the next time?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248725:: @ 8248725
	.string "Hiya! The name's {STR_VAR_1}!\n"
	.string "I'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248751:: @ 8248751
	.string "The POKéMON I've raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248781:: @ 8248781
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound interesting?\n"
	.string "How about we form a tag team, then?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2487C9:: @ 82487C9
	.string "All righty!\n"
	.string "You leave the registration to me!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2487F7:: @ 82487F7
	.string "You have to team up with me next time,\n"
	.string "all right?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248829:: @ 8248829
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
	.string "that I am a POKéFAN.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24885B:: @ 824885B
	.string "The darling POKéMON I've raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248892:: @ 8248892
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren't they just the cutest?\n"
	.string "We ought to make a team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2488D8:: @ 82488D8
	.string "Thank you, dear!\n"
	.string "I'll be on my way to register!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248908:: @ 8248908
	.string "My darling POKéMON are the best,\n"
	.string "I'll have you know. How annoying!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24894B:: @ 824894B
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24895F:: @ 824895F
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_24896F:: @ 824896F
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I've trained.\p"
	.string "You and me, let's make a tag team.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2489BD:: @ 82489BD
	.string "That's cool!\n"
	.string "I'll register the two of us.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_2489E7:: @ 82489E7
	.string "If we meet again, you owe me\n"
	.string "a tag team!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A10:: @ 8248A10
	.string "What's happening?\n"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A40:: @ 8248A40
	.string "I got a couple decent POKéMON.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248A72:: @ 8248A72
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It'd be neat if we made a tag team\n"
	.string "together, so how about it?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248AC0:: @ 8248AC0
	.string "Right on!\n"
	.string "You wait while I register, okay?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248AEB:: @ 8248AEB
	.string "I expect you'll let me join you\n"
	.string "next time, how's that?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B22:: @ 8248B22
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B39:: @ 8248B39
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248B4C:: @ 8248B4C
	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That's my pair.\p"
	.string "What do you think?\n"
	.string "We'd make a good team, I'd say.$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248BB4:: @ 8248BB4
	.string "I like that answer!\n"
	.string "I'll get done with registration fast!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248BEE:: @ 8248BEE
	.string "You'll give me another chance to form\n"
	.string "a partnership, won't you?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C2E:: @ 8248C2E
	.string "Hi, there! Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C5B:: @ 8248C5B
	.string "Check out what I've been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248C90:: @ 8248C90
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, huh?\n"
	.string "It'd be sweet to form a team, too!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248CCF:: @ 8248CCF
	.string "Much obliged!\n"
	.string "I'll get this registration thing done!$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_248D04:: @ 8248D04
	.string "If we meet again, you have to team up\n"
	.string "with me. You'll do that, right?$"

