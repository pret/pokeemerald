SixIsland_WaterPath_House1_Frlg_MapScripts::
	.byte 0

SixIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, SixIsland_WaterPath_House1_EventScript_DontShowMon
	special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, SixIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox SixIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeYSizeWasBiggest
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeSameAsBefore
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox SixIsland_WaterPath_House1_Text_ItsXSizeDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox SixIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

SixIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXSize
	releaseall
	end

SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
	.string "Hera, hera, HERACROSS!\n"
	.string "Big and shiny, it's the bug boss!\l"
	.string "Love it, need it, HERACROSS!$"

SixIsland_WaterPath_House1_Text_MayIMeasureHeracross::
	.string "Eeeeek!\n"
	.string "That's a HERACROSS!\p"
	.string "Please, please, may I measure how\n"
	.string "big it is?$"

SixIsland_WaterPath_House1_Text_ItsXSizeDeserveReward::
	.string "Eeeek, it's {STR_VAR_2}!\n"
	.string "I've never seen anything like this!\l"
	.string "You deserve a reward!$"

SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
	.string "I want to see a much, much bigger\n"
	.string "HERACROSS than that one.\p"
	.string "Oh, how I adore them, big\n"
	.string "HERACROSS!$"

SixIsland_WaterPath_House1_Text_ItsXSizeSameAsBefore::
	.string "Huh? This {STR_VAR_2} measurement…\n"
	.string "Oh, boo! It's the same as before.$"

SixIsland_WaterPath_House1_Text_ItsXSizeYSizeWasBiggest::
	.string "Oh, it's just {STR_VAR_2}.\n"
	.string "The HERACROSS before was bigger.\p"
	.string "It was {STR_VAR_3}, the biggest\n"
	.string "HERACROSS you've brought me.$"

SixIsland_WaterPath_House1_Text_ThisWontDo::
	.string "Oh, no! This won't do!\p"
	.string "HERACROSS looks much more macho\n"
	.string "and cool, and has a lovely horn!$"

SixIsland_WaterPath_House1_Text_YourBagIsFull::
	.string "Your BAG is full.\n"
	.string "My reward won't fit.$"

SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXSize::
	.string "The biggest HERACROSS that I have\n"
	.string "ever seen measured so far is:\p"
	.string "{STR_VAR_3}!$"

SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
	.string "It's a blank chart of some sort.\p"
	.string "It has spaces for writing in\n"
	.string "records of some kind.$"
