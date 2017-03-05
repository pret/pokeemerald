	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E8AF0
sub_80E8AF0: @ 80E8AF0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0
	str r0, [sp]
	ldr r2, =0x01000028
	mov r0, sp
	adds r1, r4, 0
	bl CpuFastSet
	movs r2, 0
	adds r4, 0x2
	movs r3, 0xFF
_080E8B0A:
	adds r0, r4, r2
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x6
	bls _080E8B0A
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8AF0

	thumb_func_start sub_80E8B28
sub_80E8B28: @ 80E8B28
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gSaveBlock1Ptr
_080E8B2E:
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 5
	ldr r0, =0x00001a9c
	adds r1, r0
	ldr r0, [r5]
	adds r0, r1
	bl sub_80E8AF0
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080E8B2E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8B28

	thumb_func_start sub_80E8B58
sub_80E8B58: @ 80E8B58
	ldr r0, =gUnknown_0203A01C
	ldr r1, =gUnknown_020375E0
	ldrh r1, [r1]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80E8B58

	thumb_func_start sub_80E8B6C
sub_80E8B6C: @ 80E8B6C
	push {r4,lr}
	ldr r0, =gUnknown_020375F0
	movs r1, 0
	strh r1, [r0]
	movs r3, 0
	adds r4, r0, 0
	b _080E8B86
	.pool
_080E8B80:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
_080E8B86:
	cmp r3, 0x13
	bhi _080E8BB0
	ldr r2, =gUnknown_0203A01C
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9c
	adds r1, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080E8B80
	movs r0, 0x1
	strh r0, [r4]
	ldr r0, =0x00004054
	adds r1, r3, 0
	bl VarSet
_080E8BB0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8B6C

	thumb_func_start sub_80E8BC8
sub_80E8BC8: @ 80E8BC8
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0
	beq _080E8BEC
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	strh r0, [r1]
	b _080E8BF0
	.pool
_080E8BEC:
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
_080E8BF0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8BC8

	thumb_func_start sub_80E8BF8
sub_80E8BF8: @ 80E8BF8
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	adds r1, r0, 0
	ldr r2, =0x00000fff
	adds r0, r2, 0
	ands r1, r0
	adds r0, r1, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080E8C34
	movs r0, 0x1
	b _080E8C8E
	.pool
_080E8C34:
	adds r0, r1, 0
	subs r0, 0x92
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080E8C44
	movs r0, 0x2
	b _080E8C8E
_080E8C44:
	adds r0, r1, 0
	subs r0, 0x9A
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080E8C54
	movs r0, 0x3
	b _080E8C8E
_080E8C54:
	adds r0, r1, 0
	subs r0, 0x94
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080E8C64
	movs r0, 0x4
	b _080E8C8E
_080E8C64:
	adds r0, r1, 0
	subs r0, 0x96
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080E8C78
	cmp r1, 0x9C
	beq _080E8C78
	cmp r1, 0x9D
	bne _080E8C7C
_080E8C78:
	movs r0, 0x5
	b _080E8C8E
_080E8C7C:
	adds r0, r1, 0
	subs r0, 0x98
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080E8C8C
	movs r0, 0
	b _080E8C8E
_080E8C8C:
	movs r0, 0x6
_080E8C8E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80E8BF8

	thumb_func_start sub_80E8C98
sub_80E8C98: @ 80E8C98
	push {r4,lr}
	ldr r4, =gUnknown_020375E6
	bl sub_80E8BF8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8C98

	thumb_func_start sub_80E8CB0
sub_80E8CB0: @ 80E8CB0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r2, 16
	lsrs r2, 16
	mov r10, r2
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0
	mov r12, r0
	mov r1, r8
	ldr r0, [r1, 0x4]
	cmp r12, r0
	bge _080E8D3C
	ldr r4, [r1]
_080E8CDA:
	movs r2, 0
	mov r0, r12
	lsls r7, r0, 16
	cmp r2, r4
	bge _080E8D28
	asrs r0, r7, 16
	adds r6, r0, 0
	muls r6, r4
	mov r1, r8
	ldr r5, [r1, 0xC]
	ldr r0, =0x000003ff
	mov r9, r0
_080E8CF2:
	lsls r0, r2, 16
	asrs r3, r0, 16
	adds r0, r6, r3
	lsls r0, 1
	adds r0, r5
	ldrh r1, [r0]
	mov r0, r9
	ands r0, r1
	cmp r0, r10
	bne _080E8D1C
	ldr r1, [sp]
	strh r2, [r1]
	mov r0, r12
	ldr r2, [sp, 0x4]
	strh r0, [r2]
	b _080E8D3C
	.pool
_080E8D1C:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, r4
	blt _080E8CF2
_080E8D28:
	movs r2, 0x80
	lsls r2, 9
	adds r1, r7, r2
	lsrs r0, r1, 16
	mov r12, r0
	asrs r1, 16
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r1, r0
	blt _080E8CDA
_080E8D3C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8CB0

	thumb_func_start sub_80E8D4C
sub_80E8D4C: @ 80E8D4C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	movs r5, 0
	mov r12, r4
	lsls r0, 16
	asrs r3, r0, 16
	ldr r1, =gUnknown_0858CFCC
	mov r8, r1
	adds r7, r0, 0
	mov r4, sp
	mov r6, r12
_080E8D80:
	ldr r0, =gUnknown_0858CFCC
	lsls r1, r5, 2
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, r3
	bne _080E8D9C
	movs r3, 0
	ldrsh r0, [r4, r3]
	movs r5, 0
	ldrsh r1, [r6, r5]
	ldrh r3, [r2, 0x2]
	b _080E8DC4
	.pool
_080E8D9C:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x6
	bls _080E8D80
	movs r5, 0
	mov r4, sp
	mov r6, r12
_080E8DAC:
	lsls r0, r5, 2
	mov r1, r8
	adds r3, r0, r1
	ldrh r1, [r3, 0x2]
	asrs r0, r7, 16
	cmp r1, r0
	bne _080E8DDE
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r5, 0
	ldrsh r1, [r6, r5]
	ldrh r3, [r3]
_080E8DC4:
	movs r5, 0xC0
	lsls r5, 4
	adds r2, r5, 0
	orrs r2, r3
	bl MapGridSetMetatileIdAt
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl CurrentMapDrawMetatileAt
	b _080E8DE8
_080E8DDE:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x6
	bls _080E8DAC
_080E8DE8:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8D4C

	thumb_func_start sub_80E8DF4
sub_80E8DF4: @ 80E8DF4
	push {lr}
	adds r2, r0, 0
	movs r1, 0
_080E8DFA:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080E8E06
	adds r0, r1, 0
	b _080E8E12
_080E8E06:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x6
	bls _080E8DFA
	movs r0, 0x7
_080E8E12:
	pop {r1}
	bx r1
	thumb_func_end sub_80E8DF4

	thumb_func_start sub_80E8E18
sub_80E8E18: @ 80E8E18
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =gUnknown_0203A01C
	ldrb r1, [r1]
	ldr r3, =0x00001a9c
	adds r0, r3
	strb r1, [r0]
	movs r3, 0
	ldr r5, =0x00001aa5
	ldr r4, =gSaveBlock2Ptr
_080E8E32:
	ldr r1, [r2]
	adds r1, r5
	adds r1, r3
	ldr r0, [r4]
	adds r0, 0xA
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _080E8E32
	ldr r0, =0x00004054
	movs r1, 0
	bl VarSet
	ldr r6, =gSaveBlock1Ptr
	ldr r4, [r6]
	ldr r0, =0x00001a9e
	adds r4, r0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	ldr r5, [r1]
	adds r0, r5, 0
	bl sub_80E8DF4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl StringCopyN
	ldr r3, [r6]
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	ldr r1, =0x00001a9d
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 4
	ldrb r2, [r3]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6]
	ldr r3, =0x00001aa9
	adds r0, r3
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, =0x00004026
	ldr r1, =gUnknown_02037318
	ldrb r1, [r1, 0x14]
	bl VarSet
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8E18

	thumb_func_start sub_80E8EE0
sub_80E8EE0: @ 80E8EE0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	movs r5, 0
	b _080E8F8A
_080E8EEE:
	mov r0, r8
	ldr r1, [r0, 0x10]
	lsls r2, r5, 1
	adds r0, r2, r5
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	adds r6, r1, 0
	adds r1, r5, 0x1
	mov r9, r1
	cmp r0, 0x8
	bne _080E8F82
	movs r4, 0
	ldr r7, =gSaveBlock1Ptr
_080E8F0A:
	ldr r1, [r7]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9c
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r2, r5
	lsls r0, 2
	adds r3, r0, r6
	ldr r0, [r3, 0x8]
	cmp r1, r0
	bne _080E8F78
	ldrh r5, [r3]
	adds r5, 0x7
	ldrh r4, [r3, 0x2]
	adds r4, 0x7
	lsls r5, 16
	asrs r0, r5, 16
	lsls r4, 16
	asrs r1, r4, 16
	bl MapGridGetMetatileIdAt
	movs r3, 0
	lsls r0, 16
	asrs r1, r0, 16
	ldr r6, =gUnknown_0858CFCC
