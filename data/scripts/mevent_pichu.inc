MysteryEventScript_SurfPichu:: @ 8674D3D
	setvaddress MysteryEventScript_SurfPichu
	vgoto_if_unset FLAG_MYSTERY_EVENT_DONE, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible: @ 8674D4C
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
	compare VAR_EVENT_PICHU_SLOT, PARTY_SIZE
	vgoto_if_eq SurfPichu_FullParty
	setflag FLAG_MYSTERY_EVENT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
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
	compare VAR_EVENT_PICHU_SLOT, 1
	vgoto_if_eq SurfPichu_Slot1
	compare VAR_EVENT_PICHU_SLOT, 2
	vgoto_if_eq SurfPichu_Slot2
	compare VAR_EVENT_PICHU_SLOT, 3
	vgoto_if_eq SurfPichu_Slot3
	compare VAR_EVENT_PICHU_SLOT, 4
	vgoto_if_eq SurfPichu_Slot4
	compare VAR_EVENT_PICHU_SLOT, 5
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
