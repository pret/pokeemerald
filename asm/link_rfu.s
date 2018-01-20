	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80109E8
sub_80109E8: @ 80109E8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	movs r5, 0x1
	ldr r4, =gUnknown_03005000+0xCDE
	movs r3, 0
_080109F6:
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _08010A04
	adds r0, r1, r4
	strb r3, [r0]
_08010A04:
	adds r1, 0x1
	cmp r1, 0x3
	ble _080109F6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80109E8

	thumb_func_start sub_8010A14
sub_8010A14: @ 8010A14
	push {r4-r7,lr}
	adds r2, r0, 0
	ldr r1, =gUnknown_03005000
	ldrb r0, [r2, 0xF]
	strb r0, [r1, 0xD]
	movs r4, 0
	ldr r0, =0x00000cde
	adds r5, r1, r0
	adds r3, r2, 0
	adds r3, 0x10
_08010A28:
	adds r0, r4, r5
	adds r1, r3, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _08010A28
	adds r6, r2, 0
	ldr r5, =gLinkPlayers
	movs r4, 0x4
_08010A3C:
	adds r0, r5, 0
	adds r1, r6, 0
	adds r1, 0x14
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r5, 0
	bl sub_800B524
	adds r6, 0x1C
	adds r5, 0x1C
	subs r4, 0x1
	cmp r4, 0
	bge _08010A3C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010A14

	thumb_func_start sub_8010A70
sub_8010A70: @ 8010A70
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =gUnknown_082ED7EC
	adds r1, r4, 0
	bl strcmp
	adds r5, r0, 0
	cmp r5, 0
	bne _08010A9C
	adds r0, r4, 0
	bl sub_8010A14
	mov r0, sp
	strh r5, [r0]
	ldr r2, =0x0100007e
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0
	bl ResetBlockReceivedFlag
_08010A9C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010A70

	thumb_func_start sub_8010AAC
sub_8010AAC: @ 8010AAC
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r3, =gUnknown_03005000
	ldr r2, =gUnknown_082ED68C
	ldr r1, =0x00000ce9
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, r2
	ldr r2, =0x00000cde
	adds r0, r3, r2
	ldrb r1, [r1]
	adds r0, r1
	ldrb r4, [r0]
	adds r0, r3, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08010AE8
	ldr r5, =0x00000ce8
	adds r1, r3, r5
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	bl DestroyTask
_08010AE8:
	ldr r0, =gTasks
	lsls r2, r6, 2
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	movs r3, 0x8
	ldrsh r1, [r1, r3]
	adds r3, r0, 0
	adds r7, r2, 0
	cmp r1, 0x5
	bls _08010B00
	b _08010CF0
_08010B00:
	lsls r0, r1, 2
	ldr r1, =_08010B28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08010B28:
	.4byte _08010B40
	.4byte _08010B60
	.4byte _08010B78
	.4byte _08010BC0
	.4byte _08010C0A
	.4byte _08010C94
_08010B40:
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	beq _08010B4A
	b _08010CF0
_08010B4A:
	adds r0, r4, 0
	bl ResetBlockReceivedFlag
	movs r0, 0xF0
	lsls r0, 7
	bl sub_800FD14
	b _08010C4A
	.pool
_08010B60:
	ldr r0, =gSendCmd
	ldrh r0, [r0]
	cmp r0, 0
	beq _08010B6A
	b _08010CF0
_08010B6A:
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r3
	b _08010C52
	.pool
_08010B78:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08010B8C
	b _08010CF0
_08010B8C:
	adds r0, r4, 0
	bl ResetBlockReceivedFlag
	lsls r2, r4, 8
	ldr r0, =gBlockRecvBuffer
	adds r2, r0
	ldr r1, =gLinkPlayers
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	adds r1, r0, 0
	adds r2, 0x10
	ldm r2!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r2!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r2, [r2]
	str r2, [r1]
	bl sub_800B524
	b _08010C4A
	.pool
_08010BC0:
	ldr r5, =gBlockSendBuffer
	adds r1, r5, 0
	ldr r0, =gUnknown_082ED7EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldrh r2, [r0]
	strh r2, [r1]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x2]
	ldr r1, =gUnknown_03005000
	ldrb r0, [r1, 0xD]
	strb r0, [r5, 0xF]
	movs r2, 0
	adds r4, r5, 0
	adds r4, 0x10
	ldr r0, =0x00000cde
	adds r3, r1, r0
_08010BE2:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010BE2
	ldr r1, =gLinkPlayers
	adds r0, r5, 0
	adds r0, 0x14
	movs r2, 0x8C
	bl memcpy
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_08010C0A:
	ldr r5, =gBlockSendBuffer
	ldr r1, =gUnknown_03005000
	ldrb r0, [r1, 0xD]
	strb r0, [r5, 0xF]
	movs r2, 0
	ldr r3, =gLinkPlayers
	mov r12, r3
	adds r4, r5, 0
	adds r4, 0x10
	ldr r0, =0x00000cde
	adds r3, r1, r0
_08010C20:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010C20
	adds r0, r5, 0
	adds r0, 0x14
	mov r1, r12
	movs r2, 0x8C
	bl memcpy
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0xA0
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _08010CF0
_08010C4A:
	ldr r0, =gTasks
	adds r1, r7, r6
	lsls r1, 3
	adds r1, r0
_08010C52:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08010CF0
	.pool
_08010C74:
	adds r0, r3, 0
	lsls r0, r2
	ldr r2, =0x00000ce5
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r4]
	eors r0, r1
	strb r0, [r4]
	ldr r4, =0x00000ce8
	adds r0, r5, r4
	strb r3, [r0]
	b _08010CEA
	.pool
_08010C94:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08010CF0
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08010CF0
	mov r0, sp
	movs r4, 0
	strh r4, [r0]
	ldr r1, =gBlockRecvBuffer
	ldr r2, =0x0100007e
	bl CpuSet
	movs r0, 0
	bl ResetBlockReceivedFlag
	ldr r1, =gUnknown_03005000
	ldr r5, =0x00000ce8
	adds r0, r1, r5
	strb r4, [r0]
	ldr r0, =0x00000ce6
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, 0
	beq _08010CEA
	movs r2, 0
	adds r5, r1, 0
	adds r4, r3, 0
	ldrb r1, [r4]
	movs r3, 0x1
_08010CDA:
	adds r0, r1, 0
	asrs r0, r2
	ands r0, r3
	cmp r0, 0
	bne _08010C74
	adds r2, 0x1
	cmp r2, 0x3
	ble _08010CDA
_08010CEA:
	adds r0, r6, 0
	bl DestroyTask
_08010CF0:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010AAC

	thumb_func_start sub_8010D0C
