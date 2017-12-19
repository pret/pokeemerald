	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ResetBagScrollPositions
ResetBagScrollPositions: @ 81AAB70
	push {r4,lr}
	ldr r4, =gUnknown_0203CE58
	movs r0, 0
	strb r0, [r4, 0x5]
	adds r0, r4, 0
	adds r0, 0x8
	movs r1, 0
	movs r2, 0xA
	bl memset
	adds r4, 0x12
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xA
	bl memset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetBagScrollPositions

	thumb_func_start CB2_BagMenuFromStartMenu
@ void CB2_BagMenuFromStartMenu()
CB2_BagMenuFromStartMenu: @ 81AAB9C
	push {lr}
	ldr r2, =sub_8086194
	movs r0, 0
	movs r1, 0x5
	bl GoToBagMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_BagMenuFromStartMenu

	thumb_func_start sub_81AABB0
sub_81AABB0: @ 81AABB0
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _081AABCC
	ldr r2, =SetCB2ToReshowScreenAfterMenu2
	movs r0, 0x1
	movs r1, 0x5
	bl GoToBagMenu
	b _081AABD4
	.pool
_081AABCC:
	ldr r1, =SetCB2ToReshowScreenAfterMenu2
	movs r0, 0x1
	bl sub_81C4F98
_081AABD4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AABB0

	thumb_func_start CB2_ChooseBerry
CB2_ChooseBerry: @ 81AABDC
	push {lr}
	ldr r2, =sub_80861B0
	movs r0, 0x4
	movs r1, 0x3
	bl GoToBagMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_ChooseBerry

	thumb_func_start sub_81AABF0
sub_81AABF0: @ 81AABF0
	push {lr}
	adds r2, r0, 0
	movs r0, 0x5
	movs r1, 0x3
	bl GoToBagMenu
	pop {r0}
	bx r0
	thumb_func_end sub_81AABF0

	thumb_func_start CB2_GoToSellMenu
@ void CB2_GoToSellMenu()
CB2_GoToSellMenu: @ 81AAC00
	push {lr}
	ldr r2, =CB2_ExitSellMenu
	movs r0, 0x3
	movs r1, 0x5
	bl GoToBagMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_GoToSellMenu

	thumb_func_start sub_81AAC14
sub_81AAC14: @ 81AAC14
	push {lr}
	ldr r2, =sub_816B31C
	movs r0, 0x6
	movs r1, 0x5
	bl GoToBagMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AAC14

	thumb_func_start sub_81AAC28
sub_81AAC28: @ 81AAC28
	push {lr}
	ldr r2, =bag_menu_leave_maybe_3
	movs r0, 0x9
	movs r1, 0x5
	bl GoToBagMenu
	ldr r0, =gSpecialVar_0x8005
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AAC28

	thumb_func_start sub_81AAC50
sub_81AAC50: @ 81AAC50
	push {lr}
	ldr r2, =bag_menu_leave_maybe_2
	movs r0, 0x7
	movs r1, 0x5
	bl GoToBagMenu
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AAC50

	thumb_func_start sub_81AAC70
sub_81AAC70: @ 81AAC70
	push {lr}
	ldr r2, =bag_menu_leave_maybe
	movs r0, 0x8
	movs r1, 0x5
	bl GoToBagMenu
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AAC70

	thumb_func_start GoToBagMenu
@ void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)())
GoToBagMenu: @ 81AAC90
	push {r4-r7,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r6, =gUnknown_0203CE54
	ldr r0, =0x00000c48
	bl AllocZeroed
	str r0, [r6]
	cmp r0, 0
	bne _081AACBC
	adds r0, r4, 0
	bl SetMainCallback2
	b _081AAD3A
	.pool
_081AACBC:
	ldr r0, =gUnknown_0203CE58
	cmp r5, 0xC
	beq _081AACC4
	strb r5, [r0, 0x4]
_081AACC4:
	cmp r4, 0
	beq _081AACCA
	str r4, [r0]
_081AACCA:
	cmp r7, 0x4
	bhi _081AACD0
	strb r7, [r0, 0x5]
_081AACD0:
	ldrb r0, [r0, 0x4]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _081AACF0
	ldr r2, [r6]
	ldr r0, =0x0000081b
	adds r2, r0
	ldrb r1, [r2]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_081AACF0:
	ldr r0, [r6]
	movs r1, 0
	str r1, [r0]
	ldr r1, =0x0000081a
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x0000081e
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x0000081f
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x00000804
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0xC
	bl memset
	ldr r0, [r6]
	movs r1, 0x81
	lsls r1, 4
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0xA
	bl memset
	ldr r0, =CB2_Bag
	bl SetMainCallback2
_081AAD3A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GoToBagMenu

	thumb_func_start c2_bag_3
c2_bag_3: @ 81AAD5C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end c2_bag_3

	thumb_func_start vblank_cb_bag_menu
vblank_cb_bag_menu: @ 81AAD78
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end vblank_cb_bag_menu

	thumb_func_start CB2_Bag
CB2_Bag: @ 81AAD8C
	push {lr}
_081AAD8E:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AADB2
	bl setup_bag_menu
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AADB2
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081AAD8E
_081AADB2:
	pop {r0}
	bx r0
	thumb_func_end CB2_Bag

	thumb_func_start setup_bag_menu
setup_bag_menu: @ 81AADB8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x14
	bls _081AADCE
	b _081AB02C
_081AADCE:
	lsls r0, 2
	ldr r1, =_081AADE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AADE0:
	.4byte _081AAE34
	.4byte _081AAE3E
	.4byte _081AAE50
	.4byte _081AAE56
	.4byte _081AAE78
	.4byte _081AAE7E
	.4byte _081AAE86
	.4byte _081AAEA4
	.4byte _081AAECC
	.4byte _081AAEDA
	.4byte _081AAEEC
	.4byte _081AAEFA
	.4byte _081AAF0C
	.4byte _081AAF1C
	.4byte _081AAF54
	.4byte _081AAFA0
	.4byte _081AAFBC
	.4byte _081AAFC2
	.4byte _081AAFD8
	.4byte _081AAFDE
	.4byte _081AAFF8
_081AAE34:
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	b _081AB012
_081AAE3E:
	bl remove_some_task
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAE50:
	bl FreeAllSpritePalettes
	b _081AB012
_081AAE56:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAE78:
	bl ResetSpriteData
	b _081AB012
_081AAE7E:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	b _081AB01A
_081AAE86:
	bl sub_81221AC
	lsls r0, 24
	cmp r0, 0
	bne _081AAE94
	bl ResetTasks
_081AAE94:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAEA4:
	bl bag_menu_init_bgs
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000834
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAECC:
	bl load_bag_menu_graphics
	lsls r0, 24
	cmp r0, 0
	bne _081AAED8
	b _081AB044
_081AAED8:
	b _081AB012
_081AAEDA:
	bl setup_bag_menu_textboxes
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAEEC:
	bl sub_81ABA6C
	bl sub_81ABAC4
	bl sub_81ABAE0
	b _081AB012
_081AAEFA:
	bl allocate_bag_item_list_buffers
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAF0C:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	bl load_bag_item_list_buffers
	b _081AB012
	.pool
_081AAF1C:
	ldr r1, =gPocketNamesStringsTable
	ldr r4, =gUnknown_0203CE58
	ldrb r0, [r4, 0x5]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl bag_menu_print_pocket_names
	movs r0, 0
	bl bag_menu_copy_pocket_name_to_window
	ldrb r0, [r4, 0x5]
	movs r1, 0x1
	bl bag_menu_draw_pocket_indicator_square
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAF54:
	ldr r4, =gUnknown_0203CE58
	ldrb r0, [r4, 0x4]
	bl sub_81AB1F0
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_03006310
	ldrb r2, [r4, 0x5]
	lsls r2, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r2, r1
	ldrh r1, [r1]
	adds r4, 0x8
	adds r2, r4
	ldrh r2, [r2]
	bl ListMenuInit
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xE]
	strh r2, [r1, 0x18]
	b _081AB012
	.pool
_081AAFA0:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	bl AddBagVisualObject
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAFBC:
	bl sub_80D4FAC
	b _081AB012
_081AAFC2:
	bl bag_menu_add_pocket_scroll_arrow_indicators_maybe
	bl bag_menu_add_list_scroll_arrow_indicators_maybe
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAFD8:
	bl bag_menu_prepare_tmhm_move_window
	b _081AB012
_081AAFDE:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _081AB01A
	.pool
_081AAFF8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
_081AB012:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_081AB01A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081AB044
	.pool
_081AB02C:
	ldr r0, =vblank_cb_bag_menu
	bl SetVBlankCallback
	ldr r0, =c2_bag_3
	bl SetMainCallback2
	movs r0, 0x1
	b _081AB046
	.pool
_081AB044:
	movs r0, 0
_081AB046:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end setup_bag_menu

	thumb_func_start bag_menu_init_bgs
bag_menu_init_bgs: @ 81AB050
	push {r4,lr}
	bl sub_8121DA0
	ldr r4, =gUnknown_0203CE54
	ldr r0, [r4]
	adds r0, 0x4
	movs r2, 0x80
	lsls r2, 4
	movs r1, 0
	bl memset
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08613F90
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r1, [r4]
	adds r1, 0x4
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_init_bgs

	thumb_func_start load_bag_menu_graphics
load_bag_menu_graphics: @ 81AB0BC
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203CE54
	ldr r0, [r4]
	ldr r1, =0x00000834
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bls _081AB0D2
	b _081AB1CC
_081AB0D2:
	lsls r0, 2
	ldr r1, =_081AB0E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AB0E8:
	.4byte _081AB0FC
	.4byte _081AB118
	.4byte _081AB13C
	.4byte _081AB174
	.4byte _081AB1A8
_081AB0FC:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D9A620
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081AB1AE
	.pool
_081AB118:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AB1E4
	ldr r0, =gUnknown_08D9A88C
	ldr r4, =gUnknown_0203CE54
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r1, [r4]
	b _081AB1B2
	.pool
_081AB13C:
	bl IsWallysBag
	lsls r0, 24
	cmp r0, 0
	bne _081AB164
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _081AB164
	ldr r0, =gUnknown_08D9A5D4
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	b _081AB1AE
	.pool
_081AB164:
	ldr r0, =gUnknown_08D9A588
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	b _081AB1AE
	.pool
_081AB174:
	bl IsWallysBag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AB18A
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _081AB19C
_081AB18A:
	ldr r0, =gUnknown_0857FB34
	bl LoadCompressedObjectPic
	b _081AB1AE
	.pool
_081AB19C:
	ldr r0, =gUnknown_0857FB3C
	bl LoadCompressedObjectPic
	b _081AB1AE
	.pool
_081AB1A8:
	ldr r0, =gUnknown_0857FB44
	bl LoadCompressedObjectPalette
_081AB1AE:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
_081AB1B2:
	ldr r0, =0x00000834
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081AB1E4
	.pool
_081AB1CC:
	bl sub_8122328
	ldr r0, [r4]
	ldr r1, =0x00000834
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _081AB1E6
	.pool
_081AB1E4:
	movs r0, 0
_081AB1E6:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end load_bag_menu_graphics

	thumb_func_start sub_81AB1F0
sub_81AB1F0: @ 81AB1F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	bne _081AB204
	ldr r0, =Task_WallyTutorialBagMenu
	b _081AB206
	.pool
_081AB204:
	ldr r0, =Task_BagMenu
_081AB206:
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81AB1F0

	thumb_func_start allocate_bag_item_list_buffers
