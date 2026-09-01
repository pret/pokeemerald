FiveIsland_LostCave_Room10_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FiveIsland_LostCave_Room10_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_LostCave_Room10_OnFrame
	.byte 0

FiveIsland_LostCave_Room10_OnResume::
	call_if_defeated TRAINER_LADY_SELPHY, FiveIsland_LostCave_Room10_EventScript_StopSelphySceneTrigger
	end

FiveIsland_LostCave_Room10_EventScript_StopSelphySceneTrigger::
	setvar VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 1
	return

FiveIsland_LostCave_Room10_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 0, FiveIsland_LostCave_Room10_EventScript_FindSelphyScene
	.2byte 0

FiveIsland_LostCave_Room10_EventScript_FindSelphyScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_LOST_CAVE_SELPHY, FiveIsland_LostCave_Room10_Movement_SelphyWander
	waitmovement 0
	delay 100
	applymovement LOCALID_LOST_CAVE_SELPHY, FiveIsland_LostCave_Room10_Movement_SelphyApproach
	waitmovement 0
	msgbox FiveIsland_LostCave_Room10_Text_SelphyIntro
	trainerbattle_no_intro TRAINER_LADY_SELPHY, FiveIsland_LostCave_Room10_Text_SelphyDefeat
	msgbox FiveIsland_LostCave_Room10_Text_MayIAskYouToTakeMeHome
	closemessage
	call FiveIsland_LostCave_Room10_EventScript_SetSelphyFound
	warp MAP_FIVE_ISLAND_RESORT_GORGEOUS, 39, 10
	waitstate
	releaseall
	end

FiveIsland_LostCave_Room10_EventScript_SetSelphyFound::
	setflag FLAG_HIDE_LOST_CAVE_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 1
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1
	return

FiveIsland_LostCave_Room10_EventScript_SelphyQuestLog::
	settrainerflag TRAINER_LADY_SELPHY
	call FiveIsland_LostCave_Room10_EventScript_SetSelphyFound
	releaseall
	end

FiveIsland_LostCave_Room10_Movement_SelphyWander::
	walk_left
	delay_16
	walk_right
	delay_16
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	step_end

FiveIsland_LostCave_Room10_Movement_SelphyApproach::
	walk_down
	walk_down
	step_end

FiveIsland_LostCave_Room10_Text_SelphyIntro::
	.string "W-what do you intend to do with\n"
	.string "me?$"

FiveIsland_LostCave_Room10_Text_SelphyDefeat::
	.string "Oh… I was afraid that you meant to\n"
	.string "harm me.$"

FiveIsland_LostCave_Room10_Text_MayIAskYouToTakeMeHome::
	.string "I am so glad that you happened\n"
	.string "here.\p"
	.string "I grew rather bored of walking,\n"
	.string "and I am feeling fatigued.\p"
	.string "May I ask you to take me home\n"
	.string "from here?$"

