.set LOCALID_ATTENDANT, 1

TrainerHill_Elevator_MapScripts:: @ 826934F
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_OnFrame
	.byte 0

TrainerHill_Elevator_OnFrame: @ 8269355
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_EnterElevator
	.2byte 0

TrainerHill_Elevator_EventScript_Attendant:: @ 826935F
	end

TrainerHill_Elevator_EventScript_ExitToRoof:: @ 8269360
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof
	waitmovement 0
	releaseall
	warp MAP_TRAINER_HILL_ROOF, 255, 15, 5
	waitstate
	end

TrainerHill_Elevator_EventScript_EnterElevator:: @ 8269375
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerApproachAttendant
	waitmovement 0
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFacePlayer
	waitmovement 0
	lockall
	msgbox TrainerHill_Elevator_Text_ReturnToReception, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TrainerHill_Elevator_EventScript_ExitToRoof
	releaseall
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator
	waitmovement 0
	call TrainerHill_Elevator_EventScript_MoveElevator
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevator
	waitmovement 0
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 17, 8
	waitstate
	end

@ Unused
TrainerHill_Elevator_EventScript_ExitFloorSelect:: @ 82693CE
	goto TrainerHill_Elevator_EventScript_CloseFloorSelect
	end

@ Functionally unused
TrainerHill_Elevator_EventScript_CloseFloorSelect:: @ 82693D4
	special CloseDeptStoreElevatorWindow
	releaseall
	end

TrainerHill_Elevator_EventScript_MoveElevator:: @ 82693D9
	waitse
	special MoveElevator
	waitstate
	return

TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator: @ 82693DF
	walk_up
	walk_up
	walk_right
	face_down
	step_end

TrainerHill_Elevator_Movement_PlayerApproachAttendant: @ 82693E4
	delay_16
	walk_left
	step_end

TrainerHill_Elevator_Movement_PlayerExitElevator: @ 82693E7
	delay_16
	walk_down
	walk_down
	step_end

TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof: @ 82693EB
	face_down
	delay_16
	step_end

TrainerHill_Elevator_Movement_AttendantFacePlayer: @ 82693EE
	face_right
	step_end

TrainerHill_Elevator_Movement_AttendantFaceDown: @ 82693F0
	face_down
	step_end

