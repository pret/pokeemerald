#include "constants/apprentice.h"

.macro apprentice_msg waitbuttonpress which
setvar VAR_0x8004, 8
setvar VAR_0x8005, \waitbuttonpress
setvar VAR_0x8006, \which
special CallApprenticeFunction
waitstate
.endm

.macro apprentice_buff whichstringvar tobuff
setvar VAR_0x8004, 16
setvar VAR_0x8005, \whichstringvar
setvar VAR_0x8006, \tobuff
special CallApprenticeFunction
.endm

.macro apprentice_menu which
setvar VAR_0x8004, 7
setvar VAR_0x8005, \which
special CallApprenticeFunction
waitstate
.endm

EventScript_Apprentice:: @ 82B688D
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq Script_Apprentice_FirstMeeting
	setvar VAR_0x8004, 10
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B68BE
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, Script_Apprentice_ReleaseAndEnd

BattleFrontier_BattleTowerLobby_EventScript_2B68BE:
	setvar VAR_0x8004, 11
	special CallApprenticeFunction
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B69D3
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ACF
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C77
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D5C
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6DD4
	release
	releaseall
	end

Script_Apprentice_FirstMeeting:
	apprentice_buff 0, APPRENTICE_BUFF_NAME
	apprentice_msg FALSE, 0

Script_Apprentice_FirstMeetingNag:
	apprentice_menu APPRENTICE_ASK_YES_NO
	compare VAR_RESULT, 1
	goto_if_eq Script_Apprentice_FirstMeetingAskAgain
	apprentice_msg FALSE, 2
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
	setvar VAR_0x8004, 1
	setorcopyvar VAR_0x8005, VAR_RESULT
	addvar VAR_0x8005, 1
	special CallApprenticeFunction
	setvar VAR_0x8004, 3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_LEVEL
	apprentice_msg TRUE, 3
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

Script_Apprentice_FirstMeetingAskAgain:
	apprentice_msg FALSE, 1
	goto Script_Apprentice_FirstMeetingNag

BattleFrontier_BattleTowerLobby_EventScript_2B69D3:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 2
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES1
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES2
	apprentice_msg FALSE, 6
	apprentice_menu APPRENTICE_ASK_2SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ABA
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC0
	setvar VAR_0x8004, 12
	special CallApprenticeFunction
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 13
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	setvar VAR_0x8004, 12
	special CallApprenticeFunction
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6AC6
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	apprentice_msg TRUE, 7
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6ABA:
	setvar VAR_0x8007, 0
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC0:
	setvar VAR_0x8007, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC6:
	setvar VAR_0x8004, 4
	special CallApprenticeFunction
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6ACF:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg TRUE, 10
	setvar VAR_0x8004, 15
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_2B6B09:
	fadescreen 1
	setvar VAR_RESULT, 0
	setvar VAR_0x8004, 19
	special CallApprenticeFunction
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B81
	setvar VAR_0x8004, 20
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C0C
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_msg TRUE, 12
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6B81:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 13
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09

BattleFrontier_BattleTowerLobby_EventScript_2B6BD4:
	apprentice_msg TRUE, 14
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C0C:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES3
	apprentice_msg FALSE, 16
	apprentice_menu APPRENTICE_ASK_GIVE
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6BD4
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C77:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 3
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
	apprentice_buff 1, APPRENTICE_BUFF_MOVE1
	apprentice_buff 2, APPRENTICE_BUFF_MOVE2
	apprentice_msg FALSE, 8
	apprentice_menu APPRENTICE_ASK_MOVES
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D50
	compare VAR_0x8005, 1
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D56
	setvar VAR_0x8004, 17
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special CallApprenticeFunction
	setvar VAR_0x8004, 15
	special CallApprenticeFunction
	apprentice_msg TRUE, 9
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6D50:
	setvar VAR_0x8007, 3
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D56:
	setvar VAR_0x8007, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D5C:
	apprentice_msg FALSE, 4
	apprentice_menu APPRENTICE_ASK_3SPECIES
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, 18
	special CallApprenticeFunction
	setvar VAR_0x8004, 5
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES4
	apprentice_msg TRUE, 5
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6DD4:
	apprentice_msg TRUE, 11
	setvar VAR_0x8004, 25
	special CallApprenticeFunction
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	setvar VAR_0x8004, 21
	special CallApprenticeFunction
	apprentice_buff 0, APPRENTICE_BUFF_EASY_CHAT
	apprentice_msg TRUE, 15
	setvar VAR_0x8004, 9
	special CallApprenticeFunction
	call Script_Apprentice_SetLeavingFlags
	release
	releaseall
	switch VAR_FACING
	case 2, Script_Apprentice_LeaveGoRight
	goto Script_Apprentice_Leave
	end

Script_Apprentice_SetLeavingFlags:
	setflag FLAG_HIDE_APPRENTICE
	setflag FLAG_DAILY_APPRENTICE_LEAVES
	return

Script_Apprentice_LeaveGoRight:
	setvar VAR_0x8004, 24
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq Script_Apprentice_End
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E94
	waitmovement 0
	end

Script_Apprentice_Leave:
	setvar VAR_0x8004, 24
	special CallApprenticeFunction
	compare VAR_0x8004, 0
	goto_if_eq Script_Apprentice_End
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E95
	waitmovement 0
	end

Script_Apprentice_ReleaseAndEnd:
	release
	releaseall
	end

Script_Apprentice_End:
	end

BattleFrontier_BattleTowerLobby_Movement_2B6E94: @ 82B6E94
	walk_fast_right

BattleFrontier_BattleTowerLobby_Movement_2B6E95: @ 82B6E95
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	slide_down
	slide_down
	slide_down
	step_end

gText_082B6EA5:: @ 82B6EA5
	.string "Um, I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Snivel… This tension is getting to me…$"

gText_082B6EEC:: @ 82B6EEC
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!\n"
	.string "Here we come!$"

gText_082B6F16:: @ 82B6F16
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}!\n"
	.string "Accept my challenge!$"

gText_082B6F4C:: @ 82B6F4C
	.string "Um… I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…\n"
	.string "Do you think someone like me can win?$"

gText_082B6F92:: @ 82B6F92
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!\n"
	.string "I'll let you challenge me!$"

gText_082B6FC9:: @ 82B6FC9
	.string "I'm horribly busy, but I also happen\n"
	.string "to be {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"

gText_082B700C:: @ 82B700C
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Glad to meet you!$"

gText_082B703A:: @ 82B703A
	.string "I serve as {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "May I begin?$"

gText_082B706A:: @ 82B706A
	.string "Eek! I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!\n"
	.string "I'll do my best!$"

gText_082B709C:: @ 82B709C
	.string "Yeehaw! I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!\n"
	.string "Put 'em up!$"

gText_082B70CC:: @ 82B70CC
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\n"
	.string "Actually, I'm no. {STR_VAR_2}! Here goes!$"

gText_082B710A:: @ 82B710A
	.string "Yeah, I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!\n"
	.string "Let's get rockin' and a-rollin'!$"

gText_082B714D:: @ 82B714D
	.string "Yippee-yahoo! I'm what you call\n"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

gText_082B7185:: @ 82B7185
	.string "Cough! I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Good to meet you! Cough!$"

gText_082B71C1:: @ 82B71C1
	.string "This is nerve-racking…\n"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

gText_082B71F9:: @ 82B71F9
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice,\n"
	.string "and that's no lie.$"

gText_082B7229:: @ 82B7229
	.string "Are you… {PLAYER}?\n"
	.string "Oh! Sniff…sob…\p"
	.string "Oh! S-sorry…\n"
	.string "I'm so nervous, I can't help crying…\p"
	.string "I'm {STR_VAR_1}, and I really look up\n"
	.string "to you, {PLAYER}.\p"
	.string "I… I had this dream of one day meeting\n"
	.string "you and asking you about POKéMON.\p"
	.string "Please, please, {PLAYER}!\n"
	.string "Please teach me about POKéMON!$"

gText_082B731C:: @ 82B731C
	.string "Oh… B-but…\n"
	.string "Snivel… Waaaaaaah!\p"
	.string "Please!\n"
	.string "I'm begging you, please!$"

gText_082B735B:: @ 82B735B
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "Um… Then please tell me!\n"
	.string "It's about the BATTLE TOWER.\p"
	.string "Which would be better for me: Level 50\n"
	.string "or the Open Level?$"

gText_082B7423:: @ 82B7423
	.string "{STR_VAR_1}?\n"
	.string "Waaaaah!\p"
	.string "Oh! I'm so sorry!\n"
	.string "You've made me happy by choosing\l"
	.string "the level for me, and it's made me cry…\p"
	.string "Snivel…\n"
	.string "Thank you so much!\l"
	.string "Please talk with me again!$"

gText_082B74C1:: @ 82B74C1
	.string "Wowee! You're {PLAYER}, aren't you?\n"
	.string "You're awesomely strong, aren't you?\p"
	.string "I'm {STR_VAR_1}!\n"
	.string "I just became a TRAINER!\p"
	.string "Please, {PLAYER}!\n"
	.string "Can you be my teacher and tell me\l"
	.string "lots about being a TRAINER?$"

gText_082B756F:: @ 82B756F
	.string "Aww, why?\n"
	.string "Oh, please? Pretty please?\l"
	.string "Please be my teacher, please!$"

gText_082B75B2:: @ 82B75B2
	.string "Yay! Great!\p"
	.string "The first thing I wanted to ask you is\n"
	.string "about the BATTLE TOWER!\p"
	.string "The Level 50 and Open Level Rooms…\n"
	.string "Which would be perfect for me?$"

gText_082B763F:: @ 82B763F
	.string "{STR_VAR_1}, huh? That's true!\n"
	.string "I'll do my best there!\p"
	.string "If we meet here again, please teach\n"
	.string "me something else, teacher!$"

gText_082B76AC:: @ 82B76AC
	.string "Um… Are you {PLAYER}?\n"
	.string "My name is {STR_VAR_1}.\p"
	.string "I want to become a POKéMON TRAINER,\n"
	.string "but I don't know what to do…\p"
	.string "So I thought maybe I could ask you for\n"
	.string "advice because you're so famous.\p"
	.string "{PLAYER}, could you give me advice?$"

gText_082B7772:: @ 82B7772
	.string "Oh, but…\p"
	.string "I sincerely want to become a POKéMON\n"
	.string "TRAINER!\p"
	.string "Please, can you answer my questions?$"

gText_082B77CE:: @ 82B77CE
	.string "Thank you!\n"
	.string "Here's my first question right away!\p"
	.string "The BATTLE TOWER has two levels,\n"
	.string "Level 50 and Open Level, right?\p"
	.string "Which level do you think is more\n"
	.string "suitable for me?$"

gText_082B7871:: @ 82B7871
	.string "Oh, the {STR_VAR_1} challenge?\n"
	.string "Understood!\p"
	.string "If I have another question, I'll come\n"
	.string "back here for your advice!$"

gText_082B78D4:: @ 82B78D4
	.string "Oh? Huh? You're…\n"
	.string "No, that can't be true.\p"
	.string "There isn't any way that someone\n"
	.string "like me could meet {PLAYER}.\p"
	.string "…You really are {PLAYER}?\n"
	.string "I can't believe I'm talking to you!\p"
	.string "When something this good happens,\n"
	.string "only terrible things will happen to me\l"
	.string "now, I just know it…\p"
	.string "…I'm sorry…\n"
	.string "I'm… {STR_VAR_1}…\p"
	.string "There isn't anything special about\n"
	.string "me that I can be proud of…\p"
	.string "I shouldn't even say anything about\n"
	.string "myself because you'll forget…\p"
	.string "I had this dream that if I ever met\n"
	.string "you, {PLAYER}, that maybe I could ask\l"
	.string "you for advice as a TRAINER.\p"
	.string "But I don't think you would agree\n"
	.string "to that.\p"
	.string "…Or will you be so kind as to give\n"
	.string "me advice?$"

