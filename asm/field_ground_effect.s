	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetAllGroundEffectFlags_OnSpawn
@ void GetAllGroundEffectFlags_OnSpawn(struct npc_state *fieldObject, u32 *flags)
GetAllGroundEffectFlags_OnSpawn: @ 8096638
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectUpdateMetatileBehaviors
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Reflection
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_TallGrassOnSpawn
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_LongGrassOnSpawn
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_HotSprings
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnSpawn

	thumb_func_start GetAllGroundEffectFlags_OnBeginStep
@ void GetAllGroundEffectFlags_OnBeginStep(struct npc_state *fieldObject, u32 *flags)
GetAllGroundEffectFlags_OnBeginStep: @ 8096680
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectUpdateMetatileBehaviors
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Reflection
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_TallGrassOnBeginStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_LongGrassOnBeginStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Tracks
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Puddle
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_HotSprings
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnBeginStep

	thumb_func_start GetAllGroundEffectFlags_OnFinishStep
@ void GetAllGroundEffectFlags_OnFinishStep(struct npc_state *fieldObject, u32 *flags)
GetAllGroundEffectFlags_OnFinishStep: @ 80966D8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectUpdateMetatileBehaviors
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Puddle
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Ripple
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_HotSprings
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_Seaweed
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetGroundEffectFlags_JumpLanding
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnFinishStep

	thumb_func_start FieldObjectUpdateMetatileBehaviors
@ void FieldObjectUpdateMetatileBehaviors(struct npc_state *fieldObject)
FieldObjectUpdateMetatileBehaviors: @ 8096728
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	strb r0, [r4, 0x1F]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	strb r0, [r4, 0x1E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectUpdateMetatileBehaviors

	thumb_func_start GetGroundEffectFlags_Reflection
@ void GetGroundEffectFlags_Reflection(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_Reflection: @ 8096750
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_0850E5DC
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	adds r0, r4, 0
	bl FieldObjectCheckForReflectiveSurface
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08096798
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 30
	cmp r0, 0
	blt _080967A2
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x2]
	subs r0, r2, 0x1
	lsls r0, 2
	add r0, sp
	ldr r1, [r5]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r5]
	b _080967A2
	.pool
