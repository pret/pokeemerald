#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"


	.section .rodata

gText_MysteryGiftBerry:: @ 8674AE4
	.string "Obtained a {STR_VAR_2} BERRY!\nDad has it at PETALBURG GYM.$"

gText_MysteryGiftBerryTransform:: @ 8674B16
	.string "The {STR_VAR_1} BERRY transformed into\none {STR_VAR_2} BERRY.$"

gText_MysteryGiftBerryObtained:: @ 8674B42
	.string "The {STR_VAR_1} BERRY has already been\nobtained.$"

gText_MysteryGiftSpecialRibbon:: @ 8674B6A
	.string "A special RIBBON was awarded to\nyour party POKéMON.$"

gText_MysteryGiftNationalDex:: @ 8674B9E
	.string "The POKéDEX has been upgraded\nwith the NATIONAL MODE.$"

gText_MysteryGiftRareWord:: @ 8674BD4
	.string "A rare word has been added.$"

gText_MysteryGiftSentOver:: @ 8674BF0
	.string "{STR_VAR_1} was sent over!$"

gText_MysteryGiftFullParty:: @ 8674C02
	.string "Your party is full.\n{STR_VAR_1} could not be sent over.$"

gText_MysteryGiftNewTrainer:: @ 8674C31
	.string "A new TRAINER has arrived in\nHOENN.$"
	.string "A new adversary has arrived in the\nBATTLE TOWER.$"

gText_MysteryGiftCantBeUsed:: @ 8674C86
	.string "This data can’t be used in\nthis version.$"
	
	.align 2
gUnknown_08674CB0:: @ 8674CB0
	setvaddress gUnknown_08674CB0
	setorcopyvar 0x800D, 1
	specialvar 0x8008, sub_813986C
	setorcopyvar 0x800D, 0
	specialvar 0x8009, sub_813986C
	subvar 0x8008, 32777
	buffernumberstring 0, 0x8008
	lock
	faceplayer
	vmessage gText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftStampCard::
	.string "Thank you for using the STAMP CARD\nSystem.\pYou have {STR_VAR_1} more to collect to\nfill your STAMP CARD.$"

gUnknown_08674D3D:: @ 8674D3D
	setvaddress gUnknown_08674D3D
	checkflag 0x1E4
	vgoto_if 0, EventScript_674D4C
	gotoram

EventScript_674D4C:: @ 8674D4C
	specialvar 0x40DD, CalculatePlayerPartyCount
	compare_var_to_value 0x40DD, 6
	vgoto_if 1, EventScript_674D73
	setflag 0x1E4
	vcall EventScript_674D7E
	lock
	faceplayer
	vmessage gText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare 370
	waitfanfare
	release
	end

EventScript_674D73:: @ 8674D73
	lock
	faceplayer
	vmessage gText_MysteryGiftEgg_2
	waitmessage
	waitbuttonpress
	release
	end

EventScript_674D7E:: @ 8674D7E
	giveegg SPECIES_PICHU
	setmonobedient 0x40DD
	setmonmetlocation 0x40DD, 255
	compare_var_to_value 0x40DD, 1
	vgoto_if 1, EventScript_674DC0
	compare_var_to_value 0x40DD, 2
	vgoto_if 1, EventScript_674DC6
	compare_var_to_value 0x40DD, 3
	vgoto_if 1, EventScript_674DCC
	compare_var_to_value 0x40DD, 4
	vgoto_if 1, EventScript_674DD2
	compare_var_to_value 0x40DD, 5
	vgoto_if 1, EventScript_674DD8
	return

EventScript_674DC0:: @ 8674DC0
	setmonmove 1, 2, 57
	return

EventScript_674DC6:: @ 8674DC6
	setmonmove 2, 2, 57
	return

EventScript_674DCC:: @ 8674DCC
	setmonmove 3, 2, 57
	return

EventScript_674DD2:: @ 8674DD2
	setmonmove 4, 2, 57
	return