gText_082B7B1A:: @ 82B7B1A
	.string "I knew it…\p"
	.string "It had to happen because I'm such\n"
	.string "a really boring nobody…\p"
	.string "But I thought just maybe…\n"
	.string "You won't reconsider, will you?\p"
	.string "But I can't give up just like that.\n"
	.string "I'll ask you while I'm still lucky!\p"
	.string "Please, will you be so kind as to give\n"
	.string "me advice?$"

gText_082B7C13:: @ 82B7C13
	.string "Really? I can't believe it!\n"
	.string "I can't believe you'll advise me!\l"
	.string "I… I'm so happy…\p"
	.string "What I want to ask you is really\n"
	.string "trivial, but I can't decide…\p"
	.string "At the BATTLE TOWER, they let you\n"
	.string "choose Level 50 or Open Level.\p"
	.string "Which course do you think even I may\n"
	.string "have a chance at?$"

gText_082B7D18:: @ 82B7D18
	.string "{STR_VAR_1}? Okay!\n"
	.string "But do you really think someone like\l"
	.string "me would have a chance?\p"
	.string "I'll do my best, even though I don't\n"
	.string "think it will work.\p"
	.string "Thank you very much for spending\n"
	.string "time with someone like me.$"

gText_082B7DD4:: @ 82B7DD4
	.string "Oh! You're {PLAYER}{STRING 5}, aren't you?\p"
	.string "I've heard that you're tough at\n"
	.string "POKéMON!\p"
	.string "I'm {STR_VAR_1}!\n"
	.string "I'll be your friend!\p"
	.string "Did you know?\p"
	.string "You can't win at the BATTLE FRONTIER\n"
	.string "if all you know is what they teach at\l"
	.string "the TRAINER'S SCHOOL.\p"
	.string "I'm willing to listen to your advice.\n"
	.string "You'll agree, of course?$"

gText_082B7EE5:: @ 82B7EE5
	.string "Huh? Why are you refusing me?\n"
	.string "It's me who's asking you!\l"
	.string "You have to reconsider!$"

gText_082B7F35:: @ 82B7F35
	.string "Okay, so there is this something.\n"
	.string "I want you to decide it for me.\p"
	.string "You know that the BATTLE TOWER has\n"
	.string "Level 50 and Open Level Rooms?\p"
	.string "Which do you think would be good\n"
	.string "for me, {PLAYER}{STRING 5}?$"

gText_082B7FE8:: @ 82B7FE8
	.string "Okay, {STR_VAR_1} is suitable for me?\n"
	.string "Thank you!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082B8087:: @ 82B8087
	.string "Oh, hi, there! {PLAYER}{STRING 5}!\n"
	.string "I know you because you're famous!\l"
	.string "Call me {STR_VAR_1}! Glad to meet you!\p"
	.string "I'm a TRIATHLETE, so I keep myself\n"
	.string "fit even while I raise POKéMON.\p"
	.string "I'm also involved with other things\n"
	.string "like work, napping, ballroom dancing…\p"
	.string "Being this busy, it's not so easy for\n"
	.string "me to become a decent TRAINER.\p"
	.string "So, I have a proposition!\p"
	.string "There must be a reason why we met.\n"
	.string "So, {PLAYER}{STRING 5}, how about sharing your\l"
	.string "wisdom with me every so often?$"

gText_082B822B:: @ 82B822B
	.string "Oh, but, please?\n"
	.string "A guy like me needs someone like\l"
	.string "you, {PLAYER}{STRING 5}!\p"
	.string "Honestly, I need your advice!$"

gText_082B8286:: @ 82B8286
	.string "Thank you! That's more like it!\n"
	.string "So, let's start with an easy one!\p"
	.string "You know about the BATTLE TOWER's\n"
	.string "two courses, right?\l"
	.string "You know, Level 50 and Open Level.\p"
	.string "Me being a busy guy, which one should\n"
	.string "I gear up for?$"

gText_082B8356:: @ 82B8356
	.string "{STR_VAR_1}, huh? Okay, gotcha.\n"
	.string "I'll find time somehow and give it a go!\p"
	.string "…Whoops, I'd better go to work!\n"
	.string "Thanks! See you around!$"

gText_082B83CE:: @ 82B83CE
	.string "No way! Uh-uh!\n"
	.string "Are you maybe the real {PLAYER}?\p"
	.string "A-hah! Awesome! I'm {STR_VAR_1},\n"
	.string "so pleased to meet you!\p"
	.string "{PLAYER}, you're very strong,\n"
	.string "aren't you?\p"
	.string "Everyone's talking about you!\p"
	.string "Oh! I just had this great idea!\n"
	.string "I'll get advice off you, {PLAYER}!\l"
	.string "I'm sure it will make me tougher!\p"
	.string "Isn't it a great idea?\n"
	.string "Please, I want your advice!$"

gText_082B84FC:: @ 82B84FC
	.string "Ahahaha, you can pretend to be mean,\n"
	.string "but you can't fool me!\l"
	.string "You really mean okay, don't you?$"

gText_082B8559:: @ 82B8559
	.string "Yay! I knew you'd have a big heart,\n"
	.string "{PLAYER}!\p"
	.string "What should I ask you first?\n"
	.string "…Oh, I thought of something!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I were to take a BATTLE TOWER\n"
	.string "challenge, which way should I go?\p"
	.string "Level 50 or Open Level?\n"
	.string "Which suits me more?$"

gText_082B8656:: @ 82B8656
	.string "Oh-oh-oh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thank you for a totally cool reply!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082B86EA:: @ 82B86EA
	.string "I beg your pardon, but…\n"
	.string "Are you {PLAYER}?\p"
	.string "I'm {STR_VAR_1}, and I am delighted to\n"
	.string "make your acquaintance.\p"
	.string "I have long been an admirer\n"
	.string "of yours…\p"
	.string "… … … … … …\p"
	.string "Um… I hope you don't find this\n"
	.string "request too much of a burden, but…\p"
	.string "May I become your apprentice,\n"
	.string "{PLAYER}?$"

gText_082B87DA:: @ 82B87DA
	.string "Oh…!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "…I must have fainted from shock.\n"
	.string "I'm sorry, I must have misheard you.\p"
	.string "Please! Please say that you will\n"
	.string "accept me as your apprentice!$"

gText_082B887C:: @ 82B887C
	.string "Oh… I'm delighted!\p"
	.string "I don't wish to waste your time,\n"
	.string "so please advise me on this.\p"
	.string "I plan to take a BATTLE TOWER\n"
	.string "challenge soon.\p"
	.string "However, there are two levels…\p"
	.string "Which would be most suitable for me?\n"
	.string "Level 50 or Open Level?$"

gText_082B8957:: @ 82B8957
	.string "{STR_VAR_1} is your choice!\n"
	.string "I see. I will do my best!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082B89C6:: @ 82B89C6
	.string "Eek! Eek! {PLAYER}!\n"
	.string "You spoke to me!\l"
	.string "I… I'm overjoyed!\p"
	.string "Me! My name is {STR_VAR_1}!\n"
	.string "I just became a TRAINER!\p"
	.string "I'm delighted I met you, {PLAYER},\n"
	.string "the big name in POKéMON circles!\p"
	.string "Oh-oh-oh, I know!\n"
	.string "May I ask a huge favor, {PLAYER}?\p"
	.string "Please take me in as your apprentice!\n"
	.string "I want to learn from you!$"

gText_082B8ACF:: @ 82B8ACF
	.string "Waaaah!\n"
	.string "{PLAYER} turned me down…\l"
	.string "It… It's an invaluable experience!\p"
	.string "{PLAYER}, please! I want to hear\n"
	.string "an affirmative answer this time!\p"
	.string "I beg you for your guidance!$"

gText_082B8B66:: @ 82B8B66
	.string "Hieeeeh! {PLAYER} said yes!\n"
	.string "{PLAYER} said yes!\p"
	.string "I won't be able to sleep tonight…\n"
	.string "Thank you ever so much!\p"
	.string "Then, here's my question!\p"
	.string "At the BATTLE TOWER, what is right\n"
	.string "for me, Level 50 or Open Level?$"

gText_082B8C20:: @ 82B8C20
	.string "{STR_VAR_1}! Perfectly understood!\n"
	.string "I understand perfectly!\l"
	.string "I'm deliriously delighted!\p"
	.string "I hope you'll be willing to teach me\n"
	.string "some more another time.$"

gText_082B8CAA:: @ 82B8CAA
	.string "Whoa! Could you be…\n"
	.string "Might you be… {PLAYER}{STRING 5}?!\l"
	.string "That strong and famous TRAINER?\l"
	.string "Well, hello, aren't I just the luckiest!\p"
	.string "Hello, the name's {STR_VAR_1}!\p"
	.string "I've been on the lookout for\n"
	.string "a POKéMON teacher.\p"
	.string "And with impeccably good timing,\n"
	.string "along came you, {PLAYER}{STRING 5}!\p"
	.string "So, there you have it, {PLAYER}{STRING 5}!\n"
	.string "Let me apprentice under you!$"

gText_082B8DD3:: @ 82B8DD3
	.string "Gwaaaah!\n"
	.string "You're quite cool and tough…\p"
	.string "Don't be that way, please.\n"
	.string "I'm asking you!$"

gText_082B8E24:: @ 82B8E24
	.string "Oh, yeah! That's a solid reply!\n"
	.string "Excellent, I might add!\p"
	.string "So how about a first piece of advice\n"
	.string "on the BATTLE TOWER?\p"
	.string "If I were to go, what would be better?\n"
	.string "Level 50 or Open Level?$"

gText_082B8ED5:: @ 82B8ED5
	.string "Uh-huh, {STR_VAR_1} it is!\n"
	.string "OK, A-OK!\l"
	.string "I'll go show my mettle, like, jam!\p"
	.string "All right, I'll look to you as my mentor!\n"
	.string "Adios!$"

gText_082B8F45:: @ 82B8F45
	.string "Oh, hey, {PLAYER}{STRING 5}, right?\n"
	.string "The police were looking for you!\p"
	.string "… … …\n"
	.string "Of course I'm lying!\p"
	.string "Me, I'm {STR_VAR_1}. Despite the way\n"
	.string "I look, I'm the POKéMON CHAMPION!\l"
	.string "…That's a lie, too!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at battling.\p"
	.string "So, how about you becoming my master\n"
	.string "about all things POKéMON?$"

gText_082B905F:: @ 82B905F
	.string "If you're going to act cold like that,\n"
	.string "I'll show you what I'll do!\p"
	.string "Waaah! Waaah! Waaah!\n"
	.string "Hiccup!\p"
	.string "Hahaha, that was my FAKE TEARS!\p"
	.string "Come on, will you please be\n"
	.string "my POKéMON master?$"

gText_082B910E:: @ 82B910E
	.string "Yippee!\n"
	.string "I'll buy you a boat for that!\p"
	.string "Of course I'm lying again!\n"
	.string "But… Thank you, master!\p"
	.string "You know how there's Level 50 and\n"
	.string "Open Level at the BATTLE TOWER?\p"
	.string "I'm having trouble deciding which\n"
	.string "level I should challenge…\p"
	.string "Can you decide for me, master?$"

gText_082B9204:: @ 82B9204
	.string "Okay, so {STR_VAR_1} is better!\n"
	.string "I'll go to the other level, then!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082B929C:: @ 82B929C
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy, and it means hi!\p"
	.string "I'm {STR_VAR_1}, the rappin' SAILOR\n"
	.string "am I!\p"
	.string "Your turn now, tell me a little about\n"
	.string "yourself, give it a try!\p"
	.string "Uh-huh, uh-huh!\n"
	.string "{PLAYER}{STRING 5}'s your name,\l"
	.string "and POKéMON's your game!\p"
	.string "And you're at a delicate age\n"
	.string "when all the world's your stage!\p"
	.string "Anyway, I just want to say,\n"
	.string "that you're the tenth TRAINER\l"
	.string "I've spoken to today.\p"
	.string "Let's make that a celebration!\n"
	.string "Become my mentor for commemoration!$"

