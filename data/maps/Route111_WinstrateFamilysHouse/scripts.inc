Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applywaitmovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Jij bent de eerste TRAINER die ik zie\n"
	.string "die POKéMON zo goed inzet.\p"
	.string "Maar ik zeg je--mijn zoon is\n"
	.string "sterker dan jij.\p"
	.string "Hij heeft zelfs de POKéMON LEAGUE\n"
	.string "uitgedaagd, weet je.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Met deze MACHOBAND trainen we\n"
	.string "onze POKéMON nog beter.\p"
	.string "Je hebt ons allemaal verslagen, dus\n"
	.string "misschien heb je hem niet nodig. Maar\l"
	.string "we geven je graag onze MACHOBAND.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Bij POKéMON-gevechten gaan we\n"
	.string "altijd helemaal los.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mama is sterker dan papa.\p"
	.string "Ik ben sterker dan mama.\p"
	.string "En oma is sterker dan ik!\p"
	.string "Maar mijn grote broer is nog\n"
	.string "sterker dan oma.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Je bent sterk, dat is zeker.\p"
	.string "Maar tegen mijn kleinzoon zou je\n"
	.string "huilen van boosheid.\p"
	.string "Hij is veel sterker dan elke TRAINER\n"
	.string "die wij kennen.\p"
	.string "Hij daagt nu vast de KAMPIOEN van\n"
	.string "de POKéMON LEAGUE uit.\p"
	.string "Ik ken mijn kleinzoon. Misschien is\n"
	.string "hij al KAMPIOEN!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mijn kleinzoon daagt nu vast de\n"
	.string "KAMPIOEN van de POKéMON LEAGUE uit.\p"
	.string "Ik ken mijn kleinzoon. Misschien is\n"
	.string "hij al KAMPIOEN!$"

