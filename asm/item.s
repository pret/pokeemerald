	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start CheckBagHasSpace
CheckBagHasSpace: @ 80D6800
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r5, r1, 16
	bl ItemId_GetPocket
	lsls r0, 24
	cmp r0, 0
	beq _080D6906
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080D6838
	ldr r0, =0x00004004
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D684C
_080D6838:
	mov r0, r8
	adds r1, r5, 0
	bl CheckPyramidBagHasSpace
	lsls r0, 24
	lsrs r0, 24
	b _080D6916
	.pool
_080D684C:
	mov r0, r8
	bl ItemId_GetPocket
	subs r0, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r7, =0x000003e7
	cmp r2, 0x3
	beq _080D6860
	movs r7, 0x63
_080D6860:
	movs r6, 0
	ldr r1, =gBagPockets
	lsls r4, r2, 3
	adds r0, r4, r1
	mov r9, r4
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcs _080D68BC
	subs r0, r2, 0x2
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_080D6878:
	adds r0, r4, r1
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r8
	bne _080D68AC
	adds r0, r1, 0x2
	str r2, [sp]
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r1, r5
	ldr r2, [sp]
	cmp r0, r7
	ble _080D6914
	mov r0, r10
	cmp r0, 0x1
	bls _080D6906
	subs r0, r7, r1
	subs r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _080D6914
_080D68AC:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gBagPockets
	adds r0, r4, r1
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcc _080D6878
_080D68BC:
	cmp r5, 0
	beq _080D6914
	movs r6, 0
	ldr r3, =gBagPockets
	mov r1, r9
	adds r0, r1, r3
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcs _080D6902
	adds r4, r3, 0
	subs r0, r2, 0x2
	lsls r0, 24
	lsrs r2, r0, 24
_080D68D6:
	adds r0, r1, r4
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080D68F2
	cmp r5, r7
	bls _080D6914
	cmp r2, 0x1
	bls _080D6906
	subs r0, r5, r7
	lsls r0, 16
	lsrs r5, r0, 16
_080D68F2:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r9
	adds r0, r1, r3
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcc _080D68D6
_080D6902:
	cmp r5, 0
	beq _080D6914
_080D6906:
	movs r0, 0
	b _080D6916
	.pool
_080D6914:
	movs r0, 0x1
_080D6916:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckBagHasSpace

	thumb_func_start AddBagItem
@ int AddBagItem(int item_id, int quantity)
AddBagItem: @ 80D6928
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r1, 16
	lsrs r5, r1, 16
	bl ItemId_GetPocket
	lsls r0, 24
	cmp r0, 0
	bne _080D694C
	movs r0, 0
	b _080D6A92
_080D694C:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080D6964
	ldr r0, =0x00004004
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D6978
_080D6964:
	mov r0, r9
	adds r1, r5, 0
	bl AddPyramidBagItem
	lsls r0, 24
	lsrs r0, 24
	b _080D6A92
	.pool
_080D6978:
	mov r0, r9
	bl ItemId_GetPocket
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, r0, 3
	ldr r0, =gBagPockets
	adds r7, r1, r0
	ldrb r0, [r7, 0x4]
	lsls r0, 2
	bl AllocZeroed
	mov r8, r0
	ldr r1, [r7]
	ldrb r2, [r7, 0x4]
	lsls r2, 2
	bl memcpy
	ldr r2, =0x000003e7
	mov r0, r10
	cmp r0, 0x3
	beq _080D69AA
	movs r2, 0x63
_080D69AA:
	movs r6, 0
	ldrb r0, [r7, 0x4]
	cmp r6, r0
	bcs _080D6A06
	mov r0, r10
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
_080D69BC:
	lsls r0, r6, 2
	mov r3, r8
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, r9
	bne _080D69FA
	adds r4, r1, 0x2
	adds r0, r4, 0
	str r2, [sp, 0x4]
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, r5
	ldr r2, [sp, 0x4]
	cmp r1, r2
	ble _080D6A68
	ldr r1, [sp]
	cmp r1, 0x1
	bls _080D6A74
	subs r0, r2, r0
	subs r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl SetBagItemQuantity
	ldr r2, [sp, 0x4]
	cmp r5, 0
	beq _080D6A7E
