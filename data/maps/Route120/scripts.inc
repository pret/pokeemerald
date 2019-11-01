Route120_MapScripts:: @ 81F53EC
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	.byte 0

Route120_OnResume: @ 81F53FC
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
	end

Route120_EventScript_RemoveKecleonObject:: @ 81F5406
	compare VAR_0x8009, 0
	call_if_eq Route120_EventScript_RemoveBridgeKecleon
	compare VAR_0x8009, 1
	call_if_eq Route120_EventScript_RemoveKecleon
	compare VAR_0x8009, 2
	call_if_eq Route120_EventScript_RemoveKecleon
	compare VAR_0x8009, 3
	call_if_eq Route120_EventScript_RemoveKecleon
	compare VAR_0x8009, 4
	call_if_eq Route120_EventScript_RemoveKecleon
	compare VAR_0x8009, 5
	call_if_eq Route120_EventScript_RemoveKecleon
	return

Route120_EventScript_RemoveBridgeKecleon:: @ 81F5449
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 30 @ Invisible Bridge Kecleon
	removeobject 36 @ Visible Bridge Kecleon
	return

Route120_EventScript_RemoveKecleon:: @ 81F5460
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route120_OnLoad: @ 81F5474
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_1F5490
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_1F54A3
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_1F54C8
	end

Route120_EventScript_1F5490:: @ 81F5490
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, 1
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, 1
	return

Route120_EventScript_1F54A3:: @ 81F54A3
	setmetatile 13, 15, METATILE_Fortree_WoodBridge_Kecleon0, 0
	setmetatile 12, 16, METATILE_Fortree_WoodBridge_Kecleon1, 0
	setmetatile 12, 17, METATILE_General_ReflectiveWater, 0
	setmetatile 13, 17, METATILE_General_ReflectiveWater, 0
	return

Route120_EventScript_1F54C8:: @ 81F54C8
	setobjectmovementtype 36, MOVEMENT_TYPE_FACE_RIGHT
	return

Route120_OnTransition: @ 81F54CD
	call GabbyAndTy_EventScript_UpdateLocation
	call Route120_EventScript_1F54D8
	end

Route120_EventScript_1F54D8:: @ 81F54D8
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 14
	goto_if_le Route120_EventScript_1F5503
	compare VAR_TEMP_1, 60
	goto_if_le Route120_EventScript_1F5507
	compare VAR_TEMP_1, 61
	goto_if_ge Route120_EventScript_1F54FF
	return

Route120_EventScript_1F54FF:: @ 81F54FF
	setweather WEATHER_CLOUDS
	return

Route120_EventScript_1F5503:: @ 81F5503
	setweather WEATHER_SUNNY
	return

Route120_EventScript_1F5507:: @ 81F5507
	compare VAR_TEMP_0, 7
	goto_if_le Route120_EventScript_1F5523
	compare VAR_TEMP_0, 19
	goto_if_le Route120_EventScript_1F5503
	goto Route120_EventScript_1F5523
	end

Route120_EventScript_1F5523:: @ 81F5523
	setweather WEATHER_RAIN_LIGHT
	return

Route120_EventScript_1F5527:: @ 81F5527
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_1F5625
	msgbox Route120_Text_2A70C7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq Route120_EventScript_1F562F
	compare VAR_RESULT, 0
	call_if_eq Route120_EventScript_1F5638
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, Route120_EventScript_1F55CA
	case 5, Route120_EventScript_1F55CA
	case 1, Route120_EventScript_1F55D5
	case 6, Route120_EventScript_1F55D5
	case 2, Route120_EventScript_1F55E0
	case 7, Route120_EventScript_1F55E0
	case 3, Route120_EventScript_1F55EB
	case 8, Route120_EventScript_1F55EB
	case 4, Route120_EventScript_1F55F6
	case 9, Route120_EventScript_1F55F6
	end

Route120_EventScript_1F55CA:: @ 81F55CA
	setvar VAR_0x8004, ITEM_FIGY_BERRY
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55D5:: @ 81F55D5
	setvar VAR_0x8004, ITEM_WIKI_BERRY
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55E0:: @ 81F55E0
	setvar VAR_0x8004, ITEM_MAGO_BERRY
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55EB:: @ 81F55EB
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F55F6:: @ 81F55F6
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
	goto Route120_EventScript_1F5601
	end

