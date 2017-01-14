	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gDigits:: @ 82EC7D4
	.string "0123456789ABCDEF"

	.align 2
gPowersOfTen:: @ 82EC7E4
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

gUnknown_082EC80C:: @ 82EC80C
	.incbin "baserom.gba", 0x2ec80c, 0x4

gUnknown_082EC810:: @ 82EC810
	.incbin "baserom.gba", 0x2ec810, 0x8

	.align 2
gStringRefFunctionTable:: @ 82EC818
	.4byte StringRef_GetPossiblyUnusedStringVar
	.4byte StringRef_GetPlayerName
	.4byte StringRef_GetStringVar1
	.4byte StringRef_GetStringVar2
	.4byte StringRef_GetStringVar3
	.4byte StringRef_GetDummiedOutGenderDependentString
	.4byte StringRef_GetRivalName
	.4byte StringRef_GetEmeraldString
	.4byte StringRef_GetAquaString
	.4byte StringRef_GetMagmaString
	.4byte StringRef_GetArchieString
	.4byte StringRef_GetMaxieString
	.4byte StringRef_GetKyogreString
	.4byte StringRef_GetGroudonString

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
