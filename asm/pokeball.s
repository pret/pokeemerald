	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80753E8
sub_80753E8: @ 80753E8
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =sub_8075450
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	ldrb r0, [r6]
	strh r0, [r1, 0xE]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80753E8

	thumb_func_start sub_8075450
sub_8075450: @ 8075450
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r0, 0
	str r0, [sp]
	ldr r1, =gTasks
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x8]
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08075488
	adds r0, r2, 0x1
	strh r0, [r1, 0x8]
	b _08075602
	.pool
_08075488:
	ldrh r0, [r1, 0xC]
	mov r8, r0
	ldrb r5, [r1, 0xE]
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080754B4
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _080754C2
	.pool
_080754B4:
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_080754C2:
	adds r0, r1
	movs r1, 0x26
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8076A78
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r1, =gUnknown_0832C588
	adds r0, r1
	movs r1, 0x20
	movs r2, 0x50
	movs r3, 0x1D
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gSprites
	mov r9, r2
	lsls r0, r7, 4
	adds r0, r7
	lsls r6, r0, 2
	adds r4, r6, r2
	movs r0, 0x80
	strh r0, [r4, 0x2E]
	movs r3, 0
	strh r3, [r4, 0x30]
	mov r0, r8
	strh r0, [r4, 0x3C]
	mov r2, r8
	cmp r2, 0xFE
	beq _08075548
	cmp r2, 0xFF
	bne _08075584
	ldr r0, =gBankTarget
	strb r5, [r0]
	movs r0, 0x18
	strh r0, [r4, 0x20]
	movs r0, 0x44
	strh r0, [r4, 0x22]
	mov r0, r9
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =sub_80761B4
	str r1, [r0]
	b _08075592
	.pool
_08075548:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x18
	strh r0, [r4, 0x22]
	ldr r0, =gBankTarget
	strb r5, [r0]
	movs r3, 0
	strh r3, [r4, 0x2E]
	mov r0, r9
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =sub_8076398
	str r1, [r0]
	b _08075592
	.pool
_08075584:
	movs r0, 0x1
	bl GetBankByIdentity
	ldr r1, =gBankTarget
	strb r0, [r1]
	movs r0, 0x1
	str r0, [sp]
_08075592:
	ldr r0, =gSprites
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	adds r4, r1, r0
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	strh r0, [r4, 0x3A]
	ldr r2, [sp]
	cmp r2, 0
	bne _080755B8
	mov r0, r10
	bl DestroyTask
	b _08075602
	.pool
_080755B8:
	movs r0, 0x22
	strh r0, [r4, 0x2E]
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	mov r3, r10
	strh r3, [r4, 0x6]
	ldr r1, =gTasks
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r5]
	strh r1, [r0, 0x10]
	ldr r1, =TaskDummy
	str r1, [r0]
	movs r0, 0x3D
	bl PlaySE
_08075602:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075450

	thumb_func_start objc_0804ABD4
objc_0804ABD4: @ 8075620
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _080756C0
	ldrb r6, [r7, 0x6]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldrb r5, [r0, 0x10]
	ldrb r0, [r0, 0xC]
	mov r8, r0
	adds r0, r7, 0
	movs r1, 0x1
	bl StartSpriteAnim
	adds r2, r7, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r7, 0x24]
	ldrh r1, [r7, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r7, 0x20]
	ldrh r0, [r7, 0x26]
	ldrh r2, [r7, 0x22]
	adds r0, r2
	strh r0, [r7, 0x22]
	strh r1, [r7, 0x24]
	strh r1, [r7, 0x26]
	strh r1, [r7, 0x38]
	adds r0, r5, 0
	bl sub_8076B14
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	ldrh r0, [r7, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r7, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl sub_8171D98
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0xE
	adds r3, r4, 0
	bl sub_81729E8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x2E]
	strh r5, [r7, 0x3A]
	mov r0, r8
	strh r0, [r7, 0x3C]
	adds r0, r6, 0
	bl DestroyTask
	ldr r0, =sub_80756D4
	str r0, [r7, 0x1C]
_080756C0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end objc_0804ABD4

	thumb_func_start sub_80756D4
sub_80756D4: @ 80756D4
	ldr r1, =sub_80756E0
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_80756D4

	thumb_func_start sub_80756E0
