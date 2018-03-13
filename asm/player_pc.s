	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start fish4_goto_x5_or_x6
fish4_goto_x5_or_x6: @ 816BE44
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0816BED4
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000666
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _0816BE8E
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0816BE84
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xFF
	bl sub_816BFE0
	b _0816BE8E
	.pool
_0816BE84:
	adds r0, r5, 0
	movs r1, 0xFF
	movs r2, 0xFF
	bl sub_816BFE0
_0816BE8E:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsls r2, r4, 2
	adds r1, r2
	ldr r2, =0x0000049a
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x68
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x7
	adds r2, r4, 0
	bl PrintTextOnWindow
_0816BED4:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fish4_goto_x5_or_x6

	thumb_func_start sub_816BEF0
sub_816BEF0: @ 816BEF0
	push {r4,r5,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r2, =0x00000661
	adds r0, r2
	ldrb r5, [r0]
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _0816BF2C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetDescription
	b _0816BF32
	.pool
_0816BF2C:
	ldr r0, =0x0000ffff
	bl sub_816C228
_0816BF32:
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BEF0

	thumb_func_start sub_816BF60
sub_816BF60: @ 816BF60
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _0816BF8C
	ldrb r0, [r4, 0x5]
	ldrb r1, [r4, 0x4]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x000013f8
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xB0
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	strb r0, [r4, 0x9]
_0816BF8C:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BF60

	thumb_func_start sub_816BF9C
sub_816BF9C: @ 816BF9C
	push {r4,lr}
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	beq _0816BFAE
	bl RemoveScrollIndicatorArrowPair
	movs r0, 0xFF
	strb r0, [r4, 0x9]
_0816BFAE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BF9C

	thumb_func_start sub_816BFB8
sub_816BFB8: @ 816BFB8
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_816BFE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_816BFB8

	thumb_func_start sub_816BFE0
sub_816BFE0: @ 816BFE0
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r3, 0xCC
	lsls r3, 3
	adds r0, r3
	ldrb r5, [r0]
	cmp r1, 0xFF
	bne _0816C030
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
	adds r0, r5, 0
	movs r1, 0x11
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	b _0816C050
	.pool
_0816C030:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_085DFF8C
	str r0, [sp, 0x8]
	lsls r0, r2, 24
	asrs r0, 24
	str r0, [sp, 0xC]
	ldr r0, =gText_SelectorArrow2
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r6, 0
	bl AddTextPrinterParameterized2
_0816C050:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BFE0

	thumb_func_start sub_816C060
sub_816C060: @ 816C060
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000667
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _0816C0B2
	ldr r4, =0x000013f6
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0816C0B2
	strb r2, [r5]
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x18
	strh r0, [r1, 0x24]
	movs r0, 0x50
	strh r0, [r1, 0x26]
_0816C0B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C060

	thumb_func_start sub_816C0C8
sub_816C0C8: @ 816C0C8
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000667
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _0816C0FA
	ldr r4, =0x000013f6
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_0816C0FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C0C8

	thumb_func_start sub_816C110
sub_816C110: @ 816C110
	push {lr}
	sub sp, 0x4
	bl sub_80D6E84
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldr r2, =gUnknown_0203BCBC
	adds r3, r2, 0x1
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x32
	bl sub_812220C
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C110

	thumb_func_start sub_816C140
sub_816C140: @ 816C140
	push {lr}
	ldr r0, =gUnknown_0203BCBA
	subs r1, r0, 0x2
	ldrb r2, [r1, 0x4]
	ldrb r3, [r1, 0x5]
	bl sub_812225C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C140

	thumb_func_start ItemStorage_ProcessInput
ItemStorage_ProcessInput: @ 816C158
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r4, 0
_0816C16C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_816BC7C
	adds r4, 0x1
	cmp r4, 0x3
	bls _0816C16C
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	ldr r5, =gText_TossItem
	cmp r0, 0
	bne _0816C186
	ldr r5, =gText_WithdrawItem
_0816C186:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x68
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldr r4, =gUnknown_0203BCC4
	ldr r0, [r4]
	ldr r1, =0x00000663
	adds r0, r1
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl PrintTextOnWindow
	ldr r0, [r4]
	ldr r1, =0x00000662
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	bl sub_816C110
	bl sub_816C140
	bl sub_816BD04
	ldr r0, =gMultiuseListMenuTemplate
	ldr r2, =gUnknown_0203BCB8
	ldrh r1, [r2, 0x2]
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0xA]
	bl sub_816BF60
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemStorage_ProcessInput

	thumb_func_start sub_816C228
