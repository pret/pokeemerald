	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80FC4F4
sub_80FC4F4: @ 80FC4F4
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r4, r1, 16
	lsrs r4, 16
	ldr r5, =0x0201c000
	adds r0, r5, 0
	adds r1, r2, 0
	adds r2, r4, 0
	bl memcpy
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl link_0800A448
	lsls r0, 24
	cmp r0, 0
	bne _080FC528
	movs r0, 0
	b _080FC52A
	.pool
_080FC528:
	movs r0, 0x1
_080FC52A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80FC4F4

	thumb_func_start sub_80FC530
sub_80FC530: @ 80FC530
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0x80
	lsls r4, 17
	lsls r4, r5
	lsrs r4, 24
	bl sub_800A550
	ands r4, r0
	cmp r4, 0
	beq _080FC552
	adds r0, r5, 0
	bl sub_800A5EC
	movs r0, 0x1
	b _080FC554
_080FC552:
	movs r0, 0
_080FC554:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80FC530

	thumb_func_start sub_80FC55C
sub_80FC55C: @ 80FC55C
	push {r4,lr}
	bl sub_800A550
	adds r4, r0, 0
	bl sub_800A9D8
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080FC574
	movs r0, 0
	b _080FC57A
_080FC574:
	bl sub_800A5B4
	movs r0, 0x1
_080FC57A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80FC55C

	thumb_func_start sub_80FC580
sub_80FC580: @ 80FC580
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r5, =0x03005e00
	ldr r6, =sub_80FC5C0
	ldr r4, =0x020223c4
	movs r3, 0xFF
_080FC590:
	lsls r0, r1, 8
	adds r0, r4
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _080FC590
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r5
	movs r1, 0
	strh r1, [r0, 0x8]
	str r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC580

	thumb_func_start sub_80FC5C0
sub_80FC5C0: @ 80FC5C0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_80FC5DC
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80FC5C0

	thumb_func_start sub_80FC5DC
sub_80FC5DC: @ 80FC5DC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =0x03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _080FC650
	bl link_get_multiplayer_id
	ldr r1, =0x02039f25
	strb r0, [r1]
	bl sub_8009FCC
	ldr r4, =0x02039f30
	strb r0, [r4]
	ldr r1, =0x02039f2a
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x030030fc
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080FC60C
	movs r0, 0x3
	strb r0, [r1]
_080FC60C:
	movs r3, 0
	ldrb r2, [r4]
	cmp r3, r2
	bge _080FC64A
	ldr r1, =0x020229e8
	ldrb r0, [r1]
	subs r0, 0x1
	adds r6, r4, 0
	cmp r0, 0x1
	bls _080FC63A
	adds r4, r2, 0
	adds r2, r1, 0
	movs r5, 0xFF
_080FC626:
	adds r2, 0x1C
	adds r3, 0x1
	cmp r3, r4
	bge _080FC64A
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	subs r0, 0x1
	cmp r0, 0x1
	bhi _080FC626
_080FC63A:
	ldrb r6, [r6]
	cmp r3, r6
	bge _080FC64A
	ldr r0, =0x02039f2a
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080FC64A:
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
_080FC650:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC5DC

	thumb_func_start sub_80FC670
sub_80FC670: @ 80FC670
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x02039f2a
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080FC698
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FC6A0
	cmp r0, 0x1
	beq _080FC6AE
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080FC6B4
_080FC698:
	movs r0, 0x1
	b _080FC6B6
	.pool
_080FC6A0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FC6B4
	bl sub_800ADF8
_080FC6AE:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_080FC6B4:
	movs r0, 0
_080FC6B6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80FC670

	thumb_func_start sub_80FC6BC
sub_80FC6BC: @ 80FC6BC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r6, r7, 2
	adds r0, r6, r7
	lsls r4, r0, 3
	ldr r5, =0x03005e08
	adds r0, r4, r5
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	bne _080FC6DC
	b _080FC7F4
_080FC6DC:
	adds r0, r5, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080FC758
	cmp r0, 0x1
	bgt _080FC6F8
	cmp r0, 0
	beq _080FC6FE
	b _080FC7DC
	.pool
_080FC6F8:
	cmp r0, 0xA
	beq _080FC7C0
	b _080FC7DC
_080FC6FE:
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _080FC738
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FC7F4
	ldr r0, =0x020228c4
	ldr r1, =0x02039f25
	ldrb r1, [r1]
	lsls r1, 6
	ldr r2, =0x02039e00
	adds r1, r2
	movs r2, 0x40
	bl memcpy
	movs r0, 0xA
	strh r0, [r4, 0x8]
	b _080FC7F4
	.pool