_080E8F42:
	lsls r0, r3, 2
	adds r2, r0, r6
	ldrh r0, [r2]
	cmp r0, r1
	bne _080E8F6C
	ldrh r0, [r2, 0x2]
	movs r1, 0xC0
	lsls r1, 4
	adds r2, r1, 0
	orrs r2, r0
	asrs r0, r5, 16
	asrs r1, r4, 16
	bl MapGridSetMetatileIdAt
	b _080E8F82
	.pool
_080E8F6C:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x6
	bls _080E8F42
	b _080E8F82
_080E8F78:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080E8F0A
_080E8F82:
	mov r1, r9
	lsls r0, r1, 16
	lsrs r5, r0, 16
	mov r0, r8
_080E8F8A:
	ldrb r0, [r0, 0x3]
	cmp r5, r0
	bcc _080E8EEE
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8EE0

	thumb_func_start sub_80E8F9C
sub_80E8F9C: @ 80E8F9C
	push {lr}
	ldr r0, =gUnknown_0203A01C
	ldrb r0, [r0]
	movs r1, 0xA
	bl __udivsi3
	ldr r2, =gUnknown_0858CFE8
	lsls r0, 26
	asrs r0, 24
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	adds r0, 0x1
	adds r0, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	movs r0, 0x19
	bl warp1_set_2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8F9C

	thumb_func_start sub_80E8FD0
sub_80E8FD0: @ 80E8FD0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _080E8FF4
	cmp r0, 0x1
	beq _080E900C
	b _080E904A
	.pool
_080E8FF4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E904A
	movs r0, 0x1
	strh r0, [r2, 0x8]
	b _080E904A
	.pool
_080E900C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r0, =0x00001aac
	adds r2, r0
	ldrb r0, [r2]
	cmp r0, 0xFE
	bhi _080E9030
	adds r0, 0x1
	strb r0, [r2]
_080E9030:
	bl sub_80E8F9C
	bl warp_in
	ldr r0, =gUnknown_03005DAC
	ldr r1, =sub_80AF168
	str r1, [r0]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_080E904A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8FD0

	thumb_func_start sub_80E9068
sub_80E9068: @ 80E9068
	push {lr}
	ldr r0, =sub_80E8FD0
	movs r1, 0
	bl CreateTask
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
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
	thumb_func_end sub_80E9068

	thumb_func_start sub_80E909C
sub_80E909C: @ 80E909C
	push {lr}
	ldr r0, =gUnknown_02037318
	ldrb r0, [r0, 0x17]
	cmp r0, 0x9
	bne _080E90C0
	ldr r0, =0x00004097
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _080E90C0
	movs r0, 0
	b _080E90C2
	.pool
_080E90C0:
	movs r0, 0x1
_080E90C2:
	pop {r1}
	bx r1
	thumb_func_end sub_80E909C

	thumb_func_start sub_80E90C8
sub_80E90C8: @ 80E90C8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	movs r1, 0x2
	bl FieldObjectTurn
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E90F8
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r4, 0
	bl DestroyTask
_080E90F8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E90C8

	thumb_func_start sub_80E9108
sub_80E9108: @ 80E9108
	push {r4,lr}
	sub sp, 0x4
	bl script_env_2_enable
	bl HideMapNamePopUpWindow
	mov r4, sp
	adds r4, 0x2
	movs r2, 0x88
	lsls r2, 2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80E8CB0
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	adds r0, 0x7
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, 0x7
	strh r0, [r4]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r2, 0xE2
	lsls r2, 4
	bl MapGridSetMetatileIdAt
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	bl pal_fill_black
	ldr r0, =sub_80E90C8
	movs r1, 0
	bl CreateTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9108

	thumb_func_start sub_80E916C
sub_80E916C: @ 80E916C
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E91D4
	ldr r0, =gUnknown_0203A01C
	ldrb r0, [r0]
	movs r1, 0xA
	bl __udivsi3
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	movs r5, 0x4
	ldrsb r5, [r1, r5]
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	ldr r4, =gUnknown_0858CFE8
	lsls r0, 26
	asrs r0, 24
	adds r3, r0, 0x2
	adds r3, r4
	ldrb r3, [r3]
	lsls r3, 24
	asrs r3, 24
	adds r0, 0x3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	adds r0, r5, 0
	bl warp1_set
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80E9108
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
_080E91D4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E916C

	thumb_func_start sub_80E91F8
sub_80E91F8: @ 80E91F8
	push {lr}
	ldr r0, =sub_80E916C
	movs r1, 0
	bl CreateTask
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E91F8

	thumb_func_start CurrentMapIsSecretBase
CurrentMapIsSecretBase: @ 80E9214
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x19
	bne _080E9230
	ldrb r0, [r1, 0x5]
	cmp r0, 0x17
	bhi _080E9230
	movs r0, 0x1
	b _080E9232
	.pool
_080E9230:
	movs r0, 0
_080E9232:
	pop {r1}
	bx r1
	thumb_func_end CurrentMapIsSecretBase

	thumb_func_start sub_80E9238
sub_80E9238: @ 80E9238
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl CurrentMapIsSecretBase
	lsls r0, 24
	cmp r0, 0
	beq _080E9328
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gSaveBlock1Ptr
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	ldr r2, =0x00001a9c
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r7, r1, 0
	adds r7, 0x12
	adds r6, r1, 0
	adds r6, 0x22
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	mov r4, sp
_080E927A:
	ldrh r2, [r4]
	adds r1, r7, r2
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x77
	bhi _080E92AC
	ldr r0, =gUnknown_085A5C08
	ldrb r3, [r1]
	lsls r1, r3, 5
	adds r1, r0
	ldrb r0, [r1, 0x11]
	cmp r0, 0x4
	beq _080E92AC
	adds r0, r6, r2
	ldrb r2, [r0]
	lsrs r0, r2, 4
	adds r0, 0x7
	movs r1, 0xF
	ands r1, r2
	adds r1, 0x7
	adds r2, r3, 0
	bl sub_8127D38
_080E92AC:
	ldrh r0, [r4]
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r4]
	cmp r0, 0xF
	bls _080E927A
	cmp r5, 0
	beq _080E92F4
	mov r4, sp
	adds r4, 0x2
	movs r2, 0x88
	lsls r2, 2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80E8CB0
	mov r0, sp
	ldrh r0, [r0]
	adds r0, 0x7
	ldrh r1, [r4]
	adds r1, 0x7
	ldr r2, =0x00000e21
	bl MapGridSetMetatileIdAt
	b _080E9328
	.pool
_080E92F4:
	mov r0, r8
	cmp r0, 0x1
	bne _080E9328
	ldr r0, =0x00004089
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _080E9328
	mov r4, sp
	adds r4, 0x2
	movs r2, 0x88
	lsls r2, 2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80E8CB0
	mov r0, sp
	ldrh r0, [r0]
	adds r0, 0x7
	ldrh r1, [r4]
	adds r1, 0x7
	ldr r2, =0x00000e0a
	bl MapGridSetMetatileIdAt
_080E9328:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9238

	thumb_func_start sub_80E933C
sub_80E933C: @ 80E933C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	bl CurrentMapIsSecretBase
	lsls r0, 24
	cmp r0, 0
	bne _080E9374
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000271c
	adds r1, r0, r1
	str r1, [sp, 0x4]
	ldr r2, =0x00002728
	adds r2, r0, r2
	str r2, [sp, 0x8]
	movs r3, 0xC
	str r3, [sp, 0x10]
	b _080E939C
	.pool
_080E9374:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gSaveBlock1Ptr
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	ldr r4, =0x00001a9c
	adds r1, r4
	ldr r0, [r2]
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x12
	str r1, [sp, 0x4]
	adds r0, 0x22
	str r0, [sp, 0x8]
	movs r2, 0x10
	str r2, [sp, 0x10]
_080E939C:
	movs r6, 0
	b _080E955A
	.pool
_080E93AC:
	ldr r4, [sp, 0x4]
	adds r0, r4, r6
	ldrb r1, [r0]
	mov r10, r0
	adds r0, r6, 0x1
	str r0, [sp, 0x14]
	cmp r1, 0
	bne _080E93BE
	b _080E9554
_080E93BE:
	mov r1, r10
	ldrb r0, [r1]
	lsls r0, 5
	ldr r2, =gUnknown_085A5C08
	adds r0, r2
	ldrb r1, [r0, 0x11]
	ldrb r0, [r0, 0x13]
	str r0, [sp, 0xC]
	cmp r1, 0x4
	beq _080E93D4
	b _080E9554
_080E93D4:
	movs r5, 0
	ldr r0, =gUnknown_02037318
	ldr r3, [r0, 0x4]
	ldrb r4, [r3]
	mov r9, r0
	cmp r5, r4
	bcs _080E9412
	ldr r0, [r3, 0x4]
	ldrh r2, [r0, 0x14]
	ldr r1, =gUnknown_020375E0
	ldrh r0, [r1]
	adds r0, 0xAE
	adds r7, r1, 0
	cmp r2, r0
	beq _080E9412
	adds r2, r4, 0
_080E93F4:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r2
	bcs _080E9412
	ldr r1, [r3, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x14]
	ldrh r0, [r7]
	adds r0, 0xAE
	cmp r1, r0
	bne _080E93F4
