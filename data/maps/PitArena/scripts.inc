PitArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PitArena_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PitArena_OnFrame
	.byte 0

PitArena_OnFrame:
	map_script_2 VAR_REWARD_STATE, 1, PitArena_OnFrameRewardDrop
	.2byte 0

PitArena_OnFrameRewardDrop::
	lockall
	setvar VAR_PIT_TUTOR_STATE, 0
	setvar VAR_REWARD_STATE, 2
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnFrameRewardDrop_4
	random 3
	switch VAR_RESULT
	case 0, PitArena_OnFrameRewardDrop_3
	case 1, PitArena_OnFrameRewardDrop_4
	case 2, PitArena_OnFrameRewardDrop_5
PitArena_OnFrameRewardDrop_1:
	callnative UpdateObjectEventsFromScript
	releaseall
	end

PitArena_OnFrameRewardDrop_3:
	clearflag FLAG_REWARD_ITEM_1
	addobject 6
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_4:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	addobject 6
	addobject 7
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnFrameRewardDrop_5:
	clearflag FLAG_REWARD_ITEM_1
	clearflag FLAG_REWARD_ITEM_2
	clearflag FLAG_REWARD_ITEM_3
	addobject 6
	addobject 7
	addobject 12
	goto PitArena_OnFrameRewardDrop_1

PitArena_OnResume:
	callnative CheckFloorCleared
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnResumeNormal
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setflashlevel 0
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_OnResumeNormal
	addvar VAR_REWARD_STATE, 1
	setflashlevel 1
PitArena_OnResumeNormal:
	end

PitArena_OnTransition:
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_OnTransitionNormal
PitArena_OnTransitionNormal::
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setflashlevel 1
	return

PitArena_Warp::
	callnative SetAutosaveFlag
	goto_if_unset FLAG_FLOOR_CLEARED, PitArena_WarpEnd
	goto_if_unset FLAG_AUTO_SAVE, PitArenaNoAutoSave
	clearflag FLAG_SAVING_FIELD_EFFECT
	dofieldeffect(FLDEFF_SAVING)
	waitfieldeffect(FLDEFF_SAVING)
	callnative AutoSave
PitArenaNoAutoSave::
	lockall
	addvar VAR_PIT_FLOOR, 1
	clearflag FLAG_FLOOR_CLEARED
	setflag FLAG_REWARD_ITEM_1
	setflag FLAG_REWARD_ITEM_2
	setflag FLAG_REWARD_ITEM_3
	setvar VAR_REWARD_STATE, 0
	callnative BufferMapFloorString
	callnative SetRandomTrainers
	goto_if_eq VAR_PIT_FLOOR, 100, PitArena_WarpFloor100
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	goto PitArena_WarpEnd
PitArena_WarpFloor100::
	setvar VAR_FINAL_FLOOR, 2
	setvar VAR_REWARD_STATE, 2
	warpteleport MAP_PIT_ARENA, 9, 11
	waitstate
PitArena_WarpEnd::
	releaseall
	end

PitArena_Archie::
	lockall
	setflag FLAG_START_ARCHIE_BATTLE
	special HealPlayerParty
	trainerbattle_single TRAINER_ARCHIE_PIT_BOSS, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_ArchieBattleFinished
	releaseall
	end

PitArena_ArchieBattleFinished::
	lockall
	clearflag FLAG_START_ARCHIE_BATTLE
	msgbox PitArena_EndGameStatue_Text1, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 11
	setflag FLAG_END_GAME_ARCHIE
	addobject 10
	clearflag FLAG_END_GAME_STATUE
	fadescreen FADE_FROM_BLACK
	releaseall
	end

PitArena_EndGameStatue:: 
	lockall
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_NORTH, PitArena_EndGameStatue222
	goto_if_eq VAR_RESULT, DIR_SOUTH, PitArena_EndGameStatue222
	goto_if_eq VAR_RESULT, DIR_WEST, PitArena_EndGameStatue4
	goto_if_eq VAR_RESULT, DIR_EAST, PitArena_EndGameStatue3
	releaseall
	end

PitArena_EndGameStatue3::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWestMovement
	waitmovement 0
	goto PitArena_EndGameStatue222

PitArena_EndGameStatue4::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerEastMovement
	waitmovement 0
	goto PitArena_EndGameStatue222

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

