	thumb_func_start SwitchFlashBank
SwitchFlashBank: @ 82E185C
	lsls r0, 24
	lsrs r0, 24
	ldr r3, _082E1878
	movs r1, 0xAA
	strb r1, [r3]
	ldr r2, _082E187C
	movs r1, 0x55
	strb r1, [r2]
	movs r1, 0xB0
	strb r1, [r3]
	movs r1, 0xE0
	lsls r1, 20
	strb r0, [r1]
	bx lr
	.align 2, 0
_082E1878: .4byte 0x0e005555
_082E187C: .4byte 0x0e002aaa
	thumb_func_end SwitchFlashBank

	thumb_func_start ReadFlashID
@ u16 ReadFlashID()
ReadFlashID: @ 82E1880
	push {r4,r5,lr}
	sub sp, 0x44
	mov r0, sp
	bl SetReadFlash1
	mov r5, sp
	adds r5, 0x1
	ldr r2, _082E18A8
	movs r0, 0xAA
	strb r0, [r2]
	ldr r1, _082E18AC
	movs r0, 0x55
	strb r0, [r1]
	movs r0, 0x90
	strb r0, [r2]
	add r1, sp, 0x40
	ldr r2, _082E18B0
	adds r0, r2, 0
	b _082E18B8
	.align 2, 0
_082E18A8: .4byte 0x0e005555
_082E18AC: .4byte 0x0e002aaa
_082E18B0: .4byte 0x00004e20
_082E18B4:
	ldrh r0, [r1]
	subs r0, 0x1
_082E18B8:
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, 0
	bne _082E18B4
	ldr r0, _082E18F4
	bl _call_via_r5
	lsls r0, 24
	lsrs r4, r0, 16
	movs r0, 0xE0
	lsls r0, 20
	bl _call_via_r5
	lsls r0, 24
	lsrs r0, 24
	orrs r4, r0
	ldr r1, _082E18F8
	movs r0, 0xAA
	strb r0, [r1]
	ldr r2, _082E18FC
	movs r0, 0x55
	strb r0, [r2]
	movs r0, 0xF0
	strb r0, [r1]
	strb r0, [r1]
	add r1, sp, 0x40
	ldr r2, _082E1900
	adds r0, r2, 0
	b _082E1908
	.align 2, 0
_082E18F4: .4byte 0x0e000001
_082E18F8: .4byte 0x0e005555
_082E18FC: .4byte 0x0e002aaa
_082E1900: .4byte 0x00004e20
_082E1904:
	ldrh r0, [r1]
	subs r0, 0x1
_082E1908:
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, 0
	bne _082E1904
	adds r0, r4, 0
	add sp, 0x44
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end ReadFlashID

	thumb_func_start FlashTimerIntr
@ void FlashTimerIntr()
FlashTimerIntr: @ 82E191C
	push {lr}
	ldr r1, _082E193C
	ldrh r0, [r1]
	cmp r0, 0
	beq _082E1938
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _082E1938
	ldr r1, _082E1940
	movs r0, 0x1
	strb r0, [r1]
_082E1938:
	pop {r0}
	bx r0
	.align 2, 0
_082E193C: .4byte 0x03001a72
_082E1940: .4byte 0x03007840
	thumb_func_end FlashTimerIntr

	thumb_func_start SetFlashTimerIntr
@ void SetFlashTimerIntr(u8 timer_id, void ( **irq_timer_func)())
SetFlashTimerIntr: @ 82E1944
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _082E1978
	ldr r0, _082E1968
	strb r1, [r0]
	ldr r1, _082E196C
	ldrb r0, [r0]
	lsls r0, 2
	ldr r3, _082E1970
	adds r0, r3
	str r0, [r1]
	ldr r0, _082E1974
	str r0, [r2]
	movs r0, 0
	b _082E197A
	.align 2, 0
_082E1968: .4byte 0x03001a70
_082E196C: .4byte 0x03001a74
_082E1970: .4byte 0x04000100
_082E1974: .4byte FlashTimerIntr + 1
_082E1978:
	movs r0, 0x1
_082E197A:
	pop {r1}
	bx r1
	thumb_func_end SetFlashTimerIntr

	thumb_func_start StartFlashTimer
