	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_808F988
@ bool8 sub_808F988(struct npc_state *fieldObject, struct obj *object)
sub_808F988: @ 808F988
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808F988

	thumb_func_start sub_808F99C
@ bool8 sub_808F99C(struct npc_state *fieldObject, struct obj *object)
sub_808F99C: @ 808F99C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808F99C

	thumb_func_start sub_808F9C8
@ bool8 sub_808F9C8(struct npc_state *fieldObject, struct obj *object)
sub_808F9C8: @ 808F9C8
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0808F9FE
	ldr r4, =gUnknown_0850D6DC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0808F9FE:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808F9C8

	thumb_func_start sub_808FA0C
@ bool8 sub_808FA0C(struct npc_state *fieldObject, struct obj *object)
sub_808FA0C: @ 808FA0C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _0808FA2A
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _0808FA32
_0808FA2A:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _0808FA34
_0808FA32:
	movs r0, 0
_0808FA34:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FA0C

	thumb_func_start sub_808FA3C
@ bool8 sub_808FA3C(struct npc_state *fieldObject, struct obj *object)
sub_808FA3C: @ 808FA3C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D710
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	movs r1, 0
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0808FA6C
	bl Random
	movs r1, 0x3
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_0808FA6C:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808FA3C

	thumb_func_start FieldObjectCB_RandomlyGoNorthOrSouth
FieldObjectCB_RandomlyGoNorthOrSouth: @ 808FA84
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_RandomlyGoNorthOrSouth
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyGoNorthOrSouth

	thumb_func_start FieldObjectCB2_RandomlyGoNorthOrSouth
FieldObjectCB2_RandomlyGoNorthOrSouth: @ 808FAA8
	push {r4,lr}
	ldr r3, =gUnknown_0850D754
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_RandomlyGoNorthOrSouth

	thumb_func_start sub_808FAC8
sub_808FAC8: @ 808FAC8
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FAC8

	thumb_func_start sub_808FADC
sub_808FADC: @ 808FADC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FADC

	thumb_func_start sub_808FB08
@ bool8 sub_808FB08(struct npc_state *fieldObject, struct obj *object)
sub_808FB08: @ 808FB08
	push {r4-r6,lr}
	adds r6, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0808FB3C
	ldr r5, =gUnknown_0850D6DC
	bl Random
	movs r4, 0x3
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r5
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r6, 0
	bl sub_8097978
	strh r4, [r6, 0x30]
	movs r0, 0x1
	b _0808FB3E
	.pool
_0808FB3C:
	movs r0, 0
_0808FB3E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808FB08

	thumb_func_start sub_808FB44
@ bool8 sub_808FB44(struct npc_state *fieldObject, struct obj *object)
sub_808FB44: @ 808FB44
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _0808FB58
	movs r0, 0
	b _0808FB5E
_0808FB58:
	movs r0, 0x4
	strh r0, [r4, 0x30]
	movs r0, 0x1
_0808FB5E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FB44

	thumb_func_start sub_808FB64
@ bool8 sub_808FB64(struct npc_state *fieldObject, struct obj *object)
sub_808FB64: @ 808FB64
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r1, =gUnknown_0850D770
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	bl Random
	movs r7, 0x1
	adds r1, r7, 0
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r4, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x5
	strh r0, [r6, 0x30]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8092B88
	lsls r0, 24
	cmp r0, 0
	beq _0808FBA2
	strh r7, [r6, 0x30]
_0808FBA2:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808FB64

	thumb_func_start sub_808FBB0
sub_808FBB0: @ 808FBB0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x6
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FBB0

	thumb_func_start sub_808FBE0
sub_808FBE0: @ 808FBE0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0808FBFE
	ldrb r0, [r4]
	movs r1, 0x3
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	movs r0, 0x1
	strh r0, [r5, 0x30]
_0808FBFE:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FBE0

	thumb_func_start FieldObjectCB_RandomlyGoEastOrWest
FieldObjectCB_RandomlyGoEastOrWest: @ 808FC08
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_RandomlyGoEastOrWest
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyGoEastOrWest

	thumb_func_start FieldObjectCB2_RandomlyGoEastOrWest
FieldObjectCB2_RandomlyGoEastOrWest: @ 808FC2C
	push {r4,lr}
	ldr r3, =gUnknown_0850D774
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_RandomlyGoEastOrWest

	thumb_func_start sub_808FC4C
sub_808FC4C: @ 808FC4C
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FC4C

	thumb_func_start sub_808FC60
sub_808FC60: @ 808FC60
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FC60

	thumb_func_start sub_808FC8C
sub_808FC8C: @ 808FC8C
	push {r4-r6,lr}
	adds r6, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0808FCC0
	ldr r5, =gUnknown_0850D6DC
	bl Random
	movs r4, 0x3
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r5
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r6, 0
	bl sub_8097978
	strh r4, [r6, 0x30]
	movs r0, 0x1
	b _0808FCC2
	.pool
_0808FCC0:
	movs r0, 0
_0808FCC2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808FC8C

	thumb_func_start sub_808FCC8
sub_808FCC8: @ 808FCC8
	push {r4,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _0808FCDC
	movs r0, 0
	b _0808FCE2
_0808FCDC:
	movs r0, 0x4
	strh r0, [r4, 0x30]
	movs r0, 0x1
_0808FCE2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FCC8

	thumb_func_start sub_808FCE8
sub_808FCE8: @ 808FCE8
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r1, =gUnknown_0850D790
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	bl Random
	movs r7, 0x1
	adds r1, r7, 0
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r4, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x5
	strh r0, [r6, 0x30]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8092B88
	lsls r0, 24
	cmp r0, 0
	beq _0808FD26
	strh r7, [r6, 0x30]
_0808FD26:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808FCE8

	thumb_func_start sub_808FD34
sub_808FD34: @ 808FD34
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x6
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FD34

	thumb_func_start sub_808FD64
sub_808FD64: @ 808FD64
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0808FD82
	ldrb r0, [r4]
	movs r1, 0x3
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	movs r0, 0x1
	strh r0, [r5, 0x30]
_0808FD82:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FD64

	thumb_func_start FieldObjectCB_FaceFixedDirection
FieldObjectCB_FaceFixedDirection: @ 808FD8C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_FaceFixedDirection
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_FaceFixedDirection

	thumb_func_start FieldObjectCB2_FaceFixedDirection
@ bool8 FieldObjectCB2_FaceFixedDirection(struct npc_state *fieldObject, struct obj *object)
FieldObjectCB2_FaceFixedDirection: @ 808FDB0
	push {r4,lr}
	ldr r3, =gUnknown_0850D794
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_FaceFixedDirection

	thumb_func_start sub_808FDD0
@ bool8 sub_808FDD0(struct npc_state *fieldObject, struct obj *object)
sub_808FDD0: @ 808FDD0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808FDD0

	thumb_func_start sub_808FDFC
@ bool8 sub_808FDFC(struct npc_state *fieldObject, struct obj *object)
sub_808FDFC: @ 808FDFC
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	bne _0808FE0E
	movs r0, 0
	b _0808FE14
_0808FE0E:
	movs r0, 0x2
	strh r0, [r4, 0x30]
	movs r0, 0x1
_0808FE14:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FDFC

	thumb_func_start sub_808FE1C
@ bool8 sub_808FE1C(struct npc_state *fieldObject, struct obj *object)
sub_808FE1C: @ 808FE1C
	ldrb r2, [r0]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0
	bx lr
	thumb_func_end sub_808FE1C

	thumb_func_start FieldObjectCB_BerryTree
FieldObjectCB_BerryTree: @ 808FE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrh r1, [r4, 0x3C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0808FE58
	adds r0, r5, 0
	adds r1, r4, 0
	bl get_berry_tree_graphics
	ldrh r1, [r4, 0x3C]
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r4, 0x3C]
_0808FE58:
	ldr r2, =FieldObjectCB2_BerryTree
	adds r0, r5, 0
	adds r1, r4, 0
	bl FieldObjectStep
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_BerryTree

	thumb_func_start FieldObjectCB2_BerryTree
FieldObjectCB2_BerryTree: @ 808FE70
	push {r4,lr}
	ldr r3, =gUnknown_0850D7A0
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_BerryTree

	thumb_func_start do_berry_tree_growth_sparkle_1
@ bool8 do_berry_tree_growth_sparkle_1(struct npc_state *fieldObject, struct obj *object)
do_berry_tree_growth_sparkle_1: @ 808FE90
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r6, r5, 0
	adds r6, 0x3E
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r4, 0x1D]
	bl GetStageByBerryTreeId
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0808FF00
	ldrh r1, [r5, 0x3C]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0808FEF6
	subs r6, 0x14
	ldrb r0, [r6]
	cmp r0, 0x4
	bne _0808FEF6
	ldr r1, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	str r0, [r1, 0x4]
	adds r0, r5, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r1, 0x8]
	ldrb r0, [r5, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r1, 0xC]
	movs r0, 0x17
	bl FieldEffectStart
	strb r7, [r6]
_0808FEF6:
	movs r0, 0
	b _0808FF42
	.pool
_0808FF00:
	ldrb r1, [r4, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r6]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	subs r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, r7
	bne _0808FF3C
	adds r0, r4, 0
	adds r1, r5, 0
	bl get_berry_tree_graphics
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x39
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	b _0808FF42
_0808FF3C:
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
_0808FF42:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end do_berry_tree_growth_sparkle_1

	thumb_func_start sub_808FF48
@ bool8 sub_808FF48(struct npc_state *fieldObject, struct obj *object)
sub_808FF48: @ 808FF48
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	bne _0808FF5A
	movs r0, 0
	b _0808FF60
