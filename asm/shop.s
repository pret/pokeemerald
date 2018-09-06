	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start BuyMenuDrawMapMetatile
@ void BuyMenuDrawMapMetatile(u16 x, u16 y, u16 *src, u8 metatileLayerType)
BuyMenuDrawMapMetatile: @ 80E0670
	push {r4-r7,lr}
	adds r7, r2, 0
	lsls r3, 24
	lsrs r3, 24
	adds r2, r3, 0
	lsls r0, 17
	lsrs r5, r0, 16
	lsls r1, 22
	lsrs r1, 16
	cmp r3, 0x1
	beq _080E06C0
	cmp r3, 0x1
	bgt _080E0690
	cmp r3, 0
	beq _080E0696
	b _080E0728
_080E0690:
	cmp r2, 0x2
	beq _080E06F8
	b _080E0728
_080E0696:
	ldr r6, =gShopDataPtr
	ldr r0, [r6]
	movs r2, 0xC0
	lsls r2, 5
	adds r0, r2
	lsls r5, 16
	asrs r5, 16
	lsls r4, r1, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl BuyMenuDrawMapMetatileLayer
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 4
	b _080E06E2
	.pool
_080E06C0:
	ldr r6, =gShopDataPtr
	ldr r0, [r6]
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2
	lsls r5, 16
	asrs r5, 16
	lsls r4, r1, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl BuyMenuDrawMapMetatileLayer
	ldr r0, [r6]
	movs r1, 0xC0
	lsls r1, 5
_080E06E2:
	adds r0, r1
	adds r3, r7, 0
	adds r3, 0x8
	adds r1, r5, 0
	adds r2, r4, 0
	bl BuyMenuDrawMapMetatileLayer
	b _080E0728
	.pool
_080E06F8:
	ldr r6, =gShopDataPtr
	ldr r0, [r6]
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2
	lsls r5, 16
	asrs r5, 16
	lsls r4, r1, 16
	asrs r4, 16
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl BuyMenuDrawMapMetatileLayer
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1
	adds r3, r7, 0
	adds r3, 0x8
	adds r1, r5, 0
	adds r2, r4, 0
	bl BuyMenuDrawMapMetatileLayer
_080E0728:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuDrawMapMetatile

	thumb_func_start BuyMenuDrawMapMetatileLayer
@ int BuyMenuDrawMapMetatileLayer(void *tilemapBuffer, s16 xOffset, s16 yOffset, u16 *src)
BuyMenuDrawMapMetatileLayer: @ 80E0734
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r2
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r3]
	strh r0, [r1]
	ldrh r0, [r3, 0x2]
	strh r0, [r1, 0x2]
	adds r2, r1, 0
	adds r2, 0x40
	ldrh r0, [r3, 0x4]
	strh r0, [r2]
	adds r1, 0x42
	ldrh r0, [r3, 0x6]
	strh r0, [r1]
	bx lr
	thumb_func_end BuyMenuDrawMapMetatileLayer

	thumb_func_start BuyMenuCollectEventObjectData
@ void BuyMenuCollectEventObjectData()
BuyMenuCollectEventObjectData: @ 80E075C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r7, 0
	ldr r5, =gShopDataPtr
	ldr r3, =0x00002010
	movs r2, 0x10
_080E0780:
	ldr r1, [r5]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 1
	adds r1, r3
	adds r1, r0
	strh r2, [r1]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xF
	bls _080E0780
	movs r7, 0
	str r4, [sp, 0x8]
	ldr r1, =gShopDataPtr
	mov r9, r1
	mov r2, sp
	str r2, [sp, 0x4]
_080E07A4:
	movs r3, 0
	adds r4, r7, 0x1
	str r4, [sp, 0xC]
