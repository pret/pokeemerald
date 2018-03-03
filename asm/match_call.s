	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D1920
sub_81D1920: @ 81D1920
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r1
	movs r5, 0
	ldr r0, [r6]
	cmp r0, 0
	beq _081D1940
	adds r1, r6, 0
_081D1936:
	adds r1, 0x8
	adds r5, 0x1
	ldr r0, [r1]
	cmp r0, 0
	bne _081D1936
_081D1940:
	cmp r5, 0
	beq _081D1946
	subs r5, 0x1
_081D1946:
	ldr r0, =0x0000ffff
	mov r8, r0
	lsls r0, r5, 3
	adds r0, 0x4
	adds r4, r0, r6
	b _081D195C
	.pool
_081D1958:
	subs r4, 0x8
	subs r5, 0x1
_081D195C:
	lsls r7, r5, 3
	cmp r5, 0
	beq _081D1974
	ldrh r0, [r4]
	cmp r0, r8
	beq _081D1958
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D1958
_081D1974:
	adds r4, r7, r6
	ldrh r1, [r4, 0x6]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1984
	adds r0, r1, 0
	bl FlagSet
_081D1984:
	ldr r1, [r4]
	mov r0, r9
	bl StringExpandPlaceholders
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1920

	thumb_func_start sub_81D199C
sub_81D199C: @ 81D199C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r10, r2
	lsls r1, 16
	lsrs r7, r1, 16
	movs r5, 0
	ldr r0, [r6]
	cmp r0, 0
	beq _081D19E6
	ldrh r0, [r6, 0x4]
	ldr r1, =0x0000fffe
	cmp r0, r1
	beq _081D1A24
	ldr r0, =0x0000ffff
	mov r9, r0
	mov r8, r1
	adds r4, r6, 0
_081D19C6:
	ldrh r0, [r4, 0x4]
	cmp r0, r9
	beq _081D19D6
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D19E6
_081D19D6:
	adds r4, 0x8
	adds r5, 0x1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D19E6
	ldrh r0, [r4, 0x4]
	cmp r0, r8
	bne _081D19C6
_081D19E6:
	lsls r0, r5, 3
	adds r0, r6
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000fffe
	cmp r1, r0
	beq _081D1A24
	cmp r5, 0
	beq _081D19F8
	subs r5, 0x1
_081D19F8:
	lsls r0, r5, 3
	adds r4, r0, r6
	ldrh r1, [r4, 0x6]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081D1A0A
	adds r0, r1, 0
	bl FlagSet
_081D1A0A:
	ldr r1, [r4]
	mov r0, r10
	bl StringExpandPlaceholders
	b _081D1A5C
	.pool
_081D1A1C:
	adds r5, 0x2
	b _081D1A50
_081D1A20:
	adds r5, 0x3
	b _081D1A50
_081D1A24:
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D1A50
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D1A1C
	adds r0, r7, 0
	bl CountBattledRematchTeams
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D1A20
	adds r5, 0x1
_081D1A50:
	lsls r0, r5, 3
	adds r0, r6
	ldr r1, [r0]
	mov r0, r10
	bl StringExpandPlaceholders
_081D1A5C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D199C

	thumb_func_start sub_81D1A78
sub_81D1A78: @ 81D1A78
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r6, r2, 0
	cmp r0, 0x14
	bhi _081D1AA2
	ldr r1, =gUnknown_086252A8
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_81D1574
	ldr r1, =gUnknown_08625374
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl _call_via_r3
_081D1AA2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1A78

	thumb_func_start sub_81D1AB0
sub_81D1AB0: @ 81D1AB0
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1AB0

	thumb_func_start sub_81D1ABC
sub_81D1ABC: @ 81D1ABC
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0
	bne _081D1AD0
	ldrh r0, [r4, 0x4]
	bl sub_81D1B0C
	b _081D1AD2
_081D1AD0:
	str r0, [r2]
_081D1AD2:
	ldr r0, [r4, 0x8]
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1ABC

	thumb_func_start sub_81D1ADC
sub_81D1ADC: @ 81D1ADC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r4, 0x4]
	bl sub_81D1B0C
	ldr r0, [r4, 0x8]
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1ADC

	thumb_func_start sub_81D1AF4
sub_81D1AF4: @ 81D1AF4
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1AF4

	thumb_func_start sub_81D1B00
sub_81D1B00: @ 81D1B00
	ldr r3, [r0, 0x4]
	str r3, [r1]
	ldr r0, [r0, 0x8]
	str r0, [r2]
	bx lr
	thumb_func_end sub_81D1B00

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
