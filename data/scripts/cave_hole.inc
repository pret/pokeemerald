CaveHole_CheckFallDownHole: @ 82A8327
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0

CaveHole_FixCrackedGround: @ 82A8331
	copyvar VAR_ICE_STEP_COUNT, 1
	end

EventScript_FallDownHole:: @ 82A8337
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_UNDEFINED
	waitstate
	end

EventScript_FallDownHoleMtPyre:: @ 82A8350
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	special DoFallWarp
	waitstate
	end

Movement_SetInvisible: @ 82A8369
	set_invisible
	step_end
