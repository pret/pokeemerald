IslandCave_MapScripts:: @ 8238E2A
	map_script 5, IslandCave_MapScript1_238E3A
	map_script 1, IslandCave_MapScript1_238E58
	map_script 3, IslandCave_MapScript1_238E99
	.byte 0

IslandCave_MapScript1_238E3A: @ 8238E3A
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, IslandCave_EventScript_238E44
	end

IslandCave_EventScript_238E44:: @ 8238E44
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, IslandCave_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

IslandCave_MapScript1_238E58: @ 8238E58
	checkflag FLAG_SYS_BRAILLE_WAIT
	call_if 0, IslandCave_EventScript_238E62
	end

IslandCave_EventScript_238E62:: @ 8238E62
	setmetatile 7, 19, 553, 1
	setmetatile 8, 19, 553, 1
	setmetatile 9, 19, 553, 1
	setmetatile 7, 20, 565, 1
	setmetatile 8, 20, 565, 1
	setmetatile 9, 20, 565, 1
	return

IslandCave_MapScript1_238E99: @ 8238E99
	setflag FLAG_0x8B5
	call IslandCave_EventScript_238F45
	checkflag FLAG_0x1BC
	call_if 0, IslandCave_EventScript_238EAB
	end

IslandCave_EventScript_238EAB:: @ 8238EAB
	clearflag FLAG_0x3A8
	return

