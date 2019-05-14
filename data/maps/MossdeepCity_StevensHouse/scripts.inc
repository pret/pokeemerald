MossdeepCity_StevensHouse_MapScripts:: @ 8222784
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_MapScript1_222794
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_MapScript2_2227C0
	.byte 0

MossdeepCity_StevensHouse_MapScript1_222794: @ 8222794
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_22279E
	end

MossdeepCity_StevensHouse_EventScript_22279E:: @ 822279E
	setmetatile 6, 4, 753, 1
	return

MossdeepCity_StevensHouse_OnTransition: @ 82227A8
	compare VAR_STEVENS_HOUSE_STATE, 2
	call_if_eq MossdeepCity_StevensHouse_EventScript_2227B4
	end

MossdeepCity_StevensHouse_EventScript_2227B4:: @ 82227B4
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_MapScript2_2227C0: @ 82227C0
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_2227CA
	.2byte 0

MossdeepCity_StevensHouse_EventScript_2227CA:: @ 82227CA
	lockall
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, MossdeepCity_StevensHouse_Movement_222833
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_222936, MSGBOX_DEFAULT
	giveitem_std ITEM_HM08
	setflag FLAG_RECEIVED_HM08
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_222A0E, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 1, MossdeepCity_StevensHouse_Movement_22283B
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_222833: @ 8222833
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MossdeepCity_StevensHouse_Movement_22283B: @ 822283B
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MossdeepCity_StevensHouse_EventScript_222841:: @ 8222841
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222B9E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_22285B
	goto MossdeepCity_StevensHouse_EventScript_222865
	end

MossdeepCity_StevensHouse_EventScript_22285B:: @ 822285B
	msgbox MossdeepCity_StevensHouse_Text_222C2A, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222865:: @ 8222865
	setvar VAR_TEMP_1, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5, ITEM_NONE, 0x0, 0x0, 0
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_222895
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_StevensHouse_EventScript_2228BD
	goto MossdeepCity_StevensHouse_EventScript_273811
	end

MossdeepCity_StevensHouse_EventScript_222895:: @ 8222895
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_222901
	call MossdeepCity_StevensHouse_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto MossdeepCity_StevensHouse_EventScript_222901
	end

MossdeepCity_StevensHouse_EventScript_2228BD:: @ 82228BD
	call MossdeepCity_StevensHouse_EventScript_2228EB
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_2228E0
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
	playfanfare MUS_FANFA4
	message MossdeepCity_StevensHouse_Text_222BED
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_222901:: @ 8222901
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222909:: @ 8222909
	msgbox MossdeepCity_StevensHouse_Text_222D97, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_222912:: @ 8222912
	msgbox MossdeepCity_StevensHouse_Text_222B11, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_22291B:: @ 822291B
	lockall
	msgbox MossdeepCity_StevensHouse_Text_222C4E, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_222926:: @ 8222926
	giveitem_std ITEM_HM08, 1, 1
	setflag FLAG_RECEIVED_HM08
	end

MossdeepCity_StevensHouse_Text_222936: @ 8222936
	.string "STEVEN: {PLAYER}{KUN}…\p"
	.string "As you can see, there's not much here,\n"
	.string "but this is my home.\p"
	.string "Thank you for all that you've done.\p"
	.string "This is my token of appreciation.\n"
	.string "It's the HIDDEN MACHINE DIVE.\p"
	.string "No need to be shy--you've earned\n"
	.string "this HM.$"

MossdeepCity_StevensHouse_Text_222A0E: @ 8222A0E
	.string "STEVEN: While you're using SURF, you\n"
	.string "should notice dark patches of water.\p"
	.string "Use DIVE if you come to deep water\n"
	.string "like it. You'll drop to the seafloor.\p"
	.string "When you want to come back up, use\n"
	.string "DIVE again.\p"
	.string "In some places, it won't be possible\n"
	.string "for you to surface, though.$"

MossdeepCity_StevensHouse_Text_222B11: @ 8222B11
	.string "STEVEN: Apparently, there's an\n"
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
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the POKé BALL on\n"
	.string "the desk.\p"
	.string "Inside it is a BELDUM, my favorite\n"
	.string "POKéMON.\p"
	.string "I'm counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "STEVEN STONE$"

MossdeepCity_StevensHouse_Text_222D97: @ 8222D97
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by STEVEN.$"

