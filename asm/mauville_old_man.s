	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81200A0
sub_81200A0: @ 81200A0
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x00002e28
	adds r0, r2, r1
	movs r1, 0
	strb r1, [r0]
	ldr r3, =0x00002e51
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, =gGameLanguage
	ldrb r1, [r0]
	adds r3, 0x1
	adds r0, r2, r3
	strb r1, [r0]
	movs r3, 0
	ldr r0, =0x00002e2a
	adds r2, r0
	ldr r4, =gUnknown_0859EFE4
_081200C6:
	lsls r0, r3, 1
	adds r1, r2, r0
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _081200C6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81200A0

	thumb_func_start sub_81200F8
sub_81200F8: @ 81200F8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002e28
	adds r1, r0
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r2, [r1, 0x1]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	bx lr
	.pool
	thumb_func_end sub_81200F8

	thumb_func_start sub_812011C
sub_812011C: @ 812011C
	push {lr}
	bl sub_8120E08
	pop {r0}
	bx r0
	thumb_func_end sub_812011C

	thumb_func_start sub_8120128
sub_8120128: @ 8120128
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002e28
	adds r2, r1, r0
	movs r3, 0
	movs r0, 0x4
	strb r0, [r2]
	strb r3, [r2, 0x1]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	ldr r2, =0x00002e48
	adds r1, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8120128

	thumb_func_start sub_8120154
sub_8120154: @ 8120154
	push {lr}
	bl sub_81339F8
	pop {r0}
	bx r0
	thumb_func_end sub_8120154

	thumb_func_start SetMauvilleOldMan
SetMauvilleOldMan: @ 8120160
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0xB]
	lsls r1, 8
	ldrb r0, [r0, 0xA]
	orrs r0, r1
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 17
	cmp r0, 0x4
	bhi _081201C0
	lsls r0, 2
	ldr r1, =_08120190
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08120190:
	.4byte _081201A4
	.4byte _081201AA
	.4byte _081201B0
	.4byte _081201B6
	.4byte _081201BC
_081201A4:
	bl sub_81200A0
	b _081201C0
_081201AA:
	bl sub_81200F8
	b _081201C0
_081201B0:
	bl sub_8120154
	b _081201C0
_081201B6:
	bl sub_812011C
	b _081201C0
_081201BC:
	bl sub_8120128
_081201C0:
	bl sub_8120B5C
	pop {r0}
	bx r0
	thumb_func_end SetMauvilleOldMan

	thumb_func_start sub_81201C8
sub_81201C8: @ 81201C8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81201C8

	thumb_func_start sub_81201DC
sub_81201DC: @ 81201DC
	push {r4,lr}
	ldr r4, =gSpecialVar_Result
	bl sub_81201C8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81201DC

	thumb_func_start sub_81201F4
sub_81201F4: @ 81201F4
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e51
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81201F4

	thumb_func_start sub_8120210
