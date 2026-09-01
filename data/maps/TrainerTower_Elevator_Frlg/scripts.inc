TrainerTower_Elevator_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

TrainerTower_Elevator_EventScript_FloorSelect::
	lockall
	setvar VAR_0x8004, 6
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message gText_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, TrainerTower_Elevator_EventScript_FloorSelectFromRoof
	case 1, TrainerTower_Elevator_EventScript_FloorSelectFromLobby
	end

TrainerTower_Elevator_EventScript_FloorSelectFromRoof::
	multichoicedefault 0, 0, MULTI_ROOFTOP_B1F, 0, FALSE
	goto TrainerTower_Elevator_EventScript_ChooseFloor
	end

TrainerTower_Elevator_EventScript_FloorSelectFromLobby::
	multichoicedefault 0, 0, MULTI_ROOFTOP_B1F, 1, FALSE
	goto TrainerTower_Elevator_EventScript_ChooseFloor
	end

TrainerTower_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, TrainerTower_Elevator_EventScript_SelectRoof
	case 1, TrainerTower_Elevator_EventScript_SelectLobby
	case 2, TrainerTower_Elevator_EventScript_CloseFloorSelect
	case MULTI_B_PRESSED, TrainerTower_Elevator_EventScript_CloseFloorSelect
	end

TrainerTower_Elevator_EventScript_SelectLobby::
	setvar VAR_0x8006, 3
	setdynamicwarp MAP_TRAINER_TOWER_LOBBY, 17, 8
	goto_if_eq VAR_ELEVATOR_FLOOR, 3, TrainerTower_Elevator_EventScript_CloseFloorSelect
	call TrainerTower_Elevator_EventScript_MoveElevator
	setvar VAR_ELEVATOR_FLOOR, 3
	special CloseElevatorCurrentFloorWindow
	delay 25
	applymovement LOCALID_PLAYER, TrainerTower_Elevator_Movement_ExitElevator
	waitmovement 0
	warp MAP_TRAINER_TOWER_LOBBY, 17, 8
	waitstate
	releaseall
	end

TrainerTower_Elevator_EventScript_SelectRoof::
	goto TrainerTower_Elevator_EventScript_CloseFloorSelect
	end

TrainerTower_Elevator_EventScript_CloseFloorSelect::
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

TrainerTower_Elevator_EventScript_MoveElevator::
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return

TrainerTower_Elevator_Movement_ExitElevator::
	walk_in_place_faster_down
	delay_16
	walk_down
	walk_right
	walk_right
	walk_down
	step_end