sub_80756E0: @ 80756E0
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x38]
	adds r0, 0x1
	movs r7, 0
	strh r0, [r6, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0807573A
	strh r7, [r6, 0x38]
	ldr r0, =sub_807574C
	str r0, [r6, 0x1C]
	ldr r5, =gBankSpriteIds
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0x2
	bl StartSpriteAffineAnim
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl AnimateSprite
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r7, [r0, 0x30]
_0807573A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80756E0

	thumb_func_start sub_807574C
sub_807574C: @ 807574C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08075764
	movs r0, 0x3C
	bl PlaySE
_08075764:
	ldr r6, =gSprites
	ldr r5, =gBankSpriteIds
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r6
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080757BC
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0
	strh r0, [r4, 0x38]
	ldr r0, =sub_80757E4
	str r0, [r4, 0x1C]
	b _080757DC
	.pool
_080757BC:
	ldrh r0, [r1, 0x30]
	adds r0, 0x60
	strh r0, [r1, 0x30]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	adds r0, r5
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	negs r0, r0
	asrs r0, 8
	strh r0, [r1, 0x26]
_080757DC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_807574C

	thumb_func_start sub_80757E4
sub_80757E4: @ 80757E4
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0807582C
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0807582C
	strh r1, [r4, 0x34]
	movs r0, 0x20
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	movs r0, 0
	movs r1, 0x20
	bl Cos
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldr r0, =sub_8075838
	str r0, [r4, 0x1C]
_0807582C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80757E4

	thumb_func_start sub_8075838
sub_8075838: @ 8075838
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0
	beq _0807584E
	cmp r1, 0x1
	beq _080758C2
	b _080758EE
_0807584E:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	adds r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	adds r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3F
	ble _080758EE
	ldrh r0, [r4, 0x36]
	subs r0, 0xA
	strh r0, [r4, 0x36]
	ldr r1, =0x00000101
	adds r0, r2, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	cmp r0, 0x4
	bne _0807588A
	movs r5, 0x1
_0807588A:
	cmp r0, 0x2
	beq _080758AA
	cmp r0, 0x2
	bgt _0807589C
	cmp r0, 0x1
	beq _080758A2
	b _080758BA
	.pool
_0807589C:
	cmp r0, 0x3
	beq _080758B2
	b _080758BA
_080758A2:
	movs r0, 0x38
	bl PlaySE
	b _080758EE
_080758AA:
	movs r0, 0x39
	bl PlaySE
	b _080758EE
_080758B2:
	movs r0, 0x3A
	bl PlaySE
	b _080758EE
_080758BA:
	movs r0, 0x3B
	bl PlaySE
	b _080758EE
_080758C2:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	subs r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	subs r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	cmp r1, 0
	bgt _080758EE
	strh r5, [r4, 0x38]
	ldr r0, =0xffffff00
	ands r0, r2
	strh r0, [r4, 0x34]
_080758EE:
	cmp r5, 0
	beq _08075926
	movs r5, 0
	strh r5, [r4, 0x34]
	movs r0, 0x40
	movs r1, 0x20
	bl Cos
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x26]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0807591C
	ldr r0, =sub_8075D14
	str r0, [r4, 0x1C]
	b _08075926
	.pool
_0807591C:
	ldr r0, =sub_8075930
	str r0, [r4, 0x1C]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
_08075926:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075838

	thumb_func_start sub_8075930
sub_8075930: @ 8075930
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08075964
	movs r0, 0
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =sub_8075970
	str r0, [r4, 0x1C]
	movs r0, 0x17
	bl PlaySE
_08075964:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075930

	thumb_func_start sub_8075970
sub_8075970: @ 8075970
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x4
	bhi _08075A70
	lsls r0, r1, 2
	ldr r1, =_0807598C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807598C:
	.4byte _080759A0
	.4byte _080759D2
	.4byte _080759A0
	.4byte _08075A26
	.4byte _08075A70
_080759A0:
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x24]
	adds r1, r0, r2
	strh r1, [r4, 0x24]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0x3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bls _08075AB6
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	movs r0, 0
	strh r0, [r4, 0x38]
	b _08075AB6
_080759D2:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08075A18
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bge _08075A0E
	adds r0, r4, 0
	movs r1, 0x2
	bl ChangeSpriteAffineAnim
	b _08075AB6
_08075A0E:
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
	b _08075AB6
_08075A18:
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	b _08075AB6
_08075A26:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r2, [r4, 0x34]
	adds r0, r2
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08075A48
	ldr r0, =sub_8075D14
	str r0, [r4, 0x1C]
	b _08075AB6
	.pool
