	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8184DA4
sub_8184DA4: @ 8184DA4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	ldr r0, =gUnknown_0203C7AC
	mov r1, r12
	strb r1, [r0]
	ldr r1, =gUnknown_0203CCD0
	movs r0, 0
	strb r0, [r1]
	movs r2, 0
	movs r7, 0
	ldr r3, =gUnknown_0203C7BC
	mov r10, r3
	ldr r6, =gUnknown_0203C794
	mov r9, r6
	ldr r0, =gUnknown_0203BD34
	mov r8, r0
_08184DD0:
	lsls r0, r2, 1
	mov r3, r9
	adds r1, r0, r3
	strh r7, [r1]
	ldr r6, =gUnknown_0203C79C
	adds r1, r0, r6
	strh r7, [r1]
	ldr r1, =gUnknown_0203C7A4
	adds r0, r1
	strh r7, [r0]
	adds r4, r2, 0x1
	mov r3, r12
	cmp r3, 0x1
	bne _08184E1C
	ldr r5, =gBattleTypeFlags
	movs r3, 0xFF
	movs r1, 0xA6
	lsls r1, 2
	adds r0, r2, 0
	muls r0, r1
	mov r6, r8
	adds r2, r0, r6
_08184DFC:
	ldrb r0, [r2]
	orrs r0, r3
	strb r0, [r2]
	adds r2, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _08184DFC
	ldr r0, [r5]
	ldr r1, =gUnknown_0203C7B8
	str r0, [r1]
	ldr r3, =gBattleResources
	ldr r0, [r3]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0xC]
	mov r6, r10
	str r0, [r6]
_08184E1C:
	adds r2, r4, 0
	cmp r2, 0x3
	ble _08184DD0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184DA4

	thumb_func_start sub_8184E58
sub_8184E58: @ 8184E58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r0, =gUnknown_0203C7AC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08184EA0
	ldr r1, =gRecordedBattleRngSeed
	ldr r0, =gRngValue
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, =gUnknown_0203C7AE
	ldr r0, =0x000040cf
	bl VarGet
	strb r0, [r4]
	ldr r4, =gUnknown_0203C7AF
	bl sub_81A513C
	strb r0, [r4]
	b _08184EAC
	.pool
_08184EA0:
	cmp r0, 0x2
	bne _08184EAC
	ldr r0, =gRngValue
	ldr r1, =gRecordedBattleRngSeed
	ldr r1, [r1]
	str r1, [r0]
_08184EAC:
	ldr r0, =gBattleTypeFlags
	ldr r5, [r0]
	movs r0, 0x2
	ands r5, r0
	cmp r5, 0
	beq _08184F64
	bl GetMultiplayerId
	ldr r1, =gUnknown_0203C7B4
	strb r0, [r1]
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r5, 0
	ldr r0, =gUnknown_0203CC80
	mov r9, r0
	ldr r6, =gLinkPlayers
	movs r0, 0x8
	adds r0, r6
	mov r8, r0
	mov r7, r9
	adds r7, 0x4
_08184EDC:
	lsls r0, r5, 2
	adds r0, r5
	lsls r4, r0, 2
	mov r0, r9
	adds r2, r4, r0
	lsls r0, r5, 3
	subs r0, r5
	lsls r3, r0, 2
	adds r0, r6, 0x4
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r3, r6
	ldrb r0, [r1, 0x13]
	strb r0, [r2, 0xC]
	ldrh r0, [r1, 0x18]
	strh r0, [r2, 0xE]
	ldrh r0, [r1, 0x1A]
	strh r0, [r2, 0x10]
	cmp r5, r10
	bge _08184F3C
	mov r0, r8
	adds r1, r3, r0
	mov r0, sp
	bl StringCopy
	mov r0, sp
	bl StripExtCtrlCodes
	adds r0, r4, r7
	mov r1, sp
	bl StringCopy
	adds r5, 0x1
	b _08184F56
	.pool
_08184F3C:
	adds r5, 0x1
	ldr r0, =gLinkPlayers + 8
	adds r1, r3, r0
	ldr r0, =gUnknown_0203CC84
	adds r2, r4, r0
	movs r3, 0x7
_08184F48:
	ldrb r0, [r1]
	strb r0, [r2]
	adds r1, 0x1
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08184F48
_08184F56:
	cmp r5, 0x3
	ble _08184EDC
	b _08184FA0
	.pool
_08184F64:
	ldr r3, =gUnknown_0203CC80
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	ldrb r1, [r2, 0xA]
	ldrb r0, [r2, 0xB]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0xC]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0xD]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	ldrb r0, [r2, 0x8]
	strb r0, [r3, 0xC]
	strh r5, [r3, 0xE]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strh r0, [r3, 0x10]
	movs r5, 0
	adds r3, 0x4
_08184F90:
	adds r0, r5, r3
	ldr r1, [r4]
	adds r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x7
	ble _08184F90
_08184FA0:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184E58

	thumb_func_start RecordedBattle_SetBankAction
RecordedBattle_SetBankAction: @ 8184FBC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r1, =gUnknown_0203C794
	lsls r0, r5, 1
	adds r4, r0, r1
	ldrh r2, [r4]
	adds r3, r2, 0
	ldr r0, =0x00000297
	cmp r3, r0
	bhi _08184FF0
	ldr r0, =gUnknown_0203C7AC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08184FF0
	ldr r1, =gUnknown_0203BD34
	adds r0, r2, 0x1
	strh r0, [r4]
	movs r0, 0xA6
	lsls r0, 2
	muls r0, r5
	adds r0, r3, r0
	adds r0, r1
	strb r6, [r0]
_08184FF0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RecordedBattle_SetBankAction

	thumb_func_start sub_8185008
sub_8185008: @ 8185008
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r3, 0
	cmp r3, r4
	bge _08185046
	ldr r0, =gUnknown_0203C794
	lsls r1, r5, 1
	adds r2, r1, r0
	ldr r7, =gUnknown_0203BD34
	movs r0, 0xA6
	lsls r0, 2
	muls r5, r0
	movs r6, 0xFF
_08185028:
	ldrh r0, [r2]
	subs r0, 0x1
	strh r0, [r2]
	ldrh r1, [r2]
	adds r1, r5
	adds r1, r7
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, 0
	beq _08185046
	adds r3, 0x1
	cmp r3, r4
	blt _08185028
_08185046:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185008

	thumb_func_start sub_8185054
sub_8185054: @ 8185054
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gUnknown_0203C794
	lsls r0, r3, 1
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, =0x00000297
	cmp r1, r0
	bhi _0818507A
	ldr r4, =gUnknown_0203BD34
	adds r0, 0x1
	muls r3, r0
	adds r0, r1, r3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081850BC