_080E9412:
	mov r3, r9
	ldr r0, [r3, 0x4]
	ldrb r0, [r0]
	cmp r5, r0
	bne _080E941E
	b _080E9554
_080E941E:
	ldr r4, =gUnknown_020375E4
	mov r8, r4
	ldr r0, [sp, 0x8]
	adds r1, r0, r6
	ldrb r0, [r1]
	lsrs r0, 4
	strh r0, [r4]
	ldr r7, =gUnknown_020375E6
	ldrb r1, [r1]
	movs r0, 0xF
	ands r0, r1
	strh r0, [r7]
	ldrh r0, [r4]
	adds r0, 0x7
	ldrh r1, [r7]
	adds r1, 0x7
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8089350
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E9462
	adds r0, r4, 0
	bl sub_8089364
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E9554
_080E9462:
	ldr r6, =gUnknown_020375F0
	mov r1, r9
	ldr r0, [r1, 0x4]
	ldr r1, [r0, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	lsls r4, 3
	adds r1, r4, r1
	ldr r2, =0x00003f20
	adds r0, r2, 0
	ldrb r1, [r1, 0x1]
	adds r0, r1
	strh r0, [r6]
	ldrh r0, [r6]
	mov r3, r10
	ldrb r1, [r3]
	lsls r1, 5
	ldr r2, =gUnknown_085A5C24
	adds r1, r2
	ldr r1, [r1]
	ldrh r1, [r1]
	bl VarSet
	mov r3, r9
	ldr r0, [r3, 0x4]
	ldr r0, [r0, 0x4]
	adds r4, r0
	ldrb r0, [r4]
	strh r0, [r6]
	ldr r0, =gUnknown_020375E0
	ldrh r0, [r0]
	adds r0, 0xAE
	lsls r0, 16
	lsrs r0, 16
	bl FlagReset
	ldrb r0, [r6]
	ldr r5, =gSaveBlock1Ptr
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl show_sprite
	ldrb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r4, r8
	movs r3, 0
	ldrsh r4, [r4, r3]
	mov r8, r4
	movs r4, 0
	ldrsh r7, [r7, r4]
	str r7, [sp]
	mov r3, r8
	bl sub_808EBA8
	ldrb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl sub_808F254
	bl CurrentMapIsSecretBase
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E954C
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080E954C
	ldr r0, [sp, 0xC]
	cmp r0, 0x6
	bne _080E9538
	ldrb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	movs r3, 0x6
	bl sub_808F28C
	b _080E954C
	.pool
_080E9538:
	ldr r1, [sp, 0xC]
	cmp r1, 0x7
	bne _080E954C
	ldrb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	movs r3, 0x7
	bl sub_808F28C
_080E954C:
	ldr r1, =gUnknown_020375E0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080E9554:
	ldr r2, [sp, 0x14]
	lsls r0, r2, 24
	lsrs r6, r0, 24
_080E955A:
	ldr r3, [sp, 0x10]
	cmp r6, r3
	bcs _080E9562
	b _080E93AC
_080E9562:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E933C

	thumb_func_start sub_80E9578
sub_80E9578: @ 80E9578
	push {r4-r6,lr}
	movs r5, 0
	ldr r1, =gUnknown_02037318
	ldr r0, [r1, 0x4]
	ldrb r0, [r0]
	cmp r5, r0
	bcs _080E95C4
	adds r6, r1, 0
_080E9588:
	ldr r0, [r6, 0x4]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	ldrh r4, [r1, 0x14]
	adds r0, r4, 0
	subs r0, 0xAE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xD
	bhi _080E95B6
	ldrb r0, [r1]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl RemoveFieldObjectByLocalIdAndMap
	adds r0, r4, 0
	bl FlagSet
_080E95B6:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r6, 0x4]
	ldrb r0, [r0]
	cmp r5, r0
	bcc _080E9588
_080E95C4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9578

	thumb_func_start sub_80E95D4
sub_80E95D4: @ 80E95D4
	push {r4,r5,lr}
	ldr r5, =0x0000401f
	ldr r4, =gUnknown_0858D060
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_80EA20C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r5, 0
	bl VarSet
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E95D4

	thumb_func_start sub_80E9608
sub_80E9608: @ 80E9608
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r3, 0
	ldrb r0, [r4, 0x3]
	cmp r3, r0
	bge _080E9660
	ldr r6, =gUnknown_0203A01C
_080E9618:
	lsls r3, 16
	asrs r1, r3, 16
	ldr r2, [r4, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x5]
	cmp r0, 0x8
	bne _080E9650
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r2]
	adds r0, 0x7
	cmp r1, r0
	bne _080E9650
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	ldrh r0, [r2, 0x2]
	adds r0, 0x7
	cmp r1, r0
	bne _080E9650
	ldr r0, [r2, 0x8]
	strb r0, [r6]
	b _080E9660
	.pool
_080E9650:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r3, r1
	lsrs r3, r0, 16
	asrs r0, 16
	ldrb r1, [r4, 0x3]
	cmp r0, r1
	blt _080E9618
_080E9660:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E9608

	thumb_func_start sub_80E9668
sub_80E9668: @ 80E9668
	push {lr}
	bl sub_80E9608
	bl sub_80E8B6C
	ldr r0, =gUnknown_08275BB7
	bl script_env_1_execute_new_script
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9668

	thumb_func_start sub_80E9680
sub_80E9680: @ 80E9680
	push {lr}
	bl sub_80E8B58
	bl sub_80E8B6C
	ldr r0, =gUnknown_020375F0
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080E969C
	movs r0, 0x1
	b _080E969E
	.pool
_080E969C:
	movs r0, 0
_080E969E:
	pop {r1}
	bx r1
	thumb_func_end sub_80E9680

	thumb_func_start sub_80E96A4
sub_80E96A4: @ 80E96A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080E96DC
	cmp r0, 0x1
	bgt _080E96CC
	cmp r0, 0
	beq _080E96D2
	b _080E9714
	.pool
_080E96CC:
	cmp r0, 0x2
	beq _080E96F4
	b _080E9714
_080E96D2:
	bl script_env_2_enable
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _080E9714
_080E96DC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E9714
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _080E9714
	.pool
_080E96F4:
	movs r0, 0x7E
	bl copy_saved_warp2_bank_and_enter_x_to_warp1
	bl warp_in
	ldr r0, =gUnknown_03005DAC
	ldr r1, =mapldr_default
	str r1, [r0]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	bl script_env_2_disable
	adds r0, r5, 0
	bl DestroyTask
_080E9714:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E96A4

	thumb_func_start sub_80E9728
sub_80E9728: @ 80E9728
	push {lr}
	ldr r0, =sub_80E96A4
	movs r1, 0
	bl CreateTask
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9728

	thumb_func_start sub_80E9744
sub_80E9744: @ 80E9744
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldr r1, =gUnknown_0203A01C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E9770
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	b _080E9774
	.pool
_080E9770:
	ldr r1, =gUnknown_020375F0
	movs r0, 0
_080E9774:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9744

	thumb_func_start sub_80E9780
sub_80E9780: @ 80E9780
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	lsls r5, r1, 2
	adds r5, r1
	lsls r5, 5
	ldr r4, [r0]
	adds r4, r5, r4
	ldr r1, =0x00001a9e
	adds r4, r1
	adds r0, r4, 0
	bl sub_80E8DF4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringCopyN
	movs r1, 0xFF
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	ldr r1, =0x00001aa9
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl ConvertInternationalString
	ldr r1, =gUnknown_085EA72F
	adds r0, r6, 0
	bl StringAppend
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E9780

	thumb_func_start GetSecretBaseMapName
GetSecretBaseMapName: @ 80E97EC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x00004054
	bl VarGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80E9780
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSecretBaseMapName

	thumb_func_start sub_80E980C
sub_80E980C: @ 80E980C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	mov r8, r1
	lsls r5, r0, 2
	adds r5, r0
	lsls r5, 5
	ldr r4, [r1]
	adds r4, r5, r4
	ldr r0, =0x00001a9e
	adds r4, r0
	ldr r6, =gStringVar1
	adds r0, r4, 0
	bl sub_80E8DF4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringCopyN
	movs r1, 0xFF
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	ldr r1, =0x00001aa9
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl ConvertInternationalString
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E980C

	thumb_func_start sub_80E9878
sub_80E9878: @ 80E9878
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r0, [r2]
	lsrs r0, 6
	cmp r0, 0
	bne _080E98A4
	movs r0, 0
	b _080E98A6
	.pool
_080E98A4:
	movs r0, 0x1
_080E98A6:
	pop {r1}
	bx r1
	thumb_func_end sub_80E9878

	thumb_func_start sub_80E98AC
sub_80E98AC: @ 80E98AC
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x1A
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1B
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1C
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1D
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1E
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1F
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E98AC

	thumb_func_start sub_80E9914
sub_80E9914: @ 80E9914
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	movs r0, 0
	mov r10, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x00001ad0
	adds r2, r1, r2
	str r2, [sp]
	ldr r3, =0x00001a9c
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E993A
	b _080E9A60