sub_8010D0C: @ 8010D0C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_03005000
	adds r0, r6, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08010D2A
	adds r0, r5, 0
	bl DestroyTask
_08010D2A:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08010D70
	cmp r0, 0x1
	bgt _08010D50
	cmp r0, 0
	beq _08010D56
	b _08010DA6
	.pool
_08010D50:
	cmp r0, 0x2
	beq _08010D82
	b _08010DA6
_08010D56:
	ldrb r0, [r6, 0xD]
	cmp r0, 0
	beq _08010DA6
	bl sub_800B348
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0x3C
	bl SendBlock
	b _08010D7A
	.pool
_08010D70:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08010DA6
_08010D7A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08010DA6
_08010D82:
	bl GetBlockReceivedStatus
	movs r4, 0x1
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _08010DA6
	ldr r0, =gBlockRecvBuffer
	bl sub_8010A14
	movs r0, 0
	bl ResetBlockReceivedFlag
	ldr r0, =gReceivedRemoteLinkPlayers
	strb r4, [r0]
	adds r0, r5, 0
	bl DestroyTask
_08010DA6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010D0C

	thumb_func_start sub_8010DB4
sub_8010DB4: @ 8010DB4
	push {r4-r7,lr}
	ldr r0, =gUnknown_03005000
	adds r1, r0, 0
	adds r1, 0xEE
	ldrb r1, [r1]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _08010E5C
	ldr r2, =gUnknown_03004140
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08010E5C
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8018438
	cmp r1, r0
	beq _08010DDE
	ldr r0, [r2, 0x3C]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08010DE4
_08010DDE:
	ldr r1, =gWirelessCommType
	movs r0, 0x2
	strb r0, [r1]
_08010DE4:
	ldr r4, =CB2_LinkError
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =gMain
	str r4, [r0, 0x8]
	ldr r5, =gUnknown_03005000
	ldrh r0, [r5, 0xA]
	lsls r4, r0, 16
	ldrh r0, [r5, 0x10]
	lsls r0, 8
	orrs r4, r0
	ldrh r0, [r5, 0x12]
	orrs r4, r0
	ldr r1, =0x000009e6
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r0, 0
	ldr r1, =0x00000c1a
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r6, r0, 0
	bl sub_8011A74
	movs r3, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08010E20
	movs r3, 0x1
_08010E20:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_800AF18
	adds r0, r5, 0
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x2
	strb r1, [r0]
	bl CloseLink
	b _08010E8E
	.pool
_08010E5C:
	ldr r1, =0x00000c1b
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08010E70
	ldr r1, =0x000009e7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08010E8E
_08010E70:
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08010E7C
	bl sub_800D630
_08010E7C:
	movs r4, 0xE0
	lsls r4, 7
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
_08010E8E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010DB4

	thumb_func_start rfu_REQ_recvData_then_sendData
rfu_REQ_recvData_then_sendData: @ 8010EA0
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	bne _08010EB8
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	movs r0, 0
	bl rfu_REQ_sendData_wrapper
_08010EB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end rfu_REQ_recvData_then_sendData

	thumb_func_start sub_8010EC0
sub_8010EC0: @ 8010EC0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ccd
	adds r0, r4, r1
	strb r5, [r0]
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C54C
	adds r0, r4, 0
	adds r0, 0xEF
	ldrb r0, [r0]
	cmp r0, 0
	bne _08010F14
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08010F02
	cmp r0, 0x1
	bgt _08010EFC
	cmp r0, 0
	beq _08010F08
	b _08010F14
	.pool
_08010EFC:
	cmp r0, 0x2
	beq _08010F10
	b _08010F14
_08010F02:
	bl sub_800F0F8
	b _08010F14
_08010F08:
	bl sub_800F4F0
	adds r5, r0, 0
	b _08010F14
_08010F10:
	bl rfu_REQ_recvData_then_sendData
_08010F14:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8010EC0

	thumb_func_start sub_8010F1C
sub_8010F1C: @ 8010F1C
	push {r4,lr}
	movs r4, 0
	ldr r1, =gUnknown_03005000
	adds r0, r1, 0
	adds r0, 0xEF
	ldrb r0, [r0]
	cmp r0, 0
	bne _08010F3C
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	bne _08010F38
	bl sub_800F1E0
	adds r4, r0, 0
_08010F38:
	bl sub_8010DB4
_08010F3C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8010F1C

	thumb_func_start sub_8010F48
sub_8010F48: @ 8010F48
	push {lr}
	ldr r0, =gUnknown_02022B14 + 0xE
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F48

	thumb_func_start sub_8010F60
sub_8010F60: @ 8010F60
	push {r4,lr}
	ldr r4, =gUnknown_02022B14
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xD
	bl memset
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_800DD94
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F60

	thumb_func_start sub_8010F84
sub_8010F84: @ 8010F84
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02022B14
	adds r1, r4, 0
	bl sub_800DD94
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010F84

	thumb_func_start sub_8010FA0
sub_8010FA0: @ 8010FA0
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	movs r4, 0x1
	ands r0, r4
	lsls r0, 4
	ldrb r3, [r5]
	movs r2, 0x11
	negs r2, r2
	ands r2, r3
	orrs r2, r0
	ands r1, r4
	lsls r1, 5
	movs r0, 0x21
	negs r0, r0
	ands r2, r0
	orrs r2, r1
	strb r2, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010FA0

	thumb_func_start sub_8010FCC
sub_8010FCC: @ 8010FCC
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	lsls r0, 2
	ldrb r4, [r5, 0x9]
	movs r3, 0x3
	ands r3, r4
	orrs r3, r0
	strb r3, [r5, 0x9]
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldrh r3, [r5, 0x8]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r1
	strh r0, [r5, 0x8]
	lsls r2, 1
	ldrb r1, [r5, 0xB]
	movs r0, 0x1
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0xB]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8010FCC

	thumb_func_start sub_801100C
sub_801100C: @ 801100C
	push {r4,lr}
	movs r4, 0x80
	ldr r3, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r1, r3
	ldrb r2, [r0, 0x13]
	lsls r2, 3
	orrs r2, r4
	adds r3, 0x4
	adds r1, r3
	ldr r0, [r1]
	movs r1, 0x7
	ands r0, r1
	orrs r0, r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801100C

	thumb_func_start sub_801103C
sub_801103C: @ 801103C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022B14
	movs r4, 0x1
	b _08011054
	.pool
_08011048:
	adds r0, r4, 0
	bl sub_801100C
	adds r1, r5, r4
	strb r0, [r1, 0x3]
	adds r4, 0x1
_08011054:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _08011048
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801103C

	thumb_func_start sub_8011068
