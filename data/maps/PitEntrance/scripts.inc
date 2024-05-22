PitEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_Entrance
	.byte 0

PitArena_Entrance:
	goto_if_set FLAG_PIT_STARTED, PitArena_EntranceEnd
	callnative SetDefaultOptions
	setvar VAR_PIT_FLOOR, 0
	setflag FLAG_PIT_STARTED
	setflag	FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setflashlevel 0
PitArena_EntranceEnd:
	return

PitEntrance_Warp::
	lockall
	setflag FLAG_PIT_ENTERED
	setvar VAR_PIT_FLOOR, 1
	setvar VAR_REWARD_STATE, 0
	setflag FLAG_EXP_SHARE
	callnative BufferMapFloorString
	callnative SetRandomTrainers
	additem ITEM_SACRED_ASH, 1
	additem ITEM_POTION, 5
	additem ITEM_SUPER_POTION, 2
	additem ITEM_FULL_RESTORE, 1
	additem ITEM_REVIVE, 2
	additem ITEM_FULL_HEAL, 3
	additem ITEM_ETHER, 2
	additem ITEM_ELIXIR, 1
	additem ITEM_ESCAPE_ROPE, 1
#ifndef RANDOM_GEN_5_MODE
	additem ITEM_MEGA_RING, 1
	additem ITEM_Z_POWER_RING, 1
#endif
	additem ITEM_EXP_SHARE, 1
	setflag FLAG_SYS_POKEMON_GET
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	releaseall
	end

PitEntrance_Sign_Luck:
	.string "Good Luck...$"

PitEntrance_ModeMenu:
	.string "Please choose your game mode.$"

PitEntrance_ReadyToStart:
	.string "Are you ready to start?$"

PitEntrance_MsgYes:
	.string "Let's go!$"

PitEntrance_MsgModeMenu:
	.string "Change game mode again!$"

PitEntrance_StartBag::
	lockall
	msgbox PitEntrance_ModeMenu, MSGBOX_AUTOCLOSE
	waitmessage
PitEntrace_ModeMenu::
	callnative CallModeMenu
	waitstate
	message PitEntrance_ReadyToStart
	dynmultichoice 17, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, PitEntrance_MsgYes, PitEntrance_MsgModeMenu
	closemessage
	goto_if_eq VAR_RESULT, 0, PitEntrance_StartBagContinue3
	goto_if_eq VAR_RESULT, 1, PitEntrace_ModeMenu
PitEntrance_StartBagContinue3::
	setflag FLAG_CASE_STARTER_MODE
	callnative InitTrainerIdAndNameData
	callnative StartNewPokeballCaseUI
   	waitstate
	clearflag FLAG_CASE_STARTER_MODE
	removeobject 1
	setflag FLAG_STARTER_CHOICE_BAG

	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, PitEntrance_EndGameStatue1
	call_if_eq VAR_RESULT, DIR_SOUTH, PitEntrance_EndGameStatue2
	call_if_eq VAR_RESULT, DIR_WEST, PitEntrance_EndGameStatue4
	call_if_eq VAR_RESULT, DIR_EAST, PitEntrance_EndGameStatue3

	msgbox PitEntrance_Sign_Luck, MSGBOX_DEFAULT
	goto PitEntrance_Warp

	releaseall
	end

PitEntrance_EndGameStatue1::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerNorthMovement2
	waitmovement 0
	return

PitEntrance_EndGameStatue2::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerSouthMovement2
	waitmovement 0
	return

PitEntrance_EndGameStatue3::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWestMovement2
	waitmovement 0
	return

PitEntrance_EndGameStatue4::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerEastMovement2
	waitmovement 0
	return

PlayerWestMovement2:
	walk_right
	face_down
	step_end

PlayerEastMovement2:
	walk_left
	face_down
	step_end

PlayerNorthMovement2:
	walk_up
	face_down
	step_end

PlayerSouthMovement2:
	walk_down
	face_down
	step_end

PitEntrance_EventScript_Sign::
	lockall
	msgbox PitEntrance_Text_Rules, MSGBOX_DEFAULT
PitEntrance_EventScript_Sign_Hook::
	message PitEntrance_Sign_Text
	dynmultichoice 17, 0, 0, 6, VAR_TEMP_9, DYN_MULTICHOICE_CB_NONE, PitEntrance_Sign_Option0, PitEntrance_Sign_Option1, PitEntrance_Sign_Option2, PitEntrance_Sign_Option3, PitEntrance_Sign_Option4, PitEntrance_Sign_Option5
	closemessage
	copyvar VAR_TEMP_9, VAR_RESULT
	goto_if_eq VAR_RESULT, 0, PitEntrance_MoreInfo
	goto_if_eq VAR_RESULT, 1, PitEntrance_BattleInfo
	goto_if_eq VAR_RESULT, 2, PitEntrance_Credits
	goto_if_eq VAR_RESULT, 3, PitEntrance_Cheats
	goto_if_eq VAR_RESULT, 4, PitEntrance_Bugs
	goto_if_eq VAR_RESULT, 5, PitEntrance_Discord
	release
	end

