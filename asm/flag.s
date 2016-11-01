	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetFlagPointer
@ u8 *GetFlagPointer(u16 flagId)
GetFlagPointer: @ 809D6EC
	push {lr}
	lsls r1, r0, 16
	lsrs r2, r1, 16
	adds r3, r2, 0
	cmp r2, 0
	bne _0809D6FC
	movs r0, 0
	b _0809D72E
_0809D6FC:
	ldr r0, =0x00003fff
	cmp r2, r0
	bhi _0809D71C
	ldr r0, =0x03005d8c
	lsrs r1, 19
	ldr r2, =0x00001270
	adds r1, r2
	ldr r0, [r0]
	b _0809D72C
	.pool
_0809D71C:
	ldr r1, =0xffffc000
	adds r0, r3, r1
	cmp r0, 0
	bge _0809D728
	ldr r2, =0xffffc007
	adds r0, r3, r2
_0809D728:
	asrs r0, 3
	ldr r1, =0x020375fc
_0809D72C:
	adds r0, r1
_0809D72E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetFlagPointer

	thumb_func_start FlagSet
@ bool8 FlagSet(u16 flagId)
FlagSet: @ 809D740
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	adds r2, r0, 0
	cmp r2, 0
	beq _0809D760
	movs r0, 0x7
	ands r0, r4
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
_0809D760:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagSet

	thumb_func_start FlagReset
@ bool8 FlagReset(u16 flagId)
FlagReset: @ 809D768
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	adds r2, r0, 0
	cmp r2, 0
	beq _0809D788
	movs r0, 0x7
	ands r0, r4
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
_0809D788:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagReset

	thumb_func_start FlagGet
@ bool8 FlagGet(u16 flagId)
FlagGet: @ 809D790
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetFlagPointer
	cmp r0, 0
	beq _0809D7B4
	ldrb r0, [r0]
	movs r1, 0x7
	ands r1, r4
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809D7B4
	movs r0, 0x1
	b _0809D7B6
_0809D7B4:
	movs r0, 0
_0809D7B6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FlagGet

	.align 2, 0 @ Don't pad with nop.