gText_082B9438:: @ 82B9438
	.string "But!\n"
	.string "You have to work with me!\p"
	.string "Don't be such a tease!\n"
	.string "Become my mentor, please!$"

gText_082B9488:: @ 82B9488
	.string "That's it!\n"
	.string "{PLAYER}, you've got the spirit!\p"
	.string "So here's my first question\n"
	.string "that begs your suggestion!\p"
	.string "It's about the BATTLE TOWER,\n"
	.string "and it hinges on my power!\p"
	.string "Level 50 and Open Level there be,\n"
	.string "which is the one that's good for me?$"

gText_082B9564:: @ 82B9564
	.string "Okay, {STR_VAR_1} it is, you say!\n"
	.string "I'll go and take it on my way!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082B95D8:: @ 82B95D8
	.string "Say, hey, aren't you {PLAYER}?\n"
	.string "What should I do? Talk to you?\l"
	.string "Why not? I'm already talking to you!\p"
	.string "{PLAYER}, are you surprised at me?\n"
	.string "I'd better tell you who I happen to be!\p"
	.string "{STR_VAR_1} is what you can call me.\n"
	.string "The brightest star in guitardom,\l"
	.string "that's me!\p"
	.string "Are you receiving me?\n"
	.string "You are receiving me!\p"
	.string "My luck's at its best,\n"
	.string "I'll hit you with a request!\p"
	.string "{PLAYER}, let me be your underling!\n"
	.string "I want you to teach me everything!$"

gText_082B9763:: @ 82B9763
	.string "You're turning me down, then?\n"
	.string "I'll just have to ask you again!\p"
	.string "{PLAYER}, I beg to be your underling!\n"
	.string "I need you to teach me everything!$"

gText_082B97E5:: @ 82B97E5
	.string "Lucky, yeah, woohoo!\n"
	.string "Should I pop a question to you?\p"
	.string "Since we're near the BATTLE TOWER,\n"
	.string "how about a question about its power?\p"
	.string "Of the choices you see,\n"
	.string "which is the right one for me?$"

gText_082B989A:: @ 82B989A
	.string "If {STR_VAR_1} is what you suggest,\n"
	.string "it must be the very best!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082B992D:: @ 82B992D
	.string "Oh, hi! You there!\n"
	.string "Can I get you to massage my shoulder?\p"
	.string "…Yes, there! That's it!\n"
	.string "Ouch, ouch! Oooh, that feels great!\p"
	.string "My name's {STR_VAR_1}.\n"
	.string "I take karate training, but my body's\l"
	.string "not built to take the abuse…\p"
	.string "I decided I'll battle POKéMON and\n"
	.string "toughen myself up.\p"
	.string "You're {PLAYER}{STRING 5}, aren't you?\n"
	.string "The POKéMON LEAGUE CHAMP?\p"
	.string "Listen, can I get you to give me\n"
	.string "advice?$"

gText_082B9A84:: @ 82B9A84
	.string "Oh, why?\p"
	.string "I won't be a big bother, I promise!\n"
	.string "Please?$"

gText_082B9AB9:: @ 82B9AB9
	.string "Thank you. Mighty good of you!\n"
	.string "…Cough! Cough!\p"
	.string "Oogh, I have to toughen up quick…\p"
	.string "I'll be heading off to the BATTLE TOWER\n"
	.string "right away, but what would be better\l"
	.string "for me? Level 50 or Open Level?$"

gText_082B9B76:: @ 82B9B76
	.string "Hm, all right. That's {STR_VAR_1}.\n"
	.string "I'll go there right away.\p"
	.string "I hope I can keep hitting you up for\n"
	.string "help--after all, you're my mentor!$"

gText_082B9BF2:: @ 82B9BF2
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don't look at me that way.\n"
	.string "You're making me all self-conscious.\p"
	.string "I… I'm {STR_VAR_1}.\p"
	.string "I'm really embarrassed to say this,\n"
	.string "but I explore ancient ruins and such.\p"
	.string "I'm even more embarrassed to admit\n"
	.string "I'm interested in the BATTLE FRONTIER.\p"
	.string "{PLAYER}{STRING 5}, you have a reputation as\n"
	.string "a tough TRAINER…\p"
	.string "It's hard for me to say this,\n"
	.string "but I want to ask something.\p"
	.string "Could you become my teacher and\n"
	.string "give me advice?$"

gText_082B9D83:: @ 82B9D83
	.string "Please don't brush me off like this!\n"
	.string "I can't live with the humiliation.\p"
	.string "Please become my teacher!\n"
	.string "I need your advice!$"

gText_082B9DF9:: @ 82B9DF9
	.string "Th-thank you…\p"
	.string "But please don't look at me like that.\n"
	.string "It makes me all flustered.\p"
	.string "Please, answer me without looking\n"
	.string "at my eyes.\p"
	.string "At the BATTLE TOWER…\n"
	.string "Which level should I attempt?$"

gText_082B9EAA:: @ 82B9EAA
	.string "Oh… Okay!\n"
	.string "I'll try my hand at that.\p"
	.string "I hope I can make a valiant challenge\n"
	.string "without getting all flustered…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082B9F55:: @ 82B9F55
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "You may call me {STR_VAR_1}.\p"
	.string "I have been toying with the idea of\n"
	.string "apprenticing under a strong TRAINER.\p"
	.string "So, I must say I'm lucky you came along!\n"
	.string "…You really are {PLAYER}{STRING 5}, yes?\p"
	.string "No, no, if you are real, it's fine.\n"
	.string "I merely want you to recognize me\l"
	.string "as your apprentice.$"

gText_082BA084:: @ 82BA084
	.string "Oh?\n"
	.string "But what would compel you to refuse?\p"
	.string "I apologize for being skeptical about\n"
	.string "your identity.\p"
	.string "Please accept my apology and\n"
	.string "accept me as your apprentice.$"

gText_082BA11D:: @ 82BA11D
	.string "You really are accepting me?\n"
	.string "I don't wish to celebrate prematurely.\p"
	.string "If it is true, I apologize.\n"
	.string "But now, I need your advice.\p"
	.string "If I were to enter the BATTLE TOWER,\n"
	.string "what would be worthy of me?\l"
	.string "Level 50 or Open Level?$"

gText_082BA1F3:: @ 82BA1F3
	.string "{STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I realize I can annoy, but it delights\n"
	.string "me that you have accepted me.\p"
	.string "Let us meet again!$"

gText_082BA2A3:: @ 82BA2A3
	.string "Sigh… Sob…\n"
	.string "Oh, {PLAYER}!\p"
	.string "I'm all tangled up in a dilemma\n"
	.string "that I can't decide.\p"
	.string "I can't decide what I should make\n"
	.string "my {STR_VAR_1} hold.\p"
	.string "Please tell me, {PLAYER}.\n"
	.string "What item should I make it hold?$"

gText_082BA34E:: @ 82BA34E
	.string "Oh, really? I shouldn't make\n"
	.string "my {STR_VAR_1} hold anything?$"

gText_082BA380:: @ 82BA380
	.string "Oh, okay! I'm delighted it's settled!\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Thank you so much!$"

gText_082BA3D2:: @ 82BA3D2
	.string "Oh, I'm so glad…\n"
	.string "I think I have that {STR_VAR_1}, too.\p"
	.string "I'm delighted it's settled!\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Thank you so much!$"

gText_082BA448:: @ 82BA448
	.string "Waaaah! Please don't be mean!\p"
	.string "That item {STR_VAR_1} was already\n"
	.string "recommended to me before, sob…\p"
	.string "Or do you mean I shouldn't make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BA4D3:: @ 82BA4D3
	.string "Yay! It's {PLAYER}!\n"
	.string "Great! I wanted to ask you something!\p"
	.string "Do you make your POKéMON hold items?\n"
	.string "I want to make mine hold items, but…\p"
	.string "What item would be good for\n"
	.string "{STR_VAR_1} to hold?\p"
	.string "What do you think?$"

gText_082BA58C:: @ 82BA58C
	.string "Huh? You mean my {STR_VAR_1} doesn't\n"
	.string "have to hold anything?$"

gText_082BA5BF:: @ 82BA5BF
	.string "Oh, I get it! I'll do that!\n"
	.string "Thanks for teaching me!$"

gText_082BA5F3:: @ 82BA5F3
	.string "Oh, wow! One {STR_VAR_1}, huh?\n"
	.string "Okay, I'll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BA635:: @ 82BA635
	.string "Oh, uh, no, that's not what I meant.\n"
	.string "I want to know about a different item\l"
	.string "than the ones I already know.\p"
	.string "Or do you mean that my POKéMON doesn't\n"
	.string "have to hold anything this time?$"

gText_082BA6E6:: @ 82BA6E6
	.string "{PLAYER}, hello!\n"
	.string "It's about my {STR_VAR_1}…\p"
	.string "I want to make it hold a good item.\n"
	.string "What would be good for it?$"

gText_082BA742:: @ 82BA742
	.string "Oh, then my {STR_VAR_1} doesn't have\n"
	.string "to hold anything?$"

gText_082BA770:: @ 82BA770
	.string "Okay, I got it!\n"
	.string "See you again!$"

gText_082BA78F:: @ 82BA78F
	.string "Oh, the item {STR_VAR_1}?\n"
	.string "Understood!\p"
	.string "I'll do my best to find one!\n"
	.string "See you again!$"

gText_082BA7D8:: @ 82BA7D8
	.string "Somebody taught me about\n"
	.string "the {STR_VAR_1} already.\p"
	.string "I want my POKéMON to hold a different\n"
	.string "kind of item.\p"
	.string "Or do you think {STR_VAR_2} doesn't\n"
	.string "have to hold anything?$"

gText_082BA867:: @ 82BA867
	.string "Hello, {PLAYER}…\n"
	.string "I'm sorry to disturb you, but I have\l"
	.string "something else I wanted to ask you.\p"
	.string "I don't think I'm good enough to win\n"
	.string "matches on my own, so I'm thinking of\l"
	.string "making my {STR_VAR_1} hold an item.\p"
	.string "But I don't know what would be good.\p"
	.string "{PLAYER}, please, could you decide\n"
	.string "for me?$"

gText_082BA96B:: @ 82BA96B
	.string "A POKéMON belonging to someone like me\n"
	.string "would be better off without an item?$"

gText_082BA9B7:: @ 82BA9B7
	.string "I understand…\n"
	.string "You're saying I shouldn't rely on items.\l"
	.string "I'll do my best not to!\p"
	.string "Thank you very much!$"

gText_082BAA1B:: @ 82BAA1B
	.string "The item {STR_VAR_1}, okay.\n"
	.string "I'm not sure if I can get one…\l"
	.string "No! I'll do my best to get it.\p"
	.string "Thank you very much!$"

gText_082BAA81:: @ 82BAA81
	.string "Oh, but…\n"
	.string "I think I've heard about that before…\p"
	.string "Is it maybe because I haven't handled\n"
	.string "the item {STR_VAR_1} very well?\p"
	.string "Or do you mean I shouldn't make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BAB22:: @ 82BAB22
	.string "Oh, {PLAYER}{STRING 5}.\n"
	.string "There's something I wanted to ask you.\p"
	.string "You know how you decided which\n"
	.string "POKéMON I should have for me?\p"
	.string "But I never asked you what item\n"
	.string "it should be holding.\p"
	.string "Since you already gave me advice,\n"
	.string "how about seeing this to the end?\p"
	.string "What would be good? I want to make\n"
	.string "my {STR_VAR_1} hold something.$"

gText_082BAC43:: @ 82BAC43
	.string "Oh! So my {STR_VAR_1} should do\n"
	.string "the best it can empty-handed?$"

