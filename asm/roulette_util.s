	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8151678
sub_8151678: @ 8151678
	push {lr}
	movs r1, 0
	strb r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	movs r2, 0xC0
	bl memset
	pop {r0}
	bx r0
	thumb_func_end sub_8151678

	thumb_func_start sub_815168C
sub_815168C: @ 815168C
	push {r4-r7,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r6, 0xF
	bhi _081516A8
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r5, r3, r0
	ldrb r7, [r5, 0x4]
	lsrs r0, r7, 7
	cmp r0, 0
	beq _081516AC
_081516A8:
	movs r0, 0xFF
	b _0815170A
_081516AC:
	ldrh r0, [r2]
	movs r4, 0
	strh r0, [r5, 0x8]
	ldrh r0, [r2, 0x2]
	strh r0, [r5, 0xA]
	ldrb r0, [r2, 0x4]
	strb r0, [r5, 0xC]
	ldrb r0, [r2, 0x5]
	strb r0, [r5, 0xD]
	ldrb r0, [r2, 0x6]
	strb r0, [r5, 0xE]
	ldrb r3, [r2, 0x7]
	lsls r0, r3, 27
	lsrs r0, 27
	ldrb r2, [r5, 0xF]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	movs r0, 0x60
	ands r0, r3
	movs r2, 0x61
	negs r2, r2
	ands r1, r2
	orrs r1, r0
	lsls r3, 24
	asrs r3, 31
	lsls r3, 7
	movs r0, 0x7F
	ands r1, r0
	orrs r1, r3
	strb r1, [r5, 0xF]
	subs r0, 0xFF
	ands r0, r7
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r5, 0x4]
	strb r4, [r5, 0x6]
	strb r4, [r5, 0x5]
	lsls r1, 24
	cmp r1, 0
	bge _08151704
	movs r0, 0xFF
	b _08151706
_08151704:
	movs r0, 0x1
_08151706:
	strb r0, [r5, 0x7]
	adds r0, r6, 0
_0815170A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_815168C

	thumb_func_start sub_8151710
sub_8151710: @ 8151710
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r4, r1, 0
	cmp r4, 0xF
	bhi _0815173C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r1, r2, r0
	ldrb r0, [r1, 0x4]
	lsrs r0, 7
	cmp r0, 0
	beq _0815173C
	adds r0, r1, 0x4
	movs r1, 0
	movs r2, 0xC
	bl memset
	adds r0, r4, 0
	b _0815173E
_0815173C:
	movs r0, 0xFF
_0815173E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8151710

	thumb_func_start sub_8151744
sub_8151744: @ 8151744
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	movs r0, 0
	mov r12, r0
	ldrb r1, [r5, 0x8]
	cmp r12, r1
	bcc _0815175C
	b _081518F4
_0815175C:
	movs r7, 0x1F
	ldr r0, =0xfffffc1f
	mov r10, r0
	movs r1, 0x7D
	negs r1, r1
	mov r9, r1
	movs r0, 0x1F
	mov r8, r0
_0815176C:
	ldrh r0, [r5, 0x6]
	add r0, r12
	lsls r0, 1
	ldr r1, =gUnknown_02037B14
	adds r3, r0, r1
	ldr r1, =gUnknown_02037714
	adds r6, r0, r1
	ldrb r0, [r5]
	lsls r0, 25
	lsrs r0, 25
	cmp r0, 0x1
	beq _08151798
	cmp r0, 0x2
	beq _081517F6
	b _081518E2
	.pool
_08151798:
	ldr r0, [r3]
	lsls r2, r0, 27
	lsrs r0, r2, 27
	movs r1, 0x3
	ldrsb r1, [r5, r1]
	adds r0, r1
	cmp r0, 0x1F
	bhi _081517BA
	lsrs r0, r2, 27
	adds r0, r1
	ands r0, r7
	ldrb r2, [r3]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_081517BA:
	ldr r0, [r3]
	lsls r2, r0, 22
	lsrs r0, r2, 27
	movs r1, 0x3
	ldrsb r1, [r5, r1]
	adds r0, r1
	cmp r0, 0x1F
	bhi _081517DE
	lsrs r0, r2, 27
	adds r0, r1
	mov r1, r8
	ands r0, r1
	lsls r0, 5
	ldrh r2, [r3]
	mov r1, r10
	ands r1, r2
	orrs r1, r0
	strh r1, [r3]
