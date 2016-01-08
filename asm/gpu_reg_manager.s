	thumb_func_start InitGpuRegManager
; void InitGpuRegManager()
InitGpuRegManager: ; 8000FE4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r2, 0
	ldr r7, =0x030008d8
	ldr r0, =0x030008d9
	mov r12, r0
	ldr r1, =0x030008da
	mov r8, r1
	ldr r6, =0x03000818
	movs r5, 0
	ldr r4, =0x03000878
	movs r3, 0xFF
_08000FFE:
	adds r0, r2, r6
	strb r5, [r0]
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x5F
	ble _08000FFE
	movs r0, 0
	strb r0, [r7]
	mov r1, r12
	strb r0, [r1]
	movs r0, 0
	mov r1, r8
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitGpuRegManager

	thumb_func_start CopyBufferedValueToGpuReg
; void CopyBufferedValueToGpuReg(u8 reg)
CopyBufferedValueToGpuReg: ; 800103C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bne _08001068
	ldr r2, =0x04000004
	ldrh r1, [r2]
	ldr r0, =0x0000ffe7
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0300081c
	ldrh r0, [r2]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	b _08001076
	.pool
_08001068:
	movs r0, 0x80
	lsls r0, 19
	adds r0, r2, r0
	ldr r1, =0x03000818
	adds r1, r2, r1
	ldrh r1, [r1]
	strh r1, [r0]
_08001076:
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyBufferedValueToGpuReg

	thumb_func_start CopyBufferedValuesToGpuRegs
; void CopyBufferedValuesToGpuRegs()
CopyBufferedValuesToGpuRegs: ; 8001080
	push {r4,r5,lr}
	ldr r0, =0x030008d8
	ldrb r0, [r0]
	cmp r0, 0
	bne _080010A4
	movs r5, 0
_0800108C:
	ldr r0, =0x03000878
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080010A4
	bl CopyBufferedValueToGpuReg
	movs r0, 0xFF
	strb r0, [r4]
	adds r5, 0x1
	cmp r5, 0x5F
	ble _0800108C
_080010A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyBufferedValuesToGpuRegs

	thumb_func_start SetGpuReg
; void SetGpuReg(u8 reg, u16 value)
SetGpuReg: ; 80010B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r4, 0x5F
	bhi _08001130
	ldr r0, =0x03000818
	adds r0, r4, r0
	strh r1, [r0]
	ldr r0, =0x04000006
	ldrh r1, [r0]
	movs r0, 0xFF
	ands r0, r1
	subs r0, 0xA1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x40
	bls _080010E8
	movs r0, 0x80
	lsls r0, 19
	ldrh r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080010FE
_080010E8:
	adds r0, r4, 0
	bl CopyBufferedValueToGpuReg
	b _08001130
	.pool
_080010F8:
	movs r0, 0
	strb r0, [r5]
	b _08001130
_080010FE:
	ldr r2, =0x030008d8
	movs r0, 0x1
	strb r0, [r2]
	movs r3, 0
	ldr r0, =0x03000878
	ldrb r1, [r0]
	adds r5, r2, 0
	adds r2, r0, 0
	cmp r1, 0xFF
	beq _08001128
	adds r1, r2, 0
_08001114:
	ldrb r0, [r1]
	cmp r0, r4
	beq _080010F8
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x5F
	bgt _08001128
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08001114
_08001128:
	adds r0, r3, r2
	movs r1, 0
	strb r4, [r0]
	strb r1, [r5]
_08001130:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetGpuReg

	thumb_func_start SetGpuReg_ForcedBlank
; void SetGpuReg_ForcedBlank(u8 reg, u16 value)
SetGpuReg_ForcedBlank: ; 8001140
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r4, 0x5F
	bhi _080011A8
	ldr r0, =0x03000818
	adds r0, r4, r0
	strh r1, [r0]
	movs r0, 0x80
	lsls r0, 19
	ldrh r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08001176
	adds r0, r4, 0
	bl CopyBufferedValueToGpuReg
	b _080011A8
	.pool
