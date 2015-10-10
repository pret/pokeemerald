	thumb_func_start _call_via_r0
_call_via_r0: ; 82E70D0
	bx r0
	mov r8, r8
	thumb_func_end _call_via_r0

	thumb_func_start _call_via_r1
_call_via_r1: ; 82E70D4
	bx r1
	mov r8, r8
	thumb_func_end _call_via_r1

	thumb_func_start _call_via_r2
; void __usercall_call_via_r2(void ( *func)()<R2>)
_call_via_r2: ; 82E70D8
	bx r2
	mov r8, r8
	thumb_func_end _call_via_r2

	thumb_func_start _call_via_r3
_call_via_r3: ; 82E70DC
	bx r3
	mov r8, r8
	thumb_func_end _call_via_r3

	thumb_func_start _call_via_r4
_call_via_r4: ; 82E70E0
	bx r4
	mov r8, r8
	thumb_func_end _call_via_r4

	thumb_func_start _call_via_r5
; void __usercall_call_via_r5(void ( *func)()<R5>)
_call_via_r5: ; 82E70E4
	bx r5
	mov r8, r8
	thumb_func_end _call_via_r5

	thumb_func_start _call_via_r6
_call_via_r6: ; 82E70E8
	bx r6
	mov r8, r8
	thumb_func_end _call_via_r6

	thumb_func_start _call_via_r7
_call_via_r7: ; 82E70EC
	bx r7
	mov r8, r8
	thumb_func_end _call_via_r7

	thumb_func_start _call_via_r8
_call_via_r8: ; 82E70F0
	bx r8
	mov r8, r8
	thumb_func_end _call_via_r8

	thumb_func_start _call_via_r9
_call_via_r9: ; 82E70F4
	bx r9
	mov r8, r8
	thumb_func_end _call_via_r9

	thumb_func_start _call_via_sl
_call_via_sl: ; 82E70F8
	bx r10
	mov r8, r8
	thumb_func_end _call_via_sl

	thumb_func_start _call_via_fp
_call_via_fp: ; 82E70FC
	bx r11
	mov r8, r8
	thumb_func_end _call_via_fp

	thumb_func_start _call_via_ip
_call_via_ip: ; 82E7100
	bx r12
	mov r8, r8
	thumb_func_end _call_via_ip

	thumb_func_start _call_via_sp
_call_via_sp: ; 82E7104
	bx sp
	mov r8, r8
	thumb_func_end _call_via_sp

	thumb_func_start _call_via_lr
_call_via_lr: ; 82E7108
	bx lr
	mov r8, r8
	thumb_func_end _call_via_lr

	thumb_func_start __divdi3
__divdi3: ; 82E710C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	movs r4, 0
	str r4, [sp]
	adds r5, r1, 0
	adds r4, r0, 0
	cmp r5, 0
	bge _082E713C
	ldr r0, [sp]
	mvns r0, r0
	str r0, [sp]
	negs r0, r4
	adds r6, r0, 0
	negs r1, r5
	cmp r0, 0
	beq _082E7136
	subs r1, 0x1
_082E7136:
	adds r7, r1, 0
	adds r5, r7, 0
	adds r4, r6, 0
_082E713C:
	cmp r3, 0
	bge _082E7158
	ldr r1, [sp]
	mvns r1, r1
	str r1, [sp]
	negs r0, r2
	str r0, [sp, 0x4]
	negs r2, r3
	cmp r0, 0
	beq _082E7152
	subs r2, 0x1
_082E7152:
	str r2, [sp, 0x8]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0x8]
_082E7158:
	adds r7, r2, 0
	adds r6, r3, 0
	mov r10, r4
	mov r8, r5
	cmp r6, 0
	beq _082E7166
	b _082E73B4
_082E7166:
	cmp r7, r8
	bls _082E7240
	ldr r0, _082E717C
	cmp r7, r0
	bhi _082E7180
	movs r1, 0
	cmp r7, 0xFF
	bls _082E718A
	movs r1, 0x8
	b _082E718A
	.align 2, 0
_082E717C: .4byte 0x0000ffff
_082E7180:
	ldr r0, _082E7234
	movs r1, 0x18
	cmp r7, r0
	bhi _082E718A
	movs r1, 0x10
_082E718A:
	ldr r0, _082E7238
	lsrs r2, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r0, r1
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	beq _082E71B2
	lsls r7, r2
	mov r3, r8
	lsls r3, r2
	subs r1, r2
	mov r0, r10
	lsrs r0, r1
	orrs r3, r0
	mov r8, r3
	mov r4, r10
	lsls r4, r2
	mov r10, r4
_082E71B2:
	lsrs r0, r7, 16
	mov r9, r0
	ldr r1, _082E723C
	ands r1, r7
	str r1, [sp, 0xC]
	mov r0, r8
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	mov r0, r8
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r3, [sp, 0xC]
	adds r2, r6, 0
	muls r2, r3
	lsls r4, 16
	mov r1, r10
	lsrs r0, r1, 16
	orrs r4, r0
	cmp r4, r2
	bcs _082E71F2
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E71F2
	cmp r4, r2
	bcs _082E71F2
	subs r6, 0x1
	adds r4, r7
_082E71F2:
	subs r4, r2
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r1, r0, 0
	ldr r3, [sp, 0xC]
	adds r2, r1, 0
	muls r2, r3
	lsls r5, 16
	ldr r0, _082E723C
	mov r4, r10
	ands r4, r0
	orrs r5, r4
	cmp r5, r2
	bcs _082E722A
	subs r1, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E722A
	cmp r5, r2
	bcs _082E722A
	subs r1, 0x1
_082E722A:
	lsls r6, 16
	orrs r6, r1
	movs r0, 0
	str r0, [sp, 0x10]
	b _082E750A
	.align 2, 0
_082E7234: .4byte 0x00ffffff
_082E7238: .4byte 0x089a3270
_082E723C: .4byte 0x0000ffff
_082E7240:
	cmp r2, 0
	bne _082E724E
	movs r0, 0x1
	movs r1, 0
	bl __udivsi3
	adds r7, r0, 0
_082E724E:
	adds r1, r7, 0
	ldr r0, _082E7260
	cmp r7, r0
	bhi _082E7264
	movs r2, 0
	cmp r7, 0xFF
	bls _082E726E
	movs r2, 0x8
	b _082E726E
	.align 2, 0
_082E7260: .4byte 0x0000ffff
_082E7264:
	ldr r0, _082E728C
	movs r2, 0x18
	cmp r7, r0
	bhi _082E726E
	movs r2, 0x10
_082E726E:
	ldr r0, _082E7290
	lsrs r1, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r0, r2
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	bne _082E7294
	mov r1, r8
	subs r1, r7
	mov r8, r1
	movs r2, 0x1
	str r2, [sp, 0x10]
	b _082E7332
	.align 2, 0
_082E728C: .4byte 0x00ffffff
_082E7290: .4byte 0x089a3270
_082E7294:
	subs r1, r2
	lsls r7, r2
	mov r5, r8
	lsrs r5, r1
	mov r3, r8
	lsls r3, r2
	mov r0, r10
	lsrs r0, r1
	orrs r3, r0
	mov r8, r3
	mov r4, r10
	lsls r4, r2
	mov r10, r4
	lsrs r0, r7, 16
	mov r9, r0
	ldr r1, _082E73B0
	ands r1, r7
	str r1, [sp, 0x14]
	adds r0, r5, 0
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	adds r0, r5, 0
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r2, [sp, 0x14]
	adds r1, r6, 0
	muls r1, r2
	lsls r4, 16
	mov r3, r8
	lsrs r0, r3, 16
	orrs r4, r0
	cmp r4, r1
	bcs _082E72EE
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E72EE
	cmp r4, r1
	bcs _082E72EE
	subs r6, 0x1
	adds r4, r7
_082E72EE:
	subs r4, r1
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r2, r0, 0
	ldr r4, [sp, 0x14]
	adds r1, r2, 0
	muls r1, r4
	lsls r5, 16
	ldr r0, _082E73B0
	mov r3, r8
	ands r3, r0
	orrs r5, r3
	cmp r5, r1
	bcs _082E7328
	subs r2, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E7328
	cmp r5, r1
	bcs _082E7328
	subs r2, 0x1
	adds r5, r7
_082E7328:
	lsls r6, 16
	orrs r6, r2
	str r6, [sp, 0x10]
	subs r1, r5, r1
	mov r8, r1
_082E7332:
	lsrs r4, r7, 16
	mov r9, r4
	ldr r0, _082E73B0
	ands r0, r7
	str r0, [sp, 0x18]
	mov r0, r8
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	mov r0, r8
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r1, [sp, 0x18]
	adds r2, r6, 0
	muls r2, r1
	lsls r4, 16
	mov r3, r10
	lsrs r0, r3, 16
	orrs r4, r0
	cmp r4, r2
	bcs _082E7372
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E7372
	cmp r4, r2
	bcs _082E7372
	subs r6, 0x1
	adds r4, r7
_082E7372:
	subs r4, r2
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r1, r0, 0
	ldr r4, [sp, 0x18]
	adds r2, r1, 0
	muls r2, r4
	lsls r5, 16
	ldr r0, _082E73B0
	mov r3, r10
	ands r3, r0
	orrs r5, r3
	cmp r5, r2
	bcs _082E73AA
	subs r1, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E73AA
	cmp r5, r2
	bcs _082E73AA
	subs r1, 0x1
_082E73AA:
	lsls r6, 16
	orrs r6, r1
	b _082E750A
	.align 2, 0
_082E73B0: .4byte 0x0000ffff
_082E73B4:
	cmp r6, r8
	bls _082E73C0
	movs r6, 0
	movs r4, 0
	str r4, [sp, 0x10]
	b _082E750A
_082E73C0:
	adds r1, r6, 0
	ldr r0, _082E73D4
	cmp r6, r0
	bhi _082E73D8
	movs r2, 0
	cmp r6, 0xFF
	bls _082E73E2
	movs r2, 0x8
	b _082E73E2
	.align 2, 0
_082E73D4: .4byte 0x0000ffff
_082E73D8:
	ldr r0, _082E7404
	movs r2, 0x18
	cmp r6, r0
	bhi _082E73E2
	movs r2, 0x10
_082E73E2:
	ldr r0, _082E7408
	lsrs r1, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r0, r2
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	bne _082E7410
	cmp r8, r6
	bhi _082E73FC
	cmp r10, r7
	bcc _082E740C
_082E73FC:
	movs r6, 0x1
	mov r1, r10
	b _082E7504
	.align 2, 0
_082E7404: .4byte 0x00ffffff
_082E7408: .4byte 0x089a3270
_082E740C:
	movs r6, 0
	b _082E7506
_082E7410:
	subs r1, r2
	lsls r6, r2
	adds r0, r7, 0
	lsrs r0, r1
	orrs r6, r0
	lsls r7, r2
	mov r5, r8
	lsrs r5, r1
	mov r3, r8
	lsls r3, r2
	mov r0, r10
	lsrs r0, r1
	orrs r3, r0
	mov r8, r3
	mov r4, r10
	lsls r4, r2
	mov r10, r4
	lsrs r0, r6, 16
	mov r9, r0
	ldr r1, _082E753C
	ands r1, r6
	str r1, [sp, 0x1C]
	adds r0, r5, 0
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	adds r0, r5, 0
	mov r1, r9
	bl __udivsi3
	adds r3, r0, 0
	ldr r2, [sp, 0x1C]
	adds r1, r3, 0
	muls r1, r2
	lsls r4, 16
	mov r2, r8
	lsrs r0, r2, 16
	orrs r4, r0
	cmp r4, r1
	bcs _082E7472
	subs r3, 0x1
	adds r4, r6
	cmp r4, r6
	bcc _082E7472
	cmp r4, r1
	bcs _082E7472
	subs r3, 0x1
	adds r4, r6
_082E7472:
	subs r4, r1
	adds r0, r4, 0
	mov r1, r9
	str r3, [sp, 0x30]
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r2, r0, 0
	ldr r4, [sp, 0x1C]
	adds r1, r2, 0
	muls r1, r4
	lsls r5, 16
	ldr r0, _082E753C
	mov r4, r8
	ands r4, r0
	orrs r5, r4
	ldr r3, [sp, 0x30]
	cmp r5, r1
	bcs _082E74B0
	subs r2, 0x1
	adds r5, r6
	cmp r5, r6
	bcc _082E74B0
	cmp r5, r1
	bcs _082E74B0
	subs r2, 0x1
	adds r5, r6
_082E74B0:
	lsls r6, r3, 16
	orrs r6, r2
	subs r1, r5, r1
	mov r8, r1
	ldr r0, _082E753C
	mov r9, r0
	adds r1, r6, 0
	ands r1, r0
	lsrs r3, r6, 16
	adds r0, r7, 0
	mov r2, r9
	ands r0, r2
	lsrs r2, r7, 16
	adds r5, r1, 0
	muls r5, r0
	adds r4, r1, 0
	muls r4, r2
	adds r1, r3, 0
	muls r1, r0
	muls r3, r2
	lsrs r0, r5, 16
	adds r4, r0
	adds r4, r1
	cmp r4, r1
	bcs _082E74E8
	movs r0, 0x80
	lsls r0, 9
	adds r3, r0
_082E74E8:
	lsrs r0, r4, 16
	adds r3, r0
	mov r1, r9
	ands r4, r1
	lsls r0, r4, 16
	ands r5, r1
	adds r1, r0, r5
	cmp r3, r8
	bhi _082E7502
	cmp r3, r8
	bne _082E7506
	cmp r1, r10
	bls _082E7506
_082E7502:
	subs r6, 0x1
_082E7504:
	subs r0, r1, r7
_082E7506:
	movs r2, 0
	str r2, [sp, 0x10]
_082E750A:
	str r6, [sp, 0x20]
	ldr r3, [sp, 0x10]
	str r3, [sp, 0x24]
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r4, [sp]
	cmp r4, 0
	beq _082E752C
	negs r0, r1
	str r0, [sp, 0x28]
	negs r1, r2
	cmp r0, 0
	beq _082E7526
	subs r1, 0x1
_082E7526:
	str r1, [sp, 0x2C]
	ldr r1, [sp, 0x28]
	ldr r2, [sp, 0x2C]
_082E752C:
	adds r0, r1, 0
	adds r1, r2, 0
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_082E753C: .4byte 0x0000ffff
	thumb_func_end __divdi3

	thumb_func_start __divsi3
