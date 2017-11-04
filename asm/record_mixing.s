	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E6E24
sub_80E6E24: @ 80E6E24
	push {r4,r5,lr}
	bl sub_80E9914
	bl sub_80F0BB8
	bl sub_80E6BF8
	bl sub_800A064
	cmp r0, 0
	beq _080E6E60
	bl sub_800A03C
	cmp r0, 0
	bne _080E6E50
	ldr r0, =gUnknown_0203A018
	ldr r0, [r0]
	bl sub_80E6CA0
	b _080E6F12
	.pool
_080E6E50:
	ldr r0, =gUnknown_0203A018
	ldr r0, [r0]
	bl sub_80E6D54
	b _080E6F12
	.pool
_080E6E60:
	ldr r5, =gUnknown_0203A018
	ldr r0, [r5]
	ldr r1, =gUnknown_03001134
	ldr r1, [r1]
	movs r4, 0xC8
	lsls r4, 4
	adds r2, r4, 0
	bl memcpy
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gUnknown_03001138
	ldr r1, [r1]
	movs r2, 0xE1
	lsls r2, 2
	bl memcpy
	ldr r0, [r5]
	ldr r1, =0x00001004
	adds r0, r1
	ldr r1, =gUnknown_0300113C
	ldr r1, [r1]
	movs r2, 0x40
	bl memcpy
	ldr r0, [r5]
	ldr r2, =0x00001044
	adds r0, r2
	ldr r1, =gUnknown_03001140
	ldr r1, [r1]
	movs r2, 0x40
	bl memcpy
	ldr r0, [r5]
	ldr r1, =0x00001214
	adds r0, r1
	ldr r1, =gUnknown_03001150
	ldr r1, [r1]
	movs r2, 0x40
	bl memcpy
	ldr r0, [r5]
	ldr r2, =0x00001084
	adds r0, r2
	ldr r1, =gUnknown_03001144
	ldr r1, [r1]
	movs r2, 0x28
	bl memcpy
	ldr r0, [r5]
	ldr r1, =0x000010ac
	adds r0, r1
	bl sub_80E89F8
	ldr r0, [r5]
	ldr r4, =0x00001124
	adds r0, r4
	ldr r1, =gUnknown_0300114C
	ldr r1, [r1]
	movs r2, 0xEC
	bl memcpy
	ldr r0, [r5]
	adds r0, r4
	bl sub_80E8AC0
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _080E6EFA
	bl sub_81539D4
	ldr r1, [r5]
	ldr r2, =0x00001210
	adds r1, r2
	strh r0, [r1]
_080E6EFA:
	ldr r0, [r5]
	ldr r1, =0x00001254
	adds r0, r1
	ldr r1, =gUnknown_03001154
	ldr r1, [r1]
	bl sub_80E8110
	ldr r0, [r5]
	ldr r2, =0x000012dc
	adds r0, r2
	bl sub_80E8260
_080E6F12:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E6E24

	thumb_func_start sub_80E6F60
sub_80E6F60: @ 80E6F60
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	bl sub_800A064
	cmp r0, 0
	beq _080E7014
	ldr r5, =gUnknown_0203A014
	ldr r0, [r5]
	movs r1, 0xC8
	lsls r1, 4
	mov r8, r1
	add r0, r8
	bl sub_80E7B2C
	ldr r0, [r5]
	ldr r6, =0x00001230
	lsls r4, 24
	lsrs r4, 24
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80EAF80
	ldr r3, [r5]
	ldr r1, =0x000010ac
	adds r0, r3, r1
	add r3, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E7B60
	ldr r0, [r5]
	ldr r1, =0x00001124
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E7948
	ldr r0, [r5]
	add r0, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80F01E8
	ldr r0, [r5]
	ldr r1, =0x00001004
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80F0C7C
	ldr r0, [r5]
	ldr r1, =0x00001044
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E78C4
	ldr r0, [r5]
	ldr r1, =0x00001084
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_812287C
	ldr r0, [r5]
	ldr r1, =0x000011c8
	adds r0, r1
	adds r1, r4, 0
	bl sub_80E7F68
	b _080E70BE
	.pool
_080E7014:
	ldr r5, =gUnknown_0203A014
	ldr r0, [r5]
	movs r1, 0xC8
	lsls r1, 4
	mov r8, r1
	add r0, r8
	bl sub_80E7B2C
	ldr r0, [r5]
	ldr r6, =0x00001444
	lsls r4, 24
	lsrs r4, 24
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80EAF80
	ldr r0, [r5]
	add r0, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80F01E8
	ldr r0, [r5]
	ldr r1, =0x00001004
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80F0C7C
	ldr r0, [r5]
	ldr r1, =0x00001044
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E78C4
	ldr r0, [r5]
	ldr r1, =0x00001084
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_812287C
	ldr r3, [r5]
	ldr r1, =0x000010ac
	adds r0, r3, r1
	add r3, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E7B60
	ldr r0, [r5]
	ldr r1, =0x00001124
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E7948
	ldr r0, [r5]
	ldr r1, =0x00001210
	adds r0, r1
	adds r1, r4, 0
	bl sub_80E7F68
	ldr r0, [r5]
	ldr r1, =0x00001214
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E7A14
	ldr r0, [r5]
	ldr r1, =0x00001254
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E8468
	ldr r0, [r5]
	ldr r1, =0x000012dc
	adds r0, r1
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80E89AC
_080E70BE:
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E6F60

	thumb_func_start sub_80E70F4
sub_80E70F4: @ 80E70F4
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80E70F4

	thumb_func_start sub_80E7128
sub_80E7128: @ 80E7128
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	bne _080E7150
	movs r0, 0xE2
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x8]
_080E7150:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7128

	thumb_func_start sub_80E715C
sub_80E715C: @ 80E715C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x5
	bls _080E7176
	b _080E730A
_080E7176:
	lsls r0, 2
	ldr r1, =_080E7188
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E7188:
	.4byte _080E71A0
	.4byte _080E7218
	.4byte _080E724C
	.4byte _080E726C
	.4byte _080E72AC
	.4byte _080E72C0
_080E71A0:
	ldr r4, =gUnknown_0203A018
	ldr r0, =0x00001444
	bl Alloc
	str r0, [r4]
	ldr r4, =gUnknown_0203A014
	ldr r0, =0x00005110
	bl Alloc
	str r0, [r4]
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
	bl sub_8009628
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0x1
	bl VarSet
	ldr r1, =gUnknown_03001130
	movs r0, 0
	strb r0, [r1]
	bl sub_80E6E24
	bl sub_80FB00C
	movs r0, 0x1
	strh r0, [r5]
	ldr r0, =sub_80E7324
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldr r0, =sub_80E7128
	movs r1, 0x51
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1E]
	b _080E730A
	.pool
_080E7218:
	ldr r2, =gTasks
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _080E730A
	movs r0, 0x2
	strh r0, [r5]
	ldr r0, =0x00000894
	bl FlagSet
	bl sub_80FB074
	ldrb r0, [r5, 0x1E]
	bl DestroyTask
	b _080E730A
	.pool
_080E724C:
	ldr r0, =sub_80E7FF8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	movs r0, 0x3
	strh r0, [r5]
	movs r0, 0xE0
	bl PlaySE
	b _080E730A
	.pool
_080E726C:
	ldr r2, =gTasks
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r4, [r0, 0x4]
	cmp r4, 0
	bne _080E730A
	movs r0, 0x4
	strh r0, [r5]
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E7296
	bl sub_80B3050
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
_080E7296:
	ldr r0, =gText_RecordMixingComplete
	bl sub_80E70F4
	strh r4, [r5, 0x10]
	b _080E730A
	.pool
_080E72AC:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _080E730A
	movs r0, 0x5
	strh r0, [r5]
	b _080E730A
_080E72C0:
	ldr r2, =gTasks
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _080E730A
	ldr r0, =gUnknown_0203A014
	ldr r0, [r0]
	bl Free
	ldr r0, =gUnknown_0203A018
	ldr r0, [r0]
	bl Free
	bl sub_808729C
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E72F8
	ldr r0, =sub_80AF2B4
	movs r1, 0xA
	bl CreateTask
