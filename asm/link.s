	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start HandleLinkConnection
HandleLinkConnection: @ 800B40C
	push {r4,r5,lr}
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B45C
	ldr r0, =gShouldAdvanceLinkState
	ldr r1, =gSendCmd
	ldr r2, =gRecvCmds
	bl sub_800B638
	ldr r4, =gLinkStatus
	str r0, [r4]
	ldr r0, =gMain+0x2c
	bl LinkMain2
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _0800B480
	bl sub_808766C
	cmp r0, 0x1
	bne _0800B480
_0800B43E:
	movs r0, 0x1
	b _0800B482
	.pool
_0800B45C:
	bl sub_8010EC0
	adds r4, r0, 0
	bl sub_8010F1C
	adds r5, r0, 0
	bl sub_808766C
	cmp r0, 0x1
	bne _0800B480
	cmp r4, 0x1
	beq _0800B43E
	bl sub_800F0B8
	cmp r0, 0
	bne _0800B43E
	cmp r5, 0
	bne _0800B43E
_0800B480:
	movs r0, 0
_0800B482:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end HandleLinkConnection

	thumb_func_start sub_800B488
sub_800B488: @ 800B488
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B498
	ldr r1, =gWirelessCommType
	movs r0, 0x1
	strb r0, [r1]
_0800B498:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B488

	thumb_func_start sub_800B4A4
sub_800B4A4: @ 800B4A4
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r1, [r0]
	cmp r1, 0
	bne _0800B4B2
	ldr r0, =gWirelessCommType
	strb r1, [r0]
_0800B4B2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B4A4

	thumb_func_start sub_800B4C0
sub_800B4C0: @ 800B4C0
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r1, [r0]
	cmp r1, 0
	bne _0800B4CE
	ldr r0, =gWirelessCommType
	strb r1, [r0]
_0800B4CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B4C0

	thumb_func_start sub_800B4DC
sub_800B4DC: @ 800B4DC
	push {lr}
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800B4FC
	ldr r0, =gLink
	ldr r1, =0x00000fbd
	adds r0, r1
	ldrb r0, [r0]
	b _0800B500
	.pool
_0800B4FC:
	bl sub_80124D4
_0800B500:
	pop {r1}
	bx r1
	thumb_func_end sub_800B4DC

	thumb_func_start sub_800B504
sub_800B504: @ 800B504
	push {lr}
	bl sub_800B4DC
	cmp r0, 0x2
	bhi _0800B512
	movs r0, 0
	b _0800B514
_0800B512:
	movs r0, 0x1
_0800B514:
	pop {r1}
	bx r1
	thumb_func_end sub_800B504

	thumb_func_start sub_800B518
sub_800B518: @ 800B518
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_800B518

	thumb_func_start sub_800B524
sub_800B524: @ 800B524
	push {lr}
	ldrb r1, [r0, 0x10]
	strb r1, [r0, 0x12]
	adds r2, r0, 0
	adds r2, 0x8
	ldrb r1, [r0, 0x1A]
	adds r0, r2, 0
	bl ConvertInternationalString
	pop {r0}
	bx r0
	thumb_func_end sub_800B524

	thumb_func_start DisableSerial
DisableSerial: @ 800B53C
	push {lr}
	sub sp, 0x4
	movs r0, 0xC0
	bl DisableInterrupts
	ldr r1, =0x04000128
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x0400010e
	movs r2, 0
	strh r2, [r0]
	adds r1, 0xDA
	movs r0, 0xC0
	strh r0, [r1]
	ldr r0, =0x0400012a
	strh r2, [r0]
	ldr r2, =0x04000120
	movs r0, 0
	movs r1, 0
	str r0, [r2]
	str r1, [r2, 0x4]
	str r0, [sp]
	ldr r1, =gLink
	ldr r2, =0x050003f0
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisableSerial

	thumb_func_start EnableSerial
EnableSerial: @ 800B594
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0xC0
	bl DisableInterrupts
	ldr r0, =0x04000134
	movs r4, 0
	strh r4, [r0]
	ldr r2, =0x04000128
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, =0x00004003
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x80
	bl EnableInterrupts
	ldr r0, =0x0400012a
	strh r4, [r0]
	movs r5, 0
	str r5, [sp]
	ldr r1, =gLink
	ldr r2, =0x050003f0
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_03000D6C
	strb r4, [r0]
	ldr r0, =gUnknown_03000D6E
	strh r5, [r0]
	ldr r0, =gUnknown_03000D70
	strh r5, [r0]
	ldr r0, =gUnknown_03000D72
	strb r4, [r0]
	ldr r0, =gUnknown_03000D73
	strb r4, [r0]
	ldr r0, =gLastSendQueueCount
	strb r4, [r0]
	ldr r0, =gLastRecvQueueCount
	strb r4, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EnableSerial

	thumb_func_start ResetSerial
ResetSerial: @ 800B628
	push {lr}
	bl EnableSerial
	bl DisableSerial
	pop {r0}
	bx r0
	thumb_func_end ResetSerial

	thumb_func_start sub_800B638
sub_800B638: @ 800B638
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, =gLink
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bhi _0800B6EA
	lsls r0, 2
	ldr r1, =_0800B65C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800B65C:
	.4byte _0800B670
	.4byte _0800B680
	.4byte _0800B698
	.4byte _0800B6D4
	.4byte _0800B6DE
_0800B670:
	bl DisableSerial
	ldr r1, =gLink
	movs r0, 0x1
	strb r0, [r1, 0x1]
	b _0800B6EA
	.pool
_0800B680:
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _0800B6EA
	bl EnableSerial
	ldr r1, =gLink
	movs r0, 0x2
	strb r0, [r1, 0x1]
	b _0800B6EA
	.pool
_0800B698:
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _0800B6A8
	cmp r1, 0x2
	beq _0800B6C0
	bl sub_800B764
	b _0800B6EA
_0800B6A8:
	ldr r2, =gLink
	ldrb r0, [r2]
	cmp r0, 0x8
	bne _0800B6EA
	ldrb r0, [r2, 0x3]
	cmp r0, 0x1
	bls _0800B6EA
	strb r1, [r2, 0xE]
	b _0800B6EA
	.pool
_0800B6C0:
	ldr r0, =gLink
	movs r1, 0
	strb r1, [r0, 0x1]
	ldr r0, =0x0400012a
	strh r1, [r0]
	b _0800B6EA
	.pool
_0800B6D4:
	bl sub_800B790
	ldr r1, =gLink
	movs r0, 0x4
	strb r0, [r1, 0x1]
_0800B6DE:
	adds r0, r5, 0
	bl sub_800B7C0
	adds r0, r6, 0
	bl sub_800B8A8
_0800B6EA:
	movs r0, 0
	strb r0, [r4]
	ldr r1, =gLink
	ldrb r2, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _0800B702
	movs r0, 0x20
	orrs r2, r0
_0800B702:
	ldrb r0, [r1, 0xC]
	lsls r3, r0, 8
	ldrb r0, [r1, 0xF]
	lsls r4, r0, 9
	ldrb r0, [r1, 0x10]
	lsls r5, r0, 12
	ldrb r0, [r1, 0x11]
	lsls r6, r0, 13
	ldrb r0, [r1, 0x12]
	lsls r7, r0, 14
	ldrb r0, [r1, 0x1]
	cmp r0, 0x4
	bne _0800B728
	movs r0, 0x40
	orrs r0, r3
	orrs r0, r2
	b _0800B72C
	.pool
_0800B728:
	adds r0, r2, 0
	orrs r0, r3
_0800B72C:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	adds r2, r0, 0
	ldrb r3, [r1, 0x13]
	cmp r3, 0x1
	bne _0800B742
	movs r0, 0x80
	lsls r0, 9
	orrs r2, r0
_0800B742:
	ldrb r0, [r1, 0x2]
	cmp r0, 0x3
	bls _0800B74E
	movs r0, 0x80
	lsls r0, 10
	orrs r2, r0
_0800B74E:
	adds r1, r2, 0
	cmp r3, 0x2
	bne _0800B75A
	movs r0, 0x80
	lsls r0, 11
	orrs r1, r0
_0800B75A:
	adds r0, r1, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800B638

	thumb_func_start sub_800B764
sub_800B764: @ 800B764
	push {lr}
	ldr r0, =0x04000128
	ldr r1, [r0]
	movs r0, 0xC
	ands r1, r0
	ldr r2, =gLink
	cmp r1, 0x8
	bne _0800B788
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0800B788
	strb r1, [r2]
	b _0800B78C
	.pool
_0800B788:
	movs r0, 0
	strb r0, [r2]
_0800B78C:
	pop {r0}
	bx r0
	thumb_func_end sub_800B764

	thumb_func_start sub_800B790
sub_800B790: @ 800B790
	push {lr}
	ldr r0, =gLink
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800B7AE
	ldr r1, =0x0400010c
	ldr r2, =0x0000ff3b
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x41
	strh r0, [r1]
	movs r0, 0x40
	bl EnableInterrupts
_0800B7AE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B790

	thumb_func_start sub_800B7C0
sub_800B7C0: @ 800B7C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r3, r0, 0
	ldr r2, =gUnknown_03004134
	ldr r1, =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gLink
	ldr r4, =0x00000339
	adds r0, r1, r4
	ldrb r4, [r0]
	adds r6, r1, 0
	cmp r4, 0x31
	bhi _0800B850
	movs r1, 0xCE
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800B7FE
	subs r0, 0x32
	lsls r0, 24
	lsrs r0, 24
_0800B7FE:
	movs r2, 0
	ldr r4, =gUnknown_03000D6E
	mov r9, r4
	ldr r1, =gLastSendQueueCount
	mov r10, r1
	lsls r5, r0, 1
	movs r0, 0x18
	adds r0, r6
	mov r8, r0
	mov r12, r2
	movs r7, 0x64
_0800B814:
	ldrh r0, [r4]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r2, 0
	muls r0, r7
	adds r0, r5, r0
	add r0, r8
	strh r1, [r0]
	mov r1, r12
	strh r1, [r3]
	adds r3, 0x2
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B814
	b _0800B85C
	.pool
_0800B850:
	movs r0, 0x1
	strb r0, [r6, 0x12]
	ldr r2, =gUnknown_03000D6E
	mov r9, r2
	ldr r4, =gLastSendQueueCount
	mov r10, r4
_0800B85C:
	mov r1, r9
	ldrh r0, [r1]
	cmp r0, 0
	beq _0800B874
	ldr r2, =0x00000339
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r1, 0x1
	movs r2, 0
	strb r1, [r0]
	mov r4, r9
	strh r2, [r4]
_0800B874:
	ldr r1, =0x04000208
	ldr r2, =gUnknown_03004134
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r4, =0x00000339
	adds r0, r6, r4
	ldrb r0, [r0]
	mov r1, r10
	strb r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B7C0

	thumb_func_start sub_800B8A8
sub_800B8A8: @ 800B8A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	ldr r2, =gUnknown_03004134
	ldr r1, =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gLink
	ldr r3, =0x00000fbd
	adds r0, r1, r3
	ldrb r0, [r0]
	mov r12, r1
	cmp r0, 0
	bne _0800B914
	movs r3, 0
	ldrb r0, [r1, 0x3]
	cmp r3, r0
	bcs _0800B8FA
	movs r5, 0
	adds r6, r0, 0
_0800B8DA:
	movs r2, 0
	lsls r1, r3, 4
	adds r4, r3, 0x1
	add r1, r9
_0800B8E2:
	lsls r0, r2, 1
	adds r0, r1
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B8E2
	lsls r0, r4, 24
	lsrs r3, r0, 24
	cmp r3, r6
	bcc _0800B8DA
_0800B8FA:
	movs r0, 0x1
	mov r7, r12
	strb r0, [r7, 0xC]
	b _0800B990
	.pool
_0800B914:
	movs r3, 0
	mov r0, r12
	ldrb r1, [r0, 0x3]
	cmp r3, r1
	bcs _0800B96A
	ldr r0, =0x00000fbc
	add r0, r12
	ldrb r0, [r0]
	lsls r6, r0, 1
	movs r2, 0xCF
	lsls r2, 2
	add r2, r12
	mov r8, r2
	mov r10, r1
_0800B930:
	movs r2, 0
	lsls r1, r3, 4
	adds r4, r3, 0x1
	lsls r0, r3, 1
	mov r7, r9
	adds r5, r1, r7
	adds r0, r3
	lsls r0, 3
	adds r0, r3
	lsls r3, r0, 5
_0800B944:
	lsls r1, r2, 1
	adds r1, r5
	movs r7, 0x64
	adds r0, r2, 0
	muls r0, r7
	adds r0, r6, r0
	adds r0, r3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0800B944
	lsls r0, r4, 24
	lsrs r3, r0, 24
	cmp r3, r10
	bcc _0800B930
