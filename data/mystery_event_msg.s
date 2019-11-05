#include "constants/global.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_scripts.h"
#include "constants/mevent.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2

MysteryEventScript_StampCard:: @ 8674CB0
	setvaddress MysteryEventScript_StampCard
	setorcopyvar VAR_RESULT, GET_MAX_STAMPS
	specialvar VAR_0x8008, GetMysteryEventCardVal
	setorcopyvar VAR_RESULT, GET_NUM_STAMPS
	specialvar VAR_0x8009, GetMysteryEventCardVal
	subvar VAR_0x8008, VAR_0x8009
	buffernumberstring 0, VAR_0x8008
	lock
	faceplayer
	vmessage sText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftStampCard:
	.string "Thank you for using the STAMP CARD\n"
	.string "System.\p"
	.string "You have {STR_VAR_1} more to collect to\n"
	.string "fill your STAMP CARD.$"

MysteryEventScript_SurfPichu:: @ 8674D3D
	setvaddress MysteryEventScript_SurfPichu
	checkflag FLAG_MYSTERY_EVENT_DONE
	vgoto_if_ne SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible: @ 8674D4C
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
	compare_var_to_value VAR_EVENT_PICHU_SLOT, PARTY_SIZE
	vgoto_if_eq SurfPichu_FullParty
	setflag FLAG_MYSTERY_EVENT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_FANFA4
	waitfanfare
	release
	end

SurfPichu_FullParty: @ 8674D73
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfPichu_GiveEgg: @ 8674D7E
	giveegg SPECIES_PICHU
	setmonobedient VAR_EVENT_PICHU_SLOT
	setmonmetlocation VAR_EVENT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 1
	vgoto_if_eq SurfPichu_Slot1
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 2
	vgoto_if_eq SurfPichu_Slot2
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 3
	vgoto_if_eq SurfPichu_Slot3
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 4
	vgoto_if_eq SurfPichu_Slot4
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 5
	vgoto_if_eq SurfPichu_Slot5
	return

SurfPichu_Slot1: @ 8674DC0
	setmonmove 1, 2, MOVE_SURF
	return

SurfPichu_Slot2:: @ 8674DC6
	setmonmove 2, 2, MOVE_SURF
	return

SurfPichu_Slot3: @ 8674DCC
	setmonmove 3, 2, MOVE_SURF
	return

SurfPichu_Slot4: @ 8674DD2
	setmonmove 4, 2, MOVE_SURF
	return

SurfPichu_Slot5: @ 8674DD8
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "From the POKéMON CENTER we\n"
	.string "have a gift--a POKéMON EGG!\p"
	.string "Please raise it with love and\n"
	.string "kindness.$"

sText_FullParty:
	.string "Oh, your party appears to be full.\p"
	.string "Please come see me after storing\n"
	.string "a POKéMON on a PC.$"

MysteryEventScript_VisitingTrainer:: @ 8674EC1
	setvaddress MysteryEventScript_VisitingTrainer
	special ValidateEReaderTrainer
	compare_var_to_value VAR_RESULT, 0
	vgoto_if_eq MysteryEventScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryEventScript_VisitingTrainerArrived: @ 8674EDF
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "By holding this WONDER CARD, you\n"
	.string "may take part in a survey at a\l"
	.string "POKéMON MART.\p"
	.string "Use these surveys to invite\n"
	.string "TRAINERS to SOOTOPOLIS CITY.\p"
	.string "…Let me give you a secret\n"
	.string "password for a survey:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Write that in on a survey and send\n"
	.string "it to the WIRELESS\l"
	.string "COMMUNICATION SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "A TRAINER has arrived in\n"
	.string "SOOTOPOLIS CITY looking for you.\p"
	.string "We hope you will enjoy\n"
	.string "battling the visiting TRAINER.\p"
	.string "You may invite other TRAINERS by\n"
	.string "entering other passwords.\p"
	.string "Try looking for other passwords\n"
	.string "that may work.$"

