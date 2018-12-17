	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_8016CA0
sub_8016CA0: @ 8016CA0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r7, 0
	mov r0, sp
	adds r0, 0x10
	str r0, [sp, 0x18]
_08016CC4:
	lsls r2, r7, 24
	lsrs r2, 24
	mov r0, sp
	ldr r1, [sp, 0x18]
	bl sub_800DE7C
	lsls r0, 24
	lsrs r4, r0, 24
	mov r0, sp
	ldrb r0, [r0, 0xA]
	lsls r0, 25
	lsrs r0, 25
	mov r2, r10
	lsls r1, r2, 2
	add r1, r10
	lsls r1, 3
	ldr r3, =gTasks
	adds r1, r3
	movs r5, 0x10
	ldrsh r1, [r1, r5]
	bl sub_8013D88
	cmp r0, 0
	bne _08016D00
	mov r1, sp
	ldr r0, =gUnknown_082F045C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_08016D00:
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _08016D18
	mov r1, sp
	ldr r0, =gUnknown_082F045C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_08016D18:
	cmp r4, 0
	bne _08016D9C
	lsls r0, r7, 3
	mov r8, r0
	adds r1, r7, 0x1
	mov r9, r1
	cmp r7, 0
	ble _08016D58
	movs r2, 0
	str r2, [sp, 0x1C]
	adds r4, r7, 0
_08016D2E:
	ldr r0, [r6, 0x4]
	ldr r3, [sp, 0x1C]
	adds r0, r3
	mov r1, sp
	bl sub_8017630
	lsls r0, 24
	cmp r0, 0
	bne _08016D4C
	mov r1, sp
	ldr r0, =gUnknown_082F045C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_08016D4C:
	ldr r5, [sp, 0x1C]
	adds r5, 0x1C
	str r5, [sp, 0x1C]
	subs r4, 0x1
	cmp r4, 0
	bne _08016D2E
_08016D58:
	ldr r1, [r6, 0x4]
	mov r0, r8
	subs r4, r0, r7
	lsls r4, 2
	adds r1, r4
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r6, 0x4]
	adds r0, r4
	ldr r1, =gUnknown_082F045C
	bl sub_8017630
	ldr r3, [r6, 0x4]
	adds r3, r4
	movs r2, 0x1
	ands r2, r0
	ldrb r0, [r3, 0x18]
	movs r4, 0x2
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x18]
	b _08016DD4
	.pool
_08016D9C:
	ldr r1, [r6]
	lsls r4, r7, 3
	subs r4, r7
	lsls r4, 2
	adds r1, r4
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r6]
	adds r0, r4
	ldr r1, =gUnknown_082F045C
	bl sub_8017630
	ldr r3, [r6]
	adds r3, r4
	movs r2, 0x1
	ands r2, r0
	ldrb r0, [r3, 0x18]
	movs r4, 0x2
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x18]
	adds r7, 0x1
	mov r9, r7
_08016DD4:
	mov r7, r9
	cmp r7, 0x3
	bgt _08016DDC
	b _08016CC4
_08016DDC:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8016CA0

	thumb_func_start sub_8016DF0
sub_8016DF0: @ 8016DF0
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, =sub_8016CA0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r2, =gTasks + 0x8
	adds r3, r1, r2
	str r4, [r3]
	str r5, [r3, 0x4]
	adds r2, r1
	strh r6, [r2, 0x8]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8016DF0

	thumb_func_start sub_8016E24
sub_8016E24: @ 8016E24
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r3, 0
_08016E42:
	lsls r4, r3, 3
	subs r0, r4, r3
	lsls r5, r0, 2
	ldr r0, [r6]
	adds r0, r5
	adds r1, r0, 0
	adds r1, 0x10
	lsls r2, r3, 24
	lsrs r2, 24
	str r3, [sp]
	bl sub_800DE7C
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0, 0xA]
	lsls r0, 25
	lsrs r0, 25
	mov r2, r10
	lsls r1, r2, 2
	add r1, r10
	lsls r1, 3
	ldr r7, =gTasks
	adds r1, r7
	movs r2, 0xC
	ldrsh r1, [r1, r2]
	bl sub_8013D88
	mov r8, r4
	ldr r3, [sp]
	cmp r0, 0
	bne _08016E8E
	ldr r1, [r6]
	adds r1, r5
	ldr r0, =gUnknown_082F045C
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
_08016E8E:
	adds r4, r3, 0x1
	mov r9, r4
	cmp r3, 0
	ble _08016ED2
	str r5, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	adds r4, r3, 0
_08016E9E:
	ldr r1, [r6]
	ldr r7, [sp, 0x8]
	adds r0, r1, r7
	ldr r2, [sp, 0x4]
	adds r1, r2
	str r3, [sp]
	bl sub_8017630
	lsls r0, 24
	ldr r3, [sp]
	cmp r0, 0
	bne _08016EC6
	ldr r1, [r6]
	ldr r5, [sp, 0x4]
	adds r1, r5
	ldr r0, =gUnknown_082F045C
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
_08016EC6:
	ldr r7, [sp, 0x8]
	adds r7, 0x1C
	str r7, [sp, 0x8]
	subs r4, 0x1
	cmp r4, 0
	bne _08016E9E
_08016ED2:
	mov r0, r8
	subs r4, r0, r3
	lsls r4, 2
	ldr r0, [r6]
	adds r0, r4
	ldr r1, =gUnknown_082F045C
	bl sub_8017630
	ldr r3, [r6]
	adds r3, r4
	movs r2, 0x1
	ands r2, r0
	ldrb r0, [r3, 0x18]
	movs r4, 0x2
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x18]
	mov r3, r9
	cmp r3, 0x3
	ble _08016E42
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8016E24

	thumb_func_start sub_8016F1C
sub_8016F1C: @ 8016F1C
	push {lr}
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7
	bne _08016F2C
	ldrb r1, [r0]
	movs r0, 0x20
	b _08016F34
_08016F2C:
	cmp r1, 0x8
	bne _08016F3E
	ldrb r1, [r0]
	movs r0, 0x10
_08016F34:
	ands r0, r1
	cmp r0, 0
	beq _08016F3E
	movs r0, 0x1
	b _08016F40
_08016F3E:
	movs r0, 0
_08016F40:
	pop {r1}
	bx r1
	thumb_func_end sub_8016F1C

	thumb_func_start sub_8016F44
sub_8016F44: @ 8016F44
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r6, 0
	subs r0, 0x8
	movs r5, 0
	adds r1, r0
	mov r8, r1
_08016F62:
	ldr r0, [r4]
	adds r0, r5
	adds r1, r0, 0
	adds r1, 0x10
	lsls r2, r6, 24
	lsrs r2, 24
	bl sub_800DF34
	lsls r0, 24
	cmp r0, 0
	beq _08016F86
	ldr r0, [r4]
	adds r0, r5
	mov r2, r8
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	bl sub_8016F1C
_08016F86:
	ldr r0, [r4]
	adds r0, r5
	ldr r1, =gUnknown_082F045C
	bl sub_8017630
	ldr r3, [r4]
	adds r3, r5
	movs r2, 0x1
	ands r2, r0
	ldrb r0, [r3, 0x18]
	movs r7, 0x2
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x18]
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _08016F62
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8016F44

	thumb_func_start sub_8016FC0
sub_8016FC0: @ 8016FC0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =sub_8016E24
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r1, =gTasks + 0x8
	adds r3, r2, r1
	str r4, [r3]
	adds r1, r2
	strh r5, [r1, 0x4]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8016FC0

	thumb_func_start sub_8016FF0
sub_8016FF0: @ 8016FF0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =sub_8016F44
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r1, =gTasks + 0x8
	adds r3, r2, r1
	str r4, [r3]
	adds r1, r2
	strh r5, [r1, 0x4]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8016FF0

	thumb_func_start sub_8017020
sub_8017020: @ 8017020
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81973A4
	movs r0, 0
	movs r1, 0x1
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterWithCustomSpeedForMessage
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8017020

	thumb_func_start sub_801704C
sub_801704C: @ 801704C
	push {lr}
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, 16
	cmp r0, 0
	beq _0801705C
	movs r0, 0
	b _0801705E
_0801705C:
	movs r0, 0x1
_0801705E:
	pop {r1}
	bx r1
	thumb_func_end sub_801704C

	thumb_func_start PrintOnTextbox
PrintOnTextbox: @ 8017064
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _08017076
	cmp r0, 0x1
	beq _0801709C
	b _080170AE
_08017076:
	bl sub_81973A4
	movs r0, 0
	movs r1, 0x1
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r0, =gStringVar4
	adds r1, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage_2
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _080170AE
	.pool
_0801709C:
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _080170AE
	strb r0, [r4]
	movs r0, 0x1
	b _080170B0
_080170AE:
	movs r0, 0
_080170B0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end PrintOnTextbox

	thumb_func_start sub_80170B8
sub_80170B8: @ 80170B8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080170CA
	cmp r0, 0x1
	beq _080170E0
	b _0801710C
_080170CA:
	cmp r5, 0
	beq _080170D4
	movs r0, 0x3
	negs r0, r0
	b _08017110
_080170D4:
	bl DisplayYesNoMenu
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801710C
_080170E0:
	cmp r5, 0
	beq _080170F2
	bl sub_8198C78
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	negs r0, r0
	b _08017110
_080170F2:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x2
	bhi _0801710C
	strb r5, [r4]
	adds r0, r1, 0
	b _08017110
_0801710C:
	movs r0, 0x2
	negs r0, r0
_08017110:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80170B8

	thumb_func_start sub_8017118
sub_8017118: @ 8017118
	push {r4,lr}
	sub sp, 0x8
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	adds r0, r4, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_082EFD94
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl sub_80173E0
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8017118

	thumb_func_start sub_8017168
sub_8017168: @ 8017168
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	pop {r0}
	bx r0
	thumb_func_end sub_8017168

	thumb_func_start sub_8017178
sub_8017178: @ 8017178
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	adds r5, r1, 0
	mov r9, r2
	ldrb r4, [r7]
	cmp r4, 0
	beq _08017194
	cmp r4, 0x1
	beq _08017228
	b _0801728E
_08017194:
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [sp, 0x24]
	bl sub_81DB41C
	adds r1, r0, 0
	ldr r2, [sp]
	lsrs r0, r2, 24
	cmp r0, r1
	ble _080171B6
	lsls r1, 24
	ldr r0, =0x00ffffff
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_080171B6:
	ldr r2, [sp]
	lsrs r0, r2, 8
	lsls r0, 24
	lsrs r0, 24
	lsrs r1, r2, 24
	adds r0, r1
	cmp r0, 0x1D
	ble _080171DC
	movs r0, 0x1D
	subs r0, r1
	cmp r0, 0
	bge _080171D0
	movs r0, 0
_080171D0:
	lsls r1, r0, 24
	lsrs r1, 16
	ldr r0, =0xffff00ff
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_080171DC:
	mov r0, sp
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldr r0, =gMultiuseListMenuTemplate
	adds r2, r0, 0
	ldr r1, [sp, 0x24]
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldrb r1, [r5]
	strb r1, [r0, 0x10]
	movs r1, 0
	movs r2, 0
	bl ListMenuInit
	mov r1, r9
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _0801728E
	.pool
_08017228:
	mov r3, r9
	ldrb r0, [r3]
	bl ListMenuHandleInputGetItemId
	mov r8, r0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	ands r4, r1
	cmp r4, 0
	beq _08017264
	mov r4, r9
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r5]
	bl RemoveWindow
	movs r0, 0
	strb r0, [r7]
	mov r0, r8
	b _08017292
	.pool
_08017264:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801728E
	mov r6, r9
	ldrb r0, [r6]
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r5]
	bl RemoveWindow
	strb r4, [r7]
	movs r0, 0x2
	negs r0, r0
	b _08017292
_0801728E:
	movs r0, 0x1
	negs r0, r0
_08017292:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8017178

	thumb_func_start sub_80172A0
sub_80172A0: @ 80172A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r10, r2
	mov r9, r3
	ldrb r4, [r5]
	cmp r4, 0x1
	beq _0801730C
	cmp r4, 0x1
	bgt _080172C2
	cmp r4, 0
	beq _080172C8
	b _0801739C
_080172C2:
	cmp r4, 0x2
	beq _0801731C
	b _0801739C
_080172C8:
	ldr r0, =gUnknown_082F0344
	bl sub_8017118
	mov r1, r9
	strb r0, [r1]
	ldr r0, [sp, 0x20]
	bl AddWindow
	strb r0, [r6]
	ldrb r0, [r6]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldr r0, =gMultiuseListMenuTemplate
	adds r2, r0, 0
	ldr r1, [sp, 0x24]
	ldm r1!, {r3,r4,r7}
	stm r2!, {r3,r4,r7}
	ldm r1!, {r3,r4,r7}
	stm r2!, {r3,r4,r7}
	ldrb r1, [r6]
	strb r1, [r0, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl ListMenuInit
	mov r1, r10
	strb r0, [r1]
	b _08017314
	.pool
_0801730C:
	ldrb r0, [r6]
	movs r1, 0x1
	bl CopyWindowToVram
_08017314:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0801739C
_0801731C:
	mov r3, r10
	ldrb r0, [r3]
	bl ListMenuHandleInputGetItemId
	adds r1, r0, 0
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0
	beq _0801739C
	cmp r1, 0x8
	beq _0801733E
	ands r4, r2
	mov r8, r4
	cmp r4, 0
	beq _08017368
_0801733E:
	mov r4, r10
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldrb r0, [r6]
	bl RemoveWindow
	mov r7, r9
	ldrb r0, [r7]
	bl sub_8017168
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x2
	negs r0, r0
	b _080173A0
	.pool
_08017368:
	ldr r0, [sp, 0x28]
	bl sub_8017CB0
	adds r4, r0, 0
	cmp r4, 0
	blt _08017396
	mov r1, r10
	ldrb r0, [r1]
	movs r1, 0
	movs r2, 0
	bl DestroyListMenuTask
	ldrb r0, [r6]
	bl RemoveWindow
	mov r3, r9
	ldrb r0, [r3]
	bl sub_8017168
	mov r7, r8
	strb r7, [r5]
	adds r0, r4, 0
	b _080173A0
_08017396:
	movs r0, 0x7
	bl PlaySE
_0801739C:
	movs r0, 0x1
	negs r0, r0
_080173A0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80172A0

	thumb_func_start sub_80173B0
sub_80173B0: @ 80173B0
	push {lr}
	sub sp, 0xC
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_80173B0

	thumb_func_start sub_80173D4
sub_80173D4: @ 80173D4
	push {lr}
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_80173D4

	thumb_func_start sub_80173E0
sub_80173E0: @ 80173E0
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	str r2, [sp]
	mov r2, sp
	strb r0, [r2, 0x4]
	mov r0, sp
	strb r1, [r0, 0x5]
	strb r3, [r0, 0x6]
	strb r5, [r0, 0x7]
	strb r3, [r0, 0x8]
	strb r5, [r0, 0x9]
	ldrb r1, [r2, 0xC]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xC]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	cmp r4, 0x6
	bls _08017422
	b _0801756E
_08017422:
	lsls r0, r4, 2
	ldr r1, =_08017434
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08017434:
	.4byte _08017450
	.4byte _0801747C
	.4byte _080174A8
	.4byte _080174D4
	.4byte _08017500
	.4byte _0801752C
	.4byte _08017544
