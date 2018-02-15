	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start npc_before_player_of_type
npc_before_player_of_type: @ 8135424
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gUnknown_0203AB40
	adds r1, r4, 0x2
	adds r0, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	bl PlayerGetZCoord
	strb r0, [r4, 0x4]
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	ldrb r2, [r4, 0x4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gMapObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r0, [r2, 0x5]
	cmp r0, r5
	bne _08135470
	ldr r1, =gSpecialVar_LastTalked
	ldrb r0, [r2, 0x8]
	strh r0, [r1]
	movs r0, 0x1
	b _08135472
	.pool
_08135470:
	movs r0, 0
_08135472:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end npc_before_player_of_type

	thumb_func_start oei_task_add
oei_task_add: @ 8135478
	push {lr}
	ldr r0, =gUnknown_0203AB40
	adds r1, r0, 0x2
	bl GetXYCoordsOneStepInFrontOfPlayer
	ldr r0, =task08_080C9820
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_task_add

	thumb_func_start task08_080C9820
task08_080C9820: @ 813549C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl ScriptContext2_Enable
	ldr r1, =gPlayerAvatar
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrb r1, [r1, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _081354D2
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _0813551E
_081354D2:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x5
	bne _08135504
	movs r0, 0x3B
	bl FieldEffectStart
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8135578
	b _0813551C
	.pool
_08135504:
	bl sub_808C114
	adds r0, r4, 0
	movs r1, 0x39
	bl FieldObjectSetSpecialAnim
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_813552C
_0813551C:
	str r0, [r1]
_0813551E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task08_080C9820

	thumb_func_start sub_813552C
sub_813552C: @ 813552C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08135560
	movs r0, 0x3B
	bl FieldEffectStart
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8135578
	str r0, [r1]
_08135560:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813552C

	thumb_func_start sub_8135578
sub_8135578: @ 8135578
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081355FC
	bl player_get_direction_lower_nybble
	ldr r6, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r6, 0x4]
	cmp r0, 0x1
	bne _0813559E
	str r4, [r6, 0x8]
_0813559E:
	ldr r1, [r6, 0x4]
	cmp r1, 0x2
	bne _081355A8
	movs r0, 0x1
	str r0, [r6, 0x8]
_081355A8:
	cmp r1, 0x3
	bne _081355B0
	movs r0, 0x2
	str r0, [r6, 0x8]
_081355B0:
	cmp r1, 0x4
	bne _081355B8
	movs r0, 0x3
	str r0, [r6, 0x8]
_081355B8:
	ldr r5, =gPlayerAvatar
	ldrb r0, [r5, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	bl GetPlayerAvatarGraphicsIdByCurrentState
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r1, [r6, 0x8]
	bl StartSpriteAnim
	movs r0, 0x6
	bl FieldEffectActiveListRemove
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_813561C
	str r1, [r0]
_081355FC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135578

	thumb_func_start sub_813561C
sub_813561C: @ 813561C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x18]
	lsls r1, 16
	ldrh r0, [r0, 0x1A]
	orrs r1, r0
	bl _call_via_r1
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0x6]
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813561C

	thumb_func_start sub_8135654
sub_8135654: @ 8135654
	push {r4,lr}
	bl ShouldDoBrailleStrengthEffect
	lsls r0, 24
	cmp r0, 0
	beq _0813568C
	ldr r4, =gSpecialVar_Result
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r1, =gUnknown_03005DB0
	ldr r0, =FieldCallback_Teleport
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_8179834
	b _081356A8
	.pool
_0813568C:
	movs r0, 0x56
	bl npc_before_player_of_type
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813569E
	movs r0, 0
	b _081356AC
_0813569E:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =FieldCallback_Teleport
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =sub_81356C4
_081356A8:
	str r0, [r1]
	movs r0, 0x1
_081356AC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8135654

	thumb_func_start sub_81356C4
sub_81356C4: @ 81356C4
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	ldr r0, =Route111_EventScript_2907F0
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81356C4

	thumb_func_start oei_rocksmash
oei_rocksmash: @ 81356E4
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_8135714
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	movs r0, 0x13
	bl IncrementGameStat
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_rocksmash

	thumb_func_start sub_8135714
sub_8135714: @ 8135714
	push {lr}
	movs r0, 0x83
	bl PlaySE
	movs r0, 0x25
	bl FieldEffectActiveListRemove
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_8135714

	thumb_func_start sub_813572C
sub_813572C: @ 813572C
	push {lr}
	bl sub_80FE314
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813573E
	movs r0, 0
	b _0813574C
_0813573E:
	ldr r1, =gUnknown_03005DB0
	ldr r0, =FieldCallback_Teleport
	str r0, [r1]
	ldr r1, =gUnknown_0203CEEC
	ldr r0, =hm2_dig
	str r0, [r1]
	movs r0, 0x1
_0813574C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813572C

	thumb_func_start hm2_dig
hm2_dig: @ 8135760
	push {lr}
	bl Overworld_ResetStateAfterDigEscRope
	movs r0, 0x26
	bl FieldEffectStart
	bl GetCursorSelectionMonId
	ldr r1, =gFieldEffectArguments
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end hm2_dig

	thumb_func_start sub_8135780
sub_8135780: @ 8135780
	push {lr}
	bl oei_task_add
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =sub_81357BC
	lsrs r0, r2, 16
	strh r0, [r1, 0x18]
	strh r2, [r1, 0x1A]
	bl ShouldDoBrailleDigEffect
	lsls r0, 24
	cmp r0, 0
	bne _081357AC
	movs r0, 0x1
	bl SetPlayerAvatarTransitionFlags
_081357AC:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8135780

	thumb_func_start sub_81357BC
sub_81357BC: @ 81357BC
	push {r4,lr}
	movs r0, 0x26
	bl FieldEffectActiveListRemove
	bl ShouldDoBrailleDigEffect
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _081357D6
	bl DoBrailleDigEffect
	b _081357EE
_081357D6:
	ldr r0, =task08_080A1C44
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
_081357EE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81357BC


	.align 2, 0 @ Don't pad with nop.
