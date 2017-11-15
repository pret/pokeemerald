BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8243D92
	map_script 5, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7
	map_script 3, BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0
	map_script 4, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14
	map_script 2, BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DA7: @ 8243DA7
	setvar VAR_0x8004, 17
	special sub_81A8E7C
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript1_243DB0: @ 8243DB0
	checkflag FLAG_0x152
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA
	clearflag FLAG_0x2C7
	clearflag FLAG_0x2C8
	clearflag FLAG_0x2C9
	clearflag FLAG_0x2CA
	clearflag FLAG_0x2CB
	clearflag FLAG_0x2CC
	setflag FLAG_0x360
	setflag FLAG_0x361
	setvar VAR_0x8004, 10
	special sub_8161F74
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243DDA:: @ 8243DDA
	setvar VAR_0x4010, 7
	setvar VAR_0x4011, 7
	setvar VAR_0x4012, 7
	setvar VAR_0x4013, 7
	setvar VAR_0x4014, 7
	setvar VAR_0x4015, 7
	setvar VAR_0x4016, 7
	setvar VAR_0x4017, 7
	setvar VAR_0x4001, 1
	setvar VAR_0x4003, 1
	setobjectxyperm 1, 10, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E14: @ 8243E14
	map_script_2 VAR_0x4003, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E1E:: @ 8243E1E
	turnobject 255, 2
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScript2_243E23: @ 8243E23
	map_script_2 VAR_0x4001, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41
	map_script_2 VAR_0x4003, 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E35:: @ 8243E35
	lockall
	setvar VAR_0x4003, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E41:: @ 8243E41
	lockall
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77
	waitmovement 0
	moveobjectoffscreen 1
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_2725A6
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244056, 4
	special sp000_heal_pokemon
	setvar VAR_0x4001, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E75: @ 8243E75
	step_down
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243E77: @ 8243E77
	step_left
	step_25
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E7A:: @ 8243E7A
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_244094
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_24410C, 4
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243E9D:: @ 8243E9D
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special sub_81A1780
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_241C03
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EB5:: @ 8243EB5
	msgbox BattleFrontier_BattleTowerMultiBattleRoom_Text_244149, 4
	closemessage
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_2725A6
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4
	closedoor 10, 1
	waitdooranim
	warp BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EE4:: @ 8243EE4
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243EF6: @ 8243EF6
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F08: @ 8243F08
	applymovement 1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26
	applymovement 255, BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1A: @ 8243F1A
	step_up
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F1E: @ 8243F1E
	step_right
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F22: @ 8243F22
	step_left
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243F26: @ 8243F26
	step_up
	step_54
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F29:: @ 8243F29
	lock
	faceplayer
	setvar VAR_0x4002, 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36:: @ 8243F36
	checkflag FLAG_0x152
	goto_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 0
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 1
	special sub_8161F74
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 2
	special sub_8161F74
	waitmessage
	multichoicedefault 20, 8, 94, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	case 127, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 3
	special sub_8161F74
	waitmessage
	waitbuttonpress
	closemessage
	compare_var_to_value VAR_FACING, 1
	call_if 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FD4
	compare_var_to_value VAR_FACING, 1
	call_if 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FDF
	removeobject VAR_LAST_TALKED
	setflag FLAG_0x152
	warpsilent BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FC3:: @ 8243FC3
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 4
	special sub_8161F74
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
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_243FF2: @ 8243FF2
	step_17
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_16
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243FFB:: @ 8243FFB
	lock
	faceplayer
	setvar VAR_0x4002, 1
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244008:: @ 8244008
	lock
	faceplayer
	setvar VAR_0x4002, 2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244015:: @ 8244015
	lock
	faceplayer
	setvar VAR_0x4002, 3
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244022:: @ 8244022
	lock
	faceplayer
	setvar VAR_0x4002, 4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24402F:: @ 824402F
	lock
	faceplayer
	setvar VAR_0x4002, 5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_24403C:: @ 824403C
	lock
	faceplayer
	setvar VAR_0x4002, 6
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_243F36
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_244049:: @ 8244049
	lock
	faceplayer
	setvar VAR_0x4002, 7
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

