MossdeepCity_Gym_MapScripts:: @ 8220800
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_MapScript1_220806
	.byte 0

MossdeepCity_Gym_MapScript1_220806: @ 8220806
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_22083D
	goto MossdeepCity_Gym_EventScript_220815
	end

MossdeepCity_Gym_EventScript_220815:: @ 8220815
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_220855
	goto MossdeepCity_Gym_EventScript_220824
	end

MossdeepCity_Gym_EventScript_220824:: @ 8220824
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_22086D
	goto MossdeepCity_Gym_EventScript_220833
	end

MossdeepCity_Gym_EventScript_220833:: @ 8220833
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_220885
	end

MossdeepCity_Gym_EventScript_22083D:: @ 822083D
	setmetatile 5, 5, 516, 0
	setmetatile 2, 7, 569, 1
	goto MossdeepCity_Gym_EventScript_220815
	end

MossdeepCity_Gym_EventScript_220855:: @ 8220855
	setmetatile 8, 14, 516, 0
	setmetatile 8, 10, 569, 1
	goto MossdeepCity_Gym_EventScript_220824
	end

MossdeepCity_Gym_EventScript_22086D:: @ 822086D
	setmetatile 15, 17, 524, 0
	setmetatile 17, 15, 569, 1
	goto MossdeepCity_Gym_EventScript_220833
	end

MossdeepCity_Gym_EventScript_220885:: @ 8220885
	setmetatile 1, 23, 525, 0
	setmetatile 5, 24, 569, 1
	end

MossdeepCity_Gym_EventScript_220898:: @ 8220898
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_221783, MossdeepCity_Gym_Text_2218EC, MossdeepCity_Gym_Text_221BCE, MossdeepCity_Gym_EventScript_2208D1, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_Gym_EventScript_22097E
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_220937
	msgbox MossdeepCity_Gym_Text_221B1D, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_2208D1:: @ 82208D1
	message MossdeepCity_Gym_Text_22196A
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_221999, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call MossdeepCity_Gym_EventScript_271F43
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 1
	call MossdeepCity_Gym_EventScript_22095B
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox MossdeepCity_Gym_Text_221AEA, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_220937:: @ 8220937
	giveitem_std ITEM_TM04
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_221A40, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_22095B:: @ 822095B
	giveitem_std ITEM_TM04
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_221A40, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_22097E:: @ 822097E
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_221D0B, MossdeepCity_Gym_Text_221E05, MossdeepCity_Gym_Text_221EB8
	msgbox MossdeepCity_Gym_Text_221E45, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220999:: @ 8220999
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_2209D0
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 5, 5, 516, 0
	setmetatile 2, 7, 569, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_2209C8:: @ 82209C8
	special DrawWholeMapView
	playse SE_TK_KASYA
	releaseall
	end

MossdeepCity_Gym_EventScript_2209D0:: @ 82209D0
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 5, 5, 524, 0
	setmetatile 2, 7, 568, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_2209F5:: @ 82209F5
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_220A24
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 8, 14, 516, 0
	setmetatile 8, 10, 569, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220A24:: @ 8220A24
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 8, 14, 517, 0
	setmetatile 8, 10, 568, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220A49:: @ 8220A49
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_220A78
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 15, 17, 524, 0
	setmetatile 17, 15, 569, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220A78:: @ 8220A78
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 15, 17, 516, 0
	setmetatile 17, 15, 568, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220A9D:: @ 8220A9D
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_220ACC
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 1, 23, 525, 0
	setmetatile 5, 24, 569, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220ACC:: @ 8220ACC
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Gym_Movement_220C30
	waitmovement 0
	setmetatile 1, 23, 516, 0
	setmetatile 5, 24, 568, 1
	goto MossdeepCity_Gym_EventScript_2209C8
	end

