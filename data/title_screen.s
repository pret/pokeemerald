    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gTitleScreenRayquazaTiles:: @ 853F058
	.incbin "graphics/title_screen/rayquaza.4bpp.lz"

	.align 2
gUnknown_0853F83C:: @ 853F83C
	.incbin "baserom.gba", 0x53f83c, 0x450

gTitleScreenCloudsTiles:: @ 853FC8C
	.incbin "graphics/title_screen/clouds.4bpp.lz"

	.align 2
gUnknown_0853FF70:: @ 853FF70
	.incbin "baserom.gba", 0x53ff70, 0xa8

gUnknown_08540018:: @ 8540018
	.incbin "baserom.gba", 0x540018, 0x18

gUnknown_08540030:: @ 8540030
	.incbin "baserom.gba", 0x540030, 0x18

gUnknown_08540048:: @ 8540048
	.incbin "baserom.gba", 0x540048, 0x90

gUnknown_085400D8:: @ 85400D8
	.incbin "baserom.gba", 0x5400d8, 0x18

gUnknown_085400F0:: @ 85400F0
	.incbin "baserom.gba", 0x5400f0, 0x10

gUnknown_08540100:: @ 8540100
	.incbin "baserom.gba", 0x540100, 0x24

gUnknown_08540124:: @ 8540124
	.incbin "baserom.gba", 0x540124, 0x18

gUnknown_0854013C:: @ 854013C
	.incbin "baserom.gba", 0x54013c, 0x10

gUnknown_0854014C:: @ 854014C
	.incbin "baserom.gba", 0x54014c, 0xc000