allocate_bag_item_list_buffers: @ 81AB218
	push {r4,lr}
	ldr r4, =gUnknown_0203CE74
	movs r0, 0x82
	lsls r0, 2
	bl Alloc
	str r0, [r4]
	ldr r4, =gUnknown_0203CE78
	movs r0, 0xC3
	lsls r0, 3
	bl Alloc
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end allocate_bag_item_list_buffers

	thumb_func_start load_bag_item_list_buffers
@ void load_bag_item_list_buffers(int pocket_id)
load_bag_item_list_buffers: @ 81AB240
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, r7, 3
	ldr r0, =gBagPockets
	adds r1, r0
	mov r8, r1
	ldr r0, =gUnknown_0203CE54
	ldr r2, [r0]
	ldr r1, =0x0000081b
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081AB2FC
	movs r6, 0
	ldr r3, =0x00000829
	adds r0, r2, r3
	adds r0, r7
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _081AB2B6
	ldr r5, =gUnknown_0203CE78
_081AB276:
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r0, [r5]
	adds r0, r4
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r6, 2
	adds r1, r2
	ldrh r1, [r1]
	bl get_name
	ldr r0, =gUnknown_0203CE74
	ldr r0, [r0]
	lsls r1, r6, 3
	adds r1, r0
	ldr r0, [r5]
	adds r0, r4
	str r0, [r1]
	str r6, [r1, 0x4]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r3, =0x00000829
	adds r0, r3
	adds r0, r7
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	blt _081AB276
_081AB2B6:
	ldr r5, =gUnknown_0203CE78
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gText_CloseBag
	bl StringCopy
	ldr r0, =gUnknown_0203CE74
	ldr r0, [r0]
	lsls r1, r6, 3
	adds r1, r0
	ldr r0, [r5]
	adds r0, r4
	str r0, [r1]
	movs r0, 0x2
	negs r0, r0
	str r0, [r1, 0x4]
	b _081AB34A
	.pool
_081AB2FC:
	movs r6, 0
	ldr r4, =0x00000829
	adds r0, r2, r4
	adds r0, r7
	ldrb r0, [r0]
	cmp r6, r0
	bcs _081AB34A
	ldr r5, =gUnknown_0203CE78
_081AB30C:
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r0, [r5]
	adds r0, r4
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r6, 2
	adds r1, r2
	ldrh r1, [r1]
	bl get_name
	ldr r0, =gUnknown_0203CE74
	ldr r0, [r0]
	lsls r1, r6, 3
	adds r1, r0
	ldr r0, [r5]
	adds r0, r4
	str r0, [r1]
	str r6, [r1, 0x4]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r3, =0x00000829
	adds r0, r3
	adds r0, r7
	ldrb r0, [r0]
	cmp r6, r0
	bcc _081AB30C
_081AB34A:
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_08613F9C
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r4, =0x00000829
	adds r0, r1, r4
	adds r0, r7
	ldrb r0, [r0]
	strh r0, [r2, 0xC]
	ldr r0, =gUnknown_0203CE74
	ldr r0, [r0]
	str r0, [r2]
	ldr r5, =0x0000082e
	adds r1, r5
	adds r1, r7
	ldrb r0, [r1]
	strh r0, [r2, 0xE]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end load_bag_item_list_buffers

	thumb_func_start get_name
@ void get_name(char *dest, int name_id)
get_name: @ 81AB39C
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x2
	beq _081AB3C0
	cmp r0, 0x3
	beq _081AB420
	adds r0, r5, 0
	adds r1, r6, 0
	bl CopyItemName
	b _081AB43E
	.pool
_081AB3C0:
	ldr r4, =gStringVar2
	adds r0, r5, 0
	bl ItemIdToBattleMoveId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0xA9
	lsls r0, 1
	cmp r5, r0
	bls _081AB408
	ldr r0, =gStringVar1
	ldr r2, =0xfffffeae
	adds r1, r5, r2
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_ClearTo11Var1Clear5Var2
	b _081AB438
	.pool
_081AB408:
	ldr r0, =gStringVar1
	ldr r2, =0xfffffee0
	adds r1, r5, r2
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	b _081AB436
	.pool
_081AB420:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	subs r1, 0x84
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	adds r0, r5, 0
	bl CopyItemName
_081AB436:
	ldr r1, =gText_UnkF908Var1Clear7Var2
_081AB438:
	adds r0, r6, 0
	bl StringExpandPlaceholders
_081AB43E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end get_name

	thumb_func_start bag_menu_change_item_callback
bag_menu_change_item_callback: @ 81AB450
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081AB466
	movs r0, 0x5
	bl PlaySE
	bl ShakeBagVisual
_081AB466:
	ldr r4, =gUnknown_0203CE54
	ldr r1, [r4]
	ldr r2, =0x0000081a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081AB50C
	adds r2, 0x1
	adds r0, r1, r2
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 30
	movs r0, 0x1
	eors r0, r1
	bl RemoveBagItemIconObject
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081AB4C8
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r6, 16
	lsrs r1, 16
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4]
	ldr r2, =0x0000081b
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 26
	lsrs r1, 30
	bl AddBagItemIconObject
	b _081AB4DA
	.pool
_081AB4C8:
	ldr r0, =0x0000ffff
	ldr r1, [r4]
	ldr r2, =0x0000081b
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 26
	lsrs r1, 30
	bl AddBagItemIconObject
_081AB4DA:
	ldr r5, =gUnknown_0203CE54
	ldr r2, [r5]
	ldr r4, =0x0000081b
	adds r2, r4
	ldrb r3, [r2]
	lsls r0, r3, 26
	lsrs r0, 30
	movs r1, 0x1
	eors r1, r0
	lsls r1, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _081AB50C
	adds r0, r6, 0
	bl bag_menu_print_description_box_text
_081AB50C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_change_item_callback

	thumb_func_start sub_81AB520
@ void sub_81AB520(u8 rbox_id, int item_index_in_pocket, int a3)
sub_81AB520: @ 81AB520
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r2, 24
	lsrs r7, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081AB540
	b _081AB696
_081AB540:
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x0000081a
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _081AB570
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081AB568
	adds r0, r7, 0
	movs r1, 0x2
	bl bag_menu_print_cursor
	b _081AB570
	.pool
_081AB568:
	adds r0, r7, 0
	movs r1, 0xFF
	bl bag_menu_print_cursor
_081AB570:
	ldr r5, =gUnknown_0203CE58
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 16
	lsrs r4, 16
	adds r1, r4, 0
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	lsrs r6, r0, 16
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl BagGetQuantityByPocketPosition
	lsls r0, 16
	lsrs r4, r0, 16
	mov r9, r4
	ldr r1, =0xfffffead
	adds r0, r6, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7
	bhi _081AB5BE
	ldr r1, =gUnknown_08DC6378
	subs r3, r7, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x10
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0x8
	bl BlitBitmapToWindow
_081AB5BE:
	ldrb r0, [r5, 0x5]
	cmp r0, 0x3
	bne _081AB610
	ldr r0, =gStringVar1
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x77
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	str r7, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0xFF
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	b _081AB652
	.pool
_081AB610:
	cmp r0, 0x4
	beq _081AB66C
	adds r0, r6, 0
	bl itemid_is_unique
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081AB66C
	ldr r0, =gStringVar1
	mov r1, r9
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x77
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	str r7, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0xFF
	str r0, [sp, 0xC]
	str r5, [sp, 0x10]
_081AB652:
	mov r0, r8
	movs r1, 0x7
	adds r2, r4, 0
	bl bag_menu_print
	b _081AB696
	.pool
_081AB66C:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00000496
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081AB696
	cmp r0, r6
	bne _081AB696
	ldr r1, =gUnknown_086140A4
	subs r3, r7, 0x1
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x18
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0x60
	bl BlitBitmapToWindow
_081AB696:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AB520

	thumb_func_start bag_menu_print_description_box_text
@ void bag_menu_print_description_box_text(int a1)
bag_menu_print_description_box_text: @ 81AB6B0
	push {r4,lr}
	sub sp, 0x14
	adds r1, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _081AB6E0
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	lsrs r0, 16
	bl ItemId_GetDescription
	adds r4, r0, 0
	b _081AB6FC
	.pool
_081AB6E0:
	ldr r0, =gStringVar1
	ldr r2, =gReturnToXStringsTable
	ldr r1, =gUnknown_0203CE58
	ldrb r1, [r1, 0x4]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_ReturnToVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
_081AB6FC:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print_description_box_text

	thumb_func_start bag_menu_print_cursor_
bag_menu_print_cursor_: @ 81AB73C
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl bag_menu_print_cursor
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bag_menu_print_cursor_

	thumb_func_start bag_menu_print_cursor
