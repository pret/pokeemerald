LavaridgeTown_Gym_1F_MapScripts:: @ 81FE6F4
	map_script 3, LavaridgeTown_Gym_1F_MapScript1_1FE6FA
	.byte 0

LavaridgeTown_Gym_1F_MapScript1_1FE6FA: @ 81FE6FA
	call LavaridgeTown_Gym_1F_EventScript_1FE705
	call LavaridgeTown_Gym_1F_EventScript_1FE757
	end

LavaridgeTown_Gym_1F_EventScript_1FE705:: @ 81FE705
	setvar VAR_0x400B, 0
	setvar VAR_0x400C, 0
	setvar VAR_0x400D, 0
	setvar VAR_0x400E, 0
	setvar VAR_0x400F, 0
	checktrainerflag TRAINER_COLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE72C
	setvar VAR_0x400B, 1

LavaridgeTown_Gym_1F_EventScript_1FE72C:: @ 81FE72C
	checktrainerflag TRAINER_GERALD
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE73A
	setvar VAR_0x400C, 1

LavaridgeTown_Gym_1F_EventScript_1FE73A:: @ 81FE73A
	checktrainerflag TRAINER_AXLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE748
	setvar VAR_0x400D, 1

LavaridgeTown_Gym_1F_EventScript_1FE748:: @ 81FE748
	checktrainerflag TRAINER_DANIELLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE756
	setvar VAR_0x400E, 1

LavaridgeTown_Gym_1F_EventScript_1FE756:: @ 81FE756
	return

LavaridgeTown_Gym_1F_EventScript_1FE757:: @ 81FE757
	checktrainerflag TRAINER_COLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE764
	setobjectmovementtype 2, 63

LavaridgeTown_Gym_1F_EventScript_1FE764:: @ 81FE764
	checktrainerflag TRAINER_GERALD
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE771
	setobjectmovementtype 3, 63

LavaridgeTown_Gym_1F_EventScript_1FE771:: @ 81FE771
	checktrainerflag TRAINER_AXLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE77E
	setobjectmovementtype 4, 63

LavaridgeTown_Gym_1F_EventScript_1FE77E:: @ 81FE77E
	checktrainerflag TRAINER_DANIELLE
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE78B
	setobjectmovementtype 5, 63

LavaridgeTown_Gym_1F_EventScript_1FE78B:: @ 81FE78B
	return

LavaridgeTown_Gym_1F_EventScript_1FE78C:: @ 81FE78C
	trainerbattle 1, TRAINER_FLANNERY_1, 0, LavaridgeTown_Gym_1F_Text_1FF0DC, LavaridgeTown_Gym_1F_Text_1FF233, LavaridgeTown_Gym_1F_EventScript_1FE7C1
	specialvar VAR_RESULT, sub_80B226C
	compare_var_to_value VAR_RESULT, 1
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE864
	checkflag FLAG_0x0A8
	goto_if 0, LavaridgeTown_Gym_1F_EventScript_1FE81D
	msgbox LavaridgeTown_Gym_1F_Text_1FF546, 4
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE7C1:: @ 81FE7C1
	message LavaridgeTown_Gym_1F_Text_1FF32F
	waitmessage
	call LavaridgeTown_Gym_1F_EventScript_27207E
	msgbox LavaridgeTown_Gym_1F_Text_1FF359, 4
	setflag FLAG_0x06C
	setflag FLAG_0x4F3
	setflag FLAG_BADGE04_GET
	addvar VAR_0x4085, 1
	compare_var_to_value VAR_0x4085, 6
	call_if 1, LavaridgeTown_Gym_1F_EventScript_271E84
	setvar VAR_0x8008, 4
	call LavaridgeTown_Gym_1F_EventScript_271F43
	setflag FLAG_0x326
	setvar VAR_0x4053, 1
	call LavaridgeTown_Gym_1F_EventScript_1FE841
	closemessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_1FF517, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x1D6
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE81D:: @ 81FE81D
	giveitem_std ITEM_TM50
	compare_var_to_value VAR_RESULT, 0
	goto_eq LavaridgeTown_Gym_1F_EventScript_272054
	msgbox LavaridgeTown_Gym_1F_Text_1FF45C, 4
	setflag FLAG_0x0A8
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE841:: @ 81FE841
	giveitem_std ITEM_TM50
	compare_var_to_value VAR_RESULT, 0
	goto_eq LavaridgeTown_Gym_1F_EventScript_27205E
	msgbox LavaridgeTown_Gym_1F_Text_1FF45C, 4
	setflag FLAG_0x0A8
	return

LavaridgeTown_Gym_1F_EventScript_1FE864:: @ 81FE864
	trainerbattle 7, TRAINER_FLANNERY_1, 0, LavaridgeTown_Gym_1F_Text_1FF601, LavaridgeTown_Gym_1F_Text_1FF69F, LavaridgeTown_Gym_1F_Text_1FF75E
	msgbox LavaridgeTown_Gym_1F_Text_1FF6BF, 6
	end

LavaridgeTown_Gym_1F_EventScript_1FE87F:: @ 81FE87F
	trainerbattle 2, TRAINER_COLE, 2, LavaridgeTown_Gym_1F_Text_1FEADE, LavaridgeTown_Gym_1F_Text_1FEAFB, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEB1C, 6
	end

