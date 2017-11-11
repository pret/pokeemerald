	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085CDC38:: @ 85CDC38
	.incbin "baserom.gba", 0x5cdc38, 0x6

gUnknown_085CDC3E:: @ 85CDC3E
@ replacing .incbin "baserom.gba", 0x005cdc3e, 0x4
.byte 0x00, 0x01, 0x02, 0x03

gUnknown_085CDC42:: @ 85CDC42
@ replacing .incbin "baserom.gba", 0x005cdc42, 0xa
.2byte 0x0004, 0x0004, 0x0004, 0x0010, 0x0000

gUnknown_085CDC4C:: @ 85CDC4C
@ replacing .incbin "baserom.gba", 0x005cdc4c, 0x8
.4byte sub_8154C7C
.4byte sub_8154CA0

gUnknown_085CDC54:: @ 85CDC54
@ replacing .incbin "baserom.gba", 0x005cdc54, 0xc
.4byte sub_815547C
.4byte sub_81554AC
.4byte sub_815550C

gUnknown_085CDC60:: @ 85CDC60
	.incbin "baserom.gba", 0x5cdc60, 0xa

gUnknown_085CDC6A:: @ 85CDC6A
	.incbin "baserom.gba", 0x5cdc6a, 0x96