bag_menu_print_cursor: @ 81AB75C
	push {r4,r5,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0xFF
	bne _081AB798
	movs r0, 0x1
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl FillWindowPixelRect
	b _081AB7AE
_081AB798:
	ldr r2, =gText_SelectorArrow2
	str r5, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0
	bl bag_menu_print
_081AB7AE:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print_cursor

	thumb_func_start bag_menu_add_pocket_scroll_arrow_indicators_maybe
bag_menu_add_pocket_scroll_arrow_indicators_maybe: @ 81AB7BC
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_0203CE54
	ldr r4, [r5]
	ldr r1, =0x0000081e
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081AB80A
	ldr r2, =gUnknown_0203CE58
	ldrb r3, [r2, 0x5]
	ldr r6, =0x00000829
	adds r0, r4, r6
	adds r0, r3
	ldrb r1, [r0]
	adds r6, 0x5
	adds r0, r4, r6
	adds r0, r3
	ldrb r0, [r0]
	subs r1, r0
	str r1, [sp]
	movs r0, 0x6E
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	ldrb r0, [r2, 0x5]
	lsls r0, 1
	adds r2, 0x12
	adds r0, r2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xAC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	ldr r1, [r5]
	ldr r2, =0x0000081e
	adds r1, r2
	strb r0, [r1]
_081AB80A:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_add_pocket_scroll_arrow_indicators_maybe

	thumb_func_start sub_81AB824
sub_81AB824: @ 81AB824
	push {r4,lr}
	ldr r4, =gUnknown_0203CE54
	ldr r0, [r4]
	ldr r2, =0x0000081e
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081AB842
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x0000081e
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_081AB842:
	bl sub_81AB89C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AB824

	thumb_func_start bag_menu_add_list_scroll_arrow_indicators_maybe
bag_menu_add_list_scroll_arrow_indicators_maybe: @ 81AB854
	push {r4,lr}
	ldr r4, =gUnknown_0203CE54
	ldr r2, [r4]
	ldr r1, =0x0000081b
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	beq _081AB882
	ldr r1, =0x0000081f
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081AB882
	ldr r0, =gUnknown_08614094
	ldr r1, =gUnknown_0203CE5E
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r2, =0x0000081f
	adds r1, r2
	strb r0, [r1]
_081AB882:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_add_list_scroll_arrow_indicators_maybe

	thumb_func_start sub_81AB89C
sub_81AB89C: @ 81AB89C
	push {r4,lr}
	ldr r4, =gUnknown_0203CE54
	ldr r0, [r4]
	ldr r2, =0x0000081f
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081AB8BA
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x0000081f
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_081AB8BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AB89C

	thumb_func_start free_bag_item_list_buffers
free_bag_item_list_buffers: @ 81AB8C8
	push {lr}
	ldr r0, =gUnknown_0203CE78
	ldr r0, [r0]
	bl Free
	ldr r0, =gUnknown_0203CE74
	ldr r0, [r0]
	bl Free
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end free_bag_item_list_buffers

	thumb_func_start unknown_ItemMenu_Confirm
unknown_ItemMenu_Confirm: @ 81AB8F8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_close_bag_menu_2
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_ItemMenu_Confirm

	thumb_func_start task_close_bag_menu_2
task_close_bag_menu_2: @ 81AB930
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081AB9A0
	ldrb r0, [r2]
	ldr r4, =gUnknown_0203CE58
	ldrb r2, [r4, 0x5]
	lsls r2, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r2, r1
	adds r3, r4, 0
	adds r3, 0x8
	adds r2, r3
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _081AB984
	bl SetMainCallback2
	b _081AB98A
	.pool
_081AB984:
	ldr r0, [r4]
	bl SetMainCallback2
_081AB98A:
	bl sub_81AB824
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl free_bag_item_list_buffers
	adds r0, r5, 0
	bl DestroyTask
_081AB9A0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_close_bag_menu_2

	thumb_func_start sub_81AB9A8
sub_81AB9A8: @ 81AB9A8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, r5, 3
	ldr r0, =gBagPockets
	adds r4, r1, r0
	cmp r5, 0x3
	bgt _081AB9C8
	cmp r5, 0x2
	blt _081AB9C8
	adds r0, r4, 0
	bl sub_80D6FB4
	b _081AB9CE
	.pool
_081AB9C8:
	adds r0, r4, 0
	bl sub_80D6F64
_081AB9CE:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r6, =0x00000829
	adds r1, r6
	adds r1, r5
	movs r2, 0
	strb r2, [r1]
	adds r3, r0, 0
	ldrb r0, [r4, 0x4]
	cmp r2, r0
	bcs _081ABA12
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _081ABA12
	adds r7, r3, 0
_081AB9EE:
	ldr r0, [r7]
	adds r0, r6
	adds r0, r5
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrb r1, [r4, 0x4]
	cmp r2, r1
	bcs _081ABA12
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _081AB9EE
_081ABA12:
	ldr r2, [r3]
	ldr r1, =0x0000081b
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081ABA2E
	ldr r0, =0x00000829
	adds r1, r2, r0
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081ABA2E:
	ldr r1, [r3]
	ldr r2, =0x00000829
	adds r0, r1, r2
	adds r0, r5
	ldrb r2, [r0]
	cmp r2, 0x8
	bls _081ABA58
	ldr r3, =0x0000082e
	adds r0, r1, r3
	adds r0, r5
	movs r1, 0x8
	strb r1, [r0]
	b _081ABA60
	.pool
_081ABA58:
	ldr r3, =0x0000082e
	adds r0, r1, r3
	adds r0, r5
	strb r2, [r0]
_081ABA60:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AB9A8

	thumb_func_start sub_81ABA6C
sub_81ABA6C: @ 81ABA6C
	push {r4,lr}
	movs r4, 0
_081ABA70:
	adds r0, r4, 0
	bl sub_81AB9A8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081ABA70
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81ABA6C

	thumb_func_start sub_81ABA88
sub_81ABA88: @ 81ABA88
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	ldr r2, =gUnknown_0203CE6A
	adds r4, r1, r2
	subs r2, 0xA
	adds r1, r2
	ldr r2, =gUnknown_0203CE54
	ldr r3, [r2]
	ldr r5, =0x0000082e
	adds r2, r3, r5
	adds r2, r0
	ldrb r2, [r2]
	subs r5, 0x5
	adds r3, r5
	adds r3, r0
	ldrb r3, [r3]
	adds r0, r4, 0
	bl sub_812225C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ABA88

	thumb_func_start sub_81ABAC4
sub_81ABAC4: @ 81ABAC4
	push {r4,lr}
	movs r4, 0
_081ABAC8:
	adds r0, r4, 0
	bl sub_81ABA88
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081ABAC8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81ABAC4

	thumb_func_start sub_81ABAE0
sub_81ABAE0: @ 81ABAE0
	push {r4-r7,lr}
	sub sp, 0x4
	movs r5, 0
	ldr r6, =gUnknown_0203CE6A
	adds r7, r6, 0
	subs r7, 0xA
_081ABAEC:
	lsls r1, r5, 1
	adds r0, r1, r6
	adds r1, r7
	ldr r2, =gUnknown_0203CE54
	ldr r3, [r2]
	ldr r4, =0x0000082e
	adds r2, r3, r4
	adds r2, r5
	ldrb r2, [r2]
	subs r4, 0x5
	adds r3, r4
	adds r3, r5
	ldrb r3, [r3]
	movs r4, 0x8
	str r4, [sp]
	bl sub_8122298
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _081ABAEC
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ABAE0

	thumb_func_start sub_81ABB2C
sub_81ABB2C: @ 81ABB2C
	lsls r0, 24
	ldr r1, =gUnknown_0203CE58
	lsrs r0, 23
	adds r2, r1, 0
	adds r2, 0x12
	adds r2, r0, r2
	adds r1, 0x8
	adds r0, r1
	ldrb r0, [r0]
	ldrb r2, [r2]
	adds r0, r2
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_81ABB2C

	thumb_func_start DisplayItemMessage
@ void DisplayItemMessage(u8 taskId, u8 fontId, u8 *str, void ( *callback)(u8 taskId))
DisplayItemMessage: @ 81ABB4C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r9, r3
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0x4
	bl AddItemMessageWindow
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl GetPlayerTextSpeed
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r4, 0x14]
	str r6, [sp]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisplayItemMessage

	thumb_func_start bag_menu_inits_lists_menu
bag_menu_inits_lists_menu: @ 81ABBBC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r5, r6, 2
	adds r5, r6
	lsls r5, 3
	ldr r0, =gTasks + 0x8
	adds r5, r0
	ldr r7, =gUnknown_0203CE58
	ldrb r4, [r7, 0x5]
	lsls r4, 1
	movs r0, 0x12
	adds r0, r7
	mov r8, r0
	add r8, r4
	adds r0, r7, 0
	adds r0, 0x8
	adds r4, r0
	movs r0, 0x4
	bl bag_menu_RemoveBagItem_message_window
	ldrb r0, [r5]
	mov r1, r8
	adds r2, r4, 0
	bl sub_81AE6C8
	ldrb r0, [r7, 0x5]
	bl sub_81AB9A8
	ldrb r0, [r7, 0x5]
	bl sub_81ABA88
	ldrb r0, [r7, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r4]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl set_callback3_to_bag
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_inits_lists_menu

	thumb_func_start sub_81ABC3C
sub_81ABC3C: @ 81ABC3C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl bag_menu_add_window
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81ABC54
	pop {r0}
	bx r0
	thumb_func_end sub_81ABC3C

	thumb_func_start sub_81ABC54
sub_81ABC54: @ 81ABC54
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	movs r3, 0x2
	cmp r0, 0x3
	bne _081ABC6C
	movs r3, 0x3
_081ABC6C:
	ldr r0, =gStringVar1
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ABC54

	thumb_func_start sub_81ABCC0
sub_81ABCC0: @ 81ABCC0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r7, r2, 0
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	movs r3, 0x2
	cmp r0, 0x3
	bne _081ABCD4
	movs r3, 0x3
_081ABCD4:
	ldr r0, =gStringVar1
	movs r2, 0x2
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r6, 0
	bl StringExpandPlaceholders
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0
	bl PrintTextOnWindow
	str r5, [sp]
	adds r0, r4, 0
	movs r1, 0x26
	movs r2, 0x1
	adds r3, r7, 0
	bl PrintMoneyAmount
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ABCC0

	thumb_func_start Task_BagMenu
Task_BagMenu: @ 81ABD28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	str r0, [sp]
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r5, =gUnknown_0203CE58
	ldrb r0, [r5, 0x5]
	lsls r0, 1
	adds r1, r5, 0
	adds r1, 0x12
	adds r7, r0, r1
	subs r1, 0xA
	adds r0, r1
	mov r8, r0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081ABD66
	b _081ABEB2
_081ABD66:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081ABD74
	b _081ABEB2
_081ABD74:
	bl GetSwitchBagPocketDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081ABDB8
	cmp r0, 0x2
	beq _081ABDC0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	cmp r0, 0
	beq _081ABE10
	bl sub_81AC2C0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081ABDA4
	b _081ABEB2
_081ABDA4:
	b _081ABDCC
	.pool
_081ABDB8:
	movs r1, 0x1
	negs r1, r1
	mov r0, r9
	b _081ABDC4
_081ABDC0:
	mov r0, r9
	movs r1, 0x1
_081ABDC4:
	movs r2, 0
	bl SwitchBagPocket
	b _081ABEB2
_081ABDCC:
	ldrb r0, [r6]
	adds r1, r7, 0
	mov r2, r8
	bl get_coro_args_x18_x1A
	ldrh r2, [r7]
	mov r3, r8
	ldrh r0, [r3]
	adds r2, r0
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =gUnknown_0203CE58
	ldr r3, =0x00000829
	adds r0, r3
	ldrb r1, [r1, 0x5]
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r2, r0
	beq _081ABEB2
	movs r0, 0x5
	bl PlaySE
	mov r0, r9
	bl bag_menu_swap_items
	b _081ABEB2
	.pool
_081ABE10:
	ldrb r0, [r6]
	bl ListMenuHandleInput
	adds r4, r0, 0
	ldrb r0, [r6]
	adds r1, r7, 0
	mov r2, r8
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081ABE32
	adds r0, 0x1
	cmp r4, r0
	bne _081ABE68
	b _081ABEB2
_081ABE32:
	ldrb r0, [r5, 0x4]
	cmp r0, 0x5
	bne _081ABE40
	movs r0, 0x20
	bl PlaySE
	b _081ABEB2
_081ABE40:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSpecialVar_ItemId
	mov r1, r10
	strh r1, [r0]
	ldr r0, =gTasks + 0x8
	subs r0, 0x8
	ldr r3, [sp]
	adds r0, r3, r0
	ldr r1, =unknown_ItemMenu_Confirm
	str r1, [r0]
	b _081ABEB2
	.pool