EventScript_674DD8:: @ 8674DD8
	setmonmove 5, 2, 57
	return

gText_MysteryGiftEgg::
	.string "Thank you for using the MYSTERY\nGIFT System.\pFrom the POKéMON CENTER we\nhave a gift--a POKéMON EGG!\pPlease raise it with love and\nkindness.$"
	
gText_MysteryGiftEgg_2::
	.string "Oh, your party appears to be full.\pPlease come see me after storing\na POKéMON on a PC.$"

gUnknown_08674EC1:: @ 8674EC1
	setvaddress gUnknown_08674EC1
	special sub_81652B4
	compare_var_to_value 0x800D, 0
	vgoto_if 1, EventScript_674EDF
	lock
	faceplayer
	vmessage gText_MysteryGiftVisitingTrainer
	waitmessage
	waitbuttonpress
	release
	end

EventScript_674EDF:: @ 8674EDF
	lock
	faceplayer
	vmessage gText_MysteryGiftVisitingTrainer_2
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftVisitingTrainer::
	.string "Thank you for using the MYSTERY\nGIFT System.\pBy holding this WONDER CARD, you\nmay take part in a survey at a\lPOKéMON MART.\pUse these surveys to invite\nTRAINERS to SOOTOPOLIS CITY.\p…Let me give you a secret\npassword for a survey:\p“GIVE ME\nAWESOME TRAINER”\pWrite that in on a survey and send\nit to the WIRELESS\lCOMMUNICATION SYSTEM.$"
	
gText_MysteryGiftVisitingTrainer_2::
	.string "Thank you for using the MYSTERY\nGIFT System.\pA TRAINER has arrived in\nSOOTOPOLIS CITY looking for you.\pWe hope you will enjoy\nbattling the visiting TRAINER.\pYou may invite other TRAINERS by\nentering other passwords.\pTry looking for other passwords\nthat may work.$"

gUnknown_0867513C:: @ 867513C
	setvaddress gUnknown_0867513C
	checkflag 0x1E4
	vgoto_if 1, EventScript_675179
	setorcopyvar 0x800D, 2
	specialvar 0x8008, sub_813986C
	compare_var_to_value 0x8008, 3
	vgoto_if 0, EventScript_675179
	lock
	faceplayer
	vmessage gText_MysteryGiftBattleCountCard_2
	waitmessage
	waitbuttonpress
	giveitem_std 13
	release
	setflag 0x1E4
	end

EventScript_675179:: @ 8675179
	lock
	faceplayer
	vmessage gText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftBattleCountCard::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYour BATTLE COUNT CARD keeps\ntrack of your battle record against\lTRAINERS with the same CARD.\pLook for and battle TRAINERS who\nhave the same CARD as you.\pYou may check the overall rankings\nby reading the NEWS.\pPlease do give it a try!$"
	
gText_MysteryGiftBattleCountCard_2::
	.string "Thank you for using the MYSTERY\nGIFT System.\pCongratulations!\pYou have won a prize for winning\nthree battles!\pWe hope you will be inspired to\nbattle some more.$"

gUnknown_0867533C:: @ 867533C
	setvaddress gUnknown_0867533C
	lock
	faceplayer
	checkflag 0x13A
	vgoto_if 1, EventScript_6753A0
	checkflag 0x1AD
	vgoto_if 1, EventScript_6753A0
	checkitem 371, 1
	compare_var_to_value 0x800D, 1
	vgoto_if 1, EventScript_6753A0
	vmessage gText_MysteryGiftTicket1
	waitmessage
	waitbuttonpress
	checkitemspace 371, 1
	compare_var_to_value 0x800D, 0
	vgoto_if 1, EventScript_675397
	giveitem_std 371
	setflag 0x8D5
	setflag 0x13A
	vmessage gText_MysteryGiftTicket1_1
	waitmessage
	waitbuttonpress
	release
	end

