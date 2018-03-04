	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
