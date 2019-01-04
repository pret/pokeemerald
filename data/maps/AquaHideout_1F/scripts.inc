AquaHideout_1F_MapScripts:: @ 8233493
	.byte 0

AquaHideout_1F_EventScript_233494:: @ 8233494
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334BC
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334B2
	msgbox AquaHideout_1F_Text_23351D, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334B2:: @ 82334B2
	msgbox AquaHideout_1F_Text_2335E3, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334BC:: @ 82334BC
	msgbox AquaHideout_1F_Text_23367D, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334C6:: @ 82334C6
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334EE
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334E4
	msgbox AquaHideout_1F_Text_233739, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334E4:: @ 82334E4
	msgbox AquaHideout_1F_Text_2337FA, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334EE:: @ 82334EE
	msgbox AquaHideout_1F_Text_233884, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_2334F8:: @ 82334F8
	trainerbattle_single TRAINER_GRUNT_1, AquaHideout_1F_Text_23393D, AquaHideout_1F_Text_233964, AquaHideout_1F_EventScript_233513
	msgbox AquaHideout_1F_Text_233977, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_233513:: @ 8233513
	msgbox AquaHideout_1F_Text_233977, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_23351D: @ 823351D
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's gone off to\n"
	.string "snatch something important!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_2335E3: @ 82335E3
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is trying to\n"
	.string "awaken an awesome POKéMON at their\l"
	.string "HIDEOUT.\p"
	.string "But where might their HIDEOUT be?$"

AquaHideout_1F_Text_23367D: @ 823367D
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's gone off to jack a submarine!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_233739: @ 8233739
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's on his way to\n"
	.string "MT. PYRE on ROUTE 122!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_2337FA: @ 82337FA
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is after\n"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
	.string "But what is that POKéMON like?$"

AquaHideout_1F_Text_233884: @ 8233884
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's on his way to SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_23393D: @ 823393D
	.string "Ayiyiyi!\n"
	.string "Suspicious character spotted!$"

AquaHideout_1F_Text_233964: @ 8233964
	.string "Grrrrr…\n"
	.string "I lost it!$"

AquaHideout_1F_Text_233977: @ 8233977
	.string "I took the loss for the TEAM,\n"
	.string "but I did my job…$"

