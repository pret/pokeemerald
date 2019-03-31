	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8019930
sub_8019930: @ 8019930
	ldr r0, =0x000001a9
	bx lr
	.pool
	thumb_func_end sub_8019930

	thumb_func_start bgid_upload_textbox_1
bgid_upload_textbox_1: @ 8019938
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnkTextboxBorderGfx
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0
	str r3, [sp]
	bl DecompressAndLoadBgGfxUsingHeap
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end bgid_upload_textbox_1

	thumb_func_start is_walking_or_running
is_walking_or_running: @ 8019958
	push {lr}
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x3]
	cmp r0, 0x2
	beq _08019966
	cmp r0, 0
	bne _08019970
_08019966:
	movs r0, 0x1
	b _08019972
	.pool
_08019970:
	movs r0, 0
_08019972:
	pop {r1}
	bx r1
	thumb_func_end is_walking_or_running

	thumb_func_start sub_8019978
sub_8019978: @ 8019978
	ldr r3, =gUnknown_082F072C
	movs r2, 0x7
	ands r2, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	adds r2, r1
	adds r2, r3
	ldrb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8019978

	thumb_func_start sub_8019990
sub_8019990: @ 8019990
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, =gUnknown_082F0740
	mov r8, r4
	lsls r0, 2
	adds r4, r0, r4
	movs r6, 0
	ldrsh r5, [r4, r6]
	ldr r6, =gUnknown_082F0760
	lsls r1, 1
	adds r4, r1, r6
	ldrb r4, [r4]
	lsls r4, 24
	asrs r4, 24
	adds r5, r4
	adds r5, 0x7
	str r5, [r2]
	movs r2, 0x2
	add r8, r2
	add r0, r8
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r6, 0x1
	adds r1, r6
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019990

	thumb_func_start sub_80199E0
sub_80199E0: @ 80199E0
	push {r4-r7,lr}
	mov r12, r3
	ldr r7, =gUnknown_082F0740
	lsls r5, r0, 2
	adds r0, r5, r7
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r6, =gUnknown_082F0760
	lsls r4, r1, 1
	adds r0, r4, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r3, r0
	adds r3, 0x7
	cmp r3, r2
	bne _08019A28
	adds r0, r7, 0x2
	adds r0, r5, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r6, 0x1
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r1, r0
	adds r1, 0x7
	cmp r1, r12
	bne _08019A28
	movs r0, 0x1
	b _08019A2A
	.pool
_08019A28:
	movs r0, 0
_08019A2A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80199E0

	thumb_func_start IsUnionRoomPlayerHidden
IsUnionRoomPlayerHidden: @ 8019A30
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsUnionRoomPlayerHidden

	thumb_func_start HideUnionRoomPlayer
HideUnionRoomPlayer: @ 8019A4C
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end HideUnionRoomPlayer

	thumb_func_start ShowUnionRoomPlayer
ShowUnionRoomPlayer: @ 8019A64
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagClear
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowUnionRoomPlayer

	thumb_func_start SetUnionRoomPlayerGfx
SetUnionRoomPlayerGfx: @ 8019A7C
	push {lr}
	ldr r2, =0x00004010
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUnionRoomPlayerGfx

	thumb_func_start CreateUnionRoomPlayerEventObject
CreateUnionRoomPlayerEventObject: @ 8019A98
	push {lr}
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl show_sprite
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateUnionRoomPlayerEventObject

	thumb_func_start RemoveUnionRoomPlayerEventObject
RemoveUnionRoomPlayerEventObject: @ 8019AB8
	push {lr}
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl RemoveEventObjectByLocalIdAndMap
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveUnionRoomPlayerEventObject

	thumb_func_start SetUnionRoomPlayerEnterExitMovement
SetUnionRoomPlayerEnterExitMovement: @ 8019AD8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r1, 0
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	ldrb r1, [r5]
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	movs r0, 0x1
	b _08019B32
	.pool
_08019B30:
	movs r0, 0
_08019B32:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end SetUnionRoomPlayerEnterExitMovement

	thumb_func_start sub_8019B3C
sub_8019B3C: @ 8019B3C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08019B9C
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	bne _08019B84
	movs r0, 0
	b _08019B9E
	.pool
_08019B84:
	bl ScriptContext2_IsEnabled
	lsls r0, 24
	cmp r0, 0
	bne _08019B96
	adds r0, r4, 0
	bl UnfreezeEventObject
	b _08019B9C