; int __divsi3(int dividend, int divisor)
__divsi3: ; 82E7540
	cmp r1, 0
	beq _082E75C8
	push {r4}
	adds r4, r0, 0
	eors r4, r1
	mov r12, r4
	movs r3, 0x1
	movs r2, 0
	cmp r1, 0
	bpl _082E7556
	negs r1, r1
_082E7556:
	cmp r0, 0
	bpl _082E755C
	negs r0, r0
_082E755C:
	cmp r0, r1
	bcc _082E75BA
	movs r4, 0x1
	lsls r4, 28
_082E7564:
	cmp r1, r4
	bcs _082E7572
	cmp r1, r0
	bcs _082E7572
	lsls r1, 4
	lsls r3, 4
	b _082E7564
_082E7572:
	lsls r4, 3
_082E7574:
	cmp r1, r4
	bcs _082E7582
	cmp r1, r0
	bcs _082E7582
	lsls r1, 1
	lsls r3, 1
	b _082E7574
_082E7582:
	cmp r0, r1
	bcc _082E758A
	subs r0, r1
	orrs r2, r3
_082E758A:
	lsrs r4, r1, 1
	cmp r0, r4
	bcc _082E7596
	subs r0, r4
	lsrs r4, r3, 1
	orrs r2, r4
_082E7596:
	lsrs r4, r1, 2
	cmp r0, r4
	bcc _082E75A2
	subs r0, r4
	lsrs r4, r3, 2
	orrs r2, r4
_082E75A2:
	lsrs r4, r1, 3
	cmp r0, r4
	bcc _082E75AE
	subs r0, r4
	lsrs r4, r3, 3
	orrs r2, r4
_082E75AE:
	cmp r0, 0
	beq _082E75BA
	lsrs r3, 4
	beq _082E75BA
	lsrs r1, 4
	b _082E7582
_082E75BA:
	adds r0, r2, 0
	mov r4, r12
	cmp r4, 0
	bpl _082E75C4
	negs r0, r0
_082E75C4:
	pop {r4}
	mov pc, lr
_082E75C8:
	push {lr}
	bl nullsub_1
	movs r0, 0
	pop {pc}
	thumb_func_end __divsi3

	thumb_func_start nullsub_1
nullsub_1: ; 82E75D4
	mov pc, lr
	thumb_func_end nullsub_1

	thumb_func_start __fixunsdfsi
__fixunsdfsi: ; 82E75D8
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r3, _082E75F8
	ldr r2, _082E75F4
	bl __gedf2
	cmp r0, 0
	bge _082E75FC
	adds r1, r5, 0
	adds r0, r4, 0
	bl __fixdfsi
	b _082E7612
	.align 2, 0
_082E75F4: .4byte 0x41e00000
_082E75F8: .4byte 0x00000000
_082E75FC:
	ldr r3, _082E7618
	ldr r2, _082E7614
	adds r1, r5, 0
	adds r0, r4, 0
	bl __adddf3
	bl __fixdfsi
	movs r1, 0x80
	lsls r1, 24
	adds r0, r1
_082E7612:
	pop {r4,r5,pc}
	.align 2, 0
_082E7614: .4byte 0xc1e00000
_082E7618: .4byte 0x00000000
	thumb_func_end __fixunsdfsi

	thumb_func_start __fixunssfsi
__fixunssfsi: ; 82E761C
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _082E7634
	bl __gesf2
	cmp r0, 0
	bge _082E7638
	adds r0, r4, 0
	bl __fixsfsi
	b _082E764A
	.align 2, 0
_082E7634: .4byte 0x4f000000
_082E7638:
	ldr r1, _082E764C
	adds r0, r4, 0
	bl __addsf3
	bl __fixsfsi
	movs r1, 0x80
	lsls r1, 24
	adds r0, r1
_082E764A:
	pop {r4,pc}
	.align 2, 0
_082E764C: .4byte 0xcf000000
	thumb_func_end __fixunssfsi

	thumb_func_start __modsi3
__modsi3: ; 82E7650
	movs r3, 0x1
	cmp r1, 0
	beq _082E7714
	bpl _082E765A
	negs r1, r1
_082E765A:
	push {r4}
	push {r0}
	cmp r0, 0
	bpl _082E7664
	negs r0, r0
_082E7664:
	cmp r0, r1
	bcc _082E7708
	movs r4, 0x1
	lsls r4, 28
_082E766C:
	cmp r1, r4
	bcs _082E767A
	cmp r1, r0
	bcs _082E767A
	lsls r1, 4
	lsls r3, 4
	b _082E766C
_082E767A:
	lsls r4, 3
_082E767C:
	cmp r1, r4
	bcs _082E768A
	cmp r1, r0
	bcs _082E768A
	lsls r1, 1
	lsls r3, 1
	b _082E767C
_082E768A:
	movs r2, 0
	cmp r0, r1
	bcc _082E7692
	subs r0, r1
_082E7692:
	lsrs r4, r1, 1
	cmp r0, r4
	bcc _082E76A4
	subs r0, r4
	mov r12, r3
	movs r4, 0x1
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E76A4:
	lsrs r4, r1, 2
	cmp r0, r4
	bcc _082E76B6
	subs r0, r4
	mov r12, r3
	movs r4, 0x2
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E76B6:
	lsrs r4, r1, 3
	cmp r0, r4
	bcc _082E76C8
	subs r0, r4
	mov r12, r3
	movs r4, 0x3
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E76C8:
	mov r12, r3
	cmp r0, 0
	beq _082E76D6
	lsrs r3, 4
	beq _082E76D6
	lsrs r1, 4
	b _082E768A
_082E76D6:
	movs r4, 0xE
	lsls r4, 28
	ands r2, r4
	beq _082E7708
	mov r3, r12
	movs r4, 0x3
	rors r3, r4
	tst r2, r3
	beq _082E76EC
	lsrs r4, r1, 3
	adds r0, r4
_082E76EC:
	mov r3, r12
	movs r4, 0x2
	rors r3, r4
	tst r2, r3
	beq _082E76FA
	lsrs r4, r1, 2
	adds r0, r4
_082E76FA:
	mov r3, r12
	movs r4, 0x1
	rors r3, r4
	tst r2, r3
	beq _082E7708
	lsrs r4, r1, 1
	adds r0, r4
_082E7708:
	pop {r4}
	cmp r4, 0
	bpl _082E7710
	negs r0, r0
_082E7710:
	pop {r4}
	mov pc, lr
_082E7714:
	push {lr}
	bl nullsub_1
	movs r0, 0
	pop {pc}
	thumb_func_end __modsi3

	thumb_func_start __muldi3
__muldi3: ; 82E7720
	push {r4-r7,lr}
	sub sp, 0x10
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	ldr r3, [sp]
	ldr r0, _082E778C
	mov r12, r0
	adds r2, r3, 0
	ands r2, r0
	lsrs r3, 16
	ldr r1, [sp, 0x8]
	adds r0, r1, 0
	mov r4, r12
	ands r0, r4
	lsrs r1, 16
	adds r5, r2, 0
	muls r5, r0
	adds r4, r2, 0
	muls r4, r1
	adds r2, r3, 0
	muls r2, r0
	muls r3, r1
	lsrs r0, r5, 16
	adds r4, r0
	adds r4, r2
	cmp r4, r2
	bcs _082E7760
	movs r0, 0x80
	lsls r0, 9
	adds r3, r0
_082E7760:
	lsrs r0, r4, 16
	adds r7, r3, r0
	mov r1, r12
	ands r4, r1
	lsls r0, r4, 16
	ands r5, r1
	adds r6, r0, 0
	orrs r6, r5
	adds r1, r7, 0
	adds r0, r6, 0
	ldr r3, [sp]
	ldr r4, [sp, 0xC]
	adds r2, r3, 0
	muls r2, r4
	ldr r5, [sp, 0x4]
	ldr r4, [sp, 0x8]
	adds r3, r5, 0
	muls r3, r4
	adds r2, r3
	adds r1, r7, r2
	add sp, 0x10
	pop {r4-r7,pc}
	.align 2, 0
_082E778C: .4byte 0x0000ffff
	thumb_func_end __muldi3

	thumb_func_start __udivdi3
__udivdi3: ; 82E7790
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r7, r2, 0
	adds r6, r3, 0
	mov r10, r0
	mov r8, r1
	cmp r6, 0
	beq _082E77AA
	b _082E79F8
_082E77AA:
	cmp r7, r8
	bls _082E7884
	ldr r0, _082E77C0
	cmp r7, r0
	bhi _082E77C4
	movs r1, 0
	cmp r7, 0xFF
	bls _082E77CE
	movs r1, 0x8
	b _082E77CE
	.align 2, 0
_082E77C0: .4byte 0x0000ffff
_082E77C4:
	ldr r0, _082E7878
	movs r1, 0x18
	cmp r7, r0
	bhi _082E77CE
	movs r1, 0x10
_082E77CE:
	ldr r0, _082E787C
	lsrs r2, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r0, r1
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	beq _082E77FA
	lsls r7, r2
	mov r0, r8
	lsls r0, r2
	mov r8, r0
	subs r1, r2
	mov r0, r10
	lsrs r0, r1
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	mov r3, r10
	lsls r3, r2
	mov r10, r3
_082E77FA:
	lsrs r4, r7, 16
	mov r9, r4
	ldr r0, _082E7880
	ands r0, r7
	str r0, [sp]
	mov r0, r8
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	mov r0, r8
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r1, [sp]
	adds r2, r6, 0
	muls r2, r1
	lsls r4, 16
	mov r3, r10
	lsrs r0, r3, 16
	orrs r4, r0
	cmp r4, r2
	bcs _082E783A
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E783A
	cmp r4, r2
	bcs _082E783A
	subs r6, 0x1
	adds r4, r7
_082E783A:
	subs r4, r2
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r1, r0, 0
	ldr r4, [sp]
	adds r2, r1, 0
	muls r2, r4
	lsls r5, 16
	ldr r0, _082E7880
	mov r3, r10
	ands r3, r0
	orrs r5, r3
	cmp r5, r2
	bcs _082E7872
	subs r1, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E7872
	cmp r5, r2
	bcs _082E7872
	subs r1, 0x1
_082E7872:
	lsls r6, 16
	orrs r6, r1
	b _082E79FE
	.align 2, 0
_082E7878: .4byte 0x00ffffff
_082E787C: .4byte 0x089a3370
_082E7880: .4byte 0x0000ffff
_082E7884:
	cmp r2, 0
	bne _082E7892
	movs r0, 0x1
	movs r1, 0
	bl __udivsi3
	adds r7, r0, 0
_082E7892:
	adds r1, r7, 0
	ldr r0, _082E78A4
	cmp r7, r0
	bhi _082E78A8
	movs r2, 0
	cmp r7, 0xFF
	bls _082E78B2
	movs r2, 0x8
	b _082E78B2
	.align 2, 0
_082E78A4: .4byte 0x0000ffff
_082E78A8:
	ldr r0, _082E78D0
	movs r2, 0x18
	cmp r7, r0
	bhi _082E78B2
	movs r2, 0x10
_082E78B2:
	ldr r0, _082E78D4
	lsrs r1, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r0, r2
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	bne _082E78D8
	mov r0, r8
	subs r0, r7
	mov r8, r0
	movs r1, 0x1
	str r1, [sp, 0x4]
	b _082E7976
	.align 2, 0
_082E78D0: .4byte 0x00ffffff
_082E78D4: .4byte 0x089a3370
_082E78D8:
	subs r1, r2
	lsls r7, r2
	mov r5, r8
	lsrs r5, r1
	mov r3, r8
	lsls r3, r2
	mov r0, r10
	lsrs r0, r1
	orrs r3, r0
	mov r8, r3
	mov r4, r10
	lsls r4, r2
	mov r10, r4
	lsrs r0, r7, 16
	mov r9, r0
	ldr r1, _082E79F4
	ands r1, r7
	str r1, [sp, 0x8]
	adds r0, r5, 0
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	adds r0, r5, 0
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r2, [sp, 0x8]
	adds r1, r6, 0
	muls r1, r2
	lsls r4, 16
	mov r3, r8
	lsrs r0, r3, 16
	orrs r4, r0
	cmp r4, r1
	bcs _082E7932
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E7932
	cmp r4, r1
	bcs _082E7932
	subs r6, 0x1
	adds r4, r7
_082E7932:
	subs r4, r1
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r2, r0, 0
	ldr r4, [sp, 0x8]
	adds r1, r2, 0
	muls r1, r4
	lsls r5, 16
	ldr r0, _082E79F4
	mov r3, r8
	ands r3, r0
	orrs r5, r3
	cmp r5, r1
	bcs _082E796C
	subs r2, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E796C
	cmp r5, r1
	bcs _082E796C
	subs r2, 0x1
	adds r5, r7
_082E796C:
	lsls r6, 16
	orrs r6, r2
	str r6, [sp, 0x4]
	subs r1, r5, r1
	mov r8, r1
_082E7976:
	lsrs r4, r7, 16
	mov r9, r4
	ldr r0, _082E79F4
	ands r0, r7
	str r0, [sp, 0xC]
	mov r0, r8
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	mov r0, r8
	mov r1, r9
	bl __udivsi3
	adds r6, r0, 0
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	muls r2, r1
	lsls r4, 16
	mov r3, r10
	lsrs r0, r3, 16
	orrs r4, r0
	cmp r4, r2
	bcs _082E79B6
	subs r6, 0x1
	adds r4, r7
	cmp r4, r7
	bcc _082E79B6
	cmp r4, r2
	bcs _082E79B6
	subs r6, 0x1
	adds r4, r7
_082E79B6:
	subs r4, r2
	adds r0, r4, 0
	mov r1, r9
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r1, r0, 0
	ldr r4, [sp, 0xC]
	adds r2, r1, 0
	muls r2, r4
	lsls r5, 16
	ldr r0, _082E79F4
	mov r3, r10
	ands r3, r0
	orrs r5, r3
	cmp r5, r2
	bcs _082E79EE
	subs r1, 0x1
	adds r5, r7
	cmp r5, r7
	bcc _082E79EE
	cmp r5, r2
	bcs _082E79EE
	subs r1, 0x1
_082E79EE:
	lsls r6, 16
	orrs r6, r1
	b _082E7B4E
	.align 2, 0
