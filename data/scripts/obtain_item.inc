Std_ObtainItem:: @ 8271AD3
	giveitem VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_271AE3
	return

EventScript_271AE3:: @ 8271AE3
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	call_if_eq EventScript_271B95
	compare VAR_0x8007, 0
	call_if_eq EventScript_271BA9
	return

EventScript_BufferStdString:: @ 8271B08
	switch VAR_RESULT
	case POCKET_ITEMS, EventScript_StdStringItem
	case POCKET_KEY_ITEMS, EventScript_StdStringKeyItems
	case POCKET_POKE_BALLS, EventScript_StdStringPokeballs
	case POCKET_TM_HM, EventScript_StdStringTMHMS
	case POCKET_BERRIES, EventScript_StdStringBerries
	end

EventScript_StdStringItem:: @ 8271B45
	bufferstdstring 2, STDSTRING_ITEMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfareObtainedItem
	return

EventScript_StdStringKeyItems:: @ 8271B55
	bufferstdstring 2, STDSTRING_KEYITEMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfareObtainedItem
	return

EventScript_StdStringPokeballs:: @ 8271B65
	bufferstdstring 2, STDSTRING_POKEBALLS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfareObtainedItem
	return

EventScript_StdStringTMHMS:: @ 8271B75
	bufferstdstring 2, STDSTRING_TMHMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfareObtainedTMHM
	return

EventScript_StdStringBerries:: @ 8271B85
	bufferstdstring 2, STDSTRING_BERRIES
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfareObtainedItem
	return

EventScript_271B95:: @ 8271B95
	message gText_ObtainedTheItem
	waitfanfare
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

EventScript_271BA9:: @ 8271BA9
	setvar VAR_RESULT, 0
	return

EventScript_PlayFanfareObtainedItem:: @ 8271BAF
	playfanfare MUS_FANFA4
	return

EventScript_PlayFanfareObtainedTMHM:: @ 8271BB3
	playfanfare MUS_ME_WAZA
	return

Std_ObtainDecoration:: @ 8271BB7
	givedecoration VAR_0x8000
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_271BC5
	return

EventScript_271BC5:: @ 8271BC5
	bufferdecorationname 1, VAR_0x8000
	compare VAR_0x8007, 1
	call_if_eq EventScript_271BE0
	compare VAR_0x8007, 0
	call_if_eq EventScript_271BF7
	return

EventScript_271BE0:: @ 8271BE0
	playfanfare MUS_FANFA4
	message gText_ObtainedTheDecor
	waitfanfare
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

EventScript_271BF7:: @ 8271BF7
	setvar VAR_RESULT, 0
	return

Std_FindItem:: @ 8271BFD
	lock
	faceplayer
	waitse
	copyvar VAR_0x8004, VAR_0x8000
	copyvar VAR_0x8005, VAR_0x8001
	checkitemspace VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	call_if_eq EventScript_PickItemUp
	compare VAR_0x8007, 0
	call_if_eq EventScript_271CA1
	release
	return

EventScript_PickItemUp:: @ 8271C3A
	removeobject VAR_LAST_TALKED
	giveitem VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 1
	call_if_eq EventScript_271C8F
	compare VAR_0x8008, 0
	call_if_eq EventScript_271C9B
	waitfanfare
	waitmessage
	bufferitemnameplural 1, VAR_0x8004, VAR_0x8005
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_IS_IN
	special CallBattlePyramidFunction
	compare VAR_RESULT, 1
	goto_if_eq EventScript_271C86
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	return

EventScript_271C86:: @ 8271C86
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_271C8F:: @ 8271C8F
	bufferitemnameplural 0, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneItemTwoLines
	return

EventScript_271C9B:: @ 8271C9B
	message gText_PlayerFoundOneItem
	return

EventScript_271CA1:: @ 8271CA1
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

EventScript_HiddenItemScript:: @ 8271CB7
	lockall
	waitse
	giveitem VAR_0x8005, 1
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	goto_if_eq EventScript_271CE8
	compare VAR_0x8007, 0
	goto_if_eq EventScript_271D47
	end

EventScript_271CE8:: @ 8271CE8
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	compare VAR_RESULT, 1
	goto_if_eq EventScript_271D0E
	compare VAR_RESULT, 0
	goto_if_eq EventScript_271D1F
	end

EventScript_271D0E:: @ 8271D0E
	bufferitemnameplural 0, VAR_0x8004, 1
	message gText_PlayerFoundOneItemTwoLines
	goto EventScript_271D2A
	end

EventScript_271D1F:: @ 8271D1F
	message gText_PlayerFoundOneItem
	goto EventScript_271D2A
	end

EventScript_271D2A:: @ 8271D2A
	waitmessage
	waitfanfare
	bufferitemnameplural 1, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	special sub_80EDCE8
	special SetFlagInVar
	releaseall
	end

EventScript_271D47:: @ 8271D47
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end
