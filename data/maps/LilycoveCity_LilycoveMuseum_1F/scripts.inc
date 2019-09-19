LilycoveCity_LilycoveMuseum_1F_MapScripts:: @ 8218CB8
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_218CB9:: @ 8218CB9
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218E4B, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CC2:: @ 8218CC2
	lockall
	applymovement 2, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_218EBC
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218CF5
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218CEC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CEC:: @ 8218CEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218F5C, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218CF5:: @ 8218CF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218F98, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218D14
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_218D1E
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D14:: @ 8218D14
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_218FF8, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D1E:: @ 8218D1E
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219035, MSGBOX_SIGN
	applymovement 2, LilycoveCity_LilycoveMuseum_1F_Movement_218D99
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case 2, LilycoveCity_LilycoveMuseum_1F_EventScript_218D5A
	case 3, LilycoveCity_LilycoveMuseum_1F_EventScript_218D6F
	case 4, LilycoveCity_LilycoveMuseum_1F_EventScript_218D84
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D5A:: @ 8218D5A
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218DA1
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D6F:: @ 8218D6F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218D9B
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218D84:: @ 8218D84
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_218D9E
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_218D99: @ 8218D99
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218D9B: @ 8218D9B
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218D9E: @ 8218D9E
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_218DA1: @ 8218DA1
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DA4:: @ 8218DA4
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219080, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DAD:: @ 8218DAD
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2190BF, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DB6:: @ 8218DB6
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2190F9, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DBF:: @ 8218DBF
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219142, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DC8:: @ 8218DC8
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2191A2, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DD1:: @ 8218DD1
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21920D, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DDA:: @ 8218DDA
LilycoveCity_LilycoveMuseum_2F_EventScript_218DDA:: @ 8218DDA
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219260, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DE3:: @ 8218DE3
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2192AA, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DEC:: @ 8218DEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219311, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DF5:: @ 8218DF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2193B4, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218DFE:: @ 8218DFE
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21941A, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E07:: @ 8218E07
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2194BA, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E10:: @ 8218E10
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2194E1, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E19:: @ 8218E19
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_219515, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E22:: @ 8218E22
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21959B, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E2B:: @ 8218E2B
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_2195FF, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_218E42:: @ 8218E42
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_21967A, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_218E4B: @ 8218E4B
	.string "Welcome to LILYCOVE MUSEUM.\p"
	.string "Please take the time to enjoy our\n"
	.string "collection of fantastic artwork\l"
	.string "featuring POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_218EBC: @ 8218EBC
	.string "I'm the CURATOR of this MUSEUM of\n"
	.string "fine arts.\p"
	.string "It's heartening to see someone so\n"
	.string "young as you in our MUSEUM.\p"
	.string "Have you viewed our collection of\n"
	.string "paintings already?$"

LilycoveCity_LilycoveMuseum_1F_Text_218F5C: @ 8218F5C
	.string "Ah, then let me not disturb you.\n"
	.string "Please, do take your time.$"

LilycoveCity_LilycoveMuseum_1F_Text_218F98: @ 8218F98
	.string "Oh? I do believe that you seem to\n"
	.string "be a POKéMON TRAINER.\p"
	.string "Have you an interest in paintings,\n"
	.string "too?$"

LilycoveCity_LilycoveMuseum_1F_Text_218FF8: @ 8218FF8
	.string "I see…\p"
	.string "I'm honored that you would visit\n"
	.string "us in spite of that.$"

LilycoveCity_LilycoveMuseum_1F_Text_219035: @ 8219035
	.string "Ah, excellent!\n"
	.string "You do like paintings!\p"
	.string "Then, may I ask you to come with me?$"

LilycoveCity_LilycoveMuseum_1F_Text_219080: @ 8219080
	.string "It's a very old painting.\n"
	.string "The paint is peeling here and there.$"

LilycoveCity_LilycoveMuseum_1F_Text_2190BF: @ 82190BF
	.string "It's an odd landscape with bizarre\n"
	.string "and fantastic scenery.$"

