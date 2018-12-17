	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_81D4D50
sub_81D4D50: @ 81D4D50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gIntrTable
	ldr r0, =sub_81D3FAC
	str r0, [r1, 0x4]
	ldr r0, =sub_81D3F9C
	str r0, [r1, 0x8]
	bl sub_81D41A0
	bl sub_81D4238
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	strh r0, [r5]
	str r6, [r5, 0x4]
	mov r0, r8
	str r0, [r5, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4D50

	thumb_func_start sub_81D4DB8
sub_81D4DB8: @ 81D4DB8
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	bl sub_81D4238
	bl sub_81D41F4
	bl RestoreSerialTimer3IntrHandlers
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4DB8

	thumb_func_start sub_81D4DE8
sub_81D4DE8: @ 81D4DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	movs r0, 0x1
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	strh r1, [r4]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D4E08
	movs r5, 0x1
_081D4E08:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D4E12
	movs r5, 0x2
_081D4E12:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D4E1C
	movs r5, 0x3
_081D4E1C:
	ldr r1, =gShouldAdvanceLinkState
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4DE8

	thumb_func_start sub_81D4E30
sub_81D4E30: @ 81D4E30
	push {lr}
	ldr r0, =gDecompressionBuffer
	movs r2, 0x80
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r1, =gLinkType
	ldr r2, =0x00005503
	adds r0, r2, 0
	strh r0, [r1]
	bl OpenLink
	movs r0, 0x1
	bl SetSuppressLinkErrorMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4E30

	thumb_func_start sub_81D4E60
sub_81D4E60: @ 81D4E60
	push {lr}
	sub sp, 0xC
	mov r1, sp
	ldr r2, =0x04000208
	ldrh r0, [r2]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r2]
	ldr r0, =gLink+0x4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	add r2, sp, 0x4
	ldrh r1, [r2]
	ldr r0, =0x0000b9a0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ccd0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x4]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081D4EB8
	ldrh r0, [r2, 0x6]
	cmp r0, r1
	bne _081D4EB8
	movs r0, 0x1
	b _081D4EBA
	.pool
_081D4EB8:
	movs r0, 0
_081D4EBA:
	add sp, 0xC
	pop {r1}
	bx r1
	thumb_func_end sub_81D4E60

	thumb_func_start sub_81D4EC0
sub_81D4EC0: @ 81D4EC0
	push {lr}
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4EDC
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4EDC
	movs r0, 0x1
	b _081D4EDE
_081D4EDC:
	movs r0, 0
_081D4EDE:
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EC0

	thumb_func_start sub_81D4EE4
sub_81D4EE4: @ 81D4EE4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081D4F08
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D4F08
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	b _081D500E
_081D4F08:
	ldrb r0, [r4]
	cmp r0, 0x5
	bls _081D4F10
	b _081D500C
_081D4F10:
	lsls r0, 2
	ldr r1, =_081D4F20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D4F20:
	.4byte _081D4F38
	.4byte _081D4F54
	.4byte _081D4F6C
	.4byte _081D4FA0
	.4byte _081D4FEC
	.4byte _081D4FF8
_081D4F38:
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4F88
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D4F88
	movs r0, 0x1
	strb r0, [r4]
	b _081D500C
_081D4F54:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _081D500C
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x2
	strb r0, [r4]
	b _081D500C
_081D4F6C:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4F88
	movs r0, 0x49
	bl PlaySE
	bl sub_800A620
	movs r0, 0
	strh r0, [r5]
	b _081D4FE6
_081D4F88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D500C
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _081D500E
	.pool
_081D4FA0:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081D4FB6
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x5
	b _081D500E
_081D4FB6:
	bl IsLinkConnectionEstablished
	lsls r0, 24
	cmp r0, 0
	beq _081D500C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D4FE6
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, 24
	cmp r0, 0
	beq _081D4FE0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x2
	b _081D500E
	.pool
_081D4FE0:
	movs r0, 0x4
	strb r0, [r4]
	b _081D500C
