	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F7670
sub_80F7670: @ 80F7670
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _080F7732
	movs r0, 0
	strh r0, [r1, 0x8]
	ldr r0, =gUnknown_0203A034
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0x27
	bhi _080F7732
	ldr r4, =gSpriteTemplate_858D860
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r1, r0, 0
	subs r1, 0x14
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0x2C
	movs r3, 0x5
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl Random
	ldr r1, =gSprites
	lsls r5, r4, 4
	adds r5, r4
	lsls r5, 2
	adds r5, r1
	lsls r0, 23
	lsrs r0, 23
	strh r0, [r5, 0x2E]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x18
	bl __umodsi3
	adds r0, 0x10
	strh r0, [r5, 0x30]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xFF
	ands r0, r1
	adds r0, 0x30
	strh r0, [r5, 0x32]
	bl Random
	ldrh r6, [r5, 0x4]
	lsls r4, r6, 22
	lsrs r4, 22
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	adds r4, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r4, r0
	ldr r0, =0xfffffc00
	ands r0, r6
	orrs r0, r4
	strh r0, [r5, 0x4]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	adds r0, 0x1
	strb r0, [r1, 0x7]
_080F7732:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080F7744
	adds r0, r7, 0
	bl DestroyTask
_080F7744:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7670

	thumb_func_start sub_80F7768
sub_80F7768: @ 80F7768
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r1, [r4, 0x32]
	ldrh r0, [r4, 0x36]
	adds r1, r0
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0x36]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	ldr r5, =gUnknown_0203A034
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080F77B6
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080F77B6:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0xF8
	bgt _080F77C6
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0x74
	ble _080F77D6
_080F77C6:
	adds r0, r4, 0
	bl DestroySprite
	ldr r0, [r5]
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	subs r0, 0x1
	strb r0, [r1, 0x7]
_080F77D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7768

	thumb_func_start sub_80F77E0
sub_80F77E0: @ 80F77E0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_80F7824
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xA]
	ldr r0, =gContestMons
	lsls r4, 6
	adds r4, r0
	ldrh r0, [r4]
	strh r0, [r1, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F77E0

	thumb_func_start sub_80F7824
sub_80F7824: @ 80F7824
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrb r5, [r4, 0x8]
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _080F786E
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r0, [r4, 0xC]
	ldrb r2, [r4, 0x1E]
	ldr r1, =gContestMons
	lsls r3, r5, 6
	adds r1, 0x38
	adds r3, r1
	ldr r1, [r3]
	str r1, [sp]
	adds r1, r5, 0
	movs r3, 0
	bl sub_80F69B8
	ldrh r0, [r4, 0x1E]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x1E]
_080F786E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7824

	thumb_func_start sub_80F7880
sub_80F7880: @ 80F7880
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_02039F08
	ldrh r2, [r0]
	adds r4, r0, 0
	adds r3, r4, 0x2
	movs r0, 0x2
	mov r8, r0
_080F7898:
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0
	ldrsh r1, [r3, r5]
	cmp r0, r1
	bge _080F78A6
	ldrh r2, [r3]
_080F78A6:
	adds r3, 0x2
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080F7898
	lsls r0, r2, 16
	str r0, [sp]
	cmp r0, 0
	bge _080F78E4
	ldrh r2, [r4]
	adds r3, r4, 0x2
	movs r4, 0x2
	mov r8, r4
_080F78C4:
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0
	ldrsh r1, [r3, r5]
	cmp r0, r1
	ble _080F78D2
	ldrh r2, [r3]
_080F78D2:
	adds r3, 0x2
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	lsls r1, r2, 16
	str r1, [sp]
	mov r4, r8
	cmp r4, 0
	bge _080F78C4
_080F78E4:
	movs r5, 0
	mov r8, r5
	mov r10, r5
_080F78EA:
	ldr r0, =gContestMonConditions
	mov r1, r8
	lsls r7, r1, 1
	adds r0, r7, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	ldr r4, [sp]
	asrs r5, r4, 16
	adds r1, r5, 0
	cmp r5, 0
	bge _080F790C
	negs r1, r5
_080F790C:
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	cmp r0, 0x4
	ble _080F791E
	adds r4, 0xA
