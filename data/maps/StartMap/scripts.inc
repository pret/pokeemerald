StartMap_MapScripts::
	.byte 0

StartMap_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_0x8004, 0
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	msgbox StartMap_Text_Nickname, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
	setvar VAR_0x8004, 1
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	msgbox StartMap_Text_Nickname, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
	removeobject 1
	special DrawWholeMapView
	releaseall
	end

StartMap_Text_Nickname:
	.string "Nickname?$"