PitArena_EndGameStatue222::
	lockall
	msgbox PitArena_EndGameStatue_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitArena_EndGameStatue2
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

PitArena_EndGameStatue2::
	msgbox PitArena_EndGameStatue_Text3, MSGBOX_AUTOCLOSE 
	special GameClear
	waitstate
	releaseall
	end


PitArena_EndGameStatue_Text1:
	.string "Congratulations, you have.\n"
	.string "completed the Pit of 100\l"
	.string "Trials....\p"
	.string "I hope your descent was\n"
	.string "pleasant.$"

PitArena_EndGameStatue_Text2:
	.string "Do you want to keep going?$"

PitArena_EndGameStatue_Text3:
	.string "Well, thanks for playing!$"

PitArena_TrainerBattle::
	trainerbattle_single TRAINER_RANDOM_BATTLE_0, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle1::
	trainerbattle_single TRAINER_RANDOM_BATTLE_1, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle2::
	trainerbattle_single TRAINER_RANDOM_BATTLE_2, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_TrainerBattle3::
	trainerbattle_single TRAINER_RANDOM_BATTLE_3, PitArena_Text_Intro, PitArena_Text_Defeat, PitArena_TrainerBattleFinished
	end

PitArena_Text_Intro:
	.string ".$"

PitArena_Text_Defeat:
	.string ".$"

PitArena_TrainerBattleFinished::
	end

PitArena_Debug::
	releaseall
	end


PitArenaDebugNotOnWall::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setvar VAR_PIT_FLOOR, 24
	additem ITEM_RARE_CANDY, 99
	special DrawWholeMapView
	end

PitArena_Debug2::
	releaseall
	end

PitArenaDebug2NotOnWall::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 24
	special DrawWholeMapView
	end

PitArenaDebug3NotOnWall::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setvar VAR_PIT_FLOOR, 99
	additem ITEM_RARE_CANDY, 99
	special DrawWholeMapView
	end

PitArenaDebug4NotOnWall::
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	setvar VAR_PIT_FLOOR, 19
	additem ITEM_RARE_CANDY, 99
	special DrawWholeMapView
	end


PitArena_HealNPC::
	lockall
	faceplayer
	special HealPlayerParty
	msgbox PitArena_HealNPC_Text, MSGBOX_DEFAULT
	release
	end

PitArena_HealNPC_Text:
	.string "Your party has been healed.\p"
	.string "Have a nice descent.$"


PitArena_RewardDrop1::
	finditem ITEM_RARE_CANDY
	end

PitArena_RewardDrop2::
	finditem ITEM_NET_BALL
	end

PitArena_RewardDrop3::
	finditem ITEM_MAWILITE
	end

PitArena_NewMon::
	lockall
	callnative PlayerPartyCountToResultVar
	goto_if_eq VAR_RESULT, 6, PitArena_PartyFullRemoveOne
PitArenaNewMon2::
	callnative StartNewPokeballCaseUI
   	waitstate
	goto PitArena_EventScript_ReceiveMonParty
	release
	end

PitArena_EventScript_ReceiveMonParty::
	removeobject 8
	releaseall
	end

PitArena_PartyFullRemoveOne::
	message PitArena_GiveMonFullNothingChosen_Text1
	waitbuttonpress
	msgbox PitArena_GiveMonFullNothingChosen_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitArena_FullPartyNothingChosen
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, PitArena_FullPartyNothingChosen
	callnative RemovePartyPokemon
	goto PitArenaNewMon2
	release
	end

PitArena_FullPartyNothingChosen::
	release
	end

PitArena_GiveMonFullNothingChosen_Text1:
	.string "Your party is too full.$"

PitArena_GiveMonFullNothingChosen_Text2:
	.string "Do you want to get rid\n"
	.string "of a party member?$"

PitArena_Text_ReceivedMon:
	.string "{PLAYER} pulled a {STR_VAR_2}\n"
	.string "from the bag.$"


PitArena_MoveRelearner::
	lockall
	faceplayer
	showmoneybox 12, 11
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitArena_MoveRelearnerText, PitArena_EggMovesText, PitArena_TutorMovesText, PitArena_ShopNPC_Option8
	goto_if_eq VAR_RESULT, 0, PitArena_MartNPCMoveRelearner
	goto_if_eq VAR_RESULT, 1, PitArena_MartNPCMoveTutorEggMoves
	goto_if_eq VAR_RESULT, 2, PitArena_MartNPCMoveTutorTutorMoves
