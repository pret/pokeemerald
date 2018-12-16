	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




	thumb_func_start sub_80D0164
sub_80D0164: @ 80D0164
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, =0x00000974
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _080D01B0
	ldr r0, =gUnknown_0857BB1C
	bl AddWindow8Bit
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r2, 0x88
	lsls r2, 6
	adds r0, r2
	strh r1, [r0]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _080D01B0
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	b _080D01B2
	.pool
_080D01B0:
	movs r0, 0
_080D01B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0164

	thumb_func_start sub_80D01B8
sub_80D01B8: @ 80D01B8
	push {lr}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	cmp r0, 0
	beq _080D01C6
	bl Free
_080D01C6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D01B8

	thumb_func_start sub_80D01D0
sub_80D01D0: @ 80D01D0
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	movs r3, 0
	strb r0, [r1]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_80D01D0

	thumb_func_start sub_80D01E4
sub_80D01E4: @ 80D01E4
	push {lr}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _080D0244
	lsls r0, 2
	ldr r1, =_080D0204
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D0204:
	.4byte _080D021C
	.4byte _080D0222
	.4byte _080D0228
	.4byte _080D022E
	.4byte _080D0234
	.4byte _080D023A
_080D021C:
	bl sub_80D024C
	b _080D023E
_080D0222:
	bl sub_80D0344
	b _080D023E
_080D0228:
	bl sub_80D03B0
	b _080D023E
_080D022E:
	bl sub_80D0420
	b _080D023E
_080D0234:
	bl sub_80D04A0
	b _080D023E
_080D023A:
	bl sub_80D04C8
_080D023E:
	lsls r0, 24
	lsrs r0, 24
	b _080D0246
_080D0244:
	movs r0, 0
_080D0246:
	pop {r1}
	bx r1
	thumb_func_end sub_80D01E4

	thumb_func_start sub_80D024C
sub_80D024C: @ 80D024C
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =gUnknown_02039D80
	ldr r1, [r6]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x1
	beq _080D027C
	cmp r0, 0x1
	bgt _080D0268
	cmp r0, 0
	beq _080D026E
	b _080D0338
	.pool
_080D0268:
	cmp r0, 0x2
	beq _080D0324
	b _080D0338
_080D026E:
	movs r0, 0
	bl HideBg
	movs r0, 0x80
	bl sub_80D304C
	b _080D030E
_080D027C:
	adds r0, r1, 0x2
	adds r1, 0x3
	bl sub_80CFE14
	ldr r1, [r6]
	ldrb r0, [r1, 0x2]
	strb r0, [r1, 0x4]
	ldr r1, [r6]
	ldrb r0, [r1, 0x3]
	strb r0, [r1, 0x5]
	ldr r4, =0xfffffc00
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	movs r4, 0x88
	lsls r4, 6
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer8Bit
	ldr r1, [r6]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	bl sub_80D07B0
	movs r0, 0
	movs r1, 0x4
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram8Bit
	movs r0, 0xFC
	lsls r0, 6
	ldr r2, =0x00007fff
	movs r1, 0x8
	bl BlendPalettes
	movs r0, 0x2
	bl sub_80CFE54
	movs r0, 0x8
	movs r1, 0x80
	bl SetGpuRegBits
_080D030E:
	ldr r1, [r6]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0338
	.pool
_080D0324:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D0338
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D033A
_080D0338:
	movs r0, 0x1
_080D033A:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D024C

	thumb_func_start sub_80D0344
sub_80D0344: @ 80D0344
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D036E
	cmp r0, 0x1
	bgt _080D0360
	cmp r0, 0
	beq _080D0366
	b _080D03A8
	.pool
_080D0360:
	cmp r0, 0x2
	beq _080D0382
	b _080D03A8
_080D0366:
	movs r0, 0
	bl HideBg
	b _080D0378
_080D036E:
	bl sub_80D0B5C
	movs r0, 0
	bl sub_80CFE54
_080D0378:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D03A8
_080D0382:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D03A8
	bl sub_80CFE84
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D03AA
_080D03A8:
	movs r0, 0x1
_080D03AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0344

	thumb_func_start sub_80D03B0
sub_80D03B0: @ 80D03B0
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _080D03C8
	cmp r0, 0x1
	beq _080D040C
	b _080D0416
	.pool
_080D03C8:
	bl sub_80CD554
	lsls r0, 24
	cmp r0, 0
	bne _080D0416
	ldr r1, [r4]
	adds r0, r1, 0x6
	adds r1, 0x7
	bl sub_80CFE14
	bl sub_80D062C
	ldr r1, [r4]
	ldrb r0, [r1, 0x6]
	strb r0, [r1, 0x4]
	ldr r1, [r4]
	ldrb r0, [r1, 0x7]
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x88
	lsls r1, 6
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram8Bit
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0416
	.pool
_080D040C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _080D0418
_080D0416:
	movs r0, 0x1
_080D0418:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D03B0

	thumb_func_start sub_80D0420
sub_80D0420: @ 80D0420
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D044E
	cmp r0, 0x1
	bgt _080D043C
	cmp r0, 0
	beq _080D0442
	b _080D0498
	.pool
_080D043C:
	cmp r0, 0x2
	beq _080D047A
	b _080D0498
_080D0442:
	bl sub_80D08CC
	bl sub_80D09A4
	movs r0, 0
	b _080D046C
_080D044E:
	bl DoMonPlaceChange
	lsls r0, 24
	cmp r0, 0
	bne _080D0498
	movs r0, 0x3
	bl sub_80CFE54
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	movs r2, 0x8
	bl sub_80D0884
	movs r0, 0x1
_080D046C:
	bl sub_80CDC64
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0498
_080D047A:
	bl sub_80D0894
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl DoMonPlaceChange
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	bne _080D0498
	cmp r0, 0
	bne _080D0498
	movs r0, 0
	b _080D049A
_080D0498:
	movs r0, 0x1
_080D049A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0420

	thumb_func_start sub_80D04A0
sub_80D04A0: @ 80D04A0
	push {r4,lr}
	bl sub_80CD554
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80D0894
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	bne _080D04C0
	cmp r0, 0
	bne _080D04C0
	movs r0, 0
	b _080D04C2
_080D04C0:
	movs r0, 0x1
_080D04C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D04A0

	thumb_func_start sub_80D04C8
sub_80D04C8: @ 80D04C8
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _080D0506
	cmp r0, 0x1
	bgt _080D04E4
	cmp r0, 0
	beq _080D04EE
	b _080D0576
	.pool
_080D04E4:
	cmp r0, 0x2
	beq _080D0532
	cmp r0, 0x3
	beq _080D0550
	b _080D0576
_080D04EE:
	bl sub_80D0AAC
	movs r1, 0xFF
	lsls r1, 8
	movs r0, 0
	movs r2, 0x8
	bl sub_80D0884
	movs r0, 0
	bl sub_80CDC64
	b _080D0546
_080D0506:
	bl DoMonPlaceChange
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	bl sub_80D0894
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	bl sub_80D0A1C
	movs r0, 0x2
	bl sub_80CFE54
	movs r0, 0x1
	bl sub_80CDC64
	movs r0, 0
	bl HideBg
	b _080D0546
_080D0532:
	bl DoMonPlaceChange
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	movs r0, 0
	bl sub_80CFE54
	bl sub_80D0B5C
_080D0546:
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	b _080D0576
_080D0550:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _080D0576
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	bl sub_80CFE84
	movs r0, 0
	bl ShowBg
	movs r0, 0
	b _080D0578
_080D0576:
	movs r0, 0x1
_080D0578:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D04C8

	thumb_func_start sub_80D0580
sub_80D0580: @ 80D0580
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _080D05BC
	cmp r0, 0x1
	bgt _080D0596
	cmp r0, 0
	beq _080D05A0
	b _080D0624
_080D0596:
	cmp r1, 0x2
	beq _080D05DC
	cmp r1, 0x3
	beq _080D05FC
	b _080D0624
_080D05A0:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _080D060A
	subs r0, 0x1
	strb r0, [r1, 0x9]
	movs r1, 0x80
	lsls r1, 3
	movs r0, 0
	b _080D05F0
	.pool
_080D05BC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r2, [r1, 0x9]
	ldrb r0, [r1, 0xB]
	adds r0, r2, r0
	cmp r0, 0x4
	bgt _080D060A
	adds r0, r2, 0x1
	strb r0, [r1, 0x9]
	movs r1, 0xFC
	lsls r1, 8
	movs r0, 0
	b _080D05F0
	.pool
_080D05DC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _080D060A
	subs r0, 0x1
	strb r0, [r1, 0x8]
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0
_080D05F0:
	movs r2, 0x6
	bl sub_80D0884
	b _080D0624
	.pool
_080D05FC:
	ldr r0, =gUnknown_02039D80
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r0, [r1, 0xA]
	adds r0, r2, r0
	cmp r0, 0x5
	ble _080D0614
_080D060A:
	movs r0, 0
	b _080D0626
	.pool
