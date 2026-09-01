FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "You travel all over the place,\n"
	.string "don't you?\p"
	.string "You're not driving your POKéMON\n"
	.string "too harshly, are you?\p"
	.string "Let me take a look.\n"
	.string "… … …   … … …$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "Ah, hmm…\n"
	.string "I see, I see…$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "Oh, impressive.\n"
	.string "You treat your POKéMON right.\p"
	.string "I think you can be entrusted with\n"
	.string "this.\p"
	.string "Please, I'd like you to have this.$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "{PLAYER} received an EGG\n"
	.string "from the man!$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "…Unfortunately, you don't have\n"
	.string "space for this in your party.\p"
	.string "You'd better come back for it\n"
	.string "another time.$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "やあ\n"
	.string "タマゴを　もらいに\l"
	.string "きて　くれたんだね$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "I received that EGG while I was\n"
	.string "traveling.\p"
	.string "I'm glad I met someone like you.$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "Oh, hello.\n"
	.string "That's a cute {STR_VAR_2}.\p"
	.string "Seeing it reminds me of a sweet \n"
	.string "little girl I met while traveling.\p"
	.string "She was gently grooming POKéMON…\n"
	.string "She was a little angel.\p"
	.string "That little girl's name…\n"
	.string "I think it was DAISY.$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "This is an excellent environment\n"
	.string "for raising POKéMON.$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "Your POKéMON are growing up\n"
	.string "admirably well!$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "You know, I think you have the\n"
	.string "talent to be a good BREEDER.$"
