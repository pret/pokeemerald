	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8093038
sub_8093038: @ 8093038
	push {r4-r7,lr}
	adds r7, r2, 0
	mov r12, r3
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r0, =gUnknown_03005DEC
	ldrh r0, [r0]
	negs r0, r0
	ldr r1, =gUnknown_03005DD0
	ldr r2, [r1, 0x10]
	subs r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_03005DE8
	ldrh r0, [r0]
	negs r0, r0
	ldr r1, [r1, 0x14]
	subs r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r2, 0
	ble _08093072
	lsls r0, r3, 16
	movs r3, 0x80
	lsls r3, 13
	adds r0, r3
	lsrs r3, r0, 16
_08093072:
	cmp r2, 0
	bge _0809307E
	lsls r0, r3, 16
	ldr r2, =0xfff00000
	adds r0, r2
	lsrs r3, r0, 16
_0809307E:
	cmp r1, 0
	ble _0809308C
	lsls r0, r4, 16
	movs r2, 0x80
	lsls r2, 13
	adds r0, r2
	lsrs r4, r0, 16
_0809308C:
	cmp r1, 0
	bge _08093098
	lsls r0, r4, 16
	ldr r1, =0xfff00000
	adds r0, r1
	lsrs r4, r0, 16
_08093098:
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldrh r1, [r0]
	lsls r0, r5, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 4
	lsls r1, r3, 16
	asrs r1, 16
	adds r1, r0
	strh r1, [r7]
	ldr r0, [r2]
	ldrh r1, [r0, 0x2]
	lsls r0, r6, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 4
	lsls r1, r4, 16
	asrs r1, 16
	adds r1, r0
	mov r2, r12
	strh r1, [r2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8093038

	thumb_func_start sub_80930E0
sub_80930E0: @ 80930E0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	mov r8, r1
	adds r4, r2, 0
	adds r5, r3, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	movs r1, 0
	ldrsh r0, [r6, r1]
	mov r2, r8
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r2, r6, 0
	mov r3, r8
	bl sub_8093038
	lsls r4, 16
	asrs r4, 16
	ldrh r0, [r6]
	adds r4, r0
	strh r4, [r6]
	lsls r5, 16
	asrs r5, 16
	mov r1, r8
	ldrh r1, [r1]
	adds r5, r1
	mov r2, r8
	strh r5, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80930E0

	thumb_func_start GetFieldObjectMovingCameraOffset
@ void GetFieldObjectMovingCameraOffset(s16 *x, s16 *y)
GetFieldObjectMovingCameraOffset: @ 809312C
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	strh r0, [r2]
	strh r0, [r1]
	ldr r3, =gUnknown_03005DD0
	ldr r0, [r3, 0x10]
	cmp r0, 0
	ble _08093142
	movs r0, 0x1
	strh r0, [r2]
_08093142:
	ldr r0, [r3, 0x10]
	cmp r0, 0
	bge _0809314E
	ldrh r0, [r2]
	subs r0, 0x1
	strh r0, [r2]
_0809314E:
	ldr r2, [r3, 0x14]
	cmp r2, 0
	ble _0809315A
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0809315A:
	cmp r2, 0
	bge _08093164
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_08093164:
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetFieldObjectMovingCameraOffset

	thumb_func_start FieldObjectMoveDestCoords
@ void FieldObjectMoveDestCoords(struct npc_state *fieldObject, u8 direction)
FieldObjectMoveDestCoords: @ 809316C
	push {r4,lr}
	lsls r1, 24
	lsrs r1, 24
	ldrh r4, [r0, 0x10]
	strh r4, [r2]
	ldrh r0, [r0, 0x12]
	strh r0, [r3]
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	bl MoveCoords
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectMoveDestCoords

	thumb_func_start FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
@ bool8 FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(struct npc_state *fieldObject)
FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive: @ 809318C
	push {lr}
	ldrb r1, [r0]
	movs r0, 0x42
	ands r0, r1
	cmp r0, 0
	bne _0809319C
	movs r0, 0
	b _0809319E
_0809319C:
	movs r0, 0x1
_0809319E:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive

	thumb_func_start FieldObjectIsSpecialAnimActive
@ bool8 FieldObjectIsSpecialAnimActive(struct npc_state *fieldObject)
FieldObjectIsSpecialAnimActive: @ 80931A4
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	bge _080931BA
	ldrb r0, [r1, 0x1C]
	cmp r0, 0xFF
	beq _080931BA
	movs r0, 0x1
	b _080931BC
_080931BA:
	movs r0, 0
_080931BC:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectIsSpecialAnimActive

	thumb_func_start FieldObjectSetSpecialAnim
@ bool8 FieldObjectSetSpecialAnim(struct npc_state *fieldObject, u8 animId)
FieldObjectSetSpecialAnim: @ 80931C0
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08093200
	adds r0, r4, 0
	bl npc_sync_anim_pause_bits
	strb r5, [r4, 0x1C]
	ldrb r0, [r4]
	movs r1, 0x40
	orrs r0, r1
	movs r1, 0x7F
	ands r0, r1
	strb r0, [r4]
	ldr r2, =gSprites
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r6, [r0, 0x32]
	movs r0, 0
	b _08093202
	.pool
_08093200:
	movs r0, 0x1
_08093202:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end FieldObjectSetSpecialAnim

	thumb_func_start FieldObjectForceSetSpecialAnim
@ void FieldObjectForceSetSpecialAnim(struct npc_state *fieldObject, u8 animId)
FieldObjectForceSetSpecialAnim: @ 8093208
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl FieldObjectClearAnimIfSpecialAnimActive
	adds r0, r5, 0
	adds r1, r4, 0
	bl FieldObjectSetSpecialAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectForceSetSpecialAnim

	thumb_func_start FieldObjectClearAnimIfSpecialAnimActive
@ void FieldObjectClearAnimIfSpecialAnimActive(struct npc_state *fieldObject)
FieldObjectClearAnimIfSpecialAnimActive: @ 8093224
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	bge _08093236
	adds r0, r1, 0
	bl FieldObjectClearAnim
_08093236:
	pop {r0}
	bx r0
	thumb_func_end FieldObjectClearAnimIfSpecialAnimActive

	thumb_func_start FieldObjectClearAnim
@ void FieldObjectClearAnim(struct npc_state *fieldObject)
FieldObjectClearAnim: @ 809323C
	movs r1, 0xFF
	strb r1, [r0, 0x1C]
	ldrb r2, [r0]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	movs r2, 0x7F
	ands r1, r2
	strb r1, [r0]
	ldr r3, =gSprites
	ldrb r2, [r0, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	movs r2, 0
	strh r2, [r1, 0x30]
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x32]
	bx lr
	.pool
	thumb_func_end FieldObjectClearAnim

    .section .text.get_simple_go_anim_id

	thumb_func_start GetSimpleGoAnimId
@ u8 GetSimpleGoAnimId(u8 direction)
GetSimpleGoAnimId: @ 809335C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBA5
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093374
	movs r4, 0
_08093374:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSimpleGoAnimId

	thumb_func_start GetGoSpeed0AnimId
@ u8 GetGoSpeed0AnimId(u8 direction)
GetGoSpeed0AnimId: @ 8093388
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBAA
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080933A0
	movs r4, 0
_080933A0:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGoSpeed0AnimId

	thumb_func_start GetGoSpeed1AnimId
@ u8 GetGoSpeed1AnimId(u8 direction)
GetGoSpeed1AnimId: @ 80933B4
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBAF
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080933CC
	movs r4, 0
_080933CC:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGoSpeed1AnimId

	thumb_func_start GetGoSpeed2AnimId
@ u8 GetGoSpeed2AnimId(u8 direction)
GetGoSpeed2AnimId: @ 80933E0
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBB4
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080933F8
	movs r4, 0
_080933F8:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGoSpeed2AnimId

	thumb_func_start GetGoSpeed3AnimId
@ u8 GetGoSpeed3AnimId(u8 direction)
GetGoSpeed3AnimId: @ 809340C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBB9
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093424
	movs r4, 0
_08093424:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGoSpeed3AnimId

	thumb_func_start sub_8093438
@ u8 sub_8093438(u8 direction)
sub_8093438: @ 8093438
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBBE
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093450
	movs r4, 0
_08093450:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093438

	thumb_func_start GetRunAnimId
@ u8 GetRunAnimId(u8 direction)
GetRunAnimId: @ 8093464
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBC3
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _0809347C
	movs r4, 0
_0809347C:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetRunAnimId

	thumb_func_start GetJumpLedgeAnimId
@ u8 GetJumpLedgeAnimId(u8 direction)
GetJumpLedgeAnimId: @ 8093490
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBC8
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080934A8
	movs r4, 0
_080934A8:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetJumpLedgeAnimId

	thumb_func_start sub_80934BC
@ u8 sub_80934BC(u8 direction)
sub_80934BC: @ 80934BC
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBCD
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080934D4
	movs r4, 0
_080934D4:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80934BC

	thumb_func_start sub_80934E8
@ u8 sub_80934E8(u8 direction)
sub_80934E8: @ 80934E8
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBD2
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093500
	movs r4, 0
_08093500:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80934E8

	thumb_func_start sub_8093514
@ u8 sub_8093514(u8 direction)
sub_8093514: @ 8093514
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBD7
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _0809352C
	movs r4, 0
_0809352C:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093514

	thumb_func_start sub_8093540
@ u8 sub_8093540(u8 direction)
sub_8093540: @ 8093540
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBDC
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093558
	movs r4, 0
_08093558:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093540

	thumb_func_start GetStepInPlaceDelay32AnimId
@ u8 GetStepInPlaceDelay32AnimId(u8 direction)
GetStepInPlaceDelay32AnimId: @ 809356C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBE1
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093584
	movs r4, 0
_08093584:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetStepInPlaceDelay32AnimId

	thumb_func_start GetStepInPlaceDelay16AnimId
@ u8 GetStepInPlaceDelay16AnimId(u8 direction)
GetStepInPlaceDelay16AnimId: @ 8093598
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBE6
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080935B0
	movs r4, 0
_080935B0:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetStepInPlaceDelay16AnimId

	thumb_func_start GetStepInPlaceDelay8AnimId
@ u8 GetStepInPlaceDelay8AnimId(u8 direction)
GetStepInPlaceDelay8AnimId: @ 80935C4
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBEB
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080935DC
	movs r4, 0
_080935DC:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetStepInPlaceDelay8AnimId

	thumb_func_start GetStepInPlaceDelay4AnimId
@ u8 GetStepInPlaceDelay4AnimId(u8 direction)
GetStepInPlaceDelay4AnimId: @ 80935F0
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBF0
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093608
	movs r4, 0
_08093608:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetStepInPlaceDelay4AnimId

	thumb_func_start FieldObjectFaceOppositeDirection
@ bool8 FieldObjectFaceOppositeDirection(struct npc_state *fieldObject, u8 direction)
FieldObjectFaceOppositeDirection: @ 809361C
	push {r4,lr}
	adds r4, r0, 0
	lsls r0, r1, 24
	lsrs r0, 24
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FieldObjectFaceOppositeDirection

	thumb_func_start sub_8093648
sub_8093648: @ 8093648
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBF5
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093660
	movs r4, 0
_08093660:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093648

	thumb_func_start sub_8093674
sub_8093674: @ 8093674
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBFA
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _0809368C
	movs r4, 0
_0809368C:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093674

	thumb_func_start sub_80936A0
sub_80936A0: @ 80936A0
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBFF
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080936B8
	movs r4, 0
_080936B8:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80936A0

	thumb_func_start sub_80936CC
sub_80936CC: @ 80936CC
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC04
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080936E4
	movs r4, 0
_080936E4:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80936CC

	thumb_func_start sub_80936F8
sub_80936F8: @ 80936F8
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC09
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093710
	movs r4, 0
_08093710:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80936F8

	thumb_func_start sub_8093724
sub_8093724: @ 8093724
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC0E
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _0809373C
	movs r4, 0
_0809373C:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093724

	thumb_func_start sub_8093750
sub_8093750: @ 8093750
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC13
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093768
	movs r4, 0
_08093768:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8093750

	thumb_func_start sub_809377C
sub_809377C: @ 809377C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC18
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093794
	movs r4, 0
_08093794:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809377C

	thumb_func_start sub_80937A8
sub_80937A8: @ 80937A8
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC1D
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080937C0
	movs r4, 0
_080937C0:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80937A8

	thumb_func_start d2s_08064034
d2s_08064034: @ 80937D4
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC22
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _080937EC
	movs r4, 0
_080937EC:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end d2s_08064034

	thumb_func_start GetOppositeDirection
@ u8 GetOppositeDirection(u8 direction)
GetOppositeDirection: @ 8093800
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DC27
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	subs r1, r4, 0x1
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x7
	bhi _08093828
	mov r2, sp
	adds r0, r2, r1
	ldrb r0, [r0]
	b _0809382A
	.pool
_08093828:
	adds r0, r4, 0
_0809382A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetOppositeDirection

	thumb_func_start zffu_offset_calc
zffu_offset_calc: @ 8093834
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0850DC2F
	lsrs r0, 22
	subs r0, 0x5
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end zffu_offset_calc

	thumb_func_start state_to_direction
state_to_direction: @ 809384C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	lsls r2, 24
	lsrs r2, 24
	cmp r1, 0
	beq _0809386C
	cmp r2, 0
	beq _0809386C
	cmp r1, 0x4
	bhi _0809386C
	cmp r2, 0x4
	bls _08093870
_0809386C:
	movs r0, 0
	b _08093882
_08093870:
	adds r1, r2, 0
	bl zffu_offset_calc
	ldr r2, =gUnknown_0850DC3F
	lsls r1, r4, 2
	subs r1, 0x5
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
_08093882:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end state_to_direction

	thumb_func_start FieldObjectExecSpecialAnim
@ void FieldObjectExecSpecialAnim(struct npc_state *fieldObject, struct obj *object)
FieldObjectExecSpecialAnim: @ 809388C
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_0850DC50
	ldrb r0, [r4, 0x1C]
	lsls r0, 2
	adds r0, r2
	movs r3, 0x32
	ldrsh r2, [r1, r3]
	ldr r0, [r0]
	lsls r2, 2
	adds r2, r0
	ldr r2, [r2]
	adds r0, r4, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	beq _080938B8
	ldrb r0, [r4]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4]
