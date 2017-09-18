	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BEB24
sub_81BEB24: @ 81BEB24
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_08617DA4
_081BEB2A:
	lsls r2, r4, 2
	adds r2, r5
	ldrb r0, [r2]
	adds r0, 0x7
	ldrb r1, [r2, 0x1]
	adds r1, 0x7
	ldrh r2, [r2, 0x2]
	bl MapGridSetMetatileIdAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x11
	bls _081BEB2A
	bl DrawWholeMapView
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB24

	thumb_func_start sub_81BEB54
sub_81BEB54: @ 81BEB54
	push {lr}
	ldr r0, =sub_81BED50
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB54

	thumb_func_start sub_81BEB68
sub_81BEB68: @ 81BEB68
	push {lr}
	ldr r0, =sub_81BEBF4
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB68

	thumb_func_start sub_81BEB7C
sub_81BEB7C: @ 81BEB7C
	push {lr}
	ldr r0, =sub_81BF028
	movs r1, 0x9
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB7C

	thumb_func_start sub_81BEB90
sub_81BEB90: @ 81BEB90
	push {r4,lr}
	ldr r4, =gUnknown_0203CF14
	ldr r0, [r4]
	ldrh r1, [r0]
	movs r0, 0x10
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x2]
	movs r0, 0x12
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEB90

	thumb_func_start sub_81BEBB4
sub_81BEBB4: @ 81BEBB4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r1, [r2, 0x8]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _081BEBEC
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
	movs r0, 0x2
	strh r0, [r2, 0x8]
	bl sub_81BEB90
	b _081BEBF0
	.pool
_081BEBEC:
	subs r0, r1, 0x1
	strh r0, [r2, 0x8]
_081BEBF0:
	pop {r0}
	bx r0
	thumb_func_end sub_81BEBB4

	thumb_func_start sub_81BEBF4
sub_81BEBF4: @ 81BEBF4
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	bls _081BEC10
	b _081BED40
_081BEC10:
	lsls r0, 2
	ldr r1, =_081BEC24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BEC24:
	.4byte _081BEC40
	.4byte _081BEC50
	.4byte _081BEC88
	.4byte _081BECB0
	.4byte _081BECF8
	.4byte _081BED00
	.4byte _081BED1C
_081BEC40:
	bl FreeAllWindowBuffers
	movs r0, 0
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	b _081BED04
_081BEC50:
	ldr r4, =gUnknown_0203CF04
	movs r0, 0x92
	lsls r0, 4
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_0203CF08
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	b _081BECD8
	.pool
_081BEC88:
	ldr r0, =gUnknown_08617274
	ldr r4, =gUnknown_0203CF04
	ldr r1, [r4]
	movs r2, 0x92
	lsls r2, 3
	bl CpuSet
	ldr r1, [r4]
	movs r2, 0x92
	lsls r2, 4
	movs r0, 0
	movs r3, 0
	bl LoadBgTiles
	b _081BECD8
	.pool
_081BECB0:
	ldr r0, =gUnknown_0203CF08
	ldr r1, [r0]
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08617B94
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r2, 0xC
	movs r3, 0x1D
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_081BECD8:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _081BED40
	.pool
_081BECF8:
	movs r0, 0
	bl ShowBg
	b _081BED04
_081BED00:
	bl sub_81BEB24
_081BED04:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _081BED40
	.pool
_081BED1C:
	ldr r4, =gUnknown_0203CF14
	movs r0, 0x4
	bl Alloc
	str r0, [r4]
	movs r2, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r2, [r0, 0x2]
	ldr r0, =sub_81BEBB4
	movs r1, 0xA
	bl CreateTask
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_081BED40:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BEBF4

	thumb_func_start sub_81BED50
sub_81BED50: @ 81BED50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	adds r6, r1, 0
	cmp r0, 0x7
	bls _081BED7C
	b _081BF002
_081BED7C:
	lsls r0, 2
	ldr r1, =_081BED90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BED90:
	.4byte _081BEDB0
	.4byte _081BF002
	.4byte _081BEDC4
	.4byte _081BEF64
	.4byte _081BEF94
	.4byte _081BEFD0
	.4byte _081BEFF0
	.4byte _081BEFF8
_081BEDB0:
	ldr r4, =gUnknown_0203CF10
	movs r0, 0xC0
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	b _081BF002
	.pool
_081BEDC4:
	mov r1, r10
	lsls r0, r1, 2
	adds r1, r0, r1
	lsls r1, 3
	adds r2, r1, r6
	ldrh r3, [r2, 0xE]
	movs r4, 0xE
	ldrsh r1, [r2, r4]
	str r0, [sp, 0x8]
	cmp r1, 0x5F
	bgt _081BEE8A
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	ble _081BEE7C
	lsls r0, r3, 24
	lsrs r4, r0, 24
	movs r0, 0x30
	bl Alloc
	ldr r3, =gUnknown_0203CF10
	ldr r1, [r3]
	lsls r2, r4, 3
	adds r1, r2, r1
	str r0, [r1]
	movs r5, 0
	adds r4, r2, 0
