	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80F9BCC
sub_80F9BCC: @ 80F9BCC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =sub_80F9C90
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80F9C44
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9BCC

	thumb_func_start sub_80F9BF4
sub_80F9BF4: @ 80F9BF4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =sub_80F9DFC
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80F9C44
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9BF4

	thumb_func_start sub_80F9C1C
sub_80F9C1C: @ 80F9C1C
	push {lr}
	ldr r0, =sub_80F9C90
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F9C1C

	thumb_func_start sub_80F9C30
sub_80F9C30: @ 80F9C30
	push {lr}
	ldr r0, =sub_80F9DFC
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80F9C30

	thumb_func_start sub_80F9C44
sub_80F9C44: @ 80F9C44
	push {r4,r5,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	adds r5, r4, 0
	lsls r3, 24
	lsrs r3, 24
	adds r1, r3, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x10
	cmp r4, 0
	beq _080F9C72
	adds r0, r4, 0
_080F9C72:
	strh r0, [r1, 0xA]
	movs r0, 0x14
	cmp r5, 0
	beq _080F9C7C
	adds r0, r5, 0
_080F9C7C:
	strh r0, [r1, 0xC]
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9C44

	thumb_func_start sub_80F9C90
sub_80F9C90: @ 80F9C90
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
	beq _080F9D10
	cmp r0, 0x1
	bgt _080F9CB8
	cmp r0, 0
	beq _080F9CC2
	b _080F9DDE
	.pool
_080F9CB8:
	cmp r0, 0x2
	beq _080F9D32
	cmp r0, 0x3
	beq _080F9D94
	b _080F9DDE
_080F9CC2:
	movs r0, 0x78
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	movs r0, 0x50
	strh r0, [r4, 0x12]
	movs r0, 0x51
	strh r0, [r4, 0x14]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0x10]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x40
	bl SetGpuReg
	ldrh r1, [r4, 0x12]
	lsls r1, 8
	ldrh r0, [r4, 0x14]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	b _080F9DEE
_080F9D10:
	movs r0, 0x50
	bl GetGpuReg
	strh r0, [r4, 0x16]
	movs r0, 0x54
	bl GetGpuReg
	strh r0, [r4, 0x18]
	movs r0, 0x50
	movs r1, 0xBF
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x10
	bl SetGpuReg
	b _080F9DEE
_080F9D32:
	ldrh r0, [r4, 0xE]
	ldrh r1, [r4, 0xA]
	subs r0, r1
	movs r5, 0
	strh r0, [r4, 0xE]
	ldrh r2, [r4, 0x10]
	adds r1, r2
	strh r1, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	ble _080F9D50
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xEF
	ble _080F9D76
_080F9D50:
	strh r5, [r4, 0xE]
	movs r0, 0xF0
	strh r0, [r4, 0x10]
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4, 0x16]
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	movs r2, 0
	bl BlendPalettes
	ldr r0, =gPlttBufferFaded
	strh r5, [r0]
_080F9D76:
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0x10]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x40
	bl SetGpuReg
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	b _080F9DD8
	.pool
_080F9D94:
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0xC]
	subs r0, r1
	strh r0, [r4, 0x12]
	ldrh r2, [r4, 0x14]
	adds r1, r2
	strh r1, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	ble _080F9DB0
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _080F9DC2
_080F9DB0:
	movs r0, 0
	strh r0, [r4, 0x12]
	movs r0, 0xA0
	strh r0, [r4, 0x14]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
_080F9DC2:
	ldrh r1, [r4, 0x12]
	lsls r1, 8
	ldrh r0, [r4, 0x14]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	movs r1, 0x12
	ldrsh r0, [r4, r1]
_080F9DD8:
	cmp r0, 0
	bne _080F9DF4
	b _080F9DEE
_080F9DDE:
	ldrh r1, [r4, 0x16]
	movs r0, 0x50
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	b _080F9DF4
_080F9DEE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080F9DF4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F9C90

	thumb_func_start sub_80F9DFC
sub_80F9DFC: @ 80F9DFC
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
	beq _080F9E38
	cmp r1, 0x1
	bgt _080F9E24
	cmp r1, 0
	beq _080F9E2E
	b _080F9F2C
	.pool
_080F9E24:
	cmp r1, 0x2
	beq _080F9E86
	cmp r1, 0x3
	beq _080F9ED8
	b _080F9F2C
