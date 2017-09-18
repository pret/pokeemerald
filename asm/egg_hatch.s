	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_807228C
sub_807228C: @ 807228C
	push {r4-r6,lr}
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	cmp r5, r6
	bcs _080722D6
_0807229C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _080722CC
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x28
	beq _080722C4
	cmp r0, 0x31
	bne _080722CC
_080722C4:
	movs r0, 0x2
	b _080722D8
	.pool
_080722CC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _0807229C
_080722D6:
	movs r0, 0x1
_080722D8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_807228C

	thumb_func_start sub_80722E0
sub_80722E0: @ 80722E0
	push {r4,lr}
	bl sub_80D22D0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x6
	bl sub_80C7050
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80722E0

	.align 2, 0 @ Don't pad with nop.