_080E72F8:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_080E730A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E715C

	thumb_func_start sub_80E7324
sub_80E7324: @ 80E7324
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r6, =gTasks
	adds r5, r0, r6
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0x64
	beq _080E73A0
	cmp r1, 0x64
	bgt _080E7362
	cmp r1, 0x1
	bne _080E7346
	b _080E7464
_080E7346:
	cmp r1, 0x1
	bgt _080E7354
	cmp r1, 0
	beq _080E7384
	b _080E7566
	.pool
_080E7354:
	cmp r1, 0x2
	bne _080E735A
	b _080E7490
_080E735A:
	cmp r1, 0x5
	bne _080E7360
	b _080E7550
_080E7360:
	b _080E7566
_080E7362:
	cmp r1, 0xC9
	beq _080E73F8
	cmp r1, 0xC9
	bgt _080E7370
	cmp r1, 0x65
	beq _080E73B8
	b _080E7566
_080E7370:
	ldr r0, =0x0000012d
	cmp r1, r0
	beq _080E7432
	adds r0, 0x63
	cmp r1, r0
	beq _080E744A
	b _080E7566
	.pool
_080E7384:
	ldr r0, =gText_MixingRecords
	bl sub_80E70F4
	movs r0, 0xE1
	lsls r0, 3
	strh r0, [r5, 0x18]
	movs r0, 0xC8
	lsls r0, 1
	strh r0, [r5, 0x8]
	bl sub_8009FAC
	b _080E7566
	.pool
_080E73A0:
	ldrh r0, [r5, 0x20]
	adds r0, 0x1
	strh r0, [r5, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bgt _080E73B0
	b _080E7566
_080E73B0:
	movs r0, 0
	strh r0, [r5, 0x20]
	movs r0, 0x65
	b _080E7564
_080E73B8:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800ABBC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E73EA
	bl sub_800AA48
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _080E73DA
	b _080E7566
_080E73DA:
	movs r0, 0x15
	bl PlaySE
	movs r1, 0
	movs r0, 0xC9
	strh r0, [r5, 0x8]
	strh r1, [r5, 0x20]
	b _080E7566
_080E73EA:
	movs r0, 0x16
	bl PlaySE
	ldr r0, =0x0000012d
	b _080E7564
	.pool
_080E73F8:
	bl sub_800AA48
	adds r4, r0, 0
	bl sub_800ABAC
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080E740C
	b _080E7566
_080E740C:
	ldrh r4, [r5, 0x20]
	adds r4, 0x1
	strh r4, [r5, 0x20]
	lsls r4, 16
	asrs r4, 16
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	cmp r4, r1
	bgt _080E742A
	b _080E7566
_080E742A:
	bl sub_800A620
	movs r0, 0x1
	b _080E7564
_080E7432:
	bl sub_800AA48
	adds r4, r0, 0
	bl sub_800ABAC
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080E7446
	b _080E7566
_080E7446:
	movs r0, 0x1
	b _080E7564
_080E744A:
	ldrh r0, [r5, 0x20]
	adds r0, 0x1
	strh r0, [r5, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bgt _080E745A
	b _080E7566
_080E745A:
	movs r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	strh r0, [r5, 0x20]
	b _080E7566
_080E7464:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E746E
	b _080E7566
_080E746E:
	ldr r4, =gStringVar1
	bl sub_80E7810
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0x5
	b _080E7564
	.pool
_080E7490:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r5, 0x14]
	strh r1, [r5, 0x8]
	bl sub_80E7810
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	ldr r0, =sub_80E756C
	str r0, [r5]
	bl sub_800A064
	cmp r0, 0
	beq _080E7504
	ldr r0, =gUnknown_0203A018
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0xC
	bl sub_80E7808
	ldr r0, =sub_80E7630
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1C]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r0, r1, r6
	strh r4, [r0, 0x8]
	ldr r0, =gUnknown_0203A014
	ldr r0, [r0]
	adds r1, r6, r1
	adds r1, 0x12
	bl sub_80E7808
	ldr r1, =gUnknown_0300115C
	ldr r0, =0x00001230
	str r0, [r1]
	b _080E7566
	.pool
_080E7504:
	ldr r0, =gUnknown_0203A018
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0xC
	bl sub_80E7808
	ldr r0, =sub_80E7630
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1C]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r0, r1, r6
	strh r4, [r0, 0x8]
	ldr r0, =gUnknown_0203A014
	ldr r0, [r0]
	adds r1, r6, r1
	adds r1, 0x12
	bl sub_80E7808
	ldr r1, =gUnknown_0300115C
	ldr r0, =0x00001444
	str r0, [r1]
	b _080E7566
	.pool
_080E7550:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _080E7566
	movs r0, 0
	strh r0, [r5, 0x1C]
	movs r0, 0x2
_080E7564:
	strh r0, [r5, 0x8]
_080E7566:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E7324

	thumb_func_start sub_80E756C
sub_80E756C: @ 80E756C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _080E7624
	lsls r0, r1, 2
	ldr r1, =_080E7598
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E7598:
	.4byte _080E75AC
	.4byte _080E75D0
	.4byte _080E7624
	.4byte _080E75E2
	.4byte _080E760E
_080E75AC:
	adds r0, r5, 0
	adds r0, 0xC
	bl sub_80E77FC
	adds r1, r0, 0
	movs r0, 0x10
	ldrsh r2, [r5, r0]
	movs r0, 0xC8
	muls r0, r2
	adds r1, r0
	ldr r0, =gUnknown_020228C4
	movs r2, 0xC8
	bl memcpy
	b _080E75FC
	.pool
_080E75D0:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _080E75FC
	movs r0, 0x1
	bl sub_800A4D8
	b _080E75FC
_080E75E2:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	movs r1, 0x10
	ldrsh r4, [r5, r1]
	ldr r0, =gUnknown_0300115C
	ldr r0, [r0]
	movs r1, 0xC8
	bl __udivsi3
	adds r0, 0x1
	cmp r4, r0
	bne _080E7608
_080E75FC:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _080E7624
	.pool
_080E7608:
	movs r0, 0
	strh r0, [r5, 0x8]
	b _080E7624
_080E760E:
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _080E7624
	ldr r0, =sub_80E77D4
	str r0, [r5]
_080E7624:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E756C

	thumb_func_start sub_80E7630
sub_80E7630: @ 80E7630
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	mov r10, r0
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	bl sub_800A9D8
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [sp, 0x4]
	cmp r3, r0
	bne _080E773E
	movs r4, 0
	mov r8, r4
	b _080E771C
	.pool
_080E7678:
	ldr r1, [sp, 0x4]
	mov r0, r8
	asrs r1, r0
	movs r0, 0x1
	ands r1, r0
	movs r2, 0x1
	add r2, r8
	mov r9, r2
	cmp r1, 0
	beq _080E7714
	mov r0, r10
	adds r0, 0x12
	bl sub_80E77FC
	mov r3, r9
	lsls r4, r3, 1
	mov r5, r10
	adds r5, 0x8
	adds r4, r5, r4
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r7, 0xC8
	muls r1, r7
	adds r0, r1
	ldr r3, =gUnknown_0300115C
	ldr r1, [r3]
	mov r2, r8
	muls r2, r1
	adds r1, r2, 0
	adds r6, r0, r1
	mov r0, r8
	bl sub_80E7820
	adds r1, r0, 0
	movs r3, 0
	ldrsh r2, [r4, r3]
	adds r0, r2, 0x1
	muls r0, r7
	ldr r4, =gUnknown_0300115C
	ldr r3, [r4]
	cmp r0, r3
	bls _080E76DC
	muls r2, r7
	subs r2, r3, r2
	adds r0, r6, 0
	bl memcpy
	b _080E76E4
	.pool
_080E76DC:
	adds r0, r6, 0
	movs r2, 0xC8
	bl memcpy