gText_082BAC78:: @ 82BAC78
	.string "If you think that's best, I'll do that.\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082BAD17:: @ 82BAD17
	.string "The item {STR_VAR_1}, huh?\n"
	.string "Not bad. I'll use it!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082BADB6:: @ 82BADB6
	.string "Huh? What are you saying?\n"
	.string "You told me about the {STR_VAR_1}\l"
	.string "already before.\p"
	.string "Or do you mean my {STR_VAR_2} should\n"
	.string "do the best it can empty-handed?$"

gText_082BAE36:: @ 82BAE36
	.string "Yo, {PLAYER}{STRING 5}!\p"
	.string "We're both busy, but we seem to run\n"
	.string "into each other often anyway!\p"
	.string "Today I have to do some walking,\n"
	.string "cleaning, and brushing.\p"
	.string "I haven't even had the time to buy\n"
	.string "my precious {STR_VAR_1} anything.\p"
	.string "I don't have any time, so how about\n"
	.string "giving me advice on what I should make\l"
	.string "my {STR_VAR_1} hold?$"

gText_082BAF4E:: @ 82BAF4E
	.string "Oh, so me being a busy guy, you say\n"
	.string "my {STR_VAR_1} doesn't need anything?$"

gText_082BAF8F:: @ 82BAF8F
	.string "Okay, gotcha.\n"
	.string "I won't need any time for that.\p"
	.string "Thanks today!\n"
	.string "See you around!$"

gText_082BAFDB:: @ 82BAFDB
	.string "Okay, gotcha.\n"
	.string "I'll find time somehow and find\l"
	.string "that {STR_VAR_1} you recommended.\p"
	.string "I'm glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082BB05F:: @ 82BB05F
	.string "Huh? I already know about\n"
	.string "that {STR_VAR_1}.\p"
	.string "Oh, right, I get it.\n"
	.string "So me being a busy guy, you say\l"
	.string "my {STR_VAR_2} doesn't need anything?$"

gText_082BB0D4:: @ 82BB0D4
	.string "Hiya, {PLAYER}! It's me!\n"
	.string "I need to tap your mind again today.\l"
	.string "Please, I need your advice!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I want to make my {STR_VAR_1} hold\n"
	.string "an item, what should it be?$"

gText_082BB18C:: @ 82BB18C
	.string "Is that right? My {STR_VAR_1} doesn't\n"
	.string "need to hold an item, you're saying.$"

gText_082BB1CE:: @ 82BB1CE
	.string "Okay, that's what I'll do!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082BB242:: @ 82BB242
	.string "Uh-huh! One {STR_VAR_1}.\n"
	.string "What a cool choice!\l"
	.string "I'll definitely try that!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082BB2D9:: @ 82BB2D9
	.string "Ahahah! That's silly!\n"
	.string "You already told me about that\l"
	.string "{STR_VAR_1} before!\p"
	.string "Are you feeling okay, {PLAYER}?\p"
	.string "Oh, wait! My {STR_VAR_2} doesn't\n"
	.string "need to hold an item, you're saying.$"

gText_082BB370:: @ 82BB370
	.string "Hello, {PLAYER}. I hope you've been\n"
	.string "keeping well.\p"
	.string "May I approach you for advice?\p"
	.string "In a recent battle, my opponent\n"
	.string "seemed to have given his POKéMON\l"
	.string "an item to hold.\p"
	.string "As a result, I was defeated…\p"
	.string "I don't wish to be left behind.\n"
	.string "I would like to make my {STR_VAR_1}\l"
	.string "hold an item, too.\p"
	.string "It would please me if you could decide\n"
	.string "what would be right for my POKéMON…$"

gText_082BB4C3:: @ 82BB4C3
	.string "In other words… My POKéMON has\n"
	.string "no need to hold an item?$"

gText_082BB4FB:: @ 82BB4FB
	.string "I understand clearly now!\n"
	.string "I will keep trying like this.\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BB575:: @ 82BB575
	.string "One {STR_VAR_1} it is!\n"
	.string "I will order it right away.\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BB5E1:: @ 82BB5E1
	.string "You've already told me about that,\n"
	.string "and I already have it.\p"
	.string "Or are you saying… My POKéMON has\n"
	.string "no need to hold an item?$"

gText_082BB656:: @ 82BB656
	.string "Eek! {PLAYER}!\n"
	.string "I… I'm overjoyed to see you again!\p"
	.string "Oh-oh-oh! There's something I just\n"
	.string "had to ask you, {PLAYER}!\p"
	.string "Please decide what my {STR_VAR_1}\n"
	.string "should be holding!$"

gText_082BB6E5:: @ 82BB6E5
	.string "Oh, wow! I didn't expect that answer!\n"
	.string "So, a hold item isn't necessary?$"

gText_082BB72C:: @ 82BB72C
	.string "Perfectly understood!\n"
	.string "I'll keep at this without an item!\p"
	.string "I hope you'll be willing to teach me\n"
	.string "some more another time.$"

gText_082BB7A2:: @ 82BB7A2
	.string "{STR_VAR_1}! I'll use that!\p"
	.string "Um… Could it be, {PLAYER}, you also\n"
	.string "make your POKéMON hold that item?\p"
	.string "I'll be sure to get it!\n"
	.string "I hope you'll be willing to teach me\l"
	.string "some more another time.$"

gText_082BB84A:: @ 82BB84A
	.string "Oh? You recommended that\n"
	.string "{STR_VAR_1} before, too.\p"
	.string "Or is it the best thing to hold?\n"
	.string "Or do you mean that my {STR_VAR_2}\l"
	.string "doesn't need anything to hold?$"

gText_082BB8CD:: @ 82BB8CD
	.string "Hola!\n"
	.string "My maestro, {PLAYER}{STRING 5}!\p"
	.string "I want to hit you up for advice on\n"
	.string "POKéMON tools.\p"
	.string "What do you think would be good for\n"
	.string "my {STR_VAR_1} to hold?\p"
	.string "Don't be shy now.\n"
	.string "Let's blurt it out!$"

gText_082BB970:: @ 82BB970
	.string "Oh? So, you're saying my {STR_VAR_1}\n"
	.string "can win without holding any item?$"

gText_082BB9AE:: @ 82BB9AE
	.string "Si, bueno!\n"
	.string "I'll give it my best shot, like, slam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BBA05:: @ 82BBA05
	.string "Uh-huh, that's one {STR_VAR_1}?\n"
	.string "Si, bueno!\l"
	.string "I'll go find me one, like, bam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BBA6C:: @ 82BBA6C
	.string "No, no! You already told me about\n"
	.string "that {STR_VAR_1} thing before.\p"
	.string "Oh, now wait just one minute here…\n"
	.string "So, you're saying my {STR_VAR_2}\l"
	.string "can win without holding any item?$"

gText_082BBB01:: @ 82BBB01
	.string "{PLAYER}{STRING 5}, something unbelievable\n"
	.string "has happened!\p"
	.string "I woke up this morning, and my POKéMON\n"
	.string "had 10 NUGGETS!\p"
	.string "Of course I'm lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at thinking about\l"
	.string "what items POKéMON should hold.\p"
	.string "So, how about deciding for me what\n"
	.string "my {STR_VAR_1} should hold, master?$"

gText_082BBC1C:: @ 82BBC1C
	.string "What's that mean?\n"
	.string "Don't make it hold anything?$"

gText_082BBC4B:: @ 82BBC4B
	.string "Okay, so it shouldn't hold anything.\n"
	.string "Then, I'd better get something for it!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082BBCF6:: @ 82BBCF6
	.string "Okay, so it's one {STR_VAR_1}!\n"
	.string "I'll make it hold anything but that!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082BBD90:: @ 82BBD90
	.string "Um, you told me about that before,\n"
	.string "didn't you?\p"
	.string "Isn't there something else?\p"
	.string "Or do you mean, don't make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BBE0B:: @ 82BBE0B
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin' SAILOR am I!\n"
	.string "I present to you a question\l"
	.string "that's pretty fly!\p"
	.string "It's an item question\n"
	.string "that begs your suggestion!\p"
	.string "My {STR_VAR_1} needs an item to hold,\n"
	.string "What should it be, if I may be bold?$"

gText_082BBEE5:: @ 82BBEE5
	.string "Is that right?\n"
	.string "My {STR_VAR_1} doesn't need to be\l"
	.string "holding anything tight?$"

gText_082BBF25:: @ 82BBF25
	.string "Okay, I hear you, sure I do!\n"
	.string "My POKéMON will go empty-handed, too!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082BBFA4:: @ 82BBFA4
	.string "Okay, one {STR_VAR_1},\n"
	.string "that's what I'll use.\l"
	.string "I was right to make you choose!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082BC024:: @ 82BC024
	.string "Okay, one {STR_VAR_1}, you say?\n"
	.string "You told me that the other day.\l"
	.string "I need a new idea, a brand new way.\p"
	.string "Or, what, is that right?\n"
	.string "My POKéMON doesn't need to hold\l"
	.string "anything tight?$"

gText_082BC0C8:: @ 82BC0C8
	.string "Say, hey, {PLAYER}!\n"
	.string "I found you again today!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I'm already talking to you!\p"
	.string "{PLAYER}, are you getting sick of me?\n"
	.string "Nah, no way, that can't be.\p"
	.string "Will you hear me out?\n"
	.string "I'm looking for advice--that's what\l"
	.string "I'm talking about.\p"
	.string "It's about a hold item for\n"
	.string "my {STR_VAR_1} that'd be good.\l"
	.string "My indecision is making me brood.$"

gText_082BC213:: @ 82BC213
	.string "My {STR_VAR_1} needs nothing?\n"
	.string "Doesn't need to hold anything?$"

gText_082BC247:: @ 82BC247
	.string "If holding nothing is the best,\n"
	.string "I'll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BC2DD:: @ 82BC2DD
	.string "If holding that {STR_VAR_1} is\n"
	.string "the best, I'll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BC373:: @ 82BC373
	.string "Haven't I heard about that\n"
	.string "{STR_VAR_1} before?\l"
	.string "I'm certain I have, that's for sure!\p"
	.string "I need a new something!\n"
	.string "Or, my {STR_VAR_2} needs nothing?\l"
	.string "Doesn't need to hold anything?$"

gText_082BC40E:: @ 82BC40E
	.string "Gwah! Ouch! {PLAYER}{STRING 5}, my arm's broken!\n"
	.string "Don't touch it, please!\p"
	.string "I must've broken it while I was trying\n"
	.string "out different hold items with my posse\l"
	.string "of POKéMON.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, what do you think would be\n"
	.string "good for my {STR_VAR_1} to hold?$"

gText_082BC514:: @ 82BC514
	.string "Ouch…\p"
	.string "So your suggestion is my {STR_VAR_1}\n"
	.string "doesn't have to hold anything?$"

gText_082BC555:: @ 82BC555
	.string "Hm, all right. That would be easier\n"
	.string "for me, the way things are now.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BC5CE:: @ 82BC5CE
	.string "Hm, all right. That's one {STR_VAR_1}.\n"
	.string "My POKéMON's arm is fine, so I'll make\l"
	.string "it hold that item right away.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BC666:: @ 82BC666
	.string "No, no, you told me about that\n"
	.string "{STR_VAR_1} before, remember?\p"
	.string "How about telling me something\n"
	.string "even better?\p"
	.string "Oh, wait a second.\n"
	.string "So your suggestion is my {STR_VAR_2}\l"
	.string "doesn't have to hold anything?$"

gText_082BC714:: @ 82BC714
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…\p"
	.string "Please, don't look at me that way.\n"
	.string "My POKéMON don't have anything.\p"
	.string "I… I'm really embarrassed about this,\n"
	.string "but I really need your advice.\p"
	.string "I can't decide what hold item would\n"
	.string "make my {STR_VAR_1} strong.\p"
	.string "{PLAYER}{STRING 5}, what do you think would\n"
	.string "be good?$"

gText_082BC808:: @ 82BC808
	.string "Oh… Then, you think it would be better\n"
	.string "if my {STR_VAR_1} didn't have an item?$"