_080938B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectExecSpecialAnim

	thumb_func_start FieldObjectExecRegularAnim
@ bool8 FieldObjectExecRegularAnim(struct npc_state *fieldObject, struct obj *object)
FieldObjectExecRegularAnim: @ 80938C4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DC50
	ldrb r0, [r4, 0x1C]
	lsls r0, 2
	adds r0, r1
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldr r2, [r1]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	bne _080938F4
	movs r0, 0
	b _080938FE
	.pool
_080938F4:
	movs r0, 0xFF
	strb r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080938FE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end FieldObjectExecRegularAnim

	thumb_func_start FieldObjectSetRegularAnim
@ void FieldObjectSetRegularAnim(struct npc_state *fieldObject, struct obj *object, u8 animState)
FieldObjectSetRegularAnim: @ 8093904
	movs r3, 0
	strb r2, [r0, 0x1C]
	strh r3, [r1, 0x32]
	bx lr
	thumb_func_end FieldObjectSetRegularAnim

	thumb_func_start an_look_any
@ void an_look_any(struct npc_state *fieldObject, struct obj *object, u8 direction)
an_look_any: @ 809390C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r1, r2, 24
	lsrs r1, 24
	bl FieldObjectSetDirection
	adds r0, r4, 0
	bl npc_coords_shift_still
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl get_go_image_anim_num
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl obj_npc_animation_step
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strh r0, [r5, 0x32]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end an_look_any

	thumb_func_start sub_8093950
sub_8093950: @ 8093950
	push {lr}
	movs r2, 0x1
	bl an_look_any
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093950

	thumb_func_start sub_8093960
sub_8093960: @ 8093960
	push {lr}
	movs r2, 0x2
	bl an_look_any
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093960

	thumb_func_start sub_8093970
sub_8093970: @ 8093970
	push {lr}
	movs r2, 0x3
	bl an_look_any
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093970

	thumb_func_start sub_8093980
sub_8093980: @ 8093980
	push {lr}
	movs r2, 0x4
	bl an_look_any
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093980

	thumb_func_start npc_apply_direction
@ void npc_apply_direction(struct npc_state *fieldObject, struct obj *object, u8 direction, u8 speed)
npc_apply_direction: @ 8093990
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	mov r8, r1
	adds r4, r2, 0
	adds r6, r3, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	ldrh r1, [r7, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r7, 0x12]
	mov r5, sp
	adds r5, 0x2
	strh r0, [r5]
	adds r0, r7, 0
	adds r1, r4, 0
	bl FieldObjectSetDirection
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl MoveCoords
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r7, 0
	bl npc_coords_shift
	mov r0, r8
	adds r1, r4, 0
	adds r2, r6, 0
	bl oamt_npc_ministep_reset
	mov r4, r8
	adds r4, 0x2C
	ldrb r1, [r4]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldr r0, =gUnknown_020375B8
	ldr r0, [r0]
	cmp r0, 0
	beq _08093A0E
	adds r0, r7, 0
	bl sub_8097F78
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _08093A0E
	ldrb r0, [r4]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4]
_08093A0E:
	ldrb r0, [r7]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r7]
	movs r0, 0x1
	mov r1, r8
	strh r0, [r1, 0x32]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end npc_apply_direction

	thumb_func_start do_go_anim
@ void do_go_anim(struct npc_state *fieldObject, struct obj *object, u8 direction, u8 speed)
do_go_anim: @ 8093A2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r0, 0
	mov r8, r1
	adds r4, r3, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r4, 24
	lsrs r4, 24
	mov r1, sp
	ldr r0, =gUnknown_0850DEE8
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6}
	stm r1!, {r3,r6}
	adds r0, r5, 0
	mov r1, r8
	adds r3, r4, 0
	bl npc_apply_direction
	lsls r4, 2
	mov r7, sp
	adds r1, r7, r4
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	ldr r1, [r1]
	bl _call_via_r1
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	mov r1, r8
	bl npc_apply_anim_looping
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end do_go_anim

	thumb_func_start do_run_anim
