Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
	.string "The water is shallow here.\n"
	.string "There are many people swimming.$"

Route20_Text_BarryDefeat::
	.string "Splash!$"

Route20_Text_BarryPostBattle::
	.string "I wish I could ride my POKéMON.\n"
	.string "I bet you're not tired.$"

Route20_Text_ShirleyIntro::
	.string "SEAFOAM is a quiet getaway.\n"
	.string "I'm vacationing here.$"

Route20_Text_ShirleyDefeat::
	.string "Quit it!$"

Route20_Text_ShirleyPostBattle::
	.string "There's a huge cavern underneath\n"
	.string "this island.$"

Route20_Text_TiffanyIntro::
	.string "I love floating with the fishes\n"
	.string "here among the waves.$"

Route20_Text_TiffanyDefeat::
	.string "Yowch!$"

Route20_Text_TiffanyPostBattle::
	.string "Want to float with me?$"

Route20_Text_IreneIntro::
	.string "Are you on vacation, too?$"

Route20_Text_IreneDefeat::
	.string "No mercy at all!$"

Route20_Text_IrenePostBattle::
	.string "SEAFOAM used to be a single island\n"
	.string "in the distant past.$"

Route20_Text_DeanIntro::
	.string "Check out my buff physique!$"

Route20_Text_DeanDefeat::
	.string "Wimpy!$"

Route20_Text_DeanPostBattle::
	.string "I should've been buffing up my\n"
	.string "POKéMON, not me!$"

Route20_Text_DarrinIntro::
	.string "Why are you riding a POKéMON?\n"
	.string "Can't you swim?$"

Route20_Text_DarrinDefeat::
	.string "Ouch!\n"
	.string "Torpedoed!$"

Route20_Text_DarrinPostBattle::
	.string "Riding a POKéMON sure looks fun!$"

Route20_Text_RogerIntro::
	.string "I rode my bird POKéMON here.$"

Route20_Text_RogerDefeat::
	.string "Oh, no!\n"
	.string "Now what am I to do?$"

Route20_Text_RogerPostBattle::
	.string "My birds are exhausted.\n"
	.string "They can't FLY me back!$"

Route20_Text_NoraIntro::
	.string "My boyfriend gave me big pearls.$"

Route20_Text_NoraDefeat::
	.string "Oh, no!\n"
	.string "My pearls were in them!$"

Route20_Text_NoraPostBattle::
	.string "Will my pearls grow bigger inside\n"
	.string "CLOYSTER?$"

Route20_Text_MissyIntro::
	.string "I swam here from CINNABAR ISLAND.\n"
	.string "It wasn't easy, I tell you.$"

Route20_Text_MissyDefeat::
	.string "I'm so disappointed!$"

Route20_Text_MissyPostBattle::
	.string "POKéMON have taken over an\n"
	.string "abandoned mansion on CINNABAR.\p"
	.string "They call it the POKéMON MANSION\n"
	.string "now.$"

Route20_Text_MelissaIntro::
	.string "CINNABAR, in the west, has a LAB\n"
	.string "for POKéMON.\p"
	.string "My daddy works there.$"

Route20_Text_MelissaDefeat::
	.string "Wait!\n"
	.string "You're supposed to wait!$"

Route20_Text_MelissaPostBattle::
	.string "CINNABAR is a volcanic island.\p"
	.string "I heard it rose out of the sea\n"
	.string "when a volcano erupted.$"

Route20_Text_SeafoamIslands::
	.string "SEAFOAM ISLANDS$"

Route20_Text_MistyTrainsHere::
	.string "Strong TRAINERS and WATER POKéMON\n"
	.string "are common sights in these parts.\p"
	.string "They say that MISTY of the\n"
	.string "CERULEAN GYM trains here.$"