_0818507A:
	ldr r2, =gScriptResult
	ldr r1, =gBattleOutcome
	movs r0, 0x5
	strb r0, [r1]
	movs r0, 0x5
	strh r0, [r2]
	bl ResetPaletteFadeControl
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_80384E4
	bl SetMainCallback2
	movs r0, 0xFF
	b _081850C6
	.pool
_081850BC:
	adds r0, r1, 0x1
	strh r0, [r2]
	adds r0, r1, r3
	adds r0, r4
	ldrb r0, [r0]
_081850C6:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8185054

	thumb_func_start sub_81850D0
sub_81850D0: @ 81850D0
	ldr r0, =gUnknown_0203C7AC
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81850D0

	thumb_func_start sub_81850DC
sub_81850DC: @ 81850DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	movs r7, 0
	movs r0, 0
	mov r12, r0
_081850F0:
	mov r1, r12
	lsls r3, r1, 1
	ldr r0, =gUnknown_0203C794
	adds r5, r3, r0
	ldr r1, =gUnknown_0203C79C
	adds r6, r3, r1
	ldrh r0, [r5]
	mov r9, r3
	mov r1, r12
	adds r1, 0x1
	str r1, [sp]
	ldrh r1, [r6]
	cmp r0, r1
	beq _0818517E
	adds r1, r7, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r2, r7, 0
	add r1, r8
	mov r0, r12
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	add r2, r8
	ldrb r0, [r5]
	ldrb r1, [r6]
	subs r0, r1
	strb r0, [r2]
	movs r4, 0
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r1
	cmp r4, r0
	bge _08185172
	ldr r1, =gUnknown_0203BD34
	mov r10, r1
	ldr r6, =gUnknown_0203C79C
	movs r0, 0xA6
	lsls r0, 2
	mov r5, r12
	muls r5, r0
_08185146:
	adds r1, r7, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	add r1, r8
	adds r2, r3, r6
	ldrh r0, [r2]
	adds r0, r4
	adds r0, r5
	add r0, r10
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0203C794
	adds r0, r3, r1
	ldrh r1, [r0]
	ldrh r0, [r2]
	subs r1, r0
	cmp r4, r1
	blt _08185146
_08185172:
	ldr r0, =gUnknown_0203C79C
	add r0, r9
	ldr r1, =gUnknown_0203C794
	add r1, r9
	ldrh r1, [r1]
	strh r1, [r0]
_0818517E:
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r12, r0
	cmp r0, 0x3
	bls _081850F0
	adds r0, r7, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81850DC

	thumb_func_start sub_81851A8
sub_81851A8: @ 81851A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r7, r0, 0
	movs r1, 0x2
	mov r0, sp
	strb r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _0818525E
	movs r5, 0
	ldr r4, =gLinkPlayers
	b _081851DA
	.pool
_081851D0:
	ldrb r0, [r4]
	cmp r0, 0x3
	bne _0818525E
	adds r4, 0x1C
	adds r5, 0x1
_081851DA:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _081851D0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0818525E
	ldrb r0, [r7]
	mov r4, sp
	adds r4, 0x1
	strb r0, [r4]
	ldrb r0, [r4]
	mov r8, r4
	cmp r0, 0
	beq _0818525E
_08185202:
	adds r0, r7, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_8185278
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_8185278
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08185256
	ldr r3, =gUnknown_0203BD34
	ldr r0, =gUnknown_0203C7A4
	lsls r1, r6, 1
	adds r4, r1, r0
	adds r5, r2, 0
	movs r0, 0xA6
	lsls r0, 2
	muls r6, r0
_08185232:
	adds r0, r7, 0
	mov r1, sp
	mov r2, r8
	str r3, [sp, 0x4]
	bl sub_8185278
	ldrh r1, [r4]
	adds r2, r1, 0x1
	strh r2, [r4]
	lsls r1, 16
	lsrs r1, 16
	adds r1, r6
	ldr r3, [sp, 0x4]
	adds r1, r3
	strb r0, [r1]
	subs r5, 0x1
	cmp r5, 0
	bne _08185232
_08185256:
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, 0
	bne _08185202
_0818525E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81851A8

	thumb_func_start sub_8185278
sub_8185278: @ 8185278
	ldrb r3, [r2]
	subs r3, 0x1
	strb r3, [r2]
	ldrb r2, [r1]
	adds r3, r2, 0x1
	strb r3, [r1]
	lsls r2, 24
	lsrs r2, 24
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	thumb_func_end sub_8185278

	thumb_func_start sub_8185290
sub_8185290: @ 8185290
	push {r4,r5,lr}
	movs r0, 0xF8
	lsls r0, 4
	bl AllocZeroed
	adds r4, r0, 0
	bl start_ov_to_battle_anim
	adds r5, r0, 0
	adds r0, r4, 0
	bl Free
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8185290

	thumb_func_start sub_81852B0
sub_81852B0: @ 81852B0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =0x000004ec
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, 0
	beq _081852E8
	ldr r0, =0x7d007e92
	ands r1, r0
	cmp r1, 0
	bne _081852E8
	ldr r4, =0x00000f7c
	adds r0, r5, 0
	adds r1, r4, 0
	bl CalcByteArraySum
	adds r4, r5, r4
	ldr r1, [r4]
	cmp r0, r1
	bne _081852E8
	movs r0, 0x1
	b _081852EA
	.pool
_081852E8:
	movs r0, 0
_081852EA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81852B0

	thumb_func_start sub_81852F0
sub_81852F0: @ 81852F0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r5, 0
	movs r1, 0
	bl memset
	movs r2, 0xF8
	lsls r2, 4
	adds r0, r5, 0
	adds r1, r4, 0
	bl memcpy
	ldr r4, =0x00000f7c
	adds r0, r5, 0
	adds r1, r4, 0
	bl CalcByteArraySum
	adds r4, r5, r4
	str r0, [r4]
	movs r0, 0x1F
	adds r1, r5, 0
	bl sub_8153634
	cmp r0, 0x1
	bne _08185330
	movs r0, 0x1
	b _08185332
	.pool
_08185330:
	movs r0, 0
_08185332:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81852F0

	thumb_func_start sub_8185338
sub_8185338: @ 8185338
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0xF8
	lsls r0, 4
	bl AllocZeroed
	adds r7, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	str r0, [sp]
	movs r6, 0
