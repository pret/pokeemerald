	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818E9AC
sub_818E9AC: @ 818E9AC
	push {lr}
	ldr r1, =gUnknown_0860D090
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E9AC

	thumb_func_start sub_818E9CC
sub_818E9CC: @ 818E9CC
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r4]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r6, 0
	strb r6, [r0]
	ldr r1, [r4]
	adds r2, 0xA
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r4, [r4]
	ldr r0, =0x00000cdc
	adds r3, r4, r0
	ldr r2, =gUnknown_0860D0EC
	lsls r1, r5, 2
	lsls r0, r7, 3
	adds r1, r0
	adds r1, r2
	ldr r0, [r3]
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _0818EA3E
	lsls r0, r5, 1
	lsls r1, r7, 2
	adds r0, r1
	ldr r2, =0x00000d0c
	adds r1, r4, r2
	adds r1, r0
	strh r6, [r1]
_0818EA3E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	ldr r0, =gTrainerBattleOpponent_A
	strh r6, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E9CC

	thumb_func_start sub_818EA84
sub_818EA84: @ 818EA84
	push {r4-r6,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x9
	bls _0818EAA8
	b _0818ED10
_0818EAA8:
	lsls r0, 2
	ldr r1, =_0818EAC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0818EAC8:
	.4byte _0818EAF0
	.4byte _0818EB14
	.4byte _0818EB48
	.4byte _0818EB64
	.4byte _0818EB80
	.4byte _0818EB98
	.4byte _0818EBB4
	.4byte _0818EC40
	.4byte _0818ECD0
	.4byte _0818ECF4
_0818EAF0:
	ldr r3, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r5, 1
	lsls r2, r6, 2
	adds r1, r2
	ldr r2, =0x00000d0c
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	b _0818ED10
	.pool
_0818EB14:
	ldr r4, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r3, =0x00000cdc
	adds r2, r3
	ldr r3, =gUnknown_0860D0EC
	lsls r0, r5, 2
	lsls r1, r6, 3
	adds r0, r1
	adds r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	strh r0, [r4]
	b _0818ED10
	.pool
_0818EB48:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 31
	b _0818ECBE
	.pool
_0818EB64:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 30
	b _0818ECBE
	.pool
_0818EB80:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	b _0818ECBA
	.pool
_0818EB98:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 28
	b _0818ECBE
	.pool
_0818EBB4:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0818EC04
	cmp r5, 0
	beq _0818EBE8
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 26
	b _0818ECBE
	.pool
_0818EBE8:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 27
	b _0818ECBE
	.pool
_0818EC04:
	cmp r5, 0
	beq _0818EC24
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 30
	b _0818ECBE
	.pool
_0818EC24:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 31
	b _0818ECBE
	.pool
_0818EC40:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0818EC90
	cmp r5, 0
	beq _0818EC74
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	ldrb r0, [r0]
	lsrs r0, 7
	strh r0, [r1]
	b _0818ED10
	.pool
_0818EC74:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 25
	b _0818ECBE
	.pool
_0818EC90:
	cmp r5, 0
	beq _0818ECB0
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d08
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 28
	b _0818ECBE
	.pool
_0818ECB0:
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d08
	adds r0, r3
_0818ECBA:
	ldrb r0, [r0]
	lsls r0, 29
_0818ECBE:
	lsrs r0, 31
	strh r0, [r1]
	b _0818ED10
	.pool
_0818ECD0:
	bl sub_81B8558
	ldr r2, =gUnknown_0203CEF8
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xCB
	lsls r1, 4
	adds r0, r1
	ldrh r1, [r0]
	strb r1, [r2]
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r2, 0x1]
	b _0818ED10
	.pool
_0818ECF4:
	ldr r2, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r3, =0x00000d0a
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r3, 0x1
	adds r1, r3
	ldr r3, =0x0000fffd
	adds r0, r3
	ldrb r1, [r1]
	adds r0, r1
	strh r0, [r2]
_0818ED10:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818EA84

	thumb_func_start sub_818ED28
sub_818ED28: @ 818ED28
	push {r4,r5,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r4, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x8
	bls _0818ED4C
	b _0818F01E
_0818ED4C:
	lsls r0, 2
	ldr r1, =_0818ED6C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0818ED6C:
	.4byte _0818ED90
	.4byte _0818EDB4
	.4byte _0818EE10
	.4byte _0818EE34
	.4byte _0818EE5C
	.4byte _0818EE78
	.4byte _0818EEA0
	.4byte _0818EF50
	.4byte _0818F008
_0818ED90:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r0, r4, 1
	lsls r1, r5, 2
	adds r0, r1
	ldr r1, =0x00000d0c
	adds r2, r1
	adds r2, r0
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	strh r0, [r2]
	b _0818F01E
	.pool
_0818EDB4:
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _0818EDE8
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_0860D0EC
	lsls r1, r4, 2
	lsls r0, r5, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	orrs r0, r1
	str r0, [r2]
	b _0818F01E
	.pool
_0818EDE8:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000cdc
	adds r2, r1
	ldr r3, =gUnknown_0860D0FC
	lsls r1, r4, 2
	lsls r0, r5, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	ands r0, r1
	str r0, [r2]
	b _0818F01E
	.pool
_0818EE10:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =0x00000d08
	adds r2, r1
	movs r1, 0x1
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x2
	negs r0, r0
	b _0818EF74
	.pool
_0818EE34:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r3]
	movs r0, 0x3
	negs r0, r0
	b _0818EFF4
	.pool
_0818EE5C:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =0x00000d08
	adds r3, r1
	b _0818EFE8
	.pool
_0818EE78:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3]
	movs r0, 0x9
	negs r0, r0
	b _0818EFF4
	.pool
_0818EEA0:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1
	bne _0818EF00
	cmp r4, 0
	beq _0818EEDC
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r3]
	movs r0, 0x21
	negs r0, r0
	b _0818EFF4
	.pool
_0818EEDC:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
	ands r1, r0
	lsls r1, 4
	ldrb r2, [r3]
	movs r0, 0x11
	negs r0, r0
	b _0818EFF4
	.pool
_0818EF00:
	cmp r4, 0
	beq _0818EF2C
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =0x00000d08
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r3]
	movs r0, 0x3
	negs r0, r0
	b _0818EFF4
	.pool
_0818EF2C:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =0x00000d08
	adds r2, r1
	movs r1, 0x1
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x2
	negs r0, r0
	b _0818EF74
	.pool
_0818EF50:
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x1
	bne _0818EFB0
	cmp r4, 0
	beq _0818EF8C
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r1, [r0]
	ldr r0, =0x00000d08
	adds r2, r0
	lsls r1, 7
	ldrb r3, [r2]
	movs r0, 0x7F
_0818EF74:
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	b _0818F01E
	.pool
_0818EF8C:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r3]
	movs r0, 0x41
	negs r0, r0
	b _0818EFF4
	.pool
_0818EFB0:
	cmp r4, 0
	beq _0818EFDC
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =0x00000d08
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3]
	movs r0, 0x9
	negs r0, r0
	b _0818EFF4
	.pool
_0818EFDC:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r2, =0x00000d08
	adds r3, r2
_0818EFE8:
	movs r1, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
_0818EFF4:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _0818F01E
	.pool
_0818F008:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =gUnknown_0203CEF8
	ldrb r1, [r0]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0xCB
	lsls r0, 4
	adds r2, r0
	strh r1, [r2]
_0818F01E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818ED28

	thumb_func_start sub_818F02C
sub_818F02C: @ 818F02C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0x20
	bl AllocZeroed
	str r0, [sp, 0x18]
	movs r0, 0x18
	bl AllocZeroed
	str r0, [sp, 0x1C]
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	adds r0, 0x1
	ldr r3, =0x00000d0a
	adds r1, r3
	strb r0, [r1]
	ldr r0, =0x000040ce
	bl VarGet
	ldr r1, [r4]
	adds r0, 0x1
	ldr r5, =0x00000d0b
	adds r1, r5
	strb r0, [r1]
	ldr r2, [r4]
	ldr r7, =0x00000d24
	adds r3, r2, r7
	ldrh r0, [r3]
	ldr r5, =0x000003ff
	adds r1, r5, 0
	orrs r0, r1
	strh r0, [r3]
	ldr r3, =0x00000d25
	adds r2, r3
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r4]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x19
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	strb r0, [r1]
	movs r7, 0
	mov r10, r7
	mov r8, r4
	ldr r0, =gBattleScripting + 0x14
	mov r9, r0
	movs r4, 0
_0818F0BA:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00000caa
	adds r0, r2
	adds r0, r4
	ldrh r0, [r0]
	movs r3, 0x64
	muls r0, r3
	add r0, r9
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	mov r5, r8
	ldr r1, [r5]
	ldr r7, =0x00000d64
	adds r1, r7
	adds r1, r4
	strh r0, [r1]
	movs r5, 0
	mov r0, r10
	lsls r7, r0, 4
	adds r6, r7, 0
_0818F0E8:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00000caa
	adds r0, r2
	adds r0, r4
	ldrh r0, [r0]
	movs r3, 0x64
	muls r0, r3
	add r0, r9
	adds r1, r5, 0
	adds r1, 0xD
	movs r2, 0
	bl GetMonData
	mov r2, r8
	ldr r1, [r2]
	ldr r3, =0x00000efc
	adds r1, r3
	adds r1, r6
	strh r0, [r1]
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0818F0E8
	movs r5, 0
	ldr r6, =gSaveBlock2Ptr
_0818F11C:
	ldr r0, [r6]
	ldr r1, =0x00000caa
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	movs r2, 0x64
	muls r0, r2
	add r0, r9
	adds r1, r5, 0
	adds r1, 0x1A
	movs r2, 0
	bl GetMonData
	ldr r1, [r6]
	adds r2, r5, r7
	ldr r3, =0x00000f04
	adds r1, r3
	adds r1, r2
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x5
	ble _0818F11C
	mov r5, r8
	ldr r0, [r5]
	ldr r1, =0x00000caa
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	movs r2, 0x64
	muls r0, r2
	add r0, r9
	bl GetNature
	ldr r1, [r5]
	adds r1, r7
	ldr r3, =0x00000f0a
	adds r1, r3
	strb r0, [r1]
	adds r4, 0x2
	movs r5, 0x1
	add r10, r5
	mov r7, r10
	cmp r7, 0x2
	ble _0818F0BA
	mov r10, r5
	movs r0, 0x4
	str r0, [sp, 0x34]
	movs r1, 0x6
	str r1, [sp, 0x38]
_0818F17E:
	mov r2, r10
	cmp r2, 0x5
	ble _0818F22C
_0818F184:
	bl sub_81A39C4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8162548
	lsls r0, 16
	lsrs r4, r0, 16
	movs r5, 0x1
	cmp r5, r10
	bge _0818F1CA
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r7, =0x00000d28
	adds r0, r7
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	adds r2, r3, 0
	cmp r0, r4
	beq _0818F1CA
	ldr r3, =0x00000d24
_0818F1B2:
	adds r5, 0x1
	cmp r5, r10
	bge _0818F1CA
	ldr r0, [r2]
	lsls r1, r5, 2
	adds r0, r1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r4
	bne _0818F1B2
_0818F1CA:
	cmp r5, r10
	bne _0818F184
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, [sp, 0x34]
	adds r3, r1
	ldr r2, =0x00000d24
	adds r3, r2
	ldr r5, =0x000003ff
	adds r0, r5, 0
	adds r2, r4, 0
	ands r2, r0
	ldrh r0, [r3]
	ldr r7, =0xfffffc00
	adds r1, r7, 0
	b _0818F292
	.pool
_0818F22C:
	bl sub_81A39C4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8162548
	lsls r0, 16
	lsrs r4, r0, 16
	movs r5, 0x1
	cmp r5, r10
	bge _0818F274
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000d28
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	adds r2, r1, 0
	cmp r0, r4
	beq _0818F274
	ldr r3, =0x00000d24
_0818F25C:
	adds r5, 0x1
	cmp r5, r10
	bge _0818F274
	ldr r0, [r2]
	lsls r1, r5, 2
	adds r0, r1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r4
	bne _0818F25C
_0818F274:
	cmp r5, r10
	bne _0818F22C
	ldr r5, =gSaveBlock2Ptr
	ldr r3, [r5]
	ldr r7, [sp, 0x34]
	adds r3, r7
	ldr r0, =0x00000d24
	adds r3, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	adds r2, r4, 0
	ands r2, r0
	ldrh r0, [r3]
	ldr r5, =0xfffffc00
	adds r1, r5, 0
_0818F292:
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	movs r5, 0
	lsls r4, 16
	str r4, [sp, 0x2C]
	ldr r7, [sp, 0x38]
	str r7, [sp, 0x20]
_0818F2A2:
	lsls r0, r5, 1
	mov r9, r0
	adds r1, r5, 0x1
	str r1, [sp, 0x24]
	lsls r2, r5, 2
	str r2, [sp, 0x28]
_0818F2AE:
	ldr r3, [sp, 0x2C]
	lsrs r0, r3, 16
	bl sub_8163524
	lsls r0, 16
	lsrs r6, r0, 16
	movs r7, 0
	cmp r7, r5
	bge _0818F300
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, [sp, 0x8]
	mov r8, r1
	ldr r2, [sp, 0xC]
	mov r12, r2
	ldr r3, =0x00000d64
	adds r0, r3
	ldr r1, [sp, 0x20]
	adds r4, r1, r0
_0818F2D4:
	ldrh r3, [r4]
	cmp r3, r6
	beq _0818F300
	ldr r2, =gUnknown_0203BC8C
	ldr r1, [r2]
	lsls r0, r6, 4
	adds r2, r0, r1
	ldrh r0, [r2]
	cmp r8, r0
	beq _0818F300
	cmp r12, r0
	beq _0818F300
	lsls r0, r3, 4
	adds r0, r1
	ldrb r0, [r0, 0xA]
	ldrb r2, [r2, 0xA]
	cmp r0, r2
	beq _0818F300
	adds r4, 0x2
	adds r7, 0x1
	cmp r7, r5
	blt _0818F2D4
_0818F300:
	cmp r7, r5
	bne _0818F2AE
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r1, [sp, 0x38]
	add r1, r9
	ldr r5, =0x00000d64
	adds r0, r5
	adds r0, r1
	strh r6, [r0]
	ldr r2, [sp, 0x28]
	add r2, sp
	adds r2, 0x8
	ldr r0, =gUnknown_0203BC8C
	ldr r1, [r0]
	lsls r0, r6, 4
	adds r0, r1
	ldrh r0, [r0]
	str r0, [r2]
	ldr r5, [sp, 0x24]
	cmp r5, 0x2
	ble _0818F2A2
	ldr r2, [r3]
	ldr r7, [sp, 0x34]
	adds r2, r7
	ldr r0, =0x00000d25
	adds r2, r0
	ldrb r0, [r2]
	movs r3, 0x5
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
	ldr r5, =gSaveBlock2Ptr
	ldr r2, [r5]
	adds r2, r7
	ldr r7, =0x00000d25
	adds r2, r7
	ldrb r0, [r2]
	subs r3, 0x14
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r5]
	ldr r5, [sp, 0x34]
	adds r1, r5
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	strb r0, [r1]
	adds r5, 0x4
	str r5, [sp, 0x34]
	ldr r7, [sp, 0x38]
	adds r7, 0x6
	str r7, [sp, 0x38]
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0xF
	bgt _0818F37C
	b _0818F17E
_0818F37C:
	movs r7, 0
	ldr r2, [sp, 0x18]
	strh r7, [r2]
	movs r3, 0
	mov r10, r3
	ldr r6, =gBitTable
	ldr r5, =gBaseStats
_0818F38A:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	mov r2, r10
	lsls r1, r2, 1
	ldr r3, =0x00000caa
	adds r0, r3
	adds r0, r1
	ldrh r0, [r0]
	subs r4, r0, 0x1
	movs r0, 0x64
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	ldr r2, [sp, 0x18]
	ldrh r1, [r2]
	adds r1, r0
	strh r1, [r2]
	adds r0, r4, 0
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	ldr r3, [sp, 0x18]
	ldrh r1, [r3]
	adds r1, r0
	strh r1, [r3]
	adds r0, r4, 0
	movs r1, 0x3E
	movs r2, 0
	bl GetMonData
	ldr r2, [sp, 0x18]
	ldrh r1, [r2]
	adds r1, r0
	strh r1, [r2]
	adds r0, r4, 0
	movs r1, 0x3F
	movs r2, 0
	bl GetMonData
	ldr r3, [sp, 0x18]
	ldrh r1, [r3]
	adds r1, r0
	strh r1, [r3]
	adds r0, r4, 0
	movs r1, 0x3D
	movs r2, 0
	bl GetMonData
	ldr r2, [sp, 0x18]
	ldrh r1, [r2]
	adds r1, r0
	strh r1, [r2]
	adds r0, r4, 0
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	ldr r3, [sp, 0x18]
	ldrh r1, [r3]
	adds r1, r0
	strh r1, [r3]
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x6]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	orrs r7, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x7]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	orrs r7, r0
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x2
	ble _0818F38A
	movs r4, 0
	movs r1, 0x1
	movs r5, 0x1F
_0818F458:
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0818F462
	adds r4, 0x1
_0818F462:
	asrs r7, 1
	subs r5, 0x1
	cmp r5, 0
	bge _0818F458
	bl sub_8165C40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	adds r2, r0, 0
	adds r0, r4, 0
	muls r0, r2
	movs r1, 0x14
	bl __divsi3
	ldr r3, [sp, 0x18]
	ldrh r1, [r3]
	adds r1, r0
	strh r1, [r3]
	movs r5, 0x1
	mov r10, r5
	adds r6, r3, 0
	adds r6, 0x2
	movs r7, 0x2
	str r7, [sp, 0x30]
_0818F494:
	movs r7, 0
	strh r7, [r6]
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	mov r2, r10
	lsls r1, r2, 2
	adds r0, r1
	ldr r3, =0x00000d24
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	bl sub_8190168
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r0, [sp, 0x30]
	mov r9, r0
_0818F4BC:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	mov r4, r9
	add r4, r10
	adds r4, r5
	lsls r4, 1
	ldr r2, =0x00000d64
	adds r0, r2
	adds r0, r4
	ldrh r1, [r0]
	ldr r3, =gUnknown_0203BC8C
	ldr r0, [r3]
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrb r3, [r1, 0xB]
	ldrb r1, [r1, 0xC]
	str r1, [sp]
	ldr r1, [sp, 0x1C]
	str r1, [sp, 0x4]
	ldr r1, [sp, 0x14]
	mov r2, r8
	bl sub_818F720
	ldr r2, [sp, 0x1C]
	ldr r1, [r2, 0x4]
	ldrh r0, [r6]
	adds r0, r1
	ldr r1, [r2, 0x8]
	adds r0, r1
	ldr r1, [r2, 0x10]
	adds r0, r1
	ldr r1, [r2, 0x14]
	adds r0, r1
	ldr r1, [r2, 0xC]
	adds r0, r1
	ldr r1, [r2]
	adds r0, r1
	strh r0, [r6]
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r1, =0x00000d64
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	ldr r2, =gUnknown_0203BC8C
	ldr r1, [r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r3, =gBaseStats
	adds r1, r3
	ldrb r0, [r1, 0x6]
	lsls r0, 2
	ldr r2, =gBitTable
	adds r0, r2
	ldr r0, [r0]
	orrs r7, r0
	ldrb r0, [r1, 0x7]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	orrs r7, r0
	adds r5, 0x1
	cmp r5, 0x2
	ble _0818F4BC
	movs r4, 0
	movs r1, 0x1
	movs r5, 0x1F
_0818F54C:
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0818F556
	adds r4, 0x1
_0818F556:
	asrs r7, 1
	subs r5, 0x1
	cmp r5, 0
	bge _0818F54C
	ldr r3, [sp, 0x14]
	adds r0, r4, 0
	muls r0, r3
	movs r1, 0x14
	bl __divsi3
	ldrh r1, [r6]
	adds r1, r0
	strh r1, [r6]
	adds r6, 0x2
	ldr r5, [sp, 0x30]
	adds r5, 0x2
	str r5, [sp, 0x30]
	movs r7, 0x1
	add r10, r7
	mov r0, r10
	cmp r0, 0xF
	ble _0818F494
	movs r1, 0
	mov r10, r1
	ldr r2, =0x000003ff
	mov r8, r2
_0818F58A:
	mov r5, r10
	adds r5, 0x1
	adds r7, r5, 0
	cmp r5, 0xF
	bgt _0818F626
	mov r3, r10
	lsls r0, r3, 1
	ldr r1, [sp, 0x18]
	adds r6, r0, r1
	lsls r0, r5, 1
	adds r4, r0, r1
_0818F5A0:
	ldrh r1, [r6]
	ldrh r0, [r4]
	cmp r1, r0
	bcc _0818F5C2
	cmp r1, r0
	bne _0818F61E
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r1, r0
	ldr r2, =0x00000d24
	adds r0, r2
	ldrh r0, [r0]
	lsls r2, r0, 22
	lsrs r0, r2, 22
	cmp r0, r8
	bne _0818F602
_0818F5C2:
	mov r0, r10
	adds r1, r5, 0
	ldr r2, [sp, 0x18]
	bl sub_818F904
	b _0818F600
	.pool
_0818F600:
	b _0818F61E
_0818F602:
	mov r3, r10
	lsls r0, r3, 2
	adds r0, r1, r0
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	cmp r0, r2
	bls _0818F61E
	mov r0, r10
	adds r1, r5, 0
	ldr r2, [sp, 0x18]
	bl sub_818F904
_0818F61E:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0xF
	ble _0818F5A0
_0818F626:
	mov r10, r7
	mov r2, r10
	cmp r2, 0xE
	ble _0818F58A
	bl sub_81A3610
	lsls r0, 24
	cmp r0, 0
	beq _0818F6EE
	movs r3, 0
	mov r10, r3
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r4, =0x00000d24
	adds r1, r4
	ldrh r1, [r1]
	lsls r1, 22
	lsrs r1, 22
	ldr r3, =0x000003ff
	adds r2, r0, 0
	ldr r6, =gUnknown_0860D3F1
	cmp r1, r3
	beq _0818F674
	adds r5, r2, 0
_0818F656:
	movs r7, 0x1
	add r10, r7
	mov r0, r10
	cmp r0, 0xF
	bgt _0818F674
	ldr r0, [r5]
	mov r7, r10
	lsls r1, r7, 2
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r3
	bne _0818F656
_0818F674:
	mov r1, r10
	lsls r0, r1, 1
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _0818F6AC
	movs r5, 0
	ldr r2, [r2]
	ldr r3, =0x00000d24
	adds r2, r3
	ldrh r1, [r2]
	ldr r0, =0xfffffc00
	ands r0, r1
	ldr r7, =0x000003fe
	adds r1, r7, 0
	b _0818F6BE
	.pool
_0818F6AC:
	movs r5, 0x1
	ldr r2, [r2]
	ldr r0, =0x00000d28
	adds r2, r0
	ldrh r1, [r2]
	ldr r0, =0xfffffc00
	ands r0, r1
	ldr r3, =0x000003fe
	adds r1, r3, 0
_0818F6BE:
	orrs r0, r1
	strh r0, [r2]
	movs r7, 0
	mov r10, r7
	lsls r0, r5, 1
	adds r0, r5
	lsls r4, r0, 1
_0818F6CC:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81A4FF0
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r2, =0x00000d64
	adds r1, r2
	adds r1, r4
	strh r0, [r1]
	adds r4, 0x2
	movs r3, 0x1
	add r10, r3
	mov r5, r10
	cmp r5, 0x2
	ble _0818F6CC
_0818F6EE:
	ldr r0, [sp, 0x18]
	bl Free
	ldr r0, [sp, 0x1C]
	bl Free
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818F02C

	thumb_func_start sub_818F720
sub_818F720: @ 818F720
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r1, 0
	mov r9, r2
	ldr r1, [sp, 0x3C]
	ldr r2, [sp, 0x40]
	mov r8, r2
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x18]
	movs r1, 0
	adds r4, r5, 0
	movs r3, 0x1
	movs r2, 0x5
_0818F74C:
	adds r0, r4, 0
	ands r0, r3
	cmp r0, 0
	beq _0818F756
	adds r1, 0x1
_0818F756:
	lsrs r4, 1
	subs r2, 0x1
	cmp r2, 0
	bge _0818F74C
	movs r0, 0xFF
	lsls r0, 1
	bl __divsi3
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r0, r6, 3
	mov r10, r0
	movs r1, 0
	mov r12, r1
	mov r1, sp
	movs r2, 0x5
_0818F776:
	mov r0, r12
	str r0, [r1]
	adds r0, r5, 0
	ands r0, r4
	cmp r0, 0
	beq _0818F784
	str r3, [r1]
_0818F784:
	lsls r0, r4, 25
	lsrs r4, r0, 24
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0818F776
	ldr r0, =0x0000012f
	cmp r6, r0
	bne _0818F7A0
	movs r0, 0x1
	b _0818F7CA
	.pool
_0818F7A0:
	mov r2, r10
	subs r0, r2, r6
	lsls r0, 2
	ldr r1, =gBaseStats
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	mov r2, r9
	adds r1, r0, r2
	ldr r0, [sp]
	cmp r0, 0
	bge _0818F7BA
	adds r0, 0x3
_0818F7BA:
	asrs r0, 2
	adds r0, r1, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r0, r7
	adds r0, 0xA
_0818F7CA:
	mov r1, r8
	str r0, [r1]
	mov r2, r10
	subs r0, r2, r6
	lsls r0, 2
	ldr r1, =gBaseStats
	adds r4, r0, r1
	ldrb r0, [r4, 0x1]
	lsls r0, 1
	mov r2, r9
	adds r1, r0, r2
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _0818F7E8
	adds r0, 0x3
_0818F7E8:
	asrs r0, 2
	adds r0, r1, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	adds r1, 0x5
	mov r0, r8
	str r1, [r0, 0x4]
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	movs r2, 0x1
	bl ModifyStatByNature
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	str r0, [r1, 0x4]
	ldrb r0, [r4, 0x2]
	lsls r0, 1
	mov r2, r9
	adds r1, r0, r2
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _0818F820
	adds r0, 0x3
_0818F820:
	asrs r0, 2
	adds r0, r1, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	adds r1, 0x5
	mov r0, r8
	str r1, [r0, 0x8]
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	movs r2, 0x2
	bl ModifyStatByNature
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	str r0, [r1, 0x8]
	ldrb r0, [r4, 0x3]
	lsls r0, 1
	mov r2, r9
	adds r1, r0, r2
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bge _0818F858
	adds r0, 0x3
_0818F858:
	asrs r0, 2
	adds r0, r1, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	adds r1, 0x5
	mov r0, r8
	str r1, [r0, 0xC]
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	movs r2, 0x3
	bl ModifyStatByNature
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	str r0, [r1, 0xC]
	ldrb r0, [r4, 0x4]
	lsls r0, 1
	mov r2, r9
	adds r1, r0, r2
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bge _0818F890
	adds r0, 0x3
_0818F890:
	asrs r0, 2
	adds r0, r1, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	adds r1, 0x5
	mov r0, r8
	str r1, [r0, 0x10]
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	movs r2, 0x4
	bl ModifyStatByNature
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	str r0, [r1, 0x10]
	ldrb r0, [r4, 0x5]
	lsls r0, 1
	mov r1, r9
	adds r2, r0, r1
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bge _0818F8C8
	adds r0, 0x3
_0818F8C8:
	asrs r0, 2
	adds r0, r2, r0
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	adds r1, 0x5
	mov r2, r8
	str r1, [r2, 0x14]
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	movs r2, 0x5
	bl ModifyStatByNature
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	str r0, [r1, 0x14]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818F720

	thumb_func_start sub_818F904
sub_818F904: @ 818F904
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r3, r0, 1
	mov r12, r3
	adds r4, r3, r2
	ldrh r5, [r4]
	lsls r7, r1, 1
	mov r9, r7
	add r2, r9
	ldrh r3, [r2]
	strh r3, [r4]
	strh r5, [r2]
	ldr r2, =gSaveBlock2Ptr
	ldr r5, [r2]
	lsls r6, r0, 2
	adds r6, r5, r6
	ldr r3, =0x00000d24
	adds r6, r3
	ldrh r7, [r6]
	mov r10, r7
	mov r2, r10
	lsls r2, 22
	mov r8, r2
	lsls r2, r1, 2
	adds r5, r2
	adds r5, r3
	ldrh r4, [r5]
	lsls r4, 22
	lsrs r4, 22
	ldr r3, =0xfffffc00
	adds r2, r3, 0
	mov r7, r10
	ands r2, r7
	orrs r2, r4
	strh r2, [r6]
	mov r2, r8
	lsrs r2, 22
	mov r8, r2
	ldrh r2, [r5]
	ands r3, r2
	mov r7, r8
	orrs r3, r7
	strh r3, [r5]
	ldr r2, =gSaveBlock2Ptr
	mov r8, r2
	add r12, r0
	add r9, r1
	mov r3, r9
	lsls r4, r3, 1
	mov r7, r12
	lsls r3, r7, 1
	ldr r7, =0x00000d64
	movs r6, 0x2
_0818F974:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r7
	adds r2, r0, r3
	ldrh r5, [r2]
	adds r0, r4
	ldrh r1, [r0]
	strh r1, [r2]
	strh r5, [r0]
	adds r4, 0x2
	adds r3, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _0818F974
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818F904

	thumb_func_start sub_818F9B0
sub_818F9B0: @ 818F9B0
	push {lr}
	ldr r0, =gStringVar1
	ldr r2, =gRoundsStringTable
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r3, =0x00000cb2
	adds r1, r3
	ldrh r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818F9B0

	thumb_func_start sub_818F9E0
