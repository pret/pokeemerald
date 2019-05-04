DewfordTown_Gym_MapScripts:: @ 81FC63C
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition: @ 81FC642
	call DewfordTown_Gym_EventScript_1FC648
	end

DewfordTown_Gym_EventScript_1FC648:: @ 81FC648
	checktrainerflag TRAINER_BRAWLY_1
	goto_if_eq DewfordTown_Gym_EventScript_1FC6A2
	call DewfordTown_Gym_EventScript_1FC768
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 0
	goto_if_eq DewfordTown_Gym_EventScript_1FC6BE
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_1FC6BA
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_1FC6B6
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_1FC6B2
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_1FC6AE
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_1FC6AA
	goto DewfordTown_Gym_EventScript_1FC6A6

DewfordTown_Gym_EventScript_1FC6A2:: @ 81FC6A2
	setflashradius 0
	return

DewfordTown_Gym_EventScript_1FC6A6:: @ 81FC6A6
	setflashradius 1
	return

DewfordTown_Gym_EventScript_1FC6AA:: @ 81FC6AA
	setflashradius 2
	return

DewfordTown_Gym_EventScript_1FC6AE:: @ 81FC6AE
	setflashradius 3
	return

DewfordTown_Gym_EventScript_1FC6B2:: @ 81FC6B2
	setflashradius 4
	return

DewfordTown_Gym_EventScript_1FC6B6:: @ 81FC6B6
	setflashradius 5
	return

DewfordTown_Gym_EventScript_1FC6BA:: @ 81FC6BA
	setflashradius 6
	return

DewfordTown_Gym_EventScript_1FC6BE:: @ 81FC6BE
	setflashradius 7
	return

DewfordTown_Gym_EventScript_1FC6C2:: @ 81FC6C2
	call DewfordTown_Gym_EventScript_1FC768
	nop1
	compare VAR_0x8000, VAR_0x8001
	goto_if_eq DewfordTown_Gym_EventScript_1FC71A
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_1FC71B
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_1FC726
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_1FC731
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_1FC73C
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_1FC747
	compare VAR_0x8000, 6
	goto_if_eq DewfordTown_Gym_EventScript_1FC752

DewfordTown_Gym_EventScript_1FC71A:: @ 81FC71A
	return

DewfordTown_Gym_EventScript_1FC71B:: @ 81FC71B
	playse SE_MU_PACHI
	animateflash 6
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC726:: @ 81FC726
	playse SE_MU_PACHI
	animateflash 5
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC731:: @ 81FC731
	playse SE_MU_PACHI
	animateflash 4
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC73C:: @ 81FC73C
	playse SE_MU_PACHI
	animateflash 3
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC747:: @ 81FC747
	playse SE_MU_PACHI
	animateflash 2
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC752:: @ 81FC752
	playse SE_MU_PACHI
	animateflash 1
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC75D:: @ 81FC75D
	playse SE_MU_PACHI
	animateflash 0
	call DewfordTown_Gym_EventScript_1FC648
	return

DewfordTown_Gym_EventScript_1FC768:: @ 81FC768
	setvar VAR_0x8000, 0
	checktrainerflag TRAINER_TAKAO
	goto_if_lt DewfordTown_Gym_EventScript_1FC77B
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC77B:: @ 81FC77B
	checktrainerflag TRAINER_JOCELYN
	goto_if_lt DewfordTown_Gym_EventScript_1FC789
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC789:: @ 81FC789
	checktrainerflag TRAINER_LAURA
	goto_if_lt DewfordTown_Gym_EventScript_1FC797
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC797:: @ 81FC797
	checktrainerflag TRAINER_BRENDEN
	goto_if_lt DewfordTown_Gym_EventScript_1FC7A5
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC7A5:: @ 81FC7A5
	checktrainerflag TRAINER_CRISTIAN
	goto_if_lt DewfordTown_Gym_EventScript_1FC7B3
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC7B3:: @ 81FC7B3
	checktrainerflag TRAINER_LILITH
	goto_if_lt DewfordTown_Gym_EventScript_1FC7C1
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_1FC7C1:: @ 81FC7C1
	return

DewfordTown_Gym_EventScript_1FC7C2:: @ 81FC7C2
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_1FCF44, DewfordTown_Gym_Text_1FD008, DewfordTown_Gym_EventScript_1FC7F7, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Gym_EventScript_1FC89C
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_Gym_EventScript_1FC878
	msgbox DewfordTown_Gym_Text_1FD20D, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_1FC7F7:: @ 81FC7F7
	call DewfordTown_Gym_EventScript_1FC75D
	message DewfordTown_Gym_Text_1FD07D
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_1FD0A8, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq DewfordTown_Gym_EventScript_271E84
	setvar VAR_0x8008, 2
	call DewfordTown_Gym_EventScript_271F43
	call DewfordTown_Gym_EventScript_1FC855
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox DewfordTown_Gym_Text_1FD1E0, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_1FC855:: @ 81FC855
	giveitem_std ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_1FD181, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_Gym_EventScript_1FC878:: @ 81FC878
	giveitem_std ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_1FD181, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_Gym_EventScript_1FC89C:: @ 81FC89C
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_1FD2C4, DewfordTown_Gym_Text_1FD367, DewfordTown_Gym_Text_1FD3DE
	msgbox DewfordTown_Gym_Text_1FD37B, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC8B7:: @ 81FC8B7
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_1FCB9F, DewfordTown_Gym_Text_1FCBB8, DewfordTown_Gym_EventScript_1FC8D2
	msgbox DewfordTown_Gym_Text_1FCBCA, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC8D2:: @ 81FC8D2
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC8D9:: @ 81FC8D9
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_1FCC0A, DewfordTown_Gym_Text_1FCC45, DewfordTown_Gym_EventScript_1FC8F4
	msgbox DewfordTown_Gym_Text_1FCC6B, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC8F4:: @ 81FC8F4
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC8FB:: @ 81FC8FB
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_1FCD01, DewfordTown_Gym_Text_1FCD3C, DewfordTown_Gym_EventScript_1FC916
	msgbox DewfordTown_Gym_Text_1FCD4F, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC916:: @ 81FC916
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC91D:: @ 81FC91D
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_1FCE48, DewfordTown_Gym_Text_1FCE75, DewfordTown_Gym_EventScript_1FC938
	msgbox DewfordTown_Gym_Text_1FCEAB, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC938:: @ 81FC938
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC93F:: @ 81FC93F
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_1FCEDC, DewfordTown_Gym_Text_1FCF0A, DewfordTown_Gym_EventScript_1FC95A
	msgbox DewfordTown_Gym_Text_1FCF26, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC95A:: @ 81FC95A
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC961:: @ 81FC961
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_1FCDB8, DewfordTown_Gym_Text_1FCDE5, DewfordTown_Gym_EventScript_1FC97C
	msgbox DewfordTown_Gym_Text_1FCE08, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_1FC97C:: @ 81FC97C
	call DewfordTown_Gym_EventScript_1FC6C2
	release
	end