_0800B96A:
	mov r2, r12
	ldr r0, =0x00000fbd
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, 0x1
	movs r3, 0
	strb r0, [r1]
	ldr r1, =0x00000fbc
	adds r2, r1
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800B98C
	strb r3, [r2]
_0800B98C:
	mov r2, r12
	strb r3, [r2, 0xC]
_0800B990:
	ldr r1, =0x04000208
	ldr r3, =gUnknown_03004134
	ldrh r0, [r3]
	strh r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B8A8

	thumb_func_start sub_800B9B8
sub_800B9B8: @ 800B9B8
	push {r4,lr}
	ldr r3, =gLink
	ldrb r4, [r3]
	cmp r4, 0
	beq _0800B9F4
	ldrb r0, [r3, 0x1]
	cmp r0, 0x2
	beq _0800B9EE
	cmp r0, 0x4
	bne _0800BA1E
	movs r0, 0xD
	ldrsb r0, [r3, r0]
	cmp r0, 0x8
	bgt _0800B9E4
	ldrb r0, [r3, 0x10]
	cmp r0, 0x1
	beq _0800B9EE
	movs r0, 0x1
	strb r0, [r3, 0x13]
	b _0800BA1E
	.pool
_0800B9E4:
	ldrb r0, [r3, 0x13]
	cmp r0, 0x1
	beq _0800BA1E
	movs r0, 0
	strb r0, [r3, 0xD]
_0800B9EE:
	bl sub_800BAC0
	b _0800BA1E
_0800B9F4:
	ldrb r2, [r3, 0x1]
	cmp r2, 0x4
	beq _0800B9FE
	cmp r2, 0x2
	bne _0800BA1E
_0800B9FE:
	ldr r1, =gUnknown_03000D6C
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	bls _0800BA1E
	cmp r2, 0x4
	bne _0800BA16
	movs r0, 0x2
	strb r0, [r3, 0x13]
_0800BA16:
	cmp r2, 0x2
	bne _0800BA1E
	strb r4, [r3, 0x3]
	strb r4, [r3, 0xF]
_0800BA1E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800B9B8

	thumb_func_start Timer3Intr
Timer3Intr: @ 800BA28
	push {lr}
	bl sub_800BD98
	bl sub_800BAC0
	pop {r0}
	bx r0
	thumb_func_end Timer3Intr

	thumb_func_start sub_800BA38
sub_800BA38: @ 800BA38
	push {r4,lr}
	ldr r4, =gLink
	ldr r0, =0x04000128
	ldr r1, [r0]
	lsls r0, r1, 26
	lsrs r0, 30
	strb r0, [r4, 0x2]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _0800BA6C
	cmp r0, 0x4
	bne _0800BA8A
	lsls r0, r1, 25
	lsrs r0, 31
	strb r0, [r4, 0x10]
	bl sub_800BBCC
	bl sub_800BCE4
	bl sub_800BDCC
	b _0800BA8A
	.pool
_0800BA6C:
	bl sub_800BAD0
	lsls r0, 24
	cmp r0, 0
	beq _0800BA8A
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800BA86
	movs r0, 0x3
	strb r0, [r4, 0x1]
	movs r0, 0x8
	strb r0, [r4, 0xD]
	b _0800BA8A
_0800BA86:
	movs r0, 0x4
	strb r0, [r4, 0x1]
_0800BA8A:
	ldr r3, =gLink
	ldrb r0, [r3, 0xD]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r3, 0xD]
	ldr r1, =gUnknown_03000D6C
	strb r2, [r1]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x8
	bne _0800BAAA
	ldr r0, =gLastRecvQueueCount
	ldr r2, =0x00000fbd
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
_0800BAAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BA38

	thumb_func_start sub_800BAC0
sub_800BAC0: @ 800BAC0
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_800BAC0

	thumb_func_start sub_800BAD0
sub_800BAD0: @ 800BAD0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r6, =0x0000ffff
	ldr r0, =gLink
	ldrb r1, [r0, 0xE]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _0800BAFC
	ldr r1, =0x0400012a
	ldr r2, =0x00008fff
	b _0800BB00
	.pool
_0800BAFC:
	ldr r1, =0x0400012a
	ldr r2, =0x0000b9a0
_0800BB00:
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, =gLink+0x4
	ldr r3, =0x04000120
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
	movs r1, 0
	str r0, [r3]
	str r1, [r3, 0x4]
	strb r0, [r2, 0xA]
	movs r4, 0
	ldr r0, =gUnknown_03000D73
	mov r9, r0
	mov r8, r2
	ldr r2, =0x00008fff
	ldr r1, =0x0000ffff
	mov r12, r1
_0800BB28:
	lsls r0, r4, 1
	add r0, r8
	ldrh r3, [r0]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	ldr r1, =0x0000b9a0
	cmp r0, r1
	beq _0800BB40
	adds r0, r3, 0
	cmp r0, r2
	bne _0800BB70
_0800BB40:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r3, 0
	cmp r6, r0
	bls _0800BB78
	cmp r0, 0
	beq _0800BB78
	adds r6, r3, 0
	b _0800BB78
	.pool
_0800BB70:
	cmp r0, r12
	beq _0800BB82
	movs r5, 0
	b _0800BB82
_0800BB78:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800BB28
_0800BB82:
	strb r5, [r7, 0x3]
	adds r0, r5, 0
	cmp r0, 0x1
	bls _0800BBB2
	mov r2, r9
	ldrb r2, [r2]
	cmp r0, r2
	bne _0800BBA4
	ldrh r1, [r7, 0x4]
	ldr r0, =0x00008fff
	cmp r1, r0
	bne _0800BBA4
	movs r0, 0x1
	b _0800BBBE
	.pool
_0800BBA4:
	ldrb r0, [r7, 0x3]
	cmp r0, 0x1
	bls _0800BBB2
	movs r0, 0x3
	ands r6, r0
	adds r0, r6, 0x1
	b _0800BBB4
_0800BBB2:
	movs r0, 0
_0800BBB4:
	strb r0, [r7, 0xF]
	ldrb r0, [r7, 0x3]
	mov r1, r9
	strb r0, [r1]
	movs r0, 0
_0800BBBE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800BAD0

	thumb_func_start sub_800BBCC
sub_800BBCC: @ 800BBCC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gLink
	ldrb r1, [r0, 0x16]
	adds r6, r0, 0
	cmp r1, 0
	bne _0800BC30
	movs r4, 0
	ldr r7, =gUnknown_03000D72
	ldrb r0, [r6, 0x3]
	cmp r4, r0
	bcs _0800BC1A
	adds r5, r6, 0
	ldrh r1, [r6, 0x14]
	adds r3, r7, 0
	adds r2, r6, 0
_0800BBFA:
	lsls r0, r4, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	beq _0800BC0E
	ldrb r0, [r3]
	cmp r0, 0
	beq _0800BC0E
	movs r0, 0x1
	strb r0, [r5, 0x11]
_0800BC0E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r2, 0x3]
	cmp r4, r0
	bcc _0800BBFA
_0800BC1A:
	movs r0, 0
	strh r0, [r6, 0x14]
	movs r0, 0x1
	strb r0, [r7]
	b _0800BCD0
	.pool
_0800BC30:
	ldr r2, =0x00000fbc
	adds r1, r6, r2
	adds r2, 0x1
	adds r0, r6, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r0, r2, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800BC4C
	subs r0, 0x32
	lsls r0, 24
	lsrs r0, 24
_0800BC4C:
	cmp r2, 0x31
	bhi _0800BCA8
	movs r4, 0
	ldrb r1, [r6, 0x3]
	cmp r4, r1
	bcs _0800BCAC
	adds r5, r6, 0
	ldr r7, =gUnknown_03000D70
	lsls r0, 1
	mov r12, r0
	movs r2, 0xCF
	lsls r2, 2
	adds r2, r6
	mov r8, r2
_0800BC68:
	lsls r1, r4, 1
	mov r2, sp
	adds r0, r2, r1
	ldrh r3, [r0]
	ldrh r2, [r5, 0x14]
	adds r0, r3, r2
	strh r0, [r5, 0x14]
	ldrh r0, [r7]
	orrs r0, r3
	strh r0, [r7]
	ldrb r2, [r5, 0x17]
	movs r0, 0x64
	muls r0, r2
	add r0, r12
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 5
	adds r0, r1
	add r0, r8
	strh r3, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x3]
	cmp r4, r0
	bcc _0800BC68
	b _0800BCAC
	.pool
_0800BCA8:
	movs r0, 0x2
	strb r0, [r6, 0x12]
_0800BCAC:
	ldrb r0, [r6, 0x17]
	adds r0, 0x1
	strb r0, [r6, 0x17]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bne _0800BCD0
	ldr r2, =gUnknown_03000D70
	ldrh r0, [r2]
	cmp r0, 0
	beq _0800BCD0
	ldr r1, =0x00000fbd
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0
	strh r0, [r2]
_0800BCD0:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BBCC

	thumb_func_start sub_800BCE4
sub_800BCE4: @ 800BCE4
	push {r4,lr}
	ldr r0, =gLink
	ldrb r1, [r0, 0x16]
	adds r4, r0, 0
	cmp r1, 0x8
	bne _0800BD36
	ldr r1, =0x0400012a
	ldrh r0, [r4, 0x14]
	strh r0, [r1]
	ldr r1, =gUnknown_03000D6D
	ldrb r2, [r1]
	cmp r2, 0
	bne _0800BD30
	ldr r0, =0x00000339
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	movs r0, 0xCE
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x31
	bls _0800BD8C
	strb r2, [r1]
	b _0800BD8C
	.pool
_0800BD30:
	movs r0, 0
	strb r0, [r1]
	b _0800BD8C
_0800BD36:
	ldr r1, =gUnknown_03000D6D
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800BD52
	ldr r2, =0x00000339
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800BD4C
	movs r0, 0x1
	strb r0, [r1]
_0800BD4C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800BD68
_0800BD52:
	ldr r1, =0x0400012a
	movs r0, 0
	strh r0, [r1]
	b _0800BD86
	.pool
_0800BD68:
	ldr r3, =0x0400012a
	movs r1, 0xCE
	lsls r1, 2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, 1
	ldrb r2, [r4, 0x16]
	movs r1, 0x64
	muls r1, r2
	adds r0, r1
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
_0800BD86:
	ldrb r0, [r4, 0x16]
	adds r0, 0x1
	strb r0, [r4, 0x16]
_0800BD8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BCE4

	thumb_func_start sub_800BD98
sub_800BD98: @ 800BD98
	push {lr}
	ldr r0, =gLink
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800BDB4
	ldr r2, =0x0400010e
	ldrh r1, [r2]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0400010c
	ldr r2, =0x0000ff3b
	adds r0, r2, 0
	strh r0, [r1]
_0800BDB4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BD98

	thumb_func_start sub_800BDCC
sub_800BDCC: @ 800BDCC
	push {lr}
	ldr r1, =gLink
	ldrb r0, [r1, 0x17]
	cmp r0, 0x8
	bne _0800BDE4
	movs r0, 0
	strb r0, [r1, 0x16]
	strb r0, [r1, 0x17]
	b _0800BDF4
	.pool
_0800BDE4:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800BDF4
	ldr r0, =0x0400010e
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
_0800BDF4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BDCC

	thumb_func_start sub_800BDFC
sub_800BDFC: @ 800BDFC
	push {r4-r6,lr}
	ldr r1, =gLink
	ldr r2, =0x00000339
	adds r0, r1, r2
	movs r2, 0
	strb r2, [r0]
	movs r3, 0xCE
	lsls r3, 2
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, 0
	movs r6, 0x64
	adds r5, r1, 0
	adds r5, 0x18
	ldr r4, =0x0000efff
_0800BE1A:
	movs r2, 0
	adds r1, r0, 0x1
	adds r3, r0, 0
	muls r3, r6
_0800BE22:
	lsls r0, r2, 1
	adds r0, r3
	adds r0, r5
	strh r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x31
	bls _0800BE22
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x7
	bls _0800BE1A
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BDFC

	thumb_func_start sub_800BE50
sub_800BE50: @ 800BE50
	push {r4-r7,lr}
	ldr r1, =gLink
	ldr r2, =0x00000fbd
	adds r0, r1, r2
	movs r2, 0
	strb r2, [r0]
	ldr r3, =0x00000fbc
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, 0x64
	mov r12, r0
	movs r3, 0xCF
	lsls r3, 2
	adds r7, r1, r3
	ldr r6, =0x0000efff
_0800BE6E:
	movs r3, 0
	lsls r0, r2, 1
	adds r5, r2, 0x1
	adds r0, r2
	lsls r0, 3
	adds r0, r2
	lsls r4, r0, 5
_0800BE7C:
	movs r2, 0
	adds r1, r3, 0x1
	mov r0, r12
	muls r0, r3
	adds r3, r0, 0
