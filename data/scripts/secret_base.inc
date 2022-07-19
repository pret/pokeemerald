SecretBase_Text_TreeCanBeClimbed:
	.string "On peut grimper à cet arbre si une liane\n"
	.string "en descend.$"

SecretBase_Text_TreeUseSecretPower:
	.string "On peut grimper à cet arbre si une liane\n"
	.string "en descend.\p"
	.string "Voulez-vous utiliser FORCE CACHEE?$"

SecretBase_Text_VineDroppedDown:
	.string "Une liane épaisse est tombée de l’arbre!$"

SecretBase_Text_ClumpOfGrass:
	.string "On peut pénétrer à l’intérieur\n"
	.string "en déplaçant ce massif d’herbe.$"

SecretBase_Text_ClumpUseSecretPower:
	.string "On peut pénétrer à l’intérieur\n"
	.string "en déplaçant ce massif d’herbe.\p"
	.string "Voulez-vous utiliser FORCE CACHEE?$"

SecretBase_Text_DiscoveredSmallEntrance:
	.string "Une petite entrée a été découverte!$"

	.include "data/text/secret_base_trainers.inc"

SecretBase_EventScript_CheckEntrance::
	special GetSecretBaseTypeInFrontOfPlayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, TRUE, SecretBase_EventScript_AlreadyHasSecretBase
	checkpartymove MOVE_SECRET_POWER
	setfieldeffectargument 0, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_Tree
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_Shrub
	end

SecretBase_EventScript_Cave::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_CaveNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_IndentUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveNoSecretPower::
	msgbox SecretBase_Text_SmallIndentInWall, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_CaveEnter::
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Tree::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_TreeNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_TreeUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeNoSecretPower::
	msgbox SecretBase_Text_TreeCanBeClimbed, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_TreeEnter::
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Shrub::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_ShrubNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_ClumpUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubNoSecretPower::
	msgbox SecretBase_Text_ClumpOfGrass, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_ShrubEnter::
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_InitSecretBase::
	closemessage
	playse SE_EXIT
	setvar VAR_INIT_SECRET_BASE, 0
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	waitstate
	end

SecretBase_EventScript_FirstEntrance::
	applymovement OBJ_EVENT_ID_PLAYER, SecretBase_Movement_EnterBase
	waitmovement 0
	setvar VAR_INIT_SECRET_BASE, 1
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SecretBase_EventScript_SetAsBase
	closemessage
	playse SE_EXIT
	special ClearAndLeaveSecretBase
	end

SecretBase_EventScript_SetAsBase::
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	special EnterNewlyCreatedSecretBase
	waitstate
	end

SecretBase_Movement_EnterBase:
	walk_up
	walk_up
	step_end

SecretBase_EventScript_Enter::
	lockall
	setvar VAR_INIT_SECRET_BASE, 1
	playse SE_EXIT
	special IsCurSecretBaseOwnedByAnotherPlayer
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_EnterPlayersBase
	clearflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_EnterPlayersBase::
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_AlreadyHasSecretBase::
	checkpartymove MOVE_SECRET_POWER
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_NoSecretPower
	setfieldeffectargument 0, VAR_RESULT
	setorcopyvar VAR_0x8004, VAR_RESULT
	lockall
	special GetSecretBaseNearbyMapName
	msgbox SecretBase_Text_WouldYouLikeToMoveBases, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	fadescreenswapbuffers FADE_TO_BLACK
	special MoveOutOfSecretBaseFromOutside
	closemessage
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SecretBase_Text_MovingCompletedUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	closemessage
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubUseSecretPower
	releaseall
	end

SecretBase_EventScript_NoSecretPower::
	lockall
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubNoSecretPower
	end

SecretBase_EventScript_CancelOnEntrance::
	closemessage
	releaseall
	end

SecretBase_EventScript_SetDecorationFlags::
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	setflag FLAG_DECORATION_13
	setflag FLAG_DECORATION_14
	return

SecretBase_EventScript_InitDecorations::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SecretBase_EventScript_SetDecoration::
	setvar VAR_0x8005, 0
	goto SecretBase_EventScript_SetDecoration2
	end

SecretBase_EventScript_SetDecoration2::
	special SetDecoration
	end

