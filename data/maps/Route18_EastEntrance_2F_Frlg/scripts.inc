Route18_EastEntrance_2F_Frlg_MapScripts::
	.byte 0

Route18_EastEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route18_EastEntrance_2F_Text_PalletTownInWest, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route18_EastEntrance_2F_Text_PeopleSwimming, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_EventScript_Haden::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_LICKITUNG
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_MARC_TRADE, Route18_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route18_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route18_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route18_EastEntrance_2F_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_MARC_TRADE
	release
	end

Route18_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route18_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

Route18_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route18_EastEntrance_2F_Text_PalletTownInWest::
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "PALLET TOWN is in the west.$"

Route18_EastEntrance_2F_Text_PeopleSwimming::
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "There are people swimming.$"