sub_8011068: @ 8011068
	push {lr}
	lsls r0, 24
	ldr r2, =gUnknown_02022B14
	lsrs r0, 17
	ldrb r3, [r2, 0xA]
	movs r1, 0x7F
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0xA]
	ldr r3, =gUnknown_02022B14 + 0xE
	movs r0, 0
	movs r1, 0x2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011068

	thumb_func_start sub_8011090
sub_8011090: @ 8011090
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0801109E
	bl sub_8010F84
_0801109E:
	ldr r2, =gUnknown_02022B14
	ldr r3, =gUnknown_02022B14 + 0xE
	movs r0, 0
	movs r1, 0x2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011090

	thumb_func_start sub_80110B8
sub_80110B8: @ 80110B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	bne _0801114C
	movs r5, 0
	movs r7, 0
	ldr r3, =gUnknown_03005000
	ldr r1, =0x00000ce2
	adds r0, r3, r1
	ldr r2, =0x00000ce3
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	adds r1, r0, 0
	eors r1, r2
	mov r8, r1
	movs r4, 0
	movs r6, 0x1
	ldr r2, =gLinkPlayers
	mov r12, r2
	ldr r0, =0x00000cde
	adds r0, r3
	mov r10, r0
	mov r3, r12
	adds r3, 0x4
_080110FC:
	mov r0, r8
	asrs r0, r4
	ands r0, r6
	cmp r0, 0
	beq _0801113C
	mov r1, r10
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r2, r12
	adds r1, r0, r2
	ldrb r1, [r1, 0x13]
	adds r2, r6, 0
	ands r2, r1
	lsls r2, 3
	adds r0, r3
	ldr r1, [r0]
	movs r0, 0x7
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	orrs r2, r1
	lsls r0, r5, 3
	lsls r2, r0
	orrs r7, r2
	adds r5, 0x1
	mov r0, r9
	subs r0, 0x1
	cmp r5, r0
	beq _08011142
_0801113C:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080110FC
_08011142:
	movs r0, 0x45
	adds r1, r7, 0
	movs r2, 0
	bl sub_8011090
_0801114C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80110B8

	thumb_func_start sub_8011170
sub_8011170: @ 8011170
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_03005000
	adds r3, r2, 0
	adds r3, 0xEE
	ldrb r0, [r3]
	cmp r0, 0
	bne _08011192
	ldr r1, =gUnknown_03004140
	ldrh r0, [r1, 0x14]
	strh r0, [r2, 0x10]
	ldrh r0, [r1, 0x16]
	strh r0, [r2, 0x12]
	strh r4, [r2, 0xA]
	ldrb r0, [r3]
	movs r0, 0x1
	strb r0, [r3]
_08011192:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011170

	thumb_func_start sub_80111A0
sub_80111A0: @ 80111A0
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80111A0

	thumb_func_start sub_80111B0
sub_80111B0: @ 80111B0
	push {lr}
	adds r2, r0, 0
	cmp r2, 0
	bne _080111C8
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	strb r2, [r0]
	b _080111D2
	.pool
_080111C8:
	ldr r0, =gUnknown_03005000
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x4
	strb r1, [r0]
_080111D2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80111B0

	thumb_func_start sub_80111DC
sub_80111DC: @ 80111DC
	push {lr}
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_8011E94
	ldr r1, =gUnknown_03005000
	movs r0, 0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80111DC

	thumb_func_start sub_80111FC
sub_80111FC: @ 80111FC
	ldr r1, =gUnknown_03005000
	ldr r0, =sub_80111DC
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80111FC

	thumb_func_start sub_801120C
sub_801120C: @ 801120C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r6, 0
	cmp r4, 0x32
	bne _08011222
	b _08011360
_08011222:
	cmp r4, 0x32
	bgt _08011252
	cmp r4, 0x13
	bgt _08011240
	cmp r4, 0x12
	blt _08011230
	b _080113EE
_08011230:
	cmp r4, 0x10
	bne _08011236
	b _080113EE
_08011236:
	cmp r4, 0x10
	bgt _0801128C
	cmp r4, 0
	beq _0801127E
	b _080113EE
_08011240:
	cmp r4, 0x30
	bne _08011246
	b _0801136C
_08011246:
	cmp r4, 0x30
	ble _0801124C
	b _08011354
_0801124C:
	cmp r4, 0x14
	beq _08011328
	b _080113EE
_08011252:
	cmp r4, 0x44
	bgt _08011264
	cmp r4, 0x42
	blt _0801125C
	b _080113EE
_0801125C:
	cmp r4, 0x33
	bne _08011262
	b _0801136C
_08011262:
	b _080113EE
_08011264:
	cmp r4, 0xF3
	bne _0801126A
	b _080113BA
_0801126A:
	cmp r4, 0xF3
	bgt _08011276
	cmp r4, 0xF0
	bge _08011274
	b _080113EE
_08011274:
	b _080113D4
_08011276:
	cmp r4, 0xFF
	bne _0801127C
	b _080113D4
_0801127C:
	b _080113EE
_0801127E:
	ldr r1, =gUnknown_03005000
	movs r0, 0x2
	strh r0, [r1, 0x4]
	b _080113EE
	.pool
_0801128C:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_80115EC
	movs r5, 0
	movs r0, 0x1
	mov r8, r0
	ldr r1, =gUnknown_03005000
	mov r9, r1
	ldr r3, =0x00000cd5
	add r3, r9
	mov r10, r3
	movs r7, 0x7F
_080112A6:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	asrs r0, r5
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0801130E
	ldr r0, =gUnknown_03007890
	lsls r1, r5, 5
	adds r1, 0x14
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0, 0x10]
	adds r4, r7, 0
	ands r4, r0
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	adds r0, r7, 0
	ands r0, r1
	cmp r4, r0
	bne _08011304
	ldr r0, =0x00000cd1
	add r0, r9
	adds r0, r5, r0
	movs r1, 0
	strb r1, [r0]
	mov r3, r10
	adds r2, r5, r3
	strb r1, [r2]
	movs r0, 0x20
	adds r1, r5, 0
	movs r3, 0x1
	bl rfu_setRecvBuffer
	b _0801130E
	.pool
_08011304:
	mov r0, r8
	lsls r0, r5
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_0801130E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080112A6
	cmp r6, 0
	beq _080113EE
	adds r0, r6, 0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	b _080113EE
_08011328:
	ldr r4, =gUnknown_03005000
	ldr r1, =0x00000ce7
	adds r0, r4, r1
	ldr r1, =gUnknown_03004140
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	beq _08011342
	eors r0, r2
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08011342:
	movs r0, 0x11
	strh r0, [r4, 0x4]
	b _080113EE
	.pool
