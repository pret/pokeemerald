	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F9568
sub_80F9568: @ 80F9568
	push {lr}
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080F9580
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _080F9584
_080F9580:
	movs r0, 0
	b _080F9586
_080F9584:
	movs r0, 0x1
_080F9586:
	pop {r1}
	bx r1
	thumb_func_end sub_80F9568

	thumb_func_start sub_80F958C
sub_80F958C: @ 80F958C
	push {r4,r5,lr}
	ldr r4, =gPlayerParty
	movs r5, 0
_080F9592:
	adds r0, r4, 0
	bl sub_80F9568
	cmp r0, 0
	beq _080F95B0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080F95B0
	movs r0, 0
	b _080F95BA
	.pool
_080F95B0:
	adds r5, 0x1
	adds r4, 0x64
	cmp r5, 0x5
	ble _080F9592
	movs r0, 0x1
_080F95BA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80F958C

	thumb_func_start sub_80F95C0
sub_80F95C0: @ 80F95C0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	adds r4, r0, 0
	muls r4, r1
	ldr r0, =gPlayerParty
	adds r4, r0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x7
	bl AdjustFriendship
	adds r0, r4, 0
	movs r1, 0x37
	mov r2, sp
	bl SetMonData
	ldr r5, =gStringVar1
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetMonData
	adds r0, r5, 0
	bl StringGetEnd10
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F95C0

	thumb_func_start sub_80F960C
sub_80F960C: @ 80F960C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80F9568
	cmp r0, 0
	beq _080F964C
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080F964C
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	bl pokemon_ailments_get_primary
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080F964C
	movs r0, 0x1
	b _080F964E
	.pool
_080F964C:
	movs r0, 0
_080F964E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80F960C

	thumb_func_start sub_80F9654
sub_80F9654: @ 80F9654
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r0, 0
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _080F96AE
	cmp r5, 0x1
	bgt _080F967C
	cmp r5, 0
	beq _080F9682
	b _080F9722
	.pool
_080F967C:
	cmp r5, 0x2
	beq _080F96C0
	b _080F9722
_080F9682:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	bgt _080F96A8
_080F968C:
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_80F960C
	cmp r0, 0
	bne _080F96FC
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	adds r1, r0, 0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080F968C
_080F96A8:
	movs r0, 0x2
	strh r0, [r4]
	b _080F9722
_080F96AE:
	bl sub_809833C
	lsls r0, 24
	cmp r0, 0
	beq _080F9722
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	b _080F9722
_080F96C0:
	bl sub_80F958C
	adds r1, r0, 0
	cmp r1, 0
	beq _080F9714
	bl InBattlePyramid
	adds r4, r0, 0
	bl InBattlePike
	orrs r4, r0
	lsls r4, 24
	cmp r4, 0
	bne _080F96E6
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _080F96F0
_080F96E6:
	ldr r0, =gScriptResult
	strh r5, [r0]
	b _080F9718
	.pool
_080F96F0:
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	b _080F9718
	.pool
_080F96FC:
	ldrb r0, [r4, 0x2]
	bl sub_80F95C0
	ldr r0, =gUnknown_085ECF5D
	bl box_related_two__2
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080F9722
	.pool
_080F9714:
	ldr r0, =gScriptResult
	strh r1, [r0]
_080F9718:
	bl script_env_2_enable_and_set_ctx_running
	adds r0, r6, 0
	bl DestroyTask
_080F9722:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9654

	thumb_func_start sub_80F972C
sub_80F972C: @ 80F972C
	push {lr}
	ldr r0, =sub_80F9654
	movs r1, 0x50
	bl CreateTask
	bl script_env_2_set_ctx_paused
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F972C

	thumb_func_start overworld_poison
overworld_poison: @ 80F9744
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r4, =gPlayerParty
	movs r7, 0
	movs r6, 0
	movs r5, 0x5
_080F9750:
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _080F9794
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	bl pokemon_ailments_get_primary
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080F9794
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	str r0, [sp]
	cmp r0, 0
	beq _080F9786
	subs r0, 0x1
	str r0, [sp]
	cmp r0, 0
	bne _080F9788
_080F9786:
	adds r6, 0x1
_080F9788:
	adds r0, r4, 0
	movs r1, 0x39
	mov r2, sp
	bl SetMonData
	adds r7, 0x1
_080F9794:
	adds r4, 0x64
	subs r5, 0x1
	cmp r5, 0
	bge _080F9750
	cmp r6, 0
	bne _080F97A4
	cmp r7, 0
	beq _080F97A8
_080F97A4:
	bl overworld_posion_effect
_080F97A8:
	cmp r6, 0
	beq _080F97B4
	movs r0, 0x2
	b _080F97BE
	.pool
_080F97B4:
	cmp r7, 0
	bne _080F97BC
	movs r0, 0
	b _080F97BE
_080F97BC:
	movs r0, 0x1
_080F97BE:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end overworld_poison

	.align 2, 0 @ Don't pad with nop.