_080D69FA:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r7, 0x4]
	cmp r6, r0
	bcc _080D69BC
_080D6A06:
	cmp r5, 0
	beq _080D6A7E
	movs r6, 0
	cmp r6, r0
	bcs _080D6A62
	mov r0, r10
	subs r0, 0x2
	lsls r0, 24
	lsrs r4, r0, 24
_080D6A18:
	lsls r0, r6, 2
	mov r3, r8
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, 0
	bne _080D6A56
	mov r0, r9
	strh r0, [r1]
	cmp r5, r2
	bhi _080D6A40
	adds r0, r1, 0x2
	adds r1, r5, 0
	bl SetBagItemQuantity
	b _080D6A7E
	.pool
_080D6A40:
	cmp r4, 0x1
	bls _080D6A74
	subs r0, r5, r2
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r1, 0x2
	adds r1, r2, 0
	str r2, [sp, 0x4]
	bl SetBagItemQuantity
	ldr r2, [sp, 0x4]
_080D6A56:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r7, 0x4]
	cmp r6, r1
	bcc _080D6A18
_080D6A62:
	cmp r5, 0
	beq _080D6A7E
	b _080D6A74
_080D6A68:
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl SetBagItemQuantity
	b _080D6A7E
_080D6A74:
	mov r0, r8
	bl Free
	movs r0, 0
	b _080D6A92
_080D6A7E:
	ldr r0, [r7]
	ldrb r2, [r7, 0x4]
	lsls r2, 2
	mov r1, r8
	bl memcpy
	mov r0, r8
	bl Free
	movs r0, 0x1
_080D6A92:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddBagItem

	thumb_func_start RemoveBagItem
@ pokescrcmd
RemoveBagItem: @ 80D6AA4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r7, r1, 16
	movs r4, 0
	bl ItemId_GetPocket
	lsls r0, 24
	cmp r0, 0
	beq _080D6B38
	mov r0, r8
	cmp r0, 0
	beq _080D6B38
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _080D6AE0
	ldr r0, =0x00004004
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D6AF4
_080D6AE0:
	mov r0, r8
	adds r1, r7, 0
	bl RemovePyramidBagItem
	lsls r0, 24
	lsrs r0, 24
	b _080D6C5A
	.pool
_080D6AF4:
	mov r0, r8
	bl ItemId_GetPocket
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, r0, 3
	ldr r0, =gBagPockets
	adds r5, r1, r0
	movs r6, 0
	ldrb r2, [r5, 0x4]
	cmp r6, r2
	bcs _080D6B34
_080D6B10:
	ldr r0, [r5]
	lsls r1, r6, 2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, r8
	bne _080D6B28
	adds r0, r1, 0x2
	bl GetBagItemQuantity
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
_080D6B28:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r5, 0x4]
	cmp r6, r0
	bcc _080D6B10
_080D6B34:
	cmp r4, r7
	bcs _080D6B40
_080D6B38:
	movs r0, 0
	b _080D6C5A
	.pool
_080D6B40:
	bl CurrentMapIsSecretBase
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D6B70
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	ldr r0, =0x000040ed
	mov r1, r8
	bl VarSet
_080D6B70:
	mov r0, r9
	bl sub_81ABB2C
	lsls r0, 24
	lsrs r1, r0, 24
	ldrb r0, [r5, 0x4]
	cmp r0, r1
	bls _080D6BE6
	ldr r0, [r5]
	lsls r1, 2
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r4, r1, 0
	cmp r0, r8
	bne _080D6BE6
	adds r0, r2, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r7
	bcc _080D6BB8
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	subs r1, r7
	lsls r1, 16
	lsrs r1, 16
	bl SetBagItemQuantity
	movs r7, 0
	b _080D6BCA
	.pool
_080D6BB8:
	subs r0, r7, r1
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	movs r1, 0
	bl SetBagItemQuantity
_080D6BCA:
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _080D6BE2
	ldr r0, [r5]
	adds r0, r4, r0
	strh r2, [r0]
_080D6BE2:
	cmp r7, 0
	beq _080D6C58
