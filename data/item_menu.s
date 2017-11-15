	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_08613F90:: @ 8613F90
	.4byte 0x11F0, 0x1E1, 0x21DE

@ possibly a struct
gUnknown_08613F9C:: @ 8613F9C
	.4byte 0
	.4byte bag_menu_change_item_callback
	.4byte sub_81AB520
	.4byte 0
	.4byte 0x80000
	.4byte 0x7003011

gUnknown_08613FB4:: @ 8613FB4
    .4byte gMenuText_Use, ItemMenu_UseOutOfBattle
    .4byte gMenuText_Toss, ItemMenu_Toss
    .4byte gMenuText_Register, ItemMenu_Register
    .4byte gMenuText_Give, ItemMenu_Give
    .4byte gText_Cancel2, ItemMenu_Cancel
    .4byte gMenuText_Use, ItemMenu_UseInBattle
    .4byte gMenuText_Check, ItemMenu_UseOutOfBattle
    .4byte gMenuText_Walk, ItemMenu_UseOutOfBattle
    .4byte gMenuText_Deselect, ItemMenu_Register
    .4byte gMenuText_CheckTag, ItemMenu_CheckTag
    .4byte gMenuText_Confirm, unknown_ItemMenu_Confirm
    .4byte gMenuText_Show, unknown_ItemMenu_Show
    .4byte gMenuText_Give2, unknown_ItemMenu_Give2
    .4byte gMenuText_Confirm, unknown_ItemMenu_Confirm2
    .4byte gText_EmptyString2, NULL

gUnknown_0861402C:: @ 861402C
	.byte 0, 3, 1, 4

gUnknown_08614030:: @ 8614030
	.byte 0, 2, 14, 4

gUnknown_08614034:: @ 8614034
	.byte 3, 14, 1, 4

gUnknown_08614038:: @ 8614038
	.byte 0, 3, 14, 4

gUnknown_0861403C:: @ 861403C
	.byte 9, 14, 0, 3, 1, 4

gUnknown_08614042:: @ 8614042
	.byte 5, 4

gUnknown_08614044:: @ 8614044
	.byte 3, 4

gUnknown_08614046:: @ 8614046
	.byte 4

gUnknown_08614047:: @ 8614047
	.byte 10, 9, 14, 4

gUnknown_0861404B:: @ 861404B
	.byte 11, 4

gUnknown_0861404D:: @ 861404D
	.byte 12, 4

gUnknown_0861404F:: @ 861404F
	.byte 13, 4

    .align 2
gUnknown_08614054:: @ 8614054
	.4byte unknown_item_menu_type
	.4byte unknown_item_menu_type
	.4byte item_menu_type_2
	.4byte display_sell_item_ask_str
	.4byte unknown_ItemMenu_Confirm
	.4byte unknown_item_menu_type
	.4byte display_deposit_item_ask_str
	.4byte unknown_item_menu_type
	.4byte unknown_item_menu_type
	.4byte unknown_item_menu_type
	.4byte NULL
	.4byte item_menu_type_b

    .align 2
gUnknown_08614084:: @ 8614084
	.4byte BagMenuActuallyToss
	.4byte BagMenuCancelToss

gUnknown_0861408C:: @ 861408C
	.4byte sub_81AD84C
	.4byte sub_81AD6FC

@ probably a struct
gUnknown_08614094:: @ 8614094
	.4byte 0x1101C00
	.4byte 0xFFFF1064
	.4byte 0x6FFFFF
	.4byte 0x6F

gUnknown_086140A4:: @ 86140A4
	.incbin "baserom.gba", 0x6140a4, 0xc0

gUnknown_08614164:: @ 8614164
	.incbin "baserom.gba", 0x614164, 0x10

gUnknown_08614174:: @ 8614174
	.incbin "baserom.gba", 0x614174, 0x38

gUnknown_086141AC:: @ 86141AC
	.incbin "baserom.gba", 0x6141ac, 0x50