_080E07AA:
	ldr r1, =0x0000fffc
	adds r0, r3, r1
	ldr r2, [sp, 0x4]
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	asrs r0, 16
	ldr r4, =0x0000fffe
	adds r1, r7, r4
	ldr r2, [sp, 0x8]
	ldrh r2, [r2]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	str r3, [sp, 0x10]
	bl GetEventObjectIdByXY
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, [sp, 0x10]
	cmp r6, 0x10
	beq _080E08C2
	mov r4, r9
	ldr r1, [r4]
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r5, r0, 1
	ldr r2, =0x00002010
	adds r0, r1, r2
	adds r0, r5
	movs r2, 0
	mov r10, r2
	strh r6, [r0]
	ldr r2, =0x00002012
	adds r0, r1, r2
	adds r0, r5
	strh r3, [r0]
	ldr r0, =0x00002014
	adds r1, r0
	adds r1, r5
	strh r7, [r1]
	ldr r1, [sp, 0x4]
	movs r2, 0
	ldrsh r0, [r1, r2]
	subs r1, r3, 0x4
	adds r0, r1
	ldr r1, [sp, 0x8]
	movs r2, 0
	ldrsh r1, [r1, r2]
	mov r12, r1
	subs r1, r7, 0x2
	add r1, r12
	str r3, [sp, 0x10]
	bl MapGridGetMetatileLayerTypeAt
	mov r1, r9
	ldr r2, [r1]
	ldr r1, =0x00002018
	adds r1, r2
	mov r12, r1
	add r12, r5
	lsls r0, 24
	lsrs r0, 24
	mov r1, r12
	strh r0, [r1]
	ldr r1, =gEventObjects
	lsls r0, r6, 3
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	ldr r3, [sp, 0x10]
	cmp r0, 0x2
	beq _080E0884
	cmp r0, 0x2
	bgt _080E0870
	cmp r0, 0x1
	beq _080E0876
	b _080E08A4
	.pool
_080E0870:
	cmp r0, 0x3
	beq _080E0894
	b _080E08A4
_080E0876:
	ldr r4, =0x00002016
	adds r0, r2, r4
	adds r0, r5
	mov r1, r10
	b _080E08B6
	.pool
_080E0884:
	ldr r4, =0x00002016
	adds r0, r2, r4
	adds r0, r5
	movs r1, 0x1
	b _080E08B6
	.pool
_080E0894:
	ldr r1, =0x00002016
	adds r0, r2, r1
	adds r0, r5
	movs r1, 0x2
	b _080E08B6
	.pool
_080E08A4:
	mov r2, r9
	ldr r0, [r2]
	mov r2, r8
	adds r1, r4, r2
	lsls r1, 1
	ldr r4, =0x00002016
	adds r0, r4
	adds r0, r1
	movs r1, 0x3
_080E08B6:
	strh r1, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_080E08C2:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x6
	bhi _080E08CE
	b _080E07AA
_080E08CE:
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x4
	bhi _080E08DA
	b _080E07A4
_080E08DA:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuCollectEventObjectData

	thumb_func_start BuyMenuDrawEventObjects
@ void BuyMenuDrawEventObjects()
BuyMenuDrawEventObjects: @ 80E08F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r7, 0
	ldr r0, =gShopDataPtr
	mov r8, r0
	ldr r1, =gEventObjects
	mov r10, r1
	ldr r2, =gSprites
	mov r9, r2
_080E090A:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, 2
	adds r1, r7
	lsls r5, r1, 1
	ldr r4, =0x00002010
	adds r0, r4
	adds r1, r0, r5
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x10
	beq _080E09D8
	adds r1, r0, 0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrb r0, [r0, 0x5]
	bl GetEventObjectGraphicsInfo
	mov r4, r8
	ldr r3, [r4]
	ldr r2, =0x00002010
	adds r1, r3, r2
	adds r1, r5
	movs r4, 0
	ldrsh r2, [r1, r4]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	add r1, r10
	ldrb r4, [r1, 0x5]
	ldr r2, =0x00002012
	adds r1, r3, r2
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 4
	adds r2, 0x8
	lsls r2, 16
	asrs r2, 16
	ldr r1, =0x00002014
	adds r3, r1
	adds r3, r5
	ldrh r3, [r3]
	lsls r3, 4
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r0, 0x30
	subs r3, r0
	lsls r3, 16
	asrs r3, 16
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	ldr r1, =SpriteCallbackDummy
	bl AddPseudoEventObject
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r2, =0x00002010
	adds r1, r5, r2
	mov r3, r8
	ldr r0, [r3]
	adds r0, r1
	bl BuyMenuCheckIfEventObjectOverlapsMenuBg
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E09C0
	lsls r2, r4, 4
	adds r2, r4
	lsls r2, 2
	add r2, r9
	adds r2, 0x42
	ldrb r0, [r2]
	movs r4, 0x40
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
_080E09C0:
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	add r0, r9
	mov r2, r8
	ldr r1, [r2]
	ldr r3, =0x00002016
	adds r1, r3
	adds r1, r5
	ldrb r1, [r1]
	bl StartSpriteAnim
