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

gUnknown_08674CB0:: @ 8674CB0
	.incbin "baserom.gba", 0x00674cb0, 0x2d

gText_MysteryGiftStampCard::
	.string "Thank you for using the STAMP CARD\nSystem.\pYou have {STR_VAR_1} more to collect to\nfill your STAMP CARD.$"

gUnknown_08674D3D:: @ 8674D3D
	.incbin "baserom.gba", 0x00674d3d, 0xa1

gText_MysteryGiftEgg::
	.string "Thank you for using the MYSTERY\nGIFT System.\pFrom the POKéMON CENTER we\nhave a gift--a POKéMON EGG!\pPlease raise it with love and\nkindness.$"
	.string "Oh, your party appears to be full.\pPlease come see me after storing\na POKéMON on a PC.$"

gUnknown_08674EC1:: @ 8674EC1
	.incbin "baserom.gba", 0x00674ec1, 0x29

gText_MysteryGiftVisitingTrainer::
	.string "Thank you for using the MYSTERY\nGIFT System.\pBy holding this WONDER CARD, you\nmay take part in a survey at a\lPOKéMON MART.\pUse these surveys to invite\nTRAINERS to SOOTOPOLIS CITY.\p…Let me give you a secret\npassword for a survey:\p“GIVE ME\nAWESOME TRAINER”\pWrite that in on a survey and send\nit to the WIRELESS\lCOMMUNICATION SYSTEM.$"
	.string "Thank you for using the MYSTERY\nGIFT System.\pA TRAINER has arrived in\nSOOTOPOLIS CITY looking for you.\pWe hope you will enjoy\nbattling the visiting TRAINER.\pYou may invite other TRAINERS by\nentering other passwords.\pTry looking for other passwords\nthat may work.$"

gUnknown_0867513C:: @ 867513C
	.incbin "baserom.gba", 0x0067513c, 0x48

gText_MysteryGiftBattleCountCard::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYour BATTLE COUNT CARD keeps\ntrack of your battle record against\lTRAINERS with the same CARD.\pLook for and battle TRAINERS who\nhave the same CARD as you.\pYou may check the overall rankings\nby reading the NEWS.\pPlease do give it a try!$"
	.string "Thank you for using the MYSTERY\nGIFT System.\pCongratulations!\pYou have won a prize for winning\nthree battles!\pWe hope you will be inspired to\nbattle some more.$"

gUnknown_0867533C:: @ 867533C
	.incbin "baserom.gba", 0x0067533c, 0x6d

gText_MysteryGiftTicket1::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

gUnknown_0867550B:: @ 867550B
	.incbin "baserom.gba", 0x0067550b, 0x76

gText_MysteryGiftTicket2::
	.string "Thank you for using the MYSTERY\nGIFT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"

gUnknown_086756E3:: @ 86756E3
	.incbin "baserom.gba", 0x006756e3, 0x25

gText_MysteryGiftAlteringCave::
	.string "Thank you for using the MYSTERY\nGIFT System.\pThere appears to be a rumor about\nrare POKéMON sightings.\pThe sightings reportedly came from\nthe ALTERING CAVE on ROUTE 103.\pPerhaps it would be worthwhile for\nyou to investigate this rumor.$"

gUnknown_086757F4:: @ 86757F4
	.incbin "baserom.gba", 0x006757f4, 0x6d

gText_MysteryGiftOldSeaMap::
	.string "Thank you for using the MYSTERY\nGIFT System.\pLet me confirm--you are {PLAYER}?\pWe received this OLD SEA MAP\naddressed to you.$"
	.string "It appears to be for use at the\nLILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"
	.string "Thank you for using the MYSTERY\nGIFT System.$"
	.string "Oh, I’m sorry, {PLAYER}.\nYour BAG’s KEY ITEMS POCKET is full.\pPlease store something on your PC,\nthen come back for this.$"
	.align 2
