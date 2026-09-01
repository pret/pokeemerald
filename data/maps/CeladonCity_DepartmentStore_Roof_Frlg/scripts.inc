CeladonCity_DepartmentStore_Roof_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_Roof_EventScript_ThirstyGirl::
	lock
	faceplayer
	call CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks
	goto_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink
	goto CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_FRESH_WATER
	call_if_eq VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater
	checkitem ITEM_SODA_POP
	call_if_eq VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop
	checkitem ITEM_LEMONADE
	call_if_eq VAR_RESULT, TRUE, CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater::
	addvar VAR_TEMP_1, 1
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop::
	addvar VAR_TEMP_1, 2
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade::
	addvar VAR_TEMP_1, 4
	return

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink
	waitmessage
	textcolor NPC_TEXT_COLOR_FEMALE
	switch VAR_TEMP_1
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop
	case 4, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade
	case 5, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade
	case 6, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade
	case 7, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_FRESH_WATER, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_FRESH_WATER_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_FRESH_WATER_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_SODA_POP_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks::
	multichoice 0, 0, MULTI_THIRSTY_GIRL_FRESH_WATER_SODA_POP_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater::
	setvar VAR_0x8008, ITEM_FRESH_WATER
	setvar VAR_0x8009, ITEM_TM16
	goto_if_set FLAG_GOT_TM16_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop::
	setvar VAR_0x8008, ITEM_SODA_POP
	setvar VAR_0x8009, ITEM_TM20
	goto_if_set FLAG_GOT_TM20_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade::
	setvar VAR_0x8008, ITEM_LEMONADE
	setvar VAR_0x8009, ITEM_TM33
	goto_if_set FLAG_GOT_TM33_FROM_THIRSTY_GIRL, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	removeitem VAR_0x8008
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForReward
	additem VAR_0x8009
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message Text_ReceivedItemFromLittleGirl
	waitmessage
	waitfanfare
	putitemaway VAR_0x8009
	call EventScript_RestorePrevTextColor
	call_if_eq VAR_0x8008, ITEM_FRESH_WATER, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16
	call_if_eq VAR_0x8008, ITEM_SODA_POP, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20
	call_if_eq VAR_0x8008, ITEM_LEMONADE, CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16::
	setflag FLAG_GOT_TM16_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM16
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20::
	setflag FLAG_GOT_TM20_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM20
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33::
	setflag FLAG_GOT_TM33_FROM_THIRSTY_GIRL
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM33
	return

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForReward::
	msgbox CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink::
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll::
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_CooltrainerM::
	msgbox CeladonCity_DepartmentStore_Roof_Text_MySisterIsImmature, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_Roof_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_Roof_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_Roof_EventScript_VendingMachine::
	lockall
	message CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave
	waitmessage
	showmoneybox 0, 0
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink::
	multichoice 12, 0, MULTI_CELADON_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_BuyFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_BuySodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_BuyLemonade
	msgbox CeladonCity_DepartmentStore_Roof_Text_NotThirsty
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_BuyFreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	checkmoney 200
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_BuySodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	checkmoney 300
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_BuyLemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	checkmoney 350
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink::
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoney
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_DrinkCanPoppedOut
	additem VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink::
	message CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave
	waitmessage
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoney::
	msgbox CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_NoMoreRoomForStuff
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink::
	.string "I'm thirsty!\n"
	.string "I want something to drink!\p"
	.string "{FONT_NORMAL}Give her a drink?$"

CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink::
	.string "Give her which drink?$"

CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis::
	.string "Yay!\p"
	.string "FRESH WATER!\p"
	.string "Thank you!\n"
	.string "You can have this from me!$"

Text_ReceivedItemFromLittleGirl::
	.string "{PLAYER} received a {STR_VAR_2}\n"
	.string "from the little girl.$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM16::
	.string "TM16 contains LIGHT SCREEN.\p"
	.string "It's a move that weakens the power\n"
	.string "of special attacks by your foe.$"

CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis::
	.string "Yay!\p"
	.string "SODA POP!\p"
	.string "Thank you!\n"
	.string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM20::
	.string "TM20 contains SAFEGUARD.\p"
	.string "It's a move that prevents status\n"
	.string "problems among your POKéMON.$"

CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis::
	.string "Yay!\p"
	.string "LEMONADE!\p"
	.string "Thank you!\n"
	.string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM33::
	.string "TM33 contains REFLECT.\p"
	.string "It's a move that weakens the power\n"
	.string "of physical attacks by your foe.$"

CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis::
	.string "You don't have space for this!$"

CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll::
	.string "No, thank you!\n"
	.string "I'm not thirsty after all!$"

CeladonCity_DepartmentStore_Roof_Text_MySisterIsImmature::
	.string "My sister is a TRAINER, believe it\n"
	.string "or not.\p"
	.string "But, she's so immature, she drives\n"
	.string "me nuts!$"

CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink::
	.string "I'm thirsty!\n"
	.string "I want something to drink!$"

CeladonCity_DepartmentStore_Roof_Text_FloorSign::
	.string "ROOFTOP SQUARE:\n"
	.string "VENDING MACHINES$"

CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave::
	.string "A vending machine!\n"
	.string "What does it have?$"

CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney::
	.string "Oops, not enough money!$"

CeladonCity_DepartmentStore_Roof_Text_DrinkCanPoppedOut::
	.string "A can of {STR_VAR_1} popped out!$"

CeladonCity_DepartmentStore_Roof_Text_NoMoreRoomForStuff::
	.string "There's no more room for stuff!$"

CeladonCity_DepartmentStore_Roof_Text_NotThirsty::
	.string "Not thirsty!$"

