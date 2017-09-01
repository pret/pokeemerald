	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8097404
@ bool8 sub_8097404(struct npc_state *fieldObject)
sub_8097404: @ 8097404
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0xA0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	bne _0809748C
	ldrb r0, [r5, 0x1]
	movs r4, 0x1
	orrs r0, r4
	strb r0, [r5, 0x1]
	ldr r3, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x2C
	ldrb r1, [r0]
	lsls r1, 25
	lsrs r1, 31
	lsls r1, 7
	ldrb r2, [r5, 0x2]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x2]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x2C
	ldrb r1, [r0]
	lsrs r1, 7
	ands r1, r4
	ldrb r2, [r5, 0x3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0
	b _0809748E
	.pool
_0809748C:
	movs r0, 0x1
_0809748E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8097404

	thumb_func_start player_bitmagic
@ void player_bitmagic()
player_bitmagic: @ 8097494
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_02037350
_0809749A:
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _080974B8
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	beq _080974B8
	adds r0, r1, 0
	bl sub_8097404
_080974B8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _0809749A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end player_bitmagic

	thumb_func_start sub_80974D0
sub_80974D0: @ 80974D0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r6, =gUnknown_02037350
_080974DA:
	cmp r4, r5
	beq _080974FC
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r6
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _080974FC
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	beq _080974FC
	adds r0, r1, 0
	bl sub_8097404
_080974FC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _080974DA
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80974D0

	thumb_func_start npc_sync_anim_pause_bits
@ void npc_sync_anim_pause_bits(struct npc_state *fieldObject)
npc_sync_anim_pause_bits: @ 8097514
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r2, [r5]
	ldr r1, =0x00000101
	adds r0, r1, 0
	ands r0, r2
	cmp r0, r1
	bne _0809756C
	ldrb r1, [r5, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r4, =gSprites
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r5, 0x2]
	adds r1, 0x2C
	lsrs r2, 7
	lsls r2, 6
	ldrb r3, [r1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrb r1, [r5, 0x3]
	lsls r1, 31
	lsrs r1, 31
	adds r2, 0x2C
	lsls r1, 7
	ldrb r3, [r2]
	movs r0, 0x7F
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0809756C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end npc_sync_anim_pause_bits

	thumb_func_start sub_809757C
sub_809757C: @ 809757C
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_02037350
_08097582:
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _08097598
	adds r0, r1, 0
	bl npc_sync_anim_pause_bits
_08097598:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08097582
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809757C

	thumb_func_start little_step
@ void little_step(struct obj *object, u8 direction)
little_step: @ 80975AC
	lsls r1, 24
	ldr r2, =gUnknown_0850DB7C
	lsrs r1, 22
	adds r1, r2
	ldrh r2, [r1]
	ldrh r3, [r0, 0x20]
	adds r2, r3
	strh r2, [r0, 0x20]
	ldrh r1, [r1, 0x2]
	ldrh r2, [r0, 0x22]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end little_step

	thumb_func_start double_little_steps
double_little_steps: @ 80975CC
	lsls r1, 24
	ldr r2, =gUnknown_0850DB7C
	lsrs r1, 22
	adds r1, r2
	ldrh r2, [r1]
	lsls r2, 1
	ldrh r3, [r0, 0x20]
	adds r2, r3
	strh r2, [r0, 0x20]
	ldrh r1, [r1, 0x2]
	lsls r1, 1
	ldrh r2, [r0, 0x22]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end double_little_steps

	thumb_func_start triple_little_steps
triple_little_steps: @ 80975F0
	lsls r1, 24
	ldr r2, =gUnknown_0850DB7C
	lsrs r1, 22
	adds r1, r2
	ldrh r2, [r1]
	lsls r3, r2, 1
	adds r2, r3
	ldrh r3, [r0, 0x20]
	adds r2, r3
	strh r2, [r0, 0x20]
	ldrh r1, [r1, 0x2]
	lsls r2, r1, 1
	adds r1, r2
	ldrh r2, [r0, 0x22]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end triple_little_steps

	thumb_func_start quad_little_steps
quad_little_steps: @ 8097618
	lsls r1, 24
	ldr r2, =gUnknown_0850DB7C
	lsrs r1, 22
	adds r1, r2
	ldrh r2, [r1]
	lsls r2, 2
	ldrh r3, [r0, 0x20]
	adds r2, r3
	strh r2, [r0, 0x20]
	ldrh r1, [r1, 0x2]
	lsls r1, 2
	ldrh r2, [r0, 0x22]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end quad_little_steps

	thumb_func_start oct_little_steps
@ void oct_little_steps(struct obj *object, u8 direction)
oct_little_steps: @ 809763C
	lsls r1, 24
	ldr r2, =gUnknown_0850DB7C
	lsrs r1, 22
	adds r1, r2
	ldrh r2, [r1]
	lsls r2, 3
	ldrh r3, [r0, 0x20]
	adds r2, r3
	strh r2, [r0, 0x20]
	ldrh r1, [r1, 0x2]
	lsls r1, 3
	ldrh r2, [r0, 0x22]
	adds r1, r2
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end oct_little_steps

	thumb_func_start oamt_npc_ministep_reset
@ void oamt_npc_ministep_reset(struct obj *object, u8 direction, u8 speed)
oamt_npc_ministep_reset: @ 8097660
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	strh r1, [r0, 0x34]
	strh r2, [r0, 0x36]
	strh r3, [r0, 0x38]
	bx lr
	thumb_func_end oamt_npc_ministep_reset

	thumb_func_start obj_npc_ministep
@ bool8 obj_npc_ministep(struct obj *object)
obj_npc_ministep: @ 8097674
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_0850E768
	movs r0, 0x36
	ldrsh r2, [r4, r0]
	lsls r0, r2, 1
	adds r0, r5
	movs r3, 0x38
	ldrsh r1, [r4, r3]
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080976D4
	ldr r1, =gUnknown_0850E754
	lsls r0, r2, 2
	adds r0, r1
	movs r1, 0x38
	ldrsh r2, [r4, r1]
	ldr r0, [r0]
	lsls r2, 2
	adds r2, r0
	ldrh r1, [r4, 0x34]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, [r2]
	adds r0, r4, 0
	bl _call_via_r2
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	lsls r1, 1
	adds r1, r5
	lsls r0, 16
	asrs r0, 16
	movs r3, 0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	blt _080976D4
	movs r0, 0x1
	b _080976D6
	.pool
_080976D4:
	movs r0, 0
_080976D6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end obj_npc_ministep

	thumb_func_start sub_80976DC
@ void sub_80976DC(struct obj *object, u8 direction)
sub_80976DC: @ 80976DC
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	strh r1, [r0, 0x34]
	strh r2, [r0, 0x36]
	strh r2, [r0, 0x38]
	bx lr
	thumb_func_end sub_80976DC

	thumb_func_start sub_80976EC
@ bool8 sub_80976EC(struct obj *object)
sub_80976EC: @ 80976EC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x36]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809770C
	ldrh r1, [r4, 0x34]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl little_step
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
_0809770C:
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	bgt _0809771E
	movs r0, 0
	b _08097720
_0809771E:
	movs r0, 0x1
_08097720:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80976EC

	thumb_func_start sub_8097728
sub_8097728: @ 8097728
	ldr r1, =gUnknown_0850E7BA
	lsls r0, 16
	asrs r0, 16
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_8097728

	thumb_func_start sub_809773C
sub_809773C: @ 809773C
	ldr r1, =gUnknown_0850E772
	lsls r0, 16
	asrs r0, 16
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_809773C

	thumb_func_start sub_8097750
sub_8097750: @ 8097750
	movs r1, 0
	strh r1, [r0, 0x3A]
	strh r1, [r0, 0x3C]
	bx lr
	thumb_func_end sub_8097750

	thumb_func_start sub_8097758
sub_8097758: @ 8097758
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0809778E
	cmp r0, 0x1
	bgt _08097770
	cmp r0, 0
	beq _0809777A
	b _080977F2
_08097770:
	cmp r0, 0x2
	beq _080977B6
	cmp r0, 0x3
	beq _080977CA
	b _080977F2
_0809777A:
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	adds r0, r1
	strh r0, [r5, 0x24]
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	b _080977E8
_0809778E:
	ldrh r0, [r5, 0x3A]
	movs r4, 0x47
	subs r0, r4, r0
	lsls r0, 16
	asrs r0, 16
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	subs r1, r0
	strh r1, [r5, 0x24]
	ldrh r0, [r5, 0x3A]
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_8097728
	ldrh r2, [r5, 0x26]
	adds r0, r2
	b _080977F0
_080977B6:
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	bl sub_809773C
	ldrh r1, [r5, 0x24]
	subs r1, r0
	strh r1, [r5, 0x24]
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	b _080977E8
_080977CA:
	ldrh r0, [r5, 0x3A]
	movs r4, 0x47
	subs r0, r4, r0
	lsls r0, 16
	asrs r0, 16
	bl sub_809773C
	ldrh r2, [r5, 0x24]
	adds r0, r2
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x3A]
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
_080977E8:
	bl sub_8097728
	ldrh r1, [r5, 0x26]
	adds r0, r1
