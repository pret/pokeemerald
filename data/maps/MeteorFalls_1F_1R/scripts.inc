MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_MapScript1_22BD30
	.byte 0

MeteorFalls_1F_1R_MapScript1_22BD30: @ 822BD30
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_22BD3A
	end

MeteorFalls_1F_1R_EventScript_22BD3A:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_22BD5F:: @ 822BD5F
	lockall
	playbgm MUS_MGM0, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 5, MeteorFalls_1F_1R_Movement_2725B4
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BF47, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceUp
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BF84, MSGBOX_DEFAULT
	closemessage
	applymovement 5, MeteorFalls_1F_1R_Movement_22BEC0
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22BFE4, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement 5, Common_Movement_WalkInPlaceLeft
	applymovement 6, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	addobject 7
	addobject 8
	addobject 9
	playbgm MUS_AQA_0, 0
	applymovement 7, MeteorFalls_1F_1R_Movement_22BED9
	applymovement 8, MeteorFalls_1F_1R_Movement_22BEE0
	applymovement 9, MeteorFalls_1F_1R_Movement_22BEE8
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceLeft
	applymovement 6, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C04E, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_22BF1D
	applymovement 5, MeteorFalls_1F_1R_Movement_22BEC4
	applymovement 6, MeteorFalls_1F_1R_Movement_22BECE
	waitmovement 0
	removeobject 5
	removeobject 6
	applymovement 7, MeteorFalls_1F_1R_Movement_22BEF8
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C11C, MSGBOX_DEFAULT
	closemessage
	applymovement 8, MeteorFalls_1F_1R_Movement_22BF08
	applymovement 9, MeteorFalls_1F_1R_Movement_22BF18
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C268, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C292, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_22C2FC, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MeteorFalls_1F_1R_Movement_22BEF0
	applymovement 8, MeteorFalls_1F_1R_Movement_22BEFE
	applymovement 9, MeteorFalls_1F_1R_Movement_22BF0D
	waitmovement 0
	fadedefaultbgm
	removeobject 7
	removeobject 8
	removeobject 9
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_22BEC0: @ 822BEC0
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BEC4: @ 822BEC4
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_22BECE: @ 822BECE
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_22BED9: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEE0: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEE8: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEF0: @ 822BEF0
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BEF8: @ 822BEF8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

MeteorFalls_1F_1R_Movement_22BEFE: @ 822BEFE
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BF08: @ 822BF08
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BF0D: @ 822BF0D
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_22BF18: @ 822BF18
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_22BF1D: @ 822BF1D
	walk_in_place_fastest_down
	delay_4
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_22BF25:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COSMO, MeteorFalls_1F_1R_EventScript_22BF3D
	setflag FLAG_MET_PROF_COSMO
	msgbox MeteorFalls_1F_1R_Text_22C342, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_22BF3D:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_22C47D, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_22BF47: @ 822BF47
	.string "Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"

MeteorFalls_1F_1R_Text_22BF84: @ 822BF84
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_22BFE4: @ 822BFE4
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_22C04E: @ 822C04E
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_22C11C: @ 822C11C
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"

MeteorFalls_1F_1R_Text_22C268: @ 822C268
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_22C292: @ 822C292
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"

MeteorFalls_1F_1R_Text_22C2FC: @ 822C2FC
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_22C342: @ 822C342
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_22C47D: @ 822C47D
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"