_0808FF5A:
	movs r0, 0
	strh r0, [r4, 0x30]
	movs r0, 0x1
_0808FF60:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FF48

	thumb_func_start do_berry_tree_growth_sparkle_2
@ bool8 do_berry_tree_growth_sparkle_2(struct npc_state *fieldObject, struct obj *object)
do_berry_tree_growth_sparkle_2: @ 808FF68
	push {r4,lr}
	ldrb r2, [r0]
	movs r3, 0x2
	orrs r2, r3
	strb r2, [r0]
	movs r3, 0
	movs r2, 0x3
	strh r2, [r1, 0x30]
	strh r3, [r1, 0x32]
	ldrh r3, [r1, 0x3C]
	movs r2, 0x2
	orrs r2, r3
	strh r2, [r1, 0x3C]
	ldr r3, =gUnknown_02038C08
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r2, 0x12
	ldrsh r0, [r0, r2]
	str r0, [r3, 0x4]
	adds r0, r1, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r3, 0x8]
	ldrb r0, [r1, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r3, 0xC]
	movs r0, 0x17
	bl FieldEffectStart
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end do_berry_tree_growth_sparkle_2

	thumb_func_start sub_808FFB4
@ bool8 sub_808FFB4(struct npc_state *fieldObject, struct obj *object)
sub_808FFB4: @ 808FFB4
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrh r1, [r4, 0x32]
	adds r1, 0x1
	strh r1, [r4, 0x32]
	movs r0, 0x2
	ands r1, r0
	lsls r1, 16
	lsrs r1, 17
	lsls r1, 5
	ldrb r2, [r3, 0x1]
	subs r0, 0x23
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	bgt _0808FFEC
	movs r0, 0
	b _0808FFFE
_0808FFEC:
	adds r0, r3, 0
	adds r1, r4, 0
	bl get_berry_tree_graphics
	movs r0, 0x4
	strh r0, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	movs r0, 0x1
_0808FFFE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_808FFB4

	thumb_func_start sub_8090004
@ bool8 sub_8090004(struct npc_state *fieldObject, struct obj *object)
sub_8090004: @ 8090004
	push {r4,lr}
	adds r4, r1, 0
	ldrh r2, [r4, 0x32]
	adds r2, 0x1
	strh r2, [r4, 0x32]
	movs r1, 0x2
	ands r2, r1
	lsls r2, 16
	lsrs r2, 17
	lsls r2, 5
	ldrb r3, [r0, 0x1]
	subs r1, 0x23
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	bgt _0809003A
	movs r0, 0
	b _08090048
_0809003A:
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x3C]
	subs r0, 0x3
	ands r0, r1
	strh r0, [r4, 0x3C]
	movs r0, 0x1
_08090048:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090004

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrSouth
FieldObjectCB_RandomlyLookNorthOrSouth: @ 8090050
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_RandomlyLookNorthOrSouth
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrSouth

	thumb_func_start FieldObjectCB2_RandomlyLookNorthOrSouth
FieldObjectCB2_RandomlyLookNorthOrSouth: @ 8090074
	push {r4,lr}
	ldr r3, =gUnknown_0850D7B4
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_RandomlyLookNorthOrSouth

	thumb_func_start sub_8090094
sub_8090094: @ 8090094
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090094

	thumb_func_start sub_80900A8
sub_80900A8: @ 80900A8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80900A8

	thumb_func_start sub_80900D4
sub_80900D4: @ 80900D4
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809010A
	ldr r4, =gUnknown_0850D6DC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809010A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80900D4

	thumb_func_start sub_8090118
sub_8090118: @ 8090118
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090136
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _0809013E
_08090136:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090140
_0809013E:
	movs r0, 0
_08090140:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090118

	thumb_func_start sub_8090148
sub_8090148: @ 8090148
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D770
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090178
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090178:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090148

	thumb_func_start FieldObjectCB_RandomlyLookEastOrWest
FieldObjectCB_RandomlyLookEastOrWest: @ 8090190
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_RandomlyLookEastOrWest
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookEastOrWest

	thumb_func_start FieldObjectCB2_RandomlyLookEastOrWest
FieldObjectCB2_RandomlyLookEastOrWest: @ 80901B4
	push {r4,lr}
	ldr r3, =gUnknown_0850D7C8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_RandomlyLookEastOrWest

	thumb_func_start sub_80901D4
sub_80901D4: @ 80901D4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80901D4

	thumb_func_start sub_80901E8
sub_80901E8: @ 80901E8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80901E8

	thumb_func_start sub_8090214
sub_8090214: @ 8090214
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809024A
	ldr r4, =gUnknown_0850D6DC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809024A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090214

	thumb_func_start sub_8090258
sub_8090258: @ 8090258
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090276
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _0809027E
_08090276:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090280
_0809027E:
	movs r0, 0
_08090280:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090258

	thumb_func_start sub_8090288
sub_8090288: @ 8090288
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D790
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080902B8
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_080902B8:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090288

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrWest
FieldObjectCB_RandomlyLookNorthOrWest: @ 80902D0
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =FieldObjectCB2_RandomlyLookNorthOrWest
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrWest

	thumb_func_start FieldObjectCB2_RandomlyLookNorthOrWest
FieldObjectCB2_RandomlyLookNorthOrWest: @ 80902F4
	push {r4,lr}
	ldr r3, =gUnknown_0850D7DC
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldObjectCB2_RandomlyLookNorthOrWest

	thumb_func_start sub_8090314
sub_8090314: @ 8090314
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090314

	thumb_func_start sub_8090328
sub_8090328: @ 8090328
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090328

	thumb_func_start sub_8090354
sub_8090354: @ 8090354
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809038A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809038A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090354

	thumb_func_start sub_8090398
sub_8090398: @ 8090398
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _080903B6
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _080903BE
_080903B6:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _080903C0
_080903BE:
	movs r0, 0
_080903C0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090398

	thumb_func_start sub_80903C8
sub_80903C8: @ 80903C8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D7F0
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080903F8
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_080903F8:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80903C8

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrEast
FieldObjectCB_RandomlyLookNorthOrEast: @ 8090410
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090434
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrEast

	thumb_func_start sub_8090434
sub_8090434: @ 8090434
	push {r4,lr}
	ldr r3, =gUnknown_0850D7F4
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090434

	thumb_func_start sub_8090454
sub_8090454: @ 8090454
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090454

	thumb_func_start sub_8090468
sub_8090468: @ 8090468
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090468

	thumb_func_start sub_8090494
sub_8090494: @ 8090494
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _080904CA
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_080904CA:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090494

	thumb_func_start sub_80904D8
sub_80904D8: @ 80904D8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _080904F6
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _080904FE
_080904F6:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090500
_080904FE:
	movs r0, 0
_08090500:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80904D8

	thumb_func_start sub_8090508
sub_8090508: @ 8090508
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D808
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090538
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090538:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090508

	thumb_func_start FieldObjectCB_RandomlyLookSouthOrWest
FieldObjectCB_RandomlyLookSouthOrWest: @ 8090550
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090574
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookSouthOrWest

	thumb_func_start sub_8090574
sub_8090574: @ 8090574
	push {r4,lr}
	ldr r3, =gUnknown_0850D80C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090574

	thumb_func_start sub_8090594
sub_8090594: @ 8090594
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090594

	thumb_func_start sub_80905A8
sub_80905A8: @ 80905A8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80905A8

	thumb_func_start sub_80905D4
sub_80905D4: @ 80905D4
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809060A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809060A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80905D4

	thumb_func_start sub_8090618
sub_8090618: @ 8090618
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090636
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _0809063E
_08090636:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090640
_0809063E:
	movs r0, 0
_08090640:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090618

	thumb_func_start sub_8090648
sub_8090648: @ 8090648
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D820
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090678
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090678:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090648

	thumb_func_start FieldObjectCB_RandomlyLookSouthOrEast
FieldObjectCB_RandomlyLookSouthOrEast: @ 8090690
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80906B4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookSouthOrEast

	thumb_func_start sub_80906B4
sub_80906B4: @ 80906B4
	push {r4,lr}
	ldr r3, =gUnknown_0850D824
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80906B4

	thumb_func_start sub_80906D4
sub_80906D4: @ 80906D4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80906D4

	thumb_func_start sub_80906E8
sub_80906E8: @ 80906E8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80906E8

	thumb_func_start sub_8090714
sub_8090714: @ 8090714
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809074A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809074A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090714

	thumb_func_start sub_8090758
sub_8090758: @ 8090758
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090776
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _0809077E
_08090776:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090780
_0809077E:
	movs r0, 0
_08090780:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090758

	thumb_func_start sub_8090788
sub_8090788: @ 8090788
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D838
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x6
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080907B8
	bl Random
	movs r1, 0x1
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_080907B8:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090788

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrSouthOrWest
FieldObjectCB_RandomlyLookNorthOrSouthOrWest: @ 80907D0
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80907F4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrSouthOrWest

	thumb_func_start sub_80907F4
sub_80907F4: @ 80907F4
	push {r4,lr}
	ldr r3, =gUnknown_0850D83C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80907F4

	thumb_func_start sub_8090814
sub_8090814: @ 8090814
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090814

	thumb_func_start sub_8090828
sub_8090828: @ 8090828
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090828

	thumb_func_start sub_8090854
sub_8090854: @ 8090854
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809088A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_0809088A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090854

	thumb_func_start sub_8090898
sub_8090898: @ 8090898
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _080908B6
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _080908BE
_080908B6:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _080908C0
_080908BE:
	movs r0, 0
