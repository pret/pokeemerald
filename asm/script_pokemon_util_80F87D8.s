	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F87D8
sub_80F87D8: @ 80F87D8
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_02039E00
	ldrb r3, [r1, 0x15]
	ldr r4, =0x000013bc
	adds r0, r2, r4
	strh r3, [r0]
	adds r0, r1, 0
	adds r0, 0x55
	ldrb r3, [r0]
	adds r4, 0x2
	adds r0, r2, r4
	strh r3, [r0]
	adds r1, 0x95
	ldrb r0, [r1]
	movs r1, 0x9E
	lsls r1, 5
	adds r2, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F87D8

	thumb_func_start sub_80F8814
sub_80F8814: @ 80F8814
	push {lr}
	ldr r0, =gUnknown_020375E2
	ldrb r0, [r0]
	adds r1, r0, 0
	cmp r0, 0x1
	beq _080F883A
	cmp r0, 0x1
	bgt _080F8830
	cmp r0, 0
	beq _080F8836
	b _080F8842
	.pool
_080F8830:
	cmp r1, 0x2
	beq _080F883E
	b _080F8842
_080F8836:
	movs r1, 0x3
	b _080F8844
_080F883A:
	movs r1, 0x4
	b _080F8844
_080F883E:
	movs r1, 0x5
	b _080F8844
_080F8842:
	movs r1, 0x64
_080F8844:
	ldr r0, =gUnknown_020375E0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8814

	thumb_func_start sub_80F8850
sub_80F8850: @ 80F8850
	push {lr}
	bl sub_80F8264
	bl sub_80F8290
	bl sub_80F8438
	pop {r0}
	bx r0
	thumb_func_end sub_80F8850

	thumb_func_start sub_80F8864
sub_80F8864: @ 80F8864
	push {lr}
	ldr r0, =gUnknown_02039F2C
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080F88A4
	lsls r0, 2
	ldr r1, =_080F8880
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F8880:
	.4byte _080F8894
	.4byte _080F8898
	.4byte _080F889C
	.4byte _080F88A0
	.4byte _080F88A4
_080F8894:
	movs r1, 0x8
	b _080F88A6
_080F8898:
	movs r1, 0x9
	b _080F88A6
_080F889C:
	movs r1, 0xA
	b _080F88A6
_080F88A0:
	movs r1, 0xB
	b _080F88A6
_080F88A4:
	movs r1, 0xC
_080F88A6:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, 5
	adds r0, r1
	ldr r1, =0x00002e98
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, 0
	bne _080F88CC
	ldr r0, =gUnknown_020375E0
	strh r1, [r0]
	b _080F88D2
	.pool
_080F88CC:
	ldr r1, =gUnknown_020375E0
	movs r0, 0x1
	strh r0, [r1]
_080F88D2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8864

	thumb_func_start sub_80F88DC
sub_80F88DC: @ 80F88DC
	push {lr}
	movs r0, 0xFF
	bl sub_80DEDA8
	pop {r0}
	bx r0
	thumb_func_end sub_80F88DC

	thumb_func_start sub_80F88E8
sub_80F88E8: @ 80F88E8
	push {lr}
	ldr r0, =gUnknown_02039F20
	ldr r1, =gUnknown_02039F25
	ldrb r2, [r1]
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F8930
	ldr r0, =gUnknown_02039F2E
	ldrh r0, [r0]
	cmp r0, 0x3
	bne _080F8930
	ldr r1, =gUnknown_02039F08
	lsls r0, r2, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, =0x0000031f
	cmp r1, r0
	ble _080F8930
	ldr r1, =gUnknown_020375E0
	movs r0, 0x1
	b _080F8934
	.pool
_080F8930:
	ldr r1, =gUnknown_020375E0
	movs r0, 0
_080F8934:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F88E8

	thumb_func_start sub_80F8940
sub_80F8940: @ 80F8940
	push {lr}
	movs r3, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002f98
	adds r1, r0, r2
	movs r2, 0x4
_080F894E:
	ldrh r0, [r1]
	cmp r0, 0
	beq _080F895A
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_080F895A:
	adds r1, 0x20
	subs r2, 0x1
	cmp r2, 0
	bge _080F894E
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F8940

	thumb_func_start sub_80F8970
sub_80F8970: @ 80F8970
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gUnknown_02039F00
	mov r12, r0
	ldr r1, =gUnknown_020375E4
	mov r9, r1
	ldr r2, =gUnknown_02039E02
	mov r10, r2
	mov r2, r12
	mov r1, sp
	movs r6, 0x3
