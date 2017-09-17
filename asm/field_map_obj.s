	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