_0800BE86:
	lsls r0, r2, 1
	adds r0, r3
	adds r0, r4
	adds r0, r7
	strh r6, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x31
	bls _0800BE86
	lsls r0, r1, 24
	lsrs r3, r0, 24
	cmp r3, 0x7
	bls _0800BE7C
	lsls r0, r5, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800BE6E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BE50

// RFU; bss indicates that no file boundary exists here

	thumb_func_start sub_800BEC0
sub_800BEC0: @ 800BEC0
	push {r4,lr}
	bl rfu_REQBN_softReset_and_checkID
	adds r4, r0, 0
	ldr r0, =0x00008001
	cmp r4, r0
	bne _0800BED4
	ldr r1, =gUnknown_03004140
	movs r0, 0x1
	strb r0, [r1, 0x8]
_0800BED4:
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0, 0x4]
	adds r1, r0, 0
	cmp r2, 0x17
	beq _0800BEE8
	cmp r2, 0x1
	beq _0800BEE8
	movs r0, 0
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x4]
_0800BEE8:
	movs r0, 0
	strb r0, [r1, 0x7]
	strb r0, [r1, 0xD]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	movs r0, 0xFF
	strb r0, [r1, 0x6]
	bl sub_800D610
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800BEC0

	thumb_func_start rfu_REQ_sendData_wrapper
rfu_REQ_sendData_wrapper: @ 800BF0C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800BF34
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x2]
	movs r2, 0
	cmp r0, 0x1
	bne _0800BF3C
	movs r2, 0x1
	b _0800BF3C
	.pool
_0800BF34:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x3]
	movs r1, 0
	strb r1, [r0, 0x3]
_0800BF3C:
	adds r0, r2, 0
	bl rfu_REQ_sendData
	pop {r0}
	bx r0
	.pool
	thumb_func_end rfu_REQ_sendData_wrapper

	thumb_func_start sub_800BF4C
sub_800BF4C: @ 800BF4C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	beq _0800BF94
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r4, =gUnknown_03004140
	ldr r2, =0x01000024
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	str r5, [r4, 0x40]
	str r6, [r4, 0x44]
	ldr r0, =sub_800CEB0
	bl rfu_setMSCCallback
	ldr r0, =sub_800C7B4
	bl rfu_setREQCallback
	movs r0, 0
	b _0800BF96
	.pool
_0800BF94:
	movs r0, 0x4
_0800BF96:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800BF4C

	thumb_func_start sub_800BFA0
sub_800BFA0: @ 800BFA0
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r4, =gUnknown_03004140
	ldr r2, =0x01000020
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BFA0

	thumb_func_start sub_800BFCC
sub_800BFCC: @ 800BFCC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_800C000
	ldr r1, =gUnknown_03004140
	movs r2, 0x1
	strb r2, [r1, 0x4]
	movs r0, 0x2
	strb r0, [r1, 0x5]
	str r4, [r1, 0x3C]
	ldrb r0, [r4, 0x11]
	strb r0, [r1, 0x9]
	ldrh r0, [r4, 0x12]
	strh r0, [r1, 0x32]
	ldrh r0, [r4, 0x14]
	strh r0, [r1, 0x18]
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _0800BFF4
	strb r2, [r1, 0xB]
_0800BFF4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800BFCC

	thumb_func_start sub_800C000
sub_800C000: @ 800C000
	push {r4,r5,lr}
	ldr r2, =gUnknown_03004140
	movs r0, 0
	strb r0, [r2, 0x5]
	strb r0, [r2, 0x4]
	movs r1, 0xFF
	strb r1, [r2, 0x6]
	strb r0, [r2, 0x7]
	strb r0, [r2, 0x10]
	strb r0, [r2, 0xC]
	adds r1, r2, 0
	adds r1, 0x24
	strb r0, [r1]
	adds r1, 0xC
	strb r0, [r1]
	movs r3, 0
	adds r5, r2, 0
	adds r5, 0x28
	movs r4, 0
	adds r2, 0x34
_0800C028:
	lsls r1, r3, 1
	adds r0, r1, r5
	strh r4, [r0]
	adds r1, r2
	strh r4, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800C028
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800C000

	thumb_func_start sub_800C048
sub_800C048: @ 800C048
	ldr r1, =gUnknown_03004140
	movs r0, 0x15
	strb r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_800C048

	thumb_func_start sub_800C054
sub_800C054: @ 800C054
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r3, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0800C090
	cmp r0, 0x8
	bne _0800C07A
	cmp r5, 0x1
	beq _0800C090
_0800C07A:
	movs r0, 0x1
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x1
	b _0800C122
	.pool
_0800C090:
	bl rfu_getMasterSlave
	lsls r0, 24
	cmp r0, 0
	bne _0800C0B0
	ldr r1, =gUnknown_03004140
	movs r0, 0x2
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x2
	b _0800C122
	.pool
_0800C0B0:
	movs r2, 0
	ldrh r0, [r6]
	ldr r4, =0x0000ffff
	adds r1, r6, 0x2
	ldr r3, =gUnknown_03004140
	cmp r0, r4
	beq _0800C0D0
_0800C0BE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bhi _0800C0D0
	ldrh r0, [r1]
	adds r1, 0x2
	cmp r0, r4
	bne _0800C0BE
_0800C0D0:
	cmp r2, 0x10
	bne _0800C0EC
	movs r0, 0x4
	strh r0, [r3, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x4
	b _0800C122
	.pool
_0800C0EC:
	cmp r5, 0x1
	bls _0800C0FA
	movs r0, 0x1
	strb r0, [r3, 0x7]
	movs r5, 0x1
	movs r7, 0
	b _0800C0FE
_0800C0FA:
	movs r0, 0
	strb r0, [r3, 0x7]
_0800C0FE:
	cmp r5, 0
	beq _0800C108
	movs r0, 0x5
	strb r0, [r3, 0x4]
	b _0800C116
_0800C108:
	movs r0, 0x9
	strb r0, [r3, 0x4]
	ldrb r0, [r3, 0xB]
	cmp r0, 0
	beq _0800C116
	movs r0, 0x2
	strb r0, [r3, 0xB]
_0800C116:
	strb r5, [r3, 0x6]
	strh r7, [r3, 0x1A]
	mov r0, r8
	strh r0, [r3, 0x26]
	str r6, [r3, 0x20]
	movs r0, 0
_0800C122:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800C054

	thumb_func_start sub_800C12C
sub_800C12C: @ 800C12C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0800C164
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0800C164
	movs r0, 0x1
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x1
	b _0800C204
	.pool
_0800C164:
	bl rfu_getMasterSlave
	lsls r0, 24
	cmp r0, 0
	bne _0800C184
	ldr r1, =gUnknown_03004140
	movs r0, 0x2
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x2
	b _0800C204
	.pool
_0800C184:
	movs r2, 0
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	ldrb r3, [r1, 0x8]
	ldr r5, =gUnknown_03004140
	adds r7, r0, 0
	cmp r2, r3
	bcs _0800C1B2
	ldrh r0, [r1, 0x14]
	cmp r0, r6
	beq _0800C1B2
	adds r4, r1, 0
	adds r1, r3, 0
_0800C19E:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r1
	bcs _0800C1B2
	lsls r0, r2, 5
	adds r0, r4, r0
	ldrh r0, [r0, 0x14]
	cmp r0, r6
	bne _0800C19E
_0800C1B2:
	ldr r0, [r7]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _0800C1BE
	cmp r2, r0
	bne _0800C1D8
_0800C1BE:
	movs r0, 0x3
	strh r0, [r5, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x3
	b _0800C204
	.pool
_0800C1D8:
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _0800C1E2
	cmp r0, 0x9
	bne _0800C1EA
_0800C1E2:
	movs r0, 0xC
	strb r0, [r5, 0x4]
	movs r0, 0xD
	b _0800C1F0
_0800C1EA:
	movs r0, 0xB
	strb r0, [r5, 0x4]
	movs r0, 0xC
_0800C1F0:
	strb r0, [r5, 0x5]
	strh r6, [r5, 0x1E]
	mov r0, r8
	strh r0, [r5, 0x1A]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0800C202
	movs r0, 0x7
	strb r0, [r5, 0x7]
_0800C202:
	movs r0, 0
_0800C204:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800C12C

	thumb_func_start sub_800C210
sub_800C210: @ 800C210
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r6, =gUnknown_03004140
	adds r3, r6, 0
	adds r3, 0x30
	ldrb r2, [r3]
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _0800C26C
	adds r0, r2, 0
	bics r0, r1
	strb r0, [r3]
	movs r4, 0
	ldr r7, =gUnknown_03007890
	movs r5, 0x1
	adds r3, 0x4
	movs r2, 0
_0800C236:
	adds r0, r1, 0
	asrs r0, r4
	ands r0, r5
	cmp r0, 0
	beq _0800C246
	lsls r0, r4, 1
	adds r0, r3
	strh r2, [r0]
_0800C246:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800C236
	ldr r0, [r7]
	ldrb r4, [r0, 0x3]
	ands r4, r1
	cmp r4, 0
	beq _0800C260
	adds r0, r4, 0
	bl sub_800D334
_0800C260:
	ldr r0, =gUnknown_03004140
	strh r4, [r0, 0x14]
	movs r0, 0x33
	adds r1, r4, 0
	bl sub_800D30C
_0800C26C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800C210

	thumb_func_start sub_800C27C
sub_800C27C: @ 800C27C
	push {r4,r5,lr}
	lsls r0, 24
	movs r2, 0
	ldr r1, =gUnknown_03004140
	strb r2, [r1, 0x7]
	adds r5, r1, 0
	cmp r0, 0
	beq _0800C29C
	bl sub_800C000
	movs r0, 0x17
	strb r0, [r5, 0x4]
	b _0800C366
	.pool
_0800C29C:
	ldrb r0, [r5, 0x4]
	subs r0, 0x5
	cmp r0, 0xD
	bhi _0800C352
	lsls r0, 2
	ldr r1, =_0800C2B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800C2B4:
	.4byte _0800C2EC
	.4byte _0800C2F8
	.4byte _0800C2F8
	.4byte _0800C358
	.4byte _0800C302
	.4byte _0800C30C
	.4byte _0800C30C
	.4byte _0800C316
	.4byte _0800C320
	.4byte _0800C320
	.4byte _0800C358
	.4byte _0800C326
	.4byte _0800C34C
	.4byte _0800C34C
_0800C2EC:
	movs r1, 0
	movs r0, 0x8
	strb r0, [r5, 0x4]
	strb r1, [r5, 0x5]
	movs r2, 0x13
	b _0800C358
_0800C2F8:
	movs r0, 0x7
	strb r0, [r5, 0x4]
	movs r0, 0x8
	strb r0, [r5, 0x5]
	b _0800C358
_0800C302:
	movs r0, 0
	strb r0, [r5, 0x5]
	strb r0, [r5, 0x4]
	movs r2, 0x21
	b _0800C358
_0800C30C:
	movs r1, 0
	movs r0, 0xB
	strb r0, [r5, 0x4]
	strb r1, [r5, 0x5]
	b _0800C358
_0800C316:
	movs r0, 0
	strb r0, [r5, 0x5]
	strb r0, [r5, 0x4]
	movs r2, 0x23
	b _0800C358
_0800C320:
	movs r0, 0xE
	strb r0, [r5, 0x4]
	b _0800C358
_0800C326:
	ldrb r0, [r5, 0x11]
	strb r0, [r5, 0x4]
	ldrb r0, [r5, 0x12]
	strb r0, [r5, 0x5]
	ldr r4, =gUnknown_03007890
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	bl sub_800D334
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	strh r0, [r5, 0x14]
	movs r0, 0x33
	movs r1, 0x1
	bl sub_800D30C
	b _0800C366
	.pool
_0800C34C:
	movs r0, 0x12
	strb r0, [r5, 0x4]
	b _0800C358
_0800C352:
	strb r2, [r5, 0x5]
	strb r2, [r5, 0x4]
	movs r2, 0x43
_0800C358:
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	bne _0800C366
	adds r0, r2, 0
	movs r1, 0
	bl sub_800D30C
_0800C366:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800C27C

	thumb_func_start sub_800C36C
sub_800C36C: @ 800C36C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	mov r8, r1
	mov r5, sp
	adds r5, 0x1
	mov r4, sp
	adds r4, 0x2
	mov r1, sp
	adds r2, r5, 0
	adds r3, r4, 0
	bl rfu_REQBN_watchLink
	mov r0, sp
	ldrb r0, [r0]
	adds r7, r4, 0
	cmp r0, 0
	beq _0800C43E
	ldr r1, =gUnknown_03004140
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, 0x14]
	ldrb r0, [r5]
	strh r0, [r1, 0x16]
	ldrb r0, [r1, 0x9]
	adds r6, r1, 0
	cmp r0, 0
	beq _0800C426
	movs r0, 0x1
	strb r0, [r6, 0xA]
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0800C3C2
	ldrb r0, [r5]
	cmp r0, 0
	bne _0800C3C2
	movs r0, 0x4
	strb r0, [r6, 0xA]
_0800C3C2:
	ldrb r0, [r6, 0xA]
	cmp r0, 0x1
	bne _0800C40C
	movs r2, 0
	mov r4, sp
	movs r5, 0x1
	mov r12, r6
	mov r3, r12
	adds r3, 0x30
	movs r6, 0x34
	add r6, r12
	mov r9, r6
_0800C3DA:
	ldrb r0, [r4]
	asrs r0, r2
	ands r0, r5
	cmp r0, 0
	beq _0800C3F8
	adds r0, r5, 0
	lsls r0, r2
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	lsls r0, r2, 1
	add r0, r9
	mov r6, r12
	ldrh r1, [r6, 0x32]
	strh r1, [r0]
_0800C3F8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800C3DA
	movs r0, 0x31
	b _0800C41E
	.pool
_0800C40C:
	movs r0, 0
	strb r0, [r6, 0xA]
	mov r0, sp
	ldrb r0, [r0]
	bl sub_800D334
	movs r0, 0x1
	mov r8, r0
	movs r0, 0x33
_0800C41E:
	movs r1, 0x1
	bl sub_800D30C
	b _0800C43A
_0800C426:
	mov r0, sp
	ldrb r0, [r0]
	bl sub_800D334
	movs r1, 0x1
	mov r8, r1
	movs r0, 0x30
	movs r1, 0x2
	bl sub_800D30C
_0800C43A:
	bl sub_800D610
_0800C43E:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800C518
	ldrb r0, [r7]
	cmp r0, 0
	beq _0800C49C
	movs r2, 0
	ldr r6, =gUnknown_03004140
	movs r3, 0x1
	adds r4, r6, 0
	adds r4, 0x34
	adds r6, 0x30
	adds r5, r7, 0
_0800C45C:
	ldrb r0, [r6]
	asrs r0, r2
	ands r0, r3
	cmp r0, 0
	beq _0800C478
	ldrb r0, [r5]
	asrs r0, r2
	ands r0, r3
	cmp r0, 0
	beq _0800C478
	lsls r0, r2, 1
	adds r0, r4
	movs r1, 0
	strh r1, [r0]
_0800C478:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800C45C
	ldr r3, =gUnknown_03004140
	adds r2, r3, 0
	adds r2, 0x30
	ldrb r1, [r7]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r7]
	strh r0, [r3, 0x14]
	movs r0, 0x32
	movs r1, 0x1
	bl sub_800D30C
