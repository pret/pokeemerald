Shuffler_Trainer1::
	trainerbattle_single 1, 0, 0
	bufferpostbattletext 0, 1
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer2::
	trainerbattle_single 2, 0, 0
	bufferpostbattletext 0, 2
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer3::
	trainerbattle_single 3, 0, 0
	bufferpostbattletext 0, 3
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer4::
	trainerbattle_single 4, 0, 0
	bufferpostbattletext 0, 4
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer5::
	trainerbattle_single 5, 0, 0
	bufferpostbattletext 0, 5
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer6::
	trainerbattle_single 6, 0, 0
	bufferpostbattletext 0, 6
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer7::
	trainerbattle_single 7, 0, 0
	bufferpostbattletext 0, 7
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer8::
	trainerbattle_single 8, 0, 0
	bufferpostbattletext 0, 8
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer9::
	trainerbattle_single 9, 0, 0
	bufferpostbattletext 0, 9
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Text_PostBattle:
	.string "{STR_VAR_1}$"
Shuffler_WildMon_Common::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end
Shuffler_WildMon1::
	lockall
	setwildbattle 1, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon2::
	lockall
	setwildbattle 2, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon3::
	lockall
	setwildbattle 3, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon4::
	lockall
	setwildbattle 4, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon5::
	lockall
	setwildbattle 5, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon6::
	lockall
	setwildbattle 6, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon7::
	lockall
	setwildbattle 7, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon8::
	lockall
	setwildbattle 8, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon9::
	lockall
	setwildbattle 9, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_Item1::
	finditem 1
	end
Shuffler_Item2::
	finditem 2
	end
Shuffler_Item3::
	finditem 3
	end
Shuffler_Item4::
	finditem 4
	end
Shuffler_Item5::
	finditem 5
	end
Shuffler_Item6::
	finditem 6
	end
Shuffler_Item7::
	finditem 7
	end
Shuffler_Item8::
	finditem 8
	end
Shuffler_Item9::
	finditem 9
	end

Shuffler_NPC1::
	setvar VAR_0x8008, 1
	call Shuffler_NPC_Common
Shuffler_NPC2::
	setvar VAR_0x8008, 2
	call Shuffler_NPC_Common
Shuffler_NPC3::
	setvar VAR_0x8008, 3
	call Shuffler_NPC_Common
Shuffler_NPC4::
	setvar VAR_0x8008, 4
	call Shuffler_NPC_Common
Shuffler_NPC5::
	setvar VAR_0x8008, 5
	call Shuffler_NPC_Common
Shuffler_NPC6::
	setvar VAR_0x8008, 6
	call Shuffler_NPC_Common
Shuffler_NPC7::
	setvar VAR_0x8008, 7
	call Shuffler_NPC_Common
Shuffler_NPC8::
	setvar VAR_0x8008, 8
	call Shuffler_NPC_Common
Shuffler_NPC9::
	setvar VAR_0x8008, 9
	call Shuffler_NPC_Common

Shuffler_NPC_Common::
	specialvar VAR_RESULT, GetShuffledNPCType
	compare VAR_RESULT, 1
	goto_if_eq Shuffler_NPC_Trader
	compare VAR_RESULT, 2
	goto_if_eq Shuffler_NPC_Healer
	compare VAR_RESULT, 3
	goto_if_eq Shuffler_NPC_Witch
	@ put more compares here for different npc types
	msgbox Shuffler_NPC_Text_Error, MSGBOX_DEFAULT
	end

Shuffler_NPC_Trader::
	lock
	faceplayer
	specialvar VAR_RESULT, GetNPCFlag
	compare VAR_RESULT, 1
	goto_if_eq Shuffler_NPC_Trader_TradeCompleted
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeTypeInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Shuffler_NPC_Trader_Text_Offer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Shuffler_NPC_Trader_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq Shuffler_NPC_Trader_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, CompareTradeTypes
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, 1
	goto_if_ne Shuffler_NPC_Trader_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Shuffler_NPC_Trader_Text_PostTrade, MSGBOX_DEFAULT
	special SetNPCFlag
	release
	end

Shuffler_NPC_Trader_TradeCompleted::
	msgbox Shuffler_NPC_Trader_Text_AfterTrade, MSGBOX_DEFAULT
	release
	end

Shuffler_NPC_Trader_DeclineTrade::
	msgbox Shuffler_NPC_Trader_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Shuffler_NPC_Trader_NotRequestedMon::
	buffertypename 0, VAR_0x8009
	msgbox Shuffler_NPC_Trader_Text_WrongType, MSGBOX_DEFAULT
	release
	end

Shuffler_NPC_Witch::
	lock
	faceplayer
	specialvar VAR_RESULT, GetNPCFlag
	compare VAR_RESULT, 1
	goto_if_eq Shuffler_NPC_Witch_Goodbye
	special BufferWitchText
	msgbox Shuffler_NPC_Witch_Text_Ask, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Shuffler_NPC_Witch_DoMagic
	compare VAR_RESULT, NO
	goto_if_eq Shuffler_NPC_Witch_Goodbye
	release
	end

Shuffler_NPC_Witch_DoMagic::
	special SetNPCFlag
	msgbox Shuffler_NPC_Witch_Text_DoMagic
	special DoWitchDeal
	goto Shuffler_NPC_Witch_Goodbye
	release
	end

Shuffler_NPC_Witch_Goodbye::
	msgbox Shuffler_NPC_Witch_Text_Done
	release
	end

Shuffler_NPC_Healer::
	lock
	faceplayer
	specialvar VAR_RESULT, GetNPCFlag
	compare VAR_RESULT, 1
	goto_if_eq Shuffler_NPC_Healer_Goodbye
	msgbox Shuffler_NPC_Healer_Text_AskHeal, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq Shuffler_NPC_Healer_HealPkmn
    compare VAR_RESULT, NO
    goto_if_eq Shuffler_NPC_Healer_Goodbye
	release
	end

Shuffler_NPC_Healer_HealPkmn::
	special SetNPCFlag
	msgbox Shuffler_NPC_Healer_Text_DoHeal
	@ I'm not sure how to edit field effects
	@ such that just the healing sound plays.
	@message gText_IllTakeYourPkmn
	@waitmessage
	@dofieldeffect FLDEFF_POKECENTER_HEAL
    @waitfieldeffect FLDEFF_POKECENTER_HEAL
	special HealPlayerParty
	goto Shuffler_NPC_Healer_Goodbye
	release
	end

Shuffler_NPC_Healer_Goodbye::
	msgbox Shuffler_NPC_Healer_Text_Done
	release
	end