sub_816C228: @ 816C228
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xffff0009
	adds r0, r1, r2
	cmp r0, 0x8
	bhi _0816C2B4
	lsls r0, 2
	ldr r1, =_0816C248
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816C248:
	.4byte _0816C2AC
	.4byte _0816C2A4
	.4byte _0816C29C
	.4byte _0816C294
	.4byte _0816C28C
	.4byte _0816C284
	.4byte _0816C27C
	.4byte _0816C274
	.4byte _0816C26C
_0816C26C:
	ldr r0, =gText_GoBackPrevMenu
	b _0816C2BA
	.pool
_0816C274:
	ldr r0, =gText_WithdrawHowManyItems
	b _0816C2BA
	.pool
_0816C27C:
	ldr r0, =gText_WithdrawXItems
	b _0816C2BA
	.pool
_0816C284:
	ldr r0, =gText_TossHowManyVar1s
	b _0816C2BA
	.pool
_0816C28C:
	ldr r0, =gText_ThrewAwayVar2Var1s
	b _0816C2BA
	.pool
_0816C294:
	ldr r0, =gText_NoRoomInBag
	b _0816C2BA
	.pool
_0816C29C:
	ldr r0, =gText_TooImportantToToss
	b _0816C2BA
	.pool
_0816C2A4:
	ldr r0, =gText_ConfirmTossItems
	b _0816C2BA
	.pool
_0816C2AC:
	ldr r0, =gText_MoveVar1Where
	b _0816C2BA
	.pool
_0816C2B4:
	adds r0, r1, 0
	bl ItemId_GetDescription
_0816C2BA:
	pop {r1}
	bx r1
	thumb_func_end sub_816C228

	thumb_func_start sub_816C2C0
sub_816C2C0: @ 816C2C0
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000661
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gStringVar4
	adds r0, r4, 0
	adds r1, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C2C0

	thumb_func_start sub_816C30C
sub_816C30C: @ 816C30C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816C35C
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r4, r1, 0x2
	adds r2, r4, 0
	bl sub_81AE860
	ldrh r1, [r4, 0x2]
	ldrh r0, [r4]
	adds r1, r0
	ldrb r0, [r4, 0x5]
	subs r0, 0x1
	cmp r1, r0
	beq _0816C39E
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C450
	b _0816C39E
	.pool
_0816C35C:
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r2, r1, 0x2
	bl sub_81AE860
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _0816C384
	adds r0, 0x1
	cmp r6, r0
	bne _0816C392
	b _0816C39E
	.pool
_0816C384:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C400
	b _0816C39E
_0816C392:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C71C
_0816C39E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816C30C

	thumb_func_start bx_battle_menu_t3
bx_battle_menu_t3: @ 816C3A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0816C3F2
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0816C3DC
	adds r0, r4, 0
	movs r1, 0
	bl InitItemStorageMenu
	b _0816C3E4
	.pool
_0816C3DC:
	adds r0, r4, 0
	movs r1, 0x2
	bl InitItemStorageMenu
_0816C3E4:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =ItemStorageMenuProcessInput
	str r0, [r1]
_0816C3F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_battle_menu_t3

	thumb_func_start sub_816C400