@ void do_run_anim(struct npc_state *fieldObject, struct obj *object, u8 direction)
do_run_anim: @ 8093A88
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0x1
	bl npc_apply_direction
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl get_run_image_anim_num
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_apply_anim_looping
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end do_run_anim

	thumb_func_start npc_obj_ministep_stop_on_arrival
@ bool8 npc_obj_ministep_stop_on_arrival(struct npc_state *fieldObject, struct obj *object)
npc_obj_ministep_stop_on_arrival: @ 8093AB8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl obj_npc_ministep
	lsls r0, 24
	cmp r0, 0
	bne _08093ACE
	movs r0, 0
	b _08093AEA
_08093ACE:
	adds r0, r4, 0
	bl npc_coords_shift_still
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
_08093AEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end npc_obj_ministep_stop_on_arrival

	thumb_func_start sub_8093AF0
@ void sub_8093AF0(struct npc_state *fieldObject, struct obj *object, u8 direction)
sub_8093AF0: @ 8093AF0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	lsls r5, r2, 24
	lsrs r5, 24
	ldrh r1, [r6, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r6, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	adds r0, r6, 0
	adds r1, r5, 0
	bl FieldObjectSetDirection
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl MoveCoords
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r4, r0]
	adds r0, r6, 0
	bl npc_coords_shift
	mov r0, r8
	adds r1, r5, 0
	bl sub_80976DC
	mov r2, r8
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
	movs r0, 0x1
	mov r1, r8
	strh r0, [r1, 0x32]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8093AF0

	thumb_func_start sub_8093B60
@ void sub_8093B60(struct npc_state *fieldObject, struct obj *object, u8 direction)
sub_8093B60: @ 8093B60
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	bl sub_8093AF0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl get_go_image_anim_num
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_apply_anim_looping
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8093B60

	thumb_func_start an_walk_any_2
@ bool8 an_walk_any_2(struct npc_state *fieldObject, struct obj *object)
an_walk_any_2: @ 8093B8C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_80976EC
	lsls r0, 24
	cmp r0, 0
	bne _08093BA2
	movs r0, 0
	b _08093BBE
_08093BA2:
	adds r0, r4, 0
	bl npc_coords_shift_still
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
_08093BBE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end an_walk_any_2

	thumb_func_start sub_8093BC4
sub_8093BC4: @ 8093BC4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x7
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093BE4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093BC4

	thumb_func_start sub_8093BE4
sub_8093BE4: @ 8093BE4
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093BF6
	movs r0, 0
	b _08093BFC
_08093BF6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093BFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093BE4

	thumb_func_start sub_8093C04
sub_8093C04: @ 8093C04
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093C24
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093C04

	thumb_func_start sub_8093C24
sub_8093C24: @ 8093C24
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093C36
	movs r0, 0
	b _08093C3C
_08093C36:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093C3C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093C24

	thumb_func_start sub_8093C44
sub_8093C44: @ 8093C44
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x5
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093C64
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093C44

	thumb_func_start sub_8093C64
sub_8093C64: @ 8093C64
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093C76
	movs r0, 0
	b _08093C7C
_08093C76:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093C7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093C64

	thumb_func_start sub_8093C84
sub_8093C84: @ 8093C84
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x6
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093CA4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093C84

	thumb_func_start sub_8093CA4
sub_8093CA4: @ 8093CA4
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093CB6
	movs r0, 0
	b _08093CBC
_08093CB6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093CBC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093CA4

	thumb_func_start sub_8093CC4
@ bool8 sub_8093CC4(struct npc_state *fieldObject, struct obj *object)
sub_8093CC4: @ 8093CC4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093CE4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093CC4

	thumb_func_start sub_8093CE4
@ bool8 sub_8093CE4(struct npc_state *fieldObject, struct obj *object)
sub_8093CE4: @ 8093CE4
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093CF6
	movs r0, 0
	b _08093CFC
_08093CF6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093CFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093CE4

	thumb_func_start sub_8093D04
sub_8093D04: @ 8093D04
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093D24
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D04

	thumb_func_start sub_8093D24
sub_8093D24: @ 8093D24
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093D36
	movs r0, 0
	b _08093D3C
_08093D36:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093D3C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D24

	thumb_func_start sub_8093D44
sub_8093D44: @ 8093D44
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093D64
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D44

	thumb_func_start sub_8093D64
sub_8093D64: @ 8093D64
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093D76
	movs r0, 0
	b _08093D7C
_08093D76:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093D7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D64

	thumb_func_start sub_8093D84
sub_8093D84: @ 8093D84
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8093B60
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093DA4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D84

	thumb_func_start sub_8093DA4
sub_8093DA4: @ 8093DA4
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08093DB6
	movs r0, 0
	b _08093DBC
_08093DB6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093DBC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DA4

	thumb_func_start sub_8093DC4
sub_8093DC4: @ 8093DC4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x7
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093DE4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DC4

	thumb_func_start sub_8093DE4
@ bool8 sub_8093DE4(struct npc_state *fieldObject, struct obj *object)
sub_8093DE4: @ 8093DE4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093DF6
	movs r0, 0
	b _08093DFC
_08093DF6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093DFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DE4

	thumb_func_start sub_8093E04
sub_8093E04: @ 8093E04
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093E24
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093E04

	thumb_func_start sub_8093E24
sub_8093E24: @ 8093E24
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093E36
	movs r0, 0
	b _08093E3C
_08093E36:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093E3C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093E24

	thumb_func_start sub_8093E44
sub_8093E44: @ 8093E44
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x5
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093E64
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093E44

	thumb_func_start sub_8093E64
sub_8093E64: @ 8093E64
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093E76
	movs r0, 0
	b _08093E7C
_08093E76:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093E7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093E64

	thumb_func_start sub_8093E84
sub_8093E84: @ 8093E84
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x6
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093EA4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093E84

	thumb_func_start sub_8093EA4
sub_8093EA4: @ 8093EA4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093EB6
	movs r0, 0
	b _08093EBC
_08093EB6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093EBC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093EA4

	thumb_func_start sub_8093EC4
sub_8093EC4: @ 8093EC4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093EE4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093EC4

	thumb_func_start sub_8093EE4
sub_8093EE4: @ 8093EE4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093EF6
	movs r0, 0
	b _08093EFC
_08093EF6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093EFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093EE4

	thumb_func_start sub_8093F04
sub_8093F04: @ 8093F04
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093F24
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093F04

	thumb_func_start sub_8093F24
sub_8093F24: @ 8093F24
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093F36
	movs r0, 0
	b _08093F3C
_08093F36:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093F3C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093F24

	thumb_func_start sub_8093F44
sub_8093F44: @ 8093F44
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093F64
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093F44

	thumb_func_start sub_8093F64
sub_8093F64: @ 8093F64
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093F76
	movs r0, 0
	b _08093F7C
_08093F76:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093F7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093F64

	thumb_func_start sub_8093F84
sub_8093F84: @ 8093F84
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093FA4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8093F84

	thumb_func_start sub_8093FA4
sub_8093FA4: @ 8093FA4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08093FB6
	movs r0, 0
	b _08093FBC
_08093FB6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08093FBC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093FA4

	thumb_func_start sub_8093FC4
sub_8093FC4: @ 8093FC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r0, 0
	mov r10, r1
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x30]
	lsls r4, 24
	lsrs r4, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gUnknown_0850DFBC
	add r0, sp, 0x4
	movs r2, 0x6
	bl memcpy
	add r5, sp, 0xC
	movs r0, 0
	strh r0, [r5]
	mov r6, sp
	adds r6, 0xE
	strh r0, [r6]
	adds r0, r7, 0
	adds r1, r4, 0
	bl FieldObjectSetDirection
	mov r1, r8
	lsls r0, r1, 1
	add r0, sp
	adds r0, 0x4
	movs r1, 0
	ldrsh r3, [r0, r1]
	str r3, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8092F88
	ldrh r1, [r5]
	ldrh r0, [r7, 0x10]
	adds r1, r0
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r6]
	ldrh r0, [r7, 0x12]
	adds r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r7, 0
	bl npc_coords_shift
	mov r0, r10
	adds r1, r4, 0
	mov r2, r8
	mov r3, r9
	bl sub_809783C
	movs r0, 0x1
	mov r1, r10
	strh r0, [r1, 0x32]
	movs r0, 0x2C
	add r10, r0
	mov r0, r10
	ldrb r1, [r0]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	mov r1, r10
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r7]
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8093FC4

	thumb_func_start maybe_shadow_1
maybe_shadow_1: @ 8094080
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [sp, 0x10]
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	adds r0, r4, 0
	bl sub_8093FC4
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl get_go_image_anim_num
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_apply_anim_looping
	adds r0, r4, 0
	bl DoShadowFieldEffect
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end maybe_shadow_1

	thumb_func_start sub_80940C4