_080D0614:
	adds r0, r2, 0x1
	strb r0, [r1, 0x8]
	movs r0, 0xFC
	lsls r0, 8
	movs r1, 0
	movs r2, 0x6
	bl sub_80D0884
_080D0624:
	movs r0, 0x1
_080D0626:
	pop {r1}
	bx r1
	thumb_func_end sub_80D0580

	thumb_func_start sub_80D062C
sub_80D062C: @ 80D062C
	push {r4-r7,lr}
	ldr r6, =gUnknown_02039D80
	ldr r2, [r6]
	ldrb r3, [r2, 0x2]
	ldrb r5, [r2, 0x6]
	subs r1, r3, r5
	cmp r1, 0
	bge _080D063E
	negs r1, r1
_080D063E:
	ldrb r0, [r2, 0x4]
	subs r0, r3, r0
	cmp r0, 0
	bge _080D0648
	negs r0, r0
_080D0648:
	subs r0, r1, r0
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x7]
	subs r3, r1, r0
	cmp r3, 0
	bge _080D065A
	negs r3, r3
_080D065A:
	ldrb r2, [r2, 0x5]
	subs r0, r1, r2
	cmp r0, 0
	bge _080D0664
	negs r0, r0
_080D0664:
	subs r0, r3, r0
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	cmp r4, 0
	ble _080D0678
	adds r0, r5, 0
	bl sub_80D06D0
_080D0678:
	cmp r4, 0
	bge _080D0694
	ldr r2, [r6]
	ldrb r0, [r2, 0x4]
	ldrb r1, [r2, 0x3]
	ldrb r2, [r2, 0x5]
	bl sub_80D0740
	ldr r2, [r6]
	ldrb r0, [r2, 0x6]
	ldrb r1, [r2, 0x3]
	ldrb r2, [r2, 0x5]
	bl sub_80D06D0
_080D0694:
	lsls r0, r7, 16
	asrs r4, r0, 16
	cmp r4, 0
	ble _080D06A8
	ldr r2, [r6]
	ldrb r0, [r2, 0x7]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0708
_080D06A8:
	cmp r4, 0
	bge _080D06C4
	ldr r2, [r6]
	ldrb r0, [r2, 0x5]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0778
	ldr r2, [r6]
	ldrb r0, [r2, 0x7]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x4]
	bl sub_80D0708
_080D06C4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D062C

	thumb_func_start sub_80D06D0
sub_80D06D0: @ 80D06D0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D06EE
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0700
_080D06EE:
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	bl sub_80D07B0
	cmp r4, r5
	bls _080D06EE
_080D0700:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D06D0

	thumb_func_start sub_80D0708
sub_80D0708: @ 80D0708
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D0726
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0738
_080D0726:
	adds r0, r4, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r6, 0
	bl sub_80D07B0
	cmp r4, r5
	bls _080D0726
_080D0738:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0708

	thumb_func_start sub_80D0740
sub_80D0740: @ 80D0740
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D075E
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D0770
_080D075E:
	adds r1, r4, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	bl sub_80D0834
	cmp r4, r5
	bls _080D075E
_080D0770:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0740

	thumb_func_start sub_80D0778
sub_80D0778: @ 80D0778
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r4, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r5, 0
	cmp r4, r5
	bls _080D0796
	adds r4, r5, 0
	adds r5, r1, 0
	cmp r0, r5
	bhi _080D07A8
_080D0796:
	adds r0, r4, 0
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r4, r1, 24
	adds r1, r6, 0
	bl sub_80D0834
	cmp r4, r5
	bls _080D0796
_080D07A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D0778

	thumb_func_start sub_80D07B0
sub_80D07B0: @ 80D07B0
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r7, r0, r1
	lsls r4, r7, 1
	adds r4, r6, r4
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x41
	bl GetCurrentBoxMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0
	bl GetCurrentBoxMonData
	adds r1, r0, 0
	cmp r5, 0
	beq _080D0828
	adds r0, r5, 0
	movs r2, 0x1
	bl GetMonIconPtr
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_80D3080
	adds r0, 0x8
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039D08
	ldr r1, [r1]
	movs r2, 0x88
	lsls r2, 6
	adds r1, r2
	ldrb r3, [r1]
	movs r2, 0x20
	str r2, [sp]
	str r2, [sp, 0x4]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	str r1, [sp, 0x8]
	lsls r1, r7, 3
	str r1, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	str r0, [sp, 0x18]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow4BitTo8Bit
_080D0828:
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D07B0

	thumb_func_start sub_80D0834
sub_80D0834: @ 80D0834
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r5, r0, r1
	lsls r0, r5, 1
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x41
	bl GetCurrentBoxMonData
	lsls r0, 16
	cmp r0, 0
	beq _080D0878
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	movs r1, 0x88
	lsls r1, 6
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r4, 1
	adds r2, r4
	lsls r2, 3
	lsls r3, r5, 3
	movs r1, 0x20
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	bl FillWindowPixelRect8Bit
_080D0878:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0834

	thumb_func_start sub_80D0884
sub_80D0884: @ 80D0884
	ldr r3, =gUnknown_02039D80
	ldr r3, [r3]
	strh r0, [r3, 0xC]
	strh r1, [r3, 0xE]
	strh r2, [r3, 0x10]
	bx lr
	.pool
	thumb_func_end sub_80D0884

	thumb_func_start sub_80D0894
sub_80D0894: @ 80D0894
	push {r4,lr}
	ldr r4, =gUnknown_02039D80
	ldr r1, [r4]
	ldrh r0, [r1, 0x10]
	cmp r0, 0
	beq _080D08BE
	ldrh r1, [r1, 0xC]
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgX
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, [r4]
	ldrh r0, [r1, 0x10]
	subs r0, 0x1
	strh r0, [r1, 0x10]
_080D08BE:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D0894

	thumb_func_start sub_80D08CC
sub_80D08CC: @ 80D08CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gUnknown_02039D80
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	ldrb r2, [r1, 0x2]
	cmp r0, r2
	bls _080D08E4
	adds r0, r2, 0
_080D08E4:
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	ldrb r0, [r1, 0x5]
	ldrb r2, [r1, 0x3]
	cmp r0, r2
	bls _080D08F2
	adds r0, r2, 0
_080D08F2:
	strb r0, [r1, 0x9]
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x4]
	subs r0, r1, r0
	cmp r0, 0
	bge _080D0902
	negs r0, r0
_080D0902:
	adds r0, 0x1
	strb r0, [r2, 0xA]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x5]
	subs r0, r1, r0
	cmp r0, 0
	bge _080D0914
	negs r0, r0
_080D0914:
	adds r0, 0x1
	strb r0, [r2, 0xB]
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r6, 0
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r8, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1
	mov r9, r0
	adds r2, r1, 0
	cmp r2, r9
	bge _080D0990
_080D093C:
	lsls r0, r2, 1
	adds r0, r2
	ldr r3, =gUnknown_02039D80
	ldr r1, [r3]
	lsls r0, 1
	ldrb r3, [r1, 0x8]
	adds r0, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r7, r2, 0x1
	cmp r4, r8
	bge _080D098A
	mov r0, r8
	subs r4, r0, r4
_080D095A:
	mov r0, r10
	adds r1, r5, 0
	bl GetBoxedMonPtr
	adds r1, r0, 0
	ldr r2, =gUnknown_02039D80
	ldr r0, [r2]
	lsls r2, r6, 2
	adds r2, r6
	lsls r2, 4
	adds r0, r2
	adds r0, 0x14
	movs r2, 0x50
	bl memcpy
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D095A
_080D098A:
	adds r2, r7, 0
	cmp r2, r9
	blt _080D093C
_080D0990:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D08CC

	thumb_func_start sub_80D09A4
sub_80D09A4: @ 80D09A4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r7, r2, r1
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r1, r0
	mov r9, r1
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, [r4]
	ldrb r2, [r0, 0x9]
	cmp r2, r9
	bge _080D0A0C
_080D09D0:
	lsls r0, r2, 1
	adds r0, r2
	ldr r1, =gUnknown_02039D80
	ldr r1, [r1]
	lsls r0, 1
	ldrb r3, [r1, 0x8]
	adds r0, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r6, r2, 0x1
	cmp r4, r7
	bge _080D0A06
	subs r4, r7, r4
_080D09EC:
	adds r0, r5, 0
	bl DestroyBoxMonIconAtPosition
	mov r0, r8
	adds r1, r5, 0
	bl ZeroBoxMonAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D09EC
_080D0A06:
	adds r2, r6, 0
	cmp r2, r9
	blt _080D09D0
_080D0A0C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D09A4

	thumb_func_start sub_80D0A1C
sub_80D0A1C: @ 80D0A1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r8, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1
	mov r10, r0
	movs r6, 0
	adds r2, r1, 0
	cmp r2, r10
	bge _080D0A98
