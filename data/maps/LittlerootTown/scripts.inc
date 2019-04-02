LittlerootTown_MapScripts::
	map_script 3, YamakiTown_MapScript1
	map_script 2, YamakiTown_MapScript2
	.byte 0

YamakiTown_MapScript1:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	compare VAR_0x408C, 4
	call_if_le YamakiTown_EventScript_OldManPosition
	end

YamakiTown_EventScript_OldManPosition::
	setobjectxyperm 1, 24, 14
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

YamakiTown_MapScript2:
	map_script_2 VAR_0x408C, 0, YamakiTown_EventScript_CameraIntro
	map_script_2 VAR_0x408C, 3, YamakiTown_EventScript_FanZhengIntro
	.2byte 0
	
YamakiTown_EventScript_CameraIntro::
	lock
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN //used for Fan Zheng appearance in Yamaki Town jsyk guys
	removeobject 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK //used for Sister appearance in Yamaki Town jsyk guys
	removeobject 4
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_MapScript2_CameraMovements
	waitmovement 0
	setvar VAR_0x408C, 1
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 3, 5
	waitstate
	end
	
YamakiTown_MapScript2_CameraMovements:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

YamakiTown_HealingShrine::
	goto_if_set FLAG_SYS_POKEMON_GET, YamakiTown_HealingShrineActivated
	msgbox YamakiTown_HealingShrine_Text1, MSGBOX_DEFAULT
	closemessage
	end
	
YamakiTown_HealingShrineActivated::
	msgbox YamakiTown_HealingShrine_Text1, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	msgbox YamakiTown_HealingShrine_Text2, MSGBOX_DEFAULT
	closemessage
	end

YamakiTown_HealingShrine_Text1:
	.string "The sound of the waves fills you\n"
	.string "with determination.$"
	
YamakiTown_HealingShrine_Text2:
	.string "Your Pokémon were fully healed!$"
	
YamakiTown_EventScript_FanZhengIntro::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_StepDown
	waitmovement 0
	opendoor 16, 18
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	addobject 4
	applymovement 4, YamakiTown_Movement_StepDown
	waitmovement 0
	closedoor 16, 18
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_FaceRight
	waitmovement 0
	applymovement 4, YamakiTown_Movement_SisterApproachesFanZheng
	waitmovement 0
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FaceUp
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text2, MSGBOX_DEFAULT
	closemessage
	applymovement 4, YamakiTown_Movement_StepDownOnSpot
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text3, MSGBOX_DEFAULT
	closemessage
	applymovement 4, YamakiTown_Movement_SisterGoesInside
	waitmovement 0
	opendoor 16, 18
	waitdooranim	
	applymovement 4, YamakiTown_Movement_StepUp
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	removeobject 4
	closedoor 16, 18
	waitdooranim
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text4, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_WalkingToShrine
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_WalkingToShrine
	waitmovement 0
	applymovement 1, YamakiTown_Movement_FaceDown
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text5, MSGBOX_DEFAULT
	closemessage
	msgbox YamakiTown_FanZhengIntro_Text6, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_FaceRight
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text7, MSGBOX_DEFAULT
	closemessage
	msgbox YamakiTown_FanZhengIntro_Text8, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_FaceUp
	applymovement 3, YamakiTown_Movement_FaceUp
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text9, MSGBOX_DEFAULT
	closemessage
	msgbox YamakiTown_FanZhengIntro_Text10, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_FaceRight
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text11, MSGBOX_DEFAULT
	closemessage
	applymovement 1, YamakiTown_Movement_FaceUp
	waitmovement 0
	applymovement 3, YamakiTown_Movement_WalkingToEggs
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_WalkingToEggs
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text12, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_Movement_FaceRight
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text13, MSGBOX_DEFAULT
	closemessage
	special ChooseStarter
	waitstate
	bufferleadmonspeciesname 0
	msgbox YamakiTown_FanZhengIntro_Text14, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FaceUp
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text15, MSGBOX_DEFAULT
	closemessage
	removeobject 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	applymovement 3, YamakiTown_Movement_FaceLeft
	waitmovement 0
	msgbox YamakiTown_FanZhengIntro_Text16, MSGBOX_DEFAULT
	closemessage
	applymovement 3, YamakiTown_Movement_FanZhengLeaves
	waitmovement 0
	removeobject 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setvar VAR_0x408C, 4
	release
	end
	
YamakiTown_Movement_StepDown:
	walk_down
	step_end
	
