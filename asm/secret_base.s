	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80EBB28
sub_80EBB28: @ 80EBB28
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffddb
	adds r0, r1
	cmp r0, 0xA2
	bls _080EBB50
	b _080EBE6C
_080EBB50:
	lsls r0, 2
	ldr r1, =_080EBB64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBB64:
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE14
	.4byte _080EBE14
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
_080EBDF0:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EBE30
	.pool
_080EBE14:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
_080EBE30:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EBE6C
	.pool
_080EBE48:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBE6C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBB28

	thumb_func_start sub_80EBE7C
sub_80EBE7C: @ 80EBE7C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000028e
	cmp r1, r0
	bgt _080EBECC
	subs r0, 0x1
	cmp r1, r0
	blt _080EBECC
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBECC
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBECC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBE7C

	.align 2, 0 @ Don't pad with nop.
