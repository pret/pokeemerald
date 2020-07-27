.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts:: @ 826FA86
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition: @ 826FA8C
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos:: @ 826FA98
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy:: @ 826FAA4
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere:: @ 826FABE
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1:: @ 826FAC8
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	compare VAR_0x8004, 2  @ Both defeated
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_StudyingRain
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated:: @ 826FAFF
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain:: @ 826FB05
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2:: @ 826FB0F
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed:: @ 826FB18
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1:: @ 826FB29
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4:: @ 826FB40
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro: @ 826FB57
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat: @ 826FBBB
	.string "Blast it…\n"
	.string "Blasted by a kid…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle: @ 826FBD7
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro: @ 826FC34
	.string "Huh?\n"
	.string "What's a kid doing here?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat: @ 826FC52
	.string "Huh?\n"
	.string "I lost?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle: @ 826FC60
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs: @ 826FCB7
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong: @ 826FCE5
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain: @ 826FD2E
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather: @ 826FDE8
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo: @ 826FE94
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed: @ 826FEFC
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

