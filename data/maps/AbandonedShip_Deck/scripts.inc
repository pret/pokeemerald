AbandonedShip_Deck_MapScripts:: @ 823799A
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	.byte 0

AbandonedShip_Deck_OnTransition: @ 82379A0
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end

