	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AllocateBattleSpritesData
AllocateBattleSpritesData: @ 805D118
	push {r4,lr}
	ldr r4, =gBattleSpritesDataPtr
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x30
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x8]
	movs r0, 0x50
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AllocateBattleSpritesData

	thumb_func_start FreeBattleSpritesData
FreeBattleSpritesData: @ 805D158
	push {r4,r5,lr}
	ldr r5, =gBattleSpritesDataPtr
	ldr r0, [r5]
	cmp r0, 0
	beq _0805D192
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x8]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x8]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	str r4, [r0]
	bl Free
	str r4, [r5]
_0805D192:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeBattleSpritesData

	thumb_func_start sub_805D19C
sub_805D19C: @ 805D19C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 9
	ldr r1, =gBattleBufferA + 4
	adds r2, r1
	mov r10, r2
	movs r1, 0
	movs r2, 0xFF
	bl CheckMoveLimitations
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x92
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r4, r0, 31
	movs r0, 0x2
	ands r4, r0
	adds r6, r4, 0
	adds r5, r4, 0x2
	b _0805D20E
	.pool
_0805D20C:
	adds r4, 0x1
_0805D20E:
	cmp r4, r5
	bge _0805D234
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gBattleMons + 0x48
	adds r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4, r0
	ldr r2, =gUnknown_0831C494
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, r7
	ble _0805D20C
_0805D234:
	subs r7, r4, r6
	cmp r4, r5
	bne _0805D23C
	movs r7, 0x2
_0805D23C:
	movs r6, 0
	movs r4, 0
	mov r1, r10
	ldrh r0, [r1]
	cmp r0, 0
	beq _0805D27C
	mov r5, r10
_0805D24A:
	ldrh r0, [r5]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r7, r0
	bne _0805D26E
	mov r0, r10
	adds r0, 0x8
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805D26E
	ldr r0, =gBitTable
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	orrs r6, r0
_0805D26E:
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0805D27C
	ldrh r0, [r5]
	cmp r0, 0
	bne _0805D24A
_0805D27C:
	cmp r6, 0
	beq _0805D2AC
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r1, 0x92
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, 0x92
	lsls r0, r6, 4
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	lsls r0, r6, 24
	lsrs r0, 24
	bl BattleAI_SetupAIData
	bl BattleAI_ChooseMoveOrAction
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0805D2AC:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D2B6
	b _0805D40C
_0805D2B6:
	mov r2, r8
	cmp r2, 0xF
	bne _0805D2BE
	b _0805D3EA
_0805D2BE:
	movs r5, 0
	movs r6, 0
	ldr r7, =gBitTable
	mov r4, r10
_0805D2C6:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	cmp r0, 0
	bne _0805D2DE
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D2DE
	adds r5, 0x1
_0805D2DE:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805D2F8
	ldr r0, [r7]
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	bne _0805D2F8
	adds r5, 0x10
_0805D2F8:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0805D316
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D316
	movs r2, 0x80
	lsls r2, 1
	adds r5, r2
_0805D316:
	adds r7, 0x4
	adds r4, 0x2
	ldr r0, =gBitTable
	adds r0, 0xC
	cmp r7, r0
	ble _0805D2C6
	movs r1, 0xF
	ands r1, r5
	cmp r1, 0x1
	ble _0805D32C
	adds r6, 0x1
_0805D32C:
	movs r0, 0xF0
	ands r0, r5
	cmp r0, 0x1F
	ble _0805D336
	adds r6, 0x1
_0805D336:
	ldr r2, =0x000001ff
	cmp r0, r2
	ble _0805D33E
	adds r6, 0x1
_0805D33E:
	cmp r6, 0x1
	bgt _0805D346
	cmp r6, 0
	bne _0805D388
_0805D346:
	ldr r5, =gBitTable
_0805D348:
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r4, r1, 16
	lsls r0, r4, 2
	adds r0, r5
	ldr r0, [r0]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D366
	mov r9, r4
_0805D366:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D348
	b _0805D3D4
	.pool
_0805D388:
	cmp r1, 0x1
	ble _0805D38E
	movs r6, 0
_0805D38E:
	cmp r0, 0x1F
	ble _0805D394
	movs r6, 0x1
_0805D394:
	cmp r0, r2
	ble _0805D39A
	movs r6, 0x2
_0805D39A:
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r4, r1, 16
	ldr r1, =gBitTable
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	bne _0805D3CC
	lsls r0, r4, 1
	add r0, r10
	ldrh r0, [r0]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _0805D3CC
	mov r9, r4
_0805D3CC:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D39A
_0805D3D4:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x31
	bls _0805D40C
_0805D3EA:
	ldr r2, =gProtectStructs
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r2
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	movs r0, 0
	b _0805D496
	.pool
_0805D40C:
	mov r1, r9
	lsls r0, r1, 1
	mov r2, r10
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0xAE
	bne _0805D434
	ldrb r0, [r2, 0x12]
	movs r5, 0
	cmp r0, 0x7
	beq _0805D442
	ldrb r1, [r2, 0x13]
	movs r0, 0x7
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r5, r0, 31
	movs r0, 0x10
	ands r5, r0
	b _0805D442
_0805D434:
	ldr r2, =gBattleMoves
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r5, [r0, 0x6]
_0805D442:
	movs r0, 0x10
	ands r0, r5
	cmp r0, 0
	beq _0805D45C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 8
	b _0805D48A
	.pool
_0805D45C:
	cmp r5, 0
	bne _0805D470
	bl sub_805D5F4
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	b _0805D490
_0805D470:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 16
_0805D48A:
	mov r1, r9
	orrs r1, r0
	mov r9, r1
_0805D490:
	mov r2, r9
	lsls r0, r2, 16
	lsrs r0, 16
_0805D496:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_805D19C

	thumb_func_start sub_805D4A8
sub_805D4A8: @ 805D4A8
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x6]
	adds r3, r1, 0
	cmp r0, 0x40
	bls _0805D4C2
	b _0805D5EE