_08075A48:
	cmp r1, 0x4
	bne _08075A5C
	cmp r0, 0x3
	bne _08075A5C
	ldr r0, =sub_8075FB4
	str r0, [r4, 0x1C]
	b _08075A62
	.pool
_08075A5C:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
_08075A62:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	b _08075AB6
_08075A70:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08075AB6
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r1, [r4, 0x34]
	ldr r0, =0xffffff00
	ands r0, r1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAffineAnim
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _08075AA8
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	b _08075AB0
	.pool
_08075AA8:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_08075AB0:
	movs r0, 0x17
	bl PlaySE
_08075AB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8075970

	thumb_func_start c3_0804B070
c3_0804B070: @ 8075ABC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	ldrb r1, [r0, 0xC]
	mov r12, r1
	ldrb r5, [r0, 0xA]
	ldrh r6, [r0, 0x8]
	ldrb r3, [r0, 0xE]
	mov r8, r3
	ldrb r7, [r0, 0x10]
	movs r3, 0x12
	ldrsh r1, [r0, r3]
	lsls r3, r1, 16
	ldrh r1, [r0, 0x14]
	orrs r3, r1
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	cmp r0, 0x20
	bhi _08075B88
	lsls r0, 2
	ldr r1, =_08075B04
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08075B04:
	.4byte _08075B88
	.4byte _08075BB4
	.4byte _08075BDA
	.4byte _08075C54
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075BF8
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075B88
	.4byte _08075C66
	.4byte _08075C7E
	.4byte _08075CA8
_08075B88:
	ldr r0, =gSprites
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	adds r1, r0
	adds r1, 0x3F
	ldrb r0, [r1]
	lsls r0, 26
	cmp r0, 0
	blt _08075B9E
	b _08075D04
_08075B9E:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	mov r1, r12
	adds r1, 0x1
	strh r1, [r0, 0x26]
	b _08075D04
	.pool
_08075BB4:
	adds r0, r3, 0
	bl sub_805F110
	cmp r0, 0x1
	bne _08075BCC
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0
	bl PlayCry3
	b _08075C2E
_08075BCC:
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0xB
	bl PlayCry3
	b _08075C2E
_08075BDA:
	bl StopCryAndClearCrySongs
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3
	strh r1, [r0, 0x1C]
	movs r1, 0x14
	strh r1, [r0, 0x26]
	b _08075D04
	.pool
_08075BF8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r2, [r1, 0x1C]
	movs r7, 0x1C
	ldrsh r0, [r1, r7]
	cmp r0, 0
	bne _08075CBA
	adds r0, r3, 0
	bl sub_805F110
	cmp r0, 0x1
	bne _08075C22
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0x1
	bl PlayCry4
	b _08075C2E
_08075C22:
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0xC
	bl PlayCry4
_08075C2E:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r2, r8
	lsls r1, r2, 1
	add r1, r8
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	adds r0, r4, 0
	bl DestroyTask
	b _08075D04
	.pool
_08075C54:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	movs r1, 0x6
	strh r1, [r0, 0x1C]
	movs r1, 0x1E
	strh r1, [r0, 0x26]
	b _08075D04
_08075C66:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r2, [r1, 0x1C]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08075CBA
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
_08075C7E:
	bl IsCryPlayingOrClearCrySongs
	lsls r0, 24
	cmp r0, 0
	bne _08075D04
	bl StopCryAndClearCrySongs
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x3
	strh r0, [r1, 0x1C]
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _08075D04
	.pool
_08075CA8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r2, [r1, 0x1C]
	movs r7, 0x1C
	ldrsh r0, [r1, r7]
	cmp r0, 0
	beq _08075CC0
_08075CBA:
	subs r0, r2, 0x1
	strh r0, [r1, 0x1C]
	b _08075D04
_08075CC0:
	adds r0, r3, 0
	bl sub_805F110
	cmp r0, 0x1
	bne _08075CD8
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0
	bl PlayCry4
	b _08075CE4
_08075CD8:
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r6, 0
	movs r2, 0xB
	bl PlayCry4
_08075CE4:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r2, r8
	lsls r1, r2, 1
	add r1, r8
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	adds r0, r4, 0
	bl DestroyTask
_08075D04:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0804B070

	thumb_func_start sub_8075D14