StartFlashTimer: @ 82E1980
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _082E1A04
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 1
	ldr r0, [r1]
	adds r2, r0
	ldr r1, _082E1A08
	ldr r0, _082E1A0C
	mov r9, r0
	ldrh r0, [r0]
	strh r0, [r1]
	movs r3, 0
	mov r1, r9
	strh r3, [r1]
	ldr r0, _082E1A10
	mov r8, r0
	ldr r4, [r0]
	strh r3, [r4, 0x2]
	ldr r6, _082E1A14
	ldr r1, _082E1A18
	mov r10, r1
	ldrb r1, [r1]
	movs r5, 0x8
	adds r0, r5, 0
	lsls r0, r1
	adds r1, r0, 0
	ldrh r0, [r6]
	orrs r0, r1
	strh r0, [r6]
	ldr r0, _082E1A1C
	strb r3, [r0]
	ldr r1, _082E1A20
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	ldrh r0, [r2]
	strh r0, [r4]
	adds r0, r4, 0x2
	mov r1, r8
	str r0, [r1]
	ldrh r0, [r2, 0x2]
	strh r0, [r4, 0x2]
	str r4, [r1]
	ldr r1, _082E1A24
	mov r2, r10
	ldrb r0, [r2]
	lsls r5, r0
	strh r5, [r1]
	movs r0, 0x1
	mov r3, r9
	strh r0, [r3]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E1A04: .4byte 0x03007864
_082E1A08: .4byte 0x03001a78
_082E1A0C: .4byte 0x04000208
_082E1A10: .4byte 0x03001a74
_082E1A14: .4byte 0x04000200
_082E1A18: .4byte 0x03001a70
_082E1A1C: .4byte 0x03007840
_082E1A20: .4byte 0x03001a72
_082E1A24: .4byte 0x04000202
	thumb_func_end StartFlashTimer

	thumb_func_start StopFlashTimer
StopFlashTimer: @ 82E1A28
	ldr r3, _082E1A58
	movs r1, 0
	strh r1, [r3]
	ldr r2, _082E1A5C
	ldr r0, [r2]
	strh r1, [r0]
	adds r0, 0x2
	str r0, [r2]
	strh r1, [r0]
	subs r0, 0x2
	str r0, [r2]
	ldr r2, _082E1A60
	ldr r0, _082E1A64
	ldrb r0, [r0]
	movs r1, 0x8
	lsls r1, r0
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	ldr r0, _082E1A68
	ldrh r0, [r0]
	strh r0, [r3]
	bx lr
	.align 2, 0
_082E1A58: .4byte 0x04000208
_082E1A5C: .4byte 0x03001a74
_082E1A60: .4byte 0x04000200
_082E1A64: .4byte 0x03001a70
_082E1A68: .4byte 0x03001a78
	thumb_func_end StopFlashTimer

	thumb_func_start ReadFlash1
@ u8 ReadFlash1(int address)
ReadFlash1: @ 82E1A6C
	ldrb r0, [r0]
	bx lr
	thumb_func_end ReadFlash1

	thumb_func_start SetReadFlash1
@ void SetReadFlash1(u8 ( *target_func)(int address))
SetReadFlash1: @ 82E1A70
	push {lr}
	adds r2, r0, 0
	ldr r1, _082E1A8C
	adds r0, r2, 0x1
	str r0, [r1]
	ldr r3, _082E1A90
	movs r0, 0x1
	eors r3, r0
	ldr r0, _082E1A94
	ldr r1, _082E1A90
	subs r0, r1
	lsls r0, 15
	b _082E1AA4
	.align 2, 0
_082E1A8C: .4byte 0x03007844
_082E1A90: .4byte ReadFlash1 + 1
_082E1A94: .4byte SetReadFlash1 + 1
_082E1A98:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r0, r1, 0x1
	lsls r0, 16
_082E1AA4:
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E1A98
	pop {r0}
	bx r0
	thumb_func_end SetReadFlash1

	thumb_func_start ReadFlash_Core
ReadFlash_Core: @ 82E1AB0
	push {r4,lr}
	adds r4, r0, 0
	subs r3, r2, 0x1
	cmp r2, 0
	beq _082E1ACC
	movs r2, 0x1
	negs r2, r2
_082E1ABE:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, r2
	bne _082E1ABE
_082E1ACC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ReadFlash_Core

	thumb_func_start ReadFlash
ReadFlash: @ 82E1AD4
	push {r4-r7,lr}
	sub sp, 0x80
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	lsls r3, r0, 16
	lsrs r4, r3, 16
	ldr r2, _082E1B20
	ldrh r0, [r2]
	ldr r1, _082E1B24
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _082E1B28
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 10
	cmp r1, r0
	bne _082E1B0C
	lsrs r0, r3, 20
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ands r4, r0
_082E1B0C:
	ldr r3, _082E1B2C
	movs r0, 0x1
	eors r3, r0
	mov r2, sp
	ldr r0, _082E1B30
	ldr r1, _082E1B2C
	subs r0, r1
	lsls r0, 15
	b _082E1B40
	.align 2, 0
