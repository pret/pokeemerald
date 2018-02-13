	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

//	thumb_func_start hm_prepare_rocksmash
//hm_prepare_rocksmash: @ 8145DC4
//	push {r4,lr}
//	movs r0, 0x57
//	bl npc_before_player_of_type
//	lsls r0, 24
//	lsrs r0, 24
//	cmp r0, 0x1
//	beq _08145DD8
//	movs r0, 0
//	b _08145DF2
//_08145DD8:
//	ldr r4, =gSpecialVar_Result
//	bl GetCursorSelectionMonId
//	lsls r0, 24
//	lsrs r0, 24
//	strh r0, [r4]
//	ldr r1, =gUnknown_03005DB0
//	ldr r0, =FieldCallback_Teleport
//	str r0, [r1]
//	ldr r1, =gUnknown_0203CEEC
//	ldr r0, =sub_8145E0C
//	str r0, [r1]
//	movs r0, 0x1
//_08145DF2:
//	pop {r4}
//	pop {r1}
//	bx r1
//	.pool
//	thumb_func_end hm_prepare_rocksmash

//	thumb_func_start sub_8145E0C
//sub_8145E0C: @ 8145E0C
//	push {lr}
//	bl GetCursorSelectionMonId
//	ldr r1, =gFieldEffectArguments
//	lsls r0, 24
//	lsrs r0, 24
//	str r0, [r1]
//	ldr r0, =FieryPath_EventScript_2908FD
//	bl ScriptContext1_SetupScript
//	pop {r0}
//	bx r0
//	.pool
//	thumb_func_end sub_8145E0C

	thumb_func_start sub_8145E2C
sub_8145E2C: @ 8145E2C
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_8145E74
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	ldr r0, =gFieldEffectArguments
	ldr r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8145E2C

	thumb_func_start sub_8145E74
sub_8145E74: @ 8145E74
	push {lr}
	movs r0, 0x28
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_8145E74

	.align 2, 0 @ Don't pad with nop.