EndOfRelearnerScript::
	hidemoneybox
	release
	end

PitArena_MartNPCMoveRelearner::
	setvar VAR_PIT_TUTOR_STATE, 0
	hidemoneybox
	release
PitArena_MartNPCMoveTutor::
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EndOfRelearnerScript
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EndOfRelearnerScript
	goto_if_eq VAR_0x8005, 0, EndOfRelearnerScript
	special TeachMoveRelearnerMove
	waitstate
	goto EndOfRelearnerScript
	end

PitArena_MartNPCMoveTutorEggMoves::
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, PitArena_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	setvar VAR_PIT_TUTOR_STATE, 2
	hidemoneybox
	release
	goto PitArena_MartNPCMoveTutor
	end

PitArena_MartNPCMoveTutorTutorMoves::
	setvar VAR_PIT_TUTOR_STATE, 1
	hidemoneybox
	release
	special ShowTutorMoveList
	waitstate
	call_if_eq VAR_RESULT, 99, PitArena_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	release
	end

PitArena_MartNPCMoveTutorTutorMoves_NotEnoughMoney::
	hidemoneybox
	release
	lock
	msgbox PitArena_Tutor_NotGotTheMoney, MSGBOX_AUTOCLOSE
	release
	end

PitArena_Mover::
	lockall
	faceplayer
	message PitArena_NPCMoverOpen
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitArena_NPCMover2, PitArena_NPCMover3, PitArena_ShopNPC_Option8
	goto_if_eq VAR_RESULT, 0, PitArena_MoverSkip2
	goto_if_eq VAR_RESULT, 1, PitArena_MoverSkip3
	closemessage
EndOfMoverScript::
	release
	end

PitArena_NPCMoverOpen:
	.string "Do you want to pay to skip floors?$"

PitArena_MoverSkip2::
	checkmoney 3000
	goto_if_eq VAR_RESULT, FALSE, PitArena_Mover_NotEnoughMoney
	removemoney 3000
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 1
	special DrawWholeMapView
	goto PitArena_Warp
	release
	end

PitArena_MoverSkip3::
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, PitArena_Mover_NotEnoughMoney
	removemoney 5000
	setflag FLAG_FLOOR_CLEARED
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 2
	special DrawWholeMapView
	goto PitArena_Warp
	release
	end

PitArena_Mover_NotEnoughMoney:
	msgbox PitArena_NPCMoverNotEnoughMoneyText, MSGBOX_DEFAULT
	release
	end

PitArena_NPCMoverNotEnoughMoneyText:
	.string "Not enough money...$"

PitArena_NPCMover2:
	.string "2 Floors: ¥3000$"
PitArena_NPCMover3:
	.string "3 Floors: ¥5000$"

PitArena_ShopNPC::
	lockall
	faceplayer
	setvar VAR_TEMP_9, 0
PitArena_ShopNPCHook::
	message PitArena_ShopNPC_Text
#ifndef RANDOM_GEN_5_MODE
	goto_if_unset FLAG_STAT_CHANGER, PitArena_ShopNPCHook_GenNewIVs
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitArena_ShopNPC_Option0, PitArena_ShopNPC_Option1, PitArena_ShopNPC_OptionVitamin, PitArena_ShopNPC_Option2, PitArena_ShopNPC_Option3, PitArena_ShopNPC_Option4, PitArena_ShopNPC_Option5, PitArena_ShopNPC_Option6, PitArena_ShopNPC_Option7, PitArena_ShopNPC_Option8
#else
	goto_if_unset FLAG_STAT_CHANGER, PitArena_ShopNPCHook_Gen5IVs
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitArena_ShopNPC_Option0, PitArena_ShopNPC_Option1, PitArena_ShopNPC_OptionVitamin, PitArena_ShopNPC_Option3, PitArena_ShopNPC_Option4, PitArena_ShopNPC_Option6, PitArena_ShopNPC_Option7, PitArena_ShopNPC_Option8
#endif
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
#ifndef RANDOM_GEN_5_MODE
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_MegaStones
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_ZCrystals
	goto_if_eq VAR_RESULT, 7, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 8, PitArena_MartScript_Sell