_080E993A:
	movs r6, 0
	ldr r7, =0x00001ae8
	adds r7, r1, r7
	str r7, [sp, 0x14]
	ldr r0, =0x00001b18
	adds r0, r1, r0
	str r0, [sp, 0xC]
	ldr r2, =0x00001b24
	adds r2, r1, r2
	str r2, [sp, 0x10]
	adds r3, 0x94
	adds r3, r1, r3
	str r3, [sp, 0x18]
	ldr r7, =0x00001b36
	adds r7, r1, r7
	str r7, [sp, 0x1C]
	mov r9, r6
_080E995C:
	movs r4, 0
	lsls r5, r6, 2
	lsls r3, r6, 1
	ldr r0, =gPlayerParty
	mov r8, r0
	adds r1, r6, 0x1
	str r1, [sp, 0x4]
	adds r2, r5, 0
	ldr r1, [sp, 0x14]
_080E996E:
	adds r0, r2, r4
	lsls r0, 1
	adds r0, r1, r0
	mov r7, r9
	strh r7, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080E996E
	ldr r1, [sp, 0xC]
	adds r0, r1, r3
	mov r2, r9
	strh r2, [r0]
	ldr r7, [sp, 0x10]
	adds r0, r7, r3
	strh r2, [r0]
	ldr r1, [sp, 0x18]
	adds r0, r1, r6
	mov r2, r9
	strb r2, [r0]
	ldr r3, [sp]
	adds r0, r3, r5
	mov r7, r9
	str r7, [r0]
	ldr r1, [sp, 0x1C]
	adds r0, r1, r6
	strb r7, [r0]
	movs r2, 0x64
	adds r5, r6, 0
	muls r5, r2
	mov r3, r8
	adds r4, r5, r3
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _080E9A54
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _080E9A54
	movs r4, 0
	mov r7, r10
	lsls r7, 2
	mov r8, r7
	mov r0, r10
	lsls r7, r0, 1
	adds r0, 0x1
	str r0, [sp, 0x8]
	ldr r2, =gPlayerParty
_080E99DA:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, r2
	str r2, [sp, 0x20]
	bl GetMonData
	mov r3, r8
	adds r1, r3, r4
	lsls r1, 1
	ldr r3, [sp, 0x14]
	adds r1, r3, r1
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r2, [sp, 0x20]
	cmp r4, 0x3
	bls _080E99DA
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldr r2, [sp, 0xC]
	adds r1, r2, r7
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	ldr r3, [sp, 0x10]
	adds r1, r3, r7
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x18]
	add r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	ldr r1, [sp]
	add r1, r8
	str r0, [r1]
	adds r0, r4, 0
	bl sub_80E98AC
	ldr r1, [sp, 0x1C]
	add r1, r10
	strb r0, [r1]
	ldr r7, [sp, 0x8]
	lsls r0, r7, 16
	lsrs r0, 16
	mov r10, r0
_080E9A54:
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bhi _080E9A60
	b _080E995C
_080E9A60:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9914

	thumb_func_start sub_80E9A90
sub_80E9A90: @ 80E9A90
	push {r4-r6,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x00001aaa
	adds r1, r0, r4
	ldrh r6, [r1]
	ldr r1, =0x00001a9c
	adds r0, r1
	bl sub_80E8AF0
	ldr r0, [r5]
	adds r0, r4
	strh r6, [r0]
	bl sub_80E9728
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9A90

	thumb_func_start sub_80E9AC0
sub_80E9AC0: @ 80E9AC0
	push {lr}
	movs r0, 0x14
	bl sav12_xor_increment
	bl sub_80E9A90
	pop {r0}
	bx r0
	thumb_func_end sub_80E9AC0

	thumb_func_start sub_80E9AD0
sub_80E9AD0: @ 80E9AD0
	push {r4-r7,lr}
	ldr r0, =gUnknown_02037318
	ldr r4, [r0, 0x4]
	movs r6, 0
	b _080E9B62
	.pool
_080E9AE0:
	ldr r2, [r4, 0x10]
	lsls r1, r6, 1
	adds r0, r1, r6
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x5]
	adds r7, r1, 0
	cmp r0, 0x8
	bne _080E9B5C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r2, 0x8]
	cmp r1, r0
	bne _080E9B5C
	ldrh r0, [r2]
	adds r0, 0x7
	ldrh r1, [r2, 0x2]
	adds r1, 0x7
	bl MapGridGetMetatileIdAt
	movs r1, 0
	ldr r5, =gUnknown_0858CFCC
	lsls r0, 16
	asrs r2, r0, 16
_080E9B16:
	lsls r0, r1, 2
	adds r3, r0, r5
	ldrh r0, [r3, 0x2]
	cmp r0, r2
	beq _080E9B3C
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x6
	bls _080E9B16
_080E9B2A:
	bl DrawWholeMapView
	b _080E9B68
	.pool
_080E9B3C:
	ldr r0, [r4, 0x10]
	adds r1, r7, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x7
	ldrh r1, [r1, 0x2]
	adds r1, 0x7
	ldrh r3, [r3]
	movs r4, 0xC0
	lsls r4, 4
	adds r2, r4, 0
	orrs r2, r3
	bl MapGridSetMetatileIdAt
	b _080E9B2A
_080E9B5C:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080E9B62:
	ldrb r0, [r4, 0x3]
	cmp r6, r0
	bcc _080E9AE0
_080E9B68:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E9AD0

	thumb_func_start sub_80E9B70
sub_80E9B70: @ 80E9B70
	push {r4-r6,lr}
	bl sub_80E9AD0
	movs r0, 0x14
	bl sav12_xor_increment
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x00001aaa
	adds r1, r0, r4
	ldrh r6, [r1]
	ldr r1, =0x00001a9c
	adds r0, r1
	bl sub_80E8AF0
	ldr r0, [r5]
	adds r0, r4
	strh r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9B70

	thumb_func_start sub_80E9BA8
sub_80E9BA8: @ 80E9BA8
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0x1
_080E9BAE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80E9878
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E9BC4
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E9BC4:
	lsls r0, r4, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080E9BAE
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E9BA8

	thumb_func_start sub_80E9BDC
sub_80E9BDC: @ 80E9BDC
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E9878
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080E9C04
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
	b _080E9C22
	.pool
_080E9C04:
	bl sub_80E9BA8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bls _080E9C1C
	ldr r1, =gUnknown_020375F0
	movs r0, 0x2
	b _080E9C20
	.pool
_080E9C1C:
	ldr r1, =gUnknown_020375F0
	movs r0, 0
_080E9C20:
	strh r0, [r1]
_080E9C22:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9BDC

	thumb_func_start sub_80E9C2C
sub_80E9C2C: @ 80E9C2C
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 6
	movs r0, 0x1
	eors r1, r0
	lsls r1, 6
	movs r0, 0x3F
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x86
	lsls r0, 1
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C2C

	thumb_func_start sub_80E9C74
sub_80E9C74: @ 80E9C74
	push {lr}
	ldr r0, =sub_8126AD8
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C74

	thumb_func_start sub_80E9C88
sub_80E9C88: @ 80E9C88
	push {lr}
	ldr r0, =sub_80E9C9C
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C88

	thumb_func_start sub_80E9C9C
sub_80E9C9C: @ 80E9C9C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r5, r7, r0
	bl script_env_2_enable
	bl sub_80E9BA8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	cmp r0, 0
	beq _080E9D10
	movs r0, 0
	strh r0, [r5, 0x2]
	strh r0, [r5, 0x4]
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldr r4, =gUnknown_0203A020
	movs r0, 0xDC
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_0858D06C
	bl AddWindow
	strh r0, [r5, 0xC]
	adds r0, r6, 0
	bl game_continue
	adds r0, r6, 0
	bl sub_80E9E00
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_80E9E90
	str r1, [r0]
	b _080E9D1A
	.pool
_080E9D10:
	ldr r1, =gUnknown_085EA785
	ldr r2, =task_pc_turn_off
	adds r0, r6, 0
	bl DisplayItemMessageOnField
_080E9D1A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C9C

	thumb_func_start game_continue
game_continue: @ 80E9D2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r7, r1, r0
	movs r6, 0
	movs r5, 0x1
	ldr r0, =gUnknown_0203A020
	mov r8, r0
_080E9D48:
	adds r0, r5, 0
	bl sub_80E9878
	lsls r0, 24
	cmp r0, 0
	beq _080E9D7C
	lsls r4, r6, 5
	adds r4, 0x58
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	adds r1, r5, 0
	bl sub_80E9780
	mov r3, r8
	ldr r0, [r3]
	lsls r2, r6, 3
	adds r1, r0, r2
	adds r4, r0, r4
	str r4, [r1]
	adds r0, 0x4
	adds r0, r2
	str r5, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080E9D7C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080E9D48
	ldr r4, =gUnknown_0203A020
	ldr r1, [r4]
	lsls r3, r6, 3
	adds r2, r1, r3
	ldr r0, =gUnknown_085E8CF0
	str r0, [r2]
	adds r1, 0x4
	adds r1, r3
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	adds r2, r6, 0x1
	strh r2, [r7]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x7
	bgt _080E9DB8
	strh r2, [r7, 0x6]
	b _080E9DBC
	.pool
