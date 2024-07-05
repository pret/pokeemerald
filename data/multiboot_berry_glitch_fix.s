	.section .rodata

gMultiBootProgram_BerryGlitchFix_Start::
.ifdef FRENCH
	.incbin "data/mb_berry_fix_fr.gba"
.else
.ifdef ITALIAN
	.incbin "data/mb_berry_fix_it.gba"
.else @ENGLISH
	.incbin "data/mb_berry_fix.gba"
.endif
.endif
gMultiBootProgram_BerryGlitchFix_End::