_08096798:
	ldrb r1, [r4, 0x2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
_080967A2:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Reflection

	thumb_func_start GetGroundEffectFlags_TallGrassOnSpawn
@ void GetGroundEffectFlags_TallGrassOnSpawn(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_TallGrassOnSpawn: @ 80967AC
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsTallGrass
	lsls r0, 24
	cmp r0, 0
	beq _080967C4
	ldr r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	str r0, [r4]
_080967C4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_TallGrassOnSpawn

	thumb_func_start GetGroundEffectFlags_TallGrassOnBeginStep
@ void GetGroundEffectFlags_TallGrassOnBeginStep(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_TallGrassOnBeginStep: @ 80967CC
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsTallGrass
	lsls r0, 24
	cmp r0, 0
	beq _080967E4
	ldr r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	str r0, [r4]
_080967E4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_TallGrassOnBeginStep

	thumb_func_start GetGroundEffectFlags_LongGrassOnSpawn
@ void GetGroundEffectFlags_LongGrassOnSpawn(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_LongGrassOnSpawn: @ 80967EC
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _08096804
	ldr r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	str r0, [r4]
_08096804:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_LongGrassOnSpawn

	thumb_func_start GetGroundEffectFlags_LongGrassOnBeginStep
@ void GetGroundEffectFlags_LongGrassOnBeginStep(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_LongGrassOnBeginStep: @ 809680C
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _08096824
	ldr r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	str r0, [r4]
_08096824:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_LongGrassOnBeginStep

	thumb_func_start GetGroundEffectFlags_Tracks
@ void GetGroundEffectFlags_Tracks(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_Tracks: @ 809682C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsDeepSand
	lsls r0, 24
	cmp r0, 0
	beq _08096846
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 1
	b _08096862
_08096846:
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsSandOrDeepSand
	lsls r0, 24
	cmp r0, 0
	bne _0809685E
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsUnusedFootprintMetatile
	lsls r0, 24
	cmp r0, 0
	beq _08096866
_0809685E:
	ldr r0, [r5]
	movs r1, 0x80
_08096862:
	orrs r0, r1
	str r0, [r5]
_08096866:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Tracks

	thumb_func_start GetGroundEffectFlags_SandHeap
@ void GetGroundEffectFlags_SandHeap(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_SandHeap: @ 809686C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsDeepSand
	lsls r0, 24
	cmp r0, 0
	beq _080968AA
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsDeepSand
	lsls r0, 24
	cmp r0, 0
	beq _080968AA
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 27
	cmp r0, 0
	blt _080968B4
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4, 0x2]
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	str r0, [r5]
	b _080968B4
_080968AA:
	ldrb r1, [r4, 0x2]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
_080968B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_SandHeap

	thumb_func_start GetGroundEffectFlags_ShallowFlowingWater
@ void GetGroundEffectFlags_ShallowFlowingWater(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_ShallowFlowingWater: @ 80968BC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsShallowFlowingWater
	lsls r0, 24
	cmp r0, 0
	beq _080968DA
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsShallowFlowingWater
	lsls r0, 24
	cmp r0, 0
	bne _080968F2
_080968DA:
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, 24
	cmp r0, 0
	beq _08096910
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, 24
	cmp r0, 0
	beq _08096910
_080968F2:
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 28
	cmp r0, 0
	blt _0809691A
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4, 0x2]
	ldr r0, [r5]
	movs r1, 0x40
	orrs r0, r1
	str r0, [r5]
	b _0809691A
_08096910:
	ldrb r1, [r4, 0x2]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
_0809691A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_ShallowFlowingWater

	thumb_func_start GetGroundEffectFlags_Puddle
@ void GetGroundEffectFlags_Puddle(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_Puddle: @ 8096920
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsPuddle
	lsls r0, 24
	cmp r0, 0
	beq _08096948
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsPuddle
	lsls r0, 24
	cmp r0, 0
	beq _08096948
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 3
	orrs r0, r1
	str r0, [r5]
_08096948:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Puddle

	thumb_func_start GetGroundEffectFlags_Ripple
@ void GetGroundEffectFlags_Ripple(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_Ripple: @ 8096950
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_HasRipples
	lsls r0, 24
	cmp r0, 0
	beq _0809696A
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	str r0, [r4]
_0809696A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Ripple

	thumb_func_start GetGroundEffectFlags_ShortGrass
@ void GetGroundEffectFlags_ShortGrass(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_ShortGrass: @ 8096970
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsShortGrass
	lsls r0, 24
	cmp r0, 0
	beq _080969AE
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsShortGrass
	lsls r0, 24
	cmp r0, 0
	beq _080969AE
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 29
	cmp r0, 0
	blt _080969B8
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x2]
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 10
	orrs r0, r1
	str r0, [r5]
	b _080969B8
_080969AE:
	ldrb r1, [r4, 0x2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
_080969B8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_ShortGrass

	thumb_func_start GetGroundEffectFlags_HotSprings
@ void GetGroundEffectFlags_HotSprings(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_HotSprings: @ 80969C0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsHotSprings
	lsls r0, 24
	cmp r0, 0
	beq _080969FE
	ldrb r0, [r4, 0x1F]
	bl MetatileBehavior_IsHotSprings
	lsls r0, 24
	cmp r0, 0
	beq _080969FE
	ldrb r1, [r4, 0x2]
	lsls r0, r1, 26
	cmp r0, 0
	blt _08096A08
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x2]
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 11
	orrs r0, r1
	str r0, [r5]
	b _08096A08
_080969FE:
	ldrb r1, [r4, 0x2]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
_08096A08:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_HotSprings

	thumb_func_start GetGroundEffectFlags_Seaweed
@ void GetGroundEffectFlags_Seaweed(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_Seaweed: @ 8096A10
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsSeaweed
	lsls r0, 24
	cmp r0, 0
	beq _08096A2A
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r4]
_08096A2A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Seaweed

	thumb_func_start GetGroundEffectFlags_JumpLanding
@ void GetGroundEffectFlags_JumpLanding(struct npc_state *fieldObject, u32 *flags)
GetGroundEffectFlags_JumpLanding: @ 8096A30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r0, [r7]
	ldr r1, =0x02000020
	ands r0, r1
	cmp r0, 0x20
	bne _08096A82
	movs r5, 0
	ldr r0, =gUnknown_0850E5E4
	mov r8, r0
_08096A4A:
	lsls r4, r5, 2
	mov r0, r8
	adds r1, r4, r0
	ldrb r0, [r7, 0x1E]
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _08096A78
	ldr r0, =gUnknown_0850E5FC
	adds r0, r4, r0
	ldr r1, [r6]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r6]
	b _08096A82
	.pool
_08096A78:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08096A4A
_08096A82:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_JumpLanding

	thumb_func_start FieldObjectCheckForReflectiveSurface
@ u8 FieldObjectCheckForReflectiveSurface(struct npc_state *fieldObject)
FieldObjectCheckForReflectiveSurface: @ 8096A8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	ldrb r0, [r5, 0x5]
	bl GetFieldObjectGraphicsInfo
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	adds r1, 0x8
	lsls r1, 12
	lsrs r1, 16
	str r1, [sp]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	adds r0, 0x8
	lsls r0, 12
	movs r4, 0
	lsrs r2, r0, 16
	str r2, [sp, 0x4]
	asrs r0, 16
	cmp r4, r0
	blt _08096AC2
	b _08096BC8
_08096AC2:
	movs r0, 0x1
	mov r10, r0
_08096AC6:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	add r1, r10
	lsls r4, 16
	asrs r6, r4, 16
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	mov r9, r4
	cmp r0, 0
	bne _08096BCA
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	movs r2, 0x16
	ldrsh r1, [r5, r2]
	add r1, r10
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08096BCA
	movs r2, 0x1
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r1, r0, 16
	mov r8, r0
	cmp r2, r1
	bge _08096BB6
	movs r0, 0x80
	lsls r0, 9
	asrs r7, r0, 16
_08096B20:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	lsls r1, r2, 16
	asrs r4, r1, 16
	adds r0, r4
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	adds r1, r7
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08096BCA
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	subs r0, r4
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	adds r1, r7
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08096BCA
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	adds r0, r4
	movs r2, 0x16
	ldrsh r1, [r5, r2]
	adds r1, r7
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08096BCA
	movs r1, 0x14
	ldrsh r0, [r5, r1]
	subs r0, r4
	movs r2, 0x16
	ldrsh r1, [r5, r2]
	adds r1, r7
	adds r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08096BCA
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r0, r8
	blt _08096B20
_08096BB6:
	movs r1, 0x80
	lsls r1, 9
	add r1, r9
	lsrs r4, r1, 16
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	cmp r1, r0
	bge _08096BC8
	b _08096AC6
_08096BC8:
	movs r0, 0
_08096BCA:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end FieldObjectCheckForReflectiveSurface

	thumb_func_start GetReflectionTypeByMetatileBehavior
@ u8 GetReflectionTypeByMetatileBehavior(u8 metatileBehavior)
GetReflectionTypeByMetatileBehavior: @ 8096BDC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsIce
	lsls r0, 24
	cmp r0, 0
	beq _08096BF2
	movs r0, 0x1
	b _08096C04
_08096BF2:
	adds r0, r4, 0
	bl MetatileBehavior_IsReflective
	lsls r0, 24
	cmp r0, 0
	bne _08096C02
	movs r0, 0
	b _08096C04
_08096C02:
	movs r0, 0x2
_08096C04:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetReflectionTypeByMetatileBehavior

	thumb_func_start GetLedgeJumpDirection
@ u8 GetLedgeJumpDirection(u16 x, u16 y, u8 direction)
GetLedgeJumpDirection: @ 8096C0C
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0
	beq _08096C52
	cmp r4, 0x4
	bls _08096C28
	subs r0, r4, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
_08096C28:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r3, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_0850E614
	lsls r1, r4, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08096C5C
_08096C52:
	movs r0, 0
	b _08096C62
	.pool
_08096C5C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
_08096C62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetLedgeJumpDirection

	thumb_func_start FieldObjectSetSpriteOamTableForLongGrass
@ void FieldObjectSetSpriteOamTableForLongGrass(struct npc_state *fieldObject, struct obj *object)
FieldObjectSetSpriteOamTableForLongGrass: @ 8096C68
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5]
	lsls r0, 27
	cmp r0, 0
	blt _08096CBC
	ldrb r0, [r5, 0x1E]
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _08096CBC
	ldrb r0, [r5, 0x1F]
	bl MetatileBehavior_IsLongGrass
	lsls r0, 24
	cmp r0, 0
	beq _08096CBC
	adds r4, 0x42
	ldrb r1, [r4]
	movs r6, 0x40
	negs r6, r6
	adds r0, r6, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5, 0xB]
	lsrs r0, 4
	bl ZCoordToPriority
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08096CBC
	ldrb r0, [r4]
	adds r1, r6, 0
	ands r1, r0
	movs r0, 0x5
	orrs r1, r0
	strb r1, [r4]
_08096CBC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectSetSpriteOamTableForLongGrass

	thumb_func_start IsZCoordMismatchAt
@ bool8 IsZCoordMismatchAt(u8 z, u16 x, u16 y)
IsZCoordMismatchAt: @ 8096CC4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r2, 16
	lsrs r1, r2, 16
	cmp r4, 0
	beq _08096CF2
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08096CF2
	cmp r0, 0xF
	beq _08096CF2
	cmp r0, r4
	bne _08096CF6
_08096CF2:
	movs r0, 0
	b _08096CF8
_08096CF6:
	movs r0, 0x1
_08096CF8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsZCoordMismatchAt

	thumb_func_start FieldObjectUpdateZCoordAndPriority
@ void FieldObjectUpdateZCoordAndPriority(struct npc_state *fieldObject, struct obj *object)
FieldObjectUpdateZCoordAndPriority: @ 8096D00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x3]
	lsls r0, 29
	cmp r0, 0
	blt _08096D4E
	adds r0, r4, 0
	bl FieldObjectUpdateZCoord
	ldr r1, =gUnknown_0850E644
	ldrb r2, [r4, 0xB]
	lsls r2, 24
	lsrs r0, r2, 28
	adds r0, r1
	ldrb r0, [r0]
	adds r4, r5, 0
	adds r4, 0x42
	movs r1, 0x3F
	ands r1, r0
	ldrb r3, [r4]
	movs r0, 0x40
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldr r0, =gUnknown_0850E634
	lsrs r2, 28
	adds r2, r0
	movs r0, 0x3
	ldrb r1, [r2]
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
_08096D4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectUpdateZCoordAndPriority

	thumb_func_start InitObjectPriorityByZCoord
@ void InitObjectPriorityByZCoord(struct obj *object, u8 z)
InitObjectPriorityByZCoord: @ 8096D5C
	push {r4,lr}
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0850E644
	adds r2, r1, r2
	ldrb r2, [r2]
	movs r3, 0x42
	adds r3, r0
	mov r12, r3
	movs r3, 0x3F
	ands r3, r2
	mov r2, r12
	ldrb r4, [r2]
	movs r2, 0x40
	negs r2, r2
	ands r2, r4
	orrs r2, r3
	mov r3, r12
	strb r2, [r3]
	ldr r2, =gUnknown_0850E634
	adds r1, r2
	movs r3, 0x3
	ldrb r2, [r1]
	ands r2, r3
	lsls r2, 2
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitObjectPriorityByZCoord

	thumb_func_start ZCoordToPriority
@ u8 ZCoordToPriority(u8 z)
ZCoordToPriority: @ 8096DA8
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850E634
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end ZCoordToPriority

	thumb_func_start FieldObjectUpdateZCoord
@ void FieldObjectUpdateZCoord(struct npc_state *fieldObject)
FieldObjectUpdateZCoord: @ 8096DB8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r5, 0xF
	beq _08096E06
	cmp r0, 0xF
	beq _08096E06
	movs r3, 0xF
	adds r0, r5, 0
	ands r0, r3
	ldrb r1, [r4, 0xB]
	movs r2, 0x10
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0xB]
	cmp r5, 0
	beq _08096E06
	cmp r5, 0xF
	beq _08096E06
	lsls r0, r5, 4
	ands r2, r3
	orrs r2, r0
	strb r2, [r4, 0xB]
_08096E06:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectUpdateZCoord

	thumb_func_start SetObjectSubpriorityByZCoord
@ void SetObjectSubpriorityByZCoord(u8 z, struct obj *object, u8 offset)
SetObjectSubpriorityByZCoord: @ 8096E0C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	adds r3, r1, 0
	adds r3, 0x29
	movs r5, 0
	ldrsb r5, [r3, r5]
	ldrh r4, [r1, 0x22]
	ldr r3, =gSpriteCoordOffsetY
	subs r4, r5
	ldrh r3, [r3]
	adds r4, r3
	adds r4, 0x8
	movs r3, 0xFF
	ands r4, r3
	lsrs r4, 4
	movs r3, 0x10
	subs r3, r4
	lsls r3, 17
	ldr r4, =gUnknown_0850E624
	adds r0, r4
	lsrs r3, 16
	ldrb r0, [r0]
	adds r3, r0
	adds r2, r3
	adds r1, 0x43
	strb r2, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetObjectSubpriorityByZCoord

	thumb_func_start FieldObjectUpdateSubpriority
@ void FieldObjectUpdateSubpriority(struct npc_state *fieldObject, struct obj *object)
FieldObjectUpdateSubpriority: @ 8096E54
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2, 0x3]
	lsls r0, 29
	cmp r0, 0
	blt _08096E6A
	ldrb r0, [r2, 0xB]
	lsrs r0, 4
	movs r2, 0x1
	bl SetObjectSubpriorityByZCoord
_08096E6A:
	pop {r0}
	bx r0
	thumb_func_end FieldObjectUpdateSubpriority

	thumb_func_start AreZCoordsCompatible
@ bool8 AreZCoordsCompatible(u8 z1, u8 z2)
AreZCoordsCompatible: @ 8096E70
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0
	beq _08096E86
	cmp r1, 0
	beq _08096E86
	cmp r0, r1
	bne _08096E8A
_08096E86:
	movs r0, 0x1
	b _08096E8C
_08096E8A:
	movs r0, 0
_08096E8C:
	pop {r1}
	bx r1
	thumb_func_end AreZCoordsCompatible

	thumb_func_start GroundEffect_SpawnOnTallGrass
@ void GroundEffect_SpawnOnTallGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_SpawnOnTallGrass: @ 8096E90
	push {lr}
	ldr r3, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, 0x4]
	ldrb r1, [r0, 0xB]
	lsrs r1, 4
	str r1, [r3, 0x8]
	movs r1, 0x2
	str r1, [r3, 0xC]
	ldrb r1, [r0, 0x8]
	lsls r1, 8
	ldrb r2, [r0, 0x9]
	orrs r1, r2
	str r1, [r3, 0x10]
	ldrb r0, [r0, 0xA]
	str r0, [r3, 0x14]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	lsls r0, 8
	ldrb r1, [r1, 0x4]
	orrs r0, r1
	str r0, [r3, 0x18]
	movs r0, 0x1
	str r0, [r3, 0x1C]
	movs r0, 0x4
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_SpawnOnTallGrass

	thumb_func_start GroundEffect_StepOnTallGrass
@ void GroundEffect_StepOnTallGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_StepOnTallGrass: @ 8096EDC
	push {lr}
	ldr r3, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, 0x4]
	ldrb r1, [r0, 0xB]
	lsrs r1, 4
	str r1, [r3, 0x8]
	movs r1, 0x2
	str r1, [r3, 0xC]
	ldrb r1, [r0, 0x8]
	lsls r1, 8
	ldrb r2, [r0, 0x9]
	orrs r1, r2
	str r1, [r3, 0x10]
	ldrb r0, [r0, 0xA]
	str r0, [r3, 0x14]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	lsls r0, 8
	ldrb r1, [r1, 0x4]
	orrs r0, r1
	str r0, [r3, 0x18]
	movs r0, 0
	str r0, [r3, 0x1C]
	movs r0, 0x4
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_StepOnTallGrass

	thumb_func_start GroundEffect_SpawnOnLongGrass
@ void GroundEffect_SpawnOnLongGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_SpawnOnLongGrass: @ 8096F28
	push {lr}
	ldr r3, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, 0x4]
	ldrb r1, [r0, 0xB]
	lsrs r1, 4
	str r1, [r3, 0x8]
	movs r1, 0x2
	str r1, [r3, 0xC]
	ldrb r1, [r0, 0x8]
	lsls r1, 8
	ldrb r2, [r0, 0x9]
	orrs r1, r2
	str r1, [r3, 0x10]
	ldrb r0, [r0, 0xA]
	str r0, [r3, 0x14]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	lsls r0, 8
	ldrb r1, [r1, 0x4]
	orrs r0, r1
	str r0, [r3, 0x18]
	movs r0, 0x1
	str r0, [r3, 0x1C]
	movs r0, 0x11
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_SpawnOnLongGrass

	thumb_func_start GroundEffect_StepOnLongGrass