sub_818F9E0: @ 818F9E0
	push {lr}
	ldr r0, =gStringVar1
	ldr r2, =gRoundsStringTable
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r3, =0x00000cb2
	adds r1, r3
	ldrh r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, =gTrainerBattleOpponent_A
	ldrh r1, [r1]
	bl sub_8195898
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818F9E0

	thumb_func_start sub_818FA20
sub_818FA20: @ 818FA20
	push {r4,r5,lr}
	ldr r1, =gUnknown_0203CD70
	movs r0, 0
	str r0, [r1]
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	ldr r5, =gUnknown_0203CD74
	str r0, [r5]
	adds r4, 0x64
	adds r0, r4, 0
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	ldr r1, [r5]
	adds r1, r0
	str r1, [r5]
	bl CalculatePlayerPartyCount
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_8195358
	lsls r0, 16
	lsrs r0, 16
	bl sub_818FBDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818FA20

	thumb_func_start sub_818FA74
sub_818FA74: @ 818FA74
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r5, r2, 0
	str r3, [sp, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x28]
	lsls r5, 24
	lsrs r5, 24
	add r0, sp, 0xC
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r0, [sp, 0x28]
	bl sub_8190168
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x2C]
	bl sub_8165C40
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x64
	ldr r4, [sp, 0x10]
	adds r3, r4, 0
	muls r3, r0
	str r3, [sp, 0x18]
	ldr r6, =gEnemyParty
	adds r0, r3, r6
	ldr r7, =gSaveBlock2Ptr
	ldr r4, [r7]
	lsls r5, 1
	ldr r3, [sp, 0x28]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 1
	adds r1, r5, r1
	ldr r6, =0x00000d64
	adds r4, r6
	adds r4, r1
	ldrh r3, [r4]
	ldr r7, =gUnknown_0203BC8C
	ldr r7, [r7]
	mov r8, r7
	lsls r3, 4
	add r3, r8
	ldrh r1, [r3]
	ldrb r3, [r3, 0xC]
	ldr r6, [sp, 0x2C]
	str r6, [sp]
	ldrh r4, [r4]
	lsls r4, 4
	add r4, r8
	ldrb r4, [r4, 0xB]
	str r4, [sp, 0x4]
	ldr r7, [sp, 0x14]
	str r7, [sp, 0x8]
	bl CreateMonWithEVSpreadPersonalityOTID
	add r0, sp, 0xC
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	movs r6, 0
	ldr r2, [sp, 0x18]
	str r2, [sp, 0x1C]
	mov r10, r5
	ldr r3, =0x00000d64
	mov r9, r3
	ldr r3, =gUnknown_0203BC8C
	mov r4, r10
	str r4, [sp, 0x20]
_0818FB18:
	ldr r7, =gSaveBlock2Ptr
	ldr r1, [r7]
	ldr r2, [sp, 0x28]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	mov r8, r0
	mov r5, r10
	add r5, r8
	add r1, r9
	adds r1, r5
	ldrh r0, [r1]
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	lsls r4, r6, 1
	adds r0, 0x2
	adds r0, r4
	ldrh r1, [r0]
	lsls r2, r6, 24
	lsrs r2, 24
	mov r12, r2
	ldr r7, [sp, 0x1C]
	ldr r2, =gEnemyParty
	adds r0, r7, r2
	mov r2, r12
	str r3, [sp, 0x24]
	bl SetMonMoveSlot
	ldr r7, =gSaveBlock2Ptr
	ldr r0, [r7]
	add r0, r9
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, [sp, 0x24]
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	adds r0, 0x2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0xDA
	bne _0818FB74
	movs r1, 0
	add r0, sp, 0xC
	strb r1, [r0]
_0818FB74:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0818FB18
	movs r0, 0x64
	ldr r1, [sp, 0x10]
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0xC
	bl SetMonData
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, [sp, 0x20]
	add r1, r8
	ldr r2, =0x00000d64
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gUnknown_0203BC8C
	ldr r1, [r1]
	lsls r0, 4
	adds r0, r1
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818FA74

	thumb_func_start sub_818FBDC
sub_818FBDC: @ 818FBDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	movs r6, 0
	bl ZeroEnemyPartyMons
	mov r0, r8
	bl sub_818FC78
	adds r5, r0, 0
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r7, r4, 16
	lsls r0, 16
	orrs r7, r0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _0818FC46
	movs r4, 0
_0818FC20:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0818FC3C
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r6, 0
	mov r1, r8
	adds r3, r7, 0
	bl sub_818FA74
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0818FC3C:
	asrs r5, 1
	adds r4, 0x1
	cmp r4, 0x2
	ble _0818FC20
	b _0818FC6C
_0818FC46:
	movs r4, 0x2
_0818FC48:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _0818FC64
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r6, 0
	mov r1, r8
	adds r3, r7, 0
	bl sub_818FA74
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0818FC64:
	lsls r5, 1
	subs r4, 0x1
	cmp r4, 0
	bge _0818FC48
_0818FC6C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_818FBDC

	thumb_func_start sub_818FC78
sub_818FC78: @ 818FC78
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0818FCA2
	adds r0, r4, 0
	movs r1, 0
	bl sub_818FCBC
	cmp r0, 0
	bne _0818FCB6
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_818FDB8
	b _0818FCB6
_0818FCA2:
	adds r0, r5, 0
	movs r1, 0
	bl sub_818FDB8
	cmp r0, 0
	bne _0818FCB6
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_818FCBC
_0818FCB6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818FC78

	thumb_func_start sub_818FCBC
sub_818FCBC: @ 818FCBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	movs r0, 0
	mov r9, r0
	mov r1, r8
	lsls r1, 2
	str r1, [sp, 0x18]
_0818FCDE:
	mov r2, r9
	lsls r0, r2, 2
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0
	str r0, [r1]
	movs r7, 0
	mov r0, r9
	adds r0, 0x1
	str r0, [sp, 0x14]
	adds r5, r1, 0
	mov r1, r9
	lsls r1, 1
	str r1, [sp, 0x10]
_0818FCFA:
	movs r6, 0
	adds r2, r7, 0x1
	mov r10, r2
_0818FD00:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, [sp, 0x18]
	adds r0, r1, r2
	ldr r2, =0x00000d24
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	ldr r2, =0x000003fe
	cmp r0, r2
	bne _0818FD3C
	mov r1, r9
	lsls r0, r1, 24
	lsls r1, r7, 24
	lsrs r0, 24
	lsrs r1, 24
	bl sub_81A5060
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	b _0818FD60
	.pool
_0818FD3C:
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 1
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r2, =0x00000d64
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r1, [r1]
	lsls r0, 4
	adds r0, r1
	lsls r1, r7, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r4, [r0]
_0818FD60:
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl sub_818FFC0
	ldr r1, [r5]
	adds r1, r0
	str r1, [r5]
	adds r6, 0x1
	cmp r6, 0x2
	ble _0818FD00
	mov r7, r10
	cmp r7, 0x3
	ble _0818FCFA
	ldr r0, [sp, 0x14]
	mov r9, r0
	cmp r0, 0x2
	ble _0818FCDE
	mov r0, sp
	ldr r1, [sp, 0xC]
	bl sub_818FEB4
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818FCBC

	thumb_func_start sub_818FDB8
sub_818FDB8: @ 818FDB8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	movs r0, 0
	mov r9, r0
	mov r1, r8
	lsls r1, 2
	str r1, [sp, 0x18]
_0818FDDA:
	mov r2, r9
	lsls r0, r2, 2
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0
	str r0, [r1]
	movs r7, 0
	mov r0, r9
	adds r0, 0x1
	str r0, [sp, 0x14]
	adds r5, r1, 0
	mov r1, r9
	lsls r1, 1
	str r1, [sp, 0x10]
_0818FDF6:
	movs r6, 0
	adds r2, r7, 0x1
	mov r10, r2
_0818FDFC:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, [sp, 0x18]
	adds r0, r1, r2
	ldr r2, =0x00000d24
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	ldr r2, =0x000003fe
	cmp r0, r2
	bne _0818FE38
	mov r1, r9
	lsls r0, r1, 24
	lsls r1, r7, 24
	lsrs r0, 24
	lsrs r1, 24
	bl sub_81A5060
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	b _0818FE5C
	.pool
_0818FE38:
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 1
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r2, =0x00000d64
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r1, [r1]
	lsls r0, 4
	adds r0, r1
	lsls r1, r7, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r4, [r0]
_0818FE5C:
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_818FFC0
	ldr r1, [r5]
	adds r1, r0
	str r1, [r5]
	adds r6, 0x1
	cmp r6, 0x2
	ble _0818FDFC
	mov r7, r10
	cmp r7, 0x3
	ble _0818FDF6
	ldr r0, [sp, 0x14]
	mov r9, r0
	cmp r0, 0x2
	ble _0818FDDA
	mov r0, sp
	ldr r1, [sp, 0xC]
	bl sub_818FEB4
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818FDB8

	thumb_func_start sub_818FEB4
sub_818FEB4: @ 818FEB4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	str r0, [sp, 0xC]
	movs r3, 0x2
	add r0, sp, 0x8
_0818FECE:
	str r3, [r0]
	subs r0, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0818FECE
	mov r3, r10
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	cmp r2, r0
	bne _0818FF20
	ldr r0, [r3, 0x8]
	cmp r2, r0
	bne _0818FF20
	cmp r1, 0
	beq _0818FFAA
	movs r3, 0
	ldr r4, =gBitTable
_0818FEF0:
	str r3, [sp, 0x14]
	bl Random
	movs r1, 0x3
	ands r1, r0
	ldr r3, [sp, 0x14]
	cmp r1, 0x3
	beq _0818FF16
	lsls r0, r1, 2
	adds r0, r4
	ldr r1, [r0]
	ldr r0, [sp, 0xC]
	ands r0, r1
	cmp r0, 0
	bne _0818FF16
	ldr r0, [sp, 0xC]
	orrs r0, r1
	str r0, [sp, 0xC]
	adds r3, 0x1
_0818FF16:
	cmp r3, 0x2
	bne _0818FEF0
	b _0818FFAA
	.pool
_0818FF20:
	movs r3, 0
	mov r9, sp
	mov r8, r10
_0818FF26:
	adds r2, r3, 0x1
	cmp r2, 0x2
	bgt _0818FF84
	mov r6, r8
	mov r7, r9
	lsls r0, r2, 2
	mov r1, sp
	adds r5, r0, r1
	mov r1, r10
	adds r4, r0, r1
_0818FF3A:
	ldr r0, [r6]
	ldr r1, [r4]
	cmp r0, r1
	bge _0818FF4E
	str r1, [r6]
	str r0, [r4]
	ldr r1, [r7]
	ldr r0, [r5]
	str r0, [r7]
	str r1, [r5]
_0818FF4E:
	ldr r1, [r6]
	ldr r0, [r4]
	cmp r1, r0
	bne _0818FF7A
	str r2, [sp, 0x10]
	str r3, [sp, 0x14]
	bl Random
	movs r1, 0x1
	ands r1, r0
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	cmp r1, 0
	beq _0818FF7A
	ldr r1, [r6]
	ldr r0, [r4]
	str r0, [r6]
	str r1, [r4]
	ldr r1, [r7]
	ldr r0, [r5]
	str r0, [r7]
	str r1, [r5]
_0818FF7A:
	adds r5, 0x4
	adds r4, 0x4
	adds r2, 0x1
	cmp r2, 0x2
	ble _0818FF3A
_0818FF84:
	movs r4, 0x4
	add r9, r4
	add r8, r4
	adds r3, 0x1
	cmp r3, 0x1
	ble _0818FF26
	ldr r2, =gBitTable
	mov r1, sp
	movs r3, 0x1
_0818FF96:
	ldm r1!, {r0}
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldr r4, [sp, 0xC]
	orrs r4, r0
	str r4, [sp, 0xC]
	subs r3, 0x1
	cmp r3, 0
	bge _0818FF96
_0818FFAA:
	ldr r0, [sp, 0xC]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818FEB4

	thumb_func_start sub_818FFC0
sub_818FFC0: @ 818FFC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	movs r6, 0
	movs r2, 0x14
	cmp r3, 0
	beq _0818FFF0
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _0818FFF0
	ldr r0, =gBattleMoves
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3, 0x1]
	cmp r0, 0
	bne _0818FFFC
_0818FFF0:
	movs r0, 0
	b _08190156
	.pool
_0818FFFC:
	ldr r1, =gBaseStats
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x6]
	mov r10, r1
	ldrb r1, [r0, 0x7]
	mov r9, r1
	ldrb r0, [r0, 0x16]
	mov r8, r0
	ldrb r3, [r3, 0x2]
	str r3, [sp, 0x4]
	cmp r0, 0x1A
	bne _0819002C
	cmp r3, 0x4
	bne _0819002C
	ldr r0, [sp]
	cmp r0, 0x1
	bne _081900AA
	movs r2, 0x8
	b _081900A4
	.pool
_0819002C:
	ldr r0, =gTypeEffectiveness
	adds r1, r6, r0
	ldrb r0, [r1]
	ldr r7, =gTypeEffectiveness
	cmp r0, 0xFF
	beq _081900A4
	adds r4, r1, 0
_0819003A:
	ldrb r0, [r4]
	cmp r0, 0xFE
	beq _08190096
	ldrb r0, [r4]
	ldr r1, [sp, 0x4]
	cmp r0, r1
	bne _08190096
	ldrb r0, [r4, 0x1]
	adds r5, r6, 0x1
	cmp r0, r10
	bne _0819006C
	adds r1, r6, 0x2
	mov r0, r8
	cmp r0, 0x19
	bne _0819005E
	ldrb r0, [r4, 0x2]
	cmp r0, 0x28
	bne _0819006C
_0819005E:
	adds r0, r1, r7
	ldrb r0, [r0]
	muls r0, r2
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
_0819006C:
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, r9
	bne _08190096
	cmp r10, r9
	beq _08190096
	adds r1, r6, 0x2
	mov r0, r8
	cmp r0, 0x19
	bne _08190088
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0x28
	bne _08190096
_08190088:
	adds r0, r1, r7
	ldrb r0, [r0]
	muls r0, r2
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
_08190096:
	adds r4, 0x3
	adds r6, 0x3
	ldr r1, =gTypeEffectiveness
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0819003A
_081900A4:
	ldr r0, [sp]
	cmp r0, 0x1
	beq _081900E0
_081900AA:
	ldr r1, [sp]
	cmp r1, 0x1
	bgt _081900BC
	cmp r1, 0
	beq _081900C4
	b _08190154
	.pool
_081900BC:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08190114
	b _08190154
_081900C4:
	cmp r2, 0xA
	beq _08190146
	cmp r2, 0xA
	ble _08190146
	cmp r2, 0x28
	beq _0819014A
	cmp r2, 0x28
	bgt _081900DA
	cmp r2, 0x14
	beq _08190104
	b _08190146
_081900DA:
	cmp r2, 0x50
	bne _08190146
	b _08190100
_081900E0:
	cmp r2, 0xA
	beq _08190104
	cmp r2, 0xA
	bgt _081900F2
	cmp r2, 0
	beq _08190100
	cmp r2, 0x5
	beq _0819014A
	b _08190146
_081900F2:
	cmp r2, 0x28
	beq _08190108
	cmp r2, 0x28
	ble _08190146
	cmp r2, 0x50
	beq _0819010E
	b _08190146
_08190100:
	movs r2, 0x8
	b _08190154
_08190104:
	movs r2, 0x2
	b _08190154
_08190108:
	movs r2, 0x2
	negs r2, r2
	b _08190154
_0819010E:
	movs r2, 0x4
	negs r2, r2
	b _08190154
_08190114:
	cmp r2, 0xA
	beq _08190146
	cmp r2, 0xA
	bgt _08190126
	cmp r2, 0
	beq _0819013A
	cmp r2, 0x5
	beq _08190140
	b _08190146
_08190126:
	cmp r2, 0x28
	beq _0819014E
	cmp r2, 0x28
	bgt _08190134
	cmp r2, 0x14
	beq _0819014A
	b _08190146
_08190134:
	cmp r2, 0x50
	beq _08190152
	b _08190146
_0819013A:
	movs r2, 0x10
	negs r2, r2
	b _08190154
_08190140:
	movs r2, 0x8
	negs r2, r2
	b _08190154
_08190146:
	movs r2, 0
	b _08190154
_0819014A:
	movs r2, 0x4
	b _08190154
_0819014E:
	movs r2, 0xC
	b _08190154
_08190152:
	movs r2, 0x14
_08190154:
	adds r0, r2, 0
_08190156:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818FFC0

	thumb_func_start sub_8190168
sub_8190168: @ 8190168
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	cmp r0, 0x63
	bls _0819019A
	movs r1, 0x6
	cmp r0, 0x77
	bls _0819019A
	movs r1, 0x9
	cmp r0, 0x8B
	bls _0819019A
	movs r1, 0xC
	cmp r0, 0x9F
	bls _0819019A
	movs r1, 0xF
	cmp r0, 0xB3
	bls _0819019A
	movs r1, 0x12
	cmp r0, 0xC7
	bls _0819019A
	movs r1, 0x1F
	cmp r0, 0xDB
	bhi _0819019A
	movs r1, 0x15
_0819019A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8190168

	thumb_func_start sub_81901A0
sub_81901A0: @ 81901A0
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r5, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r4, =0x00000d24
	adds r1, r4
	ldrh r1, [r1]
	lsls r1, 22
	lsrs r1, 22
	mov r12, r0
	ldr r6, =gUnknown_0860D10C
	cmp r1, r2
	beq _081901D8
	mov r7, r12
_081901C0:
	adds r5, 0x1
	cmp r5, 0xF
	bgt _081901D8
	ldr r0, [r7]
	lsls r1, r5, 2
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r2
	bne _081901C0
_081901D8:
	cmp r3, 0
	beq _0819026C
	cmp r3, 0x3
	bne _081901FC
	lsls r0, r5, 2
	adds r1, r0, 0x3
	adds r1, r6
	ldrb r1, [r1]
	adds r4, r1, 0
	adds r4, 0x8
	b _08190206
	.pool
_081901FC:
	lsls r0, r5, 2
	adds r1, r3, r0
	adds r1, r6
	ldrb r1, [r1]
	adds r4, r1, 0x4
_08190206:
	adds r0, r3, r0
	adds r0, r6
	ldrb r2, [r0]
	cmp r2, r4
	bge _08190256
	ldr r1, =gUnknown_0860D14C
	adds r0, r2, r1
	ldrb r3, [r0]
	adds r6, r1, 0
	cmp r3, r5
	beq _08190234
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r3, 2
	adds r0, r1
	ldr r3, =0x00000d25
	adds r0, r3
	b _0819024E
	.pool
_08190234:
	adds r2, 0x1
	cmp r2, r4
	bge _08190256
	adds r0, r2, r6
	ldrb r1, [r0]
	cmp r1, r5
	beq _08190234
	mov r3, r12
	ldr r0, [r3]
	lsls r1, 2
	adds r0, r1
	ldr r1, =0x00000d25
	adds r0, r1
_0819024E:
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08190234
_08190256:
	cmp r2, r4
	beq _08190286
	ldr r0, =gUnknown_0860D14C
	adds r0, r2, r0
	ldrb r0, [r0]
	b _08190292
	.pool
_0819026C:
	mov r3, r12
	ldr r1, [r3]
	lsls r0, r5, 2
	adds r0, r6
	ldrb r2, [r0]
	lsls r0, r2, 2
	adds r1, r0
	ldr r0, =0x00000d25
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 29
	cmp r0, 0
	bge _08190290
_08190286:
	movs r0, 0xFF
	b _08190292
	.pool
_08190290:
	adds r0, r2, 0
_08190292:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81901A0

	thumb_func_start sub_8190298
sub_8190298: @ 8190298
	push {lr}
	bl sub_81902AC
	ldr r1, =gTrainerBattleOpponent_A
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190298

	thumb_func_start sub_81902AC
