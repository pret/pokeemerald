	.section .rodata

gMultiBootProgram_BerryGlitchFix_Start::
.ifdef ENGLISH
	.incbin "data/mb_berry_fix.gba"
.else
.ifdef FRENCH
	.incbin "data/mb_berry_fix_fr.gba"
.else
.ifdef ITALIAN
	.incbin "data/mb_berry_fix_it.gba"
.endif
.endif
.endif
gMultiBootProgram_BerryGlitchFix_End::