_080E76E4:
	mov r0, r8
	bl ResetBlockReceivedFlag
	mov r0, r9
	lsls r1, r0, 1
	adds r1, r5, r1
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r2, 0
	ldrsh r4, [r1, r2]
	ldr r3, =gUnknown_0300115C
	ldr r0, [r3]
	movs r1, 0xC8
	bl __udivsi3
	adds r0, 0x1
	cmp r4, r0
	bne _080E7714
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
_080E7714:
	mov r4, r9
	lsls r0, r4, 24
	lsrs r0, 24
	mov r8, r0
_080E771C:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r8, r0
	bcc _080E7678
	ldr r2, =gTasks
	mov r0, r10
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
_080E773E:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bne _080E7752
	ldr r0, [sp]
	bl DestroyTask
_080E7752:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7630

	thumb_func_start sub_80E776C
sub_80E776C: @ 80E776C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	movs r4, 0x1C
	ldrsh r1, [r0, r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _080E7794
	adds r0, r3, 0
	bl DestroyTask
_080E7794:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E776C

	thumb_func_start sub_80E77A0
sub_80E77A0: @ 80E77A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r0, =sub_80E776C
	str r0, [r1]
	ldr r0, =gUnknown_03001130
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080E77C4
	movs r2, 0x12
	ldrsh r0, [r1, r2]
	bl sub_80E6F60
_080E77C4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E77A0

	thumb_func_start sub_80E77D4
sub_80E77D4: @ 80E77D4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_80E77A0
	str r0, [r1]
	ldr r1, =gUnknown_03001130
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80E77D4

	thumb_func_start sub_80E77FC
sub_80E77FC: @ 80E77FC
	adds r1, r0, 0
	ldrh r0, [r1]
	ldrh r1, [r1, 0x2]
	lsls r1, 16
	orrs r0, r1
	bx lr
	thumb_func_end sub_80E77FC

	thumb_func_start sub_80E7808
sub_80E7808: @ 80E7808
	strh r0, [r1]
	lsrs r0, 16
	strh r0, [r1, 0x2]
	bx lr
	thumb_func_end sub_80E7808

	thumb_func_start sub_80E7810
sub_80E7810: @ 80E7810
	push {lr}
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80E7810

	thumb_func_start sub_80E7820
sub_80E7820: @ 80E7820
	lsls r0, 24
	lsrs r0, 16
	ldr r1, =gBlockRecvBuffer
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_80E7820

	thumb_func_start sub_80E7830
sub_80E7830: @ 80E7830
	push {r4,lr}
	adds r4, r0, 0
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _080E7868
	cmp r0, 0x3
	bhi _080E784A
	cmp r0, 0x2
	beq _080E7850
	b _080E78B8
_080E784A:
	cmp r0, 0x4
	beq _080E7894
	b _080E78B8
_080E7850:
	movs r3, 0
	ldr r2, =gUnknown_0858CF8C
	adds r1, r4, 0
_080E7856:
	adds r0, r3, r2
	ldrb r0, [r0]
	stm r1!, {r0}
	adds r3, 0x1
	cmp r3, 0x1
	bls _080E7856
	b _080E78B8
	.pool
_080E7868:
	movs r0, 0
	bl GetLinkPlayerTrainerId
	adds r2, r0, 0
	movs r0, 0x1
	ands r2, r0
	movs r3, 0
	ldr r1, =gUnknown_0858CF8E
	lsls r0, r2, 1
	adds r0, r2
	adds r1, r0, r1
	adds r2, r4, 0
_080E7880:
	ldrb r0, [r1]
	stm r2!, {r0}
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x2
	bls _080E7880
	b _080E78B8
	.pool
_080E7894:
	movs r0, 0
	bl GetLinkPlayerTrainerId
	movs r1, 0x9
	bl __umodsi3
	adds r2, r0, 0
	movs r3, 0
	ldr r1, =gUnknown_0858CF94
	lsls r0, r2, 2
	adds r1, r0, r1
	adds r2, r4, 0
_080E78AC:
	ldrb r0, [r1]
	stm r2!, {r0}
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x3
	bls _080E78AC
_080E78B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7830

	thumb_func_start sub_80E78C4
sub_80E78C4: @ 80E78C4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r9, r0
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	mov r0, sp
	bl sub_80E7830
	lsls r0, r7, 2
	add r0, sp
	ldr r1, [r0]
	mov r0, r8
	muls r0, r1
	mov r2, r9
	adds r6, r2, r0
	ldr r2, =gLinkPlayers
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r4, [r0]
	ldrh r5, [r0, 0x1A]
	bl sub_800A064
	cmp r0, 0
	beq _080E7910
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8120D34
	b _080E791A
	.pool
_080E7910:
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8120CD0
_080E791A:
	ldr r0, =gUnknown_03001140
	ldr r0, [r0]
	lsls r1, r7, 2
	add r1, sp
	ldr r1, [r1]
	mov r2, r8
	muls r2, r1
	adds r1, r2, 0
	add r1, r9
	movs r2, 0x40
	bl memcpy
	bl sub_8120670
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E78C4

	thumb_func_start sub_80E7948
sub_80E7948: @ 80E7948
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	mov r0, sp
	bl sub_80E7830
	bl sub_800A064
	cmp r0, 0
	beq _080E79AC
	lsls r0, r6, 2
	mov r1, sp
	adds r5, r1, r0
	ldr r0, [r5]
	muls r0, r7
	add r0, r8
	adds r4, r7, 0
	muls r4, r6
	mov r1, r8
	adds r6, r1, r4
	adds r1, r6, 0
	bl sub_816587C
	mov r9, r4
	cmp r0, 0x1
	bne _080E79FE
	adds r7, r6, 0
	ldr r2, =gLinkPlayers
	ldr r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x1A]
	adds r0, r7, 0
	adds r0, 0xE4
	strb r1, [r0]
	adds r0, r7, 0
	bl sub_8164F70
	b _080E79FE
	.pool
_080E79AC:
	adds r5, r7, 0
	muls r5, r6
	mov r0, r8
	adds r4, r0, r5
	lsls r0, r6, 2
	add r0, sp
	ldr r0, [r0]
	adds r1, r7, 0
	muls r1, r0
	add r1, r8
	adds r0, r4, 0
	movs r2, 0xEC
	bl memcpy
	adds r7, r4, 0
	movs r6, 0
	mov r9, r5
_080E79CE:
	movs r0, 0x2C
	muls r0, r6
	adds r0, 0x34
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080E79F2
	adds r4, r1, 0
	adds r4, 0x20
	adds r0, r4, 0
	bl IsStringJapanese
	cmp r0, 0
	beq _080E79F2
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
_080E79F2:
	adds r6, 0x1
	cmp r6, 0x3
	ble _080E79CE
	adds r0, r7, 0
	bl sub_8164F70
_080E79FE:
	mov r0, r8
	add r0, r9
	bl sub_81628A0
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E7948

	thumb_func_start sub_80E7A14
sub_80E7A14: @ 80E7A14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r5, r2, 24
	mov r0, sp
	bl sub_80E7830
	adds r0, r7, 0
	muls r0, r5
	add r0, r8
	ldr r6, =gUnknown_03001150
	ldr r1, [r6]
	movs r2, 0x40
	bl memcpy
	bl GetLilycoveLadyId
	lsls r0, 24
	cmp r0, 0
	bne _080E7A60
	movs r0, 0x40
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq _080E7A8A
	ldr r1, [r6]
	movs r2, 0x40
	bl memcpy
	b _080E7A62
	.pool
_080E7A60:
	movs r4, 0
_080E7A62:
	ldr r0, =gUnknown_03001150
	ldr r0, [r0]
	lsls r1, r5, 2
	add r1, sp
	ldr r1, [r1]
	muls r1, r7
	add r1, r8
	movs r2, 0x40
	bl memcpy
	bl sub_818DA78
	cmp r4, 0
	beq _080E7A8A
	adds r0, r4, 0
	bl sub_818E570
	adds r0, r4, 0
	bl Free
