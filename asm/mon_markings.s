	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_811F90C
sub_811F90C: @ 811F90C
	ldr r1, =gUnknown_0203A124
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811F90C

	thumb_func_start sub_811F918
sub_811F918: @ 811F918
	push {lr}
	sub sp, 0x4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8098758
	ldr r3, =gUnknown_0203A124
	ldr r2, [r3]
	ldr r1, [r0]
	str r1, [r2, 0x2C]
	ldr r0, [r0, 0x4]
	str r0, [r2, 0x30]
	ldr r0, =0x000010b4
	adds r2, r0
	movs r1, 0
	strb r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldr r1, [r3]
	adds r1, 0x34
	ldr r2, =0x01000800
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F918

	thumb_func_start sub_811F960
sub_811F960: @ 811F960
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203A124
	ldr r1, [r0]
	ldr r2, =0x000010b4
	adds r0, r1, r2
	ldrb r2, [r0]
	lsls r0, r2, 8
	adds r0, 0x34
	adds r5, r1, r0
	cmp r2, 0xD
	beq _0811FA30
	cmp r2, 0xD
	bgt _0811F988
	cmp r2, 0
	beq _0811F98E
	b _0811F9D8
	.pool
_0811F988:
	cmp r2, 0xE
	beq _0811FA7C
	b _0811F9D8
_0811F98E:
	ldr r0, [r1, 0x2C]
	adds r1, r5, 0
	movs r2, 0x8
	bl CpuFastSet
	movs r4, 0
	adds r7, r5, 0
	adds r7, 0xE0
_0811F99E:
	ldr r6, =gUnknown_0203A124
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	adds r0, 0x20
	adds r4, 0x1
	lsls r1, r4, 5
	adds r1, r5, r1
	movs r2, 0x8
	bl CpuFastSet
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0x5
	bls _0811F99E
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	adds r0, 0x40
	adds r1, r7, 0
	movs r2, 0x8
	bl CpuFastSet
	ldr r1, [r6]
	ldr r0, =0x000010b4
	adds r1, r0
	b _0811FA1E
	.pool
_0811F9D8:
	ldr r0, =gUnknown_0203A124
	ldr r0, [r0]
	ldr r0, [r0, 0x2C]
	adds r0, 0x60
	adds r1, r5, 0
	movs r2, 0x8
	bl CpuFastSet
	movs r4, 0
	adds r7, r5, 0
	adds r7, 0xE0
_0811F9EE:
	ldr r6, =gUnknown_0203A124
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	adds r0, 0x80
	adds r4, 0x1
	lsls r1, r4, 5
	adds r1, r5, r1
	movs r2, 0x8
	bl CpuFastSet
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0x5
	bls _0811F9EE
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	adds r0, 0xA0
	adds r1, r7, 0
	movs r2, 0x8
	bl CpuFastSet
	ldr r1, [r6]
	ldr r2, =0x000010b4
	adds r1, r2
_0811FA1E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0811FA88
	.pool
_0811FA30:
	ldr r0, [r1, 0x2C]
	adds r0, 0xC0
	adds r1, r5, 0
	movs r2, 0x8
	bl CpuFastSet
	movs r4, 0
	adds r7, r5, 0
	adds r7, 0xE0
_0811FA42:
	ldr r6, =gUnknown_0203A124
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	adds r0, 0xE0
	adds r4, 0x1
	lsls r1, r4, 5
	adds r1, r5, r1
	movs r2, 0x8
	bl CpuFastSet
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0x5
	bls _0811FA42
	ldr r0, [r6]
	ldr r0, [r0, 0x2C]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x8
	bl CpuFastSet
	ldr r1, [r6]
	ldr r2, =0x000010b4
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0811FA7C:
	movs r0, 0
	b _0811FA8A
	.pool
_0811FA88:
	movs r0, 0x1
_0811FA8A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_811F960

	thumb_func_start sub_811FA90
sub_811FA90: @ 811FA90
	push {lr}
	bl sub_811F918
_0811FA96:
	bl sub_811F960
	lsls r0, 24
	cmp r0, 0
	bne _0811FA96
	pop {r0}
	bx r0
	thumb_func_end sub_811FA90

	thumb_func_start sub_811FAA4
sub_811FAA4: @ 811FAA4
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	ldr r2, =gUnknown_0203A124
	ldr r3, [r2]
	movs r1, 0
	strb r1, [r3, 0x5]
	ldr r1, [r2]
	strb r0, [r1, 0x4]
	movs r3, 0
	adds r7, r2, 0
	adds r4, r7, 0
	movs r2, 0x1
