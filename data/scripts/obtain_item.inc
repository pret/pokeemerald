.set ITEMID, VAR_0x8000
.set AMOUNT, VAR_0x8001

Std_ObtainItem::
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	additem ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call_if_eq VAR_0x8007, FALSE, EventScript_TryAddItemToPCObtain
	call EventScript_ObtainItemMessage
	return

EventScript_TryAddItemToPCObtain::
	checkitemtype VAR_0x8004 @ Don't add if it's a key item
	goto_if_eq VAR_RESULT, POCKET_KEY_ITEMS, EventScript_TryAddItemToPCObtainContinue
	addpcitem VAR_0x8004, VAR_0x8005
	call_if_eq VAR_RESULT, FALSE, EventScript_TryAddItemToPCObtainContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC) 
EventScript_TryAddItemToPCObtainContinue::
	return

EventScript_ObtainItemMessage::
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_ne VAR_0x8007, FALSE, EventScript_ObtainedItem
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
	call_if_ne VAR_0x8007, FALSE, EventScript_ObtainedItem
	return

EventScript_BufferKeyItemsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_KEYITEMS
	call_if_ne VAR_0x8007, FALSE, EventScript_ObtainedItem
	return

EventScript_BufferPokeballsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	call_if_ne VAR_0x8007, FALSE, EventScript_ObtainedItem
	return

EventScript_BufferTMHMsPocket::
	bufferstdstring STR_VAR_3, STDSTRING_TMHMS
	call_if_ne VAR_0x8007, FALSE, EventScript_PlayFanfareObtainedTMHM
	return

EventScript_BufferBerriesPocket::
	bufferstdstring STR_VAR_3, STDSTRING_BERRIES
	call_if_ne VAR_0x8007, FALSE, EventScript_ObtainedItem
	return

EventScript_ObtainedItem::
	message gText_ObtainedTheItem
	waitfanfare
	call EventScript_PutItemMsg
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
	copyvar VAR_0x8004, ITEMID
	copyvar VAR_0x8005, AMOUNT
	checkitemspace ITEMID, AMOUNT
	copyvar VAR_0x8007, VAR_RESULT
	call_if_eq VAR_0x8007, FALSE, EventScript_CheckPCSpace
	bufferitemnameplural STR_VAR_2, ITEMID, AMOUNT
	checkitemtype ITEMID
	call EventScript_BufferPocketNameAndTryFanfare
	call_if_ne VAR_0x8007, FALSE, EventScript_PickUpItem
	call_if_eq VAR_0x8007, FALSE, EventScript_NoRoomToPickUpItem
	release
	return

EventScript_CheckPCSpace::
	checkitemtype VAR_0x8004 @ Don't add if it's a key item
	goto_if_eq VAR_RESULT, POCKET_KEY_ITEMS, EventScript_CheckPCSpaceContinue
	pyramid_inchallenge
	copyvar VAR_0x8004, ITEMID  @ pyramid_inchallenge modifies VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, EventScript_CheckPCSpaceContinue
	checkpcspace VAR_0x8004, VAR_0x8005
	call_if_eq VAR_RESULT, FALSE, EventScript_CheckPCSpaceContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC)
EventScript_CheckPCSpaceContinue::
	return

EventScript_PickUpItem::
	removeobject VAR_LAST_TALKED
	goto_if_eq VAR_0x8007, 2, EventScript_PickUpItemPCAdd
	additem VAR_0x8004, VAR_0x8005
	goto EventScript_PickUpItemContinueAdd
EventScript_PickUpItemPCAdd::
	addpcitem VAR_0x8004, VAR_0x8005
EventScript_PickUpItemContinueAdd::
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, TRUE, EventScript_FoundTMHM
	call_if_eq VAR_0x8008, FALSE, EventScript_FoundItem
	waitfanfare
	waitmessage
	bufferitemnameplural STR_VAR_2, VAR_0x8004, VAR_0x8005
	pyramid_inchallenge
	goto_if_eq VAR_RESULT, TRUE, EventScript_PutBattlePyramidItemInBag
	call EventScript_PutItemMsg
	return

EventScript_PutBattlePyramidItemInBag::
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_FoundTMHM::
	bufferitemnameplural STR_VAR_1, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneTMHM
	return

EventScript_FoundItem::
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
	additem VAR_0x8005
	copyvar VAR_0x8007, VAR_RESULT
	call_if_eq VAR_0x8007, FALSE, EventScript_TryAddItemToPCHidden
	bufferitemnameplural STR_VAR_2, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferPocketNameAndTryFanfare
	goto_if_ne VAR_0x8007, FALSE, EventScript_PickUpHiddenItem
	goto_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForHiddenItem
	end

EventScript_TryAddItemToPCHidden::
	checkitemtype VAR_0x8005 @ Don't add if it's a key item
	goto_if_eq VAR_RESULT, POCKET_KEY_ITEMS, EventScript_TryAddHiddenItemToPCContinue
	addpcitem VAR_0x8005
	call_if_eq VAR_RESULT, FALSE, EventScript_TryAddHiddenItemToPCContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC) 
EventScript_TryAddHiddenItemToPCContinue::
	return

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
	message gText_PlayerFoundOneItem
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_PutHiddenItemInPocket::
	waitmessage
	waitfanfare
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	call EventScript_PutItemMsg
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	releaseall
	end

EventScript_PutItemMsg::
	goto_if_eq VAR_0x8007, 2, EventScript_PutItemPCMsg
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto EventScript_PutItemContinueMsg
EventScript_PutItemPCMsg::
	msgbox gText_PutItemInPC, MSGBOX_DEFAULT
EventScript_PutItemContinueMsg::
	return

EventScript_NoRoomForHiddenItem::
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagAndPCAreFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end
