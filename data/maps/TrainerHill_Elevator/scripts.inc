TrainerHill_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_OnFrame
	.byte 0

TrainerHill_Elevator_OnFrame:
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_EnterElevator
	.2byte 0

TrainerHill_Elevator_EventScript_Attendant::
	end

TrainerHill_Elevator_EventScript_ExitToRoof::
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof
	waitmovement 0
	releaseall
	warp MAP_TRAINER_HILL_ROOF, 15, 5
	waitstate
	end

TrainerHill_Elevator_EventScript_EnterElevator::
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerApproachAttendant
	waitmovement 0
	applymovement LOCALID_TRAINER_HILL_ELEVATOR_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFacePlayer
	waitmovement 0
	lockall
	msgbox TrainerHill_Elevator_Text_ReturnToReception, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Elevator_EventScript_ExitToRoof
	releaseall
	applymovement LOCALID_TRAINER_HILL_ELEVATOR_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFaceDown
	waitmovement 0
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator
	waitmovement 0
	call TrainerHill_Elevator_EventScript_MoveElevator
	delay 25
	applymovement LOCALID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevator
	waitmovement 0
	warp MAP_TRAINER_HILL_ENTRANCE, 17, 8
	waitstate
	end

@ Unused
TrainerHill_Elevator_EventScript_ExitFloorSelect::
	goto TrainerHill_Elevator_EventScript_CloseFloorSelect
	end

@ Functionally unused
TrainerHill_Elevator_EventScript_CloseFloorSelect::
	special CloseDeptStoreElevatorWindow
	releaseall
	end

TrainerHill_Elevator_EventScript_MoveElevator::
	waitse
	special MoveElevator
	waitstate
	return

TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator:
	walk_up
	walk_up
	walk_right
	face_down
	step_end

TrainerHill_Elevator_Movement_PlayerApproachAttendant:
	delay_16
	walk_left
	step_end

TrainerHill_Elevator_Movement_PlayerExitElevator:
	delay_16
	walk_down
	walk_down
	step_end

TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof:
	face_down
	delay_16
	step_end

TrainerHill_Elevator_Movement_AttendantFacePlayer:
	face_right
	step_end

TrainerHill_Elevator_Movement_AttendantFaceDown:
	face_down
	step_end

