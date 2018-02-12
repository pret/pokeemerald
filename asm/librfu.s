	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start rfu_initializeAPI
rfu_initializeAPI: @ 82E3EB4
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
	ldr r3, =0x00000e64
	b _082E3EEE
	.align 2, 0
	.pool
_082E3EEC:
	ldr r3, =0x00000504
_082E3EEE:
	cmp r2, r3
	bcs _082E3EFC
	movs r0, 0x1
	b _082E3FB8
	.align 2, 0
	.pool
_082E3EFC:
	ldr r0, =gUnknown_03007890
	str r4, [r0]
	ldr r1, =gUnknown_03007894
	adds r0, r4, 0
	adds r0, 0xB4
	str r0, [r1]
	ldr r1, =gUnknown_03007898
	adds r0, 0x28
	str r0, [r1]
	ldr r2, =gUnknown_03007880
	movs r1, 0xDE
	lsls r1, 1
	adds r0, r4, r1
	str r0, [r2]
	ldr r1, =gUnknown_03007870
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
	ldr r0, =gUnknown_03007898
	ldr r1, [r0]
	adds r1, 0xDC
	ldr r4, =gUnknown_03007870
	ldr r0, [r4, 0xC]
	adds r0, 0x1C
	str r0, [r1]
	mov r1, r12
	adds r2, r7, 0
	bl STWI_init_all
	bl rfu_STC_clearAPIVariables
	movs r5, 0
	ldr r3, =gUnknown_03007880
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
	ldr r4, =sub_82E53F4
	movs r0, 0x2
	negs r0, r0
	ands r4, r0
	ldr r1, =gUnknown_03007898
	ldr r0, [r1]
	adds r2, r0, 0
	adds r2, 0x8
	movs r3, 0x2F
	ldr r5, =0x0000ffff
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
	.pool
	thumb_func_end rfu_initializeAPI

	thumb_func_start rfu_STC_clearAPIVariables
rfu_STC_clearAPIVariables: @ 82E3FDC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =0x04000208
	ldrh r0, [r1]
	adds r7, r0, 0
	movs r6, 0
	strh r6, [r1]
	ldr r5, =gUnknown_03007894
	ldr r1, [r5]
	ldrb r4, [r1]
	mov r0, sp
	strh r6, [r0]
	ldr r2, =0x01000014
	bl CpuSet
	ldr r2, [r5]
	movs r0, 0x8
	ands r4, r0
	movs r1, 0
	strb r4, [r2]
	mov r0, sp
	adds r0, 0x2
	strh r1, [r0]
	ldr r4, =gUnknown_03007890
	ldr r1, [r4]
	ldr r2, =0x0100005a
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
	ldr r0, =0x04000208
	strh r7, [r0]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_STC_clearAPIVariables

	thumb_func_start rfu_REQ_PARENT_resumeRetransmitAndChange
rfu_REQ_PARENT_resumeRetransmitAndChange: @ 82E4064
	push {lr}
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	bl STWI_send_ResumeRetransmitAndChangeREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_PARENT_resumeRetransmitAndChange

	thumb_func_start rfu_UNI_PARENT_getDRAC_ACK
rfu_UNI_PARENT_getDRAC_ACK: @ 82E4078
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r4]
	ldr r5, =gUnknown_03007890
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _082E4094
	movs r0, 0xC0
	lsls r0, 2
	b _082E40BA
	.align 2, 0
	.pool
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
rfu_setTimerInterrupt: @ 82E40C0
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
rfu_getSTWIRecvBuffer: @ 82E40D4
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end rfu_getSTWIRecvBuffer

	thumb_func_start rfu_setMSCCallback
rfu_setMSCCallback: @ 82E40E4
	push {lr}
	bl STWI_set_Callback_S
	pop {r0}
	bx r0
	thumb_func_end rfu_setMSCCallback

	thumb_func_start rfu_setREQCallback
rfu_setREQCallback: @ 82E40F0
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	str r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bl rfu_enableREQCallback
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_setREQCallback

	thumb_func_start rfu_enableREQCallback
rfu_enableREQCallback: @ 82E410C
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _082E4124
	ldr r0, =gUnknown_03007894
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	b _082E412E
	.align 2, 0
	.pool
_082E4124:
	ldr r0, =gUnknown_03007894
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0xF7
	ands r0, r1
_082E412E:
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_enableREQCallback

	thumb_func_start rfu_STC_REQ_callback
rfu_STC_REQ_callback: @ 82E4138
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r0, =rfu_CB_defaultCallback
	bl STWI_set_Callback_M
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	strh r4, [r0, 0x1C]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _082E4166
	ldr r0, =gUnknown_03007898
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
	.pool
	thumb_func_end rfu_STC_REQ_callback

	thumb_func_start rfu_CB_defaultCallback
rfu_CB_defaultCallback: @ 82E4178
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	cmp r0, 0xFF
	bne _082E41D4
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _082E41A2
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	ldr r2, [r0]
	movs r0, 0xFF
	adds r1, r3, 0
	bl _call_via_r2
_082E41A2:
	ldr r0, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	movs r0, 0xFF
	strb r0, [r1]
_082E41D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_CB_defaultCallback

	thumb_func_start rfu_waitREQComplete
rfu_waitREQComplete: @ 82E41E8
	push {lr}
	bl STWI_poll_CommandEnd
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	ldrh r0, [r0, 0x1C]
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end rfu_waitREQComplete

	thumb_func_start rfu_REQ_RFUStatus
rfu_REQ_RFUStatus: @ 82E41FC
	push {lr}
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_RFUStatus

	thumb_func_start rfu_getRFUStatus
rfu_getRFUStatus: @ 82E4210
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_03007898
	ldr r0, [r5]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x93
	beq _082E422C
	movs r0, 0x10
	b _082E4246
	.align 2, 0
	.pool
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
sub_82E424C: @ 82E424C
	push {lr}
	ldr r2, =gUnknown_089A324C
	ldr r3, =gDma3Requests + 0xE0
	b _082E4266
	.align 2, 0
	.pool
	thumb_func_end sub_82E424C

	thumb_func_start sub_82E425C
sub_82E425C: @ 82E425C
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
	ldr r0, =gDma3Requests + 0xEA
	ldrh r0, [r0]
	cmp r3, r0
	bne _082E42BC
	movs r0, 0xC0
	lsls r0, 18
	ldr r1, =gUnknown_03007890
	ldr r1, [r1]
	movs r2, 0x5A
	bl CpuSet
	ldr r0, =gUnknown_03007894
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0
	b _082E42BE
	.align 2, 0
	.pool
