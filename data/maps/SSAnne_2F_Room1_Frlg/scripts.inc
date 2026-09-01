SSAnne_2F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room1_EventScript_Gentleman::
	lock
	faceplayer
	message SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis
	waitmessage
	setvar VAR_0x8004, SPECIES_SNORLAX
	special SetSeenMon
	showmonpic SPECIES_SNORLAX, 10, 3
	waitbuttonpress
	hidemonpic
	release
	end

SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis::
	.string "I've journeyed far and wide, but in\n"
	.string "all my travels I've never seen\l"
	.string "any POKéMON sleep like this one!\p"
	.string "It was something like this!$"