@ int sub_80940C4(int a1, int a2, int a3)
sub_80940C4: @ 80940C4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	ldr r1, =gUnknown_0850DFC2
	add r0, sp, 0x4
	movs r2, 0x6
	bl memcpy
	adds r0, r7, 0
	bl _call_via_r4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bne _08094154
	movs r1, 0x36
	ldrsh r0, [r7, r1]
	lsls r0, 1
	add r0, sp
	adds r0, 0x4
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _08094154
	add r4, sp, 0xC
	movs r0, 0
	strh r0, [r4]
	mov r5, sp
	adds r5, 0xE
	strh r0, [r5]
	ldrb r0, [r6, 0x18]
	lsrs r0, 4
	movs r2, 0x36
	ldrsh r1, [r7, r2]
	lsls r1, 1
	add r1, sp
	adds r1, 0x4
	movs r2, 0
	ldrsh r3, [r1, r2]
	str r3, [sp]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8092F88
	ldrh r1, [r4]
	ldrh r0, [r6, 0x10]
	adds r1, r0
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r5]
	ldrh r0, [r6, 0x12]
	adds r2, r0
	lsls r2, 16
	asrs r2, 16
	adds r0, r6, 0
	bl npc_coords_shift
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r6]
	b _08094178
	.pool
_08094154:
	mov r1, r8
	cmp r1, 0xFF
	bne _08094178
	adds r0, r6, 0
	bl npc_coords_shift_still
	ldrb r0, [r6]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r6]
	adds r2, r7, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
_08094178:
	mov r0, r8
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80940C4

	thumb_func_start sub_8094188
sub_8094188: @ 8094188
	push {lr}
	ldr r2, =sub_809785C
	bl sub_80940C4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8094188

	thumb_func_start sub_809419C
sub_809419C: @ 809419C
	push {lr}
	ldr r2, =sub_80978E4
	bl sub_80940C4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809419C

	thumb_func_start sub_80941B0
sub_80941B0: @ 80941B0
	push {lr}
	bl sub_8094188
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080941C2
	movs r0, 0
	b _080941C4
_080941C2:
	movs r0, 0x1
_080941C4:
	pop {r1}
	bx r1
	thumb_func_end sub_80941B0

	thumb_func_start sub_80941C8
sub_80941C8: @ 80941C8
	push {lr}
	bl sub_809419C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080941DA
	movs r0, 0
	b _080941DC
_080941DA:
	movs r0, 0x1
_080941DC:
	pop {r1}
	bx r1
	thumb_func_end sub_80941C8

	thumb_func_start sub_80941E0
sub_80941E0: @ 80941E0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8094188
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080941FA
	cmp r0, 0xFF
	bne _08094226
	movs r0, 0x1
	b _08094228
_080941FA:
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetOppositeDirection
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetDirection
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl get_go_image_anim_num
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl obj_npc_animation_step
_08094226:
	movs r0, 0
_08094228:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80941E0

	thumb_func_start sub_8094230
sub_8094230: @ 8094230
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809425C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094230

	thumb_func_start sub_809425C
sub_809425C: @ 809425C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08094270
	movs r0, 0
	b _08094280
_08094270:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08094280:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809425C

	thumb_func_start sub_8094288
sub_8094288: @ 8094288
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80942B4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094288

	thumb_func_start sub_80942B4
sub_80942B4: @ 80942B4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _080942C8
	movs r0, 0
	b _080942D8
_080942C8:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080942D8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80942B4

	thumb_func_start sub_80942E0
sub_80942E0: @ 80942E0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0x2
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809430C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80942E0

	thumb_func_start sub_809430C
sub_809430C: @ 809430C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08094320
	movs r0, 0
	b _08094330
_08094320:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08094330:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809430C

	thumb_func_start sub_8094338
sub_8094338: @ 8094338
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0x2
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094364
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094338

	thumb_func_start sub_8094364
sub_8094364: @ 8094364
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08094378
	movs r0, 0
	b _08094388
_08094378:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08094388:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094364

	thumb_func_start sub_8094390
sub_8094390: @ 8094390
	movs r2, 0x1
	strh r2, [r0, 0x32]
	strh r1, [r0, 0x34]
	bx lr
	thumb_func_end sub_8094390

	thumb_func_start sub_8094398
sub_8094398: @ 8094398
	push {lr}
	ldrh r0, [r1, 0x34]
	subs r0, 0x1
	strh r0, [r1, 0x34]
	lsls r0, 16
	cmp r0, 0
	beq _080943AA
	movs r0, 0
	b _080943B0
_080943AA:
	movs r0, 0x2
	strh r0, [r1, 0x32]
	movs r0, 0x1
_080943B0:
	pop {r1}
	bx r1
	thumb_func_end sub_8094398

	thumb_func_start sub_80943B4
sub_80943B4: @ 80943B4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8094390
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8094398
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80943B4

	thumb_func_start sub_80943D4
sub_80943D4: @ 80943D4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_8094390
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8094398
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80943D4

	thumb_func_start sub_80943F4
sub_80943F4: @ 80943F4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_8094390
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8094398
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80943F4

	thumb_func_start sub_8094414
sub_8094414: @ 8094414
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_8094390
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8094398
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094414

	thumb_func_start sub_8094434
sub_8094434: @ 8094434
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x10
	bl sub_8094390
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8094398
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094434

	thumb_func_start sub_8094454
sub_8094454: @ 8094454
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094474
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094454

	thumb_func_start sub_8094474
sub_8094474: @ 8094474
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094486
	movs r0, 0
	b _0809448C
_08094486:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_0809448C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094474

	thumb_func_start sub_8094494
sub_8094494: @ 8094494
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80944B4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094494

	thumb_func_start sub_80944B4
sub_80944B4: @ 80944B4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080944C6
	movs r0, 0
	b _080944CC
_080944C6:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080944CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80944B4

	thumb_func_start sub_80944D4
sub_80944D4: @ 80944D4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80944F4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80944D4

	thumb_func_start sub_80944F4
sub_80944F4: @ 80944F4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094506
	movs r0, 0
	b _0809450C
_08094506:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_0809450C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80944F4

	thumb_func_start sub_8094514
sub_8094514: @ 8094514
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x1
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094534
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094514

	thumb_func_start sub_8094534
sub_8094534: @ 8094534
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094546
	movs r0, 0
	b _0809454C
_08094546:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_0809454C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094534

	thumb_func_start sub_8094554
sub_8094554: @ 8094554
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r6, r1, 0
	adds r1, r2, 0
	adds r4, r3, 0
	ldr r5, [sp, 0x14]
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	bl FieldObjectSetDirection
	mov r0, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl npc_apply_anim_looping
	adds r2, r6, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strh r0, [r6, 0x32]
	strh r5, [r6, 0x34]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8094554

	thumb_func_start sub_809459C
@ signed int sub_809459C(int a1, obj *a2)
sub_809459C: @ 809459C
	push {lr}
	ldrh r0, [r1, 0x34]
	subs r0, 0x1
	strh r0, [r1, 0x34]
	lsls r0, 16
	cmp r0, 0
	beq _080945AE
	movs r0, 0
	b _080945C0
_080945AE:
	movs r0, 0x2
	strh r0, [r1, 0x32]
	adds r2, r1, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
_080945C0:
	pop {r1}
	bx r1
	thumb_func_end sub_809459C

	thumb_func_start sub_80945C4
@ int sub_80945C4(int a1, obj *a2)
sub_80945C4: @ 80945C4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r1, [r4, 0x34]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080945EE
	adds r3, r4, 0
	adds r3, 0x2C
	ldrb r2, [r3]
	lsls r1, r2, 26
	lsrs r1, 26
	adds r1, 0x1
	movs r0, 0x3F
	ands r1, r0
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080945EE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80945C4

	thumb_func_start sub_8094600
sub_8094600: @ 8094600
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x20
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80945C4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094600

	thumb_func_start sub_8094638
sub_8094638: @ 8094638
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x20
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80945C4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094638

	thumb_func_start sub_8094670
sub_8094670: @ 8094670
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x20
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80945C4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094670

	thumb_func_start sub_80946A8
sub_80946A8: @ 80946A8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x20
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80945C4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80946A8

	thumb_func_start sub_80946E0
sub_80946E0: @ 80946E0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x10
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80946E0

	thumb_func_start sub_8094718
sub_8094718: @ 8094718
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x10
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094718

	thumb_func_start sub_8094750
sub_8094750: @ 8094750
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x10
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094750

	thumb_func_start sub_8094788
sub_8094788: @ 8094788
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl get_go_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x10
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094788

	thumb_func_start sub_80947C0
sub_80947C0: @ 80947C0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl get_go_fast_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80947C0

	thumb_func_start sub_80947F8
sub_80947F8: @ 80947F8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl get_go_fast_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80947F8

	thumb_func_start sub_8094830
sub_8094830: @ 8094830
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl get_go_fast_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094830

	thumb_func_start sub_8094868
sub_8094868: @ 8094868
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl get_go_fast_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094868

	thumb_func_start sub_80948A0
sub_80948A0: @ 80948A0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl get_go_faster_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80948A0

	thumb_func_start sub_80948D8
sub_80948D8: @ 80948D8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl get_go_faster_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80948D8

	thumb_func_start sub_8094910
sub_8094910: @ 8094910
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl get_go_faster_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094910

	thumb_func_start sub_8094948
sub_8094948: @ 8094948
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl get_go_faster_image_anim_num
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094948

	thumb_func_start sub_8094980
sub_8094980: @ 8094980
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x2
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80949A0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094980

	thumb_func_start sub_80949A0
sub_80949A0: @ 80949A0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080949B2
	movs r0, 0
	b _080949B8
_080949B2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080949B8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80949A0

	thumb_func_start sub_80949C0
sub_80949C0: @ 80949C0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80949E0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80949C0

	thumb_func_start sub_80949E0