_0805D4C2:
	lsls r0, 2
	ldr r1, =_0805D4D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805D4D4:
	.4byte _0805D5D8
	.4byte _0805D5E6
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EA
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5E6
_0805D5D8:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0805D5EE
_0805D5E6:
	movs r0, 0x2
	b _0805D5F0
_0805D5EA:
	movs r0, 0x1
	b _0805D5F0
_0805D5EE:
	movs r0, 0
_0805D5F0:
	pop {r1}
	bx r1
	thumb_func_end sub_805D4A8

	thumb_func_start sub_805D5F4
sub_805D5F4: @ 805D5F4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805D6FA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805D630
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x3
	b _0805D63E
	.pool
_0805D630:
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x2
_0805D63E:
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gBattleMons
	movs r2, 0x58
	mov r0, r8
	muls r0, r2
	adds r5, r0, r1
	adds r0, r7, 0
	muls r0, r2
	adds r6, r0, r1
	ldrh r0, [r5, 0x28]
	ldrh r3, [r6, 0x28]
	cmp r0, r3
	bne _0805D680
	bl Random
	adds r3, r0, 0
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	movs r1, 0x2
	ands r1, r3
	adds r0, r1
	b _0805D702
	.pool
_0805D680:
	ldr r4, =gUnknown_0831C604
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r0, [r0]
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _0805D6CC
	cmp r4, 0x1
	bgt _0805D6B4
	cmp r4, 0
	beq _0805D6BA
	b _0805D6FA
	.pool
_0805D6B4:
	cmp r4, 0x2
	beq _0805D6DE
	b _0805D6FA
_0805D6BA:
	ldrh r0, [r5, 0x28]
	ldrh r6, [r6, 0x28]
	cmp r0, r6
	bls _0805D6C8
	mov r1, r8
	lsls r0, r1, 8
	b _0805D704
_0805D6C8:
	lsls r0, r7, 8
	b _0805D704
_0805D6CC:
	ldrh r0, [r5, 0x28]
	ldrh r6, [r6, 0x28]
	cmp r0, r6
	bcs _0805D6DA
	mov r3, r8
	lsls r0, r3, 8
	b _0805D704
_0805D6DA:
	lsls r0, r7, 8
	b _0805D704
_0805D6DE:
	bl Random
	adds r3, r0, 0
	mov r0, r9
	ldrb r1, [r0]
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	ands r4, r3
	adds r0, r4
	lsls r0, 24
	lsrs r0, 16
	b _0805D704
_0805D6FA:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
_0805D702:
	lsls r0, 8
_0805D704:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_805D5F4

	thumb_func_start sub_805D714
sub_805D714: @ 805D714
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r3, [r0]
	lsls r0, r3, 26
	cmp r0, 0
	bge _0805D766
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _0805D766
	adds r2, r1, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	lsls r0, r1, 25
	cmp r0, 0
	bge _0805D75C
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _0805D766
	.pool
_0805D75C:
	lsls r0, r3, 27
	cmp r0, 0
	bge _0805D766
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_0805D766:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D714

	thumb_func_start sub_805D770
sub_805D770: @ 805D770
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	adds r3, r4, 0
	adds r3, 0x2C
	ldrb r0, [r3]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r3]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	cmp r1, 0
	bne _0805D798
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _0805D7A0
	.pool
_0805D798:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0805D7A0:
	adds r0, r4, 0
	bl AnimateSprite
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_805D770

	thumb_func_start sub_805D7AC
sub_805D7AC: @ 805D7AC
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_020243FC
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805D7E4
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0805D7E4
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0805D7E0
	ldr r0, =sub_805D7EC
	b _0805D7E2
	.pool
_0805D7E0:
	ldr r0, =SpriteCallbackDummy
_0805D7E2:
	str r0, [r2, 0x1C]
_0805D7E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D7AC

	thumb_func_start sub_805D7EC
sub_805D7EC: @ 805D7EC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x26]
	subs r0, 0x2
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	bne _0805D800
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_0805D800:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D7EC

	thumb_func_start move_anim_start_t2_for_situation
move_anim_start_t2_for_situation: @ 805D808
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	ldr r6, =gBattleSpritesDataPtr
	ldr r1, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r3, [r1, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1]
	movs r3, 0x10
	orrs r2, r3
	strb r2, [r1]
	cmp r0, 0
	bne _0805D888
	cmp r4, 0x20
	bne _0805D844
	ldrb r0, [r5]
	movs r1, 0x6
	bl move_anim_start_t2
	b _0805D902
	.pool
_0805D844:
	cmp r4, 0x8
	beq _0805D850
	movs r0, 0x80
	ands r0, r4
	cmp r0, 0
	beq _0805D85A
_0805D850:
	ldrb r0, [r5]
	movs r1, 0
	bl move_anim_start_t2
	b _0805D902
_0805D85A:
	cmp r4, 0x10
	bne _0805D868
	ldrb r0, [r5]
	movs r1, 0x2
	bl move_anim_start_t2
	b _0805D902
_0805D868:
	movs r0, 0x7
	ands r0, r4
	cmp r0, 0
	beq _0805D87A
	ldrb r0, [r5]
	movs r1, 0x4
	bl move_anim_start_t2
	b _0805D902
_0805D87A:
	cmp r4, 0x40
	bne _0805D8EA
	ldrb r0, [r5]
	movs r1, 0x5
	bl move_anim_start_t2
	b _0805D902
_0805D888:
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r4
	cmp r0, 0
	beq _0805D89C
	ldrb r0, [r5]
	movs r1, 0x3
	bl move_anim_start_t2
	b _0805D902
_0805D89C:
	movs r0, 0x7
	ands r0, r4
	cmp r0, 0
	beq _0805D8AE
	ldrb r0, [r5]
	movs r1, 0x1
	bl move_anim_start_t2
	b _0805D902
_0805D8AE:
	movs r0, 0x80
	lsls r0, 21
	ands r0, r4
	cmp r0, 0
	beq _0805D8C2
	ldrb r0, [r5]
	movs r1, 0x7
	bl move_anim_start_t2
	b _0805D902
