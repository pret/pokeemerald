	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ClearMailData
ClearMailData: @ 80D436C
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gSaveBlock1Ptr
_080D4372:
	lsls r1, r4, 3
	adds r1, r4
	lsls r1, 2
	ldr r0, =0x00002be0
	adds r1, r0
	ldr r0, [r5]
	adds r0, r1
	bl ClearMailStruct
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080D4372
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearMailData

	thumb_func_start ClearMailStruct
ClearMailStruct: @ 80D439C
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r0, =0x0000ffff
	adds r4, r0, 0
	adds r1, r3, 0
	movs r2, 0x8
_080D43A8:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080D43A8
	movs r2, 0
	adds r6, r3, 0
	adds r6, 0x1A
	adds r4, r3, 0
	adds r4, 0x12
	movs r5, 0xFF
_080D43C2:
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x7
	ble _080D43C2
	adds r1, r6, 0
	movs r2, 0
	adds r0, r1, 0x3
_080D43D6:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080D43D6
	movs r1, 0
	movs r0, 0x1
	strh r0, [r3, 0x1E]
	strh r1, [r3, 0x20]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearMailStruct

	thumb_func_start MonHasMail
MonHasMail: @ 80D43F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl itemid_is_mail
	lsls r0, 24
	cmp r0, 0
	beq _080D4418
	adds r0, r4, 0
	movs r1, 0x40
	bl GetMonData
	cmp r0, 0xFF
	beq _080D4418
	movs r0, 0x1
	b _080D441A
_080D4418:
	movs r0, 0
_080D441A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MonHasMail

	thumb_func_start sub_80D4420
sub_80D4420: @ 80D4420
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	lsls r1, 16
	lsrs r0, r1, 16
	str r0, [sp, 0x8]
	mov r0, sp
	movs r2, 0
	ldrb r3, [r0, 0x8]
	strb r3, [r0]
	lsrs r1, 24
	strb r1, [r0, 0x1]
	add r3, sp, 0x4
	strb r2, [r3]
	ldr r4, =gSaveBlock1Ptr
	mov r10, r4
	mov r9, r3
	adds r4, r3, 0
_080D444C:
	mov r1, r10
	ldr r0, [r1]
	ldrb r2, [r4]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r0, r1
	movs r1, 0xB0
	lsls r1, 6
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080D4468
	b _080D45A8
_080D4468:
	movs r4, 0
	ldr r2, =gSaveBlock2Ptr
	mov r12, r2
	ldr r7, =gSaveBlock1Ptr
	add r5, sp, 0x4
	ldr r3, =0x0000ffff
	adds r6, r3, 0
_080D4476:
	ldr r2, [r7]
	lsls r3, r4, 1
	ldrb r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00002be0
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	orrs r0, r6
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x8
	bls _080D4476
	movs r4, 0
	ldr r5, =gSaveBlock1Ptr
	add r3, sp, 0x4