_080D6BE6:
	movs r6, 0
	ldrb r0, [r5, 0x4]
	cmp r6, r0
	bcs _080D6C58
_080D6BEE:
	ldr r0, [r5]
	lsls r1, r6, 2
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r4, r1, 0
	cmp r0, r8
	bne _080D6C4C
	adds r0, r2, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r7
	bcc _080D6C1E
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	subs r1, r7
	lsls r1, 16
	lsrs r1, 16
	bl SetBagItemQuantity
	movs r7, 0
	b _080D6C30
_080D6C1E:
	subs r0, r7, r1
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	movs r1, 0
	bl SetBagItemQuantity
_080D6C30:
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _080D6C48
	ldr r0, [r5]
	adds r0, r4, r0
	strh r2, [r0]
_080D6C48:
	cmp r7, 0
	beq _080D6C58
_080D6C4C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r2, [r5, 0x4]
	cmp r6, r2
	bcc _080D6BEE
_080D6C58:
	movs r0, 0x1
_080D6C5A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end RemoveBagItem

	thumb_func_start GetPocketByItemId
GetPocketByItemId: @ 80D6C68
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetPocketByItemId

	thumb_func_start ClearItemSlots
ClearItemSlots: @ 80D6C7C
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	movs r4, 0
	lsrs r1, 24
	cmp r4, r1
	bcs _080D6CA6
	adds r5, r1, 0
	movs r7, 0
_080D6C8E:
	lsls r0, r4, 2
	adds r0, r6
	strh r7, [r0]
	adds r0, 0x2
	movs r1, 0
	bl SetBagItemQuantity
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r5
	bcc _080D6C8E
_080D6CA6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ClearItemSlots

	thumb_func_start sub_80D6CAC