_081517DE:
	ldr r0, [r3]
	lsls r2, r0, 17
	lsrs r0, r2, 27
	movs r1, 0x3
	ldrsb r1, [r5, r1]
	adds r0, r1
	cmp r0, 0x1F
	bls _081517F0
	b _081518E2
_081517F0:
	lsrs r0, r2, 27
	adds r0, r1
	b _081518D4
_081517F6:
	movs r0, 0x3
	ldrsb r0, [r5, r0]
	cmp r0, 0
	bge _08151868
	ldr r0, [r3]
	lsls r4, r0, 27
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 27
	lsrs r0, 27
	cmp r1, r0
	blt _08151826
	lsrs r0, r4, 27
	adds r0, r2
	ands r0, r7
	ldrb r2, [r3]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_08151826:
	ldr r0, [r3]
	lsls r4, r0, 22
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 22
	lsrs r0, 27
	cmp r1, r0
	blt _08151850
	lsrs r0, r4, 27
	adds r0, r2
	mov r1, r8
	ands r0, r1
	lsls r0, 5
	ldrh r2, [r3]
	mov r1, r10
	ands r1, r2
	orrs r1, r0
	strh r1, [r3]
_08151850:
	ldr r0, [r3]
	lsls r4, r0, 17
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 17
	lsrs r0, 27
	cmp r1, r0
	blt _081518E2
	b _081518D0
_08151868:
	ldr r0, [r3]
	lsls r4, r0, 27
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 27
	lsrs r0, 27
	cmp r1, r0
	bgt _08151890
	lsrs r0, r4, 27
	adds r0, r2
	ands r0, r7
	ldrb r2, [r3]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_08151890:
	ldr r0, [r3]
	lsls r4, r0, 22
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 22
	lsrs r0, 27
	cmp r1, r0
	bgt _081518BA
	lsrs r0, r4, 27
	adds r0, r2
	mov r1, r8
	ands r0, r1
	lsls r0, 5
	ldrh r2, [r3]
	mov r1, r10
	ands r1, r2
	orrs r1, r0
	strh r1, [r3]
_081518BA:
	ldr r0, [r3]
	lsls r4, r0, 17
	lsrs r1, r4, 27
	movs r2, 0x3
	ldrsb r2, [r5, r2]
	adds r1, r2
	ldr r0, [r6]
	lsls r0, 17
	lsrs r0, 27
	cmp r1, r0
	bgt _081518E2
_081518D0:
	lsrs r0, r4, 27
	adds r0, r2
_081518D4:
	ands r0, r7
	lsls r0, 2
	ldrb r2, [r3, 0x1]
	mov r1, r9
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
_081518E2:
	mov r0, r12
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	ldrb r0, [r5, 0x8]
	cmp r12, r0
	bcs _081518F4
	b _0815176C
_081518F4:
	ldrb r1, [r5, 0x2]
	adds r0, r1, 0x1
	strb r0, [r5, 0x2]
	ldrb r0, [r5, 0xB]
	lsls r0, 27
	lsls r1, 24
	asrs r0, 3
	cmp r1, r0
	beq _0815190A
	movs r0, 0
	b _0815193E
_0815190A:
	movs r0, 0
	strb r0, [r5, 0x2]
	movs r0, 0x3
	ldrsb r0, [r5, r0]
	negs r0, r0
	strb r0, [r5, 0x3]
	ldrb r2, [r5]
	movs r1, 0x7F
	movs r0, 0x7F
	ands r0, r2
	cmp r0, 0x1
	bne _0815192A
	lsls r0, r2, 25
	lsrs r0, 25
	adds r0, 0x1
	b _08151930
_0815192A:
	lsls r0, r2, 25
	lsrs r0, 25
	subs r0, 0x1
_08151930:
	ands r0, r1
	movs r1, 0x80
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5]
	movs r0, 0x1
_0815193E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8151744

	thumb_func_start sub_815194C
sub_815194C: @ 815194C
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r2, 0
	ldrb r0, [r3]
	lsls r0, 25
	lsrs r0, 25
	cmp r0, 0x1
	beq _08151962
	cmp r0, 0x2
	beq _08151990
	b _081519CA
_08151962:
	ldrb r0, [r3, 0x8]
	cmp r2, r0
	bcs _08151982
	ldr r4, =gUnknown_02037B14
_0815196A:
	ldrh r0, [r3, 0x6]
	adds r0, r2
	lsls r0, 1
	adds r0, r4
	ldrh r1, [r3, 0x4]
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r3, 0x8]
	cmp r2, r0
	bcc _0815196A