gText_082BC84D:: @ 82BC84D
	.string "Oh… Okay!\n"
	.string "I'll go without an item.\p"
	.string "This is nerve-racking, though.\n"
	.string "Wouldn't it be too cool?\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BC8EA:: @ 82BC8EA
	.string "Oh… Okay!\n"
	.string "I'll go with that {STR_VAR_1}.\p"
	.string "This is nerve-racking, though.\n"
	.string "Wouldn't it be too cool?\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BC984:: @ 82BC984
	.string "B-but I already heard about that.\p"
	.string "Please don't brush me off like this!\n"
	.string "I can't live with the humiliation.\p"
	.string "Oh… Am I jumping to conclusions?\n"
	.string "Do you think it would be better if\l"
	.string "my {STR_VAR_2} didn't have an item?$"

gText_082BCA4D:: @ 82BCA4D
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps you're a twin?\p"
	.string "Oh, no, no, no, don't worry!\n"
	.string "If you really are {PLAYER}, please\l"
	.string "forget about my rudeness.\p"
	.string "What I would like is some more of\n"
	.string "your fine advice.\p"
	.string "I have here my {STR_VAR_1} that I wish\n"
	.string "to make hold a convenient item.\p"
	.string "What would be worthy of it?$"

gText_082BCB75:: @ 82BCB75
	.string "It's better if it held nothing?\n"
	.string "Are you certain?$"

gText_082BCBA6:: @ 82BCBA6
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "Let us meet again!$"

gText_082BCBFC:: @ 82BCBFC
	.string "One {STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope my POKéMON will be able to\n"
	.string "put it to good use.\p"
	.string "Let us meet again!$"

gText_082BCCA4:: @ 82BCCA4
	.string "No, no, wait a minute.\n"
	.string "I believe you taught me that before.\p"
	.string "I would like you to recommend\n"
	.string "something different this time.\p"
	.string "Perhaps you're suggesting that\n"
	.string "my {STR_VAR_2} should hold nothing?\l"
	.string "Are you certain?$"

gText_082BCD68:: @ 82BCD68
	.string "Waah, {PLAYER}!\n"
	.string "I have a dilemma, sob…\p"
	.string "I want to begin battling other people,\n"
	.string "but I don't know what to do.\p"
	.string "How should I line up my POKéMON\n"
	.string "so they'll be at their strongest?\p"
	.string "Please tell me, {PLAYER}.\n"
	.string "If you were me, which of these POKéMON\l"
	.string "would you send out first?$"

gText_082BCE64:: @ 82BCE64
	.string "My {STR_VAR_1} should go first?\n"
	.string "Waaaaah!\p"
	.string "Oh! I'm so sorry!\n"
	.string "You've made me happy by choosing\l"
	.string "my first POKéMON, and it's made me cry…\p"
	.string "Thank you so much!$"

gText_082BCEF2:: @ 82BCEF2
	.string "Yay! It's {PLAYER}!\n"
	.string "Great! I wanted to ask you something!\p"
	.string "Um, of my POKéMON, which do you\n"
	.string "think should go out first?$"

gText_082BCF61:: @ 82BCF61
	.string "My {STR_VAR_1}? That's true.\n"
	.string "Okay, I'll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BCFA1:: @ 82BCFA1
	.string "{PLAYER}, hello!\p"
	.string "I think, in a battle, it's very important\n"
	.string "which POKéMON comes out first.\p"
	.string "Out of the POKéMON that I have,\n"
	.string "which would be good to send out first?$"

gText_082BD03C:: @ 82BD03C
	.string "My {STR_VAR_1} goes first?\n"
	.string "Okay, I got it!\p"
	.string "See you again!$"

gText_082BD06D:: @ 82BD06D
	.string "Hello, {PLAYER}…\n"
	.string "I'm sorry to disturb you again with\l"
	.string "another question.\p"
	.string "I have so little confidence, I don't\n"
	.string "know what I'd do without you, {PLAYER}.\p"
	.string "It may be a waste of time for me to\n"
	.string "even worry about it, but I just can't\l"
	.string "decide something…\p"
	.string "Which of my POKéMON should I send\n"
	.string "out first in a battle?$"

gText_082BD18A:: @ 82BD18A
	.string "My {STR_VAR_1}?\n"
	.string "Understood!\p"
	.string "I can't believe that you would bother\n"
	.string "to answer my questions so often!\p"
	.string "I'm so grateful that you would even\n"
	.string "speak with me… Thank you!$"

gText_082BD222:: @ 82BD222
	.string "Oh, {PLAYER}{STRING 5}! It's me!\n"
	.string "I'm so glad to see you because I have\l"
	.string "this little problem.\p"
	.string "I can't decide how my POKéMON should\n"
	.string "be lined up. Could you decide for me?\p"
	.string "Oh, you don't need to decide the whole\n"
	.string "party right now.\p"
	.string "How about deciding just the first\n"
	.string "POKéMON for me?$"

gText_082BD325:: @ 82BD325
	.string "My {STR_VAR_1}? That's great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082BD3B1:: @ 82BD3B1
	.string "Hi, my teacher {PLAYER}{STRING 5}!\n"
	.string "I'm busy again today!\p"
	.string "I have to do some cycling, shopping,\n"
	.string "and humming.\p"
	.string "I haven't even had the time to decide\n"
	.string "how to line up my POKéMON team.\p"
	.string "So, how about checking out my team?\n"
	.string "Which one should go first?$"

gText_082BD493:: @ 82BD493
	.string "Okay, gotcha.\n"
	.string "I have enough time at least to put\l"
	.string "my {STR_VAR_1} at the head of the line!\p"
	.string "Whoops, my girlfriend's waiting!\n"
	.string "Thanks! See you around!$"

gText_082BD51C:: @ 82BD51C
	.string "Yoohoo! Hiya, {PLAYER}!\n"
	.string "You always walk around looking tough!\p"
	.string "Listen, I need something from you\n"
	.string "again! It's the usual thing!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is about my team.\p"
	.string "Which POKéMON of mine should be first\n"
	.string "to go out in a battle?$"

gText_082BD609:: @ 82BD609
	.string "Hmhm!\n"
	.string "My {STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082BD697:: @ 82BD697
	.string "Thank you so much for stopping to\n"
	.string "chat with me, {PLAYER}.\p"
	.string "I know I'm taking advantage of your\n"
	.string "kindness, but may I ask for advice?\p"
	.string "I would like you to decide on the order\n"
	.string "of my POKéMON team.\p"
	.string "It would please me if you could decide\n"
	.string "which POKéMON should come first.$"

gText_082BD797:: @ 82BD797
	.string "My {STR_VAR_1} it is!\n"
	.string "I will put it first right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BD806:: @ 82BD806
	.string "Eek! {PLAYER}!\n"
	.string "I… I'm overjoyed to see you again!\p"
	.string "My POKéMON have become much\n"
	.string "stronger!\p"
	.string "But I don't always win. It seems to\n"
	.string "depend on which POKéMON goes first.\p"
	.string "{PLAYER}, please, I need your help!\p"
	.string "Please decide which of my POKéMON\n"
	.string "should go out first!$"

gText_082BD8F5:: @ 82BD8F5
	.string "Sigh… I'm overwhelmed with happiness…\p"
	.string "It's like a dream having you decide\n"
	.string "for me, {PLAYER}.\p"
	.string "But perfectly understood!\n"
	.string "I will go with my {STR_VAR_1} first!\p"
	.string "I hope you'll be willing to teach me\n"
	.string "some more another time.$"

gText_082BD9BE:: @ 82BD9BE
	.string "Hello, hello!\n"
	.string "My mentor, {PLAYER}{STRING 5}!\l"
	.string "Hit me with your sage advice today!\p"
	.string "You see, I pulled together a team of\n"
	.string "three POKéMON. So far so good.\p"
	.string "But the team's battling order's not\n"
	.string "settled yet.\p"
	.string "This is where you come in, {PLAYER}{STRING 5}!\n"
	.string "You decide which POKéMON leads off!\p"
	.string "Don't be shy now.\n"
	.string "Let's blurt it out!$"

gText_082BDAE1:: @ 82BDAE1
	.string "Uh-huh, my {STR_VAR_1} leads off!\n"
	.string "OK, A-OK!\l"
	.string "I'll reorder the lineup, like, wham!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BDB4E:: @ 82BDB4E
	.string "{PLAYER}{STRING 5}, listen!\n"
	.string "It's a crisis!\p"
	.string "My POKéMON, all three of them, go into\n"
	.string "battle at once!\p"
	.string "Of course that's impossible!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at thinking about\l"
	.string "how I should line up my POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "POKéMON should go first, master?$"

gText_082BDC6B:: @ 82BDC6B
	.string "Okay, so it's my {STR_VAR_1} you chose?\n"
	.string "I'll let any but that one go first!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082BDD0D:: @ 82BDD0D
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin' SAILOR am I!\n"
	.string "I present to you a question\l"
	.string "that's pretty fly!\p"
	.string "It's a team lineup question\n"
	.string "that begs your suggestion!\p"
	.string "Out of this lot, which should go first\n"
	.string "as the first on the spot?$"

gText_082BDDEC:: @ 82BDDEC
	.string "Okay, I hear you, sure I do!\n"
	.string "I'll switch them up, that I'll do!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082BDE68:: @ 82BDE68
	.string "Yahoo, {PLAYER}!\n"
	.string "How do you do?\p"
	.string "What should I do? Go ahead and ask?\n"
	.string "Uh-huh, I have something to ask!\l"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\p"
	.string "You have to decide, which of my\n"
	.string "POKéMON is the first to ride!\l"
	.string "Into battle, I mean to say.$"

gText_082BDF4D:: @ 82BDF4D
	.string "My {STR_VAR_1}? Yes!\n"
	.string "That'll do, there's no distress!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BDFD8:: @ 82BDFD8
	.string "…Oof…ooch… {PLAYER}{STRING 5}…\n"
	.string "My stomach's hurting all of a sudden…\p"
	.string "…It's getting better now…\p"
	.string "I must've worried myself sick racking\n"
	.string "my brains on how I should line up\l"
	.string "my posse of POKéMON.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, which of my POKéMON should\n"
	.string "go first? So I'd win, I mean.$"

gText_082BE0FD:: @ 82BE0FD
	.string "Hm, all right.\n"
	.string "My {STR_VAR_1} goes first.\p"
	.string "I'll fix the lineup like that after\n"
	.string "I have my supper.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BE189:: @ 82BE189
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}?\p"
	.string "Please, don't look at me that way.\n"
	.string "You're making me feel all flustered.\p"
	.string "Um…\n"
	.string "I really need your advice.\p"
	.string "It makes me bashful to say this,\n"
	.string "but I chose my 3-POKéMON team.\l"
	.string "I can't decide on the order, though.\p"
	.string "Which POKéMON should I send out first\n"
	.string "so I at least look capable?$"

gText_082BE2A5:: @ 82BE2A5
	.string "Oh… Okay!\n"
	.string "I'll lead with my {STR_VAR_1}.\p"
	.string "I hope I can do my best without\n"
	.string "getting all flustered.\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BE33E:: @ 82BE33E
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps you're a clever look-alike?\p"
	.string "Oh, no, no, no, don't worry!\n"
	.string "If you really are {PLAYER}, please\l"
	.string "forget about my rudeness.\p"
	.string "What I would like is your fine advice.\p"
	.string "I have here my POKéMON team.\n"
	.string "I would like you to tell me which one\l"
	.string "should go first in a battle.$"

gText_082BE46C:: @ 82BE46C
	.string "My {STR_VAR_1}…\n"
	.string "You aren't pulling my leg?\p"
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I am as you see, but I shall do\n"
	.string "my best.\p"
	.string "Let us meet again!$"

gText_082BE50D:: @ 82BE50D
	.string "Snivel…\n"
	.string "Oh, {PLAYER}!\p"
	.string "What perfect timing!\n"
	.string "There's something I just can't decide…\p"
	.string "I can't decide which POKéMON I should\n"
	.string "be using.\p"
	.string "I can't decide between the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}…\p"
	.string "{PLAYER}, which do you think will give\n"
	.string "even me a chance at winning?$"