_080D0A42:
	lsls r0, r2, 1
	adds r0, r2
	ldr r3, =gUnknown_02039D80
	ldr r1, [r3]
	lsls r0, 1
	ldrb r4, [r1, 0x8]
	adds r0, r4
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	adds r7, r2, 0x1
	cmp r4, r8
	bge _080D0A92
	mov r9, r3
	mov r0, r8
	subs r4, r0, r4
_080D0A62:
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 4
	adds r1, 0x14
	mov r2, r9
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0A80
	adds r0, r5, 0
	bl sub_80CB140
_080D0A80:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	subs r4, 0x1
	cmp r4, 0
	bne _080D0A62
_080D0A92:
	adds r2, r7, 0
	cmp r2, r10
	blt _080D0A42
_080D0A98:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0A1C

	thumb_func_start sub_80D0AAC
sub_80D0AAC: @ 80D0AAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, =gUnknown_02039D80
	ldr r0, [r4]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r10, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r1, r0
	str r1, [sp]
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r7, 0
	ldr r0, [r4]
	ldrb r3, [r0, 0x9]
	ldr r0, [sp]
	cmp r3, r0
	bge _080D0B46
_080D0AE2:
	lsls r0, r3, 1
	adds r0, r3
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	lsls r0, 1
	ldrb r4, [r1, 0x8]
	adds r0, r4
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r5, [r1, 0x8]
	adds r3, 0x1
	mov r9, r3
	cmp r5, r10
	bge _080D0B3E
	mov r8, r2
	mov r0, r10
	subs r5, r0, r5
_080D0B04:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 4
	adds r4, r0, 0
	adds r4, 0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0B2C
	mov r0, r8
	ldr r2, [r0]
	adds r2, r4
	ldr r0, [sp, 0x4]
	adds r1, r6, 0
	bl SetBoxMonAt
_080D0B2C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	subs r5, 0x1
	cmp r5, 0
	bne _080D0B04
_080D0B3E:
	mov r3, r9
	ldr r1, [sp]
	cmp r3, r1
	blt _080D0AE2
_080D0B46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0AAC

	thumb_func_start sub_80D0B5C
