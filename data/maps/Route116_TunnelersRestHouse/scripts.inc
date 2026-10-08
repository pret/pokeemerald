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
	.string "Die RUSTURF TUNNEL daar…\p"
	.string "Eerst groeven we met een grote ploeg\n"
	.string "en de nieuwste machines door de rots.\l"
	.string "Maar we moesten stoppen.\p"
	.string "Het bleek slecht te zijn voor de\n"
	.string "wilde POKéMON in de buurt.\p"
	.string "Dus nu hangen we hier maar wat\n"
	.string "rond en doen we niks.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Er is een man die helemaal alleen\n"
	.string "een gang graaft naar VERDANTURF.\l"
	.string "Hij wil er heel graag doorheen.\p"
	.string "Hij zegt: als hij beetje bij beetje\n"
	.string "graaft zonder machines, stoort hij\l"
	.string "de POKéMON niet en blijft de\l"
	.string "natuur heel.\p"
	.string "Zou hij er al doorheen zijn?$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Wil je naar VERDANTURF zonder deze\n"
	.string "TUNNEL? Dan moet je over zee naar\l"
	.string "DEWFORD, door naar SLATEPORT,\l"
	.string "en dan via MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Heb je het gehoord? De TUNNEL naar\n"
	.string "VERDANTURF is klaar!\p"
	.string "Als je maar hard genoeg hoopt,\n"
	.string "komen dromen soms echt uit.$"