#else
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_Sell
#endif
EndOfMartScript::
	clearflag FLAG_SELL_FROM_MART
	clearflag FLAG_BUY_FROM_MART
	release
	end

PitArena_ShopNPCHook_GenNewIVs::
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitArena_ShopNPC_Option0, PitArena_ShopNPC_Option1, PitArena_ShopNPC_OptionVitamin, PitArena_ShopNPC_Option2, PitArena_ShopNPC_Option3, PitArena_ShopNPC_Option4, PitArena_ShopNPC_Option5, PitArena_ShopNPC_Option6, PitArena_ShopNPC_EditIVs, PitArena_ShopNPC_Option7, PitArena_ShopNPC_Option8
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_MegaStones
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_ZCrystals
	goto_if_eq VAR_RESULT, 7, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 8, PitArena_MartScript_EditIVs
	goto_if_eq VAR_RESULT, 9, PitArena_MartScript_Sell
	release
	end

PitArena_ShopNPCHook_Gen5IVs::
	dynmultichoice 17, 1, 0, 5, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitArena_ShopNPC_Option0, PitArena_ShopNPC_Option1, PitArena_ShopNPC_OptionVitamin, PitArena_ShopNPC_Option3, PitArena_ShopNPC_Option4, PitArena_ShopNPC_Option6, PitArena_ShopNPC_EditIVs, PitArena_ShopNPC_Option7, PitArena_ShopNPC_Option8
	closemessage
	setflag FLAG_BUY_FROM_MART
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitArena_MartScript_TMs
	goto_if_eq VAR_RESULT, 1, PitArena_MartScript_EvoItems
	goto_if_eq VAR_RESULT, 2, PitArena_MartScript_Vitamins
	goto_if_eq VAR_RESULT, 3, PitArena_MartScript_Mints
	goto_if_eq VAR_RESULT, 4, PitArena_MartScript_Gems
	goto_if_eq VAR_RESULT, 5, PitArena_MartScript_FormItems
	goto_if_eq VAR_RESULT, 6, PitArena_MartScript_EditIVs
	goto_if_eq VAR_RESULT, 7, PitArena_MartScript_Sell
	release
	end

PitArena_MartScript_Vitamins:
	setflag FLAG_BUY_FROM_MART
	pokemart PitArena_Mart_Vitamins
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end 

PitArena_MartScript_TMs:
	setflag FLAG_BUY_FROM_MART
	pokemart PitArena_Mart_TMs
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end 

PitArena_MartScript_EvoItems:
	setflag FLAG_BUY_FROM_MART
	pokemart PitArena_Mart_EvoItems
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_MegaStones:
	pokemart PitArena_Mart_MegaStones
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Mints::
	pokemart PitArena_Mart_Mints
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Gems::
	pokemart PitArena_Mart_Gems
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_ZCrystals::
	pokemart PitArena_Mart_ZCrystals
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_FormItems::
	pokemart PitArena_Mart_FormItems
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_EditIVs::
	showmoneybox 0, 0
	msgbox PitArena_ShopNPC_IV_Text, MSGBOX_YESNO
	hidemoneybox
	release
	lock
	goto_if_eq VAR_RESULT, NO, PitArena_ShopNPCHook
	checkmoney 3000
	goto_if_eq VAR_RESULT, FALSE, PitArena_MartScript_EditIVs_NotEnoughMoney
	removemoney 3000
	call PitArena_MartScript_EditIVs_Execute
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_Sell::
	clearflag FLAG_BUY_FROM_MART
	setflag FLAG_SELL_FROM_MART
	pokemart PitArena_Mart_EvoItems
	goto PitArena_ShopNPCHook
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitArena_MartScript_EditIVs_NotEnoughMoney::
	msgbox PitArena_Tutor_NotGotTheMoney, MSGBOX_DEFAULT
	goto PitArena_ShopNPCHook
	release
	end

PitArena_MartScript_EditIVs_Execute::
	setvar VAR_PIT_TUTOR_STATE, 3
	setflag FLAG_STAT_EDIT_PAID
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PitArena_ShopNPCHook
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PitArena_ShopNPCHook
	special CallStatEditor
	waitstate
	goto PitArena_ShopNPCHook
	release
	end