sub_80D0B5C: @ 80D0B5C
	push {lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0
	movs r1, 0x4
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x8
	movs r1, 0x80
	bl ClearGpuRegBits
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80D0B5C

	thumb_func_start sub_80D0BA4
sub_80D0BA4: @ 80D0BA4
	ldr r0, =gUnknown_02039D80
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	ldrb r2, [r2, 0x2]
	adds r0, r2
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_80D0BA4

	thumb_func_start sub_80D0BC0
sub_80D0BC0: @ 80D0BC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_02039D80
	ldr r0, [r0]
	ldrb r2, [r0, 0x8]
	ldrb r1, [r0, 0xA]
	adds r2, r1
	mov r9, r2
	ldrb r1, [r0, 0x9]
	ldrb r0, [r0, 0xB]
	adds r0, r1, r0
	str r0, [sp]
	movs r7, 0
	adds r6, r1, 0
	cmp r6, r0
	bge _080D0C4E
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 1
	mov r8, r0
_080D0BF0:
	ldr r2, =gUnknown_02039D80
	ldr r1, [r2]
	ldrb r0, [r1, 0x8]
	add r0, r8
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r4, [r1, 0x8]
	cmp r4, r9
	bge _080D0C42
	mov r10, r2
_080D0C04:
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 4
	adds r1, 0x14
	mov r2, r10
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D0C30
	adds r0, r5, 0
	movs r1, 0x5
	bl GetCurrentBoxMonData
	cmp r0, 0
	beq _080D0C30
	movs r0, 0
	b _080D0C50
	.pool
_080D0C30:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x1
	cmp r4, r9
	blt _080D0C04
_080D0C42:
	movs r0, 0x6
	add r8, r0
	adds r6, 0x1
	ldr r2, [sp]
	cmp r6, r2
	blt _080D0BF0
_080D0C4E:
	movs r0, 0x1
_080D0C50:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D0BC0

	thumb_func_start sub_80D0C60
sub_80D0C60: @ 80D0C60
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r3, =gUnknown_02039D08
	ldr r0, [r3]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0D3E
	ldr r0, =gUnknown_03000F78
	str r0, [sp, 0x18]
	ldr r1, =0xffff0000
	add r2, sp, 0x18
	ldr r0, [r2, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	str r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gSpriteTemplate_857BC70
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r7, 0
	mov r9, r2
	mov r8, r3
	movs r0, 0
	mov r10, r0
_080D0CA0:
	adds r6, r7, 0x7
	lsls r1, r6, 16
	mov r2, r9
	ldrh r0, [r2, 0x4]
	orrs r0, r1
	str r0, [r2, 0x4]
	mov r0, r9
	bl LoadCompressedObjectPic
	mov r4, r9
	ldrh r0, [r4, 0x6]
	bl GetSpriteTileStartByTag
	mov r5, r8
	ldr r1, [r5]
	lsls r5, r7, 4
	ldr r2, =0x00002208
	adds r1, r2
	adds r1, r5
	lsls r0, 16
	lsrs r0, 11
	ldr r4, =0x06010000
	adds r0, r4
	str r0, [r1]
	ldr r0, =0xffffdacb
	adds r4, r7, r0
	lsls r0, r4, 16
	lsrs r0, 16
	bl AllocSpritePalette
	mov r2, r8
	ldr r1, [r2]
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0000220c
	adds r1, r2
	strh r0, [r1]
	ldrh r0, [r1]
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	strh r0, [r1]
	mov r0, sp
	strh r6, [r0]
	strh r4, [r0, 0x2]
	movs r1, 0
	movs r2, 0
	movs r3, 0xB
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r4, r8
	ldr r2, [r4]
	ldr r6, =0x00002204
	adds r2, r6
	adds r2, r5
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r5
	ldr r1, =0x00002210
	adds r0, r1
	mov r2, r10
	strb r2, [r0]
	adds r7, 0x1
	cmp r7, 0x2
	ble _080D0CA0
_080D0D3E:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r4, =0x00002234
	adds r0, r4
	movs r1, 0
	strh r1, [r0]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0C60

	thumb_func_start sub_80D0D8C
sub_80D0D8C: @ 80D0D8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0E42
	mov r0, r8
	adds r1, r7, 0
	bl sub_80D1324
	cmp r0, 0
	bne _080D0E42
	mov r0, r8
	cmp r0, 0
	beq _080D0DC4
	cmp r0, 0x1
	beq _080D0DDA
	b _080D0E42
	.pool
_080D0DC4:
	adds r0, r7, 0
	movs r1, 0x5
	bl GetCurrentBoxMonData
	cmp r0, 0
	beq _080D0E42
	adds r0, r7, 0
	movs r1, 0xC
	bl GetCurrentBoxMonData
	b _080D0DFC
_080D0DDA:
	cmp r7, 0x5
	bhi _080D0E42
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _080D0E42
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
_080D0DFC:
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080D0E42
	adds r0, r4, 0
	bl GetItemIconPic
	adds r6, r0, 0
	adds r0, r4, 0
	bl GetItemIconPalette
	adds r5, r0, 0
	bl sub_80D12E8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_80D140C
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80D1524
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D1740
_080D0E42:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0D8C

	thumb_func_start sub_80D0E50
sub_80D0E50: @ 80D0E50
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0E86
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
_080D0E86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0E50

	thumb_func_start sub_80D0E90
sub_80D0E90: @ 80D0E90
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D0F20
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_80D140C
	cmp r6, 0
	bne _080D0EF8
	adds r0, r5, 0
	movs r1, 0xC
	mov r2, sp
	bl SetCurrentBoxMonData
	adds r0, r5, 0
	movs r1, 0x1
	bl SetBoxMonIconObjMode
	b _080D0F10
	.pool
_080D0EF8:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x1
	bl SetPartyMonIconObjMode
_080D0F10:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00000ce6
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r2, =0x00002234
	adds r0, r2
	strh r1, [r0]
_080D0F20:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0E90

	thumb_func_start sub_80D0F38
sub_80D0F38: @ 80D0F38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r5, 0
	bl GetItemIconPic
	mov r8, r0
	adds r0, r5, 0
	bl GetItemIconPalette
	adds r6, r0, 0
	bl sub_80D12E8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_80D1524
	adds r0, r4, 0
	movs r1, 0x6
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_80D1604
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_80D140C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80D1740
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	strh r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0F38

	thumb_func_start sub_80D0FAC
sub_80D0FAC: @ 80D0FAC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039D08
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D106A
	mov r0, r9
	adds r1, r7, 0
	bl sub_80D1370
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
	mov r1, r9
	cmp r1, 0
	bne _080D101C
	adds r0, r7, 0
	movs r1, 0xC
	bl GetCurrentBoxMonData
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r8
	ldr r2, [r0]
	ldr r4, =0x00002234
	adds r2, r4
	adds r0, r7, 0
	movs r1, 0xC
	bl SetCurrentBoxMonData
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	b _080D1048
	.pool
_080D101C:
	movs r0, 0x64
	adds r4, r7, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r8
	ldr r2, [r0]
	ldr r5, =0x00002234
	adds r2, r5
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
_080D1048:
	strh r6, [r0]
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x4
	mov r2, r9
	adds r3, r7, 0
	bl sub_80D1604
_080D106A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D0FAC

	thumb_func_start sub_80D1080
sub_80D1080: @ 80D1080
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	mov r8, r5
	ldr r6, =gUnknown_02039D08
	ldr r0, [r6]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D1100
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_80D1604
	cmp r7, 0
	bne _080D10E0
	ldr r2, [r6]
	ldr r0, =0x00002234
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0xC
	bl SetCurrentBoxMonData
	adds r0, r5, 0
	movs r1, 0
	bl SetBoxMonIconObjMode
	b _080D1100
	.pool
_080D10E0:
	movs r0, 0x64
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r2, [r6]
	ldr r1, =0x00002234
	adds r2, r1
	movs r1, 0xC
	bl SetMonData
	mov r0, r8
	movs r1, 0
	bl SetPartyMonIconObjMode
_080D1100:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1080

	thumb_func_start sub_80D1114
sub_80D1114: @ 80D1114
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D1188
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_80D1604
	cmp r6, 0
	bne _080D1170
	adds r0, r5, 0
	movs r1, 0xC
	mov r2, sp
	bl SetCurrentBoxMonData
	adds r0, r5, 0
	movs r1, 0x1
	bl SetBoxMonIconObjMode
	b _080D1188
	.pool
_080D1170:
	movs r0, 0x64
	muls r0, r7
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x1
	bl SetPartyMonIconObjMode
_080D1188:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1114

	thumb_func_start sub_80D1194
sub_80D1194: @ 80D1194
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D11C2
	movs r0, 0x2
	movs r1, 0
	bl sub_80D1370
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x5
	bl sub_80D15D4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
_080D11C2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1194

	thumb_func_start sub_80D11CC
sub_80D11CC: @ 80D11CC
	push {r4,lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x3
	bne _080D120A
	movs r4, 0
_080D11DA:
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	lsls r0, r4, 4
	adds r1, r0
	ldr r2, =0x00002210
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1204
	subs r2, 0x2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D1204
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x7
	movs r2, 0x2
	movs r3, 0
	bl sub_80D1604
_080D1204:
	adds r4, 0x1
	cmp r4, 0x2
	ble _080D11DA
_080D120A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D11CC

	thumb_func_start sub_80D1218
sub_80D1218: @ 80D1218
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002204
	adds r4, r0, r1
	adds r3, r0, 0
_080D1226:
	ldr r1, =0x00002210
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1268
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x28
	ands r0, r1
	cmp r0, 0x8
	beq _080D124E
	ldr r1, [r2, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _080D1268
	ldr r0, =sub_80D1AD8
	cmp r1, r0
	beq _080D1268
_080D124E:
	movs r0, 0x1
	b _080D1274
	.pool
_080D1268:
	adds r4, 0x10
	adds r3, 0x10
	adds r5, 0x1
	cmp r5, 0x2
	ble _080D1226
	movs r0, 0
_080D1274:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1218

	thumb_func_start sub_80D127C
sub_80D127C: @ 80D127C
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x3
	bne _080D12B0
	movs r2, 0
	ldr r0, =0x0000220e
	adds r1, r0
_080D128E:
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _080D12A8
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _080D12A8
	movs r0, 0x1
	b _080D12B2
	.pool
_080D12A8:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x2
	ble _080D128E
_080D12B0:
	movs r0, 0
_080D12B2:
	pop {r1}
	bx r1
	thumb_func_end sub_80D127C

	thumb_func_start GetMovingItemName
GetMovingItemName: @ 80D12B8
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetName
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMovingItemName

	thumb_func_start GetMovingItem
GetMovingItem: @ 80D12D4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end GetMovingItem

	thumb_func_start sub_80D12E8
sub_80D12E8: @ 80D12E8
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_02039D08
	ldr r3, =0x00002210
	movs r4, 0x1
_080D12F2:
	ldr r0, [r5]
	lsls r1, r2, 4
	adds r0, r1
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _080D1310
	strb r4, [r1]
	adds r0, r2, 0
	b _080D131C
	.pool
_080D1310:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _080D12F2
	movs r0, 0x3
_080D131C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D12E8

	thumb_func_start sub_80D1324
sub_80D1324: @ 80D1324
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	ldr r0, =gUnknown_02039D08
	ldr r2, [r0]
_080D1334:
	ldr r5, =0x00002210
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D1360
	subs r5, 0x2
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D1360
	adds r5, 0x1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r1
	bne _080D1360
	movs r0, 0x1
	b _080D136A
	.pool
_080D1360:
	adds r2, 0x10
	adds r3, 0x1
	cmp r3, 0x2
	ble _080D1334
	movs r0, 0
_080D136A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1324

	thumb_func_start sub_80D1370
sub_80D1370: @ 80D1370
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r3, 0
	ldr r0, =gUnknown_02039D08
	ldr r1, [r0]
_080D1380:
	lsls r0, r3, 4
	adds r2, r1, r0
	ldr r6, =0x00002210
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D13B0
	subs r6, 0x2
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r5
	bne _080D13B0
	adds r6, 0x1
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D13B0
	adds r0, r3, 0
	b _080D13BC
	.pool
_080D13B0:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _080D1380
	movs r0, 0x3
_080D13BC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D1370

	thumb_func_start sub_80D13C4
sub_80D13C4: @ 80D13C4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r2, 0
	ldr r0, =gUnknown_02039D08
	ldr r3, [r0]
	ldr r0, =0x00002204
	adds r4, r3, r0
	ldr r6, =0x00002210
_080D13D4:
	lsls r1, r2, 4
	adds r0, r3, r1
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080D13F8
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, r5
	bne _080D13F8
	adds r0, r2, 0
	b _080D1404
	.pool
_080D13F8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _080D13D4
	movs r0, 0x3
_080D1404:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80D13C4

	thumb_func_start sub_80D140C
sub_80D140C: @ 80D140C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	cmp r5, 0x2
	bhi _080D150A
	cmp r1, 0
	beq _080D1438
	cmp r1, 0x1
	beq _080D1494
	ldr r4, =gUnknown_02039D08
	lsls r3, r5, 4
	b _080D14F4
	.pool
_080D1438:
	adds r0, r7, 0
	movs r1, 0x6
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_02039D08
	ldr r2, [r6]
	lsls r5, 4
	ldr r1, =0x00002204
	adds r2, r1
	adds r2, r5
	ldr r3, [r2]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x70
	strh r1, [r3, 0x20]
	ldr r3, [r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x38
	strh r1, [r3, 0x22]
	ldr r2, [r2]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r4, r6, 0
	adds r3, r5, 0
	b _080D14F4
	.pool
_080D1494:
	cmp r7, 0
	bne _080D14BC
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0x74
	strh r1, [r2, 0x20]
	ldr r1, [r0]
	movs r0, 0x4C
	strh r0, [r1, 0x22]
	b _080D14DC
	.pool
_080D14BC:
	ldr r4, =gUnknown_02039D08
	ldr r0, [r4]
	lsls r3, r5, 4
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	movs r1, 0xA4
	strh r1, [r2, 0x20]
	ldr r2, [r0]
	subs r1, r7, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x1C
	strh r0, [r2, 0x22]
_080D14DC:
	ldr r0, [r4]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r3
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
_080D14F4:
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220e
	adds r0, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldr r1, =0x0000220f
	adds r0, r1
	strb r7, [r0]
_080D150A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D140C

	thumb_func_start sub_80D1524
sub_80D1524: @ 80D1524
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r1
	mov r9, r2
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x2
	bhi _080D15AC
	movs r0, 0
	str r0, [sp]
	ldr r4, =gUnknown_02039D08
	ldr r1, [r4]
	ldr r6, =0x000042c4
	adds r1, r6
	ldr r2, =0x01000080
	mov r0, sp
	bl CpuFastSet
	ldr r1, [r4]
	ldr r5, =0x000022c4
	adds r1, r5
	mov r0, r8
	bl LZ77UnCompWram
	lsls r7, 4
	mov r8, r7
	adds r7, r4, 0
	movs r4, 0x2
_080D1562:
	ldr r1, [r7]
	adds r0, r1, r5
	adds r1, r6
	movs r2, 0x18
	bl CpuFastSet
	adds r6, 0x80
	adds r5, 0x60
	subs r4, 0x1
	cmp r4, 0
	bge _080D1562
	ldr r5, =gUnknown_02039D08
	ldr r1, [r5]
	ldr r4, =0x000042c4
	adds r0, r1, r4
	ldr r2, =0x00002208
	adds r1, r2
	add r1, r8
	ldr r1, [r1]
	movs r2, 0x80
	bl CpuFastSet
	ldr r1, [r5]
	adds r1, r4
	mov r0, r9
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r4, r0, r4
	add r0, r8
	ldr r1, =0x0000220c
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
_080D15AC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1524

	thumb_func_start sub_80D15D4
sub_80D15D4: @ 80D15D4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r2, 0x2
	bhi _080D15F6
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r2, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	adds r1, r3, 0
	bl StartSpriteAffineAnim
_080D15F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D15D4

	thumb_func_start sub_80D1604
sub_80D1604: @ 80D1604
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	cmp r4, 0x2
	bls _080D161C
	b _080D172E
_080D161C:
	cmp r0, 0x7
	bls _080D1622
	b _080D172E
_080D1622:
	lsls r0, 2
	ldr r1, =_080D1630
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D1630:
	.4byte _080D1650
	.4byte _080D1674
	.4byte _080D1698
	.4byte _080D16C4
	.4byte _080D16F0
	.4byte _080D172E
	.4byte _080D172E
	.4byte _080D171C
_080D1650:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	strh r4, [r1, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A48
	b _080D172C
	.pool
_080D1674:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	ldr r0, =sub_80D1A74
	b _080D172C
	.pool
_080D1698:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1B14
	b _080D172C
	.pool
_080D16C4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r2, [r0]
	ldr r1, =sub_80D1B94
	str r1, [r2, 0x1C]
	strh r5, [r2, 0x3A]
	ldr r0, [r0]
	strh r3, [r0, 0x3C]
	b _080D172E
	.pool
_080D16F0:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	movs r1, 0
	strh r1, [r2, 0x2E]
	ldr r1, [r0]
	strh r5, [r1, 0x3A]
	ldr r1, [r0]
	strh r3, [r1, 0x3C]
	ldr r1, [r0]
	ldr r0, =sub_80D1C30
	b _080D172C
	.pool
_080D171C:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	lsls r1, r4, 4
	ldr r2, =0x00002204
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =sub_80D1CCC
_080D172C:
	str r0, [r1, 0x1C]
_080D172E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1604

	thumb_func_start sub_80D1740
sub_80D1740: @ 80D1740
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r2, 0x2
	bhi _080D1780
	ldr r1, =gUnknown_02039D08
	ldr r0, [r1]
	lsls r2, 4
	adds r0, r2
	ldr r3, =0x00002210
	adds r0, r3
	strb r4, [r0]
	ldr r0, [r1]
	ldr r1, =0x00002204
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	movs r3, 0
	cmp r4, 0
	bne _080D176E
	movs r3, 0x1
_080D176E:
	adds r2, r0, 0
	adds r2, 0x3E
	lsls r3, 2
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_080D1780:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1740

	thumb_func_start GetItemIconPic
GetItemIconPic: @ 80D1794
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPic

	thumb_func_start GetItemIconPalette
GetItemIconPalette: @ 80D17A4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPalette

	thumb_func_start sub_80D17B4
sub_80D17B4: @ 80D17B4
	push {r4,lr}
	sub sp, 0x14
	bl sub_80D127C
	lsls r0, 24
	cmp r0, 0
	beq _080D17D4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002234
	b _080D17DA
	.pool
_080D17D4:
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00000ce6
_080D17DA:
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetDescription
	adds r4, r0, 0
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized5
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D17B4

	thumb_func_start sub_80D1818
sub_80D1818: @ 80D1818
	push {lr}
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	movs r1, 0x15
	strh r1, [r0]
	ldr r1, =gUnknown_0857BB24
	movs r3, 0x9D
	lsls r3, 1
	movs r0, 0
	movs r2, 0x80
	bl LoadBgTiles
	movs r0, 0
	bl sub_80D19B4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1818

	thumb_func_start sub_80D184C
sub_80D184C: @ 80D184C
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	bne _080D186C
	movs r0, 0
	b _080D18D2
	.pool
_080D186C:
	subs r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D18BC
_080D187C:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D187C
_080D18BC:
	adds r0, r5, 0
	bl sub_80D19B4
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r1, =0x00002236
	adds r0, r1
	ldrh r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080D18D2:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D184C

	thumb_func_start sub_80D18E4
sub_80D18E4: @ 80D18E4
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02039D08
	ldr r0, [r5]
	ldr r4, =0x00002236
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x16
	bne _080D1904
	movs r0, 0
	b _080D19A4
	.pool
_080D1904:
	cmp r0, 0
	bne _080D1920
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x15
	movs r3, 0xC
	bl FillBgTilemapBufferRect
_080D1920:
	ldr r1, [r5]
	adds r1, r4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, 0x15
	subs r5, r0, r1
	movs r4, 0
	cmp r4, r5
	bge _080D1976
_080D1936:
	movs r0, 0
	movs r1, 0xA
	bl GetBgAttribute
	adds r1, r0, 0
	ldr r0, =gUnknown_02039D08
	ldr r0, [r0]
	ldr r2, =0x00002236
	adds r0, r2
	adds r1, 0x14
	ldrh r0, [r0]
	adds r1, r0
	adds r1, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r4, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x15
	str r0, [sp, 0xC]
	movs r0, 0
	movs r3, 0xD
	bl WriteSequenceToBgTilemapBuffer
	adds r4, 0x1
	cmp r4, r5
	blt _080D1936
_080D1976:
	cmp r5, 0
	blt _080D1980
	adds r0, r5, 0
	bl sub_80D19B4
_080D1980:
	adds r2, r5, 0x1
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x9
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
_080D19A4:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D18E4

	thumb_func_start sub_80D19B4
sub_80D19B4: @ 80D19B4
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	cmp r7, 0
	beq _080D19EC
	movs r1, 0x9D
	lsls r1, 1
	lsls r4, r7, 24
	lsrs r4, 24
	str r4, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000093a
	str r4, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r2, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
_080D19EC:
	ldr r1, =0x0000013b
	lsls r5, r7, 24
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r6, 0xF
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xD
	bl FillBgTilemapBufferRect
	movs r1, 0x9E
	lsls r1, 1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000013d
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	adds r2, r5, 0
	movs r3, 0x14
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D19B4

	thumb_func_start sub_80D1A48
sub_80D1A48: @ 80D1A48
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080D1A68
	ldrh r0, [r4, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1A68:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A48

	thumb_func_start sub_80D1A74
sub_80D1A74: @ 80D1A74
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _080D1A86
	cmp r1, 0x1
	beq _080D1AA2
	b _080D1AD0
_080D1A86:
	ldrh r0, [r3, 0x20]
	lsls r0, 4
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x22]
	lsls r0, 4
	strh r0, [r3, 0x32]
	movs r0, 0xA
	strh r0, [r3, 0x34]
	movs r0, 0x15
	strh r0, [r3, 0x36]
	strh r1, [r3, 0x38]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_080D1AA2:
	ldrh r1, [r3, 0x30]
	ldrh r0, [r3, 0x34]
	subs r1, r0
	strh r1, [r3, 0x30]
	ldrh r0, [r3, 0x32]
	ldrh r2, [r3, 0x36]
	subs r0, r2
	strh r0, [r3, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r3, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r3, 0x22]
	ldrh r0, [r3, 0x38]
	adds r0, 0x1
	strh r0, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1AD0
	ldr r0, =sub_80D1AD8
	str r0, [r3, 0x1C]
_080D1AD0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1A74

	thumb_func_start sub_80D1AD8
sub_80D1AD8: @ 80D1AD8
	ldr r1, =gUnknown_02039D08
	ldr r3, [r1]
	ldr r1, =0x00000cb4
	adds r3, r1
	ldr r1, [r3]
	ldrh r1, [r1, 0x20]
	adds r1, 0x4
	strh r1, [r0, 0x20]
	ldr r2, [r3]
	ldrh r1, [r2, 0x26]
	ldrh r2, [r2, 0x22]
	adds r1, r2
	adds r1, 0x8
	strh r1, [r0, 0x22]
	ldr r1, [r3]
	ldrb r1, [r1, 0x5]
	movs r2, 0xC
	ands r2, r1
	ldrb r3, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x5]
	bx lr
	.pool
	thumb_func_end sub_80D1AD8

	thumb_func_start sub_80D1B14
sub_80D1B14: @ 80D1B14
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1B26
	cmp r1, 0x1
	beq _080D1B42
	b _080D1B8A
_080D1B26:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1B42:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1B8A
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_080D1B8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B14

	thumb_func_start sub_80D1B94
sub_80D1B94: @ 80D1B94
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1BA6
	cmp r1, 0x1
	beq _080D1BC2
	b _080D1C20
_080D1BA6:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1BC2:
	ldrh r1, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	subs r1, r0
	strh r1, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	subs r0, r2
	strh r0, [r4, 0x32]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x20]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1C20
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =sub_80D1AD8
	str r0, [r4, 0x1C]
_080D1C20:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1B94

	thumb_func_start sub_80D1C30
sub_80D1C30: @ 80D1C30
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080D1C42
	cmp r1, 0x1
	beq _080D1C5E
	b _080D1CBE
_080D1C42:
	ldrh r0, [r4, 0x20]
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0xA
	strh r0, [r4, 0x34]
	movs r0, 0x15
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080D1C5E:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	ldrh r2, [r4, 0x32]
	adds r1, r2
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r4, 0x20]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r4, 0x22]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080D1CBE
	adds r0, r4, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r4, 0x3C]
	lsls r2, 24
	lsrs r2, 24
	bl sub_80D140C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x24]
