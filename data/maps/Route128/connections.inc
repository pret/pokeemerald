Route128_MapConnectionsList:
	connection up, 0, MAP_ROUTE127
	connection down, 0, MAP_ROUTE129
	connection right, -40, MAP_EVER_GRANDE_CITY
	connection dive, 0, MAP_UNDERWATER4

Route128_MapConnections:
	.4byte 4
	.4byte Route128_MapConnectionsList