_0805D8C2:
	movs r0, 0x80
	lsls r0, 20
	ands r0, r4
	cmp r0, 0
	beq _0805D8D6
	ldrb r0, [r5]
	movs r1, 0x8
	bl move_anim_start_t2
	b _0805D902
_0805D8D6:
	movs r0, 0xE0
	lsls r0, 8
	ands r0, r4
	cmp r0, 0
	beq _0805D8EA
	ldrb r0, [r5]
	movs r1, 0x9
	bl move_anim_start_t2
	b _0805D902
_0805D8EA:
	ldr r0, [r6]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0805D902:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end move_anim_start_t2_for_situation

	thumb_func_start move_anim_start_t3
move_anim_start_t3: @ 805D908
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r4, 16
	lsrs r7, r4, 16
	cmp r5, 0
	bne _0805D950
	movs r0, 0x80
	ands r0, r7
	cmp r0, 0
	beq _0805D950
	ldr r0, =gBattleMonForms
	adds r0, r6, r0
	movs r2, 0x7F
	adds r1, r7, 0
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D950:
	ldr r0, =gBattleSpritesDataPtr
	mov r9, r0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r4, r6, 2
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r2, 0x4
	mov r8, r2
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0805D9CC
	adds r0, r5, 0
	bl sub_805DAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805D980
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D980:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	adds r0, r4, r0
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0805D9CC
	cmp r5, 0x2
	bne _0805D9CC
	ldr r1, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r6, r0
	ldrb r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _0805D9CC
	adds r0, r6, 0
	movs r1, 0x1
	bl refresh_graphics_maybe
	adds r0, r6, 0
	bl sub_805E974
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D9CC:
	ldr r0, =gAnimationBankAttacker
	mov r2, r10
	strb r2, [r0]
	ldr r0, =gAnimationBankTarget
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r4, =gBattleSpritesDataPtr
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	strh r7, [r0]
	ldr r0, =gUnknown_082C9320
	adds r1, r5, 0
	movs r2, 0
	bl move_something
	ldr r0, =task0A_0803415C
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0x8]
	ldr r0, [r4]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0
_0805DA1E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end move_anim_start_t3

	thumb_func_start task0A_0803415C
task0A_0803415C: @ 805DA48
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DA8A
	ldr r0, =gBattleSpritesDataPtr
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0805DA8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_0803415C

	thumb_func_start sub_805DAA0
sub_805DAA0: @ 805DAA0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	bgt _0805DAB4
	cmp r0, 0xA
	bge _0805DAB8
	cmp r0, 0x2
	beq _0805DAB8
	b _0805DABC
_0805DAB4:
	cmp r0, 0x11
	bne _0805DABC
_0805DAB8:
	movs r0, 0x1
	b _0805DABE
_0805DABC:
	movs r0, 0
_0805DABE:
	pop {r1}
	bx r1
	thumb_func_end sub_805DAA0

	thumb_func_start move_anim_start_t4
move_anim_start_t4: @ 805DAC4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gAnimationBankAttacker
	strb r1, [r0]
	ldr r0, =gAnimationBankTarget
	strb r2, [r0]
	ldr r0, =gUnknown_082C937C
	adds r1, r3, 0
	movs r2, 0
	bl move_something
	ldr r0, =task0A_08034248
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_start_t4

	thumb_func_start task0A_08034248
task0A_08034248: @ 805DB34
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DB76
	ldr r0, =gBattleSpritesDataPtr
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0805DB76:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_08034248

	thumb_func_start sub_805DB8C
sub_805DB8C: @ 805DB8C
	movs r0, 0
	bx lr
	thumb_func_end sub_805DB8C

	thumb_func_start mplay_80342A4
mplay_80342A4: @ 805DB90
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0805DBD8
	ldr r2, =gBattleSpritesDataPtr
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	adds r1, 0x1
	strb r1, [r0, 0x8]
	ldr r2, [r2]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1D
	bls _0805DBDC
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
_0805DBD8:
	cmp r5, 0
	beq _0805DBF0
_0805DBDC:
	movs r0, 0x1
	b _0805DC02
	.pool
_0805DBF0:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	strb r5, [r0, 0x8]
	movs r0, 0
_0805DC02:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mplay_80342A4

	thumb_func_start BattleLoadOpponentMonSpriteGfx
BattleLoadOpponentMonSpriteGfx: @ 805DC0C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	adds r2, r1, r0
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	bne _0805DC50
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r6, [sp]
	b _0805DC58
	.pool
_0805DC50:
	ldrh r5, [r2, 0x2]
	ldr r0, =gUnknown_020244BC
	adds r0, r1, r0
	ldr r6, [r0]
_0805DC58:
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	mov r10, r0
	mov r0, r8
	bl GetBankIdentity
	lsls r0, 24
	lsls r2, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r2, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
	mov r3, r8
	lsls r2, r3, 4
	movs r0, 0x80
	lsls r0, 1
	adds r7, r2, r0
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r1, r3, 2
	adds r0, r1, r0
	ldrh r0, [r0, 0x2]
	str r1, [sp, 0x4]
	mov r9, r2
	cmp r0, 0
	bne _0805DCBC
	adds r0, r4, 0
	bl pokemon_get_pal
	b _0805DCC6
	.pool
_0805DCBC:
	adds r0, r5, 0
	mov r1, r10
	ldr r2, [sp]
	bl species_and_otid_get_pal
_0805DCC6:
	adds r6, r0, 0
	ldr r4, =0x0201c000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
	mov r1, r9
	adds r1, 0x80
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r5, r0
	bne _0805DD1A
	movs r7, 0x80
	lsls r7, 1
	add r7, r9
	ldr r5, =gBattleStruct
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	adds r0, r6, 0
	bl LZDecompressWram
	ldr r0, =gBattleMonForms
	add r0, r8
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
_0805DD1A:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DD46
	ldr r3, =0x00007fff
	adds r0, r7, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r7, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805DD46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleLoadOpponentMonSpriteGfx

	thumb_func_start BattleLoadPlayerMonSpriteGfx
