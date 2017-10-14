	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81B9B28
sub_81B9B28: @ 81B9B28
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000e6a
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _081B9B70
	ldr r0, [r4]
	ldr r1, =0x00000e6a
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000e6a
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gScriptResult
	strh r5, [r0]
	b _081B9B76
	.pool
_081B9B70:
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
_081B9B76:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9B28

	thumb_func_start sub_81B9B80
sub_81B9B80: @ 81B9B80
	push {lr}
	ldr r1, =gUnknown_086160D8
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9B80

	thumb_func_start sub_81B9BA0
sub_81B9BA0: @ 81B9BA0
	push {lr}
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r1, [r1]
	ldr r3, =0x00000cb2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
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
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9BA0

	thumb_func_start sub_81B9BF4
sub_81B9BF4: @ 81B9BF4
	ldr r1, =gScriptResult
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000e6c
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81B9BF4

	thumb_func_start sub_81B9C10
sub_81B9C10: @ 81B9C10
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	ldr r2, =0x00000e6c
	adds r0, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81B9C10

	thumb_func_start sub_81B9C2C
sub_81B9C2C: @ 81B9C2C
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
	thumb_func_end sub_81B9C2C

	thumb_func_start sub_81B9C70
sub_81B9C70: @ 81B9C70
	push {r4,r5,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r5, =gUnknown_086160F4
	bl Random
	ldrh r0, [r5]
	ldr r1, =0x00000e6c
	adds r4, r1
	strh r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9C70

	thumb_func_start sub_81B9C98
sub_81B9C98: @ 81B9C98
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000e6c
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _081B9CE0
	ldr r0, [r4]
	ldr r1, =0x00000e6c
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000e6c
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gScriptResult
	strh r5, [r0]
	b _081B9CE6
	.pool
_081B9CE0:
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
_081B9CE6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9C98

	thumb_func_start sub_81B9CF0
sub_81B9CF0: @ 81B9CF0
	push {lr}
	ldr r0, =gStringVar1
	ldr r1, =gTrainerBattleOpponent_A
	ldrh r1, [r1]
	bl GetFrontierTrainerName
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9CF0

	thumb_func_start sub_81B9D08
sub_81B9D08: @ 81B9D08
	push {lr}
	ldr r1, =gUnknown_086160F8
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9D08

	thumb_func_start sub_81B9D28
sub_81B9D28: @ 81B9D28
	push {lr}
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r1, [r1]
	ldr r3, =0x00000cb2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
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
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9D28

	thumb_func_start sub_81B9D7C
sub_81B9D7C: @ 81B9D7C
	ldr r1, =gScriptResult
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000e6e
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81B9D7C

	thumb_func_start sub_81B9D98
sub_81B9D98: @ 81B9D98
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	ldr r2, =0x00000e6e
	adds r0, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81B9D98

	thumb_func_start sub_81B9DB4
sub_81B9DB4: @ 81B9DB4
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
	thumb_func_end sub_81B9DB4

	thumb_func_start sub_81B9DF8
sub_81B9DF8: @ 81B9DF8
	push {r4,r5,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r5, =gUnknown_08616120
	bl Random
	ldrh r0, [r5]
	ldr r1, =0x00000e6e
	adds r4, r1
	strh r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9DF8

	thumb_func_start sub_81B9E20
sub_81B9E20: @ 81B9E20
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000e6e
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _081B9E68
	ldr r0, [r4]
	ldr r1, =0x00000e6e
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000e6e
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gScriptResult
	strh r5, [r0]
	b _081B9E6E
	.pool
_081B9E68:
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
_081B9E6E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9E20

	thumb_func_start sub_81B9E78
sub_81B9E78: @ 81B9E78
	push {lr}
	bl ZeroPlayerPartyMons
	bl sub_819A4F8
	pop {r0}
	bx r0
	thumb_func_end sub_81B9E78

	thumb_func_start sub_81B9E88
sub_81B9E88: @ 81B9E88
	push {lr}
	bl sub_819DC00
	pop {r0}
	bx r0
	thumb_func_end sub_81B9E88

	thumb_func_start sub_81B9E94
sub_81B9E94: @ 81B9E94
	push {lr}
	movs r2, 0
	ldr r1, =gMapHeader
	ldrb r0, [r1, 0x14]
	cmp r0, 0x8
	bne _081B9EB2
	ldr r3, =0xfffffe7f
	adds r0, r3, 0
	ldrh r1, [r1, 0x12]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081B9EB2
	movs r2, 0x1
_081B9EB2:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B9E94

	thumb_func_start sub_81B9EC0
sub_81B9EC0: @ 81B9EC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gSlateportBattleTentTrainers
	str r0, [r1]
	add r0, sp, 0xC
	mov r9, r0
	mov r1, sp
	adds r1, 0x18
	str r1, [sp, 0x2C]
	ldr r5, =gUnknown_0203BC8C
	ldr r4, =gSlateportBattleTentMons
	movs r2, 0
	adds r3, r1, 0
	mov r1, r9
	mov r0, sp
	movs r6, 0x5
	mov r8, r6
_081B9EEC:
	strh r2, [r0]
	strh r2, [r1]
	strh r2, [r3]
	adds r3, 0x2
	adds r1, 0x2
	adds r0, 0x2
	movs r7, 0x1
	negs r7, r7
	add r8, r7
	mov r6, r8
	cmp r6, 0
	bge _081B9EEC
	str r4, [r5]
	movs r7, 0
	mov r10, r7
	movs r0, 0
	mov r8, r0
	ldr r1, [sp, 0x2C]
	str r1, [sp, 0x30]
	mov r2, sp
	str r2, [sp, 0x34]
	lsls r6, r0, 1
	str r6, [sp, 0x24]
	add r6, r9
	str r6, [sp, 0x28]
_081B9F1E:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x46
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	movs r2, 0
	mov r7, r8
	adds r6, r2, r7
	cmp r2, r6
	bge _081B9F7C
	ldr r1, [sp, 0x28]
	ldrh r0, [r1]
	cmp r0, r5
	beq _081B9F7C
	ldr r0, =gUnknown_0203BC8C
	ldr r1, [r0]
	lsls r0, r5, 4
	adds r4, r0, r1
	ldrh r7, [r4]
	mov r12, r7
	lsls r3, r2, 1
	ldr r1, [sp, 0x24]
	add r1, sp
	str r6, [sp, 0x38]
_081B9F56:
	ldrh r0, [r1]
	cmp r0, r12
	bne _081B9F66
	mov r0, r10
	cmp r0, 0
	bne _081B9F7C
	ldrh r7, [r4]
	mov r10, r7
_081B9F66:
	adds r3, 0x2
	adds r1, 0x2
	adds r2, 0x1
	ldr r0, [sp, 0x38]
	cmp r2, r0
	bge _081B9F7C
	mov r7, r9
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, r5
	bne _081B9F56
_081B9F7C:
	cmp r2, r6
	bne _081BA01C
	movs r2, 0
	cmp r2, r6
	bge _081B9FD4
	ldr r0, =gBattleFrontierHeldItems
	mov r12, r0
	ldr r7, =gUnknown_0203BC8C
	ldr r1, [sp, 0x24]
	ldr r0, [sp, 0x2C]
	adds r4, r1, r0
_081B9F92:
	ldrh r3, [r4]
	cmp r3, 0
	beq _081B9FCC
	ldr r1, [r7]
	lsls r0, r5, 4
	adds r1, r0, r1
	ldrb r0, [r1, 0xA]
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	cmp r3, r0
	bne _081B9FCC
	ldrh r0, [r1]
	cmp r0, r10
	bne _081B9FD4
	movs r1, 0
	mov r10, r1
	b _081B9FD4
	.pool
_081B9FCC:
	adds r4, 0x2
	adds r2, 0x1
	cmp r2, r6
	blt _081B9F92
_081B9FD4:
	cmp r2, r6
	bne _081BA01C
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	mov r2, r8
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r1, r0
	movs r6, 0xE7
	lsls r6, 4
	adds r1, r6
	strh r5, [r1]
	ldr r0, =gUnknown_0203BC8C
	ldr r0, [r0]
	lsls r1, r5, 4
	adds r1, r0
	ldrh r0, [r1]
	ldr r7, [sp, 0x34]
	strh r0, [r7]
	ldr r2, =gBattleFrontierHeldItems
	ldrb r0, [r1, 0xA]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, 0x30]
	strh r0, [r1]
	add r3, r9
	strh r5, [r3]
	adds r1, 0x2
	str r1, [sp, 0x30]
	adds r2, r7, 0
	adds r2, 0x2
	str r2, [sp, 0x34]
	movs r6, 0x1
	add r8, r6
_081BA01C:
	mov r7, r8
	cmp r7, 0x6
	beq _081BA024
	b _081B9F1E
_081BA024:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9EC0

	thumb_func_start sub_81BA040
sub_81BA040: @ 81BA040
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r0, 0
	mov r10, r0
	ldr r1, =gUnknown_0203BC88
	ldr r0, =gSlateportBattleTentTrainers
	str r0, [r1]
	ldr r1, =gUnknown_0203BC8C
	ldr r0, =gSlateportBattleTentMons
	str r0, [r1]
	ldr r7, =gSaveBlock2Ptr
	ldr r1, =0x0000ffff
	mov r8, r1
_081BA062:
	mov r2, r10
	lsls r6, r2, 1
_081BA066:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	lsrs r3, r0, 16
	movs r5, 0
	ldr r1, [r7]
	ldr r4, =0x00000cb2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r5, r0
	bge _081BA0AA
	ldr r2, =0x00000cb4
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, r3
	beq _081BA0AA
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r1, r4
	ldrh r2, [r0]
	adds r4, 0x2
	adds r1, r4
_081BA09C:
	adds r1, 0x2
	adds r5, 0x1
	cmp r5, r2
	bge _081BA0AA
	ldrh r0, [r1]
	cmp r0, r3
	bne _081BA09C
_081BA0AA:
	ldr r0, [r7]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	bne _081BA066
	ldr r2, =gTrainerBattleOpponent_A
	strh r3, [r2]
	ldrh r3, [r2]
	ldr r4, =gUnknown_0203BC88
	ldr r1, [r4]
	movs r0, 0x34
	muls r0, r3
	adds r0, r1
	ldr r0, [r0, 0x30]
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, r8
	beq _081BA0DE
	ldr r3, =0x0000ffff
_081BA0D2:
	adds r1, 0x2
	movs r6, 0x1
	add r10, r6
	ldrh r0, [r1]
	cmp r0, r3
	bne _081BA0D2
_081BA0DE:
	mov r0, r10
	cmp r0, 0x8
	bgt _081BA110
	movs r1, 0
	mov r10, r1
	b _081BA062
	.pool
_081BA110:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r6, =0x00000cb2
	adds r3, r1, r6
	ldrh r0, [r3]
	cmp r0, 0x1
	bhi _081BA12A
	lsls r0, 1
	ldr r3, =0x00000cb4
	adds r1, r3
	adds r1, r0
	ldrh r0, [r2]
	strh r0, [r1]
_081BA12A:
	ldrh r1, [r2]
	ldr r2, [r4]
	movs r0, 0x34
	muls r0, r1
	adds r0, r2
	ldr r0, [r0, 0x30]
	mov r9, r0
	movs r5, 0
	ldr r7, =gUnknown_03001298
	mov r8, sp
_081BA13E:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r10
	bl __modsi3
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r7]
	movs r2, 0
	ldrh r0, [r7]
	ldr r4, =gUnknown_0203BC8C
	ldr r3, [r4]
	lsls r0, 4
	adds r0, r3
	ldr r1, =gSaveBlock2Ptr
	ldrh r6, [r0]
	ldr r1, [r1]
