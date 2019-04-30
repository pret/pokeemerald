LavaridgeTown_Gym_1F_MapScripts:: @ 81FE6F4
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition: @ 81FE6FA
	call LavaridgeTown_Gym_1F_EventScript_1FE705
	call LavaridgeTown_Gym_1F_EventScript_1FE757
	end

LavaridgeTown_Gym_1F_EventScript_1FE705:: @ 81FE705
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	checktrainerflag TRAINER_COLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE72C
	setvar VAR_TEMP_B, 1

LavaridgeTown_Gym_1F_EventScript_1FE72C:: @ 81FE72C
	checktrainerflag TRAINER_GERALD
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE73A
	setvar VAR_TEMP_C, 1

LavaridgeTown_Gym_1F_EventScript_1FE73A:: @ 81FE73A
	checktrainerflag TRAINER_AXLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE748
	setvar VAR_TEMP_D, 1

LavaridgeTown_Gym_1F_EventScript_1FE748:: @ 81FE748
	checktrainerflag TRAINER_DANIELLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE756
	setvar VAR_TEMP_E, 1

LavaridgeTown_Gym_1F_EventScript_1FE756:: @ 81FE756
	return

LavaridgeTown_Gym_1F_EventScript_1FE757:: @ 81FE757
	checktrainerflag TRAINER_COLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE764
	setobjectmovementtype 2, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_1F_EventScript_1FE764:: @ 81FE764
	checktrainerflag TRAINER_GERALD
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE771
	setobjectmovementtype 3, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_1F_EventScript_1FE771:: @ 81FE771
	checktrainerflag TRAINER_AXLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE77E
	setobjectmovementtype 4, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_1F_EventScript_1FE77E:: @ 81FE77E
	checktrainerflag TRAINER_DANIELLE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE78B
	setobjectmovementtype 5, MOVEMENT_TYPE_HIDDEN

LavaridgeTown_Gym_1F_EventScript_1FE78B:: @ 81FE78B
	return

LavaridgeTown_Gym_1F_EventScript_1FE78C:: @ 81FE78C
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_1FF0DC, LavaridgeTown_Gym_1F_Text_1FF233, LavaridgeTown_Gym_1F_EventScript_1FE7C1, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE864
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_1FE81D
	msgbox LavaridgeTown_Gym_1F_Text_1FF546, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE7C1:: @ 81FE7C1
	message LavaridgeTown_Gym_1F_Text_1FF32F
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_1FF359, MSGBOX_DEFAULT
	setflag FLAG_FLANNERY_GIVES_BADGE_INFO
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq LavaridgeTown_Gym_1F_EventScript_271E84
	setvar VAR_0x8008, 4
	call LavaridgeTown_Gym_1F_EventScript_271F43
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_RIVAL_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_1FE841
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox LavaridgeTown_Gym_1F_Text_1FF517, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE81D:: @ 81FE81D
	giveitem_std ITEM_TM50
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_1FF45C, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE841:: @ 81FE841
	giveitem_std ITEM_TM50
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_1FF45C, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_1FE864:: @ 81FE864
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_1FF601, LavaridgeTown_Gym_1F_Text_1FF69F, LavaridgeTown_Gym_1F_Text_1FF75E
	msgbox LavaridgeTown_Gym_1F_Text_1FF6BF, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_1FE87F:: @ 81FE87F
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, 2, LavaridgeTown_Gym_1F_Text_1FEADE, LavaridgeTown_Gym_1F_Text_1FEAFB, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEB1C, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_1FE89A:: @ 81FE89A
LavaridgeTown_Gym_B1F_EventScript_1FE89A:: @ 81FE89A
	call LavaridgeTown_Gym_1F_EventScript_1FE705
	release
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_1FE8AF:: @ 81FE8AF
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, 4, LavaridgeTown_Gym_1F_Text_1FEB7B, LavaridgeTown_Gym_1F_Text_1FEBC0, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEBE1, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_1FE8CA:: @ 81FE8CA
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, 2, LavaridgeTown_Gym_B1F_Text_1FEC31, LavaridgeTown_Gym_B1F_Text_1FECE3, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FED02, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_1FE8E5:: @ 81FE8E5
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, 5, LavaridgeTown_Gym_1F_Text_1FEE22, LavaridgeTown_Gym_1F_Text_1FEE42, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEE5D, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_1FE900:: @ 81FE900
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, 3, LavaridgeTown_Gym_1F_Text_1FED72, LavaridgeTown_Gym_1F_Text_1FED9E, LavaridgeTown_Gym_1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_1F_Text_1FEDBB, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_1FE91B:: @ 81FE91B
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, 1, LavaridgeTown_Gym_B1F_Text_1FEE9D, LavaridgeTown_Gym_B1F_Text_1FEED5, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FEF07, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_1FE936:: @ 81FE936
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, 3, LavaridgeTown_Gym_B1F_Text_1FEF60, LavaridgeTown_Gym_B1F_Text_1FEFA7, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FEFC2, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_1FE951:: @ 81FE951
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, 4, LavaridgeTown_Gym_B1F_Text_1FF025, LavaridgeTown_Gym_B1F_Text_1FF05F, LavaridgeTown_Gym_B1F_EventScript_1FE89A
	msgbox LavaridgeTown_Gym_B1F_Text_1FF09A, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_1FE96C:: @ 81FE96C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_1FE981
	msgbox LavaridgeTown_Gym_1F_Text_1FE9BF, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE981:: @ 81FE981
	msgbox LavaridgeTown_Gym_1F_Text_1FEAB8, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_1FE98B:: @ 81FE98B
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_1FE9AB
	goto LavaridgeTown_Gym_1F_EventScript_1FE9B5
	end

