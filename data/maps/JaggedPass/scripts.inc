JaggedPass_MapScripts:: @ 8230656
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_MapScript1_230666
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_MapScript1_23069C
	.byte 0

JaggedPass_MapScript1_230666: @ 8230666
	setstepcallback 1
	compare VAR_JAGGED_PASS_STATE, 0
	call_if_eq JaggedPass_EventScript_230674
	end

JaggedPass_EventScript_230674:: @ 8230674
	checkitem ITEM_MAGMA_EMBLEM, 1
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_230685
	return

JaggedPass_EventScript_230685:: @ 8230685
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition: @ 823068B
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
	call_if_eq JaggedPass_EventScript_230697
	end

JaggedPass_EventScript_230697:: @ 8230697
	setweather WEATHER_ASH
	doweather
	return

JaggedPass_MapScript1_23069C: @ 823069C
	compare VAR_JAGGED_PASS_STATE, 1
	goto_if_le JaggedPass_EventScript_2306A8
	end

JaggedPass_EventScript_2306A8:: @ 82306A8
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, 1
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, 1
	end

JaggedPass_EventScript_2306BB:: @ 82306BB
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	msgbox JaggedPass_Text_230DBA, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 16
	setvar VAR_0x8007, 3
	special sub_8139560
	waitstate
	playse SE_KOUKA_M
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, 1
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, 0
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_230718:: @ 8230718
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_230766
	waitse
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_230CCB, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_30, JaggedPass_Text_230D2D
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_230766:: @ 8230766
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_230D65, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_230785:: @ 8230785
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_230888, JaggedPass_Text_2308FF
	msgbox JaggedPass_Text_230916, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_23079C:: @ 823079C
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_230974, JaggedPass_Text_2309B5, JaggedPass_EventScript_2307C8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_2307E4
	msgbox JaggedPass_Text_2309D8, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_2307C8:: @ 82307C8
	special sub_80B4808
	msgbox JaggedPass_Text_230A2C, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_2307E4:: @ 82307E4
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_230A76, JaggedPass_Text_230AAA
	msgbox JaggedPass_Text_230AD7, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_2307FB:: @ 82307FB
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_230B10, JaggedPass_Text_230B50, JaggedPass_EventScript_230827
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq JaggedPass_EventScript_230843
	msgbox JaggedPass_Text_230B93, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_230827:: @ 8230827
	special sub_80B4808
	msgbox JaggedPass_Text_230BC6, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_230843:: @ 8230843
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_230C28, JaggedPass_Text_230C60
	msgbox JaggedPass_Text_230C94, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_23085A:: @ 823085A
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_230DF7, JaggedPass_Text_230E38
	msgbox JaggedPass_Text_230E57, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_230871:: @ 8230871
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_230E8E, JaggedPass_Text_230ECD
	msgbox JaggedPass_Text_230EE3, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_230888: @ 8230888
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"

JaggedPass_Text_2308FF: @ 82308FF
	.string "Losing left me bitter!$"

JaggedPass_Text_230916: @ 8230916
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"

JaggedPass_Text_230974: @ 8230974
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"

JaggedPass_Text_2309B5: @ 82309B5
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"

JaggedPass_Text_2309D8: @ 82309D8
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"

JaggedPass_Text_230A2C: @ 8230A2C
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_230A76: @ 8230A76
	.string "Picnics are fun wherever you go.\n"
	.string "Just like POKéMON!$"

JaggedPass_Text_230AAA: @ 8230AAA
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"

JaggedPass_Text_230AD7: @ 8230AD7
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_230B10: @ 8230B10
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"

JaggedPass_Text_230B50: @ 8230B50
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"

JaggedPass_Text_230B93: @ 8230B93
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"

JaggedPass_Text_230BC6: @ 8230BC6
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"

JaggedPass_Text_230C28: @ 8230C28
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"

JaggedPass_Text_230C60: @ 8230C60
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"

JaggedPass_Text_230C94: @ 8230C94
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_230CCB: @ 8230CCB
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"

JaggedPass_Text_230D2D: @ 8230D2D
	.string "Urrrgh…\p"
	.string "I should've ducked into our HIDEOUT\n"
	.string "right away…$"

JaggedPass_Text_230D65: @ 8230D65
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_230DBA: @ 8230DBA
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"

JaggedPass_Text_230DF7: @ 8230DF7
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"

JaggedPass_Text_230E38: @ 8230E38
	.string "I feel like I'm falling apart…$"

JaggedPass_Text_230E57: @ 8230E57
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"

JaggedPass_Text_230E8E: @ 8230E8E
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"

JaggedPass_Text_230ECD: @ 8230ECD
	.string "Hmm…\n"
	.string "What went wrong?$"

JaggedPass_Text_230EE3: @ 8230EE3
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"

