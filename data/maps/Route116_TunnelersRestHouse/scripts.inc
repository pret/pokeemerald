Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "C’est le TUNNEL MERAZON, là-bas…\p"
	.string "Au début, de nombreux ouvriers\n"
	.string "perçaient les rochers avec d’énormes\l"
	.string "engins. Mais nous avons dû arrêter.\p"
	.string "On s’est rendu compte que les travaux\n"
	.string "avaient un effet négatif sur les\l"
	.string "POKéMON sauvages de la région.\p"
	.string "Maintenant, nous n’avons plus rien\n"
	.string "à faire, à part flâner.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Il y a un homme qui creuse un TUNNEL\n"
	.string "vers VERGAZON, tout seul.\l"
	.string "Il veut absolument passer.\p"
	.string "Il affirme que s’il creuse petit à petit\n"
	.string "sans utiliser de machine, il ne\l"
	.string "dérangera pas les POKéMON et n’abîmera\l"
	.string "pas l’écosystème environnant.\p"
	.string "Je me demande s’il a déjà fini.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Pour atteindre VERGAZON sans utiliser\n"
	.string "ce TUNNEL, tu devras naviguer jusqu’à\l"
	.string "MYOKARA, puis jusqu’à POIVRESSEL et\l"
	.string "enfin passer par LAVANDIA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Tu as entendu? Le TUNNEL pour\n"
	.string "VERGAZON est enfin terminé!\p"
	.string "Parfois, si l’on souhaite très fort\n"
	.string "quelque chose, ça se réalise.$"