_082E42BC:
	movs r0, 0x1
_082E42BE:
	pop {r1}
	bx r1
	thumb_func_end sub_82E425C

	thumb_func_start rfu_REQ_stopMode
rfu_REQ_stopMode: @ 82E42C4
	push {lr}
	ldr r0, =0x04000208
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E42EC
	movs r0, 0x3D
	movs r1, 0x6
	bl rfu_STC_REQ_callback
	ldr r0, =gRfuState
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	movs r0, 0x6
	strh r0, [r1, 0x12]
	b _082E4362
	.align 2, 0
	.pool
_082E42EC:
	bl AgbRFU_SoftReset
	bl rfu_STC_clearAPIVariables
	movs r0, 0x8
	bl sub_82E6D6C
	ldr r1, =0x00008001
	cmp r0, r1
	bne _082E4350
	ldr r0, =gRfuState
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r2, =0x04000100
	adds r1, r0, r2
	movs r0, 0
	str r0, [r1]
	movs r0, 0x83
	lsls r0, 16
	str r0, [r1]
	ldr r0, [r1]
	lsls r0, 16
	ldr r2, =0x0105ffff
	ldr r3, =rfu_CB_stopMode
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
	.pool
_082E4350:
	ldr r1, =0x04000128
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
	.pool
	thumb_func_end rfu_REQ_stopMode

	thumb_func_start rfu_CB_stopMode
rfu_CB_stopMode: @ 82E436C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r2, r1, 0
	cmp r2, 0
	bne _082E4386
	ldr r1, =0x04000128
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
	.pool
	thumb_func_end rfu_CB_stopMode

	thumb_func_start rfu_REQBN_softReset_and_checkID
rfu_REQBN_softReset_and_checkID: @ 82E4398
	push {lr}
	ldr r0, =0x04000208
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E43AC
	movs r0, 0x1
	negs r0, r0
	b _082E43CC
	.align 2, 0
	.pool
_082E43AC:
	bl AgbRFU_SoftReset
	bl rfu_STC_clearAPIVariables
	movs r0, 0x1E
	bl sub_82E6D6C
	adds r2, r0, 0
	cmp r2, 0
	bne _082E43CA
	ldr r1, =0x04000128
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
	.pool
	thumb_func_end rfu_REQBN_softReset_and_checkID

	thumb_func_start rfu_REQ_reset
rfu_REQ_reset: @ 82E43D4
	push {lr}
	ldr r0, =rfu_CB_reset
	bl STWI_set_Callback_M
	bl STWI_send_ResetREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_reset

	thumb_func_start rfu_CB_reset
rfu_CB_reset: @ 82E43E8
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
rfu_REQ_configSystem: @ 82E440C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =rfu_STC_REQ_callback
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
	ldr r0, =gUnknown_03007894
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x1A]
	b _082E4466
	.align 2, 0
	.pool
_082E444C:
	ldr r5, =0x04000208
	ldrh r4, [r5]
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x96
	lsls r0, 2
	adds r1, r6, 0
	bl Div
	ldr r1, =gUnknown_03007894
	ldr r1, [r1]
	strh r0, [r1, 0x1A]
	strh r4, [r5]
_082E4466:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_configSystem

	thumb_func_start rfu_REQ_configGameData
rfu_REQ_configGameData: @ 82E4474
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
	ldr r0, =rfu_CB_configGameData
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
	.pool
	thumb_func_end rfu_REQ_configGameData

	thumb_func_start rfu_CB_configGameData
rfu_CB_configGameData: @ 82E4500
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E458A
	ldr r0, =gRfuState
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	ldr r0, =gUnknown_03007890
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
	.pool
_082E454C:
	adds r1, r6, 0
	adds r1, 0x97
	movs r0, 0
_082E4552:
	strb r0, [r1]
	movs r2, 0
	ldr r3, =gUnknown_03007890
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
	ldr r3, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_CB_configGameData

	thumb_func_start rfu_REQ_startSearchChild
rfu_REQ_startSearchChild: @ 82E459C
	push {r4,lr}
	movs r1, 0
	ldr r4, =rfu_CB_defaultCallback
	ldr r3, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007898
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
	.pool
_082E45F0:
	movs r0, 0x19
	bl rfu_STC_REQ_callback
_082E45F6:
	ldr r0, =rfu_CB_startSearchChild
	bl STWI_set_Callback_M
	bl STWI_send_SC_StartREQ
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_startSearchChild

	thumb_func_start rfu_CB_startSearchChild
rfu_CB_startSearchChild: @ 82E460C
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r1, 16
	adds r2, r1, 0
	cmp r2, 0
	bne _082E4624
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_CB_startSearchChild

	thumb_func_start rfu_STC_clearLinkStatus
rfu_STC_clearLinkStatus: @ 82E4634
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
	ldr r4, =gUnknown_03007890
	ldr r1, [r4]
	adds r1, 0x14
	ldr r2, =0x01000040
	bl CpuSet
	ldr r0, [r4]
	strb r5, [r0, 0x8]
_082E465C:
	movs r1, 0
	ldr r2, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_STC_clearLinkStatus

	thumb_func_start rfu_REQ_pollSearchChild
rfu_REQ_pollSearchChild: @ 82E4698
	push {lr}
	ldr r0, =rfu_CB_pollAndEndSearchChild
	bl STWI_set_Callback_M
	bl STWI_send_SC_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_pollSearchChild

	thumb_func_start rfu_REQ_endSearchChild
rfu_REQ_endSearchChild: @ 82E46AC
	push {lr}
	ldr r0, =rfu_CB_pollAndEndSearchChild
	bl STWI_set_Callback_M
	bl STWI_send_SC_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_endSearchChild

	thumb_func_start rfu_CB_pollAndEndSearchChild
rfu_CB_pollAndEndSearchChild: @ 82E46C0
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
	ldr r5, =gUnknown_03007890
	ldr r0, [r5]
	adds r0, 0x94
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E4730
	ldr r0, =rfu_CB_defaultCallback
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E4730
	ldr r1, [r5]
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	adds r1, 0x94
	strh r0, [r1]
	b _082E4730
	.align 2, 0
	.pool
_082E4714:
	cmp r4, 0x1B
	bne _082E4730
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _082E4728
	adds r1, 0x94
	movs r0, 0
	strh r0, [r1]
_082E4728:
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_CB_pollAndEndSearchChild

	thumb_func_start rfu_STC_readChildList
rfu_STC_readChildList: @ 82E4748
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r7, [r0, 0x1]
	adds r6, r0, 0x4
	cmp r7, 0
	beq _082E47EE
	ldr r0, =gUnknown_03007894
	mov r8, r0
	ldr r1, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_STC_readChildList

	thumb_func_start rfu_REQ_startSearchParent