_082E79F4: .4byte 0x0000ffff
_082E79F8:
	cmp r6, r8
	bls _082E7A04
	movs r6, 0
_082E79FE:
	movs r4, 0
	str r4, [sp, 0x4]
	b _082E7B4E
_082E7A04:
	adds r1, r6, 0
	ldr r0, _082E7A18
	cmp r6, r0
	bhi _082E7A1C
	movs r2, 0
	cmp r6, 0xFF
	bls _082E7A26
	movs r2, 0x8
	b _082E7A26
	.align 2, 0
_082E7A18: .4byte 0x0000ffff
_082E7A1C:
	ldr r0, _082E7A48
	movs r2, 0x18
	cmp r6, r0
	bhi _082E7A26
	movs r2, 0x10
_082E7A26:
	ldr r0, _082E7A4C
	lsrs r1, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r0, r2
	movs r1, 0x20
	subs r2, r1, r0
	cmp r2, 0
	bne _082E7A54
	cmp r8, r6
	bhi _082E7A40
	cmp r10, r7
	bcc _082E7A50
_082E7A40:
	movs r6, 0x1
	mov r1, r10
	b _082E7B48
	.align 2, 0
_082E7A48: .4byte 0x00ffffff
_082E7A4C: .4byte 0x089a3370
_082E7A50:
	movs r6, 0
	b _082E7B4A
_082E7A54:
	subs r1, r2
	lsls r6, r2
	adds r0, r7, 0
	lsrs r0, r1
	orrs r6, r0
	lsls r7, r2
	mov r5, r8
	lsrs r5, r1
	mov r3, r8
	lsls r3, r2
	mov r0, r10
	lsrs r0, r1
	orrs r3, r0
	mov r8, r3
	mov r4, r10
	lsls r4, r2
	mov r10, r4
	lsrs r0, r6, 16
	mov r9, r0
	ldr r1, _082E7B64
	ands r1, r6
	str r1, [sp, 0x10]
	adds r0, r5, 0
	mov r1, r9
	bl __umodsi3
	adds r4, r0, 0
	adds r0, r5, 0
	mov r1, r9
	bl __udivsi3
	adds r3, r0, 0
	ldr r2, [sp, 0x10]
	adds r1, r3, 0
	muls r1, r2
	lsls r4, 16
	mov r2, r8
	lsrs r0, r2, 16
	orrs r4, r0
	cmp r4, r1
	bcs _082E7AB6
	subs r3, 0x1
	adds r4, r6
	cmp r4, r6
	bcc _082E7AB6
	cmp r4, r1
	bcs _082E7AB6
	subs r3, 0x1
	adds r4, r6
_082E7AB6:
	subs r4, r1
	adds r0, r4, 0
	mov r1, r9
	str r3, [sp, 0x1C]
	bl __umodsi3
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, r9
	bl __udivsi3
	adds r2, r0, 0
	ldr r4, [sp, 0x10]
	adds r1, r2, 0
	muls r1, r4
	lsls r5, 16
	ldr r0, _082E7B64
	mov r4, r8
	ands r4, r0
	orrs r5, r4
	ldr r3, [sp, 0x1C]
	cmp r5, r1
	bcs _082E7AF4
	subs r2, 0x1
	adds r5, r6
	cmp r5, r6
	bcc _082E7AF4
	cmp r5, r1
	bcs _082E7AF4
	subs r2, 0x1
	adds r5, r6
_082E7AF4:
	lsls r6, r3, 16
	orrs r6, r2
	subs r1, r5, r1
	mov r8, r1
	ldr r0, _082E7B64
	mov r9, r0
	adds r1, r6, 0
	ands r1, r0
	lsrs r3, r6, 16
	adds r0, r7, 0
	mov r2, r9
	ands r0, r2
	lsrs r2, r7, 16
	adds r5, r1, 0
	muls r5, r0
	adds r4, r1, 0
	muls r4, r2
	adds r1, r3, 0
	muls r1, r0
	muls r3, r2
	lsrs r0, r5, 16
	adds r4, r0
	adds r4, r1
	cmp r4, r1
	bcs _082E7B2C
	movs r0, 0x80
	lsls r0, 9
	adds r3, r0
_082E7B2C:
	lsrs r0, r4, 16
	adds r3, r0
	mov r1, r9
	ands r4, r1
	lsls r0, r4, 16
	ands r5, r1
	adds r1, r0, r5
	cmp r3, r8
	bhi _082E7B46
	cmp r3, r8
	bne _082E7B4A
	cmp r1, r10
	bls _082E7B4A
_082E7B46:
	subs r6, 0x1
_082E7B48:
	subs r0, r1, r7
_082E7B4A:
	movs r2, 0
	str r2, [sp, 0x4]
_082E7B4E:
	str r6, [sp, 0x14]
	ldr r3, [sp, 0x4]
	str r3, [sp, 0x18]
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x18]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_082E7B64: .4byte 0x0000ffff
	thumb_func_end __udivdi3

	thumb_func_start __udivsi3
; unsigned int __udivsi3(unsigned int dividend, unsigned int divisor)
__udivsi3: ; 82E7B68
	cmp r1, 0
	beq _082E7BD6
	movs r3, 0x1
	movs r2, 0
	push {r4}
	cmp r0, r1
	bcc _082E7BD0
	movs r4, 0x1
	lsls r4, 28
_082E7B7A:
	cmp r1, r4
	bcs _082E7B88
	cmp r1, r0
	bcs _082E7B88
	lsls r1, 4
	lsls r3, 4
	b _082E7B7A
_082E7B88:
	lsls r4, 3
_082E7B8A:
	cmp r1, r4
	bcs _082E7B98
	cmp r1, r0
	bcs _082E7B98
	lsls r1, 1
	lsls r3, 1
	b _082E7B8A
_082E7B98:
	cmp r0, r1
	bcc _082E7BA0
	subs r0, r1
	orrs r2, r3
_082E7BA0:
	lsrs r4, r1, 1
	cmp r0, r4
	bcc _082E7BAC
	subs r0, r4
	lsrs r4, r3, 1
	orrs r2, r4
_082E7BAC:
	lsrs r4, r1, 2
	cmp r0, r4
	bcc _082E7BB8
	subs r0, r4
	lsrs r4, r3, 2
	orrs r2, r4
_082E7BB8:
	lsrs r4, r1, 3
	cmp r0, r4
	bcc _082E7BC4
	subs r0, r4
	lsrs r4, r3, 3
	orrs r2, r4
_082E7BC4:
	cmp r0, 0
	beq _082E7BD0
	lsrs r3, 4
	beq _082E7BD0
	lsrs r1, 4
	b _082E7B98
_082E7BD0:
	adds r0, r2, 0
	pop {r4}
	mov pc, lr
_082E7BD6:
	push {lr}
	bl nullsub_1
	movs r0, 0
	pop {pc}
	thumb_func_end __udivsi3

	thumb_func_start __umodsi3
; unsigned int __umodsi3(unsigned int dividend, unsigned int divisor)
__umodsi3: ; 82E7BE0
	cmp r1, 0
	beq _082E7C96
	movs r3, 0x1
	cmp r0, r1
	bcs _082E7BEC
	mov pc, lr
_082E7BEC:
	push {r4}
	movs r4, 0x1
	lsls r4, 28
_082E7BF2:
	cmp r1, r4
	bcs _082E7C00
	cmp r1, r0
	bcs _082E7C00
	lsls r1, 4
	lsls r3, 4
	b _082E7BF2
_082E7C00:
	lsls r4, 3
_082E7C02:
	cmp r1, r4
	bcs _082E7C10
	cmp r1, r0
	bcs _082E7C10
	lsls r1, 1
	lsls r3, 1
	b _082E7C02
_082E7C10:
	movs r2, 0
	cmp r0, r1
	bcc _082E7C18
	subs r0, r1
_082E7C18:
	lsrs r4, r1, 1
	cmp r0, r4
	bcc _082E7C2A
	subs r0, r4
	mov r12, r3
	movs r4, 0x1
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E7C2A:
	lsrs r4, r1, 2
	cmp r0, r4
	bcc _082E7C3C
	subs r0, r4
	mov r12, r3
	movs r4, 0x2
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E7C3C:
	lsrs r4, r1, 3
	cmp r0, r4
	bcc _082E7C4E
	subs r0, r4
	mov r12, r3
	movs r4, 0x3
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_082E7C4E:
	mov r12, r3
	cmp r0, 0
	beq _082E7C5C
	lsrs r3, 4
	beq _082E7C5C
	lsrs r1, 4
	b _082E7C10
_082E7C5C:
	movs r4, 0xE
	lsls r4, 28
	ands r2, r4
	bne _082E7C68
	pop {r4}
	mov pc, lr
_082E7C68:
	mov r3, r12
	movs r4, 0x3
	rors r3, r4
	tst r2, r3
	beq _082E7C76
	lsrs r4, r1, 3
	adds r0, r4
_082E7C76:
	mov r3, r12
	movs r4, 0x2
	rors r3, r4
	tst r2, r3
	beq _082E7C84
	lsrs r4, r1, 2
	adds r0, r4
_082E7C84:
	mov r3, r12
	movs r4, 0x1
	rors r3, r4
	tst r2, r3
	beq _082E7C92
	lsrs r4, r1, 1
	adds r0, r4
_082E7C92:
	pop {r4}
	mov pc, lr
_082E7C96:
	push {lr}
	bl nullsub_1
	movs r0, 0
	pop {pc}
	thumb_func_end __umodsi3

	thumb_func_start __pack_d
__pack_d: ; 82E7CA0
	push {r4-r7,lr}
	sub sp, 0x8
	adds r1, r0, 0
	ldr r4, [r1, 0xC]
	ldr r5, [r1, 0x10]
	ldr r7, [r1, 0x4]
	movs r6, 0
	movs r2, 0
	ldr r0, [r1]
	cmp r0, 0x1
	bhi _082E7CB8
	movs r2, 0x1
_082E7CB8:
	cmp r2, 0
	beq _082E7CD8
	ldr r6, _082E7CCC
	ldr r2, _082E7CD0
	ldr r3, _082E7CD4
	adds r0, r4, 0
	adds r1, r5, 0
	orrs r1, r3
	b _082E7D90
	.align 2, 0
_082E7CCC: .4byte 0x000007ff
_082E7CD0: .4byte 0x00000000
_082E7CD4: .4byte 0x00080000
_082E7CD8:
	movs r2, 0
	cmp r0, 0x4
	bne _082E7CE0
	movs r2, 0x1
_082E7CE0:
	cmp r2, 0
	bne _082E7D2C
	movs r2, 0
	cmp r0, 0x2
	bne _082E7CEC
	movs r2, 0x1
_082E7CEC:
	cmp r2, 0
	beq _082E7CF6
	movs r4, 0
	movs r5, 0
	b _082E7D94
_082E7CF6:
	adds r0, r5, 0
	orrs r0, r4
	cmp r0, 0
	beq _082E7D94
	ldr r2, [r1, 0x8]
	ldr r0, _082E7D14
	cmp r2, r0
	bge _082E7D26
	subs r2, r0, r2
	cmp r2, 0x38
	ble _082E7D18
	movs r4, 0
	movs r5, 0
	b _082E7D86
	.align 2, 0
_082E7D14: .4byte 0xfffffc02
_082E7D18:
	adds r1, r5, 0
	adds r0, r4, 0
	bl __lshrdi3
	adds r5, r1, 0
	adds r4, r0, 0
	b _082E7D86
_082E7D26:
	ldr r0, _082E7D34
	cmp r2, r0
	ble _082E7D3C
_082E7D2C:
	ldr r6, _082E7D38
	movs r4, 0
	movs r5, 0
	b _082E7D94
	.align 2, 0
_082E7D34: .4byte 0x000003ff
_082E7D38: .4byte 0x000007ff
_082E7D3C:
	ldr r0, _082E7D64
	adds r6, r2, r0
	movs r0, 0xFF
	adds r1, r4, 0
	ands r1, r0
	movs r2, 0
	cmp r1, 0x80
	bne _082E7D68
	cmp r2, 0
	bne _082E7D68
	adds r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	adds r0, r2, 0
	orrs r0, r1
	cmp r0, 0
	beq _082E7D70
	movs r0, 0x80
	movs r1, 0
	b _082E7D6C
	.align 2, 0
_082E7D64: .4byte 0x000003ff
_082E7D68:
	movs r0, 0x7F
	movs r1, 0
_082E7D6C:
	adds r4, r0
	adcs r5, r1
_082E7D70:
	ldr r0, _082E7DD4
	cmp r5, r0
	bls _082E7D86
	lsls r3, r5, 31
	lsrs r2, r4, 1
	adds r0, r3, 0
	orrs r0, r2
	lsrs r1, r5, 1
	adds r5, r1, 0
	adds r4, r0, 0
	adds r6, 0x1
_082E7D86:
	lsls r3, r5, 24
	lsrs r2, r4, 8
	adds r0, r3, 0
	orrs r0, r2
	lsrs r1, r5, 8
_082E7D90:
	adds r5, r1, 0
	adds r4, r0, 0