_081ABE68:
	movs r0, 0x5
	bl PlaySE
	bl sub_81AB824
	ldrb r0, [r6]
	movs r1, 0x2
	bl bag_menu_print_cursor_
	strh r4, [r6, 0x2]
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 16
	lsrs r4, 16
	adds r1, r4, 0
	bl BagGetQuantityByPocketPosition
	strh r0, [r6, 0x4]
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl BagGetItemIdByPocketPosition
	ldr r1, =gSpecialVar_ItemId
	strh r0, [r1]
	ldr r1, =gUnknown_08614054
	ldrb r0, [r5, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	mov r0, r9
	bl _call_via_r1
_081ABEB2:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_BagMenu

	thumb_func_start set_callback3_to_bag
set_callback3_to_bag: @ 81ABECC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl bag_menu_add_pocket_scroll_arrow_indicators_maybe
	bl bag_menu_add_list_scroll_arrow_indicators_maybe
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x4
	bl ClearWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =Task_BagMenu
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_callback3_to_bag

	thumb_func_start GetSwitchBagPocketDirection
GetSwitchBagPocketDirection: @ 81ABF10
	push {lr}
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x0000081b
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081ABF6A
	bl GetLRKeysState
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081ABF3C
	cmp r2, 0x1
	bne _081ABF54
_081ABF3C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	b _081ABF6C
	.pool
_081ABF54:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081ABF60
	cmp r2, 0x2
	bne _081ABF6A
_081ABF60:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x2
	b _081ABF6C
_081ABF6A:
	movs r0, 0
_081ABF6C:
	pop {r1}
	bx r1
	thumb_func_end GetSwitchBagPocketDirection

	thumb_func_start ChangeBagPocketId
@ void ChangeBagPocketId(u8 *bagPocketId, u8 deltaBagPocketId)
ChangeBagPocketId: @ 81ABF70
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	asrs r1, 24
	cmp r1, 0x1
	bne _081ABF88
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _081ABF88
	movs r0, 0
	b _081ABFA0
_081ABF88:
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	ldrb r3, [r2]
	cmp r0, r1
	bne _081ABF9E
	cmp r3, 0
	bne _081ABF9E
	movs r0, 0x4
	b _081ABFA0
_081ABF9E:
	adds r0, r3, r4
_081ABFA0:
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ChangeBagPocketId

	thumb_func_start SwitchBagPocket
@ void SwitchBagPocket(u8 taskId, u16 deltaBagPocketId, u16 a3)
SwitchBagPocket: @ 81ABFA8
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x18]
	strh r5, [r4, 0x16]
	cmp r2, 0
	bne _081AC026
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0x1
	bl ClearWindowTilemap
	ldrb r0, [r4]
	ldr r3, =gUnknown_0203CE58
	ldrb r2, [r3, 0x5]
	lsls r2, 1
	adds r1, r3, 0
	adds r1, 0x12
	adds r1, r2, r1
	adds r3, 0x8
	adds r2, r3
	bl sub_81AE6C8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r3, =gSprites
	ldr r0, =gUnknown_0203CE54
	ldr r2, [r0]
	ldr r1, =0x0000081b
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 30
	movs r0, 0x1
	eors r0, r1
	adds r2, r0
	ldr r0, =0x00000806
	adds r2, r0
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	bl sub_81AB824
_081AC026:
	ldr r4, =gUnknown_0203CE58
	ldrb r1, [r4, 0x5]
	add r0, sp, 0x8
	strb r1, [r0]
	lsls r1, r5, 24
	asrs r1, 24
	bl ChangeBagPocketId
	lsls r0, r5, 16
	asrs r1, r0, 16
	adds r5, r0, 0
	cmp r1, 0x1
	bne _081AC07C
	ldr r2, =gPocketNamesStringsTable
	ldrb r0, [r4, 0x5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	add r1, sp, 0x8
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl bag_menu_print_pocket_names
	movs r0, 0
	bl bag_menu_copy_pocket_name_to_window
	b _081AC09A
	.pool
_081AC07C:
	ldr r2, =gPocketNamesStringsTable
	add r0, sp, 0x8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldrb r1, [r4, 0x5]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl bag_menu_print_pocket_names
	movs r0, 0x8
	bl bag_menu_copy_pocket_name_to_window
_081AC09A:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	movs r1, 0
	bl bag_menu_draw_pocket_indicator_square
	add r0, sp, 0x8
	ldrb r0, [r0]
	movs r1, 0x1
	bl bag_menu_draw_pocket_indicator_square
	movs r0, 0xF
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0xB
	movs r2, 0xE
	movs r3, 0x2
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add r0, sp, 0x8
	ldrb r0, [r0]
	movs r1, 0x1
	bl SetBagVisualPocketId
	movs r0, 0x1
	bl RemoveBagObject
	asrs r0, r5, 16
	bl AddSwitchPocketRotatingBallObject
	ldr r1, =sub_81AC10C
	ldr r2, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r2
	ldr r2, [r0]
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SwitchBagPocket

	thumb_func_start sub_81AC10C
sub_81AC10C: @ 81AC10C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	bl sub_81221AC
	lsls r0, 24
	cmp r0, 0
	bne _081AC184
	bl IsWallysBag
	lsls r0, 24
	cmp r0, 0
	bne _081AC184
	bl GetSwitchBagPocketDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AC148
	cmp r0, 0x2
	beq _081AC164
	b _081AC184
	.pool
_081AC148:
	ldr r0, =gUnknown_0203CE5D
	movs r1, 0x16
	ldrsb r1, [r6, r1]
	bl ChangeBagPocketId
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
	movs r1, 0x1
	negs r1, r1
	adds r0, r7, 0
	b _081AC178
	.pool
_081AC164:
	ldr r0, =gUnknown_0203CE5D
	movs r1, 0x16
	ldrsb r1, [r6, r1]
	bl ChangeBagPocketId
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
	adds r0, r7, 0
	movs r1, 0x1
_081AC178:
	movs r2, 0x1
	bl SwitchBagPocket
	b _081AC22E
	.pool
_081AC184:
	movs r1, 0x1A
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _081AC192
	cmp r0, 0x1
	beq _081AC1DC
	b _081AC22E
_081AC192:
	ldrb r0, [r6, 0x18]
	bl sub_81AC23C
	ldrh r0, [r6, 0x18]
	adds r1, r0, 0x1
	strh r1, [r6, 0x18]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081AC1CC
	movs r2, 0x16
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bne _081AC1BC
	lsls r0, r1, 16
	asrs r0, 17
	lsls r0, 24
	lsrs r0, 24
	bl bag_menu_copy_pocket_name_to_window
	b _081AC1CC
_081AC1BC:
	lsls r1, 16
	asrs r1, 17
	movs r0, 0x8
	subs r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl bag_menu_copy_pocket_name_to_window
_081AC1CC:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	cmp r0, 0x10
	bne _081AC22E
	ldrh r0, [r6, 0x1A]
	adds r0, 0x1
	strh r0, [r6, 0x1A]
	b _081AC22E
_081AC1DC:
	ldr r4, =gUnknown_0203CE5D
	movs r1, 0x16
	ldrsb r1, [r6, r1]
	adds r0, r4, 0
	bl ChangeBagPocketId
	subs r5, r4, 0x5
	ldrb r0, [r5, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	ldrb r2, [r5, 0x5]
	lsls r2, 1
	adds r1, r4, 0
	adds r1, 0xD
	adds r1, r2, r1
	ldrh r1, [r1]
	adds r4, 0x3
	adds r2, r4
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6]
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	bl bag_menu_add_pocket_scroll_arrow_indicators_maybe
	bl bag_menu_add_list_scroll_arrow_indicators_maybe
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
_081AC22E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AC10C

	thumb_func_start sub_81AC23C
sub_81AC23C: @ 81AC23C
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r3, 24
	movs r0, 0x80
	lsls r0, 18
	adds r3, r0
	lsrs r3, 24
	movs r0, 0xF
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x11
	movs r2, 0xE
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81AC23C

	thumb_func_start bag_menu_draw_pocket_indicator_square
@ void bag_menu_draw_pocket_indicator_square(char x, int is_current_bag)
bag_menu_draw_pocket_indicator_square: @ 81AC26C
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	cmp r1, 0
	bne _081AC298
	ldr r1, =0x00001017
	adds r2, r0, 0x5
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0x3
	bl FillBgTilemapBufferRect_Palette0
	b _081AC2AE
	.pool
_081AC298:
	ldr r1, =0x0000102b
	adds r2, r0, 0x5
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0x3
	bl FillBgTilemapBufferRect_Palette0
_081AC2AE:
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_draw_pocket_indicator_square

	thumb_func_start sub_81AC2C0
sub_81AC2C0: @ 81AC2C0
	push {lr}
	ldr r1, =gUnknown_0203CE58
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	bhi _081AC2E0
	ldrb r0, [r1, 0x5]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081AC2E0
	movs r0, 0x1
	b _081AC2E2
	.pool
_081AC2E0:
	movs r0, 0
_081AC2E2:
	pop {r1}
	bx r1
	thumb_func_end sub_81AC2C0

	thumb_func_start bag_menu_swap_items
bag_menu_swap_items: @ 81AC2E8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r6, r4, r0
	ldrb r0, [r6]
	movs r1, 0x10
	movs r2, 0x1
	bl sub_81AF15C
	ldr r3, =gUnknown_0203CE58
	ldrb r0, [r3, 0x5]
	lsls r0, 1
	adds r2, r3, 0
	adds r2, 0x12
	adds r2, r0, r2
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	strh r1, [r6, 0x2]
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r2, =0x0000081a
	adds r0, r2
	movs r5, 0
	strb r1, [r0]
	ldrb r0, [r3, 0x5]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x2]
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar4
	mov r8, r0
	ldr r1, =gText_MoveVar1Where
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	str r5, [sp, 0xC]
	str r5, [sp, 0x10]
	movs r1, 0x1
	mov r2, r8
	movs r3, 0x3
	bl bag_menu_print
	ldrb r0, [r6, 0x2]
	bl sub_80D4FEC
	bl sub_81AB89C
	ldrb r0, [r6]
	movs r1, 0x2
	bl bag_menu_print_cursor_
	movs r2, 0x8
	negs r2, r2
	add r9, r2
	add r4, r9
	ldr r0, =sub_81AC3C0
	str r0, [r4]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_swap_items

	thumb_func_start sub_81AC3C0
@ void sub_81AC3C0(u8 taskId)
sub_81AC3C0: @ 81AC3C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AC48E
	ldr r0, =gMain
	mov r8, r0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081AC418
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	ldr r3, =gUnknown_0203CE58
	ldrb r2, [r3, 0x5]
	lsls r2, 1
	adds r1, r3, 0
	adds r1, 0x12
	adds r1, r2, r1
	adds r3, 0x8
	adds r2, r3
	bl get_coro_args_x18_x1A
	b _081AC472
	.pool
_081AC418:
	ldrb r0, [r4]
	bl ListMenuHandleInput
	adds r7, r0, 0
	ldrb r0, [r4]
	ldr r5, =gUnknown_0203CE58
	ldrb r2, [r5, 0x5]
	lsls r2, 1
	adds r1, r5, 0
	adds r1, 0x12
	adds r1, r2, r1
	adds r4, r5, 0
	adds r4, 0x8
	adds r2, r4
	bl get_coro_args_x18_x1A
	movs r0, 0
	bl sub_80D4FC8
	ldrb r0, [r5, 0x5]
	lsls r0, 1
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80D4FEC
	movs r0, 0x2
	negs r0, r0
	cmp r7, r0
	beq _081AC460
	adds r0, 0x1
	cmp r7, r0
	bne _081AC482
	b _081AC48E
	.pool
_081AC460:
	movs r0, 0x5
	bl PlaySE
	mov r0, r8
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AC47A
_081AC472:
	adds r0, r6, 0
	bl sub_81AC498
	b _081AC48E
_081AC47A:
	adds r0, r6, 0
	bl sub_81AC590
	b _081AC48E
_081AC482:
	movs r0, 0x5
	bl PlaySE
	adds r0, r6, 0
	bl sub_81AC498
_081AC48E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81AC3C0

	thumb_func_start sub_81AC498
sub_81AC498: @ 81AC498
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	mov r10, r0
	ldr r0, =gTasks + 0x8
	add r0, r10
	mov r9, r0
	ldr r5, =gUnknown_0203CE58
	ldrb r6, [r5, 0x5]
	lsls r1, r6, 1
	adds r0, r5, 0
	adds r0, 0x12
	adds r0, r1
	mov r8, r0
	ldr r2, =gUnknown_0203CE60
	adds r7, r1, r2
	ldrh r0, [r7]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	mov r0, r9
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	cmp r2, r4
	beq _081AC4E2
	subs r0, r4, 0x1
	cmp r2, r0
	bne _081AC4F8
_081AC4E2:
	adds r0, r3, 0
	bl sub_81AC590
	b _081AC566
	.pool