rfu_REQ_startSearchParent: @ 82E4804
	push {lr}
	ldr r0, =rfu_CB_startSearchParent
	bl STWI_set_Callback_M
	bl STWI_send_SP_StartREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_startSearchParent

	thumb_func_start rfu_CB_startSearchParent
rfu_CB_startSearchParent: @ 82E4818
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
rfu_REQ_pollSearchParent: @ 82E483C
	push {lr}
	ldr r0, =sub_82E4850
	bl STWI_set_Callback_M
	bl STWI_send_SP_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_pollSearchParent

	thumb_func_start sub_82E4850
sub_82E4850: @ 82E4850
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
rfu_REQ_endSearchParent: @ 82E4874
	push {lr}
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	bl STWI_send_SP_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_endSearchParent

	thumb_func_start rfu_STC_readParentCandidateList
rfu_STC_readParentCandidateList: @ 82E4888
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r0, sp
	movs r4, 0
	strh r4, [r0]
	ldr r5, =gUnknown_03007890
	ldr r1, [r5]
	adds r1, 0x14
	ldr r2, =0x01000040
	bl CpuSet
	ldr r0, =gUnknown_03007898
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
	ldr r0, =0x00007fff
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
	.pool
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
rfu_REQ_startConnectParent: @ 82E4998
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0
	movs r2, 0
	ldr r1, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	strh r4, [r0, 0x1E]
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	adds r0, r4, 0
	bl STWI_send_CP_StartREQ
	b _082E49F8
	.align 2, 0
	.pool
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
rfu_REQ_pollConnectParent: @ 82E4A00
	push {lr}
	ldr r0, =rfu_CB_pollConnectParent
	bl STWI_set_Callback_M
	bl STWI_send_CP_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_pollConnectParent

	thumb_func_start rfu_CB_pollConnectParent
rfu_CB_pollConnectParent: @ 82E4A14
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
	ldr r0, =gUnknown_03007898
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
	ldr r4, =gUnknown_03007890
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
	ldr r3, =gUnknown_03007894
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
	ldr r2, =0x01000040
	bl CpuSet
	ldr r0, [r7]
	mov r1, r8
	strb r1, [r0, 0x8]
	b _082E4AF4
	.align 2, 0
	.pool
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
	ldr r4, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_CB_pollConnectParent

	thumb_func_start rfu_getConnectParentStatus
rfu_getConnectParentStatus: @ 82E4B34
	push {lr}
	adds r3, r0, 0
	movs r0, 0xFF
	strb r0, [r3]
	ldr r0, =gUnknown_03007898
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
	.pool
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
rfu_REQ_endConnectParent: @ 82E4B68
	push {lr}
	ldr r0, =rfu_CB_pollConnectParent
	bl STWI_set_Callback_M
	bl STWI_send_CP_EndREQ
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0x3
	bhi _082E4B90
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_REQ_endConnectParent

	thumb_func_start rfu_syncVBlank
rfu_syncVBlank: @ 82E4BA0
	push {r4,r5,lr}
	bl rfu_NI_checkCommFailCounter
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _082E4C78
	ldr r4, =gUnknown_03007894
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
	.pool
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
	ldr r3, =gUnknown_03007894
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _082E4C1A
	.align 2, 0
	.pool
_082E4C10:
	ldr r3, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
	b _082E4C7A
	.align 2, 0
	.pool
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
rfu_REQBN_watchLink: @ 82E4C80
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
	ldr r5, =gUnknown_03007890
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _082E4CBE
	b _082E504E
_082E4CBE:
	ldr r0, =gRfuState
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _082E4CCA
	b _082E504E
_082E4CCA:
	ldr r3, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007898
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
	.pool
_082E4D30:
	movs r0, 0x9B
	lsls r0, 1
	cmp r6, r0
	bne _082E4D80
	ldr r0, =gUnknown_03007898
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
	ldr r0, =gUnknown_03007890
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
	ldr r4, =gUnknown_03007898
	ldr r0, [r4]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r1, [r0]
	str r1, [sp, 0x10]
	ldr r0, [r0, 0x4]
	str r0, [sp, 0x14]
	ldr r0, =rfu_CB_defaultCallback
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
	ldr r3, =gUnknown_03007890
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
	.pool
_082E4DE8:
	movs r0, 0x11
	ldr r1, [sp, 0xC]
	bl rfu_STC_REQ_callback
	ldr r0, [sp, 0xC]
	b _082E5050
_082E4DF4:
	ldr r1, =gUnknown_03007894
	ldr r0, [r1]
	adds r0, 0xE
	adds r2, r0, r5
	ldrb r0, [r2]
	adds r3, r1, 0
	cmp r0, 0
	beq _082E4E1A
	subs r0, 0x4
	strb r0, [r2]
	ldr r0, =gUnknown_03007890
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
	ldr r4, =gUnknown_03007890
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
	.pool
_082E4E84:
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E4F10
	ldr r0, =gUnknown_03007898
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
	.pool
_082E4EB8:
	ldr r2, =gUnknown_03007894
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
	.pool
_082E4F04:
	ldr r0, [r3]
	adds r0, 0xA
	adds r0, r5
	mov r1, sp
	ldrb r1, [r1, 0xC]
_082E4F0E:
	strb r1, [r0]
_082E4F10:
	ldr r2, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	adds r0, 0xA
	adds r0, r5
	strb r3, [r0]
	b _082E5002
	.align 2, 0
	.pool
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
	ldr r0, =gUnknown_03007898
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
	ldr r0, =gUnknown_03007894
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
	.pool
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
	ldr r0, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007890
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
	ldr r1, =gUnknown_03007898
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
	.pool
	thumb_func_end rfu_REQBN_watchLink

	thumb_func_start rfu_STC_removeLinkData
rfu_STC_removeLinkData: @ 82E506C
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
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	adds r0, 0xE
	adds r0, r7
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gUnknown_03007890
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
	ldr r1, =0x00ff00ff
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
	ldr r2, =0x01000010
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
	.pool
	thumb_func_end rfu_STC_removeLinkData

	thumb_func_start rfu_REQ_disconnect
rfu_REQ_disconnect: @ 82E512C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_03007890
	ldr r1, [r2]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	ands r0, r4
	cmp r0, 0
	beq _082E51B0
	ldr r0, =gUnknown_03007894
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
	.pool
_082E5178:
	ldr r0, [r3]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _082E51A4
	ldr r0, =rfu_CB_defaultCallback
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
	.pool
