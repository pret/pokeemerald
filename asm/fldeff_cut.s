	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80D3718
sub_80D3718: @ 80D3718
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	movs r0, 0x52
	bl npc_before_player_of_type
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D3754
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_80D3A9C
	str r0, [r1]
	movs r0, 0x1
	b _080D3A2C
	.pool
_080D3754:
	ldr r0, =gUnknown_0203AB40
	adds r1, r0, 0x2
	bl PlayerGetDestCoords
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	cmp r0, 0x34
	bne _080D3798
	ldr r1, =gUnknown_03001100
	movs r0, 0x5
	strb r0, [r1]
	ldr r0, =gUnknown_03001101
	movs r1, 0x2
	b _080D37A2
	.pool
_080D3798:
	ldr r1, =gUnknown_03001100
	movs r0, 0x3
	strb r0, [r1]
	ldr r0, =gUnknown_03001101
	movs r1, 0x1
_080D37A2:
	strb r1, [r0]
	ldr r0, =gUnknown_03001102
	strb r1, [r0]
	movs r6, 0
	movs r1, 0
_080D37AC:
	mov r2, sp
	adds r0, r2, r6
	strb r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x8
	bls _080D37AC
	movs r6, 0
	ldr r2, =gUnknown_03001108
	movs r1, 0
_080D37C2:
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x18
	bls _080D37C2
	movs r3, 0
	str r3, [sp, 0x10]
	movs r6, 0
_080D37D6:
	ldr r4, =0x0000ffff
	adds r0, r6, r4
	ldr r1, =gUnknown_0203AB40
	ldrh r1, [r1, 0x2]
	adds r0, r1
	movs r5, 0
	adds r2, r6, 0x1
	str r2, [sp, 0x18]
	lsls r7, r6, 1
	lsls r0, 16
	str r0, [sp, 0x14]
	asrs r0, 16
	mov r10, r0
	lsls r0, r6, 2
	adds r0, r6
	mov r9, r0
_080D37F6:
	ldr r3, =0x0000ffff
	adds r0, r5, r3
	ldr r4, =gUnknown_0203AB40
	ldrh r4, [r4]
	adds r0, r4
	lsls r0, 16
	lsrs r1, r0, 16
	mov r8, r1
	asrs r4, r0, 16
	adds r0, r4, 0
	mov r1, r10
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_0203AB40
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	cmp r0, r1
	bne _080D38BC
	adds r0, r4, 0
	mov r1, r10
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080D3846
	adds r0, r4, 0
	bl MetatileBehavior_IsAsh
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D3856
_080D3846:
	adds r0, r5, 0x6
	add r0, r9
	ldr r3, =gUnknown_03001108
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	str r0, [sp, 0x10]
_080D3856:
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	ldr r2, [sp, 0x14]
	asrs r1, r2, 16
	bl MapGridIsImpassableAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D3890
	adds r0, r7, r6
	adds r0, r5
	mov r3, sp
	adds r1, r3, r0
	b _080D38C4
	.pool
_080D3890:
	adds r0, r7, r6
	adds r0, r5
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl MetatileBehavior_IsCuttableGrass
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080D38C8
	adds r0, r5, 0x6
	add r0, r9
	ldr r3, =gUnknown_03001108
	adds r0, r3
	strb r1, [r0]
	b _080D38C8
	.pool
_080D38BC:
	adds r0, r7, r6
	adds r0, r5
	mov r4, sp
	adds r1, r4, r0
_080D38C4:
	movs r0, 0
	strb r0, [r1]
_080D38C8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _080D37F6
	ldr r1, [sp, 0x18]
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bhi _080D38DE
	b _080D37D6
_080D38DE:
	ldr r2, [sp, 0xC]
	cmp r2, 0x34
	beq _080D38EE
	ldr r3, [sp, 0x10]
	cmp r3, 0x1
	beq _080D38EC
	b _080D3A2A
_080D38EC:
	b _080D3A1E
_080D38EE:
	movs r6, 0
	ldr r4, =gUnknown_0203AB40
	mov r9, r4
	ldr r0, =gUnknown_0857C608
	mov r10, r0
_080D38F8:
	lsls r2, r6, 2
	mov r3, r10
	adds r1, r2, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	mov r4, r9
	ldrh r4, [r4]
	adds r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	movs r0, 0x1
	ldrsb r0, [r1, r0]
	mov r1, r9
	ldrh r1, [r1, 0x2]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r7, 0x1
	movs r5, 0
	ldr r3, =gUnknown_0857C60A
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r6, 0x1
	str r6, [sp, 0x18]
	adds r6, r2, 0
	cmp r0, 0
	beq _080D395A