_081AC4F8:
	ldr r1, =gBagPockets
	lsls r0, r6, 3
	adds r0, r1
	ldr r0, [r0]
	adds r1, r2, 0
	adds r2, r4, 0
	bl sub_80D702C
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r2, =0x0000081a
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0]
	mov r1, r9
	ldrb r0, [r1]
	mov r1, r8
	adds r2, r7, 0
	bl sub_81AE6C8
	mov r2, r9
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	cmp r0, r4
	bge _081AC538
	ldrb r1, [r5, 0x5]
	lsls r1, 1
	ldr r2, =gUnknown_0203CE60
	adds r1, r2
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_081AC538:
	ldrb r0, [r5, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	mov r1, r9
	strh r0, [r1]
	movs r0, 0x1
	bl sub_80D4FC8
	bl bag_menu_add_list_scroll_arrow_indicators_maybe
	ldr r0, =gTasks + 0x8
	subs r0, 0x8
	add r0, r10
	ldr r1, =Task_BagMenu
	str r1, [r0]
_081AC566:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AC498

	thumb_func_start sub_81AC590
sub_81AC590: @ 81AC590
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	mov r9, r1
	ldr r0, =gTasks + 0x8
	mov r10, r0
	mov r7, r9
	add r7, r10
	ldr r4, =gUnknown_0203CE58
	ldrb r0, [r4, 0x5]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r6, r0, r1
	movs r1, 0x8
	adds r1, r4
	mov r8, r1
	adds r5, r0, r1
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x0000081a
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldrb r0, [r7]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_81AE6C8
	movs r0, 0x2
	ldrsh r2, [r7, r0]
	ldrh r0, [r6]
	ldrh r1, [r5]
	adds r0, r1
	cmp r2, r0
	bge _081AC5F2
	ldrb r1, [r4, 0x5]
	lsls r1, 1
	add r1, r8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_081AC5F2:
	ldrb r0, [r4, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	ldrh r1, [r6]
	ldrh r2, [r5]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r0, 0x1
	bl sub_80D4FC8
	bl bag_menu_add_list_scroll_arrow_indicators_maybe
	mov r0, r10
	subs r0, 0x8
	add r0, r9
	ldr r1, =Task_BagMenu
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AC590

	thumb_func_start sub_81AC644
sub_81AC644: @ 81AC644
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x4]
	subs r0, 0x1
	cmp r0, 0x9
	bls _081AC654
	b _081AC82C
_081AC654:
	lsls r0, 2
	ldr r1, =_081AC668
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AC668:
	.4byte _081AC690
	.4byte _081AC82C
	.4byte _081AC82C
	.4byte _081AC82C
	.4byte _081AC6E8
	.4byte _081AC82C
	.4byte _081AC76C
	.4byte _081AC7CC
	.4byte _081AC70C
	.4byte _081AC690
_081AC690:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl ItemId_GetBattleUsage
	lsls r0, 24
	cmp r0, 0
	beq _081AC6C4
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614042
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x2
	b _081ACA10
	.pool
_081AC6C4:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614046
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x1
	b _081ACA10
	.pool
_081AC6E8:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614047
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x4
	b _081ACA10
	.pool
_081AC70C:
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AC748
	ldrh r0, [r4]
	cmp r0, 0xAF
	beq _081AC748
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_0861404B
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x2
	b _081ACA10
	.pool
_081AC748:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614046
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x1
	b _081ACA10
	.pool
_081AC76C:
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AC7A8
	ldrh r0, [r4]
	cmp r0, 0xAF
	beq _081AC7A8
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_0861404D
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x2
	b _081ACA10
	.pool
_081AC7A8:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614046
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x1
	b _081ACA10
	.pool
_081AC7CC:
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AC808
	ldrh r0, [r4]
	cmp r0, 0xAF
	beq _081AC808
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_0861404F
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x2
	b _081ACA10
	.pool
_081AC808:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614046
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x1
	b _081ACA10
	.pool
_081AC82C:
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AC840
	bl InUnionRoom
	cmp r0, 0x1
	bne _081AC8A4
_081AC840:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x4
	beq _081AC856
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl sub_8122148
	lsls r0, 24
	cmp r0, 0
	bne _081AC880
_081AC856:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614046
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x1
	b _081ACA10
	.pool
_081AC880:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614044
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x2
	b _081ACA10
	.pool
_081AC8A4:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x4
	bls _081AC8AE
	b _081ACA12
_081AC8AE:
	lsls r0, 2
	ldr r1, =_081AC8C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AC8C0:
	.4byte _081AC8D4
	.4byte _081AC9B4
	.4byte _081AC9D8
	.4byte _081AC9FC
	.4byte _081AC92C
_081AC8D4:
	ldr r4, =gUnknown_0203CE54
	ldr r1, [r4]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r3, =0x00000824
	adds r0, r1, r3
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =gUnknown_0861402C
	movs r2, 0x4
	bl memcpy
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081AC90A
	b _081ACA12
_081AC90A:
	ldr r0, [r4]
	ldr r1, =0x00000824
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	b _081ACA12
	.pool
_081AC92C:
	ldr r4, =gUnknown_0203CE54
	ldr r1, [r4]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r5, =0x00000824
	adds r0, r1, r5
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r5
	ldr r1, =gUnknown_08614030
	movs r2, 0x4
	bl memcpy
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00000496
	adds r0, r1
	ldr r2, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldrh r1, [r2]
	cmp r0, r1
	bne _081AC96C
	ldr r0, [r4]
	ldr r1, =0x00000825
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
_081AC96C:
	ldrh r1, [r2]
	ldr r0, =0x00000103
	cmp r1, r0
	beq _081AC97A
	adds r0, 0xD
	cmp r1, r0
	bne _081ACA12
_081AC97A:
	movs r0, 0x6
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _081ACA12
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x7
	strb r1, [r0]
	b _081ACA12
	.pool
_081AC9B4:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614034
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x4
	b _081ACA10
	.pool
_081AC9D8:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_08614038
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x4
	b _081ACA10
	.pool
_081AC9FC:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	movs r0, 0x82
	lsls r0, 4
	adds r2, r1, r0
	ldr r0, =gUnknown_0861403C
	str r0, [r2]
	ldr r0, =0x00000828
	adds r1, r0
	movs r0, 0x6
_081ACA10:
	strb r0, [r1]
_081ACA12:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x2
	bne _081ACA50
	movs r0, 0x1
	bl ClearWindowTilemap
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl PrintTMHMMoveData
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x4
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	b _081ACA86
	.pool
_081ACA50:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1IsSelected
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
_081ACA86:
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000828
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081ACAB0
	movs r0, 0
	b _081ACAB6
	.pool
_081ACAB0:
	cmp r0, 0x2
	bne _081ACAC4
	movs r0, 0x1
_081ACAB6:
	bl bag_menu_add_window
	lsls r0, 24
	lsrs r0, 24
	bl sub_81ACAF8
	b _081ACAEE
_081ACAC4:
	cmp r0, 0x4
	bne _081ACADC
	movs r0, 0x2
	bl bag_menu_add_window
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	movs r2, 0x2
	bl sub_81ACB54
	b _081ACAEE
_081ACADC:
	movs r0, 0x3
	bl bag_menu_add_window
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	movs r2, 0x3
	bl sub_81ACB54
_081ACAEE:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81AC644

	thumb_func_start sub_81ACAF8
sub_81ACAF8: @ 81ACAF8
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	ldr r6, =gUnknown_0203CE54
	ldr r1, [r6]
	ldr r5, =0x00000828
	adds r0, r1, r5
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_08613FB4
	str r0, [sp, 0xC]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	ldr r0, [r1]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl AddItemMenuActionTextPrinters
	ldr r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ACAF8

	thumb_func_start sub_81ACB54
sub_81ACB54: @ 81ACB54
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x38
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	ldr r0, =gUnknown_08613FB4
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl sub_8198DBC
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x38
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8199944
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ACB54

	thumb_func_start unknown_item_menu_type
unknown_item_menu_type: @ 81ACBB0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_81AC644
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000828
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bhi _081ACBE8
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =Task_HandleInBattleItemMenuInput
	b _081ACBF4
	.pool
_081ACBE8:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =Task_HandleOutOfBattleItemMenuInput
_081ACBF4:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_item_menu_type

	thumb_func_start Task_HandleInBattleItemMenuInput
Task_HandleInBattleItemMenuInput: @ 81ACC04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081ACC6A
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081ACC6A
	adds r0, 0x1
	cmp r4, r0
	bne _081ACC44
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_08613FB4
	ldr r1, [r0, 0x24]
	adds r0, r5, 0
	bl _call_via_r1
	b _081ACC6A
	.pool
_081ACC44:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_08613FB4
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	movs r2, 0x82
	lsls r2, 4
	adds r0, r2
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl _call_via_r1
_081ACC6A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_HandleInBattleItemMenuInput

	thumb_func_start Task_HandleOutOfBattleItemMenuInput
Task_HandleOutOfBattleItemMenuInput: @ 81ACC78
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081ACC8C
	b _081ACDF0
_081ACC8C:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081ACCD4
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0
	bgt _081ACCAA
	b _081ACDF0
_081ACCAA:
	subs r0, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81ACDFC
	lsls r0, 24
	cmp r0, 0
	bne _081ACCBC
	b _081ACDF0
_081ACCBC:
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	bl sub_8199134
	b _081ACDF0
	.pool
_081ACCD4:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081ACD1C
	lsls r0, r4, 24
	asrs r1, r0, 24
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r2, =0x00000828
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x2
	cmp r1, r0
	blt _081ACCF2
	b _081ACDF0
_081ACCF2:
	adds r0, r1, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81ACDFC
	lsls r0, 24
	cmp r0, 0
	beq _081ACDF0
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	movs r1, 0x1
	bl sub_8199134
	b _081ACDF0
	.pool
_081ACD1C:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081ACD30
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081ACD58
_081ACD30:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081ACDF0
	subs r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81ACDFC
	lsls r0, 24
	cmp r0, 0
	beq _081ACDF0
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _081ACD92
_081ACD58:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081ACD6E
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081ACD9A
_081ACD6E:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081ACDF0
	adds r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81ACDFC
	lsls r0, 24
	cmp r0, 0
	beq _081ACDF0
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_081ACD92:
	movs r1, 0
	bl sub_8199134
	b _081ACDF0
_081ACD9A:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081ACDD8
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gUnknown_08613FB4
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	lsls r1, r4, 24
	asrs r1, 24
	movs r3, 0x82
	lsls r3, 4
	adds r0, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r2, 0x4
	adds r0, r2
	ldr r1, [r0]
	adds r0, r6, 0
	bl _call_via_r1
	b _081ACDF0
	.pool
_081ACDD8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081ACDF0
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_08613FB4
	ldr r1, [r0, 0x24]
	adds r0, r6, 0
	bl _call_via_r1
_081ACDF0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_HandleOutOfBattleItemMenuInput

	thumb_func_start sub_81ACDFC
sub_81ACDFC: @ 81ACDFC
	push {lr}
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081ACE30
	ldr r0, =gUnknown_0203CE54
	ldr r2, [r0]
	ldr r3, =0x00000828
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081ACE30
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _081ACE30
	movs r0, 0x1
	b _081ACE32
	.pool
_081ACE30:
	movs r0, 0
_081ACE32:
	pop {r1}
	bx r1
	thumb_func_end sub_81ACDFC

	thumb_func_start bag_menu_remove_some_window
bag_menu_remove_some_window: @ 81ACE38
	push {lr}
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000828
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081ACE58
	movs r0, 0
	bl bag_menu_remove_window
	b _081ACE76
	.pool
_081ACE58:
	cmp r0, 0x2
	bne _081ACE64
	movs r0, 0x1
	bl bag_menu_remove_window
	b _081ACE76
_081ACE64:
	cmp r0, 0x4
	bne _081ACE70
	movs r0, 0x2
	bl bag_menu_remove_window
	b _081ACE76
_081ACE70:
	movs r0, 0x3
	bl bag_menu_remove_window
_081ACE76:
	pop {r0}
	bx r0
	thumb_func_end bag_menu_remove_some_window

	thumb_func_start ItemMenu_UseOutOfBattle
@ void ItemMenu_UseOutOfBattle(u8 taskId)
ItemMenu_UseOutOfBattle: @ 81ACE7C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gSpecialVar_ItemId
	ldrh r0, [r5]
	bl ItemId_GetFieldFunc
	cmp r0, 0
	beq _081ACEEE
	bl bag_menu_remove_some_window
	bl CalculatePlayerPartyCount
	lsls r0, 24
	cmp r0, 0
	bne _081ACEB8
	ldrh r0, [r5]
	bl ItemId_GetType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081ACEB8
	adds r0, r4, 0
	bl bag_menu_print_there_is_no_pokemon
	b _081ACEEE
	.pool
_081ACEB8:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x3
	beq _081ACEE8
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl ItemId_GetFieldFunc
	adds r1, r0, 0
	adds r0, r4, 0
	bl _call_via_r1
	b _081ACEEE
	.pool
_081ACEE8:
	adds r0, r4, 0
	bl sub_80FDD10
_081ACEEE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ItemMenu_UseOutOfBattle

	thumb_func_start ItemMenu_Toss
ItemMenu_Toss: @ 81ACEF4
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	bl bag_menu_remove_some_window
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081ACF24
	adds r0, r5, 0
	bl BagMenuConfirmToss
	b _081ACF6A
	.pool
_081ACF24:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_TossHowManyVar1s
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
	movs r0, 0x7
	bl sub_81ABC3C
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =Task_ChooseHowManyToToss
	str r1, [r0]
_081ACF6A:
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemMenu_Toss

	thumb_func_start BagMenuConfirmToss
BagMenuConfirmToss: @ 81ACF88
	push {r4,r5,lr}
	sub sp, 0x14
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_ConfirmTossItems
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
	ldr r2, =gUnknown_08614084
	adds r0, r5, 0
	movs r1, 0x5
	bl bag_menu_yes_no
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BagMenuConfirmToss

	thumb_func_start BagMenuCancelToss
BagMenuCancelToss: @ 81AD010
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl bag_menu_print_description_box_text
	ldrb r0, [r4]
	movs r1, 0
	bl bag_menu_print_cursor_
	adds r0, r5, 0
	bl set_callback3_to_bag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BagMenuCancelToss

	thumb_func_start Task_ChooseHowManyToToss
Task_ChooseHowManyToToss: @ 81AD044
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x10
	ldrh r1, [r4, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081AD088
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000817
	adds r0, r1
	ldrb r0, [r0]
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	bl sub_81ABC54
	b _081AD0C6
	.pool
_081AD088:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AD0AC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	bl bag_menu_remove_window
	adds r0, r5, 0
	bl BagMenuConfirmToss
	b _081AD0C6
	.pool
_081AD0AC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081AD0C6
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	bl bag_menu_remove_window
	adds r0, r6, 0
	bl BagMenuCancelToss
_081AD0C6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end Task_ChooseHowManyToToss

	thumb_func_start BagMenuActuallyToss
BagMenuActuallyToss: @ 81AD0CC
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar4
	ldr r1, =gText_ThrewAwayVar2Var1s
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0x3
	bl bag_menu_print
	subs r5, 0x8
	adds r4, r5
	ldr r0, =Task_ActuallyToss
	str r0, [r4]
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BagMenuActuallyToss

	thumb_func_start Task_ActuallyToss
Task_ActuallyToss: @ 81AD150
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r4, =gUnknown_0203CE58
	ldrb r0, [r4, 0x5]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r0
	mov r8, r1
	adds r1, r4, 0
	adds r1, 0x8
	adds r7, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081AD1CE
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldrh r1, [r5, 0x10]
	bl RemoveBagItem
	ldrb r0, [r5]
	mov r1, r8
	adds r2, r7, 0
	bl sub_81AE6C8
	ldrb r0, [r4, 0x5]
	bl sub_81AB9A8
	ldrb r0, [r4, 0x5]
	bl sub_81ABA88
	ldrb r0, [r4, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl set_callback3_to_bag
_081AD1CE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_ActuallyToss

	thumb_func_start ItemMenu_Register
ItemMenu_Register: @ 81AD1EC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	ldr r0, =gUnknown_0203CE58
	ldrb r1, [r0, 0x5]
	lsls r1, 1
	adds r2, r0, 0
	adds r2, 0x12
	adds r6, r1, r2
	adds r0, 0x8
	adds r5, r1, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00000496
	adds r1, r0, r2
	ldr r0, =gSpecialVar_ItemId
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	bne _081AD238
	movs r0, 0
	strh r0, [r1]
	b _081AD23A
	.pool
_081AD238:
	strh r2, [r1]
_081AD23A:
	ldrb r0, [r7]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	ldrh r1, [r6]
	ldrh r2, [r5]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r4, 0
	bl ItemMenu_Cancel
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemMenu_Register

	thumb_func_start ItemMenu_Give
ItemMenu_Give: @ 81AD278
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	bl bag_menu_remove_some_window
	ldr r5, =gSpecialVar_ItemId
	ldrh r0, [r5]
	bl itemid_80BF6D8_mail_related
	lsls r0, 24
	cmp r0, 0
	bne _081AD2AC
	ldr r2, =gText_CantWriteMail
	ldr r3, =sub_81AD350
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _081AD2EA
	.pool
_081AD2AC:
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AD2E4
	bl CalculatePlayerPartyCount
	lsls r0, 24
	cmp r0, 0
	bne _081AD2CA
	adds r0, r4, 0
	bl bag_menu_print_there_is_no_pokemon
	b _081AD2EA
_081AD2CA:
	ldr r0, =gUnknown_0203CE54
	ldr r1, [r0]
	ldr r0, =sub_81B7F60
	str r0, [r1]
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	b _081AD2EA
	.pool
_081AD2E4:
	adds r0, r6, 0
	bl bag_menu_print_cant_be_held_msg
_081AD2EA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ItemMenu_Give

	thumb_func_start bag_menu_print_there_is_no_pokemon
bag_menu_print_there_is_no_pokemon: @ 81AD2F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_NoPokemon
	ldr r3, =sub_81AD350
	movs r1, 0x1
	bl DisplayItemMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print_there_is_no_pokemon

	thumb_func_start bag_menu_print_cant_be_held_msg
bag_menu_print_cant_be_held_msg: @ 81AD30C
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r5, =gStringVar4
	ldr r1, =gText_Var1CantBeHeld
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_81AD350
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl DisplayItemMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print_cant_be_held_msg

	thumb_func_start sub_81AD350
sub_81AD350: @ 81AD350
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AD36E
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl bag_menu_inits_lists_menu
_081AD36E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD350

	thumb_func_start ItemMenu_CheckTag
ItemMenu_CheckTag: @ 81AD378
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CE54
	ldr r2, [r1]
	ldr r1, =sub_8177C14
	str r1, [r2]
	bl unknown_ItemMenu_Confirm
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemMenu_CheckTag

	thumb_func_start ItemMenu_Cancel
ItemMenu_Cancel: @ 81AD398
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl bag_menu_remove_some_window
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl bag_menu_print_description_box_text
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldrb r0, [r4]
	movs r1, 0
	bl bag_menu_print_cursor_
	adds r0, r5, 0
	bl set_callback3_to_bag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemMenu_Cancel

	thumb_func_start ItemMenu_UseInBattle
ItemMenu_UseInBattle: @ 81AD3DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	cmp r0, 0
	beq _081AD400
	bl bag_menu_remove_some_window
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081AD400:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemMenu_UseInBattle

	thumb_func_start bag_menu_mail_related
bag_menu_mail_related: @ 81AD40C
	push {lr}
	movs r0, 0xC
	movs r1, 0x5
	movs r2, 0
	bl GoToBagMenu
	pop {r0}
	bx r0
	thumb_func_end bag_menu_mail_related

	thumb_func_start item_menu_type_2
item_menu_type_2: @ 81AD41C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl itemid_80BF6D8_mail_related
	lsls r0, 24
	cmp r0, 0
	bne _081AD44C
	ldr r2, =gText_CantWriteMail
	ldr r3, =sub_81AD350
	adds r0, r5, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _081AD4AE
	.pool
_081AD44C:
	ldrh r0, [r4]
	bl sub_8122148
	lsls r0, 24
	cmp r0, 0
	bne _081AD488
	ldrh r0, [r4]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1CantBeHeldHere
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_81AD350
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	b _081AD4AE
	.pool
_081AD488:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x4
	beq _081AD4A8
	ldrh r0, [r4]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AD4A8
	adds r0, r5, 0
	bl unknown_ItemMenu_Confirm
	b _081AD4AE
	.pool
_081AD4A8:
	adds r0, r5, 0
	bl bag_menu_print_cant_be_held_msg
_081AD4AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end item_menu_type_2

	thumb_func_start item_menu_type_b
item_menu_type_b: @ 81AD4B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gSpecialVar_ItemId
	ldrh r0, [r5]
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081AD4E4
	ldr r2, =gText_CantWriteMail
	ldr r3, =sub_81AD350
	adds r0, r4, 0
	movs r1, 0x1
	bl DisplayItemMessage
	b _081AD51A
	.pool
_081AD4E4:
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x5]
	cmp r0, 0x4
	beq _081AD514
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081AD514
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =unknown_ItemMenu_Confirm
	str r0, [r1]
	b _081AD51A
	.pool
_081AD514:
	adds r0, r4, 0
	bl bag_menu_print_cant_be_held_msg
_081AD51A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end item_menu_type_b

	thumb_func_start UseRegisteredKeyItemOnField
@ bool8 UseRegisteredKeyItemOnField()
UseRegisteredKeyItemOnField: @ 81AD520
	push {r4-r7,lr}
	bl InUnionRoom
	cmp r0, 0x1
	beq _081AD54C
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _081AD54C
	bl InBattlePike
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _081AD54C
	bl InMultiBattleRoom
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081AD550
_081AD54C:
	movs r0, 0
	b _081AD5D2
_081AD550:
	bl HideMapNamePopUpWindow
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY_ScreenOff
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x00000496
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, 0
	beq _081AD5CA
	movs r1, 0x1
	bl CheckBagHasItem
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bne _081AD5C4
	bl ScriptContext2_Enable
	bl FreezeMapObjects
	bl sub_808B864
	bl sub_808BCF4
	ldr r2, =gSpecialVar_ItemId
	ldr r0, [r4]
	adds r0, r5
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0]
	bl ItemId_GetFieldFunc
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0xE]
	b _081AD5D0
	.pool