_081BEDFA:
	ldr r0, [r3]
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, r5
	strb r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x2F
	bls _081BEDFA
	movs r5, 0
	ldr r7, =gUnknown_0203CF10
	adds r6, r2, 0
_081BEE14:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x30
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x30
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r7]
	adds r1, r6, r1
	ldr r1, [r1]
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r1, r4
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, r6, r0
	ldr r0, [r0]
	adds r0, r4
	strb r2, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x2F
	bls _081BEE14
	ldr r0, =gTasks
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	adds r2, r1, r0
	ldrh r3, [r2, 0xE]
	movs r4, 0xE
	ldrsh r1, [r2, r4]
	adds r6, r0, 0
	cmp r1, 0x5F
	bgt _081BEE78
	adds r0, r3, 0x1
	strh r0, [r2, 0xE]
_081BEE78:
	movs r0, 0
	strh r0, [r2, 0xA]
_081BEE7C:
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_081BEE8A:
	ldr r0, [sp, 0x8]
	add r0, r10
	lsls r0, 3
	adds r0, r6
	ldrb r4, [r0, 0xE]
	ldrb r5, [r0, 0xC]
	lsls r0, r4, 16
	cmp r5, r4
	bcs _081BEF32
	str r0, [sp, 0xC]
_081BEE9E:
	movs r6, 0
	adds r0, r5, 0x1
	str r0, [sp, 0x4]
	lsls r4, r5, 3
	movs r2, 0x5F
	subs r1, r2, r5
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	mov r9, r0
_081BEEB2:
	ldr r0, =gUnknown_0203CF04
	ldr r0, [r0]
	ldr r7, =gUnknown_0203CF10
	ldr r3, [r7]
	adds r3, r4, r3
	ldrb r2, [r3, 0x4]
	adds r1, r2, 0x1
	strb r1, [r3, 0x4]
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [r3]
	adds r1, r2
	ldrb r1, [r1]
	add r1, r9
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0x1
	mov r8, r2
	str r2, [sp]
	movs r2, 0
	movs r3, 0x30
	bl sub_81BF2B8
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _081BEEB2
	ldr r0, [r7]
	adds r1, r4, r0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x2F
	bls _081BEF24
	ldr r0, [r1]
	bl Free
	ldr r0, [r7]
	adds r0, r4, r0
	movs r1, 0
	str r1, [r0]
	ldr r1, [sp, 0x8]
	add r1, r10
	lsls r1, 3
	ldr r4, =gTasks
	adds r1, r4
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	mov r0, r8
	ands r5, r0
	cmp r5, 0x1
	bne _081BEF24
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	ldrh r0, [r1, 0x2]
	subs r0, 0x1
	strh r0, [r1, 0x2]
_081BEF24:
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	lsrs r5, r0, 16
	ldr r2, [sp, 0xC]
	lsrs r0, r2, 16
	cmp r5, r0
	bcc _081BEE9E
_081BEF32:
	ldr r0, =gUnknown_0203CF04
	ldr r1, [r0]
	movs r2, 0x92
	lsls r2, 4
	movs r0, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0203CF10
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2F
	bhi _081BF002
	b _081BF014
	.pool
_081BEF64:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	ldr r0, =sub_81BEBB4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081BEF7C
	bl DestroyTask
_081BEF7C:
	ldr r0, =gUnknown_0203CF14
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bl sub_81BEB90
	b _081BF002
	.pool
_081BEF94:
	ldr r4, =gUnknown_0203CF14
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r4, =gUnknown_0203CF10
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203CF04
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203CF08
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	b _081BF002
	.pool
_081BEFD0:
	movs r0, 0xC
	movs r1, 0x2
	bl SetGpuRegBits
	movs r0, 0x8
	movs r1, 0
	bl SetGpuRegBits
	movs r0, 0
	movs r1, 0x7
	movs r2, 0
	bl SetBgAttribute
	bl sub_81971D0
	b _081BF002
_081BEFF0:
	movs r0, 0
	bl ShowBg
	b _081BF002
_081BEFF8:
	mov r0, r10
	bl DestroyTask
	bl EnableBothScriptContexts
_081BF002:
	ldr r0, =gTasks
	mov r2, r10
	lsls r1, r2, 2
	add r1, r10
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081BF014:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BED50

	thumb_func_start sub_81BF028
sub_81BF028: @ 81BF028
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _081BF04C
	b _081BF228
_081BF04C:
	lsls r0, 2
	ldr r1, =_081BF060
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BF060:
	.4byte _081BF080
	.4byte _081BF0B4
	.4byte _081BF0DC
	.4byte _081BF0F0
	.4byte _081BF148
	.4byte _081BF170
	.4byte _081BF1CC
	.4byte _081BF224
_081BF080:
	ldr r4, =gUnknown_0203CF0C
	movs r0, 0x14
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x80
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x8
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 2
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0
	strh r0, [r1, 0x10]
	b _081BF228
	.pool
_081BF0B4:
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldr r1, [r0]
	movs r5, 0
	ldr r2, =gUnknown_08617C44
_081BF0BE:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r1, 0x1
	cmp r5, 0x7F
	bls _081BF0BE
	b _081BF228
	.pool