LavaridgeTown_Gym_1F_EventScript_1FE99B:: @ 81FE99B
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_1FE9AB
	goto LavaridgeTown_Gym_1F_EventScript_1FE9B5
	end

LavaridgeTown_Gym_1F_EventScript_1FE9AB:: @ 81FE9AB
	msgbox LavaridgeTown_Gym_1F_Text_1FF5C4, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_1FE9B5:: @ 81FE9B5
	msgbox LavaridgeTown_Gym_1F_Text_1FF5A9, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_1FE9BF: @ 81FE9BF
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE's GYM LEADER FLANNERY\n"
	.string "uses FIRE-type POKéMON.\p"
	.string "Her passion for POKéMON burns stronger\n"
	.string "and hotter than a volcano.\p"
	.string "Don't get too close to her--you'll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"

LavaridgeTown_Gym_1F_Text_1FEAB8: @ 81FEAB8
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_1FEADE: @ 81FEADE
	.string "Owowowowow!\n"
	.string "Yikes, it's hot!$"

LavaridgeTown_Gym_1F_Text_1FEAFB: @ 81FEAFB
	.string "I'm blinded by sweat in my eyes…$"

LavaridgeTown_Gym_1F_Text_1FEB1C: @ 81FEB1C
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It's effective for healing pain in\n"
	.string "your joints.$"

LavaridgeTown_Gym_1F_Text_1FEB7B: @ 81FEB7B
	.string "I'm trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"

LavaridgeTown_Gym_1F_Text_1FEBC0: @ 81FEBC0
	.string "I hope FLANNERY flames you good!$"

LavaridgeTown_Gym_1F_Text_1FEBE1: @ 81FEBE1
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"

LavaridgeTown_Gym_B1F_Text_1FEC31: @ 81FEC31
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "But you should know that maintaining\n"
	.string "your willpower is an important ability\l"
	.string "for all TRAINERS.$"

LavaridgeTown_Gym_B1F_Text_1FECE3: @ 81FECE3
	.string "Play with fire, and be burned…$"

