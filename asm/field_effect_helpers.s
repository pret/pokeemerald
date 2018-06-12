	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetUpReflection
SetUpReflection: @ 8153ED4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r5, r2, 24
	lsrs r5, 24
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x22
	ldrsh r2, [r4, r0]
	adds r0, r4, 0
	movs r3, 0x98
	bl obj_unfreeze
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r7, r1, r0
	ldr r0, =objc_reflection_maybe
	str r0, [r7, 0x1C]
	ldrb r1, [r7, 0x5]
	movs r0, 0xC
	orrs r1, r0
	strb r1, [r7, 0x5]
	ldr r2, =gUnknown_084975C4
	lsrs r0, r1, 4
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 4
	movs r2, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x5]
	movs r1, 0x3F
	adds r1, r7
	mov r8, r1
	ldrb r0, [r1]
	movs r1, 0x40
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	ldr r0, =gDummySpriteAnimTable
	str r0, [r7, 0x8]
	adds r0, r7, 0
	movs r1, 0
	bl StartSpriteAnim
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [r7, 0x10]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x8
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	adds r2, r7, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	strh r0, [r7, 0x2E]
	ldrb r0, [r6, 0x8]
	strh r0, [r7, 0x30]
	strh r5, [r7, 0x3C]
	adds r0, r6, 0
	adds r1, r7, 0
	bl npc_pal_op
	cmp r5, 0
	bne _08153F7A
	ldrb r0, [r7, 0x1]
	movs r1, 0x4
	negs r1, r1
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strb r1, [r7, 0x1]
_08153F7A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpReflection

	thumb_func_start sub_8153F98
sub_8153F98: @ 8153F98
	push {lr}
	ldrb r0, [r0, 0x5]
	bl GetEventObjectGraphicsInfo
	ldrh r0, [r0, 0xA]
	subs r0, 0x2
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8153F98

	thumb_func_start npc_pal_op
@ void npc_pal_op(struct npc_state *npcState, struct obj *obj)
npc_pal_op: @ 8153FAC
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_085CDC38
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrb r0, [r5, 0x5]
	bl GetEventObjectGraphicsInfo
	ldrb r1, [r0, 0xC]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08154008
	ldrb r0, [r5, 0x1F]
	bl MetatileBehavior_GetBridgeSth
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08153FEE
	ldrb r0, [r5, 0x1E]
	bl MetatileBehavior_GetBridgeSth
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08154008
_08153FEE:
	subs r0, 0x1
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x32]
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	adds r0, r5, 0
	bl npc_pal_op_A
	b _08154012
	.pool
_08154008:
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	adds r0, r5, 0
	bl npc_pal_op_B
_08154012:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end npc_pal_op

	thumb_func_start npc_pal_op_B
@ void npc_pal_op_B(void *a1, u8 slot)
npc_pal_op_B: @ 815401C
	push {r4,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldrb r0, [r0, 0x5]
	bl GetEventObjectGraphicsInfo
	adds r2, r0, 0
	ldrh r1, [r2, 0x4]
	ldr r0, =0x000011ff
	cmp r1, r0
	beq _08154070
	ldrb r0, [r2, 0xC]
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0
	bne _0815404C
	ldrh r0, [r2, 0x2]
	adds r1, r4, 0
	bl npc_load_two_palettes__no_record
	b _0815406A
	.pool
_0815404C:
	cmp r1, 0xA
	bne _0815405A
	ldrh r0, [r2, 0x2]
	adds r1, r4, 0
	bl npc_load_two_palettes__and_record
	b _0815406A
_0815405A:
	adds r0, r4, 0
	bl npc_paltag_by_palslot
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl pal_patch_for_npc
_0815406A:
	adds r0, r4, 0
	bl UpdateSpritePaletteWithWeather
_08154070:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end npc_pal_op_B

	thumb_func_start npc_pal_op_A
npc_pal_op_A: @ 8154078
	push {r4,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldrb r0, [r0, 0x5]
	bl GetEventObjectGraphicsInfo
	adds r2, r0, 0
	ldrh r1, [r2, 0x4]
	ldr r0, =0x000011ff
	cmp r1, r0
	beq _0815409C
	adds r0, r1, 0
	adds r1, r4, 0
	bl pal_patch_for_npc
	adds r0, r4, 0
	bl UpdateSpritePaletteWithWeather
_0815409C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end npc_pal_op_A

	thumb_func_start objc_reflection_maybe
@ void objc_reflection_maybe(struct obj *object)
objc_reflection_maybe: @ 81540A8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r7, r0, r1
	ldrb r1, [r7, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	ldr r0, [r7]
	ldr r1, =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _081540E0
	ldrb r1, [r7, 0x8]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _081540FC
_081540E0:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _08154214
	.pool
_081540FC:
	ldr r1, =gUnknown_084975C4
	ldrb r0, [r5, 0x5]
	lsrs r0, 4
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 4
	ldrb r2, [r4, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldrb r1, [r5, 0x1]
	lsrs r1, 6
	lsls r1, 6
	ldrb r2, [r4, 0x1]
	movs r3, 0x3F
	adds r0, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r5, 0x3]
	lsrs r0, 6
	lsls r0, 6
	ldrb r2, [r4, 0x3]
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x3]
	ldrb r0, [r5, 0x3]
	lsls r0, 26
	lsrs r0, 27
	movs r2, 0x10
	orrs r0, r2
	lsls r0, 1
	subs r2, 0x4F
	mov r9, r2
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x3]
	ldrh r1, [r5, 0x4]
	lsls r1, 22
	lsrs r1, 22
	ldrh r2, [r4, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r0, [r5, 0x18]
	str r0, [r4, 0x18]
	adds r0, r5, 0
	adds r0, 0x42
	ldrb r0, [r0]
	lsls r0, 26
	lsrs r0, 26
	adds r2, r4, 0
	adds r2, 0x42
	ands r3, r0
	ldrb r1, [r2]
	movs r0, 0x40
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	movs r0, 0x3E
	adds r0, r5
	mov r8, r0
	ldrb r0, [r0]
	adds r6, r4, 0
	adds r6, 0x3E
	movs r1, 0x4
	ands r1, r0
	ldrb r2, [r6]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	ldrh r0, [r5, 0x20]
	strh r0, [r4, 0x20]
	adds r0, r7, 0
	bl sub_8153F98
	ldrh r1, [r5, 0x22]
	adds r0, r1
	ldrh r1, [r4, 0x32]
	adds r1, r0
	strh r1, [r4, 0x22]
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x28
	strb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x29
	strb r0, [r1]
	ldrh r0, [r5, 0x24]
	strh r0, [r4, 0x24]
	ldrh r0, [r5, 0x26]
	negs r0, r0
	strh r0, [r4, 0x26]
	mov r2, r8
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	ldrb r1, [r6]
	movs r2, 0x3
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r6]
	ldrb r0, [r7, 0x3]
	lsls r0, 28
	cmp r0, 0
	bge _081541EE
	movs r0, 0x4
	orrs r2, r0
	strb r2, [r6]
_081541EE:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08154214
	ldrb r0, [r4, 0x3]
	mov r2, r9
	ands r2, r0
	strb r2, [r4, 0x3]
	ldrb r0, [r5, 0x3]
	lsls r0, 26
	lsrs r0, 27
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08154214
	movs r1, 0x2
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r4, 0x3]
_08154214:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end objc_reflection_maybe

	thumb_func_start sub_8154228