_082E1B20: .4byte 0x04000204
_082E1B24: .4byte 0x0000fffc
_082E1B28: .4byte 0x03007850
_082E1B2C: .4byte ReadFlash_Core + 1
_082E1B30: .4byte ReadFlash + 1
_082E1B34:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r0, r1, 0x1
	lsls r0, 16
_082E1B40:
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E1B34
	mov r3, sp
	adds r3, 0x1
	ldr r0, _082E1B6C
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	lsls r4, r0
	adds r0, r4, 0
	movs r2, 0xE0
	lsls r2, 20
	adds r1, r5, r2
	adds r0, r1
	adds r1, r6, 0
	adds r2, r7, 0
	bl _call_via_r3
	add sp, 0x80
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E1B6C: .4byte 0x03007850
	thumb_func_end ReadFlash

	thumb_func_start VerifyFlashSector_Core
VerifyFlashSector_Core: @ 82E1B70
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	subs r4, r2, 0x1
	cmp r2, 0
	beq _082E1B96
	movs r2, 0x1
	negs r2, r2
_082E1B80:
	ldrb r1, [r3]
	ldrb r0, [r5]
	adds r5, 0x1
	adds r3, 0x1
	cmp r1, r0
	beq _082E1B90
	subs r0, r3, 0x1
	b _082E1B98
_082E1B90:
	subs r4, 0x1
	cmp r4, r2
	bne _082E1B80
_082E1B96:
	movs r0, 0
_082E1B98:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end VerifyFlashSector_Core

	thumb_func_start VerifyFlashSector
VerifyFlashSector: @ 82E1BA0
	push {r4,r5,lr}
	sub sp, 0x100
	adds r5, r1, 0
	lsls r3, r0, 16
	lsrs r4, r3, 16
	ldr r2, _082E1BE8
	ldrh r0, [r2]
	ldr r1, _082E1BEC
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _082E1BF0
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 10
	cmp r1, r0
	bne _082E1BD4
	lsrs r0, r3, 20
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ands r4, r0
_082E1BD4:
	ldr r3, _082E1BF4
	movs r0, 0x1
	eors r3, r0
	mov r2, sp
	ldr r0, _082E1BF8
	ldr r1, _082E1BF4
	subs r0, r1
	lsls r0, 15
	b _082E1C08
	.align 2, 0
_082E1BE8: .4byte 0x04000204
_082E1BEC: .4byte 0x0000fffc
_082E1BF0: .4byte 0x03007850
_082E1BF4: .4byte VerifyFlashSector_Core + 1
_082E1BF8: .4byte VerifyFlashSector + 1
_082E1BFC:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r0, r1, 0x1
	lsls r0, 16
_082E1C08:
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E1BFC
	mov r3, sp
	adds r3, 0x1
	ldr r0, _082E1C34
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r4, r1
	adds r1, r4, 0
	movs r2, 0xE0
	lsls r2, 20
	adds r1, r2
	ldrh r2, [r0, 0x4]
	adds r0, r5, 0
	bl _call_via_r3
	add sp, 0x100
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_082E1C34: .4byte 0x03007850
	thumb_func_end VerifyFlashSector

	thumb_func_start VerifyFlashSectorFirstNBytes
VerifyFlashSectorFirstNBytes: @ 82E1C38
	push {r4-r6,lr}
	sub sp, 0x100
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r2, r0, 16
	lsrs r4, r2, 16
	ldr r0, _082E1C80
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 10
	cmp r1, r0
	bne _082E1C60
	lsrs r0, r2, 20
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ands r4, r0
_082E1C60:
	ldr r2, _082E1C84
	ldrh r0, [r2]
	ldr r1, _082E1C88
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _082E1C8C
	movs r0, 0x1
	eors r3, r0
	mov r2, sp
	ldr r0, _082E1C90
	ldr r1, _082E1C8C
	subs r0, r1
	lsls r0, 15
	b _082E1CA0
	.align 2, 0
_082E1C80: .4byte 0x03007850
_082E1C84: .4byte 0x04000204
_082E1C88: .4byte 0x0000fffc
_082E1C8C: .4byte VerifyFlashSector_Core + 1
_082E1C90: .4byte VerifyFlashSector + 1
_082E1C94:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r0, r1, 0x1
	lsls r0, 16
