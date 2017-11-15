MossdeepCity_StevensHouse_MapScripts:: @ 8222784
	map_script 1, MossdeepCity_StevensHouse_MapScript1_222794
	map_script 3, MossdeepCity_StevensHouse_MapScript1_2227A8
	map_script 2, MossdeepCity_StevensHouse_MapScript2_2227C0
	.byte 0

MossdeepCity_StevensHouse_MapScript1_222794: @ 8222794
	checkflag FLAG_SYS_GAME_CLEAR
	call_if 0, MossdeepCity_StevensHouse_EventScript_22279E
	end

MossdeepCity_StevensHouse_EventScript_22279E:: @ 822279E
	setmetatile 6, 4, 753, 1
	return

MossdeepCity_StevensHouse_MapScript1_2227A8: @ 82227A8
	compare_var_to_value VAR_0x40C6, 2
	call_if 1, MossdeepCity_StevensHouse_EventScript_2227B4
	end

MossdeepCity_StevensHouse_EventScript_2227B4:: @ 82227B4
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, 7
	return

MossdeepCity_StevensHouse_MapScript2_2227C0: @ 82227C0
	map_script_2 VAR_0x40C6, 1, MossdeepCity_StevensHouse_EventScript_2227CA
	.2byte 0

MossdeepCity_StevensHouse_EventScript_2227CA:: @ 82227CA
	lockall
	applymovement 1, MossdeepCity_StevensHouse_Movement_2725A4
	waitmovement 0
	playse SE_PIN
	applymovement 1, MossdeepCity_StevensHouse_Movement_272598
	waitmovement 0
	applymovement 1, MossdeepCity_StevensHouse_Movement_27259A
	waitmovement 0
	applymovement 1, MossdeepCity_StevensHouse_Movement_222833
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_222936, 4
	giveitem_std ITEM_HM08
	setflag FLAG_0x07B
	setflag FLAG_0x12E
	msgbox MossdeepCity_StevensHouse_Text_222A0E, 4
	closemessage
	delay 20
	applymovement 1, MossdeepCity_StevensHouse_Movement_22283B
	waitmovement 0
	setflag FLAG_0x314
	setflag FLAG_0x3AD
	setvar VAR_0x40C6, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_222833: @ 8222833
	step_left
	step_left
	step_left
	step_left
	step_left
	step_left
	step_25
	step_end

MossdeepCity_StevensHouse_Movement_22283B: @ 822283B
	step_up
	step_right
	step_right
	step_right
	step_26
	step_end

MossdeepCity_StevensHouse_EventScript_222841:: @ 8222841
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222B9E, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_StevensHouse_EventScript_22285B
	goto MossdeepCity_StevensHouse_EventScript_222865
	end

MossdeepCity_StevensHouse_EventScript_22285B:: @ 822285B
	msgbox MossdeepCity_StevensHouse_Text_222C2A, 4
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222865:: @ 8222865
	setvar VAR_0x4001, 398
	givemon SPECIES_BELDUM, 5, ITEM_NONE, 0x0, 0x0, 0
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_StevensHouse_EventScript_222895
	compare_var_to_value VAR_RESULT, 1
	goto_eq MossdeepCity_StevensHouse_EventScript_2228BD
	goto MossdeepCity_StevensHouse_EventScript_273811
	end

MossdeepCity_StevensHouse_EventScript_222895:: @ 8222895
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_StevensHouse_EventScript_222901
	call MossdeepCity_StevensHouse_EventScript_27378B
	call MossdeepCity_StevensHouse_EventScript_2723DD
	goto MossdeepCity_StevensHouse_EventScript_222901
	end

MossdeepCity_StevensHouse_EventScript_2228BD:: @ 82228BD
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gUnknown_08273374, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_StevensHouse_EventScript_2228E0
	call MossdeepCity_StevensHouse_EventScript_273797
	goto MossdeepCity_StevensHouse_EventScript_2228E0
	end

MossdeepCity_StevensHouse_EventScript_2228E0:: @ 82228E0
	call MossdeepCity_StevensHouse_EventScript_2737A0
	goto MossdeepCity_StevensHouse_EventScript_222901
	end

MossdeepCity_StevensHouse_EventScript_2228EB:: @ 82228EB
	bufferspeciesname 1, SPECIES_BELDUM
	removeobject 2
	playfanfare BGM_FANFA4
	message MossdeepCity_StevensHouse_Text_222BED
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_222901:: @ 8222901
	setflag FLAG_0x3C8
	setflag FLAG_0x12A
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222909:: @ 8222909
	msgbox MossdeepCity_StevensHouse_Text_222D97, 3
	end

MossdeepCity_StevensHouse_EventScript_222912:: @ 8222912
	msgbox MossdeepCity_StevensHouse_Text_222B11, 2
	end

MossdeepCity_StevensHouse_EventScript_22291B:: @ 822291B
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222C4E, 4
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222926:: @ 8222926
	giveitem_std ITEM_HM08, 1, 1
	setflag FLAG_0x07B
	end

MossdeepCity_StevensHouse_Text_222936: @ 8222936
	.string "STEVEN: {PLAYER}{KUN}…\p"
	.string "As you can see, there’s not much here,\n"
	.string "but this is my home.\p"
	.string "Thank you for all that you’ve done.\p"
	.string "This is my token of appreciation.\n"
	.string "It’s the HIDDEN MACHINE DIVE.\p"
	.string "No need to be shy--you’ve earned\n"
	.string "this HM.$"

MossdeepCity_StevensHouse_Text_222A0E: @ 8222A0E
	.string "STEVEN: While you’re using SURF, you\n"
	.string "should notice dark patches of water.\p"
	.string "Use DIVE if you come to deep water\n"
	.string "like it. You’ll drop to the seafloor.\p"
	.string "When you want to come back up, use\n"
	.string "DIVE again.\p"
	.string "In some places, it won’t be possible\n"
	.string "for you to surface, though.$"

MossdeepCity_StevensHouse_Text_222B11: @ 8222B11
	.string "STEVEN: Apparently, there’s an\n"
	.string "underwater cavern between\l"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
	.string "You know, the one that CAPT. STERN\n"
	.string "found in his submarine.$"

MossdeepCity_StevensHouse_Text_222B9E: @ 8222B9E
	.string "{PLAYER} checked the POKé BALL.\p"
	.string "It contained the POKéMON\n"
	.string "BELDUM.\p"
	.string "Take the POKé BALL?$"

MossdeepCity_StevensHouse_Text_222BED: @ 8222BED
	.string "{PLAYER} obtained a BELDUM.$"

MossdeepCity_StevensHouse_Text_222C03: @ 8222C03
	.string "There is no space for another POKéMON.$"

MossdeepCity_StevensHouse_Text_222C2A: @ 8222C2A
	.string "{PLAYER} left the POKé BALL where\n"
	.string "it was.$"

MossdeepCity_StevensHouse_Text_222C4E: @ 8222C4E
	.string "It’s a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I’ve decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don’t plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the POKé BALL on\n"
	.string "the desk.\p"
	.string "Inside it is a BELDUM, my favorite\n"
	.string "POKéMON.\p"
	.string "I’m counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "STEVEN STONE$"

MossdeepCity_StevensHouse_Text_222D97: @ 8222D97
	.string "It’s a collection of rare rocks and\n"
	.string "stones assembled by STEVEN.$"

