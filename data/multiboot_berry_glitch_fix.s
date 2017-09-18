	.section .rodata

gUnknown_089A6550:: @ 89A6550
	.incbin "baserom.gba", 0x9a6550, 0xc0

gMultiBootProgram_BerryGlitchFix_Script:: @ 89A6610
gMultiBootProgram_BerryGlitchFix_Start:: @ 89A6610
	.incbin "baserom.gba", 0x9a6610, 0x3b34
gMultiBootProgram_BerryGlitchFix_End::
