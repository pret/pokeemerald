

PitStop_HealNPC::
	lock
	faceplayer
	special HealPlayerParty
	msgbox PitStop_HealNPC_Text, MSGBOX_DEFAULT
	release
	end

PitStop_HealNPC_Text:
	.string "Your party has been healed.\p"
	.string "Have a nice descent.$"


PitTutor_MoveRelearner::
	lockall
	faceplayer
	showmoneybox 12, 11
#ifndef PIT_GEN_9_MODE
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitTutor_MoveRelearnerText, PitArena_EggMovesText, PitArena_PreEvoMovesText, PitArena_TutorMovesText, PitShop_ShopNPC_Option8
#else
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitTutor_MoveRelearnerText, PitArena_EggMovesText, PitArena_PreEvoMovesText, PitShop_ShopNPC_Option8
#endif	
	goto_if_eq VAR_RESULT, 0, PitTutor_MartNPCMoveRelearner
	goto_if_eq VAR_RESULT, 1, PitTutor_MartNPCMoveTutorEggMoves
	goto_if_eq VAR_RESULT, 2, PitTutor_MartNPCMoveTutorPreEvoMoves
#ifndef PIT_GEN_9_MODE
	goto_if_eq VAR_RESULT, 3, PitTutor_MartNPCMoveTutorTutorMoves
#endif
EndOfRelearnerScript::
	hidemoneybox
	release
	end

PitTutor_MartNPCMoveRelearner::
	setvar VAR_PIT_TUTOR_STATE, 0
	hidemoneybox
PitTutor_MartNPCMoveTutor::
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

PitTutor_MartNPCMoveTutorEggMoves::
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	setvar VAR_PIT_TUTOR_STATE, 2
	hidemoneybox
	goto PitTutor_MartNPCMoveTutor
	end

PitTutor_MartNPCMoveTutorTutorMoves::
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	setvar VAR_PIT_TUTOR_STATE, 1
	hidemoneybox
	goto PitTutor_MartNPCMoveTutor
	end

PitTutor_MartNPCMoveTutorStaticTutorMoves::
	setvar VAR_PIT_TUTOR_STATE, 1
	hidemoneybox
	special ShowTutorMoveList
	waitstate
	call_if_eq VAR_RESULT, 99, PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	release
	end

PitTutor_MartNPCMoveTutorPreEvoMoves::
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney
	setvar VAR_PIT_TUTOR_STATE, 4
	hidemoneybox
	goto PitTutor_MartNPCMoveTutor
	end

PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney::
	hidemoneybox
	msgbox PitArena_Tutor_NotGotTheMoney, MSGBOX_AUTOCLOSE
	release
	end
