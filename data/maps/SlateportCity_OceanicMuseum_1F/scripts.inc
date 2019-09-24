SlateportCity_OceanicMuseum_1F_MapScripts:: @ 820AD95
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_20AD96:: @ 820AD96
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AD9F:: @ 820AD9F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20ADC1
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADB0:: @ 820ADB0
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20ADC1
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADC1:: @ 820ADC1
	showmoneybox 0, 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20AFD5, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20ADE8
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AE4B
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20ADE8:: @ 820ADE8
	checkmoney 50, 0
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AE18
	playse SE_REGI
	takemoney 50, 0
	updatemoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	nop
	nop
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE18:: @ 820AE18
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_20AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B03D, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AE4B
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE39:: @ 820AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B075, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	nop
	nop
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_20AE4B: @ 820AE4B
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_20AE4D:: @ 820AE4D
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B0E8, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE56:: @ 820AE56
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B112, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE5F:: @ 820AE5F
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B165, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE68:: @ 820AE68
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B19C, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE71:: @ 820AE71
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B1D4, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE7A:: @ 820AE7A
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B218, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE83:: @ 820AE83
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B4CF, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE8C:: @ 820AE8C
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B547, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE95:: @ 820AE95
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B5CA, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AE9E:: @ 820AE9E
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B699, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEA7:: @ 820AEA7
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B74B, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEB0:: @ 820AEB0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B81F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEB9:: @ 820AEB9
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B912, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEC2:: @ 820AEC2
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B9C0, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AECB:: @ 820AECB
	msgbox SlateportCity_OceanicMuseum_1F_Text_20BA9C, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AED4:: @ 820AED4
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B25F, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEDD:: @ 820AEDD
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B2A2, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEE6:: @ 820AEE6
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B302, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEEF:: @ 820AEEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B369, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AEF8:: @ 820AEF8
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement 13, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 13, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B3AB, MSGBOX_DEFAULT
	giveitem_std ITEM_TM46
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AFB5
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B449, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF6C
	compare VAR_FACING, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF83
	compare VAR_FACING, 3
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF93
	compare VAR_FACING, 4
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AF93
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF6C:: @ 820AF6C
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AFBF
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFCE
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF83:: @ 820AF83
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFC7
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AF93:: @ 820AF93
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_20AFC4
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_20AFC7
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_20AFAA
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AFAA:: @ 820AFAA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_KAIDAN
	removeobject 13
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_20AFB5:: @ 820AFB5
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B49B, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_20AFBF: @ 820AFBF
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFC4: @ 820AFC4
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFC7: @ 820AFC7
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_20AFCE: @ 820AFCE
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_20AFD5: @ 820AFD5
	.string "Welcome to the OCEANIC MUSEUM.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"

SlateportCity_OceanicMuseum_1F_Text_20B026: @ 820B026
	.string "Please enjoy yourself.$"

SlateportCity_OceanicMuseum_1F_Text_20B03D: @ 820B03D
	.string "Oh? I'm sorry, but you don't seem to\n"
	.string "have enough money.$"

SlateportCity_OceanicMuseum_1F_Text_20B075: @ 820B075
	.string "Oh? You're with that group that\n"
	.string "went in earlier?\p"
	.string "You're the only one who's late.\n"
	.string "You'd better go catch up to them!$"

SlateportCity_OceanicMuseum_1F_Text_20B0E8: @ 820B0E8
	.string "We, TEAM AQUA, exist for the good\n"
	.string "of all!$"

SlateportCity_OceanicMuseum_1F_Text_20B112: @ 820B112
	.string "We were told to assemble here,\n"
	.string "so we did, but…\p"
	.string "Our BOSS, the linchpin, isn't here.$"

SlateportCity_OceanicMuseum_1F_Text_20B165: @ 820B165
	.string "If I ripped off the stuff here,\n"
	.string "would it make me rich?$"

SlateportCity_OceanicMuseum_1F_Text_20B19C: @ 820B19C
	.string "What I learn here, I can put to use on\n"
	.string "nefarious deeds…$"

SlateportCity_OceanicMuseum_1F_Text_20B1D4: @ 820B1D4
	.string "If our goons didn't bungle things\n"
	.string "in RUSTBORO, we wouldn't be here!$"

SlateportCity_OceanicMuseum_1F_Text_20B218: @ 820B218
	.string "I didn't have ¥50, so it took a long\n"
	.string "time getting by the receptionist.$"

SlateportCity_OceanicMuseum_1F_Text_20B25F: @ 820B25F
	.string "I want to learn about the sea and\n"
	.string "use that knowledge for battling.$"