sub_8075D14: @ 8075D14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldrh r0, [r6, 0x3A]
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r5, 0
	bl sub_8076B14
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	ldrh r0, [r6, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl sub_8171D98
	ldrh r1, [r6, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	movs r2, 0xE
	adds r3, r4, 0
	bl sub_81729E8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x2E]
	ldr r0, =sub_8075FD4
	str r0, [r6, 0x1C]
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08075D88
	b _08075EF4
_08075D88:
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08075DC0
	ldr r0, =gBattlePartyID
	lsls r2, r5, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r7, r1, r0
	movs r4, 0x19
	mov r10, r4
	b _08075DD4
	.pool
_08075DC0:
	ldr r0, =gBattlePartyID
	lsls r2, r5, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	movs r0, 0xE7
	mov r10, r0
_08075DD4:
	mov r8, r2
	adds r0, r7, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _08075E00
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _08075E56
_08075E00:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08075E56
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08075E56
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08075E4C
	bl IsBGMPlaying
	lsls r0, 24
	cmp r0, 0
	beq _08075E56
	ldr r0, =gMPlay_BGM
	bl m4aMPlayStop
	b _08075E56
	.pool
_08075E4C:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	bl m4aMPlayVolumeControl
_08075E56:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08075E70
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08075E80
_08075E70:
	movs r4, 0
	b _08075EA2
	.pool
_08075E80:
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _08075E9C
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _08075EA0
_08075E9C:
	movs r4, 0x1
	b _08075EA2
_08075EA0:
	movs r4, 0x2
_08075EA2:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r2, r8
	adds r1, r2, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1, 0x1]
	ldr r0, =c3_0804B070
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r3, 0
	mov r0, r9
	strh r0, [r1, 0x8]
	mov r2, r10
	lsls r0, r2, 24
	asrs r0, 24
	strh r0, [r1, 0xA]
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	ldr r2, =gBankSpriteIds
	movs r4, 0x3A
	ldrsh r0, [r6, r4]
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0x10]
	lsrs r0, r7, 16
	strh r0, [r1, 0x12]
	strh r7, [r1, 0x14]
	strh r3, [r1, 0x26]
_08075EF4:
	ldr r4, =gBankSpriteIds
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldrh r0, [r6, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08075F50
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8039B58
	b _08075F66
	.pool
_08075F50:
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8039E44
_08075F66:
	str r1, [r0]
	ldr r5, =gBankSpriteIds
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl AnimateSprite
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x80
	lsls r1, 5
	strh r1, [r0, 0x30]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075D14

	thumb_func_start sub_8075FB4
sub_8075FB4: @ 8075FB4
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r1, [r3]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =sub_80760F8
	str r1, [r0, 0x1C]
	movs r1, 0
	strh r1, [r0, 0x34]
	strh r1, [r0, 0x36]
	strh r1, [r0, 0x38]
	bx lr
	.pool
	thumb_func_end sub_8075FB4

	thumb_func_start sub_8075FD4
sub_8075FD4: @ 8075FD4
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	ldrh r0, [r5, 0x3A]
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gSprites
	ldr r0, =gBankSpriteIds
	adds r3, r6, r0
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08076016
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08076016:
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _08076040
	adds r0, r1, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r7, 0x1
	b _0807605C
	.pool
_08076040:
	ldr r2, =0xfffffee0
	adds r0, r2, 0
	ldrh r2, [r1, 0x30]
	adds r0, r2
	strh r0, [r1, 0x30]
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r1, 0x26]
_0807605C:
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080760DE
	cmp r7, 0
	beq _080760DE
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r6, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x26]
	ldr r0, =gDoingBattleAnim
	strb r2, [r0]
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl FreeSpriteOamMatrix
	adds r0, r5, 0
	bl DestroySprite
	movs r3, 0
	ldr r0, [r4]
	ldr r2, [r0, 0x4]
	movs r5, 0x8
	movs r4, 0x3
_080760B6:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080760C2
	adds r3, 0x1
_080760C2:
	adds r2, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _080760B6
	cmp r3, 0x4
	bne _080760DE
	movs r4, 0
_080760D0:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8076AE8
	adds r4, 0x1
	cmp r4, 0xB
	ble _080760D0
_080760DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075FD4

	thumb_func_start sub_80760F8