PitArena_ShopNPC_Option0:
	.string "TMs    $"
PitArena_ShopNPC_Option1:
	.string "Evos$"
PitArena_ShopNPC_Option2:
	.string "Megas$"
PitArena_ShopNPC_Option3:
	.string "Mints   $"
PitArena_ShopNPC_Option4:
	.string "Gems$"
PitArena_ShopNPC_Option5:
	.string "Z-Moves$"
PitArena_ShopNPC_Option6:
	.string "Forms$"
PitArena_ShopNPC_Option7:
	.string "Sell$"
PitArena_ShopNPC_Option8:
	.string "Exit$"
PitArena_ShopNPC_EditIVs:
	.string "Edit IVs$"
PitArena_MoveRelearnerText:
	.string "Move Relearner (free)$"
PitArena_EggMovesText:
	.string "Egg Moves (¥10,000)$"
PitArena_TutorMovesText:
	.string "Tutor Moves (¥10,000)$"
PitArena_ShopNPC_OptionVitamin:
	.string "Vitamins$"
PitArena_ShopNPC_Text:
	.string "How may I assist you?$"
PitArena_ShopNPC_IV_Text:
	.string "Your Pokémon are at max IVs by default.\n"
	.string "Still want to change it for ¥3,000?$"

PitArena_Tutor_ConfirmMoveSelection_Text_0:
	.string "The move {STR_VAR_1}, is it?$"
PitArena_Tutor_ConfirmMoveSelection_Text_1:
	.string "That will be ¥{STR_VAR_2}, okay?$"
PitArena_Tutor_ConfirmMoveSelection_Text_2:
	.string "Alright. Come back anytime you want.$"
PitArena_Tutor_NotGotTheMoney:
	.string "Oh, you don't have enough money!$"


	.align 2
