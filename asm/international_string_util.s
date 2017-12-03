	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_81DB41C
sub_81DB41C: @ 81DB41C
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	movs r7, 0
	movs r6, 0
	ldrh r0, [r4, 0xC]
	cmp r7, r0
	bge _081DB44C
	adds r5, r1, 0
_081DB42E:
	ldrb r0, [r4, 0x17]
	lsls r0, 26
	lsrs r0, 26
	ldr r1, [r5]
	movs r2, 0
	bl GetStringWidth
	cmp r0, r7
	ble _081DB442
	adds r7, r0, 0
_081DB442:
	adds r5, 0x8
	adds r6, 0x1
	ldrh r0, [r4, 0xC]
	cmp r6, r0
	blt _081DB42E
_081DB44C:
	ldrb r0, [r4, 0x12]
	adds r1, r7, r0
	adds r0, r1, 0
	adds r0, 0x9
	cmp r0, 0
	bge _081DB45A
	adds r0, 0x7
_081DB45A:
	asrs r0, 3
	cmp r0, 0x1C
	ble _081DB462
	movs r0, 0x1C
_081DB462:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB41C

	thumb_func_start CopyMonCategoryText
CopyMonCategoryText: @ 81DB468
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 5
	ldr r1, =gPokedexEntries
	adds r2, r1
	adds r1, r2, 0
	bl StringCopy
	movs r1, 0
	strb r1, [r0]
	adds r0, 0x1
	ldr r1, =gText_Pokemon
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyMonCategoryText

	thumb_func_start sub_81DB494
sub_81DB494: @ 81DB494
	push {r4-r7,lr}
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	cmp r5, 0
	beq _081DB4B6
	adds r1, r5, 0
	bl StringCopy
	adds r4, r0, 0
	lsls r0, r6, 24
	lsrs r0, 24
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	b _081DB4BA
_081DB4B6:
	adds r4, r0, 0
	movs r0, 0
_081DB4BA:
	subs r3, r7, r0
	cmp r3, 0
	ble _081DB4D4
	movs r0, 0xFC
	strb r0, [r4]
	adds r4, 0x1
	movs r0, 0x11
	strb r0, [r4]
	adds r4, 0x1
	strb r3, [r4]
	adds r4, 0x1
	movs r0, 0xFF
	strb r0, [r4]
_081DB4D4:
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB494

	thumb_func_start PadNameString
PadNameString: @ 81DB4DC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl StripExtCtrlCodes
	adds r0, r4, 0
	bl StringLength
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r5, 0xFC
	bne _081DB51A
	cmp r1, 0x5
	bhi _081DB51E
	movs r3, 0xFC
	movs r2, 0x7
_081DB4FE:
	adds r0, r4, r1
	strb r3, [r0]
	strb r2, [r0, 0x1]
	adds r0, r1, 0x2
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x5
	bls _081DB4FE
	b _081DB51E
_081DB510:
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_081DB51A:
	cmp r1, 0x5
	bls _081DB510
_081DB51E:
	adds r1, r4, r1
	movs r0, 0xFF
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end PadNameString

	thumb_func_start sub_81DB52C
sub_81DB52C: @ 81DB52C
	push {r4,lr}
	adds r4, r0, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081DB546
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _081DB54C
_081DB546:
	adds r0, r4, 0
	bl StripExtCtrlCodes
_081DB54C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB52C

	thumb_func_start sub_81DB554
sub_81DB554: @ 81DB554
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081DB572
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _081DB5A4
_081DB572:
	cmp r5, 0xFC
	bne _081DB57E
	adds r0, r4, 0
	bl StripExtCtrlCodes
	b _081DB5A4
_081DB57E:
	adds r1, r4, 0
	b _081DB584
_081DB582:
	adds r1, 0x1
_081DB584:
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _081DB582
	cmp r1, r4
	bcc _081DB5A4
	ldrb r0, [r1]
	cmp r0, r5
	bne _081DB5A4
	movs r2, 0xFF
_081DB596:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r4
	bcc _081DB5A4
	ldrb r0, [r1]
	cmp r0, r5
	beq _081DB596
_081DB5A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DB554

	thumb_func_start sub_81DB5AC
sub_81DB5AC: @ 81DB5AC
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	adds r2, 0x1
	cmp r0, 0xFC
	bne _081DB5E4
	ldrb r0, [r2]
	adds r2, 0x1
	cmp r0, 0x15
	bne _081DB5E4
	b _081DB5CE
_081DB5C2:
	cmp r1, 0xFC
	bne _081DB5CC
	ldrb r0, [r2, 0x1]
	cmp r0, 0x16
	beq _081DB5E4
_081DB5CC:
	adds r2, 0x1
_081DB5CE:
	ldrb r1, [r2]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _081DB5C2
	movs r0, 0xFC
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0x16
	strb r0, [r2]
	movs r0, 0xFF
	strb r0, [r2, 0x1]
_081DB5E4:
	pop {r0}
	bx r0
	thumb_func_end sub_81DB5AC

	thumb_func_start TVShowConvertInternationalString
TVShowConvertInternationalString: @ 81DB5E8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	bl StringCopy
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl ConvertInternationalString
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end TVShowConvertInternationalString

	thumb_func_start sub_81DB604
sub_81DB604: @ 81DB604
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0xFC
	bne _081DB618
	ldrb r0, [r1, 0x1]
	cmp r0, 0x15
	bne _081DB618
	movs r0, 0x1
	b _081DB61A
_081DB618:
	movs r0, 0x2
_081DB61A:
	pop {r1}
	bx r1
	thumb_func_end sub_81DB604

	thumb_func_start sub_81DB620
sub_81DB620: @ 81DB620
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	ldr r0, =gWindows
	adds r4, r0
	lsls r7, r3, 5
	ldrb r0, [r4, 0x3]
	lsls r6, r0, 5
	muls r2, r6
	ldr r0, [r4, 0x8]
	adds r0, r2
	lsls r1, 5
	adds r5, r0, r1
	ldr r0, [sp, 0x18]
	cmp r0, 0
	ble _081DB66C
	adds r4, r0, 0
_081DB646:
	ldr r0, =0x11111111
	str r0, [sp]
	adds r2, r7, 0
	cmp r2, 0
	bge _081DB652
	adds r2, 0x3
_081DB652:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	adds r1, r5, 0
	bl CpuFastSet
	adds r5, r6
	subs r4, 0x1
	cmp r4, 0
	bne _081DB646
_081DB66C:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB620

	.align 2, 0 @ Don't pad with nop.