_081AD5C4:
	ldr r0, [r4]
	adds r0, r5
	strh r7, [r0]
_081AD5CA:
	ldr r0, =EventScript_2736B3
	bl ScriptContext1_SetupScript
_081AD5D0:
	movs r0, 0x1
_081AD5D2:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end UseRegisteredKeyItemOnField

	thumb_func_start display_sell_item_ask_str
@ void display_sell_item_ask_str(int a1)
display_sell_item_ask_str: @ 81AD5DC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r6, =gSpecialVar_ItemId
	ldrh r0, [r6]
	bl itemid_get_market_price
	lsls r0, 16
	cmp r0, 0
	bne _081AD634
	ldrh r0, [r6]
	ldr r1, =gStringVar2
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_CantBuyKeyItem
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =bag_menu_inits_lists_menu
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	b _081AD66A
	.pool
_081AD634:
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081AD64C
	bl bag_menu_AddMoney_window
	adds r0, r5, 0
	bl sub_81AD680
	b _081AD66A
_081AD64C:
	ldrh r0, [r6]
	ldr r1, =gStringVar2
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_HowManyToSell
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_81AD730
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
_081AD66A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end display_sell_item_ask_str

	thumb_func_start sub_81AD680
sub_81AD680: @ 81AD680
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r6, =gStringVar1
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 17
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	muls r1, r0
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_ICanPayVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_81AD6E4
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD680

	thumb_func_start sub_81AD6E4
