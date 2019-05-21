LittlerootTown_MaysHouse_1F_MapScripts:: 
	map_script 3, YamakiTown_PlayerHouse_MapScript2
	map_script 2, YamakiTown_PlayerHouse_MapScript1
	.byte 0

YamakiTown_PlayerHouse_MapScript1:
	map_script_2 VAR_0x408C, 6, YamakiTown_PlayerHouse_EggsHatched
	map_script_2 VAR_0x408C, 4, YamakiTown_PlayerHouse_EndOfDay
	map_script_2 VAR_0x408C, 1, YamakiTown_PlayerHouse_MomIntro
	.2byte 0
	
YamakiTown_PlayerHouse_MapScript2:
	compare VAR_0x408C, 6
	call_if_eq YamakiTown_PlayerHouse_SisterStarterChase
	compare VAR_0x408C, 4
	call_if_eq YamakiTown_PlayerHouse_SisterPositionAtTable
	end
	
YamakiTown_PlayerHouse_SisterPositionAtTable::
	setobjectxyperm 2, 8, 6
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return
	
YamakiTown_PlayerHouse_SisterStarterChase::
	setobjectxyperm 2, 2, 5
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return
	
YamakiTown_PlayerHouse_EggsHatched::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_WalkAroundSisAndStarter
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_ExcMark
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EggsHatched_Text1, MSGBOX_DEFAULT
	closemessage
	bufferleadmonspeciesname 0
	playmoncry SPECIES_CHARMANDER, 0
	msgbox YamakiTown_PlayerHouseUpstairs_PlaceholderCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	applymovement 1, YamakiTown_PlayerHouse_Movement_Heart
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EggsHatched_Text2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_2723DD
	closemessage
	setvar VAR_0x408C, 7
	release
	end
	
YamakiTown_PlayerHouse_MomIntro::
	lock
	applymovement 1, YamakiTown_PlayerHouse_Movement_MomNoticePlayer
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_WalkToTable
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceRight
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_MomIntro_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	showobjectat 3, MAP_LITTLEROOT_TOWN
	setvar VAR_0x408C, 2
	release
	end
	
YamakiTown_PlayerHouse_SisterScript::
	lock
	compare VAR_0x408C, 2
	goto_if_eq YamakiTown_PlayerHouse_SisterIntro
	compare VAR_0x408C, 7
	goto_if_eq YamakiTown_PlayerHouse_SisterAfterStarter
	faceplayer
	release
	end
	
YamakiTown_PlayerHouse_SisterAfterStarter::
	faceplayer
	msgbox YamakiTown_PlayerHouse_SisterStarter_Text, MSGBOX_DEFAULT
	closemessage
	release
	end
	
YamakiTown_PlayerHouse_MomScript::
	lock
	faceplayer
	compare VAR_0x408C, 7
	goto_if_eq YamakiTown_PlayerHouse_MomScript_EggsHatched
	release
	end
	
YamakiTown_PlayerHouse_MomScript_EggsHatched::
	msgbox YamakiTown_PlayerHouse_MomScript_EggsHatched_Text, MSGBOX_DEFAULT
	closemessage
	release
	end
	
YamakiTown_PlayerHouse_SisterStarterScript_Deino::
	lock
	faceplayer
	playmoncry SPECIES_BAGON, 0
	msgbox YamakiTown_PlayerHouse_DeinoCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	release
	end
	
YamakiTown_PlayerHouse_SisterStarterScript_Dratini::
	lock
	faceplayer
	playmoncry SPECIES_DRATINI, 0
	msgbox YamakiTown_PlayerHouse_DratiniCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	release
	end
	
YamakiTown_PlayerHouse_SisterStarterScript_Goomy::
	lock
	faceplayer
	playmoncry SPECIES_CHARMANDER, 0
	msgbox YamakiTown_PlayerHouse_GoomyCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	release
	end
	
YamakiTown_PlayerHouse_SisterIntro::
	lock
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text1, MSGBOX_DEFAULT
	closemessage
	faceplayer
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text2, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_MoveAside
	waitmovement 0
	applymovement 2, YamakiTown_PlayerHouse_Movement_SisterWalksToTable
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_TryToLeave
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text3, MSGBOX_DEFAULT
	closemessage	
	applymovement 2, YamakiTown_PlayerHouse_Movement_SisterRunsToMom
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceDown
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text5, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_FaceRight
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_SisterIntro_Text6, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceRight
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x408C, 3
	release
	end
	
