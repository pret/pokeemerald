Route121_SafariZoneEntrance_MapScripts:: @ 822BBBB
	map_script 2, Route121_SafariZoneEntrance_MapScript2_22BBC1
	.byte 0

Route121_SafariZoneEntrance_MapScript2_22BBC1: @ 822BBC1
	map_script_2 VAR_0x40A4, 1, Route121_SafariZoneEntrance_EventScript_22BBCB
	.2byte 0

Route121_SafariZoneEntrance_EventScript_22BBCB:: @ 822BBCB
	lockall
	applymovement 255, Route121_SafariZoneEntrance_Movement_22BBDD
	waitmovement 0
	setvar VAR_0x40A4, 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_22BBDD: @ 822BBDD
	step_up
	step_right
	step_right
	step_right
	step_right
	step_right
	step_right
	step_right
	step_end

Route121_SafariZoneEntrance_EventScript_22BBE6:: @ 822BBE6
	msgbox Route121_SafariZoneEntrance_Text_2A4D12, 2
	end

Route121_SafariZoneEntrance_EventScript_22BBEF:: @ 822BBEF
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_2A4E46, 5
	compare VAR_RESULT, 1
	goto_eq Route121_SafariZoneEntrance_EventScript_22BC0E
	msgbox Route121_SafariZoneEntrance_Text_2A4E7E, 4
	release
	end

Route121_SafariZoneEntrance_EventScript_22BC0E:: @ 822BC0E
	msgbox Route121_SafariZoneEntrance_Text_2A4EA1, 4
	release
	end

Route121_SafariZoneEntrance_EventScript_22BC18:: @ 822BC18
	lockall
	applymovement 255, Route121_SafariZoneEntrance_Movement_2725A6
	waitmovement 0
	showmoneybox 0, 0, 0
	msgbox Route121_SafariZoneEntrance_Text_2A4F74, 5
	compare VAR_RESULT, 1
	goto_eq Route121_SafariZoneEntrance_EventScript_22BC48
	msgbox Route121_SafariZoneEntrance_Text_2A4FD7, 4
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BC48:: @ 822BC48
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare VAR_RESULT, 0
	goto_eq Route121_SafariZoneEntrance_EventScript_22BCEA
	call Route121_SafariZoneEntrance_EventScript_22BCBF
	checkmoney 0x1f4, 0
	compare VAR_RESULT, 0
	goto_eq Route121_SafariZoneEntrance_EventScript_22BCF8
	playse SE_REGI
	msgbox Route121_SafariZoneEntrance_Text_2A501B, 4
	takemoney 0x1f4, 0
	updatemoneybox 0, 0
	nop
	msgbox Route121_SafariZoneEntrance_Text_2A5036, 4
	playfanfare MUS_FANFA4
	message Route121_SafariZoneEntrance_Text_2A5052
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_2A506F, 4
	closemessage
	hidemoneybox
	nop
	nop
	applymovement 255, Route121_SafariZoneEntrance_Movement_22BD18
	waitmovement 0
	special EnterSafariMode
	setvar VAR_0x40A4, 2
	clearflag FLAG_0x05D
	warp SAFARI_ZONE_SOUTH, 255, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_22BCBF:: @ 822BCBF
	getpartysize
	compare VAR_RESULT, 6
	goto_if 5, Route121_SafariZoneEntrance_EventScript_22BCE9
	specialvar VAR_RESULT, sub_8139530
	compare VAR_RESULT, 1
	goto_eq Route121_SafariZoneEntrance_EventScript_22BCE9
	msgbox Route121_SafariZoneEntrance_Text_2A50E5, 4
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BCE9:: @ 822BCE9
	return

Route121_SafariZoneEntrance_EventScript_22BCEA:: @ 822BCEA
	msgbox Route121_SafariZoneEntrance_Text_2A5105, 4
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BCF8:: @ 822BCF8
	msgbox Route121_SafariZoneEntrance_Text_2A4FF7, 4
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BD06:: @ 822BD06
	closemessage
	hidemoneybox
	nop
	nop
	applymovement 255, Route121_SafariZoneEntrance_Movement_22BD16
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_22BD16: @ 822BD16
	step_right
	step_end

Route121_SafariZoneEntrance_Movement_22BD18: @ 822BD18
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_down
	step_14
	step_end

Route121_SafariZoneEntrance_EventScript_22BD21:: @ 822BD21
	msgbox Route121_SafariZoneEntrance_Text_2A55BB, 3
	end