_082E7D94:
	str r4, [sp]
	ldr r2, _082E7DD8
	ands r2, r5
	ldr r0, [sp, 0x4]
	ldr r1, _082E7DDC
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r2, sp
	ldr r1, _082E7DE0
	adds r0, r1, 0
	ands r6, r0
	lsls r1, r6, 4
	ldr r0, _082E7DE4
	ldrh r3, [r2, 0x6]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x6]
	lsls r1, r7, 7
	movs r0, 0x7F
	ldrb r3, [r2, 0x7]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x7]
	ldr r1, [sp]
	ldr r0, [sp, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	add sp, 0x8
	pop {r4-r7,pc}
	.align 2, 0
_082E7DD4: .4byte 0x1fffffff
_082E7DD8: .4byte 0x000fffff
_082E7DDC: .4byte 0xfff00000
_082E7DE0: .4byte 0x000007ff
_082E7DE4: .4byte 0xffff800f
	thumb_func_end __pack_d

	thumb_func_start __unpack_d
__unpack_d: ; 82E7DE8
	push {r4-r7,lr}
	sub sp, 0x8
	adds r2, r0, 0
	adds r6, r1, 0
	ldr r1, [r2, 0x4]
	str r1, [sp]
	ldr r0, [r2]
	str r0, [sp, 0x4]
	mov r2, sp
	adds r4, r1, 0
	lsls r0, 12
	lsrs r5, r0, 12
	ldrh r3, [r2, 0x6]
	lsls r0, r3, 17
	lsrs r3, r0, 21
	ldrb r2, [r2, 0x7]
	lsrs r0, r2, 7
	str r0, [r6, 0x4]
	cmp r3, 0
	bne _082E7E5C
	orrs r1, r5
	cmp r1, 0
	bne _082E7E1C
	movs r0, 0x2
	str r0, [r6]
	b _082E7EB0
_082E7E1C:
	ldr r0, _082E7E54
	str r0, [r6, 0x8]
	lsrs r3, r4, 24
	lsls r2, r5, 8
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 8
	adds r5, r1, 0
	adds r4, r0, 0
	movs r0, 0x3
	str r0, [r6]
	ldr r0, _082E7E58
	cmp r5, r0
	bhi _082E7E8C
	adds r7, r0, 0
_082E7E3A:
	lsrs r3, r4, 31
	lsls r2, r5, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 1
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r0, [r6, 0x8]
	subs r0, 0x1
	str r0, [r6, 0x8]
	cmp r5, r7
	bls _082E7E3A
	b _082E7E8C
	.align 2, 0
_082E7E54: .4byte 0xfffffc02
_082E7E58: .4byte 0x0fffffff
_082E7E5C:
	ldr r0, _082E7E70
	cmp r3, r0
	bne _082E7E92
	orrs r1, r5
	cmp r1, 0
	bne _082E7E74
	movs r0, 0x4
	str r0, [r6]
	b _082E7EB0
	.align 2, 0
_082E7E70: .4byte 0x000007ff
_082E7E74:
	movs r2, 0x80
	lsls r2, 12
	movs r0, 0
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	cmp r1, 0
	beq _082E7E8A
	movs r0, 0x1
	str r0, [r6]
	b _082E7E8C
_082E7E8A:
	str r1, [r6]
_082E7E8C:
	str r4, [r6, 0xC]
	str r5, [r6, 0x10]
	b _082E7EB0
_082E7E92:
	ldr r1, _082E7EB4
	adds r0, r3, r1
	str r0, [r6, 0x8]
	movs r0, 0x3
	str r0, [r6]
	lsrs r3, r4, 24
	lsls r2, r5, 8
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 8
	ldr r2, _082E7EB8
	ldr r3, _082E7EBC
	orrs r1, r3
	str r0, [r6, 0xC]
	str r1, [r6, 0x10]
_082E7EB0:
	add sp, 0x8
	pop {r4-r7,pc}
	.align 2, 0
_082E7EB4: .4byte 0xfffffc01
_082E7EB8: .4byte 0x00000000
_082E7EBC: .4byte 0x10000000
	thumb_func_end __unpack_d

	thumb_func_start __fpadd_parts_d
__fpadd_parts_d: ; 82E7EC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r3, r0, 0
	adds r4, r1, 0
	mov r10, r2
	movs r0, 0
	ldr r2, [r3]
	cmp r2, 0x1
	bhi _082E7EDC
	movs r0, 0x1
_082E7EDC:
	cmp r0, 0
	beq _082E7EE4
_082E7EE0:
	adds r0, r3, 0
	b _082E811C
_082E7EE4:
	movs r1, 0
	ldr r0, [r4]
	cmp r0, 0x1
	bhi _082E7EEE
	movs r1, 0x1
_082E7EEE:
	cmp r1, 0
	bne _082E7F66
	movs r1, 0
	cmp r2, 0x4
	bne _082E7EFA
	movs r1, 0x1
_082E7EFA:
	cmp r1, 0
	beq _082E7F1C
	movs r1, 0
	cmp r0, 0x4
	bne _082E7F06
	movs r1, 0x1
_082E7F06:
	cmp r1, 0
	beq _082E7EE0
	ldr r1, [r3, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	beq _082E7EE0
	ldr r0, _082E7F18
	b _082E811C
	.align 2, 0
_082E7F18: .4byte 0x03001a80
_082E7F1C:
	movs r1, 0
	cmp r0, 0x4
	bne _082E7F24
	movs r1, 0x1
_082E7F24:
	cmp r1, 0
	bne _082E7F66
	movs r1, 0
	cmp r0, 0x2
	bne _082E7F30
	movs r1, 0x1
_082E7F30:
	cmp r1, 0
	beq _082E7F58
	movs r0, 0
	cmp r2, 0x2
	bne _082E7F3C
	movs r0, 0x1
_082E7F3C:
	cmp r0, 0
	beq _082E7EE0
	mov r1, r10
	adds r0, r3, 0
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5}
	stm r1!, {r2,r5}
	ldr r0, [r3, 0x4]
	ldr r1, [r4, 0x4]
	ands r0, r1
	mov r6, r10
	str r0, [r6, 0x4]
	b _082E811A
_082E7F58:
	movs r1, 0
	ldr r0, [r3]
	cmp r0, 0x2
	bne _082E7F62
	movs r1, 0x1
_082E7F62:
	cmp r1, 0
	beq _082E7F6A
_082E7F66:
	adds r0, r4, 0
	b _082E811C
_082E7F6A:
	ldr r0, [r3, 0x8]
	mov r9, r0
	ldr r1, [r4, 0x8]
	mov r8, r1
	ldr r6, [r3, 0xC]
	ldr r7, [r3, 0x10]
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x10]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r1, r9
	mov r2, r8
	subs r0, r1, r2
	cmp r0, 0
	bge _082E7F8A
	negs r0, r0
_082E7F8A:
	cmp r0, 0x3F
	bgt _082E8008
	ldr r3, [r3, 0x4]
	mov r12, r3
	ldr r4, [r4, 0x4]
	str r4, [sp, 0x8]
	cmp r9, r8
	ble _082E7FD4
	mov r3, r9
	mov r4, r8
	subs r3, r4
	mov r8, r3
_082E7FA2:
	movs r5, 0x1
	negs r5, r5
	add r8, r5
	ldr r2, [sp]
	movs r0, 0x1
	ands r2, r0
	movs r3, 0
	ldr r1, [sp, 0x4]
	lsls r5, r1, 31
	ldr r0, [sp]
	lsrs r4, r0, 1
	adds r0, r5, 0
	orrs r0, r4
	adds r4, r1, 0
	lsrs r1, r4, 1
	adds r5, r2, 0
	orrs r5, r0
	str r5, [sp]
	adds r4, r3, 0
	orrs r4, r1
	str r4, [sp, 0x4]
	mov r5, r8
	cmp r5, 0
	bne _082E7FA2
	mov r8, r9
_082E7FD4:
	cmp r8, r9
	ble _082E8024
	mov r0, r8
	mov r1, r9
	subs r0, r1
	mov r9, r0
_082E7FE0:
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	movs r2, 0x1
	ands r2, r6
	movs r3, 0
	lsls r5, r7, 31
	lsrs r4, r6, 1
	adds r0, r5, 0
	orrs r0, r4
	lsrs r1, r7, 1
	adds r6, r2, 0
	orrs r6, r0
	adds r7, r3, 0
	orrs r7, r1
	mov r3, r9
	cmp r3, 0
	bne _082E7FE0
	mov r9, r8
	b _082E8024
_082E8008:
	cmp r9, r8
	ble _082E8016
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	b _082E801C
_082E8016:
	mov r9, r8
	movs r6, 0
	movs r7, 0
_082E801C:
	ldr r3, [r3, 0x4]
	mov r12, r3
	ldr r4, [r4, 0x4]
	str r4, [sp, 0x8]
_082E8024:
	ldr r1, [sp, 0x8]
	cmp r12, r1
	beq _082E80CC
	mov r2, r12
	cmp r2, 0
	beq _082E8046
	adds r1, r7, 0
	adds r0, r6, 0
	bl __negdi2
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r4, [sp]
	ldr r5, [sp, 0x4]
	adds r2, r4
	adcs r3, r5
	b _082E8052
_082E8046:
	adds r3, r7, 0
	adds r2, r6, 0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	subs r2, r0
	sbcs r3, r1
_082E8052:
	cmp r3, 0
	blt _082E8068
	movs r0, 0
	mov r1, r10
	str r0, [r1, 0x4]
	mov r4, r9
	str r4, [r1, 0x8]
	mov r5, r10
	str r2, [r5, 0xC]
	str r3, [r5, 0x10]
	b _082E8080
_082E8068:
	movs r0, 0x1
	mov r6, r10
	str r0, [r6, 0x4]
	mov r0, r9
	str r0, [r6, 0x8]
	adds r1, r3, 0
	adds r0, r2, 0
	bl __negdi2
	mov r2, r10
	str r0, [r2, 0xC]
	str r1, [r2, 0x10]
_082E8080:
	mov r4, r10
	ldr r2, [r4, 0xC]
	ldr r3, [r4, 0x10]
	movs r0, 0x1
	negs r0, r0
	asrs r1, r0, 31
_082E808C:
	adds r2, r0
	adcs r3, r1
	ldr r0, _082E80C8
	cmp r3, r0
	bhi _082E80E4
	cmp r3, r0
	bne _082E80A2
	movs r0, 0x2
	negs r0, r0
	cmp r2, r0
	bhi _082E80E4
_082E80A2:
	mov r5, r10
	ldr r0, [r5, 0xC]
	ldr r1, [r5, 0x10]
	lsrs r3, r0, 31
	lsls r2, r1, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, 1
	mov r6, r10
	str r0, [r6, 0xC]
	str r1, [r6, 0x10]
	ldr r2, [r6, 0x8]
	subs r2, 0x1
	str r2, [r6, 0x8]
	movs r2, 0x1
	negs r2, r2
	asrs r3, r2, 31
	b _082E808C
	.align 2, 0
_082E80C8: .4byte 0x0fffffff
_082E80CC:
	mov r0, r12
	mov r1, r10
	str r0, [r1, 0x4]
	mov r2, r9
	str r2, [r1, 0x8]
	ldr r3, [sp]
	ldr r4, [sp, 0x4]
	adds r6, r3
	adcs r7, r4
	mov r4, r10
	str r6, [r4, 0xC]
	str r7, [r4, 0x10]
_082E80E4:
	movs r0, 0x3
	mov r5, r10
	str r0, [r5]
	ldr r1, [r5, 0x10]
	ldr r0, _082E8128
	cmp r1, r0
	bls _082E811A
	ldr r4, [r5, 0xC]
	ldr r5, [r5, 0x10]
	movs r2, 0x1
	adds r0, r4, 0
	ands r0, r2
	movs r1, 0
	lsls r6, r5, 31
	mov r8, r6
	lsrs r6, r4, 1
	mov r2, r8
	orrs r2, r6
	lsrs r3, r5, 1
	orrs r0, r2
	orrs r1, r3
	mov r2, r10
	str r0, [r2, 0xC]
	str r1, [r2, 0x10]
	ldr r0, [r2, 0x8]
	adds r0, 0x1
	str r0, [r2, 0x8]
_082E811A:
	mov r0, r10
_082E811C:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_082E8128: .4byte 0x1fffffff
	thumb_func_end __fpadd_parts_d

	thumb_func_start __adddf3
; double __adddf3(double arg_a, double arg_b)
__adddf3: ; 82E812C
	push {r4,lr}
	sub sp, 0x4C
	str r0, [sp, 0x3C]
	str r1, [sp, 0x40]
	str r2, [sp, 0x44]
	str r3, [sp, 0x48]
	add r0, sp, 0x3C
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x44
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	add r2, sp, 0x28
	mov r0, sp
	adds r1, r4, 0
	bl __fpadd_parts_d
	bl __pack_d
	add sp, 0x4C
	pop {r4,pc}
	thumb_func_end __adddf3

	thumb_func_start __subdf3
__subdf3: ; 82E815C
	push {r4,lr}
	sub sp, 0x4C
	str r0, [sp, 0x3C]
	str r1, [sp, 0x40]
	str r2, [sp, 0x44]
	str r3, [sp, 0x48]
	add r0, sp, 0x3C
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x44
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	ldr r0, [r4, 0x4]
	movs r1, 0x1
	eors r0, r1
	str r0, [r4, 0x4]
	add r2, sp, 0x28
	mov r0, sp
	adds r1, r4, 0
	bl __fpadd_parts_d
	bl __pack_d
	add sp, 0x4C
	pop {r4,pc}
	thumb_func_end __subdf3

	thumb_func_start __muldf3
__muldf3: ; 82E8194
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x74
	str r0, [sp, 0x3C]
	str r1, [sp, 0x40]
	str r2, [sp, 0x44]
	str r3, [sp, 0x48]
	add r0, sp, 0x3C
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x44
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	mov r8, sp
	add r0, sp, 0x28
	mov r10, r0
	movs r0, 0
	ldr r1, [sp]
	cmp r1, 0x1
	bhi _082E81CA
	movs r0, 0x1
_082E81CA:
	cmp r0, 0
	bne _082E822E
	movs r2, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E81D8
	movs r2, 0x1
_082E81D8:
	cmp r2, 0
	beq _082E81E0
	ldr r0, [sp, 0x4]
	b _082E8250
_082E81E0:
	movs r2, 0
	cmp r1, 0x4
	bne _082E81E8
	movs r2, 0x1
_082E81E8:
	cmp r2, 0
	beq _082E81FA
	movs r1, 0
	cmp r0, 0x2
	bne _082E81F4
	movs r1, 0x1
_082E81F4:
	cmp r1, 0
	bne _082E8212
	b _082E822E
_082E81FA:
	movs r2, 0
	cmp r0, 0x4
	bne _082E8202
	movs r2, 0x1
_082E8202:
	cmp r2, 0
	beq _082E8222
	movs r0, 0
	cmp r1, 0x2
	bne _082E820E
	movs r0, 0x1
_082E820E:
	cmp r0, 0
	beq _082E821C
_082E8212:
	ldr r0, _082E8218
	b _082E841A
	.align 2, 0
_082E8218: .4byte 0x03001a80
_082E821C:
	mov r1, r8
	ldr r0, [r1, 0x4]
	b _082E8250
_082E8222:
	movs r2, 0
	cmp r1, 0x2
	bne _082E822A
	movs r2, 0x1
_082E822A:
	cmp r2, 0
	beq _082E8240
_082E822E:
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x18]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x4]
	mov r0, sp
	b _082E841A
