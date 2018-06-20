	.align 2
MauvilleCity_GameCorner_MapBorder::
	.incbin "data/layouts/MauvilleCity_GameCorner/border.bin"

	.align 2
MauvilleCity_GameCorner_MapBlockdata::
	.incbin "data/layouts/MauvilleCity_GameCorner/map.bin"

	.align 2
MauvilleCity_GameCorner_Layout::
	.4byte 0x16
	.4byte 0xb
	.4byte MauvilleCity_GameCorner_MapBorder
	.4byte MauvilleCity_GameCorner_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MauvilleGameCorner