sub_81902AC: @ 81902AC
	push {r4,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r1, =0x00000cb2
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r1, =0x000003ff
	bl sub_81901A0
	lsls r0, 2
	adds r4, r0
	ldr r0, =0x00000d24
	adds r4, r0
	ldrh r0, [r4]
	lsls r0, 22
	lsrs r0, 22
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81902AC

	thumb_func_start sub_81902E4
sub_81902E4: @ 81902E4
	push {lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	movs r1, 0
	bl sub_8162614
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81902E4

	thumb_func_start sub_81902F8
sub_81902F8: @ 81902F8
	push {r4,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0
	bl VarSet
	ldr r1, [r4]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_81A4C30
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81902F8

	thumb_func_start sub_819033C
sub_819033C: @ 819033C
	push {r4,r5,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r4, [r0]
	lsls r4, 30
	lsrs r4, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	ldr r1, [r5]
	lsls r4, 1
	lsrs r0, 22
	adds r4, r0
	ldr r3, =0x00000d0c
	adds r1, r3
	adds r1, r4
	ldrh r0, [r1]
	ldr r2, =0x000003e6
	cmp r0, r2
	bhi _0819036E
	adds r0, 0x1
	strh r0, [r1]
_0819036E:
	ldr r0, [r5]
	ldr r1, =0x00000d1c
	adds r0, r1
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r2
	bhi _08190380
	adds r0, 0x1
	strh r0, [r1]
_08190380:
	ldr r0, [r5]
	adds r1, r0, r3
	adds r1, r4
	ldr r2, =0x00000d14
	adds r0, r2
	adds r0, r4
	ldrh r1, [r1]
	ldrh r2, [r0]
	cmp r1, r2
	bls _08190396
	strh r1, [r0]
_08190396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819033C

	thumb_func_start sub_81903B8
sub_81903B8: @ 81903B8
	push {r4,r5,lr}
	ldr r0, =sub_8190400
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r5, 0
	strh r5, [r4, 0x8]
	bl sub_81902AC
	lsls r0, 16
	lsrs r0, 16
	bl sub_8195358
	strh r0, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	ldr r0, =sub_8194B54
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81903B8

	thumb_func_start sub_8190400
sub_8190400: @ 8190400
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	adds r6, r0, r1
	movs r0, 0xA
	ldrsh r5, [r6, r0]
	movs r2, 0xC
	ldrsh r1, [r6, r2]
	mov r9, r1
	movs r0, 0xE
	ldrsh r7, [r6, r0]
	movs r1, 0x8
	ldrsh r4, [r6, r1]
	cmp r4, 0x1
	beq _08190508
	cmp r4, 0x1
	bgt _08190440
	cmp r4, 0
	beq _0819044E
	b _08190772
	.pool
_08190440:
	cmp r4, 0x2
	bne _08190446
	b _08190570
_08190446:
	cmp r4, 0x3
	bne _0819044C
	b _08190634
_0819044C:
	b _08190772
_0819044E:
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x1
	bl EnableInterrupts
	str r4, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	add r0, sp, 0x4
	bl CpuSet
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0860CE84
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0860CEB4
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gBattle_BG0_X
	strh r4, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r4, [r0]
	ldr r0, =gBattle_BG1_X
	strh r4, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r4, [r0]
	ldr r0, =gBattle_BG3_X
	strh r4, [r0]
	ldr r0, =gBattle_BG3_Y
	strh r4, [r0]
	mov r2, r9
	cmp r2, 0x2
	bne _081904DC
	ldr r0, =gBattle_BG2_X
	strh r4, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r4, [r0]
	b _081904E6
	.pool
_081904DC:
	ldr r0, =gBattle_BG2_X
	strh r4, [r0]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
_081904E6:
	ldr r0, =gTasks
	mov r2, r10
	lsls r1, r2, 2
	add r1, r10
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08190772
	.pool
_08190508:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	b _08190602
	.pool
_08190570:
	ldr r1, =gUnknown_08D83D50
	movs r5, 0x80
	lsls r5, 6
	movs r7, 0
	str r7, [sp]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08D84970
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08D84F00
	movs r2, 0x80
	lsls r2, 4
	str r4, [sp]
	movs r0, 0x3
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r0, =gUnknown_0860CF50
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08D85358
	movs r4, 0x80
	lsls r4, 2
	movs r1, 0
	adds r2, r4, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08D85444
	movs r1, 0x80
	lsls r1, 1
	adds r2, r4, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08D85600
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadCompressedPalette
	mov r0, r9
	cmp r0, 0x2
	bne _081905DE
	ldr r0, =gUnknown_08D854C8
	movs r1, 0x50
	movs r2, 0x20
	bl LoadCompressedPalette
_081905DE:
	str r7, [sp, 0x8]
	add r0, sp, 0x8
	ldr r1, =gPlttBufferFaded
	ldr r2, =0x05000100
	bl CpuSet
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_08190602:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _08190772
	.pool
_08190634:
	ldr r0, =sub_8194B70
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203CD78
	movs r0, 0x14
	bl AllocZeroed
	str r0, [r4]
	movs r6, 0
	lsls r5, 24
	movs r2, 0xFF
_0819064A:
	ldr r1, [r4]
	adds r1, r6
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0xF
	ble _0819064A
	bl LoadMonIconPalettes
	ldr r0, =sub_8190CD4
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	strh r7, [r0, 0x10]
	mov r2, r9
	cmp r2, 0x2
	bne _081906A8
	lsrs r1, r5, 24
	movs r0, 0
	bl sub_819314C
	ldr r0, =gUnknown_0203CD78
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	b _081906B0
	.pool
_081906A8:
	lsrs r1, r5, 24
	movs r0, 0
	bl sub_81924E0
_081906B0:
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	mov r0, r9
	cmp r0, 0
	beq _0819076C
	ldr r5, =gUnknown_0860D068
	adds r0, r5, 0
	movs r1, 0x78
	movs r2, 0x4
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	ldr r1, =gSprites
	mov r8, r1
	add r4, r8
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
	adds r0, r5, 0
	movs r1, 0x78
	movs r2, 0x9C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	add r4, r8
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
	ldr r5, =gUnknown_0860D050
	adds r0, r5, 0
	movs r1, 0x6
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	mov r2, r8
	adds r4, r0, r2
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
	movs r0, 0
	strh r0, [r4, 0x30]
	mov r1, r9
	cmp r1, 0x1
	bne _08190746
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08190746:
	adds r0, r5, 0
	movs r1, 0xEA
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	add r4, r8
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
	movs r0, 0x1
	strh r0, [r4, 0x30]
_0819076C:
	mov r0, r10
	bl DestroyTask
_08190772:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190400

	thumb_func_start sub_8190790
sub_8190790: @ 8190790
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x22]
	adds r1, r0, 0x4
	strh r1, [r2, 0x22]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081907D4
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	blt _081907BC
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_081907BC:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	bne _081907F0
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	b _081907F0
	.pool
_081907D4:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xBF
	ble _081907F0
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldrh r0, [r2, 0x34]
	bl sub_818D8F0
_081907F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190790

	thumb_func_start sub_81907F8
sub_81907F8: @ 81907F8
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x22]
	subs r1, r0, 0x4
	strh r1, [r2, 0x22]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08190838
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xC0
	bgt _08190820
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_08190820:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	bne _08190858
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	b _08190858
	.pool
_08190838:
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bgt _08190858
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldrh r0, [r2, 0x34]
	bl sub_818D8F0
_08190858:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81907F8

	thumb_func_start sub_8190860
sub_8190860: @ 8190860
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	adds r1, r0, 0x4
	strh r1, [r2, 0x20]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081908A4
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	blt _0819088C
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_0819088C:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _081908C0
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	b _081908C0
	.pool
_081908A4:
	lsls r1, 16
	ldr r0, =0x010f0000
	cmp r1, r0
	ble _081908C0
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldrh r0, [r2, 0x34]
	bl sub_818D8F0
_081908C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190860

	thumb_func_start sub_81908CC
sub_81908CC: @ 81908CC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	subs r1, r0, 0x4
	strh r1, [r2, 0x20]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08190910
	lsls r1, 16
	movs r0, 0x88
	lsls r0, 17
	cmp r1, r0
	bgt _081908F6
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_081908F6:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08190930
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	b _08190930
	.pool
_08190910:
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bgt _08190930
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldrh r0, [r2, 0x34]
	bl sub_818D8F0
_08190930:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81908CC

	thumb_func_start sub_8190938
sub_8190938: @ 8190938
	push {lr}
	adds r1, r0, 0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0819094A
	adds r0, r1, 0
	bl UpdateMonIconFrame
_0819094A:
	pop {r0}
	bx r0
	thumb_func_end sub_8190938

	thumb_func_start sub_8190950
sub_8190950: @ 8190950
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08190962
	adds r0, r4, 0
	bl UpdateMonIconFrame
_08190962:
	ldrh r0, [r4, 0x22]
	adds r1, r0, 0x4
	strh r1, [r4, 0x22]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081909A4
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	blt _0819098A
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0819098A:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	bne _081909C0
	ldr r0, =sub_8190938
	str r0, [r4, 0x1C]
	b _081909C0
	.pool
_081909A4:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xAF
	ble _081909C0
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_80D2EF8
_081909C0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190950

	thumb_func_start sub_81909CC
sub_81909CC: @ 81909CC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081909DE
	adds r0, r4, 0
	bl UpdateMonIconFrame
_081909DE:
	ldrh r0, [r4, 0x22]
	subs r1, r0, 0x4
	strh r1, [r4, 0x22]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08190A1C
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xB0
	bgt _08190A02
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08190A02:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	bne _08190A3C
	ldr r0, =sub_8190938
	str r0, [r4, 0x1C]
	b _08190A3C
	.pool
_08190A1C:
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _08190A3C
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_80D2EF8
_08190A3C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81909CC

	thumb_func_start sub_8190A48
sub_8190A48: @ 8190A48
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08190A5A
	adds r0, r4, 0
	bl UpdateMonIconFrame
_08190A5A:
	ldrh r0, [r4, 0x20]
	adds r1, r0, 0x4
	strh r1, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08190A9C
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	blt _08190A82
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08190A82:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08190AB8
	ldr r0, =sub_8190938
	str r0, [r4, 0x1C]
	b _08190AB8
	.pool
_08190A9C:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _08190AB8
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_80D2EF8
_08190AB8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190A48

	thumb_func_start sub_8190AC4
sub_8190AC4: @ 8190AC4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08190AD6
	adds r0, r4, 0
	bl UpdateMonIconFrame
_08190AD6:
	ldrh r0, [r4, 0x20]
	subs r1, r0, 0x4
	strh r1, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08190B14
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bgt _08190AFC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08190AFC:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08190B34
	ldr r0, =sub_8190938
	str r0, [r4, 0x1C]
	b _08190B34
	.pool
_08190B14:
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _08190B34
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_80D2EF8
_08190B34:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190AC4

	thumb_func_start sub_8190B40
sub_8190B40: @ 8190B40
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r6, [r3, r0]
	ldr r2, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r2
	movs r7, 0x10
	ldrsh r1, [r4, r7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	ldr r1, =gUnknown_0860D080
	adds r0, r1
	ldrb r0, [r0]
	mov r10, r0
	ldr r1, =gSaveBlock2Ptr
	ldr r5, [r1]
	ldr r7, =0x00000cb2
	adds r0, r5, r7
	ldrh r0, [r0]
	mov r12, r0
	movs r7, 0xE
	ldrsh r0, [r4, r7]
	mov r9, r2
	mov r8, r1
	cmp r0, 0x1
	bne _08190C0C
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08190BFC
	mov r2, r10
	lsls r0, r2, 2
	adds r1, r5, r0
	ldr r7, =0x00000d25
	adds r1, r7
	ldrb r2, [r1]
	lsls r1, r2, 29
	adds r4, r0, 0
	cmp r1, 0
	bge _08190BB6
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	subs r1, 0x1
	lsls r0, r2, 27
	lsrs r0, 30
	cmp r1, r0
	blt _08190C32
_08190BB6:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldr r2, =0x00000d25
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08190BD4
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	subs r0, 0x1
	cmp r0, r12
	blt _08190C32
_08190BD4:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	add r0, r9
	movs r7, 0x8
	ldrsh r0, [r0, r7]
	b _08190C4C
	.pool
_08190BFC:
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _08190C32
	b _08190C48
	.pool
_08190C0C:
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08190C28
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bls _08190C32
	movs r7, 0x8
	ldrsh r0, [r4, r7]
	b _08190C4C
	.pool
_08190C28:
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	beq _08190C48
_08190C32:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _08190C5C
	.pool
_08190C48:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
_08190C4C:
	cmp r0, 0x2
	bne _08190C5C
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08190C5C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8190B40

	thumb_func_start sub_8190C6C
sub_8190C6C: @ 8190C6C
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _08190C9C
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _08190CA6
	b _08190CC0
	.pool
_08190C9C:
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	beq _08190CC0
_08190CA6:
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	bne _08190CCE
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08190CCE
	.pool
_08190CC0:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08190CCE:
	pop {r0}
	bx r0
	thumb_func_end sub_8190C6C

	thumb_func_start sub_8190CD4
sub_8190CD4: @ 8190CD4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r3, 0xE
	ldrsh r2, [r0, r3]
	mov r9, r2
	movs r4, 0x10
	ldrsh r7, [r0, r4]
	movs r5, 0x8
	ldrsh r0, [r0, r5]
	cmp r0, 0x8
	bls _08190D06
	bl _08192202
_08190D06:
	lsls r0, 2
	ldr r1, =_08190D18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08190D18:
	.4byte _08190D3C
	.4byte _08190D7C
	.4byte _08190DA8
	.4byte _08190E48
	.4byte _08191FF8
	.4byte _08192038
	.4byte _08192078
	.4byte _081920BC
	.4byte _08192106
_08190D3C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08190D50
	bl _08192202
_08190D50:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	mov r6, r8
	lsls r0, r6, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	bl _08192202
	.pool
_08190D7C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08190D8C
	bl _08192202
_08190D8C:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	bl _08192202
	.pool
_08190DA8:
	mov r0, r8
	bl sub_819221C
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x8
	bgt _08190DBE
	cmp r6, 0x1
	bge _08190DF0
	bl _08192202
_08190DBE:
	cmp r6, 0x9
	beq _08190DC6
	bl _08192202
_08190DC6:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	strh r1, [r0, 0x8]
	bl _08192202
	.pool
_08190DF0:
	ldr r1, =gTasks
	mov r4, r8
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x12]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0
	mov r9, r2
	cmp r0, 0
	beq _08190E0C
	movs r1, 0x9
_08190E0C:
	adds r6, r1, 0
	adds r0, r6, 0
	adds r0, 0x9
	cmp r6, r0
	bge _08190E32
	adds r5, r0, 0
_08190E18:
	lsls r4, r6, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r6, 0x1
	cmp r6, r5
	blt _08190E18
_08190E32:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x3
	strh r0, [r1, 0x8]
	bl _08192202
	.pool
_08190E48:
	mov r6, r8
	lsls r1, r6, 2
	adds r0, r1, r6
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	movs r3, 0x12
	ldrsh r6, [r0, r3]
	subs r0, r6, 0x1
	mov r9, r1
	cmp r0, 0x7
	bls _08190E64
	bl _08192202
_08190E64:
	lsls r0, 2
	ldr r1, =_08190E78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08190E78:
	.4byte _08190E98
	.4byte _08191234
	.4byte _081915CC
	.4byte _08191B08
	.4byte _08190E98
	.4byte _08191234
	.4byte _0819187C
	.4byte _08191D68
_08190E98:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _08190ED4
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG1_X
	strh r1, [r0]
	ldr r1, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r1]
	b _08190EE6
	.pool
_08190ED4:
	ldr r0, =gBattle_BG0_X
	strh r2, [r0]
	ldr r1, =gBattle_BG0_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_08190EE6:
	cmp r6, 0x1
	bne _08190F9C
	ldr r5, =gUnknown_0203CD78
	ldr r0, [r5]
	ldrb r1, [r0, 0x10]
	cmp r1, 0
	bne _08190F50
	ldr r0, =gBattle_BG2_X
	strh r1, [r0]
	ldr r1, =gBattle_BG2_Y
	movs r6, 0xA0
	lsls r6, 1
	adds r0, r6, 0
	strh r0, [r1]
	ldr r3, =gUnknown_0860D080
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r4, 0xA
	ldrsh r1, [r0, r4]
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x10
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_81924E0
	b _08191084
	.pool
_08190F50:
	ldr r1, =gBattle_BG2_X
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG2_Y
	movs r4, 0
	strh r4, [r0]
	ldr r3, =gUnknown_0860D080
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x10
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_81924E0
	ldr r0, [r5]
	strb r4, [r0, 0x10]
	b _08191084
	.pool
_08190F9C:
	ldr r6, =gUnknown_0203CD78
	ldr r1, [r6]
	ldrb r5, [r1, 0x10]
	cmp r5, 0
	bne _08190FF8
	ldr r4, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	adds r2, r0, 0
	subs r2, 0x10
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, 0x11
	bl sub_8192F08
	ldr r0, =gBattle_BG2_X
	strh r5, [r0]
	ldr r1, =gBattle_BG2_Y
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r3, 0
	strh r0, [r1]
	ldr r2, [r6]
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r4
	ldrb r1, [r0, 0xC]
	movs r0, 0x10
	orrs r0, r1
	ldrb r1, [r2, 0x11]
	bl sub_81924E0
	b _08191084
	.pool
_08190FF8:
	cmp r5, 0x2
	bne _0819104C
	ldr r4, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	adds r2, r0, 0
	subs r2, 0x10
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, 0x11
	bl sub_8192F08
	ldr r1, =gBattle_BG2_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, [r6]
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r4
	ldrb r1, [r0, 0xC]
	movs r0, 0x10
	orrs r0, r1
	ldrb r1, [r2, 0x12]
	bl sub_81924E0
	b _08191084
	.pool
_0819104C:
	ldr r1, =gBattle_BG2_X
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r4, 0xA
	ldrsh r0, [r0, r4]
	adds r2, r0, 0
	subs r2, 0x10
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x10
	orrs r0, r1
	lsls r1, r2, 24
	lsrs r1, 24
	bl sub_819314C
_08191084:
	movs r6, 0
	ldr r5, =gUnknown_0203CD78
	mov r10, r5
	ldr r3, =gSprites
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	mov r12, r6
	adds r4, r3, 0
	adds r4, 0x1C
	movs r7, 0x1
_0819109E:
	cmp r6, 0x1
	bgt _0819110C
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191150
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190790
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191150
	.pool
_0819110C:
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191150
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190950
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191150:
	adds r6, 0x1
	cmp r6, 0x7
	ble _0819109E
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_0819116E:
	cmp r6, 0x9
	bgt _081911D4
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191214
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190790
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191214
	.pool
_081911D4:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191214
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190950
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191214:
	adds r6, 0x1
	cmp r6, 0xF
	ble _0819116E
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r2, 0
	movs r1, 0x4
	bl _08191FE8
	.pool
_08191234:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _08191278
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r0, =gBattle_BG1_X
	strh r1, [r0]
	ldr r1, =gBattle_BG1_Y
	ldr r2, =0x0000ff60
	adds r0, r2, 0
	strh r0, [r1]
	b _0819128C
	.pool
_08191278:
	ldr r0, =gBattle_BG0_X
	strh r2, [r0]
	ldr r1, =gBattle_BG0_Y
	ldr r3, =0x0000ff60
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_0819128C:
	cmp r6, 0x2
	bne _0819133C
	ldr r5, =gUnknown_0203CD78
	ldr r0, [r5]
	ldrb r1, [r0, 0x10]
	cmp r1, 0
	bne _081912F4
	ldr r0, =gBattle_BG2_X
	strh r1, [r0]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r3, =gUnknown_0860D080
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r4, 0xA
	ldrsh r1, [r0, r4]
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x4
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_81924E0
	b _0819141C
	.pool
_081912F4:
	ldr r0, =gBattle_BG2_X
	movs r4, 0
	strh r4, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r4, [r0]
	ldr r3, =gUnknown_0860D080
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x4
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_81924E0
	ldr r0, [r5]
	strb r4, [r0, 0x10]
	b _0819141C
	.pool
_0819133C:
	ldr r6, =gUnknown_0203CD78
	ldr r1, [r6]
	ldrb r5, [r1, 0x10]
	cmp r5, 0
	bne _08191394
	ldr r4, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	adds r2, r0, 0
	subs r2, 0x10
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, 0x11
	bl sub_8192F08
	ldr r0, =gBattle_BG2_X
	strh r5, [r0]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r2, [r6]
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r4
	ldrb r1, [r0, 0xC]
	movs r0, 0x4
	orrs r0, r1
	ldrb r1, [r2, 0x11]
	bl sub_81924E0
	b _0819141C
	.pool
_08191394:
	cmp r5, 0x2
	bne _081913E4
	ldr r4, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r4
	movs r3, 0xA
	ldrsh r0, [r0, r3]
	adds r2, r0, 0
	subs r2, 0x10
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, 0x11
	bl sub_8192F08
	ldr r1, =gBattle_BG2_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r2, [r6]
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r4
	ldrb r1, [r0, 0xC]
	movs r0, 0x4
	orrs r0, r1
	ldrb r1, [r2, 0x12]
	bl sub_81924E0
	b _0819141C
	.pool
_081913E4:
	ldr r1, =gBattle_BG2_X
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	adds r2, r0, 0
	subs r2, 0x10
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x4
	orrs r0, r1
	lsls r1, r2, 24
	lsrs r1, 24
	bl sub_819314C
_0819141C:
	movs r6, 0
	ldr r0, =gUnknown_0203CD78
	mov r10, r0
	ldr r3, =gSprites
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	mov r12, r6
	adds r4, r3, 0
	adds r4, 0x1C
	movs r7, 0x1
_08191436:
	cmp r6, 0x1
	bgt _081914A4
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _081914E8
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_81907F8
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _081914E8
	.pool
_081914A4:
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _081914E8
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_81909CC
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_081914E8:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08191436
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_08191506:
	cmp r6, 0x9
	bgt _0819156C
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _081915AC
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81907F8
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _081915AC
	.pool
_0819156C:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _081915AC
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81909CC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_081915AC:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08191506
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r2, 0
	movs r1, 0x5
	bl _08191FE8
	.pool
_081915CC:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _0819160C
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r2, =gBattle_BG1_X
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	strh r0, [r2]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	b _08191622
	.pool
_0819160C:
	ldr r1, =gBattle_BG0_X
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG0_Y
	strh r2, [r0]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_08191622:
	ldr r0, =gUnknown_0203CD78
	ldr r4, [r0]
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	bne _08191688
	ldr r1, =gBattle_BG2_X
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r3, =gUnknown_0860D080
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r5, 0xA
	ldrsh r1, [r0, r5]
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x8
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_81924E0
	b _081916C6
	.pool
_08191688:
	ldr r1, =gBattle_BG2_X
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0
	strh r0, [r1]
	ldr r3, =gUnknown_0860D15C
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r5, 0xA
	ldrsh r1, [r0, r5]
	lsls r1, 2
	subs r1, 0x1
	ldrb r4, [r4, 0x10]
	adds r1, r4
	adds r1, r3
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0, 0xC]
	movs r0, 0x8
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_819314C
_081916C6:
	movs r6, 0
	ldr r0, =gUnknown_0203CD78
	mov r10, r0
	ldr r3, =gSprites
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	mov r12, r6
	adds r4, r3, 0
	adds r4, 0x1C
	movs r7, 0x1
_081916E0:
	cmp r6, 0x1
	bgt _08191754
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191798
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190860
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191798
	.pool
_08191754:
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191798
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190A48
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191798:
	adds r6, 0x1
	cmp r6, 0x7
	ble _081916E0
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_081917B6:
	cmp r6, 0x9
	bgt _0819181C
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _0819185C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190860
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _0819185C
	.pool
_0819181C:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _0819185C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190A48
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_0819185C:
	adds r6, 0x1
	cmp r6, 0xF
	ble _081917B6
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r2, 0
	movs r1, 0x6
	b _08191FE8
	.pool
_0819187C:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _081918BC
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r2, =gBattle_BG1_X
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	strh r0, [r2]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	b _081918D2
	.pool
_081918BC:
	ldr r1, =gBattle_BG0_X
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG0_Y
	strh r2, [r0]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_081918D2:
	ldr r0, =gUnknown_0203CD78
	ldr r2, [r0]
	ldrb r0, [r2, 0x10]
	cmp r0, 0
	bne _08191924
	ldr r1, =gBattle_BG2_X
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x8
	orrs r0, r1
	ldrb r1, [r2, 0x11]
	bl sub_81924E0
	b _08191958
	.pool
_08191924:
	ldr r1, =gBattle_BG2_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	adds r2, r0, 0
	subs r2, 0x10
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x8
	orrs r0, r1
	lsls r1, r2, 24
	lsrs r1, 24
	bl sub_819314C
_08191958:
	movs r6, 0
	ldr r0, =gUnknown_0203CD78
	mov r10, r0
	ldr r3, =gSprites
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	mov r12, r6
	adds r4, r3, 0
	adds r4, 0x1C
	movs r7, 0x1
_08191972:
	cmp r6, 0x1
	bgt _081919E0
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191A24
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190860
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191A24
	.pool
_081919E0:
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191A24
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190A48
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191A24:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08191972
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_08191A42:
	cmp r6, 0x9
	bgt _08191AA8
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191AE8
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190860
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191AE8
	.pool
_08191AA8:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191AE8
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190A48
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191AE8:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08191A42
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r2, 0
	movs r1, 0x6
	b _08191FE8
	.pool
_08191B08:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _08191B48
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r2, =gBattle_BG1_X
	movs r6, 0xFF
	lsls r6, 8
	adds r0, r6, 0
	strh r0, [r2]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	b _08191B5E
	.pool
_08191B48:
	ldr r1, =gBattle_BG0_X
	movs r3, 0xFF
	lsls r3, 8
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG0_Y
	strh r2, [r0]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_08191B5E:
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _08191B94
	ldr r1, =gBattle_BG2_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	b _08191B9E
	.pool
_08191B94:
	ldr r0, =gBattle_BG2_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
_08191B9E:
	ldr r4, =gUnknown_0860D15C
	ldr r5, =gUnknown_0203CD78
	ldr r3, [r5]
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	lsls r1, 2
	subs r1, 0x1
	ldrb r3, [r3, 0x10]
	adds r1, r3
	adds r1, r4
	mov r4, r9
	add r4, r8
	lsls r4, 3
	adds r4, r2
	ldrb r2, [r4, 0xC]
	movs r0, 0x2
	orrs r0, r2
	ldrb r1, [r1]
	bl sub_819314C
	movs r6, 0
	ldr r7, =gSprites
	mov r12, r6
	mov r10, r5
	adds r5, r7, 0
	adds r5, 0x1C
_08191BDC:
	cmp r6, 0x1
	bgt _08191C50
	mov r1, r10
	ldr r0, [r1]
	adds r3, r0, r6
	ldrb r0, [r3]
	cmp r0, 0xFF
	beq _08191C96
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_81908CC
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r4, 0xC]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0x2E]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r12
	strh r2, [r0, 0x30]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r6, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r1, [r0, 0x34]
	b _08191C96
	.pool
_08191C50:
	mov r3, r10
	ldr r0, [r3]
	adds r3, r0, r6
	ldrb r0, [r3]
	cmp r0, 0xFF
	beq _08191C96
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_8190AC4
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrh r1, [r4, 0xC]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0x2E]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r6, [r0, 0x32]
_08191C96:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08191BDC
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_08191CB4:
	cmp r6, 0x9
	bgt _08191D1C
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191D5C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81908CC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191D5C
	.pool
_08191D1C:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191D5C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190AC4
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191D5C:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08191CB4
	b _08191FDA
	.pool
_08191D68:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r0, r4
	movs r5, 0xC
	ldrsh r2, [r0, r5]
	cmp r2, 0
	beq _08191DA8
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r2, =gBattle_BG1_X
	movs r6, 0xFF
	lsls r6, 8
	adds r0, r6, 0
	strh r0, [r2]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	b _08191DBE
	.pool
_08191DA8:
	ldr r1, =gBattle_BG0_X
	movs r3, 0xFF
	lsls r3, 8
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =gBattle_BG0_Y
	strh r2, [r0]
	ldr r0, =gBattle_BG1_X
	strh r2, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r2, [r0]
_08191DBE:
	ldr r0, =gUnknown_0203CD78
	ldr r2, [r0]
	ldrb r0, [r2, 0x10]
	cmp r0, 0x2
	bne _08191E10
	ldr r1, =gBattle_BG2_X
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x2
	orrs r0, r1
	ldrb r1, [r2, 0x12]
	bl sub_81924E0
	b _08191E44
	.pool
_08191E10:
	ldr r1, =gBattle_BG2_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	adds r2, r0, 0
	subs r2, 0x10
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r0, 0x2
	orrs r0, r1
	lsls r1, r2, 24
	lsrs r1, 24
	bl sub_819314C
_08191E44:
	movs r6, 0
	ldr r0, =gUnknown_0203CD78
	mov r10, r0
	ldr r3, =gSprites
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	mov r12, r6
	adds r4, r3, 0
	adds r4, 0x1C
	movs r7, 0x1
_08191E5E:
	cmp r6, 0x1
	bgt _08191ECC
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191F10
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_81908CC
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191F10
	.pool
_08191ECC:
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191F10
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8190AC4
	str r1, [r0]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r5, 0xC]
	eors r0, r7
	strh r0, [r1, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	mov r1, r12
	strh r1, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191F10:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08191E5E
	movs r6, 0x8
	ldr r2, =gUnknown_0203CD78
	mov r12, r2
	ldr r3, =gSprites
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	movs r4, 0
	adds r7, r3, 0
	adds r7, 0x1C
_08191F2E:
	cmp r6, 0x9
	bgt _08191F94
	mov r1, r12
	ldr r0, [r1]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191FD4
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81908CC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r1, [r0, 0x34]
	b _08191FD4
	.pool
_08191F94:
	mov r2, r12
	ldr r0, [r2]
	adds r2, r0, r6
	ldrb r0, [r2]
	cmp r0, 0xFF
	beq _08191FD4
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_8190AC4
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r5, 0xC]
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r4, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r6, [r0, 0x32]
_08191FD4:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08191F2E
_08191FDA:
	mov r0, r9
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r2, 0
	movs r1, 0x7
_08191FE8:
	strh r1, [r0, 0x8]
	strh r2, [r0, 0x12]
	b _08192202
	.pool
_08191FF8:
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	ldr r5, =gTasks
	adds r1, r0, r5
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x29
	beq _08192100
	ldr r1, =gBattle_BG0_Y
	ldrh r0, [r1]
	subs r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	subs r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	b _081920A4
	.pool
_08192038:
	mov r6, r8
	lsls r0, r6, 2
	add r0, r8
	lsls r0, 3
	ldr r2, =gTasks
	adds r1, r0, r2
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x29
	beq _08192100
	ldr r1, =gBattle_BG0_Y
	ldrh r0, [r1]
	adds r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	adds r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG2_Y
	b _081920E8
	.pool
_08192078:
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	ldr r4, =gTasks
	adds r1, r0, r4
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x41
	beq _08192100
	ldr r1, =gBattle_BG0_X
	ldrh r0, [r1]
	subs r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	subs r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG2_X
_081920A4:
	ldrh r0, [r1]
	subs r0, 0x4
	strh r0, [r1]
	b _08192202
	.pool
_081920BC:
	mov r5, r8
	lsls r0, r5, 2
	add r0, r8
	lsls r0, 3
	ldr r6, =gTasks
	adds r1, r0, r6
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x41
	beq _08192100
	ldr r1, =gBattle_BG0_X
	ldrh r0, [r1]
	adds r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x4
	strh r0, [r1]
	ldr r1, =gBattle_BG2_X
_081920E8:
	ldrh r0, [r1]
	adds r0, 0x4
	strh r0, [r1]
	b _08192202
	.pool
_08192100:
	movs r0, 0x2
	strh r0, [r1, 0x8]
	b _08192202
_08192106:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08192202
	movs r6, 0
	ldr r4, =gUnknown_0203CD78
_08192116:
	cmp r6, 0x1
	bgt _08192134
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0819214E
	bl sub_818D8F0
	b _0819214E
	.pool
_08192134:
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0819214E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_0819214E:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08192116
	movs r6, 0x8
	ldr r4, =gUnknown_0203CD78
_08192158:
	cmp r6, 0x9
	bgt _08192174
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0819218E
	bl sub_818D8F0
	b _0819218E
	.pool
_08192174:
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0819218E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_0819218E:
	adds r6, 0x1
	cmp r6, 0xF
	ble _08192158
	bl FreeMonIconPalettes
	ldr r4, =gUnknown_0203CD78
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	bl FreeAllWindowBuffers
	mov r0, r9
	cmp r0, 0
	bne _081921C4
	ldr r0, =CB2_ReturnToFieldContinueScript
	bl SetMainCallback2
	b _081921FC
	.pool
_081921C4:
	ldr r0, =sub_8194220
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	strh r5, [r1, 0xA]
	movs r0, 0x3
	strh r0, [r1, 0xC]
	mov r3, r8
	lsls r0, r3, 2
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x10]
	strh r0, [r1, 0xE]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x14]
	strh r0, [r1, 0x10]
_081921FC:
	mov r0, r8
	bl DestroyTask
_08192202:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8190CD4

	thumb_func_start sub_819221C
sub_819221C: @ 819221C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r7, 0
	ldr r2, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r2
	mov r12, r0
	movs r1, 0x10
	ldrsh r6, [r0, r1]
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r2
	movs r3, 0xA
	ldrsh r5, [r0, r3]
	ldr r0, =gUnknown_0860D080
	adds r0, r5, r0
	ldrb r0, [r0]
	mov r10, r0
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	mov r8, r0
	ldr r1, =gMain
	ldrh r4, [r1, 0x2E]
	movs r0, 0x3
	ands r0, r4
	adds r2, r1, 0
	cmp r0, 0
	beq _0819226E
	movs r7, 0x9
_0819226E:
	mov r3, r12
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _0819227A
	b _081924CC
_0819227A:
	cmp r0, 0x1
	beq _08192280
	b _081923B0
_08192280:
	movs r0, 0x40
	ands r0, r4
	cmp r0, 0
	beq _081922BA
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _081922BA
	cmp r5, 0
	bne _081922B4
	movs r5, 0xF
	b _081922B6
	.pool
_081922B4:
	subs r5, 0x1
_081922B6:
	movs r7, 0x1
	b _08192360
_081922BA:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081922E2
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _081922E2
	cmp r5, 0xF
	bne _081922DC
	movs r5, 0
	b _081922DE
	.pool
_081922DC:
	adds r5, 0x1
_081922DE:
	movs r7, 0x2
	b _08192360
_081922E2:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08192304
	ldr r0, =gUnknown_0203CD78
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _08192304
	subs r0, 0x1
	strb r0, [r1, 0x10]
	movs r7, 0x3
	b _08192360
	.pool
_08192304:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08192360
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	mov r3, r10
	lsls r1, r3, 2
	adds r0, r1
	ldr r2, =0x00000d25
	adds r0, r2
	ldrb r3, [r0]
	lsls r0, r3, 29
	mov r12, r1
	cmp r0, 0
	bge _0819233C
	ldr r0, =gUnknown_0203CD78
	ldr r2, [r0]
	ldrb r4, [r2, 0x10]
	subs r1, r4, 0x1
	lsls r0, r3, 27
	lsrs r0, 30
	cmp r1, r0
	bge _0819233C
	adds r0, r4, 0x1
	strb r0, [r2, 0x10]
	movs r7, 0x4
_0819233C:
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	add r0, r12
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08192360
	ldr r0, =gUnknown_0203CD78
	ldr r3, [r0]
	ldrb r1, [r3, 0x10]
	subs r0, r1, 0x1
	cmp r0, r8
	bge _08192360
	adds r0, r1, 0x1
	strb r0, [r3, 0x10]
	movs r7, 0x4
_08192360:
	cmp r7, 0x9
	beq _08192366
	b _081924A0
_08192366:
	ldr r0, =gUnknown_0203CD78
	ldr r3, [r0]
	ldrb r0, [r3, 0x10]
	cmp r0, 0
	beq _081923A0
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r2, =gTasks
	adds r1, r2
	ldr r2, =gUnknown_0860D1A0
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r0, 1
	lsls r0, 2
	subs r0, 0x1
	ldrb r3, [r3, 0x10]
	adds r0, r3
	b _08192482
	.pool
_081923A0:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	b _0819249E
	.pool
_081923B0:
	movs r0, 0x40
	ands r0, r4
	cmp r0, 0
	beq _081923DE
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _081923DE
	cmp r5, 0x10
	bne _081923D8
	ldr r0, =gUnknown_0860D19C
	add r0, r8
	ldrb r5, [r0]
	b _081923DA
	.pool
_081923D8:
	subs r5, 0x1
_081923DA:
	movs r7, 0x5
	b _08192446
_081923DE:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0819240E
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _0819240E
	ldr r0, =gUnknown_0860D19C
	add r0, r8
	ldrb r0, [r0]
	cmp r5, r0
	bne _08192408
	movs r5, 0x10
	b _0819240A
	.pool
_08192408:
	adds r5, 0x1
_0819240A:
	movs r7, 0x6
	b _08192446
_0819240E:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0819242C
	ldr r0, =gUnknown_0203CD78
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _0819242C
	movs r7, 0x7
	subs r0, 0x1
	b _08192444
	.pool
_0819242C:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08192446
	ldr r0, =gUnknown_0203CD78
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0x1
	bhi _08192446
	movs r7, 0x8
	adds r0, 0x1
_08192444:
	strb r0, [r1, 0x10]
_08192446:
	cmp r7, 0x9
	bne _081924A0
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	cmp r1, 0
	bne _08192470
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r2, =gTasks
	adds r1, r2
	ldr r2, =gUnknown_0860D1C0
	ldrb r0, [r0, 0x11]
	b _08192482
	.pool
_08192470:
	cmp r1, 0x2
	bne _08192494
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r3, =gTasks
	adds r1, r3
	ldr r2, =gUnknown_0860D1C0
	ldrb r0, [r0, 0x12]
_08192482:
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0xA]
	b _081924A0
	.pool
_08192494:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
_0819249E:
	strh r5, [r0, 0xA]
_081924A0:
	cmp r7, 0
	beq _081924CC
	cmp r7, 0x9
	beq _081924CC
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0xA]
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0xC]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0xC]
_081924CC:
	adds r0, r7, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_819221C

	thumb_func_start sub_81924E0
sub_81924E0: @ 81924E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x20]
	movs r5, 0
	movs r0, 0
	str r0, [sp, 0x28]
	movs r1, 0
	str r1, [sp, 0x2C]
	movs r2, 0
	str r2, [sp, 0x30]
	movs r4, 0
	movs r0, 0x24
	bl AllocZeroed
	mov r8, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r3, [sp, 0x20]
	lsls r0, r3, 2
	adds r0, r1, r0
	ldr r2, =0x00000d24
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	str r0, [sp, 0x24]
	movs r0, 0x1
	ldr r3, [sp, 0x1C]
	ands r0, r3
	cmp r0, 0
	beq _08192538
	movs r5, 0x8
	movs r4, 0x9
	str r4, [sp, 0x28]
	movs r4, 0x2
