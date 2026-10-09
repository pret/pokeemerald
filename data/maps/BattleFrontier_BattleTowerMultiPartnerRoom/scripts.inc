BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applywaitmovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	applywaitmovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applywaitmovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applywaitmovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Zoek een maatje uit de TRAINERS\n"
	.string "die hier zijn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, je hebt nog geen maatje\n"
	.string "voor je team gevonden.\p"
	.string "Wil je stoppen met zoeken en\n"
	.string "terug naar de balie gaan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Zoek dan een maatje uit de\n"
	.string "TRAINERS die hier zijn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Bedankt dat je een maatje koos.\p"
	.string "Ik breng je nu naar je\n"
	.string "MULTI-GEVECHTSKAMER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Ik ben leerling nr. {STR_VAR_2} van\n"
	.string "{STR_VAR_1}. Noem me maar {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Op advies van {STR_VAR_1} heb ik een\n"
	.string "{STR_VAR_3} met {STR_VAR_2} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Laat me alsjeblieft in je team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Bedankt!\n"
	.string "Ik ga me meteen aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Ik wilde zo graag een team\n"
	.string "vormen met jou, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Ik ben leerling nr. {STR_VAR_2} van\n"
	.string "{STR_VAR_1}. Ik heet {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Ik kreeg advies van {STR_VAR_1} en koos\n"
	.string "een {STR_VAR_3} met {STR_VAR_2} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Laten we een team vormen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Heel erg bedankt!\n"
	.string "Ik meld me zo aan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, ik hoopte zo dat ik\n"
	.string "je maatje mocht worden…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Eh, ik heet {STR_VAR_3} en ik ben\n"
	.string "leerling nr. {STR_VAR_2} van {STR_VAR_1}.\p"
	.string "Snif…\p"
	.string "Sorry!\n"
	.string "Deze spanning maakt me aan het huilen…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} adviseerde me, dus ik heb\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "Wil je alsjeblieft met me samen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Echt? Doe je het?\n"
	.string "Gaaf! Wauw! Awoooh!\p"
	.string "Oh… Sorry…\n"
	.string "Ik ben zo blij dat ik moet huilen…\p"
	.string "Ik meld me meteen aan.\n"
	.string "Ga alsjeblieft niet weg!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, m-maar…\n"
	.string "Snik… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hoi! Ik ben {STR_VAR_3}!\n"
	.string "Ik ben leerling nr. {STR_VAR_2}\l"
	.string "van {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} raadde mijn team aan.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1},\n"
	.string "dat heb ik! Gaaf, hè?\p"
	.string "Kom op!\n"
	.string "Laten we een team vormen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Joepie! Super!\n"
	.string "Oké, ik ga me aanmelden, oké?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, waarom?\n"
	.string "Ik wilde met je samen, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Ik ben {STR_VAR_3}, leerling nr. {STR_VAR_2}\n"
	.string "van de beroemde {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Ik vroeg {STR_VAR_3} om advies.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "en een {STR_VAR_2} met {STR_VAR_1},\n"
	.string "dat is mijn duo.\p"
	.string "Wil je alsjeblieft met me\n"
	.string "een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Bedankt!\n"
	.string "Ik meld me meteen aan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, ik hoopte zo dat ik\n"
	.string "bij jou in het team mocht…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Eh… Ik ben echt blij dat je de tijd\n"
	.string "nam om met me te praten.\p"
	.string "Ik ben {STR_VAR_3}.\n"
	.string "Ik ben leerling nr. {STR_VAR_2}\l"
	.string "van {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gaf me advies.\n"
	.string "Ik ben er heel dankbaar voor.\p"
	.string "Mijn team is een {STR_VAR_2}\n"
	.string "met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\n"
	.string "Ik weet dat ik veel vraag…\p"
	.string "Ik denk niet dat je het wilt,\n"
	.string "maar mag ik je maatje zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Echt? Ongelofelijk!\n"
	.string "Ik kan niet geloven dat het mag!\l"
	.string "Ik… Ik laat je niet vallen!\p"
	.string "Eh… Als het echt mag, meld ik me\n"
	.string "meteen aan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "Ik dacht dat ik niet goed was…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hoi, ik ben {STR_VAR_3}.\n"
	.string "Ik ben leerling nr. {STR_VAR_2}\l"
	.string "van {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} zei dat dit een goed team\n"
	.string "zou zijn:\l"
	.string "een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "en een {STR_VAR_2} die {STR_VAR_1}\n"
	.string "kan gebruiken.\p"
	.string "Niet slecht, hè?\n"
	.string "Wil je met me samen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Oké, leuk om met je te spelen!\n"
	.string "Verpest het niet voor me, hoor!\l"
	.string "Ik meld me nu aan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hè? Waarom zei je nee?\n"
	.string "Jij kunt echt geen mensen lezen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Ik ben {STR_VAR_3} en ik ben TRIATLEET.\n"
	.string "Elke dag ben ik bezig met rennen,\l"
	.string "trainen en rappen.\p"
	.string "Ik ben ook leerling nr. {STR_VAR_2}\n"
	.string "van {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Dit raadde {STR_VAR_3} me aan.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}.\p"
	.string "Ik heb er veel moeite in gestoken,\n"
	.string "ook al heb ik het druk.\p"
	.string "Laten we een team vormen\n"
	.string "en het proberen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Dank je, zo hoort het!\n"
	.string "Wacht even terwijl ik me aanmeld, oké?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Ik heb tijd uit mijn drukke\n"
	.string "agenda gehaald! Doe normaal!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hoi!\n"
	.string "Hoe gaat het?\p"
	.string "Ik ben {STR_VAR_3}, leerling nr. {STR_VAR_2}\n"
	.string "van {STR_VAR_1}. Leuk je te ontmoeten!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Luister, luister! Je moet horen\n"
	.string "welke POKéMON {STR_VAR_3} aanraadde.\l"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\n"
	.string "Natuurlijk heb ik ze super getraind!\p"
	.string "Dus, wil je samen? Dat wordt vast\n"
	.string "een geweldige combinatie!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Joepie, dit wordt leuk!\n"
	.string "Ik ga me aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, wat gemeen!\n"
	.string "Ik ben juist aanbevolen, hoor.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Mag ik me voorstellen?\n"
	.string "Ik ben {STR_VAR_3}.\p"
	.string "Ik ben leerling nr. {STR_VAR_2}\n"
	.string "van {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Ik vroeg {STR_VAR_3} om wijs\n"
	.string "advies en trainde mijn team:\l"
	.string "een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "en een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Wil je alsjeblieft met me samen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… Wat fijn!\n"
	.string "Ik beloof dat ik mijn best doe!\p"
	.string "Natuurlijk meld ik ons aan!\n"
	.string "Wacht even!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Ik hoopte zo dat ik bij je mocht,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Iek! Je praatte tegen me!\n"
	.string "Ik… Ik ben dolblij!\p"
	.string "Ik ben {STR_VAR_3}! Ik ben leerling\n"
	.string "nr. {STR_VAR_2} van {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Op advies van {STR_VAR_3} trainde ik\n"
	.string "een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}.\p"
	.string "Alsjeblieft, vervul je mijn wens?\n"
	.string "Ik wil je maatje zijn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Iek! Ik… Ik word er duizelig van!\n"
	.string "Hartstikke bedankt!\l"
	.string "Ik meld ons meteen aan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Heb je geen medelijden?\n"
	.string "Maar dat maakt je juist cooler…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Joehoe! Ik ben leerling nr. {STR_VAR_2}\n"
	.string "van {STR_VAR_1}!\p"
	.string "{STR_VAR_3} is mijn naam, hallo, hallo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mijn mentor {STR_VAR_3} raadde een\n"
	.string "{STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1} aan.\p"
	.string "Goed spul, hè?\n"
	.string "Je wordt mijn maatje, toch?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Oké, super!\n"
	.string "Ik ga me snel aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "Jij rekent alles uit, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hé! Groot probleem! Het is de\n"
	.string "laatste dag van de BATTLE TOWER!\p"
	.string "… … … … … …\n"
	.string "Ik maak maar een grapje!\p"
	.string "Mensen noemen me {STR_VAR_3} en ik ook!\n"
	.string "Ik ben de 1000e leerling van\l"
	.string "{STR_VAR_1}! Eigenlijk nr. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gaf me advies.\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} met {STR_VAR_1}.\n"
	.string "Ik heb er tien van elk!\l"
	.string "Eigenlijk maar één van elk!\p"
	.string "En, wat denk je?\n"
	.string "Wil je tagbattles met me doen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Joepie!\n"
	.string "Als bedankje geef ik je een POKéMON!\p"
	.string "Grapje! Maar ik ga me echt\n"
	.string "aanmelden, oké?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, wat koud! Daarvoor maak ik de\n"
	.string "BATTLE TOWER kapot!\p"
	.string "Natuurlijk doe ik dat niet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hé, ik rock en ik roll!\n"
	.string "POKéMON, die heb ik onder controle!\p"
	.string "Ik ben {STR_VAR_3}, de rappende MATROOS.\n"
	.string "Verwar me niet met een zeur!\p"
	.string "Ik ben leerling nr. {STR_VAR_2}\n"
	.string "van {STR_VAR_1}. Onderschat me niet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Op raad van {STR_VAR_3} maakte ik\n"
	.string "mijn team, mijn trots, hoor!\l"
	.string "Een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}!\p"
	.string "Onze ontmoeting vieren we groots,\n"
	.string "met een gezamenlijke overwinning!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hé, hé, ik hou van je stijl!\n"
	.string "Ik ga ons aanmelden, hoor!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hé, {PLAYER}, dat is koud!\n"
	.string "Dat mag ik wel zeggen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Jippie-jahoe!\n"
	.string "Oh, ren niet weg! Ik maakte maar een grapje!\p"
	.string "Hoi! Ik ben {STR_VAR_3}!\n"
	.string "Ik ben leerling nr. {STR_VAR_2}\l"
	.string "van {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} vertelde me wat ik moest\n"
	.string "doen. Dus koos ik een\l"
	.string "{STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}.\p"
	.string "Dus, wat zeg je?\n"
	.string "Kom op, maak mijn dag!\p"
	.string "Alsjeblieft, ik smeek je!\n"
	.string "Laat me meedoen, laat me niet alleen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Jeehaa! Ik heb geluk!\n"
	.string "Ik ben er zo blij van!\p"
	.string "Voor we het gevecht ingaan,\n"
	.string "ga ik me meteen aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Je wijst me af?\n"
	.string "{PLAYER}, dat vind ik echt jammer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Hatsjoe!\p"
	.string "Oh, sorry, ik ben verkouden.\n"
	.string "Mijn POKéMON zijn wel gezond.\p"
	.string "Ik heet {STR_VAR_3}, leerling\n"
	.string "nr. {STR_VAR_2} van {STR_VAR_1}.\l"
	.string "Hatsjoe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Ik nam het advies van {STR_VAR_3} aan\n"
	.string "en maakte mijn team van\l"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Ik trainde ze elke dag,\n"
	.string "ook in wind en regen.\p"
	.string "Daarom ben ik verkouden,\n"
	.string "denk ik.\p"
	.string "Zo ben ik nou eenmaal.\n"
	.string "Wil je mijn maatje zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Bedankt, dat waardeer ik!\n"
	.string "Hatsjoe, hatsjoe!\l"
	.string "Wacht even terwijl ik me aanmeld.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, wil je niet?\n"
	.string "{PLAYER}, wij zijn vast een goed duo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hallo!\n"
	.string "Ik ben zo zenuwachtig.\p"
	.string "Ik ben {STR_VAR_3}.\n"
	.string "Ik ben leerling nr. {STR_VAR_2} van {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} zei dat dit team goed is--\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Ik ben er onzeker over,\n"
	.string "maar mag ik met je mee?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, wat fijn, bedankt!\n"
	.string "Ik ben verlegen, maar ik doe mijn best!\p"
	.string "Ik ga me aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, zeg alsjeblieft geen nee!\n"
	.string "Ik ben al zo onzeker…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Ik ben {STR_VAR_3}, echt waar.\n"
	.string "Ik ben leerling nr. {STR_VAR_2}\l"
	.string "van {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} raadde mijn team aan.\p"
	.string "Het advies klonk oprecht, dus\n"
	.string "ik nam mijn {STR_VAR_2} met\l"
	.string "{STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "mijn {STR_VAR_2} met {STR_VAR_1} mee.\p"
	.string "Als het kan, zou ik graag je\n"
	.string "maatje zijn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Neem je me echt aan?\n"
	.string "Anders was het te erg.\p"
	.string "Maar nu je ja zegt, is het goed.\n"
	.string "Ik meld ons allebei aan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Waarom zou je weigeren?\n"
	.string "Is dit een grapje van je?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Ik ben {STR_VAR_1}, een MEISJE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Ik heb een {STR_VAR_2}\n"
	.string "met {STR_VAR_1} en een$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} met {STR_VAR_1}.\n"
	.string "Die heb ik bij me.\p"
	.string "Word je mijn maatje?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Bedankt!\n"
	.string "Ik ga me aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Wil je mijn maatje niet zijn?\n"
	.string "Dat zul je later betreuren!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hallo!\p"
	.string "Ik ben JONGEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Wil je weten wat ik heb?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Je wordt mijn tagteam-maatje,\n"
	.string "toch?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Joepie!\n"
	.string "Ik ga me aanmelden, oké?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aww! Als je met mijn POKéMON een\n"
	.string "team vormt, zijn we niet te stoppen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Joehoe!\n"
	.string "Ik ben WANDELAAR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Weet je wat ik bij me heb?\n"
	.string "Mijn {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "mijn {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Klinkt goed, hè?\n"
	.string "Wil je een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Joehoe!\n"
	.string "Dan ga ik me aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Ik had graag met je gevochten,\n"
	.string "zij aan zij.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hallo!\n"
	.string "Ik ben {STR_VAR_1}, een SCHOONHEID!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Weet je wat ik heb getraind?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Wat vind je?\n"
	.string "Wil je samen een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Heerlijk!\n"
	.string "Ik ga me nu aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Wat jammer!\p"
	.string "Wij samen--wij waren de\n"
	.string "beste geweest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Hé!\p"
	.string "Weet je wie ik ben?\n"
	.string "Ik ben VISSER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Ik heb een team van een\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Dus, wat zeg je?\n"
	.string "Vecht je aan mijn zijde?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Goed, goed!\n"
	.string "Laat maar aan mij over!\p"
	.string "Ik ga ons nu aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "We pasten zo goed bij elkaar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Aangenaam kennis te maken.\n"
	.string "Ik ben {STR_VAR_1}, een DAME.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Ik word vergezeld door een team van\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Ik hoop dat je het goed vindt.\n"
	.string "Ik wil jou graag als maatje.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Hartelijk bedankt.\n"
	.string "Ik regel de aanmelding.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Je zult er vast spijt van krijgen\n"
	.string "dat ik niet je maatje ben.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Ik ben TRIATLEET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Wat ik heb…\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\n"
	.string "Dat is mijn duo!\p"
	.string "Alsjeblieft?\n"
	.string "Wil je met me een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Wat fijn, bedankt!\n"
	.string "Ik ga me aanmelden bij de balie.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Wij samen, we waren zeker\n"
	.string "sterk geweest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hoi!\n"
	.string "Ik ben INSECTVANGER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Kijk eens wat ik heb!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Luister!\n"
	.string "Wil je een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Begrepen!\p"
	.string "Ik ga de aanmelding regelen\n"
	.string "bij de balie.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, mijn POKéMON zijn geweldig.\n"
	.string "Ik hoop dat je er geen spijt van krijgt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Goedendag!\n"
	.string "Ik ben SCHOLIER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Ik heb getraind: een\n"
	.string "{STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}.\p"
	.string "Niet slecht, vind je niet?\n"
	.string "Wil je een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Hartelijk bedankt!\n"
	.string "Ik regel de aanmelding.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Wat jammer…\p"
	.string "Ik hoopte van je te leren\n"
	.string "als je maatje…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Ik vertel je wie ik ben!\n"
	.string "Ik ben RIJKE JONGEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Raad eens wat ik heb!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Ik geef je de kans om met mij\n"
	.string "een team te vormen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Slim van je!\p"
	.string "Ik ben snel klaar met\n"
	.string "de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Wijs je mij af, van alle mensen?\n"
	.string "Daar krijg je zeker spijt van!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "Ik ben KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Als maatjes heb ik\n"
	.string "een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1}.\p"
	.string "Alsjeblieft, vervul mijn wens!\n"
	.string "Laat me je maatje zijn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "Ik ga me direct aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Ik snap het… Ik hoop op een kans\n"
	.string "als we elkaar weer zien…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hoi!\n"
	.string "Ik ben {STR_VAR_1}, een WATERRAT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Ik vertel wat ik heb.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\n"
	.string "Mag ik alsjeblieft in je team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Bedankt!\n"
	.string "Ik ga ons nu aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Als we maatjes waren geworden,\n"
	.string "waren we zo sterk geweest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Hallo…\n"
	.string "Ik ben HEKS {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Ik heb een {STR_VAR_2} met {STR_VAR_1}\n"
	.string "bij me, samen met een$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} met {STR_VAR_1}…\p"
	.string "Ik smeek je…\n"
	.string "Vorm een team met mij…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Ik dank je…\n"
	.string "Ik meld ons aan…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Ik verlangde zo naar jou…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Hoe gaat het? Ik ben {STR_VAR_1},\n"
	.string "en ik ben een POKéMON FOKKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Ik fok een paar goede!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Wat zeg je ervan?\n"
	.string "Wil je een team met mij vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Hartelijk bedankt!\p"
	.string "Ik regel de aanmelding,\n"
	.string "dus wacht maar hier!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Ik keek uit naar jou als\n"
	.string "maatje…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Hoi!\n"
	.string "Ik ben TRIATLEET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Wil je weten waarmee ik ren?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Nou?\n"
	.string "Wil je met mij een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Goed zo!\p"
	.string "Ik ben snel en regel de\n"
	.string "aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Jij en ik, wij waren de beste\n"
	.string "geweest. Wat jammer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hé, hoi! Ik heet {STR_VAR_1}!\n"
	.string "Ik ben TRIATLEET!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Ik ren met mijn sterke team--\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Niet slecht, hè?\n"
	.string "We moeten samen een team vormen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Goed zo!\n"
	.string "Ik ga me in een flits aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Ik wilde zo graag als jouw maatje\n"
	.string "vechten…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Ik ben VECHTMEISJE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Ik heb een {STR_VAR_2} met\n"
	.string "{STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Vind je die combinatie leuk?\n"
	.string "Zullen jij en ik samengaan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Wat fijn, bedankt!\p"
	.string "Ik regel de aanmelding\n"
	.string "meteen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Met jou dacht ik het\n"
	.string "beste team te vormen…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Ik ben TRIATLEET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Ik ren met een {STR_VAR_2}\n"
	.string "die {STR_VAR_1} kan gebruiken$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "en een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "We kunnen een team vormen.\n"
	.string "Zou dat niet geweldig zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Bedankt!\p"
	.string "Ik meld ons aan, en wel\n"
	.string "meteen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, wat jammer. Wij waren het\n"
	.string "sterkste team van allemaal geweest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Ik?\n"
	.string "Ik ben WATERRAT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Wat ik bij me heb?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Hé?\n"
	.string "Je vormt een team met me, toch?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Oké!\p"
	.string "Ik ga me aanmelden!\n"
	.string "Laten we samen geweldig zijn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mijn POKéMON zijn echt sterk…\n"
	.string "Wat jammer dat je niet wilt.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hee!\n"
	.string "Noem me GITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Kijk eens wat een gevolg!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Yay-hee! Best wild, hè?\n"
	.string "We moeten een duet doen als team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hee! Top!\n"
	.string "Ik ga me nu aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mijn POKéMON rocken hard!\n"
	.string "Je krijgt er spijt van, echt waar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Aangenaam.\n"
	.string "Ik ben {STR_VAR_1}, een GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Ik word vergezeld door mijn trouwe\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Mag ik je vragen om samen een\n"
	.string "team te vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, ik dank je voor je vertrouwen.\n"
	.string "Ik regel de aanmelding.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Dat is jammer…\p"
	.string "Ik kijk uit naar de volgende\n"
	.string "kans…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hallo, ik ben {STR_VAR_1}\n"
	.string "en ik ben een POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Ik heb nu een {STR_VAR_2}\n"
	.string "die de AANVAL {STR_VAR_1} kent en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Vind je het mooi?\n"
	.string "Word je mijn maatje?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Bedankt!\n"
	.string "Ik regel de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mijn POKéMON zijn van topklasse…\n"
	.string "Jammer dat je dat niet waardeert.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "Ik ben {STR_VAR_1}, een EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "De POKéMON die ik sterk maakte zijn\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Wat zeg je van een team met mij?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "Ik meld ons direct aan!\l"
	.string "Laten we ons best doen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Ik hoop dat je keuze echt\n"
	.string "de juiste is…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hallo, hallo.\n"
	.string "Ik ben {STR_VAR_1}, een EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Ik heb mijn POKéMON goed getraind.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}--\n"
	.string "die heb ik.\p"
	.string "Wil je niet met mij samen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Goed, goed.\n"
	.string "Ik regel meteen de aanmelding.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Misschien vormen we een team\n"
	.string "als we elkaar weer zien.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Ik ben DRAKENTEMMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Mijn team dat ik sterk maakte is\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Wat zeg je ervan?\n"
	.string "Wil je mijn maatje zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Oké, ik doe mijn best!\n"
	.string "Ik ga me nu aanmelden, goed?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Je vindt niet veel sterkere\n"
	.string "maatjes dan ik!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Ik ben VOGELAAR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Welke POKéMON ik heb?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Denk je niet dat we een prima\n"
	.string "team zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Super, bedankt!\n"
	.string "Ik regel de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mijn POKéMON en ik zijn sterk.\n"
	.string "Wat een teleurstelling.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Ik ben NINJAJONGEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mijn team bestaat uit een\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Laten we samen een team vormen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay!\n"
	.string "Ik ga me aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Je krijgt spijt als je mijn sterke\n"
	.string "POKéMON niet aan je zijde hebt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hallo!\n"
	.string "Ik ben PARASOLDAME {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Mijn gevolg is nu mijn {STR_VAR_2}\n"
	.string "die {STR_VAR_1} gebruikt en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "een {STR_VAR_2} die\n"
	.string "{STR_VAR_1} gebruikt.\p"
	.string "Zijn ze niet mooi?\n"
	.string "Wil je met ons een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Hartelijk bedankt!\p"
	.string "Ik meld ons aan bij de balie.\n"
	.string "Laten we elkaar niet teleurstellen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mijn POKéMON zijn enorm sterk.\n"
	.string "Wat een teleurstelling…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hallo.\n"
	.string "Ik ben {STR_VAR_1}, een INSECTENFAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Ik heb mijn POKéMON gevonden, ja.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}--\n"
	.string "die heb ik gevonden.\p"
	.string "Heb je zin om een\n"
	.string "team te vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Oké!\n"
	.string "Begrepen!\p"
	.string "Ik ben zo klaar met de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Met de POKéMON die ik vond, hadden\n"
	.string "we niet verloren…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoi!\n"
	.string "Ik ben MATROOS {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Ik laat je mijn trots zien!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Je zegt vast geen nee.\n"
	.string "We vormen een team, toch?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Dat had ik niet anders verwacht!\n"
	.string "Ik ga me nu aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "We hadden de tegenstanders\n"
	.string "weggeblazen! Jammer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hoi, ik ben {STR_VAR_1}.\n"
	.string "Ik ben een VERZAMELAAR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "De juwelen in mijn collectie zijn\n"
	.string "mijn {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Mooi, hè?\n"
	.string "We moeten samen een team vormen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh ja!\p"
	.string "Laten we geen tijd verspillen.\n"
	.string "Ik meld ons allebei aan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Nou, dat is vervelend.\n"
	.string "Je waardeert mijn POKéMON niet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Hoi, ik ben {STR_VAR_1}.\n"
	.string "Ik ben een POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Mijn gezelschap is een\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Denk je niet dat we een indrukwekkend\n"
	.string "team zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Super!\n"
	.string "Ik regel de aanmelding nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Kies de volgende keer mijn POKéMON,\n"
	.string "wil je?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Ik heet {STR_VAR_1}.\n"
	.string "Ik ben een POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Ik vertel je over mijn team. Ik heb\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Wil je een team vormen met\n"
	.string "mijn groepje?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "We doen ons best!\n"
	.string "Ik regel snel de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Ik hoop dat je de volgende keer\n"
	.string "mijn POKéMON kiest.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Aangenaam. Ik ben {STR_VAR_1}.\n"
	.string "Ik ben een GEURDAME.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Ik reis met een {STR_VAR_2}\n"
	.string "die {STR_VAR_1} gebruikt en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "een {STR_VAR_2} die\n"
	.string "{STR_VAR_1} gebruikt.\p"
	.string "Ik hoop dat ze je bevallen.\n"
	.string "Wil je mijn maatje zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Het is een eer dat je ja zegt.\n"
	.string "Ik ga me meteen aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Het zou fijn zijn als we de\n"
	.string "volgende keer een team vormen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Wil je weten wie ik ben?\n"
	.string "Ik ben {STR_VAR_1}, de RUÏNEFAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "De POKéMON die ik bij me heb zijn\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Interessant, hè?\n"
	.string "Zullen jij en ik samengaan?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Een verstandig besluit!\n"
	.string "Ik ga het papierwerk voor de\l"
	.string "aanmelding doen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "Ik vind mijn POKéMON sterk…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Ik ben TOPTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "De POKéMON die ik nu heb zijn een\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\n"
	.string "Cool, hè?\p"
	.string "Vind je het niet cool als\n"
	.string "we een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool!\n"
	.string "Ik regel de aanmelding in een flits!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Ik dacht dat we het beste\n"
	.string "team ooit zouden zijn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Ik ben TOPTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Mijn team heeft een\n"
	.string "{STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Klinkt dat goed?\n"
	.string "Zullen we maatjes worden?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Klinkt prima!\n"
	.string "Ik moet me maar aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Ik dacht dat we een\n"
	.string "sterk team zouden zijn…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Hoi hoi!\n"
	.string "Ik ben {STR_VAR_1}, de POKéMANIAK!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Wat heeft zo'n kerel als ik?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}, dat!\p"
	.string "Laten we gaan!\n"
	.string "We stampen samen als team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Goede keuze!\n"
	.string "Ik meld ons allebei aan!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Mijn POKéMON zijn wreed!\n"
	.string "Geef mij niet de schuld van je spijt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Hé daar!\n"
	.string "Ik ben VUURSTOKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Weet je wat mijn training opleverde?\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Nou, wat zeg je?\n"
	.string "Wil je een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Oké!\n"
	.string "Ik ga verder met de aanmelding.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Beloof dat je de volgende keer\n"
	.string "mijn maatje wordt als we elkaar zien.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Ik ben {STR_VAR_1}, een KAMPEERDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Ik heb een {STR_VAR_2} met\n"
	.string "{STR_VAR_1} en een$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} met {STR_VAR_1} getraind.\p"
	.string "Denk je dat een team leuk is?\n"
	.string "Ik wed van wel!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Ja!\n"
	.string "Ik ga me aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "De volgende keer, oké?\n"
	.string "Ik wil in jouw team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hallo!\n"
	.string "Ik ben {STR_VAR_1}, een PICKNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "De POKéMON die ik meeneem zijn\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Wil je met me een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Wat aardig, bedankt!\n"
	.string "Ik ga me nu aanmelden.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Het zou fijn zijn als ik een andere\n"
	.string "keer met je mee mocht.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Ik ben HELDERZIENDE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Het tweetal dat ik train is\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Wil je een team met me vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Natuurlijk!\n"
	.string "Ik regel de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Als we elkaar weer zien, wil ik\n"
	.string "graag met je samen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Ik ben {STR_VAR_1}.\n"
	.string "Ik ben een HELDERZIENDE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}--\n"
	.string "zij zijn mijn leerlingen.\p"
	.string "Vind je het niet interessant\n"
	.string "om een team te vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Bedankt.\n"
	.string "Ik ga de aanmelding regelen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Ik hoop dat er nog een kans\n"
	.string "komt om samen te werken.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Ik ben SCHOLIER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1} zijn mijn duo.\p"
	.string "Mag ik alsjeblieft je maatje zijn?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, bedankt!\n"
	.string "Ik meld me meteen aan bij de balie!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Alsjeblieft?\n"
	.string "Mag ik de volgende keer mee?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hoi! Ik heet {STR_VAR_1}!\n"
	.string "Ik ben een POKéMON FOKKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "De POKéMON die ik heb gefokt zijn\n"
	.string "een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Klinkt interessant?\n"
	.string "Zullen we dan een team vormen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Prima!\n"
	.string "Laat de aanmelding maar aan mij!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "De volgende keer moet je met me\n"
	.string "samen, goed?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Ik ben {STR_VAR_1} en ik zeg trots\n"
	.string "dat ik een POKéFAN ben.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "De lieve POKéMON die ik heb\n"
	.string "gefokt zijn een {STR_VAR_2} met\l"
	.string "{STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}.\p"
	.string "Zijn ze niet superschattig?\n"
	.string "We moeten een team vormen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Bedankt, lieverd!\n"
	.string "Ik ga me aanmelden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mijn lieve POKéMON zijn de beste,\n"
	.string "weet je. Wat vervelend!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hoi, ik ben ZWEMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Een {STR_VAR_2} met {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "en een {STR_VAR_2} met\n"
	.string "{STR_VAR_1} heb ik getraind.\p"
	.string "Jij en ik, laten we een team vormen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Cool!\n"
	.string "Ik meld ons allebei aan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Als we elkaar weer zien, ben je\n"
	.string "mij een team verschuldigd!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Hoe gaat het?\n"
	.string "Ik ben {STR_VAR_1} en ik ben TRIATLEET.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Ik heb een paar goede POKéMON.\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Het zou gaaf zijn om samen een\n"
	.string "team te vormen, dus wat zeg je?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Top!\n"
	.string "Wacht even terwijl ik me aanmeld, oké?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Ik reken erop dat ik de volgende\n"
	.string "keer met je mee mag, afgesproken?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Ik ben TRIATLEET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "nog een {STR_VAR_2} die {STR_VAR_1}\n"
	.string "kan gebruiken. Dat is mijn duo.\p"
	.string "Wat vind je?\n"
	.string "We zouden een goed team zijn.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Dat antwoord bevalt me!\n"
	.string "Ik ben snel klaar met de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Je geeft me nog een kans om samen\n"
	.string "te werken, toch?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hoi! Hallo!\n"
	.string "Ik ben {STR_VAR_1} en ik ben ZWEMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Kijk eens wat ik heb getraind!\n"
	.string "Een {STR_VAR_2} met {STR_VAR_1} en$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "een {STR_VAR_2} met {STR_VAR_1}!\p"
	.string "Tof, hè?\n"
	.string "Een team vormen zou ook tof zijn!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Dank je wel!\n"
	.string "Ik regel de aanmelding!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Als we elkaar weer zien, moet je\n"
	.string "met me samen. Dat doe je toch?$"