_08151982:
	ldrb r2, [r3]
	lsls r1, r2, 25
	lsrs r1, 25
	adds r1, 0x1
	b _081519BC
	.pool
_08151990:
	ldrb r0, [r3, 0x8]
	cmp r2, r0
	bcs _081519B4
	ldr r5, =gUnknown_02037B14
	ldr r4, =gUnknown_02037714
_0815199A:
	ldrh r0, [r3, 0x6]
	adds r0, r2
	lsls r0, 1
	adds r1, r0, r5
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r3, 0x8]
	cmp r2, r0
	bcc _0815199A
_081519B4:
	ldrb r2, [r3]
	lsls r1, r2, 25
	lsrs r1, 25
	subs r1, 0x1
_081519BC:
	movs r0, 0x7F
	ands r1, r0
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_081519CA:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815194C

	thumb_func_start task_tutorial_controls_fadein
task_tutorial_controls_fadein: @ 81519DC
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _08151A40
_081519E8:
	ldrh r0, [r4, 0x2]
	asrs r0, r5
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08151A36
	lsls r1, r5, 1
	adds r0, r1, r5
	lsls r3, r0, 2
	adds r2, r4, r3
	ldrb r0, [r2, 0x5]
	subs r0, 0x1
	strb r0, [r2, 0x5]
	lsls r0, 24
	lsrs r0, 24
	adds r6, r1, 0
	cmp r0, 0xFF
	bne _08151A36
	ldrh r0, [r2, 0x8]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08151A24
	adds r0, r3, 0x4
	adds r0, r4, r0
	bl sub_8151744
	b _08151A2C
_08151A24:
	adds r0, r3, 0x4
	adds r0, r4, r0
	bl sub_815194C
_08151A2C:
	adds r0, r6, r5
	lsls r0, 2
	adds r0, r4, r0
	ldrb r1, [r0, 0xD]
	strb r1, [r0, 0x5]
_08151A36:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _081519E8
_08151A40:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end task_tutorial_controls_fadein

	thumb_func_start sub_8151A48
sub_8151A48: @ 8151A48
	push {r4-r7,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	movs r4, 0
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	movs r5, 0x1
	movs r7, 0x80
	negs r7, r7
_08151A5E:
	adds r0, r6, 0
	asrs r0, r4
	ands r0, r5
	cmp r0, 0
	beq _08151A8C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, r3, r0
	ldrb r0, [r2, 0x4]
	lsrs r0, 7
	cmp r0, 0
	beq _08151A8C
	adds r0, r5, 0
	lsls r0, r4
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldrb r1, [r2, 0x4]
	adds r0, r7, 0
	ands r0, r1
	orrs r0, r5
	strb r0, [r2, 0x4]
_08151A8C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08151A5E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8151A48

	thumb_func_start sub_8151A9C
sub_8151A9C: @ 8151A9C
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	movs r5, 0
	movs r3, 0x1
_08151AAA:
	ldrh r0, [r6, 0x2]
	asrs r0, r5
	ands r0, r3
	cmp r0, 0
	beq _08151B12
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r4, r6, r0
	ldrb r0, [r4, 0x4]
	lsrs r0, 7
	cmp r0, 0
	beq _08151B12
	adds r0, r7, 0
	asrs r0, r5
	ands r0, r3
	cmp r0, 0
	beq _08151B12
	ldrh r1, [r4, 0xA]
	lsls r1, 1
	ldr r0, =gUnknown_02037B14
	adds r0, r1, r0
	ldr r2, =gUnknown_02037714
	adds r1, r2
	ldrb r2, [r4, 0xC]
	lsls r2, 1
	str r3, [sp]
	bl memcpy
	ldrb r0, [r4, 0x4]
	movs r2, 0x80
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r4, 0x4]
	movs r0, 0
	strb r0, [r4, 0x6]
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0xF]
	lsls r0, 24
	ldr r3, [sp]
	cmp r0, 0
	bge _08151B10
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	b _08151B12
	.pool
_08151B10:
	strb r3, [r4, 0x7]
_08151B12:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _08151AAA
	ldr r0, =0x0000ffff
	cmp r7, r0
	bne _08151B2C
	movs r0, 0
	strb r0, [r6]
	b _08151B30
	.pool
_08151B2C:
	ldrh r0, [r6, 0x2]
	bics r0, r7
_08151B30:
	strh r0, [r6, 0x2]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8151A9C

	thumb_func_start sub_8151B3C