_080D1CBE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1C30

	thumb_func_start sub_80D1CCC
sub_80D1CCC: @ 80D1CCC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x22]
	subs r0, 0x8
	strh r0, [r2, 0x22]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _080D1CFC
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	adds r0, r2, 0
	bl sub_80D13C4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80D1740
_080D1CFC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1CCC

	thumb_func_start TaskDummy0
TaskDummy0: @ 80D1D04
	bx lr
	thumb_func_end TaskDummy0

	thumb_func_start nullsub_98
nullsub_98: @ 80D1D08
	bx lr
	thumb_func_end nullsub_98

	thumb_func_start StorageGetCurrentBox
@ char StorageGetCurrentBox()
StorageGetCurrentBox: @ 80D1D0C
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end StorageGetCurrentBox

	thumb_func_start SetCurrentBox
SetCurrentBox: @ 80D1D18
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bhi _080D1D28
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	strb r1, [r0]
_080D1D28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetCurrentBox

	thumb_func_start GetBoxMonDataAt
GetBoxMonDataAt: @ 80D1D30
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1D6C
	cmp r4, 0x1D
	bhi _080D1D6C
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl GetBoxMonData
	b _080D1D6E
	.pool
_080D1D6C:
	movs r0, 0
_080D1D6E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetBoxMonDataAt

	thumb_func_start SetBoxMonDataFromAnyBox
