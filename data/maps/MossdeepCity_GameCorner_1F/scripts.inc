MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "When I was young, I traveled the world\n"
	.string "as a Pokémon Trainer.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "Trainers battle.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "The door appears to be locked.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "A Trainer named {STR_VAR_1} is\n"
	.string "visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "I hope to see a good match!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"