LavaridgeTown_Gym_1F_EventScript_1FE89A:: @ 81FE89A
LavaridgeTown_Gym_B1F_EventScript_1FE89A:: @ 81FE89A
	call LavaridgeTown_Gym_1F_EventScript_1FE705
	release
	special CheckIfMultipleTrainersWantBattle
	compare_var_to_value VAR_RESULT, 1
	goto_eq LavaridgeTown_Gym_1F_EventScript_2742F6
	end

LavaridgeTown_Gym_1F_EventScript_1FE8AF:: @ 81FE8AF
	trainerbattle 2, TRAINER_AXLE, 4, LavaridgeTown_Gym_1F_Text_1FEB7B, LavaridgeTown_Gym_1F_Text_1FEBC0, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEBE1, 6
	end

LavaridgeTown_Gym_B1F_EventScript_1FE8CA:: @ 81FE8CA
	trainerbattle 2, TRAINER_KEEGAN, 2, LavaridgeTown_Gym_B1F_Text_1FEC31, LavaridgeTown_Gym_B1F_Text_1FECE3, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FED02, 6
	end

LavaridgeTown_Gym_1F_EventScript_1FE8E5:: @ 81FE8E5
	trainerbattle 2, TRAINER_DANIELLE, 5, LavaridgeTown_Gym_1F_Text_1FEE22, LavaridgeTown_Gym_1F_Text_1FEE42, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEE5D, 6
	end

LavaridgeTown_Gym_1F_EventScript_1FE900:: @ 81FE900
	trainerbattle 2, TRAINER_GERALD, 3, LavaridgeTown_Gym_1F_Text_1FED72, LavaridgeTown_Gym_1F_Text_1FED9E, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEDBB, 6
	end

LavaridgeTown_Gym_B1F_EventScript_1FE91B:: @ 81FE91B
	trainerbattle 2, TRAINER_JACE, 1, LavaridgeTown_Gym_B1F_Text_1FEE9D, LavaridgeTown_Gym_B1F_Text_1FEED5, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FEF07, 6
	end

LavaridgeTown_Gym_B1F_EventScript_1FE936:: @ 81FE936
	trainerbattle 2, TRAINER_JEFF, 3, LavaridgeTown_Gym_B1F_Text_1FEF60, LavaridgeTown_Gym_B1F_Text_1FEFA7, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FEFC2, 6
	end

LavaridgeTown_Gym_B1F_EventScript_1FE951:: @ 81FE951
	trainerbattle 2, TRAINER_ELI, 4, LavaridgeTown_Gym_B1F_Text_1FF025, LavaridgeTown_Gym_B1F_Text_1FF05F, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FF09A, 6
	end

LavaridgeTown_Gym_1F_EventScript_1FE96C:: @ 81FE96C
	lock
	faceplayer
	checkflag FLAG_0x4F3
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE981
	msgbox LavaridgeTown_Gym_1F_Text_1FE9BF, 4
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE981:: @ 81FE981
	msgbox LavaridgeTown_Gym_1F_Text_1FEAB8, 4
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE98B:: @ 81FE98B
	lockall
	checkflag FLAG_BADGE04_GET
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE9AB
	goto LavaridgeTown_Gym_1F_EventScript_1FE9B5
	end

LavaridgeTown_Gym_1F_EventScript_1FE99B:: @ 81FE99B
	lockall
	checkflag FLAG_BADGE04_GET
	goto_eq LavaridgeTown_Gym_1F_EventScript_1FE9AB
	goto LavaridgeTown_Gym_1F_EventScript_1FE9B5
	end

LavaridgeTown_Gym_1F_EventScript_1FE9AB:: @ 81FE9AB
	msgbox LavaridgeTown_Gym_1F_Text_1FF5C4, 4
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_1FE9B5:: @ 81FE9B5
	msgbox LavaridgeTown_Gym_1F_Text_1FF5A9, 4
	releaseall
	end

LavaridgeTown_Gym_1F_Text_1FE9BF: @ 81FE9BF
	.string "Hey, how’s it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE’s GYM LEADER FLANNERY\n"
	.string "uses FIRE-type POKéMON.\p"
	.string "Her passion for POKéMON burns stronger\n"
	.string "and hotter than a volcano.\p"
	.string "Don’t get too close to her--you’ll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"

LavaridgeTown_Gym_1F_Text_1FEAB8: @ 81FEAB8
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_1FEADE: @ 81FEADE
	.string "Owowowowow!\n"
	.string "Yikes, it’s hot!$"

LavaridgeTown_Gym_1F_Text_1FEAFB: @ 81FEAFB
	.string "I’m blinded by sweat in my eyes…$"

LavaridgeTown_Gym_1F_Text_1FEB1C: @ 81FEB1C
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It’s effective for healing pain in\n"
	.string "your joints.$"

LavaridgeTown_Gym_1F_Text_1FEB7B: @ 81FEB7B
	.string "I’m trying to relieve my stress.\n"
	.string "Don’t come along and stress me out!$"

LavaridgeTown_Gym_1F_Text_1FEBC0: @ 81FEBC0
	.string "I hope FLANNERY flames you good!$"

LavaridgeTown_Gym_1F_Text_1FEBE1: @ 81FEBE1
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"

