	thumb_func_start umul3232H32
umul3232H32: @ 82DF04C
	adr r2, _082DF050
	bx r2
	.arm
_082DF050:
	umull r2, r3, r0, r1
	add r0, r3, 0
	bx lr
	thumb_func_end umul3232H32

	.thumb
	thumb_func_start SoundMain
SoundMain: @ 82DF05C
	ldr r0, _082DF0C8
	ldr r0, [r0]
	ldr r2, _082DF0CC
	ldr r3, [r0]
	cmp r2, r3
	beq _082DF06A
	bx lr
_082DF06A:
	adds r3, 0x1
	str r3, [r0]
	push {r4-r7,lr}
	mov r1, r8
	mov r2, r9
	mov r3, r10
	mov r4, r11
	push {r0-r4}
	sub sp, 0x18
	ldrb r1, [r0, 0xC]
	cmp r1, 0
	beq _082DF08E
	ldr r2, _082DF0D4
	ldrb r2, [r2]
	cmp r2, 0xA0
	bcs _082DF08C
	adds r2, 0xE4
_082DF08C:
	adds r1, r2
_082DF08E:
	str r1, [sp, 0x14]
	ldr r3, [r0, 0x20]
	cmp r3, 0
	beq _082DF09E
	ldr r0, [r0, 0x24]
	bl _082DF496
	ldr r0, [sp, 0x18]
_082DF09E:
	ldr r3, [r0, 0x28]
	bl _082DF496
	ldr r0, [sp, 0x18]
	ldr r3, [r0, 0x10]
	mov r8, r3
	ldr r5, _082DF0D8
	adds r5, r0
	ldrb r4, [r0, 0x4]
	subs r7, r4, 0x1
	bls _082DF0BE
	ldrb r1, [r0, 0xB]
	subs r1, r7
	mov r2, r8
	muls r2, r1
	adds r5, r2
_082DF0BE:
	str r5, [sp, 0x8]
	ldr r6, _082DF0DC
	ldr r3, _082DF0D0
	bx r3
	.align 2, 0
_082DF0C8: .4byte 0x03007ff0
_082DF0CC: .4byte 0x68736d53
_082DF0D0: .4byte 0x03001aa9
_082DF0D4: .4byte 0x04000006
_082DF0D8: .4byte 0x00000350
_082DF0DC: .4byte 0x00000630
	thumb_func_end SoundMain

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 82DF0E0
	ldrb r3, [r0, 0x5]
	cmp r3, 0
	beq _082DF140
	adr r1, _082DF0EC
	bx r1
	.arm
_082DF0EC:
	cmp r4, 0x2
	addeq r7, r0, 0x350
	addne r7, r5, r8
	mov r4, r8
_082DF0FC:
	ldrsb r0, [r5, r6]
	ldrsb r1, [r5]
	add r0, r0, r1
	ldrsb r1, [r7, r6]
	add r0, r0, r1
	ldrsb r1, [r7], 0x1
	add r0, r0, r1
	mul r1, r0, r3
	mov r0, r1, asr 9
	tst r0, 0x80
	addne r0, r0, 0x1
	strb r0, [r5, r6]
	strb r0, [r5], 0x1
	subs r4, r4, 0x1
	bgt _082DF0FC
	add r0, pc, 0x2F
	bx r0
	.thumb
_082DF140:
	movs r0, 0
	mov r1, r8
	adds r6, r5
	lsrs r1, 3
	bcc _082DF14E
	stm r5!, {r0}
	stm r6!, {r0}
_082DF14E:
	lsrs r1, 1
	bcc _082DF15A
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
_082DF15A:
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	subs r1, 0x1
	bgt _082DF15A
	ldr r4, [sp, 0x18]
	ldr r0, [r4, 0x18]
	mov r12, r0
	ldrb r0, [r4, 0x6]
	adds r4, 0x50
_082DF178:
	str r0, [sp, 0x4]
	ldr r3, [r4, 0x24]
	ldr r0, [sp, 0x14]
	cmp r0, 0
	beq _082DF198
	ldr r1, _082DF194
	ldrb r1, [r1]
	cmp r1, 0xA0
	bcs _082DF18C
	adds r1, 0xE4
_082DF18C:
	cmp r1, r0
	bcc _082DF198
	b _082DF482
	.align 2, 0
_082DF194: .4byte 0x04000006
_082DF198:
	ldrb r6, [r4]
	movs r0, 0xC7
	tst r0, r6
	bne _082DF1A2
	b _082DF478
_082DF1A2:
	movs r0, 0x80
	tst r0, r6
	beq _082DF1D8
	movs r0, 0x40
	tst r0, r6
	bne _082DF1E8
	movs r6, 0x3
	strb r6, [r4]
	adds r0, r3, 0
	adds r0, 0x10
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r4, 0x28]
	ldr r0, [r3, 0xC]
	subs r0, r1
	str r0, [r4, 0x18]
	movs r5, 0
	strb r5, [r4, 0x9]
	str r5, [r4, 0x1C]
	ldrb r2, [r3, 0x3]
	movs r0, 0xC0
	tst r0, r2
	beq _082DF230
	movs r0, 0x10
	orrs r6, r0
	strb r6, [r4]
	b _082DF230
_082DF1D8:
	ldrb r5, [r4, 0x9]
	movs r0, 0x4
	tst r0, r6
	beq _082DF1EE
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	bhi _082DF23E
_082DF1E8:
	movs r0, 0
	strb r0, [r4]
	b _082DF478
_082DF1EE:
	movs r0, 0x40
	tst r0, r6
	beq _082DF20E
	ldrb r0, [r4, 0x7]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, 0xC]
	cmp r5, r0
	bhi _082DF23E
_082DF200:
	ldrb r5, [r4, 0xC]
	cmp r5, 0
	beq _082DF1E8
	movs r0, 0x4
	orrs r6, r0
	strb r6, [r4]
	b _082DF23E
_082DF20E:
	movs r2, 0x3
	ands r2, r6
	cmp r2, 0x2
	bne _082DF22C
	ldrb r0, [r4, 0x5]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, 0x6]
	cmp r5, r0
	bhi _082DF23E
	adds r5, r0, 0
	beq _082DF200
	subs r6, 0x1
	strb r6, [r4]
	b _082DF23E
_082DF22C:
	cmp r2, 0x3
	bne _082DF23E
_082DF230:
	ldrb r0, [r4, 0x4]
	adds r5, r0
	cmp r5, 0xFF
	bcc _082DF23E
	movs r5, 0xFF
	subs r6, 0x1
	strb r6, [r4]
_082DF23E:
	strb r5, [r4, 0x9]
	ldr r0, [sp, 0x18]
	ldrb r0, [r0, 0x7]
	adds r0, 0x1
	muls r0, r5
	lsrs r5, r0, 4
	ldrb r0, [r4, 0x2]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, 0xA]
	ldrb r0, [r4, 0x3]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, 0xB]
	movs r0, 0x10
	ands r0, r6
	str r0, [sp, 0x10]
	beq _082DF272
	adds r0, r3, 0
	adds r0, 0x10
	ldr r1, [r3, 0x8]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r3, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
_082DF272:
	ldr r5, [sp, 0x8]
	ldr r2, [r4, 0x18]
	ldr r3, [r4, 0x28]
	adr r0, _082DF27C
	bx r0
	.arm
_082DF27C:
	str r8, [sp]
	ldr r9, [r4, 0x1C]
	ldrb r10, [r4, 0xA]
	ldrb r11, [r4, 0xB]
	ldrb r0, [r4, 0x1]
	tst r0, 0x30
	beq _082DF2A0
	bl sub_82DF49C
	b _082DF460
_082DF2A0:
	mov r10, r10, lsl 16
	mov r11, r11, lsl 16
	ldrb r0, [r4, 0x1]
	tst r0, 0x8
	beq _082DF3D4
_082DF2B4:
	cmp r2, 0x4
	ble _082DF324
	subs r2, r2, r8
	movgt r9, 0
	bgt _082DF2E0
	mov r9, r8
	add r2, r2, r8
	sub r8, r2, 0x4
	sub r9, r9, r8
	ands r2, r2, 0x3
	moveq r2, 0x4
_082DF2E0:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF2E8:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	adds r5, r5, 0x40000000
	bcc _082DF2E8
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _082DF2E0
	adds r8, r8, r9
	beq _082DF464
_082DF324:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF32C:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	subs r2, r2, 0x1
	beq _082DF39C
_082DF350:
	adds r5, r5, 0x40000000
	bcc _082DF32C
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _082DF2B4
	b _082DF464
_082DF36C:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq _082DF390
	ldr r3, [sp, 0x14]
	rsb lr, r2, 0
_082DF380:
	adds r2, r0, r2
	bgt _082DF434
	sub lr, lr, r0
	b _082DF380
_082DF390:
	ldmia sp!, {r4,r12}
	mov r2, 0
	b _082DF3AC
_082DF39C:
	ldr r2, [sp, 0x10]
	cmp r2, 0
	ldrne r3, [sp, 0xC]
	bne _082DF350
_082DF3AC:
	strb r2, [r4]
	mov r0, r5, lsr 30
	bic r5, r5, 0xC0000000
	rsb r0, r0, 0x3
	mov r0, r0, lsl 3
	mov r6, r6, ror r0
	mov r7, r7, ror r0
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	b _082DF46C
_082DF3D4:
	stmdb sp!, {r4,r12}
	ldr r1, [r4, 0x20]
	mul r4, r12, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
_082DF3EC:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF3F4:
	mul lr, r9, r1
	add lr, r0, lr, asr 23
	mul r12, r10, lr
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, lr
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add r9, r9, r4
	movs lr, r9, lsr 23
	beq _082DF440
	bic r9, r9, 0x3F800000
	subs r2, r2, lr
	ble _082DF36C
	subs lr, lr, 0x1
	addeq r0, r0, r1
_082DF434:
	ldrsbne r0, [r3, lr]!
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
_082DF440:
	adds r5, r5, 0x40000000
	bcc _082DF3F4
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _082DF3EC
	sub r3, r3, 0x1
	ldmia sp!, {r4,r12}
_082DF460:
	str r9, [r4, 0x1C]
_082DF464:
	str r2, [r4, 0x18]
	str r3, [r4, 0x28]
_082DF46C:
	ldr r8, [sp]
	add r0, pc, 0x1
	bx r0
	.thumb
_082DF478:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	ble _082DF482
	adds r4, 0x40
	b _082DF178
_082DF482:
	ldr r0, [sp, 0x18]
	ldr r3, _082DF498
	str r3, [r0]
	add sp, 0x1C
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
_082DF496:
	bx r3
	.align 2, 0
_082DF498: .4byte 0x68736d53
	thumb_func_end SoundMainRAM

	.arm
	arm_func_start sub_82DF49C
sub_82DF49C: @ 82DF49C
	ldr r6, [r4, 0x24]
	ldrb r0, [r4]
	tst r0, 0x20
	bne _082DF4EC
	orr r0, r0, 0x20
	strb r0, [r4]
	ldrb r0, [r4, 0x1]
	tst r0, 0x10
	beq _082DF4D4
	ldr r1, [r6, 0xC]
	add r1, r1, r6, lsl 1
	add r1, r1, 0x20
	sub r3, r1, r3
	str r3, [r4, 0x28]
_082DF4D4:
	ldrh r0, [r6]
	cmp r0, 0
	beq _082DF4EC
	sub r3, r3, r6
	sub r3, r3, 0x10
	str r3, [r4, 0x28]
_082DF4EC:
	stmdb sp!, {r8,r12,lr}
	mov r10, r10, lsl 16
	mov r11, r11, lsl 16
	ldr r1, [r4, 0x20]
	ldrb r0, [r4, 0x1]
	tst r0, 0x8
	movne r8, 0x800000
	muleq r8, r12, r1
	ldrh r0, [r6]
	cmp r0, 0
	beq _082DF6A0
	mov r0, 0xFF000000
	str r0, [r4, 0x3C]
	ldrb r0, [r4, 0x1]
	tst r0, 0x10
	bne _082DF5F8
	bl sub_82DF758
	mov r0, r1
	add r3, r3, 0x1
	bl sub_82DF758
	sub r1, r1, r0
_082DF540:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF548:
	mul lr, r9, r1
	add lr, r0, lr, asr 23
	mul r12, r10, lr
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, lr
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add r9, r9, r8
	movs lr, r9, lsr 23
	beq _082DF5A8
	bic r9, r9, 0x3F800000
	subs r2, r2, lr
	ble _082DF5D0
	subs lr, lr, 0x1
	bne _082DF590
	add r0, r0, r1
	b _082DF59C
_082DF590:
	add r3, r3, lr
	bl sub_82DF758
	mov r0, r1
_082DF59C:
	add r3, r3, 0x1
	bl sub_82DF758
	sub r1, r1, r0
_082DF5A8:
	adds r5, r5, 0x40000000
	bcc _082DF548
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	ldr r6, [sp]
	subs r6, r6, 0x4
	str r6, [sp]
	bgt _082DF540
	sub r3, r3, 0x1
	b _082DF728
_082DF5D0:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	beq _082DF72C
	ldr r3, [r4, 0x24]
	ldr r3, [r3, 0x8]
	rsb lr, r2, 0
_082DF5E8:
	adds r2, r2, r0
	bgt _082DF590
	sub lr, lr, r0
	b _082DF5E8
_082DF5F8:
	sub r3, r3, 0x1
	bl sub_82DF758
	mov r0, r1
	sub r3, r3, 0x1
	bl sub_82DF758
	sub r1, r1, r0
_082DF610:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF618:
	mul lr, r9, r1
	add lr, r0, lr, asr 23
	mul r12, r10, lr
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, lr
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add r9, r9, r8
	movs lr, r9, lsr 23
	beq _082DF678
	bic r9, r9, 0x3F800000
	subs r2, r2, lr
	ble _082DF72C
	subs lr, lr, 0x1
	bne _082DF660
	add r0, r0, r1
	b _082DF66C
_082DF660:
	sub r3, r3, lr
	bl sub_82DF758
	mov r0, r1
_082DF66C:
	sub r3, r3, 0x1
	bl sub_82DF758
	sub r1, r1, r0
_082DF678:
	adds r5, r5, 0x40000000
	bcc _082DF618
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	ldr r6, [sp]
	subs r6, r6, 0x4
	str r6, [sp]
	bgt _082DF610
	add r3, r3, 0x2
	b _082DF728
