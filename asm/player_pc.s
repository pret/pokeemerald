	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


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