_080977F0:
	strh r0, [r5, 0x26]
_080977F2:
	ldrh r0, [r5, 0x3A]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x3A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x48
	bne _0809780A
	strh r1, [r5, 0x3A]
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
_0809780A:
	movs r2, 0x3C
	ldrsh r0, [r5, r2]
	cmp r0, 0x4
	bne _08097818
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	movs r6, 0x1
_08097818:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8097758

	thumb_func_start sub_8097820
sub_8097820: @ 8097820
	lsls r1, 24
	ldr r2, =gUnknown_0850E834
	lsrs r1, 22
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	ldrsb r0, [r1, r0]
	bx lr
	.pool
	thumb_func_end sub_8097820

	thumb_func_start sub_809783C
sub_809783C: @ 809783C
	push {r4,lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r4, 0
	strh r1, [r0, 0x34]
	strh r2, [r0, 0x36]
	strh r3, [r0, 0x38]
	strh r4, [r0, 0x3A]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_809783C

	thumb_func_start sub_809785C
sub_809785C: @ 809785C
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_0850E840
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	add r5, sp, 0x8
	ldr r1, =gUnknown_0850E846
	adds r0, r5, 0
	movs r2, 0x3
	bl memcpy
	movs r6, 0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809788E
	ldrh r1, [r4, 0x34]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl little_step
_0809788E:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	adds r1, r5, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r4, 0x38]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8097820
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x3A]
	adds r1, 0x1
	strh r1, [r4, 0x3A]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r1, 16
	asrs r0, 17
	cmp r1, r0
	bne _080978C8
	movs r6, 0x1