_081D4FE6:
	movs r0, 0x3
	strb r0, [r4]
	b _081D500C
_081D4FEC:
	movs r0, 0
	bl sub_800ABF4
	movs r0, 0x5
	strb r0, [r4]
	b _081D500C
_081D4FF8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D500C
	strb r0, [r4]
	movs r0, 0x4
	b _081D500E
	.pool
_081D500C:
	movs r0, 0
_081D500E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EE4

	thumb_func_start sub_81D5014
sub_81D5014: @ 81D5014
	push {r4,lr}
	ldr r0, =sub_81D5084
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0
	strb r0, [r4, 0x8]
	strb r0, [r4, 0x9]
	strb r0, [r4, 0xA]
	strb r0, [r4, 0xB]
	strb r0, [r4, 0xC]
	strb r0, [r4, 0xD]
	movs r1, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r1, [r4, 0xE]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5014

	thumb_func_start sub_81D505C
sub_81D505C: @ 81D505C
	movs r1, 0
	strh r1, [r0]
	bx lr
	thumb_func_end sub_81D505C

	thumb_func_start sub_81D5064
sub_81D5064: @ 81D5064
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, r1
	bhi _081D507A
	movs r0, 0
	b _081D5080
_081D507A:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
_081D5080:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5064

	thumb_func_start sub_81D5084
sub_81D5084: @ 81D5084
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1A
	bls _081D509C
	b _081D548A
_081D509C:
	lsls r0, 2
	ldr r1, =_081D50B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D50B0:
	.4byte _081D511C
	.4byte _081D5138
	.4byte _081D5148
	.4byte _081D515C
	.4byte _081D516C
	.4byte _081D5198
	.4byte _081D51D0
	.4byte _081D524C
	.4byte _081D5268
	.4byte _081D5290
	.4byte _081D52AC
	.4byte _081D52DC
	.4byte _081D52F2
	.4byte _081D5308
	.4byte _081D536A
	.4byte _081D5390
	.4byte _081D53A8
	.4byte _081D53C6
	.4byte _081D53F2
	.4byte _081D5418
	.4byte _081D5448
	.4byte _081D5454
	.4byte _081D5460
	.4byte _081D5430
	.4byte _081D548A
	.4byte _081D548A
	.4byte _081D5478
_081D511C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFD6
	bl mevent_0814257C
	cmp r0, 0
	bne _081D512C
	b _081D548A
_081D512C:
	movs r0, 0x1
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5138:
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _081D548A
_081D5148:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D5156
	b _081D548A
_081D5156:
	movs r0, 0x3
	strb r0, [r4, 0x8]
	b _081D548A
_081D515C:
	bl sub_81D4EC0
	cmp r0, 0
	beq _081D5166
	b _081D52FC
_081D5166:
	bl CloseLink
	b _081D525C
_081D516C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFF5
	bl mevent_0814257C
	cmp r0, 0
	bne _081D517C
	b _081D548A
_081D517C:
	ldr r0, =gUnknown_085EE014
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5198:
	adds r0, r4, 0
	movs r1, 0x5A
	bl sub_81D5064
	cmp r0, 0
	beq _081D51AE
	bl sub_81D4E30
	movs r0, 0x6
	strb r0, [r4, 0x8]
	b _081D548A
_081D51AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D51BC
	b _081D548A
_081D51BC:
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	bl PlaySE
	b _081D535A
	.pool
_081D51D0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D51F4
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	b _081D535A
	.pool
_081D51F4:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D5210
	adds r0, r4, 0
	bl sub_81D505C
	bl CloseLink
	movs r0, 0x7
	strb r0, [r4, 0x8]
	b _081D548A
_081D5210:
	bl sub_81D4E60
	cmp r0, 0
	beq _081D522E
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x8
	strb r0, [r4, 0x8]
	b _081D548A
_081D522E:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D523C
	b _081D548A
_081D523C:
	bl CloseLink
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	b _081D548A
_081D524C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE05C
	bl mevent_0814257C
	cmp r0, 0
	bne _081D525C
	b _081D548A