gText_082BE5F5:: @ 82BE5F5
	.string "Snivel… I… I understand!\n"
	.string "Oh! I'm so sorry!\l"
	.string "You've made me so happy, I'm crying…\p"
	.string "I'll do my best to catch one\n"
	.string "{STR_VAR_1}!\p"
	.string "Thank you so much!$"

gText_082BE679:: @ 82BE679
	.string "Yay! It's {PLAYER}!\n"
	.string "Yay, you came at the right time, too!\l"
	.string "I need your advice again!\p"
	.string "Um, I'm all mixed up--should I use\n"
	.string "my {STR_VAR_1} or {STR_VAR_2}…\p"
	.string "Which do you think I should raise,\n"
	.string "{PLAYER}?$"

gText_082BE71E:: @ 82BE71E
	.string "Oh, so my {STR_VAR_1} is better!\n"
	.string "Okay, I'll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BE762:: @ 82BE762
	.string "{PLAYER}, hello!\n"
	.string "I have a question I wanted to ask.\p"
	.string "I'm in a dilemma over whether I should\n"
	.string "raise one {STR_VAR_1} or {STR_VAR_2}.\p"
	.string "Which POKéMON do you think will\n"
	.string "be stronger?$"

gText_082BE7F8:: @ 82BE7F8
	.string "{STR_VAR_1} is your choice?\n"
	.string "Okay, I got it!\p"
	.string "I'll go catch a strong {STR_VAR_1}\n"
	.string "right away!\p"
	.string "See you again!$"

gText_082BE850:: @ 82BE850
	.string "Hello, {PLAYER}…\p"
	.string "Um, you've probably already forgotten\n"
	.string "about someone like me…\p"
	.string "…But that doesn't matter if you\n"
	.string "could give me advice…\p"
	.string "I can't decide on the one kind of\n"
	.string "POKéMON I should raise…\p"
	.string "I've narrowed the field to the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, but that's\l"
	.string "where I became stuck…\p"
	.string "{PLAYER}, you probably don't want to\n"
	.string "bother, but please decide for me.$"

gText_082BE99C:: @ 82BE99C
	.string "But will a wild {STR_VAR_1} even pay\n"
	.string "attention to me?\p"
	.string "I will try!\p"
	.string "But will I even be able to catch one…\n"
	.string "No! I'll do my best!\p"
	.string "Thank you!$"

gText_082BEA1B:: @ 82BEA1B
	.string "Oh, {PLAYER}{STRING 5}! I'm so glad to see you!\n"
	.string "I was about to go looking for you!\p"
	.string "Can you decide what kind of POKéMON\n"
	.string "I should use?\p"
	.string "For instance…\n"
	.string "How about the POKéMON {STR_VAR_1}\l"
	.string "and {STR_VAR_2}?\p"
	.string "Which one do you think would be\n"
	.string "better?$"

gText_082BEAE9:: @ 82BEAE9
	.string "{STR_VAR_1}? That's great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082BEB72:: @ 82BEB72
	.string "If it isn't {PLAYER}{STRING 5}! How's it going?\n"
	.string "I'm busy again as always!\p"
	.string "I want to do good with POKéMON, too,\n"
	.string "but I haven't been able to decide\l"
	.string "which POKéMON I should use.\p"
	.string "You know how {STR_VAR_1} look strong?\n"
	.string "But {STR_VAR_2} are tough to ignore.\p"
	.string "{PLAYER}{STRING 5}, give me some of your good\n"
	.string "advice! Which one'd be good for me?$"

gText_082BEC8E:: @ 82BEC8E
	.string "Okay, gotcha.\n"
	.string "I'll find time somehow and catch me\l"
	.string "that {STR_VAR_1} you recommended.\p"
	.string "I'm glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082BED16:: @ 82BED16
	.string "Oh!\n"
	.string "Yay, it's {PLAYER}!\p"
	.string "I didn't waste any time boasting to\n"
	.string "my friends about meeting you!\p"
	.string "I need to tap your mind again today.\n"
	.string "It's an easy one for you!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I were to raise a POKéMON,\n"
	.string "and the choices were one {STR_VAR_1}\l"
	.string "or {STR_VAR_2}, which should it be?$"

gText_082BEE29:: @ 82BEE29
	.string "Ahhh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082BEEB4:: @ 82BEEB4
	.string "Oh, is it you, {PLAYER}?\n"
	.string "I'm delighted to see you again!\p"
	.string "Ever since I became your apprentice,\n"
	.string "my confidence has been blooming.\p"
	.string "I think I'm ready to raise a POKéMON\n"
	.string "of my own!\p"
	.string "{PLAYER}, may I impose on you to choose\n"
	.string "which POKéMON I should raise?\p"
	.string "The choices are the POKéMON\n"
	.string "{STR_VAR_1} or {STR_VAR_2}…\l"
	.string "Which POKéMON is right for me?$"

gText_082BEFE2:: @ 82BEFE2
	.string "One {STR_VAR_1} it is!\n"
	.string "I will find one right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BF04E:: @ 82BF04E
	.string "Eek! {PLAYER}! I met you again!\n"
	.string "I… I'm overjoyed!\p"
	.string "Oh-oh-oh, I know!\n"
	.string "I shouldn't pass up this opportunity!\p"
	.string "May I ask a huge favor, {PLAYER}?\n"
	.string "Please choose a POKéMON for me!\p"
	.string "Please decide which would be better,\n"
	.string "{STR_VAR_1} or {STR_VAR_2}!$"

gText_082BF11D:: @ 82BF11D
	.string "Wow! You decided for me!\n"
	.string "One {STR_VAR_1} is what I'll raise to\l"
	.string "the best of my ability.\p"
	.string "I hope you'll be willing to teach me\n"
	.string "some more another time.$"

gText_082BF1A8:: @ 82BF1A8
	.string "Hey, hey!\n"
	.string "My mentor, {PLAYER}{STRING 5}!\p"
	.string "Hello, I've been looking for you\n"
	.string "for some more of your sage advice!\p"
	.string "Which kind of POKéMON would be right\n"
	.string "for me, one {STR_VAR_1} or {STR_VAR_2}?\p"
	.string "Don't be shy now.\n"
	.string "Let's blurt it out!$"

gText_082BF268:: @ 82BF268
	.string "Uh-huh, one {STR_VAR_1} it is!\n"
	.string "OK, A-OK!\l"
	.string "I'll get one in a BALL, like, cram!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BF2D1:: @ 82BF2D1
	.string "{PLAYER}{STRING 5}, listen! Big news!\n"
	.string "I caught a mirage POKéMON!\p"
	.string "Of course I'm lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at catching\l"
	.string "POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "kind of POKéMON I should catch,\l"
	.string "master?\p"
	.string "Which would be better?\n"
	.string "{STR_VAR_1} or {STR_VAR_2}?$"

gText_082BF3CF:: @ 82BF3CF
	.string "Okay, so it's {STR_VAR_1} you chose?\n"
	.string "I'll grab the other kind, then!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082BF46A:: @ 82BF46A
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin' SAILOR am I!\n"
	.string "Surely you remember who am I?\p"
	.string "Today, I have a POKéMON question\n"
	.string "that begs your suggestion!\p"
	.string "I have the choice between this\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, you see.\l"
	.string "Which is the one to catch for me?$"

gText_082BF551:: @ 82BF551
	.string "{STR_VAR_1}, you say, hey, hey!\n"
	.string "I'll go get me one right away!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082BF5C3:: @ 82BF5C3
	.string "Oh, wow, if it isn't {PLAYER}!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I'm already talking to you!\p"
	.string "It's been a long time. Let me break\n"
	.string "the ice. I'm also looking for advice!\l"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\p"
	.string "My POKéMON--which should I use?\n"
	.string "It's either {STR_VAR_1} or {STR_VAR_2}.\l"
	.string "Which do you choose?$"

gText_082BF6E5:: @ 82BF6E5
	.string "If that {STR_VAR_1} is the best,\n"
	.string "I'll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BF773:: @ 82BF773
	.string "Oh, hi, {PLAYER}{STRING 5}…\n"
	.string "I have this horrible headache…\p"
	.string "I must've worried too much about\n"
	.string "the kind of POKéMON I should raise.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, if I had to choose between\n"
	.string "the POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}, which should it be?$"

gText_082BF869:: @ 82BF869
	.string "Hm, one {STR_VAR_1}, all right.\n"
	.string "I'll go look for one when I get better.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BF8DD:: @ 82BF8DD
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don't look at me that way.\n"
	.string "I'm getting all flustered…\l"
	.string "I… I need your advice.\p"
	.string "I… I'm really embarrassed, but I can't\n"
	.string "decide which POKéMON to use.\p"
	.string "If the choices were {STR_VAR_1} or\n"
	.string "{STR_VAR_2}, which would be better?$"

gText_082BF9BA:: @ 82BF9BA
	.string "Oh… Okay!\n"
	.string "I'll do my best with one {STR_VAR_1}.\p"
	.string "I hope I can do my best without\n"
	.string "getting all flustered.\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BFA5A:: @ 82BFA5A
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "No, no, if you are real, it's fine.\n"
	.string "Incidentally, I would like to obtain\l"
	.string "your advice.\p"
	.string "It's about the POKéMON I am to use.\p"
	.string "If the choices are the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, which is\l"
	.string "more worthy of me?$"

gText_082BFB4E:: @ 82BFB4E
	.string "{STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope it is something even I can\n"
	.string "handle with aplomb.\p"
	.string "Let us meet again!$"

gText_082BFBF2:: @ 82BFBF2
	.string "Waaah! Oh, {PLAYER}!\n"
	.string "Snivel… Hiccup…\p"
	.string "I have a dilemma!\n"
	.string "I can't decide on a move for\l"
	.string "my {STR_VAR_1}…\p"
	.string "Please, please, {PLAYER}.\n"
	.string "Can you decide for me?\p"
	.string "For my {STR_VAR_1}, which move would\n"
	.string "be the better choice: {STR_VAR_2}\l"
	.string "or {STR_VAR_3}?$"

gText_082BFCAE:: @ 82BFCAE
	.string "{STR_VAR_1}?\n"
	.string "Waaaaah!\p"
	.string "Oh! I'm so sorry, {PLAYER}!\n"
	.string "You've made me so happy by deciding\l"
	.string "the move, I'm crying…\p"
	.string "Snivel…\n"
	.string "Thank you so much!$"

gText_082BFD26:: @ 82BFD26
	.string "Yay! Hi, {PLAYER}!\n"
	.string "I need your advice again!\p"
	.string "I want to teach my {STR_VAR_1}\n"
	.string "a cool move.\p"
	.string "I like either of the moves\n"
	.string "{STR_VAR_2} or {STR_VAR_3}.\l"
	.string "What's your recommendation?$"

gText_082BFDB1:: @ 82BFDB1
	.string "{STR_VAR_1} is better? I guess so!\n"
	.string "Okay, I'll go with that!\p"
	.string "If we meet here again, please teach\n"
	.string "me something else, teacher!$"

gText_082BFE24:: @ 82BFE24
	.string "{PLAYER}, hello!\n"
	.string "It's about my {STR_VAR_1}, but I'm\l"
	.string "worried about its moves.\p"
	.string "You see, it's the moves {STR_VAR_2}\n"
	.string "and {STR_VAR_3}.\p"
	.string "Which is stronger and better for\n"
	.string "my {STR_VAR_1}?$"

gText_082BFEAD:: @ 82BFEAD
	.string "{STR_VAR_1} is your choice?\n"
	.string "Okay, I got it!\p"
	.string "I'll go teach {STR_VAR_1} to\n"
	.string "my POKéMON right away!\p"
	.string "See you again!$"

