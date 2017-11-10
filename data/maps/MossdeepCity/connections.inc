MossdeepCity_MapConnectionsList: @ 84867C4
	connection up, 0, ROUTE_125, 0
	connection down, 0, ROUTE_127, 0
	connection left, -40, ROUTE_124, 0

MossdeepCity_MapConnections: @ 84867E8
	.4byte 0x3
	.4byte MossdeepCity_MapConnectionsList

	.incbin "baserom.gba", 0x4867f0, 0x8