_080978C8:
	cmp r1, r2
	blt _080978D2
	movs r0, 0
	strh r0, [r4, 0x26]
	movs r6, 0xFF
_080978D2:
	adds r0, r6, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809785C

	thumb_func_start sub_80978E4
sub_80978E4: @ 80978E4
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldr r1, =gUnknown_0850E84A
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	add r4, sp, 0x8
	ldr r1, =gUnknown_0850E850
	adds r0, r4, 0
	movs r2, 0x3
	bl memcpy
	movs r6, 0
	movs r1, 0x36
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08097920
	ldrh r1, [r5, 0x3A]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08097920
	ldrh r1, [r5, 0x34]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl little_step
_08097920:
	movs r2, 0x3A
	ldrsh r0, [r5, r2]
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	adds r1, r4, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r5, 0x38]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8097820
	strh r0, [r5, 0x26]
	ldrh r1, [r5, 0x3A]
	adds r1, 0x1
	strh r1, [r5, 0x3A]
	movs r2, 0x36
	ldrsh r0, [r5, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r1, 16
	asrs r0, 17
	cmp r1, r0
	bne _0809795A
	movs r6, 0x1
_0809795A:
	cmp r1, r2
	blt _08097964
	movs r0, 0
	strh r0, [r5, 0x26]
	movs r6, 0xFF
_08097964:
	adds r0, r6, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80978E4

	thumb_func_start sub_8097978
@ void sub_8097978(struct obj *object, u16 a2)
sub_8097978: @ 8097978
	strh r1, [r0, 0x34]
	bx lr
	thumb_func_end sub_8097978

	thumb_func_start sub_809797C
@ bool8 sub_809797C(struct obj *object)
sub_809797C: @ 809797C
	push {lr}
	ldrh r1, [r0, 0x34]
	subs r1, 0x1
	strh r1, [r0, 0x34]
	lsls r1, 16
	cmp r1, 0
	beq _0809798E
	movs r0, 0
	b _08097990
_0809798E:
	movs r0, 0x1
_08097990:
	pop {r1}
	bx r1
	thumb_func_end sub_809797C

	thumb_func_start obj_anim_image_set_and_seek
obj_anim_image_set_and_seek: @ 8097994
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	adds r3, r0, 0
	adds r3, 0x2A
	strb r1, [r3]
	adds r4, r0, 0
	adds r4, 0x2C
	ldrb r3, [r4]
	movs r1, 0x41
	negs r1, r1
	ands r1, r3
	strb r1, [r4]
	adds r1, r2, 0
	bl SeekObjectImageAnim
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end obj_anim_image_set_and_seek

	thumb_func_start sub_80979BC
sub_80979BC: @ 80979BC
	push {lr}
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080979CE
	movs r0, 0
	b _080979D0
_080979CE:
	movs r0, 0x1
_080979D0:
	pop {r1}
	bx r1
	thumb_func_end sub_80979BC

	thumb_func_start sub_80979D4
sub_80979D4: @ 80979D4
	push {r4-r6,lr}
	mov r12, r0
	lsls r1, 24
	lsrs r1, 24
	mov r3, r12
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08097A3C
	mov r0, r12
	ldrh r1, [r0, 0x24]
	ldrh r2, [r0, 0x20]
	adds r1, r2
	mov r4, r12
	adds r4, 0x28
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r2, =gSpriteCoordOffsetX
	adds r0, r1
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r12
	ldrh r1, [r0, 0x26]
	ldrh r2, [r0, 0x22]
	adds r1, r2
	subs r3, 0x15
	movs r0, 0
	ldrsb r0, [r3, r0]
	ldr r2, =gSpriteCoordOffsetY
	adds r0, r1
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r5, r0, 16
	adds r2, r3, 0
	b _08097A6A
	.pool
_08097A3C:
	mov r0, r12
	ldrh r1, [r0, 0x24]
	ldrh r2, [r0, 0x20]
	adds r1, r2
	mov r3, r12
	adds r3, 0x28
	movs r0, 0
	ldrsb r0, [r3, r0]
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r12
	ldrh r1, [r0, 0x26]
	ldrh r2, [r0, 0x22]
	adds r1, r2
	mov r2, r12
	adds r2, 0x29
	movs r0, 0
	ldrsb r0, [r2, r0]
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, r3, 0
_08097A6A:
	ldrb r0, [r4]
	lsls r0, 24
	asrs r0, 25
	subs r0, r6, r0
	lsls r0, 16
	lsrs r3, r0, 16
	ldrb r0, [r2]
	lsls r0, 24
	asrs r0, 25
	subs r0, r5, r0
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0xFF
	bgt _08097A96
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _08097AA2
_08097A96:
	mov r4, r12
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
_08097AA2:
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0xAF
	bgt _08097AB6
	lsls r0, r2, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _08097AC2
_08097AB6:
	mov r0, r12
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08097AC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80979D4

	thumb_func_start sub_8097AC8
sub_8097AC8: @ 8097AC8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8097D68
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	movs r2, 0x1
	bl SetObjectSubpriorityByZCoord
	ldrh r1, [r4, 0x32]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_80979D4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8097AC8

	thumb_func_start sub_8097AF0
sub_8097AF0: @ 8097AF0
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0x3F
_08097AF6:
	ldr r0, =gSprites
	adds r2, r5, r0
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08097B16
	ldr r1, [r2, 0x1C]
	ldr r0, =sub_8097AC8
	cmp r1, r0
	bne _08097B16
	adds r0, r2, 0
	bl DestroySprite
_08097B16:
	adds r5, 0x44
	subs r4, 0x1
	cmp r4, 0
	bge _08097AF6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097AF0

	thumb_func_start sub_8097B2C
sub_8097B2C: @ 8097B2C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r6, =gSprites
	movs r4, 0
_08097B38:
	adds r2, r4, r6
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08097B68
	ldr r1, [r2, 0x1C]
	ldr r0, =sub_8097AC8
	cmp r1, r0
	bne _08097B68
	ldrh r0, [r2, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _08097B68
	adds r0, r3, 0
	b _08097B72
	.pool
_08097B68:
	adds r4, 0x44
	adds r3, 0x1
	cmp r3, 0x3F
	ble _08097B38
	movs r0, 0x40
_08097B72:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8097B2C

	thumb_func_start sub_8097B78
sub_8097B78: @ 8097B78
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08097BAA
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r5, 0
	bl FieldObjectDirectionToImageAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
_08097BAA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097B78

	thumb_func_start sub_8097BB4
sub_8097BB4: @ 8097BB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_8097B2C
	adds r1, r0, 0
	cmp r1, 0x40
	beq _08097C3E
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r5, 0
	bl GetFieldObjectGraphicsInfo
	ldrh r3, [r4, 0x4]
	lsls r3, 22
	ldr r1, [r0, 0x10]
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [r4]
	str r2, [r4, 0x4]
	lsrs r3, 22
	ldrh r2, [r4, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r3
	strh r1, [r4, 0x4]
	ldrb r2, [r0, 0xC]
	lsls r2, 28
	lsrs r2, 24
	ldrb r3, [r4, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r2
	strb r1, [r4, 0x5]
	ldr r1, [r0, 0x1C]
	str r1, [r4, 0xC]
	ldr r1, [r0, 0x14]
	cmp r1, 0
	bne _08097C20
	str r1, [r4, 0x18]
	adds r0, r4, 0
	adds r0, 0x42
	strb r1, [r0]
	b _08097C36
	.pool
_08097C20:
	adds r0, r4, 0
	bl SetSpriteOamTables_NoPriorityFromTable
	adds r2, r4, 0
	adds r2, 0x42
	ldrb r0, [r2]
	movs r1, 0x3F
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2]
_08097C36:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnim
_08097C3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8097BB4

	thumb_func_start sub_8097C44
sub_8097C44: @ 8097C44
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	cmp r2, 0x40
	beq _08097C80
	cmp r4, 0
	beq _08097C74
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x32]
	b _08097C80
	.pool
_08097C74:
	ldr r1, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x32]
_08097C80:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097C44

	thumb_func_start sub_8097C8C
sub_8097C8C: @ 8097C8C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	bne _08097CA2
	movs r0, 0
	b _08097CBA
_08097CA2:
	movs r3, 0
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r2, 0x32
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _08097CB8
	movs r3, 0x1
_08097CB8:
	adds r0, r3, 0
_08097CBA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8097C8C

	thumb_func_start sub_8097CC4
sub_8097CC4: @ 8097CC4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08097CEA
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0
	strh r4, [r1, 0x34]
	strh r0, [r1, 0x36]
_08097CEA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097CC4

	thumb_func_start sub_8097CF4
sub_8097CF4: @ 8097CF4
	push {lr}
	adds r2, r0, 0
	movs r1, 0x36
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _08097D06
	cmp r0, 0x1
	beq _08097D0E
	b _08097D2C
_08097D06:
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x36]
	adds r0, 0x1
	strh r0, [r2, 0x36]
