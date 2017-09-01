	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ Unreferenced data. Also unreferenced in Ruby.
	.incbin "baserom.gba", 0x2ec61c, 0x18

gUnknown_082EC634:: @ 82EC634
	.incbin "baserom.gba", 0x2ec634, 0x18

sDummySprite:: @ 82EC64C
	.incbin "baserom.gba", 0x2ec64c, 0x44

@ off-screen and low priority relative to background
gDefaultOamAttributes:: @ 82EC690
	.2byte 160 @ Y
	.2byte 304 @ X
	.2byte 3 << 10 @ priority

	.align 2
gDummyObjectImageAnim:: @ 82EC698
	obj_image_anim_end

	.align 2
gDummyObjectImageAnimTable:: @ 82EC69C
	.4byte gDummyObjectImageAnim

	.align 2
gDummyObjectRotScalAnim:: @ 82EC6A0
	obj_rot_scal_anim_end

	.align 2
gDummyObjectRotScalAnimTable:: @ 82EC6A8
	.4byte gDummyObjectRotScalAnim

gUnknown_082EC6AC:: @ 82EC6AC
	.incbin "baserom.gba", 0x2ec6ac, 0x18

gUnknown_082EC6C4:: @ 82EC6C4
	.incbin "baserom.gba", 0x2ec6c4, 0x8

gUnknown_082EC6CC:: @ 82EC6CC
	.incbin "baserom.gba", 0x2ec6cc, 0x8

gUnknown_082EC6D4:: @ 82EC6D4
	.incbin "baserom.gba", 0x2ec6d4, 0x10

gUnknown_082EC6E4:: @ 82EC6E4
	.incbin "baserom.gba", 0x2ec6e4, 0x10

gUnknown_082EC6F4:: @ 82EC6F4
	.incbin "baserom.gba", 0x2ec6f4, 0x60

gUnknown_082EC754:: @ 82EC754
	.incbin "baserom.gba", 0x2ec754, 0x70

gUnknown_82EC7C4:: @ 82EC7C4
	.2byte 0x0100
	.2byte 0x0200
	.2byte 0x0400
	.2byte 0x0800

gUnknown_82EC7CC:: @ 82EC7CC
	.2byte 0x0001
	.2byte 0x0002
	.2byte 0x0004
	.2byte 0x0008
