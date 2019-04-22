ShoalCave_LowTideEntranceRoom_MapScripts:: @ 8236DBA
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideEntranceRoom_OnTransition
	.byte 0

ShoalCave_LowTideEntranceRoom_OnTransition: @ 8236DC0
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideEntranceRoom_EventScript_236DD1
	goto ShoalCave_LowTideEntranceRoom_EventScript_236DD5

ShoalCave_LowTideEntranceRoom_EventScript_236DD1:: @ 8236DD1
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM
	end

ShoalCave_LowTideEntranceRoom_EventScript_236DD5:: @ 8236DD5
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
	end

ShoalCave_LowTideEntranceRoom_EventScript_236DD9:: @ 8236DD9
	lock
	faceplayer
	dotimebasedevents
	call_if_set FLAG_SYS_SHOAL_ITEM, ShoalCave_LowTideEntranceRoom_EventScript_236ED9
	checkitem ITEM_SHOAL_SALT, 4
	compare VAR_RESULT, 0
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E9B
	checkitem ITEM_SHOAL_SHELL, 4
	compare VAR_RESULT, 0
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E9B
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7F37, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236ECF
	checkitemspace ITEM_SHELL_BELL, 1
	compare VAR_RESULT, 0
	call_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E69
	compare VAR_RESULT, 2
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E91
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7FAC, MSGBOX_DEFAULT
	takeitem ITEM_SHOAL_SALT, 4
	takeitem ITEM_SHOAL_SHELL, 4
	giveitem_std ITEM_SHELL_BELL
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A8012, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236E69:: @ 8236E69
	checkitem ITEM_SHOAL_SALT, 5
	compare VAR_RESULT, 1
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E7A
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E7A:: @ 8236E7A
	checkitem ITEM_SHOAL_SHELL, 5
	compare VAR_RESULT, 1
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236E8B
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E8B:: @ 8236E8B
	setvar VAR_RESULT, 2
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E91:: @ 8236E91
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A80F5, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236E9B:: @ 8236E9B
	checkitem ITEM_SHOAL_SALT, 1
	compare VAR_RESULT, 1
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236EC5
	checkitem ITEM_SHOAL_SHELL, 1
	compare VAR_RESULT, 1
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_236EC5
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7E0E, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236EC5:: @ 8236EC5
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7EB3, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236ECF:: @ 8236ECF
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A80C6, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236ED9:: @ 8236ED9
	clearflag FLAG_RECEIVED_SHOAL_SALT_1
	clearflag FLAG_RECEIVED_SHOAL_SALT_2
	clearflag FLAG_RECEIVED_SHOAL_SALT_3
	clearflag FLAG_RECEIVED_SHOAL_SALT_4
	clearflag FLAG_RECEIVED_SHOAL_SHELL_1
	clearflag FLAG_RECEIVED_SHOAL_SHELL_2
	clearflag FLAG_RECEIVED_SHOAL_SHELL_3
	clearflag FLAG_RECEIVED_SHOAL_SHELL_4
	clearflag FLAG_SYS_SHOAL_ITEM
	return