_08019B96:
	adds r0, r4, 0
	bl FreezeEventObject
_08019B9C:
	movs r0, 0x1
_08019B9E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019B3C

	thumb_func_start sub_8019BA8
sub_8019BA8: @ 8019BA8
	push {lr}
	ldr r2, =gUnknown_02022C68
	movs r1, 0
	str r1, [r2]
	ldr r1, =gUnknown_02022C64
	str r0, [r1]
	movs r1, 0
	movs r2, 0x7
_08019BB8:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x3]
	adds r0, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08019BB8
	bl sub_8019DF4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8019BA8

	thumb_func_start sub_8019BDC
sub_8019BDC: @ 8019BDC
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	beq _08019BF0
	cmp r0, 0x1
	beq _08019C10
	b _08019C2E
_08019BF0:
	ldr r1, =gUnknown_082F078C
	adds r0, r4, 0
	bl SetUnionRoomPlayerEnterExitMovement
	cmp r0, 0x1
	bne _08019C2E
	adds r0, r4, 0
	bl HideUnionRoomPlayer
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _08019C2E
	.pool
_08019C10:
	adds r0, r4, 0
	bl sub_8019B3C
	cmp r0, 0
	beq _08019C2E
	adds r0, r4, 0
	bl RemoveUnionRoomPlayerEventObject
	adds r0, r4, 0
	bl HideUnionRoomPlayer
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	b _08019C30
_08019C2E:
	movs r0, 0
_08019C30:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8019BDC

	thumb_func_start sub_8019C38
sub_8019C38: @ 8019C38
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	movs r0, 0
	ldrsb r0, [r6, r0]
	cmp r0, 0x2
	beq _08019CD4
	cmp r0, 0x2
	bgt _08019C54
	cmp r0, 0
	beq _08019C5A
	b _08019CE6
_08019C54:
	cmp r0, 0x3
	beq _08019CBC
	b _08019CE6
_08019C5A:
	bl is_walking_or_running
	cmp r0, 0
	beq _08019CE6
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r4, r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _08019CE6
	mov r0, sp
	adds r1, r4, 0
	bl player_get_pos_including_state_based_drift
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r4, r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _08019CE6
	ldrb r1, [r7, 0x1]
	adds r0, r5, 0
	bl SetUnionRoomPlayerGfx
	adds r0, r5, 0
	bl CreateUnionRoomPlayerEventObject
	adds r0, r5, 0
	bl ShowUnionRoomPlayer
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_08019CBC:
	ldr r1, =gUnknown_082F078E
	adds r0, r5, 0
	bl SetUnionRoomPlayerEnterExitMovement
	cmp r0, 0x1
	bne _08019CE6
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08019CE6
	.pool
_08019CD4:
	adds r0, r5, 0
	bl sub_8019B3C
	cmp r0, 0
	beq _08019CE6
	movs r0, 0
	strb r0, [r6]
	movs r0, 0x1
	b _08019CE8
_08019CE6:
	movs r0, 0
_08019CE8:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8019C38

	thumb_func_start sub_8019CF0
sub_8019CF0: @ 8019CF0
	push {r4,lr}
	ldr r3, =gUnknown_02022C64
	lsls r0, 2
	ldr r4, [r3]
	adds r4, r0
	movs r0, 0x1
	strb r0, [r4, 0x3]
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_8019978
	strb r0, [r4, 0x1]
	ldrb r0, [r4]
	cmp r0, 0
	beq _08019D18
	movs r0, 0
	b _08019D1A
	.pool
_08019D18:
	movs r0, 0x1
_08019D1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019CF0

	thumb_func_start AGBAssert
AGBAssert: @ 8019D20
	push {lr}
	ldr r1, =gUnknown_02022C64
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1, 0x3]
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08019D3C
	movs r0, 0
	b _08019D3E
	.pool
_08019D3C:
	movs r0, 0x1
_08019D3E:
	pop {r1}
	bx r1
	thumb_func_end AGBAssert

	thumb_func_start sub_8019D44
sub_8019D44: @ 8019D44
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _08019DA6
	cmp r1, 0x1
	bgt _08019D5A
	cmp r1, 0
	beq _08019D64
	b _08019DC6
_08019D5A:
	cmp r1, 0x2
	beq _08019D70
	cmp r1, 0x3
	beq _08019DB4
	b _08019DC6
