	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817F498
sub_817F498: @ 817F498
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r6, r5, 2
	adds r0, r6, r5
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	lsls r3, r0, 16
	movs r4, 0xC
	ldrsh r0, [r2, r4]
	orrs r3, r0
	movs r0, 0x8
	ldrsh r4, [r2, r0]
	mov r8, r1
	ldr r0, =SpriteCallbackDummy
	mov r12, r0
	cmp r4, 0
	bne _0817F508
	ldrh r0, [r3, 0x2E]
	strh r0, [r2, 0x10]
	ldrh r0, [r3, 0x32]
	strh r0, [r2, 0x12]
	movs r0, 0x1
	strh r0, [r3, 0x30]
	strh r4, [r3, 0x2E]
	movs r0, 0x2
	adds r1, r6, 0
	ldr r6, =gUnknown_0860AA88
	ldr r7, =gUnknown_03001274
	movs r4, 0
	adds r2, r3, 0
	adds r2, 0x32
_0817F4E2:
	strh r4, [r2]
	adds r2, 0x2
	adds r0, 0x1
	cmp r0, 0x7
	bls _0817F4E2
	adds r1, r5
	lsls r1, 3
	add r1, r8
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0
	str r0, [r7]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0817F508:
	ldr r0, [r3, 0x1C]
	cmp r0, r12
	bne _0817F528
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r8
	ldrh r1, [r0, 0x10]
	movs r2, 0
	strh r1, [r3, 0x2E]
	ldrh r0, [r0, 0x12]
	strh r0, [r3, 0x32]
	strh r2, [r3, 0x30]
	adds r0, r5, 0
	bl DestroyTask
_0817F528:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817F498

	thumb_func_start sub_817F544
sub_817F544: @ 817F544
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r0, =sub_817F498
	movs r1, 0x80
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsrs r0, r5, 16
	strh r0, [r1, 0xA]
	strh r5, [r1, 0xC]
	strh r4, [r1, 0xE]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817F544

	thumb_func_start sub_817F578
sub_817F578: @ 817F578
	lsls r1, 24
	ldr r3, =gUnknown_03001274
	movs r2, 0x1
	str r2, [r3]
	ldr r2, =gUnknown_0860AA88
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_817F578

	thumb_func_start sub_817F594
sub_817F594: @ 817F594
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r6, r1, 24
	lsrs r6, 24
	ldr r0, =sub_817F498
	movs r1, 0x80
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	lsrs r0, r5, 16
	strh r0, [r4, 0xA]
	strh r5, [r4, 0xC]
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	ldr r1, =gBattlePartyID
	lsrs r0, 23
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r6, 1
	ldr r2, =gUnknown_0860AD2F
	adds r0, r2
	adds r1, r6
	ldrb r0, [r0]
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_0860ACE4
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817F594

	thumb_func_start sub_817F60C
sub_817F60C: @ 817F60C
	ldr r1, =nullsub_69
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_817F60C

	thumb_func_start sub_817F618
sub_817F618: @ 817F618
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r1, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r4, =0xffff0000
	lsls r2, 16
	lsrs r1, 16
	orrs r1, r2
	str r1, [sp]
	ldr r1, [sp, 0x4]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, 0x4]
	ldrb r4, [r0, 0x3]
	lsls r4, 26
	lsrs r4, 27
	add r5, sp, 0x8
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ObjAffineSet
	ldr r0, =gOamMatrices
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r5]
	strh r0, [r4]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x4]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x6]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817F618

	thumb_func_start sub_817F670
sub_817F670: @ 817F670
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_0860AD68
	str r0, [r4, 0x10]
	ldr r0, =gUnknown_03001274
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0817F68E
	adds r0, r4, 0
	bl InitSpriteAffineAnim
_0817F68E:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0817F6A8
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	b _0817F6B0
	.pool
_0817F6A8:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectRotScalAnim
_0817F6B0:
	ldrb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817F670

	thumb_func_start sub_817F6D4
sub_817F6D4: @ 817F6D4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	movs r5, 0x30
	ldrsh r0, [r4, r5]
	cmp r0, 0
	bne _0817F6F8
	lsls r0, r1, 16
	negs r0, r0
	lsrs r1, r0, 16
	negs r0, r3
	lsls r0, 16
	lsrs r3, r0, 16
_0817F6F8:
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	bl sub_817F618
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817F6D4

	thumb_func_start sub_817F70C
sub_817F70C: @ 817F70C
	push {lr}
	adds r1, r0, 0
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0817F720
	movs r2, 0x24
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x24]
_0817F720:
	pop {r0}
	bx r0
	thumb_func_end sub_817F70C

	thumb_func_start sub_817F724
sub_817F724: @ 817F724
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bhi _0817F750
	ldr r1, =gUnknown_03001240
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r2, 0
	strh r2, [r0, 0x6]
	strh r2, [r0]
	movs r1, 0x1
	strh r1, [r0, 0x4]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x8]
	movs r0, 0x1
	b _0817F752
	.pool
_0817F750:
	movs r0, 0
_0817F752:
	pop {r1}
	bx r1
	thumb_func_end sub_817F724

	thumb_func_start sub_817F758
sub_817F758: @ 817F758
	push {r4,lr}
	ldr r4, =gUnknown_03001270
	ldrb r1, [r4]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 2
	lsls r0, 2
	subs r0, r2, r0
	strb r0, [r4]
	ldrb r0, [r4]
	bl sub_817F724
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817F758

	thumb_func_start sub_817F77C
sub_817F77C: @ 817F77C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x1]
	movs r3, 0x4
	negs r3, r3
	ands r3, r0
	movs r5, 0x1
	orrs r3, r5
	strb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	ldr r0, =gUnknown_03001274
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0817F800
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0817F7C0
	adds r1, r4, 0
	adds r1, 0x3F
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r5, r1, 0
	b _0817F7D0
	.pool
_0817F7C0:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r2, [r0]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r5, r0, 0
_0817F7D0:
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldrb r2, [r4, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	ldrb r0, [r5]
	lsls r0, 31
	lsrs r0, 31
	lsls r0, 3
	orrs r1, r0
	lsls r1, 1
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
_0817F800:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817F77C

	thumb_func_start pokemonanimfunc_01
pokemonanimfunc_01: @ 817F808
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0817F81A
	adds r0, r6, 0
	bl sub_817F670
_0817F81A:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x28
	ble _0817F840
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _0817F88C
	.pool
_0817F840:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 9
	movs r1, 0x28
	bl __divsi3
	adds r4, r0, 0
	cmp r0, 0
	bge _0817F854
	adds r4, 0xFF
_0817F854:
	asrs r4, 8
	lsls r4, 8
	subs r4, r0, r4
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x20
	bl Cos
	adds r0, r5
	strh r0, [r6, 0x38]
	movs r0, 0x36
	ldrsh r1, [r6, r0]
	movs r0, 0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F6D4
_0817F88C:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_01

	thumb_func_start pokemonanimfunc_02
pokemonanimfunc_02: @ 817F898
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _0817F8B4
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0817F8EE
	.pool
_0817F8B4:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _0817F8C0
	movs r5, 0x1
_0817F8C0:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0817F8D4
	adds r0, 0xFF
_0817F8D4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
_0817F8EE:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_02

	thumb_func_start sub_817F8FC
sub_817F8FC: @ 817F8FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0817F91C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0817F946
	.pool
_0817F91C:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 7
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0817F936
	adds r0, 0xFF
_0817F936:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl Sin
_0817F946:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817F8FC

	thumb_func_start pokemonanimfunc_03
pokemonanimfunc_03: @ 817F95C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x28
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F8FC
	ldr r0, =sub_817F8FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_03

	thumb_func_start sub_817F978
sub_817F978: @ 817F978
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0817F998
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0817F9C4
	.pool
_0817F998:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 7
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0817F9B2
	adds r0, 0xFF
_0817F9B2:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl Sin
	negs r0, r0
_0817F9C4:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817F978

	thumb_func_start pokemonanimfunc_04
pokemonanimfunc_04: @ 817F9D8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x28
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F978
	ldr r0, =sub_817F978
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_04

	thumb_func_start sub_817F9F4
sub_817F9F4: @ 817F9F4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0xC0
	lsls r0, 1
	cmp r1, r0
	ble _0817FA14
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0817FA5E
	.pool
_0817FA14:
	adds r0, r1, 0
	cmp r1, 0
	bge _0817FA1C
	adds r0, 0x7F
_0817FA1C:
	asrs r2, r0, 7
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0
	blt _0817FA60
	cmp r0, 0x1
	ble _0817FA48
	cmp r0, 0x3
	bgt _0817FA60
	ldr r2, =0xffffff00
	adds r1, r2
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x2E
	ldrsh r2, [r4, r1]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 16
	b _0817FA56
	.pool
_0817FA48:
	lsls r0, r2, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsls r1, 17
_0817FA56:
	asrs r1, 16
	bl Sin
	negs r0, r0
_0817FA5E:
	strh r0, [r4, 0x26]
_0817FA60:
	ldrh r0, [r4, 0x32]
	adds r0, 0xC
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817F9F4

	thumb_func_start pokemonanimfunc_1E
pokemonanimfunc_1E: @ 817FA6C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F9F4
	ldr r0, =sub_817F9F4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_1E

	thumb_func_start pokemonanimfunc_06
pokemonanimfunc_06: @ 817FA88
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r0, 0xC0
	lsls r0, 2
	cmp r2, r0
	ble _0817FAA8
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0817FB56
	.pool
_0817FAA8:
	adds r0, r2, 0
	cmp r2, 0
	bge _0817FAB0
	adds r0, 0x7F
_0817FAB0:
	lsls r0, 9
	asrs r0, 16
	cmp r0, 0x5
	bhi _0817FB3C
	lsls r0, 2
	ldr r1, =_0817FAC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817FAC8:
	.4byte _0817FAE0
	.4byte _0817FAE0
	.4byte _0817FAE4
	.4byte _0817FAE8
	.4byte _0817FB04
	.4byte _0817FB1E
_0817FAE0:
	movs r0, 0
	b _0817FB3A
_0817FAE4:
	movs r2, 0
	b _0817FB3C
_0817FAE8:
	adds r0, r2, 0
	cmp r2, 0
	bge _0817FAF0
	adds r0, 0x7F
_0817FAF0:
	asrs r0, 7
	lsls r0, 7
	subs r0, r2, r0
	lsls r0, 3
	negs r0, r0
	cmp r0, 0
	bge _0817FB00
	adds r0, 0x7F
_0817FB00:
	asrs r0, 7
	b _0817FB3A
_0817FB04:
	adds r0, r2, 0
	cmp r2, 0
	bge _0817FB0C
	adds r0, 0x7F
_0817FB0C:
	asrs r0, 7
	lsls r0, 7
	subs r0, r2, r0
	cmp r0, 0
	bge _0817FB18
	adds r0, 0x7
_0817FB18:
	asrs r0, 3
	subs r0, 0x8
	b _0817FB3A
_0817FB1E:
	adds r0, r2, 0
	cmp r2, 0
	bge _0817FB26
	adds r0, 0x7F
_0817FB26:
	asrs r0, 7
	lsls r0, 7
	subs r0, r2, r0
	lsls r0, 3
	negs r0, r0
	cmp r0, 0
	bge _0817FB36
	adds r0, 0x7F
_0817FB36:
	asrs r0, 7
	adds r0, 0x8
_0817FB3A:
	strh r0, [r4, 0x24]
_0817FB3C:
	adds r0, r2, 0
	cmp r2, 0
	bge _0817FB44
	adds r0, 0x7F
_0817FB44:
	asrs r0, 7
	lsls r0, 7
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
_0817FB56:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0xC
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_06

	thumb_func_start pokemonanimfunc_09
pokemonanimfunc_09: @ 817FB64
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0817FB76
	adds r0, r6, 0
	bl sub_817F670
_0817FB76:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x28
	ble _0817FB9C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _0817FC12
	.pool
_0817FB9C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 8
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0817FBB0
	adds r0, 0xFF
_0817FBB0:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldrh r0, [r6, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0817FBE0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x20
	b _0817FBFA
_0817FBE0:
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x8
_0817FBFA:
	bl Sin
	adds r0, r5
	strh r0, [r6, 0x38]
	movs r0, 0x36
	ldrsh r1, [r6, r0]
	movs r0, 0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F6D4
_0817FC12:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_09

	thumb_func_start sub_817FC20
sub_817FC20: @ 817FC20
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0817FC32
	strh r0, [r4, 0x34]
_0817FC32:
	ldr r2, =gUnknown_0860AD70
	movs r5, 0x34
	ldrsh r1, [r4, r5]
	lsls r0, r1, 1
	adds r0, r1
	adds r1, r2, 0x2
	adds r3, r0, r1
	movs r1, 0
	ldrsb r1, [r3, r1]
	movs r5, 0x32
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0817FC6A
	adds r0, r1, 0
	cmp r0, 0
	bne _0817FC60
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0817FC6A
	.pool
_0817FC60:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x34]
	strh r1, [r4, 0x32]
_0817FC6A:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r1, r0, r1
	adds r0, r2, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _0817FC8C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0817FCBE
	.pool
_0817FC8C:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r5, 0x34
	ldrsh r1, [r4, r5]
	lsls r0, r1, 1
	adds r0, r1
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
_0817FCBE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817FC20

	thumb_func_start pokemonanimfunc_0A
pokemonanimfunc_0A: @ 817FCC4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817FC20
	ldr r0, =sub_817FC20
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0A

	thumb_func_start sub_817FCDC
sub_817FCDC: @ 817FCDC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x90
	lsls r0, 4
	cmp r1, r0
	ble _0817FCF8
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0817FD12
	.pool
_0817FCF8:
	adds r0, r1, 0
	cmp r1, 0
	bge _0817FD00
	adds r0, 0xFF
_0817FD00:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
_0817FD12:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817FCDC

	thumb_func_start pokemonanimfunc_0F
pokemonanimfunc_0F: @ 817FD24
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817FCDC
	ldr r0, =sub_817FCDC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0F

	thumb_func_start sub_817FD44
sub_817FD44: @ 817FD44
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x90
	lsls r0, 4
	cmp r1, r0
	ble _0817FD60
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0817FD78
	.pool
_0817FD60:
	adds r0, r1, 0
	cmp r1, 0
	bge _0817FD68
	adds r0, 0xFF
_0817FD68:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl Sin
_0817FD78:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817FD44

	thumb_func_start pokemonanimfunc_10
pokemonanimfunc_10: @ 817FD88
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817FD44
	ldr r0, =sub_817FD44
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_10

	thumb_func_start pokemonanimfunc_11
pokemonanimfunc_11: @ 817FDA4
	push {r4-r7,lr}
	adds r7, r0, 0
	ldrh r2, [r7, 0x32]
	movs r0, 0x32
	ldrsh r1, [r7, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _0817FDC8
	ldr r0, =sub_8184D88
	str r0, [r7, 0x1C]
	movs r0, 0
	strh r0, [r7, 0x24]
	strh r0, [r7, 0x26]
	b _0817FE24
	.pool
_0817FDC8:
	movs r0, 0x1
	ands r0, r2
	movs r5, 0xFF
	cmp r0, 0
	bne _0817FDD4
	movs r5, 0x1
_0817FDD4:
	movs r1, 0x32
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bge _0817FDDE
	adds r0, 0x3
_0817FDDE:
	asrs r0, 2
	movs r1, 0x8
	bl Sin
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0x32
	ldrsh r1, [r7, r0]
	adds r4, r1, 0
	cmp r1, 0
	bge _0817FDF6
	adds r4, 0xFF
_0817FDF6:
	asrs r4, 8
	lsls r4, 8
	subs r4, r1, r4
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	adds r1, r6, 0
	bl Sin
	lsls r5, 24
	asrs r5, 24
	adds r1, r0, 0
	muls r1, r5
	adds r0, r1, 0
	strh r0, [r7, 0x26]
	adds r0, r4, 0
	adds r1, r6, 0
	bl Cos
	adds r1, r0, 0
	muls r1, r5
	adds r0, r1, 0
	strh r0, [r7, 0x24]
_0817FE24:
	ldrh r0, [r7, 0x32]
	adds r0, 0x9
	strh r0, [r7, 0x32]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_11

	thumb_func_start sub_817FE30
sub_817FE30: @ 817FE30
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_03001240
	ldrh r6, [r4, 0x2E]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r2
	ldrh r0, [r5]
	cmp r0, 0
	beq _0817FE54
	subs r0, 0x1
	strh r0, [r5]
	b _0817FEF8
	.pool
_0817FE54:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0817FE70
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0817FE70
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0817FE70:
	ldr r2, =gUnknown_03001240
	lsls r1, r6, 16
	asrs r1, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r2
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _0817FEC4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r1, [r5, 0x4]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	cmp r0, 0x1
	ble _0817FEB4
	subs r0, r1, 0x1
	movs r1, 0
	strh r0, [r5, 0x4]
	movs r0, 0xA
	strh r0, [r5]
	strh r1, [r4, 0x32]
	b _0817FEF2
	.pool
_0817FEB4:
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0817FEF2
	.pool
_0817FEC4:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _0817FED0
	adds r0, 0xFF
_0817FED0:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x80
	lsls r1, 5
	bl Sin
	strh r0, [r4, 0x3A]
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3A]
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
_0817FEF2:
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	strh r0, [r4, 0x32]
_0817FEF8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_817FE30

	thumb_func_start pokemonanimfunc_12
pokemonanimfunc_12: @ 817FF00
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r1, 0x6]
	strh r3, [r1]
	adds r0, r4, 0
	bl sub_817FE30
	ldr r0, =sub_817FE30
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_12

	thumb_func_start sub_817FF3C