_0811FAC2:
	ldr r0, [r4]
	adds r1, r0, 0x6
	adds r1, r3
	ldrb r0, [r0, 0x4]
	asrs r0, r3
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _0811FAC2
	lsls r0, r5, 16
	asrs r0, 16
	lsls r1, r6, 16
	asrs r1, 16
	ldr r3, [r7]
	ldrh r2, [r3]
	ldrh r3, [r3, 0x2]
	bl sub_811FC80
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811FAA4

	thumb_func_start sub_811FAF8
sub_811FAF8: @ 811FAF8
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, =gUnknown_0203A124
_0811FAFE:
	ldr r0, [r4]
	ldrh r0, [r0]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r0, 16
	bl FreeObjectTilesByTag
	ldr r0, [r4]
	ldrh r0, [r0, 0x2]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r0, 16
	bl FreeObjectPaletteByTag
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1
	bls _0811FAFE
	movs r5, 0
	ldr r6, =gUnknown_0203A124
_0811FB28:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _0811FB9A
	bl DestroySprite
	ldr r0, [r6]
	adds r0, 0xC
	adds r0, r4
	movs r1, 0
	str r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1
	bls _0811FB28
	movs r5, 0
	ldr r6, =gUnknown_0203A124
_0811FB52:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0x14
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _0811FB9A
	bl DestroySprite
	ldr r0, [r6]
	adds r0, 0x14
	adds r0, r4
	movs r7, 0
	str r7, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _0811FB52
	ldr r4, =gUnknown_0203A124
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	beq _0811FB8A
	bl DestroySprite
	ldr r0, [r4]
	str r7, [r0, 0x24]
_0811FB8A:
	ldr r0, [r4]
	ldr r0, [r0, 0x28]
	cmp r0, 0
	beq _0811FB9A
	bl DestroySprite
	ldr r0, [r4]
	str r7, [r0, 0x28]
_0811FB9A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811FAF8

	thumb_func_start sub_811FBA4