sub_8154228: @ 8154228
	push {r4,lr}
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x20]
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r0, 0x40
	beq _08154266
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1, 0x5]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	orrs r0, r3
	strb r0, [r1]
_08154266:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154228

	thumb_func_start objid_set_invisible
objid_set_invisible: @ 8154278
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
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end objid_set_invisible

	thumb_func_start sub_8154298
sub_8154298: @ 8154298
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081542E2
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	lsls r0, r7, 16
	asrs r0, 16
	cmp r1, r0
	bne _081542E2
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	lsls r0, r6, 16
	asrs r0, 16
	cmp r1, r0
	beq _0815432E
_081542E2:
	lsls r0, r7, 16
	asrs r0, 16
	lsls r1, r6, 16
	asrs r1, 16
	mov r4, sp
	adds r4, 0x2
	mov r2, sp
	adds r3, r4, 0
	bl sub_8093038
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	mov r0, sp
	ldrh r0, [r0]
	adds r0, 0x8
	strh r0, [r2, 0x20]
	ldrh r0, [r4]
	adds r0, 0x8
	strh r0, [r2, 0x22]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	strh r7, [r2, 0x2E]
	strh r6, [r2, 0x30]
	mov r1, r8
	subs r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl StartSpriteAnim
_0815432E:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8154298

	thumb_func_start oei_shadow
oei_shadow: @ 8154340
	push {r4,r5,lr}
	ldr r5, =gFieldEffectArguments
	ldrb r0, [r5]
	ldrb r1, [r5, 0x4]
	ldrb r2, [r5, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gEventObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x5]
	bl GetEventObjectGraphicsInfo
	adds r4, r0, 0
	ldr r2, =gFieldEffectObjectTemplatePointers
	ldr r1, =gUnknown_085CDC3E
	ldrb r0, [r4, 0xC]
	lsls r0, 26
	lsrs r0, 30
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	movs r3, 0x94
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081543C4
	ldr r0, =gSprites
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r5]
	strh r0, [r2, 0x2E]
	ldr r0, [r5, 0x4]
	strh r0, [r2, 0x30]
	ldr r0, [r5, 0x8]
	strh r0, [r2, 0x32]
	ldrh r1, [r4, 0xA]
	lsls r1, 16
	asrs r1, 17
	ldr r3, =gUnknown_085CDC42
	ldrb r0, [r4, 0xC]
	lsls r0, 26
	lsrs r0, 30
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	subs r1, r0
	strh r1, [r2, 0x34]
_081543C4:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_shadow

	thumb_func_start oamc_shadow
oamc_shadow: @ 81543E4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r5, 0x32]
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	beq _08154412
	adds r0, r5, 0
	movs r1, 0x3
	bl FieldEffectStop
	b _08154498
_08154412:
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrb r0, [r1, 0x5]
	movs r2, 0xC
	ands r2, r0
	ldrb r3, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r5, 0x5]
	ldrh r0, [r1, 0x20]
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x34]
	ldrh r1, [r1, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldr r0, [r4]
	ldr r1, =0x00400001
	ands r0, r1
	cmp r0, r1
	bne _08154490
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	cmp r0, 0
	bne _08154490
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _08154490
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsSurfableWaterOrUnderwater
	lsls r0, 24
	cmp r0, 0
	bne _08154490
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsReflective
	lsls r0, 24
	cmp r0, 0
	bne _08154490
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsReflective
	lsls r0, 24
	cmp r0, 0
	beq _08154498
_08154490:
	adds r0, r5, 0
	movs r1, 0x3
	bl FieldEffectStop
_08154498:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end oamc_shadow

	thumb_func_start oei_grass_normal
oei_grass_normal: @ 81544AC
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gFieldEffectArguments
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x10]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _08154538
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x3
	ldrb r1, [r5, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r0, [r5, 0x8]
	strh r0, [r3, 0x2E]
	ldr r0, [r5]
	strh r0, [r3, 0x30]
	ldr r0, [r5, 0x4]
	strh r0, [r3, 0x32]
	ldr r0, [r5, 0x10]
	strh r0, [r3, 0x34]
	ldr r0, [r5, 0x14]
	strh r0, [r3, 0x36]
	ldr r0, [r5, 0x18]
	strh r0, [r3, 0x38]
	ldr r0, [r5, 0x1C]
	cmp r0, 0
	beq _08154538
	adds r0, r3, 0
	movs r1, 0x4
	bl SeekSpriteAnim
_08154538:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_grass_normal

	thumb_func_start unc_grass_normal
unc_grass_normal: @ 8154550
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r0, [r5, 0x38]
	lsrs r4, r0, 8
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, =gCamera
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815459C
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, r4
	bne _08154582
	movs r0, 0x4
	ldrsb r0, [r2, r0]
	cmp r0, r7
	beq _0815459C
_08154582:
	ldr r1, [r3, 0x4]
	ldrh r0, [r5, 0x30]
	subs r0, r1
	strh r0, [r5, 0x30]
	ldr r1, [r3, 0x8]
	ldrh r0, [r5, 0x32]
	subs r0, r1
	strh r0, [r5, 0x32]
	ldrb r1, [r2, 0x5]
	lsls r1, 8
	ldrb r0, [r2, 0x4]
	orrs r0, r1
	strh r0, [r5, 0x38]
_0815459C:
	ldrh r0, [r5, 0x34]
	lsrs r1, r0, 8
	mov r8, r1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5, 0x36]
	lsls r0, 24
	lsrs r7, r0, 24
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r6, r0, 24
	mov r0, r8
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _081545F0
	adds r0, r6, 0
	bl MetatileBehavior_IsTallGrass
	lsls r0, 24
	cmp r0, 0
	beq _081545F0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08154604
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08154604
_081545F0:
	adds r0, r5, 0
	movs r1, 0x4
	bl FieldEffectStop
	b _08154648
	.pool
_08154604:
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r2, r0, r1
	ldr r0, [r2, 0x10]
	ldr r1, [r5, 0x30]
	cmp r0, r1
	beq _08154624
	ldr r0, [r2, 0x14]
	cmp r0, r1
	beq _08154624
	movs r0, 0x1
	strh r0, [r5, 0x3C]
_08154624:
	movs r6, 0
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	bne _08154632
	movs r6, 0x4
_08154632:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80979D4
	ldrh r1, [r5, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_81561FC
_08154648:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_grass_normal

	thumb_func_start sub_8154658
sub_8154658: @ 8154658
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0xC
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x28]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081546B4
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r2, 0x2E]
	movs r0, 0xC
	strh r0, [r2, 0x30]
_081546B4:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154658

	thumb_func_start sub_81546C8
sub_81546C8: @ 81546C8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r5, 0
	ldr r0, =gSprites
	mov r8, r0
	lsls r3, 16
	asrs r3, 16
	lsls r4, 16
	asrs r4, 16
