Route127_MapConnectionsList: @ 8486BE8
	connection up, 0, MAP_MOSSDEEP_CITY
	connection down, 0, MAP_ROUTE128
	connection left, 0, MAP_ROUTE126
	connection dive, 0, MAP_UNDERWATER3

Route127_MapConnections: @ 8486C18
	.4byte 0x4
	.4byte Route127_MapConnectionsList