_080F791E:
	ldr r0, =gUnknown_0203A034
	mov r9, r0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r6, r1, r0
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	str r0, [r6]
	ldr r0, =gUnknown_02039F18
	adds r7, r0
	movs r2, 0
	ldrsh r1, [r7, r2]
	cmp r1, 0
	bge _080F7942
	negs r1, r1
_080F7942:
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r5, 0
	cmp r1, 0
	bge _080F7954
	negs r1, r1
_080F7954:
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	cmp r0, 0x4
	ble _080F7966
	adds r4, 0xA
_080F7966:
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	str r0, [r6, 0x4]
	movs r4, 0
	ldrsh r0, [r7, r4]
	cmp r0, 0
	bge _080F797C
	movs r0, 0x1
	strb r0, [r6, 0x10]
_080F797C:
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r4, r1, r0
	ldr r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	subs r0, r1
	lsls r0, 11
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	movs r5, 0xFF
	ands r0, r5
	cmp r0, 0x7F
	bls _080F79A8
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2
_080F79A8:
	lsrs r0, r1, 8
	str r0, [r4, 0x8]
	ldr r1, [r4, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	subs r0, r1
	lsls r0, 11
	movs r1, 0x64
	bl __divsi3
	adds r1, r0, 0
	ands r0, r5
	cmp r0, 0x7F
	bls _080F79CC
	movs r5, 0x80
	lsls r5, 1
	adds r1, r5
_080F79CC:
	lsrs r0, r1, 8
	str r0, [r4, 0xC]
	mov r0, r8
	lsls r4, r0, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80F7310
	mov r2, r9
	ldr r1, [r2]
	ldr r1, [r1, 0x4]
	add r1, r10
	strb r0, [r1, 0x11]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80F7364
	mov r4, r9
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	add r1, r10
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _080F7A02
	negs r0, r0
_080F7A02:
	strb r0, [r1, 0x12]
	ldr r0, =gContestFinalStandings
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F7A60
	mov r5, r9
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	mov r2, r10
	adds r1, r2, r0
	ldr r5, [r1, 0x8]
	ldrh r3, [r1, 0x8]
	ldr r4, [r1, 0xC]
	ldrh r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _080F7A2C
	lsls r0, r2, 16
	negs r0, r0
	lsrs r2, r0, 16
_080F7A2C:
	lsls r0, r3, 16
	asrs r3, r0, 16
	lsls r0, r2, 16
	asrs r2, r0, 16
	adds r0, r3, r2
	cmp r0, 0x58
	bne _080F7A60
	cmp r2, 0
	ble _080F7A58
	subs r0, r4, 0x1
	str r0, [r1, 0xC]
	b _080F7A60
	.pool
_080F7A58:
	cmp r3, 0
	ble _080F7A60
	subs r0, r5, 0x1
	str r0, [r1, 0x8]
_080F7A60:
	movs r4, 0x14
	add r10, r4
	movs r5, 0x1
	add r8, r5
	mov r0, r8
	cmp r0, 0x3
	bgt _080F7A70
	b _080F78EA
_080F7A70:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7880

	thumb_func_start sub_80F7A80
sub_80F7A80: @ 80F7A80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	str r1, [sp, 0x8]
	movs r3, 0
	str r3, [sp, 0xC]
	cmp r0, 0
	bne _080F7B5C
	mov r9, r3
	ldr r4, =gUnknown_0203A034
	mov r10, r4
	movs r7, 0xA0
	lsls r7, 19
	movs r6, 0
_080F7AAC:
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r2, [r0, 0x11]
	cmp r8, r2
	bcs _080F7B2E
	adds r2, 0x13
	mov r3, r8
	subs r2, r3
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	lsrs r3, r7, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r1, =0x000060b3
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =sub_80F7CA8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r10
	ldr r4, [r0]
	ldr r1, [r4, 0x4]
	adds r1, r6, r1
	ldr r0, [r1, 0x8]
	lsls r0, 16
	ldrb r1, [r1, 0x11]
	bl __udivsi3
	mov r1, r8
	adds r1, 0x1
	adds r3, r0, 0
	muls r3, r1
	ldr r0, =0x0000ffff
	ands r0, r3
	ldr r1, =0x00007fff
	cmp r0, r1
	bls _080F7B0A
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1
_080F7B0A:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	mov r1, r9
	strh r1, [r0, 0x8]
	lsrs r1, r3, 16
	strh r1, [r0, 0xA]
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
_080F7B2E:
	movs r3, 0xC0
	lsls r3, 18
	adds r7, r3
	adds r6, 0x14
	movs r4, 0x1
	add r9, r4
	mov r0, r9
	cmp r0, 0x3
	ble _080F7AAC
	b _080F7C7E
	.pool
_080F7B5C:
	movs r1, 0
	mov r9, r1
	mov r10, r1
	movs r3, 0xC0
	lsls r3, 19
	str r3, [sp, 0x10]
_080F7B68:
	ldr r4, =gUnknown_0203A034
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	add r0, r10
	ldrb r2, [r0, 0x12]
	ldrb r0, [r0, 0x10]
	ldr r1, =0x000060a3
	cmp r0, 0
	beq _080F7B7C
	adds r1, 0x2
_080F7B7C:
	lsls r0, r2, 24
	asrs r0, 24
	cmp r8, r0
	bge _080F7C64
	mov r3, r8
	lsls r2, r3, 24
	asrs r2, 24
	subs r2, 0x13
	subs r2, r0, r2
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r4, [sp, 0x10]
	lsrs r3, r4, 24
	movs r7, 0x1
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r0, 0x1
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =sub_80F7CA8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A034
	ldr r6, [r0]
	ldr r1, [r6, 0x4]
	add r1, r10
	ldr r0, [r1, 0xC]
	lsls r0, 16
	ldrb r1, [r1, 0x12]
	bl __udivsi3
	mov r1, r8
	adds r1, 0x1
	adds r3, r0, 0
	muls r3, r1
	ldr r0, =0x0000ffff
	ands r0, r3
	ldr r1, =0x00007fff
	cmp r0, r1
	bls _080F7BDA
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1
_080F7BDA:
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r4, r0, r1
	mov r0, r9
	strh r0, [r4, 0x8]
	ldr r0, [r6, 0x4]
	add r0, r10
	ldrb r0, [r0, 0x10]
	adds r6, r1, 0
	cmp r0, 0
	beq _080F7C1C
	strh r7, [r4, 0xC]
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	b _080F7C26
	.pool
_080F7C1C:
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
_080F7C26:
	ldr r1, =gUnknown_0203A034
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	mov r4, r10
	adds r1, r4, r0
	ldrb r0, [r1, 0x10]
	ldr r4, =gUnknown_0203A034
	cmp r0, 0
	beq _080F7C4C
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r6
	lsrs r2, r3, 16
	ldr r1, [r1, 0x8]
	subs r1, r2
	b _080F7C58
	.pool
_080F7C4C:
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r6
	lsrs r2, r3, 16
	ldr r1, [r1, 0x8]
	adds r1, r2
_080F7C58:
	strh r1, [r0, 0xA]
	ldr r0, [r4]
	ldr r1, [r0]
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
_080F7C64:
	movs r0, 0x14
	add r10, r0
	ldr r1, [sp, 0x10]
	movs r3, 0xC0
	lsls r3, 18
	adds r1, r3
	str r1, [sp, 0x10]
	movs r4, 0x1
	add r9, r4
	mov r0, r9
	cmp r0, 0x3
	bgt _080F7C7E
	b _080F7B68
_080F7C7E:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _080F7C8A
	movs r0, 0x16
	bl PlaySE
_080F7C8A:
	ldr r3, [sp, 0x8]
	cmp r3, 0
	beq _080F7C96
	movs r0, 0x15
	bl PlaySE
_080F7C96:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7A80

	thumb_func_start sub_80F7CA8
sub_80F7CA8: @ 80F7CA8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r4, 0
	mov r9, r4
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r6, [r0, 0x8]
	ldrh r7, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	mov r12, r1
	movs r2, 0xC
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _080F7CF8
	ldr r2, =gUnknown_0203A034
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0xC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r5, r1, 0
	cmp r0, 0
	bgt _080F7D10
	b _080F7D0E
	.pool
_080F7CF8:
	ldr r2, =gUnknown_0203A034
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0xC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r5, r1, 0
	cmp r0, 0x57
	ble _080F7D10
_080F7D0E:
	movs r4, 0x1
_080F7D10:
	ldr r0, [r2]
	ldr r0, [r0]
	adds r0, 0xC
	adds r2, r0, r5
	ldrh r3, [r2]
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r7, 16
	asrs r0, 16
	cmp r1, r0
	bne _080F7D2A
	movs r1, 0x1
	mov r9, r1
_080F7D2A:
	mov r0, r9
	cmp r0, 0
	bne _080F7D4A
	cmp r4, 0
	beq _080F7D3C
	strh r7, [r2]
	b _080F7D4A
	.pool
_080F7D3C:
	mov r1, r12
	cmp r1, 0
	beq _080F7D46
	subs r0, r3, 0x1
	b _080F7D48
_080F7D46:
	adds r0, r3, 0x1
_080F7D48:
	strh r0, [r2]
_080F7D4A:
	cmp r4, 0
	bne _080F7DC4
	mov r2, r9
	cmp r2, 0
	bne _080F7DCA
	movs r2, 0
_080F7D56:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0xC
	adds r0, r5
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r2, 0x1
	lsls r1, r0, 3
	adds r4, r0, 0
	cmp r3, r1
	blt _080F7D78
	movs r0, 0x8
	b _080F7D94
	.pool
_080F7D78:
	lsls r0, r2, 3
	cmp r3, r0
	blt _080F7D92
	adds r0, r3, 0
	cmp r3, 0
	bge _080F7D86
	adds r0, r3, 0x7
_080F7D86:
	asrs r0, 3
	lsls r0, 3
	subs r0, r3, r0
	lsls r0, 24
	lsrs r0, 24
	b _080F7D94
_080F7D92:
	movs r0, 0
_080F7D94:
	cmp r0, 0x3
	bhi _080F7DA0
	ldr r3, =0x0000504c
	b _080F7DA2
	.pool
_080F7DA0:
	ldr r3, =0x00005057
_080F7DA2:
	adds r1, r0, r3
	adds r2, 0x7
	lsls r2, 24
	lsrs r2, 24
	adds r3, r5, r6
	adds r3, 0x6
	lsls r3, 24
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	lsrs r3, 24
	bl FillBgTilemapBufferRect_Palette0
	adds r2, r4, 0
	cmp r2, 0xA
	ble _080F7D56
_080F7DC4:
	mov r0, r9
	cmp r0, 0
	beq _080F7DDC
_080F7DCA:
	ldr r0, =gUnknown_0203A034
	ldr r0, [r0]
	ldr r1, [r0]
	ldrb r0, [r1, 0x14]
	subs r0, 0x1
	strb r0, [r1, 0x14]
	mov r0, r8
	bl DestroyTask
_080F7DDC:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7CA8

	thumb_func_start sub_80F7DF4
sub_80F7DF4: @ 80F7DF4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203A034
	movs r0, 0x20
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x18
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x50
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r5, 0x80
	lsls r5, 4
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x8]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x10]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x14]
	adds r0, r5, 0
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x18]
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x1C]
	bl AllocateMonSpritesGfx
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7DF4

	thumb_func_start sub_80F7E64