_082E1CA0:
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E1C94
	mov r3, sp
	adds r3, 0x1
	ldr r0, _082E1CCC
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	lsls r4, r1
	adds r1, r4, 0
	movs r0, 0xE0
	lsls r0, 20
	adds r1, r0
	adds r0, r5, 0
	adds r2, r6, 0
	bl _call_via_r3
	add sp, 0x100
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_082E1CCC: .4byte 0x03007850
	thumb_func_end VerifyFlashSectorFirstNBytes

	thumb_func_start ProgramFlashSectorsAndVerify
ProgramFlashSectorsAndVerify: @ 82E1CD0
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 16
	lsrs r4, r0, 16
	movs r6, 0
	b _082E1CE2
_082E1CDC:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_082E1CE2:
	cmp r6, 0x2
	bhi _082E1D08
	ldr r0, _082E1D10
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _082E1CDC
	adds r0, r4, 0
	adds r1, r5, 0
	bl VerifyFlashSector
	adds r2, r0, 0
	cmp r2, 0
	bne _082E1CDC
_082E1D08:
	adds r0, r2, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_082E1D10: .4byte 0x0300784c
	thumb_func_end ProgramFlashSectorsAndVerify

	thumb_func_start ProgramFlashSectorsVerifyFirstNBytes
ProgramFlashSectorsVerifyFirstNBytes: @ 82E1D14
	push {r4-r7,lr}
	adds r5, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	lsrs r4, r0, 16
	movs r6, 0
	b _082E1D28
_082E1D22:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_082E1D28:
	cmp r6, 0x2
	bhi _082E1D50
	ldr r0, _082E1D58
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _082E1D22
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl VerifyFlashSectorFirstNBytes
	adds r3, r0, 0
	cmp r3, 0
	bne _082E1D22
_082E1D50:
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E1D58: .4byte 0x0300784c
	thumb_func_end ProgramFlashSectorsVerifyFirstNBytes

	thumb_func_start IdentifyFlash
@ _BOOL2 IdentifyFlash()
IdentifyFlash: @ 82E1D5C
	push {r4,lr}
	ldr r2, _082E1D7C
	ldrh r0, [r2]
	ldr r1, _082E1D80
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2]
	bl ReadFlashID
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, _082E1D84
	movs r4, 0x1
	b _082E1D8A
	.align 2, 0
_082E1D7C: .4byte 0x04000204
_082E1D80: .4byte 0x0000fffc
_082E1D84: .4byte 0x089a30d0
_082E1D88:
	adds r2, 0x4
_082E1D8A:
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _082E1D9E
	ldrh r0, [r1, 0x2C]
	cmp r3, r0
	bne _082E1D88
	movs r4, 0
_082E1D9E:
	ldr r1, _082E1DE0
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _082E1DE4
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldr r1, _082E1DE8
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	str r0, [r1]
	ldr r1, _082E1DEC
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	str r0, [r1]
	ldr r1, _082E1DF0
	ldr r0, [r2]
	ldr r0, [r0, 0x10]
	str r0, [r1]
	ldr r1, _082E1DF4
	ldr r0, [r2]
	ldr r0, [r0, 0x14]
	str r0, [r1]
	ldr r1, _082E1DF8
	ldr r0, [r2]
	adds r0, 0x18
	str r0, [r1]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082E1DE0: .4byte 0x03007854
_082E1DE4: .4byte 0x0300784c
_082E1DE8: .4byte 0x0300785c
_082E1DEC: .4byte 0x03007860
_082E1DF0: .4byte 0x03007848
_082E1DF4: .4byte 0x03007864
_082E1DF8: .4byte 0x03007850
	thumb_func_end IdentifyFlash

	thumb_func_start PollingSR_COMMON
PollingSR_COMMON: @ 82E1DFC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0
	mov r8, r0
	adds r0, r7, 0
	bl StartFlashTimer
	ldr r6, _082E1E20
	ldr r1, _082E1E24
	mov r9, r1
	b _082E1E60
	.align 2, 0
_082E1E20: .4byte 0x03007844
_082E1E24: .4byte 0x0e005555
_082E1E28:
	movs r0, 0xF0
	mov r1, r9
	strb r0, [r1]
	movs r0, 0xA0
	lsls r0, 8
	b _082E1E56
