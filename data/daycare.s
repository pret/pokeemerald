@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata



@ 832ADD8
	.include "data/egg_moves.inc"

	.align 2
gUnknown_0832B6C0:: @ 832B6C0
	.incbin "baserom.gba", 0x32b6c0, 0x20

gUnknown_0832B6E0:: @ 832B6E0
	.incbin "baserom.gba", 0x32b6e0, 0x18

gUnknown_0832B6F8:: @ 832B6F8
@ replacing .incbin "baserom.gba", 0x0032b6f8, 0x10
.4byte 0x85ef7da
.4byte 0x85ef7ff
.4byte 0x85ef81a
.4byte 0x85ef846

gEggName:: @ 832B708
	.string "タマゴ$" @ "tamago" ("egg" in Japanese)

