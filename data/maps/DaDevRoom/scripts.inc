DaDevRoom_MapScripts::
	.byte 0
	
	
	CauseEarthQuake_EventScript::
	lock
	faceplayer
	msgbox Text_SimpleYesNoScriptQuestion, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Script_PlayerAnsweredNo
	msgbox Text_PlayerAnsweredYes, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	playse SE_SUPER_EFFECTIVE
	special DoSealedChamberShakingEffect1
	waitstate
	delay 3
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_M_EXPLOSION
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_M_EXPLOSION
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_M_EXPLOSION
	delay 40
	playse MUS_RG_CAUGHT_INTRO
	msgbox Text_Poop, MSGBOX_DEFAULT
	fadeinbgm 0
	releaseall
	end

Script_PlayerAnsweredNo::
	msgbox Text_PlayerAnsweredNo, MSGBOX_DEFAULT
	release
	end

Text_SimpleYesNoScriptQuestion:
	.string "Would You like to nuke norway?$"

Text_PlayerAnsweredYes:
	.string "Suck My dick norway!$"

Text_PlayerAnsweredNo:
	.string "Norway still sucks.$"

Text_Poop:
	.string "NORWAY IS GONE!$"