sub_8120210: @ 8120210
	push {r4-r6,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002e28
	adds r6, r4, r0
	ldr r1, =0x00002e42
	adds r0, r4, r1
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	bl StringCopy
	movs r2, 0
	ldr r0, =0x00002e4d
	adds r4, r0
_0812022C:
	adds r1, r4, r2
	ldr r0, [r5]
	adds r0, 0xA
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3
	bls _0812022C
	movs r2, 0
	adds r5, r6, 0
	adds r5, 0x29
	adds r3, r6, 0x2
	adds r4, r6, 0
	adds r4, 0xE
_0812024E:
	lsls r0, r2, 1
	adds r1, r3, r0
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0812024E
	movs r0, 0x1
	strb r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120210

	thumb_func_start sub_8120280
sub_8120280: @ 8120280
	push {r4-r7,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	ldr r2, =0x00002e36
	adds r5, r1, r2
	cmp r0, 0
	bne _08120296
	ldr r0, =0x00002e2a
	adds r5, r1, r0
_08120296:
	ldr r2, =gStringVar4
	adds r4, r2, 0
	movs r6, 0
_0812029C:
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r2, 0
	bl CopyEasyChatWord
	adds r2, r0, 0
	adds r7, r6, 0x1
	cmp r2, r4
	beq _081202BE
	movs r1, 0x37
_081202B0:
	ldrb r0, [r4]
	cmp r0, 0
	bne _081202B8
	strb r1, [r4]
_081202B8:
	adds r4, 0x1
	cmp r2, r4
	bne _081202B0
_081202BE:
	adds r4, 0x1
	movs r0, 0
	strb r0, [r2]
	adds r2, 0x1
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r2, 0
	bl CopyEasyChatWord
	adds r2, r0, 0
	cmp r2, r4
	beq _081202E6
	movs r1, 0x37
_081202D8:
	ldrb r0, [r4]
	cmp r0, 0
	bne _081202E0
	strb r1, [r4]
_081202E0:
	adds r4, 0x1
	cmp r2, r4
	bne _081202D8
_081202E6:
	adds r4, 0x1
	movs r0, 0xFE
	strb r0, [r2]
	adds r2, 0x1
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r2, 0
	bl CopyEasyChatWord
	adds r2, r0, 0
	cmp r2, r4
	beq _0812030E
	movs r1, 0x37
_08120300:
	ldrb r0, [r4]
	cmp r0, 0
	bne _08120308
	strb r1, [r4]
_08120308:
	adds r4, 0x1
	cmp r2, r4
	bne _08120300
_0812030E:
	cmp r6, 0
	bne _0812031E
	movs r0, 0xFC
	strb r0, [r2]
	adds r2, 0x1
	movs r0, 0xF
	strb r0, [r2]
	adds r2, 0x1
_0812031E:
	lsls r0, r7, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _0812029C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120280

	thumb_func_start sub_8120340
sub_8120340: @ 8120340
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl sub_81206C0
	bl ScriptContext1_Stop
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120340

	thumb_func_start sub_8120358
sub_8120358: @ 8120358
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	ldrb r0, [r0, 0x1]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8120358

	thumb_func_start sub_8120374
sub_8120374: @ 8120374
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_8120374

	thumb_func_start sub_812038C
sub_812038C: @ 812038C
	push {lr}
	bl sub_811F01C
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081203AC
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081203B6
	.pool
_081203AC:
	ldr r0, =gStringVar1
	bl CopyEasyChatWord
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
_081203B6:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812038C

	thumb_func_start sub_81203C4
sub_81203C4: @ 81203C4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r2, r0, r1
	ldrb r0, [r2, 0x1]
	cmp r0, 0xA
	bne _081203EC
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	strb r0, [r2, 0x1]
	b _081203F2
	.pool
_081203EC:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081203F2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81203C4

	thumb_func_start sub_81203FC
sub_81203FC: @ 81203FC
	push {r4-r6,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002e28
	adds r5, r4, r0
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	bne _08120410
	bl sub_81204DC
_08120410:
	ldrb r0, [r5, 0x1]
	lsls r0, 1
	ldr r1, =0x00002e2c
	adds r6, r4, r1
	adds r0, r6, r0
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _08120480
	bl Random
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x7
	ands r4, r0
	ldr r0, =gStringVar4
	ldrb r1, [r5, 0x1]
	lsls r1, 1
	adds r1, r6, r1
	ldrh r1, [r1]
	bl CopyEasyChatWord
	adds r2, r0, 0
	ldr r1, =gUnknown_082942FD
	bl StringCopy
	adds r2, r0, 0
	ldr r0, =gUnknown_0859EFF0
	lsls r4, 2
	adds r4, r0
	ldr r1, [r4]
	adds r0, r2, 0
	bl StringCopy
	adds r2, r0, 0
	ldr r1, =gUnknown_08294301
	bl StringCopy
	b _081204A2
	.pool
_08120480:
	ldr r0, =gStringVar4
	ldr r3, =gUnknown_0859F010
	ldrb r2, [r5, 0x2]
	adds r1, r2, 0x1
	strb r1, [r5, 0x2]
	lsls r2, 24
	lsrs r2, 24
	movs r6, 0xB9
	lsls r6, 6
	adds r1, r4, r6
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl StringCopy
_081204A2:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081204C4
	movs r0, 0xA
	b _081204C8
	.pool
_081204C4:
	ldrb r0, [r5, 0x1]
	adds r0, 0x1
_081204C8:
	strb r0, [r5, 0x1]
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81203FC

	thumb_func_start sub_81204DC
sub_81204DC: @ 81204DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002e28
	adds r0, r4, r0
	str r0, [sp, 0x18]
	ldr r1, =gUnknown_0859F030
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	movs r5, 0
	movs r1, 0x2
	add r1, sp
	mov r8, r1
	movs r2, 0xB9
	lsls r2, 6
	adds r3, r4, r2
	adds r1, r3, 0
_0812050C:
	adds r0, r3, r5
	strb r5, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _0812050C
	movs r5, 0
	ldr r3, [sp, 0x18]
	adds r3, 0x4
	mov r9, r3
	adds r6, r1, 0
_08120524:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r4, r5, 0x1
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r6, r5
	ldrb r7, [r2]
	adds r1, r6, r1
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	lsls r4, 16
	lsrs r5, r4, 16
	cmp r5, 0x7
	bls _08120524
	movs r0, 0
	mov r10, r0
	movs r5, 0
_08120552:
	lsls r4, r5, 2
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl start_menu_is_selected_item_valid
	add r4, r8
	strh r0, [r4]
	add r0, r10
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _08120552
	movs r0, 0
	ldr r2, [sp, 0x18]
	strb r0, [r2, 0x2]
	movs r7, 0
	movs r5, 0
_0812057E:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x2
	bhi _081205BC
	cmp r7, 0x7
	bhi _081205BC
	lsls r0, r5, 1
	add r0, r9
	ldr r1, =0x0000ffff
	strh r1, [r0]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	adds r4, r5, 0x1
	b _0812060E
	.pool
_081205BC:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r10
	bl __umodsi3
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	adds r4, r5, 0x1
	lsls r6, r5, 1
	cmp r5, 0x5
	bhi _081205F8
	mov r3, r8
	ldrh r0, [r3]
	b _081205EE
_081205DE:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r5, 0x5
	bhi _081205F8
	lsls r0, r1, 2
	adds r0, r3, r0
	ldrh r0, [r0]
_081205EE:
	subs r0, r2, r0
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r0, 0
	bgt _081205DE
_081205F8:
	cmp r1, 0x6
	bne _081205FE
	movs r1, 0
_081205FE:
	lsls r0, r1, 2
	add r0, sp
	ldrh r0, [r0]
	bl sub_811EE90
	mov r2, r9
	adds r1, r2, r6
	strh r0, [r1]
_0812060E:
	lsls r0, r4, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _0812057E
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81204DC

	thumb_func_start sub_8120628
sub_8120628: @ 8120628
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e51
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8120628

	thumb_func_start sub_8120640
sub_8120640: @ 8120640
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	movs r1, 0
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_8120640

	thumb_func_start sub_8120658
sub_8120658: @ 8120658
	push {lr}
	bl sub_8133A60
	pop {r0}
	bx r0
	thumb_func_end sub_8120658

	thumb_func_start sub_8120664
sub_8120664: @ 8120664
	push {lr}
	bl sub_8120E50
	pop {r0}
	bx r0
	thumb_func_end sub_8120664

	thumb_func_start sub_8120670
sub_8120670: @ 8120670
	push {lr}
	bl sub_81201C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _081206B6
	lsls r0, 2
	ldr r1, =_0812068C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812068C:
	.4byte _081206A0
	.4byte _081206A6
	.4byte _081206B2
	.4byte _081206AC
	.4byte _081206B6
_081206A0:
	bl sub_8120628
	b _081206B6
_081206A6:
	bl sub_8120640
	b _081206B6
_081206AC:
	bl sub_8120664
	b _081206B6
_081206B2:
	bl sub_8120658
_081206B6:
	bl sub_8120B5C
	pop {r0}
	bx r0
	thumb_func_end sub_8120670

	thumb_func_start sub_81206C0
sub_81206C0: @ 81206C0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_8120944
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x12]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81206C0

	thumb_func_start sub_81206F0
sub_81206F0: @ 81206F0
	ldr r1, =gUnknown_03002F84
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81206F0

	thumb_func_start sub_81206FC
sub_81206FC: @ 81206FC
	ldr r1, =gUnknown_03002F84
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81206FC

	thumb_func_start sub_8120708
sub_8120708: @ 8120708
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r0, =sub_81206FC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl PrintTextOnWindow
	ldr r0, =gUnknown_03002F84
	strb r4, [r0]
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120708

	thumb_func_start sub_8120748
sub_8120748: @ 8120748
	push {r4-r6,lr}
	adds r6, r1, 0
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	bls _08120756
	b _08120938
_08120756:
	lsls r0, 2
	ldr r1, =_08120764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08120764:
	.4byte _0812077C
	.4byte _08120938
	.4byte _081207BC
	.4byte _081207F8
	.4byte _081207F8
	.4byte _08120938
_0812077C:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	ldr r3, =0x00002e36
	adds r1, r2, r3
	cmp r0, 0
	bne _08120790
	ldr r0, =0x00002e2a
	adds r1, r2, r0
_08120790:
	adds r2, r1, 0
	adds r1, r6, 0
	adds r1, 0xC
	movs r3, 0x5
_08120798:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08120798
	movs r0, 0
	strb r0, [r6]
	b _08120938
	.pool
_081207BC:
	ldrb r1, [r6]
	lsls r1, 1
	adds r0, r6, 0
	adds r0, 0xC
	adds r0, r1
	ldrh r4, [r0]
	adds r0, r4, 0
	bl GetWordSounds
	str r0, [r6, 0x30]
	movs r1, 0x3
	ands r1, r4
	lsrs r4, 3
	movs r0, 0x1
	ands r4, r0
	adds r1, r4
	adds r0, r6, 0
	bl GetWordPhonemes
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	ldr r0, [r6, 0x30]
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081207F4
	movs r0, 0
	b _08120936
_081207F4:
	movs r0, 0x3
	b _0812091A
_081207F8:
	ldrb r3, [r6, 0x1]
	lsls r1, r3, 3
	ldr r0, [r6, 0x30]
	adds r2, r0, r1
	ldrb r1, [r6, 0x3]
	cmp r1, 0x1
	beq _081208A0
	cmp r1, 0x1
	bgt _08120810
	cmp r1, 0
	beq _0812081C
	b _08120938
_08120810:
	cmp r1, 0x2
	beq _08120850
	cmp r1, 0x3
	bne _0812081A
	b _08120922
_0812081A:
	b _08120938
_0812081C:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x18]
	strb r0, [r6, 0x2]
	ldrb r0, [r2]
	cmp r0, 0x32
	bhi _08120844
	movs r1, 0x3
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	movs r1, 0x8C
	lsls r1, 2
	adds r0, r1
	bl m4aSongNumStart
_08120844:
	movs r0, 0x2
	strb r0, [r6, 0x3]
	ldrb r0, [r6, 0x2]
	subs r0, 0x1
	strb r0, [r6, 0x2]
	b _08120938
_08120850:
	movs r0, 0x1
	strb r0, [r6, 0x3]
	ldrb r0, [r2]
	cmp r0, 0x32
	bhi _08120938
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r6, 0x6]
	ldr r4, =gMPlayInfo_SE2
	ldr r5, =0x0000ffff
	ldrh r2, [r6, 0x6]
	adds r0, r4, 0
	adds r1, r5, 0
	bl m4aMPlayVolumeControl
	ldrb r1, [r6, 0x1]
	lsls r1, 2
	adds r1, r6, r1
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ldrh r1, [r1, 0x1A]
	adds r0, r1
	strh r0, [r6, 0x8]
	movs r3, 0x8
	ldrsh r2, [r6, r3]
	adds r0, r4, 0
	adds r1, r5, 0
	bl m4aMPlayPitchControl
	b _08120938
	.pool
