NavelRock_Harbor_MapScripts:: @ 82690BC
	.byte 0

NavelRock_Harbor_EventScript_2690BD:: @ 82690BD
	lock
	faceplayer
	msgbox NavelRock_Harbor_Text_2C6CE6, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq NavelRock_Harbor_EventScript_269102
	msgbox NavelRock_Harbor_Text_2A6A5D, 4
	closemessage
	applymovement VAR_LAST_TALKED, NavelRock_Harbor_Movement_2725AA
	waitmovement 0
	delay 30
	hideobjectat 1, NAVEL_ROCK_HARBOR
	setvar VAR_0x8004, 2
	call NavelRock_Harbor_EventScript_272250
	warp LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

NavelRock_Harbor_EventScript_269102:: @ 8269102
	msgbox NavelRock_Harbor_Text_2A6A82, 4
	release
	end

