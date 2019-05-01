LilycoveCity_House3_MapScripts:: @ 821EE3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition: @ 821EE42
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_21EE4B:: @ 821EE4B
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_21EF99, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_House3_EventScript_21EE75
	msgbox LilycoveCity_House3_Text_21F0F8, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EE75:: @ 821EE75
	msgbox LilycoveCity_House3_Text_21F0A9, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EE8A:: @ 821EE8A
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_21F430, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_21EEA1:: @ 821EEA1
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EED5:: @ 821EED5
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF09:: @ 821EF09
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF3D:: @ 821EF3D
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_21EF71
	case 1, LilycoveCity_House3_EventScript_21EF7B
	case 2, LilycoveCity_House3_EventScript_21EF85
	case 3, LilycoveCity_House3_EventScript_21EF8F
	end

LilycoveCity_House3_EventScript_21EF71:: @ 821EF71
	msgbox LilycoveCity_House3_Text_21F4A7, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF7B:: @ 821EF7B
	msgbox LilycoveCity_House3_Text_21F4E0, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF85:: @ 821EF85
	msgbox LilycoveCity_House3_Text_21F523, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_21EF8F:: @ 821EF8F
	msgbox LilycoveCity_House3_Text_21F55A, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_21EF99: @ 821EF99
	.string "Oh, my, my! Are you traveling alone?\n"
	.string "But you're so young! Good for you!\p"
	.string "I'm sure my kids could learn a thing\n"
	.string "or two from you!\p"
	.string "Me? I'm a master of {POKEBLOCK}s.\p"
	.string "If I get serious just a little, why,\n"
	.string "I can concoct great {POKEBLOCK}s.\p"
	.string "Would you like to learn from me,\n"
	.string "a master of {POKEBLOCK}s?$"

LilycoveCity_House3_Text_21F0A9: @ 821F0A9
	.string "Oh? Are you sure?\p"
	.string "You shouldn't always try to do\n"
	.string "everything by yourself, dear!$"

LilycoveCity_House3_Text_21F0F8: @ 821F0F8
	.string "Oh, good! You're a smart soul!\n"
	.string "This is a bit long, so listen up!\p"
	.string "Are you ready?\p"
	.string "If you look at {POKEBLOCK}s, you should see\n"
	.string "that they are rated on how they feel.\p"
	.string "The lower the feel rating,\n"
	.string "the better it is. Don't forget this!\p"
	.string "A good {POKEBLOCK} has a low feel\n"
	.string "rating and a high level.\p"
	.string "A Pokémon can eat more good\n"
	.string "{POKEBLOCK}s than ordinary ones, too.\p"
	.string "And this is important.\p"
	.string "If you want to make smooth {POKEBLOCK}s,\n"
	.string "use different kinds of Berries.\p"
	.string "Don't be stingy--the kinds of Berries\n"
	.string "affect the smoothness of {POKEBLOCK}s.\p"
	.string "And another thing.\p"
	.string "The more people blending Berries,\n"
	.string "the smoother the {POKEBLOCK}s.\p"
	.string "That's why you should talk to other\n"
	.string "people and make {POKEBLOCK}s together.\p"
	.string "That's about all you need to know to\n"
	.string "make good {POKEBLOCK}s.\p"
	.string "If everyone had Pokémon they love,\n"
	.string "smooth {POKEBLOCK}s, and a loving family,\l"
	.string "the world would be a happier place.\p"
	.string "Don't give up, dear!$"

LilycoveCity_House3_Text_21F430: @ 821F430
	.string "When my wife gave birth to quadruplets,\n"
	.string "you bet I was shocked.\p"
	.string "But, now, seeing them play together,\n"
	.string "it makes me happy.$"

LilycoveCity_House3_Text_21F4A7: @ 821F4A7
	.string "We're having Multi Battles, but I know\n"
	.string "I'm going to win.$"

LilycoveCity_House3_Text_21F4E0: @ 821F4E0
	.string "We like mixing stuff at\n"
	.string "the Record Corner.\p"
	.string "But what gets mixed up?$"

LilycoveCity_House3_Text_21F523: @ 821F523
	.string "We're going to make super {POKEBLOCK}s\n"
	.string "with a Berry Blender!$"

LilycoveCity_House3_Text_21F55A: @ 821F55A
	.string "I want to brag about how tough my\n"
	.string "Pokémon is, so we're going to enter\l"
	.string "a Contest together.$"