_0818535E:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	adds r5, r7, r4
	ldr r1, =gUnknown_0203C7C0
	adds r1, r4, r1
	adds r0, r5, 0
	movs r2, 0x64
	bl memcpy
	movs r1, 0x96
	lsls r1, 2
	adds r5, r1
	ldr r0, =gUnknown_0203CA18
	adds r4, r0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r6, 0x1
	cmp r6, 0x5
	ble _0818535E
	movs r6, 0
	ldr r2, =gSaveBlock2Ptr
	mov r9, r2
	movs r3, 0x9A
	lsls r3, 3
	adds r3, r7, r3
	str r3, [sp, 0x8]
	ldr r5, =gUnknown_0203CC80
	mov r8, r6
	mov r12, r6
	movs r4, 0x96
	lsls r4, 3
	adds r4, r7
	mov r10, r4
	ldr r0, =0x000004e4
	adds r4, r7, r0
_081853AC:
	lsls r1, r6, 3
	ldr r0, =gUnknown_0203CC80
	adds r0, 0x4
	mov r3, r8
	adds r2, r3, r0
	add r1, r10
	movs r3, 0x7
_081853BA:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _081853BA
	ldr r0, [sp, 0x8]
	adds r1, r0, r6
	ldrb r0, [r5, 0xC]
	strb r0, [r1]
	ldrh r0, [r5, 0x10]
	strb r0, [r4]
	ldrh r0, [r5, 0xE]
	strb r0, [r4, 0xC]
	ldr r1, =0x000004d4
	adds r0, r7, r1
	add r0, r12
	ldr r1, [r5]
	str r1, [r0]
	adds r5, 0x14
	movs r2, 0x14
	add r8, r2
	movs r3, 0x4
	add r12, r3
	adds r4, 0x1
	adds r6, 0x1
	cmp r6, 0x3
	ble _081853AC
	movs r4, 0x9D
	lsls r4, 3
	adds r1, r7, r4
	ldr r5, =gRecordedBattleRngSeed
	ldr r0, [r5]
	str r0, [r1]
	ldr r0, =gUnknown_0203C7B8
	ldr r2, [r0]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _081854DC
	ldr r1, =0x000004ec
	adds r3, r7, r1
	movs r1, 0x23
	negs r1, r1
	ands r1, r2
	movs r0, 0x80
	lsls r0, 18
	orrs r1, r0
	str r1, [r3]
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _08185454
	movs r0, 0x80
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081854E2
	.pool
_08185454:
	movs r0, 0x40
	ands r2, r0
	cmp r2, 0
	beq _081854E2
	ldr r2, =gUnknown_0203CC80
	ldrh r0, [r2, 0xE]
	cmp r0, 0x1
	beq _081854A8
	cmp r0, 0x1
	bgt _08185474
	cmp r0, 0
	beq _0818547E
	b _081854E2
	.pool
_08185474:
	cmp r0, 0x2
	beq _0818547E
	cmp r0, 0x3
	beq _081854A8
	b _081854E2
_0818547E:
	ldr r3, =gUnknown_0203C7B4
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_0203CC80
	adds r0, r4
	ldrh r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081854E2
	ldr r5, =0x000004ec
	adds r0, r7, r5
	b _081854C4
	.pool
_081854A8:
	ldr r0, =gUnknown_0203C7B4
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_0203CC80
	adds r0, r1
	ldrh r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081854E2
	ldr r2, =0x000004ec
	adds r0, r7, r2
_081854C4:
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 24
	orrs r1, r2
	str r1, [r0]
	b _081854E2
	.pool
_081854DC:
	ldr r3, =0x000004ec
	adds r0, r7, r3
	str r2, [r0]
_081854E2:
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r1, [r4]
	ldr r5, =0x000004f4
	adds r0, r7, r5
	strh r1, [r0]
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r1, [r0]
	ldr r2, =0x000004f6
	adds r0, r7, r2
	strh r1, [r0]
	ldr r3, =gPartnerTrainerId
	ldrh r1, [r3]
	movs r4, 0x9F
	lsls r4, 3
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, =gUnknown_0203C7B4
	ldrb r1, [r5]
	adds r2, 0x4
	adds r0, r7, r2
	strh r1, [r0]
	mov r3, r9
	ldr r0, [r3]
	ldr r4, =0x00000ca9
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	ldr r5, =0x000004fc
	adds r1, r7, r5
	strb r0, [r1]
	ldr r0, =gUnknown_0203C7AE
	ldrb r1, [r0]
	adds r2, 0x3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, =gUnknown_0203C7AF
	ldrb r1, [r3]
	ldr r4, =0x000004fe
	adds r0, r7, r4
	strb r1, [r0]
	mov r5, r9
	ldr r0, [r5]
	ldrb r1, [r0, 0x15]
	lsls r1, 29
	ldr r0, =0x000004ff
	adds r3, r7, r0
	lsrs r1, 31
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r5]
	ldrb r1, [r1, 0x14]
	lsls r1, 29
	lsrs r1, 28
	movs r2, 0xF
	negs r2, r2
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r2, 0xA0
	lsls r2, 3
	adds r1, r7, r2
	ldr r3, =gUnknown_0203C7BC
	ldr r0, [r3]
	str r0, [r1]
	ldr r4, =0xfffffed4
	adds r1, r4, 0
	ldr r5, =gTrainerBattleOpponent_A
	ldrh r5, [r5]
	adds r0, r1, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x63
	bls _08185580
	b _081856C4
_08185580:
	movs r6, 0
	ldr r0, =0x00000504
	adds r3, r7, r0
	mov r10, r9
	ldr r1, =gTrainerBattleOpponent_A
	mov r12, r1
	adds r2, r4, 0
	mov r8, r2
	ldr r4, =0x0000073c
_08185592:
	adds r2, r3, r6
	mov r5, r10
	ldr r1, [r5]
	mov r5, r12
	ldrh r0, [r5]
	add r0, r8
	movs r5, 0xEC
	muls r0, r5
	adds r0, r6, r0
	adds r1, r4
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x7
	ble _08185592
	mov r0, r9
	ldr r2, [r0]
	ldr r1, =gTrainerBattleOpponent_A
	ldrh r0, [r1]
	ldr r3, =0xfffffed4
	adds r0, r3
	movs r1, 0xEC
	muls r0, r1
	adds r2, r0
	ldr r4, =0x00000739
	adds r2, r4
	ldrb r1, [r2]
	ldr r5, =0x0000050c
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, =gUnknown_0203CCE8
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08185664
	movs r6, 0
	ldr r2, =0x0000050e
	adds r4, r7, r2
	mov r10, r9
	ldr r5, =gTrainerBattleOpponent_A
	mov r8, r5
	adds r5, r3, 0