sub_817FF3C: @ 817FF3C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0817FF54
	adds r0, r4, 0
	bl sub_817F670
_0817FF54:
	movs r2, 0x32
	ldrsh r6, [r4, r2]
	ldr r1, =gUnknown_03001240
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	cmp r6, r1
	ble _0817FF8C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0817FFAA
	.pool
_0817FF8C:
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 9
	bl __divsi3
	muls r0, r6
	strh r0, [r4, 0x3A]
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3A]
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
_0817FFAA:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_817FF3C

	thumb_func_start pokemonanimfunc_1F
pokemonanimfunc_1F: @ 817FFB8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x3C
	strh r0, [r1]
	movs r0, 0x14
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_817FF3C
	ldr r0, =sub_817FF3C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_1F

	thumb_func_start sub_817FFF0
sub_817FFF0: @ 817FFF0
	push {r4-r7,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	bl sub_817F70C
	ldr r1, =gUnknown_03001240
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r6, r0, r1
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818002C
	movs r0, 0
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
	b _0818006A
	.pool
_0818002C:
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	adds r0, r1, 0
	adds r0, 0xC0
	adds r4, r0, 0
	cmp r0, 0
	bge _0818003E
	ldr r2, =0x000001bf
	adds r4, r1, r2
_0818003E:
	asrs r4, 8
	lsls r4, 8
	subs r4, r0, r4
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	lsls r1, 17
	asrs r1, 16
	adds r0, r4, 0
	bl Cos
	negs r0, r0
	strh r0, [r5, 0x24]
	movs r2, 0x8
	ldrsh r1, [r6, r2]
	adds r0, r4, 0
	bl Sin
	ldrh r1, [r6, 0x8]
	adds r0, r1
	strh r0, [r5, 0x26]
_0818006A:
	ldr r0, =gUnknown_03001240
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x2]
	ldrh r1, [r5, 0x32]
	adds r0, r1
	strh r0, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F70C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817FFF0

	thumb_func_start pokemonanimfunc_14
pokemonanimfunc_14: @ 8180090
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r1, 0x6]
	movs r0, 0x6
	strh r0, [r1, 0x8]
	movs r0, 0x18
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_817FFF0
	ldr r0, =sub_817FFF0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_14

	thumb_func_start pokemonanimfunc_15
pokemonanimfunc_15: @ 81800D0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081800EC
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_081800EC:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _0818010C
	ldrh r0, [r4, 0x3C]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180128
	.pool
_0818010C:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0x10
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0x10
	movs r3, 0
	bl BlendPalette
_08180128:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_15

	thumb_func_start pokemonanimfunc_16
pokemonanimfunc_16: @ 8180134
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08180148
	adds r0, r6, 0
	bl sub_817F670
_08180148:
	ldrh r5, [r6, 0x32]
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	cmp r0, 0x28
	ble _08180170
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08180204
	.pool
_08180170:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r5, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bhi _08180196
	ldrh r0, [r6, 0x3C]
	adds r0, 0x33
	strh r0, [r6, 0x3C]
	movs r7, 0xFF
	ands r7, r0
_08180196:
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _081801C4
	lsls r5, r4, 16
	asrs r0, r5, 16
	movs r1, 0x28
	bl Sin
	adds r4, r0, 0
	adds r0, r7, 0
	movs r1, 0x10
	bl Sin
	ldr r1, =0xffffff00
	adds r0, r1
	adds r4, r0
	strh r4, [r6, 0x36]
	adds r4, r5, 0
	b _081801E4
	.pool
_081801C4:
	adds r0, r7, 0
	movs r1, 0x10
	bl Sin
	adds r5, r0, 0
	lsls r4, 16
	asrs r0, r4, 16
	movs r1, 0x28
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r5
	subs r1, r0
	strh r1, [r6, 0x36]
_081801E4:
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r6, 0x38]
	movs r2, 0x36
	ldrsh r1, [r6, r2]
	movs r0, 0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F618
_08180204:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_16

	thumb_func_start pokemonanimfunc_17
pokemonanimfunc_17: @ 8180210
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	movs r0, 0
	mov r8, r0
	movs r7, 0
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0818022C
	adds r0, r5, 0
	bl sub_817F670
_0818022C:
	ldrh r6, [r5, 0x32]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	cmp r0, 0x28
	ble _08180258
	movs r2, 0x80
	lsls r2, 1
	adds r0, r5, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r5, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
	mov r0, r8
	strh r0, [r5, 0x26]
	b _0818030A
	.pool
_08180258:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r6, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bhi _0818027E
	ldrh r0, [r5, 0x3C]
	adds r0, 0x33
	strh r0, [r5, 0x3C]
	movs r7, 0xFF
	ands r7, r0
_0818027E:
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _081802A0
	lsls r4, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	ldr r2, =0xffffff00
	adds r1, r2, 0
	subs r1, r0
	strh r1, [r5, 0x36]
	b _081802B2
	.pool
_081802A0:
	lsls r4, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r5, 0x36]
_081802B2:
	adds r6, r4, 0
	adds r0, r7, 0
	movs r1, 0x8
	bl Sin
	adds r4, r0, 0
	asrs r0, r6, 16
	movs r1, 0x28
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r4, r1, r4
	subs r4, r0
	strh r4, [r5, 0x38]
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	cmp r4, r1
	beq _081802F0
	movs r2, 0x38
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, 0
	bge _081802EA
	adds r0, 0x7
_081802EA:
	lsls r0, 13
	lsrs r0, 16
	mov r8, r0
_081802F0:
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r5, 0x26]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	movs r0, 0x38
	ldrsh r2, [r5, r0]
	adds r0, r5, 0
	movs r3, 0
	bl sub_817F618
_0818030A:
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_17

	thumb_func_start sub_818031C
sub_818031C: @ 818031C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gUnknown_0860AA80
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	lsls r0, 1
	adds r1, r0, r2
	ldrb r5, [r1]
	adds r2, 0x1
	adds r0, r2
	ldrb r6, [r0]
	movs r1, 0
	cmp r5, 0xFE
	beq _08180358
	subs r0, r6, r7
	muls r0, r5
	adds r1, r6, 0
	bl __divsi3
	lsls r0, 24
	lsrs r1, r0, 24
_08180358:
	cmp r5, 0xFF
	bne _08180370
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x26]
	b _08180394
	.pool
_08180370:
	mov r0, r8
	bl Sin
	strh r0, [r4, 0x26]
	cmp r7, r6
	bne _08180386
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r0, 0
	b _08180392
_08180386:
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
_08180392:
	strh r0, [r4, 0x3A]
_08180394:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_818031C

	thumb_func_start pokemonanimfunc_19
pokemonanimfunc_19: @ 81803A0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x30
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_818031C
	ldr r0, =sub_818031C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_19

	thumb_func_start pokemonanimfunc_1A
pokemonanimfunc_1A: @ 81803BC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x32]
	lsls r7, r0, 24
	lsrs r5, r7, 24
	mov r8, r5
	cmp r0, 0
	bne _081803DA
	adds r0, r4, 0
	bl sub_817F670
_081803DA:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x23
	ble _08180404
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0818045E
	.pool
_08180404:
	adds r6, r5, 0
	subs r6, 0xA
	lsls r0, r6, 7
	movs r1, 0x14
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r5, 0x9
	bhi _0818042A
	movs r2, 0x80
	lsls r2, 1
	lsrs r3, r7, 25
	lsls r3, 9
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	b _0818045E
_0818042A:
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08180442
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x5
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	b _0818045E
_08180442:
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0x23
	mov r0, r8
	subs r3, r0
	lsrs r0, r3, 31
	adds r3, r0
	asrs r3, 1
	lsls r3, 26
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
_0818045E:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_1A

	thumb_func_start pokemonanimfunc_1B
pokemonanimfunc_1B: @ 8180474
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08180486
	adds r0, r6, 0
	bl sub_817F670
_08180486:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x64
	ble _081804B0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r0, 0
	strh r0, [r6, 0x26]
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _081804E8
	.pool
_081804B0:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 8
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl Sin
	strh r0, [r6, 0x26]
	movs r5, 0x80
	lsls r5, 1
	ldr r1, =0x00000ccc
	adds r0, r4, 0
	bl Sin
	adds r3, r0, 0
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r5, 0
	bl sub_817F6D4
_081804E8:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_1B

	thumb_func_start sub_81804F8
sub_81804F8: @ 81804F8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0818050C
	adds r0, r6, 0
	bl sub_817F670
_0818050C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x64
	ble _08180534
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r5, [r6, 0x26]
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08180582
	.pool
_08180534:
	movs r0, 0x32
	ldrsh r5, [r6, r0]
	lsls r0, r5, 8
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 9
	adds r0, r5, 0
	movs r1, 0x64
	bl __divsi3
	adds r5, r0, 0
	movs r0, 0xFF
	ands r5, r0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	adds r0, r4, 0
	bl Sin
	strh r0, [r6, 0x26]
	movs r4, 0x80
	lsls r4, 1
	adds r0, r5, 0
	ldr r1, =0x00000ccc
	bl Sin
	adds r3, r0, 0
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r4, 0
	bl sub_817F6D4
_08180582:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81804F8

	thumb_func_start pokemonanimfunc_1C
pokemonanimfunc_1C: @ 8180594
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_81804F8
	ldr r0, =sub_81804F8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_1C

	thumb_func_start sub_81805B0
sub_81805B0: @ 81805B0
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081805C4
	adds r0, r6, 0
	bl sub_817F670
_081805C4:
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	cmp r0, 0x64
	ble _081805EC
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r5, [r6, 0x26]
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08180644
	.pool
_081805EC:
	movs r0, 0x32
	ldrsh r5, [r6, r0]
	lsls r0, r5, 8
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 9
	adds r0, r5, 0
	movs r1, 0x64
	bl __divsi3
	adds r5, r0, 0
	movs r0, 0xFF
	ands r5, r0
	lsls r4, 16
	asrs r0, r4, 16
	lsrs r4, 31
	adds r0, r4
	asrs r0, 1
	movs r2, 0x2E
	ldrsh r1, [r6, r2]
	lsls r1, 17
	asrs r1, 16
	bl Sin
	negs r0, r0
	strh r0, [r6, 0x26]
	movs r4, 0x80
	lsls r4, 1
	adds r0, r5, 0
	ldr r1, =0x00000ccc
	bl Sin
	adds r3, r0, 0
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r4, 0
	bl sub_817F6D4
_08180644:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81805B0

	thumb_func_start pokemonanimfunc_18
pokemonanimfunc_18: @ 8180654
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_81805B0
	ldr r0, =sub_81805B0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_18

	thumb_func_start pokemonanimfunc_1D
pokemonanimfunc_1D: @ 8180670
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_817F70C
	movs r5, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08180688
	adds r0, r6, 0
	bl sub_817F670
_08180688:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x64
	ble _081806B0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r5, [r6, 0x24]
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _081806FC
	.pool
_081806B0:
	movs r0, 0x32
	ldrsh r5, [r6, r0]
	lsls r0, r5, 8
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 9
	adds r0, r5, 0
	movs r1, 0x64
	bl __divsi3
	adds r5, r0, 0
	movs r0, 0xFF
	ands r5, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	strh r0, [r6, 0x24]
	movs r4, 0x80
	lsls r4, 1
	adds r0, r5, 0
	ldr r1, =0x00000ccc
	bl Sin
	adds r3, r0, 0
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r4, 0
	bl sub_817F6D4
_081806FC:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	adds r0, r6, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_1D

	thumb_func_start sub_8180714
sub_8180714: @ 8180714
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r6, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0818072A
	adds r0, r4, 0
	bl sub_817F670
	strh r6, [r4, 0x34]
_0818072A:
	adds r0, r4, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	cmp r2, r0
	ble _08180760
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r6, [r4, 0x26]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _081807FE
	.pool
_08180760:
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	lsls r0, 16
	lsrs r5, r0, 16
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08180796
	adds r2, r0, 0
	lsls r0, r2, 1
	cmp r1, r0
	bge _08180796
	movs r0, 0x80
	adds r1, r2, 0
	bl __divsi3
	ldrh r1, [r4, 0x34]
	adds r1, r0
	strh r1, [r4, 0x34]
_08180796:
	lsls r0, r5, 16
	asrs r1, r0, 16
	movs r2, 0x80
	lsls r2, 1
	adds r5, r0, 0
	cmp r1, r2
	ble _081807B0
	subs r0, r2, r1
	cmp r0, 0
	bge _081807AC
	adds r0, 0x7
_081807AC:
	lsls r0, 13
	lsrs r6, r0, 16
_081807B0:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl Sin
	negs r0, r0
	lsls r1, r6, 16
	asrs r1, 16
	subs r0, r1
	strh r0, [r4, 0x26]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r1, 0x20
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	asrs r2, r5, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	bl __divsi3
	ldrh r1, [r4, 0x36]
	adds r1, r0
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0x36]
_081807FE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8180714

	thumb_func_start pokemonanimfunc_00
