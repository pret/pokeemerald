	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CheckForTrainersWantingBattle
@ bool8 CheckForTrainersWantingBattle()
CheckForTrainersWantingBattle: @ 80B3BE8
	push {r4-r7,lr}
	ldr r0, =gUnknown_030060A8
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_02038BFC
	strb r1, [r0]
	movs r4, 0
	ldr r6, =gMapObjects
_080B3BF8:
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r6
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _080B3C38
	ldrb r0, [r1, 0x7]
	cmp r0, 0x1
	beq _080B3C12
	cmp r0, 0x3
	bne _080B3C38
_080B3C12:
	adds r0, r4, 0
	bl CheckIfTrainerWantsBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080B3C42
	cmp r0, 0
	beq _080B3C38
	ldr r0, =gUnknown_030060A8
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x1
	bhi _080B3C88
	bl GetMonsStateToDoubles_2
	lsls r0, 24
	cmp r0, 0
	bne _080B3C42
_080B3C38:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080B3BF8
_080B3C42:
	ldr r0, =gUnknown_030060A8
	ldrb r4, [r0]
	adds r5, r0, 0
	cmp r4, 0x1
	bne _080B3C88
	bl ResetTrainerOpponentIds
	ldr r2, =gUnknown_03006090
	ldrb r0, [r5]
	subs r0, 0x1
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x4
	adds r1, r2
	ldr r1, [r1]
	bl SingleTrainerWantsBattle
	ldr r0, =gUnknown_030060AC
	strb r4, [r0]
	movs r0, 0x1
	b _080B3CF4
	.pool
_080B3C88:
	ldrb r0, [r5]
	cmp r0, 0x2
	bne _080B3CEC
	bl ResetTrainerOpponentIds
	movs r4, 0
	ldrb r5, [r5]
	cmp r4, r5
	bcs _080B3CC6
	ldr r6, =gUnknown_03006090
	adds r7, r6, 0x4
	ldr r5, =gUnknown_02038BFC
_080B3CA0:
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	adds r0, r1, r6
	ldrb r0, [r0]
	adds r1, r7
	ldr r1, [r1]
	bl TwoTrainersWantBattle
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r4, r0
	bcc _080B3CA0
_080B3CC6:
	bl TwoTrainersWantBattleExecuteScript
	ldr r1, =gUnknown_02038BFC
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_030060AC
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	b _080B3CF4
	.pool
_080B3CEC:
	ldr r1, =gUnknown_030060AC
	movs r0, 0
	strb r0, [r1]
	movs r0, 0
_080B3CF4:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckForTrainersWantingBattle

	thumb_func_start CheckIfTrainerWantsBattle
@ u8 CheckIfTrainerWantsBattle(u8 trainerFieldObjectId)
CheckIfTrainerWantsBattle: @ 80B3D00
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x1
	mov r9, r0
	bl InTrainerHill
	cmp r0, 0x1
	bne _080B3D1E
	bl sub_81D62AC
	b _080B3D24
_080B3D1E:
	adds r0, r5, 0
	bl GetFieldObjectScriptPointerByFieldObjectId
_080B3D24:
	adds r7, r0, 0
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _080B3D3E
	adds r0, r5, 0
	bl GetBattlePyramidTrainerFlag
_080B3D36:
	lsls r0, 24
_080B3D38:
	cmp r0, 0
	beq _080B3D56
	b _080B3DE0
_080B3D3E:
	bl InTrainerHill
	cmp r0, 0x1
	bne _080B3D4E
	adds r0, r5, 0
	bl GetTrainerHillTrainerFlag
	b _080B3D36
_080B3D4E:
	adds r0, r7, 0
	bl GetTrainerFlagFromScriptPointer
	b _080B3D38
_080B3D56:
	lsls r4, r5, 3
	adds r0, r4, r5
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl CheckIfTrainerCanApproachPlayer
	lsls r0, 24
	lsrs r6, r0, 24
	mov r8, r4
	cmp r6, 0
	beq _080B3DE0
	ldrb r0, [r7, 0x1]
	cmp r0, 0x4
	beq _080B3D7C
	cmp r0, 0x7
	beq _080B3D7C
	cmp r0, 0x6
	bne _080B3D8A
