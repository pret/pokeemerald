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
	.string "Toen ik jong was, reisde ik de\n"
	.string "wereld rond als POKéMON TRAINER.\p"
	.string "Nu ik een oude man ben, vind ik\n"
	.string "het leuk om jonge TRAINERS te\l"
	.string "zien vechten.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "De deur lijkt op slot te zitten.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Een TRAINER genaamd {STR_VAR_1} is\n"
	.string "bij mij op bezoek.\p"
	.string "Wil je {STR_VAR_1}\n"
	.string "uitdagen?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Je wilt niet vechten? Jammer, ik\n"
	.string "had graag een gevecht gezien…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, fijn, fijn!\p"
	.string "Maar mijn huis is niet zo stevig.\p"
	.string "Kun je het bij een 3-tegen-3\n"
	.string "gevecht houden?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Sla je voortgang op voordat\n"
	.string "jullie vechten.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Ik hoop op een goed gevecht!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Het werd gelijkspel.\p"
	.string "Een schitterend gevecht waarin\n"
	.string "geen van beiden toegaf!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Dat was fantastisch!\p"
	.string "Het was alsof ik mezelf weer\n"
	.string "in mijn jeugd zag!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, jammer voor jou!\p"
	.string "Maar het was een goed gevecht.\n"
	.string "Hopelijk win je de volgende keer.$"