_080E09D8:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xF
	bls _080E090A
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuDrawEventObjects

	thumb_func_start BuyMenuCheckIfEventObjectOverlapsMenuBg
BuyMenuCheckIfEventObjectOverlapsMenuBg: @ 80E0A14
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	adds r1, 0x2
	bl BuyMenuCheckForOverlapWithMenuBg
	lsls r0, 24
	cmp r0, 0
	bne _080E0A38
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080E0A38
	movs r0, 0x1
	b _080E0A3A
_080E0A38:
	movs r0, 0
_080E0A3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end BuyMenuCheckIfEventObjectOverlapsMenuBg

	thumb_func_start BuyMenuCopyMenuBgToBg1TilemapBuffer
@ void BuyMenuCopyMenuBgToBg1TilemapBuffer()
BuyMenuCopyMenuBgToBg1TilemapBuffer: @ 80E0A40
	push {r4-r6,lr}
	ldr r0, =gShopDataPtr
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	adds r4, r0, r1
	adds r3, r0, 0
	movs r1, 0
	ldr r0, =0x0000c3e3
	adds r6, r0, 0
	ldr r5, =0x000003ff
_080E0A56:
	lsls r0, r1, 16
	asrs r2, r0, 16
	lsls r1, r2, 1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _080E0A6A
	adds r1, r4
	adds r0, r6
	strh r0, [r1]
_080E0A6A:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, r5
	ble _080E0A56
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuCopyMenuBgToBg1TilemapBuffer

	thumb_func_start BuyMenuCheckForOverlapWithMenuBg
@ bool8 BuyMenuCheckForOverlapWithMenuBg(u16 x, u16 y)
BuyMenuCheckForOverlapWithMenuBg: @ 80E0A88
	push {lr}
	ldr r2, =gShopDataPtr
	ldr r2, [r2]
	lsls r0, 1
	lsls r1, 6
	adds r1, r0
	lsls r1, 1
	adds r1, r2
	ldrh r0, [r1]
	cmp r0, 0
	bne _080E0AC0
	adds r0, r1, 0
	adds r0, 0x40
	ldrh r0, [r0]
	cmp r0, 0
	bne _080E0AC0
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _080E0AC0
	adds r0, r1, 0
	adds r0, 0x42
	ldrh r0, [r0]
	cmp r0, 0
	bne _080E0AC0
	movs r0, 0x1
	b _080E0AC2
	.pool
_080E0AC0:
	movs r0, 0
_080E0AC2:
	pop {r1}
	bx r1
	thumb_func_end BuyMenuCheckForOverlapWithMenuBg

	thumb_func_start Task_BuyMenu
@ void Task_BuyMenu(u8 taskId)
Task_BuyMenu: @ 80E0AC8
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
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080E0AEA
	b _080E0C8E
_080E0AEA:
	ldrb r0, [r4, 0xE]
	bl ListMenuHandleInputGetItemId
	adds r5, r0, 0
	ldrb r0, [r4, 0xE]
	ldr r7, =gShopDataPtr
	ldr r2, [r7]
	ldr r3, =0x00002008
	adds r1, r2, r3
	subs r3, 0x2
	adds r2, r3
	bl ListMenuGetScrollAndRow
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _080E0B24
	adds r0, 0x1
	cmp r5, r0
	bne _080E0B32
	b _080E0C8E
	.pool