@ void GroundEffect_StepOnLongGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_StepOnLongGrass: @ 8096F74
	push {lr}
	ldr r3, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, 0x4]
	ldrb r1, [r0, 0xB]
	lsrs r1, 4
	str r1, [r3, 0x8]
	movs r1, 0x2
	str r1, [r3, 0xC]
	ldrb r1, [r0, 0x8]
	lsls r1, 8
	ldrb r2, [r0, 0x9]
	orrs r1, r2
	str r1, [r3, 0x10]
	ldrb r0, [r0, 0xA]
	str r0, [r3, 0x14]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	lsls r0, 8
	ldrb r1, [r1, 0x4]
	orrs r0, r1
	str r0, [r3, 0x18]
	movs r0, 0
	str r0, [r3, 0x1C]
	movs r0, 0x11
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_StepOnLongGrass

	thumb_func_start GroundEffect_WaterReflection
@ void GroundEffect_WaterReflection(struct npc_state *fieldObject, struct obj *object)
GroundEffect_WaterReflection: @ 8096FC0
	push {lr}
	movs r2, 0
	bl SetUpReflection
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_WaterReflection

	thumb_func_start GroundEffect_IceReflection
@ void GroundEffect_IceReflection(struct npc_state *fieldObject, struct obj *object)
GroundEffect_IceReflection: @ 8096FCC
	push {lr}
	movs r2, 0x1
	bl SetUpReflection
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_IceReflection

	thumb_func_start GroundEffect_FlowingWater