sub_80F7E64: @ 80F7E64
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A034
	ldr r0, [r5]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0, 0x8]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x8]
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x10]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x10]
	ldr r0, [r0, 0x14]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x14]
	ldr r0, [r0, 0x18]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x18]
	ldr r0, [r0, 0x1C]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x1C]
	bl Free
	str r4, [r5]
	bl FreeMonSpritesGfx
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7E64

	thumb_func_start sub_80F7ED0
sub_80F7ED0: @ 80F7ED0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	str r1, [sp]
	mov r0, sp
	movs r3, 0
	strb r4, [r0, 0x4]
	mov r1, sp
	movs r0, 0x7
	strb r0, [r1, 0x5]
	mov r0, sp
	strb r2, [r0, 0x6]
	movs r1, 0x2
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x12
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0x10
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r1, sp
	movs r0, 0x80
	strb r0, [r1, 0xD]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80F7ED0

	thumb_func_start sub_80F7F30
sub_80F7F30: @ 80F7F30
	push {r4,r5,lr}
	ldr r0, =gContestMonPartyIndex
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_80DAE0C
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	cmp r5, 0
	beq _080F7F5E
	ldr r4, =gSpecialVar_ContestCategory
	ldrb r0, [r4]
	ldr r1, =gSpecialVar_ContestRank
	ldrb r1, [r1]
	bl sub_80DAB8C
	ldrb r0, [r4]
	bl sub_80DB09C
