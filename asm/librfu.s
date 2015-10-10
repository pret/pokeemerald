	thumb_func_start STWI_init_all
STWI_init_all: ; 82E2A18
	push {r4,lr}
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	cmp r2, 0x1
	bne _082E2A54
	adds r2, r3, 0
	adds r2, 0xE8
	str r2, [r1]
	ldr r1, _082E2A40
	ldr r0, _082E2A44
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, _082E2A48
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r1, _082E2A4C
	ldr r2, _082E2A50
	adds r0, r3, r2
	b _082E2A5E
	.align 2, 0
_082E2A40: .4byte 0x040000d4
_082E2A44: .4byte IntrSIO32
_082E2A48: .4byte 0x800004b0
_082E2A4C: .4byte 0x03007868
_082E2A50: .4byte 0x00000a48
_082E2A54:
	ldr r0, _082E2AD8
	str r0, [r1]
	ldr r1, _082E2ADC
	adds r0, r3, 0
	adds r0, 0xE8
_082E2A5E:
	str r0, [r1]
	adds r2, r1, 0
	ldr r1, [r2]
	str r3, [r1, 0x28]
	adds r0, r3, 0
	adds r0, 0x74
	str r0, [r1, 0x24]
	ldrb r0, [r1, 0x14]
	movs r4, 0
	movs r0, 0x1
	strb r0, [r1, 0x14]
	ldr r0, [r2]
	str r4, [r0]
	strb r4, [r0, 0x4]
	ldr r0, [r2]
	strb r4, [r0, 0x5]
	ldr r0, [r2]
	strb r4, [r0, 0x7]
	ldr r0, [r2]
	strb r4, [r0, 0x8]
	ldr r0, [r2]
	strb r4, [r0, 0x9]
	ldr r0, [r2]
	str r4, [r0, 0xC]
	ldrb r1, [r0, 0x10]
	strb r4, [r0, 0x10]
	ldr r0, [r2]
	ldrh r1, [r0, 0x12]
	movs r1, 0
	strh r4, [r0, 0x12]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	adds r0, 0x2C
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r1, _082E2AE0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0xC
	ldr r2, _082E2AE4
	adds r0, r2, 0
	strh r0, [r1]
	bl STWI_init_Callback_M
	bl STWI_init_Callback_S
	ldr r3, _082E2AE8
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, _082E2AEC
	ldrh r0, [r4]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E2AD8: .4byte IntrSIO32
_082E2ADC: .4byte 0x03007868
_082E2AE0: .4byte 0x04000134
_082E2AE4: .4byte 0x00005003
_082E2AE8: .4byte 0x04000208
_082E2AEC: .4byte 0x04000200
	thumb_func_end STWI_init_all

	thumb_func_start STWI_init_timer
STWI_init_timer: ; 82E2AF0
	push {r4,r5,lr}
	ldr r2, _082E2B1C
	str r2, [r0]
	ldr r5, _082E2B20
	ldr r0, [r5]
	movs r4, 0
	strb r1, [r0, 0xA]
	ldr r3, _082E2B24
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, _082E2B28
	ldr r1, [r5]
	movs r0, 0x8
	ldrb r1, [r1, 0xA]
	lsls r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E2B1C: .4byte STWI_intr_timer + 1
_082E2B20: .4byte 0x03007868
_082E2B24: .4byte 0x04000208
_082E2B28: .4byte 0x04000200
	thumb_func_end STWI_init_timer

	thumb_func_start AgbRFU_SoftReset
AgbRFU_SoftReset: ; 82E2B2C
	push {r4,r5,lr}
	ldr r5, _082E2BC4
	movs r1, 0x80
	lsls r1, 8
	adds r0, r1, 0
	strh r0, [r5]
	ldr r2, _082E2BC8
	adds r0, r2, 0
	strh r0, [r5]
	ldr r1, _082E2BCC
	ldr r0, [r1]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r3, _082E2BD0
	adds r2, r0, r3
	ldr r4, _082E2BD4
	adds r3, r0, r4
	movs r0, 0
	strh r0, [r3]
	strh r0, [r2]
	movs r0, 0x83
	strh r0, [r3]
	ldrh r0, [r2]
	adds r4, r1, 0
	cmp r0, 0x11
	bhi _082E2B6C
	ldr r0, _082E2BD8
	adds r1, r0, 0
_082E2B64:
	strh r1, [r5]
	ldrh r0, [r2]
	cmp r0, 0x11
	bls _082E2B64
_082E2B6C:
	movs r0, 0x3
	strh r0, [r3]
	ldr r1, _082E2BC4
	ldr r2, _082E2BC8
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0xC
	ldr r3, _082E2BDC
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, [r4]
	movs r2, 0
	str r2, [r0]
	strb r2, [r0, 0x4]
	ldr r0, [r4]
	strb r2, [r0, 0x5]
	ldr r0, [r4]
	strb r2, [r0, 0x6]
	ldr r0, [r4]
	strb r2, [r0, 0x7]
	ldr r0, [r4]
	strb r2, [r0, 0x8]
	ldr r0, [r4]
	strb r2, [r0, 0x9]
	ldr r0, [r4]
	str r2, [r0, 0xC]
	ldrb r1, [r0, 0x10]
	strb r2, [r0, 0x10]
	ldr r1, [r4]
	ldrh r0, [r1, 0x12]
	movs r3, 0
	strh r2, [r1, 0x12]
	ldrb r0, [r1, 0x14]
	movs r0, 0x1
	strb r0, [r1, 0x14]
	ldr r0, [r4]
	strb r3, [r0, 0x15]
	ldr r0, [r4]
	adds r0, 0x2C
	ldrb r1, [r0]
	strb r3, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E2BC4: .4byte 0x04000134
_082E2BC8: .4byte 0x000080a0
_082E2BCC: .4byte 0x03007868
_082E2BD0: .4byte 0x04000100
_082E2BD4: .4byte 0x04000102
_082E2BD8: .4byte 0x000080a2
_082E2BDC: .4byte 0x00005003
	thumb_func_end AgbRFU_SoftReset

	thumb_func_start STWI_set_MS_mode
STWI_set_MS_mode: ; 82E2BE0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _082E2BF0
	ldr r1, [r1]
	ldrb r2, [r1, 0x14]
	strb r0, [r1, 0x14]
	bx lr
	.align 2, 0
_082E2BF0: .4byte 0x03007868
	thumb_func_end STWI_set_MS_mode

	thumb_func_start STWI_read_status
STWI_read_status: ; 82E2BF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _082E2C20
	cmp r0, 0x1
	bgt _082E2C0A
	cmp r0, 0
	beq _082E2C14
	b _082E2C48
_082E2C0A:
	cmp r1, 0x2
	beq _082E2C2C
	cmp r1, 0x3
	beq _082E2C3C
	b _082E2C48
_082E2C14:
	ldr r0, _082E2C1C
	ldr r0, [r0]
	ldrh r0, [r0, 0x12]
	b _082E2C4A
	.align 2, 0
_082E2C1C: .4byte 0x03007868
_082E2C20:
	ldr r0, _082E2C28
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	b _082E2C4A
	.align 2, 0
_082E2C28: .4byte 0x03007868
_082E2C2C:
	ldr r0, _082E2C38
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r0, 16
	lsrs r0, 16
	b _082E2C4A
	.align 2, 0
_082E2C38: .4byte 0x03007868
_082E2C3C:
	ldr r0, _082E2C44
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	b _082E2C4A
	.align 2, 0
_082E2C44: .4byte 0x03007868
_082E2C48:
	ldr r0, _082E2C50
_082E2C4A:
	pop {r1}
	bx r1
	.align 2, 0
_082E2C50: .4byte 0x0000ffff
	thumb_func_end STWI_read_status

	thumb_func_start STWI_init_Callback_M
STWI_init_Callback_M: ; 82E2C54
	push {lr}
	movs r0, 0
	bl STWI_set_Callback_M
	pop {r0}
	bx r0
	thumb_func_end STWI_init_Callback_M

	thumb_func_start STWI_init_Callback_S
STWI_init_Callback_S: ; 82E2C60
	push {lr}
	movs r0, 0
	bl STWI_set_Callback_S
	pop {r0}
	bx r0
	thumb_func_end STWI_init_Callback_S

	thumb_func_start STWI_set_Callback_M
STWI_set_Callback_M: ; 82E2C6C
	ldr r1, _082E2C74
	ldr r1, [r1]
	str r0, [r1, 0x18]
	bx lr
	.align 2, 0
_082E2C74: .4byte 0x03007868
	thumb_func_end STWI_set_Callback_M

	thumb_func_start STWI_set_Callback_S
STWI_set_Callback_S: ; 82E2C78
	ldr r1, _082E2C80
	ldr r1, [r1]
	str r0, [r1, 0x1C]
	bx lr
	.align 2, 0
_082E2C80: .4byte 0x03007868
	thumb_func_end STWI_set_Callback_S

	thumb_func_start STWI_set_Callback_ID
STWI_set_Callback_ID: ; 82E2C84
	ldr r1, _082E2C8C
	ldr r1, [r1]
	str r0, [r1, 0x20]
	bx lr
	.align 2, 0
_082E2C8C: .4byte 0x03007868
	thumb_func_end STWI_set_Callback_ID

	thumb_func_start STWI_poll_CommandEnd
STWI_poll_CommandEnd: ; 82E2C90
	push {lr}
	ldr r0, _082E2CB4
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _082E2CAA
	adds r1, r2, 0
_082E2CA4:
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _082E2CA4
_082E2CAA:
	ldr r0, [r3]
	ldrh r0, [r0, 0x12]
	pop {r1}
	bx r1
	.align 2, 0
_082E2CB4: .4byte 0x03007868
	thumb_func_end STWI_poll_CommandEnd

	thumb_func_start STWI_send_ResetREQ
STWI_send_ResetREQ: ; 82E2CB8
	push {lr}
	movs r0, 0x10
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2CD2
	ldr r0, _082E2CD8
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2CD2:
	pop {r0}
	bx r0
	.align 2, 0
_082E2CD8: .4byte 0x03007868
	thumb_func_end STWI_send_ResetREQ

	thumb_func_start STWI_send_LinkStatusREQ
STWI_send_LinkStatusREQ: ; 82E2CDC
	push {lr}
	movs r0, 0x11
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2CF6
	ldr r0, _082E2CFC
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2CF6:
	pop {r0}
	bx r0
	.align 2, 0
_082E2CFC: .4byte 0x03007868
	thumb_func_end STWI_send_LinkStatusREQ

	thumb_func_start STWI_send_VersionStatusREQ
STWI_send_VersionStatusREQ: ; 82E2D00
	push {lr}
	movs r0, 0x12
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2D1A
	ldr r0, _082E2D20
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2D1A:
	pop {r0}
	bx r0
	.align 2, 0
_082E2D20: .4byte 0x03007868
	thumb_func_end STWI_send_VersionStatusREQ

	thumb_func_start STWI_send_SystemStatusREQ
STWI_send_SystemStatusREQ: ; 82E2D24
	push {lr}
	movs r0, 0x13
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2D3E
	ldr r0, _082E2D44
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2D3E:
	pop {r0}
	bx r0
	.align 2, 0
_082E2D44: .4byte 0x03007868
	thumb_func_end STWI_send_SystemStatusREQ

	thumb_func_start STWI_send_SlotStatusREQ
STWI_send_SlotStatusREQ: ; 82E2D48
	push {lr}
	movs r0, 0x14
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2D62
	ldr r0, _082E2D68
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2D62:
	pop {r0}
	bx r0
	.align 2, 0
_082E2D68: .4byte 0x03007868
	thumb_func_end STWI_send_SlotStatusREQ

	thumb_func_start STWI_send_ConfigStatusREQ
STWI_send_ConfigStatusREQ: ; 82E2D6C
	push {lr}
	movs r0, 0x15
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2D86
	ldr r0, _082E2D8C
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2D86:
	pop {r0}
	bx r0
	.align 2, 0
_082E2D8C: .4byte 0x03007868
	thumb_func_end STWI_send_ConfigStatusREQ

	thumb_func_start STWI_send_GameConfigREQ
STWI_send_GameConfigREQ: ; 82E2D90
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x16
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E2DDC
	ldr r2, _082E2DE4
	ldr r1, [r2]
	movs r0, 0x6
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r1, [r0, 0x24]
	adds r1, 0x4
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	adds r4, 0x2
	movs r2, 0xD
_082E2DBA:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _082E2DBA
	movs r2, 0x7
_082E2DCA:
	ldrb r0, [r5]
	strb r0, [r1]
	adds r1, 0x1
	adds r5, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _082E2DCA
	bl STWI_start_Command
_082E2DDC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E2DE4: .4byte 0x03007868
	thumb_func_end STWI_send_GameConfigREQ

	thumb_func_start STWI_send_SystemConfigREQ
STWI_send_SystemConfigREQ: ; 82E2DE8
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r4, r2, 24
	movs r0, 0x17
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E2E1E
	ldr r2, _082E2E24
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r0, [r0, 0x24]
	adds r0, 0x4
	strb r4, [r0]
	adds r0, 0x1
	strb r5, [r0]
	adds r0, 0x1
	strh r6, [r0]
	bl STWI_start_Command
_082E2E1E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E2E24: .4byte 0x03007868
	thumb_func_end STWI_send_SystemConfigREQ

	thumb_func_start STWI_send_SC_StartREQ
STWI_send_SC_StartREQ: ; 82E2E28
	push {lr}
	movs r0, 0x19
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2E42
	ldr r0, _082E2E48
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2E42:
	pop {r0}
	bx r0
	.align 2, 0
_082E2E48: .4byte 0x03007868
	thumb_func_end STWI_send_SC_StartREQ

	thumb_func_start STWI_send_SC_PollingREQ
STWI_send_SC_PollingREQ: ; 82E2E4C
	push {lr}
	movs r0, 0x1A
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2E66
	ldr r0, _082E2E6C
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2E66:
	pop {r0}
	bx r0
	.align 2, 0
_082E2E6C: .4byte 0x03007868
	thumb_func_end STWI_send_SC_PollingREQ

	thumb_func_start STWI_send_SC_EndREQ
STWI_send_SC_EndREQ: ; 82E2E70
	push {lr}
	movs r0, 0x1B
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2E8A
	ldr r0, _082E2E90
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2E8A:
	pop {r0}
	bx r0
	.align 2, 0
_082E2E90: .4byte 0x03007868
	thumb_func_end STWI_send_SC_EndREQ

	thumb_func_start STWI_send_SP_StartREQ
STWI_send_SP_StartREQ: ; 82E2E94
	push {lr}
	movs r0, 0x1C
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2EAE
	ldr r0, _082E2EB4
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2EAE:
	pop {r0}
	bx r0
	.align 2, 0
_082E2EB4: .4byte 0x03007868
	thumb_func_end STWI_send_SP_StartREQ

	thumb_func_start STWI_send_SP_PollingREQ
STWI_send_SP_PollingREQ: ; 82E2EB8
	push {lr}
	movs r0, 0x1D
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2ED2
	ldr r0, _082E2ED8
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2ED2:
	pop {r0}
	bx r0
	.align 2, 0
_082E2ED8: .4byte 0x03007868
	thumb_func_end STWI_send_SP_PollingREQ

	thumb_func_start STWI_send_SP_EndREQ
STWI_send_SP_EndREQ: ; 82E2EDC
	push {lr}
	movs r0, 0x1E
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2EF6
	ldr r0, _082E2EFC
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2EF6:
	pop {r0}
	bx r0
	.align 2, 0
_082E2EFC: .4byte 0x03007868
	thumb_func_end STWI_send_SP_EndREQ

	thumb_func_start STWI_send_CP_StartREQ
STWI_send_CP_StartREQ: ; 82E2F00
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1F
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E2F24
	ldr r2, _082E2F2C
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r0, [r0, 0x24]
	str r4, [r0, 0x4]
	bl STWI_start_Command
_082E2F24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E2F2C: .4byte 0x03007868
	thumb_func_end STWI_send_CP_StartREQ

	thumb_func_start STWI_send_CP_PollingREQ
STWI_send_CP_PollingREQ: ; 82E2F30
	push {lr}
	movs r0, 0x20
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2F4A
	ldr r0, _082E2F50
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2F4A:
	pop {r0}
	bx r0
	.align 2, 0
_082E2F50: .4byte 0x03007868
	thumb_func_end STWI_send_CP_PollingREQ

	thumb_func_start STWI_send_CP_EndREQ
STWI_send_CP_EndREQ: ; 82E2F54
	push {lr}
	movs r0, 0x21
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E2F6E
	ldr r0, _082E2F74
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E2F6E:
	pop {r0}
	bx r0
	.align 2, 0
_082E2F74: .4byte 0x03007868
	thumb_func_end STWI_send_CP_EndREQ

	thumb_func_start STWI_send_DataTxREQ
STWI_send_DataTxREQ: ; 82E2F78
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r4, r1, 24
	lsrs r5, r4, 24
	movs r0, 0x24
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E2FB6
	lsrs r2, r4, 26
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0
	beq _082E2F98
	adds r2, 0x1
_082E2F98:
	ldr r1, _082E2FBC
	ldr r0, [r1]
	strb r2, [r0, 0x4]
	ldr r0, [r1]
	ldr r1, [r0, 0x24]
	adds r1, 0x4
	ldrb r2, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 19
	orrs r2, r0
	adds r0, r6, 0
	bl CpuSet
	bl STWI_start_Command
_082E2FB6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E2FBC: .4byte 0x03007868
	thumb_func_end STWI_send_DataTxREQ

	thumb_func_start STWI_send_DataTxAndChangeREQ
STWI_send_DataTxAndChangeREQ: ; 82E2FC0
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r4, r1, 24
	lsrs r5, r4, 24
	movs r0, 0x25
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E2FFE
	lsrs r2, r4, 26
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0
	beq _082E2FE0
	adds r2, 0x1
_082E2FE0:
	ldr r1, _082E3004
	ldr r0, [r1]
	strb r2, [r0, 0x4]
	ldr r0, [r1]
	ldr r1, [r0, 0x24]
	adds r1, 0x4
	ldrb r2, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 19
	orrs r2, r0
	adds r0, r6, 0
	bl CpuSet
	bl STWI_start_Command
_082E2FFE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E3004: .4byte 0x03007868
	thumb_func_end STWI_send_DataTxAndChangeREQ

	thumb_func_start STWI_send_DataRxREQ
STWI_send_DataRxREQ: ; 82E3008
	push {lr}
	movs r0, 0x26
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E3022
	ldr r0, _082E3028
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E3022:
	pop {r0}
	bx r0
	.align 2, 0
_082E3028: .4byte 0x03007868
	thumb_func_end STWI_send_DataRxREQ

	thumb_func_start STWI_send_MS_ChangeREQ
STWI_send_MS_ChangeREQ: ; 82E302C
	push {lr}
	movs r0, 0x27
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E3046
	ldr r0, _082E304C
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E3046:
	pop {r0}
	bx r0
	.align 2, 0
_082E304C: .4byte 0x03007868
	thumb_func_end STWI_send_MS_ChangeREQ

	thumb_func_start STWI_send_DataReadyAndChangeREQ
STWI_send_DataReadyAndChangeREQ: ; 82E3050
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0x28
	bl STWI_init
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _082E3096
	cmp r4, 0
	bne _082E3078
	ldr r0, _082E3074
	ldr r0, [r0]
	strb r3, [r0, 0x4]
	b _082E3092
	.align 2, 0
_082E3074: .4byte 0x03007868
_082E3078:
	ldr r2, _082E309C
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r0, [r0, 0x24]
	adds r0, 0x4
	strb r5, [r0]
	adds r0, 0x1
	strb r3, [r0]
	adds r0, 0x1
	strb r3, [r0]
	strb r3, [r0, 0x1]
_082E3092:
	bl STWI_start_Command
_082E3096:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E309C: .4byte 0x03007868
	thumb_func_end STWI_send_DataReadyAndChangeREQ

	thumb_func_start STWI_send_DisconnectedAndChangeREQ
STWI_send_DisconnectedAndChangeREQ: ; 82E30A0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r0, 0x29
	bl STWI_init
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _082E30D6
	ldr r2, _082E30DC
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r0, [r0, 0x24]
	adds r0, 0x4
	strb r4, [r0]
	adds r0, 0x1
	strb r5, [r0]
	adds r0, 0x1
	strb r3, [r0]
	strb r3, [r0, 0x1]
	bl STWI_start_Command
_082E30D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E30DC: .4byte 0x03007868
	thumb_func_end STWI_send_DisconnectedAndChangeREQ

	thumb_func_start STWI_send_ResumeRetransmitAndChangeREQ
STWI_send_ResumeRetransmitAndChangeREQ: ; 82E30E0
	push {lr}
	movs r0, 0x37
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E30FA
	ldr r0, _082E3100
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E30FA:
	pop {r0}
	bx r0
	.align 2, 0
_082E3100: .4byte 0x03007868
	thumb_func_end STWI_send_ResumeRetransmitAndChangeREQ

	thumb_func_start STWI_send_DisconnectREQ
STWI_send_DisconnectREQ: ; 82E3104
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x30
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E3128
	ldr r2, _082E3130
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r0, [r0, 0x24]
	str r4, [r0, 0x4]
	bl STWI_start_Command
_082E3128:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E3130: .4byte 0x03007868
	thumb_func_end STWI_send_DisconnectREQ

	thumb_func_start STWI_send_TestModeREQ
STWI_send_TestModeREQ: ; 82E3134
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r0, 0x31
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E3160
	ldr r2, _082E3168
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	ldr r1, [r0, 0x24]
	lsls r0, r4, 8
	orrs r0, r5
	str r0, [r1, 0x4]
	bl STWI_start_Command
_082E3160:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E3168: .4byte 0x03007868
	thumb_func_end STWI_send_TestModeREQ

	thumb_func_start STWI_send_CPR_StartREQ
STWI_send_CPR_StartREQ: ; 82E316C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r6, r2, 24
	movs r0, 0x32
	bl STWI_init
	lsls r0, 16
	cmp r0, 0
	bne _082E319E
	ldr r2, _082E31A4
	ldr r1, [r2]
	movs r0, 0x2
	strb r0, [r1, 0x4]
	lsls r0, r5, 16
	orrs r0, r4
	ldr r1, [r2]
	ldr r1, [r1, 0x24]
	str r0, [r1, 0x4]
	str r6, [r1, 0x8]
	bl STWI_start_Command
_082E319E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E31A4: .4byte 0x03007868
	thumb_func_end STWI_send_CPR_StartREQ

	thumb_func_start STWI_send_CPR_PollingREQ
STWI_send_CPR_PollingREQ: ; 82E31A8
	push {lr}
	movs r0, 0x33
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E31C2
	ldr r0, _082E31C8
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E31C2:
	pop {r0}
	bx r0
	.align 2, 0
_082E31C8: .4byte 0x03007868
	thumb_func_end STWI_send_CPR_PollingREQ

	thumb_func_start STWI_send_CPR_EndREQ
STWI_send_CPR_EndREQ: ; 82E31CC
	push {lr}
	movs r0, 0x34
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E31E6
	ldr r0, _082E31EC
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E31E6:
	pop {r0}
	bx r0
	.align 2, 0
_082E31EC: .4byte 0x03007868
	thumb_func_end STWI_send_CPR_EndREQ

	thumb_func_start STWI_send_StopModeREQ
STWI_send_StopModeREQ: ; 82E31F0
	push {lr}
	movs r0, 0x3D
	bl STWI_init
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E320A
	ldr r0, _082E3210
	ldr r0, [r0]
	strb r1, [r0, 0x4]
	bl STWI_start_Command
_082E320A:
	pop {r0}
	bx r0
	.align 2, 0
_082E3210: .4byte 0x03007868
	thumb_func_end STWI_send_StopModeREQ

	thumb_func_start STWI_intr_timer
STWI_intr_timer: ; 82E3214
	push {r4,lr}
	ldr r4, _082E322C
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0x2
	beq _082E323A
	cmp r0, 0x2
	bgt _082E3230
	cmp r0, 0x1
	beq _082E3248
	b _082E3270
	.align 2, 0
_082E322C: .4byte 0x03007868
_082E3230:
	cmp r0, 0x3
	beq _082E3252
	cmp r0, 0x4
	beq _082E3248
	b _082E3270
_082E323A:
	ldrb r0, [r1, 0x10]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	movs r0, 0x32
	bl STWI_set_timer
	b _082E3270
_082E3248:
	bl STWI_stop_timer
	bl STWI_restart_Command
	b _082E3270