_080F9E2E:
	ldr r0, =gPlttBufferFaded
	strh r1, [r0]
	b _080F9F4E
	.pool
_080F9E38:
	movs r1, 0
	strh r1, [r4, 0xE]
	movs r0, 0xF0
	strh r0, [r4, 0x10]
	strh r1, [r4, 0x12]
	movs r0, 0xA0
	strh r0, [r4, 0x14]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0x10]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x40
	bl SetGpuReg
	ldrh r1, [r4, 0x12]
	lsls r1, 8
	ldrh r0, [r4, 0x14]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	b _080F9F4E
_080F9E86:
	ldrh r0, [r4, 0xC]
	ldrh r2, [r4, 0x12]
	adds r1, r0, r2
	strh r1, [r4, 0x12]
	ldrh r2, [r4, 0x14]
	subs r0, r2, r0
	strh r0, [r4, 0x14]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x4F
	bgt _080F9EA4
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bgt _080F9EBC
_080F9EA4:
	movs r0, 0x50
	strh r0, [r4, 0x12]
	movs r0, 0x51
	strh r0, [r4, 0x14]
	movs r0, 0x50
	movs r1, 0xBF
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x10
	bl SetGpuReg
_080F9EBC:
	ldrh r1, [r4, 0x12]
	lsls r1, 8
	ldrh r0, [r4, 0x14]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x50
	bne _080F9F54
	b _080F9F4E
_080F9ED8:
	ldrh r0, [r4, 0xA]
	ldrh r2, [r4, 0xE]
	adds r1, r0, r2
	strh r1, [r4, 0xE]
	ldrh r2, [r4, 0x10]
	subs r0, r2, r0
	strh r0, [r4, 0x10]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x77
	bgt _080F9EF6
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x78
	bgt _080F9F0C
_080F9EF6:
	movs r0, 0x78
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	subs r0, 0x79
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r1, =gPlttBufferFaded
	movs r0, 0
	strh r0, [r1]
_080F9F0C:
	ldrh r1, [r4, 0xE]
	lsls r1, 8
	ldrh r0, [r4, 0x10]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x40
	bl SetGpuReg
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	bne _080F9F54
	b _080F9F4E
	.pool
_080F9F2C:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	b _080F9F54
_080F9F4E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080F9F54:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80F9DFC

	thumb_func_start sub_80F9F5C
sub_80F9F5C: @ 80F9F5C
	push {lr}
	ldr r0, =gUnknown_0203AB40
	ldr r1, =gMapHeader
	ldr r1, [r1, 0x4]
	bl sub_80E9608
	bl sub_80E8B6C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80F9F5C

	thumb_func_start sub_80F9F78
sub_80F9F78: @ 80F9F78
	push {lr}
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	beq _080F9FC0
	ldr r1, =gFieldEffectArguments
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _080F9FAE
	cmp r0, 0x2
	bgt _080F9FA0
	cmp r0, 0x1
	beq _080F9FA6
	b _080F9FFE
	.pool
_080F9FA0:
	cmp r0, 0x3
	beq _080F9FB6
	b _080F9FDC
_080F9FA6:
	movs r0, 0x10
	str r0, [r1, 0x14]
	movs r0, 0x28
	b _080F9FFC
_080F9FAE:
	movs r0, 0x10
	str r0, [r1, 0x14]
	movs r0, 0x8
	b _080F9FFC
_080F9FB6:
	movs r0, 0x8
	negs r0, r0
	str r0, [r1, 0x14]
	movs r0, 0x18
	b _080F9FFC
_080F9FC0:
	ldr r1, =gFieldEffectArguments
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _080F9FEA
	cmp r0, 0x2
	bgt _080F9FD8
	cmp r0, 0x1
	beq _080F9FE2
	b _080F9FFE
	.pool
_080F9FD8:
	cmp r0, 0x3
	beq _080F9FEE
_080F9FDC:
	cmp r0, 0x4
	beq _080F9FF8
	b _080F9FFE
_080F9FE2:
	movs r0, 0x8
	str r0, [r1, 0x14]
	movs r0, 0x28
	b _080F9FFC
_080F9FEA:
	movs r0, 0x8
	b _080F9FFA
