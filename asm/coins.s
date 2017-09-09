	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AddCoins
@ bool8 AddCoins(u16 toAdd)
AddCoins: @ 8145C80
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl GetCoins
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000270e
	cmp r1, r0
	bls _08145C9C
	movs r0, 0
	b _08145CC0
	.pool
_08145C9C:
	adds r0, r1, r4
	cmp r1, r0
	ble _08145CAC
	ldr r0, =0x0000270f
	b _08145CBA
	.pool
_08145CAC:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000270f
	cmp r1, r0
	bls _08145CB8
	adds r1, r0, 0
_08145CB8:
	adds r0, r1, 0
_08145CBA:
	bl SetCoins
	movs r0, 0x1
_08145CC0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddCoins

	thumb_func_start SubtractCoins
@ bool8 SubtractCoins(u16 toSub)
SubtractCoins: @ 8145CCC
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcs _08145CE2
	movs r0, 0
	b _08145CEE
_08145CE2:
	subs r0, r4
	lsls r0, 16
	lsrs r0, 16
	bl SetCoins
	movs r0, 0x1
_08145CEE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end SubtractCoins

	.align 2, 0 @ Don't pad with nop.