pokemonanimfunc_00: @ 818080C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_8180714
	ldr r0, =sub_8180714
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_00

	thumb_func_start sub_8180828
sub_8180828: @ 8180828
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
	movs r0, 0x32
	ldrsh r4, [r5, r0]
	movs r2, 0x3A
	ldrsh r1, [r5, r2]
	movs r0, 0x80
	bl __divsi3
	movs r2, 0x3C
	ldrsh r1, [r5, r2]
	muls r0, r1
	cmp r4, r0
	ble _08180868
	movs r2, 0x80
	lsls r2, 1
	adds r0, r5, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r6, [r5, 0x26]
	adds r0, r5, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
	b _081808D0
	.pool
_08180868:
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0x20
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	ble _08180894
	subs r0, r1, r0
	cmp r0, 0
	bge _08180890
	adds r0, 0x7
_08180890:
	lsls r0, 13
	lsrs r6, r0, 16
_08180894:
	lsls r0, r6, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r5, 0x26]
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0x30
	bl Sin
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	lsls r2, r4, 16
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x3A]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x36]
_081808D0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8180828

	thumb_func_start pokemonanimfunc_13
pokemonanimfunc_13: @ 81808D8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081808F2
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
_081808F2:
	adds r0, r4, 0
	bl sub_8180828
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_13

	thumb_func_start sub_8180900
sub_8180900: @ 8180900
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_03001240
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x6]
	str r1, [sp]
	ldr r5, =gUnknown_0860AD8E
	movs r3, 0x36
	ldrsh r2, [r4, r3]
	lsls r1, r2, 1
	adds r1, r2
	movs r3, 0x8
	ldrsh r2, [r0, r3]
	lsls r0, r2, 1
	adds r0, r2
	lsls r6, r0, 3
	adds r1, r6
	adds r2, r1, r5
	adds r0, r5, 0x1
	adds r1, r0
	movs r0, 0
	ldrsb r0, [r1, r0]
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	mov r9, r2
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	ldrh r7, [r4, 0x34]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0818096C
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_0818096C:
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r6
	adds r5, 0x2
	mov r8, r5
	adds r1, r0, r5
	movs r5, 0
	ldrsb r5, [r1, r5]
	cmp r5, 0
	bne _081809B0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	strh r5, [r4, 0x24]
	strh r5, [r4, 0x26]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180A3A
	.pool
_081809B0:
	lsls r0, r7, 16
	asrs r5, r0, 16
	lsls r0, r5, 7
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	mov r3, r10
	lsls r0, r3, 16
	asrs r0, 16
	muls r0, r5
	movs r1, 0x36
	ldrsh r2, [r4, r1]
	lsls r1, r2, 1
	adds r1, r2
	adds r1, r6
	add r1, r8
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	bl __divsi3
	add r0, r9
	strh r0, [r4, 0x24]
	ldr r2, [sp]
	lsls r0, r2, 16
	asrs r0, 16
	movs r3, 0x24
	ldrsh r1, [r4, r3]
	muls r0, r1
	negs r0, r0
	cmp r0, 0
	bge _08180A04
	adds r0, 0x7
_08180A04:
	lsls r3, r0, 13
	lsrs r3, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r6
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r5, r0
	bne _08180A34
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	movs r0, 0
	b _08180A38
_08180A34:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
_08180A38:
	strh r0, [r4, 0x34]
_08180A3A:
	adds r0, r4, 0
	bl sub_817F70C
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8180900

	thumb_func_start pokemonanimfunc_05
pokemonanimfunc_05: @ 8180A50
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 5
	strh r0, [r1, 0x6]
	ldrh r0, [r4, 0x3A]
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_8180900
	ldr r0, =sub_8180900
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_05

	thumb_func_start pokemonanimfunc_20
pokemonanimfunc_20: @ 8180A8C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180AA8
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_08180AA8:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _08180ACC
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000002df
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180AE8
	.pool
_08180ACC:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x000002df
	movs r1, 0x10
	bl BlendPalette
_08180AE8:
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_20

	thumb_func_start pokemonanimfunc_21
pokemonanimfunc_21: @ 8180AF8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180B14
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_08180B14:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _08180B34
	ldrh r0, [r4, 0x3C]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0x1F
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180B50
	.pool
_08180B34:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0x10
	movs r3, 0x1F
	bl BlendPalette
_08180B50:
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_21

	thumb_func_start pokemonanimfunc_22
pokemonanimfunc_22: @ 8180B5C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180B78
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_08180B78:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _08180B98
	ldrh r0, [r4, 0x3C]
	movs r3, 0xF8
	lsls r3, 7
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180BB6
	.pool
_08180B98:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0xF8
	lsls r3, 7
	movs r1, 0x10
	bl BlendPalette
_08180BB6:
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_22

	thumb_func_start pokemonanimfunc_23
pokemonanimfunc_23: @ 8180BC4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180BE0
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_08180BE0:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _08180C04
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180C20
	.pool
_08180C04:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x000003ff
	movs r1, 0x10
	bl BlendPalette
_08180C20:
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_23

	thumb_func_start pokemonanimfunc_24
pokemonanimfunc_24: @ 8180C30
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180C4C
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
_08180C4C:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x80
	ble _08180C70
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x00006018
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08180C8C
	.pool
_08180C70:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x00006018
	movs r1, 0x10
	bl BlendPalette
_08180C8C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_24

	thumb_func_start pokemonanimfunc_25
pokemonanimfunc_25: @ 8180C9C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	ldr r0, =sub_8180CB4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_25

	thumb_func_start sub_8180CB4
sub_8180CB4: @ 8180CB4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _08180CD6
	movs r0, 0x8
	strh r0, [r4, 0x24]
	movs r0, 0x2
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8180CE8
	str r0, [r4, 0x1C]
_08180CD6:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180CB4

	thumb_func_start sub_8180CE8
sub_8180CE8: @ 8180CE8
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	subs r1, r0
	strh r1, [r4, 0x24]
	adds r0, 0x1
	adds r2, r0, 0
	strh r0, [r4, 0x3C]
	lsls r1, 16
	cmp r1, 0
	bgt _08180D32
	lsls r0, r2, 24
	lsrs r2, r0, 24
	movs r0, 0
	strh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x24]
	ldr r5, =sub_8180D44
	movs r3, 0x8
	negs r3, r3
_08180D14:
	subs r0, r1, r2
	lsls r0, 16
	ldrh r1, [r4, 0x3A]
	adds r1, 0x1
	strh r1, [r4, 0x3A]
	adds r1, r2, 0x1
	lsls r1, 24
	lsrs r2, r1, 24
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, r3
	bgt _08180D14
	movs r0, 0x1
	strh r0, [r4, 0x38]
	str r5, [r4, 0x1C]
_08180D32:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180CE8

	thumb_func_start sub_8180D44
sub_8180D44: @ 8180D44
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x3C]
	subs r0, r1
	strh r0, [r4, 0x24]
	adds r1, 0x1
	strh r1, [r4, 0x3C]
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _08180D84
	strh r2, [r4, 0x38]
_08180D84:
	movs r2, 0x80
	lsls r2, 1
	lsls r3, r5, 8
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	bge _08180DAE
	strh r1, [r4, 0x24]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x32]
	ldr r0, =sub_8180DC0
	str r0, [r4, 0x1C]
_08180DAE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180D44

	thumb_func_start sub_8180DC0
sub_8180DC0: @ 8180DC0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0xB
	ble _08180E08
	ldrh r0, [r4, 0x32]
	subs r0, 0x2
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	bge _08180DE2
	movs r0, 0
	strh r0, [r4, 0x32]
_08180DE2:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x32]
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08180E1C
	ldr r0, =sub_8180E28
	str r0, [r4, 0x1C]
	b _08180E1C
	.pool
_08180E08:
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	negs r0, r0
	strh r0, [r4, 0x36]
	adds r0, r1, 0x1
	strh r0, [r4, 0x34]
_08180E1C:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8180DC0

	thumb_func_start sub_8180E28
sub_8180E28: @ 8180E28
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	adds r0, 0x2
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	ble _08180E4A
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08180E4A:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180E28

	thumb_func_start pokemonanimfunc_26
pokemonanimfunc_26: @ 8180E5C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r0, 0
	strh r0, [r4, 0x34]
	ldr r0, =sub_8180E78
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_26

	thumb_func_start sub_8180E78
sub_8180E78: @ 8180E78
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x24]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08180EA2
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _08180EA2
	movs r0, 0xA
	strh r0, [r4, 0x34]
_08180EA2:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	ble _08180EBA
	movs r1, 0
	movs r0, 0x8
	strh r0, [r4, 0x24]
	ldr r0, =0x0000fff8
	strh r0, [r4, 0x26]
	strh r1, [r4, 0x36]
	ldr r0, =sub_8180ED0
	str r0, [r4, 0x1C]
_08180EBA:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180E78

	thumb_func_start sub_8180ED0
sub_8180ED0: @ 8180ED0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Cos
	subs r0, 0x8
	strh r0, [r4, 0x24]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	subs r0, 0x8
	strh r0, [r4, 0x26]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _08180F08
	movs r0, 0xA0
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	ldr r0, =sub_8180F2C
	str r0, [r4, 0x1C]
_08180F08:
	ldrh r0, [r4, 0x36]
	adds r0, 0x8
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	ble _08180F1A
	movs r0, 0x40
	strh r0, [r4, 0x36]
_08180F1A:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180ED0

	thumb_func_start sub_8180F2C
sub_8180F2C: @ 8180F2C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08180F44
	subs r0, r1, 0x1
	strh r0, [r4, 0x34]
	b _08180F96
_08180F44:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl Cos
	subs r0, 0x4
	movs r5, 0
	strh r0, [r4, 0x24]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0x5
	bl Sin
	negs r0, r0
	adds r0, 0x4
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	subs r0, 0x4
	strh r0, [r4, 0x32]
	movs r0, 0x32
	ldrsh r3, [r4, r0]
	subs r3, 0x20
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 25
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bgt _08180F96
	strh r5, [r4, 0x24]
	strh r5, [r4, 0x26]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08180F96:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8180F2C

	thumb_func_start pokemonanimfunc_27
pokemonanimfunc_27: @ 8180FA8
	push {r4,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x34]
	movs r2, 0x34
	ldrsh r0, [r3, r2]
	cmp r0, 0
	ble _08180FBA
	subs r0, r1, 0x1
	b _08180FFE
_08180FBA:
	movs r2, 0
	movs r1, 0x36
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08180FC6
	movs r2, 0x1
_08180FC6:
	strh r2, [r3, 0x36]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	lsls r2, 2
	ldrb r1, [r0]
	movs r4, 0x5
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	orrs r0, r2
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _08180FFC
	ldrb r0, [r1]
	adds r1, r4, 0
	ands r1, r0
	mov r2, r12
	strb r1, [r2]
	ldr r0, =sub_8184D88
	str r0, [r3, 0x1C]
_08180FFC:
	movs r0, 0x2
_08180FFE:
	strh r0, [r3, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_27

	thumb_func_start pokemonanimfunc_28
pokemonanimfunc_28: @ 818100C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	ldr r0, =sub_8181024
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_28

	thumb_func_start sub_8181024
sub_8181024: @ 8181024
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	strh r0, [r4, 0x24]
	ldrh r1, [r4, 0x26]
	adds r1, 0x1
	strh r1, [r4, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _08181054
	ldr r0, =0x0000fff0
	strh r0, [r4, 0x24]
	movs r0, 0x10
	strh r0, [r4, 0x26]
	ldr r0, =sub_8181068
	str r0, [r4, 0x1C]
	movs r0, 0xA0
	strh r0, [r4, 0x32]
_08181054:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181024

	thumb_func_start sub_8181068
sub_8181068: @ 8181068
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x32]
	subs r0, 0x4
	strh r0, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x16
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x16
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r0, 0x32
	ldrsh r3, [r4, r0]
	subs r3, 0x20
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 25
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bgt _081810B2
	ldr r0, =sub_81810C4
	str r0, [r4, 0x1C]
_081810B2:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181068

	thumb_func_start sub_81810C4
sub_81810C4: @ 81810C4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x24]
	subs r1, 0x1
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	lsls r1, 16
	cmp r1, 0
	bgt _081810E8
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_081810E8:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81810C4

	thumb_func_start pokemonanimfunc_29
pokemonanimfunc_29: @ 81810F8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	ldr r0, =sub_8181110
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_29

	thumb_func_start sub_8181110
sub_8181110: @ 8181110
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x24]
	adds r1, 0x1
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xF
	ble _08181134
	movs r0, 0
	strh r0, [r4, 0x32]
	ldr r0, =sub_8181144
	str r0, [r4, 0x1C]
_08181134:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181110

	thumb_func_start sub_8181144
sub_8181144: @ 8181144
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	strh r0, [r4, 0x32]
	ldrh r2, [r4, 0x24]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bgt _0818117C
	ldr r0, =0x0000fff0
	strh r0, [r4, 0x24]
	movs r0, 0x10
	strh r0, [r4, 0x26]
	movs r0, 0
	strh r0, [r4, 0x32]
	ldr r0, =sub_81811A4
	str r0, [r4, 0x1C]
	b _08181186
	.pool
_0818117C:
	subs r0, r2, 0x2
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
_08181186:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x32]
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8181144

	thumb_func_start sub_81811A4
sub_81811A4: @ 81811A4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x24]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	lsls r1, 16
	cmp r1, 0
	blt _081811CE
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_081811CE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81811A4

	thumb_func_start pokemonanimfunc_2A
pokemonanimfunc_2A: @ 81811E0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x2
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_8181214
	ldr r0, =sub_8181214
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_2A

	thumb_func_start sub_8181214
sub_8181214: @ 8181214
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r6
	ldrh r0, [r1]
	cmp r0, 0
	beq _08181238
	subs r0, 0x1
	strh r0, [r1]
	b _0818134A
	.pool
_08181238:
	adds r0, r4, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x32]
	movs r1, 0x32
	ldrsh r5, [r4, r1]
	cmp r5, 0
	bne _08181270
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F670
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r0, [r0, 0x2]
	strh r0, [r4, 0x3C]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x34]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3A]
_08181270:
	movs r3, 0x3C
	ldrsh r1, [r4, r3]
	movs r6, 0x34
	ldrsh r0, [r4, r6]
	lsls r0, 1
	muls r1, r0
	ldrh r0, [r4, 0x24]
	adds r1, r0
	strh r1, [r4, 0x24]
	ldrh r2, [r4, 0x3C]
	ldrh r0, [r4, 0x36]
	adds r3, r0, 0
	muls r3, r2
	adds r0, r3, 0
	ldrh r6, [r4, 0x26]
	adds r2, r0, r6
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x8
	strh r0, [r4, 0x3A]
	adds r1, 0xF
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x1E
	bls _081812B8
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 4
	strh r0, [r4, 0x24]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	negs r0, r0
	strh r0, [r4, 0x34]
	b _081812D4
	.pool
_081812B8:
	adds r0, r2, 0
	adds r0, 0xF
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081812DA
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	lsls r0, 4
	strh r0, [r4, 0x26]
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	negs r0, r0
	strh r0, [r4, 0x36]