YamakiTown_PlayerHouse_Roadblock::
	compare VAR_0x408C, 2
	goto_if_eq YamakiTown_PlayerHouse_RoadblockScript
	end
	
YamakiTown_PlayerHouse_RoadblockScript::
	lockall
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_Roadblock_Text, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_StepUp
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x408C, 2
	releaseall
	end
	
YamakiTown_PlayerHouse_EndOfDay::
	lock
	applymovement 1, YamakiTown_PlayerHouse_Movement_ExcMark
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EndOfDay_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceDown
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_PlayerWalksToTable
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EndOfDay_Text2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, YamakiTown_PlayerHouse_Movement_SisterWalksToTable2
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EndOfDay_Text3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_EndOfDay_Text4, MSGBOX_DEFAULT
	closemessage
	msgbox YamakiTown_PlayerHouse_EndOfDay_Text5, MSGBOX_DEFAULT
	closemessage
	applymovement 2, YamakiTown_PlayerHouse_Movement_SisterGoesUpstairs
	waitmovement 0
	removeobject 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceRight
	waitmovement 0
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_PlayerGoingUpstairs
	waitmovement 0
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 7, 4
	setvar VAR_0x408C, 5
	release
	end
	
YamakiTown_PlayerHouse_Movement_WalkAroundSisAndStarter:
	delay_4
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	face_right
	step_end
	
YamakiTown_PlayerHouse_Movement_ExcMark:
	emote_exclamation_mark
	step_end

YamakiTown_PlayerHouse_Movement_Heart:
	emote_heart
	step_end

YamakiTown_PlayerHouse_Movement_PlayerGoingUpstairs:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YamakiTown_PlayerHouse_Movement_MomNoticePlayer:
	delay_16
	delay_16
	face_right
	delay_16
	emote_exclamation_mark
	delay_16
	step_end
	
YamakiTown_PlayerHouse_Movement_WalkToTable:
	walk_left
	walk_left
	walk_down
	walk_left
	step_end
	
YamakiTown_PlayerHouse_Movement_FaceDown:
	face_down
	step_end
	
YamakiTown_PlayerHouse_Movement_StepUp:
	walk_up
	step_end
	
YamakiTown_PlayerHouse_Movement_FaceUp:
	face_up
	step_end
	
YamakiTown_PlayerHouse_Movement_MoveAside:
	walk_up
	face_down
	step_end
	
YamakiTown_PlayerHouse_Movement_FaceRight:
	face_right
	step_end
	
YamakiTown_PlayerHouse_Movement_SisterWalksToTable:
	walk_left
	walk_left
	walk_up
	face_left
	step_end
	
YamakiTown_PlayerHouse_Movement_SisterWalksToTable2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_right
	step_end
	
YamakiTown_PlayerHouse_Movement_PlayerWalksToTable:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end
	
YamakiTown_PlayerHouse_Movement_FaceLeft:
	face_left
	step_end
	
YamakiTown_PlayerHouse_Movement_TryToLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
	
YamakiTown_PlayerHouse_Movement_SisterRunsToMom:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end
	
YamakiTown_PlayerHouse_Movement_SisterGoesUpstairs:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
YamakiTown_PlayerHouse_MomIntro_Text1:
	.string "{COLOR CHARACTER_COLOR}Mom:{COLOR NO_COLOR} Morning, {COLOR CHARACTER_COLOR}{PLAYER}{COLOR NO_COLOR}!\n"
	.string "Still no reply on your letter, huh?\n"
	.string "I'm sure they'll respond to you soon!\p"
	.string "By the way, {COLOR CHARACTER_COLOR}Fan Zheng{COLOR NO_COLOR} came by,\n"
	.string "asking for you. He says he found\l"
	.string "something he wants to show you.\p"
	.string "Why don't you take your {COLOR CHARACTER_COLOR}Rui{COLOR NO_COLOR} out\n"
	.string "with you? I don't even know the last\l"
	.string "time she went outside...$"
	