_08011354:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	b _080113EA
	.pool
_08011360:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x3
	b _080113EC
	.pool
_0801136C:
	ldr r1, =gUnknown_03005000
	adds r2, r1, 0
	adds r2, 0xF0
	movs r0, 0x4
	strb r0, [r2]
	ldr r3, =0x00000ce2
	adds r1, r3
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0, 0x14]
	ldrb r0, [r1]
	adds r3, r0, 0
	bics r3, r2
	adds r2, r3, 0
	strb r2, [r1]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080113B0
	cmp r2, 0
	bne _080113AC
	adds r0, r4, 0
	bl sub_8011170
	b _080113B0
	.pool
_080113AC:
	bl sub_80111FC
_080113B0:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _080113EE
_080113BA:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	b _080113EA
	.pool
_080113D4:
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cdb
	adds r0, r1
	ldrb r1, [r0]
_080113EA:
	movs r1, 0x1
_080113EC:
	strb r1, [r0]
_080113EE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801120C

	thumb_func_start sub_8011404
sub_8011404: @ 8011404
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x31
	bne _08011410
	b _08011570
_08011410:
	cmp r4, 0x31
	bgt _0801143E
	cmp r4, 0x22
	beq _08011494
	cmp r4, 0x22
	bgt _0801142C
	cmp r4, 0x20
	beq _0801147C
	cmp r4, 0x20
	ble _08011426
	b _080115DE
_08011426:
	cmp r4, 0
	beq _0801146E
	b _080115DE
_0801142C:
	cmp r4, 0x24
	beq _080114BA
	cmp r4, 0x24
	blt _080114B0
	cmp r4, 0x25
	beq _08011504
	cmp r4, 0x30
	beq _0801150E
	b _080115DE
_0801143E:
	cmp r4, 0x44
	bgt _08011454
	cmp r4, 0x42
	blt _08011448
	b _080115DE
_08011448:
	cmp r4, 0x33
	beq _08011522
	cmp r4, 0x33
	bge _08011452
	b _0801158C
_08011452:
	b _080115DE
_08011454:
	cmp r4, 0xF3
	bne _0801145A
	b _080115AC
_0801145A:
	cmp r4, 0xF3
	bgt _08011466
	cmp r4, 0xF0
	bge _08011464
	b _080115DE
_08011464:
	b _080115C4
_08011466:
	cmp r4, 0xFF
	bne _0801146C
	b _080115C4
_0801146C:
	b _080115DE
_0801146E:
	ldr r1, =gUnknown_03005000
	movs r0, 0x6
	strh r0, [r1, 0x4]
	b _080115DE
	.pool
_0801147C:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000ccd
	adds r0, r2
	b _080115DC
	.pool
_08011494:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000c3e
	adds r0, r2
	ldrb r2, [r0]
	b _080115DC
	.pool
_080114B0:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _080115DE
_080114BA:
	ldr r4, =gUnknown_03005000
	movs r1, 0
	movs r0, 0xB
	strh r0, [r4, 0x4]
	ldr r2, =0x00000c85
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, =0x00000c86
	adds r2, r4, r0
	strb r1, [r2]
	ldr r1, =0x00000c3e
	adds r5, r4, r1
	ldrb r1, [r5]
	movs r0, 0x20
	movs r3, 0x1
	bl rfu_setRecvBuffer
	ldrb r1, [r5]
	ldr r2, =0x00000c3f
	adds r4, r2
	movs r0, 0x10
	adds r2, r4, 0
	movs r3, 0x46
	bl rfu_setRecvBuffer
	b _080115DE
	.pool
_08011504:
	movs r0, 0x2
	movs r1, 0x25
	bl sub_8011A64
	b _080115DE
_0801150E:
	ldr r0, =gUnknown_03005000
	adds r2, r0, 0
	adds r2, 0xF0
	movs r1, 0x2
	strb r1, [r2]
	ldr r1, =0x00000c86
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _080115DE
_08011522:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08011532
	movs r0, 0x4
	strb r0, [r1]
_08011532:
	ldr r1, =0x00000c86
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _08011544
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
_08011544:
	ldr r0, =gUnknown_082ED7FC
	movs r1, 0x5
	movs r2, 0x5
	bl nullsub_5
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080115DE
	adds r0, r4, 0
	bl sub_8011170
	b _080115DE
	.pool
_08011570:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, =gUnknown_082ED814
	movs r1, 0x5
	movs r2, 0x5
	bl nullsub_5
	b _080115DE
	.pool
_0801158C:
	ldr r1, =gUnknown_03005000
	adds r2, r1, 0
	adds r2, 0xF0
	movs r0, 0x3
	strb r0, [r2]
	ldr r2, =0x00000c3c
	adds r1, r2
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
	b _080115DE
	.pool
_080115AC:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	b _080115DA
	.pool
_080115C4:
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	adds r0, r4, 0
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000cdb
	adds r0, r1
	ldrb r1, [r0]
_080115DA:
	movs r1, 0x1
_080115DC:
	strb r1, [r0]
_080115DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011404

	thumb_func_start sub_80115EC
sub_80115EC: @ 80115EC
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r2, 0
	movs r6, 0x1
	ldr r0, =gUnknown_03005000
	ldr r4, =0x00000cea
	adds r1, r0, r4
	movs r5, 0
	movs r4, 0xFF
_080115FE:
	adds r0, r3, 0
	asrs r0, r2
	ands r0, r6
	cmp r0, 0
	beq _08011610
	strb r5, [r1]
	ldrb r0, [r1, 0x4]
	orrs r0, r4
	strb r0, [r1, 0x4]
_08011610:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x3
	ble _080115FE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80115EC

	thumb_func_start sub_8011628
sub_8011628: @ 8011628
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r3, 0
	movs r2, 0
	movs r4, 0x1
	ldr r6, =gUnknown_03007890
	movs r7, 0x7F
_08011636:
	adds r0, r5, 0
	asrs r0, r2
	ands r0, r4
	cmp r0, 0
	beq _0801165C
	lsls r1, r2, 5
	adds r1, 0x14
	ldr r0, [r6]
	adds r0, r1
	ldrb r1, [r0, 0x10]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x45
	bne _0801165C
	adds r0, r4, 0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
_0801165C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _08011636
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011628

	thumb_func_start sub_8011674
sub_8011674: @ 8011674
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x25
	bne _08011680
	b _080118EC
_08011680:
	cmp r4, 0x25
	bgt _080116C2
	cmp r4, 0x14
	bne _0801168A
	b _08011804
_0801168A:
	cmp r4, 0x14
	bgt _080116A2
	cmp r4, 0x11
	beq _08011722
	cmp r4, 0x11
	ble _08011698
	b _08011A42