MossdeepCity_Gym_EventScript_220AF1:: @ 8220AF1
	lockall
	warp7 MAP_MOSSDEEP_CITY_GYM, 255, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_220AFD:: @ 8220AFD
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_220E5C, MossdeepCity_Gym_Text_220EAC
	msgbox MossdeepCity_Gym_Text_220ED3, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B14:: @ 8220B14
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_220F02, MossdeepCity_Gym_Text_220F1A
	msgbox MossdeepCity_Gym_Text_220F3A, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B2B:: @ 8220B2B
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_220FB0, MossdeepCity_Gym_Text_221024
	msgbox MossdeepCity_Gym_Text_221055, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B42:: @ 8220B42
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_2210EE, MossdeepCity_Gym_Text_221152
	msgbox MossdeepCity_Gym_Text_22116A, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B59:: @ 8220B59
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_2211E2, MossdeepCity_Gym_Text_221230
	msgbox MossdeepCity_Gym_Text_22123D, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B70:: @ 8220B70
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_2212A6, MossdeepCity_Gym_Text_221309
	msgbox MossdeepCity_Gym_Text_22132E, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B87:: @ 8220B87
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_2213C2, MossdeepCity_Gym_Text_2213F4
	msgbox MossdeepCity_Gym_Text_221412, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220B9E:: @ 8220B9E
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_221460, MossdeepCity_Gym_Text_2214A7
	msgbox MossdeepCity_Gym_Text_2214D3, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220BB5:: @ 8220BB5
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_22161B, MossdeepCity_Gym_Text_221658
	msgbox MossdeepCity_Gym_Text_221680, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220BCC:: @ 8220BCC
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_22157C, MossdeepCity_Gym_Text_2215B8
	msgbox MossdeepCity_Gym_Text_2215E2, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220BE3:: @ 8220BE3
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_2216EE, MossdeepCity_Gym_Text_22172D
	msgbox MossdeepCity_Gym_Text_22173A, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220BFA:: @ 8220BFA
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_221507, MossdeepCity_Gym_Text_22153B
	msgbox MossdeepCity_Gym_Text_221545, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_220C11:: @ 8220C11
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_220C26
	msgbox MossdeepCity_Gym_Text_220CD5, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_220C26:: @ 8220C26
	msgbox MossdeepCity_Gym_Text_220E2A, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_Movement_220C30: @ 8220C30
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_220C33:: @ 8220C33
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_220C53
	goto MossdeepCity_Gym_EventScript_220C5D
	end

MossdeepCity_Gym_EventScript_220C43:: @ 8220C43
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_220C53
	goto MossdeepCity_Gym_EventScript_220C5D
	end

MossdeepCity_Gym_EventScript_220C53:: @ 8220C53
	msgbox MossdeepCity_Gym_Text_221CCA, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_220C5D:: @ 8220C5D
	msgbox MossdeepCity_Gym_Text_221CB0, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_220C67:: @ 8220C67
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 0
	mossdeepgym1 0
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

MossdeepCity_Gym_EventScript_220C7D:: @ 8220C7D
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 0
	mossdeepgym1 1
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

MossdeepCity_Gym_EventScript_220C93:: @ 8220C93
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 0
	mossdeepgym1 2
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

MossdeepCity_Gym_EventScript_220CA9:: @ 8220CA9
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 0
	mossdeepgym1 3
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

MossdeepCity_Gym_EventScript_220CBF:: @ 8220CBF
	playse SE_MU_PACHI
	waitse
	playse SE_TU_SAA
	mossdeepgym3 0
	mossdeepgym1 4
	waitmovement 0
	mossdeepgym2
	waitmovement 0
	mossdeepgym4
	end

MossdeepCity_Gym_Text_220CD5: @ 8220CD5
	.string "Yo, how's it going, CHAMPION-bound\n"
	.string "{PLAYER}?\p"
	.string "The GYM LEADERS here use\n"
	.string "PSYCHIC-type POKéMON.\p"
	.string "If you go up against them with\n"
	.string "FIGHTING- or POISON-type POKéMON,\l"
	.string "they'll inflict horrible damage!\p"
	.string "Plus, they'll come at you with\n"
	.string "outstanding combination attacks.\p"
	.string "If you want to win, you'll need to show\n"
	.string "them how tight you are with your\l"
	.string "POKéMON. Go for it!$"

MossdeepCity_Gym_Text_220E2A: @ 8220E2A
	.string "Wow, you're astounding!\n"
	.string "You're one great TRAINER!$"

MossdeepCity_Gym_Text_220E5C: @ 8220E5C
	.string "Battles hinge on the strength of your\n"
	.string "spirit! The weak-spirited will never win!$"

MossdeepCity_Gym_Text_220EAC: @ 8220EAC
	.string "I lost!\n"
	.string "I must temper my spirit again!$"

MossdeepCity_Gym_Text_220ED3: @ 8220ED3
	.string "The indecisive lose.\n"
	.string "That's my warning to you.$"