_081546EC:
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	mov r1, r8
	adds r2, r0, r1
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _08154740
	ldr r1, [r2, 0x1C]
	ldr r0, =unc_grass_normal
	cmp r1, r0
	bne _08154740
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bne _08154740
	movs r1, 0x32
	ldrsh r0, [r2, r1]
	cmp r4, r0
	bne _08154740
	ldrh r1, [r2, 0x34]
	lsrs r0, r1, 8
	cmp r12, r0
	bne _08154740
	movs r0, 0xFF
	ands r0, r1
	cmp r7, r0
	bne _08154740
	movs r1, 0x36
	ldrsh r0, [r2, r1]
	cmp r6, r0
	bne _08154740
	adds r0, r5, 0
	b _0815474C
	.pool
_08154740:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3F
	bls _081546EC
	movs r0, 0x40
_0815474C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81546C8

	thumb_func_start sub_8154758
sub_8154758: @ 8154758
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gFieldEffectArguments
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x3C]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081547E8
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, 0x8]
	bl ZCoordToPriority
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldr r0, [r5, 0x8]
	strh r0, [r4, 0x2E]
	ldr r0, [r5]
	strh r0, [r4, 0x30]
	ldr r0, [r5, 0x4]
	strh r0, [r4, 0x32]
	ldr r0, [r5, 0x10]
	strh r0, [r4, 0x34]
	ldr r0, [r5, 0x14]
	strh r0, [r4, 0x36]
	ldr r0, [r5, 0x18]
	strh r0, [r4, 0x38]
	ldr r0, [r5, 0x1C]
	cmp r0, 0
	beq _081547E8
	adds r0, r4, 0
	movs r1, 0x6
	bl SeekSpriteAnim
_081547E8:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154758

	thumb_func_start unc_grass_tall
unc_grass_tall: @ 8154800
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r0, [r5, 0x38]
	lsrs r7, r0, 8
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gCamera
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815484C
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, r7
	bne _08154832
	movs r0, 0x4
	ldrsb r0, [r2, r0]
	cmp r0, r6
	beq _0815484C
_08154832:
	ldr r1, [r3, 0x4]
	ldrh r0, [r5, 0x30]
	subs r0, r1
	strh r0, [r5, 0x30]
	ldr r1, [r3, 0x8]
	ldrh r0, [r5, 0x32]
	subs r0, r1
	strh r0, [r5, 0x32]
	ldrb r1, [r2, 0x5]
	lsls r1, 8
	ldrb r0, [r2, 0x4]
	orrs r0, r1
	strh r0, [r5, 0x38]
_0815484C:
	ldrh r0, [r5, 0x34]
	lsrs r1, r0, 8
	mov r8, r1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r5, 0x36]
	lsls r0, 24
	lsrs r6, r0, 24
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	mov r0, r8
	adds r1, r7, 0
	adds r2, r6, 0
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _081548A0
	adds r0, r4, 0
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _081548A0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _081548B4
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081548B4
_081548A0:
	adds r0, r5, 0
	movs r1, 0x11
	bl FieldEffectStop
	b _081548EA
	.pool
_081548B4:
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r2, r0, r1
	ldr r0, [r2, 0x10]
	ldr r1, [r5, 0x30]
	cmp r0, r1
	beq _081548D4
	ldr r0, [r2, 0x14]
	cmp r0, r1
	beq _081548D4
	movs r0, 0x1
	strh r0, [r5, 0x3C]
_081548D4:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80979D4
	ldrh r1, [r5, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	movs r2, 0
	bl sub_81561FC
_081548EA:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_grass_tall

	thumb_func_start sub_81548FC
sub_81548FC: @ 81548FC
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x40]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08154958
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r2, 0x2E]
	movs r0, 0x12
	strh r0, [r2, 0x30]
_08154958:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81548FC

	thumb_func_start sub_815496C
sub_815496C: @ 815496C
	push {r4-r6,lr}
	ldr r6, =gFieldEffectArguments
	ldrb r0, [r6]
	ldrb r1, [r6, 0x4]
	ldrb r2, [r6, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x78]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081549F8
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, =gSprites
	adds r2, r4
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x5]
	movs r1, 0xC
	ands r1, r0
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r6]
	strh r0, [r2, 0x2E]
	ldr r0, [r6, 0x4]
	strh r0, [r2, 0x30]
	ldr r0, [r6, 0x8]
	strh r0, [r2, 0x32]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x20]
	strh r0, [r2, 0x34]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x22]
	strh r0, [r2, 0x36]
_081549F8:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815496C

	thumb_func_start sub_8154A10
sub_8154A10: @ 8154A10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
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
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08154A4E
	ldr r5, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x2]
	lsls r0, 29
	cmp r0, 0
	blt _08154A5C
_08154A4E:
	adds r0, r4, 0
	movs r1, 0x29
	bl FieldEffectStop
	b _08154AF2
	.pool
_08154A5C:
	ldrb r0, [r1, 0x5]
	bl GetEventObjectGraphicsInfo
	mov r8, r0
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r6, r0, r1
	ldrh r5, [r6, 0x22]
	ldrh r7, [r6, 0x20]
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08154A98
	lsls r0, r5, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	cmp r0, r1
	beq _08154AB2
_08154A98:
	strh r7, [r4, 0x34]
	strh r5, [r4, 0x36]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08154AB2
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
_08154AB2:
	strh r7, [r4, 0x20]
	strh r5, [r4, 0x22]
	mov r1, r8
	ldrh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 17
	subs r0, 0x8
	strh r0, [r4, 0x26]
	adds r0, r6, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrb r0, [r6, 0x5]
	movs r1, 0xC
	ands r1, r0
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r0, r6, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	adds r0, r4, 0
	bl sub_80979D4
_08154AF2:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8154A10

	thumb_func_start sub_8154B04
sub_8154B04: @ 8154B04
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x2C]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _08154B62
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	movs r1, 0x3
	ldrb r2, [r4, 0xC]
	ands r2, r1
	lsls r2, 2
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0xD
	strh r1, [r0, 0x3C]
	ldrb r1, [r4, 0x10]
	bl StartSpriteAnim
_08154B62:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154B04

	thumb_func_start sub_8154B78
sub_8154B78: @ 8154B78
	push {r4,r5,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x5C]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	adds r5, r1, 0
	cmp r1, 0x40
	beq _08154BD8
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	movs r1, 0x3
	ldrb r2, [r4, 0xC]
	ands r2, r1
	lsls r2, 2
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x18
	strh r1, [r0, 0x3C]
	ldrb r1, [r4, 0x10]
	bl StartSpriteAnim
_08154BD8:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154B78

	thumb_func_start sub_8154BEC
sub_8154BEC: @ 8154BEC
	push {r4,r5,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x6C]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	adds r5, r1, 0
	cmp r1, 0x40
	beq _08154C4C
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	movs r1, 0x3
	ldrb r2, [r4, 0xC]
	ands r2, r1
	lsls r2, 2
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x23
	strh r1, [r0, 0x3C]
	ldrb r1, [r4, 0x10]
	bl StartSpriteAnim
_08154C4C:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154BEC

	thumb_func_start sub_8154C60