BattleLoadPlayerMonSpriteGfx: @ 805DD7C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	adds r2, r1, r0
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	bne _0805DDC0
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, [sp]
	b _0805DDC8
	.pool
_0805DDC0:
	ldrh r5, [r2, 0x2]
	ldr r0, =gUnknown_020244BC
	adds r0, r1, r0
	ldr r4, [r0]
_0805DDC8:
	adds r0, r6, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x4]
	mov r0, r8
	bl GetBankIdentity
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x1
	mov r1, r8
	bl sub_80688F8
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	lsls r1, 2
	mov r10, r1
	cmp r0, 0x1
	beq _0805DE00
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DE2C
_0805DE00:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsls r2, r7, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	adds r2, r5, 0
	adds r3, r4, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
	b _0805DE46
	.pool
_0805DE2C:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsls r2, r7, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	adds r2, r5, 0
	adds r3, r4, 0
	bl HandleLoadSpecialPokePic
_0805DE46:
	mov r2, r8
	lsls r1, r2, 4
	movs r0, 0x80
	lsls r0, 1
	adds r7, r1, r0
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	mov r9, r1
	cmp r0, 0
	bne _0805DE74
	adds r0, r6, 0
	bl pokemon_get_pal
	b _0805DE7E
	.pool
_0805DE74:
	adds r0, r5, 0
	ldr r1, [sp, 0x4]
	ldr r2, [sp]
	bl species_and_otid_get_pal
_0805DE7E:
	adds r6, r0, 0
	ldr r4, =0x0201c000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
	mov r1, r9
	adds r1, 0x80
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r5, r0
	bne _0805DED2
	movs r7, 0x80
	lsls r7, 1
	add r7, r9
	ldr r5, =gBattleStruct
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	adds r0, r6, 0
	bl LZDecompressWram
	ldr r0, =gBattleMonForms
	add r0, r8
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
_0805DED2:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DEFC
	ldr r3, =0x00007fff
	adds r0, r7, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r7, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805DEFC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleLoadPlayerMonSpriteGfx

	thumb_func_start nullsub_23
nullsub_23: @ 805DF30
	bx lr
	thumb_func_end nullsub_23

	thumb_func_start nullsub_24
nullsub_24: @ 805DF34
	bx lr
	thumb_func_end nullsub_24

	thumb_func_start sub_805DF38
sub_805DF38: @ 805DF38
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	bl GetBankIdentity
	lsls r0, 24
	lsls r4, 3
	ldr r2, =gTrainerFrontPicTable
	adds r2, r4, r2
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	movs r2, 0
	bl DecompressPicFromTable_2
	ldr r0, =gTrainerFrontPicPaletteTable
	adds r4, r0
	adds r0, r4, 0
	bl LoadCompressedObjectPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DF38

	thumb_func_start LoadBackTrainerBankSpriteGfx
LoadBackTrainerBankSpriteGfx: @ 805DF84
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	lsls r5, 3
	ldr r2, =gTrainerBackPicTable
	adds r2, r5, r2
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	movs r2, 0
	bl DecompressPicFromTable_2
	ldr r0, =gTrainerBackPicPaletteTable
	adds r5, r0
	ldr r0, [r5]
	lsls r4, 20
	movs r1, 0x80
	lsls r1, 17
	adds r4, r1
	lsrs r4, 16
	adds r1, r4, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadBackTrainerBankSpriteGfx

	thumb_func_start nullsub_25
nullsub_25: @ 805DFE0
	bx lr
	thumb_func_end nullsub_25

	thumb_func_start sub_805DFE4
sub_805DFE4: @ 805DFE4
	push {lr}
	lsls r0, 16
	ldr r1, =gTrainerFrontPicPaletteTable
	lsrs r0, 13
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DFE4

	thumb_func_start sub_805DFFC
sub_805DFFC: @ 805DFFC
	push {r4-r7,lr}
	ldr r4, =gUnknown_0832C128
	adds r0, r4, 0
	bl LoadSpritePalette
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadSpritePalette
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _0805E034
	ldr r0, =gUnknown_0832C0D0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0832C0D8
	bl LoadCompressedObjectPic
	movs r5, 0x2
	b _0805E056
	.pool
_0805E034:
	ldr r4, =gUnknown_0832C0E0
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	ldr r4, =gUnknown_0832C0F0
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	movs r5, 0x4
_0805E056:
	movs r4, 0
	cmp r4, r5
	bcs _0805E076
	ldr r7, =gBanksByIdentity
	ldr r6, =gUnknown_0832C108
_0805E060:
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r6
	bl LoadCompressedObjectPic
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0805E060
_0805E076:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DFFC

	thumb_func_start BattleLoadAllHealthBoxesGfx
BattleLoadAllHealthBoxesGfx: @ 805E08C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r6, 0
	cmp r4, 0
	bne _0805E09C
	b _0805E1AE
_0805E09C:
	cmp r4, 0x1
	bne _0805E0B8
	ldr r4, =gUnknown_0832C128
	adds r0, r4, 0
	bl LoadSpritePalette
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadSpritePalette
	b _0805E1AE
	.pool
_0805E0B8:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _0805E120
	cmp r4, 0x2
	bne _0805E0F0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0805E0E4
	ldr r0, =gUnknown_0832C100
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E0E4:
	ldr r0, =gUnknown_0832C0D0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E0F0:
	cmp r4, 0x3
	bne _0805E100
	ldr r0, =gUnknown_0832C0D8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E100:
	cmp r4, 0x4
	bne _0805E110
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0]
	b _0805E198
	.pool
_0805E110:
	cmp r4, 0x5
	bne _0805E1AC
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0, 0x1]
	b _0805E198
	.pool
_0805E120:
	cmp r4, 0x2
	bne _0805E130
	ldr r0, =gUnknown_0832C0E0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E130:
	cmp r4, 0x3
	bne _0805E140
	ldr r0, =gUnknown_0832C0E8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E140:
	cmp r4, 0x4
	bne _0805E150
	ldr r0, =gUnknown_0832C0F0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E150:
	cmp r4, 0x5
	bne _0805E160
	ldr r0, =gUnknown_0832C0F8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E160:
	cmp r4, 0x6
	bne _0805E170
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0]
	b _0805E198
	.pool