_082E51A4:
	ldr r0, =rfu_CB_disconnect
	bl STWI_set_Callback_M
	adds r0, r4, 0
	bl STWI_send_DisconnectREQ
_082E51B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_disconnect

	thumb_func_start rfu_CB_disconnect
rfu_CB_disconnect: @ 82E51BC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	cmp r5, 0x3
	bne _082E51F8
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	bne _082E51F8
	ldr r0, =rfu_CB_defaultCallback
	bl STWI_set_Callback_M
	bl STWI_send_SystemStatusREQ
	bl STWI_poll_CommandEnd
	lsls r0, 16
	cmp r0, 0
	bne _082E51F8
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _082E51F8
	movs r5, 0
_082E51F8:
	ldr r3, =gUnknown_03007894
	ldr r2, [r3]
	ldr r0, =gUnknown_03007890
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	ldrb r1, [r2, 0x5]
	ands r0, r1
	strb r0, [r2, 0x5]
	ldr r0, =gUnknown_03007898
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
	ldr r1, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _082E5286
	ldr r0, =rfu_CB_defaultCallback
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
	.pool
	thumb_func_end rfu_CB_disconnect

	thumb_func_start rfu_REQ_CHILD_startConnectRecovery
rfu_REQ_CHILD_startConnectRecovery: @ 82E529C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	strb r5, [r0, 0x5]
	movs r4, 0
	movs r0, 0x1
	ands r0, r5
	ldr r2, =rfu_STC_REQ_callback
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
	ldr r0, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_REQ_CHILD_startConnectRecovery

	thumb_func_start rfu_REQ_CHILD_pollConnectRecovery
rfu_REQ_CHILD_pollConnectRecovery: @ 82E52F8
	push {lr}
	ldr r0, =rfu_CB_CHILD_pollConnectRecovery
	bl STWI_set_Callback_M
	bl STWI_send_CPR_PollingREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_CHILD_pollConnectRecovery

	thumb_func_start rfu_CB_CHILD_pollConnectRecovery
rfu_CB_CHILD_pollConnectRecovery: @ 82E530C
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
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _082E5390
	ldr r0, =gUnknown_03007894
	ldr r1, [r0]
	ldrb r1, [r1, 0x5]
	adds r6, r0, 0
	cmp r1, 0
	beq _082E5390
	ldr r1, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_CB_CHILD_pollConnectRecovery

	thumb_func_start rfu_CHILD_getConnectRecoveryStatus
rfu_CHILD_getConnectRecoveryStatus: @ 82E53B0
	push {lr}
	adds r2, r0, 0
	movs r0, 0xFF
	strb r0, [r2]
	ldr r0, =gUnknown_03007898
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
	.pool
_082E53D4:
	ldrb r0, [r1, 0x4]
	strb r0, [r2]
	movs r0, 0
_082E53DA:
	pop {r1}
	bx r1
	thumb_func_end rfu_CHILD_getConnectRecoveryStatus

	thumb_func_start rfu_REQ_CHILD_endConnectRecovery
rfu_REQ_CHILD_endConnectRecovery: @ 82E53E0
	push {lr}
	ldr r0, =rfu_CB_CHILD_pollConnectRecovery
	bl STWI_set_Callback_M
	bl STWI_send_CPR_EndREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_CHILD_endConnectRecovery

	thumb_func_start sub_82E53F4
sub_82E53F4: @ 82E53F4
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
sub_82E540A: @ 82E540A
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
rfu_REQ_changeMasterSlave: @ 82E5424
	push {lr}
	movs r0, 0x1
	bl STWI_read_status
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _082E5444
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	bl STWI_send_MS_ChangeREQ
	b _082E544C
	.align 2, 0
	.pool
_082E5444:
	movs r0, 0x27
	movs r1, 0
	bl rfu_STC_REQ_callback
_082E544C:
	pop {r0}
	bx r0
	thumb_func_end rfu_REQ_changeMasterSlave

	thumb_func_start rfu_getMasterSlave
rfu_getMasterSlave: @ 82E5450
	push {lr}
	movs r0, 0x1
	bl STWI_read_status
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bne _082E547E
	ldr r0, =gRfuState
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
	.pool
	thumb_func_end rfu_getMasterSlave

	thumb_func_start rfu_clearAllSlot
rfu_clearAllSlot: @ 82E5488
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r1, =0x04000208
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
	ldr r0, =gUnknown_03007880
	lsls r4, r5, 2
	adds r0, r4, r0
	ldr r1, [r0]
	mov r0, sp
	ldr r2, =0x01000034
	bl CpuSet
	strh r7, [r6]
	ldr r0, =gUnknown_03007870
	adds r4, r0
	ldr r1, [r4]
	adds r0, r6, 0
	ldr r2, =0x0100000a
	bl CpuSet
	ldr r3, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	strb r1, [r0, 0x2]
	ldr r0, =0x04000208
	mov r1, r8
	strh r1, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_clearAllSlot

	thumb_func_start rfu_STC_releaseFrame
rfu_STC_releaseFrame: @ 82E5528
	push {r4-r6,lr}
	adds r4, r2, 0
	lsls r0, 24
	lsrs r2, r0, 24
	adds r5, r2, 0
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E5568
	ldr r6, =gUnknown_03007890
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
	.pool
_082E5568:
	ldr r6, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_STC_releaseFrame

	thumb_func_start rfu_clearSlot
rfu_clearSlot: @ 82E5594
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
	ldr r1, =0x04000208
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
	ldr r1, =gUnknown_03007880
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
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	ldrb r0, [r2, 0x4]
	bics r0, r1
	strb r0, [r2, 0x4]
	b _082E5634
	.align 2, 0
	.pool
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
	ldr r0, =gUnknown_03007890
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
	ldr r2, =0x0100001a
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
	ldr r1, =gUnknown_03007870
	lsls r0, r7, 2
	adds r0, r1
	ldr r3, [r0]
	ldrh r1, [r3]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _082E56F4
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _082E56D8
	ldr r2, =gUnknown_03007890
	ldr r1, [r2]
	ldrb r0, [r1, 0xF]
	adds r0, 0x3
	ldrb r4, [r3, 0x4]
	adds r0, r4
	strb r0, [r1, 0xF]
	b _082E56EA
	.align 2, 0
	.pool
_082E56D8:
	ldr r2, =gUnknown_03007890
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
	ldr r2, =0x01000006
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
	ldr r1, =gUnknown_03007870
	lsls r0, r7, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0xC
	ldr r2, =0x01000004
	mov r0, sp
	bl CpuSet
