.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
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

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
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

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
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

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Welcome to the Oceanic Museum.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Please enjoy yourself.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? I'm sorry, but you don't seem to\n"
	.string "have enough money.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? You're with that group that\n"
	.string "went in earlier?\p"
	.string "You're the only one who's late.\n"
	.string "You'd better go catch up to them!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "We, Team Aqua, exist for the good\n"
	.string "of all!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "We were told to assemble here,\n"
	.string "so we did, but…\p"
	.string "Our Boss, the linchpin, isn't here.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "If I ripped off the stuff here,\n"
	.string "would it make me rich?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "What I learn here, I can put to use on\n"
	.string "nefarious deeds…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "If our goons didn't bungle things\n"
	.string "in Rustboro, we wouldn't be here!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "I didn't have ¥50, so it took a long\n"
	.string "time getting by the receptionist.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "I want to learn about the sea and\n"
	.string "use that knowledge for battling.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "I get all giddy and gooey when\n"
	.string "I see the sea!\p"
	.string "For me, Capt. Stern is the number\n"
	.string "one role model!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "The sea is vast without end, and\n"
	.string "infinitely deep…\p"
	.string "There must be many Pokémon that\n"
	.string "we don't know about.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "I want a sea Pokémon.\p"
	.string "I think it would feel cool and nice\n"
	.string "to hug.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh!\n"
	.string "What are you doing here?\p"
	.string "Me? I'm the Team Aqua member\n"
	.string "you thumped before, remember?\l"
	.string "Back in Rusturf Tunnel?\p"
	.string "Here, take this!\n"
	.string "You have to forgive me!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "That TM, it suits you more than it\n"
	.string "does me.\p"
	.string "Hope I never see you again!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Awww, come on!\n"
	.string "You have to take this and let me go!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "A blue fluid is spiraling inside\n"
	.string "a glass vessel.\p"
	.string "“This is an experiment to create a\n"
	.string "Whirlpool artificially using wind.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "A red ball is bobbing up and down\n"
	.string "inside a glass vessel.\p"
	.string "“This is an experiment simulating a\n"
	.string "Waterfall using the ball's buoyancy.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "It's a sample of soil from the ocean\n"
	.string "floor.\p"
	.string "“Over many years, the remains of\n"
	.string "life-forms settle at the bottom of\l"
	.string "the sea, making sedimentary layers.\p"
	.string "“By analyzing these layers, the\n"
	.string "ancient past is revealed.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "It's a sample of beach sand.\p"
	.string "“Stones from mountains are washed\n"
	.string "down by rivers where they are\l"
	.string "chipped and ground down.\p"
	.string "“They are reduced to grains and end\n"
	.string "up as sand on beaches.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“Oceanic Minifact 1\n"
	.string "Why is seawater blue?\p"
	.string "“Light is composed of many colors.\p"
	.string "“When light passes through water,\n"
	.string "most kinds of light lose color.\p"
	.string "“However, blue light retains its\n"
	.string "color, making the sea appear blue.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“Oceanic Minifact 2\n"
	.string "Why is the sea salty?\p"
	.string "“Seawater contains dissolved salt in\n"
	.string "the form of sodium and chlorine ions.\p"
	.string "“These ions leech out of rocks\n"
	.string "and are carried out to sea by rain.\p"
	.string "“The concentration of dissolved salt\n"
	.string "makes the sea salty.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“Oceanic Minifact 3\n"
	.string "Which is bigger? The sea or land?\p"
	.string "“The sea covers about 70% of\n"
	.string "the planet, and the rest is land.\p"
	.string "“The sea is therefore more than twice\n"
	.string "the size of land.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "It's a fossil with wavy ridges on it.\p"
	.string "“Soil on the ocean floor gets scoured\n"
	.string "by the tide.\p"
	.string "“The flowing seawater marks the soil\n"
	.string "with small ridges and valleys.\p"
	.string "“If this soil becomes fossilized, it is\n"
	.string "called a ripple mark.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"