_080F7F5E:
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7F30

	thumb_func_start sub_80F7F7C
sub_80F7F7C: @ 80F7F7C
	push {r4,lr}
	movs r4, 0
	ldr r0, =gContestMonPartyIndex
	ldrb r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r2, r1, r0
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080F7FEE
	lsls r0, 2
	ldr r1, =_080F7FB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F7FB0:
	.4byte _080F7FC4
	.4byte _080F7FCA
	.4byte _080F7FD0
	.4byte _080F7FD6
	.4byte _080F7FDC
_080F7FC4:
	adds r0, r2, 0
	movs r1, 0x32
	b _080F7FE0
_080F7FCA:
	adds r0, r2, 0
	movs r1, 0x33
	b _080F7FE0
_080F7FD0:
	adds r0, r2, 0
	movs r1, 0x34
	b _080F7FE0
_080F7FD6:
	adds r0, r2, 0
	movs r1, 0x35
	b _080F7FE0
_080F7FDC:
	adds r0, r2, 0
	movs r1, 0x36
_080F7FE0:
	bl GetMonData
	ldr r1, =gSpecialVar_ContestRank
	ldrh r1, [r1]
	cmp r0, r1
	bls _080F7FEE
	movs r4, 0x1
_080F7FEE:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F7F7C

	thumb_func_start sub_80F7FFC
