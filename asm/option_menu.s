	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80BA4B0
sub_80BA4B0: @ 80BA4B0
	push {lr}
	bl RunTasks
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl fade_and_return_progress_probably
	pop {r0}
	bx r0
	thumb_func_end sub_80BA4B0

	thumb_func_start sub_80BA4C8
sub_80BA4C8: @ 80BA4C8
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl copy_pal_bg_faded_to_pal_ram
	pop {r0}
	bx r0
	thumb_func_end sub_80BA4C8

	thumb_func_start CB2_OptionsMenu
CB2_OptionsMenu: @ 80BA4DC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r1, =gUnknown_030022C0
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xB
	bhi _080BA538
	lsls r0, 2
	ldr r1, =_080BA508
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BA508:
	.4byte _080BA538
	.4byte _080BA54C
	.4byte _080BA69C
	.4byte _080BA6BC
	.4byte _080BA6E0
	.4byte _080BA718
	.4byte _080BA728
	.4byte _080BA740
	.4byte _080BA748
	.4byte _080BA760
	.4byte _080BA774
	.4byte _080BA80C
_080BA538:
	movs r0, 0
	bl SetVBlankCallback
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BA7F4
	.pool
_080BA54C:
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r1, sp, 0x8
	mov r8, r1
	add r2, sp, 0x4
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_080BA56A:
	strh r6, [r2]
	add r0, sp, 0x4
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _080BA56A
	strh r6, [r2]
	add r2, sp, 0x4
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x8]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	add r0, sp, 0x4
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0855C698
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
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
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_0855C680
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x1
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x23
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0xC1
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x4
	bl SetGpuReg
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	b _080BA7EC
	.pool
_080BA69C:
	bl sub_80A1A74
	bl remove_some_task
	bl ResetTasks
	bl ResetAllObjectData
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BA7F4
	.pool
_080BA6BC:
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	movs r3, 0xD1
	lsls r3, 1
	movs r0, 0x1
	bl LoadBgTiles
	b _080BA7EC
	.pool
_080BA6E0:
	ldr r0, =gUnknown_0855C6A0
	movs r1, 0
	movs r2, 0x2
	bl gpu_pal_apply
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r0, [r0, 0x4]
	movs r1, 0x70
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BA7F4
	.pool
_080BA718:
	ldr r0, =gUnknown_0855C604
	movs r1, 0x10
	movs r2, 0x20
	bl gpu_pal_apply
	b _080BA7EC
	.pool
_080BA728:
	movs r0, 0
	bl PutWindowTilemap
	bl sub_80BB0D0
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BA7F4
	.pool
_080BA740:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	b _080BA7F4
_080BA748:
	movs r0, 0x1
	bl PutWindowTilemap
	bl sub_80BB104
	ldr r1, =gUnknown_030022C0
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080BA760:
	bl sub_80BB154
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080BA7F4
	.pool
_080BA774:
	ldr r0, =sub_80BA83C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_03005D90
	ldr r2, [r0]
	ldrb r0, [r2, 0x14]
	lsls r0, 29
	lsrs r0, 29
	strh r0, [r4, 0xA]
	ldrb r1, [r2, 0x15]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r4, 0xC]
	ldrb r1, [r2, 0x15]
	lsls r1, 30
	lsrs r1, 31
	strh r1, [r4, 0xE]
	ldrb r1, [r2, 0x15]
	lsls r1, 31
	lsrs r1, 31
	strh r1, [r4, 0x10]
	ldrb r1, [r2, 0x13]
	strh r1, [r4, 0x12]
	ldrb r1, [r2, 0x14]
	lsrs r1, 3
	strh r1, [r4, 0x14]
	bl sub_80BAC38
	ldrb r0, [r4, 0xC]
	bl sub_80BAD08
	ldrb r0, [r4, 0xE]
	bl sub_80BAD84
	ldrb r0, [r4, 0x10]
	bl sub_80BAE08
	ldrb r0, [r4, 0x12]
	bl sub_80BB028
	ldrb r0, [r4, 0x14]
	bl sub_80BAF0C
	ldrb r0, [r4, 0x8]
	bl sub_80BAB38
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
_080BA7EC:
	ldr r1, =gUnknown_030022C0
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_080BA7F4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080BA828
	.pool
