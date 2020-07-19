.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

BirthIsland_Harbor_MapScripts:: @ 826805C
	.byte 0

BirthIsland_Harbor_EventScript_Sailor:: @ 826805D
	lock
	faceplayer
	msgbox BirthIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BirthIsland_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_BIRTH_ISLAND_HARBOR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BirthIsland_Harbor_EventScript_AsYouLike:: @ 82680A2
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