_081208A0:
	ldrh r2, [r6, 0xA]
	movs r3, 0xA
	ldrsh r0, [r6, r3]
	cmp r0, 0xA
	ble _081208B0
	ldrh r0, [r6, 0x6]
	subs r0, 0x2
	strh r0, [r6, 0x6]
_081208B0:
	ands r1, r2
	cmp r1, 0
	beq _081208BC
	ldrh r0, [r6, 0x8]
	adds r0, 0x40
	b _081208C0
_081208BC:
	ldrh r0, [r6, 0x8]
	subs r0, 0x40
_081208C0:
	strh r0, [r6, 0x8]
	ldr r4, =gMPlayInfo_SE2
	ldr r5, =0x0000ffff
	ldrh r2, [r6, 0x6]
	adds r0, r4, 0
	adds r1, r5, 0
	bl m4aMPlayVolumeControl
	movs r0, 0x8
	ldrsh r2, [r6, r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl m4aMPlayPitchControl
	ldrh r0, [r6, 0xA]
	adds r0, 0x1
	strh r0, [r6, 0xA]
	ldrb r0, [r6, 0x2]
	subs r0, 0x1
	strb r0, [r6, 0x2]
	lsls r0, 24
	cmp r0, 0
	bne _08120938
	ldrb r0, [r6, 0x1]
	adds r0, 0x1
	strb r0, [r6, 0x1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08120918
	ldrb r0, [r6, 0x1]
	ldr r1, [r6, 0x30]
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08120918
	movs r0, 0
	b _08120936
	.pool
_08120918:
	movs r0, 0x3
_0812091A:
	strb r0, [r6, 0x3]
	movs r0, 0x2
	strb r0, [r6, 0x2]
	b _08120938
_08120922:
	ldrb r0, [r6, 0x2]
	subs r0, 0x1
	strb r0, [r6, 0x2]
	lsls r0, 24
	cmp r0, 0
	bne _08120938
	ldr r0, =gMPlayInfo_SE2
	bl m4aMPlayStop
	movs r0, 0x4
_08120936:
	strb r0, [r6, 0x3]
_08120938:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120748

	thumb_func_start sub_8120944
sub_8120944: @ 8120944
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldr r1, =gUnknown_03006130
	adds r0, r5, 0
	bl sub_8120748
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x5
	bls _08120966
	b _08120B50
_08120966:
	lsls r0, 2
	ldr r1, =_0812097C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812097C:
	.4byte _08120994
	.4byte _081209B8
	.4byte _081209C8
	.4byte _08120A7E
	.4byte _08120B40
	.4byte _08120A6E
_08120994:
	bl sub_8120280
	ldr r0, =gStringVar4
	bl sub_8120708
	movs r0, 0
	strh r0, [r5, 0xA]
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	strh r0, [r5, 0x10]
	movs r0, 0x4
	bl FadeOutBGMTemporarily
	movs r0, 0x1
	b _08120B4E
	.pool
_081209B8:
	bl IsBGMPausedOrStopped
	lsls r0, 24
	cmp r0, 0
	bne _081209C4
	b _08120B50
_081209C4:
	movs r0, 0x2
	b _08120B4E
_081209C8:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r4, r0, r2
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	ldr r0, =gStringVar4
	adds r1, r0
	movs r3, 0
	ldrb r0, [r1]
	ldr r7, =gUnknown_03006130
	ldrh r2, [r5, 0x12]
	ldr r6, =gUnknown_0203A128
	b _08120A02
	.pool
_081209F8:
	adds r1, 0x1
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrb r0, [r1]
_08120A02:
	cmp r0, 0
	beq _08120A12
	cmp r0, 0xFE
	beq _08120A12
	cmp r0, 0xFC
	beq _08120A12
	cmp r0, 0xFF
	bne _081209F8
_08120A12:
	cmp r2, 0
	bne _08120A20
	movs r2, 0x10
	ldrsh r1, [r5, r2]
	lsls r1, 1
	adds r0, r4, 0x2
	b _08120A2A
_08120A20:
	movs r0, 0x10
	ldrsh r1, [r5, r0]
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0xE
_08120A2A:
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	lsrs r0, 3
	movs r2, 0x1
	ands r0, r2
	adds r1, r0
	strh r1, [r6]
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	adds r1, r3, 0
	bl __divsi3
	movs r1, 0
	strh r0, [r7, 0x4]
	lsls r0, 16
	cmp r0, 0
	bgt _08120A54
	movs r0, 0x1
	strh r0, [r7, 0x4]
_08120A54:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _08120A66
	movs r0, 0x3
	b _08120A68
_08120A66:
	movs r0, 0x5
_08120A68:
	strh r0, [r5, 0x8]
	strh r1, [r5, 0xA]
	b _08120B50
_08120A6E:
	ldrh r1, [r5, 0xC]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _08120B4C
	subs r0, r1, 0x1
	strh r0, [r5, 0xC]
	b _08120B50
_08120A7E:
	ldr r1, =gStringVar4
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	adds r0, r1
	ldrb r4, [r0]
	cmp r4, 0xFF
	bne _08120AB0
	movs r0, 0x6
	bl FadeInBGM
	ldr r0, =gMPlayInfo_SE2
	movs r1, 0x2
	bl m4aMPlayFadeOutTemporarily
	bl EnableBothScriptContexts
	adds r0, r6, 0
	bl DestroyTask
	b _08120B50
	.pool
_08120AB0:
	cmp r4, 0
	bne _08120AC6
	bl sub_81206F0
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	movs r0, 0x2
	strh r0, [r5, 0x8]
	strh r4, [r5, 0xC]
	b _08120B50
_08120AC6:
	cmp r4, 0xFE
	bne _08120ADA
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0xE]
	movs r0, 0x2
	strh r0, [r5, 0x8]
	strh r1, [r5, 0xC]
	b _08120B50
_08120ADA:
	cmp r4, 0xFC
	bne _08120AEE
	ldrh r0, [r5, 0xE]
	adds r0, 0x2
	strh r0, [r5, 0xE]
	movs r0, 0x2
	strh r0, [r5, 0x8]
	movs r0, 0x8
	strh r0, [r5, 0xC]
	b _08120B50
_08120AEE:
	cmp r4, 0x37
	bne _08120B04
	movs r4, 0
	strb r4, [r0]
	bl sub_81206F0
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	strh r4, [r5, 0xC]
	b _08120B50
_08120B04:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08120B20
	cmp r0, 0x1
	bgt _08120B16
	cmp r0, 0
	beq _08120B1C
	b _08120B50
_08120B16:
	cmp r0, 0x2
	beq _08120B28
	b _08120B50
_08120B1C:
	bl sub_81206F0
_08120B20:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _08120B50
_08120B28:
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0xE]
	strh r1, [r5, 0xA]
	ldr r0, =gUnknown_03006130
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0xC]
	movs r0, 0x4
	b _08120B4E
	.pool
