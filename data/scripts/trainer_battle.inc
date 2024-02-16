EventScript_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
EventScript_TrainerApproach::
	special PlayTrainerEncounterMusic
	special DoTrainerApproach
	waitstate
	goto EventScript_ShowTrainerIntroMsg

EventScript_TryDoNormalTrainerBattle::
	lock
	faceplayer
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	specialvar VAR_RESULT, GetTrainerFlag
	goto_if_ne VAR_RESULT, FALSE, EventScript_NoNormalTrainerBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NoNormalTrainerBattle::
	gotopostbattlescript

EventScript_TryDoDoubleTrainerBattle::
	lock
	faceplayer
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, GetTrainerFlag
	goto_if_ne VAR_RESULT, FALSE, EventScript_NoDoubleTrainerBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NotEnoughMonsForDoubleBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_NoDoubleTrainerBattle::
	gotopostbattlescript

EventScript_DoNoIntroTrainerBattle::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	special PlayTrainerEncounterMusic
	dotrainerbattle
	gotopostbattlescript

EventScript_TryDoRematchBattle::
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoRematchTrainerBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_NoRematchTrainerBattle::
	gotopostbattlescript

EventScript_TryDoDoubleRematchBattle::
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoDoubleRematchTrainerBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleRematchBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_NoDoubleRematchTrainerBattle::
	gotopostbattlescript

EventScript_NotEnoughMonsForDoubleRematchBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_RevealTrainer::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Movement_RevealTrainer:
	reveal_trainer
	step_end

EventScript_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special TryPrepareSecondApproachingTrainer
	goto_if_eq VAR_RESULT, TRUE, EventScript_TrainerApproach
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle::
	dotrainerbattle
	@ Below battle mode check only needed in FRLG
	specialvar VAR_RESULT, GetTrainerBattleMode
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_SINGLE, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, EventScript_EndTrainerBattle
EventScript_EndTrainerBattle::
	gotobeatenscript
	releaseall
	end

Std_MsgboxAutoclose::
	message NULL
	waitmessage
	waitbuttonpress
	release
	return