sub_8154C60: @ 8154C60
	push {lr}
	ldr r2, =gUnknown_085CDC4C
	movs r3, 0x2E
	ldrsh r1, [r0, r3]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8154C60

	thumb_func_start sub_8154C7C
sub_8154C7C: @ 8154C7C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _08154C92
	movs r0, 0x1
	strh r0, [r1, 0x2E]
_08154C92:
	adds r0, r1, 0
	movs r1, 0
	bl sub_80979D4
	pop {r0}
	bx r0
	thumb_func_end sub_8154C7C

	thumb_func_start sub_8154CA0
sub_8154CA0: @ 8154CA0
	push {r4,lr}
	adds r4, r0, 0
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
	ldrb r1, [r3]
	lsls r1, 29
	lsrs r1, 31
	adds r0, r4, 0
	bl sub_80979D4
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x38
	ble _08154CE4
	ldrh r1, [r4, 0x3C]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldEffectStop
_08154CE4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8154CA0

	thumb_func_start sub_8154CEC
sub_8154CEC: @ 8154CEC
	push {r4-r6,lr}
	ldr r6, =gFieldEffectArguments
	ldrb r0, [r6]
	ldrb r1, [r6, 0x4]
	ldrb r2, [r6, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x34]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	beq _08154D76
	ldrb r0, [r5, 0x5]
	bl GetEventObjectGraphicsInfo
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	ldr r4, =gSprites
	adds r3, r4
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r1, [r1]
	movs r2, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	ldrb r2, [r5, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r4, [r3, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r4
	orrs r1, r2
	strb r1, [r3, 0x5]
	ldr r1, [r6]
	strh r1, [r3, 0x2E]
	ldr r1, [r6, 0x4]
	strh r1, [r3, 0x30]
	ldr r1, [r6, 0x8]
	strh r1, [r3, 0x32]
	ldrh r0, [r0, 0xA]
	lsls r0, 16
	asrs r0, 17
	subs r0, 0x4
	strh r0, [r3, 0x26]
	movs r0, 0x46
	bl PlaySE
_08154D76:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154CEC

	thumb_func_start sub_8154D90
sub_8154D90: @ 8154D90
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08154DC0
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
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	beq _08154DCA
_08154DC0:
	adds r0, r4, 0
	movs r1, 0xF
	bl FieldEffectStop
	b _08154E0A
_08154DCA:
	ldr r3, =gSprites
	ldr r2, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x20]
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
_08154E0A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8154D90

	thumb_func_start sub_8154E1C
sub_8154E1C: @ 8154E1C
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0xC
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x38]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08154E78
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r2, 0x2E]
	movs r0, 0x10
	strh r0, [r2, 0x30]
_08154E78:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154E1C

	thumb_func_start oei_water_drop_tall
oei_water_drop_tall: @ 8154E8C
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x30]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08154EE8
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r2, 0x2E]
	movs r0, 0xE
	strh r0, [r2, 0x30]
_08154EE8:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_water_drop_tall

	thumb_func_start sub_8154EFC
sub_8154EFC: @ 8154EFC
	push {r4-r7,lr}
	ldr r7, =gFieldEffectArguments
	ldrb r0, [r7]
	ldrb r1, [r7, 0x4]
	ldrb r2, [r7, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r6, r1, r0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x34]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _08154F92
	ldrb r0, [r6, 0x5]
	bl GetEventObjectGraphicsInfo
	adds r4, r0, 0
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r3, =gSprites
	adds r0, r3
	ldr r1, =sub_8154FB4
	str r1, [r0, 0x1C]
	adds r5, r0, 0
	adds r5, 0x3E
	ldrb r1, [r5]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r5]
	ldrb r2, [r6, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, [r7]
	strh r1, [r0, 0x2E]
	ldr r1, [r7, 0x4]
	strh r1, [r0, 0x30]
	ldr r1, [r7, 0x8]
	strh r1, [r0, 0x32]
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x34]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x36]
	ldrh r1, [r4, 0xA]
	lsls r1, 16
	asrs r1, 17
	subs r1, 0x4
	strh r1, [r0, 0x26]
	movs r1, 0x1
	bl StartSpriteAnim
_08154F92:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8154EFC

	thumb_func_start sub_8154FB4
sub_8154FB4: @ 8154FB4
	push {r4,r5,lr}
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
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08154FEE
	ldr r2, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r2
	ldrb r0, [r5, 0x2]
	lsls r0, 28
	cmp r0, 0
	blt _08154FFC
_08154FEE:
	adds r0, r4, 0
	movs r1, 0x22
	bl FieldEffectStop
	b _08155046
	.pool
_08154FFC:
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrh r1, [r0, 0x20]
	strh r1, [r4, 0x20]
	ldrh r1, [r0, 0x22]
	strh r1, [r4, 0x22]
	adds r0, 0x43
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
	ldr r1, [r5, 0x10]
	ldr r0, [r4, 0x34]
	cmp r1, r0
	beq _08155046
	ldrh r0, [r5, 0x10]
	strh r0, [r4, 0x34]
	ldrh r0, [r5, 0x12]
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08155046
	movs r0, 0x46
	bl PlaySE
_08155046:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8154FB4

	thumb_func_start oei_ripples
oei_ripples: @ 8155054
	push {r4,lr}
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x14]
	ldr r4, =gFieldEffectArguments
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081550A0
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x5
	strh r0, [r2, 0x2E]
_081550A0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_ripples

	thumb_func_start sub_81550B4
sub_81550B4: @ 81550B4
	push {r4-r6,lr}
	ldr r6, =gFieldEffectArguments
	ldrb r0, [r6]
	ldrb r1, [r6, 0x4]
	ldrb r2, [r6, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x7C]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155140
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, =gSprites
	adds r2, r4
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x5]
	movs r1, 0xC
	ands r1, r0
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r6]
	strh r0, [r2, 0x2E]
	ldr r0, [r6, 0x4]
	strh r0, [r2, 0x30]
	ldr r0, [r6, 0x8]
	strh r0, [r2, 0x32]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x20]
	strh r0, [r2, 0x34]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x22]
	strh r0, [r2, 0x36]
_08155140:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81550B4

	thumb_func_start sub_8155158
sub_8155158: @ 8155158
	push {r4,r5,lr}
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
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08155192
	ldr r5, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x2]
	lsls r0, 26
	cmp r0, 0
	blt _081551A0
_08155192:
	adds r0, r4, 0
	movs r1, 0x2A
	bl FieldEffectStop
	b _081551E4
	.pool
_081551A0:
	ldrb r0, [r1, 0x5]
	bl GetEventObjectGraphicsInfo
	mov r1, sp
	ldrb r2, [r1]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r1, r2
	ldrh r2, [r1, 0x20]
	strh r2, [r4, 0x20]
	ldrh r0, [r0, 0xA]
	lsls r0, 16
	asrs r0, 17
	ldrh r2, [r1, 0x22]
	adds r0, r2
	subs r0, 0x8
	strh r0, [r4, 0x22]
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
_081551E4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155158

	thumb_func_start sub_81551F0
sub_81551F0: @ 81551F0
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x44]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155248
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x13
	strh r0, [r2, 0x2E]