_080F9FEE:
	movs r0, 0x8
	negs r0, r0
	str r0, [r1, 0x14]
	movs r0, 0x18
	b _080F9FFC
_080F9FF8:
	movs r0, 0x18
_080F9FFA:
	str r0, [r1, 0x14]
_080F9FFC:
	str r0, [r1, 0x18]
_080F9FFE:
	pop {r0}
	bx r0
	thumb_func_end sub_80F9F78

	thumb_func_start sub_80FA004
sub_80FA004: @ 80FA004
	push {r4,lr}
	bl sub_80E8BC8
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _080FA0AE
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080FA0AE
	ldr r4, =gUnknown_0203AB40
	adds r1, r4, 0x2
	adds r0, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseCave
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FA070
	bl sub_80F9F5C
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_80FA0DC
	b _080FA0C0
	.pool
_080FA070:
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseTree
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FA0A0
	bl sub_80F9F5C
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_80FA1E8
	b _080FA0C0
	.pool
_080FA0A0:
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseShrub
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080FA0B2
_080FA0AE:
	movs r0, 0
	b _080FA0C4
_080FA0B2:
	bl sub_80F9F5C
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_80FA34C
_080FA0C0:
	str r0, [r1]
	movs r0, 0x1
_080FA0C4:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA004

	thumb_func_start sub_80FA0DC
sub_80FA0DC: @ 80FA0DC
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =EventScript_275A86
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA0DC

	thumb_func_start oei_sweet_scent
oei_sweet_scent: @ 80FA0FC
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_80FA128
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_sweet_scent

	thumb_func_start sub_80FA128
sub_80FA128: @ 80FA128
	push {lr}
	movs r0, 0xB
	bl FieldEffectActiveListRemove
	movs r0, 0x37
	bl FieldEffectStart
	pop {r0}
	bx r0
	thumb_func_end sub_80FA128

	thumb_func_start sub_80FA13C
sub_80FA13C: @ 80FA13C
	push {r4,lr}
	bl sub_80F9F78
	ldr r0, =gUnknown_0858E600
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 23
	ldr r4, =gFieldEffectArguments
	ldr r3, [r4, 0x14]
	adds r1, r3
	lsls r1, 16
	asrs r1, 16
	ldrb r2, [r2]
	ldr r3, [r4, 0x18]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x94
	bl CreateSprite
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA13C

	thumb_func_start sub_80FA18C
sub_80FA18C: @ 80FA18C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x83
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FA1A8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA18C

	thumb_func_start sub_80FA1A8
sub_80FA1A8: @ 80FA1A8
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r1, r3]
	cmp r0, 0x27
	bgt _080FA1C8
	adds r0, r2, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _080FA1D0
	bl sub_80E8D4C
	b _080FA1D0
_080FA1C8:
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, =sub_80FA1D8
	str r0, [r1, 0x1C]
_080FA1D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA1A8

	thumb_func_start sub_80FA1D8
sub_80FA1D8: @ 80FA1D8
	push {lr}
	movs r1, 0x37
	bl FieldEffectStop
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80FA1D8

	thumb_func_start sub_80FA1E8
sub_80FA1E8: @ 80FA1E8
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =EventScript_275ADF
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA1E8

	thumb_func_start sub_80FA208
sub_80FA208: @ 80FA208
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_80FA234
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA208

	thumb_func_start sub_80FA234
sub_80FA234: @ 80FA234
	push {lr}
	movs r0, 0x1A
	bl FieldEffectActiveListRemove
	movs r0, 0x38
	bl FieldEffectStart
	pop {r0}
	bx r0
	thumb_func_end sub_80FA234

	thumb_func_start sub_80FA248
sub_80FA248: @ 80FA248
	push {r4,lr}
	ldr r1, =gUnknown_0203AB40
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl MapGridGetMetatileBehaviorAt
	adds r2, r0, 0
	ldr r1, =0x00000fff
	adds r0, r1, 0
	ands r2, r0
	cmp r2, 0x96
	bne _080FA26A
	ldr r1, =gFieldEffectArguments
	movs r0, 0
	str r0, [r1, 0x1C]
_080FA26A:
	cmp r2, 0x9C
	bne _080FA274
	ldr r1, =gFieldEffectArguments
	movs r0, 0x2
	str r0, [r1, 0x1C]