SetBoxMonDataFromAnyBox: @ 80D1D74
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1DAC
	cmp r4, 0x1D
	bhi _080D1DAC
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl SetBoxMonData
_080D1DAC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonDataFromAnyBox

	thumb_func_start GetCurrentBoxMonData
GetCurrentBoxMonData: @ 80D1DB8
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r3, 0
	bl GetBoxMonDataAt
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetCurrentBoxMonData

	thumb_func_start SetCurrentBoxMonData
SetCurrentBoxMonData: @ 80D1DD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetBoxMonDataFromAnyBox
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetCurrentBoxMonData

	thumb_func_start GetBoxMonNickFromAnyBox
GetBoxMonNickFromAnyBox: @ 80D1DFC
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1E38
	cmp r4, 0x1D
	bhi _080D1E38
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl GetBoxMonData
	b _080D1E3C
	.pool
_080D1E38:
	movs r0, 0xFF
	strb r0, [r5]
_080D1E3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetBoxMonNickFromAnyBox

	thumb_func_start sub_80D1E44
sub_80D1E44: @ 80D1E44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r0, 0xD
	bhi _080D1E84
	cmp r2, 0x1D
	bhi _080D1E84
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D1E84
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	bl GetLevelFromBoxMonExp
_080D1E84:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D1E44

	thumb_func_start SetBoxMonNickFromAnyBox
SetBoxMonNickFromAnyBox: @ 80D1E90
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1EC6
	cmp r4, 0x1D
	bhi _080D1EC6
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	movs r1, 0x2
	adds r2, r5, 0
	bl SetBoxMonData
_080D1EC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonNickFromAnyBox

	thumb_func_start GetAndCopyBoxMonDataAt
GetAndCopyBoxMonDataAt: @ 80D1ED0
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D1F10
	cmp r4, 0x1D
	bhi _080D1F10
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	adds r2, r6, 0
	bl GetBoxMonData
	b _080D1F12
	.pool
_080D1F10:
	movs r0, 0
_080D1F12:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetAndCopyBoxMonDataAt

	thumb_func_start SetBoxMonAt
SetBoxMonAt: @ 80D1F18
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r4, 0xD
	bhi _080D1F4E
	cmp r1, 0x1D
	bhi _080D1F4E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	lsls r3, r1, 2
	adds r3, r1
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 5
	adds r3, r1
	adds r0, r3
	adds r0, 0x4
	adds r1, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonAt

	thumb_func_start sub_80D1F58
sub_80D1F58: @ 80D1F58
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r4, 0xD
	bhi _080D1F8E
	cmp r2, 0x1D
	bhi _080D1F8E
	ldr r0, =gPokemonStoragePtr
	ldr r1, [r0]
	lsls r3, r2, 2
	adds r3, r2
	lsls r3, 4
	lsls r2, r4, 2
	adds r2, r4
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	adds r3, r0
	adds r1, r3
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x50
	bl memcpy
_080D1F8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F58

	thumb_func_start sub_80D1F98
sub_80D1F98: @ 80D1F98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r6, [sp, 0x3C]
	mov r12, r6
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r0, r12
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r7, 0xD
	bhi _080D2004
	cmp r6, 0x1D
	bhi _080D2004
	ldr r2, =gPokemonStoragePtr
	lsls r0, r7, 2
	adds r0, r7
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 4
	adds r0, r1
	str r5, [sp]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x40]
	str r1, [sp, 0xC]
	mov r1, r9
	mov r2, r8
	adds r3, r4, 0
	bl CreateBoxMon
_080D2004:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D1F98

	thumb_func_start ZeroBoxMonAt
ZeroBoxMonAt: @ 80D2018
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2048
	cmp r4, 0x1D
	bhi _080D2048
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	bl ZeroBoxMonData
_080D2048:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ZeroBoxMonAt

	thumb_func_start BoxMonAtToMon
BoxMonAtToMon: @ 80D2054
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D2088
	cmp r4, 0x1D
	bhi _080D2088
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	adds r1, r5, 0
	bl BoxMonToMon
_080D2088:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BoxMonAtToMon

	thumb_func_start GetBoxedMonPtr
@ pokemon *GetBoxedMonPtr(u8 box_id, u8 pos)
GetBoxedMonPtr: @ 80D2094
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r3, 0xD
	bhi _080D20C8
	cmp r4, 0x1D
	bhi _080D20C8
	ldr r2, =gPokemonStoragePtr
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 4
	adds r0, r1
	b _080D20CA
	.pool
_080D20C8:
	movs r0, 0
_080D20CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBoxedMonPtr

	thumb_func_start GetBoxNamePtr
GetBoxNamePtr: @ 80D20D0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xD
	bls _080D20DE
	movs r0, 0
	b _080D20EC
_080D20DE:
	ldr r0, =gPokemonStoragePtr
	lsls r1, r2, 3
	adds r1, r2
	ldr r2, =0x00008344
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
_080D20EC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxNamePtr

	thumb_func_start GetBoxWallpaper
GetBoxWallpaper: @ 80D20F8
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xD
	bls _080D2106
	movs r0, 0
	b _080D2112
_080D2106:
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r2, =0x000083c2
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
_080D2112:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBoxWallpaper

	thumb_func_start SetBoxWallpaper
SetBoxWallpaper: @ 80D2120
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r2, 0xD
	bhi _080D213E
	cmp r1, 0x10
	bhi _080D213E
	ldr r0, =gPokemonStoragePtr
	ldr r0, [r0]
	ldr r3, =0x000083c2
	adds r0, r3
	adds r0, r2
	strb r1, [r0]
_080D213E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxWallpaper

	thumb_func_start sub_80D214C
sub_80D214C: @ 80D214C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r0, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	adds r4, r3, 0
	ldr r2, =0x0000ffff
	cmp r3, 0x1
	bhi _080D216E
	movs r2, 0x1
	cmp r3, 0x1
	beq _080D2172
_080D216E:
	cmp r4, 0x3
	bne _080D21BC
_080D2172:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D218A:
	asrs r4, r0, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	add r0, r8
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	bne _080D21B4
	asrs r0, r6, 16
	adds r0, r4, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D218A
	b _080D2208
	.pool
_080D21B4:
	adds r0, r4, 0
	b _080D220C
_080D21B8:
	adds r0, r5, 0
	b _080D220C
_080D21BC:
	lsls r0, 24
	asrs r0, 24
	lsls r2, 16
	asrs r1, r2, 16
	adds r1, r0
	lsls r0, r1, 16
	asrs r1, r0, 16
	adds r6, r2, 0
	cmp r1, 0
	blt _080D2208
	cmp r1, r7
	bgt _080D2208
_080D21D4:
	asrs r5, r0, 16
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 4
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21F8
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetBoxMonData
	cmp r0, 0
	beq _080D21B8
_080D21F8:
	asrs r0, r6, 16
	adds r0, r5, r0
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _080D2208
	cmp r2, r7
	ble _080D21D4
_080D2208:
	movs r0, 0x1
	negs r0, r0
_080D220C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D214C

	thumb_func_start CheckFreePokemonStorageSpace
CheckFreePokemonStorageSpace: @ 80D2218
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gPokemonStoragePtr
	mov r8, r0
	movs r7, 0x4
_080D2228:
	movs r5, 0
	adds r6, r7, 0
	movs r4, 0