_082DF6A0:
	ldrb r0, [r4, 0x1]
	tst r0, 0x10
	beq _082DF728
	ldrsb r0, [r3, -0x1]!
	ldrsb r1, [r3, -0x1]
	sub r1, r1, r0
_082DF6B8:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_082DF6C0:
	mul lr, r9, r1
	add lr, r0, lr, asr 23
	mul r12, r10, lr
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, lr
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add r9, r9, r8
	movs lr, r9, lsr 23
	beq _082DF704
	bic r9, r9, 0x3F800000
	subs r2, r2, lr
	ble _082DF72C
	ldrsb r0, [r3, -lr]!
	ldrsb r1, [r3, -0x1]
	sub r1, r1, r0
_082DF704:
	adds r5, r5, 0x40000000
	bcc _082DF6C0
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	ldr r6, [sp]
	subs r6, r6, 0x4
	str r6, [sp]
	bgt _082DF6B8
	add r3, r3, 0x1
_082DF728:
	ldmia sp!, {r8,r12,pc}
_082DF72C:
	mov r2, 0
	strb r2, [r4]
	mov r0, r5, lsr 30
	bic r5, r5, 0xC0000000
	rsb r0, r0, 0x3
	mov r0, r0, lsl 3
	mov r6, r6, ror r0
	mov r7, r7, ror r0
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	ldmia sp!, {r8,r12,pc}
	arm_func_end sub_82DF49C

	arm_func_start sub_82DF758
sub_82DF758: @ 82DF758
	stmdb sp!, {r0,r2,r5-r7,lr}
	mov r0, r3, lsr 6
	ldr r1, [r4, 0x3C]
	cmp r0, r1
	beq _082DF7CC
	str r0, [r4, 0x3C]
	mov r1, 0x21
	mul r2, r1, r0
	ldr r1, [r4, 0x24]
	add r2, r2, r1
	add r2, r2, 0x10
	ldr r5, _082DF7DC
	ldr r6, _082DF7E0
	mov r7, 0x40
	ldrb lr, [r2], 0x1
	strb lr, [r5], 0x1
	ldrb r1, [r2], 0x1
	b _082DF7B4
_082DF7A0:
	ldrb r1, [r2], 0x1
	mov r0, r1, lsr 4
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], 0x1
_082DF7B4:
	and r0, r1, 0xF
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], 0x1
	subs r7, r7, 0x2
	bgt _082DF7A0
_082DF7CC:
	ldr r5, _082DF7DC
	and r0, r3, 0x3F
	ldrsb r1, [r5, r0]
	ldmia sp!, {r0,r2,r5-r7,pc}
	.align 2, 0
_082DF7DC: .4byte 0x03001300
_082DF7E0: .4byte 0x08675a70
	arm_func_end sub_82DF758

	.thumb
	thumb_func_start SoundMainBTM
SoundMainBTM: @ 82DF7E4
	mov r12, r4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	movs r4, 0
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	mov r4, r12
	bx lr
	thumb_func_end SoundMainBTM

	thumb_func_start ClearChain
ClearChain: @ 82DF7FC
	ldr r3, [r0, 0x2C]
	cmp r3, 0
	beq _082DF81A
	ldr r1, [r0, 0x34]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _082DF80E
	str r1, [r2, 0x34]
	b _082DF810
_082DF80E:
	str r1, [r3, 0x20]
_082DF810:
	cmp r1, 0
	beq _082DF816
	str r2, [r1, 0x30]
_082DF816:
	movs r1, 0
	str r1, [r0, 0x2C]
_082DF81A:
	bx lr
	thumb_func_end ClearChain

	thumb_func_start ply_fine
ply_fine: @ 82DF81C
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _082DF840
_082DF826:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _082DF834
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
_082DF834:
	adds r0, r4, 0
	bl ClearChain
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _082DF826
_082DF840:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ply_fine

	thumb_func_start MPlyJmpTblCopy
MPlyJmpTblCopy: @ 82DF84C
	mov r12, lr
	movs r1, 0x24
	ldr r2, _082DF87C
_082DF852:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt _082DF852
	bx r12
	thumb_func_end MPlyJmpTblCopy

	thumb_func_start ldrb_r3_r2
ldrb_r3_r2: @ 82DF864
	ldrb r3, [r2]
	thumb_func_end ldrb_r3_r2

	non_word_aligned_thumb_func_start chk_adr_r2
chk_adr_r2: @ 82DF866
	push {r0}
	lsrs r0, r2, 25
	bne _082DF878
	ldr r0, _082DF87C
	cmp r2, r0
	bcc _082DF876
	lsrs r0, r2, 14
	beq _082DF878
_082DF876:
	movs r3, 0
_082DF878:
	pop {r0}
	bx lr
	.align 2, 0
_082DF87C: .4byte 0x086759e0
	thumb_func_end chk_adr_r2

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i: @ 82DF880
	ldr r2, [r1, 0x40]
_082DF882:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b chk_adr_r2
	thumb_func_end ld_r3_tp_adr_i

	thumb_func_start ply_goto
ply_goto: @ 82DF88C
	push {lr}
_082DF88E:
	ldr r2, [r1, 0x40]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, 0x40]
	pop {r0}
	bx r0
	thumb_func_end ply_goto

	thumb_func_start ply_patt
ply_patt: @ 82DF8AC
	ldrb r2, [r1, 0x2]
	cmp r2, 0x3
	bcs _082DF8C4
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, 0x40]
	adds r2, 0x4
	str r2, [r3, 0x44]
	ldrb r2, [r1, 0x2]
	adds r2, 0x1
	strb r2, [r1, 0x2]
	b ply_goto
_082DF8C4:
	b ply_fine
	thumb_func_end ply_patt

	thumb_func_start play_pend
play_pend: @ 82DF8C8
	ldrb r2, [r1, 0x2]
	cmp r2, 0
	beq _082DF8DA
	subs r2, 0x1
	strb r2, [r1, 0x2]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, 0x44]
	str r2, [r1, 0x40]
_082DF8DA:
	bx lr
	thumb_func_end play_pend

	thumb_func_start ply_rept
ply_rept: @ 82DF8DC
	push {lr}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	cmp r3, 0
	bne _082DF8EC
	adds r2, 0x1
	str r2, [r1, 0x40]
	b _082DF88E
_082DF8EC:
	ldrb r3, [r1, 0x3]
	adds r3, 0x1
	strb r3, [r1, 0x3]
	mov r12, r3
	bl ld_r3_tp_adr_i
	cmp r12, r3
	bcs _082DF8FE
	b _082DF88E
_082DF8FE:
	movs r3, 0
	strb r3, [r1, 0x3]
	adds r2, 0x5
	str r2, [r1, 0x40]
	pop {r0}
	bx r0
	thumb_func_end ply_rept

	thumb_func_start ply_prio
ply_prio: @ 82DF90C
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, 0x1D]
	bx r12
	thumb_func_end ply_prio

	thumb_func_start ply_tempo
ply_tempo: @ 82DF918
	mov r12, lr
	bl ld_r3_tp_adr_i
	lsls r3, 1
	strh r3, [r0, 0x1C]
	ldrh r2, [r0, 0x1E]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, 0x20]
	bx r12
	thumb_func_end ply_tempo

	thumb_func_start ply_keysh
ply_keysh: @ 82DF92C
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, 0xA]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_keysh

	thumb_func_start ply_voice
ply_voice: @ 82DF940
	mov r12, lr
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r1, 0x40]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, 0x30]
	adds r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, 0x24]
	ldr r3, [r2, 0x4]
	bl chk_adr_r2
	str r3, [r1, 0x28]
	ldr r3, [r2, 0x8]
	bl chk_adr_r2
	str r3, [r1, 0x2C]
	bx r12
	thumb_func_end ply_voice

	thumb_func_start ply_vol
ply_vol: @ 82DF970
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, 0x12]
	ldrb r3, [r1]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_vol

	thumb_func_start ply_pan
ply_pan: @ 82DF984
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, 0x14]
	ldrb r3, [r1]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_pan

	thumb_func_start ply_bend
ply_bend: @ 82DF998
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, 0xE]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_bend

	thumb_func_start ply_bendr
ply_bendr: @ 82DF9AC
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, 0xF]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_bendr

	thumb_func_start ply_lfodl
ply_lfodl: @ 82DF9C0
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, 0x1B]
	bx r12
	thumb_func_end ply_lfodl

	thumb_func_start ply_modt
ply_modt: @ 82DF9CC
	mov r12, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, 0x18]
	cmp r0, r3
	beq _082DF9E2
	strb r3, [r1, 0x18]
	ldrb r3, [r1]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1]
_082DF9E2:
	bx r12
	thumb_func_end ply_modt

	thumb_func_start ply_tune
ply_tune: @ 82DF9E4
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, 0xC]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end ply_tune

	thumb_func_start ply_port
ply_port: @ 82DF9F8
	mov r12, lr
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	ldr r0, _082DFA0C
	adds r0, r3
	bl _082DF882
	strb r3, [r0]
	bx r12
	.align 2, 0
_082DFA0C: .4byte 0x04000060
	thumb_func_end ply_port

	thumb_func_start SoundVSync_rev01
SoundVSync_rev01: @ 82DFA10
	ldr r0, _082DFCBC
	ldr r0, [r0]
	ldr r2, _082DFCC0
	ldr r3, [r0]
	subs r3, r2
	cmp r3, 0x1
	bhi _082DFA50
	ldrb r1, [r0, 0x4]
	subs r1, 0x1
	strb r1, [r0, 0x4]
	bgt _082DFA50
	ldrb r1, [r0, 0xB]
	strb r1, [r0, 0x4]
	ldr r2, _082DFA54
	ldr r1, [r2, 0x8]
	lsls r1, 7
	bcc _082DFA36
	ldr r1, _082DFA58
	str r1, [r2, 0x8]
_082DFA36:
	ldr r1, [r2, 0x14]
	lsls r1, 7
	bcc _082DFA40
	ldr r1, _082DFA58
	str r1, [r2, 0x14]
_082DFA40:
	movs r1, 0x4
	lsls r1, 8
	strh r1, [r2, 0xA]
	strh r1, [r2, 0x16]
	movs r1, 0xB6
	lsls r1, 8
	strh r1, [r2, 0xA]
	strh r1, [r2, 0x16]
_082DFA50:
	bx lr
	.align 2, 0
_082DFA54: .4byte 0x040000bc
_082DFA58: .4byte 0x84400004
	thumb_func_end SoundVSync_rev01

	thumb_func_start MPlayMain_rev01
MPlayMain_rev01: @ 82DFA5C
	ldr r2, _082DFCC0
	ldr r3, [r0, 0x34]
	cmp r2, r3
	beq _082DFA66
	bx lr
_082DFA66:
	adds r3, 0x1
	str r3, [r0, 0x34]
	push {r0,lr}
	ldr r3, [r0, 0x38]
	cmp r3, 0
	beq _082DFA78
	ldr r0, [r0, 0x3C]
	bl _082DFCB4
_082DFA78:
	pop {r0}
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	adds r7, r0, 0
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _082DFA90
	b _082DFCA4
_082DFA90:
	ldr r0, _082DFCBC
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, 0
	bl FadeOutBody_rev01
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _082DFAA4
	b _082DFCA4
_082DFAA4:
	ldrh r0, [r7, 0x22]
	ldrh r1, [r7, 0x20]
	adds r0, r1
	b _082DFBF4
_082DFAAC:
	ldrb r6, [r7, 0x8]
	ldr r5, [r7, 0x2C]
	movs r3, 0x1
	movs r4, 0
_082DFAB4:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	bne _082DFABE
	b _082DFBD0
_082DFABE:
	mov r10, r3
	orrs r4, r3
	mov r11, r4
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _082DFAF2
_082DFACA:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _082DFAE6
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _082DFAEC
	subs r0, 0x1
	strb r0, [r4, 0x10]
	bne _082DFAEC
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
	b _082DFAEC
_082DFAE6:
	adds r0, r4, 0
	bl ClearChain_rev
_082DFAEC:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _082DFACA
_082DFAF2:
	ldrb r3, [r5]
	movs r0, 0x40
	tst r0, r3
	beq _082DFB70
	adds r0, r5, 0
	bl Clear64byte_rev
	movs r0, 0x80
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0xF]
	movs r0, 0x40
	strb r0, [r5, 0x13]
	movs r0, 0x16
	strb r0, [r5, 0x19]
	movs r0, 0x1
	adds r1, r5, 0x6
	strb r0, [r1, 0x1E]
	b _082DFB70
_082DFB18:
	ldr r2, [r5, 0x40]
	ldrb r1, [r2]
	cmp r1, 0x80
	bcs _082DFB24
	ldrb r1, [r5, 0x7]
	b _082DFB2E
_082DFB24:
	adds r2, 0x1
	str r2, [r5, 0x40]
	cmp r1, 0xBD
	bcc _082DFB2E
	strb r1, [r5, 0x7]
_082DFB2E:
	cmp r1, 0xCF
	bcc _082DFB44
	mov r0, r8
	ldr r3, [r0, 0x38]
	adds r0, r1, 0
	subs r0, 0xCF
	adds r1, r7, 0
	adds r2, r5, 0
	bl _082DFCB4
	b _082DFB70
_082DFB44:
	cmp r1, 0xB0
	bls _082DFB66
	adds r0, r1, 0
	subs r0, 0xB1
	strb r0, [r7, 0xA]
	mov r3, r8
	ldr r3, [r3, 0x34]
	lsls r0, 2
	ldr r3, [r3, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl _082DFCB4
	ldrb r0, [r5]
	cmp r0, 0
	beq _082DFBCC
	b _082DFB70
_082DFB66:
	ldr r0, _082DFCB8
	subs r1, 0x80
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r5, 0x1]
_082DFB70:
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _082DFB18
	subs r0, 0x1
	strb r0, [r5, 0x1]
	ldrb r1, [r5, 0x19]
	cmp r1, 0
	beq _082DFBCC
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _082DFBCC
	ldrb r0, [r5, 0x1C]
	cmp r0, 0
	beq _082DFB92
	subs r0, 0x1
	strb r0, [r5, 0x1C]
	b _082DFBCC
_082DFB92:
	ldrb r0, [r5, 0x1A]
	adds r0, r1
	strb r0, [r5, 0x1A]
	adds r1, r0, 0
	subs r0, 0x40
	lsls r0, 24
	bpl _082DFBA6
	lsls r2, r1, 24
	asrs r2, 24
	b _082DFBAA