_081812D4:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_081812DA:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	ble _08181332
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _08181332
	movs r3, 0
	strh r3, [r4, 0x24]
	strh r3, [r4, 0x26]
	ldr r5, =gUnknown_03001240
	movs r6, 0x2E
	ldrsh r0, [r4, r6]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r2, [r1, 0x4]
	movs r6, 0x4
	ldrsh r0, [r1, r6]
	cmp r0, 0x1
	ble _08181328
	subs r0, r2, 0x1
	strh r0, [r1, 0x4]
	strh r3, [r4, 0x38]
	strh r3, [r4, 0x3A]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0xA
	strh r1, [r0]
	b _08181332
	.pool
_08181328:
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08181332:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3A]
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
_0818134A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181214

	thumb_func_start pokemonanimfunc_2B
pokemonanimfunc_2B: @ 8181354
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r0, 0
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8181370
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_2B

	thumb_func_start sub_8181370
sub_8181370: @ 8181370
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3A]
	adds r0, 0x4
	strh r0, [r4, 0x3A]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	movs r1, 0xFF
	ands r0, r1
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0xC0
	ble _081813BA
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081813BA
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	b _081813D2
_081813BA:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	ble _081813DE
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081813DE
	ldr r1, =0xffffff00
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
_081813D2:
	movs r3, 0
	bl sub_817F6D4
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
_081813DE:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _08181404
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08181404:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181370

	thumb_func_start pokemonanimfunc_2C
pokemonanimfunc_2C: @ 8181418
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08181442
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	strh r2, [r4, 0x3A]
	strh r2, [r4, 0x38]
	strh r2, [r4, 0x36]
_08181442:
	ldr r1, =gUnknown_0860AA64
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r2, r0, 1
	adds r0, r1, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08181464
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _081814CE
	.pool
_08181464:
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _0818149A
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08181488
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0x10
	bl BlendPalette
	b _08181494
	.pool
_08181488:
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
_08181494:
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r1, =gUnknown_0860AA64
_0818149A:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _081814C8
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _081814CE
	.pool
_081814C8:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_081814CE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_2C

	thumb_func_start sub_81814D4
sub_81814D4: @ 81814D4
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081814E6
	adds r0, r6, 0
	bl sub_817F670
_081814E6:
	adds r0, r6, 0
	bl sub_817F70C
	ldr r4, =gUnknown_03001240
	movs r3, 0x2E
	ldrsh r1, [r6, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r4
	movs r0, 0x32
	ldrsh r1, [r6, r0]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _0818154C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r3, 0
	strh r3, [r6, 0x24]
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrh r2, [r1, 0x4]
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r0, 0x1
	ble _0818153C
	subs r0, r2, 0x1
	strh r0, [r1, 0x4]
	strh r3, [r6, 0x32]
	b _08181588
	.pool
_0818153C:
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08181588
	.pool
_0818154C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 8
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl Sin
	negs r0, r0
	strh r0, [r6, 0x24]
	movs r5, 0x80
	lsls r5, 1
	ldr r1, =0x00000ccc
	adds r0, r4, 0
	bl Sin
	adds r3, r0, 0
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r5, 0
	bl sub_817F6D4
_08181588:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	adds r0, r6, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81814D4

	thumb_func_start pokemonanimfunc_2D
pokemonanimfunc_2D: @ 81815A0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81814D4
	ldr r0, =sub_81814D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_2D

	thumb_func_start sub_81815D4
sub_81815D4: @ 81815D4
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081815E6
	adds r0, r6, 0
	bl sub_817F670
_081815E6:
	adds r0, r6, 0
	bl sub_817F70C
	ldr r4, =gUnknown_03001240
	movs r3, 0x2E
	ldrsh r1, [r6, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r4
	movs r0, 0x32
	ldrsh r1, [r6, r0]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _0818164C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r3, 0
	strh r3, [r6, 0x24]
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrh r2, [r1, 0x4]
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r0, 0x1
	ble _0818163C
	subs r0, r2, 0x1
	strh r0, [r1, 0x4]
	strh r3, [r6, 0x32]
	b _0818168A
	.pool
_0818163C:
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _0818168A
	.pool
_0818164C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r0, 8
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl Sin
	negs r0, r0
	strh r0, [r6, 0x24]
	movs r5, 0x80
	lsls r5, 1
	ldr r1, =0x00000ccc
	adds r0, r4, 0
	bl Sin
	adds r3, r0, 0
	negs r3, r3
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r5, 0
	bl sub_817F6D4
_0818168A:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	adds r0, r6, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81815D4

	thumb_func_start pokemonanimfunc_2E
pokemonanimfunc_2E: @ 81816A0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81815D4
	ldr r0, =sub_81815D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_2E

	thumb_func_start pokemonanimfunc_2F
pokemonanimfunc_2F: @ 81816D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	adds r0, r4, 0
	adds r0, 0x28
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	movs r1, 0xA
	bl __divsi3
	negs r0, r0
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8181708
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_2F

	thumb_func_start sub_8181708
sub_8181708: @ 8181708
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Cos
	ldrh r1, [r4, 0x3A]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	subs r3, 0x80
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	bgt _08181760
	movs r0, 0x78
	strh r0, [r4, 0x3C]
	movs r0, 0
	strh r0, [r4, 0x34]
	ldr r0, =sub_8181770
	str r0, [r4, 0x1C]
_08181760:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181708

	thumb_func_start sub_8181770
sub_8181770: @ 8181770
	push {lr}
	adds r1, r0, 0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0x14
	bne _08181784
	ldr r0, =sub_8181794
	str r0, [r1, 0x1C]
	movs r0, 0
	strh r0, [r1, 0x34]
_08181784:
	ldrh r0, [r1, 0x34]
	adds r0, 0x1
	strh r0, [r1, 0x34]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181770

	thumb_func_start sub_8181794
sub_8181794: @ 8181794
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	adds r0, 0x2
	movs r6, 0
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Cos
	ldrh r1, [r4, 0x3A]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r5, 0x80
	lsls r5, 1
	ldrh r3, [r4, 0x3C]
	subs r3, 0x80
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r5, 0
	bl sub_817F6D4
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _08181800
	strh r6, [r4, 0x24]
	strh r6, [r4, 0x26]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_817F6D4
	strh r6, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =pokemonanimfunc_10
	str r0, [r4, 0x1C]
_08181800:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181794

	thumb_func_start sub_8181810
sub_8181810: @ 8181810
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrh r0, [r1]
	adds r6, r0, 0
	cmp r6, 0
	beq _08181834
	subs r0, 0x1
	strh r0, [r1]
	b _08181950
	.pool
_08181834:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0818184A
	adds r0, r5, 0
	bl sub_817F670
	strh r6, [r5, 0x36]
	strh r6, [r5, 0x38]
	movs r0, 0x1
	strh r0, [r5, 0x32]
_0818184A:
	movs r3, 0x38
	ldrsh r0, [r5, r3]
	cmp r0, 0
	bne _081818A2
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4, 0
	bl Sin
	strh r0, [r5, 0x3C]
	movs r3, 0x36
	ldrsh r0, [r5, r3]
	movs r1, 0x10
	bl Sin
	strh r0, [r5, 0x26]
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0x20
	bl Sin
	adds r1, r0, 0
	strh r1, [r5, 0x3A]
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r5, 0x3C]
	adds r2, r4
	lsls r2, 16
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl sub_817F6D4
	movs r3, 0x36
	ldrsh r0, [r5, r3]
	cmp r0, 0x80
	bne _0818193A
	strh r6, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	b _0818193A
_081818A2:
	cmp r0, 0x1
	bne _0818193A
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0x20
	bl Sin
	strh r0, [r5, 0x3C]
	movs r3, 0x36
	ldrsh r0, [r5, r3]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r5, 0x26]
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	bl Sin
	adds r1, r0, 0
	strh r1, [r5, 0x3A]
	movs r3, 0x80
	lsls r3, 1
	adds r2, r3, 0
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	ldrh r0, [r5, 0x3C]
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl sub_817F6D4
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	cmp r0, 0x80
	bne _0818193A
	movs r3, 0x2E
	ldrsh r0, [r5, r3]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r2, [r1, 0x4]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	ble _08181922
	subs r0, r2, 0x1
	strh r0, [r1, 0x4]
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xA
	strh r1, [r0]
	strh r6, [r5, 0x36]
	strh r6, [r5, 0x38]
	b _0818193A
_08181922:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r5, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r5, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
_0818193A:
	ldr r2, =gUnknown_03001240
	movs r3, 0x2E
	ldrsh r1, [r5, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
_08181950:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181810

	thumb_func_start pokemonanimfunc_30
pokemonanimfunc_30: @ 8181960
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	bl sub_8181810
	ldr r0, =sub_8181810
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_30

	thumb_func_start pokemonanimfunc_31
pokemonanimfunc_31: @ 8181994
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r4, [r5, r0]
	adds r0, r5, 0
	bl sub_817F70C
	movs r0, 0x80
	lsls r0, 2
	cmp r4, r0
	ble _081819B8
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
	movs r0, 0
	strh r0, [r5, 0x24]
	b _08181A62
	.pool
_081819B8:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _081819C2
	adds r0, 0x7F
_081819C2:
	asrs r0, 7
	cmp r0, 0x1
	beq _081819F8
	cmp r0, 0x1
	bgt _081819D2
	cmp r0, 0
	beq _081819DC
	b _08181A48
_081819D2:
	cmp r0, 0x2
	beq _08181A12
	cmp r0, 0x3
	beq _08181A2A
	b _08181A48
_081819DC:
	adds r0, r4, 0
	cmp r4, 0
	bge _081819E4
	adds r0, 0x7F
_081819E4:
	asrs r0, 7
	lsls r0, 7
	subs r0, r4, r0
	lsls r0, 3
	negs r0, r0
	cmp r0, 0
	bge _081819F4
	adds r0, 0x7F
_081819F4:
	asrs r0, 7
	b _08181A46
_081819F8:
	adds r0, r4, 0
	cmp r4, 0
	bge _08181A00
	adds r0, 0x7F
_08181A00:
	asrs r0, 7
	lsls r0, 7
	subs r0, r4, r0
	cmp r0, 0
	bge _08181A0C
	adds r0, 0xF
_08181A0C:
	asrs r0, 4
	subs r0, 0x8
	b _08181A46
_08181A12:
	adds r0, r4, 0
	cmp r4, 0
	bge _08181A1A
	adds r0, 0x7F
_08181A1A:
	asrs r0, 7
	lsls r0, 7
	subs r0, r4, r0
	cmp r0, 0
	bge _08181A26
	adds r0, 0xF
_08181A26:
	asrs r0, 4
	b _08181A46
_08181A2A:
	adds r0, r4, 0
	cmp r4, 0
	bge _08181A32
	adds r0, 0x7F
_08181A32:
	asrs r0, 7
	lsls r0, 7
	subs r0, r4, r0
	lsls r0, 3
	negs r0, r0
	cmp r0, 0
	bge _08181A42
	adds r0, 0x7F
_08181A42:
	asrs r0, 7
	adds r0, 0x8
_08181A46:
	strh r0, [r5, 0x24]
_08181A48:
	adds r0, r4, 0
	cmp r4, 0
	bge _08181A50
	adds r0, 0x7F
_08181A50:
	asrs r0, 7
	lsls r0, 7
	subs r0, r4, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
_08181A62:
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x32]
	adds r0, 0xC
	strh r0, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_31

	thumb_func_start pokemonanimfunc_32
pokemonanimfunc_32: @ 8181A78
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_817F670
	strh r5, [r4, 0x34]
	adds r0, r4, 0
	bl sub_8181ABC
	ldr r0, =sub_8181ABC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_32

	thumb_func_start sub_8181ABC
sub_8181ABC: @ 8181ABC
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r6
	ldrh r0, [r1]
	adds r5, r0, 0
	cmp r5, 0
	beq _08181AE0
	subs r0, 0x1
	strh r0, [r1]
	b _08181B44
	.pool
_08181AE0:
	adds r0, r4, 0
	bl sub_817F70C
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r0, 0x80
	ble _08181AFC
	strh r5, [r4, 0x32]
	ldr r0, =sub_8181B4C
	str r0, [r4, 0x1C]
	b _08181B3E
	.pool
_08181AFC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	lsls r3, r0, 3
	adds r0, r2, 0
	cmp r2, 0
	bge _08181B16
	adds r0, 0x7F
_08181B16:
	asrs r0, 7
	lsls r0, 7
	subs r1, r2, r0
	adds r0, r3, 0
	muls r0, r1
	cmp r0, 0
	bge _08181B26
	adds r0, 0x7F
_08181B26:
	asrs r0, 7
	strh r0, [r4, 0x24]
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0xC
	strh r0, [r4, 0x32]
_08181B3E:
	adds r0, r4, 0
	bl sub_817F70C
_08181B44:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8181ABC

	thumb_func_start sub_8181B4C
sub_8181B4C: @ 8181B4C
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x30
	ble _08181B7C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r0, 0
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x32]
	ldr r0, =sub_8181C2C
	str r0, [r4, 0x1C]
	b _08181C1A
	.pool
_08181B7C:
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r1, 0x40
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r6, r1, 0
	adds r0, r6
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r0, [r4, 0x32]
	subs r0, 0x10
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _08181BBA
	ldrh r0, [r4, 0x34]
	adds r0, 0x8
	strh r0, [r4, 0x34]
	ldr r2, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x24]
	ldrh r0, [r0, 0x8]
	subs r1, r0
	strh r1, [r4, 0x24]
_08181BBA:
	movs r5, 0
	lsls r1, r3, 16
	asrs r2, r1, 16
	lsls r0, r6, 16
	asrs r0, 16
	adds r6, r1, 0
	cmp r2, r0
	ble _08181BD6
	subs r0, r2
	cmp r0, 0
	bge _08181BD2
	adds r0, 0x7
_08181BD2:
	lsls r0, 13
	lsrs r5, r0, 16
_08181BD6:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Sin
	negs r0, r0
	lsls r1, r5, 16
	asrs r1, 16
	subs r0, r1
	strh r0, [r4, 0x26]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r1, 0x20
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	asrs r2, r6, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x36]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x36]
_08181C1A:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181B4C

	thumb_func_start sub_8181C2C
sub_8181C2C: @ 8181C2C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r3, [r4, r0]
	cmp r3, 0x80
	ble _08181C90
	ldr r3, =gUnknown_03001240
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r2, [r1, 0x4]
	movs r5, 0x4
	ldrsh r0, [r1, r5]
	cmp r0, 0x1
	ble _08181C7C
	subs r0, r2, 0x1
	movs r2, 0
	strh r0, [r1, 0x4]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0xA
	strh r1, [r0]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x32]
	strh r2, [r4, 0x36]
	ldr r0, =sub_8181ABC
	b _08181C84
	.pool
_08181C7C:
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
_08181C84:
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _08181CD0
	.pool
