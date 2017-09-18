	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start walda_maybe
walda_maybe: @ 81D99E4
	push {r4,lr}
	sub sp, 0x8
	ldr r4, =gStringVar2
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_81D9A1C
	str r0, [sp, 0x4]
	movs r0, 0x4
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl DoNamingScreen
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end walda_maybe

	thumb_func_start sub_81D9A1C
sub_81D9A1C: @ 81D9A1C
	push {r4,r5,lr}
	ldr r4, =gSpecialVar_0x8004
	ldr r5, =gStringVar2
	adds r0, r5, 0
	bl sub_81D9A98
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _081D9A68
	cmp r0, 0x1
	bgt _081D9A44
	cmp r0, 0
	beq _081D9A62
	b _081D9A68
	.pool
_081D9A44:
	cmp r0, 0x2
	bne _081D9A68
	bl sub_80D2578
	cmp r0, 0
	beq _081D9A5C
	ldr r0, =gUnknown_085EE49A
	bl sub_80D255C
	b _081D9A68
	.pool
_081D9A5C:
	movs r0, 0x1
	strh r0, [r4]
	b _081D9A68
_081D9A62:
	adds r0, r5, 0
	bl sub_80D255C
_081D9A68:
	ldr r4, =gStringVar1
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9A1C

	thumb_func_start sub_81D9A98
sub_81D9A98: @ 81D9A98
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081D9AA6
	movs r0, 0x2
	b _081D9ABC
_081D9AA6:
	bl sub_80D2548
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCompare
	cmp r0, 0
	beq _081D9ABA
	movs r0, 0
	b _081D9ABC
_081D9ABA:
	movs r0, 0x1
_081D9ABC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9A98

	thumb_func_start sub_81D9AC4
sub_81D9AC4: @ 81D9AC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xA
	bl ReadUnalignedWord
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gScriptResult
	mov r8, r0
	bl sub_80D2548
	mov r7, sp
	adds r7, 0xA
	add r6, sp, 0xC
	mov r5, sp
	adds r5, 0xD
	str r4, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_81D9B68
	mov r1, r8
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _081D9B1E
	ldrb r0, [r5]
	bl sub_80D24BC
	ldrb r0, [r6]
	bl sub_80D24F0
	add r0, sp, 0x8
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl sub_80D2524
_081D9B1E:
	mov r1, r8
	ldrh r0, [r1]
	bl sub_80D2480
	mov r1, r8
	ldrb r0, [r1]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D9AC4

	thumb_func_start sub_81D9B40
sub_81D9B40: @ 81D9B40
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_0862AD14
_081D9B4A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081D9B5C
	lsls r0, r1, 24
	lsrs r0, 24
	b _081D9B64
	.pool
_081D9B5C:
	adds r1, 0x1
	cmp r1, 0x1F
	bls _081D9B4A
	movs r0, 0x20
_081D9B64:
	pop {r1}
	bx r1
	thumb_func_end sub_81D9B40

	thumb_func_start sub_81D9B68
sub_81D9B68: @ 81D9B68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r10, r0
	str r1, [sp, 0x20]
	str r2, [sp, 0x24]
	str r3, [sp, 0x28]
	ldr r0, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	adds r0, r5, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bne _081D9C7E
	movs r4, 0
	add r7, sp, 0x10
_081D9B98:
	adds r0, r5, r4
	ldrb r0, [r0]
	bl sub_81D9B40
	adds r1, r7, r4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	beq _081D9C7E
	adds r4, 0x1
	cmp r4, 0xE
	ble _081D9B98
	movs r6, 0x3
	movs r5, 0
	movs r0, 0x5
	mov r8, r0
	movs r4, 0xD