_0800C49C:
	ldr r0, =gUnknown_03004140
	adds r3, r0, 0
	adds r3, 0x30
	ldrb r1, [r3]
	adds r6, r0, 0
	cmp r1, 0
	beq _0800C514
	movs r4, 0
	movs r2, 0
	movs r5, 0x1
_0800C4B0:
	ldrb r0, [r3]
	asrs r0, r2
	ands r0, r5
	cmp r0, 0
	beq _0800C4E2
	lsls r1, r2, 1
	adds r0, r6, 0
	adds r0, 0x34
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _0800C4E2
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _0800C4E2
	adds r0, r5, 0
	lsls r0, r2
	ldrb r1, [r3]
	bics r1, r0
	strb r1, [r3]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0800C4E2:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _0800C4B0
	cmp r4, 0
	beq _0800C506
	adds r0, r4, 0
	bl sub_800D334
	movs r6, 0x1
	mov r8, r6
	ldr r0, =gUnknown_03004140
	strh r4, [r0, 0x14]
	movs r0, 0x33
	movs r1, 0x1
	bl sub_800D30C
_0800C506:
	ldr r0, =gUnknown_03004140
	adds r1, r0, 0
	adds r1, 0x30
	ldrb r1, [r1]
	adds r6, r0, 0
	cmp r1, 0
	bne _0800C518
_0800C514:
	movs r0, 0
	strb r0, [r6, 0xA]
_0800C518:
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800C36C

	thumb_func_start rfu_syncVBlank_
rfu_syncVBlank_: @ 800C530
	push {lr}
	bl rfu_syncVBlank
	lsls r0, 16
	cmp r0, 0
	beq _0800C548
	movs r0, 0xF1
	movs r1, 0
	bl sub_800D30C
	bl sub_800D610
_0800C548:
	pop {r0}
	bx r0
	thumb_func_end rfu_syncVBlank_

	thumb_func_start sub_800C54C
sub_800C54C: @ 800C54C
	push {r4,lr}
	adds r3, r0, 0
	ldr r1, =gUnknown_03004140
	ldr r2, [r1, 0x40]
	cmp r2, 0
	bne _0800C568
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0800C568
	strb r2, [r1, 0x4]
	b _0800C736
	.pool
_0800C568:
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0800C576
	adds r0, r3, 0
	bl sub_800C744
_0800C576:
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _0800C580
	b _0800C700
_0800C580:
	bl rfu_waitREQComplete
	movs r0, 0x1
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0x4]
	subs r0, 0x1
	cmp r0, 0x16
	bls _0800C592
	b _0800C6F6
_0800C592:
	lsls r0, 2
	ldr r1, =_0800C5A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800C5A4:
	.4byte _0800C624
	.4byte _0800C65C
	.4byte _0800C662
	.4byte _0800C678
	.4byte _0800C690
	.4byte _0800C696
	.4byte _0800C69C
	.4byte _0800C6F6
	.4byte _0800C6A2
	.4byte _0800C6A8
	.4byte _0800C6AE
	.4byte _0800C6B4
	.4byte _0800C6C4
	.4byte _0800C6CA
	.4byte _0800C6F6
	.4byte _0800C6D0
	.4byte _0800C6E0
	.4byte _0800C6E6
	.4byte _0800C6EC
	.4byte _0800C6F6
	.4byte _0800C6F2
	.4byte _0800C6F6
	.4byte _0800C600
_0800C600:
	bl sub_800BEC0
	ldr r1, =0x00008001
	movs r2, 0xFF
	cmp r0, r1
	bne _0800C60E
	movs r2, 0x44
_0800C60E:
	ldr r1, =gUnknown_03004140
	movs r0, 0
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x4]
	adds r0, r2, 0
	b _0800C64E
	.pool
_0800C624:
	bl sub_800BEC0
	ldr r1, =0x00008001
	cmp r0, r1
	bne _0800C644
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x5]
	strb r1, [r0, 0x4]
	movs r1, 0x3
	strb r1, [r0, 0x5]
	b _0800C6F6
	.pool
_0800C644:
	ldr r1, =gUnknown_03004140
	movs r0, 0
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x4]
	movs r0, 0xFF
_0800C64E:
	movs r1, 0
	bl sub_800D30C
	b _0800C6F6
	.pool
_0800C65C:
	bl rfu_REQ_reset
	b _0800C6F6
_0800C662:
	ldr r0, =gUnknown_03004140
	ldr r2, [r0, 0x3C]
	ldrh r0, [r2, 0x2]
	ldrb r1, [r2]
	ldrb r2, [r2, 0x1]
	bl rfu_REQ_configSystem
	b _0800C6F6
	.pool
_0800C678:
	ldr r0, =gUnknown_03004140
	ldr r3, [r0, 0x3C]
	ldrb r0, [r3, 0x4]
	ldrh r1, [r3, 0x6]
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0xC]
	bl rfu_REQ_configGameData
	b _0800C6F6
	.pool
_0800C690:
	bl rfu_REQ_startSearchChild
	b _0800C6F6
_0800C696:
	bl rfu_REQ_pollSearchChild
	b _0800C6F6
_0800C69C:
	bl rfu_REQ_endSearchChild
	b _0800C6F6
_0800C6A2:
	bl rfu_REQ_startSearchParent
	b _0800C6F6
_0800C6A8:
	bl rfu_REQ_pollSearchParent
	b _0800C6F6
_0800C6AE:
	bl rfu_REQ_endSearchParent
	b _0800C6F6
_0800C6B4:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x1E]
	bl rfu_REQ_startConnectParent
	b _0800C6F6
	.pool
_0800C6C4:
	bl rfu_REQ_pollConnectParent
	b _0800C6F6
_0800C6CA:
	bl rfu_REQ_endConnectParent
	b _0800C6F6
_0800C6D0:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	bl rfu_REQ_CHILD_startConnectRecovery
	b _0800C6F6
	.pool
_0800C6E0:
	bl rfu_REQ_CHILD_pollConnectRecovery
	b _0800C6F6
_0800C6E6:
	bl rfu_REQ_CHILD_endConnectRecovery
	b _0800C6F6
_0800C6EC:
	bl rfu_REQ_changeMasterSlave
	b _0800C6F6
_0800C6F2:
	bl rfu_REQ_stopMode
_0800C6F6:
	bl rfu_waitREQComplete
	ldr r1, =gUnknown_03004140
	movs r0, 0
	strb r0, [r1, 0xE]
_0800C700:
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x4]
	subs r0, 0x12
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0800C710
	b _0800C576
_0800C710:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800C726
	movs r0, 0
	bl sub_800C36C
	lsls r0, 24
	cmp r0, 0
	bne _0800C736
_0800C726:
	bl sub_800CF34
	bl sub_800D158
	bl sub_800D268
	bl sub_800D434
_0800C736:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800C54C

	thumb_func_start sub_800C744
sub_800C744: @ 800C744
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x7]
	adds r4, r0, 0
	cmp r1, 0x5
	bne _0800C76E
	movs r2, 0x1
	strb r2, [r4, 0x6]
	strb r1, [r4, 0x4]
	ldrh r0, [r4, 0x1C]
	strh r0, [r4, 0x1A]
	lsls r0, 16
	cmp r0, 0
	beq _0800C76C
	movs r0, 0x6
	strb r0, [r4, 0x7]
	b _0800C76E
	.pool
_0800C76C:
	strb r2, [r4, 0x7]
_0800C76E:
	ldrb r0, [r4, 0x7]
	cmp r0, 0x1
	bne _0800C798
	strb r0, [r4, 0x6]
	movs r0, 0x5
	strb r0, [r4, 0x4]
	adds r0, r3, 0
	movs r1, 0x8C
	bl __umodsi3
	strh r0, [r4, 0x1A]
	movs r1, 0x8C
	subs r1, r0
	strh r1, [r4, 0x1C]
	lsls r0, 16
	cmp r0, 0
	beq _0800C794
	movs r0, 0x2
	b _0800C796
_0800C794:
	movs r0, 0x3
_0800C796:
	strb r0, [r4, 0x7]
_0800C798:
	ldrb r0, [r4, 0x7]
	cmp r0, 0x3
	bne _0800C7AE
	movs r0, 0
	strb r0, [r4, 0x6]
	movs r0, 0x28
	strh r0, [r4, 0x1A]
	movs r0, 0x4
	strb r0, [r4, 0x7]
	movs r0, 0x9
	strb r0, [r4, 0x4]
_0800C7AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800C744

	thumb_func_start sub_800C7B4
sub_800C7B4: @ 800C7B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0xE]
	adds r7, r0, 0
	cmp r1, 0
	bne _0800C7D2
	b _0800CC98
_0800C7D2:
	movs r0, 0
	strb r0, [r7, 0xE]
	mov r0, r8
	subs r0, 0x10
	cmp r0, 0x2D
	bls _0800C7E0
	b _0800CC8A
_0800C7E0:
	lsls r0, 2
	ldr r1, =_0800C7F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800C7F4:
	.4byte _0800C8AC
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800C8D8
	.4byte _0800C8C4
	.4byte _0800CC8A
	.4byte _0800C8EC
	.4byte _0800C8FC
	.4byte _0800C920
	.4byte _0800C940
	.4byte _0800C960
	.4byte _0800C9D0
	.4byte _0800CA02
	.4byte _0800CA18
	.4byte _0800CA60
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CBD8
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CAD0
	.4byte _0800CB1C
	.4byte _0800CB64
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC8A
	.4byte _0800CC78
_0800C8AC:
	cmp r6, 0
	beq _0800C8B2
	b _0800CC8A
_0800C8B2:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x5]
	strb r1, [r0, 0x4]
	movs r1, 0x4
	strb r1, [r0, 0x5]
	b _0800CC8A
	.pool
_0800C8C4:
	cmp r6, 0
	beq _0800C8CA
	b _0800CC8A
_0800C8CA:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x5]
	strb r1, [r0, 0x4]
	strb r6, [r0, 0x5]
	b _0800CC8A
	.pool
_0800C8D8:
	cmp r6, 0
	beq _0800C8DE
	b _0800CC8A
_0800C8DE:
	ldr r0, =gUnknown_03004140
	strb r6, [r0, 0x5]
	strb r6, [r0, 0x4]
	movs r0, 0
	b _0800CBF6
	.pool
_0800C8EC:
	cmp r6, 0
	beq _0800C8F2
	b _0800CC8A
_0800C8F2:
	ldr r1, =gUnknown_03004140
	movs r0, 0x6
	b _0800CA0C
	.pool