_08019D64:
	ldrb r0, [r4, 0x3]
	cmp r0, 0x1
	bne _08019DC6
	movs r0, 0x2
	strb r0, [r4]
	strb r1, [r4, 0x2]
_08019D70:
	adds r0, r5, 0
	movs r1, 0
	bl sub_8019F8C
	adds r1, r0, 0
	cmp r1, 0
	bne _08019D96
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	bne _08019D96
	strb r1, [r4]
	strb r1, [r4, 0x2]
	adds r0, r5, 0
	bl RemoveUnionRoomPlayerEventObject
	adds r0, r5, 0
	bl HideUnionRoomPlayer
	b _08019DC6
_08019D96:
	adds r0, r4, 0x2
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8019C38
	cmp r0, 0x1
	bne _08019DC6
	b _08019DC4
_08019DA6:
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	bne _08019DC6
	movs r1, 0
	movs r0, 0x3
	strb r0, [r4]
	strb r1, [r4, 0x2]
_08019DB4:
	adds r0, r4, 0x2
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8019BDC
	cmp r0, 0x1
	bne _08019DC6
	movs r0, 0
_08019DC4:
	strb r0, [r4]
_08019DC6:
	movs r0, 0
	strb r0, [r4, 0x3]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8019D44

	thumb_func_start sub_8019DD0
sub_8019DD0: @ 8019DD0
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_02022C64
_08019DD6:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	adds r0, r4, 0
	bl sub_8019D44
	adds r4, 0x1
	cmp r4, 0x7
	ble _08019DD6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019DD0

	thumb_func_start sub_8019DF4
sub_8019DF4: @ 8019DF4
	push {r4,lr}
	ldr r4, =sub_8019DD0
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08019E18
	adds r0, r4, 0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	b _08019E1A
	.pool
_08019E18:
	movs r0, 0x10
_08019E1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019DF4

	thumb_func_start sub_8019E20
sub_8019E20: @ 8019E20
	push {lr}
	ldr r0, =sub_8019DD0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _08019E34
	bl DestroyTask
_08019E34:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E20

	thumb_func_start sub_8019E3C
sub_8019E3C: @ 8019E3C
	push {r4,lr}
	movs r4, 0
_08019E40:
	adds r0, r4, 0
	bl IsUnionRoomPlayerHidden
	cmp r0, 0
	bne _08019E56
	adds r0, r4, 0
	bl RemoveUnionRoomPlayerEventObject
	adds r0, r4, 0
	bl HideUnionRoomPlayer
_08019E56:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08019E40
	ldr r1, =gUnknown_02022C64
	movs r0, 0
	str r0, [r1]
	bl sub_8019E20
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E3C

	thumb_func_start sub_8019E70
sub_8019E70: @ 8019E70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp, 0x8]
	mov r9, r1
	movs r7, 0
	mov r0, r9
	lsls r0, 2
	mov r8, r0
	ldr r0, =gUnknown_082F0740
	mov r2, r8
	adds r1, r2, r0
	ldrh r1, [r1]
	mov r2, sp
	strh r1, [r2, 0xC]
	adds r0, 0x2
	add r0, r8
	ldrh r0, [r0]
	mov r10, r0
	ldr r6, =gUnknown_082F0760
_08019E9E:
	mov r5, r8
	add r5, r9
	adds r5, r7
	adds r4, r5, 0
	subs r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	movs r2, 0
	ldrsb r2, [r6, r2]
	mov r0, sp
	ldrh r0, [r0, 0xC]
	adds r2, r0, r2
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x1
	ldrsb r3, [r6, r3]
	add r3, r10
	lsls r3, 16
	asrs r3, 16
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x41
	adds r1, r4, 0
	bl sprite_new
	ldr r1, [sp, 0x8]
	adds r5, r1, r5
	strb r0, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8097C44
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x4
	ble _08019E9E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E70

	thumb_func_start sub_8019F04
sub_8019F04: @ 8019F04
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gSprites
_08019F0C:
	adds r0, r5, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	adds r4, 0x1
	cmp r4, 0x27
	ble _08019F0C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019F04

	thumb_func_start sub_8019F2C
sub_8019F2C: @ 8019F2C
	push {r4-r7,lr}
	sub sp, 0x8
	movs r5, 0
	add r7, sp, 0x4
_08019F34:
	movs r4, 0
	adds r6, r5, 0x1