_080D222E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	adds r0, r4
	movs r1, 0x5
	str r2, [sp]
	bl GetBoxMonData
	ldr r2, [sp]
	cmp r0, 0
	bne _080D224C
	movs r0, 0x1
	b _080D2262
	.pool
_080D224C:
	adds r4, 0x50
	adds r5, 0x1
	cmp r5, 0x1D
	ble _080D222E
	movs r0, 0x96
	lsls r0, 4
	adds r7, r0
	adds r2, 0x1
	cmp r2, 0xD
	ble _080D2228
	movs r0, 0
_080D2262:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckFreePokemonStorageSpace

	thumb_func_start CheckBoxedMonSanity
CheckBoxedMonSanity: @ 80D2270
	push {r4-r6,lr}
	adds r2, r1, 0
	cmp r0, 0xD
	bhi _080D22C8
	cmp r2, 0x1D
	bhi _080D22C8
	ldr r6, =gPokemonStoragePtr
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	ldr r0, [r6]
	adds r0, r5
	lsls r1, r2, 2
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	ldr r0, [r6]
	adds r0, r5
	adds r0, r4
	movs r1, 0x4
	bl GetBoxMonData
	cmp r0, 0
	bne _080D22C8
	movs r0, 0x1
	b _080D22CA
	.pool
_080D22C8:
	movs r0, 0
_080D22CA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CheckBoxedMonSanity

	thumb_func_start sub_80D22D0
sub_80D22D0: @ 80D22D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D22E0:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D22F4:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D231A
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D231A
	adds r7, 0x1
_080D231A:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D22F4
	mov r0, r8
	cmp r0, 0xD
	ble _080D22E0
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D22D0

	thumb_func_start sub_80D233C
sub_80D233C: @ 80D233C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	movs r0, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_080D234C:
	lsls r1, r0, 2
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	movs r5, 0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r4, r0, 0x4
	movs r6, 0x1D
_080D2360:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r4
	adds r0, r5
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2384
	mov r2, r9
	ldr r0, [r2]
	adds r0, r4
	adds r0, r5
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2386
_080D2384:
	adds r7, 0x1
_080D2386:
	adds r5, 0x50
	subs r6, 0x1
	cmp r6, 0
	bge _080D2360
	mov r0, r8
	cmp r0, 0xD
	ble _080D234C
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D233C

	thumb_func_start sub_80D23A8
sub_80D23A8: @ 80D23A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	ldr r0, =0x00000163
	strh r0, [r1, 0x2]
	movs r0, 0
	mov r8, r0
	ldr r7, =gPokemonStoragePtr
	movs r5, 0x4
_080D23C0:
	movs r6, 0
	movs r4, 0
_080D23C4:
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x5
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x6
	bl GetBoxMonData
	cmp r0, 0
	bne _080D2404
	ldr r0, [r7]
	adds r0, r5
	adds r0, r4
	movs r1, 0x51
	mov r2, sp
	bl GetBoxMonData
	cmp r0, 0
	beq _080D2404
	movs r0, 0x1
	b _080D241E
	.pool
_080D2404:
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1D
	ble _080D23C4
	movs r0, 0x96
	lsls r0, 4
	adds r5, r0
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0xD
	ble _080D23C0
	movs r0, 0
_080D241E:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D23A8

	thumb_func_start ResetWaldaWallpaper
ResetWaldaWallpaper: @ 80D242C
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x00003d84
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, =0x00003d85
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =0x00003d70
	adds r2, r1, r0
	ldr r0, =0x00007b35
	strh r0, [r2]
	subs r3, 0x14
	adds r2, r1, r3
	ldr r0, =0x00006186
	strh r0, [r2]
	ldr r0, =0x00003d74
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetWaldaWallpaper

	thumb_func_start SetWaldaWallpaperLockedOrUnlocked
SetWaldaWallpaperLockedOrUnlocked: @ 80D2480
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003d86
	adds r1, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SetWaldaWallpaperLockedOrUnlocked

	thumb_func_start IsWaldaWallpaperUnlocked
IsWaldaWallpaperUnlocked: @ 80D2494
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d86
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end IsWaldaWallpaperUnlocked

	thumb_func_start GetWaldaWallpaperPatternId
GetWaldaWallpaperPatternId: @ 80D24A8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d85
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperPatternId

	thumb_func_start SetWaldaWallpaperPatternId
SetWaldaWallpaperPatternId: @ 80D24BC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bhi _080D24D0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d85
	adds r0, r2
	strb r1, [r0]
_080D24D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperPatternId

	thumb_func_start GetWaldaWallpaperIconId
GetWaldaWallpaperIconId: @ 80D24DC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d84
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperIconId

	thumb_func_start SetWaldaWallpaperIconId
SetWaldaWallpaperIconId: @ 80D24F0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1D
	bhi _080D2504
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d84
	adds r0, r2
	strb r1, [r0]
_080D2504:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperIconId

	thumb_func_start GetWaldaWallpaperColorsPtr
GetWaldaWallpaperColorsPtr: @ 80D2510
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d70
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaWallpaperColorsPtr

	thumb_func_start SetWaldaWallpaperColors
SetWaldaWallpaperColors: @ 80D2524
	push {r4,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	ldr r4, =0x00003d70
	adds r3, r2, r4
	strh r0, [r3]
	ldr r0, =0x00003d72
	adds r2, r0
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaWallpaperColors

	thumb_func_start GetWaldaPhrasePtr
GetWaldaPhrasePtr: @ 80D2548
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d74
	adds r0, r1
	bx lr
	.pool
	thumb_func_end GetWaldaPhrasePtr

	thumb_func_start SetWaldaPhrase
SetWaldaPhrase: @ 80D255C
	push {lr}
	adds r1, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWaldaPhrase

	thumb_func_start IsWaldaPhraseEmpty
IsWaldaPhraseEmpty: @ 80D2578
	push {lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080D258C
	movs r1, 0x1
_080D258C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsWaldaPhraseEmpty

	thumb_func_start sub_80D259C
sub_80D259C: @ 80D259C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_02039D84
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	bl Alloc
	str r0, [r6]
	ldr r5, =gUnknown_02039D88
	movs r1, 0
	cmp r0, 0
	beq _080D25BA
	adds r1, r4, 0
_080D25BA:
	strh r1, [r5]
	movs r2, 0
	cmp r2, r1
	bcs _080D25E2
	movs r3, 0
	adds r4, r5, 0
_080D25C6:
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 4
	adds r1, r0
	str r3, [r1, 0x18]
	adds r1, 0x2C
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r4]
	cmp r2, r0
	bcc _080D25C6
_080D25E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D259C

	thumb_func_start sub_80D25F0
sub_80D25F0: @ 80D25F0
	push {lr}
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D25F0

	thumb_func_start sub_80D2604
sub_80D2604: @ 80D2604
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D2634
	movs r5, 0
_080D2612:
	ldr r0, =gUnknown_02039D84
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080D2628
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80D2918
_080D2628:
	adds r5, 0x30
	adds r4, 0x1
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D2612
_080D2634:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2604

	thumb_func_start sub_80D2644
sub_80D2644: @ 80D2644
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r2, 0
	ldr r2, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r6, r0
	bcs _080D272C
	ldr r0, =gUnknown_02039D84
	mov r9, r0
	ldr r0, [r0]
	lsls r1, r6, 1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, 4
	adds r0, r5, r0
	movs r1, 0
	str r1, [r0, 0x18]
	str r4, [r0, 0x1C]
	adds r0, 0x2B
	strb r7, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, r10
	strh r3, [r0, 0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	adds r0, r7, 0
	movs r1, 0x3
	bl GetBgAttribute
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	movs r1, 0x9
	bl GetBgAttribute
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	ldr r1, [r2]
	adds r5, r1
	ldr r2, =gSpriteTemplate_857BC88
	lsls r4, 2
	lsls r1, r0, 4
	adds r4, r1
	adds r4, r2
	ldrh r1, [r4]
	strh r1, [r5, 0x20]
	ldrh r1, [r4, 0x2]
	strh r1, [r5, 0x22]
	mov r2, r8
	cmp r0, 0
	beq _080D26E8
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x1
	b _080D26EE
	.pool
_080D26E8:
	adds r1, r5, 0
	adds r1, 0x2A
	movs r0, 0x2
_080D26EE:
	strb r0, [r1]
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	adds r2, r6
	lsls r2, 4
	adds r1, r2, r1
	adds r0, r1, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	mov r3, r10
	muls r3, r0
	movs r0, 0
	strh r3, [r1, 0x28]
	mov r3, r10
	strh r3, [r1, 0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, 0x12]
	strh r0, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, [r4]
	adds r2, r0
	adds r2, 0x2C
	movs r0, 0x1
	strb r0, [r2]
_080D272C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2644

	thumb_func_start sub_80D2740
sub_80D2740: @ 80D2740
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2764
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1
	str r3, [r0, 0x18]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D2764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2740

	thumb_func_start sub_80D2770
sub_80D2770: @ 80D2770
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r3, r0
	bcs _080D279C
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 4
	adds r0, r1
	strh r4, [r0, 0x14]
	strh r2, [r0, 0x16]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D279C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2770

	thumb_func_start sub_80D27AC
sub_80D27AC: @ 80D27AC
	push {r4-r6,lr}
	ldr r4, [sp, 0x10]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcs _080D27E6
	ldr r0, =gUnknown_02039D84
	ldr r1, [r0]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 4
	adds r0, r1
	strh r6, [r0, 0xC]
	strh r2, [r0, 0xE]
	strh r3, [r0, 0x10]
	strh r4, [r0, 0x12]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
_080D27E6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27AC

	thumb_func_start sub_80D27F4
sub_80D27F4: @ 80D27F4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r5, r0
	bcc _080D280C
	b _080D290E
_080D280C:
	ldr r4, =gUnknown_02039D84
	lsls r2, r5, 1
	cmp r1, 0x5
	bls _080D2816
	b _080D2900
_080D2816:
	lsls r0, r1, 2
	ldr r1, =_080D282C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080D282C:
	.4byte _080D2844
	.4byte _080D2864
	.4byte _080D2888
	.4byte _080D28A8
	.4byte _080D28CC
	.4byte _080D28E8
_080D2844:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x14]
	adds r0, r2
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0x10]
	subs r0, r2
	b _080D287E
	.pool
