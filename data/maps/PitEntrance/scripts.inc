PitEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_Entrance
	.byte 0

PitArena_Entrance:
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
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	callnative StartTimer1Script
	setflashlevel 0
	return

PitEntrance_Warp::
	lockall
	setflag FLAG_PIT_ENTERED
	setvar VAR_PIT_FLOOR, 1
	callnative BufferMapFloorString
	callnative InitTrainerIdAndNameData
	callnative SetRandomTrainers
	setvar VAR_REWARD_STATE, 0
	setflag FLAG_EXP_SHARE
	givemon SPECIES_MUDKIP, 5
	givemon SPECIES_TREECKO, 5
	givemon SPECIES_TORCHIC, 5
	additem ITEM_POTION, 5
	additem ITEM_SUPER_POTION, 3
	additem ITEM_HYPER_POTION, 1
	additem ITEM_FULL_RESTORE, 1
	additem ITEM_REVIVE, 3
	additem ITEM_MAX_REVIVE, 1
	additem ITEM_FULL_HEAL, 5
	additem ITEM_ETHER, 5
	additem ITEM_ELIXIR, 2
	additem ITEM_ESCAPE_ROPE, 1
	additem ITEM_MEGA_RING, 1
	additem ITEM_Z_POWER_RING, 1
	additem ITEM_EXP_SHARE, 1
	setflag FLAG_SYS_POKEMON_GET
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	releaseall
	end

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


PitEntrance_Text_Rules:
	.string "Welcome to the Pit of 100 Trials!\n"
	.string "Beyond this point is a neverending -\p"
	.string "series of rooms filled with opponents.\n"
	.string	"Can you survive even 100 floors?$"

PitEntrance_Text_MoreInfo:
	.string "In this challenge you start with 3\n"
	.string "random Pokemon and must fight around\p"
	.string "200 trainers in a random battle\n"
	.string "gauntlet.\p"
	.string "You and each trainer have random mons,\n"
	.string "moves, and abilities.\p"
	.string "Trainer mon levels are tied to the\n"
	.string "floor number, with Lvl. 5 being the\p"
	.string "minimum and Lvl. 100 being the max.\n"
	.string "Starting the challenge there is only\p"
	.string "one trainer per floor, but as you \n"
	.string "progress through the Trials more -\p"
	.string "will spawn, with a maximum being\n"
	.string "four trainers per floor.\p"
	.string "After clearing each floor you will\n"
	.string "receive two random item drops to -\p"
	.string "aid you on your challenge. And the\n"
	.string "next floor warp will activate.\p"
	.string "Every 5th floor is a Heal/Shop floor\n"
	.string "where you will be able to rest and\l"
	.string "prepare for the next Trial.\p"
	.string "At the start this occurs every four\n"
	.string "battles, but eventually it is every \l"
	.string "sixteen. So take advantage of it.\p"
	.string "On every 25th floor, you will\n"
	.string "recieve a random Mon with the lvl\l"
	.string "of the floor you are on.\p"
	.string "You can choose to keep going past\n"
	.string "floor 100 to see how far you can get.\p"
	.string "Thats all the info I've got. \n"
	.string "Hopefully you have fun!$"

PitEntrance_Text_BattleInfo:
	.string "This hack is built on a hack base\n"
	.string "called the pokeemerald-expansion.\p"
	.string "By default most later Gen mechanics\n"
	.string "have been implemented.\p"
	.string "Depending on the version of the Pit\n"
	.string "that you downloaded this means things\p"
	.string "like Megas and late Gen Pokemon exist.\n"
	.string "I'm not even really aware of the full\l"
	.string "extent of these changes as I haven't\p"
	.string "played all the later games, so if you\n"
	.string "have specific question you can check\p"
	.string "the Expansion to see what they've done.$"

PitEntrance_Text_Credits:
	.string "I, Archie from Team Aquas Hideout,\n"
	.string "have put together this romhack.\p"
	.string "Full credits will be on the release\n"
	.string "but I wanted to include some here.\p"
	.string "All the battle code is from the team\n"
	.string "at RHH, they do amazing work.\p"
	.string "The decomps themselves were created\n"
	.string "by talented people in pret.\p"
	.string "Nico gave me the Healthboxes,\n"
	.string "RavePossum the backgrounds,\p"
	.string "Pawkkie gave me the Player sprites,\n"
	.string "Nicolavs the tiles,\l"
	.string "TheXaman the core of the randomizer,\p"
	.string "Special thanks to Edu and everyone\n"
	.string "in our Team Aqua Discord.\p"
	.string "Game text is slow and there are too\n"
	.string "many people to thank here, but this\l"
	.string "hack is built on community resources\p"
	.string "Without all of them this hack would\n"
	.string "not exist. Thank you all <3$"

PitEntrance_Text_Discord:
	.string "To talk about the hack join the TAH\n"
	.string "Discord: https://discord.gg/hX3a63RYzZ$"

PitEntrance_Text_Bugs:
	.string "If you have any Battle related bugs\n"
	.string "you can report them on the GitHub for\p"
	.string "the pokeemerald-expansion as I have\n"
	.string "not changed any Battle Code myself.\p"
	.string "Other bugs can be reported in the\n"
	.string "Team Aquas Hideout Discord Server$"

PitEntrance_Text_Cheats:
	.string "You can enable the Expansion debug\n"
	.string "menu by pressing R and Start at same\l"
	.string "time after entering the pit.\p"
	.string "These features can break the game\n"
	.string "so don't report bugs if using it.$"
