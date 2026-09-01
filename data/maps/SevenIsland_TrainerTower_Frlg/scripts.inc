SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "I sensed your approach.$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "Give up…$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "In your future, I sense that you\n"
	.string "will meet many others.\p"
	.string "I think you will be linked to each\n"
	.string "other by a strange power.$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "Somewhere on this island, peculiar\n"
	.string "POKéMON are sleeping.$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "What an amazing TRAINER!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "Somewhere on this island, peculiar\n"
	.string "POKéMON are sleeping.\p"
	.string "Could it be that they're waiting\n"
	.string "for you?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "TRAINER TOWER ENTRANCE\n"
	.string "Rise to the Challenge, TRAINERS!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "TRAINER TOWER AHEAD$"