sub_81AD6E4: @ 81AD6E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_0861408C
	movs r1, 0x6
	bl bag_menu_yes_no
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD6E4

	thumb_func_start sub_81AD6FC
sub_81AD6FC: @ 81AD6FC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl bag_menu_remove_money_window
	movs r0, 0x4
	bl bag_menu_RemoveBagItem_message_window
	ldrb r0, [r4]
	movs r1, 0
	bl bag_menu_print_cursor_
	adds r0, r5, 0
	bl set_callback3_to_bag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD6FC

	thumb_func_start sub_81AD730
sub_81AD730: @ 81AD730
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r0, r4, r6
	mov r8, r0
	movs r0, 0x8
	bl bag_menu_add_window
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 17
	mov r2, r8
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81ABCC0
	bl bag_menu_AddMoney_window
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_81AD794
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD730

	thumb_func_start sub_81AD794
sub_81AD794: @ 81AD794
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	adds r0, r6, 0
	adds r0, 0x10
	ldrh r1, [r6, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081AD7F4
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r0, r1
	ldrb r4, [r0]
	movs r2, 0x10
	ldrsh r5, [r6, r2]
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 17
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81ABCC0
	b _081AD844
	.pool
_081AD7F4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AD818
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x8
	bl bag_menu_remove_window
	adds r0, r4, 0
	bl sub_81AD680
	b _081AD844
	.pool
_081AD818:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081AD844
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r6]
	movs r1, 0
	bl bag_menu_print_cursor_
	bl bag_menu_remove_money_window
	movs r0, 0x8
	bl bag_menu_remove_window
	movs r0, 0x4
	bl bag_menu_RemoveBagItem_message_window
	adds r0, r5, 0
	bl set_callback3_to_bag
_081AD844:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81AD794

	thumb_func_start sub_81AD84C
sub_81AD84C: @ 81AD84C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r6, =gSpecialVar_ItemId
	ldrh r0, [r6]
	ldr r1, =gStringVar2
	bl CopyItemName
	ldr r0, =gStringVar1
	mov r8, r0
	ldrh r0, [r6]
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 17
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	muls r1, r0
	mov r0, r8
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_TurnedOverVar1ForVar2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r3, =sub_81AD8C8
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl DisplayItemMessage
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD84C

	thumb_func_start sub_81AD8C8
sub_81AD8C8: @ 81AD8C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r6, r0, 2
	adds r6, r0
	lsls r6, 3
	ldr r0, =gTasks + 0x8
	adds r0, r6
	mov r10, r0
	ldr r7, =gUnknown_0203CE58
	ldrb r5, [r7, 0x5]
	lsls r5, 1
	movs r1, 0x12
	adds r1, r7
	mov r9, r1
	add r9, r5
	adds r0, r7, 0
	adds r0, 0x8
	adds r5, r0
	movs r0, 0x5F
	bl PlaySE
	ldr r2, =gSpecialVar_ItemId
	mov r8, r2
	ldrh r0, [r2]
	mov r3, r10
	ldrh r1, [r3, 0x10]
	bl RemoveBagItem
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r4, r1
	mov r2, r8
	ldrh r0, [r2]
	bl itemid_get_market_price
	lsls r0, 16
	lsrs r0, 17
	mov r3, r10
	movs r2, 0x10
	ldrsh r1, [r3, r2]
	muls r1, r0
	adds r0, r4, 0
	bl AddMoney
	mov r3, r10
	ldrb r0, [r3]
	mov r1, r9
	adds r2, r5, 0
	bl sub_81AE6C8
	ldrb r0, [r7, 0x5]
	bl sub_81AB9A8
	ldrb r0, [r7, 0x5]
	bl sub_81ABA88
	ldrb r0, [r7, 0x5]
	bl load_bag_item_list_buffers
	ldr r0, =gUnknown_03006310
	mov r2, r9
	ldrh r1, [r2]
	ldrh r2, [r5]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	mov r3, r10
	strh r0, [r3]
	movs r1, 0x2
	bl bag_menu_print_cursor_
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000819
	adds r0, r1
	ldrb r4, [r0]
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	movs r3, 0x92
	lsls r3, 3
	adds r0, r3
	bl GetMoney
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl PrintMoneyAmountInMoneyBox
	ldr r0, =gTasks + 0x8
	subs r0, 0x8
	adds r6, r0
	ldr r0, =sub_81AD9C0
	str r0, [r6]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD8C8

	thumb_func_start sub_81AD9C0
sub_81AD9C0: @ 81AD9C0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081AD9E2
	movs r0, 0x5
	bl PlaySE
	bl bag_menu_remove_money_window
	adds r0, r4, 0
	bl bag_menu_inits_lists_menu
_081AD9E2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AD9C0

	thumb_func_start display_deposit_item_ask_str
display_deposit_item_ask_str: @ 81AD9EC
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r5, r0, 3
	ldr r6, =gTasks + 0x8
	adds r1, r5, r6
	movs r0, 0x1
	strh r0, [r1, 0x10]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bne _081ADA18
	adds r0, r2, 0
	bl sub_81ADB14
	b _081ADA5E
	.pool
_081ADA18:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_DepositHowManyVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
	movs r0, 0x7
	bl sub_81ABC3C
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_81ADA7C
	str r1, [r0]
_081ADA5E:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end display_deposit_item_ask_str

	thumb_func_start sub_81ADA7C
