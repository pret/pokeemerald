	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80FB59C
sub_80FB59C: @ 80FB59C
	push {r4-r6,lr}
	sub sp, 0xC
	mov r4, sp
	adds r4, 0x5
	mov r5, sp
	adds r5, 0x6
	add r6, sp, 0x8
	add r0, sp, 0x4
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8137FFC
	lsls r0, 24
	cmp r0, 0
	bne _080FB5DE
	add r0, sp, 0x4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r4, r1]
	movs r2, 0x1
	negs r2, r2
	movs r3, 0
	ldrsb r3, [r5, r3]
	movs r4, 0
	ldrsb r4, [r6, r4]
	str r4, [sp]
	bl warp1_set
	movs r0, 0x1
	b _080FB5E0
_080FB5DE:
	movs r0, 0
_080FB5E0:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80FB59C

	thumb_func_start sub_80FB5E8
sub_80FB5E8: @ 80FB5E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =0x000040b4
	bl GetVarPointer
	adds r7, r0, 0
	ldr r0, =gUnknown_03005D8C
	ldr r3, [r0]
	adds r6, r3, 0x4
	movs r0, 0
	ldrsh r2, [r4, r0]
	cmp r2, 0x1
	beq _080FB648
	cmp r2, 0x1
	bgt _080FB624
	cmp r2, 0
	beq _080FB62E
	b _080FB6E2
	.pool
_080FB624:
	cmp r2, 0x2
	beq _080FB68A
	cmp r2, 0x3
	beq _080FB6C4
	b _080FB6E2
_080FB62E:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080FB6E2
	strh r2, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r4]
	b _080FB6E2
	.pool
_080FB648:
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080FB656
	strh r2, [r4, 0x2]
_080FB656:
	ldrb r1, [r6, 0x1]
	ldrb r2, [r3, 0x4]
	movs r0, 0xFF
	bl sub_80D3340
	lsls r0, 24
	cmp r0, 0
	beq _080FB6E2
	movs r0, 0x1
	bl sub_8137FC0
	cmp r0, 0x1
	bne _080FB686
	ldrh r0, [r7]
	cmp r0, 0x2
	bne _080FB680
	movs r0, 0x9
	b _080FB682
	.pool
_080FB680:
	movs r0, 0xA
_080FB682:
	strh r0, [r7]
	b _080FB692
_080FB686:
	movs r0, 0x2
	strh r0, [r4]
_080FB68A:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FB698
_080FB692:
	movs r0, 0x3
	strh r0, [r4]
	b _080FB6E2
_080FB698:
	ldrh r0, [r7]
	cmp r0, 0x2
	bne _080FB6AC
	ldrb r1, [r6, 0x1]
	ldrb r2, [r6]
	ldr r3, =gUnknown_0858E8AB
	b _080FB6B2
	.pool
_080FB6AC:
	ldrb r1, [r6, 0x1]
	ldrb r2, [r6]
	ldr r3, =gUnknown_0858E8AD
_080FB6B2:
	movs r0, 0xFF
	bl exec_movement
	movs r0, 0x1
	strh r0, [r4]
	b _080FB6E2
	.pool
_080FB6C4:
	ldr r0, =0x00004001
	bl FlagReset
	movs r0, 0x80
	lsls r0, 7
	bl FlagReset
	movs r0, 0
	bl copy_saved_warp2_bank_and_enter_x_to_warp1
	bl sp13E_warp_to_last_warp
	adds r0, r5, 0
	bl DestroyTask
_080FB6E2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB5E8

	thumb_func_start sub_80FB6EC
sub_80FB6EC: @ 80FB6EC
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =DummyObjectCallback
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8C
	movs r2, 0x70
	movs r3, 0x50
	bl AddPseudoFieldObject
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02020630
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r2
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =0x000040b4
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _080FB74C
	movs r0, 0x4
	bl FieldObjectDirectionToImageAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	b _080FB75E
	.pool
_080FB74C:
	movs r0, 0x3
	bl FieldObjectDirectionToImageAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
_080FB75E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FB6EC

	thumb_func_start sub_80FB768
sub_80FB768: @ 80FB768
	push {lr}
	bl sub_80FB6EC
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl pal_fill_black
	ldr r0, =sub_80FB5E8
	movs r1, 0x50
	bl CreateTask
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB768

	thumb_func_start sub_80FB7A4
sub_80FB7A4: @ 80FB7A4
	push {lr}
	ldr r0, =0x0000088d
	bl FlagSet
	ldr r0, =0x00004001
	bl FlagSet
	movs r0, 0x80
	lsls r0, 7
	bl FlagSet
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	movs r2, 0x5
	ldrsb r2, [r0, r2]
	movs r3, 0x1
	negs r3, r3
	movs r0, 0
	bl saved_warp2_set
	bl sub_80FB59C
	bl sub_80AF8B8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB7A4

	.align 2, 0 @ Don't pad with nop.