_080E7A8A:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7A14

	thumb_func_start sub_80E7A9C
sub_80E7A9C: @ 80E7A9C
	ldrh r0, [r0, 0x20]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	thumb_func_end sub_80E7A9C

	thumb_func_start sub_80E7AA4
sub_80E7AA4: @ 80E7AA4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x38
	mov r8, r0
	mov r10, r1
	mov r9, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x54]
	lsls r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsrs r4, 23
	add r4, r9
	ldrb r0, [r4]
	mov r6, r10
	muls r6, r0
	add r6, r8
	ldrb r0, [r4, 0x1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 3
	adds r1, r6, r1
	mov r0, sp
	movs r2, 0x38
	bl memcpy
	lsls r5, 1
	add r5, r9
	ldrb r0, [r5]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r8, r0
	ldrb r1, [r4, 0x1]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 3
	adds r6, r0
	ldrb r0, [r5, 0x1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 3
	add r1, r8
	adds r0, r6, 0
	movs r2, 0x38
	bl memcpy
	ldrb r1, [r5, 0x1]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 3
	add r8, r0
	mov r0, r8
	mov r1, sp
	movs r2, 0x38
	bl memcpy
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E7AA4

	thumb_func_start sub_80E7B2C
sub_80E7B2C: @ 80E7B2C
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	movs r1, 0
	ldr r4, =gUnknown_03001160
_080E7B36:
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, r2, r0
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, 0x1
	cmp r1, 0xFF
	ble _080E7B36
	strb r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7B2C

	thumb_func_start sub_80E7B54
sub_80E7B54: @ 80E7B54
	ldr r0, =gUnknown_03001160
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80E7B54

	thumb_func_start sub_80E7B60
sub_80E7B60: @ 80E7B60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0x2C]
	str r1, [sp, 0x30]
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x38]
	ldr r0, =gLinkPlayers
	ldrh r0, [r0, 0x4]
	bl SeedRng2
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	mov r8, r0
	mov r1, sp
	adds r1, 0x1C
	str r1, [sp, 0x4C]
	mov r2, sp
	adds r2, 0x1D
	str r2, [sp, 0x50]
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x48]
	movs r7, 0xFF
	add r3, sp, 0x8
	movs r2, 0
	adds r6, r1, 0
	ldr r5, [sp, 0x50]
_080E7BB0:
	mov r1, sp
	add r1, r8
	adds r1, 0x4
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
	mov r1, r8
	adds r0, r3, r1
	strb r2, [r0]
	lsls r1, 1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, r5, r1
	strb r2, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x3
	bls _080E7BB0
	bl sub_800A064
	str r0, [sp, 0x3C]
	movs r2, 0
	mov r8, r2
	lsls r4, 16
	str r4, [sp, 0x54]
	ldr r0, [sp, 0x30]
	mov r3, r9
	muls r3, r0
	str r3, [sp, 0x44]
	b _080E7D04
	.pool
_080E7BF8:
	ldr r1, [sp, 0x30]
	mov r0, r8
	muls r0, r1
	ldr r2, [sp, 0x2C]
	adds r7, r2, r0
	ldr r1, =gLinkPlayers
	mov r3, r8
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x1A]
	mov r9, r1
	ldrb r0, [r0]
	str r0, [sp, 0x40]
	movs r6, 0
	ldr r0, [r7, 0x70]
	cmp r6, r0
	bcs _080E7CFA
	movs r2, 0x10
	negs r2, r2
	mov r10, r2
_080E7C24:
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 3
	adds r5, r7, r0
	ldrh r0, [r5, 0x20]
	cmp r0, 0
	beq _080E7CEE
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	beq _080E7C9A
	adds r4, r5, 0
	adds r4, 0x24
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080E7C54
	movs r4, 0x1
	b _080E7C5C
	.pool
_080E7C54:
	adds r0, r4, 0
	bl StripExtCtrlCodes
	mov r4, r9
_080E7C5C:
	ldrh r1, [r5, 0x2C]
	ldr r0, =0x000015fc
	cmp r1, r0
	bne _080E7C74
	adds r0, r5, 0
	adds r0, 0x2C
	bl StripExtCtrlCodes
	movs r1, 0x1
	b _080E7C76
	.pool
_080E7C74:
	mov r1, r9
_080E7C76:
	ldr r0, [sp, 0x40]
	subs r0, 0x1
	cmp r0, 0x1
	bhi _080E7CEE
	adds r2, r5, 0
	adds r2, 0x37
	movs r0, 0xF
	ands r4, r0
	ldrb r0, [r2]
	mov r3, r10
	ands r0, r3
	orrs r0, r4
	lsls r1, 4
	movs r3, 0xF
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	b _080E7CEE
_080E7C9A:
	mov r0, r9
	cmp r0, 0x1
	bne _080E7CEE
	adds r0, r5, 0
	adds r0, 0x24
	bl IsStringJapanese
	cmp r0, 0
	beq _080E7CBA
	adds r0, r5, 0
	adds r0, 0x37
	ldrb r1, [r0]
	mov r2, r10
	ands r1, r2
	movs r2, 0x1
	b _080E7CC6
_080E7CBA:
	adds r0, r5, 0
	adds r0, 0x37
	ldrb r1, [r0]
	mov r3, r10
	ands r1, r3
	movs r2, 0x2
_080E7CC6:
	orrs r1, r2
	strb r1, [r0]
	adds r4, r0, 0
	adds r0, r5, 0
	adds r0, 0x2C
	bl IsStringJapanese
	cmp r0, 0
	beq _080E7CE2
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x10
	b _080E7CEA
_080E7CE2:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x20
_080E7CEA:
	orrs r1, r0
	strb r1, [r4]
_080E7CEE:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r7, 0x70]
	cmp r6, r0
	bcc _080E7C24
_080E7CFA:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_080E7D04:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r8, r0
	bcs _080E7D12
	b _080E7BF8
_080E7D12:
	movs r0, 0
	str r0, [sp, 0x34]
	mov r8, r0
	ldr r1, [sp, 0x54]
	lsrs r0, r1, 16
	ldr r2, [sp, 0x34]
	cmp r2, r0
	bcs _080E7D70
	adds r5, r0, 0
_080E7D24:
	ldr r3, [sp, 0x30]
	mov r0, r8
	muls r0, r3
	ldr r1, [sp, 0x2C]
	adds r7, r1, r0
	ldr r0, [r7, 0x70]
	cmp r0, 0
	beq _080E7D62
	movs r6, 0
	cmp r6, r0
	bcs _080E7D62
	adds r3, r7, 0
	adds r3, 0x74
	ldr r2, [sp, 0x4C]
	mov r0, r8
	lsls r1, r0, 1
	movs r4, 0x1
_080E7D46:
	lsls r0, r6, 1
	adds r0, r3, r0
	ldrh r0, [r0]
	cmp r0, 0
	bne _080E7D56
	adds r0, r6, r1
	adds r0, r2, r0
	strb r4, [r0]
_080E7D56:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r7, 0x70]
	cmp r6, r0
	bcc _080E7D46
_080E7D62:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r8, r5
	bcc _080E7D24
_080E7D70:
	movs r6, 0
	mov r8, r6
	ldr r1, [sp, 0x54]
	cmp r1, 0
	beq _080E7E64
	add r2, sp, 0x24
	mov r10, r2
	movs r3, 0x25
	add r3, sp
	mov r9, r3
_080E7D84:
	ldr r1, [sp, 0x30]
	mov r0, r8
	muls r0, r1
	ldr r2, [sp, 0x2C]
	adds r7, r2, r0
	mov r3, r8
	lsls r1, r3, 1
	ldr r2, [sp, 0x4C]
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080E7DA6
	ldr r3, [sp, 0x50]
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080E7DB0
_080E7DA6:
	ldr r0, [sp, 0x34]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x34]
_080E7DB0:
	ldr r2, [sp, 0x4C]
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080E7DD4
	ldr r3, [sp, 0x50]
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0
	bne _080E7DD4