_080F898E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _080F898E
	movs r6, 0
_080F899E:
	movs r1, 0x3
	cmp r1, r6
	ble _080F89C8
_080F89A4:
	subs r5, r1, 0x1
	lsls r0, r5, 1
	mov r4, sp
	adds r3, r4, r0
	lsls r0, r1, 1
	adds r2, r4, r0
	ldrh r4, [r3]
	movs r7, 0
	ldrsh r1, [r3, r7]
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080F89C2
	strh r4, [r2]
	strh r0, [r3]
_080F89C2:
	adds r1, r5, 0
	cmp r1, r6
	bgt _080F89A4
_080F89C8:
	adds r6, 0x1
	cmp r6, 0x2
	ble _080F899E
	mov r2, r9
	ldrh r0, [r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	lsls r0, 16
	asrs r4, r0, 16
	adds r3, r0, 0
	mov r1, sp
	mov r5, r9
_080F89E8:
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080F8A02
	lsls r0, r2, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r2, r0, 24
	ldrh r7, [r5]
	cmp r6, r7
	bne _080F8A02
	mov r8, r2
_080F8A02:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _080F89E8
	movs r6, 0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	asrs r1, r3, 16
	lsls r2, 24
	mov r9, r2
	cmp r0, r1
	beq _080F8A30
	adds r2, r1, 0
	mov r1, sp
_080F8A20:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	bgt _080F8A30
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bne _080F8A20
_080F8A30:
	lsls r0, r6, 24
	lsrs r7, r0, 24
	mov r2, r8
	movs r6, 0
	asrs r1, r3, 16
	mov r5, r12
	movs r4, 0
	ldrsh r0, [r5, r4]
	b _080F8A66
	.pool
_080F8A50:
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080F8A56:
	adds r6, 0x1
	cmp r6, 0x3
	bgt _080F8A6E
	lsls r0, r6, 1
	add r0, r12
	asrs r1, r3, 16
	movs r5, 0
	ldrsh r0, [r0, r5]
_080F8A66:
	cmp r1, r0
	bne _080F8A56
	cmp r2, 0x1
	bne _080F8A50
_080F8A6E:
	lsls r4, r6, 6
	mov r0, r10
	adds r1, r4, r0
	ldr r0, =gStringVar1
	bl StringCopy
	ldr r5, =gStringVar2
	mov r0, r10
	adds r0, 0xB
	adds r4, r0
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringCopy
	adds r0, r5, 0
	bl sub_81DB5AC
	mov r1, r9
	asrs r0, r1, 24
	cmp r0, 0x1
	beq _080F8A9C
	cmp r8, r0
	bne _080F8AB0
_080F8A9C:
	ldr r0, =gUnknown_020375E4
	strh r7, [r0]
	b _080F8AB6
	.pool
_080F8AB0:
	ldr r1, =gUnknown_020375E4
	adds r0, r7, 0x4
	strh r0, [r1]
_080F8AB6:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8970

	thumb_func_start sub_80F8ACC
sub_80F8ACC: @ 80F8ACC
	push {lr}
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8ACC

	thumb_func_start sub_80F8ADC
sub_80F8ADC: @ 80F8ADC
	push {lr}
	ldr r0, =sub_812FDEC
	bl SetMainCallback2
	ldr r1, =gUnknown_030022C0
	ldr r0, =sub_80F8ACC
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8ADC

	thumb_func_start sub_80F8AFC
sub_80F8AFC: @ 80F8AFC
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F8B7C
	movs r3, 0
	ldr r0, =gUnknown_02039F30
	adds r4, r0, 0
	ldr r5, =gUnknown_02039E00
	ldrb r0, [r4]
	cmp r3, r0
	bge _080F8B50
	adds r2, r5, 0
	ldr r1, =gUnknown_020229E8
_080F8B1C:
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r0, 0x1
	bhi _080F8B44
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _080F8B40
	movs r0, 0xEB
	b _080F8B42
	.pool
_080F8B40:
	movs r0, 0xEC
_080F8B42:
	strb r0, [r2, 0x15]
_080F8B44:
	adds r2, 0x40
	adds r1, 0x1C
	adds r3, 0x1
	ldrb r0, [r4]
	cmp r3, r0
	blt _080F8B1C
_080F8B50:
	ldr r0, =0x00004010
	ldrb r1, [r5, 0x15]
	bl VarSet
	ldr r0, =0x00004011
	adds r1, r5, 0
	adds r1, 0x55
	ldrb r1, [r1]
	bl VarSet
	ldr r0, =0x00004012
	adds r1, r5, 0
	adds r1, 0x95
	ldrb r1, [r1]
	bl VarSet
	ldr r0, =0x00004013
	adds r1, r5, 0
	adds r1, 0xD5
	ldrb r1, [r1]
	bl VarSet
_080F8B7C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8AFC

	thumb_func_start sub_80F8B94
sub_80F8B94: @ 80F8B94
	push {r4-r7,lr}
	ldr r1, =gUnknown_0300301C
	movs r0, 0xC
	strb r0, [r1]
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F8C6E
	movs r5, 0
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r5, r0
	bge _080F8C6E
	movs r7, 0
	movs r6, 0x60
	movs r4, 0xB0
	lsls r4, 17
_080F8BBA:
	ldr r0, =gUnknown_0858D8EC
	adds r0, r5, r0
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl GetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02037350
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02020630
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_020229E8
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r0, 0x1
	bhi _080F8C38
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _080F8C2C
	lsrs r1, r4, 16
	ldr r0, =gFieldObjectPalette33
	b _080F8C42
	.pool
_080F8C2C:
	lsrs r1, r4, 16
	ldr r0, =gFieldObjectPalette34
	b _080F8C42
	.pool
_080F8C38:
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _080F8C50
	lsrs r1, r4, 16
	ldr r0, =gFieldObjectPalette8
_080F8C42:
	movs r2, 0x20
	bl gpu_pal_apply
	b _080F8C5A
	.pool
_080F8C50:
	lsrs r1, r4, 16
	ldr r0, =gFieldObjectPalette17
	movs r2, 0x20
	bl gpu_pal_apply
_080F8C5A:
	movs r0, 0x80
	lsls r0, 13
	adds r4, r0
	adds r7, 0x1C
	adds r6, 0x10
	adds r5, 0x1
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r5, r0
	blt _080F8BBA
_080F8C6E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8B94

	thumb_func_start sub_80F8C7C
sub_80F8C7C: @ 80F8C7C
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gUnknown_02039F24
	ldrb r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x46
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	cmp r0, 0
	bne _080F8D18
	ldr r0, =gUnknown_02039F20
	ldr r1, =gUnknown_02039F25
	ldrb r2, [r1]
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F8D18
	ldr r0, =gUnknown_02039F2E
	ldrh r0, [r0]
	cmp r0, 0x3
	bne _080F8D18
	ldr r1, =gUnknown_02039F08
	lsls r0, r2, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, =0x0000031f
	cmp r1, r0
	ble _080F8D18
	movs r1, 0x1
	mov r0, sp
	strb r1, [r0]
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x46
	mov r2, sp
	bl pokemon_setattr
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	bl sub_80EE5A4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8CF6
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x46
	bl sub_80EE4DC
_080F8CF6:
	movs r0, 0x1
	b _080F8D1A
	.pool
_080F8D18:
	movs r0, 0
_080F8D1A:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F8C7C

	thumb_func_start sub_80F8D24
sub_80F8D24: @ 80F8D24
	movs r0, 0
	bx lr
	thumb_func_end sub_80F8D24

	thumb_func_start sub_80F8D28
sub_80F8D28: @ 80F8D28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r7, =sub_80F8EE8
	adds r0, r7, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080F8D44
	b _080F8E9C
_080F8D44:
	bl init_uns_table_pokemon_copy
	movs r0, 0xA
	mov r9, r0
	movs r1, 0x3
	mov r10, r1
	ldr r2, =gUnknown_02039E00
	ldr r4, =gUnknown_020375E4
	ldrh r1, [r4]
	lsls r1, 6
	adds r0, r1, r2
	ldrh r6, [r0]
	adds r0, r2, 0
	adds r0, 0x38
	adds r0, r1, r0
	ldr r5, [r0]
	adds r2, 0x3C
	adds r1, r2
	ldr r1, [r1]
	mov r8, r1
	adds r0, r7, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
	strh r6, [r0, 0xA]
	ldr r1, =gUnknown_02039F25
	ldrh r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080F8DC4
	lsls r0, r6, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	adds r2, r6, 0
	adds r3, r5, 0
	bl DecompressMonPic_DetectFrontOrBack_2
	b _080F8DD8
	.pool
_080F8DC4:
	lsls r0, r6, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	adds r2, r6, 0
	adds r3, r5, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
_080F8DD8:
	adds r0, r6, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_806E7CC
	adds r4, r0, 0
	bl LoadCompressedObjectPalette
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	ldrh r1, [r4, 0x4]
	strh r1, [r0, 0x2]
	mov r1, r9
	adds r1, 0x1
	lsls r1, 19
	movs r2, 0x80
	lsls r2, 14
	adds r1, r2
	asrs r1, 16
	mov r3, r10
	lsls r2, r3, 19
	movs r3, 0xA0
	lsls r3, 14
	adds r2, r3
	asrs r2, 16
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F8E58
	movs r0, 0x4
	ands r0, r1
	lsls r4, r5, 4
	cmp r0, 0
	bne _080F8E6C
	adds r0, r4, r5
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_806ED40
	b _080F8E6C
	.pool
_080F8E58:
	lsls r4, r5, 4
	adds r0, r4, r5
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_806ED40
_080F8E6C:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	mov r2, r10
	strh r2, [r0, 0x10]
	ldr r3, =gUnknown_02020630
	adds r1, r4, r5
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =DummyObjectCallback
	str r2, [r0]
	adds r1, r3
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
_080F8E9C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8D28

	thumb_func_start sub_80F8EB8
sub_80F8EB8: @ 80F8EB8
	push {lr}
	ldr r0, =sub_80F8EE8
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080F8EDC
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	bl sub_805F094
_080F8EDC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8EB8

	thumb_func_start sub_80F8EE8
sub_80F8EE8: @ 80F8EE8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _080F8F98
	lsls r0, 2
	ldr r1, =_080F8F14
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F8F14:
	.4byte _080F8F78
	.4byte _080F8F28
	.4byte _080F8F98
	.4byte _080F8F42
	.4byte _080F8F84
_080F8F28:
	movs r0, 0xA
	movs r1, 0x3
	movs r2, 0x8
	movs r3, 0x8
	bl CreateWindowFromRect
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	movs r1, 0x1
	bl SetStandardWindowBorderStyle
	b _080F8F78
_080F8F42:
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r4, r0, r1
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	bl GetObjectPaletteTagBySlot
	lsls r0, 16
	lsrs r0, 16
	bl FreeObjectPaletteByTag
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	cmp r0, 0
	beq _080F8F72
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
_080F8F72:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_080F8F78:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _080F8F98
	.pool
_080F8F84:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x12]
	bl sub_80E2A78
	adds r0, r4, 0
	bl DestroyTask
