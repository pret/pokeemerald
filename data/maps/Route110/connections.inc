Route110_MapConnectionsList:
	connection up, 0, MAP_MAUVILLE_CITY
	connection down, 0, MAP_SLATEPORT_CITY
	connection left, 60, MAP_ROUTE103

Route110_MapConnections:
	.4byte 3
	.4byte Route110_MapConnectionsList