sub_80F7FFC: @ 80F7FFC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080F8010
	b _080F8250
_080F8010:
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bls _080F801A
	b _080F8250
_080F801A:
	lsls r0, 2
	ldr r1, =_080F8034
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F8034:
	.4byte _080F8048
	.4byte _080F80B8
	.4byte _080F8124
	.4byte _080F8190
	.4byte _080F81F8
_080F8048:
	ldr r6, =gContestMonPartyIndex
	ldrb r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x32
	bl GetMonData
	lsls r0, 24
	lsrs r1, r0, 24
	mov r0, sp
	strb r1, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r1, r0
	bls _080F806C
	b _080F8250
_080F806C:
	adds r0, r1, 0
	cmp r0, 0x3
	bls _080F8074
	b _080F8250
_080F8074:
	adds r1, r0, 0x1
	mov r0, sp
	strb r1, [r0]
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x32
	mov r2, sp
	bl SetMonData
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080F809C
	b _080F8250
_080F809C:
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0x32
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F80B8:
	mov r4, sp
	ldr r7, =gContestMonPartyIndex
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x33
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bls _080F80DC
	b _080F8250
_080F80DC:
	cmp r2, 0x3
	bls _080F80E2
	b _080F8250
_080F80E2:
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x33
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080F810A
	b _080F8250
_080F810A:
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x33
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F8124:
	mov r4, sp
	ldr r7, =gContestMonPartyIndex
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x34
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bls _080F8148
	b _080F8250
_080F8148:
	cmp r2, 0x3
	bls _080F814E
	b _080F8250
_080F814E:
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x34
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x34
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F8190:
	mov r4, sp
	ldr r7, =gContestMonPartyIndex
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x35
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bhi _080F8250
	cmp r2, 0x3
	bhi _080F8250
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x35
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x35
	bl sub_80EE4DC
	b _080F8250
	.pool
_080F81F8:
	mov r4, sp
	ldr r7, =gContestMonPartyIndex
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x36
	bl GetMonData
	strb r0, [r4]
	mov r0, sp
	ldrb r2, [r0]
	ldr r0, =gSpecialVar_ContestRank
	ldrh r0, [r0]
	cmp r2, r0
	bhi _080F8250
	cmp r2, 0x3
	bhi _080F8250
	mov r1, sp
	adds r0, r2, 0x1
	strb r0, [r1]
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x36
	mov r2, sp
	bl SetMonData
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	bl GetRibbonCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080F8250
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r5
	movs r1, 0x36
	bl sub_80EE4DC
_080F8250:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F7FFC

	thumb_func_start sub_80F8264
