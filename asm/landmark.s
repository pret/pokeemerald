	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8145CF4
sub_8145CF4: @ 8145CF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	bl sub_8145D48
	adds r4, r0, 0
	cmp r4, 0
	bne _08145D10
_08145D0C:
	movs r0, 0
	b _08145D42
_08145D10:
	ldr r6, =0x0000ffff
	b _08145D26
	.pool
_08145D18:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_08145D1E:
	adds r4, 0x4
	ldr r0, [r4]
	cmp r0, 0
	beq _08145D0C
_08145D26:
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	cmp r0, r6
	beq _08145D3A
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08145D1E
_08145D3A:
	cmp r5, 0
	bne _08145D18
	ldr r0, [r4]
	ldr r0, [r0]
_08145D42:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8145CF4

	thumb_func_start sub_8145D48
sub_8145D48: @ 8145D48
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	movs r2, 0
	ldr r0, =gUnknown_085B91B8
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0xD5
	beq _08145DB8
	adds r1, r4, 0
_08145D60:
	lsls r0, r2, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, r3
	bhi _08145DB8
	cmp r0, r3
	beq _08145D7E
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r0, r2, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xD5
	bne _08145D60
_08145D7E:
	lsls r0, r2, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xD5
	bne _08145D98
	b _08145DB8
	.pool
_08145D90:
	adds r0, r4, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	b _08145DBA
_08145D98:
	cmp r0, r3
	bne _08145DB8
	ldr r5, =gUnknown_085B91B8
_08145D9E:
	lsls r1, r2, 3
	adds r0, r1, r5
	ldrb r0, [r0, 0x1]
	cmp r0, r6
	beq _08145D90
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r0, r2, 3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r3
	beq _08145D9E
_08145DB8:
	movs r0, 0
_08145DBA:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8145D48

	.align 2, 0 @ Don't pad with nop.