_0800C8FC:
	ldr r1, =gUnknown_03004140
	ldrh r0, [r1, 0x1A]
	cmp r0, 0
	bne _0800C906
	b _0800CC8A
_0800C906:
	subs r0, 0x1
	strh r0, [r1, 0x1A]
	lsls r0, 16
	cmp r0, 0
	beq _0800C912
	b _0800CC8A
_0800C912:
	movs r0, 0x7
	strb r0, [r1, 0x4]
	movs r0, 0x8
	strb r0, [r1, 0x5]
	b _0800CC8A
	.pool
_0800C920:
	cmp r6, 0
	beq _0800C926
	b _0800CC8A
_0800C926:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x5]
	strb r1, [r0, 0x4]
	strb r6, [r0, 0x5]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0800C936
	b _0800CC8A
_0800C936:
	movs r0, 0x13
	b _0800CBF6
	.pool
_0800C940:
	cmp r6, 0
	beq _0800C946
	b _0800CC8A
_0800C946:
	ldrb r0, [r7, 0xB]
	cmp r0, 0x1
	bne _0800C956
	ldrh r0, [r7, 0x1A]
	cmp r0, 0x1
	bls _0800C956
	subs r0, 0x1
	strh r0, [r7, 0x1A]
_0800C956:
	ldr r1, =gUnknown_03004140
	movs r0, 0xA
	b _0800CA0C
	.pool
_0800C960:
	cmp r6, 0
	bne _0800C9A6
	bl sub_800D294
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	ldr r4, =gUnknown_03004140
	strh r0, [r4, 0x14]
	cmp r0, 0
	beq _0800C980
	movs r0, 0x20
	movs r1, 0x1
	bl sub_800D30C
_0800C980:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0800C9A6
	ldrh r0, [r4, 0x1A]
	cmp r0, 0x1
	beq _0800C9A6
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x4
	bne _0800C9A6
	bl rfu_REQ_endSearchParent
	bl rfu_waitREQComplete
	movs r0, 0x9
	strb r0, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r4, 0xB]
_0800C9A6:
	ldr r1, =gUnknown_03004140
	ldrh r0, [r1, 0x1A]
	cmp r0, 0
	bne _0800C9B0
	b _0800CC8A
_0800C9B0:
	subs r0, 0x1
	strh r0, [r1, 0x1A]
	lsls r0, 16
	cmp r0, 0
	beq _0800C9BC
	b _0800CC8A
_0800C9BC:
	movs r0, 0xB
	strb r0, [r1, 0x4]
	movs r0, 0
	strb r0, [r1, 0x5]
	b _0800CC8A
	.pool
_0800C9D0:
	cmp r6, 0
	beq _0800C9D6
	b _0800CC8A
_0800C9D6:
	ldr r2, =gUnknown_03004140
	ldrb r0, [r2, 0x5]
	strb r0, [r2, 0x4]
	ldrb r1, [r2, 0x7]
	cmp r1, 0
	bne _0800C9F4
	lsls r0, 24
	cmp r0, 0
	beq _0800C9EA
	b _0800CC8A
_0800C9EA:
	movs r0, 0x21
	b _0800CBF6
	.pool
_0800C9F4:
	cmp r1, 0x7
	bne _0800C9FA
	b _0800CC8A
_0800C9FA:
	movs r0, 0x5
	strb r0, [r2, 0x4]
	strb r0, [r2, 0x7]
	b _0800CC8A
_0800CA02:
	cmp r6, 0
	beq _0800CA08
	b _0800CC8A
_0800CA08:
	ldr r1, =gUnknown_03004140
	movs r0, 0xD
_0800CA0C:
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x4]
	b _0800CC8A
	.pool
_0800CA18:
	cmp r6, 0
	bne _0800CA3C
	ldr r4, =gUnknown_03004150
	mov r0, sp
	adds r1, r4, 0
	bl rfu_getConnectParentStatus
	lsls r0, 16
	cmp r0, 0
	bne _0800CA3C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800CA3C
	adds r1, r4, 0
	subs r1, 0x10
	movs r0, 0xE
	strb r0, [r1, 0x4]
_0800CA3C:
	ldr r1, =gUnknown_03004140
	ldrh r0, [r1, 0x1A]
	cmp r0, 0
	bne _0800CA46
	b _0800CC8A
_0800CA46:
	subs r0, 0x1
	strh r0, [r1, 0x1A]
	lsls r0, 16
	cmp r0, 0
	beq _0800CA52
	b _0800CC8A
_0800CA52:
	movs r0, 0xE
	strb r0, [r1, 0x4]
	b _0800CC8A
	.pool
_0800CA60:
	cmp r6, 0
	beq _0800CA66
	b _0800CC8A
_0800CA66:
	ldr r4, =gUnknown_03004150
	mov r0, sp
	adds r1, r4, 0
	bl rfu_getConnectParentStatus
	lsls r0, 16
	cmp r0, 0
	beq _0800CA78
	b _0800CC8A
_0800CA78:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800CA9C
	adds r1, r4, 0
	subs r1, 0x10
	movs r0, 0x13
	strb r0, [r1, 0x4]
	movs r0, 0xF
	strb r0, [r1, 0x5]
	movs r0, 0x22
	strh r0, [r1, 0x1E]
	ldrb r0, [r1, 0x10]
	strh r0, [r1, 0x14]
	b _0800CABC
	.pool
_0800CA9C:
	adds r1, r4, 0
	subs r1, 0x10
	strb r6, [r1, 0x5]
	strb r6, [r1, 0x4]
	movs r0, 0x23
	strh r0, [r1, 0x1E]
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, 0x14]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _0800CABC
	movs r0, 0x3
	strb r0, [r1, 0x7]
	movs r0, 0x9
	strb r0, [r1, 0x4]
_0800CABC:
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0x1E]
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0
	strh r0, [r4, 0x1E]
	b _0800CC8A
	.pool
_0800CAD0:
	cmp r6, 0
	beq _0800CAD6
	b _0800CC8A
_0800CAD6:
	ldr r2, =gUnknown_03007890
	ldr r3, [r2]
	ldrb r0, [r3, 0x3]
	movs r1, 0
	strh r0, [r7, 0x14]
	movs r0, 0x11
	strb r0, [r7, 0x5]
	strb r0, [r7, 0x4]
	strb r1, [r7, 0x10]
	ldrb r0, [r3, 0x3]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800CAF4
	b _0800CC8A
_0800CAF4:
	adds r1, r7, 0
	movs r3, 0x1
_0800CAF8:
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0800CB08
	b _0800CC8A
_0800CB08:
	ldr r0, [r2]
	ldrb r0, [r0, 0x3]
	ldrb r4, [r7, 0x10]
	asrs r0, r4
	ands r0, r3
	cmp r0, 0
	beq _0800CAF8
	b _0800CC8A
	.pool
_0800CB1C:
	cmp r6, 0
	bne _0800CB3A
	mov r0, sp
	bl rfu_CHILD_getConnectRecoveryStatus
	lsls r0, 16
	cmp r0, 0
	bne _0800CB3A
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _0800CB3A
	ldr r1, =gUnknown_03004140
	movs r0, 0x12
	strb r0, [r1, 0x4]
_0800CB3A:
	ldr r2, =gUnknown_03004140
	ldrb r0, [r2, 0x10]
	lsls r0, 1
	adds r1, r2, 0
	adds r1, 0x34
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	bne _0800CB4E
	b _0800CC8A
_0800CB4E:
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _0800CB5A
	b _0800CC8A
_0800CB5A:
	movs r0, 0x12
	strb r0, [r2, 0x4]
	b _0800CC8A
	.pool
_0800CB64:
	cmp r6, 0
	beq _0800CB6A
	b _0800CC8A
_0800CB6A:
	mov r0, sp
	bl rfu_CHILD_getConnectRecoveryStatus
	lsls r0, 16
	cmp r0, 0
	beq _0800CB78
	b _0800CC8A
_0800CB78:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800CB94
	ldr r1, =gUnknown_03004140
	movs r0, 0x13
	strb r0, [r1, 0x4]
	movs r0, 0x16
	strb r0, [r1, 0x5]
	movs r0, 0x32
	strh r0, [r1, 0x1E]
	b _0800CBA8
	.pool
_0800CB94:
	ldr r4, =gUnknown_03004140
	strb r6, [r4, 0x5]
	strb r6, [r4, 0x4]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	bl sub_800D334
	movs r0, 0x33
	strh r0, [r4, 0x1E]
_0800CBA8:
	ldr r5, =gUnknown_03004140
	ldrb r0, [r5, 0x10]
	lsls r0, 1
	adds r1, r5, 0
	adds r1, 0x34
	adds r0, r1
	movs r1, 0
	movs r4, 0
	strh r4, [r0]
	adds r0, r5, 0
	adds r0, 0x30
	strb r1, [r0]
	strb r1, [r5, 0xA]
	ldrb r0, [r5, 0x1E]
	movs r1, 0x1
	bl sub_800D30C
	strh r4, [r5, 0x1E]
	b _0800CC8A
	.pool
_0800CBD8:
	cmp r6, 0
	bne _0800CC8A
	ldr r5, =gUnknown_03004140
	ldrb r1, [r5, 0x5]
	adds r0, r1, 0
	cmp r0, 0x16
	bne _0800CC04
	ldrb r0, [r5, 0x11]
	strb r0, [r5, 0x4]
	ldrb r0, [r5, 0x12]
	strb r0, [r5, 0x5]
	ldrb r0, [r5, 0x2]
	movs r0, 0x1
	strb r0, [r5, 0x2]
	movs r0, 0x41
_0800CBF6:
	movs r1, 0
	bl sub_800D30C
	b _0800CC8A
	.pool
_0800CC04:
	cmp r0, 0xF
	bne _0800CC8A
	strb r1, [r5, 0x4]
	ldrb r0, [r5, 0x2]
	movs r4, 0x1
	strb r4, [r5, 0x2]
	movs r0, 0x41
	movs r1, 0
	bl sub_800D30C
	adds r1, r5, 0
	adds r1, 0x24
	ldrb r0, [r5, 0x10]
	lsls r4, r0
	ldrb r0, [r1]
	orrs r4, r0
	strb r4, [r1]
	ldrb r0, [r5, 0x10]
	lsls r0, 1
	adds r1, 0x4
	adds r0, r1
	ldrh r1, [r5, 0x26]
	movs r7, 0
	strh r1, [r0]
	ldrb r1, [r5, 0x10]
	movs r0, 0x4
	bl rfu_clearSlot
	mov r4, sp
	ldrb r0, [r5, 0x10]
	movs r1, 0xE
	bl rfu_NI_CHILD_setSendGameName
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	beq _0800CC8A
	strb r7, [r5, 0x5]
	strb r7, [r5, 0x4]
	bl sub_800D610
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	orrs r0, r1
	bl sub_800D334
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r5, 0x14]
	movs r0, 0x25
	movs r1, 0x1
	bl sub_800D30C
	b _0800CC8A
	.pool
_0800CC78:
	cmp r6, 0
	bne _0800CC8A
	ldr r0, =gUnknown_03004140
	strb r6, [r0, 0x5]
	strb r6, [r0, 0x4]
	movs r0, 0x42
	movs r1, 0
	bl sub_800D30C
_0800CC8A:
	ldr r1, =gUnknown_03004140
	movs r0, 0x1
	strb r0, [r1, 0xE]
	b _0800CCE6
	.pool
_0800CC98:
	cmp r6, 0x3
	bne _0800CCE6
	ldrb r0, [r7, 0xF]
	cmp r0, 0
	beq _0800CCE6
	mov r3, r8
	cmp r3, 0x24
	beq _0800CCB0
	cmp r3, 0x26
	beq _0800CCB0
	cmp r3, 0x27
	bne _0800CCE6
_0800CCB0:
	bl rfu_REQ_RFUStatus
	bl rfu_waitREQComplete
	mov r0, sp
	bl rfu_getRFUStatus
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800CCE6
	ldr r4, =gUnknown_03007890
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	bne _0800CCE6
	bl rfu_getSTWIRecvBuffer
	ldr r1, [r4]
	ldrb r1, [r1, 0x2]
	strb r1, [r0, 0x4]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	movs r0, 0x29
	bl sub_800C36C
	movs r6, 0
_0800CCE6:
	mov r4, r8
	cmp r4, 0x26
	bne _0800CCEE
	b _0800CE02
_0800CCEE:
	cmp r4, 0x26
	bgt _0800CD00
	cmp r4, 0x10
	bne _0800CCF8
	b _0800CE20
_0800CCF8:
	b _0800CE3E
	.pool
_0800CD00:
	mov r0, r8
	cmp r0, 0x30
	beq _0800CD0E
	cmp r0, 0x3D
	bne _0800CD0C
	b _0800CE20
_0800CD0C:
	b _0800CE3E