_082E5724:
	ldr r0, =0x04000208
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
	.pool
	thumb_func_end rfu_clearSlot

	thumb_func_start rfu_setRecvBuffer
rfu_setRecvBuffer: @ 82E5750
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
	ldr r0, =gUnknown_03007880
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	str r5, [r0, 0x68]
	str r6, [r0, 0x6C]
	b _082E57A2
	.align 2, 0
	.pool
_082E5788:
	movs r0, 0x10
	ands r2, r0
	cmp r2, 0
	bne _082E5796
	movs r0, 0xC0
	lsls r0, 3
	b _082E57A4
_082E5796:
	ldr r0, =gUnknown_03007870
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
	.pool
	thumb_func_end rfu_setRecvBuffer

	thumb_func_start rfu_NI_setSendData
rfu_NI_setSendData: @ 82E57B0
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
rfu_UNI_setSendData: @ 82E57DC
	push {lr}
	sub sp, 0x4
	adds r3, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E57FC
	adds r0, r2, 0x3
	b _082E57FE
	.align 2, 0
	.pool
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
rfu_NI_CHILD_setSendGameName: @ 82E5818
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
	ldr r0, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_NI_CHILD_setSendGameName

	thumb_func_start rfu_STC_setSendData_org
rfu_STC_setSendData_org: @ 82E584C
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
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r1, [r2]
	mov r10, r0
	cmp r1, 0xFF
	bne _082E5880
	ldr r0, =0x00000301
	b _082E5A36
	.align 2, 0
	.pool
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
	ldr r0, =0x00000401
	b _082E5A36
	.align 2, 0
	.pool
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
	ldr r0, =0x00000402
	b _082E5A36
	.align 2, 0
	.pool
_082E58C0:
	movs r2, 0
	movs r0, 0x1
	ands r0, r3
	ldr r4, =gUnknown_089A3220
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
	.pool
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
	ldr r1, =0x04000208
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
	ldr r1, =gUnknown_03007880
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
	.pool
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
	ldr r4, =gUnknown_03007880
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
	ldr r0, =0x00008021
	mov r2, r12
	strh r0, [r2]
	b _082E5A2C
	.align 2, 0
	.pool
_082E59F4:
	movs r0, 0x10
	ands r0, r6
	cmp r0, 0
	beq _082E5A2C
	ldr r1, =gUnknown_03007870
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
	ldr r0, =0x00008024
	strh r0, [r1]
	mov r0, r10
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2, 0x6]
_082E5A2C:
	ldr r0, =0x04000208
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
	.pool
	thumb_func_end rfu_STC_setSendData_org

	thumb_func_start rfu_changeSendTarget
rfu_changeSendTarget: @ 82E5A54
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
	ldr r0, =gUnknown_03007880
	mov r12, r0
	lsls r0, r7, 2
	add r0, r12
	ldr r5, [r0]
	ldrh r2, [r5]
	ldr r1, =0x00008020
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
	ldr r1, =0x04000208
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
	ldr r0, =gUnknown_03007890
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
	ldr r0, =0x04000208
	mov r1, r8
	strh r1, [r0]
	b _082E5BAA
	.align 2, 0
	.pool
_082E5B18:
	cmp r3, 0x10
	bne _082E5BA4
	ldr r3, =gUnknown_03007870
	lsls r1, r7, 2
	adds r0, r1, r3
	ldr r0, [r0]
	ldrh r2, [r0]
	ldr r0, =0x00008024
	adds r5, r3, 0
	cmp r2, r0
	beq _082E5B40
_082E5B2E:
	ldr r0, =0x00000403
	b _082E5BAC
	.align 2, 0
	.pool
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
	ldr r0, =0x00000404
	b _082E5BAC
	.align 2, 0
	.pool
_082E5B70:
	ldr r3, =0x04000208
	ldrh r0, [r3]
	mov r8, r0
	strh r2, [r3]
	ldr r4, =gUnknown_03007890
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
	.pool
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
rfu_NI_stopReceivingData: @ 82E5BBC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _082E5BCC
	movs r0, 0x80
	lsls r0, 3
	b _082E5C26
_082E5BCC:
	ldr r1, =gUnknown_03007880
	lsls r0, r3, 2
	adds r0, r1
	ldr r2, [r0]
	adds r5, r2, 0
	adds r5, 0x34
	ldr r1, =0x04000208
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
	ldr r0, =0x00008043
	cmp r1, r0
	bne _082E5C04
	movs r0, 0x48
	b _082E5C06
	.align 2, 0
	.pool
_082E5C04:
	movs r0, 0x47
_082E5C06:
	strh r0, [r2, 0x34]
	ldr r0, =gUnknown_03007890
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
	ldr r0, =0x04000208
	strh r4, [r0]
	movs r0, 0
_082E5C26:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end rfu_NI_stopReceivingData

	thumb_func_start rfu_UNI_changeAndReadySendData
rfu_UNI_changeAndReadySendData: @ 82E5C34
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
	ldr r1, =gUnknown_03007870
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	ldrh r1, [r4]
	ldr r0, =0x00008024
	cmp r1, r0
	beq _082E5C6C
	ldr r0, =0x00000403
	b _082E5CC0
	.align 2, 0
	.pool
_082E5C6C:
	ldr r0, =gUnknown_03007890
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
	.pool
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
	ldr r2, =0x04000208
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
	.pool
_082E5CBC:
	movs r0, 0xA0
	lsls r0, 3
_082E5CC0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end rfu_UNI_changeAndReadySendData

	thumb_func_start rfu_UNI_readySendData
rfu_UNI_readySendData: @ 82E5CC8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _082E5CE6
	ldr r1, =gUnknown_03007870
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldrh r1, [r2]
	ldr r0, =0x00008024
	cmp r1, r0
	bne _082E5CE6
	movs r0, 0x1
	strb r0, [r2, 0x2]
_082E5CE6:
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_UNI_readySendData

	thumb_func_start rfu_UNI_clearRecvNewDataFlag
rfu_UNI_clearRecvNewDataFlag: @ 82E5CF4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _082E5D0A
	ldr r1, =gUnknown_03007870
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x12]
_082E5D0A:
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_UNI_clearRecvNewDataFlag

	thumb_func_start rfu_REQ_sendData