sub_80F8264: @ 80F8264
	push {r4,lr}
	ldr r4, =gStringVar1
	ldr r0, =gSpecialVar_0x8006
	ldrh r1, [r0]
	lsls r1, 6
	ldr r0, =gContestMons + 13
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_81DB5AC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8264

	thumb_func_start sub_80F8290
sub_80F8290: @ 80F8290
	push {lr}
	ldr r0, =gStringVar3
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	lsls r1, 6
	ldr r2, =gContestMons + 2
	adds r1, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8290

	thumb_func_start sub_80F82B4
sub_80F82B4: @ 80F82B4
	push {r4-r6,lr}
	movs r1, 0
	movs r2, 0
	ldr r5, =gSpecialVar_0x8004
	ldr r4, =gContestMonConditions
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r4
	movs r6, 0
	ldrsh r3, [r0, r6]
_080F82CA:
	lsls r0, r1, 1
	adds r0, r4
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r3, r0
	bge _080F82DC
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080F82DC:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080F82CA
	strh r2, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F82B4

	thumb_func_start sub_80F82FC
sub_80F82FC: @ 80F82FC
	ldr r2, =gSpecialVar_0x8004
	ldr r1, =gContestMonConditions
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80F82FC

	thumb_func_start sub_80F831C
sub_80F831C: @ 80F831C
	push {lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r3, =gSpecialVar_0x8005
	cmp r0, 0
	beq _080F833C
_080F832A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F833C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F832A
_080F833C:
	strh r1, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F831C

	thumb_func_start sub_80F834C
sub_80F834C: @ 80F834C
	push {r4,lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r4, =gStringVar3
	ldr r3, =gContestMons + 13
	cmp r0, 0
	beq _080F836E
_080F835C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F836E
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F835C
_080F836E:
	lsls r1, 6
	adds r1, r3
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	bl sub_81DB5AC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F834C

	thumb_func_start sub_80F8390
sub_80F8390: @ 80F8390
	push {r4,lr}
	movs r1, 0
	ldr r2, =gContestFinalStandings
	ldrb r0, [r2]
	ldr r4, =gStringVar1
	ldr r3, =gContestMons + 2
	cmp r0, 0
	beq _080F83B2
_080F83A0:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _080F83B2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F83A0
_080F83B2:
	lsls r1, 6
	adds r1, r3
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8390

	thumb_func_start sub_80F83D0
sub_80F83D0: @ 80F83D0
	push {lr}
	ldr r0, =sub_80D7B24
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F83D0

	thumb_func_start sub_80F83E0
sub_80F83E0: @ 80F83E0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080F83FE
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =sub_80F83D0
	bl SetMainCallback2
_080F83FE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F83E0

	thumb_func_start sub_80F840C
sub_80F840C: @ 80F840C
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_80F83E0
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F840C

	thumb_func_start sub_80F8438
sub_80F8438: @ 80F8438
	ldr r2, =gSpecialVar_0x8004
	ldr r1, =gContestMons
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 6
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_80F8438

	thumb_func_start sub_80F8458
sub_80F8458: @ 80F8458
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080F8476
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =sub_80F5B00
	bl SetMainCallback2
_080F8476:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8458

	thumb_func_start sub_80F8484
sub_80F8484: @ 80F8484
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_80F8458
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8484

	thumb_func_start sub_80F84B0
sub_80F84B0: @ 80F84B0
	ldr r0, =gSpecialVar_0x8004
	ldr r1, =gContestPlayerMonIndex
	ldrb r1, [r1]
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80F84B0

	thumb_func_start sub_80F84C4
sub_80F84C4: @ 80F84C4
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	bl ScriptContext2_Enable
	ldr r6, =sub_80FC580
	adds r0, r6, 0
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r2, =sub_80F8508
	adds r0, r4, 0
	adds r1, r6, 0
	bl SetTaskFuncWithFollowupFunc
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x1A]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F84C4

	thumb_func_start sub_80F8508
sub_80F8508: @ 80F8508
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080F8540
	ldr r0, =gContestMonPartyIndex
	ldrb r0, [r0]
	bl sub_80DA8C8
	ldr r1, =sub_80FC6BC
	ldr r2, =sub_80F8568
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	b _080F8556
	.pool
_080F8540:
	ldr r0, =gContestMonPartyIndex
	ldrb r0, [r0]
	bl sub_80DA8C8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81D9DE4
	str r1, [r0]
_080F8556:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8508

	thumb_func_start sub_80F8568
sub_80F8568: @ 80F8568
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC804
	ldr r2, =sub_80F8584
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8568

	thumb_func_start sub_80F8584
sub_80F8584: @ 80F8584
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FCE48
	ldr r2, =sub_80F85A0
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8584

	thumb_func_start sub_80F85A0
sub_80F85A0: @ 80F85A0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_80FC894
	ldr r2, =sub_80F85BC
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F85A0

	thumb_func_start sub_80F85BC
sub_80F85BC: @ 80F85BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r3, 0
	ldr r5, =gNumLinkContestPlayers
	mov r12, r5
	ldr r0, =gSpecialVar_0x8004
	mov r9, r0
	add r1, sp, 0x4
	mov r8, r1
	ldrb r0, [r5]
	cmp r3, r0
	bcs _080F8606
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 3
	ldr r7, =gTasks + 0x8
_080F85EC:
	mov r1, sp
	adds r2, r1, r3
	adds r1, r3, 0x1
	lsls r0, r1, 1
	adds r0, r4
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	ldrb r0, [r5]
	cmp r3, r0
	bcc _080F85EC
_080F8606:
	movs r3, 0
	mov r1, r12
	ldrb r0, [r1]
	cmp r3, r0
	bcs _080F862A
	adds r4, r0, 0
	mov r2, sp
_080F8614:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcs _080F862A
	mov r0, sp
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080F8614
_080F862A:
	mov r1, r12
	ldrb r1, [r1]
	cmp r3, r1
	bne _080F8644
	movs r0, 0
	b _080F8646
	.pool
_080F8644:
	movs r0, 0x1
_080F8646:
	mov r1, r9
	strh r0, [r1]
	movs r3, 0
	mov r4, r12
	ldrb r0, [r4]
	cmp r3, r0
	bcs _080F8678
	mov r5, r8
	lsls r0, r6, 2
	adds r0, r6
	lsls r2, r0, 3
	ldr r7, =gTasks + 0x8
_080F865E:
	adds r1, r5, r3
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r2
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r4]
	cmp r3, r1
	bcc _080F865E
