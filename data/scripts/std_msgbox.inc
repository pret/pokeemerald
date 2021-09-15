Std_MsgboxNPC:
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign:
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault:
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints:
	message 0x0
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

Std_10:
	pokenavcall 0x0
	waitmessage
	return

EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	waitstate
	return