_082E8240:
	movs r1, 0
	cmp r0, 0x2
	bne _082E8248
	movs r1, 0x1
_082E8248:
	cmp r1, 0
	beq _082E8260
	mov r2, r8
	ldr r0, [r2, 0x4]
_082E8250:
	ldr r1, [sp, 0x18]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x18]
	adds r0, r4, 0
	b _082E841A
_082E8260:
	mov r4, r8
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x10]
	adds r6, r0, 0
	movs r7, 0
	str r1, [sp, 0x4C]
	movs r5, 0
	str r5, [sp, 0x50]
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	adds r4, r0, 0
	str r1, [sp, 0x54]
	movs r0, 0
	str r0, [sp, 0x58]
	adds r1, r5, 0
	adds r0, r4, 0
	adds r3, r7, 0
	adds r2, r6, 0
	bl __muldi3
	str r0, [sp, 0x5C]
	str r1, [sp, 0x60]
	ldr r0, [sp, 0x54]
	ldr r1, [sp, 0x58]
	adds r3, r7, 0
	adds r2, r6, 0
	bl __muldi3
	adds r7, r1, 0
	adds r6, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	ldr r2, [sp, 0x4C]
	ldr r3, [sp, 0x50]
	bl __muldi3
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r0, [sp, 0x54]
	ldr r1, [sp, 0x58]
	ldr r2, [sp, 0x4C]
	ldr r3, [sp, 0x50]
	bl __muldi3
	str r0, [sp, 0x64]
	str r1, [sp, 0x68]
	movs r1, 0
	movs r2, 0
	str r1, [sp, 0x6C]
	str r2, [sp, 0x70]
	adds r3, r7, 0
	adds r2, r6, 0
	adds r2, r4
	adcs r3, r5
	cmp r7, r3
	bhi _082E82D8
	cmp r7, r3
	bne _082E82E0
	cmp r6, r2
	bls _082E82E0
_082E82D8:
	ldr r5, _082E8430
	ldr r4, _082E842C
	str r4, [sp, 0x6C]
	str r5, [sp, 0x70]
_082E82E0:
	adds r1, r2, 0
	movs r6, 0
	adds r7, r1, 0
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	adds r6, r0
	adcs r7, r1
	cmp r1, r7
	bhi _082E82FC
	ldr r1, [sp, 0x60]
	cmp r1, r7
	bne _082E830C
	cmp r0, r6
	bls _082E830C
_082E82FC:
	movs r0, 0x1
	movs r1, 0
	ldr r4, [sp, 0x6C]
	ldr r5, [sp, 0x70]
	adds r4, r0
	adcs r5, r1
	str r4, [sp, 0x6C]
	str r5, [sp, 0x70]
_082E830C:
	adds r0, r3, 0
	adds r2, r0, 0
	movs r3, 0
	adds r5, r3, 0
	adds r4, r2, 0
	ldr r0, [sp, 0x64]
	ldr r1, [sp, 0x68]
	adds r4, r0
	adcs r5, r1
	ldr r1, [sp, 0x6C]
	ldr r2, [sp, 0x70]
	adds r4, r1
	adcs r5, r2
	mov r0, r8
	ldr r2, [r0, 0x8]
	ldr r0, [sp, 0x1C]
	adds r2, r0
	str r2, [sp, 0x30]
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [sp, 0x18]
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0x2C]
	adds r2, 0x4
	str r2, [sp, 0x30]
	ldr r0, _082E8434
	cmp r5, r0
	bls _082E838E
	movs r1, 0x1
	mov r9, r1
	mov r8, r0
	mov r12, r2
_082E8352:
	movs r2, 0x1
	add r12, r2
	mov r0, r9
	ands r0, r4
	cmp r0, 0
	beq _082E8378
	lsls r3, r7, 31
	lsrs r2, r6, 1
	adds r0, r3, 0
	orrs r0, r2
	lsrs r1, r7, 1
	adds r7, r1, 0
	adds r6, r0, 0
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 24
	orrs r1, r7
	adds r7, r1, 0
	adds r6, r0, 0
_082E8378:
	lsls r3, r5, 31
	lsrs r2, r4, 1
	adds r0, r3, 0
	orrs r0, r2
	lsrs r1, r5, 1
	adds r5, r1, 0
	adds r4, r0, 0
	cmp r5, r8
	bhi _082E8352
	mov r0, r12
	str r0, [sp, 0x30]
_082E838E:
	ldr r0, _082E8438
	cmp r5, r0
	bhi _082E83E0
	movs r1, 0x80
	lsls r1, 24
	mov r9, r1
	mov r8, r0
	ldr r2, [sp, 0x30]
	mov r12, r2
_082E83A0:
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	lsrs r3, r4, 31
	lsls r2, r5, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 1
	adds r5, r1, 0
	adds r4, r0, 0
	movs r0, 0
	mov r1, r9
	ands r1, r7
	orrs r0, r1
	cmp r0, 0
	beq _082E83CA
	movs r0, 0x1
	orrs r0, r4
	adds r1, r5, 0
	adds r5, r1, 0
	adds r4, r0, 0
_082E83CA:
	lsrs r3, r6, 31
	lsls r2, r7, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r6, 1
	adds r7, r1, 0
	adds r6, r0, 0
	cmp r5, r8
	bls _082E83A0
	mov r1, r12
	str r1, [sp, 0x30]
_082E83E0:
	movs r0, 0xFF
	adds r1, r4, 0
	ands r1, r0
	movs r2, 0
	cmp r1, 0x80
	bne _082E840E
	cmp r2, 0
	bne _082E840E
	adds r0, 0x1
	adds r1, r4, 0
	ands r1, r0
	adds r0, r2, 0
	orrs r0, r1
	cmp r0, 0
	bne _082E8406
	adds r0, r7, 0
	orrs r0, r6
	cmp r0, 0
	beq _082E840E
_082E8406:
	movs r0, 0x80
	movs r1, 0
	adds r4, r0
	adcs r5, r1
_082E840E:
	str r4, [sp, 0x34]
	str r5, [sp, 0x38]
	movs r0, 0x3
	mov r2, r10
	str r0, [r2]
	add r0, sp, 0x28
_082E841A:
	bl __pack_d
	add sp, 0x74
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_082E842C: .4byte 0x00000000
_082E8430: .4byte 0x00000001
_082E8434: .4byte 0x1fffffff
_082E8438: .4byte 0x0fffffff
	thumb_func_end __muldf3

	thumb_func_start __divdf3
__divdf3: ; 82E843C
	push {r4-r7,lr}
	sub sp, 0x48
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	mov r12, sp
	movs r0, 0
	ldr r3, [sp]
	cmp r3, 0x1
	bhi _082E8466
	movs r0, 0x1
_082E8466:
	cmp r0, 0
	beq _082E846E
	mov r1, sp
	b _082E85B0
_082E846E:
	movs r0, 0
	ldr r2, [sp, 0x14]
	adds r5, r2, 0
	cmp r2, 0x1
	bhi _082E847A
	movs r0, 0x1
_082E847A:
	cmp r0, 0
	beq _082E8482
	adds r1, r4, 0
	b _082E85B0
_082E8482:
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x18]
	eors r0, r1
	str r0, [sp, 0x4]
	movs r0, 0
	cmp r3, 0x4
	bne _082E8492
	movs r0, 0x1
_082E8492:
	cmp r0, 0
	bne _082E84A2
	movs r4, 0
	cmp r3, 0x2
	bne _082E849E
	movs r4, 0x1
_082E849E:
	cmp r4, 0
	beq _082E84B4
_082E84A2:
	mov r1, r12
	ldr r0, [r1]
	cmp r0, r5
	beq _082E84AC
	b _082E85B0
_082E84AC:
	ldr r1, _082E84B0
	b _082E85B0
	.align 2, 0
_082E84B0: .4byte 0x03001a80
_082E84B4:
	movs r0, 0
	cmp r2, 0x4
	bne _082E84BC
	movs r0, 0x1
_082E84BC:
	cmp r0, 0
	beq _082E84CE
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	str r4, [sp, 0x8]
	mov r1, sp
	b _082E85B0
_082E84CE:
	movs r0, 0
	cmp r2, 0x2
	bne _082E84D6
	movs r0, 0x1
_082E84D6:
	cmp r0, 0
	beq _082E84E2
	movs r0, 0x4
	mov r2, r12
	str r0, [r2]
	b _082E85AE
_082E84E2:
	mov r3, r12
	ldr r1, [r3, 0x8]
	ldr r0, [sp, 0x1C]
	subs r6, r1, r0
	str r6, [r3, 0x8]
	ldr r4, [r3, 0xC]
	ldr r5, [r3, 0x10]
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	cmp r1, r5
	bhi _082E8506
	ldr r1, [sp, 0x3C]
	cmp r1, r5
	bne _082E851A
	cmp r0, r4
	bls _082E851A
_082E8506:
	lsrs r3, r4, 31
	lsls r2, r5, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 1
	adds r5, r1, 0
	adds r4, r0, 0
	subs r0, r6, 0x1
	mov r2, r12
	str r0, [r2, 0x8]
_082E851A:
	ldr r7, _082E85C0
	ldr r6, _082E85BC
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
_082E8526:
	ldr r1, [sp, 0x3C]
	cmp r1, r5
	bhi _082E854A
	cmp r1, r5
	bne _082E8536
	ldr r2, [sp, 0x38]
	cmp r2, r4
	bhi _082E854A
_082E8536:
	ldr r0, [sp, 0x40]
	orrs r0, r6
	ldr r1, [sp, 0x44]
	orrs r1, r7
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	ldr r0, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	subs r4, r0
	sbcs r5, r1
_082E854A:
	lsls r3, r7, 31
	lsrs r2, r6, 1
	adds r0, r3, 0
	orrs r0, r2
	lsrs r1, r7, 1
	adds r7, r1, 0
	adds r6, r0, 0
	lsrs r3, r4, 31
	lsls r2, r5, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, r4, 1
	adds r5, r1, 0
	adds r4, r0, 0
	adds r0, r7, 0
	orrs r0, r6
	cmp r0, 0
	bne _082E8526
	movs r0, 0xFF
	ldr r1, [sp, 0x40]
	ands r1, r0
	movs r2, 0
	cmp r1, 0x80
	bne _082E85A4
	cmp r2, 0
	bne _082E85A4
	adds r0, 0x1
	ldr r1, [sp, 0x40]
	ands r1, r0
	adds r0, r2, 0
	orrs r0, r1
	cmp r0, 0
	bne _082E8594
	adds r0, r5, 0
	orrs r0, r4
	cmp r0, 0
	beq _082E85A4
_082E8594:
	movs r0, 0x80
	movs r1, 0
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x44]
	adds r2, r0
	adcs r3, r1
	str r2, [sp, 0x40]
	str r3, [sp, 0x44]
_082E85A4:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	mov r2, r12
	str r0, [r2, 0xC]
	str r1, [r2, 0x10]
_082E85AE:
	mov r1, r12
_082E85B0:
	adds r0, r1, 0
	bl __pack_d
	add sp, 0x48
	pop {r4-r7,pc}
	.align 2, 0
_082E85BC: .4byte 0x00000000
_082E85C0: .4byte 0x10000000
	thumb_func_end __divdf3

	thumb_func_start __fpcmp_parts_d
__fpcmp_parts_d: ; 82E85C4
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0
	ldr r1, [r5]
	cmp r1, 0x1
	bhi _082E85D4
	movs r0, 0x1
_082E85D4:
	cmp r0, 0
	bne _082E85E6
	movs r0, 0
	ldr r2, [r6]
	cmp r2, 0x1
	bhi _082E85E2
	movs r0, 0x1
_082E85E2:
	cmp r0, 0
	beq _082E85EA
_082E85E6:
	movs r0, 0x1
	b _082E86C0
_082E85EA:
	movs r0, 0
	cmp r1, 0x4
	bne _082E85F2
	movs r0, 0x1
_082E85F2:
	cmp r0, 0
	beq _082E860A
	movs r0, 0
	cmp r2, 0x4
	bne _082E85FE
	movs r0, 0x1
_082E85FE:
	cmp r0, 0
	beq _082E860A
	ldr r0, [r6, 0x4]
	ldr r1, [r5, 0x4]
	subs r0, r1
	b _082E86C0
_082E860A:
	movs r1, 0
	ldr r0, [r5]
	cmp r0, 0x4
	bne _082E8614
	movs r1, 0x1
_082E8614:
	cmp r1, 0
	bne _082E8662
	movs r1, 0
	cmp r2, 0x4
	bne _082E8620
	movs r1, 0x1
_082E8620:
	cmp r1, 0
	beq _082E8632