_080E0B24:
	movs r0, 0x5
	bl PlaySE
	adds r0, r6, 0
	bl ExitBuyMenu
	b _080E0C8E
_080E0B32:
	movs r0, 0x5
	bl PlaySE
	strh r5, [r4, 0xA]
	movs r0, 0x2
	bl ClearWindowTilemap
	bl BuyMenuRemoveScrollIndicatorArrows
	ldrb r0, [r4, 0xE]
	movs r1, 0x2
	bl BuyMenuPrintCursor
	ldr r0, =gMartInfo
	ldrb r0, [r0, 0xF]
	cmp r0, 0
	bne _080E0B80
	lsls r0, r5, 16
	lsrs r0, 16
	bl ItemId_GetPrice
	adds r4, r0, 0
	movs r0, 0x1
	bl GetPriceReduction
	ldr r1, [r7]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	asrs r4, r0
	str r4, [r1]
	b _080E0B92
	.pool
_080E0B80:
	ldr r1, [r7]
	movs r3, 0x80
	lsls r3, 6
	adds r1, r3
	ldr r2, =gDecorations
	lsls r0, r5, 5
	adds r0, r2
	ldrh r0, [r0, 0x14]
	str r0, [r1]
_080E0B92:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	ldr r2, =gShopDataPtr
	mov r8, r2
	ldr r1, [r2]
	movs r7, 0x80
	lsls r7, 6
	adds r1, r7
	ldr r1, [r1]
	bl IsEnoughMoney
	lsls r0, 24
	cmp r0, 0
	bne _080E0BD0
	ldr r1, =gText_YouDontHaveMoney
	ldr r2, =BuyMenuReturnToItemList
	b _080E0C28
	.pool
_080E0BD0:
	ldr r4, =gMartInfo
	ldrb r0, [r4, 0xF]
	cmp r0, 0
	bne _080E0C38
	lsls r0, r5, 16
	lsrs r5, r0, 16
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl CopyItemName
	adds r0, r5, 0
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080E0C24
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
	ldr r1, =gText_Var1CertainlyHowMany2
	b _080E0C26
	.pool
_080E0C24:
	ldr r1, =gText_Var1CertainlyHowMany
_080E0C26:
	ldr r2, =Task_BuyHowManyDialogueInit
_080E0C28:
	adds r0, r6, 0
	bl BuyMenuDisplayMessage
	b _080E0C8E
	.pool
_080E0C38:
	ldr r0, =gStringVar1
	lsls r1, r5, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	mov r3, r8
	ldr r1, [r3]
	adds r1, r7
	ldr r1, [r1]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldrb r0, [r4, 0xF]
	cmp r0, 0x1
	bne _080E0C7C
	ldr r0, =gStringVar4
	ldr r1, =gText_Var1IsItThatllBeVar2
	bl StringExpandPlaceholders
	b _080E0C84
	.pool
_080E0C7C:
	ldr r0, =gStringVar4
	ldr r1, =gText_YouWantedVar1ThatllBeVar2
	bl StringExpandPlaceholders
_080E0C84:
	ldr r1, =gStringVar4
	ldr r2, =BuyMenuConfirmPurchase
	adds r0, r6, 0
	bl BuyMenuDisplayMessage
_080E0C8E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_BuyMenu

	thumb_func_start Task_BuyHowManyDialogueInit
@ void Task_BuyHowManyDialogueInit(u8 taskId)
Task_BuyHowManyDialogueInit: @ 80E0CA4
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r5, r6, 2
	adds r5, r6
	lsls r5, 3
	ldr r0, =gTasks + 0x8
	adds r5, r0
	ldrh r0, [r5, 0xA]
	bl CountTotalItemQuantityInBag
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r0, =gStringVar1
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_InBagVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl BuyMenuPrint
	movs r0, 0x1
	strh r0, [r5, 0x2]
	movs r0, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xD
	bl SetWindowBorderStyle
	adds r0, r6, 0
	bl BuyMenuPrintItemQuantityAndPrice
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	bl GetMoney
	ldr r1, =gShopDataPtr
	ldr r4, [r1]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r4, r2
	ldr r1, [r1]
	bl __udivsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x63
	bls _080E0D60
	ldr r0, =0x0000200a
	adds r1, r4, r0
	movs r0, 0x63
	strb r0, [r1]
	b _080E0D66
	.pool