_08192538:
	movs r0, 0x2
	ldr r2, [sp, 0x1C]
	ands r0, r2
	cmp r0, 0
	beq _08192548
	movs r3, 0x80
	lsls r3, 1
	str r3, [sp, 0x2C]
_08192548:
	movs r0, 0x4
	ldr r2, [sp, 0x1C]
	ands r0, r2
	cmp r0, 0
	beq _08192556
	movs r3, 0xA0
	str r3, [sp, 0x30]
_08192556:
	movs r0, 0x8
	ldr r2, [sp, 0x1C]
	ands r0, r2
	cmp r0, 0
	beq _08192564
	ldr r3, =0xffffff00
	str r3, [sp, 0x2C]
_08192564:
	movs r0, 0x10
	ldr r2, [sp, 0x1C]
	ands r0, r2
	cmp r0, 0
	beq _08192574
	movs r3, 0xA0
	negs r3, r3
	str r3, [sp, 0x30]
_08192574:
	ldr r0, =0x000003ff
	ldr r2, [sp, 0x24]
	cmp r2, r0
	bne _08192598
	ldrb r0, [r1, 0x8]
	bl PlayerGenderToFrontTrainerPicId
	lsls r0, 16
	lsrs r0, 16
	b _081925B6
	.pool
_08192598:
	ldr r0, =0x000003fe
	ldr r3, [sp, 0x24]
	cmp r3, r0
	bne _081925AC
	bl sub_8195910
	b _081925B2
	.pool
_081925AC:
	ldr r0, [sp, 0x24]
	bl GetFrontierTrainerFrontSpriteId
_081925B2:
	lsls r0, 24
	lsrs r0, 24
_081925B6:
	ldr r2, [sp, 0x2C]
	adds r2, 0x30
	ldr r3, [sp, 0x30]
	adds r3, 0x40
	adds r1, r4, 0
	adds r1, 0xC
	str r1, [sp]
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	bl sub_818D8AC
	ldr r1, =gUnknown_0203CD78
	ldr r1, [r1]
	adds r1, r5
	strb r0, [r1]
	movs r0, 0x1E
	ldr r4, [sp, 0x1C]
	ands r0, r4
	cmp r0, 0
	beq _081925FC
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081925FC:
	movs r7, 0
	ldr r0, [sp, 0x20]
	lsls r0, 1
	str r0, [sp, 0x3C]
	adds r1, r5, 0x2
	ldr r2, [sp, 0x28]
	lsls r2, 24
	str r2, [sp, 0x44]
	ldr r3, [sp, 0x28]
	adds r3, 0x4
	str r3, [sp, 0x40]
	ldr r4, [sp, 0x20]
	adds r0, r4
	ldr r6, =gUnknown_0203CD78
	ldr r2, =gSprites
	mov r10, r2
	adds r4, r1, 0
	lsls r5, r0, 1
	movs r3, 0
	mov r9, r3
_08192624:
	ldr r0, =0x000003ff
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192660
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000d64
	adds r0, r2
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =gUnknown_0860D340
	adds r1, r7, r1
	ldrb r2, [r1]
	ldr r3, [sp, 0x2C]
	orrs r2, r3
	b _081926B0
	.pool
_08192660:
	ldr r0, =0x000003fe
	ldr r3, [sp, 0x24]
	cmp r3, r0
	bne _08192690
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000d64
	adds r0, r1
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =gUnknown_0860D340
	adds r1, r7, r1
	ldrb r2, [r1]
	ldr r3, [sp, 0x2C]
	orrs r2, r3
	b _081926B0
	.pool
_08192690:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r3, =0x00000d64
	adds r0, r3
	adds r0, r5
	ldrh r1, [r0]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gUnknown_0860D340
	adds r1, r7, r1
	ldrb r2, [r1]
	ldr r1, [sp, 0x2C]
	orrs r2, r1
_081926B0:
	ldr r1, =gUnknown_0860D343
	adds r1, r7, r1
	ldrb r3, [r1]
	ldr r1, [sp, 0x30]
	adds r3, r1
	mov r1, r9
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	ldr r1, =sub_8190938
	bl CreateMonIcon
	ldr r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrb r1, [r0, 0x5]
	movs r2, 0xD
	negs r2, r2
	ands r1, r2
	strb r1, [r0, 0x5]
	movs r0, 0x1E
	ldr r3, [sp, 0x1C]
	ands r0, r3
	cmp r0, 0
	beq _0819270A
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0819270A:
	adds r4, 0x1
	adds r5, 0x2
	adds r7, 0x1
	cmp r7, 0x2
	ble _08192624
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x2
	strb r3, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r2, [r0, 0x7]
	adds r1, r0, 0
	adds r0, r2, 0
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	adds r0, r1, 0
	strb r3, [r0, 0xA]
	strb r2, [r0, 0xB]
	adds r3, r0, 0
	ldrb r2, [r3, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	adds r2, r3, 0
	movs r0, 0xE0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	adds r1, r2, 0
	movs r0, 0xD0
	strb r0, [r1, 0xD]
	movs r7, 0
	ldr r0, =0x000003ff
	ldr r4, [sp, 0x24]
	cmp r4, r0
	bne _08192784
	ldr r0, =gFacilityClassToTrainerClass
	adds r0, 0x3C
	ldrb r5, [r0]
	b _081927A2
	.pool
_08192784:
	ldr r0, =0x000003fe
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192798
	bl sub_8195924
	b _0819279E
	.pool
_08192798:
	ldr r0, [sp, 0x24]
	bl GetFrontierOpponentClass
_0819279E:
	lsls r0, 24
	lsrs r5, r0, 24
_081927A2:
	ldr r2, =gTrainerClassNames
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	adds r0, r7, r1
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081927CA
	ldr r3, =gStringVar1
	adds r0, r1, r2
	adds r2, r7, r0
_081927BA:
	adds r0, r7, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, 0x1
	adds r7, 0x1
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _081927BA
_081927CA:
	ldr r5, =gStringVar1
	adds r1, r7, r5
	movs r0, 0
	strb r0, [r1]
	adds r0, r7, 0x1
	adds r0, r5
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =0x000003ff
	ldr r2, [sp, 0x24]
	cmp r2, r0
	bne _08192800
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringAppend
	b _08192836
	.pool
_08192800:
	ldr r0, =0x000003fe
	ldr r3, [sp, 0x24]
	cmp r3, r0
	bne _08192824
	ldr r4, =gStringVar2
	adds r0, r4, 0
	bl sub_8195938
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringAppend
	b _08192836
	.pool
_08192824:
	ldr r4, =gStringVar2
	ldr r1, [sp, 0x24]
	adds r0, r4, 0
	bl sub_8195898
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringAppend
_08192836:
	add r0, sp, 0xC
	ldrb r0, [r0, 0x5]
	ldr r4, =gStringVar1
	add r1, sp, 0xC
	ldrb r3, [r1, 0xA]
	adds r1, r4, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	add r1, sp, 0xC
	movs r5, 0
	strb r0, [r1, 0x8]
	str r4, [sp, 0xC]
	adds r0, r1, 0
	add r4, sp, 0x28
	ldrb r4, [r4]
	strb r4, [r0, 0x4]
	ldr r0, [sp, 0x44]
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	add r0, sp, 0xC
	strb r5, [r0, 0xA]
	movs r7, 0
	adds r6, r0, 0
	ldr r1, [sp, 0x3C]
	ldr r2, [sp, 0x20]
	adds r0, r1, r2
	lsls r0, 1
	mov r9, r0
	movs r3, 0xB
	mov r10, r3
_0819288A:
	ldr r0, =gUnknown_0860D346
	adds r0, r7, r0
	ldrb r0, [r0]
	strb r0, [r6, 0x9]
	ldr r0, =0x000003ff
	ldr r4, [sp, 0x24]
	cmp r4, r0
	bne _081928C0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	lsls r0, r7, 1
	add r0, r9
	ldr r2, =0x00000d64
	adds r1, r2
	b _081928FA
	.pool
_081928C0:
	ldr r0, =0x000003fe
	ldr r4, [sp, 0x24]
	cmp r4, r0
	bne _081928E4
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	lsls r0, r7, 1
	add r0, r9
	ldr r2, =0x00000d64
	adds r1, r2
	b _081928FA
	.pool
_081928E4:
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	lsls r0, r7, 1
	add r0, r9
	ldr r2, =0x00000d64
	adds r1, r2
	adds r1, r0
	ldrh r1, [r1]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r1, 4
_081928FA:
	adds r1, r0
	ldrh r0, [r1]
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	ldr r1, =gSpeciesNames
	adds r0, r1
	str r0, [sp, 0xC]
	adds r0, r7, 0x1
	ldr r4, [sp, 0x28]
	adds r0, r4
	movs r1, 0
	strb r0, [r6, 0x4]
	cmp r7, 0x1
	bne _08192930
	movs r0, 0x7
	strb r0, [r6, 0x8]
	b _08192932
	.pool
_08192930:
	strb r1, [r6, 0x8]
_08192932:
	adds r5, r7, 0x1
	ldr r0, [sp, 0x28]
	adds r4, r5, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	adds r7, r5, 0
	cmp r7, 0x2
	ble _0819288A
	ldr r4, [sp, 0x40]
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =0x000003fe
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192980
	ldr r0, =gBattleDomePotentialPointers
	ldr r0, [r0, 0x40]
	b _0819298A
	.pool
_08192980:
	ldr r0, =gBattleDomePotentialPointers
	ldr r2, [sp, 0x20]
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
_0819298A:
	str r0, [sp, 0xC]
	add r1, sp, 0xC
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x5]
	adds r0, r1, 0
	add r3, sp, 0x40
	ldrb r3, [r3]
	strb r3, [r0, 0x4]
	strb r2, [r0, 0x8]
	movs r1, 0x4
	strb r1, [r0, 0x7]
	strb r1, [r0, 0x9]
	movs r1, 0
	bl AddTextPrinter
	movs r7, 0
	ldr r3, =gUnknown_0860B358
_081929AE:
	movs r5, 0
	adds r4, r7, 0x1
	str r4, [sp, 0x38]
	lsls r0, r7, 1
	str r0, [sp, 0x34]
	lsls r2, r7, 4
_081929BA:
	movs r6, 0
	lsls r1, r5, 1
	mov r10, r1
	mov r4, r8
	mov r9, r2
_081929C4:
	ldr r0, =0x000003fe
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192A00
	lsls r0, r7, 24
	lsls r1, r5, 24
	lsrs r0, 24
	lsrs r1, 24
	str r2, [sp, 0x48]
	str r3, [sp, 0x4C]
	bl sub_81A5060
	lsls r0, 16
	lsrs r0, 12
	adds r0, r6, r0
	ldr r3, [sp, 0x4C]
	adds r0, r3
	ldrh r1, [r4]
	ldrb r0, [r0]
	adds r1, r0
	strh r1, [r4]
	ldr r2, [sp, 0x48]
	b _08192A58
	.pool
_08192A00:
	ldr r0, =0x000003ff
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192A20
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000efc
	adds r0, r1
	add r0, r9
	b _08192A48
	.pool
_08192A20:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	mov r12, r0
	ldr r0, [sp, 0x3C]
	ldr r1, [sp, 0x20]
	adds r0, r1
	str r0, [sp, 0x50]
	lsls r0, 1
	ldr r1, [sp, 0x34]
	adds r0, r1, r0
	ldr r1, =0x00000d64
	add r1, r12
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r1, [r1]
	lsls r0, 4
	adds r0, r1
	adds r0, 0x2
	add r0, r10
_08192A48:
	ldrh r0, [r0]
	lsls r0, 4
	adds r0, r6, r0
	adds r0, r3
	ldrh r1, [r4]
	ldrb r0, [r0]
	adds r1, r0
	strh r1, [r4]
_08192A58:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0xF
	ble _081929C4
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _081929BA
	ldr r7, [sp, 0x38]
	cmp r7, 0x2
	ble _081929AE
	movs r7, 0
	ldr r2, =gBattleDomeOpponentStylePointers
	mov r9, r2
	ldr r3, =gUnknown_0860C988
	mov r10, r3
_08192A78:
	movs r4, 0
	movs r6, 0
	movs r5, 0
	mov r3, r8
	lsls r0, r7, 4
	mov r1, r10
	adds r2, r0, r1
_08192A86:
	ldrb r0, [r2]
	cmp r0, 0
	beq _08192A9E
	adds r4, 0x1
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08192A9E
	ldrb r1, [r2]
	cmp r0, r1
	blt _08192A9E
	adds r6, 0x1
_08192A9E:
	adds r3, 0x2
	adds r2, 0x1
	adds r5, 0x1
	cmp r5, 0xF
	ble _08192A86
	cmp r4, r6
	beq _08192AB2
	adds r7, 0x1
	cmp r7, 0x1E
	bls _08192A78
_08192AB2:
	lsls r0, r7, 2
	add r0, r9
	ldr r0, [r0]
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	movs r1, 0x14
	strb r1, [r0, 0x7]
	strb r1, [r0, 0x9]
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	movs r1, 0
	mov r0, r8
	adds r0, 0x22
_08192AD0:
	strh r1, [r0]
	subs r0, 0x2
	cmp r0, r8
	bge _08192AD0
	ldr r2, [sp, 0x24]
	ldr r3, =0xfffffc02
	adds r0, r2, r3
	cmp r0, 0x1
	bls _08192AE4
	b _08192C24
_08192AE4:
	movs r7, 0
	movs r4, 0
	mov r9, r4
_08192AEA:
	movs r5, 0
	mov r4, r8
	mov r6, r9
_08192AF0:
	ldr r0, =0x000003fe
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192B24
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	bl sub_81A50F0
	lsls r0, 24
	lsrs r0, 24
	b _08192B34
	.pool
_08192B24:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r7, 4
	adds r1, r5, r1
	ldr r2, =0x00000f04
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
_08192B34:
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x5
	ble _08192AF0
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r3, 0xC]
	adds r0, r4
	strh r0, [r3, 0xC]
	movs r5, 0
	mov r4, r8
_08192B4C:
	ldr r0, =0x000003fe
	ldr r1, [sp, 0x24]
	cmp r1, r0
	bne _08192B70
	mov r2, r9
	lsrs r0, r2, 24
	bl sub_81A50B0
	lsls r0, 24
	lsrs r2, r0, 24
	b _08192B7E
	.pool
_08192B70:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r7, 4
	adds r0, r1
	ldr r3, =0x00000f0a
	adds r0, r3
	ldrb r2, [r0]
_08192B7E:
	ldr r1, =gNatureStatTable
	lsls r0, r2, 2
	adds r0, r2
	adds r0, r5, r0
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _08192BB4
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x6E
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	ldrh r1, [r4, 0xE]
	adds r1, r0
	strh r1, [r4, 0xE]
	b _08192BDC
	.pool
_08192BB4:
	cmp r0, 0
	bge _08192BD4
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r0, 0x5A
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	ldrh r1, [r4, 0xE]
	adds r1, r0
	strh r1, [r4, 0xE]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	b _08192BDC
_08192BD4:
	ldrh r0, [r4, 0x2]
	ldrh r3, [r4, 0xE]
	adds r0, r3
	strh r0, [r4, 0xE]
_08192BDC:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x4
	ble _08192B4C
	movs r4, 0x80
	lsls r4, 17
	add r9, r4
	adds r7, 0x1
	cmp r7, 0x2
	bgt _08192BF2
	b _08192AEA
_08192BF2:
	movs r5, 0
	mov r1, r8
	movs r7, 0x5
_08192BF8:
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	adds r5, r0
	adds r1, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08192BF8
	movs r6, 0x64
	mov r4, r8
	movs r7, 0x5
_08192C0C:
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	muls r0, r6
	adds r1, r5, 0
	bl __divsi3
	strh r0, [r4]
	adds r4, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08192C0C
	b _08192D70
_08192C24:
	ldr r4, =gUnknown_0203BC8C
	mov r10, r4
	ldr r1, [sp, 0x3C]
	ldr r2, [sp, 0x20]
	adds r0, r1, r2
	lsls r0, 1
	mov r9, r0
	movs r7, 0x2
_08192C34:
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r4, =0x00000d64
	adds r0, r4
	add r0, r9
	ldrh r0, [r0]
	mov r2, r10
	ldr r1, [r2]
	lsls r0, 4
	adds r0, r1
	ldrb r2, [r0, 0xB]
	movs r6, 0
	movs r4, 0
	movs r3, 0x1
	mov r1, r8
	movs r5, 0x5
_08192C54:
	strh r4, [r1]
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _08192C60
	adds r6, 0x1
_08192C60:
	asrs r2, 1
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08192C54
	movs r0, 0xFF
	lsls r0, 1
	adds r1, r6, 0
	bl __divsi3
	adds r6, r0, 0
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r4, =0x00000d64
	adds r0, r4
	add r0, r9
	ldrh r0, [r0]
	mov r2, r10
	ldr r1, [r2]
	lsls r0, 4
	adds r0, r1
	ldrb r2, [r0, 0xB]
	movs r3, 0x1
	mov r1, r8
	movs r5, 0x5
_08192C92:
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _08192C9C
	strh r6, [r1]
_08192C9C:
	asrs r2, 1
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08192C92
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r3, 0xC]
	adds r0, r4
	strh r0, [r3, 0xC]
	movs r5, 0
	mov r4, r8
_08192CB4:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000d64
	adds r0, r2
	add r0, r9
	ldrh r0, [r0]
	mov r3, r10
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	ldrb r2, [r0, 0xC]
	lsls r0, r2, 2
	adds r0, r2
	adds r0, r5, r0
	ldr r1, =gNatureStatTable
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _08192D04
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r0, 0x6E
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	ldrh r1, [r4, 0xE]
	adds r1, r0
	strh r1, [r4, 0xE]
	b _08192D2C
	.pool
_08192D04:
	cmp r0, 0
	bge _08192D24
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r0, 0x5A
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	ldrh r1, [r4, 0xE]
	adds r1, r0
	strh r1, [r4, 0xE]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	b _08192D2C
_08192D24:
	ldrh r0, [r4, 0x2]
	ldrh r1, [r4, 0xE]
	adds r0, r1
	strh r0, [r4, 0xE]
_08192D2C:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x4
	ble _08192CB4
	movs r2, 0x2
	add r9, r2
	subs r7, 0x1
	cmp r7, 0
	blt _08192D40
	b _08192C34
_08192D40:
	movs r5, 0
	mov r1, r8
	movs r7, 0x5
_08192D46:
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	adds r5, r0
	adds r1, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08192D46
	movs r6, 0x64
	mov r4, r8
	movs r7, 0x5
_08192D5A:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	muls r0, r6
	adds r1, r5, 0
	bl __divsi3
	strh r0, [r4]
	adds r4, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08192D5A
_08192D70:
	movs r7, 0
	movs r5, 0
	movs r6, 0
	mov r4, r8
	mov r10, r8
	mov r9, r8
_08192D7C:
	movs r2, 0
	ldrsh r1, [r4, r2]
	cmp r1, 0x1D
	ble _08192DDE
	cmp r7, 0x2
	bne _08192DD4
	mov r3, r8
	movs r0, 0xC
	ldrsh r3, [r3, r0]
	mov r12, r3
	cmp r12, r1
	bge _08192DC6
	mov r2, r8
	ldrh r2, [r2, 0xE]
	add r3, sp, 0x54
	strh r2, [r3]
	mov r2, r8
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r0, r1
	bge _08192DBA
	cmp r12, r0
	bge _08192DB4
	add r0, sp, 0x54
	ldrh r0, [r0]
	strh r0, [r2, 0xC]
	strh r6, [r2, 0xE]
	b _08192DDE
_08192DB4:
	mov r1, r8
	strh r6, [r1, 0xE]
	b _08192DDE
_08192DBA:
	add r2, sp, 0x54
	ldrh r3, [r2]
	mov r2, r8
	strh r3, [r2, 0xC]
	strh r6, [r2, 0xE]
	b _08192DDE
_08192DC6:
	mov r3, r8
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r0, r1
	bge _08192DDE
	strh r6, [r3, 0xE]
	b _08192DDE
_08192DD4:
	mov r3, r9
	strh r6, [r3, 0xC]
	movs r0, 0x2
	add r9, r0
	adds r7, 0x1
_08192DDE:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08192E64
	cmp r5, 0x2
	bne _08192E5A
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _08192E18
	cmp r0, 0x1
	bne _08192E64
	mov r3, r8
	movs r1, 0x10
	ldrsh r0, [r3, r1]
	lsls r0, 1
	add r0, r8
	movs r2, 0x18
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _08192E22
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	lsls r0, 1
	add r0, r8
	movs r2, 0x18
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _08192E22
_08192E18:
	mov r3, r8
	ldrh r0, [r3, 0x12]
	strh r0, [r3, 0x10]
	strh r6, [r3, 0x12]
	b _08192E64
_08192E22:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08192E64
	mov r2, r8
	movs r3, 0x10
	ldrsh r0, [r2, r3]
	lsls r0, 1
	add r0, r8
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08192E44
	ldrh r0, [r2, 0x12]
	strh r0, [r2, 0x10]
	strh r6, [r2, 0x12]
	b _08192E64
_08192E44:
	mov r2, r8
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	lsls r0, 1
	add r0, r8
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08192E64
	strh r6, [r2, 0x12]
	b _08192E64
_08192E5A:
	mov r2, r10
	strh r6, [r2, 0x10]
	movs r3, 0x2
	add r10, r3
	adds r5, 0x1
_08192E64:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _08192D7C
	cmp r7, 0x2
	bne _08192E8C
	ldr r0, =gUnknown_0860D349
	mov r4, r8
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	adds r0, r2, r0
	movs r3, 0xE
	ldrsh r1, [r4, r3]
	subs r1, 0x1
	subs r1, r2
	ldrb r0, [r0]
	adds r7, r1, r0
	b _08192ED2
	.pool
_08192E8C:
	cmp r7, 0x1
	bne _08192E9C
	mov r4, r8
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	adds r7, r0, 0
	adds r7, 0xF
	b _08192ED2
_08192E9C:
	cmp r5, 0x2
	bne _08192EC0
	ldr r0, =gUnknown_0860D349
	mov r3, r8
	movs r4, 0x10
	ldrsh r2, [r3, r4]
	adds r0, r2, r0
	movs r4, 0x12
	ldrsh r1, [r3, r4]
	subs r1, 0x1
	subs r1, r2
	ldrb r0, [r0]
	adds r1, r0
	adds r7, r1, 0
	adds r7, 0x15
	b _08192ED2
	.pool
_08192EC0:
	cmp r5, 0x1
	bne _08192ED0
	mov r1, r8
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	adds r7, r0, 0
	adds r7, 0x24
	b _08192ED2
_08192ED0:
	movs r7, 0x2A
_08192ED2:
	lsls r0, r7, 2
	ldr r3, =gBattleDomeOpponentStatsPointers
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	movs r1, 0x24
	strb r1, [r0, 0x7]
	strb r1, [r0, 0x9]
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	mov r0, r8
	bl Free
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81924E0

	thumb_func_start sub_8192F08
sub_8192F08: @ 8192F08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	str r0, [sp, 0x4]
	mov r8, r0
	ldr r2, =gUnknown_0860D3C4
	lsls r0, r7, 1
	adds r0, r7
	adds r1, r0, r2
	ldrb r6, [r1]
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r6, r0
	adds r3, r2, 0
	cmp r6, r0
	bge _08192FD4
	ldr r5, =gSaveBlock2Ptr
	ldr r1, =0x000003ff
	mov r10, r1
	ldr r2, =0x000003fe
	mov r9, r2
_08192F42:
	ldr r0, =gUnknown_0860D3B4
	adds r0, r6, r0
	ldrb r4, [r0]
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r0, r1
	ldr r2, =0x00000d25
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08192FBE
	ldr r0, [sp]
	add r0, r8
	strb r4, [r0]
	ldr r2, [r5]
	adds r0, r2, r1
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 22
	lsrs r0, r1, 22
	cmp r0, r10
	bne _08192F9C
	ldr r0, =gStringVar1
	adds r1, r2, 0
	bl StringCopy
	b _08192FB8
	.pool
_08192F9C:
	lsrs r0, r1, 22
	cmp r0, r9
	bne _08192FB0
	ldr r0, =gStringVar1
	bl sub_8195938
	b _08192FB8
	.pool
_08192FB0:
	lsrs r1, 22
	ldr r0, =gStringVar1
	bl sub_8195898
_08192FB8:
	movs r2, 0x1
	add r8, r2
	ldr r3, =gUnknown_0860D3C4
_08192FBE:
	adds r6, 0x1
	lsls r1, r7, 1
	adds r1, r7
	adds r0, r1, r3
	ldrb r2, [r0]
	adds r0, r3, 0x1
	adds r1, r0
	ldrb r0, [r1]
	adds r2, r0
	cmp r6, r2
	blt _08192F42
_08192FD4:
	mov r5, r8
	cmp r5, 0x2
	bne _08192FE8
	movs r0, 0
	b _0819313C
	.pool
_08192FE8:
	mov r12, r3
	lsls r3, r7, 1
	adds r0, r3, r7
	mov r2, r12
	adds r1, r0, r2
	ldrb r6, [r1]
	mov r1, r12
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r6, r0
	str r3, [sp, 0x8]
	cmp r6, r0
	blt _08193006
	b _08193126
_08193006:
	ldr r5, =gSaveBlock2Ptr
	mov r10, r5
	ldr r0, =0x00000d25
	mov r9, r0
_0819300E:
	ldr r0, =gUnknown_0860D3B4
	adds r0, r6, r0
	ldrb r4, [r0]
	mov r1, r10
	ldr r0, [r1]
	lsls r2, r4, 2
	str r2, [sp, 0xC]
	adds r0, r2
	add r0, r9
	ldrb r2, [r0]
	lsls r0, r2, 29
	cmp r0, 0
	bge _08193100
	lsls r2, 27
	adds r1, r3, r7
	mov r0, r12
	adds r0, 0x2
	adds r1, r0
	lsrs r2, 30
	ldrb r1, [r1]
	cmp r2, r1
	bcc _08193100
	ldr r0, [sp]
	add r0, r8
	strb r4, [r0]
	movs r5, 0x1
	add r8, r5
	mov r0, r10
	ldr r3, [r0]
	ldr r5, [sp, 0xC]
	adds r2, r3, r5
	adds r0, r2, 0
	add r0, r9
	ldrb r5, [r0]
	mov r12, r5
	mov r0, r12
	lsls r0, 27
	lsrs r0, 30
	cmp r0, r1
	bne _081930BC
	lsls r4, 1
	movs r1, 0xEC
	lsls r1, 4
	adds r0, r3, r1
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	ldr r0, =gStringVar2
	bl StringCopy
	mov r2, r10
	ldr r1, [r2]
	ldr r5, [sp, 0xC]
	adds r0, r1, r5
	add r0, r9
	ldrb r0, [r0]
	lsls r2, r0, 24
	lsrs r0, r2, 29
	lsls r0, 1
	str r0, [sp, 0x4]
	movs r0, 0xEC
	lsls r0, 4
	adds r1, r0
	adds r1, r4
	ldrh r0, [r1]
	cmp r0, 0
	bne _08193100
	lsrs r0, r2, 29
	cmp r0, 0
	bne _08193100
	movs r1, 0x4
	str r1, [sp, 0x4]
	b _08193100
	.pool
_081930BC:
	ldr r5, =0x00000d24
	adds r0, r2, r5
	ldrh r0, [r0]
	lsls r1, r0, 22
	ldr r0, =0xffc00000
	cmp r1, r0
	bne _081930E0
	ldr r0, =gStringVar1
	adds r1, r3, 0
	bl StringCopy
	b _08193100
	.pool
_081930E0:
	ldr r0, =0xff800000
	cmp r1, r0
	bne _081930F8
	ldr r0, =gStringVar1
	bl sub_8195938
	b _08193100
	.pool
_081930F8:
	lsrs r1, 22
	ldr r0, =gStringVar1
	bl sub_8195898
_08193100:
	mov r0, r8
	cmp r0, 0x2
	beq _08193126
	adds r6, 0x1
	ldr r1, =gUnknown_0860D3C4
	mov r12, r1
	ldr r3, [sp, 0x8]
	adds r1, r3, r7
	mov r2, r12
	adds r0, r1, r2
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	adds r2, r0
	cmp r6, r2
	bge _08193126
	b _0819300E
_08193126:
	cmp r7, 0xE
	beq _08193138
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	b _0819313C
	.pool
_08193138:
	ldr r0, [sp, 0x4]
	adds r0, 0x2
_0819313C:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8192F08

	thumb_func_start sub_819314C
sub_819314C: @ 819314C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x80
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x34]
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0
	str r0, [sp, 0x3C]
	movs r7, 0
	movs r1, 0
	str r1, [sp, 0x40]
	movs r2, 0
	str r2, [sp, 0x44]
	mov r9, r2
	movs r0, 0x1
	ldr r3, [sp, 0x34]
	ands r0, r3
	cmp r0, 0
	beq _08193186
	movs r7, 0x8
	str r7, [sp, 0x3C]
	movs r7, 0x9
	movs r0, 0x2
	mov r9, r0
_08193186:
	movs r0, 0x2
	ldr r1, [sp, 0x34]
	ands r0, r1
	cmp r0, 0
	beq _08193196
	movs r2, 0x80
	lsls r2, 1
	str r2, [sp, 0x40]
_08193196:
	movs r0, 0x4
	ldr r3, [sp, 0x34]
	ands r0, r3
	cmp r0, 0
	beq _081931A4
	movs r0, 0xA0
	str r0, [sp, 0x44]