_082E8624:
	ldr r0, [r6, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, 0
	beq _082E866C
	movs r1, 0x1
	b _082E866C
_082E8632:
	movs r1, 0
	cmp r0, 0x2
	bne _082E863A
	movs r1, 0x1
_082E863A:
	cmp r1, 0
	beq _082E864A
	movs r1, 0
	cmp r2, 0x2
	bne _082E8646
	movs r1, 0x1
_082E8646:
	cmp r1, 0
	bne _082E86BE
_082E864A:
	movs r1, 0
	cmp r0, 0x2
	bne _082E8652
	movs r1, 0x1
_082E8652:
	cmp r1, 0
	bne _082E8624
	movs r0, 0
	cmp r2, 0x2
	bne _082E865E
	movs r0, 0x1
_082E865E:
	cmp r0, 0
	beq _082E8670
_082E8662:
	ldr r0, [r5, 0x4]
	movs r1, 0x1
	cmp r0, 0
	beq _082E866C
	subs r1, 0x2
_082E866C:
	adds r0, r1, 0
	b _082E86C0
_082E8670:
	ldr r0, [r6, 0x4]
	ldr r4, [r5, 0x4]
	cmp r4, r0
	beq _082E8682
_082E8678:
	movs r0, 0x1
	cmp r4, 0
	beq _082E86C0
	subs r0, 0x2
	b _082E86C0
_082E8682:
	ldr r1, [r5, 0x8]
	ldr r0, [r6, 0x8]
	cmp r1, r0
	bgt _082E8678
	cmp r1, r0
	bge _082E869A
_082E868E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, 0
	beq _082E86C0
	movs r0, 0x1
	b _082E86C0
_082E869A:
	ldr r3, [r5, 0x10]
	ldr r2, [r6, 0x10]
	cmp r3, r2
	bhi _082E8678
	cmp r3, r2
	bne _082E86AE
	ldr r1, [r5, 0xC]
	ldr r0, [r6, 0xC]
	cmp r1, r0
	bhi _082E8678
_082E86AE:
	cmp r2, r3
	bhi _082E868E
	cmp r2, r3
	bne _082E86BE
	ldr r1, [r6, 0xC]
	ldr r0, [r5, 0xC]
	cmp r1, r0
	bhi _082E868E
_082E86BE:
	movs r0, 0
_082E86C0:
	pop {r4-r6,pc}
	thumb_func_end __fpcmp_parts_d

	thumb_func_start __cmpdf2
__cmpdf2: ; 82E86C4
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __cmpdf2

	thumb_func_start __eqdf2
__eqdf2: ; 82E86F0
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E8718
	movs r1, 0x1
_082E8718:
	cmp r1, 0
	bne _082E872A
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E8726
	movs r1, 0x1
_082E8726:
	cmp r1, 0
	beq _082E872E
_082E872A:
	movs r0, 0x1
	b _082E8736
_082E872E:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E8736:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __eqdf2

	thumb_func_start __nedf2
__nedf2: ; 82E873C
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E8764
	movs r1, 0x1
_082E8764:
	cmp r1, 0
	bne _082E8776
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E8772
	movs r1, 0x1
_082E8772:
	cmp r1, 0
	beq _082E877A
_082E8776:
	movs r0, 0x1
	b _082E8782
_082E877A:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E8782:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __nedf2

	thumb_func_start __gtdf2
__gtdf2: ; 82E8788
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E87B0
	movs r1, 0x1
_082E87B0:
	cmp r1, 0
	bne _082E87C2
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E87BE
	movs r1, 0x1
_082E87BE:
	cmp r1, 0
	beq _082E87C8
_082E87C2:
	movs r0, 0x1
	negs r0, r0
	b _082E87D0
_082E87C8:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E87D0:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __gtdf2

	thumb_func_start __gedf2
; int __gedf2(double arg_a, double arg_b)
__gedf2: ; 82E87D4
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E87FC
	movs r1, 0x1
_082E87FC:
	cmp r1, 0
	bne _082E880E
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E880A
	movs r1, 0x1
_082E880A:
	cmp r1, 0
	beq _082E8814
_082E880E:
	movs r0, 0x1
	negs r0, r0
	b _082E881C
_082E8814:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E881C:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __gedf2

	thumb_func_start __ltdf2
__ltdf2: ; 82E8820
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E8848
	movs r1, 0x1
_082E8848:
	cmp r1, 0
	bne _082E885A
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E8856
	movs r1, 0x1
_082E8856:
	cmp r1, 0
	beq _082E885E
_082E885A:
	movs r0, 0x1
	b _082E8866
_082E885E:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E8866:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __ltdf2

	thumb_func_start __ledf2
__ledf2: ; 82E886C
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x28]
	str r1, [sp, 0x2C]
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	add r0, sp, 0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, 0x30
	add r4, sp, 0x14
	adds r1, r4, 0
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E8894
	movs r1, 0x1
_082E8894:
	cmp r1, 0
	bne _082E88A6
	movs r1, 0
	ldr r0, [sp, 0x14]
	cmp r0, 0x1
	bhi _082E88A2
	movs r1, 0x1
_082E88A2:
	cmp r1, 0
	beq _082E88AA
_082E88A6:
	movs r0, 0x1
	b _082E88B2
_082E88AA:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_d
_082E88B2:
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __ledf2

	thumb_func_start __floatsidf
__floatsidf: ; 82E88B8
	push {r4,r5,lr}
	sub sp, 0x14
	adds r2, r0, 0
	movs r0, 0x3
	str r0, [sp]
	lsrs r1, r2, 31
	str r1, [sp, 0x4]
	cmp r2, 0
	bne _082E88D0
	movs r0, 0x2
	str r0, [sp]
	b _082E8926
_082E88D0:
	movs r0, 0x3C
	str r0, [sp, 0x8]
	cmp r1, 0
	beq _082E88F6
	movs r0, 0x80
	lsls r0, 24
	cmp r2, r0
	bne _082E88F0
	ldr r1, _082E88EC
	ldr r0, _082E88E8
	b _082E892C
	.align 2, 0
_082E88E8: .4byte 0xc1e00000
_082E88EC: .4byte 0x00000000
_082E88F0:
	negs r0, r2
	asrs r1, r0, 31
	b _082E88FA
_082E88F6:
	adds r0, r2, 0
	asrs r1, r2, 31
_082E88FA:
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x10]
	ldr r1, _082E8930
	cmp r0, r1
	bhi _082E8926
	adds r5, r1, 0
	ldr r4, [sp, 0x8]
_082E890A:
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	lsrs r3, r0, 31
	lsls r2, r1, 1
	adds r1, r3, 0
	orrs r1, r2
	lsls r0, 1
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	subs r4, 0x1
	ldr r0, [sp, 0x10]
	cmp r0, r5
	bls _082E890A
	str r4, [sp, 0x8]
_082E8926:
	mov r0, sp
	bl __pack_d
_082E892C:
	add sp, 0x14
	pop {r4,r5,pc}
	.align 2, 0
_082E8930: .4byte 0x0fffffff
	thumb_func_end __floatsidf

	thumb_func_start __fixdfsi
; int __fixdfsi(double arg_a)
__fixdfsi: ; 82E8934
	push {lr}
	sub sp, 0x1C
	str r0, [sp, 0x14]
	str r1, [sp, 0x18]
	add r0, sp, 0x14
	mov r1, sp
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x2
	bne _082E894E
	movs r1, 0x1
_082E894E:
	cmp r1, 0
	bne _082E8982
	movs r1, 0
	cmp r0, 0x1
	bhi _082E895A
	movs r1, 0x1
_082E895A:
	cmp r1, 0
	bne _082E8982
	movs r1, 0
	cmp r0, 0x4
	bne _082E8966
	movs r1, 0x1
_082E8966:
	cmp r1, 0
	beq _082E897C
_082E896A:
	ldr r0, [sp, 0x4]
	ldr r1, _082E8978
	cmp r0, 0
	beq _082E89A0
	adds r1, 0x1
	b _082E89A0
	.align 2, 0
_082E8978: .4byte 0x7fffffff
_082E897C:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _082E8986
_082E8982:
	movs r0, 0
	b _082E89A2
_082E8986:
	cmp r0, 0x1E
	bgt _082E896A
	movs r2, 0x3C
	subs r2, r0
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl __lshrdi3
	adds r1, r0, 0
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _082E89A0
	negs r1, r1
_082E89A0:
	adds r0, r1, 0
_082E89A2:
	add sp, 0x1C
	pop {pc}
	thumb_func_end __fixdfsi

	thumb_func_start __negdf2
__negdf2: ; 82E89A8
	push {lr}
	sub sp, 0x1C
	str r0, [sp, 0x14]
	str r1, [sp, 0x18]
	add r0, sp, 0x14
	mov r1, sp
	bl __unpack_d
	movs r1, 0
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _082E89C2
	movs r1, 0x1
_082E89C2:
	str r1, [sp, 0x4]
	mov r0, sp
	bl __pack_d
	add sp, 0x1C
	pop {pc}
	thumb_func_end __negdf2

	thumb_func_start __make_dp
__make_dp: ; 82E89D0
	sub sp, 0x4
	push {r4,lr}
	sub sp, 0x14
	str r3, [sp, 0x1C]
	ldr r3, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	str r4, [sp, 0x10]
	mov r0, sp
	bl __pack_d
	add sp, 0x14
	pop {r4}
	pop {r3}
	add sp, 0x4
	bx r3
	thumb_func_end __make_dp

	thumb_func_start __truncdfsf2
__truncdfsf2: ; 82E89F8
	push {r4,r5,lr}
	sub sp, 0x1C
	str r0, [sp, 0x14]
	str r1, [sp, 0x18]
	add r0, sp, 0x14
	mov r1, sp
	bl __unpack_d
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x10]
	lsls r5, r3, 2
	lsrs r4, r2, 30
	adds r0, r5, 0
	orrs r0, r4
	adds r5, r0, 0
	ldr r4, _082E8A38
	adds r0, r2, 0
	ands r0, r4
	movs r1, 0
	orrs r0, r1
	cmp r0, 0
	beq _082E8A28
	movs r0, 0x1
	orrs r5, r0
_082E8A28:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	adds r3, r5, 0
	bl __make_fp
	add sp, 0x1C
	pop {r4,r5,pc}
	.align 2, 0
_082E8A38: .4byte 0x3fffffff
	thumb_func_end __truncdfsf2

	thumb_func_start __pack_f
__pack_f: ; 82E8A3C
	push {r4-r6,lr}
	ldr r2, [r0, 0xC]
	ldr r6, [r0, 0x4]
	movs r5, 0
	movs r1, 0
	ldr r3, [r0]
	cmp r3, 0x1
	bhi _082E8A4E
	movs r1, 0x1
_082E8A4E:
	cmp r1, 0
	beq _082E8A5C
	movs r5, 0xFF
	movs r0, 0x80
	lsls r0, 13
	orrs r2, r0
	b _082E8AC2
_082E8A5C:
	movs r1, 0
	cmp r3, 0x4
	bne _082E8A64
	movs r1, 0x1
_082E8A64:
	cmp r1, 0
	bne _082E8A98
	movs r1, 0
	cmp r3, 0x2
	bne _082E8A70
	movs r1, 0x1
_082E8A70:
	cmp r1, 0
	beq _082E8A78
	movs r2, 0
	b _082E8AC2
_082E8A78:
	cmp r2, 0
	beq _082E8AC2
	ldr r0, [r0, 0x8]
	movs r3, 0x7E
	negs r3, r3
	cmp r0, r3
	bge _082E8A94
	subs r0, r3, r0
	cmp r0, 0x19
	ble _082E8A90
	movs r2, 0
	b _082E8AC0
_082E8A90:
	lsrs r2, r0
	b _082E8AC0
_082E8A94:
	cmp r0, 0x7F
	ble _082E8A9E
_082E8A98:
	movs r5, 0xFF
	movs r2, 0
	b _082E8AC2
_082E8A9E:
	adds r5, r0, 0
	adds r5, 0x7F
	movs r0, 0x7F
	ands r0, r2
	cmp r0, 0x40
	bne _082E8AB6
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _082E8AB8
	adds r2, 0x40
	b _082E8AB8
_082E8AB6:
	adds r2, 0x3F
_082E8AB8:
	cmp r2, 0
	bge _082E8AC0
	lsrs r2, 1
	adds r5, 0x1
_082E8AC0:
	lsrs r2, 7
_082E8AC2:
	ldr r0, _082E8AE4
	ands r2, r0
	ldr r0, _082E8AE8
	ands r4, r0
	orrs r4, r2
	movs r0, 0xFF
	ands r5, r0
	lsls r1, r5, 23
	ldr r0, _082E8AEC
	ands r4, r0
	orrs r4, r1
	lsls r1, r6, 31
	ldr r0, _082E8AF0
	ands r4, r0
	orrs r4, r1
	adds r0, r4, 0
	pop {r4-r6,pc}
	.align 2, 0
_082E8AE4: .4byte 0x007fffff
_082E8AE8: .4byte 0xff800000
_082E8AEC: .4byte 0x807fffff
_082E8AF0: .4byte 0x7fffffff
	thumb_func_end __pack_f

	thumb_func_start __unpack_f
__unpack_f: ; 82E8AF4
	push {r4,lr}
	adds r3, r1, 0
	ldr r0, [r0]
	lsls r1, r0, 9
	lsrs r2, r1, 9
	lsls r1, r0, 1
	lsrs r1, 24
	lsrs r0, 31
	str r0, [r3, 0x4]
	cmp r1, 0
	bne _082E8B38
	cmp r2, 0
	bne _082E8B14
	movs r0, 0x2
	str r0, [r3]
	b _082E8B6C
_082E8B14:
	adds r4, r1, 0
	subs r4, 0x7E
	str r4, [r3, 0x8]
	lsls r2, 7
	movs r0, 0x3
	str r0, [r3]
	ldr r1, _082E8B34
	cmp r2, r1
	bhi _082E8B54
	adds r0, r4, 0
_082E8B28:
	lsls r2, 1
	subs r0, 0x1
	cmp r2, r1
	bls _082E8B28
	str r0, [r3, 0x8]
	b _082E8B54
	.align 2, 0
_082E8B34: .4byte 0x3fffffff
_082E8B38:
	cmp r1, 0xFF
	bne _082E8B58
	cmp r2, 0
	bne _082E8B46
	movs r0, 0x4
	str r0, [r3]
	b _082E8B6C
_082E8B46:
	movs r0, 0x80
	lsls r0, 13
	ands r0, r2
	cmp r0, 0
	beq _082E8B52
	movs r0, 0x1
_082E8B52:
	str r0, [r3]
_082E8B54:
	str r2, [r3, 0xC]
	b _082E8B6C
_082E8B58:
	adds r0, r1, 0
	subs r0, 0x7F
	str r0, [r3, 0x8]
	movs r0, 0x3
	str r0, [r3]
	lsls r0, r2, 7
	movs r1, 0x80
	lsls r1, 23
	orrs r0, r1
	str r0, [r3, 0xC]
_082E8B6C:
	pop {r4,pc}
	thumb_func_end __unpack_f

	thumb_func_start __fpadd_parts_f
__fpadd_parts_f: ; 82E8B70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	movs r0, 0
	ldr r2, [r6]
	cmp r2, 0x1
	bhi _082E8B86
	movs r0, 0x1
_082E8B86:
	cmp r0, 0
	beq _082E8B8E
_082E8B8A:
	adds r0, r6, 0
	b _082E8CE4
_082E8B8E:
	movs r1, 0
	ldr r0, [r7]
	cmp r0, 0x1
	bhi _082E8B98
	movs r1, 0x1
_082E8B98:
	cmp r1, 0
	bne _082E8C0C
	movs r1, 0
	cmp r2, 0x4
	bne _082E8BA4
	movs r1, 0x1
_082E8BA4:
	cmp r1, 0
	beq _082E8BC4
	movs r1, 0
	cmp r0, 0x4
	bne _082E8BB0
	movs r1, 0x1