_08017450:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldrb r1, [r2, 0xD]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0xD]
	ands r0, r3
	movs r1, 0x30
	b _0801756A
_0801747C:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldrb r1, [r2, 0xD]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0xD]
	ands r0, r3
	movs r1, 0x50
	b _0801756A
_080174A8:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x60
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldrb r1, [r2, 0xD]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0xD]
	ands r0, r3
	movs r1, 0x70
	b _0801756A
_080174D4:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldrb r1, [r2, 0xD]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0xD]
	ands r0, r3
	movs r1, 0x30
	b _0801756A
_08017500:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldrb r1, [r2, 0xD]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xD]
	ands r0, r3
	movs r1, 0x30
	b _0801756A
_0801752C:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r4, 0xF
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x70
	b _0801755A
_08017544:
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r4, 0xF
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0xE0
_0801755A:
	orrs r0, r1
	strb r0, [r2, 0xC]
	mov r1, sp
	ldrb r0, [r1, 0xD]
	orrs r0, r4
	strb r0, [r1, 0xD]
	ands r0, r3
	movs r1, 0x90
_0801756A:
	orrs r0, r1
	strb r0, [r2, 0xD]
_0801756E:
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80173E0

	thumb_func_start sub_8017580
sub_8017580: @ 8017580
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	beq _080175D8
	ldr r2, =gUnknown_082F045C
	mov r8, r2
	movs r5, 0
	mov r9, r5
	movs r6, 0x4
	negs r6, r6
	mov r12, r6
	adds r2, r0, 0
	adds r2, 0x18
	adds r4, r0, 0
	movs r7, 0xFF
	mov r10, r7
	adds r3, r1, 0
_080175AC:
	adds r1, r4, 0
	mov r0, r8
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	mov r0, r10
	strh r0, [r2]
	ldrb r1, [r2, 0x2]
	mov r0, r12
	ands r0, r1
	movs r1, 0x5
	negs r1, r1
	ands r0, r1
	strb r0, [r2, 0x2]
	mov r5, r9
	strb r5, [r2, 0x3]
	adds r2, 0x20
	adds r4, 0x20
	subs r3, 0x1
	cmp r3, 0
	bne _080175AC
_080175D8:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8017580

	thumb_func_start sub_80175EC
sub_80175EC: @ 80175EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, =gUnknown_082F045C
	mov r12, r1
	movs r5, 0x2
	negs r5, r5
	mov r8, r5
	adds r2, r0, 0
	adds r2, 0x18
	adds r3, r0, 0
	movs r4, 0x3
_08017604:
	adds r1, r3, 0
	mov r0, r12
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldrb r1, [r2]
	mov r0, r8
	ands r0, r1
	strb r0, [r2]
	adds r2, 0x1C
	adds r3, 0x1C
	subs r4, 0x1
	cmp r4, 0
	bge _08017604
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80175EC

	thumb_func_start sub_8017630
sub_8017630: @ 8017630
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r2, 0
	adds r4, r5, 0x2
	adds r3, r6, 0x2
_0801763C:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08017664
	adds r2, 0x1
	cmp r2, 0x1
	ble _0801763C
	movs r2, 0
	adds r4, r5, 0
	adds r4, 0x10
	adds r3, r6, 0
	adds r3, 0x10
_08017658:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08017668
_08017664:
	movs r0, 0x1
	b _08017670
_08017668:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08017658
	movs r0, 0
_08017670:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8017630

	thumb_func_start sub_8017678
sub_8017678: @ 8017678
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r3, [r5, 0xA]
	movs r0, 0x7F
	ldrb r2, [r6, 0xA]
	adds r1, r0, 0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080176DC
	movs r0, 0x80
	adds r1, r0, 0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080176DC
	movs r2, 0
	adds r4, r5, 0x4
	adds r3, r6, 0x4
_080176A0:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080176DC
	adds r2, 0x1
	cmp r2, 0x3
	ble _080176A0
	ldrh r2, [r5, 0x8]
	ldr r0, =0x000003ff
	ldrh r3, [r6, 0x8]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _080176DC
	ldrb r2, [r5, 0x9]
	movs r0, 0xFC
	ldrb r3, [r6, 0x9]
	adds r1, r0, 0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _080176DC
	movs r0, 0
	b _080176DE
	.pool
_080176DC:
	movs r0, 0x1
_080176DE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8017678

	thumb_func_start sub_80176E4
sub_80176E4: @ 80176E4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, 0xFF
	movs r6, 0
	adds r4, r1, 0
	adds r4, 0x18
	adds r5, r1, 0
_080176F6:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801771E
	mov r0, r8
	adds r1, r5, 0
	bl sub_8017630
	lsls r0, 24
	cmp r0, 0
	bne _0801771E
	lsls r0, r6, 24
	lsrs r7, r0, 24
	ldrb r0, [r4]
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r4]
_0801771E:
	adds r4, 0x1C
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _080176F6
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80176E4

	thumb_func_start sub_8017734
sub_8017734: @ 8017734
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r3, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r6, r2, 24
	ldrb r1, [r1, 0x18]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080177A8
	movs r5, 0
	cmp r5, r6
	bge _080177A8
	movs r0, 0x4
	negs r0, r0
	mov r9, r0
	movs r1, 0x2
	negs r1, r1
	mov r12, r1
	adds r2, r3, 0
	adds r2, 0x18
	adds r1, r3, 0
_08017766:
	ldrb r0, [r2, 0x2]
	movs r3, 0x3
	ands r3, r0
	cmp r3, 0
	bne _0801779E
	mov r0, r8
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	strh r3, [r2]
	ldrb r1, [r2, 0x2]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	movs r0, 0x40
	strb r0, [r2, 0x3]
	mov r0, r8
	ldrb r1, [r0, 0x18]
	mov r0, r12
	ands r0, r1
	mov r1, r8
	strb r0, [r1, 0x18]
	lsls r0, r5, 24
	lsrs r0, 24
	b _080177AA
_0801779E:
	adds r2, 0x20
	adds r1, 0x20
	adds r5, 0x1
	cmp r5, r6
	blt _08017766
_080177A8:
	movs r0, 0xFF
_080177AA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8017734

	thumb_func_start sub_80177B8
