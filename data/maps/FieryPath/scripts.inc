FieryPath_MapScripts:: @ 8230F24
	map_script 3, FieryPath_MapScript1_230F2A
	.byte 0

FieryPath_MapScript1_230F2A: @ 8230F2A
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_230F37
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_230F37:: @ 8230F37
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
	return