PitArena_Mart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_HEALTH_FEATHER
	.2byte ITEM_MUSCLE_FEATHER
	.2byte ITEM_RESIST_FEATHER
	.2byte ITEM_GENIUS_FEATHER
	.2byte ITEM_CLEVER_FEATHER
	.2byte ITEM_SWIFT_FEATHER
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_EvoItems:
	.2byte ITEM_EVERSTONE
	.2byte ITEM_FIRE_STONE
    .2byte ITEM_WATER_STONE
    .2byte ITEM_THUNDER_STONE
    .2byte ITEM_LEAF_STONE
    .2byte ITEM_ICE_STONE
    .2byte ITEM_SUN_STONE
    .2byte ITEM_MOON_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
	.2byte ITEM_LINKING_CORD
    .2byte ITEM_DRAGON_SCALE
    .2byte ITEM_UPGRADE
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
    .2byte ITEM_PROTECTOR
    .2byte ITEM_ELECTIRIZER
    .2byte ITEM_MAGMARIZER
    .2byte ITEM_DUBIOUS_DISC
    .2byte ITEM_REAPER_CLOTH
    .2byte ITEM_PRISM_SCALE
    .2byte ITEM_WHIPPED_DREAM
    .2byte ITEM_SACHET
	.2byte ITEM_PEAT_BLOCK
    .2byte ITEM_OVAL_STONE
    .2byte ITEM_SWEET_APPLE
    .2byte ITEM_TART_APPLE
    .2byte ITEM_SYRUPY_APPLE
    .2byte ITEM_CRACKED_POT
    .2byte ITEM_CHIPPED_POT
    .2byte ITEM_GALARICA_CUFF
    .2byte ITEM_GALARICA_WREATH
    .2byte ITEM_SCROLL_OF_DARKNESS
    .2byte ITEM_SCROLL_OF_WATERS
    .2byte ITEM_METAL_ALLOY
    .2byte ITEM_AUSPICIOUS_ARMOR
    .2byte ITEM_MALICIOUS_ARMOR
    .2byte ITEM_UNREMARKABLE_TEACUP
    .2byte ITEM_MASTERPIECE_TEACUP
    .2byte ITEM_STRAWBERRY_SWEET
    .2byte ITEM_LOVE_SWEET
    .2byte ITEM_BERRY_SWEET
    .2byte ITEM_CLOVER_SWEET
    .2byte ITEM_FLOWER_SWEET
    .2byte ITEM_STAR_SWEET
    .2byte ITEM_RIBBON_SWEET
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_MegaStones:
	.2byte ITEM_RED_ORB
    .2byte ITEM_BLUE_ORB
	.2byte ITEM_VENUSAURITE
    .2byte ITEM_CHARIZARDITE_X
    .2byte ITEM_CHARIZARDITE_Y
    .2byte ITEM_BLASTOISINITE
    .2byte ITEM_BEEDRILLITE
    .2byte ITEM_PIDGEOTITE
    .2byte ITEM_ALAKAZITE
    .2byte ITEM_SLOWBRONITE
    .2byte ITEM_GENGARITE
    .2byte ITEM_KANGASKHANITE
    .2byte ITEM_PINSIRITE
    .2byte ITEM_GYARADOSITE
    .2byte ITEM_AERODACTYLITE
    .2byte ITEM_MEWTWONITE_X
    .2byte ITEM_MEWTWONITE_Y
    .2byte ITEM_AMPHAROSITE
    .2byte ITEM_STEELIXITE
    .2byte ITEM_SCIZORITE
    .2byte ITEM_HERACRONITE
    .2byte ITEM_HOUNDOOMINITE
    .2byte ITEM_TYRANITARITE
    .2byte ITEM_SCEPTILITE
    .2byte ITEM_BLAZIKENITE
    .2byte ITEM_SWAMPERTITE
    .2byte ITEM_GARDEVOIRITE
    .2byte ITEM_SABLENITE
    .2byte ITEM_MAWILITE
    .2byte ITEM_AGGRONITE
    .2byte ITEM_MEDICHAMITE
    .2byte ITEM_MANECTITE
    .2byte ITEM_SHARPEDONITE
    .2byte ITEM_CAMERUPTITE
    .2byte ITEM_ALTARIANITE
    .2byte ITEM_BANETTITE
    .2byte ITEM_ABSOLITE
    .2byte ITEM_GLALITITE
    .2byte ITEM_SALAMENCITE
    .2byte ITEM_METAGROSSITE
    .2byte ITEM_LATIASITE
    .2byte ITEM_LATIOSITE
    .2byte ITEM_LOPUNNITE
    .2byte ITEM_GARCHOMPITE
    .2byte ITEM_LUCARIONITE
    .2byte ITEM_ABOMASITE
    .2byte ITEM_GALLADITE
    .2byte ITEM_AUDINITE
    .2byte ITEM_DIANCITE
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_Mints:
	.2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_ABILITY_PATCH
	.2byte ITEM_LONELY_MINT
    .2byte ITEM_ADAMANT_MINT
    .2byte ITEM_NAUGHTY_MINT
    .2byte ITEM_BRAVE_MINT
    .2byte ITEM_BOLD_MINT
    .2byte ITEM_IMPISH_MINT
    .2byte ITEM_LAX_MINT
    .2byte ITEM_RELAXED_MINT
    .2byte ITEM_MODEST_MINT
    .2byte ITEM_MILD_MINT
    .2byte ITEM_RASH_MINT
    .2byte ITEM_QUIET_MINT
    .2byte ITEM_CALM_MINT
    .2byte ITEM_GENTLE_MINT
    .2byte ITEM_CAREFUL_MINT
    .2byte ITEM_SASSY_MINT
    .2byte ITEM_TIMID_MINT
    .2byte ITEM_HASTY_MINT
    .2byte ITEM_JOLLY_MINT
    .2byte ITEM_NAIVE_MINT
    .2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE
	release
	end

	.align 2
PitArena_Mart_Gems:
    .2byte ITEM_NORMAL_GEM
    .2byte ITEM_FIRE_GEM
    .2byte ITEM_WATER_GEM
    .2byte ITEM_ELECTRIC_GEM
    .2byte ITEM_GRASS_GEM
    .2byte ITEM_ICE_GEM
    .2byte ITEM_FIGHTING_GEM
    .2byte ITEM_POISON_GEM
    .2byte ITEM_GROUND_GEM
    .2byte ITEM_FLYING_GEM
    .2byte ITEM_PSYCHIC_GEM
    .2byte ITEM_BUG_GEM
    .2byte ITEM_ROCK_GEM
    .2byte ITEM_GHOST_GEM
    .2byte ITEM_DRAGON_GEM
    .2byte ITEM_DARK_GEM
    .2byte ITEM_STEEL_GEM
    .2byte ITEM_FAIRY_GEM
	.2byte ITEM_NONE
	release
	end

 	.align 2
