	.include "asm/macros.s"
	.include "constants/constants.s"

	.section script_data, "aw", %progbits

gUnknown_082DBD08:: @ 82DBD08
	.incbin "baserom.gba", 0x2dbd08, 0x34

gUnknown_082DBD3C:: @ 82DBD3C
	.incbin "baserom.gba", 0x2dbd3c, 0x18

gUnknown_082DBD54:: @ 82DBD54
	.incbin "baserom.gba", 0x2dbd54, 0x4

gUnknown_082DBD58:: @ 82DBD58
	.incbin "baserom.gba", 0x2dbd58, 0x2c

gUnknown_082DBD84:: @ 82DBD84
	.incbin "baserom.gba", 0x2dbd84, 0x46

gUnknown_082DBDCA:: @ 82DBDCA
	.incbin "baserom.gba", 0x2dbdca, 0xa

gUnknown_082DBDD4:: @ 82DBDD4
	.incbin "baserom.gba", 0x2dbdd4, 0x2e

gUnknown_082DBE02:: @ 82DBE02
	.incbin "baserom.gba", 0x2dbe02, 0xf6
