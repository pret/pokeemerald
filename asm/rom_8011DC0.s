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
	bl ListMenu_ProcessInput
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
	bl ListMenu_ProcessInput
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
	bl IsLinkTaskFinished
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

	thumb_func_start sub_801AFD8
sub_801AFD8: @ 801AFD8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x0000322c
	adds r1, r0
	ldr r2, =0x050000db
	mov r0, sp
	bl CpuSet
	bl sub_801B180
	bl sub_811F8BC
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AFD8

	thumb_func_start sub_801B00C
sub_801B00C: @ 801B00C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B00C

	thumb_func_start sav1_get_mevent_buffer_1
sav1_get_mevent_buffer_1: @ 801B020
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sav1_get_mevent_buffer_1

	thumb_func_start sav1_get_mevent_buffer_2
sav1_get_mevent_buffer_2: @ 801B034
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sav1_get_mevent_buffer_2

	thumb_func_start sub_801B044
sub_801B044: @ 801B044
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000356c
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B044

	thumb_func_start sub_801B058
sub_801B058: @ 801B058
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003564
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B058

	thumb_func_start sub_801B06C
sub_801B06C: @ 801B06C
	push {lr}
	bl sub_801B14C
	pop {r0}
	bx r0
	thumb_func_end sub_801B06C

	thumb_func_start sub_801B078
sub_801B078: @ 801B078
	push {r4-r7,lr}
	adds r7, r0, 0
	bl sub_801B114
	cmp r0, 0
	beq _0801B0C4
	bl sub_801B14C
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x00003230
	adds r0, r5
	movs r6, 0xDE
	lsls r6, 1
	adds r1, r7, 0
	adds r2, r6, 0
	bl memcpy
	ldr r0, [r4]
	adds r0, r5
	adds r1, r6, 0
	bl CalcCRC16WithTable
	ldr r1, [r4]
	ldr r2, =0x0000322c
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	str r0, [r1]
	movs r0, 0x1
	b _0801B0C6
	.pool
_0801B0C4:
	movs r0, 0
_0801B0C6:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B078

	thumb_func_start sub_801B0CC
sub_801B0CC: @ 801B0CC
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003230
	adds r0, r1
	movs r1, 0xDE
	lsls r1, 1
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldr r4, [r4]
	ldr r2, =0x0000322c
	adds r1, r4, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _0801B10C
	ldr r1, =0x00003230
	adds r0, r4, r1
	bl sub_801B114
	cmp r0, 0
	beq _0801B10C
	movs r0, 0x1
	b _0801B10E
	.pool
_0801B10C:
	movs r0, 0
_0801B10E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B0CC

	thumb_func_start sub_801B114
sub_801B114: @ 801B114
	push {lr}
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801B120
	movs r0, 0x1
	b _0801B122
_0801B120:
	movs r0, 0
_0801B122:
	pop {r1}
	bx r1
	thumb_func_end sub_801B114

	thumb_func_start sub_801B128
sub_801B128: @ 801B128
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r0, r1
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0801B144
	movs r0, 0x1
	b _0801B146
	.pool
_0801B144:
	movs r0, 0
_0801B146:
	pop {r1}
	bx r1
	thumb_func_end sub_801B128

	thumb_func_start sub_801B14C
sub_801B14C: @ 801B14C
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0
	str r4, [sp]
	bl sub_801B00C
	adds r1, r0, 0
	ldr r2, =0x0500006f
	mov r0, sp
	bl CpuSet
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000322c
	adds r0, r1
	str r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B14C

	thumb_func_start sub_801B180
sub_801B180: @ 801B180
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801B044
	adds r1, r0, 0
	ldr r2, =0x05000001
	mov r0, sp
	bl CpuSet
	bl sub_801DBC0
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B180

	thumb_func_start sub_801B1A4
sub_801B1A4: @ 801B1A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r4, r0, r1
	bl sub_801B0CC
	cmp r0, 0
	bne _0801B1C4
_0801B1B8:
	movs r0, 0
	b _0801B1DC
	.pool
_0801B1C4:
	movs r2, 0
	ldr r3, =0x000001bb
_0801B1C8:
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0801B1B8
	adds r2, 0x1
	cmp r2, r3
	bls _0801B1C8
	movs r0, 0x1
_0801B1DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B1A4

	thumb_func_start sub_801B1E8
sub_801B1E8: @ 801B1E8
	push {lr}
	bl sub_801B330
	bl sub_801B368
	bl sub_801B9F8
	bl ClearRamScript
	bl sub_809D4D8
	bl sub_809D570
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bec
	adds r0, r1
	bl ClearEReaderTrainer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B1E8

	thumb_func_start sub_801B21C
sub_801B21C: @ 801B21C
	push {r4-r7,lr}
	adds r7, r0, 0
	bl sub_801B2CC
	cmp r0, 0
	beq _0801B274
	bl sub_801B1E8
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x000033f0
	adds r0, r5
	movs r6, 0xA6
	lsls r6, 1
	adds r1, r7, 0
	adds r2, r6, 0
	bl memcpy
	ldr r0, [r4]
	adds r0, r5
	adds r1, r6, 0
	bl CalcCRC16WithTable
	ldr r1, [r4]
	ldr r3, =0x000033ec
	adds r2, r1, r3
	lsls r0, 16
	lsrs r0, 16
	str r0, [r2]
	movs r0, 0xD5
	lsls r0, 6
	adds r2, r1, r0
	adds r1, r5
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x6]
	movs r0, 0x1
	b _0801B276
	.pool
_0801B274:
	movs r0, 0
_0801B276:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B21C

	thumb_func_start sub_801B27C
sub_801B27C: @ 801B27C
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r1, =0x000033ec
	adds r4, r0, r1
	adds r1, 0x4
	adds r0, r1
	movs r1, 0xA6
	lsls r1, 1
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4]
	cmp r1, r0
	bne _0801B2C4
	ldr r0, [r5]
	ldr r1, =0x000033f0
	adds r0, r1
	bl sub_801B2CC
	cmp r0, 0
	beq _0801B2C4
	bl sub_80991F8
	cmp r0, 0
	beq _0801B2C4
	movs r0, 0x1
	b _0801B2C6
	.pool
_0801B2C4:
	movs r0, 0
_0801B2C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801B27C

	thumb_func_start sub_801B2CC
sub_801B2CC: @ 801B2CC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B302
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x2
	bhi _0801B302
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0801B2F0
	cmp r0, 0x40
	beq _0801B2F0
	cmp r0, 0x80
	bne _0801B302
_0801B2F0:
	lsls r0, r1, 26
	lsrs r0, 28
	cmp r0, 0x7
	bhi _0801B302
	ldrb r0, [r2, 0x9]
	cmp r0, 0x7
	bhi _0801B302
	movs r0, 0x1
	b _0801B304
_0801B302:
	movs r0, 0
_0801B304:
	pop {r1}
	bx r1
	thumb_func_end sub_801B2CC

	thumb_func_start sub_801B308
sub_801B308: @ 801B308
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0801B328
	movs r0, 0x1
	b _0801B32A
	.pool
_0801B328:
	movs r0, 0
_0801B32A:
	pop {r1}
	bx r1
	thumb_func_end sub_801B308

	thumb_func_start sub_801B330
sub_801B330: @ 801B330
	push {r4,r5,lr}
	sub sp, 0x4
	movs r5, 0
	str r5, [sp]
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r0, =0x000033f0
	adds r1, r0
	ldr r2, =0x05000053
	mov r0, sp
	bl CpuSet
	ldr r0, [r4]
	ldr r1, =0x000033ec
	adds r0, r1
	str r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B330

	thumb_func_start sub_801B368
sub_801B368: @ 801B368
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0
	str r4, [sp]
	bl sav1_get_mevent_buffer_2
	adds r1, r0, 0
	ldr r2, =0x05000009
	mov r0, sp
	bl CpuSet
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000353c
	adds r0, r1
	str r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B368

	thumb_func_start sub_801B39C
sub_801B39C: @ 801B39C
	push {lr}
	bl sub_801B27C
	cmp r0, 0
	bne _0801B3AA
	movs r0, 0
	b _0801B3B4
_0801B3AA:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrh r0, [r0]
_0801B3B4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B39C

	thumb_func_start sub_801B3C0
sub_801B3C0: @ 801B3C0
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2, 0x8]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _0801B3D4
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x8]
_0801B3D4:
	pop {r0}
	bx r0
	thumb_func_end sub_801B3C0

	thumb_func_start sub_801B3D8
sub_801B3D8: @ 801B3D8
	push {lr}
	lsls r0, 16
	ldr r1, =0xfc180000
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x13
	bls _0801B3F0
	movs r0, 0
	b _0801B3F2
	.pool
_0801B3F0:
	movs r0, 0x1
_0801B3F2:
	pop {r1}
	bx r1
	thumb_func_end sub_801B3D8

	thumb_func_start sub_801B3F8
sub_801B3F8: @ 801B3F8
	push {r4,lr}
	bl sub_801B39C
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_801B3D8
	cmp r0, 0
	beq _0801B430
	ldr r1, =gUnknown_082F0DE8
	ldr r2, =0xfffffc18
	adds r0, r4, r2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801B430
	movs r0, 0x1
	b _0801B432
	.pool
_0801B430:
	movs r0, 0
_0801B432:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B3F8

	thumb_func_start sub_801B438
sub_801B438: @ 801B438
	push {lr}
	movs r3, 0
	cmp r3, r1
	bge _0801B45A
	adds r2, r0, 0
	adds r2, 0x8
_0801B444:
	ldrh r0, [r2, 0xE]
	cmp r0, 0
	beq _0801B452
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B452
	adds r3, 0x1
_0801B452:
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _0801B444
_0801B45A:
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end sub_801B438

	thumb_func_start sub_801B460
sub_801B460: @ 801B460
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r2
	bge _0801B49A
	ldrh r6, [r4, 0x2]
	movs r0, 0x16
	adds r0, r5
	mov r12, r0
_0801B474:
	lsls r3, r1, 1
	mov r7, r12
	ldrh r0, [r7]
	cmp r0, r6
	beq _0801B48C
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r3
	ldrh r0, [r0]
	ldrh r3, [r4]
	cmp r0, r3
	bne _0801B490
_0801B48C:
	movs r0, 0x1
	b _0801B49C
_0801B490:
	movs r7, 0x2
	add r12, r7
	adds r1, 0x1
	cmp r1, r2
	blt _0801B474
_0801B49A:
	movs r0, 0
_0801B49C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B460

	thumb_func_start sub_801B4A4
sub_801B4A4: @ 801B4A4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0801B4C4
	ldrh r1, [r1]
	cmp r1, 0
	beq _0801B4C4
	ldr r0, =0x0000019b
	cmp r1, r0
	bhi _0801B4C4
	movs r0, 0x1
	b _0801B4C6
	.pool
_0801B4C4:
	movs r0, 0
_0801B4C6:
	pop {r1}
	bx r1
	thumb_func_end sub_801B4A4

	thumb_func_start sub_801B4CC
sub_801B4CC: @ 801B4CC
	push {lr}
	bl sub_801B27C
	cmp r0, 0
	beq _0801B500
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r0, =0x000033f0
	adds r2, r3, r0
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B500
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r3, r1
	ldrb r1, [r2, 0x9]
	bl sub_801B438
	b _0801B502
	.pool
_0801B500:
	movs r0, 0
_0801B502:
	pop {r1}
	bx r1
	thumb_func_end sub_801B4CC

	thumb_func_start sub_801B508
sub_801B508: @ 801B508
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r4, [r0, 0x9]
	adds r0, r5, 0
	bl sub_801B4A4
	cmp r0, 0
	beq _0801B572
	ldr r0, [r6]
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r1
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_801B460
	cmp r0, 0
	beq _0801B54C
	b _0801B572
	.pool
_0801B540:
	ldrh r0, [r5, 0x2]
	strh r0, [r1]
	ldrh r0, [r5]
	strh r0, [r2]
	movs r0, 0x1
	b _0801B574
_0801B54C:
	movs r3, 0
	cmp r3, r4
	bge _0801B572
	ldr r0, [r6]
	ldr r6, =0x00003548
	adds r2, r0, r6
	adds r6, 0xE
	adds r1, r0, r6
_0801B55C:
	ldrh r0, [r2, 0xE]
	cmp r0, 0
	bne _0801B568
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B540
_0801B568:
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r4
	blt _0801B55C
_0801B572:
	movs r0, 0
_0801B574:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B508

	thumb_func_start sub_801B580
sub_801B580: @ 801B580
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [sp]
	ldr r2, =0x05000019
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	ldr r0, =0x00000101
	str r0, [r5]
	movs r0, 0x1
	strh r0, [r5, 0x4]
	str r0, [r5, 0x8]
	cmp r4, 0
	beq _0801B5C0
	movs r0, 0x5
	strh r0, [r5, 0xC]
	ldr r0, =0x00000201
	b _0801B5C8
	.pool
_0801B5C0:
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r0, 0x80
	lsls r0, 2
_0801B5C8:
	str r0, [r5, 0x10]
	bl sub_801B27C
	cmp r0, 0
	beq _0801B5FC
	bl sav1_get_mevent_buffer_1
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	bl sav1_get_mevent_buffer_2
	adds r1, r5, 0
	adds r1, 0x20
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sav1_get_mevent_buffer_1
	ldrb r1, [r0, 0x9]
	adds r0, r5, 0
	adds r0, 0x44
	strb r1, [r0]
	b _0801B5FE
_0801B5FC:
	strh r0, [r5, 0x14]
_0801B5FE:
	adds r4, r5, 0
	adds r4, 0x4C
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	adds r6, r5, 0
	adds r6, 0x45
	adds r7, r5, 0
	adds r7, 0x50
	movs r1, 0x5C
	adds r1, r5
	mov r9, r1
	movs r2, 0x60
	adds r2, r5
	mov r10, r2
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003564
	adds r2, r0, r3
	adds r1, r5, 0
	adds r1, 0x16
	movs r3, 0x3
_0801B628:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0801B628
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0xA
	adds r0, r4, 0
	bl CopyTrainerId
	mov r2, r8
	ldr r1, [r2]
	adds r0, r6, 0
	bl StringCopy
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00002bb0
	adds r2, r0, r3
	adds r1, r7, 0
	movs r3, 0x5
_0801B658:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0801B658
	ldr r1, =RomHeaderGameCode
	mov r0, r9
	movs r2, 0x4
	bl memcpy
	ldr r0, =RomHeaderSoftwareVersion
	ldrb r0, [r0]
	mov r4, r10
	strb r0, [r4]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B580

	thumb_func_start sub_801B6A0
sub_801B6A0: @ 801B6A0
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r1, [r2]
	ldr r0, =0x00000101
	cmp r1, r0
	bne _0801B6DC
	ldrh r1, [r2, 0x4]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0801B6DC
	ldr r0, [r2, 0x8]
	ands r0, r3
	cmp r0, 0
	beq _0801B6DC
	cmp r4, 0
	bne _0801B6E4
	ldrh r1, [r2, 0xC]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0801B6DC
	ldr r0, [r2, 0x10]
	movs r1, 0xE0
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	bne _0801B6E4
_0801B6DC:
	movs r0, 0
	b _0801B6E6
	.pool
_0801B6E4:
	movs r0, 0x1
_0801B6E6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B6A0

	thumb_func_start sub_801B6EC
sub_801B6EC: @ 801B6EC
	push {lr}
	ldrh r1, [r1, 0x14]
	cmp r1, 0
	bne _0801B6F8
	movs r0, 0
	b _0801B704
_0801B6F8:
	ldrh r0, [r0]
	cmp r0, r1
	beq _0801B702
	movs r0, 0x2
	b _0801B704
_0801B702:
	movs r0, 0x1
_0801B704:
	pop {r1}
	bx r1
	thumb_func_end sub_801B6EC

	thumb_func_start sub_801B708
sub_801B708: @ 801B708
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r4, 0
	adds r5, 0x20
	adds r4, 0x44
	ldrb r1, [r4]
	adds r0, r5, 0
	bl sub_801B438
	ldrb r2, [r4]
	subs r4, r2, r0
	cmp r4, 0
	bne _0801B728
	movs r0, 0x1
	b _0801B742
_0801B728:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_801B460
	cmp r0, 0
	beq _0801B738
	movs r0, 0x3
	b _0801B742
_0801B738:
	cmp r4, 0x1
	beq _0801B740
	movs r0, 0x2
	b _0801B742
_0801B740:
	movs r0, 0x4
_0801B742:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801B708

	thumb_func_start sub_801B748
sub_801B748: @ 801B748
	push {r4,lr}
	movs r3, 0
	adds r2, r0, 0
	adds r2, 0x16
_0801B750:
	ldrh r0, [r2]
	ldrh r4, [r1]
	cmp r0, r4
	beq _0801B75C
	movs r0, 0
	b _0801B768
_0801B75C:
	adds r1, 0x2
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _0801B750
	movs r0, 0x1
_0801B768:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B748

	thumb_func_start sub_801B770
sub_801B770: @ 801B770
	push {lr}
	adds r2, r0, 0
	adds r2, 0x20
	adds r0, 0x44
	ldrb r1, [r0]
	adds r0, r2, 0
	bl sub_801B438
	pop {r1}
	bx r1
	thumb_func_end sub_801B770

	thumb_func_start sub_801B784
sub_801B784: @ 801B784
	push {lr}
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _0801B7D0
	lsls r0, r1, 2
	ldr r1, =_0801B79C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B79C:
	.4byte _0801B7B0
	.4byte _0801B7B4
	.4byte _0801B7B8
	.4byte _0801B7BC
	.4byte _0801B7C8
_0801B7B0:
	ldrh r0, [r2, 0x20]
	b _0801B7D2
_0801B7B4:
	ldrh r0, [r2, 0x22]
	b _0801B7D2
_0801B7B8:
	ldrh r0, [r2, 0x24]
	b _0801B7D2
_0801B7BC:
	adds r0, r2, 0
	bl sub_801B770
	lsls r0, 16
	lsrs r0, 16
	b _0801B7D2
_0801B7C8:
	adds r0, r2, 0
	adds r0, 0x44
	ldrb r0, [r0]
	b _0801B7D2
_0801B7D0:
	movs r0, 0
_0801B7D2:
	pop {r1}
	bx r1
	thumb_func_end sub_801B784

	thumb_func_start sub_801B7D8
sub_801B7D8: @ 801B7D8
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	adds r3, r2, 0
	cmp r0, 0x2
	bne _0801B850
	movs r2, 0
	cmp r4, 0x4
	bhi _0801B83A
	lsls r0, r4, 2
	ldr r1, =_0801B80C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B80C:
	.4byte _0801B820
	.4byte _0801B828
	.4byte _0801B834
	.4byte _0801B83A
	.4byte _0801B83A
_0801B820:
	ldr r0, [r3]
	movs r1, 0xD5
	lsls r1, 6
	b _0801B838
_0801B828:
	ldr r0, [r3]
	ldr r1, =0x00003542
	b _0801B838
	.pool
_0801B834:
	ldr r0, [r3]
	ldr r1, =0x00003544
_0801B838:
	adds r2, r0, r1
_0801B83A:
	cmp r2, 0
	beq _0801B850
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x000003e7
	cmp r0, r1
	bls _0801B850
	strh r1, [r2]
_0801B850:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B7D8

	thumb_func_start mevent_081445C0
mevent_081445C0: @ 801B860
	push {lr}
	cmp r0, 0x4
	bhi _0801B938
	lsls r0, 2
	ldr r1, =_0801B874
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B874:
	.4byte _0801B888
	.4byte _0801B8AC
	.4byte _0801B8D0
	.4byte _0801B8F4
	.4byte _0801B918
_0801B888:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0]
	b _0801B93A
	.pool
_0801B8AC:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0, 0x2]
	b _0801B93A
	.pool
_0801B8D0:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0, 0x4]
	b _0801B93A
	.pool
_0801B8F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B938
	bl sub_801B4CC
	lsls r0, 16
	lsrs r0, 16
	b _0801B93A
	.pool
_0801B918:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r2, r0, r1
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B938
	ldrb r0, [r2, 0x9]
	b _0801B93A
	.pool
_0801B938:
	movs r0, 0
_0801B93A:
	pop {r1}
	bx r1
	thumb_func_end mevent_081445C0

	thumb_func_start sub_801B940
sub_801B940: @ 801B940
	ldr r1, =gUnknown_02022C70
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801B940

	thumb_func_start sub_801B94C
sub_801B94C: @ 801B94C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0, 0
	ldr r5, =gUnknown_02022C70
	movs r0, 0
	str r0, [r5]
	cmp r4, 0
	beq _0801B98A
	bl sub_801B27C
	cmp r0, 0
	beq _0801B988
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r4
	bne _0801B988
	movs r0, 0x1
	str r0, [r5]
	b _0801B98A
	.pool
_0801B988:
	movs r0, 0
_0801B98A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801B94C

	thumb_func_start sub_801B990
sub_801B990: @ 801B990
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02022C70
	ldr r0, [r0]
	cmp r0, 0
	beq _0801B9EC
	cmp r2, 0x1
	beq _0801B9DC
	cmp r2, 0x1
	bcc _0801B9C0
	cmp r2, 0x2
	bne _0801B9EC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003584
	adds r2, r0
	movs r0, 0x2
	b _0801B9CA
	.pool
_0801B9C0:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003570
	adds r2, r0
	movs r0, 0
_0801B9CA:
	movs r3, 0x5
	bl sub_801BA8C
	b _0801B9EC
	.pool
_0801B9DC:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003570
	adds r2, r0
	movs r0, 0x1
	movs r3, 0x5
	bl sub_801BA8C
_0801B9EC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B990

	thumb_func_start sub_801B9F8
sub_801B9F8: @ 801B9F8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003570
	adds r1, r0
	ldr r2, =0x0500000a
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B9F8

	thumb_func_start sub_801BA24
sub_801BA24: @ 801BA24
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r2
	bge _0801BA46
	ldr r0, [r4]
	cmp r0, r5
	beq _0801BA46
	adds r3, r4, 0
_0801BA38:
	adds r3, 0x4
	adds r1, 0x1
	cmp r1, r2
	bge _0801BA46
	ldr r0, [r3]
	cmp r0, r5
	bne _0801BA38
_0801BA46:
	cmp r1, r2
	bne _0801BA68
	subs r3, r1, 0x1
	cmp r3, 0
	ble _0801BA62
	lsls r0, r3, 2
	subs r0, 0x4
	adds r2, r0, r4
_0801BA56:
	ldr r0, [r2]
	str r0, [r2, 0x4]
	subs r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bgt _0801BA56
_0801BA62:
	str r5, [r4]
	movs r0, 0x1
	b _0801BA84
_0801BA68:
	adds r3, r1, 0
	cmp r3, 0
	ble _0801BA80
	lsls r0, r3, 2
	subs r0, 0x4
	adds r2, r0, r4
_0801BA74:
	ldr r0, [r2]
	str r0, [r2, 0x4]
	subs r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bgt _0801BA74
_0801BA80:
	str r5, [r4]
	movs r0, 0
_0801BA84:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801BA24

	thumb_func_start sub_801BA8C
sub_801BA8C: @ 801BA8C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	bl sub_801BA24
	cmp r0, 0
	beq _0801BAA4
	adds r0, r4, 0
	bl sub_801B7D8
_0801BAA4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BA8C

	thumb_func_start sub_801BAAC
sub_801BAAC: @ 801BAAC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	beq _0801BAC8
	cmp r6, 0
	beq _0801BAC8
	ldr r7, =gUnknown_02022C74
	ldr r0, =0x0000145c
	bl AllocZeroed
	str r0, [r7]
	cmp r0, 0
	bne _0801BAD4
_0801BAC8:
	movs r0, 0
	b _0801BB3E
	.pool
_0801BAD4:
	movs r4, 0xA6
	lsls r4, 1
	adds r1, r5, 0
	adds r2, r4, 0
	bl memcpy
	ldr r1, [r7]
	adds r1, r4
	adds r0, r6, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 26
	lsrs r0, 28
	cmp r0, 0x7
	bls _0801BB06
	movs r0, 0x3D
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x8]
_0801BB06:
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x2
	bls _0801BB1A
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x8]
_0801BB1A:
	ldr r1, [r7]
	ldrb r0, [r1, 0x9]
	cmp r0, 0x7
	bls _0801BB26
	movs r0, 0
	strb r0, [r1, 0x9]
_0801BB26:
	ldr r0, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r2, r0, r1
	ldrb r0, [r0, 0x8]
	lsls r0, 26
	lsrs r0, 28
	lsls r0, 4
	ldr r1, =gUnknown_082F1D60
	adds r0, r1
	str r0, [r2]
	movs r0, 0x1
_0801BB3E:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BAAC

	thumb_func_start sub_801BB48
sub_801BB48: @ 801BB48
	push {r4,lr}
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	cmp r0, 0
	beq _0801BB64
	ldr r2, =0x0000145c
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801BB64:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801BB48

	thumb_func_start sub_801BB74
sub_801BB74: @ 801BB74
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	cmp r0, 0
	bne _0801BB8C
	movs r0, 0x1
	negs r0, r0
	b _0801BD98
	.pool
_0801BB8C:
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _0801BB9A
	b _0801BD70
_0801BB9A:
	lsls r0, 2
	ldr r1, =_0801BBA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801BBA8:
	.4byte _0801BBC8
	.4byte _0801BBDA
	.4byte _0801BBE8
	.4byte _0801BC8C
	.4byte _0801BD14
	.4byte _0801BD1A
	.4byte _0801BD34
	.4byte _0801BD3A
_0801BBC8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801BD86
_0801BBDA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801BBE6
	b _0801BD86
_0801BBE6:
	b _0801BD96
_0801BBE8:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0x8
	bl decompress_and_copy_tile_data_to_vram
	ldr r4, =gUnknown_082F0E1C
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBB
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBC
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r4, 0x10
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xBD
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	b _0801BD86
	.pool
_0801BC8C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _0801BC9A
	b _0801BD96
_0801BC9A:
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldr r4, =0x0000045c
	adds r1, r4
	bl LZ77UnCompWram
	ldr r1, [r5]
	adds r1, r4
	movs r2, 0x1E
	str r2, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	str r6, [sp, 0xC]
	str r2, [sp, 0x10]
	str r0, [sp, 0x14]
	movs r0, 0x1
	str r0, [sp, 0x18]
	movs r0, 0x8
	str r0, [sp, 0x1C]
	str r6, [sp, 0x20]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801BD86
	.pool
_0801BD14:
	bl sub_801BEF8
	b _0801BD86
_0801BD1A:
	movs r0, 0
	bl sub_801C178
	movs r0, 0x1
	bl sub_801C178
	movs r0, 0x2
	bl sub_801C178
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _0801BD86
_0801BD34:
	bl LoadMonIconPalettes
	b _0801BD86
_0801BD3A:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	bl sub_801C4C0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0801BD86
	.pool
_0801BD70:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0801BD96
	ldr r0, [r5]
	adds r0, r4
	strb r1, [r0]
	movs r0, 0x1
	b _0801BD98
_0801BD86:
	ldr r0, =gUnknown_02022C74
	ldr r1, [r0]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0801BD96:
	movs r0, 0
_0801BD98:
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BB74

	thumb_func_start sub_801BDA4
sub_801BDA4: @ 801BDA4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r2, r0, 0
	ldr r5, =gUnknown_02022C74
	ldr r0, [r5]
	cmp r0, 0
	bne _0801BDBC
	movs r0, 0x1
	negs r0, r0
	b _0801BEEC
	.pool
_0801BDBC:
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _0801BDCA
	b _0801BEC4
_0801BDCA:
	lsls r0, 2
	ldr r1, =_0801BDD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801BDD8:
	.4byte _0801BDF0
	.4byte _0801BE02
	.4byte _0801BE0E
	.4byte _0801BE56
	.4byte _0801BE94
	.4byte _0801BE9E
_0801BDF0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801BEDA
_0801BE02:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801BEDA
	b _0801BEEA
_0801BE0E:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801BEDA
_0801BE56:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r1, 0xBD
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r1, 0xBB
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _0801BEDA
	.pool
_0801BE94:
	bl sub_801C61C
	bl FreeMonIconPalettes
	b _0801BEDA
_0801BE9E:
	ldr r0, =gUnknown_02022C60
	ldrb r0, [r0]
	adds r1, r2, 0
	bl sub_80186EC
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0801BEDA
	.pool
_0801BEC4:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0801BEEA
	ldr r0, [r5]
	adds r0, r4
	strb r1, [r0]
	movs r0, 0x1
	b _0801BEEC
_0801BEDA:
	ldr r0, =gUnknown_02022C74
	ldr r1, [r0]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0801BEEA:
	movs r0, 0
_0801BEEC:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801BDA4

	thumb_func_start sub_801BEF8
sub_801BEF8: @ 801BEF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r5, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0x6
	bl memset
	ldr r4, =gUnknown_02022C74
	ldr r1, [r4]
	ldr r2, =0x0000018b
	adds r0, r1, r2
	adds r1, 0xA
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	ldr r3, =0x000001b3
	adds r1, r0, r3
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [r4]
	movs r2, 0xDA
	lsls r2, 1
	adds r0, r1, r2
	adds r1, 0x32
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	movs r3, 0xEE
	lsls r3, 1
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	ldr r2, =0x000f423f
	cmp r0, r2
	bls _0801BF54
	str r2, [r1, 0x4]
_0801BF54:
	ldr r1, [r4]
	ldr r2, =0x000001dd
	adds r0, r1, r2
	ldr r1, [r1, 0x4]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	adds r6, r4, 0
_0801BF66:
	ldr r2, [r6]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r5
	adds r0, r4, r2
	movs r3, 0xF2
	lsls r3, 1
	adds r0, r3
	adds r1, r2
	adds r1, 0x5A
	movs r2, 0x28
	bl memcpy
	ldr r1, [r6]
	movs r0, 0x83
	lsls r0, 2
	adds r1, r0
	adds r1, r4
	movs r2, 0x1
	negs r2, r2
	adds r7, r2, 0
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _0801BF66
	ldr r6, =gUnknown_02022C74
	ldr r1, [r6]
	movs r3, 0xA2
	lsls r3, 2
	adds r0, r1, r3
	adds r1, 0xFA
	movs r2, 0x28
	bl memcpy
	ldr r0, [r6]
	movs r4, 0xAC
	lsls r4, 2
	adds r0, r4
	movs r1, 0x1
	negs r1, r1
	adds r4, r1, 0
	movs r1, 0xFF
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, 0x8]
	lsls r0, 30
	lsrs r0, 30
	cmp r0, 0x1
	beq _0801C018
	cmp r0, 0x1
	bgt _0801BFF0
	cmp r0, 0
	beq _0801BFF6
	b _0801C168
	.pool
_0801BFF0:
	cmp r0, 0x2
	beq _0801C028
	b _0801C168
_0801BFF6:
	ldr r2, =0x000002b1
	adds r0, r1, r2
	movs r3, 0x91
	lsls r3, 1
	adds r1, r3
	movs r2, 0x28
	bl memcpy
	ldr r1, [r6]
	ldr r0, =0x000002d9
	adds r1, r0
	b _0801C01C
	.pool
_0801C018:
	ldr r2, =0x000002b1
	adds r1, r2
_0801C01C:
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	b _0801C168
	.pool
_0801C028:
	ldr r3, =0x000002b1
	adds r0, r1, r3
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	mov r3, sp
	ldr r1, [r6]
	movs r4, 0xA6
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	ldr r2, =0x000003e7
	cmp r0, r2
	bls _0801C046
	adds r0, r2, 0
_0801C046:
	strh r0, [r3]
	mov r3, sp
	movs r4, 0xA7
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r2
	bls _0801C058
	adds r0, r2, 0
_0801C058:
	strh r0, [r3, 0x2]
	mov r3, sp
	movs r4, 0xA8
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r2
	bls _0801C06A
	adds r0, r2, 0
_0801C06A:
	strh r0, [r3, 0x4]
	movs r5, 0
_0801C06E:
	lsls r4, r5, 1
	adds r4, r5
	lsls r4, 4
	movs r0, 0xB7
	lsls r0, 2
	adds r4, r0
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x2A
	movs r1, 0xFF
	movs r2, 0x4
	bl memset
	ldr r0, [r6]
	adds r0, r4
	adds r0, 0x1
	movs r1, 0xFF
	movs r2, 0x29
	bl memset
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _0801C06E
	movs r5, 0
	movs r6, 0
	ldr r1, =gUnknown_02022C74
	mov r8, r1
	movs r2, 0x91
	lsls r2, 1
	mov r10, r2
	ldr r7, =0x00000175
	movs r3, 0xB7
	lsls r3, 2
	mov r9, r3
_0801C0B6:
	mov r4, r8
	ldr r2, [r4]
	mov r0, r10
	adds r1, r2, r0
	adds r0, r1, r5
	ldrb r3, [r0]
	cmp r3, 0xF7
	beq _0801C0F8
	ldr r1, =0x00000175
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	adds r0, r6, r0
	ldr r4, =0x000002dd
	adds r1, r2, r4
	adds r1, r0
	strb r3, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	b _0801C15E
	.pool
_0801C0F8:
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	cmp r3, 0x2
	bls _0801C108
	adds r0, r5, 0x2
	lsls r0, 16
	b _0801C15C
_0801C108:
	adds r0, r2, r7
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	add r0, r9
	adds r0, r2, r0
	adds r0, 0x2A
	lsls r1, r3, 1
	add r1, sp
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, r7
	ldrb r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r0, r1, r0
	adds r4, r5, 0x2
	add r1, r10
	adds r1, r4
	ldrb r1, [r1]
	add r0, r9
	strb r1, [r0]
	mov r2, r8
	ldr r1, [r2]
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0x7
	bhi _0801C168
	movs r6, 0
	lsls r0, r4, 16
_0801C15C:
	lsrs r5, r0, 16
_0801C15E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x27
	bls _0801C0B6
_0801C168:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BEF8

	thumb_func_start sub_801C178
sub_801C178: @ 801C178
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	movs r0, 0
	str r0, [sp, 0xC]
	ldr r7, =gUnknown_02022C74
	ldr r0, [r7]
	lsls r1, r4, 1
	movs r2, 0xBB
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	ldrh r0, [r0]
	lsls r6, r0, 24
	lsrs r5, r6, 24
	adds r0, r5, 0
	bl PutWindowTilemap
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0x1
	beq _0801C2A0
	cmp r4, 0x1
	bgt _0801C1C4
	cmp r4, 0
	beq _0801C1D0
	mov r9, r6
	b _0801C498
	.pool
_0801C1C4:
	mov r0, r8
	cmp r0, 0x2
	bne _0801C1CC
	b _0801C304
_0801C1CC:
	mov r9, r6
	b _0801C498
_0801C1D0:
	ldr r2, [r7]
	movs r1, 0xB8
	lsls r1, 1
	mov r10, r1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	mov r8, r0
	add r1, r8
	str r1, [sp]
	ldr r1, [sp, 0xC]
	str r1, [sp, 0x4]
	ldr r0, =0x0000018b
	adds r2, r0
	str r2, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r4, [r7]
	movs r1, 0xDA
	lsls r1, 1
	mov r9, r1
	add r4, r9
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x3
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xA0
	subs r1, r0
	cmp r1, 0
	bge _0801C22E
	movs r1, 0
_0801C22E:
	lsls r2, r1, 24
	lsrs r2, 24
	ldr r3, [r7]
	mov r1, r10
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r8
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	add r3, r9
	str r3, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	ldr r2, [r7]
	ldr r0, [r2, 0x4]
	mov r9, r6
	cmp r0, 0
	bne _0801C266
	b _0801C498
_0801C266:
	mov r1, r10
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r1, [r0]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r8
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	ldr r1, =0x000001dd
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0xA6
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	b _0801C498
	.pool
_0801C2A0:
	mov r9, r6
_0801C2A2:
	ldr r2, [sp, 0xC]
	lsls r4, r2, 24
	asrs r4, 24
	lsls r3, r4, 4
	adds r3, 0x2
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_02022C74
	ldr r2, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsrs r0, 4
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	adds r1, r0
	str r1, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r4
	movs r1, 0xF2
	lsls r1, 1
	adds r0, r1
	adds r2, r0
	str r2, [sp, 0x8]
	mov r2, r9
	lsrs r0, r2, 24
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r4, 0x1
	lsls r4, 24
	lsrs r0, r4, 24
	str r0, [sp, 0xC]
	asrs r4, 24
	cmp r4, 0x3
	ble _0801C2A2
	b _0801C498
	.pool
_0801C304:
	ldr r4, =gUnknown_082F0E18
	ldr r2, [r7]
	ldrb r0, [r2, 0x8]
	lsls r0, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r3, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r0, 1
	adds r1, r0
	ldr r0, =gUnknown_082F0E10
	mov r10, r0
	add r1, r10
	str r1, [sp]
	ldr r1, [sp, 0xC]
	str r1, [sp, 0x4]
	movs r1, 0xA2
	lsls r1, 2
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	ldr r2, [r7]
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _0801C398
	lsls r0, r1, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r3, [r0]
	adds r3, 0x10
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	add r0, r10
	str r0, [sp]
	ldr r0, [sp, 0xC]
	str r0, [sp, 0x4]
	ldr r1, =0x000002b1
	adds r0, r2, r1
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	mov r9, r6
	b _0801C498
	.pool
_0801C398:
	movs r2, 0
	mov r8, r2
	lsls r0, r1, 30
	lsrs r0, 30
	adds r0, r4
	ldrb r0, [r0]
	adds r4, r0, 0
	adds r4, 0x10
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r7]
	ldr r1, =0x00000175
	adds r0, r1
	mov r9, r6
	ldr r1, [sp, 0xC]
	ldrb r0, [r0]
	cmp r1, r0
	bge _0801C498
	str r5, [sp, 0x10]
	lsls r0, r4, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	mov r10, r2
_0801C3CE:
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r3, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	ldr r1, =gUnknown_082F0E10
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	asrs r6, r0, 24
	lsls r0, r6, 1
	adds r0, r6
	lsls r5, r0, 4
	movs r0, 0xB7
	lsls r0, 2
	adds r4, r5, r0
	adds r3, r4
	adds r3, 0x1
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x10]
	movs r1, 0x3
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r0, r1, r5
	ldr r2, =0x00000306
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0801C482
	adds r1, r4
	adds r1, 0x1
	movs r0, 0x3
	mov r2, r10
	bl GetStringWidth
	add r8, r0
	mov r0, r8
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r3, [r7]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	ldr r1, =gUnknown_082F0E10
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r3, r4
	adds r3, 0x2A
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x10]
	movs r1, 0x3
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r1, r4
	adds r1, 0x2A
	movs r0, 0x3
	mov r2, r10
	bl GetStringWidth
	ldr r1, [r7]
	adds r1, r5
	movs r2, 0xB7
	lsls r2, 2
	adds r1, r2
	ldrb r1, [r1]
	adds r0, r1
	add r8, r0
_0801C482:
	adds r1, r6, 0x1
	lsls r1, 24
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	asrs r1, 24
	ldr r0, [r7]
	ldr r2, =0x00000175
	adds r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _0801C3CE
_0801C498:
	mov r1, r9
	lsrs r0, r1, 24
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C178

	thumb_func_start sub_801C4C0
sub_801C4C0: @ 801C4C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r7, 0
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xA9
	lsls r2, 1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _0801C52C
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =SpriteCallbackDummy
	str r7, [sp]
	str r7, [sp, 0x4]
	movs r2, 0xDC
	movs r3, 0x14
	bl sub_80D2D78
	ldr r1, [r4]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	ldr r2, =gSprites
	ldr r0, [r4]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
_0801C52C:
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _0801C5EE
	ldrb r1, [r1, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801C5EE
	ldr r0, =gUnknown_082F1D00
	bl LoadCompressedSpriteSheetUsingHeap
	ldr r0, [r4]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsrs r0, 4
	lsls r0, 3
	ldr r1, =gUnknown_082F1D08
	adds r0, r1
	bl LoadSpritePalette
	ldr r0, [r4]
	ldrb r0, [r0, 0x9]
	cmp r7, r0
	bcs _0801C5EE
	adds r6, r4, 0
	ldr r0, =0x0000017d
	mov r10, r0
	movs r1, 0
	mov r9, r1
	movs r2, 0xFF
	mov r8, r2
_0801C572:
	ldr r1, [r6]
	lsls r4, r7, 1
	add r1, r10
	adds r1, r4
	ldrb r0, [r1]
	mov r2, r8
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	movs r0, 0xBF
	lsls r0, 1
	adds r1, r0
	adds r1, r4
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	lsls r1, r7, 5
	movs r0, 0xD8
	subs r5, r0, r1
	ldr r0, =gUnknown_082F1D48
	adds r1, r5, 0
	movs r2, 0x90
	movs r3, 0x8
	bl CreateSprite
	ldr r1, [r6]
	add r1, r10
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, 0
	beq _0801C5E0
	bl sub_80D2E84
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	str r2, [sp]
	str r2, [sp, 0x4]
	ldr r1, =SpriteCallbackDummy
	adds r2, r5, 0
	movs r3, 0x88
	bl sub_80D2D78
	ldr r1, [r6]
	movs r2, 0xBF
	lsls r2, 1
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_0801C5E0:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [r6]
	ldrb r0, [r0, 0x9]
	cmp r7, r0
	bcc _0801C572
_0801C5EE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C4C0

	thumb_func_start sub_801C61C
sub_801C61C: @ 801C61C
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, =gUnknown_02022C74
	ldr r0, [r4]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C640
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D2EF8
_0801C640:
	ldr r0, [r4]
	ldrb r2, [r0, 0x9]
	cmp r2, 0
	beq _0801C6B4
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801C6B4
	cmp r5, r2
	bcs _0801C6A4
	adds r6, r4, 0
	ldr r7, =gSprites
_0801C65A:
	ldr r0, [r6]
	lsls r4, r5, 1
	ldr r1, =0x0000017d
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C678
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySprite
_0801C678:
	ldr r0, [r6]
	movs r2, 0xBF
	lsls r2, 1
	adds r0, r2
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801C696
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl sub_80D2EF8
_0801C696:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r6]
	ldrb r0, [r0, 0x9]
	cmp r5, r0
	bcc _0801C65A
_0801C6A4:
	movs r4, 0x80
	lsls r4, 8
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
_0801C6B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C61C

	thumb_func_start sub_801C6C8
sub_801C6C8: @ 801C6C8
	push {r4-r6,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0801C6DE
	ldr r5, =gUnknown_02022C78
	ldr r0, =0x000013a4
	bl AllocZeroed
	str r0, [r5]
	cmp r0, 0
	bne _0801C6EC
_0801C6DE:
	movs r0, 0
	b _0801C71C
	.pool
_0801C6EC:
	movs r6, 0xDE
	lsls r6, 1
	adds r1, r4, 0
	adds r2, r6, 0
	bl memcpy
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	cmp r0, 0x7
	bls _0801C704
	movs r0, 0
	strb r0, [r1, 0x3]
_0801C704:
	ldr r2, [r5]
	adds r3, r2, r6
	ldrb r0, [r2, 0x3]
	lsls r0, 4
	ldr r1, =gUnknown_082F24C8
	adds r0, r1
	str r0, [r3]
	ldr r0, =0x000001c1
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
_0801C71C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801C6C8

	thumb_func_start sub_801C72C
sub_801C72C: @ 801C72C
	push {r4,lr}
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	cmp r0, 0
	beq _0801C748
	ldr r2, =0x000013a4
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801C748:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801C72C

	thumb_func_start sub_801C758
sub_801C758: @ 801C758
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C778
	movs r0, 0x1
	negs r0, r0
	b _0801CA3A
	.pool
_0801C778:
	movs r4, 0xE0
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	lsrs r0, 1
	cmp r0, 0x6
	bls _0801C788
	b _0801CA04
_0801C788:
	lsls r0, 2
	ldr r1, =_0801C798
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801C798:
	.4byte _0801C7B4
	.4byte _0801C7C6
	.4byte _0801C82C
	.4byte _0801C8D4
	.4byte _0801C990
	.4byte _0801C996
	.4byte _0801C9A8
_0801C7B4:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801CA1E
_0801C7C6:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801C7D2
	b _0801CA38
_0801C7D2:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00001a98
	movs r0, 0x44
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x1F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x1B
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	b _0801CA1E
	.pool
_0801C82C:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	movs r1, 0xDE
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x8
	bl decompress_and_copy_tile_data_to_vram
	ldr r4, =gUnknown_082F1DE8
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r2, 0xE4
	lsls r2, 1
	adds r1, r2
	strh r0, [r1]
	adds r4, 0x8
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	movs r3, 0xE5
	lsls r3, 1
	adds r1, r3
	strh r0, [r1]
	b _0801CA1E
	.pool
_0801C8D4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _0801C8E2
	b _0801CA38
_0801C8E2:
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =gUnknown_02022C78
	mov r8, r0
	ldr r0, [r0]
	movs r4, 0xDE
	lsls r4, 1
	adds r0, r4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r4
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r6, 0xE9
	lsls r6, 2
	adds r1, r6
	bl LZ77UnCompWram
	mov r3, r8
	ldr r1, [r3]
	adds r1, r6
	movs r4, 0x1E
	str r4, [sp]
	movs r5, 0x3
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	str r7, [sp, 0xC]
	str r4, [sp, 0x10]
	str r5, [sp, 0x14]
	movs r0, 0x1
	mov r10, r0
	str r0, [sp, 0x18]
	movs r2, 0x8
	mov r9, r2
	str r2, [sp, 0x1C]
	str r7, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	mov r3, r8
	ldr r1, [r3]
	adds r1, r6
	str r4, [sp]
	movs r0, 0x17
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	str r5, [sp, 0xC]
	str r4, [sp, 0x10]
	str r0, [sp, 0x14]
	mov r0, r10
	str r0, [sp, 0x18]
	mov r2, r9
	str r2, [sp, 0x1C]
	str r7, [sp, 0x20]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x3
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0801CA1E
	.pool
_0801C990:
	bl sub_801CDCC
	b _0801CA1E
_0801C996:
	bl sub_801CE7C
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _0801CA1E
_0801C9A8:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r4, =gUnknown_02022C78
	ldr r1, [r4]
	movs r3, 0xE5
	lsls r3, 2
	adds r0, r1, r3
	movs r2, 0xE3
	lsls r2, 1
	adds r1, r2
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r3, =0x000001c1
	adds r2, r1, r3
	movs r1, 0
	strb r0, [r2]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0801CA1E
	.pool
_0801CA04:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801CA38
	ldr r0, [r5]
	adds r0, r4
	ldrb r2, [r0]
	movs r1, 0x1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0801CA3A
_0801CA1E:
	ldr r0, =gUnknown_02022C78
	ldr r2, [r0]
	movs r0, 0xE0
	lsls r0, 1
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 1
	adds r1, 0x1
	lsls r1, 1
	movs r0, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801CA38:
	movs r0, 0
_0801CA3A:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801C758

	thumb_func_start sub_801CA50
sub_801CA50: @ 801CA50
	push {r4,r5,lr}
	sub sp, 0x8
	adds r2, r0, 0
	ldr r5, =gUnknown_02022C78
	ldr r0, [r5]
	cmp r0, 0
	bne _0801CA68
	movs r0, 0x1
	negs r0, r0
	b _0801CC2A
	.pool
_0801CA68:
	movs r4, 0xE0
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	lsrs r0, 1
	cmp r0, 0x5
	bls _0801CA78
	b _0801CBF4
_0801CA78:
	lsls r0, 2
	ldr r1, =_0801CA88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801CA88:
	.4byte _0801CAA0
	.4byte _0801CAB2
	.4byte _0801CAF4
	.4byte _0801CB54
	.4byte _0801CB84
	.4byte _0801CBC0
_0801CAA0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0801CC0E
_0801CAB2:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801CABE
	b _0801CC28
_0801CABE:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	b _0801CC0E
_0801CAF4:
	movs r4, 0x1E
	str r4, [sp]
	movs r5, 0x14
	str r5, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r5, 0x18
	str r5, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0801CC0E
_0801CB54:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	bl RemoveWindow
	b _0801CC0E
	.pool
_0801CB84:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r4, =gUnknown_02022C78
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801CC0E
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
	b _0801CC0E
	.pool
_0801CBC0:
	ldr r0, =gUnknown_02022C60
	ldrb r0, [r0]
	adds r1, r2, 0
	bl sub_80186EC
	movs r0, 0x3
	bl sub_8018798
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0801CC0E
	.pool
_0801CBF4:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801CC28
	ldr r0, [r5]
	adds r0, r4
	ldrb r2, [r0]
	movs r1, 0x1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0801CC2A
_0801CC0E:
	ldr r0, =gUnknown_02022C78
	ldr r2, [r0]
	movs r0, 0xE0
	lsls r0, 1
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 1
	adds r1, 0x1
	lsls r1, 1
	movs r0, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801CC28:
	movs r0, 0
_0801CC2A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801CA50

	thumb_func_start sub_801CC38
sub_801CC38: @ 801CC38
	push {r4,r5,lr}
	ldr r4, =gUnknown_02022C78
	ldr r2, [r4]
	movs r5, 0xE0
	lsls r5, 1
	adds r0, r2, r5
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801CC72
	ldr r0, =0x000001c1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0801CC72
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x000001c1
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
_0801CC72:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CC38

	thumb_func_start sub_801CC80
sub_801CC80: @ 801CC80
	push {r4,lr}
	ldr r4, =gUnknown_02022C78
	ldr r2, [r4]
	movs r1, 0xE0
	lsls r1, 1
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801CCC0
	movs r3, 0xE5
	lsls r3, 2
	adds r0, r2, r3
	movs r3, 0xE3
	lsls r3, 1
	adds r1, r2, r3
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r2, =0x000001c1
	adds r1, r2
	strb r0, [r1]
	ldr r1, [r4]
	movs r3, 0xE0
	lsls r3, 1
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0801CCC0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CC80

	thumb_func_start sub_801CCD0
sub_801CCD0: @ 801CCD0
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r3, r4, 0
	ldr r2, =gUnknown_02022C78
	ldr r0, [r2]
	mov r12, r0
	movs r0, 0xE1
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _0801CD00
	bl sub_801CFA4
_0801CCF6:
	movs r0, 0xFF
	b _0801CDC6
	.pool
_0801CD00:
	cmp r4, 0x2
	beq _0801CD1C
	cmp r4, 0x2
	bgt _0801CD0E
	cmp r4, 0x1
	beq _0801CD18
	b _0801CCF6
_0801CD0E:
	cmp r3, 0x40
	beq _0801CD20
	cmp r3, 0x80
	beq _0801CD50
	b _0801CCF6
_0801CD18:
	movs r0, 0
	b _0801CDC6
_0801CD1C:
	movs r0, 0x1
	b _0801CDC6
_0801CD20:
	movs r0, 0xE3
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CCF6
	movs r0, 0xE0
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0801CCF6
	ldr r2, =0x000001c3
	add r2, r12
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	b _0801CD7E
	.pool
_0801CD50:
	movs r0, 0xE3
	lsls r0, 1
	add r0, r12
	movs r1, 0xE2
	lsls r1, 1
	add r1, r12
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0801CCF6
	movs r0, 0xE0
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0801CCF6
	ldr r2, =0x000001c3
	add r2, r12
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
_0801CD7E:
	strb r0, [r2]
	ldr r2, [r6]
	movs r4, 0xE1
	lsls r4, 1
	adds r2, r4
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r3, [r6]
	adds r3, r4
	ldrb r1, [r3]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r6]
	adds r4, 0x1
	adds r1, r4
	ldrb r3, [r1]
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0801CDC4
	movs r0, 0x3
	b _0801CDC6
	.pool
_0801CDC4:
	movs r0, 0x2
_0801CDC6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801CCD0

	thumb_func_start sub_801CDCC
sub_801CDCC: @ 801CDCC
	push {r4-r6,lr}
	movs r5, 0
	ldr r4, =gUnknown_02022C78
	ldr r1, [r4]
	movs r2, 0xE7
	lsls r2, 1
	adds r0, r1, r2
	adds r1, 0x4
	movs r2, 0x28
	bl memcpy
	ldr r0, [r4]
	movs r3, 0xFB
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r6, r4, 0
_0801CDF0:
	ldr r2, [r6]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r4, r1, r5
	adds r0, r4, r2
	ldr r3, =0x000001f7
	adds r0, r3
	adds r1, r2
	adds r1, 0x2C
	movs r2, 0x28
	bl memcpy
	ldr r0, [r6]
	ldr r1, =0x0000021f
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
	cmp r5, 0x7
	bls _0801CE34
	ldr r1, [r6]
	ldr r2, =0x000001f7
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0801CE34
	movs r3, 0xE2
	lsls r3, 1
	adds r1, r3
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0801CE34:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _0801CDF0
	ldr r2, =gUnknown_02022C78
	ldr r1, [r2]
	movs r4, 0xE5
	lsls r4, 2
	adds r1, r4
	ldr r0, =gUnknown_082F1DF8
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, [r2]
	movs r5, 0xE2
	lsls r5, 1
	adds r0, r2, r5
	ldrh r1, [r0]
	movs r3, 0xE7
	lsls r3, 2
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CDCC

	thumb_func_start sub_801CE7C
sub_801CE7C: @ 801CE7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	movs r5, 0
	ldr r6, =gUnknown_02022C78
	ldr r0, [r6]
	movs r7, 0xE4
	lsls r7, 1
	adds r0, r7
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r4, 0xE5
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	adds r0, r7
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r4, [r6]
	movs r0, 0xE7
	lsls r0, 1
	mov r8, r0
	add r4, r8
	movs r0, 0x3
	movs r1, 0x2
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x3
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xE0
	subs r1, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	cmp r1, 0
	bge _0801CEEC
	movs r1, 0
_0801CEEC:
	ldr r4, [r6]
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r2, r1, 24
	lsrs r2, 24
	movs r3, 0xDE
	lsls r3, 1
	adds r1, r4, r3
	ldr r1, [r1]
	ldrb r1, [r1]
	lsls r1, 28
	lsrs r1, 28
	lsls r3, r1, 1
	adds r3, r1
	ldr r1, =gUnknown_082F1DE0
	adds r3, r1
	str r3, [sp]
	str r5, [sp, 0x4]
	add r4, r8
	str r4, [sp, 0x8]
	movs r1, 0x3
	movs r3, 0x6
	bl AddTextPrinterParameterized3
_0801CF1C:
	ldr r6, =gUnknown_02022C78
	ldr r4, [r6]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r3, r5, 4
	adds r3, 0x2
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0xDE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	ldrb r1, [r1]
	lsrs r1, 4
	lsls r2, r1, 1
	adds r2, r1
	ldr r1, =gUnknown_082F1DE0
	adds r2, r1
	str r2, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r5
	ldr r2, =0x000001f7
	adds r1, r2
	adds r4, r1
	str r4, [sp, 0x8]
	movs r1, 0x3
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _0801CF1C
	ldr r0, [r6]
	movs r3, 0xE4
	lsls r3, 1
	adds r0, r3
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, [r6]
	movs r1, 0xE5
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CE7C

	thumb_func_start sub_801CFA4
sub_801CFA4: @ 801CFA4
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C78
	ldr r1, [r0]
	movs r2, 0xE1
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsrs r4, r0, 1
	lsls r4, 8
	ldr r6, =0x000001c3
	adds r0, r1, r6
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801CFE4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0x1
	bl ChangeBgY
	b _0801CFF8
	.pool
_0801CFE4:
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgY
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0x2
	bl ChangeBgY
_0801CFF8:
	ldr r3, =gUnknown_02022C78
	ldr r0, [r3]
	ldr r2, =0x000001c3
	adds r5, r0, r2
	ldrb r4, [r5]
	lsrs r1, r4, 1
	movs r6, 0xE1
	lsls r6, 1
	adds r0, r6
	ldrb r0, [r0]
	lsrs r0, 1
	adds r1, r0
	lsls r1, 1
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r5]
	ldr r1, [r3]
	adds r2, r1, r2
	ldrb r2, [r2]
	lsrs r0, r2, 1
	cmp r0, 0xF
	bls _0801D070
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	beq _0801D044
	movs r0, 0xE3
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	b _0801D04E
	.pool
_0801D044:
	movs r2, 0xE3
	lsls r2, 1
	adds r1, r2
	ldrh r0, [r1]
	subs r0, 0x1
_0801D04E:
	strh r0, [r1]
	ldr r0, [r3]
	movs r6, 0xE1
	lsls r6, 1
	adds r2, r0, r6
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldr r1, =0x000001c3
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	strb r0, [r2]
_0801D070:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801CFA4

	thumb_func_start mevent_srv_init_wnews
mevent_srv_init_wnews: @ 801D07C
	push {r4,lr}
	ldr r4, =gUnknown_02022C7C
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gUnknown_082F298C
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mevent_srv_init_wnews

	thumb_func_start mevent_srv_new_wcard
mevent_srv_new_wcard: @ 801D0A0
	push {r4,lr}
	ldr r4, =gUnknown_02022C7C
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gUnknown_082F29EC
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mevent_srv_new_wcard

	thumb_func_start sub_801D0C4
sub_801D0C4: @ 801D0C4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =gUnknown_02022C7C
	ldr r0, [r4]
	cmp r0, 0
	bne _0801D0D8
	movs r0, 0x3
	b _0801D0F8
	.pool
_0801D0D8:
	bl mevent_dispatch_08145600
	adds r5, r0, 0
	cmp r5, 0x3
	bne _0801D0F6
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	strh r1, [r6]
	bl mevent_srv_free_resources
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801D0F6:
	adds r0, r5, 0
_0801D0F8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D0C4

	thumb_func_start mevent_srv_init_common
mevent_srv_init_common: @ 801D100
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r9, r3
	movs r5, 0
	str r5, [r4]
	str r5, [r4, 0x8]
	movs r0, 0xA6
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x18]
	movs r0, 0xDE
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x1C]
	movs r0, 0x80
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4, 0x14]
	movs r0, 0x64
	bl AllocZeroed
	str r0, [r4, 0x20]
	str r6, [r4, 0x10]
	str r5, [r4, 0xC]
	adds r4, 0x38
	adds r0, r4, 0
	mov r1, r8
	mov r2, r9
	bl sub_801D8D8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_init_common

	thumb_func_start mevent_srv_free_resources
mevent_srv_free_resources: @ 801D158
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x18]
	bl Free
	ldr r0, [r4, 0x1C]
	bl Free
	ldr r0, [r4, 0x14]
	bl Free
	ldr r0, [r4, 0x20]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_free_resources

	thumb_func_start mevent_srv_814501C
mevent_srv_814501C: @ 801D17C
	push {lr}
	adds r0, 0x38
	bl sub_801D904
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_814501C

	thumb_func_start sub_801D188
sub_801D188: @ 801D188
	push {lr}
	cmp r0, 0
	bne _0801D190
	adds r0, r1, 0
_0801D190:
	pop {r1}
	bx r1
	thumb_func_end sub_801D188

	thumb_func_start sub_801D194
sub_801D194: @ 801D194
	push {lr}
	cmp r1, r0
	bcs _0801D19E
	movs r0, 0
	b _0801D1A8
_0801D19E:
	cmp r1, r0
	beq _0801D1A6
	movs r0, 0x2
	b _0801D1A8
_0801D1A6:
	movs r0, 0x1
_0801D1A8:
	pop {r1}
	bx r1
	thumb_func_end sub_801D194

	thumb_func_start sub_801D1AC
sub_801D1AC: @ 801D1AC
	movs r1, 0x4
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end sub_801D1AC

	thumb_func_start sub_801D1B4
sub_801D1B4: @ 801D1B4
	movs r0, 0x3
	bx lr
	thumb_func_end sub_801D1B4

	thumb_func_start sub_801D1B8
sub_801D1B8: @ 801D1B8
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_801D8C0
	cmp r0, 0
	beq _0801D1CA
	movs r0, 0x4
	str r0, [r4, 0x8]
_0801D1CA:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1B8

	thumb_func_start sub_801D1D4
sub_801D1D4: @ 801D1D4
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_801D8CC
	cmp r0, 0
	beq _0801D1E6
	movs r0, 0x4
	str r0, [r4, 0x8]
_0801D1E6:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1D4

	thumb_func_start sub_801D1F0
sub_801D1F0: @ 801D1F0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r2, [r5, 0x10]
	adds r3, r2, r1
	adds r0, 0x1
	str r0, [r5, 0xC]
	ldr r0, [r3]
	cmp r0, 0x1E
	bls _0801D20C
	b _0801D464
_0801D20C:
	lsls r0, 2
	ldr r1, =_0801D21C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801D21C:
	.4byte _0801D298
	.4byte _0801D2A2
	.4byte _0801D2A8
	.4byte _0801D2E2
	.4byte _0801D2D8
	.4byte _0801D2BA
	.4byte _0801D2C6
	.4byte _0801D2EC
	.4byte _0801D300
	.4byte _0801D308
	.4byte _0801D31E
	.4byte _0801D32E
	.4byte _0801D33A
	.4byte _0801D360
	.4byte _0801D348
	.4byte _0801D390
	.4byte _0801D378
	.4byte _0801D3DC
	.4byte _0801D3A8
	.4byte _0801D3C0
	.4byte _0801D3CE
	.4byte _0801D406
	.4byte _0801D3EA
	.4byte _0801D3F8
	.4byte _0801D40E
	.4byte _0801D418
	.4byte _0801D422
	.4byte _0801D43C
	.4byte _0801D450
	.4byte _0801D458
	.4byte _0801D2CC
_0801D298:
	movs r0, 0x1
	str r0, [r5, 0x8]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x4]
	b _0801D464
_0801D2A2:
	movs r0, 0x3
	str r0, [r5, 0x8]
	b _0801D464
_0801D2A8:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r1, [r3, 0x4]
	ldr r2, [r5, 0x14]
	bl sub_801D928
	movs r0, 0x2
	str r0, [r5, 0x8]
	b _0801D464
_0801D2BA:
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	movs r2, 0x64
	bl memcpy
	b _0801D464
_0801D2C6:
	ldr r0, [r5, 0x20]
	movs r1, 0
	b _0801D2D0
_0801D2CC:
	ldr r0, [r5, 0x20]
	movs r1, 0x1
_0801D2D0:
	bl sub_801B6A0
	str r0, [r5, 0x4]
	b _0801D464
_0801D2D8:
	ldr r1, [r5, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	beq _0801D2E2
	b _0801D464
_0801D2E2:
	movs r0, 0
	str r0, [r5, 0xC]
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x10]
	b _0801D464
_0801D2EC:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_801D188
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_801B6EC
	str r0, [r5, 0x4]
	b _0801D464
_0801D300:
	ldr r0, [r5, 0x14]
	ldr r0, [r0]
	str r0, [r5, 0x4]
	b _0801D464
_0801D308:
	ldr r0, [r3, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_801D188
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_801B708
	str r0, [r5, 0x4]
	b _0801D464
_0801D31E:
	ldr r0, [r5, 0x20]
	ldr r1, [r3, 0x4]
	bl sub_801B784
	lsls r0, 16
	lsrs r0, 16
	str r0, [r5, 0x4]
	b _0801D464
_0801D32E:
	ldr r0, [r5, 0x20]
	ldr r1, [r3, 0x8]
	bl sub_801B748
	str r0, [r5, 0x4]
	b _0801D464
_0801D33A:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x14]
	ldr r1, [r1]
	bl sub_801D194
	str r0, [r5, 0x4]
	b _0801D464
_0801D348:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x1C]
	bl sub_801D188
	adds r2, r0, 0
	movs r3, 0xDE
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x17
	bl mevent_srv_814501C
	b _0801D464
_0801D360:
	ldr r0, [r3, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_801D188
	adds r2, r0, 0
	movs r3, 0xA6
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x16
	bl mevent_srv_814501C
	b _0801D464
_0801D378:
	ldr r0, [r3, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_801D188
	adds r2, r0, 0
	adds r0, r5, 0
	movs r1, 0x18
	movs r3, 0x4
	bl mevent_srv_814501C
	b _0801D464
_0801D390:
	ldr r2, [r3, 0x8]
	cmp r2, 0
	bne _0801D39C
	ldr r2, [r5, 0x24]
	ldr r3, [r5, 0x28]
	b _0801D39E
_0801D39C:
	ldr r3, [r3, 0x4]
_0801D39E:
	adds r0, r5, 0
	movs r1, 0x19
	bl mevent_srv_814501C
	b _0801D464
_0801D3A8:
	ldr r2, [r3, 0x8]
	cmp r2, 0
	bne _0801D3B4
	ldr r2, [r5, 0x2C]
	ldr r3, [r5, 0x30]
	b _0801D3B6
_0801D3B4:
	ldr r3, [r3, 0x4]
_0801D3B6:
	adds r0, r5, 0
	movs r1, 0x10
	bl mevent_srv_814501C
	b _0801D464
_0801D3C0:
	ldr r2, [r3, 0x8]
	adds r0, r5, 0
	movs r1, 0x1A
	movs r3, 0xBC
	bl mevent_srv_814501C
	b _0801D464
_0801D3CE:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x15
	bl mevent_srv_814501C
	b _0801D464
_0801D3DC:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x1C
	bl mevent_srv_814501C
	b _0801D464
_0801D3EA:
	ldr r0, [r5, 0x18]
	ldr r1, [r3, 0x8]
	movs r2, 0xA6
	lsls r2, 1
	bl memcpy
	b _0801D464
_0801D3F8:
	ldr r0, [r5, 0x1C]
	ldr r1, [r3, 0x8]
	movs r2, 0xDE
	lsls r2, 1
	bl memcpy
	b _0801D464
_0801D406:
	ldr r0, [r3, 0x8]
	ldr r0, [r0]
	str r0, [r5, 0x34]
	b _0801D464
_0801D40E:
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x24]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x28]
	b _0801D464
_0801D418:
	ldr r0, [r3, 0x8]
	str r0, [r5, 0x2C]
	ldr r0, [r3, 0x4]
	str r0, [r5, 0x30]
	b _0801D464
_0801D422:
	ldr r4, [r5, 0x18]
	bl sav1_get_mevent_buffer_1
	adds r1, r0, 0
	movs r2, 0xA6
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	ldr r0, [r5, 0x18]
	bl sub_801B3C0
	b _0801D464
_0801D43C:
	ldr r4, [r5, 0x1C]
	bl sub_801B00C
	adds r1, r0, 0
	movs r2, 0xDE
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	b _0801D464
_0801D450:
	bl sub_8099244
	str r0, [r5, 0x24]
	b _0801D464
_0801D458:
	ldr r2, [r3, 0x8]
	ldr r3, [r3, 0x4]
	adds r0, r5, 0
	movs r1, 0x1B
	bl mevent_srv_814501C
_0801D464:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801D1F0

	thumb_func_start mevent_dispatch_08145600
mevent_dispatch_08145600: @ 801D46C
	push {lr}
	ldr r2, =gUnknown_082F2548
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_dispatch_08145600

	thumb_func_start sub_801D484
sub_801D484: @ 801D484
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02022C80
	movs r0, 0x50
	bl AllocZeroed
	str r0, [r4]
	movs r1, 0x1
	movs r2, 0
	bl mevent_srv_ish_init
	ldr r0, [r4]
	str r5, [r0, 0x4C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D484

	thumb_func_start sub_801D4A8
sub_801D4A8: @ 801D4A8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =gUnknown_02022C80
	ldr r0, [r4]
	cmp r0, 0
	bne _0801D4BC
	movs r0, 0x6
	b _0801D4DC
	.pool
_0801D4BC:
	bl mevent_srv_ish_exec
	adds r5, r0, 0
	cmp r5, 0x6
	bne _0801D4DA
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	strh r1, [r6]
	bl sub_801D55C
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_0801D4DA:
	adds r0, r5, 0
_0801D4DC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D4A8

	thumb_func_start sub_801D4E4
sub_801D4E4: @ 801D4E4
	ldr r0, =gUnknown_02022C80
	ldr r1, [r0]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	bx lr
	.pool
	thumb_func_end sub_801D4E4

	thumb_func_start sub_801D4F4
sub_801D4F4: @ 801D4F4
	ldr r0, =gUnknown_02022C80
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_801D4F4

	thumb_func_start sub_801D500
sub_801D500: @ 801D500
	ldr r1, =gUnknown_02022C80
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_801D500

	thumb_func_start mevent_srv_ish_init
mevent_srv_ish_init: @ 801D50C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	movs r5, 0x80
	lsls r5, 3
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x14]
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x18]
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4, 0x1C]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x20]
	adds r4, 0x24
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_801D8D8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_ish_init

	thumb_func_start sub_801D55C
sub_801D55C: @ 801D55C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	bl Free
	ldr r0, [r4, 0x18]
	bl Free
	ldr r0, [r4, 0x1C]
	bl Free
	ldr r0, [r4, 0x20]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D55C

	thumb_func_start sub_801D580
sub_801D580: @ 801D580
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x18]
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r0, 0
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D580

	thumb_func_start sub_801D59C
sub_801D59C: @ 801D59C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r0, 0
	str r0, [sp]
	ldr r1, [r4, 0x14]
	ldr r2, =0x05000100
	mov r0, sp
	bl CpuSet
	ldr r2, [r4, 0x14]
	str r5, [r2]
	adds r4, 0x24
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0x4
	bl sub_801D904
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D59C

	thumb_func_start sub_801D5D0
sub_801D5D0: @ 801D5D0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	ldr r1, =gUnknown_082F2598
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r1, 0
	str r1, [r4, 0x10]
	movs r0, 0x4
	str r0, [r4, 0x8]
	str r1, [r4, 0xC]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D5D0

	thumb_func_start sub_801D5F8
sub_801D5F8: @ 801D5F8
	movs r0, 0x6
	bx lr
	thumb_func_end sub_801D5F8

	thumb_func_start sub_801D5FC
sub_801D5FC: @ 801D5FC
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_801D8C0
	cmp r0, 0
	beq _0801D612
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D612:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D5FC

	thumb_func_start sub_801D61C
sub_801D61C: @ 801D61C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_801D8CC
	cmp r0, 0
	beq _0801D632
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D632:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D61C

	thumb_func_start sub_801D63C
sub_801D63C: @ 801D63C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	lsls r2, r0, 3
	ldr r1, [r4, 0x1C]
	adds r2, r1, r2
	adds r0, 0x1
	str r0, [r4, 0x10]
	ldr r0, [r2]
	cmp r0, 0x15
	bls _0801D654
	b _0801D804
_0801D654:
	lsls r0, 2
	ldr r1, =_0801D664
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801D664:
	.4byte _0801D804
	.4byte _0801D6BC
	.4byte _0801D6C4
	.4byte _0801D6D4
	.4byte _0801D70E
	.4byte _0801D716
	.4byte _0801D6FE
	.4byte _0801D708
	.4byte _0801D764
	.4byte _0801D790
	.4byte _0801D788
	.4byte _0801D72C
	.4byte _0801D742
	.4byte _0801D758
	.4byte _0801D77C
	.4byte _0801D7B8
	.4byte _0801D7BC
	.4byte _0801D7C4
	.4byte _0801D7D0
	.4byte _0801D6EA
	.4byte _0801D6D8
	.4byte _0801D7F0
_0801D6BC:
	ldr r0, [r2, 0x4]
	str r0, [r4, 0x4]
	movs r0, 0x1
	b _0801D7FE
_0801D6C4:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r1, [r2, 0x4]
	ldr r2, [r4, 0x18]
	bl sub_801D928
	movs r0, 0x2
	b _0801D7FE
_0801D6D4:
	movs r0, 0x3
	b _0801D7FE
_0801D6D8:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x14
	movs r3, 0
	bl sub_801D904
	movs r0, 0x3
	b _0801D7FE
_0801D6EA:
	ldrb r0, [r2, 0x4]
	bl GetGameStat
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0x12
	bl sub_801D59C
	movs r0, 0x3
	b _0801D7FE
_0801D6FE:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0801D706
	b _0801D804
_0801D706:
	b _0801D70E
_0801D708:
	ldr r0, [r4, 0x4]
	cmp r0, 0x1
	bne _0801D804
_0801D70E:
	adds r0, r4, 0
	bl sub_801D580
	b _0801D804
_0801D716:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _0801D806
_0801D72C:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x3
	b _0801D806
_0801D742:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x5
	b _0801D806
_0801D758:
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _0801D806
_0801D764:
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x4C]
	bl sub_801B580
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x11
	movs r3, 0x64
	bl sub_801D904
	b _0801D804
_0801D77C:
	ldr r2, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x13
	bl sub_801D59C
	b _0801D804
_0801D788:
	ldr r0, [r4, 0x18]
	bl sub_801B21C
	b _0801D804
_0801D790:
	ldr r0, [r4, 0x18]
	bl sub_801B1A4
	cmp r0, 0
	bne _0801D7AC
	ldr r0, [r4, 0x18]
	bl sub_801B078
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_801D59C
	b _0801D804
_0801D7AC:
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0x1
	bl sub_801D59C
	b _0801D804
_0801D7B8:
	movs r0, 0x6
	b _0801D7FE
_0801D7BC:
	ldr r0, [r4, 0x18]
	bl sub_801B508
	b _0801D804
_0801D7C4:
	ldr r0, [r4, 0x18]
	movs r1, 0xFA
	lsls r1, 2
	bl sub_80992A0
	b _0801D804
_0801D7D0:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bec
	adds r0, r1
	ldr r1, [r4, 0x18]
	movs r2, 0xBC
	bl memcpy
	bl ValidateEReaderTrainer
	b _0801D804
	.pool
_0801D7F0:
	ldr r0, =gDecompressionBuffer
	ldr r1, [r4, 0x18]
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r0, 0x7
_0801D7FE:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D804:
	movs r0, 0x1
_0801D806:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D63C

	thumb_func_start sub_801D810
sub_801D810: @ 801D810
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801D822
	movs r0, 0x4
	str r0, [r1, 0x8]
	movs r0, 0
	str r0, [r1, 0xC]
_0801D822:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_801D810

	thumb_func_start sub_801D828
sub_801D828: @ 801D828
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0801D838
	cmp r0, 0x1
	beq _0801D846
	b _0801D858
_0801D838:
	ldr r0, [r4, 0x18]
	bl sub_8153870
	ldr r0, [r4, 0xC]
	adds r0, 0x1
	str r0, [r4, 0xC]
	b _0801D858
_0801D846:
	adds r0, r4, 0x4
	bl sub_8153884
	adds r1, r0, 0
	cmp r1, 0
	bne _0801D858
	movs r0, 0x4
	str r0, [r4, 0x8]
	str r1, [r4, 0xC]
_0801D858:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D828

	thumb_func_start sub_801D860
sub_801D860: @ 801D860
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, =gDecompressionBuffer
	adds r0, r4, 0x4
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r2, =gSaveBlock1Ptr
	ldr r2, [r2]
	bl _call_via_r3
	cmp r0, 0x1
	bne _0801D880
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_0801D880:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801D860

	thumb_func_start mevent_srv_ish_exec
mevent_srv_ish_exec: @ 801D894
	push {r4,r5,lr}
	sub sp, 0x20
	mov r2, sp
	ldr r1, =gUnknown_082F255C
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3,r4}
	stm r2!, {r3,r4}
	ldr r1, [r0, 0x8]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	bl _call_via_r1
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mevent_srv_ish_exec

	thumb_func_start sub_801D8C0
sub_801D8C0: @ 801D8C0
	push {lr}
	ldr r1, [r0, 0x20]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_801D8C0

	thumb_func_start sub_801D8CC
sub_801D8CC: @ 801D8CC
	push {lr}
	ldr r1, [r0, 0x24]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_801D8CC

	thumb_func_start sub_801D8D8
sub_801D8D8: @ 801D8D8
	movs r3, 0
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	str r3, [r0]
	strh r3, [r0, 0x12]
	strh r3, [r0, 0x14]
	strh r3, [r0, 0x10]
	strh r3, [r0, 0xA]
	strh r3, [r0, 0xC]
	strh r3, [r0, 0x8]
	str r3, [r0, 0x1C]
	str r3, [r0, 0x18]
	ldr r1, =sub_801DA5C
	str r1, [r0, 0x24]
	ldr r1, =sub_801D988
	str r1, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_801D8D8

	thumb_func_start sub_801D904
sub_801D904: @ 801D904
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	str r0, [r4]
	strh r1, [r4, 0xE]
	strh r0, [r4, 0x10]
	strh r0, [r4, 0x12]
	cmp r3, 0
	beq _0801D91A
	strh r3, [r4, 0x14]
	b _0801D920
_0801D91A:
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x14]
_0801D920:
	str r2, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D904

	thumb_func_start sub_801D928
sub_801D928: @ 801D928
	movs r3, 0
	str r3, [r0]
	strh r1, [r0, 0x6]
	strh r3, [r0, 0x8]
	strh r3, [r0, 0xA]
	strh r3, [r0, 0xC]
	str r2, [r0, 0x18]
	bx lr
	thumb_func_end sub_801D928

	thumb_func_start sub_801D938
sub_801D938: @ 801D938
	push {lr}
	adds r3, r0, 0
	adds r0, r1, 0
	lsls r3, 8
	ldr r1, =gBlockRecvBuffer
	adds r3, r1
	adds r1, r3, 0
	bl memcpy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D938

	thumb_func_start sub_801D954
sub_801D954: @ 801D954
	push {r4,lr}
	adds r4, r0, 0
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801D96E
	movs r0, 0
	b _0801D970
_0801D96E:
	movs r0, 0x1
_0801D970:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D954

	thumb_func_start sub_801D978
sub_801D978: @ 801D978
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl ResetBlockReceivedFlag
	pop {r0}
	bx r0
	thumb_func_end sub_801D978

	thumb_func_start sub_801D988
sub_801D988: @ 801D988
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r6, [r5]
	cmp r6, 0x1
	beq _0801D9EC
	cmp r6, 0x1
	bgt _0801D99E
	cmp r6, 0
	beq _0801D9A4
	b _0801DA52
_0801D99E:
	cmp r6, 0x2
	beq _0801DA38
	b _0801DA52
_0801D9A4:
	ldrb r0, [r5, 0x5]
	bl sub_801D954
	cmp r0, 0
	beq _0801DA52
	ldrb r0, [r5, 0x5]
	mov r4, sp
	mov r1, sp
	movs r2, 0x8
	bl sub_801D938
	ldrh r1, [r4, 0x4]
	strh r1, [r5, 0xC]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0xA]
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 19
	cmp r1, r0
	bls _0801D9D2
_0801D9CC:
	bl sub_8010198
	b _0801DA52
_0801D9D2:
	mov r1, sp
	ldrh r0, [r5, 0x6]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0801D9CC
	strh r6, [r5, 0x8]
	ldrb r0, [r5, 0x5]
	bl sub_801D978
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	b _0801DA52
_0801D9EC:
	ldrb r0, [r5, 0x5]
	bl sub_801D954
	cmp r0, 0
	beq _0801DA52
	ldrh r0, [r5, 0x8]
	lsls r1, r0, 6
	subs r1, r0
	lsls r3, r1, 2
	ldrh r0, [r5, 0xC]
	subs r2, r0, r3
	cmp r2, 0xFC
	bhi _0801DA1E
	ldrb r0, [r5, 0x5]
	ldr r1, [r5, 0x18]
	adds r1, r3
	bl sub_801D938
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	b _0801DA30
_0801DA1E:
	ldrb r0, [r5, 0x5]
	ldr r1, [r5, 0x18]
	adds r1, r3
	movs r2, 0xFC
	bl sub_801D938
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0801DA30:
	ldrb r0, [r5, 0x5]
	bl sub_801D978
	b _0801DA52
_0801DA38:
	ldr r0, [r5, 0x18]
	ldrh r1, [r5, 0xC]
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r5, 0xA]
	cmp r0, r1
	bne _0801D9CC
	movs r0, 0
	str r0, [r5]
	movs r0, 0x1
	b _0801DA54
_0801DA52:
	movs r0, 0
_0801DA54:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D988

	thumb_func_start sub_801DA5C
sub_801DA5C: @ 801DA5C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r5, [r4]
	cmp r5, 0x1
	beq _0801DAC8
	cmp r5, 0x1
	bgt _0801DA72
	cmp r5, 0
	beq _0801DA7C
	b _0801DB5E
_0801DA72:
	cmp r5, 0x2
	beq _0801DB1C
	cmp r5, 0x3
	beq _0801DB46
	b _0801DB5E
_0801DA7C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldrh r1, [r4, 0xE]
	ldr r2, =0xffff0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, 0x14]
	ldr r0, [sp, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x1C]
	bl CalcCRC16WithTable
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	lsrs r1, 16
	strh r1, [r4, 0x12]
	strh r5, [r4, 0x10]
	movs r0, 0
	mov r1, sp
	movs r2, 0x8
	bl SendBlock
	b _0801DB3E
	.pool
_0801DAC8:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D954
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D978
	ldrh r1, [r4, 0x10]
	lsls r0, r1, 6
	subs r0, r1
	lsls r3, r0, 2
	ldrh r0, [r4, 0x14]
	subs r0, r3
	cmp r0, 0xFC
	bhi _0801DB08
	ldr r1, [r4, 0x1C]
	adds r1, r3
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	bl SendBlock
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	b _0801DB3E
_0801DB08:
	ldr r1, [r4, 0x1C]
	adds r1, r3
	movs r0, 0
	movs r2, 0xFC
	bl SendBlock
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	b _0801DB5E
_0801DB1C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldr r0, [r4, 0x1C]
	ldrh r1, [r4, 0x14]
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0x12]
	cmp r0, r1
	beq _0801DB3E
	bl sub_8010198
	b _0801DB5E
_0801DB3E:
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	b _0801DB5E
_0801DB46:
	ldrb r0, [r4, 0x4]
	bl sub_801D954
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D978
	movs r0, 0
	str r0, [r4]
	movs r0, 0x1
	b _0801DB60
_0801DB5E:
	movs r0, 0
_0801DB60:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801DA5C

	thumb_func_start sub_801DB68
sub_801DB68: @ 801DB68
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_801B044
	adds r5, r0, 0
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r5]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	cmp r4, 0x2
	bhi _0801DB8E
	cmp r4, 0x1
	bcs _0801DB94
	b _0801DBB8
_0801DB8E:
	cmp r4, 0x3
	beq _0801DBA6
	b _0801DBB8
_0801DB94:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	bl __umodsi3
	adds r0, 0x10
	b _0801DBB6
_0801DBA6:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	bl __umodsi3
	adds r0, 0x1
_0801DBB6:
	strb r0, [r5, 0x1]
_0801DBB8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801DB68

	thumb_func_start sub_801DBC0
sub_801DBC0: @ 801DBC0
	push {lr}
	bl sub_801B044
	movs r1, 0
	strb r1, [r0]
	strb r1, [r0, 0x1]
	ldr r0, =0x0000402e
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DBC0

	thumb_func_start sub_801DBDC
sub_801DBDC: @ 801DBDC
	push {r4,lr}
	ldr r0, =0x0000402e
	bl GetVarPointer
	adds r4, r0, 0
	bl sub_801B044
	adds r2, r0, 0
	ldr r0, [r2]
	lsls r0, 24
	lsrs r0, 29
	cmp r0, 0x4
	bls _0801DC10
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	ldr r1, =0x01f30000
	cmp r0, r1
	bls _0801DC10
	ldrb r0, [r2]
	movs r1, 0x1F
	ands r1, r0
	strb r1, [r2]
	movs r0, 0
	strh r0, [r4]
_0801DC10:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DBDC

	thumb_func_start sub_801DC20
sub_801DC20: @ 801DC20
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_Result
	bl sub_801B044
	adds r4, r0, 0
	bl IsMysteryEventEnabled
	cmp r0, 0
	beq _0801DC3A
	bl sub_801B0CC
	cmp r0, 0
	bne _0801DC44
_0801DC3A:
	movs r0, 0
	b _0801DCA6
	.pool
_0801DC44:
	adds r0, r4, 0
	bl sub_801DD44
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x6
	bhi _0801DCA4
	lsls r0, r5, 2
	ldr r1, =_0801DC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801DC60:
	.4byte _0801DCA4
	.4byte _0801DC7C
	.4byte _0801DC7C
	.4byte _0801DCA4
	.4byte _0801DC86
	.4byte _0801DC96
	.4byte _0801DCA4
_0801DC7C:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	b _0801DCA4
_0801DC86:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	adds r0, r4, 0
	bl sub_801DCD8
	b _0801DCA4
_0801DC96:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	adds r0, r4, 0
	bl sub_801DCCC
_0801DCA4:
	adds r0, r5, 0
_0801DCA6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801DC20

	thumb_func_start sub_801DCAC
sub_801DCAC: @ 801DCAC
	push {r4,lr}
	ldrb r2, [r0]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r4, [r0, 0x1]
	adds r4, 0x84
	movs r1, 0
	strb r1, [r0, 0x1]
	bl sub_801DD10
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801DCAC

	thumb_func_start sub_801DCCC
sub_801DCCC: @ 801DCCC
	ldrb r2, [r0]
	movs r1, 0x1D
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_801DCCC

	thumb_func_start sub_801DCD8
sub_801DCD8: @ 801DCD8
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3]
	lsls r0, 27
	lsrs r0, 29
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	lsls r0, 2
	ldrb r1, [r3]
	movs r4, 0x1D
	negs r4, r4
	adds r2, r4, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3]
	ldr r0, [r3]
	lsls r0, 27
	lsrs r0, 29
	cmp r0, 0x4
	bls _0801DD0A
	ands r2, r4
	movs r0, 0x10
	orrs r2, r0
	strb r2, [r3]
_0801DD0A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DCD8

	thumb_func_start sub_801DD10
sub_801DD10: @ 801DD10
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3]
	lsls r0, 24
	lsrs r0, 29
	adds r0, 0x1
	lsls r0, 5
	ldrb r1, [r3]
	movs r4, 0x1F
	adds r2, r4, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3]
	ldr r0, [r3]
	lsls r0, 24
	lsrs r0, 29
	cmp r0, 0x5
	bls _0801DD3C
	ands r2, r4
	movs r0, 0xA0
	orrs r2, r0
	strb r2, [r3]
_0801DD3C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DD10

	thumb_func_start sub_801DD44
sub_801DD44: @ 801DD44
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2]
	movs r0, 0xE0
	ands r0, r1
	cmp r0, 0xA0
	bne _0801DD56
	movs r0, 0x6
	b _0801DD92
_0801DD56:
	ldr r1, [r2]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x1
	beq _0801DD78
	cmp r0, 0x1
	bgt _0801DD6A
	cmp r0, 0
	beq _0801DD74
	b _0801DD90
_0801DD6A:
	cmp r0, 0x2
	beq _0801DD7C
	cmp r0, 0x3
	beq _0801DD80
	b _0801DD90
_0801DD74:
	movs r0, 0x3
	b _0801DD92
_0801DD78:
	movs r0, 0x1
	b _0801DD92
_0801DD7C:
	movs r0, 0x2
	b _0801DD92
_0801DD80:
	lsls r0, r1, 27
	lsrs r0, 29
	cmp r0, 0x2
	bhi _0801DD8C
	movs r0, 0x4
	b _0801DD92
_0801DD8C:
	movs r0, 0x5
	b _0801DD92
_0801DD90:
	movs r0, 0
_0801DD92:
	pop {r1}
	bx r1
	thumb_func_end sub_801DD44

	thumb_func_start sub_801DD98
sub_801DD98: @ 801DD98
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	movs r0, 0xDE
	lsls r0, 1
	bl Alloc
	str r0, [r4]
	bl sub_801DDD0
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =c2_081284E0
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DD98

	thumb_func_start sub_801DDD0
sub_801DDD0: @ 801DDD0
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r5, [r4, 0x10]
	strb r5, [r4, 0x11]
	strb r5, [r4, 0x12]
	strb r5, [r4, 0x14]
	strb r5, [r4, 0x15]
	strb r5, [r4, 0x16]
	movs r0, 0xFF
	strb r0, [r4, 0x1A]
	bl GetLinkPlayerCount
	strb r0, [r4, 0xD]
	bl GetMultiplayerId
	strb r0, [r4, 0x13]
	strb r5, [r4, 0x17]
	strb r5, [r4, 0x18]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	bl sub_801EF1C
	ldr r7, =gSaveBlock1Ptr
	ldr r6, =0x00003c88
	adds r4, 0xB9
	movs r5, 0x9
_0801DE0E:
	ldr r1, [r7]
	adds r1, r6
	adds r0, r4, 0
	bl StringCopy
	adds r6, 0x15
	adds r4, 0x15
	subs r5, 0x1
	cmp r5, 0
	bge _0801DE0E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DDD0

	thumb_func_start sub_801DE30
sub_801DE30: @ 801DE30
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	bl DestroyTask
	ldr r0, [r4]
	ldrb r0, [r0, 0xF]
	bl DestroyTask
	ldr r0, [r4]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DE30

	thumb_func_start c2_081284E0
c2_081284E0: @ 801DE54
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801DE8C
	cmp r0, 0x1
	bgt _0801DE74
	cmp r0, 0
	beq _0801DE7A
	b _0801DF04
	.pool
_0801DE74:
	cmp r0, 0x2
	beq _0801DEC8
	b _0801DF04
_0801DE7A:
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl sub_801F4D0
	b _0801DEBC
_0801DE8C:
	bl sub_801F5B8
	bl sub_801F534
	adds r5, r0, 0
	cmp r5, 0
	bne _0801DF04
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_801DF20
	bl SetVBlankCallback
_0801DEBC:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _0801DF04
	.pool
_0801DEC8:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801DF04
	ldr r0, =sub_801DF38
	bl SetMainCallback2
	ldr r0, =sub_801DF54
	movs r1, 0x8
	bl CreateTask
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	strb r0, [r1, 0xE]
	ldr r0, =sub_801F2B4
	movs r1, 0x7
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0xF]
	bl sub_800E0E8
	movs r0, 0xE8
	movs r1, 0x96
	bl CreateWirelessStatusIndicatorSprite
_0801DF04:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_081284E0

	thumb_func_start sub_801DF20
sub_801DF20: @ 801DF20
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	thumb_func_end sub_801DF20

	thumb_func_start sub_801DF38
sub_801DF38: @ 801DF38
	push {lr}
	bl RunTasks
	bl sub_801F5B8
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_801DF38

	thumb_func_start sub_801DF54
sub_801DF54: @ 801DF54
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x17]
	cmp r0, 0x2
	beq _0801DF7A
	cmp r0, 0x2
	bgt _0801DF70
	cmp r0, 0x1
	beq _0801DF76
	b _0801DF8A
	.pool
_0801DF70:
	cmp r0, 0x3
	beq _0801DF7E
	b _0801DF8A
_0801DF76:
	movs r0, 0x6
	b _0801DF80
_0801DF7A:
	movs r0, 0x7
	b _0801DF80
_0801DF7E:
	movs r0, 0x8
_0801DF80:
	bl sub_801EBD4
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x17]
_0801DF8A:
	ldr r1, =gUnknown_082F2A7C
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DF54

	thumb_func_start sub_801DFAC
sub_801DFAC: @ 801DFAC
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrh r1, [r0, 0x6]
	cmp r1, 0x1
	beq _0801DFE0
	cmp r1, 0x1
	bgt _0801DFC8
	cmp r1, 0
	beq _0801DFCE
	b _0801E028
	.pool
_0801DFC8:
	cmp r1, 0x2
	beq _0801E018
	b _0801E028
_0801DFCE:
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EF24
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
_0801DFE0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E028
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E028
	.pool
_0801E018:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	movs r0, 0x1
	bl sub_801EBD4
_0801E028:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DFAC

	thumb_func_start sub_801E030
sub_801E030: @ 801E030
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C84
	ldr r3, [r5]
	ldrh r0, [r3, 0x6]
	cmp r0, 0
	beq _0801E048
	cmp r0, 0x1
	beq _0801E0F6
	b _0801E118
	.pool
_0801E048:
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0801E068
	ldrb r0, [r3, 0x15]
	cmp r0, 0
	beq _0801E118
	movs r0, 0x4
	bl sub_801EBD4
	b _0801E118
	.pool
_0801E068:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _0801E078
	movs r0, 0x2
	bl sub_801EBD4
	b _0801E118
_0801E078:
	ldrh r1, [r1, 0x30]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801E0A4
	ldrb r0, [r3, 0x15]
	cmp r0, 0
	beq _0801E09C
	bl sub_801ED68
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r5]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E118
_0801E09C:
	movs r0, 0x3
	bl sub_801EBD4
	b _0801E118
_0801E0A4:
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _0801E0C0
	bl sub_801EC94
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	movs r0, 0x2
	movs r1, 0x1
	b _0801E0EC
_0801E0C0:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0801E0E0
	ldrb r0, [r3, 0x10]
	cmp r0, 0x3
	beq _0801E0D8
	bl sub_801ED94
	movs r0, 0x8
	b _0801E0EA
_0801E0D8:
	movs r0, 0x5
	bl sub_801EBD4
	b _0801E118
_0801E0E0:
	bl sub_801EBE4
	cmp r0, 0
	beq _0801E118
	movs r0, 0x1
_0801E0EA:
	movs r1, 0
_0801E0EC:
	bl sub_801F5EC
	ldr r0, [r5]
	strh r4, [r0, 0x6]
	b _0801E118
_0801E0F6:
	movs r0, 0
	bl sub_801F644
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_801F644
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	bne _0801E118
	cmp r1, 0
	bne _0801E118
	ldr r0, [r5]
	strh r1, [r0, 0x6]
_0801E118:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E030

	thumb_func_start sub_801E120
sub_801E120: @ 801E120
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x6]
	cmp r0, 0x4
	bls _0801E12E
	b _0801E23A
_0801E12E:
	lsls r0, 2
	ldr r1, =_0801E140
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E140:
	.4byte _0801E154
	.4byte _0801E15E
	.4byte _0801E17C
	.4byte _0801E208
	.4byte _0801E21C
_0801E154:
	movs r0, 0x3
	movs r1, 0
	bl sub_801F5EC
	b _0801E16A
_0801E15E:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
_0801E16A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E23A
	.pool
_0801E17C:
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r0, 8
	lsrs r6, r0, 16
	asrs r4, r0, 16
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0801E1B4
	adds r0, 0x1
	cmp r4, r0
	beq _0801E1D4
	movs r0, 0x4
	movs r1, 0
	bl sub_801F5EC
	ldr r5, =gUnknown_02022C84
	ldr r2, [r5]
	ldrb r0, [r2, 0x10]
	cmp r0, r4
	beq _0801E1DC
	cmp r4, 0x3
	ble _0801E1EC
	b _0801E1DC
	.pool
_0801E1B4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0801E23A
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl Menu_MoveCursor
	b _0801E23A
	.pool
_0801E1D4:
	movs r0, 0x4
	movs r1, 0
	bl sub_801F5EC
_0801E1DC:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801E23A
	.pool
_0801E1EC:
	movs r1, 0
	strb r1, [r2, 0x11]
	ldr r0, [r5]
	strb r1, [r0, 0x12]
	movs r0, 0x5
	movs r1, 0x1
	bl sub_801F5EC
	ldr r0, [r5]
	strb r6, [r0, 0x10]
	ldr r1, [r5]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801E23A
_0801E208:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E23A
_0801E21C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801EBD4
_0801E23A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801E120

	thumb_func_start sub_801E240
sub_801E240: @ 801E240
	push {r4,r5,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0xA
	bls _0801E250
	b _0801E458
_0801E250:
	lsls r0, 2
	ldr r1, =_0801E264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E264:
	.4byte _0801E290
	.4byte _0801E2A8
	.4byte _0801E2C4
	.4byte _0801E322
	.4byte _0801E3D4
	.4byte _0801E424
	.4byte _0801E458
	.4byte _0801E458
	.4byte _0801E378
	.4byte _0801E338
	.4byte _0801E35C
_0801E290:
	movs r0, 0x6
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E2A8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E2B6
	b _0801E458
_0801E2B6:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E2C4:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801E2E6
	cmp r1, 0
	bgt _0801E2DE
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801E396
	b _0801E458
_0801E2DE:
	cmp r1, 0x1
	beq _0801E2E4
	b _0801E458
_0801E2E4:
	b _0801E396
_0801E2E6:
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801E310
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_801EFD0
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r4]
	movs r0, 0x9
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E310:
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_801EF7C
	ldr r1, [r4]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801E458
_0801E322:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E330
	b _0801E458
_0801E330:
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E458
_0801E338:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E346
	b _0801E458
_0801E346:
	movs r0, 0x14
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xA
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E35C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E36A
	b _0801E458
_0801E36A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x8
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E378:
	bl sub_801FF08
	lsls r0, 24
	asrs r5, r0, 24
	cmp r5, 0
	beq _0801E3AC
	cmp r5, 0
	bgt _0801E392
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801E396
	b _0801E458
_0801E392:
	cmp r5, 0x1
	bne _0801E458
_0801E396:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E3AC:
	bl sub_80104B0
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EFD0
	ldr r0, [r4]
	movs r1, 0x4
	strh r1, [r0, 0x6]
	movs r2, 0xDC
	lsls r2, 1
	adds r0, r2
	strh r5, [r0]
	b _0801E458
	.pool
_0801E3D4:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E414
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E414
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E414
	ldr r1, [r4]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801E410
	movs r0, 0x6
	b _0801E412
	.pool
_0801E410:
	movs r0, 0x5
_0801E412:
	strh r0, [r1, 0x6]
_0801E414:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E458
	b _0801E42C
	.pool
_0801E424:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E438
_0801E42C:
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E458
	.pool
_0801E438:
	ldr r3, [r2]
	movs r1, 0xDC
	lsls r1, 1
	adds r2, r3, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	bls _0801E458
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x4
	strh r0, [r3, 0x6]
_0801E458:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E240

	thumb_func_start sub_801E460
sub_801E460: @ 801E460
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0x7
	bls _0801E470
	b _0801E5BC
_0801E470:
	lsls r0, 2
	ldr r1, =_0801E484
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E484:
	.4byte _0801E4A4
	.4byte _0801E4C8
	.4byte _0801E4E8
	.4byte _0801E50C
	.4byte _0801E540
	.4byte _0801E560
	.4byte _0801E584
	.4byte _0801E5A8
_0801E4A4:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0801E4B2
	b _0801E5BC
_0801E4B2:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E4C8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E5BC
	movs r0, 0x12
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E4E8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E5BC
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EFA8
	ldr r1, [r4]
	b _0801E59A
	.pool
_0801E50C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E5BC
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	ldr r1, [r4]
	b _0801E59A
	.pool
_0801E540:
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801E5BC
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E5BC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E560:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E5BC
	bl sub_800AC34
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	strh r4, [r1, 0xA]
	b _0801E59A
	.pool
_0801E584:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E590
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E590:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E5BC
	ldr r1, [r2]
_0801E59A:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E5BC
	.pool
_0801E5A8:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E5B8
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E5BC
_0801E5B8:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E5BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E460

	thumb_func_start sub_801E5C4
sub_801E5C4: @ 801E5C4
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C84
	ldr r1, [r5]
	ldrh r0, [r1, 0x6]
	cmp r0, 0x1
	beq _0801E604
	cmp r0, 0x1
	bgt _0801E5E0
	cmp r0, 0
	beq _0801E5EA
	b _0801E662
	.pool
_0801E5E0:
	cmp r0, 0x2
	beq _0801E62E
	cmp r0, 0x3
	beq _0801E650
	b _0801E662
_0801E5EA:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0801E662
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	b _0801E640
	.pool
_0801E604:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E662
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E662
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E662
	bl sub_800AC34
	ldr r1, [r5]
	strh r4, [r1, 0xA]
	b _0801E642
_0801E62E:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E638
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E638:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E662
_0801E640:
	ldr r1, [r5]
_0801E642:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E662
	.pool
_0801E650:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E65E
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E662
_0801E65E:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E662:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E5C4

	thumb_func_start sub_801E668
sub_801E668: @ 801E668
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0801E75C
	lsls r0, 2
	ldr r1, =_0801E688
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E688:
	.4byte _0801E69C
	.4byte _0801E6C8
	.4byte _0801E6F0
	.4byte _0801E724
	.4byte _0801E748
_0801E69C:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0801E75C
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _0801E6BA
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
_0801E6BA:
	ldr r1, [r4]
	b _0801E73A
	.pool
_0801E6C8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E75C
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _0801E6E6
	movs r0, 0x13
	movs r1, 0
	bl sub_801F5EC
_0801E6E6:
	ldr r1, [r4]
	b _0801E73A
	.pool
_0801E6F0:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801E75C
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E75C
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E75C
	bl sub_800AC34
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	strh r4, [r1, 0xA]
	b _0801E73A
	.pool
_0801E724:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E730
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E730:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E75C
	ldr r1, [r2]
_0801E73A:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E75C
	.pool
_0801E748:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E758
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E75C
_0801E758:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E75C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E668

	thumb_func_start sub_801E764
sub_801E764: @ 801E764
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0801E830
	lsls r0, 2
	ldr r1, =_0801E784
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E784:
	.4byte _0801E798
	.4byte _0801E7C0
	.4byte _0801E7F4
	.4byte _0801E802
	.4byte _0801E820
_0801E798:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E7AC
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E830
	.pool
_0801E7AC:
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EF4C
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
_0801E7C0:
	bl IsLinkTaskFinished
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0801E830
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E830
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E830
	ldr r1, [r4]
	b _0801E812
	.pool
_0801E7F4:
	bl sub_801EE10
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	b _0801E80E
_0801E802:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E830
_0801E80E:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
_0801E812:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E830
	.pool
_0801E820:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801E830
	movs r0, 0x1
	bl sub_801EBD4
_0801E830:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E764

	thumb_func_start sub_801E838
sub_801E838: @ 801E838
	push {r4,lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x6]
	cmp r0, 0x6
	bls _0801E846
	b _0801E968
_0801E846:
	lsls r0, 2
	ldr r1, =_0801E858
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E858:
	.4byte _0801E874
	.4byte _0801E8A4
	.4byte _0801E8F8
	.4byte _0801E910
	.4byte _0801E920
	.4byte _0801E934
	.4byte _0801E94C
_0801E874:
	bl sub_801EDC4
	cmp r0, 0
	beq _0801E890
	movs r0, 0x9
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	b _0801E966
	.pool
_0801E890:
	movs r0, 0xD
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x5
	b _0801E966
	.pool
_0801E8A4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801E8CC
	bl sub_801EDE0
	movs r0, 0xB
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	b _0801E966
	.pool
_0801E8CC:
	movs r4, 0x2
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0801E8DA
	movs r0, 0xA
	b _0801E95A
_0801E8DA:
	bl sub_801EBE4
	cmp r0, 0
	beq _0801E968
	movs r0, 0x1
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	strh r4, [r0, 0x6]
	b _0801E968
	.pool
_0801E8F8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x1
	b _0801E966
	.pool
_0801E910:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	movs r0, 0xA
	b _0801E95A
_0801E920:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E968
_0801E934:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x6
	b _0801E966
	.pool
_0801E94C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0801E968
	movs r0, 0x7
_0801E95A:
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x4
_0801E966:
	strh r0, [r1, 0x6]
_0801E968:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801E838

	thumb_func_start sub_801E978
sub_801E978: @ 801E978
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r4, r1, 0
	cmp r0, 0xD
	bls _0801E98A
	b _0801EBC2
_0801E98A:
	lsls r0, 2
	ldr r1, =_0801E99C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E99C:
	.4byte _0801E9D4
	.4byte _0801E9EE
	.4byte _0801EA14
	.4byte _0801EA58
	.4byte _0801EA7C
	.4byte _0801EA98
	.4byte _0801EADC
	.4byte _0801EB04
	.4byte _0801EB28
	.4byte _0801EB40
	.4byte _0801EB64
	.4byte _0801EB72
	.4byte _0801EB88
	.4byte _0801EBA8
_0801E9D4:
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	bne _0801E9DE
	b _0801EB82
_0801E9DE:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r4]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801E9EE:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E9FC
	b _0801EBC2
_0801E9FC:
	movs r0, 0xE
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA14:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801EA40
	cmp r1, 0
	bgt _0801EA2E
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801EA34
	b _0801EBC2
_0801EA2E:
	cmp r1, 0x1
	beq _0801EA34
	b _0801EBC2
_0801EA34:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801EB82
	.pool
_0801EA40:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA58:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801EA66
	b _0801EBC2
_0801EA66:
	movs r0, 0xF
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA7C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801EA8A
	b _0801EBC2
_0801EA8A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x5
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA98:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801EAC4
	cmp r1, 0
	bgt _0801EAB2
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801EAB8
	b _0801EBC2
_0801EAB2:
	cmp r1, 0x1
	beq _0801EAB8
	b _0801EBC2
_0801EAB8:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801EB82
	.pool
_0801EAC4:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x6
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EADC:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	movs r0, 0x10
	movs r1, 0
	bl sub_801F5EC
	bl sub_801EE2C
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x7
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB04:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	bl SetContinueGameWarpStatusToDynamicWarp
	movs r0, 0
	bl TrySavingData
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x8
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB28:
	movs r0, 0x11
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x9
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB40:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	movs r0, 0x37
	bl PlaySE
	bl ClearContinueGameWarpStatus2
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xA
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB64:
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x19]
	ldr r1, [r4]
	movs r0, 0xB
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801EB72:
	ldr r0, [r4]
	ldrb r1, [r0, 0x19]
	adds r1, 0x1
	strb r1, [r0, 0x19]
	ldr r1, [r4]
	ldrb r0, [r1, 0x19]
	cmp r0, 0x78
	bls _0801EBC2
_0801EB82:
	movs r0, 0xC
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801EB88:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xD
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EBA8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801EBC2
	bl sub_801F544
	bl sub_801DE30
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
_0801EBC2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801E978

	thumb_func_start sub_801EBD4
sub_801EBD4: @ 801EBD4
	ldr r1, =gUnknown_02022C84
	ldr r1, [r1]
	movs r2, 0
	strh r0, [r1, 0x4]
	strh r2, [r1, 0x6]
	bx lr
	.pool
	thumb_func_end sub_801EBD4

	thumb_func_start sub_801EBE4
sub_801EBE4: @ 801EBE4
	push {lr}
	ldr r0, =gMain
	ldrh r2, [r0, 0x30]
	movs r0, 0x40
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _0801EC6E
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _0801EC24
	ldr r0, =gUnknown_02022C84
	ldr r2, [r0]
	ldr r1, =gUnknown_082F2AA4
	ldrb r0, [r2, 0x10]
	adds r0, r1
	ldrb r1, [r2, 0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0801EC20
	adds r0, r1, 0x1
	b _0801EC88
	.pool
_0801EC20:
	strb r3, [r2, 0x12]
	b _0801EC8A
_0801EC24:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0x3
	beq _0801EC6A
	movs r0, 0x20
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _0801EC52
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _0801EC4C
	subs r0, 0x1
	strb r0, [r1, 0x11]
	b _0801EC8A
	.pool
_0801EC4C:
	movs r0, 0x4
	strb r0, [r1, 0x11]
	b _0801EC8A
_0801EC52:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _0801EC6A
	ldrb r0, [r1, 0x11]
	cmp r0, 0x3
	bhi _0801EC66
	adds r0, 0x1
	strb r0, [r1, 0x11]
	b _0801EC8A
_0801EC66:
	strb r3, [r1, 0x11]
	b _0801EC8A
_0801EC6A:
	movs r0, 0
	b _0801EC8C
_0801EC6E:
	ldr r0, =gUnknown_02022C84
	ldr r2, [r0]
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0801EC80
	subs r0, 0x1
	b _0801EC88
	.pool
_0801EC80:
	ldr r0, =gUnknown_082F2AA4
	ldrb r1, [r2, 0x10]
	adds r1, r0
	ldrb r0, [r1]
_0801EC88:
	strb r0, [r2, 0x12]
_0801EC8A:
	movs r0, 0x1
_0801EC8C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EBE4

	thumb_func_start sub_801EC94
sub_801EC94: @ 801EC94
	push {r4-r6,lr}
	sub sp, 0x18
	ldr r0, =gUnknown_02022C84
	ldr r5, [r0]
	ldrb r0, [r5, 0x10]
	cmp r0, 0x3
	beq _0801ECDC
	ldr r3, =gUnknown_082F2BA8
	ldrb r1, [r5, 0x12]
	lsls r1, 2
	adds r2, r0, 0
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r3
	ldr r4, [r1]
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _0801ECCE
	adds r1, r0, 0
_0801ECBE:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne _0801ECC6
	adds r4, 0x1
_0801ECC6:
	adds r4, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _0801ECBE
_0801ECCE:
	movs r5, 0x1
	b _0801ED02
	.pool
_0801ECDC:
	ldrb r0, [r5, 0x12]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r0
	adds r1, 0xB9
	adds r1, r5, r1
	mov r0, sp
	bl StringCopy
	movs r1, 0
	strb r1, [r0]
	movs r1, 0xFF
	strb r1, [r0, 0x1]
	mov r4, sp
	mov r0, sp
	bl StringLength_Multibyte
	adds r5, r0, 0
_0801ED02:
	ldr r6, =gUnknown_02022C84
	ldr r1, [r6]
	ldrb r0, [r1, 0x15]
	strb r0, [r1, 0x14]
	cmp r4, 0
	beq _0801ED5A
	bl sub_801EE84
	adds r2, r0, 0
	subs r5, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801ED56
	ldr r0, [r6]
	ldrb r0, [r0, 0x15]
	cmp r0, 0xE
	bhi _0801ED56
	adds r3, r6, 0
_0801ED28:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne _0801ED34
	strb r0, [r2]
	adds r4, 0x1
	adds r2, 0x1
_0801ED34:
	ldrb r0, [r4]
	strb r0, [r2]
	adds r4, 0x1
	adds r2, 0x1
	ldr r1, [r3]
	ldrb r0, [r1, 0x15]
	adds r0, 0x1
	strb r0, [r1, 0x15]
	subs r5, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801ED56
	ldr r0, [r3]
	ldrb r0, [r0, 0x15]
	cmp r0, 0xE
	bls _0801ED28
_0801ED56:
	movs r0, 0xFF
	strb r0, [r2]
_0801ED5A:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EC94

	thumb_func_start sub_801ED68
sub_801ED68: @ 801ED68
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	strb r0, [r1, 0x14]
	ldr r0, [r4]
	ldrb r0, [r0, 0x15]
	cmp r0, 0
	beq _0801ED8A
	bl sub_801EEA8
	movs r1, 0xFF
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	subs r0, 0x1
	strb r0, [r1, 0x15]
_0801ED8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801ED68

	thumb_func_start sub_801ED94
sub_801ED94: @ 801ED94
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x15]
	subs r0, 0x1
	strb r0, [r1, 0x14]
	bl sub_801EEA8
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0xF9
	beq _0801EDB8
	ldr r1, =gUnknown_082F2AA8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801EDB8
	strb r0, [r2]
_0801EDB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801ED94

	thumb_func_start sub_801EDC4
sub_801EDC4: @ 801EDC4
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	cmp r0, 0
	bne _0801EDD8
	movs r0, 0
	b _0801EDDA
	.pool
_0801EDD8:
	movs r0, 0x1
_0801EDDA:
	pop {r1}
	bx r1
	thumb_func_end sub_801EDC4

	thumb_func_start sub_801EDE0
sub_801EDE0: @ 801EDE0
	push {r4,lr}
	bl sub_801F114
	adds r1, r0, 0
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r3, [r0, 0x12]
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 2
	adds r2, r3
	adds r2, 0xB9
	adds r0, r2
	bl StringCopy
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EDE0

	thumb_func_start sub_801EE10
sub_801EE10: @ 801EE10
	ldr r1, =gUnknown_02022C84
	ldr r2, [r1]
	movs r0, 0xFF
	strb r0, [r2, 0x1A]
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0xF
	strb r0, [r2, 0x14]
	ldr r0, [r1]
	strb r3, [r0, 0x15]
	bx lr
	.pool
	thumb_func_end sub_801EE10

	thumb_func_start sub_801EE2C
sub_801EE2C: @ 801EE2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r7, =gUnknown_02022C84
	movs r6, 0xB9
	ldr r5, =0x00003c88
	movs r4, 0x9
_0801EE3E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	ldr r1, [r7]
	adds r1, r6
	bl StringCopy
	adds r6, 0x15
	adds r5, 0x15
	subs r4, 0x1
	cmp r4, 0
	bge _0801EE3E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EE2C

	thumb_func_start sub_801EE6C
sub_801EE6C: @ 801EE6C
	ldr r2, =gUnknown_02022C84
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r0
	adds r1, 0xB9
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801EE6C

	thumb_func_start sub_801EE84
sub_801EE84: @ 801EE84
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	ldrb r0, [r0, 0x1A]
	cmp r0, 0xFF
	beq _0801EE9C
_0801EE94:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0801EE94
_0801EE9C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EE84

	thumb_func_start sub_801EEA8
sub_801EEA8: @ 801EEA8
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x1A
	adds r1, r2, 0
	ldrb r0, [r0, 0x1A]
	cmp r0, 0xFF
	beq _0801EECC
_0801EEBA:
	adds r2, r1, 0
	ldrb r0, [r2]
	cmp r0, 0xF9
	bne _0801EEC4
	adds r1, r2, 0x1
_0801EEC4:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0801EEBA
_0801EECC:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EEA8

	thumb_func_start sub_801EED8
sub_801EED8: @ 801EED8
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	adds r0, 0x1A
	bl StringLength_Multibyte
	adds r2, r0, 0
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x1A
	movs r4, 0
	cmp r2, 0xA
	bls _0801EF0C
	subs r2, 0xA
	movs r3, 0
	cmp r4, r2
	bcs _0801EF0C
_0801EEFA:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801EF02
	adds r1, 0x1
_0801EF02:
	adds r1, 0x1
	adds r4, 0x1
	adds r3, 0x1
	cmp r3, r2
	bcc _0801EEFA
_0801EF0C:
	lsls r0, r4, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EED8

	thumb_func_start sub_801EF1C
sub_801EF1C: @ 801EF1C
	movs r1, 0
	strb r1, [r0]
	bx lr
	thumb_func_end sub_801EF1C

	thumb_func_start sub_801EF24
sub_801EF24: @ 801EF24
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF24

	thumb_func_start sub_801EF4C
sub_801EF4C: @ 801EF4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r4, 0x9
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	adds r1, 0x1A
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF4C

	thumb_func_start sub_801EF7C
sub_801EF7C: @ 801EF7C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	bl sub_8011A50
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF7C

	thumb_func_start sub_801EFA8
sub_801EFA8: @ 801EFA8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EFA8

	thumb_func_start sub_801EFD0
sub_801EFD0: @ 801EFD0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EFD0

	thumb_func_start sub_801EFF8
sub_801EFF8: @ 801EFF8
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldrb r0, [r5]
	adds r1, r0, 0
	adds r4, r5, 0x1
	adds r5, r4, 0
	adds r5, 0x8
	cmp r0, 0x2
	beq _0801F020
	cmp r0, 0x2
	bgt _0801F016
	cmp r0, 0x1
	beq _0801F044
	b _0801F0A8
_0801F016:
	cmp r1, 0x3
	beq _0801F07A
	cmp r1, 0x5
	beq _0801F06E
	b _0801F0A8
_0801F020:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	ldrb r1, [r4, 0x8]
	cmp r0, r1
	beq _0801F0A8
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, =gText_F700JoinedChat
	b _0801F094
	.pool
_0801F044:
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringCopy
	movs r1, 0xFC
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x13
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x2A
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF0
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	bl StringCopy
	movs r0, 0x1
	b _0801F0AA
_0801F06E:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x79
	adds r1, r4, 0
	bl StringCopy
_0801F07A:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	ldrb r5, [r5]
	cmp r0, r5
	beq _0801F0A8
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, =gText_F700LeftChat
_0801F094:
	adds r0, r6, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x1
	b _0801F0AA
	.pool
_0801F0A8:
	movs r0, 0
_0801F0AA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801EFF8

	thumb_func_start sub_801F0B0
sub_801F0B0: @ 801F0B0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bx lr
	.pool
	thumb_func_end sub_801F0B0

	thumb_func_start sub_801F0BC
sub_801F0BC: @ 801F0BC
	ldr r2, =gUnknown_02022C84
	ldr r3, [r2]
	ldrb r2, [r3, 0x11]
	strb r2, [r0]
	ldrb r0, [r3, 0x12]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801F0BC

	thumb_func_start sub_801F0D0
sub_801F0D0: @ 801F0D0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x1A
	bx lr
	.pool
	thumb_func_end sub_801F0D0

	thumb_func_start sub_801F0DC
sub_801F0DC: @ 801F0DC
	push {lr}
	bl sub_801F0D0
	bl StringLength_Multibyte
	pop {r1}
	bx r1
	thumb_func_end sub_801F0DC

	thumb_func_start sub_801F0EC
sub_801F0EC: @ 801F0EC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r3, [r0, 0x15]
	ldrb r2, [r0, 0x14]
	subs r0, r3, r2
	cmp r0, 0
	bge _0801F108
	negs r0, r0
	str r3, [r4]
	b _0801F10A
	.pool
_0801F108:
	str r2, [r4]
_0801F10A:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801F0EC

	thumb_func_start sub_801F114
sub_801F114: @ 801F114
	push {lr}
	bl sub_801EED8
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	cmp r2, 0
	beq _0801F13A
_0801F12A:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801F132
	adds r1, 0x1
_0801F132:
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0801F12A
_0801F13A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801F114

	thumb_func_start sub_801F144
sub_801F144: @ 801F144
	push {r4,lr}
	bl sub_801EED8
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	movs r2, 0
	movs r3, 0
	cmp r2, r4
	bcs _0801F174
_0801F15E:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801F166
	adds r1, 0x1
_0801F166:
	adds r1, 0x1
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, 0x1
	cmp r3, r4
	bcc _0801F15E
_0801F174:
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801F144

	thumb_func_start sub_801F180
sub_801F180: @ 801F180
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x39
	bx lr
	.pool
	thumb_func_end sub_801F180

	thumb_func_start sub_801F18C
sub_801F18C: @ 801F18C
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x16]
	bx lr
	.pool
	thumb_func_end sub_801F18C

	thumb_func_start sub_801F198
sub_801F198: @ 801F198
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	bx lr
	.pool
	thumb_func_end sub_801F198

	thumb_func_start sub_801F1A4
sub_801F1A4: @ 801F1A4
	push {lr}
	bl sub_801EEA8
	ldrb r1, [r0]
	cmp r1, 0xFF
	bhi _0801F1BE
	ldr r0, =gUnknown_082F2AA8
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, r1
	beq _0801F1BE
	cmp r0, 0
	bne _0801F1C8
_0801F1BE:
	movs r0, 0x3
	b _0801F1CA
	.pool
_0801F1C8:
	movs r0, 0
_0801F1CA:
	pop {r1}
	bx r1
	thumb_func_end sub_801F1A4

	thumb_func_start sub_801F1D0
sub_801F1D0: @ 801F1D0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x79
	bx lr
	.pool
	thumb_func_end sub_801F1D0

	thumb_func_start copy_strings_to_sav1
copy_strings_to_sav1: @ 801F1DC
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003c88
	adds r0, r1
	ldr r1, =gText_Hello
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003c9d
	adds r0, r1
	ldr r1, =gText_Pokemon2
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cb2
	adds r0, r1
	ldr r1, =gText_Trade
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cc7
	adds r0, r1
	ldr r1, =gText_Battle
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cdc
	adds r0, r1
	ldr r1, =gText_Lets
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cf1
	adds r0, r1
	ldr r1, =gText_Ok
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d06
	adds r0, r1
	ldr r1, =gText_Sorry
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d1b
	adds r0, r1
	ldr r1, =gText_YayUnkF9F9
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d30
	adds r0, r1
	ldr r1, =gText_ThankYou
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d45
	adds r0, r1
	ldr r1, =gText_ByeBye
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_strings_to_sav1

	thumb_func_start sub_801F2B4
sub_801F2B4: @ 801F2B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bls _0801F2CE
	b _0801F4C4
_0801F2CE:
	lsls r0, 2
	ldr r1, =_0801F2E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F2E0:
	.4byte _0801F300
	.4byte _0801F30E
	.4byte _0801F4A8
	.4byte _0801F35C
	.4byte _0801F448
	.4byte _0801F480
	.4byte _0801F494
	.4byte _0801F438
_0801F300:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801F30A
	b _0801F49C
_0801F30A:
	movs r0, 0x1
	strh r0, [r4]
_0801F30E:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	strh r0, [r4, 0x8]
	ldr r3, =gUnknown_02022C84
	ldr r0, [r3]
	ldrb r1, [r0, 0xD]
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	cmp r1, r0
	beq _0801F33C
	movs r0, 0x2
	strh r0, [r4]
	ldr r0, [r3]
	strb r2, [r0, 0xD]
	b _0801F4C4
	.pool
_0801F33C:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x6]
	cmp r0, 0
	bne _0801F354
	bl sub_8011A9C
	cmp r0, 0
	beq _0801F354
	b _0801F4C4
_0801F354:
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x3
	strh r0, [r4]
_0801F35C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bgt _0801F396
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801F396
	movs r2, 0x1
_0801F378:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _0801F396
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	ands r0, r2
	cmp r0, 0
	beq _0801F378
_0801F396:
	ldrh r1, [r4, 0x2]
	movs r5, 0x2
	ldrsh r0, [r4, r5]
	cmp r0, 0x5
	bne _0801F3A2
	b _0801F4C0
_0801F3A2:
	strh r1, [r4, 0x4]
	lsls r0, r1, 24
	lsrs r0, 24
	bl ResetBlockReceivedFlag
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	lsls r0, 8
	ldr r1, =gBlockRecvBuffer
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r0, 0x4
	bhi _0801F3E4
	lsls r0, 2
	ldr r1, =_0801F3D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F3D0:
	.4byte _0801F3E4
	.4byte _0801F3E8
	.4byte _0801F3EC
	.4byte _0801F3F0
	.4byte _0801F3F4
_0801F3E4:
	movs r0, 0x3
	b _0801F3F6
_0801F3E8:
	movs r0, 0x3
	b _0801F3F6
_0801F3EC:
	movs r0, 0x4
	b _0801F3F6
_0801F3F0:
	movs r0, 0x5
	b _0801F3F6
_0801F3F4:
	movs r0, 0x6
_0801F3F6:
	strh r0, [r4, 0xA]
	ldr r5, =gUnknown_02022C84
	ldr r0, [r5]
	adds r0, 0x39
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 8
	ldr r2, =gBlockRecvBuffer
	adds r1, r2
	bl sub_801EFF8
	cmp r0, 0
	beq _0801F42C
	ldr r0, [r5]
	ldrh r1, [r4, 0x2]
	strb r1, [r0, 0x16]
	movs r0, 0xC
	movs r1, 0x2
	bl sub_801F5EC
	movs r0, 0x7
	b _0801F42E
	.pool
_0801F42C:
	ldrh r0, [r4, 0xA]
_0801F42E:
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _0801F4C4
_0801F438:
	movs r0, 0x2
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801F4C4
	ldrh r0, [r4, 0xA]
	b _0801F4C2
_0801F448:
	ldr r6, =gUnknown_02022C84
	ldr r0, [r6]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	bne _0801F47C
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0801F47C
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0801F474
	bl sub_80104B0
	ldr r1, [r6]
	movs r0, 0x1
	b _0801F49A
	.pool
_0801F474:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	bl sub_8011DE0
_0801F47C:
	movs r0, 0x3
	b _0801F4C2
_0801F480:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _0801F49C
	movs r0, 0x2
	b _0801F49A
	.pool
_0801F494:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
_0801F49A:
	strb r0, [r1, 0x17]
_0801F49C:
	adds r0, r5, 0
	bl DestroyTask
	b _0801F4C4
	.pool
_0801F4A8:
	bl sub_8011A9C
	cmp r0, 0
	bne _0801F4C4
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801F4C0
	ldrb r0, [r1, 0xD]
	bl sub_80110B8
_0801F4C0:
	movs r0, 0x1
_0801F4C2:
	strh r0, [r4]
_0801F4C4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F2B4

	thumb_func_start sub_801F4D0
sub_801F4D0: @ 801F4D0
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, =0x00002168
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _0801F52C
	bl sub_8020890
	cmp r0, 0
	beq _0801F52C
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F2C60
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_082F2C70
	bl InitWindows
	bl reset_temp_tile_data_buffers
	bl sub_8020770
	ldr r0, [r4]
	bl sub_801F574
	bl sub_801F580
	movs r0, 0
	movs r1, 0
	bl sub_801F5EC
	movs r0, 0x1
	b _0801F52E
	.pool
_0801F52C:
	movs r0, 0
_0801F52E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F4D0

	thumb_func_start sub_801F534
sub_801F534: @ 801F534
	push {lr}
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_801F534

	thumb_func_start sub_801F544
sub_801F544: @ 801F544
	push {r4,lr}
	bl sub_80208D0
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	cmp r0, 0
	beq _0801F55A
	bl Free
	movs r0, 0
	str r0, [r4]
_0801F55A:
	bl FreeAllWindowBuffers
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F544

	thumb_func_start sub_801F574
sub_801F574: @ 801F574
	movs r2, 0
	movs r1, 0xFF
	strh r1, [r0, 0x18]
	strh r1, [r0, 0x1E]
	strh r2, [r0, 0x1A]
	bx lr
	thumb_func_end sub_801F574

	thumb_func_start sub_801F580
sub_801F580: @ 801F580
	push {r4,r5,lr}
	ldr r1, =gUnknown_02022C88
	ldr r0, [r1]
	cmp r0, 0
	beq _0801F5A8
	movs r2, 0
	adds r4, r1, 0
	ldr r5, =sub_801FDD8
	movs r3, 0
_0801F592:
	ldr r0, [r4]
	lsls r1, r2, 3
	adds r0, r1
	str r5, [r0]
	strb r3, [r0, 0x4]
	ldr r0, [r4]
	adds r0, r1
	strb r3, [r0, 0x5]
	adds r2, 0x1
	cmp r2, 0x2
	ble _0801F592
_0801F5A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F580

	thumb_func_start sub_801F5B8
sub_801F5B8: @ 801F5B8
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C88
	ldr r0, [r1]
	cmp r0, 0
	beq _0801F5E0
	movs r5, 0
	adds r6, r1, 0
_0801F5C6:
	ldr r1, [r6]
	lsls r4, r5, 3
	adds r1, r4
	adds r0, r1, 0x5
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, [r6]
	adds r1, r4
	strb r0, [r1, 0x4]
	adds r5, 0x1
	cmp r5, 0x2
	ble _0801F5C6
_0801F5E0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F5B8

	thumb_func_start sub_801F5EC
sub_801F5EC: @ 801F5EC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	ldr r3, =gUnknown_02022C88
	ldr r0, [r3]
	lsrs r1, 21
	adds r0, r1
	ldr r2, =sub_801FDD8
	str r2, [r0]
	movs r4, 0
	adds r5, r3, 0
	adds r3, r1, 0
	mov r12, r4
	ldr r1, =gUnknown_082F2C98
	movs r7, 0x1
	adds r2, r1, 0x4
_0801F60E:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0801F634
	ldr r1, [r5]
	adds r1, r3
	ldr r0, [r2]
	str r0, [r1]
	strb r7, [r1, 0x4]
	ldr r0, [r5]
	adds r0, r3
	mov r1, r12
	strb r1, [r0, 0x5]
	b _0801F63E
	.pool
_0801F634:
	adds r1, 0x8
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x14
	bls _0801F60E
_0801F63E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801F5EC

	thumb_func_start sub_801F644
sub_801F644: @ 801F644
	lsls r0, 24
	ldr r1, =gUnknown_02022C88
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	ldrb r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_801F644

	thumb_func_start sub_801F658
sub_801F658: @ 801F658
	push {r4,lr}
	adds r4, r0, 0
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801F6EE
	ldrb r0, [r4]
	cmp r0, 0x6
	bhi _0801F6E4
	lsls r0, 2
	ldr r1, =_0801F67C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F67C:
	.4byte _0801F698
	.4byte _0801F6A2
	.4byte _0801F6A8
	.4byte _0801F6AE
	.4byte _0801F6B4
	.4byte _0801F6BA
	.4byte _0801F6CC
_0801F698:
	bl sub_8020480
	bl sub_8020538
	b _0801F6E8
_0801F6A2:
	bl sub_8020584
	b _0801F6E8
_0801F6A8:
	bl sub_80205B4
	b _0801F6E8
_0801F6AE:
	bl task_tutorial_story_unknown
	b _0801F6E8
_0801F6B4:
	bl sub_8020680
	b _0801F6E8
_0801F6BA:
	bl sub_80206A4
	bl sub_80206D0
	bl sub_8020740
	bl sub_80206E8
	b _0801F6E8
_0801F6CC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F6E8
	bl sub_80208E8
	bl sub_8020A68
	bl sub_8020B20
	b _0801F6E8
_0801F6E4:
	movs r0, 0
	b _0801F6F0
_0801F6E8:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F6EE:
	movs r0, 0x1
_0801F6F0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F658

	thumb_func_start sub_801F6F8
sub_801F6F8: @ 801F6F8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F708
	cmp r0, 0x1
	beq _0801F716
	b _0801F720
_0801F708:
	bl sub_80203B0
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F720
_0801F716:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F728
_0801F720:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F728:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F6F8

	thumb_func_start sub_801F730
sub_801F730: @ 801F730
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F740
	cmp r0, 0x1
	beq _0801F74E
	b _0801F758
_0801F740:
	bl sub_802040C
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F758
_0801F74E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F760
_0801F758:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F760:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F730

	thumb_func_start sub_801F768
sub_801F768: @ 801F768
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _0801F79E
	cmp r0, 0x1
	bgt _0801F77C
	cmp r0, 0
	beq _0801F782
	b _0801F7C4
_0801F77C:
	cmp r0, 0x2
	beq _0801F7AA
	b _0801F7C4
_0801F782:
	movs r0, 0x1
	bl sub_802091C
	bl sub_8020320
	cmp r0, 0
	bne _0801F7CA
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F7C4
_0801F79E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _0801F7C4
	b _0801F7CA
_0801F7AA:
	bl sub_8020368
	cmp r0, 0
	bne _0801F7CA
	bl sub_802093C
	movs r0, 0
	bl sub_802091C
	bl sub_8020B80
	movs r0, 0
	b _0801F7CC
_0801F7C4:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F7CA:
	movs r0, 0x1
_0801F7CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F768

	thumb_func_start sub_801F7D4
sub_801F7D4: @ 801F7D4
	push {lr}
	bl sub_802093C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_801F7D4

	thumb_func_start sub_801F7E0
sub_801F7E0: @ 801F7E0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F7F0
	cmp r0, 0x1
	beq _0801F814
	b _0801F81E
_0801F7F0:
	movs r0, 0
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xB
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F81E
	.pool
_0801F814:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F826
_0801F81E:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F7E0

	thumb_func_start sub_801F82C
sub_801F82C: @ 801F82C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F83C
	cmp r0, 0x1
	beq _0801F84C
	b _0801F862
_0801F83C:
	bl sub_8020094
	bl sub_801FEBC
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	b _0801F862
_0801F84C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F868
	bl sub_80200C8
	bl sub_801FEE4
	movs r0, 0
	b _0801F86A
_0801F862:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F868:
	movs r0, 0x1
_0801F86A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F82C

	thumb_func_start sub_801F870
sub_801F870: @ 801F870
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F882
	cmp r0, 0x1
	beq _0801F8BA
	b _0801F8CC
_0801F882:
	add r1, sp, 0x8
	add r0, sp, 0x4
	bl sub_801F0EC
	ldr r0, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x8]
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0
	bl sub_80200EC
	bl sub_801F0D0
	adds r1, r0, 0
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F8CC
_0801F8BA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F8D2
	bl sub_8020B80
	movs r0, 0
	b _0801F8D4
_0801F8CC:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F8D2:
	movs r0, 0x1
_0801F8D4:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F870

	thumb_func_start sub_801F8DC
sub_801F8DC: @ 801F8DC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F938
	cmp r0, 0x1
	bgt _0801F8F2
	cmp r0, 0
	beq _0801F8FC
	b _0801F972
_0801F8F2:
	cmp r0, 0x2
	beq _0801F95C
	cmp r0, 0x3
	beq _0801F96E
	b _0801F972
_0801F8FC:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x66
	bl sub_80200EC
	movs r0, 0x5
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x4
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F972
_0801F938:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F972
	.pool
_0801F95C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	bl sub_80209AC
	b _0801F972
_0801F96E:
	movs r0, 0
	b _0801F97A
_0801F972:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801F978:
	movs r0, 0x1
_0801F97A:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F8DC

	thumb_func_start sub_801F984
sub_801F984: @ 801F984
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F9E0
	cmp r0, 0x1
	bgt _0801F99A
	cmp r0, 0
	beq _0801F9A4
	b _0801FA1A
_0801F99A:
	cmp r0, 0x2
	beq _0801FA00
	cmp r0, 0x3
	beq _0801FA16
	b _0801FA1A
_0801F9A4:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl sub_80200EC
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FA1A
_0801F9E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	bl sub_8020094
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801FA1A
	.pool
_0801FA00:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	movs r0, 0
	bl sub_80209AC
	bl sub_80200C8
	b _0801FA1A
_0801FA16:
	movs r0, 0
	b _0801FA22
_0801FA1A:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FA20:
	movs r0, 0x1
_0801FA22:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F984

	thumb_func_start sub_801FA2C
sub_801FA2C: @ 801FA2C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FA3C
	cmp r0, 0x1
	beq _0801FA50
	b _0801FA5E
_0801FA3C:
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FA5E
_0801FA50:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA5E
	movs r0, 0
	b _0801FA60
_0801FA5E:
	movs r0, 0x1
_0801FA60:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA2C

	thumb_func_start sub_801FA68
sub_801FA68: @ 801FA68
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x4
	bhi _0801FB3A
	lsls r0, 2
	ldr r1, =_0801FA80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801FA80:
	.4byte _0801FA94
	.4byte _0801FAC0
	.4byte _0801FAF0
	.4byte _0801FB14
	.4byte _0801FADE
_0801FA94:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r5, [r0, 0x1A]
	bl sub_801F180
	adds r4, r0, 0
	bl sub_801F18C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8020420
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FB34
	.pool
_0801FAC0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1A]
	cmp r0, 0x8
	bhi _0801FAE8
	adds r0, 0x1
	strh r0, [r1, 0x1A]
	movs r0, 0x4
	strb r0, [r6]
_0801FADE:
	movs r0, 0
	b _0801FB3C
	.pool
_0801FAE8:
	strh r2, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FAF0:
	movs r0, 0
	movs r1, 0
	movs r2, 0x5
	movs r3, 0x11
	bl ScrollWindow
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FB14:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r0, [r0, 0x1C]
	cmp r0, 0x2
	bhi _0801FB34
	ldrb r0, [r6]
	subs r0, 0x1
	b _0801FB38
	.pool
_0801FB34:
	ldrb r0, [r6]
	adds r0, 0x1
_0801FB38:
	strb r0, [r6]
_0801FB3A:
	movs r0, 0x1
_0801FB3C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA68

	thumb_func_start sub_801FB44
sub_801FB44: @ 801FB44
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB54
	cmp r0, 0x1
	beq _0801FB60
	b _0801FB66
_0801FB54:
	bl sub_80209E0
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FB66
_0801FB60:
	bl sub_8020A1C
	b _0801FB68
_0801FB66:
	movs r0, 0x1
_0801FB68:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB44

	thumb_func_start sub_801FB70
sub_801FB70: @ 801FB70
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB80
	cmp r0, 0x1
	beq _0801FBA0
	b _0801FBAA
_0801FB80:
	movs r0, 0x3
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBAA
	.pool
_0801FBA0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBAC
_0801FBAA:
	movs r0, 0x1
_0801FBAC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB70

	thumb_func_start sub_801FBB4
sub_801FBB4: @ 801FBB4
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FBC4
	cmp r0, 0x1
	beq _0801FBE4
	b _0801FBEE
_0801FBC4:
	movs r0, 0x4
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBEE
	.pool
_0801FBE4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBF0
_0801FBEE:
	movs r0, 0x1
_0801FBF0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBB4

	thumb_func_start sub_801FBF8
sub_801FBF8: @ 801FBF8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC08
	cmp r0, 0x1
	beq _0801FC38
	b _0801FC42
_0801FC08:
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_801F1D0
	adds r1, r0, 0
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x5
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC42
	.pool
_0801FC38:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC44
_0801FC42:
	movs r0, 0x1
_0801FC44:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBF8

	thumb_func_start sub_801FC4C
sub_801FC4C: @ 801FC4C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC5C
	cmp r0, 0x1
	beq _0801FC88
	b _0801FC92
_0801FC5C:
	movs r0, 0x6
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC92
	.pool
_0801FC88:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC94
_0801FC92:
	movs r0, 0x1
_0801FC94:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC4C

	thumb_func_start sub_801FC9C
sub_801FC9C: @ 801FC9C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCAC
	cmp r0, 0x1
	beq _0801FCD8
	b _0801FCE2
_0801FCAC:
	movs r0, 0x7
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FCE2
	.pool
_0801FCD8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FCE4
_0801FCE2:
	movs r0, 0x1
_0801FCE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC9C

	thumb_func_start sub_801FCEC
sub_801FCEC: @ 801FCEC
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCFC
	cmp r0, 0x1
	beq _0801FD1C
	b _0801FD26
_0801FCFC:
	movs r0, 0x8
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD26
	.pool
_0801FD1C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD28
_0801FD26:
	movs r0, 0x1
_0801FD28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FCEC

	thumb_func_start sub_801FD30
sub_801FD30: @ 801FD30
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD40
	cmp r0, 0x1
	beq _0801FD74
	b _0801FD7E
_0801FD40:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x9
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD7E
	.pool
_0801FD74:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD80
_0801FD7E:
	movs r0, 0x1
_0801FD80:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD30

	thumb_func_start sub_801FD88
sub_801FD88: @ 801FD88
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD98
	cmp r0, 0x1
	beq _0801FDC4
	b _0801FDCE
_0801FD98:
	movs r0, 0xA
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FDCE
	.pool
_0801FDC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FDD0
_0801FDCE:
	movs r0, 0x1
_0801FDD0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD88

	thumb_func_start sub_801FDD8
sub_801FDD8: @ 801FDD8
	movs r0, 0
	bx lr
	thumb_func_end sub_801FDD8

	thumb_func_start sub_801FDDC
sub_801FDDC: @ 801FDDC
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsls r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r4, =0xffffff00
	ldr r2, [sp, 0xC]
	ands r2, r4
	lsrs r0, 16
	ldr r3, =0xffff00ff
	ands r2, r3
	orrs r2, r0
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r2, r0
	orrs r2, r1
	ldr r0, =0x00ffffff
	ands r2, r0
	movs r0, 0xC0
	lsls r0, 19
	orrs r2, r0
	str r2, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r4
	movs r1, 0x4
	orrs r0, r1
	ands r0, r3
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xA4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl AddWindow
	adds r1, r0, 0
	ldr r5, =gUnknown_02022C88
	ldr r0, [r5]
	movs r6, 0
	strh r1, [r0, 0x18]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _0801FE94
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r4, 0xFF
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x2
	adds r2, r7, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
_0801FE94:
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FDDC

	thumb_func_start sub_801FEBC
sub_801FEBC: @ 801FEBC
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEDA
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8198070
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl ClearWindowTilemap
_0801FEDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEBC

	thumb_func_start sub_801FEE4
sub_801FEE4: @ 801FEE4
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEFE
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x18]
_0801FEFE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEE4

	thumb_func_start sub_801FF08
sub_801FF08: @ 801FF08
	push {lr}
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_801FF08

	thumb_func_start sub_801FF18
sub_801FF18: @ 801FF18
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	adds r7, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r1, =0xffffff00
	ldr r3, [sp, 0x14]
	ands r3, r1
	ldr r2, =0xffff00ff
	ands r3, r2
	movs r0, 0x80
	lsls r0, 4
	orrs r3, r0
	ldr r0, =0xff00ffff
	ands r3, r0
	movs r0, 0x80
	lsls r0, 13
	orrs r3, r0
	ldr r5, =0x00ffffff
	ands r3, r5
	movs r0, 0xA8
	lsls r0, 21
	orrs r3, r0
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x18]
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	ands r0, r2
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xD4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x18]
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0801FF98
	lsls r0, r3, 16
	movs r1, 0xF9
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	ands r2, r3
	orrs r2, r0
	lsrs r1, r2, 24
	adds r1, 0x7
	lsls r1, 24
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
_0801FF98:
	add r0, sp, 0x14
	bl AddWindow
	ldr r5, =gUnknown_02022C88
	ldr r1, [r5]
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x1E]
	mov r8, r0
	cmp r0, 0xFF
	beq _08020082
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801FFE0
	adds r0, r1, 0
	adds r0, 0x22
	ldr r1, [r4]
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r5]
	adds r6, r0, 0
	adds r6, 0x22
	b _0801FFE2
	.pool
_0801FFE0:
	ldr r6, [r4]
_0801FFE2:
	mov r0, r9
	lsls r1, r0, 8
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
	mov r1, r8
	lsls r0, r1, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0x1
	bne _08020050
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_80989E0
	ldrb r3, [r4, 0x5]
	adds r3, 0x8
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x6]
	adds r0, 0x8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
	b _0802007A
	.pool
_08020050:
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_8098858
	ldrb r3, [r4, 0x5]
	ldrb r0, [r4, 0x6]
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
_0802007A:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, 0x1E]
_08020082:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FF18

	thumb_func_start sub_8020094
sub_8020094: @ 8020094
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200B2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8198070
	ldr r0, [r4]
	ldrb r0, [r0, 0x1E]
	bl ClearWindowTilemap
_080200B2:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020094

	thumb_func_start sub_80200C8
sub_80200C8: @ 80200C8
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200E2
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x1E]
_080200E2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80200C8

	thumb_func_start sub_80200EC
sub_80200EC: @ 80200EC
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 19
	lsrs r3, 16
	lsls r1, 19
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	movs r0, 0x1
	adds r1, r2, 0
	adds r2, r3, 0
	movs r3, 0x1
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80200EC

	thumb_func_start sub_8020118
sub_8020118: @ 8020118
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r10, r1
	ldr r1, [sp, 0x54]
	lsls r0, 16
	lsrs r5, r0, 16
	mov r9, r5
	lsls r2, 24
	lsrs r4, r2, 24
	mov r8, r4
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0
	beq _08020154
	bl sub_801F198
	adds r1, r0, 0
	subs r1, r5
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_80200EC
_08020154:
	add r0, sp, 0xC
	mov r1, r8
	strb r1, [r0]
	strb r7, [r0, 0x1]
	strb r6, [r0, 0x2]
	add r4, sp, 0x10
	movs r0, 0xFC
	strb r0, [r4]
	movs r0, 0x14
	strb r0, [r4, 0x1]
	movs r0, 0x8
	strb r0, [r4, 0x2]
	mov r0, sp
	adds r0, 0x13
	mov r1, r10
	bl StringCopy
	mov r0, r9
	lsls r2, r0, 27
	lsrs r2, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8020118

	thumb_func_start sub_80201A4
sub_80201A4: @ 80201A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	movs r0, 0x2
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	bl sub_801F0B0
	lsls r0, 24
	lsrs r2, r0, 24
	add r1, sp, 0xC
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xE
	strb r0, [r1, 0x1]
	movs r0, 0xD
	strb r0, [r1, 0x2]
	cmp r2, 0x3
	beq _08020240
	add r1, sp, 0x10
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x14
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	cmp r2, 0x2
	bne _080201EC
	movs r1, 0x6
	str r1, [sp, 0x40]
_080201EC:
	movs r7, 0
	movs r6, 0
	lsls r0, r2, 2
	ldr r1, =gUnknown_082F2BA8
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldr r0, [sp, 0x40]
	lsls r5, r0, 24
_080201FE:
	ldr r1, [r4]
	cmp r1, 0
	bne _08020206
	b _0802030C
_08020206:
	mov r0, sp
	adds r0, 0x13
	bl StringCopy
	lsls r3, r6, 24
	lsrs r3, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x44]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	lsrs r2, r5, 24
	bl AddTextPrinterParameterized3
	adds r4, 0x4
	adds r7, 0x1
	adds r0, r6, 0
	adds r0, 0xC
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _080201FE
	b _0802030C
	.pool
_08020240:
	movs r1, 0x4
	str r1, [sp, 0x40]
	movs r7, 0
	movs r6, 0
_08020248:
	adds r0, r7, 0
	bl sub_801EE6C
	adds r5, r0, 0
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x28
	bgt _08020286
	lsls r3, r6, 24
	lsrs r3, 24
	add r4, sp, 0xC
	str r4, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r4, 0x80
	lsls r4, 19
	lsrs r2, r4, 24
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	b _08020300
_08020286:
	adds r0, r5, 0
	bl StringLength_Multibyte
	adds r4, r0, 0
	mov r1, sp
	adds r1, 0x10
	str r1, [sp, 0x44]
	ldr r0, [sp, 0x40]
	lsls r0, 24
	mov r8, r0
	lsls r1, r6, 24
	mov r9, r1
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	ldr r7, [sp, 0x40]
	adds r7, 0x23
	ldr r6, [sp, 0x44]
_080202AC:
	subs r4, 0x1
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl StringCopyN_Multibyte
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x23
	bgt _080202AC
	mov r1, r8
	lsrs r2, r1, 24
	mov r0, r9
	lsrs r4, r0, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	str r1, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	adds r2, r7, 0
	add r0, sp, 0xC
	str r0, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	ldr r0, =gText_Ellipsis
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
_08020300:
	ldr r7, [sp, 0x48]
	mov r4, r10
	lsls r0, r4, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _08020248
_0802030C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80201A4

	thumb_func_start sub_8020320
sub_8020320: @ 8020320
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0x37
	bgt _08020354
	adds r0, r3, 0
	adds r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x37
	ble _08020348
	movs r0, 0x38
	strh r0, [r2, 0x20]
	b _08020354
	.pool
_08020348:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _08020360
_08020354:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_08020360:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020320

	thumb_func_start sub_8020368
sub_8020368: @ 8020368
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0
	ble _0802039C
	adds r0, r3, 0
	subs r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	cmp r0, 0
	bgt _08020390
	movs r0, 0
	strh r0, [r2, 0x20]
	b _0802039C
	.pool
_08020390:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _080203A8
_0802039C:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_080203A8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020368

	thumb_func_start sub_80203B0
sub_80203B0: @ 80203B0
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	movs r5, 0xE
	str r5, [sp]
	movs r4, 0x5
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_082F2DC8
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0x8
	movs r3, 0x1
	bl PrintTextArray
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	str r5, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x1
	bl sub_81983AC
	movs r0, 0x3
	bl PutWindowTilemap
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80203B0

	thumb_func_start sub_802040C
sub_802040C: @ 802040C
	push {lr}
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	pop {r0}
	bx r0
	thumb_func_end sub_802040C

	thumb_func_start sub_8020420
sub_8020420: @ 8020420
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 24
	add r3, sp, 0xC
	movs r1, 0x1
	strb r1, [r3]
	lsrs r2, 23
	adds r1, r2, 0x2
	strb r1, [r3, 0x1]
	adds r1, r3, 0
	adds r2, 0x3
	strb r2, [r1, 0x2]
	lsls r4, r0, 4
	subs r4, r0
	lsls r3, r4, 16
	lsrs r3, 16
	movs r0, 0xA8
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	add r0, sp, 0xC
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8020420

	thumb_func_start sub_8020480
sub_8020480: @ 8020480
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
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xE0
	lsls r1, 8
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x000040f0
	movs r0, 0x40
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3D
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020480

	thumb_func_start sub_8020538
sub_8020538: @ 8020538
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000928
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001128
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001928
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020538

	thumb_func_start sub_8020584
sub_8020584: @ 8020584
	push {lr}
	sub sp, 0x8
	movs r1, 0xC0
	lsls r1, 19
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8020584

	thumb_func_start sub_80205B4
sub_80205B4: @ 80205B4
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_08DD4BD0
	movs r1, 0x70
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08DD4BB0
	movs r1, 0xC0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_08DD4BF0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DD4C4C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80205B4

	thumb_func_start task_tutorial_story_unknown
task_tutorial_story_unknown: @ 8020604
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gLinkMiscMenu_Pal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gLinkMiscMenu_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r5, r0, 0
	cmp r5, 0
	beq _0802064E
	movs r1, 0x88
	lsls r1, 2
	adds r0, r5, r1
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	ldr r2, =0x00002128
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	movs r1, 0x84
	lsls r1, 3
	adds r0, r5, r1
	ldr r1, [r4]
	ldr r2, =0x00002148
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
_0802064E:
	ldr r1, =gLinkMiscMenu_Tilemap
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_tutorial_story_unknown

	thumb_func_start sub_8020680
sub_8020680: @ 8020680
	push {lr}
	ldr r0, =gUnknown_082F2C20
	movs r1, 0x80
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0x06004020
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020680

	thumb_func_start sub_80206A4
sub_80206A4: @ 80206A4
	push {lr}
	ldr r0, =gUnknown_082F2C40
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206A4

	thumb_func_start sub_80206D0
sub_80206D0: @ 80206D0
	push {lr}
	movs r0, 0x2
	bl PutWindowTilemap
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_80206D0

	thumb_func_start sub_80206E8
sub_80206E8: @ 80206E8
	push {r4,lr}
	sub sp, 0xC
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	movs r4, 0
_080206F8:
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldr r0, =0x00002128
	adds r1, r0
	lsls r2, r4, 19
	lsrs r2, 16
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r3, 0
	bl BlitBitmapToWindow
	adds r4, 0x1
	cmp r4, 0xE
	ble _080206F8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206E8

	thumb_func_start sub_8020740
sub_8020740: @ 8020740
	push {lr}
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0x3
	movs r1, 0xA
	movs r2, 0x20
	bl LoadUserWindowBorderGfx_
	ldr r0, =gUnknown_0860F074
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020740

	thumb_func_start sub_8020770
sub_8020770: @ 8020770
	push {lr}
	sub sp, 0x10
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	ldr r0, =0x04000014
	str r0, [sp]
	mov r2, sp
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	mov r0, sp
	strb r1, [r0, 0x9]
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	strh r1, [r0, 0x20]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	ldr r1, =gScanlineEffectRegBuffers
	ldr r2, =0x010003c0
	bl CpuFastSet
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020770

	thumb_func_start sub_80207C0
sub_80207C0: @ 80207C0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	ldr r5, =gScanlineEffect
	ldrb r0, [r5, 0x14]
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 7
	ldr r4, =gScanlineEffectRegBuffers
	adds r1, r4
	ldr r2, =0x01000090
	mov r0, sp
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r1, 0
	strh r1, [r0]
	ldrb r2, [r5, 0x14]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 7
	movs r2, 0x90
	lsls r2, 1
	adds r4, r2
	adds r1, r4
	ldr r2, =0x01000010
	bl CpuSet
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80207C0

	thumb_func_start sub_8020818
sub_8020818: @ 8020818
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, sp
	strh r4, [r0]
	ldr r5, =gScanlineEffectRegBuffers
	ldr r0, =0x01000090
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r6, 0
	strh r6, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r1, r5, r2
	ldr r2, =0x01000010
	mov r8, r2
	bl CpuSet
	add r0, sp, 0x4
	strh r4, [r0]
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r5, r2
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	movs r1, 0x8A
	lsls r1, 4
	adds r5, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020818

	thumb_func_start sub_8020890
sub_8020890: @ 8020890
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_082F3134
_08020896:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	bls _08020896
	ldr r0, =gUnknown_082F315C
	bl LoadSpritePalette
	ldr r4, =gUnknown_02022C8C
	movs r0, 0x18
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _080208C8
	movs r0, 0x1
	b _080208CA
	.pool
_080208C8:
	movs r0, 0
_080208CA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8020890

	thumb_func_start sub_80208D0
sub_80208D0: @ 80208D0
	push {lr}
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	cmp r0, 0
	beq _080208DE
	bl Free
_080208DE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208D0

	thumb_func_start sub_80208E8
sub_80208E8: @ 80208E8
	push {lr}
	ldr r0, =gUnknown_082F319C
	movs r1, 0xA
	movs r2, 0x18
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C8C
	ldr r2, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208E8

	thumb_func_start sub_802091C
sub_802091C: @ 802091C
	ldr r1, =gUnknown_02022C8C
	ldr r1, [r1]
	ldr r2, [r1]
	adds r2, 0x3E
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_802091C

	thumb_func_start sub_802093C
sub_802093C: @ 802093C
	push {r4,r5,lr}
	sub sp, 0x4
	bl sub_801F0B0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r5, sp
	adds r5, 0x1
	mov r0, sp
	adds r1, r5, 0
	bl sub_801F0BC
	cmp r4, 0x3
	beq _0802097C
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	ldr r1, [r4]
	ldr r2, [r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0xA
	strh r0, [r2, 0x20]
	ldr r2, [r1]
	b _08020992
	.pool
_0802097C:
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r2, [r4]
	ldr r1, [r2]
	movs r0, 0x18
	strh r0, [r1, 0x20]
	ldr r2, [r2]
_08020992:
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x18
	strh r0, [r2, 0x22]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802093C

	thumb_func_start sub_80209AC
sub_80209AC: @ 80209AC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 2
	ldr r0, =gUnknown_082F2DF0+2
	adds r4, r0
	movs r0, 0
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	ldr r0, =0x01010000
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x4
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209E0
sub_80209E0: @ 80209E0
	push {lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A00
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _08020A0C
	.pool
_08020A00:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
_08020A0C:
	ldr r0, =gUnknown_02022C8C
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x14]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209E0

	thumb_func_start sub_8020A1C
sub_8020A1C: @ 8020A1C
	push {r4,lr}
	ldr r4, =gUnknown_02022C8C
	ldr r1, [r4]
	ldrh r0, [r1, 0x14]
	cmp r0, 0x3
	bls _08020A30
_08020A28:
	movs r0, 0
	b _08020A62
	.pool
_08020A30:
	adds r0, 0x1
	strh r0, [r1, 0x14]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _08020A60
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A54
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	b _08020A28
_08020A54:
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	b _08020A28
_08020A60:
	movs r0, 0x1
_08020A62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020A1C

	thumb_func_start sub_8020A68
sub_8020A68: @ 8020A68
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F31BC
	movs r1, 0x4C
	movs r2, 0x98
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0x8]
	ldr r0, =gUnknown_082F31D4
	movs r1, 0x40
	movs r2, 0x98
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020A68

	thumb_func_start sub_8020ABC
sub_8020ABC: @ 8020ABC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_801F198
	adds r3, r0, 0
	cmp r3, 0xF
	bne _08020AD8
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08020AEC
_08020AD8:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	lsls r0, r3, 3
	adds r0, 0x4C
	strh r0, [r4, 0x20]
_08020AEC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020ABC

	thumb_func_start sub_8020AF4
sub_8020AF4: @ 8020AF4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x2E]
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x24]
_08020B1A:
	pop {r0}
	bx r0
	thumb_func_end sub_8020AF4

	thumb_func_start sub_8020B20
sub_8020B20: @ 8020B20
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F322C
	movs r1, 0x8
	movs r2, 0x98
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0xC]
	ldr r0, =gUnknown_082F3244
	movs r1, 0x20
	movs r2, 0x98
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B20

	thumb_func_start sub_8020B80
sub_8020B80: @ 8020B80
	push {r4,lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _08020BB8
	bl sub_801F0DC
	cmp r0, 0
	beq _08020BC2
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	movs r1, 0x3
	bl StartSpriteAnim
	b _08020BF6
	.pool
_08020BB8:
	bl sub_801F1A4
	adds r4, r0, 0
	cmp r4, 0x3
	bne _08020BD8
_08020BC2:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _08020BF6
	.pool
_08020BD8:
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	lsls r1, r4, 24
	lsrs r1, 24
	bl StartSpriteAnim
_08020BF6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B80

	thumb_func_start sub_8020C00
sub_8020C00: @ 8020C00
	ldr r0, =gUnknown_02022C90
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8020C00

	thumb_func_start sub_8020C0C
sub_8020C0C: @ 8020C0C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02022C90
	ldr r0, [r5]
	cmp r0, 0
	bne _08020C20
	movs r0, 0x2
	b _08020C5C
	.pool
_08020C20:
	cmp r4, 0
	bne _08020C26
	ldr r4, [r0]
_08020C26:
	ldrb r0, [r0, 0xA]
	bl DestroyTask
	ldr r0, [r5]
	bl Free
	movs r0, 0
	str r0, [r5]
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =CB2_ReturnToField
	cmp r4, r0
	bne _08020C5A
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0xC8
	lsls r0, 1
	bl PlayNewMapMusic
	ldr r0, =CB1_Overworld
	bl SetMainCallback1
_08020C5A:
	movs r0, 0
_08020C5C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8020C0C

	thumb_func_start sub_8020C70
sub_8020C70: @ 8020C70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	mov r8, r0
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _08020C8E
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _08020CAC
_08020C8E:
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =gUnknown_03005000
	mov r1, r8
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	b _08020CF8
	.pool
_08020CAC:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r8
	cmp r0, 0x1
	bls _08020CC8
	cmp r7, r8
	bcc _08020CDC
_08020CC8:
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =gUnknown_03005000
	movs r1, 0
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	b _08020CF8
	.pool
_08020CDC:
	ldr r6, =gUnknown_02022C90
	ldr r0, =0x000041c0
	bl AllocZeroed
	adds r5, r0, 0
	str r5, [r6]
	cmp r5, 0
	bne _08020D10
	adds r0, r4, 0
	bl SetMainCallback2
	ldr r0, =gUnknown_03005000
	strh r5, [r0, 0x10]
	strh r5, [r0, 0x12]
_08020CF8:
	adds r0, 0xEE
	ldrb r1, [r0]
	movs r1, 0x1
	strb r1, [r0]
	b _08020D74
	.pool
_08020D10:
	str r4, [r5]
	movs r4, 0
	strb r7, [r5, 0x8]
	ldr r0, [r6]
	mov r1, r8
	strb r1, [r0, 0x9]
	ldr r0, [r6]
	bl sub_8020FC4
	ldr r1, [r6]
	movs r2, 0x1
	movs r0, 0x1
	strh r0, [r1, 0x12]
	strb r2, [r1, 0xE]
	ldr r1, [r6]
	movs r0, 0x6
	strb r0, [r1, 0xF]
	ldr r0, [r6]
	adds r0, 0x36
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x10
	str r1, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl sub_8024604
	ldr r2, [r6]
	adds r2, 0x36
	movs r0, 0x4
	movs r1, 0x1
	bl sub_8022BEC
	ldr r0, =sub_8020F88
	bl SetMainCallback2
	ldr r0, =sub_8020FA0
	movs r1, 0x8
	bl CreateTask
	ldr r1, [r6]
	strb r0, [r1, 0xA]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08020D74:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020C70

	thumb_func_start sub_8020D8C
sub_8020D8C: @ 8020D8C
	push {r4,lr}
	sub sp, 0xC
	ldr r1, =gSpecialVar_ItemId
	ldrh r0, [r1]
	subs r0, 0x85
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2B
	bls _08020DA8
	movs r0, 0x85
	strh r0, [r1]
	b _08020DB0
	.pool
_08020DA8:
	ldrh r0, [r1]
	movs r1, 0x1
	bl RemoveBagItem
_08020DB0:
	ldr r4, =gUnknown_02022C90
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	lsls r0, 5
	adds r0, r2, r0
	ldr r1, =gSpecialVar_ItemId
	ldrh r1, [r1]
	subs r1, 0x85
	adds r0, 0xA4
	movs r3, 0
	strh r1, [r0]
	movs r0, 0x1
	strb r0, [r2, 0xE]
	ldr r1, [r4]
	movs r0, 0x9
	strb r0, [r1, 0xF]
	ldr r0, [r4]
	adds r0, 0x36
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x10
	str r1, [sp]
	str r3, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0
	bl sub_8024604
	ldr r2, [r4]
	adds r2, 0x36
	movs r0, 0x4
	movs r1, 0x1
	bl sub_8022BEC
	ldr r0, =sub_8020FA0
	movs r1, 0x8
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0xA]
	ldr r0, =sub_8020F88
	bl SetMainCallback2
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020D8C

	thumb_func_start sub_8020E1C
sub_8020E1C: @ 8020E1C
	push {lr}
	ldr r0, =gUnknown_02022C90
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl DestroyTask
	ldr r0, =sub_8020D8C
	bl sub_81AABF0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020E1C

	thumb_func_start sub_8020E3C
sub_8020E3C: @ 8020E3C
	push {lr}
	ldr r0, =sub_8020F74
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020E3C

	thumb_func_start sub_8020E4C
sub_8020E4C: @ 8020E4C
	push {lr}
	movs r0, 0
	bl SetVBlankCallback
	pop {r0}
	bx r0
	thumb_func_end sub_8020E4C

	thumb_func_start sub_8020E58
sub_8020E58: @ 8020E58
	push {r4-r6,lr}
	ldr r4, =gUnknown_02022C90
	ldr r0, [r4]
	adds r0, 0x6C
	ldrh r2, [r0]
	lsls r2, 8
	movs r1, 0xF0
	lsls r1, 6
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	ldr r0, [r4]
	adds r0, 0x72
	ldrh r3, [r0]
	lsls r3, 8
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_81515FC
	adds r3, r0, 0
	ldr r0, =0x0000ffff
	ands r3, r0
	ldr r2, [r4]
	strh r3, [r2, 0x16]
	ldrb r0, [r2, 0x9]
	cmp r0, 0x3
	beq _08020EDC
	cmp r0, 0x3
	bgt _08020EA4
	cmp r0, 0x2
	beq _08020EAE
	b _08020F48
	.pool
_08020EA4:
	cmp r0, 0x4
	beq _08020EEC
	cmp r0, 0x5
	beq _08020F20
	b _08020F48
_08020EAE:
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	movs r0, 0xF6
	lsls r0, 1
	adds r1, r0
	lsls r0, r3, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bls _08020F48
	adds r2, 0x25
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r1, [r4]
	ldrh r1, [r1, 0x16]
	movs r2, 0xF6
	lsls r2, 1
	b _08020F14
	.pool
_08020EDC:
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	movs r6, 0xF7
	lsls r6, 1
	b _08020F28
	.pool
_08020EEC:
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	movs r0, 0xF8
	lsls r0, 1
	adds r1, r0
	lsls r0, r3, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bls _08020F48
	adds r2, 0x25
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r1, [r4]
	ldrh r1, [r1, 0x16]
	movs r2, 0xF8
	lsls r2, 1
_08020F14:
	adds r0, r2
	strh r1, [r0]
	b _08020F48
	.pool
_08020F20:
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	movs r6, 0xF9
	lsls r6, 1
_08020F28:
	adds r1, r0, r6
	lsls r0, r3, 16
	lsrs r0, 16
	ldrh r1, [r1]
	cmp r0, r1
	bls _08020F48
	adds r2, 0x25
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r5]
	ldr r0, [r4]
	ldrh r0, [r0, 0x16]
	adds r1, r6
	strh r0, [r1]
_08020F48:
	ldr r4, =gUnknown_02022C90
	ldr r1, [r4]
	ldr r0, [r1, 0x68]
	str r0, [r1, 0x1C]
	bl sub_8024700
	lsls r0, 24
	cmp r0, 0
	bne _08020F66
	ldr r0, [r4]
	adds r0, 0x25
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
_08020F66:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020E58

	thumb_func_start sub_8020F74
sub_8020F74: @ 8020F74
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	thumb_func_end sub_8020F74

	thumb_func_start sub_8020F88
sub_8020F88: @ 8020F88
	push {lr}
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8020F88

	thumb_func_start sub_8020FA0
sub_8020FA0: @ 8020FA0
	push {r4,lr}
	ldr r4, =gUnknown_02022C90
	ldr r0, [r4]
	ldr r2, [r0, 0x4]
	cmp r2, 0
	beq _08020FB4
	adds r1, r0, 0
	adds r1, 0x36
	bl _call_via_r2
_08020FB4:
	ldr r0, [r4]
	bl sub_8021450
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020FA0

	thumb_func_start sub_8020FC4
sub_8020FC4: @ 8020FC4
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	b _08020FE6
_08020FCC:
	lsls r0, r5, 5
	adds r0, 0x98
	adds r0, r6, r0
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	ldr r2, =gLinkPlayers + 8
	adds r1, r2
	bl StringCopy
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_08020FE6:
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _08020FCC
	cmp r5, 0x4
	bhi _08021012
_08020FF0:
	lsls r4, r5, 5
	adds r0, r4, 0
	adds r0, 0x98
	adds r0, r6, r0
	movs r1, 0x1
	movs r2, 0x7
	bl memset
	adds r4, r6, r4
	adds r4, 0x9F
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08020FF0
_08021012:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsls r0, 29
	lsrs r0, 29
	cmp r0, 0x1
	beq _0802103E
	cmp r0, 0x1
	bgt _08021034
	cmp r0, 0
	beq _0802103A
	b _08021046
	.pool
_08021034:
	cmp r0, 0x2
	beq _08021042
	b _08021046
_0802103A:
	movs r0, 0x8
	b _08021044
_0802103E:
	movs r0, 0x4
	b _08021044
_08021042:
	movs r0, 0x1
_08021044:
	strb r0, [r6, 0xB]
_08021046:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8020FC4

	thumb_func_start sub_802104C
sub_802104C: @ 802104C
	push {r4,r5,lr}
	sub sp, 0xC
	bl sub_8020C00
	adds r5, r0, 0
	cmp r5, 0
	bne _08021060
	movs r0, 0x1
	negs r0, r0
	b _08021304
_08021060:
	ldrb r0, [r5, 0xC]
	cmp r0, 0x9
	bls _08021068
	b _080212FC
_08021068:
	lsls r0, 2
	ldr r1, =_08021078
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08021078:
	.4byte _080210A0
	.4byte _080210BE
	.4byte _080210E4
	.4byte _080210F2
	.4byte _08021178
	.4byte _080211BE
	.4byte _080211EC
	.4byte _0802121C
	.4byte _08021278
	.4byte _080212B4
_080210A0:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	bl ScanlineEffect_Stop
	bl reset_temp_tile_data_buffers
	b _080212FC
_080210BE:
	add r0, sp, 0x8
	movs r4, 0
	strh r4, [r0]
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x01000200
	bl CpuSet
	ldr r0, =gReservedSpritePaletteCount
	strb r4, [r0]
	movs r0, 0x3
	bl sub_8034C54
	b _080212FC
	.pool
_080210E4:
	bl ResetPaletteFade
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	b _080212FC
_080210F2:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F32C8
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0xE0
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x87
	lsls r0, 6
	adds r1, r5, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	movs r0, 0xC7
	lsls r0, 6
	adds r1, r5, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	b _080212FC
	.pool
_08021178:
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r0, 0x40
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	b _080212FC
_080211BE:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r1, =gUnknown_08DE34B8
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _080212FC
	.pool
_080211EC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _080211F8
	b _08021302
_080211F8:
	bl InitStandardTextBoxWindows
	bl sub_8197200
	adds r0, r5, 0
	bl sub_8022588
	adds r0, r5, 0
	bl sub_8022600
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x8]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x8]
	b _080212FC
	.pool
_0802121C:
	ldr r0, =gUnknown_08DE3398
	movs r2, 0xC0
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	ldr r1, =gBerryCrushGrinderTopTilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gBerryCrushContainerCapTilemap
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gBerryCrushBackgroundTilemap
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	adds r0, r5, 0
	bl sub_80226D0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _080212FC
	.pool
_08021278:
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl CreateWirelessStatusIndicatorSprite
	adds r0, r5, 0
	bl sub_8022730
	ldr r0, =gSpriteCoordOffsetY
	ldrh r1, [r0]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x16
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	b _080212FC
	.pool
_080212B4:
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	bl sub_8020E3C
	movs r0, 0
	strb r0, [r5, 0xC]
	movs r0, 0x1
	b _08021304
	.pool
_080212FC:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_08021302:
	movs r0, 0
_08021304:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802104C

	thumb_func_start sub_802130C
sub_802130C: @ 802130C
	push {r4,r5,lr}
	sub sp, 0x8
	bl sub_8020C00
	adds r5, r0, 0
	cmp r5, 0
	bne _08021320
	movs r0, 0x1
	negs r0, r0
	b _08021446
_08021320:
	ldrb r0, [r5, 0xC]
	cmp r0, 0x7
	bls _08021328
	b _0802143E
_08021328:
	lsls r0, 2
	ldr r1, =_08021338
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08021338:
	.4byte _08021358
	.4byte _0802135E
	.4byte _08021368
	.4byte _0802137E
	.4byte _0802138A
	.4byte _080213E6
	.4byte _08021426
	.4byte _08021436
_08021358:
	bl sub_8010434
	b _0802143E
_0802135E:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08021444
_08021368:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0802143E
_0802137E:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0802143E
	b _08021444
_0802138A:
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0802143E
_080213E6:
	bl FreeAllWindowBuffers
	movs r0, 0
	bl HideBg
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl HideBg
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl HideBg
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl HideBg
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl ClearGpuRegBits
	b _0802143E
_08021426:
	bl sub_800E084
	adds r0, r5, 0
	bl sub_8022960
	bl sub_8034CC8
	b _0802143E
_08021436:
	movs r0, 0
	strb r0, [r5, 0xC]
	movs r0, 0x1
	b _08021446
_0802143E:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_08021444:
	movs r0, 0
_08021446:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802130C

	thumb_func_start sub_8021450
sub_8021450: @ 8021450
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gSpriteCoordOffsetY
	ldrh r1, [r4, 0x2C]
	ldrh r2, [r4, 0x2A]
	adds r1, r2
	strh r1, [r0]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x16
	bl SetGpuReg
	ldrh r0, [r4, 0x12]
	cmp r0, 0x7
	bne _0802147C
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r4, r1
	ldrh r1, [r4, 0x28]
	bl sub_8022524
_0802147C:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8021450

	thumb_func_start sub_8021488
sub_8021488: @ 8021488
	movs r1, 0
	ldr r2, =0x0000ff98
	strh r2, [r0, 0x2A]
	strh r1, [r0, 0x2C]
	ldr r0, =gSpriteCoordOffsetX
	strh r1, [r0]
	ldr r0, =gSpriteCoordOffsetY
	strh r2, [r0]
	bx lr
	.pool
	thumb_func_end sub_8021488

	thumb_func_start sub_80214A8
sub_80214A8: @ 80214A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r10, r0
	str r1, [sp]
	movs r0, 0
	mov r9, r0
	mov r1, r10
	ldrb r1, [r1, 0x9]
	cmp r9, r1
	bcc _080214C6
	b _080215E4
_080214C6:
	ldr r1, =gUnknown_082F41E8
	mov r2, r9
	lsls r0, r2, 1
	adds r0, r1
	ldrh r2, [r0]
	mov r1, r9
	lsls r0, r1, 5
	add r0, r10
	adds r0, 0xA4
	ldrh r3, [r0]
	adds r3, 0x85
	lsls r3, 16
	lsrs r3, 16
	ldr r0, =gUnknown_082F436C
	adds r1, r2, 0
	bl AddCustomItemIconSprite
	lsls r0, 24
	lsrs r0, 24
	mov r2, r9
	lsls r3, r2, 2
	ldr r1, [sp]
	adds r1, 0x38
	adds r6, r1, r3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r6]
	ldrb r0, [r1, 0x5]
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r2, [r6]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r6]
	ldr r0, [sp]
	adds r0, 0xC
	adds r0, r3
	mov r8, r0
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	adds r0, 0x78
	strh r0, [r1, 0x20]
	ldr r1, [r6]
	ldr r0, =0x0000fff0
	strh r0, [r1, 0x22]
	ldr r3, [r6]
	adds r5, r3, 0
	adds r5, 0x2E
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r5, 0x2]
	movs r0, 0x20
	strh r0, [r5, 0x4]
	movs r0, 0x70
	strh r0, [r5, 0xE]
	mov r2, r8
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	ldrh r1, [r1, 0x8]
	subs r0, r1
	lsls r0, 16
	asrs r1, r0, 16
	adds r0, r1, 0
	cmp r1, 0
	bge _08021558
	adds r0, r1, 0x3
_08021558:
	asrs r0, 2
	strh r0, [r5, 0xC]
	lsls r0, r1, 23
	lsrs r7, r0, 16
	movs r2, 0x80
	lsls r2, 2
	adds r2, 0x20
	lsrs r2, 1
	movs r0, 0x7
	movs r1, 0xFE
	lsls r1, 6
	str r3, [sp, 0x4]
	bl sub_81515D4
	adds r4, r0, 0
	ldr r0, [r6]
	ldrh r0, [r0, 0x20]
	lsls r0, 7
	ldr r3, [sp, 0x4]
	strh r0, [r3, 0x2E]
	lsls r1, r7, 16
	asrs r1, 16
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x7
	adds r2, r4, 0
	bl sub_81515D4
	strh r0, [r5, 0x6]
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x55
	bl sub_8151550
	adds r2, r0, 0
	movs r0, 0
	strh r0, [r5, 0x8]
	lsls r2, 16
	asrs r2, 16
	movs r0, 0x7
	movs r1, 0xFE
	lsls r1, 6
	bl sub_81515D4
	strh r0, [r5, 0xA]
	ldrh r0, [r5, 0xE]
	ldr r2, =0xffff8000
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r5, 0xE]
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _080215D0
	ldr r0, [r6]
	movs r1, 0x1
	bl StartSpriteAffineAnim
_080215D0:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r10
	ldrb r0, [r0, 0x9]
	cmp r9, r0
	bcs _080215E4
	b _080214C6
_080215E4:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80214A8

	thumb_func_start sub_8021608
sub_8021608: @ 8021608
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	ldrh r0, [r4, 0x4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r5, 0x26]
	adds r0, r2
	strh r0, [r5, 0x26]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r6, 0x80
	lsls r6, 8
	ands r0, r6
	cmp r0, 0
	beq _0802166E
	ldrh r0, [r4, 0x6]
	ldrh r2, [r5, 0x2E]
	adds r0, r2
	strh r0, [r5, 0x2E]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r5, 0x24]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ands r0, r6
	cmp r0, 0
	beq _0802166E
	ldrh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	cmp r0, 0x7E
	ble _0802166E
	movs r0, 0
	strh r0, [r5, 0x24]
	ldrh r1, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xE]
_0802166E:
	ldrh r0, [r4]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r5, 0x20]
	movs r2, 0x22
	ldrsh r1, [r5, r2]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	ldrh r2, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r2
	cmp r1, r0
	blt _0802169A
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
	adds r0, r5, 0
	bl FreeSpriteOamMatrix
	adds r0, r5, 0
	bl DestroySprite
_0802169A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021608

	thumb_func_start sub_80216A8
sub_80216A8: @ 80216A8
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r5, 0
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcs _080216D4
	ldr r7, =gUnknown_082F41E8
_080216B6:
	lsls r0, r5, 1
	adds r0, r7
	ldrh r4, [r0]
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _080216B6
_080216D4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80216A8

	thumb_func_start sub_80216E0
sub_80216E0: @ 80216E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	str r1, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0x4E
	adds r1, r6
	mov r10, r1
	mov r9, r0
	ldrb r2, [r6, 0x9]
	cmp r0, r2
	bcs _080217AE
	ldr r7, =gUnknown_082F41CC
_08021704:
	mov r3, r10
	ldrh r0, [r3, 0xA]
	mov r4, r9
	lsls r1, r4, 1
	add r1, r9
	asrs r0, r1
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	lsrs r1, 16
	mov r8, r1
	cmp r1, 0
	beq _0802179E
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08021748
	lsls r4, 2
	ldr r5, [sp]
	adds r5, 0x24
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _0802175A
	.pool
_08021748:
	mov r0, r9
	lsls r4, r0, 2
	ldr r5, [sp]
	adds r5, 0x24
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
_0802175A:
	adds r3, r5, r4
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r4, 0x5
	negs r4, r4
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	subs r4, 0x3C
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	movs r0, 0x3
	mov r1, r8
	ands r1, r0
	mov r8, r1
	subs r1, 0x1
	lsls r1, 1
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r2, 0x24]
	ldr r2, [r3]
	ldr r3, =gUnknown_082F41CC+1
	adds r1, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	strh r0, [r2, 0x26]
_0802179E:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r4, [r6, 0x9]
	cmp r9, r4
	bcc _08021704
_080217AE:
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _080217C0
	adds r2, r6, 0
	adds r2, 0x25
	ldrb r1, [r2]
	b _0802189C
	.pool
_080217C0:
	ldrh r0, [r6, 0x28]
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r1, r8
	str r1, [sp, 0x8]
	movs r2, 0
	mov r9, r2
	mov r3, r10
	ldrh r1, [r3, 0xC]
	lsls r0, r1, 1
	adds r0, 0x3
	adds r6, 0x25
	str r6, [sp, 0xC]
	adds r3, r1, 0
	cmp r9, r0
	bge _08021890
_080217E8:
	mov r4, r9
	lsls r1, r4, 2
	ldr r0, [sp]
	adds r0, 0x4C
	adds r7, r0, r1
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0802187E
	ldr r0, =sub_8022B28
	str r0, [r2, 0x1C]
	lsls r1, r4, 1
	ldr r3, =gUnknown_082F41CC+6
	adds r0, r1, r3
	movs r4, 0
	ldrsb r4, [r0, r4]
	adds r0, r4, 0
	adds r0, 0x78
	strh r0, [r2, 0x20]
	ldr r2, [r7]
	ldr r0, =gUnknown_082F41CC+7
	adds r1, r0
	movs r6, 0
	ldrsb r6, [r1, r6]
	mov r1, r8
	lsls r0, r1, 2
	subs r0, 0x88
	subs r0, r6, r0
	strh r0, [r2, 0x22]
	ldr r5, [r7]
	ldr r2, [sp, 0x8]
	lsls r1, r2, 2
	adds r0, r4, 0
	bl __divsi3
	adds r4, r0
	strh r4, [r5, 0x24]
	ldr r0, [r7]
	strh r6, [r0, 0x26]
	mov r3, r10
	ldrb r1, [r3, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08021860
	ldr r0, [r7]
	movs r1, 0x1
	bl StartSpriteAnim
	b _08021868
	.pool
_08021860:
	ldr r0, [r7]
	movs r1, 0
	bl StartSpriteAnim
_08021868:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r4, r10
	ldrh r3, [r4, 0xC]
	cmp r0, 0x3
	bls _0802187E
	movs r0, 0
	mov r8, r0
_0802187E:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, r3, 1
	adds r0, 0x3
	cmp r9, r0
	blt _080217E8
_08021890:
	ldr r2, [sp, 0xC]
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080218A6
_0802189C:
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _080218C4
_080218A6:
	ldr r3, [sp, 0x4]
	cmp r3, 0x1
	bne _080218B4
	movs r0, 0x4E
	bl PlaySE
	b _080218BA
_080218B4:
	movs r0, 0x4D
	bl PlaySE
_080218BA:
	ldr r4, [sp, 0xC]
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
_080218C4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80216E0

	thumb_func_start sub_80218D4
sub_80218D4: @ 80218D4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r2, 0
	ldrb r0, [r5, 0x9]
	cmp r2, r0
	bcs _08021906
	adds r4, r6, 0
	adds r4, 0x24
	movs r7, 0x4
	adds r3, r0, 0
_080218EA:
	lsls r0, r2, 2
	adds r0, r4, r0
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08021920
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r3
	bcc _080218EA
_08021906:
	movs r2, 0
	adds r3, r6, 0
	adds r3, 0x4C
	movs r4, 0x4
_0802190E:
	lsls r0, r2, 2
	adds r0, r3, r0
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _08021924
_08021920:
	movs r0, 0
	b _0802193C
_08021924:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _0802190E
	movs r1, 0x2C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0802193A
	movs r0, 0
	strh r0, [r5, 0x2C]
_0802193A:
	movs r0, 0x1
_0802193C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80218D4

	thumb_func_start sub_8021944
sub_8021944: @ 8021944
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r4, r1, 16
	lsrs r4, 16
	movs r7, 0
	movs r5, 0xE1
	lsls r5, 4
	adds r0, r4, 0
	adds r1, r5, 0
	bl __udivsi3
	strh r0, [r6, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3C
	bl __udivsi3
	strh r0, [r6, 0x6]
	adds r0, r4, 0
	movs r1, 0x3C
	bl __umodsi3
	lsls r0, 24
	asrs r0, 16
	movs r1, 0x4
	bl sub_8151534
	adds r2, r7, 0
	lsls r0, 16
	asrs r3, r0, 16
	movs r0, 0x7
	mov r12, r0
	ldr r5, =gUnknown_082F334C
	movs r4, 0x1
_08021990:
	mov r0, r12
	subs r1, r0, r2
	adds r0, r3, 0
	asrs r0, r1
	ands r0, r4
	cmp r0, 0
	beq _080219A6
	lsls r0, r2, 2
	adds r0, r5
	ldr r0, [r0]
	adds r7, r0
_080219A6:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _08021990
	ldr r1, =0x000f4240
	adds r0, r7, 0
	bl __udivsi3
	strh r0, [r6, 0x8]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021944

	thumb_func_start sub_80219C8
sub_80219C8: @ 80219C8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r8, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x2
	mov r1, r8
	bl GetStringWidth
	lsls r4, 2
	lsrs r0, 1
	subs r4, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r5, 1
	adds r0, r5
	ldr r1, =gUnknown_082F32D8
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x2
	adds r2, r4, 0
	movs r3, 0
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80219C8

	thumb_func_start sub_8021A28
sub_8021A28: @ 8021A28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r3, 24
	movs r0, 0
	str r0, [sp, 0x18]
	movs r1, 0
	str r1, [sp, 0x1C]
	ldr r2, [sp, 0xC]
	adds r2, 0x68
	str r2, [sp, 0x20]
	movs r4, 0xF0
	lsls r4, 24
	adds r3, r4
	lsrs r3, 24
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	bne _08021A68
	adds r0, r3, 0
	subs r0, 0x2A
	lsls r0, 24
	lsrs r3, r0, 24
_08021A68:
	ldr r2, [sp, 0xC]
	ldrb r1, [r2, 0x9]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	subs r6, r3, r0
	cmp r6, 0
	ble _08021A84
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r0, 1
	adds r6, r0, 0
	adds r6, 0x10
	b _08021A86
_08021A84:
	movs r6, 0x10
_08021A86:
	movs r5, 0
	ldr r3, [sp, 0xC]
	ldrb r3, [r3, 0x9]
	cmp r5, r3
	bcc _08021A92
	b _08021D14
_08021A92:
	ldr r4, [sp, 0x10]
	lsls r4, 2
	str r4, [sp, 0x24]
_08021A98:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, [sp, 0x10]
	cmp r0, 0x1
	beq _08021B48
	cmp r0, 0x1
	bgt _08021AC0
	cmp r0, 0
	beq _08021ADE
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r1, r6, 24
	mov r10, r1
	ldr r2, [sp, 0x1C]
	adds r2, 0xA2
	mov r9, r2
	ldr r3, [sp, 0x18]
	lsls r3, 5
	mov r8, r3
	b _08021C5A
_08021AC0:
	ldr r4, [sp, 0x10]
	cmp r4, 0x2
	bne _08021AC8
	b _08021C1C
_08021AC8:
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	ldr r1, [sp, 0x1C]
	adds r1, 0xA2
	mov r9, r1
	ldr r2, [sp, 0x18]
	lsls r2, 5
	mov r8, r2
	b _08021C5A
_08021ADE:
	ldr r0, [sp, 0x20]
	adds r0, 0x20
	adds r0, r5
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	lsls r3, r5, 1
	ldr r2, [sp, 0x20]
	adds r2, 0xC
	cmp r5, 0
	beq _08021B04
	adds r0, r2, r3
	subs r1, r5, 0x1
	lsls r1, 1
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08021B04
	str r5, [sp, 0x1C]
_08021B04:
	ldr r4, [sp, 0x24]
	ldr r1, [sp, 0x10]
	adds r0, r4, r1
	lsls r0, 1
	adds r0, r3, r0
	adds r0, r2, r0
	ldrh r1, [r0]
	ldr r0, =gStringVar4
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_082F43B4
	adds r0, r4, r0
	ldr r1, [r0]
	ldr r0, =gStringVar4
	bl StringAppend
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r2, r6, 24
	mov r10, r2
	ldr r3, [sp, 0x1C]
	adds r3, 0xA2
	mov r9, r3
	ldr r0, [sp, 0x18]
	lsls r0, 5
	mov r8, r0
	b _08021C5A
	.pool
_08021B48:
	ldr r1, [sp, 0x20]
	adds r0, r1, r5
	adds r0, 0x28
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	lsls r3, r5, 1
	adds r2, r1, 0
	adds r2, 0xC
	cmp r5, 0
	beq _08021B72
	adds r0, r3, 0
	adds r0, 0xA
	adds r0, r2, r0
	adds r1, r3, 0
	adds r1, 0x8
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08021B72
	str r5, [sp, 0x1C]
_08021B72:
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x10]
	adds r4, r0, r1
	lsls r4, 1
	adds r4, r3, r4
	adds r4, r2, r4
	ldrh r1, [r4]
	lsrs r1, 4
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r7, 0
	ldrb r0, [r4]
	movs r3, 0xF
	ands r3, r0
	movs r2, 0
	ldr r4, [sp, 0x10]
	lsls r4, 2
	str r4, [sp, 0x28]
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	ldr r1, [sp, 0x1C]
	adds r1, 0xA2
	mov r9, r1
	ldr r0, [sp, 0x18]
	lsls r0, 5
	mov r8, r0
	adds r6, 0xE
	adds r5, 0x1
	ldr r1, =gUnknown_082F334C
	mov r12, r1
_08021BB8:
	movs r0, 0x3
	subs r1, r0, r2
	adds r0, r3, 0
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08021BD0
	lsls r0, r2, 2
	add r0, r12
	ldr r0, [r0]
	adds r7, r0
_08021BD0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _08021BB8
	adds r0, r7, 0
	ldr r1, =0x000f4240
	bl __udivsi3
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gStringVar2
	adds r1, r3, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_082F43B4
	ldr r2, [sp, 0x28]
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	b _08021C5E
	.pool
_08021C1C:
	str r5, [sp, 0x18]
	str r5, [sp, 0x1C]
	lsls r7, r5, 5
	ldr r3, [sp, 0xC]
	adds r0, r3, r7
	adds r0, 0xA4
	ldrb r2, [r0]
	cmp r2, 0x2B
	bls _08021C30
	movs r2, 0
_08021C30:
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, =gBerries
	adds r1, r0
	ldr r0, =gStringVar1
	bl StringCopy
	ldr r0, =gUnknown_082F43B4
	ldr r1, [r0, 0x8]
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	ldr r4, [sp, 0x14]
	subs r4, 0x4
	lsls r0, r6, 24
	mov r10, r0
	movs r1, 0xA2
	adds r1, r5
	mov r9, r1
	mov r8, r7
_08021C5A:
	adds r6, 0xE
	adds r5, 0x1
_08021C5E:
	movs r0, 0x2
	ldr r1, =gStringVar4
	adds r2, r4, 0
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	ldr r3, [sp, 0xC]
	movs r4, 0xDD
	lsls r4, 1
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r10
	lsrs r3, r1, 24
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x2
	bl AddTextPrinterParameterized3
	ldr r3, [sp, 0x18]
	ldr r2, [sp, 0xC]
	ldrb r2, [r2, 0x8]
	cmp r3, r2
	bne _08021CC0
	ldr r0, =gStringVar3
	ldr r1, =gText_1DotBlueF700
	bl StringCopy
	b _08021CC8
	.pool
_08021CC0:
	ldr r0, =gStringVar3
	ldr r1, =gText_1DotF700
	bl StringCopy
_08021CC8:
	ldr r4, =gStringVar3
	mov r3, r9
	strb r3, [r4]
	mov r1, r8
	adds r1, 0x98
	ldr r0, [sp, 0xC]
	adds r1, r0, r1
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r1, [sp, 0xC]
	movs r2, 0xDD
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r4, r10
	lsrs r3, r4, 24
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r2, =gStringVar4
	str r2, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	lsls r0, r5, 24
	lsrs r5, r0, 24
	ldr r3, [sp, 0xC]
	ldrb r3, [r3, 0x9]
	cmp r5, r3
	bcs _08021D14
	b _08021A98
_08021D14:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021A28

	thumb_func_start sub_8021D34
sub_8021D34: @ 8021D34
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r8, r0
	movs r0, 0
	mov r10, r0
	movs r6, 0
	movs r1, 0
	str r1, [sp, 0xC]
	mov r2, r8
	adds r2, 0x68
	str r2, [sp, 0x10]
	movs r4, 0xDD
	lsls r4, 1
	add r4, r8
	mov r9, r4
	ldrb r0, [r4]
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 27
	movs r1, 0xD6
	lsls r1, 24
	adds r0, r1
	lsrs r7, r0, 24
	movs r0, 0x9C
	lsls r0, 1
	add r0, r8
	ldr r2, [sp, 0x10]
	ldrh r1, [r2, 0x4]
	bl sub_8021944
	ldrb r0, [r4]
	ldr r4, =gUnknown_082F32D8
	str r4, [sp]
	str r6, [sp, 0x4]
	ldr r1, =gText_TimeColon
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_SpaceSec
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0xB0
	subs r0, r1, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r2, r9
	ldrb r0, [r2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x9F
	lsls r0, 1
	add r0, r8
	movs r4, 0
	ldrsh r1, [r0, r4]
	ldr r0, =gStringVar1
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	movs r1, 0xA0
	lsls r1, 1
	add r1, r8
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar4
	ldr r1, =gText_XDotY2
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r4, r9
	ldrb r0, [r4]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_SpaceMin
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	str r2, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, =gStringVar1
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_StrVar1
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x2
	adds r1, r5, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r4, r9
	ldrb r0, [r4]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	mov r2, r10
	str r2, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	adds r0, r7, 0
	adds r0, 0xE
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r4]
	ldr r4, =gUnknown_082F32D8
	str r4, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r1, =gText_PressingSpeed
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r4, =gText_TimesPerSec
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r2, 0xB0
	subs r0, r2, r0
	lsls r0, 24
	str r0, [sp, 0x18]
	lsrs r6, r0, 24
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	str r2, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	mov r4, r8
	ldrb r2, [r4, 0x16]
	ldrh r0, [r4, 0x16]
	mov r12, r0
	movs r1, 0x7
	mov r9, r1
	movs r5, 0x1
	ldr r3, =gUnknown_082F334C
_08021EEC:
	mov r4, r9
	mov r0, r10
	subs r1, r4, r0
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _08021F0A
	mov r1, r10
	lsls r0, r1, 2
	adds r0, r3
	ldr r0, [r0]
	ldr r4, [sp, 0xC]
	adds r4, r0
	str r4, [sp, 0xC]
_08021F0A:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0x7
	bls _08021EEC
	ldr r0, =gStringVar1
	mov r2, r12
	lsrs r1, r2, 8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	ldr r1, =0x000f4240
	ldr r0, [sp, 0xC]
	bl __udivsi3
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_XDotY3
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x2
	adds r1, r4, 0
	bl GetStringWidth
	subs r0, r6, r0
	lsls r0, 24
	lsrs r6, r0, 24
	mov r0, r8
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08021FC4
	movs r0, 0xDD
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, =gUnknown_082F32E7
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	b _08021FDE
	.pool
_08021FC4:
	movs r0, 0xDD
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	str r2, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
_08021FDE:
	adds r0, r7, 0
	adds r0, 0xE
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0xDD
	lsls r4, 1
	add r8, r4
	mov r1, r8
	ldrb r0, [r1]
	ldr r2, =gUnknown_082F32D8
	mov r9, r2
	str r2, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	ldr r1, =gText_Silkiness
	str r1, [sp, 0x8]
	movs r1, 0x2
	movs r2, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	ldr r0, =gStringVar1
	ldr r4, [sp, 0x10]
	ldrh r1, [r4, 0x8]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1Percent
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x2
	adds r1, r4, 0
	bl GetStringWidth
	movs r1, 0xB0
	subs r1, r0
	lsls r1, 24
	lsrs r6, r1, 24
	mov r1, r8
	ldrb r0, [r1]
	mov r2, r9
	str r2, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x2
	adds r2, r6, 0
	adds r3, r7, 0
	bl AddTextPrinterParameterized3
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8021D34

	thumb_func_start sub_8022070
sub_8022070: @ 8022070
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	adds r0, r6, 0
	adds r0, 0x80
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _08022084
	b _08022218
_08022084:
	lsls r0, 2
	ldr r1, =_08022094
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08022094:
	.4byte _080220AC
	.4byte _080220F8
	.4byte _0802210C
	.4byte _08022130
	.4byte _080221F8
	.4byte _08022200
_080220AC:
	ldrb r0, [r4, 0x9]
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0
	bl sub_8022554
	ldrh r0, [r4, 0x12]
	lsls r0, 3
	ldr r2, =gUnknown_082F32CC
	mov r1, sp
	adds r0, r2
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	ldrh r0, [r4, 0x12]
	cmp r0, 0xD
	bne _080220DC
	ldr r0, =gUnknown_082F3344
	adds r0, 0x4
	b _080220DE
	.pool
_080220DC:
	ldr r0, =gUnknown_082F3344
_080220DE:
	adds r0, r5, r0
	ldrb r1, [r0]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r0, sp
	bl AddWindow
	adds r1, r6, 0
	adds r1, 0x82
	strb r0, [r1]
	b _08022218
	.pool
_080220F8:
	adds r4, r6, 0
	adds r4, 0x82
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	b _08022218
_0802210C:
	adds r5, r6, 0
	adds r5, 0x82
	ldrb r0, [r5]
	ldr r4, =0x0000021d
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0xD
	bl SetWindowBorderStyle
	b _08022218
	.pool
_08022130:
	ldrb r0, [r4, 0x9]
	subs r0, 0x2
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x12]
	cmp r0, 0xC
	beq _08022184
	cmp r0, 0xC
	bgt _08022148
	cmp r0, 0xB
	beq _0802214E
	b _08022218
_08022148:
	cmp r0, 0xD
	beq _080221C8
	b _08022218
_0802214E:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r3, =gText_PressesRankings
	movs r1, 0x14
	movs r2, 0x3
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xA0
	bl sub_8021A28
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0x5
	b _08022220
	.pool
_08022184:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r2, =gUnknown_082F43B4
	adds r1, r4, 0
	adds r1, 0x8F
	ldrb r1, [r1]
	adds r1, 0x3
	lsls r1, 2
	adds r1, r2
	ldr r3, [r1]
	movs r1, 0x14
	movs r2, 0x4
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0xA0
	bl sub_8021A28
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0x5
	b _08022220
	.pool
_080221C8:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	ldr r3, =gText_CrushingResults
	movs r1, 0x16
	movs r2, 0x3
	bl sub_80219C8
	ldr r0, =gUnknown_082F3344
	adds r0, 0x4
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, 27
	lsrs r3, 24
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0xB0
	bl sub_8021A28
	b _08022218
	.pool
_080221F8:
	adds r0, r4, 0
	bl sub_8021D34
	b _08022218
_08022200:
	adds r0, r6, 0
	adds r0, 0x82
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	adds r1, r6, 0
	adds r1, 0x80
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _08022224
_08022218:
	adds r1, r6, 0
	adds r1, 0x80
	ldrb r0, [r1]
	adds r0, 0x1
_08022220:
	strb r0, [r1]
	movs r0, 0
_08022224:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8022070

	thumb_func_start sub_802222C
sub_802222C: @ 802222C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xDD
	lsls r0, 1
	adds r5, r4, r0
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r5]
	bl RemoveWindow
	adds r0, r4, 0
	bl sub_8022600
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802222C

	thumb_func_start sub_8022250
sub_8022250: @ 8022250
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0xC]
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080222D0
	cmp r0, 0x1
	bgt _08022288
	cmp r0, 0
	beq _08022296
	b _080224BA
	.pool
_08022288:
	cmp r0, 0x2
	bne _0802228E
	b _08022480
_0802228E:
	cmp r0, 0x3
	bne _08022294
	b _08022494
_08022294:
	b _080224BA
_08022296:
	ldr r0, =gUnknown_082F32EC
	bl AddWindow
	strh r0, [r6, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r6, 0x2]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r6, 0x2]
	ldr r4, =0x0000021d
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r6, 0x2]
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0xD
	bl SetWindowBorderStyle
	b _080224BA
	.pool
_080222D0:
	ldr r0, =gText_BerryCrush2
	mov r10, r0
	movs r1, 0x1
	negs r1, r1
	mov r8, r1
	movs r0, 0x1
	mov r1, r10
	mov r2, r8
	bl GetStringWidth
	lsrs r0, 1
	movs r4, 0x60
	subs r0, r4, r0
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x2]
	ldr r5, =gUnknown_082F32E1
	str r5, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r0, =gText_PressingSpeedRankings
	mov r10, r0
	movs r0, 0x1
	mov r1, r10
	mov r2, r8
	bl GetStringWidth
	lsrs r0, 1
	subs r4, r0
	lsls r4, 24
	lsrs r7, r4, 24
	ldrb r0, [r6, 0x2]
	str r5, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0x11
	bl AddTextPrinterParameterized3
	movs r0, 0x29
	mov r10, r0
_08022336:
	mov r1, r9
	adds r1, 0x2
	ldr r0, =gStringVar1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar4
	ldr r1, =gText_Var1Players
	bl StringExpandPlaceholders
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	movs r0, 0x1
	ldr r1, =gText_TimesPerSec
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0xC0
	subs r1, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gText_TimesPerSec
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	movs r2, 0
	mov r0, r9
	lsls r4, r0, 1
	mov r1, r10
	adds r1, 0x10
	str r1, [sp, 0x10]
	movs r0, 0x1
	add r9, r0
	adds r0, r4, r6
	ldrb r3, [r0, 0x4]
	movs r1, 0x7
	mov r12, r1
	movs r0, 0x1
	mov r8, r0
	ldr r5, =gUnknown_082F334C
_080223AE:
	mov r0, r12
	subs r1, r0, r2
	adds r0, r3, 0
	asrs r0, r1
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _080223CA
	lsls r0, r2, 2
	adds r0, r5
	ldr r0, [r0]
	ldr r1, [sp, 0xC]
	adds r1, r0
	str r1, [sp, 0xC]
_080223CA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _080223AE
	adds r0, r4, r6
	ldrh r1, [r0, 0x4]
	lsrs r1, 8
	ldr r0, =gStringVar1
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [sp, 0xC]
	ldr r1, =0x000f4240
	bl __udivsi3
	adds r1, r0, 0
	ldr r0, =gStringVar2
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar4
	ldr r1, =gText_XDotY3
	bl StringExpandPlaceholders
	movs r0, 0x1
	ldr r1, =gStringVar4
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	subs r0, r7, r0
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x2]
	ldr r1, =gUnknown_082F32D8
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gStringVar4
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	mov r3, r10
	bl AddTextPrinterParameterized3
	ldr r1, [sp, 0x10]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r10, r0
	movs r0, 0
	str r0, [sp, 0xC]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0x3
	bhi _08022444
	b _08022336
_08022444:
	ldrb r0, [r6, 0x2]
	movs r1, 0x3
	bl CopyWindowToVram
	b _080224BA
	.pool
_08022480:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080224BA
	b _080224C0
	.pool
_08022494:
	ldrb r0, [r6, 0x2]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r6, 0x2]
	bl ClearWindowTilemap
	ldrb r0, [r6, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	bl ScriptContext2_Disable
	mov r0, r9
	b _080224BE
_080224BA:
	ldrh r0, [r6]
	adds r0, 0x1
_080224BE:
	strh r0, [r6]
_080224C0:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022250

	thumb_func_start sub_80224D0
sub_80224D0: @ 80224D0
	push {lr}
	bl ScriptContext2_Enable
	ldr r0, =sub_8022250
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	movs r3, 0xF6
	lsls r3, 1
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0xC]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0x10]
	adds r3, 0x2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, 0x12]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80224D0

	thumb_func_start sub_8022524
sub_8022524: @ 8022524
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	bl sub_8021944
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl sub_8035044
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	bl sub_8035044
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	movs r0, 0x2
	bl sub_8035044
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022524

	thumb_func_start sub_8022554
sub_8022554: @ 8022554
	push {lr}
	ldr r2, [r0, 0x78]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r2]
	ldr r1, [r0, 0x7C]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x1
	bl sub_803547C
	movs r0, 0x1
	movs r1, 0x1
	bl sub_803547C
	movs r0, 0
	movs r1, 0x1
	bl sub_803547C
	pop {r0}
	bx r0
	thumb_func_end sub_8022554

	thumb_func_start sub_8022588
sub_8022588: @ 8022588
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r6, 0
	ldrb r0, [r5, 0x9]
	cmp r6, r0
	bcs _080225E8
	ldr r7, =gUnknown_082F417C
_08022596:
	lsls r0, r6, 2
	movs r1, 0xA2
	lsls r1, 1
	adds r2, r5, r1
	adds r2, r0
	ldrb r1, [r5, 0x9]
	subs r1, 0x2
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r6, r0
	adds r0, r7
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_082F4190
	adds r0, r1
	str r0, [r2]
	ldrb r0, [r0]
	lsls r0, 3
	ldr r1, =gUnknown_082F32F4
	adds r0, r1
	bl AddWindow
	ldr r1, =0x000001bb
	adds r4, r5, r1
	adds r4, r6
	strb r0, [r4]
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r6, r0
	bcc _08022596
_080225E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022588

	thumb_func_start sub_8022600
sub_8022600: @ 8022600
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	movs r7, 0
	ldrb r0, [r6, 0x9]
	cmp r7, r0
	bcs _080226B6
	movs r1, 0
	mov r8, r1
_08022616:
	ldr r1, =0x000001bb
	adds r0, r6, r1
	adds r5, r0, r7
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r6, 0x8]
	cmp r7, r0
	bne _08022668
	lsls r4, r7, 5
	adds r4, 0x98
	adds r4, r6, r4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	lsrs r0, 1
	movs r2, 0x24
	subs r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_082F32DB
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	b _0802269C
	.pool
_08022668:
	lsls r4, r7, 5
	adds r4, 0x98
	adds r4, r6, r4
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	lsrs r0, 1
	movs r2, 0x24
	subs r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_082F32DE
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized4
_0802269C:
	ldr r1, =0x000001bb
	adds r0, r6, r1
	adds r0, r7
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x9]
	cmp r7, r0
	bcc _08022616
_080226B6:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022600

	thumb_func_start sub_80226D0
sub_80226D0: @ 80226D0
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r5, 0
	ldr r0, =gUnknown_08DE3FD4
	ldr r4, =gDecompressionBuffer
	adds r1, r4, 0
	bl LZ77UnCompWram
	b _0802271A
	.pool
_080226EC:
	lsls r1, r5, 2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	adds r0, r1
	ldr r3, [r0]
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4, r1
	ldrb r2, [r3, 0x1]
	ldrb r3, [r3, 0x2]
	movs r0, 0xA
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x3
	bl CopyToBgTilemapBufferRect
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0802271A:
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _080226EC
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80226D0

	thumb_func_start sub_8022730
sub_8022730: @ 8022730
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r0, =0x0000ff98
	strh r0, [r6, 0x2A]
	strh r5, [r6, 0x2C]
	ldr r1, =gSpriteCoordOffsetX
	strh r5, [r1]
	ldr r1, =gSpriteCoordOffsetY
	strh r0, [r1]
	ldr r4, =gUnknown_082F41F4
_08022746:
	lsls r0, r5, 3
	adds r0, r4
	bl LoadCompressedSpriteSheet
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08022746
	ldr r0, =gUnknown_082F421C
	bl LoadSpritePalettes
	ldr r0, =gUnknown_082F430C
	movs r1, 0x78
	movs r2, 0x58
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xAC
	lsls r0, 1
	adds r3, r6, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, 0x2C
	ldrb r0, [r1]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1]
	movs r5, 0
	ldrb r1, [r6, 0x9]
	cmp r5, r1
	bcs _08022822
	movs r7, 0x4
_080227AA:
	lsls r4, r5, 2
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r6, r3
	adds r0, r4
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	adds r1, 0x78
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r0, 0x6]
	adds r2, 0x20
	lsls r2, 16
	asrs r2, 16
	ldr r0, =gUnknown_082F4324
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xAE
	lsls r0, 1
	adds r3, r6, r0
	adds r3, r4
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r3]
	ldrb r0, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r0, r2
	orrs r0, r7
	strb r0, [r1, 0x5]
	ldr r1, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6, 0x9]
	cmp r5, r0
	bcc _080227AA
_08022822:
	movs r5, 0
	ldr r4, =gUnknown_082F41CC+6
	adds r7, r4, 0x1
_08022828:
	lsls r2, r5, 1
	adds r0, r2, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r1, 0x78
	adds r2, r7
	ldrb r2, [r2]
	lsls r2, 24
	asrs r2, 24
	adds r2, 0x88
	ldr r0, =gUnknown_082F433C
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r5, 2
	movs r1, 0xC2
	lsls r1, 1
	adds r3, r6, r1
	adds r3, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	strh r5, [r0, 0x2E]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08022828
	movs r5, 0
_0802288E:
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 19
	movs r3, 0xB0
	lsls r3, 16
	adds r1, r3
	asrs r1, 16
	ldr r0, =gUnknown_082F4354
	movs r2, 0x8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r5, 2
	movs r4, 0xD8
	lsls r4, 1
	adds r3, r6, r4
	adds r3, r0
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r3]
	ldrb r1, [r0, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r1, r2
	strb r1, [r0, 0x5]
	ldr r2, [r3]
	adds r2, 0x3E
	ldrb r0, [r2]
	adds r4, 0x8
	adds r1, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [r3]
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r3, 0x41
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _0802288E
	ldr r4, =gUnknown_082F4384
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_8034D14
	adds r2, r4, 0
	adds r2, 0x10
	movs r0, 0x1
	movs r1, 0
	bl sub_8034D14
	adds r4, 0x20
	movs r0, 0x2
	movs r1, 0
	adds r2, r4, 0
	bl sub_8034D14
	ldrh r0, [r6, 0x12]
	cmp r0, 0x1
	bne _08022928
	movs r4, 0x9C
	lsls r4, 1
	adds r0, r6, r4
	bl sub_8022554
_08022928:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022730

	thumb_func_start sub_8022960
sub_8022960: @ 8022960
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	movs r0, 0x4
	bl FreeSpriteTilesByTag
	movs r0, 0x3
	bl FreeSpriteTilesByTag
	movs r0, 0x2
	bl FreeSpriteTilesByTag
	movs r0, 0x1
	bl FreeSpriteTilesByTag
	movs r0, 0x4
	bl FreeSpritePaletteByTag
	movs r0, 0x2
	bl FreeSpritePaletteByTag
	movs r0, 0x1
	bl FreeSpritePaletteByTag
	movs r0, 0xD8
	lsls r0, 1
	adds r6, r5, r0
_08022996:
	lsls r0, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _08022996
	movs r0, 0x2
	bl sub_80353DC
	movs r0, 0x1
	bl sub_80353DC
	movs r0, 0
	bl sub_80353DC
	movs r4, 0
	movs r1, 0xC2
	lsls r1, 1
	adds r6, r5, r1
_080229C4:
	lsls r0, r4, 2
	adds r0, r6, r0
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _080229C4
	movs r4, 0
	ldrb r2, [r5, 0x9]
	cmp r4, r2
	bcs _080229FC
_080229E0:
	lsls r1, r4, 2
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r5, r2
	adds r0, r1
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcc _080229E0
_080229FC:
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08022A18
	adds r0, r2, 0
	bl DestroySprite
_08022A18:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8022960

	thumb_func_start sub_8022A20
sub_8022A20: @ 8022A20
	push {lr}
	adds r3, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08022A46
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
_08022A46:
	pop {r0}
	bx r0
	thumb_func_end sub_8022A20

	thumb_func_start sub_8022A4C
sub_8022A4C: @ 8022A4C
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r1, 0
	ldr r5, =SpriteCallbackDummy
	adds r2, r3, 0
	adds r2, 0x2E
	movs r4, 0
_08022A5A:
	lsls r0, r1, 1
	adds r0, r2, r0
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _08022A5A
	movs r0, 0
	strh r0, [r3, 0x24]
	strh r0, [r3, 0x26]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	str r5, [r3, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022A4C

	thumb_func_start sub_8022A94
sub_8022A94: @ 8022A94
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	ldrh r0, [r4, 0x4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r5, 0x26]
	adds r0, r2
	strh r0, [r5, 0x26]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r6, 0x80
	lsls r6, 8
	ands r0, r6
	cmp r0, 0
	beq _08022AFA
	ldrh r0, [r4, 0x6]
	ldrh r2, [r5, 0x2E]
	adds r0, r2
	strh r0, [r5, 0x2E]
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r5, 0x24]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	ands r0, r6
	cmp r0, 0
	beq _08022AFA
	ldrh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 23
	cmp r0, 0x7E
	ble _08022AFA
	movs r0, 0
	strh r0, [r5, 0x24]
	ldrh r1, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xE]
_08022AFA:
	ldrh r0, [r4]
	lsls r0, 16
	asrs r0, 23
	strh r0, [r5, 0x20]
	movs r2, 0x22
	ldrsh r1, [r5, r2]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	ldrh r2, [r4, 0xE]
	ldr r0, =0x00007fff
	ands r0, r2
	cmp r1, r0
	ble _08022B1A
	ldr r0, =sub_8022A4C
	str r0, [r5, 0x1C]
_08022B1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022A94

	thumb_func_start sub_8022B28
sub_8022B28: @ 8022B28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r6, 0
	adds r7, 0x2E
	movs r0, 0
	mov r8, r0
	movs r2, 0xA0
	lsls r2, 2
	strh r2, [r7, 0x2]
	movs r0, 0x20
	strh r0, [r7, 0x4]
	movs r1, 0xA8
	strh r1, [r7, 0xE]
	movs r0, 0x24
	ldrsh r4, [r6, r0]
	lsls r4, 23
	lsrs r4, 16
	ldrh r0, [r6, 0x22]
	subs r1, r0
	lsls r1, 23
	asrs r1, 16
	adds r2, 0x20
	asrs r2, 1
	movs r0, 0x7
	bl sub_81515D4
	adds r5, r0, 0
	ldrh r0, [r6, 0x20]
	lsls r0, 7
	strh r0, [r6, 0x2E]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	movs r0, 0x7
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81515D4
	strh r0, [r7, 0x6]
	movs r0, 0x7
	adds r1, r5, 0
	movs r2, 0x55
	bl sub_8151550
	adds r2, r0, 0
	mov r1, r8
	strh r1, [r7, 0x8]
	movs r1, 0xFE
	lsls r1, 6
	lsls r2, 16
	asrs r2, 16
	movs r0, 0x7
	bl sub_81515D4
	strh r0, [r7, 0xA]
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bge _08022BA6
	adds r0, 0x3
_08022BA6:
	asrs r0, 2
	strh r0, [r7, 0xC]
	ldrh r0, [r7, 0xE]
	ldr r2, =0xffff8000
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r7, 0xE]
	mov r0, r8
	strh r0, [r6, 0x26]
	strh r0, [r6, 0x24]
	ldr r0, =sub_8022A94
	str r0, [r6, 0x1C]
	adds r2, r6, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r2, 0x12
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022B28

	thumb_func_start sub_8022BEC
sub_8022BEC: @ 8022BEC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r2, 0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	mov r8, r4
	bl sub_8020C00
	adds r6, r0, 0
	cmp r5, 0x19
	bls _08022C0A
	movs r5, 0
_08022C0A:
	cmp r4, 0
	beq _08022C14
	cmp r4, 0x1
	beq _08022C40
	b _08022C4A
_08022C14:
	cmp r5, 0
	beq _08022C28
	ldr r0, =gUnknown_082F43CC
	lsls r1, r5, 2
	adds r1, r0
	ldr r2, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl _call_via_r2
_08022C28:
	ldrb r0, [r6, 0xE]
	cmp r0, 0x19
	bls _08022C32
	mov r0, r8
	strb r0, [r6, 0xE]
_08022C32:
	ldr r0, =gUnknown_082F43CC
	ldrb r1, [r6, 0xE]
	lsls r1, 2
	b _08022C44
	.pool
_08022C40:
	ldr r0, =gUnknown_082F43CC
	lsls r1, r5, 2
_08022C44:
	adds r1, r0
	ldr r0, [r1]
	str r0, [r6, 0x4]
_08022C4A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8022BEC

	thumb_func_start sub_8022C58
sub_8022C58: @ 8022C58
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r2, [r1]
	ldrb r3, [r1, 0x1]
	lsls r3, 8
	orrs r2, r3
	ldrb r3, [r1, 0x2]
	lsls r3, 16
	orrs r2, r3
	ldrb r3, [r1, 0x3]
	lsls r3, 24
	adds r0, r2, 0
	orrs r0, r3
	ldrb r2, [r1, 0x9]
	strb r2, [r1]
	ldrb r4, [r1, 0x8]
	lsls r4, 8
	ldrb r2, [r1, 0x7]
	orrs r4, r2
	ldr r5, =gPaletteFade
	ldrb r3, [r5, 0x8]
	movs r2, 0x7F
	ands r2, r3
	strb r2, [r5, 0x8]
	movs r5, 0x4
	ldrsb r5, [r1, r5]
	ldrb r2, [r1, 0x5]
	ldrb r3, [r1, 0x6]
	str r4, [sp]
	adds r1, r5, 0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	movs r0, 0x2
	strb r0, [r6, 0xE]
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8022C58

	thumb_func_start sub_8022CB0
sub_8022CB0: @ 8022CB0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08022CE4
	cmp r0, 0x1
	bgt _08022CC6
	cmp r0, 0
	beq _08022CD0
	b _08022D06
_08022CC6:
	cmp r0, 0x2
	beq _08022CEA
	cmp r0, 0x3
	beq _08022CF6
	b _08022D06
_08022CD0:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08022D0C
	ldrb r0, [r5]
	cmp r0, 0
	bne _08022D06
	movs r0, 0x3
	b _08022D0A
_08022CE4:
	bl sub_8010434
	b _08022D06
_08022CEA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	bne _08022D06
	b _08022D0C
_08022CF6:
	ldrb r0, [r4, 0xF]
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strb r0, [r4, 0xC]
	b _08022D0E
_08022D06:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
_08022D0A:
	strb r0, [r4, 0xC]
_08022D0C:
	movs r0, 0
_08022D0E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8022CB0

	thumb_func_start sub_8022D14
sub_8022D14: @ 8022D14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r7, r0, 0
	adds r5, r1, 0
	ldrb r4, [r5, 0x3]
	lsls r4, 8
	ldrb r0, [r5, 0x2]
	orrs r4, r0
	ldrb r6, [r7, 0xC]
	cmp r6, 0x1
	beq _08022DC0
	cmp r6, 0x1
	bgt _08022D38
	cmp r6, 0
	beq _08022D42
	b _08022E08
_08022D38:
	cmp r6, 0x2
	beq _08022DD8
	cmp r6, 0x3
	beq _08022DE8
	b _08022E08
_08022D42:
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldrb r1, [r5, 0x1]
	movs r0, 0x2
	mov r8, r0
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08022D90
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_082F32A4
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldrb r3, [r7, 0xB]
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized2
	b _08022DB2
	.pool
_08022D90:
	ldr r1, =gUnknown_082F32A4
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldrb r3, [r7, 0xB]
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
_08022DB2:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _08022E08
	.pool
_08022DC0:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _08022E0E
	cmp r4, 0
	bne _08022E08
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
	strb r0, [r7, 0xC]
	b _08022E08
_08022DD8:
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	ands r4, r0
	cmp r4, 0
	bne _08022E08
	b _08022E0E
	.pool
_08022DE8:
	ldrb r1, [r5, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08022DFA
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
_08022DFA:
	ldrb r0, [r7, 0xE]
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	ldrb r0, [r5, 0x4]
	b _08022E0C
_08022E08:
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
_08022E0C:
	strb r0, [r7, 0xC]
_08022E0E:
	movs r0, 0
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8022D14

	thumb_func_start sub_8022E1C
sub_8022E1C: @ 8022E1C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_802104C
	cmp r0, 0
	beq _08022E34
	ldrb r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x36
	movs r1, 0
	bl sub_8022BEC
_08022E34:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E1C

	thumb_func_start sub_8022E3C
sub_8022E3C: @ 8022E3C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_802130C
	cmp r0, 0
	beq _08022E54
	ldrb r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x36
	movs r1, 0
	bl sub_8022BEC
_08022E54:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E3C

	thumb_func_start sub_8022E5C
sub_8022E5C: @ 8022E5C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	beq _08022E6C
	cmp r0, 0x1
	beq _08022E72
	b _08022E9C
_08022E6C:
	bl sub_8010434
	b _08022E9C
_08022E72:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08022EA2
	ldr r0, =0x000001e5
	bl PlayNewMapMusic
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x3
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _08022EA2
	.pool
_08022E9C:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08022EA2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8022E5C

	thumb_func_start sub_8022EAC
sub_8022EAC: @ 8022EAC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0
	beq _08022EC2
	cmp r0, 0x1
	beq _08022EE8
	adds r0, 0x1
	b _08022EF8
_08022EC2:
	adds r0, r4, 0
	bl sub_8024578
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8024644
	movs r0, 0x7
	strb r0, [r4, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08022EFA
_08022EE8:
	movs r0, 0x8
	strb r0, [r4, 0xE]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0x2
_08022EF8:
	strb r0, [r4, 0xC]
_08022EFA:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8022EAC

	thumb_func_start sub_8022F04
sub_8022F04: @ 8022F04
	push {lr}
	movs r1, 0
	str r1, [r0, 0x4]
	ldr r0, =sub_8020E1C
	bl SetMainCallback2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8022F04

	thumb_func_start sub_8022F1C
sub_8022F1C: @ 8022F1C
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r2, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x5
	bls _08022F2C
	b _08023060
_08022F2C:
	lsls r0, 2
	ldr r1, =_08022F3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08022F3C:
	.4byte _08022F54
	.4byte _08022F74
	.4byte _08022F7A
	.4byte _08022FAA
	.4byte _08022FBA
	.4byte _08023044
_08022F54:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r2, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x9
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023066
_08022F74:
	bl sub_8010434
	b _08023060
_08022F7A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023066
	adds r4, r5, 0
	adds r4, 0x42
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	ldrb r0, [r5, 0x8]
	lsls r0, 5
	adds r0, r5, r0
	adds r0, 0xA4
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl SendBlock
	b _08023060
_08022FAA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023066
	movs r0, 0
	strh r0, [r5, 0x10]
	b _08023060
_08022FBA:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r4, [r5, 0x9]
	subs r1, r4, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _08023066
	movs r3, 0
	cmp r3, r4
	bcs _0802301E
	ldr r7, =gBlockRecvBuffer
	movs r6, 0
	ldr r4, =gUnknown_0858AB24
_08022FDC:
	lsls r0, r3, 5
	adds r0, r5, r0
	lsls r1, r3, 8
	adds r1, r7
	ldrh r1, [r1]
	adds r2, r0, 0
	adds r2, 0xA4
	strh r1, [r2]
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xB0
	bls _08022FF6
	strh r6, [r2]
_08022FF6:
	ldrh r1, [r2]
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x18]
	ldrb r1, [r1]
	adds r0, r1
	strh r0, [r5, 0x18]
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x2]
	ldr r0, [r5, 0x1C]
	adds r0, r1
	str r0, [r5, 0x1C]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r3, r0
	bcc _08022FDC
_0802301E:
	movs r0, 0
	strh r0, [r5, 0x10]
	bl ResetBlockReceivedFlags
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x80
	lsls r1, 6
	bl sub_81515FC
	str r0, [r5, 0x20]
	b _08023060
	.pool
_08023044:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r0, 0xA
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x4
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _08023066
_08023060:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_08023066:
	movs r0, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8022F1C

	thumb_func_start sub_8023070
sub_8023070: @ 8023070
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x6
	bls _0802307C
	b _080231A8
_0802307C:
	lsls r0, 2
	ldr r1, =_0802308C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802308C:
	.4byte _080230A8
	.4byte _080230BA
	.4byte _080230E8
	.4byte _08023120
	.4byte _08023150
	.4byte _08023172
	.4byte _08023184
_080230A8:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	adds r0, r4, 0
	bl sub_80214A8
	bl sub_8010434
	b _080231A8
_080230BA:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	ldr r3, =0x00000139
	adds r1, r4, r3
	strb r0, [r1]
	adds r2, 0x2
	adds r1, r4, r2
	strb r0, [r1]
	adds r3, 0x2
	adds r1, r4, r3
	strb r0, [r1]
	b _080231A8
	.pool
_080230E8:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	ldrb r0, [r3]
	lsls r0, 2
	movs r2, 0xB8
	lsls r2, 1
	adds r1, r4, r2
	adds r0, r1, r0
	ldr r2, [r0]
	ldr r0, =sub_8021608
	str r0, [r2, 0x1C]
	ldrb r0, [r3]
	lsls r0, 2
	adds r1, r0
	ldr r1, [r1]
	adds r1, 0x2C
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x3D
	bl PlaySE
	b _080231A8
	.pool
_08023120:
	movs r3, 0x9C
	lsls r3, 1
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r0, 2
	adds r3, 0x38
	adds r1, r4, r3
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r1, [r0, 0x1C]
	ldr r0, =sub_8021608
	cmp r1, r0
	beq _080231AE
	movs r0, 0
	str r0, [r3]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	bl sub_8010434
	b _080231A8
	.pool
_08023150:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	ldrb r0, [r1]
	ldrb r2, [r4, 0x9]
	cmp r0, r2
	bcs _0802316C
	movs r0, 0x2
	b _080231AC
_0802316C:
	movs r0, 0
	strb r0, [r1]
	b _080231A8
_08023172:
	movs r3, 0x9C
	lsls r3, 1
	adds r1, r4, r3
	adds r0, r4, 0
	bl sub_80216A8
	bl sub_8010434
	b _080231A8
_08023184:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080231AE
	movs r0, 0x2B
	bl PlaySE
	movs r0, 0xB
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x5
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _080231AE
_080231A8:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
_080231AC:
	strb r0, [r4, 0xC]
_080231AE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023070

	thumb_func_start sub_80231B8
sub_80231B8: @ 80231B8
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0xC]
	cmp r1, 0x1
	beq _0802321C
	cmp r1, 0x1
	bgt _080231CC
	cmp r1, 0
	beq _080231D6
	b _080232DC
_080231CC:
	cmp r1, 0x2
	beq _0802329C
	cmp r1, 0x3
	beq _080232BE
	b _080232DC
_080231D6:
	ldrh r0, [r4, 0x2A]
	adds r0, 0x4
	strh r0, [r4, 0x2A]
	lsls r0, 16
	cmp r0, 0
	bge _080231E4
	b _080232E2
_080231E4:
	strh r1, [r4, 0x2A]
	ldr r0, =0x00000139
	adds r3, r4, r0
	movs r0, 0x4
	strb r0, [r3]
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	ldr r2, =gUnknown_082F326C
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r2, 0x9D
	lsls r2, 1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, 0xD6
	bl PlaySE
	b _080232DC
	.pool
_0802321C:
	ldr r7, =gUnknown_082F326C
	movs r0, 0x9C
	lsls r0, 1
	adds r6, r4, r0
	ldr r1, =0x00000139
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	ldrb r2, [r6]
	adds r0, r2
	adds r0, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	strh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	movs r1, 0x9D
	lsls r1, 1
	adds r2, r4, r1
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2]
	cmp r0, r1
	bcc _080232E2
	ldrb r0, [r5]
	cmp r0, 0
	beq _080232DC
	subs r0, 0x1
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0
	strb r0, [r6]
	b _080232E2
	.pool
_0802329C:
	movs r0, 0
	strh r0, [r4, 0x2C]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	bl sub_8010434
	b _080232DC
_080232BE:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080232E2
	movs r0, 0xC
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0x6
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _080232E2
_080232DC:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_080232E2:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80231B8

	thumb_func_start sub_80232EC
sub_80232EC: @ 80232EC
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _0802330C
	cmp r0, 0x1
	bgt _08023302
	cmp r0, 0
	beq _08023332
	b _0802338C
_08023302:
	cmp r0, 0x2
	beq _0802332A
	cmp r0, 0x3
	beq _08023338
	b _0802338C
_0802330C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023392
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x78
	movs r3, 0x50
	bl sub_802EB24
	b _0802338C
_0802332A:
	bl sub_802EB84
	cmp r0, 0
	bne _08023392
_08023332:
	bl sub_8010434
	b _0802338C
_08023338:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023392
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x00000139
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	strh r0, [r4, 0x10]
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _08023378
	movs r0, 0xD
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023382
	.pool
_08023378:
	movs r0, 0xE
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_08023382:
	movs r1, 0
	movs r0, 0x7
	strh r0, [r4, 0x12]
	strb r1, [r4, 0xC]
	b _08023392
_0802338C:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08023392:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80232EC

	thumb_func_start sub_802339C
sub_802339C: @ 802339C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	movs r0, 0
	mov r8, r0
	movs r2, 0
	adds r7, r2, 0
	ldrb r1, [r4, 0x9]
	cmp r7, r1
	bcs _080234AA
	movs r2, 0x5E
	adds r2, r4
	mov r9, r2
	ldr r3, =gUnknown_082F325C
	mov r10, r3
_080233C0:
	lsls r0, r7, 4
	ldr r1, =gRecvCmds
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r3, 0xBC
	lsls r3, 6
	cmp r0, r3
	bne _0802349E
	ldrh r0, [r2, 0x2]
	cmp r0, 0x2
	bne _0802349E
	ldrb r1, [r2, 0x4]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08023496
	mov r0, r9
	ldrb r2, [r0]
	lsrs r1, r2, 3
	mov r3, r10
	adds r0, r7, r3
	ldrb r0, [r0]
	orrs r1, r0
	lsls r1, 3
	movs r0, 0x7
	ands r0, r2
	orrs r0, r1
	mov r1, r9
	strb r0, [r1]
	lsls r2, r7, 5
	adds r3, r4, r2
	mov r12, r3
	mov r1, r12
	adds r1, 0xB5
	movs r0, 0x1
	strb r0, [r1]
	subs r1, 0x7
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	subs r1, 0x8
	ldrh r0, [r4, 0x28]
	ldrh r1, [r1]
	subs r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	mov r5, r12
	adds r5, 0xAA
	ldrh r1, [r5]
	subs r0, r1, 0x1
	adds r6, r2, 0
	cmp r3, r0
	blt _08023468
	adds r0, r1, 0x1
	cmp r3, r0
	bgt _08023468
	mov r1, r12
	adds r1, 0xA8
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	strh r3, [r5]
	mov r0, r12
	adds r0, 0xAC
	ldrh r1, [r1]
	ldrh r2, [r0]
	cmp r1, r2
	bls _08023476
	strh r1, [r0]
	b _08023476
	.pool
_08023468:
	adds r0, r4, r6
	adds r2, r0, 0
	adds r2, 0xA8
	movs r1, 0
	strh r1, [r2]
	adds r0, 0xAA
	strh r3, [r0]
_08023476:
	adds r1, r4, r6
	ldrh r0, [r4, 0x28]
	adds r3, r1, 0
	adds r3, 0xA6
	movs r2, 0
	strh r0, [r3]
	adds r1, 0xB4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0802349E
	strb r2, [r1]
	b _0802349E
_08023496:
	lsls r0, r7, 5
	adds r0, r4, r0
	adds r0, 0xB5
	strb r1, [r0]
_0802349E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r3, [r4, 0x9]
	cmp r7, r3
	bcc _080233C0
_080234AA:
	mov r0, r8
	cmp r0, 0x1
	bls _080234E0
	movs r7, 0
	ldrb r1, [r4, 0x9]
	cmp r7, r1
	bcs _080234E0
	movs r3, 0x2
_080234BA:
	lsls r0, r7, 5
	adds r1, r4, r0
	adds r2, r1, 0
	adds r2, 0xB5
	ldrb r0, [r2]
	cmp r0, 0
	beq _080234D4
	orrs r0, r3
	strb r0, [r2]
	adds r1, 0xB0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_080234D4:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r2, [r4, 0x9]
	cmp r7, r2
	bcc _080234BA
_080234E0:
	mov r3, r8
	cmp r3, 0
	beq _08023548
	ldrh r0, [r4, 0x2E]
	add r0, r8
	strh r0, [r4, 0x2E]
	ldr r1, =gUnknown_082F3264
	mov r0, r8
	subs r0, 0x1
	adds r0, r1
	ldrb r0, [r0]
	add r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r4, 0x34]
	add r0, r8
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x1A]
	add r0, r8
	strh r0, [r4, 0x1A]
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	movs r3, 0x1A
	ldrsh r2, [r4, r3]
	subs r0, r2
	cmp r0, 0
	ble _08023534
	lsls r2, 8
	ldr r1, [r4, 0x20]
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	asrs r2, 8
	adds r0, r4, 0
	adds r0, 0x24
	strb r2, [r0]
	b _08023548
	.pool
_08023534:
	adds r1, r4, 0
	adds r1, 0x24
	movs r0, 0x20
	strb r0, [r1]
	adds r2, r4, 0
	adds r2, 0x5E
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08023548:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802339C

	thumb_func_start sub_8023558
sub_8023558: @ 8023558
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r6, 0
	movs r1, 0
	adds r4, r1, 0
	ldrb r0, [r3, 0x9]
	cmp r4, r0
	bcs _080235B0
	adds r5, r3, 0
	adds r5, 0x64
_0802356C:
	lsls r0, r4, 5
	adds r1, r3, r0
	adds r0, r1, 0
	adds r0, 0xB5
	ldrb r2, [r0]
	cmp r2, 0
	beq _080235A4
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r1, 0
	adds r0, 0xB4
	ldrb r0, [r0]
	adds r1, r0, 0x1
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08023594
	movs r0, 0x4
	orrs r1, r0
_08023594:
	lsls r0, r4, 1
	adds r0, r4
	lsls r1, r0
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
_080235A4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r1, [r3, 0x9]
	cmp r4, r1
	bcc _0802356C
_080235B0:
	adds r0, r3, 0
	adds r0, 0x24
	ldrb r1, [r0]
	adds r0, 0x3C
	strh r1, [r0]
	cmp r6, 0
	bne _080235D4
	ldr r2, =0x0000013b
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080236A0
	movs r4, 0x9C
	lsls r4, 1
	adds r1, r3, r4
	b _08023612
	.pool
_080235D4:
	ldr r5, =0x0000013b
	adds r2, r3, r5
	ldrb r0, [r2]
	cmp r0, 0
	beq _0802361A
	ldr r0, =0x00000139
	adds r1, r3, r0
	ldrb r2, [r1]
	cmp r6, r2
	beq _0802360C
	subs r0, r6, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_082F3290
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x9D
	lsls r4, 1
	adds r1, r3, r4
	strb r0, [r1]
	b _08023640
	.pool
_0802360C:
	movs r5, 0x9C
	lsls r5, 1
	adds r1, r3, r5
_08023612:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08023640
_0802361A:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0
	strb r0, [r1]
	subs r0, r6, 0x1
	ldr r4, =0x00000139
	adds r1, r3, r4
	strb r0, [r1]
	ldr r1, =gUnknown_082F3290
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r5, 0x9D
	lsls r5, 1
	adds r1, r3, r5
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r2]
_08023640:
	ldr r0, =0x0000013b
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, 0
	beq _080236A0
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r3, r2
	movs r5, 0x9D
	lsls r5, 1
	adds r2, r3, r5
	ldrb r0, [r1]
	ldrb r5, [r2]
	cmp r0, r5
	bcc _0802367C
	movs r0, 0
	strb r0, [r1]
	ldr r5, =0x00000139
	adds r1, r3, r5
	strb r0, [r1]
	strb r0, [r2]
	strb r0, [r4]
	movs r1, 0
	b _08023690
	.pool
_0802367C:
	ldr r2, =gUnknown_082F3290
	ldrb r1, [r1]
	ldr r4, =0x00000139
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, 0x1
	adds r1, r0
	adds r1, r2
	ldrb r1, [r1]
_08023690:
	adds r0, r3, 0
	adds r0, 0x5F
	strb r1, [r0]
	b _080236A8
	.pool
_080236A0:
	adds r1, r3, 0
	adds r1, 0x5F
	movs r0, 0
	strb r0, [r1]
_080236A8:
	ldrh r1, [r3, 0x26]
	adds r0, r3, 0
	adds r0, 0x62
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8023558

	thumb_func_start sub_80236B8
sub_80236B8: @ 80236B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldr r3, =gMain
	ldrh r1, [r3, 0x2E]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080236DA
	adds r2, r5, 0
	adds r2, 0x5E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080236DA:
	ldrh r1, [r3, 0x2C]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080236FA
	ldrb r0, [r5, 0x8]
	lsls r0, 5
	adds r0, r5, r0
	adds r1, r0, 0
	adds r1, 0xB2
	ldrh r0, [r1]
	ldrh r2, [r5, 0x28]
	cmp r0, r2
	bcs _080236FA
	adds r0, 0x1
	strh r0, [r1]
_080236FA:
	ldrb r0, [r5, 0x8]
	adds r7, r5, 0
	adds r7, 0x5E
	cmp r0, 0
	beq _08023710
	ldrb r1, [r7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08023710
	b _0802384C
_08023710:
	adds r4, r5, 0
	adds r4, 0x5C
	movs r0, 0x2
	strh r0, [r4]
	ldrh r0, [r5, 0x28]
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	mov r8, r4
	adds r6, r5, 0
	adds r6, 0x25
	cmp r0, 0
	bne _08023768
	movs r0, 0x2E
	ldrsh r2, [r5, r0]
	ldr r1, =gUnknown_082F4444
	ldrb r0, [r5, 0x9]
	subs r0, 0x2
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	ble _08023754
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrb r0, [r6]
	movs r1, 0x10
	orrs r0, r1
	b _0802375C
	.pool
_08023754:
	ldrb r1, [r6]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
_0802375C:
	strb r0, [r6]
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
_08023768:
	ldrh r0, [r5, 0x28]
	movs r1, 0xF
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _080237DE
	movs r0, 0x34
	ldrsh r2, [r5, r0]
	ldr r3, =gUnknown_082F4434
	ldrb r0, [r5, 0x9]
	subs r0, 0x2
	lsls r1, r0, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge _08023798
	ldrb r1, [r6]
	movs r0, 0x1F
	ands r0, r1
	strb r0, [r6]
	b _080237D8
	.pool
_08023798:
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237AC
	ldrb r0, [r6]
	movs r1, 0x1F
	ands r1, r0
	movs r0, 0x20
	b _080237D4
_080237AC:
	adds r0, r3, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237BC
	movs r0, 0x2
	strh r0, [r5, 0x34]
	b _080237D8
_080237BC:
	adds r0, r3, 0x3
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _080237CC
	movs r0, 0x3
	strh r0, [r5, 0x34]
	b _080237D8
_080237CC:
	ldrb r0, [r6]
	movs r1, 0x1F
	ands r1, r0
	movs r0, 0x80
_080237D4:
	orrs r1, r0
	strb r1, [r6]
_080237D8:
	movs r0, 0
	strh r0, [r5, 0x34]
	b _0802380A
_080237DE:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3C
	bls _0802380A
	cmp r0, 0x46
	bls _080237FA
	bl sub_8011AC8
	movs r0, 0
	strh r0, [r5, 0x10]
	b _0802380A
_080237FA:
	ldrb r0, [r7]
	movs r4, 0xF8
	ands r4, r0
	cmp r4, 0
	bne _0802380A
	bl sub_8011AC8
	strh r4, [r5, 0x10]
_0802380A:
	ldrh r1, [r5, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _0802381A
	ldrb r0, [r7]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r7]
_0802381A:
	ldrb r1, [r6]
	lsls r1, 27
	lsrs r1, 31
	lsls r1, 1
	ldrb r2, [r7]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	ldrb r0, [r6]
	lsrs r0, 5
	adds r2, r5, 0
	adds r2, 0x66
	strh r0, [r2]
	adds r4, r5, 0
	adds r4, 0x42
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0xC
	bl memcpy
	adds r0, r4, 0
	bl sub_800FE50
_0802384C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80236B8

	thumb_func_start sub_802385C
sub_802385C: @ 802385C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r3, =gRecvCmds
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcs _08023880
	movs r1, 0
_0802386C:
	lsls r0, r4, 5
	adds r0, r5, r0
	adds r0, 0xB5
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r5, 0x9]
	cmp r4, r0
	bcc _0802386C
_08023880:
	adds r2, r3, 0
	ldrh r0, [r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08023898
	ldrh r0, [r2, 0x2]
	cmp r0, 0x2
	beq _080238AC
_08023898:
	adds r2, r5, 0
	adds r2, 0x25
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _080238EA
	.pool
_080238AC:
	adds r4, r5, 0
	adds r4, 0x4E
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0xE
	bl memcpy
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x2A]
	movs r0, 0x5
	ldrsb r0, [r4, r0]
	strh r0, [r5, 0x2C]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x28]
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_80216E0
	ldrb r1, [r4, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080238EA
	adds r0, r5, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_080238EA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802385C

	thumb_func_start sub_80238F0
sub_80238F0: @ 80238F0
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0xC
	bl memset
	adds r0, r4, 0
	adds r0, 0x4E
	movs r1, 0
	movs r2, 0xE
	bl memset
	adds r0, r4, 0
	bl sub_802385C
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	adds r0, r4, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08023978
	ldrh r1, [r4, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08023964
	adds r0, 0x1
	strh r0, [r4, 0x28]
	movs r0, 0x10
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _0802396E
	.pool
_08023964:
	movs r0, 0xF
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_0802396E:
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023992
_08023978:
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	bl sub_802339C
	adds r0, r4, 0
	bl sub_8023558
	adds r0, r4, 0
	bl sub_80236B8
	movs r0, 0
_08023992:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80238F0

	thumb_func_start sub_8023998
sub_8023998: @ 8023998
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0xC
	bl memset
	adds r0, r4, 0
	adds r0, 0x4E
	movs r1, 0
	movs r2, 0xE
	bl memset
	adds r0, r4, 0
	bl sub_802385C
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	adds r0, r4, 0
	adds r0, 0x25
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08023A20
	ldrh r1, [r4, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08023A0C
	adds r0, 0x1
	strh r0, [r4, 0x28]
	movs r0, 0x10
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _08023A16
	.pool
_08023A0C:
	movs r0, 0xF
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_08023A16:
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023A28
_08023A20:
	adds r0, r4, 0
	bl sub_80236B8
	movs r0, 0
_08023A28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023998

	thumb_func_start sub_8023A30
sub_8023A30: @ 8023A30
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x5
	bls _08023A3C
	b _08023BB2
_08023A3C:
	lsls r0, 2
	ldr r1, =_08023A4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08023A4C:
	.4byte _08023A64
	.4byte _08023A8C
	.4byte _08023ADC
	.4byte _08023B5C
	.4byte _08023B7A
	.4byte _08023B94
_08023A64:
	movs r0, 0x8
	strh r0, [r4, 0x12]
	movs r0, 0xD6
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x000003ff
	movs r1, 0x8
	bl BlendPalettes
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _08023BB2
	.pool
_08023A8C:
	movs r1, 0x9C
	lsls r1, 1
	adds r5, r4, r1
	ldrb r0, [r5]
	subs r0, 0x1
	strb r0, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08023AA2
	b _08023BB8
_08023AA2:
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x000003ff
	movs r1, 0
	bl BlendPalettes
	ldr r2, =0x00000139
	adds r1, r4, r2
	movs r0, 0x4
	strb r0, [r1]
	movs r0, 0
	strb r0, [r5]
	ldr r2, =gUnknown_082F326C
	ldrb r1, [r1]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r2, 0x9D
	lsls r2, 1
	adds r1, r4, r2
	strb r0, [r1]
	b _08023BB2
	.pool
_08023ADC:
	ldr r7, =gUnknown_082F326C
	movs r0, 0x9C
	lsls r0, 1
	adds r6, r4, r0
	ldr r1, =0x00000139
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	ldrb r2, [r6]
	adds r0, r2
	adds r0, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	strh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x12
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1A
	bl SetGpuReg
	ldrh r1, [r4, 0x2C]
	negs r1, r1
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl SetGpuReg
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	movs r1, 0x9D
	lsls r1, 1
	adds r2, r4, r1
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2]
	cmp r0, r1
	bcc _08023BB8
	ldrb r0, [r5]
	cmp r0, 0
	beq _08023BB2
	subs r0, 0x1
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	adds r0, r7
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0
	strb r0, [r6]
	b _08023BB8
	.pool
_08023B5C:
	movs r0, 0
	strh r0, [r4, 0x2C]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	b _08023BB2
_08023B7A:
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r4, r2
	adds r0, r4, 0
	bl sub_80218D4
	cmp r0, 0
	beq _08023BB8
	bl sub_8010434
	movs r0, 0
	strh r0, [r4, 0x10]
	b _08023BB2
_08023B94:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023BB8
	movs r0, 0x11
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _08023BBA
_08023BB2:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_08023BB8:
	movs r0, 0
_08023BBA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8023A30

	thumb_func_start sub_8023BC0
sub_8023BC0: @ 8023BC0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _08023C04
	cmp r0, 0x1
	bgt _08023BD8
	cmp r0, 0
	beq _08023BE2
	b _08023C9C
_08023BD8:
	cmp r0, 0x2
	beq _08023C2A
	cmp r0, 0x3
	beq _08023C5C
	b _08023C9C
_08023BE2:
	movs r0, 0x9
	strh r0, [r5, 0x12]
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x8
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	strb r0, [r1]
	b _08023C9C
_08023C04:
	movs r0, 0x9C
	lsls r0, 1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08023CA2
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0
	strb r0, [r4]
	b _08023C9C
_08023C2A:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_80218D4
	cmp r0, 0
	beq _08023CA2
	bl sub_8010434
	movs r0, 0
	strh r0, [r5, 0x10]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	b _08023C9C
_08023C5C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023CA2
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x7
	movs r2, 0x1
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x10]
	b _08023CA0
	.pool
_08023C9C:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08023CA0:
	strb r0, [r5, 0xC]
_08023CA2:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8023BC0

	thumb_func_start sub_8023CAC
sub_8023CAC: @ 8023CAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r0, 0
	ldrb r0, [r7, 0xC]
	cmp r0, 0x7
	bls _08023CC2
	b _0802402E
_08023CC2:
	lsls r0, 2
	ldr r1, =_08023CD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08023CD0:
	.4byte _08023CF0
	.4byte _08023D2A
	.4byte _08023D38
	.4byte _08023DA0
	.4byte _08023F20
	.4byte _08023FD0
	.4byte _08023FDC
	.4byte _08024010
_08023CF0:
	adds r4, r7, 0
	adds r4, 0x42
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x4
	bl memset
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r2, r0, 0
	adds r2, 0xB2
	ldrh r1, [r7, 0x28]
	ldrh r0, [r2]
	cmp r0, r1
	bls _08023D12
	strh r1, [r2]
_08023D12:
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r0, 0xB2
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl SendBlock
	b _0802402E
_08023D2A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	bne _08023D36
	b _08024034
_08023D36:
	b _08024004
_08023D38:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r7, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _08023D50
	b _08024034
_08023D50:
	movs r0, 0
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x42
	cmp r8, r3
	bcs _08023D7E
	ldr r2, =gBlockRecvBuffer
_08023D5E:
	mov r3, r8
	lsls r1, r3, 5
	adds r1, r7, r1
	lsls r0, r3, 8
	adds r0, r2
	ldrh r0, [r0]
	adds r1, 0xB2
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r6, [r7, 0x9]
	cmp r8, r6
	bcc _08023D5E
_08023D7E:
	movs r0, 0
	strh r0, [r7, 0x10]
	strh r0, [r4]
	bl ResetBlockReceivedFlags
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _08023D9C
	movs r0, 0x3
	b _08024032
	.pool
_08023D9C:
	movs r0, 0x6
	b _08024032
_08023DA0:
	adds r0, r7, 0
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldrh r1, [r7, 0x28]
	adds r0, r7, 0
	adds r0, 0x6C
	strh r1, [r0]
	movs r0, 0x18
	ldrsh r4, [r7, r0]
	ldrh r0, [r7, 0x28]
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl __divsi3
	adds r1, r7, 0
	adds r1, 0x6E
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	lsls r0, 8
	movs r4, 0xC8
	lsls r4, 6
	adds r1, r4, 0
	bl sub_8151574
	adds r2, r0, 0
	movs r3, 0x32
	ldrsh r1, [r7, r3]
	lsls r1, 8
	bl sub_81515FC
	adds r2, r0, r4
	asrs r2, 8
	movs r1, 0x7F
	adds r0, r2, 0
	ands r0, r1
	adds r1, r7, 0
	adds r1, 0x70
	strh r0, [r1]
	lsls r2, 8
	movs r1, 0xC8
	lsls r1, 7
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	ldrb r1, [r7, 0x9]
	ldr r0, [r7, 0x1C]
	muls r0, r1
	lsls r4, r0, 8
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8151574
	adds r4, r0, 0
	asrs r0, r4, 8
	str r0, [r7, 0x68]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r1, r7, 0
	adds r1, 0x8F
	strb r0, [r1]
	movs r6, 0
	mov r8, r6
	mov r9, r1
	ldrb r0, [r7, 0x9]
	cmp r8, r0
	bcc _08023E44
	b _0802402E
_08023E44:
	adds r0, r7, 0
	adds r0, 0x88
	add r0, r8
	mov r1, r8
	strb r1, [r0]
	adds r0, r7, 0
	adds r0, 0x90
	add r0, r8
	strb r1, [r0]
	mov r3, r8
	lsls r2, r3, 1
	adds r1, r7, 0
	adds r1, 0x74
	adds r1, r2
	lsls r0, r3, 5
	adds r3, r7, r0
	adds r5, r3, 0
	adds r5, 0xAE
	ldrh r0, [r5]
	strh r0, [r1]
	adds r1, r7, 0
	adds r1, 0x72
	ldrh r6, [r1]
	adds r0, r6
	strh r0, [r1]
	mov r1, r9
	ldrb r0, [r1]
	adds r6, r2, 0
	cmp r0, 0x1
	beq _08023EAE
	cmp r0, 0x1
	bgt _08023E8A
	cmp r0, 0
	beq _08023E90
	b _08023F04
_08023E8A:
	cmp r0, 0x2
	beq _08023ECC
	b _08023F04
_08023E90:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xAC
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023EAE:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xB0
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023ECC:
	ldrh r0, [r5]
	cmp r0, 0
	bne _08023ED6
_08023ED2:
	movs r4, 0
	b _08023F04
_08023ED6:
	adds r1, r3, 0
	adds r1, 0xB2
	ldrh r0, [r1]
	ldrh r2, [r7, 0x28]
	cmp r0, r2
	bcc _08023EE8
	movs r4, 0xC8
	lsls r4, 7
	b _08023F04
_08023EE8:
	ldrh r2, [r1]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r7, 0x28]
_08023EFA:
	lsls r4, 8
	adds r1, r4, 0
	bl sub_81515FC
	adds r4, r0, 0
_08023F04:
	asrs r4, 4
	adds r0, r7, 0
	adds r0, 0x7E
	adds r0, r6
	strh r4, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r7, 0x9]
	cmp r8, r3
	bcc _08023E44
	b _0802402E
_08023F20:
	movs r6, 0
	mov r8, r6
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	adds r1, r7, 0
	adds r1, 0x68
	str r1, [sp, 0xC]
	cmp r8, r0
	bge _08023FC4
_08023F32:
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r2, r8
	adds r2, 0x1
	str r2, [sp, 0x8]
	cmp r4, r8
	bls _08023FB4
	adds r3, r7, 0
	adds r3, 0x74
	str r3, [sp]
	adds r6, r7, 0
	adds r6, 0x88
	str r6, [sp, 0x4]
	movs r0, 0x90
	adds r0, r7
	mov r10, r0
	movs r1, 0x7E
	adds r1, r7
	mov r9, r1
_08023F5C:
	subs r2, r4, 0x1
	mov r12, r2
	lsls r6, r2, 1
	ldr r0, [sp]
	adds r3, r0, r6
	lsls r5, r4, 1
	adds r1, r0, r5
	ldrh r2, [r3]
	ldrh r0, [r1]
	cmp r2, r0
	bcs _08023F86
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	ldr r1, [sp, 0x4]
	adds r2, r1, r4
	ldrb r3, [r2]
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023F86:
	mov r2, r9
	adds r3, r2, r6
	adds r1, r2, r5
	ldrh r2, [r3]
	ldrh r6, [r1]
	cmp r2, r6
	bcs _08023FAA
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	mov r0, r10
	adds r2, r0, r4
	ldrb r3, [r2]
	mov r1, r10
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023FAA:
	mov r1, r12
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r4, r8
	bhi _08023F5C
_08023FB4:
	ldr r2, [sp, 0x8]
	lsls r0, r2, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	cmp r8, r0
	blt _08023F32
_08023FC4:
	movs r0, 0
	ldr r1, [sp, 0xC]
	movs r2, 0x30
	bl SendBlock
	b _0802402E
_08023FD0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024034
	b _08024004
_08023FDC:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08024034
	adds r4, r7, 0
	adds r4, 0x68
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r1, =gBlockRecvBuffer
	adds r0, r4, 0
	movs r2, 0x30
	bl memcpy
	bl ResetBlockReceivedFlags
_08024004:
	movs r0, 0
	strh r0, [r7, 0x10]
	b _0802402E
	.pool
_08024010:
	bl sub_8020E58
	movs r0, 0x12
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	movs r1, 0xB
	strh r1, [r7, 0x12]
	strb r0, [r7, 0xC]
	adds r1, r7, 0
	adds r1, 0x24
	strb r0, [r1]
	b _08024034
_0802402E:
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
_08024032:
	strb r0, [r7, 0xC]
_08024034:
	movs r0, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8023CAC

	thumb_func_start sub_8024048
sub_8024048: @ 8024048
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024124
	lsls r0, 2
	ldr r1, =_08024064
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024064:
	.4byte _08024078
	.4byte _0802408A
	.4byte _0802409C
	.4byte _080240CC
	.4byte _080240DC
_08024078:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_8022070
	cmp r0, 0
	bne _08024124
	b _0802412A
_0802408A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1E
	strb r0, [r1]
	b _08024124
_0802409C:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080240AE
	subs r0, 0x1
	strb r0, [r1]
	b _0802412A
_080240AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0802412A
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_802222C
	b _08024124
	.pool
_080240CC:
	ldrh r0, [r5, 0x12]
	cmp r0, 0xC
	bhi _08024124
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802412A
_080240DC:
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	bl sub_80247BC
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x3
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802412A
	.pool
_08024124:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802412A:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024048

	thumb_func_start sub_8024134
sub_8024134: @ 8024134
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024218
	lsls r0, 2
	ldr r1, =_08024150
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024150:
	.4byte _08024164
	.4byte _080241A0
	.4byte _080241A6
	.4byte _080241F0
	.4byte _08024204
_08024164:
	ldrh r1, [r5, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08024176
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r5, r1
	bl sub_8022554
_08024176:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r4, 0
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802421E
	.pool
_080241A0:
	bl sub_8010434
	b _08024218
_080241A6:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802421E
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized2
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _08024218
	.pool
_080241F0:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _08024218
	b _0802421E
	.pool
_08024204:
	movs r0, 0x14
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0xF
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802421E
_08024218:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802421E:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024134

	thumb_func_start sub_8024228
sub_8024228: @ 8024228
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _0802426A
	cmp r0, 0x1
	bgt _08024240
	cmp r0, 0
	beq _08024246
	b _080242D0
_08024240:
	cmp r0, 0x2
	beq _08024270
	b _080242D0
_08024246:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0x4
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x14
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strb r0, [r5, 0xC]
	b _080242D8
_0802426A:
	bl DisplayYesNoMenu
	b _080242D0
_08024270:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _080242D6
	adds r0, r5, 0
	adds r0, 0x42
	movs r1, 0
	movs r2, 0xC
	bl memset
	cmp r4, 0
	bne _080242A2
	bl HasAtLeastOneBerry
	lsls r0, 24
	cmp r0, 0
	beq _0802429E
	strh r4, [r5, 0x14]
	b _080242A6
_0802429E:
	movs r0, 0x3
	b _080242A4
_080242A2:
	movs r0, 0x1
_080242A4:
	strh r0, [r5, 0x14]
_080242A6:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x15
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080242D6
_080242D0:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080242D6:
	movs r0, 0
_080242D8:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024228

	thumb_func_start sub_80242E0
sub_80242E0: @ 80242E0
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08024306
	cmp r0, 0x1
	bgt _080242F6
	cmp r0, 0
	beq _08024300
	b _080243AC
_080242F6:
	cmp r0, 0x2
	beq _08024328
	cmp r0, 0x3
	beq _08024336
	b _080243AC
_08024300:
	bl sub_8010434
	b _080243AC
_08024306:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	ldrh r0, [r4, 0x14]
	adds r1, r4, 0
	adds r1, 0x42
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4E
	strh r5, [r0]
	movs r0, 0
	movs r2, 0x2
	bl SendBlock
	b _080243AC
_08024328:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	strh r5, [r4, 0x10]
	b _080243AC
_08024336:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r4, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _080243B2
	adds r7, r4, 0
	adds r7, 0x42
	adds r6, r4, 0
	adds r6, 0x4E
	cmp r5, r3
	bcs _08024374
	adds r1, r6, 0
	ldr r2, =gBlockRecvBuffer
_0802435C:
	lsls r0, r5, 8
	adds r0, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4, 0x9]
	cmp r5, r0
	bcc _0802435C
_08024374:
	ldrh r0, [r6]
	cmp r0, 0
	beq _08024390
	movs r0, 0x17
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _0802439A
	.pool
_08024390:
	movs r0, 0x16
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_0802439A:
	bl ResetBlockReceivedFlags
	movs r1, 0
	movs r0, 0
	strh r0, [r7]
	strh r0, [r6]
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _080243B4
_080243AC:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_080243B2:
	movs r0, 0
_080243B4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80242E0

	thumb_func_start sub_80243BC
sub_80243BC: @ 80243BC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080243EA
	cmp r4, 0x1
	bgt _080243D2
	cmp r4, 0
	beq _080243DC
	b _08024434
_080243D2:
	cmp r4, 0x2
	beq _080243F6
	cmp r4, 0x3
	beq _0802441A
	b _08024434
_080243DC:
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	b _08024410
_080243EA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _08024434
	b _0802443A
_080243F6:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	adds r0, r5, 0
	bl sub_8021488
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
_08024410:
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _08024434
_0802441A:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0802443A
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x12]
	b _08024438
_08024434:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08024438:
	strb r0, [r5, 0xC]
_0802443A:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80243BC

	thumb_func_start sub_8024444
sub_8024444: @ 8024444
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080244BC
	cmp r4, 0x1
	bgt _0802445A
	cmp r4, 0
	beq _08024460
	b _080244F6
_0802445A:
	cmp r4, 0x2
	beq _080244D4
	b _080244F6
_08024460:
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldrh r1, [r5, 0x14]
	cmp r1, 0x3
	bne _08024490
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x14]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
	b _080244AC
	.pool
_08024490:
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x18]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
_080244AC:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _080244F6
	.pool
_080244BC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080244FC
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x78
	strb r0, [r1]
	b _080244F6
_080244D4:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, 0
	cmp r4, 0
	beq _080244E8
	subs r0, 0x1
	strb r0, [r1]
	b _080244FC
_080244E8:
	movs r0, 0x18
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080244FC
_080244F6:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080244FC:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024444

	thumb_func_start sub_8024508
sub_8024508: @ 8024508
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _08024528
	cmp r4, 0x1
	bgt _0802451C
	cmp r4, 0
	beq _08024522
	b _08024558
_0802451C:
	cmp r4, 0x2
	beq _08024538
	b _08024558
_08024522:
	bl sub_8010434
	b _08024558
_08024528:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802455E
	bl sub_800AC34
	b _08024558
_08024538:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802455E
	movs r0, 0x19
	strb r0, [r5, 0xE]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802455E
	.pool
_08024558:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802455E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024508

	thumb_func_start sub_8024568
sub_8024568: @ 8024568
	push {lr}
	movs r0, 0
	bl sub_8020C0C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8024568

	thumb_func_start sub_8024578
sub_8024578: @ 8024578
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x33
	bl IncrementGameStat
	strb r5, [r4, 0xD]
	movs r1, 0
	strh r5, [r4, 0x10]
	movs r0, 0x2
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	str r5, [r4, 0x1C]
	strh r5, [r4, 0x18]
	strh r5, [r4, 0x1A]
	str r5, [r4, 0x20]
	adds r0, r4, 0
	adds r0, 0x24
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x25
	movs r0, 0
	strb r0, [r1]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x28]
	strh r5, [r4, 0x2E]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x34]
	movs r6, 0
	movs r3, 0
_080245B8:
	lsls r0, r5, 5
	adds r2, r4, r0
	adds r1, r2, 0
	adds r1, 0xA4
	ldr r0, =0x0000ffff
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA6
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r1, 0x6
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xAC
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strb r6, [r0]
	adds r0, 0x1
	strb r6, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080245B8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024578

	thumb_func_start sub_8024604
sub_8024604: @ 8024604
	push {r4-r6,lr}
	sub sp, 0x8
	str r2, [sp, 0x4]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, 0x4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, 0x1]
	strb r2, [r0, 0x1]
	ldrb r2, [r4, 0x2]
	strb r2, [r0, 0x2]
	ldrb r2, [r4, 0x3]
	strb r2, [r0, 0x3]
	strb r3, [r0, 0x4]
	strb r5, [r0, 0x5]
	strb r6, [r0, 0x6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, 0x7]
	mov r2, sp
	ldrb r2, [r2, 0x1]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8024604

	thumb_func_start sub_8024644
sub_8024644: @ 8024644
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, [sp, 0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, 0x1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x2]
	mov r1, sp
	ldrb r1, [r1, 0x1]
	strb r1, [r0, 0x3]
	strb r5, [r0, 0x4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8024644

	thumb_func_start sub_8024668
sub_8024668: @ 8024668
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	adds r1, 0xAC
	ldr r0, [r0]
	ldr r1, [r1]
	eors r0, r1
	bx lr
	.pool
	thumb_func_end sub_8024668

	thumb_func_start SetBerryPowder
SetBerryPowder: @ 802467C
	ldr r2, =gSaveBlock2Ptr
	ldr r2, [r2]
	adds r2, 0xAC
	ldr r2, [r2]
	eors r2, r1
	str r2, [r0]
	bx lr
	.pool
	thumb_func_end SetBerryPowder

	thumb_func_start ApplyNewEncryptionKeyToBerryPowder
ApplyNewEncryptionKeyToBerryPowder: @ 8024690
	push {lr}
	adds r1, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r2
	bl ApplyNewEncryptionKeyToWord
	pop {r0}
	bx r0
	.pool
	thumb_func_end ApplyNewEncryptionKeyToBerryPowder

	thumb_func_start sub_80246AC
sub_80246AC: @ 80246AC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	cmp r0, r4
	bcc _080246CC
	movs r0, 0x1
	b _080246CE
	.pool
_080246CC:
	movs r0, 0
_080246CE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80246AC

	thumb_func_start sub_80246D4
sub_80246D4: @ 80246D4
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	cmp r0, r1
	bcc _080246F8
	movs r0, 0x1
	b _080246FA
	.pool
_080246F8:
	movs r0, 0
_080246FA:
	pop {r1}
	bx r1
	thumb_func_end sub_80246D4

	thumb_func_start sub_8024700
sub_8024700: @ 8024700
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r5, r0, r1
	adds r0, r5, 0
	bl sub_8024668
	adds r1, r0, r4
	ldr r2, =0x0001869f
	cmp r1, r2
	bhi _08024730
	adds r0, r5, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _0802473A
	.pool
_08024730:
	adds r0, r5, 0
	adds r1, r2, 0
	bl SetBerryPowder
	movs r0, 0
_0802473A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024700

	thumb_func_start sub_8024740
sub_8024740: @ 8024740
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r4, r0, r1
	adds r0, r5, 0
	bl sub_80246AC
	lsls r0, 24
	cmp r0, 0
	beq _08024774
	adds r0, r4, 0
	bl sub_8024668
	adds r1, r0, 0
	subs r1, r5
	adds r0, r4, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _08024776
	.pool
_08024774:
	movs r0, 0
_08024776:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024740

	thumb_func_start sub_802477C
sub_802477C: @ 802477C
	push {r4,r5,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r4, r0, r1
	ldr r5, =gSpecialVar_0x8004
	ldrh r0, [r5]
	bl sub_80246AC
	lsls r0, 24
	cmp r0, 0
	beq _080247B4
	adds r0, r4, 0
	bl sub_8024668
	adds r1, r0, 0
	ldrh r0, [r5]
	subs r1, r0
	adds r0, r4, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _080247B6
	.pool
_080247B4:
	movs r0, 0
_080247B6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802477C

	thumb_func_start sub_80247BC
sub_80247BC: @ 80247BC
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80247BC

	thumb_func_start sub_80247D4
sub_80247D4: @ 80247D4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x24]
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gStringVar1
	mov r9, r0
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	mov r2, r9
	mov r3, r8
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80247D4

	thumb_func_start sub_802482C
sub_802482C: @ 802482C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r8, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl SetWindowBorderStyle
	ldr r2, =gText_Powder
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	str r4, [sp]
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0x1A
	movs r3, 0x11
	bl sub_80247D4
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802482C

	thumb_func_start sub_802488C
sub_802488C: @ 802488C
	push {lr}
	sub sp, 0x4
	bl sub_80247BC
	adds r1, r0, 0
	ldr r0, =gUnknown_02022C94
	ldrb r0, [r0]
	movs r2, 0
	str r2, [sp]
	movs r2, 0x1A
	movs r3, 0x11
	bl sub_80247D4
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802488C

	thumb_func_start sub_80248B0
sub_80248B0: @ 80248B0
	push {r4,r5,lr}
	sub sp, 0x18
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x1C
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl SetWindowTemplateFields
	ldr r4, =gUnknown_02022C94
	add r0, sp, 0x10
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	ldr r5, =0x0000021d
	adds r1, r5, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r4, [r4]
	bl sub_80247BC
	adds r3, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD
	bl sub_802482C
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80248B0

	thumb_func_start sub_8024918
sub_8024918: @ 8024918
	push {r4,lr}
	ldr r4, =gUnknown_02022C94
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024918

	thumb_func_start sub_802493C
sub_802493C: @ 802493C
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, =gUnknown_03000DB0
	movs r0, 0
	str r0, [r1]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _08024A10
	ldr r4, =gUnknown_02022C98
	ldr r0, =0x00003330
	bl AllocZeroed
	str r0, [r4]
	cmp r0, 0
	beq _08024A10
	bl sub_8024A1C
	ldr r0, [r4]
	bl sub_8024A30
	ldr r0, [r4]
	str r5, [r0]
	bl GetMultiplayerId
	ldr r1, [r4]
	adds r1, 0x28
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x000032cc
	adds r0, r1, r2
	adds r2, r1, 0
	adds r2, 0x28
	ldrb r3, [r2]
	lsls r2, r3, 4
	subs r2, r3
	lsls r2, 2
	adds r1, r2
	ldr r2, =0x000031a0
	adds r1, r2
	movs r2, 0x3C
	bl memcpy
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x28
	ldrb r1, [r1]
	lsls r1, 2
	ldr r2, =0x0000318c
	adds r1, r2
	adds r0, r1
	movs r1, 0x64
	muls r1, r6
	ldr r2, =gPlayerParty
	adds r1, r2
	bl sub_80261F8
	ldr r0, =sub_8024BC8
	movs r1, 0x1
	bl CreateTask
	ldr r0, =sub_80261CC
	bl SetMainCallback2
	bl sub_80273F0
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x24
	ldrb r0, [r0]
	adds r1, r2, 0
	adds r1, 0x44
	adds r2, 0x48
	bl sub_8026B5C
	bl StopMapMusic
	ldr r0, =0x0000021e
	bl PlayNewMapMusic
	b _08024A16
	.pool
_08024A10:
	adds r0, r5, 0
	bl SetMainCallback2
_08024A16:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802493C

	thumb_func_start sub_8024A1C
sub_8024A1C: @ 8024A1C
	push {lr}
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	pop {r0}
	bx r0
	thumb_func_end sub_8024A1C

	thumb_func_start sub_8024A30
sub_8024A30: @ 8024A30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r2, r0, 0
	movs r0, 0
	strb r0, [r2, 0xC]
	strb r0, [r2, 0x10]
	strb r0, [r2, 0x14]
	strb r0, [r2, 0x18]
	strb r0, [r2, 0x1C]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	str r0, [r1]
	movs r7, 0x90
	lsls r7, 1
	adds r1, r2, r7
	str r0, [r1]
	adds r1, r2, 0
	adds r1, 0x30
	strb r0, [r1]
	adds r1, 0x10
	strb r0, [r1]
	subs r1, 0x4
	strb r0, [r1]
	adds r3, 0x10
	adds r1, r2, r3
	str r0, [r1]
	movs r5, 0
	adds r1, r2, 0
	adds r1, 0x98
	movs r3, 0
_08024A76:
	adds r0, r1, r5
	strb r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08024A76
	movs r5, 0
	adds r7, r2, 0
	adds r7, 0xA8
	str r7, [sp]
	adds r0, r2, 0
	adds r0, 0xB0
	str r0, [sp, 0xC]
	movs r1, 0x4A
	adds r1, r2
	mov r10, r1
	movs r3, 0x4C
	adds r3, r2
	mov r9, r3
	movs r7, 0x4E
	adds r7, r2
	mov r12, r7
	subs r0, 0x60
	str r0, [sp, 0x24]
	adds r6, r2, 0
	adds r6, 0x54
	adds r1, r2, 0
	adds r1, 0xD0
	str r1, [sp, 0x1C]
	adds r3, r2, 0
	adds r3, 0xDC
	str r3, [sp, 0x20]
	adds r7, r2, 0
	adds r7, 0xC4
	str r7, [sp, 0x14]
	adds r0, 0xA4
	str r0, [sp, 0x4]
	adds r1, 0x25
	str r1, [sp, 0x8]
	subs r3, 0xBC
	str r3, [sp, 0x10]
	movs r7, 0x24
	adds r7, r2
	mov r8, r7
	subs r0, 0xC0
	str r0, [sp, 0x18]
	movs r3, 0
	movs r1, 0x86
	lsls r1, 1
	adds r4, r2, r1
	movs r7, 0x98
	lsls r7, 1
	adds r2, r7
_08024AE2:
	ldr r1, [sp]
	adds r0, r1, r5
	strb r3, [r0]
	ldr r7, [sp, 0xC]
	adds r0, r7, r5
	strb r3, [r0]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	mov r7, r10
	adds r1, r7, r0
	strh r3, [r1]
	mov r7, r9
	adds r1, r7, r0
	strh r3, [r1]
	mov r7, r12
	adds r1, r7, r0
	strh r3, [r1]
	ldr r7, [sp, 0x24]
	adds r1, r7, r0
	strh r3, [r1]
	adds r0, r6, r0
	strh r3, [r0]
	adds r0, r4, r5
	strb r3, [r0]
	lsls r0, r5, 2
	adds r0, r2, r0
	str r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08024AE2
	movs r5, 0
	movs r3, 0
	movs r4, 0xFF
	ldr r6, [sp, 0x1C]
_08024B2C:
	adds r0, r6, r5
	strb r3, [r0]
	ldr r1, [sp, 0x20]
	adds r0, r1, r5
	strb r3, [r0]
	ldr r7, [sp, 0x14]
	adds r0, r7, r5
	strb r3, [r0]
	lsls r1, r5, 1
	ldr r0, [sp, 0x4]
	adds r2, r0, r1
	ldrb r0, [r2]
	orrs r0, r4
	strb r0, [r2]
	ldr r7, [sp, 0x8]
	adds r1, r7, r1
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08024B2C
	bl GetMultiplayerId
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08024B6A
	movs r1, 0x1
_08024B6A:
	ldr r0, [sp, 0x10]
	strb r1, [r0]
	bl GetLinkPlayerCount
	mov r1, r8
	strb r0, [r1]
	bl GetMultiplayerId
	ldr r3, [sp, 0x18]
	strb r0, [r3]
	movs r5, 0x1
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bcs _08024BB6
	ldr r7, [sp, 0x18]
	mov r6, r8
_08024B8C:
	adds r4, r7, r5
	subs r0, r5, 0x1
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r0, 0x1
	strb r0, [r4]
	ldrb r2, [r4]
	ldrb r1, [r6]
	subs r0, r1, 0x1
	cmp r2, r0
	ble _08024BAA
	adds r0, r2, 0
	bl __umodsi3
	strb r0, [r4]
_08024BAA:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6]
	cmp r5, r0
	bcc _08024B8C
_08024BB6:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8024A30

	thumb_func_start sub_8024BC8
sub_8024BC8: @ 8024BC8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0x7
	bls _08024BDC
	b _08024D34
_08024BDC:
	lsls r0, 2
	ldr r1, =_08024BF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024BF0:
	.4byte _08024C10
	.4byte _08024C24
	.4byte _08024C4C
	.4byte _08024C5A
	.4byte _08024C80
	.4byte _08024CD4
	.4byte _08024CE6
	.4byte _08024D10
_08024C10:
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_8025910
	movs r1, 0x4
	bl sub_802620C
	b _08024D20
	.pool
_08024C24:
	ldr r0, =sub_8025910
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _08024C32
	b _08024D40
_08024C32:
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r1
	bl sub_8029274
	ldr r1, [r4]
	b _08024D24
	.pool
_08024C4C:
	bl sub_802A770
	cmp r0, 0
	bne _08024D40
	bl sub_8010434
	b _08024D20
_08024C5A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024D40
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _08024D20
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl CreateWirelessStatusIndicatorSprite
	b _08024D20
	.pool
_08024C80:
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	bl sub_80283A8
	movs r4, 0
	cmp r4, r5
	bcs _08024CBA
_08024C92:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x34
	adds r0, r4
	ldrb r2, [r0]
	lsls r0, r2, 2
	ldr r3, =0x0000318c
	adds r0, r3
	adds r0, r1, r0
	adds r1, 0x24
	ldrb r3, [r1]
	adds r1, r4, 0
	bl sub_8028408
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08024C92
_08024CBA:
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	adds r0, 0x24
	ldrb r1, [r0]
	movs r0, 0
	bl sub_802868C
	ldr r1, [r4]
	b _08024D24
	.pool
_08024CD4:
	bl sub_8028A34
	bl sub_8028A88
	bl sub_8028D44
	bl sub_8028734
	b _08024D20
_08024CE6:
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_80261E4
	bl SetVBlankCallback
	b _08024D20
	.pool
_08024D10:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08024D40
_08024D20:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
_08024D24:
	ldrb r0, [r1, 0xC]
	adds r0, 0x1
	strb r0, [r1, 0xC]
	b _08024D40
	.pool
_08024D34:
	adds r0, r1, 0
	bl DestroyTask
	ldr r0, =sub_802589C
	bl sub_802621C
_08024D40:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024BC8

	thumb_func_start sub_8024D4C
sub_8024D4C: @ 8024D4C
	push {lr}
	bl sub_8025D04
	ldr r1, =gUnknown_082F7AC4
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	ldrb r0, [r0, 0x18]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_03000DB0
	ldr r0, [r0]
	cmp r0, 0
	bne _08024D70
	bl sub_8026AF4
_08024D70:
	bl sub_8025D50
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024D4C

	thumb_func_start sub_8024D84
sub_8024D84: @ 8024D84
	push {lr}
	bl sub_8025E0C
	ldr r1, =gUnknown_082F7AF4
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	ldrb r0, [r0, 0x18]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_03000DB0
	ldr r0, [r0]
	cmp r0, 0
	bne _08024DA8
	bl sub_8026B28
_08024DA8:
	bl sub_8025ED8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024D84

	thumb_func_start sub_8024DBC
sub_8024DBC: @ 8024DBC
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	beq _08024DD4
	cmp r0, 0x1
	beq _08024DEA
	b _08024DF8
	.pool
_08024DD4:
	movs r0, 0x1
	bl sub_8028504
	movs r0, 0x1
	bl sub_80292E0
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08024DF8
_08024DEA:
	bl sub_802A770
	cmp r0, 0
	bne _08024DF8
	movs r0, 0x1
	bl sub_8026240
_08024DF8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8024DBC

	thumb_func_start sub_8024E00
sub_8024E00: @ 8024E00
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	bne _08024E20
	bl sub_80262C0
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08024E30
	.pool
_08024E20:
	movs r0, 0x8C
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	str r0, [r1]
	movs r0, 0x2
	bl sub_8026240
_08024E30:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8024E00

	thumb_func_start sub_8024E38
sub_8024E38: @ 8024E38
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _08024F08
	lsls r0, 2
	ldr r1, =_08024E5C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024E5C:
	.4byte _08024E74
	.4byte _08024E90
	.4byte _08024EA0
	.4byte _08024EC4
	.4byte _08024ED8
	.4byte _08024EF8
_08024E74:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	movs r1, 0x8
	movs r2, 0x78
	movs r3, 0x50
	bl sub_802EB24
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08024EF0
	.pool
_08024E90:
	bl sub_8010434
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08024EF0
	.pool
_08024EA0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024F08
	ldr r2, =gUnknown_02022C98
	ldr r1, [r2]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	movs r3, 0
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	adds r0, 0x30
	strb r3, [r0]
	b _08024F08
	.pool
_08024EC4:
	bl sub_802EB84
	cmp r0, 0
	bne _08024F08
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08024EF0
	.pool
_08024ED8:
	ldr r1, [r4]
	adds r1, 0x30
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _08024F08
	bl sub_8010434
	ldr r1, [r4]
_08024EF0:
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08024F08
_08024EF8:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024F08
	movs r0, 0x3
	bl sub_8026240
_08024F08:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8024E38

	thumb_func_start sub_8024F10
sub_8024F10: @ 8024F10
	push {lr}
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	bne _08024F2E
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _08024F2E
	movs r0, 0x4
	bl sub_8026240
_08024F2E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024F10

	thumb_func_start sub_8024F38
sub_8024F38: @ 8024F38
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r2, [r4]
	ldrb r0, [r2, 0x10]
	cmp r0, 0
	bne _08024FF6
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _08024FE8
	adds r0, r2, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0
	bne _08024FEE
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08024F88
	ldr r1, =0x000031cc
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, 0
	bne _08024FEE
	ldr r3, =0x000031d0
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, 0x2
	b _08024FC2
	.pool
_08024F88:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08024FA8
	ldr r3, =0x000031cc
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, 0
	bne _08024FEE
	adds r3, 0x4
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, 0x1
	b _08024FC2
	.pool
_08024FA8:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08024FD4
	ldr r3, =0x000031cc
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, 0
	bne _08024FEE
	adds r3, 0x4
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, 0x3
_08024FC2:
	bl sub_8027518
	ldr r1, [r4]
	ldr r2, =0x000031cc
	adds r1, r2
	strb r0, [r1]
	b _08024FEE
	.pool
_08024FD4:
	movs r0, 0
	bl sub_8027518
	ldr r1, [r4]
	ldr r3, =0x000031cc
	adds r1, r3
	strb r0, [r1]
	b _08024FEE
	.pool
_08024FE8:
	movs r0, 0xB
	bl sub_8026240
_08024FEE:
	bl sub_802671C
	bl sub_8025F48
_08024FF6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8024F38

	thumb_func_start sub_8024FFC
sub_8024FFC: @ 8024FFC
	push {lr}
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _080250C4
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0802504C
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r2, r0
	ldr r1, =0x000031cc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080250CA
	ldr r3, =0x000032f8
	adds r1, r2, r3
	movs r0, 0x2
	strb r0, [r1]
	b _080250CA
	.pool
_0802504C:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08025080
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r2, r0
	ldr r1, =0x000031cc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080250CA
	ldr r3, =0x000032f8
	adds r1, r2, r3
	movs r0, 0x1
	strb r0, [r1]
	b _080250CA
	.pool
_08025080:
	movs r0, 0x20
	ands r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080250B8
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r2, r0
	ldr r1, =0x000031cc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080250CA
	ldr r3, =0x000032f8
	adds r1, r2, r3
	movs r0, 0x3
	strb r0, [r1]
	b _080250CA
	.pool
_080250B8:
	ldr r3, =0x000032f8
	adds r0, r2, r3
	strb r1, [r0]
	b _080250CA
	.pool
_080250C4:
	movs r0, 0xB
	bl sub_8026240
_080250CA:
	bl sub_8026044
	pop {r0}
	bx r0
	thumb_func_end sub_8024FFC

	thumb_func_start sub_80250D4
sub_80250D4: @ 80250D4
	push {r4,r5,lr}
	bl sub_802671C
	bl sub_8025F48
	bl sub_8026C50
	cmp r0, 0x1
	bne _080250F2
	bl sub_80272A4
	movs r0, 0x5
	bl sub_8026240
	b _08025150
_080250F2:
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	movs r1, 0x96
	lsls r1, 1
	adds r4, r2, r1
	movs r1, 0x1
	str r1, [r4]
	movs r3, 0x1
	adds r1, r2, 0
	adds r1, 0x24
	adds r5, r0, 0
	ldrb r1, [r1]
	cmp r3, r1
	bcs _08025150
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _08025124
	movs r0, 0
	str r0, [r4]
	b _08025150
	.pool
_08025124:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r3, r0
	bcs _08025150
	lsls r0, r3, 2
	movs r4, 0x98
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0x1
	beq _08025124
	movs r0, 0x96
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0
	str r0, [r1]
_08025150:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80250D4

	thumb_func_start sub_8025158
sub_8025158: @ 8025158
	push {lr}
	bl sub_8026044
	bl sub_8026C90
	cmp r0, 0x1
	bne _0802516C
	movs r0, 0x5
	bl sub_8026240
_0802516C:
	pop {r0}
	bx r0
	thumb_func_end sub_8025158

	thumb_func_start sub_8025170
sub_8025170: @ 8025170
	push {r4,lr}
	bl GetBlockReceivedStatus
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_800A9D8
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0802518C
	movs r0, 0
	b _08025192
_0802518C:
	bl ResetBlockReceivedFlags
	movs r0, 0x1
_08025192:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8025170

	thumb_func_start sub_8025198
sub_8025198: @ 8025198
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C98
	ldr r1, [r5]
	ldrb r4, [r1, 0x10]
	cmp r4, 0x1
	beq _080251D0
	cmp r4, 0x1
	bgt _080251B4
	cmp r4, 0
	beq _080251BA
	b _0802520C
	.pool
_080251B4:
	cmp r4, 0x2
	beq _080251DC
	b _0802520C
_080251BA:
	adds r1, 0x4A
	movs r0, 0
	movs r2, 0x3C
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _08025226
	ldr r0, [r5]
	strb r4, [r0, 0x8]
	b _08025202
_080251D0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08025226
	b _08025202
_080251DC:
	bl sub_8025170
	cmp r0, 0
	beq _080251EE
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x24
	ldrb r1, [r1]
	strb r1, [r0, 0x8]
_080251EE:
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r0, [r2, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08025226
	ldrb r0, [r2, 0x14]
	adds r0, 0x1
	strb r0, [r2, 0x14]
_08025202:
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08025226
_0802520C:
	movs r0, 0x1
	bl WaitFanfare
	lsls r0, 24
	cmp r0, 0
	beq _08025226
	movs r0, 0x6
	bl sub_8026240
	ldr r0, =0x0000020b
	movs r1, 0x4
	bl FadeOutAndPlayNewMapMusic
_08025226:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025198

	thumb_func_start sub_8025230
sub_8025230: @ 8025230
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C98
	ldr r2, [r5]
	ldrb r4, [r2, 0x10]
	cmp r4, 0x1
	beq _08025274
	cmp r4, 0x1
	bgt _0802524C
	cmp r4, 0
	beq _08025252
	b _080252DC
	.pool
_0802524C:
	cmp r4, 0x2
	beq _08025282
	b _080252DC
_08025252:
	ldrb r0, [r2, 0x14]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, 0x4A
	adds r1, r2, r1
	movs r0, 0
	movs r2, 0x3C
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _08025316
	ldr r0, [r5]
	strb r4, [r0, 0x8]
	ldr r1, [r5]
	b _080252CC
_08025274:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08025316
	ldr r1, [r5]
	b _080252CC
_08025282:
	bl sub_8025170
	cmp r0, 0
	beq _080252B4
	movs r4, 0
	b _080252AA
_0802528E:
	ldr r0, [r5]
	adds r0, 0x4A
	ldr r1, =gBlockRecvBuffer
	movs r2, 0x3C
	bl memcpy
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080252AA:
	ldr r0, [r5]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r4, r0
	bcc _0802528E
_080252B4:
	ldr r3, =gUnknown_02022C98
	ldr r2, [r3]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r0, [r2, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08025316
	ldrb r0, [r2, 0x14]
	adds r0, 0x1
	strb r0, [r2, 0x14]
	ldr r1, [r3]
_080252CC:
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08025316
	.pool
_080252DC:
	movs r0, 0x1
	bl WaitFanfare
	lsls r0, 24
	cmp r0, 0
	beq _08025316
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x54
	adds r0, r1
	ldrh r1, [r0]
	movs r3, 0x8A
	lsls r3, 1
	adds r0, r2, r3
	strh r1, [r0]
	movs r0, 0x6
	bl sub_8026240
	ldr r0, =0x0000020b
	movs r1, 0x4
	bl FadeOutAndPlayNewMapMusic
_08025316:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025230

	thumb_func_start sub_8025324
sub_8025324: @ 8025324
	push {r4,r5,lr}
	sub sp, 0x4
	movs r1, 0x1
	mov r0, sp
	strb r1, [r0]
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x4
	bls _0802533A
	b _08025458
_0802533A:
	lsls r0, 2
	ldr r1, =_0802534C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802534C:
	.4byte _08025360
	.4byte _08025384
	.4byte _0802539C
	.4byte _080253BC
	.4byte _080253DC
_08025360:
	bl sub_802749C
	movs r0, 0x1
	bl sub_80289E8
	bl sub_8028DFC
	movs r0, 0x1
	bl sub_8028EC8
	movs r0, 0x2
	bl sub_80292E0
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08025448
	.pool
_08025384:
	bl sub_802A770
	cmp r0, 0
	bne _08025466
	movs r0, 0x5
	bl sub_80292E0
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08025448
	.pool
_0802539C:
	bl sub_802A794
	mov r1, sp
	strb r0, [r1]
	movs r0, 0
	movs r2, 0x1
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _08025466
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08025448
	.pool
_080253BC:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08025466
	ldr r3, =gUnknown_02022C98
	ldr r1, [r3]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1, 0x10]
	ldr r0, [r3]
	strb r2, [r0, 0x8]
	b _08025466
	.pool
_080253DC:
	bl sub_8025170
	cmp r0, 0
	beq _08025422
	movs r2, 0
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08025422
	adds r3, r1, 0
	movs r5, 0x86
	lsls r5, 1
	ldr r4, =gBlockRecvBuffer
_080253FA:
	ldr r1, [r3]
	adds r1, r2, r1
	adds r1, r5
	lsls r0, r2, 8
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r3]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcc _080253FA
_08025422:
	ldr r4, =gUnknown_02022C98
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r0, [r2, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08025466
	ldrb r0, [r2, 0x14]
	adds r0, 0x1
	strb r0, [r2, 0x14]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x77
	bls _08025466
	movs r0, 0x6
	bl sub_80292E0
	ldr r1, [r4]
_08025448:
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08025466
	.pool
_08025458:
	bl sub_802A770
	cmp r0, 0
	bne _08025466
	movs r0, 0x7
	bl sub_8026240
_08025466:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025324

	thumb_func_start sub_8025470
sub_8025470: @ 8025470
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x7
	bls _08025480
	b _08025606
_08025480:
	lsls r0, 2
	ldr r1, =_08025494
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08025494:
	.4byte _080254B4
	.4byte _080254D4
	.4byte _080254F0
	.4byte _08025504
	.4byte _08025520
	.4byte _0802553C
	.4byte _08025564
	.4byte _08025578
_080254B4:
	bl sub_8027748
	ldr r1, =0x00000bb7
	cmp r0, r1
	bls _080254C4
	movs r0, 0x4
	bl sub_80292E0
_080254C4:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_080254D4:
	bl sub_802A770
	cmp r0, 0
	beq _080254DE
	b _0802563C
_080254DE:
	movs r0, 0x3
	bl sub_80292E0
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_080254F0:
	bl sub_8028FCC
	bl sub_80272E8
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_08025504:
	bl sub_802A794
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	cmp r0, 0
	bne _08025516
	b _0802563C
_08025516:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_08025520:
	bl sub_802A770
	cmp r0, 0
	beq _0802552A
	b _0802563C
_0802552A:
	movs r0, 0x5
	bl sub_80292E0
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_0802553C:
	bl sub_802A794
	mov r1, sp
	strb r0, [r1]
	movs r0, 0
	movs r2, 0x1
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0802563C
	ldr r2, =gUnknown_02022C98
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x8]
	ldr r1, [r2]
	b _080255E8
	.pool
_08025564:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802563C
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _080255E8
	.pool
_08025578:
	bl sub_8025170
	cmp r0, 0
	beq _080255BE
	movs r2, 0
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcs _080255BE
	adds r3, r1, 0
	movs r5, 0x86
	lsls r5, 1
	ldr r4, =gBlockRecvBuffer
_08025596:
	ldr r1, [r3]
	adds r1, r2, r1
	adds r1, r5
	lsls r0, r2, 8
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r3]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08025596
_080255BE:
	ldr r4, =gUnknown_02022C98
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r0, [r2, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080255F8
	ldrb r0, [r2, 0x14]
	adds r0, 0x1
	strb r0, [r2, 0x14]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x77
	bls _0802563C
	bl sub_8027608
	movs r0, 0x6
	bl sub_80292E0
	ldr r1, [r4]
_080255E8:
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _0802563C
	.pool
_080255F8:
	bl sub_8027554
	b _0802563C
_080255FE:
	movs r0, 0x8
	bl sub_8026240
	b _0802563C
_08025606:
	bl sub_802A770
	cmp r0, 0
	bne _0802563C
	movs r2, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08025636
	movs r4, 0x86
	lsls r4, 1
	adds r3, r1, r4
	adds r1, r0, 0
_08025624:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _080255FE
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r1
	bcc _08025624
_08025636:
	movs r0, 0xA
	bl sub_8026240
_0802563C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025470

	thumb_func_start sub_8025644
sub_8025644: @ 8025644
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	beq _08025672
	cmp r0, 0x1
	bgt _08025660
	cmp r0, 0
	beq _08025666
	b _08025692
	.pool
_08025660:
	cmp r0, 0x2
	beq _0802567C
	b _08025692
_08025666:
	bl sub_800AC34
	movs r0, 0x7
	bl sub_80292E0
	b _08025688
_08025672:
	bl sub_802A770
	cmp r0, 0
	bne _080256A0
	b _08025688
_0802567C:
	bl sub_802A794
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _080256A0
_08025688:
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _080256A0
_08025692:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080256A0
	movs r0, 0x9
	bl sub_8026240
_080256A0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025644

	thumb_func_start sub_80256AC
sub_80256AC: @ 80256AC
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	ldrb r1, [r0, 0x10]
	cmp r1, 0x1
	beq _080256E0
	cmp r1, 0x1
	bgt _080256C8
	cmp r1, 0
	beq _080256CE
	b _08025728
	.pool
_080256C8:
	cmp r1, 0x2
	beq _080256F8
	b _08025728
_080256CE:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0802571A
_080256E0:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0802574C
	b _0802571A
	.pool
_080256F8:
	bl sub_8028B80
	bl sub_80287E4
	ldr r0, [r4]
	adds r0, 0x24
	ldrb r0, [r0]
	bl sub_8028614
	bl sub_8028E84
	ldr r1, =gUnknown_03000DB0
	movs r0, 0x1
	str r0, [r1]
	movs r0, 0x8
	bl sub_80292E0
_0802571A:
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _0802574C
	.pool
_08025728:
	bl sub_802A770
	cmp r0, 0
	bne _0802574C
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl DestroyTask
	ldr r0, [r4]
	bl Free
	bl FreeAllWindowBuffers
_0802574C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80256AC

	thumb_func_start sub_8025758
sub_8025758: @ 8025758
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	cmp r0, 0x6
	bls _08025768
	b _0802585C
_08025768:
	lsls r0, 2
	ldr r1, =_0802577C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802577C:
	.4byte _08025798
	.4byte _08025838
	.4byte _080257B0
	.4byte _08025802
	.4byte _08025808
	.4byte _08025818
	.4byte _08025838
_08025798:
	movs r0, 0x9
	bl sub_80292E0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08025848
_080257B0:
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
	b _08025848
_08025802:
	bl StopMapMusic
	b _08025848
_08025808:
	ldr r0, =0x0000021e
	bl PlayNewMapMusic
	bl sub_8028E4C
	b _08025848
	.pool
_08025818:
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _08025848
_08025838:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0802588C
_08025848:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _0802588C
	.pool
_0802585C:
	ldrb r0, [r1, 0x4]
	bl DestroyTask
	ldr r0, =sub_802589C
	bl sub_802621C
	bl sub_802903C
	ldr r0, [r4]
	bl sub_8024A30
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _08025882
	ldr r0, [r4]
	adds r0, 0x24
	movs r1, 0x1
	strb r1, [r0]
_08025882:
	bl sub_80273F0
	movs r0, 0
	bl sub_8028EC8
_0802588C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025758

	thumb_func_start sub_802589C
sub_802589C: @ 802589C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	adds r4, r1, 0
	cmp r0, 0x1
	beq _080258C8
	cmp r0, 0x1
	bgt _080258BC
	cmp r0, 0
	beq _080258C2
	b _080258E0
	.pool
_080258BC:
	cmp r0, 0x2
	beq _080258CE
	b _080258E0
_080258C2:
	bl sub_8026264
	b _080258D2
_080258C8:
	bl sub_80286E4
	b _080258D6
_080258CE:
	bl sub_8028828
_080258D2:
	cmp r0, 0x1
	bne _08025904
_080258D6:
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	b _08025904
_080258E0:
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080258F8
	ldr r0, =sub_8024D4C
	bl sub_802621C
	b _080258FE
	.pool
_080258F8:
	ldr r0, =sub_8024D84
	bl sub_802621C
_080258FE:
	adds r0, r5, 0
	bl DestroyTask
_08025904:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802589C

	thumb_func_start sub_8025910
sub_8025910: @ 8025910
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0
	ldrsh r4, [r5, r0]
	cmp r4, 0x1
	beq _0802596C
	cmp r4, 0x1
	bgt _08025938
	cmp r4, 0
	beq _0802593E
	b _080259E8
	.pool
_08025938:
	cmp r4, 0x2
	beq _0802597E
	b _080259E8
_0802593E:
	ldr r6, =gUnknown_02022C98
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 2
	ldr r2, =0x0000318c
	adds r0, r2
	adds r1, r0
	movs r0, 0
	movs r2, 0x1
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _080259E8
	ldr r0, [r6]
	strb r4, [r0, 0x8]
	b _08025976
	.pool
_0802596C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080259E8
_08025976:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _080259E8
_0802597E:
	bl sub_8025170
	cmp r0, 0
	beq _080259C4
	movs r2, 0
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcs _080259C4
	adds r3, r1, 0
	ldr r5, =gBlockRecvBuffer
	ldr r4, =0x0000318c
_0802599A:
	ldr r0, [r3]
	lsls r1, r2, 2
	adds r1, r0
	adds r1, r4
	lsls r0, r2, 8
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	strb r0, [r1, 0x8]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r3]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0802599A
_080259C4:
	ldr r4, =gUnknown_02022C98
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x24
	ldrb r0, [r0, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080259E8
	adds r0, r6, 0
	bl DestroyTask
	movs r0, 0x6
	bl sub_80292E0
	ldr r1, [r4]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
_080259E8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025910

	thumb_func_start sub_80259FC
sub_80259FC: @ 80259FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r6, =gUnknown_02022C98
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x24
	ldrb r7, [r1]
	ldr r2, =0x000031a0
	adds r1, r0, r2
	ldr r3, =0x000031cc
	adds r2, r0, r3
	ldr r4, =0x00003208
	adds r3, r0, r4
	ldr r5, =0x00003244
	adds r4, r0, r5
	str r4, [sp]
	adds r5, 0x3C
	adds r4, r0, r5
	str r4, [sp, 0x4]
	adds r5, 0x3C
	adds r4, r0, r5
	str r4, [sp, 0x8]
	adds r4, r0, 0
	adds r4, 0x40
	str r4, [sp, 0xC]
	movs r5, 0x90
	lsls r5, 1
	adds r4, r0, r5
	str r4, [sp, 0x10]
	movs r4, 0x96
	lsls r4, 1
	adds r0, r4
	str r0, [sp, 0x14]
	movs r0, 0
	bl sub_8028164
	ldr r1, [r6]
	ldr r5, =0x000031b0
	adds r2, r1, r5
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	movs r5, 0x1
	cmp r5, r7
	bcs _08025AA4
_08025A60:
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xA8
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _08025A9A
	lsls r0, r5, 4
	subs r0, r5
	lsls r4, r0, 2
	adds r1, r4, r1
	ldr r2, =0x000031cc
	adds r1, r2
	adds r0, r5, 0
	bl sub_8028318
	adds r1, r0, 0
	cmp r1, 0
	bne _08025A9A
	ldr r0, [r6]
	adds r0, r4
	ldr r3, =0x000031cc
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	movs r4, 0x94
	lsls r4, 1
	adds r0, r4
	strb r1, [r0]
_08025A9A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _08025A60
_08025AA4:
	ldr r5, =gUnknown_02022C98
	ldr r1, [r5]
	movs r6, 0x92
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _08025B02
	ldr r1, [r5]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r1, r2
	ldrb r4, [r0]
	cmp r4, 0
	beq _08025AF0
	bl sub_8011AC8
	ldr r0, [r5]
	adds r0, r6
	movs r1, 0
	strb r1, [r0]
	b _08025B02
	.pool
_08025AF0:
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0x46
	bls _08025B02
	bl sub_8011AC8
	ldr r0, [r5]
	adds r0, r6
	strb r4, [r0]
_08025B02:
	movs r5, 0
	cmp r5, r7
	bcs _08025BF6
	ldr r3, =0x000031cc
	mov r12, r3
	ldr r4, =gUnknown_02022C98
	mov r8, r4
_08025B10:
	mov r6, r8
	ldr r2, [r6]
	lsls r0, r5, 4
	subs r1, r0, r5
	lsls r1, 2
	adds r1, r2, r1
	add r1, r12
	ldrb r1, [r1]
	adds r6, r0, 0
	cmp r1, 0
	beq _08025B36
	adds r0, r2, 0
	adds r0, 0xA8
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0
	bne _08025B36
	movs r0, 0x1
	strb r0, [r1]
_08025B36:
	adds r3, r4, 0
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0xA8
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x3
	bgt _08025B54
	cmp r0, 0x1
	bge _08025B5A
	b _08025BEC
	.pool
_08025B54:
	cmp r0, 0x4
	beq _08025BA8
	b _08025BEC
_08025B5A:
	adds r1, 0xB0
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _08025BEC
	ldr r0, [r3]
	adds r0, 0xB0
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, 0xA8
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r3]
	subs r1, r6, r5
	lsls r1, 2
	adds r0, r1
	add r0, r12
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r1
	ldr r6, =0x000031d0
	adds r0, r6
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r1
	ldr r1, =0x000031d4
	adds r0, r1
	b _08025BEA
	.pool
_08025BA8:
	adds r1, 0xB0
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x27
	bls _08025BEC
	ldr r0, [r4]
	adds r0, 0xB0
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xA8
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r4]
	subs r1, r6, r5
	lsls r1, 2
	adds r0, r1
	add r0, r12
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	ldr r3, =0x000031d0
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	ldr r6, =0x000031d4
	adds r0, r6
_08025BEA:
	strb r2, [r0]
_08025BEC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _08025B10
_08025BF6:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80259FC

	thumb_func_start sub_8025C0C
sub_8025C0C: @ 8025C0C
	push {r4-r7,lr}
	sub sp, 0x18
	ldr r5, =gUnknown_02022C98
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x24
	ldrb r6, [r1]
	ldr r2, =0x000031a0
	adds r1, r0, r2
	ldr r3, =0x000031cc
	adds r2, r0, r3
	ldr r4, =0x00003208
	adds r3, r0, r4
	ldr r7, =0x00003244
	adds r4, r0, r7
	str r4, [sp]
	adds r7, 0x3C
	adds r4, r0, r7
	str r4, [sp, 0x4]
	adds r7, 0x3C
	adds r4, r0, r7
	str r4, [sp, 0x8]
	adds r4, r0, 0
	adds r4, 0x40
	str r4, [sp, 0xC]
	movs r7, 0x90
	lsls r7, 1
	adds r4, r0, r7
	str r4, [sp, 0x10]
	movs r4, 0x96
	lsls r4, 1
	adds r0, r4
	str r0, [sp, 0x14]
	movs r0, 0
	bl sub_8028164
	ldr r1, [r5]
	ldr r7, =0x000031b0
	adds r2, r1, r7
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0x1
	cmp r4, r6
	bcs _08025C9C
_08025C6C:
	adds r0, r4, 0
	bl sub_8028374
	cmp r0, 0
	beq _08025C92
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	lsls r1, r4, 2
	movs r3, 0x98
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	movs r7, 0x94
	lsls r7, 1
	adds r1, r2, r7
	movs r0, 0
	strb r0, [r1]
_08025C92:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _08025C6C
_08025C9C:
	ldr r5, =gUnknown_02022C98
	ldr r1, [r5]
	movs r6, 0x92
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _08025CFA
	ldr r1, [r5]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r1, r2
	ldrb r4, [r0]
	cmp r4, 0
	beq _08025CE8
	bl sub_8011AC8
	ldr r0, [r5]
	adds r0, r6
	movs r1, 0
	strb r1, [r0]
	b _08025CFA
	.pool
_08025CE8:
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0x46
	bls _08025CFA
	bl sub_8011AC8
	ldr r0, [r5]
	adds r0, r6
	strb r4, [r0]
_08025CFA:
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8025C0C

	thumb_func_start sub_8025D04
sub_8025D04: @ 8025D04
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C98
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	cmp r0, 0x4
	beq _08025D40
	cmp r0, 0x4
	bgt _08025D20
	cmp r0, 0x3
	beq _08025D26
	b _08025D4A
	.pool
_08025D20:
	cmp r0, 0xB
	beq _08025D46
	b _08025D4A
_08025D26:
	bl sub_8026BB8
	adds r4, r0, 0
	cmp r4, 0x1
	bne _08025D4A
	bl sub_8026C28
	ldr r0, [r5]
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r1
	str r4, [r0]
	b _08025D4A
_08025D40:
	bl sub_80259FC
	b _08025D4A
_08025D46:
	bl sub_8025C0C
_08025D4A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025D04

	thumb_func_start sub_8025D50
sub_8025D50: @ 8025D50
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_02022C98
	ldr r5, [r0]
	ldrb r0, [r5, 0x18]
	cmp r0, 0x4
	beq _08025D68
	cmp r0, 0xB
	beq _08025DB8
	b _08025DF4
	.pool
_08025D68:
	ldr r1, =0x000032cc
	adds r0, r5, r1
	ldr r2, =0x000031cc
	adds r1, r5, r2
	ldr r3, =0x00003208
	adds r2, r5, r3
	ldr r4, =0x00003244
	adds r3, r5, r4
	movs r6, 0xCA
	lsls r6, 6
	adds r4, r5, r6
	str r4, [sp]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x4]
	adds r4, r5, 0
	adds r4, 0x40
	ldrb r4, [r4]
	str r4, [sp, 0x8]
	movs r6, 0x90
	lsls r6, 1
	adds r4, r5, r6
	ldr r4, [r4]
	str r4, [sp, 0xC]
	adds r6, 0xC
	adds r4, r5, r6
	ldr r4, [r4]
	str r4, [sp, 0x10]
	bl sub_8027E30
	b _08025DF4
	.pool
_08025DB8:
	ldr r1, =0x000032cc
	adds r0, r5, r1
	ldr r2, =0x000031cc
	adds r1, r5, r2
	ldr r3, =0x00003208
	adds r2, r5, r3
	ldr r4, =0x00003244
	adds r3, r5, r4
	movs r6, 0xCA
	lsls r6, 6
	adds r4, r5, r6
	str r4, [sp]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x4]
	adds r4, r5, 0
	adds r4, 0x40
	ldrb r4, [r4]
	str r4, [sp, 0x8]
	movs r6, 0x90
	lsls r6, 1
	adds r4, r5, r6
	ldr r4, [r4]
	str r4, [sp, 0xC]
	adds r6, 0xC
	adds r4, r5, r6
	ldr r4, [r4]
	str r4, [sp, 0x10]
	bl sub_8027E30
_08025DF4:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025D50

	thumb_func_start sub_8025E0C
sub_8025E0C: @ 8025E0C
	push {r4-r6,lr}
	sub sp, 0x18
	ldr r0, =gUnknown_02022C98
	ldr r5, [r0]
	ldrb r0, [r5, 0x18]
	cmp r0, 0x4
	beq _08025E24
	cmp r0, 0xB
	beq _08025E7C
	b _08025EC0
	.pool
_08025E24:
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 2
	ldr r2, =0x000031a0
	adds r1, r2
	adds r1, r5, r1
	ldr r3, =0x000031cc
	adds r2, r5, r3
	ldr r4, =0x00003208
	adds r3, r5, r4
	ldr r6, =0x00003244
	adds r4, r5, r6
	str r4, [sp]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x4]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x8]
	adds r4, r5, 0
	adds r4, 0x40
	str r4, [sp, 0xC]
	movs r6, 0x90
	lsls r6, 1
	adds r4, r5, r6
	str r4, [sp, 0x10]
	adds r6, 0xC
	adds r4, r5, r6
	str r4, [sp, 0x14]
	bl sub_8028164
	b _08025EC0
	.pool
_08025E7C:
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 2
	ldr r2, =0x000031a0
	adds r1, r2
	adds r1, r5, r1
	ldr r3, =0x000031cc
	adds r2, r5, r3
	ldr r4, =0x00003208
	adds r3, r5, r4
	ldr r6, =0x00003244
	adds r4, r5, r6
	str r4, [sp]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x4]
	adds r6, 0x3C
	adds r4, r5, r6
	str r4, [sp, 0x8]
	adds r4, r5, 0
	adds r4, 0x40
	str r4, [sp, 0xC]
	movs r6, 0x90
	lsls r6, 1
	adds r4, r5, r6
	str r4, [sp, 0x10]
	adds r6, 0xC
	adds r4, r5, r6
	str r4, [sp, 0x14]
	bl sub_8028164
_08025EC0:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8025E0C

	thumb_func_start sub_8025ED8
sub_8025ED8: @ 8025ED8
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0x4
	beq _08025F0E
	cmp r0, 0x4
	bgt _08025EF4
	cmp r0, 0x3
	beq _08025EFA
	b _08025F40
	.pool
_08025EF4:
	cmp r0, 0xB
	beq _08025F24
	b _08025F40
_08025EFA:
	movs r0, 0x1
	bl sub_8027DD0
	ldr r0, [r4]
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	b _08025F40
_08025F0E:
	ldr r2, =0x000032f8
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08025F40
	bl sub_80282EC
	b _08025F40
	.pool
_08025F24:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _08025F40
	adds r2, 0xC
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _08025F40
	movs r0, 0x1
	bl sub_8028350
_08025F40:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025ED8

	thumb_func_start sub_8025F48
sub_8025F48: @ 8025F48
	push {r4-r6,lr}
	ldr r6, =gUnknown_02022C98
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r1, r2, r0
	ldr r3, =0x000031cc
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08025F88
	bl IsSEPlaying
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08025FEA
	ldr r0, [r6]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	b _08025FEA
	.pool
_08025F88:
	ldr r3, =0x000031d0
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _08025FB8
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08025FEA
	movs r0, 0x1F
	bl m4aSongNumStop
	movs r0, 0x1F
	bl PlaySE
	ldr r0, [r6]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r2
	b _08025FE8
	.pool
_08025FB8:
	ldr r3, =0x000031d4
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _08025FEA
	movs r5, 0xA2
	lsls r5, 1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _08025FEA
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _08025FEA
	movs r0, 0x16
	bl PlaySE
	movs r0, 0x1
	bl sub_80284CC
	ldr r0, [r6]
	adds r0, r5
_08025FE8:
	strb r4, [r0]
_08025FEA:
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r2, r5
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, 0
	bne _0802601C
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _0802601C
	bl StopMapMusic
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	b _0802603A
	.pool
_0802601C:
	ldr r0, [r4]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0802603C
	movs r0, 0xB
	bl PlayFanfareByFanfareNum
	ldr r0, [r4]
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	movs r1, 0x2
_0802603A:
	strb r1, [r0]
_0802603C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8025F48

	thumb_func_start sub_8026044
sub_8026044: @ 8026044
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r6, =gUnknown_02022C98
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x44
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r2, 0
	adds r0, 0x48
	ldrb r7, [r0]
	subs r0, 0x20
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r1, r2, r0
	ldr r3, =0x000031cc
	adds r0, r1, r3
	ldrb r3, [r0]
	cmp r3, 0
	bne _0802609C
	ldr r4, =0x000031d0
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080260FE
	adds r4, 0x4
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080260FE
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	strb r3, [r0]
	b _080260FE
	.pool
_0802609C:
	ldr r3, =0x000031d0
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _080260CC
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080260FE
	movs r0, 0x1F
	bl m4aSongNumStop
	movs r0, 0x1F
	bl PlaySE
	ldr r0, [r6]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r3
	b _080260FC
	.pool
_080260CC:
	ldr r4, =0x000031d4
	adds r0, r1, r4
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _080260FE
	movs r5, 0xA2
	lsls r5, 1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080260FE
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	bne _080260FE
	movs r0, 0x16
	bl PlaySE
	movs r0, 0x1
	bl sub_80284CC
	ldr r0, [r6]
	adds r0, r5
_080260FC:
	strb r4, [r0]
_080260FE:
	mov r4, r8
	cmp r4, r7
	bcs _08026172
	ldr r5, =gUnknown_02022C98
_08026106:
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	ldr r1, =0x000031a0
	adds r0, r1
	adds r0, r2, r0
	adds r1, r0, 0
	adds r1, 0x14
	adds r0, 0x1F
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _0802615C
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026168
	adds r0, r1, r4
	ldrb r0, [r0]
	adds r0, 0x4A
	bl PlaySE
	ldr r0, [r5]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	adds r0, r4
	movs r1, 0x1
	b _08026166
	.pool
_0802615C:
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r4
	movs r1, 0
_08026166:
	strb r1, [r0]
_08026168:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r7
	bcc _08026106
_08026172:
	ldr r0, =gUnknown_02022C98
	ldr r2, [r0]
	movs r5, 0xAA
	lsls r5, 1
	adds r1, r2, r5
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, 0
	bne _080261A0
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _080261A0
	bl StopMapMusic
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	b _080261BE
	.pool
_080261A0:
	ldr r0, [r4]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080261C0
	movs r0, 0xB
	bl PlayFanfareByFanfareNum
	ldr r0, [r4]
	movs r3, 0xAA
	lsls r3, 1
	adds r0, r3
	movs r1, 0x2
_080261BE:
	strb r1, [r0]
_080261C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8026044

	thumb_func_start sub_80261CC
sub_80261CC: @ 80261CC
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_80261CC

	thumb_func_start sub_80261E4
sub_80261E4: @ 80261E4
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	thumb_func_end sub_80261E4

	thumb_func_start sub_80261F8
sub_80261F8: @ 80261F8
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl IsMonShiny
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80261F8

	thumb_func_start sub_802620C
sub_802620C: @ 802620C
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	bl CreateTask
	pop {r0}
	bx r0
	thumb_func_end sub_802620C

	thumb_func_start sub_802621C
sub_802621C: @ 802621C
	push {lr}
	movs r1, 0x1
	bl CreateTask
	ldr r1, =gUnknown_02022C98
	ldr r3, [r1]
	movs r2, 0
	strb r0, [r3, 0x4]
	ldr r0, [r1]
	strb r2, [r0, 0x10]
	ldr r0, [r1]
	strb r2, [r0, 0xC]
	ldr r0, [r1]
	strb r2, [r0, 0x14]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802621C

	thumb_func_start sub_8026240
sub_8026240: @ 8026240
	push {r4,lr}
	ldr r2, =gUnknown_02022C98
	ldr r1, [r2]
	ldrb r3, [r1, 0x18]
	movs r4, 0
	strb r3, [r1, 0x1C]
	ldr r1, [r2]
	strb r0, [r1, 0x18]
	ldr r0, [r2]
	strb r4, [r0, 0x10]
	ldr r0, [r2]
	strb r4, [r0, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026240

	thumb_func_start sub_8026264
sub_8026264: @ 8026264
	push {r4,lr}
	ldr r3, =gUnknown_02022C98
	ldr r1, [r3]
	ldrb r0, [r1, 0x14]
	lsrs r2, r0, 2
	adds r0, 0x1
	strb r0, [r1, 0x14]
	cmp r2, 0
	beq _080262B8
	ldr r3, [r3]
	ldrb r0, [r3, 0x14]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080262B8
	ldr r1, =gUnknown_082F7A94
	adds r0, r3, 0
	adds r0, 0x24
	ldrb r0, [r0]
	subs r0, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bcc _080262A0
	movs r0, 0x1
	b _080262BA
	.pool
_080262A0:
	lsls r4, r2, 3
	adds r1, r4, 0
	movs r0, 0x14
	bl SetGpuReg
	negs r4, r4
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x18
	adds r1, r4, 0
	bl SetGpuReg
_080262B8:
	movs r0, 0
_080262BA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026264

	thumb_func_start sub_80262C0
sub_80262C0: @ 80262C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gUnknown_02022C98
	ldr r0, [r2]
	adds r1, r0, 0
	adds r1, 0x44
	adds r0, 0x48
	ldrb r5, [r0]
	ldrb r1, [r1]
	cmp r1, r5
	bcs _0802630C
	mov r8, r2
	ldr r0, =0x000032e0
	mov r12, r0
	movs r7, 0
	movs r6, 0x1
_080262E2:
	mov r2, r8
	ldr r0, [r2]
	mov r2, r12
	adds r4, r0, r2
	ldr r2, =0x000032eb
	adds r0, r2
	adds r2, r0, r1
	movs r3, 0
	adds r0, r1, 0
	ands r0, r6
	cmp r0, 0
	bne _080262FC
	movs r3, 0x1
_080262FC:
	strb r3, [r2]
	adds r0, r4, r1
	strb r7, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r5
	bcc _080262E2
_0802630C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80262C0

	thumb_func_start sub_8026324
sub_8026324: @ 8026324
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r1, 0
	adds r0, 0x48
	ldrb r0, [r0]
	str r0, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _08026358
	b _08026614
_08026358:
	movs r6, 0
	ldr r0, [sp, 0x8]
	cmp r6, r0
	bcs _08026440
_08026360:
	ldr r3, =gUnknown_02022C98
	lsls r0, r6, 4
	subs r1, r0, r6
	lsls r1, 2
	ldr r2, [r3]
	adds r1, r2
	ldr r4, =0x000031cc
	adds r4, r1
	mov r8, r4
	ldrb r1, [r4]
	mov r9, r0
	adds r0, r6, 0x1
	str r0, [sp, 0xC]
	cmp r1, 0
	beq _08026434
	adds r0, r2, 0
	adds r0, 0xA8
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08026434
	ldr r1, [sp]
	mov r10, r1
	ldr r2, [sp, 0x4]
	cmp r10, r2
	bcs _08026434
	adds r7, r3, 0
_08026396:
	ldr r0, =gUnknown_082F449C
	add r0, r10
	ldrb r5, [r0]
	ldr r1, [r7]
	lsls r4, r5, 1
	adds r0, r1, 0
	adds r0, 0xF4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _08026434
	adds r0, r1, 0
	adds r0, 0xF5
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _08026434
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r2, r5, 0
	bl sub_8026634
	cmp r0, 0x1
	bne _08026410
	movs r2, 0
	ldr r3, =gUnknown_02022C98
	mov r8, r4
_080263CE:
	ldr r0, [r3]
	mov r4, r8
	adds r1, r2, r4
	adds r0, 0xF4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _08026404
	strb r6, [r1]
	ldr r0, [r3]
	adds r0, 0xA8
	adds r0, r6
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0xC4
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	b _08026434
	.pool
_08026404:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bls _080263CE
	b _08026434
_08026410:
	ldr r0, [r7]
	mov r2, r9
	subs r1, r2, r6
	lsls r1, 2
	adds r0, r1
	ldr r4, =0x000031d4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08026434
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, [sp, 0x4]
	cmp r10, r0
	bcc _08026396
_08026434:
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	lsrs r6, r0, 24
	ldr r2, [sp, 0x8]
	cmp r6, r2
	bcc _08026360
_08026440:
	ldr r4, [sp]
	mov r10, r4
	ldr r0, [sp, 0x4]
	cmp r10, r0
	bcc _0802644C
	b _08026614
_0802644C:
	ldr r1, =gUnknown_02022C98
	mov r9, r1
_08026450:
	movs r6, 0xFF
	ldr r0, =gUnknown_082F449C
	add r0, r10
	ldrb r5, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, 0xC4
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08026468
	b _08026602
_08026468:
	adds r0, r5, 0
	bl sub_8026D8C
	mov r1, r9
	ldr r4, [r1]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r1, 0x90
	adds r1, r0
	ldrb r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _0802648E
	movs r3, 0x2
_0802648E:
	ldr r2, =gUnknown_082F7A88
	ldr r0, =0x000031b4
	adds r1, r4, r0
	adds r1, r5
	lsls r0, r3, 1
	adds r0, r3
	ldrb r1, [r1]
	adds r0, r1
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0xD0
	adds r0, r5
	ldrb r0, [r0]
	subs r2, r1, r0
	cmp r2, 0x5
	bgt _080264BC
	adds r1, r4, 0
	adds r1, 0x9C
	adds r1, r5
	ldrb r0, [r1]
	adds r0, r2
	strb r0, [r1]
_080264BC:
	mov r2, r9
	ldr r1, [r2]
	adds r1, 0x9C
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	movs r4, 0xFF
	ands r0, r4
	cmp r0, 0x5
	bhi _080264D6
	b _08026602
_080264D6:
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x9C
	adds r0, r5
	strb r2, [r0]
	ldr r3, [r1]
	lsls r1, r5, 1
	adds r0, r3, 0
	adds r0, 0xF4
	adds r2, r0, r1
	ldrb r0, [r2]
	mov r8, r1
	cmp r0, 0xFF
	bne _08026518
	adds r0, r3, 0
	adds r0, 0xF5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08026500
	b _08026602
_08026500:
	b _08026528
	.pool
_08026518:
	adds r0, r3, 0
	adds r0, 0xF5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08026528
	ldrb r4, [r2]
	b _0802654E
_08026528:
	mov r2, r9
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0xF4
	add r0, r8
	ldrb r7, [r0]
	adds r1, 0xF5
	add r1, r8
	ldrb r6, [r1]
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _0802654A
	adds r4, r7, 0
	b _0802654E
_0802654A:
	adds r4, r6, 0
	adds r6, r7, 0
_0802654E:
	mov r1, r9
	ldr r0, [r1]
	ldr r2, =0x000032eb
	adds r0, r2
	adds r0, r5
	movs r1, 0x7
	strb r1, [r0]
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xC4
	adds r0, r5
	movs r1, 0x2
	strb r1, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, 0xA8
	adds r0, r4
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xB8
	adds r0, r5
	strb r4, [r0]
	ldr r1, [r2]
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 2
	adds r1, r0
	ldr r2, =0x000031d0
	adds r1, r2
	movs r0, 0x1
	strb r0, [r1]
	mov r2, r9
	ldr r1, [r2]
	lsls r0, r6, 4
	subs r0, r6
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000031d4
	adds r1, r0
	movs r2, 0x1
	strb r2, [r1]
	mov r0, r9
	ldr r1, [r0]
	lsls r0, r4, 1
	adds r1, 0x86
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8026F1C
	movs r0, 0x1
	bl sub_8027234
	adds r0, r4, 0
	bl sub_8026D1C
	mov r1, r9
	ldr r0, [r1]
	adds r1, r0, 0
	adds r1, 0xE8
	adds r1, r5
	ldr r2, =0x000032e0
	adds r0, r2
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	mov r4, r9
	ldr r0, [r4]
	adds r0, r2
	adds r0, r5
	movs r1, 0x3
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0xF4
	add r1, r8
	ldrb r0, [r1]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, 0xF5
	add r1, r8
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_08026602:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, [sp, 0x4]
	cmp r10, r4
	bcs _08026614
	b _08026450
_08026614:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026324

	thumb_func_start sub_8026634
sub_8026634: @ 8026634
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r7, 0
	ldr r2, =gUnknown_02022C98
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =0x000032e0
	adds r1, r0
	mov r12, r2
	cmp r3, 0x2
	beq _08026670
	cmp r3, 0x2
	bgt _08026676
	cmp r3, 0x1
	beq _08026674
	b _08026676
	.pool
_08026670:
	movs r7, 0x1
	b _08026676
_08026674:
	movs r7, 0x2
_08026676:
	adds r0, r1, 0
	adds r0, 0xB
	adds r0, r6
	ldrb r0, [r0]
	subs r0, 0x6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080266D4
	ldr r0, =gUnknown_082F449C+0x113
	lsls r1, r4, 1
	adds r1, r4
	adds r1, r7, r1
	lsls r2, r5, 4
	subs r2, r5
	adds r1, r2
	adds r1, r0
	ldrb r1, [r1]
	cmp r6, r1
	bne _0802670A
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xC4
	adds r0, r6
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080266D0
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 2
	adds r0, r1, r0
	ldr r1, =0x000031d4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _0802670A
	.pool
_080266D0:
	movs r0, 0x1
	b _0802670C
_080266D4:
	ldr r0, =gUnknown_082F449C+0x113
	lsls r1, r4, 1
	adds r1, r4
	adds r1, r7, r1
	lsls r2, r5, 4
	subs r2, r5
	adds r1, r2
	adds r1, r0
	ldrb r1, [r1]
	cmp r6, r1
	bne _0802670A
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xA8
	adds r0, r4
	movs r1, 0x4
	strb r1, [r0]
	mov r0, r12
	ldr r1, [r0]
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000031d4
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_0802670A:
	movs r0, 0
_0802670C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8026634

	thumb_func_start sub_802671C
sub_802671C: @ 802671C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gUnknown_02022C98
	ldr r4, [r2]
	adds r0, r4, 0
	adds r0, 0x44
	ldrb r1, [r0]
	adds r0, 0x4
	ldrb r0, [r0]
	mov r9, r0
	movs r3, 0
	mov r10, r3
	movs r5, 0x90
	lsls r5, 1
	adds r0, r4, r5
	str r3, [r0]
	adds r5, r1, 0
	mov r0, r9
	subs r0, 0x1
	cmp r5, r0
	blt _0802674E
	b _08026974
_0802674E:
	mov r8, r2
_08026750:
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, 0
	adds r0, 0xC4
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08026762
	b _0802686C
_08026762:
	movs r1, 0x90
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0x1
	str r2, [r0]
	ldr r1, =0x000032eb
	adds r0, r4, r1
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, 0x9
	bls _080267FC
	movs r7, 0
	movs r0, 0xA
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xC4
	adds r0, r5
	movs r1, 0x3
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0
	bne _080267AC
	strb r2, [r1]
	ldr r2, =0x000032e0
	adds r0, r4, r2
	adds r0, r5
	ldrb r0, [r0]
	adds r0, 0x4A
	bl PlaySE
_080267AC:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _080267C2
	mov r2, r10
	cmp r2, 0x1
	beq _080267C2
	b _08026964
_080267C2:
	movs r0, 0x1
	mov r10, r0
	adds r0, r1, r6
	adds r0, r5
	strb r7, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r1, r0, 0
	adds r1, 0x40
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _080267DE
	adds r0, 0x1
	strb r0, [r1]
_080267DE:
	movs r0, 0x3
	adds r1, r5, 0
	movs r2, 0
	bl sub_8026F1C
	movs r0, 0
	bl sub_8027234
	b _08026964
	.pool
_080267FC:
	adds r0, r5, 0
	bl sub_8026D8C
	mov r2, r8
	ldr r7, [r2]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r7, 0
	adds r1, 0x90
	adds r1, r0
	ldrb r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08026822
	movs r3, 0x2
_08026822:
	ldr r2, =gUnknown_082F7A88
	ldr r0, =0x000032e0
	adds r1, r4, r0
	adds r1, r5
	lsls r0, r3, 1
	adds r0, r3
	ldrb r1, [r1]
	adds r0, r1
	adds r0, r2
	ldrb r2, [r0]
	adds r1, r7, 0
	adds r1, 0xD0
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r3, 0
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r2
	bcc _0802685C
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xD0
	adds r0, r5
	strb r3, [r0]
_0802685C:
	bl sub_8026324
	b _08026964
	.pool
_0802686C:
	cmp r0, 0x2
	bne _080268F4
	movs r2, 0x90
	lsls r2, 1
	adds r0, r4, r2
	movs r6, 0x1
	str r6, [r0]
	adds r1, r4, 0
	adds r1, 0xDC
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r3, 0
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _08026964
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xB8
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r1, =0x000031d0
	adds r2, r1
	strb r3, [r2]
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xDC
	adds r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, 0xD0
	adds r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, 0xC4
	adds r0, r5
	strb r3, [r0]
	ldr r1, =0x000032eb
	adds r0, r4, r1
	adds r0, r5
	strb r6, [r0]
	adds r0, r5, 0
	bl sub_8026D8C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	bl sub_8026DB0
	ldr r2, =0x000032e0
	adds r1, r4, r2
	adds r1, r5
	strb r0, [r1]
	b _08026964
	.pool
_080268F4:
	cmp r0, 0x3
	bne _08026964
	adds r1, r4, 0
	adds r1, 0xDC
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _08026964
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bhi _08026964
	adds r0, r1, 0
	adds r0, 0xDC
	adds r0, r5
	strb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xD0
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, 0xC4
	adds r0, r5
	strb r2, [r0]
	ldr r2, =0x000032eb
	adds r0, r4, r2
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0xE8
	adds r1, r5
	subs r2, 0xB
	adds r4, r2
	adds r4, r5
	ldrb r0, [r4]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8026D8C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r5, 0
	bl sub_8026DB0
	strb r0, [r4]
_08026964:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r9
	subs r0, 0x1
	cmp r5, r0
	bge _08026974
	b _08026750
_08026974:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802671C

	thumb_func_start sub_8026988
sub_8026988: @ 8026988
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x44
	adds r0, 0x48
	ldrb r0, [r0]
	mov r8, r0
	ldrb r6, [r1]
	cmp r6, r8
	bcs _08026A7A
	ldr r0, =gUnknown_082F449C
	mov r9, r0
_080269A8:
	ldr r0, =gUnknown_02022C98
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	ldr r2, =0x000031a0
	adds r0, r2
	adds r7, r3, r0
	movs r0, 0xB
	adds r2, r1, 0
	muls r2, r0
	adds r2, r6, r2
	adds r3, 0x24
	ldrb r1, [r3]
	subs r1, 0x1
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	adds r2, r0
	add r2, r9
	ldrb r4, [r2]
	adds r0, r7, 0
	adds r0, 0x1F
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080269FC
	adds r0, r6, 0
	movs r1, 0
	bl sub_8028BF8
	b _08026A04
	.pool
_080269FC:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8028BF8
_08026A04:
	adds r0, r7, 0
	adds r0, 0x1F
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, 0x9
	bls _08026A30
	adds r0, r7, 0
	adds r0, 0x14
	adds r0, r4
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	movs r0, 0xFF
	lsls r0, 24
	adds r1, r0
	b _08026A52
_08026A30:
	adds r0, r7, 0
	adds r0, 0x14
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, 0x3
	bne _08026A5C
	movs r0, 0x7
	strb r0, [r5]
	adds r0, r6, 0
	movs r1, 0x6
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	movs r2, 0xFF
	lsls r2, 24
	adds r1, r2
_08026A52:
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028C7C
	b _08026A70
_08026A5C:
	ldrb r1, [r3]
	adds r0, r6, 0
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028C7C
_08026A70:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r8
	bcc _080269A8
_08026A7A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8026988

	thumb_func_start sub_8026A88
sub_8026A88: @ 8026A88
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _08026ABA
	adds r6, r1, 0
_08026A9A:
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 2
	ldr r1, [r6]
	adds r0, r1
	ldr r1, =0x000031cc
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_80286B4
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026A9A
_08026ABA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026A88

	thumb_func_start sub_8026AC8
sub_8026AC8: @ 8026AC8
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _08026AEA
_08026AD8:
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80286B4
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026AD8
_08026AEA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026AC8

	thumb_func_start sub_8026AF4
sub_8026AF4: @ 8026AF4
	push {lr}
	bl sub_8026988
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _08026B10
	bl sub_8026AC8
	b _08026B14
	.pool
_08026B10:
	bl sub_8026A88
_08026B14:
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	bl sub_80288D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026AF4

	thumb_func_start sub_8026B28
sub_8026B28: @ 8026B28
	push {lr}
	bl sub_8026988
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _08026B44
	bl sub_8026AC8
	b _08026B48
	.pool
_08026B44:
	bl sub_8026A88
_08026B48:
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	bl sub_80288D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026B28

	thumb_func_start sub_8026B5C
sub_8026B5C: @ 8026B5C
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x4
	bhi _08026BB4
	lsls r0, 2
	ldr r1, =_08026B78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026B78:
	.4byte _08026B8C
	.4byte _08026B94
	.4byte _08026B9C
	.4byte _08026BA4
	.4byte _08026BAC
_08026B8C:
	movs r0, 0x4
	strb r0, [r3]
	movs r0, 0x7
	b _08026BB2
_08026B94:
	movs r0, 0x3
	strb r0, [r3]
	movs r0, 0x8
	b _08026BB2
_08026B9C:
	movs r0, 0x2
	strb r0, [r3]
	movs r0, 0x9
	b _08026BB2
_08026BA4:
	movs r0, 0x1
	strb r0, [r3]
	movs r0, 0xA
	b _08026BB2
_08026BAC:
	movs r0, 0
	strb r0, [r3]
	movs r0, 0xB
_08026BB2:
	strb r0, [r2]
_08026BB4:
	pop {r0}
	bx r0
	thumb_func_end sub_8026B5C

	thumb_func_start sub_8026BB8
sub_8026BB8: @ 8026BB8
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0x1
	cmp r4, r5
	bcs _08026C1E
	adds r6, r1, 0
_08026BCA:
	ldr r0, [r6]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026BEC
	adds r0, r4, 0
	bl sub_8027DFC
	ldr r1, [r6]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_08026BEC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026BCA
	cmp r4, r5
	bcs _08026C1E
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r0, r2
_08026C04:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026C14
	movs r0, 0
	b _08026C20
	.pool
_08026C14:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026C04
_08026C1E:
	movs r0, 0x1
_08026C20:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026BB8

	thumb_func_start sub_8026C28
sub_8026C28: @ 8026C28
	push {r4,lr}
	movs r1, 0
	ldr r4, =gUnknown_02022C98
	movs r3, 0xAC
	lsls r3, 1
	movs r2, 0
_08026C34:
	ldr r0, [r4]
	adds r0, r3
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _08026C34
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026C28

	thumb_func_start sub_8026C50
sub_8026C50: @ 8026C50
	push {r4,lr}
	ldr r3, =gUnknown_02022C98
	ldr r1, [r3]
	adds r2, r1, 0
	adds r2, 0x40
	ldrb r0, [r2]
	cmp r0, 0x9
	bls _08026C88
	movs r4, 0x90
	lsls r4, 1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, 0
	bne _08026C88
	movs r0, 0xA
	strb r0, [r2]
	ldr r0, [r3]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _08026C88
	movs r0, 0x1
	b _08026C8A
	.pool
_08026C88:
	movs r0, 0
_08026C8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026C50

	thumb_func_start sub_8026C90
sub_8026C90: @ 8026C90
	push {r4-r6,lr}
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0x40
	ldrb r0, [r2]
	cmp r0, 0x9
	bls _08026D14
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r3, [r0]
	adds r0, 0x4
	ldrb r5, [r0]
	movs r0, 0xA
	strb r0, [r2]
	ldr r4, [r4]
	mov r12, r4
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	beq _08026D14
	adds r4, r3, 0
	cmp r4, r5
	bcs _08026D04
	mov r0, r12
	adds r0, 0x28
	ldrb r3, [r0]
	lsls r1, r3, 4
	subs r1, r3
	lsls r1, 2
	ldr r6, =gUnknown_082F449C
	subs r0, 0x4
	ldrb r2, [r0]
	subs r2, 0x1
	add r1, r12
	movs r0, 0xB
	muls r3, r0
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 3
	subs r2, r0, r2
	ldr r0, =0x000031bf
	adds r1, r0
_08026CEA:
	adds r0, r4, r3
	adds r0, r2
	adds r0, r6
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _08026D14
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026CEA
_08026D04:
	movs r0, 0x1
	b _08026D16
	.pool
_08026D14:
	movs r0, 0
_08026D16:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026C90

	thumb_func_start sub_8026D1C
sub_8026D1C: @ 8026D1C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_082F7A9C
	mov r8, r0
	ldr r0, =gUnknown_02022C98
	ldr r6, [r0]
	adds r0, r6, 0
	adds r0, 0x90
	adds r0, r5
	mov r9, r0
	ldrb r7, [r0]
	adds r0, r7, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	add r4, r8
	adds r0, r7, 0
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldrb r4, [r4]
	adds r0, r4
	lsls r0, 24
	lsls r5, 1
	adds r6, 0x86
	adds r6, r5
	ldrh r1, [r6]
	lsrs r0, 24
	cmp r1, r0
	bcc _08026D76
	adds r0, r7, 0x1
	mov r1, r9
	strb r0, [r1]
_08026D76:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026D1C

	thumb_func_start sub_8026D8C
sub_8026D8C: @ 8026D8C
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_082F449C+0x1AC
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x24
	ldrb r1, [r1]
	subs r1, 0x1
	movs r2, 0xB
	muls r1, r2
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8026D8C

	thumb_func_start sub_8026DB0
sub_8026DB0: @ 8026DB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	adds r1, 0x24
	ldrb r2, [r1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_082F449C+0x15E
	lsls r1, r0, 1
	adds r1, r0
	lsls r0, r2, 4
	subs r0, r2
	adds r1, r0
	adds r0, r1, r3
	ldrb r0, [r0]
	mov r12, r0
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r7, [r0]
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	mov r8, r1
	movs r3, 0
	ldr r1, =gUnknown_082F449C+0x1E3
	lsls r0, r2, 2
	adds r2, r0, r2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08026E18
	adds r6, r1, 0
_08026DFE:
	adds r0, r3, r2
	adds r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	beq _08026E3C
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r3, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026DFE
_08026E18:
	ldr r0, [r4]
	adds r0, 0x90
	mov r1, r12
	adds r2, r0, r1
	adds r1, r0, r7
	ldrb r0, [r2]
	ldrb r3, [r1]
	cmp r0, r3
	bls _08026E46
	adds r1, r0, 0
	b _08026E48
	.pool
_08026E3C:
	ldr r0, [r4]
	adds r0, 0x90
	adds r0, r7
	ldrb r0, [r0]
	b _08026E5A
_08026E46:
	ldrb r1, [r1]
_08026E48:
	ldr r0, [r4]
	adds r0, 0x90
	mov r2, r8
	adds r4, r0, r2
	ldrb r0, [r4]
	cmp r0, r1
	bls _08026E58
	adds r1, r0, 0
_08026E58:
	adds r0, r1, 0
_08026E5A:
	adds r1, r5, 0
	bl sub_8026E70
	lsls r0, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8026DB0

	thumb_func_start sub_8026E70
sub_8026E70: @ 8026E70
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r2, [r2]
	adds r2, 0xE8
	adds r2, r1
	ldrb r4, [r2]
	movs r1, 0x7
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bhi _08026EDE
	lsls r0, 2
	ldr r1, =_08026EA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026EA4:
	.4byte _08026EDE
	.4byte _08026ED6
	.4byte _08026EE2
	.4byte _08026EC0
	.4byte _08026EC6
	.4byte _08026ECC
	.4byte _08026ED2
_08026EC0:
	cmp r4, 0
	beq _08026ED6
	b _08026EDE
_08026EC6:
	cmp r4, 0
	beq _08026EE2
	b _08026EDE
_08026ECC:
	cmp r4, 0x2
	beq _08026ED6
	b _08026EE2
_08026ED2:
	cmp r4, 0
	bne _08026EDA
_08026ED6:
	movs r0, 0x1
	b _08026EE4
_08026EDA:
	cmp r4, 0x1
	beq _08026EE2
_08026EDE:
	movs r0, 0
	b _08026EE4
_08026EE2:
	movs r0, 0x2
_08026EE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026E70

	thumb_func_start sub_8026EEC
sub_8026EEC: @ 8026EEC
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	adds r4, r0, 0
	b _08026EFE
_08026EF6:
	ldrh r0, [r4, 0x6]
	adds r6, r0
	adds r4, 0xC
	adds r5, 0x1
_08026EFE:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _08026EF6
	cmp r6, 0xA
	bgt _08026F12
	movs r0, 0
	b _08026F14
_08026F12:
	movs r0, 0x1
_08026F14:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026EEC

	thumb_func_start sub_8026F1C
sub_8026F1C: @ 8026F1C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r6, =gUnknown_02022C98
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r5, [r0]
	cmp r3, 0
	bge _08026F3A
	b _0802722C
_08026F3A:
	cmp r3, 0x2
	ble _08026F48
	cmp r3, 0x3
	beq _08026F78
	b _0802722C
	.pool
_08026F48:
	ldr r3, =0x000031b4
	adds r0, r1, r3
	adds r0, r4
	ldrb r4, [r0]
	lsls r4, 1
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0
	adds r0, r1, 0
	adds r0, 0x4A
	adds r0, r4
	ldrh r0, [r0]
	ldr r1, =0x00004e20
	bl sub_8027A28
	ldr r1, [r6]
	adds r1, 0x4A
	adds r1, r4
	b _0802722A
	.pool
_08026F78:
	adds r0, r1, 0
	adds r0, 0x4A
	bl sub_8026EEC
	cmp r0, 0
	beq _08026F86
	b _0802722C
_08026F86:
	cmp r5, 0x3
	bne _08026F8C
	b _08027154
_08026F8C:
	cmp r5, 0x3
	bgt _08026F98
	cmp r5, 0x2
	bne _08026F96
	b _080271E8
_08026F96:
	b _0802722C
_08026F98:
	cmp r5, 0x4
	bne _08026F9E
	b _08027090
_08026F9E:
	cmp r5, 0x5
	beq _08026FA4
	b _0802722C
_08026FA4:
	cmp r4, 0x9
	bls _08026FAA
	b _0802722C
_08026FAA:
	lsls r0, r4, 2
	ldr r1, =_08026FB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026FB8:
	.4byte _08026FE0
	.4byte _08026FF8
	.4byte _08027004
	.4byte _0802701C
	.4byte _08027028
	.4byte _08027040
	.4byte _0802704C
	.4byte _08027060
	.4byte _0802706C
	.4byte _08027084
_08026FE0:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x74
	b _08027226
	.pool
_08026FF8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x74
	b _08027226
	.pool
_08027004:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x74
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x80
	b _08027226
	.pool
_0802701C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x80
	b _08027226
	.pool
_08027028:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_08027040:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_0802704C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_08027060:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_0802706C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027084:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_08027090:
	subs r0, r4, 0x1
	cmp r0, 0x7
	bls _08027098
	b _0802722C
_08027098:
	lsls r0, 2
	ldr r1, =_080270A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080270A8:
	.4byte _080270C8
	.4byte _080270E0
	.4byte _080270EC
	.4byte _08027104
	.4byte _08027110
	.4byte _08027124
	.4byte _08027130
	.4byte _08027148
_080270C8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x74
	b _08027226
	.pool
_080270E0:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x74
	b _08027226
	.pool
_080270EC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x74
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_08027104:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_08027110:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_08027124:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_08027130:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027148:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_08027154:
	subs r0, r4, 0x2
	cmp r0, 0x5
	bhi _0802722C
	lsls r0, 2
	ldr r1, =_08027168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08027168:
	.4byte _08027180
	.4byte _08027198
	.4byte _080271A4
	.4byte _080271BC
	.4byte _080271C8
	.4byte _080271DC
_08027180:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027198:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_080271A4:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_080271BC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_080271C8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_080271DC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_080271E8:
	cmp r4, 0x4
	beq _0802720E
	cmp r4, 0x4
	bgt _080271F6
	cmp r4, 0x3
	beq _08027200
	b _0802722C
_080271F6:
	cmp r4, 0x5
	beq _08027214
	cmp r4, 0x6
	beq _08027222
	b _0802722C
_08027200:
	ldr r1, [r6]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
_0802720E:
	ldr r1, [r6]
	adds r1, 0x50
	b _08027226
_08027214:
	ldr r1, [r6]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
_08027222:
	ldr r1, [r6]
_08027224:
	adds r1, 0x5C
_08027226:
	ldrh r0, [r1]
	adds r0, 0x1
_0802722A:
	strh r0, [r1]
_0802722C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8026F1C

	thumb_func_start sub_8027234
sub_8027234: @ 8027234
	push {r4,r5,lr}
	adds r1, r0, 0
	ldr r4, =gUnknown_02022C98
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0802729E
	cmp r1, 0x1
	bne _08027280
	movs r5, 0x89
	lsls r5, 1
	adds r1, r3, r5
	ldrh r0, [r1]
	adds r2, r0, 0x1
	strh r2, [r1]
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r3, r0
	lsls r0, r2, 16
	lsrs r0, 16
	ldrh r3, [r1]
	cmp r0, r3
	bls _08027268
	strh r2, [r1]
_08027268:
	ldr r0, [r4]
	adds r2, r0, r5
	ldrh r0, [r2]
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0802729E
	strh r1, [r2]
	b _0802729E
	.pool
_08027280:
	movs r2, 0x89
	lsls r2, 1
	adds r0, r3, r2
	movs r5, 0x8A
	lsls r5, 1
	adds r1, r3, r5
	ldrh r0, [r0]
	ldrh r3, [r1]
	cmp r0, r3
	bls _08027296
	strh r0, [r1]
_08027296:
	ldr r0, [r4]
	adds r0, r2
	movs r1, 0
	strh r1, [r0]
_0802729E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8027234

	thumb_func_start sub_80272A4
sub_80272A4: @ 80272A4
	push {r4,r5,lr}
	movs r3, 0
	ldr r2, =gUnknown_02022C98
	ldr r0, [r2]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r3, r0
	bcs _080272DC
	adds r5, r2, 0
	movs r4, 0x8A
	lsls r4, 1
_080272BA:
	ldr r2, [r5]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x54
	adds r1, r0
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, 0x24
	ldrb r2, [r2]
	cmp r3, r2
	bcc _080272BA
_080272DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80272A4

	thumb_func_start sub_80272E8
sub_80272E8: @ 80272E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	ldr r7, =gUnknown_02022C98
	movs r4, 0
	ldr r0, =0x000031bf
	mov r10, r0
_080272FC:
	movs r2, 0
	lsls r6, r5, 4
	lsls r1, r5, 1
	mov r8, r1
	lsls r0, r5, 3
	mov r12, r0
	adds r1, r5, 0x1
	mov r9, r1
	subs r0, r6, r5
	lsls r3, r0, 2
_08027310:
	ldr r0, [r7]
	adds r1, r2, r3
	add r0, r10
	adds r0, r1
	strb r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _08027310
	ldr r0, [r7]
	subs r1, r6, r5
	lsls r1, 2
	adds r0, r1
	ldr r2, =0x000031cc
	adds r0, r2
	strb r4, [r0]
	ldr r0, [r7]
	adds r0, r1
	ldr r1, =0x000031d0
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r7]
	adds r0, 0x90
	adds r0, r5
	strb r4, [r0]
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x86
	add r0, r8
	strh r4, [r0]
	add r1, r12
	ldr r2, =0x00003308
	adds r1, r2
	strb r4, [r1]
	ldr r2, [r7]
	ldr r1, =0x0000330c
	adds r0, r2, r1
	add r0, r12
	str r4, [r0]
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x4A
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x4E
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x50
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x52
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r0, r1
	strh r4, [r0]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080272FC
	ldr r2, =gUnknown_02022C98
	ldr r0, [r2]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	strb r2, [r0]
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	movs r1, 0x89
	lsls r1, 1
	adds r3, r0, r1
	movs r1, 0
	strh r2, [r3]
	adds r0, 0x40
	strb r1, [r0]
	bl sub_8026A88
	bl sub_8026988
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80272E8

	thumb_func_start sub_80273F0
sub_80273F0: @ 80273F0
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0802740C
	cmp r0, 0x5
	beq _08027410
	b _08027412
	.pool
_0802740C:
	movs r4, 0x1
	b _08027412
_08027410:
	movs r4, 0x2
_08027412:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	lsls r1, r4, 2
	ldr r5, =gUnknown_02022C98
	ldr r2, =gUnknown_082F7AA4
	adds r1, r4
	lsls r1, 1
	adds r0, r1
	adds r0, r2
	ldrb r2, [r0]
_08027436:
	ldr r1, [r5]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, 0x52
	adds r1, r0
	strh r2, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x4
	bls _08027436
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80273F0

	thumb_func_start sub_802745C
sub_802745C: @ 802745C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r2, [r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x4A
	adds r0, r1
	ldrh r3, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1
	ldrh r0, [r0]
	adds r2, 0x4E
	adds r2, r1
	adds r3, r0
	ldrh r2, [r2]
	adds r0, r3, r2
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0802748E
	adds r0, r1, 0
_0802748E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802745C

	thumb_func_start sub_802749C
sub_802749C: @ 802749C
	push {r4-r6,lr}
	ldr r5, =gUnknown_02022C98
	ldr r0, [r5]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_802745C
	ldr r1, =0x0000270f
	bl sub_8027A38
	adds r4, r0, 0
	ldr r0, [r5]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_80276C0
	ldr r1, =0x000f4236
	bl sub_8027A38
	adds r2, r0, 0
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	movs r6, 0x83
	lsls r6, 2
	adds r1, r0, r6
	ldr r0, [r1]
	cmp r0, r2
	bcs _080274D6
	str r2, [r1]
_080274D6:
	ldr r0, [r3]
	movs r2, 0x84
	lsls r2, 2
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, r4
	bcs _080274E6
	strh r4, [r1]
_080274E6:
	ldr r0, [r3]
	ldr r6, =0x00000212
	adds r2, r0, r6
	ldr r0, [r5]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	ldrh r1, [r0]
	ldrh r0, [r2]
	cmp r0, r1
	bcs _080274FE
	strh r1, [r2]
_080274FE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802749C

	thumb_func_start sub_8027518
sub_8027518: @ 8027518
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x9B
	ldrb r6, [r0]
	movs r3, 0x3
	adds r5, r1, 0
	adds r4, r5, 0
_0802752C:
	ldr r0, [r4]
	adds r0, 0x98
	adds r2, r0, r3
	subs r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r3, 0
	bne _0802752C
	ldr r0, [r5]
	adds r0, 0x98
	strb r7, [r0]
	adds r0, r6, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027518

	thumb_func_start sub_8027554
sub_8027554: @ 8027554
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0x28
	ldrb r1, [r0]
	adds r0, 0x88
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, 0
	bne _080275FC
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08027594
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x2
	b _080275CA
	.pool
_08027594:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080275B0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x3
	b _080275CA
	.pool
_080275B0:
	movs r0, 0x10
	ands r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _080275E8
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x1
_080275CA:
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x28
	adds r0, 0xB0
	ldrb r1, [r1]
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	movs r0, 0xD4
	bl PlaySE
	b _08027600
	.pool
_080275E8:
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	strb r2, [r0]
	b _08027600
	.pool
_080275FC:
	subs r0, 0x1
	strb r0, [r2]
_08027600:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027554

	thumb_func_start sub_8027608
sub_8027608: @ 8027608
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r2, [r0]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000031cc
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8027608

	thumb_func_start sub_802762C
sub_802762C: @ 802762C
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, 0x52
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x85
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_802762C

	thumb_func_start sub_8027650
sub_8027650: @ 8027650
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8027650

	thumb_func_start sub_8027660
sub_8027660: @ 8027660
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802768C
	ldr r0, =gUnknown_02022C98
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 2
	ldr r2, =0x000031a0
	adds r1, r2
	ldr r0, [r0]
	b _08027694
	.pool
_0802768C:
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	ldr r1, =gLinkPlayers + 8
_08027694:
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027660

	thumb_func_start sub_80276A0
sub_80276A0: @ 80276A0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r3, [r2]
	lsrs r1, 23
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r3, 0x4A
	adds r3, r1
	ldrh r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_80276A0

	thumb_func_start sub_80276C0
sub_80276C0: @ 80276C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	movs r3, 0
	ldr r0, =gUnknown_02022C98
	mov r9, r0
	ldr r2, =gUnknown_082F7B24
	mov r10, r2
	ldr r2, [r0]
	lsls r1, r4, 1
	adds r0, r1, r4
	lsls r0, 2
	str r0, [sp]
	adds r6, r2, 0
	adds r6, 0x4A
	mov r12, r1
	mov r8, r10
_080276EE:
	lsls r1, r3, 1
	ldr r7, [sp]
	adds r0, r1, r7
	adds r0, r6, r0
	ldrh r2, [r0]
	add r1, r8
	movs r7, 0
	ldrsh r0, [r1, r7]
	muls r0, r2
	adds r5, r0
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _080276EE
	mov r0, r9
	ldr r1, [r0]
	mov r2, r12
	adds r0, r2, r4
	lsls r0, 2
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	mov r3, r10
	movs r7, 0x6
	ldrsh r0, [r3, r7]
	muls r0, r1
	cmp r5, r0
	bls _08027734
	subs r0, r5, r0
	b _08027736
	.pool
_08027734:
	movs r0, 0
_08027736:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80276C0

	thumb_func_start sub_8027748
sub_8027748: @ 8027748
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r6, [r0]
	movs r0, 0
	bl sub_80276C0
	adds r5, r0, 0
	movs r4, 0x1
	cmp r4, r6
	bcs _08027776
_08027760:
	adds r0, r4, 0
	bl sub_80276C0
	cmp r0, r5
	bls _0802776C
	adds r5, r0, 0
_0802776C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _08027760
_08027776:
	ldr r1, =0x000f4236
	adds r0, r5, 0
	bl sub_8027A38
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027748

	thumb_func_start sub_802778C
sub_802778C: @ 802778C
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r5, [r1]
	lsrs r4, r0, 23
	adds r2, 0x4A
	adds r0, r2, r4
	ldrh r3, [r0]
	movs r1, 0
	cmp r1, r5
	bcs _080277C4
_080277A8:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, r3
	bls _080277BA
	adds r3, r0, 0
_080277BA:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r5
	bcc _080277A8
_080277C4:
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802778C

	thumb_func_start sub_80277D0
sub_80277D0: @ 80277D0
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0x1
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _080277FE
_080277E8:
	adds r0, r4, 0
	bl sub_80276C0
	lsls r1, r4, 2
	add r1, sp
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080277E8
_080277FE:
	lsls r7, 2
	mov r12, r7
	cmp r6, 0
	beq _08027838
	subs r7, r5, 0x1
_08027808:
	movs r6, 0
	movs r4, 0
	cmp r6, r7
	bge _08027834
	adds r5, r7, 0
_08027812:
	lsls r0, r4, 2
	mov r2, sp
	adds r1, r2, r0
	adds r4, 0x1
	lsls r0, r4, 2
	adds r3, r2, r0
	ldr r0, [r1]
	ldr r2, [r3]
	cmp r0, r2
	bcs _0802782C
	str r2, [r1]
	str r0, [r3]
	movs r6, 0x1
_0802782C:
	lsls r0, r4, 24
	lsrs r4, r0, 24
	cmp r4, r5
	blt _08027812
_08027834:
	cmp r6, 0
	bne _08027808
_08027838:
	mov r0, sp
	add r0, r12
	ldr r0, [r0]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80277D0

	thumb_func_start sub_802784C
sub_802784C: @ 802784C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	mov r8, r0
	mov r9, r0
	ldr r6, =gUnknown_02022C98
	ldr r0, [r6]
	adds r0, 0x24
	ldrb r5, [r0]
	bl sub_8027748
	bl sub_8027748
	cmp r0, 0
	bne _080278A0
	movs r4, 0
	cmp r9, r5
	bcs _080278A0
	adds r2, r6, 0
	ldr r1, =0x00003308
	mov r12, r1
	movs r7, 0
	movs r6, 0x4
	ldr r3, =0x0000330c
_08027884:
	ldr r0, [r2]
	lsls r1, r4, 3
	adds r0, r1
	add r0, r12
	strb r6, [r0]
	ldr r0, [r2]
	adds r0, r3
	adds r0, r1
	str r7, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08027884
_080278A0:
	movs r4, 0
	cmp r4, r5
	bcs _080278CA
_080278A6:
	adds r0, r4, 0
	bl sub_80276C0
	ldr r1, =0x000f4236
	bl sub_8027A38
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	lsls r2, r4, 3
	ldr r3, =0x0000330c
	adds r1, r3
	adds r1, r2
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080278A6
_080278CA:
	mov r0, r10
	bl sub_80277D0
	adds r6, r0, 0
	mov r3, r8
	movs r4, 0
	cmp r4, r5
	bcs _08027916
	ldr r7, =gUnknown_02022C98
	mov r10, r7
_080278DE:
	mov r0, r10
	ldr r2, [r0]
	lsls r1, r4, 3
	ldr r7, =0x0000330c
	adds r0, r2, r7
	adds r0, r1
	ldr r0, [r0]
	cmp r6, r0
	bne _0802790C
	adds r0, r2, r1
	ldr r1, =0x00003308
	adds r0, r1
	strb r3, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0802790C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080278DE
_08027916:
	mov r10, r8
	cmp r9, r5
	bcc _080278CA
	movs r0, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802784C

	thumb_func_start sub_802793C
sub_802793C: @ 802793C
	lsls r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r2, [r2]
	lsrs r1, 21
	ldr r3, =0x00003308
	adds r2, r3
	adds r2, r1
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_802793C

	thumb_func_start sub_802795C
sub_802795C: @ 802795C
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl memset
	movs r4, 0
	cmp r7, r5
	bcs _08027994
_0802797E:
	adds r0, r4, 0
	bl sub_80276C0
	lsls r1, r4, 2
	add r1, sp
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0802797E
_08027994:
	lsls r0, r6, 2
	add r0, sp
	ldr r1, [r0]
	movs r4, 0
_0802799C:
	cmp r4, r6
	beq _080279B0
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r1, r0
	bcs _080279B0
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_080279B0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _0802799C
	adds r0, r7, 0
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802795C

	thumb_func_start sub_80279C8
sub_80279C8: @ 80279C8
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x28
	ldrb r4, [r0]
	bl sub_802762C
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, r5, 0
	adds r0, r4, 0
	bl sub_80276C0
	adds r4, r0, 0
	bl sub_8027748
	cmp r4, r0
	beq _080279F4
	movs r0, 0x3
	b _08027A22
	.pool
_080279F4:
	adds r0, r5, 0
	movs r1, 0x1
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	bne _08027A06
	movs r0, 0x2
	b _08027A22
_08027A06:
	adds r0, r6, 0
	movs r1, 0x1
	bl AddBagItem
	adds r0, r6, 0
	movs r1, 0x1
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	beq _08027A20
	movs r0, 0
	b _08027A22
_08027A20:
	movs r0, 0x1
_08027A22:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80279C8

	thumb_func_start sub_8027A28
sub_8027A28: @ 8027A28
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	cmp r2, r0
	bcs _08027A34
	adds r0, r2, 0x1
_08027A34:
	pop {r1}
	bx r1
	thumb_func_end sub_8027A28

	thumb_func_start sub_8027A38
sub_8027A38: @ 8027A38
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	cmp r2, r0
	bcs _08027A44
	adds r0, r2, 0
_08027A44:
	pop {r1}
	bx r1
	thumb_func_end sub_8027A38

	thumb_func_start sub_8027A48
sub_8027A48: @ 8027A48
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x34
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8027A48

	thumb_func_start sub_8027A5C
sub_8027A5C: @ 8027A5C
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gSpecialVar_Result
_08027A62:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _08027A94
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0x55
	bne _08027A94
	movs r0, 0x1
	strh r0, [r6]
	b _08027AA0
	.pool
_08027A94:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08027A62
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_08027AA0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027A5C

	thumb_func_start sub_8027AAC
sub_8027AAC: @ 8027AAC
	push {r4,lr}
	ldr r4, =sub_8027ACC
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027AAC

	thumb_func_start sub_8027ACC
sub_8027ACC: @ 8027ACC
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	beq _08027B94
	cmp r0, 0x1
	bgt _08027AF4
	cmp r0, 0
	beq _08027AFE
	b _08027BE2
	.pool
_08027AF4:
	cmp r0, 0x2
	beq _08027BA0
	cmp r0, 0x3
	beq _08027BC8
	b _08027BE2
_08027AFE:
	ldr r0, =gUnknown_082F7B2C
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gText_BerryPickingRecords
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	movs r6, 0
	ldr r5, =gUnknown_082F7B34
_08027B18:
	ldr r1, [r5]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r0, 0x32
	cmp r0, r4
	ble _08027B2A
	adds r4, r0, 0
_08027B2A:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x2
	bls _08027B18
	adds r0, r4, 0x7
	cmp r0, 0
	bge _08027B3A
	adds r0, 0x7
_08027B3A:
	asrs r4, r0, 3
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08027B46
	adds r4, 0x1
_08027B46:
	movs r1, 0x1E
	subs r1, r4
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r4, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x2]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_8027BEC
	ldrb r0, [r7, 0x2]
	movs r1, 0x3
	b _08027BB6
	.pool
_08027B94:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08027BE2
	b _08027BBA
_08027BA0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08027BE2
	ldrb r0, [r7, 0x2]
	bl rbox_fill_rectangle
	ldrb r0, [r7, 0x2]
	movs r1, 0x1
_08027BB6:
	bl CopyWindowToVram
_08027BBA:
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	b _08027BE2
	.pool
_08027BC8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08027BE2
	ldrb r0, [r7, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_08027BE2:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8027ACC

	thumb_func_start sub_8027BEC
sub_8027BEC: @ 8027BEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r1, [sp, 0x18]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r2, 0x84
	lsls r2, 2
	adds r0, r1, r2
	ldrh r0, [r0]
	str r0, [sp, 0xC]
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [sp, 0x10]
	ldr r0, =0x00000212
	adds r1, r0
	ldrh r0, [r1]
	str r0, [sp, 0x14]
	ldr r4, =0x0000021d
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0xD
	bl sub_8098858
	adds r0, r7, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gText_BerryPickingRecords
	ldr r0, [sp, 0x18]
	lsls r2, r0, 3
	movs r0, 0x1
	adds r1, r4, 0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized
	movs r6, 0
	ldr r2, =gStringVar1
	mov r8, r2
	movs r0, 0xFF
	mov r10, r0
	mov r9, r6
	mov r2, sp
	adds r2, 0xC
	str r2, [sp, 0x1C]
_08027C76:
	lsls r4, r6, 2
	ldr r0, [sp, 0x1C]
	ldm r0!, {r1}
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_082F7B40
	adds r0, r6, r0
	ldrb r3, [r0]
	mov r0, r8
	movs r2, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	mov r1, r8
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r5, r0, 0
	ldr r0, =gUnknown_082F7B34
	adds r4, r0
	ldr r2, [r4]
	ldr r0, =gUnknown_082F7B44
	lsls r4, r6, 1
	adds r0, r4, r0
	ldrb r0, [r0]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r2, [sp, 0x18]
	lsls r3, r2, 3
	subs r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_082F7B4A
	adds r4, r0
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl AddTextPrinterParameterized
	adds r6, 0x1
	cmp r6, 0x2
	ble _08027C76
	adds r0, r7, 0
	bl PutWindowTilemap
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027BEC

	thumb_func_start sub_8027D20
sub_8027D20: @ 8027D20
	push {lr}
	bl GetLinkPlayerCount
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x24
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027D20

	thumb_func_start sub_8027D38
sub_8027D38: @ 8027D38
	push {r4-r7,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r4, [r0]
	cmp r4, 0x4
	bhi _08027D66
	ldr r5, =gUnknown_082F7B90
_08027D48:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, =gLinkPlayers + 8
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r5
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _08027D48
_08027D66:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x24
	movs r2, 0x5
	strb r2, [r1]
	movs r1, 0
	mov r12, r0
_08027D74:
	movs r4, 0
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0x24
	adds r5, r1, 0x1
	ldrb r0, [r0]
	cmp r4, r0
	bcs _08027DB2
	ldr r7, =gUnknown_02022C98
	lsls r3, r1, 1
	ldr r6, =gUnknown_082F7B50
_08027D8A:
	ldr r2, [r7]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r3, r0
	adds r1, r2, 0
	adds r1, 0x4A
	adds r1, r0
	lsls r0, r4, 3
	adds r0, r3, r0
	adds r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r2, 0x24
	ldrb r2, [r2]
	cmp r4, r2
	bcc _08027D8A
_08027DB2:
	lsls r0, r5, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _08027D74
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027D38

	thumb_func_start sub_8027DD0
sub_8027DD0: @ 8027DD0
	push {lr}
	sub sp, 0x8
	ldr r3, =0xffffff00
	ldr r1, [sp]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	str r1, [sp]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027DD0

	thumb_func_start sub_8027DFC
sub_8027DFC: @ 8027DFC
	push {lr}
	adds r2, r0, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08027E1E
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08027E28
_08027E1E:
	movs r0, 0
	b _08027E2A
	.pool
_08027E28:
	ldrb r0, [r1, 0x4]
_08027E2A:
	pop {r1}
	bx r1
	thumb_func_end sub_8027DFC

	thumb_func_start sub_8027E30
sub_8027E30: @ 8027E30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x48]
	lsls r4, 24
	str r4, [sp, 0x1C]
	movs r4, 0x14
	adds r4, r0
	mov r9, r4
	mov r5, sp
	movs r4, 0x2
	strb r4, [r5]
	mov r10, sp
	mov r5, r9
	ldrb r4, [r5, 0xB]
	movs r7, 0xF
	adds r5, r7, 0
	ands r5, r4
	mov r6, r10
	ldrb r6, [r6, 0x1]
	mov r8, r6
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x1]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0xC]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x1]
	ldrb r5, [r6, 0xD]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x2]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x2]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0xE]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x2]
	ldrb r5, [r6, 0xF]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x3]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x3]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0x10]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x3]
	ldrb r5, [r6, 0x11]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x4]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x4]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0x12]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x4]
	ldrb r4, [r6, 0x13]
	movs r6, 0xF
	ands r4, r6
	mov r6, r8
	ldrb r5, [r6, 0x5]
	movs r6, 0x10
	negs r6, r6
	ands r6, r5
	orrs r6, r4
	str r6, [sp, 0xC]
	mov r4, r8
	strb r6, [r4, 0x5]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x14]
	lsls r4, 4
	ldr r6, [sp, 0xC]
	ands r6, r7
	orrs r6, r4
	strb r6, [r5, 0x5]
	mov r7, sp
	movs r4, 0x3
	mov r8, r4
	ldrb r0, [r0, 0x14]
	mov r5, r8
	ands r0, r5
	ldrb r5, [r7, 0x6]
	movs r6, 0x4
	negs r6, r6
	mov r10, r6
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	strb r4, [r7, 0x6]
	mov r5, r9
	ldrb r0, [r5, 0x1]
	mov r6, r8
	ands r0, r6
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	strb r5, [r7, 0x6]
	mov r0, r9
	ldrb r4, [r0, 0x2]
	ands r4, r6
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	strb r0, [r7, 0x6]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x3]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x6]
	mov r4, r9
	ldrb r0, [r4, 0x4]
	mov r5, r8
	ands r0, r5
	ldrb r5, [r7, 0x7]
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	strb r4, [r7, 0x7]
	mov r6, r9
	ldrb r0, [r6, 0x5]
	mov r5, r8
	ands r0, r5
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	strb r5, [r7, 0x7]
	ldrb r4, [r6, 0x6]
	mov r6, r8
	ands r4, r6
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	strb r0, [r7, 0x7]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x7]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x7]
	mov r8, sp
	mov r0, r9
	ldrb r4, [r0, 0x8]
	movs r7, 0x3
	adds r0, r7, 0
	ands r0, r4
	mov r4, r8
	ldrb r5, [r4, 0x8]
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	mov r5, r8
	strb r4, [r5, 0x8]
	mov r6, r9
	ldrb r5, [r6, 0x9]
	adds r0, r7, 0
	ands r0, r5
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	mov r0, r8
	strb r5, [r0, 0x8]
	ldrb r0, [r1]
	adds r4, r7, 0
	ands r4, r0
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	mov r4, r8
	strb r0, [r4, 0x8]
	mov r5, sp
	ldrb r4, [r2]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x8]
	ldrb r4, [r3]
	adds r0, r7, 0
	ands r0, r4
	ldrb r4, [r5, 0x9]
	mov r6, r10
	ands r6, r4
	orrs r6, r0
	mov r10, r6
	strb r6, [r5, 0x9]
	ldr r0, [sp, 0x40]
	ldrb r4, [r0]
	adds r0, r7, 0
	ands r0, r4
	lsls r0, 2
	movs r4, 0xD
	negs r4, r4
	ands r6, r4
	orrs r6, r0
	str r6, [sp, 0x10]
	strb r6, [r5, 0x9]
	mov r4, sp
	ldr r5, [sp, 0x44]
	ldrb r0, [r5]
	adds r6, r7, 0
	ands r6, r0
	lsls r0, r6, 4
	subs r7, 0x34
	ldr r5, [sp, 0x10]
	ands r7, r5
	orrs r7, r0
	strb r7, [r4, 0x9]
	mov r5, sp
	ldrb r0, [r1, 0x4]
	movs r6, 0x1
	mov r12, r6
	mov r4, r12
	ands r4, r0
	lsls r4, 6
	movs r0, 0x41
	negs r0, r0
	mov r10, r0
	ands r0, r7
	orrs r0, r4
	strb r0, [r5, 0x9]
	ldrb r4, [r2, 0x4]
	lsls r4, 7
	movs r5, 0x7F
	ands r0, r5
	orrs r0, r4
	mov r4, r8
	strb r0, [r4, 0x9]
	ldrb r4, [r3, 0x4]
	mov r0, r12
	ands r0, r4
	mov r5, r8
	ldrb r4, [r5, 0xA]
	movs r7, 0x2
	negs r7, r7
	adds r5, r7, 0
	ands r5, r4
	orrs r5, r0
	mov r6, r8
	strb r5, [r6, 0xA]
	mov r9, sp
	ldr r4, [sp, 0x40]
	ldrb r0, [r4, 0x4]
	mov r4, r12
	ands r4, r0
	lsls r4, 1
	movs r6, 0x3
	negs r6, r6
	mov r8, r6
	mov r0, r8
	ands r0, r5
	orrs r0, r4
	mov r4, r9
	strb r0, [r4, 0xA]
	ldr r6, [sp, 0x44]
	ldrb r5, [r6, 0x4]
	mov r4, r12
	ands r4, r5
	lsls r4, 2
	movs r5, 0x5
	negs r5, r5
	ands r0, r5
	orrs r0, r4
	mov r4, r9
	strb r0, [r4, 0xA]
	mov r4, sp
	ldrb r1, [r1, 0x8]
	mov r0, r12
	ands r0, r1
	lsls r0, 2
	ldrb r1, [r4, 0xB]
	ands r5, r1
	orrs r5, r0
	strb r5, [r4, 0xB]
	ldrb r1, [r2, 0x8]
	mov r0, r12
	ands r0, r1
	lsls r0, 3
	movs r1, 0x9
	negs r1, r1
	ands r1, r5
	orrs r1, r0
	strb r1, [r4, 0xB]
	ldrb r2, [r3, 0x8]
	mov r0, r12
	ands r0, r2
	lsls r0, 4
	movs r2, 0x11
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0xB]
	mov r3, sp
	ldr r5, [sp, 0x40]
	ldrb r0, [r5, 0x8]
	mov r1, r12
	ands r1, r0
	lsls r1, 5
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xB]
	mov r2, sp
	ldrb r1, [r6, 0x8]
	mov r6, r12
	ands r6, r1
	lsls r1, r6, 6
	mov r3, r10
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0xB]
	ldr r4, [sp, 0x1C]
	lsrs r3, r4, 21
	ldrb r1, [r2, 0xA]
	movs r0, 0x7
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0xA]
	mov r1, sp
	ldr r5, [sp, 0x4C]
	movs r6, 0x1
	ands r5, r6
	lsls r2, r5, 1
	ldrb r0, [r1, 0xB]
	mov r3, r8
	ands r3, r0
	orrs r3, r2
	mov r8, r3
	strb r3, [r1, 0xB]
	mov r0, sp
	ldr r4, [sp, 0x50]
	ands r4, r6
	mov r5, r8
	ands r5, r7
	orrs r5, r4
	strb r5, [r0, 0xB]
	bl sub_800FE50
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8027E30

	thumb_func_start sub_8028164
sub_8028164: @ 8028164
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x1C]
	mov r12, r0
	ldr r1, [sp, 0x20]
	mov r8, r1
	ldr r0, [sp, 0x24]
	mov r9, r0
	adds r2, r7, 0
	adds r2, 0x14
	ldr r4, =gRecvCmds
	ldrh r0, [r4]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802819C
	adds r3, r4, 0x2
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _080281A4
_0802819C:
	movs r0, 0
	b _080282DE
	.pool
_080281A4:
	ldrb r0, [r3, 0x1]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xB]
	ldrb r0, [r3, 0x1]
	lsrs r0, 4
	strb r0, [r2, 0xC]
	ldrb r0, [r3, 0x2]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xD]
	ldrb r0, [r3, 0x2]
	lsrs r0, 4
	strb r0, [r2, 0xE]
	ldrb r0, [r3, 0x3]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xF]
	ldrb r0, [r3, 0x3]
	lsrs r0, 4
	strb r0, [r2, 0x10]
	ldrb r0, [r3, 0x4]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x11]
	ldrb r0, [r3, 0x4]
	lsrs r0, 4
	strb r0, [r2, 0x12]
	ldrb r0, [r3, 0x5]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x13]
	ldrb r0, [r3, 0x5]
	lsrs r0, 4
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x15]
	ldrb r0, [r3, 0x6]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r7, 0x14]
	ldrb r0, [r3, 0x6]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x1]
	ldrb r0, [r3, 0x6]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r2, 0x2]
	ldrb r0, [r3, 0x6]
	lsrs r0, 6
	strb r0, [r2, 0x3]
	ldrb r0, [r3, 0x7]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0x4]
	ldrb r0, [r3, 0x7]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x5]
	ldrb r0, [r3, 0x7]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r2, 0x6]
	ldrb r0, [r3, 0x7]
	lsrs r0, 6
	strb r0, [r2, 0x7]
	ldrb r0, [r3, 0x8]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0x8]
	ldrb r0, [r3, 0x8]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x9]
	ldrb r0, [r3, 0x6]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0xA]
	ldrb r0, [r3, 0x8]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r5]
	ldrb r0, [r3, 0x9]
	lsls r0, 25
	lsrs r0, 31
	strb r0, [r5, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 29
	lsrs r0, 31
	strb r0, [r5, 0x8]
	ldrb r0, [r3, 0x8]
	lsrs r0, 6
	strb r0, [r6]
	ldrb r0, [r3, 0x9]
	lsrs r0, 7
	strb r0, [r6, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r6, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 30
	lsrs r0, 30
	mov r1, r12
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 31
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 27
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 28
	lsrs r0, 30
	mov r1, r8
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 30
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 26
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 26
	lsrs r0, 30
	mov r1, r9
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 29
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 25
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0xA]
	lsrs r0, 3
	ldr r1, [sp, 0x28]
	strb r0, [r1]
	ldrb r0, [r3, 0xB]
	lsls r0, 30
	lsrs r0, 31
	ldr r1, [sp, 0x2C]
	str r0, [r1]
	ldrb r0, [r3, 0xB]
	lsls r0, 31
	lsrs r0, 31
	ldr r1, [sp, 0x30]
	str r0, [r1]
	movs r0, 0x1
_080282DE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8028164

	thumb_func_start sub_80282EC
sub_80282EC: @ 80282EC
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0xffffff00
	ldr r1, [sp]
	ands r1, r3
	movs r2, 0x3
	orrs r1, r2
	str r1, [sp]
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80282EC

	thumb_func_start sub_8028318
sub_8028318: @ 8028318
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802833C
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08028344
_0802833C:
	movs r0, 0
	b _0802834A
	.pool
_08028344:
	ldrb r0, [r1, 0x4]
	strb r0, [r4]
	movs r0, 0x1
_0802834A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8028318

	thumb_func_start sub_8028350
sub_8028350: @ 8028350
	push {lr}
	sub sp, 0x8
	ldr r2, =0xffffff00
	ldr r1, [sp]
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	str r1, [sp]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028350

	thumb_func_start sub_8028374
sub_8028374: @ 8028374
	push {lr}
	adds r2, r0, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08028396
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _080283A0
_08028396:
	movs r0, 0
	b _080283A2
	.pool
_080283A0:
	ldr r0, [r1, 0x4]
_080283A2:
	pop {r1}
	bx r1
	thumb_func_end sub_8028374

	thumb_func_start sub_80283A8
sub_80283A8: @ 80283A8
	push {r4,r5,lr}
	sub sp, 0x18
	movs r5, 0xC0
	lsls r5, 6
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	ldr r0, =gUnknown_082FB2D8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gUnknown_082FB2E0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, =gDodrioBerryPkmnGfx
	adds r1, r4, 0
	bl LZ77UnCompWram
	cmp r4, 0
	beq _080283E8
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r4, 0
	bl Free
_080283E8:
	add r0, sp, 0x8
	bl LoadSpritePalette
	add r0, sp, 0x10
	bl LoadSpritePalette
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80283A8

	thumb_func_start sub_8028408
sub_8028408: @ 8028408
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x30
	adds r6, r1, 0
	mov r8, r2
	adds r5, r3, 0
	lsls r6, 24
	lsrs r6, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r5, 24
	lsrs r5, 24
	add r1, sp, 0x18
	movs r3, 0
	strh r3, [r1]
	ldrb r2, [r0]
	mov r0, sp
	adds r0, 0x1A
	strh r2, [r0]
	ldr r0, =gUnknown_082FB1E0
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_082FB228
	str r0, [sp, 0x20]
	str r3, [sp, 0x24]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [sp, 0x28]
	ldr r0, =sub_80284A8
	str r0, [sp, 0x2C]
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	movs r0, 0x4
	bl AllocZeroed
	ldr r1, =gUnknown_02022C9C
	mov r2, r8
	lsls r4, r2, 2
	adds r4, r1
	str r0, [r4]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8028F14
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	movs r2, 0x88
	movs r3, 0x3
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	movs r0, 0x1
	mov r1, r8
	bl sub_8028654
	add sp, 0x30
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028408

	thumb_func_start sub_80284A8
sub_80284A8: @ 80284A8
	push {lr}
	movs r2, 0x2E
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _080284BC
	cmp r1, 0x1
	ble _080284C6
	cmp r1, 0x2
	beq _080284C2
	b _080284C6
_080284BC:
	bl sub_802853C
	b _080284C6
_080284C2:
	bl sub_80285AC
_080284C6:
	pop {r0}
	bx r0
	thumb_func_end sub_80284A8

	thumb_func_start sub_80284CC
sub_80284CC: @ 80284CC
	push {lr}
	bl GetMultiplayerId
	ldr r1, =gUnknown_02022C9C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	strh r2, [r0, 0x34]
	strh r2, [r0, 0x36]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80284CC

	thumb_func_start sub_8028504
sub_8028504: @ 8028504
	push {lr}
	bl GetMultiplayerId
	ldr r1, =gUnknown_02022C9C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	strh r2, [r0, 0x34]
	strh r2, [r0, 0x36]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028504

	thumb_func_start sub_802853C
sub_802853C: @ 802853C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r2, r0, 16
	lsrs r0, 31
	adds r0, r2, r0
	asrs r1, r0, 1
	adds r0, r1, 0
	cmp r1, 0
	bge _08028558
	adds r0, r1, 0x3
_08028558:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r2, 0x2
	ble _080285A2
	cmp r0, 0x2
	bgt _0802856E
	cmp r0, 0x1
	bge _08028572
_0802856E:
	movs r0, 0x1
	b _08028574
_08028572:
	movs r0, 0xFF
_08028574:
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _080285A2
	movs r0, 0
	strh r0, [r4, 0x2E]
	bl sub_8027650
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8028F14
	strh r0, [r4, 0x20]
_080285A2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802853C

	thumb_func_start sub_80285AC
sub_80285AC: @ 80285AC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xD
	bl __divsi3
	lsls r0, 16
	asrs r1, r0, 16
	adds r0, r1, 0
	cmp r1, 0
	bge _080285CC
	adds r0, r1, 0x3
_080285CC:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	movs r1, 0xD
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _080285F0
	cmp r4, 0
	beq _080285F0
	movs r0, 0xD4
	bl PlaySE
_080285F0:
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x67
	ble _080285FE
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r4, 0
_080285FE:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_80286B4
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80285AC

	thumb_func_start sub_8028614
sub_8028614: @ 8028614
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08028646
	ldr r6, =gUnknown_02022C9C
_08028622:
	lsls r0, r4, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _0802863C
	bl DestroySpriteAndFreeResources
_0802863C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08028622
_08028646:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028614

	thumb_func_start sub_8028654
sub_8028654: @ 8028654
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022C9C
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	ldrh r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_8028654

	thumb_func_start sub_802868C
sub_802868C: @ 802868C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	cmp r4, r5
	bcs _080286AE
_0802869C:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8028654
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0802869C
_080286AE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802868C

	thumb_func_start sub_80286B4
sub_80286B4: @ 80286B4
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022C9C
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80286B4

	thumb_func_start nullsub_15
nullsub_15: @ 80286E0
	bx lr
	thumb_func_end nullsub_15

	thumb_func_start sub_80286E4
sub_80286E4: @ 80286E4
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =gSprites
	mov r12, r0
	movs r6, 0
	ldr r5, =gUnknown_02022CF4
_080286F0:
	ldr r3, [r5]
	lsls r1, r4, 1
	adds r0, r3, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r12
	lsls r0, r4, 4
	adds r0, 0x30
	strh r0, [r1, 0x20]
	lsls r2, r4, 3
	movs r7, 0x8
	negs r7, r7
	adds r0, r7, 0
	subs r0, r2
	strh r0, [r1, 0x22]
	adds r3, 0xC
	adds r3, r4
	strb r6, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080286F0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80286E4

	thumb_func_start sub_8028734
sub_8028734: @ 8028734
	push {r4-r6,lr}
	sub sp, 0x28
	movs r4, 0xC0
	lsls r4, 1
	adds r0, r4, 0
	bl AllocZeroed
	adds r6, r0, 0
	ldr r0, =gUnknown_082FB2E8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, =gDodrioBerryStatusGfx
	adds r1, r6, 0
	bl LZ77UnCompWram
	cmp r6, 0
	beq _080287C4
	str r6, [sp, 0x18]
	add r5, sp, 0x18
	movs r0, 0x80
	lsls r0, 9
	orrs r0, r4
	str r0, [r5, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_082FB2F0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, =gUnknown_02022CF4
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4]
	adds r0, r5, 0
	bl LoadSpriteSheet
	add r0, sp, 0x20
	bl LoadSpritePalette
	movs r4, 0
_0802878A:
	lsls r1, r4, 20
	movs r0, 0xC0
	lsls r0, 14
	adds r1, r0
	asrs r1, 16
	lsls r0, r4, 3
	movs r3, 0x8
	negs r3, r3
	adds r2, r3, 0
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	ldr r1, =gUnknown_02022CF4
	ldr r1, [r1]
	lsls r2, r4, 1
	adds r1, 0x2A
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _0802878A
_080287C4:
	adds r0, r6, 0
	bl Free
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028734

	thumb_func_start sub_80287E4
sub_80287E4: @ 80287E4
	push {r4,r5,lr}
	movs r4, 0
_080287E8:
	ldr r5, =gUnknown_02022CF4
	ldr r0, [r5]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028806
	bl DestroySpriteAndFreeResources
_08028806:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080287E8
	ldr r0, [r5]
	bl Free
	movs r0, 0
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80287E4

	thumb_func_start sub_8028828
sub_8028828: @ 8028828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r3, 0
	movs r6, 0
	ldr r0, =gUnknown_02022CF4
	mov r9, r0
_0802883A:
	mov r7, r9
	ldr r2, [r7]
	lsls r5, r6, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r5
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r2, 0
	adds r0, 0x16
	adds r0, r5
	movs r1, 0x2
	strh r1, [r0]
	adds r0, r2, 0
	adds r0, 0xC
	adds r2, r0, r6
	ldrb r1, [r2]
	cmp r1, 0
	beq _08028870
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r0, 0x8
	beq _080288A6
_08028870:
	movs r3, 0x1
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r0, 0x8
	bne _08028896
	cmp r1, 0
	bne _080288A6
	strb r3, [r2]
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x16
	adds r0, r5
	ldr r1, =0x0000fff0
	strh r1, [r0]
	movs r0, 0x24
	str r3, [sp]
	bl PlaySE
	ldr r3, [sp]
_08028896:
	mov r7, r9
	ldr r0, [r7]
	adds r0, 0x16
	adds r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_080288A6:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x9
	bls _0802883A
	cmp r3, 0
	bne _080288C4
	movs r0, 0x1
	b _080288C6
	.pool
_080288C4:
	movs r0, 0
_080288C6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8028828

	thumb_func_start sub_80288D4
sub_80288D4: @ 80288D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028910
	movs r4, 0
_080288E0:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080288E0
	b _080289DA
	.pool
_08028910:
	movs r4, 0
	movs r0, 0xA
	subs r0, r5
	cmp r4, r0
	bge _080289D6
	ldr r6, =gSprites
_0802891C:
	cmp r5, 0x6
	bls _08028984
	ldr r0, =gUnknown_02022CF4
	ldr r2, [r0]
	ldr r1, =0x0000fffa
	adds r0, r1, 0
	ldrh r1, [r2, 0x3E]
	adds r0, r1
	adds r0, r5
	movs r1, 0
	strh r0, [r2, 0x3E]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _0802894C
	strh r1, [r2, 0x3E]
	b _0802899E
	.pool
_0802894C:
	cmp r0, 0xA
	bls _0802896A
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartSpriteAnim
	b _0802899E
_0802896A:
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartSpriteAnim
	b _0802899E
_08028984:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartSpriteAnim
_0802899E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0xA
	subs r0, r5
	cmp r4, r0
	blt _0802891C
	b _080289D6
	.pool
_080289B4:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080289D6:
	cmp r4, 0x9
	bls _080289B4
_080289DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80288D4

	thumb_func_start sub_80289E8
sub_80289E8: @ 80289E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r6, 0x5
	negs r6, r6
	ldr r5, =gUnknown_02022CF4
_080289FE:
	ldr r0, [r5]
	lsls r1, r3, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x9
	bls _080289FE
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80289E8

	thumb_func_start sub_8028A34
sub_8028A34: @ 8028A34
	push {r4,r5,lr}
	sub sp, 0x10
	movs r5, 0x90
	lsls r5, 3
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	ldr r0, =gUnknown_082FB314
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gDodrioBerrySpritesGfx
	adds r1, r4, 0
	bl LZ77UnCompWram
	cmp r4, 0
	beq _08028A6A
	str r4, [sp]
	movs r0, 0x80
	lsls r0, 10
	orrs r0, r5
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
_08028A6A:
	add r0, sp, 0x8
	bl LoadSpritePalette
	adds r0, r4, 0
	bl Free
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028A34

	thumb_func_start sub_8028A88
sub_8028A88: @ 8028A88
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	mov r1, sp
	ldr r0, =gUnknown_082FB324
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	add r2, sp, 0x18
	adds r1, r2, 0
	ldr r0, =gUnknown_082FB33C
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	movs r5, 0
	mov r9, r2
_08028AB0:
	movs r0, 0x4
	bl AllocZeroed
	ldr r1, =gUnknown_02022CB8
	lsls r4, r5, 2
	adds r4, r1
	str r0, [r4]
	lsls r0, r5, 3
	lsls r1, r5, 4
	adds r1, r0
	mov r0, sp
	movs r2, 0x8
	movs r3, 0x1
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8028BF8
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028AB0
	movs r5, 0
	ldr r7, =gUnknown_02022CE4
	ldr r4, =gUnknown_082FB31C
	mov r8, r4
_08028AF0:
	movs r0, 0x4
	bl AllocZeroed
	lsls r1, r5, 2
	adds r4, r1, r7
	str r0, [r4]
	adds r6, r1, 0
	cmp r5, 0x3
	bne _08028B2C
	mov r0, r8
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0x31
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7, 0xC]
	b _08028B40
	.pool
_08028B2C:
	lsls r0, r5, 1
	add r0, r8
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r0, r9
	movs r2, 0x34
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
_08028B40:
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r6, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r1, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08028AF0
	movs r0, 0x1
	bl sub_8028C30
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028A88

	thumb_func_start sub_8028B80
sub_8028B80: @ 8028B80
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_02022CB8
_08028B86:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028BA0
	bl DestroySprite
_08028BA0:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028B86
	movs r5, 0
	ldr r6, =gUnknown_02022CE4
_08028BB8:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028BD2
	bl DestroySprite
_08028BD2:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08028BB8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028B80

	thumb_func_start sub_8028BF8
sub_8028BF8: @ 8028BF8
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8028BF8

	thumb_func_start sub_8028C30
sub_8028C30: @ 8028C30
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	ldr r6, =gUnknown_02022CE4
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r5, 0x5
	negs r5, r5
_08028C46:
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _08028C46
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028C30

	thumb_func_start sub_8028C7C
sub_8028C7C: @ 8028C7C
	lsls r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	lsrs r1, 21
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_8028C7C

	thumb_func_start sub_8028CA4
sub_8028CA4: @ 8028CA4
	push {lr}
	lsls r0, 16
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 14
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028CA4

	thumb_func_start sub_8028CD0
sub_8028CD0: @ 8028CD0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x32
	strh r1, [r2, 0x20]
	movs r0, 0x32
	strh r0, [r2, 0x22]
	bx lr
	.pool
	thumb_func_end sub_8028CD0

	thumb_func_start sub_8028CF4
sub_8028CF4: @ 8028CF4
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r0, 0x42
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _08028D36
	movs r3, 0
	ldr r7, =gUnknown_082FB354
	ldr r6, =gUnknown_02022CB0
	movs r5, 0
_08028D0A:
	lsls r0, r3, 2
	adds r2, r0, r6
	ldr r1, [r2]
	ldrh r0, [r1, 0x2]
	adds r0, 0x1
	strh r0, [r1, 0x2]
	adds r1, r3, r7
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1]
	cmp r0, r1
	bls _08028D2C
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
	strh r0, [r4, 0x20]
	ldr r0, [r2]
	strh r5, [r0, 0x2]
_08028D2C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028D0A
_08028D36:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028CF4

	thumb_func_start sub_8028D44
sub_8028D44: @ 8028D44
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x28
	movs r4, 0x80
	lsls r4, 3
	adds r0, r4, 0
	bl AllocZeroed
	adds r6, r0, 0
	ldr r0, =gUnknown_082FB360
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, =gDodrioBerryPlatformGfx
	adds r1, r6, 0
	bl LZ77UnCompWram
	cmp r6, 0
	beq _08028DD2
	str r6, [sp, 0x18]
	add r0, sp, 0x18
	movs r1, 0xA0
	lsls r1, 11
	orrs r1, r4
	str r1, [r0, 0x4]
	mov r2, sp
	ldr r1, =gUnknown_082FB368
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	bl LoadSpriteSheet
	add r0, sp, 0x20
	bl LoadSpritePalette
	movs r5, 0
	ldr r7, =gUnknown_082FB356
	adds r0, r7, 0x2
	mov r9, r0
	ldr r1, =gUnknown_02022CB0
	mov r8, r1
_08028D9E:
	movs r0, 0x4
	bl AllocZeroed
	lsls r2, r5, 2
	mov r3, r8
	adds r4, r2, r3
	str r0, [r4]
	adds r0, r2, r7
	movs r3, 0
	ldrsh r1, [r0, r3]
	add r2, r9
	movs r0, 0
	ldrsh r2, [r2, r0]
	mov r0, sp
	movs r3, 0x4
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _08028D9E
_08028DD2:
	adds r0, r6, 0
	bl Free
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028D44

	thumb_func_start sub_8028DFC
sub_8028DFC: @ 8028DFC
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gUnknown_02022CB0
	mov r12, r0
	ldr r4, =gUnknown_082FB356
	adds r7, r4, 0x2
	ldr r6, =gSprites
	movs r5, 0x1
_08028E0C:
	lsls r2, r3, 2
	mov r1, r12
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r0, r1, 0
	adds r0, 0x42
	strh r5, [r0]
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, 0x20]
	adds r2, r7
	ldrh r0, [r2]
	strh r0, [r1, 0x22]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028E0C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028DFC

	thumb_func_start sub_8028E4C
sub_8028E4C: @ 8028E4C
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_02022CB0
	ldr r4, =gSprites
	movs r3, 0
_08028E56:
	lsls r0, r2, 2
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x42
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bls _08028E56
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028E4C

	thumb_func_start sub_8028E84
sub_8028E84: @ 8028E84
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_02022CB0
_08028E8A:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028EA4
	bl DestroySprite
_08028EA4:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _08028E8A
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028E84

	thumb_func_start sub_8028EC8
sub_8028EC8: @ 8028EC8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	ldr r6, =gUnknown_02022CB0
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r5, 0x5
	negs r5, r5
_08028EDE:
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028EDE
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028EC8

	thumb_func_start sub_8028F14
sub_8028F14: @ 8028F14
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	subs r0, r1, 0x1
	cmp r0, 0x4
	bhi _08028FC6
	lsls r0, 2
	ldr r1, =_08028F34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08028F34:
	.4byte _08028FB4
	.4byte _08028F48
	.4byte _08028F52
	.4byte _08028F66
	.4byte _08028F8E
_08028F48:
	cmp r2, 0
	beq _08028F7E
	cmp r2, 0x1
	bne _08028FC6
	b _08028F82
_08028F52:
	cmp r2, 0x1
	beq _08028FB8
	cmp r2, 0x1
	bgt _08028F60
	cmp r2, 0
	beq _08028FB4
	b _08028FC6
_08028F60:
	cmp r2, 0x2
	bne _08028FC6
	b _08028FC4
_08028F66:
	cmp r2, 0x1
	beq _08028F82
	cmp r2, 0x1
	bgt _08028F74
	cmp r2, 0
	beq _08028F7E
	b _08028FC6
_08028F74:
	cmp r2, 0x2
	beq _08028F86
	cmp r2, 0x3
	beq _08028F8A
	b _08028FC6
_08028F7E:
	movs r3, 0xC
	b _08028FC6
_08028F82:
	movs r3, 0x12
	b _08028FC6
_08028F86:
	movs r3, 0x18
	b _08028FC6
_08028F8A:
	movs r3, 0x6
	b _08028FC6
_08028F8E:
	cmp r2, 0x4
	bhi _08028FC6
	lsls r0, r2, 2
	ldr r1, =_08028FA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08028FA0:
	.4byte _08028FB4
	.4byte _08028FB8
	.4byte _08028FBC
	.4byte _08028FC0
	.4byte _08028FC4
_08028FB4:
	movs r3, 0xF
	b _08028FC6
_08028FB8:
	movs r3, 0x15
	b _08028FC6
_08028FBC:
	movs r3, 0x1B
	b _08028FC6
_08028FC0:
	movs r3, 0x3
	b _08028FC6
_08028FC4:
	movs r3, 0x9
_08028FC6:
	lsls r0, r3, 3
	pop {r1}
	bx r1
	thumb_func_end sub_8028F14

	thumb_func_start sub_8028FCC
sub_8028FCC: @ 8028FCC
	push {r4,lr}
	movs r4, 0
_08028FD0:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8028BF8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8028C7C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _08028FD0
	movs r0, 0
	bl sub_80289E8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8028FCC

	thumb_func_start sub_8028FF8
sub_8028FF8: @ 8028FF8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	movs r0, 0
	movs r3, 0x1
	bl LoadBgTiles
	adds r0, r4, 0
	bl GetWindowFrameTilesPal
	ldr r0, [r0, 0x4]
	movs r1, 0xA0
	movs r2, 0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8028FF8

	thumb_func_start sub_802902C
sub_802902C: @ 802902C
	push {lr}
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xB0
	bl LoadUserWindowBorderGfx_
	pop {r0}
	bx r0
	thumb_func_end sub_802902C

	thumb_func_start sub_802903C
sub_802903C: @ 802903C
	ldr r3, =gUnknown_02022CF8
	ldr r0, [r3]
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r1, =0x00003014
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x8
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	bx lr
	.pool
	thumb_func_end sub_802903C

	thumb_func_start sub_8029074
sub_8029074: @ 8029074
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r6, 0xA
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x3
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x4
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x6
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x8
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r4, [r4, 0x2]
	adds r3, r4
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x9
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8029074

	thumb_func_start sub_8029174
sub_8029174: @ 8029174
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r6, 0xB
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xA
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xB
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xC
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xD
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xF
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x10
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x11
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r4, [r4, 0x2]
	adds r3, r4
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x12
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8029174

	thumb_func_start sub_8029274
sub_8029274: @ 8029274
	push {r4,lr}
	ldr r4, =gUnknown_02022CF8
	str r0, [r4]
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r3, =0x00003014
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, =0x00003018
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0xC
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0xC
	adds r0, r1
	strb r2, [r0]
	ldr r0, =sub_8029314
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	ldr r2, =0x00003004
	adds r1, r2
	strb r0, [r1]
	ldr r0, =sub_8029338
	bl sub_802A72C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029274

	thumb_func_start sub_80292D4
sub_80292D4: @ 80292D4
	push {lr}
	bl FreeAllWindowBuffers
	pop {r0}
	bx r0
	thumb_func_end sub_80292D4

	thumb_func_start sub_80292E0
sub_80292E0: @ 80292E0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, =gUnknown_082FB40C
	adds r7, r5, 0x4
_080292EC:
	lsls r1, r4, 3
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r6
	bne _080292FE
	adds r0, r1, r7
	ldr r0, [r0]
	bl sub_802A72C
_080292FE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080292EC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80292E0

	thumb_func_start sub_8029314
sub_8029314: @ 8029314
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0802932E
	bl sub_802A75C
	bl _call_via_r0
_0802932E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029314

	thumb_func_start sub_8029338
sub_8029338: @ 8029338
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _08029430
	lsls r0, 2
	ldr r1, =_08029360
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08029360:
	.4byte _08029374
	.4byte _0802937A
	.4byte _08029394
	.4byte _080293D8
	.4byte _08029404
_08029374:
	bl sub_802A7A8
	b _08029414
_0802937A:
	bl sub_802A8E8
	cmp r0, 0x1
	bne _0802943A
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802941C
	.pool
_08029394:
	ldr r1, =gDodrioBerryBgTilemap1
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gDodrioBerryBgTilemap2Left
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gDodrioBerryBgTilemap2Right
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _08029414
	.pool
_080293D8:
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802941C
	.pool
_08029404:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8028FF8
	bl sub_802902C
_08029414:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
_0802941C:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802943A
	.pool
_08029430:
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r2
	movs r0, 0x1
	str r0, [r1]
_0802943A:
	pop {r0}
	bx r0
	thumb_func_end sub_8029338

	thumb_func_start sub_8029440
sub_8029440: @ 8029440
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r2, =0x00003014
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08029488
	cmp r0, 0x1
	bne _08029460
	b _080295EC
_08029460:
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB4
	bhi _0802946E
	b _0802968E
_0802946E:
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	cmp r6, r7
	bcc _0802947E
	b _08029666
_0802947E:
	b _08029640
	.pool
_08029488:
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gUnknown_082FB3C8
	subs r0, r7, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	ldr r2, =0xffffff00
	ldr r0, [sp, 0xC]
	ands r0, r2
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0xE0
	lsls r1, 19
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r2
	movs r1, 0x2
	orrs r0, r1
	ldr r1, =0xffff00ff
	ands r0, r1
	movs r1, 0xD0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x98
	lsls r1, 13
	orrs r0, r1
	str r0, [sp, 0x10]
	movs r6, 0
	cmp r6, r7
	bcs _080295B8
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x18]
	mov r10, r4
	ldr r0, =0x00003008
	mov r9, r0
_080294DC:
	movs r1, 0
	mov r8, r1
	adds r0, r6, 0
	bl sub_8027A48
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_8027660
	adds r1, r0, 0
	movs r0, 0x1
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0x38
	subs r1, r0
	lsrs r1, 1
	str r1, [sp, 0x14]
	ldrb r0, [r5]
	lsls r0, 8
	ldr r2, =0xffff00ff
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	ldrb r2, [r5, 0x1]
	lsls r2, 16
	ldr r0, =0xff00ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	bl AddWindow
	mov r2, r10
	ldr r1, [r2]
	add r1, r9
	adds r1, r6
	strb r0, [r1]
	ldr r0, [r2]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r3, r10
	ldr r0, [r3]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0802955A
	movs r0, 0x2
	mov r8, r0
_0802955A:
	adds r0, r4, 0
	bl sub_8027660
	adds r4, r0, 0
	mov r1, r10
	ldr r0, [r1]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	ldr r3, [sp, 0x14]
	lsls r2, r3, 24
	lsrs r2, 24
	mov r3, r8
	lsls r1, r3, 1
	add r1, r8
	ldr r3, =gUnknown_082FB380
	adds r1, r3
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	mov r2, r10
	ldr r0, [r2]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r3, [sp, 0x18]
	ldrh r0, [r3, 0x6]
	adds r0, 0xE
	strh r0, [r3, 0x6]
	add r0, sp, 0xC
	bl sub_8029174
	adds r5, 0x4
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _080294DC
_080295B8:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802962A
	.pool
_080295EC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802968E
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	cmp r6, r7
	bcs _0802961C
_08029604:
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	adds r0, r6
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08029604
_0802961C:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
_0802962A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802968E
	.pool
_08029640:
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003008
	adds r0, r4
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	adds r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08029640
_08029666:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r3, 0xC0
	lsls r3, 6
	adds r0, r3
	movs r1, 0x1
	str r1, [r0]
_0802968E:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029440

	thumb_func_start sub_80296A8
sub_80296A8: @ 80296A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	lsls r0, 24
	movs r1, 0
	mov r8, r1
	movs r6, 0
	lsrs r7, r0, 24
	add r4, sp, 0x2C
	ldr r1, =gUnknown_082FB45C
	adds r0, r4, 0
	movs r2, 0x5
	bl memcpy
	movs r5, 0
	cmp r5, r7
	bcs _080296F8
	add r4, sp, 0x34
_080296D2:
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	strb r5, [r0]
	add r0, sp, 0x5C
	adds r1, r5, 0
	bl sub_802793C
	lsls r2, r5, 3
	adds r2, r4, r2
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _080296D2
_080296F8:
	bl sub_8027748
	cmp r0, 0
	beq _0802972E
_08029700:
	movs r5, 0
	cmp r5, r7
	bcs _08029728
	add r2, sp, 0x34
	add r1, sp, 0x2C
_0802970A:
	lsls r0, r5, 3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r8
	bne _0802971E
	adds r0, r1, r6
	strb r5, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0802971E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802970A
_08029728:
	mov r8, r6
	cmp r6, r7
	bcc _08029700
_0802972E:
	movs r5, 0
	ldr r4, =gText_SpacePoints
	cmp r5, r7
	bcs _08029754
	add r1, sp, 0x34
	add r6, sp, 0x38
	subs r3, r7, 0x1
_0802973C:
	lsls r2, r5, 3
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0802974A
	adds r0, r1, r2
	strb r3, [r0]
_0802974A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802973C
_08029754:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	movs r1, 0xD8
	subs r1, r0
	str r1, [sp, 0x64]
	movs r5, 0
	cmp r5, r7
	bcs _08029860
	mov r2, sp
	adds r2, 0x34
	str r2, [sp, 0x68]
	ldr r3, =0x00003009
	mov r10, r3
_08029774:
	movs r0, 0
	mov r8, r0
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	ldrb r0, [r0]
	adds r4, r0, 0
	lsls r1, r4, 3
	add r0, sp, 0x38
	adds r0, r1
	ldr r0, [r0]
	mov r9, r0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gUnknown_082FB3DC
	ldr r3, [sp, 0x68]
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r3, =gUnknown_082FB402
	lsls r1, r5, 1
	adds r1, r3
	ldrb r6, [r1]
	str r6, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r3, r8
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080297CC
	movs r0, 0x2
	mov r8, r0
_080297CC:
	adds r0, r4, 0
	bl sub_8027660
	adds r3, r0, 0
	ldr r1, =gUnknown_02022CF8
	ldr r0, [r1]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r8
	lsls r1, r2, 1
	add r1, r8
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0x1C
	adds r3, r6, 0
	bl AddTextPrinterParameterized3
	add r0, sp, 0xC
	mov r1, r9
	movs r2, 0
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r3, r0, 0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	subs r3, r1, r3
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	lsls r3, r1, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gText_SpacePoints
	lsrs r3, 24
	bl AddTextPrinterParameterized
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _08029774
_08029860:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80296A8

	thumb_func_start sub_802988C
sub_802988C: @ 802988C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl sub_8027650
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	ldr r6, =gUnknown_02022CF8
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xB
	bls _080298B2
	b _08029FA8
_080298B2:
	lsls r0, 2
	ldr r1, =_080298C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080298C8:
	.4byte _080298F8
	.4byte _08029914
	.4byte _0802996C
	.4byte _08029B6C
	.4byte _08029BB8
	.4byte _08029BFC
	.4byte _08029C60
	.4byte _08029C9C
	.4byte _08029CE0
	.4byte _08029DA0
	.4byte _08029F08
	.4byte _08029F5C
_080298F8:
	bl sub_802784C
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x0000301c
	adds r2, r1, r0
	movs r0, 0
	strh r0, [r2]
	b _08029F8A
	.pool
_08029914:
	ldr r6, =gUnknown_082F7BBC
	adds r0, r6, 0
	bl AddWindow
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	ldr r2, =0x00003008
	mov r8, r2
	add r1, r8
	strb r0, [r1]
	movs r0, 0x8
	adds r0, r6
	mov r9, r0
	bl AddWindow
	ldr r1, [r4]
	ldr r5, =0x00003009
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	mov r0, r9
	bl sub_8029174
	b _08029F88
	.pool
_0802996C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r9, r1
	add r0, r9
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_BerryPickingResults
	mov r8, r2
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	mov r1, r8
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r6, 0xFF
	str r6, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	mov r2, r8
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	add r0, r9
	ldrb r0, [r0]
	ldr r2, =gText_10P30P50P50P
	movs r1, 0x11
	str r1, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x44
	bl AddTextPrinterParameterized
	mov r9, r5
	ldr r0, [sp, 0xC]
	cmp r9, r0
	bcc _080299E2
	b _08029B2A
_080299E2:
	movs r4, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r9, r0
	bne _080299F2
	movs r4, 0x2
_080299F2:
	mov r0, r9
	bl sub_8027660
	adds r6, r0, 0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r9
	lsls r5, r2, 1
	ldr r2, =gUnknown_082FB3F8
	adds r1, r5, r2
	ldrb r3, [r1]
	lsls r1, r4, 1
	adds r1, r4
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	movs r7, 0
	mov r8, r5
	mov r0, r9
	adds r0, 0x1
	str r0, [sp, 0x10]
	ldr r1, =gStringVar4
	mov r10, r1
_08029A36:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80276A0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	bl sub_8027A38
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl sub_802778C
	ldr r1, =0x0000270f
	bl sub_8027A38
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r5, r0, 0
	cmp r6, r4
	bne _08029AE0
	cmp r6, 0
	beq _08029AE0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r2, [r1]
	subs r2, r5
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r3, [r1]
	ldr r1, =gUnknown_082FB383
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	b _08029B10
	.pool
_08029AE0:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r3, [r1]
	subs r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar4
	bl AddTextPrinterParameterized
_08029B10:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08029A36
	ldr r1, [sp, 0x10]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, [sp, 0xC]
	cmp r9, r2
	bcs _08029B2A
	b _080299E2
_08029B2A:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029B6C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029B90
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029B90:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl sub_8028C30
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029BB8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029BD0
	b _08029FF8
_08029BD0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029BDE
	b _08029FF8
_08029BDE:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl sub_8028C30
	b _08029F88
	.pool
_08029BFC:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r6, =gText_AnnouncingRankings
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized
	b _08029F88
	.pool
_08029C60:
	ldr r0, [sp, 0xC]
	bl sub_80296A8
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029C9C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029CC0
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029CC0:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029CE0:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029CF8
	b _08029FF8
_08029CF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029D06
	b _08029FF8
_08029D06:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	bl sub_8027748
	ldr r1, =0x00000bb7
	cmp r0, r1
	bhi _08029D3C
	ldr r0, [r4]
	ldr r2, =0x00003014
	adds r0, r2
	movs r1, 0x7F
	strb r1, [r0]
	b _08029D4C
	.pool
_08029D3C:
	bl StopMapMusic
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08029D4C:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x5
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r6, =gUnknown_082F7BCC
	adds r0, r6, 0
	bl AddWindow
	ldr r1, [r5]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	b _08029FF8
	.pool
_08029DA0:
	ldr r0, =0x0000016f
	bl PlayNewMapMusic
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_AnnouncingPrizes
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r5, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0x1
	mov r9, r2
	str r2, [sp]
	movs r1, 0xFF
	mov r8, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gStringVar1
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r7, =gStringVar4
	ldr r1, =gText_FirstPlacePrize
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r4]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r9
	str r2, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	bl sub_80279C8
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	cmp r4, 0
	beq _08029EC8
	cmp r4, 0x3
	beq _08029EC8
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r4, 0x2
	bne _08029E9C
	ldr r1, =gText_CantHoldAnyMore
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08029EA8
	.pool
_08029E9C:
	cmp r6, 0x1
	bne _08029EA8
	ldr r1, =gText_FilledStorageSpace
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
_08029EA8:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	ldr r2, =gStringVar4
	movs r1, 0x29
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
_08029EC8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F08:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029F2C
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029F2C:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =0x0000020b
	movs r1, 0x14
	movs r2, 0xA
	bl FadeOutAndFadeInNewMapMusic
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F5C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bls _08029FF8
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08029FF8
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
_08029F88:
	ldr r1, [r4]
_08029F8A:
	ldr r2, =0x00003014
	adds r1, r2
_08029F8E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08029FF8
	.pool
_08029FA8:
	ldr r5, =0x00003008
	adds r0, r1, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_08029FF8:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802988C

	thumb_func_start sub_802A010
sub_802A010: @ 802A010
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r3, =0x00003014
	adds r0, r2, r3
	ldrb r6, [r0]
	adds r7, r1, 0
	cmp r6, 0x1
	beq _0802A0CC
	cmp r6, 0x1
	bgt _0802A040
	cmp r6, 0
	beq _0802A04E
	b _0802A2FC
	.pool
_0802A040:
	cmp r6, 0x2
	bne _0802A046
	b _0802A194
_0802A046:
	cmp r6, 0x3
	bne _0802A04C
	b _0802A1D0
_0802A04C:
	b _0802A2FC
_0802A04E:
	ldr r0, =gUnknown_082F7BD4
	mov r9, r0
	bl AddWindow
	ldr r1, [r7]
	ldr r4, =0x00003008
	adds r1, r4
	strb r0, [r1]
	movs r1, 0x8
	add r1, r9
	mov r8, r1
	mov r0, r8
	bl AddWindow
	ldr r1, [r7]
	ldr r2, =0x00003009
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r3, =0x00003009
	adds r0, r3
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r0, r9
	bl sub_8029174
	mov r0, r8
	bl sub_8029074
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r1, =0x00003020
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r7]
	ldr r2, =0x00003024
	adds r0, r2
	strb r6, [r0]
	b _0802A35E
	.pool
_0802A0CC:
	ldr r3, =0x00003008
	mov r8, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_WantToPlayAgain
	movs r1, 0x5
	str r1, [sp]
	movs r3, 0xFF
	mov r9, r3
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A194:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A1B6
	ldr r0, [r7]
	ldr r3, =0x00003008
	adds r0, r3
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1B6:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A1D0:
	ldr r3, =0x00003020
	adds r0, r2, r3
	ldrb r5, [r0]
	cmp r5, 0
	bne _0802A1DC
	movs r5, 0x1
_0802A1DC:
	ldr r0, =0x00003009
	mov r8, r0
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r3, 0xFF
	mov r10, r3
	str r3, [sp, 0x4]
	movs r1, 0
	mov r9, r1
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	subs r1, r5, 0x1
	lsls r1, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r5, 0x1
	movs r2, 0x1
	ands r2, r1
	cmp r2, 0
	beq _0802A294
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802A2E4
	strb r5, [r1]
	b _0802A2E4
	.pool
_0802A294:
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0802A2CC
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0802A2C2
	cmp r0, 0x1
	bgt _0802A2BC
	cmp r0, 0
	beq _0802A2C2
	b _0802A35E
	.pool
_0802A2BC:
	cmp r0, 0x2
	beq _0802A2C8
	b _0802A35E
_0802A2C2:
	movs r0, 0x2
	strb r0, [r1]
	b _0802A35E
_0802A2C8:
	strb r5, [r1]
	b _0802A35E
_0802A2CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0802A35E
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r0, r3
	movs r1, 0x2
	strb r1, [r0]
_0802A2E4:
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
_0802A2EA:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A35E
	.pool
_0802A2FC:
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, =0x00003024
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r7]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r7]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r7]
	movs r3, 0xC0
	lsls r3, 6
	adds r0, r3
	movs r1, 0x1
	str r1, [r0]
_0802A35E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A010

	thumb_func_start sub_802A380
sub_802A380: @ 802A380
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r6, =0x00003014
	adds r0, r6
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _0802A3D8
	cmp r4, 0x1
	bgt _0802A3A4
	cmp r4, 0
	beq _0802A3AE
	b _0802A420
	.pool
_0802A3A4:
	cmp r4, 0x2
	beq _0802A3EC
	cmp r4, 0x3
	beq _0802A404
	b _0802A420
_0802A3AE:
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized2
	b _0802A410
	.pool
_0802A3D8:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A414
	.pool
_0802A3EC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _0802A410
	.pool
_0802A404:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
_0802A410:
	ldr r1, [r5]
	adds r1, r6
_0802A414:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A448
	.pool
_0802A420:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A448:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A380

	thumb_func_start sub_802A454
sub_802A454: @ 802A454
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r6, =0x00003014
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _0802A4AC
	cmp r0, 0x1
	bgt _0802A47C
	cmp r0, 0
	beq _0802A482
	b _0802A520
	.pool
_0802A47C:
	cmp r0, 0x2
	beq _0802A4F4
	b _0802A520
_0802A482:
	ldr r4, =gUnknown_082F7BEC
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	b _0802A510
	.pool
_0802A4AC:
	ldr r4, =0x00003008
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_CommunicationStandby3
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A514
	.pool
_0802A4F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A50A
	ldr r0, [r5]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A50A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802A510:
	ldr r1, [r5]
	adds r1, r6
_0802A514:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A52C
	.pool
_0802A520:
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A52C:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802A454

	thumb_func_start sub_802A534
sub_802A534: @ 802A534
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A534

	thumb_func_start sub_802A588
sub_802A588: @ 802A588
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r7, =0x00003014
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, 0
	cmp r5, 0x1
	beq _0802A610
	cmp r5, 0x1
	bgt _0802A5B0
	cmp r5, 0
	beq _0802A5BA
	b _0802A6A4
	.pool
_0802A5B0:
	cmp r5, 0x2
	beq _0802A658
	cmp r5, 0x3
	beq _0802A684
	b _0802A6A4
_0802A5BA:
	ldr r4, =gUnknown_082F7BE4
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	ldr r1, [r6]
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, =0x0000301c
	adds r1, r0, r2
	movs r2, 0
	strh r5, [r1]
	ldr r1, =0x00003020
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	b _0802A6EA
	.pool
_0802A610:
	ldr r4, =0x00003008
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_SomeoneDroppedOut
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A678
	.pool
_0802A658:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A66E
	ldr r0, [r6]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A66E:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r7
_0802A678:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A6EA
	.pool
_0802A684:
	ldr r0, =0x0000301c
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x77
	bls _0802A6EA
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _0802A6EA
	.pool
_0802A6A4:
	ldr r0, [r6]
	ldr r1, =0x00003024
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, 0xC0
	lsls r2, 6
	adds r0, r2
	movs r1, 0x1
	str r1, [r0]
_0802A6EA:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A588

	thumb_func_start unused_0
unused_0: @ 802A6FC
	push {r4,lr}
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003004
	adds r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unused_0

	thumb_func_start nullsub_16
nullsub_16: @ 802A728
	bx lr
	thumb_func_end nullsub_16

	thumb_func_start sub_802A72C
sub_802A72C: @ 802A72C
	push {r4,lr}
	ldr r2, =gUnknown_02022CF8
	ldr r1, [r2]
	ldr r3, =0x00003014
	adds r1, r3
	movs r3, 0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, 0xC0
	lsls r4, 6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, =0x00003028
	adds r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A72C

	thumb_func_start sub_802A75C
sub_802A75C: @ 802A75C
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003028
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A75C

	thumb_func_start sub_802A770
sub_802A770: @ 802A770
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0802A78C
	movs r0, 0x1
	b _0802A78E
	.pool
_0802A78C:
	movs r0, 0
_0802A78E:
	pop {r1}
	bx r1
	thumb_func_end sub_802A770

	thumb_func_start sub_802A794
sub_802A794: @ 802A794
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003024
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A794

	thumb_func_start sub_802A7A8
sub_802A7A8: @ 802A7A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0802A7CE:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0802A7CE
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F7BA4
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
	bl InitStandardTextBoxWindows
	bl sub_8197200
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A7A8

	thumb_func_start sub_802A8E8
sub_802A8E8: @ 802A8E8
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003018
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x5
	bhi _0802A982
	lsls r0, 2
	ldr r1, =_0802A910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802A910:
	.4byte _0802A928
	.4byte _0802A938
	.4byte _0802A93E
	.4byte _0802A94C
	.4byte _0802A964
	.4byte _0802A972
_0802A928:
	ldr r0, =gDodrioBerryBgPal1
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	b _0802A98A
	.pool
_0802A938:
	bl reset_temp_tile_data_buffers
	b _0802A98A
_0802A93E:
	ldr r1, =gDodrioBerryBgGfx1
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _0802A954
	.pool
_0802A94C:
	ldr r1, =gDodrioBerryBgGfx2
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
_0802A954:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _0802A98A
	.pool
_0802A964:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802A98A
	b _0802A998
_0802A972:
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	b _0802A98A
_0802A982:
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _0802A99A
_0802A98A:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003018
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0802A998:
	movs r0, 0
_0802A99A:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802A8E8

	thumb_func_start sub_802A9A8
sub_802A9A8: @ 802A9A8
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802AA3C
	ldr r5, =gUnknown_02022CFC
	ldr r0, =0x000083b0
	bl Alloc
	str r0, [r5]
	cmp r0, 0
	beq _0802AA3C
	bl ResetTasks
	ldr r0, =sub_802ACA0
	movs r1, 0x1
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, [r5]
	movs r1, 0
	strh r1, [r0, 0x8]
	str r6, [r0]
	strb r4, [r0, 0x4]
	bl GetMultiplayerId
	ldr r1, [r5]
	strb r0, [r1, 0x6]
	ldr r0, [r5]
	ldrb r2, [r0, 0x6]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	ldr r2, =0x000082a8
	adds r1, r2
	adds r0, r1
	movs r1, 0x64
	muls r1, r7
	ldr r2, =gPlayerParty
	adds r1, r2
	bl sub_802AC2C
	ldr r0, [r5]
	bl sub_802AA60
	ldr r2, [r5]
	adds r0, r4, 0
	movs r1, 0x2
	bl SetWordTaskArg
	ldr r0, =sub_802AC6C
	bl SetMainCallback2
	b _0802AA42
	.pool
_0802AA3C:
	adds r0, r6, 0
	bl SetMainCallback2
_0802AA42:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802A9A8

	thumb_func_start sub_802AA48
sub_802AA48: @ 802AA48
	push {lr}
	bl sub_802D0AC
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AA48

	thumb_func_start sub_802AA60
sub_802AA60: @ 802AA60
	push {r4,lr}
	adds r4, r0, 0
	bl GetLinkPlayerCount
	movs r2, 0
	strb r0, [r4, 0x5]
	adds r1, r4, 0
	adds r1, 0x70
	movs r0, 0x5
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x72
	strh r2, [r0]
	bl sub_802AB20
	adds r0, r4, 0
	bl sub_802AA94
	ldrb r0, [r4, 0x5]
	cmp r0, 0x5
	bne _0802AA8E
	bl sub_802E3A8
_0802AA8E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802AA60

	thumb_func_start sub_802AA94
sub_802AA94: @ 802AA94
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x6
	str r0, [r4, 0x14]
	str r0, [r4, 0x18]
	adds r0, r4, 0
	adds r0, 0x4A
	movs r6, 0
	movs r5, 0
	strh r5, [r0]
	str r5, [r4, 0x1C]
	str r5, [r4, 0x5C]
	bl GetMultiplayerId
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0802AABA
	movs r1, 0x1
_0802AABA:
	adds r0, r4, 0
	adds r0, 0x47
	strb r1, [r0]
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	str r5, [r4, 0x58]
	strh r5, [r4, 0x3A]
	subs r0, 0x3
	strb r6, [r0]
	str r5, [r4, 0x54]
	adds r0, 0x2
	strb r6, [r0]
	adds r0, 0x3
	strb r6, [r0]
	subs r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	str r5, [r4, 0x78]
	adds r0, 0x29
	strb r6, [r0]
	adds r0, 0x3
	strh r5, [r0]
	str r1, [r4, 0x60]
	subs r0, 0x27
	strb r6, [r0]
	str r5, [r4, 0x68]
	str r5, [r4, 0x64]
	str r5, [r4, 0x2C]
	str r5, [r4, 0x30]
	bl sub_802AB98
	bl sub_802C0E8
	movs r2, 0
	adds r5, r4, 0
	adds r5, 0x7C
	movs r3, 0
	adds r1, r4, 0
	adds r1, 0x9A
_0802AB0C:
	adds r0, r5, r2
	strb r3, [r0]
	strh r3, [r1]
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x4
	ble _0802AB0C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802AA94

	thumb_func_start sub_802AB20
sub_802AB20: @ 802AB20
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r7, =gUnknown_02022CFC
	movs r6, 0
	movs r5, 0
	ldr r0, =gPkmnJumpSpecies
	mov r8, r0
	movs r4, 0x4
_0802AB32:
	ldr r0, [r7]
	adds r0, r5
	ldr r1, =0x000082a8
	adds r0, r1
	ldrh r0, [r0]
	bl sub_802AC00
	lsls r0, 16
	ldr r1, [r7]
	adds r1, r6
	asrs r0, 14
	add r0, r8
	ldrh r0, [r0, 0x2]
	ldr r2, =0x000082f0
	adds r1, r2
	strh r0, [r1]
	adds r6, 0x28
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _0802AB32
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldr r0, =0x000083ac
	adds r3, r1, r0
	ldrb r2, [r1, 0x6]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r2, =0x000082e4
	adds r0, r2
	adds r1, r0
	str r1, [r3]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AB20

	thumb_func_start sub_802AB98
sub_802AB98: @ 802AB98
	push {r4-r7,lr}
	movs r5, 0
	ldr r6, =gUnknown_02022CFC
	movs r4, 0
	movs r3, 0
_0802ABA2:
	ldr r2, [r6]
	adds r1, r2, r3
	ldr r7, =0x000082f2
	adds r0, r1, r7
	strh r4, [r0]
	adds r7, 0x2
	adds r0, r1, r7
	strh r4, [r0]
	ldr r0, =0x000082f6
	adds r1, r0
	strh r4, [r1]
	ldr r1, =0x000082e4
	adds r0, r2, r1
	adds r0, r3
	str r4, [r0]
	subs r7, 0xC
	adds r0, r2, r7
	adds r0, r3
	ldr r1, =0x7fffffff
	str r1, [r0]
	ldr r1, =0x000082f8
	adds r0, r2, r1
	adds r0, r3
	str r4, [r0]
	adds r2, 0x8B
	adds r2, r5
	movs r0, 0x9
	strb r0, [r2]
	adds r3, 0x28
	adds r5, 0x1
	cmp r5, 0x4
	ble _0802ABA2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AB98

	thumb_func_start sub_802AC00
sub_802AC00: @ 802AC00
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0
	ldr r2, =gPkmnJumpSpecies
_0802AC0A:
	ldrh r0, [r2]
	cmp r0, r3
	bne _0802AC1C
	lsls r0, r1, 16
	asrs r0, 16
	b _0802AC28
	.pool
_0802AC1C:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0x63
	bls _0802AC0A
	movs r0, 0x1
	negs r0, r0
_0802AC28:
	pop {r1}
	bx r1
	thumb_func_end sub_802AC00

	thumb_func_start sub_802AC2C
sub_802AC2C: @ 802AC2C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r5, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802AC2C

	thumb_func_start sub_802AC58
sub_802AC58: @ 802AC58
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	thumb_func_end sub_802AC58

	thumb_func_start sub_802AC6C
sub_802AC6C: @ 802AC6C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_802AC6C

	thumb_func_start sub_802AC84
sub_802AC84: @ 802AC84
	push {lr}
	movs r1, 0x1
	bl CreateTask
	ldr r2, =gUnknown_02022CFC
	ldr r1, [r2]
	movs r3, 0
	strb r0, [r1, 0x4]
	ldr r0, [r2]
	strh r3, [r0, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AC84

	thumb_func_start sub_802ACA0
sub_802ACA0: @ 802ACA0
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0x8]
	adds r2, r1, 0
	cmp r0, 0x5
	bls _0802ACB6
	b _0802AE08
_0802ACB6:
	lsls r0, 2
	ldr r1, =_0802ACC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802ACC8:
	.4byte _0802ACE0
	.4byte _0802AD0C
	.4byte _0802AD3C
	.4byte _0802AD68
	.4byte _0802ADA4
	.4byte _0802ADD0
_0802ACE0:
	movs r0, 0
	bl SetVBlankCallback
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =sub_802BD84
	movs r1, 0x5
	bl sub_802BE60
	movs r0, 0x4
	bl FadeOutMapMusic
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	b _0802ADC0
	.pool
_0802AD0C:
	ldr r0, =sub_802BD84
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0802AE08
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	adds r0, 0xA4
	bl sub_802D074
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl CreateWirelessStatusIndicatorSprite
	ldr r1, [r4]
	b _0802ADC0
	.pool
_0802AD3C:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802AE08
	bl IsNotWaitingForBGMStop
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802AE08
	ldr r0, =0x0000021a
	movs r1, 0x8
	bl FadeOutAndPlayNewMapMusic
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	b _0802ADC0
	.pool
_0802AD68:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802AE08
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_802AC58
	bl SetVBlankCallback
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	b _0802ADC0
	.pool
_0802ADA4:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0802AE08
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	strb r2, [r0, 0x7]
	ldr r1, [r1]
_0802ADC0:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802AE08
	.pool
_0802ADD0:
	ldr r0, [r2]
	ldrb r1, [r0, 0x7]
	adds r1, 0x1
	strb r1, [r0, 0x7]
	ldr r1, [r2]
	ldrb r0, [r1, 0x7]
	cmp r0, 0x13
	bls _0802AE08
	adds r0, r1, 0
	adds r0, 0x47
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802ADF8
	ldr r0, =sub_802AF80
	bl sub_802AC84
	b _0802ADFE
	.pool
_0802ADF8:
	ldr r0, =sub_802B194
	bl sub_802AC84
_0802ADFE:
	bl sub_802BE80
	adds r0, r4, 0
	bl DestroyTask
_0802AE08:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802ACA0

	thumb_func_start sub_802AE14
sub_802AE14: @ 802AE14
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	bne _0802AE34
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldr r0, =0x00001111
	str r0, [r1, 0x30]
	movs r0, 0x1
	str r0, [r1, 0x2C]
	b _0802AE46
	.pool
_0802AE34:
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	subs r1, 0x1
	movs r0, 0x1
	lsls r0, r1
	subs r0, 0x1
	str r0, [r2, 0x30]
	movs r0, 0
	str r0, [r2, 0x2C]
_0802AE46:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AE14

	thumb_func_start sub_802AE50
sub_802AE50: @ 802AE50
	push {r4-r6,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	adds r1, 0x70
	movs r2, 0
	strb r0, [r1]
	ldr r0, [r4]
	movs r3, 0
	strh r2, [r0, 0x8]
	strh r2, [r0, 0xA]
	adds r0, 0x48
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x49
	strb r3, [r0]
	movs r3, 0x1
	ldr r0, [r4]
	ldrb r0, [r0, 0x5]
	cmp r3, r0
	bge _0802AE94
	adds r6, r4, 0
	ldr r5, =0x000082fc
	movs r4, 0
	movs r2, 0x28
_0802AE82:
	ldr r1, [r6]
	adds r0, r1, r5
	adds r0, r2
	str r4, [r0]
	adds r2, 0x28
	adds r3, 0x1
	ldrb r1, [r1, 0x5]
	cmp r3, r1
	blt _0802AE82
_0802AE94:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AE50

	thumb_func_start sub_802AEA4
sub_802AEA4: @ 802AEA4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r4, 0x1
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r7, =gUnknown_02022CFC
	ldr r0, [r7]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	bge _0802AF48
	adds r1, r7, 0
	mov r10, r1
	movs r2, 0x2
	add r2, sp
	mov r8, r2
	ldr r3, =0x0000830c
	mov r9, r3
	movs r6, 0x28
_0802AED0:
	mov r1, r10
	ldr r0, [r1]
	adds r1, r0, r6
	ldr r2, =0x000082f4
	adds r1, r2
	ldrh r5, [r1]
	add r0, r9
	adds r1, r4, 0
	mov r2, sp
	mov r3, r8
	bl sub_802E264
	cmp r0, 0
	beq _0802AF10
	ldr r2, [r7]
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x90
	adds r0, r1
	mov r3, r8
	ldrh r1, [r3]
	strh r1, [r0]
	adds r2, 0x8B
	adds r2, r4
	mov r0, sp
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, [r7]
	adds r0, r6
	ldr r1, =0x000082f6
	adds r0, r1
	strh r5, [r0]
_0802AF10:
	mov r2, r10
	ldr r1, [r2]
	ldr r3, =0x000082fc
	adds r0, r1, r3
	adds r0, r6
	ldr r0, [r0]
	cmp r0, 0
	beq _0802AF36
	adds r0, r1, 0
	adds r0, 0x8B
	adds r0, r4
	adds r1, 0x70
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0802AF36
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x4]
_0802AF36:
	movs r1, 0x28
	add r9, r1
	adds r6, 0x28
	adds r4, 0x1
	ldr r7, =gUnknown_02022CFC
	ldr r0, [r7]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	blt _0802AED0
_0802AF48:
	ldr r2, =gUnknown_02022CFC
	ldr r1, [r2]
	ldrb r0, [r1, 0x5]
	subs r0, 0x1
	ldr r3, [sp, 0x4]
	cmp r3, r0
	bne _0802AF5C
	adds r1, 0x49
	movs r0, 0x1
	strb r0, [r1]
_0802AF5C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AEA4

	thumb_func_start sub_802AF80
sub_802AF80: @ 802AF80
	push {r4,r5,lr}
	bl sub_802AEA4
	bl sub_802C43C
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802AFB2
	adds r0, r1, 0
	adds r0, 0x49
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802AFB2
	adds r0, r1, 0
	adds r0, 0x4C
	ldrb r0, [r0]
	bl sub_802AE50
	movs r0, 0x3
	bl sub_802AE14
_0802AFB2:
	ldr r4, =gUnknown_02022CFC
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x48
	ldrb r5, [r0]
	cmp r5, 0x1
	bne _0802AFEE
	ldr r1, =gUnknown_082FB5F4
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	adds r1, r0, 0
	cmp r1, 0
	bne _0802AFEE
	ldr r0, [r4]
	adds r0, 0x48
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r2, [r1, 0x6]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r2, =0x000082fc
	adds r1, r2
	adds r1, r0
	str r5, [r1]
_0802AFEE:
	bl sub_802C1DC
	bl sub_802B008
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802AF80

	thumb_func_start sub_802B008
sub_802B008: @ 802B008
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldr r0, [r1, 0x2C]
	cmp r0, 0
	bne _0802B01E
	ldr r2, =0x000082e4
	adds r0, r1, r2
	adds r1, 0x70
	bl sub_802E138
_0802B01E:
	ldr r1, [r4]
	ldr r2, [r1, 0x30]
	ldr r0, =0x00001111
	cmp r2, r0
	beq _0802B030
	ldr r0, [r1, 0x2C]
	adds r0, 0x1
	ands r0, r2
	str r0, [r1, 0x2C]
_0802B030:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802B008

	thumb_func_start sub_802B044
sub_802B044: @ 802B044
	ldr r2, =gUnknown_02022CFC
	ldr r1, [r2]
	adds r1, 0x70
	movs r3, 0
	strb r0, [r1]
	ldr r0, [r2]
	strh r3, [r0, 0x8]
	strh r3, [r0, 0xA]
	adds r0, 0x48
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, [r2]
	ldrb r2, [r1, 0x6]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r2, =0x000082fc
	adds r1, r2
	adds r1, r0
	str r3, [r1]
	bx lr
	.pool
	thumb_func_end sub_802B044

	thumb_func_start sub_802B078
sub_802B078: @ 802B078
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldr r2, =0x000082f4
	adds r1, r0, r2
	ldrh r1, [r1]
	mov r8, r1
	ldr r3, =0x000082e4
	adds r0, r3
	mov r1, sp
	bl sub_802E1BC
	cmp r0, 0
	beq _0802B128
	ldr r2, [r4]
	ldrb r0, [r2, 0x6]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r3, =0x000082fc
	adds r0, r2, r3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0802B0C6
	mov r0, sp
	adds r1, r2, 0
	adds r1, 0x70
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0802B0C6
	mov r0, sp
	ldrb r0, [r0]
	bl sub_802B044
_0802B0C6:
	ldr r3, =gUnknown_02022CFC
	ldr r2, [r3]
	ldr r0, [r2, 0x78]
	ldr r1, [sp, 0x8]
	cmp r0, r1
	beq _0802B108
	str r1, [r2, 0x78]
	movs r4, 0x1
	str r4, [r2, 0x5C]
	mov r0, sp
	ldrb r1, [r0, 0x1]
	adds r0, r2, 0
	adds r0, 0x71
	strb r1, [r0]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x71
	ldrb r1, [r1]
	cmp r1, 0
	beq _0802B104
	adds r0, 0x4D
	strb r4, [r0]
	b _0802B108
	.pool
_0802B104:
	adds r0, 0x4D
	strb r1, [r0]
_0802B108:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	mov r0, sp
	ldrh r0, [r0, 0x2]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	mov r0, sp
	ldrh r2, [r0, 0x4]
	adds r0, r1, 0
	adds r0, 0x74
	strh r2, [r0]
	ldr r0, =0x000082f6
	adds r1, r0
	mov r2, r8
	strh r2, [r1]
_0802B128:
	movs r4, 0x1
	ldr r2, =gUnknown_02022CFC
	ldr r0, [r2]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	bge _0802B176
	adds r7, r2, 0
	ldr r6, =0x0000830c
	movs r5, 0x28
_0802B13A:
	ldr r1, [r7]
	ldrb r3, [r1, 0x6]
	cmp r4, r3
	beq _0802B168
	adds r0, r1, r5
	ldr r3, =0x000082f4
	adds r0, r3
	ldrh r0, [r0]
	mov r8, r0
	adds r0, r1, r6
	adds r1, r4, 0
	str r2, [sp, 0xC]
	bl sub_802E2D0
	ldr r2, [sp, 0xC]
	cmp r0, 0
	beq _0802B168
	ldr r0, [r7]
	adds r0, r5
	ldr r1, =0x000082f6
	adds r0, r1
	mov r3, r8
	strh r3, [r0]
_0802B168:
	adds r6, 0x28
	adds r5, 0x28
	adds r4, 0x1
	ldr r0, [r2]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	blt _0802B13A
_0802B176:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802B078

	thumb_func_start sub_802B194
sub_802B194: @ 802B194
	push {r4,lr}
	bl sub_802B078
	ldr r4, =gUnknown_02022CFC
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802B1E0
	ldr r1, =gUnknown_082FB618
	adds r0, r2, 0
	adds r0, 0x70
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	adds r1, r0, 0
	cmp r1, 0
	bne _0802B1E0
	ldr r0, [r4]
	adds r0, 0x48
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r2, [r1, 0x6]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r2, =0x000082fc
	adds r1, r2
	adds r1, r0
	movs r0, 0x1
	str r0, [r1]
	movs r0, 0x3
	bl sub_802AE14
_0802B1E0:
	bl sub_802C1DC
	bl sub_802B1FC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802B194

	thumb_func_start sub_802B1FC
sub_802B1FC: @ 802B1FC
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r2, [r4]
	ldr r0, [r2, 0x2C]
	cmp r0, 0
	bne _0802B224
	ldrb r1, [r2, 0x6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =0x000082e4
	adds r0, r1
	adds r0, r2, r0
	adds r1, r2, 0
	adds r1, 0x70
	ldrb r1, [r1]
	adds r2, 0x42
	ldrh r2, [r2]
	bl sub_802E234
_0802B224:
	ldr r1, [r4]
	ldr r2, [r1, 0x30]
	ldr r0, =0x00001111
	cmp r2, r0
	beq _0802B236
	ldr r0, [r1, 0x2C]
	adds r0, 0x1
	ands r0, r2
	str r0, [r1, 0x2C]
_0802B236:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802B1FC

	thumb_func_start sub_802B248
sub_802B248: @ 802B248
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B260
	cmp r0, 0x1
	beq _0802B26E
	b _0802B294
	.pool
_0802B260:
	movs r0, 0x3
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B26E:
	bl sub_802B7E0
	cmp r0, 0
	bne _0802B294
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x4A
	ldrh r0, [r0]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	adds r1, 0x4C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	b _0802B296
	.pool
_0802B294:
	movs r0, 0x1
_0802B296:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B248

	thumb_func_start sub_802B29C
sub_802B29C: @ 802B29C
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B2B4
	cmp r0, 0x1
	beq _0802B2CA
	movs r0, 0x1
	b _0802B2CE
	.pool
_0802B2B4:
	movs r0, 0
	bl sub_802AE14
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x72
	ldrh r0, [r0]
	str r0, [r1, 0x24]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B2CA:
	bl sub_802B7E0
_0802B2CE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B29C

	thumb_func_start sub_802B2D4
sub_802B2D4: @ 802B2D4
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	beq _0802B2EC
	cmp r0, 0x1
	beq _0802B300
	b _0802B314
	.pool
_0802B2EC:
	bl sub_802C0E8
	movs r0, 0x5
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B314
_0802B300:
	adds r0, r1, 0
	adds r0, 0x49
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802B314
	adds r1, 0x4C
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0
	b _0802B316
_0802B314:
	movs r0, 0x1
_0802B316:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B2D4

	thumb_func_start sub_802B31C
sub_802B31C: @ 802B31C
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B334
	cmp r0, 0x1
	beq _0802B352
	b _0802B35E
	.pool
_0802B334:
	bl sub_802C0E8
	movs r0, 0
	bl sub_802AE14
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x72
	ldrh r0, [r0]
	adds r2, r1, 0
	adds r2, 0x4A
	strh r0, [r2]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B352:
	bl sub_802C70C
	cmp r0, 0
	beq _0802B35E
	movs r0, 0
	b _0802B360
_0802B35E:
	movs r0, 0x1
_0802B360:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B31C

	thumb_func_start sub_802B368
sub_802B368: @ 802B368
	push {lr}
	bl sub_802B8CC
	cmp r0, 0
	bne _0802B390
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x4A
	ldrh r0, [r0]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	adds r1, 0x4C
	movs r0, 0x1
	strb r0, [r1]
	b _0802B3AA
	.pool
_0802B390:
	bl sub_802C538
	cmp r0, 0
	beq _0802B39C
	movs r0, 0x1
	b _0802B3AC
_0802B39C:
	bl sub_802C0B8
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x4C
	movs r1, 0x3
	strb r1, [r0]
_0802B3AA:
	movs r0, 0
_0802B3AC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802B368

	thumb_func_start sub_802B3B4
sub_802B3B4: @ 802B3B4
	push {lr}
	bl sub_802B8CC
	cmp r0, 0
	beq _0802B3CE
	bl sub_802C538
	cmp r0, 0
	beq _0802B3CA
	movs r0, 0x1
	b _0802B3D0
_0802B3CA:
	bl sub_802C0B8
_0802B3CE:
	movs r0, 0
_0802B3D0:
	pop {r1}
	bx r1
	thumb_func_end sub_802B3B4

	thumb_func_start sub_802B3D4
sub_802B3D4: @ 802B3D4
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0802B40C
	cmp r0, 0x1
	bgt _0802B3F0
	cmp r0, 0
	beq _0802B3F6
	b _0802B468
	.pool
_0802B3F0:
	cmp r0, 0x2
	beq _0802B460
	b _0802B468
_0802B3F6:
	bl sub_802C538
	bl sub_802C5DC
	cmp r0, 0
	beq _0802B468
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B468
_0802B40C:
	bl sub_802B964
	cmp r0, 0
	bne _0802B468
	bl sub_802C7BC
	cmp r0, 0
	beq _0802B42E
	bl sub_802C7E0
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	adds r1, 0x4C
	movs r0, 0x7
	b _0802B454
_0802B42E:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0xC7
	bls _0802B448
	ldrh r0, [r1, 0xE]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	adds r1, 0x4C
	movs r0, 0x8
	b _0802B454
_0802B448:
	ldrh r0, [r1, 0xE]
	adds r2, r1, 0
	adds r2, 0x72
	strh r0, [r2]
	adds r1, 0x4C
	movs r0, 0x4
_0802B454:
	strb r0, [r1]
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B460:
	movs r0, 0
	b _0802B46A
	.pool
_0802B468:
	movs r0, 0x1
_0802B46A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B3D4

	thumb_func_start sub_802B470
sub_802B470: @ 802B470
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0802B4B0
	cmp r0, 0x1
	bgt _0802B48C
	cmp r0, 0
	beq _0802B492
	b _0802B4C4
	.pool
_0802B48C:
	cmp r0, 0x2
	beq _0802B4C0
	b _0802B4C4
_0802B492:
	bl sub_802C538
	cmp r0, 0
	bne _0802B49E
	bl sub_802C0B8
_0802B49E:
	bl sub_802C5DC
	cmp r0, 0
	beq _0802B4C4
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B4C4
_0802B4B0:
	bl sub_802B964
	cmp r0, 0
	bne _0802B4C4
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B4C0:
	movs r0, 0
	b _0802B4C6
_0802B4C4:
	movs r0, 0x1
_0802B4C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B470

	thumb_func_start sub_802B4CC
sub_802B4CC: @ 802B4CC
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r1, [r0, 0x8]
	cmp r1, 0x1
	beq _0802B500
	cmp r1, 0x1
	bgt _0802B4E8
	cmp r1, 0
	beq _0802B4F2
	b _0802B560
	.pool
_0802B4E8:
	cmp r1, 0x2
	beq _0802B52C
	cmp r1, 0x3
	beq _0802B556
	b _0802B560
_0802B4F2:
	movs r0, 0x4
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B500:
	bl sub_802BB84
	cmp r0, 0
	bne _0802B560
	ldr r4, =gUnknown_02022CFC
	ldr r2, [r4]
	ldr r0, [r2, 0x78]
	adds r1, r2, 0
	adds r1, 0x74
	ldrh r1, [r1]
	adds r2, 0x72
	ldrh r2, [r2]
	bl sub_802E354
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B560
	.pool
_0802B52C:
	adds r0, 0x49
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802B560
	bl sub_802C650
	cmp r0, 0
	beq _0802B544
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x5
	b _0802B54A
_0802B544:
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x6
_0802B54A:
	strb r1, [r0]
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B556:
	movs r0, 0
	b _0802B562
	.pool
_0802B560:
	movs r0, 0x1
_0802B562:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B4CC

	thumb_func_start sub_802B568
sub_802B568: @ 802B568
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B580
	cmp r0, 0x1
	beq _0802B58E
	b _0802B5C0
	.pool
_0802B580:
	movs r0, 0
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B58E:
	bl sub_802BB84
	cmp r0, 0
	bne _0802B5C0
	ldr r4, =gUnknown_02022CFC
	ldr r2, [r4]
	ldr r0, [r2, 0x78]
	adds r1, r2, 0
	adds r1, 0x74
	ldrh r1, [r1]
	adds r2, 0x72
	ldrh r2, [r2]
	bl sub_802E354
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x45
	ldrb r1, [r1]
	adds r0, 0x42
	strh r1, [r0]
	movs r0, 0
	b _0802B5C2
	.pool
_0802B5C0:
	movs r0, 0x1
_0802B5C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B568

	thumb_func_start sub_802B5C8
sub_802B5C8: @ 802B5C8
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	beq _0802B5E0
	cmp r0, 0x1
	beq _0802B5F2
	b _0802B61E
	.pool
_0802B5E0:
	bl sub_802BD30
	cmp r0, 0
	bne _0802B61E
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B61E
_0802B5F2:
	adds r0, r1, 0
	adds r0, 0x49
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802B61E
	adds r0, r1, 0
	bl sub_802AA94
	bl Random
	ldr r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	str r0, [r1, 0x24]
	adds r3, r1, 0
	adds r3, 0x72
	movs r2, 0
	strh r0, [r3]
	adds r1, 0x4C
	strb r2, [r1]
	movs r0, 0
	b _0802B620
_0802B61E:
	movs r0, 0x1
_0802B620:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B5C8

	thumb_func_start sub_802B628
sub_802B628: @ 802B628
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B640
	cmp r0, 0x1
	beq _0802B656
	b _0802B65A
	.pool
_0802B640:
	bl sub_802BD30
	cmp r0, 0
	bne _0802B65A
	ldr r0, [r4]
	bl sub_802AA94
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0802B656:
	movs r0, 0
	b _0802B65C
_0802B65A:
	movs r0, 0x1
_0802B65C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B628

	thumb_func_start sub_802B664
sub_802B664: @ 802B664
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	cmp r0, 0x1
	beq _0802B68C
	cmp r0, 0x1
	bgt _0802B680
	cmp r0, 0
	beq _0802B686
	b _0802B6B0
	.pool
_0802B680:
	cmp r0, 0x2
	beq _0802B69C
	b _0802B6B0
_0802B686:
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B6B0
_0802B68C:
	movs r0, 0
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B6B0
_0802B69C:
	bl sub_802BC60
	cmp r0, 0
	bne _0802B6B0
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	bl sub_802AA48
_0802B6B0:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B664

	thumb_func_start sub_802B6B8
sub_802B6B8: @ 802B6B8
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _0802B6D0
	cmp r0, 0x1
	beq _0802B6E0
	b _0802B6FC
	.pool
_0802B6D0:
	movs r0, 0x4
	bl sub_802AE14
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B6FC
_0802B6E0:
	bl sub_802BA58
	cmp r0, 0
	bne _0802B6FC
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	adds r2, r0, 0
	adds r2, 0x72
	strh r1, [r2]
	adds r0, 0x4C
	movs r1, 0x8
	strb r1, [r0]
	movs r0, 0
	b _0802B6FE
_0802B6FC:
	movs r0, 0x1
_0802B6FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B6B8

	thumb_func_start sub_802B704
sub_802B704: @ 802B704
	push {lr}
	movs r0, 0
	bl sub_802AE14
	bl sub_802BA58
	cmp r0, 0
	beq _0802B718
	movs r0, 0x1
	b _0802B71A
_0802B718:
	movs r0, 0
_0802B71A:
	pop {r1}
	bx r1
	thumb_func_end sub_802B704

	thumb_func_start sub_802B720
sub_802B720: @ 802B720
	push {r4,lr}
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0x8]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0802B7D8
	lsls r0, 2
	ldr r1, =_0802B740
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802B740:
	.4byte _0802B754
	.4byte _0802B770
	.4byte _0802B780
	.4byte _0802B798
	.4byte _0802B7BC
_0802B754:
	ldr r2, [r4]
	ldr r0, [r2, 0x78]
	adds r1, r2, 0
	adds r1, 0x74
	ldrh r1, [r1]
	adds r2, 0x72
	ldrh r2, [r2]
	bl sub_802E354
	movs r0, 0x5
	bl sub_802D0C8
	ldr r1, [r4]
	b _0802B7AC
_0802B770:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802B7D8
	movs r0, 0
	bl sub_802AE14
	b _0802B7A8
_0802B780:
	bl sub_802C70C
	cmp r0, 0
	beq _0802B7D8
	ldr r0, =sub_8153688
	movs r1, 0x6
	bl CreateTask
	b _0802B7A8
	.pool
_0802B798:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0802B7D8
	bl sub_802DA14
_0802B7A8:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
_0802B7AC:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0802B7D8
	.pool
_0802B7BC:
	bl sub_802DA44
	cmp r0, 0
	bne _0802B7D8
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x4C
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0
	b _0802B7DA
	.pool
_0802B7D8:
	movs r0, 0x1
_0802B7DA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802B720

	thumb_func_start sub_802B7E0
sub_802B7E0: @ 802B7E0
	push {r4,r5,lr}
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0xA]
	adds r4, r1, 0
	cmp r0, 0x7
	bhi _0802B8C4
	lsls r0, 2
	ldr r1, =_0802B800
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802B800:
	.4byte _0802B820
	.4byte _0802B82C
	.4byte _0802B84C
	.4byte _0802B866
	.4byte _0802B878
	.4byte _0802B880
	.4byte _0802B8A0
	.4byte _0802B8BA
_0802B820:
	movs r0, 0x2
	bl sub_802D0C8
	bl sub_802DDE0
	b _0802B890
_0802B82C:
	bl sub_802D0F0
	adds r5, r0, 0
	cmp r5, 0
	bne _0802B8C4
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	bl sub_802DDF4
	ldr r1, [r4]
	strh r5, [r1, 0x3C]
	b _0802B894
	.pool
_0802B84C:
	ldr r1, [r4]
	ldrh r0, [r1, 0x3C]
	adds r0, 0x1
	strh r0, [r1, 0x3C]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x78
	bls _0802B8C4
	movs r0, 0x3
	bl sub_802D0C8
	ldr r1, [r4]
	b _0802B894
_0802B866:
	bl sub_802D0F0
	cmp r0, 0x1
	beq _0802B8C4
	bl sub_802DE08
	cmp r0, 0x1
	beq _0802B8C4
	b _0802B890
_0802B878:
	movs r0, 0x9
	bl sub_802D0C8
	b _0802B890
_0802B880:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802B8C4
	bl sub_802C260
	bl sub_802D764
_0802B890:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
_0802B894:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802B8C4
	.pool
_0802B8A0:
	bl sub_802D788
	cmp r0, 0
	bne _0802B8C4
	bl sub_802C270
	bl sub_802BEA0
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0802B8BA:
	movs r0, 0
	b _0802B8C6
	.pool
_0802B8C4:
	movs r0, 0x1
_0802B8C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802B7E0

	thumb_func_start sub_802B8CC
sub_802B8CC: @ 802B8CC
	push {r4,r5,lr}
	bl sub_802BEE4
	ldr r5, =gUnknown_02022CFC
	ldr r1, [r5]
	ldrh r4, [r1, 0x36]
	cmp r4, 0
	beq _0802B8E8
	movs r0, 0
	strh r0, [r1, 0x36]
	b _0802B95C
	.pool
_0802B8E8:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x1
	beq _0802B914
	cmp r0, 0x1
	bgt _0802B8F8
	cmp r0, 0
	beq _0802B902
	b _0802B95A
_0802B8F8:
	cmp r0, 0x2
	beq _0802B938
	cmp r0, 0x3
	beq _0802B94C
	b _0802B95A
_0802B902:
	movs r0, 0
	bl sub_802C130
	cmp r0, 0
	beq _0802B95A
	ldr r1, [r5]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0802B914:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0802B95A
	bl sub_802C164
	movs r0, 0x3
	bl sub_802AE14
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	b _0802B944
	.pool
_0802B938:
	movs r0, 0x1
	bl sub_802C130
	cmp r0, 0x1
	bne _0802B95A
	ldr r1, [r5]
_0802B944:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802B95A
_0802B94C:
	movs r0, 0
	bl sub_802C130
	cmp r0, 0x1
	bne _0802B95A
	ldr r0, [r5]
	strh r4, [r0, 0xA]
_0802B95A:
	movs r0, 0x1
_0802B95C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802B8CC

	thumb_func_start sub_802B964
sub_802B964: @ 802B964
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0xA]
	adds r5, r1, 0
	cmp r0, 0x4
	bhi _0802BA50
	lsls r0, 2
	ldr r1, =_0802B984
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802B984:
	.4byte _0802B998
	.4byte _0802B9BC
	.4byte _0802BA00
	.4byte _0802BA24
	.4byte _0802BA46
_0802B998:
	movs r4, 0
	ldr r0, [r5]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	bge _0802B9B8
	adds r6, r5, 0
_0802B9A4:
	adds r0, r4, 0
	bl sub_802DDB8
	cmp r0, 0x1
	beq _0802BA50
	adds r4, 0x1
	ldr r0, [r6]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	blt _0802B9A4
_0802B9B8:
	ldr r1, [r5]
	b _0802BA1C
_0802B9BC:
	movs r4, 0
	ldr r0, [r5]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	bge _0802B9EC
	adds r6, r5, 0
	movs r5, 0
_0802B9CA:
	ldr r0, [r6]
	adds r0, r5
	ldr r1, =0x000082f4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _0802B9E0
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_802DDA0
_0802B9E0:
	adds r5, 0x28
	adds r4, 0x1
	ldr r0, [r6]
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	blt _0802B9CA
_0802B9EC:
	movs r0, 0x1
	bl sub_802D0C8
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	b _0802BA18
	.pool
_0802BA00:
	ldr r1, [r5]
	ldrh r0, [r1, 0x3C]
	adds r0, 0x1
	strh r0, [r1, 0x3C]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x64
	bls _0802BA50
	movs r0, 0x3
	bl sub_802D0C8
	ldr r1, [r5]
_0802BA18:
	movs r0, 0
	strh r0, [r1, 0x3C]
_0802BA1C:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802BA50
_0802BA24:
	bl sub_802D0F0
	adds r5, r0, 0
	cmp r5, 0
	bne _0802BA50
	bl sub_802DDCC
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	adds r0, 0x71
	strb r5, [r0]
	bl sub_802C114
	ldr r1, [r4]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0802BA46:
	movs r0, 0
	b _0802BA52
	.pool
_0802BA50:
	movs r0, 0x1
_0802BA52:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802B964

	thumb_func_start sub_802BA58
sub_802BA58: @ 802BA58
	push {r4,lr}
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0xA]
	adds r4, r1, 0
	cmp r0, 0x6
	bls _0802BA68
	b _0802BB7C
_0802BA68:
	lsls r0, 2
	ldr r1, =_0802BA7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802BA7C:
	.4byte _0802BA98
	.4byte _0802BAB8
	.4byte _0802BAD0
	.4byte _0802BB00
	.4byte _0802BAB8
	.4byte _0802BAD0
	.4byte _0802BB70
_0802BA98:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x72
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x3E
	adds r2, 0x40
	bl sub_802C808
	ldr r1, [r4]
	ldrh r0, [r1, 0x3E]
	adds r1, 0x40
	ldrh r1, [r1]
	bl sub_802D7E8
	b _0802BAF0
_0802BAB8:
	bl sub_802D974
	adds r2, r0, 0
	cmp r2, 0
	bne _0802BB7C
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	strh r2, [r1, 0x3C]
	b _0802BAF2
	.pool
_0802BAD0:
	ldr r1, [r4]
	ldrh r0, [r1, 0x3C]
	adds r2, r0, 0x1
	strh r2, [r1, 0x3C]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0802BAEC
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0xB4
	bls _0802BB7C
_0802BAEC:
	bl sub_802DA14
_0802BAF0:
	ldr r1, [r4]
_0802BAF2:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802BB7C
	.pool
_0802BB00:
	bl sub_802DA44
	cmp r0, 0
	bne _0802BB7C
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldrh r0, [r1, 0x3E]
	adds r1, 0x40
	ldrh r1, [r1]
	bl sub_802C880
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0x40
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	beq _0802BB58
	ldrh r0, [r1, 0x3E]
	ldrh r1, [r2]
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	beq _0802BB58
	ldr r0, [r4]
	ldrh r0, [r0, 0x3E]
	movs r1, 0x1
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	bne _0802BB50
	ldr r0, [r4]
	ldrh r0, [r0, 0x3E]
	bl sub_802D884
	b _0802BB62
	.pool
_0802BB50:
	ldr r1, [r4]
	movs r0, 0x6
	strh r0, [r1, 0xA]
	b _0802BB7C
_0802BB58:
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0x3E]
	bl sub_802D8FC
_0802BB62:
	ldr r1, [r4]
	movs r0, 0x4
	strh r0, [r1, 0xA]
	b _0802BB7C
	.pool
_0802BB70:
	bl sub_802DA44
	cmp r0, 0
	bne _0802BB7C
	movs r0, 0
	b _0802BB7E
_0802BB7C:
	movs r0, 0x1
_0802BB7E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802BA58

	thumb_func_start sub_802BB84
sub_802BB84: @ 802BB84
	push {r4,lr}
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x6
	bhi _0802BC58
	lsls r0, 2
	ldr r1, =_0802BBA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802BBA4:
	.4byte _0802BBC0
	.4byte _0802BBC4
	.4byte _0802BBCE
	.4byte _0802BC1C
	.4byte _0802BC26
	.4byte _0802BC3C
	.4byte _0802BC4E
_0802BBC0:
	movs r0, 0x4
	b _0802BC28
_0802BBC4:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802BC58
	b _0802BC2C
_0802BBCE:
	bl sub_802DA8C
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0802BC04
	cmp r1, 0
	bgt _0802BBE8
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0802BBEC
	b _0802BC58
_0802BBE8:
	cmp r1, 0x1
	bne _0802BC58
_0802BBEC:
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	adds r0, 0x45
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x6
	bl sub_802D0C8
	ldr r1, [r4]
	b _0802BC30
	.pool
_0802BC04:
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	adds r0, 0x45
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x6
	bl sub_802D0C8
	ldr r1, [r4]
	b _0802BC30
	.pool
_0802BC1C:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802BC58
	b _0802BC2C
_0802BC26:
	movs r0, 0x8
_0802BC28:
	bl sub_802D0C8
_0802BC2C:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
_0802BC30:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802BC58
	.pool
_0802BC3C:
	bl sub_802D0F0
	cmp r0, 0
	bne _0802BC58
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0802BC4E:
	movs r0, 0
	b _0802BC5A
	.pool
_0802BC58:
	movs r0, 0x1
_0802BC5A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802BB84

	thumb_func_start sub_802BC60
sub_802BC60: @ 802BC60
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrh r0, [r0, 0xA]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _0802BD24
	lsls r0, 2
	ldr r1, =_0802BC84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802BC84:
	.4byte _0802BC9C
	.4byte _0802BCA2
	.4byte _0802BCB2
	.4byte _0802BCC8
	.4byte _0802BCEE
	.4byte _0802BD14
_0802BC9C:
	bl sub_802DA14
	b _0802BCFE
_0802BCA2:
	bl sub_802DA44
	cmp r0, 0
	bne _0802BD24
	movs r0, 0x7
	bl sub_802D0C8
	b _0802BCFE
_0802BCB2:
	bl sub_802D0F0
	adds r2, r0, 0
	cmp r2, 0
	bne _0802BD24
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	strh r2, [r1, 0x3C]
	b _0802BD02
	.pool
_0802BCC8:
	ldr r1, [r4]
	ldrh r0, [r1, 0x3C]
	adds r0, 0x1
	strh r0, [r1, 0x3C]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x78
	bls _0802BD24
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	b _0802BD02
_0802BCEE:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0802BD24
	bl sub_800AC34
_0802BCFE:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
_0802BD02:
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802BD24
	.pool
_0802BD14:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802BD24
	movs r0, 0
	b _0802BD26
	.pool
_0802BD24:
	movs r0, 0x1
_0802BD26:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802BC60

	thumb_func_start sub_802BD30
sub_802BD30: @ 802BD30
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x1
	beq _0802BD66
	cmp r0, 0x1
	bgt _0802BD4C
	cmp r0, 0
	beq _0802BD52
	b _0802BD7A
	.pool
_0802BD4C:
	cmp r0, 0x2
	beq _0802BD76
	b _0802BD7A
_0802BD52:
	bl sub_802DA14
	movs r0, 0
	bl sub_802DD64
	ldr r1, [r4]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _0802BD7A
_0802BD66:
	bl sub_802DA44
	cmp r0, 0
	bne _0802BD7A
	ldr r1, [r4]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0802BD76:
	movs r0, 0
	b _0802BD7C
_0802BD7A:
	movs r0, 0x1
_0802BD7C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802BD30

	thumb_func_start sub_802BD84
sub_802BD84: @ 802BD84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	mov r0, r10
	movs r1, 0xE
	bl GetWordTaskArg
	mov r8, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0802BDC8
	cmp r0, 0x1
	beq _0802BDDC
	b _0802BE48
	.pool
_0802BDBC:
	bl sub_802AB20
	mov r0, r10
	bl DestroyTask
	b _0802BE48
_0802BDC8:
	movs r1, 0
	adds r0, r6, 0
	adds r0, 0x8
_0802BDCE:
	strh r1, [r0, 0x4]
	subs r0, 0x2
	cmp r0, r6
	bge _0802BDCE
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
_0802BDDC:
	mov r3, r8
	ldrb r1, [r3, 0x6]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r4, =0x000082a8
	adds r0, r4
	add r0, r8
	bl sub_802E0AC
	movs r2, 0
	adds r5, r6, 0x4
	mov r9, r2
	movs r7, 0x83
	lsls r7, 8
	add r7, r8
	add r4, r8
_0802BDFE:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0802BE38
	adds r0, r2, 0
	adds r1, r4, 0
	str r2, [sp]
	bl sub_802E0D0
	ldr r2, [sp]
	cmp r0, 0
	beq _0802BE38
	ldr r1, =gLinkPlayers + 8
	add r1, r9
	adds r0, r7, 0
	bl StringCopy
	movs r0, 0x1
	strh r0, [r5]
	ldrh r0, [r6, 0x2]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	movs r3, 0x2
	ldrsh r0, [r6, r3]
	ldr r2, [sp]
	mov r1, r8
	ldrb r1, [r1, 0x5]
	cmp r0, r1
	beq _0802BDBC
_0802BE38:
	adds r5, 0x2
	movs r3, 0x1C
	add r9, r3
	adds r7, 0x28
	adds r4, 0xC
	adds r2, 0x1
	cmp r2, 0x4
	ble _0802BDFE
_0802BE48:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802BD84

	thumb_func_start sub_802BE60
sub_802BE60: @ 802BE60
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022CFC
	ldr r2, [r1]
	movs r1, 0xE
	bl SetWordTaskArg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802BE60

	thumb_func_start sub_802BE80
sub_802BE80: @ 802BE80
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4A
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x6
	str r0, [r2, 0x14]
	strh r1, [r2, 0x34]
	str r1, [r2, 0x1C]
	strh r1, [r2, 0x36]
	str r1, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end sub_802BE80

	thumb_func_start sub_802BEA0
sub_802BEA0: @ 802BEA0
	push {r4,lr}
	ldr r3, =gUnknown_02022CFC
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x4A
	movs r4, 0
	movs r2, 0
	strh r2, [r1]
	ldr r1, =0x000006ff
	strh r1, [r0, 0x34]
	movs r1, 0x7
	str r1, [r0, 0x14]
	strh r2, [r0, 0x36]
	str r2, [r0, 0x10]
	adds r0, 0x51
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, 0x50
	strb r4, [r0]
	ldr r0, [r3]
	str r2, [r0, 0x20]
	adds r1, r0, 0
	adds r1, 0x4E
	strh r2, [r1]
	str r2, [r0, 0x6C]
	bl sub_802BF7C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802BEA0

	thumb_func_start sub_802BEE4
sub_802BEE4: @ 802BEE4
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x46
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802BF34
	adds r1, 0x4A
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	bl sub_802BF48
	ldr r3, [r4]
	ldrh r1, [r3, 0x34]
	adds r2, r1, r0
	strh r2, [r3, 0x34]
	lsls r1, r2, 16
	ldr r0, =0x09fe0000
	cmp r1, r0
	bls _0802BF16
	ldr r1, =0xfffff601
	adds r0, r2, r1
	strh r0, [r3, 0x34]
_0802BF16:
	ldr r1, [r4]
	ldr r2, [r1, 0x14]
	str r2, [r1, 0x18]
	ldrh r0, [r1, 0x34]
	lsrs r0, 8
	str r0, [r1, 0x14]
	cmp r0, 0x6
	bls _0802BF34
	cmp r2, 0x6
	bhi _0802BF34
	ldrh r0, [r1, 0x36]
	adds r0, 0x1
	strh r0, [r1, 0x36]
	bl sub_802BF7C
_0802BF34:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802BEE4

	thumb_func_start sub_802BF48
sub_802BF48: @ 802BF48
	push {lr}
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	ldr r0, [r2, 0x10]
	cmp r0, 0
	beq _0802BF5C
	movs r0, 0
	b _0802BF72
	.pool
_0802BF5C:
	ldr r3, [r2, 0x1C]
	ldrh r1, [r2, 0x34]
	ldr r0, =0x000005ff
	cmp r1, r0
	bhi _0802BF70
	ldr r0, [r2, 0x20]
	adds r0, 0x50
	str r0, [r2, 0x20]
	lsrs r0, 8
	adds r3, r0
_0802BF70:
	adds r0, r3, 0
_0802BF72:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802BF48

	thumb_func_start sub_802BF7C
sub_802BF7C: @ 802BF7C
	push {r4,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r3, [r4]
	movs r0, 0
	str r0, [r3, 0x20]
	adds r1, r3, 0
	adds r1, 0x4E
	ldrh r0, [r1]
	cmp r0, 0
	beq _0802BFC0
	subs r0, 0x1
	strh r0, [r1]
	ldr r0, [r3, 0x6C]
	cmp r0, 0
	beq _0802C08A
	bl sub_802C098
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	beq _0802BFB0
	ldr r1, [r4]
	b _0802C086
	.pool
_0802BFB0:
	ldr r1, [r4]
	ldr r0, [r1, 0x28]
	cmp r0, 0x36
	bls _0802BFBC
	movs r0, 0x1E
	b _0802C088
_0802BFBC:
	movs r0, 0x52
	b _0802C088
_0802BFC0:
	adds r2, r3, 0
	adds r2, 0x50
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0802C014
	ldr r0, =gUnknown_082FB63C
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	adds r0, r3, 0
	adds r0, 0x51
	ldrb r2, [r0]
	lsls r0, r2, 3
	subs r0, r2
	ldrh r1, [r1]
	adds r0, r1
	str r0, [r3, 0x28]
	bl sub_802C098
	ldr r2, [r4]
	ldr r3, =gUnknown_082FB64C
	movs r1, 0x3
	ands r1, r0
	lsls r1, 1
	adds r1, r3
	ldrh r0, [r1]
	adds r0, 0x2
	adds r1, r2, 0
	adds r1, 0x4E
	strh r0, [r1]
	adds r2, 0x50
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _0802C082
	.pool
_0802C014:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x8
	bne _0802C030
	adds r1, r3, 0
	adds r1, 0x51
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _0802C02C
	adds r0, 0x1
	strb r0, [r1]
	b _0802C030
_0802C02C:
	movs r0, 0x1
	str r0, [r3, 0x6C]
_0802C030:
	ldr r2, =gUnknown_082FB63C
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	mov r12, r0
	mov r3, r12
	adds r3, 0x50
	ldrb r0, [r3]
	movs r1, 0xF
	subs r1, r0
	lsls r1, 1
	adds r1, r2
	mov r0, r12
	adds r0, 0x51
	ldrb r2, [r0]
	lsls r0, r2, 3
	subs r0, r2
	ldrh r1, [r1]
	adds r0, r1
	mov r1, r12
	str r0, [r1, 0x28]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bls _0802C082
	bl sub_802C098
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _0802C07A
	ldr r1, [r4]
	ldr r0, [r1, 0x28]
	subs r0, 0x5
	str r0, [r1, 0x28]
_0802C07A:
	ldr r0, [r4]
	adds r0, 0x50
	movs r1, 0
	strb r1, [r0]
_0802C082:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
_0802C086:
	ldr r0, [r1, 0x28]
_0802C088:
	str r0, [r1, 0x1C]
_0802C08A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802BF7C

	thumb_func_start sub_802C098
sub_802C098: @ 802C098
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	ldr r1, [r2, 0x24]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00006073
	adds r0, r1
	str r0, [r2, 0x24]
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_802C098

	thumb_func_start sub_802C0B8
sub_802C0B8: @ 802C0B8
	push {lr}
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x10]
	movs r0, 0x6
	str r0, [r1, 0x14]
	ldr r0, =0x000005ff
	strh r0, [r1, 0x34]
	bl sub_802C270
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C0B8

	thumb_func_start sub_802C0DC
sub_802C0DC: @ 802C0DC
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bx lr
	.pool
	thumb_func_end sub_802C0DC

	thumb_func_start sub_802C0E8
sub_802C0E8: @ 802C0E8
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022CFC
	ldr r4, =0x000082f8
	movs r3, 0
	movs r2, 0
	movs r1, 0x4
_0802C0F4:
	ldr r0, [r5]
	adds r0, r4
	adds r0, r2
	str r3, [r0]
	adds r2, 0x28
	subs r1, 0x1
	cmp r1, 0
	bge _0802C0F4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C0E8

	thumb_func_start sub_802C114
sub_802C114: @ 802C114
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldr r1, =0x000083ac
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0
	strh r2, [r1, 0x10]
	ldr r0, [r0]
	strh r2, [r0, 0x12]
	bx lr
	.pool
	thumb_func_end sub_802C114

	thumb_func_start sub_802C130
sub_802C130: @ 802C130
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_02022CFC
	ldr r2, [r1]
	ldrb r3, [r2, 0x6]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r2, r1
	ldr r1, =0x000082f4
	adds r2, r1
	ldrh r1, [r2]
	cmp r1, r0
	beq _0802C15C
	movs r0, 0
	b _0802C15E
	.pool
_0802C15C:
	movs r0, 0x1
_0802C15E:
	pop {r1}
	bx r1
	thumb_func_end sub_802C130

	thumb_func_start sub_802C164
sub_802C164: @ 802C164
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldr r1, =0x000083ac
	adds r2, r0, r1
	ldr r1, [r2]
	adds r0, 0x4A
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	ldr r1, [r2]
	ldrh r0, [r1, 0x10]
	strh r0, [r1, 0x12]
	ldr r1, [r2]
	movs r0, 0x1
	strh r0, [r1, 0x10]
	bx lr
	.pool
	thumb_func_end sub_802C164

	thumb_func_start sub_802C18C
sub_802C18C: @ 802C18C
	push {r4,lr}
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	ldr r0, =0x000083ac
	adds r3, r2, r0
	ldr r1, [r3]
	ldrh r0, [r1, 0x10]
	strh r0, [r1, 0x12]
	ldr r0, [r3]
	movs r4, 0x2
	strh r4, [r0, 0x10]
	ldr r1, [r3]
	adds r2, 0x4A
	ldrh r0, [r2]
	strh r0, [r1, 0xE]
	ldr r0, [r3]
	str r4, [r0, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C18C

	thumb_func_start sub_802C1BC
sub_802C1BC: @ 802C1BC
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldr r1, =0x000083ac
	adds r0, r1
	ldr r1, [r0]
	ldrh r2, [r1, 0x10]
	movs r3, 0
	strh r2, [r1, 0x12]
	ldr r0, [r0]
	strh r3, [r0, 0x10]
	bx lr
	.pool
	thumb_func_end sub_802C1BC

	thumb_func_start sub_802C1DC
sub_802C1DC: @ 802C1DC
	push {r4,r5,lr}
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldr r0, [r1, 0x5C]
	cmp r0, 0
	beq _0802C21C
	ldr r0, [r1, 0x78]
	bl sub_802DD64
	ldr r1, [r4]
	movs r5, 0
	str r5, [r1, 0x5C]
	adds r0, r1, 0
	adds r0, 0x4D
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802C21C
	adds r0, r1, 0
	adds r0, 0x71
	ldrb r0, [r0]
	bl sub_802DCCC
	ldr r1, =gUnknown_082FB654
	subs r0, 0x2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	bl PlaySE
	ldr r0, [r4]
	adds r0, 0x4D
	strb r5, [r0]
_0802C21C:
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x74
	ldrh r0, [r0]
	bl sub_802DD74
	bl sub_802C280
	bl sub_802C240
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C1DC

	thumb_func_start sub_802C240
sub_802C240: @ 802C240
	push {lr}
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x46
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802C256
	ldr r0, [r1, 0x14]
	bl sub_802DC9C
_0802C256:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C240

	thumb_func_start sub_802C260
sub_802C260: @ 802C260
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x46
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_802C260

	thumb_func_start sub_802C270
sub_802C270: @ 802C270
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x46
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_802C270

	thumb_func_start sub_802C280
sub_802C280: @ 802C280
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r6, 0
	ldr r2, =gUnknown_02022CFC
	ldr r0, [r2]
	ldrb r0, [r0, 0x5]
	mov r9, r0
	movs r5, 0
	cmp r6, r9
	bge _0802C360
	mov r10, r2
	mov r8, r5
	movs r7, 0
_0802C2A2:
	mov r0, r10
	ldr r3, [r0]
	adds r1, r3, r7
	ldr r2, =0x000082f4
	adds r0, r1, r2
	ldrh r2, [r0]
	cmp r2, 0x1
	beq _0802C2D4
	cmp r2, 0x1
	bgt _0802C2C4
	cmp r2, 0
	beq _0802C2CA
	b _0802C354
	.pool
_0802C2C4:
	cmp r2, 0x2
	beq _0802C338
	b _0802C354
_0802C2CA:
	adds r0, r5, 0
	movs r1, 0
	bl sub_802DC80
	b _0802C354
_0802C2D4:
	ldr r0, =0x000082f6
	adds r4, r1, r0
	ldrh r0, [r4]
	cmp r0, 0x1
	bne _0802C2F6
	ldr r0, =0x000082f2
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x9A
	add r1, r8
	str r1, [sp]
	ldrh r1, [r0]
	mov r12, r1
	ldr r0, [sp]
	ldrh r0, [r0]
	cmp r12, r0
	beq _0802C31E
_0802C2F6:
	ldrb r3, [r3, 0x6]
	cmp r5, r3
	bne _0802C2FE
	strh r2, [r4]
_0802C2FE:
	orrs r6, r2
	mov r1, r10
	ldr r2, [r1]
	ldr r1, =0x000082e8
	adds r0, r2, r1
	adds r0, r7
	ldr r1, =0x7fffffff
	str r1, [r0]
	adds r1, r2, 0
	adds r1, 0x9A
	add r1, r8
	adds r2, r7
	ldr r0, =0x000082f2
	adds r2, r0
	ldrh r0, [r2]
	strh r0, [r1]
_0802C31E:
	adds r0, r5, 0
	bl sub_802C398
	b _0802C354
	.pool
_0802C338:
	ldr r0, =0x000082f6
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0x2
	beq _0802C354
	ldrb r3, [r3, 0x6]
	cmp r5, r3
	bne _0802C34A
	strh r2, [r1]
_0802C34A:
	orrs r6, r2
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_802DD88
_0802C354:
	movs r1, 0x2
	add r8, r1
	adds r7, 0x28
	adds r5, 0x1
	cmp r5, r9
	blt _0802C2A2
_0802C360:
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _0802C378
	movs r0, 0x83
	lsls r0, 1
	bl PlaySE
	b _0802C386
	.pool
_0802C378:
	movs r0, 0x1
	ands r6, r0
	cmp r6, 0
	beq _0802C386
	movs r0, 0xA
	bl PlaySE
_0802C386:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802C280

	thumb_func_start sub_802C398
sub_802C398: @ 802C398
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gUnknown_02022CFC
	ldr r2, [r0]
	ldr r0, [r2, 0x68]
	cmp r0, 0
	bne _0802C432
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =0x000082e4
	adds r0, r1
	adds r5, r2, r0
	ldr r1, [r5, 0x4]
	ldr r0, =0x7fffffff
	cmp r1, r0
	beq _0802C3D0
	adds r0, r1, 0x1
	str r0, [r5, 0x4]
	adds r3, r0, 0
	b _0802C3E8
	.pool
_0802C3D0:
	adds r0, r2, 0
	adds r0, 0x4A
	ldrh r1, [r0]
	ldrh r0, [r5, 0xE]
	subs r3, r1, r0
	ldr r0, =0x0000fde7
	cmp r3, r0
	ble _0802C3E6
	ldr r0, =0xffff0218
	adds r3, r0
	adds r3, r1
_0802C3E6:
	str r3, [r5, 0x4]
_0802C3E8:
	cmp r3, 0x3
	ble _0802C432
	subs r3, 0x4
	cmp r3, 0x2F
	bgt _0802C414
	ldr r2, =gUnknown_082FB65C
	ldrh r1, [r5, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	adds r0, r3, r0
	adds r0, r2
	movs r4, 0
	ldrsb r4, [r0, r4]
	b _0802C416
	.pool
_0802C414:
	movs r4, 0
_0802C416:
	adds r1, r4, 0
	adds r0, r6, 0
	bl sub_802DC80
	cmp r4, 0
	bne _0802C430
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r6, r0
	bne _0802C430
	bl sub_802C1BC
_0802C430:
	str r4, [r5]
_0802C432:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C398

	thumb_func_start sub_802C43C
sub_802C43C: @ 802C43C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022CFC
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	cmp r0, 0x8
	bne _0802C4CE
	ldr r0, [r1, 0x18]
	cmp r0, 0x7
	bne _0802C4CE
	ldr r4, [r1, 0x58]
	cmp r4, 0
	bne _0802C46C
	bl sub_802C780
	ldr r0, [r5]
	str r4, [r0, 0x54]
	movs r1, 0x1
	str r1, [r0, 0x58]
	adds r0, 0x71
	strb r4, [r0]
	b _0802C4CE
	.pool
_0802C46C:
	ldr r0, [r1, 0x54]
	cmp r0, 0x5
	bne _0802C480
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0xC]
	bl sub_802C7A0
	b _0802C484
_0802C480:
	movs r0, 0
	strh r0, [r1, 0xC]
_0802C484:
	ldr r4, =gUnknown_02022CFC
	ldr r1, [r4]
	ldr r0, [r1, 0x54]
	cmp r0, 0x1
	ble _0802C49E
	movs r0, 0x1
	str r0, [r1, 0x64]
	adds r0, r1, 0
	adds r0, 0x86
	adds r1, 0x81
	movs r2, 0x5
	bl memcpy
_0802C49E:
	bl sub_802C780
	ldr r0, [r4]
	movs r2, 0
	str r2, [r0, 0x54]
	movs r1, 0x1
	str r1, [r0, 0x58]
	adds r0, 0x71
	strb r2, [r0]
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x74
	ldrh r1, [r2]
	ldr r0, =0x0000270e
	cmp r1, r0
	bhi _0802C4C2
	adds r0, r1, 0x1
	strh r0, [r2]
_0802C4C2:
	movs r0, 0xA
	bl sub_802C688
	movs r0, 0x3
	bl sub_802AE14
_0802C4CE:
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldr r0, [r0, 0x64]
	cmp r0, 0
	beq _0802C504
	bl sub_802C618
	cmp r0, 0x1
	beq _0802C4E8
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	bne _0802C504
_0802C4E8:
	ldr r0, [r4]
	adds r0, 0x86
	bl sub_802C73C
	bl sub_802C790
	bl sub_802C688
	movs r0, 0x3
	bl sub_802AE14
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x64]
_0802C504:
	ldr r4, =gUnknown_02022CFC
	ldr r0, [r4]
	ldr r0, [r0, 0x58]
	cmp r0, 0
	beq _0802C52A
	bl sub_802C6B0
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r0, [r1, 0x54]
	cmp r2, r0
	ble _0802C52A
	str r2, [r1, 0x54]
	adds r0, r1, 0
	adds r0, 0x81
	adds r1, 0x7C
	movs r2, 0x5
	bl memcpy
_0802C52A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C43C

	thumb_func_start sub_802C538
sub_802C538: @ 802C538
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022CFC
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	cmp r0, 0x6
	bne _0802C582
	ldr r4, =0x000083ac
	adds r0, r1, r4
	ldr r1, [r0]
	ldr r0, [r1]
	cmp r0, 0
	bne _0802C582
	ldrh r0, [r1, 0x12]
	cmp r0, 0x1
	bne _0802C578
	bl sub_802C0DC
	adds r1, r0, 0
	cmp r1, 0x1
	bne _0802C578
	ldr r0, [r5]
	adds r0, r4
	ldr r0, [r0]
	str r1, [r0, 0x14]
	b _0802C582
	.pool
_0802C574:
	movs r0, 0
	b _0802C5CA
_0802C578:
	bl sub_802C18C
	movs r0, 0x3
	bl sub_802AE14
_0802C582:
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	ldr r0, [r1, 0x14]
	cmp r0, 0x7
	bne _0802C5A8
	ldr r0, [r1, 0x18]
	cmp r0, 0x6
	bne _0802C5A8
	ldr r2, =0x000083ac
	adds r0, r1, r2
	ldr r1, [r0]
	ldrh r0, [r1, 0x10]
	cmp r0, 0x2
	beq _0802C5A8
	movs r0, 0x1
	str r0, [r1, 0x14]
	movs r0, 0x3
	bl sub_802AE14
_0802C5A8:
	movs r2, 0
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	cmp r2, r1
	bge _0802C5C8
	adds r3, r1, 0
	ldr r4, =0x000082f4
	adds r1, r0, r4
_0802C5BA:
	ldrh r0, [r1]
	cmp r0, 0x2
	beq _0802C574
	adds r1, 0x28
	adds r2, 0x1
	cmp r2, r3
	blt _0802C5BA
_0802C5C8:
	movs r0, 0x1
_0802C5CA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C538

	thumb_func_start sub_802C5DC
sub_802C5DC: @ 802C5DC
	push {r4,lr}
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrb r3, [r0, 0x5]
	movs r4, 0
	cmp r4, r3
	bge _0802C600
	ldr r1, =0x000082f8
	adds r2, r0, r1
	adds r1, r3, 0
_0802C5F0:
	ldr r0, [r2]
	cmp r0, 0
	beq _0802C5F8
	adds r4, 0x1
_0802C5F8:
	adds r2, 0x28
	subs r1, 0x1
	cmp r1, 0
	bne _0802C5F0
_0802C600:
	movs r0, 0
	cmp r4, r3
	bne _0802C608
	movs r0, 0x1
_0802C608:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C5DC

	thumb_func_start sub_802C618
sub_802C618: @ 802C618
	push {r4,lr}
	movs r2, 0
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	cmp r2, r1
	bge _0802C648
	adds r3, r1, 0
	ldr r4, =0x000082f8
	adds r1, r0, r4
_0802C62C:
	ldr r0, [r1]
	cmp r0, 0x1
	beq _0802C640
	movs r0, 0
	b _0802C64A
	.pool
_0802C640:
	adds r1, 0x28
	adds r2, 0x1
	cmp r2, r3
	blt _0802C62C
_0802C648:
	movs r0, 0x1
_0802C64A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802C618

	thumb_func_start sub_802C650
sub_802C650: @ 802C650
	push {lr}
	ldr r0, =gUnknown_02022CFC
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0802C668
_0802C660:
	movs r0, 0
	b _0802C684
	.pool
_0802C668:
	movs r2, 0x1
	ldrb r0, [r1, 0x5]
	cmp r2, r0
	bge _0802C682
	adds r3, r0, 0
	adds r1, 0x92
_0802C674:
	ldrh r0, [r1]
	cmp r0, 0x1
	beq _0802C660
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _0802C674
_0802C682:
	movs r0, 0x1
_0802C684:
	pop {r1}
	bx r1
	thumb_func_end sub_802C650

	thumb_func_start sub_802C688
sub_802C688: @ 802C688
	push {lr}
	ldr r1, =gUnknown_02022CFC
	ldr r2, [r1]
	ldr r1, [r2, 0x78]
	adds r1, r0
	str r1, [r2, 0x78]
	movs r0, 0x1
	str r0, [r2, 0x5C]
	ldr r0, =0x00018695
	cmp r1, r0
	bls _0802C6A2
	adds r0, 0x1
	str r0, [r2, 0x78]
_0802C6A2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C688

	thumb_func_start sub_802C6B0
sub_802C6B0: @ 802C6B0
	push {r4-r7,lr}
	movs r5, 0
	ldr r1, =gUnknown_02022CFC
	ldr r0, [r1]
	ldrb r4, [r0, 0x5]
	movs r2, 0
	cmp r5, r4
	bge _0802C702
	mov r12, r1
	movs r3, 0
	ldr r7, =0x000082e4
	movs r6, 0x1E
	negs r6, r6
_0802C6CA:
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, r7
	adds r0, r3
	ldr r0, [r0]
	cmp r0, r6
	bne _0802C6F0
	adds r0, r1, 0
	adds r0, 0x7C
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	adds r5, 0x1
	b _0802C6FA
	.pool
_0802C6F0:
	adds r0, r1, 0
	adds r0, 0x7C
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
_0802C6FA:
	adds r3, 0x28
	adds r2, 0x1
	cmp r2, r4
	blt _0802C6CA
_0802C702:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_802C6B0

	thumb_func_start sub_802C70C
sub_802C70C: @ 802C70C
	push {lr}
	movs r2, 0
	ldr r1, =gUnknown_03005000
	ldr r3, =0x000009e6
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802C728
	ldr r3, =0x00000c1a
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802C728
	movs r2, 0x1
_0802C728:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C70C

	thumb_func_start sub_802C73C
sub_802C73C: @ 802C73C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	ldr r6, =gUnknown_02022CFC
	movs r5, 0x1
_0802C74A:
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802C75A
	adds r0, r5, 0
	lsls r0, r1
	orrs r2, r0
	adds r3, 0x1
_0802C75A:
	adds r1, 0x1
	cmp r1, 0x4
	ble _0802C74A
	ldr r0, [r6]
	adds r0, 0x71
	strb r2, [r0]
	cmp r2, 0
	beq _0802C772
	ldr r0, [r6]
	adds r0, 0x4D
	movs r1, 0x1
	strb r1, [r0]
_0802C772:
	adds r0, r3, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C73C

	thumb_func_start sub_802C780
sub_802C780: @ 802C780
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	adds r0, 0x44
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_802C780

	thumb_func_start sub_802C790
sub_802C790: @ 802C790
	ldr r1, =gUnknown_082FB6EC
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802C790

	thumb_func_start sub_802C7A0
sub_802C7A0: @ 802C7A0
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrh r2, [r0, 0xE]
	cmp r1, r2
	bls _0802C7B2
	strh r1, [r0, 0xE]
_0802C7B2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C7A0

	thumb_func_start sub_802C7BC
sub_802C7BC: @ 802C7BC
	push {lr}
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldr r1, =gUnknown_082FB714
	ldr r2, [r0, 0x78]
	ldr r0, [r1]
	cmp r2, r0
	bcs _0802C7D8
	movs r0, 0
	b _0802C7DA
	.pool
_0802C7D8:
	movs r0, 0x1
_0802C7DA:
	pop {r1}
	bx r1
	thumb_func_end sub_802C7BC

	thumb_func_start sub_802C7E0
sub_802C7E0: @ 802C7E0
	push {r4,lr}
	bl sub_802C818
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_802C838
	lsls r0, 16
	lsrs r0, 4
	ldr r1, =0x00000fff
	ands r4, r1
	orrs r0, r4
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C7E0

	thumb_func_start sub_802C808
sub_802C808: @ 802C808
	lsls r0, 16
	lsrs r3, r0, 28
	strh r3, [r2]
	lsls r0, 4
	lsrs r0, 20
	strh r0, [r1]
	bx lr
	thumb_func_end sub_802C808

	thumb_func_start sub_802C818
sub_802C818: @ 802C818
	push {lr}
	bl Random
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	ldr r0, =gUnknown_082FB704
	lsrs r1, 15
	adds r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802C818

	thumb_func_start sub_802C838
sub_802C838: @ 802C838
	push {r4-r6,lr}
	movs r5, 0
	movs r4, 0
	ldr r3, =gUnknown_02022CFC
	ldr r0, [r3]
	ldr r2, =gUnknown_082FB714
	ldr r1, [r0, 0x78]
	ldr r0, [r2]
	cmp r1, r0
	bcc _0802C874
	ldr r5, [r2, 0x4]
	adds r6, r3, 0
	adds r3, r2, 0x4
_0802C852:
	adds r3, 0x8
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x4
	bhi _0802C874
	ldr r0, [r6]
	ldr r1, [r0, 0x78]
	ldr r0, [r2]
	cmp r1, r0
	bcc _0802C874
	ldr r5, [r3]
	b _0802C852
	.pool
_0802C874:
	lsls r0, r5, 16
	lsrs r0, 16
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802C838

	thumb_func_start sub_802C880
sub_802C880: @ 802C880
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	b _0802C892
_0802C88C:
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0802C892:
	cmp r4, 0
	beq _0802C8A4
	adds r0, r5, 0
	adds r1, r4, 0
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	beq _0802C88C
_0802C8A4:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802C880

	thumb_func_start sub_802C8AC
sub_802C8AC: @ 802C8AC
	push {lr}
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_802C8AC

	thumb_func_start sub_802C8BC
sub_802C8BC: @ 802C8BC
	ldr r0, =gUnknown_02022CFC
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	bx lr
	.pool
	thumb_func_end sub_802C8BC

	thumb_func_start sub_802C8C8
sub_802C8C8: @ 802C8C8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02022CFC
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, =0x000082a8
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_802C8C8

	thumb_func_start sub_802C8E8
sub_802C8E8: @ 802C8E8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022CFC
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, [r2]
	adds r0, r1
	movs r1, 0x83
	lsls r1, 8
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_802C8E8

	thumb_func_start sub_802C908
sub_802C908: @ 802C908
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_802AC00
	lsls r0, 16
	asrs r0, 16
	mvns r0, r0
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_802C908

	thumb_func_start sub_802C920
sub_802C920: @ 802C920
	push {r4,r5,lr}
	movs r5, 0
_0802C924:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _0802C95C
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl sub_802C908
	cmp r0, 0
	beq _0802C95C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _0802C966
	.pool
_0802C95C:
	adds r5, 0x1
	cmp r5, 0x5
	ble _0802C924
	ldr r1, =gSpecialVar_Result
	movs r0, 0
_0802C966:
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C920

	thumb_func_start sub_802C974
sub_802C974: @ 802C974
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r4, 0
	ldr r5, =gUnknown_082FBE08
_0802C97C:
	adds r0, r5, 0
	bl LoadCompressedSpriteSheet
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x4
	bls _0802C97C
	movs r4, 0
	ldr r5, =gUnknown_082FBE30
_0802C98E:
	adds r0, r5, 0
	bl LoadSpritePalette
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x1
	bls _0802C98E
	movs r0, 0x5
	bl IndexOfSpritePaletteTag
	strb r0, [r6, 0xE]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	strb r0, [r6, 0xF]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C974

	thumb_func_start sub_802C9BC
sub_802C9BC: @ 802C9BC
	push {lr}
	movs r2, 0
	movs r1, 0x7
	adds r0, 0x3C
_0802C9C4:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0802C9C4
	pop {r0}
	bx r0
	thumb_func_end sub_802C9BC

	thumb_func_start sub_802C9D4
sub_802C9D4: @ 802C9D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r9, r0
	adds r7, r1, 0
	ldr r0, [sp, 0x54]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x28]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x2C]
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, sp
	ldr r0, =gUnknown_082FBE40
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x80
	lsls r0, 6
	bl Alloc
	mov r8, r0
	movs r0, 0x80
	lsls r0, 4
	bl Alloc
	mov r10, r0
	bl sub_802C8BC
	lsls r0, 16
	lsrs r0, 16
	cmp r6, r0
	bne _0802CA2C
	movs r0, 0x3
	b _0802CA32
	.pool
_0802CA2C:
	adds r0, r6, 0x4
	lsls r0, 24
	lsrs r0, 24
_0802CA32:
	str r0, [sp, 0x30]
	mov r1, r8
	cmp r1, 0
	beq _0802CAF4
	mov r2, r10
	cmp r2, 0
	beq _0802CAF4
	ldrh r2, [r7]
	lsls r0, r2, 3
	ldr r1, =gMonStillFrontPicTable
	adds r0, r1
	ldr r3, [r7, 0x8]
	mov r1, r8
	bl HandleLoadSpecialPokePic
	mov r3, r8
	str r3, [sp, 0x18]
	adds r4, r6, 0
	add r0, sp, 0x18
	ldr r5, =0xffff0000
	lsls r1, r4, 16
	movs r2, 0x80
	lsls r2, 4
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadSpriteSheet
	ldrh r0, [r7]
	ldr r1, [r7, 0x4]
	ldr r2, [r7, 0x8]
	bl GetFrontSpritePalFromSpeciesAndPersonality
	str r0, [sp, 0x20]
	add r0, sp, 0x20
	ldr r1, [r0, 0x4]
	ands r1, r5
	orrs r1, r4
	str r1, [r0, 0x4]
	bl LoadCompressedSpritePalette
	mov r0, r8
	bl Free
	mov r0, r10
	bl Free
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r6
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0, 0x2]
	adds r0, r6
	strh r0, [r1, 0x2]
	ldr r4, [sp, 0x28]
	lsls r1, r4, 16
	asrs r1, 16
	ldr r0, [sp, 0x2C]
	lsls r2, r0, 16
	asrs r2, 16
	mov r0, sp
	ldr r3, [sp, 0x30]
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0802CAF4
	lsls r0, r6, 2
	ldr r2, =0x000081a8
	add r2, r9
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	ldr r0, =0x000081fc
	add r0, r9
	adds r0, r6
	add r1, sp, 0x30
	ldrb r1, [r1]
	strb r1, [r0]
	b _0802CB00
	.pool
_0802CAF4:
	lsls r0, r6, 2
	ldr r1, =0x000081a8
	add r1, r9
	adds r1, r0
	movs r0, 0
	str r0, [r1]
_0802CB00:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802C9D4

	thumb_func_start sub_802CB14
sub_802CB14: @ 802CB14
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r6, r1, 2
	ldr r0, =0x000081bc
	adds r5, r4, r0
	adds r5, r6
	ldr r0, [r5]
	bl sub_802C9BC
	ldr r2, [r5]
	ldr r0, =0x000081a8
	adds r4, r0
	adds r4, r6
	ldr r1, [r4]
	ldr r0, =gSprites
	subs r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r1, r0, 8
	adds r0, r1
	lsls r1, r0, 16
	adds r0, r1
	negs r0, r0
	asrs r0, 2
	strh r0, [r2, 0x3C]
	ldr r1, [r5]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, 0x60
	strh r0, [r1, 0x22]
	ldr r0, [r5]
	ldr r1, =sub_802CB7C
	str r1, [r0, 0x1C]
	movs r1, 0x1
	bl StartSpriteAnim
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CB14

	thumb_func_start sub_802CB7C
sub_802CB7C: @ 802CB7C
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _0802CBA8
	cmp r0, 0x1
	bgt _0802CB92
	cmp r0, 0
	beq _0802CB98
	b _0802CBE6
_0802CB92:
	cmp r0, 0x2
	beq _0802CBC8
	b _0802CBE6
_0802CB98:
	adds r0, r2, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0802CBE6
	b _0802CBD6
_0802CBA8:
	ldrh r1, [r2, 0x22]
	subs r1, 0x1
	strh r1, [r2, 0x22]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x48
	bgt _0802CBE6
	movs r0, 0x48
	strh r0, [r2, 0x22]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _0802CBE6
_0802CBC8:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2F
	ble _0802CBE6
_0802CBD6:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_0802CBE6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CB7C

	thumb_func_start sub_802CBF0
sub_802CBF0: @ 802CBF0
	push {lr}
	lsls r1, 2
	ldr r2, =0x000081a8
	adds r0, r2
	adds r0, r1
	ldr r2, [r0]
	ldr r1, =sub_802CC40
	str r1, [r2, 0x1C]
	movs r1, 0
	strh r1, [r2, 0x26]
	ldr r0, [r0]
	bl sub_802C9BC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CBF0

	thumb_func_start sub_802CC18
sub_802CC18: @ 802CC18
	push {lr}
	movs r2, 0
	lsls r1, 2
	ldr r3, =0x000081a8
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	ldr r0, =sub_802CC40
	cmp r1, r0
	bne _0802CC30
	movs r2, 0x1
_0802CC30:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802CC18

	thumb_func_start sub_802CC40
sub_802CC40: @ 802CC40
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0802CC6C
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0802CC64
	movs r0, 0x2
	b _0802CC66
_0802CC64:
	ldr r0, =0x0000fffe
_0802CC66:
	strh r0, [r2, 0x26]
	movs r0, 0
	strh r0, [r2, 0x30]
_0802CC6C:
	movs r1, 0x32
	ldrsh r0, [r2, r1]
	cmp r0, 0xC
	ble _0802CC7C
	movs r0, 0
	strh r0, [r2, 0x26]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_0802CC7C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CC40

	thumb_func_start sub_802CC88
sub_802CC88: @ 802CC88
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 2
	ldr r0, =0x000081a8
	adds r4, r0
	adds r4, r1
	ldr r0, [r4]
	bl sub_802C9BC
	ldr r1, [r4]
	ldr r0, =sub_802CD08
	str r0, [r1, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CC88

	thumb_func_start sub_802CCB0
sub_802CCB0: @ 802CCB0
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_802C8AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _0802CCF4
	movs r1, 0x5
	negs r1, r1
	mov r12, r1
	ldr r1, =0x000081a8
	adds r3, r4, r1
	ldr r7, =sub_802CD08
	ldr r6, =SpriteCallbackDummy
	movs r5, 0xA
	adds r4, r0, 0
_0802CCD2:
	ldr r2, [r3]
	ldr r0, [r2, 0x1C]
	cmp r0, r7
	bne _0802CCEC
	adds r2, 0x3E
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	str r6, [r0, 0x1C]
	adds r0, 0x43
	strb r5, [r0]
_0802CCEC:
	adds r3, 0x4
	subs r4, 0x1
	cmp r4, 0
	bne _0802CCD2
_0802CCF4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CCB0

	thumb_func_start sub_802CD08
sub_802CD08: @ 802CD08
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0802CD36
	movs r0, 0
	strh r0, [r3, 0x2E]
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0802CD36:
	pop {r0}
	bx r0
	thumb_func_end sub_802CD08

	thumb_func_start sub_802CD3C
sub_802CD3C: @ 802CD3C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_802C8AC
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r3
	bge _0802CD66
	ldr r0, =0x000081fc
	adds r5, r4, r0
	subs r0, 0x54
	adds r4, r0
_0802CD56:
	ldm r4!, {r0}
	adds r1, r5, r2
	ldrb r1, [r1]
	adds r0, 0x43
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt _0802CD56
_0802CD66:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CD3C

	thumb_func_start sub_802CD70
sub_802CD70: @ 802CD70
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 2
	ldr r0, =0x000081a8
	adds r4, r0
	adds r4, r1
	ldr r0, [r4]
	bl sub_802C9BC
	ldr r1, [r4]
	ldr r0, =sub_802CDD4
	str r0, [r1, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CD70

	thumb_func_start sub_802CD98
sub_802CD98: @ 802CD98
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_802C8AC
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r3
	bge _0802CDCC
	ldr r5, =sub_802CDD4
	ldr r0, =0x000081a8
	adds r1, r4, r0
_0802CDB0:
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	cmp r0, r5
	bne _0802CDC4
	movs r0, 0x1
	b _0802CDCE
	.pool
_0802CDC4:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, r3
	blt _0802CDB0
_0802CDCC:
	movs r0, 0
_0802CDCE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802CD98

	thumb_func_start sub_802CDD4
sub_802CDD4: @ 802CDD4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	cmp r4, 0
	beq _0802CDE6
	cmp r4, 0x1
	beq _0802CDF4
	b _0802CE3C
_0802CDE6:
	movs r0, 0x22
	bl PlaySE
	strh r4, [r5, 0x30]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0802CDF4:
	ldrh r0, [r5, 0x30]
	adds r0, 0x4
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0802CE06
	movs r0, 0
	strh r0, [r5, 0x30]
_0802CE06:
	ldr r1, =gSineTable
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	negs r0, r0
	strh r0, [r5, 0x26]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	cmp r1, 0
	bne _0802CE3C
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _0802CE38
	strh r1, [r5, 0x2E]
	b _0802CE3C
	.pool
_0802CE38:
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
_0802CE3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CDD4

	thumb_func_start sub_802CE48
sub_802CE48: @ 802CE48
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r3, 24
	lsrs r4, r3, 24
	ldr r0, =gUnknown_082FC00C
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0802CE88
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r3]
	lsls r2, r4, 2
	ldr r3, =0x000081bc
	adds r0, r5, r3
	adds r0, r2
	str r1, [r0]
_0802CE88:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CE48

	thumb_func_start sub_802CE9C
sub_802CE9C: @ 802CE9C
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r4, 0
	ldr r6, =gUnknown_082FBE58
_0802CEA6:
	ldr r1, =gUnknown_082FBEB8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r2, =gUnknown_082FBEA8
	lsls r1, r5, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r6, r3]
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r5, 2
	ldr r3, =0x000081d0
	adds r2, r7, r3
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	adds r5, 0x1
	adds r6, 0x14
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802CEA6
	movs r4, 0x3
	movs r6, 0x3C
_0802CEE8:
	ldr r1, =gUnknown_082FBEB8
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r2, =gUnknown_082FBEA8
	lsls r1, r5, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	ldr r2, =gUnknown_082FBE58
	adds r2, r6, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r5, 2
	ldr r3, =0x000081d0
	adds r2, r7, r3
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	adds r5, 0x1
	subs r6, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _0802CEE8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CE9C

	thumb_func_start sub_802CF50
sub_802CF50: @ 802CF50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x8]
	cmp r1, 0x5
	ble _0802CF70
	movs r0, 0xA
	subs r1, r0, r1
	movs r0, 0x3
	str r0, [sp]
	ldr r2, [sp, 0x8]
	ldrb r0, [r2, 0xF]
	b _0802CF78
_0802CF70:
	movs r3, 0x2
	str r3, [sp]
	ldr r7, [sp, 0x8]
	ldrb r0, [r7, 0xE]
_0802CF78:
	movs r6, 0
	lsls r2, r1, 1
	str r2, [sp, 0x4]
	lsls r0, 4
	mov r9, r0
	lsls r1, 24
	mov r8, r1
	ldr r0, =gUnknown_082FBE58
	adds r4, r2, r0
	ldr r3, [sp]
	lsls r3, 2
	mov r10, r3
	movs r5, 0x3
_0802CF92:
	lsls r0, r6, 2
	ldr r7, [sp, 0x8]
	ldr r1, =0x000081d0
	adds r2, r7, r1
	adds r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, 0x22]
	ldr r3, [r2]
	ldrb r0, [r3, 0x5]
	movs r7, 0xD
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	mov r1, r10
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r3, [r2]
	ldrb r1, [r3, 0x5]
	movs r0, 0xF
	ands r0, r1
	mov r7, r9
	orrs r0, r7
	strb r0, [r3, 0x5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, 24
	bl StartSpriteAnim
	adds r6, 0x1
	adds r4, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _0802CF92
	movs r5, 0x3
	ldr r0, =gUnknown_082FBE58
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	adds r4, r0, 0
	adds r4, 0x3C
	ldr r7, [sp]
	lsls r7, 2
	mov r10, r7
_0802CFE8:
	lsls r0, r6, 2
	ldr r1, [sp, 0x8]
	ldr r3, =0x000081d0
	adds r2, r1, r3
	adds r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, 0x22]
	ldr r3, [r2]
	ldrb r0, [r3, 0x5]
	movs r7, 0xD
	negs r7, r7
	adds r1, r7, 0
	ands r0, r1
	mov r1, r10
	orrs r0, r1
	strb r0, [r3, 0x5]
	ldr r3, [r2]
	ldrb r1, [r3, 0x5]
	movs r0, 0xF
	ands r0, r1
	mov r7, r9
	orrs r0, r7
	strb r0, [r3, 0x5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, 24
	bl StartSpriteAnim
	adds r6, 0x1
	subs r4, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _0802CFE8
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802CF50

	thumb_func_start sub_802D044
sub_802D044: @ 802D044
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x9
	movs r1, 0x7
	movs r2, 0x78
	movs r3, 0x50
	bl sub_802EB24
	adds r0, r4, 0
	bl sub_802CD3C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D044

	thumb_func_start sub_802D068
sub_802D068: @ 802D068
	push {lr}
	bl sub_802EB84
	pop {r1}
	bx r1
	thumb_func_end sub_802D068

	thumb_func_start sub_802D074
sub_802D074: @ 802D074
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	str r0, [r4]
	bl sub_802D0BC
	ldr r0, =sub_802D12C
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0x6]
	ldr r2, [r4]
	ldrb r0, [r2, 0x6]
	movs r1, 0x2
	bl SetWordTaskArg
	ldr r0, =sub_802D150
	bl sub_802D108
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D074

	thumb_func_start sub_802D0AC
sub_802D0AC: @ 802D0AC
	push {lr}
	bl FreeAllWindowBuffers
	bl sub_8034CC8
	pop {r0}
	bx r0
	thumb_func_end sub_802D0AC

	thumb_func_start sub_802D0BC
sub_802D0BC: @ 802D0BC
	movs r1, 0
	strh r1, [r0, 0x4]
	str r1, [r0]
	movs r1, 0xFF
	strh r1, [r0, 0x12]
	bx lr
	thumb_func_end sub_802D0BC

	thumb_func_start sub_802D0C8
sub_802D0C8: @ 802D0C8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_082FE18C
_0802D0D0:
	ldr r0, [r4]
	cmp r0, r6
	bne _0802D0DC
	ldr r0, [r4, 0x4]
	bl sub_802D108
_0802D0DC:
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x9
	bls _0802D0D0
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D0C8

	thumb_func_start sub_802D0F0
sub_802D0F0: @ 802D0F0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_802D0F0

	thumb_func_start sub_802D108
sub_802D108: @ 802D108
	push {r4,lr}
	adds r2, r0, 0
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	movs r1, 0
	bl SetWordTaskArg
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0x4]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D108

	thumb_func_start sub_802D12C
sub_802D12C: @ 802D12C
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	bne _0802D148
	adds r0, r1, 0
	movs r1, 0
	bl GetWordTaskArg
	bl _call_via_r0
_0802D148:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D12C

	thumb_func_start sub_802D150
sub_802D150: @ 802D150
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =gUnknown_02022D00
	ldr r1, [r6]
	ldrh r5, [r1, 0x4]
	cmp r5, 0x1
	bne _0802D160
	b _0802D298
_0802D160:
	cmp r5, 0x1
	bgt _0802D170
	cmp r5, 0
	beq _0802D178
	b _0802D2DA
	.pool
_0802D170:
	cmp r5, 0x2
	bne _0802D176
	b _0802D2D6
_0802D176:
	b _0802D2DA
_0802D178:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082FE164
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_082FE174
	bl InitWindows
	bl reset_temp_tile_data_buffers
	ldr r0, [r6]
	bl sub_802C974
	bl sub_802DD08
	ldr r0, =gPkmnJumpBgPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpBgGfx
	str r5, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpBgTilemap
	movs r4, 0x1
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpVenusaurPal
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpVenusaurGfx
	str r5, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpVenusaurTilemap
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpResultsPal
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gPkmnJumpResultsGfx
	str r5, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gPkmnJumpResultsTilemap
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gPkmnJumpPal3
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r6]
	movs r0, 0xD3
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	bl sub_802DB8C
	movs r0, 0
	bl sub_802DD64
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_8098C6C
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	bl sub_8199D98
	b _0802D2CC
	.pool
_0802D298:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _0802D2DA
	bl sub_802DBF8
	ldr r0, [r6]
	bl sub_802CE9C
	ldr r0, [r6]
	movs r1, 0x6
	bl sub_802CF50
	movs r0, 0x3
	bl ShowBg
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x1
	bl HideBg
_0802D2CC:
	ldr r1, [r6]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D2DA
_0802D2D6:
	movs r0, 0x1
	str r0, [r1]
_0802D2DA:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802D150

	thumb_func_start sub_802D2E4
sub_802D2E4: @ 802D2E4
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _0802D310
	cmp r0, 0x1
	bgt _0802D300
	cmp r0, 0
	beq _0802D30A
	b _0802D34A
	.pool
_0802D300:
	cmp r0, 0x2
	beq _0802D322
	cmp r0, 0x3
	beq _0802D33A
	b _0802D34A
_0802D30A:
	bl sub_802DE1C
	b _0802D330
_0802D310:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	movs r0, 0
	bl sub_802DF70
	b _0802D330
_0802D322:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	bl sub_802DFD4
_0802D330:
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D34A
_0802D33A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D34A
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_0802D34A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D2E4

	thumb_func_start sub_802D350
sub_802D350: @ 802D350
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _0802D37C
	cmp r0, 0x1
	bgt _0802D36C
	cmp r0, 0
	beq _0802D376
	b _0802D3B6
	.pool
_0802D36C:
	cmp r0, 0x2
	beq _0802D38E
	cmp r0, 0x3
	beq _0802D3A6
	b _0802D3B6
_0802D376:
	bl sub_802DE1C
	b _0802D39C
_0802D37C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	movs r0, 0x1
	bl sub_802DF70
	b _0802D39C
_0802D38E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	bl sub_802DFD4
_0802D39C:
	ldr r1, [r4]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D3B6
_0802D3A6:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D3B6
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_0802D3B6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D350

	thumb_func_start sub_802D3BC
sub_802D3BC: @ 802D3BC
	push {r4,r5,lr}
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	beq _0802D3DC
	cmp r0, 0x1
	beq _0802D410
	b _0802D43E
	.pool
_0802D3DC:
	movs r4, 0
	cmp r4, r5
	bge _0802D3F8
_0802D3E2:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r4, 0x1
	cmp r4, r5
	blt _0802D3E2
_0802D3F8:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D43E
	.pool
_0802D410:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D43E
	movs r4, 0
	cmp r4, r5
	bge _0802D436
_0802D420:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	adds r4, 0x1
	cmp r4, r5
	blt _0802D420
_0802D436:
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1]
_0802D43E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D3BC

	thumb_func_start sub_802D448
sub_802D448: @ 802D448
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D4A4
	cmp r4, 0x1
	bgt _0802D464
	cmp r4, 0
	beq _0802D46A
	b _0802D4EC
	.pool
_0802D464:
	cmp r4, 0x2
	beq _0802D4DC
	b _0802D4EC
_0802D46A:
	movs r0, 0x1
	movs r1, 0x8
	movs r2, 0x14
	movs r3, 0x2
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_WantToPlayAgain2
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D4D2
	.pool
_0802D4A4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D4EC
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x17
	movs r1, 0x7
	movs r2, 0
	bl sub_802DB18
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D4D2:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D4EC
_0802D4DC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D4EC
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D4EC:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D448

	thumb_func_start sub_802D4F4
sub_802D4F4: @ 802D4F4
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D550
	cmp r4, 0x1
	bgt _0802D510
	cmp r4, 0
	beq _0802D516
	b _0802D58E
	.pool
_0802D510:
	cmp r4, 0x2
	beq _0802D57E
	b _0802D58E
_0802D516:
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1A
	movs r3, 0x4
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SavingDontTurnOffPower
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D574
	.pool
_0802D550:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D58E
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D574:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D58E
_0802D57E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D58E
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D58E:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D4F4

	thumb_func_start sub_802D598
sub_802D598: @ 802D598
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0
	beq _0802D5B0
	cmp r4, 0x1
	beq _0802D5C8
	b _0802D5DE
	.pool
_0802D5B0:
	bl sub_802DA14
	bl sub_8198C78
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D5DE
_0802D5C8:
	bl sub_802DA44
	cmp r0, 0
	bne _0802D5DE
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D5DE
	ldr r0, [r5]
	str r4, [r0]
_0802D5DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D598

	thumb_func_start sub_802D5E4
sub_802D5E4: @ 802D5E4
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D640
	cmp r4, 0x1
	bgt _0802D600
	cmp r4, 0
	beq _0802D606
	b _0802D67E
	.pool
_0802D600:
	cmp r4, 0x2
	beq _0802D66E
	b _0802D67E
_0802D606:
	movs r0, 0x2
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_SomeoneDroppedOut2
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D664
	.pool
_0802D640:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D67E
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D664:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D67E
_0802D66E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D67E
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D67E:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D5E4

	thumb_func_start sub_802D688
sub_802D688: @ 802D688
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0x1
	beq _0802D6E4
	cmp r4, 0x1
	bgt _0802D6A4
	cmp r4, 0
	beq _0802D6AA
	b _0802D722
	.pool
_0802D6A4:
	cmp r4, 0x2
	beq _0802D712
	b _0802D722
_0802D6AA:
	movs r0, 0x7
	movs r1, 0xA
	movs r2, 0x10
	movs r3, 0x2
	bl sub_802DA9C
	ldr r1, [r5]
	strh r0, [r1, 0x12]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gText_CommunicationStandby4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	b _0802D708
	.pool
_0802D6E4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D722
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802D708:
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D722
_0802D712:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802D722
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1]
_0802D722:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D688

	thumb_func_start sub_802D72C
sub_802D72C: @ 802D72C
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022D00
	ldr r0, [r5]
	ldrh r4, [r0, 0x4]
	cmp r4, 0
	beq _0802D744
	cmp r4, 0x1
	beq _0802D752
	b _0802D75E
	.pool
_0802D744:
	bl sub_802D044
	ldr r1, [r5]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
	b _0802D75E
_0802D752:
	bl sub_802D068
	cmp r0, 0
	bne _0802D75E
	ldr r0, [r5]
	str r4, [r0]
_0802D75E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802D72C

	thumb_func_start sub_802D764
sub_802D764: @ 802D764
	push {lr}
	ldr r1, =gUnknown_02022D00
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0xA]
	ldr r0, [r1]
	strb r2, [r0, 0xB]
	ldr r2, [r1]
	movs r0, 0x6
	strb r0, [r2, 0xC]
	ldr r0, [r1]
	ldrb r0, [r0, 0xC]
	bl sub_802DC9C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D764

	thumb_func_start sub_802D788
sub_802D788: @ 802D788
	push {r4,lr}
	ldr r0, =gUnknown_02022D00
	ldr r2, [r0]
	ldrb r3, [r2, 0xA]
	adds r4, r0, 0
	cmp r3, 0
	beq _0802D7A0
	cmp r3, 0x1
	beq _0802D7DA
	b _0802D7DE
	.pool
_0802D7A0:
	ldrb r0, [r2, 0xB]
	adds r0, 0x1
	strb r0, [r2, 0xB]
	ldr r1, [r4]
	ldrb r0, [r1, 0xB]
	cmp r0, 0xA
	bls _0802D7CA
	strb r3, [r1, 0xB]
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	adds r1, 0x1
	strb r1, [r0, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x9
	bls _0802D7CA
	strb r3, [r1, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
_0802D7CA:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_802DC9C
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, 0x7
	bne _0802D7DE
_0802D7DA:
	movs r0, 0
	b _0802D7E0
_0802D7DE:
	movs r0, 0x1
_0802D7E0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802D788

	thumb_func_start sub_802D7E8
sub_802D7E8: @ 802D7E8
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =gUnknown_02022D00
	ldr r1, [r5]
	adds r1, 0x26
	adds r2, r4, 0
	bl CopyItemNameHandlePlural
	ldr r0, [r5]
	adds r0, 0x66
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r5]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, [r5]
	adds r1, 0x66
	movs r0, 0x1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r5]
	adds r0, 0xA6
	ldr r1, =gText_AwesomeWonF701F700
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r2, [r5]
	movs r4, 0
	movs r3, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x1
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x0000016f
	strh r0, [r1, 0x14]
	strb r4, [r1, 0xD]
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D7E8

	thumb_func_start sub_802D884
sub_802D884: @ 802D884
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	adds r1, 0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, 0xA6
	ldr r1, =gText_FilledStorageSpace2
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x8
	movs r2, 0x16
	movs r3, 0x4
	bl sub_802DA9C
	ldr r2, [r4]
	movs r6, 0
	movs r5, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, 0x14]
	strb r6, [r0, 0xD]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D884

	thumb_func_start sub_802D8FC
sub_802D8FC: @ 802D8FC
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	adds r1, 0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, 0x26
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, 0xA6
	ldr r1, =gText_CantHoldMore
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x4
	movs r1, 0x9
	movs r2, 0x16
	movs r3, 0x2
	bl sub_802DA9C
	ldr r2, [r4]
	movs r6, 0
	movs r5, 0
	strh r0, [r2, 0x12]
	lsls r0, 24
	lsrs r0, 24
	adds r2, 0xA6
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, 0x14]
	strb r6, [r0, 0xD]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802D8FC

	thumb_func_start sub_802D974
sub_802D974: @ 802D974
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrb r0, [r0, 0xD]
	cmp r0, 0x1
	beq _0802D9C8
	cmp r0, 0x1
	bgt _0802D990
	cmp r0, 0
	beq _0802D99A
	b _0802DA0C
	.pool
_0802D990:
	cmp r0, 0x2
	beq _0802D9EE
	cmp r0, 0x3
	beq _0802DA02
	b _0802DA0C
_0802D99A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA0C
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r4]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
	b _0802DA0C
_0802D9C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA0C
	ldr r1, [r4]
	ldrh r0, [r1, 0x14]
	cmp r0, 0
	bne _0802D9E0
	ldrb r0, [r1, 0xD]
	adds r0, 0x2
	b _0802DA00
_0802D9E0:
	ldrh r0, [r1, 0x14]
	bl PlayFanfare
	ldr r1, [r4]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
_0802D9EE:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _0802DA0C
	ldr r0, =gUnknown_02022D00
	ldr r1, [r0]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
_0802DA00:
	strb r0, [r1, 0xD]
_0802DA02:
	movs r0, 0
	b _0802DA0E
	.pool
_0802DA0C:
	movs r0, 0x1
_0802DA0E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802D974

	thumb_func_start sub_802DA14
sub_802DA14: @ 802DA14
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldrh r0, [r0, 0x12]
	cmp r0, 0xFF
	beq _0802DA38
	lsls r0, 24
	lsrs r0, 24
	bl rbox_fill_rectangle
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	movs r1, 0x1
	bl CopyWindowToVram
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0xD]
_0802DA38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DA14

	thumb_func_start sub_802DA44
sub_802DA44: @ 802DA44
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r1, [r4]
	ldrh r0, [r1, 0x12]
	cmp r0, 0xFF
	bne _0802DA58
_0802DA50:
	movs r0, 0
	b _0802DA84
	.pool
_0802DA58:
	ldrb r0, [r1, 0xD]
	cmp r0, 0
	bne _0802DA7E
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802DA82
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x12]
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
	b _0802DA50
_0802DA7E:
	cmp r0, 0x1
	beq _0802DA50
_0802DA82:
	movs r0, 0x1
_0802DA84:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802DA44

	thumb_func_start sub_802DA8C
sub_802DA8C: @ 802DA8C
	push {lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_802DA8C

	thumb_func_start sub_802DA9C
sub_802DA9C: @ 802DA9C
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, =0xffffff00
	ldr r4, [sp]
	ands r4, r6
	lsls r0, 24
	lsrs r0, 16
	ldr r5, =0xffff00ff
	ands r4, r5
	orrs r4, r0
	lsls r1, 24
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r4, r0
	orrs r4, r1
	lsls r2, 24
	ldr r0, =0x00ffffff
	ands r4, r0
	orrs r4, r2
	str r4, [sp]
	lsls r3, 24
	lsrs r3, 24
	ldr r0, [sp, 0x4]
	ands r0, r6
	orrs r0, r3
	ands r0, r5
	movs r1, 0xF0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x86
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DA9C

	thumb_func_start sub_802DB18
sub_802DB18: @ 802DB18
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r2, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r5, =0xffffff00
	ldr r2, [sp]
	ands r2, r5
	lsls r0, 24
	lsrs r0, 16
	ldr r4, =0xffff00ff
	ands r2, r4
	orrs r2, r0
	lsls r1, 24
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r2, r0
	orrs r2, r1
	ldr r0, =0x00ffffff
	ands r2, r0
	movs r0, 0xC0
	lsls r0, 19
	orrs r2, r0
	str r2, [sp]
	ldr r0, [sp, 0x4]
	ands r0, r5
	movs r1, 0x4
	orrs r0, r1
	ands r0, r4
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xAC
	lsls r1, 14
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	movs r1, 0x1
	movs r2, 0xD
	bl CreateYesNoMenu
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DB18

	thumb_func_start sub_802DB8C
sub_802DB8C: @ 802DB8C
	push {r4,lr}
	sub sp, 0x10
	ldr r1, =gUnknown_082FE1DC
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	add r0, sp, 0xC
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r0, =gText_SpacePoints2
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add r0, sp, 0xC
	str r0, [sp]
	str r4, [sp, 0x4]
	ldr r0, =gText_SpaceTimes3
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DB8C

	thumb_func_start sub_802DBF8
sub_802DBF8: @ 802DBF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	bl sub_802C8AC
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	ldr r1, =gUnknown_082FE260
	subs r0, 0x2
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r6, 0
	cmp r6, r10
	bge _0802DC62
	ldr r0, =gMonFrontPicCoords
	mov r9, r0
	ldr r1, =gUnknown_02022D00
	mov r8, r1
_0802DC26:
	lsls r4, r6, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_802C8C8
	adds r1, r0, 0
	ldrh r0, [r1]
	lsls r0, 2
	add r0, r9
	ldrb r3, [r0, 0x1]
	mov r2, r8
	ldr r0, [r2]
	movs r7, 0
	ldrsh r2, [r5, r7]
	adds r3, 0x70
	str r4, [sp]
	bl sub_802C9D4
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r2, 0x70
	adds r3, r4, 0
	bl sub_802CE48
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, r10
	blt _0802DC26
_0802DC62:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DBF8

	thumb_func_start sub_802DC80
sub_802DC80: @ 802DC80
	ldr r2, =gUnknown_02022D00
	ldr r2, [r2]
	lsls r0, 2
	ldr r3, =0x000081a8
	adds r2, r3
	adds r2, r0
	ldr r0, [r2]
	strh r1, [r0, 0x26]
	bx lr
	.pool
	thumb_func_end sub_802DC80

	thumb_func_start sub_802DC9C
sub_802DC9C: @ 802DC9C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_802CF50
	ldr r0, =gUnknown_082FE1DF
	adds r4, r0
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 13
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DC9C

	thumb_func_start sub_802DCCC
sub_802DCCC: @ 802DCCC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	movs r6, 0
_0802DCD6:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0802DCEA
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_802CB14
	adds r6, 0x1
_0802DCEA:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x4
	ble _0802DCD6
	subs r0, r6, 0x2
	lsls r0, 24
	lsrs r0, 24
	bl sub_802E00C
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DCCC

	thumb_func_start sub_802DD08
sub_802DD08: @ 802DD08
	push {r4,lr}
	sub sp, 0x10
	mov r1, sp
	movs r0, 0x40
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	movs r0, 0x6C
	strh r0, [r1, 0x4]
	movs r4, 0x6
	strh r4, [r1, 0x6]
	ldr r0, =gUnknown_082FE1EC
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_082FE1F4
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl sub_8034C54
	movs r0, 0
	movs r1, 0
	mov r2, sp
	bl sub_8034D14
	mov r1, sp
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x1E
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r4, [r0, 0x6]
	movs r0, 0x1
	movs r1, 0
	mov r2, sp
	bl sub_8034D14
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DD08

	thumb_func_start sub_802DD64
sub_802DD64: @ 802DD64
	push {lr}
	adds r1, r0, 0
	movs r0, 0
	bl sub_8035044
	pop {r0}
	bx r0
	thumb_func_end sub_802DD64

	thumb_func_start sub_802DD74
sub_802DD74: @ 802DD74
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1
	bl sub_8035044
	pop {r0}
	bx r0
	thumb_func_end sub_802DD74

	thumb_func_start sub_802DD88
sub_802DD88: @ 802DD88
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CBF0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DD88

	thumb_func_start sub_802DDA0
sub_802DDA0: @ 802DDA0
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CC88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDA0

	thumb_func_start sub_802DDB8
sub_802DDB8: @ 802DDB8
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CC18
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DDB8

	thumb_func_start sub_802DDCC
sub_802DDCC: @ 802DDCC
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CCB0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDCC

	thumb_func_start sub_802DDE0
sub_802DDE0: @ 802DDE0
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD3C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDE0

	thumb_func_start sub_802DDF4
sub_802DDF4: @ 802DDF4
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD70
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DDF4

	thumb_func_start sub_802DE08
sub_802DE08: @ 802DE08
	push {lr}
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	bl sub_802CD98
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802DE08

	thumb_func_start sub_802DE1C
sub_802DE1C: @ 802DE1C
	push {r4-r7,lr}
	sub sp, 0x8
	bl sub_802C8AC
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r1, =gUnknown_082FE234
	subs r0, r7, 0x2
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	ldr r2, =0xffffff00
	ldr r0, [sp]
	ands r0, r2
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 20
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, 0x4]
	ands r0, r2
	movs r1, 0x2
	orrs r0, r1
	ldr r1, =0xffff00ff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xAC
	lsls r1, 14
	orrs r0, r1
	str r0, [sp, 0x4]
	movs r5, 0
	cmp r5, r7
	bge _0802DEAC
	mov r6, sp
_0802DE6A:
	ldrb r0, [r4]
	lsls r0, 8
	ldr r2, =0xffff00ff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrb r2, [r4, 0x2]
	lsls r2, 16
	ldr r0, =0xff00ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	ldr r1, =gUnknown_02022D00
	ldr r1, [r1]
	lsls r2, r5, 1
	adds r1, 0x1C
	adds r1, r2
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl ClearWindowTilemap
	ldrh r0, [r6, 0x6]
	adds r0, 0x10
	strh r0, [r6, 0x6]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r7
	blt _0802DE6A
_0802DEAC:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DE1C

	thumb_func_start sub_802DED8
sub_802DED8: @ 802DED8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	strb r1, [r0]
	strb r2, [r0, 0x1]
	strb r3, [r0, 0x2]
	ldr r6, =gUnknown_02022D00
	ldr r0, [r6]
	lsls r1, r5, 1
	mov r8, r1
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl sub_802C8E8
	adds r1, r0, 0
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
	movs r0, 0x1
	bl GetStringWidth
	movs r4, 0x40
	subs r4, r0
	lsrs r4, 1
	adds r0, r5, 0
	bl sub_802C8E8
	adds r1, r0, 0
	ldr r0, [r6]
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	lsls r4, 24
	lsrs r4, 24
	add r2, sp, 0xC
	str r2, [sp]
	mov r2, r9
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldr r0, [r6]
	adds r0, 0x1C
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DED8

	thumb_func_start sub_802DF70
sub_802DF70: @ 802DF70
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r4, 0
	bne _0802DF9A
	movs r4, 0
	cmp r4, r5
	bge _0802DFCC
_0802DF86:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x3
	bl sub_802DED8
	adds r4, 0x1
	cmp r4, r5
	blt _0802DF86
	b _0802DFCC
_0802DF9A:
	bl sub_802C8BC
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
	cmp r4, r5
	bge _0802DFCC
_0802DFA8:
	cmp r6, r4
	beq _0802DFBA
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x3
	bl sub_802DED8
	b _0802DFC6
_0802DFBA:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x4
	movs r3, 0x5
	bl sub_802DED8
_0802DFC6:
	adds r4, 0x1
	cmp r4, r5
	blt _0802DFA8
_0802DFCC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802DF70

	thumb_func_start sub_802DFD4
sub_802DFD4: @ 802DFD4
	push {r4,r5,lr}
	bl sub_802C8AC
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0
	cmp r4, r5
	bge _0802DFFA
_0802DFE4:
	ldr r0, =gUnknown_02022D00
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r4, 0x1
	cmp r4, r5
	blt _0802DFE4
_0802DFFA:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802DFD4

	thumb_func_start sub_802E00C
sub_802E00C: @ 802E00C
	push {r4,lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_02022D00
	ldr r2, [r0]
	movs r0, 0
	str r0, [r2, 0x18]
	lsrs r1, 25
	lsls r1, 16
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	ands r4, r0
	lsls r4, 8
	subs r4, 0x28
	lsls r4, 8
	adds r1, r4, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	ldr r0, =sub_802E090
	movs r1, 0x4
	bl CreateTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E00C

	thumb_func_start sub_802E058
sub_802E058: @ 802E058
	push {r4,lr}
	ldr r4, =gUnknown_02022D00
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	cmp r0, 0x1F
	bls _0802E06C
	movs r0, 0
	b _0802E08A
	.pool
_0802E06C:
	movs r0, 0x1
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r0, 0x1
	str r0, [r1, 0x18]
	cmp r0, 0x1F
	bls _0802E088
	movs r0, 0x1
	bl HideBg
_0802E088:
	movs r0, 0x1
_0802E08A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E058

	thumb_func_start sub_802E090
sub_802E090: @ 802E090
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_802E058
	cmp r0, 0
	bne _0802E0A4
	adds r0, r4, 0
	bl DestroyTask
_0802E0A4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E090

	thumb_func_start sub_802E0AC
sub_802E0AC: @ 802E0AC
	push {lr}
	sub sp, 0xC
	mov r2, sp
	movs r1, 0x1
	strb r1, [r2]
	ldrh r1, [r0]
	strh r1, [r2, 0x2]
	ldr r1, [r0, 0x4]
	str r1, [sp, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_802E0AC

	thumb_func_start sub_802E0D0
sub_802E0D0: @ 802E0D0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r1, 0
	ldr r3, =gRecvCmds
	lsls r2, r0, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E100
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0802E108
_0802E100:
	movs r0, 0
	b _0802E118
	.pool
_0802E108:
	mov r0, sp
	ldrh r0, [r0, 0x2]
	strh r0, [r4]
	ldr r0, [sp, 0x8]
	str r0, [r4, 0x4]
	ldr r0, [sp, 0x4]
	str r0, [r4, 0x8]
	movs r0, 0x1
_0802E118:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E0D0

	thumb_func_start sub_802E120
sub_802E120: @ 802E120
	push {lr}
	sub sp, 0xC
	mov r2, sp
	movs r1, 0x2
	strb r1, [r2]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_802E120

	thumb_func_start sub_802E138
sub_802E138: @ 802E138
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r3, sp
	movs r2, 0x3
	strb r2, [r3]
	ldr r3, [r1, 0x8]
	lsls r3, 15
	ldr r2, [sp, 0x8]
	ldr r4, =0x00007fff
	mov r8, r4
	ands r2, r4
	orrs r2, r3
	str r2, [sp, 0x8]
	mov r6, sp
	ldrb r2, [r1, 0x1]
	movs r5, 0x1F
	adds r3, r5, 0
	ands r3, r2
	ldrb r4, [r6, 0x3]
	movs r2, 0x20
	negs r2, r2
	ands r2, r4
	orrs r2, r3
	strb r2, [r6, 0x3]
	mov r3, sp
	ldrb r2, [r1]
	strb r2, [r3, 0x1]
	ldrh r2, [r1, 0x2]
	strh r2, [r3, 0x6]
	mov r4, sp
	ldrh r2, [r1, 0x4]
	mov r1, r8
	ands r2, r1
	ldrh r3, [r4, 0x8]
	ldr r1, =0xffff8000
	ands r1, r3
	orrs r1, r2
	strh r1, [r4, 0x8]
	mov r2, sp
	ldrh r1, [r0, 0x10]
	strb r1, [r2, 0x2]
	mov r3, sp
	ldr r1, [r0, 0x14]
	lsls r1, 5
	ldrb r2, [r3, 0x3]
	ands r5, r2
	orrs r5, r1
	strb r5, [r3, 0x3]
	mov r1, sp
	ldrh r0, [r0, 0xE]
	strh r0, [r1, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E138

	thumb_func_start sub_802E1BC
sub_802E1BC: @ 802E1BC
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r2, =gRecvCmds
	ldrh r0, [r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802E228
	adds r1, r2, 0x2
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0802E228
	ldr r0, [sp, 0x8]
	lsrs r0, 15
	str r0, [r4, 0x8]
	mov r0, sp
	ldrb r1, [r0, 0x3]
	lsls r0, r1, 27
	lsrs r0, 27
	strb r0, [r4, 0x1]
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0, 0x6]
	strh r0, [r4, 0x2]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	lsls r0, 17
	lsrs r0, 17
	strh r0, [r4, 0x4]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	strh r0, [r5, 0x10]
	lsls r1, 24
	lsrs r1, 29
	str r1, [r5, 0x14]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0xE]
	movs r0, 0x1
	b _0802E22A
	.pool
_0802E228:
	movs r0, 0
_0802E22A:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802E1BC

	thumb_func_start sub_802E234
sub_802E234: @ 802E234
	push {r4,lr}
	sub sp, 0xC
	mov r4, sp
	movs r3, 0x4
	strb r3, [r4]
	ldrh r3, [r0, 0x10]
	strb r3, [r4, 0x1]
	ldr r3, [r0, 0x14]
	strb r3, [r4, 0x2]
	ldr r3, [r0, 0x18]
	strb r3, [r4, 0x3]
	mov r3, sp
	ldrh r0, [r0, 0xE]
	strh r0, [r3, 0x4]
	mov r0, sp
	strb r1, [r0, 0x6]
	strh r2, [r0, 0x8]
	bl sub_800FE50
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802E234

	thumb_func_start sub_802E264
sub_802E264: @ 802E264
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r3, =gRecvCmds
	lsls r2, r1, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E2C4
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0802E2C4
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strh r0, [r4, 0x10]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	str r0, [r4, 0x14]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	str r0, [r4, 0x18]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0xE]
	mov r0, sp
	ldrb r0, [r0, 0x6]
	strb r0, [r5]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	strh r0, [r6]
	movs r0, 0x1
	b _0802E2C6
	.pool
_0802E2C4:
	movs r0, 0
_0802E2C6:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802E264

	thumb_func_start sub_802E2D0
sub_802E2D0: @ 802E2D0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r3, =gRecvCmds
	lsls r2, r1, 4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	movs r1, 0xBC
	lsls r1, 6
	cmp r0, r1
	bne _0802E320
	adds r1, r3, 0x2
	adds r1, r2, r1
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0802E320
	mov r0, sp
	ldrb r0, [r0, 0x1]
	strh r0, [r4, 0x10]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	str r0, [r4, 0x14]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	str r0, [r4, 0x18]
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0xE]
	movs r0, 0x1
	b _0802E322
	.pool
_0802E320:
	movs r0, 0
_0802E322:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802E2D0

	thumb_func_start sub_802E32C
sub_802E32C: @ 802E32C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_802E32C

	thumb_func_start ResetPokeJumpResults
ResetPokeJumpResults: @ 802E33C
	push {lr}
	bl sub_802E32C
	movs r1, 0
	strh r1, [r0]
	str r1, [r0, 0xC]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	str r1, [r0, 0x8]
	strh r1, [r0, 0x2]
	pop {r0}
	bx r0
	thumb_func_end ResetPokeJumpResults

	thumb_func_start sub_802E354
sub_802E354: @ 802E354
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	bl sub_802E32C
	adds r1, r0, 0
	movs r2, 0
	ldr r0, [r1, 0xC]
	cmp r0, r4
	bcs _0802E378
	ldr r0, =0x00018696
	cmp r4, r0
	bhi _0802E378
	str r4, [r1, 0xC]
	movs r2, 0x1
_0802E378:
	ldrh r0, [r1]
	cmp r0, r5
	bcs _0802E388
	ldr r0, =0x0000270f
	cmp r5, r0
	bhi _0802E388
	strh r5, [r1]
	movs r2, 0x1
_0802E388:
	ldrh r0, [r1, 0x4]
	cmp r0, r6
	bcs _0802E398
	ldr r0, =0x0000270f
	cmp r6, r0
	bhi _0802E398
	strh r6, [r1, 0x4]
	movs r2, 0x1
_0802E398:
	adds r0, r2, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E354

	thumb_func_start sub_802E3A8
sub_802E3A8: @ 802E3A8
	push {lr}
	bl sub_802E32C
	adds r2, r0, 0
	ldrh r1, [r2, 0x6]
	ldr r0, =0x0000270e
	cmp r1, r0
	bhi _0802E3BC
	adds r0, r1, 0x1
	strh r0, [r2, 0x6]
_0802E3BC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E3A8

	thumb_func_start sub_802E3C4
sub_802E3C4: @ 802E3C4
	push {r4,lr}
	ldr r4, =sub_802E3E4
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E3C4

	thumb_func_start sub_802E3E4
sub_802E3E4: @ 802E3E4
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	beq _0802E4A8
	cmp r0, 0x1
	bgt _0802E40C
	cmp r0, 0
	beq _0802E416
	b _0802E4F6
	.pool
_0802E40C:
	cmp r0, 0x2
	beq _0802E4B4
	cmp r0, 0x3
	beq _0802E4DC
	b _0802E4F6
_0802E416:
	ldr r0, =gUnknown_082FE270
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gText_PkmnJumpRecords
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	movs r6, 0
	ldr r5, =gUnknown_082FE278
_0802E430:
	ldr r1, [r5]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r0, 0x26
	cmp r0, r4
	ble _0802E442
	adds r4, r0, 0
_0802E442:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x2
	bls _0802E430
	adds r0, r4, 0x7
	cmp r0, 0
	bge _0802E452
	adds r0, 0x7
_0802E452:
	asrs r4, r0, 3
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0802E45E
	adds r4, 0x1
_0802E45E:
	movs r1, 0x1E
	subs r1, r4
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r4, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x2]
	ldrh r0, [r7, 0x2]
	adds r1, r4, 0
	bl sub_802E500
	ldrb r0, [r7, 0x2]
	movs r1, 0x3
	b _0802E4CA
	.pool
_0802E4A8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802E4F6
	b _0802E4CE
_0802E4B4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0802E4F6
	ldrb r0, [r7, 0x2]
	bl rbox_fill_rectangle
	ldrb r0, [r7, 0x2]
	movs r1, 0x1
_0802E4CA:
	bl CopyWindowToVram
_0802E4CE:
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	b _0802E4F6
	.pool
_0802E4DC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802E4F6
	ldrb r0, [r7, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_0802E4F6:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802E3E4

	thumb_func_start sub_802E500
sub_802E500: @ 802E500
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x1C]
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
	bl sub_802E32C
	ldrh r1, [r0]
	str r1, [sp, 0xC]
	ldr r1, [r0, 0xC]
	str r1, [sp, 0x10]
	ldrh r0, [r0, 0x4]
	str r0, [sp, 0x14]
	ldr r0, [sp, 0x18]
	lsls r4, r0, 24
	lsrs r4, 24
	ldr r5, =0x0000021d
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD
	bl sub_8098858
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_PkmnJumpRecords
	ldr r1, [sp, 0x1C]
	lsls r2, r1, 3
	movs r0, 0x1
	adds r1, r5, 0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r6, 0
	adds r7, r4, 0
	movs r0, 0xFF
	mov r10, r0
	mov r9, r6
	mov r1, sp
	adds r1, 0xC
	str r1, [sp, 0x20]
	movs r0, 0xC8
	lsls r0, 21
	mov r8, r0
	ldr r5, =gStringVar1
_0802E58A:
	ldr r1, =gUnknown_082FE278
	lsls r0, r6, 2
	adds r0, r1
	ldr r2, [r0]
	mov r1, r8
	lsrs r4, r1, 24
	str r4, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [sp, 0x20]
	ldm r0!, {r1}
	str r0, [sp, 0x20]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0
	bl sub_802E620
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	ldr r1, [sp, 0x1C]
	lsls r3, r1, 3
	subs r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r4, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x80
	lsls r0, 21
	add r8, r0
	adds r6, 0x1
	ldr r1, [sp, 0x18]
	lsls r0, r1, 24
	cmp r6, 0x2
	bls _0802E58A
	lsrs r0, 24
	bl PutWindowTilemap
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E500

	thumb_func_start sub_802E620
sub_802E620: @ 802E620
	push {lr}
	adds r1, r0, 0
	b _0802E628
_0802E626:
	adds r1, 0x1
_0802E628:
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0802E636
	cmp r0, 0
	bne _0802E626
	movs r0, 0xFF
	strb r0, [r1]
_0802E636:
	pop {r0}
	bx r0
	thumb_func_end sub_802E620

	thumb_func_start sub_802E63C
sub_802E63C: @ 802E63C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_802E6D0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	strh r5, [r0, 0xA]
	ldr r0, =gUnknown_082FE748
	lsls r5, 4
	adds r5, r0
	ldr r1, [r5]
	adds r0, r4, 0
	bl _call_via_r1
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E63C

	thumb_func_start sub_802E688
sub_802E688: @ 802E688
	push {lr}
	ldr r0, =sub_802E6D0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0802E6B4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	movs r0, 0x1
	b _0802E6B6
	.pool
_0802E6B4:
	movs r0, 0
_0802E6B6:
	pop {r1}
	bx r1
	thumb_func_end sub_802E688

	thumb_func_start sub_802E6BC
sub_802E6BC: @ 802E6BC
	push {lr}
	ldr r0, =sub_802E6D0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802E6BC

	thumb_func_start sub_802E6D0
sub_802E6D0: @ 802E6D0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _0802E71C
	cmp r0, 0x3
	bgt _0802E6F8
	cmp r0, 0x2
	beq _0802E6FE
	b _0802E752
	.pool
_0802E6F8:
	cmp r0, 0x4
	beq _0802E738
	b _0802E752
_0802E6FE:
	ldr r1, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	lsls r0, 4
	adds r1, 0x8
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	movs r0, 0x3
	strh r0, [r4]
	b _0802E752
	.pool
_0802E71C:
	ldr r0, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 4
	adds r0, 0xC
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl _call_via_r1
	b _0802E752
	.pool
_0802E738:
	ldr r0, =gUnknown_082FE748
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 4
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl _call_via_r1
	adds r0, r5, 0
	bl DestroyTask
_0802E752:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E6D0

	thumb_func_start sub_802E75C
sub_802E75C: @ 802E75C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	lsls r0, 3
	ldr r1, =gUnknown_082FE6C8
	adds r0, r1
	bl LoadCompressedSpriteSheet
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 3
	ldr r1, =gUnknown_082FE6D8
	adds r0, r1
	bl LoadSpritePalette
	movs r5, 0
	movs r3, 0x10
	ldrsh r0, [r4, r3]
	cmp r5, r0
	bge _0802E7C4
_0802E790:
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldr r1, =gUnknown_082FE730
	adds r0, r1
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	movs r3, 0x14
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0xE]
	bl CreateSprite
	lsls r1, r5, 1
	adds r1, r4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x1A]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E790
_0802E7C4:
	movs r5, 0
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bge _0802E820
	movs r7, 0x3
	movs r3, 0xD
	negs r3, r3
	mov r12, r3
	ldr r6, =gSprites
_0802E7D8:
	lsls r0, r5, 1
	adds r0, r4
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrb r1, [r4, 0xC]
	ands r1, r7
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	mov r0, r12
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, 0xA]
	strh r0, [r2, 0x30]
	mov r3, r8
	strh r3, [r2, 0x34]
	strh r5, [r2, 0x36]
	ldrh r0, [r4, 0x1A]
	strh r0, [r2, 0x38]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E7D8
_0802E820:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E75C

	thumb_func_start sub_802E83C
sub_802E83C: @ 802E83C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r1, =gTasks + 0x8
	adds r4, r1
	movs r5, 0
	strh r5, [r4, 0x4]
	strh r5, [r4, 0x6]
	strh r5, [r4, 0x8]
	movs r1, 0x3C
	strh r1, [r4, 0xA]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	movs r1, 0x3
	strh r1, [r4, 0x10]
	movs r1, 0x78
	strh r1, [r4, 0x12]
	movs r1, 0x58
	strh r1, [r4, 0x14]
	adds r1, r4, 0
	bl sub_802E75C
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x4
	bl StartSpriteAnim
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x24]
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x5
	bl StartSpriteAnim
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x20
	strh r1, [r0, 0x24]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E83C

	thumb_func_start sub_802E8C8
sub_802E8C8: @ 802E8C8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	b _0802E8FC
	.pool
_0802E8E0:
	lsls r0, r5, 1
	adds r0, r4
	movs r2, 0x1A
	ldrsh r1, [r0, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0802E8FC:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E8E0
	ldr r1, =gUnknown_082FE6C8
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl FreeSpriteTilesByTag
	ldr r1, =gUnknown_082FE6D8
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802E8C8

	thumb_func_start sub_802E938
sub_802E938: @ 802E938
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0x34
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	movs r2, 0xA
	ldrsh r1, [r5, r2]
	bl __modsi3
	cmp r0, 0
	bne _0802EA4A
	ldrh r2, [r5, 0x16]
	movs r3, 0x16
	ldrsh r1, [r5, r3]
	movs r3, 0x14
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0802EA4A
	strh r2, [r5, 0x14]
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x4
	bhi _0802EA44
	lsls r0, 2
	ldr r1, =_0802E984
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802E984:
	.4byte _0802E998
	.4byte _0802E9A6
	.4byte _0802E9A6
	.4byte _0802E9BA
	.4byte _0802EA04
_0802E998:
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0802E9A6:
	movs r0, 0x38
	bl PlaySE
	ldrh r1, [r6, 0x32]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl StartSpriteAnim
	b _0802EA44
_0802E9BA:
	movs r0, 0x15
	bl PlaySE
	ldrh r1, [r6, 0x32]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl StartSpriteAnim
	ldr r4, =gSprites
	movs r2, 0x1C
	ldrsh r0, [r5, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r3, 0x1E
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	b _0802EA44
	.pool
_0802EA04:
	adds r1, r6, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r3, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x1E
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x4
	strh r0, [r5]
	b _0802EA4A
	.pool
_0802EA44:
	ldrh r0, [r6, 0x32]
	adds r0, 0x1
	strh r0, [r6, 0x32]
_0802EA4A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802E938

	thumb_func_start sub_802EA50
sub_802EA50: @ 802EA50
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	movs r0, 0x38
	bl PlaySE
	ldr r2, =gSprites
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_802E938
	str r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	subs r5, 0x8
	adds r4, r5
	movs r0, 0x3
	strh r0, [r4, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EA50

	thumb_func_start sub_802EAB0
sub_802EAB0: @ 802EAB0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802EB14
	ldr r1, =gRecvCmds
	ldrh r0, [r1, 0x2]
	ldr r5, =0x00007fff
	cmp r0, r5
	bne _0802EAD8
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x16]
_0802EAD8:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0802EB1A
	ldrh r0, [r4, 0x18]
	adds r0, 0x1
	strh r0, [r4, 0x18]
	mov r0, sp
	movs r1, 0
	movs r2, 0xC
	bl memset
	mov r0, sp
	strh r5, [r0]
	mov r1, sp
	ldrh r0, [r4, 0x18]
	strh r0, [r1, 0x2]
	mov r0, sp
	bl sub_800FE50
	b _0802EB1A
	.pool
_0802EB14:
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	strh r0, [r4, 0x16]
_0802EB1A:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802EAB0

	thumb_func_start sub_802EB24
sub_802EB24: @ 802EB24
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [sp, 0x18]
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =sub_802EB98
	movs r1, 0x50
	str r3, [sp]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r6, [r1, 0x10]
	ldr r3, [sp]
	strh r3, [r1, 0x12]
	mov r0, r8
	strh r0, [r1, 0x14]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EB24

	thumb_func_start sub_802EB84
sub_802EB84: @ 802EB84
	push {lr}
	ldr r0, =sub_802EB98
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EB84

	thumb_func_start sub_802EB98
sub_802EB98: @ 802EB98
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0802EC08
	cmp r0, 0x1
	bgt _0802EBC0
	cmp r0, 0
	beq _0802EBC6
	b _0802EC8A
	.pool
_0802EBC0:
	cmp r0, 0x2
	beq _0802EC4C
	b _0802EC8A
_0802EBC6:
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	bl sub_802EF50
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0xA
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0xC]
	str r4, [sp]
	bl sub_802EFA8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r5, 0x6]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0xA
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0xC]
	str r4, [sp]
	adds r4, r5, 0
	adds r4, 0x10
	str r4, [sp, 0x4]
	adds r4, 0x2
	str r4, [sp, 0x8]
	bl sub_802EFFC
	b _0802EC3E
_0802EC08:
	ldrb r0, [r5, 0xE]
	bl sub_802EC98
	cmp r0, 0
	bne _0802EC8A
	ldrb r0, [r5, 0xE]
	ldrb r1, [r5, 0x10]
	ldrb r2, [r5, 0x12]
	bl sub_802EDCC
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	movs r3, 0xE
	ldrsh r1, [r5, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0802EC3E:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0802EC8A
	.pool
_0802EC4C:
	ldrb r0, [r5, 0x10]
	bl sub_802EE30
	cmp r0, 0
	bne _0802EC8A
	movs r4, 0x10
	ldrsh r1, [r5, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r0, 0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldrh r0, [r5, 0x4]
	bl FreeSpriteTilesByTag
	ldrh r0, [r5, 0x6]
	bl FreeSpritePaletteByTag
	adds r0, r6, 0
	bl DestroyTask
_0802EC8A:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EB98

	thumb_func_start sub_802EC98
sub_802EC98: @ 802EC98
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r4, r1, r0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bls _0802ECB2
	b _0802EDC4
_0802ECB2:
	lsls r0, 2
	ldr r1, =_0802ECC4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802ECC4:
	.4byte _0802ECE4
	.4byte _0802ECF6
	.4byte _0802ED1C
	.4byte _0802ED2C
	.4byte _0802ED4E
	.4byte _0802ED86
	.4byte _0802EDAC
	.4byte _0802ED82
_0802ECE4:
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0x1A
	bl sub_8007E18
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0802ECF6:
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0802ED04
	movs r0, 0x39
	bl PlaySE
_0802ED04:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	movs r1, 0x1
	b _0802EDA2
_0802ED1C:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0802EDC4
	b _0802EDA6
_0802ED2C:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	b _0802EDC4
_0802ED4E:
	ldrh r0, [r4, 0x22]
	subs r0, 0x4
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0802EDC4
	ldrh r1, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	bgt _0802ED7E
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0802EDA6
_0802ED7E:
	movs r0, 0x7
	strh r0, [r4, 0x2E]
_0802ED82:
	movs r0, 0
	b _0802EDC6
_0802ED86:
	ldrh r0, [r4, 0x22]
	adds r0, 0x4
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0802EDC4
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r0, r4, 0
	movs r1, 0x3
_0802EDA2:
	bl StartSpriteAffineAnim
_0802EDA6:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	b _0802EDC2
_0802EDAC:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0802EDC4
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	movs r0, 0x1
_0802EDC2:
	strh r0, [r4, 0x2E]
_0802EDC4:
	movs r0, 0x1
_0802EDC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802EC98

	thumb_func_start sub_802EDCC
sub_802EDCC: @ 802EDCC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gSprites
	mov r8, r0
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r5, r4, r0
	ldr r0, =0x0000ffd8
	strh r0, [r5, 0x26]
	lsls r3, r2, 4
	adds r3, r2
	lsls r3, 2
	mov r1, r8
	adds r2, r3, r1
	strh r0, [r2, 0x26]
	adds r5, 0x3E
	ldrb r6, [r5]
	movs r1, 0x5
	negs r1, r1
	adds r0, r1, 0
	ands r0, r6
	strb r0, [r5]
	adds r2, 0x3E
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	movs r0, 0x1C
	add r8, r0
	add r4, r8
	ldr r0, =sub_802EE5C
	str r0, [r4]
	add r3, r8
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EDCC

	thumb_func_start sub_802EE30
sub_802EE30: @ 802EE30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r2, 0x1C
	adds r1, r2
	ldr r1, [r1]
	ldr r0, =sub_802EE5C
	cmp r1, r0
	bne _0802EE4E
	movs r3, 0x1
_0802EE4E:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EE30

	thumb_func_start sub_802EE5C
sub_802EE5C: @ 802EE5C
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x2E
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bhi _0802EF46
	lsls r0, 2
	ldr r1, =_0802EE7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802EE7C:
	.4byte _0802EE90
	.4byte _0802EEA0
	.4byte _0802EEC8
	.4byte _0802EEFC
	.4byte _0802EF34
_0802EE90:
	movs r0, 0x40
	strh r0, [r4, 0x8]
	ldrh r0, [r5, 0x26]
	lsls r0, 4
	strh r0, [r4, 0xA]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EEA0:
	ldrh r1, [r4, 0x8]
	ldrh r2, [r4, 0xA]
	adds r0, r1, r2
	strh r0, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r5, 0x26]
	cmp r0, 0
	blt _0802EF46
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r5, 0x26]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0802EF46
_0802EEC8:
	ldrh r0, [r4, 0x2]
	adds r0, 0xC
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0802EEE6
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EEE6:
	ldr r0, =gSineTable
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	asrs r0, 4
	b _0802EF2A
	.pool
_0802EEFC:
	ldrh r0, [r4, 0x2]
	adds r0, 0x10
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0802EF1A
	movs r0, 0x39
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_0802EF1A:
	ldr r1, =gSineTable
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
_0802EF2A:
	negs r0, r0
	strh r0, [r5, 0x26]
	b _0802EF46
	.pool
_0802EF34:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0802EF46
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
_0802EF46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EE5C

	thumb_func_start sub_802EF50
sub_802EF50: @ 802EF50
	push {r4,lr}
	sub sp, 0x10
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gUnknown_082FEBCC
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, 0x4]
	ldr r2, =gUnknown_082FEBD4
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	lsls r0, 16
	ldr r3, =0x0000ffff
	ldr r2, [sp, 0x4]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r2, =0xffff0000
	add r4, sp, 0x8
	ldr r0, [r4, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [r4, 0x4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	adds r0, r4, 0
	bl LoadSpritePalette
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EF50

	thumb_func_start sub_802EFA8
sub_802EFA8: @ 802EFA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r12, r3
	ldr r3, [sp, 0x30]
	lsls r1, 16
	lsrs r1, 16
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	mov r5, sp
	ldr r4, =gUnknown_082FEC90
	ldm r4!, {r3,r6,r7}
	stm r5!, {r3,r6,r7}
	ldm r4!, {r3,r6,r7}
	stm r5!, {r3,r6,r7}
	mov r4, sp
	strh r0, [r4]
	mov r0, sp
	strh r1, [r0, 0x2]
	lsls r2, 16
	asrs r2, 16
	mov r0, r12
	lsls r6, r0, 16
	asrs r6, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r6, 0
	mov r3, r8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802EFA8

	thumb_func_start sub_802EFFC
sub_802EFFC: @ 802EFFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r12, r3
	ldr r6, [sp, 0x38]
	ldr r3, [sp, 0x3C]
	mov r9, r3
	ldr r4, [sp, 0x40]
	mov r8, r4
	lsls r1, 16
	lsrs r1, 16
	lsls r6, 24
	lsrs r6, 24
	mov r10, r6
	mov r4, sp
	ldr r3, =gUnknown_082FECA8
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	mov r3, sp
	strh r0, [r3]
	mov r0, sp
	strh r1, [r0, 0x2]
	lsls r2, 16
	asrs r4, r2, 16
	ldr r0, =0xffe00000
	adds r2, r0
	asrs r2, 16
	mov r1, r12
	lsls r5, r1, 16
	asrs r5, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r5, 0
	mov r3, r10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r3, r9
	strh r0, [r3]
	adds r4, 0x20
	lsls r4, 16
	asrs r4, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r4, r8
	strh r0, [r4]
	ldr r2, =gSprites
	mov r5, r9
	movs r6, 0
	ldrsh r1, [r5, r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0]
	movs r7, 0
	ldrsh r1, [r4, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	bl StartSpriteAnim
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802EFFC

	.align 2, 0 @ don't pad with nop
