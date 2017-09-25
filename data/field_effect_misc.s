	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
    .incbin "baserom.gba", 0x58d978, 0x2a0

	.align 2
gFieldEffectObjectPalette7:: @ 858DC18
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_07.gbapal"

	.incbin "baserom.gba", 0x58dc38, 0x580

	.align 2
gFieldEffectObjectPalette8:: @ 858E1B8
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_08.gbapal"

	.incbin "baserom.gba", 0x58e1d8, 0x428

gUnknown_0858E600:: @ 858E600
	.incbin "baserom.gba", 0x58e600, 0x18

gUnknown_0858E618:: @ 858E618
	.incbin "baserom.gba", 0x58e618, 0x18

gUnknown_0858E630:: @ 858E630
	.incbin "baserom.gba", 0x58e630, 0x18

	.align 2
gFieldEffectObjectPaletteInfo7:: @ 858E648
	obj_pal gFieldEffectObjectPalette7, 0x1003

	.align 2
gFieldEffectObjectPaletteInfo8:: @ 858E650
	obj_pal gFieldEffectObjectPalette8, 0x1008

	.incbin "baserom.gba", 0x58e658, 0x34

gUnknown_0858E68C:: @ 858E68C
	.incbin "baserom.gba", 0x58e68c, 0x18

	.align 2
@ This uses one of the secret base palettes, so there is no
@ "field_effect_object_palette_09.pal" file.
gFieldEffectObjectPaletteInfo9:: @ 858E6A4
	obj_pal gTilesetPalettes_SecretBase + 5 * 0x20, 0x100E

	.incbin "baserom.gba", 0x58e6ac, 0x1b8

gUnknown_0858E864:: @ 858E864
	.incbin "baserom.gba", 0x58e864, 0x1c

gUnknown_0858E880:: @ 858E880
	.incbin "baserom.gba", 0x58e880, 0x18
