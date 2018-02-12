#include "constants/items.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085DFEA4:: @ 85DFEA4
	.4byte gText_TakeOutItemsFromPC
	.4byte gText_StoreItemsInPC
	.4byte gText_ThrowAwayItemsInPC
	.4byte gText_GoBackPrevMenu

	.align 2
gUnknown_085DFEB4:: @ 85DFEB4
	.4byte gText_ItemStorage,	task_pc_itemstorage
	.4byte gText_Mailbox,		sub_816B0A8
	.4byte gText_Decoration,	sub_816B138
	.4byte gText_TurnOff,		sub_816B148

	.align 2
gUnknown_085DFED4:: @ 85DFED4
	.byte 0x00, 0x01, 0x02, 0x03

	.align 2
gUnknown_085DFED8:: @ 85DFED8
	.byte 0x00, 0x01, 0x03, 0x00

	.align 2
gUnknown_085DFEDC:: @ 85DFEDC
	.4byte gText_WithdrawItem,	sub_816B398
	.4byte gText_DepositItem,	sub_816B2C8
	.4byte gText_TossItem,		sub_816B3E4
	.4byte gText_Cancel,		sub_816B4A4

	.align 2
gUnknown_085DFEFC:: @ 85DFEFC
	.2byte ITEM_POTION, 0x0001
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_085DFF04:: @ 85DFF04
	.4byte gText_Read,			sub_816B878
	.4byte gText_MoveToBag,		sub_816B994
	.4byte gText_Give2,			sub_816BABC
	.4byte gText_Cancel2,		sub_816BBD4

	.align 2
gUnknown_085DFF24:: @ 85DFF24
	.4byte 0x09010100, 0x00010f06, 0x09010100, 0x00010f08, 0x0a010100, 0x00010f08

	.align 2
gUnknown_085DFF3C:: @ 85DFF3C
	.4byte sub_816CA94
	.4byte sub_816CAC8

	.align 2
gUnknown_085DFF44:: @ 85DFF44
	.4byte 0x00000000, sub_816BDDC, fish4_goto_x5_or_x6, 0x00000000, 0x00080000, 0x07003129

	.align 2
gUnknown_085DFF5C:: @ 85DFF5C
	window_template 0x00, 0x10, 0x01, 0x0d, 0x12, 0x0f, 0x0001
	window_template 0x00, 0x01, 0x0d, 0x0d, 0x06, 0x0f, 0x00eb
	window_template 0x00, 0x01, 0x08, 0x03, 0x03, 0x0f, 0x0153
	window_template 0x00, 0x01, 0x01, 0x0d, 0x02, 0x0f, 0x0139
	window_template 0x00, 0x08, 0x09, 0x06, 0x02, 0x0f, 0x015c

	.align 2
gUnknown_085DFF84:: @ 85DFF84
	window_template 0x00, 0x09, 0x07, 0x05, 0x04, 0x0f, 0x0168

	.align 2
gUnknown_085DFF8C:: @ 85DFF8C
	.byte 0x01, 0x03, 0x02, 0x00