_0800CD0E:
	cmp r6, 0
	beq _0800CD14
	b _0800CE42
_0800CD14:
	bl rfu_getSTWIRecvBuffer
	ldr r4, =gUnknown_03004140
	ldrb r0, [r0, 0x8]
	strh r0, [r4, 0x14]
	bl sub_800D358
	adds r2, r4, 0
	adds r2, 0x30
	ldrb r1, [r2]
	cmp r1, 0
	beq _0800CD6A
	ldrb r0, [r4, 0x14]
	adds r3, r1, 0
	bics r3, r0
	adds r0, r3, 0
	strb r0, [r2]
	movs r3, 0
	adds r7, r4, 0
	adds r1, r7, 0
	movs r5, 0x1
	adds r4, r1, 0
	adds r4, 0x34
	movs r2, 0
_0800CD44:
	ldrh r0, [r1, 0x14]
	asrs r0, r3
	ands r0, r5
	cmp r0, 0
	beq _0800CD54
	lsls r0, r3, 1
	adds r0, r4
	strh r2, [r0]
_0800CD54:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800CD44
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _0800CD6A
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x4]
_0800CD6A:
	mov r3, sp
	ldr r1, =gUnknown_03004140
	ldrb r2, [r1]
	ldrb r0, [r1, 0x14]
	ands r0, r2
	strb r0, [r3]
	movs r3, 0
	adds r7, r1, 0
	ldr r2, =gUnknown_03007890
	mov r1, sp
	movs r5, 0x1
	adds r4, r7, 0
_0800CD82:
	ldrb r0, [r1]
	asrs r0, r3
	ands r0, r5
	cmp r0, 0
	beq _0800CD96
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _0800CD96
	subs r0, 0x1
	strb r0, [r7, 0x1]
_0800CD96:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0800CD82
	ldrb r1, [r7, 0x14]
	ldrb r0, [r7]
	bics r0, r1
	strb r0, [r7]
	ldrb r1, [r7, 0x7]
	cmp r1, 0
	beq _0800CDE0
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0800CDF2
	cmp r1, 0x8
	bne _0800CDCC
	ldrh r0, [r7, 0x1C]
	strh r0, [r7, 0x1A]
	movs r0, 0x6
	strb r0, [r7, 0x7]
	b _0800CDDE
	.pool
_0800CDCC:
	ldrb r0, [r7, 0x4]
	subs r0, 0x6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0800CDE0
	movs r0, 0x1
	strb r0, [r7, 0x7]
	movs r0, 0x5
_0800CDDE:
	strb r0, [r7, 0x4]
_0800CDE0:
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0800CDF2
	ldrb r0, [r7, 0x4]
	cmp r0, 0
	bne _0800CDF2
	movs r0, 0xFF
	strb r0, [r7, 0x6]
_0800CDF2:
	ldrb r0, [r7, 0xE]
	cmp r0, 0
	bne _0800CE3E
	movs r0, 0x40
	movs r1, 0x1
	bl sub_800D30C
	b _0800CE3E
_0800CE02:
	bl sub_800D20C
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0800CE3E
	movs r0, 0x50
	movs r1, 0
	bl sub_800D30C
	b _0800CE3E
	.pool
_0800CE20:
	cmp r6, 0
	bne _0800CE42
	ldr r0, =gUnknown_03004140
	strb r6, [r0, 0xD]
	strb r6, [r0, 0x1]
	strb r6, [r0]
	movs r1, 0xFF
	strb r1, [r0, 0x6]
	bl sub_800D610
	mov r4, r8
	cmp r4, 0x3D
	bne _0800CE3E
	bl sub_800BFA0
_0800CE3E:
	cmp r6, 0
	beq _0800CE92
_0800CE42:
	ldr r7, =gUnknown_03004140
	mov r0, r8
	cmp r0, 0x1C
	bne _0800CE74
	cmp r6, 0
	beq _0800CE74
	ldrb r0, [r7, 0x7]
	cmp r0, 0x4
	bne _0800CE74
	ldr r2, =gUnknown_03007890
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, 0xF
	strb r0, [r1, 0x2]
	bl sub_800D334
	bl rfu_waitREQComplete
	b _0800CEA4
	.pool
_0800CE74:
	movs r1, 0
	mov r3, r8
	strh r3, [r7, 0x14]
	strh r6, [r7, 0x16]
	ldrb r0, [r7, 0xE]
	cmp r0, 0
	beq _0800CE86
	strb r1, [r7, 0x5]
	strb r1, [r7, 0x4]
_0800CE86:
	movs r0, 0xF0
	movs r1, 0x2
	bl sub_800D30C
	bl sub_800D610
_0800CE92:
	mov r4, r8
	cmp r4, 0xFF
	bne _0800CEA4
	movs r0, 0xF2
	movs r1, 0
	bl sub_800D30C
	bl sub_800D610
_0800CEA4:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800C7B4

	thumb_func_start sub_800CEB0
sub_800CEB0: @ 800CEB0
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r4, =gUnknown_03004140
	ldrb r7, [r4, 0xE]
	movs r0, 0
	strb r0, [r4, 0xE]
	movs r0, 0x1
	strb r0, [r4, 0xF]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r5, [r0]
	cmp r5, 0
	bne _0800CEEC
	adds r0, r6, 0
	bl sub_800C36C
	ldrb r0, [r4, 0x2]
	cmp r0, 0x1
	beq _0800CF04
	bl sub_800D610
	strb r5, [r4, 0xF]
	strb r7, [r4, 0xE]
	b _0800CF28
	.pool
_0800CEEC:
	mov r0, sp
	bl rfu_UNI_PARENT_getDRAC_ACK
	lsls r0, 16
	cmp r0, 0
	bne _0800CF04
	mov r1, sp
	ldrb r0, [r4, 0x3]
	ldrb r1, [r1]
	orrs r0, r1
	ldrb r1, [r4, 0x3]
	strb r0, [r4, 0x3]
_0800CF04:
	ldr r4, =gUnknown_03004140
	ldr r1, [r4, 0x44]
	cmp r1, 0
	beq _0800CF20
	adds r0, r6, 0
	bl _call_via_r1
	bl rfu_waitREQComplete
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	bne _0800CF20
	bl sub_800D610
_0800CF20:
	ldr r1, =gUnknown_03004140
	movs r0, 0
	strb r0, [r1, 0xF]
	strb r7, [r1, 0xE]
_0800CF28:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800CEB0

	thumb_func_start sub_800CF34
sub_800CF34: @ 800CF34
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x4]
	subs r0, 0x5
	lsls r0, 24
	lsrs r0, 24
	adds r3, r1, 0
	cmp r0, 0x3
	bls _0800CF52
	b _0800D146
_0800CF52:
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r3, 0xC]
	adds r4, r1, 0
	eors r4, r0
	ands r4, r1
	ldrb r0, [r2, 0x7]
	bics r4, r0
	mov r8, r4
	strb r1, [r3, 0xC]
	cmp r4, 0
	beq _0800CF7A
	strh r4, [r3, 0x14]
	movs r0, 0x10
	movs r1, 0x1
	str r3, [sp, 0x4]
	bl sub_800D30C
	ldr r3, [sp, 0x4]
_0800CF7A:
	movs r0, 0
	str r0, [sp]
	movs r6, 0
	adds r7, r3, 0
	movs r1, 0x24
	adds r1, r3
	mov r9, r1
_0800CF88:
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r6
	lsrs r4, r0, 24
	movs r5, 0
	mov r0, r8
	ands r0, r4
	cmp r0, 0
	beq _0800CFDA
	lsls r1, r6, 1
	adds r0, r7, 0
	adds r0, 0x28
	adds r1, r0
	ldrh r0, [r7, 0x26]
	strh r0, [r1]
	mov r2, r9
	ldrb r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r10, r6
	b _0800D090
	.pool
_0800CFC0:
	ldrb r1, [r7]
	adds r0, r4, 0
	orrs r0, r1
	strb r0, [r7]
	ldrb r0, [r7, 0x1]
	adds r0, 0x1
	strb r0, [r7, 0x1]
	ldr r0, [sp]
	orrs r0, r4
	str r0, [sp]
	movs r0, 0x1
	orrs r5, r0
	b _0800D024
_0800CFDA:
	mov r1, r9
	ldrb r0, [r1]
	ands r0, r4
	adds r2, r6, 0x1
	mov r10, r2
	cmp r0, 0
	beq _0800D090
	ldr r0, =gUnknown_03007880
	lsls r1, r6, 2
	adds r1, r0
	ldr r1, [r1]
	ldrh r0, [r1, 0x34]
	cmp r0, 0x46
	bne _0800D040
	adds r0, r1, 0
	adds r0, 0x61
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0800D058
	movs r5, 0x2
	ldr r3, [r3, 0x20]
	ldrh r2, [r3]
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _0800D024
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	lsls r1, r6, 5
	adds r0, r1
	ldrh r0, [r0, 0x18]
	ldr r1, =0x0000ffff
_0800D018:
	cmp r0, r2
	beq _0800CFC0
	adds r3, 0x2
	ldrh r2, [r3]
	cmp r2, r1
	bne _0800D018
_0800D024:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0800D058
	movs r0, 0x4
	orrs r5, r0
	b _0800D058
	.pool
_0800D040:
	lsls r1, r6, 1
	adds r0, r3, 0
	adds r0, 0x28
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	ldr r1, =0x0000ffff
	ands r0, r1
	cmp r0, 0
	bne _0800D058
	movs r5, 0x6
_0800D058:
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _0800D07E
	mov r2, r9
	ldrb r0, [r2]
	bics r0, r4
	movs r2, 0
	mov r1, r9
	strb r0, [r1]
	lsls r0, r6, 1
	adds r1, r7, 0
	adds r1, 0x28
	adds r0, r1
	strh r2, [r0]
	movs r0, 0x8
	adds r1, r6, 0
	bl rfu_clearSlot
_0800D07E:
	movs r0, 0x4
	ands r5, r0
	ldr r3, =gUnknown_03004140
	cmp r5, 0
	beq _0800D090
	ldrb r1, [r7, 0xD]
	adds r0, r4, 0
	orrs r0, r1
	strb r0, [r7, 0xD]
_0800D090:
	mov r2, r10
	lsls r0, r2, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bhi _0800D09C
	b _0800CF88
_0800D09C:
	ldr r4, [sp]
	cmp r4, 0
	beq _0800D0AE
	ldr r0, =gUnknown_03004140
	strh r4, [r0, 0x14]
	movs r0, 0x11
	movs r1, 0x1
	bl sub_800D30C
_0800D0AE:
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0xD]
	cmp r0, 0
	beq _0800D0EA
	movs r5, 0x1
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0800D0CE
	ldrb r0, [r1, 0x3]
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, r1
	beq _0800D0CE
	movs r5, 0
_0800D0CE:
	cmp r5, 0
	beq _0800D0EA
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0xD]
	bl sub_800D334
	ldrb r0, [r4, 0xD]
	movs r1, 0
	strh r0, [r4, 0x14]
	strb r1, [r4, 0xD]
	movs r0, 0x12
	movs r1, 0x1
	bl sub_800D30C
_0800D0EA:
	ldr r0, =gUnknown_03004140
	adds r1, r0, 0
	adds r1, 0x24
	ldrb r1, [r1]
	adds r3, r0, 0
	cmp r1, 0
	bne _0800D146
	ldrb r0, [r3, 0x4]
	cmp r0, 0x8
	bne _0800D146
	ldrb r0, [r3, 0x7]
	cmp r0, 0
	bne _0800D120
	strb r0, [r3, 0x5]
	strb r0, [r3, 0x4]
	movs r0, 0x14
	movs r1, 0
	bl sub_800D30C
	b _0800D146
	.pool
_0800D120:
	cmp r0, 0x2
	bne _0800D12C
	movs r0, 0x3
	strb r0, [r3, 0x7]
	movs r0, 0x9
	b _0800D132
_0800D12C:
	movs r0, 0x1
	strb r0, [r3, 0x7]
	movs r0, 0x5
_0800D132:
	strb r0, [r3, 0x4]
	ldrb r0, [r3]
	cmp r0, 0
	beq _0800D146
	movs r0, 0
	strh r0, [r3, 0x1A]
	movs r0, 0x8
	strb r0, [r3, 0x7]
	movs r0, 0x5
	strb r0, [r3, 0x4]
_0800D146:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800CF34

	thumb_func_start sub_800D158
sub_800D158: @ 800D158
	push {r4-r6,lr}
	ldr r1, =0x04000208
	ldrh r0, [r1]
	adds r6, r0, 0
	movs r0, 0
	strh r0, [r1]
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0x4]
	cmp r0, 0xF
	bne _0800D1BC
	ldrb r1, [r4, 0x10]
	lsls r1, 1
	adds r5, r4, 0
	adds r5, 0x28
	adds r1, r5
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _0800D192
	ldr r1, =gUnknown_03007880
	ldrb r0, [r4, 0x10]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x27
	bne _0800D1BC
