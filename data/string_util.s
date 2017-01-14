	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

sDigits:: @ 82EC7D4
	.string "0123456789ABCDEF"

	.align 2
sPowersOfTen:: @ 82EC7E4
	.4byte          1
	.4byte         10
	.4byte        100
	.4byte       1000
	.4byte      10000
	.4byte     100000
	.4byte    1000000
	.4byte   10000000
	.4byte  100000000
	.4byte 1000000000

sSetBrailleFont:: @ 82EC80C
	.incbin "baserom.gba", 0x2ec80c, 0x4

sGotoLine2:: @ 82EC810
	.incbin "baserom.gba", 0x2ec810, 0x8

	.align 2
sExpandPlaceholderFuncs:: @ 82EC818
	.4byte ExpandPlaceholder_UnknownStringVar
	.4byte ExpandPlaceholder_PlayerName
	.4byte ExpandPlaceholder_StringVar1
	.4byte ExpandPlaceholder_StringVar2
	.4byte ExpandPlaceholder_StringVar3
	.4byte ExpandPlaceholder_KunChan
	.4byte ExpandPlaceholder_RivalName
	.4byte ExpandPlaceholder_Version
	.4byte ExpandPlaceholder_Aqua
	.4byte ExpandPlaceholder_Magma
	.4byte ExpandPlaceholder_Archie
	.4byte ExpandPlaceholder_Maxie
	.4byte ExpandPlaceholder_Kyogre
	.4byte ExpandPlaceholder_Groudon

gExtendedControlCodeLengths:: @ 82EC850
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 4
	.byte 2
	.byte 2
	.byte 1
	.byte 2
	.byte 1
	.byte 1
	.byte 3
	.byte 2
	.byte 2
	.byte 2
	.byte 1
	.byte 3
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 1
	.byte 1
	.byte 1
	.byte 1
