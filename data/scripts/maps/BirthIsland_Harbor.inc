BirthIsland_Harbor_MapScripts:: @ 826805C
	.byte 0

BirthIsland_Harbor_EventScript_26805D:: @ 826805D
	lock
	faceplayer
	msgbox BirthIsland_Harbor_Text_2C6B90, 5
	compare VAR_RESULT, 0
	goto_eq BirthIsland_Harbor_EventScript_2680A2
	msgbox BirthIsland_Harbor_Text_2A6A5D, 4
	closemessage
	applymovement VAR_LAST_TALKED, BirthIsland_Harbor_Movement_2725AA
	waitmovement 0
	delay 30
	hideobjectat 1, BIRTH_ISLAND_HARBOR
	setvar VAR_0x8004, 2
	call BirthIsland_Harbor_EventScript_272250
	warp LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BirthIsland_Harbor_EventScript_2680A2:: @ 82680A2
	msgbox BirthIsland_Harbor_Text_2A6A82, 4
	release
	end