sub_80177B8: @ 80177B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r4, r1, 0
	adds r6, r3, 0
	ldr r3, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r1, 24
	lsrs r1, 24
	ldr r5, =gStringVar4
	adds r1, 0x1
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_Colon
	adds r0, r5, 0
	bl StringAppend
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0x1
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80173E0
	adds r4, 0x12
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6, 0xA]
	lsls r0, 25
	lsrs r2, r0, 25
	ldrb r1, [r6, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _08017884
	movs r0, 0x40
	ands r2, r0
	cmp r2, 0
	bne _08017884
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8018404
	str r7, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0x1
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80173E0
	ldrb r1, [r6, 0x2]
	ldrb r0, [r6, 0x3]
	lsls r0, 8
	orrs r1, r0
	add r0, sp, 0x8
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_UnkCtrlCodeF907
	adds r0, r5, 0
	bl StringCopy
	adds r0, r5, 0
	add r1, sp, 0x8
	bl StringAppend
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x88
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	str r7, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0x1
	adds r2, r5, 0
	bl sub_80173E0
_08017884:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80177B8

	thumb_func_start sub_80178A0
sub_80178A0: @ 80178A0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r5, r3, 0
	ldr r3, [sp, 0x2C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r7, r3, 24
	ldrb r1, [r5, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801792A
	ldr r4, =gStringVar4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8018404
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r0, r9
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_80173E0
	ldrb r1, [r5, 0x2]
	ldrb r0, [r5, 0x3]
	lsls r0, 8
	orrs r1, r0
	add r0, sp, 0x8
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_UnkCtrlCodeF907
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	add r1, sp, 0x8
	bl StringAppend
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x68
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r0, r9
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80173E0
_0801792A:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80178A0

	thumb_func_start sub_8017940
sub_8017940: @ 8017940
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bne _08017978
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bne _08017978
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x3]
	cmp r0, 0x2
	beq _0801796E
	cmp r0, 0
	bne _08017978
_0801796E:
	movs r0, 0x1
	b _0801797A
	.pool
_08017978:
	movs r0, 0
_0801797A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8017940

	thumb_func_start sub_8017984
sub_8017984: @ 8017984
	push {lr}
	cmp r0, 0x4
	beq _0801799C
	cmp r0, 0x4
	ble _080179A4
	cmp r0, 0x5
	beq _08017998
	cmp r0, 0x8
	beq _080179A0
	b _080179A4
_08017998:
	movs r0, 0x1
	b _080179A6
_0801799C:
	movs r0, 0x2
	b _080179A6
_080179A0:
	movs r0, 0x3
	b _080179A6
_080179A4:
	movs r0, 0
_080179A6:
	pop {r1}
	bx r1
	thumb_func_end sub_8017984

	thumb_func_start sub_80179AC
sub_80179AC: @ 80179AC
	push {r4,lr}
	sub sp, 0x20
	adds r4, r0, 0
	mov r0, sp
	adds r1, r4, 0
	bl sub_8018404
	adds r4, 0x2
	adds r0, r4, 0
	bl ReadAsU16
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	bl sub_800E540
	add sp, 0x20
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80179AC

	thumb_func_start sub_80179D4
sub_80179D4: @ 80179D4
	push {r4-r6,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r2, 19
	adds r5, r0, r2
	ldrb r1, [r5, 0xA]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08017A4C
	cmp r4, 0
	bne _08017A4C
	ldr r4, =gStringVar1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8018404
	adds r0, r5, 0x2
	bl ReadAsU16
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl sub_800E540
	adds r2, r0, 0
	ldrb r1, [r5, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	bne _08017A38
	ldr r0, =gStringVar4
	ldr r3, =gUnknown_082EE6B8
	lsls r1, r6, 2
	lsls r2, 3
	adds r1, r2
	adds r1, r3
	ldr r1, [r1]
	bl StringExpandPlaceholders
	movs r0, 0x2
	b _08017B2A
	.pool
_08017A38:
	ldr r0, =gUnknown_082EE17C
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	bl sub_8017020
	movs r0, 0x1
	b _08017B2A
	.pool
_08017A4C:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	bl sub_8018404
	cmp r4, 0
	beq _08017A62
	adds r0, r5, r4
	ldrb r0, [r0, 0x3]
	lsrs r6, r0, 3
	movs r0, 0x1
	ands r6, r0
_08017A62:
	ldrb r0, [r5, 0xA]
	lsls r0, 25
	lsrs r0, 25
	movs r1, 0x3F
	ands r1, r0
	cmp r1, 0x4
	beq _08017AB0
	cmp r1, 0x4
	bgt _08017A80
	cmp r1, 0x1
	beq _08017A8A
	b _08017B20
	.pool
_08017A80:
	cmp r1, 0x5
	beq _08017AD0
	cmp r1, 0x8
	beq _08017AF4
	b _08017B20
_08017A8A:
	ldr r5, =gStringVar4
	ldr r4, =gUnknown_082EEEAC
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 14
	lsls r0, r6, 4
	adds r1, r0
	adds r1, r4
	ldr r1, [r1]
	b _08017B0E
	.pool
_08017AB0:
	ldr r5, =gStringVar4
	ldr r4, =gUnknown_082EF1CC
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	lsls r1, r6, 4
	b _08017B08
	.pool
_08017AD0:
	ldr r5, =gStringVar4
	ldr r4, =gUnknown_082EF010
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 14
	lsls r0, r6, 4
	adds r1, r0
	adds r1, r4
	ldr r1, [r1]
	b _08017B0E
	.pool
_08017AF4:
	ldr r5, =gStringVar4
	ldr r4, =gUnknown_082EF100
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	lsls r1, r6, 3
_08017B08:
	adds r0, r1
	adds r0, r4
	ldr r1, [r0]
_08017B0E:
	adds r0, r5, 0
	bl StringExpandPlaceholders
	b _08017B28
	.pool
_08017B20:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082EE6C8
	bl StringExpandPlaceholders
_08017B28:
	movs r0, 0
_08017B2A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80179D4

	thumb_func_start nullsub_14
nullsub_14: @ 8017B38
	bx lr
	thumb_func_end nullsub_14

	thumb_func_start sub_8017B3C
sub_8017B3C: @ 8017B3C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r4, [sp, 0x28]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r4, 24
	lsrs r4, 24
	ldrh r0, [r2, 0x8]
	lsls r0, 22
	lsrs r0, 22
	mov r8, r0
	ldrb r0, [r2, 0x9]
	lsrs r7, r0, 2
	ldrb r0, [r2, 0xB]
	lsrs r0, 1
	mov r9, r0
	str r5, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r3, 0
	movs r3, 0x8
	bl sub_80173E0
	movs r0, 0xCE
	lsls r0, 1
	cmp r8, r0
	bne _08017B94
	ldr r2, =gUnknown_082EF7D0
	str r5, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0x1
	movs r3, 0x44
	bl sub_80173E0
	b _08017BD4
	.pool
_08017B94:
	adds r1, r7, 0x1
	adds r0, r6, 0
	movs r2, 0x44
	adds r3, r5, 0
	bl blit_move_info_icon
	movs r0, 0xB
	mov r2, r8
	muls r2, r0
	ldr r0, =gSpeciesNames
	adds r2, r0
	str r5, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0x1
	movs r3, 0x76
	bl sub_80173E0
	add r0, sp, 0x8
	mov r1, r9
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	str r5, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0x1
	add r2, sp, 0x8
	movs r3, 0xC6
	bl sub_80173E0
_08017BD4:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8017B3C

	thumb_func_start sub_8017BE8
sub_8017BE8: @ 8017BE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r0, =gUnknown_02022C30
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0x3
	negs r0, r0
	cmp r4, r0
	bne _08017C6C
	ldr r0, =gUnknown_082F03A4
	ldrb r0, [r0, 0x14]
	lsls r0, 28
	lsrs r0, 28
	cmp r7, r0
	bne _08017C6C
	bl sub_800F7DC
	adds r2, r0, 0
	ldrh r1, [r2, 0x8]
	ldr r0, =0x000003ff
	ands r0, r1
	cmp r0, 0
	beq _08017CA0
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	movs r0, 0x5
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	bl sub_8017B3C
	b _08017CA0
	.pool
_08017C4C:
	mov r0, r12
	adds r1, r0, r4
	add r0, sp, 0x4
	bl sub_8018404
	mov r0, r8
	ldr r2, [r0]
	adds r2, r4
	movs r0, 0x6
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	add r3, sp, 0x4
	bl sub_8017B3C
	b _08017CA0
_08017C6C:
	movs r5, 0
	movs r1, 0
	mov r2, r8
	ldr r2, [r2]
	mov r12, r2
	adds r2, 0x8
	movs r3, 0
	adds r6, r4, 0x1
_08017C7C:
	ldrb r0, [r2, 0x12]
	lsls r0, 30
	lsrs r0, 30
	adds r4, r3, 0
	cmp r0, 0x1
	bne _08017C92
	ldrh r0, [r2]
	lsls r0, 22
	cmp r0, 0
	beq _08017C92
	adds r5, 0x1
_08017C92:
	cmp r5, r6
	beq _08017C4C
	adds r2, 0x20
	adds r3, 0x20
	adds r1, 0x1
	cmp r1, 0x7
	ble _08017C7C
_08017CA0:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8017BE8

	thumb_func_start sub_8017CB0
sub_8017CB0: @ 8017CB0
	push {r4-r7,lr}
	movs r4, 0
	movs r3, 0
	movs r7, 0x3
	ldr r6, =0x000003ff
	adds r2, r0, 0
	adds r2, 0x8
	adds r5, r1, 0x1
_08017CC0:
	ldrb r1, [r2, 0x12]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x1
	bne _08017CD6
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08017CD6
	adds r4, 0x1
_08017CD6:
	cmp r4, r5
	bne _08017CE4
	adds r0, r3, 0
	b _08017CF0
	.pool
_08017CE4:
	adds r2, 0x20
	adds r3, 0x1
	cmp r3, 0x7
	ble _08017CC0
	movs r0, 0x1
	negs r0, r0
_08017CF0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8017CB0

	thumb_func_start sub_8017CF8
sub_8017CF8: @ 8017CF8
	lsls r0, 5
	adds r0, r1
	ldrb r0, [r0, 0xB]
	lsls r0, 31
	lsrs r0, 31
	bx lr
	thumb_func_end sub_8017CF8

	thumb_func_start sub_8017D04
sub_8017D04: @ 8017D04
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _08017D44
	movs r4, 0
	b _08017D2E
_08017D14:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _08017D74
	adds r4, 0x1
_08017D2E:
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r4, r0
	blt _08017D14
	movs r0, 0x2
	b _08017D90
	.pool
_08017D44:
	movs r4, 0
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r4, r0
	bge _08017D8E
	ldr r6, =gBaseStats
_08017D50:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	bl GetMonData
	adds r1, r0, 0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r6
	ldrb r0, [r1, 0x6]
	cmp r0, r5
	beq _08017D74
	ldrb r0, [r1, 0x7]
	cmp r0, r5
	bne _08017D84
_08017D74:
	movs r0, 0
	b _08017D90
	.pool
_08017D84:
	adds r4, 0x1
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r4, r0
	blt _08017D50
_08017D8E:
	movs r0, 0x1
_08017D90:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8017D04

	thumb_func_start sub_8017D9C
sub_8017D9C: @ 8017D9C
	push {lr}
	adds r3, r0, 0
	cmp r1, 0x44
	beq _08017DD8
	cmp r1, 0x44
	bgt _08017DAE
	cmp r1, 0x41
	beq _08017DB8
	b _08017DF6
_08017DAE:
	cmp r1, 0x45
	beq _08017DC8
	cmp r1, 0x48
	beq _08017DE8
	b _08017DF6
_08017DB8:
	ldr r0, =gUnknown_082EEA68
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	b _08017DDA
	.pool
_08017DC8:
	ldr r0, =gUnknown_082EED3C
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	b _08017DDA
	.pool
_08017DD8:
	ldr r1, =gUnknown_082EF7B0
_08017DDA:
	adds r0, r3, 0
	bl StringExpandPlaceholders
	b _08017DF6
	.pool
_08017DE8:
	ldr r0, =gUnknown_082EEB08
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r3, 0
	bl StringExpandPlaceholders
_08017DF6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8017D9C

	thumb_func_start sub_8017E00
sub_8017E00: @ 8017E00
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	adds r6, r4, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gLinkPlayers
	movs r0, 0x1
	adds r1, r3, 0
	eors r1, r0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	cmp r4, 0x44
	beq _08017E54
	cmp r4, 0x44
	bgt _08017E38
	cmp r4, 0x41
	beq _08017E3E
	b _08017E94
	.pool
_08017E38:
	cmp r6, 0x45
	beq _08017E78
	b _08017E94
_08017E3E:
	ldr r2, =gUnknown_082EE984
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r0
	b _08017E66
	.pool
_08017E54:
	ldr r2, =gUnknown_082EE984
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r0
	adds r2, 0x8
_08017E66:
	adds r1, r2
	ldr r1, [r1]
	adds r0, r5, 0
	bl StringCopy
	b _08017E94
	.pool
_08017E78:
	ldr r2, =gUnknown_082EE984
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r0
	adds r2, 0x4
	adds r1, r2
	ldr r1, [r1]
	adds r0, r5, 0
	bl StringCopy
_08017E94:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8017E00

	thumb_func_start sub_8017EA0
sub_8017EA0: @ 8017EA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	movs r2, 0
	mov r8, r2
	ldrh r0, [r5]
	subs r0, 0x40
	cmp r0, 0x8
	bls _08017EBA
	b _08017FC6
_08017EBA:
	lsls r0, 2
	ldr r1, =_08017EC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08017EC8:
	.4byte _08017FBC
	.4byte _08017EEC
	.4byte _08017FC6
	.4byte _08017FC6
	.4byte _08017EFC
	.4byte _08017EF4
	.4byte _08017FC6
	.4byte _08017FC6
	.4byte _08017FAC
_08017EEC:
	ldr r1, =gUnknown_082EE3DC
	b _08017FAE
	.pool
_08017EF4:
	ldr r1, =gUnknown_082EE430
	b _08017FAE
	.pool
_08017EFC:
	adds r0, r6, 0
	adds r0, 0x58
	ldr r4, =gUnknown_02022C40
	ldrh r1, [r4, 0xC]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	adds r0, 0x68
	ldrh r2, [r4, 0xA]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	movs r4, 0
	b _08017F2E
	.pool
_08017F2C:
	adds r4, 0x1
_08017F2E:
	cmp r4, 0x3
	bgt _08017F64
	ldr r0, =gUnknown_03007890
	ldr r0, [r0]
	lsls r1, r4, 5
	adds r0, r1
	ldrh r0, [r0, 0x18]
	cmp r0, 0x2
	bne _08017F2C
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	adds r0, 0x78
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldrh r1, [r5, 0x2]
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r6, 0
	adds r0, 0x88
	bl StringCopy
	ldrh r5, [r5, 0x2]
	mov r8, r5
_08017F64:
	movs r0, 0xCE
	lsls r0, 1
	cmp r8, r0
	bne _08017F84
	ldr r1, =gUnknown_082EE4F0
	adds r0, r7, 0
	bl StringCopy
	b _08017FB4
	.pool
_08017F84:
	movs r4, 0
	adds r5, r6, 0
	adds r5, 0x58
_08017F8A:
	lsls r0, r4, 24
	lsrs r0, 24
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	adds r5, 0x10
	adds r4, 0x1
	cmp r4, 0x3
	ble _08017F8A
	ldr r1, =gUnknown_082EE47C
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08017FB4
	.pool
_08017FAC:
	ldr r1, =gUnknown_082EE380
_08017FAE:
	adds r0, r7, 0
	bl StringExpandPlaceholders
_08017FB4:
	movs r2, 0x1
	b _08017FC6
	.pool
_08017FBC:
	ldr r1, =gUnknown_082EE544
	adds r0, r7, 0
	bl StringExpandPlaceholders
	movs r2, 0x2
_08017FC6:
	adds r0, r2, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8017EA0

	thumb_func_start sub_8017FD8
sub_8017FD8: @ 8017FD8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gRecvCmds
	ldrh r1, [r0, 0x2]
	cmp r1, 0
	beq _08017FFC
	cmp r1, 0x51
	beq _08017FEC
	cmp r1, 0x52
	bne _08017FFC
_08017FEC:
	adds r0, r2, 0
	adds r0, 0x98
	strh r1, [r0]
	movs r0, 0x1
	b _08017FFE
	.pool
_08017FFC:
	movs r0, 0
_08017FFE:
	pop {r1}
	bx r1
	thumb_func_end sub_8017FD8

	thumb_func_start InUnionRoom
InUnionRoom: @ 8018004
	push {lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x00003c19
	cmp r1, r0
	bne _08018016
	movs r2, 0x1
_08018016:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end InUnionRoom

	thumb_func_start sub_8018024
sub_8018024: @ 8018024
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r6, r0
	bge _08018064
_08018032:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x1E
	bhi _0801805A
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _0801805A
	adds r6, 0x1
_0801805A:
	adds r5, 0x1
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	blt _08018032
_08018064:
	cmp r6, 0x1
	bgt _08018074
	movs r0, 0
	b _08018076
	.pool
_08018074:
	movs r0, 0x1
_08018076:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8018024

	thumb_func_start sub_801807C
sub_801807C: @ 801807C
	movs r1, 0
	strh r1, [r0]
	strh r1, [r0, 0x2]
	str r1, [r0, 0x4]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	str r1, [r0, 0x14]
	bx lr
	thumb_func_end sub_801807C

	thumb_func_start sub_8018090
sub_8018090: @ 8018090
	push {lr}
	ldr r0, =gUnknown_02022C40
	bl sub_801807C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8018090

	thumb_func_start sub_80180A0
sub_80180A0: @ 80180A0
	push {r4,r5,lr}
	adds r5, r1, 0
	movs r1, 0x64
	adds r4, r0, 0
	muls r4, r1
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	strh r0, [r5, 0xA]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	strh r0, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _080180E0
	movs r0, 0
	b _080180E2
	.pool
_080180E0:
	movs r0, 0x1
_080180E2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80180A0

	thumb_func_start sub_80180E8
sub_80180E8: @ 80180E8
	push {r4,r5,lr}
	adds r5, r1, 0
	movs r1, 0x64
	adds r4, r0, 0
	muls r4, r1
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	strh r0, [r5, 0xE]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	strh r0, [r5, 0x10]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r5, 0x14]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80180E8

	thumb_func_start sub_8018120
sub_8018120: @ 8018120
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r1, 24
	movs r2, 0
	mov r8, r2
	cmp r1, 0
	bne _0801813E
	ldrh r7, [r0, 0xA]
	ldr r6, [r0, 0x4]
	b _08018142
_08018136:
	lsls r0, r5, 16
	lsrs r0, 16
	mov r8, r0
	b _08018176
_0801813E:
	ldrh r7, [r0, 0xE]
	ldr r6, [r0, 0x14]
_08018142:
	movs r5, 0
	b _0801816E
_08018146:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	cmp r0, r6
	bne _0801816C
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r7
	beq _08018136
_0801816C:
	adds r5, 0x1
_0801816E:
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	blt _08018146
_08018176:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8018120

	thumb_func_start sub_801818C
sub_801818C: @ 801818C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80173B0
	bl ScriptContext2_Disable
	bl sub_8098524
	ldr r1, =gUnknown_02022C2C
	movs r0, 0
	strb r0, [r1]
	cmp r4, 0
	beq _080181BC
	ldr r2, =gUnknown_02022C40
	ldrh r0, [r2, 0x2]
	ldrh r1, [r2, 0xA]
	ldrh r2, [r2, 0xC]
	bl sub_8010FCC
	movs r0, 0x40
	movs r1, 0
	movs r2, 0
	bl sub_8011090
_080181BC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801818C

	thumb_func_start sub_80181CC
sub_80181CC: @ 80181CC
	push {lr}
	bl ScriptContext2_Enable
	bl ScriptFreezeEventObjects
	pop {r0}
	bx r0
	thumb_func_end sub_80181CC

	thumb_func_start sub_80181DC
sub_80181DC: @ 80181DC
	push {r4,lr}
	movs r3, 0x80
	movs r2, 0
	ldr r4, [r0, 0xC]
_080181E4:
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x18]
	lsls r0, 31
	cmp r0, 0
	beq _0801820C
	ldrb r0, [r1, 0xB]
	lsls r0, 31
	lsrs r0, 31
	lsls r0, 3
	orrs r3, r0
	ldrb r1, [r1, 0x2]
	movs r0, 0x7
	ands r0, r1
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	b _08018216
_0801820C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080181E4
_08018216:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80181DC

	thumb_func_start sub_8018220
sub_8018220: @ 8018220
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	bl GetMultiplayerId
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gTrainerCards
	adds r1, r0
	mov r8, r1
	bl DynamicPlaceholderTextUtil_Reset
	mov r6, r9
	adds r6, 0xC0
	bl sub_8068BB0
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gTrainerClassNames
	adds r1, r0
	adds r0, r6, 0
	bl StringCopy
	movs r0, 0
	adds r1, r6, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r1, r8
	adds r1, 0x30
	movs r0, 0x1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r4, 0xBA
	lsls r4, 1
	add r4, r9
	ldr r1, =gUnknown_082EFF50
	mov r2, r8
	ldrb r0, [r2, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0x2
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r5, r9
	adds r5, 0xDE
	mov r0, r8
	ldrh r1, [r0, 0xC]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x3
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, 0xED
	add r2, r9
	mov r10, r2
	mov r0, r8
	ldrh r1, [r0, 0x10]
	mov r0, r10
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r4, r9
	adds r4, 0xFC
	mov r2, r8
	ldrh r1, [r2, 0x12]
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	mov r1, r10
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x5
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r4, 0xD2
	lsls r4, 1
	add r4, r9
	ldr r1, =gUnknown_082EFF64
	adds r0, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl StringCopy
	mov r0, r8
	ldrh r1, [r0, 0x14]
	ldr r4, =0x0000270f
	cmp r1, r4
	ble _0801830C
	adds r1, r4, 0
_0801830C:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	movs r0, 0
	adds r1, r6, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r2, r8
	ldrh r1, [r2, 0x16]
	cmp r1, r4
	ble _08018328
	adds r1, r4, 0
_08018328:
	mov r4, r9
	adds r4, 0xCF
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	movs r0, 0x2
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r0, r8
	ldrh r1, [r0, 0x20]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	movs r0, 0x3
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r7, 0
	movs r6, 0x80
	lsls r6, 19
	mov r5, r8
	adds r5, 0x28
	mov r4, r10
_08018360:
	ldrh r1, [r5]
	adds r0, r4, 0
	bl CopyEasyChatWord
	lsrs r0, r6, 24
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, 0x80
	lsls r2, 17
	adds r6, r2
	adds r5, 0x2
	adds r4, 0xF
	adds r7, 0x1
	cmp r7, 0x3
	ble _08018360
	movs r4, 0xD2
	lsls r4, 1
	add r4, r9
	ldr r1, =gUnknown_082EFFA4
	adds r0, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r5, =gStringVar4
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringAppend
	ldr r0, [sp]
	cmp r0, 0x1
	bne _080183D0
	ldr r1, =gUnknown_082F0020
	adds r0, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringAppend
	b _080183F0
	.pool
_080183D0:
	ldr r2, [sp]
	cmp r2, 0
	bne _080183F0
	ldr r0, =gUnknown_082F0018
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, 0
	adds r1, r4, 0
	bl StringAppend
_080183F0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8018220

	thumb_func_start sub_8018404
sub_8018404: @ 8018404
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, 0x10
	bl StringCopy7
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r5, 0
	bl ConvertInternationalString
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8018404

	thumb_func_start sub_8018424
sub_8018424: @ 8018424
	push {lr}
	bl ProcessSpriteCopyRequests
	bl LoadOam
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8018424

	thumb_func_start sub_8018438
sub_8018438: @ 8018438
	push {lr}
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8018438

	thumb_func_start sub_8018450
sub_8018450: @ 8018450
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, 0x1
	bne _08018466
	b _08018574
_08018466:
	cmp r0, 0x1
	bgt _08018474
	cmp r0, 0
	beq _08018482
	b _08018644
	.pool
_08018474:
	cmp r0, 0x2
	bne _0801847A
	b _080185F8
_0801847A:
	cmp r0, 0x3
	bne _08018480
	b _08018618
_08018480:
	b _08018644
_08018482:
	movs r0, 0
	bl SetVBlankCallback
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl ScanlineEffect_Stop
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0598
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
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
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	movs r0, 0x3
	bl bgid_upload_textbox_1
	ldr r0, =gUnknown_082F05A8
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r1, 0xC0
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	b _08018610
	.pool
_08018574:
	ldr r0, =gUnkTextboxBorderPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x2
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xC0
	bl sub_81978B0
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xF0
	bl LoadUserWindowBorderGfx_
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r5, 0x11
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x3
	bl sub_8018798
	lsls r0, r7, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80186EC
	b _08018610
	.pool
_080185F8:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_08018610:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08018644
_08018618:
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r0, =0x0000021d
	bl PlayBGM
	ldr r0, =sub_8018424
	bl SetVBlankCallback
	movs r0, 0xC5
	bl EnableInterrupts
	movs r0, 0x1
	b _08018646
	.pool
_08018644:
	movs r0, 0
_08018646:
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8018450

	thumb_func_start c2_mystery_gift
c2_mystery_gift: @ 8018650
	push {lr}
	movs r0, 0
	bl sub_8018450
	cmp r0, 0
	beq _0801866C
	ldr r0, =sub_8018438
	bl SetMainCallback2
	ldr r1, =gUnknown_02022C60
	movs r0, 0
	strb r0, [r1]
	bl task_add_00_mystery_gift
_0801866C:
	bl RunTasks
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_mystery_gift

	thumb_func_start sub_801867C
sub_801867C: @ 801867C
	push {lr}
	movs r0, 0x1
	bl sub_8018450
	cmp r0, 0
	beq _08018698
	ldr r0, =sub_8018438
	bl SetMainCallback2
	ldr r1, =gUnknown_02022C60
	movs r0, 0x1
	strb r0, [r1]
	bl sub_81D5014
_08018698:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801867C

	thumb_func_start sub_80186A4
sub_80186A4: @ 80186A4
	push {lr}
	ldr r1, =gUnknown_02022C60
	movs r0, 0
	strb r0, [r1]
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x2
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x3
	bl GetBgTilemapBuffer
	bl Free
	ldr r0, =CB2_InitTitleScreen
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80186A4

	thumb_func_start sub_80186EC
sub_80186EC: @ 80186EC
	push {r4-r7,lr}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0
	bne _0801871C
	ldr r0, =gText_MysteryGift
	ldr r7, =gText_PickOKCancel
	cmp r5, 0
	bne _08018720
	ldr r7, =gText_PickOKExit
	b _08018720
	.pool
_0801871C:
	ldr r0, =gJPText_MysteryGift
	ldr r7, =gJPText_DecideStop
_08018720:
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r6, =gUnknown_082F0720
	str r6, [sp, 0x8]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0xC]
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	movs r0, 0
	adds r1, r7, 0
	movs r2, 0xDE
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	str r5, [sp, 0xC]
	str r7, [sp, 0x10]
	movs r0, 0
	movs r1, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl PutWindowTilemap
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80186EC

	thumb_func_start sub_8018784
sub_8018784: @ 8018784
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	movs r2, 0xF
	bl sub_8098858
	pop {r0}
	bx r0
	thumb_func_end sub_8018784

	thumb_func_start sub_8018798
sub_8018798: @ 8018798
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	mov r9, r0
	lsls r4, 24
	lsrs r0, r4, 24
	movs r1, 0x20
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r1, 0x11
	str r1, [sp, 0x8]
	movs r1, 0x3
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	mov r8, r4
	movs r4, 0x1
_080187C8:
	movs r7, 0
	mov r0, r9
	adds r0, 0x2
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	lsls r5, r0, 24
	movs r6, 0
_080187D8:
	mov r1, r9
	ands r1, r4
	adds r0, r7, 0
	ands r0, r4
	cmp r1, r0
	beq _080187FC
	lsrs r2, r6, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	mov r1, r8
	lsrs r0, r1, 24
	movs r1, 0x1
	lsrs r3, r5, 24
	bl FillBgTilemapBufferRect
	b _08018812
_080187FC:
	lsrs r2, r6, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	mov r1, r8
	lsrs r0, r1, 24
	movs r1, 0x2
	lsrs r3, r5, 24
	bl FillBgTilemapBufferRect
_08018812:
	movs r0, 0x80
	lsls r0, 17
	adds r6, r0
	adds r7, 0x1
	cmp r7, 0x1F
	ble _080187D8
	mov r9, r10
	mov r1, r9
	cmp r1, 0x11
	ble _080187C8
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8018798

	thumb_func_start sub_8018838
sub_8018838: @ 8018838
	push {lr}
	sub sp, 0xC
	cmp r0, 0
	beq _08018846
	cmp r0, 0x1
	beq _0801885E
	b _08018876
_08018846:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	b _08018876
_0801885E:
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x1E
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x2
	bl FillBgTilemapBufferRect
_08018876:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_8018838

	thumb_func_start sub_8018884
sub_8018884: @ 8018884
	push {r4,lr}
	sub sp, 0x14
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_082F0728
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0xF
	bl sub_8098858
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8018884

	thumb_func_start sub_80188DC
sub_80188DC: @ 80188DC
	push {lr}
	movs r0, 0x1
	bl rbox_fill_rectangle
	movs r0, 0x1
	bl ClearWindowTilemap
	movs r0, 0x1
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_80188DC

	thumb_func_start mevent_0814257C
mevent_0814257C: @ 80188F8
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r0, r1, 0
	ldrb r2, [r4]
	cmp r2, 0x1
	beq _08018920
	cmp r2, 0x1
	bgt _08018910
	cmp r2, 0
	beq _0801891A
	b _08018980
_08018910:
	cmp r2, 0x2
	beq _08018954
	cmp r2, 0xFF
	beq _0801897C
	b _08018980
_0801891A:
	bl sub_8018884
	b _08018944
_08018920:
	movs r0, 0
	str r0, [sp]
	ldr r0, =gUnknown_02022C58
	str r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD0
	movs r2, 0x14
	movs r3, 0x1
	bl DrawDownArrow
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08018980
_08018944:
	ldrb r0, [r4]
	adds r0, 0x1
	b _0801897E
	.pool
_08018954:
	movs r0, 0x1
	str r0, [sp]
	ldr r0, =gUnknown_02022C58
	str r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD0
	movs r2, 0x14
	movs r3, 0x1
	bl DrawDownArrow
	movs r0, 0
	strb r0, [r4]
	bl sub_80188DC
	movs r0, 0x1
	b _08018982
	.pool
_0801897C:
	movs r0, 0x2
_0801897E:
	strb r0, [r4]
_08018980:
	movs r0, 0
_08018982:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end mevent_0814257C

	thumb_func_start sub_801898C
sub_801898C: @ 801898C
	push {lr}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp]
	ldr r0, =gUnknown_02022C58
	str r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD0
	movs r2, 0x14
	movs r3, 0x1
	bl DrawDownArrow
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801898C

	thumb_func_start sub_80189B4
sub_80189B4: @ 80189B4
	push {lr}
	sub sp, 0xC
	movs r0, 0x1
	str r0, [sp]
	ldr r0, =gUnknown_02022C58
	str r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0xD0
	movs r2, 0x14
	movs r3, 0x1
	bl DrawDownArrow
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80189B4

	thumb_func_start sub_80189DC
sub_80189DC: @ 80189DC
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080189EC
	cmp r0, 0x1
	beq _08018A08
	b _08018A14
_080189EC:
	bl sub_801898C
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08018A14
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _08018A14
	.pool
_08018A08:
	bl sub_80189B4
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _08018A16
_08018A14:
	movs r0, 0
_08018A16:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80189DC

	thumb_func_start sub_8018A1C
sub_8018A1C: @ 8018A1C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	bne _08018A2C
	adds r0, r1, 0
	bl sub_8018884
_08018A2C:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x78
	bhi _08018A3E
	movs r0, 0
	b _08018A48
_08018A3E:
	movs r0, 0
	strb r0, [r4]
	bl sub_80188DC
	movs r0, 0x1
_08018A48:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8018A1C

	thumb_func_start sub_8018A50
sub_8018A50: @ 8018A50
	push {r4,r5,lr}
	sub sp, 0x24
	lsls r2, 24
	add r1, sp, 0x4
	ldr r0, =gUnknown_082F0638
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, =gUnknown_082F05E0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	str r1, [sp, 0x20]
	cmp r2, 0
	bne _08018A80
	ldr r0, =gUnknown_082F0608
	b _08018A82
	.pool
_08018A80:
	ldr r0, =gUnknown_082F0620
_08018A82:
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_81DB41C
	adds r3, r0, 0
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _08018A96
	adds r3, 0x1
_08018A96:
	lsls r1, r3, 24
	ldr r0, =0x00ffffff
	ldr r2, [sp, 0x1C]
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x1C]
	cmp r3, 0x1D
	bgt _08018ACC
	movs r0, 0x1E
	subs r0, r3
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 24
	lsrs r0, 16
	ldr r1, =0xffff00ff
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x1C]
	b _08018AD2
	.pool