_0805E170:
	cmp r4, 0x7
	bne _0805E180
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0, 0x1]
	b _0805E198
	.pool
_0805E180:
	cmp r4, 0x8
	bne _0805E190
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0, 0x2]
	b _0805E198
	.pool
_0805E190:
	cmp r5, 0x9
	bne _0805E1AC
	ldr r0, =gBanksByIdentity
	ldrb r0, [r0, 0x3]
_0805E198:
	lsls r0, 3
	ldr r1, =gUnknown_0832C108
	adds r0, r1
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E1AC:
	movs r6, 0x1
_0805E1AE:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end BattleLoadAllHealthBoxesGfx

	thumb_func_start LoadBattleBarGfx
LoadBattleBarGfx: @ 805E1B8
	push {lr}
	ldr r0, =gUnknown_08C093F0
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	movs r2, 0xBA
	lsls r2, 1
	adds r1, r2
	ldr r1, [r1]
	bl LZDecompressWram
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadBattleBarGfx

	thumb_func_start BattleInitAllSprites
BattleInitAllSprites: @ 805E1D8
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r6, 0
	ldrb r0, [r5]
	cmp r0, 0x6
	bls _0805E1E8
	b _0805E346
_0805E1E8:
	lsls r0, 2
	ldr r1, =_0805E1F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805E1F8:
	.4byte _0805E214
	.4byte _0805E21A
	.4byte _0805E324
	.4byte _0805E230
	.4byte _0805E260
	.4byte _0805E29C
	.4byte _0805E33C
_0805E214:
	bl sub_805E378
	b _0805E324
_0805E21A:
	ldrb r0, [r4]
	bl BattleLoadAllHealthBoxesGfx
	lsls r0, 24
	cmp r0, 0
	beq _0805E228
	b _0805E320
_0805E228:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0805E346
_0805E230:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0805E24C
	ldrb r0, [r4]
	cmp r0, 0
	bne _0805E24C
	bl CreateSafariPlayerHealthboxSprites
	b _0805E252
	.pool
_0805E24C:
	ldrb r0, [r4]
	bl CreateBankHealthboxSprites
_0805E252:
	ldr r2, =gHealthBoxesIds
	ldrb r1, [r4]
	adds r1, r2
	strb r0, [r1]
	b _0805E30E
	.pool
_0805E260:
	ldrb r0, [r4]
	bl SetBankHealthboxSpritePos
	ldr r0, =gBanksByIdentity
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _0805E288
	ldr r0, =gHealthBoxesIds
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, 0
	bl DummyBattleInterfaceFunc
	b _0805E30E
	.pool
_0805E288:
	ldr r0, =gHealthBoxesIds
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, 0x1
	bl DummyBattleInterfaceFunc
	b _0805E30E
	.pool
_0805E29C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805E2E4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805E302
	ldr r0, =gHealthBoxesIds
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl UpdateHealthboxAttribute
	b _0805E302
	.pool
_0805E2E4:
	ldr r0, =gHealthBoxesIds
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl UpdateHealthboxAttribute
_0805E302:
	ldr r1, =gHealthBoxesIds
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	bl SetHealthboxSpriteInvisible
_0805E30E:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E346
_0805E320:
	movs r0, 0
	strb r0, [r4]
_0805E324:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0805E346
	.pool
_0805E33C:
	bl LoadAndCreateEnemyShadowSprites
	bl sub_81B8C68
	movs r6, 0x1
_0805E346:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end BattleInitAllSprites

	thumb_func_start sub_805E350
sub_805E350: @ 805E350
	push {r4,lr}
	ldr r4, =gBattleSpritesDataPtr
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E350

	thumb_func_start sub_805E378
sub_805E378: @ 805E378
	push {lr}
	bl sub_805E350
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E378

	thumb_func_start sub_805E394
sub_805E394: @ 805E394
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r5, =gNoOfAllBanks
	ldrb r0, [r5]
	cmp r4, r0
	bge _0805E3EA
	ldr r0, =gSprites
	mov r9, r0
	movs r0, 0x1
	mov r12, r0
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ldr r7, =gBattleSpritesDataPtr
	ldr r6, =gBankSpriteIds
_0805E3B8:
	ldr r0, [r7]
	ldr r0, [r0]
	lsls r3, r4, 2
	adds r3, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	mov r0, r12
	ands r1, r0
	ldrb r2, [r3]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r4, 0x1
	ldrb r0, [r5]
	cmp r4, r0
	blt _0805E3B8
_0805E3EA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E394

	thumb_func_start sub_805E408
sub_805E408: @ 805E408
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleSpritesDataPtr
	ldr r1, [r1]
	ldr r1, [r1]
	lsls r3, r0, 2
	adds r3, r1
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_805E408

	thumb_func_start sub_805E448
sub_805E448: @ 805E448
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	lsls r2, 24
	cmp r2, 0
	beq _0805E51C
	ldr r0, =gBankSpriteIds
	adds r5, r7, r0
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	mov r8, r1
	add r0, r8
	ldr r4, =gBattleSpritesDataPtr
	ldr r1, [r4]
	ldr r1, [r1, 0x8]
	ldrb r1, [r1]
	bl StartSpriteAnim
	lsls r0, r7, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r6, r0, 16
	ldr r2, =gBattleStruct
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrh r1, [r0]
	lsls r1, 5
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3
	ldr r0, [r2]
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gBattleMonForms
	adds r1, r7, r1
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805E4DE
	ldr r3, =0x00007fff
	adds r0, r6, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r6, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805E4DE:
	adds r0, r7, 0
	bl sub_80A6138
	ldrb r2, [r5]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x22]
	b _0805E77A
	.pool
_0805E51C:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0805E558
	movs r0, 0
	mov r10, r0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2, 0x2]
	mov r8, r1
	ldr r3, [r2, 0x8]
	mov r9, r3
	ldr r4, [r2, 0xC]
	lsls r0, r1, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	ldr r3, [r2, 0x10]
	b _0805E5FA
	.pool