sub_811FBA4: @ 811FBA4
	push {r4,r5,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _0811FBDC
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0203A124
	ldr r1, [r2]
	ldrb r0, [r1, 0x5]
	subs r0, 0x1
	strb r0, [r1, 0x5]
	lsls r0, 24
	cmp r0, 0
	bge _0811FC64
	ldr r1, [r2]
	movs r0, 0x5
	strb r0, [r1, 0x5]
	b _0811FC64
	.pool
_0811FBDC:
	movs r0, 0x80
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0811FC0C
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0203A124
	ldr r1, [r2]
	ldrb r0, [r1, 0x5]
	adds r0, 0x1
	strb r0, [r1, 0x5]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x5
	ble _0811FC64
	ldr r0, [r2]
	strb r5, [r0, 0x5]
	b _0811FC64
	.pool
_0811FC0C:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0811FC68
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_0203A124
	ldr r0, [r2]
	movs r1, 0x5
	ldrsb r1, [r0, r1]
	cmp r1, 0x4
	beq _0811FC40
	cmp r1, 0x5
	beq _0811FC76
	adds r0, 0x6
	adds r1, r0, r1
	movs r2, 0
	ldrb r0, [r1]
	cmp r0, 0
	bne _0811FC62
	movs r2, 0x1
	b _0811FC62
	.pool
_0811FC40:
	strb r4, [r0, 0x4]
	movs r3, 0
	adds r4, r2, 0
_0811FC46:
	ldr r2, [r4]
	adds r0, r2, 0x6
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, r3
	ldrb r1, [r2, 0x4]
	orrs r0, r1
	strb r0, [r2, 0x4]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x3
	bls _0811FC46
	b _0811FC76
_0811FC62:
	strb r2, [r1]
_0811FC64:
	movs r0, 0x1
	b _0811FC78
_0811FC68:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0811FC64
	movs r0, 0x5
	bl audio_play
_0811FC76:
	movs r0, 0
_0811FC78:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811FBA4

	thumb_func_start sub_811FC80
sub_811FC80: @ 811FC80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	mov r8, r0
	mov r9, r1
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r4, =gUnknown_0203A124
	ldr r0, [r4]
	adds r0, 0x34
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	movs r7, 0
	movs r0, 0x80
	lsls r0, 5
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x1E
	strh r5, [r0]
	add r1, sp, 0x20
	ldr r0, =gUnknown_08DC9628
	str r0, [sp, 0x20]
	movs r0, 0xC8
	lsls r0, 2
	strh r0, [r1, 0x4]
	adds r0, r5, 0x1
	strh r0, [r1, 0x6]
	add r0, sp, 0x28
	movs r1, 0
	movs r2, 0x8
	bl memset
	add r2, sp, 0x18
	mov r10, r2
	mov r0, sp
	mov r1, r10
	movs r2, 0x18
	bl memcpy
	ldr r0, [r4]
	ldr r0, [r0, 0x30]
	str r0, [sp, 0x30]
	add r0, sp, 0x34
	strh r6, [r0]
	add r1, sp, 0x38
	ldr r0, =gUnknown_08DC9608
	str r0, [sp, 0x38]
	adds r0, r6, 0x1
	strh r0, [r1, 0x4]
	add r0, sp, 0x40
	movs r1, 0
	movs r2, 0x8
	bl memset
	add r4, sp, 0x30
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0x18
	bl memcpy
	strh r5, [r4]
	strh r6, [r4, 0x2]
	ldr r0, =gUnknown_0859EE7C
	str r0, [r4, 0x4]
	ldr r0, =gUnknown_0859EF14
	str r0, [r4, 0x8]
	str r7, [r4, 0xC]
	ldr r0, =gDummyObjectRotScalAnimTable
	str r0, [r4, 0x10]
	ldr r0, =TaskDummy7
	str r0, [r4, 0x14]
	mov r0, sp
	bl LoadObjectPics
	mov r0, r10
	bl LoadTaggedObjectPalettes
	movs r5, 0
	mov r3, r8
	lsls r3, 16
	mov r8, r3
	movs r0, 0x80
	lsls r0, 14
	add r0, r8
	mov r10, r0
	mov r1, r8
	str r1, [sp, 0x48]
	mov r2, r9
	lsls r2, 16
	mov r9, r2
	movs r7, 0x80
	lsls r7, 14
	add r7, r9
	mov r3, r9
	str r3, [sp, 0x4C]
_0811FD58:
	adds r0, r4, 0
	mov r2, r10
	asrs r1, r2, 16
	asrs r2, r7, 16
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	bne _0811FD70
	b _0811FEFC
_0811FD70:
	ldr r6, =gUnknown_0203A124
	ldr r2, [r6]
	lsls r0, r5, 2
	adds r2, 0xC
	adds r2, r0
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	lsls r1, r5, 24
	lsrs r1, 24
	bl StartObjectImageAnim
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1
	bls _0811FD58
	ldr r0, [r6]
	ldr r1, [r0, 0x10]
	ldr r3, [sp, 0x4C]
	asrs r0, r3, 16
	adds r0, 0x60
	strh r0, [r1, 0x22]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	ldr r0, =gUnknown_0859EEDC
	str r0, [r4, 0x8]
	ldr r0, =sub_811FF40
	str r0, [r4, 0x14]
	ldr r0, =gUnknown_0859EE84
	str r0, [r4, 0x4]
	movs r5, 0
	ldr r0, [sp, 0x48]
	movs r1, 0x80
	lsls r1, 14
	adds r0, r1
	mov r9, r0
_0811FDC8:
	lsls r2, r5, 4
	adds r2, 0x10
	ldr r3, [sp, 0x4C]
	asrs r3, 16
	mov r8, r3
	add r2, r8
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	mov r3, r9
	asrs r1, r3, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	bne _0811FDEE
	b _0811FF0C
_0811FDEE:
	ldr r6, =gUnknown_0203A124
	ldr r1, [r6]
	lsls r0, r5, 2
	adds r1, 0x14
	adds r1, r0
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r7, =gSprites
	adds r0, r7
	str r0, [r1]
	strh r5, [r0, 0x2E]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _0811FDC8
	ldr r0, =DummyObjectCallback
	str r0, [r4, 0x14]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _0811FEA8
	ldr r0, [r6]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r7
	str r1, [r0, 0x28]
	ldrb r3, [r1, 0x1]
	movs r2, 0x3F
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1, 0x1]
	ldr r0, [r6]
	ldr r1, [r0, 0x28]
	ldrb r0, [r1, 0x3]
	ands r2, r0
	movs r0, 0x80
	orrs r2, r0
	strb r2, [r1, 0x3]
	ldr r0, [r6]
	ldr r0, [r0, 0x28]
	movs r1, 0x9
	bl StartObjectImageAnim
	ldr r1, [r6]
	ldr r2, [r1, 0x28]
	ldr r3, [sp, 0x48]
	asrs r0, r3, 16
	adds r0, 0x20
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0x28]
	mov r0, r8
	adds r0, 0x50
	strh r0, [r2, 0x22]
	ldr r0, [r1, 0x28]
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0
	bl CalcCenterToCornerVec
	b _0811FEAE
	.pool
