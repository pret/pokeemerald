	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81795E8
sub_81795E8: @ 81795E8
	push {lr}
	ldr r0, =0x000008af
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08179634
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r1, [r2, 0x4]
	ldr r0, =0x00004718
	cmp r1, r0
	bne _08179634
	ldr r1, [r2]
	ldr r0, =0x0003000a
	cmp r1, r0
	beq _08179616
	ldr r0, =0x00030009
	cmp r1, r0
	beq _08179616
	ldr r0, =0x0003000b
	cmp r1, r0
	bne _08179634
_08179616:
	movs r0, 0x1
	b _08179636
	.pool
_08179634:
	movs r0, 0
_08179636:
	pop {r1}
	bx r1
	thumb_func_end sub_81795E8

	thumb_func_start sub_817963C
sub_817963C: @ 817963C
	push {lr}
	ldr r2, =0x0000022a
	movs r0, 0x10
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x0000022b
	movs r0, 0x11
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	movs r2, 0x8B
	lsls r2, 2
	movs r0, 0x12
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e32
	movs r0, 0x10
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000233
	movs r0, 0x11
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e34
	movs r0, 0x12
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	movs r0, 0x14
	bl PlaySE
	ldr r0, =0x000008af
	bl FlagSet
	bl ScriptContext2_Disable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817963C

	thumb_func_start sub_81796AC
sub_81796AC: @ 81796AC
	push {r4,lr}
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0x9D
	lsls r1, 1
	cmp r0, r1
	bne _081796F4
	bl CalculatePlayerPartyCount
	ldr r0, =gPlayerPartyCount
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	adds r1, r4, 0
	subs r1, 0x64
	adds r0, r1
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	ldr r1, =0x0000017d
	cmp r0, r1
	bne _081796F4
	movs r0, 0x1
	b _081796F6
	.pool
_081796F4:
	movs r0, 0
_081796F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81796AC

	thumb_func_start nullsub_84
nullsub_84: @ 81796FC
	bx lr
	thumb_func_end nullsub_84

	thumb_func_start sub_8179700
sub_8179700: @ 8179700
	push {lr}
	ldr r0, =sub_8179778
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	movs r0, 0x2
	strh r0, [r1, 0x10]
	movs r0, 0x5
	strh r0, [r1, 0x12]
	movs r0, 0x32
	strh r0, [r1, 0x14]
	movs r0, 0
	bl SetCameraPanningCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179700

	thumb_func_start sub_817973C
sub_817973C: @ 817973C
	push {lr}
	ldr r0, =sub_8179778
	movs r1, 0x9
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	movs r0, 0x3
	strh r0, [r1, 0x10]
	movs r0, 0x5
	strh r0, [r1, 0x12]
	movs r0, 0x2
	strh r0, [r1, 0x14]
	movs r0, 0
	bl SetCameraPanningCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817973C

	thumb_func_start sub_8179778
sub_8179778: @ 8179778
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _081797D0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	negs r0, r0
	strh r0, [r4, 0x10]
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl SetCameraPanning
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081797D0
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	bl InstallCameraPanAheadCallback
_081797D0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179778

	thumb_func_start sub_81797DC
sub_81797DC: @ 81797DC
	push {lr}
	movs r0, 0x8B
	lsls r0, 4
	bl FlagGet
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0817982C
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldrh r1, [r3, 0x4]
	movs r0, 0xC3
	lsls r0, 3
	cmp r1, r0
	bne _0817982C
	ldr r1, [r3]
	ldr r0, =0x00170006
	cmp r1, r0
	beq _08179810
	ldr r0, =0x00170005
	cmp r1, r0
	beq _08179810
	ldr r0, =0x00170007
	cmp r1, r0
	bne _0817982C
_08179810:
	ldr r0, =gUnknown_0203BD14
	strb r2, [r0]
	movs r0, 0x1
	b _0817982E
	.pool
_0817982C:
	movs r0, 0
_0817982E:
	pop {r1}
	bx r1
	thumb_func_end sub_81797DC

	thumb_func_start sub_8179834
sub_8179834: @ 8179834
	push {lr}
	bl brm_get_pokemon_selection
	ldr r1, =gFieldEffectSpawnParams
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	movs r0, 0x3C
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179834

	thumb_func_start sub_8179850
sub_8179850: @ 8179850
	push {lr}
	movs r0, 0x3C
	bl FieldEffectActiveListRemove
	bl sub_8179860
	pop {r0}
	bx r0
	thumb_func_end sub_8179850

	thumb_func_start sub_8179860
sub_8179860: @ 8179860
	push {lr}
	ldr r2, =0x0000022a
	movs r0, 0xE
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	ldr r2, =0x0000022b
	movs r0, 0xF
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	movs r2, 0x8B
	lsls r2, 2
	movs r0, 0x10
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e32
	movs r0, 0xE
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000233
	movs r0, 0xF
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e34
	movs r0, 0x10
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	movs r0, 0x14
	bl PlaySE
	movs r0, 0x8B
	lsls r0, 4
	bl FlagSet
	bl ScriptContext2_Disable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179860

	thumb_func_start sub_81798D0