_080F8F98:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F8EE8

	thumb_func_start sub_80F8FA0
sub_80F8FA0: @ 80F8FA0
	push {r4,lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F8FD8
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080F8FD8
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080F8FD8
	ldr r4, =gUnknown_020375F0
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	b _080F8FDE
	.pool
_080F8FD8:
	ldr r1, =gUnknown_020375F0
	movs r0, 0x4
	strh r0, [r1]
_080F8FDE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8FA0

	thumb_func_start sub_80F8FE8
sub_80F8FE8: @ 80F8FE8
	push {r4,lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F9020
	ldr r2, =gUnknown_030060B8
	ldr r1, [r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00006073
	adds r0, r1
	str r0, [r2]
	lsrs r0, 16
	ldr r4, =gUnknown_020375F0
	b _080F902A
	.pool
_080F9020:
	ldr r4, =gUnknown_020375F0
	bl Random
	lsls r0, 16
	lsrs r0, 16
_080F902A:
	ldrh r1, [r4]
	bl __umodsi3
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8FE8

	thumb_func_start sub_80F903C
sub_80F903C: @ 80F903C
	ldr r2, =gUnknown_030060B8
	ldr r1, [r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00006073
	adds r0, r1
	str r0, [r2]
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_80F903C

	thumb_func_start sub_80F905C
sub_80F905C: @ 80F905C
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080F9074
	movs r0, 0
	b _080F907E
	.pool
_080F9074:
	ldr r0, =sub_80F9088
	movs r1, 0x5
	bl CreateTask
	movs r0, 0x1
_080F907E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F905C

	thumb_func_start sub_80F9088
sub_80F9088: @ 80F9088
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
	cmp r0, 0
	beq _080F90C0
	cmp r0, 0x1
	beq _080F90CE
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080F90D4
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r5, 0
	bl DestroyTask
	b _080F90D4
	.pool
_080F90C0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080F90D4
	bl sub_800ADF8
_080F90CE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080F90D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F9088

	thumb_func_start sub_80F90DC
sub_80F90DC: @ 80F90DC
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F90FE
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F90FE
	bl sub_800E0E8
	movs r0, 0x8
	movs r1, 0x8
	bl sub_800DFB4
_080F90FE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F90DC

	thumb_func_start sub_80F910C
sub_80F910C: @ 80F910C
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080F9126
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F9126
	bl sub_800E084
_080F9126:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F910C

	thumb_func_start sub_80F9134
sub_80F9134: @ 80F9134
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080F914C
	movs r0, 0
	b _080F914E
	.pool
_080F914C:
	movs r0, 0x1
_080F914E:
	pop {r1}
	bx r1
	thumb_func_end sub_80F9134

	thumb_func_start sub_80F9154
sub_80F9154: @ 80F9154
	ldr r1, =gUnknown_02039F2A
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80F9154

	thumb_func_start sub_80F9160
sub_80F9160: @ 80F9160
	push {lr}
	ldr r0, =gUnknown_02039F2A
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080F9178
	movs r0, 0
	b _080F917A
	.pool
_080F9178:
	movs r0, 0x1
_080F917A:
	pop {r1}
	bx r1
	thumb_func_end sub_80F9160

	thumb_func_start sp000_heal_pokemon
sp000_heal_pokemon: @ 80F9180
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_020244E9
	ldrb r0, [r0]
	cmp r8, r0
	bcs _080F922C
	ldr r1, =gPlayerParty
	mov r10, r1
	mov r6, sp
_080F919E:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	add r4, r10
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	lsls r1, r0, 16
	strb r0, [r6]
	lsrs r1, 24
	strb r1, [r6, 0x1]
	adds r0, r4, 0
	movs r1, 0x39
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	lsls r0, 24
	lsrs r7, r0, 24
	movs r5, 0
	movs r1, 0x1
	add r1, r8
	mov r9, r1
_080F91D4:
	adds r1, r5, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	adds r1, r7, 0
	adds r2, r5, 0
	bl CalcPPWithPPUps
	strb r0, [r6]
	adds r1, r5, 0
	adds r1, 0x11
	adds r0, r4, 0
	mov r2, sp
	bl pokemon_setattr
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080F91D4
	movs r0, 0
	strb r0, [r6]
	strb r0, [r6, 0x1]
	strb r0, [r6, 0x2]
	strb r0, [r6, 0x3]
	movs r1, 0x64
	mov r0, r8
	muls r0, r1
	add r0, r10
	movs r1, 0x37
	mov r2, sp
	bl pokemon_setattr
	mov r1, r9
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_020244E9
	ldrb r0, [r0]
	cmp r8, r0
	bcc _080F919E
_080F922C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp000_heal_pokemon

	thumb_func_start sub_80F9244
@ void sub_80F9244(s16 species_num, u8 level, int held_item)
sub_80F9244: @ 80F9244
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x78
	adds r5, r0, 0
	adds r3, r1, 0
	adds r4, r2, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 16
	lsrs r0, r4, 16
	mov r8, r0
	add r6, sp, 0x14
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r3, 0
	movs r3, 0x20
	bl create_pokemon_set_level
	add r0, sp, 0x10
	mov r1, r8
	strb r1, [r0]
	lsrs r4, 24
	strb r4, [r0, 0x1]
	adds r0, r6, 0
	movs r1, 0xC
	add r2, sp, 0x10
	bl pokemon_setattr
	adds r0, r6, 0
	bl pokemon_catch
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r4, 0x1
	bgt _080F92B8
	cmp r4, 0
	blt _080F92B8
	adds r0, r5, 0
	movs r1, 0x2
	bl pokedex_flag_operation
	adds r0, r5, 0
	movs r1, 0x3
	bl pokedex_flag_operation
_080F92B8:
	adds r0, r4, 0
	add sp, 0x78
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F9244

	thumb_func_start sub_80F92C8
sub_80F92C8: @ 80F92C8
	push {lr}
	sub sp, 0x68
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	movs r2, 0x1
	bl sub_8070954
	add r2, sp, 0x64
	movs r0, 0x1
	strb r0, [r2]
	mov r0, sp
	movs r1, 0x2D
	bl pokemon_setattr
	mov r0, sp
	bl pokemon_catch
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x68
	pop {r1}
	bx r1
	thumb_func_end sub_80F92C8

	thumb_func_start sub_80F92F8
sub_80F92F8: @ 80F92F8
	push {lr}
	bl sub_806B5C4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	beq _080F9314
	cmp r1, 0x1
	bgt _080F9310
	cmp r1, 0
	beq _080F9314
	b _080F9318
_080F9310:
	cmp r1, 0x2
	bne _080F9318
_080F9314:
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
_080F9318:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F92F8

	thumb_func_start sub_80F9320
sub_80F9320: @ 80F9320
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
	movs r7, 0xCE
	lsls r7, 1
_080F932C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080F9360
	cmp r0, r7
	beq _080F9360
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	cmp r0, r6
	bne _080F9360
	movs r0, 0x1
	b _080F9368
	.pool
_080F9360:
	adds r5, 0x1
	cmp r5, 0x5
	ble _080F932C
	movs r0, 0
_080F9368:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80F9320

	thumb_func_start sub_80F9370
sub_80F9370: @ 80F9370
	push {r4,lr}
	movs r0, 0xAF
	bl sub_80F9320
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r4, 0x1
	bne _080F9392
	movs r0, 0xAF
	bl ItemIdToBerryType
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar1
	bl GetBerryNameByBerryType
_080F9392:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F9370

	thumb_func_start sub_80F93A0
sub_80F93A0: @ 80F93A0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r7, r2, 16
	lsrs r6, r7, 16
	bl zero_enemy_party_data
	ldr r0, =gEnemyParty
	mov r8, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x20
	bl create_pokemon_set_level
	cmp r6, 0
	beq _080F93EE
	add r0, sp, 0x10
	strb r6, [r0]
	adds r1, r0, 0
	lsrs r0, r7, 24
	strb r0, [r1, 0x1]
	mov r0, r8
	movs r1, 0xC
	add r2, sp, 0x10
	bl pokemon_setattr
_080F93EE:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F93A0

	thumb_func_start sub_80F9400
sub_80F9400: @ 80F9400
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r2, 24
	cmp r3, 0x6
	bls _080F941C
	ldr r0, =gUnknown_020244E9
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_080F941C:
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_80691F4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9400

	thumb_func_start sub_80F9438
sub_80F9438: @ 80F9438
	push {lr}
	ldr r0, =gUnknown_030022C0
	ldr r1, =sub_80F9460
	str r1, [r0, 0x8]
	ldr r0, =0x000040cf
	movs r1, 0x9
	bl VarSet
	movs r0, 0
	bl sub_81B8518
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9438

	thumb_func_start sub_80F9460
sub_80F9460: @ 80F9460
	push {lr}
	ldr r0, =gUnknown_0203CEF8
	ldrb r1, [r0]
	cmp r1, 0
	bne _080F9478
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
	b _080F947E
	.pool
_080F9478:
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	strh r0, [r1]
_080F947E:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9460

	thumb_func_start sub_80F9490
sub_80F9490: @ 80F9490
	push {lr}
	ldr r1, =gUnknown_030022C0
	ldr r0, =sub_80F94B8
	str r0, [r1, 0x8]
	ldr r0, =gUnknown_020375E0
	ldrb r0, [r0]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	bl sub_81B8518
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9490

	thumb_func_start sub_80F94B8
sub_80F94B8: @ 80F94B8
	push {lr}
	ldr r0, =gUnknown_0203CEF8
	ldrb r1, [r0]
	cmp r1, 0
	bne _080F94D0
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
	b _080F94D6
	.pool
_080F94D0:
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
	strh r0, [r1]
_080F94D6:
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F94B8

	thumb_func_start sub_80F94E8
sub_80F94E8: @ 80F94E8
	push {r4-r7,lr}
	sub sp, 0x198
	add r0, sp, 0x190
	movs r1, 0
	str r1, [r0]
	ldr r2, =0x05000064
	mov r1, sp
	bl CpuSet
	movs r5, 0
	movs r7, 0x64
	ldr r6, =gPlayerParty
	mov r4, sp
_080F9502:
	ldr r0, =gUnknown_0203CEF8
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080F951C
	subs r0, 0x1
	adds r1, r0, 0
	muls r1, r7
	adds r1, r6
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
_080F951C:
	adds r4, 0x64
	adds r5, 0x1
	cmp r5, 0x3
	ble _080F9502
	add r0, sp, 0x194
	movs r1, 0
	str r1, [r0]
	ldr r4, =gPlayerParty
	ldr r2, =0x05000096
	adds r1, r4, 0
	bl CpuSet
	mov r5, sp
	add r6, sp, 0x12C
_080F9538:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x64
	adds r4, 0x64
	cmp r5, r6
	ble _080F9538
	bl calc_player_party_count
	add sp, 0x198
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F94E8

	.align 2, 0 @ Don't pad with nop.