_08018ACC:
	ldr r0, =0xffff00ff
	ands r2, r0
	str r2, [sp, 0x1C]
_08018AD2:
	add r0, sp, 0x1C
	movs r1, 0xE0
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x1
	movs r3, 0xA
	bl DoMysteryGiftListMenu
	adds r4, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _08018AFA
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x2
	movs r1, 0x1
	bl CopyWindowToVram
_08018AFA:
	adds r0, r4, 0
	add sp, 0x24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8018A50

	thumb_func_start sub_8018B08
sub_8018B08: @ 8018B08
	push {r4-r6,lr}
	sub sp, 0x1C
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, r3, 0
	lsls r2, 24
	lsrs r6, r2, 24
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _08018B98
	cmp r0, 0x1
	bgt _08018B26
	cmp r0, 0
	beq _08018B30
	b _08018C3E
_08018B26:
	cmp r0, 0x2
	beq _08018BE4
	cmp r0, 0xFF
	beq _08018C1A
	b _08018C3E
_08018B30:
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	cmp r6, 0
	bne _08018B48
	ldr r0, =gUnknown_082F05C8
	b _08018B4A
	.pool
_08018B48:
	ldr r0, =gUnknown_082F05D0
_08018B4A:
	bl AddWindow
	strh r0, [r4]
	ldrb r0, [r4]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r1, =gUnknown_082F0728
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r1, =gStringVar4
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	ldrb r0, [r4]
	movs r1, 0x1
	movs r2, 0xF
	bl sub_8098858
	ldrb r0, [r4]
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	bl PutWindowTilemap
	b _08018BD6
	.pool
_08018B98:
	ldr r0, =gUnknown_082F05E8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x14]
	str r1, [sp, 0x18]
	cmp r6, 0
	bne _08018BBC
	ldr r0, =0xff00ffff
	ldr r1, [sp, 0x14]
	ands r1, r0
	movs r0, 0x90
	lsls r0, 12
	b _08018BC6
	.pool
_08018BBC:
	ldr r0, =0xff00ffff
	ldr r1, [sp, 0x14]
	ands r1, r0
	movs r0, 0xF0
	lsls r0, 12
_08018BC6:
	orrs r1, r0
	str r1, [sp, 0x14]
	add r0, sp, 0x14
	movs r1, 0xA
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
_08018BD6:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _08018C3E
	.pool
_08018BE4:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r6, r0, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x2
	bhi _08018C3E
	movs r0, 0
	strb r0, [r5]
	ldrb r0, [r4]
	bl rbox_fill_rectangle
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r4]
	bl RemoveWindow
	adds r0, r6, 0
	b _08018C42
_08018C1A:
	movs r0, 0
	strb r0, [r5]
	ldrb r0, [r4]
	bl rbox_fill_rectangle
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	negs r0, r0
	b _08018C42
_08018C3E:
	movs r0, 0x2
	negs r0, r0
_08018C42:
	add sp, 0x1C
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8018B08

	thumb_func_start sub_8018C4C
sub_8018C4C: @ 8018C4C
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _08018CE8
	cmp r0, 0x1
	bgt _08018C64
	cmp r0, 0
	beq _08018C6C
	b _08018D8C
_08018C64:
	cmp r0, 0xFF
	bne _08018C6A
	b _08018D68
_08018C6A:
	b _08018D8C
_08018C6C:
	cmp r2, 0
	bne _08018C84
	ldr r0, =gStringVar4
	ldr r1, =gText_WhatToDoWithCards
	bl StringExpandPlaceholders
	b _08018C8C
	.pool
_08018C84:
	ldr r0, =gStringVar4
	ldr r1, =gText_WhatToDoWithNews
	bl StringExpandPlaceholders
_08018C8C:
	ldr r0, =gUnknown_082F05D8
	bl AddWindow
	strh r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r1, =gUnknown_082F0728
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r1, =gStringVar4
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	ldrb r0, [r5]
	movs r1, 0x1
	movs r2, 0xF
	bl sub_8098858
	ldrb r0, [r5]
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08018D8C
	.pool
_08018CE8:
	cmp r3, 0
	beq _08018D10
	cmp r2, 0
	bne _08018D00
	ldr r0, =gUnknown_082F05F8
	ldr r1, =gUnknown_082F06C8
	b _08018D28
	.pool
_08018D00:
	ldr r0, =gUnknown_082F0600
	ldr r1, =gUnknown_082F06F8
	b _08018D28
	.pool
_08018D10:
	cmp r2, 0
	bne _08018D24
	ldr r0, =gUnknown_082F05F0
	ldr r1, =gUnknown_082F06B0
	b _08018D28
	.pool
_08018D24:
	ldr r0, =gUnknown_082F05F8
	ldr r1, =gUnknown_082F06E0
_08018D28:
	movs r2, 0xE0
	str r2, [sp]
	movs r2, 0x1
	movs r3, 0xA
	bl DoMysteryGiftListMenu
	adds r4, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _08018D8C
	movs r0, 0
	strb r0, [r6]
	ldrb r0, [r5]
	bl rbox_fill_rectangle
	ldrb r0, [r5]
	bl ClearWindowTilemap
	ldrb r0, [r5]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r5]
	bl RemoveWindow
	adds r0, r4, 0
	b _08018D90
	.pool
_08018D68:
	movs r0, 0
	strb r0, [r6]
	ldrb r0, [r5]
	bl rbox_fill_rectangle
	ldrb r0, [r5]
	bl ClearWindowTilemap
	ldrb r0, [r5]
	movs r1, 0x1
	bl CopyWindowToVram
	ldrb r0, [r5]
	bl RemoveWindow
	movs r0, 0x2
	negs r0, r0
	b _08018D90
_08018D8C:
	movs r0, 0x1
	negs r0, r0
_08018D90:
	add sp, 0x14
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8018C4C

	thumb_func_start sub_8018D98
sub_8018D98: @ 8018D98
	push {lr}
	cmp r0, 0
	beq _08018DA4
	bl sub_801B0CC
	b _08018DA8
_08018DA4:
	bl sub_801B27C
_08018DA8:
	pop {r1}
	bx r1
	thumb_func_end sub_8018D98

	thumb_func_start sub_8018DAC