sub_81798D0: @ 81798D0
	push {lr}
	ldr r0, =0x000008b2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08179910
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r1, [r2, 0x4]
	ldr r0, =0x00004418
	cmp r1, r0
	bne _08179910
	ldr r1, [r2]
	ldr r0, =0x00190008
	cmp r1, r0
	bne _08179910
	ldr r1, =gUnknown_0203BD14
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	b _08179912
	.pool
_08179910:
	movs r0, 0
_08179912:
	pop {r1}
	bx r1
	thumb_func_end sub_81798D0

	thumb_func_start sub_8179918
sub_8179918: @ 8179918
	push {lr}
	bl brm_get_pokemon_selection
	ldr r1, =gFieldEffectSpawnParams
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	movs r0, 0x3C
	bl FieldEffectStart
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179918

	thumb_func_start sub_8179934
sub_8179934: @ 8179934
	push {lr}
	movs r0, 0x3C
	bl FieldEffectActiveListRemove
	bl sub_8179944
	pop {r0}
	bx r0
	thumb_func_end sub_8179934

	thumb_func_start sub_8179944
sub_8179944: @ 8179944
	push {lr}
	ldr r2, =0x0000022a
	movs r0, 0xE
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	ldr r2, =0x0000022b
	movs r0, 0xF
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	movs r2, 0x8B
	lsls r2, 2
	movs r0, 0x10
	movs r1, 0x1A
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e32
	movs r0, 0xE
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000233
	movs r0, 0xF
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000e34
	movs r0, 0x10
	movs r1, 0x1B
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	movs r0, 0x14
	bl PlaySE
	ldr r0, =0x000008b2
	bl FlagSet
	bl ScriptContext2_Disable
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179944

	thumb_func_start nullsub_64
nullsub_64: @ 81799B4
	bx lr
	thumb_func_end nullsub_64

	thumb_func_start sub_81799B8
sub_81799B8: @ 81799B8
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203BD14
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081799E4
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldr r2, =sub_8179934
	b _081799F0
	.pool
_081799E4:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldr r2, =sub_8179850
_081799F0:
	lsrs r1, r2, 16
	strh r1, [r0, 0x18]
	strh r2, [r0, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81799B8

	thumb_func_start sub_8179A04
sub_8179A04: @ 8179A04
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00004318
	cmp r1, r0
	beq _08179A1A
	b _08179B5A
_08179A1A:
	ldr r0, =0x000008b1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08179A28
	b _08179B5A
_08179A28:
	movs r0, 0x2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08179A36
	b _08179B5A
_08179A36:
	movs r0, 0x3
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08179A58
	b _08179B5A
	.pool
_08179A54:
	movs r0, 0x1
	b _08179B5C
_08179A58:
	movs r5, 0
	mov r8, r4
	ldr r4, =gUnknown_085EFE74
	adds r0, r4, 0x1
	mov r12, r0
	ldr r6, =0x0000403b
	ldr r1, =0x0000403c
	mov r9, r1
_08179A68:
	lsls r0, r5, 1
	adds r1, r0, r4
	add r0, r12
	ldrb r3, [r0]
	mov r7, r8
	ldr r2, [r7]
	movs r7, 0
	ldrsh r0, [r2, r7]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08179B44
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	cmp r0, r3
	bne _08179B44
	cmp r5, 0xF
	bhi _08179AB0
	adds r0, r6, 0
	bl VarGet
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r5
	orrs r1, r0
	lsrs r1, 16
	adds r0, r6, 0
	bl VarSet
	b _08179AF0
	.pool
_08179AB0:
	cmp r5, 0x1F
	bhi _08179AD2
	mov r0, r9
	bl VarGet
	lsls r0, 16
	adds r2, r5, 0
	subs r2, 0x10
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r2
	orrs r1, r0
	lsrs r1, 16
	mov r0, r9
	bl VarSet
	b _08179AF0
_08179AD2:
	ldr r4, =0x0000403d
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	adds r2, r5, 0
	subs r2, 0x20
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r2
	orrs r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_08179AF0:
	ldr r0, =0x0000403b
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	bne _08179B5A
	ldr r0, =0x0000403c
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bne _08179B5A
	ldr r0, =0x0000403d
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bne _08179B5A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, =0x00150008
	cmp r1, r0
	beq _08179A54
	b _08179B5A
	.pool
_08179B44:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x23
	bls _08179A68
	movs r0, 0x3
	bl FlagSet
	movs r0, 0x2
	bl FlagReset
_08179B5A:
	movs r0, 0
_08179B5C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8179A04

	.align 2, 0 @ Don't pad with nop.
