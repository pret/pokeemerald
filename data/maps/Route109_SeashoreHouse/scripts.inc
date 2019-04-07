Route109_SeashoreHouse_MapScripts:: @ 82693F4
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition: @ 82693FA
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_2693FE:: @ 82693FE
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_269460
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_269432
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_269428
	msgbox Route109_SeashoreHouse_Text_269555, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_269428:: @ 8269428
	msgbox Route109_SeashoreHouse_Text_269635, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_269432:: @ 8269432
	msgbox Route109_SeashoreHouse_Text_269685, MSGBOX_DEFAULT
	giveitem_std ITEM_SODA_POP, 6
	compare VAR_RESULT, 0
	goto_if_eq Route109_SeashoreHouse_EventScript_269456
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_269456:: @ 8269456
	msgbox Route109_SeashoreHouse_Text_26973A, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_269460:: @ 8269460
	showmoneybox 0, 0, 0
	msgbox Route109_SeashoreHouse_Text_26977E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route109_SeashoreHouse_EventScript_269484
	msgbox Route109_SeashoreHouse_Text_2697EF, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_269484:: @ 8269484
	checkmoney 0x12c, 0
	compare VAR_RESULT, 0
	goto_if_eq Route109_SeashoreHouse_EventScript_2694C8
	checkitemspace ITEM_SODA_POP, 1
	compare VAR_RESULT, 0
	goto_if_eq Route109_SeashoreHouse_EventScript_2694D5
	msgbox Route109_SeashoreHouse_Text_2697C8, MSGBOX_DEFAULT
	takemoney 0x12c, 0
	updatemoneybox 0, 0
	nop
	giveitem_std ITEM_SODA_POP
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_2694C8:: @ 82694C8
	msgbox Route109_SeashoreHouse_Text_2697D5, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_2694D5:: @ 82694D5
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	nop
	nop
	release
	end

Route109_SeashoreHouse_EventScript_2694E2:: @ 82694E2
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_269803, Route109_SeashoreHouse_Text_269867, Route109_SeashoreHouse_EventScript_269533
	msgbox Route109_SeashoreHouse_Text_26989D, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_2694FD:: @ 82694FD
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_2698E3, Route109_SeashoreHouse_Text_269947, Route109_SeashoreHouse_EventScript_269533
	msgbox Route109_SeashoreHouse_Text_269953, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_269518:: @ 8269518
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_269986, Route109_SeashoreHouse_Text_2699C5, Route109_SeashoreHouse_EventScript_269533
	msgbox Route109_SeashoreHouse_Text_2699DF, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_269533:: @ 8269533
	checktrainerflag TRAINER_DWAYNE
	goto_if_lt Route109_SeashoreHouse_EventScript_269553
	checktrainerflag TRAINER_JOHANNA
	goto_if_lt Route109_SeashoreHouse_EventScript_269553
	checktrainerflag TRAINER_SIMON
	goto_if_lt Route109_SeashoreHouse_EventScript_269553
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_269553:: @ 8269553
	release
	end

Route109_SeashoreHouse_Text_269555: @ 8269555
	.string "I'm the owner of the SEASHORE HOUSE.\n"
	.string "But you can call me MR. SEA!\p"
	.string "What I love above all is to see hot\n"
	.string "POKéMON battles.\p"
	.string "Let me see that your heart burns hot!\p"
	.string "If you can defeat all the TRAINERS\n"
	.string "here, I'll reward your efforts.$"

Route109_SeashoreHouse_Text_269635: @ 8269635
	.string "Show me some hot matches!\p"
	.string "I run this SEASHORE HOUSE just for\n"
	.string "that reason alone!$"

Route109_SeashoreHouse_Text_269685: @ 8269685
	.string "You're scorching hot!\n"
	.string "Those battles blazed!\l"
	.string "I'm more than just satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's half a dozen bottles of SODA POP!$"

Route109_SeashoreHouse_Text_26973A: @ 826973A
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_26977E: @ 826977E
	.string "Want to buy some SODA POP?\n"
	.string "POKéMON love it!\p"
	.string "Just ¥300 a bottle!\n"
	.string "Buy some!$"

Route109_SeashoreHouse_Text_2697C8: @ 82697C8
	.string "Here you go!$"

Route109_SeashoreHouse_Text_2697D5: @ 82697D5
	.string "You don't have the money.$"

Route109_SeashoreHouse_Text_2697EF: @ 82697EF
	.string "No?\n"
	.string "That's too bad.$"

Route109_SeashoreHouse_Text_269803: @ 8269803
	.string "If you're looking for a battle in the\n"
	.string "SEASHORE HOUSE, you'll find no\l"
	.string "hotter TRAINER than me, matey!$"

Route109_SeashoreHouse_Text_269867: @ 8269867
	.string "That was a hot battle!\n"
	.string "I can accept that loss, matey!$"

Route109_SeashoreHouse_Text_26989D: @ 826989D
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
	.string "hot battles and ice-cold SODA POP!$"

Route109_SeashoreHouse_Text_2698E3: @ 82698E3
	.string "Boring battles aren't worth the effort.\p"
	.string "Fiery hot battles are what toughen up\n"
	.string "TRAINERS and POKéMON!$"

Route109_SeashoreHouse_Text_269947: @ 8269947
	.string "That's hot!$"

Route109_SeashoreHouse_Text_269953: @ 8269953
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a SODA POP.$"

Route109_SeashoreHouse_Text_269986: @ 8269986
	.string "I'm going to show you how great\n"
	.string "my POKéMON are, but don't cry!$"

Route109_SeashoreHouse_Text_2699C5: @ 82699C5
	.string "…I lost, but I won't cry…$"

Route109_SeashoreHouse_Text_2699DF: @ 82699DF
	.string "If one of my POKéMON knew the move\n"
	.string "for carrying me across water on its\l"
	.string "back, I could get rid of this inner tube.$"