_081931A4:
	movs r0, 0x8
	ldr r1, [sp, 0x34]
	ands r0, r1
	cmp r0, 0
	beq _081931B2
	ldr r2, =0xffffff00
	str r2, [sp, 0x40]
_081931B2:
	movs r0, 0x10
	ldr r3, [sp, 0x34]
	ands r0, r3
	cmp r0, 0
	beq _081931C2
	movs r0, 0xA0
	negs r0, r0
	str r0, [sp, 0x44]
_081931C2:
	ldr r4, =gUnknown_0203CD78
	ldr r1, [r4]
	adds r1, 0x11
	adds r0, r6, 0
	bl sub_8192F08
	str r0, [sp, 0x38]
	movs r5, 0
	mov r1, sp
	adds r1, 0x1C
	str r1, [sp, 0x48]
	mov r2, sp
	adds r2, 0x24
	str r2, [sp, 0x4C]
	lsls r1, r6, 1
	mov r3, sp
	adds r3, 0x2C
	str r3, [sp, 0x50]
	ldr r0, [sp, 0x40]
	adds r0, 0x30
	mov r8, r0
	ldr r2, [sp, 0x44]
	adds r2, 0x58
	str r2, [sp, 0x78]
	movs r3, 0xC
	add r3, r9
	mov r10, r3
	ldr r0, [sp, 0x40]
	adds r0, 0xC0
	str r0, [sp, 0x7C]
	mov r2, r9
	adds r2, 0xD
	str r2, [sp, 0x74]
	ldr r3, [sp, 0x3C]
	adds r3, 0x1
	mov r9, r3
	ldr r0, [sp, 0x3C]
	adds r0, 0x2
	str r0, [sp, 0x54]
	ldr r2, [sp, 0x3C]
	adds r2, 0x5
	str r2, [sp, 0x5C]
	adds r3, r7, 0
	adds r3, 0x8
	str r3, [sp, 0x6C]
	adds r0, r7, 0x6
	str r0, [sp, 0x64]
	adds r2, r7, 0x7
	str r2, [sp, 0x68]
	lsls r3, r6, 2
	str r3, [sp, 0x58]
	adds r0, r7, 0x5
	str r0, [sp, 0x60]
	ldr r0, [r4]
	adds r0, 0x11
	mov r12, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r0, =gUnknown_0860D3C6
	movs r3, 0
	adds r1, r6
	adds r1, r0
	ldrb r6, [r1]
_08193240:
	ldr r1, [sp, 0x48]
	adds r2, r3, r1
	mov r7, r12
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [r2]
	ldr r7, [sp, 0x4C]
	adds r1, r3, r7
	lsls r0, 2
	adds r0, r4, r0
	ldr r7, =0x00000d24
	adds r0, r7
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	str r0, [r1]
	ldr r0, [r2]
	lsls r0, 2
	adds r0, r4, r0
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 27
	lsrs r0, 30
	cmp r0, r6
	bhi _0819329C
	lsls r0, r1, 29
	cmp r0, 0
	bge _0819329C
	ldr r2, [sp, 0x50]
	adds r1, r3, r2
	movs r0, 0x1
	b _081932A2
	.pool
_0819329C:
	ldr r7, [sp, 0x50]
	adds r1, r3, r7
	movs r0, 0
_081932A2:
	str r0, [r1]
	adds r3, 0x4
	adds r5, 0x1
	cmp r5, 0x1
	ble _08193240
	ldr r1, [sp, 0x24]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _081932D4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl PlayerGenderToFrontTrainerPicId
	lsls r0, 16
	lsrs r0, 16
	mov r2, r8
	ldr r3, [sp, 0x78]
	mov r1, r10
	str r1, [sp]
	b _081932F8
	.pool
_081932D4:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _081932E4
	bl sub_8195910
	b _081932EC
	.pool
_081932E4:
	lsls r0, r1, 16
	lsrs r0, 16
	bl GetFrontierTrainerFrontSpriteId
_081932EC:
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	ldr r3, [sp, 0x78]
	mov r7, r10
	str r7, [sp]
_081932F8:
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	bl sub_818D8AC
	ldr r1, =gUnknown_0203CD78
	ldr r1, [r1]
	ldr r2, [sp, 0x3C]
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x1E
	ldr r3, [sp, 0x34]
	ands r0, r3
	cmp r0, 0
	beq _08193334
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldr r7, [sp, 0x3C]
	adds r0, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08193334:
	ldr r0, [sp, 0x2C]
	cmp r0, 0
	beq _0819335A
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	ldr r1, [sp, 0x3C]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x30
	orrs r1, r2
	strb r1, [r0, 0x5]
_0819335A:
	ldr r2, [sp, 0x4C]
	ldr r1, [r2, 0x4]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _08193388
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl PlayerGenderToFrontTrainerPicId
	lsls r0, 16
	lsrs r0, 16
	b _081933B0
	.pool
_08193388:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _081933A4
	bl sub_8195910
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x7C]
	ldr r3, [sp, 0x78]
	ldr r1, [sp, 0x74]
	str r1, [sp]
	b _081933B8
	.pool
_081933A4:
	lsls r0, r1, 16
	lsrs r0, 16
	bl GetFrontierTrainerFrontSpriteId
	lsls r0, 24
	lsrs r0, 24
_081933B0:
	ldr r2, [sp, 0x7C]
	ldr r3, [sp, 0x78]
	ldr r7, [sp, 0x74]
	str r7, [sp]
_081933B8:
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	bl sub_818D8AC
	ldr r1, =gUnknown_0203CD78
	ldr r1, [r1]
	add r1, r9
	strb r0, [r1]
	movs r0, 0x1E
	ldr r1, [sp, 0x34]
	ands r0, r1
	cmp r0, 0
	beq _081933F0
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	add r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081933F0:
	ldr r2, [sp, 0x50]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _08193416
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	add r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x30
	orrs r1, r2
	strb r1, [r0, 0x5]
_08193416:
	movs r5, 0
	ldr r3, [sp, 0x38]
	lsls r3, 2
	str r3, [sp, 0x70]
	mov r8, r5
	ldr r6, =gUnknown_0203CD78
	ldr r7, =gSprites
	ldr r4, [sp, 0x54]
	mov r9, r5
	movs r0, 0x1
	mov r10, r0
_0819342C:
	ldr r1, [sp, 0x24]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _08193464
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r0, [r2]
	b _081934B0
	.pool
_08193464:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _08193490
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r0, [r2]
	b _081934B0
	.pool
_08193490:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r1, [r2]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1]
_081934B0:
	ldr r1, =gUnknown_0860D3A8
	adds r1, r5, r1
	ldrb r2, [r1]
	ldr r3, [sp, 0x40]
	orrs r2, r3
	ldr r1, =gUnknown_0860D3AB
	adds r1, r5, r1
	ldrb r3, [r1]
	ldr r1, [sp, 0x44]
	adds r3, r1
	mov r1, r8
	str r1, [sp]
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	ldr r1, =sub_8190938
	bl CreateMonIcon
	ldr r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r1, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0, 0x5]
	movs r0, 0x1E
	ldr r1, [sp, 0x34]
	ands r0, r1
	cmp r0, 0
	beq _08193516
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08193516:
	ldr r0, [sp, 0x2C]
	cmp r0, 0
	beq _08193548
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	movs r2, 0x30
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r10
	strh r2, [r0, 0x34]
_08193548:
	adds r4, 0x1
	movs r3, 0x2
	add r9, r3
	adds r5, 0x1
	cmp r5, 0x2
	bgt _08193556
	b _0819342C
_08193556:
	movs r5, 0
	ldr r6, =gUnknown_0203CD78
	ldr r7, =gSprites
	mov r8, r7
	ldr r4, [sp, 0x5C]
	mov r9, r5
	movs r7, 0
_08193564:
	ldr r0, [sp, 0x4C]
	ldr r1, [r0, 0x4]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _081935AC
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r3, [sp, 0x48]
	ldr r1, [r3, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r0, [r2]
	b _081935FA
	.pool
_081935AC:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _081935D8
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, [sp, 0x48]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r0, [r2]
	b _081935FA
	.pool
_081935D8:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, [sp, 0x48]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	add r0, r9
	ldr r1, =0x00000d64
	adds r2, r1
	adds r2, r0
	ldrh r1, [r2]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1]
_081935FA:
	ldr r1, =gUnknown_0860D3AE
	adds r1, r5, r1
	ldrb r2, [r1]
	ldr r3, [sp, 0x40]
	orrs r2, r3
	ldr r1, =gUnknown_0860D3B1
	adds r1, r5, r1
	ldrb r3, [r1]
	ldr r1, [sp, 0x44]
	adds r3, r1
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	ldr r1, =sub_8190938
	bl CreateMonIcon
	ldr r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0, 0x5]
	movs r0, 0x1E
	ldr r1, [sp, 0x34]
	ands r0, r1
	cmp r0, 0
	beq _0819365E
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0819365E:
	ldr r2, [sp, 0x50]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _08193692
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	movs r2, 0x30
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x1
	strh r1, [r0, 0x34]
_08193692:
	adds r4, 0x1
	movs r3, 0x2
	add r9, r3
	adds r5, 0x1
	cmp r5, 0x2
	bgt _081936A0
	b _08193564
_081936A0:
	add r0, sp, 0xC
	movs r5, 0
	strb r5, [r0, 0x6]
	adds r1, r0, 0
	movs r0, 0x2
	strb r0, [r1, 0x7]
	adds r0, r1, 0
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	adds r0, r1, 0
	strb r5, [r0, 0xA]
	strb r5, [r0, 0xB]
	adds r3, r0, 0
	ldrb r2, [r3, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	adds r2, r3, 0
	movs r0, 0xE0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	adds r1, r2, 0
	movs r0, 0xD0
	strb r0, [r1, 0xD]
	ldr r4, =gStringVar4
	ldr r0, =gBattleDomeWinStringsPointers
	ldr r7, [sp, 0x70]
	adds r0, r7, r0
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	str r4, [sp, 0xC]
	add r0, sp, 0xC
	add r1, sp, 0x6C
	ldrb r1, [r1]
	strb r1, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x5]
	ldr r4, [sp, 0x6C]
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	strb r5, [r0, 0x8]
	adds r1, r0, 0
	strb r5, [r0, 0x7]
	strb r5, [r1, 0x9]
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	ldr r1, [sp, 0x24]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _0819375C
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	b _0819377E
	.pool
_0819375C:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _08193774
	ldr r0, =gStringVar1
	bl sub_8195938
	b _0819377E
	.pool
_08193774:
	ldr r0, =gStringVar1
	lsls r1, 16
	lsrs r1, 16
	bl sub_8195898
_0819377E:
	add r0, sp, 0xC
	movs r4, 0x2
	strb r4, [r0, 0x5]
	strb r4, [r0, 0xA]
	ldr r5, =gStringVar1
	str r5, [sp, 0xC]
	add r2, sp, 0x64
	ldrb r2, [r2]
	strb r2, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	ldr r1, [sp, 0xC]
	add r2, sp, 0xC
	ldrb r3, [r2, 0xA]
	movs r2, 0x40
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	add r1, sp, 0xC
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	strb r4, [r0, 0x7]
	strb r4, [r1, 0x9]
	ldr r4, [sp, 0x64]
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	ldr r3, [sp, 0x4C]
	ldr r1, [r3, 0x4]
	ldr r0, =0x000003ff
	cmp r1, r0
	bne _081937E4
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy
	b _08193802
	.pool
_081937E4:
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _081937F8
	adds r0, r5, 0
	bl sub_8195938
	b _08193802
	.pool
_081937F8:
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_8195898
_08193802:
	ldr r0, =gStringVar1
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	movs r6, 0
	add r7, sp, 0x68
	ldrb r7, [r7]
	strb r7, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	ldr r1, [sp, 0xC]
	add r2, sp, 0xC
	ldrb r3, [r2, 0xA]
	movs r2, 0x40
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	add r1, sp, 0xC
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	movs r5, 0x2
	strb r5, [r0, 0x7]
	strb r5, [r1, 0x9]
	ldr r4, [sp, 0x68]
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	add r0, sp, 0xC
	strb r6, [r0, 0xA]
	ldr r0, =gBattleDomeMatchNumberPointers
	ldr r1, [sp, 0x58]
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	add r2, sp, 0x60
	ldrb r2, [r2]
	strb r2, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	ldr r1, [sp, 0xC]
	add r2, sp, 0xC
	ldrb r3, [r2, 0xA]
	movs r2, 0xA0
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	add r1, sp, 0xC
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	strb r5, [r0, 0x7]
	strb r5, [r1, 0x9]
	ldr r4, [sp, 0x60]
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add r0, sp, 0xC
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x80
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819314C

	thumb_func_start sub_81938A4
sub_81938A4: @ 81938A4
	push {lr}
	ldr r0, =sub_8194220
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	strh r2, [r1, 0xA]
	movs r0, 0x2
	strh r0, [r1, 0xC]
	strh r2, [r1, 0x10]
	ldr r0, =sub_8194B54
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81938A4

	thumb_func_start sub_81938E0
sub_81938E0: @ 81938E0
	push {r4,lr}
	bl sub_8194D48
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldr r1, =0x00000d0a
	adds r0, r2, r1
	ldrb r1, [r0]
	subs r1, 0x1
	ldr r0, =0x00000ca9
	adds r2, r0
	movs r0, 0x3
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r4]
	ldr r1, =0x00000cb2
	adds r0, r1
	movs r4, 0
	movs r1, 0x3
	strh r1, [r0]
	ldr r0, =sub_8194220
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r4, [r1, 0xA]
	movs r0, 0x2
	strh r0, [r1, 0xC]
	movs r0, 0x1
	strh r0, [r1, 0x10]
	ldr r0, =sub_8194B54
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81938E0

	thumb_func_start sub_819395C
sub_819395C: @ 819395C
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0xA
	ldrsh r7, [r0, r2]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x7
	bls _0819397E
	b _08193BC2
_0819397E:
	lsls r0, 2
	ldr r1, =_08193990
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08193990:
	.4byte _081939B0
	.4byte _08193A00
	.4byte _08193A20
	.4byte _08193AA8
	.4byte _08193BC2
	.4byte _08193B20
	.4byte _08193BC2
	.4byte _08193B84
_081939B0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _081939C2
	b _08193BC2
_081939C2:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	b _08193BC2
	.pool
_08193A00:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08193A0E
	b _08193BC2
_08193A0E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	b _08193BC2
	.pool
_08193A20:
	adds r0, r5, 0
	bl sub_8193BDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08193A30
	b _08193BC2
_08193A30:
	cmp r0, 0x1
	ble _08193A3C
	cmp r0, 0x2
	beq _08193A60
	cmp r0, 0x3
	beq _08193A84
_08193A3C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x7
	strh r1, [r0, 0x8]
	b _08193BC2
	.pool
_08193A60:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3
	strh r1, [r0, 0x8]
	b _08193BC2
	.pool
_08193A84:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x5
	strh r1, [r0, 0x8]
	b _08193BC2
	.pool
_08193AA8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _08193ABA
	b _08193BC2
_08193ABA:
	bl FreeAllWindowBuffers
	bl ScanlineEffect_Stop
	ldr r4, =gUnknown_0203CD7C
	ldr r0, [r4]
	bl Free
	str r6, [r4]
	ldr r0, =sub_8190400
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r2
	movs r3, 0
	strh r6, [r1, 0x8]
	ldr r0, =gUnknown_0860D080
	adds r0, r7, r0
	ldrb r0, [r0]
	strh r0, [r1, 0xA]
	movs r0, 0x1
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x4
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_0203CD78
	ldr r0, [r0]
	strb r3, [r0, 0x10]
	b _08193BC2
	.pool
_08193B20:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08193BC2
	bl FreeAllWindowBuffers
	bl ScanlineEffect_Stop
	ldr r4, =gUnknown_0203CD7C
	ldr r0, [r4]
	bl Free
	str r6, [r4]
	ldr r0, =sub_8190400
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0x8]
	adds r1, r7, 0
	subs r1, 0x10
	strh r1, [r0, 0xA]
	movs r1, 0x2
	strh r1, [r0, 0xC]
	strh r5, [r0, 0xE]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x6
	strh r1, [r0, 0x8]
	b _08193BC2
	.pool
_08193B84:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08193BC2
	bl FreeAllWindowBuffers
	bl ScanlineEffect_Stop
	ldr r4, =gUnknown_0203CD7C
	ldr r0, [r4]
	bl Free
	str r6, [r4]
	ldr r0, =CB2_ReturnToFieldContinueScript
	bl SetMainCallback2
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x16]
	bl DestroyTask
	adds r0, r5, 0
	bl DestroyTask
_08193BC2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819395C

	thumb_func_start sub_8193BDC
sub_8193BDC: @ 8193BDC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x1
	mov r9, r0
	movs r1, 0x4
	mov r8, r1
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0xA
	ldrsh r5, [r0, r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r6, [r0]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	adds r2, r1, 0
	adds r3, r0, 0
	cmp r2, 0x2
	beq _08193C20
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08193C58
	cmp r5, 0x1F
	bne _08193C3C
_08193C20:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	mov r9, r0
	b _08193CDE
	.pool
_08193C3C:
	cmp r5, 0xF
	bgt _08193C4C
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x2
	mov r9, r1
	b _08193CDE
_08193C4C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x3
	mov r9, r0
	b _08193CDE
_08193C58:
	cmp r2, 0x40
	bne _08193C78
	ldr r0, =gUnknown_0860CBF1
	lsls r1, r5, 2
	adds r1, r5
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08193C78
	movs r1, 0
	mov r8, r1
	b _08193CDE
	.pool
_08193C78:
	ldrh r0, [r3, 0x2E]
	cmp r0, 0x80
	bne _08193C9C
	ldr r0, =gUnknown_0860CBF1
	lsls r1, r5, 2
	adds r1, r5
	adds r1, r6
	lsls r1, 2
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08193C9C
	movs r0, 0x1
	b _08193CDC
	.pool
_08193C9C:
	ldrh r0, [r3, 0x2E]
	cmp r0, 0x20
	bne _08193CC0
	ldr r0, =gUnknown_0860CBF1
	lsls r1, r5, 2
	adds r1, r5
	adds r1, r6
	lsls r1, 2
	adds r0, 0x2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08193CC0
	movs r1, 0x2
	mov r8, r1
	b _08193CDE
	.pool
_08193CC0:
	ldrh r0, [r3, 0x2E]
	cmp r0, 0x10
	bne _08193CDE
	ldr r0, =gUnknown_0860CBF1
	lsls r1, r5, 2
	adds r1, r5
	adds r1, r6
	lsls r1, 2
	adds r0, 0x3
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08193CDE
	movs r0, 0x3
_08193CDC:
	mov r8, r0
_08193CDE:
	mov r1, r8
	cmp r1, 0x4
	beq _08193D26
	movs r0, 0x5
	bl PlaySE
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0
	bl StartSpriteAnim
	ldr r2, =gUnknown_0860CBF1
	lsls r1, r6, 2
	add r1, r8
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrb r5, [r1]
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0xA]
_08193D26:
	mov r0, r9
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8193BDC

	thumb_func_start sub_8193D40
sub_8193D40: @ 8193D40
	push {lr}
	ldr r0, =sub_8194220
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x8]
	movs r0, 0x1
	strh r0, [r1, 0xA]
	movs r0, 0x2
	strh r0, [r1, 0xC]
	strh r2, [r1, 0x10]
	ldr r0, =sub_8194B54
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8193D40

	thumb_func_start sub_8193D7C
sub_8193D7C: @ 8193D7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r7, =gSpecialVar_0x8005
	ldrh r0, [r7]
	cmp r0, 0x1
	bne _08193E10
	ldr r5, =gTrainerBattleOpponent_A
	ldrh r0, [r5]
	bl sub_8195358
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	lsls r0, 2
	adds r2, r0
	ldr r6, =0x00000d25
	adds r2, r6
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5]
	bl sub_8195358
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1, r0
	ldr r2, =0x00000cb2
	mov r8, r2
	add r1, r8
	adds r0, r6
	movs r3, 0x3
	ldrb r2, [r1]
	ands r2, r3
	lsls r2, 3
	ldrb r3, [r0]
	movs r1, 0x19
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0]
	ldrh r0, [r5]
	bl sub_8195358
	ldr r2, [r4]
	lsls r0, 1
	movs r3, 0xEC
	lsls r3, 4
	adds r1, r2, r3
	adds r1, r0
	ldr r0, =gBattleResults
	ldrh r0, [r0, 0x22]
	strh r0, [r1]
	add r2, r8
	ldrh r0, [r2]
	cmp r0, 0x2
	bhi _08193EAE
	lsls r0, 24
	lsrs r0, 24
	bl sub_8195438
	b _08193EAE
	.pool
_08193E10:
	ldr r5, =0x000003ff
	adds r0, r5, 0
	bl sub_8195358
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	lsls r0, 2
	adds r2, r0
	ldr r6, =0x00000d25
	adds r2, r6
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8195358
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1, r0
	ldr r2, =0x00000cb2
	adds r1, r2
	adds r0, r6
	movs r3, 0x3
	ldrb r2, [r1]
	ands r2, r3
	lsls r2, 3
	ldrb r3, [r0]
	movs r1, 0x19
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl sub_8195358
	ldr r1, [r4]
	lsls r0, 1
	movs r3, 0xEC
	lsls r3, 4
	adds r1, r3
	adds r1, r0
	ldr r0, =gBattleResults
	ldrh r0, [r0, 0x24]
	strh r0, [r1]
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _08193E78
	ldrh r0, [r7]
	cmp r0, 0x9
	bne _08193E92
_08193E78:
	adds r0, r5, 0
	bl sub_8195358
	ldr r2, [r4]
	lsls r0, 2
	adds r2, r0
	adds r2, r6
	ldrb r1, [r2]
	movs r0, 0x1F
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
_08193E92:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r4, [r0]
	cmp r4, 0x3
	bgt _08193EAE
_08193EA0:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8195438
	adds r4, 0x1
	cmp r4, 0x3
	ble _08193EA0
_08193EAE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8193D7C

	thumb_func_start sub_8193ED0
sub_8193ED0: @ 8193ED0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	lsls r4, r2, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp, 0x54]
	movs r1, 0
	str r1, [sp, 0x58]
	bl sub_8165C40
	movs r2, 0
	str r2, [sp, 0x50]
	add r3, sp, 0x30
	mov r10, r3
	ldr r5, [sp, 0x4C]
	lsls r5, 1
	str r5, [sp, 0x70]
	subs r4, 0x1
	str r4, [sp, 0x78]
_08193F02:
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0x50]
	lsls r1, 2
	str r1, [sp, 0x74]
	ldr r2, [sp, 0x48]
	lsls r2, 2
	str r2, [sp, 0x6C]
	ldr r3, [sp, 0x50]
	adds r3, 0x1
	str r3, [sp, 0x60]
_08193F18:
	ldr r4, [sp, 0x74]
	add r4, r9
	lsls r0, r4, 2
	mov r5, sp
	adds r1, r5, r0
	movs r0, 0
	str r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, [sp, 0x6C]
	adds r0, r3, r1
	ldr r2, =0x00000d24
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	ldr r1, =0xff800000
	cmp r0, r1
	bne _08193F60
	ldr r3, [sp, 0x50]
	lsls r0, r3, 24
	mov r5, r9
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, 24
	bl sub_81A5060
	lsls r1, r4, 1
	add r1, r10
	strh r0, [r1]
	b _08193F8C
	.pool
_08193F60:
	lsls r2, r4, 1
	add r2, r10
	ldr r1, [sp, 0x48]
	lsls r0, r1, 1
	adds r0, r1
	ldr r4, [sp, 0x50]
	adds r0, r4
	lsls r0, 1
	ldr r5, =0x00000d64
	adds r1, r3, r5
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r1, [r1]
	lsls r0, 4
	adds r0, r1
	mov r3, r9
	lsls r1, r3, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
_08193F8C:
	ldr r0, =gBattleMoves
	ldr r1, [sp, 0x74]
	add r1, r9
	lsls r1, 1
	add r1, r10
	ldrh r2, [r1]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r6, [r1, 0x1]
	cmp r6, 0
	bne _08193FB8
	movs r6, 0x28
	b _08193FD0
	.pool
_08193FB8:
	cmp r6, 0x1
	bne _08193FC0
	movs r6, 0x3C
	b _08193FD0
_08193FC0:
	adds r1, r2, 0
	cmp r1, 0x78
	beq _08193FCA
	cmp r1, 0x99
	bne _08193FD0
_08193FCA:
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r6, r0, 1
_08193FD0:
	movs r1, 0
	mov r4, r9
	adds r4, 0x1
	str r4, [sp, 0x64]
	ldr r5, [sp, 0x70]
	ldr r2, [sp, 0x4C]
	adds r0, r5, r2
	lsls r0, 1
	str r0, [sp, 0x5C]
_08193FE2:
	lsls r7, r1, 1
	adds r1, 0x1
	str r1, [sp, 0x68]
	ldr r3, [sp, 0x5C]
	adds r3, r7
	mov r8, r3
_08193FEE:
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r5, r4, 16
	lsls r0, 16
	orrs r5, r0
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r4, =0x00000d64
	adds r0, r4
	add r0, r8
	ldrh r4, [r0]
	ldr r3, =gUnknown_0203BC8C
	ldr r0, [r3]
	lsls r4, 4
	adds r4, r0
	adds r0, r5, 0
	str r2, [sp, 0x7C]
	str r3, [sp, 0x80]
	bl GetNatureFromPersonality
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x7C]
	ldr r3, [sp, 0x80]
	cmp r1, r0
	bne _08193FEE
	ldr r0, [r2]
	ldr r2, [sp, 0x5C]
	adds r1, r7, r2
	ldr r4, =0x00000d64
	adds r0, r4
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x1
	ands r5, r0
	cmp r5, 0
	beq _08194068
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r5, =gBaseStats
	adds r0, r5
	ldrb r2, [r0, 0x17]
	b _08194074
	.pool
_08194068:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r2, =gBaseStats
	adds r0, r2
	ldrb r2, [r0, 0x16]
_08194074:
	ldr r4, [sp, 0x74]
	add r4, r9
	lsls r0, r4, 1
	add r0, r10
	ldrh r0, [r0]
	bl CalcPartyMonTypeEffectivenessMultiplier
	ldr r5, =gMoveResultFlags
	ldrb r5, [r5]
	movs r0, 0x6
	ands r0, r5
	cmp r0, 0x6
	bne _0819409C
	lsls r0, r4, 2
	mov r3, sp
	adds r1, r3, r0
	b _081940D8
	.pool
_0819409C:
	movs r0, 0x29
	ands r0, r5
	cmp r0, 0
	bne _081940DE
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _081940B6
	lsls r0, r4, 2
	mov r5, sp
	adds r2, r5, r0
	lsls r1, r6, 1
	b _081940CA
_081940B6:
	movs r0, 0x4
	ands r5, r0
	cmp r5, 0
	beq _081940D2
	lsls r0, r4, 2
	mov r1, sp
	adds r2, r1, r0
	lsrs r1, r6, 31
	adds r1, r6, r1
	asrs r1, 1
_081940CA:
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	b _081940DE
_081940D2:
	lsls r0, r4, 2
	mov r2, sp
	adds r1, r2, r0
_081940D8:
	ldr r0, [r1]
	adds r0, r6
	str r0, [r1]
_081940DE:
	ldr r1, [sp, 0x68]
	cmp r1, 0x2
	bgt _081940E6
	b _08193FE2
_081940E6:
	ldr r2, [sp, 0x74]
	add r2, r9
	lsls r0, r2, 2
	add r0, sp
	ldr r1, [r0]
	ldr r3, [sp, 0x54]
	cmp r3, r1
	bge _08194104
	lsls r0, r2, 16
	lsrs r0, 16
	str r0, [sp, 0x58]
	lsls r0, r1, 16
	lsrs r0, 16
	str r0, [sp, 0x54]
	b _08194122
_08194104:
	ldr r4, [sp, 0x54]
	cmp r4, r1
	bne _08194122
	ldr r5, [sp, 0x58]
	lsls r0, r5, 1
	add r0, r10
	lsls r1, r2, 1
	add r1, r10
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _08194122
	lsls r0, r2, 16
	lsrs r0, 16
	str r0, [sp, 0x58]
_08194122:
	ldr r0, [sp, 0x64]
	mov r9, r0
	cmp r0, 0x3
	bgt _0819412C
	b _08193F18
_0819412C:
	ldr r1, [sp, 0x60]
	str r1, [sp, 0x50]
	cmp r1, 0x2
	bgt _08194136
	b _08193F02
_08194136:
	ldr r2, [sp, 0x58]
	mov r9, r2
	b _08194182
_0819413C:
	movs r3, 0
	mov r9, r3
	movs r1, 0
	mov r4, r10
	mov r3, r10
	mov r2, sp
_08194148:
	ldr r0, [r2]
	ldr r5, [sp, 0x54]
	cmp r5, r0
	bge _0819415A
	mov r9, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x54]
	b _08194170
_0819415A:
	ldr r5, [sp, 0x54]
	cmp r5, r0
	bne _08194170
	mov r5, r9
	lsls r0, r5, 1
	adds r0, r4, r0
	ldrh r0, [r0]
	ldrh r5, [r3]
	cmp r0, r5
	bcs _08194170
	mov r9, r1
_08194170:
	adds r3, 0x2
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0xB
	ble _08194148
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x78]
	cmp r0, r1
	beq _081941F4
_08194182:
	movs r2, 0
	str r2, [sp, 0x50]
	mov r3, r9
	lsls r7, r3, 2
	ldr r4, [sp, 0x78]
	cmp r2, r4
	bge _081941CA
	lsls r0, r3, 1
	mov r5, r10
	adds r6, r5, r0
	ldr r0, [sp, 0x48]
	lsls r5, r0, 24
