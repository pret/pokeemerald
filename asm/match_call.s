	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D1B0C
sub_81D1B0C: @ 81D1B0C
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_81D15BC
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	muls r0, r2
	ldr r2, =gTrainerClassNames
	adds r0, r2
	str r0, [r4]
	adds r1, 0x4
	str r1, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1B0C

	thumb_func_start sub_81D1B40
sub_81D1B40: @ 81D1B40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	movs r5, 0
	ldr r2, =gUnknown_08625388
	movs r0, 0x8
	adds r0, r2
	mov r9, r0
_081D1B54:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D1BBC
	adds r4, r5, 0x1
	lsls r1, 2
	mov r8, r1
	cmp r4, 0x3
	bhi _081D1BA8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D1BA8
	ldr r7, =gUnknown_08625388
_081D1B7C:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r1, r7, 0x4
	adds r0, r1
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D1BA8
	adds r5, r4, 0
	adds r4, r5, 0x1
	cmp r4, 0x3
	bhi _081D1BA8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r6
	beq _081D1B7C
_081D1BA8:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	add r0, r8
	add r0, r9
	ldr r0, [r0]
	b _081D1BC4
	.pool
_081D1BBC:
	adds r5, 0x1
	cmp r5, 0x3
	bls _081D1B54
	movs r0, 0
_081D1BC4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1B40

	thumb_func_start sub_81D1BD0
sub_81D1BD0: @ 81D1BD0
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_08625388
_081D1BD8:
	ldrh r0, [r1]
	cmp r0, r3
	bne _081D1BE8
	ldrh r0, [r1, 0x2]
	b _081D1BF4
	.pool
_081D1BE8:
	adds r1, 0x18
	adds r2, 0x1
	cmp r2, 0x3
	bls _081D1BD8
	movs r0, 0x1
	negs r0, r0
_081D1BF4:
	pop {r1}
	bx r1
	thumb_func_end sub_81D1BD0

	thumb_func_start sub_81D1BF8
sub_81D1BF8: @ 81D1BF8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_081D1BFE:
	adds r0, r4, 0
	bl sub_81D1854
	cmp r0, 0x4E
	beq _081D1C10
	cmp r0, r5
	bne _081D1C10
	movs r0, 0x1
	b _081D1C18
_081D1C10:
	adds r4, 0x1
	cmp r4, 0x14
	ble _081D1BFE
	movs r0, 0
_081D1C18:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D1BF8

	thumb_func_start SetMatchCallRegisteredFlag
SetMatchCallRegisteredFlag: @ 81D1C20
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl sub_81D15CC
	cmp r0, 0
	blt _081D1C3C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
_081D1C3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetMatchCallRegisteredFlag
