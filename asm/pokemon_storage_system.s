	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80D259C
sub_80D259C: @ 80D259C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_02039D84
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	bl Alloc
	str r0, [r6]
	ldr r5, =gUnknown_02039D88
	movs r1, 0
	cmp r0, 0
	beq _080D25BA
	adds r1, r4, 0
_080D25BA:
	strh r1, [r5]
	movs r2, 0
	cmp r2, r1
	bcs _080D25E2
	movs r3, 0
	adds r4, r5, 0
_080D25C6:
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 4
	adds r1, r0
	str r3, [r1, 0x18]
	adds r1, 0x2C
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4]
	cmp r2, r0
	bcc _080D25C6
_080D25E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D259C

	thumb_func_start sub_80D25F0
sub_80D25F0: @ 80D25F0
	push {lr}
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D25F0

	thumb_func_start sub_80D2604
sub_80D2604: @ 80D2604
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D2634
	movs r5, 0
_080D2612:
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D2628
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80D2918
_080D2628:
	adds r5, 0x30
	adds r4, 0x1
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D2612
_080D2634:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2604

	thumb_func_start sub_80D2644
sub_80D2644: @ 80D2644
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r2, 0
	ldr r2, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080D272C
	ldr r0, =gUnknown_02039D84
	mov r9, r0
	ldr r0, [r0]
	lsls r1, r6, 1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, 4
	adds r0, r5, r0
	movs r1, 0
	str r1, [r0, 0x18]
	str r4, [r0, 0x1C]
	adds r0, 0x2B
	strb r7, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, r10
	strh r3, [r0, 0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	movs r1, 0x3
	bl GetBgAttribute
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	movs r1, 0x9
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	ldr r1, [r2]
	adds r5, r1
	ldr r2, =gSpriteTemplate_857BC88
	lsls r4, 2
	lsls r1, r0, 4
	adds r4, r1
	adds r4, r2
	ldrh r1, [r4]
	strh r1, [r5, 0x20]
	ldrh r1, [r4, 0x2]
	strh r1, [r5, 0x22]
	mov r2, r8
	cmp r0, 0
	beq _080D26E8
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x1
	b _080D26EE
	.pool
_080D26E8:
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x2
_080D26EE:
	strb r0, [r1]
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	adds r2, r6
	lsls r2, 4
	adds r1, r2, r1
	adds r0, r1, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	mov r3, r10
	muls r3, r0
	movs r0, 0
	strh r3, [r1, 0x28]
	mov r3, r10
	strh r3, [r1, 0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, 0x12]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, [r4]
	adds r2, r0
	adds r2, 0x2C
	movs r0, 0x1
	strb r0, [r2]
_080D272C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2644

	thumb_func_start sub_80D2740
sub_80D2740: @ 80D2740
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2764
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1
	str r3, [r0, 0x18]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D2764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2740

	thumb_func_start sub_80D2770
sub_80D2770: @ 80D2770
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r3, r0
	bcs _080D279C
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 4
	adds r0, r1
	strh r4, [r0, 0x14]
	strh r2, [r0, 0x16]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D279C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2770

	thumb_func_start sub_80D27AC
sub_80D27AC: @ 80D27AC
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcs _080D27E6
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 4
	adds r0, r1
	strh r6, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r3, [r0, 0x10]
	strh r4, [r0, 0x12]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D27E6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27AC

	thumb_func_start sub_80D27F4
sub_80D27F4: @ 80D27F4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080D280C
	b _080D290E
_080D280C:
	ldr r4, =gUnknown_02039D84
	lsls r2, r5, 1
	cmp r1, 0x5
	bls _080D2816
	b _080D2900
_080D2816:
	lsls r0, r1, 2
	ldr r1, =_080D282C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D282C:
	.4byte _080D2844
	.4byte _080D2864
	.4byte _080D2888
	.4byte _080D28A8
	.4byte _080D28CC
	.4byte _080D28E8
_080D2844:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x14]
	adds r0, r2
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x10]
	subs r0, r2
	b _080D287E
	.pool
_080D2864:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x10]
	adds r0, r2
_080D287E:
	strh r0, [r1, 0x10]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D2888:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x16]
	adds r0, r2
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x12]
	subs r0, r2
	b _080D28C2
	.pool
_080D28A8:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xE]
	subs r0, r2
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x12]
	adds r0, r2
_080D28C2:
	strh r0, [r1, 0x12]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D28CC:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x14]
	adds r0, r4
	strh r0, [r1, 0x14]
	b _080D28FE
	.pool
_080D28E8:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x16]
	adds r0, r4
	strh r0, [r1, 0x16]
_080D28FE:
	adds r4, r3, 0
_080D2900:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0x1
	strb r0, [r1]
_080D290E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27F4

	thumb_func_start sub_80D2918
sub_80D2918: @ 80D2918
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2952
	ldr r5, =gUnknown_02039D84
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4, r0
	ldr r0, [r0, 0x18]
	cmp r0, 0
	beq _080D2940
	adds r0, r2, 0
	bl sub_80D2960
