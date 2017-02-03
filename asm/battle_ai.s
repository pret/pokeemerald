	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start tai30_unk
tai30_unk: @ 8132614
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r3, 0
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	str r3, [r0, 0x8]
	movs r5, 0
	ldr r4, =gUnknown_020241F0
	ldr r7, =gUnknown_020241EA
	ldr r0, =gUnknown_02024090
	mov r8, r0
	ldr r6, =gPlayerMonIndex
_0813264A:
	movs r0, 0x28
	str r0, [r4]
	lsls r1, r5, 1
	ldrb r2, [r6]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r7]
	lsls r0, 16
	cmp r0, 0
	beq _081326B8
	ldrh r0, [r7]
	ldrb r1, [r6]
	ldr r2, =gEnemyMonIndex
	ldrb r2, [r2]
	bl move_effectiveness_something
	ldr r0, [r4]
	cmp r0, 0x78
	bne _0813267A
	movs r0, 0x50
	str r0, [r4]
_0813267A:
	ldr r0, [r4]
	cmp r0, 0xF0
	bne _08132684
	movs r0, 0xA0
	str r0, [r4]
_08132684:
	ldr r0, [r4]
	cmp r0, 0x1E
	bne _0813268E
	movs r0, 0x14
	str r0, [r4]
_0813268E:
	ldr r0, [r4]
	cmp r0, 0xF
	bne _08132698
	movs r0, 0xA
	str r0, [r4]
_08132698:
	ldr r0, =gUnknown_0202427C
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081326A8
	movs r0, 0
	str r0, [r4]
_081326A8:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, [r2, 0x8]
	ldr r1, [r4]
	cmp r0, r1
	bcs _081326B8
	str r1, [r2, 0x8]
_081326B8:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0813264A
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai30_unk

	thumb_func_start dp15_simulate_damage_bonus_jump_if_eq
dp15_simulate_damage_bonus_jump_if_eq: @ 8132700
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r5, =gUnknown_0202427C
	strb r1, [r5]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r4, =gUnknown_020241F0
	movs r0, 0x28
	str r0, [r4]
	ldr r1, =gUnknown_020241EA
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r1, =gPlayerMonIndex
	ldrb r1, [r1]
	ldr r2, =gEnemyMonIndex
	ldrb r2, [r2]
	bl move_effectiveness_something
	ldr r0, [r4]
	cmp r0, 0x78
	bne _08132746
	movs r0, 0x50
	str r0, [r4]
_08132746:
	ldr r0, [r4]
	cmp r0, 0xF0
	bne _08132750
	movs r0, 0xA0
	str r0, [r4]
_08132750:
	ldr r0, [r4]
	cmp r0, 0x1E
	bne _0813275A
	movs r0, 0x14
	str r0, [r4]
_0813275A:
	ldr r0, [r4]
	cmp r0, 0xF
	bne _08132764
	movs r0, 0xA
	str r0, [r4]
_08132764:
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08132772
	movs r0, 0
	str r0, [r4]
_08132772:
	ldrb r0, [r4]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _081327C4
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081327C8
	.pool
_081327C4:
	adds r0, r2, 0x6
	str r0, [r3]
_081327C8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp15_simulate_damage_bonus_jump_if_eq

	thumb_func_start nullsub_104
nullsub_104: @ 81327D0
	bx lr
	thumb_func_end nullsub_104

	thumb_func_start nullsub_105
nullsub_105: @ 81327D4
	bx lr
	thumb_func_end nullsub_105

	thumb_func_start tai34_unk
tai34_unk: @ 81327D8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _08132818
	ldr r0, =gPlayerMonIndex
	b _0813281A
	.pool
