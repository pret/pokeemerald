	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start ResetMiniGamesResults
ResetMiniGamesResults: @ 80845CC
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	movs r5, 0
	strh r5, [r0]
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	movs r0, 0xF6
	lsls r0, 1
	adds r1, r0
	ldr r6, =0x01000008
	mov r0, sp
	adds r2, r6, 0
	bl CpuSet
	ldr r0, [r4]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl SetBerryPowder
	bl ResetPokeJumpResults
	mov r0, sp
	adds r0, 0x2
	strh r5, [r0]
	ldr r1, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r1, r2
	adds r2, r6, 0
	bl CpuSet
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetMiniGamesResults

	.align 2, 0 @ Don't pad with nop.