_080D2940:
	adds r0, r6, 0
	bl sub_80D29F8
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080D2952:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2918

	thumb_func_start sub_80D2960
sub_80D2960: @ 80D2960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x20]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x18]
	adds r1, r2
	movs r6, 0x8
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x6]
	cmp r6, r0
	bge _080D29E4
	mov r10, r4
_080D29AA:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r3, [r1, 0xA]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x4]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x6]
	cmp r6, r4
	blt _080D29AA
_080D29E4:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2960

	thumb_func_start sub_80D29F8
sub_80D29F8: @ 80D29F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x24]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xE
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x1C]
	adds r1, r2
	movs r6, 0xC
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x12]
	cmp r6, r0
	bge _080D2A7C
	mov r10, r4
_080D2A42:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x14]
	ldrb r3, [r1, 0x16]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x10]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x12]
	cmp r6, r4
	blt _080D2A42
_080D2A7C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D29F8

	thumb_func_start sub_80D2A90
sub_80D2A90: @ 80D2A90
	ldr r3, =gUnknown_02039D8C
	str r0, [r3]
	str r1, [r0]
	movs r1, 0
	strb r2, [r0, 0x5]
	strb r1, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_80D2A90

	thumb_func_start sub_80D2AA4
sub_80D2AA4: @ 80D2AA4
	push {r4,r5,lr}
	ldr r2, =gUnknown_02039D8C
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080D2AE2
	movs r4, 0
	ldrb r1, [r1, 0x4]
	cmp r4, r1
	bcs _080D2ADA
	adds r5, r2, 0
_080D2ABA:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r0, r1
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcc _080D2ABA
_080D2ADA:
	ldr r0, =gUnknown_02039D8C
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
_080D2AE2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2AA4

	thumb_func_start sub_80D2AEC
sub_80D2AEC: @ 80D2AEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r10, r3
	ldr r0, [sp, 0x24]
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2B74
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r4, 1
	strh r0, [r1, 0x8]
	ldr r2, [sp]
	lsls r0, r2, 5
	add r0, r12
	lsls r0, 1
	add r0, r9
	str r0, [r1, 0x4]
	adds r0, r3, 0
	muls r0, r6
	add r0, r8
	lsls r0, 1
	add r0, r10
	str r0, [r1]
	strh r5, [r1, 0xC]
	strh r6, [r1, 0xA]
	ldr r0, =sub_80D2B88
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2B76
	.pool
_080D2B74:
	movs r0, 0
_080D2B76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2AEC

	thumb_func_start sub_80D2B88
sub_80D2B88: @ 80D2B88
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _080D2BB2
_080D2B90:
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldrh r2, [r4, 0x8]
	lsrs r2, 1
	bl CpuSet
	ldr r0, [r4, 0x4]
	adds r0, 0x40
	str r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	lsls r1, 1
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080D2BB2:
	ldrh r0, [r4, 0xC]
	cmp r5, r0
	bcc _080D2B90
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80D2B88

	thumb_func_start sub_80D2BC0
sub_80D2BC0: @ 80D2BC0
	push {r4-r7,lr}
	mov r12, r0
	ldr r0, [sp, 0x14]
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2C14
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r3, 1
	strh r0, [r1, 0x8]
	lsls r0, r4, 5
	adds r0, r6
	lsls r0, 1
	add r0, r12
	str r0, [r1, 0x4]
	strh r5, [r1, 0xC]
	ldr r0, =sub_80D2C1C
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2C16
	.pool
_080D2C14:
	movs r0, 0
_080D2C16:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2BC0

	thumb_func_start sub_80D2C1C
sub_80D2C1C: @ 80D2C1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	movs r0, 0
	ldrh r1, [r6, 0xC]
	cmp r0, r1
	bcs _080D2CAA
	movs r7, 0x80
	lsls r7, 5
	mov r5, sp
	ldr r2, =0x040000d4
	mov r8, r2
	movs r1, 0x81
	lsls r1, 24
	mov r10, r1
_080D2C42:
	ldr r2, [r6, 0x4]
	ldrh r3, [r6, 0x8]
	mov r12, r2
	adds r0, 0x1
	mov r9, r0
	cmp r3, r7
	bhi _080D2C6C
	movs r0, 0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, r12
	str r1, [r0, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
	mov r1, r8
	b _080D2C94
	.pool
_080D2C6C:
	movs r4, 0
	strh r4, [r5]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000800
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r7
	subs r3, r7
	cmp r3, r7
	bhi _080D2C6C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
_080D2C94:
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, r12
	adds r0, 0x40
	str r0, [r6, 0x4]
	mov r1, r9
	lsls r0, r1, 16
	lsrs r0, 16
	ldrh r2, [r6, 0xC]
	cmp r0, r2
	bcc _080D2C42
_080D2CAA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2C1C

	.align 2, 0 @ Don't pad with nop.