_081327F8:
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x6]
	ldrb r0, [r2, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0813289A
	.pool
_08132818:
	ldr r0, =gEnemyMonIndex
_0813281A:
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r9, r1
	cmp r0, 0
	bne _0813282E
	ldr r0, =gPlayerParty
	mov r9, r0
_0813282E:
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r7, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	orrs r7, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	orrs r7, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	orrs r7, r0
	movs r1, 0
	mov r8, r1
	movs r0, 0xCE
	lsls r0, 1
	mov r10, r0
_08132850:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	add r4, r9
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	cmp r5, 0
	beq _08132888
	cmp r5, r10
	beq _08132888
	cmp r6, 0
	beq _08132888
	cmp r0, r7
	beq _081327F8
_08132888:
	movs r1, 0x1
	add r8, r1
	mov r0, r8
	cmp r0, 0x5
	ble _08132850
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_0813289A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai34_unk

	thumb_func_start tai35_unk
tai35_unk: @ 81328B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081328D8
	ldr r0, =gPlayerMonIndex
	b _081328DA
	.pool
_081328D8:
	ldr r0, =gEnemyMonIndex
_081328DA:
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r10, r1
	cmp r0, 0
	bne _081328EE
	ldr r0, =gPlayerParty
	mov r10, r0
_081328EE:
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r7, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	orrs r7, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	orrs r7, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	orrs r7, r0
	movs r1, 0
	mov r8, r1
	mov r9, r2
_0813290C:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	add r4, r10
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	cmp r5, 0
	beq _08132950
	movs r1, 0xCE
	lsls r1, 1
	cmp r5, r1
	beq _08132950
	cmp r6, 0
	beq _08132950
	cmp r0, r7
	bne _08132950
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_08132950:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x5
	ble _0813290C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x6]
	ldrb r0, [r2, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai35_unk

	thumb_func_start dp15_get_weather__8
dp15_get_weather__8: @ 8132994
	push {lr}
	ldr r2, =gUnknown_020243CC
	ldrh r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _081329AC
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x1
	str r0, [r1, 0x8]
_081329AC:
	ldrh r1, [r2]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _081329C0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x2
	str r0, [r1, 0x8]
_081329C0:
	ldrh r1, [r2]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _081329D4
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0
	str r0, [r1, 0x8]
_081329D4:
	ldrh r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081329E8
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x3
	str r0, [r1, 0x8]
_081329E8:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_weather__8

	thumb_func_start tai37_unk
tai37_unk: @ 8132A00
	push {lr}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r0, [r0]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _08132A44
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132A48
	.pool
_08132A44:
	adds r0, r2, 0x6
	str r0, [r3]
_08132A48:
	pop {r0}
	bx r0
	thumb_func_end tai37_unk

	thumb_func_start tai38_unk
tai38_unk: @ 8132A4C
	push {lr}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r0, [r0]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	beq _08132A90
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132A94
	.pool
_08132A90:
	adds r0, r2, 0x6
	str r0, [r3]
_08132A94:
	pop {r0}
	bx r0
	thumb_func_end tai38_unk

	thumb_func_start tai39_unk
tai39_unk: @ 8132A98
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132AB4
	ldr r0, =gPlayerMonIndex
	b _08132AB6
	.pool
_08132AB4:
	ldr r0, =gEnemyMonIndex
_08132AB6:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	bge _08132AF4
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132AFA
	.pool
_08132AF4:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132AFA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai39_unk

	thumb_func_start tai3A_unk
tai3A_unk: @ 8132B00
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132B1C
	ldr r0, =gPlayerMonIndex
	b _08132B1E
	.pool
_08132B1C:
	ldr r0, =gEnemyMonIndex
_08132B1E:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	ble _08132B5C
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132B62
	.pool
_08132B5C:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132B62:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3A_unk

	thumb_func_start tai3B_unk
tai3B_unk: @ 8132B68
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132B84
	ldr r0, =gPlayerMonIndex
	b _08132B86
	.pool
_08132B84:
	ldr r0, =gEnemyMonIndex
_08132B86:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	bne _08132BC4
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132BCA
	.pool
_08132BC4:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132BCA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3B_unk

	thumb_func_start tai3C_unk
tai3C_unk: @ 8132BD0
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132BEC
	ldr r0, =gPlayerMonIndex
	b _08132BEE
	.pool
_08132BEC:
	ldr r0, =gEnemyMonIndex
_08132BEE:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	beq _08132C2C
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132C32
	.pool
_08132C2C:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132C32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3C_unk

	thumb_func_start tai3D_unk
tai3D_unk: @ 8132C38
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bls _08132D1C
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r7, 0x1
	strb r7, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r7, [r0]
	ldr r5, =gUnknown_020241EA
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r5]
	ldr r4, =gPlayerMonIndex
	ldrb r0, [r4]
	ldr r6, =gEnemyMonIndex
	ldrb r1, [r6]
	bl sub_8046E7C
	ldrh r0, [r5]
	ldrb r1, [r4]
	ldrb r2, [r6]
	bl move_effectiveness_something
	ldr r4, =gUnknown_020241F0
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, 0x14]
	adds r0, r1, 0
	adds r0, 0x18
	ldrb r1, [r1, 0x1]
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r4]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08132CB8
	str r7, [r4]