_082E8BB0:
	cmp r1, 0
	beq _082E8B8A
	ldr r1, [r6, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _082E8B8A
	ldr r0, _082E8BC0
	b _082E8CE4
	.align 2, 0
_082E8BC0: .4byte 0x03001a98
_082E8BC4:
	movs r1, 0
	cmp r0, 0x4
	bne _082E8BCC
	movs r1, 0x1
_082E8BCC:
	cmp r1, 0
	bne _082E8C0C
	movs r1, 0
	cmp r0, 0x2
	bne _082E8BD8
	movs r1, 0x1
_082E8BD8:
	cmp r1, 0
	beq _082E8BFE
	movs r0, 0
	cmp r2, 0x2
	bne _082E8BE4
	movs r0, 0x1
_082E8BE4:
	cmp r0, 0
	beq _082E8B8A
	adds r1, r5, 0
	adds r0, r6, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6, 0x4]
	ldr r1, [r7, 0x4]
	ands r0, r1
	str r0, [r5, 0x4]
	b _082E8CE2
_082E8BFE:
	movs r1, 0
	ldr r0, [r6]
	cmp r0, 0x2
	bne _082E8C08
	movs r1, 0x1
_082E8C08:
	cmp r1, 0
	beq _082E8C10
_082E8C0C:
	adds r0, r7, 0
	b _082E8CE4
_082E8C10:
	ldr r1, [r6, 0x8]
	ldr r3, [r7, 0x8]
	ldr r2, [r6, 0xC]
	ldr r4, [r7, 0xC]
	subs r0, r1, r3
	cmp r0, 0
	bge _082E8C20
	negs r0, r0
_082E8C20:
	cmp r0, 0x1F
	bgt _082E8C64
	ldr r6, [r6, 0x4]
	ldr r7, [r7, 0x4]
	mov r8, r7
	cmp r1, r3
	ble _082E8C46
	movs r7, 0x1
	mov r12, r7
	subs r3, r1, r3
_082E8C34:
	subs r3, 0x1
	adds r0, r4, 0
	mov r7, r12
	ands r0, r7
	lsrs r4, 1
	orrs r4, r0
	cmp r3, 0
	bne _082E8C34
	adds r3, r1, 0
_082E8C46:
	cmp r3, r1
	ble _082E8C76
	movs r0, 0x1
	mov r12, r0
	subs r1, r3, r1
_082E8C50:
	subs r1, 0x1
	adds r0, r2, 0
	mov r7, r12
	ands r0, r7
	lsrs r2, 1
	orrs r2, r0
	cmp r1, 0
	bne _082E8C50
	adds r1, r3, 0
	b _082E8C76
_082E8C64:
	cmp r1, r3
	ble _082E8C6C
	movs r4, 0
	b _082E8C70
_082E8C6C:
	adds r1, r3, 0
	movs r2, 0
_082E8C70:
	ldr r6, [r6, 0x4]
	ldr r7, [r7, 0x4]
	mov r8, r7
_082E8C76:
	cmp r6, r8
	beq _082E8CC0
	cmp r6, 0
	beq _082E8C82
	subs r3, r4, r2
	b _082E8C84
_082E8C82:
	subs r3, r2, r4
_082E8C84:
	cmp r3, 0
	blt _082E8C92
	movs r0, 0
	str r0, [r5, 0x4]
	str r1, [r5, 0x8]
	str r3, [r5, 0xC]
	b _082E8C9C
_082E8C92:
	movs r0, 0x1
	str r0, [r5, 0x4]
	str r1, [r5, 0x8]
	negs r0, r3
	str r0, [r5, 0xC]
_082E8C9C:
	ldr r1, [r5, 0xC]
	subs r0, r1, 0x1
	ldr r2, _082E8CBC
	cmp r0, r2
	bhi _082E8CC8
_082E8CA6:
	lsls r0, r1, 1
	str r0, [r5, 0xC]
	ldr r1, [r5, 0x8]
	subs r1, 0x1
	str r1, [r5, 0x8]
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, r2
	bls _082E8CA6
	b _082E8CC8
	.align 2, 0
_082E8CBC: .4byte 0x3ffffffe
_082E8CC0:
	str r6, [r5, 0x4]
	str r1, [r5, 0x8]
	adds r0, r2, r4
	str r0, [r5, 0xC]
_082E8CC8:
	movs r0, 0x3
	str r0, [r5]
	ldr r1, [r5, 0xC]
	cmp r1, 0
	bge _082E8CE2
	movs r0, 0x1
	ands r0, r1
	lsrs r1, 1
	orrs r0, r1
	str r0, [r5, 0xC]
	ldr r0, [r5, 0x8]
	adds r0, 0x1
	str r0, [r5, 0x8]
_082E8CE2:
	adds r0, r5, 0
_082E8CE4:
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	thumb_func_end __fpadd_parts_f

	thumb_func_start __addsf3
__addsf3: ; 82E8CEC
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x30]
	str r1, [sp, 0x34]
	add r0, sp, 0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x34
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	add r2, sp, 0x20
	mov r0, sp
	adds r1, r4, 0
	bl __fpadd_parts_f
	bl __pack_f
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __addsf3

	thumb_func_start __subsf3
__subsf3: ; 82E8D18
	push {r4,lr}
	sub sp, 0x38
	str r0, [sp, 0x30]
	str r1, [sp, 0x34]
	add r0, sp, 0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x34
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	ldr r0, [r4, 0x4]
	movs r1, 0x1
	eors r0, r1
	str r0, [r4, 0x4]
	add r2, sp, 0x20
	mov r0, sp
	adds r1, r4, 0
	bl __fpadd_parts_f
	bl __pack_f
	add sp, 0x38
	pop {r4,pc}
	thumb_func_end __subsf3

	thumb_func_start __mulsf3
__mulsf3: ; 82E8D4C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x38
	str r0, [sp, 0x30]
	str r1, [sp, 0x34]
	add r0, sp, 0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x34
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	mov r7, sp
	add r0, sp, 0x20
	mov r8, r0
	movs r0, 0
	ldr r1, [sp]
	mov r9, r8
	cmp r1, 0x1
	bhi _082E8D7E
	movs r0, 0x1
_082E8D7E:
	cmp r0, 0
	bne _082E8DDC
	movs r2, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E8D8C
	movs r2, 0x1
_082E8D8C:
	cmp r2, 0
	beq _082E8D94
	ldr r0, [sp, 0x4]
	b _082E8DFC
_082E8D94:
	movs r2, 0
	cmp r1, 0x4
	bne _082E8D9C
	movs r2, 0x1
_082E8D9C:
	cmp r2, 0
	beq _082E8DAE
	movs r1, 0
	cmp r0, 0x2
	bne _082E8DA8
	movs r1, 0x1
_082E8DA8:
	cmp r1, 0
	bne _082E8DC6
	b _082E8DDC
_082E8DAE:
	movs r2, 0
	cmp r0, 0x4
	bne _082E8DB6
	movs r2, 0x1
_082E8DB6:
	cmp r2, 0
	beq _082E8DD0
	movs r0, 0
	cmp r1, 0x2
	bne _082E8DC2
	movs r0, 0x1
_082E8DC2:
	cmp r0, 0
	beq _082E8DFA
_082E8DC6:
	ldr r0, _082E8DCC
	b _082E8E9E
	.align 2, 0
_082E8DCC: .4byte 0x03001a98
_082E8DD0:
	movs r2, 0
	cmp r1, 0x2
	bne _082E8DD8
	movs r2, 0x1
_082E8DD8:
	cmp r2, 0
	beq _082E8DEE
_082E8DDC:
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x14]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x4]
	mov r0, sp
	b _082E8E9E
_082E8DEE:
	movs r1, 0
	cmp r0, 0x2
	bne _082E8DF6
	movs r1, 0x1
_082E8DF6:
	cmp r1, 0
	beq _082E8E0C
_082E8DFA:
	ldr r0, [r7, 0x4]
_082E8DFC:
	ldr r1, [sp, 0x14]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x14]
	adds r0, r4, 0
	b _082E8E9E
_082E8E0C:
	ldr r0, [r7, 0xC]
	movs r1, 0
	ldr r2, [sp, 0x1C]
	movs r3, 0
	bl __muldi3
	adds r2, r1, 0
	adds r5, r2, 0
	adds r6, r0, 0
	ldr r4, [r7, 0x8]
	ldr r0, [sp, 0x18]
	adds r4, r0
	str r4, [sp, 0x28]
	ldr r1, [r7, 0x4]
	ldr r0, [sp, 0x14]
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0x24]
	adds r4, 0x2
	str r4, [sp, 0x28]
	cmp r2, 0
	bge _082E8E58
	movs r2, 0x1
	movs r1, 0x80
	lsls r1, 24
_082E8E42:
	adds r4, 0x1
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _082E8E50
	lsrs r6, 1
	orrs r6, r1
_082E8E50:
	lsrs r5, 1
	cmp r5, 0
	blt _082E8E42
	str r4, [sp, 0x28]
_082E8E58:
	ldr r0, _082E8EAC
	cmp r5, r0
	bhi _082E8E7E
	movs r4, 0x80
	lsls r4, 24
	movs r3, 0x1
	adds r2, r0, 0
	ldr r1, [sp, 0x28]
_082E8E68:
	subs r1, 0x1
	lsls r5, 1
	adds r0, r6, 0
	ands r0, r4
	cmp r0, 0
	beq _082E8E76
	orrs r5, r3
_082E8E76:
	lsls r6, 1
	cmp r5, r2
	bls _082E8E68
	str r1, [sp, 0x28]
_082E8E7E:
	movs r0, 0x7F
	ands r0, r5
	cmp r0, 0x40
	bne _082E8E94
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	bne _082E8E92
	cmp r6, 0
	beq _082E8E94
_082E8E92:
	adds r5, 0x40
_082E8E94:
	str r5, [sp, 0x2C]
	movs r0, 0x3
	mov r1, r8
	str r0, [r1]
	mov r0, r9
_082E8E9E:
	bl __pack_f
	add sp, 0x38
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7,pc}
	.align 2, 0
_082E8EAC: .4byte 0x3fffffff
	thumb_func_end __mulsf3

	thumb_func_start __divsf3
__divsf3: ; 82E8EB0
	push {r4-r6,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r5, sp, 0x10
	adds r1, r5, 0
	bl __unpack_f
	mov r4, sp
	movs r0, 0
	ldr r3, [sp]
	cmp r3, 0x1
	bhi _082E8ED6
	movs r0, 0x1
_082E8ED6:
	cmp r0, 0
	beq _082E8EDE
	mov r1, sp
	b _082E8F90
_082E8EDE:
	movs r0, 0
	ldr r2, [sp, 0x10]
	adds r6, r2, 0
	cmp r2, 0x1
	bhi _082E8EEA
	movs r0, 0x1
_082E8EEA:
	cmp r0, 0
	beq _082E8EF2
	adds r1, r5, 0
	b _082E8F90
_082E8EF2:
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x14]
	eors r0, r1
	str r0, [sp, 0x4]
	movs r0, 0
	cmp r3, 0x4
	bne _082E8F02
	movs r0, 0x1
_082E8F02:
	cmp r0, 0
	bne _082E8F12
	movs r0, 0
	cmp r3, 0x2
	bne _082E8F0E
	movs r0, 0x1
_082E8F0E:
	cmp r0, 0
	beq _082E8F24
_082E8F12:
	ldr r0, [r4]
	adds r1, r4, 0
	cmp r0, r6
	bne _082E8F90
	ldr r1, _082E8F20
	b _082E8F90
	.align 2, 0
_082E8F20: .4byte 0x03001a98
_082E8F24:
	movs r1, 0
	cmp r2, 0x4
	bne _082E8F2C
	movs r1, 0x1
_082E8F2C:
	cmp r1, 0
	beq _082E8F38
	str r0, [sp, 0xC]
	str r0, [sp, 0x8]
	mov r1, sp
	b _082E8F90
_082E8F38:
	movs r0, 0
	cmp r2, 0x2
	bne _082E8F40
	movs r0, 0x1
_082E8F40:
	cmp r0, 0
	beq _082E8F4A
	movs r0, 0x4
	str r0, [r4]
	b _082E8F8E
_082E8F4A:
	ldr r1, [r4, 0x8]
	ldr r0, [sp, 0x18]
	subs r0, r1, r0
	str r0, [r4, 0x8]
	ldr r2, [r4, 0xC]
	ldr r3, [sp, 0x1C]
	cmp r2, r3
	bcs _082E8F60
	lsls r2, 1
	subs r0, 0x1
	str r0, [r4, 0x8]
_082E8F60:
	movs r0, 0x80
	lsls r0, 23
	movs r1, 0
_082E8F66:
	cmp r2, r3
	bcc _082E8F6E
	orrs r1, r0
	subs r2, r3
_082E8F6E:
	lsrs r0, 1
	lsls r2, 1
	cmp r0, 0
	bne _082E8F66
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x40
	bne _082E8F8C
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E8F8A
	cmp r2, 0
	beq _082E8F8C
_082E8F8A:
	adds r1, 0x40
_082E8F8C:
	str r1, [r4, 0xC]
_082E8F8E:
	adds r1, r4, 0
_082E8F90:
	adds r0, r1, 0
	bl __pack_f
	add sp, 0x28
	pop {r4-r6,pc}
	thumb_func_end __divsf3

	thumb_func_start __fpcmp_parts_f
__fpcmp_parts_f: ; 82E8F9C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	ldr r2, [r4]
	cmp r2, 0x1
	bhi _082E8FAA
	movs r0, 0x1
_082E8FAA:
	cmp r0, 0
	bne _082E8FBC
	movs r0, 0
	ldr r3, [r1]
	cmp r3, 0x1
	bhi _082E8FB8
	movs r0, 0x1
_082E8FB8:
	cmp r0, 0
	beq _082E8FC0
_082E8FBC:
	movs r0, 0x1
	b _082E907E
_082E8FC0:
	movs r0, 0
	cmp r2, 0x4
	bne _082E8FC8
	movs r0, 0x1
_082E8FC8:
	cmp r0, 0
	beq _082E8FE0
	movs r0, 0
	cmp r3, 0x4
	bne _082E8FD4
	movs r0, 0x1
_082E8FD4:
	cmp r0, 0
	beq _082E8FE0
	ldr r0, [r1, 0x4]
	ldr r1, [r4, 0x4]
	subs r0, r1
	b _082E907E