@ void GroundEffect_FlowingWater(struct npc_state *fieldObject, struct obj *object)
GroundEffect_FlowingWater: @ 8096FD8
	push {lr}
	adds r1, r0, 0
	movs r0, 0x22
	bl oe_exec_and_other_stuff
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_FlowingWater

	thumb_func_start GroundEffect_SandTracks
@ void GroundEffect_SandTracks(struct npc_state *fieldObject, struct obj *object)
GroundEffect_SandTracks: @ 8096FE8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldr r1, =gUnknown_0850E654
	ldrb r0, [r0, 0xD]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl _call_via_r3
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_SandTracks

	thumb_func_start GroundEffect_DeepSandTracks
@ void GroundEffect_DeepSandTracks(struct npc_state *fieldObject, struct obj *object)
GroundEffect_DeepSandTracks: @ 8097014
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldr r1, =gUnknown_0850E654
	ldrb r0, [r0, 0xD]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl _call_via_r3
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_DeepSandTracks

	thumb_func_start DoTracksGroundEffect_None
@ void DoTracksGroundEffect_None(struct npc_state *fieldObject, struct obj *object)
DoTracksGroundEffect_None: @ 8097040
	bx lr
	thumb_func_end DoTracksGroundEffect_None

	thumb_func_start DoTracksGroundEffect_Footprints