LavaridgeTown_Gym_B1F_Text_1FED02: @ 81FED02
	.string "Your skill is real…\n"
	.string "But our LEADER FLANNERY is strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"

LavaridgeTown_Gym_1F_Text_1FED72: @ 81FED72
	.string "Can your POKéMON withstand\n"
	.string "392-degree heat?$"

LavaridgeTown_Gym_1F_Text_1FED9E: @ 81FED9E
	.string "It didn't burn hotly enough…$"

LavaridgeTown_Gym_1F_Text_1FEDBB: @ 81FEDBB
	.string "The temperature of magma is\n"
	.string "392 degrees.\p"
	.string "Your POKéMON beat me, so they should\n"
	.string "easily survive in magma.$"

LavaridgeTown_Gym_1F_Text_1FEE22: @ 81FEE22
	.string "Um…\n"
	.string "Okay, I'll battle with you.$"

LavaridgeTown_Gym_1F_Text_1FEE42: @ 81FEE42
	.string "Oh, but you're too strong.$"

LavaridgeTown_Gym_1F_Text_1FEE5D: @ 81FEE5D
	.string "I'm going to be a pretty and strong\n"
	.string "TRAINER just like FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_1FEE9D: @ 81FEE9D
	.string "Come on, get with it!\n"
	.string "Let's go before my feelings cool!$"

LavaridgeTown_Gym_B1F_Text_1FEED5: @ 81FEED5
	.string "It's so hot, and yet my heart is\n"
	.string "clutched by ice…$"

LavaridgeTown_Gym_B1F_Text_1FEF07: @ 81FEF07
	.string "The way the battling spirit burns\n"
	.string "within you, you may stand a chance\l"
	.string "against our LEADER.$"

LavaridgeTown_Gym_B1F_Text_1FEF60: @ 81FEF60
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"

LavaridgeTown_Gym_B1F_Text_1FEFA7: @ 81FEFA7
	.string "Something didn't go right.$"

LavaridgeTown_Gym_B1F_Text_1FEFC2: @ 81FEFC2
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"

LavaridgeTown_Gym_B1F_Text_1FF025: @ 81FF025
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"

LavaridgeTown_Gym_B1F_Text_1FF05F: @ 81FF05F
	.string "Well, it seems to me I lost without\n"
	.string "ever being in control.$"

LavaridgeTown_Gym_B1F_Text_1FF09A: @ 81FF09A
	.string "I stay here because I became a fan\n"
	.string "of FLANNERY's power.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_1FF0DC: @ 81FF0DC
	.string "Welcome… No, wait.\p"
	.string "Puny TRAINER, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, wait.\p"
	.string "I am FLANNERY, and I'm the GYM\n"
	.string "LEADER here!\p"
	.string "Uh…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been LEADER only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"

LavaridgeTown_Gym_1F_Text_1FF233: @ 81FF233
	.string "Oh…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a GYM LEADER.\p"
	.string "I tried too hard to be someone\n"
	.string "I'm not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my POKéMON will be confused.\p"
	.string "Thanks for teaching me that.\n"
	.string "For that, you deserve this.$"

LavaridgeTown_Gym_1F_Text_1FF32F: @ 81FF32F
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"

LavaridgeTown_Gym_1F_Text_1FF359: @ 81FF359
	.string "If you have a HEAT BADGE, all POKéMON\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets POKéMON use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_1F_Text_1FF45C: @ 81FF45C
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_1FF517: @ 81FF517
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéNAV.$"

LavaridgeTown_Gym_1F_Text_1FF546: @ 81FF546
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"

LavaridgeTown_Gym_1F_Text_1FF5A9: @ 81FF5A9
	.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_1FF5C4: @ 81FF5C4
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_1FF601: @ 81FF601
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_1F_Text_1FF69F: @ 81FF69F
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_1F_Text_1FF6BF: @ 81FF6BF
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_1F_Text_1FF75E: @ 81FF75E
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one POKéMON\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two POKéMON.$"
