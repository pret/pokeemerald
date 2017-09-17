	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81DABBC
sub_81DABBC: @ 81DABBC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81DAA74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081DABD2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DABD2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DABBC

	thumb_func_start sub_81DABDC
sub_81DABDC: @ 81DABDC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B770
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DABEE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DABEE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DABDC

	thumb_func_start sub_81DAC14
sub_81DAC14: @ 81DAC14
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r1, 0x33
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	movs r5, 0x2
	str r5, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x78
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x10]
	movs r0, 0x7
	negs r0, r0
	str r5, [sp]
	movs r4, 0x2
	negs r4, r4
	str r4, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x12]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0xF7
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x14]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAC14

	thumb_func_start sub_81DAC80
sub_81DAC80: @ 81DAC80
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DACA4
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DABDC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DACA4:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAC80

	thumb_func_start sub_81DACB4
sub_81DACB4: @ 81DACB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B784
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DACC6:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DACC6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DACB4

	thumb_func_start sub_81DACEC
sub_81DACEC: @ 81DACEC
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	movs r0, 0
	str r0, [sp]
	movs r4, 0x4
	negs r4, r4
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x78
	movs r1, 0xC5
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x10]
	str r4, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0xF1
	movs r1, 0x3B
	movs r2, 0
	movs r3, 0x1
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x4
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x3B
	movs r2, 0
	movs r3, 0x1
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81DACEC

	thumb_func_start sub_81DAD58
sub_81DAD58: @ 81DAD58
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAD7C
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DACB4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAD7C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAD58

	thumb_func_start sub_81DAD8C
sub_81DAD8C: @ 81DAD8C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B798
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAD9E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAD9E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAD8C

	thumb_func_start sub_81DADC4
sub_81DADC4: @ 81DADC4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	mov r8, r0
	movs r6, 0x80
	str r6, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r5, 0x4
	negs r5, r5
	str r5, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x2D
	movs r2, 0xC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x10]
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x59
	movs r1, 0x61
	movs r2, 0xFC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x12]
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x97
	movs r1, 0x61
	movs r2, 0x84
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DADC4

	thumb_func_start sub_81DAE44
sub_81DAE44: @ 81DAE44
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAE68
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAD8C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAE68:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAE44

	thumb_func_start sub_81DAE78
sub_81DAE78: @ 81DAE78
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7AC
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAE8A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAE8A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAE78

	thumb_func_start sub_81DAEB0
sub_81DAEB0: @ 81DAEB0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	mov r8, r0
	movs r2, 0x8E
	lsls r2, 1
	movs r6, 0x83
	str r6, [sp]
	movs r5, 0x23
	str r5, [sp, 0x4]
	movs r4, 0x3
	negs r4, r4
	str r4, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x10]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0x2C
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x12]
	str r6, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x79
	movs r1, 0x50
	movs r2, 0xA4
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAEB0

	thumb_func_start sub_81DAF34
sub_81DAF34: @ 81DAF34
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DAF58
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAE78
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DAF58:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DAF34

	thumb_func_start sub_81DAF68
sub_81DAF68: @ 81DAF68
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7C0
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DAF7A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DAF7A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAF68

	thumb_func_start sub_81DAFA0
sub_81DAFA0: @ 81DAFA0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r2, [r4, r0]
	cmp r2, 0
	bne _081DAFCC
	movs r1, 0x33
	negs r1, r1
	str r2, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0x78
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB01A
_081DAFCC:
	cmp r2, 0x10
	bne _081DAFF2
	movs r0, 0x7
	negs r0, r0
	movs r1, 0x4
	str r1, [sp]
	subs r1, 0x8
	str r1, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB01A
_081DAFF2:
	cmp r2, 0x20
	bne _081DB01A
	movs r0, 0x4
	negs r0, r0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0xF7
	movs r1, 0xC1
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB01A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAFA0

	thumb_func_start sub_81DB02C
sub_81DB02C: @ 81DB02C
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB050
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DAF68
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB050:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB02C

	thumb_func_start sub_81DB060
sub_81DB060: @ 81DB060
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7D4
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB072:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB072
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB060

	thumb_func_start sub_81DB098
sub_81DB098: @ 81DB098
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB0C4
	str r1, [sp]
	movs r0, 0x8
	negs r0, r0
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0x78
	movs r1, 0xC5
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB112
_081DB0C4:
	cmp r1, 0x10
	bne _081DB0E8
	movs r0, 0x8
	negs r0, r0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0xF1
	movs r1, 0x4E
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB112
_081DB0E8:
	cmp r1, 0x20
	bne _081DB112
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0x4E
	movs r2, 0
	movs r3, 0
	bl sub_81DA74C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB112:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB098

	thumb_func_start sub_81DB124
sub_81DB124: @ 81DB124
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB148
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB060
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB148:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB124

	.align 2, 0 @ Don't pad with nop.
