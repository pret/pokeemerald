VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
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
	.string "Aan welke WEDSTRIJD doe je mee?\n"
	.string "Wil je een tip?\p"
	.string "Bij elke WEDSTRIJD, bijvoorbeeld een\n"
	.string "SCHATTIG-WEDSTRIJD, kijken ze in de\l"
	.string "eerste ronde niet alleen naar\l"
	.string "schattigheid.\p"
	.string "Je moet bedenken hoe je\n"
	.string "POKéMON beter kunt opvoeden.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Ik heb mijn POKéMON schattig\n"
	.string "opgevoed.\p"
	.string "Ik ontdekte dat je POKéMON kunt\n"
	.string "inschrijven voor schattigheid!\p"
	.string "Ik ben blij dat ik mijn POKéMON\n"
	.string "met liefde heb opgevoed…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mijn POKéMON is de beste!\p"
	.string "Hij is stoer, sterk maar mooi,\n"
	.string "schattig en slim. Hij is compleet!\p"
	.string "Ik kan net zo goed elke\n"
	.string "WEDSTRIJD proberen te winnen.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "POKéMON WEDSTRIJDEN\n"
	.string "NORMAAL NIVEAU PODIUM!$"