LilycoveCity_LilycoveMuseum_1F_Text_2190F9: @ 82190F9
	.string "It's a painting of a beautiful, smiling\n"
	.string "woman with a POKéMON on her lap.$"

LilycoveCity_LilycoveMuseum_1F_Text_219142: @ 8219142
	.string "It's a painting of a legendary POKéMON\n"
	.string "from long ago.\p"
	.string "The artist painted this from\n"
	.string "imagination.$"

LilycoveCity_LilycoveMuseum_1F_Text_2191A2: @ 82191A2
	.string "It's a painting of GRASS POKéMON\n"
	.string "swaying in a breeze.\p"
	.string "They appear to be enjoying the wind's\n"
	.string "gentle caress.$"

LilycoveCity_LilycoveMuseum_1F_Text_21920D: @ 821920D
	.string "It's a delicious-looking painting\n"
	.string "of BERRIES.\p"
	.string "This painting could make you hungry!$"

LilycoveCity_LilycoveMuseum_1F_Text_219260: @ 8219260
	.string "It's a replica of a famous sculpture.\p"
	.string "It depicts an ancient BIRD POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_2192AA: @ 82192AA
	.string "It's a big POKé BALL carved from\n"
	.string "a black stone.\p"
	.string "It was apparently used in festivals\n"
	.string "in the olden days.$"

LilycoveCity_LilycoveMuseum_1F_Text_219311: @ 8219311
	.string "It's a huge stone tablet inscribed\n"
	.string "with POKéMON and dense text in the\l"
	.string "small characters of an ancient,\l"
	.string "unreadable language.$"

LilycoveCity_LilycoveMuseum_1F_Text_21938C: @ 821938C
	.string "Hmmm…\n"
	.string "What works of great magnificence…$"

LilycoveCity_LilycoveMuseum_1F_Text_2193B4: @ 82193B4
	.string "Battling with POKéMON is fun,\n"
	.string "I'll grant you that.\p"
	.string "But one mustn't forget our love for\n"
	.string "the fine arts.$"

LilycoveCity_LilycoveMuseum_1F_Text_21941A: @ 821941A
	.string "This ART MUSEUM… Well, you could\n"
	.string "see many fantastic paintings.\p"
	.string "And the CURATOR is a wonderful person.\p"
	.string "Among artists like myself, this MUSEUM\n"
	.string "is an inspiration.$"

LilycoveCity_LilycoveMuseum_1F_Text_2194BA: @ 82194BA
	.string "This lady is pretty!\n"
	.string "She's like Mommy!$"

LilycoveCity_LilycoveMuseum_1F_Text_2194E1: @ 82194E1
	.string "This POKéMON is adorable!\n"
	.string "Just like our little boy!$"

LilycoveCity_LilycoveMuseum_1F_Text_219515: @ 8219515
	.string "I'd heard that this ART MUSEUM got\n"
	.string "in some new paintings.\p"
	.string "So, naturally I hurried over.\p"
	.string "Are the new paintings up on\n"
	.string "the second floor?$"

LilycoveCity_LilycoveMuseum_1F_Text_21959B: @ 821959B
	.string "Lately, the CURATOR has been\n"
	.string "unusually cheerful.\p"
	.string "I bet something good happened for him.\n"
	.string "Definitely.$"

LilycoveCity_LilycoveMuseum_1F_Text_2195FF: @ 82195FF
	.string "I aim to see many great paintings\n"
	.string "here and learn from them.\p"
	.string "I have this dream of one day having\n"
	.string "my artwork exhibited here.$"

LilycoveCity_LilycoveMuseum_1F_Text_21967A: @ 821967A
	.string "The ART MUSEUM has become a favorite\n"
	.string "tourist destination.\p"
	.string "It's great for LILYCOVE…\n"
	.string "No, great for the HOENN region!\p"
	.string "This is what I've heard--a lone TRAINER\n"
	.string "procured all the paintings upstairs.$"

