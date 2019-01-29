Route105_MapConnectionsList:
	connection up, 0, MAP_ROUTE104
	connection down, 0, MAP_ROUTE106
	connection dive, 0, MAP_UNDERWATER6

Route105_MapConnections:
	.4byte 3
	.4byte Route105_MapConnectionsList