sub_8151B3C: @ 8151B3C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	strh r4, [r5]
	adds r0, r5, 0x4
	movs r1, 0
	movs r2, 0xC0
	bl memset
_08151B4E:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r5, r0
	strb r4, [r0, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08151B4E
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8151B3C

	thumb_func_start sub_8151B68
sub_8151B68: @ 8151B68
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r5, r1, 0
	movs r3, 0
	movs r4, 0
	ldrb r0, [r2, 0x5]
	lsrs r0, 7
	cmp r0, 0
	bne _08151B7E
	adds r4, r2, 0x4
	b _08151B9C
_08151B7E:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bhi _08151B9C
	lsls r0, r3, 1
	adds r0, r3
	lsls r1, r0, 2
	adds r0, r2, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 7
	cmp r0, 0
	bne _08151B7E
	adds r0, r1, 0x4
	adds r4, r2, r0
_08151B9C:
	cmp r4, 0
	beq _08151BCA
	ldrb r1, [r4, 0x1]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	adds r1, r4, 0x4
	adds r0, r5, 0
	ldm r0!, {r2,r4}
	stm r1!, {r2,r4}
	adds r0, r3, 0
	b _08151BCC
_08151BCA:
	movs r0, 0xFF
_08151BCC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8151B68

	thumb_func_start sub_8151BD4
sub_8151BD4: @ 8151BD4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0x1]
	movs r2, 0x40
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08151C16
	ldrb r1, [r4, 0xB]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08151C16
	ldrh r2, [r4, 0x6]
	ldrb r0, [r4, 0x8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151C16
	ldr r5, =gUnknown_02037B14
	ldr r3, =gUnknown_02037714
_08151BFC:
	lsls r0, r2, 1
	adds r1, r0, r5
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4, 0x6]
	ldrb r1, [r4, 0x8]
	adds r0, r1
	cmp r2, r0
	blt _08151BFC
_08151C16:
	adds r0, r4, 0x4
	movs r1, 0
	movs r2, 0x8
	bl memset
	ldrb r1, [r4, 0x1]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	subs r1, 0x10
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	movs r1, 0x7F
	ands r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0
	strb r0, [r4, 0x3]
	strb r0, [r4, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8151BD4

	thumb_func_start sub_8151C50
sub_8151C50: @ 8151C50
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	movs r5, 0
	cmp r2, 0
	bne _08151C74
	movs r1, 0xF
	ands r1, r4
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x4
	adds r0, r6, r0
	bl sub_8151BD4
	b _08151CA0
_08151C74:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08151C94
	lsls r0, r5, 1
	adds r0, r5
	lsls r1, r0, 2
	adds r0, r6, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 7
	cmp r0, 0
	beq _08151C94
	adds r0, r1, 0x4
	adds r0, r6, r0
	bl sub_8151BD4
_08151C94:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _08151C74
_08151CA0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8151C50

	thumb_func_start sub_8151CA8
sub_8151CA8: @ 8151CA8
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	movs r3, 0
	cmp r2, 0
	bne _08151CDC
	movs r0, 0xF
	adds r3, r0, 0
	ands r3, r4
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r5, r1
	ldrb r2, [r1, 0x5]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x1
	lsls r0, r3
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	b _08151D20
_08151CDC:
	movs r6, 0x1
	movs r7, 0x41
	negs r7, r7
_08151CE2:
	adds r0, r4, 0
	ands r0, r6
	cmp r0, 0
	beq _08151D00
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r5, r0
	ldrb r1, [r2, 0x5]
	lsrs r0, r1, 7
	cmp r0, 0
	beq _08151D00
	lsls r0, r1, 25
	cmp r0, 0
	blt _08151D06
_08151D00:
	lsls r0, r4, 17
	lsrs r4, r0, 16
	b _08151D16
_08151D06:
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x5]
	adds r0, r6, 0
	lsls r0, r3
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08151D16:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bls _08151CE2
_08151D20:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8151CA8

	thumb_func_start sub_8151D28