_080FC738:
	ldr r0, =0x020228c4
	ldr r1, =0x02039f25
	ldrb r1, [r1]
	lsls r1, 6
	ldr r2, =0x02039e00
	adds r1, r2
	movs r2, 0x40
	bl memcpy
	b _080FC7D6
	.pool
_080FC758:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FC7F4
	movs r5, 0
	ldr r0, =0x02039f30
	mov r8, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _080FC798
	ldr r6, =0x020229e8
_080FC770:
	lsls r4, r5, 6
	ldr r0, =0x02039e00
	adds r4, r0
	lsls r1, r5, 8
	ldr r0, =0x020223c4
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x40
	bl memcpy
	ldrh r1, [r6, 0x1A]
	adds r0, r4, 0
	bl sub_80DFA08
	adds r6, 0x1C
	adds r5, 0x1
	ldr r0, =0x02039f30
	ldrb r0, [r0]
	cmp r5, r0
	blt _080FC770
_080FC798:
	ldr r0, =0x03005e00
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080FC7F4
	.pool
_080FC7C0:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	ble _080FC7F4
	movs r0, 0x2
	bl sub_800A4D8
_080FC7D6:
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _080FC7F4
_080FC7DC:
	ldr r0, =0x03005e00
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r0, [r1, 0x1E]
	strh r0, [r1, 0x20]
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
_080FC7F4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC6BC

	thumb_func_start sub_80FC804
sub_80FC804: @ 80FC804
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080FC830
	cmp r0, 0x1
	beq _080FC858
	movs r0, 0
	strh r0, [r5, 0x8]
	adds r0, r2, 0
	bl SwitchTaskToFollowupFunc
	b _080FC880
	.pool
_080FC830:
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _080FC87A
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FC880
	ldr r0, =0x03005d80
	movs r1, 0x4
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FC880
	b _080FC87A
	.pool
_080FC858:
	movs r0, 0
	bl sub_80FC530
	lsls r0, 24
	cmp r0, 0
	beq _080FC880
	ldr r0, =0x03005d80
	ldr r4, =0x020223c4
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
	ldr r0, =0x030060b8
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
_080FC87A:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080FC880:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC804

	thumb_func_start sub_80FC894
sub_80FC894: @ 80FC894
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r8, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r7, =0x03005e08
	adds r0, r5, r7
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _080FC986
	movs r1, 0x8
	negs r1, r1
	adds r1, r7
	mov r9, r1
	adds r4, r5, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080FC90C
	cmp r0, 0x1
	bgt _080FC8D8
	cmp r0, 0
	beq _080FC8DE
	b _080FC96E
	.pool
_080FC8D8:
	cmp r0, 0xA
	beq _080FC954
	b _080FC96E
_080FC8DE:
	ldr r1, =0x020228c4
	ldrh r0, [r4, 0x1A]
	strb r0, [r1]
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _080FC904
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FC986
	movs r0, 0xA
	strh r0, [r4, 0x8]
	b _080FC986
	.pool
_080FC904:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080FC986
_080FC90C:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FC986
	movs r3, 0
	ldr r1, =0x02039f30
	ldrb r0, [r1]
	cmp r3, r0
	bge _080FC93A
	ldr r4, =0x020223c4
	adds r0, r7, 0x2
	adds r2, r5, r0
	movs r5, 0x80
	lsls r5, 1
_080FC92A:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, r5
	adds r2, 0x2
	adds r3, 0x1
	ldrb r0, [r1]
	cmp r3, r0
	blt _080FC92A
_080FC93A:
	mov r0, r8
	adds r1, r0, r6
	lsls r1, 3
	add r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080FC986
	.pool
