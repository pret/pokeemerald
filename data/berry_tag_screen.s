	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
gUnknown_085EFCF0:: @ 85EFCF0
	.4byte 0x000001f0, 0x000011e1, 0x000021d2, 0x000031c3

    .align 2
gUnknown_085EFD00:: @ 85EFD00
	.incbin "graphics/interface/berry_tag_screen.gbapal"

	.align 2
gUnknown_085EFD20:: @ 85EFD20 struct TextColor
	.byte 0x00, 0x02, 0x03

	.byte 0x0F, 0x0E, 0x0D

	.align 2
gUnknown_085EFD28:: @ 85EFD28
	window_template 0x01, 0x0b, 0x04, 0x08, 0x02, 0x0f, 0x0045
	window_template 0x01, 0x0b, 0x07, 0x12, 0x04, 0x0f, 0x0055
	window_template 0x01, 0x04, 0x0e, 0x19, 0x04, 0x0f, 0x009d
	window_template 0x00, 0x02, 0x00, 0x08, 0x02, 0x0f, 0x0101
	window_template_terminator

	.align 2
gBerryFirmnessStringPointers:: @ 85EFD50
	.4byte gBerryFirmnessString_VerySoft
	.4byte gBerryFirmnessString_Soft
	.4byte gBerryFirmnessString_Hard
	.4byte gBerryFirmnessString_VeryHard
	.4byte gBerryFirmnessString_SuperHard
