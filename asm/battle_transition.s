	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start Phase2_31_Func1
Phase2_31_Func1: @ 814A798
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	mov r1, r8
	strh r6, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	movs r0, 0xA
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_31_Func1

	thumb_func_start Phase2_31_Func2
Phase2_31_Func2: @ 814A828
	push {r4,r5,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	ldrb r0, [r4, 0xC]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0xE]
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r5, 0
	str r5, [sp, 0x1C]
	str r5, [sp, 0x20]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x4
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bne _0814A88A
	movs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x4
	strh r0, [r4, 0xE]
	strh r5, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0814A88A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814A88A:
	movs r0, 0
	add sp, 0x24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_31_Func2

	thumb_func_start Phase2_31_Func3
Phase2_31_Func3: @ 814A898
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldrh r0, [r4, 0x14]
	adds r1, r0, 0x1
	strh r1, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0814A956
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0814A8FC
	cmp r0, 0x1
	bgt _0814A8CA
	cmp r0, 0
	beq _0814A8D4
	b _0814A92C
_0814A8CA:
	cmp r0, 0x2
	beq _0814A914
	cmp r0, 0x3
	beq _0814A91C
	b _0814A92C
_0814A8D4:
	movs r2, 0xFA
	ldr r6, =gPlttBufferUnfaded
	movs r3, 0
	ldr r5, =gPlttBufferFaded
_0814A8DC:
	lsls r1, r2, 1
	adds r0, r1, r6
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFE
	bls _0814A8DC
	b _0814A94C
	.pool
_0814A8FC:
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =gUnknown_085C86F4
	b _0814A91E
	.pool
_0814A914:
	ldr r0, =gUnknown_085C87F4
	b _0814A91E
	.pool
_0814A91C:
	ldr r0, =gUnknown_085C88A4
_0814A91E:
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	b _0814A94C
	.pool
_0814A92C:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0814A956
_0814A94C:
	movs r0, 0
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
_0814A956:
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end Phase2_31_Func3

	thumb_func_start Phase2_33_Func1
Phase2_33_Func1: @ 814A960
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r4, =gUnknown_085C8578
	adds r0, r4, 0
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x8
	movs r3, 0
	bl BlendPalette
	movs r1, 0
	movs r0, 0x22
	mov r2, r8
	strh r0, [r2, 0xC]
	strh r1, [r2, 0xE]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_33_Func1

	thumb_func_start Phase2_33_Func2
Phase2_33_Func2: @ 814AA04
	push {r4-r6,lr}
	sub sp, 0x24
	adds r6, r0, 0
	ldr r1, =gUnknown_085C9A30
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	lsls r4, 2
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x8]
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bge _0814AA70
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_0814AA70:
	movs r0, 0
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_33_Func2

	thumb_func_start Phase2_33_Func3
Phase2_33_Func3: @ 814AA84
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x3
	movs r3, 0
	bl BlendPalette
	ldr r0, =0xffff3fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_33_Func3

	thumb_func_start Phase2_33_Func4
Phase2_33_Func4: @ 814AAB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	ldrh r0, [r7, 0xE]
	movs r1, 0x1
	eors r0, r1
	movs r6, 0
	strh r0, [r7, 0xE]
	cmp r0, 0
	beq _0814AB2C
	ldr r0, =gUnknown_085C8928
	mov r8, r0
	movs r4, 0x4
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r5, =gUnknown_085C9A30
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	movs r2, 0xC
	ldrsh r0, [r7, r2]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	movs r0, 0xE
	str r0, [sp, 0x18]
	str r6, [sp, 0x1C]
	str r6, [sp, 0x20]
	movs r0, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	b _0814AB78
	.pool
_0814AB2C:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _0814AB72
	ldr r1, =gUnknown_085C9A30
	subs r0, 0x1
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 26
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl FillBgTilemapBufferRect
_0814AB72:
	ldrh r0, [r7, 0xC]
	adds r0, 0x1
	strh r0, [r7, 0xC]
_0814AB78:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0x22
	ble _0814AB86
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
_0814AB86:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_33_Func4

	thumb_func_start Phase2_31_33_Func5
Phase2_31_33_Func5: @ 814ABA0
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end Phase2_31_33_Func5

	thumb_func_start sub_814ABE4
sub_814ABE4: @ 814ABE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	ldrh r0, [r6, 0xC]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r6, 0xC]
	cmp r0, 0
	bne _0814AC24
	ldr r5, =gBattle_BG0_X
	ldrh r1, [r5]
	movs r0, 0x12
	bl SetGpuReg
	ldr r4, =gBattle_BG0_Y
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r0, [r6, 0x8]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	ldrh r0, [r6, 0xA]
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r4]
_0814AC24:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814ABE4

	thumb_func_start Phase2_32_Func1
Phase2_32_Func1: @ 814AC38
	push {r4-r6,lr}
	sub sp, 0x10
	adds r6, r0, 0
	movs r5, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gBattle_BG0_X
	strh r5, [r0]
	ldr r4, =gBattle_BG0_Y
	strh r5, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	strh r5, [r6, 0xC]
	ldr r0, =sub_814ABE4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 16
	cmp r1, 0x1
	beq _0814ACE4
	cmp r1, 0x1
	bgt _0814ACC8
	cmp r1, 0
	beq _0814ACCE
	b _0814AD1C
	.pool
_0814ACC8:
	cmp r1, 0x2
	beq _0814AD00
	b _0814AD1C
_0814ACCE:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	b _0814AD2E
	.pool
_0814ACE4:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
	negs r1, r1
	b _0814AD2C
	.pool
_0814AD00:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	ldr r1, =0x0000ffff
	b _0814AD2C
	.pool
_0814AD1C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
_0814AD2C:
	strh r1, [r0, 0xA]
_0814AD2E:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_32_Func1

	thumb_func_start Phase2_32_Func2
Phase2_32_Func2: @ 814AD48
	push {r4,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	ldr r1, =gUnknown_085C8928
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	lsls r2, 2
	adds r2, 0x1
	str r2, [sp, 0x8]
	lsls r3, 2
	str r3, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814ADA0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814ADA0:
	movs r0, 0
	add sp, 0x24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_32_Func2

	thumb_func_start Phase2_32_Func3
Phase2_32_Func3: @ 814ADB4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_32_Func3

	thumb_func_start Phase2_32_Func4
Phase2_32_Func4: @ 814ADD8
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	lsls r2, 2
	adds r2, 0x1
	lsls r3, 2
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814AE2E
	ldr r0, =sub_814ABE4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814AE2E:
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_32_Func4

	thumb_func_start Phase2_32_Func5
Phase2_32_Func5: @ 814AE40
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gBattle_BG0_Y
	strh r1, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, [r5]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Phase2_32_Func5

	.align 2, 0 @ Don't pad with nop.