_082E3252:
	ldrb r0, [r1, 0x10]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	bl STWI_stop_timer
	bl STWI_reset_ClockCounter
	ldr r0, [r4]
	ldr r2, [r0, 0x18]
	cmp r2, 0
	beq _082E3270
	movs r0, 0xFF
	movs r1, 0
	bl _call_via_r2
_082E3270:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end STWI_intr_timer

	thumb_func_start STWI_set_timer
STWI_set_timer: ; 82E3278
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r5, r3, 0
	ldr r2, _082E32A8
	ldr r0, [r2]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r1, _082E32AC
	adds r4, r0, r1
	adds r1, 0x2
	adds r7, r0, r1
	ldr r1, _082E32B0
	movs r0, 0
	strh r0, [r1]
	adds r6, r2, 0
	cmp r3, 0x50
	beq _082E32D0
	cmp r3, 0x50
	bgt _082E32B4
	cmp r3, 0x32
	beq _082E32BE
	b _082E32FC
	.align 2, 0
_082E32A8: .4byte 0x03007868
_082E32AC: .4byte 0x04000100
_082E32B0: .4byte 0x04000208
_082E32B4:
	cmp r5, 0x64
	beq _082E32E0
	cmp r5, 0x82
	beq _082E32F0
	b _082E32FC
_082E32BE:
	ldr r1, _082E32CC
	adds r0, r1, 0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, 0x1
	b _082E32FA
	.align 2, 0
_082E32CC: .4byte 0x0000fccb
_082E32D0:
	ldr r1, _082E32DC
	adds r0, r1, 0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, 0x2
	b _082E32FA
	.align 2, 0
_082E32DC: .4byte 0x0000fae0
_082E32E0:
	ldr r1, _082E32EC
	adds r0, r1, 0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, 0x3
	b _082E32FA
	.align 2, 0
_082E32EC: .4byte 0x0000f996
_082E32F0:
	ldr r1, _082E3318
	adds r0, r1, 0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, 0x4
_082E32FA:
	str r0, [r1, 0xC]
_082E32FC:
	movs r0, 0xC3
	strh r0, [r7]
	ldr r2, _082E331C
	ldr r1, [r6]
	movs r0, 0x8
	ldrb r1, [r1, 0xA]
	lsls r0, r1
	strh r0, [r2]
	ldr r1, _082E3320
	movs r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E3318: .4byte 0x0000f7ad
_082E331C: .4byte 0x04000202
_082E3320: .4byte 0x04000208
	thumb_func_end STWI_set_timer

	thumb_func_start STWI_stop_timer
STWI_stop_timer: ; 82E3324
	ldr r2, _082E3344
	ldr r0, [r2]
	movs r1, 0
	str r1, [r0, 0xC]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r3, _082E3348
	adds r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r2, _082E334C
	adds r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_082E3344: .4byte 0x03007868
_082E3348: .4byte 0x04000100
_082E334C: .4byte 0x04000102
	thumb_func_end STWI_stop_timer

	thumb_func_start STWI_init
STWI_init: ; 82E3350
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	ldr r0, _082E337C
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E3384
	ldr r0, _082E3380
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	movs r0, 0x6
	strh r0, [r1, 0x12]
	ldr r2, [r1, 0x18]
	cmp r2, 0
	beq _082E33CE
	ldrh r1, [r1, 0x12]
	adds r0, r5, 0
	bl _call_via_r2
	b _082E33CE
	.align 2, 0
_082E337C: .4byte 0x04000208
_082E3380: .4byte 0x03007868
_082E3384:
	ldr r4, _082E33B0
	ldr r2, [r4]
	adds r3, r2, 0
	adds r3, 0x2C
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _082E33B4
	ldrh r0, [r2, 0x12]
	movs r1, 0
	movs r0, 0x2
	strh r0, [r2, 0x12]
	ldrb r0, [r3]
	strb r1, [r3]
	ldr r0, [r4]
	ldr r2, [r0, 0x18]
	cmp r2, 0
	beq _082E33CE
	ldrh r1, [r0, 0x12]
	adds r0, r5, 0
	bl _call_via_r2
	b _082E33CE
	.align 2, 0
_082E33B0: .4byte 0x03007868
_082E33B4:
	ldrb r0, [r2, 0x14]
	cmp r0, 0
	bne _082E33D2
	ldrh r0, [r2, 0x12]
	movs r0, 0x4
	strh r0, [r2, 0x12]
	ldr r3, [r2, 0x18]
	cmp r3, 0
	beq _082E33CE
	ldrh r1, [r2, 0x12]
	adds r0, r5, 0
	bl _call_via_r3
_082E33CE:
	movs r0, 0x1
	b _082E341A
_082E33D2:
	ldrb r0, [r3]
	movs r1, 0
	movs r0, 0x1
	strb r0, [r3]
	ldr r0, [r4]
	strb r6, [r0, 0x6]
	ldr r0, [r4]
	str r1, [r0]
	strb r1, [r0, 0x4]
	ldr r0, [r4]
	strb r1, [r0, 0x5]
	ldr r0, [r4]
	strb r1, [r0, 0x7]
	ldr r0, [r4]
	strb r1, [r0, 0x8]
	ldr r0, [r4]
	strb r1, [r0, 0x9]
	ldr r0, [r4]
	str r1, [r0, 0xC]
	ldrb r2, [r0, 0x10]
	strb r1, [r0, 0x10]
	ldr r0, [r4]
	ldrh r2, [r0, 0x12]
	movs r2, 0
	strh r1, [r0, 0x12]
	strb r2, [r0, 0x15]
	ldr r1, _082E3420
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0xC
	ldr r2, _082E3424
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
_082E341A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_082E3420: .4byte 0x04000134
_082E3424: .4byte 0x00005003
	thumb_func_end STWI_init

	thumb_func_start STWI_start_Command
STWI_start_Command: ; 82E3428
	push {r4,r5,lr}
	ldr r5, _082E3480
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	ldrb r1, [r0, 0x4]
	lsls r1, 8
	ldrb r0, [r0, 0x6]
	ldr r2, _082E3484
	orrs r0, r2
	orrs r1, r0
	str r1, [r3]
	ldr r2, _082E3488
	ldr r1, [r5]
	ldr r0, [r1, 0x24]
	ldr r0, [r0]
	str r0, [r2]
	movs r2, 0
	str r2, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x5]
	ldr r4, _082E348C
	ldrh r3, [r4]
	strh r2, [r4]
	ldr r2, _082E3490
	ldr r1, [r5]
	movs r0, 0x8
	ldrb r1, [r1, 0xA]
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4]
	ldr r1, _082E3494
	ldr r2, _082E3498
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_082E3480: .4byte 0x03007868
_082E3484: .4byte 0x99660000
_082E3488: .4byte 0x04000120
_082E348C: .4byte 0x04000208
_082E3490: .4byte 0x04000200
_082E3494: .4byte 0x04000128
_082E3498: .4byte 0x00005083
	thumb_func_end STWI_start_Command

	thumb_func_start STWI_restart_Command
STWI_restart_Command: ; 82E349C
	push {r4,lr}
	ldr r4, _082E34B4
	ldr r2, [r4]
	ldrb r0, [r2, 0x15]
	adds r3, r4, 0
	cmp r0, 0x1
	bhi _082E34B8
	adds r0, 0x1
	strb r0, [r2, 0x15]
	bl STWI_start_Command
	b _082E3512
	.align 2, 0
_082E34B4: .4byte 0x03007868
_082E34B8:
	ldrb r0, [r2, 0x6]
	cmp r0, 0x27
	beq _082E34CA
	cmp r0, 0x25
	beq _082E34CA
	cmp r0, 0x35
	beq _082E34CA
	cmp r0, 0x37
	bne _082E34EC
_082E34CA:
	ldr r0, [r3]
	ldrh r1, [r0, 0x12]
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0x12]
	adds r0, 0x2C
	ldrb r1, [r0]
	strb r2, [r0]
	ldr r1, [r3]
	ldr r2, [r1, 0x18]
	cmp r2, 0
	beq _082E3512
	ldrb r0, [r1, 0x6]
	ldrh r1, [r1, 0x12]
	bl _call_via_r2
	b _082E3512
_082E34EC:
	ldrh r0, [r2, 0x12]
	movs r1, 0
	movs r0, 0x1
	strh r0, [r2, 0x12]
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r1, [r4]
	ldr r2, [r1, 0x18]
	cmp r2, 0
	beq _082E350C
	ldrb r0, [r1, 0x6]
	ldrh r1, [r1, 0x12]
	bl _call_via_r2
_082E350C:
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1]
_082E3512:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end STWI_restart_Command

	thumb_func_start STWI_reset_ClockCounter
STWI_reset_ClockCounter: ; 82E351C
	ldr r3, _082E3548
	ldr r1, [r3]
	movs r0, 0x5
	str r0, [r1]
	movs r2, 0
	strb r2, [r1, 0x4]
	ldr r0, [r3]
	strb r2, [r0, 0x5]
	ldr r1, _082E354C
	movs r0, 0x80
	lsls r0, 24
	str r0, [r1]
	adds r1, 0x8
	strh r2, [r1]
	ldr r2, _082E3550
	adds r0, r2, 0
	strh r0, [r1]
	adds r2, 0x7F
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bx lr
	.align 2, 0
_082E3548: .4byte 0x03007868
_082E354C: .4byte 0x04000120
_082E3550: .4byte 0x00005003
	thumb_func_end STWI_reset_ClockCounter

	arm_func_start IntrSIO32
IntrSIO32: ; 82E3554
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	ldr r3, _082E35B4
	ldr r0, [r3]
	ldr r2, [r0]
	sub r11, r12, 0x4
	cmp r2, 0xA
	bne _082E3590
	ldr r0, [r0, 0x20]
	cmp r0, 0
	ldmdbeq r11, {r11,sp,lr}
	bxeq lr
	bl sub_82E3EB0
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E3590:
	ldrb r3, [r0, 0x14]
	cmp r3, 0x1
	bne _082E35A8
	bl sio32intr_clock_master
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E35A8:
	bl sio32intr_clock_slave
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E35B4: .4byte 0x03007868
	arm_func_end IntrSIO32

	arm_func_start sio32intr_clock_master
sio32intr_clock_master: ; 82E35B8
	mov r12, sp
	stmdb sp!, {r4-r6,r11,r12,lr,pc}
	mov r0, 0x50
	sub r11, r12, 0x4
	bl STWI_set_timer_in_RAM
	mov r4, 0x120
	ldr r2, _082E382C
	add r4, r4, 0x4000000
	ldr lr, [r4]
	ldr r12, [r2]
	ldr r3, [r12]
	mov r6, r2
	cmp r3, 0
	bne _082E3638
	cmp lr, 0x80000000
	bne _082E36B8
	ldrb r2, [r12, 0x5]
	ldrb r3, [r12, 0x4]
	cmp r2, r3
	bhi _082E3628
	ldr r3, [r12, 0x24]
	mov r1, r2
	ldr r2, [r3, r1, lsl 2]
	str r2, [r4]
	ldrb r3, [r12, 0x5]
	add r3, r3, 0x1
	strb r3, [r12, 0x5]
	b _082E3714
_082E3628:
	mov r3, 0x1
	str r3, [r12]
	str lr, [r4]
	b _082E3714
_082E3638:
	ldr r3, [r12]
	cmp r3, 0x1
	bne _082E36C8
	mov r3, 0x99000000
	add r3, r3, 0x660000
	mov r5, 0x80000000
	and r2, lr, r5, asr 15
	cmp r2, r3
	bne _082E36B8
	mov r3, 0
	strb r3, [r12, 0x8]
	ldr r1, [r6]
	ldrb r0, [r1, 0x8]
	ldr r2, [r1, 0x28]
	str lr, [r2, r0, lsl 2]
	ldrb r3, [r1, 0x8]
	add r3, r3, 0x1
	strb r3, [r1, 0x8]
	ldr r2, [r6]
	strb lr, [r2, 0x9]
	ldr r3, [r6]
	mov r2, lr, lsr 8
	strb r2, [r3, 0x7]
	ldr r1, [r6]
	ldrb r2, [r1, 0x7]
	ldrb r3, [r1, 0x8]
	cmp r2, r3
	bcc _082E3700
	mov r3, 0x2
	str r3, [r1]
	str r5, [r4]
	b _082E3714
_082E36B8:
	bl STWI_stop_timer_in_RAM
	mov r0, 0x82
	bl STWI_set_timer_in_RAM
	b _082E3840
_082E36C8:
	ldr r3, [r12]
	cmp r3, 0x2
	bne _082E3714
	ldrb r1, [r12, 0x8]
	ldr r2, [r12, 0x28]
	str lr, [r2, r1, lsl 2]
	ldrb r3, [r12, 0x8]
	add r3, r3, 0x1
	strb r3, [r12, 0x8]
	ldr r1, [r6]
	ldrb r2, [r1, 0x7]
	ldrb r3, [r1, 0x8]
	cmp r2, r3
	bcs _082E370C
_082E3700:
	mov r3, 0x3
	str r3, [r1]
	b _082E3714
_082E370C:
	mov r3, 0x80000000
	str r3, [r4]
_082E3714:
	mov r0, 0x1
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3840
	mov r4, 0x128
	add r4, r4, 0x4000000
	mov r5, 0x5000
	add r3, r5, 0xB
	strh r3, [r4]
	mov r0, 0
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3840
	bl STWI_stop_timer_in_RAM
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x3
	bne _082E3830
	ldrb r3, [r1, 0x9]
	cmp r3, 0xA5
	cmpne r3, 0xA7
	beq _082E3788
	and r3, r3, 0xFF
	cmp r3, 0xB5
	beq _082E3788
	cmp r3, 0xB7
	bne _082E37D0
_082E3788:
	mov r1, 0x120
	add r1, r1, 0x4000000
	mov r12, 0x128
	add r12, r12, 0x4000000
	ldr r0, [r6]
	mov r3, 0
	strb r3, [r0, 0x14]
	mov r2, 0x80000000
	str r2, [r1]
	add r3, r3, 0x5000
	add r2, r3, 0x2
	strh r2, [r12]
	add r3, r3, 0x82
	strh r3, [r12]
	ldr r2, [r6]
	mov r3, 0x5
	str r3, [r2]
	b _082E3800
_082E37D0:
	cmp r3, 0xEE
	bne _082E37F0
	add r3, r5, 0x3
	strh r3, [r4]
	mov r2, 0x4
	str r2, [r1]
	strh r0, [r1, 0x12]
	b _082E3800
_082E37F0:
	add r3, r5, 0x3
	strh r3, [r4]
	mov r2, 0x4
	str r2, [r1]
_082E3800:
	ldr r2, [r6]
	mov r3, 0
	strb r3, [r2, 0x2C]
	ldr r0, [r6]
	ldr r2, [r0, 0x18]
	cmp r2, r3
	beq _082E3840
	ldrh r1, [r0, 0x12]
	ldrb r0, [r0, 0x6]
	bl sub_82E3EA8
	b _082E3840
	.align 2, 0
_082E382C: .4byte 0x03007868
_082E3830:
	add r3, r5, 0x3
	strh r3, [r4]
	add r2, r5, 0x83
	strh r2, [r4]
_082E3840:
	ldmdb r11, {r4-r6,r11,sp,lr}
	bx lr
	arm_func_end sio32intr_clock_master

	arm_func_start sio32intr_clock_slave
sio32intr_clock_slave: ; 82E3848
	mov r12, sp
	stmdb sp!, {r4-r6,r11,r12,lr,pc}
	ldr r4, _082E3BF4
	mov r0, 0x64
	ldr r3, [r4]
	mov r6, 0
	strb r6, [r3, 0x10]
	sub r11, r12, 0x4
	bl STWI_set_timer_in_RAM
	mov r0, r6
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	mov r5, r4
	beq _082E3C4C
	mov r3, 0x128
	add r3, r3, 0x4000000
	mov r2, 0x5000
	add r2, r2, 0xA
	strh r2, [r3]
	mov lr, 0x120
	ldr r0, [r5]
	add lr, lr, 0x4000000
	ldr r12, [lr]
	ldr r3, [r0]
	cmp r3, 0x5
	bne _082E3978
	ldr r3, [r0, 0x28]
	mov r4, 0x1
	mov r0, 0x99000000
	str r12, [r3]
	add r0, r0, 0x660000
	ldr r2, [r5]
	mov r3, r0, lsr 16
	strb r4, [r2, 0x5]
	cmp r3, r12, lsr 16
	bne _082E3AC4
	ldr r3, [r5]
	mov r2, r12, lsr 8
	strb r2, [r3, 0x4]
	ldr r2, [r5]
	strb r12, [r2, 0x6]
	ldr r1, [r5]
	ldrb r3, [r1, 0x4]
	cmp r3, r6
	bne _082E395C
	ldrb r2, [r1, 0x6]
	sub r3, r2, 0x27
	cmp r2, 0x36
	cmpne r3, 0x2
	bhi _082E3930
	add r3, r2, 0x80
	strb r3, [r1, 0x9]
	ldr r2, [r5]
	ldrb r3, [r2, 0x9]
	ldr r1, [r2, 0x24]
	add r3, r3, r0
	b _082E39E0
_082E3930:
	ldr r2, [r1, 0x24]
	ldr r3, _082E3BF8
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, 0x6]
	sub r3, r3, 0x10
	cmp r3, 0x2D
	bhi _082E3A18
	ldr r3, [r2, 0x24]
	str r4, [r3, 0x4]
	b _082E3A24
_082E395C:
	mov r3, 0x80000000
	str r3, [lr]
	strb r4, [r1, 0x5]
	ldr r2, [r5]
	add r3, r3, 0x80000006
	str r3, [r2]
	b _082E3AD4
_082E3978:
	ldr r3, [r0]
	cmp r3, 0x6
	bne _082E3A78
	ldrb r1, [r0, 0x5]
	ldr r2, [r0, 0x28]
	str r12, [r2, r1, lsl 2]
	ldrb r3, [r0, 0x5]
	add r3, r3, 0x1
	strb r3, [r0, 0x5]
	ldr r1, [r5]
	ldrb r2, [r1, 0x4]
	ldrb r3, [r1, 0x5]
	cmp r2, r3
	bcs _082E3A6C
	ldrb r2, [r1, 0x6]
	sub r3, r2, 0x28
	cmp r2, 0x36
	cmpne r3, 0x1
	bhi _082E39F0
	add r3, r2, 0x80
	strb r3, [r1, 0x9]
	ldr r2, [r5]
	ldrb r3, [r2, 0x9]
	ldr r1, [r2, 0x24]
	orr r3, r3, 0x99000000
	orr r3, r3, 0x660000
_082E39E0:
	str r3, [r1]
	ldr r2, [r5]
	strb r6, [r2, 0x7]
	b _082E3A3C
_082E39F0:
	ldr r2, [r1, 0x24]
	ldr r3, _082E3BF8
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, 0x6]
	sub r3, r3, 0x10
	cmp r3, 0x2D
	ldrls r2, [r2, 0x24]
	movls r3, 0x1
	bls _082E3A20
_082E3A18:
	ldr r2, [r2, 0x24]
	mov r3, 0x2
_082E3A20:
	str r3, [r2, 0x4]
_082E3A24:
	ldr r2, [r5]
	mov r3, 0x1
	strb r3, [r2, 0x7]
	ldr r1, [r5]
	add r3, r3, 0x2
	strh r3, [r1, 0x12]
_082E3A3C:
	ldr r0, [r5]
	ldr r2, [r0, 0x24]
	mov r3, 0x120
	ldr r1, [r2]
	add r3, r3, 0x4000000
	str r1, [r3]
	mov r2, 0x1
	strb r2, [r0, 0x8]
	ldr r1, [r5]
	mov r3, 0x7
	str r3, [r1]
	b _082E3AD4
_082E3A6C:
	mov r3, 0x80000000
	str r3, [lr]
	b _082E3AD4
_082E3A78:
	ldr r3, [r0]
	cmp r3, 0x7
	bne _082E3AD4
	cmp r12, 0x80000000
	bne _082E3AC4
	ldrb r2, [r0, 0x7]
	ldrb r3, [r0, 0x8]
	cmp r2, r3
	movcc r3, 0x8
	strcc r3, [r0]
	bcc _082E3AD4
	ldrb r1, [r0, 0x8]
	ldr r3, [r0, 0x24]
	ldr r2, [r3, r1, lsl 2]
	str r2, [lr]
	ldrb r3, [r0, 0x8]
	add r3, r3, 0x1
	strb r3, [r0, 0x8]
	b _082E3AD4
_082E3AC4:
	bl STWI_stop_timer_in_RAM
	mov r0, 0x64
	bl STWI_set_timer_in_RAM
	b _082E3C4C
_082E3AD4:
	mov r0, 0x1
	bl handshake_wait
	mov r0, r0, lsl 16
	cmp r0, 0x10000
	beq _082E3C4C
	mov r6, r5
	ldr r3, [r6]
	ldr r2, [r3]
	cmp r2, 0x8
	bne _082E3B9C
	mov r4, 0x128
	add r4, r4, 0x4000000
	mov r3, 0x5000
	add r3, r3, 0x2
	strh r3, [r4]
	bl STWI_stop_timer_in_RAM
	ldr r0, [r6]
	ldrh r3, [r0, 0x12]
	cmp r3, 0x3
	bne _082E3B48
	bl STWI_init_slave
	ldr r3, [r6]
	ldr r1, [r3, 0x1C]
	cmp r1, 0
	beq _082E3C4C
	mov r0, 0x1EC
	add r0, r0, 0x2
	bl sub_82E3EAC
	b _082E3C4C
_082E3B48:
	mov r3, 0x120
	add r3, r3, 0x4000000
	mov r1, 0
	str r1, [r3]
	mov r2, 0x5000
	strh r1, [r4]
	add r2, r2, 0x3
	strh r2, [r4]
	mov r3, 0x1
	strb r3, [r0, 0x14]
	ldr r0, [r5]
	ldr r2, [r0, 0x1C]
	str r1, [r0]
	cmp r2, r1
	beq _082E3C4C
	ldrb r3, [r0, 0x4]
	ldrb r0, [r0, 0x6]
	mov r1, r2
	orr r0, r0, r3, lsl 8
	bl sub_82E3EAC
	b _082E3C4C
_082E3B9C:
	mov r3, 0x208
	add r3, r3, 0x4000000
	mov r2, 0
	strh r2, [r3]
	mov r1, 0x100
	add r2, r1, 0x4000002
	ldrh r3, [r2]
	tst r3, 0x80
	beq _082E3C20
	ldrh r3, [r2]
	tst r3, 0x3
	bne _082E3BFC
	mov r2, 0xFF00
	add r1, r1, 0x4000000
	ldrh r3, [r1]
	add r2, r2, 0x9B
	cmp r3, r2
	bls _082E3C20
_082E3BE4:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _082E3BE4
	b _082E3C20
	.align 2, 0
_082E3BF4: .4byte 0x03007868
_082E3BF8: .4byte 0x996601ee
_082E3BFC:
	mov r2, 0xFF00
	add r1, r1, 0x4000000
	ldrh r3, [r1]
	add r2, r2, 0xFE
	cmp r3, r2
	bls _082E3C20
_082E3C14:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _082E3C14
_082E3C20:
	mov r1, 0x128
	add r1, r1, 0x4000000
	mov r0, 0x208
	add r0, r0, 0x4000000
	mov r3, 0x5000
	add r2, r3, 0x2
	strh r2, [r1]
	add r3, r3, 0x82
	strh r3, [r1]
	mov r2, 0x1
	strh r2, [r0]
_082E3C4C:
	ldmdb r11, {r4-r6,r11,sp,lr}
	bx lr
	arm_func_end sio32intr_clock_slave

	arm_func_start handshake_wait
handshake_wait: ; 82E3C54
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	mov r1, 0x128
	add r1, r1, 0x4000000
	mov r0, r0, lsl 16
	ldr r2, _082E3CB8
	sub r11, r12, 0x4
	mov lr, r0, lsr 14
	ldr r12, [r2]
_082E3C78:
	ldrb r3, [r12, 0x10]
	and r0, r3, 0xFF
	cmp r0, 0x1
	beq _082E3CA4
	ldrh r3, [r1]
	and r3, r3, 0x4
	cmp r3, lr
	bne _082E3C78
	mov r0, 0
	ldmdb r11, {r11,sp,lr}
	bx lr