@ void DoTracksGroundEffect_Footprints(struct npc_state *fieldObject, struct obj *object)
DoTracksGroundEffect_Footprints: @ 8097044
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r4, r2, 24
	lsrs r4, 24
	ldr r1, =gUnknown_0850E660
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	ldr r1, =gUnknown_02038C08
	movs r2, 0x14
	ldrsh r0, [r5, r2]
	str r0, [r1]
	movs r2, 0x16
	ldrsh r0, [r5, r2]
	str r0, [r1, 0x4]
	movs r0, 0x95
	str r0, [r1, 0x8]
	movs r0, 0x2
	str r0, [r1, 0xC]
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	str r0, [r1, 0x10]
	lsls r4, 1
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl FieldEffectStart
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTracksGroundEffect_Footprints

	thumb_func_start DoTracksGroundEffect_BikeTireTracks
@ void DoTracksGroundEffect_BikeTireTracks(struct npc_state *fieldObject, struct obj *object)
DoTracksGroundEffect_BikeTireTracks: @ 8097094
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4, 0x10]
	ldr r0, [r4, 0x14]
	cmp r1, r0
	beq _080970D6
	ldr r2, =gUnknown_02038C08
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	str r0, [r2]
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	str r0, [r2, 0x4]
	movs r0, 0x95
	str r0, [r2, 0x8]
	movs r0, 0x2
	str r0, [r2, 0xC]
	ldr r3, =gUnknown_0850E664
	ldrb r1, [r4, 0x18]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 2
	subs r0, 0x5
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	str r0, [r2, 0x10]
	movs r0, 0x23
	bl FieldEffectStart