MossdeepCity_Gym_Text_220F02: @ 8220F02
	.string "Let me see your talent!$"

MossdeepCity_Gym_Text_220F1A: @ 8220F1A
	.string "You possess spectacular talent!$"

MossdeepCity_Gym_Text_220F3A: @ 8220F3A
	.string "If there are prodigies in the world,\n"
	.string "then our GYM LEADERS are them!\p"
	.string "However, you may be even more talented\n"
	.string "than them…$"

MossdeepCity_Gym_Text_220FB0: @ 8220FB0
	.string "Fufufufu… Watch me levitate a POKé\n"
	.string "BALL telekinetically!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Sometimes, I'm out of sync…$"

MossdeepCity_Gym_Text_221024: @ 8221024
	.string "My POKéMON battling skills are out\n"
	.string "of sync, too!$"

MossdeepCity_Gym_Text_221055: @ 8221055
	.string "A POKé BALL was too heavy to lift\n"
	.string "psychically. But this dust bunny…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, I'm not cheating!\n"
	.string "I didn't blow on it! Honestly!$"

MossdeepCity_Gym_Text_2210EE: @ 82210EE
	.string "When you lose to me, don't be too hard\n"
	.string "on yourself.\p"
	.string "It's not that you're weak--I'm just\n"
	.string "too strong!$"

MossdeepCity_Gym_Text_221152: @ 8221152
	.string "You're just too strong!$"

MossdeepCity_Gym_Text_22116A: @ 822116A
	.string "I'm not going to get down on myself for\n"
	.string "losing. I just need to train harder.\p"
	.string "Positive thinking--that's my strong\n"
	.string "point!$"

MossdeepCity_Gym_Text_2211E2: @ 82211E2
	.string "I see it…\n"
	.string "I see your future…\p"
	.string "If you can beat me, I will tell you\n"
	.string "your future!$"

MossdeepCity_Gym_Text_221230: @ 8221230
	.string "I surrender!$"

MossdeepCity_Gym_Text_22123D: @ 822123D
	.string "You will wage a terrifically intense\n"
	.string "battle with our GYM LEADERS…\p"
	.string "The result…\n"
	.string "You won't hear it from me!$"

MossdeepCity_Gym_Text_2212A6: @ 82212A6
	.string "The roads you have traveled…\n"
	.string "What you have experienced…\p"
	.string "Come at me with everything you've\n"
	.string "learned!$"

MossdeepCity_Gym_Text_221309: @ 8221309
	.string "You've traveled a path of greatness!$"

MossdeepCity_Gym_Text_22132E: @ 822132E
	.string "A bright future awaits those who have\n"
	.string "worked diligently.\p"
	.string "For those who lazed idly, there is\n"
	.string "only despair at the end.\p"
	.string "What goes around comes around…$"

MossdeepCity_Gym_Text_2213C2: @ 82213C2
	.string "Even at the risk of life, I will win\n"
	.string "this battle!$"

MossdeepCity_Gym_Text_2213F4: @ 82213F4
	.string "What you do…\n"
	.string "It horrifies me…$"

MossdeepCity_Gym_Text_221412: @ 8221412
	.string "How dare you beat me…\p"
	.string "It won't be my fault if something\n"
	.string "horrible befalls you…$"

MossdeepCity_Gym_Text_221460: @ 8221460
	.string "Hohoho.\p"
	.string "You need me to show you how tenacious\n"
	.string "the PSYCHIC type can be.$"

MossdeepCity_Gym_Text_2214A7: @ 82214A7
	.string "Oh! My, my!\n"
	.string "Your battle style is fantastic!$"

MossdeepCity_Gym_Text_2214D3: @ 82214D3
	.string "I… I don't let defeat rattle m-me,\n"
	.string "however b-badly.$"

MossdeepCity_Gym_Text_221507: @ 8221507
	.string "Let me show you a perfectly awful,\n"
	.string "horrifying time!$"

MossdeepCity_Gym_Text_22153B: @ 822153B
	.string "N-nooooo!$"

MossdeepCity_Gym_Text_221545: @ 8221545
	.string "Your vitality is contagious!\n"
	.string "Get away from me quickly!$"

MossdeepCity_Gym_Text_22157C: @ 822157C
	.string "I may be past my prime, but I suggest\n"
	.string "you not patronize me.$"

MossdeepCity_Gym_Text_2215B8: @ 82215B8
	.string "Ah, you overflow with the power\n"
	.string "of youth!$"