EventScript_675397:: @ 8675397
	vmessage gText_MysteryGiftTicket1_3
	waitmessage
	waitbuttonpress
	release
	end

EventScript_6753A0:: @ 86753A0
	vmessage gText_MysteryGiftTicket1_2
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftTicket1::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"
	
gText_MysteryGiftTicket1_1::
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	
gText_MysteryGiftTicket1_2::	
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	
gText_MysteryGiftTicket1_3::
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

gUnknown_0867550B:: @ 867550B
	setvaddress gUnknown_0867550B
	lock
	faceplayer
	checkflag 0x13B
	vgoto_if 1, EventScript_675578
	checkflag 0x91
	vgoto_if 1, EventScript_675578
	checkflag 0x92
	vgoto_if 1, EventScript_675578
	checkitem 370, 1
	compare_var_to_value 0x800D, 1
	vgoto_if 1, EventScript_675578
	vmessage gText_MysteryGiftTicket2
	waitmessage
	waitbuttonpress
	checkitemspace 370, 1
	compare_var_to_value 0x800D, 0
	vgoto_if 1, EventScript_67556F
	giveitem_std 370
	setflag 0x8E0
	setflag 0x13B
	vmessage gText_MysteryGiftTicket2_1
	waitmessage
	waitbuttonpress
	release
	end

EventScript_67556F:: @ 867556F
	vmessage gText_MysteryGiftTicket2_3
	waitmessage
	waitbuttonpress
	release
	end

EventScript_675578:: @ 8675578
	vmessage gText_MysteryGiftTicket2_2
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftTicket2::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"
	
gText_MysteryGiftTicket2_1::
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	
gText_MysteryGiftTicket2_2::
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	
gText_MysteryGiftTicket2_3::
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

gUnknown_086756E3:: @ 86756E3
	setvaddress gUnknown_086756E3
	addvar 0x403E, 1
	compare_var_to_value 0x403E, 10
	vgoto_if 0, EventScript_6756FD
	setvar 0x403E, 0

EventScript_6756FD:: @ 86756FD
	lock
	faceplayer
	vmessage gText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftAlteringCave::
	.string "Thank you for using the MYSTERY\nGIFT System.\pThere appears to be a rumor about\nrare POKéMON sightings.\pThe sightings reportedly came from\nthe ALTERING CAVE on ROUTE 103.\pPerhaps it would be worthwhile for\nyou to investigate this rumor.$"

gUnknown_086757F4:: @ 86757F4
	setvaddress gUnknown_086757F4
	lock
	faceplayer
	checkflag 0x13C
	vgoto_if 1, EventScript_675858
	checkflag 0x1CA
	vgoto_if 1, EventScript_675858
	checkitem 376, 1
	compare_var_to_value 0x800D, 1
	vgoto_if 1, EventScript_675858
	vmessage gText_MysteryGiftOldSeaMap
	waitmessage
	waitbuttonpress
	checkitemspace 376, 1
	compare_var_to_value 0x800D, 0
	vgoto_if 1, EventScript_67584F
	giveitem_std 376
	setflag 0x8D6
	setflag 0x13C
	vmessage gText_MysteryGiftOldSeaMap_1
	waitmessage
	waitbuttonpress
	release
	end

EventScript_67584F:: @ 867584F
	vmessage gText_MysteryGiftOldSeaMap_3
	waitmessage
	waitbuttonpress
	release
	end

EventScript_675858:: @ 8675858
	vmessage gText_MysteryGiftOldSeaMap_2
	waitmessage
	waitbuttonpress
	release
	end

gText_MysteryGiftOldSeaMap::
	.string "Thank you for using the MYSTERY\nGIFT System.\pLet me confirm--you are {PLAYER}?\pWe received this OLD SEA MAP\naddressed to you.$"
	
gText_MysteryGiftOldSeaMap_1::
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	
gText_MysteryGiftOldSeaMap_2::
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	
gText_MysteryGiftOldSeaMap_3::
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"
	.align 2