_080D3930:
	adds r1, r2, 0
	adds r0, r5, r2
	adds r0, r3
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D39F4
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bhi _080D395A
	adds r0, r5, r1
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080D3930
_080D395A:
	cmp r7, 0x1
	bne _080D3A0C
	mov r1, r8
	lsls r0, r1, 16
	asrs r5, r0, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	mov r2, r9
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	cmp r0, r1
	bne _080D3A0C
	mov r3, r10
	adds r2, r6, r3
	movs r1, 0x1
	ldrsb r1, [r2, r1]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, 0xC
	ldrb r2, [r2]
	adds r0, r2
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080D39BC
	adds r0, r4, 0
	bl MetatileBehavior_IsAsh
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080D39F8
_080D39BC:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_ruin_valley
	str r0, [r1]
	ldr r0, =gUnknown_03001108
	adds r0, r6, r0
	strb r7, [r0]
	movs r4, 0x1
	str r4, [sp, 0x10]
	b _080D3A0C
	.pool
_080D39F4:
	movs r7, 0
	b _080D395A
_080D39F8:
	adds r0, r4, 0
	bl MetatileBehavior_IsCuttableGrass
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080D3A0C
	ldr r0, =gUnknown_03001108
	adds r0, r6, r0
	strb r1, [r0]
_080D3A0C:
	ldr r1, [sp, 0x18]
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0xF
	bhi _080D3A18
	b _080D38F8
_080D3A18:
	ldr r2, [sp, 0x10]
	cmp r2, 0x1
	bne _080D3A2A
_080D3A1E:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_ruin_valley
	str r0, [r1]
_080D3A2A:
	ldr r0, [sp, 0x10]
_080D3A2C:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D3718

	thumb_func_start hm2_ruin_valley
hm2_ruin_valley: @ 80D3A50
	push {lr}
	movs r0, 0x1
	bl FieldEffectStart
	bl brm_get_pokemon_selection
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_ruin_valley

	thumb_func_start sub_80D3A6C
sub_80D3A6C: @ 80D3A6C
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_80D3AEC
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0x12
	bl IncrementGameStat
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D3A6C

	thumb_func_start sub_80D3A9C
sub_80D3A9C: @ 80D3A9C
	push {lr}
	bl brm_get_pokemon_selection
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =gUnknown_08290705
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D3A9C

	thumb_func_start sub_80D3ABC
sub_80D3ABC: @ 80D3ABC
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_80D4354
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0x12
	bl IncrementGameStat
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D3ABC

	thumb_func_start sub_80D3AEC
sub_80D3AEC: @ 80D3AEC
	push {lr}
	movs r0, 0x1
	bl FieldEffectActiveListRemove
	movs r0, 0x3A
	bl FieldEffectStart
	pop {r0}
	bx r0
	thumb_func_end sub_80D3AEC

	thumb_func_start sub_80D3B00
sub_80D3B00: @ 80D3B00
	push {r4-r7,lr}
	movs r6, 0
	movs r0, 0x80
	bl PlaySE
	ldr r4, =gUnknown_0203AB40
	adds r1, r4, 0x2
	adds r0, r4, 0
	bl PlayerGetDestCoords
	adds r7, r4, 0
_080D3B16:
	ldr r0, =gUnknown_03001108
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D3B64
	adds r0, r6, 0
	movs r1, 0x5
	bl __umodsi3
	adds r4, r0, 0
	subs r4, 0x2
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x5
	bl __udivsi3
	adds r5, r0, 0
	subs r5, 0x2
	lsls r4, 24
	asrs r4, 24
	ldrh r0, [r7]
	adds r4, r0
	lsls r5, 24
	asrs r5, 24
	ldrh r2, [r7, 0x2]
	adds r5, r2
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80D3C10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808E75C
_080D3B64:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x18
	bls _080D3B16
	ldr r2, =gUnknown_0203AB40
	ldr r0, =gUnknown_03001101
	ldrb r1, [r0]
	ldrh r0, [r2]
	subs r0, r1
	lsls r0, 16
	asrs r0, 16
	ldr r1, =gUnknown_03001102
	ldrb r1, [r1]
	mvns r1, r1
	ldrh r2, [r2, 0x2]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	bl sub_80D3D5C
	bl DrawWholeMapView
	ldr r4, =gUnknown_02039DD0
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	movs r6, 0
	ldr r5, =gSprites
