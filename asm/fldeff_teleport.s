	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start SetUpFieldMove_Teleport
SetUpFieldMove_Teleport: @ 817C8BC
	push {lr}
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	bl is_light_level_1_2_3_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0817C8D8
	movs r0, 0
	b _0817C8E6
	.pool
_0817C8D8:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =hm_add_c3_launch_phase_2
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm_teleport_run_dp02scr
	str r0, [r1]
	movs r0, 0x1
_0817C8E6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end SetUpFieldMove_Teleport

	thumb_func_start hm_teleport_run_dp02scr
hm_teleport_run_dp02scr: @ 817C8FC
	push {lr}
	bl sub_808469C
	movs r0, 0x3F
	bl FieldEffectStart
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm_teleport_run_dp02scr

	thumb_func_start sub_817C91C
sub_817C91C: @ 817C91C
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_817C94C
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0x1
	bl SetPlayerAvatarTransitionFlags
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C91C

	thumb_func_start sub_817C94C
sub_817C94C: @ 817C94C
	push {lr}
	movs r0, 0x3F
	bl FieldEffectActiveListRemove
	bl sub_80B7FC8
	pop {r0}
	bx r0
	thumb_func_end sub_817C94C

	.align 2, 0 @ Don't pad with nop.
