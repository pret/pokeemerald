	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetVarPointer
@ u16 *GetVarPointer(u16 varId)
GetVarPointer: @ 809D648
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, =0x00003fff
	cmp r1, r0
	bhi _0809D660
	movs r0, 0
	b _0809D688
	.pool
_0809D660:
	lsls r0, r1, 16
	cmp r0, 0
	bge _0809D67C
	ldr r0, =gUnknown_081DBA0C
	ldr r2, =0xffff8000
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	b _0809D688
	.pool
_0809D67C:
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r2, 1
	ldr r2, =0xffff939c
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
_0809D688:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetVarPointer

	thumb_func_start VarGet
@ u16 VarGet(u16 varId)
VarGet: @ 809D694
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetVarPointer
	cmp r0, 0
	beq _0809D6A8
	ldrh r0, [r0]
	b _0809D6AA
_0809D6A8:
	adds r0, r4, 0
_0809D6AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end VarGet

	thumb_func_start VarSet
@ bool8 VarSet(u16 varId, u16 value)
VarSet: @ 809D6B0
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	bl GetVarPointer
	cmp r0, 0
	beq _0809D6C8
	strh r4, [r0]
	movs r0, 0x1
	b _0809D6CA
_0809D6C8:
	movs r0, 0
_0809D6CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end VarSet

	thumb_func_start VarGetFieldObjectGraphicsId
@ u8 VarGetFieldObjectGraphicsId(u8 index)
VarGetFieldObjectGraphicsId: @ 809D6D0
	push {lr}
	lsls r0, 24
	lsrs r0, 8
	ldr r1, =0x40100000
	adds r0, r1
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end VarGetFieldObjectGraphicsId

	.align 2, 0 @ Don't pad with nop.