_082E3CA4:
	ldr r2, [r2]
	mov r3, 0
	strb r3, [r2, 0x10]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3CB8: .4byte 0x03007868
	arm_func_end handshake_wait

	arm_func_start STWI_set_timer_in_RAM
STWI_set_timer_in_RAM: ; 82E3CBC
	mov r12, sp
	stmdb sp!, {r4,r5,r11,r12,lr,pc}
	mov r1, 0x208
	add r1, r1, 0x4000000
	mov r3, 0
	sub r11, r12, 0x4
	ldr r12, _082E3D74
	and lr, r0, 0xFF
	ldr r2, [r12]
	cmp lr, 0x50
	ldrb r0, [r2, 0xA]
	mov r4, r12
	mov r2, lr
	strh r3, [r1]
	mov r0, r0, lsl 2
	add r3, r3, 0x100
	add r1, r3, 0x4000000
	add r3, r3, 0x4000002
	add r5, r0, r3
	beq _082E3D44
	bgt _082E3D1C
	cmp lr, 0x32
	beq _082E3D30
	b _082E3D90
_082E3D1C:
	cmp r2, 0x64
	beq _082E3D5C
	cmp r2, 0x82
	beq _082E3D78
	b _082E3D90
_082E3D30:
	mvn r3, 0x334
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x1
	b _082E3D8C
_082E3D44:
	mov r3, 0xAE000000
	mov r3, r3, asr 20
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x2
	b _082E3D8C
_082E3D5C:
	mvn r3, 0x660
	sub r3, r3, 0x9
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x3
	b _082E3D8C
	.align 2, 0
_082E3D74: .4byte 0x03007868
_082E3D78:
	mvn r3, 0x850
	sub r3, r3, 0x2
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, 0x4
_082E3D8C:
	str r3, [r2, 0xC]
_082E3D90:
	mov r12, 0x200
	add r12, r12, 0x4000002
	mov r3, 0xC3
	strh r3, [r5]
	mov r1, 0x208
	ldr r2, [r4]
	add r1, r1, 0x4000000
	ldrb r0, [r2, 0xA]
	sub r3, r3, 0xBB
	mov r3, r3, lsl r0
	strh r3, [r12]
	mov r2, 0x1
	strh r2, [r1]
	ldmdb r11, {r4,r5,r11,sp,lr}
	bx lr
	arm_func_end STWI_set_timer_in_RAM

	arm_func_start STWI_stop_timer_in_RAM
STWI_stop_timer_in_RAM: ; 82E3DCC
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	mov r1, 0x100
	ldr lr, _082E3E18
	add r0, r1, 0x4000000
	ldr r2, [lr]
	sub r11, r12, 0x4
	ldrb r3, [r2, 0xA]
	mov r12, 0
	str r12, [r2, 0xC]
	mov r3, r3, lsl 2
	strh r12, [r3, r0]
	ldr r2, [lr]
	ldrb r3, [r2, 0xA]
	add r1, r1, 0x4000002
	mov r3, r3, lsl 2
	strh r12, [r3, r1]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3E18: .4byte 0x03007868
	arm_func_end STWI_stop_timer_in_RAM

	arm_func_start STWI_init_slave
STWI_init_slave: ; 82E3E1C
	mov r12, sp
	stmdb sp!, {r11,r12,lr,pc}
	ldr r0, _082E3EA4
	ldr r2, [r0]
	mov r3, 0x5
	str r3, [r2]
	mov r1, 0
	strb r1, [r2, 0x14]
	ldr r3, [r0]
	strb r1, [r3, 0x4]
	ldr r2, [r0]
	strb r1, [r2, 0x5]
	ldr r3, [r0]
	strb r1, [r3, 0x6]
	ldr r2, [r0]
	strb r1, [r2, 0x7]
	ldr r3, [r0]
	strb r1, [r3, 0x8]
	ldr r2, [r0]
	strb r1, [r2, 0x9]
	ldr r3, [r0]
	str r1, [r3, 0xC]
	sub r11, r12, 0x4
	strb r1, [r3, 0x10]
	mov r2, 0x128
	ldr r12, [r0]
	add r2, r2, 0x4000000
	strh r1, [r12, 0x12]
	mov r3, 0x5000
	strb r1, [r12, 0x15]
	add r3, r3, 0x82
	strh r3, [r2]
	ldmdb r11, {r11,sp,lr}
	bx lr
	.align 2, 0
_082E3EA4: .4byte 0x03007868
	arm_func_end STWI_init_slave

	arm_func_start sub_82E3EA8
sub_82E3EA8: ; 82E3EA8
	bx r2
	arm_func_end sub_82E3EA8

	arm_func_start sub_82E3EAC
sub_82E3EAC: ; 82E3EAC
	bx r1
	arm_func_end sub_82E3EAC

	arm_func_start sub_82E3EB0
sub_82E3EB0: ; 82E3EB0
	bx r0
	arm_func_end sub_82E3EB0

	thumb_func_start rfu_initializeAPI
rfu_initializeAPI: ; 82E3EB4
	push {r4-r7,lr}
	adds r4, r0, 0
	mov r12, r2
	lsls r1, 16
	lsrs r2, r1, 16
	lsls r3, 24
	lsrs r7, r3, 24
	movs r0, 0xF0
	lsls r0, 20
	ands r0, r4
	movs r1, 0x80
	lsls r1, 18
	cmp r0, r1
	bne _082E3ED4
	cmp r7, 0
	bne _082E3EDC
_082E3ED4:
	movs r0, 0x3
	ands r0, r4
	cmp r0, 0
	beq _082E3EE0
_082E3EDC:
	movs r0, 0x2
	b _082E3FB8
_082E3EE0:
	cmp r7, 0
	beq _082E3EEC
	ldr r3, _082E3EE8
	b _082E3EEE
	.align 2, 0
_082E3EE8: .4byte 0x00000e64
_082E3EEC:
	ldr r3, _082E3EF8
_082E3EEE:
	cmp r2, r3
	bcs _082E3EFC
	movs r0, 0x1
	b _082E3FB8
	.align 2, 0
_082E3EF8: .4byte 0x00000504
_082E3EFC:
	ldr r0, _082E3FC0
	str r4, [r0]
	ldr r1, _082E3FC4
	adds r0, r4, 0
	adds r0, 0xB4
	str r0, [r1]
	ldr r1, _082E3FC8
	adds r0, 0x28
	str r0, [r1]
	ldr r2, _082E3FCC
	movs r1, 0xDE
	lsls r1, 1
	adds r0, r4, r1
	str r0, [r2]
	ldr r1, _082E3FD0
	movs r3, 0xDF
	lsls r3, 2
	adds r0, r4, r3
	str r0, [r1]
	movs r5, 0x1
	adds r6, r2, 0
	adds r4, r1, 0
_082E3F28:
	lsls r2, r5, 2
	adds r3, r2, r6
	subs r1, r5, 0x1
	lsls r1, 2
	adds r0, r1, r6
	ldr r0, [r0]
	adds r0, 0x70
	str r0, [r3]
	adds r2, r4
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1C
	str r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _082E3F28
	ldr r0, _082E3FC8
	ldr r1, [r0]
	adds r1, 0xDC
	ldr r4, _082E3FD0
	ldr r0, [r4, 0xC]
	adds r0, 0x1C
	str r0, [r1]
	mov r1, r12
	adds r2, r7, 0
	bl STWI_init_all
	bl rfu_STC_clearAPIVariables
	movs r5, 0
	ldr r3, _082E3FCC
	movs r2, 0
_082E3F6C:
	lsls r1, r5, 2
	adds r0, r1, r3
	ldr r0, [r0]
	str r2, [r0, 0x68]
	str r2, [r0, 0x6C]
	adds r1, r4
	ldr r0, [r1]
	str r2, [r0, 0x14]
	str r2, [r0, 0x18]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _082E3F6C
	ldr r4, _082E3FD4
	movs r0, 0x2
	negs r0, r0
	ands r4, r0
	ldr r1, _082E3FC8
	ldr r0, [r1]
	adds r2, r0, 0
	adds r2, 0x8
	movs r3, 0x2F
	ldr r5, _082E3FD8
_082E3F9C:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r5
	bne _082E3F9C
	ldr r1, [r1]
	adds r0, r1, 0
	adds r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0
_082E3FB8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E3FC0: .4byte 0x03007890
_082E3FC4: .4byte 0x03007894
_082E3FC8: .4byte 0x03007898
_082E3FCC: .4byte 0x03007880
_082E3FD0: .4byte 0x03007870
_082E3FD4: .4byte sub_82E53F4 + 1
_082E3FD8: .4byte 0x0000ffff
	thumb_func_end rfu_initializeAPI

	thumb_func_start rfu_STC_clearAPIVariables
rfu_STC_clearAPIVariables: ; 82E3FDC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, _082E4050
	ldrh r0, [r1]
	adds r7, r0, 0
	movs r6, 0
	strh r6, [r1]
	ldr r5, _082E4054
	ldr r1, [r5]
	ldrb r4, [r1]
	mov r0, sp
	strh r6, [r0]
	ldr r2, _082E4058
	bl CpuSet
	ldr r2, [r5]
	movs r0, 0x8
	ands r4, r0
	movs r1, 0
	strb r4, [r2]
	mov r0, sp
	adds r0, 0x2
	strh r1, [r0]
	ldr r4, _082E405C
	ldr r1, [r4]
	ldr r2, _082E4060
	bl CpuSet
	ldr r1, [r4]
	movs r0, 0x4
	strb r0, [r1, 0x9]
	ldr r0, [r5]
	strb r6, [r0, 0x6]
	ldr r1, [r4]
	movs r0, 0xFF
	strb r0, [r1]
	bl rfu_clearAllSlot
	ldr r0, [r5]
	strb r6, [r0, 0x9]
	movs r2, 0
	movs r3, 0
_082E4030:
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r0, 0x12
	adds r0, r1
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _082E4030
	ldr r0, _082E4050
	strh r7, [r0]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E4050: .4byte 0x04000208
_082E4054: .4byte 0x03007894
_082E4058: .4byte 0x01000014
_082E405C: .4byte 0x03007890
_082E4060: .4byte 0x0100005a
	thumb_func_end rfu_STC_clearAPIVariables

	thumb_func_start rfu_REQ_PARENT_resumeRetransmitAndChange
rfu_REQ_PARENT_resumeRetransmitAndChange: ; 82E4064
	push {lr}
	ldr r0, _082E4074
	bl STWI_set_Callback_M
	bl STWI_send_ResumeRetransmitAndChangeREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E4074: .4byte rfu_STC_REQ_callback + 1
	thumb_func_end rfu_REQ_PARENT_resumeRetransmitAndChange

	thumb_func_start rfu_UNI_PARENT_getDRAC_ACK
rfu_UNI_PARENT_getDRAC_ACK: ; 82E4078
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r4]
	ldr r5, _082E4090
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _082E4094
	movs r0, 0xC0
	lsls r0, 2
	b _082E40BA
	.align 2, 0
_082E4090: .4byte 0x03007890
_082E4094:
	bl rfu_getSTWIRecvBuffer
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x28
	beq _082E40A4
	cmp r0, 0x36
	bne _082E40B8
_082E40A4:
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _082E40B0
	ldr r0, [r5]
	ldrb r0, [r0, 0x2]
	b _082E40B2
_082E40B0:
	ldrb r0, [r1, 0x4]
_082E40B2:
	strb r0, [r4]
	movs r0, 0
	b _082E40BA
_082E40B8:
	movs r0, 0x10
_082E40BA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end rfu_UNI_PARENT_getDRAC_ACK

	thumb_func_start rfu_setTimerInterrupt
rfu_setTimerInterrupt: ; 82E40C0
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r1, r2, 0
	bl STWI_init_timer
	pop {r0}
	bx r0
	thumb_func_end rfu_setTimerInterrupt

	thumb_func_start rfu_getSTWIRecvBuffer
rfu_getSTWIRecvBuffer: ; 82E40D4
	ldr r0, _082E40E0
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_082E40E0: .4byte 0x03007898
	thumb_func_end rfu_getSTWIRecvBuffer

	thumb_func_start rfu_setMSCCallback
rfu_setMSCCallback: ; 82E40E4
	push {lr}
	bl STWI_set_Callback_S
	pop {r0}
	bx r0
	thumb_func_end rfu_setMSCCallback

	thumb_func_start rfu_setREQCallback
rfu_setREQCallback: ; 82E40F0
	push {lr}
	adds r1, r0, 0
	ldr r0, _082E4108
	ldr r0, [r0]
	str r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bl rfu_enableREQCallback
	pop {r0}
	bx r0
	.align 2, 0
_082E4108: .4byte 0x03007898
	thumb_func_end rfu_setREQCallback

	thumb_func_start rfu_enableREQCallback
rfu_enableREQCallback: ; 82E410C
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _082E4124
	ldr r0, _082E4120
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	b _082E412E
	.align 2, 0
_082E4120: .4byte 0x03007894
_082E4124:
	ldr r0, _082E4134
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0xF7
	ands r0, r1
_082E412E:
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_082E4134: .4byte 0x03007894
	thumb_func_end rfu_enableREQCallback

	thumb_func_start rfu_STC_REQ_callback
rfu_STC_REQ_callback: ; 82E4138
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, _082E416C
	bl STWI_set_Callback_M
	ldr r0, _082E4170
	ldr r0, [r0]
	strh r4, [r0, 0x1C]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _082E4166
	ldr r0, _082E4174
	ldr r0, [r0]
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl _call_via_r2
_082E4166:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E416C: .4byte rfu_CB_defaultCallback + 1
_082E4170: .4byte 0x03007894
_082E4174: .4byte 0x03007898
	thumb_func_end rfu_STC_REQ_callback

	thumb_func_start rfu_CB_defaultCallback
rfu_CB_defaultCallback: ; 82E4178
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	cmp r0, 0xFF
	bne _082E41D4
	ldr r0, _082E41DC
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _082E41A2
	ldr r0, _082E41E0
	ldr r0, [r0]
	ldr r2, [r0]
	movs r0, 0xFF
	adds r1, r3, 0
	bl _call_via_r2
_082E41A2:
	ldr r0, _082E41E4
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	adds r5, r0, 0
	orrs r5, r1
	movs r4, 0
_082E41B0:
	adds r0, r5, 0
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _082E41C2
	adds r0, r4, 0
	bl rfu_STC_removeLinkData
_082E41C2:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E41B0
	ldr r0, _082E41E4
	ldr r1, [r0]
	movs r0, 0xFF
	strb r0, [r1]
_082E41D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E41DC: .4byte 0x03007894
_082E41E0: .4byte 0x03007898
_082E41E4: .4byte 0x03007890
	thumb_func_end rfu_CB_defaultCallback

	thumb_func_start rfu_waitREQComplete
rfu_waitREQComplete: ; 82E41E8
	push {lr}
	bl STWI_poll_CommandEnd
	ldr r0, _082E41F8
	ldr r0, [r0]
	ldrh r0, [r0, 0x1C]
	pop {r1}
	bx r1
	.align 2, 0
_082E41F8: .4byte 0x03007894
	thumb_func_end rfu_waitREQComplete

	thumb_func_start rfu_REQ_RFUStatus
rfu_REQ_RFUStatus: ; 82E41FC
	push {lr}
	ldr r0, _082E420C
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E420C: .4byte rfu_STC_REQ_callback + 1
	thumb_func_end rfu_REQ_RFUStatus

	thumb_func_start rfu_getRFUStatus
rfu_getRFUStatus: ; 82E4210
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _082E4228
	ldr r0, [r5]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x93
	beq _082E422C
	movs r0, 0x10
	b _082E4246
	.align 2, 0
_082E4228: .4byte 0x03007898
_082E422C:
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E4240
	ldr r0, [r5]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	b _082E4242
_082E4240:
	movs r0, 0xFF
_082E4242:
	strb r0, [r4]
	movs r0, 0
_082E4246:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end rfu_getRFUStatus

	thumb_func_start sub_82E424C
sub_82E424C: ; 82E424C
	push {lr}
	ldr r2, _082E4254
	ldr r3, _082E4258
	b _082E4266
	.align 2, 0
_082E4254: .4byte 0x089a324c
_082E4258: .4byte 0x030000f0
	thumb_func_end sub_82E424C

	thumb_func_start sub_82E425C
sub_82E425C: ; 82E425C
	ldrb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r1, r0
	bne _082E42BC
_082E4266:
	ldrb r1, [r2]
	cmp r1, 0
	bne sub_82E425C
	movs r2, 0xC0
	lsls r2, 18
	movs r3, 0
	movs r1, 0
_082E4274:
	ldrh r0, [r2]
	adds r0, r3, r0
	lsls r0, 16
	lsrs r3, r0, 16
	adds r2, 0x2
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x59
	bls _082E4274
	ldr r0, _082E42B0
	ldrh r0, [r0]
	cmp r3, r0
	bne _082E42BC
	movs r0, 0xC0
	lsls r0, 18
	ldr r1, _082E42B4
	ldr r1, [r1]
	movs r2, 0x5A
	bl CpuSet
	ldr r0, _082E42B8
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0
	b _082E42BE
	.align 2, 0
_082E42B0: .4byte 0x030000fa
_082E42B4: .4byte 0x03007890
_082E42B8: .4byte 0x03007894
_082E42BC:
	movs r0, 0x1
_082E42BE:
	pop {r1}
	bx r1
	thumb_func_end sub_82E425C

	thumb_func_start rfu_REQ_stopMode
rfu_REQ_stopMode: ; 82E42C4
	push {lr}
	ldr r0, _082E42E4
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E42EC
	movs r0, 0x3D
	movs r1, 0x6
	bl rfu_STC_REQ_callback
	ldr r0, _082E42E8
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	movs r0, 0x6
	strh r0, [r1, 0x12]
	b _082E4362
	.align 2, 0
_082E42E4: .4byte 0x04000208
_082E42E8: .4byte 0x03007868
_082E42EC:
	bl AgbRFU_SoftReset
	bl rfu_STC_clearAPIVariables
	movs r0, 0x8
	bl sub_82E6D6C
	ldr r1, _082E433C
	cmp r0, r1
	bne _082E4350
	ldr r0, _082E4340
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r2, _082E4344
	adds r1, r0, r2
	movs r0, 0
	str r0, [r1]
	movs r0, 0x83
	lsls r0, 16
	str r0, [r1]
	ldr r0, [r1]
	lsls r0, 16
	ldr r2, _082E4348
	ldr r3, _082E434C
	cmp r0, r2
	bhi _082E432A
_082E4322:
	ldr r0, [r1]
	lsls r0, 16
	cmp r0, r2
	bls _082E4322
_082E432A:
	movs r0, 0
	str r0, [r1]
	adds r0, r3, 0
	bl STWI_set_Callback_M
	bl STWI_send_StopModeREQ
	b _082E4362
	.align 2, 0
_082E433C: .4byte 0x00008001
_082E4340: .4byte 0x03007868
_082E4344: .4byte 0x04000100
_082E4348: .4byte 0x0105ffff
_082E434C: .4byte rfu_CB_stopMode + 1
_082E4350:
	ldr r1, _082E4368
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x3D
	movs r1, 0
	bl rfu_STC_REQ_callback
_082E4362:
	pop {r0}
	bx r0
	.align 2, 0
_082E4368: .4byte 0x04000128
	thumb_func_end rfu_REQ_stopMode

	thumb_func_start rfu_CB_stopMode
rfu_CB_stopMode: ; 82E436C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r2, r1, 0
	cmp r2, 0
	bne _082E4386
	ldr r1, _082E4394
	movs r4, 0x80
	lsls r4, 6
	adds r0, r4, 0
	strh r0, [r1]
_082E4386:
	adds r0, r3, 0
	adds r1, r2, 0
	bl rfu_STC_REQ_callback
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E4394: .4byte 0x04000128
	thumb_func_end rfu_CB_stopMode

	thumb_func_start rfu_REQBN_softReset_and_checkID
rfu_REQBN_softReset_and_checkID: ; 82E4398
	push {lr}
	ldr r0, _082E43A8
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E43AC
	movs r0, 0x1
	negs r0, r0
	b _082E43CC
	.align 2, 0
_082E43A8: .4byte 0x04000208
_082E43AC:
	bl AgbRFU_SoftReset
	bl rfu_STC_clearAPIVariables
	movs r0, 0x1E
	bl sub_82E6D6C
	adds r2, r0, 0
	cmp r2, 0
	bne _082E43CA
	ldr r1, _082E43D0
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	strh r0, [r1]
_082E43CA:
	adds r0, r2, 0
_082E43CC:
	pop {r1}
	bx r1
	.align 2, 0
_082E43D0: .4byte 0x04000128
	thumb_func_end rfu_REQBN_softReset_and_checkID

	thumb_func_start rfu_REQ_reset
rfu_REQ_reset: ; 82E43D4
	push {lr}
	ldr r0, _082E43E4
	bl STWI_set_Callback_M
	bl STWI_send_ResetREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E43E4: .4byte rfu_CB_reset + 1
	thumb_func_end rfu_REQ_reset

	thumb_func_start rfu_CB_reset
rfu_CB_reset: ; 82E43E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	cmp r4, 0
	bne _082E43FC
	bl rfu_STC_clearAPIVariables
_082E43FC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl rfu_STC_REQ_callback
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end rfu_CB_reset

	thumb_func_start rfu_REQ_configSystem
rfu_REQ_configSystem: ; 82E440C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, _082E4444
	bl STWI_set_Callback_M
	movs r0, 0x3
	ands r4, r0
	movs r0, 0x3C
	orrs r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl STWI_send_SystemConfigREQ
	cmp r6, 0
	bne _082E444C
	ldr r0, _082E4448
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x1A]
	b _082E4466
	.align 2, 0
_082E4444: .4byte rfu_STC_REQ_callback + 1
_082E4448: .4byte 0x03007894
_082E444C:
	ldr r5, _082E446C
	ldrh r4, [r5]
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x96
	lsls r0, 2
	adds r1, r6, 0
	bl Div
	ldr r1, _082E4470
	ldr r1, [r1]
	strh r0, [r1, 0x1A]
	strh r4, [r5]
_082E4466:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E446C: .4byte 0x04000208
_082E4470: .4byte 0x03007894
	thumb_func_end rfu_REQ_configSystem

	thumb_func_start rfu_REQ_configGameData
rfu_REQ_configGameData: ; 82E4474
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r2, 0
	adds r7, r3, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, r1, 16
	adds r5, r4, 0
	mov r0, sp
	strb r1, [r0]
	lsrs r2, 24
	strb r2, [r0, 0x1]
	cmp r6, 0
	beq _082E449A
	movs r1, 0x80
	orrs r2, r1
	movs r1, 0
	orrs r2, r1
	strb r2, [r0, 0x1]
_082E449A:
	movs r2, 0x2
	ldr r0, _082E44FC
	mov r12, r0
_082E44A0:
	mov r3, sp
	adds r1, r3, r2
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xE
	bls _082E44A0
	movs r3, 0
	adds r1, r7, 0
	movs r2, 0
_082E44BA:
	ldrb r0, [r1]
	adds r0, r3, r0
	lsls r0, 24
	adds r1, 0x1
	lsrs r0, 24
	ldrb r3, [r5]
	adds r0, r3
	lsls r0, 24
	lsrs r3, r0, 24
	adds r5, 0x1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _082E44BA
	mov r1, sp
	mvns r0, r3
	strb r0, [r1, 0xF]
	cmp r6, 0
	beq _082E44E6
	movs r0, 0
	strb r0, [r1, 0xE]
_082E44E6:
	mov r0, r12
	bl STWI_set_Callback_M
	mov r0, sp
	adds r1, r7, 0
	bl STWI_send_GameConfigREQ
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E44FC: .4byte rfu_CB_configGameData + 1
	thumb_func_end rfu_REQ_configGameData

	thumb_func_start rfu_CB_configGameData
rfu_CB_configGameData: ; 82E4500
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E458A
	ldr r0, _082E4544
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	ldr r0, _082E4548
	ldr r6, [r0]
	ldrb r2, [r1, 0x4]
	adds r5, r6, 0
	adds r5, 0x98
	strh r2, [r5]
	ldrb r0, [r1, 0x5]
	lsls r3, r0, 8
	orrs r3, r2
	strh r3, [r5]
	adds r4, r1, 0x6
	movs r1, 0x80
	lsls r1, 8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _082E454C
	eors r3, r1
	strh r3, [r5]
	adds r1, r6, 0
	adds r1, 0x97
	movs r0, 0x1
	b _082E4552
	.align 2, 0
