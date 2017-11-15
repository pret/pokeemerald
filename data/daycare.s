@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata




	.align 2
sDaycareLevelMenuWindowTemplate:: @ 832B6C0
	.incbin "baserom.gba", 0x32b6c0, 0x20

sDaycareListMenuLevelTemplate:: @ 832B6E0
	.incbin "baserom.gba", 0x32b6e0, 0x18

sCompatibilityMessages:: @ 832B6F8
	.incbin "baserom.gba", 0x32b6f8, 0x10

sJapaneseEggNickname:: @ 832B708
	.string "タマゴ$" @ "tamago" ("egg" in Japanese)