_082E1E34:
	ldr r0, _082E1E5C
	ldrb r0, [r0]
	cmp r0, 0
	beq _082E1E60
	ldr r1, [r6]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	beq _082E1E88
	movs r0, 0xF0
	mov r1, r9
	strb r0, [r1]
	movs r0, 0xC0
	lsls r0, 8
_082E1E56:
	orrs r7, r0
	mov r8, r7
	b _082E1E88
	.align 2, 0
_082E1E5C: .4byte 0x03007840
_082E1E60:
	ldr r1, [r6]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r5
	beq _082E1E88
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _082E1E34
	ldr r1, [r6]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _082E1E28
_082E1E88:
	bl StopFlashTimer
	mov r0, r8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end PollingSR_COMMON

	thumb_func_start EraseFlashChip
EraseFlashChip: @ 82E1E9C
	push {r4-r6,lr}
	sub sp, 0x40
	ldr r5, _082E1EF8
	ldrh r1, [r5]
	ldr r6, _082E1EFC
	ands r1, r6
	ldr r0, _082E1F00
	ldr r0, [r0]
	ldrh r0, [r0, 0x10]
	orrs r1, r0
	strh r1, [r5]
	ldr r1, _082E1F04
	movs r4, 0xAA
	strb r4, [r1]
	ldr r3, _082E1F08
	movs r2, 0x55
	strb r2, [r3]
	movs r0, 0x80
	strb r0, [r1]
	strb r4, [r1]
	strb r2, [r3]
	movs r0, 0x10
	strb r0, [r1]
	mov r0, sp
	bl SetReadFlash1
	ldr r0, _082E1F0C
	movs r1, 0xE0
	lsls r1, 20
	ldr r3, [r0]
	movs r0, 0x3
	movs r2, 0xFF
	bl _call_via_r3
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r5]
	ands r1, r6
	movs r2, 0x3
	orrs r1, r2
	strh r1, [r5]
	add sp, 0x40
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_082E1EF8: .4byte 0x04000204
_082E1EFC: .4byte 0x0000fffc
_082E1F00: .4byte 0x03007850
_082E1F04: .4byte 0x0e005555
_082E1F08: .4byte 0x0e002aaa
_082E1F0C: .4byte 0x03007848
	thumb_func_end EraseFlashChip

	thumb_func_start EraseFlashSector
EraseFlashSector: @ 82E1F10
	push {r4-r7,lr}
	sub sp, 0x40
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _082E1F28
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r6, r0
	bcc _082E1F30
	ldr r0, _082E1F2C
	b _082E1FD0
	.align 2, 0
_082E1F28: .4byte 0x03007850
_082E1F2C: .4byte 0x000080ff
_082E1F30:
	lsrs r0, r6, 4
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ands r6, r0
	movs r7, 0
_082E1F40:
	ldr r3, _082E1FA8
	ldrh r1, [r3]
	ldr r0, _082E1FAC
	ands r1, r0
	ldr r0, _082E1FB0
	ldr r2, [r0]
	ldrh r0, [r2, 0x10]
	orrs r1, r0
	strh r1, [r3]
	ldrb r4, [r2, 0x8]
	adds r0, r6, 0
	lsls r0, r4
	adds r4, r0, 0
	movs r0, 0xE0
	lsls r0, 20
	adds r4, r0
	ldr r1, _082E1FB4
	movs r5, 0xAA
	strb r5, [r1]
	ldr r3, _082E1FB8
	movs r2, 0x55
	strb r2, [r3]
	movs r0, 0x80
	strb r0, [r1]
	strb r5, [r1]
	strb r2, [r3]
	movs r0, 0x30
	strb r0, [r4]
	mov r0, sp
	bl SetReadFlash1
	ldr r0, _082E1FBC
	ldr r3, [r0]
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0xFF
	bl _call_via_r3
	lsls r0, 16
	lsrs r3, r0, 16
	movs r0, 0xA0
	lsls r0, 8
	ands r0, r3
	cmp r0, 0
	beq _082E1FC0
	cmp r7, 0x3
	bhi _082E1FC0
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	b _082E1F40
	.align 2, 0
_082E1FA8: .4byte 0x04000204
_082E1FAC: .4byte 0x0000fffc
_082E1FB0: .4byte 0x03007850
_082E1FB4: .4byte 0x0e005555
_082E1FB8: .4byte 0x0e002aaa
_082E1FBC: .4byte 0x03007848
_082E1FC0:
	ldr r2, _082E1FD8
	ldrh r0, [r2]
	ldr r1, _082E1FDC
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2]
	adds r0, r3, 0
