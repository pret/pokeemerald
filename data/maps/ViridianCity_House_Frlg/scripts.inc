ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
	.string "Coming up with nicknames is fun,\n"
	.string "but it's not so easy to do.\p"
	.string "Clever names are nice, but simple\n"
	.string "names are easier to remember.$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
	.string "My daddy loves POKéMON, too.$"

ViridianCity_House_Text_Speary::
	.string "SPEARY: Tetweet!$"

ViridianCity_House_Text_SpearowNameSpeary::
	.string "SPEAROW\n"
	.string "Name: SPEARY$"

