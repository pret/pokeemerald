	thumb_func_start sub_82E2150
sub_82E2150: ; 82E2150
	push {r7,lr}
	mov r7, sp
	bl sub_82E29F0
	ldr r0, _082E2164
	movs r1, 0
	strb r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E2164: .4byte 0x03001a7e
	thumb_func_end sub_82E2150

	thumb_func_start sub_82E2168
sub_82E2168: ; 82E2168
	push {r7,lr}
	mov r7, sp
	bl sub_82E2A04
	ldr r0, _082E217C
	movs r1, 0x1
	strb r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E217C: .4byte 0x03001a7e
	thumb_func_end sub_82E2168

	thumb_func_start sub_82E2180
sub_82E2180: ; 82E2180
	push {r7,lr}
	sub sp, 0x10
	mov r7, sp
	adds r1, r7, 0x4
	adds r0, r1, 0
	bl sub_82E22DC
	lsls r1, r0, 24
	lsrs r0, r1, 24
	cmp r0, 0
	bne _082E219A
	movs r0, 0
	b _082E224E
_082E219A:
	adds r0, r7, 0
	movs r1, 0
	strb r1, [r0]
	adds r0, r7, 0x4
	ldrb r1, [r0, 0x7]
	movs r2, 0xC0
	adds r0, r1, 0
	ands r0, r2
	adds r2, r0, 0
	lsls r1, r2, 24
	lsrs r0, r1, 24
	cmp r0, 0x80
	beq _082E21CA
	adds r0, r7, 0x4
	ldrb r1, [r0, 0x7]
	movs r2, 0xC0
	adds r0, r1, 0
	ands r0, r2
	adds r2, r0, 0
	lsls r1, r2, 24
	lsrs r0, r1, 24
	cmp r0, 0
	bne _082E21E8
	b _082E21CA
_082E21CA:
	bl sub_82E2258
	lsls r1, r0, 24
	lsrs r0, r1, 24
	cmp r0, 0
	bne _082E21DA
	movs r0, 0
	b _082E224E
_082E21DA:
	adds r1, r7, 0
	adds r0, r7, 0
	adds r1, r7, 0
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
_082E21E8:
	adds r1, r7, 0x4
	adds r0, r1, 0
	bl sub_82E259C
	adds r0, r7, 0x4
	ldrb r1, [r0, 0x6]
	movs r2, 0x80
	adds r0, r1, 0
	ands r0, r2
	adds r2, r0, 0
	lsls r1, r2, 24
	lsrs r0, r1, 24
	cmp r0, 0
	beq _082E2236
	bl sub_82E2258
	lsls r1, r0, 24
	lsrs r0, r1, 24
	cmp r0, 0
	bne _082E2228
	adds r0, r7, 0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r1, r0, 0
	movs r2, 0xF
	adds r0, r1, 0
	bics r0, r2
	adds r1, r0, 0
	lsls r0, r1, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	b _082E224E
_082E2228:
	adds r1, r7, 0
	adds r0, r7, 0
	adds r1, r7, 0
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
_082E2236:
	adds r0, r7, 0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r1, r0, 0
	movs r2, 0x1
	adds r0, r1, 0
	orrs r0, r2
	adds r1, r0, 0
	lsls r0, r1, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	b _082E224E
_082E224E:
	add sp, 0x10
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2180

	thumb_func_start sub_82E2258
sub_82E2258: ; 82E2258
	push {r7,lr}
	sub sp, 0x10
	mov r7, sp
	ldr r0, _082E226C
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E2270
	movs r0, 0
	b _082E22D4
	.align 2, 0
_082E226C: .4byte 0x03001a7e
_082E2270:
	ldr r0, _082E22C8
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E22CC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E22CC
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E22D0
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x60
	bl sub_82E2820
	ldr r0, _082E22CC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E22CC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E22C8
	movs r1, 0
	strb r1, [r0]
	adds r0, r7, 0x4
	ldrb r1, [r0, 0x7]
	movs r2, 0
	ands r1, r2
	adds r2, r1, 0
	movs r3, 0x40
	adds r1, r2, 0
	orrs r1, r3
	adds r2, r1, 0
	strb r2, [r0, 0x7]
	adds r1, r7, 0x4
	adds r0, r1, 0
	bl sub_82E23A8
	adds r1, r7, 0
	strb r0, [r1]
	adds r0, r7, 0
	ldrb r1, [r0]
	adds r0, r1, 0
	b _082E22D4
	.align 2, 0
