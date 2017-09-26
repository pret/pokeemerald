    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0
gUnknown_08339D3C:: @ 8339D3C
	.incbin "baserom.gba", 0x339d3c, 0x28

gUnknown_08339D64:: @ 8339D64
	.incbin "baserom.gba", 0x339d64, 0x48

gUnknown_08339DAC:: @ 8339DAC
	.incbin "baserom.gba", 0x339dac, 0x10

gUnknown_08339DBC:: @ 8339DBC
	.incbin "baserom.gba", 0x339dbc, 0xc

gUnknown_08339DC8:: @ 8339DC8
	.incbin "baserom.gba", 0x339dc8, 0xc

gUnknown_08339DD4:: @ 8339DD4
	.incbin "baserom.gba", 0x339dd4, 0x2c

gUnknown_08339E00:: @ 8339E00
	.incbin "baserom.gba", 0x339e00, 0x8

@ 8339E08
	.include "data/tilesets/tileset_graphics.inc"

@ 83960F0
	.include "data/tilesets/metatiles.inc"

@ 83DF704
	.include "data/tilesets/tilesets.inc"

@ 83DFE14
	.incbin "baserom.gba", 0x3dfe14, 0xa1fc0

gUnknown_08481DD4:: @ 8481DD4
	.incbin "baserom.gba", 0x481dd4, 0x47a4

gUnknown_08486578:: @ 8486578
	.incbin "baserom.gba", 0x486578, 0x980
