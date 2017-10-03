    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gSafariBallsWindowTemplate:: @ 8510508
	.incbin "baserom.gba", 0x510508, 0x8

gUnknown_08510510:: @ 8510510
	.incbin "baserom.gba", 0x510510, 0x20

gPyramidFloorWindowTemplate_2:: @ 8510530
	.incbin "baserom.gba", 0x510530, 0x8

gPyramidFloorWindowTemplate_1:: @ 8510538
	.incbin "baserom.gba", 0x510538, 0x8

sStartMenuItems:: @ 8510540
	.incbin "baserom.gba", 0x510540, 0x68

gUnknown_085105A8:: @ 85105A8
	.incbin "baserom.gba", 0x5105a8, 0x4

gUnknown_085105AC:: @ 85105AC
	.incbin "baserom.gba", 0x5105ac, 0x10

gUnknown_085105BC:: @ 85105BC
	.incbin "baserom.gba", 0x5105bc, 0x8
