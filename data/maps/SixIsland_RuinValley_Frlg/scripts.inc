SixIsland_RuinValley_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_RuinValley_OnLoad
	.byte 0

SixIsland_RuinValley_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

SixIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

SixIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox SixIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SixIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SixIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor
	braillemsgbox Braille_Text_Cut
	releaseall
	end

SixIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox SixIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

SixIsland_RuinValley_Text_CantFigureOutHowToGetInside::
	.string "I can't figure out how I'm supposed\n"
	.string "to get inside.$"

SixIsland_RuinValley_Text_IFoundThisPlace::
	.string "Let me tell you, I found this\n"
	.string "place.\p"
	.string "Don't look so envious, will you?$"

SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
	.string "The door doesn't budge at all.\n"
	.string "Check it more thoroughly?$"

SixIsland_RuinValley_Text_LeftDoorAlone::
	.string "{PLAYER} left the door alone.$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
	.string "On closer inspection, there are\n"
	.string "several dots on the door…$"

SixIsland_RuinValley_Text_DoorIsOpen::
	.string "The door is open.$"

SixIsland_RuinValley_Text_StanlyIntro::
	.string "There appear to be many secrets\n"
	.string "still unsolved in this world.$"

SixIsland_RuinValley_Text_StanlyDefeat::
	.string "Hmm…$"

SixIsland_RuinValley_Text_StanlyPostBattle::
	.string "I suggest to you that you, too,\n"
	.string "give a thought to the secrets and\l"
	.string "mysteries of our world once a day.$"

SixIsland_RuinValley_Text_FosterIntro::
	.string "I'm curious, what compelled you to\n"
	.string "come here?$"

SixIsland_RuinValley_Text_FosterDefeat::
	.string "It's been so long since I battled,\n"
	.string "my instincts are off.$"

SixIsland_RuinValley_Text_FosterPostBattle::
	.string "There are several ruins on the\n"
	.string "SEVII ISLANDS.\p"
	.string "The majority of them date back\n"
	.string "a long way.$"

SixIsland_RuinValley_Text_LarryIntro::
	.string "It's been said that there are\n"
	.string "mysterious stones on this island.\p"
	.string "I suspect it has something to do\n"
	.string "with the ruins here.$"

SixIsland_RuinValley_Text_LarryDefeat::
	.string "Oh, interesting.$"

SixIsland_RuinValley_Text_LarryPostBattle::
	.string "Those ruins over there…\p"
	.string "I haven't had any luck in finding\n"
	.string "how I can get inside.$"

SixIsland_RuinValley_Text_DarylIntro::
	.string "A battle with you, so high up!$"

SixIsland_RuinValley_Text_DarylDefeat::
	.string "Oh, the heartbreak of losing so\n"
	.string "easily to you!$"

SixIsland_RuinValley_Text_DarylPostBattle::
	.string "Experience the joy of climbing!$"

SixIsland_RuinValley_Text_HectorIntro::
	.string "I'm pretty familiar with the land\n"
	.string "around these parts.$"

SixIsland_RuinValley_Text_HectorDefeat::
	.string "You don't need to be so pushy.\n"
	.string "I'll be happy to tell you.$"

SixIsland_RuinValley_Text_HectorPostBattle::
	.string "The door to the ruins…\n"
	.string "It has these strange patterns\l"
	.string "engraved on the outside.\p"
	.string "I don't know what they mean,\n"
	.string "though.$"
