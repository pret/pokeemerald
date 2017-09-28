    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08510348:: @ 8510348
	.incbin "baserom.gba", 0x510348, 0x20

gUnknown_08510368:: @ 8510368
	.incbin "baserom.gba", 0x510368, 0x20

gUnknown_08510388:: @ 8510388
	.incbin "baserom.gba", 0x510388, 0x20

gUnknown_085103A8:: @ 85103A8
	.incbin "baserom.gba", 0x5103a8, 0x20

gUnknown_085103C8:: @ 85103C8
	.incbin "baserom.gba", 0x5103c8, 0x34

gUnknown_085103FC:: @ 85103FC
	.incbin "baserom.gba", 0x5103fc, 0x8