_08019F38:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0
	bl sub_8088B94
	adds r4, 0x1
	cmp r4, 0x4
	ble _08019F38
	adds r5, r6, 0
	cmp r5, 0x7
	ble _08019F34
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019F2C

	thumb_func_start sub_8019F64
sub_8019F64: @ 8019F64
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	beq _08019F78
	ldr r0, =gUnknown_082F076F
	adds r0, r1, r0
	ldrb r0, [r0]
	b _08019F88
	.pool
_08019F78:
	ldrb r1, [r2, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	beq _08019F86
	movs r0, 0x4
	b _08019F88
_08019F86:
	movs r0, 0x1
_08019F88:
	pop {r1}
	bx r1
	thumb_func_end sub_8019F64

	thumb_func_start sub_8019F8C
sub_8019F8C: @ 8019F8C
	push {lr}
	adds r2, r0, 0
	lsls r0, r2, 2
	adds r0, r2
	adds r0, r1
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097C8C
	pop {r1}
	bx r1
	thumb_func_end sub_8019F8C

	thumb_func_start sub_8019FA4
sub_8019FA4: @ 8019FA4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	mov r9, r3
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r0, r5, 2
	adds r0, r5
	adds r7, r0, r6
	adds r0, r5, 0
	bl sub_8019F8C
	cmp r0, 0x1
	bne _08019FE2
	adds r4, r7, 0
	subs r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_8097C44
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8097CC4
_08019FE2:
	adds r0, r7, 0
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	bl sub_8097BB4
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r9
	bl sub_8019F64
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_801A3B0
	add r3, sp, 0x4
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, sp
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0x1
	bl sub_8088B94
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019FA4

	thumb_func_start sub_801A02C
sub_801A02C: @ 801A02C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r4, 2
	adds r0, r4
	adds r0, r5
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_8097CC4
	add r3, sp, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0
	bl sub_8088B94
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A02C

	thumb_func_start sub_801A064
sub_801A064: @ 801A064
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	mov r8, r1
	mov r6, sp
	adds r6, 0x2
	mov r0, sp
	adds r1, r6, 0
	bl PlayerGetDestCoords
	add r4, sp, 0x4
	mov r5, sp
	adds r5, 0x6
	adds r0, r4, 0
	adds r1, r5, 0
	bl player_get_pos_including_state_based_drift
	lsls r0, r7, 2
	adds r0, r7
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097C8C
	mov r10, r6
	mov r9, r4
	adds r6, r5, 0
	cmp r0, 0x1
	bne _0801A0F0
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, r10
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r7, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _0801A15C
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r1, 0
	ldrsh r3, [r6, r1]
	adds r0, r7, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _0801A15C
	mov r2, r8
	ldrb r0, [r2, 0xB]
	lsls r0, 31
	lsrs r0, 31
	ldrb r1, [r2, 0x2]
	bl sub_8019978
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r7, 0
	movs r1, 0
	mov r3, r8
	bl sub_8019FA4
_0801A0F0:
	movs r5, 0x1
	mov r4, r8
	adds r4, 0x4
_0801A0F6:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0801A106
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_801A02C
	b _0801A154
_0801A106:
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, r10
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80199E0
	cmp r0, 0
	bne _0801A154
	mov r0, r9
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r6, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80199E0
	cmp r0, 0
	bne _0801A154
	ldrb r2, [r4]
	lsrs r0, r2, 3
	movs r1, 0x1
	ands r0, r1
	movs r1, 0x7
	ands r1, r2
	bl sub_8019978
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r7, 0
	adds r1, r5, 0
	mov r3, r8
	bl sub_8019FA4
_0801A154:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0x4
	ble _0801A0F6
_0801A15C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801A064

	thumb_func_start sub_801A16C
sub_801A16C: @ 801A16C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r4, 0xA]
	lsls r0, 25
	lsrs r0, 25
	subs r0, 0x40
	cmp r0, 0x14
	bhi _0801A20E
	lsls r0, 2
	ldr r1, =_0801A18C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A18C:
	.4byte _0801A1E0
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A1E0
_0801A1E0:
	ldrb r1, [r4, 0xB]
	lsls r1, 31
	lsrs r1, 31
	ldrb r2, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8019CF0
	movs r4, 0
_0801A1F0:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A02C
	adds r4, 0x1
	cmp r4, 0x4
	bls _0801A1F0
	b _0801A20E