_080D2864:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x10]
	adds r0, r2
_080D287E:
	strh r0, [r1, 0x10]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D2888:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0x16]
	adds r0, r2
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x12]
	subs r0, r2
	b _080D28C2
	.pool
_080D28A8:
	ldr r4, =gUnknown_02039D84
	ldr r0, [r4]
	lsls r3, r5, 1
	adds r1, r3, r5
	lsls r1, 4
	adds r1, r0
	lsls r2, r6, 24
	asrs r2, 24
	ldrh r0, [r1, 0xE]
	subs r0, r2
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x12]
	adds r0, r2
_080D28C2:
	strh r0, [r1, 0x12]
	adds r2, r3, 0
	b _080D2900
	.pool
_080D28CC:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x14]
	adds r0, r4
	strh r0, [r1, 0x14]
	b _080D28FE
	.pool
_080D28E8:
	ldr r3, =gUnknown_02039D84
	ldr r0, [r3]
	lsls r2, r5, 1
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r4, [r1, 0x16]
	adds r0, r4
	strh r0, [r1, 0x16]
_080D28FE:
	adds r4, r3, 0
_080D2900:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0x1
	strb r0, [r1]
_080D290E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D27F4

	thumb_func_start sub_80D2918
sub_80D2918: @ 80D2918
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r6, r2, 0
	ldr r0, =gUnknown_02039D88
	ldrh r0, [r0]
	cmp r2, r0
	bcs _080D2952
	ldr r5, =gUnknown_02039D84
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r4, r1, 4
	adds r0, r4, r0
	ldr r0, [r0, 0x18]
	cmp r0, 0
	beq _080D2940
	adds r0, r2, 0
	bl sub_80D2960
_080D2940:
	adds r0, r6, 0
	bl sub_80D29F8
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0xC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080D2952:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2918

	thumb_func_start sub_80D2960
sub_80D2960: @ 80D2960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x20]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xA
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x18]
	adds r1, r2
	movs r6, 0x8
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x6]
	cmp r6, r0
	bge _080D29E4
	mov r10, r4
_080D29AA:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x8]
	ldrb r3, [r1, 0xA]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x4]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x6]
	cmp r6, r4
	blt _080D29AA
_080D29E4:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2960

	thumb_func_start sub_80D29F8
sub_80D29F8: @ 80D29F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gUnknown_02039D84
	ldr r1, [r4]
	lsls r5, r0, 1
	adds r0, r5, r0
	lsls r0, 4
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r3, [r1]
	ldrh r1, [r0, 0x24]
	adds r2, r3, 0
	muls r2, r1
	mov r9, r2
	movs r6, 0xE
	ldrsh r1, [r0, r6]
	mov r2, r9
	muls r2, r1
	ldr r1, [r0, 0x1C]
	adds r1, r2
	movs r6, 0xC
	ldrsh r2, [r0, r6]
	muls r2, r3
	adds r7, r1, r2
	movs r6, 0
	ldrh r0, [r0, 0x12]
	cmp r6, r0
	bge _080D2A7C
	mov r10, r4
_080D2A42:
	mov r0, r10
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, 4
	adds r1, r4, r1
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldrb r2, [r1, 0x14]
	ldrb r3, [r1, 0x16]
	adds r3, r6
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r1, 0x10]
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r7, 0
	bl CopyToBgTilemapBufferRect
	add r7, r9
	adds r6, 0x1
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0
	ldrh r4, [r4, 0x12]
	cmp r6, r4
	blt _080D2A42
_080D2A7C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D29F8

	thumb_func_start sub_80D2A90
sub_80D2A90: @ 80D2A90
	ldr r3, =gUnknown_02039D8C
	str r0, [r3]
	str r1, [r0]
	movs r1, 0
	strb r2, [r0, 0x5]
	strb r1, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_80D2A90

	thumb_func_start sub_80D2AA4
sub_80D2AA4: @ 80D2AA4
	push {r4,r5,lr}
	ldr r2, =gUnknown_02039D8C
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080D2AE2
	movs r4, 0
	ldrb r1, [r1, 0x4]
	cmp r4, r1
	bcs _080D2ADA
	adds r5, r2, 0
_080D2ABA:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r0, r1
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcc _080D2ABA
_080D2ADA:
	ldr r0, =gUnknown_02039D8C
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
_080D2AE2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2AA4

	thumb_func_start sub_80D2AEC
sub_80D2AEC: @ 80D2AEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r10, r3
	ldr r0, [sp, 0x24]
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2B74
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r4, 1
	strh r0, [r1, 0x8]
	ldr r2, [sp]
	lsls r0, r2, 5
	add r0, r12
	lsls r0, 1
	add r0, r9
	str r0, [r1, 0x4]
	adds r0, r3, 0
	muls r0, r6
	add r0, r8
	lsls r0, 1
	add r0, r10
	str r0, [r1]
	strh r5, [r1, 0xC]
	strh r6, [r1, 0xA]
	ldr r0, =sub_80D2B88
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2B76
	.pool
_080D2B74:
	movs r0, 0
_080D2B76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2AEC

	thumb_func_start sub_80D2B88
sub_80D2B88: @ 80D2B88
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _080D2BB2
_080D2B90:
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldrh r2, [r4, 0x8]
	lsrs r2, 1
	bl CpuSet
	ldr r0, [r4, 0x4]
	adds r0, 0x40
	str r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	lsls r1, 1
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080D2BB2:
	ldrh r0, [r4, 0xC]
	cmp r5, r0
	bcc _080D2B90
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80D2B88

	thumb_func_start sub_80D2BC0
sub_80D2BC0: @ 80D2BC0
	push {r4-r7,lr}
	mov r12, r0
	ldr r0, [sp, 0x14]
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02039D8C
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	adds r1, r0, 0
	ldrb r7, [r2, 0x5]
	cmp r1, r7
	bcs _080D2C14
	adds r0, 0x1
	strb r0, [r2, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	lsls r0, r3, 1
	strh r0, [r1, 0x8]
	lsls r0, r4, 5
	adds r0, r6
	lsls r0, 1
	add r0, r12
	str r0, [r1, 0x4]
	strh r5, [r1, 0xC]
	ldr r0, =sub_80D2C1C
	str r0, [r1, 0x10]
	movs r0, 0x1
	b _080D2C16
	.pool
_080D2C14:
	movs r0, 0
_080D2C16:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2BC0

	thumb_func_start sub_80D2C1C
sub_80D2C1C: @ 80D2C1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	movs r0, 0
	ldrh r1, [r6, 0xC]
	cmp r0, r1
	bcs _080D2CAA
	movs r7, 0x80
	lsls r7, 5
	mov r5, sp
	ldr r2, =0x040000d4
	mov r8, r2
	movs r1, 0x81
	lsls r1, 24
	mov r10, r1
_080D2C42:
	ldr r2, [r6, 0x4]
	ldrh r3, [r6, 0x8]
	mov r12, r2
	adds r0, 0x1
	mov r9, r0
	cmp r3, r7
	bhi _080D2C6C
	movs r0, 0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, r12
	str r1, [r0, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
	mov r1, r8
	b _080D2C94
	.pool
_080D2C6C:
	movs r4, 0
	strh r4, [r5]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000800
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r7
	subs r3, r7
	cmp r3, r7
	bhi _080D2C6C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r10
	orrs r0, r2
_080D2C94:
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, r12
	adds r0, 0x40
	str r0, [r6, 0x4]
	mov r1, r9
	lsls r0, r1, 16
	lsrs r0, 16
	ldrh r2, [r6, 0xC]
	cmp r0, r2
	bcc _080D2C42
_080D2CAA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2C1C

	.align 2, 0 @ Don't pad with nop.
