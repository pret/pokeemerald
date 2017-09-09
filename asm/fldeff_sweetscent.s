	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
    
	thumb_func_start SetUpFieldMove_SweetScent
SetUpFieldMove_SweetScent: @ 8159EF0
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_sweet_scent
	str r0, [r1]
	movs r0, 0x1
	bx lr
	.pool
	thumb_func_end SetUpFieldMove_SweetScent

	thumb_func_start hm2_sweet_scent
hm2_sweet_scent: @ 8159F10
	push {lr}
	movs r0, 0x33
	bl FieldEffectStart
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_sweet_scent

	thumb_func_start FldEff_SweetScent
FldEff_SweetScent: @ 8159F2C
	push {lr}
	bl sub_80AC3D0
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_8159F5C
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end FldEff_SweetScent

	thumb_func_start sub_8159F5C
sub_8159F5C: @ 8159F5C
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0xEC
	bl PlaySE
	ldr r5, =gPlttBufferUnfaded
	ldr r1, =gPaletteDecompressionBuffer
	movs r4, 0x80
	lsls r4, 1
	adds r0, r5, 0
	adds r2, r4, 0
	bl CpuFastSet
	ldr r0, =gPlttBufferFaded
	adds r1, r5, 0
	adds r2, r4, 0
	bl CpuFastSet
	bl GetPlayerAvatarObjectId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	mvns r0, r0
	movs r1, 0x1F
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0
	movs r3, 0x8
	bl BeginNormalPaletteFade
	ldr r0, =sub_8159FEC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x33
	bl FieldEffectActiveListRemove
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8159F5C

	thumb_func_start sub_8159FEC
sub_8159FEC: @ 8159FEC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0815A088
	bl sub_81BE72C
	movs r0, 0x40
	movs r1, 0x8
	movs r2, 0x1F
	bl BlendPalettes
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r0
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	bne _0815A084
	strh r6, [r4, 0x8]
	bl SweetScentWildEncounter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815A044
	adds r0, r5, 0
	bl DestroyTask
	b _0815A088
	.pool
_0815A044:
	ldr r0, =sub_815A090
	str r0, [r4]
	bl GetPlayerAvatarObjectId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	mvns r0, r0
	movs r1, 0x1F
	str r1, [sp]
	movs r1, 0x4
	movs r2, 0x8
	movs r3, 0
	bl BeginNormalPaletteFade
	bl sub_81BE6B8
	b _0815A088
	.pool
_0815A084:
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
_0815A088:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8159FEC

	thumb_func_start sub_815A090
sub_815A090: @ 815A090
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0815A0BE
	ldr r0, =gPaletteDecompressionBuffer
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 1
	bl CpuFastSet
	bl sub_80AC3E4
	ldr r0, =gUnknown_08290CAE
	bl ScriptContext1_SetupScript
	adds r0, r4, 0
	bl DestroyTask
_0815A0BE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A090

	.align 2, 0 @ Don't pad with nop.
    