_080B3D7C:
	bl GetMonsStateToDoubles_2
	lsls r0, 24
	cmp r0, 0
	bne _080B3DE0
	movs r1, 0x2
	mov r9, r1
_080B3D8A:
	ldr r2, =gUnknown_03006090
	ldr r4, =gUnknown_030060A8
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r5, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0x4
	adds r0, r1
	str r7, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r6, [r0, 0x1]
	mov r1, r8
	adds r0, r1, r5
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	subs r1, r6, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl TrainerApproachPlayer
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	mov r0, r9
	b _080B3DE2
	.pool
_080B3DE0:
	movs r0, 0
_080B3DE2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckIfTrainerWantsBattle

	thumb_func_start CheckIfTrainerCanApproachPlayer
@ u8 CheckIfTrainerCanApproachPlayer(struct npc_state *trainerFieldObject)
CheckIfTrainerCanApproachPlayer: @ 80B3DF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	ldrb r0, [r7, 0x7]
	mov r8, r4
	cmp r0, 0x1
	bne _080B3E50
	ldr r1, =gIsTrainerInRange
	ldrb r0, [r7, 0x18]
	lsls r0, 28
	lsrs r0, 26
	subs r0, 0x4
	adds r0, r1
	ldrb r1, [r7, 0x1D]
	mov r2, sp
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r5, 0
	ldrsh r3, [r4, r5]
	ldr r4, [r0]
	adds r0, r7, 0
	bl _call_via_r4
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r2, [r7, 0x18]
	lsls r2, 28
	lsrs r2, 28
	adds r0, r7, 0
	adds r1, r6, 0
	bl CheckPathBetweenTrainerAndPlayer
	lsls r0, 24
	lsrs r0, 24
	b _080B3E90
	.pool
_080B3E4C:
	adds r0, r6, 0
	b _080B3E90
_080B3E50:
	movs r5, 0
_080B3E52:
	ldr r0, =gIsTrainerInRange
	lsls r4, r5, 2
	adds r4, r0
	ldrb r1, [r7, 0x1D]
	mov r0, sp
	movs r6, 0
	ldrsh r2, [r0, r6]
	mov r0, r8
	movs r6, 0
	ldrsh r3, [r0, r6]
	ldr r4, [r4]
	adds r0, r7, 0
	bl _call_via_r4
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl CheckPathBetweenTrainerAndPlayer
	lsls r0, 24
	cmp r0, 0
	bne _080B3E4C
	adds r5, r4, 0
	cmp r5, 0x3
	bls _080B3E52
	movs r0, 0
_080B3E90:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckIfTrainerCanApproachPlayer

	thumb_func_start IsTrainerInRangeSouth
@ u8 IsTrainerInRangeSouth(struct npc_state *trainerFieldObject, u16 sightRange, u16 playerX, u16 playerY)
IsTrainerInRangeSouth: @ 80B3EA0
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r3, 16
	lsrs r5, r3, 16
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsls r2, 16
	asrs r2, 16
	cmp r0, r2
	bne _080B3EDA
	lsls r0, r5, 16
	asrs r2, r0, 16
	ldrh r3, [r4, 0x12]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r2, r0
	ble _080B3EDA
	adds r1, r0, 0
	lsls r0, r6, 16
	asrs r0, 16
	adds r1, r0
	cmp r2, r1
	bgt _080B3EDA
	subs r0, r5, r3
	lsls r0, 24
	lsrs r0, 24
	b _080B3EDC
_080B3EDA:
	movs r0, 0
_080B3EDC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsTrainerInRangeSouth

	thumb_func_start IsTrainerInRangeNorth
