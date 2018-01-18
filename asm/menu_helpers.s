	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ResetVramOamAndBgCntRegs
ResetVramOamAndBgCntRegs: @ 8121DA0
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x0100c000
	mov r0, sp
	bl CpuSet
	movs r4, 0
	str r4, [sp, 0x4]
	add r0, sp, 0x4
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x05000100
	bl CpuSet
	add r0, sp, 0x8
	strh r4, [r0]
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x01000200
	bl CpuSet
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetVramOamAndBgCntRegs

	thumb_func_start ResetAllBgsCoordinates
ResetAllBgsCoordinates: @ 8121E10
	push {lr}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end ResetAllBgsCoordinates

	thumb_func_start SetVBlankHBlankCallbacksToNull
@ void SetVBlankHBlankCallbacksToNull()
SetVBlankHBlankCallbacksToNull: @ 8121E68
	push {lr}
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	pop {r0}
	bx r0
	thumb_func_end SetVBlankHBlankCallbacksToNull

	thumb_func_start DisplayMessageAndContinueTask
@ void DisplayMessageAndContinueTask(u8 taskId, u8 windowId, u16 windowBorderFirstTileNum, u8 windowBorderPalette, u8 fontId, u8 speed, u8 *str, void ( *callback)(u8 taskId))
DisplayMessageAndContinueTask: @ 8121E7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	adds r6, r1, 0
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r7, r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203A140
	strb r6, [r0]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8197B1C
	ldr r4, =gStringVar4
	ldr r0, [sp, 0x30]
	cmp r0, r4
	beq _08121EC0
	adds r0, r4, 0
	ldr r1, [sp, 0x30]
	bl StringExpandPlaceholders
_08121EC0:
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl AddTextPrinterParametrized
	ldr r1, =gUnknown_0300117C
	ldr r0, [sp, 0x34]
	str r0, [r1]
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldr r1, =Task_ContinueTaskAfterMessagePrints
	str r1, [r0]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DisplayMessageAndContinueTask

	thumb_func_start RunTextPrintersRetIsActive
RunTextPrintersRetIsActive: @ 8121F20
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl RunTextPrinters
	adds r0, r4, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end RunTextPrintersRetIsActive

	thumb_func_start Task_ContinueTaskAfterMessagePrints
@ void Task_ContinueTaskAfterMessagePrints(u8 taskId)
Task_ContinueTaskAfterMessagePrints: @ 8121F3C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203A140
	ldrb r0, [r0]
	bl RunTextPrintersRetIsActive
	lsls r0, 16
	cmp r0, 0
	bne _08121F5A
	ldr r0, =gUnknown_0300117C
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
_08121F5A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_ContinueTaskAfterMessagePrints

	thumb_func_start sub_8121F68
sub_8121F68: @ 8121F68
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_0203A138
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [r3]
	str r2, [r3, 0x4]
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =Task_CallYesOrNoCallback
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8121F68

	thumb_func_start CreateYesNoMenuWithCallbacks
@ void CreateYesNoMenuWithCallbacks(u8 taskId, struct WindowTemplate *windowTemplate, int a3, int a4, int a5, u16 borderFirstTileNum, u8 borderPalette, void ( **callbacks)(u8 taskId))
CreateYesNoMenuWithCallbacks: @ 8121F94
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x14]
	ldr r5, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	bl CreateYesNoMenu
	ldr r2, =gUnknown_0203A138
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =Task_CallYesOrNoCallback
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateYesNoMenuWithCallbacks

	thumb_func_start Task_CallYesOrNoCallback
@ void Task_CallYesOrNoCallback(u8 taskId)
Task_CallYesOrNoCallback: @ 8121FDC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _08122002
	cmp r1, 0
	bgt _08121FFC
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08122018
	b _08122028
_08121FFC:
	cmp r1, 0x1
	beq _08122018
	b _08122028
_08122002:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203A138
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	b _08122028
	.pool
_08122018:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203A138
	ldr r1, [r0, 0x4]
	adds r0, r4, 0
	bl _call_via_r1
_08122028:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_CallYesOrNoCallback

	thumb_func_start AdjustQuantityAccordingToDPadInput
