Route119_WeatherInstitute_1F_MapScripts:: @ 826FA86
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition: @ 826FA8C
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_26FA98
	end

Route119_WeatherInstitute_1F_EventScript_26FA98:: @ 826FA98
	setobjectxyperm 5, 0, 5
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_26FAA4:: @ 826FAA4
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FABE
	msgbox Route119_WeatherInstitute_1F_Text_26FCE5, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FABE:: @ 826FABE
	msgbox Route119_WeatherInstitute_1F_Text_26FCB7, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FAC8:: @ 826FAC8
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_26FB05
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_26FAFF
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_26FAFF
	compare VAR_0x8004, 2
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_26FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FDE8, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FAFF:: @ 826FAFF
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_26FB05:: @ 826FB05
	msgbox Route119_WeatherInstitute_1F_Text_26FD2E, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_26FB0F:: @ 826FB0F
	msgbox Route119_WeatherInstitute_1F_Text_26FE94, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_26FB18:: @ 826FB18
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_26FEFC, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_26FB29:: @ 826FB29
	trainerbattle_single TRAINER_GRUNT_11, Route119_WeatherInstitute_1F_Text_26FB57, Route119_WeatherInstitute_1F_Text_26FBBB
	msgbox Route119_WeatherInstitute_1F_Text_26FBD7, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_26FB40:: @ 826FB40
	trainerbattle_single TRAINER_GRUNT_20, Route119_WeatherInstitute_1F_Text_26FC34, Route119_WeatherInstitute_1F_Text_26FC52
	msgbox Route119_WeatherInstitute_1F_Text_26FC60, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_26FB57: @ 826FB57
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"

Route119_WeatherInstitute_1F_Text_26FBBB: @ 826FBBB
	.string "Blast it…\n"
	.string "Blasted by a kid…$"

Route119_WeatherInstitute_1F_Text_26FBD7: @ 826FBD7
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"

Route119_WeatherInstitute_1F_Text_26FC34: @ 826FC34
	.string "Huh?\n"
	.string "What's a kid doing here?$"

Route119_WeatherInstitute_1F_Text_26FC52: @ 826FC52
	.string "Huh?\n"
	.string "I lost?!$"

Route119_WeatherInstitute_1F_Text_26FC60: @ 826FC60
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"

Route119_WeatherInstitute_1F_Text_26FCB7: @ 826FCB7
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_26FCE5: @ 826FCE5
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"

Route119_WeatherInstitute_1F_Text_26FD2E: @ 826FD2E
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"

Route119_WeatherInstitute_1F_Text_26FDE8: @ 826FDE8
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"

Route119_WeatherInstitute_1F_Text_26FE94: @ 826FE94
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_26FEFC: @ 826FEFC
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