_080FA274:
	bl sub_80F9F78
	ldr r0, =gUnknown_0858E618
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 23
	ldr r4, =gFieldEffectArguments
	ldr r3, [r4, 0x14]
	adds r1, r3
	lsls r1, 16
	asrs r1, 16
	ldrb r2, [r2]
	ldr r3, [r4, 0x18]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x94
	bl CreateSprite
	ldr r0, [r4, 0x1C]
	cmp r0, 0x1
	beq _080FA2B2
	cmp r0, 0x3
	bne _080FA2B6
_080FA2B2:
	bl sub_80E8D4C
_080FA2B6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA248

	thumb_func_start sub_80FA2D8
sub_80FA2D8: @ 80FA2D8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x9B
	bl PlaySE
	ldr r0, =gFieldEffectArguments
	ldr r1, [r0, 0x1C]
	adds r2, r4, 0
	adds r2, 0x2A
	movs r0, 0
	strb r1, [r2]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FA304
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA2D8

	thumb_func_start sub_80FA304
sub_80FA304: @ 80FA304
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _080FA32E
	ldr r0, =gFieldEffectArguments
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	beq _080FA322
	cmp r0, 0x2
	bne _080FA326
_080FA322:
	bl sub_80E8D4C
_080FA326:
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FA33C
	str r0, [r4, 0x1C]
_080FA32E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA304

	thumb_func_start sub_80FA33C
sub_80FA33C: @ 80FA33C
	push {lr}
	movs r1, 0x38
	bl FieldEffectStop
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80FA33C

	thumb_func_start sub_80FA34C
sub_80FA34C: @ 80FA34C
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =EventScript_275B38
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA34C

	thumb_func_start sub_80FA36C
sub_80FA36C: @ 80FA36C
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_80FA398
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA36C

	thumb_func_start sub_80FA398
sub_80FA398: @ 80FA398
	push {lr}
	movs r0, 0x1B
	bl FieldEffectActiveListRemove
	movs r0, 0x39
	bl FieldEffectStart
	pop {r0}
	bx r0
	thumb_func_end sub_80FA398

	thumb_func_start sub_80FA3AC
sub_80FA3AC: @ 80FA3AC
	push {r4,lr}
	bl sub_80F9F78
	ldr r0, =gUnknown_0858E630
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 23
	ldr r4, =gFieldEffectArguments
	ldr r3, [r4, 0x14]
	adds r1, r3
	lsls r1, 16
	asrs r1, 16
	ldrb r2, [r2]
	ldr r3, [r4, 0x18]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x94
	bl CreateSprite
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA3AC

	thumb_func_start sub_80FA3FC
sub_80FA3FC: @ 80FA3FC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xA9
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80FA418
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA3FC

	thumb_func_start sub_80FA418
sub_80FA418: @ 80FA418
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r1, r3]
	cmp r0, 0x27
	bgt _080FA438
	adds r0, r2, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _080FA440
	bl sub_80E8D4C
	b _080FA440
_080FA438:
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, =sub_80FA448
	str r0, [r1, 0x1C]
_080FA440:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA418

	thumb_func_start sub_80FA448
sub_80FA448: @ 80FA448
	push {lr}
	movs r1, 0x39
	bl FieldEffectStop
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80FA448

	thumb_func_start sub_80FA458
sub_80FA458: @ 80FA458
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldr r0, =sub_80FA4A0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	strh r0, [r1, 0x8]
	ldrh r0, [r4]
	strh r0, [r1, 0xA]
	strh r2, [r1, 0xC]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FA458

	thumb_func_start sub_80FA4A0
sub_80FA4A0: @ 80FA4A0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x4]
	subs r0, 0x4
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bhi _080FA56E
	lsls r0, 2
	ldr r1, =_080FA4D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FA4D0:
	.4byte _080FA514
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA522
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA514
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA522
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA56E
	.4byte _080FA540
_080FA514:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r2, 0x89
	lsls r2, 2
	b _080FA52E
_080FA522:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r2, 0x88
	lsls r2, 2
_080FA52E:
	bl MapGridSetMetatileIdAt
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	b _080FA56E
_080FA540:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	movs r2, 0x89
	lsls r2, 2
	bl MapGridSetMetatileIdAt
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	movs r0, 0x3D
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	adds r0, r5, 0
	bl DestroyTask
	b _080FA574