_08120B40:
	ldrh r0, [r5, 0xC]
	subs r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _08120B50
_08120B4C:
	movs r0, 0x3
_08120B4E:
	strh r0, [r5, 0x8]
_08120B50:
	bl sub_8197224
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8120944

	thumb_func_start sub_8120B5C
sub_8120B5C: @ 8120B5C
	push {lr}
	ldr r0, =0x00004010
	movs r1, 0x45
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120B5C

	thumb_func_start sub_8120B70
sub_8120B70: @ 8120B70
	push {r4-r7,lr}
	sub sp, 0x8
	ldrb r1, [r0]
	cmp r1, 0x2
	beq _08120B80
	cmp r1, 0x3
	beq _08120BA6
	b _08120C00
_08120B80:
	adds r5, r0, 0
	movs r4, 0
_08120B84:
	adds r0, r5, 0
	adds r0, 0x32
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08120B9E
	movs r0, 0xB
	muls r0, r4
	adds r0, 0x5
	adds r0, r5, r0
	movs r1, 0x1
	bl ConvertInternationalString
_08120B9E:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08120B84
	b _08120C00
_08120BA6:
	adds r6, r0, 0
	movs r4, 0
	mov r7, sp
	adds r5, r6, 0
	adds r5, 0x8
_08120BB0:
	adds r0, r6, 0x4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08120BF8
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x7
	bl memcpy
	movs r0, 0xFF
	strb r0, [r7, 0x7]
	mov r0, sp
	bl IsStringJapanese
	cmp r0, 0
	beq _08120BF8
	mov r0, sp
	movs r1, 0
	movs r2, 0x8
	bl memset
	mov r0, sp
	ldr r1, =gText_Friend
	bl StringCopy
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x7
	bl memcpy
	adds r0, r6, 0
	adds r0, 0x34
	adds r0, r4
	movs r1, 0x2
	strb r1, [r0]