sub_8018DAC: @ 8018DAC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0
	beq _08018DBC
	cmp r0, 0x1
	beq _08018DE4
	b _08018E00
_08018DBC:
	cmp r1, 0
	bne _08018DD4
	bl sav1_get_mevent_buffer_1
	adds r4, r0, 0
	bl sav1_get_mevent_buffer_2
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_801BAAC
	b _08018DDC
_08018DD4:
	bl sub_801B00C
	bl sub_801C6C8
_08018DDC:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _08018E00
_08018DE4:
	cmp r1, 0
	bne _08018DF2
	bl sub_801BB74
_08018DEC:
	cmp r0, 0
	bne _08018DF8
	b _08018E00
_08018DF2:
	bl sub_801C758
	b _08018DEC
_08018DF8:
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	b _08018E02
_08018E00:
	movs r0, 0
_08018E02:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8018DAC

	thumb_func_start sub_8018E08
sub_8018E08: @ 8018E08
	push {lr}
	cmp r0, 0
	bne _08018E14
	bl sub_801B1E8
	b _08018E18
_08018E14:
	bl sub_801B06C
_08018E18:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8018E08

	thumb_func_start sub_8018E20
sub_8018E20: @ 8018E20
	push {lr}
	cmp r0, 0
	bne _08018E36
	adds r0, r1, 0
	bl sub_801BDA4
	cmp r0, 0
	beq _08018E40
	bl sub_801BB48
	b _08018E48
_08018E36:
	adds r0, r1, 0
	bl sub_801CA50
	cmp r0, 0
	bne _08018E44
_08018E40:
	movs r0, 0
	b _08018E4A
_08018E44:
	bl sub_801C72C
_08018E48:
	movs r0, 0x1
_08018E4A:
	pop {r1}
	bx r1
	thumb_func_end sub_8018E20

	thumb_func_start sub_8018E50
sub_8018E50: @ 8018E50
	push {lr}
	cmp r2, 0
	beq _08018E60
	ldr r3, =gText_OkayToDiscardNews
	b _08018E62
	.pool
_08018E60:
	ldr r3, =gText_IfThrowAwayCardEventWontHappen
_08018E62:
	movs r2, 0x1
	bl sub_8018B08
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8018E50

	thumb_func_start mevent_message_was_thrown_away
mevent_message_was_thrown_away: @ 8018E74
	push {lr}
	cmp r1, 0
	beq _08018E84
	ldr r1, =gText_WonderNewsThrownAway
	b _08018E86
	.pool
_08018E84:
	ldr r1, =gText_WonderCardThrownAway
_08018E86:
	bl mevent_0814257C
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_message_was_thrown_away

	thumb_func_start mevent_save_game
mevent_save_game: @ 8018E94
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x4
	bhi _08018F04
	lsls r0, 2
	ldr r1, =_08018EAC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08018EAC:
	.4byte _08018EC0
	.4byte _08018ECC
	.4byte _08018ED4
	.4byte _08018EE0
	.4byte _08018EF8
_08018EC0:
	ldr r0, =gText_DataWillBeSaved
	bl sub_8018884
	b _08018EEC
	.pool
_08018ECC:
	movs r0, 0
	bl TrySavingData
	b _08018EEC
_08018ED4:
	ldr r0, =gText_SaveCompletedPressA
	bl sub_8018884
	b _08018EEC
	.pool
_08018EE0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08018F04
_08018EEC:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _08018F04
	.pool
_08018EF8:
	movs r0, 0
	strb r0, [r4]
	bl sub_80188DC
	movs r0, 0x1
	b _08018F06
_08018F04:
	movs r0, 0
_08018F06:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end mevent_save_game

	thumb_func_start mevent_message
mevent_message: @ 8018F0C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r2, 0
	str r2, [r4]
	cmp r3, 0xE
	bls _08018F22
	b _08019034
_08018F22:
	lsls r0, r3, 2
	ldr r1, =_08018F30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08018F30:
	.4byte _08018F6C
	.4byte _08018F78
	.4byte _08018F84
	.4byte _08018F9C
	.4byte _08018FB4
	.4byte _08018FC0
	.4byte _08018FCC
	.4byte _08018FD8
	.4byte _08018FE4
	.4byte _08018FF0
	.4byte _08018FFC
	.4byte _08019014
	.4byte _08019020
	.4byte _0801902C
	.4byte _08019030
_08018F6C:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_NothingSentOver
	b _08019034
	.pool
_08018F78:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_RecordUploadedViaWireless
	b _08019034
	.pool
_08018F84:
	movs r0, 0x1
	str r0, [r4]
	ldr r2, =gText_WonderCardReceivedFrom
	cmp r5, 0
	bne _08019034
	ldr r2, =gText_WonderCardReceived
	b _08019034
	.pool
_08018F9C:
	movs r0, 0x1
	str r0, [r4]
	ldr r2, =gText_WonderNewsReceivedFrom
	cmp r5, 0
	bne _08019034
	ldr r2, =gText_WonderNewsReceived
	b _08019034
	.pool
_08018FB4:
	movs r0, 0x1
	str r0, [r4]
	ldr r2, =gText_NewStampReceived
	b _08019034
	.pool
_08018FC0:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_AlreadyHadCard
	b _08019034
	.pool
_08018FCC:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_AlreadyHadStamp
	b _08019034
	.pool
_08018FD8:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_AlreadyHadNews
	b _08019034
	.pool
_08018FE4:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_NoMoreRoomForStamps
	b _08019034
	.pool
_08018FF0:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_CommunicationCanceled
	b _08019034
	.pool
_08018FFC:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_CantAcceptNewsFromTrainer
	cmp r6, 0
	bne _08019034
	ldr r2, =gText_CantAcceptCardFromTrainer
	b _08019034
	.pool
_08019014:
	movs r0, 0
	str r0, [r4]
	ldr r2, =gText_CommunicationError
	b _08019034
	.pool
_08019020:
	movs r0, 0x1
	str r0, [r4]
	ldr r2, =gText_NewTrainerReceived
	b _08019034
	.pool
_0801902C:
	movs r0, 0x1
	b _08019032
_08019030:
	movs r0, 0
_08019032:
	str r0, [r4]
_08019034:
	adds r0, r2, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end mevent_message

	thumb_func_start mevent_08142CE8
mevent_08142CE8: @ 801903C
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	adds r5, r2, 0
	ldrb r4, [r6]
	cmp r4, 0x1
	beq _0801906E
	cmp r4, 0x1
	bgt _08019054
	cmp r4, 0
	beq _0801905A
	b _0801909A
_08019054:
	cmp r4, 0x2
	beq _08019084
	b _0801909A
_0801905A:
	cmp r0, 0
	beq _08019062
	bl sub_8018884
_08019062:
	movs r0, 0xB9
	lsls r0, 1
	bl PlayFanfare
	strh r4, [r5]
	b _0801907C
_0801906E:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF0
	bls _0801909A
_0801907C:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _0801909A
_08019084:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _0801909A
	movs r0, 0
	strb r0, [r6]
	bl sub_80188DC
	movs r0, 0x1
	b _0801909C
_0801909A:
	movs r0, 0
_0801909C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end mevent_08142CE8

	thumb_func_start mevent_message_stamp_card_etc_send_status
mevent_message_stamp_card_etc_send_status: @ 80190A4
	push {r4,lr}
	adds r3, r0, 0
	ldr r1, =gText_CommunicationError
	movs r0, 0
	str r0, [r3]
	adds r4, r1, 0
	cmp r2, 0xE
	bhi _08019166
	lsls r0, r2, 2
	ldr r1, =_080190C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080190C8:
	.4byte _08019104
	.4byte _0801910C
	.4byte _08019114
	.4byte _0801911C
	.4byte _08019128
	.4byte _08019130
	.4byte _08019138
	.4byte _08019140
	.4byte _08019148
	.4byte _08019150
	.4byte _08019164
	.4byte _08019158
	.4byte _0801915C
	.4byte _0801915C
	.4byte _08019164
_08019104:
	ldr r1, =gText_NothingSentOver
	b _08019166
	.pool
_0801910C:
	ldr r1, =gText_RecordUploadedViaWireless
	b _08019166
	.pool
_08019114:
	ldr r1, =gText_WonderCardSentTo
	b _0801911E
	.pool
_0801911C:
	ldr r1, =gText_WonderNewsSentTo
_0801911E:
	movs r0, 0x1
	str r0, [r3]
	b _08019166
	.pool
_08019128:
	ldr r1, =gText_StampSentTo
	b _08019166
	.pool
_08019130:
	ldr r1, =gText_OtherTrainerHasCard
	b _08019166
	.pool
_08019138:
	ldr r1, =gText_OtherTrainerHasStamp
	b _08019166
	.pool
_08019140:
	ldr r1, =gText_OtherTrainerHasNews
	b _08019166
	.pool
_08019148:
	ldr r1, =gText_NoMoreRoomForStamps
	b _08019166
	.pool
_08019150:
	ldr r1, =gText_OtherTrainerCanceled
	b _08019166
	.pool
_08019158:
	adds r1, r4, 0
	b _08019166
_0801915C:
	ldr r1, =gText_GiftSentTo
	b _08019166
	.pool
_08019164:
	ldr r1, =gText_CantSendGiftToTrainer
_08019166:
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_message_stamp_card_etc_send_status

	thumb_func_start sub_8019174
sub_8019174: @ 8019174
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	bl mevent_message_stamp_card_etc_send_status
	adds r1, r0, 0
	ldr r0, [sp]
	cmp r0, 0
	bne _0801919A
	adds r0, r4, 0
	bl mevent_0814257C
	b _080191A2
_0801919A:
	adds r0, r4, 0
	adds r2, r5, 0
	bl mevent_08142CE8
_080191A2:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8019174

	thumb_func_start task_add_00_mystery_gift
task_add_00_mystery_gift: @ 80191AC
	push {r4,lr}
	ldr r0, =task00_mystery_gift
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
	thumb_func_end task_add_00_mystery_gift

	thumb_func_start task00_mystery_gift
task00_mystery_gift: @ 80191F4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrb r0, [r5, 0x8]
	cmp r0, 0x25
	bls _0801920E
	b _08019922
_0801920E:
	lsls r0, 2
	ldr r1, =_08019220
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08019220:
	.4byte _080192B8
	.4byte _080192BE
	.4byte _08019300
	.4byte _08019338
	.4byte _0801935C
	.4byte _080193AC
	.4byte _0801940C
	.4byte _08019444
	.4byte _08019454
	.4byte _080194CC
	.4byte _080194F0
	.4byte _08019508
	.4byte _08019538
	.4byte _08019574
	.4byte _0801958C
	.4byte _080195BC
	.4byte _080198EC
	.4byte _0801961A
	.4byte _0801962A
	.4byte _08019922
	.4byte _0801963C
	.4byte _08019688
	.4byte _080196FE
	.4byte _0801972E
	.4byte _08019764
	.4byte _0801977E
	.4byte _08019792
	.4byte _0801979E
	.4byte _080197B2
	.4byte _080197C6
	.4byte _080197F8
	.4byte _0801982C
	.4byte _08019870
	.4byte _08019884
	.4byte _080198A0
	.4byte _080198B8
	.4byte _080198EC
	.4byte _0801990C
_080192B8:
	movs r0, 0x1
	strb r0, [r5, 0x8]
	b _08019922
_080192BE:
	adds r0, r5, 0
	adds r0, 0x9
	adds r1, r5, 0
	movs r2, 0
	bl sub_8018A50
	adds r1, r0, 0
	cmp r1, 0x1
	beq _080192E8
	cmp r1, 0x1
	bcc _080192DE
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _080192FA
	b _08019922
_080192DE:
	movs r0, 0
	strb r0, [r5, 0xC]
	bl sub_801B27C
	b _080192EE
_080192E8:
	strb r1, [r5, 0xC]
	bl sub_801B0CC
_080192EE:
	cmp r0, 0x1
	bne _080192F4
	b _08019820
_080192F4:
	movs r0, 0x2
	strb r0, [r5, 0x8]
	b _08019922
_080192FA:
	movs r0, 0x25
	strb r0, [r5, 0x8]
	b _08019922
_08019300:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _08019314
	adds r0, r5, 0
	adds r0, 0x9
	ldr r1, =gText_DontHaveCardNewOneInput
	b _0801931A
	.pool
_08019314:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r1, =gText_DontHaveNewsNewOneInput
_0801931A:
	bl mevent_0814257C
	cmp r0, 0
	bne _08019324
	b _08019922