_080E7DC4:
	lsls r1, r6, 1
	mov r3, r10
	adds r0, r3, r1
	mov r3, r8
	strb r3, [r0]
	add r1, r9
	strb r2, [r1]
	b _080E7E4E
_080E7DD4:
	ldr r2, [sp, 0x4C]
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E7DE8
	ldr r3, [sp, 0x50]
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _080E7DC4
_080E7DE8:
	ldr r2, [sp, 0x4C]
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080E7E54
	ldr r3, [sp, 0x50]
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080E7E54
	lsls r5, r6, 1
	mov r1, r10
	adds r0, r1, r5
	mov r2, r8
	strb r2, [r0]
	adds r0, r7, 0
	bl sub_80E7A9C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	adds r0, 0x38
	bl sub_80E7A9C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	bne _080E7E30
	cmp r1, 0
	beq _080E7E34
	mov r3, r9
	adds r1, r3, r5
	movs r0, 0x1
	strb r0, [r1]
	b _080E7E4E
_080E7E30:
	cmp r1, 0
	beq _080E7E48
_080E7E34:
	bl Random2
	mov r1, r9
	adds r2, r1, r5
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	strb r0, [r2]
	b _080E7E4E
_080E7E48:
	mov r2, r9
	adds r0, r2, r5
	strb r1, [r0]
_080E7E4E:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080E7E54:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	mov r8, r3
	ldr r1, [sp, 0x54]
	cmp r0, r1
	bcc _080E7D84
_080E7E64:
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0x44]
	lsls r0, r3, 4
	subs r0, r3
	lsls r0, 3
	ldr r1, [sp, 0x2C]
	adds r7, r1, r0
	ldr r1, [sp, 0x48]
_080E7E76:
	mov r2, r8
	lsls r0, r2, 2
	adds r0, r1, r0
	str r7, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x3
	bls _080E7E76
	bl sub_80E7B54
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, [sp, 0x34]
	cmp r3, 0x3
	beq _080E7EC8
	cmp r3, 0x3
	bgt _080E7EAE
	cmp r3, 0x2
	beq _080E7EB6
	b _080E7F1C
_080E7EAE:
	ldr r0, [sp, 0x34]
	cmp r0, 0x4
	beq _080E7EE8
	b _080E7F1C
_080E7EB6:
	add r2, sp, 0x24
	movs r0, 0x1
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	movs r3, 0
	bl sub_80E7AA4
	b _080E7F1C
_080E7EC8:
	ldr r0, =gUnknown_0858CFB8
	lsls r1, 1
	adds r2, r1, r0
	ldrb r3, [r2]
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	add r2, sp, 0x24
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	bl sub_80E7AA4
	b _080E7F1C
	.pool
_080E7EE8:
	add r6, sp, 0x24
	ldr r4, =gUnknown_0858CFBE
	lsls r5, r1, 2
	adds r0, r5, r4
	ldrb r3, [r0]
	adds r0, r4, 0x1
	adds r0, r5, r0
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	adds r2, r6, 0
	bl sub_80E7AA4
	adds r0, r4, 0x2
	adds r0, r5, r0
	ldrb r3, [r0]
	adds r4, 0x3
	adds r5, r4
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	adds r2, r6, 0
	bl sub_80E7AA4
_080E7F1C:
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x44]
	adds r7, r1, r2
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r3, 0xC2
	lsls r3, 6
	adds r0, r3
	adds r1, r7, 0
	movs r2, 0x38
	bl memcpy
	ldr r0, [r4]
	ldr r1, =0x0000310c
	adds r0, r1
	adds r1, r7, 0
	adds r1, 0x38
	movs r2, 0x38
	bl memcpy
	ldr r0, [sp, 0x38]
	bl SeedRng
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7B60

	thumb_func_start sub_80E7F68
sub_80E7F68: @ 80E7F68
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	cmp r1, 0
	beq _080E7FEC
	ldrh r0, [r4]
	cmp r0, 0
	beq _080E7FEC
	bl GetPocketByItemId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _080E7FEC
	ldrh r0, [r4]
	movs r1, 0x1
	bl CheckBagHasItem
	lsls r0, 24
	cmp r0, 0
	bne _080E7FE4
	ldrh r0, [r4]
	movs r1, 0x1
	bl CheckPCHasItem
	lsls r0, 24
	cmp r0, 0
	bne _080E7FE4
	ldrh r0, [r4]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	beq _080E7FE4
	ldr r0, =0x00004001
	ldrh r1, [r4]
	bl VarSet
	ldr r0, =gStringVar1
	ldr r1, =gLinkPlayers + 8
	bl StringCopy
	ldrh r1, [r4]
	ldr r0, =0x00000113
	cmp r1, r0
	bne _080E7FEC
	ldr r0, =0x000008b3
	bl FlagSet
	b _080E7FEC
	.pool
_080E7FE4:
	ldr r0, =0x00004001
	movs r1, 0
	bl VarSet
_080E7FEC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E7F68

	thumb_func_start sub_80E7FF8
sub_80E7FF8: @ 80E7FF8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bls _080E8012
	b _080E810A
_080E8012:
	lsls r0, 2
	ldr r1, =_080E8024
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E8024:
	.4byte _080E80F2
	.4byte _080E804C
	.4byte _080E805A
	.4byte _080E8064
	.4byte _080E807C
	.4byte _080E8090
	.4byte _080E80A4
	.4byte _080E80C0
	.4byte _080E80EE
	.4byte _080E80FA
_080E804C:
	bl sub_800A064
	cmp r0, 0
	bne _080E80F2
	movs r0, 0x6
	strh r0, [r4, 0x8]
	b _080E810A
_080E805A:
	bl sub_8076D5C
	bl sub_8153430
	b _080E80F2
_080E8064:
	bl sub_8153474
	lsls r0, 24
	cmp r0, 0
	beq _080E810A
	bl sav2_gender2_inplace_and_xFE
	movs r1, 0
	movs r0, 0x4
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	b _080E810A
_080E807C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	ble _080E810A
	bl sub_800AC34
	b _080E80F2
_080E8090:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E810A
	adds r0, r5, 0
	bl DestroyTask
	b _080E810A
	.pool
_080E80A4:
	movs r0, 0
	bl sub_801048C
	lsls r0, 24
	cmp r0, 0
	bne _080E810A
	ldr r0, =sub_8153688
	movs r1, 0x5
	bl CreateTask
	b _080E80F2
	.pool
_080E80C0:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080E810A
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E80E8
	movs r0, 0x1
	bl sub_801048C
	movs r0, 0x8
	strh r0, [r4, 0x8]
	b _080E810A
	.pool
_080E80E8:
	movs r0, 0x4
	strh r0, [r4, 0x8]
	b _080E810A
_080E80EE:
	bl sub_800ADF8
_080E80F2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080E810A
_080E80FA:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080E810A
	adds r0, r5, 0
	bl DestroyTask
_080E810A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80E7FF8

	thumb_func_start sub_80E8110
sub_80E8110: @ 80E8110
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp]
	mov r10, r1
	adds r1, r0, 0
	adds r1, 0x38
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [sp]
	adds r1, 0x7C
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	ldr r0, [sp]
	mov r1, r10
	movs r2, 0x44
	bl memcpy
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	movs r2, 0
	str r2, [sp, 0x4]
	mov r8, r2
	movs r7, 0
	ldr r0, =gSaveBlock2Ptr
	mov r9, r0
_080E8150:
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	adds r0, r7, r0
	movs r1, 0x3
	bl __modsi3
	adds r6, r0, 0x1
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	mov r2, r10
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x38
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080E81B8
	adds r5, r1, 0
	adds r5, 0x34
	adds r0, r5, 0
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	bl ReadUnalignedWord
	cmp r4, r0
	beq _080E819A
	movs r2, 0x1
	add r8, r2
	str r6, [sp, 0x4]
