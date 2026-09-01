CeladonCity_GameCorner_PrizeRoom_Frlg_MapScripts::
	.byte 0

CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	showcoinsbox 0, 0
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
	waitmessage
	multichoice 11, 0, MULTI_GAME_CORNER_POKEMON_PRIZES, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_Abra
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_Clefairy
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_DratiniPinsir
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_ScytherDratini
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
	hidecoinsbox
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Abra::
	#ifdef FIRERED
	setvar VAR_TEMP_1, SPECIES_ABRA
	setvar VAR_TEMP_2, 180
	#else
	#ifdef LEAFGREEN
	setvar VAR_TEMP_1, SPECIES_ABRA
	setvar VAR_TEMP_2, 120
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Clefairy::
	#ifdef FIRERED
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
	setvar VAR_TEMP_2, 500
	#else
	#ifdef LEAFGREEN
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
	setvar VAR_TEMP_2, 750
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_DratiniPinsir::
	#ifdef FIRERED
	setvar VAR_TEMP_1, SPECIES_DRATINI
	setvar VAR_TEMP_2, 2800
	#else
	#ifdef LEAFGREEN
	setvar VAR_TEMP_1, SPECIES_PINSIR
	setvar VAR_TEMP_2, 2500
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ScytherDratini::
	#ifdef FIRERED
	setvar VAR_TEMP_1, SPECIES_SCYTHER
	setvar VAR_TEMP_2, 5500
	#else
	#ifdef LEAFGREEN
	setvar VAR_TEMP_1, SPECIES_DRATINI
	setvar VAR_TEMP_2, 4600
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon::
	#ifdef FIRERED
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, 9999
	#else
	#ifdef LEAFGREEN
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, 6500
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	textcolor NPC_TEXT_COLOR_NEUTRAL
	switch VAR_TEMP_1
	case SPECIES_ABRA,     CeladonCity_GameCorner_PrizeRoom_EventScript_GiveAbra
	case SPECIES_CLEFAIRY, CeladonCity_GameCorner_PrizeRoom_EventScript_GiveClefairy
	case SPECIES_DRATINI,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini
	case SPECIES_SCYTHER,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther
	case SPECIES_PORYGON,  CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon
	case SPECIES_PINSIR,   CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveAbra::
	#ifdef FIRERED
	givemon VAR_TEMP_1, 9
	#else
	#ifdef LEAFGREEN
	givemon VAR_TEMP_1, 7
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveClefairy::
	#ifdef FIRERED
	givemon VAR_TEMP_1, 8
	#else
	#ifdef LEAFGREEN
	givemon VAR_TEMP_1, 12
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini::
	#ifdef FIRERED
	givemon VAR_TEMP_1, 18
	#else
	#ifdef LEAFGREEN
	givemon VAR_TEMP_1, 24
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther::
	givemon VAR_TEMP_1, 25
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
	#ifdef FIRERED
	givemon VAR_TEMP_1, 26
	#else
	#ifdef LEAFGREEN
	givemon VAR_TEMP_1, 18
	#endif
	#endif
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
	givemon VAR_TEMP_1, 18
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox gText_NoMoreRoomForPokemon
	hidecoinsbox
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
	removecoins VAR_TEMP_2
	updatecoinsbox
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message gText_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
	removecoins VAR_TEMP_2
	updatecoinsbox
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message gText_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	showcoinsbox 0, 0
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM::
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
	waitmessage
	multichoice 11, 0, MULTI_GAME_CORNER_TMPRIZES, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TM13
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TM23
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TM24
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TM30
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TM35
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM13::
	setvar VAR_TEMP_1, ITEM_TM13
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_ICE_BEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM23::
	setvar VAR_TEMP_1, ITEM_TM23
	setvar VAR_TEMP_2, 3500
	buffermovename STR_VAR_2, MOVE_IRON_TAIL
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM24::
	setvar VAR_TEMP_1, ITEM_TM24
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_THUNDERBOLT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM30::
	setvar VAR_TEMP_1, ITEM_TM30
	setvar VAR_TEMP_2, 4500
	buffermovename STR_VAR_2, MOVE_SHADOW_BALL
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM35::
	setvar VAR_TEMP_1, ITEM_TM35
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_FLAMETHROWER
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem::
	bufferitemname STR_VAR_1, VAR_TEMP_1
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize::
	bufferitemname STR_VAR_1, VAR_TEMP_1
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	checkitemspace VAR_TEMP_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull
	removecoins VAR_TEMP_2
	updatecoinsbox
	giveitem VAR_TEMP_1
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox gText_TooBadBagIsFull
	hidecoinsbox
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	showcoinsbox 0, 0
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem::
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
	waitmessage
	multichoice 10, 0, MULTI_GAME_CORNER_BATTLE_ITEM_PRIZES, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall::
	setvar VAR_TEMP_1, ITEM_SMOKE_BALL
	setvar VAR_TEMP_2, 800
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed::
	setvar VAR_TEMP_1, ITEM_MIRACLE_SEED
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal::
	setvar VAR_TEMP_1, ITEM_CHARCOAL
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater::
	setvar VAR_TEMP_1, ITEM_MYSTIC_WATER
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute::
	setvar VAR_TEMP_1, ITEM_YELLOW_FLUTE
	setvar VAR_TEMP_2, 1600
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon::
	.string "I sure do fancy that PORYGON!\n"
	.string "But, it's hard to win at slots!$"

CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday::
	.string "Gahaha! I raked it in today!\n"
	.string "If only every day were like this…$"

CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired::
	.string "A COIN CASE is required…$"

CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes::
	.string "We exchange your COINS for prizes.$"

CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize::
	.string "Which prize would you like?$"

CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo::
	.string "はい どうぞ$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM::
	.string "Okay, a TM of {STR_VAR_2}\n"
	.string "is what you want?$"

CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins::
	.string "Sorry, you'll need more COINS\n"
	.string "than that.$"

CeladonCity_GameCorner_PrizeRoom_Text_OopsNotEnoughRoom::
	.string "おきゃくさん もう もてないよ$"

CeladonCity_GameCorner_PrizeRoom_Text_OhFineThen::
	.string "あっ そう$"