_080FC954:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	ble _080FC986
	movs r0, 0x2
	bl sub_800A4D8
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _080FC986
_080FC96E:
	ldr r0, =0x03005e00
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r0, [r1, 0x1E]
	strh r0, [r1, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
_080FC986:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC894

	thumb_func_start sub_80FC998
sub_80FC998: @ 80FC998
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FC9C4
	cmp r0, 0x1
	beq _080FC9E0
	movs r0, 0
	strh r0, [r4, 0x8]
	adds r0, r2, 0
	bl SwitchTaskToFollowupFunc
	b _080FC9F0
	.pool
_080FC9C4:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FC9F0
	ldr r0, =0x02039f25
	movs r1, 0x1
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FC9F0
	b _080FC9EA
	.pool
_080FC9E0:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FC9F0
_080FC9EA:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080FC9F0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FC998

	thumb_func_start sub_80FC9F8
sub_80FC9F8: @ 80FC9F8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =0x03005e00
	mov r8, r0
	lsls r7, r5, 2
	adds r0, r7, r5
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FCA30
	cmp r0, 0x1
	beq _080FCA68
	movs r0, 0
	strh r0, [r4, 0x8]
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
	b _080FCAB2
	.pool
_080FCA30:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCAB2
	ldr r0, =0x02039f34
	ldr r2, [r0]
	ldr r0, =0x02039f25
	ldrb r0, [r0]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r0, [r2, 0x4]
	adds r0, r1
	adds r0, 0x6
	movs r1, 0x2
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FCAB2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080FCAB2
	.pool
_080FCA68:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCAB2
	movs r2, 0
	ldr r6, =0x02039f30
	mov r9, r8
	mov r12, r7
	ldrb r0, [r6]
	cmp r2, r0
	bge _080FCAA4
	ldr r1, =0x02039f34
	mov r8, r1
	ldr r4, =0x020223c4
	movs r3, 0
	movs r7, 0x80
	lsls r7, 1
_080FCA8C:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r3, r0
	ldrh r1, [r4]
	strh r1, [r0, 0x6]
	adds r4, r7
	adds r3, 0x1C
	adds r2, 0x1
	ldrb r0, [r6]
	cmp r2, r0
	blt _080FCA8C
_080FCAA4:
	mov r0, r12
	adds r1, r0, r5
	lsls r1, 3
	add r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_080FCAB2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FC9F8

	thumb_func_start sub_80FCACC
sub_80FCACC: @ 80FCACC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	adds r3, r1, 0
	cmp r0, 0xB
	bls _080FCAE8
	b _080FCC78
_080FCAE8:
	lsls r0, 2
	ldr r1, =_080FCAFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FCAFC:
	.4byte _080FCB2C
	.4byte _080FCB44
	.4byte _080FCB6C
	.4byte _080FCB90
	.4byte _080FCBA4
	.4byte _080FCB6C
	.4byte _080FCBCC
	.4byte _080FCBE0
	.4byte _080FCB6C
	.4byte _080FCC08
	.4byte _080FCC38
	.4byte _080FCB6C
_080FCB2C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _080FCB38
	b _080FCC82
_080FCB38:
	ldr r0, =0x02039f08
	movs r1, 0x8
	b _080FCC16
	.pool
_080FCB44:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	bne _080FCB50
	b _080FCC82
_080FCB50:
	ldr r0, =0x02039f08
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x8
	b _080FCC50
	.pool
_080FCB6C:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0xA]
	adds r1, r0, 0x1
	strh r1, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bgt _080FCB84
	b _080FCC82
_080FCB84:
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _080FCC82
_080FCB90:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f10
	movs r1, 0x8
	b _080FCC16
	.pool
_080FCBA4:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f10
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x8
	b _080FCC50
	.pool
_080FCBCC:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f18
	movs r1, 0x8
	b _080FCC16
	.pool
_080FCBE0:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f18
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x8
	b _080FCC50
	.pool
_080FCC08:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f20
	movs r1, 0x4
_080FCC16:
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FCC82
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080FCC82
	.pool
_080FCC38:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCC82
	ldr r0, =0x02039f20
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x4
_080FCC50:
	bl memcpy
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080FCC82
	.pool
_080FCC78:
	movs r0, 0
	strh r0, [r2, 0x8]
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
_080FCC82:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FCACC

	thumb_func_start sub_80FCC88
sub_80FCC88: @ 80FCC88
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	adds r3, r1, 0
	cmp r0, 0xB
	bls _080FCCA4
	b _080FCE38
_080FCCA4:
	lsls r0, 2
	ldr r1, =_080FCCB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FCCB8:
	.4byte _080FCCE8
	.4byte _080FCD04
	.4byte _080FCD30
	.4byte _080FCD54
	.4byte _080FCD6C
	.4byte _080FCD30
	.4byte _080FCD98
	.4byte _080FCDB0
	.4byte _080FCD30
	.4byte _080FCDC8
	.4byte _080FCDF8
	.4byte _080FCD30
_080FCCE8:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	bne _080FCCF4
	b _080FCE42
