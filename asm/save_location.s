	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sav1_are_mapnumbers_in_given_list
sav1_are_mapnumbers_in_given_list: @ 81AFC84
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _081AFCC4
	adds r4, r1, 0
	adds r1, r2, 0
_081AFCAA:
	ldrh r0, [r1]
	cmp r0, r3
	bne _081AFCBC
	movs r0, 0x1
	b _081AFCC6
	.pool
_081AFCBC:
	adds r1, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _081AFCAA
_081AFCC4:
	movs r0, 0
_081AFCC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sav1_are_mapnumbers_in_given_list

	thumb_func_start sav1_is_in_pokecenter
sav1_is_in_pokecenter: @ 81AFCCC
	push {lr}
	ldr r0, =gUnknown_086143BC
	bl sav1_are_mapnumbers_in_given_list
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav1_is_in_pokecenter

	thumb_func_start sub_81AFCDC
sub_81AFCDC: @ 81AFCDC
	push {lr}
	ldr r0, =gUnknown_0861440A
	bl sav1_are_mapnumbers_in_given_list
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81AFCDC

	thumb_func_start sub_81AFCEC
sub_81AFCEC: @ 81AFCEC
	push {lr}
	ldr r0, =gUnknown_0861440E
	bl sav1_are_mapnumbers_in_given_list
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81AFCEC

	thumb_func_start sav2_set_x9_bit3_when_sav1_in_pokecenter
sav2_set_x9_bit3_when_sav1_in_pokecenter: @ 81AFCFC
	push {lr}
	bl sav1_is_in_pokecenter
	cmp r0, 0
	bne _081AFD18
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0xFD
	ands r0, r1
	b _081AFD22
	.pool
_081AFD18:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	orrs r0, r1
_081AFD22:
	strb r0, [r2, 0x9]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sav2_set_x9_bit3_when_sav1_in_pokecenter

	thumb_func_start sub_81AFD2C
sub_81AFD2C: @ 81AFD2C
	push {lr}
	bl sub_81AFCDC
	cmp r0, 0
	bne _081AFD48
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0xFB
	ands r0, r1
	b _081AFD52
	.pool
_081AFD48:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x4
	orrs r0, r1
_081AFD52:
	strb r0, [r2, 0x9]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AFD2C

	thumb_func_start sub_81AFD5C
sub_81AFD5C: @ 81AFD5C
	push {lr}
	bl sub_81AFCEC
	cmp r0, 0
	bne _081AFD78
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0xF7
	ands r0, r1
	b _081AFD82
	.pool
_081AFD78:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x8
	orrs r0, r1
_081AFD82:
	strb r0, [r2, 0x9]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AFD5C

	thumb_func_start sav2_set_x9_depending_on_sav1_map
sav2_set_x9_depending_on_sav1_map: @ 81AFD8C
	push {lr}
	bl sav2_set_x9_bit3_when_sav1_in_pokecenter
	bl sub_81AFD2C
	bl sub_81AFD5C
	pop {r0}
	bx r0
	thumb_func_end sav2_set_x9_depending_on_sav1_map

	thumb_func_start sub_81AFDA0
sub_81AFDA0: @ 81AFDA0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	adds r2, 0xA8
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	movs r1, 0x1
	orrs r0, r1
	movs r1, 0x2
	orrs r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x10
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	movs r1, 0x8
	orrs r0, r1
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_81AFDA0

	thumb_func_start sub_81AFDD0
sub_81AFDD0: @ 81AFDD0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x9]
	movs r0, 0x80
	orrs r0, r1
	strb r0, [r2, 0x9]
	bx lr
	.pool
	thumb_func_end sub_81AFDD0

	.align 2, 0 @ Don't pad with nop.
