Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "MR. BRINEY: Wacht even, meid!\n"
	.string "Wacht op mij, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hm? Jij bent {PLAYER}{KUN}!\n"
	.string "Jij hebt mijn lieve PEEKO gered!\l"
	.string "We hebben zoveel aan je te danken!\p"
	.string "Wat zeg je?\n"
	.string "Wil je met me meevaren?\p"
	.string "Hmhm…\p"
	.string "Je hebt een BRIEF voor DEWFORD\n"
	.string "en een pakket voor SLATEPORT?\p"
	.string "Wat heb jij het druk!\p"
	.string "Maar natuurlijk, dat is helemaal\n"
	.string "geen probleem.\p"
	.string "Je bent bij de juiste man!\n"
	.string "We varen naar DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "MR. BRINEY: Op naar DEWFORD dan!\p"
	.string "Anker op!\n"
	.string "PEEKO, we vertrekken, lieverd!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "MR. BRINEY: O ja?\n"
	.string "Kunnen je pakketjes wachten?\p"
	.string "Zeg het maar als je wilt\n"
	.string "vertrekken!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "MR. BRINEY: Ahoi!\n"
	.string "Ik weet al wat je wilt zeggen!\p"
	.string "Je moet een BRIEF naar DEWFORD\n"
	.string "en een pakket naar SLATEPORT.\p"
	.string "Geen probleem, ik ben de man\n"
	.string "voor die klus!\p"
	.string "Eerst varen we naar DEWFORD.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "MR. BRINEY: Ahoi!\n"
	.string "Ik weet al wat je wilt zeggen!\p"
	.string "Je moet een pakket naar\n"
	.string "CAPT. STERN in SLATEPORT.\p"
	.string "Geen probleem, ik ben de man\n"
	.string "voor die klus!\p"
	.string "Eerst varen we naar DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "MR. BRINEY: Ahoi!\n"
	.string "Voor jou ga ik altijd de zee op!\p"
	.string "Zo, mijn vriend, waar gaan we heen?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY: O ja?\n"
	.string "Nou, PEEKO dankt haar leven aan jou.\p"
	.string "Zeg het maar als je wilt\n"
	.string "vertrekken!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