_08120BF8:
	adds r5, 0x7
	adds r4, 0x1
	cmp r4, 0x3
	ble _08120BB0
_08120C00:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120B70

	thumb_func_start sub_8120C0C
sub_8120C0C: @ 8120C0C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r7, r2, 0
	ldrb r0, [r5]
	cmp r0, 0x4
	bhi _08120CC4
	lsls r0, 2
	ldr r1, =_08120C2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08120C2C:
	.4byte _08120C92
	.4byte _08120CA2
	.4byte _08120C40
	.4byte _08120C6A
	.4byte _08120CB0
_08120C40:
	adds r6, r5, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0x32
_08120C48:
	movs r0, 0xB
	muls r0, r5
	adds r0, 0x5
	adds r0, r6, r0
	bl IsStringJapanese
	cmp r0, 0
	beq _08120C5E
	mov r0, r8
	strb r0, [r4]
	b _08120C60
_08120C5E:
	strb r7, [r4]
_08120C60:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0x3
	ble _08120C48
	b _08120CC4
_08120C6A:
	adds r4, r5, 0
	adds r4, 0x34
	adds r6, r5, 0
	adds r6, 0x8
	movs r5, 0x3
_08120C74:
	adds r0, r6, 0
	bl IsStringJapanese
	cmp r0, 0
	beq _08120C84
	mov r1, r8
	strb r1, [r4]
	b _08120C86
_08120C84:
	strb r7, [r4]
_08120C86:
	adds r4, 0x1
	adds r6, 0x7
	subs r5, 0x1
	cmp r5, 0
	bge _08120C74
	b _08120CC4