@ u8 IsTrainerInRangeNorth(struct npc_state *trainerFieldObject, u16 sightRange, u16 playerX, u16 playerY)
IsTrainerInRangeNorth: @ 80B3EE4
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r3, 16
	lsrs r5, r3, 16
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsls r2, 16
	asrs r2, 16
	cmp r0, r2
	bne _080B3F1E
	lsls r0, r5, 16
	asrs r2, r0, 16
	ldrh r3, [r4, 0x12]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bge _080B3F1E
	adds r1, r0, 0
	lsls r0, r6, 16
	asrs r0, 16
	subs r1, r0
	cmp r2, r1
	blt _080B3F1E
	subs r0, r3, r5
	lsls r0, 24
	lsrs r0, 24
	b _080B3F20
_080B3F1E:
	movs r0, 0
_080B3F20:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsTrainerInRangeNorth

	thumb_func_start IsTrainerInRangeWest
@ u8 IsTrainerInRangeWest(struct npc_state *trainerFieldObject, u16 sightRange, u16 playerX, u16 playerY)
IsTrainerInRangeWest: @ 80B3F28
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r3, 16
	asrs r3, 16
	cmp r0, r3
	bne _080B3F62
	lsls r0, r5, 16
	asrs r3, r0, 16
	ldrh r2, [r4, 0x10]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _080B3F62
	adds r1, r0, 0
	lsls r0, r6, 16
	asrs r0, 16
	subs r1, r0
	cmp r3, r1
	blt _080B3F62
	subs r0, r2, r5
	lsls r0, 24
	lsrs r0, 24
	b _080B3F64
_080B3F62:
	movs r0, 0
_080B3F64:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsTrainerInRangeWest

	thumb_func_start IsTrainerInRangeEast
@ u8 IsTrainerInRangeEast(struct npc_state *trainerFieldObject, u16 sightRange, u16 playerX, u16 playerY)
IsTrainerInRangeEast: @ 80B3F6C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r3, 16
	asrs r3, 16
	cmp r0, r3
	bne _080B3FA6
	lsls r0, r5, 16
	asrs r3, r0, 16
	ldrh r2, [r4, 0x10]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r3, r0
	ble _080B3FA6
	adds r1, r0, 0
	lsls r0, r6, 16
	asrs r0, 16
	adds r1, r0
	cmp r3, r1
	bgt _080B3FA6
	subs r0, r5, r2
	lsls r0, 24
	lsrs r0, 24
	b _080B3FA8
_080B3FA6:
	movs r0, 0
_080B3FA8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsTrainerInRangeEast

	thumb_func_start CheckPathBetweenTrainerAndPlayer
@ u8 CheckPathBetweenTrainerAndPlayer(struct npc_state *fieldObject, u8 a2, u8 direction)
CheckPathBetweenTrainerAndPlayer: @ 80B3FB0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r7, r2, 24
	cmp r1, 0
	beq _080B4056
	ldrh r1, [r6, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r6, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	adds r0, r7, 0
	mov r1, sp
	adds r2, r4, 0
	bl MoveCoords
	movs r5, 0
	mov r8, r4
	mov r4, r9
	subs r4, 0x1
	cmp r5, r4
	bge _080B4028
_080B3FEE:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r3, r8
	movs r0, 0
	ldrsh r2, [r3, r0]
	adds r0, r6, 0
	adds r3, r7, 0
	bl sub_8092C8C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080B4014
	movs r0, 0x2
	negs r0, r0
	ands r1, r0
	cmp r1, 0
	bne _080B4056
_080B4014:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r7, 0
	mov r1, sp
	mov r2, r8
	bl MoveCoords
	cmp r5, r4
	blt _080B3FEE
_080B4028:
	ldrb r4, [r6, 0x19]
	lsls r5, r4, 28
	lsrs r5, 28
	lsrs r4, 4
	movs r0, 0
	strb r0, [r6, 0x19]
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r3, r8
	movs r0, 0
	ldrsh r2, [r3, r0]
	adds r0, r6, 0
	adds r3, r7, 0
	bl npc_block_way
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r4, 4
	orrs r5, r4
	strb r5, [r6, 0x19]
	cmp r1, 0x4
	beq _080B405A
_080B4056:
	movs r0, 0
	b _080B405C
_080B405A:
	mov r0, r9
_080B405C:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckPathBetweenTrainerAndPlayer

	thumb_func_start TrainerApproachPlayer
@ void TrainerApproachPlayer(struct npc_state *trainerFieldObject, u8 distance)
TrainerApproachPlayer: @ 80B406C
	push {r4,r5,lr}
	lsls r5, r1, 24
	lsrs r5, 24
	ldr r0, =c3_8081EDC
	movs r1, 0x50
	bl CreateTask
	ldr r4, =gUnknown_03006090
	ldr r3, =gUnknown_030060A8
	ldrb r2, [r3]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strb r0, [r1, 0x8]
	ldrb r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x8]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	strh r5, [r1, 0xE]
	ldrb r2, [r3]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0]
	strh r0, [r1, 0x16]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TrainerApproachPlayer

	thumb_func_start sub_80B40C8