_080970D6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTracksGroundEffect_BikeTireTracks

	thumb_func_start GroundEffect_Ripple
@ void GroundEffect_Ripple(struct npc_state *fieldObject, struct obj *object)
GroundEffect_Ripple: @ 80970E4
	push {lr}
	bl DoRippleFieldEffect
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_Ripple

	thumb_func_start GroundEffect_StepOnPuddle
@ void GroundEffect_StepOnPuddle(struct npc_state *fieldObject, struct obj *object)
GroundEffect_StepOnPuddle: @ 80970F0
	push {lr}
	adds r1, r0, 0
	movs r0, 0xF
	bl oe_exec_and_other_stuff
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_StepOnPuddle

	thumb_func_start GroundEffect_SandHeap
@ void GroundEffect_SandHeap(struct npc_state *fieldObject, struct obj *object)
GroundEffect_SandHeap: @ 8097100
	push {lr}
	adds r1, r0, 0
	movs r0, 0x27
	bl oe_exec_and_other_stuff
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_SandHeap

	thumb_func_start GroundEffect_JumpOnTallGrass
@ void GroundEffect_JumpOnTallGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_JumpOnTallGrass: @ 8097110
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r1, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	str r0, [r1]
	movs r4, 0x12
	ldrsh r0, [r5, r4]
	str r0, [r1, 0x4]
	ldrb r0, [r5, 0xB]
	lsrs r0, 4
	str r0, [r1, 0x8]
	movs r0, 0x2
	str r0, [r1, 0xC]
	movs r0, 0xC
	bl FieldEffectStart
	ldrb r0, [r5, 0x8]
	ldrb r1, [r5, 0x9]
	ldrb r2, [r5, 0xA]
	movs r7, 0x10
	ldrsh r3, [r5, r7]
	movs r7, 0x12
	ldrsh r4, [r5, r7]
	str r4, [sp]
	bl sub_81546C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	bne _0809715A
	adds r0, r5, 0
	adds r1, r6, 0
	bl GroundEffect_SpawnOnTallGrass