_08011698:
	cmp r4, 0
	beq _0801170C
	cmp r4, 0x10
	beq _08011718
	b _08011A42
_080116A2:
	cmp r4, 0x22
	bne _080116A8
	b _08011868
_080116A8:
	cmp r4, 0x22
	bgt _080116B4
	cmp r4, 0x20
	bne _080116B2
	b _08011850
_080116B2:
	b _08011A42
_080116B4:
	cmp r4, 0x23
	bne _080116BA
	b _08011884
_080116BA:
	cmp r4, 0x24
	bne _080116C0
	b _080118BA
_080116C0:
	b _08011A42
_080116C2:
	cmp r4, 0x44
	bgt _080116F2
	cmp r4, 0x42
	blt _080116CC
	b _08011A42
_080116CC:
	cmp r4, 0x32
	bne _080116D2
	b _08011914
_080116D2:
	cmp r4, 0x32
	bgt _080116E4
	cmp r4, 0x30
	bne _080116DC
	b _08011940
_080116DC:
	cmp r4, 0x31
	bne _080116E2
	b _080118F6
_080116E2:
	b _08011A42
_080116E4:
	cmp r4, 0x33
	bne _080116EA
	b _08011948
_080116EA:
	cmp r4, 0x40
	bne _080116F0
	b _080119FC
_080116F0:
	b _08011A42
_080116F2:
	cmp r4, 0xF3
	bne _080116F8
	b _08011A0C
_080116F8:
	cmp r4, 0xF3
	bgt _08011704
	cmp r4, 0xF0
	bge _08011702
	b _08011A42
_08011702:
	b _08011A28
_08011704:
	cmp r4, 0xFF
	bne _0801170A
	b _08011A28
_0801170A:
	b _08011A42
_0801170C:
	ldr r1, =gUnknown_03005000
	movs r0, 0x11
	strh r0, [r1, 0x4]
	b _08011A42
	.pool
_08011718:
	movs r0, 0x4
	movs r1, 0
	bl sub_8011A64
	b _08011A42
_08011722:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	bne _080117DC
	ldr r5, =gUnknown_03005000
	ldr r1, =0x00000cd9
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080117DC
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_8011628
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080117A6
	adds r0, r4, 0
	bl sub_800E87C
	movs r2, 0x1
	mov r12, r2
	mov r1, r12
	lsls r1, r0
	lsls r1, 24
	lsrs r1, 24
	ldr r7, =0x00000ce6
	adds r6, r5, r7
	ldrb r2, [r6]
	cmp r2, 0
	bne _08011798
	ldr r0, =0x00000ce8
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, 0
	bne _08011798
	subs r7, 0x1
	adds r0, r5, r7
	strb r1, [r0]
	eors r1, r4
	orrs r1, r2
	strb r1, [r6]
	mov r0, r12
	strb r0, [r3]
	b _080117A6
	.pool
_08011798:
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce6
	adds r0, r1
	ldrb r2, [r0]
	adds r1, r4, 0
	orrs r1, r2
	strb r1, [r0]
_080117A6:
	ldr r0, =gUnknown_03004140
	ldrh r1, [r0, 0x14]
	cmp r4, r1
	beq _080117F6
	ldr r2, =gUnknown_03005000
	ldr r7, =0x00000ce3
	adds r3, r2, r7
	adds r0, r4, 0
	eors r0, r1
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	ldr r0, =0x00000ce4
	adds r2, r0
	movs r0, 0x2
	strb r0, [r2]
	b _080117F6
	.pool
_080117DC:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x54
	bne _080117F6
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0]
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_080117F6:
	ldr r0, =gUnknown_03004140
	ldrh r0, [r0, 0x14]
	bl sub_80115EC
	b _08011A42
	.pool
_08011804:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	beq _08011836
	ldr r4, =gUnknown_03004140
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	bls _08011836
	ldrb r0, [r4, 0x14]
	bl sub_800E87C
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldrb r0, [r4]
	eors r1, r0
	adds r0, r1, 0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08011836:
	ldr r1, =gUnknown_03005000
	ldrh r0, [r1, 0x4]
	cmp r0, 0xF
	beq _08011840
	b _08011A42
_08011840:
	movs r0, 0x10
	strh r0, [r1, 0x4]
	b _08011A42
	.pool
_08011850:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r2, =0x00000ccd
	adds r0, r2
	b _08011A40
	.pool
_08011868:
	ldr r0, =gUnknown_03005000
	ldr r1, =gUnknown_03004140
	ldrh r1, [r1, 0x14]
	ldr r7, =0x00000c3e
	adds r0, r7
	ldrb r2, [r0]
	b _08011A40
	.pool
_08011884:
	ldr r1, =gUnknown_03005000
	movs r0, 0x12
	strh r0, [r1, 0x4]
	ldr r0, =0x00000ccf
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x1
	bhi _080118B0
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =sub_801209C
	movs r1, 0x2
	bl CreateTask
	b _08011A42
	.pool
_080118B0:
	movs r0, 0x2
	movs r1, 0x23
	bl sub_8011A64
	b _08011A42
_080118BA:
	ldr r4, =gUnknown_03005000
	movs r0, 0xD
	strh r0, [r4, 0x4]
	movs r0, 0x3
	movs r1, 0
	bl sub_8011A64
	ldr r1, =0x00000c3e
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, =0x00000c3f
	adds r4, r2
	movs r0, 0x10
	adds r2, r4, 0
	movs r3, 0x46
	bl rfu_setRecvBuffer
	b _08011A42
	.pool
_080118EC:
	movs r0, 0x2
	movs r1, 0x25
	bl sub_8011A64
	b _08011A42
_080118F6:
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0]
	ldrh r0, [r0, 0x14]
	ands r1, r0
	cmp r1, 0
	bne _08011904
	b _08011A42
_08011904:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x1
	b _08011A40
	.pool
_08011914:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	movs r0, 0x3
	strb r0, [r1]
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801192A
	b _08011A42
_0801192A:
	ldr r7, =0x00000c3c
	adds r0, r2, r7
	ldrb r1, [r0]
	movs r1, 0x1
	b _08011A40
	.pool
_08011940:
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	movs r1, 0x2
	strb r1, [r0]
_08011948:
	ldr r2, =gUnknown_03005000
	adds r1, r2, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08011958
	movs r0, 0x4
	strb r0, [r1]
