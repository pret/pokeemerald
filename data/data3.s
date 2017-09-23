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
	.incbin "baserom.gba", 0x32b6f8, 0x10

gEggName:: @ 832B708
	.string "タマゴ$" @ "tamago" ("egg" in Japanese)