BattleFrontier_BattleTowerMultiBattleRoom_Text_244149: @ 8244149
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "MULTI BATTLE ROOM.$"

	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

	.string "On {STR_VAR_1}’s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

	.string "Thank you!\n"
	.string "I’ll go register right now.$"

	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let’s form a tag team!$"

	.string "Thank you very much!\n"
	.string "I’ll be done with registration quickly!$"

	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

	.string "Um, my name’s {STR_VAR_3}, and I’m\n"
	.string "{STR_VAR_1}’s no. {STR_VAR_2} apprentice.\p"
	.string "Snivel…\p"
	.string "I’m sorry!\n"
	.string "This tension is making me cry…$"

	.string "{STR_VAR_3} advised me, so I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Snivel…\n"
	.string "Please, please team up with me!$"

	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I’m sorry…\n"
	.string "I’m so happy, I’m crying…\p"
	.string "I’ll go register right away.\n"
	.string "Please don’t go away!$"

	.string "Oh, b-but…\n"
	.string "Sob… Waaaaah!$"

	.string "Hi, there! I’m {STR_VAR_3}!\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

	.string "{STR_VAR_3} recommended my crew.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that’s what I have! Cool, huh?\p"
	.string "So come on!\n"
	.string "Let’s form a tag team!$"

	.string "Yay! Great!\n"
	.string "Okay, I’ll go register, okay?$"

	.string "Aww, why?\n"
	.string "I wanted to team up, {PLAYER}!$"

	.string "I’m {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the famous {STR_VAR_1}!$"

	.string "I looked to {STR_VAR_3} for advice.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that’s my pair.\p"
	.string "Please, will you join me in\n"
	.string "a tag team?$"

	.string "Thank you!\n"
	.string "I’ll register right away!$"

	.string "{PLAYER}, I had been hoping to join\n"
	.string "you in a tag team…$"

	.string "Um… I’m sincerely happy that you\n"
	.string "would take the time to talk to me.\p"
	.string "I’m {STR_VAR_3}.\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice…$"

	.string "{STR_VAR_3} gave me advice.\n"
	.string "I’m very grateful for it.\p"
	.string "I have a team of one {STR_VAR_2}\n"
	.string "with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I’m asking a lot…\p"
	.string "I don’t think you’ll be willing to,\n"
	.string "but may I join you as a partner?$"

	.string "Really? I can’t believe it!\n"
	.string "I can’t believe you’ll let me join you!\l"
	.string "I… I won’t let you down!\p"
	.string "Um… If it’s really okay, I’ll go register\n"
	.string "right this instant!$"

	.string "Oh…\n"
	.string "I didn’t think I was good enough…$"

	.string "Hi, I’m {STR_VAR_3}.\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

	.string "{STR_VAR_3} told me that it would be\n"
	.string "good to make this team:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}.\p"
	.string "Not bad, huh?\n"
	.string "Want me to team up with you?$"

	.string "Okay, glad to join you!\n"
	.string "I hope you won’t mess things up for me!\l"
	.string "I’ll do my registration now.$"

	.string "Huh? Why did you turn me down?\n"
	.string "You’re no judge of character!$"

	.string "I’m {STR_VAR_3} and I’m a TRIATHLETE.\n"
	.string "I’m busy every day what with jogging,\l"
	.string "training, and rapping.\p"
	.string "I also happen to be {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice.$"

	.string "This is what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of effort into raising\n"
	.string "them, even though I’m busy.\p"
	.string "Let’s form a tag team\n"
	.string "and give it a go!$"

	.string "Thanks, that’s the spirit!\n"
	.string "Hang tight while I go register, okay?$"

	.string "I took time from my busy schedule\n"
	.string "to be here! Give me a break!$"

	.string "Hi!\n"
	.string "How’s it going?\p"
	.string "I’m {STR_VAR_3}, {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"

	.string "Listen, listen! You have to hear about\n"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Of course I raised them superbly!\p"
	.string "So, want to team up?\n"
	.string "I’m sure it’ll be a great combo!$"

	.string "Yay, I think this will be fun!\n"
	.string "I’ll go register!$"

	.string "Oh, you’re mean!\n"
	.string "I come recommended, you know.$"

	.string "Please let me introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I serve as {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice.$"

	.string "I sought the sage advice of\n"
	.string "{STR_VAR_3} and raised my team\l"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"

	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please agree to a tag team with me!$"

	.string "Oh… I’m delighted!\n"
	.string "I promise to give you my best!\p"
	.string "Of course I will register us!\n"
	.string "Please wait!$"

	.string "I had been hoping to join you,\n"
	.string "{PLAYER}…$"

	.string "Eek! You spoke to me!\n"
	.string "I… I’m overjoyed!\p"
	.string "I’m {STR_VAR_3}! I’m {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice!$"

	.string "On {STR_VAR_3}’s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can you grant me my wish?\n"
	.string "I want to be your tag-team partner!$"

	.string "Eek! I… I feel giddy!\n"
	.string "Thank you so much!\l"
	.string "I’ll go register us right away!$"

	.string "Waaah! Don’t you feel any pity?\n"
	.string "But that makes you cooler…$"

	.string "Yeehaw! I’m {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3}’s my name, hello, hello!$"

	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Good stuff, huh?\n"
	.string "You’ll partner with me, won’t you?$"

	.string "Okay, excellent!\n"
	.string "I’ll get the registration done quickly!$"

	.string "Gwaaah!\n"
	.string "You’re a calculating one, {PLAYER}!$"

	.string "Hey! There’s big trouble! This is\n"
	.string "the BATTLE TOWER’s last day!\p"
	.string "… … … … … …\n"
	.string "I’m only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I’m {STR_VAR_1}’s 1,000th apprentice!\l"
	.string "Actually, I’m no. {STR_VAR_2}!$"

	.string "{STR_VAR_3} gave me some advice.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I’ve got ten of each kind!\l"
	.string "Actually, just one of each!\p"
	.string "How about it?\n"
	.string "Want to try tag battles with me?$"

	.string "Yippee!\n"
	.string "I’ll give you a POKéMON as my thanks!\p"
	.string "Just joking! But I will really go do\n"
	.string "the registration, okay?$"

	.string "Oh, that’s so cold! I’ll have to wreck\n"
	.string "the BATTLE TOWER for that!\p"
	.string "Of course I won’t!$"

	.string "Hey, there, I’m rockin’ and a-rollin’!\n"
	.string "POKéMON, I be controllin’!\p"
	.string "I’m {STR_VAR_3} the rappin’ SAILOR.\n"
	.string "Don’t be mistakin’ me for no wailer!\p"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Me, you shouldn’t be quick to dismiss!$"

	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, put together my team of pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our meeting we should commemorate,\n"
	.string "with a tag-team victory to celebrate!$"

	.string "Hey, hey, I like your style!\n"
	.string "Our registration, I will go file!$"

	.string "Oh, hey, {PLAYER}, now that’s cold!\n"
	.string "If I may be so bold!$"

	.string "Yippee-yahoo!\n"
	.string "Oh, don’t run! I was just having fun!\p"
	.string "Howdy! I’m {STR_VAR_3}!\n"
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

	.string "{STR_VAR_3} told me what to do.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did choose.\p"
	.string "So, what do you say?\n"
	.string "Come on, make my day!\p"
	.string "Please, I’m begging you!\n"
	.string "Let me join you, don’t leave me blue!$"

	.string "Yeahah! Luck is with me!\n"
	.string "It sure makes me happy!\p"
	.string "Before we go join the fray,\n"
	.string "I’ll go register right away!$"

	.string "You’re turning me down?\n"
	.string "{PLAYER}, you’re making me frown!$"

	.string "Cough!\p"
	.string "Oh, sorry, I have a cold.\n"
	.string "My POKéMON are fine, though.\p"
	.string "My name’s {STR_VAR_3}, {STR_VAR_1}’s\n"
	.string "no. {STR_VAR_2} apprentice. Cough!$"

	.string "I took {STR_VAR_3}’s advice to heart\n"
	.string "and put together my team of\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I trained them every day,\n"
	.string "even in wind and rain.\p"
	.string "That’s why I have this cold,\n"
	.string "I think.\p"
	.string "That’s what I’m about.\n"
	.string "Want to be my tag partner?$"

	.string "Thanks, I appreciate this!\n"
	.string "Cough, cough!\l"
	.string "Hang on while I go register.$"

	.string "Oh, you won’t?\n"
	.string "{PLAYER}, I think we’d make a good pair.$"

	.string "Oh, hello!\n"
	.string "This is nerve-racking.\p"
	.string "I’m {STR_VAR_3}.\n"
	.string "I’m the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

	.string "{STR_VAR_3} said this team’ll be good--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I’m feeling self-conscious about this,\n"
	.string "but will you let me join you?$"

	.string "Oh, gee, thank you!\n"
	.string "I feel bashful, but I’ll do my best!\p"
	.string "I’ll go get the registration done.$"

	.string "Oh, please don’t say no!\n"
	.string "I feel self-conscious enough already…$"

	.string "I am {STR_VAR_3}, and that’s no lie.\n"
	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice.$"

	.string "{STR_VAR_3} recommended my team.\p"
	.string "Since the advice sounded sincere,\n"
	.string "I decided to bring with me\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"

	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I would like you to accept\n"
	.string "me as your tag-team partner.$"

	.string "You really will accept me?\n"
	.string "It would be too terrible otherwise.\p"
	.string "But since you’ve agreed, this is fine.\n"
	.string "I shall go register the both of us.$"

	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"

	.string "I’m {STR_VAR_1}, and I’m a LASS!$"

	.string "What I have are one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and one$"

	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "Those are what I have with me.\p"
	.string "Will you be my partner?$"

	.string "Thank you!\n"
	.string "I’ll go do the registration!$"

	.string "You don’t want to be my partner?\n"
	.string "You’ll regret it later!$"

	.string "Hello!\p"
	.string "I’m YOUNGSTER {STR_VAR_1}!$"

	.string "Want to know what I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You’ll be my tag-team partner,\n"
	.string "won’t you?$"

	.string "Yay!\n"
	.string "I’ll go and register, okay?$"

	.string "Aww! If you’d form a tag team with\n"
	.string "my POKéMON, we’d be unstoppable!$"

	.string "Yahoo!\n"
	.string "I’m HIKER {STR_VAR_1}!$"

	.string "Know what I have with me?\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"

	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Sounds good, eh?\n"
	.string "Want to form a tag team?$"

	.string "Yahoo!\n"
	.string "I’ll go do the registering, then.$"

	.string "I would’ve liked to battle with you\n"
	.string "at my side.$"

	.string "Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a BEAUTY!$"

	.string "Do you know what I’ve been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Want to make a tag team together?$"

	.string "Wonderful!\n"
	.string "I’ll get the registration done now!$"

	.string "How disappointing!\p"
	.string "We two together--we would’ve been\n"
	.string "the best!$"

	.string "Yo!\p"
	.string "You know who I am?\n"
	.string "I’m {STR_VAR_1} the FISHERMAN!$"

	.string "I’ve got with me a team of one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, how about it?\n"
	.string "Will you battle at my side?$"

	.string "Good, good!\n"
	.string "Leave it up to me!\p"
	.string "I’ll go and register us now.$"

	.string "We matched up perfectly, too…$"

	.string "Glad to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a LADY.$"

	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "For I wish to have you as my partner.$"

	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"

	.string "I’m sure that you will regret not\n"
	.string "having me as your partner.$"

	.string "I’m TRIATHLETE {STR_VAR_1}!$"

	.string "What I have…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That’s my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"

	.string "Gee, thanks!\n"
	.string "I’ll go register at the counter.$"

	.string "We two together, we would’ve been\n"
	.string "tough for certain!$"

	.string "Hiya!\n"
	.string "I’m BUG CATCHER {STR_VAR_1}!$"

	.string "Check out what I have!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you want to form a tag team?$"

	.string "Gotcha!\p"
	.string "I’ll go do the registration stuff\n"
	.string "at the counter.$"

	.string "Aww, my POKéMON are awesome.\n"
	.string "I hope you won’t regret this!$"

	.string "Good day!\n"
	.string "I’m SCHOOL KID {STR_VAR_1}!$"

	.string "What I’ve been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"

	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don’t you think?\n"
	.string "Would you care to form a tag team?$"

	.string "Thank you very much!\n"
	.string "I’ll get done with the registration.$"

	.string "That’s too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"

	.string "Yo! Let me tell you who I am!\n"
	.string "I’m RICH BOY {STR_VAR_1}!$"

	.string "Guess what I got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I’m willing to offer you the chance\n"
	.string "to be in a tag team with me.$"

	.string "Smart move!\p"
	.string "I’ll finish up the registration\n"
	.string "process quick!$"

	.string "You’d turn me of all people down?\n"
	.string "You’ll regret that decision for sure!$"

	.string "Hiyah!\n"
	.string "I am BLACK BELT {STR_VAR_1}.$"

	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"

	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"

	.string "Hiyah!\n"
	.string "I will go register forthwith!$"

	.string "I see… I hope for an opportunity\n"
	.string "the next time we meet…$"

	.string "Hi, there!\n"
	.string "I’m {STR_VAR_1}, and I’m a TUBER!$"

	.string "I’ll tell you what I have.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "May I please be on your tag team?$"

	.string "Thank you!\n"
	.string "I’ll go register us now!$"

	.string "If we’d become partners, we could\n"
	.string "have been so strong!$"

	.string "Greetings…\n"
	.string "I am HEX MANIAC {STR_VAR_1}…$"

	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"

	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"

	.string "I thank you…\n"
	.string "I shall register us…$"

	.string "I so longed to join you…$"

	.string "How do you do? I’m {STR_VAR_1},\n"
	.string "and I’m a POKéMON BREEDER!$"

	.string "I’m raising a couple good ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Feel like making a tag team with me?$"

	.string "Thank you kindly!\p"
	.string "I’ll go take care of the registration\n"
	.string "stuff, so you wait right here!$"

	.string "I was looking forward to being\n"
	.string "your partner…$"

	.string "Well, hello!\n"
	.string "I’m TRIATHLETE {STR_VAR_1}!$"

	.string "Want to know what I run with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Want to be in a tag team with me?$"

	.string "Good going!\p"
	.string "I’ll be quick and get the registration\n"
	.string "all done!$"

	.string "You and me, we would’ve been tops.\n"
	.string "It’s too bad…$"

	.string "Hey, there! My name’s {STR_VAR_1}!\n"
	.string "I’m a TRIATHLETE!$"

	.string "I go on runs with my durable team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, huh?\n"
	.string "We should be in a tag team together!$"

	.string "All right!\n"
	.string "I’ll go register in a flash!$"

	.string "I really wanted to battle as your\n"
	.string "tag-team partner…$"

	.string "I’m BATTLE GIRL {STR_VAR_1}!$"

	.string "I’ve been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Do you like that combo?\n"
	.string "How about you and me join up?$"

	.string "Why, thanks!\p"
	.string "I’ll get the registration done\n"
	.string "right now!$"

	.string "With you, I thought we could form\n"
	.string "the ultimate tag team…$"

	.string "I’m TRIATHLETE {STR_VAR_1}!$"

	.string "I’ve been running with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"

	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be in a tag team.\n"
	.string "Wouldn’t that be great?$"

	.string "Thank you!\p"
	.string "I’ll go register us, and that’s\n"
	.string "right now!$"

	.string "Aww, that’s too bad. We would’ve been\n"
	.string "the toughest tag team around!$"

	.string "Me?\n"
	.string "I’m TUBER {STR_VAR_1}!$"

	.string "What do I have with me?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Hey?\n"
	.string "You’ll team up with me, right?$"

	.string "Okay!\p"
	.string "I’ll go register!\n"
	.string "Let’s be excellent together!$"

	.string "My POKéMON are tough for sure…\n"
	.string "It’s too bad you don’t want to team up.$"

	.string "Yay-hey!\n"
	.string "Call me GUITARIST {STR_VAR_1}!$"

	.string "Check out my entourage!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yay-hey! Pretty wild, huh?\n"
	.string "We’ll have to do a duet in a tag team!$"

	.string "Yay-hey! Right on!\n"
	.string "I’ll do that registration stuff now!$"

	.string "My POKéMON rock hard!\n"
	.string "You’ll be sorry, I tell you!$"

	.string "Pleased to meet you.\n"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"

	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "May I ask you to join me in a tag-team\n"
	.string "partnership arrangement?$"

	.string "Ah, I thank you for your trust.\n"
	.string "I shall be done with the registration.$"

	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"

	.string "Hello, I’m {STR_VAR_1},\n"
	.string "and I’m a POKéFAN.$"

	.string "I have with me now one {STR_VAR_2}\n"
	.string "that knows the move {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Do you like what you see?\n"
	.string "Why don’t you be my tag partner?$"

	.string "Thank you!\n"
	.string "I’ll look after the registration!$"

	.string "My POKéMON are top grade…\n"
	.string "It’s too bad you can’t appreciate that.$"

	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"

	.string "The POKéMON that I’ve toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What say you to a tag team with me?$"

	.string "Hm!\n"
	.string "I shall register us right away!\l"
	.string "Let us both do our best!$"

	.string "I will hope that your choice is\n"
	.string "indeed correct…$"

	.string "Hello, hello.\n"
	.string "I’m {STR_VAR_1}, and I’m an EXPERT.$"

	.string "I’ve raised my POKéMON thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they’re what I have.\p"
	.string "Wouldn’t you like to team up with me?$"

	.string "Good, good.\n"
	.string "I’ll see to the registration right away.$"

	.string "Perhaps we can form a team the next\n"
	.string "time we meet.$"

	.string "I’m DRAGON TAMER {STR_VAR_1}!$"

	.string "The team I’ve been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Want to be my partner?$"

	.string "Okay, I’ll give it my best!\n"
	.string "I’ll go register now, all right?$"

	.string "You’re not going to find many tougher\n"
	.string "partners than me!$"

	.string "I’m BIRD KEEPER {STR_VAR_1}!$"

	.string "What POKéMON do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don’t you think we’d make a decent\n"
	.string "tag team?$"

	.string "Great, thanks!\n"
	.string "I’ll look after the registration!$"

	.string "My POKéMON and I are strong.\n"
	.string "What a letdown.$"

	.string "I’m NINJA BOY {STR_VAR_1}!$"

	.string "My POKéMON team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let’s be in a tag team together!$"

	.string "Yay!\n"
	.string "Let me go register!$"

	.string "You’ll regret not having my tough\n"
	.string "POKéMON on your side!$"

	.string "Hello!\n"
	.string "I’m PARASOL LADY {STR_VAR_1}!$"

	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren’t they nice?\n"
	.string "Care to join us in a tag team?$"

	.string "Thanks a bunch!\p"
	.string "I’ll go register at the counter.\n"
	.string "Let’s not disappoint each other!$"

	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing…$"

	.string "Hello.\n"
	.string "I’m {STR_VAR_1}, and I’m a BUG MANIAC!$"

	.string "I have found my POKéMON, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"

	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won’t be long with the registration!$"

	.string "With the POKéMON I found, we wouldn’t\n"
	.string "have lost…$"

	.string "Ahoy, there!\n"
	.string "I’m SAILOR {STR_VAR_1}!$"

	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you’re not going to turn\n"
	.string "me down. We will team up, right?$"

	.string "I didn’t expect any less!\n"
	.string "I’ll go register now.$"

	.string "We would’ve stormed through\n"
	.string "the opposition! Too bad!$"

	.string "Hi, I’m {STR_VAR_1}.\n"
	.string "I’m a COLLECTOR.$"

	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, huh?\n"
	.string "We should be in a team together.$"

	.string "Oh, yeah!\p"
	.string "Well, let’s not waste any time.\n"
	.string "I’ll go register the two of us.$"

	.string "Well, that’s upsetting.\n"
	.string "You don’t appreciate my POKéMON.$"

	.string "Howdy, I’m {STR_VAR_1}.\n"
	.string "I’m a POKéMON RANGER.$"

	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don’t you think we’d make an impressive\n"
	.string "tag team?$"

	.string "That’s super!\n"
	.string "I’ll deal with the registration now.$"

	.string "Next time, choose my POKéMON,\n"
	.string "will you?$"

	.string "My name’s {STR_VAR_1}.\n"
	.string "I’m a POKéMON RANGER!$"

	.string "Let me tell you about my team. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"

	.string "We’ll be at our best!\n"
	.string "I’ll get the registration done quick!$"

	.string "I hope you’ll choose my POKéMON\n"
	.string "next time.$"

	.string "Pleased to meet you. I’m {STR_VAR_1}.\n"
	.string "I consider myself an AROMA LADY.$"

	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they strike your fancy.\n"
	.string "Would you care to be my partner?$"

	.string "I’m honored by your acceptance.\n"
	.string "I will go register right this instant.$"

	.string "It would be wonderful if we could form\n"
	.string "a tag team the next time we meet.$"

	.string "Want to know who I am?\n"
	.string "I’m {STR_VAR_1}, the RUIN MANIAC!$"

	.string "The POKéMON that I have with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh?\n"
	.string "How about you and I partner up?$"

	.string "That’s a sound decision!\n"
	.string "I’ll go do the registration paperwork.$"

	.string "Hmm…\n"
	.string "I think my POKéMON are tough…$"

	.string "I’m COOLTRAINER {STR_VAR_1}!$"

	.string "The POKéMON I have right now are one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Cool, huh?\p"
	.string "Don’t you think it’d be pretty cool\n"
	.string "if we made a tag team?$"

	.string "Cool!\n"
	.string "I’ll go do the registration in a flash!$"

	.string "I thought that we’d make just\n"
	.string "the greatest team ever.$"

	.string "I’m COOLTRAINER {STR_VAR_1}!$"

	.string "The team I’ve been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound okay?\n"
	.string "How about we become tag partners?$"

	.string "Sounds A-OK!\n"
	.string "I’d better do the registration.$"

	.string "I was thinking how we would be\n"
	.string "one tough team…$"

	.string "Heyo!\n"
	.string "I’m {STR_VAR_1}, the POKéMANIAC!$"

	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that’s what!\p"
	.string "Let’s do it!\n"
	.string "We’ll stomp around as a tag team!$"

	.string "Good call!\n"
	.string "I’ll register the both of us!$"

	.string "My POKéMON are brutal!\n"
	.string "It’s not my fault if you regret this!$"

	.string "Yo, there!\n"
	.string "I’m KINDLER {STR_VAR_1}!$"

	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what do you say?\n"
	.string "Want to form a tag team?$"

	.string "All right!\n"
	.string "I’ll get on with the registration.$"

	.string "Promise you’ll partner up with me\n"
	.string "the next time we run into each other.$"

	.string "I’m {STR_VAR_1}, and I’m a CAMPER!$"

	.string "I’ve been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"

	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it’d be fun to team up?\n"
	.string "I bet it would be!$"

	.string "Yeah!\n"
	.string "Off I go to register!$"

	.string "Next time, okay?\n"
	.string "I want to be on your team.$"

	.string "Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a PICNICKER!$"

	.string "The POKéMON I’ve been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"

	.string "Why, thank you!\n"
	.string "I will do the registration now.$"

	.string "It would be nice if I could join you\n"
	.string "some other time.$"

	.string "I’m PSYCHIC {STR_VAR_1}!$"

	.string "The twosome I’ve been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Would you like to form a tag team\n"
	.string "with me?$"

	.string "Sure thing!\n"
	.string "I’ll take care of the registration!$"

	.string "If we meet again, that’s when I’d like\n"
	.string "to team up with you.$"

	.string "I’m {STR_VAR_1}.\n"
	.string "I’m a PSYCHIC.$"

	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they’re my disciples.\p"
	.string "Doesn’t the idea of forming a tag-team\n"
	.string "partnership intrigue you?$"

	.string "Thank you.\n"
	.string "I’ll go deal with the registration.$"

	.string "I hope there will be another chance\n"
	.string "to forge an alliance.$"

	.string "I’m SCHOOL KID {STR_VAR_1}!$"

	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
	.string "May I please be your partner on\n"
	.string "a tag team?$"

	.string "Ooh, thank you!\n"
	.string "I’ll register at the counter right away!$"

	.string "Please?\n"
	.string "May I join you the next time?$"

	.string "Hiya! The name’s {STR_VAR_1}!\n"
	.string "I’m a POKéMON BREEDER!$"

	.string "The POKéMON I’ve raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound interesting?\n"
	.string "How about we form a tag team, then?$"

	.string "All righty!\n"
	.string "You leave the registration to me!$"

	.string "You have to team up with me next time,\n"
	.string "all right?$"

	.string "I’m {STR_VAR_1}, and I’m proud to say\n"
	.string "that I am a POKéFAN.$"

	.string "The darling POKéMON I’ve raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren’t they just the cutest?\n"
	.string "We ought to make a team!$"

	.string "Thank you, dear!\n"
	.string "I’ll be on my way to register!$"

	.string "My darling POKéMON are the best,\n"
	.string "I’ll have you know. How annoying!$"

	.string "Hi, I’m SWIMMER {STR_VAR_1}.$"

	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I’ve trained.\p"
	.string "You and me, let’s make a tag team.$"

	.string "That’s cool!\n"
	.string "I’ll register the two of us.$"

	.string "If we meet again, you owe me\n"
	.string "a tag team!$"

	.string "What’s happening?\n"
	.string "I’m {STR_VAR_1}, and I’m a TRIATHLETE.$"

	.string "I got a couple decent POKéMON.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It’d be neat if we made a tag team\n"
	.string "together, so how about it?$"

	.string "Right on!\n"
	.string "You wait while I register, okay?$"

	.string "I expect you’ll let me join you\n"
	.string "next time, how’s that?$"

	.string "I’m the TRIATHLETE {STR_VAR_1}!$"

	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That’s my pair.\p"
	.string "What do you think?\n"
	.string "We’d make a good team, I’d say.$"

	.string "I like that answer!\n"
	.string "I’ll get done with registration fast!$"

	.string "You’ll give me another chance to form\n"
	.string "a partnership, won’t you?$"

	.string "Hi, there! Hello!\n"
	.string "I’m {STR_VAR_1}, and I’m a SWIMMER!$"

	.string "Check out what I’ve been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, huh?\n"
	.string "It’d be sweet to form a team, too!$"

	.string "Much obliged!\n"
	.string "I’ll get this registration thing done!$"

	.string "If we meet again, you have to team up\n"
	.string "with me. You’ll do that, right?$"