_081855E6:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r5
	movs r1, 0xEC
	muls r0, r1
	adds r3, r0
	movs r0, 0xEC
	lsls r0, 3
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _081855E6
	b _08185696
	.pool
_08185664:
	movs r6, 0
	ldr r1, =0x0000050e
	adds r4, r7, r1
	mov r10, r9
	ldr r2, =gTrainerBattleOpponent_A
	mov r8, r2
	adds r5, r3, 0
_08185672:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r5
	movs r1, 0xEC
	muls r0, r1
	adds r3, r0
	ldr r0, =0x00000754
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _08185672
_08185696:
	mov r1, r9
	ldr r2, [r1]
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r0, [r3]
	ldr r4, =0xfffffed4
	adds r0, r4
	movs r1, 0xEC
	muls r0, r1
	adds r2, r0
	ldr r5, =0x0000081c
	adds r2, r5
	ldrb r1, [r2]
	b _08185856
	.pool
_081856C4:
	ldr r3, =gTrainerBattleOpponent_B
	ldrh r3, [r3]
	adds r0, r1, r3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x63
	bls _081856D4
	b _081857E4
_081856D4:
	movs r6, 0
	ldr r4, =0x00000504
	adds r3, r7, r4
	mov r10, r9
	ldr r5, =gTrainerBattleOpponent_B
	mov r12, r5
	ldr r0, =0xfffffed4
	mov r8, r0
	ldr r4, =0x0000073c
_081856E6:
	adds r2, r3, r6
	mov r5, r10
	ldr r1, [r5]
	mov r5, r12
	ldrh r0, [r5]
	add r0, r8
	movs r5, 0xEC
	muls r0, r5
	adds r0, r6, r0
	adds r1, r4
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x7
	ble _081856E6
	mov r0, r9
	ldr r2, [r0]
	ldr r1, =gTrainerBattleOpponent_B
	ldrh r0, [r1]
	ldr r3, =0xfffffed4
	adds r0, r3
	movs r1, 0xEC
	muls r0, r1
	adds r2, r0
	ldr r4, =0x00000739
	adds r2, r4
	ldrb r1, [r2]
	ldr r5, =0x0000050c
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, =gUnknown_0203CCE8
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08185784
	movs r6, 0
	ldr r2, =0x0000050e
	adds r4, r7, r2
	mov r10, r9
	ldr r5, =gTrainerBattleOpponent_B
	mov r8, r5
	adds r5, r3, 0
_0818573A:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r5
	movs r1, 0xEC
	muls r0, r1
	adds r3, r0
	movs r0, 0xEC
	lsls r0, 3
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _0818573A
	b _081857B6
	.pool
_08185784:
	movs r6, 0
	ldr r1, =0x0000050e
	adds r4, r7, r1
	mov r10, r9
	ldr r2, =gTrainerBattleOpponent_B
	mov r8, r2
	adds r5, r3, 0
_08185792:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r5
	movs r1, 0xEC
	muls r0, r1
	adds r3, r0
	ldr r0, =0x00000754
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _08185792
_081857B6:
	mov r1, r9
	ldr r2, [r1]
	ldr r3, =gTrainerBattleOpponent_B
	ldrh r0, [r3]
	ldr r4, =0xfffffed4
	adds r0, r4
	movs r1, 0xEC
	muls r0, r1
	adds r2, r0
	ldr r5, =0x0000081c
	adds r2, r5
	ldrb r1, [r2]
	b _08185856
	.pool
_081857E4:
	ldr r3, =gPartnerTrainerId
	ldrh r3, [r3]
	adds r0, r1, r3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x63
	bhi _0818585C
	movs r6, 0
	ldr r4, =0x00000504
	adds r3, r7, r4
	mov r10, r9
	ldr r5, =gPartnerTrainerId
	mov r12, r5
	ldr r0, =0xfffffed4
	mov r8, r0
	ldr r4, =0x0000073c
_08185804:
	adds r2, r3, r6
	mov r5, r10
	ldr r1, [r5]
	mov r5, r12
	ldrh r0, [r5]
	add r0, r8
	movs r5, 0xEC
	muls r0, r5
	adds r0, r6, r0
	adds r1, r4
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x7
	ble _08185804
	mov r0, r9
	ldr r1, [r0]
	ldr r2, =gPartnerTrainerId
	ldrh r0, [r2]
	ldr r3, =0xfffffed4
	adds r0, r3
	movs r2, 0xEC
	muls r0, r2
	adds r1, r0
	ldr r4, =0x00000739
	adds r1, r4
	ldrb r1, [r1]
	ldr r5, =0x0000050c
	adds r0, r7, r5
	strb r1, [r0]
	mov r0, r9
	ldr r1, [r0]
	ldr r4, =gPartnerTrainerId
	ldrh r0, [r4]
	adds r0, r3
	muls r0, r2
	adds r1, r0
	ldr r5, =0x0000081c
	adds r1, r5
	ldrb r1, [r1]
_08185856:
	ldr r2, =0x0000051a
	adds r0, r7, r2
	strb r1, [r0]
_0818585C:
	ldr r3, =gTrainerBattleOpponent_A
	ldrh r0, [r3]
	ldr r1, =0x0000018f
	cmp r0, r1
	bls _08185900
	mov r4, r9
	ldr r2, [r4]
	adds r1, r0, 0
	ldr r3, =0xfffffe70
	adds r1, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, 0xDC
	ldrb r0, [r2]
	lsls r0, 27
	lsrs r0, 27
	ldr r5, =0x0000050d
	adds r1, r7, r5
	strb r0, [r1]
	movs r6, 0
	ldr r0, =0x0000050e
	adds r4, r7, r0
	mov r10, r9
	ldr r1, =gTrainerBattleOpponent_A
	mov r8, r1
	adds r5, r3, 0
_08185894:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r0, r8
	ldrh r1, [r0]
	adds r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	movs r1, 0x82
	lsls r1, 1
	adds r2, r1
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _08185894
	mov r3, r9
	ldr r2, [r3]
	ldr r4, =gTrainerBattleOpponent_A
	ldrh r1, [r4]
	ldr r5, =0xfffffe70
	adds r1, r5
	b _081859AC
	.pool
_08185900:
	ldr r3, =gTrainerBattleOpponent_B
	ldrh r0, [r3]
	cmp r0, r1
	bls _0818597C
	mov r4, r9
	ldr r2, [r4]
	adds r1, r0, 0
	ldr r3, =0xfffffe70
	adds r1, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, 0xDC
	ldrb r0, [r2]
	lsls r0, 27
	lsrs r0, 27
	ldr r5, =0x0000050d
	adds r1, r7, r5
	strb r0, [r1]
	movs r6, 0
	ldr r0, =0x0000050e
	adds r4, r7, r0
	mov r10, r9
	ldr r1, =gTrainerBattleOpponent_B
	mov r8, r1
	adds r5, r3, 0