_082DFBA6:
	movs r0, 0x80
	subs r2, r0, r1
_082DFBAA:
	ldrb r0, [r5, 0x17]
	muls r0, r2
	asrs r2, r0, 6
	ldrb r0, [r5, 0x16]
	eors r0, r2
	lsls r0, 24
	beq _082DFBCC
	strb r2, [r5, 0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, 0x18]
	cmp r1, 0
	bne _082DFBC6
	movs r1, 0xC
	b _082DFBC8
_082DFBC6:
	movs r1, 0x3
_082DFBC8:
	orrs r0, r1
	strb r0, [r5]
_082DFBCC:
	mov r3, r10
	mov r4, r11
_082DFBD0:
	subs r6, 0x1
	ble _082DFBDC
	movs r0, 0x50
	adds r5, r0
	lsls r3, 1
	b _082DFAB4
_082DFBDC:
	ldr r0, [r7, 0xC]
	adds r0, 0x1
	str r0, [r7, 0xC]
	cmp r4, 0
	bne _082DFBEE
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, 0x4]
	b _082DFCA4
_082DFBEE:
	str r4, [r7, 0x4]
	ldrh r0, [r7, 0x22]
	subs r0, 0x96
_082DFBF4:
	strh r0, [r7, 0x22]
	cmp r0, 0x96
	bcc _082DFBFC
	b _082DFAAC
_082DFBFC:
	ldrb r2, [r7, 0x8]
	ldr r5, [r7, 0x2C]
_082DFC00:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	beq _082DFC9A
	movs r1, 0xF
	tst r1, r0
	beq _082DFC9A
	mov r9, r2
	adds r0, r7, 0
	adds r1, r5, 0
	bl TrkVolPitSet_rev01
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _082DFC90
_082DFC1E:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	bne _082DFC2E
	adds r0, r4, 0
	bl ClearChain_rev
	b _082DFC8A
_082DFC2E:
	ldrb r0, [r4, 0x1]
	movs r6, 0x7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, 0x3
	tst r0, r3
	beq _082DFC4C
	bl ChnVolSetAsm
	cmp r6, 0
	beq _082DFC4C
	ldrb r0, [r4, 0x1D]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1D]
_082DFC4C:
	ldrb r3, [r5]
	movs r0, 0xC
	tst r0, r3
	beq _082DFC8A
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _082DFC60
	movs r2, 0
_082DFC60:
	cmp r6, 0
	beq _082DFC7E
	mov r0, r8
	ldr r3, [r0, 0x30]
	adds r1, r2, 0
	ldrb r2, [r5, 0x9]
	adds r0, r6, 0
	bl _082DFCB4
	str r0, [r4, 0x20]
	ldrb r0, [r4, 0x1D]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1D]
	b _082DFC8A
_082DFC7E:
	adds r1, r2, 0
	ldrb r2, [r5, 0x9]
	ldr r0, [r4, 0x24]
	bl MidiKey2fr
	str r0, [r4, 0x20]
_082DFC8A:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _082DFC1E
_082DFC90:
	ldrb r0, [r5]
	movs r1, 0xF0
	ands r0, r1
	strb r0, [r5]
	mov r2, r9
_082DFC9A:
	subs r2, 0x1
	ble _082DFCA4
	movs r0, 0x50
	adds r5, r0
	bgt _082DFC00
_082DFCA4:
	ldr r0, _082DFCC0
	str r0, [r7, 0x34]
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
_082DFCB4:
	bx r3
	.align 2, 0
_082DFCB8: .4byte 0x08675c64
_082DFCBC: .4byte 0x03007ff0
_082DFCC0: .4byte 0x68736d53
	thumb_func_end MPlayMain_rev01

	thumb_func_start TrackStop_rev01
TrackStop_rev01: @ 82DFCC4
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5]
	movs r0, 0x80
	tst r0, r1
	beq _082DFCFC
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _082DFCFA
	movs r6, 0
_082DFCD8:
	ldrb r0, [r4]
	cmp r0, 0
	beq _082DFCF2
	ldrb r0, [r4, 0x1]
	movs r3, 0x7
	ands r0, r3
	beq _082DFCF0
	ldr r3, _082DFD04
	ldr r3, [r3]
	ldr r3, [r3, 0x2C]
	bl _082DFCB4
_082DFCF0:
	strb r6, [r4]
_082DFCF2:
	str r6, [r4, 0x2C]
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _082DFCD8
_082DFCFA:
	str r4, [r5, 0x20]
_082DFCFC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082DFD04: .4byte 0x03007ff0
	thumb_func_end TrackStop_rev01

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 82DFD08
	ldrb r1, [r4, 0x12]
	movs r0, 0x14
	ldrsb r2, [r4, r0]
	movs r3, 0x80
	adds r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x10]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _082DFD20
	movs r0, 0xFF
_082DFD20:
	strb r0, [r4, 0x2]
	movs r3, 0x7F
	subs r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x11]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _082DFD34
	movs r0, 0xFF
_082DFD34:
	strb r0, [r4, 0x3]
	bx lr
	thumb_func_end ChnVolSetAsm

	thumb_func_start ply_note_rev01
ply_note_rev01: @ 82DFD38
	push {r4-r7,lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	sub sp, 0x18
	str r1, [sp]
	adds r5, r2, 0
	ldr r1, _082DFF34
	ldr r1, [r1]
	str r1, [sp, 0x4]
	ldr r1, _082DFF38
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r5, 0x4]
	ldr r3, [r5, 0x40]
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _082DFD7E
	strb r0, [r5, 0x5]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _082DFD7C
	strb r0, [r5, 0x6]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _082DFD7C
	ldrb r1, [r5, 0x4]
	adds r1, r0
	strb r1, [r5, 0x4]
	adds r3, 0x1
_082DFD7C:
	str r3, [r5, 0x40]
_082DFD7E:
	movs r0, 0
	str r0, [sp, 0x14]
	adds r4, r5, 0
	adds r4, 0x24
	ldrb r2, [r4]
	movs r0, 0xC0
	tst r0, r2
	beq _082DFDD0
	ldrb r3, [r5, 0x5]
	movs r0, 0x40
	tst r0, r2
	beq _082DFD9E
	ldr r1, [r5, 0x2C]
	adds r1, r3
	ldrb r0, [r1]
	b _082DFDA0
_082DFD9E:
	adds r0, r3, 0
_082DFDA0:
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, [r5, 0x28]
	adds r1, r0
	mov r9, r1
	mov r6, r9
	ldrb r1, [r6]
	movs r0, 0xC0
	tst r0, r1
	beq _082DFDB8
	b _082DFF22
_082DFDB8:
	movs r0, 0x80
	tst r0, r2
	beq _082DFDD4
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	beq _082DFDCC
	subs r1, 0xC0
	lsls r1, 1
	str r1, [sp, 0x14]
_082DFDCC:
	ldrb r3, [r6, 0x1]
	b _082DFDD4
_082DFDD0:
	mov r9, r4
	ldrb r3, [r5, 0x5]
_082DFDD4:
	str r3, [sp, 0x8]
	ldr r6, [sp]
	ldrb r1, [r6, 0x9]
	ldrb r0, [r5, 0x1D]
	adds r0, r1
	cmp r0, 0xFF
	bls _082DFDE4
	movs r0, 0xFF
_082DFDE4:
	str r0, [sp, 0x10]
	mov r6, r9
	ldrb r0, [r6]
	movs r6, 0x7
	ands r6, r0
	str r6, [sp, 0xC]
	beq _082DFE24
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
	cmp r4, 0
	bne _082DFDFC
	b _082DFF22
_082DFDFC:
	subs r6, 0x1
	lsls r0, r6, 6
	adds r4, r0
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _082DFE78
	movs r0, 0x40
	tst r0, r1
	bne _082DFE78
	ldrb r1, [r4, 0x13]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bcc _082DFE78
	beq _082DFE1C
	b _082DFF22
_082DFE1C:
	ldr r0, [r4, 0x2C]
	cmp r0, r5
	bcs _082DFE78
	b _082DFF22
_082DFE24:
	ldr r6, [sp, 0x10]
	adds r7, r5, 0
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x4]
	ldrb r3, [r4, 0x6]
	adds r4, 0x50
_082DFE32:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _082DFE78
	movs r0, 0x40
	tst r0, r1
	beq _082DFE4C
	cmp r2, 0
	bne _082DFE50
	adds r2, 0x1
	ldrb r6, [r4, 0x13]
	ldr r7, [r4, 0x2C]
	b _082DFE6A
_082DFE4C:
	cmp r2, 0
	bne _082DFE6C
_082DFE50:
	ldrb r0, [r4, 0x13]
	cmp r0, r6
	bcs _082DFE5C
	adds r6, r0, 0
	ldr r7, [r4, 0x2C]
	b _082DFE6A
_082DFE5C:
	bhi _082DFE6C
	ldr r0, [r4, 0x2C]
	cmp r0, r7
	bls _082DFE68
	adds r7, r0, 0
	b _082DFE6A
_082DFE68:
	bcc _082DFE6C
_082DFE6A:
	mov r8, r4
_082DFE6C:
	adds r4, 0x40
	subs r3, 0x1
	bgt _082DFE32
	mov r4, r8
	cmp r4, 0
	beq _082DFF22
_082DFE78:
	adds r0, r4, 0
	bl ClearChain_rev
	movs r1, 0
	str r1, [r4, 0x30]
	ldr r3, [r5, 0x20]
	str r3, [r4, 0x34]
	cmp r3, 0
	beq _082DFE8C
	str r4, [r3, 0x30]
_082DFE8C:
	str r4, [r5, 0x20]
	str r5, [r4, 0x2C]
	ldrb r0, [r5, 0x1B]
	strb r0, [r5, 0x1C]
	cmp r0, r1
	beq _082DFE9E
	adds r1, r5, 0
	bl clear_modM
_082DFE9E:
	ldr r0, [sp]
	adds r1, r5, 0
	bl TrkVolPitSet_rev01
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	strb r0, [r4, 0x13]
	ldr r0, [sp, 0x8]
	strb r0, [r4, 0x8]
	ldr r0, [sp, 0x14]
	strb r0, [r4, 0x14]
	mov r6, r9
	ldrb r0, [r6]
	strb r0, [r4, 0x1]
	ldr r7, [r6, 0x4]
	str r7, [r4, 0x24]
	ldr r0, [r6, 0x8]
	str r0, [r4, 0x4]
	ldrh r0, [r5, 0x1E]
	strh r0, [r4, 0xC]
	bl ChnVolSetAsm
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _082DFED8
	movs r3, 0
_082DFED8:
	ldr r6, [sp, 0xC]
	cmp r6, 0
	beq _082DFF06
	mov r6, r9
	ldrb r0, [r6, 0x2]
	strb r0, [r4, 0x1E]
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	bne _082DFEF2
	movs r0, 0x70
	tst r0, r1
	bne _082DFEF4
_082DFEF2:
	movs r1, 0x8
_082DFEF4:
	strb r1, [r4, 0x1F]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	ldr r0, [sp, 0xC]
	ldr r3, [sp, 0x4]
	ldr r3, [r3, 0x30]
	bl _082DFCB4
	b _082DFF14
_082DFF06:
	ldr r0, [r5, 0x3C]
	str r0, [r4, 0x18]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	adds r0, r7, 0
	bl MidiKey2fr
_082DFF14:
	str r0, [r4, 0x20]
	movs r0, 0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, 0xF0
	ands r0, r1
	strb r0, [r5]
_082DFF22:
	add sp, 0x18
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r0}
	bx r0
	.align 2, 0
_082DFF34: .4byte 0x03007ff0
_082DFF38: .4byte 0x08675c64
	thumb_func_end ply_note_rev01

	thumb_func_start ply_endtie_rev01
ply_endtie_rev01: @ 82DFF3C
	push {r4,r5}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	cmp r3, 0x80
	bcs _082DFF4E
	strb r3, [r1, 0x5]
	adds r2, 0x1
	str r2, [r1, 0x40]
	b _082DFF50
_082DFF4E:
	ldrb r3, [r1, 0x5]
_082DFF50:
	ldr r1, [r1, 0x20]
	cmp r1, 0
	beq _082DFF78
	movs r4, 0x83
	movs r5, 0x40
_082DFF5A:
	ldrb r2, [r1]
	tst r2, r4
	beq _082DFF72
	tst r2, r5
	bne _082DFF72
	ldrb r0, [r1, 0x11]
	cmp r0, r3
	bne _082DFF72
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1]
	b _082DFF78
_082DFF72:
	ldr r1, [r1, 0x34]
	cmp r1, 0
	bne _082DFF5A
_082DFF78:
	pop {r4,r5}
	bx lr
	thumb_func_end ply_endtie_rev01

	thumb_func_start clear_modM
clear_modM: @ 82DFF7C
	movs r2, 0
	strb r2, [r1, 0x16]
	strb r2, [r1, 0x1A]
	ldrb r2, [r1, 0x18]
	cmp r2, 0
	bne _082DFF8C
	movs r2, 0xC
	b _082DFF8E
_082DFF8C:
	movs r2, 0x3
_082DFF8E:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	thumb_func_end clear_modM

	thumb_func_start ld_r3_tp_adr_i_rev
ld_r3_tp_adr_i_rev: @ 82DFF98
	ldr r2, [r1, 0x40]
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	bx lr
	thumb_func_end ld_r3_tp_adr_i_rev

	thumb_func_start ply_lfos_rev01
ply_lfos_rev01: @ 82DFFA4
	mov r12, lr
	bl ld_r3_tp_adr_i_rev
	strb r3, [r1, 0x19]
	cmp r3, 0
	bne _082DFFB4
	bl clear_modM
_082DFFB4:
	bx r12
	thumb_func_end ply_lfos_rev01

	thumb_func_start ply_mod_rev01
ply_mod_rev01: @ 82DFFB8
	mov r12, lr
	bl ld_r3_tp_adr_i_rev
	strb r3, [r1, 0x17]
	cmp r3, 0
	bne _082DFFC8
	bl clear_modM
_082DFFC8:
	bx r12
	thumb_func_end ply_mod_rev01

	thumb_func_start MidiKey2fr
MidiKey2fr: @ 82DFFCC
	push {r4-r7,lr}
	mov r12, r0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r7, r2, 24
	cmp r6, 0xB2
	bls _082DFFE0
	movs r6, 0xB2
	movs r7, 0xFF
	lsls r7, 24