YamakiTown_Movement_FaceRight:
	face_right
	step_end
	
YamakiTown_Movement_FaceUp:
	face_up
	step_end
	
YamakiTown_Movement_FaceDown:
	face_down
	step_end
	
YamakiTown_Movement_FaceLeft:
	face_left
	step_end
	
YamakiTown_Movement_SisterApproachesFanZheng:
	walk_right
	face_down
	step_end
	
YamakiTown_Movement_SisterGoesInside:
	walk_left
	face_up
	step_end
	
YamakiTown_Movement_StepUp:
	walk_up
	step_end
	
YamakiTown_Movement_StepDownOnSpot:
	walk_in_place_fast_down
	step_end
	
YamakiTown_Movement_WalkingToShrine:
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
YamakiTown_Movement_WalkingToEggs:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end
	
YamakiTown_Movement_FanZhengLeaves:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

YamakiTown_FanZhengIntro_Text1:
	.string "Fan Zheng: Wow {PLAYER}, take\n"
	.string "your time why don't you!\p"
	.string "Not only that, but I don't\n"
	.string "remember asking for... erm...$"
	
YamakiTown_FanZhengIntro_Text2:
	.string "What's your name again?$"
	
YamakiTown_FanZhengIntro_Text3:
	.string "Sister: Sniff...\n"
	.string "It's Sister!$"

YamakiTown_FanZhengIntro_Text4:
	.string "Fan Zheng: I was only asking\n"
	.string "her name...\p"
	.string "Well anyway, {PLAYER}, I saw\n"
	.string "something crazy by the lake today\l"
	.string "and I had to show you before\l"
	.string "anyone else finds out.\p"
	.string "Come on, follow me and don't\n"
	.string "goof around!$"
	
YamakiTown_FanZhengIntro_Text5:
	.string "Old Man: With the way you're\n"
	.string "running around, kid, you'd\l"
	.string "think there was no tomorrow.$"
	
YamakiTown_FanZhengIntro_Text6:
	.string "Fan Zheng: Right now it could\n"
	.string "be if I don't get to the lake\l"
	.string "quick!$"

YamakiTown_FanZhengIntro_Text7:
	.string "Come on {PLAYER}, hurry up!$"
	
YamakiTown_FanZhengIntro_Text8:
	.string "Old Man: Off to see what\n"
	.string "happened at the lake by any\l"
	.string "chance?$"
	
YamakiTown_FanZhengIntro_Text9:
	.string "Fan Zheng: How did y-$"
	
YamakiTown_FanZhengIntro_Text10:
	.string "Old Man: Call it old man's\n"
	.string "intuition.\p"
	.string "You've come up this far and\n"
	.string "haven't yet arrived where you\l"
	.string "want to, there's only one place\l"
	.string "place to go after this…$"
	
YamakiTown_FanZhengIntro_Text11:
	.string "Fan Zheng: Whatever, we've\n"
	.string "wasted too much time here.$"
	
YamakiTown_FanZhengIntro_Text12:
	.string "Fan Zheng: See?! Look at these,\n"
	.string "pretty neat right?\p"
	.string "I can't wait to take it home and\n"
	.string "see what it is...\p"
	.string "Hey {PLAYER}, what do you think\n"
	.string "could be in these?$"
	
YamakiTown_FanZhengIntro_Text13:
	.string "Pokémon Eggs? Imagine it!\n"
	.string "We'd have our own Pokémon!\p"
	.string "If you think you're so smart\n"
	.string "that it's a Pokémon Egg then,\l"
	.string "which Pokémon do you think\l"
	.string "they are?$"
	
YamakiTown_FanZhengIntro_Text14:
	.string "Wow, {STR_VAR_1} you say?$"
	
YamakiTown_FanZhengIntro_Text15:
	.string "Well in that case I'll pick this\n"
	.string "one.$"
	
YamakiTown_FanZhengIntro_Text16:
	.string "Hey {PLAYER}, why don't you take\n"
	.string "the other one back for Sister?\p"
	.string "Think of it as an apology from\n"
	.string "me for making her run off\l"
	.string "earlier.\p"
	.string "Well, I'm going straight home\n"
	.string "and getting this Egg safely\l"
	.string "stowed away, let's hope they do\l"
	.string "hatch, {PLAYER}!\p"
	.string "I'll see you tomorrow. Say sorry\n"
	.string "to Sister for me, laters!$"