_08155248:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81551F0

	thumb_func_start sub_815525C
sub_815525C: @ 815525C
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x48]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081552B4
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x14
	strh r0, [r2, 0x2E]
_081552B4:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815525C

	thumb_func_start sub_81552C8
sub_81552C8: @ 81552C8
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x4C]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155320
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x15
	strh r0, [r2, 0x2E]
_08155320:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81552C8

	thumb_func_start sub_8155334
sub_8155334: @ 8155334
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x50]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0815538C
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x16
	strh r0, [r2, 0x2E]
_0815538C:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155334

	thumb_func_start ash
ash: @ 81553A0
	push {r4,lr}
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gFieldEffectArguments
	lsls r0, 16
	asrs r0, 16
	str r0, [r4]
	lsls r1, 16
	asrs r1, 16
	str r1, [r4, 0x4]
	movs r0, 0x52
	str r0, [r4, 0x8]
	movs r0, 0x1
	str r0, [r4, 0xC]
	str r2, [r4, 0x10]
	lsls r3, 16
	asrs r3, 16
	str r3, [r4, 0x14]
	movs r0, 0x7
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ash

	thumb_func_start oei_ash
oei_ash: @ 81553D4
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gFieldEffectArguments
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x18]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	ldrb r3, [r5, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0815544A
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r5, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r5]
	strh r0, [r2, 0x30]
	ldr r0, [r5, 0x4]
	strh r0, [r2, 0x32]
	ldr r0, [r5, 0x10]
	strh r0, [r2, 0x34]
	ldr r0, [r5, 0x14]
	strh r0, [r2, 0x36]
_0815544A:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_ash

	thumb_func_start sub_8155460
sub_8155460: @ 8155460
	push {lr}
	ldr r2, =gUnknown_085CDC54
	movs r3, 0x2E
	ldrsh r1, [r0, r3]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155460

	thumb_func_start sub_815547C
sub_815547C: @ 815547C
	push {lr}
	adds r3, r0, 0
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x36]
	subs r0, 0x1
	strh r0, [r3, 0x36]
	lsls r0, 16
	cmp r0, 0
	bne _081554A6
	movs r0, 0x1
	strh r0, [r3, 0x2E]
_081554A6:
	pop {r0}
	bx r0
	thumb_func_end sub_815547C

	thumb_func_start sub_81554AC
sub_81554AC: @ 81554AC
	push {r4,lr}
	adds r4, r0, 0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, 0x34]
	bl MapGridSetMetatileIdAt
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x2
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81554AC

	thumb_func_start sub_815550C
sub_815550C: @ 815550C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80979D4
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815552C
	adds r0, r4, 0
	movs r1, 0x7
	bl FieldEffectStop
_0815552C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815550C

	thumb_func_start sub_8155534
sub_8155534: @ 8155534
	push {r4,r5,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x1C]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0x96
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	cmp r0, 0x40
	beq _0815558E
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r1, 0x32]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x34]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x3A]
	strh r0, [r1, 0x3C]
_0815558E:
	movs r0, 0x8
	bl FieldEffectActiveListRemove
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155534

	thumb_func_start sub_81555AC
sub_81555AC: @ 81555AC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrh r0, [r2, 0x2E]
	movs r3, 0x10
	negs r3, r3
	ands r3, r0
	movs r0, 0xF0
	lsls r0, 20
	ands r0, r1
	lsrs r0, 24
	orrs r0, r3
	strh r0, [r2, 0x2E]
	bx lr
	.pool
	thumb_func_end sub_81555AC

	thumb_func_start sub_81555D8
sub_81555D8: @ 81555D8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrh r0, [r2, 0x2E]
	movs r3, 0xF1
	negs r3, r3
	ands r3, r0
	movs r0, 0xF0
	lsls r0, 20
	ands r0, r1
	lsrs r0, 20
	orrs r3, r0
	strh r3, [r2, 0x2E]
	bx lr
	.pool
	thumb_func_end sub_81555D8

	thumb_func_start sub_8155604
sub_8155604: @ 8155604
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r4, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r4
	ldrh r0, [r3, 0x2E]
	ldr r4, =0xfffff0ff
	ands r4, r0
	movs r0, 0xF0
	lsls r0, 20
	ands r0, r1
	lsrs r0, 16
	orrs r4, r0
	strh r4, [r3, 0x2E]
	strh r2, [r3, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155604

	thumb_func_start sub_8155638
sub_8155638: @ 8155638
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF
	ands r0, r1
	bx lr
	thumb_func_end sub_8155638

	thumb_func_start sub_8155640
sub_8155640: @ 8155640
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF0
	ands r0, r1
	lsrs r0, 4
	bx lr
	thumb_func_end sub_8155640

	thumb_func_start sub_815564C
sub_815564C: @ 815564C
	ldrh r1, [r0, 0x2E]
	movs r0, 0xF0
	lsls r0, 4
	ands r0, r1
	lsrs r0, 8
	bx lr
	thumb_func_end sub_815564C

	thumb_func_start sub_8155658
sub_8155658: @ 8155658
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	ldrb r0, [r4, 0x4]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r0, =gSprites
	adds r5, r0
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_81556B0
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_81556E8
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_815577C
	ldrb r0, [r5, 0x5]
	movs r1, 0xC
	ands r1, r0
	ldrb r2, [r6, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155658

	thumb_func_start sub_81556B0
sub_81556B0: @ 81556B0
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_085CDC60
	mov r0, sp
	movs r2, 0x9
	bl memcpy
	adds r0, r4, 0
	bl sub_8155640
	lsls r0, 24
	cmp r0, 0
	bne _081556DC
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	add r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	bl StartSpriteAnimIfDifferent
_081556DC:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81556B0

	thumb_func_start sub_81556E8
sub_81556E8: @ 81556E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r1, 0
	ldrh r2, [r0, 0x10]
	mov r1, sp
	strh r2, [r1]
	ldrh r1, [r0, 0x12]
	mov r0, sp
	adds r0, 0x2
	strh r1, [r0]
	movs r2, 0x26
	ldrsh r3, [r4, r2]
	mov r8, r0
	cmp r3, 0
	bne _08155770
	mov r0, sp
	movs r5, 0
	ldrsh r2, [r0, r5]
	movs r5, 0x3A
	ldrsh r0, [r4, r5]
	cmp r2, r0
	bne _08155724
	lsls r0, r1, 16
	asrs r0, 16
	movs r5, 0x3C
	ldrsh r1, [r4, r5]
	cmp r0, r1
	beq _08155770
_08155724:
	strh r3, [r4, 0x38]
	strh r2, [r4, 0x3A]
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	strh r0, [r4, 0x3C]
	movs r5, 0x1
	mov r7, r8
	mov r6, sp
_08155736:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl MoveCoords
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0
	ldrsh r1, [r7, r2]
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0815575C
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _08155770
_0815575C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x3A]
	strh r0, [r6]
	ldrh r0, [r4, 0x3C]
	mov r1, r8
	strh r0, [r1]
	cmp r5, 0x4
	bls _08155736
_08155770:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81556E8

	thumb_func_start sub_815577C
sub_815577C: @ 815577C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r1, 0
	adds r4, r2, 0
	ldr r1, =gUnknown_085CDC6A
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	bl sub_8155638
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	cmp r2, 0
	beq _081557F6
	ldrh r1, [r4, 0x36]
	adds r1, 0x1
	strh r1, [r4, 0x36]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _081557BC
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
_081557BC:
	ldrh r1, [r4, 0x36]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _081557CC
	ldrh r0, [r4, 0x34]
	negs r0, r0
	strh r0, [r4, 0x34]
_081557CC:
	cmp r2, 0x2
	beq _081557F6
	adds r0, r4, 0
	bl sub_815564C
	lsls r0, 24
	cmp r0, 0
	bne _081557E4
	ldrh r0, [r4, 0x26]
	b _081557EA
	.pool
_081557E4:
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x30]
	adds r0, r3