_082E4544: .4byte 0x03007868
_082E4548: .4byte 0x03007890
_082E454C:
	adds r1, r6, 0
	adds r1, 0x97
	movs r0, 0
_082E4552:
	strb r0, [r1]
	movs r2, 0
	ldr r3, _082E4598
_082E4558:
	ldr r0, [r3]
	adds r0, 0x9A
	adds r0, r2
	ldrb r1, [r4]
	strb r1, [r0]
	adds r4, 0x1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xC
	bls _082E4558
	adds r4, 0x1
	movs r2, 0
	ldr r3, _082E4598
_082E4574:
	ldr r0, [r3]
	adds r0, 0xA9
	adds r0, r2
	ldrb r1, [r4]
	strb r1, [r0]
	adds r4, 0x1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _082E4574
_082E458A:
	mov r0, r12
	adds r1, r7, 0
	bl rfu_STC_REQ_callback
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E4598: .4byte 0x03007890
	thumb_func_end rfu_CB_configGameData

	thumb_func_start rfu_REQ_startSearchChild
rfu_REQ_startSearchChild: ; 82E459C
	push {r4,lr}
	movs r1, 0
	ldr r4, _082E45E4
	ldr r3, _082E45E8
	movs r2, 0
_082E45A6:
	ldr r0, [r3]
	adds r0, 0xE
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _082E45A6
	adds r0, r4, 0
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _082E45F0
	ldr r0, _082E45EC
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _082E45F6
	movs r0, 0x1
	bl rfu_STC_clearLinkStatus
	b _082E45F6
	.align 2, 0
_082E45E4: .4byte rfu_CB_defaultCallback + 1
_082E45E8: .4byte 0x03007894
_082E45EC: .4byte 0x03007898
_082E45F0:
	movs r0, 0x19
	bl rfu_STC_REQ_callback
_082E45F6:
	ldr r0, _082E4608
	bl STWI_set_Callback_M
	bl STWI_send_SC_StartREQ
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E4608: .4byte rfu_CB_startSearchChild + 1
	thumb_func_end rfu_REQ_startSearchChild

	thumb_func_start rfu_CB_startSearchChild
rfu_CB_startSearchChild: ; 82E460C
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r2, r1, 0
	cmp r2, 0
	bne _082E4624
	ldr r0, _082E4630
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x9]
_082E4624:
	adds r0, r3, 0
	adds r1, r2, 0
	bl rfu_STC_REQ_callback
	pop {r0}
	bx r0
	.align 2, 0
_082E4630: .4byte 0x03007894
	thumb_func_end rfu_CB_startSearchChild

	thumb_func_start rfu_STC_clearLinkStatus
rfu_STC_clearLinkStatus: ; 82E4634
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl rfu_clearAllSlot
	cmp r4, 0
	beq _082E465C
	mov r0, sp
	movs r5, 0
	strh r5, [r0]
	ldr r4, _082E4690
	ldr r1, [r4]
	adds r1, 0x14
	ldr r2, _082E4694
	bl CpuSet
	ldr r0, [r4]
	strb r5, [r0, 0x8]
_082E465C:
	movs r1, 0
	ldr r2, _082E4690
	adds r4, r2, 0
	movs r3, 0
_082E4664:
	ldr r0, [r4]
	adds r0, 0xA
	adds r0, r1
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _082E4664
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	strb r1, [r0, 0x2]
	ldr r0, [r2]
	strb r1, [r0, 0x3]
	ldr r0, [r2]
	strb r1, [r0, 0x7]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E4690: .4byte 0x03007890
_082E4694: .4byte 0x01000040
	thumb_func_end rfu_STC_clearLinkStatus

	thumb_func_start rfu_REQ_pollSearchChild
rfu_REQ_pollSearchChild: ; 82E4698
	push {lr}
	ldr r0, _082E46A8
	bl STWI_set_Callback_M
	bl STWI_send_SC_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E46A8: .4byte rfu_CB_pollAndEndSearchChild + 1
	thumb_func_end rfu_REQ_pollSearchChild

	thumb_func_start rfu_REQ_endSearchChild
rfu_REQ_endSearchChild: ; 82E46AC
	push {lr}
	ldr r0, _082E46BC
	bl STWI_set_Callback_M
	bl STWI_send_SC_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E46BC: .4byte rfu_CB_pollAndEndSearchChild + 1
	thumb_func_end rfu_REQ_endSearchChild

	thumb_func_start rfu_CB_pollAndEndSearchChild
rfu_CB_pollAndEndSearchChild: ; 82E46C0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	cmp r6, 0
	bne _082E46D2
	bl rfu_STC_readChildList
_082E46D2:
	cmp r4, 0x1A
	bne _082E4714
	ldr r5, _082E4708
	ldr r0, [r5]
	adds r0, 0x94
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E4730
	ldr r0, _082E470C
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E4730
	ldr r1, [r5]
	ldr r0, _082E4710
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	adds r1, 0x94
	strh r0, [r1]
	b _082E4730
	.align 2, 0
_082E4708: .4byte 0x03007890
_082E470C: .4byte rfu_CB_defaultCallback + 1
_082E4710: .4byte 0x03007898
_082E4714:
	cmp r4, 0x1B
	bne _082E4730
	ldr r0, _082E4740
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _082E4728
	adds r1, 0x94
	movs r0, 0
	strh r0, [r1]
_082E4728:
	ldr r0, _082E4744
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x9]
_082E4730:
	adds r0, r4, 0
	adds r1, r6, 0
	bl rfu_STC_REQ_callback
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E4740: .4byte 0x03007890
_082E4744: .4byte 0x03007894
	thumb_func_end rfu_CB_pollAndEndSearchChild

	thumb_func_start rfu_STC_readChildList
rfu_STC_readChildList: ; 82E4748
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _082E47F8
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r7, [r0, 0x1]
	adds r6, r0, 0x4
	cmp r7, 0
	beq _082E47EE
	ldr r0, _082E47FC
	mov r8, r0
	ldr r1, _082E4800
	mov r12, r1
_082E4766:
	ldrb r4, [r6, 0x2]
	cmp r4, 0x3
	bhi _082E47E2
	mov r2, r12
	ldr r1, [r2]
	ldrb r0, [r1, 0x2]
	asrs r0, r4
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _082E47E2
	ldrb r0, [r1, 0x3]
	asrs r0, r4
	ands r0, r5
	cmp r0, 0
	bne _082E47E2
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xE
	adds r0, r4
	movs r1, 0xF0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xA
	adds r0, r4
	movs r1, 0x10
	strb r1, [r0]
	ldr r2, [r2]
	adds r0, r5, 0
	lsls r0, r4
	ldrb r1, [r2, 0x2]
	orrs r0, r1
	strb r0, [r2, 0x2]
	mov r2, r12
	ldr r1, [r2]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	ldr r1, [r2]
	lsls r3, r4, 5
	adds r1, r3
	ldrh r0, [r6]
	strh r0, [r1, 0x14]
	strb r4, [r1, 0x16]
	ldr r0, [r2]
	strb r5, [r0]
	mov r0, r8
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, r4, 1
	adds r1, 0x12
	adds r1, r0
	mov r2, r12
	ldr r0, [r2]
	adds r0, r3
	ldrh r0, [r0, 0x14]
	strh r0, [r1]
_082E47E2:
	subs r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r6, 0x4
	cmp r7, 0
	bne _082E4766
_082E47EE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E47F8: .4byte 0x03007898
_082E47FC: .4byte 0x03007894
_082E4800: .4byte 0x03007890
	thumb_func_end rfu_STC_readChildList

	thumb_func_start rfu_REQ_startSearchParent
rfu_REQ_startSearchParent: ; 82E4804
	push {lr}
	ldr r0, _082E4814
	bl STWI_set_Callback_M
	bl STWI_send_SP_StartREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E4814: .4byte rfu_CB_startSearchParent + 1
	thumb_func_end rfu_REQ_startSearchParent

	thumb_func_start rfu_CB_startSearchParent
rfu_CB_startSearchParent: ; 82E4818
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	cmp r4, 0
	bne _082E482E
	movs r0, 0
	bl rfu_STC_clearLinkStatus
_082E482E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl rfu_STC_REQ_callback
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end rfu_CB_startSearchParent

	thumb_func_start rfu_REQ_pollSearchParent
rfu_REQ_pollSearchParent: ; 82E483C
	push {lr}
	ldr r0, _082E484C
	bl STWI_set_Callback_M
	bl STWI_send_SP_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E484C: .4byte sub_82E4850 + 1
	thumb_func_end rfu_REQ_pollSearchParent

	thumb_func_start sub_82E4850
sub_82E4850: ; 82E4850
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	cmp r4, 0
	bne _082E4864
	bl rfu_STC_readParentCandidateList
_082E4864:
	adds r0, r5, 0
	adds r1, r4, 0
	bl rfu_STC_REQ_callback
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_82E4850

	thumb_func_start rfu_REQ_endSearchParent
rfu_REQ_endSearchParent: ; 82E4874
	push {lr}
	ldr r0, _082E4884
	bl STWI_set_Callback_M
	bl STWI_send_SP_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E4884: .4byte rfu_STC_REQ_callback + 1
	thumb_func_end rfu_REQ_endSearchParent

	thumb_func_start rfu_STC_readParentCandidateList
rfu_STC_readParentCandidateList: ; 82E4888
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r0, sp
	movs r4, 0
	strh r4, [r0]
	ldr r5, _082E4930
	ldr r1, [r5]
	adds r1, 0x14
	ldr r2, _082E4934
	bl CpuSet
	ldr r0, _082E4938
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r2, [r0]
	ldrb r7, [r2, 0x1]
	adds r2, 0x4
	ldr r0, [r5]
	strb r4, [r0, 0x8]
	movs r6, 0
	cmp r7, 0
	beq _082E498C
	mov r12, r5
	ldr r0, _082E493C
	mov r8, r0
_082E48BE:
	subs r0, r7, 0x7
	lsls r0, 24
	lsrs r7, r0, 24
	adds r1, r2, 0x6
	adds r2, 0x13
	ldrb r0, [r2]
	mvns r0, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, 0x1
	movs r4, 0
	movs r3, 0
	adds r6, 0x1
_082E48D8:
	ldrb r0, [r2]
	adds r0, r4, r0
	lsls r0, 24
	adds r2, 0x1
	lsrs r0, 24
	ldrb r4, [r1]
	adds r0, r4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r1, 0x1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x7
	bls _082E48D8
	cmp r4, r5
	bne _082E4980
	subs r2, 0x1C
	mov r0, r12
	ldr r1, [r0]
	ldrb r0, [r1, 0x8]
	lsls r0, 5
	adds r0, 0x14
	adds r4, r1, r0
	ldrh r0, [r2]
	movs r3, 0
	strh r0, [r4]
	adds r2, 0x2
	ldrb r0, [r2]
	strb r0, [r4, 0x2]
	adds r2, 0x2
	ldrh r1, [r2]
	mov r0, r8
	ands r0, r1
	strh r0, [r4, 0x4]
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _082E4940
	movs r0, 0x1
	strb r0, [r4, 0x3]
	b _082E4942
	.align 2, 0
_082E4930: .4byte 0x03007890
_082E4934: .4byte 0x01000040
_082E4938: .4byte 0x03007898
_082E493C: .4byte 0x00007fff
_082E4940:
	strb r3, [r4, 0x3]
_082E4942:
	adds r2, 0x2
	movs r3, 0
	adds r5, r4, 0
	adds r5, 0x15
	adds r4, 0x6
_082E494C:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xC
	bls _082E494C
	adds r2, 0x1
	movs r3, 0
	adds r4, r5, 0
_082E4964:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x7
	bls _082E4964
	mov r4, r12
	ldr r1, [r4]
	ldrb r0, [r1, 0x8]
	adds r0, 0x1
	strb r0, [r1, 0x8]
_082E4980:
	lsls r0, r6, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bhi _082E498C
	cmp r7, 0
	bne _082E48BE
_082E498C:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end rfu_STC_readParentCandidateList

	thumb_func_start rfu_REQ_startConnectParent
rfu_REQ_startConnectParent: ; 82E4998
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0
	movs r2, 0
	ldr r1, _082E49E4
	ldr r0, [r1]
	ldrh r0, [r0, 0x14]
	cmp r0, r4
	beq _082E49C4
	adds r5, r1, 0
_082E49AE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bhi _082E49C4
	ldr r0, [r5]
	lsls r1, r2, 5
	adds r0, r1
	ldrh r0, [r0, 0x14]
	cmp r0, r4
	bne _082E49AE
_082E49C4:
	cmp r2, 0x4
	bne _082E49CC
	movs r3, 0x80
	lsls r3, 1
_082E49CC:
	cmp r3, 0
	bne _082E49F0
	ldr r0, _082E49E8
	ldr r0, [r0]
	strh r4, [r0, 0x1E]
	ldr r0, _082E49EC
	bl STWI_set_Callback_M
	adds r0, r4, 0
	bl STWI_send_CP_StartREQ
	b _082E49F8
	.align 2, 0
_082E49E4: .4byte 0x03007890
_082E49E8: .4byte 0x03007894
_082E49EC: .4byte rfu_STC_REQ_callback + 1
_082E49F0:
	movs r0, 0x1F
	adds r1, r3, 0
	bl rfu_STC_REQ_callback
_082E49F8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end rfu_REQ_startConnectParent

	thumb_func_start rfu_REQ_pollConnectParent
rfu_REQ_pollConnectParent: ; 82E4A00
	push {lr}
	ldr r0, _082E4A10
	bl STWI_set_Callback_M
	bl STWI_send_CP_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E4A10: .4byte rfu_CB_pollConnectParent + 1
	thumb_func_end rfu_REQ_pollConnectParent

	thumb_func_start rfu_CB_pollConnectParent
rfu_CB_pollConnectParent: ; 82E4A14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x28]
	cmp r1, 0
	bne _082E4B16
	ldr r0, _082E4AD0
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrh r5, [r0, 0x4]
	ldrb r1, [r0, 0x6]
	mov r10, r1
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _082E4B16
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r2, r0, 24
	ldr r4, _082E4AD4
	ldr r3, [r4]
	ldrb r1, [r3, 0x2]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _082E4B16
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3, 0x2]
	ldr r1, [r4]
	ldrb r0, [r1, 0x3]
	bics r0, r2
	strb r0, [r1, 0x3]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x94
	movs r2, 0
	strh r5, [r0]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, [r4]
	strb r2, [r0]
	ldr r3, _082E4AD8
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r5, 0
	adds r7, r4, 0
	add r6, sp, 0x20
	movs r0, 0
	mov r8, r0
_082E4A92:
	ldr r2, [r7]
	lsls r4, r5, 5
	adds r0, r2, r4
	ldr r1, [r3]
	ldrh r0, [r0, 0x14]
	ldrh r1, [r1, 0x1E]
	cmp r0, r1
	bne _082E4AEA
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _082E4AE0
	mov r9, sp
	adds r0, r4, 0
	adds r0, 0x14
	adds r0, r2, r0
	mov r1, sp
	movs r2, 0x10
	bl CpuSet
	mov r1, r8
	strh r1, [r6]
	ldr r1, [r7]
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, _082E4ADC
	bl CpuSet
	ldr r0, [r7]
	mov r1, r8
	strb r1, [r0, 0x8]
	b _082E4AF4
	.align 2, 0
_082E4AD0: .4byte 0x03007898
_082E4AD4: .4byte 0x03007890
_082E4AD8: .4byte 0x03007894
_082E4ADC: .4byte 0x01000040
_082E4AE0:
	adds r0, r4, 0
	adds r0, 0x14
	adds r2, r0
	mov r9, r2
	b _082E4AF4
_082E4AEA:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _082E4A92
_082E4AF4:
	cmp r5, 0x3
	bhi _082E4B16
	ldr r4, _082E4B30
	mov r0, r10
	lsls r5, r0, 5
	adds r0, r5, 0
	adds r0, 0x14
	ldr r1, [r4]
	adds r1, r0
	mov r0, r9
	movs r2, 0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, r5
	mov r1, r10
	strb r1, [r0, 0x16]
_082E4B16:
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x28]
	bl rfu_STC_REQ_callback
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E4B30: .4byte 0x03007890
	thumb_func_end rfu_CB_pollConnectParent

	thumb_func_start rfu_getConnectParentStatus
rfu_getConnectParentStatus: ; 82E4B34
	push {lr}
	adds r3, r0, 0
	movs r0, 0xFF
	strb r0, [r3]
	ldr r0, _082E4B54
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r2, [r0]
	ldrb r0, [r2]
	adds r0, 0x60
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _082E4B58
	movs r0, 0x10
	b _082E4B64
	.align 2, 0
_082E4B54: .4byte 0x03007898
_082E4B58:
	adds r2, 0x6
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x1]
	strb r0, [r3]
	movs r0, 0
_082E4B64:
	pop {r1}
	bx r1
	thumb_func_end rfu_getConnectParentStatus

	thumb_func_start rfu_REQ_endConnectParent
rfu_REQ_endConnectParent: ; 82E4B68
	push {lr}
	ldr r0, _082E4B94
	bl STWI_set_Callback_M
	bl STWI_send_CP_EndREQ
	ldr r0, _082E4B98
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0x3
	bhi _082E4B90
	ldr r0, _082E4B9C
	ldr r0, [r0]
	adds r0, 0xA
	ldrb r1, [r1, 0x6]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_082E4B90:
	pop {r0}
	bx r0
	.align 2, 0
_082E4B94: .4byte rfu_CB_pollConnectParent + 1
_082E4B98: .4byte 0x03007898
_082E4B9C: .4byte 0x03007894
	thumb_func_end rfu_REQ_endConnectParent

	thumb_func_start rfu_syncVBlank
rfu_syncVBlank: ; 82E4BA0
	push {r4,r5,lr}
	bl rfu_NI_checkCommFailCounter
	ldr r0, _082E4BE8
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _082E4C78
	ldr r4, _082E4BEC
	ldr r1, [r4]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _082E4BBE
	subs r0, 0x1
	strb r0, [r1, 0x6]
_082E4BBE:
	bl rfu_getMasterSlave
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, [r4]
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _082E4BF0
	cmp r3, 0
	bne _082E4BFE
	movs r0, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r4]
	movs r0, 0xB4
	lsls r0, 1
	strh r0, [r1, 0x20]
	b _082E4BFA
	.align 2, 0
_082E4BE8: .4byte 0x03007890
_082E4BEC: .4byte 0x03007894
_082E4BF0:
	cmp r3, 0
	beq _082E4C10
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r2]
_082E4BFA:
	cmp r3, 0
	beq _082E4C10
_082E4BFE:
	ldr r3, _082E4C0C
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _082E4C1A
	.align 2, 0
_082E4C0C: .4byte 0x03007894
_082E4C10:
	ldr r3, _082E4C6C
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x2
	orrs r0, r1
_082E4C1A:
	strb r0, [r2]
	ldr r3, [r3]
	ldrb r1, [r3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _082E4C78
	ldrh r0, [r3, 0x20]
	cmp r0, 0
	bne _082E4C74
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r3]
	ldr r0, _082E4C70
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	ldrb r0, [r0, 0x3]
	adds r5, r0, 0
	orrs r5, r1
	movs r4, 0
_082E4C42:
	adds r0, r5, 0
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _082E4C54
	adds r0, r4, 0
	bl rfu_STC_removeLinkData
_082E4C54:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E4C42
	ldr r0, _082E4C70
	ldr r1, [r0]
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
	b _082E4C7A
	.align 2, 0
_082E4C6C: .4byte 0x03007894
_082E4C70: .4byte 0x03007890
_082E4C74:
	subs r0, 0x1
	strh r0, [r3, 0x20]
_082E4C78:
	movs r0, 0
_082E4C7A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end rfu_syncVBlank

	thumb_func_start rfu_REQBN_watchLink
rfu_REQBN_watchLink: ; 82E4C80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r1
	str r2, [sp]
	str r3, [sp, 0x4]
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	mov r2, r8
	strb r1, [r2]
	mov r0, sp
	ldrb r1, [r0, 0xC]
	ldr r0, [sp]
	strb r1, [r0]
	mov r2, sp
	ldrb r0, [r2, 0xC]
	ldr r2, [sp, 0x4]
	strb r0, [r2]
	ldr r5, _082E4D20
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _082E4CBE
	b _082E504E
_082E4CBE:
	ldr r0, _082E4D24
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _082E4CCA
	b _082E504E
_082E4CCA:
	ldr r3, _082E4D28
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r4, 0x4
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _082E4CE0
	movs r0, 0xB4
	lsls r0, 1
	strh r0, [r2, 0x20]
_082E4CE0:
	ldr r1, [r3]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _082E4CEE
	strb r4, [r1, 0x6]
	movs r1, 0x1
	str r1, [sp, 0x8]
_082E4CEE:
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, 0x29
	bne _082E4D30
	ldr r0, _082E4D2C
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r1, 0x5]
	ldr r1, [sp]
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _082E4D18
	ldr r0, [r5]
	ldrb r0, [r0, 0x2]
	strb r0, [r2]
_082E4D18:
	movs r2, 0x2
	str r2, [sp, 0x8]
	b _082E4D88
	.align 2, 0
_082E4D20: .4byte 0x03007890
_082E4D24: .4byte 0x03007868
_082E4D28: .4byte 0x03007894
_082E4D2C: .4byte 0x03007898
_082E4D30:
	movs r0, 0x9B
	lsls r0, 1
	cmp r6, r0
	bne _082E4D80
	ldr r0, _082E4DDC
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r6, [r0, 0x5]
	ldr r0, [r5]
	ldrb r0, [r0, 0x2]
	eors r6, r0
	ands r6, r0
	mov r0, r8
	strb r6, [r0]
	movs r0, 0x1
	ldr r1, [sp]
	strb r0, [r1]
	movs r5, 0
_082E4D56:
	mov r2, r8
	ldrb r0, [r2]
	asrs r0, r5
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _082E4D76
	ldr r0, _082E4DE0
	ldr r0, [r0]
	adds r0, 0xA
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	adds r0, r5, 0
	bl rfu_STC_removeLinkData
_082E4D76:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _082E4D56
_082E4D80:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _082E4D88
	b _082E504E
_082E4D88:
	ldr r4, _082E4DDC
	ldr r0, [r4]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r1, [r0]
	str r1, [sp, 0x10]
	ldr r0, [r0, 0x4]
	str r0, [sp, 0x14]
	ldr r0, _082E4DE4
	bl STWI_set_Callback_M
	bl STWI_send_LinkStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	cmp r0, 0
	bne _082E4DE8
	ldr r0, [r4]
	adds r0, 0xDC
	ldr r0, [r0]
	adds r2, r0, 0x4
	movs r5, 0
	ldr r3, _082E4DE0
_082E4DBC:
	ldr r0, [r3]
	adds r0, 0xA
	adds r0, r5
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _082E4DBC
	movs r2, 0
	mov r9, r2
	movs r5, 0
	b _082E4DF4
	.align 2, 0
_082E4DDC: .4byte 0x03007898
_082E4DE0: .4byte 0x03007890
_082E4DE4: .4byte rfu_CB_defaultCallback + 1
_082E4DE8:
	movs r0, 0x11
	ldr r1, [sp, 0xC]
	bl rfu_STC_REQ_callback
	ldr r0, [sp, 0xC]
	b _082E5050
_082E4DF4:
	ldr r1, _082E4E7C
	ldr r0, [r1]
	adds r0, 0xE
	adds r2, r0, r5
	ldrb r0, [r2]
	adds r3, r1, 0
	cmp r0, 0
	beq _082E4E1A
	subs r0, 0x4
	strb r0, [r2]
	ldr r0, _082E4E80
	ldr r0, [r0]
	adds r0, 0xA
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0xF
	bhi _082E4E1A
	movs r0, 0x10
	strb r0, [r1]
_082E4E1A:
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r5
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	mov r10, r0
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _082E4E2E
	b _082E5002
_082E4E2E:
	ldr r2, [sp, 0x8]
	cmp r2, 0x1
	bne _082E4F10
	ldr r4, _082E4E80
	ldr r1, [r4]
	ldrb r0, [r1, 0x2]
	ands r0, r6
	cmp r0, 0
	beq _082E4F10
	adds r0, r1, 0
	adds r0, 0xA
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _082E4F04
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _082E4E84
	ldr r1, [r3]
	adds r1, 0xA
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0xA
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x3
	bls _082E4F10
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	ldr r0, [sp]
	strb r2, [r0]
	b _082E4F10
	.align 2, 0