sub_80760F8: @ 80760F8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x3A]
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r6, 0x36]
	adds r0, 0x1
	strh r0, [r6, 0x36]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0x28
	beq _08076196
	cmp r1, 0x5F
	bne _08076130
	ldr r0, =gDoingBattleAnim
	movs r1, 0
	strb r1, [r0]
	bl m4aMPlayAllStop
	ldr r0, =0x00000173
	bl PlaySE
	b _08076196
	.pool
_08076130:
	ldr r0, =0x0000013b
	cmp r1, r0
	bne _08076196
	ldr r5, =gSprites
	ldr r4, =gBankSpriteIds
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	adds r0, r6, 0
	bl DestroySpriteAndFreeResources
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08076196
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_08076196:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80760F8

	thumb_func_start sub_80761B4
sub_80761B4: @ 80761B4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x19
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x18
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffe2
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	strh r0, [r4, 0x6]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_8076204
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80761B4

	thumb_func_start sub_8076204
sub_8076204: @ 8076204
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldrh r0, [r5, 0x3C]
	movs r1, 0xFF
	mov r8, r1
	lsrs r0, 8
	subs r0, 0x23
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2C
	bhi _080762F8
	ldrh r1, [r5, 0x6]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	bne _08076266
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	adds r6, r1, 0
	ands r6, r0
	ldrh r0, [r5, 0x32]
	adds r7, r1, 0
	ands r7, r0
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	movs r1, 0x3
	bl __divsi3
	movs r1, 0x2
	negs r1, r1
	adds r4, r1, 0
	ands r0, r4
	orrs r6, r0
	strh r6, [r5, 0x30]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	movs r1, 0x3
	bl __divsi3
	ands r0, r4
	orrs r7, r0
	strh r7, [r5, 0x32]
	adds r0, r5, 0
	movs r1, 0x4
	bl StartSpriteAffineAnim
_08076266:
	ldrh r4, [r5, 0x2E]
	adds r0, r5, 0
	bl sub_80A6F3C
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	movs r1, 0x3
	bl __divsi3
	adds r1, r0, 0
	ldrh r0, [r5, 0x3C]
	adds r0, r1
	strh r0, [r5, 0x3C]
	lsls r0, 16
	asrs r0, 24
	mov r2, r8
	ands r0, r2
	movs r2, 0x38
	ldrsh r1, [r5, r2]
	bl Sin
	ldrh r1, [r5, 0x26]
	adds r0, r1
	strh r0, [r5, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ldrh r1, [r5, 0x6]
	adds r0, r1
	strh r0, [r5, 0x6]
	lsls r0, 16
	lsrs r0, 24
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _080762B6
	strh r4, [r5, 0x2E]
	b _080762BE
_080762B6:
	lsls r0, r4, 16
	asrs r0, 16
	subs r0, 0x1
	strh r0, [r5, 0x2E]
_080762BE:
	ldrh r0, [r5, 0x3C]
	lsrs r0, 8
	cmp r0, 0x4F
	ble _08076364
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	adds r6, r1, 0
	ands r6, r0
	ldrh r0, [r5, 0x32]
	adds r7, r1, 0
	ands r7, r0
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	lsls r0, r1, 1
	adds r0, r1
	movs r1, 0x2
	negs r1, r1
	adds r2, r1, 0
	ands r0, r2
	orrs r0, r6
	strh r0, [r5, 0x30]
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	ands r0, r2
	orrs r0, r7
	strh r0, [r5, 0x32]
	b _08076364
_080762F8:
	adds r0, r5, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08076364
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	ldrb r0, [r5, 0x6]
	strh r0, [r5, 0x3A]
	strh r1, [r5, 0x2E]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08076358
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08076358
	movs r0, 0x3A
	ldrsh r4, [r5, r0]
	movs r0, 0x2
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _08076358
	ldr r0, =sub_8076374
	b _0807635A
	.pool
_08076358:
	ldr r0, =sub_8075D14
_0807635A:
	str r0, [r5, 0x1C]
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAffineAnim
_08076364:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076204

	thumb_func_start sub_8076374
sub_8076374: @ 8076374
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r1, r0, 0x1
	strh r1, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	ble _0807638E
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldr r0, =sub_8075D14
	str r0, [r2, 0x1C]
_0807638E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076374

	thumb_func_start sub_8076398
sub_8076398: @ 8076398
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _080763EC
	movs r0, 0
	strh r0, [r5, 0x2E]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080763E8
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080763E8
	movs r0, 0x3A
	ldrsh r4, [r5, r0]
	movs r0, 0x3
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080763E8
	ldr r0, =sub_8076374
	b _080763EA
	.pool
_080763E8:
	ldr r0, =sub_8075D14
_080763EA:
	str r0, [r5, 0x1C]
_080763EC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076398

	thumb_func_start sub_80763F8
sub_80763F8: @ 80763F8
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r4, 0
	str r4, [sp]
	bl sub_8171D98
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80763F8

	thumb_func_start sub_8076420
sub_8076420: @ 8076420
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	bl sub_81729E8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8076420

	thumb_func_start sub_8076438
sub_8076438: @ 8076438
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	mov r9, r2
	mov r10, r3
	ldr r6, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r0, [sp, 0x30]
	ldr r2, [sp, 0x38]
	lsls r5, 24
	lsrs r5, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	lsls r0, r2, 16
	lsrs r7, r0, 16
	ldr r0, =gUnknown_0832C400
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0832C460
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, =gUnknown_0832C588
	mov r1, r9
	mov r2, r10
	adds r3, r4, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r8, r1
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r2, r4, r1
	strh r5, [r2, 0x2E]
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	add r1, r8
	ldrh r0, [r1, 0x20]
	strh r0, [r2, 0x38]
	ldrh r0, [r1, 0x22]
	strh r0, [r2, 0x3A]
	mov r3, r9
	strh r3, [r1, 0x20]
	mov r0, r10
	strh r0, [r1, 0x22]
	strh r7, [r1, 0x3C]
	mov r3, sp
	ldrh r3, [r3, 0x4]
	strh r3, [r2, 0x30]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2, 0x32]
	mov r3, sp
	ldrh r3, [r3, 0x34]
	strh r3, [r2, 0x34]
	ldr r3, [sp, 0x34]
	lsrs r0, r3, 16
	strh r0, [r2, 0x36]
	movs r0, 0x3
	ands r6, r0
	lsls r6, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r6
	strb r0, [r2, 0x5]
	movs r0, 0x1C
	add r8, r0
	add r4, r8
	ldr r0, =sub_8076524
	str r0, [r4]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076438

	thumb_func_start sub_8076524