_080908C0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090898

	thumb_func_start sub_80908C8
sub_80908C8: @ 80908C8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D850
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x7
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080908F8
	bl Random
	movs r1, 0x3
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_080908F8:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80908C8

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrSouthOrEast
FieldObjectCB_RandomlyLookNorthOrSouthOrEast: @ 8090910
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090934
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrSouthOrEast

	thumb_func_start sub_8090934
sub_8090934: @ 8090934
	push {r4,lr}
	ldr r3, =gUnknown_0850D854
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090934

	thumb_func_start sub_8090954
sub_8090954: @ 8090954
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090954

	thumb_func_start sub_8090968
sub_8090968: @ 8090968
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090968

	thumb_func_start sub_8090994
sub_8090994: @ 8090994
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _080909CA
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_080909CA:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090994

	thumb_func_start sub_80909D8
sub_80909D8: @ 80909D8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _080909F6
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _080909FE
_080909F6:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090A00
_080909FE:
	movs r0, 0
_08090A00:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80909D8

	thumb_func_start sub_8090A08
sub_8090A08: @ 8090A08
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D868
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090A38
	bl Random
	movs r1, 0x3
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090A38:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090A08

	thumb_func_start FieldObjectCB_RandomlyLookNorthOrEastOrWest
FieldObjectCB_RandomlyLookNorthOrEastOrWest: @ 8090A50
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090A74
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookNorthOrEastOrWest

	thumb_func_start sub_8090A74
sub_8090A74: @ 8090A74
	push {r4,lr}
	ldr r3, =gUnknown_0850D86C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090A74

	thumb_func_start sub_8090A94
sub_8090A94: @ 8090A94
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090A94

	thumb_func_start sub_8090AA8
sub_8090AA8: @ 8090AA8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090AA8

	thumb_func_start sub_8090AD4
sub_8090AD4: @ 8090AD4
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _08090B0A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_08090B0A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090AD4

	thumb_func_start sub_8090B18
sub_8090B18: @ 8090B18
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090B36
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _08090B3E
_08090B36:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090B40
_08090B3E:
	movs r0, 0
_08090B40:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090B18

	thumb_func_start sub_8090B48
sub_8090B48: @ 8090B48
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D880
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	movs r1, 0x9
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090B78
	bl Random
	movs r1, 0x3
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090B78:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090B48

	thumb_func_start FieldObjectCB_RandomlyLookSouthOrEastOrWest
FieldObjectCB_RandomlyLookSouthOrEastOrWest: @ 8090B90
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090BB4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_RandomlyLookSouthOrEastOrWest

	thumb_func_start sub_8090BB4
sub_8090BB4: @ 8090BB4
	push {r4,lr}
	ldr r3, =gUnknown_0850D884
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090BB4

	thumb_func_start sub_8090BD4
sub_8090BD4: @ 8090BD4
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090BD4

	thumb_func_start sub_8090BE8
sub_8090BE8: @ 8090BE8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090BE8

	thumb_func_start sub_8090C14
sub_8090C14: @ 8090C14
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _08090C4A
	ldr r4, =gUnknown_0850D6EC
	bl Random
	movs r5, 0x3
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r7, 0
	bl sub_8097978
	ldrb r1, [r6]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r6]
	strh r5, [r7, 0x30]
_08090C4A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090C14

	thumb_func_start sub_8090C58
sub_8090C58: @ 8090C58
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090C76
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _08090C7E
_08090C76:
	movs r0, 0x4
	strh r0, [r5, 0x30]
	movs r0, 0x1
	b _08090C80
_08090C7E:
	movs r0, 0
_08090C80:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090C58

	thumb_func_start sub_8090C88
sub_8090C88: @ 8090C88
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D898
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090CB8
	bl Random
	movs r1, 0x3
	ands r1, r0
	mov r2, sp
	adds r0, r2, r1
	ldrb r1, [r0]
_08090CB8:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x1
	strh r0, [r5, 0x30]
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090C88

	thumb_func_start FieldObjectCB_LookAroundCounterclockwise
FieldObjectCB_LookAroundCounterclockwise: @ 8090CD0
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090CF4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_LookAroundCounterclockwise

	thumb_func_start sub_8090CF4
sub_8090CF4: @ 8090CF4
	push {r4,lr}
	ldr r3, =gUnknown_0850D89C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090CF4

	thumb_func_start sub_8090D14
sub_8090D14: @ 8090D14
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090D14

	thumb_func_start sub_8090D40
sub_8090D40: @ 8090D40
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _08090D5A
	adds r0, r4, 0
	movs r1, 0x30
	bl sub_8097978
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08090D5A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090D40

	thumb_func_start sub_8090D64
sub_8090D64: @ 8090D64
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090D82
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _08090D86
_08090D82:
	movs r0, 0x3
	strh r0, [r5, 0x30]
_08090D86:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090D64

	thumb_func_start sub_8090D90
@ bool8 sub_8090D90(struct npc_state *fieldObject, struct obj *object)
sub_8090D90: @ 8090D90
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D8AC
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	adds r0, r4, 0
	movs r1, 0
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090DBC
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
_08090DBC:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0
	strh r0, [r5, 0x30]
	movs r0, 0x1
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090D90

	thumb_func_start FieldObjectCB_LookAroundClockwise
FieldObjectCB_LookAroundClockwise: @ 8090DD4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090DF8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_LookAroundClockwise

	thumb_func_start sub_8090DF8
sub_8090DF8: @ 8090DF8
	push {r4,lr}
	ldr r3, =gUnknown_0850D8B4
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090DF8

	thumb_func_start sub_8090E18
sub_8090E18: @ 8090E18
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090E18

	thumb_func_start sub_8090E44
sub_8090E44: @ 8090E44
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _08090E5E
	adds r0, r4, 0
	movs r1, 0x30
	bl sub_8097978
	movs r0, 0x2
	strh r0, [r4, 0x30]
_08090E5E:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090E44

	thumb_func_start sub_8090E68
sub_8090E68: @ 8090E68
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl sub_809797C
	lsls r0, 24
	cmp r0, 0
	bne _08090E86
	adds r0, r4, 0
	bl FieldObjectIsTrainerAndCloseToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _08090E8A
_08090E86:
	movs r0, 0x3
	strh r0, [r5, 0x30]
_08090E8A:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8090E68

	thumb_func_start sub_8090E94
sub_8090E94: @ 8090E94
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D8C4
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	adds r0, r4, 0
	movs r1, 0
	bl sub_808F8BC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08090EC0
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
_08090EC0:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0
	strh r0, [r5, 0x30]
	movs r0, 0x1
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090E94

	thumb_func_start FieldObjectCB_AlternatelyGoInOppositeDirections
FieldObjectCB_AlternatelyGoInOppositeDirections: @ 8090ED8
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8090EFC
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_AlternatelyGoInOppositeDirections

	thumb_func_start sub_8090EFC
sub_8090EFC: @ 8090EFC
	push {r4,lr}
	ldr r3, =gUnknown_0850D8CC
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090EFC

	thumb_func_start sub_8090F1C
sub_8090F1C: @ 8090F1C
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090F1C

	thumb_func_start sub_8090F30
@ bool8 sub_8090F30(struct npc_state *fieldObject, struct obj *object)
sub_8090F30: @ 8090F30
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_085055CD
	ldrb r1, [r4, 0x6]
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r4, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0
	beq _08090F52
	adds r0, r1, 0
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r1, r0, 24
_08090F52:
	adds r0, r4, 0
	bl FieldObjectSetDirection
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8090F30

	thumb_func_start sub_8090F68
@ bool8 sub_8090F68(struct npc_state *fieldObject, struct obj *object)
sub_8090F68: @ 8090F68
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r7, r1, 0
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0
	beq _08090F98
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bne _08090F98
	movs r0, 0
	strb r0, [r2]
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetOppositeDirection
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetDirection
_08090F98:
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl sub_8092B88
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r5, 0x1
	bne _08090FEE
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetOppositeDirection
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetDirection
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl sub_8092B88
	lsls r0, 24
	lsrs r5, r0, 24
_08090FEE:
	cmp r5, 0
	beq _08091000
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay16AnimId
	lsls r0, 24
	lsrs r6, r0, 24
_08091000:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x3
	strh r0, [r7, 0x30]
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090F68

	thumb_func_start sub_8091020
@ bool8 sub_8091020(struct npc_state *fieldObject, struct obj *object)
sub_8091020: @ 8091020
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809103E
	ldrb r0, [r4]
	movs r1, 0x3
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	movs r0, 0x1
	strh r0, [r5, 0x30]
_0809103E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091020

	thumb_func_start sub_8091048
@ bool8 sub_8091048(struct npc_state *fieldObject, struct obj *object)
sub_8091048: @ 8091048
	push {r4,lr}
	adds r4, r1, 0
	bl npc_reset
	movs r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8091048

	thumb_func_start MoveFieldObjectInNextDirectionInSequence
@ bool8 MoveFieldObjectInNextDirectionInSequence(struct npc_state *fieldObject, struct obj *object, u8 *directions)
MoveFieldObjectInNextDirectionInSequence: @ 809105C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	mov r8, r1
	adds r7, r2, 0
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x3
	bne _0809107E
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bne _0809107E
	movs r0, 0
	strb r0, [r2]
_0809107E:
	adds r5, r4, 0
	adds r5, 0x21
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl FieldObjectSetDirection
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl sub_8092B88
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080910D8
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl FieldObjectSetDirection
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetGoSpeed0AnimId
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl sub_8092B88
	lsls r0, 24
	lsrs r0, 24
