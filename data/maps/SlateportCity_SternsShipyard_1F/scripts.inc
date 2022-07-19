.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
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
	.string "Hum… Si ceci va ici et si cela va là…\p"
	.string "Mais, où va cette chose?\n"
	.string "Et ça, alors?\p"
	.string "Aaargh! Ça n’a ni queue ni tête!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hum?\n"
	.string "Salut, je suis ARCHIBALD.\p"
	.string "Le CAPT. POUPE m’a chargé\n"
	.string "de concevoir un ferry.\p"
	.string "Oh! Ça, là…\n"
	.string "C’est le PACK DEVON?\p"
	.string "Mais, hum…\n"
	.string "Ça ne va pas…\p"
	.string "Le CAPT. POUPE est sorti.\n"
	.string "Il a dit qu’il avait du travail.\p"
	.string "Pourrais-tu aller trouver le\n"
	.string "CAPT. POUPE et le lui remettre?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "ARCHIBALD: Où le CAPT. POUPE peut-il\n"
	.string "bien être allé?\p"
	.string "Pourrais-tu aller trouver le CAPT.\n"
	.string "POUPE et lui remettre ce paquet?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "ARCHIBALD: Construire des bateaux est\n"
	.string "un art.\p"
	.string "Bien des choses ne peuvent être\n"
	.string "résolues rien que par des calculs.\p"
	.string "Il me faudrait les conseils d’un vieux\n"
	.string "loup de mer…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "ARCHIBALD: Salut! M. MARCO nous\n"
	.string "a rejoints pour nous proposer son aide.\p"
	.string "Grâce à l’expérience du navigateur,\n"
	.string "l’assemblage du ferry suit son cours.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "ARCHIBALD: Le ferry est enfin terminé!\p"
	.string "Le nouveau LE MARINA est une\n"
	.string "merveille de technologie. Aucun doute!\p"
	.string "Mais j’ai le sentiment que nous \n"
	.string "pouvons encore l’améliorer.\p"
	.string "Tu sais, la technologie est\n"
	.string "en perpétuelle évolution.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "M. MARCO: Ah, {PLAYER}{KUN}!\n"
	.string "Ça faisait longtemps!\p"
	.string "Hé, depuis notre dernière rencontre, le\n"
	.string "vieux loup de mer est d’humeur folâtre.\p"
	.string "Alors j’ai décidé d’aider ARCHIBALD\n"
	.string "à construire un ferry.\p"
	.string "Hé, après tout, un ferry pourra\n"
	.string "transporter plein de gens.\p"
	.string "Mais, tu sais, cet ARCHIBALD, c’est\n"
	.string "vraiment quelqu’un!\p"
	.string "Avec ses connaissances et mon\n"
	.string "expérience, je suis sûr qu’on va pouvoir\l"
	.string "construire un imposant bateau, hé, hé!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les saisons, le temps, le coefficient\n"
	.string "de marée…\p"
	.string "Ces paramètres, parmi d’autres,\n"
	.string "influent sur l’état de la mer.\p"
	.string "C’est vrai!\n"
	.string "La mer est comme un être vivant!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "J’ai facilement le mal de mer.\n"
	.string "Alors je reste souvent aider ici.$"

