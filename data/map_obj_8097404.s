    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0850E754:: @ 850E754
	.incbin "baserom.gba", 0x50e754, 0x14

gUnknown_0850E768:: @ 850E768
	.incbin "baserom.gba", 0x50e768, 0xa

gUnknown_0850E772:: @ 850E772
	.incbin "baserom.gba", 0x50e772, 0x48

gUnknown_0850E7BA:: @ 850E7BA
	.incbin "baserom.gba", 0x50e7ba, 0x7a

gUnknown_0850E834:: @ 850E834
	.incbin "baserom.gba", 0x50e834, 0xc

gUnknown_0850E840:: @ 850E840
	.incbin "baserom.gba", 0x50e840, 0x6

gUnknown_0850E846:: @ 850E846
	.incbin "baserom.gba", 0x50e846, 0x4

gUnknown_0850E84A:: @ 850E84A
	.incbin "baserom.gba", 0x50e84a, 0x6

gUnknown_0850E850:: @ 850E850
	.incbin "baserom.gba", 0x50e850, 0x4

// referenced in src/field_map_obj.o
gUnknown_0850E854::
    .incbin "baserom.gba", 0x50e854, 0x8

gUnknown_0850E85C::
    .incbin "baserom.gba", 0x50e85C, 0x8

gUnknown_0850E864::
    .incbin "baserom.gba", 0x50e864, 0xc

gUnknown_0850E870::
    .incbin "baserom.gba", 0x50e870, 0xc