_08181C90:
	ldr r2, =gUnknown_03001240
	movs r5, 0x2E
	ldrsh r1, [r4, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x8
	ldrsh r5, [r0, r1]
	lsls r1, r5, 3
	adds r0, r3, 0
	cmp r3, 0
	bge _08181CAC
	adds r0, 0x7F
_08181CAC:
	asrs r0, 7
	lsls r0, 7
	subs r2, r3, r0
	adds r0, r1, 0
	muls r0, r2
	cmp r0, 0
	bge _08181CBC
	adds r0, 0x7F
_08181CBC:
	asrs r0, 7
	lsls r1, r5, 3
	subs r0, r1
	strh r0, [r4, 0x24]
	lsls r0, r2, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
_08181CD0:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0xC
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181C2C

	thumb_func_start sub_8181CE8
sub_8181CE8: @ 8181CE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08181D00
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08181D00:
	adds r0, r4, 0
	bl sub_817F70C
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0xFE
	ble _08181D60
	movs r5, 0
	strh r5, [r4, 0x24]
	strh r5, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldr r2, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrh r2, [r1, 0x4]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	ble _08181D48
	subs r0, r2, 0x1
	strh r0, [r1, 0x4]
	strh r5, [r4, 0x32]
	strh r5, [r4, 0x3C]
	b _08181D52
	.pool
_08181D48:
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08181D52:
	adds r0, r4, 0
	bl sub_817F70C
	b _08181DA6
	.pool
_08181D60:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	movs r1, 0x20
	bl Sin
	adds r3, r0, 0
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	ldr r2, =gUnknown_03001240
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x6]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F70C
_08181DA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181CE8

	thumb_func_start pokemonanimfunc_33
pokemonanimfunc_33: @ 8181DB0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	bl sub_8181CE8
	ldr r0, =sub_8181CE8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_33

	thumb_func_start pokemonanimfunc_34
pokemonanimfunc_34: @ 8181DE4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08181DFC
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08181DFC:
	adds r0, r4, 0
	bl sub_817F70C
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0xFE
	ble _08181E34
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	adds r0, r4, 0
	bl sub_817F70C
	b _08181E8A
	.pool
_08181E34:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08181E4E
	adds r0, 0x7F
_08181E4E:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	adds r3, r0, 0
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F70C
_08181E8A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_34

	thumb_func_start pokemonanimfunc_35
pokemonanimfunc_35: @ 8181E90
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r1, 0x32
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08181E9E
	strh r0, [r3, 0x3C]
_08181E9E:
	ldrh r4, [r3, 0x32]
	movs r5, 0x32
	ldrsh r1, [r3, r5]
	ldrh r2, [r3, 0x3C]
	movs r5, 0x3C
	ldrsh r0, [r3, r5]
	cmp r1, r0
	bne _08181EC8
	movs r0, 0
	strh r0, [r3, 0x3C]
	adds r0, r4, 0x1
	strh r0, [r3, 0x32]
	adds r1, r3, 0
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r2, r1, 0
	b _08181ED8
_08181EC8:
	adds r0, r2, 0x1
	strh r0, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08181ED8:
	movs r1, 0x32
	ldrsh r0, [r3, r1]
	cmp r0, 0xA
	ble _08181EEE
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	ldr r0, =sub_8184D88
	str r0, [r3, 0x1C]
_08181EEE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_35

	thumb_func_start pokemonanimfunc_36
pokemonanimfunc_36: @ 8181EF8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r0, 0
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8181F14
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_36

	thumb_func_start sub_8181F14
sub_8181F14: @ 8181F14
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x1F
	ble _08181F34
	movs r0, 0
	movs r1, 0x20
	strh r1, [r4, 0x3C]
	strh r0, [r4, 0x32]
	ldr r0, =sub_8181F50
	str r0, [r4, 0x1C]
	b _08181F38
	.pool
_08181F34:
	adds r0, r1, 0x4
	strh r0, [r4, 0x3C]
_08181F38:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8181F14

	thumb_func_start sub_8181F50
sub_8181F50: @ 8181F50
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _08181F74
	ldr r0, =sub_8181FC0
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08181FAE
	.pool
_08181F74:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 4
	negs r0, r0
	cmp r0, 0
	bge _08181F84
	ldr r1, =0x000001ff
	adds r0, r1
_08181F84:
	asrs r0, 9
	strh r0, [r4, 0x24]
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08181F94
	adds r0, 0x7F
_08181F94:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0xC
	strh r0, [r4, 0x32]
_08181FAE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8181F50

	thumb_func_start sub_8181FC0
sub_8181FC0: @ 8181FC0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	subs r0, 0x2
	movs r1, 0
	strh r0, [r4, 0x3C]
	lsls r0, 16
	cmp r0, 0
	bge _08181FEC
	strh r1, [r4, 0x3C]
	strh r1, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08181FFE
	.pool
_08181FEC:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
_08181FFE:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8181FC0

	thumb_func_start pokemonanimfunc_37
pokemonanimfunc_37: @ 818201C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182036
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182036:
	adds r0, r4, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0xFF
	ble _08182060
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _081820A6
	.pool
_08182060:
	adds r0, r1, 0
	adds r0, 0x10
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182072
	adds r0, 0x7F
_08182072:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182092
	adds r0, 0x7F
_08182092:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_081820A6:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081820B2
	adds r0, 0x7F
_081820B2:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	adds r3, r0, 0
	movs r2, 0x80
	lsls r2, 1
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_37

	thumb_func_start pokemonanimfunc_38
pokemonanimfunc_38: @ 81820E0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r0, 0
	strh r0, [r4, 0x3C]
	strh r0, [r4, 0x36]
	ldr r0, =sub_81820FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_38

	thumb_func_start sub_81820FC
sub_81820FC: @ 81820FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x18
	ble _0818212C
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0818214A
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r0, =sub_818216C
	str r0, [r4, 0x1C]
	b _0818214A
	.pool
_0818212C:
	adds r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_0818214A:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81820FC

	thumb_func_start sub_818216C
sub_818216C: @ 818216C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	ble _0818218C
	movs r0, 0x1
	strh r0, [r4, 0x3A]
	ldr r0, =sub_81821CC
	str r0, [r4, 0x1C]
	b _081821AA
	.pool
_0818218C:
	adds r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_081821AA:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_818216C

	thumb_func_start sub_81821CC
sub_81821CC: @ 81821CC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	ble _081821F0
	movs r0, 0x20
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8182248
	str r0, [r4, 0x1C]
_081821F0:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bls _08182224
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_08182224:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81821CC

	thumb_func_start sub_8182248
sub_8182248: @ 8182248
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _08182270
	movs r0, 0
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0818228E
	.pool
_08182270:
	subs r0, r1, 0x2
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
_0818228E:
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3C]
	negs r3, r3
	lsls r3, 24
	lsrs r3, 16
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182248

	thumb_func_start pokemonanimfunc_39
pokemonanimfunc_39: @ 81822B0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _081822D0
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0818235C
	.pool
_081822D0:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _081822DC
	movs r5, 0x1
_081822DC:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	adds r0, r2, 0
	cmp r2, 0
	bge _081822E8
	adds r0, r2, 0x3
_081822E8:
	asrs r0, 2
	lsls r0, 2
	subs r0, r2, r0
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	asrs r1, 1
	cmp r1, 0
	bne _0818232C
	lsls r0, r2, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0818230C
	adds r0, 0xFF
_0818230C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	strh r0, [r4, 0x24]
	negs r0, r0
	b _0818235A
_0818232C:
	lsls r0, r2, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _0818233C
	adds r0, 0xFF
_0818233C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	bl Sin
	lsls r0, 16
	asrs r0, 16
	negs r0, r0
	lsls r1, r5, 24
	asrs r1, 24
	muls r0, r1
	strh r0, [r4, 0x24]
_0818235A:
	strh r0, [r4, 0x26]
_0818235C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_39

	thumb_func_start pokemonanimfunc_3A
pokemonanimfunc_3A: @ 8182370
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182392
	adds r0, r4, 0
	bl sub_817F670
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3A]
	strh r5, [r4, 0x3C]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08182392:
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _081823E4
	subs r0, r1, 0x1
	strh r0, [r4, 0x3A]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _08182494
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 3
	movs r1, 0x14
	bl __divsi3
	adds r1, r0, 0
	ldrh r0, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 16
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x40
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	lsls r0, 16
	asrs r0, 16
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	b _08182494
_081823E4:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	bne _08182424
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _08182410
	movs r0, 0x40
	strh r0, [r4, 0x3C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08182410:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x40
	bl Cos
	lsls r0, 16
	lsrs r3, r0, 16
	b _08182474
	.pool
_08182424:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x40
	bl Sin
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _08182448
	movs r0, 0
	movs r1, 0x3
	strh r1, [r4, 0x38]
	movs r1, 0xA
	strh r1, [r4, 0x3A]
	strh r0, [r4, 0x3C]
	b _08182474
_08182448:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0x30
	ble _0818245C
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0818245C
	movs r0, 0x2
	b _0818246E
_0818245C:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08182474
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08182474
	movs r0, 0x1
_0818246E:
	strh r0, [r4, 0x38]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
_08182474:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x2
	strh r0, [r4, 0x3C]
	movs r0, 0x80
	lsls r0, 1
	adds r2, r0, 0
	lsls r0, r3, 16
	asrs r0, 16
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_08182494:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3A

	thumb_func_start pokemonanimfunc_3B
pokemonanimfunc_3B: @ 81824A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081824BA
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_081824BA:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _081824E8
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08182540
	.pool
_081824E8:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081824F4
	adds r0, 0xFF
_081824F4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182518
	adds r0, 0x7F
_08182518:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	movs r1, 0x80
	lsls r1, 1
	lsls r2, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
_08182540:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3B

	thumb_func_start pokemonanimfunc_3C
pokemonanimfunc_3C: @ 8182548
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182562
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182562:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r5, 0x80
	lsls r5, 1
	cmp r0, r5
	ble _08182590
	movs r0, 0
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _081825D4
	.pool
_08182590:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x4
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081825AE
	adds r0, 0x3F
_081825AE:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x80
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	adds r2, r5
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl sub_817F6D4
_081825D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3C

	thumb_func_start pokemonanimfunc_3D
pokemonanimfunc_3D: @ 81825DC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	ldr r0, =sub_81825F8
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_3D

	thumb_func_start sub_81825F8
sub_81825F8: @ 81825F8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	movs r1, 0
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0818261C
	strh r1, [r4, 0x3C]
	strh r1, [r4, 0x3A]
	ldr r0, =sub_8182648
	str r0, [r4, 0x1C]
	movs r0, 0x40
	b _08182620
	.pool
_0818261C:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
_08182620:
	movs r1, 0x80
	bl Sin
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	lsls r2, r0, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81825F8

	thumb_func_start sub_8182648
sub_8182648: @ 8182648
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x4
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5F
	ble _08182672
	movs r0, 0
	movs r1, 0x80
	bl Cos
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _081826C8
_08182672:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	lsls r1, 2
	negs r1, r1
	subs r1, r0
	strh r1, [r4, 0x26]
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _081826A4
	ldr r5, =0x0000ffff
	adds r0, r1, 0
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	b _081826A8
	.pool
_081826A4:
	movs r5, 0x1
	movs r0, 0
_081826A8:
	lsls r0, 16
	asrs r0, 15
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x80
	bl Cos
	lsls r1, r5, 16
	asrs r1, 16
	adds r2, r1, 0
	muls r2, r0
	adds r0, r2, 0
	lsls r0, 16
	lsrs r2, r0, 16
_081826C8:
	movs r1, 0x80
	lsls r1, 1
	lsls r2, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	bne _081826EE
	movs r0, 0
	strh r0, [r4, 0x3C]
	ldr r0, =sub_81826F8
	str r0, [r4, 0x1C]
_081826EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8182648

	thumb_func_start sub_81826F8
sub_81826F8: @ 81826F8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	bl Cos
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0xC
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x3F
	ble _08182742
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_08182742:
	movs r1, 0x80
	lsls r1, 1
	lsls r2, r5, 16
	asrs r2, 16
	adds r2, r1
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81826F8

	thumb_func_start sub_8182764
sub_8182764: @ 8182764
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08182798
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	b _081827F4
	.pool
_08182798:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081827A4
	adds r0, 0xFF
_081827A4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _081827CC
	adds r0, 0x7F
_081827CC:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
_081827F4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182764

	thumb_func_start pokemonanimfunc_3E
pokemonanimfunc_3E: @ 81827FC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182822
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r1, 0x8
	strh r1, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
_08182822:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3E

	thumb_func_start sub_8182830
sub_8182830: @ 8182830
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08182864
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	b _081828C0
	.pool
_08182864:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182870
	adds r0, 0xFF
_08182870:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182898
	adds r0, 0x3F
_08182898:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x80
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F6D4
_081828C0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8182830

	thumb_func_start pokemonanimfunc_3F
pokemonanimfunc_3F: @ 81828C8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081828EE
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	adds r0, 0xFC
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_081828EE:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_3F

	thumb_func_start pokemonanimfunc_40
pokemonanimfunc_40: @ 81828FC
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _0818291A
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_0818291A:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _08182948
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0818299E
	.pool
_08182948:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182954
	adds r0, 0xFF
_08182954:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182978
	adds r0, 0x7F
_08182978:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_0818299E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_40

	thumb_func_start pokemonanimfunc_41
pokemonanimfunc_41: @ 81829AC
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081829CA
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_081829CA:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _081829F8
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08182A5E
	.pool
_081829F8:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182A04
	adds r1, 0xFF
_08182A04:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x10
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182A30
	adds r1, 0xFF
_08182A30:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x40
	bl Sin
	adds r2, r0, 0
	negs r2, r2
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_08182A5E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_41

	thumb_func_start pokemonanimfunc_42
pokemonanimfunc_42: @ 8182A6C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08182A8A
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
_08182A8A:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	ble _08182AB8
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08182B16
	.pool
_08182AB8:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182AC4
	adds r0, 0xFF
_08182AC4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	adds r1, r0, 0
	cmp r0, 0
	bge _08182AEA
	adds r1, 0xFF
_08182AEA:
	asrs r1, 8
	lsls r1, 8
	subs r1, r0, r1
	lsls r1, 16
	asrs r0, r1, 16
	lsrs r1, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x60
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_08182B16:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_42

	thumb_func_start pokemonanimfunc_43
pokemonanimfunc_43: @ 8182B24
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08182B48
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08182C08
	.pool
_08182B48:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08182B56
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08182B56:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08182B62
	adds r0, r1, 0x3
_08182B62:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08182BA4
	cmp r0, 0x1
	bgt _08182B80
	cmp r0, 0
	beq _08182B8A
	b _08182BE2
	.pool
_08182B80:
	cmp r0, 0x2
	beq _08182BB8
	cmp r0, 0x3
	beq _08182BCA
	b _08182BE2
_08182B8A:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08182B9C
	ldr r1, =0x000001ff
	adds r0, r1
_08182B9C:
	asrs r0, 9
	b _08182BE0
	.pool
_08182BA4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08182BB2
	adds r0, 0x1F
_08182BB2:
	asrs r0, 5
	subs r0, 0x10
	b _08182BE0
_08182BB8:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08182BC6
	adds r0, 0x1F
_08182BC6:
	asrs r0, 5
	b _08182BE0
_08182BCA:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08182BDC
	ldr r1, =0x000001ff
	adds r0, r1
_08182BDC:
	asrs r0, 9
	adds r0, 0x10
_08182BE0:
	strh r0, [r4, 0x24]
_08182BE2:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08182BEE
	adds r0, 0x7F
_08182BEE:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x18
	strh r0, [r4, 0x32]
_08182C08:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_43

	thumb_func_start pokemonanimfunc_44
pokemonanimfunc_44: @ 8182C18
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08182C34
	strh r0, [r4, 0x3A]
	movs r0, 0x40
	strh r0, [r4, 0x3C]
	adds r0, r1, 0x1
	strh r0, [r4, 0x32]
_08182C34:
	ldrh r0, [r4, 0x3C]
	adds r1, r0, 0
	adds r1, 0x8
	movs r3, 0
	strh r1, [r4, 0x3C]
	ldrh r2, [r4, 0x3A]
	movs r5, 0x3A
	ldrsh r0, [r4, r5]
	cmp r0, 0x4
	bne _08182C52
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _08182C60
	b _08182C5A
_08182C52:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _08182C60
_08182C5A:
	strh r3, [r4, 0x3C]
	adds r0, r2, 0x1
	strh r0, [r4, 0x3A]
_08182C60:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _08182D08
	lsls r0, 2
	ldr r1, =_08182C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08182C78:
	.4byte _08182CEC
	.4byte _08182C8C
	.4byte _08182CAA
	.4byte _08182CCC
	.4byte _08182CEC
_08182C8C:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r5, 0x3C
	ldrsh r0, [r4, r5]
	movs r1, 0x8
	bl Sin
	subs r0, 0x8
	strh r0, [r4, 0x26]
	b _08182D12
_08182CAA:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	adds r0, 0x8
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	b _08182D12
_08182CCC:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	adds r0, 0x8
	strh r0, [r4, 0x26]
	b _08182D12
_08182CEC:
	movs r5, 0x3C
	ldrsh r0, [r4, r5]
	movs r1, 0x8
	bl Sin
	subs r0, 0x8
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x26]
	b _08182D12