_080E9DB8:
	movs r0, 0x8
	strh r0, [r7, 0x6]
_080E9DBC:
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_0858D07C
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldrh r0, [r7, 0xC]
	strb r0, [r2, 0x10]
	ldrh r0, [r7]
	strh r0, [r2, 0xC]
	ldr r0, [r4]
	str r0, [r2]
	ldrh r0, [r7, 0x6]
	strh r0, [r2, 0xE]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end game_continue

	thumb_func_start sub_80E9DEC
sub_80E9DEC: @ 80E9DEC
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _080E9DFC
	movs r0, 0x5
	bl audio_play
_080E9DFC:
	pop {r0}
	bx r0
	thumb_func_end sub_80E9DEC

	thumb_func_start sub_80E9E00
sub_80E9E00: @ 80E9E00
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4, 0x4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	adds r0, r5, 0
	bl sub_80E9E44
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9E00

	thumb_func_start sub_80E9E44
sub_80E9E44: @ 80E9E44
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x000013f8
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x4
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xBC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9E44

	thumb_func_start sub_80E9E90
sub_80E9E90: @ 80E9E90
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInput
	adds r5, r0, 0
	ldrb r0, [r4, 0xA]
	adds r1, r4, 0x4
	adds r2, r4, 0x2
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _080E9EC8
	adds r0, 0x1
	cmp r5, r0
	bne _080E9F0C
	b _080E9F1A
	.pool
_080E9EC8:
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldrb r0, [r4, 0x10]
	bl RemoveScrollIndicatorArrowPair
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xC]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xC]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_0203A020
	ldr r0, [r0]
	bl Free
	adds r0, r6, 0
	bl task_pc_turn_off
	b _080E9F1A
	.pool
_080E9F0C:
	movs r0, 0x5
	bl audio_play
	strh r5, [r4, 0x8]
	adds r0, r6, 0
	bl sub_80E9F20
_080E9F1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E9E90

	thumb_func_start sub_80E9F20
sub_80E9F20: @ 80E9F20
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	ldrb r0, [r5, 0x10]
	bl RemoveScrollIndicatorArrowPair
	ldr r0, =gUnknown_0858D06C
	ldr r1, [r0, 0xC]
	ldr r0, [r0, 0x8]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_0858D048
	mov r8, r0
	movs r1, 0x2
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r5, 0xE]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r5, 0xE]
	movs r1, 0x2
	mov r2, r8
	bl PrintMenuTable
	ldrb r0, [r5, 0xE]
	movs r1, 0x2
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_80E9FB0
	str r0, [r4]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9F20

	thumb_func_start sub_80E9FB0
sub_80E9FB0: @ 80E9FB0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _080E9FF2
	adds r0, 0x1
	cmp r4, r0
	bne _080E9FDC
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl sub_80EA18C
	b _080E9FF2
_080E9FDC:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_0858D048
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r6, 0
	bl _call_via_r1
_080E9FF2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9FB0

	thumb_func_start sub_80E9FFC
sub_80E9FFC: @ 80E9FFC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xE]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xC]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xE]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xE]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gStringVar1
	ldrb r1, [r4, 0x8]
	bl sub_80E9780
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EA737
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_80EA06C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9FFC

	thumb_func_start sub_80EA06C
sub_80EA06C: @ 80EA06C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_0858D058
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA06C

	thumb_func_start sub_80EA08C
sub_80EA08C: @ 80EA08C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r5, r0
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldrb r0, [r6, 0xA]
	adds r1, r6, 0x4
	mov r9, r1
	adds r1, r6, 0x2
	mov r10, r1
	mov r1, r9
	mov r2, r10
	bl sub_81AE6C8
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r2, r0
	ldr r1, =0x00001a9d
	adds r2, r1
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	bl game_continue
	ldrb r2, [r6, 0x6]
	ldrb r3, [r6]
	mov r0, r9
	mov r1, r10
	bl sub_812225C
	adds r0, r4, 0
	bl sub_80E9E00
	movs r0, 0x8
	negs r0, r0
	add r8, r0
	add r5, r8
	ldr r0, =sub_80E9E90
	str r0, [r5]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA08C

	thumb_func_start sub_80EA120
sub_80EA120: @ 80EA120
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_085EA762
	ldr r2, =sub_80EA08C
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA120

	thumb_func_start sub_80EA13C
sub_80EA13C: @ 80EA13C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r4, r0
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldrb r0, [r6, 0xA]
	adds r1, r6, 0x4
	adds r6, 0x2
	adds r2, r6, 0
	bl sub_81AE6C8
	adds r0, r5, 0
	bl sub_80E9E00
	movs r0, 0x8
	negs r0, r0
	add r8, r0
	add r4, r8
	ldr r0, =sub_80E9E90
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA13C

	thumb_func_start sub_80EA18C
sub_80EA18C: @ 80EA18C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_80E9E44
	ldrb r0, [r5, 0xE]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r5, 0xE]
	bl ClearWindowTilemap
	ldrb r0, [r5, 0xE]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_80E9E90
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA18C

	thumb_func_start task_pc_turn_off
task_pc_turn_off: @ 80EA1D0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _080EA1F4
	ldr r0, =gUnknown_0823B4E8
	bl script_env_1_execute_new_script
	b _080EA1FA
	.pool
_080EA1F4:
	ldr r0, =gUnknown_0823B5E9
	bl script_env_1_execute_new_script
_080EA1FA:
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_pc_turn_off

	thumb_func_start sub_80EA20C
sub_80EA20C: @ 80EA20C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r4, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r4, r1
	ldr r1, =0x00001aa5
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x5
	bl __umodsi3
	ldr r1, =0x00001a9d
	adds r4, r1
	ldrb r2, [r4]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EA20C

	thumb_func_start sub_80EA250
sub_80EA250: @ 80EA250
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_80EA20C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0
	bne _080EA278
	ldr r0, =gUnknown_08274966
	b _080EA2DA
	.pool
_080EA278:
	cmp r0, 0x1
	bne _080EA284
	ldr r0, =gUnknown_08274D13
	b _080EA2DA
	.pool
_080EA284:
	cmp r0, 0x2
	bne _080EA290
	ldr r0, =gUnknown_08274FFE
	b _080EA2DA
	.pool
_080EA290:
	cmp r0, 0x3
	bne _080EA29C
	ldr r0, =gUnknown_08275367
	b _080EA2DA
	.pool
_080EA29C:
	cmp r0, 0x4
	bne _080EA2A8
	ldr r0, =gUnknown_082756C7
	b _080EA2DA
	.pool
_080EA2A8:
	cmp r0, 0x5
	bne _080EA2B4
	ldr r0, =gUnknown_08274B24
	b _080EA2DA
	.pool
_080EA2B4:
	cmp r0, 0x6
	bne _080EA2C0
	ldr r0, =gUnknown_08274E75
	b _080EA2DA
	.pool
_080EA2C0:
	cmp r0, 0x7
	bne _080EA2CC
	ldr r0, =gUnknown_082751E1
	b _080EA2DA
	.pool
_080EA2CC:
	cmp r1, 0x8
	beq _080EA2D8
	ldr r0, =gUnknown_082758CC
	b _080EA2DA
	.pool
_080EA2D8:
	ldr r0, =gUnknown_082754F6
_080EA2DA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EA250

	thumb_func_start sub_80EA2E4
sub_80EA2E4: @ 80EA2E4
	push {lr}
	movs r0, 0x1
	bl sub_813BADC
	ldr r1, =gUnknown_02038BCA
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x08000008
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA2E4

	thumb_func_start sub_80EA30C
sub_80EA30C: @ 80EA30C
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	ldr r1, =gSaveBlock1Ptr
	ldr r3, [r1]
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r3, r1
	ldr r0, =gUnknown_020375F0
	ldrb r0, [r0]
	ldr r1, =0x00001a9d
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r3]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA30C

	thumb_func_start sub_80EA354