PitArena_Mart_ZCrystals:
    .2byte ITEM_NORMALIUM_Z
    .2byte ITEM_FIRIUM_Z
    .2byte ITEM_WATERIUM_Z
    .2byte ITEM_ELECTRIUM_Z
    .2byte ITEM_GRASSIUM_Z
    .2byte ITEM_ICIUM_Z
    .2byte ITEM_FIGHTINIUM_Z
    .2byte ITEM_POISONIUM_Z
    .2byte ITEM_GROUNDIUM_Z
    .2byte ITEM_FLYINIUM_Z
    .2byte ITEM_PSYCHIUM_Z
    .2byte ITEM_BUGINIUM_Z
    .2byte ITEM_ROCKIUM_Z
    .2byte ITEM_GHOSTIUM_Z
    .2byte ITEM_DRAGONIUM_Z
    .2byte ITEM_DARKINIUM_Z
    .2byte ITEM_STEELIUM_Z
    .2byte ITEM_FAIRIUM_Z
    .2byte ITEM_PIKANIUM_Z
    .2byte ITEM_EEVIUM_Z
    .2byte ITEM_SNORLIUM_Z
    .2byte ITEM_MEWNIUM_Z
    .2byte ITEM_DECIDIUM_Z
    .2byte ITEM_INCINIUM_Z
    .2byte ITEM_PRIMARIUM_Z
    .2byte ITEM_LYCANIUM_Z
    .2byte ITEM_MIMIKIUM_Z
    .2byte ITEM_KOMMONIUM_Z
    .2byte ITEM_TAPUNIUM_Z
    .2byte ITEM_SOLGANIUM_Z
    .2byte ITEM_LUNALIUM_Z
    .2byte ITEM_MARSHADIUM_Z
    .2byte ITEM_ALORAICHIUM_Z
    .2byte ITEM_PIKASHUNIUM_Z
    .2byte ITEM_ULTRANECROZIUM_Z
	.2byte ITEM_NONE
    release
	end

 	.align 2
PitArena_Mart_FormItems:
    .2byte  ITEM_FLAME_PLATE
    .2byte  ITEM_SPLASH_PLATE
    .2byte  ITEM_ZAP_PLATE
    .2byte  ITEM_MEADOW_PLATE
    .2byte  ITEM_ICICLE_PLATE
    .2byte  ITEM_FIST_PLATE
    .2byte  ITEM_TOXIC_PLATE
    .2byte  ITEM_EARTH_PLATE
    .2byte  ITEM_SKY_PLATE
    .2byte  ITEM_MIND_PLATE
    .2byte  ITEM_INSECT_PLATE
    .2byte  ITEM_STONE_PLATE
    .2byte  ITEM_SPOOKY_PLATE
    .2byte  ITEM_DRACO_PLATE
    .2byte  ITEM_DREAD_PLATE
    .2byte  ITEM_IRON_PLATE
    .2byte  ITEM_PIXIE_PLATE
    .2byte  ITEM_DOUSE_DRIVE
    .2byte  ITEM_SHOCK_DRIVE
    .2byte  ITEM_BURN_DRIVE
    .2byte  ITEM_CHILL_DRIVE
    .2byte  ITEM_RUSTED_SWORD
    .2byte  ITEM_RUSTED_SHIELD
	.2byte  ITEM_YELLOW_NECTAR
    .2byte  ITEM_PINK_NECTAR
    .2byte  ITEM_PURPLE_NECTAR
	.2byte  ITEM_FIRE_MEMORY
    .2byte  ITEM_WATER_MEMORY
    .2byte  ITEM_ELECTRIC_MEMORY
    .2byte  ITEM_GRASS_MEMORY
    .2byte  ITEM_ICE_MEMORY
    .2byte  ITEM_FIGHTING_MEMORY
    .2byte  ITEM_POISON_MEMORY
    .2byte  ITEM_GROUND_MEMORY
    .2byte  ITEM_FLYING_MEMORY
    .2byte  ITEM_PSYCHIC_MEMORY
    .2byte  ITEM_BUG_MEMORY
    .2byte  ITEM_ROCK_MEMORY
    .2byte  ITEM_GHOST_MEMORY
    .2byte  ITEM_DRAGON_MEMORY
    .2byte  ITEM_DARK_MEMORY
    .2byte  ITEM_STEEL_MEMORY
    .2byte  ITEM_FAIRY_MEMORY
	.2byte ITEM_NONE
    release
	end

 	.align 2
