	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0862AD54:: @ 862AD54
	.incbin "baserom.gba", 0x62ad54, 0x1dc

gUnknown_0862AF30:: @ 862AF30
     .incbin "baserom.gba", 0x62af30, 0x1AC

gUnknown_0862B0DC:: @ 862B0DC
     .incbin "baserom.gba", 0x62b0dc, 0x460

gUnknown_0862B53C:: @ 862B53C
     .incbin "baserom.gba", 0x62b53c, 0x1E0

gUnknown_0862B71C:: @ 862B71C
     .incbin "baserom.gba", 0x62b71c, 0x8

gUnknown_0862B724:: @ 862B724
     obj_tiles gUnknown_0862B0DC, 0x1800, 11920

gUnknown_0862B72C:: @ 862B72C
     obj_pal gUnknown_0862B53C, 11920

gUnknown_0862B734:: @ 862B734
     .incbin "baserom.gba", 0x62b734, 0x8

gUnknown_0862B73C:: @ 862B73C
     .incbin "baserom.gba", 0x62b73c, 0x8

gUnknown_0862B744:: @ 862B744
     .incbin "baserom.gba", 0x62b744, 0x8

gUnknown_0862B74C:: @ 862B74C
     .4byte gUnknown_0862B734
     .4byte gUnknown_0862B73C
     .4byte gUnknown_0862B744

gUnknown_0862B758:: @ 862B758
	spr_template 11920, 11920, gUnknown_0862B71C, gUnknown_0862B74C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