sub_80B40C8: @ 80B40C8
	push {r4,r5,lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B40E4
	ldr r0, =gUnknown_03006090
	ldrb r5, [r0, 0x8]
	b _080B40E8
	.pool
_080B40E4:
	ldr r0, =gUnknown_03006090
	ldrb r5, [r0, 0x14]
_080B40E8:
	ldr r4, =c3_8081EDC
	adds r0, r5, 0
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	adds r0, r5, 0
	bl _call_via_r4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B40C8

	thumb_func_start c3_8081EDC
c3_8081EDC: @ 80B4118
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r0, [r5]
	lsls r0, 31
	cmp r0, 0
	bne _080B4150
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _080B416C
	.pool
_080B4150:
	ldr r7, =gTrainerSeeFuncList
_080B4152:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r7
	ldr r3, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	lsls r0, 24
	cmp r0, 0
	bne _080B4152
_080B416C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_8081EDC

	thumb_func_start sub_80B4178
sub_80B4178: @ 80B4178
	movs r0, 0
	bx lr
	thumb_func_end sub_80B4178

	thumb_func_start sub_80B417C
sub_80B417C: @ 80B417C
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	ldr r1, =gFieldEffectArguments
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	adds r0, r4, 0
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0
	bl FieldEffectStart
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B417C

	thumb_func_start sub_80B41C0
sub_80B41C0: @ 80B41C0
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	beq _080B41D6
	movs r0, 0
	b _080B41F8
_080B41D6:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldrb r0, [r5, 0x6]
	subs r0, 0x39
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080B41EC
	movs r0, 0x6
	strh r0, [r4, 0x8]
_080B41EC:
	ldrb r0, [r5, 0x6]
	cmp r0, 0x3F
	bne _080B41F6
	movs r0, 0x8
	strh r0, [r4, 0x8]
_080B41F6:
	movs r0, 0x1
_080B41F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B41C0

	thumb_func_start sub_80B4200
sub_80B4200: @ 80B4200
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B421E
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B4252
_080B421E:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080B4244
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetGoSpeed0AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0xE]
	subs r0, 0x1
	strh r0, [r5, 0xE]
	b _080B4252
_080B4244:
	adds r0, r4, 0
	movs r1, 0x3E
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B4252:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4200

	thumb_func_start sub_80B425C
sub_80B425C: @ 80B425C
	push {r4-r6,lr}
	adds r6, r1, 0
	adds r5, r2, 0
	adds r0, r5, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B427A
	adds r0, r5, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B4308
_080B427A:
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl npc_running_behaviour_by_direction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl npc_set_running_behaviour_etc
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl npc_running_behaviour_by_direction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_808F23C
	adds r0, r5, 0
	bl sub_808F208
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B42D2
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B4308
_080B42D2:
	bl sub_808BCE8
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_080B4308:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B425C

	thumb_func_start sub_80B4318
sub_80B4318: @ 80B4318
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B4344
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B434A
_080B4344:
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
_080B434A:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4318

	thumb_func_start sub_80B435C
