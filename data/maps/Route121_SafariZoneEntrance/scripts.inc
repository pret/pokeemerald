Route121_SafariZoneEntrance_MapScripts:: @ 822BBBB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_MapScript2_22BBC1
	.byte 0

Route121_SafariZoneEntrance_MapScript2_22BBC1: @ 822BBC1
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_22BBCB
	.2byte 0

Route121_SafariZoneEntrance_EventScript_22BBCB:: @ 822BBCB
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Route121_SafariZoneEntrance_Movement_22BBDD
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_22BBDD: @ 822BBDD
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_SafariZoneEntrance_EventScript_22BBE6:: @ 822BBE6
	msgbox Route121_SafariZoneEntrance_Text_2A4D12, MSGBOX_NPC
	end

Route121_SafariZoneEntrance_EventScript_22BBEF:: @ 822BBEF
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_2A4E46, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route121_SafariZoneEntrance_EventScript_22BC0E
	msgbox Route121_SafariZoneEntrance_Text_2A4E7E, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_22BC0E:: @ 822BC0E
	msgbox Route121_SafariZoneEntrance_Text_2A4EA1, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_22BC18:: @ 822BC18
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	showmoneybox 0, 0, 0
	msgbox Route121_SafariZoneEntrance_Text_2A4F74, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route121_SafariZoneEntrance_EventScript_22BC48
	msgbox Route121_SafariZoneEntrance_Text_2A4FD7, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BC48:: @ 822BC48
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq Route121_SafariZoneEntrance_EventScript_22BCEA
	call Route121_SafariZoneEntrance_EventScript_22BCBF
	checkmoney 0x1f4, 0
	compare VAR_RESULT, 0
	goto_if_eq Route121_SafariZoneEntrance_EventScript_22BCF8
	playse SE_REGI
	msgbox Route121_SafariZoneEntrance_Text_2A501B, MSGBOX_DEFAULT
	takemoney 0x1f4, 0
	updatemoneybox 0, 0
	nop
	msgbox Route121_SafariZoneEntrance_Text_2A5036, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message Route121_SafariZoneEntrance_Text_2A5052
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_2A506F, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, Route121_SafariZoneEntrance_Movement_22BD18
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_SOUTH, 255, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_22BCBF:: @ 822BCBF
	getpartysize
	compare VAR_RESULT, 6
	goto_if_ne Route121_SafariZoneEntrance_EventScript_22BCE9
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	compare VAR_RESULT, 1
	goto_if_eq Route121_SafariZoneEntrance_EventScript_22BCE9
	msgbox Route121_SafariZoneEntrance_Text_2A50E5, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BCE9:: @ 822BCE9
	return

Route121_SafariZoneEntrance_EventScript_22BCEA:: @ 822BCEA
	msgbox Route121_SafariZoneEntrance_Text_2A5105, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BCF8:: @ 822BCF8
	msgbox Route121_SafariZoneEntrance_Text_2A4FF7, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_22BD06
	end

Route121_SafariZoneEntrance_EventScript_22BD06:: @ 822BD06
	closemessage
	hidemoneybox
	nop
	nop
	applymovement EVENT_OBJ_ID_PLAYER, Route121_SafariZoneEntrance_Movement_22BD16
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_22BD16: @ 822BD16
	walk_right
	step_end

Route121_SafariZoneEntrance_Movement_22BD18: @ 822BD18
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

Route121_SafariZoneEntrance_EventScript_22BD21:: @ 822BD21
	msgbox Route121_SafariZoneEntrance_Text_2A55BB, MSGBOX_SIGN
	end