_0801A200:
	adds r0, r5, 0
	bl AGBAssert
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A064
_0801A20E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A16C

	thumb_func_start sub_801A214
sub_801A214: @ 801A214
	push {r4,r5,lr}
	adds r5, r0, 0
	bl AGBAssert
	movs r4, 0
_0801A21E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A02C
	adds r4, 0x1
	cmp r4, 0x4
	ble _0801A21E
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A214

	thumb_func_start sub_801A234
sub_801A234: @ 801A234
	push {r4,r5,lr}
	ldr r2, =gUnknown_02022C68
	movs r1, 0
	str r1, [r2]
	movs r5, 0
	ldr r4, [r0]
_0801A240:
	ldrb r0, [r4, 0x1A]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x1
	bne _0801A258
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A16C
	b _0801A264
	.pool
_0801A258:
	cmp r1, 0x2
	bne _0801A264
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A214
_0801A264:
	adds r4, 0x20
	adds r5, 0x1
	cmp r5, 0x7
	ble _0801A240
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A234

	thumb_func_start sub_801A274
sub_801A274: @ 801A274
	ldr r1, =gUnknown_02022C68
	movs r0, 0x96
	lsls r0, 1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801A274

	thumb_func_start sub_801A284
sub_801A284: @ 801A284
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02022C68
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	movs r0, 0x96
	lsls r0, 1
	cmp r1, r0
	bls _0801A29E
	adds r0, r2, 0
	bl sub_801A234
_0801A29E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A284

	thumb_func_start sub_801A2A8
sub_801A2A8: @ 801A2A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	bl is_walking_or_running
	cmp r0, 0
	bne _0801A2F0
	b _0801A396
_0801A2C4:
	ldr r4, =gUnknown_082F076A
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r2, [r0]
	adds r0, r6, 0
	ldr r1, [sp, 0xC]
	bl sub_801A3B0
	ldr r0, [sp, 0x4]
	strh r6, [r0]
	mov r1, sp
	ldrh r2, [r1, 0xC]
	ldr r1, [sp, 0x8]
	strh r2, [r1]
	movs r0, 0x1
	b _0801A398
	.pool
_0801A2F0:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r0, 0
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_082F0740
	adds r7, r5, 0
	movs r1, 0
	mov r10, r1
	adds r2, r0, 0x2
	str r2, [sp, 0x10]
	str r0, [sp, 0x14]
_0801A30E:
	movs r6, 0
	ldr r4, [sp, 0x14]
	movs r0, 0
	ldrsh r4, [r4, r0]
	mov r9, r4
	ldr r1, [sp, 0x10]
	mov r8, r1
	ldr r5, =gUnknown_082F0760
_0801A31E:
	mov r2, r10
	adds r3, r2, r6
	mov r0, sp
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r5, r0]
	add r0, r9
	adds r0, 0x7
	cmp r1, r0
	bne _0801A372
	mov r1, sp
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	mov r4, r8
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r2, 0x1
	ldrsb r2, [r5, r2]
	adds r1, r2
	adds r1, 0x7
	cmp r0, r1
	bne _0801A372
	adds r0, r3, 0
	subs r0, 0x38
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8097C8C
	cmp r0, 0
	bne _0801A372
	adds r0, r4, 0
	bl sub_8097D9C
	cmp r0, 0
	bne _0801A372
	ldrb r1, [r7, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0801A2C4
_0801A372:
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x4
	ble _0801A31E
	adds r7, 0x20
	movs r4, 0x5
	add r10, r4
	ldr r0, [sp, 0x10]
	adds r0, 0x4
	str r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	adds r1, 0x4
	str r1, [sp, 0x14]
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	cmp r2, 0x7
	ble _0801A30E
_0801A396:
	movs r0, 0
_0801A398:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801A2A8

	thumb_func_start sub_801A3B0
sub_801A3B0: @ 801A3B0
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r1, r2, 24
	lsrs r1, 24
	lsls r0, r3, 2
	adds r0, r3
	subs r0, 0x38
	adds r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B78
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801A3B0

	thumb_func_start sub_801A3D0
sub_801A3D0: @ 801A3D0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r3, r4, 5
	adds r3, r2
	adds r2, r3, 0
	bl sub_8019F64
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A3B0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A3D0

	thumb_func_start sub_801A3F4
sub_801A3F4: @ 801A3F4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801A414
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801A414:
	pop {r0}
	bx r0
	thumb_func_end sub_801A3F4

	thumb_func_start sub_801A418
sub_801A418: @ 801A418
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801A418

	thumb_func_start sub_801A42C
sub_801A42C: @ 801A42C
	push {lr}
	ldr r0, =sub_801A43C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A42C

	thumb_func_start sub_801A43C
sub_801A43C: @ 801A43C
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r5, =gUnknown_03000DAC
	movs r0, 0x6C
	bl AllocZeroed
	str r0, [r5]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0D34
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gWirelessInfoScreenGfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, =gWirelessInfoScreenTilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_082F0D3C
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl ScanlineEffect_Stop
	bl m4aSoundVSyncOn
	ldr r0, =sub_801A418
	bl SetVBlankCallback
	ldr r0, =sub_801A6C0
	movs r1, 0
	bl CreateTask
	ldr r1, [r5]
	adds r1, 0x60
	strb r0, [r1]
	bl sub_8013C40
	ldr r1, [r5]
	adds r1, 0x61
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x1C]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gWirelessInfoScreenPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xF0
	bl sub_81978B0
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =sub_801A3F4
	bl SetMainCallback2
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A43C

	thumb_func_start sub_801A584