sub_80949E0: @ 80949E0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080949F2
	movs r0, 0
	b _080949F8
_080949F2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080949F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80949E0

	thumb_func_start sub_8094A00
sub_8094A00: @ 8094A00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x2
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094A20
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094A00

	thumb_func_start sub_8094A20
sub_8094A20: @ 8094A20
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094A32
	movs r0, 0
	b _08094A38
_08094A32:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094A38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094A20

	thumb_func_start sub_8094A40
sub_8094A40: @ 8094A40
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x2
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094A60
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094A40

	thumb_func_start sub_8094A60
sub_8094A60: @ 8094A60
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094A72
	movs r0, 0
	b _08094A78
_08094A72:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094A78:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094A60

	thumb_func_start sub_8094A80
sub_8094A80: @ 8094A80
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x3
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094AA0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094A80

	thumb_func_start sub_8094AA0
sub_8094AA0: @ 8094AA0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094AB2
	movs r0, 0
	b _08094AB8
_08094AB2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094AB8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094AA0

	thumb_func_start sub_8094AC0
sub_8094AC0: @ 8094AC0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x3
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094AE0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094AC0

	thumb_func_start sub_8094AE0
sub_8094AE0: @ 8094AE0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094AF2
	movs r0, 0
	b _08094AF8
_08094AF2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094AF8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094AE0

	thumb_func_start sub_8094B00
sub_8094B00: @ 8094B00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x3
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094B20
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094B00

	thumb_func_start sub_8094B20
sub_8094B20: @ 8094B20
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094B32
	movs r0, 0
	b _08094B38
_08094B32:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094B38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094B20

	thumb_func_start sub_8094B40
sub_8094B40: @ 8094B40
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x3
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094B60
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094B40

	thumb_func_start sub_8094B60
sub_8094B60: @ 8094B60
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094B72
	movs r0, 0
	b _08094B78
_08094B72:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094B78:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094B60

	thumb_func_start sub_8094B80
sub_8094B80: @ 8094B80
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x4
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094BA0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094B80

	thumb_func_start sub_8094BA0
sub_8094BA0: @ 8094BA0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094BB2
	movs r0, 0
	b _08094BB8
_08094BB2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094BB8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094BA0

	thumb_func_start sub_8094BC0
sub_8094BC0: @ 8094BC0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x4
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094BE0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094BC0

	thumb_func_start sub_8094BE0
sub_8094BE0: @ 8094BE0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094BF2
	movs r0, 0
	b _08094BF8
_08094BF2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094BF8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094BE0

	thumb_func_start sub_8094C00
sub_8094C00: @ 8094C00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x4
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094C20
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094C00

	thumb_func_start sub_8094C20
sub_8094C20: @ 8094C20
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094C32
	movs r0, 0
	b _08094C38
_08094C32:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094C38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094C20

	thumb_func_start sub_8094C40
sub_8094C40: @ 8094C40
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x4
	bl do_go_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094C60
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094C40

	thumb_func_start sub_8094C60
sub_8094C60: @ 8094C60
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094C72
	movs r0, 0
	b _08094C78
_08094C72:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094C78:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094C60

	thumb_func_start do_run_south_anim
@ bool8 do_run_south_anim(struct npc_state *fieldObject, struct obj *object)
do_run_south_anim: @ 8094C80
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl do_run_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094CA0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end do_run_south_anim

	thumb_func_start sub_8094CA0
@ bool8 sub_8094CA0(struct npc_state *fieldObject, struct obj *object)
sub_8094CA0: @ 8094CA0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094CB2
	movs r0, 0
	b _08094CB8
_08094CB2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094CB8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094CA0

	thumb_func_start do_run_north_anim
do_run_north_anim: @ 8094CC0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	bl do_run_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094CE0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end do_run_north_anim

	thumb_func_start sub_8094CE0
sub_8094CE0: @ 8094CE0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094CF2
	movs r0, 0
	b _08094CF8
_08094CF2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094CF8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094CE0

	thumb_func_start do_run_west_anim
do_run_west_anim: @ 8094D00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	bl do_run_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094D20
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end do_run_west_anim

	thumb_func_start sub_8094D20
sub_8094D20: @ 8094D20
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094D32
	movs r0, 0
	b _08094D38
_08094D32:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094D38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094D20

	thumb_func_start do_run_east_anim
do_run_east_anim: @ 8094D40
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl do_run_anim
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094D60
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end do_run_east_anim

	thumb_func_start sub_8094D60
sub_8094D60: @ 8094D60
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08094D72
	movs r0, 0
	b _08094D78
_08094D72:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094D78:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094D60

	thumb_func_start npc_set_direction_and_anim__an_proceed
npc_set_direction_and_anim__an_proceed: @ 8094D80
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r1, r3, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	movs r2, 0
	bl obj_anim_image_set_and_seek
	adds r0, r6, 0
	adds r1, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end npc_set_direction_and_anim__an_proceed

	thumb_func_start sub_8094DAC
sub_8094DAC: @ 8094DAC
	push {lr}
	ldrb r2, [r0, 0x18]
	lsrs r2, 4
	adds r3, r1, 0
	adds r3, 0x2A
	ldrb r3, [r3]
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8094DAC

	thumb_func_start sub_8094DC4
sub_8094DC4: @ 8094DC4
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_80979BC
	lsls r0, 24
	cmp r0, 0
	bne _08094DD8
	movs r0, 0
	b _08094DDE
_08094DD8:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08094DDE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094DC4

	thumb_func_start sub_8094DE4
sub_8094DE4: @ 8094DE4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8093FC4
	adds r0, r4, 0
	bl sub_80929AC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8094DE4

	thumb_func_start sub_8094E18
sub_8094E18: @ 8094E18
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8094DE4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094E38
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094E18

	thumb_func_start sub_8094E38
sub_8094E38: @ 8094E38
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941C8
	lsls r0, 24
	cmp r0, 0
	bne _08094E4C
	movs r0, 0
	b _08094E5A
_08094E4C:
	movs r0, 0x2
	strh r0, [r5, 0x32]
	ldrb r1, [r4]
	subs r0, 0x23
	ands r0, r1
	strb r0, [r4]
	movs r0, 0x1
_08094E5A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094E38

	thumb_func_start sub_8094E60
sub_8094E60: @ 8094E60
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	bl sub_8094DE4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094E80
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094E60

	thumb_func_start sub_8094E80
sub_8094E80: @ 8094E80
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941C8
	lsls r0, 24
	cmp r0, 0
	bne _08094E94
	movs r0, 0
	b _08094EA2
_08094E94:
	movs r0, 0x2
	strh r0, [r5, 0x32]
	ldrb r1, [r4]
	subs r0, 0x23
	ands r0, r1
	strb r0, [r4]
	movs r0, 0x1
_08094EA2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094E80

	thumb_func_start sub_8094EA8
sub_8094EA8: @ 8094EA8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	bl sub_8094DE4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094EC8
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094EA8

	thumb_func_start sub_8094EC8
sub_8094EC8: @ 8094EC8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941C8
	lsls r0, 24
	cmp r0, 0
	bne _08094EDC
	movs r0, 0
	b _08094EEA
_08094EDC:
	movs r0, 0x2
	strh r0, [r5, 0x32]
	ldrb r1, [r4]
	subs r0, 0x23
	ands r0, r1
	strb r0, [r4]
	movs r0, 0x1
_08094EEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094EC8

	thumb_func_start sub_8094EF0
sub_8094EF0: @ 8094EF0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8094DE4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8094F10
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094EF0

	thumb_func_start sub_8094F10
sub_8094F10: @ 8094F10
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941C8
	lsls r0, 24
	cmp r0, 0
	bne _08094F24
	movs r0, 0
	b _08094F32
_08094F24:
	movs r0, 0x2
	strh r0, [r5, 0x32]
	ldrb r1, [r4]
	subs r0, 0x23
	ands r0, r1
	strb r0, [r4]
	movs r0, 0x1
_08094F32:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8094F10

	thumb_func_start sub_8094F38
sub_8094F38: @ 8094F38
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08094F82
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	ldr r4, =gMapObjects
	mov r2, sp
	ldrb r2, [r2]
	lsls r3, r2, 3
	adds r3, r2
	lsls r3, 2
	adds r3, r4
	movs r4, 0x10
	ldrsh r2, [r3, r4]
	movs r4, 0x12
	ldrsh r3, [r3, r4]
	bl sub_8092AF8
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl an_look_any
_08094F82:
	movs r0, 0x1
	strh r0, [r6, 0x32]
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8094F38

	thumb_func_start sub_8094F94
sub_8094F94: @ 8094F94
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08094FE6
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	ldr r4, =gMapObjects
	mov r2, sp
	ldrb r2, [r2]
	lsls r3, r2, 3
	adds r3, r2
	lsls r3, 2
	adds r3, r4
	movs r4, 0x10
	ldrsh r2, [r3, r4]
	movs r4, 0x12
	ldrsh r3, [r3, r4]
	bl sub_8092AF8
	lsls r0, 24
	lsrs r0, 24
	bl GetOppositeDirection
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl an_look_any
_08094FE6:
	movs r0, 0x1
	strh r0, [r6, 0x32]
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8094F94

	thumb_func_start sub_8094FF8