_080E819A:
	adds r0, r5, 0
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	bl ReadUnalignedWord
	cmp r4, r0
	bne _080E81B8
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	str r6, [sp, 0x8]
_080E81B8:
	adds r7, 0x1
	cmp r7, 0x1
	ble _080E8150
	mov r0, r8
	cmp r0, 0
	bne _080E81D0
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _080E81D0
	mov r8, r1
	ldr r2, [sp, 0x8]
	str r2, [sp, 0x4]
_080E81D0:
	mov r0, r8
	cmp r0, 0x1
	beq _080E81E0
	cmp r0, 0x2
	beq _080E81EC
	b _080E824C
	.pool
_080E81E0:
	ldr r2, [sp, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r10
	b _080E820E
_080E81EC:
	bl Random2
	lsls r0, 16
	ldr r1, =0x33330000
	cmp r0, r1
	bls _080E8224
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r10
	adds r1, 0x44
_080E820E:
	ldr r0, [sp]
	adds r0, 0x44
	movs r2, 0x44
	bl memcpy
	b _080E824C
	.pool
_080E8224:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	adds r0, 0x1
	movs r1, 0x3
	bl __modsi3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r10
	adds r1, 0x44
	ldr r0, [sp]
	adds r0, 0x44
	movs r2, 0x44
	bl memcpy
_080E824C:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8110

	thumb_func_start sub_80E8260
sub_80E8260: @ 80E8260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	movs r6, 0
	ldr r0, =gSaveBlock2Ptr
	mov r10, r0
_080E8274:
	movs r7, 0
	lsls r0, r6, 5
	adds r6, 0x1
	mov r9, r6
	mov r1, r8
	adds r4, r0, r1
	adds r0, 0x6
	adds r6, r1, r0
	adds r5, r4, 0
_080E8286:
	mov r2, r10
	ldr r1, [r2]
	adds r1, 0xA
	adds r0, r5, 0
	bl CopyUnalignedWord
	movs r0, 0x2
	strb r0, [r4, 0xE]
	mov r0, r10
	ldr r1, [r0]
	adds r0, r6, 0
	bl StringCopy
	adds r4, 0x10
	adds r6, 0x10
	adds r5, 0x10
	adds r7, 0x1
	cmp r7, 0x1
	ble _080E8286
	mov r6, r9
	cmp r6, 0x8
	ble _080E8274
	ldr r1, =gSaveBlock2Ptr
	mov r10, r1
	ldr r2, =0x00000ee1
	str r2, [sp, 0x4]
	movs r4, 0x99
	lsls r4, 1
	add r4, r8
	movs r0, 0x95
	lsls r0, 1
	add r0, r8
	mov r9, r0
	ldr r1, =0x00000ef1
	str r1, [sp, 0x8]
	movs r6, 0x92
	lsls r6, 1
	add r6, r8
	movs r5, 0x90
	lsls r5, 1
	add r5, r8
	movs r7, 0x1
_080E82DA:
	movs r0, 0x2
	strb r0, [r4, 0x8]
	mov r2, r10
	ldr r1, [r2]
	adds r1, 0xA
	adds r0, r5, 0
	bl CopyUnalignedWord
	mov r0, r10
	ldr r1, [r0]
	ldr r2, [sp, 0x8]
	adds r1, r2
	adds r0, r6, 0
	bl CopyUnalignedWord
	mov r0, r10
	ldr r1, [r0]
	mov r0, r9
	bl StringCopy
	mov r2, r10
	ldr r1, [r2]
	ldr r0, [sp, 0x4]
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, [sp, 0x4]
	adds r1, 0x8
	str r1, [sp, 0x4]
	adds r4, 0x1C
	movs r2, 0x1C
	add r9, r2
	ldr r0, [sp, 0x8]
	adds r0, 0x4
	str r0, [sp, 0x8]
	adds r6, 0x1C
	adds r5, 0x1C
	subs r7, 0x1
	cmp r7, 0
	bge _080E82DA
	movs r6, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	mov r4, r8
	movs r1, 0xC4
	adds r1, r4
	mov r9, r1
	movs r2, 0x84
	adds r2, r4
	mov r8, r2
	movs r0, 0x44
	adds r0, r4
	mov r12, r0
	adds r7, r4, 0x4
	movs r1, 0xCF
	lsls r1, 4
	adds r1, r3, r1
	str r1, [sp]
	mov r10, r4
	ldr r2, =0x00000cf4
	adds r5, r3, r2
_080E8356:
	lsls r2, r6, 1
	ldr r1, [sp]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r0, [r5]
	strh r0, [r7, 0x20]
	ldrh r0, [r5, 0x4]
	mov r1, r12
	strh r0, [r1]
	ldr r1, =0x00000d14
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x20]
	movs r1, 0xDD
	lsls r1, 4
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r1, =0x00000dde
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1, 0x20]
	ldr r1, =0x00000dea
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r9
	strh r0, [r1]
	ldr r1, =0x00000e08
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r9
	strh r0, [r1, 0x20]
	ldr r1, =0x00000e1e
	adds r0, r3, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x82
	lsls r0, 1
	add r0, r10
	strh r1, [r0]
	ldr r1, =0x00000cfc
	adds r0, r3, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r4, r2
	strh r1, [r0]
	adds r4, 0x1C
	movs r0, 0x10
	add r9, r0
	add r8, r0
	add r12, r0
	adds r7, 0x10
	ldr r1, [sp]
	adds r1, 0x2
	str r1, [sp]
	add r10, r0
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x1
	ble _080E8356
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8260

	thumb_func_start sub_80E841C
sub_80E841C: @ 80E841C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	adds r6, r1, 0
	adds r6, 0x34
	adds r5, r1, 0
_080E842E:
	adds r0, r7, 0
	adds r0, 0x34
	bl ReadUnalignedWord
	adds r4, r0, 0
	adds r0, r6, 0
	bl ReadUnalignedWord
	cmp r4, r0
	bne _080E844E
	ldrb r0, [r7, 0x2]
	ldrb r1, [r5, 0x2]
	cmp r0, r1
	bne _080E844E
	movs r0, 0x1
	b _080E845E
_080E844E:
	adds r6, 0x44
	adds r5, 0x44
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	ble _080E842E
	movs r0, 0
_080E845E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80E841C

	thumb_func_start sub_80E8468
sub_80E8468: @ 80E8468
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r0, sp
	bl sub_80E7830
	lsls r4, 2
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	muls r0, r5
	adds r3, r6, r0
	movs r7, 0
	movs r2, 0
	mov r8, r2
	movs r5, 0
	adds r6, r3, 0
	adds r6, 0x38
	adds r4, r3, 0
_080E8496:
	ldrb r0, [r6]
	cmp r0, 0xFF
	beq _080E84B4
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0xDC
	adds r0, r4, 0
	str r3, [sp, 0x10]
	bl sub_80E841C
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bne _080E84B4
	adds r7, 0x1
	mov r8, r5
_080E84B4:
	adds r6, 0x44
	adds r4, 0x44
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E8496
	cmp r7, 0x1
	beq _080E84CC
	cmp r7, 0x2
	beq _080E8508
	b _080E8566
	.pool
_080E84CC:
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xB2
	ldrb r1, [r1]
	lsls r1, 27
	lsrs r1, 30
	adds r2, r1, 0x1
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r0, r1
	adds r0, 0xDC
	mov r2, r8
	lsls r1, r2, 4
	add r1, r8
	lsls r1, 2
	adds r1, r3
	movs r2, 0x44
	bl memcpy
	ldr r4, [r4]
	adds r4, 0xB2
	ldrb r5, [r4]
	lsls r0, r5, 27
	lsrs r0, 30
	adds r0, 0x1
	b _080E8550
	.pool
_080E8508:
	movs r5, 0
	adds r6, r3, 0
