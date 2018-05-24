TrainerHill_Elevator_MapScripts:: @ 826934F
	map_script 2, TrainerHill_Elevator_MapScript2_269355
	.byte 0

TrainerHill_Elevator_MapScript2_269355: @ 8269355
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_269375
	.2byte 0

TrainerHill_Elevator_EventScript_26935F:: @ 826935F
	end

TrainerHill_Elevator_EventScript_269360:: @ 8269360
	applymovement 255, TrainerHill_Elevator_Movement_2693EB
	waitmovement 0
	releaseall
	warp TRAINER_HILL_ROOF, 255, 15, 5
	waitstate
	end

TrainerHill_Elevator_EventScript_269375:: @ 8269375
	applymovement 255, TrainerHill_Elevator_Movement_2693E4
	waitmovement 0
	applymovement 1, TrainerHill_Elevator_Movement_2693EE
	waitmovement 0
	lockall
	msgbox TrainerHill_Elevator_Text_268F3E, 5
	compare VAR_RESULT, 0
	goto_eq TrainerHill_Elevator_EventScript_269360
	releaseall
	applymovement 1, TrainerHill_Elevator_Movement_2693F0
	waitmovement 0
	applymovement 255, TrainerHill_Elevator_Movement_2693DF
	waitmovement 0
	call TrainerHill_Elevator_EventScript_2693D9
	delay 25
	applymovement 255, TrainerHill_Elevator_Movement_2693E7
	waitmovement 0
	warp TRAINER_HILL_ENTRANCE, 255, 17, 8
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
	special sub_8139A78
	waitstate
	return

TrainerHill_Elevator_Movement_2693DF: @ 82693DF
	step_up
	step_up
	step_right
	step_00
	step_end

TrainerHill_Elevator_Movement_2693E4: @ 82693E4
	step_14
	step_left
	step_end

TrainerHill_Elevator_Movement_2693E7: @ 82693E7
	step_14
	step_down
	step_down
	step_end

TrainerHill_Elevator_Movement_2693EB: @ 82693EB
	step_00
	step_14
	step_end

TrainerHill_Elevator_Movement_2693EE: @ 82693EE
	step_03
	step_end

TrainerHill_Elevator_Movement_2693F0: @ 82693F0
	step_00
	step_end

