SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Eh… Als dit hier hoort, en dat\n"
	.string "daar…\p"
	.string "Waar moet dit ding dan heen?\n"
	.string "En dat friemelding?\p"
	.string "Aaargh! Ik snap er helemaal\n"
	.string "niks van!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Hoi, ik ben DOCK.\p"
	.string "CAPT. STERN vroeg mij om een\n"
	.string "veerboot te ontwerpen.\p"
	.string "O! Dat daar…\n"
	.string "Is dat het DEVONPAKKET?\p"
	.string "Maar, hmm…\n"
	.string "Dat gaat zo niet…\p"
	.string "CAPT. STERN is ergens heen.\n"
	.string "Hij moest nog wat werk doen.\p"
	.string "Wil jij CAPT. STERN zoeken en\n"
	.string "het aan hem geven?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Waar zou CAPT. STERN\n"
	.string "naartoe zijn?\p"
	.string "Wil jij CAPT. STERN zoeken en\n"
	.string "dat pakket aan hem geven?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Schepen bouwen is een kunst.\p"
	.string "Veel dingen kun je niet zomaar\n"
	.string "uitrekenen.\p"
	.string "Ik heb echt tips nodig van een oude\n"
	.string "zeerot die de zee goed kent…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Hoi! MR. BRINEY helpt\n"
	.string "ons nu mee.\p"
	.string "Dankzij die oude zeeman komt de\n"
	.string "veerboot steeds verder af.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: De veerboot is eindelijk klaar!\p"
	.string "De nieuwe S.S. TIDAL is echt een\n"
	.string "wonder van techniek!\p"
	.string "Maar ik denk dat we iets nog\n"
	.string "beters kunnen maken.\p"
	.string "Weet je, techniek gaat altijd\n"
	.string "maar door.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "Dat is lang geleden!\p"
	.string "Ja, sinds ik jou ken, voelt deze\n"
	.string "oude zeerot zich weer jong!\p"
	.string "Dus ik help DOCK om een\n"
	.string "veerboot te maken.\p"
	.string "Ja, want een veerboot kan heel\n"
	.string "veel mensen meenemen.\p"
	.string "Maar weet je, die DOCK is echt\n"
	.string "iets bijzonders.\p"
	.string "Met zijn slimme techniek en mijn\n"
	.string "ervaring bouwen we vast een\l"
	.string "geweldig schip, jawel!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "De seizoenen, het weer, waar de\n"
	.string "maan aan de hemel staat…\p"
	.string "Door dat soort dingen ziet de\n"
	.string "zee er steeds anders uit.\p"
	.string "Precies!\n"
	.string "De zee is net een levend wezen!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Ik word heel snel zeeziek.\n"
	.string "Daarom help ik hier mee.$"

