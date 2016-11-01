	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8145E84
sub_8145E84: @ 8145E84
	push {r4,lr}
	ldr r4, =0x0300120b
	ldrb r0, [r4]
	cmp r0, 0
	beq _08145E98
	cmp r0, 0x1
	beq _08145EAC
	b _08145EC0
	.pool
_08145E98:
	ldr r0, =0x0300120a
	ldrb r0, [r0]
	bl sub_8145F6C
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _08145EC0
	.pool
_08145EAC:
	bl sub_8145F20
	lsls r0, 24
	cmp r0, 0
	beq _08145EC0
	movs r0, 0
	strb r0, [r4]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
_08145EC0:
	bl RunTasks
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl fade_and_return_progress_probably
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145E84

	thumb_func_start sub_8145EDC
sub_8145EDC: @ 8145EDC
	push {lr}
	ldr r1, =0x0300120a
	strb r0, [r1]
	ldr r0, =sub_8145E84
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145EDC

	.align 2, 0 @ Don't pad with nop.