Route120_EventScript_1F5601:: @ 81F5601
	giveitem_std VAR_0x8004
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
	msgbox Route120_Text_2A71D5, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_1F5625:: @ 81F5625
	msgbox Route120_Text_2A7217, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_1F562F:: @ 81F562F
	msgbox Route120_Text_2A7147, MSGBOX_DEFAULT
	return

Route120_EventScript_1F5638:: @ 81F5638
	msgbox Route120_Text_2A7183, MSGBOX_DEFAULT
	return

Route120_EventScript_Steven:: @ 81F5641
	lock
	faceplayer
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_1F5672
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenNotReady:: @ 81F5665
	msgbox Route120_Text_1F5AAC, MSGBOX_DEFAULT
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
	release
	end

Route120_EventScript_1F5672:: @ 81F5672
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenBattleKecleon:: @ 81F568B
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route120_EventScript_PlayerApproachKecleonNorth
	compare VAR_FACING, DIR_WEST
	call_if_eq Route120_EventScript_PlayerApproachKecleonWest
	applymovement 31, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
	closemessage
	applymovement 30, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 30, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30, ITEM_NONE
	setvar VAR_0x8009, 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_RemoveBridgeKecleonPostBattle:: @ 81F571C
	fadescreenswapbuffers 1
	removeobject 30 @ Invisible Bridge Kecleon
	removeobject 36 @ Visible Bridge Kecleon
	fadescreenswapbuffers 0
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_StevenGiveDeconScope:: @ 81F572C
	applymovement 31, Common_Movement_WalkInPlaceFastestDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
	giveitem_std ITEM_DEVON_SCOPE
	setflag FLAG_RECEIVED_DEVON_SCOPE
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement 31, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 31
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setmetatile 13, 15, METATILE_Fortree_WoodBridge_Kecleon0, 0
	setmetatile 12, 16, METATILE_Fortree_WoodBridge_Kecleon1, 0
	setmetatile 12, 17, METATILE_General_ReflectiveWater, 0
	setmetatile 13, 17, METATILE_General_ReflectiveWater, 0
	special DrawWholeMapView
	release
	end

Route120_EventScript_PlayerApproachKecleonNorth:: @ 81F57A3
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

Route120_EventScript_PlayerApproachKecleonWest:: @ 81F57AE
	applymovement EVENT_OBJ_ID_PLAYER, Route120_Movement_ApproachKecleonWest
	waitmovement 0
	return

Route120_Movement_ApproachKecleonWest: @ 81F57B9
	walk_down
	walk_left
	step_end

Route120_EventScript_InvisibleBridgeKecleon:: @ 81F57BC
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
	end

Route120_EventScript_1F57C5:: @ 81F57C5
	msgbox Route120_Text_1F5DCB, MSGBOX_SIGN
	end

Route120_EventScript_1F57CE:: @ 81F57CE
	msgbox Route120_Text_1F5DE4, MSGBOX_SIGN
	end

Route120_EventScript_1F57D7:: @ 81F57D7
	trainerbattle_single TRAINER_COLIN, Route120_Text_29E62D, Route120_Text_29E665
	msgbox Route120_Text_29E67A, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F57EE:: @ 81F57EE
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_29E6E3, Route120_Text_29E70A, Route120_EventScript_1F581A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route120_EventScript_1F5839
	msgbox Route120_Text_29E726, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_1F581A:: @ 81F581A
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_29E75D, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROBERT_1
	release
	end

Route120_EventScript_1F5839:: @ 81F5839
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_29E7AA, Route120_Text_29E7E1
	msgbox Route120_Text_29E804, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F5850:: @ 81F5850
	trainerbattle_single TRAINER_LORENZO, Route120_Text_29E843, Route120_Text_29E884
	msgbox Route120_Text_29E8C5, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F5867:: @ 81F5867
	trainerbattle_single TRAINER_JENNA, Route120_Text_29E91C, Route120_Text_29E980
	msgbox Route120_Text_29E996, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F587E:: @ 81F587E
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_29E9D7, Route120_Text_29E9FF, Route120_EventScript_1F58AA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route120_EventScript_1F58C9
	msgbox Route120_Text_29EA08, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_1F58AA:: @ 81F58AA
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_29EA31, MSGBOX_DEFAULT
	register_matchcall TRAINER_JEFFREY_1
	release
	end