_08019324:
	movs r0, 0x3
	strb r0, [r5, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl sub_80186EC
	b _08019922
	.pool
_08019338:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _0801934C
	ldr r0, =gText_WhereShouldCardBeAccessed
	bl sub_8018884
	b _08019352
	.pool
_0801934C:
	ldr r0, =gText_WhereShouldNewsBeAccessed
	bl sub_8018884
_08019352:
	movs r0, 0x4
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_0801935C:
	adds r0, r5, 0
	adds r0, 0x9
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8018A50
	adds r4, r0, 0
	cmp r4, 0x1
	beq _0801938A
	cmp r4, 0x1
	bcc _0801937C
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _08019396
	b _08019922
_0801937C:
	bl sub_80188DC
	movs r1, 0
	movs r0, 0x5
	strb r0, [r5, 0x8]
	strb r1, [r5, 0xD]
	b _08019922
_0801938A:
	bl sub_80188DC
	movs r0, 0x5
	strb r0, [r5, 0x8]
	strb r4, [r5, 0xD]
	b _08019922
_08019396:
	bl sub_80188DC
	ldrb r0, [r5, 0xC]
	bl sub_8018D98
	cmp r0, 0
	beq _080193A6
	b _08019820
_080193A6:
	strb r0, [r5, 0x8]
	movs r0, 0
	b _080198FE
_080193AC:
	ldr r0, =gStringVar1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =gStringVar2
	strb r1, [r0]
	ldr r0, =gStringVar3
	strb r1, [r0]
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	beq _080193D4
	cmp r0, 0x1
	beq _080193EE
	b _08019406
	.pool
_080193D4:
	ldrb r0, [r5, 0xD]
	cmp r0, 0x1
	bne _080193E2
	movs r0, 0x15
	bl sub_8014EFC
	b _08019406
_080193E2:
	cmp r0, 0
	bne _08019406
	movs r0, 0x15
	bl sub_80152A8
	b _08019406
_080193EE:
	ldrb r0, [r5, 0xD]
	cmp r0, 0x1
	bne _080193FC
	movs r0, 0x16
	bl sub_8014EFC
	b _08019406
_080193FC:
	cmp r0, 0
	bne _08019406
	movs r0, 0x16
	bl sub_80152A8
_08019406:
	movs r0, 0x6
	strb r0, [r5, 0x8]
	b _08019922
_0801940C:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801942C
	movs r0, 0x1
	bl sub_8018838
	movs r0, 0x7
	strb r0, [r5, 0x8]
	ldrb r0, [r5, 0xC]
	bl sub_801D484
	b _08019922
	.pool
_0801942C:
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x5
	beq _08019436
	b _08019922
_08019436:
	movs r0, 0x1
	bl sub_8018838
	b _080197C0
	.pool
_08019444:
	ldr r0, =gText_Communicating
	bl sub_8018884
	movs r0, 0x8
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_08019454:
	adds r0, r5, 0
	bl sub_801D4A8
	subs r0, 0x2
	cmp r0, 0x4
	bls _08019462
	b _08019922
_08019462:
	lsls r0, 2
	ldr r1, =_08019470
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08019470:
	.4byte _080194AE
	.4byte _080194A8
	.4byte _080194B4
	.4byte _08019492
	.4byte _08019484
_08019484:
	bl task_add_05_task_del_08FA224_when_no_RfuFunc
	ldrh r0, [r5]
	strb r0, [r5, 0xE]
	movs r0, 0xD
	strb r0, [r5, 0x8]
	b _08019922
_08019492:
	ldr r4, [r5, 0x10]
	bl sub_801D4F4
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x40
	bl memcpy
	bl sub_801D4E4
	b _08019922
_080194A8:
	movs r0, 0xA
	strb r0, [r5, 0x8]
	b _08019922
_080194AE:
	movs r0, 0x9
	strb r0, [r5, 0x8]
	b _08019922
_080194B4:
	movs r0, 0xB
	strb r0, [r5, 0x8]
	ldr r0, =gStringVar1
	ldr r1, =gLinkPlayers + 8
	bl StringCopy
	b _08019922
	.pool
_080194CC:
	adds r4, r5, 0
	adds r4, 0x9
	bl sub_801D4F4
	adds r3, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_8018B08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0x1
	beq _08019564
	cmp r1, 0x1
	bcs _08019552
	movs r0, 0
	b _08019566
_080194F0:
	adds r4, r5, 0
	adds r4, 0x9
	bl sub_801D4F4
	adds r1, r0, 0
	adds r0, r4, 0
	bl mevent_0814257C
	cmp r0, 0
	bne _08019506
	b _08019922
_08019506:
	b _0801956A
_08019508:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r3, =gText_ThrowAwayWonderCard
	adds r1, r5, 0
	movs r2, 0
	bl sub_8018B08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0x1
	beq _08019564
	cmp r1, 0x1
	bcs _08019552
	bl sub_801B3F8
	cmp r0, 0x1
	bne _08019534
	movs r0, 0xC
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_08019534:
	movs r0, 0
	b _08019566
_08019538:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r3, =gText_HaventReceivedCardsGift
	adds r1, r5, 0
	movs r2, 0
	bl sub_8018B08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0x1
	beq _08019564
	cmp r1, 0x1
	bcc _08019560
_08019552:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08019564
	b _08019922
	.pool
_08019560:
	movs r0, 0
	b _08019566
_08019564:
	movs r0, 0x1
_08019566:
	bl sub_801D500
_0801956A:
	bl sub_801D4E4
	movs r0, 0x7
	strb r0, [r5, 0x8]
	b _08019922
_08019574:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801957E
	b _08019922
_0801957E:
	bl sub_800E084
	movs r0, 0xE
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_0801958C:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r1, =gText_CommunicationCompleted
	bl sub_8018A1C
	cmp r0, 0
	bne _0801959C
	b _08019922
_0801959C:
	ldrb r0, [r5, 0xD]
	cmp r0, 0x1
	bne _080195AA
	ldr r0, =gStringVar1
	ldr r1, =gLinkPlayers + 8
	bl StringCopy
_080195AA:
	movs r0, 0xF
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_080195BC:
	ldrb r1, [r5, 0xC]
	ldrb r2, [r5, 0xD]
	ldrb r3, [r5, 0xE]
	mov r0, sp
	bl mevent_message
	adds r1, r0, 0
	cmp r1, 0
	bne _080195D0
	ldr r1, [r5, 0x10]
_080195D0:
	ldr r0, [sp]
	cmp r0, 0
	beq _080195E2
	adds r0, r5, 0
	adds r0, 0x9
	adds r2, r5, 0
	bl mevent_08142CE8
	b _080195EA
_080195E2:
	adds r0, r5, 0
	adds r0, 0x9
	bl mevent_0814257C
_080195EA:
	adds r1, r0, 0
	cmp r1, 0
	bne _080195F2
	b _08019922
_080195F2:
	ldrb r0, [r5, 0xE]
	cmp r0, 0x3
	bne _0801960C
	ldrb r0, [r5, 0xD]
	cmp r0, 0x1
	bne _08019606
	movs r0, 0x1
	bl sub_801DB68
	b _0801960C
_08019606:
	movs r0, 0x2
	bl sub_801DB68
_0801960C:
	ldr r0, [sp]
	cmp r0, 0
	beq _08019614
	b _080198DC
_08019614:
	strb r0, [r5, 0x8]
	movs r0, 0
	b _080198FE
_0801961A:
	adds r0, r5, 0
	adds r0, 0x9
	bl mevent_save_game
	cmp r0, 0
	bne _08019628
	b _08019922
_08019628:
	b _08019820
_0801962A:
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r1, [r5, 0xC]
	bl sub_8018DAC
	cmp r0, 0
	bne _0801963A
	b _08019922
_0801963A:
	b _080196F8
_0801963C:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _08019664
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08019652
	movs r0, 0x15
	strb r0, [r5, 0x8]
_08019652:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0801965E
	b _08019922
_0801965E:
	b _08019682
	.pool
_08019664:
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	bl sub_801CCD0
	cmp r0, 0
	beq _0801967C
	cmp r0, 0x1
	beq _08019682
	b _08019922
	.pool
_0801967C:
	bl sub_801CC38
	b _0801975E
_08019682:
	movs r0, 0x1B
	strb r0, [r5, 0x8]
	b _08019922
_08019688:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _080196A2
	bl sub_801B308
	cmp r0, 0
	beq _080196B6
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r2, [r5, 0xC]
	adds r1, r5, 0
	movs r3, 0
	b _080196C0
_080196A2:
	bl sub_801B128
	cmp r0, 0
	beq _080196B6
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r2, [r5, 0xC]
	adds r1, r5, 0
	movs r3, 0
	b _080196C0
_080196B6:
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r2, [r5, 0xC]
	adds r1, r5, 0
	movs r3, 0x1
_080196C0:
	bl sub_8018C4C
	adds r1, r0, 0
	cmp r1, 0x1
	beq _080196E2
	cmp r1, 0x1
	bcc _080196DC
	cmp r1, 0x2
	beq _080196E8
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _080196EE
	b _08019922
_080196DC:
	movs r0, 0x1C
	strb r0, [r5, 0x8]
	b _08019922
_080196E2:
	movs r0, 0x1D
	strb r0, [r5, 0x8]
	b _08019922
_080196E8:
	movs r0, 0x16
	strb r0, [r5, 0x8]
	b _08019922
_080196EE:
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	bne _080196F8
	bl sub_801CC80
_080196F8:
	movs r0, 0x14
	strb r0, [r5, 0x8]
	b _08019922
_080196FE:
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r2, [r5, 0xC]
	adds r1, r5, 0
	bl sub_8018E50
	adds r1, r0, 0
	cmp r1, 0
	beq _0801971A
	cmp r1, 0
	ble _08019748
	cmp r1, 0x1
	beq _0801975E
	b _08019922
_0801971A:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _08019758
	bl sub_801B3F8
	cmp r0, 0x1
	bne _08019758
	movs r0, 0x17
	strb r0, [r5, 0x8]
	b _08019922
_0801972E:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r3, =gText_HaventReceivedGiftOkayToDiscard
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8018B08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0x1
	beq _0801975E
	cmp r1, 0x1
	bcc _08019758
_08019748:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801975E
	b _08019922
	.pool
_08019758:
	movs r0, 0x18
	strb r0, [r5, 0x8]
	b _08019922
_0801975E:
	movs r0, 0x15
	strb r0, [r5, 0x8]
	b _08019922
_08019764:
	ldrb r0, [r5, 0xC]
	movs r1, 0x1
	bl sub_8018E20
	cmp r0, 0
	bne _08019772
	b _08019922
_08019772:
	ldrb r0, [r5, 0xC]
	bl sub_8018E08
	movs r0, 0x19
	strb r0, [r5, 0x8]
	b _08019922
_0801977E:
	adds r0, r5, 0
	adds r0, 0x9
	bl mevent_save_game
	cmp r0, 0
	bne _0801978C
	b _08019922
_0801978C:
	movs r0, 0x1A
	strb r0, [r5, 0x8]
	b _08019922
_08019792:
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r1, [r5, 0xC]
	bl mevent_message_was_thrown_away
	b _080198F6
_0801979E:
	ldrb r0, [r5, 0xC]
	movs r1, 0
	bl sub_8018E20
	cmp r0, 0
	bne _080197AC
	b _08019922
_080197AC:
	movs r0, 0
	strb r0, [r5, 0x8]
	b _08019922
_080197B2:
	ldrb r0, [r5, 0xC]
	movs r1, 0x1
	bl sub_8018E20
	cmp r0, 0
	bne _080197C0
	b _08019922
_080197C0:
	movs r0, 0x3
	strb r0, [r5, 0x8]
	b _08019922
_080197C6:
	ldrb r0, [r5, 0xC]
	movs r1, 0x1
	bl sub_8018E20
	cmp r0, 0
	bne _080197D4
	b _08019922
_080197D4:
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	beq _080197E0
	cmp r0, 0x1
	beq _080197E8
	b _080197EE
_080197E0:
	movs r0, 0x15
	bl sub_8014A00
	b _080197EE
_080197E8:
	movs r0, 0x16
	bl sub_8014A00
_080197EE:
	movs r0, 0x1
	strb r0, [r5, 0xD]
	movs r0, 0x1E
	strb r0, [r5, 0x8]
	b _08019922
_080197F8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _08019810
	movs r0, 0x1
	bl sub_8018838
	movs r0, 0x1F
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_08019810:
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x5
	beq _0801981A
	b _08019922
_0801981A:
	movs r0, 0x1
	bl sub_8018838
_08019820:
	movs r0, 0x12
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_0801982C:
	ldr r0, =gStringVar1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =gStringVar2
	strb r1, [r0]
	ldr r0, =gStringVar3
	strb r1, [r0]
	ldrb r0, [r5, 0xC]
	cmp r0, 0
	bne _0801985C
	ldr r0, =gText_SendingWonderCard
	bl sub_8018884
	bl mevent_srv_new_wcard
	b _08019866
	.pool
_0801985C:
	ldr r0, =gText_SendingWonderNews
	bl sub_8018884
	bl mevent_srv_init_wnews
_08019866:
	movs r0, 0x20
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_08019870:
	adds r0, r5, 0
	bl sub_801D0C4
	cmp r0, 0x3
	bne _08019922
	ldrh r0, [r5]
	strb r0, [r5, 0xE]
	movs r0, 0x21
	strb r0, [r5, 0x8]
	b _08019922
_08019884:
	bl task_add_05_task_del_08FA224_when_no_RfuFunc
	ldr r0, =gStringVar1
	ldr r1, =gLinkPlayers + 0x1C + 0x08 @ &gLinkPlayers[1].name
	bl StringCopy
	movs r0, 0x22
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_080198A0:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _08019922
	bl sub_800E084
	movs r0, 0x23
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_080198B8:
	adds r0, r5, 0
	adds r0, 0x9
	ldrb r2, [r5, 0xD]
	ldrb r3, [r5, 0xE]
	adds r1, r5, 0
	bl sub_8019174
	cmp r0, 0
	beq _08019922
	ldr r0, [r5, 0xC]
	ldr r1, =0x00ffff00
	ands r0, r1
	ldr r1, =0x00030100
	cmp r0, r1
	bne _080198FA
	movs r0, 0x3
	bl sub_801DB68
_080198DC:
	movs r0, 0x11
	strb r0, [r5, 0x8]
	b _08019922
	.pool
_080198EC:
	adds r0, r5, 0
	adds r0, 0x9
	ldr r1, =gText_CommunicationError
	bl mevent_0814257C
_080198F6:
	cmp r0, 0
	beq _08019922
_080198FA:
	movs r0, 0
	strb r0, [r5, 0x8]
_080198FE:
	movs r1, 0
	bl sub_80186EC
	b _08019922
	.pool
_0801990C:
	bl CloseLink
	ldr r0, [r5, 0x10]
	bl Free
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_08019922:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_mystery_gift

	thumb_func_start sub_8019930
sub_8019930: @ 8019930
	ldr r0, =0x000001a9
	bx lr
	.pool
	thumb_func_end sub_8019930

	thumb_func_start bgid_upload_textbox_1
bgid_upload_textbox_1: @ 8019938
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnkTextboxBorderGfx
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0
	str r3, [sp]
	bl DecompressAndLoadBgGfxUsingHeap
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end bgid_upload_textbox_1

	thumb_func_start is_walking_or_running
is_walking_or_running: @ 8019958
	push {lr}
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x3]
	cmp r0, 0x2
	beq _08019966
	cmp r0, 0
	bne _08019970
_08019966:
	movs r0, 0x1
	b _08019972
	.pool
_08019970:
	movs r0, 0
_08019972:
	pop {r1}
	bx r1
	thumb_func_end is_walking_or_running

	thumb_func_start sub_8019978
sub_8019978: @ 8019978
	ldr r3, =gUnknown_082F072C
	movs r2, 0x7
	ands r2, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	adds r2, r1
	adds r2, r3
	ldrb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8019978

	thumb_func_start sub_8019990
sub_8019990: @ 8019990
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, =gUnknown_082F0740
	mov r8, r4
	lsls r0, 2
	adds r4, r0, r4
	movs r6, 0
	ldrsh r5, [r4, r6]
	ldr r6, =gUnknown_082F0760
	lsls r1, 1
	adds r4, r1, r6
	ldrb r4, [r4]
	lsls r4, 24
	asrs r4, 24
	adds r5, r4
	adds r5, 0x7
	str r5, [r2]
	movs r2, 0x2
	add r8, r2
	add r0, r8
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r6, 0x1
	adds r1, r6
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	adds r0, r1
	adds r0, 0x7
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019990

	thumb_func_start sub_80199E0
sub_80199E0: @ 80199E0
	push {r4-r7,lr}
	mov r12, r3
	ldr r7, =gUnknown_082F0740
	lsls r5, r0, 2
	adds r0, r5, r7
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r6, =gUnknown_082F0760
	lsls r4, r1, 1
	adds r0, r4, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r3, r0
	adds r3, 0x7
	cmp r3, r2
	bne _08019A28
	adds r0, r7, 0x2
	adds r0, r5, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r6, 0x1
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r1, r0
	adds r1, 0x7
	cmp r1, r12
	bne _08019A28
	movs r0, 0x1
	b _08019A2A
	.pool
_08019A28:
	movs r0, 0
_08019A2A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80199E0

	thumb_func_start sub_8019A30
sub_8019A30: @ 8019A30
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8019A30

	thumb_func_start flag_set_x63
flag_set_x63: @ 8019A4C
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end flag_set_x63

	thumb_func_start flag_clear_x63
flag_clear_x63: @ 8019A64
	push {lr}
	ldr r1, =0x000002bf
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagClear
	pop {r0}
	bx r0
	.pool
	thumb_func_end flag_clear_x63

	thumb_func_start sub_8019A7C
sub_8019A7C: @ 8019A7C
	push {lr}
	ldr r2, =0x00004010
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019A7C

	thumb_func_start sub_8019A98
sub_8019A98: @ 8019A98
	push {lr}
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl show_sprite
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019A98

	thumb_func_start sub_8019AB8
sub_8019AB8: @ 8019AB8
	push {lr}
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl RemoveEventObjectByLocalIdAndMap
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019AB8

	thumb_func_start sub_8019AD8