_08001170:
	movs r0, 0
	strb r0, [r5]
	b _080011A8
_08001176:
	ldr r2, =0x030008d8
	movs r0, 0x1
	strb r0, [r2]
	movs r3, 0
	ldr r0, =0x03000878
	ldrb r1, [r0]
	adds r5, r2, 0
	adds r2, r0, 0
	cmp r1, 0xFF
	beq _080011A0
	adds r1, r2, 0
_0800118C:
	ldrb r0, [r1]
	cmp r0, r4
	beq _08001170
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x5F
	bgt _080011A0
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0800118C
_080011A0:
	adds r0, r3, r2
	movs r1, 0
	strb r4, [r0]
	strb r1, [r5]
_080011A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetGpuReg_ForcedBlank

	thumb_func_start GetGpuReg
; u16 GetGpuReg(u8 reg)
GetGpuReg: ; 80011B8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r1, 0x4
	bne _080011CC
	ldr r0, =0x04000004
	b _080011DE
	.pool
_080011CC:
	cmp r1, 0x6
	beq _080011DC
	ldr r0, =0x03000818
	adds r0, r1, r0
	ldrh r0, [r0]
	b _080011E0
	.pool
_080011DC:
	ldr r0, =0x04000006
_080011DE:
	ldrh r0, [r0]
_080011E0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGpuReg

	thumb_func_start SetGpuRegBits
; void SetGpuRegBits(u8 reg, u16 mask)
SetGpuRegBits: ; 80011E8
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x03000818
	adds r1, r0, r1
	ldrh r1, [r1]
	orrs r1, r2
	lsls r1, 16
	lsrs r1, 16
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetGpuRegBits

	thumb_func_start ClearGpuRegBits
; void ClearGpuRegBits(u8 reg, u16 mask)
ClearGpuRegBits: ; 8001208
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	ldr r1, =0x03000818
	adds r1, r0, r1
	ldrh r1, [r1]
	lsrs r2, 16
	bics r1, r2
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearGpuRegBits

	thumb_func_start SyncRegIE
; void SyncRegIE()
SyncRegIE: ; 8001228
	push {r4,r5,lr}
	ldr r5, =0x030008d9
	ldrb r0, [r5]
	cmp r0, 0
	beq _08001246
	ldr r2, =0x04000208
	ldrh r1, [r2]
	movs r4, 0
	strh r4, [r2]
	ldr r3, =0x04000200
	ldr r0, =0x030008da
	ldrh r0, [r0]
	strh r0, [r3]
	strh r1, [r2]
	strb r4, [r5]
_08001246:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SyncRegIE

	thumb_func_start EnableInterrupts
; void EnableInterrupts(u16 mask)
EnableInterrupts: ; 800125C
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =0x030008da
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r1, =0x030008d9
	movs r0, 0x1
	strb r0, [r1]
	bl SyncRegIE
	ldrh r0, [r4]
	bl UpdateRegDispstatIntrBits
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end EnableInterrupts

	thumb_func_start DisableInterrupts
; void DisableInterrupts(u16 mask)
DisableInterrupts: ; 8001288
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =0x030008da
	ldrh r1, [r4]
	bics r1, r0
	strh r1, [r4]
	ldr r1, =0x030008d9
	movs r0, 0x1
	strb r0, [r1]
	bl SyncRegIE
	ldrh r0, [r4]
	bl UpdateRegDispstatIntrBits
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisableInterrupts

	thumb_func_start UpdateRegDispstatIntrBits
; void UpdateRegDispstatIntrBits(u16 mask)
UpdateRegDispstatIntrBits: ; 80012B4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x4
	bl GetGpuReg
	movs r2, 0x18
	ands r2, r0
	movs r1, 0x1
	ands r1, r4
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, 31
	movs r0, 0x8
	ands r1, r0
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _080012E0
	movs r0, 0x10
	orrs r1, r0
_080012E0:
	cmp r2, r1
	beq _080012EA
	movs r0, 0x4
	bl SetGpuReg
_080012EA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end UpdateRegDispstatIntrBits