_08185936:
	lsls r3, r6, 1
	mov r0, r10
	ldr r2, [r0]
	mov r0, r8
	ldrh r1, [r0]
	adds r1, r5
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	movs r1, 0x82
	lsls r1, 1
	adds r2, r1
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x5
	ble _08185936
	mov r3, r9
	ldr r2, [r3]
	ldr r4, =gTrainerBattleOpponent_B
	ldrh r1, [r4]
	ldr r5, =0xfffffe70
	adds r1, r5
	b _081859AC
	.pool
_0818597C:
	ldr r3, =gPartnerTrainerId
	ldrh r0, [r3]
	cmp r0, r1
	bls _081859C0
	mov r4, r9
	ldr r2, [r4]
	adds r1, r0, 0
	ldr r3, =0xfffffe70
	adds r1, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, 0xDC
	ldrb r0, [r2]
	lsls r0, 27
	lsrs r0, 27
	ldr r5, =0x0000050d
	adds r1, r7, r5
	strb r0, [r1]
	ldr r2, [r4]
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	adds r1, r3
_081859AC:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r1, =0x0000011b
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r2, =0x0000051b
	adds r0, r7, r2
	strb r1, [r0]
_081859C0:
	movs r6, 0
	ldr r3, =0x00000297
	mov r10, r3
	ldr r4, =gUnknown_0203BD34
	mov r9, r4
	movs r5, 0xA6
	lsls r5, 2
	mov r8, r5
	ldr r0, =0x0000051c
	adds r5, r7, r0
_081859D4:
	adds r4, r6, 0x1
	mov r0, r8
	muls r0, r6
	mov r1, r9
	adds r2, r0, r1
	adds r1, r0, r5
	mov r3, r10
	adds r3, 0x1
_081859E4:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _081859E4
	adds r6, r4, 0
	cmp r6, 0x3
	ble _081859D4
_081859F8:
	adds r0, r7, 0
	ldr r1, [sp]
	bl sub_81852F0
	adds r4, r0, 0
	cmp r4, 0x1
	beq _08185A14
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	cmp r0, 0x2
	bls _081859F8
_08185A14:
	adds r0, r7, 0
	bl Free
	ldr r0, [sp]
	bl Free
	adds r0, r4, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8185338

	thumb_func_start sub_8185A54
sub_8185A54: @ 8185A54
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0x1F
	bl sub_81535DC
	cmp r0, 0x1
	bne _08185A7E
	movs r2, 0xF8
	lsls r2, 4
	adds r0, r5, 0
	adds r1, r4, 0
	bl memcpy
	adds r0, r5, 0
	bl sub_81852B0
	cmp r0, 0
	beq _08185A7E
	movs r0, 0x1
	b _08185A80
_08185A7E:
	movs r0, 0
_08185A80:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8185A54

	thumb_func_start start_ov_to_battle_anim
start_ov_to_battle_anim: @ 8185A88
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8185A54
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end start_ov_to_battle_anim

	thumb_func_start sub_8185AB0
sub_8185AB0: @ 8185AB0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =gUnknown_0203C7AD
	ldrb r0, [r0]
	ldr r1, =0x00000ca9
	adds r2, r1
	movs r1, 0x3
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleOutcome
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gBattleTypeFlags
	movs r1, 0
	str r1, [r0]
	ldr r0, =gTrainerBattleOpponent_A
	strh r1, [r0]
	ldr r0, =gTrainerBattleOpponent_B
	strh r1, [r0]
	ldr r0, =gPartnerTrainerId
	strh r1, [r0]
	bl sub_8185EFC
	ldr r0, =gUnknown_0203C7B0
	ldr r0, [r0]
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185AB0

	thumb_func_start sub_8185B1C
sub_8185B1C: @ 8185B1C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	cmp r1, 0
	bne _08185B4A
	ldr r0, =gMain
	ldr r1, =sub_8185AB0
	str r1, [r0, 0x8]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08185B4A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185B1C

	thumb_func_start sub_8185B60
sub_8185B60: @ 8185B60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	bl ZeroPlayerPartyMons
	bl ZeroEnemyPartyMons
	movs r6, 0
	ldr r0, =gPlayerParty
	mov r8, r0
_08185B7C:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	mov r1, r8
	adds r0, r4, r1
	adds r5, r7, r4
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	ldr r0, =gEnemyParty
	adds r4, r0
	movs r2, 0x96
	lsls r2, 2
	adds r5, r2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r6, 0x1
	cmp r6, 0x5
	ble _08185B7C
	movs r6, 0
	ldr r3, =gLinkPlayers
	mov r8, r3
	mov r0, r8
	adds r0, 0x8
	str r0, [sp]
	mov r4, r8
	adds r4, 0x4
	mov r10, r6
	mov r9, r6
_08185BBE:
	movs r1, 0
	mov r12, r1
	lsls r5, r6, 2
	movs r2, 0x96
	lsls r2, 3
	adds r0, r7, r2
	mov r3, r9
	adds r2, r3, r0
	mov r0, r10
	lsls r1, r0, 2
	mov r0, r8
	adds r0, 0x8
	adds r1, r0
	movs r3, 0x7
_08185BDA:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _08185BE8
	movs r0, 0x1
	mov r12, r0
_08185BE8:
	adds r2, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08185BDA
	movs r1, 0x9A
	lsls r1, 3
	adds r0, r7, r1
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r4, 0xF]
	ldr r2, =0x000004e4
	adds r0, r7, r2
	adds r0, r6
	ldrb r1, [r0]
	strh r1, [r4, 0x16]
	movs r3, 0x9E
	lsls r3, 3
	adds r0, r7, r3
	adds r0, r6
	ldrb r0, [r0]
	strh r0, [r4, 0x14]
	subs r2, 0x10
	adds r0, r7, r2
	adds r0, r5
	ldr r0, [r0]
	str r0, [r4]
	mov r3, r12
	cmp r3, 0
	beq _08185C2A
	ldr r0, [sp]
	bl ConvertInternationalString