_080E850C:
	movs r0, 0x1
	eors r0, r5
	ldr r7, =gSaveBlock2Ptr
	ldr r4, [r7]
	adds r1, r4, 0
	adds r1, 0xB2
	ldrb r1, [r1]
	lsls r1, 27
	lsrs r1, 30
	adds r0, r1
	movs r1, 0x3
	bl __modsi3
	adds r2, r0, 0x1
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0
	adds r4, 0xDC
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x44
	bl memcpy
	adds r6, 0x44
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E850C
	ldr r4, [r7]
	adds r4, 0xB2
	ldrb r5, [r4]
	lsls r0, r5, 27
	lsrs r0, 30
	adds r0, 0x2
_080E8550:
	movs r1, 0x3
	bl __modsi3
	movs r1, 0x3
	ands r0, r1
	lsls r0, 3
	movs r1, 0x19
	negs r1, r1
	ands r1, r5
	orrs r1, r0
	strb r1, [r4]
_080E8566:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8468

	thumb_func_start sub_80E8578
sub_80E8578: @ 80E8578
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x54
	str r0, [sp]
	ldr r0, [sp, 0x74]
	movs r4, 0
	mov r8, r4
	movs r5, 0
	str r5, [sp, 0x4]
	ldr r4, =gUnknown_03001168
	b _080E85A0
	.pool
_080E8598:
	adds r1, r2
	ldr r6, [sp, 0x4]
	adds r6, 0x1
	str r6, [sp, 0x4]
_080E85A0:
	ldr r5, [sp, 0x4]
	cmp r5, r0
	bge _080E85B6
	cmp r5, r3
	beq _080E85B0
	stm r4!, {r1}
	movs r6, 0x1
	add r8, r6
_080E85B0:
	mov r5, r8
	cmp r5, 0x3
	bne _080E8598
_080E85B6:
	movs r6, 0
	str r6, [sp, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x24]
_080E85BE:
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r1, [sp, 0x4]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r2, [sp, 0x4]
	lsls r2, 1
	str r2, [sp, 0x34]
	ldr r3, [sp, 0x4]
	adds r3, r2, r3
	str r3, [sp, 0x10]
	movs r4, 0
	str r4, [sp, 0x44]
	movs r5, 0
	str r5, [sp, 0x48]
_080E85DC:
	movs r6, 0
	mov r8, r6
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, [sp, 0x10]
	lsls r0, r2, 5
	ldr r3, [sp, 0x48]
	adds r0, r3, r0
	adds r3, r0, r1
	lsls r0, r2, 6
	ldr r4, [sp, 0x44]
	adds r0, r4, r0
	ldr r5, [sp]
	adds r2, r0, r5
_080E85F8:
	adds r0, r2, 0
	movs r6, 0x87
	lsls r6, 2
	adds r1, r3, r6
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
	adds r3, 0x10
	adds r2, 0x10
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x2
	ble _080E85F8
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0x24]
	cmp r8, r3
	bge _080E86DC
	ldr r4, [sp, 0x4]
	lsls r4, 5
	mov r9, r4
	ldr r5, [sp, 0x8]
	lsls r7, r5, 4
	ldr r6, [sp, 0x34]
	ldr r1, [sp, 0x4]
	adds r0, r6, r1
	lsls r0, 6
	str r0, [sp, 0x14]
	ldr r2, [sp]
	adds r0, r2, r0
	ldr r3, [sp, 0x44]
	str r3, [sp, 0x18]
	adds r0, r3
	str r0, [sp, 0x1C]
	ldr r4, [sp, 0x14]
	adds r0, r3, r4
	adds r0, r2
	adds r0, 0x30
	mov r10, r0
_080E864A:
	movs r5, 0
	str r5, [sp, 0xC]
	movs r3, 0
	mov r6, r8
	lsls r6, 2
	str r6, [sp, 0x38]
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x14]
	adds r0, r1, r2
	ldr r4, [sp]
	adds r5, r0, r4
	ldr r0, =gUnknown_03001168
	adds r0, r6, r0
	str r0, [sp, 0x50]
_080E8666:
	lsls r0, r3, 4
	ldr r6, [sp, 0x1C]
	adds r0, r6, r0
	str r3, [sp, 0x4C]
	bl ReadUnalignedWord
	adds r4, r0, 0
	ldr r1, [sp, 0x50]
	ldr r0, [r1]
	add r0, r9
	adds r0, r7
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E86A8
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	ldr r4, [sp, 0x50]
	ldr r0, [r4]
	mov r6, r9
	adds r1, r7, r6
	adds r1, r0, r1
	ldrh r0, [r5, 0x4]
	ldrh r2, [r1, 0x4]
	cmp r0, r2
	bcs _080E86A8
	adds r0, r5, 0
	ldm r1!, {r2,r4,r6}
	stm r0!, {r2,r4,r6}
	ldr r1, [r1]
	str r1, [r0]
_080E86A8:
	adds r5, 0x10
	adds r3, 0x1
	cmp r3, 0x2
	ble _080E8666
	ldr r3, [sp, 0xC]
	cmp r3, 0
	bne _080E86CE
	ldr r0, =gUnknown_03001168
	ldr r4, [sp, 0x38]
	adds r0, r4, r0
	ldr r0, [r0]
	mov r5, r9
	adds r2, r7, r5
	mov r1, r10
	adds r0, r2
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
_080E86CE:
	movs r4, 0x10
	add r10, r4
	movs r5, 0x1
	add r8, r5
	ldr r6, [sp, 0x24]
	cmp r8, r6
	blt _080E864A
_080E86DC:
	ldr r0, [sp, 0x44]
	adds r0, 0x60
	str r0, [sp, 0x44]
	ldr r1, [sp, 0x48]
	adds r1, 0x30
	str r1, [sp, 0x48]
	ldr r2, [sp, 0x8]
	adds r2, 0x1
	str r2, [sp, 0x8]
	cmp r2, 0x1
	bgt _080E86F4
	b _080E85DC
_080E86F4:
	ldr r3, [sp, 0x28]
	str r3, [sp, 0x4]
	cmp r3, 0x8
	bgt _080E86FE
	b _080E85BE
_080E86FE:
	movs r4, 0
	str r4, [sp, 0x8]
_080E8702:
	ldr r5, [sp, 0x8]
	adds r5, 0x1
	str r5, [sp, 0x2C]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r0, 0x54
	ldr r6, [sp, 0x8]
	muls r0, r6
	adds r3, r0, r1
	movs r0, 0xA8
	muls r0, r6
	ldr r1, [sp]
	adds r2, r0, r1
	movs r4, 0x2
	mov r8, r4
_080E8720:
	movs r5, 0xD8
	lsls r5, 3
	adds r0, r2, r5
	ldr r6, =0x0000057c
	adds r1, r3, r6
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
	adds r3, 0x1C
	adds r2, 0x1C
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080E8720
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0x24]
	cmp r8, r3
	blt _080E8752
	b _080E885A
_080E8752:
	ldr r4, [sp, 0x8]
	lsls r1, r4, 3
	movs r0, 0xA8
	adds r5, r4, 0
	muls r5, r0
	str r5, [sp, 0x20]
	str r5, [sp, 0x3C]
	subs r1, r4
	lsls r1, 2
	mov r10, r1
_080E8766:
	movs r6, 0
	str r6, [sp, 0xC]
	mov r0, r8
	lsls r0, 2
	str r0, [sp, 0x38]
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x30]
	ldr r0, =gUnknown_03001168
	ldr r2, [sp, 0x38]
	adds r2, r0
	mov r9, r2
	ldr r3, [sp]
	movs r4, 0xD8
	lsls r4, 3
	adds r0, r3, r4
	ldr r5, [sp, 0x3C]
	adds r7, r5, r0
	str r6, [sp, 0x40]
	movs r3, 0x2
