PitOverworldMonEncounter::
	lock
	faceplayer
	callnative CallRandomMonEncounterScript
	end

PitEncounter_ChooseMonScript::
	getpartysize
	goto_if_eq VAR_RESULT, 0, PitEncounter_ChooseMonScriptEnd
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, PitEncounter_ChooseMonScriptEnd
	copyvar VAR_0x8005, VAR_0x8004
PitEncounter_ChooseMonScriptEnd::
	return

PitEncounter_Common_AlreadyUsedEffect:: @ Can Swap for a Mon Specific Post Script From the Struct if we want
	faceplayer
	msgbox PitEncounter_Common_AlreadyUsedEffect_Text, MSGBOX_DEFAULT
	release
	end
PitEncounter_Common_AlreadyUsedEffect_Text:
	.string "Already used effect.$"

PitEncounter_Common_AfterUse::
	setflag FLAG_USED_RANDOM_ENCOUNTER_THIS_FLOOR
	return


@ Heal Single Pokemon
PitEncounter_HealOneMon::
	call PitEncounter_ChooseMonScript
	callnative HealPlayerPokemon
	call PitEncounter_Common_AfterUse
	release
	end

@ Revive Single Pokemon
PitEncounter_ReviveOneMon::
	call PitEncounter_ChooseMonScript
	callnative CheckMonFainted
	goto_if_eq VAR_RESULT, 0, PitEncounter_ReviveMonNotFainted
	callnative HealPlayerPokemon
	call PitEncounter_Common_AfterUse
	release
	end

PitEncounter_ReviveMonNotFainted::
	msgbox PitEncounter_ReviveMonNotFainted_Text, MSGBOX_DEFAULT
	release
	end

PitEncounter_ReviveMonNotFainted_Text:
	.string "Invalid mon.$"


@ Give Lucky Egg Item
PitEncounter_LuckyEggDrop::
	setflag FLAG_DONT_RANDOMIZE_NEXT_ITEM
	giveitem ITEM_LUCKY_EGG, 1
	call PitEncounter_Common_AfterUse
	release
	end


@ Give Amulet Coin Item
PitEncounter_AmuletCoinDrop::
	setflag FLAG_DONT_RANDOMIZE_NEXT_ITEM
	giveitem ITEM_AMULET_COIN, 1
	call PitEncounter_Common_AfterUse
	release
	end


@ Give Nugget Item
PitEncounter_NuggetDrop::
	setflag FLAG_DONT_RANDOMIZE_NEXT_ITEM
	giveitem ITEM_NUGGET, 1
	call PitEncounter_Common_AfterUse
	release
	end


@ Wonder Trade NPC
PitEncounter_WonderTrade::
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, PitEncounter_Mover_NotEnoughMoney
	removemoney 500
	additem ITEM_RARE_CANDY, 1
	removeobject 12
	call PitEncounter_Common_AfterUse
	call EventScript_DoWonderTrade
	releaseall
	end


@ Give MooMooMilk Item
PitEncounter_MooMooMilkDrop::
	setflag FLAG_DONT_RANDOMIZE_NEXT_ITEM
	giveitem ITEM_MOOMOO_MILK, 3
	call PitEncounter_Common_AfterUse
	release
	end


@ Give RareCandy Item
PitEncounter_RareCandyDrop::
	setflag FLAG_DONT_RANDOMIZE_NEXT_ITEM
	giveitem ITEM_RARE_CANDY, 3
	call PitEncounter_Common_AfterUse
	release
	end


@ Cure All Mons Status
PitEncounter_CureAllStatus::
	callnative HealAllStatus
	call PitEncounter_Common_AfterUse
	release
	end


@ Skip Floor NPC
PitEncounter_Mover::
	lockall
	faceplayer
	message PitEncounter_NPCMoverOpen
	dynmultichoice 17, 1, 0, 5, 0, DYN_MULTICHOICE_CB_NONE, PitEncounter_NPCMover2, PitEncounter_NPCMover3, PitShop_ShopNPC_Option8
	goto_if_eq VAR_RESULT, 0, PitEncounter_MoverSkip2
	goto_if_eq VAR_RESULT, 1, PitEncounter_MoverSkip3
	closemessage
EndOfMoverScript::
	release
	end

PitEncounter_NPCMoverOpen:
	.string "I have a special offer for you!\n"
	.string "Free Rare Candy Included With Purchase!$"

PitEncounter_MoverSkip2::
	checkmoney 3000
	goto_if_eq VAR_RESULT, FALSE, PitEncounter_Mover_NotEnoughMoney
	removemoney 3000
	setflag FLAG_FLOOR_CLEARED
	call PitEncounter_Common_AfterUse
	callnative SetWarpTileActive
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
	callnative SetWarpTileActive
	call PitEncounter_Common_AfterUse
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