sub_8094FF8: @ 8094FF8
	ldrb r2, [r0, 0x1]
	movs r3, 0x2
	orrs r2, r3
	strb r2, [r0, 0x1]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_8094FF8

	thumb_func_start sub_8095008
sub_8095008: @ 8095008
	ldrb r3, [r0, 0x1]
	movs r2, 0x3
	negs r2, r2
	ands r2, r3
	strb r2, [r0, 0x1]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_8095008

	thumb_func_start sub_8095018
sub_8095018: @ 8095018
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095044
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095018

	thumb_func_start sub_8095044
sub_8095044: @ 8095044
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095058
	movs r0, 0
	b _08095068
_08095058:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095068:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095044

	thumb_func_start sub_8095070
sub_8095070: @ 8095070
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x1
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809509C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095070

	thumb_func_start sub_809509C
sub_809509C: @ 809509C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _080950B0
	movs r0, 0
	b _080950C0
_080950B0:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080950C0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809509C

	thumb_func_start sub_80950C8
sub_80950C8: @ 80950C8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0x1
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80950F4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80950C8

	thumb_func_start sub_80950F4
sub_80950F4: @ 80950F4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095108
	movs r0, 0
	b _08095118
_08095108:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095118:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80950F4

	thumb_func_start sub_8095120
sub_8095120: @ 8095120
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0x1
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809514C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095120

	thumb_func_start sub_809514C
sub_809514C: @ 809514C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095160
	movs r0, 0
	b _08095170
_08095160:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095170:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809514C

	thumb_func_start sub_8095178
sub_8095178: @ 8095178
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80951A4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095178

	thumb_func_start sub_80951A4
sub_80951A4: @ 80951A4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _080951B8
	movs r0, 0
	b _080951C8
_080951B8:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080951C8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80951A4

	thumb_func_start sub_80951D0
sub_80951D0: @ 80951D0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80951FC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80951D0

	thumb_func_start sub_80951FC
sub_80951FC: @ 80951FC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095210
	movs r0, 0
	b _08095220
_08095210:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095220:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80951FC

	thumb_func_start sub_8095228
sub_8095228: @ 8095228
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095254
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095228

	thumb_func_start sub_8095254
sub_8095254: @ 8095254
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095268
	movs r0, 0
	b _08095278
_08095268:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095278:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095254

	thumb_func_start sub_8095280
sub_8095280: @ 8095280
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80952AC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095280

	thumb_func_start sub_80952AC
sub_80952AC: @ 80952AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _080952C0
	movs r0, 0
	b _080952D0
_080952C0:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080952D0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80952AC

	thumb_func_start sub_80952D8
sub_80952D8: @ 80952D8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095304
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80952D8

	thumb_func_start sub_8095304
sub_8095304: @ 8095304
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941E0
	lsls r0, 24
	cmp r0, 0
	bne _08095318
	movs r0, 0
	b _08095328
_08095318:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095328:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095304

	thumb_func_start sub_8095330
sub_8095330: @ 8095330
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809535C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095330

	thumb_func_start sub_809535C
sub_809535C: @ 809535C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941E0
	lsls r0, 24
	cmp r0, 0
	bne _08095370
	movs r0, 0
	b _08095380
_08095370:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095380:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809535C

	thumb_func_start sub_8095388
sub_8095388: @ 8095388
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80953B4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095388

	thumb_func_start sub_80953B4
sub_80953B4: @ 80953B4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941E0
	lsls r0, 24
	cmp r0, 0
	bne _080953C8
	movs r0, 0
	b _080953D8
_080953C8:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_080953D8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80953B4

	thumb_func_start sub_80953E0
sub_80953E0: @ 80953E0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0
	bl maybe_shadow_1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809540C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80953E0

	thumb_func_start sub_809540C
sub_809540C: @ 809540C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941E0
	lsls r0, 24
	cmp r0, 0
	bne _08095420
	movs r0, 0
	b _08095430
_08095420:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095430:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809540C

	thumb_func_start sub_8095438
sub_8095438: @ 8095438
	push {lr}
	ldr r3, =gUnknown_085055CD
	ldrb r2, [r0, 0x6]
	adds r2, r3
	ldrb r2, [r2]
	bl an_look_any
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8095438

	thumb_func_start sub_8095450
sub_8095450: @ 8095450
	push {lr}
	movs r2, 0x1
	movs r3, 0x14
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8095450

	thumb_func_start sub_8095460
sub_8095460: @ 8095460
	ldrb r3, [r0, 0x3]
	movs r2, 0x3
	negs r2, r2
	ands r2, r3
	strb r2, [r0, 0x3]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_8095460

	thumb_func_start sub_8095470
sub_8095470: @ 8095470
	ldrb r2, [r0, 0x3]
	movs r3, 0x2
	orrs r2, r3
	strb r2, [r0, 0x3]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_8095470

	thumb_func_start sub_8095480
sub_8095480: @ 8095480
	ldrb r2, [r0, 0x1]
	movs r3, 0x10
	orrs r2, r3
	strb r2, [r0, 0x1]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_8095480

	thumb_func_start sub_8095490
@ int sub_8095490(npc_state *npcState, int a2)
sub_8095490: @ 8095490
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldrb r1, [r0, 0xC]
	lsls r1, 25
	lsrs r1, 31
	lsls r1, 4
	ldrb r2, [r4, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1
	strh r0, [r5, 0x32]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095490

	thumb_func_start sub_80954BC
sub_80954BC: @ 80954BC
	ldrb r2, [r0, 0x1]
	movs r3, 0x20
	orrs r2, r3
	strb r2, [r0, 0x1]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_80954BC

	thumb_func_start sub_80954CC
sub_80954CC: @ 80954CC
	ldrb r3, [r0, 0x1]
	movs r2, 0x21
	negs r2, r2
	ands r2, r3
	strb r2, [r0, 0x1]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_80954CC

	thumb_func_start do_exclamation_mark_bubble_1
do_exclamation_mark_bubble_1: @ 80954DC
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, =gFieldEffectSpawnParams
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0
	bl FieldEffectStart
	movs r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end do_exclamation_mark_bubble_1

	thumb_func_start do_exclamation_mark_bubble_2
do_exclamation_mark_bubble_2: @ 8095500
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, =gFieldEffectSpawnParams
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0x21
	bl FieldEffectStart
	movs r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end do_exclamation_mark_bubble_2

	thumb_func_start do_heart_bubble
do_heart_bubble: @ 8095524
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, =gFieldEffectSpawnParams
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0x2E
	bl FieldEffectStart
	movs r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end do_heart_bubble

	thumb_func_start sub_8095548
sub_8095548: @ 8095548
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x6]
	cmp r0, 0x3F
	bne _0809555E
	adds r0, r4, 0
	bl sub_80B4578
	movs r0, 0
	b _08095586
_0809555E:
	subs r0, 0x39
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08095580
	adds r0, r4, 0
	bl sub_8155D78
	movs r0, 0x1
	strh r0, [r5, 0x32]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809558C
	lsls r0, 24
	lsrs r0, 24
	b _08095586
_08095580:
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095586:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095548

	thumb_func_start sub_809558C
sub_809558C: @ 809558C
	push {r4,lr}
	adds r4, r1, 0
	bl sub_8155DA0
	lsls r0, 24
	cmp r0, 0
	bne _0809559E
	movs r0, 0
	b _080955A4
_0809559E:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080955A4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809558C

	thumb_func_start sub_80955AC
sub_80955AC: @ 80955AC
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl obj_anim_image_set_and_seek
	movs r0, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80955AC

	thumb_func_start sub_80955C8
sub_80955C8: @ 80955C8
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_80979BC
	lsls r0, 24
	cmp r0, 0
	beq _080955E4
	adds r0, r4, 0
	movs r1, 0x20
	bl SetFieldObjectStepTimer
	movs r0, 0x2
	strh r0, [r4, 0x32]
_080955E4:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80955C8

	thumb_func_start sub_80955EC
sub_80955EC: @ 80955EC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r2, [r4, 0x1]
	lsls r1, r2, 26
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 5
	subs r0, 0x22
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl RunFieldObjectStepTimer
	lsls r0, 24
	cmp r0, 0
	beq _0809561E
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x3
	strh r0, [r5, 0x32]
_0809561E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80955EC

	thumb_func_start sub_8095628
sub_8095628: @ 8095628
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl obj_anim_image_set_and_seek
	movs r0, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095628

	thumb_func_start sub_8095644
sub_8095644: @ 8095644
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_80979BC
	lsls r0, 24
	cmp r0, 0
	beq _08095660
	adds r0, r4, 0
	movs r1, 0x20
	bl SetFieldObjectStepTimer
	movs r0, 0x2
	strh r0, [r4, 0x32]
_08095660:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095644

	thumb_func_start sub_8095668
sub_8095668: @ 8095668
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r2, [r4, 0x1]
	lsls r1, r2, 26
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 5
	subs r0, 0x22
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl RunFieldObjectStepTimer
	lsls r0, 24
	cmp r0, 0
	beq _0809569A
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x3
	strh r0, [r5, 0x32]
_0809569A:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095668

	thumb_func_start sub_80956A4
sub_80956A4: @ 80956A4
	ldrb r2, [r0, 0x3]
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r0, 0x3]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_80956A4

	thumb_func_start sub_80956B4