sub_8019AD8: @ 8019AD8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r1, 0
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	ldrb r1, [r5]
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	lsls r0, 24
	cmp r0, 0
	bne _08019B30
	movs r0, 0x1
	b _08019B32
	.pool
_08019B30:
	movs r0, 0
_08019B32:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8019AD8

	thumb_func_start sub_8019B3C
sub_8019B3C: @ 8019B3C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_082F0774
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _08019B9C
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	bne _08019B84
	movs r0, 0
	b _08019B9E
	.pool
_08019B84:
	bl ScriptContext2_IsEnabled
	lsls r0, 24
	cmp r0, 0
	bne _08019B96
	adds r0, r4, 0
	bl UnfreezeEventObject
	b _08019B9C
_08019B96:
	adds r0, r4, 0
	bl FreezeEventObject
_08019B9C:
	movs r0, 0x1
_08019B9E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019B3C

	thumb_func_start sub_8019BA8
sub_8019BA8: @ 8019BA8
	push {lr}
	ldr r2, =gUnknown_02022C68
	movs r1, 0
	str r1, [r2]
	ldr r1, =gUnknown_02022C64
	str r0, [r1]
	movs r1, 0
	movs r2, 0x7
_08019BB8:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x3]
	adds r0, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08019BB8
	bl sub_8019DF4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8019BA8

	thumb_func_start sub_8019BDC
sub_8019BDC: @ 8019BDC
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	beq _08019BF0
	cmp r0, 0x1
	beq _08019C10
	b _08019C2E
_08019BF0:
	ldr r1, =gUnknown_082F078C
	adds r0, r4, 0
	bl sub_8019AD8
	cmp r0, 0x1
	bne _08019C2E
	adds r0, r4, 0
	bl flag_set_x63
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _08019C2E
	.pool
_08019C10:
	adds r0, r4, 0
	bl sub_8019B3C
	cmp r0, 0
	beq _08019C2E
	adds r0, r4, 0
	bl sub_8019AB8
	adds r0, r4, 0
	bl flag_set_x63
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	b _08019C30
_08019C2E:
	movs r0, 0
_08019C30:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8019BDC

	thumb_func_start sub_8019C38
sub_8019C38: @ 8019C38
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	movs r0, 0
	ldrsb r0, [r6, r0]
	cmp r0, 0x2
	beq _08019CD4
	cmp r0, 0x2
	bgt _08019C54
	cmp r0, 0
	beq _08019C5A
	b _08019CE6
_08019C54:
	cmp r0, 0x3
	beq _08019CBC
	b _08019CE6
_08019C5A:
	bl is_walking_or_running
	cmp r0, 0
	beq _08019CE6
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r4, r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _08019CE6
	mov r0, sp
	adds r1, r4, 0
	bl player_get_pos_including_state_based_drift
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r4, r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _08019CE6
	ldrb r1, [r7, 0x1]
	adds r0, r5, 0
	bl sub_8019A7C
	adds r0, r5, 0
	bl sub_8019A98
	adds r0, r5, 0
	bl flag_clear_x63
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_08019CBC:
	ldr r1, =gUnknown_082F078E
	adds r0, r5, 0
	bl sub_8019AD8
	cmp r0, 0x1
	bne _08019CE6
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08019CE6
	.pool
_08019CD4:
	adds r0, r5, 0
	bl sub_8019B3C
	cmp r0, 0
	beq _08019CE6
	movs r0, 0
	strb r0, [r6]
	movs r0, 0x1
	b _08019CE8
_08019CE6:
	movs r0, 0
_08019CE8:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8019C38

	thumb_func_start sub_8019CF0
sub_8019CF0: @ 8019CF0
	push {r4,lr}
	ldr r3, =gUnknown_02022C64
	lsls r0, 2
	ldr r4, [r3]
	adds r4, r0
	movs r0, 0x1
	strb r0, [r4, 0x3]
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_8019978
	strb r0, [r4, 0x1]
	ldrb r0, [r4]
	cmp r0, 0
	beq _08019D18
	movs r0, 0
	b _08019D1A
	.pool
_08019D18:
	movs r0, 0x1
_08019D1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019CF0

	thumb_func_start AGBAssert
AGBAssert: @ 8019D20
	push {lr}
	ldr r1, =gUnknown_02022C64
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1, 0x3]
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08019D3C
	movs r0, 0
	b _08019D3E
	.pool
_08019D3C:
	movs r0, 0x1
_08019D3E:
	pop {r1}
	bx r1
	thumb_func_end AGBAssert

	thumb_func_start sub_8019D44
sub_8019D44: @ 8019D44
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	cmp r1, 0x1
	beq _08019DA6
	cmp r1, 0x1
	bgt _08019D5A
	cmp r1, 0
	beq _08019D64
	b _08019DC6
_08019D5A:
	cmp r1, 0x2
	beq _08019D70
	cmp r1, 0x3
	beq _08019DB4
	b _08019DC6
_08019D64:
	ldrb r0, [r4, 0x3]
	cmp r0, 0x1
	bne _08019DC6
	movs r0, 0x2
	strb r0, [r4]
	strb r1, [r4, 0x2]
_08019D70:
	adds r0, r5, 0
	movs r1, 0
	bl sub_8019F8C
	adds r1, r0, 0
	cmp r1, 0
	bne _08019D96
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	bne _08019D96
	strb r1, [r4]
	strb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8019AB8
	adds r0, r5, 0
	bl flag_set_x63
	b _08019DC6
_08019D96:
	adds r0, r4, 0x2
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8019C38
	cmp r0, 0x1
	bne _08019DC6
	b _08019DC4
_08019DA6:
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	bne _08019DC6
	movs r1, 0
	movs r0, 0x3
	strb r0, [r4]
	strb r1, [r4, 0x2]
_08019DB4:
	adds r0, r4, 0x2
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8019BDC
	cmp r0, 0x1
	bne _08019DC6
	movs r0, 0
_08019DC4:
	strb r0, [r4]
_08019DC6:
	movs r0, 0
	strb r0, [r4, 0x3]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8019D44

	thumb_func_start sub_8019DD0
sub_8019DD0: @ 8019DD0
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gUnknown_02022C64
_08019DD6:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	adds r0, r4, 0
	bl sub_8019D44
	adds r4, 0x1
	cmp r4, 0x7
	ble _08019DD6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019DD0

	thumb_func_start sub_8019DF4
sub_8019DF4: @ 8019DF4
	push {r4,lr}
	ldr r4, =sub_8019DD0
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08019E18
	adds r0, r4, 0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	b _08019E1A
	.pool
_08019E18:
	movs r0, 0x10
_08019E1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8019DF4

	thumb_func_start sub_8019E20
sub_8019E20: @ 8019E20
	push {lr}
	ldr r0, =sub_8019DD0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _08019E34
	bl DestroyTask
_08019E34:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E20

	thumb_func_start sub_8019E3C
sub_8019E3C: @ 8019E3C
	push {r4,lr}
	movs r4, 0
_08019E40:
	adds r0, r4, 0
	bl sub_8019A30
	cmp r0, 0
	bne _08019E56
	adds r0, r4, 0
	bl sub_8019AB8
	adds r0, r4, 0
	bl flag_set_x63
_08019E56:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08019E40
	ldr r1, =gUnknown_02022C64
	movs r0, 0
	str r0, [r1]
	bl sub_8019E20
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E3C

	thumb_func_start sub_8019E70
sub_8019E70: @ 8019E70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp, 0x8]
	mov r9, r1
	movs r7, 0
	mov r0, r9
	lsls r0, 2
	mov r8, r0
	ldr r0, =gUnknown_082F0740
	mov r2, r8
	adds r1, r2, r0
	ldrh r1, [r1]
	mov r2, sp
	strh r1, [r2, 0xC]
	adds r0, 0x2
	add r0, r8
	ldrh r0, [r0]
	mov r10, r0
	ldr r6, =gUnknown_082F0760
_08019E9E:
	mov r5, r8
	add r5, r9
	adds r5, r7
	adds r4, r5, 0
	subs r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	movs r2, 0
	ldrsb r2, [r6, r2]
	mov r0, sp
	ldrh r0, [r0, 0xC]
	adds r2, r0, r2
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x1
	ldrsb r3, [r6, r3]
	add r3, r10
	lsls r3, 16
	asrs r3, 16
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x41
	adds r1, r4, 0
	bl sprite_new
	ldr r1, [sp, 0x8]
	adds r5, r1, r5
	strb r0, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8097C44
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x4
	ble _08019E9E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019E70

	thumb_func_start sub_8019F04
sub_8019F04: @ 8019F04
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gSprites
_08019F0C:
	adds r0, r5, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	adds r4, 0x1
	cmp r4, 0x27
	ble _08019F0C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8019F04

	thumb_func_start sub_8019F2C
sub_8019F2C: @ 8019F2C
	push {r4-r7,lr}
	sub sp, 0x8
	movs r5, 0
	add r7, sp, 0x4
_08019F34:
	movs r4, 0
	adds r6, r5, 0x1
_08019F38:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0
	bl sub_8088B94
	adds r4, 0x1
	cmp r4, 0x4
	ble _08019F38
	adds r5, r6, 0
	cmp r5, 0x7
	ble _08019F34
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019F2C

	thumb_func_start sub_8019F64
sub_8019F64: @ 8019F64
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	beq _08019F78
	ldr r0, =gUnknown_082F076F
	adds r0, r1, r0
	ldrb r0, [r0]
	b _08019F88
	.pool
_08019F78:
	ldrb r1, [r2, 0xA]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x45
	beq _08019F86
	movs r0, 0x4
	b _08019F88
_08019F86:
	movs r0, 0x1
_08019F88:
	pop {r1}
	bx r1
	thumb_func_end sub_8019F64

	thumb_func_start sub_8019F8C
sub_8019F8C: @ 8019F8C
	push {lr}
	adds r2, r0, 0
	lsls r0, r2, 2
	adds r0, r2
	adds r0, r1
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097C8C
	pop {r1}
	bx r1
	thumb_func_end sub_8019F8C

	thumb_func_start sub_8019FA4
sub_8019FA4: @ 8019FA4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	mov r9, r3
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r0, r5, 2
	adds r0, r5
	adds r7, r0, r6
	adds r0, r5, 0
	bl sub_8019F8C
	cmp r0, 0x1
	bne _08019FE2
	adds r4, r7, 0
	subs r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_8097C44
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8097CC4
_08019FE2:
	adds r0, r7, 0
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	bl sub_8097BB4
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r9
	bl sub_8019F64
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_801A3B0
	add r3, sp, 0x4
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, sp
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0x1
	bl sub_8088B94
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019FA4

	thumb_func_start sub_801A02C
sub_801A02C: @ 801A02C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r4, 2
	adds r0, r4
	adds r0, r5
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_8097CC4
	add r3, sp, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_8019990
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	movs r2, 0
	bl sub_8088B94
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A02C

	thumb_func_start sub_801A064
sub_801A064: @ 801A064
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	mov r8, r1
	mov r6, sp
	adds r6, 0x2
	mov r0, sp
	adds r1, r6, 0
	bl PlayerGetDestCoords
	add r4, sp, 0x4
	mov r5, sp
	adds r5, 0x6
	adds r0, r4, 0
	adds r1, r5, 0
	bl player_get_pos_including_state_based_drift
	lsls r0, r7, 2
	adds r0, r7
	subs r0, 0x38
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097C8C
	mov r10, r6
	mov r9, r4
	adds r6, r5, 0
	cmp r0, 0x1
	bne _0801A0F0
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, r10
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r7, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _0801A15C
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r1, 0
	ldrsh r3, [r6, r1]
	adds r0, r7, 0
	movs r1, 0
	bl sub_80199E0
	cmp r0, 0x1
	beq _0801A15C
	mov r2, r8
	ldrb r0, [r2, 0xB]
	lsls r0, 31
	lsrs r0, 31
	ldrb r1, [r2, 0x2]
	bl sub_8019978
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r7, 0
	movs r1, 0
	mov r3, r8
	bl sub_8019FA4
_0801A0F0:
	movs r5, 0x1
	mov r4, r8
	adds r4, 0x4
_0801A0F6:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0801A106
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_801A02C
	b _0801A154
_0801A106:
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r0, r10
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80199E0
	cmp r0, 0
	bne _0801A154
	mov r0, r9
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	ldrsh r3, [r6, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80199E0
	cmp r0, 0
	bne _0801A154
	ldrb r2, [r4]
	lsrs r0, r2, 3
	movs r1, 0x1
	ands r0, r1
	movs r1, 0x7
	ands r1, r2
	bl sub_8019978
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r7, 0
	adds r1, r5, 0
	mov r3, r8
	bl sub_8019FA4
_0801A154:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0x4
	ble _0801A0F6
_0801A15C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801A064

	thumb_func_start sub_801A16C
sub_801A16C: @ 801A16C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r4, 0xA]
	lsls r0, 25
	lsrs r0, 25
	subs r0, 0x40
	cmp r0, 0x14
	bhi _0801A20E
	lsls r0, 2
	ldr r1, =_0801A18C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A18C:
	.4byte _0801A1E0
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A20E
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A200
	.4byte _0801A1E0
_0801A1E0:
	ldrb r1, [r4, 0xB]
	lsls r1, 31
	lsrs r1, 31
	ldrb r2, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8019CF0
	movs r4, 0
_0801A1F0:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A02C
	adds r4, 0x1
	cmp r4, 0x4
	bls _0801A1F0
	b _0801A20E
_0801A200:
	adds r0, r5, 0
	bl AGBAssert
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A064
_0801A20E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A16C

	thumb_func_start sub_801A214
sub_801A214: @ 801A214
	push {r4,r5,lr}
	adds r5, r0, 0
	bl AGBAssert
	movs r4, 0
_0801A21E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A02C
	adds r4, 0x1
	cmp r4, 0x4
	ble _0801A21E
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A214

	thumb_func_start sub_801A234
sub_801A234: @ 801A234
	push {r4,r5,lr}
	ldr r2, =gUnknown_02022C68
	movs r1, 0
	str r1, [r2]
	movs r5, 0
	ldr r4, [r0]
_0801A240:
	ldrb r0, [r4, 0x1A]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x1
	bne _0801A258
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A16C
	b _0801A264
	.pool
_0801A258:
	cmp r1, 0x2
	bne _0801A264
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A214
_0801A264:
	adds r4, 0x20
	adds r5, 0x1
	cmp r5, 0x7
	ble _0801A240
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A234

	thumb_func_start sub_801A274
sub_801A274: @ 801A274
	ldr r1, =gUnknown_02022C68
	movs r0, 0x96
	lsls r0, 1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801A274

	thumb_func_start sub_801A284
sub_801A284: @ 801A284
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02022C68
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	movs r0, 0x96
	lsls r0, 1
	cmp r1, r0
	bls _0801A29E
	adds r0, r2, 0
	bl sub_801A234
_0801A29E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A284

	thumb_func_start sub_801A2A8
sub_801A2A8: @ 801A2A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	bl is_walking_or_running
	cmp r0, 0
	bne _0801A2F0
	b _0801A396
