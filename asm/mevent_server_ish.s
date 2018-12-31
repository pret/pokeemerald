	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text






	thumb_func_start sub_801D484
sub_801D484: @ 801D484
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02022C80
	movs r0, 0x50
	bl AllocZeroed
	str r0, [r4]
	movs r1, 0x1
	movs r2, 0
	bl mevent_srv_ish_init
	ldr r0, [r4]
	str r5, [r0, 0x4C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D484

	thumb_func_start sub_801D4A8
sub_801D4A8: @ 801D4A8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =gUnknown_02022C80
	ldr r0, [r4]
	cmp r0, 0
	bne _0801D4BC
	movs r0, 0x6
	b _0801D4DC
	.pool
_0801D4BC:
	bl mevent_srv_ish_exec
	adds r5, r0, 0
	cmp r5, 0x6
	bne _0801D4DA
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	strh r1, [r6]
	bl sub_801D55C
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801D4DA:
	adds r0, r5, 0
_0801D4DC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D4A8

	thumb_func_start sub_801D4E4
sub_801D4E4: @ 801D4E4
	ldr r0, =gUnknown_02022C80
	ldr r1, [r0]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	bx lr
	.pool
	thumb_func_end sub_801D4E4

	thumb_func_start sub_801D4F4
sub_801D4F4: @ 801D4F4
	ldr r0, =gUnknown_02022C80
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_801D4F4

	thumb_func_start sub_801D500
sub_801D500: @ 801D500
	ldr r1, =gUnknown_02022C80
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_801D500

	thumb_func_start mevent_srv_ish_init
mevent_srv_ish_init: @ 801D50C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	movs r5, 0x80
	lsls r5, 3
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x14]
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x18]
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x1C]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x20]
	adds r4, 0x24
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_801D8D8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_ish_init

	thumb_func_start sub_801D55C
sub_801D55C: @ 801D55C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	bl Free
	ldr r0, [r4, 0x18]
	bl Free
	ldr r0, [r4, 0x1C]
	bl Free
	ldr r0, [r4, 0x20]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D55C

	thumb_func_start sub_801D580
sub_801D580: @ 801D580
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x18]
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r0, 0
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D580

	thumb_func_start sub_801D59C
sub_801D59C: @ 801D59C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r0, 0
	str r0, [sp]
	ldr r1, [r4, 0x14]
	ldr r2, =0x05000100
	mov r0, sp
	bl CpuSet
	ldr r2, [r4, 0x14]
	str r5, [r2]
	adds r4, 0x24
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0x4
	bl sub_801D904
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D59C

	thumb_func_start sub_801D5D0
sub_801D5D0: @ 801D5D0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	ldr r1, =gUnknown_082F2598
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r1, 0
	str r1, [r4, 0x10]
	movs r0, 0x4
	str r0, [r4, 0x8]
	str r1, [r4, 0xC]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D5D0

	thumb_func_start sub_801D5F8
sub_801D5F8: @ 801D5F8
	movs r0, 0x6
	bx lr
	thumb_func_end sub_801D5F8

	thumb_func_start sub_801D5FC
sub_801D5FC: @ 801D5FC
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_801D8C0
	cmp r0, 0
	beq _0801D612
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D612:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D5FC

	thumb_func_start sub_801D61C
sub_801D61C: @ 801D61C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_801D8CC
	cmp r0, 0
	beq _0801D632
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D632:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D61C

	thumb_func_start sub_801D63C
sub_801D63C: @ 801D63C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	lsls r2, r0, 3
	ldr r1, [r4, 0x1C]
	adds r2, r1, r2
	adds r0, 0x1
	str r0, [r4, 0x10]
	ldr r0, [r2]
	cmp r0, 0x15
	bls _0801D654
	b _0801D804
_0801D654:
	lsls r0, 2
	ldr r1, =_0801D664
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801D664:
	.4byte _0801D804
	.4byte _0801D6BC
	.4byte _0801D6C4
	.4byte _0801D6D4
	.4byte _0801D70E
	.4byte _0801D716
	.4byte _0801D6FE
	.4byte _0801D708
	.4byte _0801D764
	.4byte _0801D790
	.4byte _0801D788
	.4byte _0801D72C
	.4byte _0801D742
	.4byte _0801D758
	.4byte _0801D77C
	.4byte _0801D7B8
	.4byte _0801D7BC
	.4byte _0801D7C4
	.4byte _0801D7D0
	.4byte _0801D6EA
	.4byte _0801D6D8
	.4byte _0801D7F0
