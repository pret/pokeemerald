EventScript_271354:: @ 8271354
	cmdD8
	cmdD9

EventScript_ShowSecondTrainerIntro:: @ 8271356
	special SetUpTrainerEncounterMusic
	special EndTrainerApproach
	waitstate
	goto EventScript_ShowTrainerIntroMsg

EventScript_TryDoNormalTrainerBattle:: @ 8271362
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	specialvar VAR_RESULT, GetTrainerFlag
	compare VAR_RESULT, 0
	goto_if_ne EventScript_NoNormalTrainerBattle
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	goto EventScript_ShowTrainerIntroMsg
EventScript_NoNormalTrainerBattle:: @ 8271389
	gotopostbattlescript

EventScript_TryDoDoubleTrainerBattle:: @ 827138A
	lock
	faceplayer
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, GetTrainerFlag
	compare VAR_RESULT, 0
	goto_if_ne EventScript_NoDoubleTrainerBattle
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne EventScript_NotEnoughMonsForDoubleBattle
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	goto EventScript_ShowTrainerIntroMsg
EventScript_NotEnoughMonsForDoubleBattle:: @ 82713BA
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end
EventScript_NoDoubleTrainerBattle:: @ 82713C1
	gotopostbattlescript

EventScript_DoNoIntroTrainerBattle:: @ 82713C2
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	special SetUpTrainerEncounterMusic
	trainerbattlebegin
	gotopostbattlescript

EventScript_TryDoRematchBattle:: @ 82713D1
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_NoRematchTrainerBattle
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end
EventScript_NoRematchTrainerBattle:: @ 82713F7
	gotopostbattlescript

EventScript_TryDoDoubleRematchBattle:: @ 82713F8
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_NoDoubleRematchTrainerBattle
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_ne EventScript_NotEnoughMonsForDoubleRematchBattle
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end
EventScript_NoDoubleRematchTrainerBattle:: @ 8271427
	gotopostbattlescript
EventScript_NotEnoughMonsForDoubleRematchBattle:: @ 8271428
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_RevealTrainer:: @ 827142F
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	return

Movement_RevealTrainer: @ 827143A
	reveal_trainer
	step_end

EventScript_ShowTrainerIntroMsg:: @ 827143C
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special TryPrepareSecondApproachingTrainer
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_ShowSecondTrainerIntro
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle:: @ 8271454
	trainerbattlebegin
	@ Below battle mode check only needed in FRLG
	specialvar VAR_RESULT, GetTrainerBattleMode
	compare VAR_RESULT, TRAINER_BATTLE_SINGLE
	goto_if_eq EventScript_EndTrainerBattle
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT
	goto_if_eq EventScript_EndTrainerBattle
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
	goto_if_eq EventScript_EndTrainerBattle
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE
	goto_if_eq EventScript_EndTrainerBattle
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC
	goto_if_eq EventScript_EndTrainerBattle
EventScript_EndTrainerBattle:: @ 8271491
	gotobeatenscript
	releaseall
	end

Std_MsgboxAutoclose:: @ 8271494
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return
