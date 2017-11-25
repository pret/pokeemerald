	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_809BEDC
sub_809BEDC: @ 809BEDC
	push {r4,r5,lr}
	movs r1, 0x2
	negs r1, r1
	movs r3, 0x3
	negs r3, r3
	movs r4, 0x5
	negs r4, r4
	movs r5, 0x9
	negs r5, r5
	movs r2, 0
	strb r2, [r0]
	ldrb r2, [r0, 0x1]
	ands r1, r2
	ands r1, r3
	ands r1, r4
	ands r1, r5
	strb r1, [r0, 0x1]
	movs r1, 0
	strb r1, [r0, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809BEDC

	thumb_func_start process_overworld_input
@ void process_overworld_input(overworld_input_data *input_data, char buttons_new, char buttons_held)
process_overworld_input: @ 809BF08
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	ldr r0, =gPlayerAvatar
	ldrb r6, [r0, 0x3]
	ldrb r0, [r0, 0x2]
	mov r9, r0
	bl cur_mapdata_block_role_at_player_pos
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsMoveTile
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r6, 0x2
	bne _0809BF3C
	cmp r7, 0
	beq _0809BF40
_0809BF3C:
	cmp r6, 0
	bne _0809BFA2
_0809BF40:
	bl sub_811A138
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0809BF8C
	movs r0, 0x8
	ands r0, r5
	cmp r0, 0
	beq _0809BF5C
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
_0809BF5C:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _0809BF6C
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4]
_0809BF6C:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0809BF7C
	ldrb r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4]
_0809BF7C:
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _0809BF8C
	ldrb r0, [r4]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4]
_0809BF8C:
	movs r0, 0xF0
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0809BFA2
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4]
_0809BFA2:
	cmp r7, 0
	bne _0809BFC8
	cmp r6, 0x2
	bne _0809BFB8
	mov r0, r9
	cmp r0, 0x2
	bne _0809BFB8
	ldrb r0, [r4]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4]
_0809BFB8:
	cmp r7, 0
	bne _0809BFC8
	cmp r6, 0x2
	bne _0809BFC8
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
_0809BFC8:
	movs r0, 0x40
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0809BFDC
	movs r0, 0x2
	b _0809C004
	.pool
_0809BFDC:
	movs r0, 0x80
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0809BFEA
	movs r0, 0x1
	b _0809C004
_0809BFEA:
	movs r0, 0x20
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0809BFF8
	movs r0, 0x3
	b _0809C004
_0809BFF8:
	movs r0, 0x10
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0809C006
	movs r0, 0x4
_0809C004:
	strb r0, [r4, 0x2]
_0809C006:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end process_overworld_input

	thumb_func_start sub_809C014
@ int sub_809C014(overworld_input_data *input_data)
sub_809C014: @ 809C014
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, =gSpecialVar_LastTalked
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gSelectedMapObject
	strb r1, [r0]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r6, r0, 24
	mov r4, sp
	mov r0, sp
	bl player_get_pos_to_and_height
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r4, r0, 16
	bl CheckForTrainersWantingBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
	bl mapheader_run_first_tag2_script_list_match
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
	ldrb r1, [r5]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809C070
	bl sub_809C89C
	cmp r0, 0x1
	beq _0809C14E
_0809C070:
	ldrb r1, [r5]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0809C096
	movs r0, 0x5
	bl IncrementGameStat
	bl increment_var_x4026_on_birth_island_modulo_100
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_809C8DC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C096:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809C0AE
	adds r0, r4, 0
	bl is_it_battle_time_3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C0AE:
	ldrb r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809C0D0
	ldrb r0, [r5, 0x2]
	cmp r0, r6
	bne _0809C0D0
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl mapheader_run_first_tag2_script_list_match_conditionally
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C0D0:
	mov r4, sp
	mov r0, sp
	bl player_get_next_pos_and_height
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809C106
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_809C1FC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C106:
	ldrb r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809C128
	ldrb r0, [r5, 0x2]
	cmp r0, r6
	bne _0809C128
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl map_warp_consider_2_to_inside
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C128:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809C13A
	bl sub_809C868
	cmp r0, 0x1
	beq _0809C14E
_0809C13A:
	ldrb r1, [r5]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0809C15C
	movs r0, 0x6
	bl PlaySE
	bl sub_809FA9C
_0809C14E:
	movs r0, 0x1
	b _0809C172
	.pool
_0809C15C:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0809C170
	bl UseRegisteredKeyItemOnField
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C14E
_0809C170:
	movs r0, 0
_0809C172:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809C014

	thumb_func_start player_get_pos_to_and_height
player_get_pos_to_and_height: @ 809C17C
	push {r4,lr}
	adds r4, r0, 0
	adds r1, r4, 0x2
	bl PlayerGetDestCoords
	bl PlayerGetZCoord
	strb r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end player_get_pos_to_and_height

	thumb_func_start player_get_next_pos_and_height
player_get_next_pos_and_height: @ 809C194
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r1, r5, 0x2
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0809C1C6
	bl PlayerGetZCoord