sub_80EA354: @ 80EA354
	push {r4-r7,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x00000922
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080EA39A
	movs r3, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r4, =0x00001a9d
	movs r6, 0x21
	negs r6, r6
_080EA376:
	ldr r1, [r7]
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 5
	adds r1, r0
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x13
	bls _080EA376
	ldr r0, =0x00000922
	bl FlagSet
_080EA39A:
	ldr r4, =gUnknown_020375E0
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80EA20C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r2, =gUnknown_020375F0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9d
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 26
	lsrs r0, 31
	strh r0, [r2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA354

	thumb_func_start sub_80EA3E4
sub_80EA3E4: @ 80EA3E4
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080EA448
	cmp r0, 0x1
	bgt _080EA40C
	cmp r0, 0
	beq _080EA414
	b _080EA820
	.pool
_080EA40C:
	cmp r0, 0x2
	bne _080EA412
	b _080EA810
_080EA412:
	b _080EA820
_080EA414:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EA434
	ldr r1, =gUnknown_0203A01D
	movs r0, 0x1
	strb r0, [r1]
	b _080EA438
	.pool
_080EA434:
	ldr r0, =gUnknown_0203A01D
	strb r1, [r0]
_080EA438:
	adds r0, r5, 0x4
	adds r1, r5, 0x6
	bl PlayerGetDestCoords
	b _080EA81C
	.pool
_080EA448:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	adds r6, r4, 0
	cmp r1, r0
	bne _080EA474
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080EA474
	b _080EA820
_080EA474:
	strh r2, [r5, 0x4]
	ldrh r0, [r6]
	strh r0, [r5, 0x6]
	ldr r4, =0x000040ec
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x8D
	lsls r0, 2
	cmp r4, r0
	beq _080EA4C2
	adds r0, 0x8
	cmp r4, r0
	bne _080EA4E8
_080EA4C2:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA4CC
	b _080EA820
_080EA4CC:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x20
	b _080EA7FA
	.pool
_080EA4E8:
	ldr r3, =0xfffffd48
	adds r0, r4, r3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080EA51A
	movs r0, 0xB0
	lsls r0, 2
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x6
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	bne _080EA540
_080EA51A:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA524
	b _080EA820
_080EA524:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x1
	b _080EA7FA
	.pool
_080EA540:
	ldr r0, =0x00000239
	cmp r4, r0
	beq _080EA558
	adds r0, 0x8
	cmp r4, r0
	beq _080EA558
	adds r0, 0x10
	cmp r4, r0
	beq _080EA558
	adds r0, 0x8
	cmp r4, r0
	bne _080EA57C
_080EA558:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA562
	b _080EA820
_080EA562:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	b _080EA7FA
	.pool
_080EA57C:
	cmp r5, 0x34
	bne _080EA586
	ldr r0, =0x0000026d
	cmp r4, r0
	beq _080EA59E
_080EA586:
	cmp r5, 0x35
	bne _080EA5CC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0x0000026a
	cmp r0, r1
	bne _080EA5CC
_080EA59E:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA5A8
	b _080EA820
_080EA5A8:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA5CC:
	cmp r5, 0xC1
	bne _080EA618
	ldr r0, =0x0000023d
	cmp r4, r0
	bne _080EA618
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA5E0
	b _080EA820
_080EA5E0:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA618:
	cmp r5, 0x47
	bne _080EA668
	ldr r0, =0x0000023e
	cmp r4, r0
	bne _080EA668
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA62C
	b _080EA820
_080EA62C:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	eors r1, r0
	b _080EA7FC
	.pool
_080EA668:
	adds r0, r5, 0
	bl sub_80893C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA698
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA680
	b _080EA820
_080EA680:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x80
	b _080EA7FA
	.pool
_080EA698:
	adds r0, r5, 0
	bl sub_808938C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA72C
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	asrs r0, 16
	mov r1, sp
	movs r3, 0
	ldrsh r1, [r1, r3]
	movs r3, 0
	ldrsh r2, [r6, r3]
	bl sub_80FA5E4
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA6D0
	b _080EA820
_080EA6D0:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	movs r0, 0xCE
	lsls r0, 2
	cmp r1, r0
	beq _080EA70C
	cmp r1, r0
	bgt _080EA6FC
	movs r0, 0x8A
	lsls r0, 2
	cmp r1, r0
	beq _080EA714
	b _080EA820
	.pool
_080EA6FC:
	movs r0, 0xCF
	lsls r0, 2
	cmp r1, r0
	beq _080EA70C
	adds r0, 0x4
	cmp r1, r0
	beq _080EA70C
	b _080EA820
_080EA70C:
	ldr r4, =0x000040ee
	b _080EA7F0
	.pool
_080EA714:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA72C:
	adds r0, r5, 0
	bl sub_80893A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA778
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA75E
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EA75E:
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl sub_80FA794
	b _080EA820
	.pool
_080EA778:
	adds r0, r5, 0
	bl sub_80893B4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA7A8
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA7A8:
	adds r0, r5, 0
	bl MetatileBehavior_0xBB
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA7D8
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	b _080EA7FA
	.pool
_080EA7D8:
	adds r0, r5, 0
	bl MetatileBehavior_0xBC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA820
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ef
_080EA7F0:
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x2
_080EA7FA:
	orrs r1, r0
_080EA7FC:
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EA820
	.pool
_080EA810:
	ldrb r0, [r5, 0x8]
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080EA820
_080EA81C:
	movs r0, 0x1
	strh r0, [r5, 0x2]
_080EA820:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EA3E4

	thumb_func_start sub_80EA828
sub_80EA828: @ 80EA828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r2, 0
	mov r8, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	lsls r2, r5, 2
	adds r2, r5
	lsls r4, r2, 5
	adds r0, r4
	ldr r2, =0x00001a9c
	mov r9, r2
	add r0, r9
	movs r2, 0xA0
	bl memcpy
	ldr r2, [r6]
	adds r2, r4
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	subs r0, r7, 0x1
	cmp r0, 0x1
	bhi _080EA876
	ldr r0, [r6]
	adds r0, r4
	ldr r1, =0x00001aa9
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
_080EA876:
	cmp r7, 0x3
	bne _080EA8B8
	mov r2, r8
	cmp r2, 0x1
	bne _080EA8B8
	mov r1, r9
	adds r0, r4, r1
	ldr r1, [r6]
	adds r1, r0
	adds r2, r1, 0x2
	movs r3, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFF
	beq _080EA8A0
_080EA892:
	adds r3, 0x1
	cmp r3, 0x6
	bgt _080EA8A0
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA892
_080EA8A0:
	cmp r3, 0x5
	ble _080EA8B8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r1, r0
	ldr r2, =0x00001aa9
	adds r1, r2
	movs r0, 0x2
	strb r0, [r1]
_080EA8B8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA828

	thumb_func_start sub_80EA8D4
sub_80EA8D4: @ 80EA8D4
	push {r4,lr}
	movs r2, 0
	adds r4, r0, 0
	adds r4, 0x9
	adds r3, r1, 0
	adds r3, 0x9
_080EA8E0:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080EA8F0
	movs r0, 0
	b _080EA8FC
_080EA8F0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080EA8E0
	movs r0, 0x1
_080EA8FC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA8D4

	thumb_func_start sub_80EA904
sub_80EA904: @ 80EA904
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r3, 0
	ldrb r0, [r6, 0x2]
	cmp r0, 0xFF
	bne _080EA918
	ldrb r0, [r5, 0x2]
	cmp r0, 0xFF
	beq _080EA946
_080EA918:
	adds r2, r6, 0x2
	adds r0, r2, r3
	adds r4, r5, 0x2
	adds r1, r4, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080EA92C
	movs r0, 0
	b _080EA948
_080EA92C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x6
	bhi _080EA946
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA918
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA918
_080EA946:
	movs r0, 0x1
_080EA948:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA904

	thumb_func_start sub_80EA950
sub_80EA950: @ 80EA950
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r2, [r4, 0x1]
	movs r0, 0x10
	adds r1, r0, 0
	ands r1, r2
	ldrb r2, [r5, 0x1]
	ands r0, r2
	cmp r1, r0
	bne _080EA986
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80EA8D4
	lsls r0, 24
	cmp r0, 0
	beq _080EA986
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80EA904
	lsls r0, 24
	cmp r0, 0
	beq _080EA986
	movs r0, 0x1
	b _080EA988
_080EA986:
	movs r0, 0
_080EA988:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA950

	thumb_func_start sub_80EA990
sub_80EA990: @ 80EA990
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r4, =0x00001a9c
_080EA99E:
	lsls r0, r1, 16
	asrs r1, r0, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r2, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r3
	bne _080EA9C0
	adds r0, r1, 0
	b _080EA9D0
	.pool
_080EA9C0:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EA99E
	movs r0, 0x1
	negs r0, r0
_080EA9D0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA990

	thumb_func_start sub_80EA9D8
sub_80EA9D8: @ 80EA9D8
	push {r4,lr}
	movs r2, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r4, =0x00001a9c
_080EA9E2:
	lsls r0, r2, 16
	asrs r1, r0, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r3, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EAA04
	lsls r0, r2, 24
	lsrs r0, 24
	b _080EAA12
	.pool
_080EAA04:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EA9E2
	movs r0, 0
_080EAA12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA9D8

	thumb_func_start sub_80EAA18
sub_80EAA18: @ 80EAA18
	push {r4,lr}
	movs r3, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
_080EAA20:
	lsls r2, r3, 16
	asrs r1, r2, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r4, r0
	ldr r1, =0x00001a9d
	adds r0, r1
	ldrb r1, [r0]
	lsrs r0, r1, 6
	cmp r0, 0
	bne _080EAA4C
	lsls r0, r1, 28
	cmp r0, 0
	bne _080EAA4C
	lsls r0, r3, 24
	lsrs r0, 24
	b _080EAA5C
	.pool
_080EAA4C:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r2, r1
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EAA20
	movs r0, 0
_080EAA5C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAA18

	thumb_func_start sub_80EAA64
sub_80EAA64: @ 80EAA64
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080EAAEC
	ldrb r0, [r5]
	bl sub_80EA990
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	beq _080EAAEC
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080EAAC4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9d
	adds r1, r0
	ldrb r1, [r1]
	lsls r0, r1, 28
	lsrs r0, 28
	cmp r0, 0x1
	beq _080EAAEC
	lsrs r0, r1, 6
	cmp r0, 0x2
	bne _080EAAB4
	ldrb r1, [r5, 0x1]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _080EAAEC
_080EAAB4:
	lsls r4, 24
	lsrs r4, 24
	b _080EAADC
	.pool
_080EAAC4:
	bl sub_80EA9D8
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080EAADC
	bl sub_80EAA18
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080EAAEC
_080EAADC:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	adds r3, r7, 0
	bl sub_80EA828
	adds r0, r4, 0
	b _080EAAEE
_080EAAEC:
	movs r0, 0
_080EAAEE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAA64

	thumb_func_start sub_80EAAF4
sub_80EAAF4: @ 80EAAF4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xA0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r7, r0, r1
	movs r2, 0x1
_080EAB08:
	adds r1, r2, 0x1
	lsls r0, r1, 24
	lsrs r5, r0, 24
	mov r9, r1
	cmp r5, 0x13
	bhi _080EAB84
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 5
	adds r6, r0, r7
	movs r0, 0xC0
	mov r8, r0
_080EAB20:
	ldrb r0, [r6, 0x1]
	mov r3, r8
	ands r3, r0
	cmp r3, 0
	bne _080EAB3E
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 5
	adds r0, r7
	ldrb r1, [r0, 0x1]
	mov r0, r8
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0x40
	beq _080EAB56
_080EAB3E:
	cmp r3, 0x80
	bne _080EAB7A
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 5
	adds r0, r7
	ldrb r1, [r0, 0x1]
	mov r0, r8
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0x80
	beq _080EAB7A
_080EAB56:
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0xA0
	bl memcpy
	adds r4, r5
	lsls r4, 5
	adds r4, r7
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0xA0
	bl memcpy
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0xA0
	bl memcpy
_080EAB7A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAB20
_080EAB84:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r2, r0, 24
	cmp r2, 0x12
	bls _080EAB08
	add sp, 0xA0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAAF4

	thumb_func_start sub_80EABA4
sub_80EABA4: @ 80EABA4
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r4, 0x1
_080EABAE:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 5
	adds r3, r1, r0
	ldrb r0, [r3, 0x1]
	lsrs r0, 6
	cmp r0, r6
	bne _080EABCA
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	adds r0, r3, 0
	bl sub_80EAA64
_080EABCA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080EABAE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EABA4

	thumb_func_start sub_80EABDC
sub_80EABDC: @ 80EABDC
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080EABF8
	ldrb r0, [r5, 0x1]
	lsls r0, 27
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	lsrs r0, 31
	adds r6, r1, 0
	ldrb r1, [r3, 0x8]
	cmp r0, r1
	beq _080EAC00
_080EABF8:
	movs r0, 0
	b _080EAC56
	.pool
_080EAC00:
	movs r2, 0
	adds r4, r5, 0
	adds r4, 0x9
	adds r3, 0xA
_080EAC08:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080EABF8
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080EAC08
	movs r2, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0xFF
	bne _080EAC2A
	ldr r0, [r6]
	b _080EAC4E
_080EAC2A:
	adds r3, r5, 0x2
	adds r0, r3, r2
	ldr r4, [r6]
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080EABF8
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bhi _080EAC54
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EAC2A
	adds r0, r4, r2
_080EAC4E:
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EAC2A
_080EAC54:
	movs r0, 0x1
_080EAC56:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EABDC

	thumb_func_start sub_80EAC5C
sub_80EAC5C: @ 80EAC5C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r9, r1
	mov r8, r2
	movs r5, 0
	movs r6, 0
_080EAC70:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	bne _080EAC9A
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r10
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EAC9A
	adds r0, r4, 0
	bl sub_80E8AF0
	movs r0, 0x1
	orrs r5, r0
_080EAC9A:
	movs r7, 0x2
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	bne _080EACC8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r9
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EACC8
	adds r0, r4, 0
	bl sub_80E8AF0
	orrs r5, r7
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080EACC8:
	movs r7, 0x4
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	bne _080EACF6
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EACF6
	adds r0, r4, 0
	bl sub_80E8AF0
	orrs r5, r7
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080EACF6:
	cmp r5, 0x7
	beq _080EAD04
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x13
	bls _080EAC70
_080EAD04:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAC5C

	thumb_func_start sub_80EAD14
sub_80EAD14: @ 80EAD14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	movs r5, 0
_080EAD24:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	mov r1, r8
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EAD7E
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80EA950
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EAD7E
	cmp r7, 0
	bne _080EAD50
	adds r0, r4, 0
	bl sub_80E8AF0
	b _080EAD88
_080EAD50:
	ldrh r0, [r6, 0xE]
	ldrh r3, [r4, 0xE]
	cmp r0, r3
	bls _080EAD60
	adds r0, r4, 0
	bl sub_80E8AF0
	b _080EAD88
_080EAD60:
	ldrb r0, [r6, 0x1]
	lsls r0, 28
	lsrs r0, 28
	ldrb r1, [r4, 0x1]
	movs r3, 0x10
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x1]
	adds r0, r6, 0
	bl sub_80E8AF0
	movs r0, 0x1
	b _080EAD8A
_080EAD7E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAD24
_080EAD88:
	movs r0, 0
_080EAD8A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAD14

	thumb_func_start sub_80EAD94
sub_80EAD94: @ 80EAD94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r7, r1, 0
	mov r8, r2
	adds r6, r3, 0
	movs r5, 0x1
_080EADA6:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	mov r1, r9
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EADF8
	ldrb r1, [r4, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _080EADCE
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
_080EADCE:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EADF8
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EADF8
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EADF8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EADA6
	movs r5, 0
_080EAE04:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r4, r0, r7
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EAE38
	ldrb r0, [r4, 0x1]
	movs r2, 0x21
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EAE38
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EAE38:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAE04
	movs r5, 0
	movs r0, 0x21
	negs r0, r0
	adds r7, r0, 0
_080EAE4A:
	lsls r0, r5, 2
	adds r0, r5
	lsls r4, r0, 5
	mov r2, r8
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080EAE6A
	ldrb r0, [r1, 0x1]
	ands r0, r7
	strb r0, [r1, 0x1]
	adds r0, r1, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EAE6A:
	adds r1, r4, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _080EAE78
	ldrb r0, [r1, 0x1]
	ands r0, r7
	strb r0, [r1, 0x1]
_080EAE78:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAE4A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAD94

	thumb_func_start sub_80EAE90
sub_80EAE90: @ 80EAE90
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _080EAEAE
	adds r0, r4, 0
	adds r1, r3, 0
	bl sub_80EAA64
	adds r0, r4, 0
	bl sub_80E8AF0
_080EAEAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAE90

	thumb_func_start sub_80EAEB4
sub_80EAEB4: @ 80EAEB4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
_080EAEBA:
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 5
	ldr r0, [r5]
	adds r0, r4
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	bl sub_80EAE90
	ldr r0, [r5, 0xC]
	adds r0, r4
	ldr r1, [r5, 0x10]
	ldr r2, [r5, 0x14]
	bl sub_80EAE90
	ldr r0, [r5, 0x18]
	adds r0, r4
	ldr r1, [r5, 0x1C]
	ldr r2, [r5, 0x20]
	bl sub_80EAE90
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x13
	bls _080EAEBA
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAEB4

	thumb_func_start sub_80EAEF4
sub_80EAEF4: @ 80EAEF4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	ldr r1, [r4, 0xC]
	ldr r2, [r4, 0x18]
	bl sub_80EAC5C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldr r1, [r4]
	ldr r2, [r4, 0xC]
	ldr r3, [r4, 0x18]
	bl sub_80EAD94
	adds r0, r4, 0
	bl sub_80EAEB4
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	bl sub_80EAA64
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x10]
	ldr r2, [r4, 0x14]
	bl sub_80EAA64
	ldr r0, [r4, 0x18]
	ldr r1, [r4, 0x1C]
	ldr r2, [r4, 0x20]
	bl sub_80EAA64
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r6, r4, 0
	adds r6, 0xC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r5, r4, 0
	adds r5, 0x18
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80EABA4
	adds r0, r6, 0
	movs r1, 0
	bl sub_80EABA4
	adds r0, r5, 0
	movs r1, 0
	bl sub_80EABA4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAEF4

	thumb_func_start sub_80EAF80
sub_80EAF80: @ 80EAF80
	push {r4-r7,lr}
	sub sp, 0x24
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	movs r0, 0x60
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080EAF9A
	b _080EB16A
_080EAF9A:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080EAFAC
	cmp r0, 0x3
	beq _080EAFC8
	b _080EAFD6
_080EAFAC:
	lsls r4, r5, 1
	adds r0, r6, r4
	movs r1, 0
	adds r2, r5, 0
	bl memset
	adds r4, r5
	adds r4, r6, r4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r5, 0
	bl memset
	b _080EAFD6
_080EAFC8:
	lsls r0, r5, 1
	adds r0, r5
	adds r0, r6, r0
	movs r1, 0
	adds r2, r5, 0
	bl memset
_080EAFD6:
	cmp r7, 0x1
	beq _080EB030
	cmp r7, 0x1
	bgt _080EAFE4
	cmp r7, 0
	beq _080EAFEE
	b _080EB0D4
_080EAFE4:
	cmp r7, 0x2
	beq _080EB074
	cmp r7, 0x3
	beq _080EB0A8
	b _080EB0D4
_080EAFEE:
	adds r0, r6, r5
	str r0, [sp]
	ldr r4, =gUnknown_020229E8
	movs r3, 0xFF
	ldrb r0, [r4, 0x1C]
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0x36]
	str r0, [sp, 0x8]
	lsls r1, r5, 1
	adds r0, r6, r1
	str r0, [sp, 0xC]
	ldrh r2, [r4, 0x38]
	adds r0, r3, 0
	ands r0, r2
	str r0, [sp, 0x10]
	adds r0, r4, 0
	adds r0, 0x52
	ldrh r0, [r0]
	str r0, [sp, 0x14]
	adds r1, r5
	adds r1, r6, r1
	str r1, [sp, 0x18]
	adds r0, r4, 0
	adds r0, 0x54
	ldrh r0, [r0]
	ands r3, r0
	str r3, [sp, 0x1C]
	adds r0, r4, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	b _080EB0D2
	.pool
