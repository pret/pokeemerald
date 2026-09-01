.set ITEMID, VAR_0x8000
.set AMOUNT, VAR_0x8001

Std_ObtainItem::
	copyvar VAR_0x8006, ITEMID
	additem ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainItemMessage
	return

EventScript_ObtainItemMessage::
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForItem
	return

EventScript_BufferPocketNameAndTryFanfare::
	switch VAR_RESULT
	case POCKET_ITEMS,      EventScript_BufferItemsPocket
	case POCKET_KEY_ITEMS,  EventScript_BufferKeyItemsPocket
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket
	case POCKET_TM_HM,      EventScript_BufferTMHMsPocket
	case POCKET_BERRIES,    EventScript_BufferBerriesPocket
	end

EventScript_BufferItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferKeyItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferPokeballsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferTMHMsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_TMHMS
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedTMHM
	return

EventScript_BufferBerriesPocket::
	bufferstdstring STR_VAR_3, STDSTRING_BERRIES
	call_if_eq VAR_0x8007, TRUE, EventScript_PlayFanfareObtainedItem
	return

EventScript_ObtainedItem::
	compare VAR_0x8001, TRUE
	goto_if_eq EventScript_ObtainedItemMessage
	buffernumberstring 0, VAR_0x8001
	message gText_ObtainedTheItems
	goto EventScript_ContinueObtainedItem
EventScript_ObtainedItemMessage:
	message gText_ObtainedTheItem
EventScript_ContinueObtainedItem:
	delay 10
	showitemdescription
	waitfanfare
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	hideitemdescription
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForItem::
	setvar VAR_RESULT, FALSE
	return

EventScript_PlayFanfareObtainedItem::
	playfanfare MUS_OBTAIN_ITEM
	return

EventScript_PlayFanfareObtainedTMHM::
	playfanfare MUS_OBTAIN_TMHM
	return

Std_ObtainDecoration::
	adddecoration ITEMID
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainDecorationMessage
	return

EventScript_ObtainDecorationMessage::
	bufferdecorationname STR_VAR_2, ITEMID
	call_if_eq VAR_0x8007, TRUE, EventScript_ObtainedDecor
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForDecor
	return

EventScript_ObtainedDecor::
	playfanfare MUS_OBTAIN_ITEM
	message gText_ObtainedTheDecor
	waitfanfare
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

EventScript_NoRoomForDecor::
	setvar VAR_RESULT, FALSE
	return

Std_FindItem::
	lock
	faceplayer
	waitse
	copyvar VAR_0x8006, ITEMID
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	checkitemspace ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_eq VAR_0x8007, TRUE, EventScript_PickUpItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomToPickUpItem
	release
	return

EventScript_PickUpItem::
	removeobject VAR_LAST_TALKED
	additem VAR_0x8004, VAR_0x8005
	copyvar VAR_0x8006 VAR_0x8004
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, EventScript_FoundTMHM
	call_if_eq VAR_0x8008, FALSE, EventScript_FoundItem
	delay 10
	showitemdescription
	waitfanfare
	waitmessage
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	pyramid_getlocation
	goto_if_eq VAR_RESULT, PYRAMID_LOCATION_FLOOR, EventScript_PutBattlePyramidItemInBag
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	hideitemdescription
	return

EventScript_PutBattlePyramidItemInBag::
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	hideitemdescription
	return

EventScript_FoundTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 2
	goto_if_lt EventScript_FoundTMHMMessage
	buffernumberstring STR_VAR_3, VAR_0x8005
	message gText_PlayerFoundTMHMs
	goto EventScript_BufferTMHMsPocket
	return
EventScript_FoundTMHMMessage::
	message gText_PlayerFoundOneTMHM
	return

EventScript_FoundItem::
	compare VAR_0x8001, TRUE
	goto_if_eq EventScript_FoundItemMessage
	buffernumberstring 0, VAR_0x8001
	message gText_PlayerFoundItems
	return
EventScript_FoundItemMessage::
	message gText_PlayerFoundOneItem
	return

EventScript_NoRoomToPickUpItem::
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	return