_08182D08:
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_08182D12:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_44

	thumb_func_start pokemonanimfunc_45
pokemonanimfunc_45: @ 8182D24
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x20
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_8180714
	ldr r0, =sub_8180714
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_45

	thumb_func_start pokemonanimfunc_46
pokemonanimfunc_46: @ 8182D40
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F8FC
	ldr r0, =sub_817F8FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_46

	thumb_func_start pokemonanimfunc_47
pokemonanimfunc_47: @ 8182D5C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F978
	ldr r0, =sub_817F978
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_47

	thumb_func_start pokemonanimfunc_48
pokemonanimfunc_48: @ 8182D78
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0x6]
	ldrh r0, [r4, 0x3A]
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_8180900
	ldr r0, =sub_8180900
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_48

	thumb_func_start pokemonanimfunc_49
pokemonanimfunc_49: @ 8182DB4
	push {lr}
	movs r1, 0x1
	strh r1, [r0, 0x3A]
	bl pokemonanimfunc_05
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_49

	thumb_func_start pokemonanimfunc_4A
pokemonanimfunc_4A: @ 8182DC4
	push {lr}
	movs r1, 0x1
	strh r1, [r0, 0x3A]
	bl pokemonanimfunc_48
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_4A

	thumb_func_start pokemonanimfunc_4B
pokemonanimfunc_4B: @ 8182DD4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08182DE2
	strh r0, [r4, 0x2E]
_08182DE2:
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _08182DF6
	adds r0, r4, 0
	bl sub_817FC20
	movs r0, 0x1
	b _08182DF8
_08182DF6:
	subs r0, r1, 0x1
_08182DF8:
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_4B

	thumb_func_start pokemonanimfunc_4C
pokemonanimfunc_4C: @ 8182E00
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817FCDC
	ldr r0, =sub_817FCDC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4C

	thumb_func_start pokemonanimfunc_4D
pokemonanimfunc_4D: @ 8182E20
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817FD44
	ldr r0, =sub_817FD44
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4D

	thumb_func_start pokemonanimfunc_4E
pokemonanimfunc_4E: @ 8182E3C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r1, 0x6]
	strh r3, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_817FE30
	ldr r0, =sub_817FE30
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4E

	thumb_func_start pokemonanimfunc_4F
pokemonanimfunc_4F: @ 8182E7C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r1, 0x6]
	movs r0, 0x3
	strh r0, [r1, 0x8]
	movs r0, 0xC
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_817FFF0
	ldr r0, =sub_817FFF0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_4F

	thumb_func_start pokemonanimfunc_50
pokemonanimfunc_50: @ 8182EBC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x18
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_818031C
	ldr r0, =sub_818031C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_50

	thumb_func_start pokemonanimfunc_51
pokemonanimfunc_51: @ 8182ED8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_81804F8
	ldr r0, =sub_81804F8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_51

	thumb_func_start pokemonanimfunc_52
pokemonanimfunc_52: @ 8182EF4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F9F4
	ldr r0, =sub_817F9F4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_52

	thumb_func_start pokemonanimfunc_53
pokemonanimfunc_53: @ 8182F10
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x3C
	strh r0, [r1]
	movs r0, 0x1E
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_817FF3C
	ldr r0, =sub_817FF3C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_53

	thumb_func_start pokemonanimfunc_54
pokemonanimfunc_54: @ 8182F48
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x2]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181214
	ldr r0, =sub_8181214
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_54

	thumb_func_start pokemonanimfunc_55
pokemonanimfunc_55: @ 8182F80
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181810
	ldr r0, =sub_8181810
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_55

	thumb_func_start pokemonanimfunc_56
pokemonanimfunc_56: @ 8182FB8
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_817F670
	strh r5, [r4, 0x34]
	adds r0, r4, 0
	bl sub_8181ABC
	ldr r0, =sub_8181ABC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_56

	thumb_func_start pokemonanimfunc_07
pokemonanimfunc_07: @ 8182FFC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x2
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	bl sub_8181CE8
	ldr r0, =sub_8181CE8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_07

	thumb_func_start pokemonanimfunc_08
pokemonanimfunc_08: @ 8183030
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x4
	strh r0, [r1, 0x6]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_8181CE8
	ldr r0, =sub_8181CE8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_08

	thumb_func_start pokemonanimfunc_0B
pokemonanimfunc_0B: @ 8183068
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x64
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81814D4
	ldr r0, =sub_81814D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0B

	thumb_func_start pokemonanimfunc_0C
pokemonanimfunc_0C: @ 818309C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81814D4
	ldr r0, =sub_81814D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0C

	thumb_func_start pokemonanimfunc_0D
pokemonanimfunc_0D: @ 81830D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x64
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	bl sub_81815D4
	ldr r0, =sub_81815D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0D

	thumb_func_start pokemonanimfunc_0E
pokemonanimfunc_0E: @ 8183108
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x32
	strh r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81815D4
	ldr r0, =sub_81815D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_0E

	thumb_func_start sub_8183140
sub_8183140: @ 8183140
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r0, 0x90
	lsls r0, 4
	cmp r2, r0
	ble _0818315C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _08183180
	.pool
_0818315C:
	adds r1, r2, 0
	adds r1, 0xC0
	adds r0, r1, 0
	cmp r1, 0
	bge _0818316A
	ldr r3, =0x000001bf
	adds r0, r2, r3
_0818316A:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x3C]
	adds r0, r1
_08183180:
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	ldrh r3, [r4, 0x32]
	adds r0, r3
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8183140

	thumb_func_start pokemonanimfunc_57
pokemonanimfunc_57: @ 8183194
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_57

	thumb_func_start pokemonanimfunc_58
pokemonanimfunc_58: @ 81831B4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_58

	thumb_func_start pokemonanimfunc_59
pokemonanimfunc_59: @ 81831D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _081831F8
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _081832BC
	.pool
_081831F8:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08183206
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08183206:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08183212
	adds r0, r1, 0x3
_08183212:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183268
	cmp r0, 0x1
	bgt _08183230
	cmp r0, 0
	beq _0818323A
	b _08183298
	.pool
_08183230:
	cmp r0, 0x2
	beq _0818324C
	cmp r0, 0x3
	beq _08183284
	b _08183298
_0818323A:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183248
	adds r0, 0x1F
_08183248:
	asrs r0, 5
	b _08183296
_0818324C:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _0818325E
	ldr r1, =0x000001ff
	adds r0, r1
_0818325E:
	asrs r0, 9
	b _08183296
	.pool
_08183268:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _0818327A
	ldr r1, =0x000001ff
	adds r0, r1
_0818327A:
	asrs r0, 9
	adds r0, 0x10
	b _08183296
	.pool
_08183284:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183292
	adds r0, 0x1F
_08183292:
	asrs r0, 5
	subs r0, 0x10
_08183296:
	strh r0, [r4, 0x24]
_08183298:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081832A4
	adds r0, 0x7F
_081832A4:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x18
	strh r0, [r4, 0x32]
_081832BC:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_59

	thumb_func_start sub_81832C8
sub_81832C8: @ 81832C8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0x38
	ldrsh r1, [r6, r2]
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818331A
	mov r0, r8
	strh r0, [r6, 0x26]
	strh r0, [r6, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r1, [r6, 0x36]
	movs r2, 0x36
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bgt _08183310
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _081833DC
	.pool
_08183310:
	subs r0, r1, 0x1
	strh r0, [r6, 0x36]
	mov r0, r8
	strh r0, [r6, 0x3C]
	b _081833DC
_0818331A:
	movs r1, 0x38
	ldrsh r5, [r6, r1]
	lsls r0, r5, 7
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r4, 0
	bge _08183334
	adds r4, 0x3
_08183334:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r1
	blt _08183358
	cmp r5, r0
	bge _08183358
	ldrh r0, [r6, 0x3C]
	adds r0, 0x33
	strh r0, [r6, 0x3C]
	movs r1, 0xFF
	mov r8, r1
	ands r1, r0
	mov r8, r1
_08183358:
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0818337C
	lsls r4, r2, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	ldr r2, =0xffffff00
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	b _08183392
	.pool
_0818337C:
	lsls r4, r2, 16
	asrs r0, r4, 16
	movs r1, 0x10
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
_08183392:
	adds r7, r4, 0
	ldrh r4, [r6, 0x34]
	lsls r4, 24
	lsrs r4, 24
	mov r5, r8
	adds r0, r4, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl Sin
	adds r5, r0, 0
	asrs r0, r7, 16
	adds r1, r4, 0
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	subs r2, r5
	subs r2, r0
	mov r0, r9
	lsls r1, r0, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F618
	ldrh r0, [r6, 0x38]
	adds r0, 0x1
	strh r0, [r6, 0x38]
_081833DC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81832C8

	thumb_func_start pokemonanimfunc_5A
pokemonanimfunc_5A: @ 81833E8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _0818340A
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_0818340A:
	adds r0, r5, 0
	bl sub_81832C8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5A

	thumb_func_start sub_8183418
sub_8183418: @ 8183418
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0x38
	ldrsh r1, [r6, r2]
	movs r2, 0x3A
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818346A
	mov r0, r8
	strh r0, [r6, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r1, [r6, 0x36]
	movs r2, 0x36
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bgt _08183460
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08183538
	.pool
_08183460:
	subs r0, r1, 0x1
	strh r0, [r6, 0x36]
	mov r0, r8
	strh r0, [r6, 0x3C]
	b _08183538
_0818346A:
	movs r1, 0x38
	ldrsh r5, [r6, r1]
	lsls r0, r5, 7
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r4, 0
	bge _08183486
	adds r4, 0x3
_08183486:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r1
	blt _081834AC
	cmp r5, r0
	bge _081834AC
	ldrh r0, [r6, 0x3C]
	adds r0, 0x33
	strh r0, [r6, 0x3C]
	movs r1, 0xFF
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
_081834AC:
	ldrh r0, [r6, 0x34]
	lsls r0, 24
	lsrs r7, r0, 24
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081834F0
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	adds r1, r7, 0
	bl Sin
	adds r4, r0, 0
	mov r5, r8
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r5, 0
	bl Sin
	ldr r1, =0xffffff00
	adds r0, r1
	adds r4, r0
	lsls r4, 16
	lsrs r1, r4, 16
	b _08183522
	.pool
_081834F0:
	mov r4, r8
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r4, 0
	bl Sin
	adds r4, r0, 0
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	adds r1, r7, 0
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r4
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
_08183522:
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F618
	ldrh r0, [r6, 0x38]
	adds r0, 0x1
	strh r0, [r6, 0x38]
_08183538:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183418

	thumb_func_start pokemonanimfunc_5B
pokemonanimfunc_5B: @ 8183544
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183566
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183566:
	adds r0, r5, 0
	bl sub_8183418
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5B

	thumb_func_start sub_8183574
sub_8183574: @ 8183574
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r3, =gUnknown_0860AA80
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r0, r1, r3
	ldrb r5, [r0]
	adds r2, r5, 0
	cmp r5, 0xFF
	beq _081835A6
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r5, r0, 24
_081835A6:
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	movs r7, 0
	cmp r2, 0xFE
	beq _081835C2
	mov r1, r9
	subs r0, r6, r1
	muls r0, r5
	adds r1, r6, 0
	bl __divsi3
	lsls r0, 24
	lsrs r7, r0, 24
_081835C2:
	cmp r5, 0xFF
	bne _081835D8
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0818360A
	.pool
_081835D8:
	mov r1, r8
	adds r1, 0xC0
	adds r0, r1, 0
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	adds r1, r7, 0
	bl Sin
	adds r0, r7
	strh r0, [r4, 0x26]
	cmp r9, r6
	bne _081835FC
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r0, 0
	b _08183608
_081835FC:
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
_08183608:
	strh r0, [r4, 0x3A]
_0818360A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183574

	thumb_func_start pokemonanimfunc_5C
pokemonanimfunc_5C: @ 8183618
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x28
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5C

	thumb_func_start pokemonanimfunc_5D
pokemonanimfunc_5D: @ 8183638
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x46
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_817FCDC
	ldr r0, =sub_817FCDC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5D

	thumb_func_start pokemonanimfunc_5E
pokemonanimfunc_5E: @ 8183658
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_817F8FC
	ldr r0, =sub_817F8FC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_5E

	thumb_func_start pokemonanimfunc_5F
pokemonanimfunc_5F: @ 8183674
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _08183690
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _081836CA
	.pool
_08183690:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _0818369C
	movs r5, 0x1
_0818369C:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081836B0
	adds r0, 0xFF
_081836B0:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x9
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
_081836CA:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5F

	thumb_func_start pokemonanimfunc_60
pokemonanimfunc_60: @ 81836D8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x28
	ble _081836F4
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	b _0818372E
	.pool
_081836F4:
	movs r0, 0x1
	ands r0, r1
	movs r5, 0xFF
	cmp r0, 0
	bne _08183700
	movs r5, 0x1
_08183700:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r1, 0x28
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _08183714
	adds r0, 0xFF
_08183714:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xC
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
_0818372E:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_60

	thumb_func_start pokemonanimfunc_61
pokemonanimfunc_61: @ 818373C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x46
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183140
	ldr r0, =sub_8183140
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_61

	thumb_func_start pokemonanimfunc_62
pokemonanimfunc_62: @ 818375C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x18
	strh r0, [r4, 0x2E]
	movs r0, 0x6
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_62

	thumb_func_start pokemonanimfunc_63
pokemonanimfunc_63: @ 818377C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x38
	strh r0, [r4, 0x2E]
	movs r0, 0x9
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	bl sub_8183574
	ldr r0, =sub_8183574
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_63

	thumb_func_start pokemonanimfunc_64
pokemonanimfunc_64: @ 818379C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gUnknown_03001240
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r1, 0x6]
	movs r0, 0x6
	strh r0, [r1, 0x8]
	movs r0, 0x18
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	bl sub_817FFF0
	ldr r0, =sub_817FFF0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_64

	thumb_func_start sub_81837DC
sub_81837DC: @ 81837DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	movs r5, 0
	movs r0, 0x38
	ldrsh r1, [r7, r0]
	movs r2, 0x3A
	ldrsh r0, [r7, r2]
	cmp r1, r0
	ble _0818382C
	strh r5, [r7, 0x26]
	strh r5, [r7, 0x38]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r7, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	ldrh r1, [r7, 0x36]
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	cmp r0, 0x1
	bgt _08183824
	adds r0, r7, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r7, 0x1C]
	b _0818392C
	.pool