_08185C2A:
	ldr r0, [sp]
	adds r0, 0x1C
	str r0, [sp]
	adds r4, 0x1C
	movs r1, 0x7
	add r10, r1
	movs r2, 0x8
	add r9, r2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08185BBE
	ldr r1, =gRecordedBattleRngSeed
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, =gBattleTypeFlags
	ldr r1, =0x000004ec
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gTrainerBattleOpponent_A
	ldr r2, =0x000004f4
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gTrainerBattleOpponent_B
	adds r3, 0xE
	adds r0, r7, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gPartnerTrainerId
	adds r2, 0x4
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_0203C7B4
	adds r3, 0x4
	adds r0, r7, r3
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r1, =gUnknown_0203C7AD
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	ldr r2, =0x00000ca9
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r1]
	ldr r1, =gUnknown_0203C7AE
	ldr r2, =0x000004fd
	adds r0, r7, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, =gUnknown_0203C7AF
	adds r2, 0x1
	adds r0, r7, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r2, =gUnknown_0203C7B6
	ldr r1, =0x000004ff
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, 31
	lsrs r0, 31
	strb r0, [r2]
	ldr r0, =gUnknown_0203C7B7
	lsls r1, 28
	lsrs r1, 29
	strb r1, [r0]
	ldr r1, =gUnknown_0203C7BC
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r6, 0
	mov r10, r3
	ldr r2, =gUnknown_0203CCD9
	ldr r3, =gUnknown_0203CCDA
	ldr r0, =gUnknown_03001278
	mov r8, r0
	ldr r1, =gUnknown_03001279
	mov r9, r1
	ldr r5, =gUnknown_0203CCD1
	ldr r0, =0x00000504
	adds r4, r7, r0
_08185CE2:
	adds r0, r6, r5
	adds r1, r4, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x7
	ble _08185CE2
	ldr r1, =0x0000050c
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, =0x0000050d
	adds r0, r7, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r3, =0x0000051a
	adds r0, r7, r3
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	adds r2, 0xE
	adds r0, r7, r2
	ldrb r0, [r0]
	mov r3, r9
	strb r0, [r3]
	ldr r0, =0x0000050e
	adds r1, r7, r0
	ldr r4, =gUnknown_0203CCDC
	movs r6, 0x5
_08185D1C:
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, 0x2
	adds r4, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _08185D1C
	mov r1, r10
	ldr r2, [r1]
	ldr r3, =0x000004fc
	adds r0, r7, r3
	ldrb r0, [r0]
	ldr r1, =0x00000ca9
	adds r2, r1
	movs r1, 0x3
	ands r1, r0
	ldrb r3, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r6, 0
	ldr r2, =0x00000297
	mov r10, r2
	ldr r3, =gUnknown_0203BD34
	mov r9, r3
	movs r0, 0xA6
	lsls r0, 2
	mov r8, r0
	ldr r1, =0x0000051c
	adds r5, r7, r1
_08185D5C:
	adds r2, r6, 0x1
	mov r0, r8
	muls r0, r6
	adds r1, r0, r5
	mov r3, r9
	adds r4, r0, r3
	mov r3, r10
	adds r3, 0x1
_08185D6C:
	ldrb r0, [r1]
	strb r0, [r4]
	adds r1, 0x1
	adds r4, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _08185D6C
	adds r6, r2, 0
	cmp r6, 0x3
	ble _08185D5C
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185B60

	thumb_func_start sub_8185E24
sub_8185E24: @ 8185E24
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0xF8
	lsls r0, 4
	bl AllocZeroed
	adds r4, r0, 0
	bl start_ov_to_battle_anim
	cmp r0, 0x1
	bne _08185E6E
	bl sub_8185EB8
	adds r0, r4, 0
	bl sub_8185B60
	ldr r0, =sub_8185B1C
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x80
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_0203C7B0
	str r5, [r0]
	movs r0, 0
	bl PlayMapChosenOrBattleBGM
	ldr r0, =sub_8185E8C
	bl SetMainCallback2
_08185E6E:
	adds r0, r4, 0
	bl Free
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185E24

	thumb_func_start sub_8185E8C
sub_8185E8C: @ 8185E8C
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTasks
	pop {r0}
	bx r0
	thumb_func_end sub_8185E8C

	thumb_func_start sub_8185EA0
sub_8185EA0: @ 8185EA0
	ldr r0, =gUnknown_0203C7AE
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8185EA0

	thumb_func_start sub_8185EAC
sub_8185EAC: @ 8185EAC
	ldr r0, =gUnknown_0203C7AF
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8185EAC

	thumb_func_start sub_8185EB8
sub_8185EB8: @ 8185EB8
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_0203C7C0
_08185EBE:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	adds r0, r4, r6
	ldr r1, =gPlayerParty
	adds r1, r4, r1
	movs r2, 0x64
	bl memcpy
	ldr r0, =gUnknown_0203CA18
	adds r0, r4, r0
	ldr r1, =gEnemyParty
	adds r4, r1
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x1
	cmp r5, 0x5
	ble _08185EBE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185EB8

	thumb_func_start sub_8185EFC
sub_8185EFC: @ 8185EFC
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gPlayerParty
_08185F02:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	adds r0, r4, r6
	ldr r1, =gUnknown_0203C7C0
	adds r1, r4, r1
	movs r2, 0x64
	bl memcpy
	ldr r0, =gEnemyParty
	adds r0, r4, r0
	ldr r1, =gUnknown_0203CA18
	adds r4, r1
	adds r1, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x1
	cmp r5, 0x5
	ble _08185F02
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185EFC

	thumb_func_start sub_8185F40
sub_8185F40: @ 8185F40
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, =gLinkPlayers
	ldr r3, =gActiveBank
	ldrh r1, [r0, 0x18]
	adds r4, r0, 0
	ldrb r0, [r3]
	cmp r1, r0
	beq _08185F64
	adds r1, r4, 0
_08185F54:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08185F64
	ldrh r0, [r1, 0x18]
	ldrb r5, [r3]
	cmp r0, r5
	bne _08185F54
_08185F64:
	cmp r2, 0x4
	bne _08185F74
	movs r0, 0
	b _08185F7E
	.pool
_08185F74:
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x13]
_08185F7E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8185F40

	thumb_func_start sub_8185F84
sub_8185F84: @ 8185F84
	ldr r1, =gUnknown_0203C7B5
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8185F84

	thumb_func_start sub_8185F90
sub_8185F90: @ 8185F90
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gUnknown_0203C7B5
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	lsls r0, 16
	lsrs r0, 31
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8185F90

	thumb_func_start sub_8185FAC
sub_8185FAC: @ 8185FAC
	ldr r0, =gUnknown_0203C7B5
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8185FAC

	thumb_func_start sub_8185FB8
sub_8185FB8: @ 8185FB8
	ldr r0, =gUnknown_0203C7B6
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8185FB8

	thumb_func_start sub_8185FC4