Route120_EventScript_1F58C9:: @ 81F58C9
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_29EA61, Route120_Text_29EA8F
	msgbox Route120_Text_29EAA9, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F58E0:: @ 81F58E0
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_29EAEF, Route120_Text_29EB53
	msgbox Route120_Text_29EB6E, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F58F7:: @ 81F58F7
	trainerbattle_single TRAINER_CHIP, Route120_Text_29EBAF, Route120_Text_29EC25
	msgbox Route120_Text_29EC41, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F590E:: @ 81F590E
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_29ECA6, Route120_Text_29ECEF
	msgbox Route120_Text_29ED19, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F5925:: @ 81F5925
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_29ED71, Route120_Text_29EDD3
	msgbox Route120_Text_29EDF7, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F593C:: @ 81F593C
	trainerbattle_single TRAINER_KEIGO, Route120_Text_29EE50, Route120_Text_29EE97
	msgbox Route120_Text_29EED4, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F5953:: @ 81F5953
	trainerbattle_single TRAINER_RILEY, Route120_Text_29EF08, Route120_Text_29EF63
	msgbox Route120_Text_29EF89, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F596A:: @ 81F596A
	trainerbattle_single TRAINER_LEONEL, Route120_Text_29F04F, Route120_Text_29F080
	msgbox Route120_Text_29F0A1, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_1F5981:: @ 81F5981
	trainerbattle_single TRAINER_CALLIE, Route120_Text_29EFB1, Route120_Text_29EFE1
	msgbox Route120_Text_29F002, MSGBOX_AUTOCLOSE
	end

Route120_Text_StevenGreeting: @ 81F5998
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
	.string "It's been a while.\p"
	.string "There's something here that you can't\n"
	.string "see, right?\p"
	.string "Now, if I were to use this device on\n"
	.string "the invisible obstacle…\p"
	.string "No, no. Rather than describing it,\n"
	.string "I should just show you.\l"
	.string "That would be more fun.\p"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
	.string "battle?$"

Route120_Text_1F5AAC: @ 81F5AAC
	.string "STEVEN: No?\p"
	.string "I'll wait here, so you can get ready.$"

Route120_Text_StevenReadyForBattle: @ 81F5ADE
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
	.string "ready for battle?$"

Route120_Text_StevenShowMeYourPower: @ 81F5B0F
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
	.string "power as a TRAINER!$"

Route120_Text_StevenUsedDevonScope: @ 81F5B43
	.string "STEVEN used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_StevenGiveDevonScope: @ 81F5BAF
	.string "STEVEN: I see…\n"
	.string "Your battle style is intriguing.\p"
	.string "Your POKéMON have obviously grown\n"
	.string "since I first met you in DEWFORD.\p"
	.string "I'd like you to have this\n"
	.string "DEVON SCOPE.\p"
	.string "Who knows, there may be other\n"
	.string "concealed POKéMON.$"

Route120_Text_StevenGoodbye: @ 81F5C7B
	.string "STEVEN: {PLAYER}{KUN}.\p"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
	.string "who strive together.\p"
	.string "I think you're doing great.\p"
	.string "Well, let's meet again somewhere.$"

Kecleon_Text_SomethingUnseeable: @ 81F5D00
	.string "Something unseeable is in the way.$"

Kecleon_Text_WantToUseDevonScope: @ 81F5D23
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

Kecleon_Text_UseDevonScopeMonAttacked: @ 81F5D63
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_1F5DCB: @ 81F5DCB
	.string "ROUTE 120\n"
	.string "{LEFT_ARROW} FORTREE CITY$"

Route120_Text_1F5DE4: @ 81F5DE4
	.string "{RIGHT_ARROW} ROUTE 121\n"
	.string "{LEFT_ARROW} ROUTE 120$"