_0819419A:
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r2, [sp, 0x50]
	lsls r1, r2, 24
	lsrs r1, 24
	lsrs r0, r5, 24
	bl sub_81953E8
	lsls r0, 24
	lsrs r0, 23
	movs r3, 0xEC
	lsls r3, 4
	adds r4, r3
	adds r4, r0
	ldrh r0, [r4]
	ldrh r4, [r6]
	cmp r0, r4
	beq _081941CA
	ldr r0, [sp, 0x50]
	adds r0, 0x1
	str r0, [sp, 0x50]
	ldr r1, [sp, 0x78]
	cmp r0, r1
	blt _0819419A
_081941CA:
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x78]
	cmp r2, r3
	beq _081941F4
	mov r4, sp
	adds r1, r4, r7
	movs r0, 0
	str r0, [r1]
	movs r5, 0
	str r5, [sp, 0x54]
	mov r9, r5
	mov r2, sp
	movs r1, 0xB
_081941E4:
	ldm r2!, {r0}
	add r9, r0
	subs r1, 0x1
	cmp r1, 0
	bge _081941E4
	mov r0, r9
	cmp r0, 0
	bne _0819413C
_081941F4:
	mov r1, r9
	lsls r0, r1, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _08194204
	ldr r2, [sp, 0x58]
	mov r9, r2
_08194204:
	mov r3, r9
	lsls r0, r3, 1
	add r0, r10
	ldrh r0, [r0]
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8193ED0

	thumb_func_start sub_8194220
sub_8194220: @ 8194220
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	mov r10, r1
	movs r3, 0xC
	ldrsh r4, [r0, r3]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	bls _08194250
	b _081948C2
_08194250:
	lsls r0, 2
	ldr r1, =_08194264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08194264:
	.4byte _0819427C
	.4byte _0819431C
	.4byte _0819438C
	.4byte _0819447C
	.4byte _081944FC
	.4byte _081947C8
_0819427C:
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x3
	bl EnableInterrupts
	movs r4, 0
	str r4, [sp, 0x14]
	add r0, sp, 0x14
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	bl CpuSet
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0860CE74
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0860CE94
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gBattle_BG0_X
	strh r4, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r4, [r0]
	ldr r0, =gBattle_BG1_X
	strh r4, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r4, [r0]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r1, 0xB0
	lsls r1, 4
	movs r0, 0x3
	movs r2, 0
	bl ChangeBgY
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	b _0819443C
	.pool
_0819431C:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00005860
	movs r0, 0x40
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0x9F
	bl SetGpuReg
	ldr r1, =0x00009098
	movs r0, 0x42
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0x9F
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r1, =gTasks
	mov r3, r8
	lsls r0, r3, 2
	b _0819443C
	.pool
_0819438C:
	ldr r4, =gUnknown_0203CD7C
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gUnknown_08D83900
	bl LZDecompressWram
	ldr r1, [r4]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r1, =gUnknown_08D82F10
	movs r5, 0x80
	lsls r5, 6
	movs r6, 0
	str r6, [sp]
	movs r0, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08D834FC
	str r6, [sp]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08D83B2C
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r1, =gUnknown_08D83C3C
	str r4, [sp]
	movs r0, 0x3
	adds r2, r5, 0
	movs r3, 0
	bl copy_decompressed_tile_data_to_vram_autofree
	ldr r0, =gUnknown_08D85358
	movs r4, 0x80
	lsls r4, 2
	movs r1, 0
	adds r2, r4, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08D85444
	movs r1, 0x80
	lsls r1, 1
	adds r2, r4, 0
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08D85600
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadCompressedPalette
	str r6, [sp, 0x18]
	add r0, sp, 0x18
	ldr r1, =gPlttBufferFaded
	ldr r2, =0x05000100
	bl CpuSet
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r1, =gTasks
	mov r4, r8
	lsls r0, r4, 2
_0819443C:
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _081948C2
	.pool
_0819447C:
	ldr r0, =gUnknown_0860CF50
	bl LoadCompressedObjectPic
	mov r0, r8
	lsls r0, 2
	str r0, [sp, 0x1C]
	mov r1, r10
	cmp r1, 0
	bne _081944E8
	movs r5, 0
	ldr r4, =gUnknown_0860D411
_08194492:
	ldrb r1, [r4]
	ldrb r2, [r4, 0x1]
	ldr r0, =gUnknown_0860CFA8
	movs r3, 0
	bl CreateSprite
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x1E
	bls _08194492
	ldr r0, =gTasks
	ldr r1, [sp, 0x1C]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _081944DC
	ldr r0, =gUnknown_0860D008
	movs r1, 0xDA
	movs r2, 0xC
	movs r3, 0
	bl CreateSprite
	b _081944E8
	.pool
_081944DC:
	ldr r0, =gUnknown_0860CFD8
	movs r1, 0xDA
	movs r2, 0xC
	movs r3, 0
	bl CreateSprite
_081944E8:
	ldr r1, =0x00007f40
	movs r0, 0
	bl SetGpuReg
	b _081947A6
	.pool
_081944FC:
	add r0, sp, 0x4
	movs r2, 0
	movs r1, 0x2
	strb r1, [r0, 0x5]
	ldr r0, =gText_BattleTourney
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x6]
	strb r2, [r0, 0x7]
	strb r1, [r0, 0xA]
	strb r2, [r0, 0xB]
	ldrb r0, [r0, 0x5]
	ldr r1, [sp, 0x4]
	add r2, sp, 0x4
	ldrb r3, [r2, 0xA]
	movs r2, 0x70
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	add r1, sp, 0x4
	strb r0, [r1, 0x8]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	adds r3, r1, 0
	ldrb r2, [r3, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	adds r2, r3, 0
	movs r0, 0xE0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	adds r1, r2, 0
	movs r0, 0xD0
	strb r0, [r1, 0xD]
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	mov r3, r8
	lsls r3, 2
	str r3, [sp, 0x1C]
	add r4, sp, 0x4
	movs r0, 0xF
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0x20]
	movs r2, 0
	str r2, [sp, 0x24]
	movs r7, 0
	movs r5, 0xF
_0819456C:
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	adds r0, r7
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 22
	lsrs r1, 22
	ldr r0, =gDisplayedStringBattle
	bl sub_8195898
	mov r2, r10
	cmp r2, 0x1
	bne _081945C4
	ldr r3, =gSaveBlock2Ptr
	ldr r2, [r3]
	adds r0, r2, r7
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 29
	cmp r0, 0
	blt _081945DC
	ldr r3, =0x00000cb2
	adds r0, r2, r3
	ldrh r1, [r0]
	cmp r1, 0x1
	beq _08194634
	ldr r2, [sp, 0x24]
	lsrs r0, r2, 24
	subs r1, 0x2
	b _081945EA
	.pool
_081945C4:
	mov r3, r10
	cmp r3, 0
	bne _08194634
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	adds r0, r2, r7
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 29
	cmp r0, 0
	bge _081945FC
_081945DC:
	lsls r1, 27
	lsrs r0, r1, 30
	cmp r0, 0
	beq _08194634
	subs r1, r0, 0x1
	ldr r2, [sp, 0x24]
	lsrs r0, r2, 24
_081945EA:
	lsls r1, 24
	lsrs r1, 24
	bl sub_81948EC
	b _08194634
	.pool
_081945FC:
	ldr r3, =0x00000cb2
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, 0
	beq _08194634
	ldr r0, [sp, 0x1C]
	add r0, r8
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	movs r3, 0x10
	ldrsh r0, [r0, r3]
	cmp r0, 0
	beq _08194624
	ldrh r1, [r1]
	b _08194628
	.pool
_08194624:
	ldrh r0, [r1]
	subs r1, r0, 0x1
_08194628:
	ldr r2, [sp, 0x24]
	lsrs r0, r2, 24
	lsls r1, 24
	lsrs r1, 24
	bl sub_81948EC
_08194634:
	ldr r0, [sp, 0x1C]
	add r0, r8
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	movs r1, 0x10
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08194660
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r3, =0x00000cb2
	adds r0, r3
	ldrh r3, [r0]
	adds r6, r2, 0
	b _0819466E
	.pool
_08194660:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000cb2
	adds r0, r2
	ldrh r0, [r0]
	subs r3, r0, 0x1
	adds r6, r1, 0
_0819466E:
	mov r0, r10
	cmp r0, 0x1
	bne _0819468E
	ldr r2, [r6]
	adds r0, r2, r7
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 27
	lsrs r1, 30
	ldr r0, =0x00000cb2
	adds r2, r0
	ldrh r0, [r2]
	subs r0, 0x1
	cmp r1, r0
	blt _081946A6
_0819468E:
	mov r1, r10
	cmp r1, 0
	bne _081946FA
	ldr r0, [r6]
	adds r0, r7
	ldr r2, =0x00000d25
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	cmp r0, r3
	bgt _081946FA
_081946A6:
	ldr r0, [r6]
	adds r1, r0, r7
	ldr r3, =0x00000d25
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081946FA
	ldr r2, =0x00000d24
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	ldr r3, =0x000003ff
	cmp r0, r3
	bne _081946F0
	ldrb r1, [r4, 0xC]
	mov r0, r9
	ands r0, r1
	movs r1, 0x30
	orrs r0, r1
	strb r0, [r4, 0xC]
	ldrb r1, [r4, 0xD]
	mov r0, r9
	ands r0, r1
	movs r1, 0x40
	b _08194740
	.pool
_081946F0:
	ldrb r1, [r4, 0xC]
	mov r0, r9
	ands r0, r1
	movs r1, 0xB0
	b _08194734
_081946FA:
	ldr r0, [r6]
	adds r0, r7
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	ldr r2, =0x000003ff
	cmp r0, r2
	bne _0819472C
	ldrb r1, [r4, 0xC]
	mov r0, r9
	ands r0, r1
	movs r1, 0x30
	orrs r0, r1
	strb r0, [r4, 0xC]
	ldrb r1, [r4, 0xD]
	mov r0, r9
	ands r0, r1
	movs r1, 0x40
	b _08194740
	.pool
_0819472C:
	ldrb r1, [r4, 0xC]
	mov r0, r9
	ands r0, r1
	movs r1, 0xE0
_08194734:
	orrs r0, r1
	strb r0, [r4, 0xC]
	ldrb r1, [r4, 0xD]
	mov r0, r9
	ands r0, r1
	movs r1, 0xD0
_08194740:
	orrs r0, r1
	strb r0, [r4, 0xD]
	ldr r0, =gUnknown_0860D3F1
	ldr r3, [sp, 0x20]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08194768
	ldrb r0, [r4, 0x5]
	ldrb r3, [r4, 0xA]
	ldr r1, =gDisplayedStringBattle
	movs r2, 0x3D
	bl GetStringWidthDifference
	b _0819476A
	.pool
_08194768:
	movs r0, 0x3
_0819476A:
	strb r0, [r4, 0x8]
	ldr r0, =gDisplayedStringBattle
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_0860D3F1
	ldr r1, [sp, 0x20]
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r4, 0x4]
	ldr r2, =gUnknown_0860D3F2
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4, 0x9]
	add r0, sp, 0x4
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	ldr r3, [sp, 0x20]
	adds r3, 0x2
	str r3, [sp, 0x20]
	ldr r0, [sp, 0x24]
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	str r0, [sp, 0x24]
	adds r7, 0x4
	subs r5, 0x1
	cmp r5, 0
	blt _081947A6
	b _0819456C
_081947A6:
	ldr r0, =gTasks
	ldr r1, [sp, 0x1C]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _081948C2
	.pool
_081947C8:
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8194BEC
	bl SetHBlankCallback
	ldr r0, =sub_8194CE4
	bl SetVBlankCallback
	cmp r4, 0x2
	bne _0819485C
	mov r2, r10
	cmp r2, 0
	bne _08194844
	ldr r0, =sub_819395C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r2
	mov r3, r10
	strh r3, [r1, 0x8]
	strh r3, [r1, 0xA]
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x10]
	strh r0, [r1, 0x14]
	b _08194878
	.pool
_08194844:
	ldr r0, =sub_8194950
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	b _0819486C
	.pool
_0819485C:
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r3, 0xE
	ldrsh r5, [r0, r3]
_0819486C:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
_08194878:
	bl ScanlineEffect_Clear
	ldr r0, =gScanlineEffectRegBuffers
	ldr r2, =0x00001f0a
	movs r4, 0xF0
	lsls r4, 3
	adds r1, r0, r4
	movs r5, 0x5A
_08194888:
	strh r2, [r0]
	strh r2, [r1]
	adds r1, 0x2
	adds r0, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08194888
	movs r5, 0x5B
	ldr r3, =gUnknown_0860CF44
	ldr r0, =gScanlineEffectRegBuffers
	ldr r2, =0x00001f09
	ldr r4, =0x00000836
	adds r1, r0, r4
	adds r0, 0xB6
_081948A4:
	strh r2, [r0]
	strh r2, [r1]
	adds r1, 0x2
	adds r0, 0x2
	adds r5, 0x1
	cmp r5, 0x9F
	ble _081948A4
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	ldr r2, [r3, 0x8]
	bl ScanlineEffect_SetParams
	mov r0, r8
	bl DestroyTask
_081948C2:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194220

	thumb_func_start sub_81948EC
sub_81948EC: @ 81948EC
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r4, =gUnknown_0860DD10
	lsls r2, r1, 2
	lsls r3, r0, 4
	adds r2, r3
	adds r2, r4
	ldr r3, [r2]
	ldr r2, =gUnknown_0860DE10
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08194938
	movs r7, 0x1
	adds r4, r3, 0
	adds r5, r4, 0x2
	adds r6, r0, 0
_0819491A:
	ldrb r2, [r4]
	ldrb r3, [r4, 0x1]
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	adds r1, r5, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	adds r4, 0x4
	adds r5, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _0819491A
_08194938:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81948EC

	thumb_func_start sub_8194950
sub_8194950: @ 8194950
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _08194974
	b _08194B3C
_08194974:
	lsls r0, 2
	ldr r1, =_08194988
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08194988:
	.4byte _0819499C
	.4byte _081949C0
	.4byte _08194AD4
	.4byte _08194AEE
	.4byte _08194B24
_0819499C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	b _08194B3C
	.pool
_081949C0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081949CE
	b _08194B3C
_081949CE:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	movs r2, 0
	movs r3, 0x2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	movs r1, 0x40
	strh r1, [r0, 0xE]
	add r0, sp, 0x4
	strb r3, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r2, [r0, 0x7]
	strb r3, [r0, 0xA]
	strb r2, [r0, 0xB]
	adds r3, r0, 0
	ldrb r2, [r3, 0xC]
	subs r1, 0x50
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	adds r2, r3, 0
	movs r0, 0xB0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	adds r1, r2, 0
	movs r0, 0xD0
	strb r0, [r1, 0xD]
	movs r7, 0
	ldr r0, =gDisplayedStringBattle
	mov r9, r0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	adds r4, r2, 0
	ldr r6, =gUnknown_0860D3F1
	movs r5, 0
_08194A1C:
	mov r2, r8
	ldr r0, [r2]
	adds r0, r5
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 22
	lsrs r1, 22
	mov r0, r9
	bl sub_8195898
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r5
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r3, [r0]
	lsls r1, r3, 27
	lsrs r1, 30
	ldr r0, =0x00000cb2
	adds r2, r0
	ldrh r0, [r2]
	subs r0, 0x1
	cmp r1, r0
	bne _08194A9E
	lsls r0, r3, 29
	cmp r0, 0
	bge _08194A9E
	ldrb r0, [r6]
	cmp r0, 0
	bne _08194A84
	ldrb r0, [r4, 0x5]
	ldrb r3, [r4, 0xA]
	mov r1, r9
	movs r2, 0x3D
	bl GetStringWidthDifference
	b _08194A86
	.pool
_08194A84:
	movs r0, 0x3
_08194A86:
	strb r0, [r4, 0x8]
	mov r1, r9
	str r1, [sp, 0x4]
	ldrb r0, [r6]
	strb r0, [r4, 0x4]
	ldrb r0, [r6, 0x1]
	strb r0, [r4, 0x9]
	add r0, sp, 0x4
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
_08194A9E:
	mov r2, r8
	ldr r1, [r2]
	adds r0, r1, r5
	ldr r2, =0x00000d25
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08194AC4
	subs r2, 0x73
	adds r0, r1, r2
	ldrh r1, [r0]
	subs r1, 0x1
	lsls r0, r7, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl sub_81948EC
_08194AC4:
	adds r6, 0x2
	adds r5, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _08194A1C
	b _08194B3C
	.pool
_08194AD4:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0xE]
	subs r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08194B3C
	movs r0, 0x3
	strh r0, [r1, 0x8]
	b _08194B3C
_08194AEE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08194B3C
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
	movs r1, 0x4
	strh r1, [r0, 0x8]
	b _08194B3C
	.pool
_08194B24:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08194B3C
	ldr r0, =CB2_ReturnToFieldContinueScript
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08194B3C:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194950

	thumb_func_start sub_8194B54
sub_8194B54: @ 8194B54
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_8194B54

	thumb_func_start sub_8194B70
sub_8194B70: @ 8194B70
	push {lr}
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x2
	bl ChangeBgY
	ldr r0, =gBattle_BG0_X
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gBattle_BG0_Y
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gBattle_BG1_X
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gBattle_BG1_Y
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, =gBattle_BG2_X
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	ldr r0, =gBattle_BG2_Y
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194B70

	thumb_func_start sub_8194BEC
sub_8194BEC: @ 8194BEC
	push {lr}
	ldr r0, =0x04000006
	ldrh r0, [r0]
	adds r1, r0, 0
	cmp r0, 0x29
	bls _08194CC8
	cmp r0, 0x31
	bhi _08194C1C
	ldr r1, =0x04000048
	ldr r2, =0x00003b3b
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x989b5558
	b _08194CD4
	.pool
_08194C1C:
	cmp r0, 0x39
	bls _08194CC8
	cmp r0, 0x4A
	bhi _08194C40
	ldr r1, =0x04000048
	ldr r2, =0x00003b3b
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x90985860
	b _08194CD4
	.pool
_08194C40:
	cmp r0, 0x51
	bhi _08194C60
	ldr r1, =0x04000048
	ldr r2, =0x00003b3b
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x989b5558
	b _08194CD4
	.pool
_08194C60:
	cmp r0, 0x5E
	bls _08194CC8
	cmp r0, 0x66
	bhi _08194C84
	ldr r1, =0x04000048
	ldr r2, =0x00003737
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x989b5558
	b _08194CD4
	.pool
_08194C84:
	cmp r0, 0x76
	bhi _08194CA4
	ldr r1, =0x04000048
	ldr r2, =0x00003737
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x90985860
	b _08194CD4
	.pool
_08194CA4:
	cmp r0, 0x7E
	bls _08194CC8
	cmp r1, 0x86
	bhi _08194CC8
	ldr r1, =0x04000048
	ldr r2, =0x00003737
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =0x989b5558
	b _08194CD4
	.pool
_08194CC8:
	ldr r1, =0x04000048
	ldr r2, =0x00003f3f
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x8
	movs r0, 0
_08194CD4:
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194BEC

	thumb_func_start sub_8194CE4
sub_8194CE4: @ 8194CE4
	push {lr}
	ldr r0, =gBattle_BG0_X
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, =gBattle_BG0_Y
	ldrh r1, [r0]
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =gBattle_BG1_X
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gBattle_BG1_Y
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	movs r0, 0x2
	movs r1, 0x80
	movs r2, 0x2
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgY
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194CE4

	thumb_func_start sub_8194D48
sub_8194D48: @ 8194D48
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gBattleFrontierMons
	str r0, [r1]
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8194D48

	thumb_func_start sub_8194D68
sub_8194D68: @ 8194D68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r3, 0
_08194D76:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =gUnknown_0203CEF8
	adds r0, r3, r0
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 1
	ldr r2, =0x00000caa
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	mov r10, r0
	movs r6, 0
	adds r0, r3, 0x1
	str r0, [sp]
	movs r1, 0x64
	mov r0, r10
	muls r0, r1
	movs r2, 0x8E
	lsls r2, 2
	adds r2, r0
	mov r9, r2
	adds r7, r3, 0
	muls r7, r1
_08194DA8:
	movs r5, 0
	adds r0, r6, 0x1
	mov r8, r0
	b _08194DBE
	.pool
_08194DBC:
	adds r5, 0x1
_08194DBE:
	cmp r5, 0x3
	bgt _08194DEA
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	add r0, r9
	adds r1, r5, 0
	adds r1, 0xD
	movs r2, 0
	str r3, [sp, 0x4]
	bl GetMonData
	adds r4, r0, 0
	adds r1, r6, 0
	adds r1, 0xD
	ldr r2, =gPlayerParty
	adds r0, r7, r2
	movs r2, 0
	bl GetMonData
	ldr r3, [sp, 0x4]
	cmp r4, r0
	bne _08194DBC
_08194DEA:
	cmp r5, 0x4
	bne _08194E00
	lsls r2, r6, 24
	lsrs r2, 24
	ldr r1, =gPlayerParty
	adds r0, r7, r1
	movs r1, 0xA6
	str r3, [sp, 0x4]
	bl SetMonMoveSlot
	ldr r3, [sp, 0x4]
_08194E00:
	mov r6, r8
	cmp r6, 0x3
	ble _08194DA8
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	movs r2, 0x64
	mov r1, r10
	muls r1, r2
	adds r0, r1
	movs r1, 0x8E
	lsls r1, 2
	adds r0, r1
	adds r1, r3, 0
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	ldr r3, [sp]
	cmp r3, 0x1
	ble _08194D76
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194D68

	thumb_func_start sub_8194E44
sub_8194E44: @ 8194E44
	push {r4-r7,lr}
	sub sp, 0x4
	movs r4, 0
	ldr r7, =gSaveBlock1Ptr
	movs r6, 0x64
	movs r5, 0
_08194E50:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =gUnknown_0203CEF8
	adds r0, r4, r0
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 1
	ldr r2, =0x00000caa
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	adds r1, r0, 0
	muls r1, r6
	movs r0, 0x8E
	lsls r0, 2
	adds r1, r0
	ldr r0, [r7]
	adds r0, r1
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	ldr r0, =gPlayerParty
	adds r0, r5, r0
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r5, 0x64
	adds r4, 0x1
	cmp r4, 0x1
	ble _08194E50
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194E44

	thumb_func_start sub_8194EB4
sub_8194EB4: @ 8194EB4
	push {lr}
	bl sub_80F94E8
	pop {r0}
	bx r0
	thumb_func_end sub_8194EB4

	thumb_func_start sub_8194EC0
sub_8194EC0: @ 8194EC0
	push {r4,lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_8195358
	adds r4, r0, 0
	ldr r0, =0x000003ff
	bl sub_8195358
	cmp r4, r0
	ble _08194EE8
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _08194EEC
	.pool
_08194EE8:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
_08194EEC:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194EC0

	thumb_func_start sub_8194EF8
sub_8194EF8: @ 8194EF8
	push {r4,lr}
	bl sub_8194D48
	movs r2, 0
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r1, =0x00000d25
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _08194F2A
	adds r4, r3, 0
	adds r3, r1, 0
_08194F14:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _08194F2A
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _08194F14
_08194F2A:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	lsls r2, 2
	adds r1, r2
	ldr r2, =0x00000d24
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 22
	lsrs r1, 22
	bl sub_8195898
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194EF8

	thumb_func_start sub_8194F58
sub_8194F58: @ 8194F58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldr r5, =0x00000d0a
	adds r0, r2, r5
	ldrb r1, [r0]
	ldr r6, =0x00000d0b
	adds r0, r2, r6
	ldrb r0, [r0]
	cmn r1, r0
	beq _08194F8C
	ldr r1, =0x00000ca8
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08194F8C
	b _0819533E
_08194F8C:
	movs r0, 0x20
	bl AllocZeroed
	str r0, [sp, 0x18]
	movs r0, 0x18
	bl AllocZeroed
	str r0, [sp, 0x1C]
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r1, r2
	ldrb r2, [r1]
	lsls r0, r2, 30
	lsrs r0, 30
	str r0, [sp, 0x14]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0x1
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r6
	strb r1, [r0]
	movs r3, 0
	mov r10, r3
	movs r4, 0
	str r4, [sp, 0x38]
	movs r5, 0
	str r5, [sp, 0x3C]
_08194FCC:
	mov r0, r10
	cmp r0, 0x4
	bgt _08194FFC
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	b _08195030
	.pool
_08194FFC:
	mov r1, r10
	cmp r1, 0xE
	bgt _0819501A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0, 0
	adds r4, 0xA
	b _08195030
_0819501A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0, 0
	adds r4, 0x1E
_08195030:
	movs r6, 0
	cmp r6, r10
	bge _08195064
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r3, =0x00000d24
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r4
	beq _08195064
	adds r3, r2, 0
	ldr r2, =0x00000d24
_0819504C:
	adds r6, 0x1
	cmp r6, r10
	bge _08195064
	ldr r0, [r3]
	lsls r1, r6, 2
	adds r0, r1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r4
	bne _0819504C
_08195064:
	cmp r6, r10
	bne _08194FCC
	ldr r5, =gSaveBlock2Ptr
	ldr r3, [r5]
	ldr r0, [sp, 0x38]
	adds r3, r0
	ldr r1, =0x00000d24
	adds r3, r1
	ldr r2, =0x000003ff
	adds r0, r2, 0
	adds r2, r4, 0
	ands r2, r0
	ldrh r0, [r3]
	ldr r5, =0xfffffc00
	adds r1, r5, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	movs r6, 0
	lsls r4, 16
	str r4, [sp, 0x30]
	ldr r0, [sp, 0x3C]
	str r0, [sp, 0x20]
_08195092:
	adds r1, r6, 0x1
	str r1, [sp, 0x24]
	lsls r2, r6, 2
	str r2, [sp, 0x2C]
	lsls r3, r6, 1
	str r3, [sp, 0x28]
_0819509E:
	ldr r4, [sp, 0x30]
	lsrs r0, r4, 16
	bl sub_8163524
	lsls r0, 16
	lsrs r5, r0, 16
	movs r7, 0
	cmp r7, r6
	bge _081950F4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =gUnknown_0203BC8C
	mov r9, r1
	ldr r2, [sp, 0x8]
	mov r8, r2
	ldr r3, [sp, 0xC]
	mov r12, r3
	ldr r4, =0x00000d64
	adds r0, r4
	ldr r1, [sp, 0x20]
	adds r4, r1, r0
_081950C8:
	ldrh r3, [r4]
	cmp r3, r5
	beq _081950F4
	mov r2, r9
	ldr r1, [r2]
	lsls r0, r5, 4
	adds r2, r0, r1
	ldrh r0, [r2]
	cmp r8, r0
	beq _081950F4
	cmp r12, r0
	beq _081950F4
	lsls r0, r3, 4
	adds r0, r1
	ldrb r0, [r0, 0xA]
	ldrb r2, [r2, 0xA]
	cmp r0, r2
	beq _081950F4
	adds r4, 0x2
	adds r7, 0x1
	cmp r7, r6
	blt _081950C8
_081950F4:
	cmp r7, r6
	bne _0819509E
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r4, [sp, 0x28]
	ldr r2, [sp, 0x3C]
	adds r1, r4, r2
	ldr r3, =0x00000d64
	adds r0, r3
	adds r0, r1
	strh r5, [r0]
	ldr r2, [sp, 0x2C]
	add r2, sp
	adds r2, 0x8
	ldr r3, =gUnknown_0203BC8C
	ldr r1, [r3]
	lsls r0, r5, 4
	adds r0, r1
	ldrh r0, [r0]
	str r0, [r2]
	ldr r6, [sp, 0x24]
	cmp r6, 0x2
	ble _08195092
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldr r5, [sp, 0x38]
	adds r2, r5
	ldr r0, =0x00000d25
	adds r2, r0
	ldrb r0, [r2]
	movs r4, 0x5
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r5, =gSaveBlock2Ptr
	ldr r2, [r5]
	ldr r0, [sp, 0x38]
	adds r2, r0
	ldr r1, =0x00000d25
	adds r2, r1
	ldrb r0, [r2]
	subs r4, 0x14
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r5]
	ldr r5, [sp, 0x38]
	adds r1, r5
	ldr r0, =0x00000d25
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	strb r0, [r1]
	adds r5, 0x4
	str r5, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	adds r1, 0x6
	str r1, [sp, 0x3C]
	movs r2, 0x1
	add r10, r2
	mov r4, r10
	cmp r4, 0xF
	bgt _08195178
	b _08194FCC
_08195178:
	movs r5, 0
	mov r10, r5
	ldr r5, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x34]
_08195182:
	movs r7, 0
	strh r7, [r5]
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	mov r2, r10
	lsls r1, r2, 2
	adds r0, r1
	ldr r3, =0x00000d24
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	bl sub_8190168
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r6, 0
	ldr r4, [sp, 0x34]
	mov r9, r4
