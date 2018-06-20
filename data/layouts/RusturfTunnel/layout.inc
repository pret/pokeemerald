RusturfTunnel_MapBorder::
	.incbin "data/layouts/RusturfTunnel/border.bin"

RusturfTunnel_MapBlockdata::
	.incbin "data/layouts/RusturfTunnel/map.bin"

	.align 2
RusturfTunnel_Layout::
	.4byte 0x24
	.4byte 0x18
	.4byte RusturfTunnel_MapBorder
	.4byte RusturfTunnel_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_RusturfTunnel