_082DFFE0:
	ldr r3, _082E0028
	adds r0, r6, r3
	ldrb r5, [r0]
	ldr r4, _082E002C
	movs r2, 0xF
	adds r0, r5, 0
	ands r0, r2
	lsls r0, 2
	adds r0, r4
	lsrs r1, r5, 4
	ldr r5, [r0]
	lsrs r5, r1
	adds r0, r6, 0x1
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 2
	adds r0, r4
	lsrs r1, 4
	ldr r0, [r0]
	lsrs r0, r1
	mov r1, r12
	ldr r4, [r1, 0x4]
	subs r0, r5
	adds r1, r7, 0
	bl umul3232H32
	adds r1, r0, 0
	adds r1, r5, r1
	adds r0, r4, 0
	bl umul3232H32
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E0028: .4byte 0x08675a80
_082E002C: .4byte 0x08675b34
	thumb_func_end MidiKey2fr

	thumb_func_start DummyFunc
DummyFunc: @ 82E0030
	bx lr
	thumb_func_end DummyFunc

	thumb_func_start MPlayContinue
MPlayContinue: @ 82E0034
	adds r2, r0, 0
	ldr r3, [r2, 0x34]
	ldr r0, _082E0048
	cmp r3, r0
	bne _082E0046
	ldr r0, [r2, 0x4]
	ldr r1, _082E004C
	ands r0, r1
	str r0, [r2, 0x4]
_082E0046:
	bx lr
	.align 2, 0
_082E0048: .4byte 0x68736d53
_082E004C: .4byte 0x7fffffff
	thumb_func_end MPlayContinue

	thumb_func_start MPlayFadeOut
@ void MPlayFadeOut(mplay_table_entry *a1, s16 a2)
MPlayFadeOut: @ 82E0050
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _082E006C
	cmp r3, r0
	bne _082E0068
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r2, 0x28]
_082E0068:
	bx lr
	.align 2, 0
_082E006C: .4byte 0x68736d53
	thumb_func_end MPlayFadeOut

	thumb_func_start m4aSoundInit
m4aSoundInit: @ 82E0070
	push {r4-r6,lr}
	ldr r0, _082E00F0
	movs r1, 0x2
	negs r1, r1
	ands r0, r1
	ldr r1, _082E00F4
	ldr r2, _082E00F8
	bl CpuSet
	ldr r0, _082E00FC
	bl SoundInit_rev01
	ldr r0, _082E0100
	bl MPlayExtender
	ldr r0, _082E0104
	bl SoundMode_rev01
	ldr r0, _082E0108
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _082E00BE
	ldr r6, _082E010C
	adds r5, r0, 0
_082E00A2:
	ldr r4, [r6]
	ldr r1, [r6, 0x4]
	ldrb r2, [r6, 0x8]
	adds r0, r4, 0
	bl MPlayOpen_rev01
	ldrh r0, [r6, 0xA]
	strb r0, [r4, 0xB]
	ldr r0, _082E0110
	str r0, [r4, 0x18]
	adds r6, 0xC
	subs r5, 0x1
	cmp r5, 0
	bne _082E00A2
_082E00BE:
	ldr r0, _082E0114
	ldr r1, _082E0118
	movs r2, 0x34
	bl memcpy
	movs r5, 0
	movs r6, 0
_082E00CC:
	lsls r0, r5, 6
	ldr r1, _082E011C
	adds r0, r1
	ldr r4, _082E0120
	adds r4, r6, r4
	adds r1, r4, 0
	movs r2, 0x2
	bl MPlayOpen_rev01
	movs r0, 0
	str r0, [r4, 0x20]
	adds r6, 0xA0
	adds r5, 0x1
	cmp r5, 0x1
	ble _082E00CC
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E00F0: .4byte SoundMainRAM + 1
_082E00F4: .4byte 0x03001aa8
_082E00F8: .4byte 0x04000200
_082E00FC: .4byte 0x03006380
_082E0100: .4byte 0x030074f0
_082E0104: .4byte 0x0094c500
_082E0108: .4byte 0x00000004
_082E010C: .4byte 0x086b49c0
_082E0110: .4byte 0x030077f0
_082E0114: .4byte 0x030077b0
_082E0118: .4byte 0x08675c98
_082E011C: .4byte 0x030073a0
_082E0120: .4byte 0x03007670
	thumb_func_end m4aSoundInit

	thumb_func_start m4aSoundMain
m4aSoundMain: @ 82E0124
	push {lr}
	bl SoundMain
	pop {r0}
	bx r0
	thumb_func_end m4aSoundMain

	thumb_func_start m4aSongNumStart
m4aSongNumStart: @ 82E0130
	push {lr}
	lsls r0, 16
	ldr r2, _082E0154
	ldr r1, _082E0158
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r0]
	adds r0, r2, 0
	bl MPlayStart_rev01
	pop {r0}
	bx r0
	.align 2, 0
_082E0154: .4byte 0x086b49c0
_082E0158: .4byte 0x086b49f0
	thumb_func_end m4aSongNumStart

	thumb_func_start m4aSongNumStartOrChange
m4aSongNumStartOrChange: @ 82E015C
	push {lr}
	lsls r0, 16
	ldr r2, _082E0188
	ldr r1, _082E018C
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r2, [r0]
	cmp r3, r2
	beq _082E0190
	adds r0, r1, 0
	adds r1, r2, 0
	bl MPlayStart_rev01
	b _082E01A4
	.align 2, 0
_082E0188: .4byte 0x086b49c0
_082E018C: .4byte 0x086b49f0
_082E0190:
	ldr r2, [r1, 0x4]
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	beq _082E019C
	cmp r2, 0
	bge _082E01A4
_082E019C:
	adds r0, r1, 0
	adds r1, r3, 0
	bl MPlayStart_rev01
_082E01A4:
	pop {r0}
	bx r0
	thumb_func_end m4aSongNumStartOrChange

	thumb_func_start m4aSongNumStartOrContinue
m4aSongNumStartOrContinue: @ 82E01A8
	push {lr}
	lsls r0, 16
	ldr r2, _082E01D4
	ldr r1, _082E01D8
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r2, [r0]
	cmp r3, r2
	beq _082E01DC
	adds r0, r1, 0
	adds r1, r2, 0
	bl MPlayStart_rev01
	b _082E01F8
	.align 2, 0
_082E01D4: .4byte 0x086b49c0
_082E01D8: .4byte 0x086b49f0
_082E01DC:
	ldr r2, [r1, 0x4]
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	bne _082E01EE
	adds r0, r1, 0
	adds r1, r3, 0
	bl MPlayStart_rev01
	b _082E01F8
_082E01EE:
	cmp r2, 0
	bge _082E01F8
	adds r0, r1, 0
	bl MPlayContinue
_082E01F8:
	pop {r0}
	bx r0
	thumb_func_end m4aSongNumStartOrContinue

	thumb_func_start m4aSongNumStop
m4aSongNumStop: @ 82E01FC
	push {lr}
	lsls r0, 16
	ldr r2, _082E0228
	ldr r1, _082E022C
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	bne _082E0222
	adds r0, r2, 0
	bl MPlayStop_rev01
_082E0222:
	pop {r0}
	bx r0
	.align 2, 0
_082E0228: .4byte 0x086b49c0
_082E022C: .4byte 0x086b49f0
	thumb_func_end m4aSongNumStop

	thumb_func_start m4aSongNumContinue
m4aSongNumContinue: @ 82E0230
	push {lr}
	lsls r0, 16
	ldr r2, _082E025C
	ldr r1, _082E0260
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	bne _082E0256
	adds r0, r2, 0
	bl MPlayContinue
_082E0256:
	pop {r0}
	bx r0
	.align 2, 0
_082E025C: .4byte 0x086b49c0
_082E0260: .4byte 0x086b49f0
	thumb_func_end m4aSongNumContinue

	thumb_func_start m4aMPlayAllStop
m4aMPlayAllStop: @ 82E0264
	push {r4,r5,lr}
	ldr r0, _082E029C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _082E0282
	ldr r5, _082E02A0
	adds r4, r0, 0
_082E0274:
	ldr r0, [r5]
	bl MPlayStop_rev01
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bne _082E0274
_082E0282:
	ldr r5, _082E02A4
	movs r4, 0x1
_082E0286:
	adds r0, r5, 0
	bl MPlayStop_rev01
	adds r5, 0x40
	subs r4, 0x1
	cmp r4, 0
	bge _082E0286
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E029C: .4byte 0x00000004
_082E02A0: .4byte 0x086b49c0
_082E02A4: .4byte 0x030073a0
	thumb_func_end m4aMPlayAllStop

	thumb_func_start m4aMPlayContinue
m4aMPlayContinue: @ 82E02A8
	push {lr}
	bl MPlayContinue
	pop {r0}
	bx r0
	thumb_func_end m4aMPlayContinue

	thumb_func_start m4aMPlayAllContinue
m4aMPlayAllContinue: @ 82E02B2
	push {r4,r5,lr}
	ldr r0, _082E02EC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _082E02D2
	ldr r5, _082E02F0
	adds r4, r0, 0
_082E02C4:
	ldr r0, [r5]
	bl MPlayContinue
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bne _082E02C4
_082E02D2:
	ldr r5, _082E02F4
	movs r4, 0x1
_082E02D6:
	adds r0, r5, 0
	bl MPlayContinue
	adds r5, 0x40
	subs r4, 0x1
	cmp r4, 0
	bge _082E02D6
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E02EC: .4byte 0x00000004
_082E02F0: .4byte 0x086b49c0
_082E02F4: .4byte 0x030073a0
	thumb_func_end m4aMPlayAllContinue

	thumb_func_start m4aMPlayFadeOut
@ void m4aMPlayFadeOut(mplay_table_entry *a1, u16 a2)
m4aMPlayFadeOut: @ 82E02F8
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl MPlayFadeOut
	pop {r0}
	bx r0
	thumb_func_end m4aMPlayFadeOut

	thumb_func_start sub_82E0308
sub_82E0308: @ 82E0308
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _082E0320
	cmp r3, r0
	bne _082E031E
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	ldr r0, _082E0324
	strh r0, [r2, 0x28]
_082E031E:
	bx lr
	.align 2, 0
_082E0320: .4byte 0x68736d53
_082E0324: .4byte 0x00000101
	thumb_func_end sub_82E0308

	thumb_func_start sub_82E0328
sub_82E0328: @ 82E0328
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _082E0348
	cmp r3, r0
	bne _082E0346
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	movs r0, 0x2
	strh r0, [r2, 0x28]
	ldr r0, [r2, 0x4]
	ldr r1, _082E034C
	ands r0, r1
	str r0, [r2, 0x4]
_082E0346:
	bx lr
	.align 2, 0
_082E0348: .4byte 0x68736d53
_082E034C: .4byte 0x7fffffff
	thumb_func_end sub_82E0328

	thumb_func_start m4aMPlayImmInit
m4aMPlayImmInit: @ 82E0350
	push {r4-r7,lr}
	ldrb r5, [r0, 0x8]
	ldr r4, [r0, 0x2C]
	cmp r5, 0
	ble _082E0392
	movs r7, 0x80
_082E035C:
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _082E038A
	movs r6, 0x40
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _082E038A
	adds r0, r4, 0
	bl Clear64byte_rev
	strb r7, [r4]
	movs r0, 0x2
	strb r0, [r4, 0xF]
	strb r6, [r4, 0x13]
	movs r0, 0x16
	strb r0, [r4, 0x19]
	adds r1, r4, 0
	adds r1, 0x24
	movs r0, 0x1
	strb r0, [r1]
_082E038A:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _082E035C
_082E0392:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end m4aMPlayImmInit

	thumb_func_start MPlayExtender
@ int MPlayExtender(void *dest)
MPlayExtender: @ 82E0398
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r1, _082E0460
	movs r0, 0x8F
	strh r0, [r1]
	ldr r3, _082E0464
	movs r2, 0
	strh r2, [r3]
	ldr r0, _082E0468
	movs r1, 0x8
	strb r1, [r0]
	adds r0, 0x6
	strb r1, [r0]
	adds r0, 0x10
	strb r1, [r0]
	subs r0, 0x14
	movs r1, 0x80
	strb r1, [r0]
	adds r0, 0x8
	strb r1, [r0]
	adds r0, 0x10
	strb r1, [r0]
	subs r0, 0xD
	strb r2, [r0]
	movs r0, 0x77
	strb r0, [r3]
	ldr r0, _082E046C
	ldr r4, [r0]
	ldr r6, [r4]
	ldr r0, _082E0470
	cmp r6, r0
	bne _082E0458
	adds r0, r6, 0x1
	str r0, [r4]
	ldr r1, _082E0474
	ldr r0, _082E0478
	str r0, [r1, 0x20]
	ldr r0, _082E047C
	str r0, [r1, 0x44]
	ldr r0, _082E0480
	str r0, [r1, 0x4C]
	ldr r0, _082E0484
	str r0, [r1, 0x70]
	ldr r0, _082E0488
	str r0, [r1, 0x74]
	ldr r0, _082E048C
	str r0, [r1, 0x78]
	ldr r0, _082E0490
	str r0, [r1, 0x7C]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r0, _082E0494
	str r0, [r2]
	adds r1, 0x84
	ldr r0, _082E0498
	str r0, [r1]
	str r5, [r4, 0x1C]
	ldr r0, _082E049C
	str r0, [r4, 0x28]
	ldr r0, _082E04A0
	str r0, [r4, 0x2C]
	ldr r0, _082E04A4
	str r0, [r4, 0x30]
	ldr r0, _082E04A8
	movs r1, 0
	strb r0, [r4, 0xC]
	str r1, [sp]
	ldr r2, _082E04AC
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	movs r0, 0x1
	strb r0, [r5, 0x1]
	movs r0, 0x11
	strb r0, [r5, 0x1C]
	adds r1, r5, 0
	adds r1, 0x41
	movs r0, 0x2
	strb r0, [r1]
	adds r1, 0x1B
	movs r0, 0x22
	strb r0, [r1]
	adds r1, 0x25
	movs r0, 0x3
	strb r0, [r1]
	adds r1, 0x1B
	movs r0, 0x44
	strb r0, [r1]
	adds r1, 0x24
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x88
	strb r0, [r1, 0x1C]
	str r6, [r4]