_081951AA:
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	mov r4, r9
	add r4, r10
	adds r4, r6
	lsls r4, 1
	ldr r2, =0x00000d64
	adds r0, r2
	adds r0, r4
	ldrh r1, [r0]
	ldr r3, =gUnknown_0203BC8C
	ldr r0, [r3]
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrb r3, [r1, 0xB]
	ldrb r1, [r1, 0xC]
	str r1, [sp]
	ldr r1, [sp, 0x1C]
	str r1, [sp, 0x4]
	movs r1, 0x32
	mov r2, r8
	bl sub_818F720
	ldr r2, [sp, 0x1C]
	ldr r1, [r2, 0x4]
	ldrh r0, [r5]
	adds r0, r1
	ldr r1, [r2, 0x8]
	adds r0, r1
	ldr r1, [r2, 0x10]
	adds r0, r1
	ldr r1, [r2, 0x14]
	adds r0, r1
	ldr r1, [r2, 0xC]
	adds r0, r1
	ldr r1, [r2]
	adds r0, r1
	strh r0, [r5]
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r1, =0x00000d64
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	ldr r2, =gUnknown_0203BC8C
	ldr r1, [r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r3, =gBaseStats
	adds r1, r3
	ldrb r0, [r1, 0x6]
	lsls r0, 2
	ldr r4, =gBitTable
	adds r0, r4
	ldr r0, [r0]
	orrs r7, r0
	ldrb r0, [r1, 0x7]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	orrs r7, r0
	adds r6, 0x1
	cmp r6, 0x2
	ble _081951AA
	movs r4, 0
	movs r1, 0x1
	movs r6, 0x1F
_0819523A:
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08195244
	adds r4, 0x1
_08195244:
	asrs r7, 1
	subs r6, 0x1
	cmp r6, 0
	bge _0819523A
	movs r1, 0x32
	adds r0, r4, 0
	muls r0, r1
	movs r1, 0x14
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r0
	strh r1, [r5]
	adds r5, 0x2
	ldr r2, [sp, 0x34]
	adds r2, 0x2
	str r2, [sp, 0x34]
	movs r3, 0x1
	add r10, r3
	mov r4, r10
	cmp r4, 0xF
	ble _08195182
	movs r5, 0
	mov r10, r5
	ldr r7, [sp, 0x18]
_08195276:
	mov r6, r10
	adds r6, 0x1
	cmp r6, 0xF
	bgt _081952F8
	mov r8, r7
	ldr r5, =0x00000d24
	lsls r0, r6, 1
	ldr r1, [sp, 0x18]
	adds r4, r0, r1
_08195288:
	mov r2, r8
	ldrh r1, [r2]
	ldrh r0, [r4]
	cmp r1, r0
	bcs _081952C4
	mov r0, r10
	adds r1, r6, 0
	ldr r2, [sp, 0x18]
	bl sub_818F904
	b _081952F0
	.pool
_081952C4:
	cmp r1, r0
	bne _081952F0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	mov r3, r10
	lsls r0, r3, 2
	adds r0, r1, r0
	adds r0, r5
	ldrh r2, [r0]
	lsls r2, 22
	lsls r0, r6, 2
	adds r1, r0
	adds r1, r5
	ldrh r0, [r1]
	lsls r0, 22
	cmp r2, r0
	bls _081952F0
	mov r0, r10
	adds r1, r6, 0
	ldr r2, [sp, 0x18]
	bl sub_818F904
_081952F0:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0xF
	ble _08195288
_081952F8:
	adds r7, 0x2
	movs r4, 0x1
	add r10, r4
	mov r5, r10
	cmp r5, 0xE
	ble _08195276
	ldr r0, [sp, 0x18]
	bl Free
	ldr r0, [sp, 0x1C]
	bl Free
	movs r0, 0
	mov r10, r0
_08195314:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_8195438
	movs r2, 0x1
	add r10, r2
	mov r3, r10
	cmp r3, 0x3
	ble _08195314
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r4, =0x00000ca9
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	ldr r5, [sp, 0x14]
	orrs r0, r5
	strb r0, [r1]
_0819533E:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8194F58

	thumb_func_start sub_8195358
sub_8195358: @ 8195358
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r3
	beq _0819538E
	adds r5, r4, 0
	adds r4, r1, 0
_08195376:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _0819538E
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r3
	bne _08195376
_0819538E:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8195358

	thumb_func_start sub_81953A0
sub_81953A0: @ 81953A0
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r3
	beq _081953D6
	adds r5, r4, 0
	adds r4, r1, 0
_081953BE:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _081953D6
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	cmp r0, r3
	bne _081953BE
_081953D6:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81953A0

	thumb_func_start sub_81953E8
sub_81953E8: @ 81953E8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0860D1A0
	ldr r0, =gUnknown_0860D1C0
	adds r0, r4, r0
	ldrb r0, [r0]
	lsrs r0, 1
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	bl sub_8192F08
	mov r0, sp
	ldrb r0, [r0]
	cmp r4, r0
	beq _0819542C
	mov r0, sp
	ldrb r0, [r0]
	b _08195430
	.pool
_0819542C:
	mov r0, sp
	ldrb r0, [r0, 0x1]
_08195430:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81953E8

	thumb_func_start sub_8195438
sub_8195438: @ 8195438
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r1, 0
	str r1, [sp, 0x10]
	movs r5, 0
	movs r1, 0x3
	ldr r0, [sp]
	ands r0, r1
	lsls r0, 3
	str r0, [sp, 0x14]
_0819545E:
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	lsls r4, r5, 2
	adds r1, r0, r4
	ldr r3, =0x00000d25
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 29
	adds r2, r5, 0x1
	str r2, [sp, 0x24]
	cmp r0, 0
	bge _08195478
	b _08195876
_08195478:
	subs r3, 0x1
	adds r0, r1, r3
	ldrh r0, [r0]
	lsls r1, r0, 22
	ldr r0, =0xffc00000
	cmp r1, r0
	bne _08195488
	b _08195876
_08195488:
	str r5, [sp, 0x4]
	lsrs r1, 22
	ldr r0, [sp]
	bl sub_81901A0
	str r0, [sp, 0x8]
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	adds r0, r3, r4
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	ldr r1, =0xff800000
	cmp r0, r1
	bne _08195504
	ldr r2, [sp, 0x8]
	cmp r2, 0xFF
	beq _08195504
	lsls r2, 2
	adds r1, r3, r2
	ldr r3, =0x00000d25
	adds r1, r3
	ldrb r0, [r1]
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, r2
	ldr r2, =0x00000d25
	adds r1, r2
	ldrb r0, [r1]
	subs r3, 0x1D
	ands r0, r3
	ldr r2, [sp, 0x14]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r5, 0
	ldr r1, [sp, 0x8]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	ldr r5, [sp, 0x8]
	lsls r2, r5, 1
	movs r3, 0xEC
	lsls r3, 4
	adds r1, r3
	adds r1, r2
	b _08195874
	.pool
_08195504:
	ldr r4, =gSaveBlock2Ptr
	ldr r3, [r4]
	ldr r0, [sp, 0x8]
	lsls r2, r0, 2
	adds r0, r3, r2
	ldr r1, =0x00000d24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	ldr r1, =0xff800000
	str r2, [sp, 0x30]
	cmp r0, r1
	bne _0819557C
	ldr r2, [sp, 0x4]
	cmp r2, 0xFF
	beq _0819557C
	lsls r2, 2
	adds r1, r3, r2
	ldr r3, =0x00000d25
	adds r1, r3
	ldrb r0, [r1]
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r2
	ldr r0, =0x00000d25
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x19
	negs r2, r2
	ands r0, r2
	ldr r3, [sp, 0x14]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x4]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r1, [r4]
	ldr r3, [sp, 0x4]
	lsls r2, r3, 1
	movs r3, 0xEC
	lsls r3, 4
	adds r1, r3
	adds r1, r2
	strh r0, [r1]
	adds r5, 0x1
	str r5, [sp, 0x24]
	b _08195876
	.pool
_0819557C:
	adds r5, 0x1
	str r5, [sp, 0x24]
	ldr r5, [sp, 0x8]
	cmp r5, 0xFF
	bne _08195588
	b _08195876
_08195588:
	movs r0, 0
	mov r10, r0
	lsls r1, r5, 1
	str r1, [sp, 0x2C]
	ldr r2, [sp, 0x4]
	lsls r2, 1
	str r2, [sp, 0x28]
	ldr r3, [sp, 0x4]
	adds r0, r2, r3
	lsls r0, 1
	mov r9, r0
	adds r0, r1, r5
	lsls r0, 1
	str r0, [sp, 0x18]
_081955A4:
	movs r5, 0
	mov r0, r9
	str r0, [sp, 0x38]
_081955AA:
	movs r6, 0
	lsls r7, r5, 1
	ldr r4, [sp, 0x18]
_081955B0:
	ldr r2, =gSaveBlock2Ptr
	ldr r1, [r2]
	ldr r3, =0x00000d64
	adds r1, r3
	ldr r2, [sp, 0x38]
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r3, =gUnknown_0203BC8C
	mov r8, r3
	ldr r2, [r3]
	lsls r0, 4
	adds r0, r2
	adds r0, 0x2
	adds r0, r7
	ldrh r0, [r0]
	adds r1, r4
	ldrh r1, [r1]
	lsls r1, 4
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x2
	bl sub_818FFC0
	ldr r1, [sp, 0xC]
	adds r1, r0
	str r1, [sp, 0xC]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x2
	ble _081955B0
	adds r5, 0x1
	cmp r5, 0x3
	ble _081955AA
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r3, =0x00000d64
	adds r0, r3
	add r0, r9
	ldrh r0, [r0]
	mov r5, r8
	ldr r1, [r5]
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0]
	ldr r0, =gBaseStats
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	ldrb r2, [r1, 0x1]
	adds r0, r2
	ldrb r2, [r1, 0x2]
	adds r0, r2
	ldrb r2, [r1, 0x3]
	adds r0, r2
	ldrb r3, [r1, 0x4]
	adds r0, r3
	ldrb r1, [r1, 0x5]
	adds r0, r1
	movs r1, 0xA
	bl __divsi3
	ldr r5, [sp, 0xC]
	adds r5, r0
	str r5, [sp, 0xC]
	movs r0, 0x2
	add r9, r0
	movs r1, 0x1
	add r10, r1
	mov r2, r10
	cmp r2, 0x2
	ble _081955A4
	bl Random
	movs r1, 0x1F
	ands r1, r0
	adds r5, r1
	ldr r3, [sp, 0x4]
	adds r5, r3
	str r5, [sp, 0xC]
	movs r5, 0
	mov r10, r5
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x8]
	adds r0, r1, r2
	lsls r0, 1
	str r0, [sp, 0x1C]
	ldr r5, [sp, 0x28]
	adds r0, r5, r3
	lsls r0, 1
	str r0, [sp, 0x20]
_08195668:
	movs r5, 0
	mov r0, r10
	lsls r3, r0, 1
	movs r1, 0x1
	add r10, r1
	ldr r2, [sp, 0x1C]
	adds r2, r3
	mov r8, r2
_08195678:
	movs r6, 0
	lsls r7, r5, 1
	adds r5, 0x1
	str r5, [sp, 0x3C]
	ldr r4, [sp, 0x20]
_08195682:
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r0, =0x00000d64
	adds r1, r0
	mov r2, r8
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r5, =gUnknown_0203BC8C
	mov r9, r5
	ldr r2, [r5]
	lsls r0, 4
	adds r0, r2
	adds r0, 0x2
	adds r0, r7
	ldrh r0, [r0]
	adds r1, r4
	ldrh r1, [r1]
	lsls r1, 4
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x2
	str r3, [sp, 0x34]
	bl sub_818FFC0
	ldr r1, [sp, 0x10]
	adds r1, r0
	str r1, [sp, 0x10]
	adds r4, 0x2
	adds r6, 0x1
	ldr r3, [sp, 0x34]
	cmp r6, 0x2
	ble _08195682
	ldr r5, [sp, 0x3C]
	cmp r5, 0x3
	ble _08195678
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldr r5, [sp, 0x1C]
	adds r1, r3, r5
	ldr r2, =0x00000d64
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	mov r3, r9
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0]
	ldr r0, =gBaseStats
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	ldrb r2, [r1, 0x1]
	adds r0, r2
	ldrb r5, [r1, 0x2]
	adds r0, r5
	ldrb r2, [r1, 0x3]
	adds r0, r2
	ldrb r2, [r1, 0x4]
	adds r0, r2
	ldrb r1, [r1, 0x5]
	adds r0, r1
	movs r1, 0xA
	bl __divsi3
	ldr r3, [sp, 0x10]
	adds r3, r0
	str r3, [sp, 0x10]
	mov r5, r10
	cmp r5, 0x2
	ble _08195668
	bl Random
	movs r1, 0x1F
	ands r1, r0
	ldr r0, [sp, 0x10]
	adds r0, r1
	ldr r1, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r2, [sp, 0xC]
	cmp r2, r0
	ble _08195784
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	ldr r5, [sp, 0x30]
	adds r1, r5
	ldr r0, =0x00000d25
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, r5
	ldr r3, =0x00000d25
	adds r1, r3
	ldrb r0, [r1]
	movs r5, 0x19
	negs r5, r5
	ands r0, r5
	ldr r2, [sp, 0x14]
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x8]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	movs r5, 0xEC
	lsls r5, 4
	adds r1, r5
	ldr r2, [sp, 0x2C]
	adds r1, r2
	b _08195874
	.pool
_08195784:
	ldr r3, [sp, 0xC]
	ldr r5, [sp, 0x10]
	cmp r3, r5
	bge _081957DC
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r3, [sp, 0x4]
	lsls r2, r3, 2
	adds r1, r2
	ldr r5, =0x00000d25
	adds r1, r5
	ldrb r0, [r1]
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1]
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	adds r1, r2
	ldr r0, =0x00000d25
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x19
	negs r2, r2
	ands r0, r2
	ldr r3, [sp, 0x14]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x4]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r1, [r5]
	movs r5, 0xEC
	lsls r5, 4
	adds r1, r5
	ldr r2, [sp, 0x28]
	adds r1, r2
	b _08195874
	.pool
_081957DC:
	ldr r3, [sp, 0x4]
	ldr r5, [sp, 0x8]
	cmp r3, r5
	ble _08195830
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, [sp, 0x30]
	adds r1, r2
	ldr r3, =0x00000d25
	adds r1, r3
	ldrb r0, [r1]
	movs r5, 0x4
	orrs r0, r5
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, r2
	adds r1, r3
	ldrb r0, [r1]
	movs r2, 0x19
	negs r2, r2
	ands r0, r2
	ldr r3, [sp, 0x14]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x8]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	movs r2, 0xEC
	lsls r2, 4
	adds r1, r2
	ldr r3, [sp, 0x2C]
	b _08195872
	.pool
_08195830:
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r0, [sp, 0x4]
	lsls r2, r0, 2
	adds r1, r2
	ldr r3, =0x00000d25
	adds r1, r3
	ldrb r0, [r1]
	movs r5, 0x4
	orrs r0, r5
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, r2
	adds r1, r3
	ldrb r0, [r1]
	movs r2, 0x19
	negs r2, r2
	ands r0, r2
	ldr r3, [sp, 0x14]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x4]
	ldr r2, [sp]
	bl sub_8193ED0
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	movs r2, 0xEC
	lsls r2, 4
	adds r1, r2
	ldr r3, [sp, 0x28]
_08195872:
	adds r1, r3
_08195874:
	strh r0, [r1]
_08195876:
	ldr r5, [sp, 0x24]
	cmp r5, 0xF
	bgt _0819587E
	b _0819545E
_0819587E:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195438

	thumb_func_start sub_8195898
sub_8195898: @ 8195898
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
	bl sub_8165C40
	ldr r0, =0x000003fe
	cmp r5, r0
	bne _081958B8
	adds r0, r6, 0
	bl sub_8195938
	b _08195902
	.pool
_081958B8:
	ldr r0, =0x000003ff
	cmp r5, r0
	bne _081958DC
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
_081958C2:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	ble _081958C2
	b _081958FC
	.pool
_081958DC:
	ldr r0, =0x0000012b
	cmp r5, r0
	bhi _081958FC
	ldr r0, =gUnknown_0203BC88
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r5
	adds r0, r1
	adds r2, r0, 0x4
_081958EE:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	ble _081958EE
_081958FC:
	adds r1, r6, r4
	movs r0, 0xFF
	strb r0, [r1]
_08195902:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195898

	thumb_func_start sub_8195910
sub_8195910: @ 8195910
	ldr r0, =gTrainers
	ldr r1, =0x00007df3
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8195910

	thumb_func_start sub_8195924
sub_8195924: @ 8195924
	ldr r0, =gTrainers
	ldr r1, =0x00007df1
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8195924

	thumb_func_start sub_8195938
sub_8195938: @ 8195938
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r4, =(gTrainers + 806 * 0x28 + 0x4) @ TRAINER_TUCKER name
_08195940:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x6
	ble _08195940
	adds r1, r3, r2
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195938

	thumb_func_start sub_8195960
sub_8195960: @ 8195960
	push {lr}
	ldr r1, =gUnknown_0860DE50
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195960

	thumb_func_start sub_8195980
sub_8195980: @ 8195980
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, [r4]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r6, 0
	strb r6, [r0]
	ldr r1, [r4]
	adds r2, 0xA
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r4, [r4]
	ldr r0, =0x00000cdc
	adds r3, r4, r0
	ldr r2, =gUnknown_0860DE98
	lsls r1, r5, 2
	lsls r0, r7, 3
	adds r1, r0
	adds r1, r2
	ldr r0, [r3]
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _081959F2
	lsls r0, r5, 1
	lsls r1, r7, 2
	adds r0, r1
	ldr r2, =0x00000dc8
	adds r1, r4, r2
	adds r1, r0
	strh r6, [r1]
_081959F2:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	ldr r0, =gTrainerBattleOpponent_A
	strh r6, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195980

	thumb_func_start sub_8195A38