MossdeepCity_Gym_Text_2215E2: @ 82215E2
	.string "It seems that I could not overcome\n"
	.string "your youthful energy.$"

MossdeepCity_Gym_Text_22161B: @ 822161B
	.string "You're not getting through to the end!\n"
	.string "Not if I can help it!$"

MossdeepCity_Gym_Text_221658: @ 8221658
	.string "How could you be so ludicrously\n"
	.string "strong?$"

MossdeepCity_Gym_Text_221680: @ 8221680
	.string "Humph! You may be strong, but you're\n"
	.string "not suitable for the PSYCHIC type!\p"
	.string "The way you battle is somehow brutal!$"

MossdeepCity_Gym_Text_2216EE: @ 82216EE
	.string "Wroooar! Have a taste of my super\n"
	.string "POKéMON hard-battling power!$"

MossdeepCity_Gym_Text_22172D: @ 822172D
	.string "Oh!\n"
	.string "Done in!$"

MossdeepCity_Gym_Text_22173A: @ 822173A
	.string "All right! I think I'll develop a special\n"
	.string "invincible POKéMON power next.$"

MossdeepCity_Gym_Text_221783: @ 8221783
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: Fufufu… Were you surprised?\p"
	.string "TATE: That there are two GYM LEADERS?\n"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: We're twins!\n"
	.string "LIZA: We're twins!\p"
	.string "TATE: We don't need to talk because…\n"
	.string "LIZA: We can each determine what…\p"
	.string "TATE: The other is thinking…\n"
	.string "LIZA: All in our minds!\p"
	.string "TATE: This combination of ours…\n"
	.string "LIZA: Can you beat it?$"

MossdeepCity_Gym_Text_2218EC: @ 82218EC
	.string "TATE: What?! Our combination…\n"
	.string "LIZA: Was shattered!\p"
	.string "TATE: It can't be helped. You've won…\n"
	.string "LIZA: So, in recognition, take this.$"

MossdeepCity_Gym_Text_22196A: @ 822196A
	.string "{PLAYER} received the MIND BADGE\n"
	.string "from TATE and LIZA.$"

MossdeepCity_Gym_Text_221999: @ 8221999
	.string "TATE: The MIND BADGE enhances the\n"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
	.string "LIZA: It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "TATE: You should also take this, too.$"

MossdeepCity_Gym_Text_221A40: @ 8221A40
	.string "TATE: That TM04 contains…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: It raises SP. ATK and…\n"
	.string "LIZA: It raises SP. DEF!\p"
	.string "TATE: It's a move that's perfect…\n"
	.string "LIZA: For PSYCHIC POKéMON!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_221AEA: @ 8221AEA
	.string "Registered GYM LEADERS TATE & LIZA\n"
	.string "in the POKéNAV.$"

MossdeepCity_Gym_Text_221B1D: @ 8221B1D
	.string "TATE: Looks like the bond between you\n"
	.string "and your POKéMON is far stronger than\l"
	.string "the bond that we share as twins.\p"
	.string "LIZA: You will become even stronger!\n"
	.string "We've battled you, so we know.$"

MossdeepCity_Gym_Text_221BCE: @ 8221BCE
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: Oops, you have only one…\n"
	.string "LIZA: POKéMON that can battle.\p"
	.string "TATE: We can't battle that way!\p"
	.string "LIZA: If you want to challenge us,\n"
	.string "bring some more POKéMON.$"

MossdeepCity_Gym_Text_221CB0: @ 8221CB0
	.string "MOSSDEEP CITY POKéMON GYM$"

MossdeepCity_Gym_Text_221CCA: @ 8221CCA
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_221D0B: @ 8221D0B
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"

MossdeepCity_Gym_Text_221E05: @ 8221E05
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"

MossdeepCity_Gym_Text_221E45: @ 8221E45
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"

MossdeepCity_Gym_Text_221EB8: @ 8221EB8
	.string "TATE: You're back again…\n"
	.string "LIZA: You're back again…\p"
	.string "TATE: To give us a rematch.\n"
	.string "LIZA: To give us a rematch.\p"
	.string "TATE: But…\n"
	.string "LIZA: For our match…\p"
	.string "TATE: You brought just one POKéMON!\n"
	.string "LIZA: You brought just one POKéMON!\p"
	.string "TATE: We need you to bring at least…\n"
	.string "LIZA: Two POKéMON when you come back.$"