sub_8185FC4: @ 8185FC4
	ldr r0, =gUnknown_0203C7B7
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8185FC4

	thumb_func_start sub_8185FD0
sub_8185FD0: @ 8185FD0
	push {r4-r7,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0818601C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _0818601C
	ldr r0, =gUnknown_0203C7AC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0818601C
	movs r3, 0
	ldr r7, =gUnknown_0203CC70
	adds r6, r4, 0
	ldr r5, =gBattleMons + 0xC
	movs r4, 0x58
_08186000:
	lsls r2, r3, 1
	ldrb r1, [r6]
	lsrs r0, r1, 1
	lsls r0, 3
	adds r0, r2, r0
	adds r0, r7
	muls r1, r4
	adds r2, r1
	adds r2, r5
	ldrh r1, [r2]
	strh r1, [r0]
	adds r3, 0x1
	cmp r3, 0x3
	ble _08186000
_0818601C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8185FD0

	thumb_func_start sub_818603C
sub_818603C: @ 818603C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0818605C
	b _081863FC
_0818605C:
	movs r0, 0
	mov r10, r0
	b _081863F2
	.pool
_0818606C:
	mov r1, r10
	lsls r4, r1, 24
	lsrs r5, r4, 24
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp, 0x4C]
	mov r2, r10
	adds r2, 0x1
	str r2, [sp, 0x38]
	cmp r0, 0x1
	bne _0818608A
	b _081863EE
_0818608A:
	ldr r3, [sp, 0x24]
	cmp r3, 0x1
	bne _0818611E
	movs r5, 0
	ldr r4, =gUnknown_0203CC70
	mov r0, r10
	asrs r6, r0, 31
	subs r0, r6
	asrs r0, 1
	lsls r0, 3
	adds r2, r0, r4
	movs r1, 0x58
	mov r0, r10
	muls r0, r1
	ldr r3, =gBattleMons + 0xC
	adds r1, r0, r3
_081860AA:
	ldrh r0, [r1]
	ldrh r4, [r2]
	cmp r0, r4
	bne _081860BC
	adds r2, 0x2
	adds r1, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _081860AA
_081860BC:
	cmp r5, 0x4
	bne _081860C2
	b _081863EE
_081860C2:
	ldr r1, [sp, 0x4C]
	lsrs r0, r1, 24
	movs r1, 0x6
	bl RecordedBattle_SetBankAction
	movs r5, 0
	ldr r2, =gUnknown_0203CC70
	mov r8, r2
	movs r3, 0x58
	mov r7, r10
	muls r7, r3
	mov r4, r10
	subs r0, r4, r6
	asrs r4, r0, 1
_081860DE:
	movs r2, 0
	lsls r0, r5, 1
	adds r5, 0x1
	adds r0, r7
	ldr r1, =gBattleMons + 0xC
	adds r3, r0, r1
	lsls r0, r4, 3
	mov r6, r8
	adds r1, r0, r6
_081860F0:
	ldrh r0, [r3]
	ldrh r6, [r1]
	cmp r0, r6
	bne _08186110
	lsls r1, r2, 24
	lsrs r1, 24
	ldr r2, [sp, 0x4C]
	lsrs r0, r2, 24
	bl RecordedBattle_SetBankAction
	b _08186118
	.pool
_08186110:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	ble _081860F0
_08186118:
	cmp r5, 0x3
	ble _081860DE
	b _081863EE
_0818611E:
	ldr r3, =gUnknown_0203BD34
	ldr r1, =gUnknown_0203C794
	mov r4, r10
	lsls r2, r4, 1
	adds r1, r2, r1
	movs r0, 0xA6
	lsls r0, 2
	mov r6, r10
	muls r6, r0
	adds r0, r6, 0
	ldrh r1, [r1]
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	str r2, [sp, 0x44]
	cmp r0, 0x6
	beq _08186142
	b _081863EE
_08186142:
	adds r0, r5, 0
	bl sub_8185054
	movs r5, 0
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x28]
	mov r1, sp
	adds r1, 0xC
	str r1, [sp, 0x30]
	mov r2, sp
	adds r2, 0x14
	str r2, [sp, 0x34]
	mov r3, sp
	adds r3, 0x18
	str r3, [sp, 0x3C]
	mov r4, sp
	adds r4, 0x8
	str r4, [sp, 0x2C]
	mov r6, r10
	lsls r6, 3
	str r6, [sp, 0x48]
	movs r1, 0x58
	mov r0, r10
	muls r0, r1
	ldr r2, =gBattleMons
	adds r0, r2
	adds r6, r0, 0
	adds r6, 0x3B
	movs r4, 0x3
_0818617E:
	mov r0, sp
	adds r3, r0, r5
	ldrb r1, [r6]
	lsls r2, r5, 1
	adds r0, r4, 0
	lsls r0, r2
	ands r1, r0
	asrs r1, r2
	strb r1, [r3]
	adds r5, 0x1
	cmp r5, 0x3
	ble _0818617E
	movs r5, 0
	ldr r1, =gBattleMons
	mov r9, r1
	movs r2, 0x58
	mov r7, r10
	muls r7, r2
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x30]
_081861A6:
	ldr r3, [sp, 0x4C]
	lsrs r0, r3, 24
	bl sub_8185054
	strb r0, [r4]
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	movs r1, 0xC
	add r1, r9
	mov r8, r1
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6]
	ldr r2, [sp, 0x34]
	adds r1, r2, r5
	ldrb r0, [r4]
	adds r0, r7
	ldr r3, =gBattleMons + 0x24
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x3C]
	adds r1, r0, r5
	ldrb r0, [r4]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [sp, 0x2C]
	adds r3, r1, r5
	ldr r2, [sp, 0x48]
	mov r1, r10
	subs r0, r2, r1
	lsls r0, 2
	ldr r2, =gDisableStructs
	adds r0, r2
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	lsrs r1, r5
	strb r1, [r3]
	adds r4, 0x1
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _081861A6
	movs r5, 0
	movs r3, 0xC
	negs r3, r3
	add r3, r8
	mov r12, r3
	ldr r4, =gDisableStructs
	mov r9, r4
	movs r6, 0x58
	mov r1, r10
	muls r1, r6
	mov r0, r8
	adds r0, 0x18
	adds r4, r1, r0
	adds r3, r1, 0
	mov r7, r8
	ldr r6, [sp, 0x34]
	ldr r2, [sp, 0x30]