_082E4E7C: .4byte 0x03007894
_082E4E80: .4byte 0x03007890
_082E4E84:
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E4F10
	ldr r0, _082E4EB4
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _082E4EB8
	mov r2, r8
	ldrb r1, [r2]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrb r1, [r0, 0x8]
	ldr r0, [sp]
	b _082E4F0E
	.align 2, 0
_082E4EB4: .4byte 0x03007898
_082E4EB8:
	ldr r2, _082E4F00
	ldr r1, [r2]
	adds r1, 0xA
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	ldr r2, [r2]
	lsrs r0, 24
	ldrh r1, [r2, 0x1A]
	cmp r0, r1
	bls _082E4F10
	adds r0, r2, 0
	adds r0, 0xA
	adds r0, r5
	mov r2, sp
	ldrb r2, [r2, 0xC]
	strb r2, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	bl STWI_send_DisconnectREQ
	bl STWI_poll_CommandEnd
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	mov r2, sp
	ldrb r0, [r2, 0x8]
	ldr r2, [sp]
	strb r0, [r2]
	b _082E4F10
	.align 2, 0
_082E4F00: .4byte 0x03007894
_082E4F04:
	ldr r0, [r3]
	adds r0, 0xA
	adds r0, r5
	mov r1, sp
	ldrb r1, [r1, 0xC]
_082E4F0E:
	strb r1, [r0]
_082E4F10:
	ldr r2, _082E4F70
	mov r12, r2
	ldr r1, [r2]
	ldrb r7, [r1]
	adds r0, r5, 0x1
	mov r10, r0
	cmp r7, 0x1
	bne _082E5002
	adds r0, r1, 0
	adds r0, 0xA
	adds r4, r0, r5
	ldrb r3, [r4]
	cmp r3, 0
	beq _082E5002
	ldrb r2, [r1, 0x3]
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	beq _082E4F7E
	cmp r3, 0xA
	bls _082E4F78
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2]
	mov r0, r12
	ldr r2, [r0]
	ldrb r1, [r2, 0x2]
	adds r0, r6, 0
	orrs r0, r1
	movs r3, 0
	strb r0, [r2, 0x2]
	mov r2, r12
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	bics r0, r6
	strb r0, [r1, 0x3]
	ldr r1, [r2]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, _082E4F74
	ldr r0, [r0]
	adds r0, 0xA
	adds r0, r5
	strb r3, [r0]
	b _082E5002
	.align 2, 0
_082E4F70: .4byte 0x03007890
_082E4F74: .4byte 0x03007894
_082E4F78:
	movs r0, 0
	strb r0, [r4]
	b _082E5002
_082E4F7E:
	ldrb r0, [r1, 0x2]
	orrs r0, r2
	ands r0, r6
	cmp r0, 0
	bne _082E5002
	bl STWI_send_SlotStatusREQ
	bl STWI_poll_CommandEnd
	ldr r0, _082E4FC8
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r2, [r0]
	ldrb r0, [r2, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, 0x8
	cmp r3, 0
	beq _082E5002
	ldrh r4, [r2]
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	bne _082E4FD0
	ldr r0, _082E4FCC
	ldr r0, [r0]
	lsls r1, r5, 1
	adds r0, 0x12
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _082E4FD0
	lsls r7, r5
	mov r0, r9
	orrs r0, r7
	lsls r0, 24
	b _082E4FFE
	.align 2, 0
_082E4FC8: .4byte 0x03007898
_082E4FCC: .4byte 0x03007894
_082E4FD0:
	adds r2, 0x4
	subs r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _082E5002
	ldrh r4, [r2]
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	bne _082E4FD0
	ldr r0, _082E5060
	ldr r0, [r0]
	lsls r1, r5, 1
	adds r0, 0x12
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _082E4FD0
	movs r0, 0x1
	lsls r0, r5
	mov r1, r9
	orrs r1, r0
	lsls r0, r1, 24
_082E4FFE:
	lsrs r0, 24
	mov r9, r0
_082E5002:
	ldr r0, _082E5064
	ldr r0, [r0]
	ldrb r1, [r0, 0x2]
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	ands r6, r0
	cmp r6, 0
	beq _082E501C
	adds r0, r5, 0
	movs r1, 0
	bl rfu_STC_removeLinkData
_082E501C:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bhi _082E5028
	b _082E4DF4
_082E5028:
	mov r2, r9
	cmp r2, 0
	beq _082E5038
	mov r0, r9
	bl STWI_send_DisconnectREQ
	bl STWI_poll_CommandEnd
_082E5038:
	ldr r1, _082E5068
	ldr r0, [r1]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r2, [sp, 0x10]
	str r2, [r0]
	ldr r0, [r1]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r1, [sp, 0x14]
	str r1, [r0, 0x4]
_082E504E:
	movs r0, 0
_082E5050:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E5060: .4byte 0x03007894
_082E5064: .4byte 0x03007890
_082E5068: .4byte 0x03007898
	thumb_func_end rfu_REQBN_watchLink

	thumb_func_start rfu_STC_removeLinkData
rfu_STC_removeLinkData: ; 82E506C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r12, r1
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r7
	lsrs r6, r0, 24
	ldr r0, _082E511C
	ldr r0, [r0]
	adds r0, 0xE
	adds r0, r7
	movs r1, 0
	strb r1, [r0]
	ldr r1, _082E5120
	ldr r4, [r1]
	ldrb r0, [r4, 0x2]
	ands r0, r6
	mov r8, r1
	cmp r0, 0
	beq _082E50AA
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _082E50AA
	subs r0, 0x1
	strb r0, [r4, 0x1]
_082E50AA:
	mov r3, r8
	ldr r2, [r3]
	mvns r5, r6
	ldrb r1, [r2, 0x2]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x2]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2, 0x3]
	ldr r3, [r3]
	ldr r0, [r3]
	ldr r1, _082E5124
	ands r0, r1
	cmp r0, 0
	bne _082E50D2
	movs r0, 0xFF
	strb r0, [r3]
_082E50D2:
	mov r0, r12
	cmp r0, 0
	beq _082E5110
	mov r1, sp
	movs r4, 0
	movs r0, 0
	strh r0, [r1]
	lsls r0, r7, 5
	adds r0, 0x14
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	ldr r2, _082E5128
	mov r0, sp
	bl CpuSet
	mov r0, r8
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x3]
	mov r2, r8
	ldr r1, [r2]
	ldrb r0, [r1, 0x7]
	ands r5, r0
	strb r5, [r1, 0x7]
	ldr r0, [r2]
	adds r0, 0xA
	adds r0, r7
	strb r4, [r0]
_082E5110:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E511C: .4byte 0x03007894
_082E5120: .4byte 0x03007890
_082E5124: .4byte 0x00ff00ff
_082E5128: .4byte 0x01000010
	thumb_func_end rfu_STC_removeLinkData

	thumb_func_start rfu_REQ_disconnect
rfu_REQ_disconnect: ; 82E512C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, _082E5170
	ldr r1, [r2]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	ands r0, r4
	cmp r0, 0
	beq _082E51B0
	ldr r0, _082E5174
	ldr r1, [r0]
	strb r4, [r1, 0x5]
	ldr r2, [r2]
	ldrb r1, [r2]
	adds r3, r0, 0
	cmp r1, 0xFF
	bne _082E5178
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _082E5178
	ldrb r0, [r2, 0x3]
	ands r0, r4
	cmp r0, 0
	beq _082E51B0
	movs r0, 0x30
	movs r1, 0
	bl rfu_CB_disconnect
	b _082E51B0
	.align 2, 0
_082E5170: .4byte 0x03007890
_082E5174: .4byte 0x03007894
_082E5178:
	ldr r0, [r3]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _082E51A4
	ldr r0, _082E51A0
	bl STWI_set_Callback_M
	bl STWI_send_SC_EndREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _082E51A4
	movs r0, 0x1B
	bl rfu_STC_REQ_callback
	b _082E51B0
	.align 2, 0
_082E51A0: .4byte rfu_CB_defaultCallback + 1
_082E51A4:
	ldr r0, _082E51B8
	bl STWI_set_Callback_M
	adds r0, r4, 0
	bl STWI_send_DisconnectREQ
_082E51B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E51B8: .4byte rfu_CB_disconnect + 1
	thumb_func_end rfu_REQ_disconnect

	thumb_func_start rfu_CB_disconnect
rfu_CB_disconnect: ; 82E51BC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	cmp r5, 0x3
	bne _082E51F8
	ldr r0, _082E528C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	bne _082E51F8
	ldr r0, _082E5290
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E51F8
	ldr r0, _082E5294
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _082E51F8
	movs r5, 0
_082E51F8:
	ldr r3, _082E5298
	ldr r2, [r3]
	ldr r0, _082E528C
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	ldrb r1, [r2, 0x5]
	ands r0, r1
	strb r0, [r2, 0x5]
	ldr r0, _082E5294
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldr r0, [r3]
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x8]
	cmp r5, 0
	bne _082E5246
	movs r4, 0
_082E5220:
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r4
	lsrs r0, 24
	ldr r1, _082E5298
	ldr r1, [r1]
	ldrb r1, [r1, 0x5]
	ands r0, r1
	cmp r0, 0
	beq _082E523C
	adds r0, r4, 0
	movs r1, 0x1
	bl rfu_STC_removeLinkData
_082E523C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E5220
_082E5246:
	ldr r0, _082E528C
	ldr r2, [r0]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	orrs r0, r1
	cmp r0, 0
	bne _082E5258
	movs r0, 0xFF
	strb r0, [r2]
_082E5258:
	adds r0, r6, 0
	adds r1, r5, 0
	bl rfu_STC_REQ_callback
	ldr r0, _082E5298
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _082E5286
	ldr r0, _082E5290
	bl STWI_set_Callback_M
	bl STWI_send_SC_StartREQ
	bl STWI_poll_CommandEnd
	adds r5, r0, 0
	cmp r5, 0
	beq _082E5286
	movs r0, 0x19
	adds r1, r5, 0
	bl rfu_STC_REQ_callback
_082E5286:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E528C: .4byte 0x03007890
_082E5290: .4byte rfu_CB_defaultCallback + 1
_082E5294: .4byte 0x03007898
_082E5298: .4byte 0x03007894
	thumb_func_end rfu_CB_disconnect

	thumb_func_start rfu_REQ_CHILD_startConnectRecovery
rfu_REQ_CHILD_startConnectRecovery: ; 82E529C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _082E52EC
	ldr r0, [r0]
	strb r5, [r0, 0x5]
	movs r4, 0
	movs r0, 0x1
	ands r0, r5
	ldr r2, _082E52F0
	cmp r0, 0
	bne _082E52CA
	movs r1, 0x1
_082E52B6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bhi _082E52CA
	adds r0, r5, 0
	asrs r0, r4
	ands r0, r1
	cmp r0, 0
	beq _082E52B6
_082E52CA:
	adds r0, r2, 0
	bl STWI_set_Callback_M
	ldr r0, _082E52F4
	ldr r1, [r0]
	lsls r0, r4, 5
	adds r0, r1, r0
	ldrh r0, [r0, 0x14]
	adds r1, 0x94
	ldrh r1, [r1]
	adds r2, r5, 0
	bl STWI_send_CPR_StartREQ
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E52EC: .4byte 0x03007894
_082E52F0: .4byte rfu_STC_REQ_callback + 1
_082E52F4: .4byte 0x03007890
	thumb_func_end rfu_REQ_CHILD_startConnectRecovery

	thumb_func_start rfu_REQ_CHILD_pollConnectRecovery
rfu_REQ_CHILD_pollConnectRecovery: ; 82E52F8
	push {lr}
	ldr r0, _082E5308
	bl STWI_set_Callback_M
	bl STWI_send_CPR_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E5308: .4byte rfu_CB_CHILD_pollConnectRecovery + 1
	thumb_func_end rfu_REQ_CHILD_pollConnectRecovery

	thumb_func_start rfu_CB_CHILD_pollConnectRecovery
rfu_CB_CHILD_pollConnectRecovery: ; 82E530C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E5390
	ldr r0, _082E53A4
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _082E5390
	ldr r0, _082E53A8
	ldr r1, [r0]
	ldrb r1, [r1, 0x5]
	adds r6, r0, 0
	cmp r1, 0
	beq _082E5390
	ldr r1, _082E53AC
	ldr r0, [r1]
	strb r7, [r0]
	movs r4, 0
	adds r5, r1, 0
	mov r12, r4
_082E5346:
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r4
	lsrs r3, r0, 24
	ldr r2, [r5]
	ldr r0, [r6]
	ldrb r0, [r0, 0x5]
	ands r0, r3
	ldrb r1, [r2, 0x3]
	ands r0, r1
	cmp r0, 0
	beq _082E5380
	ldrb r1, [r2, 0x2]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	bics r0, r3
	strb r0, [r1, 0x3]
	ldr r1, [r5]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	ldr r0, [r6]
	adds r0, 0xA
	adds r0, r4
	mov r1, r12
	strb r1, [r0]
_082E5380:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E5346
	ldr r1, [r6]
	movs r0, 0
	strb r0, [r1, 0x5]
_082E5390:
	mov r0, r8
	adds r1, r7, 0
	bl rfu_STC_REQ_callback
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E53A4: .4byte 0x03007898
_082E53A8: .4byte 0x03007894
_082E53AC: .4byte 0x03007890
	thumb_func_end rfu_CB_CHILD_pollConnectRecovery

	thumb_func_start rfu_CHILD_getConnectRecoveryStatus
rfu_CHILD_getConnectRecoveryStatus: ; 82E53B0
	push {lr}
	adds r2, r0, 0
	movs r0, 0xFF
	strb r0, [r2]
	ldr r0, _082E53D0
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x4D
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _082E53D4
	movs r0, 0x10
	b _082E53DA
	.align 2, 0
_082E53D0: .4byte 0x03007898
_082E53D4:
	ldrb r0, [r1, 0x4]
	strb r0, [r2]
	movs r0, 0
_082E53DA:
	pop {r1}
	bx r1
	thumb_func_end rfu_CHILD_getConnectRecoveryStatus

	thumb_func_start rfu_REQ_CHILD_endConnectRecovery
rfu_REQ_CHILD_endConnectRecovery: ; 82E53E0
	push {lr}
	ldr r0, _082E53F0
	bl STWI_set_Callback_M
	bl STWI_send_CPR_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E53F0: .4byte rfu_CB_CHILD_pollConnectRecovery + 1
	thumb_func_end rfu_REQ_CHILD_endConnectRecovery

	thumb_func_start sub_82E53F4
sub_82E53F4: ; 82E53F4
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r3, [r5]
	ldr r1, [r6]
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _082E5418
	adds r4, r0, 0
	thumb_func_end sub_82E53F4

	non_word_aligned_thumb_func_start sub_82E540A
sub_82E540A: ; 82E540A
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, 0x1
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, r4
	bne sub_82E540A
_082E5418:
	str r3, [r5]
	str r1, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_82E540A

	thumb_func_start rfu_REQ_changeMasterSlave
rfu_REQ_changeMasterSlave: ; 82E5424
	push {lr}
	movs r0, 0x1
	bl STWI_read_status
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _082E5444
	ldr r0, _082E5440
	bl STWI_set_Callback_M
	bl STWI_send_MS_ChangeREQ
	b _082E544C
	.align 2, 0
_082E5440: .4byte rfu_STC_REQ_callback + 1
_082E5444:
	movs r0, 0x27
	movs r1, 0
	bl rfu_STC_REQ_callback
_082E544C:
	pop {r0}
	bx r0
	thumb_func_end rfu_REQ_changeMasterSlave

	thumb_func_start rfu_getMasterSlave
rfu_getMasterSlave: ; 82E5450
	push {lr}
	movs r0, 0x1
	bl STWI_read_status
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bne _082E547E
	ldr r0, _082E5484
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _082E547E
	ldrb r0, [r1, 0x6]
	cmp r0, 0x27
	beq _082E547C
	cmp r0, 0x25
	beq _082E547C
	cmp r0, 0x37
	bne _082E547E
_082E547C:
	movs r2, 0
_082E547E:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.align 2, 0
_082E5484: .4byte 0x03007868
	thumb_func_end rfu_getMasterSlave

	thumb_func_start rfu_clearAllSlot
rfu_clearAllSlot: ; 82E5488
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r1, _082E550C
	ldrh r0, [r1]
	mov r8, r0
	movs r0, 0
	strh r0, [r1]
	movs r5, 0
	mov r0, sp
	adds r0, 0x2
	movs r7, 0
	adds r6, r0, 0
_082E54A4:
	mov r0, sp
	strh r7, [r0]
	ldr r0, _082E5510
	lsls r4, r5, 2
	adds r0, r4, r0
	ldr r1, [r0]
	mov r0, sp
	ldr r2, _082E5514
	bl CpuSet
	strh r7, [r6]
	ldr r0, _082E5518
	adds r4, r0
	ldr r1, [r4]
	adds r0, r6, 0
	ldr r2, _082E551C
	bl CpuSet
	ldr r3, _082E5520
	ldr r0, [r3]
	adds r0, 0x10
	adds r0, r5
	movs r1, 0x10
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _082E54A4
	ldr r2, [r3]
	movs r1, 0
	movs r0, 0x57
	strb r0, [r2, 0xF]
	ldr r0, [r3]
	strb r1, [r0, 0x4]
	ldr r0, [r3]
	strb r1, [r0, 0x5]
	ldr r0, [r3]
	strb r1, [r0, 0x6]
	ldr r0, _082E5524
	ldr r0, [r0]
	strb r1, [r0, 0x2]
	ldr r0, _082E550C
	mov r1, r8
	strh r1, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E550C: .4byte 0x04000208
_082E5510: .4byte 0x03007880
_082E5514: .4byte 0x01000034
_082E5518: .4byte 0x03007870
_082E551C: .4byte 0x0100000a
_082E5520: .4byte 0x03007890
_082E5524: .4byte 0x03007894
	thumb_func_end rfu_clearAllSlot

	thumb_func_start rfu_STC_releaseFrame
rfu_STC_releaseFrame: ; 82E5528
	push {r4-r6,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r2, r0, 24
	adds r5, r2, 0
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r0, _082E5560
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E5568
	ldr r6, _082E5564
	cmp r3, 0
	bne _082E5554
	ldr r1, [r6]
	ldrb r0, [r1, 0xF]
	ldrh r4, [r4, 0x2E]
	adds r0, r4
	strb r0, [r1, 0xF]
_082E5554:
	ldr r1, [r6]
	ldrb r0, [r1, 0xF]
	adds r0, 0x3
	strb r0, [r1, 0xF]
	b _082E5588
	.align 2, 0
_082E5560: .4byte 0x03007894
_082E5564: .4byte 0x03007890
_082E5568:
	ldr r6, _082E5590
	cmp r3, 0
	bne _082E557C
	ldr r1, [r6]
	adds r1, 0x10
	adds r1, r2
	ldrb r0, [r1]
	ldrh r4, [r4, 0x2E]
	adds r0, r4
	strb r0, [r1]
_082E557C:
	ldr r1, [r6]
	adds r1, 0x10
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x2
	strb r0, [r1]
_082E5588:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E5590: .4byte 0x03007890
	thumb_func_end rfu_STC_releaseFrame

	thumb_func_start rfu_clearSlot
rfu_clearSlot: ; 82E5594
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r7, 0x3
	bls _082E55B4
	movs r0, 0x80
	lsls r0, 3
	b _082E572C
_082E55B4:
	movs r0, 0xF
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _082E55C4
	movs r0, 0xC0
	lsls r0, 3
	b _082E572C
_082E55C4:
	ldr r1, _082E5608
	ldrh r0, [r1]
	mov r10, r0
	movs r0, 0
	strh r0, [r1]
	movs r0, 0xC
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _082E568C
	movs r3, 0
	ldr r1, _082E560C
	lsls r0, r7, 2
	adds r0, r1
	mov r9, r0
_082E55E2:
	movs r4, 0
	cmp r3, 0
	bne _082E5614
	movs r0, 0x4
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _082E5634
	mov r2, r9
	ldr r4, [r2]
	ldr r0, _082E5610
	ldr r2, [r0]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	ldrb r0, [r2, 0x4]
	bics r0, r1
	strb r0, [r2, 0x4]
	b _082E5634
	.align 2, 0
_082E5608: .4byte 0x04000208
_082E560C: .4byte 0x03007880
_082E5610: .4byte 0x03007890
_082E5614:
	movs r0, 0x8
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _082E5634
	mov r2, r9
	ldr r0, [r2]
	adds r4, r0, 0
	adds r4, 0x34
	ldr r0, _082E56C8
	ldr r2, [r0]
	movs r1, 0x1
	lsls r1, r7
	ldrb r0, [r2, 0x5]
	bics r0, r1
	strb r0, [r2, 0x5]
_082E5634:
	adds r6, r3, 0x1
	cmp r4, 0
	beq _082E5684
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _082E5674
	lsls r1, r3, 24
	lsrs r1, 24
	adds r0, r7, 0
	adds r2, r4, 0
	bl rfu_STC_releaseFrame
	movs r1, 0
	adds r2, r4, 0
	adds r2, 0x2C
	movs r5, 0x1
	movs r3, 0
_082E565E:
	ldrb r0, [r2]
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _082E566A
	strh r3, [r4, 0x2]
_082E566A:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _082E565E
_082E5674:
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	mov r0, sp
	adds r1, r4, 0
	ldr r2, _082E56CC
	bl CpuSet
_082E5684:
	lsls r0, r6, 16
	lsrs r3, r0, 16
	cmp r3, 0x1
	bls _082E55E2
_082E568C:
	movs r0, 0x1
	mov r4, r8
	ands r0, r4
	cmp r0, 0
	beq _082E5702
	ldr r1, _082E56D0
	lsls r0, r7, 2
	adds r0, r1
	ldr r3, [r0]
	ldrh r1, [r3]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _082E56F4
	ldr r0, _082E56D4
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E56D8
	ldr r2, _082E56C8
	ldr r1, [r2]
	ldrb r0, [r1, 0xF]
	adds r0, 0x3
	ldrb r4, [r3, 0x4]
	adds r0, r4
	strb r0, [r1, 0xF]
	b _082E56EA
	.align 2, 0
_082E56C8: .4byte 0x03007890
_082E56CC: .4byte 0x0100001a
_082E56D0: .4byte 0x03007870
_082E56D4: .4byte 0x03007894
_082E56D8:
	ldr r2, _082E573C
	ldr r1, [r2]
	adds r1, 0x10
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x2
	ldrb r4, [r3, 0x4]
	adds r0, r4
	strb r0, [r1]
_082E56EA:
	ldr r2, [r2]
	ldrb r1, [r3, 0x3]
	ldrb r0, [r2, 0x6]
	bics r0, r1
	strb r0, [r2, 0x6]
_082E56F4:
	mov r0, sp
	movs r1, 0
	strh r1, [r0]
	ldr r2, _082E5740
	adds r1, r3, 0
	bl CpuSet
_082E5702:
	movs r0, 0x2
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _082E5724
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, _082E5744
	lsls r0, r7, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0xC
	ldr r2, _082E5748
	mov r0, sp
	bl CpuSet
_082E5724:
	ldr r0, _082E574C
	mov r2, r10
	strh r2, [r0]
	movs r0, 0
_082E572C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E573C: .4byte 0x03007890
_082E5740: .4byte 0x01000006
_082E5744: .4byte 0x03007870
_082E5748: .4byte 0x01000004
_082E574C: .4byte 0x04000208
	thumb_func_end rfu_clearSlot

	thumb_func_start rfu_setRecvBuffer
rfu_setRecvBuffer: ; 82E5750
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, r3, 0
	lsls r1, 24
	lsrs r1, 24
	adds r4, r1, 0
	cmp r1, 0x3
	bls _082E576C
	movs r0, 0x80
	lsls r0, 3
	b _082E57A4
_082E576C:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _082E5788
	ldr r0, _082E5784
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	str r5, [r0, 0x68]
	str r6, [r0, 0x6C]
	b _082E57A2
	.align 2, 0
_082E5784: .4byte 0x03007880
_082E5788:
	movs r0, 0x10
	ands r2, r0
	cmp r2, 0
	bne _082E5796
	movs r0, 0xC0
	lsls r0, 3
	b _082E57A4
_082E5796:
	ldr r0, _082E57AC
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	str r5, [r0, 0x14]
	str r6, [r0, 0x18]
_082E57A2:
	movs r0, 0
_082E57A4:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_082E57AC: .4byte 0x03007870
	thumb_func_end rfu_setRecvBuffer

	thumb_func_start rfu_NI_setSendData
rfu_NI_setSendData: ; 82E57B0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r3, [sp]
	movs r0, 0x20
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl rfu_STC_setSendData_org
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end rfu_NI_setSendData

	thumb_func_start rfu_UNI_setSendData
rfu_UNI_setSendData: ; 82E57DC
	push {lr}
	sub sp, 0x4
	adds r3, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, _082E57F8
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E57FC
	adds r0, r2, 0x3
	b _082E57FE
	.align 2, 0
_082E57F8: .4byte 0x03007890
_082E57FC:
	adds r0, r2, 0x2
_082E57FE:
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	bl rfu_STC_setSendData_org
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end rfu_UNI_setSendData

	thumb_func_start rfu_NI_CHILD_setSendGameName
rfu_NI_CHILD_setSendGameName: ; 82E5818
	push {lr}
	sub sp, 0x4
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldr r0, _082E5848
	ldr r3, [r0]
	adds r3, 0x98
	movs r0, 0x1A
	str r0, [sp]
	movs r0, 0x40
	bl rfu_STC_setSendData_org
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x4
	pop {r1}
	bx r1
	.align 2, 0
_082E5848: .4byte 0x03007890
	thumb_func_end rfu_NI_CHILD_setSendGameName

	thumb_func_start rfu_STC_setSendData_org
rfu_STC_setSendData_org: ; 82E584C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r3, [sp]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r0, _082E5878
	ldr r2, [r0]
	ldrb r1, [r2]
	mov r10, r0
	cmp r1, 0xFF
	bne _082E5880
	ldr r0, _082E587C
	b _082E5A36
	.align 2, 0
_082E5878: .4byte 0x03007890
_082E587C: .4byte 0x00000301
_082E5880:
	movs r0, 0xF
	ands r0, r3
	cmp r0, 0
	bne _082E588E
	movs r0, 0x80
	lsls r0, 3
	b _082E5A36
_082E588E:
	ldrb r0, [r2, 0x2]
	ldrb r1, [r2, 0x3]
	orrs r0, r1
	ands r0, r3
	cmp r0, r3
	beq _082E58A4
	ldr r0, _082E58A0
	b _082E5A36
	.align 2, 0
_082E58A0: .4byte 0x00000401
_082E58A4:
	movs r0, 0x10
	ands r0, r6
	cmp r0, 0
	beq _082E58B0
	ldrb r0, [r2, 0x6]
	b _082E58B2
_082E58B0:
	ldrb r0, [r2, 0x4]
_082E58B2:
	ands r0, r3
	cmp r0, 0
	beq _082E58C0
	ldr r0, _082E58BC
	b _082E5A36
	.align 2, 0
_082E58BC: .4byte 0x00000402
_082E58C0:
	movs r2, 0
	movs r0, 0x1
	ands r0, r3
	ldr r4, _082E58F0
	cmp r0, 0
	bne _082E58E2
	movs r1, 0x1
_082E58CE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bhi _082E58E2
	adds r0, r3, 0
	asrs r0, r2
	ands r0, r1
	cmp r0, 0
	beq _082E58CE
_082E58E2:
	mov r0, r10
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _082E58F4
	adds r1, 0xF
	b _082E58FE
	.align 2, 0
_082E58F0: .4byte 0x089a3220
_082E58F4:
	cmp r0, 0
	bne _082E5900
	adds r0, r2, 0
	adds r0, 0x10
	adds r1, r0
_082E58FE:
	mov r9, r1
_082E5900:
	mov r1, r10
	ldr r0, [r1]
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r4
	ldrb r4, [r0]
	mov r0, r9
	ldrb r0, [r0]
	cmp r8, r0
	bhi _082E5918
	cmp r8, r4
	bhi _082E591E
_082E5918:
	movs r0, 0xA0
	lsls r0, 3
	b _082E5A36
_082E591E:
	ldr r1, _082E596C
	ldrh r0, [r1]
	str r0, [sp, 0x4]
	movs r7, 0
	strh r7, [r1]
	movs r0, 0x20
	ands r0, r6
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _082E5938
	cmp r6, 0x40
	bne _082E59F4
_082E5938:
	ldr r1, _082E5970
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0
	strh r1, [r0, 0x18]
	mov r1, r12
	adds r1, 0x2D
	mov r2, r12
	str r1, [r2, 0x4]
	movs r0, 0x7
	str r0, [r2, 0x14]
	mov r0, r12
	adds r0, 0x2C
	strb r3, [r0]
	strb r3, [r2, 0x1A]
	mov r2, r8
	subs r0, r2, r4
	mov r2, r12
	strh r0, [r2, 0x2E]
	cmp r5, 0
	beq _082E5974
	strb r7, [r1]
	b _082E5978
	.align 2, 0
_082E596C: .4byte 0x04000208
_082E5970: .4byte 0x03007880
_082E5974:
	movs r0, 0x1
	strb r0, [r1]
_082E5978:
	ldr r0, [sp, 0x28]
	mov r1, r12
	str r0, [r1, 0x30]
	ldr r2, [sp]
	str r2, [r1, 0x28]
	movs r1, 0
	mov r0, r12
	strb r1, [r0, 0x1F]
	adds r0, 0x20
	strb r1, [r0]
	mov r4, r12
	adds r4, 0x1B
	movs r6, 0
	mov r2, r12
	adds r2, 0x21
	movs r5, 0x1
_082E5998:
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r2, r1
	strb r5, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _082E5998
	movs r2, 0
	movs r5, 0x1
	ldr r4, _082E59EC
	movs r1, 0
_082E59B2:
	adds r0, r3, 0
	asrs r0, r2
	ands r0, r5
	cmp r0, 0
	beq _082E59C4
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	strh r1, [r0, 0x2]
_082E59C4:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _082E59B2
	mov r1, r10
	ldr r2, [r1]
	ldrb r1, [r2, 0x4]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2, 0x4]
	mov r2, r9
	ldrb r0, [r2]
	mov r1, r8
	subs r0, r1
	strb r0, [r2]
	ldr r0, _082E59F0
	mov r2, r12
	strh r0, [r2]
	b _082E5A2C
	.align 2, 0
