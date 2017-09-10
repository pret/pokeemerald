	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    
    
   gSafariBufferCommands:: @ 85CDF20
	.incbin "baserom.gba", 0x5cdf20, 0x380