_082E0458:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E0460: .4byte 0x04000084
_082E0464: .4byte 0x04000080
_082E0468: .4byte 0x04000063
_082E046C: .4byte 0x03007ff0
_082E0470: .4byte 0x68736d53
_082E0474: .4byte 0x03007460
_082E0478: .4byte ply_memacc + 1
_082E047C: .4byte ply_lfos_rev01 + 1
_082E0480: .4byte ply_mod_rev01 + 1
_082E0484: .4byte ply_xcmd + 1
_082E0488: .4byte ply_endtie_rev01 + 1
_082E048C: .4byte SampFreqSet_rev01 + 1
_082E0490: .4byte TrackStop_rev01 + 1
_082E0494: .4byte FadeOutBody_rev01 + 1
_082E0498: .4byte TrkVolPitSet_rev01 + 1
_082E049C: .4byte CgbSound + 1
_082E04A0: .4byte CgbOscOff + 1
_082E04A4: .4byte MidiKey2CgbFr + 1
_082E04A8: .4byte 0x00000000
_082E04AC: .4byte 0x05000040
	thumb_func_end MPlayExtender

	thumb_func_start MusicPlayerJumpTableCopy
MusicPlayerJumpTableCopy: @ 82E04B0
	swi 0x2A
	bx lr
	thumb_func_end MusicPlayerJumpTableCopy

	thumb_func_start ClearChain_rev
ClearChain_rev: @ 82E04B4
	push {lr}
	ldr r1, _082E04C4
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_082E04C4: .4byte 0x030074e8
	thumb_func_end ClearChain_rev

	thumb_func_start Clear64byte_rev
Clear64byte_rev: @ 82E04C8
	push {lr}
	ldr r1, _082E04D8
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_082E04D8: .4byte 0x030074ec
	thumb_func_end Clear64byte_rev

	thumb_func_start SoundInit_rev01
@ int SoundInit_rev01(void *dest)
SoundInit_rev01: @ 82E04DC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r3, 0
	str r3, [r5]
	ldr r1, _082E0594
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 18
	ands r0, r2
	cmp r0, 0
	beq _082E04F8
	ldr r0, _082E0598
	str r0, [r1]
_082E04F8:
	ldr r1, _082E059C
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _082E0506
	ldr r0, _082E0598
	str r0, [r1]
_082E0506:
	ldr r0, _082E05A0
	movs r2, 0x80
	lsls r2, 3
	adds r1, r2, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	ldr r1, _082E05A4
	movs r0, 0x8F
	strh r0, [r1]
	subs r1, 0x2
	ldr r2, _082E05A8
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, _082E05AC
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _082E05B0
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r5, r2
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _082E05B4
	str r0, [r1]
	adds r1, 0x8
	movs r2, 0x98
	lsls r2, 4
	adds r0, r5, r2
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _082E05B8
	str r0, [r1]
	ldr r0, _082E05BC
	str r5, [r0]
	str r3, [sp]
	ldr r2, _082E05C0
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	movs r0, 0x8
	strb r0, [r5, 0x6]
	movs r0, 0xF
	strb r0, [r5, 0x7]
	ldr r0, _082E05C4
	str r0, [r5, 0x38]
	ldr r0, _082E05C8
	str r0, [r5, 0x28]
	str r0, [r5, 0x2C]
	str r0, [r5, 0x30]
	str r0, [r5, 0x3C]
	ldr r4, _082E05CC
	adds r0, r4, 0
	bl MPlyJmpTblCopy
	str r4, [r5, 0x34]
	movs r0, 0x80
	lsls r0, 11
	bl SampFreqSet_rev01
	ldr r0, _082E05D0
	str r0, [r5]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E0594: .4byte 0x040000c4
_082E0598: .4byte 0x84400004
_082E059C: .4byte 0x040000d0
_082E05A0: .4byte 0x040000c6
_082E05A4: .4byte 0x04000084
_082E05A8: .4byte 0x0000a90e
_082E05AC: .4byte 0x04000089
_082E05B0: .4byte 0x040000bc
_082E05B4: .4byte 0x040000a0
_082E05B8: .4byte 0x040000a4
_082E05BC: .4byte 0x03007ff0
_082E05C0: .4byte 0x050003ec
_082E05C4: .4byte ply_note_rev01 + 1
_082E05C8: .4byte DummyFunc_rev + 1
_082E05CC: .4byte 0x03007460
_082E05D0: .4byte 0x68736d53
	thumb_func_end SoundInit_rev01

	thumb_func_start SampFreqSet_rev01
SampFreqSet_rev01: @ 82E05D4
	push {r4-r6,lr}
	adds r2, r0, 0
	ldr r0, _082E0654
	ldr r4, [r0]
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r2
	lsrs r2, r0, 16
	movs r6, 0
	strb r2, [r4, 0x8]
	ldr r1, _082E0658
	subs r0, r2, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r5, [r0]
	str r5, [r4, 0x10]
	movs r0, 0xC6
	lsls r0, 3
	adds r1, r5, 0
	bl __divsi3
	strb r0, [r4, 0xB]
	ldr r0, _082E065C
	muls r0, r5
	ldr r1, _082E0660
	adds r0, r1
	ldr r1, _082E0664
	bl __divsi3
	adds r1, r0, 0
	str r1, [r4, 0x14]
	movs r0, 0x80
	lsls r0, 17
	bl __divsi3
	adds r0, 0x1
	asrs r0, 1
	str r0, [r4, 0x18]
	ldr r0, _082E0668
	strh r6, [r0]
	ldr r4, _082E066C
	ldr r0, _082E0670
	adds r1, r5, 0
	bl __divsi3
	negs r0, r0
	strh r0, [r4]
	bl SoundVSyncOn_rev01
	ldr r1, _082E0674
_082E0638:
	ldrb r0, [r1]
	cmp r0, 0x9F
	beq _082E0638
	ldr r1, _082E0674
_082E0640:
	ldrb r0, [r1]
	cmp r0, 0x9F
	bne _082E0640
	ldr r1, _082E0668
	movs r0, 0x80
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E0654: .4byte 0x03007ff0
_082E0658: .4byte 0x08675b64
_082E065C: .4byte 0x00091d1b
_082E0660: .4byte 0x00001388
_082E0664: .4byte 0x00002710
_082E0668: .4byte 0x04000102
_082E066C: .4byte 0x04000100
_082E0670: .4byte 0x00044940
_082E0674: .4byte 0x04000006
	thumb_func_end SampFreqSet_rev01

	thumb_func_start SoundMode_rev01
SoundMode_rev01: @ 82E0678
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, _082E0704
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, _082E0708
	cmp r1, r0
	bne _082E06FE
	adds r0, r1, 0x1
	str r0, [r5]
	movs r4, 0xFF
	ands r4, r3
	cmp r4, 0
	beq _082E069A
	movs r0, 0x7F
	ands r4, r0
	strb r4, [r5, 0x5]
_082E069A:
	movs r4, 0xF0
	lsls r4, 4
	ands r4, r3
	cmp r4, 0
	beq _082E06BA
	lsrs r0, r4, 8
	strb r0, [r5, 0x6]
	movs r4, 0xC
	adds r0, r5, 0
	adds r0, 0x50
	movs r1, 0
_082E06B0:
	strb r1, [r0]
	subs r4, 0x1
	adds r0, 0x40
	cmp r4, 0
	bne _082E06B0
_082E06BA:
	movs r4, 0xF0
	lsls r4, 8
	ands r4, r3
	cmp r4, 0
	beq _082E06C8
	lsrs r0, r4, 12
	strb r0, [r5, 0x7]
_082E06C8:
	movs r4, 0xB0
	lsls r4, 16
	ands r4, r3
	cmp r4, 0
	beq _082E06E6
	movs r0, 0xC0
	lsls r0, 14
	ands r0, r4
	lsrs r4, r0, 14
	ldr r2, _082E070C
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r4
	strb r0, [r2]
_082E06E6:
	movs r4, 0xF0
	lsls r4, 12
	ands r4, r3
	cmp r4, 0
	beq _082E06FA
	bl SoundVSyncOff_rev01
	adds r0, r4, 0
	bl SampFreqSet_rev01
_082E06FA:
	ldr r0, _082E0708
	str r0, [r5]
_082E06FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E0704: .4byte 0x03007ff0
_082E0708: .4byte 0x68736d53
_082E070C: .4byte 0x04000089
	thumb_func_end SoundMode_rev01

	thumb_func_start SoundClear_rev01
SoundClear_rev01: @ 82E0710
	push {r4-r7,lr}
	ldr r0, _082E075C
	ldr r6, [r0]
	ldr r1, [r6]
	ldr r0, _082E0760
	cmp r1, r0
	bne _082E0756
	adds r0, r1, 0x1
	str r0, [r6]
	movs r5, 0xC
	adds r4, r6, 0
	adds r4, 0x50
	movs r0, 0
_082E072A:
	strb r0, [r4]
	subs r5, 0x1
	adds r4, 0x40
	cmp r5, 0
	bgt _082E072A
	ldr r4, [r6, 0x1C]
	cmp r4, 0
	beq _082E0752
	movs r5, 0x1
	movs r7, 0
_082E073E:
	lsls r0, r5, 24
	lsrs r0, 24
	ldr r1, [r6, 0x2C]
	bl _call_via_r1
	strb r7, [r4]
	adds r5, 0x1
	adds r4, 0x40
	cmp r5, 0x4
	ble _082E073E
_082E0752:
	ldr r0, _082E0760
	str r0, [r6]
_082E0756:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E075C: .4byte 0x03007ff0
_082E0760: .4byte 0x68736d53
	thumb_func_end SoundClear_rev01

	thumb_func_start SoundVSyncOff_rev01
SoundVSyncOff_rev01: @ 82E0764
	push {lr}
	sub sp, 0x4
	ldr r0, _082E07C4
	ldr r2, [r0]
	ldr r1, [r2]
	ldr r3, _082E07C8
	adds r0, r1, r3
	cmp r0, 0x1
	bhi _082E07BC
	adds r0, r1, 0
	adds r0, 0xA
	str r0, [r2]
	ldr r1, _082E07CC
	ldr r0, [r1]
	movs r3, 0x80
	lsls r3, 18
	ands r0, r3
	cmp r0, 0
	beq _082E078E
	ldr r0, _082E07D0
	str r0, [r1]
_082E078E:
	ldr r1, _082E07D4
	ldr r0, [r1]
	ands r0, r3
	cmp r0, 0
	beq _082E079C
	ldr r0, _082E07D0
	str r0, [r1]
_082E079C:
	ldr r0, _082E07D8
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xD4
	lsls r0, 2
	adds r1, r2, r0
	ldr r2, _082E07DC
	mov r0, sp
	bl CpuSet
_082E07BC:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_082E07C4: .4byte 0x03007ff0
_082E07C8: .4byte 0x978c92ad
_082E07CC: .4byte 0x040000c4
_082E07D0: .4byte 0x84400004
_082E07D4: .4byte 0x040000d0
_082E07D8: .4byte 0x040000c6
_082E07DC: .4byte 0x05000318
	thumb_func_end SoundVSyncOff_rev01

	thumb_func_start SoundVSyncOn_rev01
SoundVSyncOn_rev01: @ 82E07E0
	push {r4,lr}
	ldr r0, _082E0810
	ldr r2, [r0]
	ldr r3, [r2]
	ldr r0, _082E0814
	cmp r3, r0
	beq _082E0808
	ldr r0, _082E0818
	movs r4, 0xB6
	lsls r4, 8
	adds r1, r4, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	ldrb r0, [r2, 0x4]
	movs r0, 0
	strb r0, [r2, 0x4]
	adds r0, r3, 0
	subs r0, 0xA
	str r0, [r2]
_082E0808:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E0810: .4byte 0x03007ff0
_082E0814: .4byte 0x68736d53
_082E0818: .4byte 0x040000c6
	thumb_func_end SoundVSyncOn_rev01

	thumb_func_start MPlayOpen_rev01
MPlayOpen_rev01: @ 82E081C
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0
	beq _082E0880
	cmp r4, 0x10
	bls _082E0830
	movs r4, 0x10
_082E0830:
	ldr r0, _082E0888
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, _082E088C
	cmp r1, r0
	bne _082E0880
	adds r0, r1, 0x1
	str r0, [r5]
	adds r0, r7, 0
	bl Clear64byte_rev
	str r6, [r7, 0x2C]
	strb r4, [r7, 0x8]
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, 0x4]
	cmp r4, 0
	beq _082E0864
	movs r1, 0
_082E0856:
	strb r1, [r6]
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, 0x50
	cmp r4, 0
	bne _082E0856
_082E0864:
	ldr r0, [r5, 0x20]
	cmp r0, 0
	beq _082E0874
	str r0, [r7, 0x38]
	ldr r0, [r5, 0x24]
	str r0, [r7, 0x3C]
	movs r0, 0
	str r0, [r5, 0x20]
_082E0874:
	str r7, [r5, 0x24]
	ldr r0, _082E0890
	str r0, [r5, 0x20]
	ldr r0, _082E088C
	str r0, [r5]
	str r0, [r7, 0x34]
_082E0880:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E0888: .4byte 0x03007ff0
_082E088C: .4byte 0x68736d53
_082E0890: .4byte MPlayMain_rev01 + 1
	thumb_func_end MPlayOpen_rev01

	thumb_func_start MPlayStart_rev01
MPlayStart_rev01: @ 82E0894
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r1, 0
	ldr r1, [r5, 0x34]
	ldr r0, _082E0974
	cmp r1, r0
	bne _082E096A
	ldrb r0, [r5, 0xB]
	ldrb r2, [r7, 0x2]
	cmp r0, 0
	beq _082E08D6
	ldr r0, [r5]
	cmp r0, 0
	beq _082E08C0
	ldr r1, [r5, 0x2C]
	movs r0, 0x40
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _082E08CC
_082E08C0:
	ldr r1, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	cmp r0, 0
	beq _082E08D6
	cmp r1, 0
	blt _082E08D6
_082E08CC:
	ldrb r0, [r7, 0x2]
	adds r2, r0, 0
	ldrb r0, [r5, 0x9]
	cmp r0, r2
	bhi _082E096A
_082E08D6:
	ldr r0, [r5, 0x34]
	adds r0, 0x1
	str r0, [r5, 0x34]
	movs r1, 0
	str r1, [r5, 0x4]
	str r7, [r5]
	ldr r0, [r7, 0x4]
	str r0, [r5, 0x30]
	strb r2, [r5, 0x9]
	str r1, [r5, 0xC]
	movs r0, 0x96
	strh r0, [r5, 0x1C]
	strh r0, [r5, 0x20]
	adds r0, 0x6A
	strh r0, [r5, 0x1E]
	strh r1, [r5, 0x22]
	strh r1, [r5, 0x24]
	movs r6, 0
	ldr r4, [r5, 0x2C]
	ldrb r1, [r7]
	cmp r6, r1
	bge _082E0936
	ldrb r0, [r5, 0x8]
	cmp r6, r0
	bge _082E0956
	mov r8, r6
