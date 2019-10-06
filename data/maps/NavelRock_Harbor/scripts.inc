NavelRock_Harbor_MapScripts:: @ 82690BC
	.byte 0

NavelRock_Harbor_EventScript_2690BD:: @ 82690BD
	lock
	faceplayer
	msgbox NavelRock_Harbor_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq NavelRock_Harbor_EventScript_269102
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	hideobjectat 1, MAP_NAVEL_ROCK_HARBOR
	setvar VAR_0x8004, 2
	call NavelRock_Harbor_EventScript_272250
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

NavelRock_Harbor_EventScript_269102:: @ 8269102
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