SecretBase_EventScript_PutAwayDecoration::
	setvar VAR_0x8004, 0
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationLoop::
	special PutAwayDecorationIteration
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_PutAwayDecorationEnd
	addvar VAR_0x8004, 1
	goto_if_eq VAR_0x8005, 0, SecretBase_EventScript_PutAwayDecorationLoop
	removeobject VAR_0x8006
	setflag VAR_0x8005  @ UB: VAR_0x8005 is set to a flag by PutAwayDecorationIteration, but ScrCmd_setflag doesn't use VarGet
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationEnd::
	end

SecretBase_EventScript_RecordMixTrainer::
	special GetSecretBaseOwnerAndState
	goto_if_eq VAR_0x8004, 0, SecretBase_EventScript_Trainer0
	goto_if_eq VAR_0x8004, 1, SecretBase_EventScript_Trainer1
	goto_if_eq VAR_0x8004, 2, SecretBase_EventScript_Trainer2
	goto_if_eq VAR_0x8004, 3, SecretBase_EventScript_Trainer3
	goto_if_eq VAR_0x8004, 4, SecretBase_EventScript_Trainer4
	goto_if_eq VAR_0x8004, 5, SecretBase_EventScript_Trainer5
	goto_if_eq VAR_0x8004, 6, SecretBase_EventScript_Trainer6
	goto_if_eq VAR_0x8004, 7, SecretBase_EventScript_Trainer7
	goto_if_eq VAR_0x8004, 8, SecretBase_EventScript_Trainer8
	goto_if_eq VAR_0x8004, 9, SecretBase_EventScript_Trainer9
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer0::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer0PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer0PostBattle
	msgbox SecretBase_Text_Trainer0Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer0DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer0DeclineBattle
	msgbox SecretBase_Text_Trainer0AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer0PreChampion::
	msgbox SecretBase_Text_Trainer0PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer0DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer0DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer0PostBattle::
	msgbox SecretBase_Text_Trainer0PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer1PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer1PostBattle
	msgbox SecretBase_Text_Trainer1Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer1DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer1DeclineBattle
	msgbox SecretBase_Text_Trainer1AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer1PreChampion::
	msgbox SecretBase_Text_Trainer1PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer1DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer1DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer1PostBattle::
	msgbox SecretBase_Text_Trainer1PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer2::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer2PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer2PostBattle
	msgbox SecretBase_Text_Trainer2Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer2DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer2DeclineBattle
	msgbox SecretBase_Text_Trainer2AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer2PreChampion::
	msgbox SecretBase_Text_Trainer2PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer2DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer2DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer2PostBattle::
	msgbox SecretBase_Text_Trainer2PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer3::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer3PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer3PostBattle
	msgbox SecretBase_Text_Trainer3Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer3DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer3DeclineBattle
	msgbox SecretBase_Text_Trainer3AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer3PreChampion::
	msgbox SecretBase_Text_Trainer3PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer3DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer3DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer3PostBattle::
	msgbox SecretBase_Text_Trainer3PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer4::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer4PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer4PostBattle
	msgbox SecretBase_Text_Trainer4Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer4DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer4DeclineBattle
	msgbox SecretBase_Text_Trainer4AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer4PreChampion::
	msgbox SecretBase_Text_Trainer4PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer4DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer4DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer4PostBattle::
	msgbox SecretBase_Text_Trainer4PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer5::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer5PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer5PostBattle
	msgbox SecretBase_Text_Trainer5Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer5DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer5DeclineBattle
	msgbox SecretBase_Text_Trainer5AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer5PreChampion::
	msgbox SecretBase_Text_Trainer5PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer5DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer5DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer5PostBattle::
	msgbox SecretBase_Text_Trainer5PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer6::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer6PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer6PostBattle
	msgbox SecretBase_Text_Trainer6Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer6DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer6DeclineBattle
	msgbox SecretBase_Text_Trainer6AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer6PreChampion::
	msgbox SecretBase_Text_Trainer6PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer6DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer6DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer6PostBattle::
	msgbox SecretBase_Text_Trainer6PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer7::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer7PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer7PostBattle
	msgbox SecretBase_Text_Trainer7Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer7DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer7DeclineBattle
	msgbox SecretBase_Text_Trainer7AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer7PreChampion::
	msgbox SecretBase_Text_Trainer7PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer7DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer7DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer7PostBattle::
	msgbox SecretBase_Text_Trainer7PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer8::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer8PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer8PostBattle
	msgbox SecretBase_Text_Trainer8Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer8DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer8DeclineBattle
	msgbox SecretBase_Text_Trainer8AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer8PreChampion::
	msgbox SecretBase_Text_Trainer8PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer8DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer8DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer8PostBattle::
	msgbox SecretBase_Text_Trainer8PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer9::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer9PreChampion
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_Trainer9PostBattle
	msgbox SecretBase_Text_Trainer9Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_Trainer9DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_Trainer9DeclineBattle
	msgbox SecretBase_Text_Trainer9AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer9PreChampion::
	msgbox SecretBase_Text_Trainer9PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer9DeclineBattle::
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer9DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer9PostBattle::
	msgbox SecretBase_Text_Trainer9PostBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_BattleTrainer::
	special PrepSecretBaseBattleFlags
	setvar VAR_0x8004, SPECIAL_BATTLE_SECRET_BASE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	call_if_eq VAR_RESULT, B_OUTCOME_DREW, SecretBase_EventScript_DrewSecretBaseBattle
	call_if_eq VAR_RESULT, B_OUTCOME_WON, SecretBase_EventScript_WonSecretBaseBattle
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, SecretBase_EventScript_LostSecretBaseBattle
	special HealPlayerParty
	release
	end