_0809C1C6:
	strb r0, [r5, 0x4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end player_get_next_pos_and_height

	thumb_func_start cur_mapdata_block_role_at_player_pos
cur_mapdata_block_role_at_player_pos: @ 809C1D0
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end cur_mapdata_block_role_at_player_pos

	thumb_func_start sub_809C1FC
sub_809C1FC: @ 809C1FC
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	lsls r1, 24
	lsrs r1, 24
	bl TryGetScriptOnPressingA
	adds r4, r0, 0
	cmp r4, 0
	bne _0809C214
	movs r0, 0
	b _0809C24C
_0809C214:
	ldr r0, =gUnknown_081F860D
	cmp r4, r0
	beq _0809C244
	ldr r0, =gUnknown_081F9553
	cmp r4, r0
	beq _0809C244
	ldr r0, =gUnknown_0823B4BB
	cmp r4, r0
	beq _0809C244
	ldr r0, =gUnknown_0823B589
	cmp r4, r0
	beq _0809C244
	ldr r0, =EventScript_2766A2
	cmp r4, r0
	beq _0809C244
	ldr r0, =EventScript_2766A6
	cmp r4, r0
	beq _0809C244
	ldr r0, =EventScript_271D92
	cmp r4, r0
	beq _0809C244
	movs r0, 0x5
	bl PlaySE
_0809C244:
	adds r0, r4, 0
	bl ScriptContext1_SetupScript
	movs r0, 0x1
_0809C24C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809C1FC

	thumb_func_start TryGetScriptOnPressingA
TryGetScriptOnPressingA: @ 809C270
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	mov r8, r5
	lsls r2, 24
	lsrs r4, r2, 24
	adds r7, r4, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl TryGetMapObjectScript
	cmp r0, 0
	bne _0809C2BC
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl TryGetInvisibleMapObjectScript
	cmp r0, 0
	bne _0809C2BC
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl TryGetMetatileBehaviorScript
	cmp r0, 0
	bne _0809C2BC
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl TryGetFieldMoveScript
	cmp r0, 0
	bne _0809C2BC
	movs r0, 0
_0809C2BC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end TryGetScriptOnPressingA

	thumb_func_start sub_809C2C8
sub_809C2C8: @ 809C2C8
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r2, 24
	lsrs r6, r2, 24
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsCounter
	lsls r0, 24
	cmp r0, 0
	bne _0809C2F0
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	b _0809C30E
_0809C2F0:
	ldr r1, =gUnknown_08339D64
	lsls r2, r6, 3
	adds r0, r2, r1
	ldr r3, [r0]
	ldrh r0, [r4]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	adds r1, 0x4
	adds r2, r1
	ldr r2, [r2]
	ldrh r1, [r4, 0x2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
_0809C30E:
	ldrb r2, [r4, 0x4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x10
	beq _0809C32E
	ldr r1, =gMapObjects
	lsls r2, r3, 3
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0xFF
	bne _0809C33C
_0809C32E:
	movs r0, 0
	b _0809C36E
	.pool
_0809C33C:
	movs r4, 0
	ldr r1, =gLinkPlayerMapObjects
_0809C340:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _0809C34C
	ldrb r0, [r1, 0x2]
	cmp r0, r3
	beq _0809C32E
_0809C34C:
	adds r1, 0x4
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809C340
	ldr r0, =gSelectedMapObject
	strb r3, [r0]
	ldr r1, =gSpecialVar_LastTalked
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x8]
	strh r0, [r1]
	ldr r0, =gSpecialVar_Facing
	strh r6, [r0]
	adds r0, r3, 0
	bl GetFieldObjectScriptPointerByFieldObjectId
_0809C36E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809C2C8

	thumb_func_start TryGetMapObjectScript
TryGetMapObjectScript: @ 809C384
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldrh r0, [r5]
	ldrh r1, [r5, 0x2]
	ldrb r2, [r5, 0x4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x10
	beq _0809C3B4
	ldr r1, =gMapObjects
	lsls r2, r4, 3
	adds r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
	adds r3, r1, 0
	cmp r0, 0xFF
	bne _0809C40C
_0809C3B4:
	adds r0, r6, 0
	bl MetatileBehavior_IsCounter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C400
	ldr r1, =gUnknown_08339D64
	lsls r2, r7, 3
	adds r0, r2, r1
	ldr r3, [r0]
	ldrh r0, [r5]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	adds r1, 0x4
	adds r2, r1
	ldr r2, [r2]
	ldrh r1, [r5, 0x2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	ldrb r2, [r5, 0x4]
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x10
	beq _0809C400
	ldr r1, =gMapObjects
	lsls r2, r4, 3
	adds r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
	adds r3, r1, 0
	cmp r0, 0xFF
	bne _0809C40C
_0809C400:
	movs r0, 0
	b _0809C44E
	.pool
_0809C40C:
	ldr r0, =gSelectedMapObject
	strb r4, [r0]
	ldr r1, =gSpecialVar_LastTalked
	adds r0, r2, r4
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x8]
	strh r0, [r1]
	ldr r0, =gSpecialVar_Facing
	strh r7, [r0]
	bl InTrainerHill
	cmp r0, 0x1
	bne _0809C43C
	bl sub_81D62AC
	b _0809C442
	.pool
_0809C43C:
	adds r0, r4, 0
	bl GetFieldObjectScriptPointerByFieldObjectId
_0809C442:
	adds r1, r0, 0
	ldr r0, =gSpecialVar_LastTalked
	ldrb r0, [r0]
	bl GetRamScript
	adds r1, r0, 0
_0809C44E:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end TryGetMapObjectScript

	thumb_func_start TryGetInvisibleMapObjectScript
@ signed int TryGetInvisibleMapObjectScript(int a1, int a2, u8 playerFacingDirection)
TryGetInvisibleMapObjectScript: @ 809C458
	push {r4,r5,lr}
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r4, =gMapHeader
	ldrh r1, [r0]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r0, 0x2]
	subs r2, 0x7
	lsls r2, 16
	lsrs r2, 16
	ldrb r3, [r0, 0x4]
	adds r0, r4, 0
	bl FindInvisibleMapObjectByPosition
	cmp r0, 0
	beq _0809C4CC
	ldr r2, [r0, 0x8]
	cmp r2, 0
	bne _0809C490
	ldr r0, =EventScript_2C8436
	b _0809C532
	.pool
_0809C490:
	ldrb r0, [r0, 0x5]
	cmp r0, 0x8
	bhi _0809C530
	lsls r0, 2
	ldr r1, =_0809C4A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809C4A4:
	.4byte _0809C530
	.4byte _0809C4C8
	.4byte _0809C4D0
	.4byte _0809C4D6
	.4byte _0809C4DC
	.4byte _0809C4E2
	.4byte _0809C4E2
	.4byte _0809C4E2
	.4byte _0809C510
_0809C4C8:
	cmp r5, 0x2
	beq _0809C530
_0809C4CC:
	movs r0, 0
	b _0809C532
_0809C4D0:
	cmp r5, 0x1
	beq _0809C530
	b _0809C4CC
_0809C4D6:
	cmp r5, 0x4
	beq _0809C530
	b _0809C4CC
_0809C4DC:
	cmp r5, 0x3
	beq _0809C530
	b _0809C4CC
_0809C4E2:
	ldr r1, =gSpecialVar_0x8004
	lsrs r0, r2, 16
	movs r3, 0xFA
	lsls r3, 1
	adds r0, r3
	strh r0, [r1]
	ldr r0, =gSpecialVar_0x8005
	strh r2, [r0]
	ldrh r0, [r1]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C4CC
	ldr r0, =EventScript_271CB7
	b _0809C532
	.pool
_0809C510:
	cmp r5, 0x2
	bne _0809C4CC
	ldr r0, =gSpecialVar_0x8004
	strh r2, [r0]
	bl sub_80E9680
	lsls r0, 24
	cmp r0, 0
	beq _0809C4CC
	ldr r0, =EventScript_2759F1
	b _0809C532
	.pool
_0809C530:
	adds r0, r2, 0
_0809C532:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end TryGetInvisibleMapObjectScript

	thumb_func_start TryGetMetatileBehaviorScript
TryGetMetatileBehaviorScript: @ 809C538
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl MetatileBehavior_IsPlayerFacingTVScreen
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C55C
	ldr r0, =EventScript_27EE0B
	b _0809C7E4
	.pool
_0809C55C:
	adds r0, r5, 0
	bl MetatileBehavior_IsPC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C574
	ldr r0, =EventScript_271D92
	b _0809C7E4
	.pool
_0809C574:
	adds r0, r5, 0
	bl MetatileBehavior_IsClosedSootopolisGymDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C58C
	ldr r0, =SootopolisCity_EventScript_1E615D
	b _0809C7E4
	.pool
_0809C58C:
	adds r0, r5, 0
	bl MetatileBehavior_IsUnknownClosedDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C5A4
	ldr r0, =SkyPillar_Outside_EventScript_2393F9
	b _0809C7E4
	.pool
_0809C5A4:
	adds r0, r5, 0
	bl MetatileBehavior_IsCableBoxResults1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C5B4
	b _0809C6E4
_0809C5B4:
	adds r0, r5, 0
	bl MetatileBehavior_IsPokeblockFeeder
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C5CC
	ldr r0, =EventScript_2A4BAC
	b _0809C7E4
	.pool
_0809C5CC:
	adds r0, r5, 0
	bl MetatileBehavior_IsTrickHousePuzzleDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C5E4
	ldr r0, =Route110_TrickHouseEntrance_EventScript_26A22A
	b _0809C7E4
	.pool
_0809C5E4:
	adds r0, r5, 0
	bl MetatileBehavior_IsRegionMap
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C5FC
	ldr r0, =EventScript_27208F
	b _0809C7E4
	.pool
_0809C5FC:
	adds r0, r5, 0
	bl MetatileBehavior_IsRunningShoesInstruction
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C614
	ldr r0, =EventScript_292DE5
	b _0809C7E4
	.pool
_0809C614:
	adds r0, r5, 0
	bl MetatileBehavior_IsPictureBookShelf
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C62C
	ldr r0, =EventScript_2725CE
	b _0809C7E4
	.pool
_0809C62C:
	adds r0, r5, 0
	bl MetatileBehavior_IsBookShelf
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C644
	ldr r0, =EventScript_2725D7
	b _0809C7E4
	.pool
_0809C644:
	adds r0, r5, 0
	bl MetatileBehavior_IsPokeCenterBookShelf
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C65C
	ldr r0, =EventScript_2725E0
	b _0809C7E4
	.pool
_0809C65C:
	adds r0, r5, 0
	bl MetatileBehavior_IsVase
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C674
	ldr r0, =EventScript_2725E9
	b _0809C7E4
	.pool
_0809C674:
	adds r0, r5, 0
	bl MetatileBehavior_IsTrashCan
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C68C
	ldr r0, =EventScript_2725F2
	b _0809C7E4
	.pool
_0809C68C:
	adds r0, r5, 0
	bl MetatileBehavior_IsShopShelf
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C6A4
	ldr r0, =EventScript_2725FB
	b _0809C7E4
	.pool
_0809C6A4:
	adds r0, r5, 0
	bl MetatileBehavior_IsBlueprint
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C6BC
	ldr r0, =EventScript_272604
	b _0809C7E4
	.pool
_0809C6BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MetatileBehavior_IsPlayerFacingWirelessBoxResults
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C6D4
	ldr r0, =OldaleTown_PokemonCenter_2F_EventScript_277B8A
	b _0809C7E4
	.pool
_0809C6D4:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MetatileBehavior_IsCableBoxResults2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C6EC
_0809C6E4:
	ldr r0, =gUnknown_08277365
	b _0809C7E4
	.pool
_0809C6EC:
	adds r0, r5, 0
	bl MetatileBehavior_IsQuestionnaire
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C704
	ldr r0, =EventScript_27381B
	b _0809C7E4
	.pool
_0809C704:
	adds r0, r5, 0
	bl MetatileBehavior_IsTrainerHillTimer
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C71C
	ldr r0, =TrainerHill_1F_EventScript_2C8393
	b _0809C7E4
	.pool
_0809C71C:
	movs r4, 0x4
	ldrsb r4, [r6, r4]
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0809C7D0
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBasePC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C74C
	ldr r0, =gUnknown_0823B4BB
	b _0809C7E4
	.pool
_0809C74C:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseRegisterPC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C764
	ldr r0, =gUnknown_0823B589
	b _0809C7E4
	.pool
_0809C764:
	adds r0, r5, 0
	bl MetatileBehavior_IsMB_BF
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C77C
	ldr r0, =gUnknown_0823B684
	b _0809C7E4
	.pool
_0809C77C:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseTvOrShield
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C794
	ldr r0, =gUnknown_0823B68C
	b _0809C7E4
	.pool
_0809C794:
	adds r0, r5, 0
	bl MetatileBehavior_IsMB_C6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C7A8
	bl sub_80EB56C
	b _0809C7E2
_0809C7A8:
	adds r0, r5, 0
	bl MetatileBehavior_IsMB_C3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C7BC
	bl sub_80EB9E0
	b _0809C7E2
_0809C7BC:
	adds r0, r5, 0
	bl MetatileBehavior_IsMB_B5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C7E2
	bl sub_80EBB28
	b _0809C7E2
_0809C7D0:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBasePoster
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C7E2
	bl sub_80EB498
_0809C7E2:
	movs r0, 0
_0809C7E4:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end TryGetMetatileBehaviorScript

	thumb_func_start TryGetFieldMoveScript
TryGetFieldMoveScript: @ 809C7EC
	push {r4,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =0x0000086b
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C824
	bl PartyHasMonWithSurf
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C824
	bl IsPlayerFacingSurfableFishableWater
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C824
	ldr r0, =EventScript_271EA0
	b _0809C862
	.pool
_0809C824:
	adds r0, r4, 0
	bl MetatileBehavior_IsWaterfall
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C860
	ldr r0, =0x0000086e
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C858
	bl IsPlayerSurfingNorth
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C858
	ldr r0, =EventScript_290A49
	b _0809C862
	.pool
_0809C858:
	ldr r0, =EventScript_290A83
	b _0809C862
	.pool
_0809C860:
	movs r0, 0
_0809C862:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end TryGetFieldMoveScript

	thumb_func_start sub_809C868
sub_809C868: @ 809C868
	push {lr}
	ldr r0, =0x0000086d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809C894
	bl sub_809D1E8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0809C894
	ldr r0, =EventScript_290B0F
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809C896
	.pool
_0809C894:
	movs r0, 0
_0809C896:
	pop {r1}
	bx r1
	thumb_func_end sub_809C868

	thumb_func_start sub_809C89C
sub_809C89C: @ 809C89C
	push {lr}
	ldr r0, =0x0000086d
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809C8D4
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x5
	bne _0809C8D4
	bl sub_809D1E8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C8D4
	ldr r0, =EventScript_290B5A
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809C8D6
	.pool
_0809C8D4:
	movs r0, 0
_0809C8D6:
	pop {r1}
	bx r1
	thumb_func_end sub_809C89C

	thumb_func_start sub_809C8DC
sub_809C8DC: @ 809C8DC
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r6, r4, 0
	bl mapheader_trigger_activate_at__run_now
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C92E
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809CC9C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C92E
	adds r0, r4, 0
	bl sub_809C96C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C92E
	adds r0, r6, 0
	bl per_step_scripts
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C92E
	bl UpdateRepelCounter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809C92E
	movs r0, 0
	b _0809C930
_0809C92E:
	movs r0, 0x1
_0809C930:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809C8DC

	thumb_func_start mapheader_trigger_activate_at__run_now
mapheader_trigger_activate_at__run_now: @ 809C938
	push {r4,lr}
	ldr r4, =gMapHeader
	ldrh r1, [r0]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r0, 0x2]
	subs r2, 0x7
	lsls r2, 16
	lsrs r2, 16
	ldrb r3, [r0, 0x4]
	adds r0, r4, 0
	bl mapheader_trigger_activate_at
	cmp r0, 0
	beq _0809C964
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809C966
	.pool
_0809C964:
	movs r0, 0
_0809C966:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end mapheader_trigger_activate_at__run_now

	thumb_func_start sub_809C96C
sub_809C96C: @ 809C96C
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsCrackedFloorHole
	lsls r0, 24
	cmp r0, 0
	beq _0809C988
	ldr r0, =gUnknown_082A8337
	b _0809C996
	.pool
_0809C988:
	adds r0, r4, 0
	bl MetatileBehavior_IsBattlePyramidWarp
	lsls r0, 24
	cmp r0, 0
	beq _0809C9A4
	ldr r0, =BattleFrontier_BattlePyramidEmptySquare_EventScript_252BE8
_0809C996:
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809C9EA
	.pool
_0809C9A4:
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseGlitterMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C9B8
	bl sub_80FA9D0
	b _0809C9E8
_0809C9B8:
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseSoundMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809C9E8
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	asrs r0, 16
	bl sub_80FA970
_0809C9E8:
	movs r0, 0
_0809C9EA:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809C96C

	thumb_func_start per_step_scripts
per_step_scripts: @ 809C9F4
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl InUnionRoom
	cmp r0, 0x1
	bne _0809CA04
	b _0809CB24
_0809CA04:
	bl sub_80B215C
	bl AdjustFriendship_step
	bl sub_81D4998
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0809CAF8
	lsls r0, r4, 24
	lsrs r0, 24
	bl MetatileBehavior_IsMoveTile
	lsls r0, 24
	cmp r0, 0
	bne _0809CAF8
	bl overworld_poison_step
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CA48
	ldr r0, =EventScript_2736BC
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CA48:
	bl DoEggActions_CheckHatch
	lsls r0, 24
	cmp r0, 0
	beq _0809CA64
	movs r0, 0xD
	bl IncrementGameStat
	ldr r0, =Route117_PokemonDayCare_EventScript_291FC0
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CA64:
	bl sub_813B3B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CA7C
	ldr r0, =gUnknown_08273D1F
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CA7C:
	bl ShouldDoBrailleRegicePuzzle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CA94
	ldr r0, =IslandCave_EventScript_238EAF
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CA94:
	bl is_tile_that_overrides_player_control
	cmp r0, 0x1
	bne _0809CAA8
	ldr r0, =MauvilleCity_EventScript_1DF7BA
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CAA8:
	bl sub_8138120
	cmp r0, 0x1
	bne _0809CABC
	ldr r0, =Route119_EventScript_1F49EC
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CABC:
	bl sub_8138168
	cmp r0, 0x1
	bne _0809CAD0
	ldr r0, =LittlerootTown_ProfessorBirchsLab_EventScript_1FA4D6
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CAD0:
	bl sub_81381B0
	cmp r0, 0x1
	bne _0809CAE4
	ldr r0, =RustboroCity_Gym_EventScript_21307B
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CAE4:
	bl sub_81381F8
	cmp r0, 0x1
	bne _0809CAF8
	ldr r0, =MossdeepCity_SpaceCenter_2F_EventScript_224175
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CAF8:
	bl SafariZoneTakeStep
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CB28
	movs r0, 0x1
	bl CountSSTidalStep
	cmp r0, 0x1
	bne _0809CB1C
	ldr r0, =SSTidalCorridor_EventScript_23C050
	bl ScriptContext1_SetupScript
	b _0809CB28
	.pool
_0809CB1C:
	bl sub_8196034
	cmp r0, 0
	bne _0809CB28
_0809CB24:
	movs r0, 0
	b _0809CB2A
_0809CB28:
	movs r0, 0x1
_0809CB2A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end per_step_scripts

	thumb_func_start sub_809CB30
sub_809CB30: @ 809CB30
	push {lr}
	ldr r0, =0x0000402a
	movs r1, 0
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809CB30

	thumb_func_start AdjustFriendship_step
AdjustFriendship_step: @ 809CB44
	push {r4,r5,lr}
	ldr r0, =0x0000402a
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	ldrh r1, [r0]
	movs r2, 0x7F
	ands r1, r2
	strh r1, [r0]
	cmp r1, 0
	bne _0809CB72
	ldr r5, =gPlayerParty
	movs r4, 0x5
_0809CB62:
	adds r0, r5, 0
	movs r1, 0x5
	bl AdjustFriendship
	adds r5, 0x64
	subs r4, 0x1
	cmp r4, 0
	bge _0809CB62
_0809CB72:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AdjustFriendship_step

	thumb_func_start overworld_poison_timer_set
overworld_poison_timer_set: @ 809CB80
	push {lr}
	ldr r0, =0x0000402b
	movs r1, 0
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_poison_timer_set

	thumb_func_start overworld_poison_step
overworld_poison_step: @ 809CB94
	push {lr}
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x9
	beq _0809CBD4
	ldr r0, =0x0000402b
	bl GetVarPointer
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	ldrh r1, [r0]
	movs r2, 0x3
	ands r1, r2
	strh r1, [r0]
	cmp r1, 0
	bne _0809CBD4
	bl overworld_poison
	cmp r0, 0x1
	beq _0809CBD4
	cmp r0, 0x1
	ble _0809CBD4
	cmp r0, 0x2
	bne _0809CBD4
	movs r0, 0x1
	b _0809CBD6
	.pool
_0809CBD4:
	movs r0, 0
_0809CBD6:
	pop {r1}
	bx r1
	thumb_func_end overworld_poison_step

	thumb_func_start prev_quest_postbuffer_cursor_backup_reset
prev_quest_postbuffer_cursor_backup_reset: @ 809CBDC
	ldr r1, =gUnknown_020375D4
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end prev_quest_postbuffer_cursor_backup_reset

	thumb_func_start is_it_battle_time_3
is_it_battle_time_3: @ 809CBE8
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r7, r4, 0
	ldr r6, =gUnknown_020375D4
	ldrb r0, [r6]
	cmp r0, 0x3
	bhi _0809CC0C
	adds r0, 0x1
	strb r0, [r6]
	ldr r0, =gUnknown_020375D6
	strh r4, [r0]
	movs r0, 0
	b _0809CC30
	.pool
_0809CC0C:
	ldr r5, =gUnknown_020375D6
	ldrh r1, [r5]
	adds r0, r4, 0
	bl StandardWildEncounter
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CC28
	strh r4, [r5]
	movs r0, 0
	b _0809CC30
	.pool
_0809CC28:
	movs r0, 0
	strb r0, [r6]
	strh r7, [r5]
	movs r0, 0x1
_0809CC30:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end is_it_battle_time_3

	thumb_func_start mapheader_run_first_tag2_script_list_match_conditionally
mapheader_run_first_tag2_script_list_match_conditionally: @ 809CC38
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gMapHeader
	mov r8, r0
	adds r1, r7, 0
	bl map_warp_check_packed
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl is_non_stair_warp_tile
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CC90
	lsls r0, r6, 24
	asrs r4, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809CC90
	bl walkrun_find_lowest_active_bit_in_bitfield
	mov r0, r8
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_809CEB0
	bl sub_80AF734
	movs r0, 0x1
	b _0809CC92
	.pool
_0809CC90:
	movs r0, 0
_0809CC92:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end mapheader_run_first_tag2_script_list_match_conditionally

	thumb_func_start sub_809CC9C
sub_809CC9C: @ 809CC9C
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r7, =gMapHeader
	adds r0, r7, 0
	adds r1, r6, 0
	bl map_warp_check_packed
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809CD8A
	adds r0, r5, 0
	bl is_warp_tile
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD8A
	bl walkrun_find_lowest_active_bit_in_bitfield
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_809CEB0
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsEscalator
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CCF8
	adds r0, r4, 0
	bl sub_80AF80C
	movs r0, 0x1
	b _0809CD8C
	.pool
_0809CCF8:
	adds r0, r4, 0
	bl MetatileBehavior_IsLavaridgeB1FWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD0E
	bl sub_80AF828
	movs r0, 0x1
	b _0809CD8C
_0809CD0E:
	adds r0, r4, 0
	bl MetatileBehavior_IsLavaridge1FWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD24
	bl sub_80AF838
	movs r0, 0x1
	b _0809CD8C
_0809CD24:
	adds r0, r4, 0
	bl MetatileBehavior_IsAquaHideoutWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD3A
	bl sub_80AF848
	movs r0, 0x1
	b _0809CD8C
_0809CD3A:
	adds r0, r4, 0
	bl MetatileBehavior_IsWarpOrBridge
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD50
	bl sub_80B0268
	movs r0, 0x1
	b _0809CD8C
_0809CD50:
	adds r0, r4, 0
	bl MetatileBehavior_IsMtPyreHole
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD6C
	ldr r0, =gUnknown_082A8350
	bl ScriptContext1_SetupScript
	movs r0, 0x1
	b _0809CD8C
	.pool
_0809CD6C:
	adds r0, r4, 0
	bl MetatileBehavior_IsMossdeepGymWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CD82
	bl sub_80AF87C
	movs r0, 0x1
	b _0809CD8C
_0809CD82:
	bl sub_80AF734
	movs r0, 0x1
	b _0809CD8C
_0809CD8A:
	movs r0, 0
_0809CD8C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809CC9C

	thumb_func_start is_warp_tile
is_warp_tile: @ 809CD94
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsWarpDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsLadder
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsEscalator
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsNonAnimDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsLavaridgeB1FWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsLavaridge1FWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsAquaHideoutWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsMtPyreHole
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsMossdeepGymWarp
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	adds r0, r4, 0
	bl MetatileBehavior_IsWarpOrBridge
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809CE2A
	movs r0, 0
	b _0809CE2C
_0809CE2A:
	movs r0, 0x1
_0809CE2C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end is_warp_tile

	thumb_func_start is_non_stair_warp_tile
is_non_stair_warp_tile: @ 809CE34
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x2
	beq _0809CE58
	cmp r1, 0x2
	bgt _0809CE4E
	cmp r1, 0x1
	beq _0809CE62
	b _0809CE84
_0809CE4E:
	cmp r2, 0x3
	beq _0809CE6C
	cmp r2, 0x4
	beq _0809CE76
	b _0809CE84
_0809CE58:
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsNorthArrowWarp
	b _0809CE7E
_0809CE62:
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSouthArrowWarp
	b _0809CE7E
_0809CE6C:
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsWestArrowWarp
	b _0809CE7E
_0809CE76:
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsEastArrowWarp
_0809CE7E:
	lsls r0, 24
	lsrs r0, 24
	b _0809CE86
_0809CE84:
	movs r0, 0
_0809CE86:
	pop {r1}
	bx r1
	thumb_func_end is_non_stair_warp_tile

	thumb_func_start map_warp_check_packed
map_warp_check_packed: @ 809CE8C
	push {lr}
	adds r3, r1, 0
	ldrh r1, [r3]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r3, 0x2]
	subs r2, 0x7
	lsls r2, 16
	lsrs r2, 16
	ldrb r3, [r3, 0x4]
	bl map_warp_check
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end map_warp_check_packed

	thumb_func_start sub_809CEB0
sub_809CEB0: @ 809CEB0
	push {r4-r7,lr}
	adds r7, r2, 0
	lsls r1, 24
	lsrs r4, r1, 24
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	cmp r5, 0
	beq _0809CF00
	bl sub_81D6490
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _0809CEF0
	lsls r0, r4, 24
	adds r4, r0, 0
	cmp r4, 0
	bne _0809CEE8
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldr r5, [r0, 0x8]
	b _0809CF0E
	.pool
_0809CEE8:
	bl sub_81D6120
	adds r5, r0, 0
	b _0809CF0E
_0809CEF0:
	cmp r6, 0x5
	bne _0809CF00
	lsls r4, 24
	lsrs r0, r4, 24
	bl sub_81D6134
	adds r5, r0, 0
	b _0809CF0E
_0809CF00:
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	lsls r2, r4, 24
	asrs r1, r2, 21
	ldr r0, [r0, 0x8]
	adds r5, r0, r1
	adds r4, r2, 0
_0809CF0E:
	ldrb r0, [r5, 0x6]
	cmp r0, 0x7F
	bne _0809CF20
	ldrb r0, [r5, 0x5]
	bl copy_saved_warp2_bank_and_enter_x_to_warp1
	b _0809CF6E
	.pool
_0809CF20:
	movs r0, 0x7
	ldrsb r0, [r5, r0]
	movs r1, 0x6
	ldrsb r1, [r5, r1]
	movs r2, 0x5
	ldrsb r2, [r5, r2]
	bl warp1_set_2
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	bl sub_8084D5C
	ldrb r0, [r5, 0x7]
	ldrb r1, [r5, 0x6]
	bl get_mapheader_by_bank_and_number
	ldr r1, [r0, 0x4]
	ldrb r0, [r5, 0x5]
	ldr r1, [r1, 0x8]
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x6]
	cmp r0, 0x7F
	bne _0809CF6E
	asrs r3, r4, 24
	lsls r0, r3, 3
	adds r0, r1
	ldrb r0, [r0, 0x5]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	ldrb r2, [r2, 0x5]
	lsls r2, 24
	asrs r2, 24
	bl saved_warp2_set
