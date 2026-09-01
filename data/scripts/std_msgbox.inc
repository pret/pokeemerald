Std_MsgboxNPC:
	lock
	faceplayer
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign:
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	lockall
	message NULL
	waitmessage
	waitbuttonpress
	releaseall
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Std_MsgboxDefault:
	message NULL
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	message NULL
	waitmessage
	yesnobox 20, 8
	return

Std_ReceivedItem::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	call_if_eq VAR_0x8002, MUS_LEVEL_UP, EventScript_ReceivedItemFanfare1
	call_if_eq VAR_0x8002, MUS_RG_OBTAIN_KEY_ITEM, EventScript_ReceivedItemFanfare2
	message NULL
	waitmessage
	waitfanfare
	call_if_eq VAR_0x8002, MUS_LEVEL_UP, EventScript_ReceivedItemWaitFanfare
	putitemaway VAR_0x8000, VAR_0x8001
	call EventScript_RestorePrevTextColor
	return

EventScript_ReceivedItemFanfare1::
	playfanfare MUS_LEVEL_UP
	return

EventScript_ReceivedItemFanfare2::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	return

EventScript_ReceivedItemWaitFanfare::
	delay 50
	return

Std_MsgboxGetPoints:
	message NULL
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

@ Never used, pokenavcall is always used directly instead
Std_MsgboxPokenav:
	pokenavcall NULL
	waitmessage
	return

EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	return