_0818622C:
	adds r1, r3, r7
	ldrh r0, [r2]
	strh r0, [r1]
	adds r0, r6, r5
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0818622C
	movs r0, 0x58
	mov r4, r10
	muls r4, r0
	mov r1, r12
	adds r0, r4, r1
	adds r0, 0x3B
	movs r1, 0
	strb r1, [r0]
	ldr r2, [sp, 0x48]
	mov r6, r10
	subs r3, r2, r6
	lsls r3, 2
	mov r0, r9
	adds r2, r3, r0
	ldrb r1, [r2, 0x18]
	movs r0, 0xF
	ands r0, r1
	strb r0, [r2, 0x18]
	movs r5, 0
	ldr r1, =gBattleMons
	adds r4, r1
	adds r4, 0x3B
	ldr r0, =gDisableStructs
	adds r6, r3, r0
_08186274:
	ldr r2, [sp, 0x3C]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r1, r5, 1
	lsls r0, r1
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	ldrb r2, [r6, 0x18]
	lsrs r3, r2, 4
	ldr r1, [sp, 0x2C]
	adds r0, r1, r5
	ldrb r1, [r0]
	lsls r1, r5
	orrs r1, r3
	lsls r1, 4
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x18]
	adds r5, 0x1
	cmp r5, 0x3
	ble _08186274
	movs r2, 0x58
	mov r0, r10
	muls r0, r2
	mov r1, r12
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	beq _081862BC
	b _081863CA
_081862BC:
	movs r5, 0
	mov r3, sp
	adds r3, 0x20
	str r3, [sp, 0x40]
	ldr r0, =gBattlePartyID
	ldr r4, [sp, 0x44]
	adds r6, r4, r0
_081862CA:
	ldrh r1, [r6]
	movs r0, 0x64
	muls r0, r1
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	mov r1, sp
	adds r3, r1, r5
	lsls r2, r5, 1
	movs r1, 0x3
	lsls r1, r2
	ands r0, r1
	lsrs r0, r2
	strb r0, [r3]
	adds r5, 0x1
	cmp r5, 0x3
	ble _081862CA
	movs r5, 0
	ldr r0, =gBattlePartyID
	ldr r2, [sp, 0x44]
	adds r7, r2, r0
	movs r3, 0x64
	mov r9, r3
	mov r8, r4
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x30]
_08186304:
	ldrh r0, [r7]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	ldrb r1, [r4]
	adds r1, 0xD
	movs r2, 0
	bl GetMonData
	strh r0, [r6]
	ldrh r0, [r7]
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	add r0, r8
	ldrb r1, [r4]
	adds r1, 0x11
	movs r2, 0
	bl GetMonData
	ldr r3, [sp, 0x34]
	adds r1, r3, r5
	strb r0, [r1]
	ldr r0, [sp, 0x3C]
	adds r1, r0, r5
	ldrb r0, [r4]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r1]
	adds r4, 0x1
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _08186304
	movs r5, 0
	ldr r0, =gBattlePartyID
	ldr r1, [sp, 0x44]
	adds r7, r1, r0
	movs r2, 0x64
	mov r9, r2
	ldr r3, =gPlayerParty
	mov r8, r3
	ldr r6, [sp, 0x30]
	adds r6, 0x8
	ldr r4, [sp, 0x30]
_08186360:
	ldrh r0, [r7]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	adds r1, r5, 0
	adds r1, 0xD
	adds r2, r4, 0
	bl SetMonData
	ldrh r0, [r7]
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	add r0, r8
	adds r1, r5, 0
	adds r1, 0x11
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _08186360
	movs r0, 0
	ldr r3, [sp, 0x40]
	strb r0, [r3]
	movs r5, 0
	ldr r4, =gBattlePartyID
	ldr r6, =gPlayerParty
	ldr r3, [sp, 0x3C]
	ldr r2, [sp, 0x40]
_081863A2:
	adds r0, r3, r5
	ldrb r1, [r0]
	lsls r0, r5, 1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r5, 0x1
	cmp r5, 0x3
	ble _081863A2
	ldr r1, [sp, 0x44]
	adds r0, r1, r4
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	adds r0, r6
	movs r1, 0x15
	ldr r2, [sp, 0x40]
	bl SetMonData
_081863CA:
	ldr r2, =gChosenMovesByBanks
	ldr r3, [sp, 0x44]
	adds r2, r3, r2
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	add r0, r10
	adds r0, 0x80
	ldrb r0, [r0]
	lsls r0, 1
	movs r4, 0x58
	mov r1, r10
	muls r1, r4
	adds r0, r1
	ldr r1, =gBattleMons
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
_081863EE:
	ldr r6, [sp, 0x38]
	mov r10, r6
_081863F2:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r10, r0
	bge _081863FC
	b _0818606C
_081863FC:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818603C

	thumb_func_start GetAiScriptsInRecordedBattle
GetAiScriptsInRecordedBattle: @ 8186438
	ldr r0, =gUnknown_0203C7BC
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end GetAiScriptsInRecordedBattle

	thumb_func_start sub_8186444
sub_8186444: @ 8186444
	ldr r1, =gUnknown_0203CCD0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8186444

	thumb_func_start rfu_lacks_rfufunc
rfu_lacks_rfufunc: @ 8186450
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_0203CCD0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0818645E
	movs r1, 0x1
_0818645E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end rfu_lacks_rfufunc

	thumb_func_start sub_8186468
sub_8186468: @ 8186468
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r5, =gUnknown_03001278
	ldr r4, =gUnknown_0203CCD1
_08186472:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08186472
	movs r0, 0xFF
	strb r0, [r3, 0x7]
	ldrb r1, [r5]
	adds r0, r3, 0
	bl ConvertInternationalString
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186468

	thumb_func_start sub_818649C
sub_818649C: @ 818649C
	ldr r0, =gUnknown_0203CCD9
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_818649C

	thumb_func_start sub_81864A8
sub_81864A8: @ 81864A8
	ldr r0, =gUnknown_0203CCDA
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864A8

	thumb_func_start sub_81864B4
sub_81864B4: @ 81864B4
	ldr r0, =gUnknown_03001278
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864B4

	thumb_func_start sub_81864C0
sub_81864C0: @ 81864C0
	ldr r0, =gUnknown_03001279
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864C0

	thumb_func_start sub_81864CC
sub_81864CC: @ 81864CC
	ldr r0, =gUnknown_0203CCE8
	ldr r1, =gBattleOutcome
	ldrb r1, [r1]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864CC

	thumb_func_start sub_81864E0
sub_81864E0: @ 81864E0
	ldr r0, =gUnknown_0203CCDC
	bx lr
	.pool
	thumb_func_end sub_81864E0

	.align 2, 0 @ Don't pad with nop.