sub_80956B4: @ 80956B4
	ldrb r3, [r0, 0x3]
	movs r2, 0x5
	negs r2, r2
	ands r2, r3
	strb r2, [r0, 0x3]
	movs r0, 0x1
	strh r0, [r1, 0x32]
	bx lr
	thumb_func_end sub_80956B4

	thumb_func_start sub_80956C4
sub_80956C4: @ 80956C4
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r4, 0x42
	ldrb r1, [r4]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r4]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80956C4

	thumb_func_start sub_80956F4
sub_80956F4: @ 80956F4
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r0, [r4, 0x1]
	movs r1, 0x4
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x1]
	lsrs r1, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	movs r3, 0
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80956F4

	thumb_func_start sub_8095724
sub_8095724: @ 8095724
	ldrb r1, [r0, 0x3]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x3]
	movs r0, 0x1
	bx lr
	thumb_func_end sub_8095724

	thumb_func_start sub_8095730
sub_8095730: @ 8095730
	ldrb r2, [r0, 0x3]
	movs r1, 0x9
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x3]
	movs r0, 0x1
	bx lr
	thumb_func_end sub_8095730

	thumb_func_start sub_8095740
sub_8095740: @ 8095740
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8093B60
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnimIfDifferent
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095774
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095740

	thumb_func_start sub_8095774
sub_8095774: @ 8095774
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _08095786
	movs r0, 0
	b _08095798
_08095786:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08095798:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095774

	thumb_func_start sub_80957A0
sub_80957A0: @ 80957A0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8093B60
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80957D4
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80957A0

	thumb_func_start sub_80957D4
sub_80957D4: @ 80957D4
	push {r4,lr}
	adds r4, r1, 0
	bl an_walk_any_2
	lsls r0, 24
	cmp r0, 0
	bne _080957E6
	movs r0, 0
	b _080957F8
_080957E6:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080957F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80957D4

	thumb_func_start sub_8095800
sub_8095800: @ 8095800
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl do_go_anim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x2
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095834
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095800

	thumb_func_start sub_8095834
sub_8095834: @ 8095834
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08095846
	movs r0, 0
	b _08095858
_08095846:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08095858:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095834

	thumb_func_start sub_8095860
sub_8095860: @ 8095860
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x4
	movs r3, 0x1
	bl do_go_anim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x3
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095894
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095860

	thumb_func_start sub_8095894
sub_8095894: @ 8095894
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080958A6
	movs r0, 0
	b _080958B8
_080958A6:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080958B8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095894

	thumb_func_start sub_80958C0
sub_80958C0: @ 80958C0
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	adds r1, r4, 0
	bl FieldObjectSetDirection
	adds r0, r5, 0
	bl npc_coords_shift_still
	adds r0, r4, 0
	bl sub_80929FC
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl obj_npc_animation_step
	adds r2, r6, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strh r0, [r6, 0x32]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80958C0

	thumb_func_start sub_8095900
sub_8095900: @ 8095900
	push {lr}
	movs r2, 0x1
	bl sub_80958C0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8095900

	thumb_func_start sub_8095910
sub_8095910: @ 8095910
	push {lr}
	movs r2, 0x2
	bl sub_80958C0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8095910

	thumb_func_start sub_8095920
sub_8095920: @ 8095920
	push {lr}
	movs r2, 0x3
	bl sub_80958C0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8095920

	thumb_func_start sub_8095930
sub_8095930: @ 8095930
	push {lr}
	movs r2, 0x4
	bl sub_80958C0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8095930

	thumb_func_start sub_8095940
sub_8095940: @ 8095940
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl sub_80929BC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095940

	thumb_func_start sub_8095964
sub_8095964: @ 8095964
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl sub_80929BC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095964

	thumb_func_start sub_8095988
sub_8095988: @ 8095988
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl sub_80929BC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095988

	thumb_func_start sub_80959AC
sub_80959AC: @ 80959AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl sub_80929BC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80959AC

	thumb_func_start sub_80959D0
sub_80959D0: @ 80959D0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl sub_80929DC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80959D0

	thumb_func_start sub_80959F4
sub_80959F4: @ 80959F4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl sub_80929DC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80959F4

	thumb_func_start sub_8095A18
sub_8095A18: @ 8095A18
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl sub_80929DC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095A18

	thumb_func_start sub_8095A3C
sub_8095A3C: @ 8095A3C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl sub_80929DC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095A3C

	thumb_func_start sub_8095A60
sub_8095A60: @ 8095A60
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl sub_80929EC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095A60

	thumb_func_start sub_8095A84
sub_8095A84: @ 8095A84
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl sub_80929EC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095A84

	thumb_func_start sub_8095AA8
sub_8095AA8: @ 8095AA8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl sub_80929EC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095AA8

	thumb_func_start sub_8095ACC
sub_8095ACC: @ 8095ACC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl sub_80929EC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl npc_set_direction_and_anim__an_proceed
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095ACC

	thumb_func_start sub_8095AF0
sub_8095AF0: @ 8095AF0
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_8097750
	adds r4, 0x2C
	ldrb r1, [r4]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8095AF0

	thumb_func_start sub_8095B0C
sub_8095B0C: @ 8095B0C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_8097758
	lsls r0, 24
	cmp r0, 0
	bne _08095B22
	movs r0, 0
	b _08095B3E
_08095B22:
	adds r0, r4, 0
	bl npc_coords_shift_still
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
_08095B3E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B0C

	thumb_func_start sub_8095B44
sub_8095B44: @ 8095B44
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8095AF0
	movs r0, 0x1
	strh r0, [r4, 0x32]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095B64
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B44

	thumb_func_start sub_8095B64
sub_8095B64: @ 8095B64
	push {r4,lr}
	adds r4, r1, 0
	bl sub_8095B0C
	lsls r0, 24
	cmp r0, 0
	bne _08095B76
	movs r0, 0
	b _08095B7C
_08095B76:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08095B7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B64

	thumb_func_start sub_8095B84
sub_8095B84: @ 8095B84
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	ldr r0, [sp, 0x14]
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_8093FC4
	adds r0, r4, 0
	bl sub_80929BC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnimIfDifferent
	adds r0, r6, 0
	bl DoShadowFieldEffect
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8095B84

	thumb_func_start sub_8095BC8
sub_8095BC8: @ 8095BC8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095BF4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095BC8

	thumb_func_start sub_8095BF4
sub_8095BF4: @ 8095BF4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095C08
	movs r0, 0
	b _08095C18
_08095C08:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095C18:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095BF4

	thumb_func_start sub_8095C20
sub_8095C20: @ 8095C20
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095C4C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095C20

	thumb_func_start sub_8095C4C
sub_8095C4C: @ 8095C4C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095C60
	movs r0, 0
	b _08095C70
_08095C60:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095C70:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095C4C

	thumb_func_start sub_8095C78
sub_8095C78: @ 8095C78
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095CA4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095C78

	thumb_func_start sub_8095CA4
sub_8095CA4: @ 8095CA4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095CB8
	movs r0, 0
	b _08095CC8
_08095CB8:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095CC8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CA4

	thumb_func_start sub_8095CD0
sub_8095CD0: @ 8095CD0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095CFC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CD0

	thumb_func_start sub_8095CFC
sub_8095CFC: @ 8095CFC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095D10
	movs r0, 0
	b _08095D20
_08095D10:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095D20:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CFC

	thumb_func_start sub_8095D28
sub_8095D28: @ 8095D28
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095D54
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095D28

	thumb_func_start sub_8095D54
sub_8095D54: @ 8095D54
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095D68
	movs r0, 0
	b _08095D78
_08095D68:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095D78:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095D54

	thumb_func_start sub_8095D80
sub_8095D80: @ 8095D80
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095DAC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095D80

	thumb_func_start sub_8095DAC
sub_8095DAC: @ 8095DAC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095DC0
	movs r0, 0
	b _08095DD0
_08095DC0:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095DD0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095DAC

	thumb_func_start sub_8095DD8
sub_8095DD8: @ 8095DD8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095E04
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095DD8

	thumb_func_start sub_8095E04
sub_8095E04: @ 8095E04
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095E18
	movs r0, 0
	b _08095E28
_08095E18:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095E28:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E04

	thumb_func_start sub_8095E30
sub_8095E30: @ 8095E30
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0x1
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095E5C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E30

	thumb_func_start sub_8095E5C
sub_8095E5C: @ 8095E5C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095E70
	movs r0, 0
	b _08095E80
_08095E70:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095E80:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E5C

	thumb_func_start sub_8095E88
sub_8095E88: @ 8095E88
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095EB4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E88

	thumb_func_start sub_8095EB4
sub_8095EB4: @ 8095EB4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095EC8
	movs r0, 0
	b _08095ED8
_08095EC8:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095ED8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095EB4

	thumb_func_start sub_8095EE0
sub_8095EE0: @ 8095EE0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095F0C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095EE0

	thumb_func_start sub_8095F0C
sub_8095F0C: @ 8095F0C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095F20
	movs r0, 0
	b _08095F30
_08095F20:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095F30:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F0C

	thumb_func_start sub_8095F38
sub_8095F38: @ 8095F38
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x3
	movs r3, 0x2
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095F64
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F38

	thumb_func_start sub_8095F64