_082E59EC: .4byte 0x03007880
_082E59F0: .4byte 0x00008021
_082E59F4:
	movs r0, 0x10
	ands r0, r6
	cmp r0, 0
	beq _082E5A2C
	ldr r1, _082E5A48
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	strb r3, [r1, 0x3]
	ldr r0, [sp]
	str r0, [r1, 0x8]
	mov r2, r8
	subs r0, r2, r4
	strh r0, [r1, 0x4]
	mov r2, r9
	ldrb r0, [r2]
	mov r2, r8
	subs r0, r2
	mov r2, r9
	strb r0, [r2]
	ldr r0, _082E5A4C
	strh r0, [r1]
	mov r0, r10
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2, 0x6]
_082E5A2C:
	ldr r0, _082E5A50
	mov r1, sp
	ldrh r1, [r1, 0x4]
	strh r1, [r0]
	movs r0, 0
_082E5A36:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E5A48: .4byte 0x03007870
_082E5A4C: .4byte 0x00008024
_082E5A50: .4byte 0x04000208
	thumb_func_end rfu_STC_setSendData_org

	thumb_func_start rfu_changeSendTarget
rfu_changeSendTarget: ; 82E5A54
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	cmp r7, 0x3
	bls _082E5A78
	movs r0, 0x80
	lsls r0, 3
	b _082E5BAC
_082E5A78:
	cmp r0, 0x20
	bne _082E5B18
	ldr r0, _082E5B08
	mov r12, r0
	lsls r0, r7, 2
	add r0, r12
	ldr r5, [r0]
	ldrh r2, [r5]
	ldr r1, _082E5B0C
	adds r0, r1, 0
	ands r0, r2
	cmp r0, r1
	bne _082E5B2E
	ldrb r0, [r5, 0x1A]
	adds r3, r6, 0
	eors r3, r0
	adds r2, r3, 0
	ands r2, r6
	cmp r2, 0
	bne _082E5B66
	cmp r3, 0
	bne _082E5AA6
	b _082E5BAA
_082E5AA6:
	ldr r1, _082E5B10
	ldrh r0, [r1]
	mov r8, r0
	strh r2, [r1]
	movs r2, 0
	mvns r1, r3
	str r1, [sp]
	lsls r4, r6, 24
	mov r10, r4
	movs r0, 0x1
	mov r9, r0
	movs r1, 0
_082E5ABE:
	adds r0, r3, 0
	asrs r0, r2
	mov r4, r9
	ands r0, r4
	cmp r0, 0
	beq _082E5AD2
	lsls r0, r2, 2
	add r0, r12
	ldr r0, [r0]
	strh r1, [r0, 0x2]
_082E5AD2:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _082E5ABE
	ldr r0, _082E5B14
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	ldr r2, [sp]
	ands r2, r0
	strb r2, [r1, 0x4]
	strb r6, [r5, 0x1A]
	mov r0, r10
	cmp r0, 0
	bne _082E5AFE
	adds r0, r7, 0
	movs r1, 0
	adds r2, r5, 0
	bl rfu_STC_releaseFrame
	movs r0, 0x27
	strh r0, [r5]
_082E5AFE:
	ldr r0, _082E5B10
	mov r1, r8
	strh r1, [r0]
	b _082E5BAA
	.align 2, 0
_082E5B08: .4byte 0x03007880
_082E5B0C: .4byte 0x00008020
_082E5B10: .4byte 0x04000208
_082E5B14: .4byte 0x03007890
_082E5B18:
	cmp r3, 0x10
	bne _082E5BA4
	ldr r3, _082E5B34
	lsls r1, r7, 2
	adds r0, r1, r3
	ldr r0, [r0]
	ldrh r2, [r0]
	ldr r0, _082E5B38
	adds r5, r3, 0
	cmp r2, r0
	beq _082E5B40
_082E5B2E:
	ldr r0, _082E5B3C
	b _082E5BAC
	.align 2, 0
_082E5B34: .4byte 0x03007870
_082E5B38: .4byte 0x00008024
_082E5B3C: .4byte 0x00000403
_082E5B40:
	movs r3, 0
	movs r2, 0
	adds r4, r5, 0
_082E5B46:
	cmp r2, r7
	beq _082E5B54
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	orrs r3, r0
_082E5B54:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _082E5B46
	adds r2, r6, 0
	ands r2, r3
	cmp r2, 0
	beq _082E5B70
_082E5B66:
	ldr r0, _082E5B6C
	b _082E5BAC
	.align 2, 0
_082E5B6C: .4byte 0x00000404
_082E5B70:
	ldr r3, _082E5B9C
	ldrh r0, [r3]
	mov r8, r0
	strh r2, [r3]
	ldr r4, _082E5BA0
	ldr r2, [r4]
	adds r5, r1, r5
	ldr r0, [r5]
	ldrb r1, [r0, 0x3]
	ldrb r0, [r2, 0x6]
	bics r0, r1
	strb r0, [r2, 0x6]
	ldr r2, [r4]
	ldrb r1, [r2, 0x6]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2, 0x6]
	ldr r0, [r5]
	strb r6, [r0, 0x3]
	mov r2, r8
	strh r2, [r3]
	b _082E5BAA
	.align 2, 0
_082E5B9C: .4byte 0x04000208
_082E5BA0: .4byte 0x03007890
_082E5BA4:
	movs r0, 0xC0
	lsls r0, 3
	b _082E5BAC
_082E5BAA:
	movs r0, 0
_082E5BAC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end rfu_changeSendTarget

	thumb_func_start rfu_NI_stopReceivingData
rfu_NI_stopReceivingData: ; 82E5BBC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _082E5BCC
	movs r0, 0x80
	lsls r0, 3
	b _082E5C26
_082E5BCC:
	ldr r1, _082E5BF8
	lsls r0, r3, 2
	adds r0, r1
	ldr r2, [r0]
	adds r5, r2, 0
	adds r5, 0x34
	ldr r1, _082E5BFC
	ldrh r0, [r1]
	adds r4, r0, 0
	movs r0, 0
	strh r0, [r1]
	ldrh r1, [r2, 0x34]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _082E5C20
	ldr r0, _082E5C00
	cmp r1, r0
	bne _082E5C04
	movs r0, 0x48
	b _082E5C06
	.align 2, 0
_082E5BF8: .4byte 0x03007880
_082E5BFC: .4byte 0x04000208
_082E5C00: .4byte 0x00008043
_082E5C04:
	movs r0, 0x47
_082E5C06:
	strh r0, [r2, 0x34]
	ldr r0, _082E5C2C
	ldr r2, [r0]
	movs r1, 0x1
	lsls r1, r3
	ldrb r0, [r2, 0x5]
	bics r0, r1
	strb r0, [r2, 0x5]
	adds r0, r3, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl rfu_STC_releaseFrame
_082E5C20:
	ldr r0, _082E5C30
	strh r4, [r0]
	movs r0, 0
_082E5C26:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_082E5C2C: .4byte 0x03007890
_082E5C30: .4byte 0x04000208
	thumb_func_end rfu_NI_stopReceivingData

	thumb_func_start rfu_UNI_changeAndReadySendData
rfu_UNI_changeAndReadySendData: ; 82E5C34
	push {r4-r7,lr}
	adds r7, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r2, 24
	lsrs r5, r2, 24
	cmp r0, 0x3
	bls _082E5C4C
	movs r0, 0x80
	lsls r0, 3
	b _082E5CC0
_082E5C4C:
	ldr r1, _082E5C60
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	ldrh r1, [r4]
	ldr r0, _082E5C64
	cmp r1, r0
	beq _082E5C6C
	ldr r0, _082E5C68
	b _082E5CC0
	.align 2, 0
_082E5C60: .4byte 0x03007870
_082E5C64: .4byte 0x00008024
_082E5C68: .4byte 0x00000403
_082E5C6C:
	ldr r0, _082E5C80
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _082E5C84
	adds r6, r1, 0
	adds r6, 0xF
	ldrb r0, [r4, 0x4]
	ldrb r1, [r1, 0xF]
	b _082E5C92
	.align 2, 0
_082E5C80: .4byte 0x03007890
_082E5C84:
	adds r0, r3, 0
	adds r0, 0x10
	adds r6, r1, r0
	adds r1, 0x10
	adds r1, r3
	ldrb r0, [r4, 0x4]
	ldrb r1, [r1]
_082E5C92:
	adds r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r5
	bcc _082E5CBC
	ldr r2, _082E5CB8
	ldrh r1, [r2]
	movs r0, 0
	strh r0, [r2]
	str r7, [r4, 0x8]
	subs r0, r3, r5
	strb r0, [r6]
	strh r5, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	strh r1, [r2]
	movs r0, 0
	b _082E5CC0
	.align 2, 0
_082E5CB8: .4byte 0x04000208
_082E5CBC:
	movs r0, 0xA0
	lsls r0, 3
_082E5CC0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end rfu_UNI_changeAndReadySendData

	thumb_func_start rfu_UNI_readySendData
rfu_UNI_readySendData: ; 82E5CC8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _082E5CE6
	ldr r1, _082E5CEC
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldrh r1, [r2]
	ldr r0, _082E5CF0
	cmp r1, r0
	bne _082E5CE6
	movs r0, 0x1
	strb r0, [r2, 0x2]
_082E5CE6:
	pop {r0}
	bx r0
	.align 2, 0
_082E5CEC: .4byte 0x03007870
_082E5CF0: .4byte 0x00008024
	thumb_func_end rfu_UNI_readySendData

	thumb_func_start rfu_UNI_clearRecvNewDataFlag
rfu_UNI_clearRecvNewDataFlag: ; 82E5CF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _082E5D0A
	ldr r1, _082E5D10
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x12]
_082E5D0A:
	pop {r0}
	bx r0
	.align 2, 0
_082E5D10: .4byte 0x03007870
	thumb_func_end rfu_UNI_clearRecvNewDataFlag

	thumb_func_start rfu_REQ_sendData
rfu_REQ_sendData: ; 82E5D14
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _082E5D60
	ldr r2, [r0]
	ldrb r1, [r2]
	adds r4, r0, 0
	cmp r1, 0xFF
	bne _082E5D28
	b _082E5E4E
_082E5D28:
	cmp r1, 0x1
	bne _082E5DB8
	ldrb r0, [r2, 0x4]
	ldrb r1, [r2, 0x5]
	adds r3, r0, 0
	orrs r3, r1
	ldrb r0, [r2, 0x6]
	orrs r3, r0
	cmp r3, 0
	bne _082E5DB8
	ldr r0, _082E5D64
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	adds r4, r0, 0
	cmp r1, 0
	beq _082E5D50
	movs r0, 0x10
	strb r0, [r2, 0x8]
	ldr r0, [r4]
	strb r3, [r0, 0x7]
_082E5D50:
	ldr r1, [r4]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _082E5D68
	subs r0, 0x1
	strb r0, [r1, 0x8]
	b _082E5D6E
	.align 2, 0
_082E5D60: .4byte 0x03007890
_082E5D64: .4byte 0x03007894
_082E5D68:
	ldrb r0, [r1, 0x7]
	adds r0, 0x1
	strb r0, [r1, 0x7]
_082E5D6E:
	ldr r1, [r4]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _082E5D80
	ldrb r1, [r1, 0x7]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _082E5E12
_082E5D80:
	ldr r4, _082E5DA4
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x68]
	movs r0, 0xFF
	str r0, [r1, 0x78]
	ldr r0, _082E5DA8
	bl STWI_set_Callback_M
	cmp r5, 0
	bne _082E5DAC
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	bl STWI_send_DataTxREQ
	b _082E5E4E
	.align 2, 0
_082E5DA4: .4byte 0x03007898
_082E5DA8: .4byte sub_82E5F00 + 1
_082E5DAC:
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	bl STWI_send_DataTxAndChangeREQ
	b _082E5E4E
_082E5DB8:
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	cmp r0, 0
	bne _082E5DC4
	bl rfu_constructSendLLFrame
_082E5DC4:
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	cmp r0, 0
	beq _082E5E12
	ldr r0, _082E5DF0
	bl STWI_set_Callback_M
	cmp r5, 0
	beq _082E5DFC
	ldr r0, _082E5DF4
	ldr r0, [r0]
	adds r0, 0x68
	ldr r1, _082E5DF8
	ldr r1, [r1]
	ldr r1, [r1, 0x24]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	bl STWI_send_DataTxAndChangeREQ
	b _082E5E4E
	.align 2, 0
_082E5DF0: .4byte rfu_CB_sendData + 1
_082E5DF4: .4byte 0x03007898
_082E5DF8: .4byte 0x03007894
_082E5DFC:
	ldr r0, _082E5E34
	ldr r0, [r0]
	adds r0, 0x68
	ldr r1, _082E5E38
	ldr r1, [r1]
	ldr r1, [r1, 0x24]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	bl STWI_send_DataTxREQ
_082E5E12:
	cmp r5, 0
	beq _082E5E4E
	ldr r0, _082E5E3C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E5E44
	ldr r0, _082E5E40
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	cmp r1, 0
	beq _082E5E4E
	movs r0, 0x27
	bl _call_via_r1
	b _082E5E4E
	.align 2, 0
_082E5E34: .4byte 0x03007898
_082E5E38: .4byte 0x03007894
_082E5E3C: .4byte 0x03007890
_082E5E40: .4byte 0x03007868
_082E5E44:
	ldr r0, _082E5E54
	bl STWI_set_Callback_M
	bl STWI_send_MS_ChangeREQ
_082E5E4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E5E54: .4byte rfu_CB_sendData2 + 1
	thumb_func_end rfu_REQ_sendData

	thumb_func_start rfu_CB_sendData
rfu_CB_sendData: ; 82E5E58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E5EC2
	movs r6, 0
	ldr r0, _082E5EE0
	mov r8, r0
_082E5E6C:
	ldr r0, _082E5EE4
	lsls r2, r6, 2
	adds r0, r2, r0
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _082E5E7E
	movs r0, 0
	strb r0, [r1, 0x2]
_082E5E7E:
	ldr r0, _082E5EE8
	adds r0, r2, r0
	ldr r4, [r0]
	ldrh r0, [r4]
	cmp r0, r8
	bne _082E5EB8
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	bl rfu_STC_releaseFrame
	ldr r5, _082E5EEC
	ldr r2, [r5]
	ldrb r1, [r4, 0x1A]
	ldrb r0, [r2, 0x4]
	bics r0, r1
	strb r0, [r2, 0x4]
	adds r0, r4, 0
	adds r0, 0x2D
	ldrb r3, [r0]
	cmp r3, 0x1
	bne _082E5EB4
	ldr r1, [r5]
	lsls r3, r6
	ldrb r0, [r1, 0x7]
	orrs r3, r0
	strb r3, [r1, 0x7]
_082E5EB4:
	movs r0, 0x26
	strh r0, [r4]
_082E5EB8:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _082E5E6C
_082E5EC2:
	ldr r0, _082E5EEC
	ldr r1, [r0]
	ldrb r0, [r1, 0xE]
	movs r0, 0
	strb r0, [r1, 0xE]
	movs r0, 0x24
	adds r1, r7, 0
	bl rfu_STC_REQ_callback
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E5EE0: .4byte 0x00008020
_082E5EE4: .4byte 0x03007870
_082E5EE8: .4byte 0x03007880
_082E5EEC: .4byte 0x03007890
	thumb_func_end rfu_CB_sendData

	thumb_func_start rfu_CB_sendData2
rfu_CB_sendData2: ; 82E5EF0
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x24
	bl rfu_STC_REQ_callback
	pop {r0}
	bx r0
	thumb_func_end rfu_CB_sendData2

	thumb_func_start sub_82E5F00
sub_82E5F00: ; 82E5F00
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0
	beq _082E5F16
	movs r0, 0x24
	bl rfu_STC_REQ_callback
	b _082E5F22
_082E5F16:
	cmp r0, 0xFF
	bne _082E5F22
	movs r0, 0xFF
	movs r1, 0
	bl rfu_STC_REQ_callback
_082E5F22:
	pop {r0}
	bx r0
	thumb_func_end sub_82E5F00

	thumb_func_start rfu_constructSendLLFrame
rfu_constructSendLLFrame: ; 82E5F28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _082E5FD4
	ldr r2, [r0]
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _082E5F40
	b _082E6044
_082E5F40:
	ldrb r0, [r2, 0x4]
	ldrb r1, [r2, 0x5]
	orrs r0, r1
	ldrb r1, [r2, 0x6]
	orrs r0, r1
	cmp r0, 0
	beq _082E6044
	ldrb r0, [r2, 0xE]
	movs r0, 0
	strb r0, [r2, 0xE]
	mov r8, r0
	ldr r0, _082E5FD8
	ldr r0, [r0]
	adds r0, 0x6C
	str r0, [sp]
	movs r6, 0
	movs r0, 0x80
	lsls r0, 8
	mov r9, r0
	ldr r1, _082E5FDC
	mov r10, r1
_082E5F6A:
	movs r5, 0
	ldr r0, _082E5FE0
	lsls r7, r6, 2
	adds r4, r7, r0
	ldr r2, [r4]
	ldrh r1, [r2]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _082E5F8A
	adds r0, r6, 0
	mov r1, sp
	bl rfu_STC_NI_constructLLSF
	lsls r0, 16
	lsrs r5, r0, 16
_082E5F8A:
	ldr r2, [r4]
	ldrh r1, [r2, 0x34]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _082E5FA6
	adds r2, 0x34
	adds r0, r6, 0
	mov r1, sp
	bl rfu_STC_NI_constructLLSF
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0
_082E5FA6:
	ldr r0, _082E5FE4
	adds r0, r7, r0
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, r10
	bne _082E5FC0
	adds r0, r6, 0
	mov r1, sp
	bl rfu_STC_UNI_constructLLSF
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0
_082E5FC0:
	cmp r5, 0
	beq _082E5FF4
	ldr r0, _082E5FD4
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E5FE8
	add r8, r5
	b _082E5FF4
	.align 2, 0
_082E5FD4: .4byte 0x03007890
_082E5FD8: .4byte 0x03007898
_082E5FDC: .4byte 0x00008024
_082E5FE0: .4byte 0x03007880
_082E5FE4: .4byte 0x03007870
_082E5FE8:
	adds r0, r7, r6
	adds r0, 0x8
	lsls r5, r0
	mov r2, r8
	orrs r2, r5
	mov r8, r2
_082E5FF4:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _082E5F6A
	ldr r6, _082E6054
	mov r0, r8
	cmp r0, 0
	beq _082E603E
	ldr r2, [sp]
	movs r0, 0x3
	ands r0, r2
	ldr r5, _082E6058
	ldr r1, _082E605C
	cmp r0, 0
	beq _082E6026
	movs r4, 0
	movs r3, 0x3