_080FA56E:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
_080FA574:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FA4A0

	thumb_func_start sub_80FA57C
sub_80FA57C: @ 80FA57C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r0, 0x3
	bl PlaySE
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _080FA5B8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r2, 0xE2
	lsls r2, 4
	bl MapGridSetMetatileIdAt
	b _080FA5C8
	.pool
_080FA5B8:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldr r2, =0x00000e21
	bl MapGridSetMetatileIdAt
_080FA5C8:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA57C

	thumb_func_start sub_80FA5E4
sub_80FA5E4: @ 80FA5E4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =sub_80FA62C
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
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xA]
	strh r6, [r1, 0xC]
	strh r0, [r1, 0xE]
	movs r0, 0x1
	strh r0, [r1, 0x10]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA5E4

	thumb_func_start sub_80FA62C
sub_80FA62C: @ 80FA62C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r1, [r4, 0x6]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0x6
	bne _080FA650
	movs r0, 0
	b _080FA652
	.pool
_080FA650:
	adds r0, r1, 0x1
_080FA652:
	strh r0, [r4, 0x6]
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _080FA6A4
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x2
	bne _080FA66C
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl sub_80FA6AC
_080FA66C:
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, 0x8]
	ldrh r3, [r4]
	adds r2, r3
	lsls r2, 16
	lsrs r2, 16
	bl MapGridSetMetatileIdAt
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	ldrh r1, [r4, 0x8]
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	cmp r0, 0x3
	bne _080FA6A0
	adds r0, r5, 0
	bl DestroyTask
	b _080FA6A4
_080FA6A0:
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
_080FA6A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FA62C

	thumb_func_start sub_80FA6AC
sub_80FA6AC: @ 80FA6AC
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0xCE
	lsls r0, 2
	cmp r1, r0
	beq _080FA6D8
	cmp r1, r0
	bgt _080FA6C8
	movs r0, 0x8A
	lsls r0, 2
	cmp r1, r0
	beq _080FA6F0
	b _080FA6F6
_080FA6C8:
	movs r0, 0xCF
	lsls r0, 2
	cmp r1, r0
	beq _080FA6E0
	adds r0, 0x4
	cmp r1, r0
	beq _080FA6E8
	b _080FA6F6
_080FA6D8:
	movs r0, 0x4A
	bl PlaySE
	b _080FA6F6
_080FA6E0:
	movs r0, 0x4B
	bl PlaySE
	b _080FA6F6
_080FA6E8:
	movs r0, 0x4C
	bl PlaySE
	b _080FA6F6
_080FA6F0:
	movs r0, 0x4E
	bl PlaySE
_080FA6F6:
	pop {r0}
	bx r0
	thumb_func_end sub_80FA6AC

	thumb_func_start sub_80FA6FC
sub_80FA6FC: @ 80FA6FC
	movs r0, 0
	bx lr
	thumb_func_end sub_80FA6FC

	thumb_func_start sub_80FA700
sub_80FA700: @ 80FA700
	movs r0, 0
	bx lr
	thumb_func_end sub_80FA700

	thumb_func_start sub_80FA704
sub_80FA704: @ 80FA704
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x4D
	bl PlaySE
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	ldr r2, =0x00000276
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	subs r6, r4, 0x1
	ldr r2, =0x0000026e
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0
	adds r1, r4, 0
	bl CurrentMapDrawMetatileAt
	adds r0, r5, 0
	adds r1, r6, 0
	bl CurrentMapDrawMetatileAt
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA704

	thumb_func_start sub_80FA754
sub_80FA754: @ 80FA754
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x8]
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	cmp r0, 0x7
	bne _080FA788
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	movs r3, 0xC
	ldrsh r1, [r1, r3]
	bl sub_80FA704
	adds r0, r4, 0
	bl DestroyTask
	b _080FA78C
	.pool
_080FA788:
	adds r0, r2, 0x1
	strh r0, [r1, 0x8]
_080FA78C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FA754

	thumb_func_start sub_80FA794
sub_80FA794: @ 80FA794
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	adds r7, r5, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r6, r4, 0
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FA7BC
	lsls r0, r5, 16
	asrs r0, 16
	lsls r1, r4, 16
	asrs r1, 16
	bl sub_80FA704
	b _080FA7DE