_0809CF6E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809CEB0

	thumb_func_start map_warp_consider_2_to_inside
map_warp_consider_2_to_inside: @ 809CF78
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r0, r1, 16
	adds r7, r0, 0
	lsls r2, 24
	lsrs r2, 24
	cmp r2, 0x2
	bne _0809CFFC
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBaseOpen
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CFB0
	ldr r0, =gMapHeader
	ldr r1, [r0, 0x4]
	adds r0, r5, 0
	bl sub_80E9668
	movs r0, 0x1
	b _0809CFFE
	.pool
_0809CFB0:
	adds r0, r4, 0
	bl MetatileBehavior_IsWarpDoor
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CFFC
	ldr r6, =gMapHeader
	adds r0, r6, 0
	adds r1, r5, 0
	bl map_warp_check_packed
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809CFFC
	adds r0, r7, 0
	bl is_warp_tile
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809CFFC
	bl walkrun_find_lowest_active_bit_in_bitfield
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_809CEB0
	bl sub_80AF7D0
	movs r0, 0x1
	b _0809CFFE
	.pool
_0809CFFC:
	movs r0, 0
_0809CFFE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end map_warp_consider_2_to_inside

	thumb_func_start map_warp_check
map_warp_check: @ 809D004
	push {r4-r6,lr}
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	lsls r3, 24
	lsrs r4, r3, 24
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0x8]
	ldrb r3, [r0, 0x1]
	movs r2, 0
	cmp r2, r3
	bge _0809D042