_080F8678:
	mov r0, r8
	bl sub_80F86E0
	ldr r1, =gUnknown_02039F2B
	strb r0, [r1]
	ldr r0, =gSpecialVar_ContestCategory
	ldrb r0, [r0]
	bl sub_80DB09C
	ldr r1, =sub_80FCF40
	ldr r2, =sub_80F86B8
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F85BC

	thumb_func_start sub_80F86B8
sub_80F86B8: @ 80F86B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80DCE58
	ldr r1, =sub_80FCFD0
	ldr r2, =sub_80F8714
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F86B8

	thumb_func_start sub_80F86E0
sub_80F86E0: @ 80F86E0
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	movs r2, 0x1
	ldr r0, =gNumLinkContestPlayers
	ldrb r0, [r0]
	cmp r2, r0
	bge _080F8708
	adds r5, r0, 0
_080F86F2:
	adds r0, r3, r4
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080F8702
	lsls r0, r2, 24
	lsrs r4, r0, 24
_080F8702:
	adds r2, 0x1
	cmp r2, r5
	blt _080F86F2
_080F8708:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F86E0

	thumb_func_start sub_80F8714
sub_80F8714: @ 80F8714
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _080F8748
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080F877E
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80F878C
	str r0, [r1]
	b _080F877E
	.pool
_080F8748:
	ldr r5, =gContestMons + 2
	movs r4, 0x3
_080F874C:
	adds r0, r5, 0
	bl StringGetEnd10
	adds r5, 0x40
	subs r4, 0x1
	cmp r4, 0
	bge _080F874C
	adds r0, r6, 0
	bl DestroyTask
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl SetDynamicWarp
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_080F877E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F8714

	thumb_func_start sub_80F878C
sub_80F878C: @ 80F878C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_800AC34
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80F87B4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F878C

	thumb_func_start sub_80F87B4
sub_80F87B4: @ 80F87B4
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F87D0
	adds r0, r1, 0
	bl DestroyTask
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_080F87D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F87B4

	.align 2, 0 @ Don't pad with nop.
