.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts:: @ 8230656
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume: @ 8230666
	setstepcallback STEP_CB_ASH
	compare VAR_JAGGED_PASS_STATE, 0
	call_if_eq JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem:: @ 8230674
	checkitem ITEM_MAGMA_EMBLEM, 1
	compare VAR_RESULT, TRUE
	goto_if_eq JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout:: @ 8230685
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition: @ 823068B
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
	call_if_eq JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh:: @ 8230697
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad: @ 823069C
	compare VAR_JAGGED_PASS_STATE, 1
	goto_if_le JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance:: @ 82306A8
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, 1
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, 1
	end

JaggedPass_EventScript_OpenMagmaHideout:: @ 82306BB
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, 1
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, 0
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard:: @ 8230718
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated:: @ 8230766
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric:: @ 8230785
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana:: @ 823079C
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana:: @ 82307C8
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch:: @ 82307E4
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan:: @ 82307FB
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan:: @ 8230827
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch:: @ 8230843
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio:: @ 823085A
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn:: @ 8230871
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro: @ 8230888
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"

JaggedPass_Text_EricDefeat: @ 82308FF
	.string "Losing left me bitter!$"

JaggedPass_Text_EricPostBattle: @ 8230916
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"

JaggedPass_Text_DianaIntro: @ 8230974
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"

JaggedPass_Text_DianaDefeat: @ 82309B5
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"

JaggedPass_Text_DianaPostBattle: @ 82309D8
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"

JaggedPass_Text_DianaRegister: @ 8230A2C
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_DianaRematchIntro: @ 8230A76
	.string "Picnics are fun wherever you go.\n"
	.string "Just like POKéMON!$"

JaggedPass_Text_DianaRematchDefeat: @ 8230AAA
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"

JaggedPass_Text_DianaPostRematch: @ 8230AD7
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_EthanIntro: @ 8230B10
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"

JaggedPass_Text_EthanDefeat: @ 8230B50
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"

JaggedPass_Text_EthanPostBattle: @ 8230B93
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"

JaggedPass_Text_EthanRegister: @ 8230BC6
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"

JaggedPass_Text_EthanRematchIntro: @ 8230C28
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"

JaggedPass_Text_EthanRematchDefeat: @ 8230C60
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"

JaggedPass_Text_EthanPostRematch: @ 8230C94
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_GruntIntro: @ 8230CCB
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"

JaggedPass_Text_GruntDefeat: @ 8230D2D
	.string "Urrrgh…\p"
	.string "I should've ducked into our HIDEOUT\n"
	.string "right away…$"

JaggedPass_Text_GoWhereverYouWant: @ 8230D65
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem: @ 8230DBA
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro: @ 8230DF7
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"

JaggedPass_Text_JulioDefeat: @ 8230E38
	.string "I feel like I'm falling apart…$"

JaggedPass_Text_JulioPostBattle: @ 8230E57
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"

JaggedPass_Text_AutumnIntro: @ 8230E8E
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"

JaggedPass_Text_AutumnDefeat: @ 8230ECD
	.string "Hmm…\n"
	.string "What went wrong?$"

JaggedPass_Text_AutumnPostBattle: @ 8230EE3
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"