@ bool8 AdjustQuantityAccordingToDPadInput(u16 *quantity, u16 maxQuantity)
AdjustQuantityAccordingToDPadInput: @ 8122034
	push {r4-r6,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r5, r1, 0
	ldrh r4, [r2]
	adds r6, r4, 0
	ldr r0, =gMain
	ldrh r0, [r0, 0x30]
	movs r3, 0xF0
	ands r3, r0
	cmp r3, 0x40
	bne _0812206C
	adds r0, r4, 0x1
	strh r0, [r2]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, r1
	ble _0812205E
	movs r0, 0x1
	strh r0, [r2]
_0812205E:
	movs r0, 0
	ldrsh r1, [r2, r0]
_08122062:
	lsls r0, r4, 16
	b _081220B6
	.pool
_0812206C:
	cmp r3, 0x80
	bne _08122082
	subs r0, r4, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	bgt _0812207C
	strh r1, [r2]
_0812207C:
	movs r3, 0
	ldrsh r1, [r2, r3]
	b _08122062
_08122082:
	cmp r3, 0x10
	bne _0812209C
	adds r0, r4, 0
	adds r0, 0xA
	strh r0, [r2]
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, r5
	ble _08122096
	strh r5, [r2]
_08122096:
	movs r3, 0
	ldrsh r1, [r2, r3]
	b _08122062
_0812209C:
	cmp r3, 0x20
	bne _081220C6
	adds r0, r4, 0
	subs r0, 0xA
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	bgt _081220B0
	movs r0, 0x1
	strh r0, [r2]
_081220B0:
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r6, 16
_081220B6:
	asrs r0, 16
	cmp r1, r0
	beq _081220C6
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	b _081220C8
_081220C6:
	movs r0, 0
_081220C8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end AdjustQuantityAccordingToDPadInput

	thumb_func_start GetLRKeysState
GetLRKeysState: @ 81220D0
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _08122106
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _081220F8
	movs r0, 0x1
	b _08122108
	.pool
_081220F8:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08122106
	movs r0, 0x2
	b _08122108
_08122106:
	movs r0, 0
_08122108:
	pop {r1}
	bx r1
	thumb_func_end GetLRKeysState

	thumb_func_start sub_812210C
sub_812210C: @ 812210C
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x1
	bne _08122142
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _08122134
	movs r0, 0x1
	b _08122144
	.pool
_08122134:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08122142
	movs r0, 0x2
	b _08122144
_08122142:
	movs r0, 0
_08122144:
	pop {r1}
	bx r1
	thumb_func_end sub_812210C

	thumb_func_start sub_8122148
sub_8122148: @ 8122148
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _08122174
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00001919
	cmp r1, r0
	beq _08122166
	bl InUnionRoom
	cmp r0, 0x1
	bne _08122174
_08122166:
	movs r0, 0
	b _08122176
	.pool
_08122174:
	movs r0, 0x1
_08122176:
	pop {r1}
	bx r1
	thumb_func_end sub_8122148

	thumb_func_start itemid_80BF6D8_mail_related
itemid_80BF6D8_mail_related: @ 812217C
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl is_c1_link_related_active
	cmp r0, 0x1
	beq _08122192
	bl InUnionRoom
	cmp r0, 0x1
	bne _081221A4
_08122192:
	adds r0, r4, 0
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081221A4
	movs r0, 0
	b _081221A6
_081221A4:
	movs r0, 0x1
_081221A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end itemid_80BF6D8_mail_related

	thumb_func_start sub_81221AC
sub_81221AC: @ 81221AC
	push {lr}
	bl is_c1_link_related_active
	cmp r0, 0x1
	beq _081221BE
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081221C8
_081221BE:
	movs r0, 0x1
	b _081221CA
	.pool
_081221C8:
	movs r0, 0
_081221CA:
	pop {r1}
	bx r1
	thumb_func_end sub_81221AC

	thumb_func_start sub_81221D0
sub_81221D0: @ 81221D0
	push {lr}
	bl sub_81221AC
	lsls r0, 24
	cmp r0, 0
	beq _081221E6
	bl sub_8087598
	lsls r0, 24
	lsrs r0, 24
	b _081221E8
_081221E6:
	movs r0, 0
_081221E8:
	pop {r1}
	bx r1
	thumb_func_end sub_81221D0

	thumb_func_start sub_81221EC
sub_81221EC: @ 81221EC
	push {lr}
	bl sub_81221D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08122202
	bl sub_800B504
	cmp r0, 0x1
	bne _08122206
_08122202:
	movs r0, 0x1
	b _08122208
_08122206:
	movs r0, 0
_08122208:
	pop {r1}
	bx r1
	thumb_func_end sub_81221EC

	thumb_func_start sub_812220C
sub_812220C: @ 812220C
	push {r4-r6,lr}
	adds r6, r2, 0
	ldr r2, [sp, 0x10]
	lsls r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r3]
	movs r2, 0
	lsrs r1, 24
	cmp r2, r1
	bcs _08122240
_08122226:
	lsls r0, r2, 2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0
	beq _08122236
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_08122236:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r1
	bcc _08122226