sub_80B435C: @ 80B435C
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B437A
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B4388
_080B437A:
	adds r0, r4, 0
	movs r1, 0x59
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B4388:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B435C

	thumb_func_start sub_80B4390
sub_80B4390: @ 80B4390
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r2, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B43A4
	movs r0, 0x3
	strh r0, [r4, 0x8]
_080B43A4:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B4390

	thumb_func_start sub_80B43AC
sub_80B43AC: @ 80B43AC
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B43CA
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B43D8
_080B43CA:
	adds r0, r4, 0
	movs r1, 0x3E
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B43D8:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B43AC

	thumb_func_start sub_80B43E0
sub_80B43E0: @ 80B43E0
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	adds r0, r4, 0
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	cmp r0, 0
	beq _080B4426
	ldr r2, =gFieldEffectArguments
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	str r0, [r2]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	str r0, [r2, 0x4]
	ldr r3, =gSprites
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r2, 0x8]
	movs r0, 0x2
	str r0, [r2, 0xC]
	movs r0, 0x31
	bl FieldEffectStart
	strh r0, [r5, 0x10]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B4426:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B43E0

	thumb_func_start sub_80B4438
sub_80B4438: @ 80B4438
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	ldr r2, =gSprites
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x2B
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _080B44A0
	ldrb r1, [r4, 0x3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x3]
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_80934BC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B44A0:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4438

	thumb_func_start sub_80B44AC
sub_80B44AC: @ 80B44AC
	push {r4,lr}
	adds r4, r1, 0
	movs r0, 0x31
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B44C0
	movs r0, 0x3
	strh r0, [r4, 0x8]
_080B44C0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B44AC

	thumb_func_start sub_80B44C8
sub_80B44C8: @ 80B44C8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0xA
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B44FA
	ldr r0, [sp]
	bl FieldObjectClearAnim
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
_080B44FA:
	ldr r1, =gTrainerSeeFuncList2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r2, [sp]
	ldr r3, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl _call_via_r3
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	bne _080B4564
	movs r0, 0x31
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B4564
	ldr r4, [sp]
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl npc_running_behaviour_by_direction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl npc_set_running_behaviour_etc
	ldr r4, [sp]
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl npc_running_behaviour_by_direction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_808F23C
	adds r0, r5, 0
	bl DestroyTask
	b _080B456E
	.pool
_080B4564:
	ldr r2, [sp]
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
_080B456E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B44C8

	thumb_func_start sub_80B4578
sub_80B4578: @ 80B4578
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_80B44C8
	movs r1, 0
	bl CreateTask
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	adds r0, 0x2
	adds r1, r4, 0
	bl StoreWordInTwoHalfwords
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B4578

	thumb_func_start sub_80B45AC
sub_80B45AC: @ 80B45AC
	push {lr}
	ldr r0, =sub_80B45BC
	bl sub_80B40C8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B45AC

	thumb_func_start sub_80B45BC
sub_80B45BC: @ 80B45BC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80B45BC

	thumb_func_start sub_80B45D0
sub_80B45D0: @ 80B45D0
	push {lr}
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B4610
	ldr r1, =gUnknown_02038BFC
	ldrb r0, [r1]
	cmp r0, 0
	bne _080B460C
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	bl UnfreezeMapObjects
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0, 0xC]
	bl sub_80974D0
	b _080B4616
	.pool
_080B460C:
	movs r0, 0
	strb r0, [r1]
_080B4610:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_080B4616:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B45D0

	thumb_func_start oei_exclamation_mark
oei_exclamation_mark: @ 80B4620
	push {lr}
	ldr r0, =gSpriteTemplate_85507B4
	movs r1, 0
	movs r2, 0
	movs r3, 0x53
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080B4648
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_80B46D8
_080B4648:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_exclamation_mark

	thumb_func_start sub_80B4658