YamakiTown_PlayerHouse_Roadblock_Text:
	.string "Did you wake up your sister yet?$"
	
YamakiTown_PlayerHouse_SisterIntro_Text1:
	.string "{COLOR CHARACTER_COLOR}Rui:{COLOR NO_COLOR} Uuuugghhh...\n"
	.string "Alright, I'm coming.$"

YamakiTown_PlayerHouse_SisterIntro_Text2:
	.string "Good morning, {PLAYER}.$"
	
YamakiTown_PlayerHouse_SisterIntro_Text3:
	.string "Mom: I'll have breakfast ready\n"
	.string "when you're done. Be careful!$"
	
YamakiTown_PlayerHouse_SisterIntro_Text4:
	.string "{COLOR CHARACTER_COLOR}Rui:{COLOR NO_COLOR} What, {COLOR CHARACTER_COLOR}{PLAYER}{COLOR NO_COLOR} is going\n"
	.string "out? I want to go too!$"
	
YamakiTown_PlayerHouse_SisterIntro_Text5:
	.string "{COLOR CHARACTER_COLOR}Mom:{COLOR NO_COLOR} Well, alright.$"

YamakiTown_PlayerHouse_SisterIntro_Text6:
	.string "{COLOR CHARACTER_COLOR}{PLAYER}{COLOR NO_COLOR}, do you mind taking\n"
	.string "her with you?\p"
	.string "I'm sure {COLOR CHARACTER_COLOR}Fan Zheng{COLOR NO_COLOR} wouldn't\n"
	.string "mind having her along.$"
	
YamakiTown_PlayerHouse_EndOfDay_Text1:
	.string "Mom: {PLAYER}{COLOR NO_COLOR}! It's so late! I\n"
	.string "hope it was at least worthwhile.\p"
	.string "{COLOR CHARACTER_COLOR}Rui{COLOR NO_COLOR} has been complaining\n"
	.string "all day!$"

YamakiTown_PlayerHouse_EndOfDay_Text2:
	.string "What are these?! Whatever they\n"
	.string "are, I don't like the look of\l"
	.string "them.\p"
	.string "It's getting late now so you can\n"
	.string "keep them tonight, but I want\l"
	.string "them gone by the morning!$"

YamakiTown_PlayerHouse_EndOfDay_Text3:
	.string "Sister: Oh they look amazing!\n"
	.string "I wonder what they will hatch\l"
	.string "into. Can I have one?$"
	
YamakiTown_PlayerHouse_EndOfDay_Text4:
	.string "Mom: N-$"
	
YamakiTown_PlayerHouse_EndOfDay_Text5:
	.string "Sister: Oh, Fan Zheng said this\n"
	.string "was for me? Thanks! You're the\l"
	.string "best, I'm gunna go put this in\l"
	.string "my room straight away!$"
	
YamakiTown_PlayerHouse_GoomyCry:
	.string "{COLOR POKEMON_COLOR}Goomy:{COLOR NO_COLOR} Placeholder cry!$"
	
YamakiTown_PlayerHouse_DeinoCry:
	.string "{COLOR POKEMON_COLOR}Deino:{COLOR NO_COLOR} Placeholder cry!$"
	
YamakiTown_PlayerHouse_DratiniCry:
	.string "{COLOR POKEMON_COLOR}Dratini:{COLOR NO_COLOR} Placeholder cry!$"
	
YamakiTown_PlayerHouse_SisterStarter_Text:
	.string "I LOVE POKéMON! I LOVE POKéMON!\n"
	.string "I LOVE POKéMON! I LOVE POKéMON!$"
	
YamakiTown_PlayerHouse_MomScript_EggsHatched_Text:
	.string "Why don't you go show\n"
	.string "{COLOR POKEMON_COLOR}{STR_VAR_1}{COLOR NO_COLOR} to Fan Zheng?$"
	
YamakiTown_PlayerHouse_EggsHatched_Text1:
	.string "Mom: Oh? Your Egg hatched too?$"
	
YamakiTown_PlayerHouse_EggsHatched_Text2:
	.string "What a cute Pokémon!\n"
	.string "Have you given it a name?$"