_082E8FE0:
	movs r2, 0
	ldr r0, [r4]
	cmp r0, 0x4
	bne _082E8FEA
	movs r2, 0x1
_082E8FEA:
	cmp r2, 0
	bne _082E9038
	movs r2, 0
	cmp r3, 0x4
	bne _082E8FF6
	movs r2, 0x1
_082E8FF6:
	cmp r2, 0
	beq _082E9008
_082E8FFA:
	ldr r0, [r1, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, 0
	beq _082E9042
	movs r1, 0x1
	b _082E9042
_082E9008:
	movs r2, 0
	cmp r0, 0x2
	bne _082E9010
	movs r2, 0x1
_082E9010:
	cmp r2, 0
	beq _082E9020
	movs r2, 0
	cmp r3, 0x2
	bne _082E901C
	movs r2, 0x1
_082E901C:
	cmp r2, 0
	bne _082E907C
_082E9020:
	movs r2, 0
	cmp r0, 0x2
	bne _082E9028
	movs r2, 0x1
_082E9028:
	cmp r2, 0
	bne _082E8FFA
	movs r0, 0
	cmp r3, 0x2
	bne _082E9034
	movs r0, 0x1
_082E9034:
	cmp r0, 0
	beq _082E9046
_082E9038:
	ldr r0, [r4, 0x4]
	movs r1, 0x1
	cmp r0, 0
	beq _082E9042
	subs r1, 0x2
_082E9042:
	adds r0, r1, 0
	b _082E907E
_082E9046:
	ldr r3, [r4, 0x4]
	ldr r0, [r1, 0x4]
	cmp r3, r0
	beq _082E9058
_082E904E:
	movs r0, 0x1
	cmp r3, 0
	beq _082E907E
	subs r0, 0x2
	b _082E907E
_082E9058:
	ldr r2, [r4, 0x8]
	ldr r0, [r1, 0x8]
	cmp r2, r0
	bgt _082E904E
	cmp r2, r0
	bge _082E9070
_082E9064:
	movs r0, 0x1
	negs r0, r0
	cmp r3, 0
	beq _082E907E
	movs r0, 0x1
	b _082E907E
_082E9070:
	ldr r0, [r4, 0xC]
	ldr r1, [r1, 0xC]
	cmp r0, r1
	bhi _082E904E
	cmp r0, r1
	bcc _082E9064
_082E907C:
	movs r0, 0
_082E907E:
	pop {r4,pc}
	thumb_func_end __fpcmp_parts_f

	thumb_func_start __cmpsf2
__cmpsf2: ; 82E9080
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __cmpsf2

	thumb_func_start __eqsf2
__eqsf2: ; 82E90A8
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E90CC
	movs r1, 0x1
_082E90CC:
	cmp r1, 0
	bne _082E90DE
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E90DA
	movs r1, 0x1
_082E90DA:
	cmp r1, 0
	beq _082E90E2
_082E90DE:
	movs r0, 0x1
	b _082E90EA
_082E90E2:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E90EA:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __eqsf2

	thumb_func_start __nesf2
__nesf2: ; 82E90F0
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E9114
	movs r1, 0x1
_082E9114:
	cmp r1, 0
	bne _082E9126
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E9122
	movs r1, 0x1
_082E9122:
	cmp r1, 0
	beq _082E912A
_082E9126:
	movs r0, 0x1
	b _082E9132
_082E912A:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E9132:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __nesf2

	thumb_func_start __gtsf2
__gtsf2: ; 82E9138
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E915C
	movs r1, 0x1
_082E915C:
	cmp r1, 0
	bne _082E916E
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E916A
	movs r1, 0x1
_082E916A:
	cmp r1, 0
	beq _082E9174
_082E916E:
	movs r0, 0x1
	negs r0, r0
	b _082E917C
_082E9174:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E917C:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __gtsf2

	thumb_func_start __gesf2
__gesf2: ; 82E9180
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E91A4
	movs r1, 0x1
_082E91A4:
	cmp r1, 0
	bne _082E91B6
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E91B2
	movs r1, 0x1
_082E91B2:
	cmp r1, 0
	beq _082E91BC
_082E91B6:
	movs r0, 0x1
	negs r0, r0
	b _082E91C4
_082E91BC:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E91C4:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __gesf2

	thumb_func_start __ltsf2
__ltsf2: ; 82E91C8
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E91EC
	movs r1, 0x1
_082E91EC:
	cmp r1, 0
	bne _082E91FE
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E91FA
	movs r1, 0x1
_082E91FA:
	cmp r1, 0
	beq _082E9202
_082E91FE:
	movs r0, 0x1
	b _082E920A
_082E9202:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E920A:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __ltsf2

	thumb_func_start __lesf2
__lesf2: ; 82E9210
	push {r4,lr}
	sub sp, 0x28
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	add r0, sp, 0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, 0x24
	add r4, sp, 0x10
	adds r1, r4, 0
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bhi _082E9234
	movs r1, 0x1
_082E9234:
	cmp r1, 0
	bne _082E9246
	movs r1, 0
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	bhi _082E9242
	movs r1, 0x1
_082E9242:
	cmp r1, 0
	beq _082E924A
_082E9246:
	movs r0, 0x1
	b _082E9252
_082E924A:
	mov r0, sp
	adds r1, r4, 0
	bl __fpcmp_parts_f
_082E9252:
	add sp, 0x28
	pop {r4,pc}
	thumb_func_end __lesf2

	thumb_func_start __floatsisf
__floatsisf: ; 82E9258
	push {lr}
	sub sp, 0x10
	adds r1, r0, 0
	movs r0, 0x3
	str r0, [sp]
	lsrs r2, r1, 31
	str r2, [sp, 0x4]
	cmp r1, 0
	bne _082E9270
	movs r0, 0x2
	str r0, [sp]
	b _082E92A8
_082E9270:
	movs r0, 0x1E
	str r0, [sp, 0x8]
	cmp r2, 0
	beq _082E928E
	movs r0, 0x80
	lsls r0, 24
	cmp r1, r0
	bne _082E9288
	ldr r0, _082E9284
	b _082E92AE
	.align 2, 0
_082E9284: .4byte 0xcf000000
_082E9288:
	negs r0, r1
	str r0, [sp, 0xC]
	b _082E9290
_082E928E:
	str r1, [sp, 0xC]
_082E9290:
	ldr r2, [sp, 0xC]
	ldr r3, _082E92B4
	cmp r2, r3
	bhi _082E92A8
	ldr r1, [sp, 0x8]
_082E929A:
	lsls r0, r2, 1
	subs r1, 0x1
	adds r2, r0, 0
	cmp r0, r3
	bls _082E929A
	str r1, [sp, 0x8]
	str r0, [sp, 0xC]
_082E92A8:
	mov r0, sp
	bl __pack_f
_082E92AE:
	add sp, 0x10
	pop {pc}
	.align 2, 0
_082E92B4: .4byte 0x3fffffff
	thumb_func_end __floatsisf

	thumb_func_start __fixsfsi
__fixsfsi: ; 82E92B8
	push {lr}
	sub sp, 0x14
	str r0, [sp, 0x10]
	add r0, sp, 0x10
	mov r1, sp
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x2
	bne _082E92D0
	movs r1, 0x1
_082E92D0:
	cmp r1, 0
	bne _082E9302
	movs r1, 0
	cmp r0, 0x1
	bhi _082E92DC
	movs r1, 0x1
_082E92DC:
	cmp r1, 0
	bne _082E9302
	movs r1, 0
	cmp r0, 0x4
	bne _082E92E8
	movs r1, 0x1
_082E92E8:
	cmp r1, 0
	beq _082E92FC
_082E92EC:
	ldr r0, [sp, 0x4]
	ldr r1, _082E92F8
	cmp r0, 0
	beq _082E931A
	adds r1, 0x1
	b _082E931A
	.align 2, 0
_082E92F8: .4byte 0x7fffffff
_082E92FC:
	ldr r1, [sp, 0x8]
	cmp r1, 0
	bge _082E9306
_082E9302:
	movs r0, 0
	b _082E931C
_082E9306:
	cmp r1, 0x1E
	bgt _082E92EC
	movs r0, 0x1E
	subs r0, r1
	ldr r1, [sp, 0xC]
	lsrs r1, r0
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _082E931A
	negs r1, r1
_082E931A:
	adds r0, r1, 0
_082E931C:
	add sp, 0x14
	pop {pc}
	thumb_func_end __fixsfsi

	thumb_func_start __negsf2
__negsf2: ; 82E9320
	push {lr}
	sub sp, 0x14
	str r0, [sp, 0x10]
	add r0, sp, 0x10
	mov r1, sp
	bl __unpack_f
	movs r1, 0
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _082E9338
	movs r1, 0x1
_082E9338:
	str r1, [sp, 0x4]
	mov r0, sp
	bl __pack_f
	add sp, 0x14
	pop {pc}
	thumb_func_end __negsf2

	thumb_func_start __make_fp
__make_fp: ; 82E9344
	push {lr}
	sub sp, 0x10
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	mov r0, sp
	bl __pack_f
	add sp, 0x10
	pop {pc}
	thumb_func_end __make_fp

	thumb_func_start __extendsfdf2
__extendsfdf2: ; 82E935C
	push {r4-r6,lr}
	sub sp, 0x18
	str r0, [sp, 0x14]
	add r0, sp, 0x14
	add r1, sp, 0x4
	bl __unpack_f
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x8]
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x10]
	movs r4, 0
	lsrs r6, r3, 2
	lsls r5, r4, 30
	adds r4, r6, 0
	orrs r4, r5
	lsls r3, 30
	str r4, [sp]
	bl __make_dp
	add sp, 0x18
	pop {r4-r6,pc}
	thumb_func_end __extendsfdf2

	thumb_func_start __lshrdi3
__lshrdi3: ; 82E9388
	push {r4-r6,lr}
	adds r6, r1, 0
	adds r5, r0, 0
	cmp r2, 0
	beq _082E93B8
	movs r0, 0x20
	subs r0, r2
	cmp r0, 0
	bgt _082E93A4
	movs r4, 0
	negs r0, r0
	adds r3, r6, 0
	lsrs r3, r0
	b _082E93B4
_082E93A4:
	adds r1, r6, 0
	lsls r1, r0
	adds r4, r6, 0
	lsrs r4, r2
	adds r0, r5, 0
	lsrs r0, r2
	adds r3, r0, 0
	orrs r3, r1
_082E93B4:
	adds r1, r4, 0
	adds r0, r3, 0
_082E93B8:
	pop {r4-r6,pc}
	thumb_func_end __lshrdi3

	thumb_func_start __negdi2
__negdi2: ; 82E93BC
	push {r4,lr}
	negs r2, r0
	adds r3, r2, 0
	negs r1, r1
	cmp r2, 0
	beq _082E93CA
	subs r1, 0x1
_082E93CA:
	adds r4, r1, 0
	adds r1, r4, 0
	adds r0, r3, 0
	pop {r4,pc}
	thumb_func_end __negdi2

	thumb_func_start memcpy
; void *memcpy(void *dest, void *src, int size)
memcpy: ; 82E93D4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r3, r1, 0
	cmp r2, 0xF
	bls _082E9414
	adds r0, r3, 0
	orrs r0, r5
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E9414
	adds r1, r5, 0
_082E93EE:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _082E93EE
	cmp r2, 0x3
	bls _082E9412
_082E9408:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x4
	cmp r2, 0x3
	bhi _082E9408
_082E9412:
	adds r4, r1, 0
_082E9414:
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _082E942E
	adds r1, r0, 0
_082E9420:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, r1
	bne _082E9420
_082E942E:
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memcpy

	thumb_func_start memset
; void *memset(void *dest, char c, int size)
memset: ; 82E9434
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r5, 0
	cmp r2, 0x3
	bls _082E947A
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0
	bne _082E947A
	adds r1, r5, 0
	movs r0, 0xFF
	ands r4, r0
	lsls r3, r4, 8
	orrs r3, r4
	lsls r0, r3, 16
	orrs r3, r0
	cmp r2, 0xF
	bls _082E946E
_082E945A:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _082E945A
	b _082E946E
_082E946A:
	stm r1!, {r3}
	subs r2, 0x4
_082E946E:
	cmp r2, 0x3
	bhi _082E946A
	adds r3, r1, 0
	b _082E947A
_082E9476:
	strb r4, [r3]
	adds r3, 0x1
_082E947A:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	bne _082E9476
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memset

	thumb_func_start strcmp
; int strcmp(char *s1, char *s2)
strcmp: ; 82E9488
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r3, r1, 0
	orrs r0, r3
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E94CE
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _082E94CE
	ldr r5, _082E94B4
	ldr r4, _082E94B8
_082E94A4:
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
	ands r0, r4
	cmp r0, 0
	beq _082E94BC
	movs r0, 0
	b _082E94E0
	.align 2, 0
_082E94B4: .4byte 0xfefefeff
_082E94B8: .4byte 0x80808080
_082E94BC:
	adds r2, 0x4
	adds r3, 0x4
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _082E94A4
	b _082E94CE
_082E94CA:
	adds r2, 0x1
	adds r3, 0x1
_082E94CE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _082E94DA
	ldrb r1, [r3]
	cmp r0, r1
	beq _082E94CA
_082E94DA:
	ldrb r2, [r2]
	ldrb r3, [r3]
	subs r0, r2, r3
_082E94E0:
	pop {r4,r5,pc}
	thumb_func_end strcmp

	thumb_func_start strcat
strcat: ; 82E94E4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r3, r6, 0
	adds r2, r1, 0
	adds r0, r2, 0
	orrs r0, r6
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E951C
	ldr r1, [r2]
	ldr r5, _082E9504
	adds r0, r1, r5
	bics r0, r1
	ldr r4, _082E9508
	b _082E9516
	.align 2, 0
_082E9504: .4byte 0xfefefeff
_082E9508: .4byte 0x80808080
_082E950C:
	ldm r2!, {r0}
	stm r3!, {r0}
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
_082E9516:
	ands r0, r4
	cmp r0, 0
	beq _082E950C
_082E951C:
	ldrb r0, [r2]
	strb r0, [r3]
	lsls r0, 24
	adds r2, 0x1
	adds r3, 0x1
	cmp r0, 0
	bne _082E951C
	adds r0, r6, 0
	pop {r4-r6,pc}
