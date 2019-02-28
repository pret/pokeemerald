TrainerHill_Elevator_MapScripts:: @ 826934F
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_MapScript2_269355
	.byte 0

TrainerHill_Elevator_MapScript2_269355: @ 8269355
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_269375
	.2byte 0

TrainerHill_Elevator_EventScript_26935F:: @ 826935F
	end

TrainerHill_Elevator_EventScript_269360:: @ 8269360
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Elevator_Movement_2693EB
	waitmovement 0
	releaseall
	warp MAP_TRAINER_HILL_ROOF, 255, 15, 5
	waitstate
	end

TrainerHill_Elevator_EventScript_269375:: @ 8269375
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Elevator_Movement_2693E4
	waitmovement 0
	applymovement 1, TrainerHill_Elevator_Movement_2693EE
	waitmovement 0
	lockall
	msgbox TrainerHill_Elevator_Text_268F3E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TrainerHill_Elevator_EventScript_269360
	releaseall
	applymovement 1, TrainerHill_Elevator_Movement_2693F0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Elevator_Movement_2693DF
	waitmovement 0
	call TrainerHill_Elevator_EventScript_2693D9
	delay 25
	applymovement EVENT_OBJ_ID_PLAYER, TrainerHill_Elevator_Movement_2693E7
	waitmovement 0
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 17, 8
	waitstate
	end

TrainerHill_Elevator_EventScript_2693CE:: @ 82693CE
	goto TrainerHill_Elevator_EventScript_2693D4
	end

TrainerHill_Elevator_EventScript_2693D4:: @ 82693D4
	special sub_8139C10
	releaseall
	end

TrainerHill_Elevator_EventScript_2693D9:: @ 82693D9
	waitse
	special ShakeScreenInElevator
	waitstate
	return

TrainerHill_Elevator_Movement_2693DF: @ 82693DF
	walk_up
	walk_up
	walk_right
	face_down
	step_end

TrainerHill_Elevator_Movement_2693E4: @ 82693E4
	delay_16
	walk_left
	step_end

TrainerHill_Elevator_Movement_2693E7: @ 82693E7
	delay_16
	walk_down
	walk_down
	step_end

TrainerHill_Elevator_Movement_2693EB: @ 82693EB
	face_down
	delay_16
	step_end

TrainerHill_Elevator_Movement_2693EE: @ 82693EE
	face_right
	step_end

TrainerHill_Elevator_Movement_2693F0: @ 82693F0
	face_down
	step_end

