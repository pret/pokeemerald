LilycoveCity_LilycoveMuseum_2F_MapScripts:: @ 821973A
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_MapScript1_219745
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_MapScript2_2197FE
	.byte 0

LilycoveCity_LilycoveMuseum_2F_MapScript1_219745: @ 8219745
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_21978B
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219754
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219754:: @ 8219754
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197A3
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219763
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219763:: @ 8219763
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197BB
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219772
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219772:: @ 8219772
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197D3
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219781
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219781:: @ 8219781
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2197EB
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21978B:: @ 821978B
	setmetatile 10, 6, 606, 1
	setmetatile 11, 6, 607, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219754
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197A3:: @ 82197A3
	setmetatile 18, 6, 604, 1
	setmetatile 19, 6, 605, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219763
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197BB:: @ 82197BB
	setmetatile 14, 10, 608, 1
	setmetatile 15, 10, 609, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219772
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197D3:: @ 82197D3
	setmetatile 6, 10, 602, 1
	setmetatile 7, 10, 603, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_219781
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2197EB:: @ 82197EB
	setmetatile 2, 6, 610, 1
	setmetatile 3, 6, 611, 1
	end

LilycoveCity_LilycoveMuseum_2F_MapScript2_2197FE: @ 82197FE
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_219808
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_219808:: @ 8219808
	lockall
	applymovement 1, Common_Movement_FacePlayer
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219861
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_2199EB, MSGBOX_SIGN
	applymovement 1, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219A0D, MSGBOX_SIGN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_219861
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219BC4, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 0x1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_219861: @ 8219861
	walk_in_place_fastest_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_219863: @ 8219863
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_219866:: @ 8219866
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_219921
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_2198C3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219CF3, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198BA:: @ 82198BA
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219D42, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198C3:: @ 82198C3
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219DD4, MSGBOX_DEFAULT
	applymovement 1, LilycoveCity_LilycoveMuseum_2F_Movement_219863
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219DE6, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_2198EA
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2198EA:: @ 82198EA
	applymovement 1, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219EC5, MSGBOX_DEFAULT
	givedecoration_std 44
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_2F_EventScript_219911
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219911:: @ 8219911
	call Common_EventScript_NoRoomLeftForAnother
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219EED, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219921:: @ 8219921
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219F1B, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21992B:: @ 821992B
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199C1
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219FA0, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21993E:: @ 821993E
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199DD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_219FD3, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219951:: @ 8219951
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199A5
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A03B, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219964:: @ 8219964
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199B3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A008, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219977:: @ 8219977
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_2199CF
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A06D, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21998A:: @ 821998A
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0BD, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_219993:: @ 8219993
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A132, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_21999C:: @ 821999C
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A1A8, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199A5:: @ 82199A5
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 9
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199B3:: @ 82199B3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 10
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199C1:: @ 82199C1
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 11
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199CF:: @ 82199CF
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 12
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_2199DD:: @ 82199DD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_21A0A1, MSGBOX_SIGN
	fadescreen 1
	drawcontestwinner 13
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_2199EB: @ 82199EB
	.string "This is our special exhibit hall.$"

LilycoveCity_LilycoveMuseum_2F_Text_219A0D: @ 8219A0D
	.string "As you can plainly see, there is not\n"
	.string "a single painting on exhibit.\p"
	.string "Here, I don't wish to exhibit works of\n"
	.string "so-called classical art.\p"
	.string "Such classical works you can see on\n"
	.string "our ground floor.\p"
	.string "I wish to exhibit work that is far\n"
	.string "different from the classics.\p"
	.string "Art, after all, is not restricted to old,\n"
	.string "famous works!\p"
	.string "This exhibit hall, I wish to fill it with…\p"
	.string "Modern and vibrant artworks of\n"
	.string "POKéMON seemingly ready to spring\l"
	.string "forth into glorious life!$"

LilycoveCity_LilycoveMuseum_2F_Text_219BC4: @ 8219BC4
	.string "I beg your pardon. I didn't intend\n"
	.string "to monopolize the conversation.\p"
	.string "Now, as you are young, and yet\n"
	.string "obviously well traveled…\p"
	.string "You must encounter lively POKéMON\n"
	.string "and works of art depicting them.\p"
	.string "If you were to come across such\n"
	.string "a painting, may we ask you to obtain\l"
	.string "the artist's permission to exhibit\l"
	.string "it here?$"

LilycoveCity_LilycoveMuseum_2F_Text_219CF3: @ 8219CF3
	.string "I wish to fill this exhibit hall with\n"
	.string "modern and vibrant paintings of\l"
	.string "POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_219D42: @ 8219D42
	.string "Thanks to you, we've added a new\n"
	.string "painting to our collection!\p"
	.string "I've heard it depicts your POKéMON.\n"
	.string "Truly magnificent!\p"
	.string "Thank you so very, very much!$"

LilycoveCity_LilycoveMuseum_2F_Text_219DD4: @ 8219DD4
	.string "Ah! It's you!\n"
	.string "{PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_219DE6: @ 8219DE6
	.string "Isn't this marvelous?\n"
	.string "This collection of paintings!\p"
	.string "Each one of them flawless!\n"
	.string "None better than another!\p"
	.string "These paintings have attracted\n"
	.string "more guests to our ART MUSEUM.\p"
	.string "Sincerely, I thank you, {PLAYER}.\n"
	.string "This is my dream come true!$"

LilycoveCity_LilycoveMuseum_2F_Text_219EC5: @ 8219EC5
	.string "This is merely a token of my gratitude.$"

LilycoveCity_LilycoveMuseum_2F_Text_219EED: @ 8219EED
	.string "I will keep this for you until we\n"
	.string "meet again.$"

LilycoveCity_LilycoveMuseum_2F_Text_219F1B: @ 8219F1B
	.string "Ah, so good to see you, {PLAYER}!\p"
	.string "It's an honor to have you visit us\n"
	.string "on your busy journeys.\p"
	.string "Please, relax and do enjoy your\n"
	.string "visit with us.$"

LilycoveCity_LilycoveMuseum_2F_Text_219FA0: @ 8219FA0
	.string "It's a picture frame with pink-colored\n"
	.string "adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_219FD3: @ 8219FD3
	.string "It's a picture frame with\n"
	.string "yellow-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A008: @ 821A008
	.string "It's a picture frame with\n"
	.string "blue-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A03B: @ 821A03B
	.string "It's a picture frame with\n"
	.string "red-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A06D: @ 821A06D
	.string "It's a picture frame with\n"
	.string "green-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A0A1: @ 821A0A1
	.string "It's a painting of POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A0BD: @ 821A0BD
	.string "I've been away awhile, so the new\n"
	.string "paintings up here surprised me.\p"
	.string "I wish someone would paint my POKéMON\n"
	.string "this pretty.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A132: @ 821A132
	.string "Well… So this is where they show\n"
	.string "the topical POKéMON paintings.\p"
	.string "I see, these new paintings are indeed\n"
	.string "rather amusing.$"

LilycoveCity_LilycoveMuseum_2F_Text_21A1A8: @ 821A1A8
	.string "Wow, is that right?\n"
	.string "These paintings are of your POKéMON.\p"
	.string "Isn't that just the ultimate joy for\n"
	.string "a TRAINER?$"