_08097D0E:
	ldrh r0, [r2, 0x26]
	subs r0, 0x8
	movs r3, 0
	strh r0, [r2, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA0
	negs r1, r1
	cmp r0, r1
	bne _08097D2C
	strh r3, [r2, 0x26]
	movs r0, 0x1
	strh r0, [r2, 0x32]
	strh r3, [r2, 0x34]
	strh r3, [r2, 0x36]
_08097D2C:
	pop {r0}
	bx r0
	thumb_func_end sub_8097CF4

	thumb_func_start sub_8097D30
sub_8097D30: @ 8097D30
	push {lr}
	adds r1, r0, 0
	movs r2, 0x36
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08097D42
	cmp r0, 0x1
	beq _08097D4C
	b _08097D5E
_08097D42:
	ldr r0, =0x0000ff60
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x36]
	adds r0, 0x1
	strh r0, [r1, 0x36]
_08097D4C:
	ldrh r0, [r1, 0x26]
	adds r0, 0x8
	strh r0, [r1, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _08097D5E
	strh r0, [r1, 0x34]
	strh r0, [r1, 0x36]
_08097D5E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097D30

	thumb_func_start sub_8097D68
sub_8097D68: @ 8097D68
	push {lr}
	adds r1, r0, 0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _08097D84
	cmp r0, 0x1
	bgt _08097D7E
	cmp r0, 0
	beq _08097D98
	b _08097D94
_08097D7E:
	cmp r0, 0x2
	beq _08097D8C
	b _08097D94
_08097D84:
	adds r0, r1, 0
	bl sub_8097D30
	b _08097D98
_08097D8C:
	adds r0, r1, 0
	bl sub_8097CF4
	b _08097D98
_08097D94:
	movs r0, 0
	strh r0, [r1, 0x34]
_08097D98:
	pop {r0}
	bx r0
	thumb_func_end sub_8097D68

	thumb_func_start sub_8097D9C
sub_8097D9C: @ 8097D9C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08097DC0
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08097DC8
_08097DC0:
	movs r0, 0
	b _08097DCA
	.pool
_08097DC8:
	movs r0, 0x1
_08097DCA:
	pop {r1}
	bx r1
	thumb_func_end sub_8097D9C

	thumb_func_start oe_exec_and_other_stuff
oe_exec_and_other_stuff: @ 8097DD0
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gUnknown_02038C08
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	bl FieldObjectGetLocalIdAndMap
	adds r0, r4, 0
	bl FieldEffectStart
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oe_exec_and_other_stuff

	thumb_func_start DoShadowFieldEffect
DoShadowFieldEffect: @ 8097DF8
	push {lr}
	adds r1, r0, 0
	ldrb r2, [r1, 0x2]
	lsls r0, r2, 25
	cmp r0, 0
	blt _08097E10
	movs r0, 0x40
	orrs r0, r2
	strb r0, [r1, 0x2]
	movs r0, 0x3
	bl oe_exec_and_other_stuff
_08097E10:
	pop {r0}
	bx r0
	thumb_func_end DoShadowFieldEffect

	thumb_func_start DoRippleFieldEffect
@ void DoRippleFieldEffect(struct npc_state *fieldObject, struct obj *object)
DoRippleFieldEffect: @ 8097E14
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldr r2, =gUnknown_02038C08
	movs r3, 0x20
	ldrsh r1, [r4, r3]
	str r1, [r2]
	movs r3, 0x22
	ldrsh r1, [r4, r3]
	ldrh r0, [r0, 0xA]
	lsls r0, 16
	asrs r0, 17
	adds r1, r0
	subs r1, 0x2
	str r1, [r2, 0x4]
	movs r0, 0x97
	str r0, [r2, 0x8]
	movs r0, 0x3
	str r0, [r2, 0xC]
	movs r0, 0x5
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoRippleFieldEffect

	thumb_func_start sub_8097E50
sub_8097E50: @ 8097E50
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	mov r8, r1
	movs r0, 0
	mov r12, r0
	ldr r0, =gUnknown_020375B8
	ldr r1, [r0]
	adds r6, r0, 0
	cmp r1, 0
	bne _08097E80
	movs r0, 0x14
	bl AllocZeroed
	str r0, [r6]
	ldrb r1, [r4, 0x8]
	strb r1, [r0]
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	b _08097ECC
	.pool
_08097E80:
	movs r2, 0x10
	movs r5, 0
	movs r1, 0
	adds r3, r6, 0
	b _08097E90
_08097E8A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_08097E90:
	cmp r1, 0xF
	bhi _08097EB2
	cmp r2, 0x10
	bne _08097EA4
	ldr r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08097EA4
	adds r2, r1, 0
_08097EA4:
	ldr r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r7, [r4, 0x8]
	cmp r0, r7
	bne _08097E8A
	movs r5, 0x1
_08097EB2:
	cmp r5, 0
	bne _08097ECE
	cmp r2, 0x10
	beq _08097ECE
	ldr r0, [r6]
	adds r0, r2
	ldrb r1, [r4, 0x8]
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	movs r0, 0x1
_08097ECC:
	mov r12, r0
_08097ECE:
	mov r1, r12
	cmp r1, 0x1
	bne _08097EE0
	ldrb r0, [r4, 0x1]
	movs r1, 0x10
	orrs r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1]