_08183824:
	subs r0, r1, 0x1
	strh r0, [r7, 0x36]
	strh r5, [r7, 0x3C]
	b _0818392C
_0818382C:
	movs r0, 0x38
	ldrsh r6, [r7, r0]
	lsls r0, r6, 7
	movs r1, 0x3A
	ldrsh r4, [r7, r1]
	adds r1, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r4, 0
	bge _08183846
	adds r4, 0x3
_08183846:
	asrs r1, r4, 2
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r1
	blt _08183866
	cmp r6, r0
	bge _08183866
	ldrh r0, [r7, 0x3C]
	adds r0, 0x33
	strh r0, [r7, 0x3C]
	movs r5, 0xFF
	ands r5, r0
_08183866:
	ldrh r0, [r7, 0x34]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _081838B0
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	mov r1, r9
	bl Sin
	adds r4, r0, 0
	lsls r6, r5, 16
	asrs r5, r6, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r5, 0
	bl Sin
	ldr r2, =0xffffff00
	adds r4, r2
	adds r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r0, r8
	b _081838EA
	.pool
_081838B0:
	lsls r2, 16
	mov r8, r2
	asrs r0, r2, 16
	mov r1, r9
	bl Sin
	adds r6, r0, 0
	lsls r5, 16
	asrs r4, r5, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 23
	adds r0, r4, 0
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r6
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	mov r0, r8
	adds r6, r5, 0
_081838EA:
	asrs r0, 16
	mov r1, r9
	bl Sin
	adds r5, r0, 0
	asrs r4, r6, 16
	mov r0, r9
	movs r1, 0x5
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r2, r1, 0
	subs r2, r5
	subs r2, r0
	mov r0, r10
	lsls r1, r0, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r7, 0
	movs r3, 0
	bl sub_817F618
	ldrh r0, [r7, 0x38]
	adds r0, 0x1
	strh r0, [r7, 0x38]
_0818392C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81837DC

	thumb_func_start pokemonanimfunc_65
pokemonanimfunc_65: @ 818393C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _0818395E
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_0818395E:
	adds r0, r5, 0
	bl sub_81837DC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_65

	thumb_func_start pokemonanimfunc_66
pokemonanimfunc_66: @ 818396C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08183990
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08183A54
	.pool
_08183990:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _0818399E
	ldr r1, =0x000001ff
	adds r0, r2, r1
_0818399E:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _081839AA
	adds r0, r1, 0x3
_081839AA:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183A00
	cmp r0, 0x1
	bgt _081839C8
	cmp r0, 0
	beq _081839D2
	b _08183A30
	.pool
_081839C8:
	cmp r0, 0x2
	beq _081839E4
	cmp r0, 0x3
	beq _08183A1C
	b _08183A30
_081839D2:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081839E0
	adds r0, 0x1F
_081839E0:
	asrs r0, 5
	b _08183A2E
_081839E4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _081839F6
	ldr r1, =0x000001ff
	adds r0, r1
_081839F6:
	asrs r0, 9
	b _08183A2E
	.pool
_08183A00:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183A12
	ldr r1, =0x000001ff
	adds r0, r1
_08183A12:
	asrs r0, 9
	adds r0, 0x10
	b _08183A2E
	.pool
_08183A1C:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183A2A
	adds r0, 0x1F
_08183A2A:
	asrs r0, 5
	subs r0, 0x10
_08183A2E:
	strh r0, [r4, 0x24]
_08183A30:
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08183A3C
	adds r0, 0x7F
_08183A3C:
	asrs r0, 7
	lsls r0, 7
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x30
	strh r0, [r4, 0x32]
_08183A54:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_66

	thumb_func_start pokemonanimfunc_67
pokemonanimfunc_67: @ 8183A60
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	ble _08183A84
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3A]
	b _08183B40
	.pool
_08183A84:
	movs r1, 0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, 0
	cmp r2, 0
	bge _08183A92
	ldr r1, =0x000001ff
	adds r0, r2, r1
_08183A92:
	asrs r3, r0, 9
	adds r1, r3, 0
	adds r0, r1, 0
	cmp r1, 0
	bge _08183A9E
	adds r0, r1, 0x3
_08183A9E:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _08183AF4
	cmp r0, 0x1
	bgt _08183ABC
	cmp r0, 0
	beq _08183AC6
	b _08183B24
	.pool
_08183ABC:
	cmp r0, 0x2
	beq _08183AD8
	cmp r0, 0x3
	beq _08183B10
	b _08183B24
_08183AC6:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183AD4
	adds r0, 0x1F
_08183AD4:
	asrs r0, 5
	b _08183B22
_08183AD8:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183AEA
	ldr r1, =0x000001ff
	adds r0, r1
_08183AEA:
	asrs r0, 9
	b _08183B22
	.pool
_08183AF4:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 12
	negs r0, r0
	cmp r0, 0
	bge _08183B06
	ldr r1, =0x000001ff
	adds r0, r1
_08183B06:
	asrs r0, 9
	adds r0, 0x10
	b _08183B22
	.pool
_08183B10:
	lsls r0, r3, 9
	subs r0, r2, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08183B1E
	adds r0, 0x1F
_08183B1E:
	asrs r0, 5
	subs r0, 0x10
_08183B22:
	strh r0, [r4, 0x24]
_08183B24:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x60
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x40
	strh r0, [r4, 0x32]
_08183B40:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_67

	thumb_func_start sub_8183B4C
sub_8183B4C: @ 8183B4C
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183B5E
	strh r0, [r4, 0x34]
_08183B5E:
	ldr r7, =gUnknown_0860ADBE
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	adds r5, r7, 0x2
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl __divsi3
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08183B8C
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x34]
	strh r1, [r4, 0x32]
_08183B8C:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r6, r0, r1
	adds r0, r6, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x38
	ldrsh r5, [r4, r1]
	adds r1, r5, 0
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bne _08183BCC
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	cmp r0, 0
	bne _08183BC8
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08183C06
	.pool
_08183BC8:
	strh r1, [r4, 0x32]
	b _08183C06
_08183BCC:
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r0, r5
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r1, r7, 0x1
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, 0x38]
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F70C
_08183C06:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8183B4C

	thumb_func_start pokemonanimfunc_68
pokemonanimfunc_68: @ 8183C0C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x38]
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_68

	thumb_func_start pokemonanimfunc_69
pokemonanimfunc_69: @ 8183C2C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strh r0, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_69

	thumb_func_start pokemonanimfunc_6A
pokemonanimfunc_6A: @ 8183C4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strh r0, [r4, 0x38]
	strh r0, [r4, 0x3A]
	adds r0, r4, 0
	bl sub_8183B4C
	ldr r0, =sub_8183B4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_6A

	thumb_func_start sub_8183C6C
sub_8183C6C: @ 8183C6C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0xFF
	ble _08183CAE
	ldrh r1, [r4, 0x38]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _08183CA4
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	b _08183CE8
	.pool
_08183CA4:
	subs r0, r1, 0x1
	movs r1, 0
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x3C]
	b _08183CE8
_08183CAE:
	ldrh r0, [r4, 0x3A]
	adds r0, r1, r0
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x80
	lsls r5, 1
	cmp r0, r5
	ble _08183CC2
	strh r5, [r4, 0x3C]
_08183CC2:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x40
	bl Sin
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	subs r2, r5, r2
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
_08183CE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8183C6C

	thumb_func_start pokemonanimfunc_6B
pokemonanimfunc_6B: @ 8183CF0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D16
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	movs r0, 0x1
	strh r0, [r4, 0x38]
_08183D16:
	adds r0, r4, 0
	bl sub_8183C6C
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6B

	thumb_func_start pokemonanimfunc_6C
pokemonanimfunc_6C: @ 8183D28
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_817F70C
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D4E
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x2
	strh r0, [r4, 0x38]
_08183D4E:
	adds r0, r4, 0
	bl sub_8183C6C
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6C

	thumb_func_start pokemonanimfunc_6D
pokemonanimfunc_6D: @ 8183D60
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183D88
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183D88:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6D

	thumb_func_start pokemonanimfunc_6E
pokemonanimfunc_6E: @ 8183D94
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183DBA
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
	adds r0, 0xFC
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183DBA:
	adds r0, r4, 0
	bl sub_8182764
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6E

	thumb_func_start pokemonanimfunc_6F
pokemonanimfunc_6F: @ 8183DC8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183DF0
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	movs r0, 0x10
	strh r0, [r4, 0x36]
_08183DF0:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6F

	thumb_func_start pokemonanimfunc_70
pokemonanimfunc_70: @ 8183DFC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183E22
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x3C]
	movs r1, 0x8
	strh r1, [r4, 0x3A]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
_08183E22:
	adds r0, r4, 0
	bl sub_8182830
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_70

	thumb_func_start pokemonanimfunc_71
pokemonanimfunc_71: @ 8183E30
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183E4A
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x5
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
_08183E4A:
	adds r0, r4, 0
	bl sub_8180828
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_71

	thumb_func_start pokemonanimfunc_72
pokemonanimfunc_72: @ 8183E58
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08183E72
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x3
	strh r0, [r4, 0x3C]
	movs r0, 0x4
	strh r0, [r4, 0x3A]
_08183E72:
	adds r0, r4, 0
	bl sub_8180828
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_72

	thumb_func_start pokemonanimfunc_73
pokemonanimfunc_73: @ 8183E80
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183EA2
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x3C]
_08183EA2:
	adds r0, r5, 0
	bl sub_81832C8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_73

	thumb_func_start pokemonanimfunc_74
pokemonanimfunc_74: @ 8183EB0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183ED4
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x3C]
_08183ED4:
	adds r0, r4, 0
	bl sub_81832C8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_74

	thumb_func_start pokemonanimfunc_75
pokemonanimfunc_75: @ 8183EE0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183F06
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3C]
_08183F06:
	adds r0, r4, 0
	bl sub_8183418
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_75

	thumb_func_start pokemonanimfunc_76
pokemonanimfunc_76: @ 8183F14
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183F38
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183F38:
	adds r0, r5, 0
	bl sub_8183418
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_76

	thumb_func_start pokemonanimfunc_77
pokemonanimfunc_77: @ 8183F44
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08183F6A
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x2
	strh r0, [r4, 0x36]
	movs r0, 0x14
	strh r0, [r4, 0x3A]
	movs r0, 0x46
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x38]
	strh r5, [r4, 0x3C]
_08183F6A:
	adds r0, r4, 0
	bl sub_81837DC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_77

	thumb_func_start pokemonanimfunc_78
pokemonanimfunc_78: @ 8183F78
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x32
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08183F9C
	movs r4, 0x1
	strh r4, [r5, 0x32]
	adds r0, r5, 0
	bl sub_817F670
	strh r4, [r5, 0x36]
	movs r0, 0x1E
	strh r0, [r5, 0x3A]
	movs r0, 0x3C
	strh r0, [r5, 0x34]
	strh r6, [r5, 0x38]
	strh r6, [r5, 0x3C]
_08183F9C:
	adds r0, r5, 0
	bl sub_81837DC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_78

	thumb_func_start sub_8183FA8
sub_8183FA8: @ 8183FA8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _08183FEA
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bgt _08183FD0
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	b _0818403E
	.pool
_08183FD0:
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08183FDC
	adds r0, 0xFF
_08183FDC:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	strh r0, [r4, 0x3C]
	subs r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _0818403E
_08183FEA:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r3, 0x3C
	ldrsh r2, [r4, r3]
	adds r1, r2, 0
	adds r1, 0xC0
	adds r0, r1, 0
	cmp r1, 0
	bge _0818400C
	ldr r3, =0x000001bf
	adds r0, r2, r3
_0818400C:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	ble _0818402E
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	negs r0, r0
	strh r0, [r4, 0x26]
_0818402E:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	strh r0, [r4, 0x3C]
_0818403E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8183FA8

	thumb_func_start pokemonanimfunc_79
pokemonanimfunc_79: @ 8184048
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _08184066
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x4
	strh r0, [r1, 0x34]
_08184066:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_79

	thumb_func_start pokemonanimfunc_7A
pokemonanimfunc_7A: @ 8184070
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0818408E
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x6
	strh r0, [r1, 0x34]
_0818408E:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7A

	thumb_func_start pokemonanimfunc_7B
pokemonanimfunc_7B: @ 8184098
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _081840B8
	movs r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0x2
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0xC
	strh r0, [r1, 0x38]
	strh r0, [r1, 0x36]
	movs r0, 0x8
	strh r0, [r1, 0x34]
_081840B8:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7B

	thumb_func_start sub_81840C4
sub_81840C4: @ 81840C4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	ble _081840FC
	movs r2, 0x3A
	ldrsh r1, [r5, r2]
	ldrh r2, [r5, 0x36]
	movs r3, 0x36
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bgt _081840EC
	ldr r0, =sub_8184D88
	str r0, [r5, 0x1C]
	b _081840F4
	.pool
_081840EC:
	adds r0, r2, 0x1
	movs r1, 0
	strh r0, [r5, 0x36]
	strh r1, [r5, 0x3C]
_081840F4:
	movs r0, 0
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	b _08184188
_081840FC:
	cmp r0, 0x9F
	ble _08184126
	cmp r0, r1
	ble _08184106
	strh r1, [r5, 0x3C]
_08184106:
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08184112
	adds r0, 0xFF
_08184112:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	bl Sin
	negs r0, r0
	b _08184154
_08184126:
	cmp r0, 0x5F
	ble _0818414A
	movs r0, 0x60
	movs r1, 0x6
	bl Sin
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	subs r0, 0x60
	lsls r0, 17
	asrs r0, 16
	movs r1, 0x4
	bl Sin
	subs r4, r0
	strh r4, [r5, 0x26]
	b _08184156
_0818414A:
	movs r2, 0x3C
	ldrsh r0, [r5, r2]
	movs r1, 0x6
	bl Sin
_08184154:
	strh r0, [r5, 0x26]
_08184156:
	movs r3, 0x3C
	ldrsh r0, [r5, r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x38
	ldrsh r1, [r5, r2]
	bl Sin
	negs r0, r0
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r5, 0x36]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0818417E
	lsls r0, r2, 16
	negs r0, r0
	lsrs r2, r0, 16
_0818417E:
	strh r2, [r5, 0x24]
	ldrh r0, [r5, 0x34]
	ldrh r3, [r5, 0x3C]
	adds r0, r3
	strh r0, [r5, 0x3C]
_08184188:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81840C4

	thumb_func_start pokemonanimfunc_7C
pokemonanimfunc_7C: @ 8184190
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _081841B0
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x2
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x4
	strh r0, [r2, 0x34]
_081841B0:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7C

	thumb_func_start pokemonanimfunc_7D
pokemonanimfunc_7D: @ 81841BC
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _081841DC
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x2
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x6
	strh r0, [r2, 0x34]