_082E090A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl TrackStop_rev01
	movs r0, 0xC0
	strb r0, [r4]
	mov r1, r8
	str r1, [r4, 0x20]
	lsls r1, r6, 2
	adds r0, r7, 0
	adds r0, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x40]
	adds r6, 0x1
	adds r4, 0x50
	ldrb r0, [r7]
	cmp r6, r0
	bge _082E0936
	ldrb r1, [r5, 0x8]
	cmp r6, r1
	blt _082E090A
_082E0936:
	ldrb r0, [r5, 0x8]
	cmp r6, r0
	bge _082E0956
	movs r1, 0
	mov r8, r1
_082E0940:
	adds r0, r5, 0
	adds r1, r4, 0
	bl TrackStop_rev01
	mov r0, r8
	strb r0, [r4]
	adds r6, 0x1
	adds r4, 0x50
	ldrb r1, [r5, 0x8]
	cmp r6, r1
	blt _082E0940
_082E0956:
	movs r0, 0x80
	ldrb r1, [r7, 0x3]
	ands r0, r1
	cmp r0, 0
	beq _082E0966
	ldrb r0, [r7, 0x3]
	bl SoundMode_rev01
_082E0966:
	ldr r0, _082E0974
	str r0, [r5, 0x34]
_082E096A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E0974: .4byte 0x68736d53
	thumb_func_end MPlayStart_rev01

	thumb_func_start MPlayStop_rev01
MPlayStop_rev01: @ 82E0978
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r1, [r6, 0x34]
	ldr r0, _082E09B4
	cmp r1, r0
	bne _082E09AE
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldr r0, [r6, 0x4]
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	str r0, [r6, 0x4]
	ldrb r4, [r6, 0x8]
	ldr r5, [r6, 0x2C]
	cmp r4, 0
	ble _082E09AA
_082E099A:
	adds r0, r6, 0
	adds r1, r5, 0
	bl TrackStop_rev01
	subs r4, 0x1
	adds r5, 0x50
	cmp r4, 0
	bgt _082E099A
_082E09AA:
	ldr r0, _082E09B4
	str r0, [r6, 0x34]
_082E09AE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E09B4: .4byte 0x68736d53
	thumb_func_end MPlayStop_rev01

	thumb_func_start FadeOutBody_rev01
FadeOutBody_rev01: @ 82E09B8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r1, [r6, 0x24]
	cmp r1, 0
	beq _082E0A7A
	ldrh r0, [r6, 0x26]
	subs r0, 0x1
	strh r0, [r6, 0x26]
	ldr r3, _082E09F8
	adds r2, r3, 0
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _082E0A7A
	strh r1, [r6, 0x26]
	ldrh r1, [r6, 0x28]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _082E09FC
	adds r0, r1, 0
	adds r0, 0x10
	strh r0, [r6, 0x28]
	ands r0, r2
	cmp r0, 0xFF
	bls _082E0A4E
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r6, 0x28]
	strh r3, [r6, 0x24]
	b _082E0A4E
	.align 2, 0
_082E09F8: .4byte 0x0000ffff
_082E09FC:
	adds r0, r1, 0
	subs r0, 0x10
	strh r0, [r6, 0x28]
	ands r0, r2
	lsls r0, 16
	cmp r0, 0
	bgt _082E0A4E
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	cmp r5, 0
	ble _082E0A2E
_082E0A12:
	adds r0, r6, 0
	adds r1, r4, 0
	bl TrackStop_rev01
	movs r0, 0x1
	ldrh r7, [r6, 0x28]
	ands r0, r7
	cmp r0, 0
	bne _082E0A26
	strb r0, [r4]
_082E0A26:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _082E0A12
_082E0A2E:
	movs r0, 0x1
	ldrh r1, [r6, 0x28]
	ands r0, r1
	cmp r0, 0
	beq _082E0A42
	ldr r0, [r6, 0x4]
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	b _082E0A46
_082E0A42:
	movs r0, 0x80
	lsls r0, 24
_082E0A46:
	str r0, [r6, 0x4]
	movs r0, 0
	strh r0, [r6, 0x24]
	b _082E0A7A
_082E0A4E:
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	cmp r5, 0
	ble _082E0A7A
	movs r3, 0x80
	movs r7, 0
	movs r2, 0x3
_082E0A5C:
	ldrb r1, [r4]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _082E0A72
	ldrh r7, [r6, 0x28]
	lsrs r0, r7, 2
	strb r0, [r4, 0x13]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r4]
_082E0A72:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _082E0A5C
_082E0A7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end FadeOutBody_rev01

	thumb_func_start TrkVolPitSet_rev01
TrkVolPitSet_rev01: @ 82E0A80
	push {r4,lr}
	adds r2, r1, 0
	movs r0, 0x1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, 0
	beq _082E0AE4
	ldrb r3, [r2, 0x13]
	ldrb r1, [r2, 0x12]
	adds r0, r3, 0
	muls r0, r1
	lsrs r3, r0, 5
	ldrb r4, [r2, 0x18]
	cmp r4, 0x1
	bne _082E0AA8
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	adds r0, 0x80
	muls r0, r3
	lsrs r3, r0, 7
_082E0AA8:
	movs r0, 0x14
	ldrsb r0, [r2, r0]
	lsls r0, 1
	movs r1, 0x15
	ldrsb r1, [r2, r1]
	adds r1, r0, r1
	cmp r4, 0x2
	bne _082E0ABE
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	adds r1, r0
_082E0ABE:
	movs r0, 0x80
	negs r0, r0
	cmp r1, r0
	bge _082E0ACA
	adds r1, r0, 0
	b _082E0AD0
_082E0ACA:
	cmp r1, 0x7F
	ble _082E0AD0
	movs r1, 0x7F
_082E0AD0:
	adds r0, r1, 0
	adds r0, 0x80
	muls r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x10]
	movs r0, 0x7F
	subs r0, r1
	muls r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x11]
_082E0AE4:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	adds r3, r1, 0
	cmp r0, 0
	beq _082E0B28
	movs r0, 0xE
	ldrsb r0, [r2, r0]
	ldrb r1, [r2, 0xF]
	muls r0, r1
	movs r1, 0xC
	ldrsb r1, [r2, r1]
	adds r1, r0
	lsls r1, 2
	movs r0, 0xA
	ldrsb r0, [r2, r0]
	lsls r0, 8
	adds r1, r0
	movs r0, 0xB
	ldrsb r0, [r2, r0]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0xD]
	adds r1, r0, r1
	ldrb r0, [r2, 0x18]
	cmp r0, 0
	bne _082E0B22
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	lsls r0, 4
	adds r1, r0
_082E0B22:
	asrs r0, r1, 8
	strb r0, [r2, 0x8]
	strb r1, [r2, 0x9]
_082E0B28:
	movs r0, 0xFA
	ands r0, r3
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end TrkVolPitSet_rev01

	thumb_func_start MidiKey2CgbFr
MidiKey2CgbFr: @ 82E0B34
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	cmp r0, 0x4
	bne _082E0B6C
	cmp r5, 0x14
	bhi _082E0B50
	movs r5, 0
	b _082E0B5E
_082E0B50:
	adds r0, r5, 0
	subs r0, 0x15
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3B
	bls _082E0B5E
	movs r5, 0x3B
_082E0B5E:
	ldr r0, _082E0B68
	adds r0, r5, r0
	ldrb r0, [r0]
	b _082E0BCE
	.align 2, 0
_082E0B68: .4byte 0x08675c18
_082E0B6C:
	cmp r5, 0x23
	bhi _082E0B78
	movs r0, 0
	mov r12, r0
	movs r5, 0
	b _082E0B8A
_082E0B78:
	adds r0, r5, 0
	subs r0, 0x24
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x82
	bls _082E0B8A
	movs r5, 0x82
	movs r1, 0xFF
	mov r12, r1
_082E0B8A:
	ldr r3, _082E0BD4
	adds r0, r5, r3
	ldrb r6, [r0]
	ldr r4, _082E0BD8
	movs r2, 0xF
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 1
	adds r0, r4
	movs r7, 0
	ldrsh r1, [r0, r7]
	asrs r0, r6, 4
	adds r6, r1, 0
	asrs r6, r0
	adds r0, r5, 0x1
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 1
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 4
	asrs r0, r1
	subs r0, r6
	mov r7, r12
	muls r7, r0
	adds r0, r7, 0
	asrs r0, 8
	adds r0, r6, r0
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1
_082E0BCE:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E0BD4: .4byte 0x08675b7c
_082E0BD8: .4byte 0x08675c00
	thumb_func_end MidiKey2CgbFr

	thumb_func_start CgbOscOff
CgbOscOff: @ 82E0BDC
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x2
	beq _082E0C04
	cmp r0, 0x2
	bgt _082E0BF0
	cmp r0, 0x1
	beq _082E0BF6
	b _082E0C18
_082E0BF0:
	cmp r1, 0x3
	beq _082E0C0C
	b _082E0C18
_082E0BF6:
	ldr r1, _082E0C00
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x2
	b _082E0C20
	.align 2, 0
_082E0C00: .4byte 0x04000063
_082E0C04:
	ldr r1, _082E0C08
	b _082E0C1A
	.align 2, 0
_082E0C08: .4byte 0x04000069
_082E0C0C:
	ldr r1, _082E0C14
	movs r0, 0
	b _082E0C22
	.align 2, 0
_082E0C14: .4byte 0x04000070
_082E0C18:
	ldr r1, _082E0C28
_082E0C1A:
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x4
_082E0C20:
	movs r0, 0x80
_082E0C22:
	strb r0, [r1]
	bx lr
	.align 2, 0
_082E0C28: .4byte 0x04000079
	thumb_func_end CgbOscOff

	thumb_func_start CgbModVol
CgbModVol: @ 82E0C2C
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, _082E0C5C
	ldr r1, [r0]
	movs r0, 0x1
	ldrb r1, [r1, 0x9]
	ands r0, r1
	cmp r0, 0
	bne _082E0C6C
	ldrb r0, [r2, 0x2]
	lsls r1, r0, 24
	lsrs r4, r1, 24
	ldrb r3, [r2, 0x3]
	lsls r0, r3, 24
	lsrs r3, r0, 24
	cmp r4, r3
	bcc _082E0C60
	lsrs r0, r1, 25
	cmp r0, r3
	bcc _082E0C6C
	movs r0, 0xF
	strb r0, [r2, 0x1B]
	b _082E0C7A
	.align 2, 0
_082E0C5C: .4byte 0x03007ff0
_082E0C60:
	lsrs r0, 25
	cmp r0, r4
	bcc _082E0C6C
	movs r0, 0xF0
	strb r0, [r2, 0x1B]
	b _082E0C7A
_082E0C6C:
	movs r0, 0xFF
	strb r0, [r2, 0x1B]
	ldrb r1, [r2, 0x3]
	ldrb r3, [r2, 0x2]
	adds r0, r1, r3
	lsrs r0, 4
	b _082E0C8A
_082E0C7A:
	ldrb r1, [r2, 0x3]
	ldrb r3, [r2, 0x2]
	adds r0, r1, r3
	lsrs r0, 4
	strb r0, [r2, 0xA]
	cmp r0, 0xF
	bls _082E0C8C
	movs r0, 0xF
_082E0C8A:
	strb r0, [r2, 0xA]
_082E0C8C:
	ldrb r1, [r2, 0x6]
	ldrb r3, [r2, 0xA]
	adds r0, r1, 0
	muls r0, r3
	adds r0, 0xF
	asrs r0, 4
	strb r0, [r2, 0x19]
	ldrb r0, [r2, 0x1C]
	ldrb r1, [r2, 0x1B]
	ands r0, r1
	strb r0, [r2, 0x1B]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CgbModVol

	thumb_func_start CgbSound
CgbSound: @ 82E0CA8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, _082E0CC8
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _082E0CCC
	subs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1, 0xA]
	b _082E0CD2
	.align 2, 0
_082E0CC8: .4byte 0x03007ff0
_082E0CCC:
	movs r0, 0xE
	ldr r2, [sp, 0x4]
	strb r0, [r2, 0xA]
_082E0CD2:
	movs r6, 0x1
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
_082E0CD8:
	ldrb r1, [r4]
	movs r0, 0xC7
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	bne _082E0CEE
	b _082E10D8
_082E0CEE:
	cmp r6, 0x2
	beq _082E0D20
	cmp r6, 0x2
	bgt _082E0CFC
	cmp r6, 0x1
	beq _082E0D02
	b _082E0D58
_082E0CFC:
	cmp r6, 0x3
	beq _082E0D38
	b _082E0D58
_082E0D02:
	ldr r0, _082E0D14
	str r0, [sp, 0x8]
	ldr r7, _082E0D18
	ldr r2, _082E0D1C
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _082E0D68
	.align 2, 0
_082E0D14: .4byte 0x04000060
_082E0D18: .4byte 0x04000062
_082E0D1C: .4byte 0x04000063
_082E0D20:
	ldr r0, _082E0D2C
	str r0, [sp, 0x8]
	ldr r7, _082E0D30
	ldr r2, _082E0D34
	b _082E0D60
	.align 2, 0
_082E0D2C: .4byte 0x04000061
_082E0D30: .4byte 0x04000068
_082E0D34: .4byte 0x04000069
_082E0D38:
	ldr r0, _082E0D4C
	str r0, [sp, 0x8]
	ldr r7, _082E0D50
	ldr r2, _082E0D54
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _082E0D68
	.align 2, 0
_082E0D4C: .4byte 0x04000070
_082E0D50: .4byte 0x04000072
_082E0D54: .4byte 0x04000073
_082E0D58:
	ldr r0, _082E0DB8
	str r0, [sp, 0x8]
	ldr r7, _082E0DBC
	ldr r2, _082E0DC0
_082E0D60:
	str r2, [sp, 0xC]
	adds r0, 0xB
	str r0, [sp, 0x10]
	adds r2, 0x4
