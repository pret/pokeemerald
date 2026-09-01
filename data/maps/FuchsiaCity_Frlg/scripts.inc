FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
	.string "Did you try the SAFARI GAME?\p"
	.string "There are some rare POKéMON that\n"
	.string "can only be caught there.$"

FuchsiaCity_Text_SafariZoneZooInFront::
	.string "The SAFARI ZONE has a zoo in front\n"
	.string "of the entrance.\p"
	.string "Out back is the SAFARI GAME for\n"
	.string "catching POKéMON.$"

FuchsiaCity_Text_WheresSara::
	.string "ERIK: Where's SARA?\n"
	.string "I said I'd meet her here.$"

FuchsiaCity_Text_ItemBallInThere::
	.string "That item ball in there…\n"
	.string "Were you wanting that?\p"
	.string "Me, too!\n"
	.string "…Huh? That's a POKéMON?$"

FuchsiaCity_Text_CitySign::
	.string "FUCHSIA CITY\n"
	.string "Behold! It's Passion Pink!$"

FuchsiaCity_Text_SafariZoneSign::
	.string "POKéMON PARADISE\n"
	.string "SAFARI ZONE$"

FuchsiaCity_Text_SafariGameSign::
	.string "SAFARI GAME\n"
	.string "POKéMON-U-CATCH!$"

FuchsiaCity_Text_WardensHomeSign::
	.string "SAFARI ZONE\n"
	.string "WARDEN'S HOME$"

FuchsiaCity_Text_SafariZoneOfficeSign::
	.string "POKéMON PARADISE!\n"
	.string "Welcome to the SAFARI ZONE!\l"
	.string "SAFARI ZONE OFFICE$"

FuchsiaCity_Text_GymSign::
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: KOGA\l"
	.string "The Poisonous Ninja Master$"

FuchsiaCity_Text_ChanseySign::
	.string "Name: CHANSEY\n"
	.string "Catching one is all up to chance.$"

FuchsiaCity_Text_VoltorbSign::
	.string "Name: VOLTORB\n"
	.string "The very image of a POKé BALL.$"

FuchsiaCity_Text_KangaskhanSign::
	.string "Name: KANGASKHAN\p"
	.string "A maternal POKéMON that raises its\n"
	.string "young in a pouch on its belly.$"

FuchsiaCity_Text_SlowpokeSign::
	.string "Name: SLOWPOKE\n"
	.string "Friendly and very slow moving.$"

FuchsiaCity_Text_LaprasSign::
	.string "Name: LAPRAS\n"
	.string "AKA the king of the seas.$"

FuchsiaCity_Text_OmanyteSign::
	.string "Name: OMANYTE\n"
	.string "An extremely rare POKéMON that was\l"
	.string "regenerated from a fossil.$"

FuchsiaCity_Text_KabutoSign::
	.string "Name: KABUTO\n"
	.string "An extremely rare POKéMON that was\l"
	.string "regenerated from a fossil.$"

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
	.string "……$"

Text_SubstituteTeach::
	.string "Aww, I wish I was a KANGASKHAN\n"
	.string "baby.\p"
	.string "I'd love to be a substitute for the\n"
	.string "baby…\p"
	.string "And snuggle in the mother\n"
	.string "KANGASKHAN's belly pouch.\p"
	.string "But only POKéMON can use the\n"
	.string "technique SUBSTITUTE…\p"
	.string "Want me to teach SUBSTITUTE to\n"
	.string "one of your POKéMON?$"

Text_SubstituteDeclined::
	.string "Oh, really?\n"
	.string "SUBSTITUTE seems so fun…$"

Text_SubstituteWhichMon::
	.string "Which POKéMON wants to learn\n"
	.string "SUBSTITUTE?$"

Text_SubstituteTaught::
	.string "Boy, what I'd give to crawl inside\n"
	.string "a KANGASKHAN belly pouch…$"

FuchsiaCity_Text_MyFatherIsGymLeader::
	.string "My father is the GYM LEADER of\n"
	.string "this town.\p"
	.string "I'm training to use POISON POKéMON\n"
	.string "as well as my father.$"