PitEntrance_MoreInfo:
	msgbox PitEntrance_Text_MoreInfo, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_BattleInfo:
	msgbox PitEntrance_Text_BattleInfo, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_Credits:
	msgbox PitEntrance_Text_Credits, MSGBOX_DEFAULT
	msgbox PitEntrance_Text_Credits2, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_Cheats:
	msgbox PitEntrance_Text_Cheats, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_Bugs:
	msgbox PitEntrance_Text_Bugs, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_Discord:
	msgbox PitEntrance_Text_Discord, MSGBOX_DEFAULT
	goto PitEntrance_EventScript_Sign_Hook
	release
	end 

PitEntrance_Sign_Text:
	.string "Would you like more information?$"

PitEntrance_Sign_Option0:
	.string "More Info$"
PitEntrance_Sign_Option1:
	.string "BattleInfo$"
PitEntrance_Sign_Option2:
	.string "Credits$"
PitEntrance_Sign_Option3:
	.string "Cheats$"
PitEntrance_Sign_Option4:
	.string "Bugs$"
PitEntrance_Sign_Option5:
	.string "Discord$"


PitEntrance_Text_MoreInfo::
	.string "In this challenge you start with 3\n"
	.string "random Pokemon and must fight around\l"
	.string "200 trainers in a random gauntlet.\p"
	.string "You and each trainer have random mons.\n"
	.string "Trainer mon levels are tied to the\l"
	.string "floor number, with 5/100 being min/max.\p"
	.string "Trainer numbers are also randomized\p"
	.string "ranging from 1 to 4 with generally less\p"
	.string "opponents in the lower floors.\p"
	.string "After clearing each floor you will \n"
	.string "get 1-3 random item drops and then\l"
	.string "the next floor warp will activate.\p"
	.string "Every 5th floor is a Heal/Shop floor\n"
	.string "where you will be able to rest and\l"
	.string "prepare for the next Trial.\p"
	.string "Every 25th floor, you will recieve\n"
	.string "another random Mon.\p"
	.string "And every 20th floor there will be\n"
	.string "a free of charge Move Relearner.\p"
	.string "If you do manage to beat the final\n"
	.string "trainer on Floor 100, you can choose\l"
	.string "to keep going and see how far you can get.\p"
	.string "Thats all the info I've got.\n"
	.string "Hopefully you have fun.$"

PitEntrance_Text_BattleInfo::
	.string "This hack is built on a base called the\n"
	.string "pokeemerald-expansion. By default most\l"
	.string "most later Gen mechanics are in the game\p"
	.string "Depending on the version you chose that\n"
	.string "means things like Megas and late Gen\l"
	.string "Pokemon exist.\p"
	.string "I'm not even really aware of it all as\n"
	.string "I haven't played all the later games.\p"
	.string "If you have specific question you can\n"
	.string "check the Expansion Github to see what\l"
	.string "changes they have made.$"

PitEntrance_Text_Credits::
	.string "I, Archie from Team Aquas Hideout, have\n"
	.string "put together this romhack.\p"
	.string "All battle / late Gen stuff / plenty\n"
	.string "more is from the Expansion Team at RHH.\l"
	.string "they do amazing work.\p"
	.string "The decomps themselves were created by \n"
	.string "people at pret.\p"
	.string "Nico made the Battle UI.\n"
	.string "RavePossum implemented the Gen 5\l"
	.string "Summary Screen and the battle bg.\p"
	.string "Ghoulslash made the Item Desc Code +\n"
	.string "the UI shell code used for my UIs\p"
	.string "Mudskip and I together made the \n"
	.string "Main + Start Menu / Pokeball Case UIs\l"
	.string "(Mudskip made the graphics)\p"
	.string "Jaizu made the graphics for the \n"
	.string "Stat Editor (code by me)\p"
	.string "wiz1989 helped out implementing\n"
	.string "balancing changes after v1.3$"

PitEntrance_Text_Credits2::
	.string "Hyo/Poffin made the FRLG style sprites.\n"
	.string "Nicolavs gave me the cave tiles.\l"
	.string "Bsbob made the map pop-up branch.\p"
	.string "TheXaman wrote some of the randomizer\n"
	.string "and Party Menu code (graphics by me).\p"
	.string "Devolov/Rioluwott/EliteRedux/Graion\n"
	.string "for various QOL additions, mostly\l"
	.string "battle related.\p"
	.string "Special thanks to everyone in our \n"
	.string "Team Aqua Discord. There are too many\l"
	.string "people to thank here, but this hack is\l"
	.string "built on community resources.\p"
	.string "Without all of them this hack would \n"
	.string "not exist. Thank you all <3$"

PitEntrance_Text_Bugs::
	.string "If you have any Battle related bugs you\n"
	.string "can report them on the GitHub for the\l"
	.string "pokeemerald-expansion as I have not\l"
	.string "changed any Battle Code myself.\p"
	.string "Other bugs can be reported in the\n"
	.string "Team Aquas Hideout Discord Server.$"

PitEntrance_Text_Cheats::
	.string "You can enable the Expansion debug\n"
	.string "menu by pressing R and Start at same\l"
	.string "time after entering the pit. \p"
	.string "These features can break the game\n"
	.string "so don't report bugs if using it.$"



PitEntrance_Text_Rules::
	.string "Welcome to the Pit of 100 Trials!\n"
	.string "Beyond this point is a neverending\l"
	.string "series of rooms filled with opponents.\p"
	.string "Can you survive even 100 floors?$"

PitEntrance_Text_Discord:
	.string "To talk about the hack join the TAH\n"
	.string "Discord: https://discord.gg/hX3a63RYzZ$"