PitArena_Mart_TMs:
	.2byte ITEM_TM01
	.2byte ITEM_TM02
	.2byte ITEM_TM03
	.2byte ITEM_TM04
	.2byte ITEM_TM05
	.2byte ITEM_TM06
	.2byte ITEM_TM07
	.2byte ITEM_TM08
	.2byte ITEM_TM09
	.2byte ITEM_TM10
	.2byte ITEM_TM11
	.2byte ITEM_TM12
	.2byte ITEM_TM13
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_TM16
	.2byte ITEM_TM17
	.2byte ITEM_TM18
	.2byte ITEM_TM19
	.2byte ITEM_TM20
	.2byte ITEM_TM21
	.2byte ITEM_TM22
	.2byte ITEM_TM23
	.2byte ITEM_TM24
	.2byte ITEM_TM25
	.2byte ITEM_TM26
	.2byte ITEM_TM27
	.2byte ITEM_TM28
	.2byte ITEM_TM29
	.2byte ITEM_TM30
	.2byte ITEM_TM31
	.2byte ITEM_TM32
	.2byte ITEM_TM33
	.2byte ITEM_TM34
	.2byte ITEM_TM35
	.2byte ITEM_TM36
	.2byte ITEM_TM37
	.2byte ITEM_TM38
	.2byte ITEM_TM39
	.2byte ITEM_TM40
	.2byte ITEM_TM41
	.2byte ITEM_TM42
	.2byte ITEM_TM43
	.2byte ITEM_TM44
	.2byte ITEM_TM45
	.2byte ITEM_TM46
	.2byte ITEM_TM47
	.2byte ITEM_TM48
	.2byte ITEM_TM49
	.2byte ITEM_TM50
	.2byte ITEM_TM51
	.2byte ITEM_TM52
	.2byte ITEM_TM53
	.2byte ITEM_TM54
	.2byte ITEM_TM55
	.2byte ITEM_TM56
	.2byte ITEM_TM57
	.2byte ITEM_TM58
	.2byte ITEM_TM59
	.2byte ITEM_TM60
	.2byte ITEM_TM61
	.2byte ITEM_TM62
	.2byte ITEM_TM63
	.2byte ITEM_TM64
	.2byte ITEM_TM65
	.2byte ITEM_TM66
	.2byte ITEM_TM67
	.2byte ITEM_TM68
	.2byte ITEM_TM69
	.2byte ITEM_TM70
	.2byte ITEM_TM71
	.2byte ITEM_TM72
	.2byte ITEM_TM73
	.2byte ITEM_TM74
	.2byte ITEM_TM75
	.2byte ITEM_TM76
	.2byte ITEM_TM77
	.2byte ITEM_TM78
	.2byte ITEM_TM79
	.2byte ITEM_TM80
	.2byte ITEM_TM81
	.2byte ITEM_TM82
	.2byte ITEM_TM83
	.2byte ITEM_TM84
	.2byte ITEM_TM85
	.2byte ITEM_TM86
	.2byte ITEM_TM87
	.2byte ITEM_TM88
	.2byte ITEM_TM89
	.2byte ITEM_TM90
	.2byte ITEM_TM91
	.2byte ITEM_TM92
	.2byte ITEM_TM93
	.2byte ITEM_TM94
	.2byte ITEM_TM95
	.2byte ITEM_TM96
	.2byte ITEM_TM97
	.2byte ITEM_TM98
	.2byte ITEM_TM99
	.2byte ITEM_TM100
	.2byte ITEM_HM01
	.2byte ITEM_HM02
	.2byte ITEM_HM03
	.2byte ITEM_HM04
	.2byte ITEM_HM05
	.2byte ITEM_HM06
	.2byte ITEM_HM07
	.2byte ITEM_HM08
	.2byte ITEM_NONE
    release
	end