_081557EA:
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x20]
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x22]
	adds r0, 0x8
	strh r0, [r4, 0x22]
_081557F6:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815577C

	thumb_func_start sub_8155800
sub_8155800: @ 8155800
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gDummySpriteTemplate
	movs r1, 0
	movs r2, 0
	movs r3, 0xFF
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r1, =gSprites
	adds r2, r1
	ldr r1, =sub_8155850
	str r1, [r2, 0x1C]
	movs r1, 0x3E
	adds r1, r2
	mov r12, r1
	ldrb r1, [r1]
	movs r3, 0x4
	orrs r1, r3
	mov r3, r12
	strb r1, [r3]
	strh r4, [r2, 0x2E]
	movs r1, 0x1
	strh r1, [r2, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155800

	thumb_func_start sub_8155850
sub_8155850: @ 8155850
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	ldrh r1, [r2, 0x32]
	adds r0, r1, 0x1
	strh r0, [r2, 0x32]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08155878
	ldrh r0, [r2, 0x30]
	ldrh r1, [r3, 0x26]
	adds r0, r1
	strh r0, [r3, 0x26]
_08155878:
	ldrh r1, [r2, 0x32]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _08155888
	ldrh r0, [r2, 0x30]
	negs r0, r0
	strh r0, [r2, 0x30]
_08155888:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155850

	thumb_func_start sub_8155890
sub_8155890: @ 8155890
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0xC
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x24]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081558EC
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, [r4, 0x8]
	strh r0, [r2, 0x2E]
	movs r0, 0xA
	strh r0, [r2, 0x30]
_081558EC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155890

	thumb_func_start sub_8155900
sub_8155900: @ 8155900
	push {r4-r7,lr}
	ldr r7, =gFieldEffectArguments
	ldrb r0, [r7]
	ldrb r1, [r7, 0x4]
	ldrb r2, [r7, 0x8]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r6, r1, r0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x74]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	beq _081559A4
	ldrb r0, [r6, 0x5]
	bl GetEventObjectGraphicsInfo
	adds r5, r0, 0
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	ldrb r2, [r6, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, [r7]
	strh r1, [r0, 0x2E]
	ldr r1, [r7, 0x4]
	strh r1, [r0, 0x30]
	ldr r1, [r7, 0x8]
	strh r1, [r0, 0x32]
	ldrb r2, [r6, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x20]
	strh r1, [r0, 0x34]
	ldrb r2, [r6, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x22]
	strh r1, [r0, 0x36]
	ldrh r1, [r5, 0xA]
	lsls r1, 16
	asrs r1, 17
	subs r1, 0x2
	strh r1, [r0, 0x26]
	movs r1, 0x2
	bl SeekSpriteAnim
_081559A4:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155900

	thumb_func_start sub_81559BC
sub_81559BC: @ 81559BC
	push {r4-r6,lr}
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
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _081559F6
	ldr r2, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrb r0, [r1, 0x2]
	lsls r0, 27
	cmp r0, 0
	blt _08155A04
_081559F6:
	adds r0, r4, 0
	movs r1, 0x27
	bl FieldEffectStop
	b _08155A76
	.pool
_08155A04:
	ldr r2, =gSprites
	ldrb r1, [r1, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r5, [r0, 0x22]
	ldrh r6, [r0, 0x20]
	movs r2, 0x20
	ldrsh r1, [r0, r2]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08155A2C
	lsls r0, r5, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	cmp r0, r1
	beq _08155A46
_08155A2C:
	strh r6, [r4, 0x34]
	strh r5, [r4, 0x36]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08155A46
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
_08155A46:
	strh r6, [r4, 0x20]
	strh r5, [r4, 0x22]
	ldr r3, =gSprites
	ldr r2, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
_08155A76:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81559BC

	thumb_func_start sub_8155A88
sub_8155A88: @ 8155A88
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	adds r0, 0x88
	ldr r0, [r0]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155AD8
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x5]
_08155AD8:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155A88

	thumb_func_start sub_8155AEC
sub_8155AEC: @ 8155AEC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x80
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, r0
	strh r1, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
	ldrh r1, [r4, 0x3E]
	ldr r0, =0x00001004
	ands r0, r1
	cmp r0, 0
	beq _08155B20
	adds r0, r4, 0
	movs r1, 0x35
	bl FieldEffectStop
_08155B20:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155AEC

	thumb_func_start sub_8155B2C
sub_8155B2C: @ 8155B2C
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x4
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x58]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155B8C
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x3
	ldrb r1, [r4, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x50
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x17
	strh r0, [r2, 0x2E]
_08155B8C:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155B2C

	thumb_func_start ShowTreeDisguiseFieldEffect
@ u8 ShowTreeDisguiseFieldEffect()
ShowTreeDisguiseFieldEffect: @ 8155BA0
	push {lr}
	movs r0, 0x1C
	movs r1, 0x18
	movs r2, 0x4
	bl ShowDisguiseFieldEffect
	pop {r1}
	bx r1
	thumb_func_end ShowTreeDisguiseFieldEffect

	thumb_func_start ShowMountainDisguiseFieldEffect
@ u8 ShowMountainDisguiseFieldEffect()
ShowMountainDisguiseFieldEffect: @ 8155BB0
	push {lr}
	movs r0, 0x1D
	movs r1, 0x19
	movs r2, 0x3
	bl ShowDisguiseFieldEffect
	pop {r1}
	bx r1
	thumb_func_end ShowMountainDisguiseFieldEffect

	thumb_func_start ShowSandDisguiseFieldEffect
@ u8 ShowSandDisguiseFieldEffect()
ShowSandDisguiseFieldEffect: @ 8155BC0
	push {lr}
	movs r0, 0x24
	movs r1, 0x1C
	movs r2, 0x2
	bl ShowDisguiseFieldEffect
	pop {r1}
	bx r1
	thumb_func_end ShowSandDisguiseFieldEffect

	thumb_func_start ShowDisguiseFieldEffect
@ u8 ShowDisguiseFieldEffect(u8 fieldEffectId, u8 fieldEffectObjectId, u8 paletteSlot)
ShowDisguiseFieldEffect: @ 8155BD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r5, =gFieldEffectArguments
	ldrb r0, [r5]
	ldrb r1, [r5, 0x4]
	ldrb r2, [r5, 0x8]
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	beq _08155C08
	adds r0, r4, 0
	bl FieldEffectActiveListRemove
	movs r0, 0x40
	b _08155C74
	.pool
_08155C08:
	ldr r1, =gFieldEffectObjectTemplatePointers
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	mov r1, sp
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08155C70
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	movs r0, 0x3E
	adds r0, r2
	mov r12, r0
	ldrb r3, [r0]
	lsls r1, r3, 30
	lsrs r1, 31
	adds r1, 0x1
	movs r0, 0x1
	ands r1, r0
	lsls r1, 1
	movs r0, 0x3
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	lsls r3, r7, 4
	ldrb r1, [r2, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0x5]
	mov r0, r8
	strh r0, [r2, 0x30]
	ldr r0, [r5]
	strh r0, [r2, 0x32]
	ldr r0, [r5, 0x4]
	strh r0, [r2, 0x34]
	ldr r0, [r5, 0x8]
	strh r0, [r2, 0x36]
_08155C70:
	mov r0, sp
	ldrb r0, [r0]
_08155C74:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ShowDisguiseFieldEffect

	thumb_func_start sub_8155C88
sub_8155C88: @ 8155C88
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r0, [r5, 0x32]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x34]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r5, 0x36]
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	beq _08155CB8
	ldrh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldEffectStop
_08155CB8:
	ldr r4, =gEventObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x5]
	bl GetEventObjectGraphicsInfo
	mov r1, sp
	ldrb r2, [r1]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	ldr r1, =gSprites
	adds r2, r1
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r1, [r1]
	movs r3, 0x3E
	adds r3, r5
	mov r12, r3
	movs r3, 0x4
	ands r3, r1
	mov r1, r12
	ldrb r4, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r4
	orrs r1, r3
	mov r3, r12
	strb r1, [r3]
	ldrh r1, [r2, 0x20]
	strh r1, [r5, 0x20]
	ldrh r0, [r0, 0xA]
	lsls r0, 16
	asrs r0, 17
	ldrh r1, [r2, 0x22]
	adds r0, r1
	subs r0, 0x10
	strh r0, [r5, 0x22]
	adds r2, 0x43
	ldrb r0, [r2]
	subs r0, 0x1
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x1
	bne _08155D38
	adds r0, r1, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_08155D38:
	movs r3, 0x2E
	ldrsh r0, [r5, r3]
	ldrh r2, [r5, 0x2E]
	cmp r0, 0x2
	bne _08155D54
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08155D54
	movs r0, 0x1
	strh r0, [r5, 0x3C]
_08155D54:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _08155D68
	ldrh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldEffectStop
_08155D68:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155C88

	thumb_func_start sub_8155D78
sub_8155D78: @ 8155D78
	push {lr}
	adds r1, r0, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08155D96
	ldr r2, =gSprites
	ldrb r1, [r1, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x2E]
	adds r1, 0x1
	strh r1, [r0, 0x2E]
_08155D96:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155D78

	thumb_func_start sub_8155DA0
sub_8155DA0: @ 8155DA0
	push {lr}
	adds r2, r0, 0
	adds r2, 0x21
	ldrb r1, [r2]
	cmp r1, 0x2
	beq _08155DD6
	cmp r1, 0
	beq _08155DD6
	ldrb r1, [r0, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r1, r0, r1
	movs r3, 0x3C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08155DCC
	movs r0, 0
	b _08155DD8
	.pool
_08155DCC:
	movs r0, 0x2
	strb r0, [r2]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
_08155DD6:
	movs r0, 0x1
_08155DD8:
	pop {r1}
	bx r1
	thumb_func_end sub_8155DA0

	thumb_func_start sub_8155DDC
sub_8155DDC: @ 8155DDC
	push {r4,lr}
	ldr r4, =gFieldEffectArguments
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	ldr r0, [r4, 0x4]
	adds r0, 0x7
	str r0, [r4, 0x4]
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	adds r0, 0x8C
	ldr r0, [r0]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08155E3C
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0x3
	ldrb r2, [r4, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r3, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
_08155E3C:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8155DDC

	thumb_func_start sub_8155E50
sub_8155E50: @ 8155E50
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08155E84
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08155E7C
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
_08155E7C:
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _08155E9A
_08155E84:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x22
	ble _08155E9A
	adds r0, r2, 0
	movs r1, 0x36
	bl FieldEffectStop
_08155E9A:
	pop {r0}
	bx r0
	thumb_func_end sub_8155E50

	thumb_func_start sub_8155EA0
sub_8155EA0: @ 8155EA0
	movs r1, 0
	strh r1, [r0, 0x3A]
	strh r1, [r0, 0x3C]
	bx lr
	thumb_func_end sub_8155EA0

	thumb_func_start sub_8155EA8
sub_8155EA8: @ 8155EA8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08155EDE
	cmp r0, 0x1
	bgt _08155EC0
	cmp r0, 0
	beq _08155ECA
	b _08155F42
_08155EC0:
	cmp r0, 0x2
	beq _08155F06
	cmp r0, 0x3
	beq _08155F1A
	b _08155F42
_08155ECA:
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	adds r0, r1
	strh r0, [r5, 0x24]
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	b _08155F38
_08155EDE:
	ldrh r0, [r5, 0x3A]
	movs r4, 0x47
	subs r0, r4, r0
	lsls r0, 16
	asrs r0, 16
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	subs r1, r0
	strh r1, [r5, 0x24]
	ldrh r0, [r5, 0x3A]
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_8097728
	ldrh r2, [r5, 0x26]
	adds r0, r2
	b _08155F40
_08155F06:
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	subs r1, r0
	strh r1, [r5, 0x24]
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	b _08155F38
_08155F1A:
	ldrh r0, [r5, 0x3A]
	movs r4, 0x47
	subs r0, r4, r0
	lsls r0, 16
	asrs r0, 16
	bl sub_809773C
	ldrh r2, [r5, 0x24]
	adds r0, r2
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x3A]
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
_08155F38:
	bl sub_8097728
	ldrh r1, [r5, 0x26]
	adds r0, r1
_08155F40:
	strh r0, [r5, 0x26]
_08155F42:
	ldrh r1, [r5, 0x24]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x10
	bl SetGpuReg
	ldrh r0, [r5, 0x3A]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x3A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x48
	bne _08155F68
	strh r1, [r5, 0x3A]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
_08155F68:
	movs r2, 0x3C
	ldrsh r0, [r5, r2]
	cmp r0, 0x4
	bne _08155F76
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	movs r6, 0x1
_08155F76:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8155EA8

	thumb_func_start sub_8155F80
sub_8155F80: @ 8155F80
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x8
	bls _08155F8E
	b _08156156
_08155F8E:
	lsls r0, 2
	ldr r1, =_08155F9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08155F9C:
	.4byte _08155FC0
	.4byte _08156034
	.4byte _0815606C
	.4byte _08156090
	.4byte _081560C0
	.4byte _081560D4
	.4byte _081560E0
	.4byte _0815610E
	.4byte _08156120
_08155FC0:
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	movs r1, 0x3
	bl __divsi3
	movs r1, 0x78
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	movs r3, 0x2E
	ldrsh r0, [r5, r3]
	cmp r0, 0x60
	bne _08156016
	movs r1, 0
	ldr r4, =0x0600f800
	mov r12, r4
	ldr r0, =0x0000bff4
	adds r7, r0, 0
_08155FEA:
	movs r2, 0xC
	lsls r0, r1, 1
	adds r3, r1, 0x1
	lsls r6, r1, 5
	adds r0, r1
	lsls r4, r0, 1
_08155FF6:
	adds r0, r6, r2
	lsls r0, 1
	add r0, r12
	adds r1, r2, r7
	adds r1, r4, r1
	adds r1, 0x1
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x11
	bls _08155FF6
	lsls r0, r3, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _08155FEA
_08156016:
	movs r2, 0x2E
	ldrsh r1, [r5, r2]
	ldr r0, =0x00000137
	cmp r1, r0
	bgt _08156022
	b _08156156
_08156022:
	movs r1, 0
	movs r0, 0x1
	b _0815611A
	.pool
_08156034:
	ldr r4, =gSineTable
	movs r3, 0x2E
	ldrsh r0, [r5, r3]
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	asrs r0, 15
	adds r0, r4
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 18
	ldrh r4, [r5, 0x36]
	adds r0, r4
	movs r1, 0
	strh r0, [r5, 0x22]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0xBD
	bne _08156156
	movs r0, 0x2
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x38]
	strh r1, [r5, 0x2E]
	b _08156156
	.pool