_0805E558:
	adds r0, r7, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, [sp]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805E58C
	ldr r1, =gBattlePartyID
	ldr r2, [sp]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _0805E59C
	.pool
_0805E58C:
	ldr r1, =gBattlePartyID
	ldr r3, [sp]
	lsls r0, r3, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_0805E59C:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805E618
	ldr r0, =gBattlePartyID
	lsls r4, r7, 1
	adds r4, r0
	ldrh r0, [r4]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrh r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	adds r4, r0, 0
	mov r1, r8
	lsls r0, r1, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	mov r3, r10
	lsls r2, r3, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	ldr r3, =gUnknown_020244BC
	lsls r2, r7, 2
	adds r2, r3
	ldr r3, [r2]
_0805E5FA:
	mov r2, r8
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
	b _0805E662
	.pool
_0805E618:
	ldr r0, =gBattlePartyID
	lsls r4, r7, 1
	adds r4, r0
	ldrh r0, [r4]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrh r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	adds r4, r0, 0
	mov r1, r8
	lsls r0, r1, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	mov r3, r10
	lsls r2, r3, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	ldr r3, =gUnknown_020244BC
	lsls r2, r7, 2
	adds r2, r3
	ldr r3, [r2]
	mov r2, r8
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
_0805E662:
	ldr r0, =gMonSpritesGfxPtr
	ldr r0, [r0]
	mov r2, r10
	lsls r1, r2, 2
	adds r0, 0x4
	adds r0, r1
	ldr r2, [r0]
	ldr r0, =gBankSpriteIds
	adds r0, r7
	mov r10, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r3, =gSprites
	adds r0, r3
	ldrh r0, [r0, 0x4]
	lsls r0, 22
	lsrs r0, 17
	ldr r1, =0x06010000
	adds r0, r1
	ldr r1, =0x040000d4
	str r2, [r1]
	str r0, [r1, 0x4]
	ldr r0, =0x84000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	lsls r0, r7, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r6, r0, 16
	mov r0, r8
	adds r1, r4, 0
	mov r2, r9
	bl species_and_otid_get_pal
	mov r9, r0
	ldr r4, =0x0201c000
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r8, r0
	bne _0805E70A
	mov r2, r10
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r1, 0x8
	adds r0, r1
	ldr r1, =gMonAnimationsSpriteAnimsPtrTable
	mov r3, r8
	lsls r2, r3, 2
	adds r1, r2
	ldr r1, [r1]
	str r1, [r0]
	ldr r5, =gBattleStruct
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	mov r0, r9
	bl LZDecompressWram
	ldr r0, =gBattleMonForms
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
_0805E70A:
	ldr r3, =0x00007fff
	adds r0, r6, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r6, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0805E74A
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	mov r2, r8
	strh r2, [r0, 0x2]
	ldr r0, =gBattleMonForms
	adds r1, r7, r0
	ldr r3, [sp]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r1]
_0805E74A:
	adds r0, r7, 0
	bl sub_80A6138
	mov r1, r10
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x22]
	mov r3, r10
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gBattleMonForms
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartSpriteAnim
_0805E77A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E448

	thumb_func_start BattleLoadSubstituteSpriteGfx
BattleLoadSubstituteSpriteGfx: @ 805E7DC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	lsls r1, 24
	cmp r1, 0
	bne _0805E898
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0805E7F8
	movs r4, 0
	b _0805E802
_0805E7F8:
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
_0805E802:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0805E814
	ldr r0, =gUnknown_08C2D120
	b _0805E822
	.pool
_0805E814:
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805E83C
	ldr r0, =gUnknown_08C2CEE0
_0805E822:
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x4
	adds r1, r4
	ldr r1, [r1]
	bl LZDecompressVram
	b _0805E84E
	.pool
_0805E83C:
	ldr r0, =gUnknown_08C2D120
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x4
	adds r1, r4
	ldr r1, [r1]
	bl LZDecompressVram
_0805E84E:
	movs r3, 0x1
	lsls r6, r5, 4
	ldr r7, =gUnknown_08C2CEBC
	ldr r0, =gMonSpritesGfxPtr
	ldr r0, [r0]
	adds r0, 0x4
	adds r4, r0, r4
	ldr r2, =0x040000d4
	ldr r5, =0x84000200
_0805E860:
	ldr r0, [r4]
	lsls r1, r3, 11
	adds r1, r0, r1
	str r0, [r2]
	str r1, [r2, 0x4]
	str r5, [r2, 0x8]
	ldr r0, [r2, 0x8]
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805E860
	movs r0, 0x80
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r7, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _0805E8E6
	.pool
_0805E898:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0805E8E6
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805E8D0
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r1, r4, 0
	bl BattleLoadOpponentMonSpriteGfx
	b _0805E8E6
	.pool
_0805E8D0:
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r5, 0
	bl BattleLoadPlayerMonSpriteGfx
_0805E8E6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleLoadSubstituteSpriteGfx

	thumb_func_start refresh_graphics_maybe
refresh_graphics_maybe: @ 805E8F4
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r5, 0
	bl BattleLoadSubstituteSpriteGfx
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	ldr r0, =gBattleMonForms
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl StartSpriteAnim
	cmp r5, 0
	bne _0805E938
	adds r0, r6, 0
	bl sub_80A614C
	b _0805E93E
	.pool
_0805E938:
	adds r0, r6, 0
	bl sub_80A6138
_0805E93E:
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end refresh_graphics_maybe

	thumb_func_start sub_805E94C
sub_805E94C: @ 805E94C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xA4
	bne _0805E96C
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
_0805E96C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E94C

	thumb_func_start sub_805E974
sub_805E974: @ 805E974
	lsls r0, 24
	ldr r1, =gBattleSpritesDataPtr
	ldr r1, [r1]
	ldr r1, [r1]
	lsrs r0, 22
	adds r0, r1
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805E974

	thumb_func_start sub_805E990
