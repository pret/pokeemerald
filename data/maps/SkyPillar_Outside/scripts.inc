SkyPillar_Outside_MapScripts:: @ 82392A8
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_MapScript1_2392DD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_MapScript2_2392FA
	.byte 0

SkyPillar_Outside_OnTransition: @ 82392B8
	compare VAR_RAYQUAZA_STATE, 3
	call_if_eq SkyPillar_Outside_EventScript_2392CF
	compare VAR_RAYQUAZA_STATE, 4
	call_if_ge SkyPillar_Outside_EventScript_2392D3
	end

SkyPillar_Outside_EventScript_2392CF:: @ 82392CF
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SkyPillar_Outside_EventScript_2392D3:: @ 82392D3
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	return

SkyPillar_Outside_MapScript1_2392DD: @ 82392DD
	call_if_set FLAG_WALLACE_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_2392E7
	end

SkyPillar_Outside_EventScript_2392E7:: @ 82392E7
	setmetatile 14, 4, 682, 0
	setmetatile 14, 5, 690, 0
	return

SkyPillar_Outside_MapScript2_2392FA: @ 82392FA
	map_script_2 VAR_RAYQUAZA_STATE, 3, SkyPillar_Outside_EventScript_239304
	.2byte 0

SkyPillar_Outside_EventScript_239304:: @ 8239304
	lockall
	applymovement 1, SkyPillar_Outside_Movement_2393D3
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox SkyPillar_Outside_Text_239416, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special sub_8139560
	waitstate
	delay 40
	msgbox SkyPillar_Outside_Text_2394BC, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, SkyPillar_Outside_Movement_2393EB
	applymovement 1, SkyPillar_Outside_Movement_2393DE
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox SkyPillar_Outside_Text_23950C, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ALTERNATING
	doweather
	special WaitWeather
	waitstate
	delay 30
	msgbox SkyPillar_Outside_Text_23953A, MSGBOX_DEFAULT
	closemessage
	playse SE_KAIDAN
	fadescreenswapbuffers 1
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_RAYQUAZA_STATE, 4
	removeobject 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	fadescreenswapbuffers 0
	releaseall
	end

SkyPillar_Outside_Movement_2393D3: @ 82393D3
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SkyPillar_Outside_Movement_2393DE: @ 82393DE
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_Movement_2393EB: @ 82393EB
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_EventScript_2393F8:: @ 82393F8
	end

SkyPillar_Outside_EventScript_2393F9:: @ 82393F9
	msgbox SkyPillar_Outside_Text_239402, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_239402: @ 8239402
	.string "The door is closed.$"

SkyPillar_Outside_Text_239416: @ 8239416
	.string "WALLACE: Oh, my, I'm terribly sorry!\p"
	.string "In my haste, I didn't notice that\n"
	.string "I'd left you behind!\p"
	.string "I've opened the locked door of\n"
	.string "the SKY PILLAR.\p"
	.string "{PLAYER}{KUN}, let's be on our way!$"

SkyPillar_Outside_Text_2394BC: @ 82394BC
	.string "WALLACE: It's an earthquake!\p"
	.string "There's not a moment to waste!\n"
	.string "We've got to hurry!$"

SkyPillar_Outside_Text_23950C: @ 823950C
	.string "WALLACE: Hmm…\n"
	.string "The situation is getting worse…$"

SkyPillar_Outside_Text_23953A: @ 823953A
	.string "WALLACE: This isn't good…\p"
	.string "The weather distortion is spreading\n"
	.string "even here…\p"
	.string "{PLAYER}{KUN}.\p"
	.string "RAYQUAZA should be farther up\n"
	.string "from here.\p"
	.string "I'm worried about SOOTOPOLIS.\n"
	.string "I've got to go back.\p"
	.string "Everything is in your hands now.\n"
	.string "Don't fail us!$"
