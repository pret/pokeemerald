Route124_MapConnectionsList:
	connection down, 0, MAP_ROUTE126
	connection left, 10, MAP_LILYCOVE_CITY
	connection right, 0, MAP_ROUTE125
	connection right, 40, MAP_MOSSDEEP_CITY
	connection dive, 0, MAP_UNDERWATER1

Route124_MapConnections:
	.4byte 5
	.4byte Route124_MapConnectionsList