_08120C92:
	cmp r3, 0x1
	bne _08120C9C
	adds r0, r5, 0
	adds r0, 0x2A
	b _08120CB8
_08120C9C:
	adds r0, r5, 0
	adds r0, 0x2A
	b _08120CC2
_08120CA2:
	cmp r3, 0x1
	bne _08120CAC
	mov r0, r8
	strb r0, [r5, 0x2]
	b _08120CC4
_08120CAC:
	strb r7, [r5, 0x2]
	b _08120CC4
_08120CB0:
	cmp r3, 0x1
	bne _08120CBE
	adds r0, r5, 0
	adds r0, 0x20
_08120CB8:
	mov r1, r8
	strb r1, [r0]
	b _08120CC4
_08120CBE:
	adds r0, r5, 0
	adds r0, 0x20
_08120CC2:
	strb r7, [r0]
_08120CC4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8120C0C

	thumb_func_start sub_8120CD0
sub_8120CD0: @ 8120CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _08120D28
	cmp r2, 0x1
	bne _08120D28
	adds r7, r1, 0
	movs r6, 0
	mov r8, sp
	adds r4, r7, 0
	adds r4, 0x34
	adds r5, r7, 0
	adds r5, 0x8
_08120CF2:
	adds r0, r7, 0x4
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08120D1E
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x7
	bl memcpy
	movs r0, 0xFF
	mov r1, r8
	strb r0, [r1, 0x7]
	mov r0, sp
	bl IsStringJapanese
	cmp r0, 0
	beq _08120D1A
	movs r0, 0x1
	b _08120D1C
_08120D1A:
	movs r0, 0x2
_08120D1C:
	strb r0, [r4]
_08120D1E:
	adds r4, 0x1
	adds r5, 0x7
	adds r6, 0x1
	cmp r6, 0x3
	ble _08120CF2
_08120D28:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8120CD0

	thumb_func_start sub_8120D34
sub_8120D34: @ 8120D34
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r6, r2, 0
	movs r2, 0
	subs r1, 0x1
	cmp r1, 0x1
	bhi _08120D44
	movs r2, 0x1
_08120D44:
	ldrb r0, [r3]
	cmp r0, 0x4
	bhi _08120E02
	lsls r0, 2
	ldr r1, =_08120D58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08120D58:
	.4byte _08120DE6
	.4byte _08120DF0
	.4byte _08120D6C
	.4byte _08120DC6
	.4byte _08120DF8
_08120D6C:
	adds r7, r3, 0
	cmp r2, 0
	beq _08120DA4
	movs r5, 0
	adds r4, r3, 0
	adds r4, 0x32
_08120D78:
	movs r0, 0xB
	muls r0, r5
	adds r0, 0x5
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, 0xFC
	bne _08120D98
	ldrb r0, [r1, 0x1]
	cmp r0, 0x15
	bne _08120D98
	adds r0, r1, 0
	bl StripExtCtrlCodes
	movs r0, 0x1
	strb r0, [r4]
	b _08120D9A
_08120D98:
	strb r6, [r4]
_08120D9A:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0x3
	ble _08120D78
	b _08120E02
_08120DA4:
	movs r5, 0
	adds r4, r3, 0
	adds r4, 0x32
_08120DAA:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08120DBE
	movs r0, 0xB
	muls r0, r5
	adds r0, 0x5
	adds r0, r7, r0
	bl StripExtCtrlCodes
_08120DBE:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08120DAA
	b _08120E02
_08120DC6:
	cmp r2, 0
	beq _08120E02
	movs r1, 0
	adds r4, r3, 0x4
	adds r2, r3, 0
	adds r2, 0x34
_08120DD2:
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08120DDE
	adds r0, r2, r1
	strb r6, [r0]
_08120DDE:
	adds r1, 0x1
	cmp r1, 0x3
	ble _08120DD2
	b _08120E02
_08120DE6:
	cmp r2, 0
	beq _08120E02
	adds r0, r3, 0
	adds r0, 0x2A
	b _08120E00
_08120DF0:
	cmp r2, 0
	beq _08120E02
	strb r6, [r3, 0x2]
	b _08120E02
_08120DF8:
	cmp r2, 0
	beq _08120E02
	adds r0, r3, 0
	adds r0, 0x20
_08120E00:
	strb r6, [r0]
_08120E02:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8120D34

	thumb_func_start sub_8120E08
sub_8120E08: @ 8120E08
	push {r4,r5,lr}
	ldr r2, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	str r0, [r2]
	movs r3, 0
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	movs r5, 0
	movs r4, 0xFF
_08120E24:
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r3
	strb r5, [r0]
	ldr r1, [r2]
	adds r1, 0x8
	adds r1, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x3
	ble _08120E24
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120E08

	thumb_func_start sub_8120E50
sub_8120E50: @ 8120E50
	ldr r3, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r0, r1
	str r0, [r3]
	movs r2, 0
	movs r1, 0x3
	strb r1, [r0]
	ldr r0, [r3]
	strb r2, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_8120E50

	thumb_func_start sub_8120E74
sub_8120E74: @ 8120E74
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x32
	bne _08120E80
	movs r0, 0
_08120E80:
	bl GetGameStat
	pop {r1}
	bx r1
	thumb_func_end sub_8120E74

	thumb_func_start sub_8120E88