_082E22C8: .4byte 0x03001a7e
_082E22CC: .4byte _080000C4
_082E22D0: .4byte _080000C6
_082E22D4:
	add sp, 0x10
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2258

	thumb_func_start sub_82E22DC
sub_82E22DC: ; 82E22DC
	push {r4,r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E22F0
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E22F4
	movs r0, 0
	b _082E23A0
	.align 2, 0
_082E22F0: .4byte 0x03001a7e
_082E22F4:
	ldr r0, _082E2394
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E2398
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2398
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E239C
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x63
	bl sub_82E2820
	ldr r0, _082E239C
	movs r1, 0x5
	strh r1, [r0]
	bl sub_82E2964
	adds r1, r7, 0x4
	strb r0, [r1]
	ldr r0, [r7]
	adds r1, r7, 0x4
	ldrb r2, [r1]
	movs r3, 0xC0
	adds r1, r2, 0
	ands r1, r3
	adds r2, r7, 0x4
	ldrb r3, [r2]
	movs r4, 0x20
	adds r2, r3, 0
	ands r2, r4
	adds r4, r2, 0
	lsls r3, r4, 24
	lsrs r2, r3, 24
	lsrs r3, r2, 3
	adds r2, r3, 0
	orrs r1, r2
	adds r2, r7, 0x4
	ldrb r3, [r2]
	movs r4, 0x8
	adds r2, r3, 0
	ands r2, r4
	adds r4, r2, 0
	lsls r3, r4, 24
	lsrs r2, r3, 24
	lsrs r3, r2, 2
	adds r2, r3, 0
	orrs r1, r2
	adds r2, r7, 0x4
	ldrb r3, [r2]
	movs r4, 0x2
	adds r2, r3, 0
	ands r2, r4
	adds r4, r2, 0
	lsls r3, r4, 24
	lsrs r2, r3, 24
	lsrs r3, r2, 1
	adds r2, r3, 0
	orrs r1, r2
	ldrb r2, [r0, 0x7]
	movs r3, 0
	ands r2, r3
	adds r3, r2, 0
	adds r2, r3, 0
	orrs r2, r1
	adds r1, r2, 0
	strb r1, [r0, 0x7]
	ldr r0, _082E2398
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2398
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2394
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E23A0
	.align 2, 0
_082E2394: .4byte 0x03001a7e
_082E2398: .4byte _080000C4
_082E239C: .4byte _080000C6
_082E23A0:
	add sp, 0x8
	pop {r4,r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E22DC

	thumb_func_start sub_82E23A8
sub_82E23A8: ; 82E23A8
	push {r4,r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E23BC
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E23C0
	movs r0, 0
	b _082E2448
	.align 2, 0
_082E23BC: .4byte 0x03001a7e
_082E23C0:
	ldr r0, _082E243C
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E2440
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2440
	movs r1, 0x5
	strh r1, [r0]
	adds r0, r7, 0x4
	ldr r1, [r7]
	ldrb r2, [r1, 0x7]
	movs r3, 0x4
	adds r1, r2, 0
	ands r1, r3
	adds r2, r1, 0
	lsls r1, r2, 3
	ldr r2, [r7]
	ldrb r3, [r2, 0x7]
	movs r4, 0x2
	adds r2, r3, 0
	ands r2, r4
	adds r3, r2, 0
	lsls r2, r3, 2
	adds r3, r2, 0
	movs r4, 0x40
	adds r2, r3, 0
	orrs r2, r4
	orrs r1, r2
	ldr r2, [r7]
	ldrb r3, [r2, 0x7]
	movs r4, 0x1
	adds r2, r3, 0
	ands r2, r4
	adds r3, r2, 0
	lsls r2, r3, 1
	orrs r1, r2
	adds r2, r1, 0
	strb r2, [r0]
	ldr r0, _082E2444
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x62
	bl sub_82E2820
	adds r0, r7, 0x4
	ldrb r1, [r0]
	adds r0, r1, 0
	bl sub_82E28C4
	ldr r0, _082E2440
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2440
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E243C
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E2448
	.align 2, 0
_082E243C: .4byte 0x03001a7e
_082E2440: .4byte _080000C4
_082E2444: .4byte _080000C6
_082E2448:
	add sp, 0x8
	pop {r4,r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E23A8

	thumb_func_start sub_82E2450
sub_82E2450: ; 82E2450
	push {r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E2464
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E2468
	movs r0, 0
	b _082E24F8
	.align 2, 0
_082E2464: .4byte 0x03001a7e
_082E2468:
	ldr r0, _082E249C
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E24A0
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E24A0
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E24A4
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x65
	bl sub_82E2820
	ldr r0, _082E24A4
	movs r1, 0x5
	strh r1, [r0]
	adds r0, r7, 0x4
	movs r1, 0
	strb r1, [r0]
_082E2492:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	cmp r1, 0x6
	bls _082E24A8
	b _082E24C6
	.align 2, 0
_082E249C: .4byte 0x03001a7e
_082E24A0: .4byte _080000C4
_082E24A4: .4byte _080000C6
_082E24A8:
	bl sub_82E2964
	adds r1, r7, 0x4
	ldrb r2, [r1]
	ldr r3, [r7]
	adds r1, r2, r3
	strb r0, [r1]
	adds r1, r7, 0x4
	adds r0, r7, 0x4
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E2492
_082E24C6:
	ldr r1, [r7]
	adds r0, r1, 0x4
	ldr r2, [r7]
	adds r1, r2, 0x4
	ldrb r2, [r1]
	movs r3, 0x7F
	adds r1, r2, 0
	ands r1, r3
	adds r2, r1, 0
	strb r2, [r0]
	ldr r0, _082E24F0
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E24F0
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E24F4
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E24F8
	.align 2, 0
_082E24F0: .4byte _080000C4
_082E24F4: .4byte 0x03001a7e
_082E24F8:
	add sp, 0x8
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2450

	thumb_func_start sub_82E2500
sub_82E2500: ; 82E2500
	push {r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E2514
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E2518
	movs r0, 0
	b _082E2594
	.align 2, 0
_082E2514: .4byte 0x03001a7e
_082E2518:
	ldr r0, _082E2548
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E254C
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E254C
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E2550
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x64
	bl sub_82E2820
	adds r0, r7, 0x4
	movs r1, 0
	strb r1, [r0]
_082E253C:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	cmp r1, 0x6
	bls _082E2554
	b _082E2574
	.align 2, 0
_082E2548: .4byte 0x03001a7e
_082E254C: .4byte _080000C4
_082E2550: .4byte _080000C6
_082E2554:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	ldr r2, [r7]
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r1, 0
	bl sub_82E28C4
	adds r1, r7, 0x4
	adds r0, r7, 0x4
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E253C
_082E2574:
	ldr r0, _082E258C
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E258C
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2590
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E2594
	.align 2, 0
_082E258C: .4byte _080000C4
_082E2590: .4byte 0x03001a7e
_082E2594:
	add sp, 0x8
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2500

	thumb_func_start sub_82E259C
sub_82E259C: ; 82E259C
	push {r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E25B0
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E25B4
	movs r0, 0
	b _082E2648
	.align 2, 0
_082E25B0: .4byte 0x03001a7e
_082E25B4:
	ldr r0, _082E25E8
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E25EC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E25EC
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E25F0
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x67
	bl sub_82E2820
	ldr r0, _082E25F0
	movs r1, 0x5
	strh r1, [r0]
	adds r0, r7, 0x4
	movs r1, 0
	strb r1, [r0]
_082E25DE:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	cmp r1, 0x2
	bls _082E25F4
	b _082E2614
	.align 2, 0
_082E25E8: .4byte 0x03001a7e
_082E25EC: .4byte _080000C4
_082E25F0: .4byte _080000C6
_082E25F4:
	bl sub_82E2964
	adds r1, r7, 0x4
	ldrb r2, [r1]
	ldr r3, [r7]
	adds r1, r2, r3
	adds r2, r1, 0x4
	strb r0, [r2]
	adds r1, r7, 0x4
	adds r0, r7, 0x4
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E25DE
_082E2614:
	ldr r1, [r7]
	adds r0, r1, 0x4
	ldr r2, [r7]
	adds r1, r2, 0x4
	ldrb r2, [r1]
	movs r3, 0x7F
	adds r1, r2, 0
	ands r1, r3
	adds r2, r1, 0
	strb r2, [r0]
	ldr r0, _082E2640
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2640
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2644
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E2648
	.align 2, 0
_082E2640: .4byte _080000C4
_082E2644: .4byte 0x03001a7e
_082E2648:
	add sp, 0x8
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E259C

	thumb_func_start sub_82E2650
sub_82E2650: ; 82E2650
	push {r7,lr}
	sub sp, 0x8
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E2664
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E2668
	movs r0, 0
	b _082E26E4
	.align 2, 0
_082E2664: .4byte 0x03001a7e
_082E2668:
	ldr r0, _082E2698
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _082E269C
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E269C
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E26A0
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x66
	bl sub_82E2820
	adds r0, r7, 0x4
	movs r1, 0
	strb r1, [r0]
_082E268C:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	cmp r1, 0x2
	bls _082E26A4
	b _082E26C6
	.align 2, 0
_082E2698: .4byte 0x03001a7e
_082E269C: .4byte _080000C4
_082E26A0: .4byte _080000C6
_082E26A4:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	ldr r2, [r7]
	adds r0, r1, r2
	adds r1, r0, 0x4
	ldrb r2, [r1]
	adds r0, r2, 0
	bl sub_82E28C4
	adds r1, r7, 0x4
	adds r0, r7, 0x4
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E268C
_082E26C6:
	ldr r0, _082E26DC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E26DC
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E26E0
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E26E4
	.align 2, 0
_082E26DC: .4byte _080000C4
_082E26E0: .4byte 0x03001a7e
_082E26E4:
	add sp, 0x8
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2650

	thumb_func_start sub_82E26EC
sub_82E26EC: ; 82E26EC
	push {r4,r7,lr}
	sub sp, 0xC
	mov r7, sp
	str r0, [r7]
	ldr r0, _082E2700
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _082E2704
	movs r0, 0
	b _082E2818
	.align 2, 0
_082E2700: .4byte 0x03001a7e
_082E2704:
	ldr r0, _082E276C
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r7, 0
	adds r0, 0x8
	ldr r1, [r7]
	ldrb r2, [r1, 0x8]
	movs r3, 0xF
	adds r1, r2, 0
	ands r1, r3
	ldr r2, [r7]
	ldrb r3, [r2, 0x8]
	lsrs r2, r3, 4
	adds r3, r2, 0
	movs r4, 0xF
	adds r2, r3, 0
	ands r2, r4
	adds r4, r2, 0
	lsls r3, r4, 24
	lsrs r2, r3, 24
	adds r4, r2, 0
	lsls r3, r4, 2
	adds r3, r2
	lsls r2, r3, 1
	adds r1, r2
	ldrb r2, [r0]
	movs r3, 0
	ands r2, r3
	adds r3, r2, 0
	adds r2, r3, 0
	orrs r2, r1
	adds r1, r2, 0
	strb r1, [r0]
	adds r0, r7, 0
	adds r0, 0x8
	ldrb r1, [r0]
	cmp r1, 0xB
	bhi _082E2770
	adds r0, r7, 0
	adds r0, 0x8
	ldr r1, [r7]
	ldrb r2, [r0]
	movs r3, 0
	ands r2, r3
	adds r3, r2, 0
	ldrb r1, [r1, 0x8]
	adds r2, r3, 0
	orrs r2, r1
	adds r1, r2, 0
	strb r1, [r0]
	b _082E278E
	.align 2, 0
_082E276C: .4byte 0x03001a7e
_082E2770:
	adds r0, r7, 0
	adds r0, 0x8
	ldr r1, [r7]
	ldrb r2, [r1, 0x8]
	movs r3, 0x80
	adds r1, r2, 0
	orrs r1, r3
	ldrb r2, [r0]
	movs r3, 0
	ands r2, r3
	adds r3, r2, 0
	adds r2, r3, 0
	orrs r2, r1
	adds r1, r2, 0
	strb r1, [r0]
_082E278E:
	adds r0, r7, 0
	adds r0, 0x8
	ldr r1, [r7]
	ldrb r2, [r0, 0x1]
	movs r3, 0
	ands r2, r3
	adds r3, r2, 0
	ldrb r1, [r1, 0x9]
	adds r2, r3, 0
	orrs r2, r1
	adds r1, r2, 0
	strb r1, [r0, 0x1]
	ldr r0, _082E27D0
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E27D0
	movs r1, 0x5
	strh r1, [r0]
	ldr r0, _082E27D4
	movs r1, 0x7
	strh r1, [r0]
	movs r0, 0x68
	bl sub_82E2820
	adds r0, r7, 0x4
	movs r1, 0
	strb r1, [r0]
_082E27C4:
	adds r0, r7, 0x4
	ldrb r1, [r0]
	cmp r1, 0x1
	bls _082E27D8
	b _082E27FA
	.align 2, 0
_082E27D0: .4byte _080000C4
_082E27D4: .4byte _080000C6
_082E27D8:
	adds r0, r7, 0
	adds r0, 0x8
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r1, 0
	bl sub_82E28C4
	adds r1, r7, 0x4
	adds r0, r7, 0x4
	adds r1, r7, 0x4
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E27C4
_082E27FA:
	ldr r0, _082E2810
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2810
	movs r1, 0x1
	strh r1, [r0]
	ldr r0, _082E2814
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	b _082E2818
	.align 2, 0
_082E2810: .4byte _080000C4
_082E2814: .4byte 0x03001a7e
_082E2818:
	add sp, 0xC
	pop {r4,r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E26EC

	thumb_func_start sub_82E2820
sub_82E2820: ; 82E2820
	push {r4,r5,r7,lr}
	sub sp, 0x4
	mov r7, sp
	adds r1, r0, 0
	adds r2, r7, 0
	strb r1, [r2]
	adds r1, r7, 0x1
	movs r2, 0
	strb r2, [r1]
_082E2832:
	adds r1, r7, 0x1
	ldrb r2, [r1]
	cmp r2, 0x7
	bls _082E283C
	b _082E28BC
_082E283C:
	adds r1, r7, 0x2
	adds r3, r7, 0
	ldrb r2, [r3]
	adds r3, r7, 0x1
	ldrb r4, [r3]
	movs r5, 0x7
	subs r3, r5, r4
	asrs r2, r3
	adds r3, r2, 0
	movs r4, 0x1
	adds r2, r3, 0
	ands r2, r4
	adds r3, r2, 0
	strb r3, [r1]
	ldr r1, _082E28B8
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E28B8
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E28B8
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E28B8
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x5
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	adds r2, r7, 0x1
	adds r1, r7, 0x1
	adds r2, r7, 0x1
	ldrb r3, [r2]
	adds r2, r3, 0x1
	adds r3, r2, 0
	strb r3, [r1]
	b _082E2832
	.align 2, 0
_082E28B8: .4byte _080000C4
_082E28BC:
	add sp, 0x4
	pop {r4,r5,r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2820

	thumb_func_start sub_82E28C4
sub_82E28C4: ; 82E28C4
	push {r4,r7,lr}
	sub sp, 0x4
	mov r7, sp
	adds r1, r0, 0
	adds r2, r7, 0
	strb r1, [r2]
	adds r1, r7, 0x1
	movs r2, 0
	strb r2, [r1]
_082E28D6:
	adds r1, r7, 0x1
	ldrb r2, [r1]
	cmp r2, 0x7
	bls _082E28E0
	b _082E295C
_082E28E0:
	adds r1, r7, 0x2
	adds r3, r7, 0
	ldrb r2, [r3]
	adds r3, r7, 0x1
	ldrb r4, [r3]
	asrs r2, r4
	adds r3, r2, 0
	movs r4, 0x1
	adds r2, r3, 0
	ands r2, r4
	adds r3, r2, 0
	strb r3, [r1]
	ldr r1, _082E2958
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E2958
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E2958
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x4
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	ldr r1, _082E2958
	adds r2, r7, 0x2
	ldrb r3, [r2]
	adds r2, r3, 0
	lsls r3, r2, 1
	adds r2, r3, 0
	movs r3, 0x5
	orrs r2, r3
	adds r3, r2, 0
	strh r3, [r1]
	adds r2, r7, 0x1
	adds r1, r7, 0x1
	adds r2, r7, 0x1
	ldrb r3, [r2]
	adds r2, r3, 0x1
	adds r3, r2, 0
	strb r3, [r1]
	b _082E28D6
	.align 2, 0
_082E2958: .4byte _080000C4
_082E295C:
	add sp, 0x4
	pop {r4,r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E28C4

	thumb_func_start sub_82E2964
sub_82E2964: ; 82E2964
	push {r7,lr}
	sub sp, 0x4
	mov r7, sp
	adds r0, r7, 0
	movs r1, 0
	strb r1, [r0]
_082E2970:
	adds r0, r7, 0
	ldrb r1, [r0]
	cmp r1, 0x7
	bls _082E297A
	b _082E29E0
_082E297A:
	ldr r0, _082E29DC
	movs r1, 0x4
	strh r1, [r0]
	ldr r0, _082E29DC
	movs r1, 0x4
	strh r1, [r0]
	ldr r0, _082E29DC
	movs r1, 0x4
	strh r1, [r0]
	ldr r0, _082E29DC
	movs r1, 0x4
	strh r1, [r0]
	ldr r0, _082E29DC
	movs r1, 0x4
	strh r1, [r0]
	ldr r0, _082E29DC
	movs r1, 0x5
	strh r1, [r0]
	adds r0, r7, 0x1
	ldr r1, _082E29DC
	ldrh r2, [r1]
	movs r3, 0x2
	adds r1, r2, 0
	ands r1, r3
	adds r3, r1, 0
	lsls r2, r3, 16
	lsrs r1, r2, 16
	lsrs r2, r1, 1
	adds r1, r2, 0
	strb r1, [r0]
	adds r0, r7, 0x2
	adds r1, r7, 0x2
	ldrb r2, [r1]
	lsrs r1, r2, 1
	adds r2, r7, 0x1
	ldrb r3, [r2]
	lsls r2, r3, 7
	orrs r1, r2
	adds r2, r1, 0
	strb r2, [r0]
	adds r1, r7, 0
	adds r0, r7, 0
	adds r1, r7, 0
	ldrb r2, [r1]
	adds r1, r2, 0x1
	adds r2, r1, 0
	strb r2, [r0]
	b _082E2970
	.align 2, 0
_082E29DC: .4byte _080000C4
_082E29E0:
	adds r0, r7, 0x2
	ldrb r1, [r0]
	adds r0, r1, 0
	b _082E29E8
_082E29E8:
	add sp, 0x4
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E2964

	thumb_func_start sub_82E29F0
sub_82E29F0: ; 82E29F0
	push {r7,lr}
	mov r7, sp
	ldr r0, _082E2A00
	movs r1, 0x1
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E2A00: .4byte _080000C8
	thumb_func_end sub_82E29F0

	thumb_func_start sub_82E2A04
sub_82E2A04: ; 82E2A04
	push {r7,lr}
	mov r7, sp
	ldr r0, _082E2A14
	movs r1, 0
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E2A14: .4byte _080000C8
	thumb_func_end sub_82E2A04
