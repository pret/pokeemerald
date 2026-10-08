Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "De BAAS werd nieuwsgierig naar\n"
	.string "het onderzoek hier,\l"
	.string "dus stuurde hij ons.\p"
	.string "Bemoei je er niet mee!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Verdraaid…\n"
	.string "Verslagen door een kind…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Onze BAAS weet alles.\p"
	.string "Maar ik ben maar een GRUNT.\n"
	.string "Wat weet ik van zijn plannen?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hè?\n"
	.string "Wat doet een kind hier?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hè?\n"
	.string "Ik verloor?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh nee…\n"
	.string "Ik krijg op mijn kop omdat ik van\l"
	.string "een kind verloor…\p"
	.string "Ik ga maar even slapen in het bed…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Terwijl ik sliep, ging iedereen\n"
	.string "naar boven!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wauw, je bent echt sterk!\p"
	.string "Ik wou dat ik een POKéMON-TRAINER\n"
	.string "was zoals jij!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "De PROFESSOR houdt van regen.\n"
	.string "Dat is een feit.\p"
	.string "Maar als het blijft regenen, krijgen\n"
	.string "mensen problemen. Ook een feit.\p"
	.string "Daarom onderzoekt de PROFESSOR\n"
	.string "of regen nuttig kan zijn.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Op de 2e verdieping van het INSTITUTE\n"
	.string "onderzoeken we het weer boven\l"
	.string "HOENN.\p"
	.string "De laatste tijd zien we hier en daar\n"
	.string "droogte en zware regen…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hallo!\n"
	.string "Jij hebt ons gered!\p"
	.string "Maar wat wilden die AQUA's nou\n"
	.string "eigenlijk?$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Er is een bed…\n"
	.string "Laten we even rusten.$"