_082E6018:
	strb r4, [r2]
	adds r0, r2, 0x1
	str r0, [sp]
	adds r2, r0, 0
	ands r0, r3
	cmp r0, 0
	bne _082E6018
_082E6026:
	ldr r0, [r1]
	mov r2, r8
	str r2, [r0, 0x68]
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0
	bne _082E603E
	ldr r0, [sp]
	subs r0, 0x6C
	ldr r1, [r1]
	subs r0, r1
	mov r8, r0
_082E603E:
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0, 0x24]
_082E6044:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6054: .4byte 0x03007894
_082E6058: .4byte 0x03007890
_082E605C: .4byte 0x03007898
	thumb_func_end rfu_constructSendLLFrame

	thumb_func_start rfu_STC_NI_constructLLSF
rfu_STC_NI_constructLLSF: ; 82E6060
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r12, r1
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r2, _082E60DC
	ldr r0, [r2]
	ldrb r0, [r0]
	lsls r0, 4
	ldr r1, _082E60E0
	adds r0, r1
	mov r8, r0
	ldrh r1, [r4]
	ldr r0, _082E60E4
	cmp r1, r0
	bne _082E60CA
	adds r3, r4, 0
	adds r3, 0x20
	ldrb r1, [r3]
	lsls r1, 2
	adds r5, r4, 0x4
	adds r1, r5, r1
	ldr r2, [r4, 0x28]
	ldr r0, [r4, 0x30]
	adds r2, r0
	ldr r0, [r1]
	adds r6, r3, 0
	cmp r0, r2
	bcc _082E60CA
	movs r7, 0
_082E60A8:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _082E60B8
	strb r7, [r6]
_082E60B8:
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r5, r1
	ldr r2, [r4, 0x28]
	ldr r0, [r4, 0x30]
	adds r2, r0
	ldr r0, [r1]
	cmp r0, r2
	bcs _082E60A8
_082E60CA:
	ldrh r1, [r4]
	movs r0, 0x40
	ands r0, r1
	mov r9, r1
	cmp r0, 0
	beq _082E60E8
	movs r5, 0
	b _082E612C
	.align 2, 0
_082E60DC: .4byte 0x03007890
_082E60E0: .4byte 0x089a3220
_082E60E4: .4byte 0x00008022
_082E60E8:
	ldr r0, _082E6114
	cmp r9, r0
	bne _082E611C
	adds r3, r4, 0
	adds r3, 0x20
	ldrb r0, [r3]
	lsls r0, 2
	adds r1, r4, 0x4
	adds r1, r0
	ldrh r7, [r4, 0x2E]
	ldr r5, [r1]
	adds r2, r5, r7
	ldr r1, [r4, 0x28]
	ldr r0, [r4, 0x30]
	adds r0, r1, r0
	adds r6, r3, 0
	cmp r2, r0
	bls _082E6118
	subs r0, r5
	lsls r0, 16
	lsrs r5, r0, 16
	b _082E6130
	.align 2, 0
_082E6114: .4byte 0x00008022
_082E6118:
	adds r5, r7, 0
	b _082E6130
_082E611C:
	ldrh r2, [r4, 0x2E]
	ldr r0, [r4, 0x14]
	cmp r0, r2
	bcc _082E6128
	adds r5, r2, 0
	b _082E612C
_082E6128:
	lsls r0, 16
	lsrs r5, r0, 16
_082E612C:
	adds r6, r4, 0
	adds r6, 0x20
_082E6130:
	movs r3, 0xF
	mov r0, r9
	ands r3, r0
	mov r1, r8
	ldrb r1, [r1, 0x3]
	lsls r3, r1
	ldrb r0, [r4, 0x1F]
	mov r2, r8
	ldrb r2, [r2, 0x4]
	lsls r0, r2
	orrs r3, r0
	ldrb r1, [r6]
	adds r0, r1, 0
	mov r7, r8
	ldrb r7, [r7, 0x5]
	lsls r0, r7
	orrs r3, r0
	adds r0, r4, 0
	adds r0, 0x21
	adds r0, r1
	ldrb r0, [r0]
	mov r1, r8
	ldrb r1, [r1, 0x6]
	lsls r0, r1
	orrs r3, r0
	orrs r3, r5
	str r3, [sp]
	ldr r2, _082E61EC
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E6178
	ldrb r0, [r4, 0x1A]
	lsls r0, 18
	orrs r3, r0
	str r3, [sp]
_082E6178:
	mov r2, sp
	movs r3, 0
	mov r7, r8
	ldrb r7, [r7]
	cmp r3, r7
	bcs _082E61A2
_082E6184:
	mov r0, r12
	ldr r1, [r0]
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	mov r7, r12
	str r1, [r7]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bcc _082E6184
_082E61A2:
	cmp r5, 0
	beq _082E61C2
	ldrb r1, [r6]
	lsls r1, 2
	adds r0, r4, 0x4
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldr r0, _082E61F0
	ldr r1, [r0]
	add r0, sp, 0x4
	ldr r3, [r1, 0x4]
	mov r1, r12
	adds r2, r5, 0
	bl _call_via_r3
_082E61C2:
	ldrh r1, [r4]
	ldr r0, _082E61F4
	cmp r1, r0
	bne _082E61DC
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _082E61DC
	movs r0, 0
	strb r0, [r6]
_082E61DC:
	ldr r0, _082E61EC
	ldr r2, [r0]
	ldrb r1, [r2]
	cmp r1, 0x1
	bne _082E61F8
	ldrb r0, [r2, 0xE]
	strb r1, [r2, 0xE]
	b _082E6206
	.align 2, 0
_082E61EC: .4byte 0x03007890
_082E61F0: .4byte 0x03007898
_082E61F4: .4byte 0x00008022
_082E61F8:
	movs r0, 0x1
	mov r1, r10
	lsls r0, r1
	ldrb r1, [r2, 0xE]
	orrs r0, r1
	ldrb r1, [r2, 0xE]
	strb r0, [r2, 0xE]
_082E6206:
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end rfu_STC_NI_constructLLSF

	thumb_func_start rfu_STC_UNI_constructLLSF
rfu_STC_UNI_constructLLSF: ; 82E6220
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, _082E6248
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _082E6244
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _082E624C
_082E6244:
	movs r0, 0
	b _082E62E8
	.align 2, 0
_082E6248: .4byte 0x03007870
_082E624C:
	ldr r0, _082E62C4
	ldr r2, [r0]
	ldrb r0, [r2]
	lsls r0, 4
	ldr r1, _082E62C8
	adds r5, r0, r1
	ldrh r0, [r4]
	movs r1, 0xF
	ands r1, r0
	ldrb r0, [r5, 0x3]
	lsls r1, r0
	ldrh r0, [r4, 0x4]
	orrs r1, r0
	str r1, [sp]
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _082E6276
	ldrb r0, [r4, 0x3]
	lsls r0, 18
	orrs r1, r0
	str r1, [sp]
_082E6276:
	mov r2, sp
	movs r3, 0
	ldr r1, _082E62CC
	mov r12, r1
	add r7, sp, 0x4
	ldrb r0, [r5]
	cmp r3, r0
	bcs _082E629E
_082E6286:
	ldr r1, [r6]
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r1, 0x1
	str r1, [r6]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r5]
	cmp r3, r1
	bcc _082E6286
_082E629E:
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x4]
	mov r2, r12
	ldr r0, [r2]
	ldrh r2, [r4, 0x4]
	ldr r3, [r0, 0x4]
	adds r0, r7, 0
	adds r1, r6, 0
	bl _call_via_r3
	ldr r0, _082E62C4
	ldr r2, [r0]
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _082E62D0
	ldrb r0, [r2, 0xE]
	movs r0, 0x10
	b _082E62DC
	.align 2, 0
_082E62C4: .4byte 0x03007890
_082E62C8: .4byte 0x089a3220
_082E62CC: .4byte 0x03007898
_082E62D0:
	movs r0, 0x10
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r2, 0xE]
	orrs r0, r1
	ldrb r1, [r2, 0xE]
_082E62DC:
	strb r0, [r2, 0xE]
	ldrh r0, [r4, 0x4]
	ldrb r5, [r5]
	adds r0, r5
	lsls r0, 16
	lsrs r0, 16
_082E62E8:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end rfu_STC_UNI_constructLLSF

	thumb_func_start rfu_REQ_recvData
rfu_REQ_recvData: ; 82E62F4
	push {r4,lr}
	ldr r0, _082E6328
	ldr r4, [r0]
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _082E6320
	ldr r2, _082E632C
	ldr r3, [r2]
	ldrb r0, [r4, 0x4]
	ldrb r1, [r4, 0x5]
	orrs r0, r1
	ldrb r1, [r4, 0x6]
	orrs r0, r1
	movs r1, 0
	strb r0, [r3, 0x3]
	ldr r0, [r2]
	strb r1, [r0, 0x4]
	ldr r0, _082E6330
	bl STWI_set_Callback_M
	bl STWI_send_DataRxREQ
_082E6320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082E6328: .4byte 0x03007890
_082E632C: .4byte 0x03007894
_082E6330: .4byte rfu_CB_recvData + 1
	thumb_func_end rfu_REQ_recvData

	thumb_func_start rfu_CB_recvData
rfu_CB_recvData: ; 82E6334
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E63F8
	ldr r0, _082E6370
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _082E63F8
	ldr r0, _082E6374
	ldr r0, [r0]
	strb r7, [r0, 0x1]
	ldr r0, _082E6378
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E637C
	bl rfu_STC_PARENT_analyzeRecvPacket
	b _082E6380
	.align 2, 0
_082E6370: .4byte 0x03007898
_082E6374: .4byte 0x03007894
_082E6378: .4byte 0x03007890
_082E637C:
	bl rfu_STC_CHILD_analyzeRecvPacket
_082E6380:
	movs r6, 0
	ldr r0, _082E6410
	mov r8, r0
	ldr r3, _082E6414
_082E6388:
	ldr r0, _082E6418
	lsls r1, r6, 2
	adds r1, r0
	ldr r4, [r1]
	ldrh r0, [r4, 0x34]
	cmp r0, r8
	bne _082E63DA
	ldr r0, _082E641C
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _082E63DA
	adds r5, r4, 0
	adds r5, 0x34
	adds r0, r4, 0
	adds r0, 0x61
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _082E63BE
	ldr r1, [r3]
	lsls r2, r6
	ldrb r0, [r1, 0x7]
	orrs r2, r0
	strb r2, [r1, 0x7]
_082E63BE:
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r5, 0
	str r3, [sp]
	bl rfu_STC_releaseFrame
	ldr r3, [sp]
	ldr r2, [r3]
	ldrb r1, [r5, 0x1A]
	ldrb r0, [r2, 0x5]
	bics r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x46
	strh r0, [r4, 0x34]
_082E63DA:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _082E6388
	ldr r0, _082E641C
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _082E63F8
	adds r7, r0, 0
	movs r1, 0xE0
	lsls r1, 3
	adds r0, r1, 0
	orrs r7, r0
_082E63F8:
	mov r0, r9
	adds r1, r7, 0
	bl rfu_STC_REQ_callback
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6410: .4byte 0x00008043
_082E6414: .4byte 0x03007890
_082E6418: .4byte 0x03007880
_082E641C: .4byte 0x03007894
	thumb_func_end rfu_CB_recvData

	thumb_func_start rfu_STC_PARENT_analyzeRecvPacket
rfu_STC_PARENT_analyzeRecvPacket: ; 82E6420
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, _082E64B0
	ldr r0, [r1]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsrs r3, r0, 8
	movs r5, 0
	mov r12, r1
	movs r7, 0x1F
	ldr r4, _082E64B4
	movs r6, 0x1
_082E643A:
	mov r0, sp
	adds r1, r0, r5
	adds r0, r3, 0
	ands r0, r7
	strb r0, [r1]
	lsrs r3, 5
	cmp r0, 0
	bne _082E6456
	ldr r0, [r4]
	adds r1, r6, 0
	lsls r1, r5
	ldrb r2, [r0, 0x1]
	orrs r1, r2
	strb r1, [r0, 0x1]
_082E6456:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _082E643A
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDC
	ldr r0, [r0]
	adds r6, r0, 0
	adds r6, 0x8
	movs r5, 0
_082E646E:
	mov r0, sp
	adds r1, r0, r5
	ldrb r0, [r1]
	adds r7, r5, 0x1
	cmp r0, 0
	beq _082E64A0
	adds r4, r1, 0
_082E647C:
	ldrb r2, [r4]
	adds r0, r5, 0
	adds r1, r6, 0
	bl rfu_STC_analyzeLLSF
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0
	ldrb r1, [r4]
	subs r1, r0
	strb r1, [r4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E64A0
	lsls r0, r1, 24
	cmp r0, 0
	bne _082E647C
_082E64A0:
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _082E646E
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E64B0: .4byte 0x03007898
_082E64B4: .4byte 0x03007894
	thumb_func_end rfu_STC_PARENT_analyzeRecvPacket

	thumb_func_start rfu_STC_CHILD_analyzeRecvPacket
rfu_STC_CHILD_analyzeRecvPacket: ; 82E64B8
	push {r4-r6,lr}
	ldr r0, _082E6508
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	movs r4, 0x7F
	ands r4, r0
	adds r5, r1, 0
	adds r5, 0x8
	cmp r4, 0
	bne _082E64D8
	ldr r0, _082E650C
	ldr r1, [r0]
	movs r0, 0xF
	strb r0, [r1, 0x1]
_082E64D8:
	movs r0, 0x80
	lsls r0, 8
	adds r6, r0, 0
_082E64DE:
	cmp r4, 0
	beq _082E6500
	movs r0, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl rfu_STC_analyzeLLSF
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0
	subs r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	ands r0, r6
	cmp r0, 0
	beq _082E64DE
_082E6500:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_082E6508: .4byte 0x03007898
_082E650C: .4byte 0x03007894
	thumb_func_end rfu_STC_CHILD_analyzeRecvPacket

	thumb_func_start rfu_STC_analyzeLLSF
rfu_STC_analyzeLLSF: ; 82E6510
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r2, 16
	lsrs r3, r2, 16
	ldr r2, _082E6544
	ldr r0, [r2]
	ldrb r0, [r0]
	mvns r0, r0
	movs r1, 0x1
	ands r0, r1
	lsls r0, 4
	ldr r1, _082E6548
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r3, r0
	bcs _082E654C
	adds r0, r3, 0
	b _082E673E
	.align 2, 0
_082E6544: .4byte 0x03007890
_082E6548: .4byte 0x089a3220
_082E654C:
	movs r5, 0
	movs r4, 0
	ldrb r3, [r6, 0x1]
	ldrb r1, [r6, 0x7]
	mov r8, r1
	ldr r2, [sp]
	mov r9, r2
	cmp r4, r0
	bcs _082E6574
	adds r2, r0, 0
_082E6560:
	ldrb r0, [r7]
	lsls r1, r4, 3
	lsls r0, r1
	orrs r5, r0
	adds r7, 0x1
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r2
	bcc _082E6560
_082E6574:
	adds r0, r5, 0
	lsrs r0, r3
	mov r3, r8
	ands r0, r3
	ldr r1, _082E664C
	mov r10, r1
	mov r3, r10
	mov r2, r9
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	adds r0, r5, 0
	ldrb r1, [r6, 0x2]
	lsrs r0, r1
	ldrb r1, [r6, 0x8]
	ands r0, r1
	lsls r0, 8
	ldr r4, _082E6650
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, 0
	ldrb r3, [r6, 0x3]
	lsrs r0, r3
	ldrb r1, [r6, 0x9]
	ands r0, r1
	lsls r0, 16
	ldr r3, _082E6654
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	adds r0, r5, 0
	ldrb r1, [r6, 0x4]
	lsrs r0, r1
	ldrb r1, [r6, 0xA]
	ands r0, r1
	lsls r0, 24
	ldr r2, _082E6658
	mov r8, r2
	mov r1, r8
	ands r1, r3
	orrs r1, r0
	mov r8, r1
	str r1, [sp]
	adds r1, r5, 0
	ldrb r2, [r6, 0x5]
	lsrs r1, r2
	ldrb r0, [r6, 0xB]
	ands r1, r0
	mov r9, sp
	ldr r2, [sp, 0x4]
	mov r3, r10
	ands r2, r3
	orrs r2, r1
	str r2, [sp, 0x4]
	adds r0, r5, 0
	ldrb r1, [r6, 0x6]
	lsrs r0, r1
	ldrb r1, [r6, 0xC]
	ands r0, r1
	lsls r0, 8
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x4]
	ldrh r0, [r6, 0xE]
	ands r5, r0
	lsls r1, r5, 16
	ldr r0, _082E665C
	ands r0, r4
	orrs r0, r1
	str r0, [sp, 0x4]
	lsrs r0, 16
	ldrb r6, [r6]
	adds r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _082E661A
	b _082E673C
_082E661A:
	ldr r2, _082E6660
	ldr r3, [r2]
	ldrb r2, [r3]
	cmp r2, 0x1
	bne _082E66D8
	ldrb r0, [r3, 0x2]
	mov r5, r12
	asrs r0, r5
	ands r0, r2
	cmp r0, 0
	bne _082E6632
	b _082E673C
_082E6632:
	mov r1, r8
	lsrs r0, r1, 16
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _082E6664
	mov r0, r12
	mov r1, sp
	adds r2, r7, 0
	bl rfu_STC_UNI_receive
	b _082E673C
	.align 2, 0
_082E664C: .4byte 0xffffff00
_082E6650: .4byte 0xffff00ff
_082E6654: .4byte 0xff00ffff
_082E6658: .4byte 0x00ffffff
_082E665C: .4byte 0x0000ffff
_082E6660: .4byte 0x03007890
_082E6664:
	mov r5, r9
	ldrb r0, [r5, 0x3]
	cmp r0, 0
	bne _082E6678
	mov r0, r12
	mov r1, sp
	adds r2, r7, 0
	bl rfu_STC_NI_receive_Receiver
	b _082E673C
_082E6678:
	movs r4, 0
	ldr r1, _082E6690
	ldr r0, [r1]
	ldrb r0, [r0, 0x1A]
	mov r5, r12
	asrs r0, r5
	ands r0, r2
	cmp r0, 0
	beq _082E6694
	ldrb r0, [r3, 0x4]
	b _082E66BA
	.align 2, 0
_082E6690: .4byte 0x03007880
_082E6694:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bhi _082E673C
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1A]
	mov r2, r12
	asrs r0, r2
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	beq _082E6694
	ldr r3, _082E66D4
	ldr r0, [r3]
	ldrb r0, [r0, 0x4]
	mov r5, r12
_082E66BA:
	asrs r0, r5
	ands r0, r2
	cmp r0, 0
	beq _082E6694
	cmp r4, 0x3
	bhi _082E673C
	adds r0, r4, 0
	mov r1, r12
	mov r2, sp
	adds r3, r7, 0
	bl rfu_STC_NI_receive_Sender
	b _082E673C
	.align 2, 0
_082E66D4: .4byte 0x03007890
_082E66D8:
	ldrb r1, [r3, 0x2]
	mov r2, r9
	ldrb r0, [r2, 0x1]
	adds r5, r1, 0
	ands r5, r0
	cmp r5, 0
	beq _082E673C
	movs r4, 0
	movs r6, 0x1
_082E66EA:
	adds r0, r5, 0
	asrs r0, r4
	ands r0, r6
	cmp r0, 0
	beq _082E6732
	mov r1, sp
	ldrb r0, [r1, 0x2]
	cmp r0, 0x4
	bne _082E6706
	adds r0, r4, 0
	adds r2, r7, 0
	bl rfu_STC_UNI_receive
	b _082E6732
_082E6706:
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	bne _082E6718
	adds r0, r4, 0
	mov r1, sp
	adds r2, r7, 0
	bl rfu_STC_NI_receive_Receiver
	b _082E6732
_082E6718:
	ldr r0, _082E6750
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	asrs r0, r4
	ands r0, r6
	cmp r0, 0
	beq _082E6732
	adds r0, r4, 0
	adds r1, r4, 0
	mov r2, sp
	adds r3, r7, 0
	bl rfu_STC_NI_receive_Sender
_082E6732:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E66EA
_082E673C:
	mov r0, r10
_082E673E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E6750: .4byte 0x03007890
	thumb_func_end rfu_STC_analyzeLLSF

	thumb_func_start rfu_STC_UNI_receive
rfu_STC_UNI_receive: ; 82E6754
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r1, 0
	str r2, [sp]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, _082E6788
	lsls r1, r7, 2
	adds r1, r2
	ldr r3, [r1]
	adds r5, r3, 0
	adds r5, 0xC
	movs r4, 0
	movs r0, 0
	strh r0, [r5, 0x2]
	ldr r0, [r1]
	ldr r0, [r0, 0x18]
	adds r1, r2, 0
	ldrh r2, [r6, 0x6]
	cmp r0, r2
	bcs _082E6790
	movs r0, 0x49
	strh r0, [r3, 0xC]
	ldr r0, _082E678C
	strh r0, [r5, 0x2]
	b _082E67DE
	.align 2, 0
_082E6788: .4byte 0x03007870
_082E678C: .4byte 0x00000701
_082E6790:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _082E67A8
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _082E67B4
	ldr r0, _082E67A4
	strh r0, [r5, 0x2]
	b _082E67DE
	.align 2, 0
_082E67A4: .4byte 0x00000709
_082E67A8:
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _082E67B4
	movs r0, 0xE1
	lsls r0, 3
	strh r0, [r5, 0x2]
_082E67B4:
	movs r4, 0
	ldr r0, _082E67FC
	strh r0, [r5]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x4]
	ldrh r2, [r6, 0x6]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	str r0, [sp, 0x4]
	ldr r0, _082E6800
	ldr r0, [r0]
	add r1, sp, 0x4
	ldr r3, [r0, 0x4]
	mov r0, sp
	bl _call_via_r3
	movs r0, 0x1
	strb r0, [r5, 0x6]
	strh r4, [r5]
_082E67DE:
	ldrh r0, [r5, 0x2]
	cmp r0, 0
	beq _082E67F2
	ldr r0, _082E6804
	ldr r2, [r0]
	movs r0, 0x10
	lsls r0, r7
	ldrb r1, [r2, 0x4]
	orrs r0, r1
	strb r0, [r2, 0x4]
_082E67F2:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E67FC: .4byte 0x00008042
_082E6800: .4byte 0x03007898
_082E6804: .4byte 0x03007894
	thumb_func_end rfu_STC_UNI_receive

	thumb_func_start rfu_STC_NI_receive_Sender
rfu_STC_NI_receive_Sender: ; 82E6808
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r2, 0
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r1, _082E68D4
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	mov r12, r0
	ldrh r0, [r0]
	mov r9, r0
	mov r0, r12
	adds r0, 0x21
	ldrb r2, [r6, 0x4]
	adds r0, r2
	ldrb r0, [r0]
	str r0, [sp]
	ldrb r2, [r6, 0x2]
	cmp r2, 0x2
	bne _082E6844
	ldr r0, _082E68D8
	cmp r9, r0
	beq _082E685E
_082E6844:
	cmp r2, 0x1
	bne _082E684E
	ldr r0, _082E68DC
	cmp r9, r0
	beq _082E685E
_082E684E:
	movs r3, 0x1B
	add r3, r12
	mov r8, r3
	cmp r2, 0x3
	bne _082E6882
	ldr r0, _082E68E0
	cmp r9, r0
	bne _082E6882
_082E685E:
	ldrb r1, [r6, 0x4]
	mov r0, r12
	adds r0, 0x21
	adds r0, r1
	ldrb r0, [r0]
	movs r7, 0x1B
	add r7, r12
	mov r8, r7
	ldrb r2, [r6, 0x5]
	cmp r0, r2
	bne _082E6882
	adds r0, r7, r1
	movs r1, 0x1
	mov r3, r10
	lsls r1, r3
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
_082E6882:
	ldrb r2, [r6, 0x4]
	mov r7, r8
	adds r0, r7, r2
	ldrb r0, [r0]
	mov r3, r12
	ldrb r1, [r3, 0x1A]
	ands r0, r1
	cmp r0, r1
	bne _082E697E
	adds r3, 0x21
	adds r2, r3, r2
	ldrb r0, [r2]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	movs r1, 0
	strb r0, [r2]
	ldrb r0, [r6, 0x4]
	add r0, r8
	strb r1, [r0]
	mov r7, r12
	ldrh r1, [r7]
	ldr r2, _082E68E4
	adds r0, r1, r2
	lsls r0, 16
	lsrs r0, 16
	adds r5, r3, 0
	cmp r0, 0x1
	bhi _082E6970
	ldr r0, _082E68DC
	cmp r1, r0
	bne _082E68E8
	ldrb r1, [r6, 0x4]
	lsls r1, 2
	subs r3, 0x1D
	adds r1, r3, r1
	ldrh r2, [r7, 0x2E]
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	b _082E68FE
	.align 2, 0
