LittlerootTown_MaysHouse_1F_MapScripts:: 
	map_script 3, YamakiTown_PlayerHouse_MapScript2
	map_script 2, YamakiTown_PlayerHouse_MapScript1
	.byte 0

YamakiTown_PlayerHouse_MapScript1:
	map_script_2 VAR_0x408C, 4, YamakiTown_PlayerHouse_EndOfDay
	map_script_2 VAR_0x408C, 1, YamakiTown_PlayerHouse_MomIntro
	.2byte 0
	
YamakiTown_PlayerHouse_MapScript2:
	compare VAR_0x408C, 4
	call_if_eq YamakiTown_PlayerHouse_SisterPositionAtTable
	end
	
YamakiTown_PlayerHouse_SisterPositionAtTable::
	setobjectxyperm 2, 8, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return
	
YamakiTown_PlayerHouse_MomIntro::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouse_Movement_WalkToTable
	waitmovement 0
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceDown
	waitmovement 0
	msgbox YamakiTown_PlayerHouse_MomIntro_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_PlayerHouse_Movement_FaceRight
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
	faceplayer
	release
	end
	
YamakiTown_PlayerHouse_MomScript::
	lock
	faceplayer
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
	
YamakiTown_PlayerHouse_Movement_ExcMark:
	emote_exclamation_mark
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
	
YamakiTown_PlayerHouse_Movement_WalkToTable:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
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
	.string "Mom: Morning, honey.\n"
	.string "Did {COLOR POKEMON_COLOR}Farfetch'd{COLOR NO_COLOR} come by today?\p"
	.string "No? Oh, I'm sorry.\n"
	.string "I'm sure they'll respond to you soon!\p"
	.string "By the way, Fan Zheng came by,\n"
	.string "asking for you. He says he found\l"
	.string "something he wants to show you.\p"
	.string "Before you go out, can you wake\n"
	.string "up your sister for me?\p"
	.string "She's still asleep, and I need her\n"
	.string "help feeding the Ponyta today.$"
	
YamakiTown_PlayerHouse_Roadblock_Text:
	.string "Did you wake up your sister yet?$"
	
YamakiTown_PlayerHouse_SisterIntro_Text1:
	.string "Sister: Uuuugghhh...\n"
	.string "Alright, I'm coming.$"

YamakiTown_PlayerHouse_SisterIntro_Text2:
	.string "Good morning, {PLAYER}.$"
	
YamakiTown_PlayerHouse_SisterIntro_Text3:
	.string "Mom: I'll have breakfast ready\n"
	.string "when you're done. Be careful!$"
	
YamakiTown_PlayerHouse_SisterIntro_Text4:
	.string "Sister: What, {PLAYER} is going\n"
	.string "out? I want to go too!$"
	
YamakiTown_PlayerHouse_SisterIntro_Text5:
	.string "Mom: Well, alright.$"

YamakiTown_PlayerHouse_SisterIntro_Text6:
	.string "{PLAYER}, do you mind taking\n"
	.string "her with you?\p"
	.string "I'm sure Fan Zheng wouldn't\n"
	.string "mind having her along.$"
	
YamakiTown_PlayerHouse_EndOfDay_Text1:
	.string "Mom: {PLAYER}! It's so late! I\n"
	.string "hope it was at least worthwhile.\p"
	.string "Sister has been complaining\n"
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

