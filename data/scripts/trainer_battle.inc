@ As of 04.06.26 event Script are superseded by Event Snippets (see below).
@ Kept for backwards compatability.

EventScript_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
EventScript_TrainerApproach::
	special PlayTrainerEncounterMusic
	special DoTrainerApproach
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

Std_MsgboxAutoclose::
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

EventScript_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special TryPrepareSecondApproachingTrainer
	goto_if_eq VAR_RESULT, TRUE, EventScript_TrainerApproach
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle::
	dotrainerbattle
EventScript_EndTrainerBattle::
	gotobeatenscript
	releaseall
	end

@ Event Snippets for dynamic trainer battle scripting
EventSnippet_Lock::
	lock
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

EventSnippet_FacePlayer::
	faceplayer
	return

EventSnippet_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
	return

EventSnippet_TrainerApproach::
	special DoTrainerApproach
	return

EventSnippet_RevealTrainer::
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

EventSnippet_PlayTrainerEncounterMusic::
	special PlayTrainerEncounterMusic
	return

EventSnippet_SetTrainerFacingDirection::
	special SetTrainerFacingDirection
	return

EventSnippet_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	return 

EventSnippet_PrepareSecondTrainerApproach::
	special PrepareSecondApproachingTrainer
	return

EventSnippet_GotoPostBattleScript::
	gotopostbattlescript
	return

EventSnippet_DoTrainerBattle::
	dotrainerbattle
	return

EventSnippet_DoRematchTrainerBattle::
	special BattleSetup_StartRematchBattle
	return

EventSnippet_EndTrainerBattle::
	gotobeatenscript
	releaseall
	end

EventSnippet_NotEnoughMonsForDoubleBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end
