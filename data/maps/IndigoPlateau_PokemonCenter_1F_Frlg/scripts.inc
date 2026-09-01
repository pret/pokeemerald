IndigoPlateau_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_IS_CHAMPION, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_LEAGUE_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete::
	goto_if_set FLAG_IS_CHAMPION, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "At the POKéMON LEAGUE, you will\n"
	.string "face the ELITE FOUR all in a row.\p"
	.string "If you lose, you have to start all\n"
	.string "over again!\p"
	.string "This is it!\n"
	.string "Go for it!$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
	.string "From here on, you face the\n"
	.string "ELITE FOUR one by one.\p"
	.string "If you win, a door opens to the\n"
	.string "next TRAINER. Good luck!$"

IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing::
	.string "I am so sorry, but you've wasted\n"
	.string "your time coming here.\p"
	.string "LORELEI of the ELITE FOUR is\n"
	.string "absent, you see.\p"
	.string "As a result, the POKéMON LEAGUE is\n"
	.string "closed for the time being.$"

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
	.string "AGATHA's GHOST-type POKéMON are\n"
	.string "horrifically terrifying in toughness.\p"
	.string "I took my FIGHTING-type POKéMON\n"
	.string "and raised them to the max.\p"
	.string "I went at AGATHA feeling pretty\n"
	.string "confident, but she whupped us.\p"
	.string "That old lady's also got a really\n"
	.string "short fuse, too.\p"
	.string "It doesn't take anything to get\n"
	.string "that scary lady hollering.$"

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
	.string "Maybe becoming an ELITE FOUR\n"
	.string "member is in the blood.\p"
	.string "From what I've heard, LANCE has\n"
	.string "a cousin who's a GYM LEADER\l"
	.string "somewhere far away.$"

