	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start oei_exclamation_mark
oei_exclamation_mark: @ 80B4620
	push {lr}
	ldr r0, =gUnknown_085507B4
	movs r1, 0
	movs r2, 0
	movs r3, 0x53
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080B4648
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_80B46D8
_080B4648:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_exclamation_mark

	thumb_func_start sub_80B4658
sub_80B4658: @ 80B4658
	push {lr}
	ldr r0, =gUnknown_085507B4
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080B4680
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x21
	movs r2, 0x1
	bl sub_80B46D8
_080B4680:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4658

	thumb_func_start sub_80B4690
sub_80B4690: @ 80B4690
	push {r4,lr}
	ldr r0, =gUnknown_085507CC
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080B46C6
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2E
	movs r2, 0
	bl sub_80B46D8
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x5]
_080B46C6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4690

	thumb_func_start sub_80B46D8
@ void sub_80B46D8(struct obj *object, s16 a2, u8 a3)
sub_80B46D8: @ 80B46D8
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	ldrb r4, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	ands r3, r4
	movs r4, 0x4
	orrs r3, r4
	strb r3, [r0, 0x5]
	movs r3, 0x3E
	adds r3, r0
	mov r12, r3
	ldrb r3, [r3]
	movs r4, 0x2
	orrs r3, r4
	mov r4, r12
	strb r3, [r4]
	ldr r4, =gUnknown_02038C08
	ldr r3, [r4]
	strh r3, [r0, 0x2E]
	ldr r3, [r4, 0x4]
	strh r3, [r0, 0x30]
	ldr r3, [r4, 0x8]
	strh r3, [r0, 0x32]
	ldr r3, =0x0000fffb
	strh r3, [r0, 0x34]
	strh r1, [r0, 0x3C]
	adds r1, r2, 0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B46D8

	thumb_func_start objc_exclamation_mark_probably
objc_exclamation_mark_probably: @ 80B4724
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x32]
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _080B4756
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080B4764
_080B4756:
	ldrh r1, [r4, 0x3C]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldEffectStop
	b _080B47B2
_080B4764:
	ldr r2, =gMapObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrh r3, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r2, r3, r0
	strh r2, [r4, 0x36]
	ldrh r0, [r1, 0x20]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x22]
	subs r0, 0x10
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x24]
	strh r0, [r4, 0x24]
	ldrh r0, [r1, 0x26]
	adds r0, r2
	strh r0, [r4, 0x26]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _080B47B0
	adds r0, r3, 0x1
	strh r0, [r4, 0x34]
	b _080B47B2
	.pool
_080B47B0:
	strh r2, [r4, 0x34]
_080B47B2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end objc_exclamation_mark_probably

	thumb_func_start sub_80B47BC
sub_80B47BC: @ 80B47BC
	push {lr}
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B47D4
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0, 0xC]
	b _080B47D8
	.pool
_080B47D4:
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0]
_080B47D8:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B47BC

	thumb_func_start sub_80B47E0
sub_80B47E0: @ 80B47E0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080B47EE
	movs r0, 0
	b _080B4800
_080B47EE:
	cmp r0, 0
	beq _080B47FC
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0, 0xC]
	b _080B4800
	.pool
_080B47FC:
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0]
_080B4800:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B47E0

	thumb_func_start sub_80B4808
sub_80B4808: @ 80B4808
	push {lr}
	ldr r0, =gUnknown_030060AC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080B4870
	ldr r2, =gUnknown_03006090
	ldr r0, =gUnknown_03006080
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	ldr r3, =gUnknown_03006084
	strb r0, [r3]
	movs r0, 0xFE
	strb r0, [r3, 0x1]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0xFF
	bl exec_movement
	b _080B489E
	.pool
_080B4870:
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	ldr r3, =gUnknown_03006084
	strb r0, [r3]
	movs r0, 0xFE
	strb r0, [r3, 0x1]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0xFF
	bl exec_movement
_080B489E:
	movs r0, 0xFF
	bl sub_809BE48
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B4808

	.align 2, 0 @ Don't pad with nop.
