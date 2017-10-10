	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start ai_identify_item_effect
ai_identify_item_effect: @ 8063E84
	push {r4,lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bne _08063E94
	movs r0, 0x1
	b _08063EDA
_08063E94:
	ldrb r1, [r2, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08063EA2
	movs r0, 0x2
	b _08063EDA
_08063EA2:
	ldrb r4, [r2, 0x3]
	movs r3, 0x3F
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _08063EB2
	movs r0, 0x3
	b _08063EDA
_08063EB2:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08063EC8
	ldrb r0, [r2, 0x1]
	cmp r0, 0
	bne _08063EC8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _08063ECC
_08063EC8:
	movs r0, 0x4
	b _08063EDA
_08063ECC:
	movs r0, 0x80
	ands r0, r4
	cmp r0, 0
	bne _08063ED8
	movs r0, 0x6
	b _08063EDA
_08063ED8:
	movs r0, 0x5
_08063EDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ai_identify_item_effect

	thumb_func_start ShouldUseItem
ShouldUseItem: @ 8063EE0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r10, r0
	movs r7, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08063F12
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08063F12
	b _0806437C
_08063F12:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r5, =gEnemyParty
	cmp r0, 0
	bne _08063F24
	ldr r5, =gPlayerParty
_08063F24:
	movs r1, 0
	mov r8, r1
_08063F28:
	movs r0, 0x64
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r4, r5, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08063F64
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08063F64
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08063F64
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_08063F64:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x5
	ble _08063F28
	movs r2, 0
	mov r8, r2
_08063F72:
	ldr r1, =gBattleResources
	mov r0, r8
	cmp r0, 0
	beq _08063F8E
	ldr r0, [r1]
	ldr r0, [r0, 0x18]
	adds r0, 0x50
	ldrb r0, [r0]
	mov r2, r8
	subs r0, r2
	adds r0, 0x1
	cmp r10, r0
	ble _08063F8E
	b _08064370
_08063F8E:
	ldr r0, [r1]
	ldr r0, [r0, 0x18]
	mov r2, r8
	lsls r1, r2, 1
	adds r0, 0x48
	adds r0, r1
	ldrh r0, [r0]
	mov r9, r0
	str r1, [sp]
	cmp r0, 0
	bne _08063FA6
	b _08064370
_08063FA6:
	ldr r1, =gItemEffectTable
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08063FB6
	b _08064370
_08063FB6:
	mov r0, r9
	cmp r0, 0xAF
	bne _08063FE8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r5, r0, r1
	b _08063FEA
	.pool
_08063FE8:
	adds r5, r1, 0
_08063FEA:
	mov r2, r9
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, r5, 0
	bl ai_identify_item_effect
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsrs r1, 1
	ldr r3, =gBattleStruct
	ldr r2, [r3]
	adds r1, r2
	adds r1, 0xC4
	strb r0, [r1]
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r0, 0x5
	bls _0806401A
	b _08064324
_0806401A:
	lsls r0, 2
	ldr r1, =_08064030
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08064030:
	.4byte _08064048
	.4byte _08064074
	.4byte _080640BC
	.4byte _08064214
	.4byte _080642F4
	.4byte _0806437C
_08064048:
	ldr r2, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x2C]
	ldrh r0, [r0, 0x28]
	lsrs r1, 2
	cmp r0, r1
	bcc _08064060
	b _08064324
_08064060:
	cmp r0, 0
	bne _08064066
	b _08064324
_08064066:
	movs r7, 0x1
	b _08064328
	.pool
_08064074:
	mov r0, r9
	movs r1, 0x4
	movs r2, 0x4
	bl GetItemEffectParamOffset
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08064088
	b _08064324
_08064088:
	ldr r2, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	ldrh r2, [r1, 0x28]
	cmp r2, 0
	bne _0806409C
	b _08064324
_0806409C:
	ldrh r3, [r1, 0x2C]
	lsrs r0, r3, 2
	cmp r2, r0
	bcc _08064066
	adds r0, r2, 0
	subs r0, r3, r0
	adds r1, r5, r4
	ldrb r1, [r1]
	cmp r0, r1
	bgt _080640B2
	b _08064324
_080640B2:
	b _08064066
	.pool
_080640BC:
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsrs r0, 1
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r0, r1
	adds r0, 0xC6
	movs r1, 0
	strb r1, [r0]
	ldrb r1, [r5, 0x3]
	movs r6, 0x20
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08064100
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08064100
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_08064100:
	ldrb r1, [r5, 0x3]
	movs r6, 0x10
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0806413A
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806412A
	movs r0, 0x80
	ands r1, r0
	cmp r1, 0
	beq _0806413A
_0806412A:
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806413A:
	ldrb r1, [r5, 0x3]
	movs r6, 0x8
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806416C
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0806416C
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806416C:
	ldrb r1, [r5, 0x3]
	movs r6, 0x4
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806419E
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0806419E
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806419E:
	ldrb r1, [r5, 0x3]
	movs r6, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080641D0
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080641D0
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_080641D0:
	ldrb r1, [r5, 0x3]
	movs r4, 0x1
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080641DE
	b _08064324
_080641DE:
	ldr r1, =gBattleMons
	ldrb r3, [r3]
	movs r0, 0x58
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _080641F6
	b _08064324
_080641F6:
	lsrs r1, r3, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	b _08064066
	.pool
_08064214:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gDisableStructs
	ldrb r2, [r4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	beq _08064324
	ldrb r1, [r5]
	movs r6, 0xF
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08064254
	lsrs r2, 1
	ldr r0, [r3]
	adds r2, r0
	adds r2, 0xC6
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08064254:
	ldrb r1, [r5, 0x1]
	movs r7, 0xF0
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08064272
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_08064272:
	ldrb r1, [r5, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0806428E
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0806428E:
	ldrb r1, [r5, 0x2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080642AA
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_080642AA:
	ldrb r1, [r5, 0x2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080642C6
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
_080642C6:
	ldrb r1, [r5]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _080642D2
	b _08064066
_080642D2:
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	b _08064066
	.pool
_080642F4:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gDisableStructs
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	beq _08064324
	ldr r0, =gSideTimers
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08064324
	b _08064066
_08064324:
	cmp r7, 0
	beq _08064370
_08064328:
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl EmitCmd_x21
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsrs r0, 1
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC0
	mov r1, r9
	strb r1, [r0]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	adds r0, 0x48
	ldr r2, [sp]
	adds r0, r2
	movs r1, 0
	strh r1, [r0]
	adds r0, r7, 0
	b _0806437E
	.pool
_08064370:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	bgt _0806437C
	b _08063F72
_0806437C:
	movs r0, 0
_0806437E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ShouldUseItem

	.align 2, 0 @ Don't pad with nop.