_08132CB8:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x28]
	ldr r0, [r4]
	cmp r1, r0
	bgt _08132D1C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132D24
	.pool
_08132D1C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08132D24:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai3D_unk

	thumb_func_start dp15_determine_move_damage_jump_if_not_fatal
dp15_determine_move_damage_jump_if_not_fatal: @ 8132D34
	push {r4-r7,lr}
	ldr r2, =gBattleMoves
	ldr r7, =gUnknown_020244A8
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bls _08132E04
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r6, =gUnknown_020241EA
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r6]
	ldr r4, =gPlayerMonIndex
	ldrb r0, [r4]
	ldr r5, =gEnemyMonIndex
	ldrb r1, [r5]
	bl sub_8046E7C
	ldrh r0, [r6]
	ldrb r1, [r4]
	ldrb r2, [r5]
	bl move_effectiveness_something
	ldr r4, =gUnknown_020241F0
	ldr r0, [r7]
	ldr r1, [r0, 0x14]
	adds r0, r1, 0
	adds r0, 0x18
	ldrb r1, [r1, 0x1]
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r4]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	ldr r3, =gBattleMons
	ldrb r2, [r5]
	movs r1, 0x58
	muls r1, r2
	adds r1, r3
	ldrh r1, [r1, 0x28]
	cmp r1, r0
	ble _08132E04
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132E0C
	.pool
_08132E04:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08132E0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_determine_move_damage_jump_if_not_fatal

	thumb_func_start tai3F_unk
tai3F_unk: @ 8132E18
	push {r4-r7,lr}
	ldr r0, =gAIScriptPtr
	ldr r5, [r0]
	adds r7, r5, 0x2
	ldrb r1, [r5, 0x1]
	adds r6, r0, 0
	cmp r1, 0x1
	beq _08132E42
	cmp r1, 0x1
	bgt _08132E38
	cmp r1, 0
	beq _08132EDC
	b _08132F40
	.pool
_08132E38:
	cmp r1, 0x2
	beq _08132EDC
	cmp r1, 0x3
	beq _08132E84
	b _08132F40
_08132E42:
	movs r4, 0
	ldr r3, =gBattleMons
	ldr r2, =gPlayerMonIndex
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	adds r3, 0xC
	adds r0, r3
	ldrh r0, [r0]
	ldrh r5, [r5, 0x2]
	cmp r0, r5
	beq _08132E74
	movs r5, 0x58
_08132E5C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132E74
	lsls r1, r4, 1
	ldrb r0, [r2]
	muls r0, r5
	adds r1, r0
	adds r1, r3
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	bne _08132E5C
_08132E74:
	cmp r4, 0x4
	beq _08132F18
	b _08132F28
	.pool
_08132E84:
	ldr r3, =gBattleMons
	ldr r2, =gPlayerMonIndex
	ldrb r1, [r2]
	movs r0, 0x2
	eors r0, r1
	movs r1, 0x58
	muls r1, r0
	adds r0, r1, r3
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08132EA8
	adds r0, r5, 0
	b _08132F1A
	.pool
_08132EA8:
	movs r4, 0
	adds r3, 0xC
	adds r0, r1, r3
	ldrh r0, [r0]
	ldrh r5, [r5, 0x2]
	cmp r0, r5
	beq _08132E74
	mov r12, r3
	adds r5, r2, 0
	movs r3, 0x2
_08132EBC:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132E74
	lsls r1, r4, 1
	ldrb r0, [r5]
	adds r2, r3, 0
	eors r2, r0
	movs r0, 0x58
	muls r0, r2
	adds r1, r0
	add r1, r12
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	bne _08132EBC
	b _08132E74