_0809D01E:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0809D03A
	ldrh r0, [r1, 0x2]
	cmp r0, r5
	bne _0809D03A
	ldrb r0, [r1, 0x4]
	cmp r0, r4
	beq _0809D034
	cmp r0, 0
	bne _0809D03A
_0809D034:
	lsls r0, r2, 24
	asrs r0, 24
	b _0809D046
_0809D03A:
	adds r2, 0x1
	adds r1, 0x8
	cmp r2, r3
	blt _0809D01E
_0809D042:
	movs r0, 0x1
	negs r0, r0
_0809D046:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end map_warp_check

	thumb_func_start trigger_activate
trigger_activate: @ 809D04C
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809D082
	ldr r1, [r4, 0xC]
	cmp r1, 0
	bne _0809D062
	ldrb r0, [r4, 0x6]
	bl trigger_activate_weather
	b _0809D082
_0809D062:
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	beq _0809D07C
	ldrh r0, [r4, 0x6]
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r4, 0x8]
	cmp r0, r1
	bne _0809D082
	ldr r0, [r4, 0xC]
	b _0809D084
_0809D07C:
	adds r0, r1, 0
	bl ScriptContext2_RunNewScript
_0809D082:
	movs r0, 0
_0809D084:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end trigger_activate

	thumb_func_start mapheader_trigger_activate_at