sub_8076524: @ 8076524
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldrh r1, [r6, 0x30]
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _080765D0
	ldrh r0, [r6, 0x2E]
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r6, 0x32]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r4, [r6, 0x34]
	ldrh r0, [r6, 0x36]
	lsls r0, 16
	orrs r4, r0
	adds r0, r6, 0
	adds r0, 0x43
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807655E
	subs r0, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	b _08076560
_0807655E:
	movs r5, 0
_08076560:
	adds r0, r6, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r6, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r6, 0x5]
	lsls r2, 28
	lsrs r2, 30
	adds r3, r5, 0
	bl sub_80763F8
	movs r0, 0x1
	mov r1, r8
	adds r2, r4, 0
	bl sub_8076420
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r6, 0x30]
	ldr r0, =sub_80765E0
	str r0, [r6, 0x1C]
	ldr r0, =gSprites
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	adds r4, r0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	adds r0, r4, 0
	bl AnimateSprite
	movs r0, 0x80
	lsls r0, 5
	strh r0, [r4, 0x30]
	strh r5, [r6, 0x3C]
	b _080765D4
	.pool
_080765D0:
	subs r0, r1, 0x1
	strh r0, [r6, 0x30]
_080765D4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8076524

	thumb_func_start sub_80765E0
sub_80765E0: @ 80765E0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	movs r0, 0
	mov r12, r0
	movs r7, 0
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08076610
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08076610:
	ldr r1, =gSprites
	lsls r2, r6, 4
	adds r0, r2, r6
	lsls r0, 2
	adds r5, r0, r1
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	mov r8, r2
	cmp r0, 0
	bge _08076634
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r1, 0x1
	mov r12, r1
_08076634:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r3, 0x20
	ldrsh r1, [r4, r3]
	subs r0, r1
	movs r1, 0x3C
	ldrsh r2, [r4, r1]
	muls r0, r2
	cmp r0, 0
	bge _0807664A
	adds r0, 0x7F
_0807664A:
	asrs r0, 7
	ldrh r3, [r4, 0x20]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r3, 0x22
	ldrsh r1, [r4, r3]
	subs r0, r1
	muls r0, r2
	cmp r0, 0
	bge _08076668
	adds r0, 0x7F