EventScript_HiddenItemScript::
	lockall
	waitse
	goto_if_eq VAR_0x8005, 0, EventScript_TryPickUpHiddenCoins
	copyvar VAR_0x8006, VAR_0x8005
	additem VAR_0x8005, VAR_0x8009
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural STR_VAR_2, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferPocketNameAndTryFanfare
	goto_if_eq VAR_0x8007, TRUE, EventScript_PickUpHiddenItem
	goto_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForHiddenItem
	end

EventScript_PickUpHiddenItem::
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	goto_if_eq VAR_RESULT, TRUE, EventScript_FoundHiddenTMHM
	goto_if_eq VAR_RESULT, FALSE, EventScript_FoundHiddenItem
	end

EventScript_FoundHiddenTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, 1
	message gText_PlayerFoundOneTMHM
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_FoundHiddenItem::
	call_if_eq VAR_0x8009, 1, EventScript_FoundSingleItem
	call_if_ne VAR_0x8009, 1, EventScript_FoundMultipleItems
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_FoundSingleItem::
	message gText_PlayerFoundOneItem
	return

EventScript_FoundMultipleItems::
	buffernumberstring STR_VAR_1, VAR_0x8009
	message gText_FoundXItems
	return

EventScript_PutHiddenItemInPocket::
	callnative Script_ClearDowsingColor
	delay 10
	showitemdescription
	waitmessage
	waitfanfare
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	hideitemdescription
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	callnative Script_UpdateDowseState
	releaseall
	end

EventScript_NoRoomForHiddenItem::
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_RestorePrevTextColor::
	copyvar VAR_TEXT_COLOR, VAR_PREV_TEXT_COLOR
	return

Std_PutItemAway::
	bufferitemnameplural STR_VAR_2, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferPutAwayPocketName
	msgbox gText_PutItemInPocket
	return

EventScript_BufferPutAwayPocketName::
	switch VAR_RESULT
	case POCKET_ITEMS,       EventScript_BufferPutAwayPocketItems
	case POCKET_KEY_ITEMS,   EventScript_BufferPutAwayPocketKeyItems
	case POCKET_POKE_BALLS,  EventScript_BufferPutAwayPocketPokeBalls
	case POCKET_TM_HM,     EventScript_BufferPutAwayPocketTMCase
	case POCKET_BERRIES, EventScript_BufferPutAwayPocketBerryPouch
	end

EventScript_BufferPutAwayPocketItems::
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	return

EventScript_BufferPutAwayPocketKeyItems::
	bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
	return

EventScript_BufferPutAwayPocketPokeBalls::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	return

EventScript_BufferPutAwayPocketTMCase::
	bufferstdstring STR_VAR_3, STDSTRING_TMHMS
	return

EventScript_BufferPutAwayPocketBerryPouch::
	bufferstdstring STR_VAR_3, STDSTRING_BERRIES
	return

EventScript_TryPickUpHiddenCoins::
	goto_if_unset FLAG_GOT_COIN_CASE, EventScript_NoCaseForHiddenCoins
	checkcoins VAR_RESULT
	specialvar VAR_RESULT, CheckAddCoins
	goto_if_eq VAR_RESULT, FALSE, EventScript_HiddenCoinsButCaseIsFull
	addcoins VAR_0x8009
	bufferstdstring STR_VAR_2, STDSTRING_COINS
	call EventScript_PlayFanfareObtainedItem
	call EventScript_FoundCoins
	waitfanfare
	waitmessage
	msgbox gText_PutCoinsAwayInCoinCase
	special SetHiddenItemFlag
	releaseall
	end

EventScript_FoundCoins::
	buffernumberstring STR_VAR_1, VAR_0x8009
	message gText_FoundXCoins
	return

EventScript_HiddenCoinsButCaseIsFull::
	buffernumberstring STR_VAR_1, VAR_0x8009
	bufferstdstring STR_VAR_2, STDSTRING_COINS
	msgbox gText_FoundXCoins
	msgbox gText_CoinCaseIsFull
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_NoCaseForHiddenCoins::
	buffernumberstring STR_VAR_1, VAR_0x8009
	bufferstdstring STR_VAR_2, STDSTRING_COINS
	msgbox gText_FoundXCoins
	msgbox gText_NothingToPutThemIn
	setvar VAR_RESULT, 0
	releaseall
	end