_08122240:
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, r5
	bls _08122252
	strb r5, [r6]
	b _08122254
_08122252:
	strb r1, [r6]
_08122254:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812220C

	thumb_func_start sub_812225C
sub_812225C: @ 812225C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldrh r0, [r4]
	cmp r0, 0
	beq _0812227A
	adds r0, r2
	cmp r0, r3
	ble _0812227A
	subs r0, r3, r2
	strh r0, [r4]
_0812227A:
	ldrh r0, [r4]
	ldrh r1, [r5]
	adds r0, r1
	cmp r0, r3
	blt _08122290
	cmp r3, 0
	bne _0812228C
	strh r3, [r5]
	b _08122290
_0812228C:
	subs r0, r3, 0x1
	strh r0, [r5]
_08122290:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812225C

	thumb_func_start sub_8122298
sub_8122298: @ 8122298
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, [sp, 0x14]
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r2, r0, 24
	lsrs r0, r2, 24
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081222F0
	lsrs r2, 25
	ldrh r0, [r4]
	cmp r0, r2
	bcc _08122322
	movs r1, 0
	subs r0, r2
	cmp r1, r0
	bge _08122322
	ldrh r0, [r5]
	adds r0, r7
	cmp r0, r6
	beq _08122322
_081222CC:
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	ldrh r0, [r4]
	subs r0, r2
	cmp r1, r0
	bge _08122322
	ldrh r0, [r5]
	adds r0, r7
	cmp r0, r6
	bne _081222CC
	b _08122322
_081222F0:
	ldrh r3, [r4]
	lsrs r2, 25
	adds r0, r2, 0x1
	cmp r3, r0
	blt _08122322
	movs r1, 0
	subs r0, r3, r2
	b _08122316
_08122300:
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	ldrh r0, [r4]
	subs r0, r2
_08122316:
	cmp r1, r0
	bgt _08122322
	ldrh r0, [r5]
	adds r0, r7
	cmp r0, r6
	bne _08122300
_08122322:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8122298

	thumb_func_start LoadListMenuArrowsGfx
LoadListMenuArrowsGfx: @ 8122328
	push {lr}
	ldr r0, =gUnknown_0859F514
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0859F51C
	bl LoadCompressedObjectPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadListMenuArrowsGfx

	thumb_func_start sub_8122344
sub_8122344: @ 8122344
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r5, 0
	cmp r5, r6
	bcs _0812239C
	ldr r7, =gSprites
_08122358:
	lsls r1, r5, 4
	ldr r0, =gUnknown_0859F524
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	mov r1, r8
	adds r4, r1, r5
	strb r0, [r4]
	cmp r5, 0
	beq _0812237E
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x1
	bl StartSpriteAnim
_0812237E:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _08122358
_0812239C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122344

	thumb_func_start sub_81223B0
sub_81223B0: @ 81223B0
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	cmp r4, r5
	bcs _081223F6
	ldr r7, =gSprites
_081223C0:
	subs r0, r5, 0x1
	cmp r4, r0
	bne _081223DC
	adds r0, r6, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySpriteAndFreeResources
	b _081223EC
	.pool
_081223DC:
	adds r0, r6, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySprite
_081223EC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081223C0
_081223F6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81223B0

	thumb_func_start sub_81223FC
sub_81223FC: @ 81223FC
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r0, r2, 24
	movs r3, 0
	cmp r3, r4
	bcs _0812243E
	ldr r1, =gSprites
	mov r12, r1
	movs r1, 0x1
	ands r0, r1
	lsls r5, r0, 2
	movs r7, 0x5
	negs r7, r7
_0812241C:
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r12
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	orrs r0, r5
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcc _0812241C
_0812243E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81223FC

	thumb_func_start sub_8122448
@ void sub_8122448(int a1, u8 a2, u16 x, u16 y)
sub_8122448: @ 8122448
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	mov r9, r3
	movs r0, 0x80
	ands r0, r4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x7F
	ands r4, r0
	movs r3, 0
	cmp r3, r4
	bcs _081224C8
	ldr r5, =gSprites
	lsls r0, r7, 16
	asrs r0, 16
	subs r0, 0x8
	mov r12, r0
_0812247E:
	subs r0, r4, 0x1
	cmp r3, r0
	bne _081224A0
	mov r0, r8
	cmp r0, 0
	beq _081224A0
	adds r2, r6, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r12
	strh r1, [r0, 0x24]
	b _081224AE
	.pool
_081224A0:
	adds r2, r6, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x24]
_081224AE:
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r9
	adds r1, 0x1
	strh r1, [r0, 0x22]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcc _0812247E
_081224C8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8122448

	.align 2, 0 @ Don't pad with nop.
