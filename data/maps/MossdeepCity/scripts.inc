MossdeepCity_MapScripts:: @ 81E4A96
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition: @ 81E4A9C
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	end

MossdeepCity_EventScript_1E4AB2:: @ 81E4AB2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_1E4AC7
	msgbox MossdeepCity_Text_1E4E90, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AC7:: @ 81E4AC7
	msgbox MossdeepCity_Text_1E4F15, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AD1:: @ 81E4AD1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_1E4AE6
	msgbox MossdeepCity_Text_1E4F50, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AE6:: @ 81E4AE6
	msgbox MossdeepCity_Text_1E5051, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4AF0:: @ 81E4AF0
	msgbox MossdeepCity_Text_1E4E22, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4AF9:: @ 81E4AF9
	msgbox MossdeepCity_Text_1E5135, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B02:: @ 81E4B02
	msgbox MossdeepCity_Text_1E50D9, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B0B:: @ 81E4B0B
	msgbox MossdeepCity_Text_1E529D, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4B14:: @ 81E4B14
	msgbox MossdeepCity_Text_1E5396, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B1D:: @ 81E4B1D
	msgbox MossdeepCity_Text_1E53A9, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B26:: @ 81E4B26
	msgbox MossdeepCity_Text_1E53F2, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B2F:: @ 81E4B2F
	msgbox MossdeepCity_Text_1E541F, MSGBOX_SIGN
	end

MossdeepCity_EventScript_1E4B38:: @ 81E4B38
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_1E4B41:: @ 81E4B41
	lockall
	applymovement 14, MossdeepCity_Movement_1E4BAD
	waitmovement 0
	applymovement 10, MossdeepCity_Movement_1E4BB7
	applymovement 11, MossdeepCity_Movement_1E4BB7
	applymovement 12, MossdeepCity_Movement_1E4BB7
	applymovement 13, MossdeepCity_Movement_1E4BB7
	waitmovement 0
	applymovement 14, MossdeepCity_Movement_1E4BBC
	applymovement 10, MossdeepCity_Movement_1E4BCA
	applymovement 11, MossdeepCity_Movement_1E4BDD
	applymovement 12, MossdeepCity_Movement_1E4BEF
	applymovement 13, MossdeepCity_Movement_1E4C00
	waitmovement 0
	removeobject 14
	removeobject 10
	removeobject 11
	removeobject 12
	removeobject 13
	delay 30
	setvar VAR_MOSSDEEP_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_1E4BAD: @ 81E4BAD
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_1E4BB7: @ 81E4BB7
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_1E4BBC: @ 81E4BBC
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BCA: @ 81E4BCA
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BDD: @ 81E4BDD
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4BEF: @ 81E4BEF
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_1E4C00: @ 81E4C00
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_1E4C10:: @ 81E4C10
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5213, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_1E4C26:: @ 81E4C26
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_1E4C68
	msgbox MossdeepCity_Text_1E4CED, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_EventScript_1E4C72
	msgbox MossdeepCity_Text_1E4D5B, MSGBOX_DEFAULT
	giveitem_std ITEM_KINGS_ROCK
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_1E4C68:: @ 81E4C68
	msgbox MossdeepCity_Text_1E4DB3, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4C72:: @ 81E4C72
	msgbox MossdeepCity_Text_1E4DD7, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_1E4C7C:: @ 81E4C7C
	msgbox MossdeepCity_Text_1E5581, MSGBOX_NPC
	end

MossdeepCity_EventScript_1E4C85:: @ 81E4C85
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5453, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq MossdeepCity_EventScript_1E4CB0
	compare VAR_FACING, 4
	call_if_eq MossdeepCity_EventScript_1E4CC2
	addvar VAR_SCOTT_STATE, 1
	removeobject 16
	release
	end

MossdeepCity_EventScript_1E4CB0:: @ 81E4CB0
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_1E4CD4
	applymovement 16, MossdeepCity_Movement_1E4CD8
	waitmovement 0
	return

MossdeepCity_EventScript_1E4CC2:: @ 81E4CC2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_1E4CD4
	applymovement 16, MossdeepCity_Movement_1E4CE2
	waitmovement 0
	return

MossdeepCity_Movement_1E4CD4: @ 81E4CD4
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MossdeepCity_Movement_1E4CD8: @ 81E4CD8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_1E4CE2: @ 81E4CE2
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_1E4CED: @ 81E4CED
	.string "I got this from STEVEN, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called KING'S ROCK.\n"
	.string "Do you want it?$"

MossdeepCity_Text_1E4D5B: @ 81E4D5B
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"

MossdeepCity_Text_1E4DB3: @ 81E4DB3
	.string "STEVEN's house is right over there!$"

MossdeepCity_Text_1E4DD7: @ 81E4DD7
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_1E4E22: @ 81E4E22
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"

MossdeepCity_Text_1E4E90: @ 81E4E90
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_1E4F15: @ 81E4F15
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_1E4F50: @ 81E4F50
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"

MossdeepCity_Text_1E5051: @ 81E5051
	.string "I'm a SAILOR, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_1E50D9: @ 81E50D9
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_1E5135: @ 81E5135
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"

MossdeepCity_Text_1E5213: @ 81E5213
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with POKéMON\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_1E529D: @ 81E529D
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_1E5396: @ 81E5396
	.string "It's a white rock.$"

MossdeepCity_Text_1E53A9: @ 81E53A9
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"

MossdeepCity_Text_1E53F2: @ 81E53F2
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish POKéMON!”$"

MossdeepCity_Text_1E541F: @ 81E541F
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_1E5453: @ 81E5453
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_1E5581: @ 81E5581
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city SOOTOPOLIS?\p"
	.string "I think the GYM there had a new\n"
	.string "LEADER come in.\p"
	.string "People tell me the new LEADER once\n"
	.string "mentored WALLACE.$"