_08011958:
	ldrb r0, [r2, 0xC]
	cmp r0, 0x1
	bne _08011996
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080119B4
	ldr r0, =0x00000ce2
	adds r2, r0
	ldr r0, =gUnknown_03004140
	ldrb r1, [r0, 0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	cmp r0, 0
	bne _08011990
	adds r0, r4, 0
	bl sub_8011170
	b _080119B4
	.pool
_08011990:
	bl sub_80111FC
	b _080119B4
_08011996:
	ldr r1, =0x00000ce4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080119B4
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080119B4
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0
	bl sub_800C27C
_080119B4:
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080119DA
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080119DA
	ldr r0, =sub_800EB44
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080119DA
	ldr r1, =gUnknown_03005000
	movs r0, 0x11
	strh r0, [r1, 0x4]
_080119DA:
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_8011A64
	b _08011A42
	.pool
_080119FC:
	ldr r0, =gUnknown_03005000
	ldr r2, =0x00000ce3
	adds r0, r2
	b _08011A3E
	.pool
_08011A0C:
	movs r0, 0x1
	movs r1, 0xF3
	bl sub_8011A64
	movs r0, 0xF3
	bl sub_8011170
	ldr r0, =gUnknown_03005000
	adds r0, 0xEF
	movs r1, 0x1
	b _08011A40
	.pool
_08011A28:
	adds r0, r4, 0
	bl sub_8011170
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_8011A64
	ldr r0, =gUnknown_03005000
	ldr r7, =0x00000cdb
	adds r0, r7
	ldrb r1, [r0]
_08011A3E:
	movs r1, 0
_08011A40:
	strb r1, [r0]
_08011A42:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011674

	thumb_func_start sub_8011A50
sub_8011A50: @ 8011A50
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce4
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A50

	thumb_func_start sub_8011A64
sub_8011A64: @ 8011A64
	ldr r2, =gUnknown_03005000
	adds r3, r2, 0
	adds r3, 0xF1
	strb r0, [r3]
	strh r1, [r2, 0xA]
	bx lr
	.pool
	thumb_func_end sub_8011A64

	thumb_func_start sub_8011A74
sub_8011A74: @ 8011A74
	ldr r0, =gUnknown_03005000
	adds r0, 0xF1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A74

	thumb_func_start sub_8011A80
sub_8011A80: @ 8011A80
	push {lr}
	bl sub_8011A74
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x1
	bls _08011A94
	movs r0, 0
	b _08011A96
_08011A94:
	movs r0, 0x1
_08011A96:
	pop {r1}
	bx r1
	thumb_func_end sub_8011A80

	thumb_func_start sub_8011A9C
sub_8011A9C: @ 8011A9C
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000ce8
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8011A9C

	thumb_func_start Rfu_IsMaster
Rfu_IsMaster: @ 8011AB0
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end Rfu_IsMaster

	thumb_func_start RfuVSync
RfuVSync: @ 8011ABC
	push {lr}
	bl rfu_syncVBlank_
	pop {r0}
	bx r0
	thumb_func_end RfuVSync

	thumb_func_start sub_8011AC8
sub_8011AC8: @ 8011AC8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gRecvCmds
	ldr r2, =0x05000014
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011AC8

	thumb_func_start sub_8011AE8
sub_8011AE8: @ 8011AE8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8011AE8

	thumb_func_start sub_8011AFC
sub_8011AFC: @ 8011AFC
	push {r4,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl ResetPaletteFade
	ldr r0, =sub_8011AE8
	bl SetVBlankCallback
	bl sub_80093CC
	lsls r0, 24
	cmp r0, 0
	beq _08011B70
	ldr r1, =gLinkType
	ldr r2, =0x00001111
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_800B488
	bl OpenLink
	ldr r0, =gMain
	ldrh r0, [r0, 0x24]
	bl SeedRng
	movs r4, 0
_08011B38:
	bl Random
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	adds r1, 0xA
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x3
	ble _08011B38
	movs r1, 0xAA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl sub_8011BA4
	ldr r0, =sub_8011BF8
	bl SetMainCallback2
_08011B70:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011AFC

	thumb_func_start sub_8011B90
sub_8011B90: @ 8011B90
	push {lr}
	ldr r0, =sub_800EB44
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011B90

	thumb_func_start sub_8011BA4
sub_8011BA4: @ 8011BA4
	push {r4,lr}
	ldr r4, =nullsub_89
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _08011BC2
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	ldr r1, =gUnknown_03005000
	adds r1, 0x66
	strb r0, [r1]
_08011BC2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011BA4

	thumb_func_start sub_8011BD0
sub_8011BD0: @ 8011BD0
	push {lr}
	ldr r0, =nullsub_89
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08011BEA
	ldr r0, =gUnknown_03005000
	adds r0, 0x66
	ldrb r0, [r0]
	bl DestroyTask
_08011BEA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011BD0

	thumb_func_start sub_8011BF8
sub_8011BF8: @ 8011BF8
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8011BF8

	thumb_func_start sub_8011C10
sub_8011C10: @ 8011C10
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r1, =gUnknown_03005000
	movs r0, 0x1
	strb r0, [r1, 0xC]
	bl sub_8010F48
	ldr r0, =sub_801120C
	movs r1, 0
	bl sub_800BF4C
	ldr r2, =gUnknown_02022B2C
	adds r1, r2, 0
	ldr r0, =gUnknown_082ED608
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldr r0, =gUnknown_082ED620
	subs r4, 0x1
	adds r4, r0
	ldrb r0, [r4]
	strh r0, [r2, 0x2]
	bl sub_800EE78
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C10

	thumb_func_start sub_8011C5C
sub_8011C5C: @ 8011C5C
	push {lr}
	ldr r1, =gUnknown_03005000
	movs r0, 0
	strb r0, [r1, 0xC]
	bl sub_8010F48
	ldr r0, =sub_8011404
	ldr r1, =sub_800ED34
	bl sub_800BF4C
	bl sub_800EF00
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C5C

	thumb_func_start sub_8011C84
sub_8011C84: @ 8011C84
	push {r4-r7,lr}
	ldr r4, =gUnknown_03005000
	movs r5, 0
	movs r0, 0x2
	strb r0, [r4, 0xC]
	bl sub_8010F48
	ldr r0, =sub_8011674
	movs r1, 0
	bl sub_800BF4C
	ldr r2, =gUnknown_02022B2C
	adds r1, r2, 0
	ldr r0, =gUnknown_082ED608
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	strb r5, [r2, 0x11]
	movs r0, 0x96
	lsls r0, 2
	strh r0, [r2, 0x12]
	ldr r0, =sub_800EB44
	movs r1, 0x1
	bl CreateTask
	adds r4, 0x67
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011C84

	thumb_func_start sub_8011CD8
sub_8011CD8: @ 8011CD8
	ldrb r1, [r0, 0x1]
	lsls r1, 8
	ldrb r0, [r0]
	orrs r0, r1
	bx lr
	thumb_func_end sub_8011CD8

	thumb_func_start sub_8011CE4
sub_8011CE4: @ 8011CE4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	movs r0, 0xFF
	mov r9, r0
	movs r7, 0
	ldr r1, =gUnknown_03007890
	mov r8, r1
_08011D02:
	lsls r4, r7, 5
	adds r5, r4, 0
	adds r5, 0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	adds r0, 0x8
	bl sub_8011CD8
	lsls r0, 16
	lsrs r6, r0, 16
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldrh r0, [r0, 0x18]
	bl sub_8010454
	cmp r0, 0
	beq _08011D4C
	mov r0, r8
	ldr r1, [r0]
	adds r1, r5
	adds r1, 0x15
	ldr r0, [sp]
	bl StringCompare
	cmp r0, 0
	bne _08011D4C
	cmp r10, r6
	bne _08011D4C
	mov r9, r7
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0, 0x16]
	cmp r0, 0xFF
	bne _08011D56
_08011D4C:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08011D02
_08011D56:
	mov r0, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8011CE4

	thumb_func_start sub_8011D6C
sub_8011D6C: @ 8011D6C
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r0, r6, 24
	lsrs r0, 24
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000ce2
	adds r5, r4, r0
	ldrb r0, [r5]
	bics r0, r6
	strb r0, [r5]
	ldr r1, =0x00000cda
	adds r6, r4, r1
	ldrb r1, [r6]
	movs r0, 0x1
	bl rfu_clearSlot
	ldrb r0, [r5]
	ldr r1, =0x00000c87
	adds r4, r1
	adds r1, r4, 0
	movs r2, 0x46
	bl rfu_UNI_setSendData
	ldrb r0, [r5]
	bl sub_800E87C
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011D6C

	thumb_func_start sub_8011DC0
sub_8011DC0: @ 8011DC0
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_8011CE4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08011DDA
	movs r0, 0x1
	lsls r0, r1
	bl sub_8011D6C
_08011DDA:
	pop {r0}
	bx r0
	thumb_func_end sub_8011DC0

	thumb_func_start sub_8011DE0
sub_8011DE0: @ 8011DE0
	push {r4-r6,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _08011E20
	movs r3, 0
	movs r2, 0
	ldr r5, =gUnknown_03005000+0xCDE
	adds r6, r5, 0x4
_08011DF0:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _08011E0E
	ldrb r0, [r6]
	asrs r0, r2
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08011E0E
	adds r0, r1, 0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
_08011E0E:
	adds r2, 0x1
	cmp r2, 0x3
	ble _08011DF0
	cmp r3, 0
	beq _08011E20
	adds r0, r3, 0
	movs r1, 0x2
	bl sub_8011E94
_08011E20:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011DE0

	thumb_func_start sub_8011E2C
sub_8011E2C: @ 8011E2C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gSendCmd
	ldrh r0, [r6]
	cmp r0, 0
	bne _08011E7A
	ldr r5, =gUnknown_03005000
	ldr r1, =0x00000ce8
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08011E7A
	movs r0, 0xED
	lsls r0, 8
	bl sub_800FD14
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	strh r1, [r6, 0x2]
	ldrh r1, [r0, 0xA]
	strh r1, [r6, 0x4]
	ldr r1, =gUnknown_082ED695
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r1, [r5, 0xD]
	ldrb r0, [r0]
	subs r1, r0
	strb r1, [r5, 0xD]
	ldrb r0, [r5, 0xD]
	strh r0, [r6, 0x6]
	adds r0, r4, 0
	bl DestroyTask
_08011E7A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011E2C

	thumb_func_start sub_8011E94
sub_8011E94: @ 8011E94
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r5, =sub_8011E2C
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _08011ECC
	adds r0, r5, 0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	b _08011EDC
	.pool
_08011ECC:
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	orrs r4, r0
	strh r4, [r1, 0x8]
_08011EDC:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0xA]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011E94

	thumb_func_start sub_8011EF4
sub_8011EF4: @ 8011EF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_800EE94
	lsls r0, 24
	cmp r0, 0
	beq _08011FA4
	adds r0, r4, 0
	adds r0, 0x10
	bl sub_8011CD8
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_8011CE4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _08011F8C
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	lsls r1, r2, 5
	adds r0, r1
	ldrb r0, [r0, 0x16]
	cmp r0, 0xFF
	beq _08011F5C
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c3d
	adds r0, r1
	strb r2, [r0]
	bl sub_800EEBC
	cmp r0, 0
	beq _08011FAA
	b _08011F84
	.pool
_08011F5C:
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r5, 0x7F
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x15
	beq _08011FA4
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x16
	beq _08011FA4
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
_08011F84:
	adds r0, r6, 0
	bl DestroyTask
	b _08011FAA
_08011F8C:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c3d
	adds r0, r1
	strb r2, [r0]
	b _08011FAA
	.pool
_08011FA4:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
_08011FAA:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF0
	ble _08011FC2
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	adds r0, r6, 0
	bl DestroyTask
_08011FC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8011EF4

	thumb_func_start sub_8011FC8
sub_8011FC8: @ 8011FC8
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r5, r1, 16
	lsrs r5, 16
	ldr r0, =gUnknown_03005000
	adds r0, 0xF1
	movs r1, 0
	strb r1, [r0]
	ldr r0, =sub_8011EF4
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	adds r0, r4, 0
	adds r1, r6, 0
	bl StringCopy
	strh r5, [r4, 0x10]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8011FC8

	thumb_func_start sub_801200C
sub_801200C: @ 801200C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r5, r0, 16
	bl sub_800F7DC
	ldrb r1, [r0, 0xA]
	movs r2, 0x7F
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x45
	bne _08012032
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x45
	beq _08012092
_0801202E:
	movs r0, 0x1
	b _08012094
_08012032:
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x40
	bne _0801202E
	cmp r5, 0x44
	bne _08012092
	ldr r5, =gUnknown_03005000+0x10A
	ldrh r0, [r5, 0x8]
	ldr r3, =0x000003ff
	adds r2, r3, 0
	ands r2, r0
	movs r0, 0xCE
	lsls r0, 1
	cmp r2, r0
	bne _08012068
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, r2
	beq _08012092
	b _0801202E
	.pool
_08012068:
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, r2
	bne _0801202E
	ldrb r2, [r4, 0xB]
	movs r0, 0xFE
	ldrb r3, [r5, 0xB]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _0801202E
	ldrb r2, [r4, 0x9]
	movs r0, 0xFC
	ldrb r3, [r5, 0x9]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _0801202E
_08012092:
	movs r0, 0
_08012094:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801200C

	thumb_func_start sub_801209C
sub_801209C: @ 801209C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	mov r8, r5
	ldr r6, =gUnknown_03005000
	adds r0, r6, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080120BA
	adds r0, r5, 0
	bl DestroyTask
_080120BA:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	ble _080120E4
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	adds r0, r5, 0
	bl DestroyTask
_080120E4:
	ldr r1, =0x00000ccd
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801217C
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801217C
	movs r2, 0x86
	lsls r2, 1
	adds r0, r6, r2
	bl sub_8011CD8
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =0x00000119
	adds r0, r6, r2
	bl sub_8011CE4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0801217C
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	ldr r7, =gUnknown_03007890
	lsls r4, r2, 5
	adds r2, r4, 0
	adds r2, 0x14
	ldr r1, [r7]
	adds r1, r2
	adds r1, 0x6
	bl sub_801200C
	cmp r0, 0
	bne _0801216C
	ldr r0, [r7]
	adds r1, r0, r4
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _0801217C
	ldrh r0, [r1, 0x14]
	movs r1, 0x5A
	bl sub_800C12C
	lsls r0, 24
	cmp r0, 0
	bne _0801217C
	movs r0, 0xA
	strh r0, [r6, 0x4]
	adds r0, r5, 0
	bl DestroyTask
	b _0801217C
	.pool
_0801216C:
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	mov r0, r8
	bl DestroyTask
_0801217C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801209C

	thumb_func_start sub_8012188
sub_8012188: @ 8012188
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	ldr r6, =gUnknown_03005000
	ldr r1, =0x00000ccf
	adds r0, r6, r1
	movs r7, 0
	strb r7, [r0]
	adds r0, r6, 0
	adds r0, 0xF1
	strb r7, [r0]
	ldr r1, =0x00000119
	adds r0, r6, r1
	adds r1, r3, 0
	bl StringCopy
	movs r1, 0x85
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r5, 0
	movs r2, 0xD
	bl memcpy
	bl sub_800D658
	ldr r0, =sub_801209C
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r4, [r1, 0xA]
	ldr r0, =sub_800EB44
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r4, 0x45
	bne _08012210
	cmp r1, 0xFF
	beq _0801221E
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0x16]
	b _0801221E
	.pool
