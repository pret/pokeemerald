	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    
gPlayerPartnerBufferCommands:: @ 8617170
	.incbin "baserom.gba", 0x617170, 0xE4
    
    @ apparently unused data
    .incbin "baserom.gba", 0x617254,  32