_081841DC:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7D

	thumb_func_start pokemonanimfunc_7E
pokemonanimfunc_7E: @ 81841E8
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _08184208
	movs r1, 0x1
	strh r1, [r2, 0x32]
	movs r0, 0x3
	strh r0, [r2, 0x3A]
	strh r3, [r2, 0x3C]
	movs r0, 0x10
	strh r0, [r2, 0x38]
	strh r1, [r2, 0x36]
	movs r0, 0x8
	strh r0, [r2, 0x34]
_08184208:
	adds r0, r2, 0
	bl sub_81840C4
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7E

	thumb_func_start pokemonanimfunc_7F
pokemonanimfunc_7F: @ 8184214
	push {lr}
	adds r2, r0, 0
	movs r0, 0x32
	ldrsh r1, [r2, r0]
	cmp r1, 0
	bne _08184232
	movs r0, 0x1
	strh r0, [r2, 0x32]
	strh r0, [r2, 0x3A]
	strh r1, [r2, 0x3C]
	movs r1, 0x4
	strh r1, [r2, 0x38]
	movs r0, 0x6
	strh r0, [r2, 0x36]
	strh r1, [r2, 0x34]
_08184232:
	adds r0, r2, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7F

	thumb_func_start pokemonanimfunc_80
pokemonanimfunc_80: @ 818423C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0818425A
	movs r0, 0x1
	strh r0, [r1, 0x32]
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0x4
	strh r0, [r1, 0x38]
	movs r0, 0x6
	strh r0, [r1, 0x36]
	strh r0, [r1, 0x34]
_0818425A:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_80

	thumb_func_start pokemonanimfunc_81
pokemonanimfunc_81: @ 8184264
	push {lr}
	adds r1, r0, 0
	movs r0, 0x32
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _08184286
	movs r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0x2
	strh r0, [r1, 0x3A]
	strh r2, [r1, 0x3C]
	movs r0, 0x4
	strh r0, [r1, 0x38]
	movs r0, 0x6
	strh r0, [r1, 0x36]
	movs r0, 0x8
	strh r0, [r1, 0x34]
_08184286:
	adds r0, r1, 0
	bl sub_8183FA8
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_81

	thumb_func_start sub_8184290
sub_8184290: @ 8184290
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r0, r1, 8
	negs r0, r0
	strh r0, [r4, 0x3A]
	movs r0, 0x36
	ldrsh r2, [r4, r0]
	adds r0, r4, 0
	movs r3, 0
	bl sub_817F3F0
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x3A]
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_817F6D4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8184290

	thumb_func_start pokemonanimfunc_82
pokemonanimfunc_82: @ 81842DC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184300
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x3C
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184300:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _0818434C
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08184348
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08184358
	.pool
_08184348:
	strh r2, [r4, 0x32]
	b _08184352
_0818434C:
	adds r0, r4, 0
	bl sub_8184290
_08184352:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08184358:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_82

	thumb_func_start pokemonanimfunc_83
pokemonanimfunc_83: @ 8184360
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184384
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x5A
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184384:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _081843D0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _081843CC
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _081843DC
	.pool
_081843CC:
	strh r2, [r4, 0x32]
	b _081843D6
_081843D0:
	adds r0, r4, 0
	bl sub_8184290
_081843D6:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_081843DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_83

	thumb_func_start pokemonanimfunc_84
pokemonanimfunc_84: @ 81843E4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08184408
	adds r0, r4, 0
	bl sub_817F670
	movs r0, 0x1E
	strh r0, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x38]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x36]
	movs r0, 0x2
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x2E]
_08184408:
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184454
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	movs r2, 0
	strh r2, [r4, 0x24]
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08184450
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _08184460
	.pool
_08184450:
	strh r2, [r4, 0x32]
	b _0818445A
_08184454:
	adds r0, r4, 0
	bl sub_8184290
_0818445A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_08184460:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_84

	thumb_func_start sub_8184468
sub_8184468: @ 8184468
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0x32
	ldrsh r1, [r6, r0]
	movs r2, 0x3C
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0818449C
	movs r0, 0
	strh r0, [r6, 0x26]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl sub_817F6D4
	adds r0, r6, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r6, 0x1C]
	b _08184544
	.pool
_0818449C:
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	movs r2, 0x3A
	ldrsh r4, [r6, r2]
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r0, 16
	adds r1, r4, 0
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081844BC
	adds r0, 0xFF
_081844BC:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldrh r0, [r6, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081844F8
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x20
	bl Sin
	adds r0, r5
	strh r0, [r6, 0x38]
	adds r0, r4, 0
	movs r1, 0x20
	b _0818451E
_081844F8:
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	movs r2, 0x80
	lsls r2, 1
	adds r5, r2, 0
	adds r0, r5
	strh r0, [r6, 0x36]
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	adds r0, r5
	strh r0, [r6, 0x38]
	adds r0, r4, 0
	movs r1, 0x8
_0818451E:
	bl Sin
	lsls r0, 24
	lsrs r0, 24
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _08184530
	adds r0, 0x7
_08184530:
	lsrs r0, 3
	strh r0, [r6, 0x26]
	movs r0, 0x36
	ldrsh r1, [r6, r0]
	movs r0, 0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, 0
	movs r3, 0
	bl sub_817F6D4
_08184544:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8184468

	thumb_func_start pokemonanimfunc_85
pokemonanimfunc_85: @ 8184550
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08184570
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x28
	strh r0, [r4, 0x3A]
	movs r0, 0x50
	strh r0, [r4, 0x3C]
_08184570:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_85

	thumb_func_start pokemonanimfunc_86
pokemonanimfunc_86: @ 818457C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0818459A
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x28
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x3C]
_0818459A:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_86

	thumb_func_start pokemonanimfunc_87
pokemonanimfunc_87: @ 81845A8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081845C6
	adds r0, r4, 0
	bl sub_817F670
	ldrh r0, [r4, 0x26]
	adds r0, 0x2
	strh r0, [r4, 0x26]
	movs r0, 0x50
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x3C]
_081845C6:
	adds r0, r4, 0
	bl sub_8184468
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_87

	thumb_func_start sub_81845D4
sub_81845D4: @ 81845D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x32]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bgt _081845FE
	ldrh r0, [r4, 0x3A]
	negs r0, r0
	strh r0, [r4, 0x24]
	movs r0, 0x2
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8184610
	str r0, [r4, 0x1C]
_081845FE:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81845D4

	thumb_func_start sub_8184610
sub_8184610: @ 8184610
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	ldrh r2, [r4, 0x24]
	adds r1, r0, r2
	strh r1, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r1, 16
	cmp r1, 0
	blt _0818462E
	ldr r0, =sub_8184640
	str r0, [r4, 0x1C]
_0818462E:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184610

	thumb_func_start sub_8184640
sub_8184640: @ 8184640
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x3C]
	ldrh r2, [r4, 0x24]
	adds r1, r0, r2
	strh r1, [r4, 0x24]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184668
	strh r2, [r4, 0x24]
	ldr r0, =sub_8184678
	str r0, [r4, 0x1C]
_08184668:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184640

	thumb_func_start sub_8184678
sub_8184678: @ 8184678
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r2, [r4, 0x34]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08184698
	ldr r0, =sub_81846B8
	str r0, [r4, 0x1C]
	b _081846AC
	.pool
_08184698:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	negs r0, r0
	strh r0, [r4, 0x36]
	adds r0, r2, 0x1
	strh r0, [r4, 0x34]
_081846AC:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8184678

	thumb_func_start sub_81846B8
sub_81846B8: @ 81846B8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F70C
	ldrh r0, [r4, 0x24]
	subs r0, 0x2
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bgt _081846DA
	movs r0, 0
	strh r0, [r4, 0x24]
	adds r0, r4, 0
	bl sub_817F77C
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
_081846DA:
	adds r0, r4, 0
	bl sub_817F70C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81846B8

	thumb_func_start pokemonanimfunc_88
pokemonanimfunc_88: @ 81846EC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r2, 0
	movs r1, 0x4
	strh r1, [r4, 0x3C]
	movs r0, 0xC
	strh r0, [r4, 0x3A]
	movs r0, 0x10
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_88

	thumb_func_start pokemonanimfunc_89
pokemonanimfunc_89: @ 8184718
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r2, 0
	movs r1, 0x2
	strh r1, [r4, 0x3C]
	movs r0, 0x8
	strh r0, [r4, 0x3A]
	movs r0, 0xC
	strh r0, [r4, 0x38]
	strh r1, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_89

	thumb_func_start pokemonanimfunc_8A
pokemonanimfunc_8A: @ 8184744
	push {r4,lr}
	adds r4, r0, 0
	bl sub_817F670
	movs r1, 0
	strh r1, [r4, 0x3C]
	movs r0, 0x6
	strh r0, [r4, 0x3A]
	strh r0, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x32]
	ldr r0, =sub_81845D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemonanimfunc_8A

	thumb_func_start sub_8184770
sub_8184770: @ 8184770
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	strh r0, [r1, 0x24]
	ldrh r2, [r1, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	ble _0818478E
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x30]
	movs r0, 0
	b _08184790
_0818478E:
	adds r0, r2, 0x1
_08184790:
	strh r0, [r1, 0x2E]
	pop {r0}
	bx r0
	thumb_func_end sub_8184770

	thumb_func_start sub_8184798
sub_8184798: @ 8184798
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_0860AE7C
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r4, 0
	bl sub_8184770
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _081847D0
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0818482E
	.pool
_081847D0:
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bne _08184800
	ldrb r0, [r1]
	cmp r0, 0
	beq _081847F0
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0x10
	bl BlendPalette
	b _081847FC
	.pool
_081847F0:
	ldrh r0, [r4, 0x3C]
	ldr r3, =0x000003ff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
_081847FC:
	movs r0, 0
	strh r0, [r4, 0x36]
_08184800:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08184828
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _0818482E
	.pool
_08184828:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_0818482E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8184798

	thumb_func_start pokemonanimfunc_8B
pokemonanimfunc_8B: @ 8184834
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08184860
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	strh r3, [r2, 0x34]
_08184860:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8B

	thumb_func_start pokemonanimfunc_8C
pokemonanimfunc_8C: @ 818486C
	push {r4,r5,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0x1
	bne _08184898
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r5, 0x80
	lsls r5, 1
	adds r1, r5, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	strh r4, [r2, 0x34]
_08184898:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8C

	thumb_func_start pokemonanimfunc_8D
pokemonanimfunc_8D: @ 81848A4
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _081848D2
	ldrb r0, [r2, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4, 0
	adds r0, r1
	strh r0, [r2, 0x3C]
	strh r3, [r2, 0x3A]
	strh r3, [r2, 0x38]
	strh r3, [r2, 0x36]
	movs r0, 0x2
	strh r0, [r2, 0x34]
_081848D2:
	adds r0, r2, 0
	bl sub_8184798
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8D

	thumb_func_start sub_81848E0
sub_81848E0: @ 81848E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _08184904
	ldrh r0, [r4, 0x3C]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0x1F
	bl BlendPalette
	ldr r0, =sub_8184D88
	str r0, [r4, 0x1C]
	b _0818492A
	.pool
_08184904:
	movs r5, 0x32
	ldrsh r0, [r4, r5]
	movs r1, 0xC
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_0860AE88
	movs r5, 0x30
	ldrsh r1, [r4, r5]
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
_0818492A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81848E0

	thumb_func_start sub_8184934
sub_8184934: @ 8184934
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _081849CC
	adds r0, r4, 0
	bl sub_817F70C
	movs r3, 0x38
	ldrsh r1, [r4, r3]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _08184970
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0818496C
	strh r2, [r4, 0x38]
_0818496C:
	strh r2, [r4, 0x24]
	b _081849C6
_08184970:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	lsls r1, 16
	asrs r1, 15
	movs r0, 0x1
	subs r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 7
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0
	bge _081849A4
	adds r0, 0xFF
_081849A4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl Sin
	lsls r1, r5, 24
	asrs r1, 24
	adds r2, r1, 0
	muls r2, r0
	adds r0, r2, 0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_081849C6:
	adds r0, r4, 0
	bl sub_817F70C
_081849CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8184934

	thumb_func_start pokemonanimfunc_8E
pokemonanimfunc_8E: @ 81849D4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _081849FE
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_081849FE:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184A0E
	adds r0, r4, 0
	bl sub_81848E0
_08184A0E:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184A30
	adds r0, r4, 0
	bl sub_8184934
_08184A30:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8E

	thumb_func_start pokemonanimfunc_8F
pokemonanimfunc_8F: @ 8184A3C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184A66
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_08184A66:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184A76
	adds r0, r4, 0
	bl sub_81848E0
_08184A76:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184A98
	adds r0, r4, 0
	bl sub_8184934
_08184A98:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8F

	thumb_func_start pokemonanimfunc_90
pokemonanimfunc_90: @ 8184AA4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184ACE
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r2, [r4, 0x30]
_08184ACE:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184ADE
	adds r0, r4, 0
	bl sub_81848E0
_08184ADE:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184B00
	adds r0, r4, 0
	bl sub_8184934
_08184B00:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_90

	thumb_func_start pokemonanimfunc_91
pokemonanimfunc_91: @ 8184B0C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184B38
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x30]
_08184B38:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184B48
	adds r0, r4, 0
	bl sub_81848E0
_08184B48:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184B6A
	adds r0, r4, 0
	bl sub_8184934
_08184B6A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_91

	thumb_func_start pokemonanimfunc_92
pokemonanimfunc_92: @ 8184B78
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184BA2
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184BA2:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184BB2
	adds r0, r4, 0
	bl sub_81848E0
_08184BB2:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184BD4
	adds r0, r4, 0
	bl sub_8184934
_08184BD4:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_92

	thumb_func_start pokemonanimfunc_93
pokemonanimfunc_93: @ 8184BE0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184C0A
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184C0A:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184C1A
	adds r0, r4, 0
	bl sub_81848E0
_08184C1A:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184C3C
	adds r0, r4, 0
	bl sub_8184934
_08184C3C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_93

	thumb_func_start pokemonanimfunc_94
pokemonanimfunc_94: @ 8184C48
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184C72
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	strh r0, [r4, 0x30]
_08184C72:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184C82
	adds r0, r4, 0
	bl sub_81848E0
_08184C82:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184CA4
	adds r0, r4, 0
	bl sub_8184934
_08184CA4:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_94

	thumb_func_start pokemonanimfunc_95
pokemonanimfunc_95: @ 8184CB0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184CDC
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08184CDC:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184CEC
	adds r0, r4, 0
	bl sub_81848E0
_08184CEC:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184D0E
	adds r0, r4, 0
	bl sub_8184934
_08184D0E:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_95

	thumb_func_start pokemonanimfunc_96
pokemonanimfunc_96: @ 8184D1C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08184D48
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	adds r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x50
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x38]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x34]
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08184D48:
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08184D58
	adds r0, r4, 0
	bl sub_81848E0
_08184D58:
	movs r0, 0x32
	ldrsh r2, [r4, r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	muls r1, r0
	movs r0, 0x80
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r2, r0
	blt _08184D7A
	adds r0, r4, 0
	bl sub_8184934
_08184D7A:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_96

	thumb_func_start sub_8184D88
sub_8184D88: @ 8184D88
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08184D9C
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_08184D9C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8184D88

	.align 2, 0 @ Don't pad with nop.
