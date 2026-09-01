TrainerTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

@ All Trainer Tower floors/roof share these scripts for their object events

TrainerTower_EventScript_DoublesTrainer1::
	call TrainerTower_EventScript_SpeakToDoublesTrainer1
	end

TrainerTower_EventScript_SinglesTrainer::
	call TrainerTower_EventScript_SpeakToSinglesTrainer
	end

TrainerTower_EventScript_KnockoutTrainer::
	call TrainerTower_EventScript_SpeakToKnockoutTrainer
	end

TrainerTower_EventScript_DoublesTrainer2::
	call TrainerTower_EventScript_SpeakToDoublesTrainer2
	end

TrainerTower_EventScript_Owner::
	call TrainerTower_EventScript_SpeakToOwner
	end