_0800D192:
	bl sub_800D630
	movs r0, 0x18
	strb r0, [r4, 0x4]
	ldrb r1, [r4, 0x10]
	movs r0, 0x4
	bl rfu_clearSlot
	adds r2, r4, 0
	adds r2, 0x24
	movs r1, 0x1
	ldrb r0, [r4, 0x10]
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r4, 0x10]
	lsls r0, 1
	adds r0, r5
	movs r1, 0
	strh r1, [r0]
_0800D1BC:
	ldr r0, =0x04000208
	strh r6, [r0]
	ldr r5, =gUnknown_03004140
	ldrb r0, [r5, 0x4]
	cmp r0, 0x18
	bne _0800D1F6
	ldrb r0, [r5, 0x2]
	cmp r0, 0x1
	bne _0800D1D2
	bl sub_800D630
_0800D1D2:
	ldrb r0, [r5, 0x2]
	adds r4, r0, 0
	cmp r4, 0
	bne _0800D1F6
	strb r4, [r5, 0x5]
	strb r4, [r5, 0x4]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	orrs r0, r1
	bl sub_800D334
	strh r4, [r5, 0x14]
	movs r0, 0x25
	movs r1, 0x1
	bl sub_800D30C
_0800D1F6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D158

	thumb_func_start sub_800D20C
sub_800D20C: @ 800D20C
	push {r4,r5,lr}
	ldr r5, =gUnknown_03004140
	ldrb r0, [r5, 0x4]
	cmp r0, 0xF
	bne _0800D258
	ldr r1, =gUnknown_03007880
	ldrb r2, [r5, 0x10]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x26
	bne _0800D258
	movs r4, 0
	strb r4, [r5, 0x5]
	strb r4, [r5, 0x4]
	movs r0, 0x4
	adds r1, r2, 0
	bl rfu_clearSlot
	adds r2, r5, 0
	adds r2, 0x24
	movs r1, 0x1
	ldrb r0, [r5, 0x10]
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r5, 0x10]
	lsls r0, 1
	adds r1, r5, 0
	adds r1, 0x28
	adds r0, r1
	strh r4, [r0]
	movs r0, 0x24
	movs r1, 0
	bl sub_800D30C
_0800D258:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D20C

	thumb_func_start sub_800D268
sub_800D268: @ 800D268
	push {lr}
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _0800D28C
	ldrb r0, [r1, 0xA]
	cmp r0, 0x1
	bne _0800D28C
	ldrb r0, [r1, 0x4]
	strb r0, [r1, 0x11]
	ldrb r0, [r1, 0x5]
	strb r0, [r1, 0x12]
	movs r0, 0x10
	strb r0, [r1, 0x4]
	movs r0, 0x11
	strb r0, [r1, 0x5]
	movs r0, 0x2
	strb r0, [r1, 0xA]
_0800D28C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D268

	thumb_func_start sub_800D294
sub_800D294: @ 800D294
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	movs r5, 0
	ldr r1, =gUnknown_03007890
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	bcs _0800D2F0
	mov r8, r0
	ldr r0, =gUnknown_03004140
	mov r10, r0
	mov r9, r1
_0800D2B4:
	mov r1, r10
	ldr r3, [r1, 0x20]
	ldrh r2, [r3]
	adds r0, r5, 0x1
	mov r12, r0
	ldr r1, =0x0000ffff
	cmp r2, r1
	beq _0800D2E6
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r5, 5
	adds r0, r1
	ldrh r4, [r0, 0x18]
	ldr r7, =0x0000ffff
	movs r1, 0x1
	lsls r1, r5
_0800D2D4:
	cmp r4, r2
	bne _0800D2DE
	orrs r6, r1
	lsls r0, r6, 24
	lsrs r6, r0, 24
_0800D2DE:
	adds r3, 0x2
	ldrh r2, [r3]
	cmp r2, r7
	bne _0800D2D4
_0800D2E6:
	mov r1, r12
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, r8
	bcc _0800D2B4
_0800D2F0:
	adds r0, r6, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800D294

	thumb_func_start sub_800D30C
sub_800D30C: @ 800D30C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r4, =gUnknown_03004140
	ldr r2, [r4, 0x40]
	cmp r2, 0
	beq _0800D322
	bl _call_via_r2
_0800D322:
	movs r0, 0
	strh r0, [r4, 0x16]
	strh r0, [r4, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D30C

	thumb_func_start sub_800D334
sub_800D334: @ 800D334
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_03004140
	ldrb r5, [r4, 0xE]
	movs r1, 0x1
	strb r1, [r4, 0xE]
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	strb r5, [r4, 0xE]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D334

	thumb_func_start sub_800D358
sub_800D358: @ 800D358
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0800D3A0
	movs r4, 0
_0800D36A:
	ldr r1, =gUnknown_03007880
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0800D396
	ldrb r1, [r2, 0x1A]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0800D396
	adds r2, r1, 0
	bics r2, r5
	movs r0, 0x20
	adds r1, r4, 0
	bl rfu_changeSendTarget
_0800D396:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800D36A
_0800D3A0:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	beq _0800D3DE
	movs r4, 0
_0800D3AC:
	ldr r1, =gUnknown_03007880
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	ldrh r0, [r2, 0x34]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0800D3D4
	adds r0, r2, 0
	adds r0, 0x4E
	ldrb r0, [r0]
	ands r0, r5
	cmp r0, 0
	beq _0800D3D4
	adds r0, r4, 0
	bl rfu_NI_stopReceivingData
_0800D3D4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800D3AC
_0800D3DE:
	ldr r0, =gUnknown_03007890
	ldr r3, [r0]
	ldrb r2, [r3, 0x6]
	cmp r2, 0
	beq _0800D41C
	mvns r1, r5
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0x6]
	movs r4, 0
	ldr r7, =gUnknown_03007870
	ldr r6, =0x00008024
_0800D3F6:
	lsls r0, r4, 2
	adds r0, r7
	ldr r2, [r0]
	ldrh r0, [r2]
	cmp r0, r6
	bne _0800D412
	ldrb r3, [r2, 0x3]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _0800D412
	adds r0, r1, 0
	ands r0, r3
	strb r0, [r2, 0x3]
_0800D412:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800D3F6
_0800D41C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D358

	thumb_func_start sub_800D434
sub_800D434: @ 800D434
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x18]
	cmp r0, 0
	beq _0800D510
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0800D4D4
	movs r6, 0
_0800D454:
	ldr r3, =gUnknown_03007880
	lsls r2, r6, 2
	adds r0, r2, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, 0x80
	lsls r4, 8
	adds r0, r4, 0
	ands r1, r0
	adds r7, r2, 0
	adds r0, r6, 0x1
	mov r9, r0
	cmp r1, 0
	beq _0800D4CA
	movs r5, 0
	movs r4, 0
	movs r1, 0x1
	mov r8, r1
	mov r10, r3
_0800D47A:
	adds r0, r7, r3
	ldr r0, [r0]
	ldrb r0, [r0, 0x1A]
	asrs r0, r4
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0800D4A4
	lsls r0, r4, 2
	adds r0, r3
	ldr r0, [r0]
	ldr r1, =gUnknown_03004140
	ldrh r0, [r0, 0x2]
	ldrh r1, [r1, 0x18]
	cmp r0, r1
	bls _0800D4A4
	mov r0, r8
	lsls r0, r4
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_0800D4A4:
	cmp r5, 0
	beq _0800D4C0
	mov r1, r10
	adds r0, r7, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1A]
	adds r2, r5, 0
	eors r2, r0
	movs r0, 0x20
	adds r1, r6, 0
	str r3, [sp]
	bl rfu_changeSendTarget
	ldr r3, [sp]
_0800D4C0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0800D47A
_0800D4CA:
	mov r3, r9
	lsls r0, r3, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0800D454
_0800D4D4:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	beq _0800D510
	movs r6, 0
_0800D4E0:
	ldr r1, =gUnknown_03007880
	lsls r0, r6, 2
	adds r0, r1
	ldr r2, [r0]
	ldrh r0, [r2, 0x34]
	movs r4, 0x80
	lsls r4, 8
	adds r1, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0800D506
	ldr r1, =gUnknown_03004140
	ldrh r0, [r2, 0x36]
	ldrh r1, [r1, 0x18]
	cmp r0, r1
	bls _0800D506
	adds r0, r6, 0
	bl rfu_NI_stopReceivingData
_0800D506:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0800D4E0
_0800D510:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D434

	thumb_func_start sub_800D52C
sub_800D52C: @ 800D52C
	push {lr}
	ldr r1, =gUnknown_03004140
	str r0, [r1, 0x44]
	ldr r0, =sub_800CEB0
	bl rfu_setMSCCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D52C

	thumb_func_start sub_800D544
sub_800D544: @ 800D544
	ldr r1, =gUnknown_03004140
	str r0, [r1, 0x40]
	bx lr
	.pool
	thumb_func_end sub_800D544

	thumb_func_start sub_800D550
sub_800D550: @ 800D550
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x9]
	adds r3, r0, 0
	cmp r1, 0
	beq _0800D578
	cmp r4, 0
	bne _0800D578
	adds r0, 0x30
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800D578
	movs r0, 0x5
	b _0800D588
	.pool
_0800D578:
	ldr r2, =0x04000208
	ldrh r1, [r2]
	movs r0, 0
	strh r0, [r2]
	strb r4, [r3, 0x9]
	strh r5, [r3, 0x32]
	strh r1, [r2]
	movs r0, 0
_0800D588:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800D550

	thumb_func_start sub_800D594
sub_800D594: @ 800D594
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r1, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	orrs r0, r1
	cmp r0, 0
	bne _0800D5B8
	ldr r0, =gUnknown_03004140
	strh r2, [r0, 0x18]
	movs r0, 0
	b _0800D5C8
	.pool
_0800D5B8:
	ldr r1, =gUnknown_03004140
	movs r0, 0x6
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x6
_0800D5C8:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800D594

	thumb_func_start sub_800D5D0
sub_800D5D0: @ 800D5D0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x4]
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _0800D5FC
	movs r0, 0x7
	strh r0, [r1, 0x14]
	movs r0, 0xF3
	movs r1, 0x1
	bl sub_800D30C
	movs r0, 0x7
	b _0800D60A
	.pool
_0800D5FC:
	cmp r2, 0
	beq _0800D606
	movs r0, 0x1
	strb r0, [r1, 0xB]
	b _0800D608
_0800D606:
	strb r3, [r1, 0xB]
_0800D608:
	movs r0, 0
_0800D60A:
	pop {r1}
	bx r1
	thumb_func_end sub_800D5D0

	thumb_func_start sub_800D610
sub_800D610: @ 800D610
	push {lr}
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0800D628
	ldrb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x2]
	movs r0, 0x45
	movs r1, 0
	bl sub_800D30C
_0800D628:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D610

	thumb_func_start sub_800D630
sub_800D630: @ 800D630
	push {lr}
	ldr r1, =gUnknown_03004140
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _0800D648
	movs r0, 0x45
	movs r1, 0
	bl sub_800D30C
	b _0800D654
	.pool
_0800D648:
	ldrb r0, [r1, 0x2]
	cmp r0, 0x1
	bne _0800D654
	ldrb r0, [r1, 0x2]
	movs r0, 0x2
	strb r0, [r1, 0x2]
_0800D654:
	pop {r0}
	bx r0
	thumb_func_end sub_800D630

	thumb_func_start sub_800D658
sub_800D658: @ 800D658
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x7]
	adds r2, r0, 0
	cmp r1, 0
	beq _0800D6C2
	ldrb r0, [r2, 0x4]
	subs r0, 0x5
	cmp r0, 0x6
	bhi _0800D6C2
	lsls r0, 2
	ldr r1, =_0800D680
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0800D680:
	.4byte _0800D69C
	.4byte _0800D6A4
	.4byte _0800D6AE
	.4byte _0800D6AE
	.4byte _0800D6B4
	.4byte _0800D6B4
	.4byte _0800D6BA
_0800D69C:
	movs r0, 0x3
	strb r0, [r2, 0x7]
	movs r0, 0x9
	b _0800D6C0
_0800D6A4:
	movs r0, 0x2
	strb r0, [r2, 0x7]
	movs r0, 0x1
	strh r0, [r2, 0x1A]
	b _0800D6C2
_0800D6AE:
	movs r0, 0x2
	strb r0, [r2, 0x7]
	b _0800D6C2
_0800D6B4:
	movs r0, 0x28
	strh r0, [r2, 0x1A]
	b _0800D6C2
_0800D6BA:
	movs r0, 0x28
	strh r0, [r2, 0x1A]
	movs r0, 0xA
_0800D6C0:
	strb r0, [r2, 0x4]
_0800D6C2:
	pop {r0}
	bx r0
	thumb_func_end sub_800D658

	thumb_func_start sub_800D6C8