_080D3BA0:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x2]
	lsls r1, 23
	lsrs r1, 7
	movs r2, 0x80
	lsls r2, 12
	adds r1, r2
	asrs r1, 16
	ldrb r2, [r0]
	adds r2, 0x14
	ldr r0, =gUnknown_0857C66C
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, r6
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	lsls r1, r6, 5
	strh r1, [r0, 0x32]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x7
	bls _080D3BA0
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D3B00

	thumb_func_start sub_80D3C10
sub_80D3C10: @ 80D3C10
	push {r4-r7,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r6, r0, 16
	asrs r4, r0, 16
	lsrs r7, r1, 16
	asrs r5, r1, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x00000207
	cmp r1, r0
	bgt _080D3C5C
	subs r0, 0x1
	cmp r1, r0
	bge _080D3CD4
	cmp r1, 0x25
	beq _080D3CF6
	cmp r1, 0x25
	bgt _080D3C4C
	cmp r1, 0xD
	beq _080D3C9C
	cmp r1, 0x15
	beq _080D3C9C
	b _080D3D00
	.pool
_080D3C4C:
	movs r0, 0xE3
	lsls r0, 1
	cmp r1, r0
	beq _080D3CAC
	adds r0, 0x1
	cmp r1, r0
	beq _080D3CB2
	b _080D3D00
_080D3C5C:
	ldr r0, =0x00000212
	cmp r1, r0
	beq _080D3CE4
	cmp r1, r0
	bgt _080D3C78
	subs r0, 0xA
	cmp r1, r0
	beq _080D3C9C
	adds r0, 0x2
	cmp r1, r0
	beq _080D3CE4
	b _080D3D00
	.pool
_080D3C78:
	ldr r0, =0x00000282
	cmp r1, r0
	beq _080D3CC4
	cmp r1, r0
	bgt _080D3C90
	subs r0, 0x1
	cmp r1, r0
	beq _080D3CBC
	b _080D3D00
	.pool
_080D3C90:
	ldr r0, =0x00000283
	cmp r1, r0
	beq _080D3CCC
	b _080D3D00
	.pool
_080D3C9C:
	lsls r0, r6, 16
	asrs r0, 16
	lsls r1, r7, 16
	asrs r1, 16
	movs r2, 0x1
	bl MapGridSetMetatileIdAt
	b _080D3D00
_080D3CAC:
	movs r2, 0xE7
	lsls r2, 1
	b _080D3CD6
_080D3CB2:
	ldr r2, =0x000001cf
	b _080D3CD6
	.pool
_080D3CBC:
	ldr r2, =0x00000279
	b _080D3CD6
	.pool
_080D3CC4:
	ldr r2, =0x0000027a
	b _080D3CD6
	.pool
_080D3CCC:
	ldr r2, =0x0000027b
	b _080D3CD6
	.pool
_080D3CD4:
	ldr r2, =0x00000271
_080D3CD6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _080D3D00
	.pool
_080D3CE4:
	lsls r0, r6, 16
	asrs r0, 16
	lsls r1, r7, 16
	asrs r1, 16
	movs r2, 0x86
	lsls r2, 2
	bl MapGridSetMetatileIdAt
	b _080D3D00
_080D3CF6:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xE
	bl MapGridSetMetatileIdAt
_080D3D00:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D3C10

	thumb_func_start sub_80D3D08
sub_80D3D08: @ 80D3D08
	push {lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	cmp r1, 0x1
	bne _080D3D24
	movs r0, 0x1
	b _080D3D56
_080D3D24:
	ldr r0, =0x00000279
	cmp r1, r0
	bne _080D3D34
	movs r0, 0x2
	b _080D3D56
	.pool
_080D3D34:
	ldr r0, =0x0000027a
	cmp r1, r0
	bne _080D3D44
	movs r0, 0x3
	b _080D3D56
	.pool
_080D3D44:
	ldr r0, =0x0000027b
	cmp r2, r0
	beq _080D3D54
	movs r0, 0
	b _080D3D56
	.pool
_080D3D54:
	movs r0, 0x4
_080D3D56:
	pop {r1}
	bx r1
	thumb_func_end sub_80D3D08

	thumb_func_start sub_80D3D5C
sub_80D3D5C: @ 80D3D5C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	ldr r1, =gUnknown_03001100
	ldrb r2, [r1]
	mov r3, r10
	adds r0, r2, r3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	movs r4, 0
	cmp r4, r2
	blt _080D3D8A
	b _080D3EA0
_080D3D8A:
	lsls r0, r3, 16
	asrs r7, r0, 16
_080D3D8E:
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	lsls r4, 16
	asrs r1, r4, 16
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	asrs r5, r0, 16
	adds r0, r5, 0
	adds r1, r7, 0
	bl MapGridGetMetatileIdAt
	mov r8, r4
	cmp r0, 0x15
	bne _080D3E12
	adds r4, r7, 0x1
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r5, 0
	bl sub_80D3D08
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080D3DE8
	cmp r0, 0x2
	bgt _080D3DD0
	cmp r0, 0x1
	beq _080D3DDA
	b _080D3E12
	.pool
_080D3DD0:
	cmp r0, 0x3
	beq _080D3DF8
	cmp r0, 0x4
	beq _080D3E08
	b _080D3E12
_080D3DDA:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x82
	lsls r2, 2
	bl MapGridSetMetatileIdAt
	b _080D3E12
_080D3DE8:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x00000281
	bl MapGridSetMetatileIdAt
	b _080D3E12
	.pool
_080D3DF8:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x00000282
	bl MapGridSetMetatileIdAt
	b _080D3E12
	.pool
_080D3E08:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x00000283
	bl MapGridSetMetatileIdAt
_080D3E12:
	lsls r0, r6, 16
	asrs r5, r0, 16
	ldr r3, [sp]
	lsls r0, r3, 16
	asrs r4, r0, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	cmp r0, 0x1
	bne _080D3E8C
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x82
	lsls r1, 2
	cmp r0, r1
	bne _080D3E44
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl MapGridSetMetatileIdAt
_080D3E44:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000281
	cmp r0, r1
	bne _080D3E5C
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x00000279
	bl MapGridSetMetatileIdAt
_080D3E5C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000282
	cmp r0, r1
	bne _080D3E74
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x0000027a
	bl MapGridSetMetatileIdAt
_080D3E74:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000283
	cmp r0, r1
	bne _080D3E8C
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, =0x0000027b
	bl MapGridSetMetatileIdAt
_080D3E8C:
	movs r1, 0x80
	lsls r1, 9
	add r1, r8
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_03001100
	ldrb r0, [r0]
	cmp r1, r0
	bge _080D3EA0
	b _080D3D8E
_080D3EA0:
	ldr r1, =gUnknown_03001100
	ldrb r0, [r1]
	cmp r0, 0x5
	bne _080D3EC8
	mov r3, r9
	lsls r5, r3, 16
	asrs r5, 16
	mov r0, r10
	lsls r4, r0, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80D3EF4
	movs r0, 0x1
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80D3EF4
_080D3EC8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D3D5C

	thumb_func_start sub_80D3EF4
sub_80D3EF4: @ 80D3EF4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	adds r3, r5, 0
	lsls r2, 16
	lsrs r2, 16
	mov r10, r2
	cmp r0, 0
	bne _080D3F2C
	mov r2, sp
	ldr r1, =gUnknown_03001108
	ldrb r0, [r1, 0x5]
	strb r0, [r2]
	ldrb r0, [r1, 0xA]
	strb r0, [r2, 0x1]
	ldrb r0, [r1, 0xF]
	strb r0, [r2, 0x2]
	mov r8, r5
	b _080D3F4E
	.pool
_080D3F2C:
	cmp r0, 0x1
	beq _080D3F32
	b _080D414A
_080D3F32:
	mov r2, sp
	ldr r1, =gUnknown_03001108
	ldrb r0, [r1, 0x9]
	strb r0, [r2]
	ldrb r0, [r1, 0xE]
	strb r0, [r2, 0x1]
	ldrb r0, [r1, 0x13]
	strb r0, [r2, 0x2]
	lsls r0, r3, 16
	movs r1, 0x80
	lsls r1, 11
	adds r0, r1
	lsrs r0, 16
	mov r8, r0
_080D3F4E:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D3FC6
	mov r1, r8
	lsls r0, r1, 16
	asrs r5, r0, 16
	mov r1, r10
	lsls r0, r1, 16
	asrs r0, 16
	adds r4, r0, 0x3
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x82
	lsls r1, 2
	cmp r0, r1
	bne _080D3F7E
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl MapGridSetMetatileIdAt
_080D3F7E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000281
	cmp r0, r1
	bne _080D3F96
	ldr r2, =0x00000279
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D3F96:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000282
	cmp r0, r1
	bne _080D3FAE
	ldr r2, =0x0000027a
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D3FAE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000283
	cmp r0, r1
	bne _080D3FC6
	ldr r2, =0x0000027b
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D3FC6:
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _080D40C0
	mov r0, r8
	lsls r5, r0, 16
	asrs r6, r5, 16
	mov r1, r10
	lsls r4, r1, 16
	asrs r7, r4, 16
	adds r1, r7, 0x2
	adds r0, r6, 0
	bl MapGridGetMetatileIdAt
	mov r9, r4
	cmp r0, 0x15
	bne _080D4056
	adds r4, r7, 0x3
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r6, 0
	bl sub_80D3D08
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080D4034
	cmp r0, 0x2
	bgt _080D4024
	cmp r0, 0x1
	beq _080D402E
	b _080D4056
	.pool
_080D4024:
	cmp r0, 0x3
	beq _080D403C
	cmp r0, 0x4
	beq _080D404C
	b _080D4056
_080D402E:
	movs r2, 0x82
	lsls r2, 2
	b _080D403E
_080D4034:
	ldr r2, =0x00000281
	b _080D403E
	.pool
_080D403C:
	ldr r2, =0x00000282
_080D403E:
	adds r0, r6, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	b _080D4056
	.pool
_080D404C:
	ldr r2, =0x00000283
	adds r0, r6, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D4056:
	asrs r5, 16
	mov r1, r9
	asrs r0, r1, 16
	adds r4, r0, 0x4
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	movs r1, 0x82
	lsls r1, 2
	cmp r0, r1
	bne _080D4078
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl MapGridSetMetatileIdAt
_080D4078:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000281
	cmp r0, r1
	bne _080D4090
	ldr r2, =0x00000279
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D4090:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000282
	cmp r0, r1
	bne _080D40A8
	ldr r2, =0x0000027a
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D40A8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000283
	cmp r0, r1
	bne _080D40C0
	ldr r2, =0x0000027b
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D40C0:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0x1
	bne _080D414A
	mov r1, r8
	lsls r0, r1, 16
	asrs r5, r0, 16
	mov r1, r10
	lsls r0, r1, 16
	asrs r4, r0, 16
	adds r1, r4, 0x3
	adds r0, r5, 0
	bl MapGridGetMetatileIdAt
	cmp r0, 0x15
	bne _080D414A
	adds r4, 0x4
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r5, 0
	bl sub_80D3D08
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080D4128
	cmp r0, 0x2
	bgt _080D4118
	cmp r0, 0x1
	beq _080D4122
	b _080D414A
	.pool
_080D4118:
	cmp r0, 0x3
	beq _080D4130
	cmp r0, 0x4
	beq _080D4140
	b _080D414A
_080D4122:
	movs r2, 0x82
	lsls r2, 2
	b _080D4132
_080D4128:
	ldr r2, =0x00000281
	b _080D4132
	.pool
_080D4130:
	ldr r2, =0x00000282
_080D4132:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	b _080D414A
	.pool
_080D4140:
	ldr r2, =0x00000283
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
_080D414A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D3EF4

	thumb_func_start objc_8097BA8
objc_8097BA8: @ 80D4160
	movs r2, 0
	movs r1, 0x8
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x34]
	ldr r1, =objc_8097BBC
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end objc_8097BA8

	thumb_func_start objc_8097BBC
objc_8097BBC: @ 80D4174
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x2E]
	adds r1, 0x1
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 18
	adds r1, r0
	strh r1, [r4, 0x2E]
	adds r2, 0x1
	strh r2, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x1C
	beq _080D41C0
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _080D41C4
_080D41C0:
	ldr r0, =sub_80D41D0
	str r0, [r4, 0x1C]
_080D41C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end objc_8097BBC

	thumb_func_start sub_80D41D0
sub_80D41D0: @ 80D41D0
	push {r4-r6,lr}
	movs r4, 0x1
_080D41D4:
	ldr r6, =gUnknown_02039DD0
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
	ldr r0, =gUnknown_08267EDB
	bl ScriptContext1_SetupScript
_080D422A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D41D0

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
	bl sub_80D3D08
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

	thumb_func_start sub_80D4354
sub_80D4354: @ 80D4354
	push {lr}
	movs r0, 0x80
	bl PlaySE
	movs r0, 0x2
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80D4354

	.align 2, 0 @ Don't pad with nop.