rfu_REQ_sendData: @ 82E5D14
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007894
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
	.pool
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
	ldr r4, =gUnknown_03007898
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x68]
	movs r0, 0xFF
	str r0, [r1, 0x78]
	ldr r0, =sub_82E5F00
	bl STWI_set_Callback_M
	cmp r5, 0
	bne _082E5DAC
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	bl STWI_send_DataTxREQ
	b _082E5E4E
	.align 2, 0
	.pool
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
	ldr r0, =rfu_CB_sendData
	bl STWI_set_Callback_M
	cmp r5, 0
	beq _082E5DFC
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0x68
	ldr r1, =gUnknown_03007894
	ldr r1, [r1]
	ldr r1, [r1, 0x24]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	bl STWI_send_DataTxAndChangeREQ
	b _082E5E4E
	.align 2, 0
	.pool
_082E5DFC:
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0x68
	ldr r1, =gUnknown_03007894
	ldr r1, [r1]
	ldr r1, [r1, 0x24]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	bl STWI_send_DataTxREQ
_082E5E12:
	cmp r5, 0
	beq _082E5E4E
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E5E44
	ldr r0, =gRfuState
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	cmp r1, 0
	beq _082E5E4E
	movs r0, 0x27
	bl _call_via_r1
	b _082E5E4E
	.align 2, 0
	.pool
_082E5E44:
	ldr r0, =rfu_CB_sendData2
	bl STWI_set_Callback_M
	bl STWI_send_MS_ChangeREQ
_082E5E4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_sendData

	thumb_func_start rfu_CB_sendData
rfu_CB_sendData: @ 82E5E58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r1, 16
	lsrs r7, r1, 16
	cmp r7, 0
	bne _082E5EC2
	movs r6, 0
	ldr r0, =0x00008020
	mov r8, r0
_082E5E6C:
	ldr r0, =gUnknown_03007870
	lsls r2, r6, 2
	adds r0, r2, r0
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _082E5E7E
	movs r0, 0
	strb r0, [r1, 0x2]
_082E5E7E:
	ldr r0, =gUnknown_03007880
	adds r0, r2, r0
	ldr r4, [r0]
	ldrh r0, [r4]
	cmp r0, r8
	bne _082E5EB8
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	bl rfu_STC_releaseFrame
	ldr r5, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_CB_sendData

	thumb_func_start rfu_CB_sendData2
rfu_CB_sendData2: @ 82E5EF0
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x24
	bl rfu_STC_REQ_callback
	pop {r0}
	bx r0
	thumb_func_end rfu_CB_sendData2

	thumb_func_start sub_82E5F00
sub_82E5F00: @ 82E5F00
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
rfu_constructSendLLFrame: @ 82E5F28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0x6C
	str r0, [sp]
	movs r6, 0
	movs r0, 0x80
	lsls r0, 8
	mov r9, r0
	ldr r1, =0x00008024
	mov r10, r1
_082E5F6A:
	movs r5, 0
	ldr r0, =gUnknown_03007880
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
	ldr r0, =gUnknown_03007870
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
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E5FE8
	add r8, r5
	b _082E5FF4
	.align 2, 0
	.pool
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
	ldr r6, =gUnknown_03007894
	mov r0, r8
	cmp r0, 0
	beq _082E603E
	ldr r2, [sp]
	movs r0, 0x3
	ands r0, r2
	ldr r5, =gUnknown_03007890
	ldr r1, =gUnknown_03007898
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
	.pool
	thumb_func_end rfu_constructSendLLFrame

	thumb_func_start rfu_STC_NI_constructLLSF
rfu_STC_NI_constructLLSF: @ 82E6060
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
	ldr r2, =gUnknown_03007890
	ldr r0, [r2]
	ldrb r0, [r0]
	lsls r0, 4
	ldr r1, =gUnknown_089A3220
	adds r0, r1
	mov r8, r0
	ldrh r1, [r4]
	ldr r0, =0x00008022
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
	.pool
_082E60E8:
	ldr r0, =0x00008022
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
	.pool
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
	ldr r2, =gUnknown_03007890
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
	ldr r0, =gUnknown_03007898
	ldr r1, [r0]
	add r0, sp, 0x4
	ldr r3, [r1, 0x4]
	mov r1, r12
	adds r2, r5, 0
	bl _call_via_r3
_082E61C2:
	ldrh r1, [r4]
	ldr r0, =0x00008022
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
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r1, [r2]
	cmp r1, 0x1
	bne _082E61F8
	ldrb r0, [r2, 0xE]
	strb r1, [r2, 0xE]
	b _082E6206
	.align 2, 0
	.pool
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
rfu_STC_UNI_constructLLSF: @ 82E6220
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gUnknown_03007870
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
	.pool
_082E624C:
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r0, [r2]
	lsls r0, 4
	ldr r1, =gUnknown_089A3220
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
	ldr r1, =gUnknown_03007898
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
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r0, [r2]
	cmp r0, 0x1
	bne _082E62D0
	ldrb r0, [r2, 0xE]
	movs r0, 0x10
	b _082E62DC
	.align 2, 0
	.pool
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
rfu_REQ_recvData: @ 82E62F4
	push {r4,lr}
	ldr r0, =gUnknown_03007890
	ldr r4, [r0]
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _082E6320
	ldr r2, =gUnknown_03007894
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
	ldr r0, =rfu_CB_recvData
	bl STWI_set_Callback_M
	bl STWI_send_DataRxREQ
_082E6320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_recvData

	thumb_func_start rfu_CB_recvData
rfu_CB_recvData: @ 82E6334
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
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	adds r0, 0xDC
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _082E63F8
	ldr r0, =gUnknown_03007894
	ldr r0, [r0]
	strb r7, [r0, 0x1]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E637C
	bl rfu_STC_PARENT_analyzeRecvPacket
	b _082E6380
	.align 2, 0
	.pool
_082E637C:
	bl rfu_STC_CHILD_analyzeRecvPacket
_082E6380:
	movs r6, 0
	ldr r0, =0x00008043
	mov r8, r0
	ldr r3, =gUnknown_03007890
_082E6388:
	ldr r0, =gUnknown_03007880
	lsls r1, r6, 2
	adds r1, r0
	ldr r4, [r1]
	ldrh r0, [r4, 0x34]
	cmp r0, r8
	bne _082E63DA
	ldr r0, =gUnknown_03007894
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
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_CB_recvData

	thumb_func_start rfu_STC_PARENT_analyzeRecvPacket
rfu_STC_PARENT_analyzeRecvPacket: @ 82E6420
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_03007898
	ldr r0, [r1]
	adds r0, 0xDC
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsrs r3, r0, 8
	movs r5, 0
	mov r12, r1
	movs r7, 0x1F
	ldr r4, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_STC_PARENT_analyzeRecvPacket

	thumb_func_start rfu_STC_CHILD_analyzeRecvPacket
