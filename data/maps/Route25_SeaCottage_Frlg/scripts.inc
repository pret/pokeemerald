.equ BILL_IN_TELEPORTER,     FLAG_TEMP_2
.equ RETURN_AFTER_SS_TICKET, FLAG_TEMP_3

Route25_SeaCottage_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_SeaCottage_OnTransition
	.byte 0

Route25_SeaCottage_OnTransition::
	call_if_unset FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_HideClefairyBill
	call_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket
	end

Route25_SeaCottage_EventScript_HideClefairyBill::
	clearflag FLAG_HIDE_BILL_CLEFAIRY
	setobjectxyperm LOCALID_BILL_HUMAN, 3, 3
	return

Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket::
	setflag RETURN_AFTER_SS_TICKET
	return

Route25_SeaCottage_EventScript_Bill::
	lock
	faceplayer
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_BillGoToSSAnne
	goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_BillGiveSSTicket
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillAskForHelpMale
	goto_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillAskForHelpFemale
	end

Route25_SeaCottage_EventScript_BillAskForHelpMale::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_BillAskForHelpFemale::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutLady, MSGBOX_YESNO
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_BillAskForHelp::
	call_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_DeclineHelpBill
	msgbox Route25_SeaCottage_Text_RunCellSeparationOnPC
	closemessage
	delay 10
	call_if_eq VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth
	call_if_eq VAR_FACING, DIR_NORTH, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	call_if_eq VAR_FACING, DIR_WEST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	call_if_eq VAR_FACING, DIR_EAST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillEnterTeleporter
	waitmovement 0
	removeobject LOCALID_BILL_CLEFAIRY
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	waitdooranim
	setflag BILL_IN_TELEPORTER
	release
	end

@ Just returns after message, execution continues as if player had said yes
Route25_SeaCottage_EventScript_DeclineHelpBill::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_DeclineHelpBillMale
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_DeclineHelpBillFemale
	return

Route25_SeaCottage_EventScript_DeclineHelpBillMale::
	msgbox Route25_SeaCottage_Text_NoPleaseChief
	return

Route25_SeaCottage_EventScript_DeclineHelpBillFemale::
	msgbox Route25_SeaCottage_Text_NoPleaseBeautiful
	return

Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporterSouth
	waitmovement 0
	return

Route25_SeaCottage_EventScript_BillWalkToTeleporter::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporter
	waitmovement 0
	return

Route25_SeaCottage_EventScript_BillGoToSSAnne::
	msgbox Route25_SeaCottage_Text_SSAnnePartyYouGoInstead
	release
	end

Route25_SeaCottage_EventScript_BillGiveSSTicket::
	famechecker FAMECHECKER_BILL, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillThanksMale
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillThanksFemale
	checkitemspace ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, Route25_SeaCottage_EventScript_NoRoomForSSTicket
	giveitem_msg Route25_SeaCottage_Text_ReceivedSSTicketFromBill, ITEM_SS_TICKET, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_SS_TICKET_DUP
	setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
	setflag FLAG_GOT_SS_TICKET
	setflag FLAG_SYS_PC_LANETTE
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_BillThanksMale::
	msgbox Route25_SeaCottage_Text_ThanksBudTakeThis
	return

Route25_SeaCottage_EventScript_BillThanksFemale::
	msgbox Route25_SeaCottage_Text_ThanksLadyTakeThis
	return

Route25_SeaCottage_EventScript_NoRoomForSSTicket::
	msgbox Route25_SeaCottage_Text_YouveGotTooMuchStuff
	release
	end

Route25_SeaCottage_EventScript_BillGoLookAtPC::
	msgbox Route25_SeaCottage_Text_CheckOutRareMonsOnPC
	release
	end

Route25_SeaCottage_Movement_BillWalkToTeleporter::
	walk_up
	walk_up
	step_end

Route25_SeaCottage_Movement_BillWalkToTeleporterSouth::
	walk_right
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_up
	step_end

Route25_SeaCottage_Movement_BillEnterTeleporter::
	walk_up
	step_end

Route25_SeaCottage_EventScript_Computer::
	lockall
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_OpenBillsMonList
	goto_if_set BILL_IN_TELEPORTER, Route25_SeaCottage_EventScript_RunCellSeparator
	msgbox Route25_SeaCottage_Text_TeleporterIsDisplayed
	releaseall
	end

Route25_SeaCottage_EventScript_RunCellSeparator::
	fadeoutbgm 0
	msgbox Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator
	closemessage
	clearflag BILL_IN_TELEPORTER
	setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanToTeleporters
	waitmovement 0
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	waitse
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	opendoor 3, 3
	waitdooranim
	fadeinbgm 0
	addobject LOCALID_BILL_HUMAN
	clearflag FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
	delay 50
	playfanfare MUS_LEVEL_UP
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillExitTeleporter
	waitmovement 0
	waitfanfare
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanBackFromTeleporters
	waitmovement 0
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	waitdooranim
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom
	waitmovement 0
	special RemoveCameraObject
	releaseall
	end