_080910D8:
	cmp r0, 0
	beq _080910EA
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay16AnimId
	lsls r0, 24
	lsrs r6, r0, 24
_080910EA:
	adds r0, r4, 0
	mov r1, r8
	adds r2, r6, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	mov r1, r8
	strh r0, [r1, 0x30]
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MoveFieldObjectInNextDirectionInSequence

	thumb_func_start sub_8091110
@ bool8 sub_8091110(struct npc_state *fieldObject, struct obj *object)
sub_8091110: @ 8091110
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _0809112E
	ldrb r0, [r4]
	movs r1, 0x3
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	movs r0, 0x1
	strh r0, [r5, 0x30]
_0809112E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091110

	thumb_func_start FieldObjectCB_GoInDirectionSequence1
FieldObjectCB_GoInDirectionSequence1: @ 8091138
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_809115C
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence1

	thumb_func_start sub_809115C
sub_809115C: @ 809115C
	push {r4,lr}
	ldr r3, =gUnknown_0850D8DC
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809115C

	thumb_func_start sub_809117C
sub_809117C: @ 809117C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D8E8
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _080911A8
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080911A8
	movs r0, 0x3
	strb r0, [r2]
_080911A8:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809117C

	thumb_func_start FieldObjectCB_GoInDirectionSequence2
FieldObjectCB_GoInDirectionSequence2: @ 80911C4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80911E8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence2

	thumb_func_start sub_80911E8
sub_80911E8: @ 80911E8
	push {r4,lr}
	ldr r3, =gUnknown_0850D8EC
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80911E8

	thumb_func_start sub_8091208
sub_8091208: @ 8091208
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D8F8
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _08091234
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091234
	movs r0, 0x2
	strb r0, [r2]
_08091234:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091208

	thumb_func_start FieldObjectCB_GoInDirectionSequence3
FieldObjectCB_GoInDirectionSequence3: @ 8091250
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091274
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence3

	thumb_func_start sub_8091274
sub_8091274: @ 8091274
	push {r4,lr}
	ldr r3, =gUnknown_0850D8FC
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091274

	thumb_func_start sub_8091294
sub_8091294: @ 8091294
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D908
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _080912C0
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080912C0
	movs r0, 0x2
	strb r0, [r2]
_080912C0:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091294

	thumb_func_start FieldObjectCB_GoInDirectionSequence4
FieldObjectCB_GoInDirectionSequence4: @ 80912DC
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091300
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence4

	thumb_func_start sub_8091300
sub_8091300: @ 8091300
	push {r4,lr}
	ldr r3, =gUnknown_0850D90C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091300

	thumb_func_start sub_8091320
sub_8091320: @ 8091320
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D918
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _0809134C
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _0809134C
	movs r0, 0x3
	strb r0, [r2]
_0809134C:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091320

	thumb_func_start FieldObjectCB_GoInDirectionSequence5
FieldObjectCB_GoInDirectionSequence5: @ 8091368
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_809138C
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence5

	thumb_func_start sub_809138C
sub_809138C: @ 809138C
	push {r4,lr}
	ldr r3, =gUnknown_0850D91C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809138C

	thumb_func_start sub_80913AC
@ bool8 sub_80913AC(struct npc_state *fieldObject, struct obj *object)
sub_80913AC: @ 80913AC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D928
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _080913D8
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080913D8
	movs r0, 0x3
	strb r0, [r2]
_080913D8:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80913AC

	thumb_func_start FieldObjectCB_GoInDirectionSequence6
FieldObjectCB_GoInDirectionSequence6: @ 80913F4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091418
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence6

	thumb_func_start sub_8091418
sub_8091418: @ 8091418
	push {r4,lr}
	ldr r3, =gUnknown_0850D92C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091418

	thumb_func_start sub_8091438
sub_8091438: @ 8091438
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D938
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _08091464
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091464
	movs r0, 0x2
	strb r0, [r2]
_08091464:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091438

	thumb_func_start FieldObjectCB_GoInDirectionSequence7
FieldObjectCB_GoInDirectionSequence7: @ 8091480
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80914A4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence7

	thumb_func_start sub_80914A4
sub_80914A4: @ 80914A4
	push {r4,lr}
	ldr r3, =gUnknown_0850D93C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80914A4

	thumb_func_start sub_80914C4
sub_80914C4: @ 80914C4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D710
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _080914F0
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080914F0
	movs r0, 0x2
	strb r0, [r2]
_080914F0:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80914C4

	thumb_func_start FieldObjectCB_GoInDirectionSequence8
FieldObjectCB_GoInDirectionSequence8: @ 809150C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091530
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence8

	thumb_func_start sub_8091530
sub_8091530: @ 8091530
	push {r4,lr}
	ldr r3, =gUnknown_0850D948
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091530

	thumb_func_start sub_8091550
sub_8091550: @ 8091550
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D954
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _0809157C
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _0809157C
	movs r0, 0x3
	strb r0, [r2]
_0809157C:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091550

	thumb_func_start FieldObjectCB_GoInDirectionSequence9
FieldObjectCB_GoInDirectionSequence9: @ 8091598
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80915BC
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence9

	thumb_func_start sub_80915BC
sub_80915BC: @ 80915BC
	push {r4,lr}
	ldr r3, =gUnknown_0850D958
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80915BC

	thumb_func_start sub_80915DC
sub_80915DC: @ 80915DC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D964
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091608
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091608
	movs r0, 0x3
	strb r0, [r2]
_08091608:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80915DC

	thumb_func_start FieldObjectCB_GoInDirectionSequence10
FieldObjectCB_GoInDirectionSequence10: @ 8091624
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091648
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence10

	thumb_func_start sub_8091648
sub_8091648: @ 8091648
	push {r4,lr}
	ldr r3, =gUnknown_0850D968
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091648

	thumb_func_start sub_8091668
sub_8091668: @ 8091668
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D974
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _08091694
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091694
	movs r0, 0x2
	strb r0, [r2]
_08091694:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091668

	thumb_func_start FieldObjectCB_GoInDirectionSequence11
FieldObjectCB_GoInDirectionSequence11: @ 80916B0
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80916D4
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence11

	thumb_func_start sub_80916D4
sub_80916D4: @ 80916D4
	push {r4,lr}
	ldr r3, =gUnknown_0850D978
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80916D4

	thumb_func_start sub_80916F4
sub_80916F4: @ 80916F4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D984
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _08091720
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091720
	movs r0, 0x2
	strb r0, [r2]
_08091720:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80916F4

	thumb_func_start FieldObjectCB_GoInDirectionSequence12
FieldObjectCB_GoInDirectionSequence12: @ 809173C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091760
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence12

	thumb_func_start sub_8091760
sub_8091760: @ 8091760
	push {r4,lr}
	ldr r3, =gUnknown_0850D988
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091760

	thumb_func_start sub_8091780
sub_8091780: @ 8091780
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D994
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _080917AC
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080917AC
	movs r0, 0x3
	strb r0, [r2]
_080917AC:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091780

	thumb_func_start FieldObjectCB_GoInDirectionSequence13
FieldObjectCB_GoInDirectionSequence13: @ 80917C8
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80917EC
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence13

	thumb_func_start sub_80917EC
sub_80917EC: @ 80917EC
	push {r4,lr}
	ldr r3, =gUnknown_0850D998
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80917EC

	thumb_func_start sub_809180C
sub_809180C: @ 809180C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9A4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091838
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091838
	movs r0, 0x3
	strb r0, [r2]
_08091838:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809180C

	thumb_func_start FieldObjectCB_GoInDirectionSequence14
FieldObjectCB_GoInDirectionSequence14: @ 8091854
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091878
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence14

	thumb_func_start sub_8091878
sub_8091878: @ 8091878
	push {r4,lr}
	ldr r3, =gUnknown_0850D9A8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091878

	thumb_func_start sub_8091898
sub_8091898: @ 8091898
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9B4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _080918C4
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080918C4
	movs r0, 0x2
	strb r0, [r2]
_080918C4:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091898

	thumb_func_start FieldObjectCB_GoInDirectionSequence15
FieldObjectCB_GoInDirectionSequence15: @ 80918E0
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091904
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence15

	thumb_func_start sub_8091904
sub_8091904: @ 8091904
	push {r4,lr}
	ldr r3, =gUnknown_0850D9B8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091904

	thumb_func_start sub_8091924
sub_8091924: @ 8091924
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9C4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _08091950
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091950
	movs r0, 0x2
	strb r0, [r2]
_08091950:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091924

	thumb_func_start FieldObjectCB_GoInDirectionSequence16
FieldObjectCB_GoInDirectionSequence16: @ 809196C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091990
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence16

	thumb_func_start sub_8091990
sub_8091990: @ 8091990
	push {r4,lr}
	ldr r3, =gUnknown_0850D9C8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091990

	thumb_func_start sub_80919B0
sub_80919B0: @ 80919B0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9D4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _080919DC
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _080919DC
	movs r0, 0x3
	strb r0, [r2]
_080919DC:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80919B0

	thumb_func_start FieldObjectCB_GoInDirectionSequence17
FieldObjectCB_GoInDirectionSequence17: @ 80919F8
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091A1C
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence17

	thumb_func_start sub_8091A1C
sub_8091A1C: @ 8091A1C
	push {r4,lr}
	ldr r3, =gUnknown_0850D9D8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091A1C

	thumb_func_start sub_8091A3C
sub_8091A3C: @ 8091A3C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9E4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091A68
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091A68
	movs r0, 0x3
	strb r0, [r2]
_08091A68:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091A3C

	thumb_func_start FieldObjectCB_GoInDirectionSequence18