_08012210:
	cmp r2, 0xFF
	beq _0801221E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r5
	strh r7, [r0, 0x16]
_0801221E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012188

	thumb_func_start sub_8012224
sub_8012224: @ 8012224
	push {lr}
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08012238
	movs r0, 0
	b _0801223A
	.pool
_08012238:
	movs r0, 0x1
_0801223A:
	pop {r1}
	bx r1
	thumb_func_end sub_8012224

	thumb_func_start sub_8012240
sub_8012240: @ 8012240
	push {r4,lr}
	movs r1, 0
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0]
	ldr r4, =gUnknown_03005000+0xCD1
	movs r3, 0x1
_0801224C:
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0801226C
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801226C
	movs r0, 0
	b _08012274
	.pool
_0801226C:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801224C
	movs r0, 0x1
_08012274:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8012240

	thumb_func_start sub_801227C
sub_801227C: @ 801227C
	push {r4,lr}
	movs r4, 0
_08012280:
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r0, =gUnknown_082ED82C
	movs r1, 0
	bl nullsub_5
	adds r4, 0x1
	cmp r4, 0x13
	ble _08012280
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801227C

	thumb_func_start sub_801229C
sub_801229C: @ 801229C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1C
	movs r2, 0x13
	movs r3, 0x2
	bl nullsub_13
	ldr r4, =gUnknown_03007890
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	movs r1, 0x14
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	movs r1, 0x17
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xC]
	cmp r0, 0x1
	bne _08012378
	movs r6, 0
	adds r7, r4, 0
	movs r5, 0x14