sub_816C400: @ 816C400
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_816C0C8
	bl sub_816BF9C
	ldrb r0, [r5, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	bl sub_81223B0
	bl sub_816BC58
	subs r6, 0x8
	adds r4, r6
	ldr r0, =bx_battle_menu_t3
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C400

	thumb_func_start sub_816C450
sub_816C450: @ 816C450
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r1, r4, 0
	add r1, r8
	mov r9, r1
	ldrb r0, [r1, 0xA]
	movs r1, 0x10
	movs r2, 0x1
	bl sub_81AF15C
	ldr r6, =gUnknown_0203BCC4
	ldr r2, [r6]
	ldr r1, =gUnknown_0203BCB8
	ldrb r0, [r1]
	ldrb r1, [r1, 0x2]
	adds r0, r1
	ldr r5, =0x00000666
	adds r2, r5
	strb r0, [r2]
	mov r1, r9
	ldrb r0, [r1, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_816BFB8
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_816C690
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fff7
	bl sub_816C228
	bl sub_816C2C0
	movs r1, 0x8
	negs r1, r1
	add r8, r1
	add r4, r8
	ldr r0, =sub_816C4FC
	str r0, [r4]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C450

	thumb_func_start sub_816C4FC
sub_816C4FC: @ 816C4FC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r7, =gMain
	ldrh r1, [r7, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816C530
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r2, r1, 0x2
	bl sub_81AE860
	b _0816C57E
	.pool
_0816C530:
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r4, r1, 0x2
	adds r2, r4, 0
	bl sub_81AE860
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	movs r2, 0
	bl sub_81223FC
	ldrb r0, [r4]
	bl sub_816C690
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _0816C574
	adds r0, 0x1
	cmp r6, r0
	bne _0816C592
	b _0816C59A
	.pool
_0816C574:
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816C588
_0816C57E:
	adds r0, r5, 0
	movs r1, 0
	bl sub_816C5A0
	b _0816C59A
_0816C588:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_816C5A0
	b _0816C59A
_0816C592:
	adds r0, r5, 0
	movs r1, 0
	bl sub_816C5A0
_0816C59A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816C4FC

	thumb_func_start sub_816C5A0
sub_816C5A0: @ 816C5A0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	mov r8, r0
	ldr r4, =gUnknown_0203BCB8
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0x5
	bl PlaySE
	mov r2, r8
	ldrb r0, [r2, 0xA]
	adds r1, r4, 0x2
	adds r2, r4, 0
	bl sub_81AE6C8
	cmp r5, 0
	bne _0816C60A
	ldr r1, =gUnknown_0203BCC4
	ldr r0, [r1]
	ldr r2, =0x00000666
	adds r0, r2
	ldrb r2, [r0]
	adds r4, r1, 0
	cmp r2, r6
	beq _0816C622
	subs r0, r6, 0x1
	cmp r2, r0
	beq _0816C60A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	adds r1, r2, 0
	adds r2, r6, 0
	bl sub_80D702C
	bl sub_816BD04
_0816C60A:
	ldr r0, =gUnknown_0203BCC4
	ldr r1, [r0]
	ldr r2, =0x00000666
	adds r1, r2
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, r6
	bcs _0816C622
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_0816C622:
	ldr r0, [r4]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	movs r2, 0x1
	bl sub_81223FC
	ldr r0, [r4]
	ldr r2, =0x00000666
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =gMultiuseListMenuTemplate
	ldr r2, =gUnknown_0203BCB8
	ldrh r1, [r2, 0x2]
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0xA]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C5A0

	thumb_func_start sub_816C690
sub_816C690: @ 816C690
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x7
	movs r2, 0x80
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C690

	thumb_func_start sub_816C6BC
sub_816C6BC: @ 816C6BC
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r5, [sp, 0x1C]
	ldr r3, [sp, 0x20]
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gStringVar1
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x30
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C6BC

	thumb_func_start sub_816C71C
sub_816C71C: @ 816C71C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	bl sub_816BF9C
	movs r0, 0x1
	strh r0, [r6, 0x4]
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0816C798
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r1, r0
	ldr r2, =0x0000049a
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0816C774
	adds r0, r5, 0
	bl sub_816C8FC
	b _0816C7FE
	.pool
_0816C774:
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fffe
	bl sub_816C228
	bl sub_816C2C0
	b _0816C7D4
	.pool
_0816C798:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r1, r0
	ldr r2, =0x0000049a
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0816C7BC
	adds r0, r5, 0
	bl sub_816C9B8
	b _0816C7FE
	.pool
_0816C7BC:
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fffc
	bl sub_816C228
	bl sub_816C2C0
_0816C7D4:
	movs r0, 0x4
	bl sub_816BC7C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x8
	bl sub_816C6BC
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C818
	str r1, [r0]
_0816C7FE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C71C

	thumb_func_start sub_816C818
sub_816C818: @ 816C818
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	mov r9, r5
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r0, =gUnknown_0203BCB8
	ldrh r2, [r0, 0x2]
	ldrh r0, [r0]
	adds r2, r0
	lsls r2, 16
	adds r0, r6, 0x4
	ldr r1, =gSaveBlock1Ptr
	mov r8, r1
	ldr r1, [r1]
	lsrs r7, r2, 14
	adds r1, r7
	ldr r2, =0x0000049a
	adds r1, r2
	ldrh r1, [r1]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0816C888
	movs r0, 0x4
	bl sub_816BC7C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	str r4, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x8
	bl sub_816C6BC
	b _0816C8EC
	.pool
_0816C888:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816C8BC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	bl sub_816BCC4
	movs r3, 0x6
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _0816C8B4
	adds r0, r5, 0
	bl sub_816C8FC
	b _0816C8EC
	.pool
_0816C8B4:
	adds r0, r5, 0
	bl sub_816C9B8
	b _0816C8EC
_0816C8BC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0816C8EC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	bl sub_816BCC4
	mov r1, r8
	ldr r0, [r1]
	adds r0, r7
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r9
	bl sub_816CBC0
_0816C8EC:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816C818

	thumb_func_start sub_816C8FC
sub_816C8FC: @ 816C8FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r4, r6, r0
	ldr r0, =gUnknown_0203BCB8
	ldrh r1, [r0, 0x2]
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	lsrs r5, r1, 14
	adds r0, r5
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816C98C
	ldr r0, [r7]
	adds r0, r5
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =0x0000fffd
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r8
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_816CB04
	b _0816C9A2
	.pool
_0816C98C:
	movs r0, 0
	strh r0, [r4, 0x4]
	ldr r0, =0x0000fffa
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r8
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_816CB74
_0816C9A2:
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C8FC

	thumb_func_start sub_816C9B8
sub_816C9B8: @ 816C9B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r9, r0
	mov r7, r8
	add r7, r9
	ldr r0, =gUnknown_0203BCB8
	ldrh r1, [r0, 0x2]
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	lsrs r4, r1, 14
	adds r0, r4
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _0816CA64
	ldr r0, [r6]
	adds r0, r4
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =0x0000fff8
	bl sub_816C228
	bl sub_816C2C0
	ldr r1, =gUnknown_085DFF84
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x85
	lsls r0, 2
	str r0, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_085DFF3C
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	b _0816CA7C
	.pool
_0816CA64:
	movs r0, 0
	strh r0, [r7, 0x4]
	ldr r0, =0x0000fff9
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_816CB74
	str r1, [r0]
_0816CA7C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C9B8

	thumb_func_start sub_816CA94
sub_816CA94: @ 816CA94
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000fffb
	bl sub_816C228
	bl sub_816C2C0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816CB04
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CA94

	thumb_func_start sub_816CAC8
sub_816CAC8: @ 816CAC8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	movs r0, 0x93
	lsls r0, 3
	adds r2, r0
	ldrh r0, [r2]
	bl sub_816C228
	bl sub_816C2C0
	adds r0, r4, 0
	bl sub_816CBC0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CAC8

	thumb_func_start sub_816CB04
sub_816CB04: @ 816CB04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816CB5E
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x2]
	ldrb r1, [r4]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x4]
	bl sub_80D6E48
	ldrb r0, [r5, 0xA]
	adds r1, r4, 0x2
	adds r2, r4, 0
	bl sub_81AE6C8
	bl sub_816C110
	bl sub_816C140
	bl sub_816BD04
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r4, 0x2]
	ldrh r2, [r4]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	adds r0, r6, 0
	bl sub_816CBC0
_0816CB5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CB04

	thumb_func_start sub_816CB74
sub_816CB74: @ 816CB74
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816CBAC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	movs r0, 0x93
	lsls r0, 3
	adds r2, r0
	ldrh r0, [r2]
	bl sub_816C228
	bl sub_816C2C0
	adds r0, r4, 0
	bl sub_816CBC0
_0816CBAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CB74

	thumb_func_start sub_816CBC0
sub_816CBC0: @ 816CBC0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_816BF60
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CBC0

	.align 2, 0 @ Don't pad with nop.
