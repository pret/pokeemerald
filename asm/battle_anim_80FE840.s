	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80FE840
sub_80FE840: @ 80FE840
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FE87C
	ldrh r0, [r5, 0x8]
	negs r0, r0
	b _080FE87E
	.pool
_080FE87C:
	ldrh r0, [r5, 0x8]
_080FE87E:
	strh r0, [r4, 0x34]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0xA]
	strh r0, [r4, 0x36]
	ldr r0, =sub_80FE898
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE840

	thumb_func_start sub_80FE898
sub_80FE898: @ 80FE898
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080FE8D4
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x32]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r1, r0
	strh r1, [r4, 0x32]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _080FE8DA
_080FE8D4:
	adds r0, r4, 0
	bl move_anim_8072740
_080FE8DA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FE898

	thumb_func_start sub_80FE8E0
sub_80FE8E0: @ 80FE8E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE8E0

	thumb_func_start sub_80FE930
sub_80FE930: @ 80FE930
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x6]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE930

	thumb_func_start sub_80FE988
sub_80FE988: @ 80FE988
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldrh r0, [r6, 0x6]
	strh r0, [r4, 0x38]
	ldr r1, =sub_80FE9E4
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE988

	thumb_func_start sub_80FE9E4
sub_80FE9E4: @ 80FE9E4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _080FE9FA
	adds r0, r4, 0
	bl DestroySprite
	b _080FEA4E
_080FE9FA:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _080FEA14
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r0, 0x1
	b _080FEA1E
	.pool
_080FEA14:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r0, 0x6
_080FEA1E:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xE
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0xF
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
_080FEA4E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FE9E4

	thumb_func_start sub_80FEA58
sub_80FEA58: @ 80FEA58
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x8]
	subs r0, 0x1
	movs r2, 0
	strh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080FEAB2
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	movs r0, 0x6
	strh r0, [r5, 0x8]
	ldr r1, =gBattleAnimArgs
	movs r0, 0xF
	strh r0, [r1]
	strh r2, [r1, 0x2]
	movs r0, 0x50
	strh r0, [r1, 0x4]
	strh r2, [r1, 0x6]
	ldr r4, =gUnknown_08592210
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r3, r0, 0
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl CreateSpriteAndAnimate
_080FEAB2:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0xF
	bne _080FEAC0
	adds r0, r6, 0
	bl move_anim_task_del
_080FEAC0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEA58

	thumb_func_start sub_80FEAD8
sub_80FEAD8: @ 80FEAD8
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x6]
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldrh r0, [r6, 0x4]
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_80FEB28
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEAD8

	thumb_func_start sub_80FEB28
sub_80FEB28: @ 80FEB28
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _080FEB3C
	adds r0, r4, 0
	bl move_anim_8072740
_080FEB3C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FEB28

	thumb_func_start sub_80FEB44
sub_80FEB44: @ 80FEB44
	push {r4,r5,lr}
	adds r5, r0, 0
	bl Random2
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x7
	ands r1, r0
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FEB90
	ldrh r0, [r5, 0x20]
	subs r0, 0x14
	b _080FEB94
	.pool
_080FEB90:
	ldrh r0, [r5, 0x20]
	adds r0, 0x14
_080FEB94:
	strh r0, [r5, 0x20]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1F
	ands r0, r1
	adds r0, 0x40
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A7160
	bl Random2
	movs r1, 0xFF
	ands r1, r0
	strh r1, [r5, 0x38]
	adds r0, r5, 0
	adds r0, 0x43
	ldrb r0, [r0]
	strh r0, [r5, 0x3A]
	ldr r1, =sub_80FEBFC
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEB44

	thumb_func_start sub_80FEBFC
sub_80FEBFC: @ 80FEBFC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A70E8
	lsls r0, 24
	cmp r0, 0
	beq _080FEC12
	adds r0, r4, 0
	bl move_anim_8072740
	b _080FEC42
_080FEC12:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xC
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x7E
	bgt _080FEC2E
	ldrh r0, [r4, 0x3A]
	b _080FEC32
_080FEC2E:
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
_080FEC32:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	adds r0, 0x18
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
_080FEC42:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FEBFC

	thumb_func_start sub_80FEC48
sub_80FEC48: @ 80FEC48
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FEC68
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_080FEC68:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	adds r0, r1
	strh r0, [r6, 0x36]
	ldrh r0, [r4, 0xA]
	strh r0, [r6, 0x38]
	adds r0, r6, 0
	bl sub_80A68D4
	ldr r0, =sub_80FECB8
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEC48

	thumb_func_start sub_80FECB8
sub_80FECB8: @ 80FECB8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _080FECE2
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_80FECF0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
_080FECE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FECB8

	thumb_func_start sub_80FECF0
sub_80FECF0: @ 80FECF0
	push {r4,lr}
	adds r4, r0, 0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FECF0

	thumb_func_start sub_80FED28
sub_80FED28: @ 80FED28
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x8]
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080FED52
	ldrb r0, [r4, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4, 0x1]
_080FED52:
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x30]
	ldr r1, =sub_80FED74
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FED28

	thumb_func_start sub_80FED74
sub_80FED74: @ 80FED74
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	negs r1, r1
	bl Cos
	ldrh r1, [r4, 0x32]
	adds r1, 0x18
	strh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _080FEDC8
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	b _080FEDEC
	.pool
_080FEDC8:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	adds r0, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080FEDDC
	movs r2, 0x3
_080FEDDC:
	movs r0, 0x3
	ands r2, r0
	lsls r2, 2
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
_080FEDEC:
	strb r0, [r4, 0x5]
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080FEE10
	adds r0, r4, 0
	bl move_anim_8072740
_080FEE10:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FED74

	thumb_func_start sub_80FEE1C
sub_80FEE1C: @ 80FEE1C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080FEE36
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _080FEE3E
_080FEE36:
	adds r0, r4, 0
	bl move_anim_task_del
	b _080FEE70
_080FEE3E:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FEE60
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x3
	bl lcd_bg_operations
	b _080FEE6A
	.pool
_080FEE60:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
_080FEE6A:
	adds r0, r4, 0
	bl move_anim_task_del
_080FEE70:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FEE1C

	thumb_func_start sub_80FEE78
sub_80FEE78: @ 80FEE78
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x4]
	adds r0, r5
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	movs r0, 0x40
	strh r0, [r4, 0x38]
	ldr r1, =sub_80FEECC
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEE78

	thumb_func_start sub_80FEECC
sub_80FEECC: @ 80FEECC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _080FEF38
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	negs r1, r1
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _080FEF18
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	b _080FEF22
	.pool
_080FEF18:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r0, 0x1
_080FEF22:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	adds r0, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _080FEF3E
	.pool
_080FEF38:
	adds r0, r4, 0
	bl move_anim_8072740
_080FEF3E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FEECC

	thumb_func_start sub_80FEF44
sub_80FEF44: @ 80FEF44
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x4]
	adds r0, r5
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	movs r0, 0x40
	strh r0, [r4, 0x38]
	ldr r1, =sub_80FEF98
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEF44

	thumb_func_start sub_80FEF98
sub_80FEF98: @ 80FEF98
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _080FEFF0
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldrh r1, [r4, 0x38]
	adds r0, r1, 0
	subs r0, 0x3B
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bls _080FEFD0
	adds r0, r1, 0
	subs r0, 0xBB
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _080FEFE4
_080FEFD0:
	ldrb r2, [r4, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	eors r1, r0
	lsls r1, 1
	subs r0, 0x47
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
_080FEFE4:
	ldrh r0, [r4, 0x38]
	adds r0, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _080FEFF6
_080FEFF0:
	adds r0, r4, 0
	bl move_anim_8072740
_080FEFF6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FEF98

	thumb_func_start sub_80FEFFC
sub_80FEFFC: @ 80FEFFC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldr r0, =sub_80FF044
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FEFFC

	thumb_func_start sub_80FF044
sub_80FF044: @ 80FF044
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x32]
	movs r2, 0x32
	ldrsh r3, [r1, r2]
	cmp r3, 0
	bne _080FF078
	ldrh r0, [r1, 0x30]
	movs r2, 0x1
	ands r2, r0
	cmp r2, 0
	beq _080FF066
	movs r0, 0x80
	strh r0, [r1, 0x2E]
	strh r3, [r1, 0x30]
	strh r3, [r1, 0x32]
	b _080FF06C
_080FF066:
	strh r2, [r1, 0x2E]
	strh r2, [r1, 0x30]
	strh r2, [r1, 0x32]
_080FF06C:
	ldr r0, =sub_80FF090
	str r0, [r1, 0x1C]
	b _080FF08C
	.pool
_080FF078:
	subs r0, 0x1
	strh r0, [r1, 0x32]
	ldrh r0, [r1, 0x2E]
	ldrh r2, [r1, 0x20]
	adds r0, r2
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x30]
	ldrh r2, [r1, 0x22]
	adds r0, r2
	strh r0, [r1, 0x22]
_080FF08C:
	pop {r0}
	bx r0
	thumb_func_end sub_80FF044

	thumb_func_start sub_80FF090
sub_80FF090: @ 80FF090
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FF0B4
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x19
	bl Sin
	negs r0, r0
	b _080FF0BE
	.pool
_080FF0B4:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x19
	bl Sin
_080FF0BE:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080FF0DE
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
_080FF0DE:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x50
	ble _080FF0EC
	adds r0, r4, 0
	bl move_anim_8072740
_080FF0EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FF090

	thumb_func_start sub_80FF0F4
sub_80FF0F4: @ 80FF0F4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FF114
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_080FF114:
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080FF154
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x6]
	adds r0, r6
	b _080FF174
	.pool
_080FF154:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl sub_80A8924
	ldrh r0, [r6, 0x4]
	ldrh r1, [r5, 0x32]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r6, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
_080FF174:
	strh r0, [r5, 0x36]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0xA]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080FF1AC
	movs r0, 0x1
	b _080FF1AE
	.pool
_080FF1AC:
	movs r0, 0
_080FF1AE:
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80FF1C0
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF0F4

	thumb_func_start sub_80FF1C0
sub_80FF1C0: @ 80FF1C0
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	ldrh r5, [r6, 0x2E]
	ldrh r4, [r6, 0x3C]
	movs r0, 0x1
	strh r0, [r6, 0x2E]
	adds r0, r6, 0
	bl sub_80A6900
	ldrh r0, [r6, 0x3C]
	strh r5, [r6, 0x2E]
	lsls r4, 16
	asrs r4, 16
	cmp r4, 0xC8
	ble _080FF1F2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x37
	bgt _080FF1F2
	ldrh r0, [r6, 0x6]
	cmp r0, 0
	bne _080FF1F8
	adds r0, 0x1
	strh r0, [r6, 0x6]
_080FF1F2:
	ldrh r0, [r6, 0x6]
	cmp r0, 0
	beq _080FF22A
_080FF1F8:
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _080FF22A
	adds r3, r6, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r6, 0x6]
	adds r0, 0x1
	strh r0, [r6, 0x6]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bne _080FF22A
	movs r7, 0x1
_080FF22A:
	movs r2, 0x20
	ldrsh r0, [r6, r2]
	movs r2, 0x24
	ldrsh r1, [r6, r2]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _080FF254
	movs r0, 0x22
	ldrsh r1, [r6, r0]
	movs r2, 0x26
	ldrsh r0, [r6, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _080FF254
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _080FF256
_080FF254:
	movs r7, 0x1
_080FF256:
	cmp r7, 0
	beq _080FF260
	adds r0, r6, 0
	bl move_anim_8072740
_080FF260:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80FF1C0

	thumb_func_start sub_80FF268
sub_80FF268: @ 80FF268
	push {r4,lr}
	adds r4, r0, 0
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FF28A
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0x1
	bl sub_80A8924
_080FF28A:
	ldrh r0, [r4, 0x22]
	adds r0, 0x20
	strh r0, [r4, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x34]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x36]
	ldr r0, =sub_80FF2BC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF268

	thumb_func_start sub_80FF2BC
sub_80FF2BC: @ 80FF2BC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0xFF
	bne _080FF2D2
	ldrh r0, [r4, 0x22]
	subs r0, 0x2
	strh r0, [r4, 0x22]
	b _080FF2E0
_080FF2D2:
	cmp r0, 0
	ble _080FF2E0
	ldrh r0, [r4, 0x22]
	subs r0, 0x2
	strh r0, [r4, 0x22]
	subs r0, r1, 0x2
	strh r0, [r4, 0x30]
_080FF2E0:
	ldrh r3, [r4, 0x32]
	ldrh r5, [r4, 0x38]
	adds r2, r3, r5
	strh r2, [r4, 0x38]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r5, 0x36
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge _080FF2F8
	adds r0, r2, r3
	strh r0, [r4, 0x38]
_080FF2F8:
	ldrh r1, [r4, 0x38]
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r5, 0x38
	ldrsh r0, [r4, r5]
	movs r1, 0x5
	bl Sin
	strh r0, [r4, 0x26]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	bgt _080FF338
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	b _080FF346
	.pool
_080FF338:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
_080FF346:
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _080FF36A
	adds r0, r4, 0
	bl move_anim_8072740
_080FF36A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF2BC

	thumb_func_start sub_80FF374
sub_80FF374: @ 80FF374
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0
	bl sub_80A6980
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl StartSpriteAffineAnim
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x3A]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x3C]
	ldr r0, =sub_80FF3B0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF374

	thumb_func_start sub_80FF3B0
sub_80FF3B0: @ 80FF3B0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080FF3DA
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x1
	bl GetAnimBankSpriteId
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FF3EC
	str r0, [r4, 0x1C]
_080FF3DA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF3B0

	thumb_func_start sub_80FF3EC
sub_80FF3EC: @ 80FF3EC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl GetAnimBankSpriteId
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080FF404
	ldrh r0, [r4, 0x2E]
	adds r0, 0xB
	b _080FF408
_080FF404:
	ldrh r0, [r4, 0x2E]
	subs r0, 0xB
_080FF408:
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _080FF424
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x32]
_080FF424:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080FF452
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r0, 16
	cmp r0, 0
	ble _080FF44C
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	b _080FF452
_080FF44C:
	adds r0, r4, 0
	bl move_anim_8072740
_080FF452:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FF3EC

	thumb_func_start sub_80FF458
sub_80FF458: @ 80FF458
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gSprites
	mov r10, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r2, r10
	adds r7, r0, r2
	adds r0, r7, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080FF498
	adds r0, r4, 0
	bl move_anim_task_del
	b _080FF51C
	.pool
_080FF498:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_80A7270
	ldr r0, =gTasks
	lsls r6, r4, 2
	adds r6, r4
	lsls r6, 3
	adds r6, r0
	ldrb r0, [r7, 0x5]
	lsls r0, 28
	lsrs r0, 30
	strh r0, [r6, 0x24]
	ldr r0, =gAnimationBankTarget
	mov r9, r0
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	mov r8, r1
	mov r1, r8
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
	movs r0, 0x3
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	add r4, r10
	ldrb r0, [r4, 0x5]
	lsls r0, 28
	lsrs r0, 30
	strh r0, [r6, 0x26]
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x2
	eors r0, r1
	bl sub_80A8328
	mov r1, r8
	ands r1, r0
	lsls r1, 2
	ldrb r0, [r4, 0x5]
	ands r5, r0
	orrs r5, r1
	strb r5, [r4, 0x5]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r6, 0x8]
	ldrh r0, [r1, 0x2]
	strh r0, [r6, 0xA]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r6, 0x1E]
	ldr r0, =sub_80FF53C
	str r0, [r6]
_080FF51C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF458

	thumb_func_start sub_80FF53C
sub_80FF53C: @ 80FF53C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0x8]
	ldrh r0, [r4, 0x1C]
	adds r1, r0
	strh r1, [r4, 0x1C]
	ldr r2, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r5, r0, r2
	lsls r1, 16
	asrs r1, 24
	strh r1, [r5, 0x24]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080FF586
	ldrh r0, [r5, 0x24]
	negs r0, r0
	strh r0, [r5, 0x24]
_080FF586:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x10
	strh r0, [r4, 0x1E]
	movs r0, 0x1E
	ldrsh r2, [r4, r0]
	adds r0, r6, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	adds r0, r6, 0
	bl sub_80A7E6C
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _080FF5B4
	strh r0, [r4, 0x8]
	ldr r0, =sub_80FF5CC
	str r0, [r4]
_080FF5B4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF53C

	thumb_func_start sub_80FF5CC
sub_80FF5CC: @ 80FF5CC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080FF660
	ldr r0, =gTasks
	lsls r2, r3, 2
	adds r1, r2, r3
	lsls r1, 3
	adds r7, r1, r0
	movs r1, 0x8
	ldrsh r5, [r7, r1]
	adds r4, r0, 0
	cmp r5, 0
	bne _080FF674
	movs r0, 0x1
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80A7344
	ldr r6, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r6
	strh r5, [r1, 0x24]
	strh r5, [r1, 0x26]
	movs r5, 0x3
	ldrh r2, [r7, 0x24]
	ands r2, r5
	lsls r2, 2
	ldrb r3, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x3
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r7, 0x26]
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r1, 0x5]
	ands r4, r2
	orrs r4, r0
	strb r4, [r1, 0x5]
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
	b _080FF68E
	.pool
_080FF660:
	ldr r1, =gTasks
	lsls r2, r3, 2
	adds r0, r2, r3
	lsls r0, 3
	adds r0, r1
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	cmp r0, 0
	beq _080FF68E
_080FF674:
	adds r1, r2, r3
	lsls r1, 3
	adds r1, r4
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _080FF68E
	adds r0, r3, 0
	bl move_anim_task_del
_080FF68E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF5CC

	thumb_func_start sub_80FF698
sub_80FF698: @ 80FF698
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080FF6AA
	cmp r0, 0x1
	beq _080FF704
	b _080FF756
_080FF6AA:
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080FF6C2
	ldr r1, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1]
_080FF6C2:
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
	strh r0, [r5, 0x22]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _080FF756
	.pool
_080FF704:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080FF756
	adds r0, r5, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
	movs r0, 0x19
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A70C0
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_080FF756:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF698

	thumb_func_start sub_80FF768
sub_80FF768: @ 80FF768
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080FF7D4
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4]
	strh r0, [r5, 0x24]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x26]
	ldrb r0, [r4, 0x4]
	adds r0, 0x1E
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrb r1, [r4, 0x6]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	movs r2, 0x22
	ldrsh r0, [r5, r2]
	movs r2, 0x26
	ldrsh r1, [r5, r2]
	adds r0, r1
	cmp r0, 0x78
	ble _080FF7D4
	ldrh r0, [r5, 0x22]
	adds r1, r0, 0
	subs r1, 0x78
	ldrh r2, [r5, 0x26]
	adds r0, r2
	adds r1, r0
	strh r1, [r5, 0x22]
_080FF7D4:
	ldr r0, =sub_80FF8DC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF768

	thumb_func_start sub_80FF7EC
sub_80FF7EC: @ 80FF7EC
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x4
	mov r9, r0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	subs r4, r5
	lsls r4, 16
	lsrs r2, 24
	mov r1, r8
	subs r2, r1
	lsls r2, 16
	lsrs r2, 16
	lsrs r3, r4, 16
	mov r10, r3
	asrs r4, 16
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	muls r0, r4
	movs r1, 0x64
	str r2, [sp]
	bl __divsi3
	adds r5, r0
	mov r3, r9
	strh r5, [r3, 0x20]
	ldr r2, [sp]
	lsls r0, r2, 16
	asrs r0, 16
	movs r3, 0
	ldrsh r1, [r6, r3]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	add r8, r0
	mov r1, r8
	mov r0, r9
	strh r1, [r0, 0x22]
	ldrh r0, [r6, 0x2]
	mov r3, r9
	strh r0, [r3, 0x24]
	ldrh r0, [r6, 0x4]
	strh r0, [r3, 0x26]
	ldrb r0, [r6, 0x6]
	adds r0, 0x1E
	mov r1, r9
	adds r1, 0x43
	strb r0, [r1]
	ldrb r1, [r6, 0x8]
	mov r0, r9
	bl StartSpriteAnim
	ldrh r0, [r6, 0xA]
	mov r1, r9
	strh r0, [r1, 0x32]
	ldr r0, =sub_80FF8DC
	str r0, [r1, 0x1C]
	ldr r1, =gUnknown_0203A0F8
	mov r3, r9
	ldrh r0, [r3, 0x20]
	strh r0, [r1]
	ldrh r0, [r3, 0x22]
	strh r0, [r1, 0x2]
	mov r0, r10
	strh r0, [r1, 0x4]
	ldr r2, [sp]
	strh r2, [r1, 0x6]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF7EC

	thumb_func_start sub_80FF8DC
sub_80FF8DC: @ 80FF8DC
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x2E]
	adds r1, 0x1
	strh r1, [r3, 0x2E]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x32
	ldrsh r0, [r3, r2]
	subs r0, 0xA
	cmp r1, r0
	ble _080FF91C
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	movs r2, 0x3E
	adds r2, r3
	mov r12, r2
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_080FF91C:
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	movs r2, 0x32
	ldrsh r0, [r3, r2]
	cmp r1, r0
	ble _080FF92E
	adds r0, r3, 0
	bl move_anim_8072740
_080FF92E:
	pop {r0}
	bx r0
	thumb_func_end sub_80FF8DC

	thumb_func_start sub_80FF934
sub_80FF934: @ 80FF934
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080FF974
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r2, [r4]
	adds r0, r2
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r6, 0x22]
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x30]
	ldrh r0, [r4, 0x6]
	strh r0, [r6, 0x32]
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x34]
_080FF974:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	ldrh r1, [r6, 0x30]
	muls r0, r1
	strh r0, [r6, 0x24]
	movs r2, 0x2E
	ldrsh r1, [r6, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	movs r1, 0xFF
	ands r0, r1
	movs r2, 0x32
	ldrsh r1, [r6, r2]
	bl Sin
	strh r0, [r6, 0x26]
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _080FF9AA
	adds r0, r6, 0
	bl move_anim_8072740
_080FF9AA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FF934

	thumb_func_start sub_80FF9B8
sub_80FF9B8: @ 80FF9B8
	push {r4,r5,lr}
	movs r2, 0x20
	ldrsh r4, [r0, r2]
	lsls r4, 8
	movs r3, 0x22
	ldrsh r2, [r0, r3]
	orrs r4, r2
	movs r5, 0x3A
	ldrsh r2, [r0, r5]
	lsls r2, 8
	movs r5, 0x3C
	ldrsh r3, [r0, r5]
	orrs r2, r3
	lsls r1, 8
	strh r4, [r0, 0x38]
	strh r2, [r0, 0x3A]
	strh r1, [r0, 0x3C]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FF9B8

	thumb_func_start sub_80FF9E0
sub_80FF9E0: @ 80FF9E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	ldrh r0, [r0, 0x38]
	lsrs r1, r0, 8
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r1, r8
	ldrh r0, [r1, 0x3A]
	lsrs r2, r0, 8
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r1, [r1, 0x3C]
	lsls r0, r1, 16
	asrs r0, 24
	lsls r0, 16
	lsrs r6, r0, 16
	movs r3, 0xFF
	ands r3, r1
	cmp r2, 0
	bne _080FFA1A
	movs r2, 0x20
	negs r2, r2
	b _080FFA22
_080FFA1A:
	cmp r2, 0xFF
	bne _080FFA22
	movs r2, 0x88
	lsls r2, 1
_080FFA22:
	mov r0, r9
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	mov r1, r10
	subs r0, r2, r1
	lsls r5, r3, 16
	asrs r5, 16
	muls r0, r5
	lsls r1, r6, 16
	asrs r7, r1, 16
	adds r1, r7, 0
	bl __divsi3
	adds r6, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	muls r0, r5
	adds r1, r7, 0
	bl __divsi3
	add r6, r10
	mov r1, r8
	strh r6, [r1, 0x20]
	add r0, r9
	strh r0, [r1, 0x22]
	adds r5, 0x1
	lsls r5, 16
	lsrs r3, r5, 16
	asrs r5, 16
	cmp r5, r7
	beq _080FFA74
	lsls r1, r7, 8
	lsls r0, r3, 16
	asrs r0, 16
	orrs r0, r1
	mov r1, r8
	strh r0, [r1, 0x3C]
	movs r0, 0
	b _080FFA76
_080FFA74:
	movs r0, 0x1
_080FFA76:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80FF9E0

	thumb_func_start sub_80FFA84
sub_80FFA84: @ 80FFA84
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xA
	bne _080FFA98
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_080FFA98:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	ble _080FFAAC
	adds r0, r4, 0
	bl move_anim_8072740
_080FFAAC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FFA84

	thumb_func_start sub_80FFAB4
sub_80FFAB4: @ 80FFAB4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x2E]
	adds r1, r0
	movs r5, 0
	strh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _080FFADE
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x2E]
_080FFADE:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	lsls r2, 3
	movs r1, 0x1E
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	bl sub_80FF9E0
	lsls r0, 24
	cmp r0, 0
	beq _080FFB0E
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x2E]
	ldr r0, =sub_80FFA84
	str r0, [r4, 0x1C]
_080FFB0E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFAB4

	thumb_func_start sub_80FFB18
sub_80FFB18: @ 80FFB18
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	ldrb r4, [r4]
	cmp r0, r4
	bne _080FFB68
	strh r6, [r5, 0x3A]
	adds r0, r2, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3C
	bl sub_80FF9B8
	movs r0, 0x1
	b _080FFB7A
	.pool
_080FFB68:
	strh r6, [r5, 0x3A]
	adds r0, r2, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3C
	bl sub_80FF9B8
	movs r0, 0x3
_080FFB7A:
	strh r0, [r5, 0x34]
	movs r0, 0x3C
	strh r0, [r5, 0x36]
	ldr r0, =sub_80FFAB4
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFB18

	thumb_func_start sub_80FFB90
sub_80FFB90: @ 80FFB90
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x2E]
	adds r1, r0
	movs r5, 0
	strh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _080FFBBA
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x2E]
_080FFBBA:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	lsls r2, 3
	movs r1, 0x1E
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	bl sub_80FF9E0
	lsls r0, 24
	cmp r0, 0
	beq _080FFBEC
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x2E]
	adds r0, r4, 0
	bl move_anim_8072740
_080FFBEC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FFB90

	thumb_func_start sub_80FFBF4
sub_80FFBF4: @ 80FFBF4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080FFC38
	strh r0, [r5, 0x3A]
	adds r0, r6, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	adds r0, r5, 0
	movs r1, 0x28
	bl sub_80FF9B8
	movs r0, 0x3
	strh r0, [r5, 0x34]
	movs r0, 0x3C
	strh r0, [r5, 0x36]
	ldr r0, =sub_80FFAB4
	b _080FFC62
	.pool
_080FFC38:
	movs r0, 0xFF
	strh r0, [r5, 0x3A]
	adds r0, r6, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080FFC50
	movs r0, 0
	strh r0, [r5, 0x3A]
_080FFC50:
	adds r0, r5, 0
	movs r1, 0x28
	bl sub_80FF9B8
	movs r0, 0x3
	strh r0, [r5, 0x34]
	movs r0, 0x3C
	strh r0, [r5, 0x36]
	ldr r0, =sub_80FFB90
_080FFC62:
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFBF4

	thumb_func_start sub_80FFC70
sub_80FFC70: @ 80FFC70
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080FFC8A
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x30]
_080FFC8A:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	muls r0, r1
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080FFCAA
	adds r0, r4, 0
	bl move_anim_8072740
_080FFCAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFC70

	thumb_func_start sub_80FFCB4
sub_80FFCB4: @ 80FFCB4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0
	bl sub_80A6980
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gAnimationBankTarget
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	ldrb r4, [r4]
	cmp r0, r4
	bne _080FFD04
	strh r6, [r5, 0x3A]
	adds r0, r2, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3C
	bl sub_80FF9B8
	movs r0, 0x1
	b _080FFD16
	.pool
_080FFD04:
	strh r6, [r5, 0x3A]
	adds r0, r2, 0
	adds r0, 0xA
	strh r0, [r5, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3C
	bl sub_80FF9B8
	movs r0, 0x3
_080FFD16:
	strh r0, [r5, 0x34]
	movs r0, 0x3C
	strh r0, [r5, 0x36]
	ldr r0, =sub_80FFD2C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFCB4

	thumb_func_start sub_80FFD2C
sub_80FFD2C: @ 80FFD2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 7
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x2E]
	adds r1, r0
	movs r5, 0
	strh r1, [r4, 0x2E]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _080FFD56
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x2E]
_080FFD56:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x80
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	lsls r2, 3
	movs r1, 0x1E
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	bne _080FFD8A
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl PlaySE12WithPanning
_080FFD8A:
	adds r0, r4, 0
	bl sub_80FF9E0
	lsls r0, 24
	cmp r0, 0
	beq _080FFDB2
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x2E]
	ldr r0, =sub_80FFA84
	str r0, [r4, 0x1C]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl PlaySE12WithPanning
_080FFDB2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFD2C

	thumb_func_start sub_80FFDBC
sub_80FFDBC: @ 80FFDBC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080FFE50
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080FFDE4
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	strh r1, [r4, 0x30]
	movs r1, 0x78
	strh r1, [r4, 0x20]
	adds r5, r0, 0
	b _080FFE06
	.pool
_080FFDE4:
	ldr r0, =gBattleAnimArgs
	movs r1, 0x2
	ldrsh r3, [r0, r1]
	adds r1, r3, 0
	subs r1, 0x20
	adds r2, r1, 0
	adds r5, r0, 0
	cmp r1, 0
	bge _080FFDFA
	adds r2, r3, 0
	adds r2, 0xDF
_080FFDFA:
	asrs r0, r2, 8
	lsls r0, 8
	subs r0, r1, r0
	strh r0, [r4, 0x30]
	movs r0, 0x46
	strh r0, [r4, 0x20]
_080FFE06:
	ldrh r0, [r5]
	strh r0, [r4, 0x22]
	strh r0, [r4, 0x32]
	movs r0, 0x14
	strh r0, [r4, 0x36]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x3C
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	ldr r0, =sub_80FFE58
	str r0, [r4, 0x1C]
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xBE
	bhi _080FFE48
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
	b _080FFE4E
	.pool
_080FFE48:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
_080FFE4E:
	strb r0, [r1]
_080FFE50:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FFDBC

	thumb_func_start sub_80FFE58
sub_80FFE58: @ 80FFE58
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FFE6A
	cmp r0, 0x1
	beq _080FFE9A
	b _080FFEBA
_080FFE6A:
	ldrh r5, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x4E
	ble _080FFE82
	movs r0, 0x1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _080FFEBA
_080FFE82:
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl __divsi3
	adds r0, r5, r0
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x36]
	adds r1, 0x3
	strh r1, [r4, 0x36]
	strh r0, [r4, 0x22]
	b _080FFEBA
_080FFE9A:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FFEBA
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080FFEBA
	movs r0, 0
	strh r0, [r4, 0x2E]
	strh r0, [r4, 0x32]
	ldr r0, =sub_80FFEC4
	str r0, [r4, 0x1C]
_080FFEBA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFE58

	thumb_func_start sub_80FFEC4
sub_80FFEC4: @ 80FFEC4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_08592700
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r3, r0, r1
	adds r0, r5, 0x1
	adds r0, r3, r0
	ldrh r2, [r4, 0x32]
	movs r6, 0x32
	ldrsh r1, [r4, r6]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	bne _080FFF10
	adds r0, r5, 0x2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x7F
	bne _080FFEFC
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FFF7C
	str r0, [r4, 0x1C]
_080FFEFC:
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _080FFF76
	.pool
_080FFF10:
	adds r0, r2, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r1, r0, r5
	movs r2, 0
	ldrsb r2, [r1, r2]
	adds r1, r5, 0x2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r0, r2
	ldrh r1, [r4, 0x30]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080FFF5E
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xBE
	bhi _080FFF56
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
	b _080FFF5C
_080FFF56:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
_080FFF5C:
	strb r0, [r1]
_080FFF5E:
	movs r6, 0x30
	ldrsh r0, [r4, r6]
	movs r1, 0x3C
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
_080FFF76:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80FFEC4

	thumb_func_start sub_80FFF7C
sub_80FFF7C: @ 80FFF7C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x14
	ble _080FFF8E
	adds r0, r4, 0
	bl move_anim_8072740
_080FFF8E:
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FFF7C

	thumb_func_start sub_80FFFC0
sub_80FFFC0: @ 80FFFC0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	strh r0, [r5, 0x10]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x16]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A861C
	strh r0, [r5, 0x1C]
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A861C
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0x1
	bne _08100028
	movs r1, 0x1
_08100028:
	strh r1, [r5, 0x12]
	movs r3, 0x12
	ldrsh r0, [r5, r3]
	lsls r0, 6
	movs r1, 0x38
	subs r1, r0
	strh r1, [r5, 0x1A]
	ldrh r0, [r5, 0x16]
	subs r0, r1
	ldrh r1, [r5, 0x14]
	adds r0, r1
	strh r0, [r5, 0x18]
	ldr r0, =gUnknown_08592778
	movs r2, 0x18
	ldrsh r1, [r5, r2]
	movs r3, 0x1A
	ldrsh r2, [r5, r3]
	ldrb r3, [r5, 0x10]
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xC]
	cmp r0, 0x40
	bne _08100060
	adds r0, r6, 0
	bl move_anim_task_del
_08100060:
	ldr r4, =gSprites
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xA
	strh r1, [r0, 0x2E]
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r5, 0x18]
	strh r1, [r0, 0x30]
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r1, [r5, r3]
	muls r1, r0
	ldrh r0, [r5, 0x14]
	subs r0, r1
	strh r0, [r2, 0x32]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r5, 0x1A]
	strh r1, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	lsrs r2, r0, 31
	adds r0, r2
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	muls r0, r2
	ldrh r2, [r5, 0x16]
	adds r0, r2
	strh r0, [r1, 0x36]
	movs r3, 0xC
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_8100504
	movs r1, 0xC
	ldrsh r2, [r5, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x38]
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_80A68D4
	ldr r0, =sub_8100128
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FFFC0

	thumb_func_start sub_8100128
sub_8100128: @ 8100128
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	movs r0, 0xC
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r5, [r6, r1]
	cmp r5, 0x7
	bne _08100150
	b _08100380
_08100150:
	cmp r5, 0x7
	bgt _0810019E
	cmp r5, 0x3
	bne _0810015A
	b _08100272
_0810015A:
	cmp r5, 0x3
	bgt _08100174
	cmp r5, 0x1
	beq _08100204
	cmp r5, 0x1
	bgt _08100254
	cmp r5, 0
	beq _081001E6
	b _081004FC
	.pool
_08100174:
	cmp r5, 0x5
	bne _0810017A
	b _081002E8
_0810017A:
	cmp r5, 0x5
	ble _08100180
	b _08100362
_08100180:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _08100196
	b _081004FC
_08100196:
	movs r0, 0x5
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_0810019E:
	cmp r5, 0xB
	bne _081001A4
	b _08100464
_081001A4:
	cmp r5, 0xB
	bgt _081001D2
	cmp r5, 0x9
	bne _081001AE
	b _081003D2
_081001AE:
	cmp r5, 0x9
	ble _081001B4
	b _08100448
_081001B4:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _081001CA
	b _081004FC
_081001CA:
	movs r0, 0x9
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_081001D2:
	cmp r5, 0xD
	bne _081001D8
	b _081004D6
_081001D8:
	cmp r5, 0xD
	bge _081001DE
	b _081004B6
_081001DE:
	cmp r5, 0xFF
	bne _081001E4
	b _081004E6
_081001E4:
	b _081004FC
_081001E6:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _081001FC
	b _081004FC
_081001FC:
	movs r0, 0x1
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_08100204:
	ldrh r2, [r4, 0x24]
	ldrh r3, [r4, 0x20]
	adds r2, r3
	movs r0, 0
	strh r2, [r4, 0x20]
	ldrh r1, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r1, r3
	strh r1, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x30]
	ldrh r0, [r6, 0x14]
	strh r0, [r4, 0x32]
	strh r1, [r4, 0x34]
	ldrh r0, [r6, 0x16]
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	ldrh r0, [r6, 0x10]
	adds r0, 0x2
	strh r0, [r6, 0x10]
	strh r5, [r6, 0xE]
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_08100254:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _0810026A
	b _081004FC
_0810026A:
	movs r0, 0x3
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_08100272:
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x20]
	adds r1, r0
	movs r0, 0
	strh r1, [r4, 0x20]
	ldrh r2, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r2, r3
	strh r2, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r1, [r6, r3]
	muls r1, r0
	ldrh r0, [r6, 0x14]
	subs r0, r1
	strh r0, [r4, 0x32]
	strh r2, [r4, 0x34]
	movs r1, 0x1E
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r2, 0x12
	ldrsh r1, [r6, r2]
	muls r1, r0
	ldrh r0, [r6, 0x16]
	subs r0, r1
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	movs r0, 0x2
	strh r0, [r6, 0xE]
	ldrh r0, [r6, 0x10]
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_081002E8:
	ldrh r1, [r4, 0x24]
	ldrh r3, [r4, 0x20]
	adds r1, r3
	movs r0, 0
	strh r1, [r4, 0x20]
	ldrh r2, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r2, r3
	strh r2, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r1, [r6, r3]
	muls r0, r1
	ldrh r1, [r6, 0x14]
	adds r0, r1
	strh r0, [r4, 0x32]
	strh r2, [r4, 0x34]
	movs r2, 0x1E
	ldrsh r0, [r6, r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r1, [r6, r3]
	muls r0, r1
	ldrh r1, [r6, 0x16]
	adds r0, r1
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	ldrh r1, [r6, 0x10]
	subs r1, 0x2
	strh r1, [r6, 0x10]
	movs r0, 0x3
	strh r0, [r6, 0xE]
	adds r0, r4, 0
	adds r0, 0x43
	strb r1, [r0]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_08100362:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _08100378
	b _081004FC
_08100378:
	movs r0, 0x7
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_08100380:
	ldrh r2, [r4, 0x24]
	ldrh r3, [r4, 0x20]
	adds r2, r3
	movs r0, 0
	strh r2, [r4, 0x20]
	ldrh r1, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r1, r3
	strh r1, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x30]
	ldrh r0, [r6, 0x14]
	strh r0, [r4, 0x32]
	strh r1, [r4, 0x34]
	ldrh r0, [r6, 0x16]
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	ldrh r1, [r6, 0x10]
	adds r1, 0x2
	strh r1, [r6, 0x10]
	movs r0, 0x4
	strh r0, [r6, 0xE]
	adds r0, r4, 0
	adds r0, 0x43
	strb r1, [r0]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_081003D2:
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x20]
	adds r1, r0
	movs r0, 0
	strh r1, [r4, 0x20]
	ldrh r2, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r2, r3
	strh r2, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r3, 0x12
	ldrsh r1, [r6, r3]
	muls r1, r0
	ldrh r0, [r6, 0x14]
	subs r0, r1
	strh r0, [r4, 0x32]
	strh r2, [r4, 0x34]
	movs r1, 0x1E
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r0, 0xA
	movs r2, 0x12
	ldrsh r1, [r6, r2]
	muls r0, r1
	ldrh r3, [r6, 0x16]
	adds r0, r3
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	movs r0, 0x5
	strh r0, [r6, 0xE]
	ldrh r0, [r6, 0x10]
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_08100448:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _081004FC
	movs r0, 0xB
	strh r0, [r6, 0x26]
	movs r0, 0xFF
	b _081004FA
_08100464:
	ldrh r2, [r4, 0x24]
	ldrh r0, [r4, 0x20]
	adds r2, r0
	movs r0, 0
	strh r2, [r4, 0x20]
	ldrh r1, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r1, r3
	strh r1, [r4, 0x22]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0xA
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x30]
	ldrh r0, [r6, 0x18]
	strh r0, [r4, 0x32]
	strh r1, [r4, 0x34]
	ldrh r0, [r6, 0x1A]
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_8100504
	strh r0, [r4, 0x38]
	ldrh r1, [r6, 0x10]
	subs r1, 0x2
	strh r1, [r6, 0x10]
	movs r0, 0x6
	strh r0, [r6, 0xE]
	adds r0, r4, 0
	adds r0, 0x43
	strb r1, [r0]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl sub_80A68D4
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_081004B6:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_8100524
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _081004FC
	adds r0, r4, 0
	bl DestroySprite
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	b _081004FA
_081004D6:
	movs r1, 0x20
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081004FC
	adds r0, r2, 0
	bl move_anim_task_del
	b _081004FC
_081004E6:
	ldrh r0, [r6, 0xA]
	adds r0, 0x1
	strh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _081004FC
	movs r0, 0
	strh r0, [r6, 0xA]
	ldrh r0, [r6, 0x26]
_081004FA:
	strh r0, [r6, 0x8]
_081004FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8100128

	thumb_func_start sub_8100504
sub_8100504: @ 8100504
	push {lr}
	movs r2, 0x8
	movs r3, 0x36
	ldrsh r1, [r0, r3]
	movs r3, 0x22
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _0810051A
	negs r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
_0810051A:
	lsls r0, r2, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8100504

	thumb_func_start sub_8100524
sub_8100524: @ 8100524
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldrh r0, [r6, 0x24]
	adds r0, 0x1
	strh r0, [r6, 0x24]
	lsls r0, 16
	cmp r0, 0
	ble _081005BA
	movs r0, 0
	strh r0, [r6, 0x24]
	ldr r0, =gSprites
	mov r8, r0
	movs r2, 0xC
	ldrsh r1, [r6, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrh r1, [r0, 0x24]
	ldrh r2, [r0, 0x20]
	adds r1, r2
	ldrh r2, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r2, r0
	ldr r0, =gUnknown_08592778
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	ldrb r3, [r6, 0x10]
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081005BA
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	mov r0, r8
	adds r4, r5, r0
	strh r7, [r4, 0x3A]
	movs r0, 0xC
	strh r0, [r4, 0x3C]
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	ldrh r2, [r6, 0x22]
	movs r0, 0x1
	ands r0, r2
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x22]
	adds r0, 0x1
	strh r0, [r1, 0x22]
	ldrb r1, [r6, 0xE]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r6, 0x10]
	adds r4, 0x43
	strb r0, [r4]
	mov r0, r8
	adds r0, 0x1C
	adds r5, r0
	ldr r0, =sub_81005D4
	str r0, [r5]
_081005BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100524

	thumb_func_start sub_81005D4
sub_81005D4: @ 81005D4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08100636
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _08100636
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_08100636:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81005D4

	thumb_func_start sub_8100640
sub_8100640: @ 8100640
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810065C
	ldr r0, =gAnimationBankAttacker
	b _0810065E
	.pool
_0810065C:
	ldr r0, =gAnimationBankTarget
_0810065E:
	ldrb r6, [r0]
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08100688
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x32]
	ldr r0, =0x0000fff0
	b _08100698
	.pool
_08100688:
	movs r0, 0x1
	strh r0, [r4, 0x36]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r4, 0x32]
	movs r0, 0x80
	lsls r0, 1
_08100698:
	strh r0, [r4, 0x20]
	adds r7, r1, 0
	adds r5, r7, 0
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x34]
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081006CE
	cmp r0, 0x1
	bgt _081006C0
	cmp r0, 0
	beq _081006CA
	b _08100738
	.pool
_081006C0:
	cmp r0, 0x2
	beq _081006D4
	cmp r0, 0x3
	beq _08100700
	b _08100738
_081006CA:
	ldrh r0, [r5]
	b _081006E4
_081006CE:
	ldrh r0, [r5]
	strh r0, [r4, 0x22]
	b _0810071A
_081006D4:
	adds r0, r6, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5]
	adds r0, r5
_081006E4:
	strh r0, [r4, 0x22]
	adds r0, r6, 0
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	b _08100738
_08100700:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r7, [r7]
	adds r0, r7
	strh r0, [r4, 0x22]
	movs r0, 0x1
	bl GetAnimBankSpriteId
_0810071A:
	adds r0, r6, 0
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
_08100738:
	ldr r0, =sub_810074C
	str r0, [r4, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100640

	thumb_func_start sub_810074C
sub_810074C: @ 810074C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x3C
	ldrsh r3, [r4, r0]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	ldr r1, =gSineTable
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r2
	asrs r0, 8
	strh r0, [r4, 0x26]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	muls r0, r3
	strh r0, [r4, 0x24]
	movs r5, 0x34
	ldrsh r0, [r4, r5]
	muls r0, r3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081007A4
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	movs r5, 0x20
	ldrsh r1, [r4, r5]
	adds r0, r1
	cmp r0, 0xF7
	ble _081007BC
	b _081007B6
	.pool
_081007A4:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _081007BC
_081007B6:
	adds r0, r4, 0
	bl move_anim_8074EE0
_081007BC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810074C

	thumb_func_start sub_81007C4
sub_81007C4: @ 81007C4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _081007E8
	cmp r0, 0x1
	beq _0810081C
	b _08100876
	.pool
_081007E8:
	ldr r0, =0x0000274f
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r2, 0x80
	lsls r2, 1
	adds r4, r2, 0
	adds r0, r4
	strh r0, [r5, 0x18]
	ldr r0, =0x000027b0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	adds r0, r4
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _08100876
	.pool
_0810081C:
	ldrh r0, [r5, 0x1A]
	adds r0, 0x1
	movs r7, 0
	strh r0, [r5, 0x1A]
	lsls r0, 16
	cmp r0, 0
	blt _08100876
	strh r7, [r5, 0x1A]
	ldrh r0, [r5, 0x18]
	ldrb r2, [r5, 0x1C]
	ldr r4, =gUnknown_08592878
	movs r3, 0x1E
	ldrsh r1, [r5, r3]
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r5, 0x20]
	ldrb r2, [r5, 0x1C]
	movs r3, 0x1E
	ldrsh r1, [r5, r3]
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x11
	bne _08100876
	strh r7, [r5, 0x1C]
	ldrh r0, [r5, 0x1E]
	adds r0, 0x1
	strh r0, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bne _08100876
	strh r7, [r5, 0x1E]
_08100876:
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0810088A
	adds r0, r6, 0
	bl move_anim_task_del
_0810088A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81007C4

	thumb_func_start sub_8100898
sub_8100898: @ 8100898
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r1, =gBattleAnimArgs
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081008B4
	adds r0, r6, 0
	bl move_anim_8072740
	b _0810098E
	.pool
_081008B4:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _081008C4
	ldr r4, =gAnimationBankAttacker
	b _081008C6
	.pool
_081008C4:
	ldr r4, =gAnimationBankTarget
_081008C6:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x8]
	strh r1, [r6, 0x2E]
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	adds r7, r0, 0
	cmp r1, 0
	bne _08100908
	ldrh r0, [r7, 0x4]
	adds r0, r5
	strh r0, [r6, 0x20]
	ldrh r0, [r7, 0x6]
	adds r0, r2
	strh r0, [r6, 0x22]
	strh r5, [r6, 0x38]
	strh r2, [r6, 0x3A]
	b _08100918
	.pool
_08100908:
	strh r5, [r6, 0x20]
	strh r2, [r6, 0x22]
	ldrh r0, [r7, 0x4]
	adds r0, r5
	strh r0, [r6, 0x38]
	ldrh r0, [r7, 0x6]
	adds r0, r2
	strh r0, [r6, 0x3A]
_08100918:
	ldrh r4, [r6, 0x20]
	lsls r0, r4, 4
	strh r0, [r6, 0x30]
	ldrh r5, [r6, 0x22]
	lsls r0, r5, 4
	strh r0, [r6, 0x32]
	movs r1, 0x38
	ldrsh r0, [r6, r1]
	movs r2, 0x20
	ldrsh r1, [r6, r2]
	subs r0, r1
	lsls r0, 4
	movs r3, 0x8
	ldrsh r1, [r7, r3]
	bl __divsi3
	strh r0, [r6, 0x34]
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	movs r2, 0x22
	ldrsh r1, [r6, r2]
	subs r0, r1
	lsls r0, 4
	movs r3, 0x8
	ldrsh r1, [r7, r3]
	bl __divsi3
	strh r0, [r6, 0x36]
	ldrh r0, [r6, 0x38]
	subs r0, r4
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r6, 0x3A]
	subs r1, r5
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	lsrs r4, r0, 16
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810097A
	ldr r1, =0xffff8000
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
_0810097A:
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldr r0, =sub_81009A0
	str r0, [r6, 0x1C]
_0810098E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100898

	thumb_func_start sub_81009A0
sub_81009A0: @ 81009A0
	push {r4,lr}
	adds r2, r0, 0
	ldrh r3, [r2, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _081009D0
	ldrh r0, [r2, 0x34]
	ldrh r4, [r2, 0x30]
	adds r0, r4
	strh r0, [r2, 0x30]
	ldrh r1, [r2, 0x36]
	ldrh r4, [r2, 0x32]
	adds r1, r4
	strh r1, [r2, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r2, 0x22]
	subs r0, r3, 0x1
	strh r0, [r2, 0x2E]
	b _081009D6
_081009D0:
	adds r0, r2, 0
	bl move_anim_8074EE0
_081009D6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81009A0

	thumb_func_start sub_81009DC
sub_81009DC: @ 81009DC
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081009F2
	adds r0, r2, 0
	bl move_anim_8072740
_081009F2:
	pop {r0}
	bx r0
	thumb_func_end sub_81009DC

	thumb_func_start sub_81009F8
sub_81009F8: @ 81009F8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08100A20
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	b _08100A2C
	.pool
_08100A20:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	ldrh r0, [r0, 0x2]
_08100A2C:
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81009F8

	thumb_func_start sub_8100A50
sub_8100A50: @ 8100A50
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08100A6A
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_08100A6A:
	ldr r0, =sub_81009DC
	str r0, [r5, 0x1C]
	ldr r4, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_80A6864
	ldrh r0, [r4, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100A50

	thumb_func_start sub_8100A94
sub_8100A94: @ 8100A94
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x34]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x38]
	ldrb r1, [r1, 0xC]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A66DC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100A94

	thumb_func_start sub_8100AE0
sub_8100AE0: @ 8100AE0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08100B14
	ldrh r0, [r5, 0x22]
	adds r0, 0x8
	strh r0, [r5, 0x22]
_08100B14:
	ldr r0, =sub_8100CCC
	str r0, [r5, 0x1C]
	ldr r0, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	adds r3, r0, 0
	cmp r1, 0
	bne _08100B3C
	ldrh r0, [r3]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x20]
	b _08100B50
	.pool
_08100B3C:
	ldrh r0, [r5, 0x20]
	ldrh r1, [r3]
	subs r0, r1
	strh r0, [r5, 0x20]
	adds r2, r5, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08100B50:
	ldrh r0, [r3, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	ldr r1, =0xfffffc00
	adds r0, r1, 0
	ldrh r2, [r5, 0x30]
	adds r1, r0, r2
	strh r1, [r5, 0x30]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
	ldrh r0, [r3, 0x4]
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08100B7E
	negs r0, r1
	strh r0, [r5, 0x30]
_08100B7E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100AE0

	thumb_func_start sub_8100B88
sub_8100B88: @ 8100B88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _08100BA8
	cmp r0, 0x1
	ble _08100C24
	cmp r0, 0x2
	beq _08100BC8
	b _08100C24
	.pool
_08100BA8:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r4, 0x2
	eors r0, r4
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r5]
	eors r4, r0
	adds r0, r4, 0
	b _08100C34
	.pool
_08100BC8:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5]
	movs r2, 0x2
	mov r8, r2
	mov r1, r8
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _08100C3E
	ldrb r0, [r5]
	mov r2, r8
	eors r0, r2
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r7
	lsrs r7, r0, 1
	ldrb r0, [r5]
	mov r1, r8
	eors r0, r1
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	lsrs r4, r0, 1
	b _08100C3E
	.pool
_08100C24:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r4]
_08100C34:
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r4, r0, 24
_08100C3E:
	strh r7, [r6, 0x20]
	strh r4, [r6, 0x22]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08100C56
	ldrh r0, [r6, 0x22]
	adds r0, 0x8
	strh r0, [r6, 0x22]
_08100C56:
	ldr r0, =sub_8100CCC
	str r0, [r6, 0x1C]
	ldr r0, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	adds r3, r0, 0
	cmp r1, 0
	bne _08100C7C
	ldrh r0, [r3]
	ldrh r1, [r6, 0x20]
	adds r0, r1
	strh r0, [r6, 0x20]
	b _08100C90
	.pool
_08100C7C:
	ldrh r0, [r6, 0x20]
	ldrh r1, [r3]
	subs r0, r1
	strh r0, [r6, 0x20]
	adds r2, r6, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08100C90:
	ldrh r0, [r3, 0x2]
	ldrh r2, [r6, 0x22]
	adds r0, r2
	strh r0, [r6, 0x22]
	ldr r1, =0xfffffc00
	adds r0, r1, 0
	ldrh r2, [r6, 0x30]
	adds r1, r0, r2
	strh r1, [r6, 0x30]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	ldrh r2, [r6, 0x32]
	adds r0, r2
	strh r0, [r6, 0x32]
	ldrh r0, [r3, 0x4]
	strh r0, [r6, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08100CBE
	negs r0, r1
	strh r0, [r6, 0x30]
_08100CBE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100B88

	thumb_func_start sub_8100CCC
sub_8100CCC: @ 8100CCC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x34]
	adds r0, r1, r2
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08100CEE
	adds r0, r1, 0
	adds r0, 0x18
	b _08100CF2
_08100CEE:
	adds r0, r1, 0
	subs r0, 0x18
_08100CF2:
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	subs r0, 0x18
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _08100D28
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
_08100D28:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100CCC

	thumb_func_start sub_8100D38
sub_8100D38: @ 8100D38
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x32]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	cmp r0, 0x1
	ble _08100DDC
	ldrh r1, [r5, 0x34]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08100D94
	adds r3, r5, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	strb r0, [r3]
	ldr r4, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r3, [r0]
	adds r1, r2, 0
	ands r1, r3
	strb r1, [r0]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	b _08100DCA
	.pool
_08100D94:
	adds r1, r5, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r3, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
_08100DCA:
	movs r0, 0
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	b _08100DE0
	.pool
_08100DDC:
	adds r0, r1, 0x1
	strh r0, [r5, 0x32]
_08100DE0:
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0xA
	bne _08100E10
	movs r2, 0x2E
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	adds r0, r5, 0
	bl move_anim_8072740
_08100E10:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100D38

	thumb_func_start sub_8100E1C
sub_8100E1C: @ 8100E1C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08100E44
	ldrh r0, [r5, 0x20]
	ldrh r1, [r4]
	subs r0, r1
	b _08100E4A
	.pool
_08100E44:
	ldrh r0, [r4]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_08100E4A:
	strh r0, [r5, 0x20]
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xA]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x6]
	negs r0, r0
	strh r0, [r5, 0x30]
	ldrh r0, [r4, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x34]
	ldr r1, =sub_8100E80
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100E1C

	thumb_func_start sub_8100E80
sub_8100E80: @ 8100E80
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x64
	bl Cos
	strh r0, [r4, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	bgt _08100EAC
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0
	b _08100EB2
_08100EAC:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0xE
_08100EB2:
	strb r0, [r1]
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x2E]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	adds r0, 0x82
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08100EE8
	adds r0, r4, 0
	bl move_anim_8072740
_08100EE8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8100E80

	thumb_func_start sub_8100EF0
sub_8100EF0: @ 8100EF0
	push {r4-r6,lr}
	adds r5, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08100F06
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	adds r0, 0x8
	strh r0, [r1, 0x2]
_08100F06:
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A60AC
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A60AC
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
	strh r0, [r5, 0x22]
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08100F44
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08100F6C
_08100F44:
	ldrb r0, [r6]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r5, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	b _08100F84
	.pool
_08100F6C:
	ldrb r0, [r6]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
_08100F84:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	ldr r0, =0x00002828
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r5, 0x32]
	movs r4, 0x10
	movs r0, 0x10
	strh r0, [r5, 0x3C]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r0, [r5, 0x3C]
	lsls r1, r0, 8
	subs r4, r0
	orrs r1, r4
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_8100FD4
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100EF0

	thumb_func_start sub_8100FD4
sub_8100FD4: @ 8100FD4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	adds r0, 0x60
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08101032
	movs r0, 0
	strh r0, [r4, 0x30]
	ldr r1, =gPlttBufferFaded
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	adds r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r5, [r0]
	movs r2, 0
	adds r6, r1, 0
	adds r3, r6, 0
_0810100C:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r2, 0x1
	adds r0, r2
	lsls r1, r0, 1
	adds r1, r3
	adds r0, 0x1
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	cmp r2, 0x5
	ble _0810100C
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	adds r0, 0x7
	lsls r0, 1
	adds r0, r6
	strh r5, [r0]
_08101032:
	ldrh r2, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	ble _0810106C
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _08101080
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810106C
	movs r0, 0
	strh r0, [r4, 0x3A]
	subs r2, 0x1
	strh r2, [r4, 0x3C]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_0810106C:
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08101080
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	b _081010C2
	.pool
_08101080:
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081010C2
	movs r0, 0
	strh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r2, 0x1
	strh r2, [r4, 0x3C]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081010C2
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80A67F4
	str r0, [r4, 0x1C]
_081010C2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8100FD4

	thumb_func_start sub_81010CC
sub_81010CC: @ 81010CC
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x0000ffe8
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x2E]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r5, [r4, 0x34]
	strh r5, [r4, 0x36]
	strh r5, [r4, 0x3A]
	movs r0, 0x10
	strh r0, [r4, 0x3C]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_8101138
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81010CC

	thumb_func_start sub_8101138
sub_8101138: @ 8101138
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _08101146
	b _08101290
_08101146:
	lsls r0, 2
	ldr r1, =_08101154
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08101154:
	.4byte _08101168
	.4byte _081011CC
	.4byte _081011E8
	.4byte _08101266
	.4byte _0810127A
_08101168:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	bgt _08101176
	b _08101290
_08101176:
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08101198
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _081011A6
	adds r0, r1, 0x1
	strh r0, [r4, 0x3A]
	b _081011A6
_08101198:
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _081011A6
	subs r0, r1, 0x1
	strh r0, [r4, 0x3C]
_081011A6:
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08101290
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08101290
	strh r0, [r4, 0x30]
	b _08101272
_081011CC:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _08101290
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _08101272
_081011E8:
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0x4
	bl sub_8101298
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0810120A
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
_0810120A:
	ldrh r0, [r4, 0x32]
	adds r1, r0, 0x1
	strh r1, [r4, 0x32]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x1D
	ble _08101290
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08101230
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0810123E
	subs r0, r1, 0x1
	strh r0, [r4, 0x3A]
	b _0810123E
_08101230:
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _0810123E
	adds r0, r1, 0x1
	strh r0, [r4, 0x3C]
_0810123E:
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _08101290
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bne _08101290
	strh r1, [r4, 0x30]
	strh r1, [r4, 0x32]
	b _08101272
_08101266:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08101272:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _08101290
_0810127A:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
_08101290:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8101138

	thumb_func_start sub_8101298
sub_8101298: @ 8101298
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0xB
	bgt _081012AA
	ldrh r0, [r4, 0x36]
	adds r0, 0x2
	strh r0, [r4, 0x36]
_081012AA:
	ldrh r5, [r4, 0x34]
	adds r0, r5, 0
	subs r0, 0x12
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	cmp r0, 0x17
	bhi _081012C0
	ldrh r0, [r4, 0x36]
	subs r0, 0x2
	strh r0, [r4, 0x36]
_081012C0:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x2F
	ble _081012CE
	ldrh r0, [r4, 0x36]
	adds r0, 0x2
	strh r0, [r4, 0x36]
_081012CE:
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0x9
	bl __divsi3
	strh r0, [r4, 0x24]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0xE
	bl __divsi3
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	bge _081012F4
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x26]
_081012F4:
	adds r0, r5, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3B
	ble _08101304
	movs r0, 0
	strh r0, [r4, 0x34]
_08101304:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8101298

	thumb_func_start sub_810130C
sub_810130C: @ 810130C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08101320
	adds r0, r4, 0
	bl sub_80A6838
_08101320:
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x32]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A656C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810130C

	thumb_func_start sub_810135C
sub_810135C: @ 810135C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08101378
	ldr r0, =gAnimationBankAttacker
	b _0810137A
	.pool
_08101378:
	ldr r0, =gAnimationBankTarget
_0810137A:
	ldrb r6, [r0]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081013C4
	movs r1, 0x2
	adds r0, r6, 0
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _081013C4
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xC]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	adds r0, r6, 0
	bl sub_80A8924
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r0, r5, 0
	bl sub_80A6864
	ldrh r0, [r4, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	b _08101414
	.pool
_081013C4:
	ldr r4, =gBattleAnimArgs
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081013E8
	adds r0, r6, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	adds r0, r6, 0
	movs r1, 0x1
	b _081013FA
	.pool
_081013E8:
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	adds r0, r6, 0
	movs r1, 0x3
_081013FA:
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
	strh r0, [r5, 0x22]
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_80A6864
_08101414:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0xA]
	strh r0, [r5, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x32]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A656C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810135C

	thumb_func_start sub_8101440
sub_8101440: @ 8101440
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08101474
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	b _0810148E
	.pool
_08101474:
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0810148E:
	ldr r0, =sub_81014A0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101440

	thumb_func_start sub_81014A0
sub_81014A0: @ 81014A0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _081014D8
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r0, 0x1E
	subs r0, r1
	movs r1, 0x3
	bl __divsi3
	strh r0, [r4, 0x26]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	lsls r0, 18
	asrs r0, 16
	movs r1, 0x3
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_081014D8:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081014EC
	adds r0, r4, 0
	bl move_anim_8072740
_081014EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81014A0

	thumb_func_start sub_81014F4
sub_81014F4: @ 81014F4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810152C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0x1
	strh r0, [r4, 0x34]
	b _0810154A
	.pool
_0810152C:
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0810154A:
	ldr r0, =sub_8101560
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81014F4

	thumb_func_start sub_8101560
sub_8101560: @ 8101560
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x28
	bl __divsi3
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r1, 0xA
	bl __divsi3
	strh r0, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	lsls r0, 1
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x2E]
	adds r1, r0, r2
	strh r1, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081015A4
	adds r0, r4, 0
	bl move_anim_8074EE0
_081015A4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8101560

	thumb_func_start sub_81015AC
sub_81015AC: @ 81015AC
	push {lr}
	ldrh r1, [r0, 0x20]
	subs r1, 0x20
	strh r1, [r0, 0x20]
	ldrh r1, [r0, 0x22]
	subs r1, 0x20
	strh r1, [r0, 0x22]
	movs r1, 0x14
	strh r1, [r0, 0x2E]
	ldr r1, =sub_80A64B0
	str r1, [r0, 0x1C]
	ldr r1, =sub_81015D4
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81015AC

	thumb_func_start sub_81015D4
sub_81015D4: @ 81015D4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r6, [r5, 0x38]
	movs r1, 0x1
	adds r0, r1, 0
	ands r0, r6
	cmp r0, 0
	beq _081015EA
	cmp r0, 0x1
	beq _08101604
	b _0810166A
_081015EA:
	strh r1, [r5, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r5, 0x1C]
	ldr r1, =sub_81015D4
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	b _0810166A
	.pool
_08101604:
	ldrh r3, [r5, 0x24]
	ldrh r0, [r5, 0x20]
	adds r3, r0
	movs r0, 0
	strh r3, [r5, 0x20]
	ldrh r4, [r5, 0x26]
	ldrh r1, [r5, 0x22]
	adds r4, r1
	strh r4, [r5, 0x22]
	strh r0, [r5, 0x26]
	strh r0, [r5, 0x24]
	movs r0, 0x8
	strh r0, [r5, 0x2E]
	ldr r2, =gUnknown_08592CD0
	lsls r0, r6, 16
	asrs r0, 24
	lsls r0, 1
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	adds r3, r1
	strh r3, [r5, 0x32]
	adds r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r4, r0
	strh r4, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =sub_8101684
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r5, 0x38]
	adds r0, r1
	strh r0, [r5, 0x38]
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xD2
	bl PlaySE12WithPanning
_0810166A:
	ldrh r0, [r5, 0x38]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0x38]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81015D4

	thumb_func_start sub_8101684
sub_8101684: @ 8101684
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x38]
	lsls r0, 16
	asrs r0, 24
	cmp r0, 0x4
	bne _081016AC
	movs r0, 0xA
	strh r0, [r2, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r2, 0x1C]
	ldr r1, =sub_81016B8
	adds r0, r2, 0
	bl StoreSpriteCallbackInData6
	b _081016B0
	.pool
_081016AC:
	ldr r0, =sub_81015D4
	str r0, [r2, 0x1C]
_081016B0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101684

	thumb_func_start sub_81016B8
sub_81016B8: @ 81016B8
	push {r4-r7,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x6]
	cmp r1, 0
	bne _081016E0
	movs r0, 0x3
	strh r0, [r5, 0x2E]
	strh r1, [r5, 0x30]
	strh r1, [r5, 0x32]
	ldr r0, =sub_80A64B0
	str r0, [r5, 0x1C]
	ldr r1, =sub_8101774
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	b _08101760
	.pool
_081016E0:
	ldrh r0, [r5, 0x6]
	cmp r0, 0x2
	beq _08101700
	cmp r0, 0x2
	bgt _081016F0
	cmp r0, 0x1
	beq _081016F6
	b _08101714
_081016F0:
	cmp r0, 0x3
	beq _08101708
	b _08101714
_081016F6:
	ldr r6, =0x0000fff8
	adds r7, r6, 0
	b _08101718
	.pool
_08101700:
	ldr r7, =0x0000fff8
	b _08101716
	.pool
_08101708:
	movs r7, 0x8
	ldr r6, =0x0000fff8
	b _08101718
	.pool
_08101714:
	movs r7, 0x8
_08101716:
	movs r6, 0x8
_08101718:
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	movs r0, 0x6
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r7
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =sub_8101820
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_08101760:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81016B8

	thumb_func_start sub_8101774
sub_8101774: @ 8101774
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08101794
	ldrh r0, [r4, 0x30]
	adds r0, 0x3
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081017A4
	movs r0, 0x10
	b _081017A2
_08101794:
	ldrh r0, [r4, 0x30]
	subs r0, 0x3
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _081017A4
	movs r0, 0
_081017A2:
	strh r0, [r4, 0x30]
_081017A4:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80A75AC
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =0x00007fff
	bl BlendPalettes
	movs r3, 0x30
	ldrsh r0, [r4, r3]
	cmp r0, 0x10
	bne _0810180C
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	lsls r0, r1, 5
	ldr r2, =gPlttBufferUnfaded + 0x210
	adds r0, r2
	lsls r1, 4
	ldr r3, =0x00000101
	adds r2, r3, 0
	orrs r1, r2
	movs r2, 0x4
	bl LoadPalette
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xC0
	bl PlaySE12WithPanning
	b _08101814
	.pool
_0810180C:
	cmp r0, 0
	bne _08101814
	ldr r0, =sub_8101820
	str r0, [r4, 0x1C]
_08101814:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101774

	thumb_func_start sub_8101820
sub_8101820: @ 8101820
	push {lr}
	adds r2, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08101838
	movs r0, 0
	strh r0, [r2, 0x30]
	strh r0, [r2, 0x2E]
	ldr r0, =sub_8101848
	str r0, [r2, 0x1C]
_08101838:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101820

	thumb_func_start sub_8101848
sub_8101848: @ 8101848
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0810187C
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810187C:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bne _08101890
	adds r0, r4, 0
	bl move_anim_8072740
_08101890:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8101848

	thumb_func_start sub_8101898
sub_8101898: @ 8101898
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r3, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _081018BC
	ldrh r0, [r3, 0x20]
	subs r0, 0x18
	strh r0, [r3, 0x20]
	ldrh r0, [r3, 0x22]
	subs r0, 0x18
	strh r0, [r3, 0x22]
	b _0810190E
	.pool
_081018BC:
	cmp r0, 0x2
	bne _081018D8
	ldrh r0, [r3, 0x20]
	subs r0, 0x18
	strh r0, [r3, 0x20]
	ldrh r0, [r3, 0x22]
	adds r0, 0x18
	strh r0, [r3, 0x22]
	ldrb r1, [r3, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x20
	b _0810190A
_081018D8:
	cmp r0, 0x3
	bne _081018F4
	ldrh r0, [r3, 0x20]
	adds r0, 0x18
	strh r0, [r3, 0x20]
	ldrh r0, [r3, 0x22]
	subs r0, 0x18
	strh r0, [r3, 0x22]
	ldrb r1, [r3, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	b _0810190A
_081018F4:
	ldrh r0, [r3, 0x20]
	adds r0, 0x18
	strh r0, [r3, 0x20]
	ldrh r0, [r3, 0x22]
	adds r0, 0x18
	strh r0, [r3, 0x22]
	ldrb r1, [r3, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x30
_0810190A:
	orrs r0, r1
	strb r0, [r3, 0x3]
_0810190E:
	ldrh r2, [r3, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldr r1, =sub_81015AC
	str r1, [r3, 0x1C]
	adds r0, r3, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101898

	thumb_func_start sub_8101940
sub_8101940: @ 8101940
	push {lr}
	adds r3, r0, 0
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0
	strh r0, [r3, 0x2E]
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _0810197C
	cmp r0, 0x1
	bgt _0810196C
	cmp r0, 0
	beq _08101972
	b _0810198C
	.pool
_0810196C:
	cmp r0, 0x2
	beq _08101984
	b _0810198C
_08101972:
	ldr r0, =sub_8101998
	b _0810198E
	.pool
_0810197C:
	ldr r0, =sub_8101A74
	b _0810198E
	.pool
_08101984:
	ldr r0, =sub_8101AC4
	b _0810198E
	.pool
_0810198C:
	ldr r0, =sub_8101B84
_0810198E:
	str r0, [r3, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101940

	thumb_func_start sub_8101998
sub_8101998: @ 8101998
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	beq _081019B6
	movs r1, 0x2
_081019B6:
	strh r1, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	ldr r1, =gBankSpriteIds
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r4, 0x34]
	ldr r1, =sub_81019E8
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6630
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101998

	thumb_func_start sub_81019E8
sub_81019E8: @ 81019E8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r6, [r5, r0]
	cmp r6, 0
	bne _08101A24
	ldr r1, =gBankSpriteIds
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r5, 0x34]
	movs r1, 0
	bl sub_80A7270
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3A]
	ldr r2, =0xfffffd00
	adds r1, r2, 0
	cmp r0, 0
	beq _08101A20
	movs r0, 0xC0
	lsls r0, 2
	adds r1, r0, 0
_08101A20:
	strh r1, [r5, 0x36]
	strh r6, [r5, 0x38]
_08101A24:
	ldrh r0, [r5, 0x36]
	ldrh r1, [r5, 0x38]
	adds r0, r1
	strh r0, [r5, 0x38]
	ldrh r0, [r5, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r5, 0x38]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08101A5E
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =sub_8101B84
	str r0, [r5, 0x1C]
_08101A5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81019E8

	thumb_func_start sub_8101A74
sub_8101A74: @ 8101A74
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	movs r1, 0x3
	cmp r0, 0
	beq _08101A92
	movs r0, 0x3
	negs r0, r0
	adds r1, r0, 0
_08101A92:
	strh r1, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	ldr r1, =gBankSpriteIds
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r4, 0x34]
	ldr r1, =sub_8101B84
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6630
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101A74

	thumb_func_start sub_8101AC4
sub_8101AC4: @ 8101AC4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _08101ADE
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, =sub_8101AE8
	str r0, [r1, 0x1C]
_08101ADE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101AC4

	thumb_func_start sub_8101AE8
sub_8101AE8: @ 8101AE8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08101B38
	ldr r1, =gBankSpriteIds
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3A]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08101B2C
	movs r0, 0xFC
	lsls r0, 8
	strh r0, [r5, 0x36]
	movs r0, 0xC0
	lsls r0, 4
	b _08101B36
	.pool
_08101B2C:
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r5, 0x36]
	movs r0, 0xF4
	lsls r0, 8
_08101B36:
	strh r0, [r5, 0x38]
_08101B38:
	ldrh r0, [r5, 0x36]
	ldrh r1, [r5, 0x38]
	adds r0, r1
	strh r0, [r5, 0x38]
	ldrh r0, [r5, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r5, 0x38]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08101B78
	ldrh r0, [r5, 0x34]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	ldr r0, =sub_8101B84
	str r0, [r5, 0x1C]
_08101B78:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101AE8

	thumb_func_start sub_8101B84
sub_8101B84: @ 8101B84
	push {lr}
	bl move_anim_8072740
	pop {r0}
	bx r0
	thumb_func_end sub_8101B84

	thumb_func_start sub_8101B90
sub_8101B90: @ 8101B90
	movs r1, 0
	strh r1, [r0, 0x2E]
	ldr r1, =sub_8101BA0
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8101B90

	thumb_func_start sub_8101BA0
sub_8101BA0: @ 8101BA0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _08101BFA
	cmp r5, 0x1
	bgt _08101BB6
	cmp r5, 0
	beq _08101BBC
	b _08101C8E
_08101BB6:
	cmp r5, 0x2
	beq _08101C4C
	b _08101C8E
_08101BBC:
	strh r5, [r4, 0x30]
	ldr r1, =gBankSpriteIds
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r4, 0x32]
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x34]
	ldr r2, =0xfffffe00
	adds r1, r2, 0
	cmp r0, 0
	beq _08101BE4
	movs r0, 0x80
	lsls r0, 2
	adds r1, r0, 0
_08101BE4:
	strh r1, [r4, 0x36]
	strh r5, [r4, 0x38]
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_08101BFA:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x38]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08101C8E
	movs r0, 0
	strh r0, [r4, 0x30]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _08101C8E
	.pool
_08101C4C:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x38]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08101C8E
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	adds r0, r4, 0
	bl move_anim_8072740
_08101C8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8101BA0

	thumb_func_start sub_8101C94
sub_8101C94: @ 8101C94
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldr r1, =gBankSpriteIds
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0
	strh r0, [r5, 0x8]
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	strh r2, [r5, 0xA]
	strh r4, [r5, 0xC]
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r1, [r0, r3]
	cmp r1, 0
	beq _08101CE8
	cmp r1, 0x1
	beq _08101D04
	adds r0, r6, 0
	bl move_anim_task_del
	b _08101D22
	.pool
_08101CE8:
	strh r1, [r5, 0xC]
	movs r0, 0x8
	strh r0, [r5, 0xE]
	strh r1, [r5, 0x10]
	movs r0, 0x3
	strh r0, [r5, 0x12]
	cmp r2, 0
	bne _08101CFC
	negs r0, r0
	strh r0, [r5, 0x12]
_08101CFC:
	ldr r0, =sub_8101D2C
	b _08101D20
	.pool
_08101D04:
	movs r0, 0x8
	strh r0, [r5, 0xE]
	movs r0, 0xC0
	lsls r0, 3
	strh r0, [r5, 0x10]
	movs r1, 0xC0
	strh r1, [r5, 0x12]
	cmp r2, 0
	bne _08101D1E
	negs r0, r0
	strh r0, [r5, 0x10]
	negs r0, r1
	strh r0, [r5, 0x12]
_08101D1E:
	ldr r0, =sub_8101EEC
_08101D20:
	str r0, [r5]
_08101D22:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101C94

	thumb_func_start sub_8101D2C
sub_8101D2C: @ 8101D2C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _08101D46
	b _08101EE6
_08101D46:
	lsls r0, 2
	ldr r1, =_08101D58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08101D58:
	.4byte _08101D6C
	.4byte _08101D9E
	.4byte _08101DF8
	.4byte _08101E70
	.4byte _08101EB4
_08101D6C:
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r1, 0
	beq _08101D7C
	ldrh r2, [r4, 0x12]
	ldrh r3, [r4, 0x10]
	adds r2, r3
	b _08101EC2
_08101D7C:
	movs r0, 0x8
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x10]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r1, 0xC0
	cmp r0, 0
	bne _08101D92
	movs r2, 0xC0
	negs r2, r2
	adds r1, r2, 0
_08101D92:
	strh r1, [r4, 0x12]
	ldrb r0, [r4, 0x8]
	movs r1, 0
	bl sub_80A7270
	b _08101EA8
_08101D9E:
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08101DC4
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0x10]
	adds r0, r1
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x10]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x8]
	bl sub_80A73A0
	b _08101ED4
_08101DC4:
	movs r0, 0x8
	strh r0, [r4, 0xE]
	ldr r2, =gSprites
	movs r3, 0x8
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x24]
	strh r0, [r4, 0x10]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08101DEA
	movs r1, 0x2
_08101DEA:
	strh r1, [r4, 0x12]
	movs r0, 0x1
	strh r0, [r4, 0x14]
	b _08101EA8
	.pool
_08101DF8:
	ldrh r2, [r4, 0xE]
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08101E54
	ldrh r1, [r4, 0x14]
	movs r3, 0x14
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08101E12
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	b _08101EE6
_08101E12:
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08101E34
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x12]
	ldrh r2, [r4, 0x10]
	adds r1, r2
	b _08101E48
	.pool
_08101E34:
	ldr r2, =gSprites
	movs r3, 0x8
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x10]
	ldrh r2, [r4, 0x12]
	subs r1, r2
_08101E48:
	strh r1, [r0, 0x24]
	movs r0, 0x1
	strh r0, [r4, 0x14]
	b _08101ED4
	.pool
_08101E54:
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x10]
	strh r1, [r0, 0x24]
	movs r0, 0xC
	strh r0, [r4, 0xE]
	b _08101EA8
	.pool
_08101E70:
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08101E80
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _08101EE6
_08101E80:
	movs r0, 0x3
	strh r0, [r4, 0xE]
	ldr r2, =gSprites
	movs r3, 0x8
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x24]
	strh r0, [r4, 0x10]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r2, 0x8
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08101EA6
	movs r1, 0x8
_08101EA6:
	strh r1, [r4, 0x12]
_08101EA8:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	b _08101EE6
	.pool
_08101EB4:
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08101EE0
	ldrh r2, [r4, 0x12]
	ldrh r0, [r4, 0x10]
	adds r2, r0
_08101EC2:
	strh r2, [r4, 0x10]
	ldr r3, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x24]
_08101ED4:
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _08101EE6
	.pool
_08101EE0:
	adds r0, r2, 0
	bl move_anim_task_del
_08101EE6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8101D2C

	thumb_func_start sub_8101EEC
sub_8101EEC: @ 8101EEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08101F2C
	ldrh r0, [r4, 0x10]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0x10]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x8]
	bl sub_80A73A0
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _08101F38
	.pool
_08101F2C:
	ldrb r0, [r4, 0x8]
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
_08101F38:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8101EEC

	thumb_func_start sub_8101F40
sub_8101F40: @ 8101F40
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08101F5C
	ldr r4, =gAnimationBankAttacker
	b _08101F5E
	.pool
_08101F5C:
	ldr r4, =gAnimationBankTarget
_08101F5E:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x4]
	adds r0, r6
	strh r0, [r5, 0x22]
	movs r0, 0
	strh r0, [r5, 0x2E]
	strh r0, [r5, 0x30]
	ldr r1, =sub_810208C
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101F40

	thumb_func_start sub_8101FA8
sub_8101FA8: @ 8101FA8
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x0000ffd0
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r1, =sub_8102044
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101FA8

	thumb_func_start sub_8101FF0
sub_8101FF0: @ 8101FF0
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleAnimArgs
	ldr r2, =0x0000ffd0
	adds r0, r2
	ldrh r1, [r1]
	adds r0, r1
	movs r6, 0
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	strh r6, [r4, 0x2E]
	strh r6, [r4, 0x30]
	ldr r0, =sub_810208C
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8101FF0

	thumb_func_start sub_8102044
sub_8102044: @ 8102044
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0810206E
	movs r0, 0xC
	strh r0, [r4, 0x2E]
	movs r0, 0x8
	strh r0, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	ldr r1, =sub_810207C
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A653C
	str r0, [r4, 0x1C]
_0810206E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102044

	thumb_func_start sub_810207C
sub_810207C: @ 810207C
	movs r1, 0
	strh r1, [r0, 0x2E]
	strh r1, [r0, 0x30]
	ldr r1, =sub_810208C
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_810207C

	thumb_func_start sub_810208C
sub_810208C: @ 810208C
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081020D4
	movs r0, 0
	strh r0, [r3, 0x2E]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081020D4
	adds r0, r3, 0
	bl move_anim_8072740
_081020D4:
	pop {r0}
	bx r0
	thumb_func_end sub_810208C

	thumb_func_start sub_81020D8
sub_81020D8: @ 81020D8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081020F4
	ldr r4, =gAnimationBankAttacker
	b _081020F6
	.pool
_081020F4:
	ldr r4, =gAnimationBankTarget
_081020F6:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x4]
	adds r0, r6
	strh r0, [r5, 0x22]
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x6]
	strh r0, [r5, 0x30]
	ldr r0, =sub_810213C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81020D8

	thumb_func_start sub_810213C
sub_810213C: @ 810213C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x30
	ldrsh r1, [r2, r3]
	cmp r0, r1
	ble _0810215C
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldrh r0, [r2, 0x22]
	subs r0, 0x1
	strh r0, [r2, 0x22]
_0810215C:
	ldrh r0, [r2, 0x22]
	ldrh r1, [r2, 0x2E]
	subs r0, r1
	strh r0, [r2, 0x22]
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08102178
	adds r0, r2, 0
	bl move_anim_8072740
_08102178:
	pop {r0}
	bx r0
	thumb_func_end sub_810213C

	thumb_func_start sub_810217C
sub_810217C: @ 810217C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0xC
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x2E]
	movs r0, 0x2
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r5, [r4, 0x34]
	strh r5, [r4, 0x36]
	subs r0, 0x42
	bl BattleAnimGetPanControl
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x38]
	ldr r0, =sub_81021CC
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810217C

	thumb_func_start sub_81021CC
sub_81021CC: @ 81021CC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08102238
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0810221E
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0810221E
	ldrh r1, [r4, 0x38]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xC2
	bl PlaySE12WithPanning
_0810221E:
	movs r1, 0
	strh r1, [r4, 0x2E]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08102238
	strh r1, [r4, 0x32]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_08102238:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08102262
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	ble _08102262
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08102262
	adds r0, r4, 0
	bl move_anim_8072740
_08102262:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81021CC

	thumb_func_start sub_8102268
sub_8102268: @ 8102268
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081022B2
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r5, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r6, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x2]
	adds r0, r5
	strh r0, [r6, 0x22]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081022AC
	ldrh r0, [r6, 0x22]
	adds r0, 0xA
	strh r0, [r6, 0x22]
_081022AC:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
_081022B2:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081022C2
	adds r0, r6, 0
	bl move_anim_8072740
_081022C2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102268

	thumb_func_start sub_81022D4
sub_81022D4: @ 81022D4
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08102300
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xE]
	b _0810233E
	.pool
_08102300:
	cmp r0, 0x2
	bne _0810230C
	adds r0, r2, 0
	bl move_anim_task_del
	b _08102344
_0810230C:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08102344
	movs r0, 0
	strh r0, [r4, 0x8]
	ldrh r2, [r4, 0xA]
	adds r2, 0x1
	strh r2, [r4, 0xA]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08102344
_0810233E:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_08102344:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81022D4

	thumb_func_start sub_810234C
sub_810234C: @ 810234C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A6980
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_810237C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810234C

	thumb_func_start sub_810237C
sub_810237C: @ 810237C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _08102390
	subs r0, r1, 0x1
	strh r0, [r5, 0x2E]
	b _081023CC
_08102390:
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x1E
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_081023CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810237C

	thumb_func_start sub_81023E0
sub_81023E0: @ 81023E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08102428
	movs r0, 0
	strh r0, [r4, 0x8]
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08102428
	adds r0, r5, 0
	bl move_anim_task_del
_08102428:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81023E0

	thumb_func_start sub_8102434
sub_8102434: @ 8102434
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bcs _08102490
	ldr r6, =gBattleAnimArgs
	ldr r5, =gHealthBoxesIds
_08102448:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _08102464
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08102464
	adds r0, r4, r5
	ldrb r0, [r0]
	bl sub_8072984
_08102464:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _08102482
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08102482
	adds r0, r4, r5
	ldrb r0, [r0]
	bl sub_8072984
_08102482:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bcc _08102448
_08102490:
	adds r0, r7, 0
	bl move_anim_task_del
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102434

	thumb_func_start sub_81024A8
sub_81024A8: @ 81024A8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	b _081024C2
_081024B2:
	ldr r0, =gHealthBoxesIds
	adds r0, r4, r0
	ldrb r0, [r0]
	bl sub_80729D0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_081024C2:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bcc _081024B2
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81024A8

	thumb_func_start sub_81024E0
sub_81024E0: @ 81024E0
	push {r4,lr}
	adds r4, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081024F6
	movs r0, 0x30
	strh r0, [r4, 0x20]
	movs r0, 0x28
	b _081024FE
_081024F6:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	strh r1, [r4, 0x20]
	ldrh r0, [r0, 0x2]
_081024FE:
	strh r0, [r4, 0x22]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_8102528
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81024E0

	thumb_func_start sub_8102528
sub_8102528: @ 8102528
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0810253A
	adds r0, r1, 0
	bl move_anim_8072740
_0810253A:
	pop {r0}
	bx r0
	thumb_func_end sub_8102528

	thumb_func_start sub_8102540
sub_8102540: @ 8102540
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r2, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r2]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x30]
	strh r1, [r4, 0x32]
	strh r1, [r4, 0x34]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	ldr r0, =sub_8102584
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102540

	thumb_func_start sub_8102584
sub_8102584: @ 8102584
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081025AE
	movs r0, 0
	strh r0, [r1, 0x30]
	ldrh r2, [r1, 0x32]
	movs r3, 0x32
	ldrsh r0, [r1, r3]
	cmp r0, 0x77
	bgt _081025AE
	ldrh r0, [r1, 0x22]
	adds r0, 0x1
	strh r0, [r1, 0x22]
	adds r0, r2, 0x1
	strh r0, [r1, 0x32]
_081025AE:
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _081025BC
	adds r0, r1, 0
	bl move_anim_8072740
_081025BC:
	pop {r0}
	bx r0
	thumb_func_end sub_8102584

	thumb_func_start sub_81025C0
sub_81025C0: @ 81025C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	mov r8, r0
	ldr r0, =0x0000ffff
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldr r0, =gTasks
	mov r9, r0
	lsls r5, r7, 2
	adds r5, r7
	lsls r5, 3
	adds r6, r5, r0
	strh r4, [r6, 0x8]
	strh r4, [r6, 0xA]
	strh r4, [r6, 0xC]
	strh r1, [r6, 0xE]
	strh r4, [r6, 0x10]
	strh r4, [r6, 0x12]
	strh r4, [r6, 0x14]
	movs r0, 0xD
	strh r0, [r6, 0x16]
	movs r0, 0xE
	strh r0, [r6, 0x18]
	movs r0, 0xF
	strh r0, [r6, 0x1A]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80A76C4
	mov r10, r0
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	movs r0, 0x8
	add r9, r0
	add r5, r9
	adds r0, r5, 0
	adds r0, 0x1C
	adds r5, 0x1E
	adds r1, r5, 0
	mov r2, r8
	bl sub_80A8048
	ldr r0, =0x000027d2
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0x80
	lsls r4, 9
	adds r1, r4, 0
	lsls r1, r0
	mov r0, r10
	orrs r0, r1
	mov r10, r0
	ldr r0, =0x000027d3
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0
	mov r1, r10
	orrs r4, r1
	ldr r0, =0x00007fbb
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =sub_81026A8
	str r1, [r6]
	adds r0, r7, 0
	bl _call_via_r1
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81025C0

	thumb_func_start sub_81026A8
sub_81026A8: @ 81026A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _08102794
	cmp r1, 0x1
	bgt _081026D4
	cmp r1, 0
	beq _081026E2
	b _08102832
	.pool
_081026D4:
	cmp r1, 0x2
	bne _081026DA
	b _081027EC
_081026DA:
	cmp r1, 0x3
	bne _081026E0
	b _08102820
_081026E0:
	b _08102832
_081026E2:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bgt _081026F0
	b _08102832
_081026F0:
	strh r1, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _0810273C
	ldrh r0, [r4, 0x16]
	ldrh r1, [r4, 0x10]
	adds r0, r1
	strh r0, [r4, 0x10]
	ldrh r2, [r4, 0x18]
	ldrh r3, [r4, 0x12]
	adds r2, r3
	strh r2, [r4, 0x12]
	ldrh r1, [r4, 0x1A]
	ldrh r5, [r4, 0x14]
	adds r1, r5
	strh r1, [r4, 0x14]
	lsls r0, 16
	asrs r0, 19
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 16
	asrs r2, 19
	lsls r2, 16
	lsls r1, 16
	asrs r1, 19
	lsls r1, 16
	lsrs r2, 11
	orrs r0, r2
	lsrs r1, 6
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r12, r0
	b _08102746
_0810273C:
	ldr r7, =0x00007fbb
	mov r12, r7
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08102746:
	movs r2, 0x1
	movs r3, 0
	movs r1, 0
_0810274C:
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	ands r0, r2
	lsls r5, r2, 17
	adds r6, r3, 0
	adds r6, 0x10
	adds r1, 0x1
	mov r8, r1
	cmp r0, 0
	beq _08102778
	movs r1, 0x1
	ldr r2, =gPlttBufferFaded
_08102764:
	adds r0, r3, r1
	lsls r0, 1
	adds r0, r2
	mov r7, r12
	strh r7, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _08102764
_08102778:
	lsrs r2, r5, 16
	lsls r0, r6, 16
	lsrs r3, r0, 16
	mov r1, r8
	lsls r0, r1, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _0810274C
	b _08102832
	.pool
_08102794:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08102832
	movs r2, 0
	ldr r3, =gSprites
	movs r5, 0x14
	adds r5, r3
	mov r12, r5
	ldr r7, =gUnknown_08592EBC
	mov r8, r7
	ldr r6, =gUnknown_08592EEC
	movs r5, 0x1
_081027B2:
	lsls r0, r2, 4
	adds r0, r2
	lsls r1, r0, 2
	mov r7, r12
	adds r0, r1, r7
	ldr r0, [r0]
	cmp r0, r8
	beq _081027C6
	cmp r0, r6
	bne _081027CA
_081027C6:
	adds r0, r1, r3
	strh r5, [r0, 0x2E]
_081027CA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _081027B2
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08102814
	.pool
_081027EC:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _08102832
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	bl sub_80A8050
	ldr r1, =0x00007fbb
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_08102814:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08102832
	.pool
_08102820:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08102832
	adds r0, r2, 0
	bl move_anim_task_del
_08102832:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81026A8

	thumb_func_start sub_8102844
sub_8102844: @ 8102844
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bgt _08102856
	movs r0, 0x2
	strh r0, [r6, 0x4]
_08102856:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0x7F
	ble _08102862
	movs r0, 0x7F
	strh r0, [r6, 0x4]
_08102862:
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldrh r0, [r6, 0x4]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x2]
	adds r0, r6
	strh r0, [r5, 0x22]
	ldrh r1, [r5, 0x20]
	strh r1, [r5, 0x3A]
	strh r0, [r5, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081028D4
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldrh r0, [r5, 0x20]
	adds r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r4, [r5, 0x22]
	adds r4, 0x14
	strh r4, [r5, 0x22]
	lsls r0, 7
	strh r0, [r5, 0x32]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	ldr r0, =0xffffec00
	b _081028FA
	.pool
_081028D4:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810291C
	ldrh r0, [r5, 0x20]
	subs r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r4, [r5, 0x22]
	adds r4, 0x14
	strh r4, [r5, 0x22]
	lsls r0, 7
	strh r0, [r5, 0x32]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	movs r0, 0xA0
	lsls r0, 5
_081028FA:
	bl __divsi3
	strh r0, [r5, 0x34]
	lsls r4, 7
	strh r4, [r5, 0x36]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	ldr r0, =0xfffff600
	bl __divsi3
	strh r0, [r5, 0x38]
	b _08102958
	.pool
_0810291C:
	ldrh r0, [r5, 0x20]
	adds r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r4, [r5, 0x22]
	subs r4, 0x14
	strh r4, [r5, 0x22]
	lsls r0, 7
	strh r0, [r5, 0x32]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	ldr r0, =0xffffec00
	bl __divsi3
	strh r0, [r5, 0x34]
	lsls r4, 7
	strh r4, [r5, 0x36]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	movs r0, 0xA0
	lsls r0, 4
	bl __divsi3
	strh r0, [r5, 0x38]
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x30
	orrs r0, r1
	strb r0, [r5, 0x3]
_08102958:
	ldr r0, =sub_810296C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102844

	thumb_func_start sub_810296C
sub_810296C: @ 810296C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x34]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	ldrh r1, [r2, 0x38]
	ldrh r3, [r2, 0x36]
	adds r1, r3
	strh r1, [r2, 0x36]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r1, 23
	strh r1, [r2, 0x22]
	ldrh r0, [r2, 0x30]
	subs r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _081029A2
	ldrh r0, [r2, 0x3A]
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x22]
_081029A2:
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _081029B0
	adds r0, r2, 0
	bl move_anim_8072740
_081029B0:
	pop {r0}
	bx r0
	thumb_func_end sub_810296C

	thumb_func_start sub_81029B4
sub_81029B4: @ 81029B4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x8]
	ldr r0, =0x00002771
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0xA]
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	lsls r0, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r3, r0, 16
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	lsls r4, r0, 4
	movs r5, 0x1
	ldr r2, =gPlttBufferUnfaded
_08102A0C:
	adds r1, r3, r5
	lsls r1, 1
	adds r1, r2
	adds r0, r4, r5
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _08102A0C
	adds r0, r3, 0
	movs r1, 0x10
	movs r2, 0xB
	movs r3, 0
	bl BlendPalette
	movs r0, 0
	strh r0, [r6, 0xE]
	movs r5, 0
	ldr r7, =gSprites
	movs r1, 0x1C
	adds r1, r7
	mov r9, r1
	b _08102A88
	.pool
_08102A54:
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r4, r2, r7
	ldrb r1, [r6, 0xA]
	lsls r1, 4
	ldrb r3, [r4, 0x5]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r1
	strb r0, [r4, 0x5]
	movs r0, 0
	strh r0, [r4, 0x2E]
	lsls r0, r5, 7
	strh r0, [r4, 0x30]
	mov r0, r8
	strh r0, [r4, 0x32]
	add r2, r9
	ldr r0, =sub_8102B3C
	str r0, [r2]
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_08102A88:
	cmp r5, 0x1
	bhi _08102A9A
	movs r0, 0
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08102A54
_08102A9A:
	ldr r0, =sub_8102AE0
	str r0, [r6]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08102AC8
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	bl ClearGpuRegBits
	b _08102AD2
	.pool
_08102AC8:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl ClearGpuRegBits
_08102AD2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81029B4

	thumb_func_start sub_8102AE0
sub_8102AE0: @ 8102AE0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08102B32
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08102B1C
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	bl SetGpuRegBits
	b _08102B26
	.pool
_08102B1C:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl SetGpuRegBits
_08102B26:
	ldr r0, =0x00002771
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	bl move_anim_task_del
_08102B32:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102AE0

	thumb_func_start sub_8102B3C
sub_8102B3C: @ 8102B3C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08102B58
	movs r0, 0
	strh r0, [r5, 0x34]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_08102B58:
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x40
	ble _08102B80
	ldr r2, =gTasks
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0xE]
	subs r1, 0x1
	strh r1, [r0, 0xE]
	adds r0, r5, 0
	bl obj_delete_but_dont_free_vram
	b _08102BC2
	.pool
_08102B80:
	ldr r4, =gSineTable
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0x6
	bl __divsi3
	strh r0, [r5, 0x36]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xD
	bl __divsi3
	strh r0, [r5, 0x38]
	ldrh r1, [r5, 0x30]
	adds r1, r0
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r5, 0x30]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, 0x24]
_08102BC2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102B3C

	thumb_func_start sub_8102BCC
sub_8102BCC: @ 8102BCC
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =move_anim_8072740
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102BCC

	thumb_func_start sub_8102BE8
sub_8102BE8: @ 8102BE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r4, =gUnknown_08593020
	ldrh r0, [r4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	beq _08102C2C
	lsls r0, r3, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r3, r0, 16
	movs r2, 0x1
	ldr r5, =gPlttBufferFaded
_08102C14:
	adds r1, r3, r2
	lsls r1, 1
	adds r1, r5
	lsls r0, r2, 1
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _08102C14
_08102C2C:
	movs r4, 0x1
	ldr r0, =gUnknown_08593020
	mov r8, r0
_08102C32:
	lsls r0, r4, 1
	adds r0, r4
	lsls r5, r0, 2
	mov r1, r8
	adds r0, r5, r1
	ldrh r0, [r0]
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, 0x1
	mov r12, r4
	cmp r3, 0xFF
	beq _08102C7A
	lsls r0, r3, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r3, r0, 16
	movs r2, 0x1
	ldr r7, =gPlttBufferFaded
	ldr r6, =gUnknown_08593020
	adds r4, r5, 0
_08102C60:
	adds r1, r3, r2
	lsls r1, 1
	adds r1, r7
	lsls r0, r2, 1
	adds r0, r4
	adds r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _08102C60
_08102C7A:
	mov r1, r12
	lsls r0, r1, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _08102C32
	mov r0, r9
	bl move_anim_task_del
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102BE8

	thumb_func_start sub_8102CA0
sub_8102CA0: @ 8102CA0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0x1
	ldr r6, =gUnknown_08593020
_08102CAA:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r6
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _08102CAA
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102CA0

	thumb_func_start sub_8102CD4
sub_8102CD4: @ 8102CD4
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	bl sub_80A6838
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r2, =gUnknown_08593020
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08102D10
	lsls r2, r0, 4
	ldrb r1, [r5, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
_08102D10:
	ldrh r0, [r4, 0x2]
	movs r1, 0
	strh r0, [r5, 0x30]
	strh r1, [r5, 0x32]
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x34]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08102D34
	movs r6, 0x30
	movs r3, 0x28
	b _08102D4E
	.pool
_08102D34:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r3, r0, 24
_08102D4E:
	ldrh r0, [r5, 0x20]
	lsls r1, r0, 4
	strh r1, [r5, 0x36]
	ldrh r1, [r5, 0x22]
	lsls r2, r1, 4
	strh r2, [r5, 0x38]
	subs r0, r6, r0
	lsls r0, 16
	asrs r0, 16
	subs r1, r3, r1
	lsls r1, 16
	asrs r1, 16
	adds r2, r5, 0
	adds r2, 0x3A
	adds r3, r5, 0
	adds r3, 0x3C
	movs r4, 0x28
	str r4, [sp]
	bl sub_8102D8C
	ldr r0, =sub_8102DE4
	str r0, [r5, 0x1C]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102CD4

	thumb_func_start sub_8102D8C
sub_8102D8C: @ 8102D8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r2, 0
	mov r8, r3
	ldr r2, [sp, 0x18]
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 24
	lsrs r1, r2, 24
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	bge _08102DAE
	lsls r0, r1, 24
	negs r0, r0
	lsrs r1, r0, 24
_08102DAE:
	lsls r5, r2, 8
	lsls r1, 24
	asrs r1, 24
	adds r0, r5, 0
	bl __divsi3
	adds r4, r0, 0
	cmp r4, 0
	bne _08102DC2
	movs r4, 0x1
_08102DC2:
	adds r0, r5, 0
	adds r1, r4, 0
	bl __divsi3
	strh r0, [r7]
	lsls r0, r6, 16
	asrs r0, 8
	adds r1, r4, 0
	bl __divsi3
	mov r1, r8
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8102D8C

	thumb_func_start sub_8102DE4
sub_8102DE4: @ 8102DE4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x2E]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r1, r0, r1
	adds r0, r1, 0
	cmp r1, 0
	bge _08102E00
	adds r0, 0xFF
_08102E00:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	ldrh r1, [r4, 0x3A]
	ldrh r2, [r4, 0x36]
	adds r1, r2
	strh r1, [r4, 0x36]
	ldrh r2, [r4, 0x3C]
	ldrh r3, [r4, 0x38]
	adds r2, r3
	strh r2, [r4, 0x38]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x20]
	lsls r2, 16
	asrs r2, 20
	strh r2, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xF
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	ldrh r0, [r4, 0x20]
	adds r0, 0x10
	lsls r0, 16
	movs r1, 0x88
	lsls r1, 17
	cmp r0, r1
	bhi _08102E4E
	lsls r0, r2, 16
	asrs r1, r0, 16
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	blt _08102E4E
	cmp r1, 0x80
	ble _08102E56
_08102E4E:
	adds r0, r4, 0
	bl move_anim_8074EE0
	b _08102EA6
_08102E56:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _08102EA6
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r1
	ble _08102EA6
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08102E7E
	strh r5, [r4, 0x30]
_08102E7E:
	ldr r2, =gUnknown_08593020
	movs r3, 0x30
	ldrsh r1, [r4, r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08102EA6
	lsls r2, r0, 4
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x5]
_08102EA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102DE4

	thumb_func_start sub_8102EB0
sub_8102EB0: @ 8102EB0
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r7, =gAnimationBankAttacker
	ldrb r0, [r7]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08102ECE
	ldr r1, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x2]
_08102ECE:
	ldrb r0, [r7]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	movs r5, 0
	strh r0, [r6, 0x20]
	ldrb r0, [r7]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r6, 0x22]
	ldrb r1, [r4]
	adds r0, r6, 0
	bl StartSpriteAnim
	strh r5, [r6, 0x32]
	strh r5, [r6, 0x34]
	ldrh r0, [r6, 0x20]
	lsls r0, 4
	strh r0, [r6, 0x36]
	ldrh r0, [r6, 0x22]
	lsls r0, 4
	strh r0, [r6, 0x38]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	lsls r0, 4
	movs r1, 0x5
	bl __divsi3
	strh r0, [r6, 0x3A]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	lsls r0, 7
	movs r1, 0x5
	bl __divsi3
	strh r0, [r6, 0x3C]
	ldr r0, =sub_8102F40
	str r0, [r6, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102EB0

	thumb_func_start sub_8102F40
sub_8102F40: @ 8102F40
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	strh r0, [r4, 0x36]
	ldrh r1, [r4, 0x3C]
	ldrh r2, [r4, 0x38]
	adds r1, r2
	strh r1, [r4, 0x38]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	ble _08102F9E
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08102F9E
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x12
	bl Cos
	strh r0, [r4, 0x24]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0x12
	bl Sin
	strh r0, [r4, 0x26]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08102F9E
	movs r0, 0x1
	strh r0, [r4, 0x34]
_08102F9E:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x30
	bne _08102FB2
	adds r0, r4, 0
	bl move_anim_8074EE0
_08102FB2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8102F40

	thumb_func_start sub_8102FB8
sub_8102FB8: @ 8102FB8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _08102FDC
	ldrb r0, [r5, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r5, 0x3]
	movs r6, 0x10
	b _08102FDE
	.pool
_08102FDC:
	ldr r6, =0x0000fff0
_08102FDE:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x8
	strh r0, [r5, 0x22]
	movs r0, 0x8
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8102FB8

	thumb_func_start sub_8103028
sub_8103028: @ 8103028
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldrh r0, [r4, 0x22]
	adds r0, 0x8
	strh r0, [r4, 0x22]
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x2]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r2, =gUnknown_08593020
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08103068
	lsls r2, r0, 4
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x5]
_08103068:
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x20
	cmp r0, 0
	bne _08103074
	ldr r2, =0x0000ffe0
_08103074:
	movs r0, 0x28
	strh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x20]
	strh r1, [r4, 0x30]
	lsls r0, r2, 16
	asrs r0, 16
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	subs r0, 0x28
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x38]
	ldr r0, =sub_81030B0
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103028

	thumb_func_start sub_81030B0
sub_81030B0: @ 81030B0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _08103100
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r2, [r4, 0x24]
	movs r3, 0x24
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bge _081030DC
	lsls r0, r1, 16
	negs r0, r0
	lsrs r1, r0, 16
_081030DC:
	lsls r0, r1, 16
	asrs r0, 16
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	ldrh r3, [r4, 0x26]
	adds r0, r3
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _08103106
_08103100:
	adds r0, r4, 0
	bl move_anim_8072740
_08103106:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81030B0

	thumb_func_start sub_810310C
sub_810310C: @ 810310C
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810312C
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	adds r0, 0x8
	b _08103136
_0810312C:
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	subs r0, 0x8
_08103136:
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08103158
	adds r0, 0x3
_08103158:
	asrs r0, 2
	subs r0, r4, r0
	strh r0, [r6, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810310C

	thumb_func_start sub_8103164
sub_8103164: @ 8103164
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08103180
	ldr r0, =gAnimationBankAttacker
	b _08103182
	.pool
_08103180:
	ldr r0, =gAnimationBankTarget
_08103182:
	ldrb r4, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_810310C
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x2]
	strh r0, [r5, 0x2E]
	adds r0, r1, 0x2
	strh r0, [r5, 0x30]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r1, =sub_81031D0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103164

	thumb_func_start sub_81031D0
sub_81031D0: @ 81031D0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _081031F8
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
_081031F8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81031D0

	thumb_func_start sub_8103208
sub_8103208: @ 8103208
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08103224
	ldr r0, =gAnimationBankAttacker
	b _08103226
	.pool
_08103224:
	ldr r0, =gAnimationBankTarget
_08103226:
	ldrb r0, [r0]
	adds r1, r4, 0
	bl sub_810310C
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r1, =sub_8103250
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103208

	thumb_func_start sub_8103250
sub_8103250: @ 8103250
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08103276
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
_08103276:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103250

	thumb_func_start sub_8103284
sub_8103284: @ 8103284
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081032A0
	ldr r0, =gAnimationBankAttacker
	b _081032A2
	.pool
_081032A0:
	ldr r0, =gAnimationBankTarget
_081032A2:
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	strh r0, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bgt _081032CA
	movs r0, 0xA
	strh r0, [r4, 0x22]
_081032CA:
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	strh r6, [r4, 0x30]
	adds r1, r4, 0
	adds r1, 0x43
	ldrb r0, [r1]
	strh r0, [r4, 0x32]
	ldrb r0, [r1]
	adds r0, 0x4
	strh r0, [r4, 0x34]
	strh r6, [r4, 0x36]
	ldr r1, =sub_8103300
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103284

	thumb_func_start sub_8103300
sub_8103300: @ 8103300
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x36]
	adds r0, 0x1
	strh r0, [r1, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _08103316
	ldr r0, =sub_8103320
	str r0, [r1, 0x1C]
_08103316:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103300

	thumb_func_start sub_8103320
sub_8103320: @ 8103320
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0x4
	strh r1, [r2, 0x30]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFE
	ble _08103352
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _0810334C
	strh r0, [r2, 0x24]
	ldr r0, =sub_8103250
	str r0, [r2, 0x1C]
	b _08103388
	.pool
_0810334C:
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r2, 0x30]
_08103352:
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r0, 0x4F
	ble _08103362
	ldrh r0, [r2, 0x34]
	adds r1, r2, 0
	adds r1, 0x43
	strb r0, [r1]
_08103362:
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	cmp r0, 0x9F
	ble _08103372
	ldrh r0, [r2, 0x32]
	adds r1, r2, 0
	adds r1, 0x43
	strb r0, [r1]
_08103372:
	ldr r1, =gSineTable
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	asrs r1, r0, 1
	adds r0, r1
	strh r0, [r2, 0x24]
_08103388:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103320

	thumb_func_start sub_8103390
sub_8103390: @ 8103390
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081033AC
	ldr r0, =gAnimationBankAttacker
	b _081033AE
	.pool
_081033AC:
	ldr r0, =gAnimationBankTarget
_081033AE:
	ldrb r4, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_810310C
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _081033D4
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnim
	movs r0, 0x2
	b _081033DE
	.pool
_081033D4:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	movs r0, 0x3
_081033DE:
	strh r0, [r5, 0x2E]
	ldr r0, =sub_81033F0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103390

	thumb_func_start sub_81033F0
sub_81033F0: @ 81033F0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	ble _0810341E
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r1, =sub_810342C
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
_0810341E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81033F0

	thumb_func_start sub_810342C
sub_810342C: @ 810342C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _08103444
	adds r0, r1, 0
	bl move_anim_8072740
_08103444:
	pop {r0}
	bx r0
	thumb_func_end sub_810342C

	thumb_func_start sub_8103448
sub_8103448: @ 8103448
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x34]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x36]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A6450
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103448

	thumb_func_start sub_8103498
sub_8103498: @ 8103498
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081034B4
	ldr r0, =gAnimationBankAttacker
	b _081034B6
	.pool
_081034B4:
	ldr r0, =gAnimationBankTarget
_081034B6:
	ldrb r0, [r0]
	adds r1, r4, 0
	bl sub_810310C
	movs r0, 0
	strh r0, [r4, 0x2E]
	strh r0, [r4, 0x30]
	ldr r0, =sub_81034D8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103498

	thumb_func_start sub_81034D8
sub_81034D8: @ 81034D8
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0810350A
	cmp r0, 0x1
	bgt _081034EE
	cmp r0, 0
	beq _081034F4
	b _08103538
_081034EE:
	cmp r0, 0x2
	beq _08103524
	b _08103538
_081034F4:
	ldrh r0, [r1, 0x26]
	subs r0, 0x3
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _08103538
	b _0810351C
_0810350A:
	ldrh r0, [r1, 0x26]
	adds r0, 0x3
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _08103538
_0810351C:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _08103538
_08103524:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08103538
	adds r0, r1, 0
	bl move_anim_8072740
_08103538:
	pop {r0}
	bx r0
	thumb_func_end sub_81034D8

	thumb_func_start sub_810353C
sub_810353C: @ 810353C
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, =gSprites
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r4, 0x30]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x30]
	movs r0, 0x2E
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _0810357A
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x24]
	adds r0, r4, 0
	bl move_anim_8074EE0
_0810357A:
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810353C

	thumb_func_start sub_810358C
sub_810358C: @ 810358C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r6, [r0]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081035E4
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r5, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r5, 0x20]
	adds r1, r0, 0
	b _081035EE
	.pool
_081035E4:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	strh r0, [r5, 0x20]
_081035EE:
	ldrh r0, [r1, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	strh r6, [r5, 0x32]
	ldr r0, =sub_810353C
	str r0, [r5, 0x1C]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810358C

	thumb_func_start sub_8103620
sub_8103620: @ 8103620
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x38]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_8103658
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103620

	thumb_func_start sub_8103658
sub_8103658: @ 8103658
	push {lr}
	ldrh r1, [r0, 0x30]
	strh r1, [r0, 0x2E]
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x32]
	ldrh r1, [r0, 0x22]
	adds r1, 0xF
	strh r1, [r0, 0x36]
	ldr r1, =sub_80A6EEC
	str r1, [r0, 0x1C]
	ldr r1, =sub_8103680
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103658

	thumb_func_start sub_8103680
sub_8103680: @ 8103680
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x38]
	movs r3, 0x38
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08103696
	adds r0, r1, 0
	bl move_anim_8072740
	b _0810369A
_08103696:
	subs r0, r2, 0x1
	strh r0, [r1, 0x38]
_0810369A:
	pop {r0}
	bx r0
	thumb_func_end sub_8103680

	thumb_func_start sub_81036A0
sub_81036A0: @ 81036A0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A7270
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81036DC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81036A0

	thumb_func_start sub_81036DC
sub_81036DC: @ 81036DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r1, r0, r1
	ldrb r4, [r1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08103718
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	negs r0, r0
	lsls r0, 16
	lsrs r3, r0, 16
	adds r6, r2, 0
	b _08103726
	.pool
_08103718:
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	adds r0, r2
	ldrh r3, [r0, 0x8]
	adds r6, r1, 0
_08103726:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, 0
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08103760
	ldrh r0, [r1, 0x8]
	adds r0, 0xB0
	strh r0, [r1, 0x8]
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x26]
	adds r1, 0x1
	b _0810378A
	.pool
_08103760:
	cmp r0, 0x1
	bne _08103776
	ldrh r0, [r1, 0xE]
	adds r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	bne _081037D0
	movs r0, 0x2
	b _081037CE
_08103776:
	ldrh r0, [r1, 0x8]
	subs r0, 0xB0
	strh r0, [r1, 0x8]
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x26]
	subs r1, 0x1
_0810378A:
	strh r1, [r0, 0x26]
	adds r0, r4, 0
	bl sub_80A73A0
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r2, [r1, r3]
	movs r0, 0xF2
	lsls r0, 4
	cmp r2, r0
	beq _081037AA
	cmp r2, 0
	bne _081037D0
_081037AA:
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0x2
	bne _081037CC
	adds r0, r4, 0
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
	b _081037D0
	.pool
_081037CC:
	adds r0, r2, 0x1
_081037CE:
	strh r0, [r1, 0xA]
_081037D0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81036DC

	thumb_func_start sub_81037D8
sub_81037D8: @ 81037D8
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08103804
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r4, 0x20]
	adds r5, r0, 0
	b _08103810
	.pool
_08103804:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	adds r5, r1, 0
_08103810:
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810384C
	adds r3, r4, 0
	adds r3, 0x3F
	ldrb r0, [r3]
	movs r1, 0x1
	adds r2, r0, 0
	orrs r2, r1
	strb r2, [r3]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08103860
	movs r0, 0x2
	orrs r2, r0
	strb r2, [r3]
	b _08103860
	.pool
_0810384C:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _08103860
	adds r2, r4, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
_08103860:
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81037D8

	thumb_func_start sub_810387C
sub_810387C: @ 810387C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	ldr r1, =sub_81038A0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810387C

	thumb_func_start sub_81038A0
sub_81038A0: @ 81038A0
	push {lr}
	movs r1, 0x6
	strh r1, [r0, 0x2E]
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x32]
	ldrh r1, [r0, 0x22]
	subs r1, 0x20
	strh r1, [r0, 0x36]
	ldr r1, =sub_80A6EEC
	str r1, [r0, 0x1C]
	ldr r1, =move_anim_8072740
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81038A0

	thumb_func_start sub_81038C8
sub_81038C8: @ 81038C8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081038EC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	b _0810390E
	.pool
_081038EC:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810390E
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r1, 0x6]
_0810390E:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r6, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r6, 0x6]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	ldrh r1, [r5, 0x20]
	mov r2, r8
	lsls r0, r2, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r5, 0x22]
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 24
	adds r0, r1
	lsrs r4, r0, 16
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08103980
	ldr r2, =0xffffa000
	adds r0, r4, r2
	lsls r0, 16
	lsrs r4, r0, 16
_08103980:
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	mov r0, r8
	strh r0, [r5, 0x32]
	strh r7, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81038C8

	thumb_func_start sub_81039CC
sub_81039CC: @ 81039CC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r3, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _081039F6
	ldr r2, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0xA]
	subs r1, 0x1
	strh r1, [r0, 0xA]
	adds r0, r3, 0
	bl DestroySprite
_081039F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81039CC

	thumb_func_start sub_8103A00
sub_8103A00: @ 8103A00
	push {r4,lr}
	adds r2, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r3, 0x2E
	ldrsh r1, [r2, r3]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08103A34
	ldrh r0, [r2, 0x34]
	ldrh r1, [r2, 0x38]
	adds r0, r1
	strh r0, [r2, 0x38]
	ldrh r0, [r2, 0x36]
	ldrh r3, [r2, 0x3A]
	adds r0, r3
	b _08103A42
	.pool
_08103A34:
	ldrh r0, [r2, 0x38]
	ldrh r1, [r2, 0x34]
	subs r0, r1
	strh r0, [r2, 0x38]
	ldrh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x36]
	subs r0, r1
_08103A42:
	strh r0, [r2, 0x3A]
	ldrh r0, [r2, 0x38]
	ldrh r1, [r2, 0x30]
	adds r3, r0, r1
	strh r3, [r2, 0x30]
	ldrh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	ldrh r1, [r4, 0x16]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08103A66
	lsls r0, r3, 16
	lsrs r0, 24
	negs r0, r0
	b _08103A6A
_08103A66:
	lsls r0, r3, 16
	lsrs r0, 24
_08103A6A:
	strh r0, [r2, 0x24]
	ldrh r1, [r4, 0x18]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08103A7E
	ldrh r0, [r2, 0x32]
	lsrs r0, 8
	negs r0, r0
	b _08103A82
_08103A7E:
	ldrh r0, [r2, 0x32]
	lsrs r0, 8
_08103A82:
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r2, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _08103A98
	movs r0, 0x1E
	strh r0, [r2, 0x2E]
	ldr r0, =sub_81039CC
	str r0, [r2, 0x1C]
_08103A98:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103A00

	thumb_func_start sub_8103AA4
sub_8103AA4: @ 8103AA4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r0, 0x3C
	ldrsh r1, [r7, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrh r2, [r6, 0x16]
	movs r1, 0x2
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	ldrh r3, [r7, 0x30]
	adds r2, r0, r3
	strh r2, [r7, 0x30]
	ldrh r0, [r6, 0x18]
	ands r1, r0
	ldrh r0, [r7, 0x32]
	adds r1, r0
	strh r1, [r7, 0x32]
	ldrh r1, [r6, 0x16]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08103AEC
	lsls r0, r2, 16
	lsrs r0, 24
	negs r0, r0
	b _08103AF0
	.pool
_08103AEC:
	lsls r0, r2, 16
	lsrs r0, 24
_08103AF0:
	strh r0, [r7, 0x24]
	ldrh r1, [r6, 0x18]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08103B04
	ldrh r0, [r7, 0x32]
	lsrs r0, 8
	negs r0, r0
	b _08103B08
_08103B04:
	ldrh r0, [r7, 0x32]
	lsrs r0, 8
_08103B08:
	strh r0, [r7, 0x26]
	ldrh r0, [r7, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r7, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _08103BD4
	movs r4, 0
	movs r0, 0x8
	strh r0, [r7, 0x2E]
	movs r0, 0x4
	strh r0, [r6, 0x12]
	movs r0, 0x80
	lsls r0, 5
	bl sub_8151624
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r7, 0x24]
	ldrh r1, [r7, 0x20]
	adds r2, r0, r1
	strh r2, [r7, 0x20]
	ldrh r0, [r7, 0x26]
	ldrh r3, [r7, 0x22]
	adds r0, r3
	strh r0, [r7, 0x22]
	strh r4, [r7, 0x26]
	strh r4, [r7, 0x24]
	ldrh r3, [r6, 0x1E]
	movs r0, 0x1E
	ldrsh r1, [r6, r0]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	blt _08103B52
	subs r0, r3, r2
	b _08103B54
_08103B52:
	subs r0, r2, r3
_08103B54:
	lsls r0, 24
	lsrs r4, r0, 16
	ldrh r3, [r6, 0x20]
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	ldrh r2, [r7, 0x22]
	movs r6, 0x22
	ldrsh r0, [r7, r6]
	cmp r1, r0
	blt _08103B6C
	subs r0, r3, r2
	b _08103B6E
_08103B6C:
	subs r0, r2, r3
_08103B6E:
	lsls r0, 24
	lsrs r0, 16
	mov r8, r0
	movs r0, 0
	strh r0, [r7, 0x32]
	strh r0, [r7, 0x30]
	strh r0, [r7, 0x3A]
	strh r0, [r7, 0x38]
	lsls r0, r4, 16
	asrs r0, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r5, 0
	bl sub_8151534
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r6, 0
	bl sub_8151624
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8151534
	strh r0, [r7, 0x34]
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	adds r1, r5, 0
	bl sub_8151534
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r6, 0
	bl sub_8151624
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8151534
	strh r0, [r7, 0x36]
	ldr r0, =sub_8103A00
	str r0, [r7, 0x1C]
_08103BD4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103AA4

	thumb_func_start sub_8103BE4
sub_8103BE4: @ 8103BE4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08103C02
	adds r0, r2, 0
	bl move_anim_task_del
_08103C02:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103BE4

	thumb_func_start sub_8103C0C
sub_8103C0C: @ 8103C0C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x8]
	subs r1, r0, 0x1
	strh r1, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bgt _08103CE0
	ldr r0, =gUnknown_085933B0
	movs r2, 0x1A
	ldrsh r1, [r5, r2]
	movs r3, 0x1C
	ldrsh r2, [r5, r3]
	ldrb r3, [r5, 0xC]
	ldrb r4, [r5, 0xA]
	subs r3, r4
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r0, 4
	add r0, r12
	lsls r0, 2
	ldr r1, =gSprites
	adds r6, r0, r1
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08103C6C
	cmp r0, 0x2
	beq _08103C82
	b _08103C90
	.pool
_08103C6C:
	ldrb r2, [r6, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x18
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x57
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x3]
	b _08103C90
_08103C82:
	ldrb r0, [r6, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r6, 0x3]
_08103C90:
	ldr r3, =gTasks
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 3
	adds r4, r2, r3
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0x14]
	subs r0, r1
	strh r0, [r6, 0x2E]
	strh r7, [r6, 0x3C]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	adds r0, 0xD
	lsls r0, 1
	adds r0, r2
	adds r3, 0x8
	adds r0, r3
	mov r2, r12
	strh r2, [r0]
	ldrh r0, [r4, 0xE]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0x3F
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x9A
	bl PlaySE12WithPanning
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0x2
	ble _08103CE0
	ldr r0, =sub_8103BE4
	str r0, [r4]
_08103CE0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103C0C

	thumb_func_start sub_8103CF0
sub_8103CF0: @ 8103CF0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	mov r9, r0
	movs r5, 0
	mov r0, sp
	mov r1, r9
	strh r1, [r0]
	mov r4, sp
	adds r4, 0x2
	strh r1, [r4]
	bl IsContest
	lsls r0, 24
	mov r10, r4
	cmp r0, 0
	beq _08103D5C
	ldr r1, =gTasks
	lsls r2, r7, 2
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x10]
	ldr r3, =gBattleAnimArgs
	ldrh r0, [r3]
	negs r0, r0
	strh r0, [r3]
	ldrh r1, [r3, 0x4]
	movs r0, 0x1
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _08103D54
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strh r0, [r3, 0x4]
	b _08103DB6
	.pool
_08103D54:
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r3, 0x4]
	b _08103DB6
_08103D5C:
	ldr r1, =gBanksBySide
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r7, 2
	mov r8, r2
	cmp r0, 0
	bne _08103DB6
	ldr r1, =gTasks
	adds r0, r2, r7
	lsls r0, 3
	adds r0, r1
	strh r3, [r0, 0x10]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	negs r0, r0
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	negs r0, r0
	strh r0, [r2, 0x2]
	ldrh r1, [r2, 0x4]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08103DB0
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	b _08103DB4
	.pool
_08103DB0:
	movs r0, 0x1
	orrs r0, r1
_08103DB4:
	strh r0, [r2, 0x4]
_08103DB6:
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	ldr r1, =gTasks
	mov r3, r8
	adds r4, r3, r7
	lsls r4, 3
	adds r4, r1
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1A]
	adds r6, r0, 0
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	mov r9, r0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08103E20
	ldr r4, =gAnimationBankTarget
	ldrb r1, [r4]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _08103E20
	ldrb r0, [r4]
	movs r1, 0
	mov r2, sp
	mov r3, r10
	bl sub_80A8924
	b _08103E42
	.pool
_08103E20:
	mov r5, sp
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r1, r10
	strh r0, [r1]
_08103E42:
	mov r4, sp
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	mov r2, sp
	ldr r3, =gBattleAnimArgs
	ldrh r0, [r3]
	ldrh r2, [r2]
	adds r0, r2
	strh r0, [r1, 0x1E]
	strh r0, [r4]
	ldrh r0, [r3, 0x2]
	mov r3, r10
	ldrh r3, [r3]
	adds r0, r3
	strh r0, [r1, 0x20]
	mov r1, r10
	strh r0, [r1]
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0
	cmp r0, r1
	blt _08103E88
	subs r0, r2, r1
	b _08103E8A
	.pool
_08103E88:
	subs r0, r1, r2
_08103E8A:
	lsls r0, 16
	lsrs r0, 16
	lsls r4, r0, 16
	asrs r4, 16
	ldr r5, =gBattleAnimArgs
	ldrh r1, [r5, 0x4]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	lsls r0, 16
	asrs r0, 16
	bl sub_8151624
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8151534
	ldr r2, =gTasks
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 3
	adds r6, r1, r2
	strh r0, [r6, 0x12]
	movs r1, 0x12
	ldrsh r0, [r6, r1]
	movs r1, 0x80
	bl sub_8151534
	strh r0, [r6, 0x14]
	ldrh r0, [r5, 0x4]
	strh r0, [r6, 0x16]
	mov r2, r10
	ldrh r1, [r2]
	movs r3, 0
	ldrsh r0, [r2, r3]
	mov r4, r9
	cmp r0, r4
	blt _08103F08
	subs r4, r1, r4
	lsls r4, 16
	asrs r4, 16
	movs r1, 0x12
	ldrsh r0, [r6, r1]
	bl sub_8151624
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8151534
	movs r1, 0x2
	negs r1, r1
	ands r1, r0
	strh r1, [r6, 0x18]
	b _08103F28
	.pool
_08103F08:
	subs r4, r1
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x12
	ldrsh r0, [r6, r2]
	bl sub_8151624
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8151534
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r6, 0x18]
_08103F28:
	ldr r1, =gTasks
	mov r3, r8
	adds r0, r3, r7
	lsls r0, 3
	adds r5, r0, r1
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0xE]
	ldrh r1, [r4, 0x8]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08103F78
	movs r0, 0x80
	eors r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _08103FA0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0000ffc0
	adds r1, r2, 0
	ldrh r4, [r4, 0x8]
	adds r1, r4
	adds r0, r1
	b _08103FB0
	.pool
_08103F78:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _08103FA0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0x0000ffc0
	adds r1, r3, 0
	ldrh r4, [r4, 0x8]
	adds r1, r4
	adds r0, r1
	b _08103FB0
	.pool
_08103FA0:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x8]
	subs r0, r1
_08103FB0:
	strh r0, [r5, 0xC]
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0x2
	bgt _08103FC8
	movs r0, 0x3
	strh r0, [r1, 0xC]
_08103FC8:
	ldr r0, =sub_8103C0C
	str r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103CF0

	thumb_func_start sub_8103FE8
sub_8103FE8: @ 8103FE8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r0, =gUnknown_085934A0
	ldrh r0, [r0, 0x2]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4, 0x2E]
	ldr r0, =sub_8104018
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8103FE8

	thumb_func_start sub_8104018
sub_8104018: @ 8104018
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0810407C
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r5, [r4, 0x2E]
	ldr r1, =gPlttBufferFaded
	adds r0, r5, 0
	adds r0, 0x8
	lsls r0, 1
	adds r0, r1
	ldrh r7, [r0]
	adds r6, r1, 0
	adds r1, r5, 0
	adds r1, 0x9
	lsls r0, r5, 1
	adds r0, r6
	adds r2, r0, 0
	adds r2, 0x10
	movs r3, 0x7
	lsls r1, 1
	adds r1, r6
_08104050:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08104050
	adds r0, r5, 0
	adds r0, 0xF
	lsls r0, 1
	adds r0, r6
	strh r7, [r0]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	bne _0810407C
	adds r0, r4, 0
	bl move_anim_8072740
_0810407C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104018

	thumb_func_start sub_8104088
sub_8104088: @ 8104088
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	adds r0, r1
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081040CC
	ldrh r0, [r4, 0x4]
	negs r0, r0
	strh r0, [r4, 0x4]
_081040CC:
	lsls r0, r6, 16
	asrs r0, 16
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	ldrh r1, [r5, 0x20]
	lsrs r6, r0, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r5, 0x22]
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x2E]
	strh r6, [r5, 0x32]
	strh r7, [r5, 0x36]
	ldr r0, =sub_80A7000
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104088

	thumb_func_start sub_810413C
sub_810413C: @ 810413C
	ldr r1, =0x0000fff0
	strh r1, [r0, 0x32]
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldr r1, =sub_8104154
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_810413C

	thumb_func_start sub_8104154
sub_8104154: @ 8104154
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x80
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08104178
	ldrh r0, [r4, 0x24]
	negs r0, r0
	strh r0, [r4, 0x24]
_08104178:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x5
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7E
	ble _081041B8
	movs r0, 0
	strh r0, [r4, 0x30]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _081041B8
	adds r0, r4, 0
	bl move_anim_8072740
_081041B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104154

	thumb_func_start sub_81041C4
sub_81041C4: @ 81041C4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =sub_810421C
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81041C4

	thumb_func_start sub_810421C
sub_810421C: @ 810421C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xA6
	bl PlaySE12WithPanning
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	movs r2, 0
	movs r1, 0x7
	adds r0, r4, 0
	adds r0, 0x3C
_08104250:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08104250
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x7
	ands r0, r1
	ldr r2, =0x0000fff4
	adds r1, r2, 0
	subs r1, r0
	strh r1, [r4, 0x3A]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA0
	bl __umodsi3
	adds r0, 0xA0
	strh r0, [r4, 0x3C]
	ldr r0, =sub_81042A0
	str r0, [r4, 0x1C]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810421C

	thumb_func_start sub_81042A0
sub_81042A0: @ 81042A0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	ldrh r2, [r4, 0x2E]
	adds r0, r1, r2
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r2, r0, 24
	strh r2, [r4, 0x24]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081042BE
	negs r0, r2
	strh r0, [r4, 0x24]
_081042BE:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x8
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7E
	ble _081042FE
	movs r0, 0
	strh r0, [r4, 0x30]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _081042FE
	adds r0, r4, 0
	bl move_anim_8072740
_081042FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81042A0

	thumb_func_start sub_8104304
sub_8104304: @ 8104304
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08104322
	ldrh r0, [r4, 0x22]
	adds r0, 0x10
	strh r0, [r4, 0x22]
_08104322:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0xC]
	strh r0, [r4, 0x34]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A62EC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104304

	thumb_func_start sub_8104364
sub_8104364: @ 8104364
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	movs r7, 0x20
	ldr r4, =0x0000ffe0
	movs r0, 0x10
	mov r8, r0
	ldr r6, =0x0000fff0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08104390
	adds r7, r4, 0
	movs r4, 0x20
	mov r8, r6
	movs r6, 0x10
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_08104390:
	lsls r0, r7, 16
	asrs r0, 16
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x20]
	lsls r0, r4, 16
	asrs r0, 16
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	movs r0, 0x6
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	add r0, r8
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =sub_81043F8
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104364

	thumb_func_start sub_81043F8
sub_81043F8: @ 81043F8
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810440E
	adds r0, r2, 0
	bl move_anim_8072740
_0810440E:
	pop {r0}
	bx r0
	thumb_func_end sub_81043F8

	thumb_func_start sub_8104414
sub_8104414: @ 8104414
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0x20
	mov r8, r0
	ldr r4, =0x0000ffe0
	movs r2, 0x10
	mov r9, r2
	ldr r6, =0x0000fff0
	ldr r7, =gBattleAnimArgs
	ldrh r1, [r7]
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r0, 0
	beq _08104448
	mov r8, r4
	movs r4, 0x20
	mov r9, r6
	movs r6, 0x10
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
_08104448:
	mov r0, r8
	lsls r1, r0, 16
	asrs r1, 16
	ldrh r2, [r5, 0x20]
	adds r1, r2
	strh r1, [r5, 0x20]
	lsls r0, r4, 16
	asrs r0, 16
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	movs r0, 0x6
	strh r0, [r5, 0x2E]
	strh r1, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	add r0, r9
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldrh r0, [r7]
	strh r0, [r5, 0x38]
	ldrh r0, [r5, 0x2E]
	strh r0, [r5, 0x3A]
	ldr r0, =sub_81044BC
	str r0, [r5, 0x1C]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104414

	thumb_func_start sub_81044BC
sub_81044BC: @ 81044BC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _08104520
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08104520
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r2, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0x2
	strh r0, [r4, 0x24]
	ldr r0, =0x0000fffe
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	eors r0, r1
	strh r0, [r4, 0x32]
	strh r2, [r4, 0x36]
	strh r2, [r4, 0x34]
	ldr r0, =sub_8104530
	str r0, [r4, 0x1C]
_08104520:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81044BC

	thumb_func_start sub_8104530
sub_8104530: @ 8104530
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08104548
	ldrh r0, [r4, 0x24]
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	negs r0, r0
	strh r0, [r4, 0x26]
_08104548:
	ldrh r0, [r4, 0x34]
	movs r1, 0x1
	eors r0, r1
	movs r1, 0
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _0810458A
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x36]
	strh r1, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	movs r1, 0x1
	eors r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_8104594
	str r0, [r4, 0x1C]
_0810458A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104530

	thumb_func_start sub_8104594
sub_8104594: @ 8104594
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _081045A8
	adds r0, r4, 0
	bl move_anim_8072740
_081045A8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8104594

	thumb_func_start sub_81045B0
sub_81045B0: @ 81045B0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A7270
	adds r0, r4, 0
	movs r1, 0xD0
	movs r2, 0xD0
	movs r3, 0
	bl obj_id_set_rotscale
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	movs r1, 0
	bl sub_80A750C
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x50
	strh r1, [r0, 0x8]
	ldr r1, =sub_8104614
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81045B0

	thumb_func_start sub_8104614
sub_8104614: @ 8104614
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08104664
	movs r0, 0x1
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	movs r1, 0x1
	bl sub_80A750C
	adds r0, r5, 0
	bl move_anim_task_del
_08104664:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104614

	thumb_func_start sub_8104674
sub_8104674: @ 8104674
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x8]
	movs r1, 0
	bl sub_80A7270
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x10]
	strh r5, [r4, 0x12]
	strh r5, [r4, 0x14]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x16]
	ldr r0, =sub_81046CC
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104674

	thumb_func_start sub_81046CC
sub_81046CC: @ 81046CC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bls _081046E6
	b _081047F6
_081046E6:
	lsls r0, 2
	ldr r1, =_081046F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081046F8:
	.4byte _08104710
	.4byte _08104758
	.4byte _0810478E
	.4byte _08104794
	.4byte _081047A4
	.4byte _081047D8
_08104710:
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08104720
	cmp r0, 0x3
	beq _08104720
	cmp r0, 0x6
	bne _08104728
_08104720:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8104800
_08104728:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x28
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x8]
	bl sub_80A7E6C
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	bne _081047F6
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	b _081047D0
_08104758:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081047F6
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	cmp r1, 0x3
	bne _0810476E
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xA]
	b _081047F6
_0810476E:
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	movs r2, 0x80
	lsls r2, 1
	strh r2, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x8]
	bl sub_80A7E6C
	movs r0, 0x2
	strh r0, [r4, 0xA]
	b _081047F6
_0810478E:
	movs r0, 0
	strh r0, [r4, 0xA]
	b _081047F6
_08104794:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	ble _081047F6
	b _081047CC
_081047A4:
	ldrh r0, [r4, 0xC]
	adds r0, 0x2
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	subs r0, 0x50
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x8]
	bl sub_80A7E6C
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x20
	bne _081047F6
_081047CC:
	movs r0, 0
	strh r0, [r4, 0xC]
_081047D0:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _081047F6
_081047D8:
	ldrb r0, [r4, 0x8]
	bl sub_80A7344
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x26]
	adds r0, r5, 0
	bl move_anim_task_del
_081047F6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81046CC

	thumb_func_start sub_8104800
sub_8104800: @ 8104800
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _081048DA
	bl AllocOamMatrix
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xFF
	bne _08104844
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
	b _081048DA
	.pool
_08104844:
	ldr r5, =gSprites
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r4, r3, r5
	ldrb r1, [r4, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1F
	ands r6, r0
	lsls r2, r6, 1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	ldrb r0, [r7, 0x16]
	ldrb r1, [r7, 0xE]
	subs r0, r1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrh r0, [r7, 0xE]
	adds r0, 0x1
	strh r0, [r7, 0xE]
	ldrh r0, [r7, 0x14]
	adds r0, 0x1
	strh r0, [r7, 0x14]
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	mov r0, r9
	strh r0, [r4, 0x30]
	movs r0, 0x6
	strh r0, [r4, 0x32]
	adds r5, 0x1C
	adds r3, r5
	ldr r0, =sub_81048F0
	str r0, [r3]
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0x10
	ldrsh r2, [r7, r1]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrb r0, [r4, 0x1]
	movs r3, 0x4
	negs r3, r3
	ands r3, r0
	movs r0, 0x1
	orrs r3, r0
	strb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
_081048DA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104800

	thumb_func_start sub_81048F0
sub_81048F0: @ 81048F0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _0810492E
	ldr r3, =gTasks
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl obj_delete_but_dont_free_vram
_0810492E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81048F0

	thumb_func_start sub_8104938
sub_8104938: @ 8104938
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r5, =gBattleAnimArgs
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08104964
	adds r0, r2, 0
	bl move_anim_task_del
	b _0810498A
	.pool
_08104964:
	ldrb r0, [r5]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	strh r1, [r4, 0x8]
	strh r2, [r4, 0xA]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0xC]
	strh r2, [r4, 0xE]
	strh r2, [r4, 0x10]
	ldr r2, =gUnknown_085935E8
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_8104998
	str r0, [r4]
_0810498A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104938

	thumb_func_start sub_8104998
sub_8104998: @ 8104998
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _08104A00
	cmp r5, 0x1
	bgt _081049C0
	cmp r5, 0
	beq _081049CA
	b _08104AA8
	.pool
_081049C0:
	cmp r5, 0x2
	beq _08104A34
	cmp r5, 0x3
	beq _08104A64
	b _08104AA8
_081049CA:
	adds r0, r4, 0
	bl sub_80A7D34
	ldrh r2, [r4, 0x10]
	adds r2, 0x3
	strh r2, [r4, 0x10]
	ldr r3, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	adds r1, r2
	strh r1, [r0, 0x26]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _08104AA8
	strh r5, [r4, 0xE]
	b _08104A5C
	.pool
_08104A00:
	adds r0, r4, 0
	bl sub_80A7D34
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x10]
	ldrh r2, [r0, 0x26]
	adds r1, r2
	strh r1, [r0, 0x26]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _08104AA8
	movs r0, 0
	strh r0, [r4, 0xE]
	b _08104A5C
	.pool
_08104A34:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08104A5C
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x2
	strh r1, [r0, 0x26]
	ldrh r0, [r4, 0x10]
	subs r0, 0x2
	strh r0, [r4, 0x10]
	b _08104AA8
	.pool
_08104A5C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _08104AA8
_08104A64:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08104AA8
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _08104A9C
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x26]
	adds r0, r6, 0
	bl move_anim_task_del
	b _08104AA8
	.pool
_08104A9C:
	ldrb r1, [r4, 0x8]
	ldr r2, =gUnknown_085935E8
	adds r0, r4, 0
	bl sub_80A7CFC
	strh r5, [r4, 0xA]
_08104AA8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104998

	thumb_func_start sub_8104AB4
sub_8104AB4: @ 8104AB4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_08593608
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_8104AF0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104AB4

	thumb_func_start sub_8104AF0
sub_8104AF0: @ 8104AF0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _08104B10
	adds r0, r4, 0
	bl move_anim_task_del
_08104B10:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104AF0

	thumb_func_start sub_8104B1C
sub_8104B1C: @ 8104B1C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08104B50
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r4, 0x20]
	movs r0, 0x40
	b _08104B6A
	.pool
_08104B50:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x20
	strh r0, [r4, 0x20]
	ldr r0, =0x0000ffc0
_08104B6A:
	strh r0, [r4, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4, 0x22]
	movs r0, 0x34
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x32]
	strh r1, [r4, 0x34]
	strh r1, [r4, 0x36]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A656C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104B1C

	thumb_func_start sub_8104BAC
sub_8104BAC: @ 8104BAC
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08104BC8
	ldr r0, =gAnimationBankAttacker
	b _08104BCA
	.pool
_08104BC8:
	ldr r0, =gAnimationBankTarget
_08104BCA:
	ldrb r5, [r0]
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08104BE4
	ldr r1, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x2]
_08104BE4:
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x4]
	adds r0, r4
	strh r0, [r6, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bgt _08104C16
	movs r0, 0x8
	strh r0, [r6, 0x22]
_08104C16:
	ldr r1, =move_anim_8074EE0
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104BAC

	thumb_func_start sub_8104C38
sub_8104C38: @ 8104C38
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	strh r1, [r4, 0x8]
	strh r0, [r4, 0xA]
	ldr r2, =gUnknown_085936A4
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_8104C78
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104C38

	thumb_func_start sub_8104C78
sub_8104C78: @ 8104C78
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _08104C98
	adds r0, r4, 0
	bl move_anim_task_del
_08104C98:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104C78

	thumb_func_start sub_8104CA4
sub_8104CA4: @ 8104CA4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	strh r0, [r4, 0x8]
	strh r2, [r4, 0xA]
	movs r0, 0x4
	strh r0, [r4, 0xC]
	movs r0, 0x7
	strh r0, [r4, 0xE]
	movs r0, 0x3
	strh r0, [r4, 0x10]
	ldr r3, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x12]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x14]
	strh r2, [r4, 0x16]
	strh r2, [r4, 0x18]
	movs r0, 0x2
	strh r0, [r4, 0x1A]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08104D0E
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0xC]
_08104D0E:
	ldr r0, =sub_8104D28
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104CA4

	thumb_func_start sub_8104D28
sub_8104D28: @ 8104D28
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	ldrh r0, [r3, 0x16]
	adds r0, 0x1
	strh r0, [r3, 0x16]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08104D8E
	movs r0, 0
	strh r0, [r3, 0x16]
	ldrh r0, [r3, 0x18]
	adds r0, 0x1
	strh r0, [r3, 0x18]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08104D78
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0x1A]
	ldrh r2, [r0, 0x22]
	adds r1, r2
	b _08104D8C
	.pool
_08104D78:
	ldr r2, =gSprites
	movs r5, 0x8
	ldrsh r1, [r3, r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	ldrh r2, [r3, 0x1A]
	subs r1, r2
_08104D8C:
	strh r1, [r0, 0x22]
_08104D8E:
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	beq _08104DDC
	cmp r0, 0x1
	bgt _08104DA4
	cmp r0, 0
	beq _08104DAA
	b _08104E6C
	.pool
_08104DA4:
	cmp r0, 0x2
	beq _08104E0C
	b _08104E6C
_08104DAA:
	ldr r2, =gSprites
	movs r5, 0x8
	ldrsh r1, [r3, r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0xC]
	ldrh r2, [r0, 0x20]
	adds r1, r2
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0xE]
	subs r0, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08104E6C
	movs r0, 0xE
	strh r0, [r3, 0xE]
	movs r0, 0x1
	strh r0, [r3, 0xA]
	b _08104E6C
	.pool
_08104DDC:
	ldr r2, =gSprites
	movs r5, 0x8
	ldrsh r1, [r3, r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	ldrh r2, [r3, 0xC]
	subs r1, r2
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0xE]
	subs r0, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08104E6C
	movs r0, 0x7
	strh r0, [r3, 0xE]
	movs r0, 0x2
	strh r0, [r3, 0xA]
	b _08104E6C
	.pool
_08104E0C:
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0xC]
	ldrh r5, [r0, 0x20]
	adds r1, r5
	strh r1, [r0, 0x20]
	ldrh r0, [r3, 0xE]
	subs r0, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _08104E6C
	ldrh r0, [r3, 0x10]
	subs r0, 0x1
	strh r0, [r3, 0x10]
	lsls r0, 16
	cmp r0, 0
	beq _08104E48
	movs r0, 0x7
	strh r0, [r3, 0xE]
	strh r1, [r3, 0xA]
	b _08104E6C
	.pool
_08104E48:
	ldrh r1, [r3, 0x18]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08104E66
	movs r0, 0x8
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	ldrh r2, [r3, 0x1A]
	subs r1, r2
	strh r1, [r0, 0x22]
_08104E66:
	adds r0, r4, 0
	bl move_anim_task_del
_08104E6C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8104D28

	thumb_func_start sub_8104E74
sub_8104E74: @ 8104E74
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	movs r1, 0
	strh r0, [r5, 0x8]
	movs r0, 0x4
	strh r0, [r5, 0xA]
	strh r1, [r5, 0xC]
	strh r1, [r5, 0xE]
	strh r1, [r5, 0x10]
	strh r1, [r5, 0x12]
	ldrb r0, [r4]
	bl sub_80A861C
	strh r0, [r5, 0x26]
	ldrb r0, [r4]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08104ED4
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	ldr r0, =0x04000014
	b _08104EDC
	.pool
_08104ED4:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	ldr r0, =0x04000018
_08104EDC:
	str r0, [sp]
	ldrh r0, [r5, 0x8]
	adds r1, r0, 0
	subs r1, 0x40
	lsls r2, r1, 16
	lsls r0, 16
	cmp r2, r0
	bgt _08104F1A
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r4, r0
_08104EF4:
	asrs r3, r2, 16
	cmp r3, 0
	blt _08104F0C
	lsls r1, r3, 1
	adds r2, r1, r4
	ldrh r0, [r5, 0x14]
	adds r0, 0xF0
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r5, 0x14]
	adds r0, 0xF0
	strh r0, [r1]
_08104F0C:
	adds r0, r3, 0x1
	lsls r2, r0, 16
	asrs r1, r2, 16
	movs r3, 0x8
	ldrsh r0, [r5, r3]
	cmp r1, r0
	ble _08104EF4
_08104F1A:
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_8104F54
	str r0, [r5]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104E74

	thumb_func_start sub_8104F54
sub_8104F54: @ 8104F54
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r1, 0x10
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08104F78
	cmp r0, 0x1
	beq _08104F8E
	b _0810500E
	.pool
_08104F78:
	ldrh r0, [r3, 0x12]
	adds r0, 0x1
	strh r0, [r3, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _0810500E
	ldrh r0, [r3, 0x10]
	adds r0, 0x1
	strh r0, [r3, 0x10]
	b _0810500E
_08104F8E:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0810500E
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r1, [r3, 0xE]
	movs r0, 0x3
	ands r0, r1
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x8]
	subs r0, r1
	strh r0, [r3, 0x12]
	movs r2, 0xC
	ldrsh r1, [r3, r2]
	cmp r1, 0x1
	beq _08104FC4
	cmp r1, 0x1
	ble _08104FCC
	cmp r1, 0x2
	beq _08104FC8
	cmp r1, 0x3
	beq _08104FC8
	b _08104FCC
_08104FC4:
	subs r0, 0x2
	b _08104FCA
_08104FC8:
	adds r0, 0x1
_08104FCA:
	strh r0, [r3, 0x12]
_08104FCC:
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	cmp r0, 0
	blt _08104FF0
	ldr r2, =gUnknown_02038C28
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r3, 0x14]
	strh r1, [r0]
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	lsls r0, 1
	movs r1, 0xF0
	lsls r1, 3
	adds r2, r1
	adds r0, r2
	ldrh r1, [r3, 0x14]
	strh r1, [r0]
_08104FF0:
	ldrh r0, [r3, 0xE]
	adds r0, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x26
	ldrsh r1, [r3, r2]
	cmp r0, r1
	blt _0810500E
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	adds r0, r4, 0
	bl move_anim_task_del
_0810500E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8104F54

	thumb_func_start sub_810501C
sub_810501C: @ 810501C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	movs r5, 0
	strh r0, [r4, 0x20]
	ldrb r0, [r6]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x2E]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x32]
	movs r0, 0x10
	strh r0, [r4, 0x34]
	strh r5, [r4, 0x36]
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A861C
	adds r0, 0x2
	strh r0, [r4, 0x38]
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x3A]
	ldr r0, =sub_8105078
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810501C

	thumb_func_start sub_8105078
sub_8105078: @ 8105078
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _081050DC
	cmp r1, 0x1
	bgt _0810508E
	cmp r1, 0
	beq _08105094
	b _081051BC
_0810508E:
	cmp r1, 0x2
	beq _0810516E
	b _081051BC
_08105094:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081050BE
	strh r1, [r4, 0x32]
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_081050BE:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081051BC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	b _08105166
_081050DC:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08105122
	ldrh r2, [r4, 0x32]
	movs r3, 0x32
	ldrsh r1, [r4, r3]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _08105122
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	subs r0, 0x1
	strh r0, [r4, 0x22]
	adds r0, r2, 0x1
	strh r0, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08105122
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCD
	bl PlaySE12WithPanning
_08105122:
	ldrh r0, [r4, 0x34]
	ldrh r2, [r4, 0x36]
	adds r1, r0, r2
	strh r1, [r4, 0x36]
	lsls r0, r1, 16
	asrs r2, r0, 16
	cmp r2, 0x1F
	ble _08105136
	movs r0, 0x40
	b _08105144
_08105136:
	movs r0, 0x20
	negs r0, r0
	cmp r2, r0
	bgt _08105150
	movs r2, 0x40
	negs r2, r2
	adds r0, r2, 0
_08105144:
	subs r0, r1
	strh r0, [r4, 0x36]
	movs r3, 0x34
	ldrsh r0, [r4, r3]
	negs r0, r0
	strh r0, [r4, 0x34]
_08105150:
	ldrh r0, [r4, 0x36]
	movs r2, 0
	strh r0, [r4, 0x24]
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	movs r3, 0x32
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _081051BC
	strh r2, [r4, 0x30]
	strh r2, [r4, 0x32]
_08105166:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081051BC
_0810516E:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810519A
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810519A:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081051BC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	bl move_anim_8072740
_081051BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8105078

	thumb_func_start sub_81051C4
sub_81051C4: @ 81051C4
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	movs r5, 0
	mov r0, sp
	strh r5, [r0]
	mov r1, sp
	adds r1, 0x2
	strh r5, [r1]
	ldr r0, =gBattleAnimArgs
	movs r3, 0x4
	ldrsh r2, [r0, r3]
	adds r7, r1, 0
	adds r1, r0, 0
	cmp r2, 0
	bne _081051F0
	ldr r0, =gAnimationBankAttacker
	b _081051F2
	.pool
_081051F0:
	ldr r0, =gAnimationBankTarget
_081051F2:
	ldrb r5, [r0]
	ldrb r1, [r1, 0x6]
	movs r0, 0x1
	adds r4, r0, 0
	eors r4, r1
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0810526A
	movs r1, 0x2
	adds r0, r5, 0
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810526A
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_80A8924
	cmp r4, 0
	bne _08105230
	adds r0, r5, 0
	movs r1, 0
	b _08105234
	.pool
_08105230:
	adds r0, r5, 0
	movs r1, 0x2
_08105234:
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08105260
	ldr r2, =gBattleAnimArgs
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r4
	ldrh r0, [r2]
	subs r1, r0
	subs r0, r1
	strh r0, [r2]
	b _0810526A
	.pool
_08105260:
	ldr r1, =gBattleAnimArgs
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r4
	strh r0, [r1]
_0810526A:
	ldr r1, =sub_80A77C8
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81051C4

	thumb_func_start sub_8105284
sub_8105284: @ 8105284
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0810529E
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl move_anim_8072740
_0810529E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8105284

	thumb_func_start sub_81052A4
sub_81052A4: @ 81052A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	movs r6, 0
	mov r0, sp
	strh r6, [r0]
	mov r1, sp
	adds r1, 0x2
	strh r6, [r1]
	ldr r0, =gBattleAnimArgs
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081052DC
	ldr r0, =gAnimationBankAttacker
	ldrb r7, [r0]
	ldr r0, =gAnimationBankTarget
	b _081052E2
	.pool
_081052DC:
	ldr r0, =gAnimationBankTarget
	ldrb r7, [r0]
	ldr r0, =gAnimationBankAttacker
_081052E2:
	ldrb r0, [r0]
	mov r8, r0
	ldr r0, =gBattleAnimArgs
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _08105308
	movs r0, 0
	mov r10, r0
	movs r1, 0x1
	str r1, [sp, 0x4]
	b _08105310
	.pool
_08105308:
	movs r2, 0x2
	mov r10, r2
	movs r3, 0x3
	str r3, [sp, 0x4]
_08105310:
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810536C
	adds r0, r7, 0
	mov r1, r10
	bl sub_80A5C6C
	lsls r0, 24
	ldr r1, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x2
	mov r4, r8
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810535C
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	b _081053EA
	.pool
_0810535C:
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	add r0, r8
	b _081053EA
	.pool
_0810536C:
	adds r0, r7, 0
	mov r1, r10
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleAnimArgs
	ldrh r1, [r1]
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081053E4
	movs r0, 0x2
	adds r4, r7, 0
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _081053E4
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	adds r0, r7, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r6, r0, r3
	adds r2, r4, r2
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r3
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _081053E0
	adds r0, r2, 0
	adds r0, 0x43
	ldrb r0, [r0]
	adds r0, 0x1
	b _081053FA
	.pool
_081053E0:
	adds r0, r6, 0
	b _081053F4
_081053E4:
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r7, r0
_081053EA:
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
_081053F4:
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
_081053FA:
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	adds r0, r7, 0
	ldr r1, [sp, 0x4]
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810544C
	movs r1, 0x2
	mov r0, r8
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810544C
	ldrb r1, [r4, 0xC]
	mov r0, r8
	mov r2, sp
	mov r3, sp
	adds r3, 0x2
	bl sub_80A8924
	b _0810546C
	.pool
_0810544C:
	mov r4, sp
	mov r0, r8
	mov r1, r10
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	mov r0, r8
	ldr r1, [sp, 0x4]
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r2, sp
	strh r0, [r2, 0x2]
_0810546C:
	mov r0, r8
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08105490
	mov r3, sp
	mov r2, sp
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	ldrh r2, [r2]
	adds r0, r2
	strh r0, [r3]
	adds r2, r1, 0
	b _0810549E
	.pool
_08105490:
	mov r3, sp
	mov r0, sp
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r0]
	ldrh r1, [r2, 0x6]
	subs r0, r1
	strh r0, [r3]
_0810549E:
	ldrh r1, [r2, 0x8]
	mov r3, sp
	ldrh r3, [r3, 0x2]
	adds r1, r3
	mov r0, sp
	strh r1, [r0, 0x2]
	mov r3, r9
	strh r3, [r5, 0x30]
	strh r3, [r5, 0x20]
	strh r6, [r5, 0x34]
	strh r6, [r5, 0x22]
	ldrh r0, [r0]
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x36]
	ldrh r0, [r2]
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r1, =sub_8105284
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81052A4

	thumb_func_start sub_81054E8
sub_81054E8: @ 81054E8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x000027db
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0810550E
	lsls r0, 20
	ldr r1, =0x01010000
	adds r0, r1
	lsrs r0, 16
	ldr r1, =gBattleAnimArgs
	ldrb r2, [r1, 0xA]
	ldrh r3, [r1, 0x8]
	movs r1, 0xF
	bl BlendPalette
_0810550E:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r1, =sub_80A77C8
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81054E8

	thumb_func_start sub_8105538
sub_8105538: @ 8105538
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r1, 0xA0
	cmp r0, 0
	beq _08105554
	ldr r1, =0x0000ff60
_08105554:
	movs r0, 0xE0
	lsls r0, 2
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x3C]
	ldr r0, =sub_810557C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105538

	thumb_func_start sub_810557C
sub_810557C: @ 810557C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x2E]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	subs r1, r0
	movs r5, 0
	strh r1, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	subs r2, 0x20
	strh r2, [r4, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r1, 0xA0
	cmp r0, 0
	beq _081055AC
	ldr r1, =0x0000ff60
_081055AC:
	lsls r0, r1, 16
	asrs r0, 16
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x26]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _081055E0
	ldrh r2, [r4, 0x22]
	adds r0, r1, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x24]
	strh r5, [r4, 0x2E]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =sub_81055F4
	str r0, [r4, 0x1C]
_081055E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810557C

	thumb_func_start sub_81055F4
sub_81055F4: @ 81055F4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r1, r0, 0x1
	strh r1, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _08105612
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldr r0, =sub_810561C
	str r0, [r4, 0x1C]
_08105612:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81055F4

	thumb_func_start sub_810561C
sub_810561C: @ 810561C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08105682
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r0, 0
	strh r0, [r4, 0x2E]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08105668
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r0, =sub_8105694
	b _08105680
	.pool
_08105668:
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x20
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r0, =sub_810571C
_08105680:
	str r0, [r4, 0x1C]
_08105682:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810561C

	thumb_func_start sub_8105694
sub_8105694: @ 8105694
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x26]
	subs r0, 0x2
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _081056CA
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	movs r0, 0
	strh r0, [r4, 0x30]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x2E]
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_81056D4
	str r0, [r4, 0x1C]
_081056CA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105694

	thumb_func_start sub_81056D4
sub_81056D4: @ 81056D4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08105712
	ldrh r1, [r4, 0x2E]
	subs r1, 0x1
	strh r1, [r4, 0x2E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08105712
	ldr r0, =sub_810571C
	str r0, [r4, 0x1C]
_08105712:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81056D4

	thumb_func_start sub_810571C
sub_810571C: @ 810571C
	push {lr}
	adds r3, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08105754
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r1, 0x3C
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08105750
	ldr r0, =sub_810575C
	b _08105752
	.pool
_08105750:
	ldr r0, =move_anim_8072740
_08105752:
	str r0, [r3, 0x1C]
_08105754:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810571C

	thumb_func_start sub_810575C
sub_810575C: @ 810575C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810575C

	thumb_func_start sub_810577C
sub_810577C: @ 810577C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x8]
	ldr r2, =gUnknown_085938B0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_81057B8
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810577C

	thumb_func_start sub_81057B8
sub_81057B8: @ 81057B8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _08105802
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl move_anim_task_del
_08105802:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81057B8

	thumb_func_start sub_8105810
sub_8105810: @ 8105810
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	movs r0, 0x3
	strh r0, [r4, 0x20]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08105850
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x22]
	movs r0, 0x8
	b _08105856
	.pool
_08105850:
	movs r0, 0x1
	strh r0, [r4, 0x22]
	ldr r0, =0x0000fff8
_08105856:
	strh r0, [r4, 0x24]
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_8105878
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105810

	thumb_func_start sub_8105878
sub_8105878: @ 8105878
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r0, 0x8
	ldrsh r4, [r3, r0]
	cmp r4, 0x1
	beq _081058CC
	cmp r4, 0x1
	bgt _081058A0
	cmp r4, 0
	beq _081058AA
	b _08105992
	.pool
_081058A0:
	cmp r4, 0x2
	beq _08105948
	cmp r4, 0x3
	beq _08105962
	b _08105992
_081058AA:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0x24]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	strh r4, [r3, 0xA]
	strh r4, [r3, 0xC]
	strh r4, [r3, 0xE]
	b _0810595A
	.pool
_081058CC:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08105992
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	ands r0, r4
	lsls r0, 16
	cmp r0, 0
	beq _08105904
	ldr r2, =gSprites
	movs r4, 0x26
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	adds r1, 0x6
	b _08105916
	.pool
_08105904:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	subs r1, 0x6
_08105916:
	strh r1, [r0, 0x24]
	ldrh r0, [r3, 0xE]
	adds r0, 0x1
	strh r0, [r3, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08105992
	ldrh r1, [r3, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810595A
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x24]
	subs r0, 0x6
	strh r0, [r1, 0x24]
	b _0810595A
	.pool
_08105948:
	ldrh r0, [r3, 0x20]
	subs r0, 0x1
	strh r0, [r3, 0x20]
	lsls r0, 16
	cmp r0, 0
	beq _0810595A
	movs r0, 0
	strh r0, [r3, 0x8]
	b _08105992
_0810595A:
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _08105992
_08105962:
	ldr r2, =gSprites
	movs r4, 0x26
	ldrsh r1, [r3, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0x22]
	ldrh r4, [r0, 0x24]
	adds r1, r4
	strh r1, [r0, 0x24]
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08105992
	adds r0, r5, 0
	bl move_anim_task_del
_08105992:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105878

	thumb_func_start sub_810599C
sub_810599C: @ 810599C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r0, 0xE
	strh r0, [r4, 0x22]
	movs r0, 0x2
	strh r0, [r4, 0x24]
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_81059E0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810599C

	thumb_func_start sub_81059E0
sub_81059E0: @ 81059E0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _08105AA6
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _08105AA6
	strh r2, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08105A3C
	ldr r3, =gSprites
	movs r6, 0x26
	ldrsh r1, [r4, r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _08105A52
	.pool
_08105A3C:
	ldr r3, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_08105A52:
	strb r1, [r0]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x22
	ldrsh r1, [r4, r6]
	cmp r0, r1
	blt _08105AA6
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x24
	ldrsh r1, [r4, r6]
	cmp r0, r1
	bge _08105A88
	strh r2, [r4, 0xA]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	b _08105AA6
	.pool
_08105A88:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl move_anim_task_del
_08105AA6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81059E0

	thumb_func_start sub_8105AAC
sub_8105AAC: @ 8105AAC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	movs r1, 0x4
	strh r1, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	strh r0, [r4, 0x12]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x16]
	strh r0, [r4, 0x18]
	strh r0, [r4, 0x22]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x24]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_8105B08
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105AAC

	thumb_func_start sub_8105B08
sub_8105B08: @ 8105B08
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x18
	ldrsh r2, [r4, r0]
	cmp r2, 0x1
	beq _08105B74
	cmp r2, 0x1
	bgt _08105B30
	cmp r2, 0
	beq _08105B36
	b _08105B90
	.pool
_08105B30:
	cmp r2, 0x2
	beq _08105B8C
	b _08105B90
_08105B36:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08105B90
	strh r2, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08105B90
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08105B6E
	strh r2, [r4, 0x14]
	movs r0, 0x1
	strh r0, [r4, 0x18]
	b _08105B90
_08105B6E:
	movs r0, 0x2
	strh r0, [r4, 0x18]
	b _08105B90
_08105B74:
	movs r1, 0
	strh r1, [r4, 0x12]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08105B90
	strh r2, [r4, 0x16]
	strh r1, [r4, 0x18]
	b _08105B90
_08105B8C:
	movs r0, 0x1
	strh r0, [r4, 0x12]
_08105B90:
	movs r2, 0x8
	ldrsh r5, [r4, r2]
	cmp r5, 0
	beq _08105B9E
	cmp r5, 0x1
	beq _08105C34
	b _08105C42
_08105B9E:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08105C42
	strh r5, [r4, 0xA]
	ldr r0, =gUnknown_085938DC
	movs r3, 0x24
	ldrsh r1, [r4, r3]
	movs r3, 0x26
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08105C42
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	strh r6, [r1, 0x2E]
	movs r0, 0xD
	strh r0, [r1, 0x30]
	ldr r2, =gUnknown_085938F4
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0x24]
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08105C42
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _08105C42
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08105C42
	.pool
_08105C34:
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08105C42
	adds r0, r6, 0
	bl move_anim_task_del
_08105C42:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8105B08

	thumb_func_start sub_8105C48
sub_8105C48: @ 8105C48
	push {r4,lr}
	adds r3, r0, 0
	ldr r4, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	movs r2, 0x1
	ldrb r1, [r0, 0x12]
	ands r1, r2
	lsls r1, 2
	mov r0, r12
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	adds r0, r3, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08105CAA
	movs r0, 0x30
	ldrsh r1, [r3, r0]
	lsls r1, 1
	movs r0, 0x2E
	ldrsh r2, [r3, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r0, r4, 0
	adds r0, 0x8
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r3, 0
	bl DestroySprite
_08105CAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105C48

	thumb_func_start sub_8105CB4
sub_8105CB4: @ 8105CB4
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x000027de
	bl IndexOfSpritePaletteTag
	mov r1, sp
	strb r0, [r1]
	movs r4, 0x1
	ldr r0, =0x00002710
	adds r5, r0, 0
_08105CCC:
	subs r0, r5, r4
	lsls r0, 16
	lsrs r0, 16
	bl AllocSpritePalette
	mov r2, sp
	adds r1, r2, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x2
	ble _08105CCC
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	adds r1, r0, 0
	ldr r0, =gBattleSpritesGfx
	ldr r0, [r0]
	movs r2, 0xBE
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	ldr r0, =gUnknown_08C22610
	bl LZDecompressWram
	movs r4, 0
_08105D00:
	ldr r5, =gBattleSpritesGfx
	ldr r0, [r5]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	lsls r1, r4, 6
	ldr r0, [r0]
	adds r0, r1
	mov r2, sp
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, 20
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	adds r4, 0x1
	cmp r4, 0x2
	ble _08105D00
	ldr r0, [r5]
	movs r4, 0xBE
	lsls r4, 1
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	str r1, [r0]
	adds r0, r6, 0
	bl move_anim_task_del
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105CB4

	thumb_func_start sub_8105D60
sub_8105D60: @ 8105D60
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gUnknown_08593950
	movs r4, 0x2
_08105D6A:
	ldrh r0, [r5]
	bl FreeSpritePaletteByTag
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _08105D6A
	adds r0, r6, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105D60

	thumb_func_start sub_8105D88
sub_8105D88: @ 8105D88
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsls r2, 24
	lsrs r3, r2, 24
	movs r0, 0x1
	ands r3, r0
	negs r0, r3
	orrs r0, r3
	asrs r0, 31
	movs r3, 0x20
	ands r0, r3
	ldrh r4, [r5, 0x4]
	lsls r3, r4, 22
	lsrs r3, 22
	lsrs r1, 22
	adds r0, r1
	adds r3, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r3, r0
	ldr r0, =0xfffffc00
	ands r0, r4
	orrs r0, r3
	strh r0, [r5, 0x4]
	ldr r0, =gUnknown_08593950
	lsrs r2, 25
	lsls r2, 1
	adds r2, r0
	ldrh r0, [r2]
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r5, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105D88

	thumb_func_start sub_8105DE8
sub_8105DE8: @ 8105DE8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08105E08
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_08105E08:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x2E]
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldrb r1, [r4, 0xA]
	ldrb r2, [r4, 0xC]
	adds r0, r5, 0
	bl sub_8105D88
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105DE8

	thumb_func_start sub_8105E60
sub_8105E60: @ 8105E60
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08105E7A
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
_08105E7A:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x32]
	lsls r0, r2, 16
	asrs r0, 24
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x7
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	subs r2, 0x80
	strh r2, [r4, 0x32]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x3C
	bne _08105EAA
	adds r0, r4, 0
	bl move_anim_8072740
_08105EAA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8105E60

	thumb_func_start sub_8105EB0
sub_8105EB0: @ 8105EB0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	bl IsContest
	lsls r0, 24
	movs r6, 0xF0
	cmp r0, 0
	beq _08105EC4
	movs r6, 0x98
_08105EC4:
	movs r5, 0
	ldr r1, =gUnknown_02022E24
	strh r6, [r1]
	ldr r4, =gUnknown_02022E26
	movs r0, 0xA0
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, 0x40
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x44
	bl SetGpuReg
	ldr r1, =0x00003f1f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0xC8
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x10
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	strh r6, [r0, 0xA]
	ldr r1, =sub_8105F30
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105EB0

	thumb_func_start sub_8105F30
sub_8105F30: @ 8105F30
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	ldrh r0, [r3, 0x8]
	adds r4, r0, 0
	adds r4, 0xD
	strh r4, [r3, 0x8]
	ldrh r0, [r3, 0xA]
	adds r2, r0, 0
	subs r2, 0xD
	strh r2, [r3, 0xA]
	lsls r1, r4, 16
	lsls r0, r2, 16
	cmp r1, r0
	blt _08105F70
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =sub_8105F84
	str r0, [r3]
	b _08105F78
	.pool
_08105F70:
	ldr r1, =gUnknown_02022E24
	lsls r0, r4, 8
	orrs r2, r0
	strh r2, [r1]
_08105F78:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105F30

	thumb_func_start sub_8105F84
sub_8105F84: @ 8105F84
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	movs r4, 0
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08105FD8
	movs r0, 0x88
	strh r0, [r1, 0x1E]
	movs r0, 0x50
	movs r1, 0x88
	bl SetGpuReg
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	ldr r2, =0x00007fff
	movs r1, 0x10
	bl BlendPalettes
	b _0810600C
	.pool
_08105FD8:
	cmp r0, 0x4
	ble _0810600C
	ldr r0, =gUnknown_02022E24
	strh r4, [r0]
	ldr r0, =gUnknown_02022E26
	strh r4, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_task_del
_0810600C:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8105F84

	thumb_func_start sub_8106020
sub_8106020: @ 8106020
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0810607C
	movs r0, 0x1
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_08593988
	adds r0, r5, 0
	bl sub_80A7CFC
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	movs r1, 0x4
	strh r1, [r0, 0x24]
	b _081060A4
	.pool
_0810607C:
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r4, r0, r1
	ldrh r0, [r4, 0x24]
	negs r0, r0
	strh r0, [r4, 0x24]
	adds r0, r5, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081060A4
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r0, r6, 0
	bl move_anim_task_del
_081060A4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106020

	thumb_func_start sub_81060B0
sub_81060B0: @ 81060B0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0810610C
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_08593988
	adds r0, r5, 0
	bl sub_80A7CFC
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	movs r1, 0x4
	strh r1, [r0, 0x24]
	b _08106134
	.pool
_0810610C:
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r4, r0, r1
	ldrh r0, [r4, 0x24]
	negs r0, r0
	strh r0, [r4, 0x24]
	adds r0, r5, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08106134
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r0, r6, 0
	bl move_anim_task_del
_08106134:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81060B0

	thumb_func_start sub_8106140
sub_8106140: @ 8106140
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	movs r0, 0x5F
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_810618C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106140

	thumb_func_start sub_810618C
sub_810618C: @ 810618C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _081061B6
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xE
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _081061BC
_081061B6:
	adds r0, r4, 0
	bl move_anim_8072740
_081061BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810618C

	thumb_func_start sub_81061C4
sub_81061C4: @ 81061C4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081061E8
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x32]
	adds r0, r2, 0x1
	strh r0, [r4, 0x2E]
	b _08106244
	.pool
_081061E8:
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	cmp r0, 0x64
	ble _08106236
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08106236:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	ble _08106244
	adds r0, r4, 0
	bl move_anim_8072740
_08106244:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81061C4

	thumb_func_start sub_810624C
sub_810624C: @ 810624C
	push {lr}
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0x20]
	movs r1, 0xA0
	strh r1, [r0, 0x22]
	ldrh r1, [r2, 0x4]
	strh r1, [r0, 0x2E]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x30]
	ldr r1, =sub_80A64B0
	str r1, [r0, 0x1C]
	ldr r1, =sub_810627C
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810624C

	thumb_func_start sub_810627C
sub_810627C: @ 810627C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	lsls r0, 16
	lsrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x26]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0x48
	bgt _081062E2
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	cmp r5, 0x40
	bgt _081062E2
	adds r0, r4, 0
	bl move_anim_8072740
_081062E2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810627C

	thumb_func_start sub_81062E8
sub_81062E8: @ 81062E8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x3
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810632A
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0810632A:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E1A
	strh r1, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C232E0
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r1, =gUnknown_08C23D78
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gUnknown_08C23D50
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81063A8
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81062E8

	thumb_func_start sub_81063A8
sub_81063A8: @ 81063A8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _081063C6
	b _081064F0
_081063C6:
	lsls r0, 2
	ldr r1, =_081063D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081063D8:
	.4byte _081063EC
	.4byte _08106430
	.4byte _08106452
	.4byte _08106496
	.4byte _081064BC
_081063EC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _081064F0
	strh r5, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081064F0
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _081064F0
_08106430:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8D
	bne _081064F0
	movs r0, 0x10
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _081064F0
_08106452:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _081064F0
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _081064F0
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _081064F0
_08106496:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x20]
	adds r1, 0x1
	strh r1, [r0, 0x20]
	b _081064F0
	.pool
_081064BC:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081064D0
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_081064D0:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	adds r0, r4, 0
	bl move_anim_task_del
_081064F0:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81063A8

	thumb_func_start sub_81064F8
sub_81064F8: @ 81064F8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810653A
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0810653A:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E1A
	strh r1, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08106578
	ldr r1, =gUnknown_08D93960
	b _0810658A
	.pool
_08106578:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810659C
	ldr r1, =gUnknown_08D93598
_0810658A:
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	b _081065A6
	.pool
_0810659C:
	ldr r1, =gUnknown_08D9377C
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
_081065A6:
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C249F8
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C249D0
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81065EC
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81064F8

	thumb_func_start sub_81065EC
sub_81065EC: @ 81065EC
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0810660A
	b _08106730
_0810660A:
	lsls r0, 2
	ldr r1, =_0810661C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810661C:
	.4byte _08106630
	.4byte _08106674
	.4byte _08106696
	.4byte _081066DA
	.4byte _081066FC
_08106630:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08106730
	strh r5, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0xE
	bne _08106730
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _08106730
_08106674:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _08106730
	movs r0, 0xE
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _08106730
_08106696:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08106730
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _08106730
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _08106730
_081066DA:
	mov r0, sp
	bl sub_80A6B30
	movs r0, 0x1
	bl sub_80A6C68
	movs r0, 0x2
	bl sub_80A6C68
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_081066FC:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08106710
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_08106710:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	adds r0, r4, 0
	bl move_anim_task_del
_08106730:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81065EC

	thumb_func_start sub_810673C
sub_810673C: @ 810673C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	ldrb r0, [r5]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x3C]
	ldr r1, =sub_810679C
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810673C

	thumb_func_start sub_810679C
sub_810679C: @ 810679C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _081067B2
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	b _081067B6
_081067B2:
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
_081067B6:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	ldrh r1, [r4, 0x34]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x9
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r3, 0x38
	ldrsh r2, [r4, r3]
	cmp r2, 0
	beq _08106828
	cmp r2, 0x1
	bne _08106858
	ldr r1, =0xfffffc00
	adds r0, r1, 0
	ldrh r2, [r4, 0x32]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldr r3, =0xffffff00
	adds r0, r3, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08106858
	movs r0, 0x2
	strh r0, [r4, 0x38]
	b _08106868
	.pool
_08106828:
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _08106858
	strh r2, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x38]
_08106858:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08106868
	adds r0, r4, 0
	bl move_anim_8072740
_08106868:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810679C

	thumb_func_start sub_8106878
sub_8106878: @ 8106878
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl Sin
	strh r0, [r5, 0x2E]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x7
	bl Cos
	strh r0, [r5, 0x30]
	ldr r0, =sub_81068CC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106878

	thumb_func_start sub_81068CC
sub_81068CC: @ 81068CC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	ldrh r3, [r2, 0x26]
	adds r0, r3
	strh r0, [r2, 0x26]
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	movs r3, 0x24
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _0810690A
	movs r0, 0x22
	ldrsh r1, [r2, r0]
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810690A
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _08106910
_0810690A:
	adds r0, r2, 0
	bl move_anim_8072740
_08106910:
	pop {r0}
	bx r0
	thumb_func_end sub_81068CC

	thumb_func_start sub_8106914
sub_8106914: @ 8106914
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	ldrh r3, [r2, 0x26]
	adds r0, r3
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r1, r0, 0x1
	strh r1, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08106940
	adds r0, r2, 0
	bl move_anim_8072740
_08106940:
	pop {r0}
	bx r0
	thumb_func_end sub_8106914

	thumb_func_start sub_8106944
sub_8106944: @ 8106944
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl Sin
	strh r0, [r5, 0x2E]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x7
	bl Cos
	strh r0, [r5, 0x30]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x32]
	ldr r0, =sub_8106914
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106944

	thumb_func_start sub_810699C
sub_810699C: @ 810699C
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081069B2
	adds r0, r2, 0
	bl move_anim_8072740
_081069B2:
	pop {r0}
	bx r0
	thumb_func_end sub_810699C

	thumb_func_start sub_81069B8
sub_81069B8: @ 81069B8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =sub_810699C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81069B8

	thumb_func_start sub_81069D0
sub_81069D0: @ 81069D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081069EE
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_081069EE:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r5, r0, 1
	movs r0, 0xFF
	ands r5, r0
	adds r0, r5, 0
	movs r1, 0x50
	bl Sin
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4F
	bgt _08106A32
	adds r0, r5, 0
	movs r1, 0x50
	bl Cos
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	lsls r0, 16
	asrs r0, 24
	adds r1, r0
	strh r1, [r4, 0x26]
_08106A32:
	movs r0, 0x2E
	ldrsh r2, [r4, r0]
	cmp r2, 0x5A
	ble _08106A50
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
_08106A50:
	cmp r2, 0x64
	ble _08106A5A
	adds r0, r4, 0
	bl move_anim_8072740
_08106A5A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81069D0

	thumb_func_start sub_8106A64
sub_8106A64: @ 8106A64
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x14
	ble _08106ABA
	adds r1, r0, 0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08106ABA:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x1E
	ble _08106AC8
	adds r0, r4, 0
	bl move_anim_8072740
_08106AC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8106A64

	thumb_func_start sub_8106AD0
sub_8106AD0: @ 8106AD0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08106AF4
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x32]
	adds r0, r2, 0x1
	strh r0, [r4, 0x2E]
	b _08106B48
	.pool
_08106AF4:
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	movs r5, 0
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	adds r2, r0, 0
	strh r2, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	cmp r0, 0x46
	ble _08106B48
	ldr r0, =sub_8106A64
	str r0, [r4, 0x1C]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x22]
	adds r0, r2, r1
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x24]
	strh r5, [r4, 0x26]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xB4
	bl __umodsi3
	strh r0, [r4, 0x34]
_08106B48:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106AD0

	thumb_func_start sub_8106B54
sub_8106B54: @ 8106B54
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08106B8E
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	movs r0, 0x1
	strh r0, [r4, 0x32]
_08106B8E:
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x2E]
	adds r0, r2
	strh r0, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsls r1, r0, 2
	adds r0, r1, 0
	cmp r1, 0
	bge _08106BA4
	adds r0, 0xFF
_08106BA4:
	asrs r0, 8
	lsls r0, 8
	subs r0, r1, r0
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _08106BB6
	movs r0, 0
	strh r0, [r4, 0x30]
_08106BB6:
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _08106BC4
	adds r0, 0x3
_08106BC4:
	asrs r0, 2
	movs r1, 0x1E
	subs r1, r0
	adds r0, r2, 0
	bl Cos
	strh r0, [r4, 0x24]
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _08106BE0
	adds r0, 0x7
_08106BE0:
	asrs r0, 3
	movs r1, 0xA
	subs r1, r0
	adds r0, r2, 0
	bl Sin
	strh r0, [r4, 0x26]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x80
	ble _08106C04
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08106C04
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x32]
_08106C04:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08106C18
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bge _08106C18
	movs r0, 0x1
	strh r0, [r4, 0x32]
_08106C18:
	ldrh r0, [r4, 0x34]
	adds r1, r0, 0x1
	strh r1, [r4, 0x34]
	subs r0, 0x9
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x46
	bls _08106C5C
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08106C6A
	.pool
_08106C5C:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08106C6A:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x5A
	ble _08106C78
	adds r0, r4, 0
	bl move_anim_8072740
_08106C78:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8106B54

	thumb_func_start sub_8106C80
sub_8106C80: @ 8106C80
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08106CB4
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrb r1, [r1, 0x4]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _08106CC8
	.pool
_08106CB4:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08106CC8
	adds r0, r4, 0
	bl move_anim_8072740
_08106CC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8106C80

	thumb_func_start sub_8106CD0
sub_8106CD0: @ 8106CD0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08106CEC
	adds r0, r5, 0
	bl move_anim_8072740
	b _08106D50
	.pool
_08106CEC:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08106CFC
	ldr r4, =gAnimationBankAttacker
	b _08106CFE
	.pool
_08106CFC:
	ldr r4, =gAnimationBankTarget
_08106CFE:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r0, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0
	bne _08106D34
	ldrh r0, [r5, 0x20]
	adds r0, 0x20
	b _08106D38
	.pool
_08106D34:
	ldrh r0, [r5, 0x20]
	subs r0, 0x20
_08106D38:
	strh r0, [r5, 0x20]
	ldrh r0, [r2, 0x4]
	strh r0, [r5, 0x2E]
	ldrh r1, [r2, 0x2]
	strh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =sub_8106D5C
	str r0, [r5, 0x1C]
_08106D50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106CD0

	thumb_func_start sub_8106D5C
sub_8106D5C: @ 8106D5C
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08106D8C
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	cmp r0, 0
	beq _08106D86
	ldrh r1, [r2, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl StartSpriteAnim
	b _08106D8C
_08106D86:
	adds r0, r2, 0
	bl move_anim_8072740
_08106D8C:
	pop {r0}
	bx r0
	thumb_func_end sub_8106D5C

	thumb_func_start sub_8106D90
sub_8106D90: @ 8106D90
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	ldr r2, =gUnknown_08593B98
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_8106DD4
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106D90

	thumb_func_start sub_8106DD4
sub_8106DD4: @ 8106DD4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _08106DF4
	adds r0, r4, 0
	bl move_anim_task_del
_08106DF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106DD4

	thumb_func_start sub_8106E00
sub_8106E00: @ 8106E00
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08106E1C
	ldr r0, =gAnimationBankAttacker
	b _08106E1E
	.pool
_08106E1C:
	ldr r0, =gAnimationBankTarget
_08106E1E:
	ldrb r6, [r0]
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08106E38
	ldr r1, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x2]
_08106E38:
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r7, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r3, [r7, 0x2]
	adds r0, r3
	movs r4, 0
	strh r0, [r5, 0x20]
	adds r0, r6, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r7, 0x4]
	adds r0, r1
	strh r0, [r5, 0x22]
	strh r4, [r5, 0x2E]
	ldrh r1, [r5, 0x20]
	lsls r1, 3
	strh r1, [r5, 0x30]
	lsls r0, 3
	strh r0, [r5, 0x32]
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	lsls r0, 3
	cmp r0, 0
	bge _08106E78
	adds r0, 0x7
_08106E78:
	asrs r0, 3
	strh r0, [r5, 0x34]
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	lsls r0, 3
	cmp r0, 0
	bge _08106E88
	adds r0, 0x7
_08106E88:
	asrs r0, 3
	strh r0, [r5, 0x36]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0x6
	ldrsh r0, [r7, r3]
	lsls r0, 4
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r0, =sub_8106EC8
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106E00

	thumb_func_start sub_8106EC8
sub_8106EC8: @ 8106EC8
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x34]
	ldrh r1, [r2, 0x30]
	adds r0, r1
	strh r0, [r2, 0x30]
	ldrh r1, [r2, 0x36]
	ldrh r3, [r2, 0x32]
	adds r1, r3
	strh r1, [r2, 0x32]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r1, 19
	strh r1, [r2, 0x22]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08106EFC
	adds r0, r2, 0
	bl move_anim_8072740
_08106EFC:
	pop {r0}
	bx r0
	thumb_func_end sub_8106EC8

	thumb_func_start sub_8106F00
sub_8106F00: @ 8106F00
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08106F22
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	movs r0, 0x78
	subs r0, r1
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08106F22:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08106F40
	ldrb r0, [r4, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	movs r1, 0
	bl sub_80A750C
_08106F40:
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	adds r0, 0x50
	cmp r1, r0
	bne _08106F54
	adds r0, r4, 0
	bl move_anim_8072740
_08106F54:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106F00

	thumb_func_start sub_8106F60
sub_8106F60: @ 8106F60
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08106F8E
	movs r5, 0x78
	strh r5, [r6, 0x20]
	ldr r4, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r0, 0xF
	strh r0, [r6, 0x22]
	ldrb r1, [r4, 0x2]
	adds r0, r6, 0
	bl StartSpriteAnim
	strh r5, [r6, 0x38]
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x34]
_08106F8E:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r6, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r6, 0x30]
	movs r2, 0x2E
	ldrsh r0, [r6, r2]
	lsls r4, r0, 1
	adds r4, r0
	ldrh r0, [r6, 0x34]
	adds r4, r0
	movs r2, 0xFF
	ldrh r0, [r6, 0x3A]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6, 0x3A]
	ands r4, r2
	adds r0, r4, 0
	movs r1, 0x64
	bl Cos
	strh r0, [r6, 0x24]
	adds r0, r4, 0
	movs r1, 0xA
	bl Sin
	adds r4, r0, 0
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	movs r1, 0x4
	bl Cos
	ldrh r2, [r6, 0x30]
	adds r4, r2
	adds r0, r4
	strh r0, [r6, 0x26]
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	movs r2, 0x38
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0810700A
	ldr r0, =sub_8107018
	str r0, [r6, 0x1C]
	strh r5, [r6, 0x2E]
	adds r0, r6, 0
	bl oamt_add_pos2_onto_pos1
	movs r0, 0x5
	strh r0, [r6, 0x32]
	strh r5, [r6, 0x36]
	strh r5, [r6, 0x34]
	adds r0, r6, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0810700A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8106F60

	thumb_func_start sub_8107018
sub_8107018: @ 8107018
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	ble _08107032
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, =sub_810703C
	str r0, [r1, 0x1C]
_08107032:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107018

	thumb_func_start sub_810703C
sub_810703C: @ 810703C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	ldrh r2, [r4, 0x34]
	adds r0, r1, r2
	strh r0, [r4, 0x34]
	strh r0, [r4, 0x26]
	adds r1, 0x1
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x30
	ble _08107066
	lsls r0, r1, 16
	cmp r0, 0
	ble _08107066
	ldrh r0, [r4, 0x36]
	subs r1, r0, 0x5
	strh r1, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x36]
_08107066:
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _08107098
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0
	bl move_anim_8072740
_08107098:
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bne _081070A6
	adds r0, r4, 0
	bl move_anim_8072740
_081070A6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810703C

	thumb_func_start sub_81070AC
sub_81070AC: @ 81070AC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081070F8
	ldr r4, =gAnimationBankAttacker
	ldrb r1, [r4]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _081070F8
	ldrb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
	ldrh r0, [r5, 0x22]
	adds r0, 0x28
	strh r0, [r5, 0x22]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _08107118
	.pool
_081070F8:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x28
	strh r0, [r5, 0x22]
_08107118:
	movs r0, 0xD
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	subs r0, 0x48
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81070AC

	thumb_func_start sub_8107144
sub_8107144: @ 8107144
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gBattleAnimArgs
	ldr r1, =gDisableStructMoveAnim
	ldr r1, [r1]
	ldrb r2, [r1, 0x10]
	movs r1, 0x1
	ands r1, r2
	strh r1, [r3, 0xE]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107144

	thumb_func_start update_fury_cutter_counter_copy
update_fury_cutter_counter_copy: @ 8107168
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimArgs
	ldr r1, =gDisableStructMoveAnim
	ldr r1, [r1]
	ldrb r1, [r1, 0x10]
	strh r1, [r2, 0xE]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end update_fury_cutter_counter_copy

	thumb_func_start sub_8107188
sub_8107188: @ 8107188
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _081071B0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r5, 0xA]
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0xC]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0xE]
_081071B0:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	bl __modsi3
	cmp r0, 0x1
	bne _081071F8
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x50
	bl __umodsi3
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_08595020
	adds r1, r4, 0
	movs r3, 0x4
	bl CreateSprite
_081071F8:
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0810720A
	adds r0, r6, 0
	bl move_anim_task_del
_0810720A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107188

	thumb_func_start sub_810721C
sub_810721C: @ 810721C
	ldr r1, =sub_8107228
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_810721C

	thumb_func_start sub_8107228
sub_8107228: @ 8107228
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bgt _08107246
	ldrh r0, [r2, 0x24]
	adds r0, 0x1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x26]
	adds r0, 0x4
	strh r0, [r2, 0x26]
_08107246:
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810725A
	adds r0, r2, 0
	bl DestroySprite
_0810725A:
	pop {r0}
	bx r0
	thumb_func_end sub_8107228

	thumb_func_start sub_8107260
sub_8107260: @ 8107260
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08107290
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gBattleAnimArgs
	ldrh r1, [r4]
	subs r0, r1
	b _081072A2
	.pool
_08107290:
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
_081072A2:
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
	strh r0, [r6, 0x22]
	adds r2, r6, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081072D8
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_081072D8:
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0xC]
	strh r0, [r6, 0x2E]
	ldrh r0, [r6, 0x20]
	strh r0, [r6, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x32]
	ldrh r0, [r6, 0x22]
	strh r0, [r6, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =SpriteCallbackDummy
	bl CreateInvisibleSpriteWithCallback
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	strh r4, [r6, 0x38]
	ldrb r0, [r5, 0x8]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl Sin
	ldrh r1, [r6, 0x20]
	subs r1, r0
	strh r1, [r6, 0x20]
	ldrb r0, [r5, 0x8]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl Cos
	ldrh r1, [r6, 0x22]
	subs r1, r0
	strh r1, [r6, 0x22]
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r5, 0x4]
	strh r0, [r1, 0x2E]
	ldrh r0, [r5, 0x6]
	strh r0, [r1, 0x30]
	ldrh r0, [r5, 0xA]
	strh r0, [r1, 0x32]
	ldrb r0, [r5, 0x8]
	lsls r0, 8
	strh r0, [r1, 0x34]
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x36]
	ldr r1, =sub_8107380
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107260

	thumb_func_start sub_8107380
sub_8107380: @ 8107380
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r1, [r5, 0x38]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r7, r0, r2
	ldrh r4, [r7, 0x36]
	lsls r4, 24
	lsrs r4, 24
	ldrh r0, [r7, 0x34]
	mov r8, r0
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl sub_80A6F3C
	mov r1, r8
	lsrs r6, r1, 8
	movs r0, 0x2E
	ldrsh r1, [r7, r0]
	adds r0, r6, 0
	bl Sin
	ldrh r1, [r5, 0x24]
	adds r0, r1
	strh r0, [r5, 0x24]
	movs r0, 0x30
	ldrsh r1, [r7, r0]
	adds r0, r6, 0
	bl Cos
	ldrh r1, [r5, 0x26]
	adds r0, r1
	strh r0, [r5, 0x26]
	ldrh r0, [r7, 0x32]
	mov r1, r8
	adds r1, r0
	strh r1, [r7, 0x34]
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	cmp r4, 0
	beq _081073EC
	strh r4, [r7, 0x36]
	b _081073F6
	.pool
_081073EC:
	ldr r0, =sub_8107408
	str r0, [r5, 0x1C]
	adds r0, r7, 0
	bl DestroySprite
_081073F6:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107380

	thumb_func_start sub_8107408
sub_8107408: @ 8107408
	push {lr}
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r2, [r3]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	strb r1, [r3]
	ldr r1, =sub_80A67D8
	str r1, [r0, 0x1C]
	ldr r1, =sub_8107430
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107408

	thumb_func_start sub_8107430
sub_8107430: @ 8107430
	push {lr}
	movs r1, 0xA
	strh r1, [r0, 0x2E]
	ldr r1, =sub_80A64B0
	str r1, [r0, 0x1C]
	ldr r1, =move_anim_8074EE0
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107430

	thumb_func_start sub_810744C
sub_810744C: @ 810744C
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810747C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	lsls r0, 16
	lsrs r6, r0, 16
	adds r7, r1, 0
	b _08107482
	.pool
_0810747C:
	ldr r0, =gBattleAnimArgs
	ldrh r6, [r0, 0x4]
	adds r7, r0, 0
_08107482:
	ldrh r0, [r7, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r7, [r7, 0x6]
	adds r0, r7
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_81074E4
	str r0, [r5, 0x1C]
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810744C

	thumb_func_start sub_81074E4
sub_81074E4: @ 81074E4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08107506
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
_08107506:
	adds r0, r4, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _08107518
	adds r0, r4, 0
	bl move_anim_8072740
_08107518:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81074E4

	thumb_func_start sub_8107528
sub_8107528: @ 8107528
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x8]
	ldr r0, =0x0000279c
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4, 0xC]
	ldr r0, =sub_810756C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107528

	thumb_func_start sub_810756C
sub_810756C: @ 810756C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x1C]
	adds r0, 0x1
	strh r0, [r2, 0x1C]
	lsls r0, 16
	asrs r0, 16
	mov r12, r1
	cmp r0, 0x3
	bne _081075BE
	movs r0, 0
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gPlttBufferFaded
	lsls r0, r5, 1
	adds r0, r1
	ldrh r6, [r0]
	adds r7, r1, 0
	adds r3, r0, 0x2
	movs r1, 0x6
	adds r2, r0, 0
_081075A8:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _081075A8
	adds r0, r5, 0x7
	lsls r0, 1
	adds r0, r7
	strh r6, [r0]
_081075BE:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r12
	ldrh r1, [r0, 0x1E]
	adds r1, 0x1
	strh r1, [r0, 0x1E]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _081075DE
	adds r0, r4, 0
	bl move_anim_task_del
_081075DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810756C

	thumb_func_start sub_81075EC
sub_81075EC: @ 81075EC
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	movs r0, 0x1E
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	movs r0, 0xD2
	lsls r0, 8
	bl __divsi3
	strh r0, [r5, 0x38]
	ldr r0, =gBattleAnimArgs
	ldrh r2, [r0, 0x6]
	strh r2, [r5, 0x3C]
	ldrh r1, [r0, 0xE]
	movs r3, 0xE
	ldrsh r0, [r0, r3]
	cmp r0, 0x7F
	ble _0810765C
	adds r0, r1, 0
	subs r0, 0x7F
	lsls r0, 8
	strh r0, [r5, 0x3A]
	negs r0, r2
	strh r0, [r5, 0x3C]
	b _08107660
	.pool
_0810765C:
	lsls r0, r1, 8
	strh r0, [r5, 0x3A]
_08107660:
	ldr r1, =sub_8107674
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81075EC

	thumb_func_start sub_8107674
sub_8107674: @ 8107674
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _08107688
	adds r0, r4, 0
	bl move_anim_8072740
_08107688:
	ldrh r0, [r4, 0x3A]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	adds r0, r1
	asrs r0, 8
	cmp r0, 0x7F
	ble _081076B8
	movs r0, 0
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	negs r0, r0
	strh r0, [r4, 0x3C]
	b _081076C0
_081076B8:
	ldrh r0, [r4, 0x38]
	ldrh r1, [r4, 0x3A]
	adds r0, r1
	strh r0, [r4, 0x3A]
_081076C0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8107674

	thumb_func_start sub_81076C8
sub_81076C8: @ 81076C8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r3, =gBattleAnimArgs
	ldrh r0, [r3]
	movs r2, 0
	strh r0, [r1, 0x8]
	strh r2, [r3, 0xE]
	ldr r0, =sub_81076F4
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81076C8

	thumb_func_start sub_81076F4
sub_81076F4: @ 81076F4
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2, 0xE]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r2, 0xE]
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	cmp r1, 0
	bne _08107722
	adds r0, r3, 0
	bl move_anim_task_del
_08107722:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81076F4

	thumb_func_start sub_8107730
sub_8107730: @ 8107730
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r7, =gAnimationBankAttacker
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r7]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r6, =0x0000fff6
	strh r6, [r4, 0x26]
	ldrb r0, [r7]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r5, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810778A
	ldrb r0, [r7]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08107784
	movs r0, 0xA
	strh r0, [r4, 0x24]
	b _0810778C
	.pool
_08107784:
	strh r6, [r4, 0x24]
	subs r0, r5, 0x2
	b _0810778E
_0810778A:
	strh r6, [r4, 0x24]
_0810778C:
	adds r0, r5, 0x2
_0810778E:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldr r0, =sub_81077A4
	str r0, [r4, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107730

	thumb_func_start sub_81077A4
sub_81077A4: @ 81077A4
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081077BA
	adds r0, r2, 0
	bl move_anim_8072740
_081077BA:
	pop {r0}
	bx r0
	thumb_func_end sub_81077A4

	thumb_func_start sub_81077C0
sub_81077C0: @ 81077C0
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0810780A
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4]
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	beq _08107802
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810780A
_08107802:
	movs r1, 0
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4]
_0810780A:
	ldr r5, =gBattleAnimArgs
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0
	cmp r0, 0
	bne _0810781E
	movs r1, 0x1
_0810781E:
	ldrb r0, [r5, 0xA]
	movs r7, 0x1
	cmp r0, 0
	bne _08107828
	movs r7, 0x3
_08107828:
	adds r0, r6, 0
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08107842
	ldrh r0, [r5, 0x4]
	negs r0, r0
	strh r0, [r5, 0x4]
_08107842:
	ldrh r0, [r5, 0x8]
	strh r0, [r6, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r4]
	adds r1, r7, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x6]
	adds r0, r5
	strh r0, [r6, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81077C0

	thumb_func_start sub_8107894
sub_8107894: @ 8107894
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x8]
	strh r1, [r4, 0x2E]
	ldrh r0, [r0, 0x4]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	adds r1, r0
	strh r1, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107894

	thumb_func_start sub_81078D0
sub_81078D0: @ 81078D0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081078EC
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	b _081078F4
	.pool
_081078EC:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
_081078F4:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x3C]
	ldr r0, =sub_810790C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81078D0

	thumb_func_start sub_810790C
sub_810790C: @ 810790C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0xB
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x30
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810794C
	adds r0, r4, 0
	bl move_anim_8072740
_0810794C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810790C

	thumb_func_start sub_8107954
sub_8107954: @ 8107954
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	bl lcd_bg_operations
	mov r0, sp
	bl sub_80A6B30
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081079E0
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081079D0
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08D95E00
	bl sub_80A6D48
	b _081079EA
	.pool
_081079D0:
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08D960D0
	bl sub_80A6D48
	b _081079EA
	.pool
_081079E0:
	ldr r1, =gUnknown_08D963A4
	mov r0, sp
	movs r2, 0x1
	bl sub_80A6D60
_081079EA:
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08D94AB8
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08107A24
	ldr r0, =gUnknown_08D95DD8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	b _08107A32
	.pool
_08107A24:
	ldr r0, =gUnknown_08D8FB9C
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
_08107A32:
	ldr r0, =sub_8107D58
	ldr r4, =gTasks
	mov r2, r10
	lsls r5, r2, 2
	adds r1, r5, r2
	lsls r1, 3
	adds r6, r1, r4
	ldrb r1, [r6, 0x7]
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0
	mov r9, r0
	mov r1, r8
	strh r1, [r6, 0x26]
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r7, r0, r4
	mov r0, r9
	strh r0, [r7, 0x8]
	movs r0, 0x80
	lsls r0, 5
	strh r0, [r7, 0xA]
	strh r0, [r7, 0xC]
	bl IsContest
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08107AB4
	ldr r1, =0x0000ffb0
	adds r0, r1, 0
	ldr r2, =gUnknown_02022E18
	strh r0, [r2]
	adds r1, 0x20
	adds r0, r1, 0
	ldr r2, =gUnknown_02022E1A
	strh r0, [r2]
	movs r0, 0x2
	strh r0, [r6, 0x8]
	movs r0, 0x1
	strh r0, [r6, 0xA]
	mov r0, r9
	strh r0, [r7, 0xE]
	b _08107B0E
	.pool
_08107AB4:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _08107AF8
	ldr r2, =0x0000ff20
	adds r0, r2, 0
	ldr r2, =gUnknown_02022E18
	strh r0, [r2]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ldr r2, =gUnknown_02022E1A
	strh r0, [r2]
	movs r0, 0x2
	strh r0, [r6, 0x8]
	ldr r0, =0x0000ffff
	strh r0, [r6, 0xA]
	strh r1, [r7, 0xE]
	b _08107B0E
	.pool
_08107AF8:
	ldr r0, =gUnknown_02022E18
	strh r4, [r0]
	ldr r1, =0x0000ffd0
	adds r0, r1, 0
	ldr r2, =gUnknown_02022E1A
	strh r0, [r2]
	ldr r0, =0x0000fffe
	strh r0, [r6, 0x8]
	movs r0, 0x1
	strh r0, [r6, 0xA]
	strh r4, [r7, 0xE]
_08107B0E:
	ldr r0, =gUnknown_02022E18
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldr r2, =gUnknown_02022E1A
	ldrh r1, [r2]
	movs r0, 0x16
	bl SetGpuReg
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08107B54
	movs r0, 0x30
	strh r0, [r1, 0x10]
	movs r0, 0x70
	b _08107B58
	.pool
_08107B54:
	movs r0, 0
	strh r0, [r1, 0x10]
_08107B58:
	strh r0, [r1, 0x12]
	ldr r1, =gTasks
	mov r2, r10
	adds r0, r5, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x14]
	ldr r1, =sub_8107B84
	str r1, [r0]
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107954

	thumb_func_start sub_8107B84
sub_8107B84: @ 8107B84
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_02022E18
	ldr r2, =gUnknown_02022E1A
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x8]
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r2]
	adds r0, r1
	strh r0, [r2]
	mov r0, sp
	bl sub_80A6B30
	ldrh r0, [r4, 0xA]
	ldrh r3, [r4, 0xC]
	adds r0, r3
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08107C18
	ldr r1, =gPlttBufferFaded
	mov r0, sp
	ldrb r0, [r0, 0x8]
	lsls r0, 4
	adds r0, 0x7
	lsls r0, 1
	adds r0, r1
	ldrh r6, [r0]
	movs r2, 0x6
	adds r7, r1, 0
	adds r3, r7, 0
	mov r4, sp
_08107BDE:
	ldrb r0, [r4, 0x8]
	lsls r0, 4
	adds r1, r2, 0x1
	adds r0, r1
	lsls r1, r0, 1
	adds r1, r3
	subs r0, 0x1
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _08107BDE
	mov r0, sp
	ldrb r0, [r0, 0x8]
	lsls r0, 4
	adds r0, 0x1
	lsls r0, 1
	adds r0, r7
	strh r6, [r0]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0x12]
_08107C18:
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r3, r0, r1
	ldrh r0, [r3, 0x14]
	adds r0, 0x1
	strh r0, [r3, 0x14]
	lsls r0, 16
	asrs r0, 16
	adds r4, r1, 0
	adds r6, r2, 0
	cmp r0, 0x1
	ble _08107C86
	movs r0, 0
	strh r0, [r3, 0x14]
	ldrh r0, [r3, 0xE]
	adds r2, r0, 0x1
	strh r2, [r3, 0xE]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0xD
	bgt _08107C62
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x10
	subs r0, r2
	lsls r0, 8
	orrs r2, r0
	strh r2, [r1, 0xA]
	ldrh r0, [r3, 0x10]
	adds r0, 0x1
	strh r0, [r3, 0x10]
_08107C62:
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	cmp r0, 0x36
	ble _08107C86
	ldrh r2, [r3, 0x10]
	subs r2, 0x1
	strh r2, [r3, 0x10]
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x10
	subs r0, r2
	lsls r0, 8
	orrs r2, r0
	strh r2, [r1, 0xA]
_08107C86:
	adds r0, r6, r5
	lsls r0, 3
	adds r2, r0, r4
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldrh r0, [r0, 0xA]
	movs r3, 0x1F
	ands r3, r0
	cmp r3, 0
	bne _08107CA8
	strh r3, [r2, 0x8]
	ldr r0, =sub_8107CC4
	str r0, [r2]
_08107CA8:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107B84

	thumb_func_start sub_8107CC4
sub_8107CC4: @ 8107CC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r7, =gUnknown_02022E18
	ldr r0, =gUnknown_02022E1A
	mov r8, r0
	ldr r6, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r6
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08107D08
	movs r0, 0x1
	bl sub_80A6C68
	movs r0, 0x2
	bl sub_80A6C68
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08107D4A
	.pool
_08107D08:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08107D1C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_08107D1C:
	movs r0, 0
	strh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x26]
	adds r0, r5, 0
	bl move_anim_task_del
_08107D4A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107CC4

	thumb_func_start sub_8107D58
sub_8107D58: @ 8107D58
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08107D74
	b _08107EAC
_08107D74:
	cmp r0, 0x1
	bgt _08107D84
	cmp r0, 0
	beq _08107D8C
	b _08108022
	.pool
_08107D84:
	cmp r0, 0x2
	bne _08107D8A
	b _08107F78
_08107D8A:
	b _08108022
_08107D8C:
	movs r3, 0
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	ldr r1, =gUnknown_02038C28
	mov r12, r1
	cmp r3, r0
	bge _08107DCA
	mov r7, r12
	movs r5, 0xF0
	lsls r5, 3
	add r5, r12
	ldr r6, =0x0000ffff
_08107DA4:
	lsls r2, r3, 16
	asrs r2, 16
	lsls r1, r2, 1
	adds r3, r1, r7
	adds r1, r5
	ldrh r0, [r4, 0xC]
	strh r0, [r1]
	ldrh r1, [r4, 0xC]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r3]
	adds r2, 0x1
	lsls r2, 16
	lsrs r3, r2, 16
	asrs r2, 16
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r2, r0
	blt _08107DA4
_08107DCA:
	ldrh r3, [r4, 0x10]
	lsls r2, r3, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _08107E04
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
	ldr r7, =0x0000ffff
_08107DE2:
	asrs r2, 16
	lsls r1, r2, 1
	adds r3, r1, r5
	adds r1, r6
	ldrh r0, [r4, 0xA]
	strh r0, [r1]
	ldrh r1, [r4, 0xA]
	adds r0, r7, 0
	ands r0, r1
	strh r0, [r3]
	adds r2, 0x1
	lsls r2, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08107DE2
_08107E04:
	ldrh r3, [r4, 0x12]
	lsls r2, r3, 16
	asrs r0, r2, 16
	cmp r0, 0x9F
	bgt _08107E3A
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
	ldr r7, =0x0000ffff
_08107E18:
	asrs r2, 16
	lsls r1, r2, 1
	adds r3, r1, r5
	adds r1, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r1]
	ldrh r1, [r4, 0xC]
	adds r0, r7, 0
	ands r0, r1
	strh r0, [r3]
	adds r2, 0x1
	lsls r2, 16
	lsrs r3, r2, 16
	lsls r2, r3, 16
	asrs r0, r2, 16
	cmp r0, 0x9F
	ble _08107E18
_08107E3A:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08107E64
	lsls r0, r3, 16
	asrs r0, 15
	mov r3, r12
	adds r2, r0, r3
	movs r1, 0xF0
	lsls r1, 3
	add r1, r12
	adds r0, r1
	ldrh r1, [r4, 0xA]
	strh r1, [r0]
	ldrh r0, [r4, 0xA]
	b _08107E7A
	.pool
_08107E64:
	lsls r0, r3, 16
	asrs r0, 15
	mov r1, r12
	adds r2, r0, r1
	movs r1, 0xF0
	lsls r1, 3
	add r1, r12
	adds r0, r1
	ldrh r1, [r4, 0xC]
	strh r1, [r0]
	ldrh r0, [r4, 0xC]
_08107E7A:
	strh r0, [r2]
	ldr r0, =0x04000052
	str r0, [sp]
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08108022
	.pool
_08107EAC:
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _08107EC4
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bgt _08107ED8
	strh r1, [r4, 0x10]
	b _08107ED2
_08107EC4:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	ble _08107ED8
_08107ED2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08107ED8:
	movs r3, 0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _08107F0C
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107EE6:
	lsls r1, r3, 16
	asrs r1, 16
	lsls r3, r1, 1
	ldrb r2, [r5, 0x14]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 7
	adds r3, r0
	adds r3, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r3]
	adds r1, 0x1
	lsls r1, 16
	lsrs r3, r1, 16
	asrs r1, 16
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _08107EE6
_08107F0C:
	ldrh r3, [r4, 0x10]
	lsls r2, r3, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _08107F40
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107F1E:
	asrs r3, r2, 16
	lsls r2, r3, 1
	ldrb r1, [r5, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r6
	ldrh r0, [r4, 0xA]
	strh r0, [r2]
	adds r3, 0x1
	lsls r2, r3, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08107F1E
_08107F40:
	ldrh r3, [r4, 0x12]
	lsls r1, r3, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _08108022
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107F4E:
	asrs r3, r1, 16
	lsls r2, r3, 1
	ldrb r1, [r5, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	lsls r1, r3, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _08107F4E
	b _08108022
	.pool
_08107F78:
	movs r3, 0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _08107FAC
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107F86:
	lsls r1, r3, 16
	asrs r1, 16
	lsls r3, r1, 1
	ldrb r2, [r5, 0x14]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 7
	adds r3, r0
	adds r3, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r3]
	adds r1, 0x1
	lsls r1, 16
	lsrs r3, r1, 16
	asrs r1, 16
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _08107F86
_08107FAC:
	ldrh r3, [r4, 0x10]
	lsls r2, r3, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _08107FE0
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107FBE:
	asrs r3, r2, 16
	lsls r2, r3, 1
	ldrb r1, [r5, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r6
	ldrh r0, [r4, 0xA]
	strh r0, [r2]
	adds r3, 0x1
	lsls r2, r3, 16
	asrs r1, r2, 16
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08107FBE
_08107FE0:
	ldrh r3, [r4, 0x12]
	lsls r1, r3, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _0810800C
	ldr r6, =gUnknown_02038C28
	ldr r5, =gUnknown_02039B28
_08107FEE:
	asrs r3, r1, 16
	lsls r2, r3, 1
	ldrb r1, [r5, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	lsls r1, r3, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _08107FEE
_0810800C:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08108022
	bl remove_some_task
	adds r0, r7, 0
	bl DestroyTask
_08108022:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8107D58

	thumb_func_start sub_8108034
sub_8108034: @ 8108034
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x8
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	bl Random2
	movs r5, 0xFF
	ands r5, r0
	movs r0, 0x80
	lsls r0, 1
	adds r6, r0, 0
	orrs r5, r6
	bl Random2
	ldr r1, =0x000001ff
	ands r1, r0
	adds r0, r1, 0
	cmp r0, 0xFF
	ble _0810807A
	subs r0, r6, r0
	lsls r0, 16
	lsrs r1, r0, 16
_0810807A:
	strh r5, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldr r0, =sub_8108098
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108034

	thumb_func_start sub_8108098
sub_8108098: @ 8108098
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x34]
	adds r3, r0, r1
	strh r3, [r2, 0x34]
	ldrh r1, [r2, 0x32]
	ldrh r4, [r2, 0x36]
	adds r1, r4
	strh r1, [r2, 0x36]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _081080BC
	lsls r0, r3, 16
	asrs r0, 24
	negs r0, r0
	b _081080C0
_081080BC:
	lsls r0, r3, 16
	asrs r0, 24
_081080C0:
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _081080DE
	adds r0, r2, 0
	bl move_anim_8072740
_081080DE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8108098

	thumb_func_start sub_81080E4
sub_81080E4: @ 81080E4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x12]
	bl sub_8108384
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_8108140
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81080E4

	thumb_func_start sub_8108140
sub_8108140: @ 8108140
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bls _0810815C
	b _0810837A
_0810815C:
	lsls r0, 2
	ldr r1, =_08108170
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08108170:
	.4byte _08108190
	.4byte _081081B6
	.4byte _08108248
	.4byte _0810827E
	.4byte _08108292
	.4byte _081082A0
	.4byte _08108320
	.4byte _0810836C
_08108190:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 1
	movs r0, 0xE0
	str r0, [sp]
	movs r0, 0x80
	lsls r0, 2
	str r0, [sp, 0x4]
	movs r0, 0x20
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r2, r3, 0
	bl sub_80A805C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081081B6:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08108212
	movs r0, 0
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08108200
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strh r1, [r0, 0x24]
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x1
	strh r1, [r0, 0x22]
	b _08108212
	.pool
_08108200:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffd
	strh r1, [r0, 0x24]
_08108212:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08108222
	b _0810837A
_08108222:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7E6C
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
	strh r5, [r4, 0xE]
	b _0810835C
	.pool
_08108248:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _08108258
	b _0810837A
_08108258:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 2
	movs r0, 0xC0
	lsls r0, 1
	str r0, [sp]
	movs r0, 0xE0
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0xE0
	bl sub_80A805C
	movs r0, 0
	strh r0, [r4, 0xE]
	b _0810835E
_0810827E:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0810837A
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	b _0810835E
_08108292:
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8108408
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081082A0:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810837A
	movs r0, 0
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081082D8
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x2
	b _081082EA
	.pool
_081082D8:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x2
_081082EA:
	strh r1, [r0, 0x26]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0xA
	bne _0810837A
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xC0
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r3, 0xE0
	bl sub_80A805C
	movs r0, 0
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	b _0810835E
	.pool
_08108320:
	ldr r6, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r0, 0x22]
	subs r1, 0x1
	strh r1, [r0, 0x22]
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0810837A
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r4, 0x12]
	strh r1, [r0, 0x22]
_0810835C:
	strh r5, [r4, 0x10]
_0810835E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810837A
	.pool
_0810836C:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810837A
	adds r0, r2, 0
	bl move_anim_task_del
_0810837A:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8108140

	thumb_func_start sub_8108384
sub_8108384: @ 8108384
	push {r4,r5,lr}
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _081083B8
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _081083C8
	.pool
_081083B4:
	adds r0, r2, 0
	b _081083FA
_081083B8:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_081083C8:
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r3, r0, 16
	lsrs r4, 18
	movs r2, 0
_081083E6:
	adds r1, r2, 0x1
	adds r0, r4, 0
	muls r0, r1
	cmp r3, r0
	blt _081083B4
	lsls r0, r1, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _081083E6
	movs r0, 0x3
_081083FA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8108384

	thumb_func_start sub_8108408
sub_8108408: @ 8108408
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r7, r0, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0xAC
	ldrb r0, [r4]
	bl sub_80A82E4
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	ldrh r1, [r7, 0xA]
	movs r0, 0x4
	subs r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r0, 0
	bgt _08108458
	movs r1, 0x1
_08108458:
	movs r0, 0
	str r0, [sp, 0x4]
	lsls r0, r1, 16
	mov r10, r8
	mov r9, r6
	mov r1, r10
	lsls r1, 4
	str r1, [sp, 0xC]
	mov r1, r9
	lsls r1, 4
	str r1, [sp, 0x10]
	asrs r0, 16
	mov r8, r0
_08108472:
	ldr r0, =gUnknown_08595268
	mov r1, r10
	mov r2, r9
	ldr r3, [sp, 0x8]
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r6, r5, 16
	cmp r2, 0x40
	beq _081084DA
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r1
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x30]
	mov r1, sp
	ldrh r1, [r1, 0xC]
	strh r1, [r5, 0x32]
	mov r0, sp
	ldrh r0, [r0, 0x10]
	strh r0, [r5, 0x34]
	asrs r4, r6, 16
	adds r0, r4, 0
	movs r1, 0x40
	bl Cos
	strh r0, [r5, 0x36]
	adds r0, r4, 0
	movs r1, 0x40
	bl Sin
	strh r0, [r5, 0x38]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, 0x3A]
	movs r0, 0x2
	strh r0, [r5, 0x3C]
	ldrh r1, [r7, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081084D4
	adds r0, r5, 0
	bl sub_810851C
_081084D4:
	ldrh r0, [r7, 0xC]
	adds r0, 0x1
	strh r0, [r7, 0xC]
_081084DA:
	mov r1, r8
	lsls r0, r1, 1
	asrs r1, r6, 16
	adds r1, r0
	lsls r1, 16
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r5, r0, 16
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	asrs r0, 16
	add r0, r8
	lsls r0, 16
	lsrs r1, r0, 16
	str r1, [sp, 0x4]
	asrs r0, 16
	cmp r0, 0x13
	ble _08108472
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108408

	thumb_func_start sub_810851C
sub_810851C: @ 810851C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810852E
	cmp r0, 0x1
	beq _08108564
	b _081085BE
_0810852E:
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	movs r1, 0x6
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	ldrh r0, [r4, 0x36]
	adds r1, r0
	strh r1, [r4, 0x36]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	ldrh r2, [r4, 0x38]
	adds r1, r2
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_08108564:
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x38]
	ldrh r2, [r4, 0x34]
	adds r1, r2
	strh r1, [r4, 0x34]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r2, r1, 20
	strh r2, [r4, 0x22]
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _0810859A
	adds r1, r2, 0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _0810859A
	cmp r1, 0x78
	ble _081085BE
_0810859A:
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_081085BE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810851C

	thumb_func_start sub_81085C8
sub_81085C8: @ 81085C8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	bl sub_8108384
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08108600
	movs r0, 0x88
	strh r0, [r4, 0x10]
	movs r0, 0x28
	b _08108606
	.pool
_08108600:
	movs r0, 0x10
	strh r0, [r4, 0x10]
	movs r0, 0x50
_08108606:
	strh r0, [r4, 0x14]
	movs r0, 0x62
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0x10]
	adds r0, 0x31
	strh r0, [r4, 0x16]
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, 0x5
	strh r0, [r4, 0x20]
	ldr r0, =sub_810862C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81085C8

	thumb_func_start sub_810862C
sub_810862C: @ 810862C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r7, =gTasks
	adds r4, r0, r7
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	cmp r2, 0
	beq _08108654
	cmp r2, 0x1
	beq _08108704
	b _08108712
	.pool
_08108654:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0810866A
	strh r2, [r4, 0xC]
	adds r0, r4, 0
	bl sub_810871C
_0810866A:
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081086E4
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081086E4
	ldr r5, =gBattleAnimArgs
	movs r1, 0x1
	mov r8, r1
	mov r2, r8
	strh r2, [r5]
	strh r0, [r5, 0x2]
	movs r0, 0xC
	strh r0, [r5, 0x4]
	ldr r6, =sub_81152DC
	adds r0, r6, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081086B4
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r7
	ldr r1, [r0]
	adds r0, r2, 0
	bl _call_via_r1
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081086B4:
	movs r0, 0x3
	strh r0, [r5]
	adds r0, r6, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081086E0
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r7
	ldr r1, [r0]
	adds r0, r2, 0
	bl _call_via_r1
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081086E0:
	mov r0, r8
	strh r0, [r4, 0x22]
_081086E4:
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _08108712
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08108712
	.pool
_08108704:
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08108712
	adds r0, r1, 0
	bl move_anim_task_del
_08108712:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_810862C

	thumb_func_start sub_810871C
sub_810871C: @ 810871C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r1, =gSineTable
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r0, 0x3
	asrs r0, 4
	ldrh r2, [r4, 0x14]
	adds r0, r2
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_08595268
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _08108776
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_81087C0
	str r2, [r1]
	adds r0, r3
	strh r5, [r0, 0x38]
	strh r6, [r0, 0x3A]
	movs r1, 0x9
	strh r1, [r0, 0x3C]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
_08108776:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	ldrh r0, [r4, 0x18]
	adds r0, 0x27
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x18]
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00003039
	adds r0, r1
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl __modsi3
	ldrh r1, [r4, 0x10]
	adds r1, r0
	strh r1, [r4, 0x16]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810871C

	thumb_func_start sub_81087C0
sub_81087C0: @ 81087C0
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08108856
	ldrh r0, [r5, 0x22]
	adds r0, 0x8
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x38
	ldrsh r1, [r5, r2]
	cmp r0, r1
	blt _08108856
	ldr r2, =gTasks
	movs r3, 0x3A
	ldrsh r1, [r5, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x1C]
	ldr r0, =gUnknown_08597388
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r3, 0x22
	ldrsh r2, [r5, r3]
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x30]
	cmp r0, 0x40
	beq _08108850
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0x3
	bl StartSpriteAffineAnim
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r5, 0x3A]
	strh r1, [r0, 0x3A]
	movs r3, 0x30
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r5, 0x3C]
	strh r1, [r0, 0x3C]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_810886C
	str r1, [r0]
_08108850:
	adds r0, r5, 0
	bl DestroySprite
_08108856:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81087C0

	thumb_func_start sub_810886C
sub_810886C: @ 810886C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081088D8
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _081088D8
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_081088D8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810886C

	thumb_func_start sub_81088E4
sub_81088E4: @ 81088E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0
	strh r0, [r5, 0xE]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x10]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08108928
	movs r1, 0x1
_08108928:
	strh r1, [r5, 0x16]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810893C
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	negs r0, r0
	strh r0, [r5, 0x16]
_0810893C:
	movs r2, 0x16
	ldrsh r0, [r5, r2]
	lsls r0, 3
	ldrh r1, [r5, 0xE]
	adds r0, r1
	strh r0, [r5, 0x12]
	movs r2, 0x16
	ldrsh r1, [r5, r2]
	lsls r1, 3
	ldrh r0, [r5, 0x10]
	subs r0, r1
	strh r0, [r5, 0x14]
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x1A]
	strh r6, [r5, 0xA]
	strh r6, [r5, 0x8]
	ldr r0, =sub_8108978
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81088E4

	thumb_func_start sub_8108978
sub_8108978: @ 8108978
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bls _08108992
	b _08108AB2
_08108992:
	lsls r0, 2
	ldr r1, =_081089A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081089A4:
	.4byte _081089C0
	.4byte _081089D0
	.4byte _081089EA
	.4byte _08108A2C
	.4byte _08108A4E
	.4byte _08108A7C
	.4byte _08108AA2
_081089C0:
	adds r0, r4, 0
	bl sub_8108AC0
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08108AB8
	b _08108AAA
_081089D0:
	adds r0, r4, 0
	bl sub_8108AC0
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08108AB8
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08108AAA
_081089EA:
	adds r0, r4, 0
	bl sub_8108AC0
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	ldrh r0, [r4, 0x12]
	adds r1, r0
	movs r2, 0
	strh r1, [r4, 0x12]
	adds r1, 0x10
	lsls r1, 16
	movs r0, 0x88
	lsls r0, 17
	cmp r1, r0
	bls _08108AB8
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08108A28
	movs r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x6
	strh r0, [r4, 0x8]
	strh r2, [r4, 0xA]
	b _08108AB8
_08108A28:
	strh r2, [r4, 0xA]
	b _08108AAA
_08108A2C:
	adds r0, r4, 0
	bl sub_8108AC0
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	lsls r1, 1
	ldrh r0, [r4, 0x14]
	subs r0, r1
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _08108AB8
	b _08108AAA
_08108A4E:
	adds r0, r4, 0
	bl sub_8108AC0
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	ldrh r0, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x12]
	adds r0, 0x10
	lsls r0, 16
	movs r1, 0x88
	lsls r1, 17
	cmp r0, r1
	bls _08108AB8
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08108AAA
_08108A7C:
	adds r0, r4, 0
	bl sub_8108AC0
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	lsls r1, 1
	ldrh r0, [r4, 0x14]
	subs r0, r1
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _08108AB8
	movs r0, 0x2
	strh r0, [r4, 0x8]
	b _08108AB8
_08108AA2:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08108AB8
_08108AAA:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08108AB8
_08108AB2:
	adds r0, r2, 0
	bl move_anim_task_del
_08108AB8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8108978

	thumb_func_start sub_8108AC0
sub_8108AC0: @ 8108AC0
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08108B1A
	movs r0, 0
	strh r0, [r6, 0xC]
	ldr r0, =gUnknown_08595268
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	movs r3, 0x10
	ldrsh r2, [r6, r3]
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08108B1A
	ldr r5, =gSprites
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	movs r1, 0x10
	strh r1, [r0, 0x2E]
	ldrh r1, [r6, 0x12]
	strh r1, [r0, 0x32]
	ldrh r1, [r6, 0x14]
	strh r1, [r0, 0x36]
	ldrh r1, [r6, 0x1A]
	strh r1, [r0, 0x38]
	bl sub_80A68D4
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_8108B2C
	str r0, [r4]
	ldrh r0, [r6, 0x18]
	adds r0, 0x1
	strh r0, [r6, 0x18]
_08108B1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108AC0

	thumb_func_start sub_8108B2C
sub_8108B2C: @ 8108B2C
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08108B86
	ldrh r0, [r6, 0x24]
	ldrh r1, [r6, 0x20]
	adds r0, r1
	strh r0, [r6, 0x20]
	ldrh r0, [r6, 0x26]
	ldrh r1, [r6, 0x22]
	adds r0, r1
	strh r0, [r6, 0x22]
	movs r0, 0x6
	strh r0, [r6, 0x2E]
	bl Random2
	movs r4, 0x1F
	adds r1, r4, 0
	ands r1, r0
	ldr r5, =0x0000fff0
	adds r1, r5
	ldrh r0, [r6, 0x20]
	adds r1, r0
	strh r1, [r6, 0x32]
	bl Random2
	ands r4, r0
	adds r4, r5
	ldrh r1, [r6, 0x22]
	adds r4, r1
	strh r4, [r6, 0x36]
	bl Random2
	movs r1, 0x7
	ands r1, r0
	mvns r1, r1
	strh r1, [r6, 0x38]
	adds r0, r6, 0
	bl sub_80A68D4
	ldr r0, =sub_8108B94
	str r0, [r6, 0x1C]
_08108B86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108B2C

	thumb_func_start sub_8108B94
sub_8108B94: @ 8108B94
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08108BD0
	movs r4, 0
	ldr r6, =gTasks
_08108BA6:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r6
	ldr r1, [r2]
	ldr r0, =sub_8108978
	cmp r1, r0
	bne _08108BC6
	movs r0, 0x1
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0x18]
	subs r0, 0x1
	strh r0, [r2, 0x18]
	adds r0, r5, 0
	bl DestroySprite
_08108BC6:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xF
	bls _08108BA6
_08108BD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108B94

	thumb_func_start sub_8108BE0
sub_8108BE0: @ 8108BE0
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0x20]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x22]
	ldrh r1, [r2, 0x4]
	strh r1, [r0, 0x2E]
	ldrh r1, [r2, 0x6]
	strh r1, [r0, 0x30]
	ldrh r1, [r2, 0x8]
	strh r1, [r0, 0x32]
	ldrh r1, [r2, 0xA]
	strh r1, [r0, 0x34]
	ldr r1, =sub_8108C08
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8108BE0

	thumb_func_start sub_8108C08
sub_8108C08: @ 8108C08
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x2E]
	subs r0, r1
	strh r0, [r4, 0x36]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl __divsi3
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x38]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	subs r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _08108C4C
	adds r0, r4, 0
	bl move_anim_8072740
_08108C4C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8108C08

	thumb_func_start sub_8108C54
sub_8108C54: @ 8108C54
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r1, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r1, r2
	strh r1, [r4, 0x36]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r4, 0x24]
	lsls r1, 16
	asrs r1, 23
	strh r1, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _08108C8C
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_08108C8C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8108C54

	thumb_func_start sub_8108C94
sub_8108C94: @ 8108C94
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x30]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x34]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldr r0, =sub_8108CDC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108C94

	thumb_func_start sub_8108CDC
sub_8108CDC: @ 8108CDC
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	subs r5, r1, r0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	muls r0, r6
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl __divsi3
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	muls r0, r5
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl __divsi3
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08108D34
	movs r0, 0
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8108D54
_08108D34:
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08108D46
	adds r0, r4, 0
	bl move_anim_8072740
_08108D46:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8108CDC

	thumb_func_start sub_8108D54
sub_8108D54: @ 8108D54
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r4, r1, 0
	adds r5, r2, 0
	movs r2, 0x2E
	ldrsh r1, [r0, r2]
	lsrs r2, r1, 31
	adds r1, r2
	lsls r1, 15
	lsrs r1, 16
	str r1, [sp]
	ldrh r1, [r0, 0x24]
	ldrh r3, [r0, 0x20]
	adds r1, r3
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	ldrh r1, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r0, r5, r0
	subs r0, 0x5
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	bl Random2
	negs r4, r4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r4, r0
	subs r4, 0x5
	lsls r4, 16
	lsrs r7, r4, 16
	movs r6, 0
	mov r0, r8
	lsls r0, 16
	mov r8, r0
	mov r1, r10
	lsls r1, 16
	str r1, [sp, 0xC]
	ldr r2, [sp]
	lsls r2, 16
	str r2, [sp, 0x10]
	asrs r1, 16
	lsls r0, r7, 16
	asrs r5, r0, 16
	str r0, [sp, 0x14]
	negs r3, r5
	str r3, [sp, 0x4]
	asrs r0, r2, 16
	adds r1, r0
	lsls r1, 16
	mov r10, r1
_08108DE2:
	ldr r0, =gUnknown_08595310
	mov r2, r8
	asrs r1, r2, 16
	mov r3, r10
	asrs r2, r3, 16
	movs r3, 0x82
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r1
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	mov r0, r9
	strh r0, [r4, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	cmp r5, 0
	bge _08108E30
	mov r1, sp
	ldrh r1, [r1, 0x4]
	strh r1, [r4, 0x32]
	b _08108E32
	.pool
_08108E30:
	strh r7, [r4, 0x32]
_08108E32:
	lsls r0, r6, 16
	movs r2, 0x80
	lsls r2, 9
	adds r0, r2
	lsrs r6, r0, 16
	cmp r0, 0
	ble _08108DE2
	movs r6, 0
	ldr r3, [sp, 0xC]
	asrs r1, r3, 16
	ldr r0, [sp, 0x14]
	asrs r5, r0, 16
	negs r2, r5
	str r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	asrs r0, r3, 16
	subs r1, r0
	lsls r1, 16
	mov r10, r1
_08108E58:
	ldr r0, =gUnknown_08595310
	mov r2, r8
	asrs r1, r2, 16
	mov r3, r10
	asrs r2, r3, 16
	movs r3, 0x82
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r1
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	mov r0, r9
	strh r0, [r4, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	cmp r5, 0
	ble _08108EA8
	mov r1, sp
	ldrh r1, [r1, 0x8]
	strh r1, [r4, 0x32]
	b _08108EAA
	.pool
_08108EA8:
	strh r7, [r4, 0x32]
_08108EAA:
	lsls r0, r6, 16
	movs r2, 0x80
	lsls r2, 9
	adds r0, r2
	lsrs r6, r0, 16
	cmp r0, 0
	ble _08108E58
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8108D54

	thumb_func_start sub_8108EC8
sub_8108EC8: @ 8108EC8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x2E]
	movs r0, 0x3C
	strh r0, [r4, 0x30]
	movs r0, 0x9
	strh r0, [r4, 0x32]
	movs r0, 0x1E
	strh r0, [r4, 0x34]
	movs r0, 0xFE
	lsls r0, 8
	strh r0, [r4, 0x36]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A634C
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108EC8

	thumb_func_start sub_8108F08
sub_8108F08: @ 8108F08
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x32]
	ldr r0, =sub_80A656C
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108F08

	thumb_func_start sub_8108F4C
sub_8108F4C: @ 8108F4C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08108F88
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x8]
	negs r0, r0
	strh r0, [r4, 0x32]
	adds r1, r2, 0
	b _08108F9E
	.pool
_08108F88:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
_08108F9E:
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8109028
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108F4C

	thumb_func_start sub_8108FBC
sub_8108FBC: @ 8108FBC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08108FF0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x8]
	strh r0, [r4, 0x32]
	adds r1, r2, 0
	b _08109008
	.pool
_08108FF0:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x8]
	negs r0, r0
	strh r0, [r4, 0x32]
_08109008:
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8109028
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8108FBC

	thumb_func_start sub_8109028
sub_8109028: @ 8109028
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bge _0810904E
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x34]
	ldrh r3, [r2, 0x26]
	adds r0, r3
	strh r0, [r2, 0x26]
_0810904E:
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08109060
	adds r0, r2, 0
	bl move_anim_8074EE0
_08109060:
	pop {r0}
	bx r0
	thumb_func_end sub_8109028

	thumb_func_start sub_8109064
sub_8109064: @ 8109064
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08109090
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r4, 0x20]
	b _081090A2
	.pool
_08109090:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	adds r2, r4, 0
	adds r2, 0x43
	movs r1, 0x8
	strb r1, [r2]
_081090A2:
	adds r2, r0, 0
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x22]
	ldrh r0, [r2, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r2, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r2, 0x8]
	strh r0, [r4, 0x32]
	ldrh r0, [r2, 0xA]
	strh r0, [r4, 0x34]
	ldrh r0, [r2, 0xC]
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldr r0, =sub_81090D8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109064

	thumb_func_start sub_81090D8
sub_81090D8: @ 81090D8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08109160
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	ldr r0, =0x00002710
	cmp r1, r0
	ble _081090F6
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081090F6:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 24
	ldrh r2, [r4, 0x30]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 24
	ldrh r2, [r4, 0x30]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x2E]
	adds r1, r0, r2
	strh r1, [r4, 0x2E]
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x38]
	adds r0, r2
	strh r0, [r4, 0x38]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _0810914C
	ldr r2, =0xffffff00
	b _08109154
	.pool
_0810914C:
	cmp r0, 0
	bge _08109158
	movs r2, 0x80
	lsls r2, 1
_08109154:
	adds r0, r1, r2
	strh r0, [r4, 0x2E]
_08109158:
	ldrh r0, [r4, 0x34]
	subs r0, 0x1
	strh r0, [r4, 0x34]
	b _08109166
_08109160:
	adds r0, r4, 0
	bl move_anim_8074EE0
_08109166:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81090D8

	thumb_func_start sub_810916C
sub_810916C: @ 810916C
	push {lr}
	movs r1, 0
	strh r1, [r0, 0x20]
	strh r1, [r0, 0x22]
	movs r1, 0x3C
	strh r1, [r0, 0x2E]
	movs r1, 0x8C
	strh r1, [r0, 0x32]
	movs r1, 0x50
	strh r1, [r0, 0x36]
	ldr r1, =sub_80A6EEC
	str r1, [r0, 0x1C]
	ldr r1, =move_anim_8072740
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810916C

	thumb_func_start sub_8109198
sub_8109198: @ 8109198
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _081091DE
	movs r0, 0x2
	bl GetBankByPlayerAI
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _081091D6
	movs r0, 0x3
	bl GetBankByPlayerAI
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081091DE
_081091D6:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_081091DE:
	ldr r1, =sub_80A7938
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109198

	thumb_func_start sub_8109200
sub_8109200: @ 8109200
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	negs r1, r1
	strh r1, [r2]
	ldrh r1, [r2, 0x4]
	negs r1, r1
	strh r1, [r2, 0x4]
	ldr r1, =sub_80A7938
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_8109200

	thumb_func_start sub_810921C
sub_810921C: @ 810921C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	movs r1, 0
	strh r0, [r4, 0x3C]
	strh r1, [r4, 0x2E]
	ldr r0, =sub_8109244
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810921C

	thumb_func_start sub_8109244
sub_8109244: @ 8109244
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8109338
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x12
	bne _0810928E
	movs r0, 0x19
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_810929C
	str r0, [r5, 0x1C]
_0810928E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109244

	thumb_func_start sub_810929C
sub_810929C: @ 810929C
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _081092E4
	movs r4, 0
	strh r4, [r6, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	strh r4, [r6, 0x26]
	strh r4, [r6, 0x24]
	ldr r1, =sub_8109314
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
	b _0810930E
	.pool
_081092E4:
	movs r1, 0x3C
	ldrsh r0, [r6, r1]
	movs r1, 0x1C
	bl Sin
	ldrh r1, [r6, 0x24]
	adds r0, r1
	strh r0, [r6, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r6, r1]
	movs r1, 0x1C
	bl Cos
	ldrh r1, [r6, 0x26]
	adds r0, r1
	strh r0, [r6, 0x26]
	ldrh r0, [r6, 0x3C]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6, 0x3C]
_0810930E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810929C

	thumb_func_start sub_8109314
sub_8109314: @ 8109314
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8109338
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08109330
	adds r0, r4, 0
	bl move_anim_8072740
_08109330:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109314

	thumb_func_start sub_8109338
sub_8109338: @ 8109338
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x1C
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x1C
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x14
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109338

	thumb_func_start sub_8109364
sub_8109364: @ 8109364
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A653C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109364

	thumb_func_start sub_81093A4
sub_81093A4: @ 81093A4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x2E]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_81093E4
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81093A4

	thumb_func_start sub_81093E4
sub_81093E4: @ 81093E4
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r3]
	ldrh r1, [r0, 0x30]
	movs r2, 0
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	ldr r1, =sub_810940C
	str r1, [r0, 0x1C]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81093E4

	thumb_func_start sub_810940C
sub_810940C: @ 810940C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	adds r0, 0xD0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08109458
	adds r0, r4, 0
	bl move_anim_8072740
_08109458:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810940C

	thumb_func_start sub_8109460
sub_8109460: @ 8109460
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0x26]
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x10]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_81094D0
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109460

	thumb_func_start sub_81094D0
sub_81094D0: @ 81094D0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bls _081094EC
	b _081097AA
_081094EC:
	lsls r0, 2
	ldr r1, =_08109500
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08109500:
	.4byte _0810951C
	.4byte _08109542
	.4byte _081095F4
	.4byte _08109654
	.4byte _08109672
	.4byte _08109748
	.4byte _0810979C
_0810951C:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 1
	movs r0, 0xE0
	str r0, [sp]
	movs r0, 0x80
	lsls r0, 2
	str r0, [sp, 0x4]
	movs r0, 0x20
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r2, r3, 0
	bl sub_80A805C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08109542:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810958A
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109578
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	b _08109588
	.pool
_08109578:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffd
_08109588:
	strh r1, [r0, 0x24]
_0810958A:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081095B8
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _081095B8
	movs r0, 0
	strh r0, [r4, 0xE]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x1
	strh r1, [r0, 0x22]
_081095B8:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _081095C8
	b _081097AA
_081095C8:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7E6C
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	b _08109790
	.pool
_081095F4:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _08109604
	b _081097AA
_08109604:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810962E
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 2
	movs r0, 0xC0
	lsls r0, 1
	str r0, [sp]
	movs r0, 0xF0
	str r0, [sp, 0x4]
	movs r0, 0x6
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0xE0
	bl sub_80A805C
	b _0810964E
_0810962E:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0x80
	lsls r3, 2
	movs r0, 0xC0
	lsls r0, 1
	str r0, [sp]
	movs r0, 0xC0
	str r0, [sp, 0x4]
	movs r0, 0x6
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r2, 0xE0
	bl sub_80A805C
_0810964E:
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08109790
_08109654:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	cmp r0, 0
	beq _08109662
	b _081097AA
_08109662:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_81097B4
	b _08109790
_08109672:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081096C0
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081096AC
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	b _081096BE
	.pool
_081096AC:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
_081096BE:
	strh r1, [r0, 0x26]
_081096C0:
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	ble _081097AA
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081096FC
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xC0
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r3, 0xF0
	bl sub_80A805C
	b _0810971A
	.pool
_081096FC:
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xC0
	lsls r2, 1
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r3, 0xC0
	bl sub_80A805C
_0810971A:
	ldrh r1, [r4, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109738
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
_08109738:
	movs r0, 0
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	b _08109790
	.pool
_08109748:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08109764
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x1
	strh r1, [r0, 0x22]
_08109764:
	adds r0, r4, 0
	bl sub_80A80C8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081097AA
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x10]
	strh r1, [r0, 0x22]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	strh r5, [r4, 0xC]
_08109790:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081097AA
	.pool
_0810979C:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081097AA
	adds r0, r5, 0
	bl move_anim_task_del
_081097AA:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81094D0

	thumb_func_start sub_81097B4
sub_81097B4: @ 81097B4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	adds r0, r4, 0
	bl sub_8109930
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r4, [r0, 0x20]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810980C
	adds r0, r4, 0
	subs r0, 0xC
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	b _08109816
	.pool
_0810980C:
	adds r0, r4, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0xFF
_08109816:
	movs r6, 0
	movs r5, 0
	lsls r4, 16
	str r4, [sp, 0x8]
	mov r1, r9
	lsls r1, 16
	str r1, [sp, 0x4]
	ldr r2, =gUnknown_085955CC
	mov r9, r2
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r3, r8
	lsls r3, 1
	mov r10, r3
_08109834:
	ldr r0, =gUnknown_085955B4
	ldr r2, [sp, 0x8]
	asrs r1, r2, 16
	ldr r3, [sp, 0x4]
	asrs r2, r3, 16
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081098B6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r1
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	lsls r0, r5, 2
	adds r0, 0x40
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r3, =0xfffffc00
	adds r0, r3, 0
	ands r2, r0
	orrs r2, r1
	strh r2, [r4, 0x4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x4
	bls _0810987E
	movs r5, 0
_0810987E:
	lsls r2, r6, 2
	mov r1, r9
	adds r0, r2, r1
	ldrh r0, [r0]
	ldr r3, [sp]
	adds r1, r0, 0
	muls r1, r3
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_085955CE
	adds r2, r0
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r0, r4, 0
	bl sub_8109984
	strh r7, [r4, 0x3A]
	mov r0, r8
	strh r0, [r4, 0x3C]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	add r0, r10
	ldr r1, =gTasks + 0x8
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
_081098B6:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x6
	bls _08109834
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81097B4

	thumb_func_start sub_81098EC
sub_81098EC: @ 81098EC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81099A0
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08109926
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_08109926:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81098EC

	thumb_func_start sub_8109930
sub_8109930: @ 8109930
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x26]
	ldrh r0, [r1, 0x22]
	adds r2, r0
	adds r1, 0x29
	movs r0, 0
	ldrsb r0, [r1, r0]
	adds r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08109970
	lsls r0, r4, 16
	movs r1, 0x94
	lsls r1, 15
	b _08109976
	.pool
_08109970:
	lsls r0, r4, 16
	movs r1, 0xB0
	lsls r1, 14
_08109976:
	adds r0, r1
	lsrs r4, r0, 16
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8109930

	thumb_func_start sub_8109984
sub_8109984: @ 8109984
	movs r3, 0
	strh r3, [r0, 0x2E]
	strh r3, [r0, 0x30]
	ldrh r3, [r0, 0x20]
	lsls r3, 3
	strh r3, [r0, 0x32]
	ldrh r3, [r0, 0x22]
	lsls r3, 3
	strh r3, [r0, 0x34]
	lsls r1, 3
	strh r1, [r0, 0x36]
	lsls r2, 3
	strh r2, [r0, 0x38]
	bx lr
	thumb_func_end sub_8109984

	thumb_func_start sub_81099A0
sub_81099A0: @ 81099A0
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _081099CA
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0
	muls r1, r0
	adds r0, r1, 0
	ldrh r3, [r2, 0x34]
	adds r0, r3
	strh r0, [r2, 0x34]
_081099CA:
	ldrh r0, [r2, 0x36]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r2, 0x20]
	ldrh r1, [r2, 0x38]
	ldrh r3, [r2, 0x34]
	adds r1, r3
	strh r1, [r2, 0x34]
	lsls r1, 16
	asrs r3, r1, 19
	strh r3, [r2, 0x22]
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _08109A00
	adds r1, r3, 0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _08109A00
	cmp r1, 0x78
	ble _08109A0C
_08109A00:
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08109A0C:
	pop {r0}
	bx r0
	thumb_func_end sub_81099A0

	thumb_func_start sub_8109A10
sub_8109A10: @ 8109A10
	push {r4,r5,lr}
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3]
	movs r2, 0
	strh r1, [r0, 0x20]
	ldrh r1, [r3, 0x2]
	strh r1, [r0, 0x22]
	strh r2, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	ldrh r1, [r3, 0x4]
	strh r1, [r0, 0x3A]
	ldrh r1, [r3, 0x6]
	strh r1, [r0, 0x3C]
	ldrh r4, [r0, 0x4]
	lsls r2, r4, 22
	lsrs r2, 22
	movs r5, 0x8
	ldrsh r1, [r3, r5]
	lsls r1, 4
	adds r2, r1
	ldr r3, =0x000003ff
	adds r1, r3, 0
	ands r2, r1
	ldr r1, =0xfffffc00
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r1, =sub_8109A64
	str r1, [r0, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109A10

	thumb_func_start sub_8109A64
sub_8109A64: @ 8109A64
	push {r4,lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _08109A96
	cmp r0, 0x1
	bgt _08109A7A
	cmp r0, 0
	beq _08109A80
	b _08109AF4
_08109A7A:
	cmp r0, 0x2
	beq _08109AB4
	b _08109AF4
_08109A80:
	ldrh r1, [r2, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08109A90
	subs r0, r1, 0x1
	strh r0, [r2, 0x3A]
	b _08109AF4
_08109A90:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
_08109A96:
	ldrh r0, [r2, 0x22]
	adds r0, 0x8
	strh r0, [r2, 0x22]
	lsls r0, 16
	asrs r0, 16
	ldrh r3, [r2, 0x3C]
	movs r4, 0x3C
	ldrsh r1, [r2, r4]
	cmp r0, r1
	blt _08109AF4
	strh r3, [r2, 0x22]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _08109AF4
_08109AB4:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109AE0
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109ADC
	ldr r0, =0x0000fffd
	b _08109ADE
	.pool
_08109ADC:
	movs r0, 0x3
_08109ADE:
	strh r0, [r2, 0x26]
_08109AE0:
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08109AF4
	adds r0, r2, 0
	bl move_anim_8072740
_08109AF4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109A64

	thumb_func_start sub_8109AFC
sub_8109AFC: @ 8109AFC
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08109B70
	cmp r0, 0x1
	bgt _08109B12
	cmp r0, 0
	beq _08109B18
	b _08109C3E
_08109B12:
	cmp r0, 0x2
	beq _08109BCE
	b _08109C3E
_08109B18:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x3C]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08109B48
	movs r0, 0x4
	b _08109B4A
	.pool
_08109B48:
	ldr r0, =0x0000fffc
_08109B4A:
	strh r0, [r5, 0x36]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _08109BC6
	.pool
_08109B70:
	ldrh r0, [r5, 0x30]
	adds r0, 0xC0
	strh r0, [r5, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08109B94
	ldrh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	b _08109B9A
	.pool
_08109B94:
	ldrh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 24
_08109B9A:
	strh r0, [r5, 0x26]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08109C3E
	movs r0, 0
	strh r0, [r5, 0x34]
_08109BC6:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08109C3E
_08109BCE:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	bl Sin
	adds r2, r0, 0
	movs r3, 0
	strh r2, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08109C3E
	ldrh r0, [r5, 0x20]
	adds r1, r2, r0
	strh r1, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r3, [r5, 0x26]
	strh r3, [r5, 0x24]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x2E]
	strh r1, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A6FD4
	ldr r0, =sub_8109C4C
	str r0, [r5, 0x1C]
_08109C3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109AFC

	thumb_func_start sub_8109C4C
sub_8109C4C: @ 8109C4C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _08109CA4
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0x10
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x38]
	adds r0, r2, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x38]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _08109C82
	cmp r2, 0xC4
	ble _08109CAA
_08109C82:
	lsls r0, 16
	cmp r0, 0
	ble _08109CAA
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08109CAA
	ldr r0, =gUnknown_02038440
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0x90
	bl PlaySE12WithPanning
	b _08109CAA
	.pool
_08109CA4:
	adds r0, r4, 0
	bl move_anim_8072740
_08109CAA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109C4C

	thumb_func_start sub_8109CB0
sub_8109CB0: @ 8109CB0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08109CC8
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x30]
	adds r0, r1, 0x1
	strh r0, [r4, 0x2E]
_08109CC8:
	movs r0, 0xC0
	lsls r0, 1
	adds r1, r0, 0
	ldrh r2, [r4, 0x34]
	adds r1, r2
	strh r1, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0xA0
	strh r0, [r4, 0x36]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x36]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x7
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08109D64
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x83
	bls _08109D3C
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	b _08109D80
	.pool
_08109D3C:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	b _08109D80
	.pool
_08109D64:
	ldrh r0, [r4, 0x30]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x83
	bls _08109D78
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1D
	b _08109D7E
_08109D78:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1F
_08109D7E:
	strb r0, [r1]
_08109D80:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08109DA8
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08109DA8:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x1E
	bne _08109DB6
	adds r0, r4, 0
	bl move_anim_8072740
_08109DB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8109CB0

	thumb_func_start sub_8109DBC
sub_8109DBC: @ 8109DBC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08109DE2
	movs r1, 0x1
_08109DE2:
	strh r1, [r4, 0x20]
	ldr r0, =gAnimationBankTarget
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x24]
	movs r0, 0x3
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_8109E2C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109DBC

	thumb_func_start sub_8109E2C
sub_8109E2C: @ 8109E2C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r2, r0, r1
	movs r0, 0x8
	ldrsh r3, [r2, r0]
	cmp r3, 0x1
	beq _08109EF4
	cmp r3, 0x1
	bgt _08109E54
	cmp r3, 0
	beq _08109E62
	b _0810A054
	.pool
_08109E54:
	cmp r3, 0x2
	bne _08109E5A
	b _08109F7C
_08109E5A:
	cmp r3, 0x3
	bne _08109E60
	b _0810A010
_08109E60:
	b _0810A054
_08109E62:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	lsls r0, 1
	ldrh r5, [r2, 0x1C]
	adds r0, r5
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109E94
	strh r3, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109E90
	movs r0, 0x2
	b _08109E92
_08109E90:
	ldr r0, =0x0000fffe
_08109E92:
	strh r0, [r2, 0x1E]
_08109E94:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r7, 0x22
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _08109ED6
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109EA6:
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r7, [r2, 0x1C]
	adds r0, r7
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x22
	ldrsh r1, [r2, r5]
	cmp r0, r1
	blt _08109EA6
_08109ED6:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	beq _08109EE6
	b _0810A054
_08109EE6:
	movs r0, 0
	strh r0, [r2, 0x1A]
	b _0810A000
	.pool
_08109EF4:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08109F1C
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	ands r0, r3
	lsls r0, 16
	cmp r0, 0
	beq _08109F18
	movs r0, 0x2
	b _08109F1A
_08109F18:
	ldr r0, =0x0000fffe
_08109F1A:
	strh r0, [r2, 0x1E]
_08109F1C:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r7, 0x22
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _08109F5E
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109F2E:
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r5, 0
	ldrsh r0, [r0, r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r7, [r2, 0x1C]
	adds r0, r7
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r5, 0x22
	ldrsh r1, [r2, r5]
	cmp r0, r1
	blt _08109F2E
_08109F5E:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x60
	bne _0810A054
	movs r0, 0
	strh r0, [r2, 0x1A]
	b _0810A000
	.pool
_08109F7C:
	movs r7, 0x20
	ldrsh r1, [r2, r7]
	lsls r1, 1
	ldrh r0, [r2, 0x1C]
	subs r0, r1
	strh r0, [r2, 0x1C]
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08109FB0
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08109FAC
	strh r3, [r2, 0x1E]
	b _08109FB0
_08109FAC:
	ldr r0, =0x0000fffe
	strh r0, [r2, 0x1E]
_08109FB0:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _08109FF2
	ldr r4, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
_08109FC2:
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r7, 0
	ldrsh r0, [r0, r7]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r2, 0x1E]
	ldrh r5, [r2, 0x1C]
	adds r0, r5
	strh r0, [r1, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r7, 0x22
	ldrsh r1, [r2, r7]
	cmp r0, r1
	blt _08109FC2
_08109FF2:
	ldrh r0, [r2, 0x1A]
	adds r0, 0x1
	strh r0, [r2, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0810A054
_0810A000:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _0810A054
	.pool
_0810A010:
	movs r1, 0
	strh r1, [r2, 0xE]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _0810A04E
	ldr r6, =gSprites
	adds r3, r2, 0
	adds r3, 0x8
	movs r5, 0
_0810A024:
	movs r7, 0xE
	ldrsh r0, [r2, r7]
	adds r0, 0xE
	lsls r0, 1
	adds r0, r3, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r5, [r0, 0x24]
	ldrh r0, [r2, 0xE]
	adds r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	asrs r0, 16
	movs r7, 0x22
	ldrsh r1, [r2, r7]
	cmp r0, r1
	blt _0810A024
_0810A04E:
	adds r0, r4, 0
	bl move_anim_task_del
_0810A054:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8109E2C

	thumb_func_start sub_810A060
sub_810A060: @ 810A060
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x8]
	lsls r0, 4
	ldr r1, =gBattleAnimArgs
	ldrb r2, [r1]
	ldrh r3, [r1, 0x2]
	movs r1, 0x10
	bl BlendPalette
	adds r0, r4, 0
	bl move_anim_task_del
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A060

	thumb_func_start sub_810A094
sub_810A094: @ 810A094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	mov r9, r1
	ldr r4, =gBattleAnimArgs
	mov r8, r4
	cmp r0, 0
	bne _0810A0CA
	ldrh r0, [r4]
	strh r0, [r2, 0xA]
	ldrh r0, [r4, 0x2]
	strh r0, [r2, 0xC]
	ldrh r0, [r4, 0x4]
	strh r0, [r2, 0xE]
	ldrh r0, [r4, 0x6]
	strh r0, [r2, 0x10]
_0810A0CA:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r6, [r0]
	movs r5, 0x10
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne _0810A100
	ldr r4, =gUnknown_08595684
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	b _0810A106
	.pool
_0810A100:
	ldr r4, =gUnknown_08595694
	movs r3, 0x8
	ldrsh r0, [r2, r3]
_0810A106:
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	adds r0, r4
	ldrb r5, [r0]
	lsls r0, r7, 2
	adds r1, r0, r7
	lsls r1, 3
	add r1, r9
	movs r4, 0xE
	ldrsh r1, [r1, r4]
	mov r12, r0
	cmp r1, 0x1
	bne _0810A154
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	mov r10, r0
	mov r0, r8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	lsls r0, r5, 24
	asrs r0, 24
	muls r0, r1
	cmp r0, 0
	bge _0810A144
	negs r0, r0
_0810A144:
	mov r5, r10
	strh r0, [r5, 0x26]
	b _0810A16E
	.pool
_0810A154:
	ldr r3, =gSprites
	lsls r4, r6, 4
	adds r2, r4, r6
	lsls r2, 2
	adds r2, r3
	lsls r0, r5, 24
	asrs r0, 24
	mov r5, r8
	ldrh r1, [r5, 0x2]
	muls r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
_0810A16E:
	mov r1, r12
	adds r0, r1, r7
	lsls r0, 3
	add r0, r9
	movs r4, 0x8
	ldrsh r1, [r0, r4]
	movs r5, 0xA
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _0810A194
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	bl move_anim_task_del
_0810A194:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A094

	thumb_func_start sub_810A1A8
sub_810A1A8: @ 810A1A8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810A1D0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r4, 0x20]
	b _0810A1DC
	.pool
_0810A1D0:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	adds r0, r1, 0
_0810A1DC:
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =sub_810A1F8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A1A8

	thumb_func_start sub_810A1F8
sub_810A1F8: @ 810A1F8
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810A20E
	adds r0, r2, 0
	bl move_anim_8072740
_0810A20E:
	pop {r0}
	bx r0
	thumb_func_end sub_810A1F8

	thumb_func_start sub_810A214
sub_810A214: @ 810A214
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810A23C
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r0, [r0]
	subs r1, r0
	strh r1, [r4, 0x20]
	b _0810A246
	.pool
_0810A23C:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
_0810A246:
	ldr r0, =sub_810A258
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A214

	thumb_func_start sub_810A258
sub_810A258: @ 810A258
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810A26E
	adds r0, r2, 0
	bl move_anim_8074EE0
_0810A26E:
	pop {r0}
	bx r0
	thumb_func_end sub_810A258

	thumb_func_start sub_810A274
sub_810A274: @ 810A274
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810A2C4
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r5, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	ldrh r1, [r2, 0x2]
	subs r0, r1
	strh r0, [r5, 0x22]
	b _0810A2D8
	.pool
_0810A2C4:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r5, 0x20]
	adds r1, r2
	strh r1, [r5, 0x20]
	ldrh r1, [r0, 0x2]
	ldrh r2, [r5, 0x22]
	adds r1, r2
	strh r1, [r5, 0x22]
	adds r2, r0, 0
_0810A2D8:
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldrh r0, [r2, 0x4]
	strh r0, [r5, 0x30]
	ldrh r0, [r2, 0x6]
	strh r0, [r5, 0x32]
	ldrh r0, [r2, 0x8]
	strh r0, [r5, 0x34]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A62EC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A274

	thumb_func_start sub_810A308
sub_810A308: @ 810A308
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _0810A380
	cmp r0, 0x1
	bgt _0810A324
	cmp r0, 0
	beq _0810A32E
	b _0810A380
	.pool
_0810A324:
	cmp r0, 0x2
	beq _0810A338
	cmp r0, 0x3
	beq _0810A35C
	b _0810A380
_0810A32E:
	ldr r0, =gAnimationBankAttacker
	b _0810A382
	.pool
_0810A338:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r6, 0x2
	eors r0, r6
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _0810A354
	ldrb r4, [r4]
	b _0810A384
	.pool
_0810A354:
	ldrb r0, [r4]
	adds r4, r6, 0
	eors r4, r0
	b _0810A384
_0810A35C:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r4, 0x2
	eors r0, r4
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810A380
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	eors r4, r0
	b _0810A384
	.pool
_0810A380:
	ldr r0, =gAnimationBankTarget
_0810A382:
	ldrb r4, [r0]
_0810A384:
	ldr r0, =gBattleAnimArgs
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0810A3AC
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	movs r1, 0x1
	b _0810A3BE
	.pool
_0810A3AC:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	movs r1, 0x3
_0810A3BE:
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r7, =gSineTable
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	muls r0, r1
	asrs r0, 8
	strh r0, [r5, 0x24]
	movs r1, 0
	ldrsh r0, [r6, r1]
	adds r0, 0x40
	lsls r0, 1
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	muls r0, r1
	asrs r0, 8
	strh r0, [r5, 0x26]
	ldrh r1, [r6, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810A422
	adds r0, r4, 0
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r5, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
_0810A422:
	ldrb r2, [r5, 0x3]
	lsls r2, 26
	lsrs r2, 27
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	ldr r3, =gOamMatrices
	lsls r2, 3
	adds r2, r3
	adds r1, 0x40
	lsls r1, 1
	adds r1, r7
	ldrh r1, [r1]
	strh r1, [r2, 0x6]
	strh r1, [r2]
	strh r0, [r2, 0x2]
	lsls r0, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r2, 0x4]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_810E2C8
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A308

	thumb_func_start sub_810A46C
sub_810A46C: @ 810A46C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x38]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x3A]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x3C]
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	lsls r0, 2
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r1, =sub_810A4F4
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A46C

	thumb_func_start sub_810A4F4
sub_810A4F4: @ 810A4F4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _0810A55E
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0810A564
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _0810A564
_0810A55E:
	adds r0, r4, 0
	bl move_anim_8072740
_0810A564:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810A4F4

	thumb_func_start sub_810A56C
sub_810A56C: @ 810A56C
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x38]
	subs r0, 0x1
	strh r0, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810A5A4
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x36]
	strh r0, [r3, 0x38]
_0810A5A4:
	ldrh r0, [r3, 0x34]
	subs r1, r0, 0x1
	strh r1, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bgt _0810A5B6
	adds r0, r3, 0
	bl move_anim_8072740
_0810A5B6:
	pop {r0}
	bx r0
	thumb_func_end sub_810A56C

	thumb_func_start sub_810A5BC
sub_810A5BC: @ 810A5BC
	push {r4-r6,lr}
	adds r6, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810A5D8
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810A5E0
_0810A5D8:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
_0810A5E0:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x22]
	ldrh r0, [r4]
	strh r0, [r6, 0x34]
	ldrh r0, [r4, 0x6]
	strh r0, [r6, 0x36]
	strh r0, [r6, 0x38]
	ldr r0, =sub_810A56C
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A5BC

	thumb_func_start sub_810A628
sub_810A628: @ 810A628
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x2E]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810A64C
	ldr r0, =gAnimationBankTarget
	b _0810A64E
	.pool
_0810A64C:
	ldr r0, =gAnimationBankAttacker
_0810A64E:
	ldrb r6, [r0]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810A666
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810A66E
_0810A666:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810A66E:
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r3, [r4]
	adds r0, r3
	strh r0, [r5, 0x20]
	adds r0, r6, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldrh r1, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r5, 0x36]
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x38]
	ldrh r0, [r4, 0xA]
	strh r0, [r5, 0x3A]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x3C]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r1, =sub_810A6EC
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A628

	thumb_func_start sub_810A6EC
sub_810A6EC: @ 810A6EC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _0810A742
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810A742:
	ldrh r0, [r4, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _0810A754
	adds r0, r4, 0
	bl move_anim_8072740
_0810A754:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810A6EC

	thumb_func_start sub_810A75C
sub_810A75C: @ 810A75C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A6980
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	ldr r3, =gBattleAnimArgs
	movs r5, 0x6
	ldrsh r0, [r3, r5]
	lsls r0, 2
	adds r1, r0
	ldr r5, =0x000003ff
	adds r0, r5, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	bne _0810A7A4
	ldrb r0, [r4, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	b _0810A7B2
	.pool
_0810A7A4:
	cmp r0, 0x2
	bne _0810A7B6
	ldrb r0, [r4, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x20
_0810A7B2:
	orrs r1, r0
	strb r1, [r4, 0x3]
_0810A7B6:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A75C

	thumb_func_start sub_810A7DC
sub_810A7DC: @ 810A7DC
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	ldr r1, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r1
	lsls r0, 24
	ldr r5, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r4, 0x8]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0xC]
	ldr r0, =sub_810A834
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A7DC

	thumb_func_start sub_810A834
sub_810A834: @ 810A834
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	movs r7, 0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrb r2, [r0, 0xC]
	str r2, [sp]
	ldrh r4, [r0, 0x8]
	ldrh r6, [r0, 0xA]
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	mov r10, r1
	cmp r0, 0
	bne _0810A878
	movs r0, 0
	mov r8, r0
	movs r2, 0x1
	movs r1, 0x10
	mov r12, r1
	b _0810A882
	.pool
_0810A878:
	movs r2, 0x10
	mov r12, r2
	movs r3, 0x8
	mov r8, r3
	movs r2, 0x4
_0810A882:
	mov r0, r9
	lsls r1, r0, 2
	adds r0, r1, r0
	lsls r0, 3
	add r0, r10
	movs r3, 0x1C
	ldrsh r0, [r0, r3]
	mov r10, r1
	cmp r0, 0xA
	bhi _0810A978
	lsls r0, 2
	ldr r1, =_0810A8A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810A8A4:
	.4byte _0810A8D0
	.4byte _0810A978
	.4byte _0810A8E4
	.4byte _0810A978
	.4byte _0810A904
	.4byte _0810A978
	.4byte _0810A91A
	.4byte _0810A978
	.4byte _0810A93C
	.4byte _0810A978
	.4byte _0810A970
_0810A8D0:
	ldr r0, =gUnknown_08595828
	lsls r1, r4, 16
	asrs r1, 16
	lsls r2, r6, 16
	asrs r2, 16
	mov r4, r12
	lsls r3, r4, 16
	b _0810A952
	.pool
_0810A8E4:
	mov r0, r12
	lsls r3, r0, 17
	mov r1, r8
	adds r0, r1, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =gUnknown_08595828
	lsls r1, r4, 16
	asrs r1, 16
	lsls r2, r6, 16
	asrs r2, 16
	b _0810A952
	.pool
_0810A904:
	mov r3, r12
	lsls r0, r3, 16
	asrs r0, 16
	lsls r3, r0, 1
	adds r3, r0
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	b _0810A946
_0810A91A:
	mov r0, r12
	lsls r3, r0, 18
	lsls r0, r2, 1
	adds r0, r2
	add r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =gUnknown_08595828
	lsls r1, r4, 16
	asrs r1, 16
	lsls r2, r6, 16
	asrs r2, 16
	b _0810A952
	.pool
_0810A93C:
	mov r1, r12
	lsls r0, r1, 16
	asrs r0, 16
	lsls r3, r0, 2
	adds r3, r0
_0810A946:
	ldr r0, =gUnknown_08595828
	lsls r1, r4, 16
	asrs r1, 16
	lsls r2, r6, 16
	asrs r2, 16
	lsls r3, 16
_0810A952:
	asrs r3, 16
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	b _0810A978
	.pool
_0810A970:
	mov r0, r9
	bl move_anim_task_del
	b _0810A9BC
_0810A978:
	cmp r7, 0
	beq _0810A9AC
	ldr r4, =gSprites
	lsls r3, r5, 4
	adds r3, r5
	lsls r3, 2
	adds r0, r3, r4
	ldrh r5, [r0, 0x4]
	lsls r2, r5, 22
	lsrs r2, 22
	add r2, r8
	ldr r6, =0x000003ff
	adds r1, r6, 0
	ands r2, r1
	ldr r1, =0xfffffc00
	ands r1, r5
	orrs r1, r2
	strh r1, [r0, 0x4]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x2E]
	adds r4, 0x1C
	adds r3, r4
	ldr r1, [r3]
	bl _call_via_r1
_0810A9AC:
	ldr r0, =gTasks
	mov r1, r10
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
_0810A9BC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810A834

	thumb_func_start sub_810A9DC
sub_810A9DC: @ 810A9DC
	push {lr}
	adds r3, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _0810A9FE
	ldrb r1, [r3, 0x1]
	movs r2, 0x3F
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
	ldrb r0, [r3, 0x3]
	ands r2, r0
	strb r2, [r3, 0x3]
	b _0810AA12
_0810A9FE:
	ldrb r2, [r3, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0x1]
	ldrb r0, [r3, 0x3]
	ands r1, r0
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r3, 0x3]
_0810AA12:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bne _0810AA26
	adds r0, r3, 0
	bl DestroySprite
_0810AA26:
	pop {r0}
	bx r0
	thumb_func_end sub_810A9DC

	thumb_func_start sub_810AA2C
sub_810AA2C: @ 810AA2C
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	strh r1, [r4, 0x20]
	ldrh r0, [r0, 0x2]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	ldr r0, =gUnknown_08595840
	adds r1, 0x20
	lsls r1, 16
	asrs r1, 16
	movs r7, 0x22
	ldrsh r2, [r4, r7]
	adds r3, r4, 0
	adds r3, 0x43
	ldrb r3, [r3]
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r6, r2, r3
	ldrh r5, [r6, 0x4]
	lsls r1, r5, 22
	lsrs r1, 22
	adds r1, 0x8
	ldr r7, =0x000003ff
	adds r0, r7, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r5
	orrs r0, r1
	strh r0, [r6, 0x4]
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	adds r3, 0x1C
	adds r2, r3
	ldr r0, =sub_810AAB0
	str r0, [r2]
	str r0, [r4, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AA2C

	thumb_func_start sub_810AAB0
sub_810AAB0: @ 810AAB0
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0810AAE4
	movs r0, 0
	strh r0, [r3, 0x2E]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_0810AAE4:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _0810AAF8
	adds r0, r3, 0
	bl move_anim_8072740
_0810AAF8:
	pop {r0}
	bx r0
	thumb_func_end sub_810AAB0

	thumb_func_start sub_810AAFC
sub_810AAFC: @ 810AAFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810AB28
	ldr r4, =gAnimationBankAttacker
	b _0810AB2A
	.pool
_0810AB28:
	ldr r4, =gAnimationBankTarget
_0810AB2A:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x24]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x26]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2, 0x2]
	movs r1, 0
	strh r0, [r5, 0x14]
	strh r1, [r5, 0x16]
	strh r1, [r5, 0x18]
	strh r1, [r5, 0x1A]
	strh r1, [r5, 0x1C]
	ldrh r0, [r2, 0x6]
	strh r0, [r5, 0x1E]
	strh r1, [r5, 0x20]
	ldrh r0, [r2, 0x4]
	strh r0, [r5, 0x22]
	ldr r0, =sub_810AB78
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AAFC

	thumb_func_start sub_810AB78
sub_810AB78: @ 810AB78
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	adds r2, r6, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0810AC78
	ldrh r0, [r5, 0x20]
	adds r0, 0x1
	movs r7, 0
	strh r0, [r5, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x22
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _0810AC86
	strh r7, [r5, 0x20]
	ldr r0, =gUnknown_085958A8
	movs r3, 0x24
	ldrsh r1, [r5, r3]
	movs r3, 0x26
	ldrsh r2, [r5, r3]
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0810AC86
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldr r1, =gUnknown_08595858
	movs r2, 0x1A
	ldrsh r0, [r5, r2]
	lsls r0, 1
	adds r0, r1
	movs r3, 0
	ldrsb r3, [r0, r3]
	ldrh r0, [r4, 0x20]
	adds r3, r0
	strh r3, [r4, 0x20]
	movs r2, 0x1A
	ldrsh r0, [r5, r2]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldrh r0, [r4, 0x22]
	adds r2, r0
	strh r2, [r4, 0x22]
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	lsls r1, r0, 2
	adds r1, r0
	movs r0, 0x28
	subs r0, r1
	strh r0, [r4, 0x2E]
	strh r3, [r4, 0x30]
	ldrh r0, [r5, 0x24]
	strh r0, [r4, 0x32]
	strh r2, [r4, 0x34]
	ldrh r0, [r5, 0x26]
	strh r0, [r4, 0x36]
	strh r6, [r4, 0x38]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r1, =sub_810ACC0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldrh r0, [r5, 0x1A]
	adds r0, 0x1
	strh r0, [r5, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0810AC30
	strh r7, [r5, 0x1A]
_0810AC30:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1E
	ldrsh r1, [r5, r2]
	cmp r0, r1
	blt _0810AC52
	strh r7, [r5, 0x1C]
	ldrh r1, [r5, 0x18]
	movs r3, 0x18
	ldrsh r0, [r5, r3]
	cmp r0, 0x5
	bgt _0810AC52
	adds r0, r1, 0x1
	strh r0, [r5, 0x18]
_0810AC52:
	ldrh r0, [r5, 0x16]
	adds r0, 0x1
	strh r0, [r5, 0x16]
	ldrh r0, [r5, 0x14]
	subs r0, 0x1
	strh r0, [r5, 0x14]
	b _0810AC86
	.pool
_0810AC78:
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810AC86
	adds r0, r2, 0
	bl move_anim_task_del
_0810AC86:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_810AB78

	thumb_func_start sub_810AC8C
sub_810AC8C: @ 810AC8C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0810ACB4
	ldr r2, =gTasks
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x16]
	subs r1, 0x1
	strh r1, [r0, 0x16]
	adds r0, r4, 0
	bl DestroySprite
_0810ACB4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AC8C

	thumb_func_start sub_810ACC0
sub_810ACC0: @ 810ACC0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =sub_810AC8C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ACC0

	thumb_func_start sub_810ACD8
sub_810ACD8: @ 810ACD8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810ACF4
	ldr r4, =gAnimationBankAttacker
	b _0810ACF6
	.pool
_0810ACF4:
	ldr r4, =gAnimationBankTarget
_0810ACF6:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ACD8

	thumb_func_start sub_810AD30
sub_810AD30: @ 810AD30
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810AD4C
	ldr r4, =gAnimationBankAttacker
	b _0810AD4E
	.pool
_0810AD4C:
	ldr r4, =gAnimationBankTarget
_0810AD4E:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x24]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x26]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AD30

	thumb_func_start sub_810AD98
sub_810AD98: @ 810AD98
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3A]
	movs r0, 0x10
	strh r0, [r5, 0x3C]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810ADE6
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	negs r0, r0
	strh r0, [r5, 0x3C]
_0810ADE6:
	ldr r0, =sub_810ADF8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AD98

	thumb_func_start sub_810ADF8
sub_810ADF8: @ 810ADF8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810AE0A
	cmp r0, 0x1
	beq _0810AE20
	b _0810AE50
_0810AE0A:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0810AE50
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810AE50
_0810AE20:
	ldrh r2, [r4, 0x3C]
	ldrh r1, [r4, 0x20]
	adds r0, r2, r1
	strh r0, [r4, 0x20]
	ldr r3, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x24]
	adds r2, r1
	strh r2, [r0, 0x24]
	ldrh r0, [r4, 0x20]
	adds r0, 0x50
	lsls r0, 16
	movs r1, 0xC8
	lsls r1, 17
	cmp r0, r1
	bls _0810AE50
	adds r0, r4, 0
	bl move_anim_8074EE0
_0810AE50:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ADF8

	thumb_func_start sub_810AE5C
sub_810AE5C: @ 810AE5C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0810AEF0
	cmp r0, 0x1
	bgt _0810AE84
	cmp r0, 0
	beq _0810AE90
	b _0810AFC0
	.pool
_0810AE84:
	cmp r0, 0x2
	beq _0810AF4C
	cmp r0, 0x3
	bne _0810AE8E
	b _0810AFA0
_0810AE8E:
	b _0810AFC0
_0810AE90:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0
	strh r0, [r5, 0x26]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x24]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810AECC
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x24]
	movs r0, 0x2
	b _0810AED2
	.pool
_0810AECC:
	movs r0, 0x20
	strh r0, [r5, 0x24]
	ldr r0, =0x0000fffe
_0810AED2:
	strh r0, [r5, 0x22]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r5, 0x24]
	strh r1, [r0, 0x24]
	b _0810AF92
	.pool
_0810AEF0:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810AFC0
	movs r0, 0
	strh r0, [r5, 0xA]
	ldr r4, =gSprites
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	adds r2, 0x3E
	ldrb r3, [r2]
	lsls r0, r3, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrh r1, [r5, 0x24]
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _0810AF92
	ldrh r2, [r5, 0x22]
	adds r2, r1, r2
	strh r2, [r5, 0x24]
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x24]
	b _0810AFC0
	.pool
_0810AF4C:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810AFC0
	movs r0, 0
	strh r0, [r5, 0xA]
	ldr r1, =gSprites
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	adds r2, 0x3E
	ldrb r3, [r2]
	lsls r0, r3, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _0810AFC0
_0810AF92:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0810AFC0
	.pool
_0810AFA0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r0, r3, 0
	bl move_anim_task_del
_0810AFC0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810AE5C

	thumb_func_start sub_810AFCC
sub_810AFCC: @ 810AFCC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _0810AFE6
	b _0810B10C
_0810AFE6:
	cmp r0, 0x1
	bgt _0810AFF4
	cmp r0, 0
	beq _0810AFFC
	b _0810B14E
	.pool
_0810AFF4:
	cmp r0, 0x2
	bne _0810AFFA
	b _0810B140
_0810AFFA:
	b _0810B14E
_0810AFFC:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _0810B012
	movs r1, 0x1
_0810B012:
	movs r6, 0
	strh r1, [r5, 0xA]
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r3, r0, 0
	cmp r2, 0
	beq _0810B048
	cmp r2, 0x4
	beq _0810B070
	ldrh r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810B0A8
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0xE]
	ldr r0, =0x0000fff0
	b _0810B0B0
	.pool
_0810B048:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	lsls r0, 7
	adds r0, 0x78
	strh r0, [r5, 0x10]
	b _0810B0E6
_0810B070:
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r1, 7
	movs r0, 0x78
	subs r0, r1
	strh r0, [r5, 0xE]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0xA
	ldrsh r1, [r5, r2]
	lsls r1, 5
	subs r0, r1
	strh r0, [r5, 0x10]
	b _0810B0E6
	.pool
_0810B0A8:
	ldr r0, =0x0000fff0
	strh r0, [r5, 0xE]
	movs r0, 0x80
	lsls r0, 1
_0810B0B0:
	strh r0, [r5, 0x10]
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _0810B0D0
	movs r2, 0
	ldrsh r0, [r3, r2]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	movs r0, 0x50
	subs r0, r1
	strh r0, [r5, 0x12]
	b _0810B0E6
	.pool
_0810B0D0:
	movs r0, 0
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, 0x28
	strh r0, [r5, 0x12]
	ldrh r1, [r5, 0xE]
	ldrh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	strh r1, [r5, 0x10]
_0810B0E6:
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _0810B0FC
	movs r1, 0
	movs r0, 0x1
	strh r0, [r5, 0xA]
	strh r1, [r5, 0x14]
	b _0810B138
_0810B0FC:
	ldr r0, =0x0000ffff
	strh r0, [r5, 0xA]
	movs r0, 0x3
	strh r0, [r5, 0x14]
	b _0810B138
	.pool
_0810B10C:
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	ble _0810B14E
	movs r0, 0
	strh r0, [r5, 0xC]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_810B154
	lsls r0, 24
	cmp r0, 0
	bne _0810B138
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_810B154
	lsls r0, 24
	cmp r0, 0
	beq _0810B14E
_0810B138:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0810B14E
_0810B140:
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810B14E
	adds r0, r4, 0
	bl move_anim_task_del
_0810B14E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810AFCC

	thumb_func_start sub_810B154
sub_810B154: @ 810B154
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_08595A00
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	movs r3, 0x12
	ldrsh r2, [r4, r3]
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0810B18A
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strh r5, [r0, 0x3A]
	movs r1, 0x7
	strh r1, [r0, 0x3C]
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
_0810B18A:
	ldrh r1, [r4, 0xA]
	ldrh r5, [r4, 0x14]
	adds r0, r1, r5
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	bge _0810B19C
	movs r0, 0x3
	strh r0, [r4, 0x14]
_0810B19C:
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	ble _0810B1A8
	movs r0, 0
	strh r0, [r4, 0x14]
_0810B1A8:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	lsls r0, 4
	ldrh r5, [r4, 0xE]
	adds r2, r0, r5
	strh r2, [r4, 0xE]
	lsls r0, r1, 16
	asrs r3, r0, 16
	cmp r3, 0x1
	bne _0810B1C8
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0x10
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bge _0810B1DC
_0810B1C8:
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	bne _0810B1E8
	lsls r0, r2, 16
	asrs r0, 16
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bgt _0810B1E8
_0810B1DC:
	movs r0, 0x1
	b _0810B1EA
	.pool
_0810B1E8:
	movs r0, 0
_0810B1EA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_810B154

	thumb_func_start sub_810B1F0
sub_810B1F0: @ 810B1F0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0810B230
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810B230:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B1F0

	thumb_func_start sub_810B23C
sub_810B23C: @ 810B23C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0810B24E
	cmp r0, 0x1
	beq _0810B280
	b _0810B294
_0810B24E:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	adds r0, r5, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0810B294
	.pool
_0810B280:
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810B294
	adds r0, r5, 0
	bl move_anim_8074EE0
_0810B294:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810B23C

	thumb_func_start sub_810B29C
sub_810B29C: @ 810B29C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bls _0810B2B6
	b _0810B428
_0810B2B6:
	lsls r0, 2
	ldr r1, =_0810B2C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810B2C8:
	.4byte _0810B2DC
	.4byte _0810B36C
	.4byte _0810B3A8
	.4byte _0810B404
	.4byte _0810B414
_0810B2DC:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x16]
	movs r0, 0x4
	strh r0, [r5, 0x18]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r5, r2]
	movs r2, 0x14
	ldrsh r1, [r5, r2]
	subs r0, r1
	movs r1, 0x5
	bl __divsi3
	strh r0, [r5, 0x1A]
	movs r0, 0x7
	strh r0, [r5, 0x10]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0x12]
	movs r0, 0xC
	strh r0, [r5, 0x1E]
	subs r0, 0x4C
	bl BattleAnimGetPanControl
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0x20]
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0x22]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x24]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	subs r0, r1
	movs r1, 0x3
	bl __divsi3
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	b _0810B426
	.pool
_0810B36C:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	cmp r0, 0
	ble _0810B39C
	movs r0, 0
	strh r0, [r5, 0xA]
	adds r0, r5, 0
	adds r1, r2, 0
	bl sub_810B430
	lsls r0, 24
	cmp r0, 0
	beq _0810B39C
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0x5
	bne _0810B396
	movs r0, 0x3
	b _0810B39A
_0810B396:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
_0810B39A:
	strh r0, [r5, 0x8]
_0810B39C:
	ldrh r1, [r5, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _0810B428
	b _0810B41E
_0810B3A8:
	ldrh r1, [r5, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _0810B3B6
	subs r0, r1, 0x1
	strh r0, [r5, 0x1E]
_0810B3B6:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0810B428
	strh r3, [r5, 0xA]
	ldrh r1, [r5, 0xC]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0810B3E2
	movs r0, 0x4
	strh r0, [r5, 0x16]
	movs r0, 0x44
	strh r0, [r5, 0x18]
	strh r3, [r5, 0x10]
	strh r2, [r5, 0x12]
	b _0810B3F2
_0810B3E2:
	movs r0, 0x44
	strh r0, [r5, 0x16]
	movs r0, 0x4
	strh r0, [r5, 0x18]
	movs r0, 0x7
	strh r0, [r5, 0x10]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0x12]
_0810B3F2:
	movs r1, 0x1E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0810B424
	movs r0, 0x4
	b _0810B426
	.pool
_0810B404:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810B428
	adds r0, r2, 0
	bl move_anim_task_del
	b _0810B428
_0810B414:
	ldrh r1, [r5, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _0810B424
_0810B41E:
	subs r0, r1, 0x1
	strh r0, [r5, 0x1E]
	b _0810B428
_0810B424:
	movs r0, 0x1
_0810B426:
	strh r0, [r5, 0x8]
_0810B428:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810B29C

	thumb_func_start sub_810B430
sub_810B430: @ 810B430
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_08595A30
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	movs r3, 0x16
	ldrsh r2, [r4, r3]
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0810B49C
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrh r2, [r3, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	ldrh r6, [r4, 0x10]
	adds r1, r6
	ldr r6, =0x000003ff
	adds r0, r6, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0x10]
	adds r0, r1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bge _0810B484
	movs r0, 0x7
	strh r0, [r4, 0x10]
_0810B484:
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0x7
	ble _0810B490
	movs r0, 0
	strh r0, [r4, 0x10]
_0810B490:
	strh r5, [r3, 0x3A]
	movs r0, 0x3
	strh r0, [r3, 0x3C]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
_0810B49C:
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0810B4BE
	movs r5, 0x12
	ldrsh r0, [r4, r5]
	cmp r0, 0
	ble _0810B4BE
	ldrh r1, [r4, 0x26]
	ldrh r6, [r4, 0x24]
	adds r1, r6
	strh r1, [r4, 0x24]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x76
	bl PlaySE12WithPanning
_0810B4BE:
	movs r0, 0x12
	ldrsh r3, [r4, r0]
	ldrh r2, [r4, 0x16]
	cmp r3, 0
	bge _0810B4D4
	lsls r0, r2, 16
	asrs r0, 16
	movs r5, 0x18
	ldrsh r1, [r4, r5]
	cmp r0, r1
	ble _0810B4E4
_0810B4D4:
	cmp r3, 0
	ble _0810B508
	lsls r0, r2, 16
	asrs r0, 16
	movs r6, 0x18
	ldrsh r1, [r4, r6]
	cmp r0, r1
	blt _0810B508
_0810B4E4:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x1A]
	ldrh r1, [r4, 0x14]
	adds r0, r1
	strh r0, [r4, 0x14]
	movs r0, 0x1
	b _0810B514
	.pool
_0810B508:
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, r2, r0
	strh r0, [r4, 0x16]
	movs r0, 0
_0810B514:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_810B430

	thumb_func_start sub_810B51C
sub_810B51C: @ 810B51C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0810B552
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0810B552:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B51C

	thumb_func_start sub_810B55C
sub_810B55C: @ 810B55C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0810B5D8
	cmp r0, 0x1
	bgt _0810B584
	cmp r0, 0
	beq _0810B58A
	b _0810B60E
	.pool
_0810B584:
	cmp r0, 0x2
	beq _0810B600
	b _0810B60E
_0810B58A:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r5, 0x26]
	strh r0, [r5, 0x24]
	cmp r0, 0x10
	ble _0810B5B4
	adds r2, r0, 0
_0810B5A4:
	adds r1, r2, 0
	subs r1, 0x20
	adds r2, r1, 0
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x10
	bgt _0810B5A4
	strh r1, [r5, 0x24]
_0810B5B4:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x2
	strh r0, [r5, 0x20]
	b _0810B5F8
	.pool
_0810B5D8:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810B60E
	movs r0, 0
	strh r0, [r5, 0xA]
	adds r0, r5, 0
	adds r1, r2, 0
	bl sub_810B614
	lsls r0, 24
	cmp r0, 0
	beq _0810B60E
_0810B5F8:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0810B60E
_0810B600:
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810B60E
	adds r0, r2, 0
	bl move_anim_task_del
_0810B60E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810B55C

	thumb_func_start sub_810B614
sub_810B614: @ 810B614
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_085956C0
	movs r2, 0x22
	ldrsh r1, [r4, r2]
	movs r3, 0x24
	ldrsh r2, [r4, r3]
	ldrh r3, [r4, 0x20]
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0810B658
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_810B684
	str r2, [r1]
	adds r0, r3
	strh r5, [r0, 0x3A]
	movs r1, 0xA
	strh r1, [r0, 0x3C]
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
_0810B658:
	ldrh r2, [r4, 0x24]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0810B67C
	adds r0, r2, 0
	adds r0, 0x20
	strh r0, [r4, 0x24]
	movs r0, 0
	b _0810B67E
	.pool
_0810B67C:
	movs r0, 0x1
_0810B67E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_810B614

	thumb_func_start sub_810B684
sub_810B684: @ 810B684
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810B6B8
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0810B6B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B684

	thumb_func_start sub_810B6C4
sub_810B6C4: @ 810B6C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x7
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r4]
	movs r1, 0x3
	str r3, [sp]
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r1]
	ldr r3, [sp]
	adds r0, r3
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x4]
	mov r4, r9
	adds r0, r4, r0
	strh r0, [r5, 0x32]
	ldrh r0, [r1, 0x2]
	adds r0, r6
	strh r0, [r5, 0x34]
	ldrh r0, [r1, 0x6]
	mov r7, r8
	adds r0, r7, r0
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A64EC
	adds r4, 0x20
	movs r0, 0x98
	lsls r0, 1
	mov r12, r0
	ldr r3, [sp]
	cmp r4, r12
	bhi _0810B79E
	adds r0, r7, 0
	adds r0, 0x20
	ldrh r1, [r5, 0x30]
	ldrh r2, [r5, 0x32]
	cmp r0, 0xE0
	bhi _0810B79E
	adds r4, r1, 0
	mov r10, r12
_0810B76A:
	mov r7, r9
	lsls r1, r7, 16
	asrs r1, 16
	adds r1, r4
	lsls r1, 16
	mov r7, r8
	lsls r0, r7, 16
	asrs r0, 16
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsrs r0, r1, 16
	mov r9, r0
	movs r7, 0x80
	lsls r7, 14
	adds r1, r7
	lsrs r1, 16
	cmp r1, r10
	bhi _0810B79E
	mov r1, r8
	lsls r0, r1, 16
	adds r0, r7
	lsrs r0, 16
	cmp r0, 0xE0
	bls _0810B76A
_0810B79E:
	ldrh r0, [r5, 0x30]
	negs r7, r0
	strh r7, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	negs r4, r0
	strh r4, [r5, 0x32]
	lsls r0, r3, 16
	movs r1, 0x80
	lsls r1, 14
	adds r0, r1
	lsrs r0, 16
	movs r2, 0x98
	lsls r2, 1
	mov r12, r2
	ldr r1, =gBattleAnimArgs
	mov r10, r1
	cmp r0, r12
	bhi _0810B80A
	lsls r1, r6, 16
	movs r2, 0x80
	lsls r2, 14
	adds r0, r1, r2
	b _0810B802
	.pool
_0810B7E0:
	lsls r1, r3, 16
	asrs r1, 16
	adds r1, r7
	lsls r1, 16
	asrs r0, r2, 16
	adds r0, r4
	lsls r0, 16
	lsrs r6, r0, 16
	lsrs r3, r1, 16
	movs r0, 0x80
	lsls r0, 14
	adds r1, r0
	lsrs r1, 16
	cmp r1, r12
	bhi _0810B80A
	lsls r1, r6, 16
	adds r0, r1, r0
_0810B802:
	lsrs r0, 16
	adds r2, r1, 0
	cmp r0, 0xE0
	bls _0810B7E0
_0810B80A:
	strh r3, [r5, 0x20]
	strh r6, [r5, 0x22]
	mov r1, r10
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	strh r3, [r5, 0x30]
	mov r2, r9
	strh r2, [r5, 0x32]
	strh r6, [r5, 0x34]
	mov r3, r8
	strh r3, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A64EC
	mov r7, r10
	ldrh r0, [r7, 0xA]
	strh r0, [r5, 0x34]
	ldrh r0, [r7, 0xC]
	strh r0, [r5, 0x36]
	ldr r0, =sub_810B848
	str r0, [r5, 0x1C]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B6C4

	thumb_func_start sub_810B848
sub_810B848: @ 810B848
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810B8A0
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x38]
	adds r1, r2
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x3A]
	adds r0, r2
	strh r0, [r4, 0x3A]
	strh r1, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810B8A6
_0810B8A0:
	adds r0, r4, 0
	bl move_anim_8072740
_0810B8A6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810B848

	thumb_func_start sub_810B8AC
sub_810B8AC: @ 810B8AC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x2E]
	movs r0, 0x3C
	strh r0, [r4, 0x30]
	movs r0, 0x9
	strh r0, [r4, 0x32]
	movs r0, 0x1E
	strh r0, [r4, 0x34]
	movs r0, 0xFE
	lsls r0, 8
	strh r0, [r4, 0x36]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A634C
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B8AC

	thumb_func_start sub_810B8EC
sub_810B8EC: @ 810B8EC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810B92C
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x32]
	ldrh r0, [r0, 0x4]
	subs r1, r0
	strh r1, [r4, 0x32]
	b _0810B936
	.pool
_0810B92C:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
_0810B936:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	ldr r1, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r2, [r1, 0x6]
	adds r0, r2
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B8EC

	thumb_func_start sub_810B974
sub_810B974: @ 810B974
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810B990
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	b _0810B9C6
	.pool
_0810B990:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0x1
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810B9B6
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810B9B6:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810B9C6:
	ldr r1, =sub_810B9E8
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B974

	thumb_func_start sub_810B9E8
sub_810B9E8: @ 810B9E8
	push {lr}
	adds r3, r0, 0
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _0810BA1E
	adds r0, r3, 0
	bl move_anim_8074EE0
_0810BA1E:
	pop {r0}
	bx r0
	thumb_func_end sub_810B9E8

	thumb_func_start sub_810BA24
sub_810BA24: @ 810BA24
	push {r4-r7,lr}
	sub sp, 0x10
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BA74
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r5, 0x36]
	b _0810BA86
	.pool
_0810BA74:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl sub_80A8924
_0810BA86:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BAAC
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r5, 0x32]
	ldrh r0, [r0, 0x4]
	subs r1, r0
	strh r1, [r5, 0x32]
	b _0810BAB6
	.pool
_0810BAAC:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
_0810BAB6:
	adds r7, r5, 0
	adds r7, 0x2E
	adds r2, r7, 0
	mov r1, sp
	movs r4, 0x7
_0810BAC0:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BAC0
	adds r0, r5, 0
	bl sub_80A7160
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	eors r0, r1
	strh r0, [r5, 0x32]
_0810BAE2:
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl sub_80A70E8
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	adds r1, r0
	adds r1, 0x10
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bhi _0810BB16
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BB16
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BAE2
_0810BB16:
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	ldr r6, =sub_80A718C
	ldr r1, =sub_810BB60
	mov r3, sp
	adds r2, r7, 0
	movs r4, 0x7
_0810BB36:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BB36
	str r6, [r5, 0x1C]
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BA24

	thumb_func_start sub_810BB60
sub_810BB60: @ 810BB60
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r5, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x24]
	movs r0, 0x80
	strh r0, [r4, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =0x0000ffec
	cmp r0, 0
	beq _0810BB90
	movs r1, 0x14
_0810BB90:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x34]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
	ldr r1, =sub_810BBC8
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BB60

	thumb_func_start sub_810BBC8
sub_810BBC8: @ 810BBC8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =0x0000ffec
	cmp r0, 0
	beq _0810BBDE
	movs r1, 0x14
_0810BBDE:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x1F
	bgt _0810BC24
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 16
	bl Sin
	ldrh r1, [r4, 0x34]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	ldrh r1, [r4, 0x36]
	subs r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x10
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0810BC42
	.pool
_0810BC24:
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x36]
	strh r1, [r4, 0x34]
	ldr r0, =sub_810BC4C
	str r0, [r4, 0x1C]
_0810BC42:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BBC8

	thumb_func_start sub_810BC4C
sub_810BC4C: @ 810BC4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_80A70E8
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _0810BC88
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r1, r0, r1
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bgt _0810BC88
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BC8E
_0810BC88:
	adds r0, r4, 0
	bl move_anim_8072740
_0810BC8E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810BC4C

	thumb_func_start sub_810BC94
sub_810BC94: @ 810BC94
	push {r4-r7,lr}
	sub sp, 0x10
	adds r5, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0810BCE0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	b _0810BCF2
	.pool
_0810BCE0:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl sub_80A8924
_0810BCF2:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BD1C
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r5, 0x32]
	ldrh r2, [r0, 0x4]
	subs r1, r2
	strh r1, [r5, 0x32]
	adds r1, r0, 0
	b _0810BD26
	.pool
_0810BD1C:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
_0810BD26:
	ldrh r0, [r1, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A7160
	adds r7, r5, 0
	adds r7, 0x2E
	adds r2, r7, 0
	mov r1, sp
	movs r4, 0x7
_0810BD3E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BD3E
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	eors r0, r1
	strh r0, [r5, 0x32]
_0810BD5A:
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl sub_80A70E8
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	adds r1, r0
	adds r1, 0x10
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bhi _0810BD8E
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BD8E
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BD5A
_0810BD8E:
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	ldr r1, =gBattleAnimArgs
	ldr r6, =sub_810BDD8
	mov r3, sp
	adds r2, r7, 0
	movs r4, 0x7
_0810BDAE:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BDAE
	ldrh r0, [r1, 0xA]
	strh r0, [r5, 0x38]
	ldrh r0, [r1, 0xC]
	strh r0, [r5, 0x3A]
	str r6, [r5, 0x1C]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BC94

	thumb_func_start sub_810BDD8
sub_810BDD8: @ 810BDD8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A70E8
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810BDEC
	movs r0, 0x1
	strh r0, [r4, 0x2E]
_0810BDEC:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810BE42
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _0810BE3C
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BE3C
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BE42
_0810BE3C:
	adds r0, r4, 0
	bl move_anim_8072740
_0810BE42:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810BDD8

	thumb_func_start sub_810BE48
sub_810BE48: @ 810BE48
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810BEB4
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810BE6C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
	b _0810BEA2
	.pool
_0810BE6C:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BE92
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810BE92:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810BEA2:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810BEC8
	.pool
_0810BEB4:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810BEC8
	adds r0, r4, 0
	bl move_anim_8072740
_0810BEC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810BE48

	thumb_func_start sub_810BED0
sub_810BED0: @ 810BED0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BF40
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BEF4
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
	b _0810BF32
	.pool
_0810BEF4:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BF20
	ldrh r0, [r5, 0x20]
	ldrh r1, [r6]
	subs r0, r1
	b _0810BF26
	.pool
_0810BF20:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_0810BF26:
	strh r0, [r5, 0x20]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
_0810BF32:
	ldr r0, =gAnimationBankAttacker
	b _0810BF90
	.pool
_0810BF40:
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BF52
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
	b _0810BF8E
_0810BF52:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BF7C
	ldrh r0, [r5, 0x20]
	ldrh r1, [r6]
	subs r0, r1
	b _0810BF82
	.pool
_0810BF7C:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_0810BF82:
	strh r0, [r5, 0x20]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
_0810BF8E:
	ldr r0, =gAnimationBankTarget
_0810BF90:
	ldrb r0, [r0]
	strh r0, [r5, 0x3C]
	ldr r0, =gBattleAnimArgs
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0810BFA8
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _0810BFB4
_0810BFA8:
	movs r0, 0x20
	b _0810BFB6
	.pool
_0810BFB4:
	movs r0, 0x40
_0810BFB6:
	strh r0, [r5, 0x3A]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810BFCC
	ldrh r0, [r5, 0x22]
	adds r0, 0x8
	strh r0, [r5, 0x22]
_0810BFCC:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrh r1, [r1, 0x4]
	adds r0, r1
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	movs r0, 0x40
	strh r0, [r5, 0x38]
	ldr r1, =sub_810C008
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BED0

	thumb_func_start sub_810C008
sub_810C008: @ 810C008
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _0810C092
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r1, 0x6
	negs r1, r1
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _0810C064
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	b _0810C086
_0810C064:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
_0810C086:
	ldrh r0, [r4, 0x38]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _0810C098
_0810C092:
	adds r0, r4, 0
	bl move_anim_8072740
_0810C098:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810C008

	thumb_func_start sub_810C0A0
sub_810C0A0: @ 810C0A0
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C0E2
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0810C0E2:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E1A
	strh r1, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_0854CAD0
	movs r2, 0x80
	lsls r2, 4
	mov r3, sp
	ldrh r3, [r3, 0xA]
	bl LoadBgTiles
	ldr r1, =gUnknown_08D932E0
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gUnknown_0854C270
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_810C164
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C0A0

	thumb_func_start sub_810C164
sub_810C164: @ 810C164
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0810C18E
	b _0810C2DA
_0810C18E:
	lsls r0, 2
	ldr r1, =_0810C1A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810C1A8:
	.4byte _0810C1BC
	.4byte _0810C214
	.4byte _0810C236
	.4byte _0810C27A
	.4byte _0810C29C
_0810C1BC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0810C1D6
	b _0810C2DA
_0810C1D6:
	strh r5, [r4, 0x1C]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	ldr r1, =gUnknown_08595C5C
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r1, [r0]
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bne _0810C2DA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _0810C2DA
	.pool
_0810C214:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _0810C2DA
	movs r0, 0x9
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _0810C2DA
_0810C236:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0810C2DA
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _0810C2DA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _0810C2DA
_0810C27A:
	mov r0, sp
	bl sub_80A6B30
	movs r0, 0x1
	bl sub_80A6C68
	movs r0, 0x2
	bl sub_80A6C68
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_0810C29C:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C2B0
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0810C2B0:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	adds r0, r4, 0
	bl move_anim_task_del
_0810C2DA:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C164

	thumb_func_start sub_810C2F0
sub_810C2F0: @ 810C2F0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r0, =sub_80A7820
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C2F0

	thumb_func_start sub_810C324
sub_810C324: @ 810C324
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C366
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0810C366:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E1A
	strh r1, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_0854CAD0
	movs r2, 0x80
	lsls r2, 4
	mov r3, sp
	ldrh r3, [r3, 0xA]
	bl LoadBgTiles
	ldr r1, =gUnknown_08D932E0
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gUnknown_0854C270
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x26]
	ldr r1, =sub_810C3F0
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C324

	thumb_func_start sub_810C3F0
sub_810C3F0: @ 810C3F0
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_02022E18
	ldr r3, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r3
	ldrh r0, [r1, 0x26]
	ldrh r5, [r2]
	adds r0, r5
	strh r0, [r2]
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	bls _0810C416
	b _0810C54A
_0810C416:
	lsls r0, 2
	ldr r1, =_0810C42C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810C42C:
	.4byte _0810C440
	.4byte _0810C484
	.4byte _0810C4A6
	.4byte _0810C4EA
	.4byte _0810C50C
_0810C440:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	ldr r1, =gUnknown_08595C88
	movs r5, 0x1A
	ldrsh r0, [r4, r5]
	adds r0, r1
	ldrb r1, [r0]
	strh r1, [r4, 0x1E]
	movs r0, 0x11
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bne _0810C54A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x1E]
	b _0810C54A
	.pool
_0810C484:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r3
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _0810C54A
	movs r0, 0x5
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _0810C54A
_0810C4A6:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0810C54A
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _0810C54A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _0810C54A
_0810C4EA:
	mov r0, sp
	bl sub_80A6B30
	movs r0, 0x1
	bl sub_80A6C68
	movs r0, 0x2
	bl sub_80A6C68
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_0810C50C:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C520
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0810C520:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	adds r0, r4, 0
	bl move_anim_task_del
_0810C54A:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C3F0

	thumb_func_start sub_810C560
sub_810C560: @ 810C560
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6]
	strh r0, [r5, 0x2E]
	ldr r0, =gAnimationBankAttacker
	mov r8, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	ldr r7, =gAnimationBankTarget
	ldrb r0, [r7]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bcs _0810C594
	movs r0, 0x80
	lsls r0, 8
	strh r0, [r5, 0x3C]
_0810C594:
	ldr r3, =gBanksBySide
	ldrb r0, [r7]
	adds r0, r3
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0810C5F4
	ldrh r0, [r6, 0x2]
	negs r0, r0
	strh r0, [r6, 0x2]
	ldrh r0, [r6, 0x6]
	negs r0, r0
	strh r0, [r6, 0x6]
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810C5F0
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0810C5F0
	movs r0, 0x1
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
_0810C5F0:
	movs r0, 0x1
	strh r0, [r5, 0x3A]
_0810C5F4:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r6, =gBattleAnimArgs
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0810C65C
	ldrh r0, [r6, 0x2]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r6, 0x4]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	b _0810C684
	.pool
_0810C65C:
	ldrh r0, [r6, 0x2]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r6, 0x4]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x1
_0810C684:
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x8]
	adds r0, r6
	strh r0, [r5, 0x36]
	ldrb r0, [r4]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 16
	ldrh r1, [r5, 0x3C]
	orrs r0, r1
	strh r0, [r5, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810C6B8
	movs r0, 0x1
	strh r0, [r5, 0x3A]
	adds r1, r5, 0
	adds r1, 0x43
	movs r0, 0x80
	strb r0, [r1]
_0810C6B8:
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_810C6D4
	str r0, [r5, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C560

	thumb_func_start sub_810C6D4
sub_810C6D4: @ 810C6D4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	movs r5, 0xFF
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x1
	beq _0810C7BC
	cmp r1, 0x1
	bgt _0810C6EE
	cmp r1, 0
	beq _0810C6F6
	b _0810C90C
_0810C6EE:
	cmp r1, 0x2
	bne _0810C6F4
	b _0810C8D0
_0810C6F4:
	b _0810C90C
_0810C6F6:
	adds r0, r4, 0
	bl sub_80A6F3C
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	asrs r0, 4
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810C724
	ldrh r0, [r4, 0x38]
	subs r0, 0x8
	b _0810C728
	.pool
_0810C724:
	ldrh r0, [r4, 0x38]
	adds r0, 0x8
_0810C728:
	ands r0, r5
	strh r0, [r4, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0810C736
	b _0810C90C
_0810C736:
	movs r5, 0x50
	strh r5, [r4, 0x2E]
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x26]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	adds r0, 0x1D
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C78C
	ldr r1, =gBanksBySide
	ldrb r0, [r6]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C78C
	movs r0, 0xCC
	strh r0, [r4, 0x38]
	b _0810C78E
	.pool
_0810C78C:
	strh r5, [r4, 0x38]
_0810C78E:
	movs r0, 0
	strh r0, [r4, 0x26]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	asrs r0, 3
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	b _0810C90C
	.pool
_0810C7BC:
	adds r0, r4, 0
	bl sub_80A6F3C
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r0, 3
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	negs r0, r0
	asrs r0, 8
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C83A
	ldrh r1, [r4, 0x38]
	adds r0, r1, 0
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	adds r3, r1, 0
	cmp r0, 0x7F
	bhi _0810C81C
	ldrh r1, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 24
	b _0810C824
	.pool
_0810C81C:
	ldrh r1, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 24
	adds r1, 0x1
_0810C824:
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r0, r3, 0x4
	b _0810C85A
_0810C83A:
	ldrh r0, [r4, 0x38]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _0810C84E
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x80
	b _0810C854
_0810C84E:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x8C
_0810C854:
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	subs r0, 0x4
_0810C85A:
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _0810C90C
	movs r5, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	adds r0, 0x4
	strh r0, [r4, 0x36]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C8B4
	ldr r1, =gBanksBySide
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C8B4
	movs r0, 0x80
	lsls r0, 1
	b _0810C8B6
	.pool
_0810C8B4:
	ldr r0, =0x0000fff0
_0810C8B6:
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x3C]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	adds r0, r4, 0
	bl sub_80A6FD4
	b _0810C90C
	.pool
_0810C8D0:
	adds r0, r4, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0810C90C
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C8FE
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
_0810C8FE:
	adds r0, r4, 0
	bl DestroySprite
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0810C90C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C6D4

	thumb_func_start sub_810C918
sub_810C918: @ 810C918
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r0, =sub_810C934
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_810C918

	thumb_func_start sub_810C934
sub_810C934: @ 810C934
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _0810C978
	cmp r5, 0x1
	bgt _0810C95C
	cmp r5, 0
	beq _0810C962
	b _0810C9DC
	.pool
_0810C95C:
	cmp r5, 0x2
	beq _0810C9CE
	b _0810C9DC
_0810C962:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0810C9DC
	strh r5, [r4, 0x10]
	strh r5, [r4, 0x12]
	strh r5, [r4, 0xC]
	b _0810C9B4
_0810C978:
	ldrh r1, [r4, 0x12]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0810C9C8
	ldrb r0, [r4, 0xE]
	ldrb r1, [r4, 0xC]
	movs r3, 0x1
	bl sub_810C9E4
	lsls r0, 24
	cmp r0, 0
	beq _0810C998
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_0810C998:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0810C9C4
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0810C9BC
_0810C9B4:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810C9DC
_0810C9BC:
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	b _0810C9DC
_0810C9C4:
	strh r5, [r4, 0x12]
	b _0810C9DC
_0810C9C8:
	subs r0, r1, 0x1
	strh r0, [r4, 0x12]
	b _0810C9DC
_0810C9CE:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810C9DC
	adds r0, r2, 0
	bl move_anim_task_del
_0810C9DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810C934

	thumb_func_start sub_810C9E4
sub_810C9E4: @ 810C9E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08595CB4
	lsrs r0, 22
	adds r4, r0, r1
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	asrs r0, 28
	mov r8, r0
	cmp r0, 0x2
	beq _0810CAD0
	ldrh r0, [r4, 0x2]
	lsls r0, 20
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810CAD0
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r8
	cmp r1, 0
	beq _0810CA60
	cmp r1, 0x1
	beq _0810CA96
	b _0810CAE2
	.pool
_0810CA60:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r6, 16
	asrs r1, 16
	subs r1, r0
	b _0810CACA
_0810CA96:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r7, 16
	asrs r1, 16
	adds r1, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r6, 16
	asrs r1, 16
	adds r1, r0
_0810CACA:
	lsls r1, 16
	lsrs r6, r1, 16
	b _0810CAE2
_0810CAD0:
	ldrh r0, [r4]
	lsls r0, 22
	asrs r0, 6
	lsrs r7, r0, 16
	ldr r0, [r4]
	lsls r0, 12
	asrs r0, 22
	lsls r0, 16
	lsrs r6, r0, 16
_0810CAE2:
	lsls r0, r6, 16
	asrs r0, 16
	adds r0, 0x8
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r0
	ldr r0, =gUnknown_08595D2C
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x8
	negs r2, r2
	movs r3, 0x12
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _0810CB44
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	mov r1, r9
	bl StartSpriteAffineAnim
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	strh r7, [r4, 0x34]
	strh r6, [r4, 0x36]
	mov r1, r9
	strh r1, [r4, 0x38]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x3A]
	mov r1, r10
	strh r1, [r4, 0x3C]
	movs r0, 0x1
	b _0810CB46
	.pool
_0810CB44:
	movs r0, 0
_0810CB46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_810C9E4

	thumb_func_start sub_810CB58
sub_810CB58: @ 810CB58
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x22]
	adds r2, r1, 0
	adds r2, 0x8
	strh r2, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0810CB82
	lsls r0, r2, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0810CC32
_0810CB82:
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _0810CC04
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810CC04
	ldr r0, =gUnknown_08595B68
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	movs r3, 0x36
	ldrsh r2, [r4, r3]
	adds r3, r4, 0
	adds r3, 0x43
	ldrb r3, [r3]
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	cmp r0, 0x40
	beq _0810CBE6
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_810CC3C
	str r1, [r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x3A]
	strh r1, [r0, 0x3A]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x3C]
	strh r1, [r0, 0x3C]
_0810CBE6:
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	b _0810CC32
	.pool
_0810CC04:
	ldr r3, =gTasks
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810CC32:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CB58

	thumb_func_start sub_810CC3C
sub_810CC3C: @ 810CC3C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _0810CC7C
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810CC7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CC3C

	thumb_func_start unc_080B06FC
unc_080B06FC: @ 810CC88
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gDisableStructMoveAnim
	ldr r0, [r0]
	ldrb r1, [r0, 0x11]
	lsrs r0, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r0, r1
	subs r0, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _0810CCA6
	movs r1, 0x4
_0810CCA6:
	adds r0, r5, 0
	bl StartSpriteAffineAnim
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810CCCE
	ldrh r0, [r6, 0x4]
	negs r0, r0
	strh r0, [r6, 0x4]
_0810CCCE:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldrh r0, [r6, 0xA]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =sub_810CD1C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_080B06FC

	thumb_func_start sub_810CD1C
sub_810CD1C: @ 810CD1C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0810CD3E
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
_0810CD3E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CD1C

	thumb_func_start sub_810CD4C
sub_810CD4C: @ 810CD4C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x8
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	bl Random2
	movs r5, 0xFF
	ands r5, r0
	movs r0, 0x80
	lsls r0, 1
	adds r6, r0, 0
	orrs r5, r6
	bl Random2
	ldr r1, =0x000001ff
	ands r1, r0
	adds r0, r1, 0
	cmp r0, 0xFF
	ble _0810CD92
	subs r0, r6, r0
	lsls r0, 16
	lsrs r1, r0, 16
_0810CD92:
	strh r5, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldr r0, =sub_810CDB0
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CD4C

	thumb_func_start sub_810CDB0
sub_810CDB0: @ 810CDB0
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x34]
	adds r3, r0, r1
	strh r3, [r2, 0x34]
	ldrh r1, [r2, 0x32]
	ldrh r4, [r2, 0x36]
	adds r1, r4
	strh r1, [r2, 0x36]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0810CDD4
	lsls r0, r3, 16
	asrs r0, 24
	negs r0, r0
	b _0810CDD8
_0810CDD4:
	lsls r0, r3, 16
	asrs r0, 24
_0810CDD8:
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _0810CDF6
	adds r0, r2, 0
	bl move_anim_8072740
_0810CDF6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810CDB0

	thumb_func_start sub_810CDFC
sub_810CDFC: @ 810CDFC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleAnimArgs
	ldrb r3, [r1]
	lsls r3, 1
	adds r3, r1
	ldr r1, =gDisableStructMoveAnim
	ldr r1, [r1]
	ldrb r1, [r1, 0x11]
	lsrs r2, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r2, r1
	subs r2, 0x1
	strh r2, [r3]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CDFC

	thumb_func_start unc_080B08A0
unc_080B08A0: @ 810CE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0xF
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_080B08A0

	thumb_func_start sub_810CE68
sub_810CE68: @ 810CE68
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810CE90
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810CE90
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x6]
	negs r0, r0
	strh r0, [r4, 0x6]
_0810CE90:
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xC]
	adds r0, r5, 0
	bl StartSpriteAnim
	movs r0, 0
	strh r0, [r4, 0xC]
	adds r0, r5, 0
	bl sub_80A7938
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CE68

	thumb_func_start sub_810CEB4
sub_810CEB4: @ 810CEB4
	push {r4,lr}
	adds r4, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810CED0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	negs r1, r1
	strh r1, [r0, 0x2]
	ldrh r1, [r0, 0x6]
	negs r1, r1
	strh r1, [r0, 0x6]
_0810CED0:
	adds r0, r4, 0
	bl sub_810CE68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CEB4

	thumb_func_start sub_810CEE0
sub_810CEE0: @ 810CEE0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x8]
	bl StartSpriteAnim
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810CF04
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _0810CF0C
	.pool
_0810CF04:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
_0810CF0C:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CEE0

	thumb_func_start sub_810CF30
sub_810CF30: @ 810CF30
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r9, r0
	cmp r1, 0
	bne _0810CF54
	ldr r0, =gAnimationBankAttacker
	b _0810CF56
	.pool
_0810CF54:
	ldr r0, =gAnimationBankTarget
_0810CF56:
	ldrb r0, [r0]
	mov r8, r0
	mov r4, r9
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bge _0810CF74
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	strh r0, [r4, 0x4]
_0810CF74:
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl StartSpriteAnim
	mov r0, r8
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	mov r0, r8
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	mov r0, r8
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	lsls r1, 15
	lsrs r6, r1, 16
	mov r0, r8
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0810CFBE
	adds r0, 0x3
_0810CFBE:
	lsls r4, r0, 14
	lsrs r4, 16
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r6, 16
	asrs r1, 16
	bl __modsi3
	lsls r0, 16
	lsrs r6, r0, 16
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 16
	lsrs r4, r0, 16
	bl Random2
	movs r7, 0x1
	adds r1, r7, 0
	ands r1, r0
	cmp r1, 0
	beq _0810D000
	lsls r0, r6, 16
	negs r0, r0
	lsrs r6, r0, 16
_0810D000:
	bl Random2
	adds r1, r7, 0
	ands r1, r0
	cmp r1, 0
	beq _0810D012
	lsls r0, r4, 16
	negs r0, r0
	lsrs r4, r0, 16
_0810D012:
	ldr r0, =gBanksBySide
	add r0, r8
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _0810D028
	lsls r0, r4, 16
	ldr r1, =0xfff00000
	adds r0, r1
	lsrs r4, r0, 16
_0810D028:
	lsls r0, r6, 16
	asrs r0, 16
	ldrh r2, [r5, 0x20]
	adds r0, r2
	strh r0, [r5, 0x20]
	lsls r0, r4, 16
	asrs r0, 16
	ldrh r3, [r5, 0x22]
	adds r0, r3
	strh r0, [r5, 0x22]
	mov r1, r9
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x2E]
	ldr r0, =gUnknown_08597358
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r3, 0x22
	ldrsh r2, [r5, r3]
	adds r3, r5, 0
	adds r3, 0x43
	ldrb r3, [r3]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3C]
	cmp r0, 0x40
	beq _0810D08C
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r2, 0x3C
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
_0810D08C:
	ldr r0, =sub_810D0B8
	str r0, [r5, 0x1C]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CF30

	thumb_func_start sub_810D0B8
sub_810D0B8: @ 810D0B8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0810D100
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0x40
	beq _0810D0F4
	ldr r4, =gSprites
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0810D0F4:
	adds r0, r5, 0
	bl move_anim_8072740
	b _0810D104
	.pool
_0810D100:
	subs r0, r1, 0x1
	strh r0, [r5, 0x2E]
_0810D104:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810D0B8

	thumb_func_start sub_810D10C
sub_810D10C: @ 810D10C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D130
	ldrh r0, [r4, 0x20]
	subs r0, 0x14
	strh r0, [r4, 0x32]
	b _0810D142
	.pool
_0810D130:
	ldrh r0, [r4, 0x20]
	adds r0, 0x14
	strh r0, [r4, 0x32]
	adds r2, r4, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0810D142:
	ldrh r0, [r4, 0x22]
	subs r0, 0x14
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =sub_810D164
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D10C

	thumb_func_start sub_810D164
sub_810D164: @ 810D164
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x38]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _0810D1A4
	ldrh r2, [r5, 0x20]
	ldrh r4, [r5, 0x24]
	subs r0, r2, r4
	strh r0, [r5, 0x32]
	ldrh r1, [r5, 0x22]
	ldrh r3, [r5, 0x26]
	subs r0, r1, r3
	strh r0, [r5, 0x36]
	movs r0, 0x8
	strh r0, [r5, 0x2E]
	adds r2, r4
	strh r2, [r5, 0x20]
	adds r1, r3
	strh r1, [r5, 0x22]
	strh r6, [r5, 0x26]
	strh r6, [r5, 0x24]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_0810D1A4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D164

	thumb_func_start sub_810D1B4
sub_810D1B4: @ 810D1B4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	ldr r2, =gAnimationBankTarget
	eors r0, r1
	ldrb r1, [r2]
	cmp r0, r1
	bne _0810D1E0
	ldrb r0, [r2]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0810D1E0
	ldr r1, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1]
_0810D1E0:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810D1FE
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0810D1FE:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x6]
	movs r5, 0
	strh r0, [r6, 0x2E]
	ldrh r0, [r6, 0x20]
	strh r0, [r6, 0x30]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrh r0, [r6, 0x22]
	strh r0, [r6, 0x34]
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldrh r0, [r4, 0xA]
	strh r0, [r6, 0x38]
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x3A]
	strh r5, [r6, 0x3C]
	ldr r0, =sub_810D240
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D1B4

	thumb_func_start sub_810D240
sub_810D240: @ 810D240
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	bne _0810D26C
	ldrh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	strh r0, [r4, 0x3C]
	b _0810D272
_0810D26C:
	adds r0, r4, 0
	bl move_anim_8072740
_0810D272:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D240

	thumb_func_start sub_810D278
sub_810D278: @ 810D278
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x4]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_810D2B0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D278

	thumb_func_start sub_810D2B0
sub_810D2B0: @ 810D2B0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D2B0

	thumb_func_start sub_810D2E4
sub_810D2E4: @ 810D2E4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_810D308
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D2E4

	thumb_func_start sub_810D308
sub_810D308: @ 810D308
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	subs r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810D34C
	movs r0, 0x6
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =sub_810D360
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_0810D34C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D308

	thumb_func_start sub_810D360
sub_810D360: @ 810D360
	push {lr}
	movs r1, 0xF
	strh r1, [r0, 0x2E]
	ldr r1, =sub_80A64B0
	str r1, [r0, 0x1C]
	ldr r1, =move_anim_8072740
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D360

	thumb_func_start sub_810D37C
sub_810D37C: @ 810D37C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810D3A8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810D404
	.pool
_0810D3A8:
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	cmp r0, 0x64
	ble _0810D3F6
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810D3F6:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	ble _0810D404
	adds r0, r4, 0
	bl move_anim_8072740
_0810D404:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D37C

	thumb_func_start sub_810D40C
sub_810D40C: @ 810D40C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D428
	ldr r4, =gAnimationBankAttacker
	b _0810D42A
	.pool
_0810D428:
	ldr r4, =gAnimationBankTarget
_0810D42A:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r2, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r1, 0x4]
	ldrh r3, [r5, 0x22]
	adds r0, r3
	strh r0, [r5, 0x22]
	strh r2, [r5, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x32]
	strh r2, [r5, 0x34]
	ldr r0, =sub_810D47C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D40C

	thumb_func_start sub_810D47C
sub_810D47C: @ 810D47C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	cmp r2, 0
	beq _0810D48E
	cmp r2, 0x1
	beq _0810D4B2
	b _0810D4EC
_0810D48E:
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _0810D4EC
	movs r2, 0x32
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0810D4AA
	adds r0, r1, 0
	bl move_anim_8072740
	b _0810D4EC
_0810D4AA:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0810D4EC
_0810D4B2:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810D4DA
	movs r0, 0
	strh r0, [r1, 0x30]
	ldrh r0, [r1, 0x34]
	adds r0, 0x1
	strh r0, [r1, 0x34]
	ands r0, r2
	lsls r0, 16
	cmp r0, 0
	beq _0810D4D6
	movs r0, 0x2
	b _0810D4D8
_0810D4D6:
	ldr r0, =0x0000fffe
_0810D4D8:
	strh r0, [r1, 0x24]
_0810D4DA:
	ldrh r0, [r1, 0x32]
	subs r0, 0x1
	strh r0, [r1, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _0810D4EC
	adds r0, r1, 0
	bl move_anim_8072740
_0810D4EC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D47C

	thumb_func_start sub_810D4F4
sub_810D4F4: @ 810D4F4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810D520
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r6, 0x4]
	adds r0, r2
	b _0810D532
	.pool
_0810D520:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
_0810D532:
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r5, 0x22]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	ldr r3, =gBattleAnimArgs
	movs r4, 0x2
	ldrsh r0, [r3, r4]
	lsls r0, 4
	adds r1, r0
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	movs r1, 0
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	cmp r0, 0x1
	beq _0810D5A0
	cmp r0, 0x1
	bgt _0810D58C
	cmp r0, 0
	beq _0810D596
	b _0810D5C6
	.pool
_0810D58C:
	cmp r0, 0x2
	beq _0810D5B0
	cmp r0, 0x3
	beq _0810D5C0
	b _0810D5C6
_0810D596:
	ldr r0, =0x0000fffd
	b _0810D5C0
	.pool
_0810D5A0:
	movs r0, 0x3
	strh r0, [r5, 0x3A]
	ldr r0, =0x0000fffd
	strh r0, [r5, 0x3C]
	b _0810D5CE
	.pool
_0810D5B0:
	ldr r0, =0x0000fffd
	strh r0, [r5, 0x3A]
	movs r0, 0x3
	strh r0, [r5, 0x3C]
	b _0810D5CE
	.pool
_0810D5C0:
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x3C]
	b _0810D5CE
_0810D5C6:
	adds r0, r5, 0
	bl move_anim_8072740
	b _0810D5D2
_0810D5CE:
	ldr r0, =sub_810D5DC
	str r0, [r5, 0x1C]
_0810D5D2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D4F4

	thumb_func_start sub_810D5DC
sub_810D5DC: @ 810D5DC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x3A]
	ldrh r2, [r1, 0x20]
	adds r0, r2
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x3C]
	ldrh r2, [r1, 0x22]
	adds r0, r2
	strh r0, [r1, 0x22]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0810D604
	adds r0, r1, 0
	bl move_anim_8072740
_0810D604:
	pop {r0}
	bx r0
	thumb_func_end sub_810D5DC

	thumb_func_start sub_810D608
sub_810D608: @ 810D608
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D664
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	ldr r0, =gAnimationBankTarget
	b _0810D680
	.pool
_0810D664:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	ldr r0, =gAnimationBankAttacker
_0810D680:
	ldrb r0, [r0]
	strh r0, [r5, 0x3C]
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r0, 0xC
	strh r0, [r5, 0x30]
	movs r0, 0x8
	strh r0, [r5, 0x32]
	ldr r0, =sub_810D6A8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D608

	thumb_func_start sub_810D6A8
sub_810D6A8: @ 810D6A8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB4
	bne _0810D704
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6F98
	str r0, [r4, 0x1C]
_0810D704:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D6A8

	thumb_func_start sub_810D714
sub_810D714: @ 810D714
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4]
	strh r0, [r5, 0x20]
	movs r2, 0x78
	strh r2, [r5, 0x22]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	adds r0, 0x36
	adds r1, r5, 0
	adds r1, 0x38
	lsls r2, 8
	bl sub_80A8048
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x3A]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r0, =sub_810D770
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D714

	thumb_func_start sub_810D770
sub_810D770: @ 810D770
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _0810D7C2
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	movs r2, 0x38
	ldrsh r1, [r7, r2]
	bl sub_80A8050
	adds r4, r0, 0
	movs r1, 0x3A
	ldrsh r0, [r7, r1]
	subs r4, r0
	adds r0, r7, 0
	adds r0, 0x36
	adds r1, r7, 0
	adds r1, 0x38
	adds r2, r4, 0
	bl sub_80A8048
	asrs r4, 8
	strh r4, [r7, 0x22]
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x8
	negs r0, r0
	cmp r4, r0
	bge _0810D7BA
	adds r0, r7, 0
	bl move_anim_8072740
	b _0810D818
_0810D7BA:
	ldrh r0, [r7, 0x2E]
	subs r0, 0x1
	strh r0, [r7, 0x2E]
	b _0810D818
_0810D7C2:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r2, =gAnimationBankTarget
	mov r8, r2
	ldrb r0, [r2]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	subs r4, r6
	strh r4, [r7, 0x2E]
	lsrs r0, 24
	subs r0, r5
	strh r0, [r7, 0x30]
	ldrh r0, [r7, 0x20]
	lsls r0, 4
	strh r0, [r7, 0x32]
	ldrh r0, [r7, 0x22]
	lsls r0, 4
	strh r0, [r7, 0x34]
	ldr r0, =sub_810D830
	str r0, [r7, 0x1C]
_0810D818:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D770

	thumb_func_start sub_810D830
sub_810D830: @ 810D830
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x34]
	adds r1, r3
	strh r1, [r2, 0x34]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r3, r1, 20
	strh r3, [r2, 0x22]
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _0810D86A
	adds r1, r3, 0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _0810D86A
	cmp r1, 0x78
	ble _0810D870
_0810D86A:
	adds r0, r2, 0
	bl move_anim_8072740
_0810D870:
	pop {r0}
	bx r0
	thumb_func_end sub_810D830

	thumb_func_start sub_810D874
sub_810D874: @ 810D874
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D8B8
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r0, =gAnimationBankTarget
	ldrb r4, [r0]
	ldr r0, =gAnimationBankAttacker
	b _0810D8BE
	.pool
_0810D8B8:
	ldr r0, =gAnimationBankAttacker
	ldrb r4, [r0]
	ldr r0, =gAnimationBankTarget
_0810D8BE:
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810D8F8
	ldrb r2, [r5, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	b _0810D912
	.pool
_0810D8F8:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810D918
	ldrb r2, [r5, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x18
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x57
_0810D912:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
_0810D918:
	movs r0, 0x10
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6F98
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D874

	thumb_func_start sub_810D960
sub_810D960: @ 810D960
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0810D976
	adds r0, r4, 0
	bl move_anim_8072740
_0810D976:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D960

	thumb_func_start sub_810D984
sub_810D984: @ 810D984
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1]
	strh r0, [r5, 0x32]
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x34]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x36]
	ldr r0, =gUnknown_02038432
	ldrb r6, [r0]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810D9CE
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0810D9CE:
	movs r0, 0x1
	ands r6, r0
	cmp r6, 0
	beq _0810D9E2
	ldrh r0, [r5, 0x32]
	negs r0, r0
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
_0810D9E2:
	ldrh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r5, 0x32]
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x34]
	strh r0, [r5, 0x26]
	ldr r0, =sub_810D960
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D984

	thumb_func_start sub_810DA10
sub_810DA10: @ 810DA10
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810DA2C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	b _0810DA34
	.pool
_0810DA2C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
_0810DA34:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810DA48
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	b _0810DA5E
_0810DA48:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DA5E
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0810DA5E:
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DA10

	thumb_func_start sub_810DA7C
sub_810DA7C: @ 810DA7C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810DAB6
	ldrh r0, [r4, 0x30]
	adds r0, 0x28
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x2
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0810DAB6
	adds r0, r4, 0
	bl move_anim_8072740
_0810DAB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DA7C

	thumb_func_start sub_810DABC
sub_810DABC: @ 810DABC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810DAF4
	cmp r0, 0x1
	bgt _0810DB0E
	cmp r0, 0
	bne _0810DB0E
	movs r0, 0
	bl sub_80A6DAC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x18]
	b _0810DB06
	.pool
_0810DAF4:
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810DB1A
_0810DB06:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810DB1A
_0810DB0E:
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r1, [r4, 0x1A]
	adds r0, r1
	strh r0, [r4, 0x1A]
_0810DB1A:
	movs r2, 0xB0
	lsls r2, 4
	adds r0, r2, 0
	ldrh r1, [r4, 0x1C]
	adds r0, r1
	strh r0, [r4, 0x1C]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810DB50
	ldr r1, =gUnknown_02022E20
	ldrh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	adds r7, r1, 0
	b _0810DB60
	.pool
_0810DB50:
	ldr r2, =gUnknown_02022E20
	ldrh r1, [r4, 0x1A]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	adds r7, r2, 0
_0810DB60:
	ldr r3, =gUnknown_02022E22
	ldrh r2, [r4, 0x1C]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r0, 0xFF
	ldrb r1, [r4, 0x1A]
	movs r5, 0
	strh r1, [r4, 0x1A]
	ands r0, r2
	strh r0, [r4, 0x1C]
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0810DB98
	strh r5, [r7]
	strh r5, [r3]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r6, 0
	bl move_anim_task_del
_0810DB98:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DABC

	thumb_func_start sub_810DBAC
sub_810DBAC: @ 810DBAC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810DBC2
	adds r0, r5, 0
	movs r1, 0x2
	bl StartSpriteAnim
_0810DBC2:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =0x0000ffe2
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =sub_810DC10
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DBAC

	thumb_func_start sub_810DC10
sub_810DC10: @ 810DC10
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0810DC24
	adds r0, r4, 0
	bl move_anim_8072740
_0810DC24:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DC10

	thumb_func_start sub_810DC2C
sub_810DC2C: @ 810DC2C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810DC44
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
_0810DC44:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	mov r6, sp
	adds r6, 0x2
	movs r1, 0x1
	mov r2, sp
	adds r3, r6, 0
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DC72
	ldrh r0, [r5, 0x8]
	negs r0, r0
	strh r0, [r5, 0x8]
_0810DC72:
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	mov r1, sp
	ldrh r0, [r5, 0x8]
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0xA]
	ldrh r6, [r6]
	adds r0, r6
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffe2
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_810DCB4
	str r0, [r4, 0x1C]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DC2C

	thumb_func_start sub_810DCB4
sub_810DCB4: @ 810DCB4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0810DCC8
	adds r0, r4, 0
	bl move_anim_8072740
_0810DCC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DCB4

	thumb_func_start sub_810DCD0
sub_810DCD0: @ 810DCD0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_80A6E14
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r4, 0x38]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r4, 0x3A]
	ldr r0, =sub_810DD24
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DCD0

	thumb_func_start sub_810DD24
sub_810DD24: @ 810DD24
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A656C
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x38]
	subs r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x3A]
	subs r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810DD4A
	adds r0, r4, 0
	bl move_anim_8072740
_0810DD4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DD24

	thumb_func_start sub_810DD50
sub_810DD50: @ 810DD50
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0x1
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DD7C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810DD7C:
	ldr r0, =gBattleAnimArgs
	ldrh r2, [r0]
	ldrh r1, [r4, 0x20]
	adds r2, r1
	strh r2, [r4, 0x20]
	ldrh r1, [r0, 0x2]
	ldrh r3, [r4, 0x22]
	adds r1, r3
	strh r1, [r4, 0x22]
	ldrh r3, [r0, 0x8]
	strh r3, [r4, 0x2E]
	ldrh r0, [r0, 0x4]
	adds r2, r0
	strh r2, [r4, 0x32]
	adds r1, r3
	strh r1, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DD50

	thumb_func_start sub_810DDC4
sub_810DDC4: @ 810DDC4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810DDE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	b _0810DE16
	.pool
_0810DDE0:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0x1
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DE06
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810DE06:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810DE16:
	ldr r0, =sub_810DE2C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DDC4

	thumb_func_start sub_810DE2C
sub_810DE2C: @ 810DE2C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0xB
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x4
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x30
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810DE68
	adds r0, r4, 0
	bl move_anim_8072740
_0810DE68:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DE2C

	thumb_func_start sub_810DE70
sub_810DE70: @ 810DE70
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A6980
	ldrh r0, [r4, 0x22]
	adds r0, 0x14
	strh r0, [r4, 0x22]
	movs r0, 0xBF
	strh r0, [r4, 0x30]
	ldr r1, =sub_810DE98
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DE70

	thumb_func_start sub_810DE98
sub_810DE98: @ 810DE98
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x47
	bne _0810DED2
	adds r0, r4, 0
	bl move_anim_8072740
_0810DED2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DE98

	thumb_func_start sub_810DED8
sub_810DED8: @ 810DED8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x8]
	ldrh r0, [r1]
	strh r0, [r4, 0xA]
	ldr r0, =0x00002719
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	ldr r0, =sub_810DF18
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DED8

	thumb_func_start sub_810DF18
sub_810DF18: @ 810DF18
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r3, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	adds r7, r2, 0
	cmp r0, r1
	bne _0810DF76
	movs r0, 0
	strh r0, [r3, 0x1C]
	ldrb r0, [r3, 0xC]
	ldr r2, =gPlttBufferFaded
	lsls r0, 4
	movs r3, 0x84
	lsls r3, 1
	adds r1, r0, r3
	lsls r1, 1
	adds r1, r2
	ldrh r6, [r1]
	movs r4, 0x7
	mov r12, r0
	ldr r0, =0x00000107
	add r0, r12
	lsls r0, 1
	adds r3, r0, r2
_0810DF5E:
	ldrh r0, [r3]
	strh r0, [r1]
	subs r3, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0810DF5E
	ldr r0, =0x00000101
	add r0, r12
	lsls r0, 1
	adds r0, r2
	strh r6, [r0]
_0810DF76:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r7
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	cmp r1, 0
	bne _0810DF90
	adds r0, r5, 0
	bl move_anim_task_del
_0810DF90:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DF18

	thumb_func_start sub_810DFA8
sub_810DFA8: @ 810DFA8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DFC8
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0810DFC8:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldrh r0, [r6, 0x20]
	strh r0, [r6, 0x30]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrh r0, [r6, 0x22]
	strh r0, [r6, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_80A67BC
	str r0, [r6, 0x1C]
	ldr r1, =sub_810E028
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DFA8

	thumb_func_start sub_810E028
sub_810E028: @ 810E028
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0810E03C
	adds r0, r4, 0
	bl move_anim_8072740
_0810E03C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810E028

	thumb_func_start sub_810E044
sub_810E044: @ 810E044
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810E070
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r1, 0x6]
_0810E070:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810E088
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	negs r1, r1
	strh r1, [r0, 0x2]
	ldrh r1, [r0, 0x6]
	negs r1, r1
	strh r1, [r0, 0x6]
_0810E088:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	ldrh r3, [r5, 0x20]
	adds r1, r3
	strh r1, [r5, 0x20]
	lsrs r0, 24
	ldrh r1, [r2, 0x2]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldrh r0, [r2, 0x8]
	strh r0, [r5, 0x2E]
	movs r3, 0xC
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0810E0EC
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	b _0810E0FE
	.pool
_0810E0EC:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl sub_80A8924
_0810E0FE:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x4]
	ldrh r1, [r5, 0x32]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r4, 0x6]
	ldrh r3, [r5, 0x36]
	adds r0, r3
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldrb r1, [r4, 0xA]
	adds r0, r5, 0
	bl SeekSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E044

	thumb_func_start sub_810E13C
sub_810E13C: @ 810E13C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_810E184
	str r0, [r4, 0x1C]
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E13C

	thumb_func_start sub_810E184
sub_810E184: @ 810E184
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0810E198
	subs r0, r1, 0x1
	strh r0, [r2, 0x2E]
	b _0810E1AA
_0810E198:
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	subs r1, r0
	strh r1, [r2, 0x26]
_0810E1AA:
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0810E1C2
	adds r0, r2, 0
	bl move_anim_8072740
_0810E1C2:
	pop {r0}
	bx r0
	thumb_func_end sub_810E184

	thumb_func_start sub_810E1C8
sub_810E1C8: @ 810E1C8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810E1F8
	movs r0, 0x88
	lsls r0, 1
	strh r0, [r5, 0x20]
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x22]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _0810E1FE
	.pool
_0810E1F8:
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
_0810E1FE:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl obj_translate_based_on_private_1_2_3_4
	ldr r0, =sub_810E24C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E1C8

	thumb_func_start sub_810E24C
sub_810E24C: @ 810E24C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_80A6F3C
	ldrh r1, [r4, 0x34]
	lsrs r0, r1, 8
	cmp r0, 0xC8
	bls _0810E274
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x24]
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
_0810E274:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x20
	movs r1, 0x98
	lsls r1, 1
	cmp r0, r1
	bhi _0810E296
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0xA0
	ble _0810E2BC
_0810E296:
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl move_anim_8072740
_0810E2BC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E24C

	thumb_func_start sub_810E2C8
sub_810E2C8: @ 810E2C8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _0810E308
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810E2FA
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
_0810E2FA:
	adds r0, r4, 0
	bl DestroySprite
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0810E308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E2C8

	thumb_func_start sub_810E314
sub_810E314: @ 810E314
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r5, r7, 0
	adds r5, 0x2E
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0810E33C
	ldr r0, =gAnimationBankAttacker
	b _0810E33E
	.pool
_0810E33C:
	ldr r0, =gAnimationBankTarget
_0810E33E:
	ldrb r6, [r0]
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810E354
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810E354:
	adds r0, r6, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r7, 0x20]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	ldrh r1, [r4, 0x2]
	lsrs r0, 24
	adds r1, r0, r1
	strh r1, [r7, 0x22]
	lsls r1, 8
	strh r1, [r5, 0x8]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	lsls r0, 1
	ldrh r2, [r5, 0xE]
	movs r1, 0x1
	ands r1, r2
	orrs r1, r0
	strh r1, [r5, 0xE]
	ldrb r0, [r5]
	movs r2, 0x4
	mov r8, r2
	mov r1, r8
	orrs r0, r1
	strb r0, [r5]
	ldrh r0, [r4, 0x4]
	ldrb r1, [r4, 0x4]
	strh r1, [r5, 0x2]
	lsls r0, 16
	lsrs r0, 24
	strh r0, [r5, 0xA]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x4]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x6]
	ldrh r0, [r4, 0xA]
	strh r0, [r5, 0xC]
	subs r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x7F
	bhi _0810E44A
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E3F0
	adds r0, r6, 0
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r7, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x5]
	b _0810E408
	.pool
_0810E3F0:
	adds r0, r6, 0
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
_0810E408:
	ldrb r1, [r5, 0xE]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r5, 0xE]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	bne _0810E4AA
	adds r3, r7, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r0, r2, 31
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	b _0810E4A2
_0810E44A:
	adds r0, r6, 0
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
	ldrb r0, [r5, 0xE]
	movs r4, 0x1
	orrs r0, r4
	strb r0, [r5, 0xE]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810E4AA
	adds r3, r7, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	ands r1, r4
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	mov r2, r8
	orrs r0, r2
_0810E4A2:
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
_0810E4AA:
	ldrh r1, [r5, 0x2]
	lsrs r1, 6
	lsls r1, 4
	ldrb r2, [r5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	ldr r3, =gSineTable
	ldrh r0, [r5, 0x2]
	lsls r0, 1
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, 0xC]
	muls r0, r1
	asrs r0, 8
	strh r0, [r7, 0x24]
	ldrb r2, [r7, 0x3]
	lsls r2, 26
	lsrs r2, 27
	movs r1, 0x24
	ldrsh r0, [r7, r1]
	negs r0, r0
	asrs r0, 1
	ldrb r5, [r5, 0xA]
	adds r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r3
	ldrh r4, [r1]
	ldr r1, =gOamMatrices
	lsls r2, 3
	adds r2, r1
	adds r0, 0x40
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2, 0x6]
	strh r0, [r2]
	strh r4, [r2, 0x2]
	lsls r0, r4, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r2, 0x4]
	ldr r0, =sub_810E520
	str r0, [r7, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E314

	thumb_func_start sub_810E520
sub_810E520: @ 810E520
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r6, 0
	adds r4, r5, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	movs r7, 0x1
	movs r0, 0x1
	mov r9, r0
	ands r0, r2
	cmp r0, 0
	beq _0810E55A
	ldrb r0, [r4, 0x1]
	adds r1, r0, 0
	adds r1, 0xFF
	strb r1, [r4, 0x1]
	lsls r0, 24
	cmp r0, 0
	beq _0810E54E
	b _0810EA36
_0810E54E:
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810EA36
_0810E55A:
	ldrh r0, [r4, 0x2]
	lsrs r1, r0, 6
	mov r12, r0
	cmp r1, 0x1
	bne _0810E566
	b _0810E68A
_0810E566:
	cmp r1, 0x1
	bgt _0810E570
	cmp r1, 0
	beq _0810E57E
	b _0810E97C
_0810E570:
	cmp r1, 0x2
	bne _0810E576
	b _0810E77E
_0810E576:
	cmp r1, 0x3
	bne _0810E57C
	b _0810E872
_0810E57C:
	b _0810E97C
_0810E57E:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x1
	bne _0810E592
	movs r0, 0x8
	orrs r0, r2
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E680
_0810E592:
	lsrs r0, r1, 28
	cmp r0, 0x3
	bne _0810E5B4
	lsls r0, r2, 30
	lsrs r0, 31
	movs r1, 0x1
	eors r0, r1
	ands r0, r7
	lsls r0, 1
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	orrs r1, r7
	strb r1, [r4]
	strb r6, [r4, 0x1]
	b _0810E680
_0810E5B4:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E680
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E672
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E642
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E628
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E660
_0810E628:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E660
_0810E642:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E656
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E65E
_0810E656:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E65E:
	strb r0, [r1]
_0810E660:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E672:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E680:
	ldrb r1, [r4]
	movs r0, 0xF
	ands r0, r1
	strb r0, [r4]
	b _0810E97C
_0810E68A:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0
	bne _0810E698
	movs r0, 0x8
	orrs r0, r2
	b _0810E6A0
_0810E698:
	lsrs r0, r1, 28
	cmp r0, 0x2
	bne _0810E6A8
	adds r0, r2, 0
_0810E6A0:
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E774
_0810E6A8:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E774
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E766
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E736
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E71C
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E754
_0810E71C:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E754
_0810E736:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E74A
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E752
_0810E74A:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E752:
	strb r0, [r1]
_0810E754:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E766:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E774:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x10
	b _0810E978
_0810E77E:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x3
	bne _0810E78C
	movs r0, 0x8
	orrs r0, r2
	b _0810E794
_0810E78C:
	lsrs r0, r1, 28
	cmp r0, 0x1
	bne _0810E79C
	adds r0, r2, 0
_0810E794:
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E868
_0810E79C:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E868
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E85A
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E82A
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E810
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E848
_0810E810:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E848
_0810E82A:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E83E
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E846
_0810E83E:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E846:
	strb r0, [r1]
_0810E848:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E85A:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E868:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x20
	b _0810E978
_0810E872:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x2
	bne _0810E882
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r4]
	b _0810E970
_0810E882:
	lsrs r0, r1, 28
	cmp r0, 0
	bne _0810E8A4
	lsls r0, r2, 30
	lsrs r0, 31
	movs r1, 0x1
	eors r0, r1
	ands r0, r7
	lsls r0, 1
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	orrs r1, r7
	strb r1, [r4]
	strb r6, [r4, 0x1]
	b _0810E970
_0810E8A4:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E970
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E962
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E932
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E918
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E950
_0810E918:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E950
_0810E932:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E946
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E94E
_0810E946:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E94E:
	strb r0, [r1]
_0810E950:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E962:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E970:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x30
_0810E978:
	orrs r1, r0
	strb r1, [r4]
_0810E97C:
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 31
	adds r0, r4, 0
	adds r0, 0xC
	adds r0, r1
	ldrb r1, [r0]
	ldr r3, =gSineTable
	mov r2, r12
	lsls r0, r2, 1
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r0, r1
	asrs r0, 8
	strh r0, [r5, 0x24]
	ldrb r2, [r5, 0x3]
	lsls r2, 26
	lsrs r2, 27
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	negs r0, r0
	asrs r0, 1
	ldrb r1, [r4, 0xA]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r3
	ldrh r6, [r1]
	ldr r1, =gOamMatrices
	lsls r2, 3
	adds r2, r1
	adds r0, 0x40
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2, 0x6]
	strh r0, [r2]
	strh r6, [r2, 0x2]
	lsls r0, r6, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r2, 0x4]
	ldrh r0, [r4, 0x6]
	ldrh r2, [r4, 0x8]
	adds r0, r2
	strh r0, [r4, 0x8]
	lsls r0, 16
	lsrs r0, 24
	strh r0, [r5, 0x22]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810EA0C
	ldrh r0, [r4, 0x4]
	subs r1, 0x1
	ands r1, r0
	ldrh r0, [r4, 0x2]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2]
	b _0810EA1C
	.pool
_0810EA0C:
	ldrh r0, [r4, 0x4]
	ldr r1, =0x00007fff
	ands r1, r0
	ldrh r2, [r4, 0x2]
	adds r1, r2
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0x2]
_0810EA1C:
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	ldrh r0, [r4, 0xE]
	lsrs r0, 1
	cmp r1, r0
	blt _0810EA36
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =sub_810E2C8
	str r0, [r5, 0x1C]
_0810EA36:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E520

	thumb_func_start sub_810EA4C
sub_810EA4C: @ 810EA4C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r0, =sub_80A7820
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EA4C

	thumb_func_start sub_810EAA0
sub_810EAA0: @ 810EAA0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810EABC
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
	b _0810EAC4
	.pool
_0810EABC:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
_0810EAC4:
	ldr r4, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0810EADC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810EAF2
_0810EADC:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810EAF8
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810EAF8
_0810EAF2:
	ldrh r0, [r5, 0x20]
	adds r0, 0x8
	strh r0, [r5, 0x20]
_0810EAF8:
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl SeekSpriteAnim
	ldrh r0, [r5, 0x20]
	subs r0, 0x20
	strh r0, [r5, 0x20]
	ldr r0, =0x00000ccc
	strh r0, [r5, 0x30]
	ldrh r1, [r4, 0x8]
	movs r0, 0xC
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	ldrh r2, [r5, 0x24]
	adds r0, r2
	strh r0, [r5, 0x24]
	strh r1, [r5, 0x2E]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x3C]
	ldr r0, =sub_810EB40
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EAA0

	thumb_func_start sub_810EB40
sub_810EB40: @ 810EB40
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0810EB6A
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x24]
	adds r0, r4, 0
	bl StartSpriteAnim
_0810EB6A:
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810EB82
	adds r0, r4, 0
	bl move_anim_8072740
_0810EB82:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EB40

	thumb_func_start sub_810EB88
sub_810EB88: @ 810EB88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	ldrh r0, [r7, 0x8]
	movs r1, 0x1F
	ands r0, r1
	cmp r0, 0
	bne _0810EC02
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	movs r5, 0xD
	negs r5, r5
	adds r1, r5, 0
	bl Sin
	ldr r4, =gBattleAnimArgs
	strh r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	adds r1, r5, 0
	bl Cos
	strh r0, [r4, 0x2]
	movs r0, 0x1
	strh r0, [r4, 0x4]
	movs r0, 0x3
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_085973E8
	mov r8, r0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0x3
	bl CreateSpriteAndAnimate
_0810EC02:
	ldrh r0, [r7, 0x8]
	adds r0, 0x8
	strh r0, [r7, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _0810EC16
	adds r0, r6, 0
	bl move_anim_task_del
_0810EC16:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EB88

	thumb_func_start sub_810EC34
sub_810EC34: @ 810EC34
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810EC46
	cmp r0, 0x1
	beq _0810EC78
	b _0810EC8C
_0810EC46:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810EC8C
	.pool
_0810EC78:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810EC8C
	adds r0, r4, 0
	bl move_anim_8072740
_0810EC8C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EC34

	thumb_func_start sub_810EC94
sub_810EC94: @ 810EC94
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810ECCC
	cmp r0, 0x1
	bgt _0810ECAA
	cmp r0, 0
	beq _0810ECB0
	b _0810ED1E
_0810ECAA:
	cmp r0, 0x2
	beq _0810ECE0
	b _0810ED1E
_0810ECB0:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r4, 0x26]
	b _0810ECD8
	.pool
_0810ECCC:
	ldrh r0, [r4, 0x26]
	adds r0, 0xA
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _0810ED1E
_0810ECD8:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810ED1E
_0810ECE0:
	ldrh r0, [r4, 0x26]
	subs r0, 0xA
	strh r0, [r4, 0x26]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0810ED1E
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl move_anim_8072740
_0810ED1E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EC94

	thumb_func_start sub_810ED28
sub_810ED28: @ 810ED28
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_810ED70
	str r0, [r4, 0x1C]
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ED28

	thumb_func_start sub_810ED70
sub_810ED70: @ 810ED70
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0810ED84
	subs r0, r1, 0x1
	strh r0, [r2, 0x2E]
	b _0810EDC8
_0810ED84:
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	ble _0810EDAA
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	subs r1, r0
	strh r1, [r2, 0x26]
	b _0810EDC8
_0810EDAA:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x34]
	adds r1, r0, 0x1
	strh r1, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _0810EDC8
	ldr r0, =sub_810EDD0
	str r0, [r2, 0x1C]
_0810EDC8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ED70

	thumb_func_start sub_810EDD0
sub_810EDD0: @ 810EDD0
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	ble _0810EE00
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_0810EE00:
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _0810EE0E
	adds r0, r2, 0
	bl move_anim_8072740
_0810EE0E:
	pop {r0}
	bx r0
	thumb_func_end sub_810EDD0

	thumb_func_start sub_810EE14
sub_810EE14: @ 810EE14
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0810EE28
	cmp r0, 0x1
	beq _0810EE80
	b _0810EEEC
_0810EE28:
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0810EE40
	ldr r4, =gAnimationBankAttacker
	b _0810EE42
	.pool
_0810EE40:
	ldr r4, =gAnimationBankTarget
_0810EE42:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	movs r0, 0
	movs r3, 0x80
	lsls r3, 2
	strh r3, [r5, 0x30]
	movs r2, 0x80
	lsls r2, 1
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A73E0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0810EEEC
	.pool
_0810EE80:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0xB
	bgt _0810EE8E
	ldrh r0, [r5, 0x30]
	subs r0, 0x28
	b _0810EE92
_0810EE8E:
	ldrh r0, [r5, 0x30]
	adds r0, 0x28
_0810EE92:
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x32]
	movs r2, 0x80
	lsls r2, 1
	movs r0, 0x30
	ldrsh r3, [r5, r0]
	str r1, [sp]
	adds r0, r5, 0
	bl sub_80A73E0
	ldrb r1, [r5, 0x3]
	lsls r1, 26
	lsrs r1, 27
	movs r0, 0xF4
	lsls r0, 6
	ldr r2, =gOamMatrices
	lsls r1, 3
	adds r1, r2
	movs r2, 0x6
	ldrsh r1, [r1, r2]
	bl __divsi3
	adds r1, r0, 0x1
	cmp r1, 0x80
	ble _0810EECC
	movs r1, 0x80
_0810EECC:
	movs r0, 0x40
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r1, r0, 1
	strh r1, [r5, 0x26]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x18
	bne _0810EEEC
	adds r0, r5, 0
	bl sub_80A749C
	adds r0, r5, 0
	bl move_anim_8072740
_0810EEEC:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EE14

	thumb_func_start sub_810EEF8
sub_810EEF8: @ 810EEF8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl Random2
	ldr r4, =0x000001ff
	ands r4, r0
	bl Random2
	movs r1, 0x7F
	ands r1, r0
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0810EF20
	movs r2, 0xB8
	lsls r2, 2
	adds r0, r4, r2
	b _0810EF28
	.pool
_0810EF20:
	movs r2, 0xB8
	lsls r2, 2
	adds r0, r2, 0
	subs r0, r4
_0810EF28:
	strh r0, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810EF3C
	movs r2, 0xE0
	lsls r2, 2
	adds r0, r2, 0
	adds r0, r1, r0
	b _0810EF44
_0810EF3C:
	movs r2, 0xE0
	lsls r2, 2
	adds r0, r2, 0
	subs r0, r1
_0810EF44:
	strh r0, [r5, 0x30]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r5, 0x32]
	lsls r0, 16
	cmp r0, 0
	beq _0810EF60
	ldrb r0, [r5, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r5, 0x3]
_0810EF60:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _0810EF74
	ldr r4, =gAnimationBankAttacker
	b _0810EF76
	.pool
_0810EF74:
	ldr r4, =gAnimationBankTarget
_0810EF76:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r5, 0x22]
	ldr r0, =sub_810EFA8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EEF8

	thumb_func_start sub_810EFA8
sub_810EFA8: @ 810EFA8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810EFC0
	ldrh r3, [r4, 0x2E]
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	b _0810EFCA
_0810EFC0:
	ldrh r3, [r4, 0x2E]
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
_0810EFCA:
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	strh r3, [r4, 0x2E]
	adds r0, r2, 0
	subs r0, 0x20
	strh r0, [r4, 0x30]
	lsls r0, r3, 16
	cmp r0, 0
	bge _0810EFEA
	movs r0, 0
	strh r0, [r4, 0x2E]
_0810EFEA:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _0810EFFE
	adds r0, r4, 0
	bl move_anim_8072740
_0810EFFE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EFA8

	thumb_func_start sub_810F004
sub_810F004: @ 810F004
	movs r1, 0
	strh r1, [r0, 0x3A]
	movs r1, 0x40
	strh r1, [r0, 0x3C]
	ldr r1, =sub_810F018
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_810F004

	thumb_func_start sub_810F018
sub_810F018: @ 810F018
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _0810F02A
	cmp r1, 0x1
	beq _0810F078
	b _0810F07E
_0810F02A:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0810F07E
	strh r1, [r3, 0x30]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r2, [r1]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _0810F07E
	ldrb r1, [r1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810F07E
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _0810F07E
_0810F078:
	adds r0, r3, 0
	bl move_anim_8072740
_0810F07E:
	pop {r0}
	bx r0
	thumb_func_end sub_810F018

	thumb_func_start sub_810F084
sub_810F084: @ 810F084
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	ldrh r4, [r0, 0x20]
	ldrh r5, [r0, 0x22]
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	mov r2, r8
	strh r6, [r2, 0x22]
	ldrh r0, [r2, 0x20]
	mov r9, r0
	mov r1, r9
	lsls r0, r1, 4
	strh r0, [r2, 0x36]
	lsls r0, r6, 4
	strh r0, [r2, 0x38]
	lsls r4, 16
	asrs r4, 16
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	subs r0, r4, r0
	lsls r0, 4
	movs r1, 0xC
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3A]
	lsls r5, 16
	asrs r5, 16
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	subs r0, r5, r0
	lsls r0, 4
	movs r1, 0xC
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3C]
	mov r0, r9
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	subs r5, r6
	lsls r5, 16
	asrs r5, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	mov r0, r8
	movs r1, 0x1
	adds r2, r3, 0
	bl sub_80A73E0
	ldr r0, =sub_810F140
	mov r2, r8
	str r0, [r2, 0x1C]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F084

	thumb_func_start sub_810F140
sub_810F140: @ 810F140
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x36]
	adds r0, r1
	strh r0, [r2, 0x36]
	ldrh r1, [r2, 0x3C]
	ldrh r3, [r2, 0x38]
	adds r1, r3
	strh r1, [r2, 0x38]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r3, r1, 20
	strh r3, [r2, 0x22]
	adds r0, 0x2D
	lsls r0, 16
	movs r1, 0xA5
	lsls r1, 17
	cmp r0, r1
	bhi _0810F17A
	adds r1, r3, 0
	cmp r1, 0x9D
	bgt _0810F17A
	movs r0, 0x2D
	negs r0, r0
	cmp r1, r0
	bge _0810F180
_0810F17A:
	adds r0, r2, 0
	bl move_anim_8074EE0
_0810F180:
	pop {r0}
	bx r0
	thumb_func_end sub_810F140

	thumb_func_start sub_810F184
sub_810F184: @ 810F184
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810F1BC
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	b _0810F1DA
	.pool
_0810F1BC:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
_0810F1DA:
	strb r0, [r1]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F184

	thumb_func_start sub_810F1EC
sub_810F1EC: @ 810F1EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	bl IsContest
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F212
	mov r0, r8
	cmp r0, 0
	beq _0810F22E
_0810F212:
	ldrb r1, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x5]
	adds r1, r5, 0
	adds r1, 0x43
	movs r0, 0xC8
	strb r0, [r1]
	mov r1, r8
	cmp r1, 0
	bne _0810F2B8
_0810F22E:
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	adds r0, r4, 0
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F264
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80A438C
_0810F264:
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r7
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F284
	movs r0, 0x1
	eors r6, r0
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80A438C
_0810F284:
	mov r0, r8
	cmp r0, 0
	bne _0810F2B8
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0810F2B8
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810F2B0
	movs r0, 0x48
	strh r0, [r5, 0x20]
	movs r0, 0x50
	b _0810F2F2
	.pool
_0810F2B0:
	movs r0, 0xB0
	strh r0, [r5, 0x20]
	movs r0, 0x28
	b _0810F2F2
_0810F2B8:
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F2CE
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810F2CE:
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
_0810F2F2:
	strh r0, [r5, 0x22]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r5, 0x2E]
	mov r0, r8
	cmp r0, 0
	beq _0810F32C
	ldrh r0, [r5, 0x22]
	adds r0, 0x9
	strh r0, [r5, 0x22]
	ldr r1, =sub_810F3C8
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	b _0810F330
	.pool
_0810F32C:
	ldr r0, =sub_810F340
	str r0, [r5, 0x1C]
_0810F330:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F1EC

	thumb_func_start sub_810F340
sub_810F340: @ 810F340
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810F35C
	movs r0, 0x1
	strh r0, [r5, 0x3C]
	b _0810F3B6
_0810F35C:
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F382
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0810F382:
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F3AC
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0810F3AC:
	ldr r1, =sub_810F3C8
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
_0810F3B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F340

	thumb_func_start sub_810F3C8
sub_810F3C8: @ 810F3C8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0xD
	bne _0810F3F4
	ldr r0, =sub_810F400
	str r0, [r4, 0x1C]
	b _0810F3F8
	.pool
_0810F3F4:
	adds r0, r1, 0x1
	strh r0, [r4, 0x34]
_0810F3F8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810F3C8

	thumb_func_start sub_810F400
sub_810F400: @ 810F400
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0810F45E
	movs r0, 0
	strh r0, [r3, 0x30]
	ldrh r4, [r3, 0x2E]
	ldr r1, =gPlttBufferFaded
	adds r0, r4, 0
	adds r0, 0x8
	lsls r0, 1
	adds r0, r1
	ldrh r7, [r0]
	movs r5, 0x8
	adds r6, r1, 0
	adds r1, r4, 0x7
	lsls r0, r4, 1
	adds r0, r6
	adds r2, r0, 0
	adds r2, 0x10
	lsls r1, 1
	adds r1, r6
_0810F436:
	ldrh r0, [r1]
	strh r0, [r2]
	subs r1, 0x2
	subs r2, 0x2
	subs r5, 0x1
	cmp r5, 0
	bgt _0810F436
	adds r0, r4, 0x1
	lsls r0, 1
	adds r0, r6
	strh r7, [r0]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0810F45E
	ldr r0, =sub_810F46C
	str r0, [r3, 0x1C]
_0810F45E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F400

	thumb_func_start sub_810F46C
sub_810F46C: @ 810F46C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x34]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r5, 0x34]
	subs r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810F512
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F502
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F4D4
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
_0810F4D4:
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r6
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F502
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
_0810F502:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_810F524
	str r0, [r5, 0x1C]
_0810F512:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F46C

	thumb_func_start sub_810F524
sub_810F524: @ 810F524
	push {r4-r6,lr}
	adds r6, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F57C
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r5, r1, 31
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F562
	adds r0, r5, 0
	bl sub_80A477C
_0810F562:
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0810F57C
	movs r0, 0x1
	eors r5, r0
	adds r0, r5, 0
	bl sub_80A477C
_0810F57C:
	ldr r0, =move_anim_8072740
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F524

	thumb_func_start sub_810F58C
sub_810F58C: @ 810F58C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810F618
	ldr r5, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	movs r6, 0
	cmp r0, 0
	bne _0810F5A6
	movs r6, 0x1
_0810F5A6:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F5EE
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0810F5EE
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0810F5E0
	ldrh r0, [r5]
	movs r1, 0x48
	subs r1, r0
	strh r1, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	adds r0, 0x50
	strh r0, [r4, 0x22]
	b _0810F610
	.pool
_0810F5E0:
	ldrh r0, [r5]
	adds r0, 0xB0
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	adds r0, 0x28
	strh r0, [r4, 0x22]
	b _0810F610
_0810F5EE:
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810F608
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80A69CC
	b _0810F610
	.pool
_0810F608:
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80A6980
_0810F610:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810F62C
_0810F618:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _0810F62C
	adds r0, r4, 0
	bl move_anim_8074EE0
_0810F62C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810F58C

	thumb_func_start sub_810F634
sub_810F634: @ 810F634
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F684
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r5, 0x20]
	subs r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	adds r0, 0xA
	strh r0, [r5, 0x22]
	ldr r0, =0x0000ffff
	b _0810F692
	.pool
_0810F684:
	ldrh r0, [r5, 0x20]
	adds r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	subs r0, 0xA
	strh r0, [r5, 0x22]
	movs r0, 0x1
_0810F692:
	strh r0, [r5, 0x30]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F634

	thumb_func_start sub_810F6B0
sub_810F6B0: @ 810F6B0
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	lsls r1, 15
	lsrs r4, r1, 16
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	asrs r1, 1
	negs r1, r1
	lsls r1, 16
	lsrs r7, r1, 16
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810F6F6
	lsls r0, r4, 16
	negs r0, r0
	lsrs r4, r0, 16
_0810F6F6:
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r7
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _0810F722
	movs r0, 0x10
	strh r0, [r5, 0x22]
_0810F722:
	ldr r1, =sub_810F740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F6B0

	thumb_func_start sub_810F740
sub_810F740: @ 810F740
	push {r4,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_08596740
	str r0, [r4, 0x10]
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	ldr r0, =sub_810F774
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F740

	thumb_func_start sub_810F774
sub_810F774: @ 810F774
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F786
	cmp r0, 0x1
	beq _0810F7B4
	b _0810F7CC
_0810F786:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810F7CC
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x12
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810F7CC
_0810F7B4:
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810F7CC
	adds r0, r4, 0
	bl move_anim_8072740
_0810F7CC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810F774

	thumb_func_start sub_810F7D4
sub_810F7D4: @ 810F7D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x8]
	ldr r2, =gUnknown_0859675C
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_810F810
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F7D4

	thumb_func_start sub_810F810
sub_810F810: @ 810F810
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0810F830
	adds r0, r4, 0
	bl move_anim_task_del
_0810F830:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F810

	thumb_func_start sub_810F83C
sub_810F83C: @ 810F83C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	strh r1, [r4, 0xC]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r1, 0x8
	cmp r0, 0
	beq _0810F870
	movs r1, 0x4
_0810F870:
	strh r1, [r4, 0xE]
	ldrb r1, [r4, 0x8]
	ldr r2, =gUnknown_0859677C
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_810F898
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F83C

	thumb_func_start sub_810F898
sub_810F898: @ 810F898
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F8BC
	cmp r0, 0x1
	beq _0810F8D8
	b _0810F936
	.pool
_0810F8BC:
	adds r0, r4, 0
	bl sub_80A7D34
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0810F936
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _0810F936
_0810F8D8:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F900
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x8
	strh r1, [r0, 0x26]
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _0810F936
	.pool
_0810F900:
	ldr r3, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	ldrb r0, [r4, 0x8]
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
_0810F936:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F898

	thumb_func_start sub_810F940
sub_810F940: @ 810F940
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	movs r1, 0
	movs r0, 0x10
	strh r0, [r5, 0xE]
	strh r1, [r5, 0x10]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x24]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, r6
	bcs _0810F9AA
	adds r1, r6, 0
_0810F9AA:
	strh r1, [r5, 0x20]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =sub_810F9D4
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F940

	thumb_func_start sub_810F9D4
sub_810F9D4: @ 810F9D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0810FAD4
	cmp r1, 0x1
	bgt _0810F9FC
	cmp r1, 0
	beq _0810FA0A
	b _0810FB5A
	.pool
_0810F9FC:
	cmp r1, 0x2
	bne _0810FA02
	b _0810FB36
_0810FA02:
	cmp r1, 0x3
	bne _0810FA08
	b _0810FB44
_0810FA08:
	b _0810FB5A
_0810FA0A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bgt _0810FA1A
	b _0810FB5A
_0810FA1A:
	strh r1, [r4, 0xA]
	ldr r0, =gUnknown_08596794
	movs r2, 0x22
	ldrsh r1, [r4, r2]
	movs r3, 0x24
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	adds r1, 0x8
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0x8
	adds r0, r1
	strh r2, [r0]
	cmp r2, 0x40
	beq _0810FABE
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810FA78
	cmp r0, 0x1
	bgt _0810FA5C
	cmp r0, 0
	beq _0810FA66
	b _0810FABE
	.pool
_0810FA5C:
	cmp r0, 0x2
	beq _0810FA90
	cmp r0, 0x3
	beq _0810FAA8
	b _0810FABE
_0810FA66:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	b _0810FAB6
	.pool
_0810FA78:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x20]
	b _0810FABC
	.pool
_0810FA90:
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r4, 0x20]
	strh r1, [r0, 0x24]
	ldrh r1, [r4, 0x20]
	strh r1, [r0, 0x26]
	b _0810FABE
	.pool
_0810FAA8:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	negs r0, r0
_0810FAB6:
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x20]
	negs r0, r0
_0810FABC:
	strh r0, [r1, 0x26]
_0810FABE:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0810FB5A
	b _0810FB36
	.pool
_0810FAD4:
	ldrh r0, [r4, 0xA]
	ands r1, r0
	cmp r1, 0
	beq _0810FAE4
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _0810FAEA
_0810FAE4:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
_0810FAEA:
	ldrh r1, [r4, 0x10]
	lsls r1, 8
	ldrh r0, [r4, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	bne _0810FB5A
	movs r5, 0x8
	adds r6, r4, 0
	adds r6, 0x8
_0810FB10:
	lsls r0, r5, 1
	adds r1, r6, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x40
	beq _0810FB2C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_0810FB2C:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xC
	bls _0810FB10
_0810FB36:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810FB5A
	.pool
_0810FB44:
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_task_del
_0810FB5A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810F9D4

	thumb_func_start sub_810FB60
sub_810FB60: @ 810FB60
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	subs r0, 0xA
	cmp r1, r0
	ble _0810FB8A
	ldrh r0, [r4, 0x30]
	movs r1, 0x1
	ands r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810FB8A:
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0810FB9C
	adds r0, r4, 0
	bl move_anim_8072740
_0810FB9C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810FB60

	thumb_func_start sub_810FBA8
sub_810FBA8: @ 810FBA8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810FBD4
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_0810FBD4:
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_810FB60
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FBA8

	thumb_func_start sub_810FBF0
sub_810FBF0: @ 810FBF0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810FC94
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _0810FC60
	ldr r0, =0x0000fff6
	strh r0, [r5, 0x1C]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD1E
	.pool
_0810FC60:
	movs r0, 0xA
	strh r0, [r5, 0x1C]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD12
	.pool
_0810FC94:
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _0810FCE8
	ldr r0, =0x0000fff6
	strh r0, [r5, 0x1C]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD1E
	.pool
_0810FCE8:
	movs r0, 0xA
	strh r0, [r5, 0x1C]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
_0810FD12:
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
_0810FD1E:
	strh r0, [r5, 0x24]
	movs r0, 0x6
	strh r0, [r5, 0xA]
	ldr r0, =sub_810FD3C
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FBF0

	thumb_func_start sub_810FD3C
sub_810FD3C: @ 810FD3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _0810FD60
	cmp r1, 0x1
	beq _0810FDD4
	b _0810FDE8
	.pool
_0810FD60:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _0810FDE8
	strh r1, [r5, 0xA]
	ldr r0, =gUnknown_08596864
	movs r2, 0x1E
	ldrsh r1, [r5, r2]
	movs r3, 0x20
	ldrsh r2, [r5, r3]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0810FDB4
	ldr r0, =gSprites
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x22]
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0x24]
	strh r0, [r4, 0x36]
	ldrh r0, [r5, 0x1C]
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldrb r0, [r5, 0xC]
	movs r1, 0x3
	ands r1, r0
	adds r0, r4, 0
	bl StartSpriteAffineAnim
_0810FDB4:
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0810FDE8
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0810FDE8
	.pool
_0810FDD4:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x11
	ble _0810FDE8
	adds r0, r2, 0
	bl move_anim_task_del
_0810FDE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810FD3C

	thumb_func_start sub_810FDF0
sub_810FDF0: @ 810FDF0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0810FE0E
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810FE0E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810FDF0

	thumb_func_start sub_810FE14
sub_810FE14: @ 810FE14
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl sub_80A6190
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	subs r0, 0x20
	strh r0, [r4, 0x24]
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _0810FE6A
	cmp r0, 0x1
	bgt _0810FE58
	cmp r0, 0
	beq _0810FE5E
	b _0810FE86
	.pool
_0810FE58:
	cmp r0, 0x2
	beq _0810FE76
	b _0810FE86
_0810FE5E:
	movs r0, 0x2
	strh r0, [r4, 0x1E]
	movs r0, 0x5
	strh r0, [r4, 0x20]
	movs r0, 0x40
	b _0810FE7E
_0810FE6A:
	movs r0, 0x2
	strh r0, [r4, 0x1E]
	movs r0, 0x5
	strh r0, [r4, 0x20]
	movs r0, 0xC0
	b _0810FE7E
_0810FE76:
	movs r0, 0x4
	strh r0, [r4, 0x1E]
	strh r0, [r4, 0x20]
	movs r0, 0
_0810FE7E:
	strh r0, [r4, 0x22]
	adds r0, r1, 0
	adds r0, 0x20
	strh r0, [r4, 0x26]
_0810FE86:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0810FE92
	movs r0, 0
	strh r0, [r4, 0x24]
_0810FE92:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810FEB8
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r4, 0x1C]
	ldr r0, =0x04000014
	b _0810FEC0
	.pool
_0810FEB8:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	strh r0, [r4, 0x1C]
	ldr r0, =0x04000018
_0810FEC0:
	str r0, [sp]
	ldrh r1, [r4, 0x24]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	cmp r1, r0
	bgt _0810FEFA
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0810FEDA:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x1C]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x1C]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	cmp r1, r0
	ble _0810FEDA
_0810FEFA:
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_810FF34
	str r0, [r4]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FE14

	thumb_func_start sub_810FF34
sub_810FF34: @ 810FF34
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0811000E
	cmp r0, 0x1
	bgt _0810FF60
	cmp r0, 0
	beq _0810FF66
	b _08110026
	.pool
_0810FF60:
	cmp r0, 0x2
	beq _08110020
	b _08110026
_0810FF66:
	ldrh r3, [r5, 0x22]
	ldrh r4, [r5, 0x24]
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0810FFFE
	ldr r0, =gSineTable
	mov r9, r0
	movs r7, 0x3
	ldr r1, =gUnknown_02038C28
	mov r12, r1
	movs r2, 0xF0
	lsls r2, 3
	add r2, r12
	mov r8, r2
_0810FF88:
	lsls r2, r3, 16
	asrs r0, r2, 15
	add r0, r9
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r3, 0x20
	ldrsh r1, [r5, r3]
	asrs r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r3, r0, 16
	adds r6, r2, 0
	cmp r3, 0
	ble _0810FFB8
	ldrh r1, [r5, 0xA]
	adds r0, r7, 0
	ands r0, r1
	adds r0, r3, r0
	b _0810FFC4
	.pool
_0810FFB8:
	cmp r3, 0
	bge _0810FFC8
	ldrh r1, [r5, 0xA]
	adds r0, r7, 0
	ands r0, r1
	subs r0, r3, r0
_0810FFC4:
	lsls r0, 16
	lsrs r1, r0, 16
_0810FFC8:
	lsls r2, r4, 16
	asrs r2, 16
	lsls r3, r2, 1
	mov r0, r12
	adds r4, r3, r0
	ldrh r0, [r5, 0x1C]
	lsls r1, 16
	asrs r1, 16
	adds r0, r1, r0
	strh r0, [r4]
	add r3, r8
	ldrh r0, [r5, 0x1C]
	adds r1, r0
	strh r1, [r3]
	asrs r0, r6, 16
	ldrh r1, [r5, 0x1E]
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r2, 0x1
	lsls r2, 16
	lsrs r4, r2, 16
	asrs r2, 16
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r2, r0
	ble _0810FF88
_0810FFFE:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _08110026
	b _08110014
_0811000E:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08110014:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _08110026
	.pool
_08110020:
	adds r0, r2, 0
	bl move_anim_task_del
_08110026:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_810FF34

	thumb_func_start sub_8110034
sub_8110034: @ 8110034
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	bl AllocOamMatrix
	lsls r0, 24
	lsrs r5, r0, 24
	mov r10, r5
	adds r6, r5, 0
	cmp r6, 0xFF
	bne _0811006C
	adds r0, r4, 0
	bl move_anim_task_del
	b _08110116
	.pool
_0811006C:
	ldr r1, =gBattleAnimArgs
	ldrb r0, [r1]
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r1, r0, 16
	mov r9, r1
	asrs r0, 16
	cmp r0, 0
	bge _08110094
	adds r0, r5, 0
	bl FreeOamMatrix
	mov r0, r8
	bl move_anim_task_del
	b _08110116
	.pool
_08110094:
	ldr r2, =gSprites
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r0, r2, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	adds r4, r2
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1F
	ands r6, r0
	lsls r2, r6, 1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	ldr r1, =gBattleAnimArgs
	ldrb r0, [r1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x22]
	mov r0, r10
	strh r0, [r7, 0x24]
	mov r1, r9
	strh r1, [r7, 0x26]
	ldr r0, =sub_8110134
	str r0, [r7]
_08110116:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110034

	thumb_func_start sub_8110134
sub_8110134: @ 8110134
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _081101B8
	cmp r0, 0x1
	bgt _0811015C
	cmp r0, 0
	beq _08110166
	b _08110238
	.pool
_0811015C:
	cmp r0, 0x2
	beq _08110208
	cmp r0, 0x3
	beq _08110228
	b _08110238
_08110166:
	ldrh r0, [r4, 0xA]
	adds r0, 0x4
	strh r0, [r4, 0xA]
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 17
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	lsrs r1, 24
	bl sub_80A7EC0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x30
	bne _08110238
	b _0811021A
	.pool
_081101B8:
	ldrh r0, [r4, 0xA]
	subs r0, 0x4
	strh r0, [r4, 0xA]
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 17
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	lsrs r1, 24
	bl sub_80A7EC0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08110238
	b _0811021A
	.pool
_08110208:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
_0811021A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08110238
	.pool
_08110228:
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	bl FreeOamMatrix
	adds r0, r5, 0
	bl move_anim_task_del
_08110238:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8110134

	thumb_func_start sub_8110240
sub_8110240: @ 8110240
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081102B8
	cmp r0, 0x1
	bgt _08110256
	cmp r0, 0
	beq _08110260
	b _08110360
_08110256:
	cmp r0, 0x2
	beq _081102EA
	cmp r0, 0x3
	beq _0811034A
	b _08110360
_08110260:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0811028E
	ldrh r0, [r5, 0x22]
	adds r0, 0xC
	strh r0, [r5, 0x22]
_0811028E:
	movs r0, 0x8
	strh r0, [r5, 0x30]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r0, [r5, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _081102E2
	.pool
_081102B8:
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08110360
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCB
	bl PlaySE12WithPanning
	adds r0, r5, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
_081102E2:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08110360
_081102EA:
	ldrh r0, [r5, 0x32]
	adds r1, r0, 0x1
	strh r1, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811032E
	movs r0, 0
	strh r0, [r5, 0x32]
	ldrh r1, [r5, 0x30]
	subs r1, 0x1
	strh r1, [r5, 0x30]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0811032E
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0811032E:
	movs r0, 0xE0
	lsls r0, 2
	adds r2, r0, 0
	ldrh r1, [r5, 0x34]
	adds r2, r1
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r5, 0x26]
	subs r0, r1
	strh r0, [r5, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r5, 0x34]
	b _08110360
_0811034A:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_8072740
_08110360:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8110240

	thumb_func_start sub_8110368
sub_8110368: @ 8110368
	push {r4-r6,lr}
	adds r6, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08110394
	adds r0, r6, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x4]
	negs r1, r1
	strh r1, [r0, 0x4]
	ldrh r1, [r0]
	negs r1, r1
	strh r1, [r0]
	b _081103C4
	.pool
_08110394:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _081103C4
	adds r0, r6, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r1, 0x6]
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_081103C4:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A60AC
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A60AC
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r6, 0x22]
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110368

	thumb_func_start sub_8110438
sub_8110438: @ 8110438
	push {r4-r6,lr}
	adds r6, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0811045C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
	adds r0, r6, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	b _08110478
	.pool
_0811045C:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08110478
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	negs r1, r1
	strh r1, [r0, 0x2]
	ldrh r1, [r0]
	negs r1, r1
	strh r1, [r0]
_08110478:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A60AC
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r6, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A60AC
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r6, 0x22]
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x2E]
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110438

	thumb_func_start sub_81104E4
sub_81104E4: @ 81104E4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08110500
	ldr r0, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	strh r1, [r0, 0x4]
_08110500:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08110548
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	b _0811055A
	.pool
_08110548:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl sub_80A8924
_0811055A:
	adds r0, r5, 0
	bl sub_80A6FD4
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x6]
	strh r0, [r5, 0x38]
	ldr r0, =sub_811057C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81104E4

	thumb_func_start sub_811057C
sub_811057C: @ 811057C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _08110592
	adds r0, r4, 0
	bl move_anim_8072740
	b _081105AE
_08110592:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	adds r0, 0xD
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3A]
_081105AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811057C

	thumb_func_start sub_81105B4
sub_81105B4: @ 81105B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081105F0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x20]
	ldrh r2, [r0]
	subs r1, r2
	strh r1, [r4, 0x20]
	b _081105FC
	.pool
_081105F0:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	adds r0, r1, 0
_081105FC:
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08110618
	ldrh r0, [r4, 0x22]
	adds r0, 0x8
	strh r0, [r4, 0x22]
_08110618:
	ldr r0, =sub_8110630
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81105B4

	thumb_func_start sub_8110630
sub_8110630: @ 8110630
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _08110664
	movs r0, 0
	strh r0, [r3, 0x2E]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_08110664:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _08110678
	adds r0, r3, 0
	bl move_anim_8072740
_08110678:
	pop {r0}
	bx r0
	thumb_func_end sub_8110630

	thumb_func_start sub_811067C
sub_811067C: @ 811067C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	ldr r0, =sub_81106A4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811067C

	thumb_func_start sub_81106A4
sub_81106A4: @ 81106A4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0x13
	bgt _081106B8
	adds r0, r1, 0x1
	strh r0, [r4, 0x32]
	b _081106F6
_081106B8:
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081106F6
	ldrh r1, [r4, 0x2E]
	subs r1, 0x1
	strh r1, [r4, 0x2E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081106F6
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8110700
	str r0, [r4, 0x1C]
_081106F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81106A4

	thumb_func_start sub_8110700
sub_8110700: @ 8110700
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8110700

	thumb_func_start sub_8110720
sub_8110720: @ 8110720
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08110740
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	b _08110762
	.pool
_08110740:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08110762
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r1, 0x6]
_08110762:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081107B2
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _081107B2
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	beq _081107A0
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081107B2
_081107A0:
	ldr r0, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	negs r1, r1
	strh r1, [r0, 0x4]
	movs r2, 0
	ldrsh r1, [r0, r2]
	negs r1, r1
	strh r1, [r0]
_081107B2:
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	ldr r6, =gBattleAnimArgs
	lsrs r4, 24
	ldrh r0, [r6, 0x4]
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r6, 0x6]
	adds r1, r2
	lsls r1, 16
	ldrh r2, [r7, 0x20]
	lsls r0, r4, 16
	asrs r0, 16
	subs r0, r2
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r7, 0x22]
	lsrs r5, r1, 16
	asrs r1, 16
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r7, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldrh r0, [r6, 0x8]
	strh r0, [r7, 0x2E]
	strh r4, [r7, 0x32]
	strh r5, [r7, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r7, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r7, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110720

	thumb_func_start sub_8110850
sub_8110850: @ 8110850
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08110870
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_08110870:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x6]
	adds r0, r1
	strh r0, [r6, 0x36]
	ldrh r0, [r4, 0xA]
	strh r0, [r6, 0x38]
	adds r0, r6, 0
	bl sub_80A68D4
	ldr r0, =sub_81108CC
	str r0, [r6, 0x1C]
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110850

	thumb_func_start sub_81108CC
sub_81108CC: @ 81108CC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _081108F8
	adds r0, r4, 0
	bl move_anim_8072740
	b _08110988
_081108F8:
	movs r0, 0x2E
	adds r0, r4
	mov r8, r0
	ldrh r7, [r4, 0x20]
	ldrh r5, [r4, 0x24]
	ldrh r1, [r4, 0x22]
	mov r12, r1
	ldrh r6, [r4, 0x26]
	mov r2, r8
	add r1, sp, 0x4
	movs r3, 0x7
_0811090E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0811090E
	adds r0, r7, r5
	lsls r0, 16
	lsrs r5, r0, 16
	mov r2, r12
	adds r0, r2, r6
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	bne _08110988
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	lsls r1, r5, 16
	asrs r1, 16
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r1, r2
	lsls r2, r6, 16
	asrs r2, 16
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	add r2, sp, 0x4
	mov r1, r8
	movs r3, 0x7
_0811097A:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0811097A
_08110988:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81108CC

	thumb_func_start sub_8110994
sub_8110994: @ 8110994
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081109B0
	ldr r4, =gAnimationBankAttacker
	b _081109B2
	.pool
_081109B0:
	ldr r4, =gAnimationBankTarget
_081109B2:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x12
	strh r0, [r5, 0x22]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110994

	thumb_func_start sub_81109F0
sub_81109F0: @ 81109F0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08110A10
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl sub_80A8924
_08110A10:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r4, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	adds r0, 0xE
	strh r0, [r5, 0x22]
	ldrb r1, [r6, 0x2]
	adds r0, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl AnimateSprite
	strh r4, [r5, 0x2E]
	strh r4, [r5, 0x30]
	movs r0, 0x4
	strh r0, [r5, 0x32]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	ldr r0, =0x0000ffba
	strh r0, [r5, 0x36]
	ldrh r0, [r6, 0x4]
	strh r0, [r5, 0x38]
	ldr r1, =sub_8110A70
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A6450
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81109F0

	thumb_func_start sub_8110A70
sub_8110A70: @ 8110A70
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x38]
	ldrh r2, [r4, 0x20]
	adds r0, r1, r2
	strh r0, [r4, 0x20]
	movs r0, 0xC0
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r0, 0x4
	strh r0, [r4, 0x32]
	movs r0, 0x20
	strh r0, [r4, 0x34]
	ldr r0, =0x0000ffe8
	strh r0, [r4, 0x36]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A6450
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110A70

	thumb_func_start sub_8110AB4
sub_8110AB4: @ 8110AB4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xA]
	bl StartSpriteAnim
	adds r0, r5, 0
	bl AnimateSprite
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08110AE4
	ldrh r0, [r5, 0x20]
	ldrh r1, [r4]
	subs r0, r1
	b _08110AEA
	.pool
_08110AE4:
	ldrh r0, [r4]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_08110AEA:
	strh r0, [r5, 0x20]
	ldr r3, =gBattleAnimArgs
	ldrh r2, [r3, 0x2]
	ldrh r0, [r5, 0x22]
	adds r2, r0
	movs r4, 0
	strh r2, [r5, 0x22]
	ldrh r0, [r3, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	strh r2, [r5, 0x34]
	ldrh r0, [r3, 0x6]
	adds r2, r0
	strh r2, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A6E14
	strh r4, [r5, 0x34]
	strh r4, [r5, 0x36]
	ldr r0, =sub_80A656C
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110AB4

	thumb_func_start sub_8110B38
sub_8110B38: @ 8110B38
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08110B54
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	b _08110B5C
	.pool
_08110B54:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
_08110B5C:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8110B80
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110B38

	thumb_func_start sub_8110B80
sub_8110B80: @ 8110B80
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08110BC6
	adds r0, r4, 0
	bl move_anim_8072740
_08110BC6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8110B80

	thumb_func_start sub_8110BCC
sub_8110BCC: @ 8110BCC
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08110C10
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_08110C10:
	ldr r0, =gUnknown_02022E18
	strh r5, [r0]
	ldr r4, =gUnknown_02022E1A
	strh r5, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08D8D58C
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r1, =gUnknown_08D8D410
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gUnknown_08D8DAB8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08110C6E
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08110C6E
	movs r5, 0x1
_08110C6E:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	strh r5, [r1, 0x8]
	ldr r0, =sub_8110CB0
	str r0, [r1]
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110BCC

	thumb_func_start sub_8110CB0
sub_8110CB0: @ 8110CB0
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0
	bne _08110CE4
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000fffa
	adds r0, r3, 0
	ldrh r3, [r1]
	adds r0, r3
	b _08110CEA
	.pool
_08110CE4:
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r1]
	adds r0, 0x6
_08110CEA:
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	ldr r3, =0x0000ffff
	adds r0, r3, 0
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	adds r0, r2
	movs r3, 0x20
	ldrsh r0, [r0, r3]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _08110D0C
	b _08110E3A
_08110D0C:
	lsls r0, 2
	ldr r1, =_08110D28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08110D28:
	.4byte _08110D3C
	.4byte _08110D7E
	.4byte _08110D98
	.4byte _08110DDA
	.4byte _08110DFC
_08110D3C:
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08110E3A
	strh r5, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bne _08110E3A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _08110E3A
_08110D7E:
	adds r0, r4, r5
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x65
	bne _08110E3A
	movs r0, 0x7
	strh r0, [r1, 0x1E]
	b _08110DF0
_08110D98:
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08110E3A
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _08110E3A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _08110E3A
_08110DDA:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	ldr r0, =gTasks
	adds r1, r4, r5
	lsls r1, 3
	adds r1, r0
_08110DF0:
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _08110E3A
	.pool
_08110DFC:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08110E10
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_08110E10:
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	adds r0, r5, 0
	bl move_anim_task_del
_08110E3A:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110CB0

	thumb_func_start sub_8110E4C
sub_8110E4C: @ 8110E4C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08110EC8
	ldr r4, =gBattleAnimArgs
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08110E98
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08110E98
	movs r0, 0x98
	lsls r0, 1
	strh r0, [r5, 0x20]
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	ldrb r1, [r5, 0x3]
	subs r0, 0x40
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r5, 0x3]
	b _08110E9C
	.pool
_08110E98:
	ldr r0, =0x0000ffc0
	strh r0, [r5, 0x20]
_08110E9C:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4]
	strh r0, [r5, 0x22]
	ldr r1, =gUnknown_08596BC0
	adds r0, r5, 0
	bl SetSubspriteTables
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x30]
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08110F24
	.pool
_08110EC8:
	ldrh r1, [r5, 0x30]
	ldrh r3, [r5, 0x34]
	adds r1, r3
	ldrh r2, [r5, 0x32]
	ldrh r0, [r5, 0x36]
	adds r2, r0
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r3, [r5, 0x24]
	adds r0, r3
	strh r0, [r5, 0x24]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r3, [r5, 0x26]
	adds r0, r3
	strh r0, [r5, 0x26]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r5, 0x34]
	ands r2, r0
	strh r2, [r5, 0x36]
	movs r1, 0x38
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08110F0E
	movs r2, 0x20
	ldrsh r0, [r5, r2]
	movs r3, 0x24
	ldrsh r1, [r5, r3]
	adds r0, r1
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	ble _08110F24
	b _08110F20
_08110F0E:
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _08110F24
_08110F20:
	ldr r0, =move_anim_8072740
	str r0, [r5, 0x1C]
_08110F24:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110E4C

	thumb_func_start sub_8110F30
sub_8110F30: @ 8110F30
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x8]
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110F30

	thumb_func_start sub_8110F74
sub_8110F74: @ 8110F74
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	movs r1, 0xC0
	lsls r1, 13
	adds r0, r1
	lsrs r7, r0, 16
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	movs r2, 0xC0
	lsls r2, 13
	adds r0, r2
	lsrs r0, 16
	mov r8, r0
	ldrb r1, [r5]
	movs r0, 0x2
	eors r0, r1
	ldrb r4, [r4]
	cmp r0, r4
	bne _08110FE4
	mov r8, r7
_08110FE4:
	bl sub_811135C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08111000
	movs r0, 0x20
	b _08111006
	.pool
_08111000:
	lsls r1, r5, 3
	movs r0, 0x30
	subs r0, r1
_08111006:
	strh r0, [r6, 0x18]
	movs r4, 0
	strh r4, [r6, 0x8]
	strh r4, [r6, 0x1E]
	strh r4, [r6, 0x1A]
	movs r0, 0x1
	strh r0, [r6, 0x20]
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bge _0811101E
	adds r0, 0x7
_0811101E:
	asrs r0, 3
	subs r0, 0x1
	strh r0, [r6, 0x1C]
	mov r2, r9
	lsls r0, r2, 3
	strh r0, [r6, 0xC]
	lsls r0, r7, 3
	strh r0, [r6, 0xE]
	mov r1, r10
	subs r0, r1, r2
	lsls r0, 3
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x10]
	mov r1, r8
	subs r0, r1, r7
	lsls r0, 3
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x12]
	strh r4, [r6, 0x14]
	strh r4, [r6, 0x16]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 8
	lsrs r4, 16
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	lsls r0, 24
	strh r4, [r6, 0x22]
	asrs r0, 24
	lsls r4, 16
	asrs r4, 16
	subs r0, r4
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x24]
	strh r5, [r6, 0xA]
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x26]
	ldr r0, =sub_81110A4
	str r0, [r6]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110F74

	thumb_func_start sub_81110A4
sub_81110A4: @ 81110A4
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _081110BE
	b _0811120C
_081110BE:
	lsls r0, 2
	ldr r1, =_081110D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081110D0:
	.4byte _081110E4
	.4byte _08111148
	.4byte _08111150
	.4byte _081111AC
	.4byte _081111FE
_081110E4:
	ldrh r2, [r4, 0x14]
	ldrh r0, [r4, 0x10]
	subs r2, r0
	strh r2, [r4, 0x14]
	ldrh r0, [r4, 0x16]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x16]
	ldr r3, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	lsls r2, 16
	asrs r2, 19
	strh r2, [r0, 0x24]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08111134
	movs r0, 0x14
	strh r0, [r4, 0x1E]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08111134:
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xA2
	bl PlaySE12WithPanning
	b _0811120C
	.pool
_08111148:
	ldrh r0, [r4, 0x1E]
	subs r0, 0x1
	strh r0, [r4, 0x1E]
	b _081111F0
_08111150:
	ldrh r0, [r4, 0x1A]
	subs r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _08111170
	ldrh r0, [r4, 0x10]
	ldrh r2, [r4, 0x14]
	adds r0, r2
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	strh r0, [r4, 0x16]
	b _0811117A
_08111170:
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x16]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0811117A:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x24]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x26]
	b _0811120C
	.pool
_081111AC:
	ldrh r0, [r4, 0x10]
	ldrh r2, [r4, 0xC]
	adds r0, r2
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0xE]
	adds r0, r1
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _081111EA
	movs r0, 0
	strh r0, [r4, 0x1A]
	adds r0, r4, 0
	bl sub_8111214
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x22]
	adds r1, r0
	strh r1, [r4, 0x22]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xAF
	bl PlaySE12WithPanning
_081111EA:
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
_081111F0:
	lsls r0, 16
	cmp r0, 0
	bne _0811120C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0811120C
_081111FE:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0811120C
	adds r0, r2, 0
	bl move_anim_task_del
_0811120C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81110A4

	thumb_func_start sub_8111214
sub_8111214: @ 8111214
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _08111304
	lsls r0, 2
	ldr r1, =_08111234
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08111234:
	.4byte _08111248
	.4byte _08111254
	.4byte _08111254
	.4byte _08111260
	.4byte _0811126C
_08111248:
	ldr r3, =gUnknown_08596C28
	movs r5, 0
	b _08111270
	.pool
_08111254:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x50
	b _08111270
	.pool
_08111260:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x40
	b _08111270
	.pool
_0811126C:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x30
_08111270:
	ldrh r1, [r4, 0xC]
	lsls r1, 16
	asrs r1, 19
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r4, 0xE]
	lsls r2, 16
	asrs r2, 19
	lsls r2, 16
	movs r6, 0x20
	ldrsh r0, [r4, r6]
	lsls r0, 2
	adds r1, r0
	lsls r1, 16
	lsrs r6, r1, 16
	asrs r1, 16
	lsrs r7, r2, 16
	asrs r2, 16
	adds r0, r3, 0
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081112FC
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x12
	strh r1, [r0, 0x2E]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	lsls r2, r1, 2
	adds r2, r1
	lsls r2, 2
	adds r2, r6, r2
	movs r6, 0xA
	ldrsh r3, [r4, r6]
	lsls r1, r3, 1
	adds r1, r3
	adds r2, r1
	strh r2, [r0, 0x32]
	strh r7, [r0, 0x36]
	movs r1, 0xA
	ldrsh r2, [r4, r1]
	lsls r2, 1
	movs r3, 0x10
	negs r3, r3
	adds r1, r3, 0
	subs r1, r2
	strh r1, [r0, 0x38]
	ldrh r3, [r0, 0x4]
	lsls r2, r3, 22
	lsrs r2, 22
	adds r2, r5
	ldr r5, =0x000003ff
	adds r1, r5, 0
	ands r2, r1
	ldr r1, =0xfffffc00
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x4]
	bl sub_80A68D4
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
_081112FC:
	movs r6, 0x20
	ldrsh r0, [r4, r6]
	negs r0, r0
	strh r0, [r4, 0x20]
_08111304:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111214

	thumb_func_start sub_811131C
sub_811131C: @ 811131C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0811134E
	ldr r0, =sub_81110A4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _08111348
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1E]
	subs r0, 0x1
	strh r0, [r1, 0x1E]
_08111348:
	adds r0, r4, 0
	bl DestroySprite
_0811134E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811131C

	thumb_func_start sub_811135C
sub_811135C: @ 811135C
	push {lr}
	ldr r0, =gDisableStructMoveAnim
	ldr r0, [r0]
	ldrb r1, [r0, 0x11]
	lsrs r0, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x4
	bls _0811137E
	movs r1, 0x1
_0811137E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811135C

	thumb_func_start sub_8111388
sub_8111388: @ 8111388
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x8]
	bl StartSpriteAnim
	ldrh r0, [r5]
	strh r0, [r4, 0x24]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	ldrh r1, [r5, 0x4]
	subs r0, r1
	strh r0, [r4, 0x34]
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_81113C8
	str r0, [r4, 0x1C]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111388

	thumb_func_start sub_81113C8
sub_81113C8: @ 81113C8
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r3]
	ldrh r1, [r2, 0x34]
	movs r3, 0x34
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08111400
	ldrh r3, [r2, 0x32]
	adds r0, r1, r3
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	adds r1, r0
	strh r1, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r1, 16
	cmp r1, 0
	ble _08111412
	movs r0, 0
	strh r0, [r2, 0x34]
	b _08111412
_08111400:
	ldrh r0, [r2, 0x30]
	subs r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _08111412
	adds r0, r2, 0
	bl move_anim_8072740
_08111412:
	pop {r0}
	bx r0
	thumb_func_end sub_81113C8

	thumb_func_start sub_8111418
sub_8111418: @ 8111418
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08111434
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_08111434:
	adds r0, r4, 0
	bl sub_80A7820
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111418

	thumb_func_start sub_8111444
sub_8111444: @ 8111444
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r3, [r2]
	ldrh r5, [r4, 0x20]
	adds r1, r3, r5
	strh r1, [r4, 0x20]
	ldrh r1, [r2, 0x2]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r3, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldrh r0, [r2, 0x4]
	strh r0, [r4, 0x38]
	ldrb r1, [r2, 0x6]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_811149C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111444

	thumb_func_start sub_811149C
sub_811149C: @ 811149C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x8
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0x28
	bl __divsi3
	ldrh r1, [r4, 0x24]
	adds r1, r0
	strh r1, [r4, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	subs r1, r0
	strh r1, [r4, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x8C
	ble _081114E6
	adds r0, r4, 0
	bl move_anim_8072740
_081114E6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811149C

	thumb_func_start sub_81114EC
sub_81114EC: @ 81114EC
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gMoveDmgMoveAnim
	ldr r0, [r2]
	cmp r0, 0x20
	bgt _08111500
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	strh r0, [r1, 0xE]
_08111500:
	ldr r2, [r2]
	adds r0, r2, 0
	subs r0, 0x21
	cmp r0, 0x20
	bhi _08111510
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
_08111510:
	cmp r2, 0x41
	ble _0811151A
	ldr r1, =gBattleAnimArgs
	movs r0, 0x2
	strh r0, [r1, 0xE]
_0811151A:
	adds r0, r3, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81114EC

	thumb_func_start sub_811152C
sub_811152C: @ 811152C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0811154E
	movs r0, 0
	bl sub_80A6DAC
	movs r0, 0xC8
	strh r0, [r5, 0xA]
_0811154E:
	ldr r4, =gUnknown_02022E22
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	movs r1, 0xA
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r0
	strh r1, [r4]
	ldrh r0, [r5, 0xA]
	subs r0, 0x3
	strh r0, [r5, 0xA]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x78
	bne _0811157A
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r6, 0
	bl move_anim_task_del
_0811157A:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811152C

	thumb_func_start sub_8111590
sub_8111590: @ 8111590
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081115BC
	movs r0, 0
	bl sub_80A6DAC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_02022E22
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
_081115BC:
	ldrh r0, [r4, 0xA]
	adds r0, 0x50
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0xA]
	ldr r6, =gUnknown_02022E22
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r0, 0x4
	bl Cos
	ldrh r4, [r4, 0xC]
	adds r0, r4
	strh r0, [r6]
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	ldr r0, =0x00000fff
	cmp r1, r0
	bne _081115F4
	movs r0, 0
	strh r0, [r6]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r5, 0
	bl move_anim_task_del
_081115F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111590

	thumb_func_start sub_811160C
sub_811160C: @ 811160C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_80A6FD4
	ldr r0, =sub_8111674
	str r0, [r4, 0x1C]
	movs r0, 0x10
	strh r0, [r4, 0x3A]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x3A]
	movs r0, 0x52
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811160C

	thumb_func_start sub_8111674
sub_8111674: @ 8111674
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8111764
	adds r0, r4, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _08111694
	ldr r0, =sub_81116E8
	str r0, [r4, 0x1C]
	b _081116DE
	.pool
_08111694:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x38]
	adds r0, r2, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x38]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _081116CC
	cmp r2, 0xC4
	ble _081116DE
_081116CC:
	lsls r0, 16
	cmp r0, 0
	ble _081116DE
	ldr r0, =gUnknown_02038440
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0xC4
	bl PlaySE12WithPanning
_081116DE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111674

	thumb_func_start sub_81116E8
sub_81116E8: @ 81116E8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_80A6F3C
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x38]
	adds r0, r2, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x38]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _0811172E
	cmp r2, 0xC4
	ble _0811173A
_0811172E:
	lsls r0, 16
	cmp r0, 0
	ble _0811173A
	movs r0, 0xC4
	bl PlaySE
_0811173A:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08111758
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_80A67F4
	str r0, [r4, 0x1C]
	b _0811175E
	.pool
_08111758:
	adds r0, r4, 0
	bl sub_8111764
_0811175E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81116E8

	thumb_func_start sub_8111764
sub_8111764: @ 8111764
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x3A]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	ble _08111788
	adds r0, r2, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	ldr r1, =0x010d0000
	cmp r0, r1
	bne _081117EE
	movs r0, 0
	b _081117EC
	.pool
_08111788:
	ldrh r1, [r4, 0x3C]
	adds r3, r1, 0x1
	strh r3, [r4, 0x3C]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	bne _081117EE
	ldr r1, =0xffffff00
	ands r1, r3
	strh r1, [r4, 0x3C]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _081117B0
	adds r0, r2, 0x1
	b _081117B2
	.pool
_081117B0:
	subs r0, r2, 0x1
_081117B2:
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x3A]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081117D4
	cmp r0, 0x10
	bne _081117E0
_081117D4:
	ldrh r0, [r4, 0x3C]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	eors r0, r1
	strh r0, [r4, 0x3C]
_081117E0:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081117EE
	movs r0, 0x80
	lsls r0, 1
_081117EC:
	strh r0, [r4, 0x3A]
_081117EE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8111764

	thumb_func_start sub_81117F4
sub_81117F4: @ 81117F4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r1, =sub_8111814
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81117F4

	thumb_func_start sub_8111814
sub_8111814: @ 8111814
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x41
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x82
	bhi _08111848
	ldrb r0, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x8
	b _08111852
_08111848:
	ldrb r0, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
_08111852:
	orrs r1, r0
	strb r1, [r4, 0x5]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x13
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x32]
	adds r0, 0x50
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3D
	bne _08111884
	adds r0, r4, 0
	bl move_anim_8072740
_08111884:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8111814

	thumb_func_start sub_811188C
sub_811188C: @ 811188C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A7270
	adds r0, r4, 0
	movs r1, 0x80
	movs r2, 0x80
	movs r3, 0
	bl obj_id_set_rotscale
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x80
	strh r1, [r0, 0x8]
	ldr r1, =gBattleAnimArgs
	ldrh r1, [r1]
	strh r1, [r0, 0xA]
	strh r2, [r0, 0xC]
	movs r1, 0x10
	strh r1, [r0, 0xE]
	ldr r1, =sub_8111914
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811188C

	thumb_func_start sub_8111914
sub_8111914: @ 8111914
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0811195C
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0xC]
	adds r1, 0x1
	strh r1, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bne _0811195C
	ldr r0, =sub_811196C
	str r0, [r4]
_0811195C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111914

	thumb_func_start sub_811196C
sub_811196C: @ 811196C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08111994
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	b _081119D8
	.pool
_08111994:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r1, r0, 24
	ldrh r0, [r4, 0x8]
	adds r0, 0x8
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	bgt _081119BC
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	adds r0, r1, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	b _081119D8
_081119BC:
	adds r0, r1, 0
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
_081119D8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811196C

	thumb_func_start sub_81119E0
sub_81119E0: @ 81119E0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r5, [r4, 0x20]
	ldrh r6, [r4, 0x22]
	ldr r0, =gAnimationBankAttacker
	mov r8, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	mov r9, r1
	strh r0, [r4, 0x20]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	mov r1, r9
	strh r1, [r4, 0x2E]
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r4, 0x30]
	ldrh r1, [r2, 0x2]
	strh r1, [r4, 0x32]
	ldrh r1, [r2, 0x4]
	strh r1, [r4, 0x34]
	ldrh r1, [r4, 0x20]
	lsls r1, 4
	strh r1, [r4, 0x36]
	lsls r0, 4
	strh r0, [r4, 0x38]
	lsls r5, 16
	asrs r5, 16
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	subs r5, r0
	lsls r5, 4
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r1, 1
	adds r0, r5, 0
	str r2, [sp]
	bl __divsi3
	strh r0, [r4, 0x3A]
	lsls r6, 16
	asrs r6, 16
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	subs r6, r0
	lsls r6, 4
	ldr r2, [sp]
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r1, 1
	adds r0, r6, 0
	bl __divsi3
	strh r0, [r4, 0x3C]
	ldr r0, =sub_8111A88
	str r0, [r4, 0x1C]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81119E0

	thumb_func_start sub_8111A88
sub_8111A88: @ 8111A88
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08111AD2
	cmp r0, 0x1
	bgt _08111A9E
	cmp r0, 0
	beq _08111AA8
	b _08111B96
_08111A9E:
	cmp r0, 0x2
	beq _08111B3C
	cmp r0, 0x3
	beq _08111B90
	b _08111B96
_08111AA8:
	ldrh r0, [r5, 0x3A]
	ldrh r2, [r5, 0x36]
	adds r0, r2
	strh r0, [r5, 0x36]
	ldrh r1, [r5, 0x3C]
	ldrh r2, [r5, 0x38]
	adds r1, r2
	strh r1, [r5, 0x38]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r5, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r5, 0x22]
	ldrh r0, [r5, 0x30]
	subs r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	cmp r0, 0
	bgt _08111B96
	b _08111B82
_08111AD2:
	ldrh r0, [r5, 0x32]
	subs r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	cmp r0, 0
	bgt _08111B96
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x30]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x20]
	lsls r0, 4
	strh r0, [r5, 0x36]
	ldrh r0, [r5, 0x22]
	lsls r0, 4
	strh r0, [r5, 0x38]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	subs r0, r1
	lsls r0, 4
	movs r2, 0x34
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, 0x3A]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r2, 0x22
	ldrsh r1, [r5, r2]
	subs r0, r1
	lsls r0, 4
	movs r2, 0x34
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, 0x3C]
	b _08111B82
	.pool
_08111B3C:
	ldrh r0, [r5, 0x3A]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldrh r1, [r5, 0x3C]
	ldrh r2, [r5, 0x38]
	adds r1, r2
	strh r1, [r5, 0x38]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r5, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r5, 0x22]
	ldrh r0, [r5, 0x34]
	subs r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	cmp r0, 0
	bgt _08111B96
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_08111B82:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08111B96
	.pool
_08111B90:
	adds r0, r5, 0
	bl move_anim_8074EE0
_08111B96:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8111A88

	thumb_func_start sub_8111B9C
sub_8111B9C: @ 8111B9C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =sub_8111BB4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111B9C

	thumb_func_start sub_8111BB4
sub_8111BB4: @ 8111BB4
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r5, 0
	movs r6, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08111C4A
	adds r1, r3, 0
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x4
	ands r0, r2
	adds r4, r1, 0
	cmp r0, 0
	bne _08111BDE
	movs r0, 0x4
	orrs r0, r2
	strb r0, [r4]
_08111BDE:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08111BEE
	cmp r0, 0x1
	beq _08111BF8
	movs r6, 0x1
	b _08111C02
_08111BEE:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x2
	bne _08111C02
	b _08111C06
_08111BF8:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x4
	bne _08111C02
	movs r5, 0x1
_08111C02:
	cmp r5, 0
	beq _08111C38
_08111C06:
	ldrb r2, [r4]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r3, 0x32]
	strh r1, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _08111C4A
	strh r1, [r3, 0x32]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _08111C4A
_08111C38:
	cmp r6, 0
	beq _08111C44
	adds r0, r3, 0
	bl move_anim_8072740
	b _08111C4A
_08111C44:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
_08111C4A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8111BB4

	thumb_func_start sub_8111C50
sub_8111C50: @ 8111C50
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	movs r6, 0
	movs r1, 0
	strh r0, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bge _08111C80
	adds r0, r4, 0
	bl move_anim_task_del
	b _08111D5C
	.pool
_08111C80:
	strh r1, [r5, 0xA]
	movs r0, 0xF
	strh r0, [r5, 0xC]
	movs r0, 0x2
	strh r0, [r5, 0xE]
	strh r1, [r5, 0x10]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r5, 0xE]
	lsls r1, 8
	ldrh r0, [r5, 0xC]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r4, =gSprites
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x50
	strh r1, [r0, 0x2E]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08111CF4
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff70
	strh r1, [r0, 0x30]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x70
	b _08111D12
	.pool
_08111CF4:
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x90
	strh r1, [r0, 0x30]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff90
_08111D12:
	strh r1, [r0, 0x32]
	ldr r4, =gSprites
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r2, 0
	strh r2, [r0, 0x34]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x36]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =SpriteCallbackDummy
	bl StoreSpriteCallbackInData6
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_80A656C
	str r1, [r0]
	ldr r0, =sub_8111D78
	str r0, [r5]
_08111D5C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111C50

	thumb_func_start sub_8111D78
sub_8111D78: @ 8111D78
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08111E1C
	cmp r0, 0x1
	bgt _08111DA0
	cmp r0, 0
	beq _08111DA6
	b _08111E48
	.pool
_08111DA0:
	cmp r0, 0x2
	beq _08111E42
	b _08111E48
_08111DA6:
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r0, 0x3
	ands r0, r1
	strh r0, [r4, 0x12]
	cmp r0, 0x1
	bne _08111DC4
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08111DC4
	subs r0, r1, 0x1
	strh r0, [r4, 0xC]
_08111DC4:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	bne _08111DDA
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _08111DDA
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
_08111DDA:
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0xC]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r4, 0xC]
	movs r0, 0x80
	lsls r0, 13
	cmp r1, r0
	bne _08111E48
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x50
	ble _08111E48
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
	movs r0, 0x1
	strh r0, [r4, 0x10]
	b _08111E48
	.pool
_08111E1C:
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08111E48
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	b _08111E48
_08111E42:
	adds r0, r2, 0
	bl move_anim_task_del
_08111E48:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8111D78

	thumb_func_start sub_8111E50
sub_8111E50: @ 8111E50
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r2, =gTasks
	adds r1, r2
	movs r2, 0
	strh r2, [r1, 0x26]
	ldr r2, =sub_8111E78
	str r2, [r1]
	bl _call_via_r2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111E50

	thumb_func_start sub_8111E78
sub_8111E78: @ 8111E78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bls _08111EA4
	b _081120C6
_08111EA4:
	lsls r0, 2
	ldr r1, =_08111EBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08111EBC:
	.4byte _08111ED0
	.4byte _08111FD0
	.4byte _08112014
	.4byte _0811207C
	.4byte _081120A8
_08111ED0:
	ldr r7, =0x00002771
	adds r0, r7, 0
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	mov r8, r2
	strh r0, [r5, 0x24]
	cmp r0, 0xFF
	beq _08111EFE
	cmp r0, 0xF
	beq _08111EFE
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	strh r0, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bge _08111F0C
	adds r0, r7, 0
	bl FreeSpritePaletteByTag
_08111EFE:
	adds r0, r4, 0
	bl move_anim_task_del
	b _081120CC
	.pool
_08111F0C:
	ldr r4, =gSprites
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r2, [r5, 0x24]
	lsls r2, 4
	ldrb r3, [r1, 0x5]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 31
	adds r2, 0x3E
	lsrs r1, 31
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	mov r2, r8
	strh r2, [r5, 0xA]
	strh r2, [r5, 0xC]
	movs r0, 0x10
	strh r0, [r5, 0xE]
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	lsls r0, 4
	strh r0, [r5, 0x10]
	cmp r6, 0x1
	bne _08111FC4
	movs r1, 0x80
	lsls r1, 2
	b _08111FC8
	.pool
_08111FC4:
	movs r1, 0x80
	lsls r1, 3
_08111FC8:
	movs r0, 0
	bl ClearGpuRegBits
	b _081120C6
_08111FD0:
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	adds r0, 0x10
	lsls r0, 4
	strh r0, [r5, 0x24]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	lsls r0, 1
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	lsls r1, 1
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	ldrh r0, [r5, 0x10]
	ldr r3, =0x00003c0d
	movs r1, 0x10
	movs r2, 0xA
	bl BlendPalette
	b _081120C6
	.pool
_08112014:
	ldr r2, =gSprites
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r1, r0
	subs r1, 0x20
	lsls r1, 16
	lsrs r2, r1, 16
	cmp r1, 0
	bge _08112034
	movs r2, 0
_08112034:
	cmp r6, 0x1
	bne _08112054
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, r2, 0
	adds r1, 0x40
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	str r2, [sp]
	movs r2, 0x4
	str r2, [sp, 0x4]
	str r6, [sp, 0x8]
	b _0811206C
	.pool
_08112054:
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, r2, 0
	adds r1, 0x40
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	str r2, [sp]
	movs r2, 0x8
	str r2, [sp, 0x4]
	movs r2, 0x1
	str r2, [sp, 0x8]
_0811206C:
	movs r2, 0x2
	movs r3, 0x6
	bl sub_80BA384
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1C]
	b _081120C6
_0811207C:
	cmp r6, 0x1
	bne _08112090
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _08112098
	.pool
_08112090:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_08112098:
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	b _081120C6
	.pool
_081120A8:
	cmp r6, 0x1
	bne _081120B8
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	bl SetGpuRegBits
	b _081120C2
_081120B8:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl SetGpuRegBits
_081120C2:
	ldr r0, =sub_81120DC
	str r0, [r5]
_081120C6:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
_081120CC:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111E78

	thumb_func_start sub_81120DC
sub_81120DC: @ 81120DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r0, 0x1
	ands r0, r1
	strh r0, [r4, 0x12]
	cmp r0, 0
	bne _08112114
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x12
	bl __divsi3
	strh r0, [r4, 0xC]
_08112114:
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bne _08112136
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x12
	bl __divsi3
	movs r1, 0x10
	subs r1, r0
	strh r1, [r4, 0xE]
_08112136:
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0xC]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x80
	bne _0811215E
	movs r0, 0
	strh r0, [r4, 0x26]
	ldr r1, =sub_8112170
	str r1, [r4]
	adds r0, r5, 0
	bl _call_via_r1
_0811215E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81120DC

	thumb_func_start sub_8112170
sub_8112170: @ 8112170
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _081121DC
	cmp r0, 0x1
	bgt _081121A8
	cmp r0, 0
	beq _081121AE
	b _08112258
	.pool
_081121A8:
	cmp r0, 0x2
	beq _081121F0
	b _08112258
_081121AE:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	movs r0, 0x1
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x24]
	cmp r6, 0x1
	bne _081121D0
	movs r1, 0x80
	lsls r1, 2
	b _081121D4
	.pool
_081121D0:
	movs r1, 0x80
	lsls r1, 3
_081121D4:
	movs r0, 0
	bl ClearGpuRegBits
	b _08112258
_081121DC:
	ldrh r0, [r4, 0x10]
	ldr r3, =0x00003c0d
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	b _08112258
	.pool
_081121F0:
	ldr r3, =gSprites
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	bl obj_delete_but_dont_free_vram
	ldr r0, =0x00002771
	bl FreeSpritePaletteByTag
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	cmp r6, 0x1
	bne _08112248
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	bl SetGpuRegBits
	b _08112252
	.pool
_08112248:
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	bl SetGpuRegBits
_08112252:
	adds r0, r5, 0
	bl move_anim_task_del
_08112258:
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8112170

	thumb_func_start sub_8112264
sub_8112264: @ 8112264
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081122AC
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	movs r2, 0xE0
	lsls r2, 13
	adds r0, r2
	lsrs r5, r0, 16
	ldr r4, =gAnimationBankTarget
	b _081122D0
	.pool
_081122AC:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	movs r2, 0xE0
	lsls r2, 13
	adds r0, r2
	lsrs r5, r0, 16
	ldr r4, =gAnimationBankAttacker
_081122D0:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 8
	movs r1, 0xE0
	lsls r1, 13
	adds r0, r1
	lsrs r0, 16
	mov r9, r0
	mov r8, r5
	mov r2, r9
	subs r4, r2, r5
	lsls r4, 16
	lsrs r4, 16
	lsls r0, r6, 4
	strh r0, [r7, 0x2E]
	lsls r0, r5, 4
	strh r0, [r7, 0x30]
	mov r1, r10
	subs r0, r1, r6
	lsls r0, 4
	ldr r5, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r7, 0x32]
	lsls r4, 16
	asrs r4, 12
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl __divsi3
	strh r0, [r7, 0x34]
	ldrh r0, [r5, 0x2]
	strh r0, [r7, 0x36]
	mov r1, r10
	strh r1, [r7, 0x38]
	mov r2, r9
	strh r2, [r7, 0x3A]
	movs r1, 0x36
	ldrsh r0, [r7, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r7, 0x3C]
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r7, 0x5]
	strh r6, [r7, 0x20]
	mov r2, r8
	strh r2, [r7, 0x22]
	ldr r0, =sub_8112384
	str r0, [r7, 0x1C]
	adds r2, r7, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112264

	thumb_func_start sub_8112384
sub_8112384: @ 8112384
	push {r4,lr}
	adds r2, r0, 0
	ldrh r3, [r2, 0x36]
	movs r1, 0x36
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _081123BC
	ldrh r0, [r2, 0x32]
	ldrh r4, [r2, 0x2E]
	adds r0, r4
	strh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x34]
	ldrh r4, [r2, 0x30]
	adds r1, r4
	strh r1, [r2, 0x30]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r2, 0x22]
	subs r0, r3, 0x1
	strh r0, [r2, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _081123BC
	strh r0, [r2, 0x2E]
_081123BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8112384

	thumb_func_start sub_81123C4
sub_81123C4: @ 81123C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	str r1, [sp]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0
	ldr r1, [sp]
	strh r0, [r1, 0x12]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	strh r0, [r1, 0x18]
	movs r0, 0x10
	strh r0, [r1, 0x1A]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r1, 0x1C]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08112434
	b _08112530
_08112434:
	movs r4, 0
_08112436:
	lsls r1, r4, 16
	asrs r3, r1, 16
	ldr r0, =gAnimationBankAttacker
	ldrb r2, [r0]
	str r1, [sp, 0x10]
	cmp r3, r2
	beq _08112502
	movs r0, 0x2
	eors r2, r0
	cmp r3, r2
	beq _08112502
	lsls r0, r4, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _08112502
	ldr r6, [sp, 0x4]
	ldr r3, [sp, 0x8]
	lsls r0, r3, 16
	asrs r7, r0, 16
	ldr r0, =gUnknown_08596DB8
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0x37
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x40
	beq _08112502
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80A861C
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	mov r0, r8
	lsls r5, r0, 4
	add r5, r8
	lsls r5, 2
	ldr r1, =gSprites
	adds r4, r5, r1
	lsls r0, r6, 4
	strh r0, [r4, 0x2E]
	lsls r0, r7, 4
	strh r0, [r4, 0x30]
	mov r2, r10
	subs r0, r2, r6
	lsls r0, 4
	ldr r3, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r1, [r3, r2]
	bl __divsi3
	strh r0, [r4, 0x32]
	mov r3, r9
	lsls r0, r3, 16
	asrs r0, 16
	subs r0, r7
	lsls r0, 4
	ldr r2, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl __divsi3
	strh r0, [r4, 0x34]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x36]
	mov r2, r10
	strh r2, [r4, 0x38]
	mov r3, r9
	strh r3, [r4, 0x3A]
	ldr r0, =gSprites + 0x1C
	adds r5, r0
	ldr r0, =sub_8112384
	str r0, [r5]
	ldr r2, [sp]
	movs r3, 0x20
	ldrsh r1, [r2, r3]
	adds r1, 0xD
	lsls r1, 1
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r2, 0x20]
	adds r0, 0x1
	strh r0, [r2, 0x20]
_08112502:
	ldr r2, [sp, 0x10]
	movs r3, 0x80
	lsls r3, 9
	adds r0, r2, r3
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _08112436
	b _081125B4
	.pool
_08112530:
	ldr r0, =gUnknown_08596DB8
	ldr r7, [sp, 0x4]
	ldr r2, [sp, 0x8]
	lsls r1, r2, 16
	asrs r1, 16
	str r1, [sp, 0xC]
	adds r1, r7, 0
	ldr r2, [sp, 0xC]
	movs r3, 0x37
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x40
	beq _081125B4
	movs r3, 0x30
	mov r10, r3
	movs r0, 0x28
	mov r9, r0
	ldr r6, =gSprites
	mov r1, r8
	lsls r5, r1, 4
	add r5, r8
	lsls r5, 2
	adds r4, r5, r6
	lsls r0, r7, 4
	strh r0, [r4, 0x2E]
	ldr r2, [sp, 0xC]
	lsls r0, r2, 4
	strh r0, [r4, 0x30]
	subs r0, r3, r7
	lsls r0, 4
	ldr r3, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r1, [r3, r2]
	bl __divsi3
	strh r0, [r4, 0x32]
	mov r3, r9
	ldr r1, [sp, 0xC]
	subs r0, r3, r1
	lsls r0, 4
	ldr r2, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl __divsi3
	strh r0, [r4, 0x34]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x36]
	mov r2, r10
	strh r2, [r4, 0x38]
	mov r3, r9
	strh r3, [r4, 0x3A]
	adds r6, 0x1C
	adds r5, r6
	ldr r0, =sub_8112384
	str r0, [r5]
	mov r1, r8
	ldr r0, [sp]
	strh r1, [r0, 0x22]
	movs r0, 0x1
	ldr r2, [sp]
	strh r0, [r2, 0x20]
_081125B4:
	ldr r0, =sub_81125E0
	ldr r3, [sp]
	str r0, [r3]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81123C4

	thumb_func_start sub_81125E0
sub_81125E0: @ 81125E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _08112696
	cmp r1, 0x1
	bgt _08112608
	cmp r1, 0
	beq _08112616
	b _08112752
	.pool
_08112608:
	cmp r1, 0x2
	bne _0811260E
	b _08112728
_0811260E:
	cmp r1, 0x3
	bne _08112614
	b _0811273C
_08112614:
	b _08112752
_08112616:
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0811267C
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811267C
	strh r1, [r4, 0x12]
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0811264C
	ldrh r1, [r4, 0x18]
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _0811265A
	adds r0, r1, 0x1
	strh r0, [r4, 0x18]
	b _0811265A
_0811264C:
	ldrh r1, [r4, 0x1A]
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0811265A
	subs r0, r1, 0x1
	strh r0, [r4, 0x1A]
_0811265A:
	ldrh r1, [r4, 0x1A]
	lsls r1, 8
	ldrh r0, [r4, 0x18]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	cmp r0, 0x17
	ble _0811267C
	movs r0, 0
	strh r0, [r4, 0x16]
	movs r0, 0x1
	strh r0, [r4, 0x14]
_0811267C:
	ldrh r1, [r4, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0811268C
	subs r0, r1, 0x1
	strh r0, [r4, 0x1C]
	b _08112752
_0811268C:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08112752
	b _08112734
_08112696:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08112752
	movs r0, 0
	strh r0, [r4, 0x12]
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
	ands r0, r1
	lsls r0, 16
	cmp r0, 0
	beq _081126C6
	ldrh r1, [r4, 0x18]
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081126D4
	subs r0, r1, 0x1
	strh r0, [r4, 0x18]
	b _081126D4
_081126C6:
	ldrh r1, [r4, 0x1A]
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _081126D4
	adds r0, r1, 0x1
	strh r0, [r4, 0x1A]
_081126D4:
	ldrh r1, [r4, 0x1A]
	lsls r1, 8
	ldrh r0, [r4, 0x18]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r4, 0x18]
	movs r0, 0x80
	lsls r0, 13
	cmp r1, r0
	bne _08112752
	movs r5, 0
	b _08112718
_081126F4:
	adds r1, r5, 0
	adds r1, 0xD
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0x8
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_08112718:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _081126F4
	b _08112734
	.pool
_08112728:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	cmp r0, 0
	ble _08112752
_08112734:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08112752
_0811273C:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_task_del
_08112752:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81125E0

	thumb_func_start sub_8112758
sub_8112758: @ 8112758
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f1f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0xC8
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _081127A0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _081127B8
_081127A0:
	movs r6, 0x28
	b _081127BA
	.pool
_081127B8:
	movs r6, 0xC8
_081127BA:
	ldr r1, =gUnknown_02022E24
	lsls r3, r6, 16
	asrs r2, r3, 16
	lsls r0, r2, 8
	orrs r0, r2
	strh r0, [r1]
	ldr r1, =gUnknown_02022E26
	movs r5, 0x28
	ldr r0, =0x00002828
	strh r0, [r1]
	lsrs r3, 16
	movs r1, 0xF0
	subs r1, r2
	movs r4, 0x48
	ldr r2, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r2
	strh r3, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r5, [r0, 0xE]
	strh r4, [r0, 0x10]
	strh r6, [r0, 0x12]
	strh r5, [r0, 0x14]
	ldr r1, =sub_811280C
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112758

	thumb_func_start sub_811280C
sub_811280C: @ 811280C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _0811292C  @ =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0x8]
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
	ldrh r5, [r4, 0xA]
	ldrh r7, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	mov r10, r0
	ldrh r2, [r4, 0x10]
	str r2, [sp, 0xC]
	ldrh r0, [r4, 0x12]
	ldrh r2, [r4, 0x14]
	mov r8, r2
	lsls r1, 16
	asrs r6, r1, 16
	cmp r6, 0xF
	ble _08112848
	b _08112938
_08112848:
	lsls r0, 16
	asrs r0, 16
	bl __floatsidf
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	lsls r0, r5, 16
	asrs r0, 16
	bl __floatsidf
	ldr r2, _08112930  @ =0x3FB00000
	ldr r3, _08112934  @ =0x00000000
	bl __muldf3
	adds r5, r1, 0
	adds r4, r0, 0
	adds r0, r6, 0
	bl __floatsidf
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	adds r1, r5, 0
	adds r0, r4, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	bl __subdf3
	bl __fixunsdfsi
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r0, r7, 16
	asrs r0, 16
	bl __floatsidf
	ldr r2, _08112930  @ =0x3FB00000
	ldr r3, _08112934  @ =0x00000000
	bl __muldf3
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	bl __adddf3
	bl __fixunsdfsi
	lsls r0, 16
	lsrs r7, r0, 16
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	bl __floatsidf
	adds r5, r1, 0
	adds r4, r0, 0
	mov r2, r10
	lsls r0, r2, 16
	asrs r0, 16
	bl __floatsidf
	ldr r2, _08112930  @ =0x3FB00000
	ldr r3, _08112934  @ =0x00000000
	bl __muldf3
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __subdf3
	bl __fixunsdfsi
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, [sp, 0xC]
	lsls r0, r1, 16
	asrs r0, 16
	bl __floatsidf
	ldr r2, _08112930  @ =0x3FB00000
	ldr r3, _08112934  @ =0x00000000
	bl __muldf3
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __adddf3
	bl __fixunsdfsi
	lsls r0, 16
	lsrs r5, r0, 16
	b _08112966
	.align 2, 0
_0811292C:
	.4byte gTasks
_08112930:
	.4byte 0x3FB00000
_08112934:
	.4byte 0x00000000
_08112938:
	movs r2, 0
	mov r9, r2
	movs r7, 0xF0
	movs r6, 0
	movs r5, 0x70
	str r6, [sp]
	str r6, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r3, 0
	bl sub_80A75AC
	lsls r0, 16
	lsrs r0, 16
	str r6, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, _08112988 @=sub_8112994
	str r0, [r4]
_08112966:
	ldr r1, _0811298C @=gUnknown_02022E24
	mov r2, r9
	lsls r0, r2, 8
	orrs r7, r0
	strh r7, [r1]
	ldr r1, _08112990 @=gUnknown_02022E26
	lsls r0, r6, 8
	orrs r5, r0
	strh r5, [r1]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08112988:
	.4byte sub_8112994
_0811298C:
	.4byte gUnknown_02022E24
_08112990:
	.4byte gUnknown_02022E26
	thumb_func_end sub_811280C

	thumb_func_start sub_8112994
sub_8112994: @ 8112994
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081129DA
	ldr r0, =gUnknown_02022E24
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_task_del
_081129DA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112994

	thumb_func_start sub_81129F0
sub_81129F0: @ 81129F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08112A24
	movs r2, 0x18
	ldr r3, =0x0000fffe
	ldrb r0, [r4, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r4, 0x3]
	b _08112A28
	.pool
_08112A24:
	ldr r2, =0x0000ffe8
	movs r3, 0x2
_08112A28:
	lsls r0, r2, 16
	asrs r0, 16
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r3, [r4, 0x30]
	movs r0, 0x3C
	strh r0, [r4, 0x2E]
	ldr r0, =sub_8112A4C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81129F0

	thumb_func_start sub_8112A4C
sub_8112A4C: @ 8112A4C
	push {r4,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0
	ble _08112A5E
	subs r0, r1, 0x1
	b _08112AC2
_08112A5E:
	ldrh r0, [r3, 0x30]
	ldrh r4, [r3, 0x24]
	adds r1, r0, r4
	strh r1, [r3, 0x24]
	adds r0, r1, 0x7
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bls _08112AC4
	ldrh r0, [r3, 0x20]
	adds r0, r1
	strh r0, [r3, 0x20]
	movs r0, 0
	strh r0, [r3, 0x24]
	ldrh r2, [r3, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x8
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _08112AC0
	movs r0, 0x1E
	strh r0, [r3, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r3, 0x1C]
	ldr r1, =sub_8112ACC
	adds r0, r3, 0
	bl StoreSpriteCallbackInData6
	b _08112AC4
	.pool
_08112AC0:
	movs r0, 0x28
_08112AC2:
	strh r0, [r3, 0x2E]
_08112AC4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8112A4C

	thumb_func_start sub_8112ACC
sub_8112ACC: @ 8112ACC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _08112AF6
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x32]
	b _08112B3A
_08112AF6:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _08112B06
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _08112B3A
_08112B06:
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	movs r1, 0x10
	subs r1, r0
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08112B3A
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8112B44
	str r0, [r4, 0x1C]
_08112B3A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112ACC

	thumb_func_start sub_8112B44
sub_8112B44: @ 8112B44
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112B44

	thumb_func_start sub_8112B78
sub_8112B78: @ 8112B78
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r1, 0xC
	bl Sin
	strh r0, [r5, 0x24]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08112B9C
	ldrh r0, [r5, 0x24]
	negs r0, r0
	strh r0, [r5, 0x24]
_08112B9C:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x6
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08112BE8
	ldr r0, =0x0000050b
	strh r0, [r5, 0x3A]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r5, 0x3A]
	movs r0, 0x52
	bl SetGpuReg
	b _08112C40
	.pool
_08112BE8:
	cmp r0, 0x1E
	ble _08112C40
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r1, [r5, 0x3A]
	lsls r0, r1, 16
	asrs r0, 24
	lsls r0, 16
	movs r6, 0xFF
	ands r6, r1
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r7, r0, 16
	cmp r7, 0x10
	bls _08112C0C
	movs r7, 0x10
_08112C0C:
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r0, 0
	bge _08112C18
	movs r6, 0
_08112C18:
	lsls r4, r7, 8
	orrs r4, r6
	lsls r1, r4, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	strh r4, [r5, 0x3A]
	cmp r7, 0x10
	bne _08112C40
	cmp r6, 0
	bne _08112C40
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8112C4C
	str r0, [r5, 0x1C]
_08112C40:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112B78

	thumb_func_start sub_8112C4C
sub_8112C4C: @ 8112C4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8112C4C

	thumb_func_start sub_8112C6C
sub_8112C6C: @ 8112C6C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r6, 0
	strh r6, [r4, 0x8]
	movs r0, 0x10
	mov r8, r0
	mov r0, r8
	strh r0, [r4, 0xA]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1A]
	ldrb r0, [r5]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	asrs r1, 1
	adds r1, 0x8
	strh r1, [r4, 0x1E]
	strh r6, [r4, 0x16]
	ldrb r0, [r5]
	bl sub_80A8328
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	ldrb r0, [r5]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x2
	strh r0, [r4, 0x14]
	strh r6, [r4, 0xE]
	mov r0, r8
	strh r0, [r4, 0x10]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	strh r6, [r4, 0x18]
	ldr r0, =sub_8112D10
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112C6C

	thumb_func_start sub_8112D10
sub_8112D10: @ 8112D10
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bls _08112D2A
	b _08112E96
_08112D2A:
	lsls r0, 2
	ldr r1, =_08112D3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08112D3C:
	.4byte _08112D54
	.4byte _08112DC4
	.4byte _08112E06
	.4byte _08112E1A
	.4byte _08112E70
	.4byte _08112E80
_08112D54:
	movs r6, 0
_08112D56:
	movs r2, 0x1A
	ldrsh r1, [r4, r2]
	movs r0, 0x1C
	ldrsh r2, [r4, r0]
	ldrb r3, [r4, 0x14]
	ldr r0, =gUnknown_08596E30
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08112DAA
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r1
	strh r7, [r5, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08112D8C
	movs r1, 0x1
_08112D8C:
	strh r1, [r5, 0x30]
	movs r0, 0x2A
	muls r0, r6
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r4, 0x1E]
	strh r0, [r5, 0x34]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 1
	strh r0, [r5, 0x38]
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
_08112DAA:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _08112D56
	b _08112E78
	.pool
_08112DC4:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08112DE2
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0xD
	bgt _08112DF0
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _08112DF0
_08112DE2:
	ldrh r1, [r4, 0x10]
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0x4
	ble _08112DF0
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
_08112DF0:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, 0xE]
	ldrh r1, [r4, 0x10]
	cmp r0, 0xE
	bne _08112E60
	cmp r1, 0x4
	bne _08112E60
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08112E5A
_08112E06:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _08112E96
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08112E78
_08112E1A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08112E38
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08112E46
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _08112E46
_08112E38:
	ldrh r1, [r4, 0x10]
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _08112E46
	adds r0, r1, 0x1
	strh r0, [r4, 0x10]
_08112E46:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, 0xE]
	ldrh r1, [r4, 0x10]
	cmp r0, 0
	bne _08112E60
	cmp r1, 0x10
	bne _08112E60
	movs r0, 0x1
	strh r0, [r4, 0x18]
_08112E5A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08112E60:
	lsls r1, 8
	orrs r1, r2
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _08112E96
_08112E70:
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08112E96
_08112E78:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08112E96
_08112E80:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r7, 0
	bl move_anim_task_del
_08112E96:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8112D10

	thumb_func_start sub_8112E9C
sub_8112E9C: @ 8112E9C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08112EAE
	ldrh r0, [r4, 0x32]
	adds r0, 0x2
	b _08112EB2
_08112EAE:
	ldrh r0, [r4, 0x32]
	subs r0, 0x2
_08112EB2:
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x32]
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	subs r0, 0x41
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7E
	bhi _08112EF4
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x12]
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	b _08112F08
	.pool
_08112EF4:
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x3
	ldrb r1, [r0, 0x12]
	ands r1, r2
_08112F08:
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	lsls r0, 3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	movs r1, 0x7
	bl Sin
	strh r0, [r4, 0x26]
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08112F56
	ldrh r0, [r1, 0x16]
	subs r0, 0x1
	strh r0, [r1, 0x16]
	adds r0, r4, 0
	bl DestroySprite
_08112F56:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112E9C

	thumb_func_start sub_8112F60
sub_8112F60: @ 8112F60
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r3]
	ldr r2, =gBankSpriteIds
	ldr r1, =gAnimationBankAttacker
	ldrb r1, [r1]
	adds r1, r2
	ldrb r1, [r1]
	strh r1, [r0, 0x38]
	movs r1, 0x80
	strh r1, [r0, 0x2E]
	movs r1, 0xA
	strh r1, [r0, 0x30]
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0x32]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x34]
	ldr r1, =sub_8112FB8
	str r1, [r0, 0x1C]
	ldr r2, =gSprites
	movs r3, 0x38
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x8
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_8112F60

	thumb_func_start sub_8112FB8
sub_8112FB8: @ 8112FB8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x34]
	movs r1, 0x34
	ldrsh r3, [r5, r1]
	cmp r3, 0
	beq _08113020
	subs r0, 0x1
	strh r0, [r5, 0x34]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl Sin
	ldr r4, =gSprites
	movs r1, 0x38
	ldrsh r2, [r5, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl Cos
	movs r1, 0x38
	ldrsh r2, [r5, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x26]
	ldrh r0, [r5, 0x32]
	ldrh r2, [r5, 0x2E]
	adds r1, r0, r2
	strh r1, [r5, 0x2E]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _08113054
	ldr r2, =0xffffff00
	adds r0, r1, r2
	strh r0, [r5, 0x2E]
	b _08113054
	.pool
_08113020:
	ldr r2, =gSprites
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x24]
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x26]
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x8
	strh r1, [r0, 0x22]
	ldr r0, =move_anim_8074EE0
	str r0, [r5, 0x1C]
_08113054:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8112FB8

	thumb_func_start sub_8113064
sub_8113064: @ 8113064
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081130B4
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r5, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r5, 0x20]
	ldrh r0, [r2, 0x6]
	negs r0, r0
	strh r0, [r2, 0x6]
	ldrh r0, [r2, 0x8]
	negs r0, r0
	strh r0, [r2, 0x8]
	adds r1, r2, 0
	b _081130BE
	.pool
_081130B4:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	strh r0, [r5, 0x20]
_081130BE:
	ldrh r0, [r1, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x34]
	ldrh r0, [r1, 0xA]
	strh r0, [r5, 0x38]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A66DC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113064

	thumb_func_start sub_8113100
sub_8113100: @ 8113100
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_80A6838
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08113164
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r5, 0x20]
	ldrh r1, [r2, 0x2]
	subs r0, r1
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	adds r1, r0
	strh r1, [r5, 0x22]
	ldrh r0, [r5, 0x32]
	ldrh r1, [r2, 0x4]
	subs r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
	b _0811318E
	.pool
_08113164:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	strh r0, [r5, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	ldrh r0, [r1, 0x4]
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
	ldrh r0, [r1, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0811318E:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113100

	thumb_func_start sub_81131B4
sub_81131B4: @ 81131B4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081131D0
	ldr r4, =gAnimationBankAttacker
	b _081131D2
	.pool
_081131D0:
	ldr r4, =gAnimationBankTarget
_081131D2:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r4, =gBattleAnimArgs
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_80A6864
	ldrh r0, [r4, 0x4]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldr r0, =sub_80A67D8
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81131B4

	thumb_func_start sub_8113224
sub_8113224: @ 8113224
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0811323E
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0811323E:
	adds r0, r4, 0
	bl sub_8113100
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113224

	thumb_func_start sub_8113250
sub_8113250: @ 8113250
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r6, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	strh r5, [r6, 0x36]
	movs r0, 0x1
	strh r0, [r6, 0x38]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r6, 0x3A]
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A861C
	lsls r7, r0, 16
	lsrs r5, r7, 16
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A861C
	lsls r1, r0, 16
	lsrs r0, r1, 16
	cmp r5, r0
	bls _081132B0
	lsrs r0, r7, 17
	b _081132B2
	.pool
_081132B0:
	lsrs r0, r1, 17
_081132B2:
	strh r0, [r6, 0x3C]
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	movs r2, 0x3C
	ldrsh r1, [r6, r2]
	bl Cos
	strh r0, [r6, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	movs r2, 0x3C
	ldrsh r1, [r6, r2]
	bl Sin
	strh r0, [r6, 0x26]
	ldr r0, =sub_81132E0
	str r0, [r6, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113250

	thumb_func_start sub_81132E0
sub_81132E0: @ 81132E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _081132F2
	cmp r5, 0x1
	beq _0811335E
	b _081133E2
_081132F2:
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x38]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3A]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _08113344
	strh r5, [r4, 0x36]
	ldrh r1, [r4, 0x38]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _08113344
	adds r0, r1, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _08113344
	movs r0, 0x10
	strh r0, [r4, 0x38]
_08113344:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081133E2
	movs r0, 0
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081133E2
_0811335E:
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x38]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x95
	bgt _08113386
	adds r0, r1, 0
	adds r0, 0x8
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x95
	ble _08113386
	movs r0, 0x96
	strh r0, [r4, 0x3C]
_08113386:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _081133CE
	movs r0, 0
	strh r0, [r4, 0x36]
	ldrh r1, [r4, 0x38]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _081133CE
	adds r0, r1, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _081133CE
	movs r0, 0x10
	strh r0, [r4, 0x38]
_081133CE:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _081133E2
	adds r0, r4, 0
	bl move_anim_8072740
_081133E2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81132E0

	thumb_func_start sub_81133E8
sub_81133E8: @ 81133E8
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08113424
	ldr r0, =0x04000014
	str r0, [sp]
	ldr r0, =gUnknown_02022E18
	b _0811342A
	.pool
_08113424:
	ldr r0, =0x04000018
	str r0, [sp]
	ldr r0, =gUnknown_02022E1C
_0811342A:
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r5, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r5, [r0, 0x9]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r4, 0xE]
	adds r0, 0x20
	strh r0, [r4, 0x10]
	cmp r1, 0
	bge _0811345A
	strh r5, [r4, 0xE]
_0811345A:
	ldrh r3, [r4, 0xE]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bgt _08113488
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0811346C:
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0xC]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	ble _0811346C
_08113488:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_81134B8
	str r0, [r4]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81133E8

	thumb_func_start sub_81134B8
sub_81134B8: @ 81134B8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r2, r0, r1
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0x4
	bhi _0811356E
	lsls r0, 2
	ldr r1, =_081134E4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081134E4:
	.4byte _081134F8
	.4byte _0811351A
	.4byte _0811352A
	.4byte _08113556
	.4byte _08113568
_081134F8:
	ldrh r0, [r2, 0x16]
	adds r0, 0x1
	strh r0, [r2, 0x16]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811354E
	movs r0, 0
	strh r0, [r2, 0x16]
	ldrh r0, [r2, 0x14]
	adds r0, 0x1
	strh r0, [r2, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0811354E
	b _08113548
_0811351A:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _0811354E
	b _08113548
_0811352A:
	ldrh r0, [r2, 0x16]
	adds r0, 0x1
	strh r0, [r2, 0x16]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811354E
	movs r0, 0
	strh r0, [r2, 0x16]
	ldrh r0, [r2, 0x14]
	subs r0, 0x1
	strh r0, [r2, 0x14]
	lsls r0, 16
	cmp r0, 0
	bne _0811354E
_08113548:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_0811354E:
	adds r0, r2, 0
	bl sub_8113574
	b _0811356E
_08113556:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _0811356E
	.pool
_08113568:
	adds r0, r3, 0
	bl move_anim_task_del
_0811356E:
	pop {r0}
	bx r0
	thumb_func_end sub_81134B8

	thumb_func_start sub_8113574
sub_8113574: @ 8113574
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldrh r3, [r5, 0x12]
	ldrh r4, [r5, 0xE]
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r4, r0
	bgt _081135CA
	ldr r7, =gUnknown_02038C28
	mov r12, r7
	ldr r0, =gSineTable
	mov r8, r0
	ldr r6, =gUnknown_02039B28
_08113592:
	lsls r2, r4, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r12
	lsls r0, r3, 1
	add r0, r8
	movs r7, 0
	ldrsh r1, [r0, r7]
	movs r7, 0x14
	ldrsh r0, [r5, r7]
	muls r0, r1
	asrs r0, 7
	ldrh r1, [r5, 0xC]
	adds r0, r1
	strh r0, [r2]
	adds r3, 0x8
	movs r0, 0xFF
	ands r3, r0
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r7, 0x10
	ldrsh r0, [r5, r7]
	cmp r4, r0
	ble _08113592
_081135CA:
	ldrh r0, [r5, 0x12]
	adds r0, 0x9
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x12]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113574

	thumb_func_start sub_81135EC
sub_81135EC: @ 81135EC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r0, r1, 1
	adds r0, r1
	movs r1, 0x5
	bl __divsi3
	adds r6, r0, 0
	ldr r1, =gAnimationBankAttacker
	mov r8, r1
	ldrb r0, [r1]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	mov r2, r8
	ldrb r0, [r2]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r3, [r5, 0x8]
	adds r0, r3
	strh r0, [r4, 0x22]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl Cos
	strh r0, [r4, 0x30]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	lsls r6, 16
	asrs r6, 16
	adds r1, r6, 0
	bl Sin
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	ldrh r2, [r5]
	adds r3, r2, 0
	muls r3, r1
	adds r1, r3, 0
	ldrh r3, [r4, 0x20]
	adds r1, r3
	strh r1, [r4, 0x20]
	adds r1, r2, 0
	muls r1, r0
	adds r0, r1, 0
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x34]
	ldr r0, =sub_811369C
	str r0, [r4, 0x1C]
	adds r4, 0x2E
	ldr r2, =gUnknown_0203A100
	movs r1, 0x6
_08113674:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08113674
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81135EC

	thumb_func_start sub_811369C
sub_811369C: @ 811369C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x38]
	adds r0, r2
	strh r0, [r4, 0x38]
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	movs r1, 0xA
	bl __divsi3
	strh r0, [r4, 0x24]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r1, 0xA
	bl __divsi3
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _081136E0
	adds r0, r4, 0
	bl move_anim_8072740
_081136E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811369C

	thumb_func_start sub_81136E8
sub_81136E8: @ 81136E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =gBattleAnimArgs
	ldrh r1, [r1]
	strh r1, [r0, 0x8]
	ldr r1, =gAnimationBankAttacker
	ldrb r4, [r1]
	movs r1, 0x10
	strh r1, [r0, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	adds r0, r4, 0
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08113734
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _0811373C
	.pool
_08113734:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_0811373C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_811375C
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81136E8

	thumb_func_start sub_811375C
sub_811375C: @ 811375C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0xA]
	lsrs r4, r0, 8
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldrb r2, [r6, 0x8]
	cmp r0, r2
	bne _081137D8
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 8
	orrs r1, r0
	movs r5, 0
	strh r1, [r6, 0xA]
	ldrh r1, [r6, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	strh r5, [r6, 0xC]
	cmp r4, 0x10
	bne _081137DE
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	bl move_anim_task_del
	b _081137DE
	.pool
_081137D8:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
_081137DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811375C

	thumb_func_start sub_81137E4
sub_81137E4: @ 81137E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r2, 0x8]
	movs r1, 0x80
	lsls r1, 5
	strh r1, [r2, 0xA]
	ldr r0, =sub_811381C
	str r0, [r2]
	movs r0, 0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81137E4

	thumb_func_start sub_811381C
sub_811381C: @ 811381C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0xA]
	lsrs r4, r0, 8
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldrb r2, [r6, 0x8]
	cmp r0, r2
	bne _0811387C
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 8
	orrs r1, r0
	movs r5, 0
	strh r1, [r6, 0xA]
	ldrh r1, [r6, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	strh r5, [r6, 0xC]
	cmp r4, 0
	bne _08113882
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r7, 0
	bl move_anim_task_del
	b _08113882
	.pool
_0811387C:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
_08113882:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811381C

	thumb_func_start sub_8113888
sub_8113888: @ 8113888
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081138BC
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _081138C4
	.pool
_081138BC:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_081138C4:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113888

	thumb_func_start sub_81138D4
sub_81138D4: @ 81138D4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x30]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	movs r0, 0x7E
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl sub_80A6E14
	ldrh r0, [r4, 0x30]
	negs r0, r0
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x32]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x3A]
	ldr r1, =sub_8113950
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81138D4

	thumb_func_start sub_8113950
sub_8113950: @ 8113950
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r5, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	adds r2, r5, r0
	strh r2, [r4, 0x34]
	ldrh r3, [r4, 0x32]
	ldrh r6, [r4, 0x36]
	adds r1, r3, r6
	strh r1, [r4, 0x36]
	lsls r0, r2, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r4, 0x26]
	movs r6, 0x3C
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bne _08113992
	adds r0, r2, r5
	strh r0, [r4, 0x34]
	adds r1, r3
	strh r1, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
_08113992:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r6, [r4, 0x26]
	adds r0, r6
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	cmp r0, 0x7F
	ble _081139C2
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x14
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
_081139C2:
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _081139D4
	adds r0, r4, 0
	bl move_anim_8072740
_081139D4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8113950

	thumb_func_start sub_81139DC
sub_81139DC: @ 81139DC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrb r1, [r5, 0x4]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x32]
	ldr r0, =sub_8113A18
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81139DC

	thumb_func_start sub_8113A18
sub_8113A18: @ 8113A18
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x36]
	adds r0, r1
	strh r0, [r2, 0x36]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x38]
	adds r1, r3
	strh r1, [r2, 0x38]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bne _08113A4E
	ldr r0, =sub_8113A58
	str r0, [r2, 0x1C]
_08113A4E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113A18

	thumb_func_start sub_8113A58
sub_8113A58: @ 8113A58
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x36]
	ldrh r0, [r3, 0x2E]
	subs r1, r0
	strh r1, [r3, 0x36]
	ldrh r0, [r3, 0x38]
	ldrh r2, [r3, 0x30]
	subs r0, r2
	strh r0, [r3, 0x38]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r3, 0x24]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r3, 0x26]
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _08113A8A
	adds r0, r3, 0
	bl move_anim_8074EE0
_08113A8A:
	pop {r0}
	bx r0
	thumb_func_end sub_8113A58

	thumb_func_start sub_8113A90
sub_8113A90: @ 8113A90
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r3, r0, 0
	cmp r1, 0
	bne _08113AAC
	ldr r0, =gAnimationBankAttacker
	b _08113AAE
	.pool
_08113AAC:
	ldr r0, =gAnimationBankTarget
_08113AAE:
	ldrb r5, [r0]
	movs r6, 0x14
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x4
	ldr r7, =0x000003ff
	adds r0, r7, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	beq _08113B0C
	cmp r0, 0x1
	bgt _08113AE8
	cmp r0, 0
	beq _08113AF2
	b _08113B60
	.pool
_08113AE8:
	cmp r0, 0x2
	beq _08113B26
	cmp r0, 0x3
	beq _08113B3E
	b _08113B60
_08113AF2:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r4, 0x22]
	b _08113B60
_08113B0C:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0xE
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x10
	strh r0, [r4, 0x22]
	b _08113B60
_08113B26:
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _08113B54
_08113B3E:
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0xE
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x10
_08113B54:
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r6, 0xEC
_08113B60:
	movs r0, 0x20
	strh r0, [r4, 0x2E]
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	adds r0, 0xC
	strh r0, [r4, 0x36]
	ldr r0, =0x0000fff4
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_8113B90
	str r0, [r4, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113A90

	thumb_func_start sub_8113B90
sub_8113B90: @ 8113B90
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08113BA4
	adds r0, r4, 0
	bl move_anim_8074EE0
_08113BA4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8113B90

	thumb_func_start sub_8113BAC
sub_8113BAC: @ 8113BAC
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1F
	movs r6, 0
	strh r0, [r5, 0x16]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	subs r0, 0x7
	strh r0, [r5, 0x14]
	ldrh r1, [r5, 0x16]
	strh r1, [r5, 0x12]
	strh r0, [r5, 0x10]
	subs r1, r0
	lsls r1, 8
	strh r1, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r5, 0x24]
	adds r0, 0x20
	strh r0, [r5, 0x26]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08113C1C
	ldr r0, =0x0000fff4
	b _08113C1E
	.pool
_08113C1C:
	ldr r0, =0x0000ffc0
_08113C1E:
	strh r0, [r5, 0x18]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	cmp r0, 0x1
	bne _08113C80
	add r4, sp, 0xC
	adds r0, r4, 0
	bl sub_80A6B30
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldrb r1, [r4, 0x8]
	lsls r1, 4
	movs r0, 0
	movs r2, 0x20
	bl FillPalette
	ldr r0, =0x04000016
	str r0, [sp]
	movs r7, 0x2
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08113CB0
	ldr r1, =gUnknown_02022E1C
	b _08113CAA
	.pool
_08113C80:
	ldr r0, =gUnknown_02022E1E
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0
	movs r1, 0x90
	movs r2, 0x20
	bl FillPalette
	ldr r0, =0x0400001a
	str r0, [sp]
	movs r7, 0x4
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08113CB0
	ldr r1, =gUnknown_02022E18
_08113CAA:
	ldrh r0, [r1]
	adds r0, 0xF0
	strh r0, [r1]
_08113CB0:
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r2, sp
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	mov r0, sp
	strb r1, [r0, 0x9]
	strh r1, [r5, 0x1E]
	movs r0, 0x10
	strh r0, [r5, 0x20]
	strh r1, [r5, 0x8]
	strh r1, [r5, 0xA]
	strh r1, [r5, 0xC]
	movs r0, 0x3
	bl sub_8114374
	movs r3, 0
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r4, r0
_08113CDC:
	lsls r1, r3, 1
	adds r2, r1, r4
	ldrh r0, [r5, 0x1C]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r5, 0x1C]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x6F
	bls _08113CDC
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	movs r0, 0x3F
	eors r7, r0
	movs r1, 0xFC
	lsls r1, 6
	adds r0, r1, 0
	orrs r7, r0
	movs r0, 0x4A
	adds r1, r7, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r2, =gUnknown_02022E24
	ldrh r0, [r5, 0x24]
	lsls r0, 8
	ldrh r1, [r5, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =gUnknown_02022E26
	movs r0, 0xA0
	strh r0, [r1]
	ldr r0, =sub_8113D60
	str r0, [r5]
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113BAC

	thumb_func_start sub_8113D60
sub_8113D60: @ 8113D60
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _08113D7A
	b _08113E72
_08113D7A:
	lsls r0, 2
	ldr r1, =_08113D8C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08113D8C:
	.4byte _08113DA0
	.4byte _08113E02
	.4byte _08113E1C
	.4byte _08113E58
	.4byte _08113E6C
_08113DA0:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08113E72
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08113DD0
	ldrh r1, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	cmp r0, 0xC
	beq _08113DDE
	adds r0, r1, 0x1
	strh r0, [r4, 0x1E]
	b _08113DDE
_08113DD0:
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	beq _08113DDE
	subs r0, r1, 0x1
	strh r0, [r4, 0x20]
_08113DDE:
	ldrh r1, [r4, 0x20]
	lsls r1, 8
	ldrh r0, [r4, 0x1E]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _08113E72
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _08113E72
	b _08113E5E
_08113E02:
	ldrh r0, [r4, 0x10]
	subs r0, 0x8
	strh r0, [r4, 0x10]
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _08113E72
	b _08113E5E
_08113E1C:
	ldrh r0, [r4, 0x10]
	subs r0, 0x8
	strh r0, [r4, 0x10]
	adds r0, r4, 0
	bl sub_8114244
	ldrh r1, [r4, 0x24]
	adds r1, 0x4
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r2, r0, 0x4
	strh r2, [r4, 0x26]
	lsls r1, 16
	lsls r0, r2, 16
	cmp r1, r0
	blt _08113E3E
	strh r2, [r4, 0x24]
_08113E3E:
	ldr r3, =gUnknown_02022E24
	ldrh r2, [r4, 0x24]
	lsls r0, r2, 8
	ldrh r1, [r4, 0x26]
	orrs r0, r1
	strh r0, [r3]
	lsls r2, 16
	lsls r1, 16
	cmp r2, r1
	bne _08113E72
	b _08113E5E
	.pool
_08113E58:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08113E5E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08113E72
	.pool
_08113E6C:
	adds r0, r2, 0
	bl move_anim_task_del
_08113E72:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8113D60

	thumb_func_start sub_8113E78
sub_8113E78: @ 8113E78
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bls _08113E94
	b _081140A6
_08113E94:
	lsls r0, 2
	ldr r1, =_08113EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08113EA8:
	.4byte _08113EBC
	.4byte _08113F40
	.4byte _08113F84
	.4byte _08113FF0
	.4byte _08114058
_08113EBC:
	bl IsContest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08113EF8
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl move_anim_task_del
	b _081140A6
	.pool
_08113EF8:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	cmp r0, 0x1
	bne _08113F24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =gUnknown_02022E1C
	b _08113F2E
	.pool
_08113F24:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =gUnknown_02022E18
_08113F2E:
	ldrh r0, [r1]
	adds r0, 0xF0
	strh r0, [r1]
	b _08114044
	.pool
_08113F40:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08113F68
	mov r0, sp
	bl sub_80A6B30
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	mov r0, sp
	ldrb r1, [r0, 0x8]
	lsls r1, 4
	movs r0, 0
	movs r2, 0x20
	bl FillPalette
	b _08113F78
	.pool
_08113F68:
	ldr r0, =gUnknown_02022E1E
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	movs r0, 0
	movs r1, 0x90
	movs r2, 0x20
	bl FillPalette
_08113F78:
	movs r0, 0x3
	bl sub_8114374
	b _08114044
	.pool
_08113F84:
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1F
	movs r6, 0
	strh r0, [r5, 0x16]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	subs r0, 0x7
	strh r0, [r5, 0x14]
	ldrh r1, [r5, 0x16]
	subs r1, r0
	lsls r1, 8
	strh r1, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r1, r0, 0x4
	strh r1, [r5, 0x24]
	adds r0, 0x4
	strh r0, [r5, 0x26]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08113FD8
	ldr r0, =0x0000fff4
	b _08113FDA
	.pool
_08113FD8:
	ldr r0, =0x0000ffc0
_08113FDA:
	strh r0, [r5, 0x18]
	ldrh r0, [r5, 0x18]
	strh r0, [r5, 0x10]
	strh r0, [r5, 0x12]
	movs r0, 0xC
	strh r0, [r5, 0x1E]
	movs r0, 0x8
	strh r0, [r5, 0x20]
	b _08114044
	.pool
_08113FF0:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08114000
	ldr r0, =0x04000016
	b _08114002
	.pool
_08114000:
	ldr r0, =0x0400001a
_08114002:
	str r0, [sp, 0x10]
	movs r3, 0
	add r4, sp, 0x10
	ldr r6, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r7, r6, r0
_08114010:
	lsls r1, r3, 1
	adds r2, r1, r6
	ldrh r0, [r5, 0x1C]
	adds r0, 0x9F
	subs r0, r3
	strh r0, [r2]
	adds r1, r7
	ldrh r0, [r5, 0x1C]
	adds r0, 0x9F
	subs r0, r3
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x6F
	bls _08114010
	ldr r1, =0xa2600001
	str r1, [r4, 0x4]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r4, 0x8]
	strb r2, [r4, 0x9]
	ldr r0, [sp, 0x10]
	ldr r2, [r4, 0x8]
	bl sub_80BA038
_08114044:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _081140A6
	.pool
_08114058:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08114070
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	b _08114078
	.pool
_08114070:
	ldr r1, =0x00003f3b
	movs r0, 0x4A
	bl SetGpuReg
_08114078:
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r2, =gUnknown_02022E24
	ldrh r0, [r5, 0x24]
	lsls r0, 8
	ldrh r1, [r5, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =gUnknown_02022E26
	movs r0, 0xA0
	strh r0, [r1]
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0xA]
	strh r0, [r5, 0xC]
	ldr r1, =0x0000080c
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_81140C8
	str r0, [r5]
_081140A6:
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113E78

	thumb_func_start sub_81140C8
sub_81140C8: @ 81140C8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _081140E2
	b _08114232
_081140E2:
	lsls r0, 2
	ldr r1, =_081140F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081140F4:
	.4byte _08114108
	.4byte _08114134
	.4byte _0811419C
	.4byte _081141FE
	.4byte _08114210
_08114108:
	ldrh r0, [r4, 0x12]
	adds r0, 0x8
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0x16]
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	cmp r0, r1
	blt _0811411E
	strh r2, [r4, 0x12]
_0811411E:
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _08114132
	b _08114232
_08114132:
	b _08114204
_08114134:
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	subs r0, r1
	cmp r0, 0x3F
	bgt _08114150
	ldrh r0, [r4, 0x24]
	subs r0, 0x4
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	adds r0, 0x4
	strh r0, [r4, 0x26]
	b _08114154
_08114150:
	movs r0, 0x1
	strh r0, [r4, 0xA]
_08114154:
	ldr r2, =gUnknown_02022E24
	ldrh r0, [r4, 0x24]
	lsls r0, 8
	ldrh r1, [r4, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x10]
	adds r0, 0x8
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0x14]
	movs r3, 0x14
	ldrsh r1, [r4, r3]
	cmp r0, r1
	blt _08114176
	strh r2, [r4, 0x10]
_08114176:
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08114232
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08114232
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08114204
	.pool
_0811419C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08114232
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081141CC
	ldrh r1, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081141DA
	subs r0, r1, 0x1
	strh r0, [r4, 0x1E]
	b _081141DA
_081141CC:
	ldrh r1, [r4, 0x20]
	movs r3, 0x20
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _081141DA
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
_081141DA:
	ldrh r1, [r4, 0x20]
	lsls r1, 8
	ldrh r0, [r4, 0x1E]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08114232
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bne _08114232
	b _08114204
_081141FE:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08114204:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114232
	.pool
_08114210:
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl move_anim_task_del
_08114232:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81140C8

	thumb_func_start sub_8114244
sub_8114244: @ 8114244
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldrh r0, [r6, 0x12]
	ldrh r4, [r6, 0x10]
	subs r0, r4
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	beq _08114338
	movs r2, 0x22
	ldrsh r0, [r6, r2]
	bl __divsi3
	mov r8, r0
	movs r3, 0x14
	ldrsh r0, [r6, r3]
	lsls r5, r0, 8
	lsls r0, r4, 16
	movs r4, 0
	cmp r0, 0
	ble _081142A4
	ldr r0, =gUnknown_02038C28
	mov r12, r0
	ldr r7, =gUnknown_02039B28
_08114278:
	lsls r2, r4, 16
	asrs r2, 16
	lsls r3, r2, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r3, r0
	add r3, r12
	adds r1, r2, 0
	subs r1, 0x9F
	ldrh r0, [r6, 0x1C]
	subs r0, r1
	strh r0, [r3]
	adds r2, 0x1
	lsls r2, 16
	lsrs r4, r2, 16
	asrs r2, 16
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	cmp r2, r0
	blt _08114278
_081142A4:
	ldrh r4, [r6, 0x10]
	lsls r3, r4, 16
	asrs r1, r3, 16
	movs r2, 0x12
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bgt _081142EE
	ldr r0, =gUnknown_02038C28
	mov r12, r0
	ldr r7, =gUnknown_02039B28
_081142B8:
	asrs r4, r3, 16
	cmp r4, 0
	blt _081142DA
	asrs r1, r5, 8
	subs r1, r4
	lsls r3, r4, 1
	ldrb r2, [r7, 0x14]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 7
	adds r3, r0
	add r3, r12
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r6, 0x1C]
	adds r1, r2
	strh r1, [r3]
_081142DA:
	add r5, r8
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r3, r4, 16
	asrs r1, r3, 16
	movs r2, 0x12
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _081142B8
_081142EE:
	movs r3, 0x1C
	ldrsh r0, [r6, r3]
	adds r0, 0x9F
	lsls r2, r4, 16
	asrs r1, r2, 16
	subs r5, r0, r1
	movs r3, 0x16
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bge _08114366
	ldr r7, =gUnknown_02038C28
	ldr r4, =gUnknown_02039B28
_08114306:
	asrs r3, r2, 16
	cmp r3, 0
	blt _0811431E
	lsls r2, r3, 1
	ldrb r1, [r4, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	strh r5, [r2]
	subs r5, 0x1
_0811431E:
	adds r0, r3, 0x1
	lsls r2, r0, 16
	asrs r1, r2, 16
	movs r3, 0x16
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08114306
	b _08114366
	.pool
_08114338:
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	adds r5, r0, 0
	adds r5, 0x9F
	movs r4, 0
	ldr r3, =gUnknown_02038C28
	movs r2, 0xF0
	lsls r2, 3
	adds r6, r3, r2
_0811434A:
	lsls r0, r4, 16
	asrs r0, 16
	lsls r2, r0, 1
	adds r1, r2, r3
	strh r5, [r1]
	adds r2, r6
	strh r5, [r2]
	subs r5, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	ble _0811434A
_08114366:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114244

	thumb_func_start sub_8114374
sub_8114374: @ 8114374
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	ldr r7, =gSprites
	movs r1, 0x3
	ands r0, r1
	lsls r5, r0, 2
	movs r0, 0xD
	negs r0, r0
	adds r6, r0, 0
_0811438A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081143AA
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r0, [r1, 0x5]
	ands r0, r6
	orrs r0, r5
	strb r0, [r1, 0x5]
_081143AA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _0811438A
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114374

	thumb_func_start sub_81143C0
sub_81143C0: @ 81143C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	ldrb r0, [r6]
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80A438C
	ldr r0, =gSprites
	mov r9, r0
	ldr r0, =gBankSpriteIds
	mov r8, r0
	ldrb r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r9
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r7, 0x5
	negs r7, r7
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r6]
	movs r5, 0x2
	eors r0, r5
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0811444E
	ldrb r0, [r6]
	eors r0, r5
	movs r1, 0x1
	eors r4, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80A438C
	ldrb r0, [r6]
	eors r0, r5
	add r0, r8
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r7, 0
	ands r1, r2
	strb r1, [r0]
_0811444E:
	mov r0, r10
	bl move_anim_task_del
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81143C0

	thumb_func_start sub_8114470
sub_8114470: @ 8114470
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r5, r1, 31
	adds r0, r5, 0
	bl sub_80A477C
	ldrb r1, [r4]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _081144AC
	movs r0, 0x1
	eors r5, r0
	adds r0, r5, 0
	bl sub_80A477C
_081144AC:
	adds r0, r6, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114470

	thumb_func_start sub_81144BC
sub_81144BC: @ 81144BC
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrb r1, [r1, 0x4]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81144BC

	thumb_func_start sub_81144F8
sub_81144F8: @ 81144F8
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	ldr r0, =gUnknown_02022E24
	strh r6, [r0]
	ldr r0, =gUnknown_02022E26
	strh r6, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000c08
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0811455C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0811455C:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _081145D6
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081145D6
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0811458C
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	bne _081145D6
_0811458C:
	ldrb r0, [r4]
	movs r5, 0x2
	eors r0, r5
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081145D6
	ldr r3, =gSprites
	ldr r1, =gBankSpriteIds
	ldrb r0, [r4]
	eors r0, r5
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r6, 0x1
_081145D6:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08114614
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r5, [r0]
	b _0811465C
	.pool
_08114614:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08114640
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08114650
	.pool
_08114640:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08114650:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
_0811465C:
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C1D210
	bl sub_80A6D48
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C1D0AC
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C1D1E8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r2, =gUnknown_02022E18
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	negs r0, r0
	adds r0, 0x60
	strh r0, [r2]
	ldr r2, =gUnknown_02022E1A
	ldrh r0, [r1, 0x22]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	adds r1, r0, 0
	ldr r2, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _08114708
	adds r0, r1, 0
	movs r1, 0
	bl sub_80A750C
	b _08114714
	.pool
_08114708:
	lsls r0, r1, 4
	ldrh r3, [r2, 0x4]
	movs r1, 0x10
	movs r2, 0xB
	bl BlendPalette
_08114714:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0xA]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0xC]
	ldrh r1, [r2, 0x4]
	strh r1, [r0, 0xE]
	strh r6, [r0, 0x14]
	ldr r1, =sub_8114748
	str r1, [r0]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81144F8

	thumb_func_start sub_8114748
sub_8114748: @ 8114748
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r0, 0x4
	movs r5, 0
	strh r0, [r4, 0x1C]
	ldr r2, =gUnknown_02022E18
	ldrh r3, [r2]
	subs r1, r3, 0x4
	strh r1, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x80
	beq _08114776
	b _08114886
_08114776:
	strh r5, [r4, 0x1C]
	adds r0, r3, 0
	adds r0, 0x7C
	strh r0, [r2]
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08114824
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	adds r1, r0, 0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081147B8
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_80A750C
_081147B8:
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08114886
	ldr r2, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r5
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	b _08114886
	.pool
_08114824:
	cmp r0, 0x3
	bne _08114886
	ldr r0, =gUnknown_02022E24
	strh r5, [r0]
	ldr r0, =gUnknown_02022E26
	strh r5, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08114856
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_08114856:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl move_anim_task_del
_08114886:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114748

	thumb_func_start sub_811489C
sub_811489C: @ 811489C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0x7
	bhi _08114900
	lsls r0, r1, 2
	ldr r1, =_081148C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081148C4:
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148F0
	.4byte _081148F4
	.4byte _081148F8
	.4byte _081148FC
_081148E4:
	ldrb r0, [r2]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	b _08114902
_081148F0:
	movs r4, 0
	b _08114908
_081148F4:
	movs r4, 0x2
	b _08114908
_081148F8:
	movs r4, 0x1
	b _08114908
_081148FC:
	movs r4, 0x3
	b _08114908
_08114900:
	movs r2, 0xFF
_08114902:
	movs r0, 0
	cmp r0, 0
	beq _0811492E
_08114908:
	adds r0, r4, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0811492C
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r2, [r0]
	b _0811492E
	.pool
_0811492C:
	movs r2, 0xFF
_0811492E:
	cmp r2, 0xFF
	beq _0811494A
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	ldr r1, =gBattleAnimArgs
	ldrb r1, [r1, 0x2]
	bl sub_80A750C
_0811494A:
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811489C

	thumb_func_start sub_8114960
sub_8114960: @ 8114960
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gUnknown_02038432
	ldrb r0, [r2]
	cmp r0, 0x1
	bhi _08114974
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	strh r0, [r1, 0xE]
_08114974:
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08114980
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
_08114980:
	adds r0, r3, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114960

	thumb_func_start sub_8114994
sub_8114994: @ 8114994
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_81149FC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114994

	thumb_func_start sub_81149FC
sub_81149FC: @ 81149FC
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08114A50
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	movs r0, 0x14
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =sub_8114A60
	str r0, [r5, 0x1C]
_08114A50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81149FC

	thumb_func_start sub_8114A60
sub_8114A60: @ 8114A60
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08114A74
	adds r0, r4, 0
	bl move_anim_8072740
_08114A74:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8114A60

	thumb_func_start sub_8114A7C
sub_8114A7C: @ 8114A7C
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08114A9C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_08114A9C:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114A7C

	thumb_func_start sub_8114AF0
sub_8114AF0: @ 8114AF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A60AC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A60AC
	lsls r0, 24
	lsrs r7, r0, 24
	bl Random2
	movs r4, 0x1F
	adds r5, r4, 0
	ands r5, r0
	bl Random2
	ands r4, r0
	adds r1, r5, 0
	cmp r1, 0x10
	ble _08114B38
	movs r0, 0x10
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
_08114B38:
	lsls r0, r4, 16
	asrs r1, r0, 16
	cmp r1, 0x10
	ble _08114B48
	movs r0, 0x10
	subs r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
_08114B48:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r6, 0x2E]
	mov r1, r8
	adds r0, r1, r5
	strh r0, [r6, 0x32]
	adds r0, r7, r4
	strh r0, [r6, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114AF0

	thumb_func_start sub_8114B80
sub_8114B80: @ 8114B80
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x1
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08114BF4
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r6, 0x2]
	adds r0, r2
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r3, [r6, 0x4]
	adds r0, r3
	strh r0, [r5, 0x22]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	ble _08114BDA
	movs r1, 0x1
_08114BDA:
	strh r1, [r5, 0x2E]
	ldr r0, =sub_8114C10
	b _08114C02
	.pool
_08114BF4:
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x20]
	ldrh r0, [r6, 0x4]
	strh r0, [r5, 0x22]
	negs r0, r0
	strh r0, [r5, 0x26]
	ldr r0, =sub_8114C4C
_08114C02:
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114B80

	thumb_func_start sub_8114C10
sub_8114C10: @ 8114C10
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08114C2E
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
_08114C2E:
	ldrh r0, [r2, 0x22]
	subs r0, 0x4
	strh r0, [r2, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	negs r1, r1
	cmp r0, r1
	bge _08114C46
	adds r0, r2, 0
	bl move_anim_8072740
_08114C46:
	pop {r0}
	bx r0
	thumb_func_end sub_8114C10

	thumb_func_start sub_8114C4C
sub_8114C4C: @ 8114C4C
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _08114C5E
	cmp r1, 0x1
	beq _08114C74
	b _08114CB6
_08114C5E:
	ldrh r0, [r3, 0x26]
	adds r0, 0x4
	strh r0, [r3, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _08114CB6
	strh r1, [r3, 0x26]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _08114CB6
_08114C74:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	cmp r0, 0
	ble _08114CB6
	movs r0, 0
	strh r0, [r3, 0x30]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r2, [r1]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08114CB6
	adds r0, r3, 0
	bl move_anim_8072740
_08114CB6:
	pop {r0}
	bx r0
	thumb_func_end sub_8114C4C

	thumb_func_start sub_8114CBC
sub_8114CBC: @ 8114CBC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r1, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _08114CE8
	ldr r0, =sub_8114CFC
	b _08114CEA
	.pool
_08114CE8:
	ldr r0, =sub_8114EB4
_08114CEA:
	str r0, [r1]
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114CBC

	thumb_func_start sub_8114CFC
sub_8114CFC: @ 8114CFC
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _08114D16
	b _08114EAA
_08114D16:
	lsls r0, 2
	ldr r1, =_08114D28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08114D28:
	.4byte _08114D3C
	.4byte _08114DC4
	.4byte _08114DD4
	.4byte _08114E78
	.4byte _08114E8C
_08114D3C:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _08114D70
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gUnknown_02022E1A
	b _08114D78
	.pool
_08114D70:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gUnknown_02022E1E
_08114D78:
	ldrh r0, [r0]
	strh r0, [r4, 0x22]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r4, 0x24]
	adds r0, 0x20
	strh r0, [r4, 0x26]
	cmp r1, 0
	bge _08114D9A
	movs r0, 0
	strh r0, [r4, 0x24]
_08114D9A:
	ldr r2, =gSprites
	movs r3, 0x1C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08114E7E
	.pool
_08114DC4:
	ldrb r0, [r4, 0x1E]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	movs r3, 0x26
	ldrsh r2, [r4, r3]
	bl sub_81150E0
	b _08114E7E
_08114DD4:
	ldrh r0, [r4, 0xC]
	adds r0, 0x6
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08114DF6
	movs r0, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
_08114DF6:
	ldr r1, =gSineTable
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	ldrh r3, [r4, 0xE]
	adds r2, r0, r3
	strh r2, [r4, 0x12]
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08114E20
	ldr r1, =gUnknown_02022E1A
	b _08114E22
	.pool
_08114E20:
	ldr r1, =gUnknown_02022E1E
_08114E22:
	ldrh r0, [r4, 0x22]
	subs r0, r2
	strh r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _08114EAA
	ldrh r0, [r4, 0x24]
	movs r1, 0x78
	subs r2, r1, r0
	strh r2, [r4, 0x12]
	movs r3, 0x1E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _08114E4C
	ldr r1, =gUnknown_02022E1A
	b _08114E4E
	.pool
_08114E4C:
	ldr r1, =gUnknown_02022E1E
_08114E4E:
	ldrh r0, [r4, 0x22]
	subs r0, r2
	strh r0, [r1]
	ldr r2, =gSprites
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x20]
	movs r3, 0x88
	lsls r3, 1
	adds r0, r3, 0
	subs r0, r2
	strh r0, [r1, 0x24]
	b _08114E7E
	.pool
_08114E78:
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08114E7E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114EAA
	.pool
_08114E8C:
	adds r0, r2, 0
	bl move_anim_task_del
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08114EAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114CFC

	thumb_func_start sub_8114EB4
sub_8114EB4: @ 8114EB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r3]
	movs r4, 0
	strh r4, [r1, 0x24]
	strh r4, [r1, 0x26]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08114F00
	ldr r0, =gUnknown_02022E1A
	b _08114F02
	.pool
_08114F00:
	ldr r0, =gUnknown_02022E1E
_08114F02:
	strh r4, [r0]
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114EB4

	thumb_func_start sub_8114F14
sub_8114F14: @ 8114F14
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r1, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _08114F40
	ldr r0, =sub_8114F54
	b _08114F42
	.pool
_08114F40:
	ldr r0, =sub_8114FD8
_08114F42:
	str r0, [r1]
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114F14

	thumb_func_start sub_8114F54
sub_8114F54: @ 8114F54
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _08114F78
	cmp r5, 0x1
	beq _08114FCC
	b _08114FD2
	.pool
_08114F78:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r3, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x24]
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r2, [r1, 0x22]
	movs r0, 0xA0
	subs r0, r2
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114FD2
	.pool
_08114FCC:
	adds r0, r2, 0
	bl move_anim_task_del
_08114FD2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8114F54

	thumb_func_start sub_8114FD8
sub_8114FD8: @ 8114FD8
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _081150DA
	lsls r0, 2
	ldr r1, =_08115004
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08115004:
	.4byte _08115018
	.4byte _0811506C
	.4byte _0811507A
	.4byte _08115094
	.4byte _081150D4
_08115018:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _08115044
	ldr r0, =gUnknown_02022E18
	b _08115046
	.pool
_08115044:
	ldr r0, =gUnknown_02022E1C
_08115046:
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r4, 0x24]
	adds r0, 0x20
	strh r0, [r4, 0x26]
	b _081150C2
	.pool
_0811506C:
	ldrb r0, [r4, 0x1E]
	movs r1, 0x26
	ldrsh r2, [r4, r1]
	movs r1, 0
	bl sub_81150E0
	b _081150C2
_0811507A:
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x60
	strh r1, [r0, 0x26]
	b _081150C2
	.pool
_08115094:
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x8
	strh r1, [r0, 0x26]
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081150DA
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_081150C2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081150DA
	.pool
_081150D4:
	adds r0, r2, 0
	bl move_anim_task_del
_081150DA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8114FD8

	thumb_func_start sub_81150E0
sub_81150E0: @ 81150E0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	cmp r0, 0x1
	bne _08115104
	ldr r0, =gUnknown_02022E18
	ldrh r3, [r0]
	ldr r0, =0x04000014
	b _0811510A
	.pool
_08115104:
	ldr r0, =gUnknown_02022E1C
	ldrh r3, [r0]
	ldr r0, =0x04000018
_0811510A:
	str r0, [sp]
	lsls r0, r1, 16
	cmp r0, 0
	bge _08115114
	movs r1, 0
_08115114:
	lsls r2, r1, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	cmp r2, r0
	bge _08115140
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_08115126:
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r5
	strh r3, [r0]
	adds r1, r6
	strh r3, [r1]
	adds r2, 0x1
	lsls r2, 16
	lsrs r1, r2, 16
	lsls r2, r1, 16
	asrs r0, r2, 16
	cmp r0, r4
	blt _08115126
_08115140:
	lsls r1, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _0811516E
	ldr r4, =gUnknown_02038C28
	lsls r0, r3, 16
	asrs r0, 16
	adds r3, r0, 0
	adds r3, 0xF0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_08115158:
	asrs r2, r1, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r2, 0x1
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _08115158
_0811516E:
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81150E0

	thumb_func_start sub_81151A0
sub_81151A0: @ 81151A0
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r7, r0, 0
	cmp r1, 0
	bne _081151BC
	ldr r0, =gAnimationBankAttacker
	b _081151BE
	.pool
_081151BC:
	ldr r0, =gAnimationBankTarget
_081151BE:
	ldrb r4, [r0]
	movs r6, 0x18
	adds r1, r7, 0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _081151DA
	negs r0, r6
	lsls r0, 16
	lsrs r6, r0, 16
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x4]
_081151DA:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1E
	strh r0, [r5, 0x22]
	ldrh r1, [r7, 0xA]
	strh r1, [r5, 0x2E]
	ldrh r1, [r7, 0x4]
	ldrh r2, [r5, 0x20]
	adds r1, r2
	strh r1, [r5, 0x32]
	ldrh r1, [r7, 0x6]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldrh r0, [r7, 0x8]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =sub_8115228
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81151A0

	thumb_func_start sub_8115228
sub_8115228: @ 8115228
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0811523C
	adds r0, r4, 0
	bl move_anim_8072740
_0811523C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8115228

	thumb_func_start sub_8115244
sub_8115244: @ 8115244
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08115260
	ldr r0, =gAnimationBankAttacker
	b _08115262
	.pool
_08115260:
	ldr r0, =gAnimationBankTarget
_08115262:
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0000fff0
	adds r0, r2
	ldr r4, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	lsls r1, 5
	adds r0, r1
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r6, 0x22]
	ldrh r2, [r6, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, 0x4]
	ldr r1, =move_anim_8072740
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115244

	thumb_func_start sub_81152DC
sub_81152DC: @ 81152DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r0, =gBattleAnimArgs
	ldrh r2, [r0, 0x2]
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	adds r6, r0, 0
	cmp r1, 0
	beq _08115308
	adds r0, r2, 0x3
	b _08115314
	.pool
_08115308:
	ldr r0, =gMovePowerMoveAnim
	ldrh r0, [r0]
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0x3
_08115314:
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x24]
	adds r1, r6, 0
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0xE]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08115340
	cmp r0, 0x5
	bne _08115380
	ldr r0, =gUnknown_02022E20
	ldrh r0, [r0]
	strh r0, [r4, 0x22]
	ldr r0, =sub_81153AC
	b _0811539E
	.pool
_08115340:
	movs r0, 0
	strh r0, [r4, 0x22]
	movs r5, 0
_08115346:
	lsls r0, r5, 24
	lsrs r0, 24
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _08115370
	movs r3, 0x22
	ldrsh r0, [r4, r3]
	adds r0, 0x9
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r0
	ldr r0, =gBankSpriteIds
	adds r0, r5, r0
	ldrb r0, [r0]
	strh r0, [r1]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
_08115370:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _08115346
	b _0811539C
	.pool
_08115380:
	ldrb r0, [r6]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1A]
	cmp r0, 0xFF
	bne _08115398
	adds r0, r5, 0
	bl move_anim_task_del
	b _081153A0
_08115398:
	movs r0, 0x1
	strh r0, [r4, 0x22]
_0811539C:
	ldr r0, =sub_81154A4
_0811539E:
	str r0, [r4]
_081153A0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81152DC

	thumb_func_start sub_81153AC
sub_81153AC: @ 81153AC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r0, 0x8
	ldrsh r1, [r3, r0]
	cmp r1, 0x1
	beq _08115430
	cmp r1, 0x1
	bgt _081153D4
	cmp r1, 0
	beq _081153DA
	b _0811549C
	.pool
_081153D4:
	cmp r1, 0x2
	beq _08115490
	b _0811549C
_081153DA:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811549C
	strh r1, [r3, 0xA]
	ldrh r1, [r3, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08115404
	ldr r1, =gUnknown_02022E20
	ldrh r0, [r3, 0x26]
	ldrh r2, [r3, 0x22]
	adds r0, r2
	strh r0, [r1]
	b _0811540E
	.pool
_08115404:
	ldr r0, =gUnknown_02022E20
	ldrh r1, [r3, 0x22]
	ldrh r2, [r3, 0x26]
	subs r1, r2
	strh r1, [r0]
_0811540E:
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bne _0811549C
	movs r0, 0
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x24]
	subs r0, 0x1
	strh r0, [r3, 0x24]
	b _08115484
	.pool
_08115430:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811549C
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	ands r1, r0
	cmp r1, 0
	bne _0811545C
	ldr r1, =gUnknown_02022E20
	ldrh r0, [r3, 0x24]
	ldrh r2, [r3, 0x22]
	adds r0, r2
	strh r0, [r1]
	b _08115466
	.pool
_0811545C:
	ldr r0, =gUnknown_02022E20
	ldrh r1, [r3, 0x22]
	ldrh r2, [r3, 0x24]
	subs r1, r2
	strh r1, [r0]
_08115466:
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0811549C
	movs r0, 0
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x24]
	subs r0, 0x1
	strh r0, [r3, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0811549C
_08115484:
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _0811549C
	.pool
_08115490:
	ldr r1, =gUnknown_02022E20
	ldrh r0, [r3, 0x22]
	strh r0, [r1]
	adds r0, r2, 0
	bl move_anim_task_del
_0811549C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81153AC

	thumb_func_start sub_81154A4
sub_81154A4: @ 81154A4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _08115504
	cmp r5, 0x1
	bgt _081154CC
	cmp r5, 0
	beq _081154D2
	b _0811557E
	.pool
_081154CC:
	cmp r5, 0x2
	beq _08115540
	b _0811557E
_081154D2:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811557E
	strh r5, [r4, 0xA]
	adds r0, r4, 0
	bl sub_8115588
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _0811557E
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	strh r0, [r4, 0x24]
	b _08115538
_08115504:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811557E
	strh r5, [r4, 0xA]
	adds r0, r4, 0
	bl sub_8115588
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0811557E
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0811557E
_08115538:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0811557E
_08115540:
	movs r2, 0
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r2, r0
	bge _08115578
	ldr r0, =gSprites
	mov r12, r0
	adds r5, r4, 0
	adds r5, 0x8
	movs r6, 0
_08115554:
	adds r0, r2, 0
	adds r0, 0x9
	lsls r0, 1
	adds r0, r5, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r12
	strh r6, [r0, 0x24]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r2, r0
	blt _08115554
_08115578:
	adds r0, r3, 0
	bl move_anim_task_del
_0811557E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81154A4

	thumb_func_start sub_8115588
sub_8115588: @ 8115588
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0xC]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _081155B0
	movs r0, 0x24
	ldrsh r1, [r3, r0]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	ldrh r2, [r3, 0x24]
	adds r0, r4, 0
	ands r0, r2
	adds r1, r0
	lsls r1, 16
	lsrs r4, r1, 16
	b _081155C0
_081155B0:
	movs r1, 0x24
	ldrsh r0, [r3, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
_081155C0:
	movs r2, 0
	movs r7, 0x22
	ldrsh r0, [r3, r7]
	cmp r2, r0
	bge _081155F4
	ldr r6, =gSprites
	adds r5, r3, 0
	adds r5, 0x8
_081155D0:
	adds r0, r2, 0
	adds r0, 0x9
	lsls r0, 1
	adds r0, r5, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r4, [r0, 0x24]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x22
	ldrsh r0, [r3, r1]
	cmp r2, r0
	blt _081155D0
_081155F4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115588

	thumb_func_start sub_8115600
sub_8115600: @ 8115600
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gBattleAnimArgs
	movs r2, 0
	ldr r0, =gMovePowerMoveAnim
	ldrh r0, [r0]
	cmp r0, 0x63
	bls _08115614
	movs r2, 0x1
_08115614:
	strh r2, [r3, 0x1E]
	adds r0, r1, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115600

	thumb_func_start sub_8115628
sub_8115628: @ 8115628
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _08115648
	ldr r0, =gAnimationBankTarget
	b _0811564A
	.pool
_08115648:
	ldr r0, =gAnimationBankAttacker
_0811564A:
	ldrb r0, [r0]
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	ble _0811565A
	movs r0, 0x2
	eors r5, r0
_0811565A:
	ldr r0, =sub_81156D0
	ldrb r1, [r6, 0x2]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x20
	subs r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r1, r0
	strh r1, [r4, 0xA]
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x40
	subs r1, r0
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0xC]
	ldr r2, =gUnknown_02022E20
	ldrh r0, [r4, 0xA]
	strh r0, [r2]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	ldrh r0, [r6, 0x4]
	strh r0, [r4, 0xE]
	adds r0, r7, 0
	bl move_anim_task_del
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115628

	thumb_func_start sub_81156D0
sub_81156D0: @ 81156D0
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r2, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r4, 0xE
	ldrsh r1, [r0, r4]
	movs r4, 0xE
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne _08115710
	ldr r0, =gUnknown_02022E20
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	adds r0, r3, 0
	bl DestroyTask
	b _0811571C
	.pool
_08115710:
	ldr r1, =gUnknown_02022E20
	ldrh r0, [r2, 0xA]
	strh r0, [r1]
	ldr r1, =gUnknown_02022E22
	ldrh r0, [r2, 0xC]
	strh r0, [r1]
_0811571C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81156D0

	thumb_func_start sub_811572C
sub_811572C: @ 811572C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0811576C
	ldrh r0, [r5, 0x6]
	negs r0, r0
	strh r0, [r4, 0x30]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	b _0811577A
	.pool
_0811576C:
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x36]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0811577A:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x8]
	strh r0, [r4, 0x34]
	ldr r1, =sub_8115798
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811572C

	thumb_func_start sub_8115798
sub_8115798: @ 8115798
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0x1E
	bl Cos
	strh r0, [r4, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	movs r1, 0xA
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	cmp r0, 0x7F
	bhi _081157CA
	ldrb r0, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4, 0x5]
	b _081157D2
_081157CA:
	ldrb r0, [r4, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r4, 0x5]
_081157D2:
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x2E]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _081157F6
	adds r0, r4, 0
	bl move_anim_8072740
_081157F6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8115798

	thumb_func_start sub_81157FC
sub_81157FC: @ 81157FC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_811583C
	movs r1, 0x2
	ldrsb r1, [r4, r1]
	ldrb r2, [r4, 0x4]
	ldrb r3, [r4, 0x6]
	ldrh r4, [r4, 0x8]
	str r4, [sp]
	bl BeginNormalPaletteFade
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8115884
	str r0, [r5, 0x1C]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81157FC

	thumb_func_start sub_811583C
sub_811583C: @ 811583C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	movs r4, 0x1
	mov r8, r0
	mov r1, r8
	ands r1, r4
	mov r8, r1
	lsls r0, 16
	asrs r1, r0, 17
	ands r1, r4
	asrs r2, r0, 18
	ands r2, r4
	asrs r3, r0, 19
	ands r3, r4
	asrs r6, r0, 20
	ands r6, r4
	asrs r5, r0, 21
	ands r5, r4
	asrs r0, 22
	ands r0, r4
	str r6, [sp]
	str r5, [sp, 0x4]
	str r0, [sp, 0x8]
	mov r0, r8
	bl sub_80A75AC
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_811583C

	thumb_func_start sub_8115884
sub_8115884: @ 8115884
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0811589A
	adds r0, r2, 0
	bl move_anim_8072740
_0811589A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115884

	thumb_func_start sub_81158A4
sub_81158A4: @ 81158A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x2E]
	strh r0, [r5, 0x30]
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x32]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x34]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x36]
	ldrh r0, [r4, 0xA]
	strh r0, [r5, 0x38]
	ldrh r0, [r4, 0xC]
	strh r0, [r5, 0x3A]
	ldrh r0, [r4]
	strh r0, [r5, 0x3C]
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	bl sub_811583C
	ldrb r1, [r4, 0x8]
	ldrh r2, [r4, 0x6]
	bl BlendPalettes
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_81158F8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81158A4

	thumb_func_start sub_81158F8
sub_81158F8: @ 81158F8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0811590C
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	b _0811597C
_0811590C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0811597C
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08115930
	ldr r0, =sub_8115984
	str r0, [r4, 0x1C]
	b _0811597C
	.pool
_08115930:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	bl sub_811583C
	adds r3, r0, 0
	ldrh r1, [r4, 0x30]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08115956
	ldrh r1, [r4, 0x36]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x34]
	adds r0, r3, 0
	bl BlendPalettes
	b _08115964
_08115956:
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x38]
	adds r0, r3, 0
	bl BlendPalettes
_08115964:
	ldrh r0, [r4, 0x30]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	eors r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x32]
	subs r0, 0x1
	strh r0, [r4, 0x32]
_0811597C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81158F8

	thumb_func_start sub_8115984
sub_8115984: @ 8115984
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081159AA
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	bl sub_811583C
	movs r1, 0
	movs r2, 0
	bl BlendPalettes
	adds r0, r4, 0
	bl move_anim_8072740
_081159AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115984

	thumb_func_start sub_81159B4
sub_81159B4: @ 81159B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	movs r2, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r2, [r4, 0x2E]
	movs r0, 0xA
	strh r0, [r4, 0x30]
	movs r0, 0x8
	strh r0, [r4, 0x32]
	movs r0, 0x28
	strh r0, [r4, 0x34]
	movs r0, 0x70
	strh r0, [r4, 0x36]
	strh r2, [r4, 0x38]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A634C
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81159B4

	thumb_func_start sub_8115A04
sub_8115A04: @ 8115A04
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3]
	movs r5, 0
	strh r1, [r4, 0x8]
	ldrh r1, [r3, 0x2]
	strh r1, [r4, 0xA]
	ldrh r1, [r3, 0x4]
	strh r1, [r4, 0xC]
	ldrh r1, [r3, 0x6]
	strh r1, [r4, 0xE]
	ldrh r2, [r3, 0x8]
	strh r2, [r4, 0x10]
	ldrh r1, [r3, 0xA]
	strh r1, [r4, 0x12]
	strh r5, [r4, 0x18]
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0
	bl sub_8115A54
	ldr r0, =sub_8115AA4
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115A04

	thumb_func_start sub_8115A54
sub_8115A54: @ 8115A54
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	bl sub_811583C
	movs r1, 0xA
	ldrsb r1, [r4, r1]
	ldrh r2, [r4, 0x12]
	str r2, [sp]
	adds r2, r5, 0
	adds r3, r6, 0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x18]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x18]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115A54

	thumb_func_start sub_8115AA4
sub_8115AA4: @ 8115AA4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08115B06
	ldr r1, =gTasks
	lsls r2, r3, 2
	adds r0, r2, r3
	lsls r0, 3
	adds r3, r0, r1
	movs r5, 0xC
	ldrsh r0, [r3, r5]
	adds r6, r1, 0
	adds r5, r2, 0
	cmp r0, 0
	ble _08115B00
	movs r1, 0x18
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08115AE4
	ldrb r1, [r3, 0xE]
	ldrb r2, [r3, 0x10]
	b _08115AE8
	.pool
_08115AE4:
	ldrb r1, [r3, 0x10]
	ldrb r2, [r3, 0xE]
_08115AE8:
	adds r0, r5, r4
	lsls r0, 3
	adds r0, r6
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	cmp r0, 0x1
	bne _08115AF8
	movs r2, 0
_08115AF8:
	adds r0, r4, 0
	bl sub_8115A54
	b _08115B06
_08115B00:
	adds r0, r4, 0
	bl move_anim_task_del
_08115B06:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8115AA4

	thumb_func_start sub_8115B0C
sub_8115B0C: @ 8115B0C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r3, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r3
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0x8]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0xA]
	ldrh r1, [r2, 0x4]
	strh r1, [r0, 0xC]
	ldrh r1, [r2, 0x6]
	strh r1, [r0, 0xE]
	ldrh r1, [r2, 0x8]
	strh r1, [r0, 0x10]
	ldrh r1, [r2, 0xA]
	strh r1, [r0, 0x12]
	strh r5, [r0, 0x18]
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	mov r9, r3
	mov r8, r2
	cmp r5, r1
	bge _08115B74
	ldr r0, =gAnimationBankAttacker
	ldrb r3, [r0]
	ldr r7, =gAnimationBankTarget
	movs r0, 0x1
	mov r12, r0
	adds r2, r1, 0
_08115B5A:
	cmp r4, r3
	beq _08115B6E
	ldrb r1, [r7]
	cmp r4, r1
	beq _08115B6E
	adds r1, r4, 0
	adds r1, 0x10
	mov r0, r12
	lsls r0, r1
	orrs r5, r0
_08115B6E:
	adds r4, 0x1
	cmp r4, r2
	blt _08115B5A
_08115B74:
	mov r2, r8
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	bne _08115B82
	movs r0, 0xE
	orrs r5, r0
_08115B82:
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	add r4, r9
	lsrs r0, r5, 16
	strh r0, [r4, 0x1A]
	movs r0, 0xFF
	ands r5, r0
	strh r5, [r4, 0x1C]
	ldrb r2, [r4, 0x10]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8115BC8
	ldr r0, =sub_8115C18
	str r0, [r4]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115B0C

	thumb_func_start sub_8115BC8
sub_8115BC8: @ 8115BC8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrh r0, [r4, 0x1A]
	lsls r0, 16
	ldrh r1, [r4, 0x1C]
	orrs r0, r1
	movs r1, 0xA
	ldrsb r1, [r4, r1]
	ldrh r2, [r4, 0x12]
	str r2, [sp]
	adds r2, r5, 0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x18]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x18]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115BC8

	thumb_func_start sub_8115C18
sub_8115C18: @ 8115C18
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08115C7A
	ldr r1, =gTasks
	lsls r2, r3, 2
	adds r0, r2, r3
	lsls r0, 3
	adds r3, r0, r1
	movs r5, 0xC
	ldrsh r0, [r3, r5]
	adds r6, r1, 0
	adds r5, r2, 0
	cmp r0, 0
	ble _08115C74
	movs r1, 0x18
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08115C58
	ldrb r1, [r3, 0xE]
	ldrb r2, [r3, 0x10]
	b _08115C5C
	.pool
_08115C58:
	ldrb r1, [r3, 0x10]
	ldrb r2, [r3, 0xE]
_08115C5C:
	adds r0, r5, r4
	lsls r0, 3
	adds r0, r6
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	cmp r0, 0x1
	bne _08115C6C
	movs r2, 0
_08115C6C:
	adds r0, r4, 0
	bl sub_8115BC8
	b _08115C7A
_08115C74:
	adds r0, r4, 0
	bl move_anim_task_del
_08115C7A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8115C18

	thumb_func_start sub_8115C80
sub_8115C80: @ 8115C80
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3]
	movs r5, 0
	strh r1, [r4, 0x8]
	ldrh r1, [r3, 0x2]
	strh r1, [r4, 0xA]
	ldrh r1, [r3, 0x4]
	strh r1, [r4, 0xC]
	ldrh r1, [r3, 0x6]
	strh r1, [r4, 0xE]
	ldrh r2, [r3, 0x8]
	strh r2, [r4, 0x10]
	ldrh r1, [r3, 0xA]
	strh r1, [r4, 0x12]
	strh r5, [r4, 0x18]
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0
	bl sub_8115CD0
	ldr r0, =sub_8115D2C
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115C80

	thumb_func_start sub_8115CD0
sub_8115CD0: @ 8115CD0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrh r0, [r4, 0x8]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r2, 0x1
	lsls r2, r0
	movs r1, 0xA
	ldrsb r1, [r4, r1]
	ldrh r0, [r4, 0x12]
	str r0, [sp]
	adds r0, r2, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x18]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x18]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115CD0

	thumb_func_start sub_8115D2C
sub_8115D2C: @ 8115D2C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08115D8E
	ldr r1, =gTasks
	lsls r2, r3, 2
	adds r0, r2, r3
	lsls r0, 3
	adds r3, r0, r1
	movs r5, 0xC
	ldrsh r0, [r3, r5]
	adds r6, r1, 0
	adds r5, r2, 0
	cmp r0, 0
	ble _08115D88
	movs r1, 0x18
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _08115D6C
	ldrb r1, [r3, 0xE]
	ldrb r2, [r3, 0x10]
	b _08115D70
	.pool
_08115D6C:
	ldrb r1, [r3, 0x10]
	ldrb r2, [r3, 0xE]
_08115D70:
	adds r0, r5, r4
	lsls r0, 3
	adds r0, r6
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	cmp r0, 0x1
	bne _08115D80
	movs r2, 0
_08115D80:
	adds r0, r4, 0
	bl sub_8115CD0
	b _08115D8E
_08115D88:
	adds r0, r4, 0
	bl move_anim_task_del
_08115D8E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8115D2C

	thumb_func_start sub_8115D94
sub_8115D94: @ 8115D94
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x8]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0xA]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0xC]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0xE]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x10]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x12]
	ldrh r0, [r5, 0xC]
	strh r0, [r4, 0x14]
	ldrh r0, [r5]
	strh r0, [r4, 0x16]
	ldrh r0, [r5]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	ldrb r3, [r5, 0x8]
	ldrh r0, [r5, 0x6]
	str r0, [sp]
	adds r0, r1, 0
	movs r1, 0
	adds r2, r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8115E00
	str r0, [r4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115D94

	thumb_func_start sub_8115E00
sub_8115E00: @ 8115E00
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08115E28
	subs r0, r1, 0x1
	strh r0, [r4, 0x8]
	b _08115EAC
	.pool
_08115E28:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08115EAC
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _08115E4C
	ldr r0, =sub_8115EB8
	str r0, [r4]
	b _08115EAC
	.pool
_08115E4C:
	ldrh r0, [r4, 0x16]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r2, 0x1
	lsls r2, r0
	ldrh r1, [r4, 0xA]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08115E7A
	ldrb r3, [r4, 0x10]
	ldrh r0, [r4, 0xE]
	str r0, [sp]
	adds r0, r2, 0
	movs r1, 0
	adds r2, r3, 0
	bl BeginNormalPaletteFade
	b _08115E8A
_08115E7A:
	ldrb r3, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	str r0, [sp]
	adds r0, r2, 0
	movs r1, 0
	adds r2, r3, 0
	bl BeginNormalPaletteFade
_08115E8A:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xA]
	movs r3, 0x80
	lsls r3, 1
	adds r2, r3, 0
	eors r0, r2
	strh r0, [r1, 0xA]
	movs r2, 0xFF
	ands r0, r2
	strh r0, [r1, 0x8]
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
_08115EAC:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115E00

	thumb_func_start sub_8115EB8
sub_8115EB8: @ 8115EB8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08115EFE
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x16]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	str r5, [sp]
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl BeginNormalPaletteFade
	adds r0, r4, 0
	bl move_anim_task_del
_08115EFE:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115EB8

	thumb_func_start sub_8115F10
sub_8115F10: @ 8115F10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r2, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r6, [r0]
	ldr r0, =gAnimationBankTarget
	ldrb r7, [r0]
	ldr r4, =gBattleAnimArgs
	ldrh r1, [r4]
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08115F4A
	str r2, [sp]
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r3, 0
	bl sub_80A75AC
	adds r2, r0, 0
_08115F4A:
	ldrh r1, [r4, 0x2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08115F5C
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r6
	orrs r2, r0
_08115F5C:
	ldrh r1, [r4, 0x4]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08115F6E
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r7
	orrs r2, r0
_08115F6E:
	adds r0, r2, 0
	bl InvertPlttBuffer
	mov r0, r8
	bl move_anim_task_del
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115F10

	thumb_func_start sub_8115F94
sub_8115F94: @ 8115F94
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08115FD6
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0xE]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x10]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0xA]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x12]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x14]
	ldrh r0, [r1, 0xC]
	strh r0, [r4, 0x16]
_08115FD6:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	mov r9, r0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	mov r10, r0
	ldrh r1, [r4, 0xC]
	movs r7, 0x80
	lsls r7, 1
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08115FF8
	ldr r5, =0x0000ffff
_08115FF8:
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08116028
	ldr r2, =gSprites
	ldr r0, =gHealthBoxesIds
	add r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, 0x2]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r1, r6, 0
	lsls r1, r0
	lsls r1, 16
	orrs r5, r1
_08116028:
	ldrh r1, [r4, 0xE]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0811603C
	adds r0, r6, 0
	mov r2, r9
	lsls r0, r2
	lsls r0, 16
	orrs r5, r0
_0811603C:
	ldrh r1, [r4, 0x10]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08116050
	adds r0, r6, 0
	mov r1, r10
	lsls r0, r1
	lsls r0, 16
	orrs r5, r0
_08116050:
	movs r1, 0x12
	ldrsb r1, [r4, r1]
	movs r2, 0x14
	ldrsb r2, [r4, r2]
	movs r3, 0x16
	ldrsb r3, [r4, r3]
	adds r0, r5, 0
	bl TintPlttBuffer
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0811607A
	adds r0, r5, 0
	bl UnfadePlttBuffer
	mov r0, r8
	bl move_anim_task_del
_0811607A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115F94

	thumb_func_start sub_81160A4
sub_81160A4: @ 81160A4
	push {r4,lr}
	adds r4, r0, 0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x34]
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _081160EC
	cmp r0, 0x1
	bgt _081160DC
	cmp r0, 0
	beq _081160E2
	b _08116104
	.pool
_081160DC:
	cmp r0, 0x2
	beq _081160F4
	b _08116104
_081160E2:
	ldr r1, =gUnknown_02022E20
	b _081160F6
	.pool
_081160EC:
	ldr r1, =gUnknown_02022E22
	b _081160F6
	.pool
_081160F4:
	ldr r1, =gSpriteCoordOffsetX
_081160F6:
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	b _0811610C
	.pool
_08116104:
	ldr r1, =gSpriteCoordOffsetY
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
_0811610C:
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	lsls r0, 16
	orrs r1, r0
	ldrh r0, [r1]
	strh r0, [r4, 0x36]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x6]
	strh r0, [r4, 0x38]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08116130
	bl sub_81161F4
_08116130:
	ldr r0, =sub_8116148
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81160A4

	thumb_func_start sub_8116148
sub_8116148: @ 8116148
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x34]
	movs r2, 0x34
	ldrsh r0, [r3, r2]
	cmp r0, 0
	ble _0811618A
	subs r0, r1, 0x1
	strh r0, [r3, 0x34]
	ldrh r1, [r3, 0x30]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r0, 0
	ble _0811616A
	subs r0, r1, 0x1
	strh r0, [r3, 0x30]
	b _081161E2
_0811616A:
	ldrh r0, [r3, 0x32]
	strh r0, [r3, 0x30]
	movs r0, 0x3A
	ldrsh r1, [r3, r0]
	movs r2, 0x3C
	ldrsh r0, [r3, r2]
	lsls r0, 16
	orrs r1, r0
	ldrh r0, [r3, 0x2E]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	ldrh r0, [r3, 0x2E]
	negs r0, r0
	strh r0, [r3, 0x2E]
	b _081161E2
_0811618A:
	movs r0, 0x3A
	ldrsh r1, [r3, r0]
	movs r2, 0x3C
	ldrsh r0, [r3, r2]
	lsls r0, 16
	orrs r1, r0
	ldrh r0, [r3, 0x36]
	strh r0, [r1]
	ldrh r0, [r3, 0x38]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081161DC
	movs r4, 0
	ldr r5, =gNoOfAllBanks
	ldrb r0, [r5]
	cmp r4, r0
	bcs _081161DC
	ldr r2, =gSprites
	mov r12, r2
	ldr r6, =gBankSpriteIds
	movs r7, 0x3
	negs r7, r7
_081161BA:
	adds r0, r4, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r12
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5]
	cmp r4, r0
	bcc _081161BA
_081161DC:
	adds r0, r3, 0
	bl move_anim_8072740
_081161E2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116148

	thumb_func_start sub_81161F4
sub_81161F4: @ 81161F4
	push {r4-r6,lr}
	ldr r6, =gSprites
	ldr r4, =gBankSpriteIds
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x3
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r3, =gAnimationBankTarget
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r0, =gBattleAnimArgs
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	bne _0811627C
	ldrb r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	b _08116298
	.pool
_0811627C:
	cmp r0, 0
	bne _08116284
	ldrb r0, [r5]
	b _08116286
_08116284:
	ldrb r0, [r3]
_08116286:
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x2
_08116298:
	orrs r1, r2
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81161F4

	thumb_func_start sub_81162A4
sub_81162A4: @ 81162A4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3]
	strh r1, [r2, 0x8]
	ldrh r1, [r3, 0x2]
	strh r1, [r2, 0xA]
	ldrh r1, [r3, 0x4]
	strh r1, [r2, 0xC]
	ldrh r1, [r3, 0x6]
	strh r1, [r2, 0xE]
	ldrh r1, [r3, 0x6]
	strh r1, [r2, 0x18]
	ldr r4, =gUnknown_02022E20
	ldrh r1, [r3]
	strh r1, [r4]
	ldr r4, =gUnknown_02022E22
	ldrh r1, [r3, 0x2]
	strh r1, [r4]
	ldr r1, =sub_81162F8
	str r1, [r2]
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81162A4

	thumb_func_start sub_81162F8
sub_81162F8: @ 81162F8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r1
	ldrh r2, [r3, 0xE]
	movs r4, 0xE
	ldrsh r0, [r3, r4]
	mov r12, r1
	cmp r0, 0
	bne _0811637E
	ldr r0, =gUnknown_02022E20
	ldrh r2, [r0]
	movs r7, 0x8
	ldrsh r1, [r3, r7]
	adds r6, r0, 0
	cmp r2, r1
	bne _08116330
	ldrh r0, [r3, 0x8]
	negs r0, r0
	b _08116332
	.pool
_08116330:
	ldrh r0, [r3, 0x8]
_08116332:
	strh r0, [r6]
	ldr r2, =gUnknown_02022E22
	ldrh r3, [r2]
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	mov r7, r12
	adds r4, r0, r7
	movs r7, 0xA
	ldrsh r0, [r4, r7]
	cmn r3, r0
	bne _08116354
	movs r0, 0
	b _08116358
	.pool
_08116354:
	ldrh r0, [r4, 0xA]
	negs r0, r0
_08116358:
	strh r0, [r2]
	adds r0, r1, r5
	lsls r0, 3
	add r0, r12
	ldrh r1, [r0, 0x18]
	strh r1, [r0, 0xE]
	ldrh r1, [r0, 0xC]
	subs r1, 0x1
	strh r1, [r0, 0xC]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0
	bne _08116382
	strh r1, [r6]
	strh r1, [r2]
	adds r0, r5, 0
	bl move_anim_task_del
	b _08116382
_0811637E:
	subs r0, r2, 0x1
	strh r0, [r3, 0xE]
_08116382:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81162F8

	thumb_func_start sub_8116388
sub_8116388: @ 8116388
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x6]
	bl StartSpriteAffineAnim
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081163AC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _081163B4
	.pool
_081163AC:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
_081163B4:
	ldr r0, =sub_80A67BC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116388

	thumb_func_start sub_81163D0
sub_81163D0: @ 81163D0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x6]
	bl StartSpriteAffineAnim
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081163F4
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _081163FC
	.pool
_081163F4:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
_081163FC:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80A67BC
	str r0, [r5, 0x1C]
	ldr r1, =sub_810E2C8
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81163D0

	thumb_func_start sub_8116420
sub_8116420: @ 8116420
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08116444
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116444
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
_08116444:
	adds r0, r4, 0
	bl sub_8116388
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116420

	thumb_func_start sub_8116458
sub_8116458: @ 8116458
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08116474
	bl Random2
	movs r1, 0x3
	ands r1, r0
	strh r1, [r5, 0x2]
_08116474:
	ldrb r1, [r5, 0x2]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08116494
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	b _0811649C
	.pool
_08116494:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
_0811649C:
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x30
	bl __umodsi3
	ldr r1, =0x0000ffe8
	adds r0, r1
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x18
	bl __umodsi3
	ldr r1, =0x0000fff4
	adds r0, r1
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116458

	thumb_func_start sub_81164F0
sub_81164F0: @ 81164F0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrb r0, [r5]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	ldrh r0, [r0, 0x20]
	adds r1, r0
	strh r1, [r4, 0x20]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r1, r0
	strh r1, [r4, 0x22]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x24]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x26]
	ldrb r1, [r5, 0x6]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A67BC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81164F0

	thumb_func_start sub_8116560
sub_8116560: @ 8116560
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0811657C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _08116584
	.pool
_0811657C:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
_08116584:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x6]
	strh r0, [r4, 0x2E]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116560

	thumb_func_start sub_81165A8
sub_81165A8: @ 81165A8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x6]
	bl StartSpriteAffineAnim
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081165CC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _081165D4
	.pool
_081165CC:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
_081165D4:
	ldr r0, =sub_81165E4
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81165A8

	thumb_func_start sub_81165E4
sub_81165E4: @ 81165E4
	push {lr}
	adds r3, r0, 0
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x2E]
	adds r1, r0, 0x1
	strh r1, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0811661A
	adds r0, r3, 0
	bl move_anim_8072740
_0811661A:
	pop {r0}
	bx r0
	thumb_func_end sub_81165E4

	thumb_func_start sub_8116620
sub_8116620: @ 8116620
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_811583C
	adds r6, r0, 0
	ldrh r3, [r4]
	lsls r3, 16
	asrs r0, r3, 23
	movs r4, 0x1
	ands r0, r4
	asrs r1, r3, 24
	ands r1, r4
	asrs r2, r3, 25
	ands r2, r4
	asrs r3, 26
	ands r3, r4
	bl sub_80A76C4
	orrs r6, r0
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8116874
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116620

	thumb_func_start sub_8116664
sub_8116664: @ 8116664
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	movs r0, 0x1
	bl sub_811583C
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x7
	bhi _0811670E
	lsls r0, 2
	ldr r1, =_08116698
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08116698:
	.4byte _081166BA
	.4byte _081166C6
	.4byte _081166B8
	.4byte _081166C4
	.4byte _081166D4
	.4byte _081166EC
	.4byte _081166F4
	.4byte _08116700
_081166B8:
	movs r5, 0
_081166BA:
	mov r0, sp
	ldr r1, =gAnimationBankAttacker
	b _081166CA
	.pool
_081166C4:
	movs r5, 0
_081166C6:
	mov r0, sp
	ldr r1, =gAnimationBankTarget
_081166CA:
	ldrb r1, [r1]
	strb r1, [r0]
	b _0811670E
	.pool
_081166D4:
	mov r1, sp
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	b _0811670E
	.pool
_081166EC:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	b _0811670E
_081166F4:
	movs r5, 0
	mov r2, sp
	ldr r0, =gAnimationBankAttacker
	b _08116706
	.pool
_08116700:
	movs r5, 0
	mov r2, sp
	ldr r0, =gAnimationBankTarget
_08116706:
	ldrb r0, [r0]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r2]
_0811670E:
	movs r4, 0
	mov r6, sp
_08116712:
	ldrb r0, [r6]
	cmp r4, r0
	beq _0811673C
	ldrb r0, [r6, 0x1]
	cmp r4, r0
	beq _0811673C
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0811673C
	adds r0, r4, 0
	bl sub_80A77AC
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	orrs r5, r1
_0811673C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _08116712
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8116874
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116664

	thumb_func_start sub_811675C
sub_811675C: @ 811675C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_811583C
	adds r2, r0, 0
	ldr r0, =gUnknown_02022FF0
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _08116832
	lsls r0, 2
	ldr r1, =_0811678C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811678C:
	.4byte _081167B4
	.4byte _081167C4
	.4byte _081167D0
	.4byte _081167E0
	.4byte _081167EC
	.4byte _081167FC
	.4byte _0811680C
	.4byte _0811681C
	.4byte _0811682C
	.4byte _0811682C
_081167B4:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00000b0c
	b _08116830
	.pool
_081167C4:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x9E
	lsls r0, 4
	b _08116830
	.pool
_081167D0:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00002f1e
	b _08116830
	.pool
_081167E0:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x90
	lsls r0, 7
	b _08116830
	.pool
_081167EC:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007ecb
	b _08116830
	.pool
_081167FC:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007ecb
	b _08116830
	.pool
_0811680C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00002a16
	b _08116830
	.pool
_0811681C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00000d2e
	b _08116830
	.pool
_0811682C:
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x00007fff
_08116830:
	strh r0, [r1, 0x8]
_08116832:
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8116874
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811675C

	thumb_func_start sub_8116848
sub_8116848: @ 8116848
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	adds r0, r4, 0
	bl sub_8116874
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116848

	thumb_func_start sub_8116874
sub_8116874: @ 8116874
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	strh r1, [r2, 0x8]
	lsrs r1, 16
	strh r1, [r2, 0xA]
	ldr r3, =gBattleAnimArgs
	ldrh r1, [r3, 0x2]
	strh r1, [r2, 0xC]
	ldrh r1, [r3, 0x4]
	strh r1, [r2, 0xE]
	ldrh r1, [r3, 0x6]
	strh r1, [r2, 0x10]
	ldrh r1, [r3, 0x8]
	strh r1, [r2, 0x12]
	ldrh r1, [r3, 0x4]
	strh r1, [r2, 0x1C]
	ldr r1, =sub_81168B8
	str r1, [r2]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116874

	thumb_func_start sub_81168B8
sub_81168B8: @ 81168B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	ldr r2, =gTasks
	lsls r5, r7, 2
	adds r0, r5, r7
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1A]
	mov r8, r0
	movs r4, 0x1A
	ldrsh r1, [r3, r4]
	movs r4, 0xC
	ldrsh r0, [r3, r4]
	mov r9, r2
	cmp r1, r0
	bne _0811694E
	strh r6, [r3, 0x1A]
	movs r0, 0x8
	ldrsh r4, [r3, r0]
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	lsls r0, 16
	orrs r4, r0
	mov r8, r5
	cmp r4, 0
	beq _0811691A
	adds r5, r3, 0
_081168F8:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0811690C
	ldrb r2, [r5, 0x1C]
	ldrh r3, [r5, 0x12]
	adds r0, r6, 0
	movs r1, 0x10
	bl BlendPalette
_0811690C:
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	lsrs r4, 1
	cmp r4, 0
	bne _081168F8
_0811691A:
	mov r4, r8
	adds r0, r4, r7
	lsls r0, 3
	mov r1, r9
	adds r2, r0, r1
	ldrh r0, [r2, 0x1C]
	movs r4, 0x1C
	ldrsh r3, [r2, r4]
	movs r4, 0x10
	ldrsh r1, [r2, r4]
	cmp r3, r1
	bge _0811693C
	adds r0, 0x1
	strh r0, [r2, 0x1C]
	b _08116954
	.pool
_0811693C:
	cmp r3, r1
	ble _08116946
	subs r0, 0x1
	strh r0, [r2, 0x1C]
	b _08116954
_08116946:
	adds r0, r7, 0
	bl move_anim_task_del
	b _08116954
_0811694E:
	mov r0, r8
	adds r0, 0x1
	strh r0, [r3, 0x1A]
_08116954:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81168B8

	thumb_func_start sub_8116960
sub_8116960: @ 8116960
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gBattleAnimArgs
	ldrb r0, [r4]
	ldrb r1, [r4, 0x2]
	ldrb r2, [r4, 0x4]
	ldrb r3, [r4, 0x6]
	ldrb r4, [r4, 0x8]
	str r4, [sp]
	bl BeginHardwarePaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81169A0
	str r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116960

	thumb_func_start sub_81169A0
sub_81169A0: @ 81169A0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081169B8
	adds r0, r2, 0
	bl move_anim_task_del
_081169B8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81169A0

	thumb_func_start sub_81169C0
sub_81169C0: @ 81169C0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	movs r3, 0
	strh r0, [r1, 0x8]
	strh r3, [r1, 0xA]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0xC]
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0xE]
	ldrh r0, [r2, 0x6]
	strh r0, [r1, 0x10]
	strh r3, [r1, 0x12]
	ldr r0, =sub_81169F8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81169C0

	thumb_func_start sub_81169F8
sub_81169F8: @ 81169F8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08116ABC
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08116A28
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	b _08116ACA
	.pool
_08116A28:
	ldrb r0, [r4, 0x8]
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	blt _08116AA6
	ldr r6, =gSprites
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r3, r1, r6
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	movs r2, 0x2
	cmp r0, 0
	beq _08116A50
	movs r2, 0x1
_08116A50:
	lsls r2, 2
	ldrb r1, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x5]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r4, 0xE]
	strh r1, [r0, 0x2E]
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r5, [r0, 0x30]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	strh r1, [r0, 0x32]
	movs r2, 0x14
	ldrsh r1, [r4, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8116AD0
	str r1, [r0]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
_08116AA6:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xA]
	b _08116ACA
	.pool
_08116ABC:
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08116ACA
	adds r0, r2, 0
	bl move_anim_task_del
_08116ACA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81169F8

	thumb_func_start sub_8116AD0
sub_8116AD0: @ 8116AD0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08116AE4
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
	b _08116B08
_08116AE4:
	ldr r3, =gTasks
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl obj_delete_but_dont_free_vram
_08116B08:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116AD0

	thumb_func_start sub_8116B14
sub_8116B14: @ 8116B14
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r7, 0
	ldr r0, =gUnknown_02022E24
	strh r7, [r0]
	ldr r0, =gUnknown_02022E26
	strh r7, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000c08
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0xA
	bl GetGpuReg
	add r4, sp, 0x10
	strh r0, [r4]
	ldrb r1, [r4]
	movs r0, 0x4
	negs r0, r0
	mov r8, r0
	ands r0, r1
	strb r0, [r4]
	mov r2, sp
	adds r2, 0x11
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116BA2
	ldrb r1, [r4]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
_08116BA2:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08116C26
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116C26
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08116BD2
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	bne _08116C26
_08116BD2:
	ldrb r0, [r5]
	movs r6, 0x2
	eors r0, r6
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08116C26
	ldr r3, =gSprites
	ldr r1, =gBankSpriteIds
	ldrb r0, [r5]
	eors r0, r6
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4]
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	movs r7, 0x1
_08116C26:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08116C64
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r5, [r0]
	b _08116CAC
	.pool
_08116C64:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08116C90
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08116CA0
	.pool
_08116C90:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08116CA0:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
_08116CAC:
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A89C8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C20684
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C20668
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08597418
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	adds r1, 0x1
	movs r2, 0x2
	bl LoadPalette
	ldr r2, =gUnknown_02022E18
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldr r2, =gUnknown_02022E1A
	ldrh r0, [r1, 0x22]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	strh r7, [r0, 0x14]
	ldr r1, =sub_8116D64
	str r1, [r0]
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116B14

	thumb_func_start sub_8116D64
sub_8116D64: @ 8116D64
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0x1C]
	adds r0, 0x4
	movs r1, 0
	mov r8, r1
	strh r0, [r5, 0x1C]
	ldr r7, =gUnknown_02022E1A
	ldrh r2, [r7]
	subs r1, r2, 0x4
	strh r1, [r7]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	bne _08116E86
	mov r0, r8
	strh r0, [r5, 0x1C]
	adds r0, r2, 0
	adds r0, 0x3C
	strh r0, [r7]
	ldrh r0, [r5, 0x1E]
	adds r0, 0x1
	strh r0, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08116E86
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gUnknown_02022E24
	mov r1, r8
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116DF6
	movs r0, 0xA
	bl GetGpuReg
	add r1, sp, 0x10
	strh r0, [r1]
	ldrb r2, [r1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrh r1, [r1]
	movs r0, 0xA
	bl SetGpuReg
_08116DF6:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl GetAnimBankSpriteId
	ldr r4, =gSprites
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08116E7C
	ldr r2, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
_08116E7C:
	mov r2, r8
	strh r2, [r7]
	adds r0, r6, 0
	bl move_anim_task_del
_08116E86:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116D64

	thumb_func_start sub_8116EB4
sub_8116EB4: @ 8116EB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203A110
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r4]
	movs r2, 0
	ldr r3, =gBattleAnimArgs
_08116EC8:
	ldr r1, [r4]
	lsls r0, r2, 1
	adds r1, 0x4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _08116EC8
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8116F04
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116EB4

	thumb_func_start sub_8116F04
sub_8116F04: @ 8116F04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203A110
	ldr r1, [r0]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08116F24
	ldr r0, =gAnimationBankAttacker
	b _08116F26
	.pool
_08116F24:
	ldr r0, =gAnimationBankTarget
_08116F26:
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r4, =gUnknown_0203A110
	ldr r2, [r4]
	ldrb r0, [r2]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r2, 0x1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116F56
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08116F5C
	ldrb r0, [r1, 0x1]
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _08116F5C
_08116F56:
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0xA]
_08116F5C:
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08116FBA
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_08116FBA:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08117036
	ldr r4, =gUnknown_0203A110
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08117036
	ldrb r0, [r1]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08116FEC
	ldr r0, [r4]
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	bne _08117036
_08116FEC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08117036
	ldr r3, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, [r4]
	strb r5, [r0, 0x2]
_08117036:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117078
	ldr r0, =gUnknown_0203A110
	ldr r1, [r0]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	b _081170C4
	.pool
_08117078:
	ldr r4, =gUnknown_0203A110
	ldr r0, [r4]
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _081170A8
	ldr r1, =gBattlePartyID
	ldr r0, [r4]
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _081170BA
	.pool
_081170A8:
	ldr r1, =gBattlePartyID
	ldr r0, [r4]
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_081170BA:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	ldr r1, [r4]
_081170C4:
	strh r0, [r1, 0x14]
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81170EC
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8116F04

	thumb_func_start sub_81170EC
sub_81170EC: @ 81170EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r6, =gBankSpriteIds
	ldr r4, =gUnknown_0203A110
	ldr r2, [r4]
	ldrb r0, [r2]
	adds r1, r0, r6
	ldrb r1, [r1]
	ldrh r2, [r2, 0x14]
	bl sub_80A89C8
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, [r4]
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0811712E
	ldrb r0, [r2, 0x1]
	adds r1, r0, r6
	ldrb r1, [r1]
	ldrh r2, [r2, 0x14]
	bl sub_80A89C8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_0811712E:
	mov r0, sp
	bl sub_80A6B30
	ldr r0, [r4]
	movs r4, 0x4
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bne _08117158
	ldr r1, =gUnknown_08C2D930
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	b _08117162
	.pool
_08117158:
	ldr r1, =gUnknown_08C2DA4C
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
_08117162:
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2D720
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_0203A110
	ldr r0, [r0]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	bhi _081171F8
	lsls r0, 2
	ldr r1, =_08117198
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08117198:
	.4byte _081171B4
	.4byte _081171BC
	.4byte _081171C4
	.4byte _081171CC
	.4byte _081171D4
	.4byte _081171DC
	.4byte _081171E4
_081171B4:
	ldr r0, =gUnknown_08C2DB88
	b _081171E6
	.pool
_081171BC:
	ldr r0, =gUnknown_08C2DB68
	b _081171E6
	.pool
_081171C4:
	ldr r0, =gUnknown_08C2DBA8
	b _081171E6
	.pool
_081171CC:
	ldr r0, =gUnknown_08C2DBC8
	b _081171E6
	.pool
_081171D4:
	ldr r0, =gUnknown_08C2DC08
	b _081171E6
	.pool
_081171DC:
	ldr r0, =gUnknown_08C2DC28
	b _081171E6
	.pool
_081171E4:
	ldr r0, =gUnknown_08C2DC48
_081171E6:
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	b _08117206
	.pool
_081171F8:
	ldr r0, =gUnknown_08C2DBE8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
_08117206:
	ldr r3, =gUnknown_02022E18
	movs r2, 0
	strh r2, [r3]
	ldr r0, =gUnknown_02022E1A
	strh r2, [r0]
	ldr r1, =gUnknown_0203A110
	ldr r0, [r1]
	movs r4, 0x4
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	cmp r0, 0x1
	bne _08117248
	movs r0, 0x40
	strh r0, [r3]
	ldr r2, =gTasks
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	ldr r1, =0x0000fffd
	b _08117254
	.pool
_08117248:
	ldr r2, =gTasks
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x3
_08117254:
	strh r1, [r0, 0xA]
	ldr r0, [r4]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117274
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0xA
	strh r1, [r0, 0x10]
	movs r1, 0x14
	b _08117280
	.pool
_08117274:
	adds r0, r3, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0xD
	strh r1, [r0, 0x10]
	movs r1, 0x1E
_08117280:
	strh r1, [r0, 0x12]
	adds r1, r3, r5
	lsls r1, 3
	adds r1, r2
	strh r7, [r1, 0x8]
	ldr r3, [r4]
	ldrh r0, [r3, 0xA]
	strh r0, [r1, 0xC]
	mov r4, r8
	strh r4, [r1, 0xE]
	ldrb r0, [r3, 0x2]
	strh r0, [r1, 0x14]
	ldr r2, =gBankSpriteIds
	ldrb r0, [r3, 0x1]
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0x16]
	ldr r0, =sub_81172EC
	str r0, [r1]
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _081172CC
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5278
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xEF
	bl PlaySE12WithPanning
	b _081172E0
	.pool
_081172CC:
	movs r0, 0x40
	negs r0, r0
	bl sub_80A5278
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xF5
	bl PlaySE12WithPanning
_081172E0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81170EC

	thumb_func_start sub_81172EC
sub_81172EC: @ 81172EC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gUnknown_02022E1A
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	ldrh r1, [r2]
	adds r0, r1
	strh r0, [r2]
	movs r0, 0x26
	ldrsh r2, [r5, r0]
	cmp r2, 0x1
	beq _08117362
	cmp r2, 0x1
	bgt _08117320
	cmp r2, 0
	beq _0811732A
	b _08117478
	.pool
_08117320:
	cmp r2, 0x2
	beq _08117378
	cmp r2, 0x3
	beq _081173B6
	b _08117478
_0811732A:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	cmp r0, 0
	bgt _08117338
	b _08117478
_08117338:
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _08117360
	b _08117478
_08117360:
	b _081173AE
_08117362:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	cmp r0, r1
	beq _08117376
	b _08117478
_08117376:
	b _081173AE
_08117378:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	cmp r0, 0
	ble _08117478
	movs r0, 0
	strh r0, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08117478
	movs r0, 0
	bl sub_80A477C
_081173AE:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08117478
_081173B6:
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081173E6
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_081173E6:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0811743A
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0811743A:
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08117466
	movs r2, 0x16
	ldrsh r0, [r5, r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
_08117466:
	ldr r4, =gUnknown_0203A110
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r6, 0
	bl move_anim_task_del
_08117478:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81172EC

	thumb_func_start sub_8117494
sub_8117494: @ 8117494
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80A76C4
	adds r6, r0, 0
	movs r1, 0
	bl sub_81175C4
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	lsrs r0, r6, 16
	movs r5, 0
	strh r0, [r4, 0x24]
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r6, r0, 0
	ldr r1, =0x0000ffff
	ands r6, r1
	adds r0, r6, 0
	bl sub_81175C4
	strh r6, [r4, 0x26]
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	ldr r0, =sub_8117500
	str r0, [r4]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117494

	thumb_func_start sub_8117500
sub_8117500: @ 8117500
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _08117544
	cmp r1, 0x1
	bgt _08117528
	cmp r1, 0
	beq _0811752E
	b _081175BE
	.pool
_08117528:
	cmp r1, 0x2
	beq _081175B8
	b _081175BE
_0811752E:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _081175BE
	strh r1, [r4, 0xA]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	b _081175AC
_08117544:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081175BE
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	movs r5, 0
	movs r6, 0x1
_08117560:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	asrs r0, r5
	ands r0, r6
	cmp r0, 0
	beq _0811757A
	lsls r0, r5, 20
	lsrs r0, 16
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	ldr r3, =0x0000ffff
	bl BlendPalette
_0811757A:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	asrs r0, r5
	ands r0, r6
	cmp r0, 0
	beq _0811759A
	lsls r0, r5, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldrb r2, [r4, 0xC]
	movs r1, 0x10
	movs r3, 0
	bl BlendPalette
_0811759A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _08117560
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081175BE
_081175AC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081175BE
	.pool
_081175B8:
	adds r0, r2, 0
	bl move_anim_task_del
_081175BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8117500

	thumb_func_start sub_81175C4
sub_81175C4: @ 81175C4
	push {r4-r6,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	movs r2, 0
_081175CE:
	movs r0, 0x1
	ands r0, r3
	lsrs r4, r3, 1
	adds r5, r2, 0x1
	cmp r0, 0
	beq _081175FA
	lsls r0, r2, 20
	lsrs r2, r0, 16
	adds r0, r2, 0
	adds r0, 0x10
	cmp r2, r0
	bge _081175FA
	ldr r1, =gPlttBufferFaded
	adds r3, r0, 0
_081175EA:
	lsls r0, r2, 1
	adds r0, r1
	strh r6, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	blt _081175EA
_081175FA:
	adds r3, r4, 0
	lsls r0, r5, 16
	lsrs r2, r0, 16
	cmp r2, 0x1F
	bls _081175CE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81175C4

	thumb_func_start sub_8117610
sub_8117610: @ 8117610
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	movs r2, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r3, [r0]
	movs r5, 0x1
_08117620:
	cmp r3, r2
	beq _0811762E
	adds r1, r2, 0
	adds r1, 0x10
	adds r0, r5, 0
	lsls r0, r1
	orrs r4, r0
_0811762E:
	adds r2, 0x1
	cmp r2, 0x3
	bls _08117620
	movs r2, 0x5
	ldr r0, =gBattleAnimArgs
	adds r1, r0, 0
	adds r1, 0x8
_0811763C:
	ldrh r0, [r1]
	strh r0, [r1, 0x2]
	subs r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _0811763C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8116874
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117610

	thumb_func_start sub_8117660
sub_8117660: @ 8117660
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl sub_80A6DAC
	ldr r0, =sub_81176D8
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0811769C
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0811769C
	ldrh r0, [r4]
	negs r0, r0
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
_0811769C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r1, 0xA]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0xC]
	ldrh r0, [r2, 0x6]
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	adds r0, r6, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117660

	thumb_func_start sub_81176D8
sub_81176D8: @ 81176D8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r3, [r1, 0xA]
	ldrh r0, [r1, 0x1C]
	adds r3, r0
	movs r4, 0
	mov r12, r4
	strh r3, [r1, 0x1C]
	ldrh r2, [r1, 0xC]
	ldrh r7, [r1, 0x1E]
	adds r2, r7
	strh r2, [r1, 0x1E]
	ldr r6, =gUnknown_02022E20
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r4, [r6]
	adds r0, r4
	strh r0, [r6]
	ldr r4, =gUnknown_02022E22
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r7, [r4]
	adds r0, r7
	strh r0, [r4]
	movs r0, 0xFF
	ands r3, r0
	strh r3, [r1, 0x1C]
	ands r2, r0
	strh r2, [r1, 0x1E]
	ldr r0, =gBattleAnimArgs
	movs r3, 0xE
	ldrsh r2, [r0, r3]
	movs r7, 0xE
	ldrsh r0, [r1, r7]
	cmp r2, r0
	bne _0811773E
	mov r0, r12
	strh r0, [r6]
	strh r0, [r4]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r5, 0
	bl DestroyTask
_0811773E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81176D8

	thumb_func_start sub_8117754
sub_8117754: @ 8117754
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	ldr r1, =gBattleAnimArgs
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117754

	thumb_func_start sub_8117780
sub_8117780: @ 8117780
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	ldr r1, =gBattleAnimArgs
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117780

	thumb_func_start sub_81177AC
sub_81177AC: @ 81177AC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r5, =gBattleAnimArgs
	movs r4, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r2, [r0]
	movs r0, 0x2
	ldr r1, =gAnimationBankTarget
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bne _081177C8
	movs r4, 0x1
_081177C8:
	strh r4, [r5, 0xE]
	adds r0, r3, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81177AC

	thumb_func_start sub_81177E4
sub_81177E4: @ 81177E4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r6, =gSprites
_081177EE:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	cmp r4, r0
	beq _0811782C
	lsls r0, r4, 24
	lsrs r0, 24
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _0811782C
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldr r1, =gBattleAnimArgs
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r3, [r1]
	ands r3, r0
	lsls r3, 2
	ldrb r0, [r2]
	movs r7, 0x5
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_0811782C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _081177EE
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81177E4

	thumb_func_start sub_8117854
sub_8117854: @ 8117854
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r1, [sp, 0x44]
	ldr r4, [sp, 0x48]
	ldr r5, [sp, 0x4C]
	ldr r6, [sp, 0x50]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x14]
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x18]
	lsls r5, 24
	lsrs r5, 24
	str r5, [sp, 0x1C]
	lsls r6, 24
	lsrs r6, 24
	mov r10, r6
	movs r0, 0
	str r0, [sp, 0x20]
	movs r0, 0x2
	adds r6, r7, 0
	eors r6, r0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081178B6
	mov r1, r8
	cmp r1, 0
	beq _081178BA
	adds r0, r6, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _081178BA
_081178B6:
	movs r2, 0
	mov r8, r2
_081178BA:
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0xA
	bl GetGpuReg
	add r4, sp, 0x10
	strh r0, [r4]
	ldrb r1, [r4]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	mov r2, sp
	adds r2, 0x11
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08117930
	ldrb r0, [r4]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4]
_08117930:
	ldrh r1, [r4]
	movs r0, 0xA
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117964
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r4, [r0]
	b _081179A2
	.pool
_08117964:
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08117988
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08117996
	.pool
_08117988:
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08117996:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
_081179A2:
	ldr r5, =gBankSpriteIds
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r0, r7, 0
	adds r2, r4, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r8
	cmp r0, 0
	beq _081179CC
	adds r0, r6, r5
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
_081179CC:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldr r1, [sp, 0x58]
	movs r2, 0
	bl sub_80A6D60
	mov r0, sp
	ldrb r0, [r0, 0x9]
	mov r1, sp
	ldrh r2, [r1, 0xA]
	ldr r1, [sp, 0x54]
	bl sub_80A6CC0
	mov r0, sp
	ldrb r1, [r0, 0x8]
	lsls r1, 4
	ldr r0, [sp, 0x5C]
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0xA]
	mov r2, sp
	ldrh r2, [r2, 0x18]
	strh r2, [r0, 0x10]
	mov r1, r10
	strh r1, [r0, 0x12]
	mov r2, sp
	ldrh r2, [r2, 0x1C]
	strh r2, [r0, 0x14]
	strh r7, [r0, 0x8]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r2, sp
	ldrh r2, [r2, 0x20]
	strh r2, [r0, 0xE]
	ldr r1, =sub_8117A60
	str r1, [r0]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117854

	thumb_func_start sub_8117A60
sub_8117A60: @ 8117A60
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r3, r0, r1
	movs r0, 0xA
	ldrsh r2, [r3, r0]
	adds r5, r1, 0
	cmp r2, 0
	bge _08117A7E
	negs r2, r2
_08117A7E:
	ldrh r0, [r3, 0x22]
	adds r4, r0, r2
	strh r4, [r3, 0x22]
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bge _08117AA4
	ldr r2, =gUnknown_02022E1A
	lsls r1, r4, 16
	asrs r1, 24
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	b _08117AB0
	.pool
_08117AA4:
	ldr r1, =gUnknown_02022E1A
	lsls r0, r4, 16
	asrs r0, 24
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
_08117AB0:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r5
	ldrh r1, [r5, 0x22]
	movs r0, 0xFF
	ands r0, r1
	movs r2, 0
	strh r0, [r5, 0x22]
	movs r3, 0x26
	ldrsh r0, [r5, r3]
	cmp r0, 0x1
	beq _08117B1A
	cmp r0, 0x1
	bgt _08117AD8
	cmp r0, 0
	beq _08117ADE
	b _08117C0C
	.pool
_08117AD8:
	cmp r0, 0x2
	beq _08117B34
	b _08117C0C
_08117ADE:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x14
	ldrsh r1, [r5, r3]
	cmp r0, r1
	bge _08117AF2
	b _08117C0C
_08117AF2:
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _08117C0C
	b _08117B2C
_08117B1A:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r5, r3]
	cmp r0, r1
	bne _08117C0C
_08117B2C:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08117C0C
_08117B34:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x14
	ldrsh r1, [r5, r3]
	cmp r0, r1
	blt _08117C0C
	strh r2, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r4, [r5, r0]
	cmp r4, 0
	bne _08117C0C
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gUnknown_02022E24
	strh r4, [r0]
	ldr r0, =gUnknown_02022E26
	strh r4, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08117BB2
	movs r0, 0xA
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0xA
	bl SetGpuReg
_08117BB2:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r3, 0x8
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08117C06
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_08117C06:
	adds r0, r6, 0
	bl move_anim_task_del
_08117C0C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117A60

	thumb_func_start sub_8117C24
sub_8117C24: @ 8117C24
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimArgs
	ldr r1, =gUnknown_02022FF0
	ldrb r1, [r1]
	strh r1, [r2]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117C24

	thumb_func_start sub_8117C44
sub_8117C44: @ 8117C44
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	ldr r1, =gBattleSpritesGfx
	ldr r1, [r1]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117C44

	thumb_func_start sub_8117C70
sub_8117C70: @ 8117C70
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gBattleSpritesGfx
	ldr r0, [r6]
	movs r5, 0xBE
	lsls r5, 1
	adds r0, r5
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0
	str r1, [r0]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117C70

	thumb_func_start sub_8117CA0
sub_8117CA0: @ 8117CA0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117CE4
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117CFC
	movs r2, 0x1
_08117CD2:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117CD2
	b _08117CFC
	.pool
_08117CE4:
	cmp r0, 0x1
	bne _08117CF0
	ldr r0, =gAnimationBankAttacker
	b _08117CF6
	.pool
_08117CF0:
	cmp r0, 0x2
	bne _08117CFC
	ldr r0, =gAnimationBankTarget
_08117CF6:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117CFC:
	ldr r0, =gBattleSpritesGfx
	ldr r1, [r0]
	ldr r0, =gBattleAnimArgs
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	lsls r1, r4, 5
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl move_anim_task_del
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117CA0

	thumb_func_start sub_8117D3C
sub_8117D3C: @ 8117D3C
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117D80
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117D98
	movs r2, 0x1
_08117D6E:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117D6E
	b _08117D98
	.pool
_08117D80:
	cmp r0, 0x1
	bne _08117D8C
	ldr r0, =gAnimationBankAttacker
	b _08117D92
	.pool
_08117D8C:
	cmp r0, 0x2
	bne _08117D98
	ldr r0, =gAnimationBankTarget
_08117D92:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117D98:
	lsls r0, r4, 5
	ldr r1, =gPlttBufferUnfaded
	adds r0, r1
	ldr r1, =gBattleSpritesGfx
	ldr r2, [r1]
	ldr r1, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	movs r3, 0xBE
	lsls r3, 1
	adds r2, r3
	ldr r2, [r2]
	lsls r1, 5
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl move_anim_task_del
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117D3C

	thumb_func_start sub_8117DD8
sub_8117DD8: @ 8117DD8
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08117E1C
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r1, r0, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08117E34
	movs r2, 0x1
_08117E0A:
	lsrs r1, 1
	adds r4, 0x1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _08117E0A
	b _08117E34
	.pool
_08117E1C:
	cmp r0, 0x1
	bne _08117E28
	ldr r0, =gAnimationBankAttacker
	b _08117E2E
	.pool
_08117E28:
	cmp r0, 0x2
	bne _08117E34
	ldr r0, =gAnimationBankTarget
_08117E2E:
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
_08117E34:
	lsls r1, r4, 5
	ldr r0, =gPlttBufferUnfaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferFaded
	adds r1, r2
	movs r2, 0x20
	bl memcpy
	adds r0, r5, 0
	bl move_anim_task_del
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117DD8

	thumb_func_start sub_8117E60
sub_8117E60: @ 8117E60
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08117E80
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
	b _08117E84
	.pool
_08117E80:
	ldr r0, =gBattleAnimArgs
	strh r1, [r0, 0xE]
_08117E84:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117E60

	thumb_func_start sub_8117E94
sub_8117E94: @ 8117E94
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gAnimationBankAttacker
	ldr r1, =gBankTarget
	ldrb r1, [r1]
	strb r1, [r2]
	ldr r2, =gAnimationBankTarget
	ldr r1, =gUnknown_0202420E
	ldrb r1, [r1]
	strb r1, [r2]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117E94

	thumb_func_start sub_8117EC4
sub_8117EC4: @ 8117EC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _08117EF8
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	b _08117EFC
	.pool
_08117EF8:
	ldr r1, =gBattleAnimArgs
	movs r0, 0
_08117EFC:
	strh r0, [r1, 0xE]
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117EC4

	thumb_func_start sub_8117F10
sub_8117F10: @ 8117F10
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gAnimationBankTarget
	ldr r1, =gBankTarget
	ldrb r1, [r1]
	strb r1, [r2]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F10

	thumb_func_start sub_8117F30
sub_8117F30: @ 8117F30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gAnimationBankAttacker
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	strb r1, [r2]
	ldr r2, =gAnimationBankTarget
	ldr r1, =gUnknown_0202420E
	ldrb r1, [r1]
	strb r1, [r2]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F30

	thumb_func_start sub_8117F60
sub_8117F60: @ 8117F60
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08117F78
	adds r0, r4, 0
	bl move_anim_task_del
	b _08117FB4
_08117F78:
	ldr r0, =gTasks
	lsls r3, r4, 2
	adds r3, r4
	lsls r3, 3
	adds r3, r0
	ldr r0, =gUnknown_020244D0
	ldr r4, [r0]
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	ldr r1, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	strh r0, [r3, 0x8]
	ldrb r1, [r2]
	ldr r0, [r4]
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =sub_8117FD0
	str r0, [r3]
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_08117FB4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117F60

	thumb_func_start sub_8117FD0
sub_8117FD0: @ 8117FD0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08118014
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankAttacker
	ldrb r3, [r0]
	ldr r0, [r1]
	lsls r3, 2
	adds r3, r0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x8]
	movs r1, 0x1
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0
	bl DestroyTask
_08118014:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8117FD0

	thumb_func_start lcd_bg_operations
lcd_bg_operations: @ 811802C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r6, 0x3
	bls _08118040
	b _08118132
_08118040:
	ldr r0, =gUnknown_0859741A
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetGpuReg
	ldr r1, =gUnknown_0203A114
	strh r0, [r1]
	cmp r5, 0x6
	bhi _08118124
	lsls r0, r5, 2
	ldr r1, =_08118068
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118068:
	.4byte _08118084
	.4byte _08118098
	.4byte _081180B0
	.4byte _081180C8
	.4byte _081180E0
	.4byte _081180FC
	.4byte _08118110
_08118084:
	ldr r2, =gUnknown_0203A114
	lsls r3, r4, 6
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x1]
	b _08118124
	.pool
_08118098:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r3, 0x1]
	movs r0, 0x21
	negs r0, r0
	b _0811811E
	.pool
_081180B0:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r3]
	movs r0, 0x41
	negs r0, r0
	b _081180EE
	.pool
_081180C8:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0xD
	negs r0, r0
	b _081180EE
	.pool
_081180E0:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x4
	negs r0, r0
_081180EE:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08118124
	.pool
_081180FC:
	ldr r2, =gUnknown_0203A114
	lsls r3, r4, 7
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	b _08118124
	.pool
_08118110:
	ldr r3, =gUnknown_0203A114
	movs r0, 0x1F
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r3, 0x1]
	movs r0, 0x20
	negs r0, r0
_0811811E:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
_08118124:
	ldr r0, =gUnknown_0859741A
	adds r0, r6, r0
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203A114
	ldrh r1, [r1]
	bl SetGpuReg
_08118132:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_bg_operations

	thumb_func_start sub_8118140
sub_8118140: @ 8118140
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r2, 0x3
	bhi _081181C8
	ldr r0, =gUnknown_0859741E
	adds r0, r2, r0
	ldrb r0, [r0]
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	cmp r4, 0x6
	bhi _081181C8
	lsls r0, r4, 2
	ldr r1, =_08118174
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118174:
	.4byte _08118190
	.4byte _08118198
	.4byte _081181A0
	.4byte _081181A8
	.4byte _081181B0
	.4byte _081181B8
	.4byte _081181C0
_08118190:
	ldr r0, [sp]
	lsls r0, 16
	lsrs r0, 30
	b _081181CA
_08118198:
	ldr r0, [sp]
	lsls r0, 18
	lsrs r0, 31
	b _081181CA
_081181A0:
	ldr r0, [sp]
	lsls r0, 25
	lsrs r0, 31
	b _081181CA
_081181A8:
	ldr r0, [sp]
	lsls r0, 28
	lsrs r0, 30
	b _081181CA
_081181B0:
	ldr r0, [sp]
	lsls r0, 30
	lsrs r0, 30
	b _081181CA
_081181B8:
	ldr r0, [sp]
	lsls r0, 24
	lsrs r0, 31
	b _081181CA
_081181C0:
	ldr r0, [sp]
	lsls r0, 19
	lsrs r0, 27
	b _081181CA
_081181C8:
	movs r0, 0
_081181CA:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8118140

	thumb_func_start battle_intro_launch
battle_intro_launch: @ 81181D4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08118208
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	beq _08118208
	ldr r0, =sub_8118D68
	b _08118258
	.pool
_08118208:
	ldr r2, [r2]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0811821C
	ldr r0, =task00_battle_intro_wireless
	b _08118258
	.pool
_0811821C:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _08118230
	ldr r0, =task_battle_intro_anim
	b _08118258
	.pool
_08118230:
	movs r0, 0x80
	lsls r0, 5
	ands r2, r0
	cmp r2, 0
	beq _08118250
	ldr r0, =gGameVersion
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08118250
	movs r4, 0x3
	ldr r0, =task00_battle_intro_80BC6C8
	b _08118258
	.pool
_08118250:
	ldr r1, =gUnknown_08597424
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
_08118258:
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r4, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	strh r0, [r1, 0x12]
	strh r0, [r1, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_intro_launch

	thumb_func_start sub_811828C
sub_811828C: @ 811828C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811828C

	thumb_func_start task_battle_intro_80BC47C
task_battle_intro_80BC47C: @ 81182EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r1]
	adds r0, 0x6
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	mov r8, r1
	cmp r0, 0x4
	bls _08118318
	b _0811852A
_08118318:
	lsls r0, 2
	ldr r1, =_08118330
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118330:
	.4byte _08118344
	.4byte _08118374
	.4byte _0811839C
	.4byte _081183E4
	.4byte _08118524
_08118344:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08118360
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r1, 0x10
	b _0811836A
	.pool
_08118360:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r1, 0x1
_0811836A:
	strh r1, [r0, 0xC]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0811852A
_08118374:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	mov r3, r8
	adds r1, r0, r3
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _0811838C
	b _0811852A
_0811838C:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _0811852A
_0811839C:
	ldr r1, =gUnknown_02022E26
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _081183B4
	b _0811852A
_081183B4:
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	add r1, r8
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	ldr r2, =gUnknown_020243FC
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _0811852A
	.pool
_081183E4:
	lsls r0, r4, 2
	adds r1, r0, r4
	lsls r1, 3
	mov r5, r8
	adds r2, r1, r5
	ldrh r3, [r2, 0xE]
	movs r5, 0xE
	ldrsh r1, [r2, r5]
	mov r12, r0
	cmp r1, 0
	beq _08118400
	subs r0, r3, 0x1
	strh r0, [r2, 0xE]
	b _0811842E
_08118400:
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	bne _08118420
	ldr r2, =gUnknown_02022E1A
	ldrh r1, [r2]
	ldr r0, =0x0000ffb0
	cmp r1, r0
	beq _0811842E
	subs r0, r1, 0x2
	b _0811842C
	.pool
_08118420:
	ldr r2, =gUnknown_02022E1A
	ldrh r1, [r2]
	ldr r0, =0x0000ffc8
	cmp r1, r0
	beq _0811842E
	subs r0, r1, 0x1
_0811842C:
	strh r0, [r2]
_0811842E:
	ldr r2, =gUnknown_02022E26
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08118442
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_08118442:
	mov r5, r12
	adds r0, r5, r4
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0811845A
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_0811845A:
	movs r3, 0
	ldr r5, =gUnknown_02039B28
	mov r9, r5
	ldr r7, =gUnknown_02038C28
	mov r6, r9
	adds r5, r1, 0
_08118466:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r5, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118466
	cmp r3, 0x9F
	bgt _081184AA
	ldr r7, =gUnknown_02038C28
	ldr r6, =gUnknown_02039B28
	ldr r1, =gTasks
	mov r2, r12
	adds r0, r2, r4
	lsls r0, 3
	adds r5, r0, r1
_08118490:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r5, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118490
_081184AA:
	mov r3, r12
	adds r0, r3, r4
	lsls r0, 3
	mov r5, r8
	adds r1, r0, r5
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	cmp r2, 0
	bne _0811852A
	movs r0, 0x3
	mov r3, r9
	strb r0, [r3, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _0811852A
	.pool
_08118524:
	adds r0, r4, 0
	bl sub_811828C
_0811852A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task_battle_intro_80BC47C

	thumb_func_start task00_battle_intro_80BC6C8
task00_battle_intro_80BC6C8: @ 8118538
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x3
	beq _08118578
	cmp r0, 0x3
	bgt _08118568
	cmp r0, 0x2
	beq _0811856C
	b _08118580
	.pool
_08118568:
	cmp r0, 0x4
	bne _08118580
_0811856C:
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r1]
	adds r0, 0x8
	b _0811857E
	.pool
_08118578:
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r1]
	adds r0, 0x6
_0811857E:
	strh r0, [r1]
_08118580:
	lsls r0, r5, 2
	adds r1, r0, r5
	lsls r1, 3
	adds r4, r1, r2
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	adds r6, r0, 0
	cmp r1, 0x4
	bne _081185E4
	ldr r7, =gUnknown_02022E1A
	ldrh r0, [r4, 0x14]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081185A6
	ldr r1, =0x000001ff
	adds r0, r1
_081185A6:
	asrs r0, 9
	subs r0, 0x8
	strh r0, [r7]
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0xB3
	bgt _081185C8
	adds r0, r1, 0x4
	b _081185CA
	.pool
_081185C8:
	adds r0, r1, 0x6
_081185CA:
	strh r0, [r4, 0x14]
	ldr r2, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r3, r0, r2
	movs r0, 0x14
	ldrsh r1, [r3, r0]
	movs r0, 0xB4
	lsls r0, 1
	cmp r1, r0
	bne _081185E4
	movs r0, 0
	strh r0, [r3, 0x14]
_081185E4:
	adds r0, r6, r5
	lsls r0, 3
	adds r0, r2
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bls _081185F4
	b _0811881A
_081185F4:
	lsls r0, 2
	ldr r1, =_08118608
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118608:
	.4byte _0811861C
	.4byte _0811864C
	.4byte _08118678
	.4byte _081186C8
	.4byte _08118814
_0811861C:
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x10
	strh r3, [r2, 0x10]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08118640
	strh r3, [r2, 0xC]
	b _08118644
	.pool
_08118640:
	movs r0, 0x1
	strh r0, [r2, 0xC]
_08118644:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _0811881A
_0811864C:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118662
	b _0811881A
_08118662:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _0811881A
	.pool
_08118678:
	ldr r1, =gUnknown_02022E26
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118690
	b _0811881A
_08118690:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	movs r0, 0x1
	strh r0, [r1, 0x12]
	ldr r2, =gUnknown_020243FC
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _0811881A
	.pool
_081186C8:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118708
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08118728
	ldr r1, =0x00001842
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0xF
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	b _08118728
	.pool
_08118708:
	ldrh r2, [r1, 0x10]
	movs r0, 0x1F
	ands r0, r2
	cmp r0, 0
	beq _08118728
	ldrh r0, [r1, 0x12]
	subs r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	cmp r0, 0
	bne _08118728
	adds r0, r2, 0
	adds r0, 0xFF
	strh r0, [r1, 0x10]
	movs r0, 0x4
	strh r0, [r1, 0x12]
_08118728:
	ldr r2, =gUnknown_02022E26
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0811873C
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_0811873C:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118752
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_08118752:
	movs r3, 0
	ldr r0, =gUnknown_02039B28
	mov r8, r0
	ldr r2, =gUnknown_02038C28
	mov r12, r2
	mov r7, r8
	adds r4, r1, 0
_08118760:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r12
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118760
	cmp r3, 0x9F
	bgt _081187A4
	ldr r0, =gUnknown_02038C28
	mov r12, r0
	ldr r7, =gUnknown_02039B28
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r4, r0, r1
_0811878A:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r12
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _0811878A
_081187A4:
	ldr r1, =gTasks
	adds r0, r6, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0xC
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _0811881A
	movs r0, 0x3
	mov r3, r8
	strb r0, [r3, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _0811881A
	.pool
_08118814:
	adds r0, r5, 0
	bl sub_811828C
_0811881A:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08118832
	ldrh r1, [r1, 0x10]
	movs r0, 0x52
	bl SetGpuReg
_08118832:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_battle_intro_80BC6C8

	thumb_func_start task_battle_intro_anim
task_battle_intro_anim: @ 8118844
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r1]
	adds r0, 0x8
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0811886E
	b _08118A96
_0811886E:
	lsls r0, 2
	ldr r1, =_08118884
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118884:
	.4byte _08118898
	.4byte _081188F0
	.4byte _0811891C
	.4byte _0811896C
	.4byte _08118A90
_08118898:
	ldr r1, =0x00001842
	movs r0, 0x50
	bl SetGpuReg
	ldr r4, =0x00000808
	movs r0, 0x52
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	strh r4, [r2, 0x10]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _081188E4
	movs r0, 0x10
	b _081188E6
	.pool
_081188E4:
	movs r0, 0x1
_081188E6:
	strh r0, [r2, 0xC]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _08118A96
_081188F0:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118908
	b _08118A96
_08118908:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	b _08118A96
	.pool
_0811891C:
	ldr r1, =gUnknown_02022E26
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118934
	b _08118A96
_08118934:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	movs r0, 0x1
	strh r0, [r1, 0x12]
	ldr r2, =gUnknown_020243FC
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118A96
	.pool
_0811896C:
	lsls r0, r5, 2
	adds r1, r0, r5
	lsls r1, 3
	adds r2, r1, r4
	ldrh r3, [r2, 0xE]
	movs r6, 0xE
	ldrsh r1, [r2, r6]
	mov r12, r0
	cmp r1, 0
	beq _08118986
	subs r0, r3, 0x1
	strh r0, [r2, 0xE]
	b _081189A6
_08118986:
	ldrh r1, [r2, 0x10]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _081189A6
	ldrh r0, [r2, 0x12]
	subs r0, 0x1
	strh r0, [r2, 0x12]
	lsls r0, 16
	cmp r0, 0
	bne _081189A6
	adds r0, r1, 0
	adds r0, 0xFF
	strh r0, [r2, 0x10]
	movs r0, 0x6
	strh r0, [r2, 0x12]
_081189A6:
	ldr r2, =gUnknown_02022E26
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _081189BA
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_081189BA:
	mov r6, r12
	adds r0, r6, r5
	lsls r0, 3
	adds r1, r0, r4
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _081189D0
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_081189D0:
	movs r3, 0
	ldr r6, =gUnknown_02039B28
	mov r8, r6
	ldr r7, =gUnknown_02038C28
	adds r4, r1, 0
_081189DA:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _081189DA
	cmp r3, 0x9F
	bgt _08118A1E
	ldr r7, =gUnknown_02038C28
	ldr r6, =gUnknown_02039B28
	ldr r1, =gTasks
	mov r2, r12
	adds r0, r2, r5
	lsls r0, 3
	adds r4, r0, r1
_08118A04:
	lsls r2, r3, 1
	ldrb r1, [r6, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118A04
_08118A1E:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0xC
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _08118A96
	movs r0, 0x3
	mov r6, r8
	strb r0, [r6, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	str r2, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _08118A96
	.pool
_08118A90:
	adds r0, r5, 0
	bl sub_811828C
_08118A96:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08118AB0
	ldrh r1, [r1, 0x10]
	movs r0, 0x52
	bl SetGpuReg
_08118AB0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_battle_intro_anim

	thumb_func_start task00_battle_intro_wireless
task00_battle_intro_wireless: @ 8118AC0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	ble _08118B36
	movs r2, 0x10
	ldrsh r0, [r7, r2]
	cmp r0, 0
	bne _08118B36
	ldr r2, =gUnknown_02022E18
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _08118AFE
	cmp r1, 0x4F
	bhi _08118B18
_08118AFE:
	adds r0, r1, 0x3
	strh r0, [r2]
	ldr r1, =gUnknown_02022E1C
	ldrh r0, [r1]
	subs r0, 0x3
	strh r0, [r1]
	b _08118B36
	.pool
_08118B18:
	str r5, [sp]
	ldr r1, =0x0600e000
	ldr r4, =0x05000200
	mov r0, sp
	adds r2, r4, 0
	bl CpuSet
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	ldr r1, =0x0600f000
	adds r2, r4, 0
	bl CpuSet
	movs r0, 0x1
	strh r0, [r7, 0x10]
_08118B36:
	ldr r0, =gTasks
	lsls r2, r6, 2
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r1, [r1, r3]
	mov r9, r0
	adds r5, r2, 0
	cmp r1, 0x4
	bls _08118B4E
	b _08118D5A
_08118B4E:
	lsls r0, r1, 2
	ldr r1, =_08118B6C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118B6C:
	.4byte _08118B80
	.4byte _08118B92
	.4byte _08118C38
	.4byte _08118C7C
	.4byte _08118D54
_08118B80:
	adds r0, r5, r6
	lsls r0, 3
	add r0, r9
	movs r1, 0x20
	strh r1, [r0, 0xC]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _08118D5A
_08118B92:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118BA8
	b _08118D5A
_08118BA8:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r4, =gSprites
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x7D
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r3, 0x8
	mov r9, r3
	mov r3, r9
	orrs r0, r3
	strb r0, [r1, 0x1]
	ldr r3, [r5]
	adds r0, r3, 0
	adds r0, 0x7D
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	movs r1, 0x1C
	adds r1, r4
	mov r8, r1
	add r0, r8
	ldr r6, =sub_8038B74
	str r6, [r0]
	adds r3, 0x7E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	ands r2, r1
	mov r3, r9
	orrs r2, r3
	strb r2, [r0, 0x1]
	ldr r0, [r5]
	adds r0, 0x7E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r6, [r0]
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	ldr r1, =0x00003f06
	movs r0, 0x4A
	bl SetGpuReg
	b _08118D5A
	.pool
_08118C38:
	ldr r1, =gUnknown_02022E26
	ldrh r0, [r1]
	subs r0, 0xFF
	strh r0, [r1]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 6
	cmp r0, r1
	beq _08118C50
	b _08118D5A
_08118C50:
	adds r1, r5, r6
	lsls r1, 3
	add r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	movs r0, 0x20
	strh r0, [r1, 0xE]
	ldr r2, =gUnknown_020243FC
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118D5A
	.pool
_08118C7C:
	ldr r2, =gUnknown_02022E26
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08118C90
	ldr r3, =0xfffffc04
	adds r0, r1, r3
	strh r0, [r2]
_08118C90:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08118CA6
	subs r0, r2, 0x2
	strh r0, [r1, 0xC]
_08118CA6:
	movs r3, 0
	ldr r0, =gUnknown_02039B28
	mov r12, r0
	ldr r2, =gUnknown_02038C28
	mov r8, r2
	mov r7, r12
	adds r4, r1, 0
_08118CB4:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r8
	ldrh r0, [r4, 0xC]
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x4F
	ble _08118CB4
	cmp r3, 0x9F
	bgt _08118CF8
	ldr r0, =gUnknown_02038C28
	mov r8, r0
	ldr r7, =gUnknown_02039B28
	ldr r1, =gTasks
	adds r0, r5, r6
	lsls r0, 3
	adds r4, r0, r1
_08118CDE:
	lsls r2, r3, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	add r2, r8
	ldrh r0, [r4, 0xC]
	negs r0, r0
	strh r0, [r2]
	adds r3, 0x1
	cmp r3, 0x9F
	ble _08118CDE
_08118CF8:
	adds r0, r5, r6
	lsls r0, 3
	mov r2, r9
	adds r1, r0, r2
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08118D5A
	movs r0, 0x3
	mov r2, r12
	strb r0, [r2, 0x15]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	b _08118D5A
	.pool
_08118D54:
	adds r0, r6, 0
	bl sub_811828C
_08118D5A:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end task00_battle_intro_wireless

	thumb_func_start sub_8118D68
sub_8118D68: @ 8118D68
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r6, r1, 0
	cmp r0, 0x5
	bls _08118D86
	b _08118FB2
_08118D86:
	lsls r0, 2
	ldr r1, =_08118D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08118D98:
	.4byte _08118DB0
	.4byte _08118DBE
	.4byte _08118E4C
	.4byte _08118EA8
	.4byte _08118F00
	.4byte _08118FAC
_08118DB0:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	movs r1, 0x1
	strh r1, [r0, 0xC]
	b _08118F84
_08118DBE:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r6
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	cmp r0, 0
	beq _08118DD4
	b _08118FB2
_08118DD4:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r1, =0x00005c0a
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00005e0a
	movs r0, 0xC
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	ldr r2, =0x0000f040
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r1, 0xF8
	lsls r1, 6
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	ldr r1, =gUnknown_02022E16
	ldr r2, =0x0000ffd0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E18
	movs r0, 0xF0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1C
	subs r2, 0xC0
	adds r0, r2, 0
	strh r0, [r1]
	b _08118FB2
	.pool
_08118E4C:
	ldr r2, =gUnknown_02022E26
	ldrh r3, [r2]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	adds r1, r3, r0
	strh r1, [r2]
	movs r5, 0xFF
	lsls r5, 8
	ands r1, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	beq _08118E6E
	adds r0, r3, 0
	adds r0, 0xFF
	strh r0, [r2]
_08118E6E:
	ldrh r0, [r2]
	adds r1, r5, 0
	ands r1, r0
	movs r0, 0x80
	lsls r0, 6
	cmp r1, r0
	beq _08118E7E
	b _08118FB2
_08118E7E:
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xF0
	strh r0, [r1, 0xC]
	ldr r2, =gUnknown_020243FC
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	strh r0, [r2]
	b _08118FB2
	.pool
_08118EA8:
	ldr r3, =gUnknown_02022E26
	ldrh r2, [r3]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r2
	movs r1, 0x98
	lsls r1, 7
	cmp r0, r1
	beq _08118EC2
	movs r1, 0xFF
	lsls r1, 2
	adds r0, r2, r1
	strh r0, [r3]
_08118EC2:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r3, r0, r6
	ldrh r1, [r3, 0xC]
	movs r2, 0xC
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08118ED8
	subs r0, r1, 0x2
	strh r0, [r3, 0xC]
_08118ED8:
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r3, 0xC]
	strh r0, [r1]
	ldr r2, =gUnknown_02022E1C
	negs r1, r0
	strh r1, [r2]
	lsls r0, 16
	cmp r0, 0
	bne _08118FB2
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _08118FB2
	.pool
_08118F00:
	ldr r1, =gUnknown_02022E16
	ldrh r0, [r1]
	adds r3, r0, 0x2
	strh r3, [r1]
	ldr r1, =gUnknown_02022E1E
	ldrh r0, [r1]
	adds r0, 0x2
	strh r0, [r1]
	ldr r5, =gUnknown_02022E26
	ldrh r2, [r5]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r2
	movs r1, 0xA0
	lsls r1, 7
	cmp r0, r1
	beq _08118F28
	adds r0, r2, 0
	adds r0, 0xFF
	strh r0, [r5]
_08118F28:
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0
	bne _08118FB2
	str r0, [sp]
	ldr r1, =0x0600e000
	ldr r2, =0x05000800
	mov r0, sp
	bl CpuSet
	movs r0, 0
	bl GetGpuReg
	ldr r1, =0x0000bfff
	ands r1, r0
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r1, 0x9C
	lsls r1, 8
	movs r0, 0xA
	bl SetGpuReg
	movs r1, 0xBC
	lsls r1, 7
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
_08118F84:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _08118FB2
	.pool
_08118FAC:
	adds r0, r4, 0
	bl sub_811828C
_08118FB2:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8118D68

	thumb_func_start sub_8118FBC
sub_8118FBC: @ 8118FBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	adds r6, r2, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x24]
	ldr r7, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	mov r9, r2
	ldr r5, [sp, 0x30]
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleSpritesGfx
	ldr r2, [r1]
	lsls r4, 2
	adds r2, 0x4
	adds r2, r4
	ldr r1, =gBattleMonForms
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 11
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x80
	lsls r2, 3
	adds r1, r7, 0
	bl CpuSet
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 5
	adds r1, r7, 0
	adds r3, r5, 0
	bl LoadBgTiles
	adds r0, r6, 0
	adds r0, 0x8
	cmp r6, r0
	bge _08119068
	mov r12, r0
	mov r2, r8
	lsls r7, r2, 1
_0811903A:
	mov r1, r8
	adds r2, r1, 0
	adds r2, 0x8
	adds r4, r6, 0x1
	cmp r1, r2
	bge _08119062
	mov r0, r10
	lsls r3, r0, 12
	lsls r0, r6, 6
	add r0, r9
	adds r6, r7, r0
	subs r1, r2, r1
_08119052:
	adds r0, r5, 0
	orrs r0, r3
	strh r0, [r6]
	adds r5, 0x1
	adds r6, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _08119052
_08119062:
	adds r6, r4, 0
	cmp r6, r12
	blt _0811903A
_08119068:
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 4
	mov r1, r9
	movs r3, 0
	bl LoadBgTilemap
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8118FBC

	thumb_func_start sub_8119094
sub_8119094: @ 8119094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	mov r8, r5
	ldr r5, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	mov r9, r6
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r1, 24
	lsls r2, 24
	lsls r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	mov r7, r8
	lsls r7, 16
	lsrs r6, r7, 16
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	lsls r0, 24
	mov r9, r0
	ldr r4, =0x040000d4
	ldr r0, =gBattleSpritesGfx
	ldr r0, [r0]
	lsrs r2, 22
	adds r0, 0x4
	adds r0, r2
	lsrs r3, 13
	ldr r0, [r0]
	adds r0, r3
	str r0, [r4]
	movs r0, 0xC0
	lsls r0, 19
	adds r6, r0
	str r6, [r4, 0x4]
	ldr r0, =0x80000400
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	adds r2, r7, 0
	lsrs r2, 21
	mov r6, r9
	lsrs r6, 15
	subs r4, r2, r6
	lsrs r0, r1, 24
	adds r1, r0, 0
	adds r1, 0x8
	cmp r0, r1
	bge _08119148
	mov r9, r1
	mov r7, r12
	lsls r7, 1
	mov r8, r7
	lsls r5, 11
	str r5, [sp]
_08119110:
	mov r2, r12
	adds r3, r2, 0
	adds r3, 0x8
	adds r5, r0, 0x1
	cmp r2, r3
	bge _08119142
	mov r1, r10
	lsls r6, r1, 12
	lsls r0, 6
	movs r7, 0xC0
	lsls r7, 19
	adds r0, r7
	ldr r1, [sp]
	adds r0, r1, r0
	mov r7, r8
	adds r1, r7, r0
	subs r2, r3, r2
_08119132:
	adds r0, r4, 0
	orrs r0, r6
	strh r0, [r1]
	adds r4, 0x1
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _08119132
_08119142:
	adds r0, r5, 0
	cmp r0, r9
	blt _08119110
_08119148:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119094

	.align 2, 0 @ Don't pad with nop.