_080E0D60:
	ldr r2, =0x0000200a
	adds r0, r4, r2
	strb r1, [r0]
_080E0D66:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =Task_BuyHowManyDialogueHandleInput
	str r0, [r1]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_BuyHowManyDialogueInit

	thumb_func_start Task_BuyHowManyDialogueHandleInput
@ void Task_BuyHowManyDialogueHandleInput(u8 taskId)
Task_BuyHowManyDialogueHandleInput: @ 80E0D88
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, r6, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	adds r0, r5, 0x2
	ldr r7, =gShopDataPtr
	ldr r1, [r7]
	ldr r2, =0x0000200a
	adds r1, r2
	ldrb r1, [r1]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E0DF0
	ldrh r0, [r5, 0xA]
	bl ItemId_GetPrice
	adds r4, r0, 0
	movs r0, 0x1
	bl GetPriceReduction
	ldr r1, [r7]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	asrs r4, r0
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	muls r0, r4
	str r0, [r1]
	adds r0, r6, 0
	bl BuyMenuPrintItemQuantityAndPrice
	b _080E0EA4
	.pool
_080E0DF0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080E0E74
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x4
	bl ClearWindowTilemap
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	ldrh r0, [r5, 0xA]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar3
	ldr r1, [r7]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_Var1AndYouWantedVar2
	ldr r2, =BuyMenuConfirmPurchase
	adds r0, r6, 0
	bl BuyMenuDisplayMessage
	b _080E0EA4
	.pool
_080E0E74:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080E0EA4
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x4
	bl ClearWindowTilemap
	movs r0, 0x3
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl BuyMenuReturnToItemList
_080E0EA4:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end Task_BuyHowManyDialogueHandleInput

	thumb_func_start BuyMenuConfirmPurchase
@ void BuyMenuConfirmPurchase(u8 taskId)
BuyMenuConfirmPurchase: @ 80E0EAC
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_08589AA8
	movs r2, 0
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	ldr r2, =gUnknown_08589A08
	str r2, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuConfirmPurchase

	thumb_func_start BuyMenuTryMakePurchase
@ void BuyMenuTryMakePurchase(u8 taskId)
BuyMenuTryMakePurchase: @ 80E0EDC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r6, =gMartInfo
	ldrb r0, [r6, 0xF]
	cmp r0, 0
	bne _080E0F40
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x2]
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E0F30
	ldr r1, =gText_HereYouGoThankYou
	ldr r2, =BuyMenuSubtractMoney
	adds r0, r5, 0
	bl BuyMenuDisplayMessage
	adds r0, r5, 0
	bl RecordItemPurchase
	b _080E0F7A
	.pool
_080E0F30:
	ldr r1, =gText_NoMoreRoomForThis
	ldr r2, =BuyMenuReturnToItemList
	b _080E0F60
	.pool
_080E0F40:
	ldrb r0, [r4, 0xA]
	bl DecorationAdd
	lsls r0, 24
	cmp r0, 0
	beq _080E0F70
	ldrb r0, [r6, 0xF]
	cmp r0, 0x1
	bne _080E0F5C
	ldr r1, =gText_ThankYouIllSendItHome
	b _080E0F5E
	.pool
_080E0F5C:
	ldr r1, =gText_ThanksIllSendItHome
_080E0F5E:
	ldr r2, =BuyMenuSubtractMoney
_080E0F60:
	adds r0, r5, 0
	bl BuyMenuDisplayMessage
	b _080E0F7A
	.pool
_080E0F70:
	ldr r1, =gText_SpaceForVar1Full
	ldr r2, =BuyMenuReturnToItemList
	adds r0, r7, 0
	bl BuyMenuDisplayMessage
_080E0F7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuTryMakePurchase

	thumb_func_start BuyMenuSubtractMoney