_082E1FD0:
	add sp, 0x40
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E1FD8: .4byte 0x04000204
_082E1FDC: .4byte 0x0000fffc
	thumb_func_end EraseFlashSector

	thumb_func_start ProgramFlashByte
ProgramFlashByte: @ 82E1FE0
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r1, 0
	lsls r1, r0, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r5, _082E2050
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	cmp r6, r0
	bcs _082E2068
	lsrs r0, r1, 20
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ldr r1, [r5]
	ands r4, r0
	ldrb r1, [r1, 0x8]
	lsls r4, r1
	movs r1, 0xE0
	lsls r1, 20
	adds r0, r6, r1
	adds r4, r0
	mov r0, sp
	bl SetReadFlash1
	ldr r2, _082E2054
	ldrh r0, [r2]
	ldr r1, _082E2058
	ands r0, r1
	ldr r1, [r5]
	ldrh r1, [r1, 0x10]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _082E205C
	movs r0, 0xAA
	strb r0, [r2]
	ldr r1, _082E2060
	movs r0, 0x55
	strb r0, [r1]
	movs r0, 0xA0
	strb r0, [r2]
	strb r7, [r4]
	ldr r0, _082E2064
	ldr r3, [r0]
	movs r0, 0x1
	adds r1, r4, 0
	adds r2, r7, 0
	bl _call_via_r3
	lsls r0, 16
	lsrs r0, 16
	b _082E206C
	.align 2, 0
_082E2050: .4byte 0x03007850
_082E2054: .4byte 0x04000204
_082E2058: .4byte 0x0000fffc
_082E205C: .4byte 0x0e005555
_082E2060: .4byte 0x0e002aaa
_082E2064: .4byte 0x03007848
_082E2068:
	movs r0, 0x80
	lsls r0, 8
_082E206C:
	add sp, 0x40
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ProgramFlashByte

	thumb_func_start ProgramFlashByteInternal
ProgramFlashByteInternal: @ 82E2074
	push {r4,lr}
	ldr r4, _082E20A0
	movs r2, 0xAA
	strb r2, [r4]
	ldr r3, _082E20A4
	movs r2, 0x55
	strb r2, [r3]
	movs r2, 0xA0
	strb r2, [r4]
	ldrb r2, [r0]
	strb r2, [r1]
	ldr r3, _082E20A8
	ldrb r2, [r0]
	ldr r3, [r3]
	movs r0, 0x1
	bl _call_via_r3
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082E20A0: .4byte 0x0e005555
_082E20A4: .4byte 0x0e002aaa
_082E20A8: .4byte 0x03007848
	thumb_func_end ProgramFlashByteInternal

	thumb_func_start ProgramFlashSector
ProgramFlashSector: @ 82E20AC
	push {r4-r7,lr}
	sub sp, 0x40
	adds r7, r1, 0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, _082E20C4
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r4, r0
	bcc _082E20CC
	ldr r0, _082E20C8
	b _082E2146
	.align 2, 0
_082E20C4: .4byte 0x03007850
_082E20C8: .4byte 0x000080ff
_082E20CC:
	adds r0, r4, 0
	bl EraseFlashSector
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _082E2144
	lsrs r0, r4, 4
	lsls r0, 24
	lsrs r0, 24
	bl SwitchFlashBank
	movs r0, 0xF
	ands r4, r0
	mov r0, sp
	bl SetReadFlash1
	ldr r3, _082E2114
	ldrh r1, [r3]
	ldr r0, _082E2118
	ands r1, r0
	ldr r0, _082E211C
	ldr r2, [r0]
	ldrh r0, [r2, 0x10]
	orrs r1, r0
	strh r1, [r3]
	ldr r1, _082E2120
	ldr r0, [r2, 0x4]
	strh r0, [r1]
	ldrb r0, [r2, 0x8]
	lsls r4, r0
	movs r0, 0xE0
	lsls r0, 20
	adds r4, r0
	adds r6, r1, 0
	b _082E212E
	.align 2, 0
_082E2114: .4byte 0x04000204
_082E2118: .4byte 0x0000fffc
_082E211C: .4byte 0x03007850
_082E2120: .4byte 0x03007858
_082E2124:
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	adds r7, 0x1
	adds r4, 0x1
_082E212E:
	ldrh r0, [r6]
	cmp r0, 0
	beq _082E2144
	adds r0, r7, 0
	adds r1, r4, 0
	bl ProgramFlashByteInternal
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _082E2124
_082E2144:
	adds r0, r5, 0
_082E2146:
	add sp, 0x40
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ProgramFlashSector
