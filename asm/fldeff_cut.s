	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start CutGrassSpriteCallbackEnd
CutGrassSpriteCallbackEnd: @ 80D41D0
	push {r4-r6,lr}
	movs r4, 0x1
_080D41D4:
	ldr r6, =gCutGrassSpriteArrayPtr
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _080D41D4
	ldr r0, [r6]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x3A
	bl FieldEffectStop
	ldr r0, [r6]
	bl Free
	movs r0, 0
	str r0, [r6]
	bl sub_80984F4
	bl ScriptContext2_Disable
	bl unown_chamber_related
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D422A
	ldr r0, =FarawayIsland_Interior_EventScript_267EDB
	bl ScriptContext1_SetupScript
_080D422A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CutGrassSpriteCallbackEnd

	thumb_func_start sub_80D423C
sub_80D423C: @ 80D423C
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsLongGrass_Duplicate
	lsls r0, 24
	cmp r0, 0
	beq _080D42AE
	adds r4, 0x1
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r5, 0
	bl GetTallGrassCaseAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080D428A
	cmp r0, 0x2
	bgt _080D427A
	cmp r0, 0x1
	beq _080D4284
	b _080D42AE
_080D427A:
	cmp r0, 0x3
	beq _080D4294
	cmp r0, 0x4
	beq _080D42A4
	b _080D42AE
_080D4284:
	movs r2, 0x82
	lsls r2, 2
	b _080D4296
_080D428A:
	ldr r2, =0x00000281
	b _080D4296
	.pool
_080D4294:
	ldr r2, =0x00000282
_080D4296:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	b _080D42AE
	.pool
_080D42A4:
	ldr r2, =0x00000283
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D42AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D423C

	thumb_func_start sub_80D42B8
sub_80D42B8: @ 80D42B8
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	cmp r0, 0x1
	bne _080D434A
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsLongGrassSouthEdge
	lsls r0, 24
	cmp r0, 0
	beq _080D434A
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x00000281
	cmp r1, r0
	beq _080D4328
	cmp r1, r0
	bgt _080D4308
	subs r0, 0x79
	cmp r1, r0
	beq _080D431C
	b _080D434A
	.pool
_080D4308:
	ldr r0, =0x00000282
	cmp r1, r0
	beq _080D4330
	adds r0, 0x1
	cmp r1, r0
	beq _080D4340
	b _080D434A
	.pool
_080D431C:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl MapGridSetMetatileIdAt
	b _080D434A
_080D4328:
	ldr r2, =0x00000279
	b _080D4332
	.pool
_080D4330:
	ldr r2, =0x0000027a
_080D4332:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _080D434A
	.pool
_080D4340:
	ldr r2, =0x0000027b
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_080D434A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D42B8

	thumb_func_start StartCutTreeFieldEffect
StartCutTreeFieldEffect: @ 80D4354
	push {lr}
	movs r0, 0x80
	bl PlaySE
	movs r0, 0x2
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end StartCutTreeFieldEffect

	.align 2, 0 @ Don't pad with nop.