sub_80B4658: @ 80B4658
	push {lr}
	ldr r0, =gSpriteTemplate_85507B4
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _080B4680
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x21
	movs r2, 0x1
	bl sub_80B46D8
_080B4680:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4658

	thumb_func_start sub_80B4690
sub_80B4690: @ 80B4690
	push {r4,lr}
	ldr r0, =gSpriteTemplate_85507CC
	movs r1, 0
	movs r2, 0
	movs r3, 0x52
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080B46C6
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2E
	movs r2, 0
	bl sub_80B46D8
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x5]
_080B46C6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B4690

	thumb_func_start sub_80B46D8
@ void sub_80B46D8(struct obj *object, s16 a2, u8 a3)
sub_80B46D8: @ 80B46D8
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	ldrb r4, [r0, 0x5]
	movs r3, 0xD
	negs r3, r3
	ands r3, r4
	movs r4, 0x4
	orrs r3, r4
	strb r3, [r0, 0x5]
	movs r3, 0x3E
	adds r3, r0
	mov r12, r3
	ldrb r3, [r3]
	movs r4, 0x2
	orrs r3, r4
	mov r4, r12
	strb r3, [r4]
	ldr r4, =gFieldEffectArguments
	ldr r3, [r4]
	strh r3, [r0, 0x2E]
	ldr r3, [r4, 0x4]
	strh r3, [r0, 0x30]
	ldr r3, [r4, 0x8]
	strh r3, [r0, 0x32]
	ldr r3, =0x0000fffb
	strh r3, [r0, 0x34]
	strh r1, [r0, 0x3C]
	adds r1, r2, 0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B46D8

	thumb_func_start objc_exclamation_mark_probably
objc_exclamation_mark_probably: @ 80B4724
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x32]
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _080B4756
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080B4764
_080B4756:
	ldrh r1, [r4, 0x3C]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldEffectStop
	b _080B47B2
_080B4764:
	ldr r2, =gMapObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrh r3, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r2, r3, r0
	strh r2, [r4, 0x36]
	ldrh r0, [r1, 0x20]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x22]
	subs r0, 0x10
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x24]
	strh r0, [r4, 0x24]
	ldrh r0, [r1, 0x26]
	adds r0, r2
	strh r0, [r4, 0x26]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _080B47B0
	adds r0, r3, 0x1
	strh r0, [r4, 0x34]
	b _080B47B2
	.pool
_080B47B0:
	strh r2, [r4, 0x34]
_080B47B2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end objc_exclamation_mark_probably

	thumb_func_start sub_80B47BC
sub_80B47BC: @ 80B47BC
	push {lr}
	ldr r0, =gUnknown_02038BFC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B47D4
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0, 0xC]
	b _080B47D8
	.pool
_080B47D4:
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0]
_080B47D8:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B47BC

	thumb_func_start sub_80B47E0
sub_80B47E0: @ 80B47E0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080B47EE
	movs r0, 0
	b _080B4800
_080B47EE:
	cmp r0, 0
	beq _080B47FC
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0, 0xC]
	b _080B4800
	.pool
_080B47FC:
	ldr r0, =gUnknown_03006090
	ldrb r0, [r0]
_080B4800:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B47E0

	thumb_func_start sub_80B4808
sub_80B4808: @ 80B4808
	push {lr}
	ldr r0, =gUnknown_030060AC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080B4870
	ldr r2, =gUnknown_03006090
	ldr r0, =gUnknown_03006080
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	ldr r3, =gUnknown_03006084
	strb r0, [r3]
	movs r0, 0xFE
	strb r0, [r3, 0x1]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0xFF
	bl ScriptMovement_StartObjectMovementScript
	b _080B489E
	.pool
_080B4870:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	ldr r3, =gUnknown_03006084
	strb r0, [r3]
	movs r0, 0xFE
	strb r0, [r3, 0x1]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0xFF
	bl ScriptMovement_StartObjectMovementScript
_080B489E:
	movs r0, 0xFF
	bl sub_809BE48
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B4808

	.align 2, 0 @ Don't pad with nop.