sub_800D6C8: @ 800D6C8
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r0, 0
	movs r4, 0
	movs r5, 0x46
_0800D6D2:
	adds r2, r0, 0x1
	movs r1, 0x45
	muls r0, r5
	adds r0, r3
	adds r0, 0x45
_0800D6DC:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _0800D6DC
	adds r0, r2, 0
	cmp r0, 0x1F
	ble _0800D6D2
	movs r1, 0
	ldr r2, =0x000008c1
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	movs r2, 0x8C
	lsls r2, 4
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x000008c2
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x000008c3
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D6C8

	thumb_func_start sub_800D724
sub_800D724: @ 800D724
	push {r4,lr}
	adds r3, r0, 0
	movs r1, 0
	movs r4, 0
_0800D72C:
	lsls r0, r1, 3
	adds r2, r1, 0x1
	subs r0, r1
	movs r1, 0xD
	lsls r0, 1
	adds r0, r3
	adds r0, 0xD
_0800D73A:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _0800D73A
	adds r1, r2, 0
	cmp r1, 0x27
	ble _0800D72C
	movs r1, 0
	ldr r2, =0x00000231
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	movs r2, 0x8C
	lsls r2, 2
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x00000232
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x00000233
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D724

	thumb_func_start sub_800D780
sub_800D780: @ 800D780
	push {r4,lr}
	adds r3, r0, 0
	movs r1, 0
	movs r4, 0
_0800D788:
	lsls r0, r1, 8
	adds r2, r1, 0x1
	movs r1, 0xFF
	adds r0, r3
	adds r0, 0xFF
_0800D792:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _0800D792
	adds r1, r2, 0
	cmp r1, 0x1
	ble _0800D788
	movs r1, 0
	ldr r2, =0x00000201
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x00000202
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r2, =0x00000203
	adds r0, r3, r2
	ldrb r2, [r0]
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D780

	thumb_func_start sub_800D7D8
sub_800D7D8: @ 800D7D8
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldr r1, =0x000008c2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1F
	bhi _0800D874
	ldr r0, =0x04000208
	ldrh r1, [r0]
	adds r7, r1, 0
	movs r1, 0
	strh r1, [r0]
	movs r5, 0
	movs r2, 0
_0800D7F6:
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0800D80A
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _0800D80A
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0800D80A:
	adds r2, 0xE
	cmp r2, 0x45
	ble _0800D7F6
	cmp r5, 0x5
	beq _0800D866
	movs r2, 0
	movs r0, 0x8C
	lsls r0, 4
	adds r5, r3, r0
	movs r6, 0x46
_0800D81E:
	ldrb r0, [r5]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r2, r1
	adds r1, r3, r1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x45
	ble _0800D81E
	movs r0, 0x8C
	lsls r0, 4
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x000008c2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r1, 0
	adds r0, r4, 0
	adds r0, 0x45
_0800D85E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r4
	bge _0800D85E
_0800D866:
	ldr r0, =0x04000208
	strh r7, [r0]
	b _0800D87E
	.pool
_0800D874:
	ldr r1, =0x000008c3
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r1, 0x1
	strb r1, [r0]
_0800D87E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D7D8

	thumb_func_start sub_800D888
sub_800D888: @ 800D888
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r1, =0x00000232
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0x27
	bhi _0800D920
	ldr r1, =0x04000208
	ldrh r0, [r1]
	adds r7, r0, 0
	movs r0, 0
	strh r0, [r1]
	movs r2, 0
	ldrb r0, [r5]
	cmp r0, 0
	bne _0800D8B8
_0800D8AA:
	adds r2, 0x1
	cmp r2, 0xD
	bgt _0800D8B8
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800D8AA
_0800D8B8:
	cmp r2, 0xE
	beq _0800D910
	movs r2, 0
	movs r0, 0x8C
	lsls r0, 2
	adds r3, r6, r0
_0800D8C4:
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r2, r0
	adds r0, r6, r0
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xD
	ble _0800D8C4
	movs r1, 0x8C
	lsls r1, 2
	adds r4, r6, r1
	ldrb r0, [r4]
	adds r0, 0x1
	ldrb r1, [r4]
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0x28
	bl __umodsi3
	ldrb r1, [r4]
	strb r0, [r4]
	ldr r0, =0x00000232
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r1, 0
	adds r0, r5, 0
	adds r0, 0xD
_0800D908:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r5
	bge _0800D908
_0800D910:
	ldr r0, =0x04000208
	strh r7, [r0]
	b _0800D92A
	.pool
_0800D920:
	ldr r1, =0x00000233
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r1, 0x1
	strb r1, [r0]
_0800D92A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800D888

	thumb_func_start sub_800D934
sub_800D934: @ 800D934
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldr r1, =0x04000208
	ldrh r0, [r1]
	mov r12, r0
	movs r0, 0
	strh r0, [r1]
	movs r1, 0x8C
	lsls r1, 4
	adds r0, r3, r1
	ldr r7, =0x000008c1
	adds r5, r3, r7
	ldrb r1, [r0]
	ldrb r0, [r5]
	cmp r1, r0
	beq _0800D960
	ldr r1, =0x000008c3
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800D984
_0800D960:
	movs r1, 0
	adds r0, r4, 0
	adds r0, 0x45
_0800D966:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r4
	bge _0800D966
	ldr r0, =0x04000208
	mov r7, r12
	strh r7, [r0]
	movs r0, 0
	b _0800D9CA
	.pool
_0800D984:
	movs r2, 0
	movs r6, 0x46
_0800D988:
	adds r1, r4, r2
	ldrb r0, [r5]
	adds r7, r0, 0
	muls r7, r6
	adds r0, r7, 0
	adds r0, r2, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x45
	ble _0800D988
	ldr r0, =0x000008c1
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x1F
	ands r0, r2
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r7, =0x000008c2
	adds r1, r3, r7
	ldrb r0, [r1]
	subs r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x04000208
	mov r1, r12
	strh r1, [r0]
	movs r0, 0x1
_0800D9CA:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800D934

	thumb_func_start sub_800D9DC
sub_800D9DC: @ 800D9DC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r1, 0x8C
	lsls r1, 2
	adds r0, r5, r1
	adds r1, 0x1
	adds r4, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r1, r0
	beq _0800DA00
	ldr r1, =0x00000233
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r2, r0, 0
	cmp r2, 0
	beq _0800DA08
_0800DA00:
	movs r0, 0
	b _0800DA54
	.pool
_0800DA08:
	ldr r1, =0x04000208
	ldrh r0, [r1]
	adds r7, r0, 0
	strh r2, [r1]
	movs r3, 0
_0800DA12:
	adds r2, r6, r3
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r3, r0
	adds r0, r5, r0
	ldrb r0, [r0]
	strb r0, [r2]
	adds r3, 0x1
	cmp r3, 0xD
	ble _0800DA12
	ldr r0, =0x00000231
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, 0x1
	ldrb r1, [r4]
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0x28
	bl __umodsi3
	ldrb r1, [r4]
	strb r0, [r4]
	ldr r0, =0x00000232
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x04000208
	strh r7, [r0]
	movs r0, 0x1
_0800DA54:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800D9DC

	thumb_func_start sub_800DA68
sub_800DA68: @ 800DA68
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0800DA7E
	adds r0, r2, 0
	movs r1, 0
	bl sub_800DAC8
	b _0800DAC0
_0800DA7E:
	movs r3, 0
_0800DA80:
	ldrb r1, [r2, 0x1C]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r3, r0
	adds r0, r2, r0
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0xD
	ble _0800DA80
	ldrb r0, [r2, 0x1C]
	adds r0, 0x1
	ldrb r1, [r2, 0x1C]
	strb r0, [r2, 0x1C]
	ldrb r1, [r2, 0x1C]
	movs r0, 0x1
	ands r0, r1
	ldrb r1, [r2, 0x1C]
	strb r0, [r2, 0x1C]
	ldrb r0, [r2, 0x1E]
	cmp r0, 0x1
	bhi _0800DABA
	ldrb r0, [r2, 0x1E]
	adds r0, 0x1
	ldrb r1, [r2, 0x1E]
	strb r0, [r2, 0x1E]
	b _0800DAC0
_0800DABA:
	ldrb r0, [r2, 0x1C]
	ldrb r1, [r2, 0x1D]
	strb r0, [r2, 0x1D]
_0800DAC0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800DA68

	thumb_func_start sub_800DAC8
sub_800DAC8: @ 800DAC8
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	ldrb r0, [r3, 0x1E]
	cmp r0, 0
	bne _0800DAD8
	movs r0, 0
	b _0800DB12
_0800DAD8:
	cmp r5, 0
	beq _0800DAF6
	movs r4, 0
_0800DADE:
	adds r2, r5, r4
	ldrb r1, [r3, 0x1D]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, r4, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r2]
	adds r4, 0x1
	cmp r4, 0xD
	ble _0800DADE
_0800DAF6:
	ldrb r0, [r3, 0x1D]
	adds r0, 0x1
	ldrb r1, [r3, 0x1D]
	strb r0, [r3, 0x1D]
	ldrb r1, [r3, 0x1D]
	movs r0, 0x1
	ands r0, r1
	ldrb r1, [r3, 0x1D]
	strb r0, [r3, 0x1D]
	ldrb r0, [r3, 0x1E]
	subs r0, 0x1
	ldrb r1, [r3, 0x1E]
	strb r0, [r3, 0x1E]
	movs r0, 0x1
_0800DB12:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800DAC8

	thumb_func_start sub_800DB18
sub_800DB18: @ 800DB18
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	ldr r1, =0x00000202
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _0800DB70
	movs r2, 0
	movs r0, 0x80
	lsls r0, 2
	adds r4, r3, r0
_0800DB30:
	ldrb r0, [r4]
	lsls r0, 8
	adds r0, r2, r0
	adds r0, r3, r0
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xFF
	ble _0800DB30
	movs r0, 0x80
	lsls r0, 2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x00000202
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	b _0800DB7A
	.pool
_0800DB70:
	ldr r1, =0x00000203
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r1, 0x1
	strb r1, [r0]
_0800DB7A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DB18

	thumb_func_start sub_800DB84
sub_800DB84: @ 800DB84
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	movs r1, 0x80
	lsls r1, 2
	adds r0, r3, r1
	adds r1, 0x1
	adds r4, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r1, r0
	beq _0800DBA6
	ldr r1, =0x00000203
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800DBB0
_0800DBA6:
	movs r0, 0
	b _0800DBEA
	.pool
_0800DBB0:
	movs r2, 0
_0800DBB2:
	adds r0, r5, r2
	ldrb r1, [r4]
	lsls r1, 8
	adds r1, r2, r1
	adds r1, r3, r1
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xFF
	ble _0800DBB2
	ldr r0, =0x00000201
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	ldrb r2, [r1]
	strb r0, [r1]
	ldr r0, =0x00000202
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0x1
_0800DBEA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_800DB84

	thumb_func_start sub_800DBF8
sub_800DBF8: @ 800DBF8
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	movs r5, 0
	cmp r1, 0x1
	beq _0800DC36
	cmp r1, 0x1
	bgt _0800DC12
	cmp r1, 0
	beq _0800DC1C
	b _0800DCAA
_0800DC12:
	cmp r0, 0x2
	beq _0800DC56
	cmp r0, 0x3
	beq _0800DC76
	b _0800DCAA
_0800DC1C:
	movs r4, 0
_0800DC1E:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r1, [r0]
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, r1, 0
	cmp r4, 0xC7
	ble _0800DC1E
	b _0800DC70
_0800DC36:
	movs r4, 0
	adds r2, r6, 0
	adds r2, 0xC8
_0800DC3C:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r1, [r0]
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, r1, 0
	cmp r4, 0x63
	ble _0800DC3C
	strh r5, [r2]
	b _0800DCAA
_0800DC56:
	movs r4, 0
_0800DC58:
	bl Random
	lsls r0, 24
	lsrs r0, 24
	adds r1, r6, r4
	strb r0, [r1]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x1
	cmp r4, 0xC7
	ble _0800DC58
_0800DC70:
	adds r0, r6, r4
	strh r5, [r0]
	b _0800DCAA
_0800DC76:
	movs r4, 0
	ldr r3, =gUnknown_03000D74
	ldrb r1, [r3]
	ldrb r0, [r3]
	adds r7, r0, 0x1
	adds r2, r1, 0x1
	movs r0, 0xFF
	mov r12, r0
_0800DC86:
	adds r0, r6, r4
	adds r1, r4, 0x1
	strb r2, [r0]
	adds r0, r4, r7
	mov r4, r12
	ands r0, r4
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r2, 0x1
	adds r4, r1, 0
	cmp r1, 0xC7
	ble _0800DC86
	adds r0, r6, r1
	strh r5, [r0]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_0800DCAA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_800DBF8

	.align 2, 0 @ Don't pad with nop.