SlateportCity_OceanicMuseum_1F_Text_20B2A2: @ 820B2A2
	.string "I get all giddy and gooey when\n"
	.string "I see the sea!\p"
	.string "For me, CAPT. STERN is the number\n"
	.string "one role model!$"

SlateportCity_OceanicMuseum_1F_Text_20B302: @ 820B302
	.string "The sea is vast without end, and\n"
	.string "infinitely deep…\p"
	.string "There must be many POKéMON that\n"
	.string "we don't know about.$"

SlateportCity_OceanicMuseum_1F_Text_20B369: @ 820B369
	.string "I want a sea POKéMON.\p"
	.string "I think it would feel cool and nice\n"
	.string "to hug.$"

SlateportCity_OceanicMuseum_1F_Text_20B3AB: @ 820B3AB
	.string "Aiyeeeh!\n"
	.string "What are you doing here?\p"
	.string "Me? I'm the TEAM AQUA member\n"
	.string "you thumped before, remember?\l"
	.string "Back in RUSTURF TUNNEL?\p"
	.string "Here, take this!\n"
	.string "You have to forgive me!$"

SlateportCity_OceanicMuseum_1F_Text_20B449: @ 820B449
	.string "That TM, it suits you more than it\n"
	.string "does me.\p"
	.string "Hope I never see you again!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_20B49B: @ 820B49B
	.string "Awww, come on!\n"
	.string "You have to take this and let me go!$"

SlateportCity_OceanicMuseum_1F_Text_20B4CF: @ 820B4CF
	.string "A blue fluid is spiraling inside\n"
	.string "a glass vessel.\p"
	.string "“This is an experiment to create a\n"
	.string "WHIRLPOOL artificially using wind.”$"

SlateportCity_OceanicMuseum_1F_Text_20B547: @ 820B547
	.string "A red ball is bobbing up and down\n"
	.string "inside a glass vessel.\p"
	.string "“This is an experiment simulating a\n"
	.string "WATERFALL using the ball's buoyancy.”$"

SlateportCity_OceanicMuseum_1F_Text_20B5CA: @ 820B5CA
	.string "It's a sample of soil from the ocean\n"
	.string "floor.\p"
	.string "“Over many years, the remains of\n"
	.string "life-forms settle at the bottom of\l"
	.string "the sea, making sedimentary layers.\p"
	.string "“By analyzing these layers, the\n"
	.string "ancient past is revealed.”$"

SlateportCity_OceanicMuseum_1F_Text_20B699: @ 820B699
	.string "It's a sample of beach sand.\p"
	.string "“Stones from mountains are washed\n"
	.string "down by rivers where they are\l"
	.string "chipped and ground down.\p"
	.string "“They are reduced to grains and end\n"
	.string "up as sand on beaches.”$"

SlateportCity_OceanicMuseum_1F_Text_20B74B: @ 820B74B
	.string "“OCEANIC MINIFACT 1\n"
	.string "Why is seawater blue?\p"
	.string "“Light is composed of many colors.\p"
	.string "“When light passes through water,\n"
	.string "most kinds of light lose color.\p"
	.string "“However, blue light retains its\n"
	.string "color, making the sea appear blue.”$"

SlateportCity_OceanicMuseum_1F_Text_20B81F: @ 820B81F
	.string "“OCEANIC MINIFACT 2\n"
	.string "Why is the sea salty?\p"
	.string "“Seawater contains dissolved salt in\n"
	.string "the form of sodium and chlorine ions.\p"
	.string "“These ions leech out of rocks\n"
	.string "and are carried out to sea by rain.\p"
	.string "“The concentration of dissolved salt\n"
	.string "makes the sea salty.”$"

SlateportCity_OceanicMuseum_1F_Text_20B912: @ 820B912
	.string "“OCEANIC MINIFACT 3\n"
	.string "Which is bigger? The sea or land?\p"
	.string "“The sea covers about 70% of\n"
	.string "the planet, and the rest is land.\p"
	.string "“The sea is therefore more than twice\n"
	.string "the size of land.”$"

SlateportCity_OceanicMuseum_1F_Text_20B9C0: @ 820B9C0
	.string "It's a fossil with wavy ridges on it.\p"
	.string "“Soil on the ocean floor gets scoured\n"
	.string "by the tide.\p"
	.string "“The flowing seawater marks the soil\n"
	.string "with small ridges and valleys.\p"
	.string "“If this soil becomes fossilized, it is\n"
	.string "called a ripple mark.”$"

SlateportCity_OceanicMuseum_1F_Text_20BA9C: @ 820BA9C
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"

