@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	checkitem ITEM_AXE, 1
	compare VAR_RESULT, 0
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	msgbox Text_PlayerUsedAxe, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_PlayerUsedAxe:
	.string "{PLAYER} used the AXE!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	checkitem ITEM_HAMMER, 1
	compare VAR_RESULT, 0
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	msgbox Text_PlayerUsedHammer, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_CantSmash:
	.string "It's a rugged rock, but a HAMMER\n"
	.string "may be able to smash it.$"

Text_PlayerUsedHammer:
	.string "{PLAYER} used the HAMMER!$"	

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkitem ITEM_POWER_GLOVE, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantStrength
	msgbox Text_PlayerUsedGlove, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_CantStrength:
	.string "It's a big boulder, but its too heavy\n"
	.string "to push it aside.$"

Text_StrengthActivated:
	.string "Its now possible to move boulders\n"
	.string "around.$"
	
Text_PlayerUsedGlove:
	.string "{PLAYER} used the POWER GLOVE!$"

EventScript_UseWaterfall::
	lockall
	msgbox Text_PlayerUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_PlayerUsedWaterfall:
	.string "{PLAYER} climbed the watefall!$"
	
EventScript_DiveSpot::
	lockall
	checkitem ITEM_DIVING_SUIT, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantDive
	msgbox Text_PlayerUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_UseDive::
	lockall
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkitem ITEM_DIVING_SUIT, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantSurface
	msgbox Text_Surfaced, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.string "The sea is deep here. A SUIT\n"
	.string "may be able to go underwater.$"

Text_PlayerUsedDive:
	.string "{PLAYER} put on the DIVING SUIT!$"
	
Text_Surfaced:
	.string "{PLAYER} surfaced!$"

Text_CantSurface:
	.string "Light is filtering down from above.$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

Text_MonUsedFieldMove: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