@ void BuyMenuSubtractMoney(u8 taskId)
BuyMenuSubtractMoney: @ 80E0F88
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x26
	bl IncrementGameStat
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	movs r4, 0x92
	lsls r4, 3
	adds r0, r4
	ldr r1, =gShopDataPtr
	ldr r1, [r1]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2
	ldr r1, [r1]
	bl RemoveMoney
	movs r0, 0x5F
	bl PlaySE
	ldr r0, [r5]
	adds r0, r4
	bl GetMoney
	adds r1, r0, 0
	movs r0, 0
	movs r2, 0
	bl PrintMoneyAmountInMoneyBox
	ldr r0, =gMartInfo
	ldrb r0, [r0, 0xF]
	cmp r0, 0
	bne _080E0FF0
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =Task_ReturnToItemListAfterItemPurchase
	b _080E0FFC
	.pool
_080E0FF0:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =Task_ReturnToItemListAfterDecorationPurchase
_080E0FFC:
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuSubtractMoney

	thumb_func_start Task_ReturnToItemListAfterItemPurchase
@ void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
Task_ReturnToItemListAfterItemPurchase: @ 80E100C
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
	beq _080E1072
	movs r0, 0x5
	bl PlaySE
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bne _080E106C
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	ble _080E106C
	movs r0, 0xC
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E106C
	ldr r1, =gText_ThrowInPremierBall
	ldr r2, =BuyMenuReturnToItemList
	adds r0, r4, 0
	bl BuyMenuDisplayMessage
	b _080E1072
	.pool
_080E106C:
	adds r0, r4, 0
	bl BuyMenuReturnToItemList
_080E1072:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end Task_ReturnToItemListAfterItemPurchase

	thumb_func_start Task_ReturnToItemListAfterDecorationPurchase
@ void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
Task_ReturnToItemListAfterDecorationPurchase: @ 80E1078
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080E1096
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl BuyMenuReturnToItemList
_080E1096:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_ReturnToItemListAfterDecorationPurchase

	thumb_func_start BuyMenuReturnToItemList
@ void BuyMenuReturnToItemList(u8 taskId)
BuyMenuReturnToItemList: @ 80E10A0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	movs r0, 0x5
	movs r1, 0
	bl sub_8197DF8
	ldrb r0, [r6, 0xE]
	movs r1, 0x1
	bl BuyMenuPrintCursor
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	bl BuyMenuAddScrollIndicatorArrows
	subs r5, 0x8
	adds r4, r5
	ldr r0, =Task_BuyMenu
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuReturnToItemList

	thumb_func_start BuyMenuPrintItemQuantityAndPrice
@ void BuyMenuPrintItemQuantityAndPrice(u8 taskId)
BuyMenuPrintItemQuantityAndPrice: @ 80E10EC
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0x4
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gShopDataPtr
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0xFF
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0x26
	movs r2, 0x1
	bl PrintMoneyAmount
	ldr r0, =gStringVar1
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x4
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl BuyMenuPrint
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BuyMenuPrintItemQuantityAndPrice

	thumb_func_start ExitBuyMenu
@ void ExitBuyMenu(u8 taskId)
ExitBuyMenu: @ 80E1168
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gFieldCallback
	ldr r0, =MapPostLoadHook_ExitBuyOrSellMenu
	str r0, [r1]
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
	ldr r1, =Task_ExitBuyMenu
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ExitBuyMenu

	thumb_func_start Task_ExitBuyMenu
@ void Task_ExitBuyMenu(u8 taskId)
Task_ExitBuyMenu: @ 80E11B0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E11D6
	bl RemoveMoneyLabelObject
	bl BuyMenuFreeMemory
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_080E11D6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_ExitBuyMenu

	thumb_func_start ClearItemPurchases
@ void ClearItemPurchases()
ClearItemPurchases: @ 80E11E4
	push {lr}
	ldr r0, =gUnknown_02039F7C
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_02039F80
	movs r1, 0
	movs r2, 0xC
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearItemPurchases

	thumb_func_start RecordItemPurchase