sub_8120E88: @ 8120E88
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =gUnknown_0859F048
_08120E90:
	ldrb r0, [r1]
	cmp r0, r3
	bne _08120EA0
	adds r0, r1, 0
	b _08120EAA
	.pool
_08120EA0:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x23
	ble _08120E90
	ldr r0, =gUnknown_0859F278
_08120EAA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8120E88

	thumb_func_start sub_8120EB4
sub_8120EB4: @ 8120EB4
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0x4]
	pop {r1}
	bx r1
	thumb_func_end sub_8120EB4

	thumb_func_start sub_8120EC0
sub_8120EC0: @ 8120EC0
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_8120EC0

	thumb_func_start sub_8120ECC
sub_8120ECC: @ 8120ECC
	push {lr}
	bl sub_8120E88
	ldr r0, [r0, 0x8]
	pop {r1}
	bx r1
	thumb_func_end sub_8120ECC

	thumb_func_start sub_8120ED8
sub_8120ED8: @ 8120ED8
	push {lr}
	movs r1, 0
	ldr r2, =gUnknown_0203A12C
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08120EFC
_08120EE6:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bhi _08120EFC
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08120EE6
_08120EFC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8120ED8

	thumb_func_start sub_8120F08
sub_8120F08: @ 8120F08
	ldr r1, =gUnknown_0203A12C
	lsls r0, 2
	adds r0, 0x24
	ldr r2, [r1]
	adds r2, r0
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 24
	orrs r0, r1
	bx lr
	.pool
	thumb_func_end sub_8120F08

	thumb_func_start sub_8120F2C
sub_8120F2C: @ 8120F2C
	ldr r2, =gUnknown_0203A12C
	lsls r0, 2
	adds r0, 0x24
	ldr r2, [r2]
	adds r2, r0
	strb r1, [r2]
	lsrs r0, r1, 8
	strb r0, [r2, 0x1]
	lsrs r0, r1, 16
	strb r0, [r2, 0x2]
	lsrs r1, 24
	strb r1, [r2, 0x3]
	bx lr
	.pool
	thumb_func_end sub_8120F2C

	thumb_func_start sub_8120F4C
sub_8120F4C: @ 8120F4C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8120E74
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8120F08
	cmp r4, r0
	bhi _08120F74
	movs r0, 0
	b _08120F76
	.pool
_08120F74:
	movs r0, 0x1
_08120F76:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8120F4C

	thumb_func_start sub_8120F7C
sub_8120F7C: @ 8120F7C
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0203A12C
	lsls r1, r0, 3
	subs r1, r0
	adds r1, 0x8
	ldr r4, [r2]
	adds r4, r1
	adds r0, r5, 0
	movs r1, 0xFF
	movs r2, 0x8
	bl memset
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl memcpy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120F7C

	thumb_func_start sub_8120FAC
sub_8120FAC: @ 8120FAC
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r2, =gUnknown_0203A12C
	lsls r1, r0, 3
	subs r1, r0
	adds r1, 0x8
	ldr r4, [r2]
	adds r4, r1
	adds r0, r4, 0
	movs r1, 0xFF
	movs r2, 0x7
	bl memset
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl memcpy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120FAC

	thumb_func_start sub_8120FDC
sub_8120FDC: @ 8120FDC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	adds r6, r1, 0
	ldr r0, =gUnknown_0203A12C
	mov r9, r0
	ldr r0, [r0]
	adds r0, 0x4
	add r0, r8
	strb r6, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	mov r0, r8
	bl sub_8120FAC
	lsls r4, r6, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8120E74
	adds r1, r0, 0
	mov r0, r8
	bl sub_8120F2C
	ldr r5, =gStringVar1
	adds r0, r4, 0
	bl sub_8120E74
	adds r1, r0, 0
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xA
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	adds r0, r6, 0
	bl sub_8120ECC
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x34
	add r0, r8
	ldr r1, =gGameLanguage
	ldrb r1, [r1]
	strb r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8120FDC

	thumb_func_start sub_8121064
sub_8121064: @ 8121064
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	movs r5, 0
	cmp r5, r6
	bge _0812107A
_08121070:
	adds r0, r7, r5
	strb r5, [r0]
	adds r5, 0x1
	cmp r5, r6
	blt _08121070
_0812107A:
	cmp r6, 0
	ble _081210B0
	adds r5, r6, 0
_08121080:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r4, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r4, r7, r4
	ldrb r2, [r4]
	adds r0, r7, r0
	ldrb r1, [r0]
	strb r1, [r4]
	strb r2, [r0]
	subs r5, 0x1
	cmp r5, 0
	bne _08121080
_081210B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8121064

	thumb_func_start sub_81210B8
sub_81210B8: @ 81210B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r7, sp
	mov r8, sp
	ldr r0, =gUnknown_0859F288
	ldr r0, [r0]
	lsls r0, 3
	lsrs r0, 3
	adds r0, 0x3
	lsrs r0, 2
	lsls r0, 2
	mov r1, sp
	subs r1, r0
	mov sp, r1
	mov r9, sp
	mov r0, sp
	movs r1, 0x24
	bl sub_8121064
	movs r5, 0
_081210E4:
	ldr r1, =gUnknown_0859F048
	mov r2, r9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r4, [r0]
	ldrb r6, [r0, 0x1]
	movs r1, 0
	ldr r2, =gUnknown_0203A12C
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	cmp r0, r4
	beq _08121112
