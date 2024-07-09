
PitBoss_Archie::
	lockall
	setflag FLAG_START_ARCHIE_BATTLE
	setflag FLAG_FLOOR_100
	special HealPlayerParty
	goto_if_set FLAG_DOUBLES_MODE, PitBossDoublesArchie
	trainerbattle_single TRAINER_ARCHIE_PIT_BOSS, PitArena_Text_Intro, PitArena_Text_Defeat, PitBoss_ArchieBattleFinished
	releaseall
	end

PitBossDoublesArchie::
	trainerbattle_double TRAINER_ARCHIE_PIT_BOSS_DOUBLES, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_Text_NotEnoughMons, PitBoss_ArchieBattleFinished
	releaseall
	end

PitBoss_ArchieBattleFinished::
	lockall
	clearflag FLAG_START_ARCHIE_BATTLE
	msgbox Pit_EndGameStatue_Text1, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 11
	setflag FLAG_END_GAME_ARCHIE
	addobject 10
	clearflag FLAG_END_GAME_STATUE
	fadescreen FADE_FROM_BLACK
	callnative SetAutosaveFlag
	goto_if_unset FLAG_AUTO_SAVE, PitArchieNoAutoSave
	clearflag FLAG_SAVING_FIELD_EFFECT
	dofieldeffect(FLDEFF_SAVING)
	waitfieldeffect(FLDEFF_SAVING)
	callnative AutoSave
PitArchieNoAutoSave:
	releaseall
	end

Pit_EndGameStatue:: 
	lockall
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_NORTH, Pit_EndGameStatue222
	goto_if_eq VAR_RESULT, DIR_SOUTH, Pit_EndGameStatue222
	goto_if_eq VAR_RESULT, DIR_WEST, Pit_EndGameStatue4
	goto_if_eq VAR_RESULT, DIR_EAST, Pit_EndGameStatue3
	releaseall
	end

Pit_EndGameStatue3::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWestMovement
	waitmovement 0
	goto Pit_EndGameStatue222

Pit_EndGameStatue4::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerEastMovement
	waitmovement 0
	goto Pit_EndGameStatue222

PlayerWestMovement:
	walk_down
	walk_right
	face_up
	step_end

PlayerEastMovement:
	walk_down
	walk_left
	face_up
	step_end

Pit_EndGameStatue222::
	lockall
	callnative SetAutosaveFlag
	goto_if_unset FLAG_AUTO_SAVE, PitStatueNoAutoSave
	clearflag FLAG_SAVING_FIELD_EFFECT
	dofieldeffect(FLDEFF_SAVING)
	waitfieldeffect(FLDEFF_SAVING)
	callnative AutoSave
PitStatueNoAutoSave:
	msgbox Pit_EndGameStatue_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Pit_EndGameStatue2
	setvar VAR_REWARD_STATE, 2
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	additem 6
	additem 7
	callnative UpdateObjectEventsFromScript
	removeobject 10
	special HealPlayerParty
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	special DrawWholeMapView
	releaseall
	end

Pit_EndGameStatue2::
	msgbox Pit_EndGameStatue_Text3, MSGBOX_AUTOCLOSE 
	special GameClear
	waitstate
	releaseall
	end


Pit_EndGameStatue_Text1:
	.string "Congratulations, you have.\n"
	.string "completed the Pit of 100\l"
	.string "Trials....\p"
	.string "I hope your descent was\n"
	.string "pleasant.$"

Pit_EndGameStatue_Text2:
	.string "Do you want to keep going?$"

Pit_EndGameStatue_Text3:
	.string "Well, thanks for playing!$"