_08076668:
	asrs r0, 7
	ldrh r1, [r4, 0x22]
	adds r0, r1
	mov r2, r9
	strh r2, [r5, 0x20]
	strh r0, [r5, 0x22]
	ldrh r2, [r4, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0x7F
	bgt _080766AC
	ldr r1, =gSineTable
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _08076690
	adds r0, 0x7
_08076690:
	asrs r0, 3
	negs r0, r0
	lsls r0, 16
	lsrs r0, 16
	adds r1, r2, 0x4
	strh r1, [r4, 0x3C]
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	b _080766BA
	.pool
_080766AC:
	ldrh r0, [r4, 0x38]
	strh r0, [r5, 0x20]
	ldrh r0, [r4, 0x3A]
	strh r0, [r5, 0x22]
	strh r7, [r5, 0x24]
	strh r7, [r5, 0x26]
	movs r7, 0x1
_080766BA:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0807670E
	mov r2, r12
	cmp r2, 0
	beq _0807670E
	cmp r7, 0
	beq _0807670E
	ldr r1, =gSprites
	mov r3, r8
	adds r0, r3, r6
	lsls r0, 2
	adds r2, r0, r1
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _080766FC
	ldrh r1, [r2, 0x3C]
	adds r0, r2, 0
	movs r2, 0x1
	movs r3, 0
	bl DoMonFrontSpriteAnimation
	b _08076708
	.pool
_080766FC:
	ldrh r1, [r2, 0x3C]
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0
	bl DoMonFrontSpriteAnimation
_08076708:
	adds r0, r4, 0
	bl DestroySpriteAndFreeResources
_0807670E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80765E0

	thumb_func_start sub_807671C
sub_807671C: @ 807671C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	adds r6, r2, 0
	mov r8, r3
	ldr r5, [sp, 0x20]
	ldr r4, [sp, 0x24]
	ldr r0, [sp, 0x28]
	mov r9, r0
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r6, 24
	lsrs r6, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gUnknown_0832C400
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0832C460
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, =gUnknown_0832C588
	adds r1, r6, 0
	mov r2, r8
	adds r3, r4, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r2, r3, r6
	mov r1, r10
	strh r1, [r2, 0x2E]
	mov r4, r9
	strh r4, [r2, 0x30]
	strh r7, [r2, 0x32]
	mov r1, sp
	ldrh r1, [r1, 0x2C]
	strh r1, [r2, 0x34]
	ldr r4, [sp, 0x2C]
	lsrs r1, r4, 16
	strh r1, [r2, 0x36]
	movs r1, 0x3
	ands r5, r1
	lsls r5, 2
	ldrb r4, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r4
	orrs r1, r5
	strb r1, [r2, 0x5]
	adds r6, 0x1C
	adds r3, r6
	ldr r1, =sub_80767D4
	str r1, [r3]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_807671C

	thumb_func_start sub_80767D4
sub_80767D4: @ 80767D4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0807686C
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r5, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	lsls r0, 16
	orrs r5, r0
	adds r0, r4, 0
	adds r0, 0x43
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807680E
	subs r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	b _08076810
_0807680E:
	movs r6, 0
_08076810:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r4, 0x5]
	lsls r2, 28
	lsrs r2, 30
	adds r3, r6, 0
	bl sub_80763F8
	movs r0, 0x1
	mov r1, r8
	adds r2, r5, 0
	bl sub_8076420
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x30]
	ldr r0, =sub_807687C
	str r0, [r4, 0x1C]
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	adds r0, r4, 0
	bl AnimateSprite
	strh r5, [r4, 0x30]
	b _08076870
	.pool
_0807686C:
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
_08076870:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80767D4

	thumb_func_start sub_807687C
sub_807687C: @ 807687C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x38]
	adds r0, 0x1
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08076894
	movs r0, 0x3C
	bl PlaySE
