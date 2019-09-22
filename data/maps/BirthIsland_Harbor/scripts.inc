BirthIsland_Harbor_MapScripts:: @ 826805C
	.byte 0

BirthIsland_Harbor_EventScript_26805D:: @ 826805D
	lock
	faceplayer
	msgbox BirthIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BirthIsland_Harbor_EventScript_2680A2
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	hideobjectat 1, MAP_BIRTH_ISLAND_HARBOR
	setvar VAR_0x8004, 2
	call BirthIsland_Harbor_EventScript_272250
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BirthIsland_Harbor_EventScript_2680A2:: @ 82680A2
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