mapheader_trigger_activate_at: @ 809D08C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	ldr r0, [r0, 0x4]
	ldr r1, [r0, 0xC]
	ldrb r7, [r0, 0x2]
	movs r6, 0
	cmp r6, r7
	bge _0809D0E2
	adds r5, r1, 0
	adds r4, r5, 0
_0809D0B8:
	ldrh r0, [r4]
	cmp r0, r10
	bne _0809D0D8
	ldrh r0, [r4, 0x2]
	cmp r0, r9
	bne _0809D0D8
	ldrb r0, [r4, 0x4]
	cmp r0, r8
	beq _0809D0CE
	cmp r0, 0
	bne _0809D0D8
_0809D0CE:
	adds r0, r5, 0
	bl trigger_activate
	cmp r0, 0
	bne _0809D0E4
_0809D0D8:
	adds r4, 0x10
	adds r5, 0x10
	adds r6, 0x1
	cmp r6, r7
	blt _0809D0B8
_0809D0E2:
	movs r0, 0
_0809D0E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end mapheader_trigger_activate_at

	thumb_func_start sub_809D0F4
sub_809D0F4: @ 809D0F4
	push {r4,lr}
	ldr r4, =gMapHeader
	ldrh r1, [r0]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r0, 0x2]
	subs r2, 0x7
	lsls r2, 16
	lsrs r2, 16
	ldrb r3, [r0, 0x4]
	adds r0, r4, 0
	bl mapheader_trigger_activate_at
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809D0F4

	thumb_func_start FindInvisibleMapObjectByPosition