rfu_STC_CHILD_analyzeRecvPacket: @ 82E64B8
	push {r4-r6,lr}
	ldr r0, =gUnknown_03007898
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
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_STC_CHILD_analyzeRecvPacket

	thumb_func_start rfu_STC_analyzeLLSF
rfu_STC_analyzeLLSF: @ 82E6510
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
	ldr r2, =gUnknown_03007890
	ldr r0, [r2]
	ldrb r0, [r0]
	mvns r0, r0
	movs r1, 0x1
	ands r0, r1
	lsls r0, 4
	ldr r1, =gUnknown_089A3220
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r3, r0
	bcs _082E654C
	adds r0, r3, 0
	b _082E673E
	.align 2, 0
	.pool
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
	ldr r1, =0xffffff00
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
	ldr r4, =0xffff00ff
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
	ldr r3, =0xff00ffff
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	adds r0, r5, 0
	ldrb r1, [r6, 0x4]
	lsrs r0, r1
	ldrb r1, [r6, 0xA]
	ands r0, r1
	lsls r0, 24
	ldr r2, =0x00ffffff
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
	ldr r0, =0x0000ffff
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
	ldr r2, =gUnknown_03007890
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
	.pool
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
	ldr r1, =gUnknown_03007880
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
	.pool
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
	ldr r3, =gUnknown_03007890
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
	.pool
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
	ldr r0, =gUnknown_03007890
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
	.pool
	thumb_func_end rfu_STC_analyzeLLSF

	thumb_func_start rfu_STC_UNI_receive
rfu_STC_UNI_receive: @ 82E6754
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r1, 0
	str r2, [sp]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gUnknown_03007870
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
	ldr r0, =0x00000701
	strh r0, [r5, 0x2]
	b _082E67DE
	.align 2, 0
	.pool
_082E6790:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _082E67A8
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _082E67B4
	ldr r0, =0x00000709
	strh r0, [r5, 0x2]
	b _082E67DE
	.align 2, 0
	.pool
_082E67A8:
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _082E67B4
	movs r0, 0xE1
	lsls r0, 3
	strh r0, [r5, 0x2]
_082E67B4:
	movs r4, 0
	ldr r0, =0x00008042
	strh r0, [r5]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x4]
	ldrh r2, [r6, 0x6]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_03007898
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
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_STC_UNI_receive

	thumb_func_start rfu_STC_NI_receive_Sender
rfu_STC_NI_receive_Sender: @ 82E6808
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
	ldr r1, =gUnknown_03007880
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
	ldr r0, =0x00008022
	cmp r9, r0
	beq _082E685E
_082E6844:
	cmp r2, 0x1
	bne _082E684E
	ldr r0, =0x00008021
	cmp r9, r0
	beq _082E685E
_082E684E:
	movs r3, 0x1B
	add r3, r12
	mov r8, r3
	cmp r2, 0x3
	bne _082E6882
	ldr r0, =0x00008023
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
	ldr r2, =0x00007fdf
	adds r0, r1, r2
	lsls r0, 16
	lsrs r0, 16
	adds r5, r3, 0
	cmp r0, 0x1
	bhi _082E6970
	ldr r0, =0x00008021
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
	.pool
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
	ldr r0, =0x00008021
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
	ldr r0, =0x00008022
	strh r0, [r7]
	b _082E697E
	.align 2, 0
	.pool
_082E695C:
	strb r2, [r5]
	mov r0, r12
	str r2, [r0, 0x14]
	ldr r0, =0x00008023
	mov r1, r12
	strh r0, [r1]
	b _082E697E
	.align 2, 0
	.pool
_082E6970:
	lsls r1, 16
	ldr r0, =0x80230000
	cmp r1, r0
	bne _082E697E
	ldr r0, =0x00008020
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
	ldr r4, =0x04000208
	ldrh r2, [r4]
	movs r0, 0
	strh r0, [r4]
	ldr r0, =gUnknown_03007894
	ldr r3, [r0]
	movs r0, 0x10
	mov r7, r10
	lsls r0, r7
	ldrb r1, [r3, 0x2]
	orrs r0, r1
	movs r1, 0
	strb r0, [r3, 0x2]
	lsls r0, r7, 2
	ldr r3, =gUnknown_03007880
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
	.pool
	thumb_func_end rfu_STC_NI_receive_Sender

	thumb_func_start rfu_STC_NI_receive_Receiver
rfu_STC_NI_receive_Receiver: @ 82E69F4
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
	ldr r1, =gUnknown_03007880
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
	ldr r0, =gUnknown_03007894
	ldr r2, [r0]
	movs r0, 0x1
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r2, 0x1]
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrh r1, [r4, 0x34]
	ldr r0, =0x00008042
	cmp r1, r0
	bne _082E6AAA
	adds r0, r4, 0
	adds r0, 0x54
	strb r7, [r0]
	strb r7, [r3]
	ldr r0, =0x00008043
	strh r0, [r4, 0x34]
	b _082E6AAA
	.align 2, 0
	.pool
_082E6A64:
	cmp r0, 0x2
	bne _082E6A90
	ldr r0, =0x00008041
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
	ldr r0, =0x00008042
	cmp r1, r0
	bne _082E6AAA
	b _082E6AAE
	.align 2, 0
	.pool
_082E6A90:
	cmp r0, 0x1
	bne _082E6AAA
	ldr r7, =0x00008041
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
	ldr r0, =gUnknown_03007898
	ldr r0, [r0]
	lsls r1, r3, 2
	adds r1, 0x4
	adds r1, r5, r1
	ldrh r2, [r6, 0x6]
	ldr r3, [r0, 0x4]
	mov r0, sp
	bl _call_via_r3
	ldrh r1, [r5]
	ldr r0, =0x00008042
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
	ldr r3, =0x04000208
	ldrh r2, [r3]
	movs r0, 0
	strh r0, [r3]
	ldr r0, =gUnknown_03007894
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
	.pool
	thumb_func_end rfu_STC_NI_receive_Receiver

	thumb_func_start rfu_STC_NI_initSlot_asRecvControllData