sub_80D6CAC: @ 80D6CAC
	push {lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r3, 0x93
	lsls r3, 3
_080D6CB8:
	lsls r0, r1, 24
	asrs r1, r0, 24
	lsls r0, r1, 2
	adds r0, r2, r0
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, 0
	bne _080D6CD0
	adds r0, r1, 0
	b _080D6CE0
	.pool
_080D6CD0:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	asrs r0, 24
	cmp r0, 0x31
	ble _080D6CB8
	movs r0, 0x1
	negs r0, r0
_080D6CE0:
	pop {r1}
	bx r1
	thumb_func_end sub_80D6CAC

	thumb_func_start sub_80D6CE4
sub_80D6CE4: @ 80D6CE4
	push {r4,lr}
	movs r2, 0
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r4, 0x93
	lsls r4, 3
_080D6CF2:
	lsls r0, r1, 2
	adds r0, r3, r0
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0
	beq _080D6D04
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080D6D04:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x31
	bls _080D6CF2
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D6CE4

	thumb_func_start CheckPCHasItem
CheckPCHasItem: @ 80D6D1C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
_080D6D28:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	lsls r1, r4, 2
	adds r0, r2, r1
	movs r3, 0x93
	lsls r3, 3
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r6
	bne _080D6D5C
	adds r0, r1, r2
	ldr r1, =0x0000049a
	adds r0, r1
	bl GetBagItemId
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _080D6D5C
	movs r0, 0x1
	b _080D6D68
	.pool
_080D6D5C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x31
	bls _080D6D28
	movs r0, 0
_080D6D68:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CheckPCHasItem

	thumb_func_start AddPCItem
AddPCItem: @ 80D6D70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r0, 0xC8
	bl AllocZeroed
	adds r7, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	adds r0, r7, 0
	movs r2, 0xC8
	bl memcpy
	movs r6, 0
_080D6D9C:
	lsls r0, r6, 2
	adds r1, r0, r7
	ldrh r0, [r1]
	cmp r0, r8
	bne _080D6DD0
	adds r4, r1, 0x2
	adds r0, r4, 0
	bl GetBagItemId
	lsls r0, 16
	lsrs r2, r0, 16
	adds r1, r2, r5
	ldr r3, =0x000003e7
	cmp r1, r3
	ble _080D6E04
	ldr r1, =0x0000fc19
	adds r0, r5, r1
	adds r0, r2, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	adds r1, r3, 0
	bl SetBagItemId
	cmp r5, 0
	beq _080D6E20
_080D6DD0:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x31
	bls _080D6D9C
	cmp r5, 0
	beq _080D6E20
	bl sub_80D6CAC
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080D6E10
	adds r0, r7, 0
	bl Free
	movs r0, 0
	b _080D6E3A
	.pool
_080D6E04:
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl SetBagItemId
	b _080D6E20
_080D6E10:
	lsls r0, r1, 2
	adds r0, r7
	mov r1, r8
	strh r1, [r0]
	adds r0, 0x2
	adds r1, r5, 0
	bl SetBagItemId
_080D6E20:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0xC8
	bl memcpy
	adds r0, r7, 0
	bl Free
	movs r0, 0x1
_080D6E3A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddPCItem

	thumb_func_start sub_80D6E48
sub_80D6E48: @ 80D6E48
	push {lr}
	lsls r0, 24
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	lsrs r0, 22
	adds r3, r2, r0
	ldr r0, =0x0000049a
	adds r2, r3, r0
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _080D6E76
	movs r2, 0x93
	lsls r2, 3
	adds r0, r3, r2
	strh r1, [r0]
	bl sub_80D6E84
_080D6E76:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D6E48

	thumb_func_start sub_80D6E84
sub_80D6E84: @ 80D6E84
	push {r4-r7,lr}
	movs r2, 0
_080D6E88:
	adds r1, r2, 0x1
	lsls r0, r1, 16
	lsrs r4, r0, 16
	adds r6, r1, 0
	cmp r4, 0x31
	bhi _080D6ECA
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	lsls r5, r2, 2
	movs r7, 0x93
	lsls r7, 3
_080D6E9E:
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, r5
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, 0
	bne _080D6EC0
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	adds r2, r1, r5
	ldr r3, [r2]
	lsls r0, r4, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_080D6EC0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x31
	bls _080D6E9E
_080D6ECA:
	lsls r0, r6, 16
	lsrs r2, r0, 16
	cmp r2, 0x30
	bls _080D6E88
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D6E84

	thumb_func_start sub_80D6EDC
sub_80D6EDC: @ 80D6EDC
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00000496
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, =0x00000103
	cmp r2, r3
	beq _080D6F04
	movs r0, 0x88
	lsls r0, 1
	cmp r2, r0
	beq _080D6F0C
	b _080D6F0E
	.pool
_080D6F04:
	movs r0, 0x88
	lsls r0, 1
	strh r0, [r1]
	b _080D6F0E
_080D6F0C:
	strh r3, [r1]
_080D6F0E:
	pop {r0}
	bx r0
	thumb_func_end sub_80D6EDC

	thumb_func_start BagGetItemIdByPocketPosition
@ int BagGetItemIdByPocketPosition(int pocket_id_plus_1, int item_index_in_pocket)
BagGetItemIdByPocketPosition: @ 80D6F14
	lsls r0, 24
	lsls r1, 16
	ldr r2, =gBagPockets
	lsrs r0, 21
	subs r0, 0x8
	adds r0, r2
	ldr r0, [r0]
	lsrs r1, 14
	adds r1, r0
	ldrh r0, [r1]
	bx lr
	.pool
	thumb_func_end BagGetItemIdByPocketPosition

	thumb_func_start BagGetQuantityByPocketPosition
@ int BagGetQuantityByPocketPosition(int pocket_id_plus_1, int item_index_in_pocket)
BagGetQuantityByPocketPosition: @ 80D6F30
	push {lr}
	lsls r0, 24
	lsls r1, 16
	ldr r2, =gBagPockets
	lsrs r0, 21
	subs r0, 0x8
	adds r0, r2
	lsrs r1, 14
	ldr r0, [r0]
	adds r0, r1
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end BagGetQuantityByPocketPosition

	thumb_func_start swap32
swap32: @ 80D6F58
	ldr r3, [r0]
	ldr r2, [r1]
	str r2, [r0]
	str r3, [r1]
	bx lr
	thumb_func_end swap32

	thumb_func_start sub_80D6F64
sub_80D6F64: @ 80D6F64
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r3, 0
	b _080D6FA6
_080D6F6C:
	adds r1, r3, 0x1
	lsls r0, r1, 16
	lsrs r4, r0, 16
	adds r7, r1, 0
	cmp r4, r2
	bcs _080D6FA2
	lsls r5, r3, 2
_080D6F7A:
	ldr r0, [r6]
	adds r0, r5
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	cmp r0, 0
	bne _080D6F96
	ldr r1, [r6]
	adds r0, r1, r5
	lsls r2, r4, 2
	adds r1, r2
	bl swap32
_080D6F96:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r0, [r6, 0x4]
	cmp r4, r0
	bcc _080D6F7A
_080D6FA2:
	lsls r0, r7, 16
	lsrs r3, r0, 16
_080D6FA6:
	ldrb r2, [r6, 0x4]
	subs r0, r2, 0x1
	cmp r3, r0
	blt _080D6F6C
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D6F64

	thumb_func_start sub_80D6FB4
sub_80D6FB4: @ 80D6FB4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	movs r3, 0
	b _080D701A
_080D6FC0:
	adds r1, r3, 0x1
	lsls r0, r1, 16
	lsrs r5, r0, 16
	mov r8, r1
	cmp r5, r2
	bcs _080D7014
	lsls r7, r3, 2
_080D6FCE:
	ldr r0, [r6]
	adds r0, r7
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	lsls r4, r5, 2
	cmp r0, 0
	beq _080D6FFE
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x2
	bl GetBagItemQuantity
	lsls r0, 16
	cmp r0, 0
	beq _080D7008
	ldr r0, [r6]
	adds r1, r7, r0
	adds r0, r4, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bls _080D7008
_080D6FFE:
	ldr r1, [r6]
	adds r0, r1, r7
	adds r1, r4
	bl swap32
_080D7008:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r0, [r6, 0x4]
	cmp r5, r0
	bcc _080D6FCE
_080D7014:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r3, r0, 16
_080D701A:
	ldrb r2, [r6, 0x4]
	subs r0, r2, 0x1
	cmp r3, r0
	blt _080D6FC0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D6FB4

	thumb_func_start sub_80D702C
sub_80D702C: @ 80D702C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r3, r2, 0
	cmp r1, r3
	beq _080D708C
	lsls r0, r1, 2
	adds r0, r4
	ldr r6, [r0]
	cmp r3, r1
	bls _080D7064
	subs r3, 0x1
	lsls r1, 16
	lsls r0, r3, 16
	asrs r2, r0, 16
	cmp r1, r0
	bge _080D7086
	adds r5, r2, 0
_080D704E:
	asrs r2, r1, 16
	lsls r0, r2, 2
	adds r0, r4
	ldr r1, [r0, 0x4]
	str r1, [r0]
	adds r2, 0x1
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, r5
	blt _080D704E
	b _080D7086
_080D7064:
	lsls r1, 16
	lsls r0, r3, 16
	asrs r2, r0, 16
	cmp r1, r0
	ble _080D7086
	adds r5, r2, 0
_080D7070:
	asrs r2, r1, 16
	lsls r1, r2, 2
	adds r1, r4
	subs r0, r1, 0x4
	ldr r0, [r0]
	str r0, [r1]
	subs r2, 0x1
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, r5
	bgt _080D7070
_080D7086:
	lsls r0, r3, 2
	adds r0, r4
	str r6, [r0]
_080D708C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D702C

	thumb_func_start ClearBag
ClearBag: @ 80D7094
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gBagPockets
_080D709A:
	lsls r1, r4, 3
	adds r1, r5
	ldr r0, [r1]
	ldrb r1, [r1, 0x4]
	bl ClearItemSlots
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _080D709A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearBag

	thumb_func_start CountTotalItemQuantityInBag
@ u16 CountTotalItemQuantityInBag(u16 itemId)
CountTotalItemQuantityInBag: @ 80D70BC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r7, 0
	adds r0, r6, 0
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 21
	ldr r1, =gUnknown_02039DD0
	adds r5, r0, r1
	movs r4, 0
	ldrb r0, [r5, 0x4]
	cmp r7, r0
	bcs _080D70FE
_080D70DA:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, r6
	bne _080D70F2
	adds r0, r1, 0x2
	bl GetBagItemQuantity
	adds r0, r7, r0
	lsls r0, 16
	lsrs r7, r0, 16
_080D70F2:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r0, [r5, 0x4]
	cmp r4, r0
	bcc _080D70DA
_080D70FE:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CountTotalItemQuantityInBag

	thumb_func_start CheckPyramidBagHasItem
CheckPyramidBagHasItem: @ 80D710C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r2, r3, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	movs r1, 0
_080D7140:
	lsls r0, r1, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r5
	bne _080D7170
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, r4
	bcs _080D715C
	subs r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _080D7170
_080D715C:
	movs r0, 0x1
	b _080D717C
	.pool
_080D7170:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _080D7140
	movs r0, 0
_080D717C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CheckPyramidBagHasItem

	thumb_func_start CheckPyramidBagHasSpace
CheckPyramidBagHasSpace: @ 80D7184
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r2, r3, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	movs r1, 0
_080D71B8:
	lsls r0, r1, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r5
	beq _080D71C6
	cmp r0, 0
	bne _080D71F0
_080D71C6:
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, r4
	cmp r0, 0x63
	ble _080D71DA
	subs r0, 0x63
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _080D71F0
_080D71DA:
	movs r0, 0x1
	b _080D71FC
	.pool
_080D71F0:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _080D71B8
	movs r0, 0
_080D71FC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CheckPyramidBagHasSpace

	thumb_func_start AddPyramidBagItem
AddPyramidBagItem: @ 80D7204
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r0, r3
	mov r9, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	mov r8, r3
	movs r0, 0x14
	bl Alloc
	adds r5, r0, 0
	movs r0, 0xA
	bl Alloc
	adds r6, r0, 0
	adds r0, r5, 0
	mov r1, r9
	movs r2, 0x14
	bl memcpy
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0xA
	bl memcpy
	movs r2, 0
_080D7266:
	lsls r0, r2, 1
	adds r0, r5
	ldrh r0, [r0]
	cmp r0, r7
	bne _080D72AA
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, 0x62
	bhi _080D72AA
	adds r0, r4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x63
	bls _080D72A4
	ldrb r0, [r1]
	subs r0, 0x63
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x63
	strb r0, [r1]
	b _080D72A6
	.pool
_080D72A4:
	movs r4, 0
_080D72A6:
	cmp r4, 0
	beq _080D7304
_080D72AA:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bls _080D7266
	cmp r4, 0
	beq _080D7304
	movs r2, 0
_080D72BA:
	lsls r0, r2, 1
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, 0
	bne _080D72E6
	strh r7, [r1]
	adds r1, r6, r2
	strb r4, [r1]
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r0, 0x63
	bls _080D72E0
	ldrb r0, [r1]
	subs r0, 0x63
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x63
	strb r0, [r1]
	b _080D72E2
_080D72E0:
	movs r4, 0
_080D72E2:
	cmp r4, 0
	beq _080D7304
_080D72E6:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bls _080D72BA
	cmp r4, 0
	beq _080D7304
	adds r0, r5, 0
	bl Free
	adds r0, r6, 0
	bl Free
	movs r0, 0
	b _080D7326
_080D7304:
	mov r0, r9
	adds r1, r5, 0
	movs r2, 0x14
	bl memcpy
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0xA
	bl memcpy
	adds r0, r5, 0
	bl Free
	adds r0, r6, 0
	bl Free
	movs r0, 0x1
_080D7326:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddPyramidBagItem

	thumb_func_start RemovePyramidBagItem
RemovePyramidBagItem: @ 80D7334
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r0, r3
	mov r8, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r7, r3, r0
	ldr r1, =gUnknown_0203CF30
	ldrh r0, [r1, 0x8]
	ldrh r1, [r1, 0x6]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r0, r2, 1
	mov r1, r8
	adds r3, r0, r1
	ldrh r0, [r3]
	cmp r0, r9
	bne _080D73B4
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, r4
	bcc _080D73B4
	subs r0, r4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080D744C
	strh r0, [r3]
	b _080D744C
	.pool
_080D73B4:
	movs r0, 0x14
	bl Alloc
	adds r5, r0, 0
	movs r0, 0xA
	bl Alloc
	adds r6, r0, 0
	adds r0, r5, 0
	mov r1, r8
	movs r2, 0x14
	bl memcpy
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0xA
	bl memcpy
	movs r2, 0
_080D73DA:
	lsls r0, r2, 1
	adds r3, r0, r5
	ldrh r0, [r3]
	cmp r0, r9
	bne _080D740E
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, r4
	bcc _080D73FC
	subs r0, r4
	strb r0, [r1]
	movs r4, 0
	lsls r0, 24
	cmp r0, 0
	bne _080D740A
	strh r4, [r3]
	b _080D740A
_080D73FC:
	subs r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0
	strb r0, [r1]
	movs r0, 0
	strh r0, [r3]
_080D740A:
	cmp r4, 0
	beq _080D742C
_080D740E:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bls _080D73DA
	cmp r4, 0
	beq _080D742C
	adds r0, r5, 0
	bl Free
	adds r0, r6, 0
	bl Free
	movs r0, 0
	b _080D744E
_080D742C:
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x14
	bl memcpy
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0xA
	bl memcpy
	adds r0, r5, 0
	bl Free
	adds r0, r6, 0
	bl Free
_080D744C:
	movs r0, 0x1
_080D744E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end RemovePyramidBagItem

	thumb_func_start SanitizeItemId
SanitizeItemId: @ 80D745C
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xBC
	lsls r0, 1
	cmp r1, r0
	bhi _080D746E
	adds r0, r1, 0
	b _080D7470
_080D746E:
	movs r0, 0
_080D7470:
	pop {r1}
	bx r1
	thumb_func_end SanitizeItemId

	thumb_func_start ItemId_GetItem
@ item *ItemId_GetItem(s16 itemId)
ItemId_GetItem: @ 80D7474
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	ldr r1, =gItems
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetItem

	thumb_func_start itemid_get_number
itemid_get_number: @ 80D7494
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrh r0, [r0, 0xE]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end itemid_get_number

	thumb_func_start itemid_get_market_price
itemid_get_market_price: @ 80D74B8
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrh r0, [r0, 0x10]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end itemid_get_market_price

	thumb_func_start ItemId_GetHoldEffect
ItemId_GetHoldEffect: @ 80D74DC
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x12]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetHoldEffect

	thumb_func_start ItemId_GetHoldEffectParam