FieldObjectCB_GoInDirectionSequence18: @ 8091A84
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091AA8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence18

	thumb_func_start sub_8091AA8
sub_8091AA8: @ 8091AA8
	push {r4,lr}
	ldr r3, =gUnknown_0850D9E8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091AA8

	thumb_func_start sub_8091AC8
sub_8091AC8: @ 8091AC8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850D9F4
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091AF4
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091AF4
	movs r0, 0x3
	strb r0, [r2]
_08091AF4:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091AC8

	thumb_func_start FieldObjectCB_GoInDirectionSequence19
FieldObjectCB_GoInDirectionSequence19: @ 8091B10
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091B34
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence19

	thumb_func_start sub_8091B34
sub_8091B34: @ 8091B34
	push {r4,lr}
	ldr r3, =gUnknown_0850D9F8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091B34

	thumb_func_start sub_8091B54
sub_8091B54: @ 8091B54
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA04
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091B80
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091B80
	movs r0, 0x3
	strb r0, [r2]
_08091B80:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091B54

	thumb_func_start FieldObjectCB_GoInDirectionSequence20
FieldObjectCB_GoInDirectionSequence20: @ 8091B9C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091BC0
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence20

	thumb_func_start sub_8091BC0
sub_8091BC0: @ 8091BC0
	push {r4,lr}
	ldr r3, =gUnknown_0850DA08
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091BC0

	thumb_func_start sub_8091BE0
sub_8091BE0: @ 8091BE0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA14
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091C0C
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091C0C
	movs r0, 0x3
	strb r0, [r2]
_08091C0C:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091BE0

	thumb_func_start FieldObjectCB_GoInDirectionSequence21
FieldObjectCB_GoInDirectionSequence21: @ 8091C28
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091C4C
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence21

	thumb_func_start sub_8091C4C
sub_8091C4C: @ 8091C4C
	push {r4,lr}
	ldr r3, =gUnknown_0850DA18
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091C4C

	thumb_func_start sub_8091C6C
sub_8091C6C: @ 8091C6C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA24
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091C98
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091C98
	movs r0, 0x3
	strb r0, [r2]
_08091C98:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091C6C

	thumb_func_start FieldObjectCB_GoInDirectionSequence22
FieldObjectCB_GoInDirectionSequence22: @ 8091CB4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091CD8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence22

	thumb_func_start sub_8091CD8
sub_8091CD8: @ 8091CD8
	push {r4,lr}
	ldr r3, =gUnknown_0850DA28
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091CD8

	thumb_func_start sub_8091CF8
sub_8091CF8: @ 8091CF8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA34
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091D24
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091D24
	movs r0, 0x3
	strb r0, [r2]
_08091D24:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091CF8

	thumb_func_start FieldObjectCB_GoInDirectionSequence23
FieldObjectCB_GoInDirectionSequence23: @ 8091D40
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091D64
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence23

	thumb_func_start sub_8091D64
sub_8091D64: @ 8091D64
	push {r4,lr}
	ldr r3, =gUnknown_0850DA38
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091D64

	thumb_func_start sub_8091D84
sub_8091D84: @ 8091D84
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA44
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091DB0
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091DB0
	movs r0, 0x3
	strb r0, [r2]
_08091DB0:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091D84

	thumb_func_start FieldObjectCB_GoInDirectionSequence24
FieldObjectCB_GoInDirectionSequence24: @ 8091DCC
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091DF0
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_GoInDirectionSequence24

	thumb_func_start sub_8091DF0
sub_8091DF0: @ 8091DF0
	push {r4,lr}
	ldr r3, =gUnknown_0850DA48
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091DF0

	thumb_func_start sub_8091E10
sub_8091E10: @ 8091E10
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_0850DA54
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08091E3C
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bne _08091E3C
	movs r0, 0x3
	strb r0, [r2]
_08091E3C:
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl MoveFieldObjectInNextDirectionInSequence
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091E10

	thumb_func_start FieldObjectCB_CopyPlayer1
FieldObjectCB_CopyPlayer1: @ 8091E58
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8091E7C
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_CopyPlayer1

	thumb_func_start sub_8091E7C
sub_8091E7C: @ 8091E7C
	push {r4,lr}
	ldr r3, =gUnknown_0850DA58
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091E7C

	thumb_func_start mss_npc_reset_oampriv3_1_unk2_unk3
@ bool8 mss_npc_reset_oampriv3_1_unk2_unk3(struct npc_state *fieldObject, struct obj *object)
mss_npc_reset_oampriv3_1_unk2_unk3: @ 8091E9C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	adds r4, 0x21
	ldrb r0, [r4]
	cmp r0, 0
	bne _08091EB4
	bl player_get_direction_lower_nybble
	strb r0, [r4]
_08091EB4:
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end mss_npc_reset_oampriv3_1_unk2_unk3

	thumb_func_start sub_8091EC0
@ bool8 sub_8091EC0(struct npc_state *fieldObject, struct obj *object)
sub_8091EC0: @ 8091EC0
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	ldr r2, =gMapObjects
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1C]
	cmp r0, 0xFF
	beq _08091EE0
	ldrb r0, [r3, 0x3]
	cmp r0, 0x2
	bne _08091EEC
_08091EE0:
	movs r0, 0
	b _08091F14
	.pool
_08091EEC:
	ldr r5, =gUnknown_0850DA64
	bl player_get_x22
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	adds r4, r5
	bl player_get_direction_upper_nybble
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r4, [r4]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r3, 0
	bl _call_via_r4
	lsls r0, 24
	lsrs r0, 24
_08091F14:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091EC0

	thumb_func_start sub_8091F20
sub_8091F20: @ 8091F20
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _08091F3E
	ldrb r0, [r4]
	movs r1, 0x3
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	movs r0, 0x1
	strh r0, [r5, 0x30]
_08091F3E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091F20

	thumb_func_start sub_8091F48
sub_8091F48: @ 8091F48
	movs r0, 0
	bx lr
	thumb_func_end sub_8091F48

	thumb_func_start sub_8091F4C
sub_8091F4C: @ 8091F4C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	bl state_to_direction
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091F4C

	thumb_func_start sub_8091F94
sub_8091F94: @ 8091F94
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r5, r2, 24
	adds r6, r5, 0
	bl FieldObjectIsFarawayIslandMew
	lsls r0, 24
	cmp r0, 0
	beq _08091FFC
	bl sub_81D427C
	adds r5, r0, 0
	cmp r5, 0
	bne _08092012
	adds r5, r6, 0
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r5, 0
	bl state_to_direction
	adds r5, r0, 0
	mov r3, sp
	adds r3, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl FieldObjectMoveDestCoords
	adds r0, r5, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	b _08092084
	.pool
_08091FFC:
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r5, 0
	bl state_to_direction
	adds r5, r0, 0
_08092012:
	mov r6, sp
	adds r6, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	adds r3, r6, 0
	bl FieldObjectMoveDestCoords
	adds r0, r5, 0
	bl GetGoSpeed0AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r6, r0]
	adds r0, r4, 0
	adds r3, r5, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _08092070
	mov r1, r8
	cmp r1, 0
	beq _08092084
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _08092084
_08092070:
	adds r0, r5, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_08092084:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8091F94

	thumb_func_start sub_80920A4
sub_80920A4: @ 80920A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r6, 0
	bl state_to_direction
	adds r6, r0, 0
	mov r5, sp
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, sp
	adds r3, r5, 0
	bl FieldObjectMoveDestCoords
	adds r0, r6, 0
	bl GetGoSpeed1AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r6, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _0809212A
	mov r1, r8
	cmp r1, 0
	beq _0809213E
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _0809213E
_0809212A:
	adds r0, r6, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_0809213E:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80920A4

	thumb_func_start sub_809215C
sub_809215C: @ 809215C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r6, 0
	bl state_to_direction
	adds r6, r0, 0
	mov r5, sp
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, sp
	adds r3, r5, 0
	bl FieldObjectMoveDestCoords
	adds r0, r6, 0
	bl GetGoSpeed3AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r6, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _080921E2
	mov r1, r8
	cmp r1, 0
	beq _080921F6
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _080921F6
_080921E2:
	adds r0, r6, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_080921F6:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809215C

	thumb_func_start sub_8092214
sub_8092214: @ 8092214
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r6, 0
	bl state_to_direction
	adds r6, r0, 0
	mov r5, sp
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, sp
	adds r3, r5, 0
	bl FieldObjectMoveDestCoords
	adds r0, r6, 0
	bl sub_8093438
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r6, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _0809229A
	mov r1, r8
	cmp r1, 0
	beq _080922AE
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _080922AE
_0809229A:
	adds r0, r6, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_080922AE:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8092214

	thumb_func_start cph_IM_DIFFERENT
cph_IM_DIFFERENT: @ 80922CC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	bl state_to_direction
	bl sub_80934BC
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r5, 0x30]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end cph_IM_DIFFERENT

	thumb_func_start sub_8092314
sub_8092314: @ 8092314
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r6, 0
	bl state_to_direction
	adds r6, r0, 0
	mov r5, sp
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, sp
	adds r3, r5, 0
	bl FieldObjectMoveDestCoords
	adds r0, r6, 0
	bl sub_8093514
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r6, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _0809239A
	mov r1, r8
	cmp r1, 0
	beq _080923AE
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _080923AE
_0809239A:
	adds r0, r6, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_080923AE:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8092314

	thumb_func_start oac_hopping
oac_hopping: @ 80923CC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r1, =gUnknown_085055CD
	ldrb r0, [r4, 0x6]
	adds r0, r1
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r2, r6, 0
	bl state_to_direction
	adds r6, r0, 0
	ldrh r1, [r4, 0x10]
	add r0, sp, 0x4
	strh r1, [r0]
	ldrh r0, [r4, 0x12]
	mov r5, sp
	adds r5, 0x6
	strh r0, [r5]
	movs r0, 0x2
	str r0, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	movs r3, 0x2
	bl sub_8092F88
	adds r0, r6, 0
	bl GetJumpLedgeAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
	add r0, sp, 0x4
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r6, 0
	bl npc_block_way
	lsls r0, 24
	cmp r0, 0
	bne _08092460
	mov r1, r8
	cmp r1, 0
	beq _08092474
	add r0, sp, 0x4
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r8
	lsls r0, 24
	cmp r0, 0
	bne _08092474
_08092460:
	adds r0, r6, 0
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r7, 0
	bl FieldObjectSetRegularAnim
_08092474:
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x2
	strh r0, [r7, 0x30]
	movs r0, 0x1
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oac_hopping

	thumb_func_start FieldObjectCB_CopyPlayer2
FieldObjectCB_CopyPlayer2: @ 8092494
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80924B8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_CopyPlayer2

	thumb_func_start sub_80924B8
sub_80924B8: @ 80924B8
	push {r4,lr}
	ldr r3, =gUnknown_0850DA90
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80924B8

	thumb_func_start mss_08062EA4
mss_08062EA4: @ 80924D8
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	ldr r2, =gMapObjects
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1C]
	cmp r0, 0xFF
	beq _080924F8
	ldrb r0, [r3, 0x3]
	cmp r0, 0x2
	bne _08092504
_080924F8:
	movs r0, 0
	b _0809252C
	.pool
_08092504:
	ldr r5, =gUnknown_0850DA64
	bl player_get_x22
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	adds r4, r5
	bl player_get_direction_upper_nybble
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_8088E64
	ldr r4, [r4]
	adds r0, r6, 0
	adds r1, r7, 0
	bl _call_via_r4
	lsls r0, 24
	lsrs r0, 24
_0809252C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mss_08062EA4

	thumb_func_start FieldObjectCB_TreeDisguise
@ void FieldObjectCB_TreeDisguise(struct obj *object)
FieldObjectCB_TreeDisguise: @ 809253C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gMapObjects
	adds r4, r1, r0
	adds r6, r4, 0
	adds r6, 0x21
	ldrb r0, [r6]
	cmp r0, 0
	beq _08092564
	cmp r0, 0x1
	bne _08092584
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08092584
_08092564:
	ldr r1, =gUnknown_02038C08
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	adds r0, r4, 0
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0x1C
	bl FieldEffectStart
	strb r0, [r4, 0x1A]
	movs r0, 0x1
	strb r0, [r6]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
_08092584:
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldr r2, =sub_80925AC
	adds r1, r5, 0
	bl FieldObjectStep
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_TreeDisguise

	thumb_func_start sub_80925AC
sub_80925AC: @ 80925AC
	push {lr}
	bl npc_reset
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80925AC

	thumb_func_start FieldObjectCB_MountainDisguise
FieldObjectCB_MountainDisguise: @ 80925B8
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gMapObjects
	adds r4, r1, r0
	adds r6, r4, 0
	adds r6, 0x21
	ldrb r0, [r6]
	cmp r0, 0
	beq _080925E0
	cmp r0, 0x1
	bne _08092600
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08092600
_080925E0:
	ldr r1, =gUnknown_02038C08
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	adds r0, r4, 0
	bl FieldObjectGetLocalIdAndMap
	movs r0, 0x1D
	bl FieldEffectStart
	strb r0, [r4, 0x1A]
	movs r0, 0x1
	strb r0, [r6]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
_08092600:
	movs r0, 0x2E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldr r2, =sub_80925AC
	adds r1, r5, 0
	bl FieldObjectStep
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_MountainDisguise

	thumb_func_start FieldObjectCB_Hidden1
@ void FieldObjectCB_Hidden1(struct obj *object)
FieldObjectCB_Hidden1: @ 8092628
	push {r4,lr}
	adds r3, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r3, r1]
	ldr r4, =gMapObjects
	cmp r0, 0
	bne _08092668
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x3]
	adds r2, r3, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r3, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldrh r0, [r3, 0x3C]
	adds r0, 0x1
	strh r0, [r3, 0x3C]
_08092668:
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r2, =sub_809268C
	adds r1, r3, 0
	bl FieldObjectStep
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_Hidden1

	thumb_func_start sub_809268C
sub_809268C: @ 809268C
	push {r4,lr}
	ldr r3, =gUnknown_0850DA9C
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809268C

	thumb_func_start sub_80926AC
sub_80926AC: @ 80926AC
	push {lr}
	bl npc_reset
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80926AC

	thumb_func_start sub_80926B8
@ bool8 sub_80926B8(struct npc_state *fieldObject, struct obj *object)
sub_80926B8: @ 80926B8
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	beq _080926CA
	movs r0, 0
	strh r0, [r4, 0x30]
_080926CA:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80926B8

	thumb_func_start FieldObjectCB_WalkInPlace1
FieldObjectCB_WalkInPlace1: @ 80926D4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80926F8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_WalkInPlace1

	thumb_func_start sub_80926F8
sub_80926F8: @ 80926F8
	push {r4,lr}
	ldr r3, =gUnknown_0850DAA0
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80926F8

	thumb_func_start sub_8092718
sub_8092718: @ 8092718
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay16AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092718

	thumb_func_start FieldObjectCB_WalkInPlace4
FieldObjectCB_WalkInPlace4: @ 8092744
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8092768
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_WalkInPlace4

	thumb_func_start sub_8092768
sub_8092768: @ 8092768
	push {r4,lr}
	ldr r3, =gUnknown_0850DAA8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8092768

	thumb_func_start sub_8092788
sub_8092788: @ 8092788
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay32AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092788

	thumb_func_start FieldObjectCB_WalkInPlace2
FieldObjectCB_WalkInPlace2: @ 80927B4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80927D8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_WalkInPlace2

	thumb_func_start sub_80927D8
sub_80927D8: @ 80927D8
	push {r4,lr}
	ldr r3, =gUnknown_0850DAB0
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80927D8

	thumb_func_start sub_80927F8
@ bool8 sub_80927F8(struct npc_state *fieldObject, struct obj *object)
sub_80927F8: @ 80927F8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay8AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80927F8

	thumb_func_start FieldObjectCB_WalkInPlace3
FieldObjectCB_WalkInPlace3: @ 8092824
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_8092848
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_WalkInPlace3

	thumb_func_start sub_8092848
sub_8092848: @ 8092848
	push {r4,lr}
	ldr r3, =gUnknown_0850DAB8
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8092848

	thumb_func_start sub_8092868
sub_8092868: @ 8092868
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay4AnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092868

	thumb_func_start FieldObjectCB_Hidden2
FieldObjectCB_Hidden2: @ 8092894
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gMapObjects
	adds r0, r2
	ldr r2, =sub_80928B8
	bl FieldObjectStep
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectCB_Hidden2

	thumb_func_start sub_80928B8
sub_80928B8: @ 80928B8
	push {r4,lr}
	ldr r3, =gUnknown_0850DAC0
	movs r4, 0x30
	ldrsh r2, [r1, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80928B8

	thumb_func_start sub_80928D8
sub_80928D8: @ 80928D8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl npc_reset
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionAnimId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectSetRegularAnim
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1
	strh r0, [r5, 0x30]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80928D8

	thumb_func_start sub_809290C
sub_809290C: @ 809290C
	push {r4,lr}
	adds r4, r1, 0
	bl FieldObjectExecRegularAnim
	lsls r0, 24
	cmp r0, 0
	bne _0809291E
	movs r0, 0
	b _08092924
_0809291E:
	movs r0, 0x2
	strh r0, [r4, 0x30]
	movs r0, 0x1
_08092924:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809290C

	thumb_func_start sub_809292C
sub_809292C: @ 809292C
	ldrb r2, [r0]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0
	bx lr
	thumb_func_end sub_809292C

	thumb_func_start npc_reset
@ void npc_reset(struct npc_state *fieldObject, struct obj *object)
npc_reset: @ 809293C
	ldrb r3, [r0]
	movs r2, 0x3
	negs r2, r2
	ands r2, r3
	movs r3, 0x41
	negs r3, r3
	ands r2, r3
	movs r3, 0x7F
	ands r2, r3
	strb r2, [r0]
	movs r2, 0xFF
	strb r2, [r0, 0x1C]
	movs r0, 0
	strh r0, [r1, 0x30]
	bx lr
	thumb_func_end npc_reset

	thumb_func_start FieldObjectDirectionToImageAnimId
@ u8 FieldObjectDirectionToImageAnimId(u8 direction)
FieldObjectDirectionToImageAnimId: @ 809295C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DACC
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end FieldObjectDirectionToImageAnimId

	thumb_func_start get_go_image_anim_num
get_go_image_anim_num: @ 809296C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DAD5
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_go_image_anim_num

	thumb_func_start get_go_fast_image_anim_num
get_go_fast_image_anim_num: @ 809297C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DADE
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_go_fast_image_anim_num

	thumb_func_start get_go_faster_image_anim_num
get_go_faster_image_anim_num: @ 809298C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DAE7
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_go_faster_image_anim_num

	thumb_func_start get_go_fastest_image_anim_num
get_go_fastest_image_anim_num: @ 809299C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DAF0
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_go_fastest_image_anim_num

	thumb_func_start sub_80929AC
sub_80929AC: @ 80929AC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DAF9
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929AC

	thumb_func_start sub_80929BC
sub_80929BC: @ 80929BC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB02
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929BC

	thumb_func_start sub_80929CC
sub_80929CC: @ 80929CC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB0B
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929CC

	thumb_func_start sub_80929DC
sub_80929DC: @ 80929DC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB14
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929DC

	thumb_func_start sub_80929EC
sub_80929EC: @ 80929EC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB1D
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929EC

	thumb_func_start sub_80929FC
sub_80929FC: @ 80929FC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB26
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80929FC

	thumb_func_start sub_8092A0C
sub_8092A0C: @ 8092A0C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB2F
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8092A0C

	thumb_func_start sub_8092A1C
sub_8092A1C: @ 8092A1C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB38
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8092A1C

	thumb_func_start sub_8092A2C
sub_8092A2C: @ 8092A2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB41
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8092A2C

	thumb_func_start get_run_image_anim_num
get_run_image_anim_num: @ 8092A3C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB4A
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end get_run_image_anim_num

	thumb_func_start sub_8092A4C
sub_8092A4C: @ 8092A4C
	push {lr}
	adds r2, r0, 0
	ldr r1, =gUnknown_085094AC
	b _08092A64
	.pool
_08092A58:
	ldr r0, [r1]
	cmp r0, r2
	bne _08092A62
	adds r0, r1, 0
	b _08092A6C
_08092A62:
	adds r1, 0x8
_08092A64:
	ldr r0, [r1]
	cmp r0, 0
	bne _08092A58
	movs r0, 0
_08092A6C:
	pop {r1}
	bx r1
	thumb_func_end sub_8092A4C

	thumb_func_start npc_apply_anim_looping
@ void npc_apply_anim_looping(struct npc_state *fieldObject, struct obj *object, u8 anim)
npc_apply_anim_looping: @ 8092A70
	push {r4,lr}
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r0, 0x1]
	lsls r0, 27
	cmp r0, 0
	blt _08092AB2
	adds r0, r4, 0
	adds r0, 0x2A
	strb r2, [r0]
	ldr r0, [r4, 0x8]
	bl sub_8092A4C
	adds r1, r4, 0
	adds r1, 0x2B
	cmp r0, 0
	beq _08092AAA
	ldrb r2, [r1]
	ldrb r3, [r0, 0x4]
	cmp r2, r3
	bne _08092AA0
	ldrb r0, [r0, 0x7]
	b _08092AA8
_08092AA0:
	ldrb r3, [r0, 0x5]
	cmp r2, r3
	bne _08092AAA
	ldrb r0, [r0, 0x6]
_08092AA8:
	strb r0, [r1]
_08092AAA:
	ldrb r1, [r1]
	adds r0, r4, 0
	bl SeekSpriteAnim
_08092AB2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end npc_apply_anim_looping

	thumb_func_start obj_npc_animation_step
@ void obj_npc_animation_step(struct npc_state *fieldObject, struct obj *object, u8 anim)
obj_npc_animation_step: @ 8092AB8
	push {r4,lr}
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r0, 0x1]
	lsls r0, 27
	cmp r0, 0
	blt _08092AF0
	adds r0, r4, 0
	adds r0, 0x2A
	strb r2, [r0]
	ldr r0, [r4, 0x8]
	bl sub_8092A4C
	adds r2, r0, 0
	cmp r2, 0
	beq _08092AF0
	ldrb r1, [r2, 0x5]
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r3, [r2, 0x4]
	cmp r0, r3
	bhi _08092AEA
	ldrb r1, [r2, 0x4]
_08092AEA:
	adds r0, r4, 0
	bl SeekSpriteAnim
_08092AF0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end obj_npc_animation_step

	thumb_func_start sub_8092AF8
sub_8092AF8: @ 8092AF8
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r2, 16
	cmp r0, r2
	ble _08092B12
	movs r0, 0x3
	b _08092B28
_08092B12:
	cmp r0, r2
	bge _08092B1A
	movs r0, 0x4
	b _08092B28
_08092B1A:
	lsls r1, 16
	lsls r0, r3, 16
	cmp r1, r0
	bgt _08092B26
	movs r0, 0x1
	b _08092B28
_08092B26:
	movs r0, 0x2
_08092B28:
	pop {r1}
	bx r1
	thumb_func_end sub_8092AF8

	thumb_func_start npc_set_running_behaviour_etc
npc_set_running_behaviour_etc: @ 8092B2C
	push {r4,lr}
	mov r12, r0
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	strb r1, [r0, 0x6]
	adds r0, 0x21
	strb r3, [r0]
	adds r0, 0x1
	strb r3, [r0]
	ldr r4, =gSprites
	mov r0, r12
	ldrb r2, [r0, 0x4]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r2, r4, 0
	adds r2, 0x1C
	adds r0, r2
	ldr r2, =gUnknown_08505438
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	str r1, [r0]
	mov r0, r12
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r3, [r0, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end npc_set_running_behaviour_etc

	thumb_func_start npc_running_behaviour_by_direction
npc_running_behaviour_by_direction: @ 8092B78
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0850DB53
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end npc_running_behaviour_by_direction

	thumb_func_start sub_8092B88
sub_8092B88: @ 8092B88
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	lsls r5, r1, 24
	lsrs r5, 24
	ldrh r1, [r6, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r6, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
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
	adds r3, r5, 0
	bl npc_block_way
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092B88

	thumb_func_start npc_block_way
@ u8 npc_block_way(struct npc_state *fieldObject, u16 x, u16 y, u8 direction)
npc_block_way: @ 8092BC8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsls r2, 16
	lsls r3, 24
	lsrs r7, r3, 24
	mov r8, r7
	lsrs r0, r1, 16
	mov r9, r0
	asrs r5, r1, 16
	lsrs r0, r2, 16
	mov r10, r0
	asrs r4, r2, 16
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl IsCoordOutsideFieldObjectMovementRect
	lsls r0, 24
	cmp r0, 0
	beq _08092BFE
	movs r0, 0x1
	b _08092C7E
_08092BFE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridIsImpassableAt
	lsls r0, 24
	cmp r0, 0
	bne _08092C40
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapBorderIdAt
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _08092C40
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl IsMetatileDirectionallyImpassable
	lsls r0, 24
	cmp r0, 0
	bne _08092C40
	ldrb r0, [r6, 0x1]
	lsrs r0, 7
	cmp r0, 0
	beq _08092C44
	mov r0, r8
	bl CanCameraMoveInDirection
	cmp r0, 0
	bne _08092C44
_08092C40:
	movs r0, 0x2
	b _08092C7E
_08092C44:
	ldrb r0, [r6, 0xB]
	lsls r0, 28
	lsrs r0, 28
	mov r2, r9
	lsls r1, r2, 16
	asrs r5, r1, 16
	mov r2, r10
	lsls r1, r2, 16
	asrs r4, r1, 16
	adds r1, r5, 0
	adds r2, r4, 0
	bl IsZCoordMismatchAt
	lsls r0, 24
	cmp r0, 0
	beq _08092C68
	movs r0, 0x3
	b _08092C7E
_08092C68:
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl CheckForCollisionBetweenFieldObjects
	lsls r0, 24
	cmp r0, 0
	bne _08092C7C
	movs r0, 0
	b _08092C7E
_08092C7C:
	movs r0, 0x4
_08092C7E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end npc_block_way

	thumb_func_start sub_8092C8C
sub_8092C8C: @ 8092C8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	lsls r1, 16
	lsls r2, 16
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsrs r0, r1, 16
	mov r9, r0
	asrs r6, r1, 16
	lsrs r0, r2, 16
	mov r10, r0
	asrs r5, r2, 16
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl IsCoordOutsideFieldObjectMovementRect
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r6, 0
	adds r1, r5, 0
	bl MapGridIsImpassableAt
	lsls r0, 24
	cmp r0, 0
	bne _08092D04
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapBorderIdAt
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _08092D04
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	mov r3, r8
	bl IsMetatileDirectionallyImpassable
	lsls r0, 24
	cmp r0, 0
	bne _08092D04
	ldrb r0, [r7, 0x1]
	lsrs r0, 7
	cmp r0, 0
	beq _08092D08
	mov r0, r8
	bl CanCameraMoveInDirection
	cmp r0, 0
	bne _08092D08
_08092D04:
	movs r0, 0x2
	orrs r4, r0
_08092D08:
	ldrb r0, [r7, 0xB]
	lsls r0, 28
	lsrs r0, 28
	mov r2, r9
	lsls r1, r2, 16
	asrs r6, r1, 16
	mov r2, r10
	lsls r1, r2, 16
	asrs r5, r1, 16
	adds r1, r6, 0
	adds r2, r5, 0
	bl IsZCoordMismatchAt
	lsls r0, 24
	cmp r0, 0
	beq _08092D30
	movs r0, 0x4
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_08092D30:
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl CheckForCollisionBetweenFieldObjects
	lsls r0, 24
	cmp r0, 0
	beq _08092D48
	movs r0, 0x8
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_08092D48:
	adds r0, r4, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8092C8C

	thumb_func_start IsCoordOutsideFieldObjectMovementRect
@ bool8 IsCoordOutsideFieldObjectMovementRect(struct npc_state *fieldObject, u16 x, u16 y)
IsCoordOutsideFieldObjectMovementRect: @ 8092D58
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r3, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	ldrb r1, [r4, 0x19]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _08092D90
	lsls r1, 28
	lsrs r2, r1, 28
	ldrh r0, [r4, 0xC]
	subs r2, r0, r2
	lsrs r1, 28
	adds r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	lsls r2, 16
	lsls r0, r3, 16
	asrs r3, r0, 16
	cmp r2, r0
	bgt _08092DBC
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r3
	blt _08092DBC
_08092D90:
	ldrb r1, [r4, 0x19]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _08092DC0
	lsls r1, 24
	lsrs r2, r1, 28
	ldrh r0, [r4, 0xE]
	subs r2, r0, r2
	lsrs r1, 28
	adds r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	lsls r2, 16
	lsls r0, r5, 16
	asrs r3, r0, 16
	cmp r2, r0
	bgt _08092DBC
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r3
	bge _08092DC0
_08092DBC:
	movs r0, 0x1
	b _08092DC2
_08092DC0:
	movs r0, 0
_08092DC2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsCoordOutsideFieldObjectMovementRect

	thumb_func_start IsMetatileDirectionallyImpassable
@ bool8 IsMetatileDirectionallyImpassable(struct npc_state *fieldObject, u16 x, u16 y, u8 direction)
IsMetatileDirectionallyImpassable: @ 8092DC8
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 24
	ldr r1, =gUnknown_0850DB5C
	lsrs r3, 22
	subs r5, r3, 0x4
	adds r1, r5, r1
	ldrb r0, [r0, 0x1E]
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08092E0A
	ldr r4, =gUnknown_0850DB6C
	adds r4, r5, r4
	lsls r0, r6, 16
	asrs r0, 16
	lsls r1, r7, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _08092E18
_08092E0A:
	movs r0, 0x1
	b _08092E1A
	.pool
_08092E18:
	movs r0, 0
_08092E1A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end IsMetatileDirectionallyImpassable

	thumb_func_start CheckForCollisionBetweenFieldObjects
@ bool8 CheckForCollisionBetweenFieldObjects(struct npc_state *fieldObject, u16 x, u16 y)
CheckForCollisionBetweenFieldObjects: @ 8092E20
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	movs r4, 0
	lsls r2, 16
	asrs r5, r2, 16
_08092E2E:
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r2, r0, r1
	ldrb r0, [r2]
	lsls r0, 31
	cmp r0, 0
	beq _08092E88
	cmp r2, r6
	beq _08092E88
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	lsls r0, r7, 16
	asrs r3, r0, 16
	cmp r1, r3
	bne _08092E58
	movs r1, 0x12
	ldrsh r0, [r2, r1]
	cmp r0, r5
	beq _08092E68
_08092E58:
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	cmp r0, r3
	bne _08092E88
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r5
	bne _08092E88
_08092E68:
	ldrb r0, [r6, 0xB]
	lsls r0, 28
	lsrs r0, 28
	ldrb r1, [r2, 0xB]
	lsls r1, 28
	lsrs r1, 28
	bl AreZCoordsCompatible
	lsls r0, 24
	cmp r0, 0
	beq _08092E88
	movs r0, 0x1
	b _08092E94
	.pool
_08092E88:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08092E2E
	movs r0, 0
_08092E94:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckForCollisionBetweenFieldObjects

	thumb_func_start sub_8092E9C
sub_8092E9C: @ 8092E9C
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08092EE8
	ldr r3, =gSprites
	ldr r2, =gMapObjects
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x3C]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08092EE8
	movs r0, 0x1
	b _08092EEA
	.pool
_08092EE8:
	movs r0, 0
_08092EEA:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8092E9C

	thumb_func_start sub_8092EF0
sub_8092EF0: @ 8092EF0
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08092F2E
	ldr r3, =gSprites
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
	adds r1, r3
	ldrh r2, [r1, 0x3C]
	movs r0, 0x4
	orrs r0, r2
	strh r0, [r1, 0x3C]
_08092F2E:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8092EF0

	thumb_func_start MoveCoords
@ void MoveCoords(u8 direction, u16 *x, u16 *y)
MoveCoords: @ 8092F3C
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gUnknown_0850DB7C
	lsrs r0, 22
	adds r0, r3
	ldrh r3, [r0]
	ldrh r4, [r1]
	adds r3, r4
	strh r3, [r1]
	ldrh r0, [r0, 0x2]
	ldrh r1, [r2]
	adds r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MoveCoords

	thumb_func_start sub_8092F60
sub_8092F60: @ 8092F60
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gUnknown_0850DB7C
	lsrs r0, 22
	adds r0, r3
	ldrh r3, [r0]
	lsls r3, 4
	ldrh r4, [r1]
	adds r3, r4
	strh r3, [r1]
	ldrh r0, [r0, 0x2]
	lsls r0, 4
	ldrh r1, [r2]
	adds r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8092F60

	thumb_func_start sub_8092F88
sub_8092F88: @ 8092F88
	push {r4-r7,lr}
	adds r4, r1, 0
	ldr r1, [sp, 0x14]
	lsls r0, 24
	lsls r3, 16
	lsrs r3, 16
	adds r7, r3, 0
	lsls r1, 16
	lsrs r6, r1, 16
	mov r12, r6
	ldr r1, =gUnknown_0850DB7C
	lsrs r0, 22
	adds r5, r0, r1
	movs r0, 0
	ldrsh r1, [r5, r0]
	cmp r1, 0
	ble _08092FB4
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r3, [r4]
	adds r0, r3
	strh r0, [r4]
_08092FB4:
	cmp r1, 0
	bge _08092FC2
	ldrh r1, [r4]
	lsls r0, r7, 16
	asrs r0, 16
	subs r1, r0
	strh r1, [r4]
_08092FC2:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	cmp r1, 0
	ble _08092FD4
	lsls r0, r6, 16
	asrs r0, 16
	ldrh r3, [r2]
	adds r0, r3
	strh r0, [r2]
_08092FD4:
	cmp r1, 0
	bge _08092FE4
	ldrh r1, [r2]
	mov r3, r12
	lsls r0, r3, 16
	asrs r0, 16
	subs r1, r0
	strh r1, [r2]
_08092FE4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8092F88

	thumb_func_start sub_8092FF0
sub_8092FF0: @ 8092FF0
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r4, [r5]
	ldrh r4, [r4]
	lsls r0, 16
	asrs r0, 16
	subs r0, r4
	lsls r0, 4
	strh r0, [r2]
	ldr r0, [r5]
	ldrh r0, [r0, 0x2]
	lsls r1, 16
	asrs r1, 16
	subs r1, r0
	lsls r1, 4
	strh r1, [r3]
	ldr r1, =gUnknown_03005DEC
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r2]
	ldr r1, =gUnknown_03005DE8
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8092FF0

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

	thumb_func_start FieldObjectCheckIfSpecialAnimFinishedOrInactive
@ u8 FieldObjectCheckIfSpecialAnimFinishedOrInactive(struct npc_state *fieldObject)
FieldObjectCheckIfSpecialAnimFinishedOrInactive: @ 8093270
	push {lr}
	ldrb r1, [r0]
	lsls r0, r1, 25
	cmp r0, 0
	blt _0809327E
	movs r0, 0x10
	b _08093280
_0809327E:
	lsrs r0, r1, 7
_08093280:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectCheckIfSpecialAnimFinishedOrInactive

	thumb_func_start FieldObjectClearAnimIfSpecialAnimFinished
@ u8 FieldObjectClearAnimIfSpecialAnimFinished(struct npc_state *fieldObject)
FieldObjectClearAnimIfSpecialAnimFinished: @ 8093284
	push {r4,r5,lr}
	adds r5, r0, 0
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0809329E
	cmp r4, 0x10
	beq _0809329E
	adds r0, r5, 0
	bl FieldObjectClearAnimIfSpecialAnimActive
_0809329E:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end FieldObjectClearAnimIfSpecialAnimFinished

	thumb_func_start FieldObjectGetSpecialAnim
@ u8 FieldObjectGetSpecialAnim(struct npc_state *fieldObject)
FieldObjectGetSpecialAnim: @ 80932A8
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _080932B8
	movs r0, 0xFF
	b _080932BA
_080932B8:
	ldrb r0, [r1, 0x1C]
_080932BA:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectGetSpecialAnim

	thumb_func_start FieldObjectStep
@ void FieldObjectStep(struct npc_state *fieldObject, struct obj *object, bool8 ( *callback)(struct npc_state *fieldObject, struct obj *object))
FieldObjectStep: @ 80932C0
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	bl DoGroundEffects_OnSpawn
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80964E8
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080932EA
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectExecSpecialAnim
	b _08093300
_080932EA:
	ldrb r0, [r4, 0x1]
	lsls r0, 31
	cmp r0, 0
	bne _08093300
_080932F2:
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r6
	lsls r0, 24
	cmp r0, 0
	bne _080932F2
_08093300:
	adds r0, r4, 0
	adds r1, r5, 0
	bl DoGroundEffects_OnBeginStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl DoGroundEffects_OnFinishStep
	adds r0, r4, 0
	adds r1, r5, 0
	bl npc_obj_transfer_image_anim_pause_flag
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8096518
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldObjectUpdateSubpriority
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end FieldObjectStep

	thumb_func_start GetFaceDirectionAnimId
@ u8 GetFaceDirectionAnimId(u8 direction)
GetFaceDirectionAnimId: @ 8093330
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0850DBA0
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x4
	bls _08093348
	movs r4, 0
_08093348:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetFaceDirectionAnimId

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
	ldr r1, =gUnknown_02038C08
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
	ldr r1, =gUnknown_02038C08
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
	ldr r1, =gUnknown_02038C08
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
	bl sub_8097978
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
	bl sub_809797C
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
	bl sub_8097978
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
	bl sub_809797C
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