sub_801A584: @ 801A584
	push {r4,lr}
	bl FreeAllWindowBuffers
	movs r4, 0
_0801A58C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	bl Free
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801A58C
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	bl Free
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A584

	thumb_func_start sub_801A5BC
sub_801A5BC: @ 801A5BC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _0801A5E4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bne _0801A5E0
	movs r0, 0
	strh r0, [r1]
_0801A5E0:
	movs r0, 0
	strh r0, [r2]
_0801A5E4:
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x2
	lsls r0, 5
	ldr r1, =gWirelessInfoScreenPal
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A5BC

	thumb_func_start sub_801A600
sub_801A600: @ 801A600
	push {r4,r5,lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_082F0D5C
	ldr r4, [r5]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_801A8B0
	movs r1, 0
_0801A644:
	adds r4, r1, 0x1
	lsls r0, r4, 2
	adds r0, r5
	ldr r2, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	adds r1, r4, 0
	cmp r4, 0x2
	ble _0801A644
	ldr r1, =gUnknown_082F0D5C
	adds r0, r4, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A600

	thumb_func_start sub_801A6C0
sub_801A6C0: @ 801A6C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x5
	bls _0801A6E2
	b _0801A89C
_0801A6E2:
	lsls r0, 2
	ldr r1, =_0801A6F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A6F4:
	.4byte _0801A70C
	.4byte _0801A728
	.4byte _0801A74C
	.4byte _0801A768
	.4byte _0801A85C
	.4byte _0801A884
_0801A70C:
	bl sub_801A600
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0801A89C
	.pool
_0801A728:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl ShowBg
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	b _0801A86C
_0801A74C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0801A75A
	b _0801A89C
_0801A75A:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	b _0801A876
	.pool
_0801A768:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x10
	adds r2, r0, 0
	adds r2, 0x20
	adds r3, r0, 0
	adds r3, 0x61
	ldrb r3, [r3]
	bl sub_801AA30
	lsls r1, r5, 2
	mov r8, r1
	cmp r0, 0
	beq _0801A7F8
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r4, 0
	ldr r6, =gStringVar4
	movs r7, 0x80
	lsls r7, 20
_0801A796:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	cmp r4, 0x3
	beq _0801A7CC
	lsrs r0, r7, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
	b _0801A7DE
	.pool
_0801A7CC:
	movs r0, 0x62
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
_0801A7DE:
	movs r2, 0xF0
	lsls r2, 21
	adds r7, r2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801A796
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
_0801A7F8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801A80C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801A836
_0801A80C:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gTasks
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r0, 0x61
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xFF
	strh r1, [r0, 0x26]
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0801A836:
	mov r2, r8
	adds r1, r2, r5
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r0, r1, 0
	adds r0, 0xE
	adds r1, 0x10
	bl sub_801A5BC
	b _0801A89C
	.pool
_0801A85C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0801A86C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
_0801A876:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0801A89C
	.pool
_0801A884:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801A89C
	ldr r0, =sub_801A584
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_0801A89C:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A6C0

	thumb_func_start sub_801A8B0
sub_801A8B0: @ 801A8B0
	push {r4-r7,lr}
	sub sp, 0x18
	mov r12, r2
	ldr r2, [sp, 0x2C]
	ldr r4, [sp, 0x30]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r4, 24
	lsrs r0, r4, 24
	cmp r0, 0x4
	bhi _0801A93A
	lsls r0, 2
	ldr r1, =_0801A8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A8E0:
	.4byte _0801A8F4
	.4byte _0801A902
	.4byte _0801A910
	.4byte _0801A91E
	.4byte _0801A92C
_0801A8F4:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A902:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A910:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x5
	b _0801A938
_0801A91E:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	movs r0, 0x6
	b _0801A938
_0801A92C:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
_0801A938:
	strb r0, [r1, 0x2]
_0801A93A:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	mov r0, r12
	str r0, [sp, 0x10]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801A8B0

	thumb_func_start sub_801A960
sub_801A960: @ 801A960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r12, r0
	adds r7, r1, 0
	ldrb r0, [r0, 0xA]
	lsls r0, 25
	lsrs r0, 25
	mov r8, r0
	movs r4, 0
	ldr r0, =gUnknown_082F0D70
	mov r9, r0
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	mov r3, r12
	adds r3, 0x4
	str r3, [sp]
_0801A98A:
	lsls r0, r4, 1
	adds r2, r0, r4
	mov r3, r9
	adds r1, r2, r3
	adds r5, r0, 0
	adds r6, r4, 0x1
	ldrb r1, [r1]
	cmp r8, r1
	bne _0801A9EE
	mov r0, r12
	ldrb r1, [r0, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801A9EE
	mov r0, r9
	adds r0, 0x2
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, 0
	bne _0801A9DC
	movs r2, 0
	movs r1, 0
	ldr r3, [sp]
_0801A9BA:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801A9C4
	adds r2, 0x1
_0801A9C4:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801A9BA
	adds r2, 0x1
	adds r0, r5, r4
	add r0, r10
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	b _0801A9E8
	.pool
_0801A9DC:
	mov r1, r10
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r3]
_0801A9E8:
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
_0801A9EE:
	adds r4, r6, 0
	cmp r4, 0x1E
	bls _0801A98A
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801A960

	thumb_func_start sub_801AA08
sub_801AA08: @ 801AA08
	push {r4,lr}
	movs r4, 0
	adds r3, r1, 0
	adds r2, r0, 0
_0801AA10:
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _0801AA1C
	movs r0, 0x1
	b _0801AA28
_0801AA1C:
	adds r3, 0x4
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801AA10
	movs r0, 0
_0801AA28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA08

	thumb_func_start sub_801AA30
sub_801AA30: @ 801AA30
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r0, 0
	mov r9, r1
	adds r5, r2, 0
	lsls r4, r3, 24
	lsrs r4, 24
	movs r0, 0
	mov r8, r0
	mov r0, sp
	movs r1, 0
	movs r2, 0x10
	bl memset
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r4, 0
_0801AA5E:
	lsls r1, r4, 5
	ldr r0, [r7]
	adds r0, r1
	mov r1, sp
	bl sub_801A960
	adds r1, r0, 0
	ldr r0, [r5]
	cmp r1, r0
	beq _0801AA78
	str r1, [r5]
	movs r2, 0x1
	mov r8, r2
_0801AA78:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801AA5E
	mov r0, sp
	mov r1, r9
	bl sub_801AA08
	cmp r0, 0
	bne _0801AA9C
	mov r3, r8
	cmp r3, 0x1
	beq _0801AAC4
	movs r0, 0
	b _0801AAC6
	.pool
_0801AA9C:
	adds r1, r6, 0
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	adds r0, r1
	ldr r1, [r6, 0x8]
	adds r0, r1
	ldr r1, [r6, 0xC]
	adds r0, r1
	str r0, [r6, 0xC]
_0801AAC4:
	movs r0, 0x1
_0801AAC6:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA30

	thumb_func_start sub_801AAD4
sub_801AAD4: @ 801AAD4
	push {r4-r7,lr}
	movs r0, 0xA
	bl sub_8014210
	movs r4, 0
	movs r7, 0x64
	ldr r6, =gPlayerParty
	ldr r5, =gEnemyParty
_0801AAE4:
	ldr r0, =gSelectedOrderFromParty
	adds r0, r4, r0
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r0, 0
	muls r1, r7
	adds r1, r6
	adds r0, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x64
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801AAE4
	ldr r4, =gPlayerParty
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_0801AB0A:
	adds r0, r4, 0
	bl ZeroMonData
	adds r4, 0x64
	cmp r4, r5
	ble _0801AB0A
	ldr r4, =gPlayerParty
	movs r5, 0
	adds r6, r4, 0
	adds r6, 0x64
_0801AB1E:
	ldr r1, =gEnemyParty
	adds r1, r5, r1
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r4, 0x64
	adds r5, 0x64
	cmp r4, r6
	ble _0801AB1E
	movs r0, 0x32
	bl IncrementGameStat
	bl CalculatePlayerPartyCount
	ldr r0, =gTrainerBattleOpponent_A
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AAD4

	thumb_func_start sub_801AB68
sub_801AB68: @ 801AB68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	ldr r4, [sp, 0x38]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0x1
	mov r10, r1
	ldr r0, =gUnknown_082F0DE4
	mov r8, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	str r3, [sp, 0x14]
	bl FillWindowPixelBuffer
	mov r1, r9
	str r1, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AB68

	thumb_func_start sub_801ABDC
sub_801ABDC: @ 801ABDC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0801ABF4
	cmp r0, 0x1
	beq _0801AC22
	b _0801AC36
_0801ABF4:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	str r5, [sp]
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_801AB68
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0801AC36
_0801AC22:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0801AC36
	strh r0, [r4]
	movs r0, 0x1
	b _0801AC38
_0801AC36:
	movs r0, 0
_0801AC38:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ABDC

	thumb_func_start sub_801AC40
sub_801AC40: @ 801AC40
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801AC40

	thumb_func_start sub_801AC54
sub_801AC54: @ 801AC54
	push {r4,lr}
	sub sp, 0xC
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x33
	bls _0801AC6A
	b _0801AFAE
_0801AC6A:
	lsls r0, 2
	ldr r1, =_0801AC7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801AC7C:
	.4byte _0801AD4C
	.4byte _0801ADFC
	.4byte _0801AE24
	.4byte _0801AE48
	.4byte _0801AE98
	.4byte _0801AFAE
	.4byte _0801AF7C
	.4byte _0801AF58
	.4byte _0801AF7C
	.4byte _0801AF98
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AF24
	.4byte _0801AF40
_0801AD4C:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022C6C
	movs r0, 0x4
	bl AllocZeroed
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0DD0
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	bl reset_temp_tile_data_buffers
	ldr r0, =gUnknown_082F0DD4
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	bne _0801AD8C
	b _0801AFC2
_0801AD8C:
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	bl sub_819789C
	ldr r0, =sub_801AC40
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801ADFC:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_CommStandbyAwaitingOtherPlayer
	movs r2, 0
	bl sub_801ABDC
	cmp r0, 0
	bne _0801AE0E
	b _0801AFAE
_0801AE0E:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE24:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801AE48:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801AE54
	b _0801AFAE
_0801AE54:
	ldr r4, =gBlockSendBuffer
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x20
	bl memset
	ldr r0, =gSelectedOrderFromParty
	ldrb r1, [r0]
	ldrb r0, [r0, 0x1]
	cmn r1, r0
	bne _0801AE78
	movs r0, 0x52
	b _0801AE7A
	.pool
_0801AE78:
	movs r0, 0x51
_0801AE7A:
	strb r0, [r4]
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0x20
	bl SendBlock
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE98:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0801AEA6
	b _0801AFAE
_0801AEA6:
	ldr r1, =gBlockRecvBuffer
	ldrh r0, [r1]
	cmp r0, 0x51
	bne _0801AEE0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x51
	bne _0801AEE0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x32
	b _0801AF16
	.pool
_0801AEE0:
	bl sub_800AC34
	ldr r4, =gBlockRecvBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 16
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x52
	bne _0801AF0C
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x6
	b _0801AF16
	.pool
_0801AF0C:
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x8
_0801AF16:
	strb r1, [r0]
	bl ResetBlockReceivedFlags
	b _0801AFAE
	.pool
_0801AF24:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801AFAE
	bl sub_800ADF8
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AF40:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =sub_801AAD4
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF58:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_RefusedBattle
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF7C:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801AFAE
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
_0801AF8A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0801AFAE
	.pool
_0801AF98:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_BattleWasRefused
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
_0801AFAE:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801AFC2:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AC54