_080EB030:
	lsls r2, r5, 1
	adds r0, r6, r2
	str r0, [sp]
	ldr r4, =gUnknown_020229E8
	ldrh r3, [r4, 0x38]
	movs r1, 0xFF
	adds r0, r1, 0
	ands r0, r3
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r0, 0x52
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	adds r2, r5
	adds r2, r6, r2
	str r2, [sp, 0xC]
	adds r0, r4, 0
	adds r0, 0x54
	ldrh r2, [r0]
	adds r0, r1, 0
	ands r0, r2
	str r0, [sp, 0x10]
	adds r0, r4, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	str r0, [sp, 0x14]
	str r6, [sp, 0x18]
	ldrh r0, [r4]
	ands r1, r0
	str r1, [sp, 0x1C]
	ldrh r0, [r4, 0x1A]
	b _080EB0D2
	.pool
_080EB074:
	lsls r0, r5, 1
	adds r0, r5
	adds r0, r6, r0
	str r0, [sp]
	ldr r1, =gUnknown_020229E8
	adds r0, r1, 0
	adds r0, 0x54
	ldrb r0, [r0]
	str r0, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	str r6, [sp, 0xC]
	ldrb r0, [r1]
	str r0, [sp, 0x10]
	ldrh r0, [r1, 0x1A]
	str r0, [sp, 0x14]
	adds r0, r6, r5
	str r0, [sp, 0x18]
	ldrb r0, [r1, 0x1C]
	str r0, [sp, 0x1C]
	ldrh r0, [r1, 0x36]
	b _080EB0D2
	.pool