_08132EDC:
	movs r4, 0
	ldr r3, =gUnknown_020244A8
	ldr r0, [r3]
	ldr r1, [r0, 0x18]
	ldr r2, =gEnemyMonIndex
	ldrb r0, [r2]
	lsls r0, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	beq _08132F14
	adds r7, r3, 0
	adds r5, r2, 0
	adds r3, r1, 0
_08132EFA:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132F14
	ldr r0, [r7]
	ldr r2, [r0, 0x18]
	lsls r1, r4, 1
	ldrb r0, [r5]
	lsls r0, 4
	adds r1, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, r3
	bne _08132EFA
_08132F14:
	cmp r4, 0x4
	bne _08132F28
_08132F18:
	ldr r0, [r6]
_08132F1A:
	adds r0, 0x8
	str r0, [r6]
	b _08132F40
	.pool
_08132F28:
	ldr r2, [r6]
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r6]
_08132F40:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai3F_unk

	thumb_func_start tai40_unk
tai40_unk: @ 8132F48
	push {r4-r7,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r6, r0, 0x2
	ldrb r0, [r0, 0x1]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _08132F70
	cmp r0, 0x1
	bgt _08132F68
	cmp r0, 0
	beq _08132FB4
	b _08133018
	.pool
_08132F68:
	cmp r0, 0x2
	beq _08132FB4
	cmp r0, 0x3
	bne _08133018
_08132F70:
	movs r3, 0
	ldr r2, =gBattleMons
	ldr r4, =gPlayerMonIndex
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r2, 0xC
	adds r0, r2
	ldrh r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08132FA6
	adds r7, r4, 0
	movs r6, 0x58
	adds r4, r2, 0
	adds r2, r1, 0
_08132F90:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08132FA6
	lsls r1, r3, 1
	ldrb r0, [r7]
	muls r0, r6
	adds r1, r0
	adds r1, r4
	ldrh r0, [r1]
	cmp r0, r2
	bne _08132F90
_08132FA6:
	cmp r3, 0x4
	bne _08132FF0
	b _08133000
	.pool
_08132FB4:
	movs r3, 0
	ldr r4, =gUnknown_020244A8
	ldr r0, [r4]
	ldr r1, [r0, 0x18]
	ldr r2, =gEnemyMonIndex
	ldrb r0, [r2]
	lsls r0, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08132FEC
	adds r7, r4, 0
	adds r6, r2, 0
	adds r4, r1, 0
_08132FD2:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08132FEC
	ldr r0, [r7]
	ldr r2, [r0, 0x18]
	lsls r1, r3, 1
	ldrb r0, [r6]
	lsls r0, 4
	adds r1, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, r4
	bne _08132FD2
_08132FEC:
	cmp r3, 0x4
	beq _08133000
_08132FF0:
	ldr r0, [r5]
	adds r0, 0x8
	str r0, [r5]
	b _08133018
	.pool
_08133000:
	ldr r2, [r5]
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
_08133018:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai40_unk

	thumb_func_start tai41_unk
tai41_unk: @ 8133020
	push {r4-r7,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _08133044
	cmp r0, 0x1
	bgt _0813303C
	cmp r0, 0
	beq _08133090
	b _08133110
	.pool
_0813303C:
	cmp r0, 0x2
	beq _08133090
	cmp r0, 0x3
	bne _08133110
_08133044:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r2, [r0]
	ldr r6, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
	ldr r4, =gAIScriptPtr
_08133058:
	ldrh r0, [r2]
	cmp r0, 0
	beq _08133072
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r4]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _0813307A
_08133072:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08133058
_0813307A:
	cmp r3, 0x4
	beq _081330DC
	b _081330F8
	.pool
_08133090:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r2, [r0]
	ldr r0, =gBattleMoves
	mov r12, r0
	ldr r7, =gUnknown_020244A8
	ldr r6, =gEnemyMonIndex
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r4, r0, r1
_081330A8:
	lsls r2, r3, 1
	ldrh r0, [r4]
	cmp r0, 0
	beq _081330D0
	ldr r0, [r7]
	ldr r1, [r0, 0x18]
	ldrb r0, [r6]
	lsls r0, 4
	adds r0, r2, r0
	adds r1, r0
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _081330D8
_081330D0:
	adds r4, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _081330A8
_081330D8:
	cmp r3, 0x4
	bne _081330F8
_081330DC:
	ldr r0, [r5]
	adds r0, 0x7
	str r0, [r5]
	b _08133110
	.pool
_081330F8:
	ldr r2, [r5]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
_08133110:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai41_unk

	thumb_func_start tai42_unk
tai42_unk: @ 8133118
	push {r4-r6,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	adds r4, r1, 0
	cmp r0, 0x1
	beq _0813313C
	cmp r0, 0x1
	bgt _08133134
	cmp r0, 0
	beq _08133188
	b _081331F4
	.pool
_08133134:
	cmp r0, 0x2
	beq _08133188
	cmp r0, 0x3
	bne _081331F4
_0813313C:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r2, [r0]
	ldr r6, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
	ldr r5, =gAIScriptPtr
_08133150:
	ldrh r0, [r2]
	cmp r0, 0
	beq _0813316A
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _08133172
_0813316A:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08133150
_08133172:
	cmp r3, 0x4
	bne _081331C2
	b _081331DC
	.pool
_08133188:
	movs r3, 0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x18]
	ldr r0, =gEnemyMonIndex
	ldrb r0, [r0]
	ldr r6, =gBattleMoves
	lsls r0, 4
	adds r2, r0, r1
	ldr r5, =gAIScriptPtr
_0813319C:
	ldrh r0, [r2]
	cmp r0, 0
	beq _081331B6
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _081331BE
_081331B6:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _0813319C
_081331BE:
	cmp r3, 0x4
	beq _081331DC
_081331C2:
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	b _081331F4
	.pool
_081331DC:
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
_081331F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end tai42_unk

	thumb_func_start tai43_unk
tai43_unk: @ 81331FC
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _08133218
	ldr r0, =gPlayerMonIndex
	b _0813321A
	.pool
_08133218:
	ldr r0, =gEnemyMonIndex
_0813321A:
	ldrb r3, [r0]
	adds r4, r5, 0
	ldr r2, [r4]
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08133240
	ldr r0, =gUnknown_020242BC
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	beq _08133244
	b _0813325A
	.pool
_08133240:
	cmp r0, 0x1
	beq _0813324A
_08133244:
	adds r0, r2, 0x7
	str r0, [r4]
	b _0813327C
_0813324A:
	ldr r0, =gUnknown_020242BC
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	beq _08133278
_0813325A:
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813327C
	.pool
_08133278:
	adds r0, r2, 0x7
	str r0, [r5]
_0813327C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai43_unk

	thumb_func_start tai44_unk
tai44_unk: @ 8133284
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	cmp r0, 0
	beq _0813329C
	cmp r0, 0x1
	beq _081332C8
	b _08133308
	.pool
_0813329C:
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_02024064
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	ldrh r0, [r0, 0x4]
	ldrh r1, [r1, 0x2]
	cmp r0, r1
	beq _081332E4
	b _08133308
	.pool
_081332C8:
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_02024064
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	ldrh r0, [r0, 0x6]
	ldrh r1, [r1, 0x2]
	cmp r0, r1
	bne _08133308
_081332E4:
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813330C
	.pool
_08133308:
	adds r0, r3, 0x6
	str r0, [r4]
_0813330C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai44_unk

	thumb_func_start tai45_unk
tai45_unk: @ 8133314
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0xB
	orrs r0, r1
	strb r0, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end tai45_unk

	thumb_func_start tai46_unk
tai46_unk: @ 8133328
	push {r4,lr}
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x7B
	ldrb r0, [r0]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcs _08133374
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0813337C
	.pool
_08133374:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0813337C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai46_unk

	thumb_func_start dp15_end_with_move_5
dp15_end_with_move_5: @ 8133388
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0xD
	orrs r0, r1
	strb r0, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end dp15_end_with_move_5

	thumb_func_start dp15_get_held_item_x12__8
dp15_get_held_item_x12__8: @ 813339C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081333B4
	ldr r0, =gPlayerMonIndex
	b _081333B6
	.pool
_081333B4:
	ldr r0, =gEnemyMonIndex
_081333B6:
	ldrb r2, [r0]
	ldr r0, =gUnknown_02024064
	ldrb r0, [r0]
	cmp r0, r2
	beq _081333E0
	ldr r4, =gUnknown_020244A8
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	adds r0, 0x44
	adds r0, r2
	ldrb r0, [r0]
	bl itemid_get_x12
	ldr r1, [r4]
	b _081333F2
	.pool
_081333E0:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	bl itemid_get_x12
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
_081333F2:
	ldr r1, [r1, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_held_item_x12__8

	thumb_func_start tai62_unk
tai62_unk: @ 8133414
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	lsrs r3, r0, 24
	movs r0, 0x1
	ldr r1, =gPlayerMonIndex
	ldrb r2, [r1]
	adds r1, r3, 0
	ands r1, r0
	ands r0, r2
	cmp r1, r0
	bne _0813344C
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	ldrh r3, [r0, 0x2E]
	b _08133458
	.pool
_0813344C:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	adds r0, 0x44
	adds r0, r3
	ldrb r3, [r0]
_08133458:
	ldr r4, =gAIScriptPtr
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	orrs r0, r1
	cmp r0, r3
	bne _08133488
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813348E
	.pool
_08133488:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_0813348E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai62_unk

	thumb_func_start tai49_unk
tai49_unk: @ 8133494
	push {lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081334AC
	ldr r0, =gPlayerMonIndex
	b _081334AE
	.pool
_081334AC:
	ldr r0, =gEnemyMonIndex
_081334AE:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r2, 0x48
	adds r1, r2
	ldr r1, [r1]
	bl pokemon_species_get_gender_info
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai49_unk

	thumb_func_start dp15_enter_battle_countdown_get_state
dp15_enter_battle_countdown_get_state: @ 81334EC
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133508
	ldr r0, =gPlayerMonIndex
	b _0813350A
	.pool
_08133508:
	ldr r0, =gEnemyMonIndex
_0813350A:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_enter_battle_countdown_get_state

	thumb_func_start dp15_stockpile_get_num_uses
dp15_stockpile_get_num_uses: @ 8133538
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133554
	ldr r0, =gPlayerMonIndex
	b _08133556
	.pool
_08133554:
	ldr r0, =gEnemyMonIndex
_08133556:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x9]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_stockpile_get_num_uses

	thumb_func_start dp15_is_double_battle
dp15_is_double_battle: @ 8133584
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	str r0, [r2, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_is_double_battle

	thumb_func_start dp15_get_dp08_item__8
dp15_get_dp08_item__8: @ 81335AC
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _081335C8
	ldr r0, =gPlayerMonIndex
	b _081335CA
	.pool
_081335C8:
	ldr r0, =gEnemyMonIndex
_081335CA:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r1
	adds r0, 0xB8
	ldrb r0, [r0]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_dp08_item__8

	thumb_func_start dp15_move_get_type__8
dp15_move_get_type__8: @ 81335F8
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_type__8

	thumb_func_start dp15_move_get_power__8_8
dp15_move_get_power__8_8: @ 8133624
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_power__8_8

	thumb_func_start dp15_move_get_move_script_id__8
dp15_move_get_move_script_id__8: @ 8133650
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_move_script_id__8

	thumb_func_start dp15_get_protect_endure_activity
dp15_get_protect_endure_activity: @ 813367C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133698
	ldr r0, =gPlayerMonIndex
	b _0813369A
	.pool
_08133698:
	ldr r0, =gEnemyMonIndex
_0813369A:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_protect_endure_activity

	thumb_func_start nullsub_106
nullsub_106: @ 81336C8
	bx lr
	thumb_func_end nullsub_106

	thumb_func_start nullsub_107
nullsub_107: @ 81336CC
	bx lr
	thumb_func_end nullsub_107

	thumb_func_start nullsub_108
nullsub_108: @ 81336D0
	bx lr
	thumb_func_end nullsub_108

	thumb_func_start nullsub_109
nullsub_109: @ 81336D4
	bx lr
	thumb_func_end nullsub_109

	thumb_func_start nullsub_110
nullsub_110: @ 81336D8
	bx lr
	thumb_func_end nullsub_110

	thumb_func_start nullsub_111
nullsub_111: @ 81336DC
	bx lr
	thumb_func_end nullsub_111

	thumb_func_start tai58_unk
tai58_unk: @ 81336E0
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	adds r0, 0x5
	bl b_mc_stack_push
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai58_unk

	thumb_func_start dp15_jump
dp15_jump: @ 8133710
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	bx lr
	.pool
	thumb_func_end dp15_jump

	thumb_func_start dp15_return
dp15_return: @ 8133730
	push {lr}
	bl b_mc_stack_pop_cursor
	lsls r0, 24
	cmp r0, 0
	bne _0813374A
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x10]
_0813374A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_return

	thumb_func_start dp15_compare_attacker_defender_levels
dp15_compare_attacker_defender_levels: @ 8133754
	push {r4,r5,lr}
	ldr r5, =gAIScriptPtr
	ldr r4, [r5]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	beq _081337A8
	cmp r0, 0x1
	bgt _08133770
	cmp r0, 0
	beq _08133776
	b _08133824
	.pool
_08133770:
	cmp r0, 0x2
	beq _081337D8
	b _08133824
_08133776:
	ldr r3, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gEnemyMonIndex
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhi _081337FA
	b _08133820
	.pool
_081337A8:
	ldr r3, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gEnemyMonIndex
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _081337FA
	b _08133820
	.pool
_081337D8:
	ldr r3, =gBattleMons
	ldr r0, =gPlayerMonIndex
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gEnemyMonIndex
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08133820
_081337FA:
	ldrb r1, [r4, 0x2]
	ldrb r0, [r4, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r4, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r4, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _08133824
	.pool
_08133820:
	adds r0, r4, 0x6
	str r0, [r5]
_08133824:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp15_compare_attacker_defender_levels

	thumb_func_start tai5C_unk
tai5C_unk: @ 813382C
	push {lr}
	ldr r2, =gUnknown_020242BC
	ldr r0, =gEnemyMonIndex
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	lsls r0, 28
	cmp r0, 0
	beq _0813386C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08133874
	.pool
_0813386C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08133874:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5C_unk

	thumb_func_start tai5D_unk
tai5D_unk: @ 813387C
	push {lr}
	ldr r2, =gUnknown_020242BC
	ldr r0, =gEnemyMonIndex
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	lsls r0, 28
	cmp r0, 0
	bne _081338BC
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081338C4
	.pool
_081338BC:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_081338C4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5D_unk

	thumb_func_start tai5E_unk
tai5E_unk: @ 81338CC
	push {lr}
	ldr r0, =gPlayerMonIndex
	ldrb r3, [r0]
	movs r0, 0x1
	ldr r1, =gEnemyMonIndex
	ldrb r2, [r1]
	adds r1, r0, 0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _0813390C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08133914
	.pool
_0813390C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08133914:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5E_unk

	thumb_func_start tai61_unk
tai61_unk: @ 813391C
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	lsrs r0, 22
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08133960
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08133966
	.pool
_08133960:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_08133966:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai61_unk

	thumb_func_start b_mc_stack_push
b_mc_stack_push: @ 813396C
	push {r4,lr}
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r3, [r1, 0x1C]
	adds r4, r3, 0
	adds r4, 0x20
	ldrb r1, [r4]
	adds r2, r1, 0x1
	strb r2, [r4]
	lsls r1, 24
	lsrs r1, 22
	adds r3, r1
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_mc_stack_push

	thumb_func_start b_mc_stack_push_cursor
b_mc_stack_push_cursor: @ 8133990
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x1C]
	adds r3, r2, 0
	adds r3, 0x20
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, 24
	lsrs r0, 22
	adds r2, r0
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end b_mc_stack_push_cursor

	thumb_func_start b_mc_stack_pop_cursor
b_mc_stack_pop_cursor: @ 81339B8
	push {lr}
	ldr r3, =gUnknown_020244A8
	ldr r0, [r3]
	ldr r0, [r0, 0x1C]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _081339D4
	movs r0, 0
	b _081339EE
	.pool
_081339D4:
	subs r0, 0x1
	strb r0, [r1]
	ldr r2, =gAIScriptPtr
	ldr r0, [r3]
	ldr r1, [r0, 0x1C]
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0x1
_081339EE:
	pop {r1}
	bx r1
	.pool
	thumb_func_end b_mc_stack_pop_cursor

	.align 2, 0 @ Don't pad with nop.