SecretBase_EventScript_DrewSecretBaseBattle::
	special DrewSecretBaseBattle
	return

SecretBase_EventScript_WonSecretBaseBattle::
	special WonSecretBaseBattle
	return

SecretBase_EventScript_LostSecretBaseBattle::
	special LostSecretBaseBattle
	return

	.include "data/scripts/secret_power_tm.inc"

SecretBase_EventScript_DollInteract::
	special CheckInteractedWithFriendsDollDecor
	end

SecretBase_EventScript_CushionInteract::
	special CheckInteractedWithFriendsCushionDecor
	end

SecretBase_Text_AllDecorationsWillBeReturned:
	.string "Les décorations et meubles de la BASE\n"
	.string "SECRETE seront transférés sur le PC.\p"
	.string "Continuer?$"

SecretBase_Text_WantToRegisterSecretBase:
	.string "Sauvegarder les données de la\n"
	.string "BASE SECRETE de {STR_VAR_1}?$"

SecretBase_Text_AlreadyRegisteredDelete:
	.string "Ces données sont déjà sauvegardées.\n"
	.string "Les effacer?$"

SecretBase_Text_TooManyBasesDeleteSome:
	.string "Vous pouvez sauvegarder jusqu’à\n"
	.string "dix lieux.\p"
	.string "Supprimez un lieu pour sauvegarder\n"
	.string "les données d’un nouveau lieu.$"

SecretBase_Text_RegistrationCompleted:
	.string "Sauvegarde terminée.$"

SecretBase_Text_DataUnregistered:
	.string "Les données n’ont pas été\n"
	.string "sauvegardées.$"

SecretBase_Text_BootUpPC:
	.string "{PLAYER} allume le PC.$"

SecretBase_Text_WhatWouldYouLikeToDo:
	.string "Que voulez-vous faire?$"

SecretBase_Text_RegistryInfo:
	.string "A moins que le propriétaire ne parte, la\n"
	.string "BASE SECRETE sauvegardée subsistera.\p"
	.string "Si la sauvegarde est effacée, une autre\n"
	.string "BASE SECRETE peut prendre sa place.\p"
	.string "Vous pouvez sauvegarder jusqu’à\n"
	.string "dix lieux.$"

SecretBase_Text_BattleTowerShield:
	.string "Une plaque en {STR_VAR_2}, qui certifie\n"
	.string "l’obtention de {STR_VAR_1} victoires\l"
	.string "consécutives à la TOUR DE COMBAT.$"

SecretBase_Text_ToyTV:
	.string "Une fausse TV. Elle pourrait\n"
	.string "être prise pour une vraie.$"

SecretBase_Text_SeedotTV:
	.string "Une fausse TV en forme de GRAINIPIOT.\n"
	.string "Elle semble pouvoir rouler sur\l"
	.string "elle-même.$"

SecretBase_Text_SkittyTV:
	.string "Une fausse TV en forme de SKITTY.\n"
	.string "Elle semble pouvoir vadrouiller…$"

SecretBase_Text_WouldYouLikeToMoveBases:
	.string "Vous ne pouvez avoir qu’une seule\n"
	.string "BASE SECRETE.\p"
	.string "Voulez-vous déplacer ici la BASE \n"
	.string "SECRETE déjà créée {STR_VAR_1}?$"

SecretBase_Text_MovingCompletedUseSecretPower:
	.string "Déplacement terminé.\p"
	.string "Voulez-vous utiliser FORCE CACHEE?$"