_081BA166:
	movs r4, 0xE7
	lsls r4, 4
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 4
	adds r0, r3
	ldrh r0, [r0]
	cmp r6, r0
	beq _081BA180
	adds r1, 0xC
	adds r2, 0x1
	cmp r2, 0x5
	ble _081BA166
_081BA180:
	cmp r2, 0x6
	bne _081BA220
	movs r4, 0
	cmp r4, r5
	bge _081BA1B0
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, r6
	beq _081BA1B0
	ldr r6, =gUnknown_03001298
	ldr r3, =gUnknown_0203BC8C
	mov r2, sp
_081BA198:
	adds r2, 0x2
	adds r4, 0x1
	cmp r4, r5
	bge _081BA1B0
	ldrh r0, [r6]
	ldr r1, [r3]
	lsls r0, 4
	adds r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081BA198
_081BA1B0:
	cmp r4, r5
	bne _081BA220
	movs r4, 0
	cmp r4, r5
	bge _081BA1E6
	ldr r6, =gBattleFrontierHeldItems
	mov r12, r6
	add r3, sp, 0x8
_081BA1C0:
	ldrh r2, [r3]
	cmp r2, 0
	beq _081BA1DE
	ldr r1, =gUnknown_03001298
	ldrh r0, [r1]
	ldr r6, =gUnknown_0203BC8C
	ldr r1, [r6]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0xA]
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	cmp r2, r0
	beq _081BA1E6
_081BA1DE:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, r5
	blt _081BA1C0
_081BA1E6:
	cmp r4, r5
	bne _081BA220
	lsls r2, r5, 1
	ldrh r0, [r7]
	ldr r1, =gUnknown_0203BC8C
	ldr r4, [r1]
	lsls r0, 4
	adds r0, r4
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
	add r1, sp, 0x8
	adds r1, r2
	ldr r3, =gBattleFrontierHeldItems
	ldrh r0, [r7]
	lsls r0, 4
	adds r0, r4
	ldrb r0, [r0, 0xA]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, =gUnknown_03006298
	adds r2, r0
	ldrh r0, [r7]
	strh r0, [r2]
	movs r4, 0x2
	add r8, r4
	adds r5, 0x1
_081BA220:
	cmp r5, 0x3
	bne _081BA13E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BA040

	.align 2, 0 @ Don't pad with nop.
