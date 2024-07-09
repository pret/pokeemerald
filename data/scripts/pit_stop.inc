

PitStop_HealNPC::
	lockall
	faceplayer
	special HealPlayerParty
	msgbox PitStop_HealNPC_Text, MSGBOX_DEFAULT
	release
	end

PitStop_HealNPC_Text:
	.string "Your party has been healed.\p"
	.string "Have a nice descent.$"



PitStop_NewMon::
	lockall
	callnative PlayerPartyCountToResultVar
	goto_if_eq VAR_RESULT, 6, PitStop_PartyFullRemoveOne
PitStop_NewMon2::
	callnative StartNewPokeballCaseUI
   	waitstate
	goto PitStop_EventScript_ReceiveMonParty
	release
	end

PitStop_EventScript_ReceiveMonParty::
	removeobject 8
	releaseall
	end

PitStop_PartyFullRemoveOne::
	message PitStop_GiveMonFullNothingChosen_Text1
	waitbuttonpress
	msgbox PitStop_GiveMonFullNothingChosen_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitStop_FullPartyNothingChosen
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, PitStop_FullPartyNothingChosen
	callnative RemovePartyPokemon
	goto PitStop_NewMon2
	release
	end

PitStop_FullPartyNothingChosen::
	release
	end

PitStop_GiveMonFullNothingChosen_Text1:
	.string "Your party is too full.$"

PitStop_GiveMonFullNothingChosen_Text2:
	.string "Do you want to get rid\n"
	.string "of a party member?$"

PitStop_Text_ReceivedMon:
	.string "{PLAYER} pulled a {STR_VAR_2}\n"
	.string "from the bag.$"



PitTutor_MoveRelearner::
	lockall
	faceplayer
	showmoneybox 12, 11
#ifndef PIT_GEN_9_MODE
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitTutor_MoveRelearnerText, PitArena_EggMovesText, PitArena_TutorMovesText, PitShop_ShopNPC_Option8
#else
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitTutor_MoveRelearnerText, PitArena_EggMovesText, PitShop_ShopNPC_Option8
#endif	
	goto_if_eq VAR_RESULT, 0, PitTutor_MartNPCMoveRelearner
	goto_if_eq VAR_RESULT, 1, PitTutor_MartNPCMoveTutorEggMoves
#ifndef PIT_GEN_9_MODE
	goto_if_eq VAR_RESULT, 2, PitTutor_MartNPCMoveTutorTutorMoves
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

PitTutor_MartNPCMoveTutorTutorMoves_NotEnoughMoney::
	hidemoneybox
	msgbox PitArena_Tutor_NotGotTheMoney, MSGBOX_AUTOCLOSE
	release
	end