_0815606C:
	movs r3, 0x2E
	ldrsh r0, [r5, r3]
	cmp r0, 0x3C
	bne _0815607E
	ldrh r0, [r5, 0x38]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x38]
	strh r1, [r5, 0x2E]
_0815607E:
	movs r4, 0x38
	ldrsh r0, [r5, r4]
	cmp r0, 0x7
	bne _08156156
	movs r0, 0
	strh r0, [r5, 0x38]
	movs r0, 0x3
	strh r0, [r5, 0x32]
	b _08156156
_08156090:
	ldrh r2, [r5, 0x26]
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	adds r3, r2, 0
	cmp r1, 0
	bne _081560A4
	strh r1, [r5, 0x2E]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
_081560A4:
	movs r4, 0x2E
	ldrsh r0, [r5, r4]
	cmp r0, 0x5
	bne _08156156
	movs r0, 0
	strh r0, [r5, 0x2E]
	cmp r1, 0
	ble _081560BA
	subs r0, r3, 0x1
	strh r0, [r5, 0x26]
	b _08156156
_081560BA:
	adds r0, r2, 0x1
	strh r0, [r5, 0x26]
	b _08156156
_081560C0:
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x3C
	bne _08156156
	movs r1, 0
	movs r0, 0x5
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x2E]
	strh r1, [r5, 0x38]
	b _08156156
_081560D4:
	adds r0, r5, 0
	bl sub_8155EA0
	movs r1, 0
	movs r0, 0x6
	b _0815611A
_081560E0:
	adds r0, r5, 0
	bl sub_8155EA8
	lsls r0, 24
	cmp r0, 0
	beq _08156156
	movs r1, 0
	strh r1, [r5, 0x2E]
	ldrh r0, [r5, 0x38]
	adds r0, 0x1
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bgt _08156106
	adds r0, r5, 0
	bl sub_8155EA0
	b _08156156
_08156106:
	strh r1, [r5, 0x38]
	movs r0, 0x7
	strh r0, [r5, 0x32]
	b _08156156
_0815610E:
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x1E
	bne _08156156
	movs r1, 0
	movs r0, 0x8
_0815611A:
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x2E]
	b _08156156
_08156120:
	movs r1, 0
	ldr r6, =0x0600f800
	movs r4, 0
_08156126:
	movs r2, 0xC
	adds r3, r1, 0x1
	lsls r1, 5
_0815612C:
	adds r0, r1, r2
	lsls r0, 1
	adds r0, r6
	strh r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x11
	bls _0815612C
	lsls r0, r3, 24
	lsrs r1, r0, 24
	cmp r1, 0xE
	bls _08156126
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	movs r1, 0x40
	bl FieldEffectStop
_08156156:
	movs r3, 0x32
	ldrsh r0, [r5, r3]
	cmp r0, 0x1
	bne _08156184
	ldrh r1, [r5, 0x30]
	movs r0, 0x7
	ands r0, r1
	adds r2, r1, 0
	cmp r0, 0
	bne _08156172
	ldrh r0, [r5, 0x34]
	ldrh r4, [r5, 0x26]
	adds r0, r4
	strh r0, [r5, 0x26]
_08156172:
	movs r0, 0xF
	ands r0, r2
	cmp r0, 0
	bne _08156180
	ldrh r0, [r5, 0x34]
	negs r0, r0
	strh r0, [r5, 0x34]
_08156180:
	adds r0, r1, 0x1
	strh r0, [r5, 0x30]
_08156184:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8155F80

	thumb_func_start sub_8156194
sub_8156194: @ 8156194
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081561B2
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldEffectStop
	b _081561C8
_081561B2:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80979D4
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	movs r2, 0
	bl SetObjectSubpriorityByZCoord
_081561C8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8156194

	thumb_func_start sub_81561D0
sub_81561D0: @ 81561D0
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081561EE
	ldrh r1, [r2, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl FieldEffectStop
	b _081561F6
_081561EE:
	adds r0, r2, 0
	movs r1, 0
	bl sub_80979D4
_081561F6:
	pop {r0}
	bx r0
	thumb_func_end sub_81561D0

	thumb_func_start sub_81561FC
sub_81561FC: @ 81561FC
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	adds r1, r6, 0
	bl SetObjectSubpriorityByZCoord
	movs r7, 0
_08156212:
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	ldrb r0, [r4]
	lsls r0, 31
	cmp r0, 0
	beq _081562B4
	ldrb r0, [r4, 0x5]
	bl GetEventObjectGraphicsInfo
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	adds r0, r6, 0
	adds r0, 0x28
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldrh r0, [r6, 0x20]
	adds r1, r0, r2
	subs r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x20
	ldrsh r2, [r5, r0]
	cmp r1, r2
	bge _081562B4
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r2
	ble _081562B4
	adds r0, r5, 0
	adds r0, 0x29
	movs r3, 0
	ldrsb r3, [r0, r3]
	ldrh r2, [r5, 0x22]
	adds r2, r3
	ldrh r4, [r5, 0x22]
	adds r0, r6, 0
	adds r0, 0x29
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r6, 0x22]
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	adds r3, r0, r3
	lsls r2, 16
	asrs r2, 16
	lsls r3, 16
	asrs r3, 16
	cmp r2, r3
	blt _0815628C
	cmp r2, r0
	bge _081562B4
_0815628C:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r3
	ble _081562B4
	adds r2, r6, 0
	adds r2, 0x43
	adds r0, r5, 0
	adds r0, 0x43
	ldrb r1, [r0]
	ldrb r0, [r2]
	cmp r0, r1
	bhi _081562B4
	adds r0, r1, 0x2
	strb r0, [r2]
	b _081562BE
	.pool
_081562B4:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xF
	bls _08156212
_081562BE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81561FC

	.align 2, 0 @ Don't pad with nop.