@ void RecordItemPurchase(u8 taskId)
RecordItemPurchase: @ 80E1204
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r3, 0
	ldr r5, =gUnknown_02039F80
	adds r6, r5, 0
_080E121A:
	lsls r0, r3, 2
	adds r2, r0, r6
	ldrh r1, [r2]
	movs r7, 0xA
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bne _080E1250
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	beq _080E1250
	adds r1, r0, 0
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	adds r0, r1, r0
	cmp r0, 0xFF
	ble _080E1248
	movs r0, 0xFF
	strh r0, [r2, 0x2]
	b _080E127A
	.pool
_080E1248:
	ldrh r0, [r4, 0x2]
	adds r0, r1, r0
	strh r0, [r2, 0x2]
	b _080E127A
_080E1250:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x2
	bls _080E121A
	ldr r2, =gUnknown_02039F7C
	ldrb r0, [r2]
	cmp r0, 0x2
	bhi _080E127A
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r4, 0xA]
	strh r1, [r0]
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r4, 0x2]
	strh r1, [r0, 0x2]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
_080E127A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RecordItemPurchase

	thumb_func_start CreatePokemartMenu
@ void CreatePokemartMenu(u16 *itemsForSale)
CreatePokemartMenu: @ 80E1284
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl CreateShopMenu
	adds r0, r4, 0
	bl SetShopItemsForSale
	bl ClearItemPurchases
	ldr r0, =EnableBothScriptContexts
	bl SetShopMenuCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreatePokemartMenu

	thumb_func_start CreateDecorationShop1Menu
@ void CreateDecorationShop1Menu(u16 *itemsForSale)
CreateDecorationShop1Menu: @ 80E12A8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl CreateShopMenu
	adds r0, r4, 0
	bl SetShopItemsForSale
	ldr r0, =EnableBothScriptContexts
	bl SetShopMenuCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateDecorationShop1Menu

	thumb_func_start CreateDecorationShop2Menu
@ void CreateDecorationShop2Menu(u16 *itemsForSale)
CreateDecorationShop2Menu: @ 80E12C8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	bl CreateShopMenu
	adds r0, r4, 0
	bl SetShopItemsForSale
	ldr r0, =EnableBothScriptContexts
	bl SetShopMenuCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateDecorationShop2Menu

	thumb_func_start sub_80E12E8
sub_80E12E8: @ 80E12E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r1
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	mov r10, r2
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r1, 0x12]
	subs r0, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r4, [r1, 0xA]
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080E13AC
	movs r2, 0
	lsls r5, 16
	str r5, [sp, 0xC]
	lsls r0, r3, 16
	lsls r1, r4, 16
	asrs r0, 16
	str r0, [sp]
	asrs r1, 16
	str r1, [sp, 0x4]
	lsls r0, r1, 1
	mov r1, r9
	adds r7, r0, r1
_080E133C:
	movs r4, 0
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	ldr r2, [sp]
	adds r6, r2, r0