_0809715A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_JumpOnTallGrass

	thumb_func_start GroundEffect_JumpOnLongGrass
@ void GroundEffect_JumpOnLongGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_JumpOnLongGrass: @ 8097168
	push {lr}
	ldr r2, =gUnknown_02038C08
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	str r1, [r2]
	movs r3, 0x12
	ldrsh r1, [r0, r3]
	str r1, [r2, 0x4]
	ldrb r0, [r0, 0xB]
	lsrs r0, 4
	str r0, [r2, 0x8]
	movs r0, 0x2
	str r0, [r2, 0xC]
	movs r0, 0x12
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_JumpOnLongGrass

	thumb_func_start GroundEffect_JumpOnShallowWater
@ void GroundEffect_JumpOnShallowWater(struct npc_state *fieldObject, struct obj *object)
GroundEffect_JumpOnShallowWater: @ 8097190
	push {r4,lr}
	ldr r3, =gUnknown_02038C08
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, 0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, 0x4]
	ldrb r0, [r0, 0xB]
	lsrs r0, 4
	str r0, [r3, 0x8]
	ldrb r0, [r1, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r3, 0xC]
	movs r0, 0x10
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_JumpOnShallowWater

	thumb_func_start GroundEffect_JumpOnWater
@ void GroundEffect_JumpOnWater(struct npc_state *fieldObject, struct obj *object)
GroundEffect_JumpOnWater: @ 80971C0
	push {r4,lr}
	ldr r3, =gUnknown_02038C08
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, 0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, 0x4]
	ldrb r0, [r0, 0xB]
	lsrs r0, 4
	str r0, [r3, 0x8]
	ldrb r0, [r1, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r3, 0xC]
	movs r0, 0xE
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_JumpOnWater

	thumb_func_start GroundEffect_JumpLandingDust
@ void GroundEffect_JumpLandingDust(struct npc_state *fieldObject, struct obj *object)
GroundEffect_JumpLandingDust: @ 80971F0
	push {r4,lr}
	ldr r3, =gUnknown_02038C08
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, 0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, 0x4]
	ldrb r0, [r0, 0xB]
	lsrs r0, 4
	str r0, [r3, 0x8]
	ldrb r0, [r1, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r3, 0xC]
	movs r0, 0xA
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_JumpLandingDust

	thumb_func_start GroundEffect_ShortGrass
@ void GroundEffect_ShortGrass(struct npc_state *fieldObject, struct obj *object)
GroundEffect_ShortGrass: @ 8097220
	push {lr}
	adds r1, r0, 0
	movs r0, 0x29
	bl oe_exec_and_other_stuff
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_ShortGrass

	thumb_func_start GroundEffect_HotSprings