sub_8195A38: @ 8195A38
	push {r4-r7,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r7, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08195A90
	cmp r0, 0x1
	bgt _08195A74
	cmp r0, 0
	beq _08195A7A
	b _08195AD0
	.pool
_08195A74:
	cmp r0, 0x2
	beq _08195AB0
	b _08195AD0
_08195A7A:
	ldr r0, =gSpecialVar_Result
	ldr r1, [r5]
	ldr r2, =0x00000dc6
	adds r1, r2
	ldrh r1, [r1]
	strh r1, [r0]
	b _08195AD0
	.pool
_08195A90:
	ldr r3, =gSpecialVar_Result
	ldr r0, [r5]
	lsls r1, r7, 1
	lsls r2, r6, 2
	adds r1, r2
	ldr r2, =0x00000dc8
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	b _08195AD0
	.pool
_08195AB0:
	ldr r4, =gSpecialVar_Result
	ldr r2, [r5]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_0860DE98
	lsls r0, r7, 2
	lsls r1, r6, 3
	adds r0, r1
	adds r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	strh r0, [r4]
_08195AD0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195A38

	thumb_func_start sub_8195AE4
sub_8195AE4: @ 8195AE4
	push {r4-r6,lr}
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _08195B3C
	cmp r0, 0x1
	bgt _08195B20
	cmp r0, 0
	beq _08195B26
	b _08195BA0
	.pool
_08195B20:
	cmp r0, 0x2
	beq _08195B5C
	b _08195BA0
_08195B26:
	ldr r0, [r6]
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	ldr r2, =0x00000dc6
	adds r0, r2
	strh r1, [r0]
	b _08195BA0
	.pool
_08195B3C:
	ldr r2, [r6]
	lsls r0, r5, 1
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, =0x00000dc8
	adds r2, r1
	adds r2, r0
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	strh r0, [r2]
	b _08195BA0
	.pool
_08195B5C:
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _08195B88
	ldr r2, [r6]
	ldr r0, =0x00000cdc
	adds r2, r0
	ldr r3, =gUnknown_0860DE98
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	orrs r0, r1
	b _08195B9E
	.pool
_08195B88:
	ldr r2, [r6]
	ldr r1, =0x00000cdc
	adds r2, r1
	ldr r3, =gUnknown_0860DEA8
	lsls r1, r5, 2
	lsls r0, r4, 3
	adds r1, r0
	adds r1, r3
	ldr r0, [r2]
	ldr r1, [r1]
	ands r0, r1
_08195B9E:
	str r0, [r2]
_08195BA0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195AE4

	thumb_func_start sub_8195BB0
sub_8195BB0: @ 8195BB0
	push {r4,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r1, =gSaveBlock2Ptr
	ldr r2, [r1]
	ldr r3, =0x00000ca9
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 30
	lsrs r1, 29
	lsrs r0, 14
	adds r1, r0
	ldr r0, =0x00000dc8
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, 0x31
	bhi _08195C00
	ldr r4, =gSpecialVar_Result
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	strh r0, [r4]
	b _08195C16
	.pool
_08195C00:
	cmp r0, 0x62
	bhi _08195C10
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	b _08195C14
	.pool
_08195C10:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x4
_08195C14:
	strh r0, [r1]
_08195C16:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195BB0

	thumb_func_start sub_8195C20
sub_8195C20: @ 8195C20
	push {r4,lr}
	ldr r4, =gTrainerBattleOpponent_A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xFF
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsrs r1, 6
	strh r1, [r4]
	ldrh r0, [r4]
	movs r1, 0
	bl sub_8162614
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C20

	thumb_func_start sub_8195C50
sub_8195C50: @ 8195C50
	push {lr}
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r1, [r3]
	ldr r0, =0x0000012b
	cmp r1, r0
	bhi _08195C6C
	ldr r2, =gUnknown_0203BC88
	movs r0, 0x34
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xC
	bl ConvertBattleFrontierTrainerSpeechToString
_08195C6C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C50

	thumb_func_start sub_8195C7C
sub_8195C7C: @ 8195C7C
	push {r4-r7,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r7, r0, 30
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 24
	ldr r4, [r4]
	lsls r1, r7, 1
	lsrs r5, r0, 22
	adds r1, r5
	ldr r3, =0x00000dc8
	adds r6, r4, r3
	adds r3, r6, r1
	ldrh r2, [r3]
	ldr r0, =0x0000270e
	cmp r2, r0
	bhi _08195CCA
	adds r2, 0x1
	strh r2, [r3]
	movs r3, 0xDD
	lsls r3, 4
	adds r0, r4, r3
	adds r1, r0, r1
	adds r0, r5, 0
	ldrh r3, [r1]
	cmp r7, r3
	bls _08195CC0
	adds r0, 0x2
_08195CC0:
	adds r0, r6, r0
	ldrh r0, [r0]
	cmp r0, 0
	beq _08195CCA
	strh r2, [r1]
_08195CCA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195C7C

	thumb_func_start sub_8195CE4
sub_8195CE4: @ 8195CE4
	push {r4,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0
	bl VarSet
	ldr r1, [r4]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl sub_81A4C30
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195CE4

	thumb_func_start sub_8195D28
sub_8195D28: @ 8195D28
	push {r4,r5,lr}
	ldr r0, =0x000040ce
	bl VarGet
	lsls r0, 16
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldr r3, =0x00000ca9
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, 30
	lsrs r1, 29
	lsrs r0, 14
	adds r1, r0
	ldr r0, =0x00000dc8
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, 0x29
	bls _08195D88
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_0860DE84
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =0x00000dc6
	adds r4, r1
	b _08195DA6
	.pool
_08195D88:
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_0860DE78
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, =0x00000dc6
	adds r4, r3
_08195DA6:
	strh r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195D28

	thumb_func_start sub_8195DB8
sub_8195DB8: @ 8195DB8
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08195E00
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000dc6
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	b _08195E06
	.pool
_08195E00:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_08195E06:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195DB8

	thumb_func_start sub_8195E10
sub_8195E10: @ 8195E10
	push {lr}
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	bl sub_8195E34
	ldr r1, =gUnknown_0203CD80
	adds r0, 0xA
	str r0, [r1]
	movs r0, 0
	strb r0, [r1, 0x6]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8195E10

	thumb_func_start sub_8195E34
sub_8195E34: @ 8195E34
	adds r3, r0, 0
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	movs r2, 0x2
	ldrsb r2, [r3, r2]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	ldrsb r1, [r3, r1]
	adds r0, r1
	bx lr
	thumb_func_end sub_8195E34

	thumb_func_start sub_8195E58
sub_8195E58: @ 8195E58
	push {lr}
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	bl sub_8195E34
	adds r1, r0, 0
	ldr r2, =gUnknown_0203CD80
	ldr r0, [r2]
	cmp r0, r1
	bhi _08195E74
	subs r0, r1, r0
	cmp r0, 0x9
	bls _08195E84
_08195E74:
	str r1, [r2]
	movs r0, 0x1
	b _08195E86
	.pool
_08195E84:
	movs r0, 0
_08195E86:
	pop {r1}
	bx r1
	thumb_func_end sub_8195E58

	thumb_func_start sub_8195E8C
sub_8195E8C: @ 8195E8C
	push {r4,r5,lr}
	movs r5, 0x1
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _08195EAE
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1F
	bne _08195EAE
	movs r5, 0x2
_08195EAE:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r5, 1
	adds r1, r5
	cmp r0, r1
	blt _08195ED0
	movs r0, 0
	b _08195ED2
	.pool
_08195ED0:
	movs r0, 0x1
_08195ED2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8195E8C

	thumb_func_start sub_8195ED8
sub_8195ED8: @ 8195ED8
	push {r4,lr}
	ldr r4, =gMapHeader
	ldrb r0, [r4, 0x17]
	bl Overworld_MapTypeAllowsTeleportAndFly
	lsls r0, 24
	cmp r0, 0
	beq _08195F30
	ldrb r0, [r4, 0x14]
	cmp r0, 0x39
	beq _08195F30
	cmp r0, 0xE
	bne _08195F0E
	movs r0, 0xF9
	lsls r0, 2
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08195F0E
	movs r0, 0xDC
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08195F30
_08195F0E:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	cmp r0, 0x38
	bne _08195F38
	movs r0, 0xCF
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08195F38
	movs r0, 0x8B
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08195F38
_08195F30:
	movs r0, 0
	b _08195F3A
	.pool
_08195F38:
	movs r0, 0x1
_08195F3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8195ED8

	thumb_func_start sub_8195F40
sub_8195F40: @ 8195F40
	push {lr}
	ldr r1, =gUnknown_0203CD80
	ldrb r0, [r1, 0x6]
	adds r0, 0x1
	strb r0, [r1, 0x6]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08195F5C
	movs r0, 0
	b _08195F62
	.pool
_08195F5C:
	movs r0, 0
	strb r0, [r1, 0x6]
	movs r0, 0x1
_08195F62:
	pop {r1}
	bx r1
	thumb_func_end sub_8195F40

	thumb_func_start sub_8195F68
sub_8195F68: @ 8195F68
	push {r4,lr}
	bl sub_8195FCC
	adds r4, r0, 0
	cmp r4, 0
	beq _08195FB8
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __umodsi3
	bl sub_8195FF8
	ldr r2, =gUnknown_0203CD80
	movs r1, 0
	strh r0, [r2, 0x4]
	strb r1, [r2, 0x7]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4E
	beq _08195FB8
	ldrh r0, [r2, 0x4]
	bl sub_8196844
	adds r4, r0, 0
	bl sub_819672C
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _08195FC4
	adds r0, r4, 0
	bl sub_8196710
	cmp r0, 0
	bne _08195FC4
_08195FB8:
	movs r0, 0
	b _08195FC6
	.pool
_08195FC4:
	movs r0, 0x1
_08195FC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8195F68

	thumb_func_start sub_8195FCC
sub_8195FCC: @ 8195FCC
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_08195FD2:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08195FE8
	adds r5, 0x1
_08195FE8:
	adds r4, 0x1
	cmp r4, 0x3F
	bls _08195FD2
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8195FCC

	thumb_func_start sub_8195FF8
sub_8195FF8: @ 8195FF8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gRematchTable
_08196000:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08196022
	cmp r5, 0
	bne _08196020
	ldrh r0, [r6]
	b _0819602C
	.pool
_08196020:
	subs r5, 0x1
_08196022:
	adds r6, 0x10
	adds r4, 0x1
	cmp r4, 0x3F
	bls _08196000
	movs r0, 0x4E
_0819602C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8195FF8

	thumb_func_start sub_8196034
sub_8196034: @ 8196034
	push {lr}
	ldr r0, =0x0000012f
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08196078
	bl sub_8195F40
	cmp r0, 0
	beq _08196078
	bl sub_8195E58
	cmp r0, 0
	beq _08196078
	bl sub_8195E8C
	cmp r0, 0
	beq _08196078
	bl sub_8195ED8
	cmp r0, 0
	beq _08196078
	bl sub_8195F68
	cmp r0, 0
	beq _08196078
	bl task_prev_quest
	movs r0, 0x1
	b _0819607A
	.pool
_08196078:
	movs r0, 0
_0819607A:
	pop {r1}
	bx r1
	thumb_func_end sub_8196034

	thumb_func_start sub_8196080
sub_8196080: @ 8196080
	push {lr}
	ldr r1, =gUnknown_0203CD80
	movs r0, 0x1
	strb r0, [r1, 0x7]
	bl task_prev_quest
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196080

	thumb_func_start sub_8196094
sub_8196094: @ 8196094
	push {lr}
	ldr r0, =sub_81960E0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196094

	thumb_func_start task_prev_quest
task_prev_quest: @ 81960A8
	push {lr}
	ldr r0, =gUnknown_0203CD80
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _081960C2
	bl ScriptContext2_Enable
	bl FreezeEventObjects
	bl sub_808B864
	bl sub_808BCF4
_081960C2:
	ldr r0, =0x00000107
	bl PlaySE
	ldr r0, =sub_81960E0
	movs r1, 0x1
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_prev_quest

	thumb_func_start sub_81960E0
sub_81960E0: @ 81960E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r1, =gUnknown_0860EF78
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	cmp r0, 0
	beq _0819611E
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r1, 0
	strh r1, [r4, 0x2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7
	bls _0819611E
	adds r0, r5, 0
	bl DestroyTask
_0819611E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81960E0

	thumb_func_start sub_819612C
sub_819612C: @ 819612C
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gUnknown_0860EF98
	bl AddWindow
	strh r0, [r5, 0x4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	bne _0819615C
	adds r0, r4, 0
	b _081961E0
	.pool
_0819615C:
	ldr r1, =gUnknown_0860EA6C
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0x9C
	lsls r3, 2
	movs r0, 0
	bl LoadBgTiles
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _08196188
	ldrb r0, [r5, 0x4]
	bl RemoveWindow
	adds r0, r4, 0
	b _081961E0
	.pool
_08196188:
	ldr r1, =gUnknown_0860EB8C
	ldr r3, =0x00000279
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	bl decompress_and_copy_tile_data_to_vram
	cmp r0, 0
	beq _081961D8
	ldrb r0, [r5, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0860EA4C
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0860EB6C
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0xffffe000
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	b _081961E6
	.pool
_081961D8:
	ldrb r0, [r5, 0x4]
	bl RemoveWindow
	adds r0, r6, 0
_081961E0:
	bl DestroyTask
	movs r0, 0
_081961E6:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_819612C

	thumb_func_start sub_81961F0
sub_81961F0: @ 81961F0
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _08196268
	ldrb r0, [r4, 0x4]
	bl PutWindowTilemap
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r1, 0x9C
	lsls r1, 2
	movs r2, 0xE
	bl sub_819645C
	ldr r1, =0x0000f279
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0xF
	bl WriteSequenceToBgTilemapBuffer
	ldr r0, =sub_8196694
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	ldrb r0, [r4, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	b _0819626A
	.pool
_08196268:
	movs r0, 0
_0819626A:
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81961F0

	thumb_func_start sub_8196274
sub_8196274: @ 8196274
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _08196298
	movs r0, 0
	b _081962A4
	.pool
_08196298:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, =gText_PokenavCallEllipsis
	bl sub_81965D8
	movs r0, 0x1
_081962A4:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196274

	thumb_func_start sub_81962B0
sub_81962B0: @ 81962B0
	push {lr}
	movs r1, 0xC0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	cmp r0, 0
	bge _081962C6
	movs r0, 0
	b _081962D2
_081962C6:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
_081962D2:
	pop {r1}
	bx r1
	thumb_func_end sub_81962B0

	thumb_func_start sub_81962D8
sub_81962D8: @ 81962D8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_8196648
	cmp r0, 0
	bne _08196328
	ldrb r0, [r4, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_0203CD80
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0819630C
	ldrh r0, [r1, 0x4]
	ldr r1, =gStringVar4
	bl sub_81967AC
_0819630C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, =gStringVar4
	bl sub_81965D8
	movs r0, 0x1
	b _0819632A
	.pool
_08196328:
	movs r0, 0
_0819632A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81962D8

	thumb_func_start sub_8196330
sub_8196330: @ 8196330
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_8196648
	cmp r0, 0
	bne _08196388
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08196388
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08196388
	ldrb r0, [r4, 0x4]
	movs r1, 0x88
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x84
	lsls r0, 1
	bl PlaySE
	movs r0, 0x1
	b _0819638A
	.pool
_08196388:
	movs r0, 0
_0819638A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196330

	thumb_func_start sub_8196390
sub_8196390: @ 8196390
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0xC0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	ldr r1, =0xffffe000
	cmp r0, r1
	ble _081963C0
	movs r0, 0
	b _081963E8
	.pool
_081963C0:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xE
	bl FillBgTilemapBufferRect_Palette0
	ldrb r0, [r4, 0xA]
	bl DestroyTask
	ldrb r0, [r4, 0x4]
	bl RemoveWindow
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
_081963E8:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196390

	thumb_func_start sub_81963F0
sub_81963F0: @ 81963F0
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08196454
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08196454
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_0203CD80
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _08196446
	bl sub_81973A4
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetEventObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	bl EventObjectClearHeldMovementIfFinished
	bl sub_80D338C
	bl UnfreezeEventObjects
	bl ScriptContext2_Disable
_08196446:
	movs r0, 0x1
	b _08196456
	.pool
_08196454:
	movs r0, 0
_08196456:
	pop {r1}
	bx r1
	thumb_func_end sub_81963F0

	thumb_func_start sub_819645C
sub_819645C: @ 819645C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl GetWindowAttribute
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl GetWindowAttribute
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetWindowAttribute
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x3
	bl GetWindowAttribute
	adds r6, r0, 0
	adds r0, r4, 0
	movs r1, 0x4
	bl GetWindowAttribute
	str r0, [sp, 0x10]
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r1, 0xA
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0
	lsls r7, 12
	movs r1, 0xF0
	lsls r1, 8
	adds r0, r1, 0
	ands r7, r0
	adds r1, r7, 0
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x8]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldr r4, [sp, 0xC]
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	movs r3, 0x1
	mov r8, r3
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x1
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x8]
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r0, r6, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	str r0, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x14]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x2
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [sp, 0x8]
	adds r0, r3, r6
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x1C]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x3
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0xC]
	lsls r6, r2, 24
	lsrs r6, 24
	mov r3, r8
	str r3, [sp]
	ldr r0, [sp, 0x10]
	lsls r4, r0, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	mov r0, r9
	mov r2, r10
	adds r3, r6, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x4
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	mov r2, r8
	str r2, [sp]
	str r4, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x1C]
	adds r3, r6, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x5
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [sp, 0xC]
	ldr r2, [sp, 0x10]
	adds r0, r3, r2
	lsls r0, 24
	lsrs r4, r0, 24
	mov r3, r8
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	mov r2, r10
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r1, r5, 0x6
	orrs r1, r7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r2, r8
	str r2, [sp, 0x4]
	mov r0, r9
	ldr r2, [sp, 0x14]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	adds r5, 0x7
	orrs r5, r7
	lsls r5, 16
	lsrs r5, 16
	mov r3, r8
	str r3, [sp]
	str r3, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	ldr r2, [sp, 0x1C]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect_Palette0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_819645C

	thumb_func_start sub_81965D8
sub_81965D8: @ 81965D8
	push {lr}
	sub sp, 0x10
	str r1, [sp]
	mov r1, sp
	movs r3, 0
	strb r0, [r1, 0x4]
	mov r0, sp
	movs r1, 0x1
	strb r1, [r0, 0x5]
	movs r2, 0x20
	strb r2, [r0, 0x6]
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x11
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r3, 0xF
	movs r0, 0xA0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	movs r0, 0x8
	orrs r1, r0
	strb r1, [r2, 0xD]
	ands r1, r3
	movs r0, 0xE0
	orrs r1, r0
	strb r1, [r2, 0xD]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl GetPlayerTextSpeed
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81965D8

	thumb_func_start sub_8196648
sub_8196648: @ 8196648
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0819666C
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08196678
	.pool
_0819666C:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08196678:
	bl RunTextPrinters
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196648

	thumb_func_start sub_8196694
sub_8196694: @ 8196694
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081966FC
	movs r1, 0
	strh r1, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	strh r0, [r2, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _081966C8
	strh r1, [r2, 0x2]
_081966C8:
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	lsls r1, 4
	ldr r0, =0x00000279
	adds r1, r0
	strh r1, [r2, 0x4]
	ldr r2, =0xfffff000
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0xF
	bl WriteSequenceToBgTilemapBuffer
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_081966FC:
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196694

	thumb_func_start sub_8196710
sub_8196710: @ 8196710
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	adds r1, r0
	ldrb r1, [r1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_8196710

	thumb_func_start sub_819672C
sub_819672C: @ 819672C
	push {lr}
	ldr r1, =gRematchTable
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r0, r2, 0
	bl Overworld_GetMapHeaderByGroupAndId
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_819672C

	thumb_func_start sub_8196748
sub_8196748: @ 8196748
	push {r4-r6,lr}
	movs r5, 0
	movs r6, 0
	ldr r4, =gRematchTable
_08196750:
	ldrh r0, [r4]
	bl HasTrainerBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _0819675E
	adds r6, 0x1
_0819675E:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x3F
	bls _08196750
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196748

	thumb_func_start sub_8196774
sub_8196774: @ 8196774
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0
	ldr r5, =gRematchTable
_0819677E:
	ldrh r0, [r5]
	bl HasTrainerBeenFought
	lsls r0, 24
	cmp r0, 0
	beq _0819679A
	cmp r6, r7
	bne _08196798
	adds r0, r4, 0
	b _081967A4
	.pool
_08196798:
	adds r6, 0x1
_0819679A:
	adds r5, 0x10
	adds r4, 0x1
	cmp r4, 0x4D
	bls _0819677E
	movs r0, 0x4E
_081967A4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8196774

	thumb_func_start sub_81967AC
sub_81967AC: @ 81967AC
	push {r4-r7,lr}
	adds r6, r1, 0
	movs r7, 0
	bl sub_8196844
	adds r5, r0, 0
	ldr r0, =gUnknown_0203CD88
	strh r7, [r0]
	adds r0, r5, 0
	bl sub_8196710
	cmp r0, 0
	beq _081967EC
	adds r0, r5, 0
	bl sub_819672C
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081967EC
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196864
	b _08196830
	.pool
_081967EC:
	adds r0, r5, 0
	bl sub_8196D74
	cmp r0, 0
	beq _0819680A
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196890
	adds r4, r0, 0
	movs r7, 0x1
	adds r0, r5, 0
	bl UpdateRematchIfDefeated
	b _08196832
_0819680A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08196828
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_81968BC
	b _08196830
_08196828:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8196910
_08196830:
	adds r4, r0, 0
_08196832:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81969E0
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81967AC

	thumb_func_start sub_8196844
sub_8196844: @ 8196844
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_0860DEB8
_0819684C:
	ldrh r0, [r1]
	cmp r0, r3
	beq _0819685C
	adds r1, 0x14
	adds r2, 0x1
	b _0819684C
	.pool
_0819685C:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8196844

	thumb_func_start sub_8196864
sub_8196864: @ 8196864
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0xE]
	movs r2, 0xFF
	lsrs r0, r1, 8
	subs r0, 0x1
	ands r1, r2
	subs r1, 0x1
	ldr r2, =gUnknown_0860EA2C
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_8196864

	thumb_func_start sub_8196890
sub_8196890: @ 8196890
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0x10]
	movs r2, 0xFF
	lsrs r0, r1, 8
	subs r0, 0x1
	ands r1, r2
	subs r1, 0x1
	ldr r2, =gUnknown_0860EA2C
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_8196890

	thumb_func_start sub_81968BC
sub_81968BC: @ 81968BC
	push {r4,lr}
	adds r4, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	ldr r2, =gUnknown_0860DEB8
	lsrs r0, 15
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	adds r0, r1
	adds r2, 0x4
	adds r0, r2
	ldrh r4, [r0]
	cmp r4, 0
	bne _081968EC
	movs r0, 0
	bl SpriteCallbackDummy
_081968EC:
	movs r1, 0xFF
	lsrs r0, r4, 8
	subs r0, 0x1
	ands r4, r1
	subs r1, r4, 0x1
	ldr r2, =gUnknown_0860EA20
	lsls r0, 2
	adds r0, r2
	lsls r1, 3
	ldr r0, [r0]
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81968BC

	thumb_func_start sub_8196910
sub_8196910: @ 8196910
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081969AC
	movs r5, 0
	movs r4, 0
	lsls r7, r6, 2
_0819692C:
	lsls r0, r4, 16
	lsrs r0, 16
	mov r1, sp
	bl sub_8196E04
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08196940
	adds r5, 0x1
_08196940:
	adds r4, 0x1
	cmp r4, 0x6
	ble _0819692C
	cmp r5, 0
	beq _081969AC
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r5, r0, 0
	movs r4, 0
	b _08196962
_0819695E:
	subs r5, 0x1
_08196960:
	adds r4, 0x1
_08196962:
	cmp r4, 0x6
	bgt _08196980
	lsls r0, r4, 16
	lsrs r0, 16
	mov r1, sp
	bl sub_8196E04
	ldr r1, =gUnknown_0203CD88
	strh r0, [r1, 0x2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08196960
	cmp r5, 0
	bne _0819695E
_08196980:
	ldr r0, =gUnknown_0203CD88
	strh r4, [r0]
	ldr r1, =gUnknown_0860DEB8
	adds r0, r7, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xC]
	subs r2, r0, 0x1
	ldr r1, =gUnknown_0860EA34
	ldr r0, [sp]
	lsls r0, 2
	adds r0, r1
	lsls r1, r2, 3
	ldr r0, [r0]
	adds r0, r1
	b _081969D0
	.pool
_081969AC:
	ldr r1, =gUnknown_0860DEB8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrh r2, [r0, 0xA]
	lsrs r1, r2, 8
	subs r1, 0x1
	str r1, [sp]
	movs r0, 0xFF
	ands r0, r2
	subs r2, r0, 0x1
	ldr r0, =gUnknown_0860EA34
	lsls r1, 2
	adds r1, r0
	lsls r2, 3
	ldr r0, [r1]
	adds r0, r2
_081969D0:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196910

	thumb_func_start sub_81969E0
sub_81969E0: @ 81969E0
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r1, r4, 0x4
	bl sub_81969FC
	ldr r1, [r4]
	adds r0, r5, 0
	bl StringExpandPlaceholders
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81969E0

	thumb_func_start sub_81969FC
sub_81969FC: @ 81969FC
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	movs r4, 0
	ldr r5, =gUnknown_0860EFA0
_08196A06:
	adds r1, r6, r4
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0
	blt _08196A1A
	adds r1, r0, 0
	ldr r2, [r5]
	adds r0, r7, 0
	bl sub_8196A2C
_08196A1A:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0x2
	ble _08196A06
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81969FC

	thumb_func_start sub_8196A2C
sub_8196A2C: @ 8196A2C
	push {lr}
	ldr r3, =gUnknown_0860EFAC
	lsls r1, 2
	adds r1, r3
	ldr r3, [r1]
	adds r1, r2, 0
	bl _call_via_r3
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196A2C

	thumb_func_start sub_8196A44
sub_8196A44: @ 8196A44
	push {r4-r6,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r4, [r1]
	movs r2, 0
	ldr r3, =gUnknown_0860EFC4
	adds r6, r3, 0
_08196A5A:
	lsls r1, r2, 3
	ldrh r0, [r3]
	cmp r0, r4
	bne _08196A78
	adds r0, r6, 0x4
	adds r0, r1, r0
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy
	b _08196A90
	.pool
_08196A78:
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x5
	bls _08196A5A
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	ldr r0, =gTrainers + 0x4 @ name offset
	adds r1, r0
	adds r0, r5, 0
	bl StringCopy
_08196A90:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196A44

	thumb_func_start sub_8196A9C
sub_8196A9C: @ 8196A9C
	push {r4,lr}
	adds r4, r1, 0
	bl sub_819672C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl GetMapName
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8196A9C

	thumb_func_start sub_8196AB8
sub_8196AB8: @ 8196AB8
	push {lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x13
	bgt _08196AD4
	movs r0, 0
	b _08196B4A
_08196AD4:
	adds r0, r1, 0
	subs r0, 0x14
	cmp r0, 0x13
	bhi _08196AE0
	movs r0, 0x1
	b _08196B4A
_08196AE0:
	adds r0, r1, 0
	subs r0, 0x28
	cmp r0, 0x9
	bhi _08196AEC
	movs r0, 0x2
	b _08196B4A
_08196AEC:
	adds r0, r1, 0
	subs r0, 0x32
	cmp r0, 0x9
	bhi _08196AF8
	movs r0, 0x3
	b _08196B4A
_08196AF8:
	adds r0, r1, 0
	subs r0, 0x3C
	cmp r0, 0x9
	bhi _08196B04
	movs r0, 0x4
	b _08196B4A
_08196B04:
	adds r0, r1, 0
	subs r0, 0x46
	cmp r0, 0x9
	bhi _08196B10
	movs r0, 0x5
	b _08196B4A
_08196B10:
	adds r0, r1, 0
	subs r0, 0x50
	cmp r0, 0x4
	bhi _08196B1C
	movs r0, 0x6
	b _08196B4A
_08196B1C:
	adds r0, r1, 0
	subs r0, 0x55
	cmp r0, 0x4
	bhi _08196B28
	movs r0, 0x7
	b _08196B4A
_08196B28:
	adds r0, r1, 0
	subs r0, 0x5A
	cmp r0, 0x3
	bhi _08196B34
	movs r0, 0x8
	b _08196B4A
_08196B34:
	adds r0, r1, 0
	subs r0, 0x5E
	cmp r0, 0x3
	bhi _08196B40
	movs r0, 0x9
	b _08196B4A
_08196B40:
	cmp r1, 0x62
	beq _08196B48
	movs r0, 0xB
	b _08196B4A
_08196B48:
	movs r0, 0xA
_08196B4A:
	pop {r1}
	bx r1
	thumb_func_end sub_8196AB8

	thumb_func_start sub_8196B50
sub_8196B50: @ 8196B50
	push {lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3B
	bgt _08196B6C
	movs r0, 0
	b _08196B92
_08196B6C:
	adds r0, r1, 0
	subs r0, 0x3C
	cmp r0, 0x1D
	bhi _08196B78
	movs r0, 0x1
	b _08196B92
_08196B78:
	adds r0, r1, 0
	subs r0, 0x5A
	cmp r0, 0x4
	bhi _08196B84
	movs r0, 0x2
	b _08196B92
_08196B84:
	adds r0, r1, 0
	subs r0, 0x5F
	cmp r0, 0x3
	bls _08196B90
	movs r0, 0x4
	b _08196B92
_08196B90:
	movs r0, 0x3
_08196B92:
	pop {r1}
	bx r1
	thumb_func_end sub_8196B50

	thumb_func_start sub_8196B98
sub_8196B98: @ 8196B98
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r2, r0, 0
	mov r8, r1
	movs r3, 0
	ldr r0, =gWildMonHeaders
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0xFF
	beq _08196C5C
	ldr r1, =gRematchTable
	lsls r0, r2, 4
	adds r2, r0, r1
	ldrh r4, [r2, 0xA]
	adds r1, r7, 0
_08196BBA:
	ldrb r0, [r1]
	cmp r0, r4
	bne _08196BC8
	ldrb r0, [r1, 0x1]
	ldrh r5, [r2, 0xC]
	cmp r0, r5
	beq _08196BD2
_08196BC8:
	adds r1, 0x14
	adds r3, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08196BBA
_08196BD2:
	adds r1, r7, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r5, r0, 2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08196C5C
	movs r6, 0
	adds r0, r1, 0x4
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, 0
	beq _08196C02
	bl sub_8196AB8
	lsls r0, 24
	mov r2, sp
	ldr r1, [r4, 0x4]
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	movs r6, 0x1
_08196C02:
	adds r0, r7, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, 0
	beq _08196C26
	bl sub_8196B50
	lsls r0, 24
	lsls r1, r6, 1
	mov r3, sp
	adds r2, r3, r1
	ldr r1, [r4, 0x4]
	lsrs r0, 22
	adds r0, r1
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	adds r6, 0x1
_08196C26:
	cmp r6, 0
	beq _08196C5C
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 1
	add r0, sp
	ldrh r1, [r0]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	mov r0, r8
	bl StringCopy
	b _08196C62
	.pool
_08196C5C:
	movs r0, 0xFF
	mov r5, r8
	strb r0, [r5]
_08196C62:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8196B98

	thumb_func_start sub_8196C70
sub_8196C70: @ 8196C70
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r2, =gUnknown_0860DEB8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1]
	bl GetLastBeatenRematchTrainerId
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gTrainers
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r0, r5, 0
	adds r0, 0x24
	adds r0, r4, r0
	ldr r6, [r0]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r4, r5
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r1, [r1]
	bl __modsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _08196CD4
	cmp r1, 0x1
	ble _08196CC2
	cmp r1, 0x2
	beq _08196CD0
	cmp r1, 0x3
	beq _08196CD4
_08196CC2:
	lsls r0, 3
	b _08196CD6
	.pool
_08196CD0:
	lsls r0, 3
	b _08196CD6
_08196CD4:
	lsls r0, 4
_08196CD6:
	adds r0, r6
	ldrh r1, [r0, 0x4]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r7, 0
	bl StringCopy
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196C70

	thumb_func_start sub_8196CF4
sub_8196CF4: @ 8196CF4
	push {lr}
	adds r0, r1, 0
	ldr r2, =gUnknown_0860EFF4
	ldr r1, =gUnknown_0203CD88
	ldrh r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196CF4

	thumb_func_start sub_8196D14
sub_8196D14: @ 8196D14
	push {r4-r6,lr}
	adds r5, r1, 0
	movs r4, 0
	ldr r0, =gUnknown_0203CD88
	ldrh r1, [r0, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	beq _08196D34
_08196D24:
	adds r0, r1, 0
	movs r1, 0xA
	bl __divsi3
	adds r1, r0, 0
	adds r4, 0x1
	cmp r1, 0
	bne _08196D24
_08196D34:
	ldrh r1, [r6, 0x2]
	lsls r3, r4, 24
	lsrs r3, 24
	adds r0, r5, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8196D14

	thumb_func_start sub_8196D4C
sub_8196D4C: @ 8196D4C
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_0860F010
	b _08196D5C
	.pool
_08196D58:
	adds r5, 0x2
	adds r4, 0x1
_08196D5C:
	cmp r4, 0x7
	bhi _08196D6C
	ldrh r0, [r5]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08196D58
_08196D6C:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8196D4C

	thumb_func_start sub_8196D74
sub_8196D74: @ 8196D74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	bl sub_8196D4C
	cmp r0, 0x4
	ble _08196DF4
	bl RtcGetLocalDayCount
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xA
	bl ReadUnalignedWord
	adds r6, r0, 0
	ldr r0, =0x0000ffff
	ands r6, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e6a
	adds r0, r1
	ldrh r5, [r0]
	bl sub_8196748
	mov r9, r0
	movs r0, 0xD
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xA
	bl __divsi3
	mov r8, r0
	movs r0, 0x9
	bl GetGameStat
	eors r4, r5
	eors r5, r0
	adds r4, r5
	eors r4, r6
	adds r0, r4, 0
	mov r1, r8
	bl __modsi3
	cmp r0, r9
	bge _08196DF4
	bl sub_8196774
	cmp r0, r7
	bne _08196DF4
	movs r0, 0x1
	b _08196DF6
	.pool
_08196DF4:
	movs r0, 0
_08196DF6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8196D74

	thumb_func_start sub_8196E04
sub_8196E04: @ 8196E04
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 16
	lsrs r0, 16
	movs r4, 0
	cmp r0, 0x6
	bls _08196E14
	b _08196F7E
_08196E14:
	lsls r0, 2
	ldr r1, =_08196E24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08196E24:
	.4byte _08196E9C
	.4byte _08196E40
	.4byte _08196ED0
	.4byte _08196F38
	.4byte _08196E74
	.4byte _08196F04
	.4byte _08196F60
_08196E40:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000d14
	adds r0, r1
_08196E4A:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196E52:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196E5A
	ldrh r4, [r1]
_08196E5A:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196E52
	cmp r3, 0x1
	ble _08196E4A
	movs r0, 0x3
	b _08196F7C
	.pool
_08196E74:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e08
	adds r0, r1
	movs r3, 0x1
_08196E7E:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196E86
	ldrh r4, [r0]
_08196E86:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196E7E
	movs r0, 0x4
	b _08196F7C
	.pool
_08196E9C:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xCF
	lsls r1, 4
	adds r0, r1
_08196EA8:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196EB0:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196EB8
	ldrh r4, [r1]
_08196EB8:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196EB0
	movs r2, 0x2
	cmp r3, 0x3
	ble _08196EA8
	str r2, [r5]
	b _08196F7E
	.pool
_08196ED0:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xDD
	lsls r1, 4
	adds r0, r1
_08196EDC:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196EE4:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196EEC
	ldrh r4, [r1]
_08196EEC:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196EE4
	movs r2, 0x2
	cmp r3, 0x1
	ble _08196EDC
	str r2, [r5]
	b _08196F7E
	.pool
_08196F04:
	movs r3, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dea
	adds r0, r1
_08196F0E:
	lsls r1, r3, 2
	adds r3, 0x1
	adds r1, r0
	movs r2, 0x1
_08196F16:
	ldrh r6, [r1]
	cmp r4, r6
	bcs _08196F1E
	ldrh r4, [r1]
_08196F1E:
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08196F16
	movs r2, 0x2
	cmp r3, 0x1
	ble _08196F0E
	str r2, [r5]
	b _08196F7E
	.pool
_08196F38:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000dde
	adds r0, r1
	movs r3, 0x1
_08196F42:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196F4A
	ldrh r4, [r0]
_08196F4A:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196F42
	movs r3, 0x2
	str r3, [r5]
	b _08196F7E
	.pool
_08196F60:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e1e
	adds r0, r1
	movs r3, 0x1
_08196F6A:
	ldrh r6, [r0]
	cmp r4, r6
	bcs _08196F72
	ldrh r4, [r0]
_08196F72:
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08196F6A
	movs r0, 0x5
_08196F7C:
	str r0, [r5]
_08196F7E:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8196E04

	thumb_func_start sub_8196F90
sub_8196F90: @ 8196F90
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bhi _08196F9E
	movs r0, 0
	b _0819707A
_08196F9E:
	cmp r4, 0x13
	bhi _08196FA6
	movs r0, 0x1
	b _0819707A
_08196FA6:
	cmp r4, 0x1D
	bhi _08196FAE
	movs r0, 0x2
	b _0819707A
_08196FAE:
	cmp r4, 0x27
	bhi _08196FB6
	movs r0, 0x3
	b _0819707A
_08196FB6:
	cmp r4, 0x31
	bhi _08196FBE
	movs r0, 0x4
	b _0819707A
_08196FBE:
	cmp r4, 0x3B
	bhi _08196FC6
	movs r0, 0x5
	b _0819707A
_08196FC6:
	cmp r4, 0x45
	bhi _08196FCE
	movs r0, 0x6
	b _0819707A
_08196FCE:
	cmp r4, 0x4F
	bhi _08196FD6
	movs r0, 0x7
	b _0819707A
_08196FD6:
	cmp r4, 0x59
	bhi _08196FDE
	movs r0, 0x8
	b _0819707A
_08196FDE:
	cmp r4, 0x63
	bhi _08196FE6
	movs r0, 0x9
	b _0819707A
_08196FE6:
	cmp r4, 0x6D
	bhi _08196FEE
	movs r0, 0xA
	b _0819707A
_08196FEE:
	cmp r4, 0x77
	bhi _08196FF6
	movs r0, 0xB
	b _0819707A
_08196FF6:
	cmp r4, 0x81
	bhi _08196FFE
	movs r0, 0xC
	b _0819707A
_08196FFE:
	cmp r4, 0x8B
	bhi _08197006
	movs r0, 0xD
	b _0819707A
_08197006:
	cmp r4, 0x95
	bhi _0819700E
	movs r0, 0xE
	b _0819707A
_0819700E:
	cmp r4, 0x9F
	bhi _08197016
	movs r0, 0xF
	b _0819707A
_08197016:
	cmp r4, 0xA9
	bhi _0819701E
	movs r0, 0x10
	b _0819707A
_0819701E:
	cmp r4, 0xB3
	bhi _08197026
	movs r0, 0x11
	b _0819707A
_08197026:
	cmp r4, 0xBD
	bhi _0819702E
	movs r0, 0x12
	b _0819707A
_0819702E:
	cmp r4, 0xC7
	bls _08197078
	movs r0, 0xCD
	lsls r0, 1
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _08197050
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08197050:
	ldr r0, =0x00000199
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _0819706C
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0819706C:
	cmp r4, 0xC7
	bls _08197078
	movs r0, 0x14
	b _0819707A
	.pool
_08197078:
	movs r0, 0x13
_0819707A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8196F90

	thumb_func_start sub_8197080
sub_8197080: @ 8197080
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	movs r0, 0xFA
	lsls r0, 2
	bl Alloc
	adds r7, r0, 0
	cmp r7, 0
	bne _081970A2
	movs r0, 0xFF
	mov r1, r8
	strb r0, [r1]
	b _0819715C
_081970A2:
	movs r0, 0
	bl GetHoennPokedexCount
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetHoennPokedexCount
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gStringVar1
	mov r10, r0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	mov r9, r1
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	bl sub_8196F90
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gUnknown_082A5C9C
	adds r0, r7, 0
	bl StringCopy
	adds r5, r0, 0
	movs r6, 0xFB
	strb r6, [r5]
	adds r5, 0x1
	ldr r1, =gUnknown_082A5D2C
	adds r0, r5, 0
	bl StringCopy
	adds r5, r0, 0
	strb r6, [r5]
	adds r5, 0x1
	ldr r0, =gUnknown_0860F020
	lsls r4, 2
	adds r4, r0
	ldr r1, [r4]
	adds r0, r5, 0
	bl StringCopy
	mov r0, r8
	adds r1, r7, 0
	bl StringExpandPlaceholders
	adds r5, r0, 0
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _08197156
	strb r6, [r5]
	adds r5, 0x1
	movs r0, 0
	bl GetNationalPokedexCount
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	bl GetNationalPokedexCount
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gUnknown_082A633D
	adds r0, r5, 0
	bl StringExpandPlaceholders
_08197156:
	adds r0, r7, 0
	bl Free
_0819715C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool

	thumb_func_end sub_8197080
	thumb_func_start sub_8197184
sub_8197184: @ 8197184
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0860EA6C
	movs r2, 0x80
	lsls r2, 1
	lsls r4, 16
	lsrs r4, 16
	adds r3, r4, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0860EA4C
	lsls r5, 20
	lsrs r5, 16
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197184

	thumb_func_start sub_81971C4
sub_81971C4: @ 81971C4
	push {lr}
	bl sub_819645C
	pop {r0}
	bx r0
	thumb_func_end sub_81971C4

	.align 2, 0 @ Don't pad with nop.