_080D44A0:
	ldr r2, [r5]
	ldrb r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldr r1, =0x00002bf2
	adds r2, r1
	adds r2, r0
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080D44A0
	mov r3, r10
	ldr r2, [r3]
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldr r1, =0x00002bf2
	adds r2, r1
	adds r2, r0
	movs r0, 0xFF
	strb r0, [r2]
	mov r2, r9
	ldrb r1, [r2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, [r3]
	adds r0, r1
	ldr r3, =0x00002bf2
	adds r0, r3
	movs r1, 0
	bl sub_81DB4DC
	movs r4, 0
	ldr r6, =gSaveBlock1Ptr
	add r3, sp, 0x4
	ldr r5, =gSaveBlock2Ptr
_080D4500:
	ldr r2, [r6]
	ldrb r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	ldr r1, =0x00002bfa
	adds r2, r1
	adds r2, r0
	ldr r0, [r5]
	adds r0, 0xA
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _080D4500
	mov r0, r8
	movs r1, 0xB
	bl GetBoxMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0
	bl GetBoxMonData
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80D45C8
	mov r2, r10
	ldr r3, [r2]
	mov r4, r9
	ldrb r2, [r4]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r3, r1
	ldr r2, =0x00002bfe
	adds r1, r2
	strh r0, [r1]
	ldrb r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	movs r4, 0xB0
	lsls r4, 6
	adds r3, r4
	mov r0, sp
	ldrh r0, [r0, 0x8]
	strh r0, [r3]
	mov r0, r8
	movs r1, 0x40
	mov r2, r9
	bl SetMonData
	mov r0, r8
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	mov r1, r9
	ldrb r0, [r1]
	b _080D45B6
	.pool
_080D45A8:
	adds r0, r2, 0x1
	strb r0, [r3]
	ldrb r0, [r4]
	cmp r0, 0x5
	bhi _080D45B4
	b _080D444C
_080D45B4:
	movs r0, 0xFF
_080D45B6:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D4420

	thumb_func_start sub_80D45C8
sub_80D45C8: @ 80D45C8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC9
	bne _080D45E0
	adds r0, r1, 0
	bl mon_icon_personality_to_unown_id
	lsls r0, 16
	ldr r1, =0x75300000
	adds r0, r1
	lsrs r0, 16
_080D45E0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D45C8

	thumb_func_start sub_80D45E8
sub_80D45E8: @ 80D45E8
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0xffff8ad0
	adds r2, r3, r0
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0x1B
	bhi _080D4604
	movs r0, 0xC9
	strh r2, [r1]
	b _080D4606
	.pool
_080D4604:
	adds r0, r3, 0
_080D4606:
	pop {r1}
	bx r1
	thumb_func_end sub_80D45E8

	thumb_func_start GiveMailToMon2
GiveMailToMon2: @ 80D460C
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r7, r1, 0
	ldrh r5, [r7, 0x20]
	adds r1, r5, 0
	bl sub_80D4420
	add r4, sp, 0x4
	strb r0, [r4]
	ldrb r2, [r4]
	cmp r2, 0xFF
	beq _080D4670
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x00002be0
	adds r1, r0
	adds r0, r7, 0
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	adds r0, r6, 0
	movs r1, 0x40
	adds r2, r4, 0
	bl SetMonData
	mov r0, sp
	strb r5, [r0]
	mov r1, sp
	lsrs r0, r5, 8
	strb r0, [r1, 0x1]
	adds r0, r6, 0
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	ldrb r0, [r4]
	b _080D4672
	.pool
_080D4670:
	movs r0, 0xFF
_080D4672:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GiveMailToMon2

	thumb_func_start sub_80D467C
sub_80D467C: @ 80D467C
	movs r0, 0
	bx lr
	thumb_func_end sub_80D467C

	thumb_func_start TakeMailFromMon
TakeMailFromMon: @ 80D4680
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl MonHasMail
	lsls r0, 24
	cmp r0, 0
	beq _080D46D2
	adds r0, r4, 0
	movs r1, 0x40
	bl GetMonData
	add r2, sp, 0x4
	strb r0, [r2]
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	movs r0, 0xB0
	lsls r0, 6
	adds r3, r0
	movs r1, 0
	movs r0, 0
	strh r0, [r3]
	movs r0, 0xFF
	strb r0, [r2]
	mov r0, sp
	strb r1, [r0]
	strb r1, [r0, 0x1]
	adds r0, r4, 0
	movs r1, 0x40
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
_080D46D2:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TakeMailFromMon

	thumb_func_start sub_80D46E0
sub_80D46E0: @ 80D46E0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	movs r0, 0xB0
	lsls r0, 6
	adds r2, r0
	movs r0, 0
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80D46E0

	thumb_func_start sub_80D4700
sub_80D4700: @ 80D4700
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r5, r0, 0
	mov r0, sp
	movs r1, 0
	strb r1, [r0]
	strb r1, [r0, 0x1]
	add r1, sp, 0x4
	movs r0, 0xFF
	strb r0, [r1]
	movs r7, 0x6
	mov r9, r1
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r3, =0x00002be0
_080D4724:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r7, 3
	adds r1, r7
	lsls r1, 2
	adds r4, r0, r1
	movs r2, 0xB0
	lsls r2, 6
	adds r0, r4, r2
	ldrh r6, [r0]
	cmp r6, 0
	bne _080D47A0
	adds r4, r3
	adds r0, r5, 0
	movs r1, 0x40
	str r3, [sp, 0x8]
	bl GetMonData
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r3, [sp, 0x8]
	adds r1, r3
	ldm r1!, {r0,r2,r3}
	stm r4!, {r0,r2,r3}
	ldm r1!, {r0,r2,r3}
	stm r4!, {r0,r2,r3}
	ldm r1!, {r0,r2,r3}
	stm r4!, {r0,r2,r3}
	adds r0, r5, 0
	movs r1, 0x40
	bl GetMonData
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	movs r3, 0xB0
	lsls r3, 6
	adds r2, r3
	strh r6, [r2]
	adds r0, r5, 0
	movs r1, 0x40
	mov r2, r9
	bl SetMonData
	adds r0, r5, 0
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r7, 0
	b _080D47AC
	.pool
_080D47A0:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xF
	bls _080D4724
	movs r0, 0xFF
_080D47AC:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D4700

	thumb_func_start itemid_is_mail
itemid_is_mail: @ 80D47BC
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x84
	bgt _080D47CE
	cmp r0, 0x79
	blt _080D47CE
	movs r0, 0x1
	b _080D47D0
_080D47CE:
	movs r0, 0
_080D47D0:
	pop {r1}
	bx r1
	thumb_func_end itemid_is_mail

	.align 2, 0 @ Don't pad with nop.