_08121100:
	adds r1, 0x1
	cmp r1, 0x3
	bgt _08121112
	ldr r0, [r2]
	adds r0, 0x4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, r4
	bne _08121100
_08121112:
	cmp r1, 0x4
	bne _08121162
	adds r0, r4, 0
	bl sub_8120E74
	cmp r0, r6
	bcc _08121162
	ldr r0, =gUnknown_0203A12C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _08121150
	ldr r0, =gUnknown_03001178
	ldrb r0, [r0]
	adds r1, r4, 0
	bl sub_8120FDC
	b _0812115E
	.pool
_08121150:
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_8120FDC
_0812115E:
	movs r0, 0x1
	b _0812116A
_08121162:
	adds r5, 0x1
	cmp r5, 0x23
	ble _081210E4
	movs r0, 0
_0812116A:
	mov sp, r8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81210B8

	thumb_func_start sub_8121178
sub_8121178: @ 8121178
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	ldr r6, =gUnknown_0203A12C
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	mov r8, r0
	ldr r4, =gStringVar1
	adds r0, r5, 0
	bl sub_8120F08
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0xA
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	mov r0, r8
	bl sub_8120ECC
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r4, =gStringVar3
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8120F7C
	ldr r0, [r6]
	adds r0, 0x34
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
	mov r0, r8
	bl sub_8120EC0
	bl ShowFieldMessage
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121178

	thumb_func_start sub_81211EC
sub_81211EC: @ 81211EC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =gText_Exit
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	movs r4, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08121230
_08121208:
	bl sub_8120EB4
	adds r1, r0, 0
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	cmp r0, r5
	ble _0812121C
	adds r5, r0, 0
_0812121C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08121230
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121208
_08121230:
	adds r0, r5, 0
	bl convert_pixel_width_to_tile_width
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8120ED8
	adds r3, r0, 0
	lsls r3, 25
	movs r0, 0x80
	lsls r0, 18
	adds r3, r0
	lsrs r3, 24
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	bl CreateWindowFromRect
	ldr r1, =gUnknown_0203A130
	strb r0, [r1]
	ldrb r0, [r1]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	movs r4, 0
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _081212AA
	movs r5, 0x80
	lsls r5, 17
_08121272:
	bl sub_8120EB4
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A130
	ldrb r0, [r0]
	lsrs r1, r5, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	movs r0, 0x80
	lsls r0, 21
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x3
	bgt _081212AA
	ldr r0, =gUnknown_0203A12C
	ldr r0, [r0]
	adds r0, 0x4
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08121272
_081212AA:
	ldr r5, =gUnknown_0203A130
	ldrb r0, [r5]
	ldr r2, =gText_Exit
	lsls r1, r4, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	ldrb r4, [r5]
	bl sub_8120ED8
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81211EC

	thumb_func_start sub_81212FC
sub_81212FC: @ 81212FC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _08121320
	cmp r5, 0x1
	beq _0812132C
	b _08121376
	.pool
_08121320:
	bl sub_81211EC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08121376
_0812132C:
	bl ProcessMenuInput
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _08121376
	adds r0, 0x1
	cmp r4, r0
	beq _0812134E
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0812135C
_0812134E:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	b _08121364
	.pool
_0812135C:
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	ldr r0, =gUnknown_03001178
	strb r4, [r0]
_08121364:
	ldr r0, =gUnknown_0203A130
	ldrb r0, [r0]
	bl sub_80E2A78
	adds r0, r6, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_08121376:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81212FC

	thumb_func_start sub_8121388
sub_8121388: @ 8121388
	push {lr}
	ldr r0, =sub_81212FC
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8121388

	thumb_func_start sub_812139C
sub_812139C: @ 812139C
	push {lr}
	ldr r0, =gUnknown_03001178
	ldrb r0, [r0]
	bl sub_8121178
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812139C

	thumb_func_start sub_81213B0
sub_81213B0: @ 81213B0
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	bl sub_8120ED8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81213B0

	thumb_func_start sub_81213D8
sub_81213D8: @ 81213D8
	push {r4,r5,lr}
	ldr r2, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r3, =0x00002e28
	adds r0, r1, r3
	str r0, [r2]
	ldr r5, =gUnknown_03001178
	ldrb r0, [r5]
	ldr r2, =0x00002e2c
	adds r1, r2
	adds r1, r0
	ldrb r4, [r1]
	bl sub_8120F4C
	cmp r0, 0x1
	beq _08121414
	movs r0, 0
	b _0812141E
	.pool
_08121414:
	ldrb r0, [r5]
	adds r1, r4, 0
	bl sub_8120FDC
	movs r0, 0x1
_0812141E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81213D8

	thumb_func_start sub_8121424
sub_8121424: @ 8121424
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08121448
	movs r0, 0x1
	b _0812144A
	.pool
_08121448:
	movs r0, 0
_0812144A:
	pop {r1}
	bx r1
	thumb_func_end sub_8121424

	thumb_func_start sub_8121450
sub_8121450: @ 8121450
	push {lr}
	ldr r1, =gUnknown_0203A12C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00002e28
	adds r0, r2
	str r0, [r1]
	bl sub_81210B8
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8121450

	.align 2, 0 @ Don't pad with nop.