sub_8095F64: @ 8095F64
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095F78
	movs r0, 0
	b _08095F88
_08095F78:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095F88:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F64

	thumb_func_start sub_8095F90
sub_8095F90: @ 8095F90
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x4
	movs r3, 0x2
	bl sub_8095B84
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095FBC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F90

	thumb_func_start sub_8095FBC
sub_8095FBC: @ 8095FBC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80941B0
	lsls r0, 24
	cmp r0, 0
	bne _08095FD0
	movs r0, 0
	b _08095FE0
_08095FD0:
	ldrb r0, [r4, 0x2]
	movs r1, 0x41
	negs r1, r1
	ands r1, r0
	strb r1, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x32]
	movs r0, 0x1
_08095FE0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095FBC

	thumb_func_start sub_8095FE8
sub_8095FE8: @ 8095FE8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x1
	bl sub_80929FC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095FE8

	thumb_func_start sub_8096020
sub_8096020: @ 8096020
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x2
	bl sub_80929FC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096020

	thumb_func_start sub_8096058
sub_8096058: @ 8096058
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	bl sub_80929FC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096058

	thumb_func_start sub_8096090
sub_8096090: @ 8096090
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	bl sub_80929FC
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_8094554
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809459C
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096090

	thumb_func_start sub_80960C8
sub_80960C8: @ 80960C8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	bl npc_apply_direction
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_80929BC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80960C8

	thumb_func_start sub_8096100
sub_8096100: @ 8096100
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80960C8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096120
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096100

	thumb_func_start sub_8096120
sub_8096120: @ 8096120
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08096132
	movs r0, 0
	b _08096138
_08096132:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096138:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096120

	thumb_func_start sub_8096140
sub_8096140: @ 8096140
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_80960C8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096160
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096140

	thumb_func_start sub_8096160
sub_8096160: @ 8096160
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08096172
	movs r0, 0
	b _08096178
_08096172:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096178:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096160

	thumb_func_start sub_8096180
sub_8096180: @ 8096180
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_80960C8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80961A0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096180

	thumb_func_start sub_80961A0
sub_80961A0: @ 80961A0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080961B2
	movs r0, 0
	b _080961B8
_080961B2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080961B8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80961A0

	thumb_func_start sub_80961C0
sub_80961C0: @ 80961C0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x1
	bl sub_80960C8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80961E0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80961C0

	thumb_func_start sub_80961E0
sub_80961E0: @ 80961E0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080961F2
	movs r0, 0
	b _080961F8
_080961F2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080961F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80961E0

	thumb_func_start sub_8096200
sub_8096200: @ 8096200
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	bl npc_apply_direction
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_80929FC
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_apply_anim_looping
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8096200

	thumb_func_start sub_8096230
sub_8096230: @ 8096230
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8096200
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096250
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096230

	thumb_func_start sub_8096250
sub_8096250: @ 8096250
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08096262
	movs r0, 0
	b _08096268
_08096262:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096268:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096250

	thumb_func_start sub_8096270
sub_8096270: @ 8096270
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_8096200
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096290
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096270

	thumb_func_start sub_8096290
sub_8096290: @ 8096290
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080962A2
	movs r0, 0
	b _080962A8
_080962A2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080962A8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096290

	thumb_func_start sub_80962B0
sub_80962B0: @ 80962B0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8096200
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80962D0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80962B0

	thumb_func_start sub_80962D0
sub_80962D0: @ 80962D0
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080962E2
	movs r0, 0
	b _080962E8
_080962E2:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080962E8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80962D0

	thumb_func_start sub_80962F0
sub_80962F0: @ 80962F0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x1
	bl sub_8096200
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096310
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80962F0

	thumb_func_start sub_8096310
sub_8096310: @ 8096310
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _08096322
	movs r0, 0
	b _08096328
_08096322:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096328:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096310

	thumb_func_start sub_8096330
sub_8096330: @ 8096330
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	bl npc_apply_direction
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_80929DC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8096330

	thumb_func_start sub_8096368
sub_8096368: @ 8096368
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8096330
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096388
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096368

	thumb_func_start sub_8096388
sub_8096388: @ 8096388
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _0809639A
	movs r0, 0
	b _080963A0
_0809639A:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080963A0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096388

	thumb_func_start sub_80963A8
sub_80963A8: @ 80963A8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_8096330
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80963C8
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80963A8

	thumb_func_start sub_80963C8
sub_80963C8: @ 80963C8
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _080963DA
	movs r0, 0
	b _080963E0
_080963DA:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_080963E0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80963C8

	thumb_func_start sub_80963E8
sub_80963E8: @ 80963E8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8096330
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096408
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80963E8

	thumb_func_start sub_8096408
sub_8096408: @ 8096408
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _0809641A
	movs r0, 0
	b _08096420
_0809641A:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096420:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096408

	thumb_func_start sub_8096428
sub_8096428: @ 8096428
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	movs r3, 0x1
	bl sub_8096330
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096448
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096428

	thumb_func_start sub_8096448
sub_8096448: @ 8096448
	push {r4,lr}
	adds r4, r1, 0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, 24
	cmp r0, 0
	bne _0809645A
	movs r0, 0
	b _08096460
_0809645A:
	movs r0, 0x2
	strh r0, [r4, 0x32]
	movs r0, 0x1
_08096460:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096448

	thumb_func_start sub_8096468
sub_8096468: @ 8096468
	push {r4,lr}
	adds r4, r1, 0
	bl sub_8097FA4
	movs r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096468

	thumb_func_start sub_809647C
sub_809647C: @ 809647C
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x1B]
	bl sub_8098044
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809647C

	thumb_func_start sub_8096494
sub_8096494: @ 8096494
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080964A6
	movs r0, 0
	b _080964B0
_080964A6:
	ldrb r0, [r2, 0x1B]
	bl sub_8098044
	movs r0, 0x1
	strh r0, [r4, 0x32]
_080964B0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8096494

	thumb_func_start sub_80964B8
sub_80964B8: @ 80964B8
	movs r0, 0x1
	bx lr
	thumb_func_end sub_80964B8

	thumb_func_start sub_80964BC
@ bool8 sub_80964BC(struct npc_state *fieldObject, struct obj *object)
sub_80964BC: @ 80964BC
	adds r1, 0x2C
	ldrb r0, [r1]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1]
	movs r0, 0x1
	bx lr
	thumb_func_end sub_80964BC

	thumb_func_start npc_obj_transfer_image_anim_pause_flag
@ void npc_obj_transfer_image_anim_pause_flag(struct npc_state *fieldObject, struct obj *object)
npc_obj_transfer_image_anim_pause_flag: @ 80964CC
	push {lr}
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	cmp r0, 0
	bge _080964E2
	adds r0, r1, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
_080964E2:
	pop {r0}
	bx r0
	thumb_func_end npc_obj_transfer_image_anim_pause_flag

	thumb_func_start sub_80964E8
@ void sub_80964E8(struct npc_state *fieldObject, struct obj *object)
sub_80964E8: @ 80964E8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r3, [r4, 0x1]
	lsls r0, r3, 28
	cmp r0, 0
	bge _08096510
	adds r2, r1, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	movs r1, 0x9
	negs r1, r1
	ands r0, r1
	strb r0, [r4, 0x1]
_08096510:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80964E8

	thumb_func_start sub_8096518
@ void sub_8096518(struct npc_state *fieldObject, struct obj *object)
sub_8096518: @ 8096518
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8096530
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_update_obj_anim_flag
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8096518

	thumb_func_start sub_8096530
sub_8096530: @ 8096530
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r5, 0x1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldrb r0, [r5, 0x5]
	bl GetFieldObjectGraphicsInfo
	adds r6, r0, 0
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08096594
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x20]
	adds r1, r0
	adds r0, r4, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldr r2, =gSpriteCoordOffsetX
	adds r0, r1
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r1, [r4, 0x26]
	ldrh r0, [r4, 0x22]
	adds r1, r0
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldr r2, =gSpriteCoordOffsetY
	adds r0, r1
	ldrh r2, [r2]
	adds r0, r2
	b _080965BC
	.pool
_08096594:
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x20]
	adds r1, r0
	adds r0, r4, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r1, [r4, 0x26]
	ldrh r0, [r4, 0x22]
	adds r1, r0
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
_080965BC:
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r6, 0x8]
	adds r0, r3
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r0, [r6, 0xA]
	adds r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0xFF
	bgt _080965E4
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080965EC
_080965E4:
	ldrb r0, [r5, 0x1]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r5, 0x1]
_080965EC:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0xAF
	bgt _08096600
	lsls r0, r4, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _08096608
_08096600:
	ldrb r0, [r5, 0x1]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r5, 0x1]
_08096608:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8096530

	thumb_func_start npc_update_obj_anim_flag
@ void npc_update_obj_anim_flag(struct npc_state *fieldObject, struct obj *object)
npc_update_obj_anim_flag: @ 8096610
	push {lr}
	adds r2, r1, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x5
	negs r3, r3
	ands r3, r1
	strb r3, [r2]
	ldrb r1, [r0, 0x1]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08096632
	movs r1, 0x4
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08096632:
	pop {r0}
	bx r0
	thumb_func_end npc_update_obj_anim_flag

	.align 2, 0 @ Don't pad with nop.