_0801D6BC:
	ldr r0, [r2, 0x4]
	str r0, [r4, 0x4]
	movs r0, 0x1
	b _0801D7FE
_0801D6C4:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r1, [r2, 0x4]
	ldr r2, [r4, 0x18]
	bl sub_801D928
	movs r0, 0x2
	b _0801D7FE
_0801D6D4:
	movs r0, 0x3
	b _0801D7FE
_0801D6D8:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x14
	movs r3, 0
	bl sub_801D904
	movs r0, 0x3
	b _0801D7FE
_0801D6EA:
	ldrb r0, [r2, 0x4]
	bl GetGameStat
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0x12
	bl sub_801D59C
	movs r0, 0x3
	b _0801D7FE
_0801D6FE:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0801D706
	b _0801D804
_0801D706:
	b _0801D70E
_0801D708:
	ldr r0, [r4, 0x4]
	cmp r0, 0x1
	bne _0801D804
_0801D70E:
	adds r0, r4, 0
	bl sub_801D580
	b _0801D804
_0801D716:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _0801D806
_0801D72C:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x3
	b _0801D806
_0801D742:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x5
	b _0801D806
_0801D758:
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _0801D806
_0801D764:
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x4C]
	bl sub_801B580
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x11
	movs r3, 0x64
	bl sub_801D904
	b _0801D804
_0801D77C:
	ldr r2, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x13
	bl sub_801D59C
	b _0801D804
_0801D788:
	ldr r0, [r4, 0x18]
	bl sub_801B21C
	b _0801D804
_0801D790:
	ldr r0, [r4, 0x18]
	bl sub_801B1A4
	cmp r0, 0
	bne _0801D7AC
	ldr r0, [r4, 0x18]
	bl sub_801B078
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_801D59C
	b _0801D804
_0801D7AC:
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0x1
	bl sub_801D59C
	b _0801D804
_0801D7B8:
	movs r0, 0x6
	b _0801D7FE
_0801D7BC:
	ldr r0, [r4, 0x18]
	bl sub_801B508
	b _0801D804
_0801D7C4:
	ldr r0, [r4, 0x18]
	movs r1, 0xFA
	lsls r1, 2
	bl sub_80992A0
	b _0801D804
_0801D7D0:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bec
	adds r0, r1
	ldr r1, [r4, 0x18]
	movs r2, 0xBC
	bl memcpy
	bl ValidateEReaderTrainer
	b _0801D804
	.pool
_0801D7F0:
	ldr r0, =gDecompressionBuffer
	ldr r1, [r4, 0x18]
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r0, 0x7
_0801D7FE:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D804:
	movs r0, 0x1
_0801D806:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D63C

	thumb_func_start sub_801D810
sub_801D810: @ 801D810
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801D822
	movs r0, 0x4
	str r0, [r1, 0x8]
	movs r0, 0
	str r0, [r1, 0xC]
_0801D822:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_801D810

	thumb_func_start sub_801D828
sub_801D828: @ 801D828
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0801D838
	cmp r0, 0x1
	beq _0801D846
	b _0801D858
_0801D838:
	ldr r0, [r4, 0x18]
	bl sub_8153870
	ldr r0, [r4, 0xC]
	adds r0, 0x1
	str r0, [r4, 0xC]
	b _0801D858
_0801D846:
	adds r0, r4, 0x4
	bl sub_8153884
	adds r1, r0, 0
	cmp r1, 0
	bne _0801D858
	movs r0, 0x4
	str r0, [r4, 0x8]
	str r1, [r4, 0xC]
_0801D858:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D828

	thumb_func_start sub_801D860
sub_801D860: @ 801D860
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, =gDecompressionBuffer
	adds r0, r4, 0x4
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	bl _call_via_r3
	cmp r0, 0x1
	bne _0801D880
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D880:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D860

	thumb_func_start mevent_srv_ish_exec
mevent_srv_ish_exec: @ 801D894
	push {r4,r5,lr}
	sub sp, 0x20
	mov r2, sp
	ldr r1, =gUnknown_082F255C
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3,r4}
	stm r2!, {r3,r4}
	ldr r1, [r0, 0x8]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	bl _call_via_r1
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_srv_ish_exec

	.align 2, 0 @ don't pad with nop