_080FA7BC:
	cmp r0, 0x2
	bne _080FA7DE
	ldr r0, =sub_80FA754
	movs r1, 0x5
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
	strh r7, [r1, 0xA]
	strh r6, [r1, 0xC]
_080FA7DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA794

	thumb_func_start sub_80FA7EC
sub_80FA7EC: @ 80FA7EC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0x7
	beq _080FA808
	b _080FA966
_080FA808:
	ldr r2, =0xfffffd88
	adds r0, r2, 0
	ldrh r1, [r1, 0x8]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3B
	bls _080FA81A
	b _080FA95E
_080FA81A:
	lsls r0, 2
	ldr r1, =_080FA830
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FA830:
	.4byte _080FA920
	.4byte _080FA928
	.4byte _080FA930
	.4byte _080FA938
	.4byte _080FA940
	.4byte _080FA948
	.4byte _080FA950
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA95E
	.4byte _080FA958
_080FA920:
	movs r0, 0x3E
	bl PlaySE
	b _080FA95E
_080FA928:
	movs r0, 0x3F
	bl PlaySE
	b _080FA95E
_080FA930:
	movs r0, 0x40
	bl PlaySE
	b _080FA95E
_080FA938:
	movs r0, 0x41
	bl PlaySE
	b _080FA95E
_080FA940:
	movs r0, 0x42
	bl PlaySE
	b _080FA95E
_080FA948:
	movs r0, 0x43
	bl PlaySE
	b _080FA95E
_080FA950:
	movs r0, 0x44
	bl PlaySE
	b _080FA95E
_080FA958:
	movs r0, 0x45
	bl PlaySE
_080FA95E:
	adds r0, r4, 0
	bl DestroyTask
	b _080FA96A
_080FA966:
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
_080FA96A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FA7EC

	thumb_func_start sub_80FA970
sub_80FA970: @ 80FA970
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =sub_80FA7EC
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x8]
	strh r0, [r1, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA970

	thumb_func_start sub_80FA9A4
sub_80FA9A4: @ 80FA9A4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _080FA9BC
	movs r0, 0xC3
	bl PlaySE
_080FA9BC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1F
	ble _080FA9CA
	adds r0, r4, 0
	bl DestroySprite
_080FA9CA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FA9A4

	thumb_func_start sub_80FA9D0
sub_80FA9D0: @ 80FA9D0
	push {r4,lr}
	sub sp, 0x4
	ldr r3, =gMapObjects
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x4
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x58]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080FAA5E
	ldr r3, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r4, r2, r3
	movs r0, 0x3E
	adds r0, r4
	mov r12, r0
	ldrb r0, [r0]
	movs r1, 0x2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x50
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r3, 0x1C
	adds r2, r3
	ldr r0, =sub_80FA9A4
	str r0, [r2]
	movs r0, 0
	strh r0, [r4, 0x2E]
_080FAA5E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FA9D0

	thumb_func_start sub_80FAA7C
sub_80FAA7C: @ 80FAA7C
	push {r4,lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldr r1, =gFieldEffectArguments
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	str r0, [r1, 0x14]
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [r1, 0x18]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080FAAFC
	cmp r0, 0x2
	bgt _080FAABC
	cmp r0, 0x1
	beq _080FAAC6
	b _080FAB8C
	.pool
_080FAABC:
	cmp r0, 0x3
	beq _080FAB2C
	cmp r0, 0x4
	beq _080FAB64
	b _080FAB8C
_080FAAC6:
	ldr r0, =gUnknown_0858E68C
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 7
	movs r3, 0x80
	lsls r3, 12
	adds r1, r3
	asrs r1, 16
	ldrb r2, [r2]
	adds r2, 0x20
	movs r3, 0
	bl CreateSprite
	b _080FAB8C
	.pool
_080FAAFC:
	ldr r0, =gUnknown_0858E68C
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 7
	movs r3, 0x80
	lsls r3, 12
	adds r1, r3
	asrs r1, 16
	ldrb r2, [r2]
	b _080FAB4C
	.pool
_080FAB2C:
	ldr r0, =gUnknown_0858E68C
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 7
	ldr r3, =0xfff80000
	adds r1, r3
	asrs r1, 16
	ldrb r2, [r2]
	adds r2, 0x10
_080FAB4C:
	movs r3, 0x94
	bl CreateSprite
	b _080FAB8C
	.pool
_080FAB64:
	ldr r0, =gUnknown_0858E68C
	ldr r3, =gSprites
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x4]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r2, 0x2]
	lsls r1, 23
	lsrs r1, 7
	movs r3, 0xC0
	lsls r3, 13
	adds r1, r3
	asrs r1, 16
	ldrb r2, [r2]
	adds r2, 0x10
	movs r3, 0x94
	bl CreateSprite
