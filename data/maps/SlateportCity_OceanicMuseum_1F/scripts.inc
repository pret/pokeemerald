.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts:: @ 820AD95
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant:: @ 820AD96
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft:: @ 820AD9F
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight:: @ 820ADB0
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee:: @ 820ADC1
	showmoneybox 0, 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee:: @ 820ADE8
	checkmoney 50, 0
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50, 0
	updatemoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney:: @ 820AE18
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway:: @ 820AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter: @ 820AE4B
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1:: @ 820AE4D
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2:: @ 820AE56
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3:: @ 820AE5F
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4:: @ 820AE68
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5:: @ 820AE71
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6:: @ 820AE7A
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment:: @ 820AE83
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment:: @ 820AE8C
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay:: @ 820AE95
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay:: @ 820AE9E
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1:: @ 820AEA7
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2:: @ 820AEB0
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3:: @ 820AEB9
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay:: @ 820AEC2
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine:: @ 820AECB
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1:: @ 820AED4
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2:: @ 820AEDD
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3:: @ 820AEE6
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4:: @ 820AEEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt:: @ 820AEF8
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM46
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	compare VAR_FACING, DIR_WEST
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	compare VAR_FACING, DIR_EAST
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth:: @ 820AF6C
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth:: @ 820AF83
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast:: @ 820AF93
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited:: @ 820AFAA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief:: @ 820AFB5
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth: @ 820AFBF
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast: @ 820AFC4
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit: @ 820AFC7
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth: @ 820AFCE
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter: @ 820AFD5
	.string "Welcome to the OCEANIC MUSEUM.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself: @ 820B026
	.string "Please enjoy yourself.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney: @ 820B03D
	.string "Oh? I'm sorry, but you don't seem to\n"
	.string "have enough money.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup: @ 820B075
	.string "Oh? You're with that group that\n"
	.string "went in earlier?\p"
	.string "You're the only one who's late.\n"
	.string "You'd better go catch up to them!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll: @ 820B0E8
	.string "We, TEAM AQUA, exist for the good\n"
	.string "of all!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere: @ 820B112
	.string "We were told to assemble here,\n"
	.string "so we did, but…\p"
	.string "Our BOSS, the linchpin, isn't here.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich: @ 820B165
	.string "If I ripped off the stuff here,\n"
	.string "would it make me rich?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds: @ 820B19C
	.string "What I learn here, I can put to use on\n"
	.string "nefarious deeds…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled: @ 820B1D4
	.string "If our goons didn't bungle things\n"
	.string "in RUSTBORO, we wouldn't be here!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney: @ 820B218
	.string "I didn't have ¥50, so it took a long\n"
	.string "time getting by the receptionist.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling: @ 820B25F
	.string "I want to learn about the sea and\n"
	.string "use that knowledge for battling.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel: @ 820B2A2
	.string "I get all giddy and gooey when\n"
	.string "I see the sea!\p"
	.string "For me, CAPT. STERN is the number\n"
	.string "one role model!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow: @ 820B302
	.string "The sea is vast without end, and\n"
	.string "infinitely deep…\p"
	.string "There must be many POKéMON that\n"
	.string "we don't know about.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon: @ 820B369
	.string "I want a sea POKéMON.\p"
	.string "I think it would feel cool and nice\n"
	.string "to hug.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis: @ 820B3AB
	.string "Aiyeeeh!\n"
	.string "What are you doing here?\p"
	.string "Me? I'm the TEAM AQUA member\n"
	.string "you thumped before, remember?\l"
	.string "Back in RUSTURF TUNNEL?\p"
	.string "Here, take this!\n"
	.string "You have to forgive me!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain: @ 820B449
	.string "That TM, it suits you more than it\n"
	.string "does me.\p"
	.string "Hope I never see you again!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis: @ 820B49B
	.string "Awww, come on!\n"
	.string "You have to take this and let me go!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment: @ 820B4CF
	.string "A blue fluid is spiraling inside\n"
	.string "a glass vessel.\p"
	.string "“This is an experiment to create a\n"
	.string "WHIRLPOOL artificially using wind.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment: @ 820B547
	.string "A red ball is bobbing up and down\n"
	.string "inside a glass vessel.\p"
	.string "“This is an experiment simulating a\n"
	.string "WATERFALL using the ball's buoyancy.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay: @ 820B5CA
	.string "It's a sample of soil from the ocean\n"
	.string "floor.\p"
	.string "“Over many years, the remains of\n"
	.string "life-forms settle at the bottom of\l"
	.string "the sea, making sedimentary layers.\p"
	.string "“By analyzing these layers, the\n"
	.string "ancient past is revealed.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay: @ 820B699
	.string "It's a sample of beach sand.\p"
	.string "“Stones from mountains are washed\n"
	.string "down by rivers where they are\l"
	.string "chipped and ground down.\p"
	.string "“They are reduced to grains and end\n"
	.string "up as sand on beaches.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1: @ 820B74B
	.string "“OCEANIC MINIFACT 1\n"
	.string "Why is seawater blue?\p"
	.string "“Light is composed of many colors.\p"
	.string "“When light passes through water,\n"
	.string "most kinds of light lose color.\p"
	.string "“However, blue light retains its\n"
	.string "color, making the sea appear blue.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2: @ 820B81F
	.string "“OCEANIC MINIFACT 2\n"
	.string "Why is the sea salty?\p"
	.string "“Seawater contains dissolved salt in\n"
	.string "the form of sodium and chlorine ions.\p"
	.string "“These ions leech out of rocks\n"
	.string "and are carried out to sea by rain.\p"
	.string "“The concentration of dissolved salt\n"
	.string "makes the sea salty.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3: @ 820B912
	.string "“OCEANIC MINIFACT 3\n"
	.string "Which is bigger? The sea or land?\p"
	.string "“The sea covers about 70% of\n"
	.string "the planet, and the rest is land.\p"
	.string "“The sea is therefore more than twice\n"
	.string "the size of land.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay: @ 820B9C0
	.string "It's a fossil with wavy ridges on it.\p"
	.string "“Soil on the ocean floor gets scoured\n"
	.string "by the tide.\p"
	.string "“The flowing seawater marks the soil\n"
	.string "with small ridges and valleys.\p"
	.string "“If this soil becomes fossilized, it is\n"
	.string "called a ripple mark.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine: @ 820BA9C
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"

