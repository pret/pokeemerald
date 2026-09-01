CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "Those miserable ROCKETS!\p"
	.string "Look what they've done to my\n"
	.string "house!\p"
	.string "They stole a TM for teaching\n"
	.string "POKéMON how to DIG holes!\p"
	.string "I was going to use it on a\n"
	.string "MANKEY or a SANDSHREW…\p"
	.string "That cost me a bundle, it did!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "I figure what's lost is lost.\p"
	.string "I decided to teach DIGLETT how to\n"
	.string "DIG without a TM.$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "TEAM ROCKET must be trying to DIG\n"
	.string "their way into no good!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
	.string "TEAM ROCKET left a way out!$"