_080122E0:
	ldr r2, [r7]
	ldrb r0, [r2, 0x7]
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801231E
	lsls r0, r6, 5
	adds r0, r2, r0
	ldrh r0, [r0, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x6
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_0801231E:
	adds r5, 0x20
	adds r6, 0x1
	cmp r6, 0x3
	ble _080122E0
	movs r6, 0
	ldr r0, =gUnknown_03005000
	mov r8, r0
_0801232C:
	movs r5, 0
	adds r7, r6, 0x1
	lsls r0, r6, 3
	adds r2, r6, 0
	adds r2, 0xB
	subs r0, r6
	lsls r0, 1
	mov r1, r8
	adds r1, 0x14
	adds r4, r0, r1
	lsls r6, r2, 24
_08012342:
	ldrb r0, [r4]
	lsls r1, r5, 25
	lsrs r1, 24
	lsrs r2, r6, 24
	movs r3, 0x2
	bl nullsub_13
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0xD
	ble _08012342
	adds r6, r7, 0
	cmp r6, 0x3
	ble _0801232C
	ldr r0, =gUnknown_082ED868
	movs r1, 0x1
	movs r2, 0xF
	bl nullsub_5
	b _080124AA
	.pool
_08012378:
	ldr r1, [r4]
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08012414
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08012414
	movs r6, 0
	movs r5, 0xC0
	lsls r5, 18
_0801238C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r1, 0x80
	lsls r1, 17
	adds r5, r1
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801238C
	ldr r5, =gUnknown_03007890
	ldr r1, [r5]
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r4, r0
	ldrb r0, [r4]
	lsls r0, 5
	adds r1, r0
	ldrh r0, [r1, 0x18]
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x4
	bl nullsub_13
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x6
	movs r1, 0x6
	movs r2, 0x3
	bl nullsub_5
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x15
	movs r1, 0x16
	movs r2, 0x3
	bl nullsub_5
	b _080124AA
	.pool
_08012414:
	movs r6, 0
	ldr r1, =gUnknown_03007890
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	bge _08012470
	adds r7, r1, 0
	movs r1, 0x14
	mov r8, r1
_08012426:
	ldr r0, [r7]
	lsls r5, r6, 5
	adds r1, r0, r5
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _08012462
	ldrh r0, [r1, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	ldrh r0, [r0, 0x14]
	movs r1, 0x6
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	add r0, r8
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_08012462:
	movs r0, 0x20
	add r8, r0
	adds r6, 0x1
	ldr r0, [r7]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	blt _08012426
_08012470:
	cmp r6, 0x3
	bgt _080124AA
	lsls r0, r6, 24
	movs r1, 0xC0
	lsls r1, 18
	adds r5, r0, r1
_0801247C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r0, 0x80
	lsls r0, 17
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801247C
_080124AA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801229C

	thumb_func_start sub_80124C0
sub_80124C0: @ 80124C0
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c1a
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124C0

	thumb_func_start sub_80124D4
sub_80124D4: @ 80124D4
	ldr r0, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124D4

	.align 2, 0 @ don't pad with nop