@ void GroundEffect_HotSprings(struct npc_state *fieldObject, struct obj *object)
GroundEffect_HotSprings: @ 8097230
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2A
	bl oe_exec_and_other_stuff
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_HotSprings

	thumb_func_start GroundEffect_Seaweed
@ void GroundEffect_Seaweed(struct npc_state *fieldObject, struct obj *object)
GroundEffect_Seaweed: @ 8097240
	push {lr}
	ldr r2, =gUnknown_02038C08
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	str r1, [r2]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	str r0, [r2, 0x4]
	movs r0, 0x35
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end GroundEffect_Seaweed

	thumb_func_start DoFlaggedGroundEffects
@ void DoFlaggedGroundEffects(struct npc_state *fieldObject, struct obj *object, u32 flags)
DoFlaggedGroundEffects: @ 8097260
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	bl FieldObjectIsFarawayIslandMew
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08097284
	adds r0, r6, 0
	bl sub_81D4A58
	lsls r0, 24
	cmp r0, 0
	beq _080972AC
_08097284:
	movs r4, 0
	ldr r0, =gUnknown_0850E674
	mov r8, r0
_0809728A:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _080972A0
	lsls r0, r4, 2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl _call_via_r2
_080972A0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsrs r5, 1
	cmp r4, 0x13
	bls _0809728A
_080972AC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoFlaggedGroundEffects

	thumb_func_start filters_out_some_ground_effects
@ void filters_out_some_ground_effects(struct npc_state *fieldObject, u32 *flags)
filters_out_some_ground_effects: @ 80972BC
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldrb r0, [r2]
	lsls r0, 27
	cmp r0, 0
	bge _080972EA
	ldrb r1, [r2, 0x2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	adds r1, 0x8
	ands r0, r1
	subs r1, 0x18
	ands r0, r1
	strb r0, [r2, 0x2]
	ldr r0, [r3]
	ldr r1, =0xfff9f7bd
	ands r0, r1
	str r0, [r3]
_080972EA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end filters_out_some_ground_effects

	thumb_func_start FilterOutStepOnPuddleGroundEffectIfJumping
@ void FilterOutStepOnPuddleGroundEffectIfJumping(struct npc_state *fieldObject, u32 *flags)
FilterOutStepOnPuddleGroundEffectIfJumping: @ 80972F4
	push {lr}
	adds r2, r1, 0
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _08097308
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
_08097308:
	pop {r0}
	bx r0
	.pool
	thumb_func_end FilterOutStepOnPuddleGroundEffectIfJumping

	thumb_func_start DoGroundEffects_OnSpawn
@ void DoGroundEffects_OnSpawn(struct npc_state *fieldObject, struct obj *object)
DoGroundEffects_OnSpawn: @ 8097310
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	lsls r0, 29
	cmp r0, 0
	bge _08097354
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	bl FieldObjectUpdateZCoordAndPriority
	adds r0, r4, 0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnSpawn
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetSpriteOamTableForLongGrass
	ldr r2, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r4]
_08097354:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnSpawn

	thumb_func_start DoGroundEffects_OnBeginStep
@ void DoGroundEffects_OnBeginStep(struct npc_state *fieldObject, struct obj *object)
DoGroundEffects_OnBeginStep: @ 809735C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	lsls r0, 29
	cmp r0, 0
	bge _080973A8
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	bl FieldObjectUpdateZCoordAndPriority
	adds r0, r4, 0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnBeginStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetSpriteOamTableForLongGrass
	adds r0, r4, 0
	mov r1, sp
	bl filters_out_some_ground_effects
	ldr r2, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r4]
_080973A8:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnBeginStep

	thumb_func_start DoGroundEffects_OnFinishStep
@ void DoGroundEffects_OnFinishStep(struct npc_state *fieldObject, struct obj *object)
DoGroundEffects_OnFinishStep: @ 80973B0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	lsls r0, 28
	cmp r0, 0
	bge _080973FC
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	bl FieldObjectUpdateZCoordAndPriority
	adds r0, r4, 0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnFinishStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetSpriteOamTableForLongGrass
	adds r0, r4, 0
	mov r1, sp
	bl FilterOutStepOnPuddleGroundEffectIfJumping
	ldr r2, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	strb r0, [r4]
_080973FC:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnFinishStep

	.align 2, 0 @ Don't pad with nop.
