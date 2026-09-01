TrainerTower_Roof_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

@ Below script is unused, the identical version in the 1F script is used instead

TrainerTower_Roof_EventScript_Owner::
	call TrainerTower_EventScript_SpeakToOwner
	end