_080FAB8C:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FAA7C

	thumb_func_start door_restore_tilemap
door_restore_tilemap: @ 80FABA4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x83
	bl PlaySE
	ldr r4, =gFieldEffectArguments
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	subs r1, 0x1
	bl MapGridGetMetatileIdAt
	ldr r1, =0x00000286
	cmp r0, r1
	bne _080FABDC
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	subs r1, 0x1
	ldr r2, =0x00000e02
	bl MapGridSetMetatileIdAt
	b _080FABEA
	.pool
_080FABDC:
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	subs r1, 0x1
	movs r2, 0xA1
	lsls r2, 2
	bl MapGridSetMetatileIdAt
_080FABEA:
	ldr r4, =gFieldEffectArguments
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	ldr r2, =0x0000020a
	bl MapGridSetMetatileIdAt
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	subs r1, 0x1
	bl CurrentMapDrawMetatileAt
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	bl CurrentMapDrawMetatileAt
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80FAC24
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end door_restore_tilemap

	thumb_func_start sub_80FAC24
sub_80FAC24: @ 80FAC24
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x11
	bgt _080FAC38
	adds r0, r1, 0x1
	strh r0, [r5, 0x2E]
	b _080FAC54
_080FAC38:
	ldr r4, =gFieldEffectArguments
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	ldr r2, =0x00000e8c
	bl MapGridSetMetatileIdAt
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x18]
	bl CurrentMapDrawMetatileAt
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80FAC68
	str r0, [r5, 0x1C]
_080FAC54:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FAC24

	thumb_func_start sub_80FAC68
sub_80FAC68: @ 80FAC68
	push {lr}
	movs r1, 0x34
	bl FieldEffectStop
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80FAC68

	thumb_func_start sub_80FAC78
sub_80FAC78: @ 80FAC78
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x000002f5
	cmp r1, r0
	beq _080FAD6C
	cmp r1, r0
	bgt _080FACB4
	subs r0, 0x17
	cmp r1, r0
	beq _080FAD14
	adds r0, 0x16
	cmp r1, r0
	beq _080FAD60
	b _080FADCE
	.pool
_080FACB4:
	ldr r0, =0x000002f6
	cmp r1, r0
	beq _080FADA4
	adds r0, 0x40
	cmp r1, r0
	beq _080FACC2
	b _080FADCE
_080FACC2:
	ldr r0, =gStringVar1
	movs r1, 0x64
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	ldr r1, =gText_Gold
	bl StringCopy
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080FADCE
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
	b _080FAD8A
	.pool
_080FAD14:
	ldr r0, =gStringVar1
	movs r1, 0x32
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	ldr r1, =gText_Silver
	bl StringCopy
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080FADCE
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x20
	b _080FAD8A
	.pool
_080FAD60:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _080FAD70
	.pool
_080FAD6C:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
_080FAD70:
	strh r0, [r1]
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080FADCE
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x80
_080FAD8A:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080FADCE
	.pool
_080FADA4:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	strh r0, [r1]
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080FADCE
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x80
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080FADCE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FAC78

	thumb_func_start sub_80FADE4
sub_80FADE4: @ 80FADE4
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl CurrentMapIsSecretBase
	lsls r0, 24
	cmp r0, 0
	beq _080FAE28
	cmp r5, 0
	bne _080FAE1C
	ldr r1, =0xfffffd7b
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080FAE10
	ldr r0, =0x00000237
	cmp r4, r0
	bne _080FAE28
_080FAE10:
	movs r0, 0x1
	b _080FAE2A
	.pool
_080FAE1C:
	ldr r0, =0x0000028d
	cmp r4, r0
	beq _080FAE10
	ldr r0, =0x0000023f
	cmp r6, r0
	beq _080FAE10
_080FAE28:
	movs r0, 0