ItemId_GetHoldEffectParam: @ 80D7500
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x13]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetHoldEffectParam

	thumb_func_start ItemId_GetDescription
ItemId_GetDescription: @ 80D7524
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r4, 0x14
	adds r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetDescription

	thumb_func_start itemid_is_unique
itemid_is_unique: @ 80D7548
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x18]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end itemid_is_unique

	thumb_func_start itemid_get_x19
itemid_get_x19: @ 80D756C
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x19]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end itemid_get_x19

	thumb_func_start ItemId_GetPocket
ItemId_GetPocket: @ 80D7590
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x1A]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetPocket

	thumb_func_start ItemId_GetType
ItemId_GetType: @ 80D75B4
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	ldrb r0, [r0, 0x1B]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetType

	thumb_func_start ItemId_GetFieldFunc
ItemId_GetFieldFunc: @ 80D75D8
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r4, 0x1C
	adds r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetFieldFunc

	thumb_func_start ItemId_GetBattleUsage
ItemId_GetBattleUsage: @ 80D75FC
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	adds r0, 0x20
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetBattleUsage

	thumb_func_start ItemId_GetBattleFunc
ItemId_GetBattleFunc: @ 80D7620
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r4, 0x24
	adds r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetBattleFunc

	thumb_func_start ItemId_GetSecondaryId
ItemId_GetSecondaryId: @ 80D7644
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gItems
	bl SanitizeItemId
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x2C
	muls r0, r1
	adds r0, r4
	adds r0, 0x28
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ItemId_GetSecondaryId

	.align 2, 0 @ Don't pad with nop.