_080E878E:
	ldr r1, [sp, 0x20]
	movs r2, 0xD8
	lsls r2, 3
	adds r0, r1, r2
	ldr r4, [sp]
	adds r0, r4, r0
	ldr r6, [sp, 0x40]
	adds r5, r0, r6
	adds r0, r5, 0
	str r3, [sp, 0x4C]
	bl ReadUnalignedWord
	adds r4, r0, 0
	movs r6, 0x90
	lsls r6, 1
	add r6, r10
	mov r1, r9
	ldr r0, [r1]
	adds r0, r6
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E8808
	adds r0, r5, 0x4
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r2, r9
	ldr r0, [r2]
	adds r0, r6
	adds r0, 0x4
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E8808
	ldr r4, [sp, 0xC]
	adds r4, 0x1
	str r4, [sp, 0xC]
	mov r5, r9
	ldr r0, [r5]
	mov r6, r10
	adds r2, r0, r6
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	ldrh r0, [r7, 0x8]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080E8808
	adds r0, r7, 0
	movs r4, 0x90
	lsls r4, 1
	adds r1, r2, r4
	ldm r1!, {r2,r5,r6}
	stm r0!, {r2,r5,r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
_080E8808:
	adds r7, 0x1C
	ldr r0, [sp, 0x40]
	adds r0, 0x1C
	str r0, [sp, 0x40]
	subs r3, 0x1
	cmp r3, 0
	bge _080E878E
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bne _080E8850
	mov r0, r8
	adds r0, 0x3
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r2, [sp, 0x20]
	adds r1, r2
	ldr r3, [sp]
	adds r1, r3, r1
	ldr r0, =gUnknown_03001168
	ldr r4, [sp, 0x38]
	adds r0, r4, r0
	ldr r0, [r0]
	add r0, r10
	movs r5, 0xD8
	lsls r5, 3
	adds r1, r5
	movs r6, 0x90
	lsls r6, 1
	adds r0, r6
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
_080E8850:
	ldr r3, [sp, 0x30]
	mov r8, r3
	ldr r4, [sp, 0x24]
	cmp r8, r4
	blt _080E8766
_080E885A:
	ldr r5, [sp, 0x2C]
	str r5, [sp, 0x8]
	cmp r5, 0x1
	bgt _080E8864
	b _080E8702
_080E8864:
	add sp, 0x54
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8578

	thumb_func_start sub_80E8880
sub_80E8880: @ 80E8880
	push {r4-r7,lr}
	mov r12, r0
	adds r7, r1, 0
	movs r5, 0
_080E8888:
	movs r2, 0
	movs r4, 0x1
	negs r4, r4
	movs r1, 0
	adds r6, r5, 0x1
	adds r3, r7, 0
_080E8894:
	ldrh r0, [r3, 0x4]
	cmp r0, r2
	ble _080E889E
	adds r4, r1, 0
	adds r2, r0, 0
_080E889E:
	adds r3, 0x10
	adds r1, 0x1
	cmp r1, 0x5
	ble _080E8894
	cmp r4, 0
	blt _080E88C0
	lsls r1, r5, 4
	lsls r2, r4, 4
	adds r2, r7
	add r1, r12
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	strh r0, [r2, 0x4]
_080E88C0:
	adds r5, r6, 0
	cmp r5, 0x2
	ble _080E8888
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8880

	thumb_func_start sub_80E88CC
sub_80E88CC: @ 80E88CC
	push {r4-r7,lr}
	mov r12, r0
	adds r6, r1, 0
	movs r5, 0
_080E88D4:
	movs r3, 0
	movs r4, 0x1
	negs r4, r4
	movs r2, 0
	adds r7, r5, 0x1
	adds r1, r6, 0
_080E88E0:
	ldrh r0, [r1, 0x8]
	cmp r0, r3
	ble _080E88EA
	adds r4, r2, 0
	adds r3, r0, 0
_080E88EA:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x5
	ble _080E88E0
	cmp r4, 0
	blt _080E8918
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	lsls r2, r4, 3
	subs r2, r4
	lsls r2, 2
	adds r2, r6
	add r1, r12
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	strh r0, [r2, 0x8]
_080E8918:
	adds r5, r7, 0
	cmp r5, 0x2
	ble _080E88D4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E88CC

	thumb_func_start sub_80E8924
sub_80E8924: @ 80E8924
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	movs r0, 0
	ldr r1, =gSaveBlock2Ptr
	mov r10, r1
_080E8936:
	lsls r1, r0, 1
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	lsls r0, r1, 5
	movs r2, 0x87
	lsls r2, 2
	adds r7, r0, r2
	lsls r1, 6
	mov r0, r9
	adds r4, r0, r1
	movs r6, 0
	movs r5, 0x1
_080E8950:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r7
	adds r0, r6
	adds r1, r4, 0
	bl sub_80E8880
	adds r4, 0x60
	adds r6, 0x30
	subs r5, 0x1
	cmp r5, 0
	bge _080E8950
	mov r0, r8
	cmp r0, 0x8
	ble _080E8936
	movs r5, 0
	ldr r4, =gSaveBlock2Ptr
_080E8972:
	movs r0, 0x54
	adds r1, r5, 0
	muls r1, r0
	ldr r2, =0x0000057c
	adds r1, r2
	ldr r0, [r4]
	adds r0, r1
	movs r1, 0xA8
	muls r1, r5
	movs r2, 0xD8
	lsls r2, 3
	adds r1, r2
	add r1, r9
	bl sub_80E88CC
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E8972
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8924

	thumb_func_start sub_80E89AC
sub_80E89AC: @ 80E89AC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	mov r9, r2
	bl GetLinkPlayerCount
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x81
	lsls r0, 4
	bl AllocZeroed
	adds r5, r0, 0
	str r4, [sp]
	adds r1, r6, 0
	mov r2, r8
	mov r3, r9
	bl sub_80E8578
	adds r0, r5, 0
	bl sub_80E8924
	adds r0, r5, 0
	bl Free
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E89AC

	thumb_func_start sub_80E89F8
sub_80E89F8: @ 80E89F8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, =gUnknown_02039F9C
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	movs r0, 0xC2
	lsls r0, 6
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0x38
	bl memcpy
	ldr r1, [r4]
	ldr r0, =0x0000310c
	adds r1, r0
	adds r0, r5, 0
	adds r0, 0x38
	movs r2, 0x38
	bl memcpy
	ldr r0, [r4]
	ldr r1, =0x00003030
	adds r0, r1
	adds r1, r5, 0
	bl sub_806FA9C
	ldr r0, =gUnknown_03001148
	ldr r1, [r0]
	adds r0, r6, 0
	movs r2, 0x78
	bl memcpy
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E89F8

	thumb_func_start sub_80E8A54
sub_80E8A54: @ 80E8A54
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r0, [r5, 0x70]
	cmp r9, r0
	bcs _080E8AAE
	adds r4, r5, 0
	adds r4, 0x2C
	movs r0, 0x24
	adds r0, r5
	mov r8, r0
	adds r7, r5, 0
	adds r7, 0x37
	adds r6, r5, 0
_080E8A78:
	ldrh r0, [r6, 0x20]
	cmp r0, 0
	beq _080E8A9A
	ldrb r1, [r4, 0xB]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	beq _080E8A90
	mov r0, r8
	movs r1, 0xFC
	bl sub_81DB4DC
_080E8A90:
	ldrb r1, [r7]
	lsrs r1, 4
	adds r0, r4, 0
	bl ConvertInternationalString
_080E8A9A:
	adds r4, 0x38
	movs r0, 0x38
	add r8, r0
	adds r7, 0x38
	adds r6, 0x38
	movs r0, 0x1
	add r9, r0
	ldr r0, [r5, 0x70]
	cmp r9, r0
	bcc _080E8A78
_080E8AAE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8A54

	thumb_func_start TaskDummy4
TaskDummy4: @ 80E8ABC
	bx lr
	thumb_func_end TaskDummy4

	thumb_func_start sub_80E8AC0
sub_80E8AC0: @ 80E8AC0
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_080E8AC6:
	movs r0, 0x2C
	muls r0, r4
	adds r0, 0x34
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080E8ADC
	adds r0, r1, 0
	adds r0, 0x20
	bl StripExtCtrlCodes
_080E8ADC:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E8AC6
	adds r0, r5, 0
	bl sub_8164F70
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8AC0

	.align 2, 0 @ Don't pad with nop.