Route25_SeaCottage_EventScript_PlayTeleporterBeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_SeaCottage_Movement_CameraPanToTeleporters::
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_SeaCottage_Movement_CameraPanBackFromTeleporters::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_EventScript_OpenBillsMonList::
	msgbox Route25_SeaCottage_Text_BillsFavoriteMonList
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_BillsMonList::
	message Route25_SeaCottage_Text_SeeWhichMon
	waitmessage
	multichoice 0, 0, MULTI_EEVEELUTIONS, FALSE
	switch VAR_RESULT
	case 0, Route25_SeaCottage_EventScript_ViewEevee
	case 1, Route25_SeaCottage_EventScript_ViewFlareon
	case 2, Route25_SeaCottage_EventScript_ViewJolteon
	case 3, Route25_SeaCottage_EventScript_ViewVaporeon
	case 4, Route25_SeaCottage_EventScript_ExitBillsMonList
	case 127, Route25_SeaCottage_EventScript_ExitBillsMonList
	end

Route25_SeaCottage_EventScript_ViewEevee::
	showmonpic SPECIES_EEVEE, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_EEVEE
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewFlareon::
	showmonpic SPECIES_FLAREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_FLAREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewJolteon::
	showmonpic SPECIES_JOLTEON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_JOLTEON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewVaporeon::
	showmonpic SPECIES_VAPOREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_VAPOREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ExitBillsMonList::
	releaseall
	end

Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Route25_SeaCottage_Movement_BillExitTeleporter::
	walk_down
	step_end

Route25_SeaCottage_Text_ImBillHelpMeOutPal::
	.string "Hiya! I'm a POKéMON…\n"
	.string "…No I'm not!\p"
	.string "Call me BILL!\n"
	.string "I'm a true-blue POKéMANIAC!\p"
	.string "Hey!\n"
	.string "What's with that skeptical look?\p"
	.string "I'm not joshing you, pal.\p"
	.string "I screwed up an experiment and got\n"
	.string "combined with a POKéMON!\p"
	.string "So, how about it?\n"
	.string "Help me out here!$"

Route25_SeaCottage_Text_ImBillHelpMeOutLady::
	.string "Hiya! I'm a POKéMON…\n"
	.string "…No I'm not!\p"
	.string "Call me BILL!\n"
	.string "I'm a true-blue POKéMANIAC!\p"
	.string "Hey!\n"
	.string "What's with that skeptical look?\p"
	.string "I'm not joshing you, lady.\p"
	.string "I screwed up an experiment and got\n"
	.string "combined with a POKéMON!\p"
	.string "So, how about it?\n"
	.string "Help me out here!$"

Route25_SeaCottage_Text_RunCellSeparationOnPC::
	.string "Wait till I get inside the\n"
	.string "TELEPORTER.\p"
	.string "When I do, go to my PC and run\n"
	.string "the Cell Separation System.$"

Route25_SeaCottage_Text_NoPleaseChief::
	.string "No!?\n"
	.string "Now don't be so cold!\p"
	.string "Come on, you gotta help a guy in\n"
	.string "deep, deep trouble!\p"
	.string "What do you say, chief?\n"
	.string "Please?\l"
	.string "Okay?\l"
	.string "All right!$"

Route25_SeaCottage_Text_NoPleaseBeautiful::
	.string "No!?\n"
	.string "Now don't be so cold!\p"
	.string "Come on, you gotta help a guy in\n"
	.string "deep, deep trouble!\p"
	.string "What do you say, beautiful?\n"
	.string "Please?\l"
	.string "Okay?\l"
	.string "All right!$"

Route25_SeaCottage_Text_ThanksBudTakeThis::
	.string "BILL: Yeehah!\n"
	.string "Thanks, bud! I owe you one!\p"
	.string "So, did you come to see my\n"
	.string "POKéMON collection?\p"
	.string "You didn't?\n"
	.string "That's a bummer.\p"
	.string "I've got to thank you…\n"
	.string "Oh, here, maybe this'll do.$"

Route25_SeaCottage_Text_ThanksLadyTakeThis::
	.string "BILL: Yeehah!\n"
	.string "Thanks, lady! I owe you one!\p"
	.string "So, did you come to see my\n"
	.string "POKéMON collection?\p"
	.string "You didn't?\n"
	.string "That's a bummer.\p"
	.string "I've got to thank you…\n"
	.string "Oh, here, maybe this'll do.$"

Route25_SeaCottage_Text_ReceivedSSTicketFromBill::
	.string "{PLAYER} received an S.S. TICKET\n"
	.string "from BILL.$"

Route25_SeaCottage_Text_YouveGotTooMuchStuff::
	.string "You've got too much stuff!$"

Route25_SeaCottage_Text_SSAnnePartyYouGoInstead::
	.string "That cruise ship S.S. ANNE is in\n"
	.string "VERMILION CITY.\p"
	.string "I hear there are lots of TRAINERS\n"
	.string "on board, too.\p"
	.string "They invited me to their party, but\n"
	.string "I can't stand fancy do's.\p"
	.string "Why don't you go instead of me?\n"
	.string "Go on and have a good time.$"

Route25_SeaCottage_Text_CheckOutRareMonsOnPC::
	.string "BILL: Feel like checking out some\n"
	.string "of my rare POKéMON on my PC?\p"
	.string "Go on, check out my PC.$"

Route25_SeaCottage_Text_TeleporterIsDisplayed::
	.string "TELEPORTER is displayed on the PC\n"
	.string "monitor.$"

Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator::
	.string "{PLAYER} initiated the TELEPORTER's\n"
	.string "Cell Separator.$"

Route25_SeaCottage_Text_BillsFavoriteMonList::
	.string "BILL's favorite POKéMON list!$"

Route25_SeaCottage_Text_SeeWhichMon::
	.string "Which POKéMON do you want to see?$"