_080BA80C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl pal_fade_maybe
	ldr r0, =sub_80BA4C8
	bl SetVBlankCallback
	ldr r0, =sub_80BA4B0
	bl SetMainCallback2
_080BA828:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_OptionsMenu

	thumb_func_start sub_80BA83C
sub_80BA83C: @ 80BA83C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BA85C
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80BA86C
	str r0, [r1]
_080BA85C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BA83C

	thumb_func_start sub_80BA86C
sub_80BA86C: @ 80BA86C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080BA89C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x6
	beq _080BA892
	b _080BAA5A
_080BA892:
	b _080BA8AE
	.pool
_080BA89C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080BA8BC
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
_080BA8AE:
	ldr r0, =sub_80BAA64
	str r0, [r1]
	b _080BAA5A
	.pool
_080BA8BC:
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _080BA8EC
	ldr r1, =gTasks
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r1
	ldrh r5, [r3, 0x8]
	movs r6, 0x8
	ldrsh r0, [r3, r6]
	adds r7, r1, 0
	cmp r0, 0
	ble _080BA8E8
	subs r0, r5, 0x1
	b _080BA90C
	.pool
_080BA8E8:
	movs r0, 0x6
	b _080BA90C
_080BA8EC:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080BA924
	ldr r1, =gTasks
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r1
	ldrh r5, [r3, 0x8]
	movs r7, 0x8
	ldrsh r0, [r3, r7]
	adds r7, r1, 0
	cmp r0, 0x5
	bgt _080BA914
	adds r0, r5, 0x1
_080BA90C:
	strh r0, [r3, 0x8]
	b _080BA916
	.pool
_080BA914:
	strh r6, [r3, 0x8]
_080BA916:
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r7
	ldrb r0, [r0, 0x8]
	bl sub_80BAB38
	b _080BAA5A
_080BA924:
	ldr r0, =gTasks
	lsls r2, r4, 2
	adds r1, r2, r4
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r1, [r1, r3]
	adds r7, r0, 0
	cmp r1, 0x5
	bls _080BA93A
	b _080BAA5A
_080BA93A:
	lsls r0, r1, 2
	ldr r1, =_080BA94C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080BA94C:
	.4byte _080BA964
	.4byte _080BA98A
	.4byte _080BA9B0
	.4byte _080BA9D6
	.4byte _080BA9FC
	.4byte _080BAA22
_080BA964:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0xA]
	adds r0, r5, 0
	bl sub_80BABDC
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0xA]
	movs r6, 0xA
	ldrsh r0, [r4, r6]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BAC38
	b _080BAA46
_080BA98A:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0xC]
	adds r0, r5, 0
	bl sub_80BACE0
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0xC]
	movs r7, 0xC
	ldrsh r0, [r4, r7]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BAD08
	b _080BAA46
_080BA9B0:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0xE]
	adds r0, r5, 0
	bl sub_80BAD5C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BAD84
	b _080BAA46
_080BA9D6:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0x10]
	adds r0, r5, 0
	bl sub_80BADD8
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0x10]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BAE08
	b _080BAA46
_080BA9FC:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0x12]
	adds r0, r5, 0
	bl sub_80BAFCC
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0x12]
	movs r6, 0x12
	ldrsh r0, [r4, r6]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BB028
	b _080BAA46
_080BAA22:
	adds r4, r2, r4
	lsls r4, 3
	adds r4, r7
	ldrb r5, [r4, 0x14]
	adds r0, r5, 0
	bl sub_80BAE5C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	strh r0, [r4, 0x14]
	movs r7, 0x14
	ldrsh r0, [r4, r7]
	cmp r5, r0
	beq _080BAA46
	adds r0, r1, 0
	bl sub_80BAF0C
_080BAA46:
	ldr r1, =gUnknown_02039B48
	ldrb r0, [r1]
	cmp r0, 0
	beq _080BAA5A
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_080BAA5A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BA86C

	thumb_func_start sub_80BAA64