gText_082BFF0A:: @ 82BFF0A
	.string "Ohhh, {PLAYER}…\n"
	.string "I'm hopeless, no, really!\p"
	.string "I've decided to raise a POKéMON,\n"
	.string "but now I can't even decide what\l"
	.string "move I should let it learn…\p"
	.string "I know that it doesn't mean anything\n"
	.string "to you, {PLAYER}.\p"
	.string "But it means a lot to me…\p"
	.string "Please, {PLAYER}, could you choose\n"
	.string "a move for my {STR_VAR_1}?\p"
	.string "If you could even choose between\n"
	.string "{STR_VAR_2} and {STR_VAR_3}…$"

gText_082C0032:: @ 82C0032
	.string "I understand!\p"
	.string "But will it even be willing to learn\n"
	.string "{STR_VAR_1} for me…\l"
	.string "No! I'll do my best!\p"
	.string "Thank you!$"

gText_082C0090:: @ 82C0090
	.string "Oh, {PLAYER}{STRING 5}!\n"
	.string "I was just hoping to see you, too!\p"
	.string "I was wondering what move would\n"
	.string "be suitable for my {STR_VAR_1}.\p"
	.string "I can't decide, so can you decide\n"
	.string "for me instead?\p"
	.string "For instance… How about the moves\n"
	.string "{STR_VAR_2} and {STR_VAR_3}?\l"
	.string "Which one would be better?$"

gText_082C016E:: @ 82C016E
	.string "{STR_VAR_1}? That's great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won't be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I'll look to you for advice again.\n"
	.string "Bye!$"

gText_082C01F7:: @ 82C01F7
	.string "How could things be this busy?\n"
	.string "Hey, if it isn't {PLAYER}{STRING 5}!\l"
	.string "How's it going?\p"
	.string "Since I got up this morning, I've done\n"
	.string "my jogging, swimming, and cooking!\p"
	.string "You wouldn't believe how busy I am!\p"
	.string "I can't even decide what move\n"
	.string "my {STR_VAR_1} should learn!\p"
	.string "{STR_VAR_2} looks good, huh?\n"
	.string "But {STR_VAR_3}'s also decent.\p"
	.string "{PLAYER}{STRING 5}, give me some of your good\n"
	.string "advice! Which move'd be good for me?$"

gText_082C034C:: @ 82C034C
	.string "Okay, gotcha.\n"
	.string "I'll make room in my schedule and\l"
	.string "teach that move.\p"
	.string "I'm glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082C03CA:: @ 82C03CA
	.string "Oh! Lucky!\n"
	.string "I met you again, {PLAYER}!\l"
	.string "I need to tap your mind again today.\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "For my {STR_VAR_1}, which is the move\n"
	.string "best suited, {STR_VAR_2} or\l"
	.string "{STR_VAR_3}?$"

gText_082C046E:: @ 82C046E
	.string "Ahhh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that's about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let's meet here again, okay?\n"
	.string "Thanks!$"

gText_082C04F9:: @ 82C04F9
	.string "Oh, hello, {PLAYER}.\n"
	.string "I trust you've been well?\p"
	.string "I have to seek your advice again.\n"
	.string "It's about my dearest {STR_VAR_1}.\p"
	.string "What would be the ideal move for\n"
	.string "my lovable {STR_VAR_1}?\l"
	.string "{STR_VAR_2} or {STR_VAR_3}?$"

gText_082C0598:: @ 82C0598
	.string "{STR_VAR_1} it is!\n"
	.string "I will teach that right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082C0602:: @ 82C0602
	.string "Eek! {PLAYER}! I met you again!\n"
	.string "I… I'm overjoyed!\p"
	.string "Whenever I'm in need, you're always\n"
	.string "there for me, {PLAYER}!\p"
	.string "Today, I want you to recommend\n"
	.string "a move for me!\p"
	.string "Please choose a move for\n"
	.string "my {STR_VAR_1}!\p"
	.string "Which move would be better,\n"
	.string "{STR_VAR_2} or {STR_VAR_3}?$"

gText_082C06D8:: @ 82C06D8
	.string "Oh-oh-oh! Thank you!\n"
	.string "{STR_VAR_1} is it!\l"
	.string "Perfectly understood!\p"
	.string "I hope you'll be willing to teach me\n"
	.string "some more another time.$"

gText_082C074A:: @ 82C074A
	.string "Hola, {PLAYER}{STRING 5}, bueno!\n"
	.string "I'm hoping for some more of\l"
	.string "your sage advice today!\p"
	.string "What would be the best move for\n"
	.string "my {STR_VAR_1}?\p"
	.string "It should be something that'll\n"
	.string "let me win just like that!\p"
	.string "Would it be {STR_VAR_2}?\n"
	.string "Or {STR_VAR_3}?$"

gText_082C0809:: @ 82C0809
	.string "Uh-huh, {STR_VAR_1} it is!\n"
	.string "Si, bueno!\l"
	.string "I'll get it taught, like, ka-blam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082C086E:: @ 82C086E
	.string "{PLAYER}{STRING 5}, it's completely wild!\p"
	.string "My POKéMON!\n"
	.string "It learned six moves!\p"
	.string "Of course I'm lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at choosing moves\l"
	.string "for my POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "kind of move I should teach?\p"
	.string "{STR_VAR_2} or {STR_VAR_3}--which\n"
	.string "would go with my {STR_VAR_1} best?$"

gText_082C0982:: @ 82C0982
	.string "Okay, so it's {STR_VAR_1} you chose?\n"
	.string "I'll choose another move, then!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you'll keep teaching me!$"

gText_082C0A1D:: @ 82C0A1D
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin' SAILOR am I!\n"
	.string "I'm always with it, don't ask me why.\p"
	.string "Today, I have a move question\n"
	.string "that begs your suggestion!\p"
	.string "{STR_VAR_2} and {STR_VAR_3} are\n"
	.string "the moves. What would be the best\l"
	.string "for my {STR_VAR_1} so it grooves?$"

gText_082C0AFD:: @ 82C0AFD
	.string "{STR_VAR_1}, you say, hey, hey!\n"
	.string "I'll go teach that right away!\p"
	.string "If it's advice I ever need,\n"
	.string "{PLAYER}, your word I'll always heed!$"

gText_082C0B6F:: @ 82C0B6F
	.string "Oh, yeahah, if it isn't {PLAYER}!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I'm already talking to you!\p"
	.string "{PLAYER}, are you surprised by me?\n"
	.string "I want your advice, can't you see?\p"
	.string "Are you receiving me?\n"
	.string "You are receiving me!\p"
	.string "My {STR_VAR_1}--what should it use?\n"
	.string "It's {STR_VAR_2} or {STR_VAR_3},\l"
	.string "what do you choose?$"

gText_082C0C7D:: @ 82C0C7D
	.string "If that {STR_VAR_1} is the best,\n"
	.string "I'll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082C0D0B:: @ 82C0D0B
	.string "Gahack! Gaah! Oh, {PLAYER}{STRING 5}…\n"
	.string "I have this lousy cold, I do…\p"
	.string "I want to pick a move for my POKéMON,\n"
	.string "but I'm not up to it…\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, if I had to choose between\n"
	.string "{STR_VAR_2} and {STR_VAR_3} for\l"
	.string "my {STR_VAR_1}, which would it be?$"

gText_082C0DFE:: @ 82C0DFE
	.string "Hm, {STR_VAR_1}, all right. Cough!\n"
	.string "I'll go teach it when I get better.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082C0E71:: @ 82C0E71
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don't look at me that way.\n"
	.string "I'm getting all flustered…\l"
	.string "I… I need your advice.\p"
	.string "I… I'm really embarrassed, but I can't\n"
	.string "decide what move I should teach\l"
	.string "my POKéMON.\p"
	.string "It's for my {STR_VAR_1}.\n"
	.string "If the choices were {STR_VAR_2} or\l"
	.string "{STR_VAR_3}, which would be better?$"

gText_082C0F6D:: @ 82C0F6D
	.string "Oh… Okay!\n"
	.string "I'll try that {STR_VAR_1}.\p"
	.string "I hope I can teach that move…\n"
	.string "This is so nerve-racking…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082C1003:: @ 82C1003
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "Perhaps you're one of those popular\n"
	.string "mimics?\p"
	.string "No, no, if you are real, it's fine.\n"
	.string "No need to be upset, I assure you!\p"
	.string "Incidentally, I would like to obtain\n"
	.string "your advice.\p"
	.string "It's about my {STR_VAR_1}.\p"
	.string "Which move would be better for it to\n"
	.string "use, {STR_VAR_2} or {STR_VAR_3}?$"

gText_082C1122:: @ 82C1122
	.string "{STR_VAR_1}?\n"
	.string "There's no question about that?\p"
	.string "I see. If that's the case, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope it is something even\n"
	.string "my POKéMON can learn.\p"
	.string "Let us meet again!$"

gText_082C11D1:: @ 82C11D1
	.string "Oh… {PLAYER}?\n"
	.string "It is {PLAYER}!\l"
	.string "Oh! Sniff…sob… Please, listen!\p"
	.string "I… When I battle, I get so nervous,\n"
	.string "I can't help crying even if I win…\p"
	.string "I wish I could say something cool\n"
	.string "when I win…\p"
	.string "Please, please, {PLAYER}!\n"
	.string "Could you maybe teach me something\l"
	.string "cool to say when I win so I don't cry?$"

gText_082C12D5:: @ 82C12D5
	.string "{STR_VAR_1}\p"
	.string "Awesome! Wicked! Awoooh!\n"
	.string "It's really cool!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "Snivel… {PLAYER}!\n"
	.string "Thank you so much for everything!\p"
	.string "I will battle the best I can for\n"
	.string "your sake, {PLAYER}!\p"
	.string "{PLAYER}…\n"
	.string "Next time… We should battle!$"

gText_082C13AB:: @ 82C13AB
	.string "Yay! It's {PLAYER}! Hello!\n"
	.string "I wanted to ask you something!\p"
	.string "I want to say something cool when\n"
	.string "I win a match.\p"
	.string "Do you have a cool saying that\n"
	.string "you could recommend?$"

gText_082C1444:: @ 82C1444
	.string "{STR_VAR_1}\p"
	.string "Oh, wow! That is so cool!\n"
	.string "Okay, I'll say that!\p"
	.string "Thanks for teaching me all this time!\n"
	.string "I'm going to do the best I can\l"
	.string "wherever I go from now on!\p"
	.string "When we meet again, it'll be for\n"
	.string "a battle!$"

gText_082C1501:: @ 82C1501
	.string "{PLAYER}, hello!\p"
	.string "My POKéMON and I are ready for\n"
	.string "anything, except for one thing.\p"
	.string "I think it would be good if I had\n"
	.string "something to shout when I win.\p"
	.string "Could you think up something good\n"
	.string "to say?$"

gText_082C15B6:: @ 82C15B6
	.string "{STR_VAR_1}\p"
	.string "…Cool!\n"
	.string "I will use that!\p"
	.string "I'm going out to battle all over\n"
	.string "the place.\p"
	.string "Who knows, I may even get to battle\n"
	.string "you one day, {PLAYER}.\p"
	.string "Next time, let's meet at a place\n"
	.string "of battle!$"

gText_082C165E:: @ 82C165E
	.string "Hello, {PLAYER}…\n"
	.string "I'm sorry to bug you, but I'm hopeless…\p"
	.string "Even when…\n"
	.string "Even when I win, I don't have anything\l"
	.string "special to say…\p"
	.string "I know that it doesn't mean anything\n"
	.string "to you, {PLAYER}.\p"
	.string "But it means a lot to me…\p"
	.string "Please, {PLAYER}, what should I say\n"
	.string "if I win a battle?$"

gText_082C174F:: @ 82C174F
	.string "{STR_VAR_1}\p"
	.string "That's inspired…\p"
	.string "Uh… Is it okay for someone like me\n"
	.string "to even say that?\p"
	.string "No! I'll do my best!\p"
	.string "{PLAYER}, thank you so much for\n"
	.string "putting up with me for so long…\p"
	.string "I promise to do my best from now on.\p"
	.string "I'm sure you'll quickly forget about\n"
	.string "someone like me, but let's meet\l"
	.string "somewhere again!$"