_081D525C:
	movs r0, 0x4
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5268:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	ldr r0, =gUnknown_03006370
	ldr r1, =gUnknownSerialData_End
	ldr r2, =gUnknownSerialData_Start
	subs r1, r2
	bl sub_81D4D50
	movs r0, 0x9
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5290:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DE8
	strb r0, [r4, 0xE]
	lsls r0, 24
	cmp r0, 0
	bne _081D52A0
	b _081D548A
_081D52A0:
	movs r0, 0xA
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52AC:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DB8
	ldrb r0, [r4, 0xE]
	cmp r0, 0x3
	bne _081D52BA
	b _081D53C0
_081D52BA:
	cmp r0, 0x1
	beq _081D52C0
	b _081D546E
_081D52C0:
	adds r0, r4, 0
	bl sub_81D505C
	ldr r0, =gUnknown_085EE120
	bl sub_8018884
	movs r0, 0xB
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52DC:
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r4, 0
	bl sub_81D5064
	cmp r0, 0
	bne _081D52EC
	b _081D548A
_081D52EC:
	movs r0, 0xC
	strb r0, [r4, 0x8]
	b _081D548A
_081D52F2:
	bl sub_81D4E30
	ldr r0, =gUnknown_085EE0DC
	bl sub_8018884
_081D52FC:
	movs r0, 0xD
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5308:
	adds r0, r4, 0
	adds r0, 0x9
	adds r1, r4, 0
	bl sub_81D4EE4
	cmp r0, 0x5
	bls _081D5318
	b _081D548A
_081D5318:
	lsls r0, 2
	ldr r1, =_081D5328
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D5328:
	.4byte _081D548A
	.4byte _081D5350
	.4byte _081D5340
	.4byte _081D5374
	.4byte _081D5374
	.4byte _081D5360
_081D5340:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	movs r0, 0xE
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5350:
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
_081D535A:
	movs r0, 0x17
	strb r0, [r4, 0x8]
	b _081D548A
_081D5360:
	bl CloseLink
	movs r0, 0x15
	strb r0, [r4, 0x8]
	b _081D548A
_081D536A:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D537A
_081D5374:
	bl CloseLink
	b _081D53C0
_081D537A:
	bl GetBlockReceivedStatus
	lsls r0, 24
	cmp r0, 0
	bne _081D5386
	b _081D548A
_081D5386:
	bl ResetBlockReceivedFlags
	movs r0, 0xF
	strb r0, [r4, 0x8]
	b _081D548A
_081D5390:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3920
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0xE]
	bl sub_800ABF4
	movs r0, 0x10
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53A8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D548A
	ldrb r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081D53C0
	movs r0, 0x11
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53C0:
	movs r0, 0x14
	strb r0, [r4, 0x8]
	b _081D548A
_081D53C6:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3AB0
	cmp r0, 0
	beq _081D53EC
	ldr r0, =gUnknown_085EE0FA
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x12
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53EC:
	movs r0, 0x16
	strb r0, [r4, 0x8]
	b _081D548A
_081D53F2:
	adds r0, r4, 0
	movs r1, 0x78
	bl sub_81D5064
	cmp r0, 0
	beq _081D548A
	ldr r0, =gUnknown_085EE107
	bl sub_8018884
	movs r0, 0xB9
	lsls r0, 1
	bl PlayFanfare
	movs r0, 0x13
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5418:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _081D548A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	b _081D543A
	.pool
_081D5430:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE06B
	bl mevent_0814257C
_081D543A:
	cmp r0, 0
	beq _081D548A
	movs r0, 0x1A
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5448:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0A3
	b _081D5466
	.pool
_081D5454:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0BF
	b _081D5466
	.pool
_081D5460:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE12D
_081D5466:
	bl mevent_0814257C
	cmp r0, 0
	beq _081D548A
_081D546E:
	movs r0, 0
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5478:
	ldr r0, [r4, 0x10]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_081D548A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5084
