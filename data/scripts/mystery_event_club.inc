PetalburgCity_PokemonCenter_1F_EventScript_291539:: @ 8291539
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, PetalburgCity_PokemonCenter_1F_EventScript_2915F5
	msgbox PetalburgCity_PokemonCenter_1F_Text_291687, MSGBOX_DEFAULT
	goto PetalburgCity_PokemonCenter_1F_EventScript_291552
	end

PetalburgCity_PokemonCenter_1F_EventScript_291552:: @ 8291552
	msgbox PetalburgCity_PokemonCenter_1F_Text_2916FF, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
	switch VAR_RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_29159F
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_2915EB
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_291591
	case MULTI_B_PRESSED, PetalburgCity_PokemonCenter_1F_EventScript_2915EB
	end

PetalburgCity_PokemonCenter_1F_EventScript_291591:: @ 8291591
	msgbox PetalburgCity_PokemonCenter_1F_Text_291729, MSGBOX_DEFAULT
	goto PetalburgCity_PokemonCenter_1F_EventScript_291552
	end

PetalburgCity_PokemonCenter_1F_EventScript_29159F:: @ 829159F
	msgbox PetalburgCity_PokemonCenter_1F_Text_291969, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_2915CB
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_2915D5
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915CB:: @ 82915CB
	msgbox PetalburgCity_PokemonCenter_1F_Text_2919DC, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915D5:: @ 82915D5
	setvar VAR_0x8004, 0
	special sub_811EECC
	waitmessage
	delay 80
	msgbox PetalburgCity_PokemonCenter_1F_Text_291B22, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915EB:: @ 82915EB
	msgbox PetalburgCity_PokemonCenter_1F_Text_291991, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915F5:: @ 82915F5
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A1B, MSGBOX_DEFAULT
	goto PetalburgCity_PokemonCenter_1F_EventScript_291603
	end

PetalburgCity_PokemonCenter_1F_EventScript_291603:: @ 8291603
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A4F, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
	switch VAR_RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_291650
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_29167C
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_291642
	case MULTI_B_PRESSED, PetalburgCity_PokemonCenter_1F_EventScript_29167C
	end

PetalburgCity_PokemonCenter_1F_EventScript_291642:: @ 8291642
	msgbox PetalburgCity_PokemonCenter_1F_Text_291729, MSGBOX_DEFAULT
	goto PetalburgCity_PokemonCenter_1F_EventScript_291603
	end

PetalburgCity_PokemonCenter_1F_EventScript_291650:: @ 8291650
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A6B, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_2915CB
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_2915D5
	end

PetalburgCity_PokemonCenter_1F_EventScript_29167C:: @ 829167C
	msgbox PetalburgCity_PokemonCenter_1F_Text_291ABA, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_291686:: @ 8291686
	return

PetalburgCity_PokemonCenter_1F_Text_291687: @ 8291687
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile, there.\p"
	.string "I have a hobby--collecting the profiles\n"
	.string "of POKéMON TRAINERS.$"

PetalburgCity_PokemonCenter_1F_Text_2916FF: @ 82916FF
	.string "So, how about it?\n"
	.string "May I see your profile?$"

PetalburgCity_PokemonCenter_1F_Text_291729: @ 8291729
	.string "You make your own profile by putting\n"
	.string "together four words or phrases.\p"
	.string "Here, I'll show you an example of a\n"
	.string "profile using four pieces of text.\p"
	.string "You can switch those four pieces with\n"
	.string "other text pieces any which way you\l"
	.string "like to make your own profile.\p"
	.string "There are a lot of text pieces that\n"
	.string "you can use.\p"
	.string "They are arranged in groups like\n"
	.string "POKéMON, lifestyles, and hobbies so\l"
	.string "it is easier to look them up.\p"
	.string "So, first, choose the group of text\n"
	.string "pieces to display a list of choices.\p"
	.string "Then, pick the choice you want.\p"
	.string "Repeat for the remaining text choices,\n"
	.string "and you'll have your very own profile.$"

PetalburgCity_PokemonCenter_1F_Text_291969: @ 8291969
	.string "Yes! Thank you!\n"
	.string "So, let's see it, then.$"

PetalburgCity_PokemonCenter_1F_Text_291991: @ 8291991
	.string "Oh, no, really?\p"
	.string "I imagine someone like you would have\n"
	.string "a wonderful profile…$"

PetalburgCity_PokemonCenter_1F_Text_2919DC: @ 82919DC
	.string "Oh? You're not into it right now?\p"
	.string "Well, anytime is good by me!$"

PetalburgCity_PokemonCenter_1F_Text_291A1B: @ 8291A1B
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile.$"

PetalburgCity_PokemonCenter_1F_Text_291A4F: @ 8291A4F
	.string "May I see your new profile?$"

PetalburgCity_PokemonCenter_1F_Text_291A6B: @ 8291A6B
	.string "Yes! Thank you!\p"
	.string "I hope it's even better than the profile\n"
	.string "you showed me before.$"

PetalburgCity_PokemonCenter_1F_Text_291ABA: @ 8291ABA
	.string "Oh, you like your profile the way it is.\p"
	.string "I don't blame you--it's a wonderful\n"
	.string "profile the way it is now.$"

PetalburgCity_PokemonCenter_1F_Text_291B22: @ 8291B22
	.string "F-fantastic!\p"
	.string "Your profile, it's wonderful!\n"
	.string "It really says what you're about.\p"
	.string "Why, anyone hearing this profile would\n"
	.string "be captivated by you!\p"
	.string "Thank you!$"

PetalburgCity_PokemonCenter_1F_Text_291BB7: @ 8291BB7
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