_082E0D68:
	str r2, [sp, 0x14]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	str r0, [sp]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, 0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _082E0E5E
	movs r3, 0x40
	adds r0, r3, 0
	ands r0, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	mov r10, r0
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r5, 0
	bne _082E0E82
	movs r0, 0x3
	strb r0, [r4]
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	str r3, [sp, 0x18]
	bl CgbModVol
	ldr r3, [sp, 0x18]
	cmp r6, 0x2
	beq _082E0DD0
	cmp r6, 0x2
	bgt _082E0DC4
	cmp r6, 0x1
	beq _082E0DCA
	b _082E0E24
	.align 2, 0
_082E0DB8: .4byte 0x04000071
_082E0DBC: .4byte 0x04000078
_082E0DC0: .4byte 0x04000079
_082E0DC4:
	cmp r6, 0x3
	beq _082E0DDC
	b _082E0E24
_082E0DCA:
	ldrb r0, [r4, 0x1F]
	ldr r2, [sp, 0x8]
	strb r0, [r2]
_082E0DD0:
	ldr r0, [r4, 0x24]
	lsls r0, 6
	ldrb r1, [r4, 0x1E]
	adds r0, r1, r0
	strb r0, [r7]
	b _082E0E30
_082E0DDC:
	ldr r1, [r4, 0x24]
	ldr r0, [r4, 0x28]
	cmp r1, r0
	beq _082E0E04
	ldr r2, [sp, 0x8]
	strb r3, [r2]
	ldr r1, _082E0E18
	ldr r2, [r4, 0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x8]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	str r2, [r4, 0x28]
_082E0E04:
	ldr r0, [sp, 0x8]
	strb r5, [r0]
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _082E0E1C
	movs r0, 0xC0
	b _082E0E3E
	.align 2, 0
_082E0E18: .4byte 0x04000090
_082E0E1C:
	movs r1, 0x80
	negs r1, r1
	strb r1, [r4, 0x1A]
	b _082E0E40
_082E0E24:
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldr r0, [r4, 0x24]
	lsls r0, 3
	ldr r2, [sp, 0x10]
	strb r0, [r2]
_082E0E30:
	ldrb r0, [r4, 0x4]
	adds r0, 0x8
	mov r8, r0
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _082E0E3E
	movs r0, 0x40
_082E0E3E:
	strb r0, [r4, 0x1A]
_082E0E40:
	ldrb r1, [r4, 0x4]
	movs r2, 0
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	adds r1, r6, 0x1
	mov r10, r1
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r0, 0
	bne _082E0E5A
	b _082E0F96
_082E0E5A:
	strb r2, [r4, 0x9]
	b _082E0FC4
_082E0E5E:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _082E0E90
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	movs r2, 0xFF
	ands r0, r2
	lsls r0, 24
	adds r1, r6, 0x1
	mov r10, r1
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	ble _082E0E82
	b _082E0FD6
_082E0E82:
	lsls r0, r6, 24
	lsrs r0, 24
	bl CgbOscOff
	movs r0, 0
	strb r0, [r4]
	b _082E10D4
_082E0E90:
	movs r0, 0x40
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	beq _082E0ED0
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _082E0ED0
	movs r0, 0xFC
	ands r0, r1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x7]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _082E0F02
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _082E0FC4
	ldrb r2, [r4, 0x7]
	mov r8, r2
	b _082E0FC4
_082E0ED0:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _082E0FC4
	cmp r6, 0x3
	bne _082E0EE2
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
_082E0EE2:
	adds r0, r4, 0
	bl CgbModVol
	movs r0, 0x3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, 0
	bne _082E0F36
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	cmp r0, 0
	bgt _082E0F32
_082E0F02:
	ldrb r2, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	muls r0, r1
	adds r0, 0xFF
	asrs r0, 8
	movs r1, 0
	strb r0, [r4, 0x9]
	lsls r0, 24
	cmp r0, 0
	beq _082E0E82
	movs r0, 0x4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _082E0FD6
	movs r2, 0x8
	mov r8, r2
	b _082E0FD6
_082E0F32:
	ldrb r0, [r4, 0x7]
	b _082E0FC2
_082E0F36:
	cmp r0, 0x1
	bne _082E0F42
_082E0F3A:
	ldrb r0, [r4, 0x19]
	strb r0, [r4, 0x9]
	movs r0, 0x7
	b _082E0FC2
_082E0F42:
	cmp r0, 0x2
	bne _082E0F86
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	ldrb r2, [r4, 0x19]
	lsls r1, r2, 24
	cmp r0, r1
	bgt _082E0F82
_082E0F5A:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _082E0F6A
	movs r0, 0xFC
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b _082E0F02
_082E0F6A:
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	orrs r0, r2
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _082E0F3A
	movs r0, 0x8
	mov r8, r0
	b _082E0F3A
_082E0F82:
	ldrb r0, [r4, 0x5]
	b _082E0FC2
_082E0F86:
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	ldrb r2, [r4, 0xA]
	cmp r0, r2
	bcc _082E0FC0
_082E0F96:
	ldrb r0, [r4]
	subs r0, 0x1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x5]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _082E0F5A
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	cmp r6, 0x3
	beq _082E0FC4
	ldrb r2, [r4, 0x5]
	mov r8, r2
	b _082E0FC4
_082E0FC0:
	ldrb r0, [r4, 0x4]
_082E0FC2:
	strb r0, [r4, 0xB]
_082E0FC4:
	ldrb r0, [r4, 0xB]
	subs r0, 0x1
	strb r0, [r4, 0xB]
	ldr r0, [sp]
	cmp r0, 0
	bne _082E0FD6
	subs r0, 0x1
	str r0, [sp]
	b _082E0ED0
_082E0FD6:
	movs r0, 0x2
	ldrb r1, [r4, 0x1D]
	ands r0, r1
	cmp r0, 0
	beq _082E104E
	cmp r6, 0x3
	bgt _082E1016
	movs r0, 0x8
	ldrb r2, [r4, 0x1]
	ands r0, r2
	cmp r0, 0
	beq _082E1016
	ldr r0, _082E1000
	ldrb r0, [r0]
	cmp r0, 0x3F
	bgt _082E1008
	ldr r0, [r4, 0x20]
	adds r0, 0x2
	ldr r1, _082E1004
	b _082E1012
	.align 2, 0
_082E1000: .4byte 0x04000089
_082E1004: .4byte 0x000007fc
_082E1008:
	cmp r0, 0x7F
	bgt _082E1016
	ldr r0, [r4, 0x20]
	adds r0, 0x1
	ldr r1, _082E1024
_082E1012:
	ands r0, r1
	str r0, [r4, 0x20]
_082E1016:
	cmp r6, 0x4
	beq _082E1028
	ldr r0, [r4, 0x20]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	b _082E1036
	.align 2, 0
_082E1024: .4byte 0x000007fe
_082E1028:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2]
	movs r1, 0x8
	ands r1, r0
	ldr r0, [r4, 0x20]
	orrs r0, r1
	strb r0, [r2]
_082E1036:
	movs r0, 0xC0
	ldrb r1, [r4, 0x1A]
	ands r0, r1
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, 0x1A]
	movs r2, 0xFF
	ands r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_082E104E:
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	ands r0, r2
	cmp r0, 0
	beq _082E10D4
	ldr r1, _082E1098
	ldrb r0, [r1]
	ldrb r2, [r4, 0x1C]
	bics r0, r2
	ldrb r2, [r4, 0x1B]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, 0x3
	bne _082E10A0
	ldr r0, _082E109C
	ldrb r1, [r4, 0x9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, 0xC]
	strb r0, [r2]
	movs r1, 0x80
	adds r0, r1, 0
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	cmp r0, 0
	beq _082E10D4
	ldr r0, [sp, 0x8]
	strb r1, [r0]
	ldrb r0, [r4, 0x1A]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	movs r0, 0x7F
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	strb r0, [r4, 0x1A]
	b _082E10D4
	.align 2, 0
_082E1098: .4byte 0x04000081
_082E109C: .4byte 0x08675c54
_082E10A0:
	movs r0, 0xF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, 0x9]
	lsls r0, r2, 4
	add r0, r8
	ldr r1, [sp, 0xC]
	strb r0, [r1]
	movs r2, 0x80
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	cmp r6, 0x1
	bne _082E10D4
	ldr r0, [sp, 0x8]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _082E10D4
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_082E10D4:
	movs r0, 0
	strb r0, [r4, 0x1D]
_082E10D8:
	mov r6, r10
	mov r4, r9
	cmp r6, 0x4
	bgt _082E10E2
	b _082E0CD8
_082E10E2:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CgbSound

	thumb_func_start MPlayTempoControl
MPlayTempoControl: @ 82E10F4
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _082E1118
	cmp r3, r0
	bne _082E1110
	strh r1, [r2, 0x1E]
	ldrh r4, [r2, 0x1C]
	adds r0, r1, 0
	muls r0, r4
	asrs r0, 8
	strh r0, [r2, 0x20]
_082E1110:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E1118: .4byte 0x68736d53
	thumb_func_end MPlayTempoControl

	thumb_func_start MPlayVolumeControl
MPlayVolumeControl: @ 82E111C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r6, r2, 16
	ldr r3, [r4, 0x34]
	ldr r0, _082E1180
	cmp r3, r0
	bne _082E1174
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r1, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _082E1170
	movs r0, 0x80
	mov r8, r0
	lsrs r6, 18
	movs r0, 0x3
	mov r12, r0
_082E114C:
	adds r0, r7, 0
	ands r0, r5
	cmp r0, 0
	beq _082E1166
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, 0
	beq _082E1166
	strb r6, [r1, 0x13]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1]
_082E1166:
	subs r2, 0x1
	adds r1, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _082E114C
_082E1170:
	ldr r0, _082E1180
	str r0, [r4, 0x34]
_082E1174:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E1180: .4byte 0x68736d53
	thumb_func_end MPlayVolumeControl

	thumb_func_start MPlayPitchControl
MPlayPitchControl: @ 82E1184
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r6, r2, 16
	ldr r3, [r4, 0x34]
	ldr r0, _082E11F4
	cmp r3, r0
	bne _082E11E6
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r3, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _082E11E2
	movs r0, 0x80
	mov r9, r0
	lsls r0, r6, 16
	asrs r7, r0, 24
	movs r0, 0xC
	mov r8, r0
_082E11BC:
	mov r0, r12
	ands r0, r5
	cmp r0, 0
	beq _082E11D8
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _082E11D8
	strb r7, [r3, 0xB]
	strb r6, [r3, 0xD]
	mov r0, r8
	orrs r0, r1
	strb r0, [r3]
_082E11D8:
	subs r2, 0x1
	adds r3, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _082E11BC
_082E11E2:
	ldr r0, _082E11F4
	str r0, [r4, 0x34]
_082E11E6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E11F4: .4byte 0x68736d53
	thumb_func_end MPlayPitchControl

	thumb_func_start MPlayPanpotControl
MPlayPanpotControl: @ 82E11F8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r3, [r4, 0x34]
	ldr r0, _082E125C
	cmp r3, r0
	bne _082E1250
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r1, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _082E124C
	movs r0, 0x80
	mov r8, r0
	movs r0, 0x3
	mov r12, r0
_082E1228:
	adds r0, r7, 0
	ands r0, r5
	cmp r0, 0
	beq _082E1242
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, 0
	beq _082E1242
	strb r6, [r1, 0x15]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1]
_082E1242:
	subs r2, 0x1
	adds r1, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _082E1228
_082E124C:
	ldr r0, _082E125C
	str r0, [r4, 0x34]
_082E1250:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E125C: .4byte 0x68736d53
	thumb_func_end MPlayPanpotControl

	thumb_func_start MP_clear_modM
MP_clear_modM: @ 82E1260
	adds r1, r0, 0
	movs r2, 0
	movs r0, 0
	strb r0, [r1, 0x1A]
	strb r0, [r1, 0x16]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	bne _082E1274
	movs r0, 0xC
	b _082E1276
_082E1274:
	movs r0, 0x3
_082E1276:
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	thumb_func_end MP_clear_modM

	thumb_func_start MPlayModDepthSet
MPlayModDepthSet: @ 82E1280
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r1, [r6, 0x34]
	ldr r0, _082E12F0
	cmp r1, r0
	bne _082E12E0
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	movs r7, 0x1
	cmp r5, 0
	ble _082E12DC
	mov r9, r8
_082E12B0:
	mov r0, r10
	ands r0, r7
	cmp r0, 0
	beq _082E12D2
	movs r0, 0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, 0
	beq _082E12D2
	mov r0, r8
	strb r0, [r4, 0x17]
	mov r1, r9
	cmp r1, 0
	bne _082E12D2
	adds r0, r4, 0
	bl MP_clear_modM
_082E12D2:
	subs r5, 0x1
	adds r4, 0x50
	lsls r7, 1
	cmp r5, 0
	bgt _082E12B0
_082E12DC:
	ldr r0, _082E12F0
	str r0, [r6, 0x34]
_082E12E0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E12F0: .4byte 0x68736d53
	thumb_func_end MPlayModDepthSet

	thumb_func_start MPlayLFOSpeedSet
MPlayLFOSpeedSet: @ 82E12F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r1, [r6, 0x34]
	ldr r0, _082E1364
	cmp r1, r0
	bne _082E1354
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	movs r7, 0x1
	cmp r5, 0
	ble _082E1350
	mov r9, r8
_082E1324:
	mov r0, r10
	ands r0, r7
	cmp r0, 0
	beq _082E1346
	movs r0, 0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, 0
	beq _082E1346
	mov r0, r8
	strb r0, [r4, 0x19]
	mov r1, r9
	cmp r1, 0
	bne _082E1346
	adds r0, r4, 0
	bl MP_clear_modM
_082E1346:
	subs r5, 0x1
	adds r4, 0x50
	lsls r7, 1
	cmp r5, 0
	bgt _082E1324
_082E1350:
	ldr r0, _082E1364
	str r0, [r6, 0x34]
_082E1354:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E1364: .4byte 0x68736d53
	thumb_func_end MPlayLFOSpeedSet

	thumb_func_start ply_memacc
ply_memacc: @ 82E1368
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r1, [r6, 0x40]
	ldrb r5, [r1]
	adds r2, r1, 0x1
	str r2, [r6, 0x40]
	ldr r0, [r4, 0x18]
	ldrb r1, [r1, 0x1]
	adds r3, r1, r0
	adds r0, r2, 0x1
	str r0, [r6, 0x40]
	ldrb r2, [r2, 0x1]
	adds r0, 0x1
	str r0, [r6, 0x40]
	cmp r5, 0x11
	bls _082E138C
	b _082E14BA