rfu_STC_NI_initSlot_asRecvControllData: @ 82E6B70
	push {r4-r7,lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_03007890
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
	.pool
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
	ldr r0, =0x00000702
	strh r0, [r2, 0x18]
	ldr r0, =gUnknown_03007894
	ldr r2, [r0]
	ldrb r1, [r2, 0x4]
	adds r0, r6, 0
	orrs r0, r1
	strb r0, [r2, 0x4]
	b _082E6BF6
	.align 2, 0
	.pool
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
	ldr r0, =0x00008041
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
	.pool
	thumb_func_end rfu_STC_NI_initSlot_asRecvControllData

	thumb_func_start rfu_STC_NI_initSlot_asRecvDataEntity
rfu_STC_NI_initSlot_asRecvDataEntity: @ 82E6C00
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _082E6C24
	ldr r0, =gUnknown_03007890
	lsls r1, r5, 5
	adds r1, 0x14
	ldr r0, [r0]
	adds r0, r1
	adds r0, 0x4
	b _082E6C7A
	.align 2, 0
	.pool
_082E6C24:
	ldr r1, =gUnknown_03007880
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
	ldr r0, =gUnknown_03007894
	ldr r3, [r0]
	ldrb r2, [r3, 0x4]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r3, 0x4]
	ldr r0, =gUnknown_03007890
	ldr r2, [r0]
	ldrb r0, [r2, 0x5]
	bics r0, r1
	strb r0, [r2, 0x5]
	ldr r0, =0x00000701
	strh r0, [r4, 0x18]
	movs r0, 0x47
	strh r0, [r4]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl rfu_STC_releaseFrame
	b _082E6CAC
	.align 2, 0
	.pool
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
	ldr r0, =0x00008042
	strh r0, [r4]
_082E6CAC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_STC_NI_initSlot_asRecvDataEntity

	thumb_func_start rfu_NI_checkCommFailCounter
rfu_NI_checkCommFailCounter: @ 82E6CB8
	push {r4-r7,lr}
	ldr r2, =gUnknown_03007890
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	orrs r0, r1
	cmp r0, 0
	beq _082E6D3E
	ldr r1, =0x04000208
	ldrh r0, [r1]
	mov r12, r0
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03007894
	ldr r0, [r1]
	ldrb r0, [r0, 0x2]
	lsrs r7, r0, 4
	movs r3, 0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r4, =gUnknown_03007880
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
	ldr r0, =0x04000208
	mov r1, r12
	strh r1, [r0]
_082E6D3E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_NI_checkCommFailCounter

	thumb_func_start rfu_REQ_noise
rfu_REQ_noise: @ 82E6D54
	push {lr}
	ldr r0, =rfu_STC_REQ_callback
	bl STWI_set_Callback_M
	movs r0, 0x1
	movs r1, 0
	bl STWI_send_TestModeREQ
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end rfu_REQ_noise

	thumb_func_start sub_82E6D6C
sub_82E6D6C: @ 82E6D6C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =0x04000208
	ldrh r0, [r0]
	cmp r0, 0
	bne _082E6D88
	movs r0, 0x1
	negs r0, r0
	b _082E6E08
	.align 2, 0
	.pool
_082E6D88:
	ldr r0, =0x04000200
	ldrh r0, [r0]
	mov r8, r0
	ldr r4, =gRfuState
	ldr r1, [r4]
	movs r0, 0xA
	str r0, [r1]
	ldr r0, =sub_82E6F88
	bl STWI_set_Callback_ID
	bl sub_82E6E20
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	lsls r0, 2
	ldr r1, =0x04000100
	adds r4, r0, r1
	lsls r0, r5, 27
	lsrs r5, r0, 24
	movs r7, 0
	b _082E6DD6
	.align 2, 0
	.pool
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
	ldr r1, =0x04000208
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x04000200
	mov r2, r8
	strh r2, [r0]
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, =gRfuState
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
	.pool
	thumb_func_end sub_82E6D6C

	thumb_func_start sub_82E6E20
sub_82E6E20: @ 82E6E20
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r3, =0x04000208
	movs r4, 0
	strh r4, [r3]
	ldr r2, =0x04000200
	ldr r0, =gRfuState
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
	ldr r0, =0x04000134
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
	ldr r1, =gUnknown_030078A0
	ldr r2, =0x05000003
	mov r0, sp
	bl CpuSet
	ldr r0, =0x04000202
	strh r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end sub_82E6E20

	thumb_func_start sub_82E6E94
sub_82E6E94: @ 82E6E94
	push {r4-r7,lr}
	ldr r0, =gUnknown_030078A0
	ldrb r1, [r0, 0x1]
	mov r12, r1
	adds r7, r0, 0
	cmp r1, 0
	beq _082E6EAC
	cmp r1, 0x1
	beq _082E6EE4
	b _082E6F7C
	.align 2, 0
	.pool
_082E6EAC:
	movs r6, 0x1
	strb r6, [r7]
	ldr r3, =0x04000128
	ldrh r0, [r3]
	movs r5, 0x1
	orrs r0, r5
	strh r0, [r3]
	ldr r4, =0x04000208
	mov r0, r12
	strh r0, [r4]
	ldr r2, =0x04000200
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
	.pool
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
	ldr r3, =0x04000208
	strh r0, [r3]
	ldr r2, =0x04000128
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	mov r1, r12
	strh r1, [r3]
	b _082E6F80
	.align 2, 0
	.pool
_082E6F14:
	ldrh r1, [r7, 0x4]
	ldr r0, =0x00008001
	cmp r1, r0
	beq _082E6F80
	ldrh r6, [r7, 0x2]
	cmp r6, 0
	bne _082E6F80
	ldr r4, =0x04000208
	strh r6, [r4]
	ldr r3, =0x04000200
	ldrh r1, [r3]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r3]
	mov r7, r12
	strh r7, [r4]
	ldr r2, =0x04000128
	strh r6, [r2]
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	strh r0, [r2]
	ldr r0, =0x04000202
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
	.pool
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
sub_82E6F88: @ 82E6F88
	push {r4,r5,lr}
	ldr r0, =0x04000120
	ldr r5, [r0]
	ldr r0, =gUnknown_030078A0
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x1
	beq sub_82E6FA2
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	thumb_func_end sub_82E6F88

	non_word_aligned_thumb_func_start sub_82E6FA2
sub_82E6FA2: @ 82E6FA2
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
	.pool
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
	ldr r1, =gUnknown_089A3258
	adds r0, r1
	ldrh r0, [r0]
	b _082E700E
	.align 2, 0
	.pool
_082E700C:
	ldr r0, =0x00008001
_082E700E:
	strh r0, [r4, 0x4]
	mvns r0, r5
	strh r0, [r4, 0x6]
	ldr r3, =0x04000120
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
	ldr r0, =0x0000494e
	cmp r5, r0
	bne _082E705C
_082E703E:
	movs r0, 0
	ldr r1, =0x00000257
_082E7042:
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bls _082E7042
	ldrh r0, [r4, 0xA]
	cmp r0, 0
	bne _082E705C
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
_082E705C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end sub_82E6FA2

	.align 2, 0 @ Don't pad with nop.