_080FAE2A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80FADE4

	thumb_func_start task50_overworld_posion_effect
task50_overworld_posion_effect: @ 80FAE38
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r1, r0, r1
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	beq _080FAE76
	cmp r0, 0x1
	bgt _080FAE60
	cmp r0, 0
	beq _080FAE66
	b _080FAE92
	.pool
_080FAE60:
	cmp r0, 0x2
	beq _080FAE8A
	b _080FAE92
_080FAE66:
	ldrh r0, [r1, 0x2]
	adds r0, 0x2
	strh r0, [r1, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _080FAE92
	b _080FAE82
_080FAE76:
	ldrh r0, [r1, 0x2]
	subs r0, 0x2
	strh r0, [r1, 0x2]
	lsls r0, 16
	cmp r0, 0
	bne _080FAE92
_080FAE82:
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _080FAE92
_080FAE8A:
	adds r0, r2, 0
	bl DestroyTask
	b _080FAEA2
_080FAE92:
	ldrh r0, [r1, 0x2]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
_080FAEA2:
	pop {r0}
	bx r0
	thumb_func_end task50_overworld_posion_effect

	thumb_func_start overworld_posion_effect
overworld_posion_effect: @ 80FAEA8
	push {lr}
	movs r0, 0x4F
	bl PlaySE
	ldr r0, =task50_overworld_posion_effect
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_posion_effect

	thumb_func_start FieldPoisonEffectIsRunning
FieldPoisonEffectIsRunning: @ 80FAEC0
	push {lr}
	ldr r0, =task50_overworld_posion_effect
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldPoisonEffectIsRunning

	thumb_func_start sub_80FAED4
sub_80FAED4: @ 80FAED4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_80FAEF0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80FAED4

	thumb_func_start sub_80FAEF0
sub_80FAEF0: @ 80FAEF0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080FAF1C
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080FAF4E
_080FAF1C:
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl sub_808C228
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl GetStepInPlaceDelay16AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80FAF64
	str r1, [r0]
_080FAF4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FAEF0

	thumb_func_start sub_80FAF64
sub_80FAF64: @ 80FAF64
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	adds r0, r5, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080FAFC8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xA]
	adds r1, r0, 0x1
	strh r1, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bgt _080FAFC4
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl GetStepInPlaceDelay16AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldObjectSetSpecialAnim
	b _080FAFC8
	.pool
_080FAFC4:
	ldr r0, =sub_80FAFD4
	str r0, [r2]
_080FAFC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FAF64

	thumb_func_start sub_80FAFD4
sub_80FAFD4: @ 80FAFD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_808BCD0
	lsls r0, 24
	lsrs r0, 24
	bl SetPlayerAvatarTransitionFlags
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FAFD4

	thumb_func_start sub_80FAFF8
sub_80FAFF8: @ 80FAFF8
	push {lr}
	ldr r0, =sub_80FAED4
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FAFF8

	thumb_func_start sub_80FB00C
sub_80FB00C: @ 80FB00C
	push {r4,r5,lr}
	ldr r0, =gUnknown_0858E864
	bl LoadSpritePalette
	ldr r0, =gUnknown_0858E880
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _080FB06C
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r0, 0x10
	movs r1, 0xD
	bl sub_8092FF0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x20]
	adds r0, 0x10
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	adds r0, 0x2
	strh r0, [r4, 0x22]
	adds r0, r5, 0
	b _080FB06E
	.pool
_080FB06C:
	movs r0, 0x40
_080FB06E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80FB00C

	thumb_func_start sub_80FB074
sub_80FB074: @ 80FB074
	push {r4-r7,lr}
	ldr r4, =gSprites
	adds r7, r4, 0
	movs r6, 0
	movs r5, 0x3F
_080FB07E:
	adds r0, r7, 0
	adds r0, 0x14
	adds r0, r6, r0
	ldr r1, [r0]
	ldr r0, =gUnknown_0858E880
	cmp r1, r0
	bne _080FB098
	adds r0, r4, 0
	bl FreeSpritePalette
	adds r0, r4, 0
	bl DestroySprite
_080FB098:
	adds r4, 0x44
	adds r6, 0x44
	subs r5, 0x1
	cmp r5, 0
	bge _080FB07E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB074

	.align 2, 0 @ Don't pad with nop.