_082E138C:
	lsls r0, r5, 2
	ldr r1, _082E1398
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082E1398: .4byte _082E139C
	.align 2, 0
_082E139C:
	.4byte _082E13E4
	.4byte _082E13E8
	.4byte _082E13F0
	.4byte _082E13F8
	.4byte _082E1402
	.4byte _082E1410
	.4byte _082E141E
	.4byte _082E1426
	.4byte _082E142E
	.4byte _082E1436
	.4byte _082E143E
	.4byte _082E1446
	.4byte _082E144E
	.4byte _082E145C
	.4byte _082E146A
	.4byte _082E1478
	.4byte _082E1486
	.4byte _082E1494
_082E13E4:
	strb r2, [r3]
	b _082E14BA
_082E13E8:
	ldrb r1, [r3]
	adds r0, r1, r2
	strb r0, [r3]
	b _082E14BA
_082E13F0:
	ldrb r1, [r3]
	subs r0, r1, r2
	strb r0, [r3]
	b _082E14BA
_082E13F8:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	b _082E14BA
_082E1402:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	adds r0, r1, r0
	strb r0, [r3]
	b _082E14BA
_082E1410:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	subs r0, r1, r0
	strb r0, [r3]
	b _082E14BA
_082E141E:
	ldrb r3, [r3]
	cmp r3, r2
	beq _082E14A0
	b _082E14B4
_082E1426:
	ldrb r3, [r3]
	cmp r3, r2
	bne _082E14A0
	b _082E14B4
_082E142E:
	ldrb r3, [r3]
	cmp r3, r2
	bhi _082E14A0
	b _082E14B4
_082E1436:
	ldrb r3, [r3]
	cmp r3, r2
	bcs _082E14A0
	b _082E14B4
_082E143E:
	ldrb r3, [r3]
	cmp r3, r2
	bls _082E14A0
	b _082E14B4
_082E1446:
	ldrb r3, [r3]
	cmp r3, r2
	bcc _082E14A0
	b _082E14B4
_082E144E:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	beq _082E14A0
	b _082E14B4
_082E145C:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bne _082E14A0
	b _082E14B4
_082E146A:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bhi _082E14A0
	b _082E14B4
_082E1478:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bcs _082E14A0
	b _082E14B4
_082E1486:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bls _082E14A0
	b _082E14B4
_082E1494:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bcs _082E14B4
_082E14A0:
	ldr r0, _082E14B0
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl _call_via_r2
	b _082E14BA
	.align 2, 0
_082E14B0: .4byte 0x03007464
_082E14B4:
	ldr r0, [r6, 0x40]
	adds r0, 0x4
	str r0, [r6, 0x40]
_082E14BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ply_memacc

	thumb_func_start ply_xcmd
ply_xcmd: @ 82E14C0
	push {lr}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r1, 0x40]
	ldr r2, _082E14DC
	lsls r3, 2
	adds r3, r2
	ldr r2, [r3]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_082E14DC: .4byte 0x08675ccc
	thumb_func_end ply_xcmd

	thumb_func_start ply_xxx
ply_xxx: @ 82E14E0
	push {lr}
	ldr r2, _082E14F0
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_082E14F0: .4byte 0x03007460
	thumb_func_end ply_xxx

	thumb_func_start ply_xwave
ply_xwave: @ 82E14F4
	push {r4,lr}
	ldr r2, [r1, 0x40]
	ldr r0, _082E152C
	ands r4, r0
	ldrb r0, [r2]
	orrs r4, r0
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 8
	ldr r0, _082E1530
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x2]
	lsls r3, r0, 16
	ldr r0, _082E1534
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x3]
	lsls r3, r0, 24
	ldr r0, _082E1538
	ands r4, r0
	orrs r4, r3
	str r4, [r1, 0x28]
	adds r2, 0x4
	str r2, [r1, 0x40]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E152C: .4byte 0xffffff00
_082E1530: .4byte 0xffff00ff
_082E1534: .4byte 0xff00ffff
_082E1538: .4byte 0x00ffffff
	thumb_func_end ply_xwave

	thumb_func_start ply_xtype
ply_xtype: @ 82E153C
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	strb r2, [r0]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xtype

	thumb_func_start ply_xatta
ply_xatta: @ 82E1550
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	adds r0, r1, 0
	adds r0, 0x2C
	strb r2, [r0]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xatta

	thumb_func_start ply_xdeca
ply_xdeca: @ 82E1564
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2D
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xdeca

	thumb_func_start ply_xsust
ply_xsust: @ 82E1578
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2E
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xsust

	thumb_func_start ply_xrele
ply_xrele: @ 82E158C
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2F
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xrele

	thumb_func_start ply_xiecv
ply_xiecv: @ 82E15A0
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	strb r2, [r1, 0x1E]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xiecv

	thumb_func_start ply_xiecl
ply_xiecl: @ 82E15AC
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	strb r2, [r1, 0x1F]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xiecl

	thumb_func_start ply_xleng
ply_xleng: @ 82E15B8
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x26
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xleng

	thumb_func_start ply_xswee
ply_xswee: @ 82E15CC
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x27
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xswee

	thumb_func_start ply_xcmd0C
ply_xcmd0C: @ 82E15E0
	push {r4,lr}
	adds r3, r1, 0
	ldr r4, [r3, 0x40]
	ldr r0, _082E1610
	ands r2, r0
	ldrb r0, [r4]
	orrs r2, r0
	ldrb r0, [r4, 0x1]
	lsls r1, r0, 8
	ldr r0, _082E1614
	ands r2, r0
	orrs r2, r1
	ldrh r1, [r3, 0x3A]
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r1, r0
	bcs _082E1618
	adds r0, r1, 0x1
	strh r0, [r3, 0x3A]
	subs r0, r4, 0x2
	str r0, [r3, 0x40]
	movs r0, 0x1
	strb r0, [r3, 0x1]
	b _082E1620
	.align 2, 0
_082E1610: .4byte 0xffffff00
_082E1614: .4byte 0xffff00ff
_082E1618:
	movs r0, 0
	strh r0, [r3, 0x3A]
	adds r0, r4, 0x2
	str r0, [r3, 0x40]
_082E1620:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ply_xcmd0C

	thumb_func_start ply_xcmd0D
ply_xcmd0D: @ 82E1628
	push {r4,lr}
	ldr r2, [r1, 0x40]
	ldr r0, _082E1660
	ands r4, r0
	ldrb r0, [r2]
	orrs r4, r0
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 8
	ldr r0, _082E1664
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x2]
	lsls r3, r0, 16
	ldr r0, _082E1668
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x3]
	lsls r3, r0, 24
	ldr r0, _082E166C
	ands r4, r0
	orrs r4, r3
	str r4, [r1, 0x3C]
	adds r2, 0x4
	str r2, [r1, 0x40]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E1660: .4byte 0xffffff00
_082E1664: .4byte 0xffff00ff
_082E1668: .4byte 0xff00ffff
_082E166C: .4byte 0x00ffffff
	thumb_func_end ply_xcmd0D

	thumb_func_start DummyFunc_rev
DummyFunc_rev: @ 82E1670
	bx lr
	thumb_func_end DummyFunc_rev

	thumb_func_start sub_82E1674
sub_82E1674: @ 82E1674
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	movs r6, 0
	movs r1, 0
	movs r4, 0
	ldr r0, _082E1730
	mov r8, r0
	ldr r7, _082E1734
	ldr r0, _082E1738
	mov r10, r0
	mov r5, r8
	adds r5, 0xC
	movs r3, 0
	ldr r0, _082E173C
	mov r12, r0
_082E169A:
	mov r0, r12
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, 0
	bne _082E16B0
	ldr r0, [r2, 0x20]
	cmp r0, 0
	beq _082E16C6
	ldr r0, [r0, 0x2C]
	cmp r0, r2
	bne _082E16C6
_082E16B0:
	ldr r0, [r5]
	cmp r6, r0
	bcs _082E16BA
	adds r6, r0, 0
	adds r1, r4, 0
_082E16BA:
	adds r5, 0x40
	adds r3, 0xA0
	adds r4, 0x1
	cmp r4, 0x1
	ble _082E169A
	adds r4, r1, 0
_082E16C6:
	lsls r5, r4, 6
	add r5, r8
	ldr r0, [r5, 0x34]
	adds r0, 0x1
	str r0, [r5, 0x34]
	movs r0, 0x34
	muls r4, r0
	adds r6, r4, r7
	adds r0, r6, 0
	mov r1, r10
	movs r2, 0x34
	bl memcpy
	adds r0, r7, 0x4
	adds r0, r4, r0
	mov r1, r9
	str r1, [r0]
	adds r1, r7, 0
	adds r1, 0x8
	adds r1, r4, r1
	adds r0, r7, 0
	adds r0, 0x11
	adds r0, r4, r0
	str r0, [r1]
	adds r1, r7, 0
	adds r1, 0xC
	adds r1, r4, r1
	adds r0, r7, 0
	adds r0, 0x18
	adds r0, r4, r0
	str r0, [r1]
	adds r0, r7, 0
	adds r0, 0x14
	adds r0, r4, r0
	adds r1, r7, 0
	adds r1, 0x1A
	adds r4, r1
	str r4, [r0]
	ldr r0, _082E1740
	str r0, [r5, 0x34]
	adds r0, r5, 0
	adds r1, r6, 0
	bl MPlayStart_rev01
	adds r0, r5, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E1730: .4byte 0x030073a0
_082E1734: .4byte 0x03007330
_082E1738: .4byte 0x030077b0
_082E173C: .4byte 0x03007670
_082E1740: .4byte 0x68736d53
	thumb_func_end sub_82E1674

	thumb_func_start sub_82E1744
sub_82E1744: @ 82E1744
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _082E1754
	movs r1, 0x7F
	ands r0, r1
	strb r0, [r2, 0x1D]
	bx lr
	.align 2, 0
_082E1754: .4byte 0x030077b0
	thumb_func_end sub_82E1744

	thumb_func_start sub_82E1758
sub_82E1758: @ 82E1758
	ldr r2, _082E176C
	lsls r0, 24
	asrs r0, 24
	adds r0, 0x40
	movs r1, 0x7F
	ands r0, r1
	adds r2, 0x28
	strb r0, [r2]
	bx lr
	.align 2, 0
_082E176C: .4byte 0x030077b0
	thumb_func_end sub_82E1758

	thumb_func_start sub_82E1770
sub_82E1770: @ 82E1770
	push {r4-r6,lr}
	lsls r0, 16
	ldr r3, _082E17A4
	ldrb r2, [r3, 0x19]
	ldrb r4, [r3, 0x12]
	subs r1, r2, r4
	lsls r1, 24
	lsrs r1, 24
	movs r6, 0x80
	lsls r6, 16
	adds r0, r6
	asrs r2, r0, 24
	movs r5, 0x7F
	movs r4, 0x7F
	ands r2, r4
	movs r6, 0x2A
	strb r2, [r6, r3]
	asrs r0, 17
	ands r0, r4
	strb r0, [r3, 0x12]
	adds r1, r0
	ands r1, r5
	strb r1, [r3, 0x19]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E17A4: .4byte 0x030077b0
	thumb_func_end sub_82E1770

	thumb_func_start sub_82E17A8
sub_82E17A8: @ 82E17A8
	ldr r1, _082E17B0
	strh r0, [r1, 0x2E]
	bx lr
	.align 2, 0
_082E17B0: .4byte 0x030077b0
	thumb_func_end sub_82E17A8

	thumb_func_start sub_82E17B4
sub_82E17B4: @ 82E17B4
	ldr r1, _082E17BC
	adds r1, 0x26
	strb r0, [r1]
	bx lr
	.align 2, 0
_082E17BC: .4byte 0x030077b0
	thumb_func_end sub_82E17B4

	thumb_func_start sub_82E17C0
sub_82E17C0: @ 82E17C0
	ldr r1, _082E17C8
	str r0, [r1, 0x20]
	bx lr
	.align 2, 0
_082E17C8: .4byte 0x030077b0
	thumb_func_end sub_82E17C0

	thumb_func_start sub_82E17CC
sub_82E17CC: @ 82E17CC
	ldr r1, [r0, 0x2C]
	ldr r0, [r1, 0x20]
	cmp r0, 0
	beq _082E17DE
	ldr r0, [r0, 0x2C]
	cmp r0, r1
	bne _082E17DE
	movs r0, 0x1
	b _082E17E0
_082E17DE:
	movs r0, 0
_082E17E0:
	bx lr
	thumb_func_end sub_82E17CC

	thumb_func_start sub_82E17E4
sub_82E17E4: @ 82E17E4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r0, 0
	beq _082E1804
	ldr r2, _082E1800
	movs r0, 0x2
	strb r0, [r2]
	ldrb r3, [r2, 0x12]
	adds r0, r3, r1
	movs r1, 0x7F
	ands r0, r1
	strb r0, [r2, 0x19]
	b _082E180A
	.align 2, 0
_082E1800: .4byte 0x030077b0
_082E1804:
	ldr r1, _082E180C
	movs r0, 0x1
	strb r0, [r1]
_082E180A:
	bx lr
	.align 2, 0
_082E180C: .4byte 0x030077b0
	thumb_func_end sub_82E17E4

	thumb_func_start sub_82E1810
sub_82E1810: @ 82E1810
	ldr r1, _082E1828
	ldr r2, [r1]
	cmp r0, 0
	beq _082E1834
	ldr r1, _082E182C
	ldr r3, _082E1830
	adds r0, r3, 0
	strh r0, [r1]
	movs r0, 0xFE
	ldrb r1, [r2, 0x9]
	ands r0, r1
	b _082E1842
	.align 2, 0
_082E1828: .4byte 0x03007ff0
_082E182C: .4byte 0x04000082
_082E1830: .4byte 0x0000210e
_082E1834:
	ldr r1, _082E1848
	ldr r3, _082E184C
	adds r0, r3, 0
	strh r0, [r1]
	movs r0, 0x1
	ldrb r1, [r2, 0x9]
	orrs r0, r1
_082E1842:
	strb r0, [r2, 0x9]
	bx lr
	.align 2, 0
_082E1848: .4byte 0x04000082
_082E184C: .4byte 0x00003302
	thumb_func_end sub_82E1810

	thumb_func_start sub_82E1850
sub_82E1850: @ 82E1850
	ldr r1, _082E1858
	strb r0, [r1, 0x2]
	bx lr
	.align 2, 0
_082E1858: .4byte 0x030077b0
	thumb_func_end sub_82E1850