MysteryEventScript_BattleCard:: @ 867513C
	setvaddress MysteryEventScript_BattleCard
	checkflag FLAG_MYSTERY_EVENT_DONE
	vgoto_if_eq MysteryEventScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryEventCardVal
	compare_var_to_value VAR_0x8008, REQUIRED_CARD_BATTLES
	vgoto_if_ne MysteryEventScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem_std ITEM_POTION
	release
	setflag FLAG_MYSTERY_EVENT_DONE
	end

MysteryEventScript_BattleCardInfo: @ 8675179
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Your BATTLE COUNT CARD keeps\n"
	.string "track of your battle record against\l"
	.string "TRAINERS with the same CARD.\p"
	.string "Look for and battle TRAINERS who\n"
	.string "have the same CARD as you.\p"
	.string "You may check the overall rankings\n"
	.string "by reading the NEWS.\p"
	.string "Please do give it a try!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Congratulations!\p"
	.string "You have won a prize for winning\n"
	.string "three battles!\p"
	.string "We hope you will be inspired to\n"
	.string "battle some more.$"

MysteryEventScript_AuroraTicket:: @ 867533C
	setvaddress MysteryEventScript_AuroraTicket
	lock
	faceplayer
	checkflag FLAG_RECEIVED_AURORA_TICKET
	vgoto_if_eq AuroraTicket_Obtained
	checkflag FLAG_BATTLED_DEOXYS
	vgoto_if_eq AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET, 1
	compare_var_to_value VAR_RESULT, TRUE
	vgoto_if_eq AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET, 1
	compare_var_to_value VAR_RESULT, FALSE
	vgoto_if_eq AuroraTicket_NoBagSpace
	giveitem_std ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace: @ 8675397
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained: @ 86753A0
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "You must be {PLAYER}.\n"
	.string "There is a ticket here for you.$"

sText_AuroraTicketUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_AuroraTicketThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_AuroraTicketBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"

MysteryEventScript_MysticTicket:: @ 867550B
	setvaddress MysteryEventScript_MysticTicket
	lock
	faceplayer
	checkflag FLAG_RECEIVED_MYSTIC_TICKET
	vgoto_if_eq MysticTicket_Obtained
	checkflag FLAG_CAUGHT_LUGIA
	vgoto_if_eq MysticTicket_Obtained
	checkflag FLAG_CAUGHT_HO_OH
	vgoto_if_eq MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET, 1
	compare_var_to_value VAR_RESULT, TRUE
	vgoto_if_eq MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET, 1
	compare_var_to_value VAR_RESULT, FALSE
	vgoto_if_eq MysticTicket_NoBagSpace
	giveitem_std ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace: @ 867556F
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained: @ 8675578
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "You must be {PLAYER}.\n"
	.string "There is a ticket here for you.$"

sText_MysticTicketUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_MysticTicketThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_MysticTicketBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"

MysteryEventScript_AlteringCave:: @ 86756E3
	setvaddress MysteryEventScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	compare_var_to_value VAR_ALTERING_CAVE_WILD_SET, 10
	vgoto_if_ne MysteryEventScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryEventScript_AlteringCave_: @ 86756FD
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave::
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "There appears to be a rumor about\n"
	.string "rare POKéMON sightings.\p"
	.string "The sightings reportedly came from\n"
	.string "the ALTERING CAVE on ROUTE 103.\p"
	.string "Perhaps it would be worthwhile for\n"
	.string "you to investigate this rumor.$"

MysteryEventScript_OldSeaMap:: @ 86757F4
	setvaddress MysteryEventScript_OldSeaMap
	lock
	faceplayer
	checkflag FLAG_RECEIVED_OLD_SEA_MAP
	vgoto_if_eq OldSeaMap_Obtained
	checkflag FLAG_CAUGHT_MEW
	vgoto_if_eq OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP, 1
	compare_var_to_value VAR_RESULT, TRUE
	vgoto_if_eq OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP, 1
	compare_var_to_value VAR_RESULT, FALSE
	vgoto_if_eq OldSeaMap_NoBagSpace
	giveitem_std ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace: @ 867584F
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained: @ 8675858
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Let me confirm--you are {PLAYER}?\p"
	.string "We received this OLD SEA MAP\n"
	.string "addressed to you.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