@ int FindInvisibleMapObjectByPosition(struct mapheader *mapHeader, u16 x, u16 y, u8 elevation)
FindInvisibleMapObjectByPosition: @ 809D11C
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	lsls r3, 24
	lsrs r5, r3, 24
	ldr r0, [r0, 0x4]
	ldr r4, [r0, 0x10]
	ldrb r3, [r0, 0x3]
	movs r2, 0
	cmp r2, r3
	bcs _0809D162
_0809D136:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r7
	bne _0809D158
	ldrh r0, [r1, 0x2]
	cmp r0, r6
	bne _0809D158
	ldrb r0, [r1, 0x4]
	cmp r0, r5
	beq _0809D154
	cmp r0, 0
	bne _0809D158
_0809D154:
	adds r0, r1, 0
	b _0809D164
_0809D158:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r3
	bcc _0809D136
_0809D162:
	movs r0, 0
_0809D164:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end FindInvisibleMapObjectByPosition

	thumb_func_start dive_warp
dive_warp: @ 809D16C
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x5
	bne _0809D1A4
	lsls r0, r5, 24
	lsrs r0, 24
	bl MetatileBehavior_IsUnableToEmerge
	lsls r0, 24
	cmp r0, 0
	bne _0809D1A4
	ldrh r0, [r4]
	subs r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0x2]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	bl sub_8085058
	b _0809D1C8
	.pool
