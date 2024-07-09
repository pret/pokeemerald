
PitEncounter_Mover::
	lockall
	faceplayer
	message PitEncounter_NPCMoverOpen
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitEncounter_NPCMover2, PitEncounter_NPCMover3, PitEncounter_NPCMover4, PitShop_ShopNPC_Option8
	goto_if_eq VAR_RESULT, 0, PitEncounter_MoverSkip2
	goto_if_eq VAR_RESULT, 1, PitEncounter_MoverSkip3
	goto_if_eq VAR_RESULT, 2, PitEncounter_NPCMoverWonderTrade
	closemessage
EndOfMoverScript::
	release
	end

PitEncounter_NPCMoverWonderTrade:
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, PitEncounter_Mover_NotEnoughMoney
	removemoney 500
	additem ITEM_RARE_CANDY, 1
	removeobject 14
	setflag FLAG_MOVER_OBJECT
	call EventScript_DoWonderTrade
	releaseall
	end

PitEncounter_NPCMoverOpen:
	.string "I have a special offer for you!\n"
	.string "Free Rare Candy Included With Purchase!$"

PitEncounter_MoverSkip2::
	checkmoney 3000
	goto_if_eq VAR_RESULT, FALSE, PitEncounter_Mover_NotEnoughMoney
	removemoney 3000
	setflag FLAG_FLOOR_CLEARED
	additem ITEM_RARE_CANDY, 2
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 1
	special DrawWholeMapView
	goto PitArena_Warp
	release
	end

PitEncounter_MoverSkip3::
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, PitEncounter_Mover_NotEnoughMoney
	removemoney 5000
	setflag FLAG_FLOOR_CLEARED
	additem ITEM_RARE_CANDY, 3
	setmetatile 9, 9, METATILE_Cave_FLOOR_COMPLETE, FALSE
	addvar VAR_PIT_FLOOR, 2
	special DrawWholeMapView
	goto PitArena_Warp
	release
	end

PitEncounter_Mover_NotEnoughMoney:
	msgbox PitEncounter_NPCMoverNotEnoughMoneyText, MSGBOX_DEFAULT
	release
	end

PitEncounter_NPCMoverNotEnoughMoneyText:
	.string "Not enough money...$"

PitEncounter_NPCMover2:
	.string "Skip 2 Floors: ¥3000$"
PitEncounter_NPCMover3:
	.string "Skip 3 Floors: ¥5000$"
PitEncounter_NPCMover4:
	.string "Wonder Trade:   ¥500$"
