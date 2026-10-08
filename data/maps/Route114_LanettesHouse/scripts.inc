Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Sorry dat het zo'n rommel is…\n"
	.string "Als ik met onderzoek bezig ben,\l"
	.string "wordt het altijd zo…\p"
	.string "Dit is gênant… Hou het geheim,\n"
	.string "en dan krijg je dit van me.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Mag ik je een tip geven over mijn\n"
	.string "POKéMON-opslagsysteem?\p"
	.string "Ruim je BOXES goed op. Dan weet je\n"
	.string "welke POKéMON erin zitten.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Dit zijn de notities van LANETTE.\n"
	.string "Het gaat over BOXES.\p"
	.string "In elke BOX passen 30 POKéMON.\p"
	.string "Elke TRAINER moet 420 POKéMON in\n"
	.string "het PC-systeem kunnen bewaren.\p"
	.string "Verder lezen?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Met tekentjes moet je POKéMON\n"
	.string "makkelijker kunnen ordenen.\p"
	.string "De naam en het behang van elke BOX\n"
	.string "kun je veranderen. Dat vinden de\l"
	.string "POKéMON in de BOX vast fijn.\p"
	.string "Verder lezen?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Een nieuwe POKéMON gaat naar\n"
	.string "de BOX die je het laatst bekeek.\p"
	.string "Is die BOX vol? Dan gaat de POKéMON\n"
	.string "naar de volgende BOX.\p"
	.string "Dus: de BOX die je bekijkt, wordt\n"
	.string "vanzelf de BOX waar nieuwe\l"
	.string "POKéMON naartoe gaan.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} doet het schrift dicht.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Er staat een e-mail op de PC.\p"
	.string "“… … … … … … …\p"
	.string "“Jouw opslagsysteem is handiger\n"
	.string "dan dat van mij.\p"
	.string "“Het heeft veel slimme dingen.\n"
	.string "Daardoor is het leuk en handig.\p"
	.string "“Ik ben trots dat ik heb\n"
	.string "meegeholpen.\p"
	.string "“Ik hoop dat je verder gaat met\n"
	.string "je onderzoek naar opslagsystemen.\p"
	.string "“Groetjes, BILL\n"
	.string "… … … … … … … …”$"