_080EB0A8:
	str r6, [sp]
	ldr r1, =gUnknown_020229E8
	ldrb r0, [r1]
	str r0, [sp, 0x4]
	ldrh r0, [r1, 0x1A]
	str r0, [sp, 0x8]
	adds r0, r6, r5
	str r0, [sp, 0xC]
	movs r2, 0xFF
	ldrb r0, [r1, 0x1C]
	str r0, [sp, 0x10]
	ldrh r0, [r1, 0x36]
	str r0, [sp, 0x14]
	lsls r0, r5, 1
	adds r0, r6, r0
	str r0, [sp, 0x18]
	ldrh r0, [r1, 0x38]
	ands r2, r0
	str r2, [sp, 0x1C]
	adds r1, 0x52
	ldrh r0, [r1]
_080EB0D2:
	str r0, [sp, 0x20]
_080EB0D4:
	mov r0, sp
	bl sub_80EAEF4
	movs r3, 0x1
	ldr r6, =gSaveBlock1Ptr
	movs r7, 0x10
	negs r7, r7
_080EB0E2:
	ldr r0, [r6]
	lsls r1, r3, 2
	adds r1, r3
	lsls r4, r1, 5
	adds r0, r4
	ldr r5, =0x00001a9d
	adds r2, r0, r5
	ldrb r1, [r2]
	lsls r0, r1, 28
	lsrs r0, 28
	cmp r0, 0x1
	bne _080EB112
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r6]
	adds r1, r4
	adds r1, r5
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
_080EB112:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _080EB0E2
	bl sub_80EAAF4
	movs r3, 0x1
	ldr r7, =gSaveBlock1Ptr
	adds r6, r7, 0
	adds r4, r5, 0
	movs r5, 0x3F
_080EB12A:
	ldr r0, [r6]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 5
	adds r0, r1
	adds r2, r0, r4
	ldrb r1, [r2]
	lsrs r0, r1, 6
	cmp r0, 0x2
	bne _080EB144
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
_080EB144:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _080EB12A
	ldr r1, [r7]
	ldr r2, =0x00001a9c
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EB16A
	ldr r0, =0x00001aaa
	adds r2, r1, r0
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080EB16A
	adds r0, r1, 0x1
	strh r0, [r2]
_080EB16A:
	add sp, 0x24
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAF80

	thumb_func_start sub_80EB18C
sub_80EB18C: @ 80EB18C
	push {r4,r5,lr}
	movs r5, 0
	adds r4, r0, 0
_080EB192:
	ldrb r0, [r4, 0xD]
	cmp r0, 0x1
	bne _080EB19E
	adds r0, r4, 0
	bl sub_80E8AF0
_080EB19E:
	adds r4, 0xA0
	adds r5, 0x1
	cmp r5, 0x13
	bls _080EB192
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80EB18C

	thumb_func_start sub_80EB1AC
sub_80EB1AC: @ 80EB1AC
	push {lr}
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB1FC
	ldr r0, =0x000040f0
	movs r1, 0x1
	bl VarSet
	b _080EB204
	.pool
_080EB1FC:
	ldr r0, =0x000040f0
	movs r1, 0
	bl VarSet
_080EB204:
	ldr r1, =gUnknown_0203A01D
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB1AC

	thumb_func_start sub_80EB218
sub_80EB218: @ 80EB218
	push {r4-r6,lr}
	ldr r5, =0x000040f0
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB272
	ldr r6, =gUnknown_0203A01D
	ldrb r0, [r6]
	cmp r0, 0x1
	bne _080EB272
	bl CurrentMapIsSecretBase
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080EB272
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	strb r4, [r6]
	bl sub_80EEA70
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
_080EB272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB218

	thumb_func_start sub_80EB290
sub_80EB290: @ 80EB290
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2BA
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB290

	thumb_func_start sub_80EB2C8
sub_80EB2C8: @ 80EB2C8
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2F2
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2F2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB2C8

	thumb_func_start sub_80EB300
sub_80EB300: @ 80EB300
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB34C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB34C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB300

	thumb_func_start sub_80EB368
sub_80EB368: @ 80EB368
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB3B4
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB3B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB368

	thumb_func_start sub_80EB3D0
sub_80EB3D0: @ 80EB3D0
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB41C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB41C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB3D0

	thumb_func_start sub_80EB438
sub_80EB438: @ 80EB438
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB480
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r4, 0x1
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x1
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB480:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB438

	thumb_func_start sub_80EB498
sub_80EB498: @ 80EB498
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffce4
	adds r0, r1
	cmp r0, 0x18
	bhi _080EB55C
	lsls r0, 2
	ldr r1, =_080EB4D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB4D0:
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
_080EB534:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB55C
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB55C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB498

	thumb_func_start sub_80EB56C
sub_80EB56C: @ 80EB56C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffdd4
	adds r0, r1
	cmp r0, 0xCF
	bls _080EB594
	b _080EB9D0
_080EB594:
	lsls r0, 2
	ldr r1, =_080EB5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB5A8:
	.4byte _080EB930
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB930
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB954
	.4byte _080EB954
	.4byte _080EB8E8
	.4byte _080EB8E8
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
_080EB8E8:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB90C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EB994
	.pool
_080EB930:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB954:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	b _080EB994
	.pool
_080EB97C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
_080EB994:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EB9D0
	.pool
_080EB9AC:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB9D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB56C

	thumb_func_start sub_80EB9E0
sub_80EB9E0: @ 80EB9E0
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffd6f
	adds r0, r1
	cmp r0, 0x35
	bls _080EBA08
	b _080EBB18
_080EBA08:
	lsls r0, 2
	ldr r1, =_080EBA1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBA1C:
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
_080EBAF4:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBB18
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBB18:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB9E0

	thumb_func_start sub_80EBB28
sub_80EBB28: @ 80EBB28
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffddb
	adds r0, r1
	cmp r0, 0xA2
	bls _080EBB50
	b _080EBE6C
_080EBB50:
	lsls r0, 2
	ldr r1, =_080EBB64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBB64:
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE14
	.4byte _080EBE14
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
_080EBDF0:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EBE30
	.pool
_080EBE14:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
_080EBE30:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EBE6C
	.pool
_080EBE48:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBE6C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBB28

	thumb_func_start sub_80EBE7C
sub_80EBE7C: @ 80EBE7C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000028e
	cmp r1, r0
	bgt _080EBECC
	subs r0, 0x1
	cmp r1, r0
	blt _080EBECC
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBECC
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBECC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBE7C

	.align 2, 0 @ Don't pad with nop.