_0811FEA8:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x28]
_0811FEAE:
	ldr r0, =sub_811FF7C
	str r0, [r4, 0x14]
	ldr r0, [sp, 0x48]
	movs r2, 0xC0
	lsls r2, 12
	adds r1, r0, r2
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _0811FF20
	ldr r0, =gUnknown_0203A124
	ldr r2, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2, 0x24]
	ldr r3, [sp, 0x4C]
	asrs r0, r3, 16
	adds r0, 0x10
	strh r0, [r1, 0x2E]
	ldr r0, [r2, 0x24]
	movs r1, 0x8
	bl StartObjectImageAnim
	b _0811FF28
	.pool
_0811FEFC:
	ldr r0, =gUnknown_0203A124
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, 0xC
	b _0811FF14
	.pool
_0811FF0C:
	ldr r0, =gUnknown_0203A124
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, 0x14
_0811FF14:
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	b _0811FF28
	.pool
_0811FF20:
	ldr r0, =gUnknown_0203A124
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x24]
_0811FF28:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811FC80

	thumb_func_start TaskDummy7
TaskDummy7: @ 811FF3C
	bx lr
	thumb_func_end TaskDummy7

	thumb_func_start sub_811FF40
sub_811FF40: @ 811FF40
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A124
	ldr r0, [r0]
	movs r3, 0x2E
	ldrsh r1, [r2, r3]
	adds r0, 0x6
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0811FF6C
	lsls r1, 1
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl StartObjectImageAnim
	b _0811FF76
	.pool
_0811FF6C:
	lsls r1, 25
	lsrs r1, 24
	adds r0, r2, 0
	bl StartObjectImageAnim
_0811FF76:
	pop {r0}
	bx r0
	thumb_func_end sub_811FF40

	thumb_func_start sub_811FF7C
sub_811FF7C: @ 811FF7C
	ldr r1, =gUnknown_0203A124
	ldr r1, [r1]
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	lsls r1, 4
	ldrh r2, [r0, 0x2E]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_811FF7C

	thumb_func_start sub_811FF94
sub_811FF94: @ 811FF94
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r2, 0
	bne _0811FFA4
	ldr r2, =gUnknown_0859E65C
_0811FFA4:
	movs r3, 0x10
	bl sub_811FFD4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811FF94

	thumb_func_start sub_811FFB4
sub_811FFB4: @ 811FFB4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r2, 0
	bne _0811FFC4
	ldr r2, =gUnknown_0859E65C
_0811FFC4:
	movs r3, 0x1
	bl sub_811FFD4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811FFB4

	thumb_func_start sub_811FFD4
sub_811FFD4: @ 811FFD4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x28
	lsls r0, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gUnknown_0859E67C
	str r4, [sp, 0x18]
	movs r4, 0x80
	add r5, sp, 0x18
	lsrs r6, r0, 16
	orrs r0, r4
	str r0, [r5, 0x4]
	str r2, [sp, 0x20]
	ldr r0, =0xffff0000
	mov r8, r0
	add r4, sp, 0x20
	ldr r0, [r4, 0x4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	mov r0, sp
	movs r2, 0
	strh r6, [r0]
	strh r1, [r0, 0x2]
	ldr r0, =gUnknown_0859EF1C
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_0859EFA4
	str r0, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r0, =gDummyObjectRotScalAnimTable
	str r0, [sp, 0x10]
	ldr r0, =TaskDummy7
	str r0, [sp, 0x14]
	lsls r3, 23
	lsrs r3, 16
	ldr r0, [r5, 0x4]
	mov r1, r8
	ands r0, r1
	orrs r0, r3
	str r0, [r5, 0x4]
	adds r0, r5, 0
	bl LoadObjectPic
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	mov r0, sp
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	bne _08120068
	movs r0, 0
	b _08120072
	.pool
_08120068:
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
_08120072:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811FFD4

	thumb_func_start sub_8120084
sub_8120084: @ 8120084
	push {lr}
	lsls r0, 24
	lsrs r0, 17
	ldr r2, =gUnknown_0859E67C
	adds r0, r2
	movs r2, 0x80
	movs r3, 0x10
	bl RequestDma3Copy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120084

	.align 2, 0 @ Don't pad with nop.