_08097EE0:
	movs r0, 0x1
	mov r7, r8
	strh r0, [r7, 0x32]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8097E50

	thumb_func_start sub_8097EF0
sub_8097EF0: @ 8097EF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	movs r0, 0x1
	strh r0, [r1, 0x32]
	ldr r5, =gUnknown_020375B8
	ldr r0, [r5]
	cmp r0, 0
	beq _08097F68
	movs r7, 0
	adds r0, r6, 0
	bl sub_8097F78
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x10
	beq _08097F28
	ldr r0, [r5]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	subs r0, 0x1
	strb r0, [r1, 0x10]
	movs r7, 0x1
_08097F28:
	ldr r0, [r5]
	ldrb r4, [r0, 0x10]
	cmp r4, 0
	bne _08097F36
	bl Free
	str r4, [r5]
_08097F36:
	cmp r7, 0x1
	bne _08097F68
	ldrb r0, [r6, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldrb r1, [r0, 0xC]
	lsls r1, 25
	lsrs r1, 31
	lsls r1, 4
	ldrb r2, [r6, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	movs r1, 0x3
	negs r1, r1
	ands r0, r1
	strb r0, [r6, 0x1]
	mov r2, r8
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08097F68:
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8097EF0

	thumb_func_start sub_8097F78
@ signed int sub_8097F78(npc_state *a1)
sub_8097F78: @ 8097F78
	push {lr}
	movs r2, 0
	ldr r1, =gUnknown_020375B8
	ldr r1, [r1]
	ldrb r3, [r0, 0x8]
_08097F82:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r3
	bne _08097F94
	adds r0, r2, 0
	b _08097FA0
	.pool
_08097F94:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _08097F82
	movs r0, 0x10
_08097FA0:
	pop {r1}
	bx r1
	thumb_func_end sub_8097F78

	thumb_func_start sub_8097FA4
sub_8097FA4: @ 8097FA4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =sub_8097FE4
	movs r1, 0xFF
	bl CreateTask
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	adds r0, 0x8
	adds r1, r6, 0
	bl StoreWordInTwoHalfwords
	strb r5, [r6, 0x1B]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097FA4

	thumb_func_start sub_8097FE4
sub_8097FE4: @ 8097FE4
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	adds r0, r4, 0
	adds r0, 0x8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldrh r1, [r4, 0xC]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08098020
	ldrh r0, [r4, 0xE]
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
_08098020:
	ldrh r1, [r4, 0xC]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _08098030
	ldrh r0, [r4, 0xE]
	negs r0, r0
	strh r0, [r4, 0xE]
_08098030:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097FE4

	thumb_func_start sub_8098044
sub_8098044: @ 8098044
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	adds r0, 0x8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	adds r0, r4, 0
	bl DestroyTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098044

	thumb_func_start sub_8098074
sub_8098074: @ 8098074
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	ldr r7, =gUnknown_02037350
_08098082:
	cmp r4, r6
	beq _080980A8
	cmp r4, r5
	beq _080980A8
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r7
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _080980A8
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	beq _080980A8
	adds r0, r1, 0
	bl sub_8097404
_080980A8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08098082
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098074

	thumb_func_start sub_80980C0
sub_80980C0: @ 80980C0
	movs r0, 0
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0
	bx lr
	thumb_func_end sub_80980C0

	thumb_func_start sub_80980D0
sub_80980D0: @ 80980D0
	push {lr}
	adds r2, r1, 0
	ldrh r0, [r2, 0x26]
	subs r0, 0x8
	strh r0, [r2, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA0
	negs r1, r1
	cmp r0, r1
	bne _080980EC
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
_080980EC:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80980D0

	thumb_func_start sub_80980F4
sub_80980F4: @ 80980F4
	ldr r0, =0x0000ff60
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end sub_80980F4

	thumb_func_start sub_8098108
sub_8098108: @ 8098108
	push {lr}
	ldrh r0, [r1, 0x26]
	adds r0, 0x8
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	bne _0809811C
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
_0809811C:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8098108

	thumb_func_start sub_8098124
sub_8098124: @ 8098124
	movs r0, 0x1
	bx lr
	thumb_func_end sub_8098124

	.align 2, 0 @ Don't pad with nop.
