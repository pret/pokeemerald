#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_scripts.h"
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
	setorcopyvar VAR_RESULT, 1
	specialvar VAR_0x8008, sub_813986C
	setorcopyvar VAR_RESULT, 0
	specialvar VAR_0x8009, sub_813986C
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
	.string "Thank you for using the STAMP CARD\nSystem.\pYou have {STR_VAR_1} more to collect to\nfill your STAMP CARD.$"

MysteryEventScript_SurfPichu:: @ 8674D3D
	setvaddress MysteryEventScript_SurfPichu
	checkflag FLAG_MYSTERY_EVENT_DONE
	vgoto_if 0, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible: @ 8674D4C
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 6
	vgoto_if 1, SurfPichu_FullParty
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
	vgoto_if 1, SurfPichu_Slot1
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 2
	vgoto_if 1, SurfPichu_Slot2
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 3
	vgoto_if 1, SurfPichu_Slot3
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 4
	vgoto_if 1, SurfPichu_Slot4
	compare_var_to_value VAR_EVENT_PICHU_SLOT, 5
	vgoto_if 1, SurfPichu_Slot5
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
	.string "Thank you for using the MYSTERY\nGIFT System.\pFrom the POKéMON CENTER we\nhave a gift--a POKéMON EGG!\pPlease raise it with love and\nkindness.$"

sText_FullParty:
	.string "Oh, your party appears to be full.\pPlease come see me after storing\na POKéMON on a PC.$"

MysteryEventScript_VisitingTrainer:: @ 8674EC1
	setvaddress MysteryEventScript_VisitingTrainer
	special ValidateEReaderTrainer
	compare_var_to_value VAR_RESULT, 0
	vgoto_if 1, MysteryEventScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer
	waitmessage
	waitbuttonpress
	release
	end

MysteryEventScript_VisitingTrainerArrived: @ 8674EDF
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer_2
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainer:
	.string "Thank you for using the MYSTERY\nGIFT System.\pBy holding this WONDER CARD, you\nmay take part in a survey at a\lPOKéMON MART.\pUse these surveys to invite\nTRAINERS to SOOTOPOLIS CITY.\p…Let me give you a secret\npassword for a survey:\p“GIVE ME\nAWESOME TRAINER”\pWrite that in on a survey and send\nit to the WIRELESS\lCOMMUNICATION SYSTEM.$"

sText_MysteryGiftVisitingTrainer_2:
	.string "Thank you for using the MYSTERY\nGIFT System.\pA TRAINER has arrived in\nSOOTOPOLIS CITY looking for you.\pWe hope you will enjoy\nbattling the visiting TRAINER.\pYou may invite other TRAINERS by\nentering other passwords.\pTry looking for other passwords\nthat may work.$"

MysteryEventScript_BattleCard:: @ 867513C
	setvaddress MysteryEventScript_BattleCard
	checkflag FLAG_MYSTERY_EVENT_DONE
	vgoto_if 1, MysteryEventScript_BattleCardInfo
	setorcopyvar VAR_RESULT, 2
	specialvar VAR_0x8008, sub_813986C
	compare_var_to_value VAR_0x8008, 3
	vgoto_if 0, MysteryEventScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_2
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
	.string "Thank you for using the MYSTERY\nGIFT System.\pYour BATTLE COUNT CARD keeps\ntrack of your battle record against\lTRAINERS with the same CARD.\pLook for and battle TRAINERS who\nhave the same CARD as you.\pYou may check the overall rankings\nby reading the NEWS.\pPlease do give it a try!$"

sText_MysteryGiftBattleCountCard_2:
	.string "Thank you for using the MYSTERY\nGIFT System.\pCongratulations!\pYou have won a prize for winning\nthree battles!\pWe hope you will be inspired to\nbattle some more.$"