_080FCCF4:
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	movs r1, 0x70
	b _080FCDD6
	.pool
_080FCD04:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	bne _080FCD10
	b _080FCE42
_080FCD10:
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x70
	b _080FCE10
	.pool
_080FCD30:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0xA]
	adds r1, r0, 0x1
	strh r1, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bgt _080FCD48
	b _080FCE42
_080FCD48:
	movs r0, 0
	strh r0, [r2, 0xA]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _080FCE42
_080FCD54:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	movs r1, 0x14
	b _080FCDD6
	.pool
_080FCD6C:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x14
	b _080FCE10
	.pool
_080FCD98:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	b _080FCDD4
	.pool
_080FCDB0:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f34
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	b _080FCE04
	.pool
_080FCDC8:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f26
_080FCDD4:
	movs r1, 0x4
_080FCDD6:
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FCE42
	ldr r0, =0x03005e00
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080FCE42
	.pool
_080FCDF8:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCE42
	ldr r0, =0x02039f26
_080FCE04:
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x4
_080FCE10:
	bl memcpy
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _080FCE42
	.pool
_080FCE38:
	movs r0, 0
	strh r0, [r2, 0x8]
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
_080FCE42:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80FCC88

	thumb_func_start sub_80FCE48
sub_80FCE48: @ 80FCE48
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r8, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r7, =0x03005e08
	adds r0, r5, r7
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _080FCF2E
	movs r1, 0x8
	negs r1, r1
	adds r1, r7
	mov r9, r1
	adds r4, r5, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080FCEC0
	cmp r0, 0x1
	bgt _080FCE8C
	cmp r0, 0
	beq _080FCE92
	b _080FCF16
	.pool
_080FCE8C:
	cmp r0, 0xA
	beq _080FCEFC
	b _080FCF16
_080FCE92:
	ldr r1, =0x020228c4
	movs r0, 0x6E
	strb r0, [r1]
	bl link_get_multiplayer_id
	lsls r0, 24
	cmp r0, 0
	bne _080FCEB8
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCF2E
	movs r0, 0xA
	strh r0, [r4, 0x8]
	b _080FCF2E
	.pool
_080FCEB8:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080FCF2E
_080FCEC0:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCF2E
	mov r1, r8
	mov r8, r9
	ldr r4, =0x020223c4
	adds r0, r7, 0
	adds r0, 0xA
	adds r2, r5, r0
	movs r5, 0x80
	lsls r5, 1
	movs r3, 0x3
_080FCEDC:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, r5
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _080FCEDC
	adds r1, r6
	lsls r1, 3
	add r1, r8
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _080FCF2E
	.pool
_080FCEFC:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	ble _080FCF2E
	movs r0, 0x2
	bl sub_800A4D8
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _080FCF2E
_080FCF16:
	ldr r0, =0x03005e00
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	strh r0, [r1, 0x1E]
	strh r0, [r1, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
_080FCF2E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FCE48

	thumb_func_start sub_80FCF40
sub_80FCF40: @ 80FCF40
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r4, r0, 3
	ldr r6, =0x03005e08
	adds r0, r4, r6
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _080FCFBE
	adds r0, r6, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FCF80
	cmp r0, 0x1
	beq _080FCF9C
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
	b _080FCFBE
	.pool
_080FCF80:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FCFBE
	ldr r0, =0x02039f00
	movs r1, 0x8
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FCFBE
	b _080FCFB8
	.pool
_080FCF9C:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FCFBE
	ldr r0, =0x02039f00
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x8
	bl memcpy
_080FCFB8:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080FCFBE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FCF40

	thumb_func_start sub_80FCFD0
sub_80FCFD0: @ 80FCFD0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r4, r0, 3
	ldr r6, =0x03005e08
	adds r0, r4, r6
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _080FD04E
	adds r0, r6, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080FD010
	cmp r0, 0x1
	beq _080FD02C
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
	b _080FD04E
	.pool
_080FD010:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080FD04E
	ldr r0, =0x02039f26
	movs r1, 0x4
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _080FD04E
	b _080FD048
	.pool
_080FD02C:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _080FD04E
	ldr r0, =0x02039f26
	ldr r1, =0x02039f2b
	ldrb r1, [r1]
	lsls r1, 8
	ldr r2, =0x020223c4
	adds r1, r2
	movs r2, 0x4
	bl memcpy
_080FD048:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080FD04E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FCFD0

	.align 2, 0 @ Don't pad with nop.