_082E68D4: .4byte 0x03007880
_082E68D8: .4byte 0x00008022
_082E68DC: .4byte 0x00008021
_082E68E0: .4byte 0x00008023
_082E68E4: .4byte 0x00007fdf
_082E68E8:
	ldrb r2, [r6, 0x4]
	lsls r2, 2
	mov r3, r12
	adds r3, 0x4
	adds r2, r3, r2
	mov r7, r12
	ldrh r1, [r7, 0x2E]
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
_082E68FE:
	mov r0, r12
	ldrh r1, [r0, 0x2E]
	ldr r0, [r0, 0x14]
	subs r0, r1
	mov r1, r12
	str r0, [r1, 0x14]
	cmp r0, 0
	beq _082E6912
	cmp r0, 0
	bge _082E697E
_082E6912:
	mov r0, r12
	adds r0, 0x20
	movs r2, 0
	strb r2, [r0]
	mov r7, r12
	ldrh r1, [r7]
	ldr r0, _082E6954
	cmp r1, r0
	bne _082E695C
	movs r4, 0
_082E6926:
	adds r0, r5, r4
	movs r1, 0x1
	strb r1, [r0]
	lsls r1, r4, 2
	adds r1, r3, r1
	mov r2, r12
	ldrh r0, [r2, 0x2E]
	adds r2, r0, 0
	muls r2, r4
	mov r7, r12
	ldr r0, [r7, 0x28]
	adds r0, r2
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _082E6926
	ldr r0, [r7, 0x30]
	str r0, [r7, 0x14]
	ldr r0, _082E6958
	strh r0, [r7]
	b _082E697E
	.align 2, 0
_082E6954: .4byte 0x00008021
_082E6958: .4byte 0x00008022
_082E695C:
	strb r2, [r5]
	mov r0, r12
	str r2, [r0, 0x14]
	ldr r0, _082E696C
	mov r1, r12
	strh r0, [r1]
	b _082E697E
	.align 2, 0
_082E696C: .4byte 0x00008023
_082E6970:
	lsls r1, 16
	ldr r0, _082E69E0
	cmp r1, r0
	bne _082E697E
	ldr r0, _082E69E4
	mov r2, r12
	strh r0, [r2]
_082E697E:
	mov r3, r12
	ldrh r0, [r3]
	cmp r0, r9
	bne _082E69A8
	ldrb r2, [r6, 0x4]
	mov r0, r12
	adds r0, 0x21
	adds r0, r2
	ldrb r0, [r0]
	ldr r7, [sp]
	cmp r0, r7
	bne _082E69A8
	mov r1, r8
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r2, r10
	asrs r0, r2
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _082E69CE
_082E69A8:
	ldr r4, _082E69E8
	ldrh r2, [r4]
	movs r0, 0
	strh r0, [r4]
	ldr r0, _082E69EC
	ldr r3, [r0]
	movs r0, 0x10
	mov r7, r10
	lsls r0, r7
	ldrb r1, [r3, 0x2]
	orrs r0, r1
	movs r1, 0
	strb r0, [r3, 0x2]
	lsls r0, r7, 2
	ldr r3, _082E69F0
	adds r0, r3
	ldr r0, [r0]
	strh r1, [r0, 0x2]
	strh r2, [r4]
_082E69CE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E69E0: .4byte 0x80230000
_082E69E4: .4byte 0x00008020
_082E69E8: .4byte 0x04000208
_082E69EC: .4byte 0x03007894
_082E69F0: .4byte 0x03007880
	thumb_func_end rfu_STC_NI_receive_Sender

	thumb_func_start rfu_STC_NI_receive_Receiver
rfu_STC_NI_receive_Receiver: ; 82E69F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r1, 0
	str r2, [sp]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	ldr r1, _082E6A54
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r5, r4, 0
	adds r5, 0x34
	ldrh r0, [r4, 0x34]
	mov r9, r0
	ldrb r0, [r6, 0x4]
	adds r3, r4, 0
	adds r3, 0x55
	adds r0, r3, r0
	ldrb r0, [r0]
	mov r10, r0
	ldrb r0, [r6, 0x2]
	cmp r0, 0x3
	bne _082E6A64
	ldr r0, _082E6A58
	ldr r2, [r0]
	movs r0, 0x1
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r2, 0x1]
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrh r1, [r4, 0x34]
	ldr r0, _082E6A5C
	cmp r1, r0
	bne _082E6AAA
	adds r0, r4, 0
	adds r0, 0x54
	strb r7, [r0]
	strb r7, [r3]
	ldr r0, _082E6A60
	strh r0, [r4, 0x34]
	b _082E6AAA
	.align 2, 0
_082E6A54: .4byte 0x03007880
_082E6A58: .4byte 0x03007894
_082E6A5C: .4byte 0x00008042
_082E6A60: .4byte 0x00008043
_082E6A64:
	cmp r0, 0x2
	bne _082E6A90
	ldr r0, _082E6A88
	cmp r9, r0
	bne _082E6A7C
	ldr r0, [r5, 0x14]
	cmp r0, 0
	bne _082E6A7C
	mov r0, r8
	adds r1, r5, 0
	bl rfu_STC_NI_initSlot_asRecvDataEntity
_082E6A7C:
	ldrh r1, [r5]
	ldr r0, _082E6A8C
	cmp r1, r0
	bne _082E6AAA
	b _082E6AAE
	.align 2, 0
_082E6A88: .4byte 0x00008041
_082E6A8C: .4byte 0x00008042
_082E6A90:
	cmp r0, 0x1
	bne _082E6AAA
	ldr r7, _082E6B5C
	cmp r9, r7
	beq _082E6AAE
	mov r0, r8
	adds r1, r5, 0
	bl rfu_STC_NI_initSlot_asRecvControllData
	ldrh r0, [r4, 0x34]
	cmp r0, r7
	bne _082E6B4A
	movs r7, 0x1
_082E6AAA:
	cmp r7, 0
	beq _082E6B04
_082E6AAE:
	ldrb r2, [r6, 0x5]
	ldrb r3, [r6, 0x4]
	adds r4, r5, 0
	adds r4, 0x21
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	cmp r2, r0
	bne _082E6B04
	ldr r0, _082E6B60
	ldr r0, [r0]
	lsls r1, r3, 2
	adds r1, 0x4
	adds r1, r5, r1
	ldrh r2, [r6, 0x6]
	ldr r3, [r0, 0x4]
	mov r0, sp
	bl _call_via_r3
	ldrh r1, [r5]
	ldr r0, _082E6B64
	cmp r1, r0
	bne _082E6AF4
	ldrb r0, [r6, 0x4]
	lsls r0, 2
	adds r2, r5, 0x4
	adds r2, r0
	ldrh r0, [r5, 0x2E]
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
_082E6AF4:
	ldrh r1, [r6, 0x6]
	ldr r0, [r5, 0x14]
	subs r0, r1
	str r0, [r5, 0x14]
	ldrb r0, [r6, 0x4]
	adds r0, r4, r0
	ldrb r1, [r6, 0x5]
	strb r1, [r0]
_082E6B04:
	ldrh r0, [r5, 0x18]
	cmp r0, 0
	bne _082E6B4A
	ldrb r0, [r6, 0x4]
	adds r1, r5, 0
	adds r1, 0x20
	strb r0, [r1]
	ldrh r0, [r5]
	cmp r0, r9
	bne _082E6B2C
	adds r0, r5, 0
	adds r0, 0x21
	ldrb r2, [r6, 0x4]
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, r10
	bne _082E6B2C
	ldrb r6, [r6, 0x5]
	cmp r0, r6
	bne _082E6B4A
_082E6B2C:
	ldr r3, _082E6B68
	ldrh r2, [r3]
	movs r0, 0
	strh r0, [r3]
	ldr r0, _082E6B6C
	ldr r4, [r0]
	movs r0, 0x1
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r4, 0x2]
	orrs r0, r1
	movs r1, 0
	strb r0, [r4, 0x2]
	strh r1, [r5, 0x2]
	strh r2, [r3]
_082E6B4A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6B5C: .4byte 0x00008041
_082E6B60: .4byte 0x03007898
_082E6B64: .4byte 0x00008042
_082E6B68: .4byte 0x04000208
_082E6B6C: .4byte 0x03007894
	thumb_func_end rfu_STC_NI_receive_Receiver

	thumb_func_start rfu_STC_NI_initSlot_asRecvControllData
rfu_STC_NI_initSlot_asRecvControllData: ; 82E6B70
	push {r4-r7,lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _082E6B8C
	ldr r3, [r0]
	ldrb r1, [r3]
	mov r12, r0
	cmp r1, 0x1
	bne _082E6B90
	movs r5, 0x3
	adds r1, r3, 0
	adds r1, 0xF
	b _082E6B98
	.align 2, 0
_082E6B8C: .4byte 0x03007890
_082E6B90:
	movs r5, 0x2
	adds r0, r4, 0
	adds r0, 0x10
	adds r1, r3, r0
_082E6B98:
	movs r7, 0x1
	adds r0, r7, 0
	lsls r0, r4
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, r6, 0
	ldrh r3, [r2]
	cmp r3, 0
	bne _082E6BF6
	ldrb r0, [r1]
	cmp r0, r5
	bcs _082E6BD0
	movs r0, 0x49
	strh r0, [r2]
	ldr r0, _082E6BC8
	strh r0, [r2, 0x18]
	ldr r0, _082E6BCC
	ldr r2, [r0]
	ldrb r1, [r2, 0x4]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2, 0x4]
	b _082E6BF6
	.align 2, 0
_082E6BC8: .4byte 0x00000702
_082E6BCC: .4byte 0x03007894
_082E6BD0:
	strh r3, [r2, 0x18]
	ldrb r0, [r1]
	subs r0, r5
	strb r0, [r1]
	adds r0, r2, 0
	adds r0, 0x2D
	str r0, [r2, 0x4]
	movs r0, 0x7
	str r0, [r2, 0x14]
	strb r7, [r2, 0x1F]
	strh r3, [r2, 0x2E]
	strb r4, [r2, 0x1A]
	ldr r0, _082E6BFC
	strh r0, [r2]
	mov r0, r12
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	orrs r4, r0
	strb r4, [r1, 0x5]
_082E6BF6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6BFC: .4byte 0x00008041
	thumb_func_end rfu_STC_NI_initSlot_asRecvControllData

	thumb_func_start rfu_STC_NI_initSlot_asRecvDataEntity
rfu_STC_NI_initSlot_asRecvDataEntity: ; 82E6C00
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E6C24
	ldr r0, _082E6C20
	lsls r1, r5, 5
	adds r1, 0x14
	ldr r0, [r0]
	adds r0, r1
	adds r0, 0x4
	b _082E6C7A
	.align 2, 0
_082E6C20: .4byte 0x03007890
_082E6C24:
	ldr r1, _082E6C68
	lsls r0, r5, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r1, [r4, 0x30]
	ldr r0, [r2, 0x6C]
	cmp r1, r0
	bls _082E6C78
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r5
	lsrs r1, 24
	ldr r0, _082E6C6C
	ldr r3, [r0]
	ldrb r2, [r3, 0x4]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r3, 0x4]
	ldr r0, _082E6C70
	ldr r2, [r0]
	ldrb r0, [r2, 0x5]
	bics r0, r1
	strb r0, [r2, 0x5]
	ldr r0, _082E6C74
	strh r0, [r4, 0x18]
	movs r0, 0x47
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl rfu_STC_releaseFrame
	b _082E6CAC
	.align 2, 0
_082E6C68: .4byte 0x03007880
_082E6C6C: .4byte 0x03007894
_082E6C70: .4byte 0x03007890
_082E6C74: .4byte 0x00000701
_082E6C78:
	ldr r0, [r2, 0x68]
_082E6C7A:
	str r0, [r4, 0x4]
	movs r3, 0
	adds r6, r4, 0
	adds r6, 0x21
	movs r7, 0
	adds r5, r4, 0x4
_082E6C86:
	adds r0, r6, r3
	strb r7, [r0]
	lsls r1, r3, 2
	adds r1, r5, r1
	ldrh r0, [r4, 0x2E]
	adds r2, r0, 0
	muls r2, r3
	ldr r0, [r4, 0x4]
	adds r0, r2
	str r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _082E6C86
	ldr r0, [r4, 0x30]
	str r0, [r4, 0x14]
	ldr r0, _082E6CB4
	strh r0, [r4]
_082E6CAC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6CB4: .4byte 0x00008042
	thumb_func_end rfu_STC_NI_initSlot_asRecvDataEntity

	thumb_func_start rfu_NI_checkCommFailCounter
rfu_NI_checkCommFailCounter: ; 82E6CB8
	push {r4-r7,lr}
	ldr r2, _082E6D44
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	orrs r0, r1
	cmp r0, 0
	beq _082E6D3E
	ldr r1, _082E6D48
	ldrh r0, [r1]
	mov r12, r0
	movs r0, 0
	strh r0, [r1]
	ldr r1, _082E6D4C
	ldr r0, [r1]
	ldrb r0, [r0, 0x2]
	lsrs r7, r0, 4
	movs r3, 0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r4, _082E6D50
_082E6CE2:
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r3
	lsrs r2, r0, 24
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	ands r0, r2
	cmp r0, 0
	beq _082E6D0A
	ldr r0, [r6]
	ldrb r0, [r0, 0x2]
	ands r0, r2
	cmp r0, 0
	bne _082E6D0A
	lsls r0, r3, 2
	adds r0, r4
	ldr r1, [r0]
	ldrh r0, [r1, 0x2]
	adds r0, 0x1
	strh r0, [r1, 0x2]
_082E6D0A:
	ldr r0, [r5]
	ldrb r0, [r0, 0x5]
	ands r0, r2
	cmp r0, 0
	beq _082E6D28
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	bne _082E6D28
	lsls r0, r3, 2
	adds r0, r4
	ldr r1, [r0]
	ldrh r0, [r1, 0x36]
	adds r0, 0x1
	strh r0, [r1, 0x36]
_082E6D28:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _082E6CE2
	ldr r0, [r6]
	movs r1, 0
	strb r1, [r0, 0x2]
	ldr r0, _082E6D48
	mov r1, r12
	strh r1, [r0]
_082E6D3E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_082E6D44: .4byte 0x03007890
_082E6D48: .4byte 0x04000208
_082E6D4C: .4byte 0x03007894
_082E6D50: .4byte 0x03007880
	thumb_func_end rfu_NI_checkCommFailCounter

	thumb_func_start rfu_REQ_noise
rfu_REQ_noise: ; 82E6D54
	push {lr}
	ldr r0, _082E6D68
	bl STWI_set_Callback_M
	movs r0, 0x1
	movs r1, 0
	bl STWI_send_TestModeREQ
	pop {r0}
	bx r0
	.align 2, 0
_082E6D68: .4byte rfu_STC_REQ_callback + 1
	thumb_func_end rfu_REQ_noise

	thumb_func_start sub_82E6D6C
sub_82E6D6C: ; 82E6D6C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _082E6D84
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E6D88
	movs r0, 0x1
	negs r0, r0
	b _082E6E08
	.align 2, 0
_082E6D84: .4byte 0x04000208
_082E6D88:
	ldr r0, _082E6DB4
	ldrh r0, [r0]
	mov r8, r0
	ldr r4, _082E6DB8
	ldr r1, [r4]
	movs r0, 0xA
	str r0, [r1]
	ldr r0, _082E6DBC
	bl STWI_set_Callback_ID
	bl sub_82E6E20
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r1, _082E6DC0
	adds r4, r0, r1
	lsls r0, r5, 27
	lsrs r5, r0, 24
	movs r7, 0
	b _082E6DD6
	.align 2, 0
_082E6DB4: .4byte 0x04000200
_082E6DB8: .4byte 0x03007868
_082E6DBC: .4byte sub_82E6F88 + 1
_082E6DC0: .4byte 0x04000100
_082E6DC4:
	strh r6, [r4, 0x2]
	strh r6, [r4]
	movs r0, 0x83
	strh r0, [r4, 0x2]
_082E6DCC:
	ldrh r0, [r4]
	cmp r0, 0x1F
	bls _082E6DCC
	strh r7, [r4, 0x2]
	strh r7, [r4]
_082E6DD6:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xFF
	beq _082E6DEA
	bl sub_82E6E94
	adds r6, r0, 0
	cmp r6, 0
	beq _082E6DC4
_082E6DEA:
	ldr r1, _082E6E14
	movs r0, 0
	strh r0, [r1]
	ldr r0, _082E6E18
	mov r2, r8
	strh r2, [r0]
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, _082E6E1C
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1]
	bl STWI_set_Callback_ID
	adds r0, r6, 0
_082E6E08:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_082E6E14: .4byte 0x04000208
_082E6E18: .4byte 0x04000200
_082E6E1C: .4byte 0x03007868
	thumb_func_end sub_82E6D6C

	thumb_func_start sub_82E6E20
sub_82E6E20: ; 82E6E20
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r3, _082E6E78
	movs r4, 0
	strh r4, [r3]
	ldr r2, _082E6E7C
	ldr r0, _082E6E80
	ldr r0, [r0]
	movs r1, 0x8
	ldrb r0, [r0, 0xA]
	lsls r1, r0
	movs r5, 0x80
	orrs r1, r5
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldr r0, _082E6E84
	strh r4, [r0]
	subs r2, 0xD8
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, 0x81
	lsls r3, 7
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0
	str r0, [sp]
	ldr r1, _082E6E88
	ldr r2, _082E6E8C
	mov r0, sp
	bl CpuSet
	ldr r0, _082E6E90
	strh r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E6E78: .4byte 0x04000208
_082E6E7C: .4byte 0x04000200
_082E6E80: .4byte 0x03007868
_082E6E84: .4byte 0x04000134
_082E6E88: .4byte 0x030078a0
_082E6E8C: .4byte 0x05000003
_082E6E90: .4byte 0x04000202
	thumb_func_end sub_82E6E20

	thumb_func_start sub_82E6E94
sub_82E6E94: ; 82E6E94
	push {r4-r7,lr}
	ldr r0, _082E6EA8
	ldrb r1, [r0, 0x1]
	mov r12, r1
	adds r7, r0, 0
	cmp r1, 0
	beq _082E6EAC
	cmp r1, 0x1
	beq _082E6EE4
	b _082E6F7C
	.align 2, 0
_082E6EA8: .4byte 0x030078a0
_082E6EAC:
	movs r6, 0x1
	strb r6, [r7]
	ldr r3, _082E6ED8
	ldrh r0, [r3]
	movs r5, 0x1
	orrs r0, r5
	strh r0, [r3]
	ldr r4, _082E6EDC
	mov r0, r12
	strh r0, [r4]
	ldr r2, _082E6EE0
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	strh r6, [r4]
	strb r5, [r7, 0x1]
	ldrb r0, [r3]
	orrs r0, r1
	strb r0, [r3]
	b _082E6F80
	.align 2, 0
_082E6ED8: .4byte 0x04000128
_082E6EDC: .4byte 0x04000208
_082E6EE0: .4byte 0x04000200
_082E6EE4:
	ldrh r0, [r7, 0xA]
	cmp r0, 0
	bne _082E6F78
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _082E6F14
	ldrh r0, [r7, 0x2]
	cmp r0, 0
	bne _082E6F80
	ldr r3, _082E6F0C
	strh r0, [r3]
	ldr r2, _082E6F10
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	mov r1, r12
	strh r1, [r3]
	b _082E6F80
	.align 2, 0
_082E6F0C: .4byte 0x04000208
_082E6F10: .4byte 0x04000128
_082E6F14:
	ldrh r1, [r7, 0x4]
	ldr r0, _082E6F60
	cmp r1, r0
	beq _082E6F80
	ldrh r6, [r7, 0x2]
	cmp r6, 0
	bne _082E6F80
	ldr r4, _082E6F64
	strh r6, [r4]
	ldr r3, _082E6F68
	ldrh r1, [r3]
	ldr r0, _082E6F6C
	ands r0, r1
	strh r0, [r3]
	mov r7, r12
	strh r7, [r4]
	ldr r2, _082E6F70
	strh r6, [r2]
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	strh r0, [r2]
	ldr r0, _082E6F74
	movs r5, 0x80
	strh r5, [r0]
	ldrh r0, [r2]
	movs r7, 0x81
	lsls r7, 7
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	strh r6, [r4]
	ldrh r0, [r3]
	orrs r0, r5
	strh r0, [r3]
	mov r0, r12
	strh r0, [r4]
	b _082E6F80
	.align 2, 0
_082E6F60: .4byte 0x00008001
_082E6F64: .4byte 0x04000208
_082E6F68: .4byte 0x04000200
_082E6F6C: .4byte 0x0000ff7f
_082E6F70: .4byte 0x04000128
_082E6F74: .4byte 0x04000202
_082E6F78:
	movs r0, 0x2
	strb r0, [r7, 0x1]
_082E6F7C:
	ldrh r0, [r7, 0xA]
	b _082E6F82
_082E6F80:
	movs r0, 0
_082E6F82:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_82E6E94

	thumb_func_start sub_82E6F88
sub_82E6F88: ; 82E6F88
	push {r4,r5,lr}
	ldr r0, _082E6FD0
	ldr r5, [r0]
	ldr r0, _082E6FD4
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x1
	beq sub_82E6FA2
	ldr r0, _082E6FD8
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	thumb_func_end sub_82E6F88

	non_word_aligned_thumb_func_start sub_82E6FA2
sub_82E6FA2: ; 82E6FA2
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r0, r5, 0
	lsls r0, r1
	lsrs r1, r0, 16
	movs r0, 0x1
	subs r0, r2
	lsls r0, 4
	lsls r5, r0
	adds r0, r5, 0
	lsrs r5, r0, 16
	ldrh r0, [r4, 0xA]
	cmp r0, 0
	bne _082E6FF6
	ldrh r2, [r4, 0x6]
	cmp r1, r2
	bne _082E6FF4
	ldrh r3, [r4, 0x2]
	cmp r3, 0x3
	bls _082E6FDC
	strh r5, [r4, 0xA]
	b _082E6FF6
	.align 2, 0
_082E6FD0: .4byte 0x04000120
_082E6FD4: .4byte 0x030078a0
_082E6FD8: .4byte 0x04000128
_082E6FDC:
	ldrh r0, [r4, 0x4]
	mvns r0, r0
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bne _082E6FF6
	mvns r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r5, r0
	bne _082E6FF6
	adds r0, r3, 0x1
_082E6FF4:
	strh r0, [r4, 0x2]
_082E6FF6:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x3
	bhi _082E700C
	lsls r0, 1
	ldr r1, _082E7008
	adds r0, r1
	ldrh r0, [r0]
	b _082E700E
	.align 2, 0
_082E7008: .4byte 0x089a3258
_082E700C:
	ldr r0, _082E7064
_082E700E:
	strh r0, [r4, 0x4]
	mvns r0, r5
	strh r0, [r4, 0x6]
	ldr r3, _082E7068
	ldrh r2, [r4, 0x4]
	ldrb r1, [r4]
	movs r0, 0x1
	subs r0, r1
	lsls r0, 4
	lsls r2, r0
	ldrh r0, [r4, 0x6]
	lsls r1, 4
	lsls r0, r1
	adds r2, r0
	str r2, [r3]
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _082E705C
	ldrh r0, [r4, 0x2]
	cmp r0, 0
	bne _082E703E
	ldr r0, _082E706C
	cmp r5, r0
	bne _082E705C
_082E703E:
	movs r0, 0
	ldr r1, _082E7070
_082E7042:
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bls _082E7042
	ldrh r0, [r4, 0xA]
	cmp r0, 0
	bne _082E705C
	ldr r0, _082E7074
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
_082E705C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_082E7064: .4byte 0x00008001
_082E7068: .4byte 0x04000120
_082E706C: .4byte 0x0000494e
_082E7070: .4byte 0x00000257
_082E7074: .4byte 0x04000128
	thumb_func_end sub_82E6FA2