sub_80BAA64: @ 80BAA64
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_03005D90
	ldr r3, [r6]
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r0, 0x7
	ldrb r1, [r4, 0xA]
	ands r1, r0
	ldrb r2, [r3, 0x14]
	movs r0, 0x8
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x14]
	ldr r3, [r6]
	movs r5, 0x1
	ldrb r1, [r4, 0xC]
	ands r1, r5
	lsls r1, 2
	ldrb r2, [r3, 0x15]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	ldr r3, [r6]
	ldrb r1, [r4, 0xE]
	ands r1, r5
	lsls r1, 1
	ldrb r2, [r3, 0x15]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	ldr r3, [r6]
	ldrb r1, [r4, 0x10]
	ands r1, r5
	ldrb r2, [r3, 0x15]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	ldr r1, [r6]
	ldrh r0, [r4, 0x12]
	movs r5, 0
	strb r0, [r1, 0x13]
	ldr r3, [r6]
	ldrb r1, [r4, 0x14]
	lsls r1, 3
	ldrb r2, [r3, 0x14]
	movs r0, 0x7
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x14]
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldr r0, =sub_80BAB08
	str r0, [r4]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAA64

	thumb_func_start sub_80BAB08
sub_80BAB08: @ 80BAB08
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080BAB2C
	adds r0, r2, 0
	bl DestroyTask
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_030022C0
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_080BAB2C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAB08

	thumb_func_start sub_80BAB38
sub_80BAB38: @ 80BAB38
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x87
	lsls r1, 5
	movs r0, 0x40
	bl SetGpuReg
	lsls r4, 4
	adds r1, r4, 0
	adds r1, 0x28
	lsls r1, 8
	adds r4, 0x38
	orrs r1, r4
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80BAB38

	thumb_func_start sub_80BAB68
sub_80BAB68: @ 80BAB68
	push {r4-r6,lr}
	sub sp, 0x1C
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	beq _080BABA0
_080BAB84:
	mov r0, sp
	adds r0, r2
	adds r0, 0xC
	strb r1, [r0]
	adds r4, 0x1
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	beq _080BABA0
	cmp r2, 0xE
	bls _080BAB84
_080BABA0:
	cmp r3, 0
	beq _080BABAE
	add r1, sp, 0xC
	movs r0, 0x4
	strb r0, [r1, 0x2]
	movs r0, 0x5
	strb r0, [r1, 0x5]
_080BABAE:
	mov r1, sp
	adds r1, r2
	adds r1, 0xC
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	add r2, sp, 0xC
	adds r3, r6, 0
	bl Print
	add sp, 0x1C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80BAB68

	thumb_func_start sub_80BABDC
