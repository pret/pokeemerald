.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 255, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "Which Contest are you entering?\n"
	.string "Want a piece of advice?\p"
	.string "In any Contest, for example, a Cute\n"
	.string "Contest, I don't think they judge you\l"
	.string "only on cuteness in the first round.\p"
	.string "You need to work out ways for raising\n"
	.string "Pokémon better.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "I raised my Pokémon to be cute.\p"
	.string "I found out you can put Pokémon in\n"
	.string "a Contest for cuteness!\p"
	.string "I'm so glad I raised my Pokémon with\n"
	.string "loving care…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "My Pokémon rules!\p"
	.string "It's cool, tough yet beautiful, cute,\n"
	.string "and smart. It's complete!\p"
	.string "I may as well go for wins in every\n"
	.string "single Contest.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "Pokémon Contests\n"
	.string "Normal Rank Stage!$"