sub_8151D28: @ 8151D28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	movs r0, 0
	mov r12, r0
	cmp r2, 0
	bne _08151DB0
	movs r1, 0xF
	ands r1, r7
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x4
	mov r1, r8
	adds r3, r1, r0
	ldrb r1, [r3, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _08151E3A
	ldrb r1, [r3, 0xB]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08151D8E
	ldrh r2, [r3, 0x6]
	ldrb r0, [r3, 0x8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151D8E
	ldr r5, =gUnknown_02037B14
	ldr r4, =gUnknown_02037714
_08151D74:
	lsls r0, r2, 1
	adds r1, r0, r5
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r3, 0x6]
	ldrb r1, [r3, 0x8]
	adds r0, r1
	cmp r2, r0
	blt _08151D74
_08151D8E:
	ldrb r0, [r3, 0x1]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r3, 0x1]
	movs r1, 0x1
	mov r2, r12
	lsls r1, r2
	mov r2, r8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	b _08151E3A
	.pool
_08151DB0:
	movs r0, 0x1
	mov r9, r0
	movs r1, 0x40
	mov r10, r1
_08151DB8:
	mov r2, r12
	lsls r0, r2, 1
	add r0, r12
	lsls r0, 2
	adds r0, 0x4
	mov r1, r8
	adds r3, r1, r0
	adds r0, r7, 0
	mov r2, r9
	ands r0, r2
	cmp r0, 0
	beq _08151DDA
	ldrb r1, [r3, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	beq _08151DE4
_08151DDA:
	lsls r0, r7, 17
	lsrs r7, r0, 16
	mov r5, r12
	adds r5, 0x1
	b _08151E30
_08151DE4:
	ldrb r1, [r3, 0xB]
	mov r0, r10
	ands r0, r1
	mov r5, r12
	adds r5, 0x1
	cmp r0, 0
	beq _08151E1A
	ldrh r2, [r3, 0x6]
	ldrb r0, [r3, 0x8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151E1A
	ldr r6, =gUnknown_02037B14
	ldr r4, =gUnknown_02037714
_08151E00:
	lsls r0, r2, 1
	adds r1, r0, r6
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r3, 0x6]
	ldrb r1, [r3, 0x8]
	adds r0, r1
	cmp r2, r0
	blt _08151E00
_08151E1A:
	ldrb r1, [r3, 0x1]
	mov r0, r10
	orrs r0, r1
	strb r0, [r3, 0x1]
	mov r1, r9
	mov r0, r12
	lsls r1, r0
	mov r2, r8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_08151E30:
	lsls r0, r5, 24
	lsrs r0, 24
	mov r12, r0
	cmp r0, 0xF
	bls _08151DB8
_08151E3A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8151D28

	thumb_func_start sub_8151E50
sub_8151E50: @ 8151E50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	movs r0, 0
	mov r10, r0
	ldr r1, [sp]
	ldrh r0, [r1]
	cmp r0, 0
	bne _08151E6C
	b _08151FF6
_08151E6C:
	movs r2, 0xF
	mov r9, r2
	movs r3, 0x10
	negs r3, r3
	mov r8, r3
	movs r7, 0x1
_08151E78:
	mov r5, r10
	lsls r0, r5, 1
	add r0, r10
	lsls r0, 2
	adds r0, 0x4
	ldr r1, [sp]
	adds r4, r1, r0
	ldrb r2, [r4, 0x1]
	movs r3, 0xC0
	ands r3, r2
	cmp r3, 0x80
	beq _08151E92
	b _08151FE6
_08151E92:
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08151EA8
	ldrb r0, [r4, 0xB]
	ands r3, r0
	cmp r3, 0
	beq _08151EA8
	b _08151FE6
_08151EA8:
	ldrb r0, [r4, 0x2]
	subs r0, 0x1
	strb r0, [r4, 0x2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08151EB8
	b _08151FE6
_08151EB8:
	ldrb r0, [r4, 0x9]
	strb r0, [r4, 0x2]
	ldrh r0, [r4, 0x6]
	ldrb r1, [r4, 0x8]
	lsls r2, 28
	lsrs r2, 28
	ldrh r3, [r4, 0x4]
	bl pal_fade_1
	ldrb r5, [r4, 0xB]
	lsls r0, r5, 26
	asrs r0, 30
	cmp r0, 0x1
	beq _08151F16
	cmp r0, 0x1
	bgt _08151EE4
	cmp r0, 0
	beq _08151EEA
	b _08151FD0
	.pool
_08151EE4:
	cmp r0, 0x2
	beq _08151F92
	b _08151FD0
_08151EEA:
	ldrb r2, [r4, 0x1]
	lsls r1, r2, 28
	lsrs r0, r1, 28
	adds r0, 0x1
	mov r3, r9
	ands r0, r3
	mov r6, r8
	adds r3, r6, 0
	ands r3, r2
	orrs r3, r0
	strb r3, [r4, 0x1]
	lsrs r1, 28
	lsls r0, r5, 28
	asrs r0, 28
	cmp r1, r0
	bne _08151FD0
	ldrb r0, [r4, 0x3]
	adds r0, 0x1
	strb r0, [r4, 0x3]
	ands r3, r6
	strb r3, [r4, 0x1]
	b _08151FD0
_08151F16:
	ldrb r3, [r4, 0x1]
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _08151F54
	lsls r0, r3, 28
	lsrs r0, 28
	subs r0, 0x1
	mov r5, r9
	ands r0, r5
	mov r2, r8
	ands r2, r3
	orrs r2, r0
	strb r2, [r4, 0x1]
	cmp r0, 0
	bne _08151FD0
	ldrb r0, [r4, 0x3]
	adds r0, 0x1
	strb r0, [r4, 0x3]
	lsls r0, r2, 27
	lsrs r0, 31
	eors r0, r7
	ands r0, r7
	lsls r0, 4
	movs r3, 0x11
	negs r3, r3
	adds r1, r3, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0x1]
	b _08151FD0
_08151F54:
	lsls r0, r5, 28
	asrs r0, 28
	subs r0, 0x1
	mov r5, r9
	ands r0, r5
	lsls r2, r3, 28
	lsrs r1, r2, 28
	adds r1, 0x1
	ands r1, r5
	mov r5, r8
	ands r3, r5
	orrs r3, r1
	strb r3, [r4, 0x1]
	lsrs r2, 28
	cmp r2, r0
	bne _08151FD0
	ldrb r0, [r4, 0x3]
	adds r0, 0x1
	strb r0, [r4, 0x3]
	lsls r0, r3, 27
	lsrs r0, 31
	eors r0, r7
	ands r0, r7
	lsls r0, 4
	movs r2, 0x11
	negs r2, r2
	adds r1, r2, 0
	ands r3, r1
	orrs r3, r0
	strb r3, [r4, 0x1]
	b _08151FD0
_08151F92:
	ldrb r2, [r4, 0x1]
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _08151FA2
	mov r0, r8
	ands r0, r2
	b _08151FB0
_08151FA2:
	lsls r1, r5, 28
	asrs r1, 28
	mov r3, r9
	ands r1, r3
	mov r0, r8
	ands r0, r2
	orrs r0, r1
_08151FB0:
	strb r0, [r4, 0x1]
	ldrb r2, [r4, 0x1]
	lsls r0, r2, 27
	lsrs r0, 31
	eors r0, r7
	ands r0, r7
	lsls r0, 4
	movs r5, 0x11
	negs r5, r5
	adds r1, r5, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	adds r0, 0x1
	strb r0, [r4, 0x3]
_08151FD0:
	ldrb r1, [r4, 0xA]
	cmp r1, 0xFF
	beq _08151FE6
	ldrb r0, [r4, 0x3]
	cmp r0, r1
	bne _08151FE6
	ldrb r1, [r4]
	ldr r0, [sp]
	movs r2, 0
	bl sub_8151D28
_08151FE6:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0xF
	bhi _08151FF6
	b _08151E78
_08151FF6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8151E50

	thumb_func_start sub_8152008
sub_8152008: @ 8152008
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, [sp, 0x14]
	ldr r4, [sp, 0x18]
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	lsrs r3, 19
	adds r3, r2
	lsls r3, 1
	adds r6, r3
	cmp r1, r4
	bcs _08152052
_08152030:
	lsls r0, r1, 6
	adds r2, r6, r0
	movs r0, 0
	adds r3, r1, 0x1
	cmp r0, r5
	bcs _0815204A
_0815203C:
	strh r7, [r2]
	adds r2, 0x2
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bcc _0815203C
_0815204A:
	lsls r0, r3, 24
	lsrs r1, r0, 24
	cmp r1, r4
	bcc _08152030
_08152052:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8152008

	thumb_func_start sub_8152058
sub_8152058: @ 8152058
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r0, [sp, 0x14]
	ldr r4, [sp, 0x18]
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r6, r4, 24
	movs r4, 0
	lsrs r3, 19
	adds r3, r2
	lsls r3, 1
	adds r7, r3
	cmp r4, r6
	bcs _081520A2
_0815207C:
	lsls r0, r4, 6
	adds r2, r7, r0
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bcs _0815209A
_08152088:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r5
	bcc _08152088
_0815209A:
	lsls r0, r4, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _0815207C
_081520A2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8152058

	.align 2, 0 @ Don't pad with nop.
