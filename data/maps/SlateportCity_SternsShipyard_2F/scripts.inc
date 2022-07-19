SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Concevoir un grand bateau relève plus\n"
	.string "de la construction d’un vaste bâtiment\l"
	.string "que de l’assemblage d’un véhicule.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "C’est étrange qu’un bateau fait d’acier\n"
	.string "puisse flotter, non?\p"
	.string "S’il flotte, c’est dû à ce que l’on\n"
	.string "appelle le principe de flottabilité.$"

