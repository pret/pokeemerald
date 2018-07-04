ShoalCave_LowTideEntranceRoom_MapScripts:: @ 8236DBA
	map_script 3, ShoalCave_LowTideEntranceRoom_MapScript1_236DC0
	.byte 0

ShoalCave_LowTideEntranceRoom_MapScript1_236DC0: @ 8236DC0
	special UpdateShoalTideFlag
	checkflag FLAG_SYS_SHOAL_TIDE
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236DD1
	goto ShoalCave_LowTideEntranceRoom_EventScript_236DD5

ShoalCave_LowTideEntranceRoom_EventScript_236DD1:: @ 8236DD1
	setmaplayoutindex 168
	end

ShoalCave_LowTideEntranceRoom_EventScript_236DD5:: @ 8236DD5
	setmaplayoutindex 164
	end

ShoalCave_LowTideEntranceRoom_EventScript_236DD9:: @ 8236DD9
	lock
	faceplayer
	dodailyevents
	checkflag FLAG_SYS_SHOAL_ITEM
	call_if 1, ShoalCave_LowTideEntranceRoom_EventScript_236ED9
	checkitem ITEM_SHOAL_SALT, 4
	compare VAR_RESULT, 0
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236E9B
	checkitem ITEM_SHOAL_SHELL, 4
	compare VAR_RESULT, 0
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236E9B
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7F37, 5
	compare VAR_RESULT, 0
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236ECF
	checkitemspace ITEM_SHELL_BELL, 1
	compare VAR_RESULT, 0
	call_if 1, ShoalCave_LowTideEntranceRoom_EventScript_236E69
	compare VAR_RESULT, 2
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236E91
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7FAC, 4
	takeitem ITEM_SHOAL_SALT, 4
	takeitem ITEM_SHOAL_SHELL, 4
	giveitem_std ITEM_SHELL_BELL
	compare VAR_RESULT, 0
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_272054
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A8012, 4
	setflag FLAG_0x002
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236E69:: @ 8236E69
	checkitem ITEM_SHOAL_SALT, 5
	compare VAR_RESULT, 1
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236E7A
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E7A:: @ 8236E7A
	checkitem ITEM_SHOAL_SHELL, 5
	compare VAR_RESULT, 1
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236E8B
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E8B:: @ 8236E8B
	setvar VAR_RESULT, 2
	return

ShoalCave_LowTideEntranceRoom_EventScript_236E91:: @ 8236E91
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A80F5, 4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236E9B:: @ 8236E9B
	checkitem ITEM_SHOAL_SALT, 1
	compare VAR_RESULT, 1
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236EC5
	checkitem ITEM_SHOAL_SHELL, 1
	compare VAR_RESULT, 1
	goto_eq ShoalCave_LowTideEntranceRoom_EventScript_236EC5
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7E0E, 4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236EC5:: @ 8236EC5
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A7EB3, 4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236ECF:: @ 8236ECF
	msgbox ShoalCave_LowTideEntranceRoom_Text_2A80C6, 4
	release
	end

ShoalCave_LowTideEntranceRoom_EventScript_236ED9:: @ 8236ED9
	clearflag FLAG_0x3B8
	clearflag FLAG_0x3B9
	clearflag FLAG_0x3BA
	clearflag FLAG_0x3BB
	clearflag FLAG_0x3BC
	clearflag FLAG_0x3BD
	clearflag FLAG_0x3BE
	clearflag FLAG_0x3BF
	clearflag FLAG_SYS_SHOAL_ITEM
	return