sub_805E990: @ 805E990
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	adds r7, r6, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl GetHPBarLevel
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805EA08
	ldr r7, =gBattleSpritesDataPtr
	ldr r0, [r7]
	ldr r2, [r0]
	lsls r4, r6, 2
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r5, 0x2
	movs r3, 0x2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EA5A
	adds r0, r6, 0
	eors r0, r5
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805E9F6
	movs r0, 0x5A
	bl PlaySE
_0805E9F6:
	ldr r0, [r7]
	ldr r1, [r0]
	adds r1, r4, r1
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	b _0805EA5A
	.pool
_0805EA08:
	ldr r4, =gBattleSpritesDataPtr
	ldr r0, [r4]
	ldr r0, [r0]
	lsls r1, r6, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _0805EA34
	movs r0, 0x5A
	bl m4aSongNumStop
	b _0805EA5A
	.pool
_0805EA34:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0805EA5A
	ldr r1, [r4]
	movs r0, 0x2
	eors r7, r0
	ldr r1, [r1]
	lsls r0, r7, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0805EA5A
	movs r0, 0x5A
	bl m4aSongNumStop
_0805EA5A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_805E990

	thumb_func_start BattleMusicStop
BattleMusicStop: @ 805EA60
	push {r4-r6,lr}
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gBattleSpritesDataPtr
	ldr r0, [r5]
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r6, 0x3
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0805EAA2
	ldr r2, [r5]
	movs r0, 0x2
	adds r1, r4, 0
	eors r1, r0
	ldr r0, [r2]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
_0805EAA2:
	movs r0, 0x5A
	bl m4aSongNumStop
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleMusicStop

	thumb_func_start sub_805EAB4
sub_805EAB4: @ 805EAB4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl GetHPBarLevel
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805EAB4

	thumb_func_start sub_805EAE8
sub_805EAE8: @ 805EAE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805EB7E
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x2
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r5, =gBattlePartyID
	mov r1, r8
	lsls r0, r1, 1
	adds r0, r5
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r9
	lsls r0, r1, 1
	adds r0, r5
	ldrb r0, [r0]
	bl pokemon_order_func
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0x64
	adds r0, r4, 0
	muls r0, r7
	ldr r6, =gPlayerParty
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0805EB5A
	adds r0, r4, 0
	mov r1, r8
	bl sub_805E990
_0805EB5A:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0805EB7E
	adds r0, r5, 0
	muls r0, r7
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0805EB7E
	adds r0, r4, 0
	mov r1, r9
	bl sub_805E990
_0805EB7E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EAE8

	thumb_func_start sub_805EB9C
sub_805EB9C: @ 805EB9C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bge _0805EC6C
	movs r0, 0x3
	mov r10, r8
	mov r1, r10
	ands r1, r0
	mov r10, r1
	movs r6, 0
	movs r2, 0x3F
	negs r2, r2
	mov r9, r2
_0805EBC8:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _0805EC60
	ldr r4, =gSprites
	ldr r0, =gBankSpriteIds
	adds r3, r5, r0
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r7, 0x4
	negs r7, r7
	adds r2, r7, 0
	ands r1, r2
	mov r2, r10
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r7, r8
	cmp r7, 0
	bne _0805EC3C
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	adds r2, r6, r2
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r2, 0x6]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x3]
	mov r2, r9
	ands r1, r2
	strb r1, [r0, 0x3]
	b _0805EC60
	.pool
_0805EC3C:
	ldrb r0, [r3]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r1, [r0, 0x6]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r0, [r2, 0x3]
	mov r3, r9
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x3]
_0805EC60:
	adds r6, 0xC
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0805EBC8
_0805EC6C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EB9C

	thumb_func_start LoadAndCreateEnemyShadowSprites
