@ the second big chunk of data

	.align 2, 0

gUnknown_82E9530:
	.byte 3

gUnknown_82E9531:
	.byte 2

	.align 2, 0

@ compile time
	.asciz "2005 02 21 11:10"

	.align 2, 0

gRomInterruptTable: @ 82E9548
	.4byte irq_vcount+1
	.4byte irq_serial+1
	.4byte irq_timer3+1
	.4byte irq_hblank+1
	.4byte irq_vblank+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1
	.4byte irq_other+1

gBgConfigZeroValue: @ 82E9580
	.4byte 0

	.incbin "base_emerald.gba", 0x2e9584