sub_80BABDC: @ 80BABDC
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_030022C0
	ldrh r1, [r2, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080BAC08
	cmp r3, 0x1
	bhi _080BAC00
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080BAC02
	.pool
_080BAC00:
	movs r3, 0
_080BAC02:
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BAC08:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080BAC2C
	cmp r3, 0
	beq _080BAC24
	subs r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080BAC26
	.pool
_080BAC24:
	movs r3, 0x2
_080BAC26:
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BAC2C:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BABDC

	thumb_func_start sub_80BAC38
sub_80BAC38: @ 80BAC38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, =gUnknown_085EE5D4
	mov r0, sp
	ldrb r3, [r0]
	adds r0, r4, 0
	movs r1, 0x68
	bl sub_80BAB68
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldr r0, =gUnknown_085EE5DF
	mov r8, r0
	movs r0, 0x1
	mov r1, r8
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	ldr r6, =gUnknown_085EE5E9
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	subs r5, 0x5E
	subs r4, r5
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x68
	lsls r4, 24
	lsrs r4, 24
	mov r0, sp
	ldrb r3, [r0, 0x1]
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl sub_80BAB68
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xC6
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r3, [r0, 0x2]
	adds r0, r6, 0
	movs r2, 0
	bl sub_80BAB68
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAC38

	thumb_func_start sub_80BACE0
sub_80BACE0: @ 80BACE0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _080BACFA
	movs r1, 0x1
	eors r2, r1
	ldr r0, =gUnknown_02039B48
	strb r1, [r0]
_080BACFA:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BACE0

	thumb_func_start sub_80BAD08
sub_80BAD08: @ 80BAD08
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	strb r2, [r1]
	strb r2, [r1, 0x1]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_085EE5F4
	mov r1, sp
	ldrb r3, [r1]
	movs r1, 0x68
	movs r2, 0x10
	bl sub_80BAB68
	ldr r4, =gUnknown_085EE5FD
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC6
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r4, 0
	movs r2, 0x10
	bl sub_80BAB68
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAD08

	thumb_func_start sub_80BAD5C
sub_80BAD5C: @ 80BAD5C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _080BAD76
	movs r1, 0x1
	eors r2, r1
	ldr r0, =gUnknown_02039B48
	strb r1, [r0]
_080BAD76:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BAD5C

	thumb_func_start sub_80BAD84
sub_80BAD84: @ 80BAD84
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	strb r2, [r1]
	strb r2, [r1, 0x1]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_085EE607
	mov r1, sp
	ldrb r3, [r1]
	movs r1, 0x68
	movs r2, 0x20
	bl sub_80BAB68
	ldr r4, =gUnknown_085EE613
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC6
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_80BAB68
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAD84

	thumb_func_start sub_80BADD8
sub_80BADD8: @ 80BADD8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _080BADF8
	movs r4, 0x1
	eors r5, r4
	adds r0, r5, 0
	bl SetPokemonCryStereo
	ldr r0, =gUnknown_02039B48
	strb r4, [r0]
_080BADF8:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BADD8

	thumb_func_start sub_80BAE08
sub_80BAE08: @ 80BAE08
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	strb r2, [r1]
	strb r2, [r1, 0x1]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_085EE61D
	mov r1, sp
	ldrb r3, [r1]
	movs r1, 0x68
	movs r2, 0x30
	bl sub_80BAB68
	ldr r4, =gUnknown_085EE628
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC6
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r4, 0
	movs r2, 0x30
	bl sub_80BAB68
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BAE08

	thumb_func_start sub_80BAE5C
sub_80BAE5C: @ 80BAE5C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080BAEAE
	cmp r4, 0x12
	bhi _080BAE80
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	b _080BAE82
	.pool
_080BAE80:
	movs r4, 0
_080BAE82:
	adds r0, r4, 0
	bl sub_8098758
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	movs r3, 0xD1
	lsls r3, 1
	movs r0, 0x1
	bl LoadBgTiles
	adds r0, r4, 0
	bl sub_8098758
	ldr r0, [r0, 0x4]
	movs r1, 0x70
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BAEAE:
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080BAEFE
	cmp r4, 0
	beq _080BAED0
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	b _080BAED2
	.pool
_080BAED0:
	movs r4, 0x13
_080BAED2:
	adds r0, r4, 0
	bl sub_8098758
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	movs r3, 0xD1
	lsls r3, 1
	movs r0, 0x1
	bl LoadBgTiles
	adds r0, r4, 0
	bl sub_8098758
	ldr r0, [r0, 0x4]
	movs r1, 0x70
	movs r2, 0x20
	bl gpu_pal_apply
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BAEFE:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BAE5C

	thumb_func_start sub_80BAF0C
sub_80BAF0C: @ 80BAF0C
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r6, r0, 24
	movs r5, 0
	ldr r1, =gUnknown_085EE640
	ldrb r0, [r1]
	ldr r7, =gUnknown_085EE635
	cmp r0, 0xFF
	beq _080BAF44
	adds r2, r1, 0
_080BAF28:
	mov r0, sp
	adds r1, r0, r5
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080BAF44
	cmp r5, 0x5
	bls _080BAF28
_080BAF44:
	adds r0, r6, 0
	movs r1, 0xA
	bl __udivsi3
	adds r2, r0, 0
	lsls r0, r2, 24
	cmp r0, 0
	beq _080BAF80
	mov r0, sp
	adds r1, r0, r5
	adds r0, r2, 0
	adds r0, 0xA1
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	mov r1, sp
	adds r4, r1, r5
	adds r0, r6, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4]
	b _080BAF9E
	.pool
