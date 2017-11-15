FieryPath_MapScripts:: @ 8230F24
	map_script 3, FieryPath_MapScript1_230F2A
	.byte 0

FieryPath_MapScript1_230F2A: @ 8230F2A
	checkflag FLAG_0x8AA
	call_if 0, FieryPath_EventScript_230F37
	setflag FLAG_0x8AA
	end

FieryPath_EventScript_230F37:: @ 8230F37
	setflag FLAG_0x2FE
	clearflag FLAG_0x2FF
	return