MysteryEventScript_AuroraTicket:: @ 867533C
	setvaddress MysteryEventScript_AuroraTicket
	lock
	faceplayer
	checkflag FLAG_RECEIVED_AURORA_TICKET
	vgoto_if 1, AuroraTicket_Obtained
	checkflag FLAG_BATTLED_DEOXYS
	vgoto_if 1, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET, 1
	compare_var_to_value VAR_RESULT, 1
	vgoto_if 1, AuroraTicket_Obtained
	vmessage sText_AuroraTicket1
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET, 1
	compare_var_to_value VAR_RESULT, 0
	vgoto_if 1, AuroraTicket_NoBagSpace
	giveitem_std ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicket2
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace: @ 8675397
	vmessage sText_AuroraTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained: @ 86753A0
	vmessage sText_AuroraTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicket1:
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"

sText_AuroraTicket2:
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"

sText_AuroraTicketGot:
	.string "Thank you for using the MYSTERY\nGIFT System.$"

sText_AuroraTicketNoPlace:
	.string "Oh, I'm sorry, {PLAYER}.\nYour BAG's KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

MysteryEventScript_MysticTicket:: @ 867550B
	setvaddress MysteryEventScript_MysticTicket
	lock
	faceplayer
	checkflag FLAG_RECEIVED_MYSTIC_TICKET
	vgoto_if 1, MysticTicket_Obtained
	checkflag FLAG_CAUGHT_LUGIA
	vgoto_if 1, MysticTicket_Obtained
	checkflag FLAG_CAUGHT_HO_OH
	vgoto_if 1, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET, 1
	compare_var_to_value VAR_RESULT, 1
	vgoto_if 1, MysticTicket_Obtained
	vmessage sText_MysticTicket2
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET, 1
	compare_var_to_value VAR_RESULT, 0
	vgoto_if 1, MysticTicket_NoBagSpace
	giveitem_std ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicket1
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace: @ 867556F
	vmessage sText_MysticTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained: @ 8675578
	vmessage sText_MysticTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicket2:
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"

sText_MysticTicket1:
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"

sText_MysticTicketGot:
	.string "Thank you for using the MYSTERY\nGIFT System.$"

sText_MysticTicketNoPlace:
	.string "Oh, I'm sorry, {PLAYER}.\nYour BAG's KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

MysteryEventScript_AlteringCave:: @ 86756E3
	setvaddress MysteryEventScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	compare_var_to_value VAR_ALTERING_CAVE_WILD_SET, 10
	vgoto_if 0, MysteryEventScript_AlteringCave_
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
	.string "Thank you for using the MYSTERY\nGIFT System.\pThere appears to be a rumor about\nrare POKéMON sightings.\pThe sightings reportedly came from\nthe ALTERING CAVE on ROUTE 103.\pPerhaps it would be worthwhile for\nyou to investigate this rumor.$"

MysteryEventScript_OldSeaMap:: @ 86757F4
	setvaddress MysteryEventScript_OldSeaMap
	lock
	faceplayer
	checkflag FLAG_RECEIVED_OLD_SEA_MAP
	vgoto_if 1, OldSeaMap_Obtained
	checkflag FLAG_CAUGHT_MEW
	vgoto_if 1, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP, 1
	compare_var_to_value VAR_RESULT, 1
	vgoto_if 1, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMap
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP, 1
	compare_var_to_value VAR_RESULT, 0
	vgoto_if 1, OldSeaMap_NoBagSpace
	giveitem_std ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMap_1
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace: @ 867584F
	vmessage sText_MysteryGiftOldSeaMap_3
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained: @ 8675858
	vmessage sText_MysteryGiftOldSeaMap_2
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMap:
	.string "Thank you for using the MYSTERY\nGIFT System.\pLet me confirm--you are {PLAYER}?\pWe received this OLD SEA MAP\naddressed to you.$"

sText_MysteryGiftOldSeaMap_1:
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"

sText_MysteryGiftOldSeaMap_2:
	.string "Thank you for using the MYSTERY\nGIFT System.$"

sText_MysteryGiftOldSeaMap_3:
	.string "Oh, I'm sorry, {PLAYER}.\nYour BAG's KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"