_080BAF80:
	mov r0, sp
	adds r4, r0, r5
	adds r0, r6, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, sp
	adds r1, r0, r5
	movs r0, 0x77
	strb r0, [r1]
_080BAF9E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, sp
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r7, 0
	movs r1, 0x68
	movs r2, 0x50
	movs r3, 0
	bl sub_80BAB68
	mov r0, sp
	movs r1, 0x80
	movs r2, 0x50
	movs r3, 0x1
	bl sub_80BAB68
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80BAF0C

	thumb_func_start sub_80BAFCC
sub_80BAFCC: @ 80BAFCC
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_030022C0
	ldrh r1, [r2, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080BAFF8
	cmp r3, 0x1
	bhi _080BAFF0
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080BAFF2
	.pool
_080BAFF0:
	movs r3, 0
_080BAFF2:
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BAFF8:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080BB01C
	cmp r3, 0
	beq _080BB014
	subs r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080BB016
	.pool
_080BB014:
	movs r3, 0x2
_080BB016:
	ldr r1, =gUnknown_02039B48
	movs r0, 0x1
	strb r0, [r1]
_080BB01C:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80BAFCC

	thumb_func_start sub_80BB028
sub_80BB028: @ 80BB028
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	strb r2, [r1]
	strb r2, [r1, 0x1]
	strb r2, [r1, 0x2]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, =gUnknown_085EE647
	mov r0, sp
	ldrb r3, [r0]
	adds r0, r4, 0
	movs r1, 0x68
	movs r2, 0x40
	bl sub_80BAB68
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldr r0, =gUnknown_085EE654
	mov r8, r0
	movs r0, 0x1
	mov r1, r8
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	ldr r6, =gUnknown_085EE65D
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	subs r5, 0x5E
	subs r4, r5
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	adds r4, 0x68
	lsls r4, 24
	lsrs r4, 24
	mov r0, sp
	ldrb r3, [r0, 0x1]
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0x40
	bl sub_80BAB68
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xC6
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r3, [r0, 0x2]
	adds r0, r6, 0
	movs r2, 0x40
	bl sub_80BAB68
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB028

	thumb_func_start sub_80BB0D0
sub_80BB0D0: @ 80BB0D0
	push {lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_085EE589
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB0D0

	thumb_func_start sub_80BB104
sub_80BB104: @ 80BB104
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r4, 0
	ldr r5, =gUnknown_0855C664
_080BB114:
	lsls r0, r4, 2
	adds r0, r5
	ldr r2, [r0]
	lsls r0, r4, 4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080BB114
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB104

	thumb_func_start sub_80BB154
sub_80BB154: @ 80BB154
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r5, 0x7
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD1
	lsls r1, 1
	movs r2, 0x1
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1B
	mov r8, r0
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a3
	movs r2, 0x2
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD2
	lsls r1, 1
	movs r2, 0x1C
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	movs r6, 0x2
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a5
	movs r2, 0x1
	movs r3, 0x1
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a7
	movs r2, 0x1C
	movs r3, 0x1
	bl FillBgTilemapBufferRect
	movs r7, 0xD4
	lsls r7, 1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x3
	bl FillBgTilemapBufferRect
	ldr r0, =0x000001a9
	mov r10, r0
	mov r0, r8
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x2
	movs r3, 0x3
	bl FillBgTilemapBufferRect
	movs r0, 0xD5
	lsls r0, 1
	mov r9, r0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	mov r1, r9
	movs r2, 0x1C
	movs r3, 0x3
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD1
	lsls r1, 1
	movs r2, 0x1
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	movs r0, 0x1A
	mov r8, r0
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a3
	movs r2, 0x2
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD2
	lsls r1, 1
	movs r2, 0x1C
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	str r4, [sp]
	movs r6, 0x12
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a5
	movs r2, 0x1
	movs r3, 0x5
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	ldr r1, =0x000001a7
	movs r2, 0x1C
	movs r3, 0x5
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x13
	bl FillBgTilemapBufferRect
	mov r0, r8
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x2
	movs r3, 0x13
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	mov r1, r9
	movs r2, 0x1C
	movs r3, 0x13
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80BB154

	.align 2, 0 @ Don't pad with nop.
