	.align 2
BattleFrontier_ReceptionGate_MapBorder::
	.incbin "data/layouts/BattleFrontier_ReceptionGate/border.bin"

	.align 2
BattleFrontier_ReceptionGate_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_ReceptionGate/map.bin"

	.align 2
BattleFrontier_ReceptionGate_Layout::
	.4byte 0x9
	.4byte 0xe
	.4byte BattleFrontier_ReceptionGate_MapBorder
	.4byte BattleFrontier_ReceptionGate_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattleFrontier
