	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