_0801A2C4:
	ldr r4, =gUnknown_082F076A
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r2, [r0]
	adds r0, r6, 0
	ldr r1, [sp, 0xC]
	bl sub_801A3B0
	ldr r0, [sp, 0x4]
	strh r6, [r0]
	mov r1, sp
	ldrh r2, [r1, 0xC]
	ldr r1, [sp, 0x8]
	strh r2, [r1]
	movs r0, 0x1
	b _0801A398
	.pool
_0801A2F0:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	movs r0, 0
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_082F0740
	adds r7, r5, 0
	movs r1, 0
	mov r10, r1
	adds r2, r0, 0x2
	str r2, [sp, 0x10]
	str r0, [sp, 0x14]
_0801A30E:
	movs r6, 0
	ldr r4, [sp, 0x14]
	movs r0, 0
	ldrsh r4, [r4, r0]
	mov r9, r4
	ldr r1, [sp, 0x10]
	mov r8, r1
	ldr r5, =gUnknown_082F0760
_0801A31E:
	mov r2, r10
	adds r3, r2, r6
	mov r0, sp
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r5, r0]
	add r0, r9
	adds r0, 0x7
	cmp r1, r0
	bne _0801A372
	mov r1, sp
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	mov r4, r8
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r2, 0x1
	ldrsb r2, [r5, r2]
	adds r1, r2
	adds r1, 0x7
	cmp r0, r1
	bne _0801A372
	adds r0, r3, 0
	subs r0, 0x38
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8097C8C
	cmp r0, 0
	bne _0801A372
	adds r0, r4, 0
	bl sub_8097D9C
	cmp r0, 0
	bne _0801A372
	ldrb r1, [r7, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0801A2C4
_0801A372:
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x4
	ble _0801A31E
	adds r7, 0x20
	movs r4, 0x5
	add r10, r4
	ldr r0, [sp, 0x10]
	adds r0, 0x4
	str r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	adds r1, 0x4
	str r1, [sp, 0x14]
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	cmp r2, 0x7
	ble _0801A30E
_0801A396:
	movs r0, 0
_0801A398:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801A2A8

	thumb_func_start sub_801A3B0
sub_801A3B0: @ 801A3B0
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r1, r2, 24
	lsrs r1, 24
	lsls r0, r3, 2
	adds r0, r3
	subs r0, 0x38
	adds r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B78
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801A3B0

	thumb_func_start sub_801A3D0
sub_801A3D0: @ 801A3D0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r3, r4, 5
	adds r3, r2
	adds r2, r3, 0
	bl sub_8019F64
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_801A3B0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801A3D0

	thumb_func_start sub_801A3F4
sub_801A3F4: @ 801A3F4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801A414
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801A414:
	pop {r0}
	bx r0
	thumb_func_end sub_801A3F4

	thumb_func_start sub_801A418
sub_801A418: @ 801A418
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801A418

	thumb_func_start sub_801A42C
sub_801A42C: @ 801A42C
	push {lr}
	ldr r0, =sub_801A43C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A42C

	thumb_func_start sub_801A43C
sub_801A43C: @ 801A43C
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r5, =gUnknown_03000DAC
	movs r0, 0x6C
	bl AllocZeroed
	str r0, [r5]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0D34
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gWirelessInfoScreenGfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, =gWirelessInfoScreenTilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_082F0D3C
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl ScanlineEffect_Stop
	bl m4aSoundVSyncOn
	ldr r0, =sub_801A418
	bl SetVBlankCallback
	ldr r0, =sub_801A6C0
	movs r1, 0
	bl CreateTask
	ldr r1, [r5]
	adds r1, 0x60
	strb r0, [r1]
	bl sub_8013C40
	ldr r1, [r5]
	adds r1, 0x61
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x1C]
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
	ldr r0, =gWirelessInfoScreenPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xF0
	bl sub_81978B0
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =sub_801A3F4
	bl SetMainCallback2
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A43C

	thumb_func_start sub_801A584
sub_801A584: @ 801A584
	push {r4,lr}
	bl FreeAllWindowBuffers
	movs r4, 0
_0801A58C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	bl Free
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801A58C
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	bl Free
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A584

	thumb_func_start sub_801A5BC
sub_801A5BC: @ 801A5BC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _0801A5E4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bne _0801A5E0
	movs r0, 0
	strh r0, [r1]
_0801A5E0:
	movs r0, 0
	strh r0, [r2]
_0801A5E4:
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x2
	lsls r0, 5
	ldr r1, =gWirelessInfoScreenPal
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A5BC

	thumb_func_start sub_801A600
sub_801A600: @ 801A600
	push {r4,r5,lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_082F0D5C
	ldr r4, [r5]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_801A8B0
	movs r1, 0
_0801A644:
	adds r4, r1, 0x1
	lsls r0, r4, 2
	adds r0, r5
	ldr r2, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	adds r1, r4, 0
	cmp r4, 0x2
	ble _0801A644
	ldr r1, =gUnknown_082F0D5C
	adds r0, r4, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A600

	thumb_func_start sub_801A6C0
sub_801A6C0: @ 801A6C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x5
	bls _0801A6E2
	b _0801A89C
_0801A6E2:
	lsls r0, 2
	ldr r1, =_0801A6F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A6F4:
	.4byte _0801A70C
	.4byte _0801A728
	.4byte _0801A74C
	.4byte _0801A768
	.4byte _0801A85C
	.4byte _0801A884
_0801A70C:
	bl sub_801A600
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0801A89C
	.pool
_0801A728:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl ShowBg
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	b _0801A86C
_0801A74C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0801A75A
	b _0801A89C
_0801A75A:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	b _0801A876
	.pool
_0801A768:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x10
	adds r2, r0, 0
	adds r2, 0x20
	adds r3, r0, 0
	adds r3, 0x61
	ldrb r3, [r3]
	bl sub_801AA30
	lsls r1, r5, 2
	mov r8, r1
	cmp r0, 0
	beq _0801A7F8
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r4, 0
	ldr r6, =gStringVar4
	movs r7, 0x80
	lsls r7, 20
_0801A796:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	cmp r4, 0x3
	beq _0801A7CC
	lsrs r0, r7, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
	b _0801A7DE
	.pool
_0801A7CC:
	movs r0, 0x62
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
_0801A7DE:
	movs r2, 0xF0
	lsls r2, 21
	adds r7, r2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801A796
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
_0801A7F8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801A80C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801A836
_0801A80C:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gTasks
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r0, 0x61
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xFF
	strh r1, [r0, 0x26]
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0801A836:
	mov r2, r8
	adds r1, r2, r5
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r0, r1, 0
	adds r0, 0xE
	adds r1, 0x10
	bl sub_801A5BC
	b _0801A89C
	.pool
_0801A85C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0801A86C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
_0801A876:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0801A89C
	.pool
_0801A884:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801A89C
	ldr r0, =sub_801A584
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_0801A89C:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A6C0

	thumb_func_start sub_801A8B0
sub_801A8B0: @ 801A8B0
	push {r4-r7,lr}
	sub sp, 0x18
	mov r12, r2
	ldr r2, [sp, 0x2C]
	ldr r4, [sp, 0x30]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r4, 24
	lsrs r0, r4, 24
	cmp r0, 0x4
	bhi _0801A93A
	lsls r0, 2
	ldr r1, =_0801A8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A8E0:
	.4byte _0801A8F4
	.4byte _0801A902
	.4byte _0801A910
	.4byte _0801A91E
	.4byte _0801A92C
_0801A8F4:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A902:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A910:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x5
	b _0801A938
_0801A91E:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	movs r0, 0x6
	b _0801A938
_0801A92C:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
_0801A938:
	strb r0, [r1, 0x2]
_0801A93A:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	mov r0, r12
	str r0, [sp, 0x10]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801A8B0

	thumb_func_start sub_801A960
sub_801A960: @ 801A960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r12, r0
	adds r7, r1, 0
	ldrb r0, [r0, 0xA]
	lsls r0, 25
	lsrs r0, 25
	mov r8, r0
	movs r4, 0
	ldr r0, =gUnknown_082F0D70
	mov r9, r0
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	mov r3, r12
	adds r3, 0x4
	str r3, [sp]
_0801A98A:
	lsls r0, r4, 1
	adds r2, r0, r4
	mov r3, r9
	adds r1, r2, r3
	adds r5, r0, 0
	adds r6, r4, 0x1
	ldrb r1, [r1]
	cmp r8, r1
	bne _0801A9EE
	mov r0, r12
	ldrb r1, [r0, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801A9EE
	mov r0, r9
	adds r0, 0x2
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, 0
	bne _0801A9DC
	movs r2, 0
	movs r1, 0
	ldr r3, [sp]
_0801A9BA:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801A9C4
	adds r2, 0x1
_0801A9C4:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801A9BA
	adds r2, 0x1
	adds r0, r5, r4
	add r0, r10
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	b _0801A9E8
	.pool
_0801A9DC:
	mov r1, r10
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r3]
_0801A9E8:
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
_0801A9EE:
	adds r4, r6, 0
	cmp r4, 0x1E
	bls _0801A98A
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801A960

	thumb_func_start sub_801AA08
sub_801AA08: @ 801AA08
	push {r4,lr}
	movs r4, 0
	adds r3, r1, 0
	adds r2, r0, 0
_0801AA10:
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _0801AA1C
	movs r0, 0x1
	b _0801AA28
_0801AA1C:
	adds r3, 0x4
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801AA10
	movs r0, 0
_0801AA28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA08

	thumb_func_start sub_801AA30
sub_801AA30: @ 801AA30
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r0, 0
	mov r9, r1
	adds r5, r2, 0
	lsls r4, r3, 24
	lsrs r4, 24
	movs r0, 0
	mov r8, r0
	mov r0, sp
	movs r1, 0
	movs r2, 0x10
	bl memset
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r4, 0
_0801AA5E:
	lsls r1, r4, 5
	ldr r0, [r7]
	adds r0, r1
	mov r1, sp
	bl sub_801A960
	adds r1, r0, 0
	ldr r0, [r5]
	cmp r1, r0
	beq _0801AA78
	str r1, [r5]
	movs r2, 0x1
	mov r8, r2
_0801AA78:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801AA5E
	mov r0, sp
	mov r1, r9
	bl sub_801AA08
	cmp r0, 0
	bne _0801AA9C
	mov r3, r8
	cmp r3, 0x1
	beq _0801AAC4
	movs r0, 0
	b _0801AAC6
	.pool
_0801AA9C:
	adds r1, r6, 0
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	adds r0, r1
	ldr r1, [r6, 0x8]
	adds r0, r1
	ldr r1, [r6, 0xC]
	adds r0, r1
	str r0, [r6, 0xC]
_0801AAC4:
	movs r0, 0x1
_0801AAC6:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA30

	thumb_func_start sub_801AAD4
sub_801AAD4: @ 801AAD4
	push {r4-r7,lr}
	movs r0, 0xA
	bl sub_8014210
	movs r4, 0
	movs r7, 0x64
	ldr r6, =gPlayerParty
	ldr r5, =gEnemyParty
_0801AAE4:
	ldr r0, =gSelectedOrderFromParty
	adds r0, r4, r0
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r0, 0
	muls r1, r7
	adds r1, r6
	adds r0, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x64
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801AAE4
	ldr r4, =gPlayerParty
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_0801AB0A:
	adds r0, r4, 0
	bl ZeroMonData
	adds r4, 0x64
	cmp r4, r5
	ble _0801AB0A
	ldr r4, =gPlayerParty
	movs r5, 0
	adds r6, r4, 0
	adds r6, 0x64
_0801AB1E:
	ldr r1, =gEnemyParty
	adds r1, r5, r1
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r4, 0x64
	adds r5, 0x64
	cmp r4, r6
	ble _0801AB1E
	movs r0, 0x32
	bl IncrementGameStat
	bl CalculatePlayerPartyCount
	ldr r0, =gTrainerBattleOpponent_A
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AAD4

	thumb_func_start sub_801AB68
sub_801AB68: @ 801AB68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	ldr r4, [sp, 0x38]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0x1
	mov r10, r1
	ldr r0, =gUnknown_082F0DE4
	mov r8, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	str r3, [sp, 0x14]
	bl FillWindowPixelBuffer
	mov r1, r9
	str r1, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AB68

	thumb_func_start sub_801ABDC
sub_801ABDC: @ 801ABDC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0801ABF4
	cmp r0, 0x1
	beq _0801AC22
	b _0801AC36
_0801ABF4:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	str r5, [sp]
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_801AB68
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0801AC36
_0801AC22:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0801AC36
	strh r0, [r4]
	movs r0, 0x1
	b _0801AC38
_0801AC36:
	movs r0, 0
_0801AC38:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ABDC

	thumb_func_start sub_801AC40
sub_801AC40: @ 801AC40
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801AC40

	thumb_func_start sub_801AC54
sub_801AC54: @ 801AC54
	push {r4,lr}
	sub sp, 0xC
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x33
	bls _0801AC6A
	b _0801AFAE
_0801AC6A:
	lsls r0, 2
	ldr r1, =_0801AC7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801AC7C:
	.4byte _0801AD4C
	.4byte _0801ADFC
	.4byte _0801AE24
	.4byte _0801AE48
	.4byte _0801AE98
	.4byte _0801AFAE
	.4byte _0801AF7C
	.4byte _0801AF58
	.4byte _0801AF7C
	.4byte _0801AF98
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AF24
	.4byte _0801AF40
_0801AD4C:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022C6C
	movs r0, 0x4
	bl AllocZeroed
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0DD0
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	bl reset_temp_tile_data_buffers
	ldr r0, =gUnknown_082F0DD4
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	bne _0801AD8C
	b _0801AFC2
_0801AD8C:
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	bl sub_819789C
	ldr r0, =sub_801AC40
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801ADFC:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_CommStandbyAwaitingOtherPlayer
	movs r2, 0
	bl sub_801ABDC
	cmp r0, 0
	bne _0801AE0E
	b _0801AFAE
_0801AE0E:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE24:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801AE48:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801AE54
	b _0801AFAE
_0801AE54:
	ldr r4, =gBlockSendBuffer
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x20
	bl memset
	ldr r0, =gSelectedOrderFromParty
	ldrb r1, [r0]
	ldrb r0, [r0, 0x1]
	cmn r1, r0
	bne _0801AE78
	movs r0, 0x52
	b _0801AE7A
	.pool
_0801AE78:
	movs r0, 0x51
_0801AE7A:
	strb r0, [r4]
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0x20
	bl SendBlock
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE98:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0801AEA6
	b _0801AFAE
_0801AEA6:
	ldr r1, =gBlockRecvBuffer
	ldrh r0, [r1]
	cmp r0, 0x51
	bne _0801AEE0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x51
	bne _0801AEE0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x32
	b _0801AF16
	.pool
_0801AEE0:
	bl sub_800AC34
	ldr r4, =gBlockRecvBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 16
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x52
	bne _0801AF0C
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x6
	b _0801AF16
	.pool
_0801AF0C:
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x8
_0801AF16:
	strb r1, [r0]
	bl ResetBlockReceivedFlags
	b _0801AFAE
	.pool
_0801AF24:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801AFAE
	bl sub_800ADF8
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AF40:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =sub_801AAD4
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF58:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_RefusedBattle
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF7C:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801AFAE
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
_0801AF8A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0801AFAE
	.pool
_0801AF98:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_BattleWasRefused
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
_0801AFAE:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801AFC2:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AC54

	.align 2, 0 @ Don't pad with nop