_081D9BBC:
	mov r1, r8
	str r1, [sp]
	add r0, sp, 0x4
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_81D9D5C
	adds r6, 0x8
	adds r5, 0x5
	subs r4, 0x1
	cmp r4, 0
	bge _081D9BBC
	movs r0, 0x2
	str r0, [sp]
	add r0, sp, 0x4
	adds r1, r7, 0
	movs r2, 0x46
	movs r3, 0x73
	bl sub_81D9D5C
	add r0, sp, 0x4
	movs r1, 0
	movs r2, 0x3
	bl sub_81D9DAC
	adds r4, r0, 0
	adds r0, r7, 0
	movs r1, 0x75
	movs r2, 0x3
	bl sub_81D9DAC
	cmp r4, r0
	bne _081D9C7E
	add r0, sp, 0x4
	movs r1, 0x9
	movs r2, 0x15
	bl sub_81D9C90
	add r0, sp, 0x4
	ldrb r0, [r0, 0x8]
	movs r2, 0xF
	ands r2, r0
	add r0, sp, 0x4
	movs r1, 0x8
	bl sub_81D9C90
	add r0, sp, 0x4
	ldrb r2, [r0, 0x8]
	lsrs r2, 4
	movs r1, 0x8
	bl sub_81D9CDC
	add r0, sp, 0x4
	ldrb r2, [r0, 0x6]
	adds r1, r0, 0
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	eors r0, r1
	add r1, sp, 0x4
	ldrb r4, [r1, 0x4]
	eors r0, r4
	mov r3, r9
	lsrs r1, r3, 8
	eors r0, r1
	cmp r2, r0
	bne _081D9C7E
	add r0, sp, 0x4
	ldrb r3, [r0, 0x7]
	adds r2, r0, 0
	ldrb r1, [r0, 0x1]
	ldrb r0, [r2, 0x3]
	eors r1, r0
	adds r0, r2, 0
	ldrb r2, [r0, 0x5]
	eors r1, r2
	movs r0, 0xFF
	mov r5, r9
	ands r0, r5
	eors r1, r0
	cmp r3, r1
	bne _081D9C7E
	add r0, sp, 0x4
	ldrh r0, [r0]
	mov r1, r10
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6
	ldrh r0, [r0]
	ldr r3, [sp, 0x20]
	strh r0, [r3]
	ldr r5, [sp, 0x24]
	strb r4, [r5]
	ldr r0, [sp, 0x28]
	strb r2, [r0]
	movs r0, 0x1
	b _081D9C80
_081D9C7E:
	movs r0, 0
_081D9C80:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9B68

	thumb_func_start sub_81D9C90
sub_81D9C90: @ 81D9C90
	push {r4-r7,lr}
	adds r7, r0, 0
	mov r12, r1
	subs r3, r2, 0x1
	cmp r2, 0
	beq _081D9CD6
_081D9C9C:
	ldrb r1, [r7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 31
	mov r2, r12
	subs r2, 0x1
	subs r5, r3, 0x1
	cmp r2, 0
	blt _081D9CCC
	movs r6, 0x80
	adds r3, r2, r7
_081D9CB4:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	lsls r0, 24
	lsls r1, 1
	orrs r4, r1
	strb r4, [r3]
	lsrs r4, r0, 31
	subs r3, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _081D9CB4
_081D9CCC:
	adds r3, r5, 0
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	bne _081D9C9C
_081D9CD6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9C90

	thumb_func_start sub_81D9CDC
sub_81D9CDC: @ 81D9CDC
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r0, r3, 4
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _081D9D04
_081D9CF4:
	adds r2, r6, r4
	ldrb r1, [r2]
	adds r0, r3, 0
	eors r0, r1
	strb r0, [r2]
	adds r4, 0x1
	cmp r4, r5
	bcc _081D9CF4
_081D9D04:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9CDC

	thumb_func_start sub_81D9D0C
sub_81D9D0C: @ 81D9D0C
	push {lr}
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	adds r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _081D9D24
	movs r0, 0x1
_081D9D24:
	pop {r1}
	bx r1
	thumb_func_end sub_81D9D0C

	thumb_func_start sub_81D9D28
sub_81D9D28: @ 81D9D28
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D28

	thumb_func_start sub_81D9D40
sub_81D9D40: @ 81D9D40
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	mvns r1, r1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D40

	thumb_func_start sub_81D9D5C
sub_81D9D5C: @ 81D9D5C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r1
	adds r1, r2, 0
	mov r8, r3
	ldr r7, [sp, 0x1C]
	movs r5, 0
	cmp r5, r7
	bcs _081D9DA0
	adds r4, r1, 0
_081D9D76:
	mov r0, r8
	adds r1, r0, r5
	mov r0, r9
	bl sub_81D9D0C
	lsls r0, 24
	cmp r0, 0
	beq _081D9D90
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D28
	b _081D9D98
_081D9D90:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D40
_081D9D98:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, r7
	bcc _081D9D76
_081D9DA0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9D5C

	thumb_func_start sub_81D9DAC
sub_81D9DAC: @ 81D9DAC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r4, 0
	movs r5, 0
	cmp r4, r6
	bcs _081D9DD6
_081D9DC0:
	lsls r4, 1
	adds r1, r7, r5
	mov r0, r8
	bl sub_81D9D0C
	lsls r0, 24
	lsrs r0, 24
	orrs r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D9DC0
_081D9DD6:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9DAC

	.align 2, 0 @ Don't pad with nop.