_081BF0DC:
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x80
	strh r0, [r1, 0x4]
	b _081BF228
	.pool
_081BF0F0:
	mov r1, sp
	ldr r0, =gUnknown_08617E00
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, =gUnknown_0203CF0C
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	str r0, [sp, 0xC]
	movs r2, 0x10
	negs r2, r2
	mov r0, sp
	movs r1, 0x80
	movs r3, 0x1
	bl CreateSprite
	ldr r1, [r4]
	movs r3, 0
	strb r0, [r1, 0x8]
	ldr r2, =gSprites
	ldr r0, [r4]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x28
	strb r3, [r0]
	ldr r3, [r4]
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x2E]
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x30]
_081BF148:
	movs r5, 0
	ldr r2, =gUnknown_0203CF0C
_081BF14C:
	ldr r0, [r2]
	ldr r1, [r0, 0xC]
	lsls r0, r5, 1
	adds r0, r1
	strh r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xFF
	bls _081BF14C
	b _081BF228
	.pool
_081BF170:
	movs r5, 0
	movs r6, 0xFF
	ldr r0, =0x000001ff
	mov r8, r0
_081BF178:
	bl Random
	adds r4, r6, 0
	ands r4, r0
	bl Random
	adds r1, r6, 0
	ands r1, r0
	ldr r0, =gUnknown_0203CF0C
	ldr r3, [r0]
	ldr r0, [r3, 0xC]
	lsls r1, 1
	adds r1, r0
	ldrh r2, [r1]
	lsls r4, 1
	adds r4, r0
	ldrh r0, [r4]
	strh r0, [r1]
	strh r2, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bls _081BF178
	ldr r2, =gSprites
	ldrb r1, [r3, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81BF248
	str r1, [r0]
	b _081BF228
	.pool
_081BF1CC:
	ldr r3, =gSprites
	ldr r5, =gUnknown_0203CF0C
	ldr r0, [r5]
	ldrb r1, [r0, 0x8]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _081BF238
	adds r0, r2, r3
	bl DestroySprite
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	str r4, [r0]
	bl Free
	str r4, [r5]
	b _081BF228
	.pool
_081BF224:
	bl EnableBothScriptContexts
_081BF228:
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081BF238:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF028

	thumb_func_start sub_81BF248
sub_81BF248: @ 81BF248
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, =gUnknown_0203CF0C
	ldr r0, [r0]
	ldrh r0, [r0, 0x10]
	cmp r0, 0xFF
	bls _081BF268
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
	b _081BF2B0
	.pool
_081BF268:
	ldrh r1, [r5, 0x22]
	movs r2, 0x22
	ldrsh r0, [r5, r2]
	cmp r0, 0x5F
	ble _081BF2AC
	movs r4, 0
_081BF274:
	ldr r0, =gUnknown_0203CF0C
	ldr r3, [r0]
	ldr r0, [r3]
	ldrh r1, [r3, 0x10]
	adds r2, r1, 0x1
	strh r2, [r3, 0x10]
	lsls r1, 16
	ldr r2, [r3, 0xC]
	lsrs r1, 15
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0
	str r2, [sp]
	movs r3, 0x10
	bl sub_81BF2B8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _081BF274
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnim
	b _081BF2B0
	.pool
_081BF2AC:
	adds r0, r1, 0x1
	strh r0, [r5, 0x22]
_081BF2B0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81BF248

	thumb_func_start sub_81BF2B8
sub_81BF2B8: @ 81BF2B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x28]
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	mov r8, r0
	lsrs r7, r0, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r10
	adds r1, r7, 0
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 24
	lsrs r4, r5, 24
	ldr r3, =gUnknown_030012A8
	strh r4, [r3]
	mov r0, r10
	adds r1, r7, 0
	str r3, [sp, 0x4]
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, [sp, 0x4]
	strh r2, [r3, 0x2]
	movs r1, 0x7
	ands r4, r1
	ands r2, r1
	strh r4, [r3, 0x4]
	strh r2, [r3, 0x6]
	lsrs r0, 27
	lsrs r5, 27
	strh r0, [r3, 0x8]
	strh r5, [r3, 0xA]
	mov r1, r8
	lsrs r1, 27
	lsls r1, 6
	mov r8, r1
	mov r1, r8
	muls r1, r5
	lsls r0, 6
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	strh r1, [r3, 0xC]
	lsls r4, 3
	adds r4, r2
	adds r1, r4
	lsls r4, r1, 16
	lsrs r4, 17
	strh r1, [r3, 0xE]
	movs r1, 0x1
	mov r0, r10
	ands r1, r0
	movs r2, 0x1
	eors r1, r2
	lsls r0, r1, 2
	lsls r6, r0
	eors r1, r2
	lsls r1, 2
	movs r0, 0xF
	lsls r0, r1
	orrs r6, r0
	lsls r6, 24
	lsrs r6, 24
	mov r1, r9
	lsls r1, 5
	mov r9, r1
	add r9, r4
	ldr r1, [sp]
	add r1, r9
	ldrb r0, [r1]
	ands r6, r0
	strb r6, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF2B8

	.align 2, 0 @ Don't pad with nop.