DewfordTown_Gym_EventScript_1FC983:: @ 81FC983
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_1FC998
	msgbox DewfordTown_Gym_Text_1FC9D6, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_1FC998:: @ 81FC998
	msgbox DewfordTown_Gym_Text_1FCB5C, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_1FC9A2:: @ 81FC9A2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_1FC9C2
	goto DewfordTown_Gym_EventScript_1FC9CC
	end

DewfordTown_Gym_EventScript_1FC9B2:: @ 81FC9B2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_1FC9C2
	goto DewfordTown_Gym_EventScript_1FC9CC
	end

DewfordTown_Gym_EventScript_1FC9C2:: @ 81FC9C2
	msgbox DewfordTown_Gym_Text_1FD28B, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_1FC9CC:: @ 81FC9CC
	msgbox DewfordTown_Gym_Text_1FD272, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_1FC9D6: @ 81FC9D6
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
	.string "FIGHTING-type POKéMON.\p"
	.string "Going against him with NORMAL-type\n"
	.string "POKéMON is asking for trouble.\p"
	.string "FIGHTING POKéMON will lay a serious\n"
	.string "smack down on NORMAL POKéMON,\l"
	.string "so be careful!\p"
	.string "What's worse, the GYM is as dark as\n"
	.string "the ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the TRAINERS in your way.\p"
	.string "Hey, okay, go for it!$"

DewfordTown_Gym_Text_1FCB5C: @ 81FCB5C
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

DewfordTown_Gym_Text_1FCB9F: @ 81FCB9F
	.string "Might is right!\n"
	.string "Come on!$"

DewfordTown_Gym_Text_1FCBB8: @ 81FCBB8
	.string "Not enough power…$"

DewfordTown_Gym_Text_1FCBCA: @ 81FCBCA
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

DewfordTown_Gym_Text_1FCC0A: @ 81FCC0A
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

DewfordTown_Gym_Text_1FCC45: @ 81FCC45
	.string "But… How?\n"
	.string "How could I lose so easily?$"

DewfordTown_Gym_Text_1FCC6B: @ 81FCC6B
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

DewfordTown_Gym_Text_1FCD01: @ 81FCD01
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

DewfordTown_Gym_Text_1FCD3C: @ 81FCD3C
	.string "Waaaaaaah!\n"
	.string "I lost!$"

DewfordTown_Gym_Text_1FCD4F: @ 81FCD4F
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"

DewfordTown_Gym_Text_1FCDB8: @ 81FCDB8
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

DewfordTown_Gym_Text_1FCDE5: @ 81FCDE5
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

DewfordTown_Gym_Text_1FCE08: @ 81FCE08
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

DewfordTown_Gym_Text_1FCE48: @ 81FCE48
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

DewfordTown_Gym_Text_1FCE75: @ 81FCE75
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

DewfordTown_Gym_Text_1FCEAB: @ 81FCEAB
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

DewfordTown_Gym_Text_1FCEDC: @ 81FCEDC
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

DewfordTown_Gym_Text_1FCF0A: @ 81FCF0A
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

DewfordTown_Gym_Text_1FCF26: @ 81FCF26
	.string "You win!\n"
	.string "Go after that BADGE!$"

DewfordTown_Gym_Text_1FCF44: @ 81FCF44
	.string "I'm BRAWLY!\n"
	.string "DEWFORD's GYM LEADER!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

DewfordTown_Gym_Text_1FD008: @ 81FD008
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

DewfordTown_Gym_Text_1FD07D: @ 81FD07D
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"

DewfordTown_Gym_Text_1FD0A8: @ 81FD0A8
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

DewfordTown_Gym_Text_1FD181: @ 81FD181
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_1FD1E0: @ 81FD1E0
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"

DewfordTown_Gym_Text_1FD20D: @ 81FD20D
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"

DewfordTown_Gym_Text_1FD272: @ 81FD272
	.string "DEWFORD TOWN POKéMON GYM$"

DewfordTown_Gym_Text_1FD28B: @ 81FD28B
	.string "DEWFORD TOWN POKéMON GYM\p"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_1FD2C4: @ 81FD2C4
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_Gym_Text_1FD367: @ 81FD367
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_Gym_Text_1FD37B: @ 81FD37B
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

DewfordTown_Gym_Text_1FD3DE: @ 81FD3DE
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