_080E1348:
	ldr r0, [sp, 0xC]
	asrs r1, r0, 16
	lsls r4, 16
	asrs r0, r4, 16
	adds r5, r1, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridGetMetatileIdAt
	movs r2, 0
	ldrsh r1, [r7, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _080E1390
	ldr r0, [sp, 0x4]
	cmp r0, 0x2
	beq _080E1380
	ldrh r0, [r7, 0x2]
	mov r2, r10
	orrs r2, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridSetMetatileIdAt
	b _080E1390
	.pool
_080E1380:
	mov r1, r9
	ldrh r0, [r1]
	mov r2, r10
	orrs r2, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridSetMetatileIdAt
_080E1390:
	movs r2, 0x80
	lsls r2, 9
	adds r0, r4, r2
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080E1348
	adds r0, r2, 0
	add r0, r8
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080E133C
	b _080E1434
_080E13AC:
	movs r2, 0
	lsls r5, 16
	str r5, [sp, 0xC]
	lsls r0, r3, 16
	lsls r1, r4, 16
	asrs r0, 16
	str r0, [sp, 0x8]
	asrs r7, r1, 16
_080E13BC:
	movs r4, 0
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	ldr r1, [sp, 0x8]
	adds r6, r1, r0
_080E13C8:
	ldr r2, [sp, 0xC]
	asrs r1, r2, 16
	lsls r4, 16
	asrs r0, r4, 16
	adds r5, r1, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x2
	subs r1, r7
	lsls r1, 1
	add r1, r9
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _080E141A
	cmp r7, 0x2
	beq _080E140A
	movs r0, 0x1
	subs r0, r7
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	mov r2, r10
	orrs r2, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridSetMetatileIdAt
	b _080E141A
_080E140A:
	mov r1, r9
	ldrh r0, [r1, 0x4]
	mov r2, r10
	orrs r2, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridSetMetatileIdAt
_080E141A:
	movs r2, 0x80
	lsls r2, 9
	adds r0, r4, r2
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080E13C8
	adds r0, r2, 0
	add r0, r8
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _080E13BC
_080E1434:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E12E8

	thumb_func_start sub_80E1444
sub_80E1444: @ 80E1444
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0x1
	strh r0, [r4, 0x6]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bhi _080E14DE
	lsls r0, 2
	ldr r1, =_080E1474
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E1474:
	.4byte _080E1490
	.4byte _080E1498
	.4byte _080E14A0
	.4byte _080E14A8
	.4byte _080E14B0
	.4byte _080E14C4
	.4byte _080E14D4
_080E1490:
	ldr r1, =gUnknown_08589ABA
	b _080E14C6
	.pool
_080E1498:
	ldr r1, =gUnknown_08589AC0
	b _080E14C6
	.pool
_080E14A0:
	ldr r1, =gUnknown_08589AC6
	b _080E14B2
	.pool
_080E14A8:
	ldr r1, =gUnknown_08589ACC
	b _080E14C6
	.pool
_080E14B0:
	ldr r1, =gUnknown_08589AD2
_080E14B2:
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r3, 0
	bl sub_80E12E8
	b _080E14DE
	.pool
_080E14C4:
	ldr r1, =gUnknown_08589AD8
_080E14C6:
	adds r0, r3, 0
	movs r2, 0
	bl sub_80E12E8
	b _080E14DE
	.pool
_080E14D4:
	ldr r1, =gUnknown_08589ADE
	adds r0, r3, 0
	movs r2, 0
	bl sub_80E12E8
_080E14DE:
	ldrh r0, [r4]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r4]
	adds r5, r0, 0
	cmp r5, 0
	bne _080E1502
	bl DrawWholeMapView
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r1, 0x3
	bl __modsi3
	strh r0, [r4, 0x2]
	strh r5, [r4, 0x6]
_080E1502:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E1444

	thumb_func_start sub_80E150C
sub_80E150C: @ 80E150C
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =sub_80E1444
	adds r0, r6, 0
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	adds r0, r7, 0
	adds r0, 0x8
	adds r1, r7, 0
	adds r1, 0xA
	bl PlayerGetDestCoords
	movs r0, 0
	strh r0, [r7]
	strh r0, [r7, 0x2]
	strh r5, [r7, 0x4]
	adds r0, r4, 0
	bl _call_via_r6
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E150C

	thumb_func_start sub_80E1558
sub_80E1558: @ 80E1558
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E150C
	ldr r1, =gUnknown_02039F8C
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E1558

	thumb_func_start sub_80E1570
sub_80E1570: @ 80E1570
	push {lr}
	ldr r0, =gUnknown_02039F8C
	ldrb r0, [r0]
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E1570

	thumb_func_start sub_80E1584
sub_80E1584: @ 80E1584
	push {lr}
	ldr r2, =gTasks
	ldr r0, =gUnknown_02039F8C
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080E15B0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	bne _080E15B0
	movs r0, 0
	b _080E15B2
	.pool
_080E15B0:
	movs r0, 0x1
_080E15B2:
	pop {r1}
	bx r1
	thumb_func_end sub_80E1584

	.align 2, 0 @ Don't pad with nop.
