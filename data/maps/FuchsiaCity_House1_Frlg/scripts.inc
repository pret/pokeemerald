FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "The SAFARI ZONE's WARDEN is old, \n"
	.string "but he's still very much active.\p"
	.string "All his teeth are false, though.$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "Hmm?\n"
	.string "You've met BILL?\p"
	.string "He's my grandson!\p"
	.string "He always liked collecting things,\n"
	.string "even as a child!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "BILL files his own POKéMON data on\n"
	.string "his PC.\p"
	.string "Did he show you?$"

