SlateportCity_SternsShipyard_2F_MapScripts:: @ 820863D
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1:: @ 820863E
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2:: @ 8208647
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding: @ 8208650
	.string "Designing a large ship is more like\n"
	.string "making a big building than putting\l"
	.string "together a transportation vehicle.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy: @ 82086BA
	.string "Don't you think it's strange that\n"
	.string "a ship made of heavy iron floats?\p"
	.string "It floats because of a principle\n"
	.string "called buoyancy.$"

