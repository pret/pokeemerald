Route119_WeatherInstitute_2F_MapScripts:: @ 826FF1E
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition: @ 826FF24
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF44
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF50
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_26FF5C
	end

Route119_WeatherInstitute_2F_EventScript_26FF44:: @ 826FF44
	setobjectxyperm 5, 1, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF50:: @ 826FF50
	setobjectxyperm 5, 4, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF5C:: @ 826FF5C
	setobjectxyperm 5, 2, 2
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_26FF68:: @ 826FF68
	trainerbattle_single TRAINER_GRUNT_37, Route119_WeatherInstitute_2F_Text_270335, Route119_WeatherInstitute_2F_Text_27039F
	msgbox Route119_WeatherInstitute_2F_Text_2703C0, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FF7F:: @ 826FF7F
	trainerbattle_single TRAINER_GRUNT_12, Route119_WeatherInstitute_2F_Text_27019C, Route119_WeatherInstitute_2F_Text_270208
	msgbox Route119_WeatherInstitute_2F_Text_27022B, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FF96:: @ 826FF96
	trainerbattle_single TRAINER_GRUNT_13, Route119_WeatherInstitute_2F_Text_270292, Route119_WeatherInstitute_2F_Text_2702CE
	msgbox Route119_WeatherInstitute_2F_Text_2702DA, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FFAD:: @ 826FFAD
	trainerbattle_single TRAINER_SHELLY_1, Route119_WeatherInstitute_2F_Text_270409, Route119_WeatherInstitute_2F_Text_2704BD, Route119_WeatherInstitute_2F_EventScript_26FFC8
	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_26FFC8:: @ 826FFC8
	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_DEFAULT
	closemessage
	addobject 7
	applymovement 7, Route119_WeatherInstitute_2F_Movement_270170
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_27017C
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_270568, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_2705DD, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen 1
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 8
	removeobject 7
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_270184
	waitmovement 0
	fadescreen 0
	applymovement 5, Route119_WeatherInstitute_2F_Movement_270187
	waitmovement 0
	copyobjectxytoperm 5
	goto Route119_WeatherInstitute_2F_EventScript_27004D
	end

Route119_WeatherInstitute_2F_EventScript_27004D:: @ 827004D
	msgbox Route119_WeatherInstitute_2F_Text_270650, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_270085
	compare VAR_RESULT, 1
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700AD
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_270085:: @ 8270085
	call Route119_WeatherInstitute_2F_EventScript_2700DB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700EA
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_2700EA
	end

Route119_WeatherInstitute_2F_EventScript_2700AD:: @ 82700AD
	call Route119_WeatherInstitute_2F_EventScript_2700DB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700D0
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_2700D0
	end

Route119_WeatherInstitute_2F_EventScript_2700D0:: @ 82700D0
	call Route119_WeatherInstitute_2F_EventScript_2737A0
	goto Route119_WeatherInstitute_2F_EventScript_2700EA
	end

Route119_WeatherInstitute_2F_EventScript_2700DB:: @ 82700DB
	playfanfare MUS_FANFA4
	message Route119_WeatherInstitute_2F_Text_2706E8
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_2700EA:: @ 82700EA
	msgbox Route119_WeatherInstitute_2F_Text_2706FE, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_2700F7:: @ 82700F7
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather
	msgbox Route119_WeatherInstitute_2F_Text_27077E, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather:: @ 827010A
    @ This code uses VAR_0x8004 to count the number of legendaries the player has defeated
    @ already.
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	call_if_set FLAG_DEFEATED_GROUDON, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	compare VAR_0x8004, 2
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated
	call_if_unset FLAG_TEMP_2, WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather
	specialvar VAR_RESULT, GetUnusualWeatherMapNameAndType
	compare VAR_RESULT, 1
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage
	msgbox WeatherInstitute_UnusualWeather_GroudonWeatherText, MSGBOX_DEFAULT
	release
	end

WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage:: @ 827014F
	msgbox WeatherInstitute_UnusualWeather_KyogreWeatherText, MSGBOX_DEFAULT
	release
	end

WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather:: @ 8270159
	special CreateUnusualWeatherEvent
	setflag FLAG_TEMP_2
	return

WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount:: @ 8270160
	addvar VAR_0x8004, 1
	return

WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated:: @ 8270166
	msgbox WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_270170: @ 8270170
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_27017C: @ 827017C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_fastest_down
	step_end

Route119_WeatherInstitute_2F_Movement_270184: @ 8270184
	slide_down
	walk_in_place_fastest_left
	step_end

Route119_WeatherInstitute_2F_Movement_270187: @ 8270187
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_27018B:: @ 827018B
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_2700F7
	goto Route119_WeatherInstitute_2F_EventScript_27004D
	end

Route119_WeatherInstitute_2F_Text_27019C: @ 827019C
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_270208: @ 8270208
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_27022B: @ 827022B
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"

Route119_WeatherInstitute_2F_Text_270292: @ 8270292
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"

Route119_WeatherInstitute_2F_Text_2702CE: @ 82702CE
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_2702DA: @ 82702DA
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_270335: @ 8270335
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_27039F: @ 827039F
	.string "Oh, will you look at my POKéMON?$"

Route119_WeatherInstitute_2F_Text_2703C0: @ 82703C0
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_270409: @ 8270409
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_2704BD: @ 82704BD
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_2704E4: @ 82704E4
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_270568: @ 8270568
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_2705DD: @ 82705DD
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"

Route119_WeatherInstitute_2F_Text_270650: @ 8270650
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

Route119_WeatherInstitute_2F_Text_2706B2: @ 82706B2
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"

Route119_WeatherInstitute_2F_Text_2706E8: @ 82706E8
	.string "{PLAYER} received CASTFORM!$"

Route119_WeatherInstitute_2F_Text_2706FE: @ 82706FE
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_27077E: @ 827077E
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

WeatherInstitute_UnusualWeather_GroudonWeatherText: @ 82707F1
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

WeatherInstitute_UnusualWeather_KyogreWeatherText: @ 8270873
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText: @ 82708FC
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