_0809D1A4:
	lsls r0, r5, 24
	lsrs r0, 24
	bl MetatileBehavior_IsDiveable
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809D1E0
	ldrh r0, [r4]
	subs r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0x2]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	bl sub_8085078
_0809D1C8:
	lsls r0, 24
	cmp r0, 0
	beq _0809D1E0
	bl walkrun_find_lowest_active_bit_in_bitfield
	bl sp13E_warp_to_last_warp
	movs r0, 0xE9
	bl PlaySE
	movs r0, 0x1
	b _0809D1E2
_0809D1E0:
	movs r0, 0
_0809D1E2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end dive_warp

	thumb_func_start sub_809D1E8
sub_809D1E8: @ 809D1E8
	push {r4,r5,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x5
	bne _0809D244
	adds r0, r5, 0
	bl MetatileBehavior_IsUnableToEmerge
	lsls r0, 24
	cmp r0, 0
	bne _0809D244
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	bl sub_8085058
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809D274
	movs r0, 0x1
	b _0809D276
	.pool
_0809D244:
	adds r0, r5, 0
	bl MetatileBehavior_IsDiveable
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809D274
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4]
	subs r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	bl sub_8085078
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809D274
	movs r0, 0x2
	b _0809D276
_0809D274:
	movs r0, 0
_0809D276:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809D1E8

	thumb_func_start GetFieldObjectScriptPointerForComparison
@ u8 *GetFieldObjectScriptPointerForComparison()
GetFieldObjectScriptPointerForComparison: @ 809D280
	push {r4,r5,lr}
	sub sp, 0x8
	bl player_get_direction_upper_nybble
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r5, sp
	mov r0, sp
	bl player_get_next_pos_and_height
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	adds r2, r4, 0
	bl TryGetMapObjectScript
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetFieldObjectScriptPointerForComparison

	thumb_func_start sub_809D2BC
sub_809D2BC: @ 809D2BC
	push {r4,lr}
	sub sp, 0x8
	bl player_get_direction_upper_nybble
	mov r4, sp
	mov r0, sp
	bl player_get_pos_to_and_height
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	ldr r4, =gMapHeader
	adds r0, r4, 0
	mov r1, sp
	bl map_warp_check_packed
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	mov r2, sp
	bl sub_809CEB0
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809D2BC

	.align 2, 0 @ Don't pad with nop.