LoadAndCreateEnemyShadowSprites: @ 805EC84
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_0831C6A0
	bl LoadCompressedObjectPic
	movs r0, 0x1
	bl GetBankByIdentity
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0831C6B0
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 8
	movs r0, 0xE8
	lsls r0, 13
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0xC8
	bl CreateSprite
	ldr r6, =gBattleSpritesDataPtr
	ldr r1, [r6]
	ldr r2, [r1, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r2, r1, r2
	strb r0, [r2, 0x7]
	ldr r7, =gSprites
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r5, [r0, 0x2E]
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0805ED56
	movs r0, 0x3
	bl GetBankByIdentity
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 8
	movs r0, 0xE8
	lsls r0, 13
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0xC8
	bl CreateSprite
	ldr r1, [r6]
	ldr r2, [r1, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r2, r1, r2
	strb r0, [r2, 0x7]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r5, [r0, 0x2E]
_0805ED56:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadAndCreateEnemyShadowSprites

	thumb_func_start sub_805ED70
@ int sub_805ED70(obj *a1)
sub_805ED70: @ 805ED70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	movs r0, 0
	mov r8, r0
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r7, r0, r1
	adds r6, r7, 0
	adds r6, 0x3E
	ldrb r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805EDAC
	adds r0, r4, 0
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	bne _0805EDC0
_0805EDAC:
	ldr r0, =sub_805EE48
	str r0, [r5, 0x1C]
	b _0805EE36
	.pool
_0805EDC0:
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805EDD2
	ldrb r1, [r6]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805EDE4
_0805EDD2:
	movs r0, 0x1
	mov r8, r0
	ldr r2, =gBattleSpritesDataPtr
	lsls r4, 2
	b _0805EE06
	.pool
_0805EDE4:
	ldr r2, =gBattleSpritesDataPtr
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r3, r1, r0
	ldrh r0, [r3, 0x2]
	adds r4, r1, 0
	cmp r0, 0
	beq _0805EE06
	ldr r0, =gEnemyMonElevation
	ldrh r1, [r3, 0x2]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805EE06
	movs r0, 0x1
	mov r8, r0
_0805EE06:
	ldr r0, [r2]
	ldr r0, [r0]
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805EE1A
	movs r0, 0x1
	mov r8, r0
_0805EE1A:
	ldrh r0, [r7, 0x20]
	strh r0, [r5, 0x20]
	ldrh r0, [r7, 0x24]
	strh r0, [r5, 0x24]
	adds r2, r5, 0
	adds r2, 0x3E
	mov r0, r8
	lsls r3, r0, 2
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_0805EE36:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805ED70

	thumb_func_start sub_805EE48
sub_805EE48: @ 805EE48
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_805EE48

	thumb_func_start SetBankEnemyShadowSpriteCallback
SetBankEnemyShadowSpriteCallback: @ 805EE54
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	lsls r1, 16
	lsrs r5, r1, 16
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805EED0
	ldr r0, =gBattleSpritesDataPtr
	ldr r3, [r0]
	ldr r1, [r3]
	lsls r0, r4, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0805EE7E
	adds r5, r0, 0
_0805EE7E:
	ldr r0, =gEnemyMonElevation
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EEB4
	ldr r2, =gSprites
	ldr r1, [r3, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805ED70
	b _0805EECE
	.pool
_0805EEB4:
	ldr r2, =gSprites
	ldr r1, [r3, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805EE48
_0805EECE:
	str r1, [r0]
_0805EED0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBankEnemyShadowSpriteCallback

	thumb_func_start sub_805EEE0
sub_805EEE0: @ 805EEE0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	ldr r1, =gBattleSpritesDataPtr
	ldr r1, [r1]
	ldr r3, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805EE48
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805EEE0

	thumb_func_start sub_805EF14
sub_805EF14: @ 805EF14
	push {r4-r6,lr}
	ldr r3, =0x06000240
	movs r0, 0
	movs r6, 0xF0
	lsls r6, 8
_0805EF1E:
	adds r5, r0, 0x1
	movs r4, 0xF
_0805EF22:
	ldrh r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EF32
	adds r0, r6, 0
	orrs r0, r1
	strh r0, [r3]
_0805EF32:
	ldrh r1, [r3]
	movs r2, 0xF0
	lsls r2, 4
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EF46
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r3]
_0805EF46:
	ldrh r1, [r3]
	movs r2, 0xF0
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	bne _0805EF58
	adds r0, r1, 0
	orrs r0, r2
	strh r0, [r3]
_0805EF58:
	ldrh r1, [r3]
	movs r2, 0xF
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _0805EF6A
	adds r0, r1, 0
	orrs r0, r2
	strh r0, [r3]
_0805EF6A:
	adds r3, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0805EF22
	adds r0, r5, 0
	cmp r0, 0x8
	ble _0805EF1E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EF14

	thumb_func_start sub_805EF84
sub_805EF84: @ 805EF84
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r2, [r0]
	lsls r0, r4, 2
	adds r0, r2
	movs r3, 0
	movs r2, 0
	strh r2, [r0, 0x2]
	ldr r0, =gBattleMonForms
	adds r0, r4, r0
	strb r3, [r0]
	cmp r1, 0
	bne _0805EFAC
	adds r0, r4, 0
	bl sub_805E974
_0805EFAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EF84

	thumb_func_start AllocateMonSpritesGfx
AllocateMonSpritesGfx: @ 805EFBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	ldr r4, =gMonSpritesGfxPtr
	str r6, [r4]
	movs r0, 0xC0
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x80
	lsls r0, 8
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
_0805EFE2:
	ldr r0, =gMonSpritesGfxPtr
	ldr r1, [r0]
	lsls r4, r6, 2
	adds r2, r1, 0x4
	adds r2, r4
	lsls r3, r6, 13
	ldr r0, [r1]
	adds r0, r3
	str r0, [r2]
	lsls r3, r6, 1
	adds r0, r3, r6
	lsls r0, 3
	adds r1, r0, r1
	ldr r2, =gUnknown_08329D98
	adds r1, 0x14
	adds r0, r2
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	movs r5, 0
	mov r9, r3
	lsls r0, r6, 5
	mov r8, r0
	adds r1, r6, 0x1
	mov r10, r1
	mov r12, r8
	adds r7, r4, 0
_0805F01A:
	ldr r2, =gMonSpritesGfxPtr
	ldr r1, [r2]
	lsls r4, r5, 3
	add r4, r12
	adds r3, r1, 0
	adds r3, 0x74
	adds r3, r4
	adds r0, r1, 0x4
	adds r0, r7
	lsls r2, r5, 11
	ldr r0, [r0]
	adds r0, r2
	str r0, [r3]
	adds r1, r4
	adds r1, 0x78
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _0805F01A
	ldr r1, =gMonSpritesGfxPtr
	ldr r2, [r1]
	mov r5, r9
	adds r0, r5, r6
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	mov r0, r8
	adds r0, 0x74
	adds r2, r0
	str r2, [r1]
	mov r7, r10
	lsls r0, r7, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0805EFE2
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	movs r2, 0xBA
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AllocateMonSpritesGfx

	thumb_func_start FreeMonSpritesGfx
FreeMonSpritesGfx: @ 805F094
	push {r4-r6,lr}
	ldr r6, =gMonSpritesGfxPtr
	ldr r0, [r6]
	cmp r0, 0
	beq _0805F106
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0805F0BA
	bl Free
	ldr r0, [r6]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_0805F0BA:
	ldr r0, [r6]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0805F0D8
	bl Free
	ldr r0, [r6]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_0805F0D8:
	ldr r0, [r6]
	movs r5, 0xBA
	lsls r5, 1
	adds r0, r5
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r5, r0, r5
	movs r4, 0
	str r4, [r5]
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	str r4, [r0]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	str r4, [r0, 0x10]
	bl Free
	str r4, [r6]
_0805F106:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeMonSpritesGfx

	thumb_func_start sub_805F110
sub_805F110: @ 805F110
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x37
	bl GetMonData
	ldr r1, =0x00000fff
	ands r1, r0
	cmp r1, 0
	bne _0805F158
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl GetHPBarLevel
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	ble _0805F158
	movs r0, 0x1
	b _0805F15A
	.pool
_0805F158:
	movs r0, 0
_0805F15A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805F110
    
   	.align 2, 0 @ Don't pad with nop.
