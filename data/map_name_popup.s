    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gMapPopUp_Table:: @ 857C684
	.incbin "graphics/interface/map_popup/wood.4bpp"
	.incbin "graphics/interface/map_popup/marble.4bpp"
	.incbin "graphics/interface/map_popup/stone.4bpp"
	.incbin "graphics/interface/map_popup/brick.4bpp"
	.incbin "graphics/interface/map_popup/underwater.4bpp"
	.incbin "graphics/interface/map_popup/stone2.4bpp"

gMapPopUp_Outline_Table:: @ 857DD04
	.incbin "graphics/interface/map_popup/wood_outline.4bpp"
	.incbin "graphics/interface/map_popup/marble_outline.4bpp"
	.incbin "graphics/interface/map_popup/stone_outline.4bpp"
	.incbin "graphics/interface/map_popup/brick_outline.4bpp"
	.incbin "graphics/interface/map_popup/underwater_outline.4bpp"
	.incbin "graphics/interface/map_popup/stone2_outline.4bpp"

gMapPopUp_Palette_Table:: @ 857F384
	.incbin "graphics/interface/map_popup/wood.gbapal"
	.incbin "graphics/interface/map_popup/marble.gbapal"
	.incbin "graphics/interface/map_popup/stone.gbapal"
	.incbin "graphics/interface/map_popup/brick.gbapal"
	.incbin "graphics/interface/map_popup/underwater.gbapal"
	.incbin "graphics/interface/map_popup/stone2.gbapal"

gUnknown_0857F444:: @ 857F444
	.incbin "graphics/interface/map_popup/857F444.gbapal"

gUnknown_0857F464:: @ 857F464
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x02, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x05, 0x02, 0x00, 0x02, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x05, 0x02, 0x02, 0x02, 0x02, 0x00, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x05, 0x02, 0x05, 0x05, 0x05, 0x02, 0x02, 0x02, 0x01
	
gUnknown_0857F4CC:: @ 857F4CC
	.string "PYRAMID FLOOR 1$"
	
gUnknown_0857F4DC:: @ 857F4DC
	.string "PYRAMID FLOOR 2$"
	
gUnknown_0857F4EC:: @ 857F4EC
	.string "PYRAMID FLOOR 3$"
	
gUnknown_0857F4FC:: @ 857F4FC
	.string "PYRAMID FLOOR 4$"
	
gUnknown_0857F50C:: @ 857F50C
	.string "PYRAMID FLOOR 5$"
	
gUnknown_0857F51C:: @ 857F51C
	.string "PYRAMID FLOOR 6$"
	
gUnknown_0857F52C:: @ 857F52C
	.string "PYRAMID FLOOR 7$"
	
gUnknown_0857F53C:: @ 857F53C
	.string "PYRAMID$"

gUnknown_0857F544:: @ 857F544
	.4byte gUnknown_0857F4CC
	.4byte gUnknown_0857F4DC
	.4byte gUnknown_0857F4EC
	.4byte gUnknown_0857F4FC
	.4byte gUnknown_0857F50C
	.4byte gUnknown_0857F51C
	.4byte gUnknown_0857F52C
	.4byte gUnknown_0857F53C