sub_81ADA7C: @ 81ADA7C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	adds r0, r5, 0
	adds r0, 0x10
	ldrh r1, [r5, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081ADAC0
	ldr r0, =gUnknown_0203CE54
	ldr r0, [r0]
	ldr r1, =0x00000817
	adds r0, r1
	ldrb r0, [r0]
	movs r2, 0x10
	ldrsh r1, [r5, r2]
	bl sub_81ABC54
	b _081ADB0E
	.pool
_081ADAC0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081ADAE4
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	bl bag_menu_remove_window
	adds r0, r4, 0
	bl sub_81ADB14
	b _081ADB0E
	.pool
_081ADAE4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081ADB0E
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl bag_menu_print_description_box_text
	ldrb r0, [r5]
	movs r1, 0
	bl bag_menu_print_cursor_
	movs r0, 0x7
	bl bag_menu_remove_window
	adds r0, r6, 0
	bl set_callback3_to_bag
_081ADB0E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81ADA7C

	thumb_func_start sub_81ADB14
sub_81ADB14: @ 81ADB14
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r7, r1, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r2, r7, 0
	add r2, r9
	mov r8, r2
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl itemid_is_unique
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _081ADB6C
	ldr r2, =gText_CantStoreImportantItems
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x1
	b _081ADBE2
	.pool
_081ADB6C:
	ldrh r0, [r4]
	mov r3, r8
	ldrh r1, [r3, 0x10]
	bl AddPCItem
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bne _081ADBD4
	ldrh r0, [r4]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	mov r2, r8
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_DepositedVar2Var1s
	adds r0, r4, 0
	bl StringExpandPlaceholders
	str r6, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	str r5, [sp, 0xC]
	str r5, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3
	bl bag_menu_print
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =Task_ActuallyToss
	b _081ADBF2
	.pool
_081ADBD4:
	ldr r2, =gText_NoRoomForItems
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	str r5, [sp, 0xC]
	str r5, [sp, 0x10]
_081ADBE2:
	movs r1, 0x1
	movs r3, 0x3
	bl bag_menu_print
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_81ADC0C
_081ADBF2:
	str r1, [r0]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ADB14

	thumb_func_start sub_81ADC0C
sub_81ADC0C: @ 81ADC0C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081ADC44
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl bag_menu_print_description_box_text
	ldrb r0, [r5]
	movs r1, 0
	bl bag_menu_print_cursor_
	adds r0, r4, 0
	bl set_callback3_to_bag
_081ADC44:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81ADC0C

	thumb_func_start IsWallysBag
@ bool8 IsWallysBag()
IsWallysBag: @ 81ADC54
	push {lr}
	ldr r0, =gUnknown_0203CE58
	ldrb r0, [r0, 0x4]
	cmp r0, 0xA
	beq _081ADC68
	movs r0, 0
	b _081ADC6A
	.pool
_081ADC68:
	movs r0, 0x1
_081ADC6A:
	pop {r1}
	bx r1
	thumb_func_end IsWallysBag

	thumb_func_start PrepareBagForWallyTutorial
@ void PrepareBagForWallyTutorial()
PrepareBagForWallyTutorial: @ 81ADC70
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203CE80
	movs r0, 0xD0
	bl AllocZeroed
	str r0, [r4]
	ldr r5, =gSaveBlock1Ptr
	ldr r1, [r5]
	movs r2, 0xAC
	lsls r2, 3
	adds r1, r2
	movs r2, 0x78
	bl memcpy
	ldr r0, [r4]
	ldr r1, [r5]
	movs r2, 0xCA
	lsls r2, 3
	adds r1, r2
	adds r0, 0x78
	movs r2, 0x40
	bl memcpy
	ldr r0, [r4]
	ldr r2, =gUnknown_0203CE58
	ldrb r1, [r2, 0x5]
	adds r0, 0xCE
	strh r1, [r0]
	movs r6, 0
	adds r5, r2, 0
	adds r5, 0x8
_081ADCAE:
	ldr r2, [r4]
	lsls r3, r6, 1
	adds r0, r2, 0
	adds r0, 0xB8
	adds r0, r3
	ldrh r1, [r5]
	strh r1, [r0]
	adds r2, 0xC2
	adds r2, r3
	ldrh r0, [r5, 0xA]
	strh r0, [r2]
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x4
	bls _081ADCAE
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r1, 0xAC
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1E
	bl ClearItemSlots
	ldr r0, [r4]
	movs r2, 0xCA
	lsls r2, 3
	adds r0, r2
	movs r1, 0x10
	bl ClearItemSlots
	bl ResetBagScrollPositions
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrepareBagForWallyTutorial

	thumb_func_start RestoreBagAfterWallyTutorial
@ void RestoreBagAfterWallyTutorial()
RestoreBagAfterWallyTutorial: @ 81ADD00
	push {r4-r6,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	movs r1, 0xAC
	lsls r1, 3
	adds r0, r1
	ldr r4, =gUnknown_0203CE80
	ldr r1, [r4]
	movs r2, 0x78
	bl memcpy
	ldr r0, [r5]
	movs r1, 0xCA
	lsls r1, 3
	adds r0, r1
	ldr r1, [r4]
	adds r1, 0x78
	movs r2, 0x40
	bl memcpy
	ldr r1, =gUnknown_0203CE58
	ldr r0, [r4]
	adds r0, 0xCE
	ldrh r0, [r0]
	strb r0, [r1, 0x5]
	movs r5, 0
	adds r6, r4, 0
	adds r3, r1, 0
	adds r3, 0x8
_081ADD3A:
	lsls r2, r5, 1
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	adds r1, 0xC2
	adds r1, r2
	ldrh r0, [r1]
	strh r0, [r3, 0xA]
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, 0x4
	bls _081ADD3A
	ldr r0, [r6]
	bl Free
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RestoreBagAfterWallyTutorial

	thumb_func_start DoWallyTutorialBagMenu
@ void DoWallyTutorialBagMenu()
DoWallyTutorialBagMenu: @ 81ADD70
	push {lr}
	bl PrepareBagForWallyTutorial
	movs r0, 0xD
	movs r1, 0x1
	bl AddBagItem
	movs r0, 0x4
	movs r1, 0x1
	bl AddBagItem
	ldr r2, =SetCB2ToReshowScreenAfterMenu2
	movs r0, 0xA
	movs r1, 0
	bl GoToBagMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoWallyTutorialBagMenu

	thumb_func_start Task_WallyTutorialBagMenu
@ void Task_WallyTutorialBagMenu(u8 taskId)
Task_WallyTutorialBagMenu: @ 81ADD98
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081ADE32
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	cmp r1, 0xCC
	beq _081ADDEC
	cmp r1, 0xCC
	bgt _081ADDD0
	cmp r1, 0x66
	beq _081ADDDA
	b _081ADE2C
	.pool
_081ADDD0:
	movs r0, 0x99
	lsls r0, 1
	cmp r1, r0
	beq _081ADE0C
	b _081ADE2C
_081ADDDA:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	bl SwitchBagPocket
	b _081ADE2C
_081ADDEC:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	movs r1, 0x2
	bl bag_menu_print_cursor_
	ldr r1, =gSpecialVar_ItemId
	movs r0, 0x4
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_81AC644
	b _081ADE2C
	.pool
_081ADE0C:
	movs r0, 0x5
	bl PlaySE
	bl bag_menu_remove_some_window
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	bl RestoreBagAfterWallyTutorial
	adds r0, r5, 0
	bl unknown_ItemMenu_Confirm
	b _081ADE32
_081ADE2C:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
_081ADE32:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end Task_WallyTutorialBagMenu

	thumb_func_start unknown_ItemMenu_Show
unknown_ItemMenu_Show: @ 81ADE38
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gSpecialVar_0x8005
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	bl bag_menu_remove_some_window
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_ItemMenu_Show

	thumb_func_start bag_menu_leave_maybe_3
bag_menu_leave_maybe_3: @ 81ADE6C
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =sub_819FA50
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_leave_maybe_3

	thumb_func_start unknown_ItemMenu_Give2
unknown_ItemMenu_Give2: @ 81ADE8C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	bl bag_menu_remove_some_window
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_ItemMenu_Give2

	thumb_func_start bag_menu_leave_maybe_2
bag_menu_leave_maybe_2: @ 81ADEBC
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =sub_818DEF4
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_leave_maybe_2

	thumb_func_start unknown_ItemMenu_Confirm2
unknown_ItemMenu_Confirm2: @ 81ADEDC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	bl bag_menu_remove_some_window
	adds r0, r4, 0
	bl unknown_ItemMenu_Confirm
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_ItemMenu_Confirm2

	thumb_func_start bag_menu_leave_maybe
bag_menu_leave_maybe: @ 81ADF00
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =sub_818E564
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_leave_maybe

	thumb_func_start bag_menu_print_pocket_names
bag_menu_print_pocket_names: @ 81ADF20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	adds r4, r0, 0
	mov r8, r1
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x14]
	str r1, [sp, 0x18]
	ldr r1, =0x00ffffff
	ldr r0, [sp, 0x14]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 21
	orrs r0, r1
	str r0, [sp, 0x14]
	ldr r1, =0xffffff00
	ldr r0, [sp, 0x18]
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	str r0, [sp, 0x18]
	add r0, sp, 0x14
	bl AddWindow
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r7, 0x1
	str r7, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0xFF
	mov r9, r0
	str r0, [sp, 0xC]
	str r7, [sp, 0x10]
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl bag_menu_print
	mov r2, r8
	cmp r2, 0
	beq _081ADFBA
	movs r0, 0x1
	mov r1, r8
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	adds r3, 0x40
	lsls r3, 24
	lsrs r3, 24
	str r7, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	str r7, [sp, 0x10]
	adds r0, r6, 0
	movs r1, 0x1
	mov r2, r8
	bl bag_menu_print
_081ADFBA:
	adds r0, r6, 0
	movs r1, 0x7
	bl GetWindowAttribute
	ldr r1, =gUnknown_0203CE54
	ldr r1, [r1]
	ldr r2, =0x00000844
	adds r1, r2
	ldr r2, =0x04000100
	bl CpuSet
	adds r0, r6, 0
	bl RemoveWindow
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print_pocket_names

	thumb_func_start bag_menu_copy_pocket_name_to_window
bag_menu_copy_pocket_name_to_window: @ 81ADFF8
	push {r4-r7,lr}
	adds r7, r0, 0
	cmp r7, 0x8
	bls _081AE002
	movs r7, 0x8
_081AE002:
	ldr r0, =gUnknown_0203CE54
	ldr r4, [r0]
	ldr r0, =0x00000844
	adds r4, r0
	movs r0, 0x2
	movs r1, 0x7
	bl GetWindowAttribute
	adds r5, r0, 0
	lsls r0, r7, 5
	adds r0, r4, r0
	ldr r6, =0x04000040
	adds r1, r5, 0
	adds r2, r6, 0
	bl CpuSet
	adds r0, r7, 0
	adds r0, 0x10
	lsls r0, 5
	adds r4, r0
	movs r0, 0x80
	lsls r0, 1
	adds r5, r0
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl CpuSet
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_copy_pocket_name_to_window

	thumb_func_start setup_bag_menu_textboxes
setup_bag_menu_textboxes: @ 81AE054
	push {r4,lr}
	ldr r0, =gUnknown_08614174
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xD0
	bl copy_textbox_border_tile_patterns_to_vram
	movs r0, 0xC0
	movs r1, 0x1
	bl sub_819A2BC
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081AE088:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081AE088
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end setup_bag_menu_textboxes

	thumb_func_start bag_menu_print
bag_menu_print: @ 81AE0BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r9, r3
	ldr r3, [sp, 0x30]
	ldr r4, [sp, 0x34]
	ldr r6, [sp, 0x38]
	ldr r5, [sp, 0x3C]
	mov r8, r5
	ldr r5, [sp, 0x40]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r7, r9
	lsls r7, 24
	lsrs r7, 24
	mov r9, r7
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_08614164
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r2, [sp, 0x10]
	mov r2, r9
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_print

	thumb_func_start sub_81AE124
sub_81AE124: @ 81AE124
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CE54
	ldr r1, [r1]
	movs r2, 0x81
	lsls r2, 4
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81AE124

	thumb_func_start bag_menu_add_window
bag_menu_add_window: @ 81AE13C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203CE54
	movs r3, 0x81
	lsls r3, 4
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081AE172
	lsls r0, r2, 3
	ldr r1, =gUnknown_086141AC
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081AE172:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end bag_menu_add_window

	thumb_func_start bag_menu_remove_window
bag_menu_remove_window: @ 81AE184
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CE54
	movs r2, 0x81
	lsls r2, 4
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081AE1B8
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0xFF
	strb r0, [r4]
_081AE1B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_remove_window

	thumb_func_start AddItemMessageWindow
@ u8 AddItemMessageWindow(u8 a1)
AddItemMessageWindow: @ 81AE1C4
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203CE54
	movs r3, 0x81
	lsls r3, 4
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081AE1E8
	lsls r0, r2, 3
	ldr r1, =gUnknown_086141AC
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
_081AE1E8:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddItemMessageWindow

	thumb_func_start bag_menu_RemoveBagItem_message_window
bag_menu_RemoveBagItem_message_window: @ 81AE1F8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CE54
	movs r2, 0x81
	lsls r2, 4
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081AE22C
	movs r1, 0
	bl sub_8197DF8
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0xFF
	strb r0, [r4]
_081AE22C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_RemoveBagItem_message_window

	thumb_func_start bag_menu_yes_no
bag_menu_yes_no: @ 81AE238
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 21
	ldr r3, =gUnknown_086141AC
	adds r1, r3
	movs r3, 0x2
	str r3, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	movs r3, 0xE
	str r3, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_yes_no

	thumb_func_start bag_menu_AddMoney_window
bag_menu_AddMoney_window: @ 81AE268
	push {r4,lr}
	movs r0, 0x9
	bl bag_menu_add_window
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	bl GetMoney
	adds r3, r0, 0
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0xE
	bl PrintMoneyAmountInMoneyBoxWithBorder
	movs r0, 0x13
	movs r1, 0xB
	bl AddMoneyLabelObject
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bag_menu_AddMoney_window

	thumb_func_start bag_menu_remove_money_window
bag_menu_remove_money_window: @ 81AE2A4
	push {lr}
	movs r0, 0x9
	bl bag_menu_remove_window
	bl RemoveMoneyLabelObject
	pop {r0}
	bx r0
	thumb_func_end bag_menu_remove_money_window

	thumb_func_start bag_menu_prepare_tmhm_move_window
bag_menu_prepare_tmhm_move_window: @ 81AE2B4
	push {lr}
	movs r0, 0x3
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x13
	movs r2, 0
	movs r3, 0
	bl blit_move_info_icon
	movs r0, 0x3
	movs r1, 0x14
	movs r2, 0
	movs r3, 0xC
	bl blit_move_info_icon
	movs r0, 0x3
	movs r1, 0x15
	movs r2, 0
	movs r3, 0x18
	bl blit_move_info_icon
	movs r0, 0x3
	movs r1, 0x16
	movs r2, 0
	movs r3, 0x24
	bl blit_move_info_icon
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end bag_menu_prepare_tmhm_move_window

	thumb_func_start PrintTMHMMoveData
PrintTMHMMoveData: @ 81AE2FC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x4
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0
	bne _081AE354
	movs r4, 0
	movs r5, 0
_081AE31A:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0xFF
	str r0, [sp, 0xC]
	movs r0, 0x4
	str r0, [sp, 0x10]
	movs r1, 0x1
	ldr r2, =gText_ThreeDashes
	movs r3, 0x7
	bl bag_menu_print
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081AE31A
	movs r0, 0x4
	movs r1, 0x2
	bl CopyWindowToVram
	b _081AE440
	.pool
_081AE354:
	adds r0, r4, 0
	bl ItemIdToBattleMoveId
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r1, =gBattleMoves
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r5, r0, r1
	ldrb r1, [r5, 0x2]
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x4
	movs r2, 0
	movs r3, 0
	bl blit_move_info_icon
	ldrb r0, [r5, 0x1]
	cmp r0, 0x1
	bhi _081AE38C
	ldr r2, =gText_ThreeDashes
	b _081AE39C
	.pool
_081AE38C:
	ldr r4, =gStringVar1
	ldrb r1, [r5, 0x1]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
_081AE39C:
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0xFF
	str r0, [sp, 0xC]
	movs r0, 0x4
	str r0, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x7
	bl bag_menu_print
	ldr r2, =gBattleMoves
	lsls r1, r7, 1
	adds r0, r1, r7
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x3]
	adds r6, r1, 0
	cmp r0, 0
	bne _081AE3D8
	ldr r2, =gText_ThreeDashes
	b _081AE3E8
	.pool
_081AE3D8:
	ldr r4, =gStringVar1
	ldrb r1, [r2, 0x3]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
_081AE3E8:
	movs r0, 0x18
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0xFF
	mov r8, r0
	str r0, [sp, 0xC]
	movs r0, 0x4
	mov r9, r0
	str r0, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x7
	bl bag_menu_print
	ldr r5, =gStringVar1
	ldr r1, =gBattleMoves
	adds r0, r6, r7
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x4]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	movs r0, 0x4
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x7
	bl bag_menu_print
	movs r0, 0x4
	movs r1, 0x2
	bl CopyWindowToVram
_081AE440:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrintTMHMMoveData

	.align 2, 0 @ Don't pad with nop.