_08076894:
	ldrh r1, [r5, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080768D8
	adds r0, r5, 0
	movs r1, 0x2
	bl StartSpriteAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0
	strh r0, [r5, 0x38]
	ldr r0, =sub_80768F0
	str r0, [r5, 0x1C]
	b _080768E8
	.pool
_080768D8:
	ldrh r0, [r4, 0x30]
	adds r0, 0x60
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	negs r0, r0
	asrs r0, 8
	strh r0, [r4, 0x26]
_080768E8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_807687C

	thumb_func_start sub_80768F0
sub_80768F0: @ 80768F0
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08076904
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_08076904:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80768F0

	thumb_func_start obj_delete_and_free_associated_resources_
obj_delete_and_free_associated_resources_: @ 807690C
	push {lr}
	bl DestroySpriteAndFreeResources
	pop {r0}
	bx r0
	thumb_func_end obj_delete_and_free_associated_resources_

	thumb_func_start sub_8076918
sub_8076918: @ 8076918
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r0, =gHealthBoxesIds
	adds r0, r5, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gSprites
	adds r4, r0, r6
	movs r1, 0
	movs r0, 0x5
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r0, 0x73
	strh r0, [r4, 0x24]
	strh r1, [r4, 0x26]
	ldr r0, =sub_80769CC
	str r0, [r4, 0x1C]
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08076966
	ldrh r0, [r4, 0x2E]
	negs r0, r0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	negs r0, r0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x24]
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	negs r0, r0
	strh r0, [r4, 0x26]
_08076966:
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r1, r0, r1
	adds r0, r6
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r5, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08076990
	ldr r0, =sub_80769A8
	str r0, [r4, 0x1C]
_08076990:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076918

	thumb_func_start sub_80769A8
sub_80769A8: @ 80769A8
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _080769C2
	movs r0, 0
	strh r0, [r1, 0x30]
	ldr r0, =sub_80769CC
	str r0, [r1, 0x1C]
_080769C2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80769A8

	thumb_func_start sub_80769CC
sub_80769CC: @ 80769CC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x24]
	ldrh r1, [r2, 0x2E]
	subs r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x26]
	ldrh r1, [r2, 0x30]
	subs r0, r1
	strh r0, [r2, 0x26]
	ldr r0, [r2, 0x24]
	cmp r0, 0
	bne _080769EA
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_080769EA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80769CC

	thumb_func_start sub_80769F4
sub_80769F4: @ 80769F4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =oamc_804BEB4
	adds r0, r5, 0
	bl CreateInvisibleSpriteWithCallback
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r3, r1, r2
	movs r0, 0x1
	strh r0, [r3, 0x2E]
	ldr r0, =gHealthBoxesIds
	adds r4, r0
	ldrb r0, [r4]
	strh r0, [r3, 0x30]
	adds r2, 0x1C
	adds r1, r2
	str r5, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80769F4

	thumb_func_start oamc_804BEB4
oamc_804BEB4: @ 8076A38
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrh r0, [r3, 0x2E]
	movs r2, 0
	strh r0, [r1, 0x26]
	ldrh r0, [r3, 0x2E]
	negs r0, r0
	strh r0, [r3, 0x2E]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _08076A70
	strh r2, [r1, 0x24]
	strh r2, [r1, 0x26]
	adds r0, r3, 0
	bl DestroySprite
_08076A70:
	pop {r0}
	bx r0
	.pool
	thumb_func_end oamc_804BEB4

	thumb_func_start sub_8076A78
sub_8076A78: @ 8076A78
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0832C400
	lsls r6, r4, 3
	adds r5, r6, r0
	ldrh r0, [r5, 0x6]
	bl GetSpriteTileStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _08076AA0
	adds r0, r5, 0
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0832C460
	adds r0, r6, r0
	bl LoadCompressedObjectPaletteUsingHeap
_08076AA0:
	cmp r4, 0x6
	beq _08076ACC
	cmp r4, 0x6
	blt _08076AB0
	cmp r4, 0xB
	bgt _08076AB0
	cmp r4, 0xA
	bge _08076ACC
_08076AB0:
	ldr r1, =gUnknown_0832C400
	lsls r0, r4, 3
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	ldr r0, =gUnknown_08C02300
	lsrs r1, 11
	ldr r2, =0x06010100
	adds r1, r2
	bl LZDecompressVram
_08076ACC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076A78

	thumb_func_start sub_8076AE8
sub_8076AE8: @ 8076AE8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	ldr r0, =gUnknown_0832C400
	lsrs r4, 21
	adds r0, r4, r0
	ldrh r0, [r0, 0x6]
	bl FreeSpriteTilesByTag
	ldr r0, =gUnknown_0832C460
	adds r4, r0
	ldrh r0, [r4, 0x4]
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8076AE8

	thumb_func_start sub_8076B14
sub_8076B14: @ 8076B14
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08076B40
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08076B4E
	.pool
_08076B40:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08076B4E:
	adds r0, r1
	movs r1, 0x26
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8076B14

	.align 2, 0 @ Don't pad with nop.