gText_082C1862:: @ 82C1862
	.string "Oh, {PLAYER}{STRING 5}.\n"
	.string "There's something I want you to hear.\p"
	.string "I know that I don't always sound\n"
	.string "nice or polite…\p"
	.string "When I win a battle, I think I come\n"
	.string "across as being arrogant.\p"
	.string "I don't want people to dislike me,\n"
	.string "so I want to say something nice to\l"
	.string "someone I beat.\p"
	.string "But I can't think of anything good!\n"
	.string "Could you think something up for me?$"

gText_082C19A0:: @ 82C19A0
	.string "{STR_VAR_1}\p"
	.string "Not bad!\n"
	.string "Yup, that's what I'll go with!\p"
	.string "I'm going to hit the road and do what\n"
	.string "I can with what you taught me in\l"
	.string "my head and heart.\p"
	.string "I'm sorry that I've been so pushy\n"
	.string "with you!\p"
	.string "Next time, we battle, okay?\n"
	.string "See you!$"

gText_082C1A76:: @ 82C1A76
	.string "Oh, I can't get over how busy I am!\n"
	.string "Oh, hey, I was looking for you, {PLAYER}{STRING 5}.\p"
	.string "Are you well as usual?\n"
	.string "Things haven't changed for me at all.\p"
	.string "I've got running, fighting, and mapping\n"
	.string "to do. Why am I so busy?\p"
	.string "But even though I'm busy, it'd be rude\n"
	.string "to just turn on my heels and walk away\l"
	.string "from a win without saying a word.\p"
	.string "So, what would be a cool saying to\n"
	.string "underline my coolness when I'm done\l"
	.string "and walking away? {PLAYER}{STRING 5}, help me!$"

gText_082C1C16:: @ 82C1C16
	.string "{STR_VAR_1}\p"
	.string "Okay, gotcha.\n"
	.string "I can find time to say that!\p"
	.string "Honestly, I'm glad I met a good mentor\n"
	.string "like you.\p"
	.string "I'm going to make time somehow so\n"
	.string "I can get into battling.\p"
	.string "Thanks for everything, {PLAYER}{STRING 5}!\n"
	.string "We have to battle, you and me, one day!$"

gText_082C1CF5:: @ 82C1CF5
	.string "I lucked out again!\n"
	.string "{PLAYER}! Am I glad to see you!\l"
	.string "Like usual, I need your advice!\p"
	.string "Drum roll, please!\n"
	.string "The last question I have is…\p"
	.string "If I win a battle and want to end\n"
	.string "it with a cool flourish, what\l"
	.string "should I say?$"

gText_082C1DC1:: @ 82C1DC1
	.string "{STR_VAR_1}\p"
	.string "That… That's fabulous!\n"
	.string "It's dignified and cool! I claim it!\p"
	.string "…Listen, I think I'm getting decent\n"
	.string "at this, huh?\p"
	.string "So, I'm thinking of challenging other\n"
	.string "TRAINERS from now on.\p"
	.string "{PLAYER}, your advice really helped me.\p"
	.string "Maybe one day, there'll be a time when\n"
	.string "we battle!\p"
	.string "Thank you for everything!$"

gText_082C1EDC:: @ 82C1EDC
	.string "Oh, {PLAYER}.\n"
	.string "I'm so glad I met you!\p"
	.string "I no longer have any concerns with\n"
	.string "regard to my POKéMON.\p"
	.string "It's myself that worries me…\p"
	.string "Do you know how a TRAINER says\n"
	.string "a few things upon winning a battle?\p"
	.string "Definitely, I wish I could do that,\n"
	.string "too!\p"
	.string "Please, what should I say when\n"
	.string "I win a battle?$"

gText_082C1FEC:: @ 82C1FEC
	.string "{STR_VAR_1}\p"
	.string "Ah! That saying! It refreshes me\n"
	.string "and makes me feel reborn!\p"
	.string "I must use that right away!\p"
	.string "And now, I must take my leave,\n"
	.string "{PLAYER}…\p"
	.string "I will go out to battle many others,\n"
	.string "but never will I forget your teachings.\p"
	.string "Perhaps one day…\n"
	.string "Farewell!$"

gText_082C20D1:: @ 82C20D1
	.string "Eek! I spotted {PLAYER}!\n"
	.string "I… I'm overjoyed to see you!\p"
	.string "Oh-oh-oh! There's something I just\n"
	.string "had to ask you!\p"
	.string "A little while ago, I won a battle.\n"
	.string "That part was giddying!\p"
	.string "But it made me so overjoyed that\n"
	.string "I choked up and couldn't say a thing!\p"
	.string "So now, {PLAYER}, please, I want you to\n"
	.string "think up an exit line for when I win!$"

gText_082C21FF:: @ 82C21FF
	.string "{STR_VAR_1}\p"
	.string "Waaaaah!\n"
	.string "I'm going to say that?!\l"
	.string "I… I'm delirious with joy!\p"
	.string "Th-th-thank you!\n"
	.string "I have nothing left to regret now!\p"
	.string "I'm going to travel now and battle\n"
	.string "all sorts of people.\p"
	.string "Everything, I owe it to you, {PLAYER}.\n"
	.string "Really, really, thank you!\p"
	.string "I've got to go now, but let's meet\n"
	.string "in battle one day!$"

gText_082C231C:: @ 82C231C
	.string "Hola, bueno!\n"
	.string "{PLAYER}{STRING 5}!\p"
	.string "You know, I'm getting the itch to roam\n"
	.string "and battle where I may.\p"
	.string "But before I do, I want your advice\n"
	.string "once again, please!\p"
	.string "If I were to win a battle, what would\n"
	.string "be a good boast I could say to my\l"
	.string "fallen TRAINER opponent?$"

gText_082C2407:: @ 82C2407
	.string "{STR_VAR_1}\p"
	.string "Uh-huh, that's sweet!\n"
	.string "Si, bueno!\l"
	.string "I'll try saying that, like, ham!\p"
	.string "And now, it's time to say good-bye!\n"
	.string "Thanks for all sorts of things!\p"
	.string "Give me a battle one day, OK?\n"
	.string "Adios!$"

gText_082C24B5:: @ 82C24B5
	.string "{PLAYER}{STRING 5}, there's big trouble!\p"
	.string "When I win a battle, I brag about it\n"
	.string "for an hour at least!\p"
	.string "Of course I'm lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I'm not very good at chatting.\p"
	.string "So, how about deciding for me what\n"
	.string "I should say after winning a battle,\l"
	.string "master?$"

gText_082C25B1:: @ 82C25B1
	.string "{STR_VAR_1}\p"
	.string "That's what I should say, huh?\n"
	.string "Then, I'll stay away from that!\p"
	.string "Just kidding!\n"
	.string "I'll obey your teaching, master!\p"
	.string "Thanks for teaching me all this time,\n"
	.string "master!\p"
	.string "I'm finally understanding what being\n"
	.string "a TRAINER is about.\p"
	.string "I'm going to go out and win battles\n"
	.string "against any TRAINER.\p"
	.string "Maybe it'll be you one day, master!\p"
	.string "That's all!\n"
	.string "Farewell, my master!$"

gText_082C2707:: @ 82C2707
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin' SAILOR am I!\n"
	.string "This will be my last question,\l"
	.string "don't you cry!\p"
	.string "It's a saying question\n"
	.string "that begs your suggestion!\p"
	.string "If I win a match, what can I say\n"
	.string "in a real cool way?$"

gText_082C27D4:: @ 82C27D4
	.string "{STR_VAR_1}\p"
	.string "Perfect! That's what I'll use.\n"
	.string "I was right to make you choose!\p"
	.string "And now, I think it'd be best,\n"
	.string "if I were to fly the nest!\p"
	.string "Thanks for all you taught me.\n"
	.string "I'll be off on a battle spree!\p"
	.string "B-O-N-V-O-Y-A-G-E!\n"
	.string "And that spells bon voyage,\l"
	.string "to you this is my homage!$"

gText_082C28D6:: @ 82C28D6
	.string "Oh, yeah, {PLAYER}!\n"
	.string "I found you again today!\p"
	.string "What should I do? Ask you again?\n"
	.string "Why not? I'm already asking you!\p"
	.string "Anyways, {PLAYER}…\n"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\l"
	.string "I need some more advice for me!\p"
	.string "It's about what I should yell.\n"
	.string "Something cool to holler when\l"
	.string "a battle ends well.\p"
	.string "Come on, I wanna hear you say it!$"

gText_082C2A0B:: @ 82C2A0B
	.string "{STR_VAR_1}\p"
	.string "All right, all right!\n"
	.string "I'll use that because it's so tight!\p"
	.string "I'm out of things to ask you.\n"
	.string "Waving bye is all that's left to do.\p"
	.string "But maybe one day we'll meet, with one\n"
	.string "destined to go down in defeat.\p"
	.string "But, it really is time to say farewell.\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don't you forget about me!\p"
	.string "Take care, {PLAYER}!\n"
	.string "Love ya!$"

gText_082C2B50:: @ 82C2B50
	.string "{PLAYER}{STRING 5}, I'm finished…\n"
	.string "My nose won't stop dripping…\p"
	.string "I was trying to think up something\n"
	.string "cool to say when I win a battle.\p"
	.string "It inspired me so much, it made me cry,\n"
	.string "and now my nose won't stop running…\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me, {PLAYER}{STRING 5}.\p"
	.string "When I win a battle,\n"
	.string "what should I say?$"

gText_082C2C77:: @ 82C2C77
	.string "{STR_VAR_1}\p"
	.string "… … …That's good.\n"
	.string "No, it's awe inspiring!\l"
	.string "It's bringing fresh tears to my eyes!\p"
	.string "But in spite of my tears and runny\n"
	.string "nose, I will use that saying!\p"
	.string "I'm plumb out of things to ask you,\n"
	.string "{PLAYER}{STRING 5}.\p"
	.string "From now on, we're rivals!\n"
	.string "Thanks for everything!$"

gText_082C2D67:: @ 82C2D67
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…\p"
	.string "Please, don't look at me that way.\n"
	.string "You're making me all nervous.\p"
	.string "I… I need your advice again.\n"
	.string "I'll make it my last, though…\p"
	.string "It's really embarrassing to ask,\n"
	.string "but what if I win a battle?\l"
	.string "What should I say?$"

gText_082C2E41:: @ 82C2E41
	.string "{STR_VAR_1}\p"
	.string "Oh… Okay!\n"
	.string "I'll try to say that!\l"
	.string "I might be too nervous to say it…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "I have to say good-bye now.\p"
	.string "I'll obey all that you've taught me,\n"
	.string "{PLAYER}{STRING 5}, and do the best I can.$"

gText_082C2EF5:: @ 82C2EF5
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps a clever {PLAYER} DOLL?\p"
	.string "Oh, no, no, no, don't worry!\n"
	.string "If you really are real, please\l"
	.string "forget about my rudeness.\p"
	.string "No need to be so angry. All I wish for\n"
	.string "is more of your fine advice.\p"
	.string "It concerns a saying.\p"
	.string "More precisely, what should I say\n"
	.string "if I win a battle?$"

gText_082C3023:: @ 82C3023
	.string "{STR_VAR_1}\p"
	.string "… … … … … …\n"
	.string "When I win a match…\p"
	.string "{STR_VAR_1}\p"
	.string "…Are you serious?\p"
	.string "I see. If you are serious, that's fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope even I will be able to\n"
	.string "put that saying to good use.\p"
	.string "I seem to have run dry on what advice\n"
	.string "I need.\p"
	.string "I do believe it's high time I bid you\n"
	.string "farewell and strike out on my own.\p"
	.string "Thank you, my mentor!\n"
	.string "I apologize for my skepticism!$"
