	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818DF00
sub_818DF00: @ 818DF00
	push {r4-r7,lr}
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0xF
	ands r4, r0
	movs r3, 0
	ldr r5, =gUnknown_0203CD68
	ldr r1, =gUnknown_0860B1A4
	lsls r0, r4, 2
	adds r6, r0, r1
	adds r7, r5, 0
_0818DF1A:
	ldr r2, [r5]
	lsls r1, r3, 1
	adds r2, 0x2
	adds r2, r1
	ldr r0, [r6]
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x8
	bls _0818DF1A
	ldr r2, [r7]
	ldr r0, =gUnknown_0860B1E4
	lsls r1, r4, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2, 0x14]
	ldr r0, =gUnknown_0860B204
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2, 0x28]
	adds r2, 0x2B
	strb r4, [r2]
	ldr r1, [r7]
	movs r0, 0xFF
	strb r0, [r1, 0x18]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818DF00

	thumb_func_start SetLilycoveQuizLady
SetLilycoveQuizLady: @ 818DF68
	push {r4-r6,lr}
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r2]
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x1]
	movs r3, 0
	adds r4, r2, 0
	ldr r6, =gGameLanguage
	adds r5, r4, 0
	ldr r0, =0x0000ffff
	adds r2, r0, 0
_0818DF8A:
	ldr r1, [r5]
	lsls r0, r3, 1
	adds r1, 0x2
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x8
	bls _0818DF8A
	ldr r0, [r4]
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x14]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x16]
	movs r3, 0
	adds r5, r4, 0
	movs r2, 0
_0818DFB4:
	ldr r0, [r5]
	lsls r1, r3, 1
	adds r0, 0x20
	adds r0, r1
	strh r2, [r0]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0818DFB4
	ldr r0, [r4]
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x28]
	adds r0, 0x2A
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x2C
	movs r1, 0x10
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r6]
	adds r0, 0x2D
	strb r1, [r0]
	bl sub_818DF00
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetLilycoveQuizLady

	thumb_func_start sub_818E004
sub_818E004: @ 818E004
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r2]
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	adds r0, 0x2A
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x16]
	bx lr
	.pool
	thumb_func_end sub_818E004

	thumb_func_start sub_818E038
sub_818E038: @ 818E038
	push {lr}
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x2
	bne _0818E05C
	movs r0, 0x2
	b _0818E066
	.pool
_0818E05C:
	cmp r0, 0x1
	beq _0818E064
	movs r0, 0
	b _0818E066
_0818E064:
	movs r0, 0x1
_0818E066:
	pop {r1}
	bx r1
	thumb_func_end sub_818E038

	thumb_func_start sub_818E06C
sub_818E06C: @ 818E06C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00003b58
	adds r7, r4, r0
	ldrh r0, [r7, 0x14]
	bl sub_811F8D8
	cmp r0, 0
	bne _0818E0EC
	ldr r1, =0x00003b83
	adds r0, r4, r1
	ldrb r5, [r0]
	ldr r0, =0x00003b5a
	adds r0, r4
	mov r8, r0
	adds r1, r4
	mov r10, r1
	ldr r6, =gUnknown_0860B1E4
_0818E09A:
	adds r5, 0x1
	cmp r5, 0xF
	ble _0818E0A2
	movs r5, 0
_0818E0A2:
	lsls r4, r5, 1
	adds r0, r4, r6
	ldrh r0, [r0]
	bl sub_811F8D8
	cmp r0, 0
	beq _0818E09A
	movs r3, 0
	ldr r0, =gUnknown_0860B1E4
	mov r12, r0
	lsls r1, r5, 2
	ldr r0, =gUnknown_0860B204
	mov r9, r0
	ldr r0, =gUnknown_0860B1A4
	adds r6, r1, r0
	mov r2, r8
_0818E0C2:
	lsls r0, r3, 1
	ldr r1, [r6]
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x8
	ble _0818E0C2
	mov r1, r12
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7, 0x14]
	mov r1, r9
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7, 0x28]
	mov r0, r10
	strb r5, [r0]
	movs r0, 0xFF
	strb r0, [r7, 0x18]
_0818E0EC:
	bl sub_818E13C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0818E118
	movs r0, 0x2
	b _0818E12C
	.pool
_0818E118:
	cmp r0, 0x2
	beq _0818E126
	bl sub_818E1F4
	lsls r0, 24
	cmp r0, 0
	beq _0818E12A
_0818E126:
	movs r0, 0x1
	b _0818E12C
_0818E12A:
	movs r0, 0
_0818E12C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818E06C

	thumb_func_start sub_818E13C
sub_818E13C: @ 818E13C
	push {r4-r7,lr}
	movs r7, 0x1
	ldr r5, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x00003b58
	adds r0, r1, r2
	str r0, [r5]
	ldrb r0, [r0, 0x18]
	cmp r0, 0xFF
	bne _0818E174
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EEB7E
	bl StringCopy7
	movs r7, 0
	b _0818E1DC
	.pool
_0818E174:
	ldr r4, =gStringVar1
	ldr r0, =0x00003b70
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy7
	ldr r0, [r5]
	adds r0, 0x2D
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
	ldr r0, [r5]
	adds r0, 0x18
	bl sub_818E258
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	bl sub_818E258
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0818E1DC
	ldr r0, [r5]
	movs r2, 0
	cmp r2, r4
	bcs _0818E1DC
	ldr r1, [r6]
	ldrb r0, [r0, 0x18]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0818E1DA
_0818E1BA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r4
	bcs _0818E1DC
	ldr r0, =gUnknown_0203CD68
	ldr r1, [r0]
	adds r1, 0x18
	adds r1, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0818E1BA
_0818E1DA:
	movs r7, 0x2
_0818E1DC:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E13C

	thumb_func_start sub_818E1F4
sub_818E1F4: @ 818E1F4
	push {r4-r6,lr}
	ldr r3, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x00003b58
	adds r0, r1, r2
	str r0, [r3]
	movs r5, 0
	movs r4, 0
	ldr r0, =0x00003b78
	adds r1, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrh r1, [r1]
	adds r6, r3, 0
	adds r3, r0, 0
	ldrb r2, [r2, 0xA]
	cmp r1, r2
	bne _0818E23A
_0818E21A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bhi _0818E23C
	ldr r1, [r6]
	lsls r0, r4, 1
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r3]
	adds r0, 0xA
	adds r0, r4
	ldrh r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0818E21A
_0818E23A:
	movs r5, 0x1
_0818E23C:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E1F4

	thumb_func_start sub_818E258
sub_818E258: @ 818E258
	push {lr}
	movs r2, 0
	adds r1, r0, 0
	b _0818E268
_0818E260:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, 0x1
_0818E268:
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0818E260
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_818E258

	thumb_func_start sub_818E274
sub_818E274: @ 818E274
	push {r4,lr}
	ldr r4, =gStringVar1
	ldr r0, =gUnknown_0203CD68
	ldr r0, [r0]
	ldrh r0, [r0, 0x28]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E274

	thumb_func_start sub_818E298
sub_818E298: @ 818E298
	push {r4,lr}
	ldr r4, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r4]
	bl sub_818E13C
	lsls r0, 24
	cmp r0, 0
	beq _0818E2C0
	movs r0, 0
	b _0818E2CC
	.pool
_0818E2C0:
	ldr r0, [r4]
	ldr r1, =gGameLanguage
	ldrb r1, [r1]
	adds r0, 0x2D
	strb r1, [r0]
	movs r0, 0x1
_0818E2CC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E298

	thumb_func_start sub_818E2D8
sub_818E2D8: @ 818E2D8
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003b58
	adds r1, r0, r3
	str r1, [r2]
	ldr r1, =0x00003b82
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_818E2D8

	thumb_func_start sub_818E2FC
sub_818E2FC: @ 818E2FC
	push {lr}
	bl easy_chat_input_maybe
	pop {r0}
	bx r0
	thumb_func_end sub_818E2FC

	thumb_func_start sub_818E308
sub_818E308: @ 818E308
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r5]
	ldr r6, =gStringVar1
	ldrh r1, [r0, 0x14]
	adds r0, r6, 0
	bl CopyEasyChatWord
	ldr r4, =gStringVar2
	ldr r0, [r5]
	ldrh r1, [r0, 0x16]
	adds r0, r4, 0
	bl CopyEasyChatWord
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringCompare
	movs r1, 0
	cmp r0, 0
	bne _0818E33C
	movs r1, 0x1
_0818E33C:
	adds r0, r1, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E308

	thumb_func_start sub_818E358
sub_818E358: @ 818E358
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	ldrh r0, [r0, 0x28]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_818E358

	thumb_func_start sub_818E37C
sub_818E37C: @ 818E37C
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_818E37C

	thumb_func_start sub_818E39C
sub_818E39C: @ 818E39C
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	movs r1, 0x2
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_818E39C

	thumb_func_start sub_818E3BC
sub_818E3BC: @ 818E3BC
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x16]
	bx lr
	.pool
	thumb_func_end sub_818E3BC

	thumb_func_start sub_818E3E0
sub_818E3E0: @ 818E3E0
	push {lr}
	bl sub_81AAC70
	pop {r0}
	bx r0
	thumb_func_end sub_818E3E0

	thumb_func_start sub_818E3EC
sub_818E3EC: @ 818E3EC
	push {r4,lr}
	ldr r4, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r4]
	bl sub_818E298
	lsls r0, 24
	cmp r0, 0
	beq _0818E41C
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x2B
	ldrb r1, [r1]
	adds r0, 0x2C
	b _0818E422
	.pool
_0818E41C:
	ldr r0, [r4]
	adds r0, 0x2C
	movs r1, 0x10
_0818E422:
	strb r1, [r0]
	bl sub_818DF00
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_818E3EC

	thumb_func_start sub_818E430
sub_818E430: @ 818E430
	push {r4,r5,lr}
	ldr r1, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	movs r2, 0
	adds r5, r1, 0
	adds r4, r5, 0
	ldr r0, =0x0000ffff
	adds r3, r0, 0
_0818E448:
	ldr r1, [r4]
	lsls r0, r2, 1
	adds r1, 0x2
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x8
	bls _0818E448
	ldr r1, [r5]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x14]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E430

	thumb_func_start sub_818E47C
sub_818E47C: @ 818E47C
	push {lr}
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x11
	strh r0, [r1]
	bl easy_chat_input_maybe
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E47C

	thumb_func_start sub_818E490
sub_818E490: @ 818E490
	push {lr}
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E490

	thumb_func_start sub_818E4A4
sub_818E4A4: @ 818E4A4
	push {r4-r6,lr}
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r2]
	ldr r1, =gScriptItemId
	ldrh r1, [r1]
	strh r1, [r0, 0x28]
	movs r3, 0
	adds r4, r2, 0
	ldr r6, =gSaveBlock2Ptr
	adds r5, r4, 0
	adds r2, r6, 0
_0818E4C2:
	ldr r1, [r5]
	lsls r0, r3, 1
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r2]
	adds r0, 0xA
	adds r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _0818E4C2
	ldr r0, [r4]
	adds r0, 0x18
	ldr r1, [r6]
	bl StringCopy7
	ldr r0, [r4]
	ldr r1, =gGameLanguage
	ldrb r1, [r1]
	adds r0, 0x2D
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E4A4

	thumb_func_start sub_818E510
sub_818E510: @ 818E510
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003b58
	adds r1, r0, r3
	str r1, [r2]
	ldr r1, =0x00003b82
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_818E510

	thumb_func_start sub_818E538
sub_818E538: @ 818E538
	push {lr}
	ldr r2, =gUnknown_0203CD68
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003b58
	adds r1, r0
	str r1, [r2]
	ldr r0, =gStringVar3
	ldrh r1, [r1, 0x14]
	bl CopyEasyChatWord
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E538

	thumb_func_start sub_818E564
sub_818E564: @ 818E564
	push {lr}
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	thumb_func_end sub_818E564

	thumb_func_start sub_818E570
sub_818E570: @ 818E570
	push {r4-r7,lr}
	ldr r2, =gUnknown_0203CD68
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r4, =0x00003b58
	adds r3, r1, r4
	str r3, [r2]
	adds r6, r0, 0
	adds r6, 0x2C
	ldrb r4, [r6]
	adds r7, r2, 0
	cmp r4, 0xF
	bhi _0818E5EC
	ldrb r0, [r3]
	cmp r0, 0
	bne _0818E5EC
	movs r5, 0
	ldr r2, =0x00003b83
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r4, r0
	bne _0818E5E4
	adds r4, r7, 0
_0818E59E:
	bl Random
	ldr r2, [r4]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	adds r2, 0x2B
	strb r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bhi _0818E5C6
	ldr r0, [r4]
	adds r0, 0x2B
	ldrb r1, [r6]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0818E59E
_0818E5C6:
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x2B
	ldrb r0, [r6]
	ldr r7, =gUnknown_0203CD68
	ldrb r4, [r2]
	cmp r0, r4
	bne _0818E5E4
	ldrb r1, [r2]
	adds r3, r1, 0x1
	adds r0, r3, 0
	asrs r0, 4
	lsls r0, 4
	subs r0, r3, r0
	strb r0, [r2]
_0818E5E4:
	ldr r0, [r7]
	ldrb r1, [r6]
	adds r0, 0x2C
	strb r1, [r0]
_0818E5EC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E570

	thumb_func_start sub_818E604
sub_818E604: @ 818E604
	push {r4,lr}
	ldr r4, =gUnknown_0203CD6C
	ldr r1, [r4]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x2]
	ldr r0, [r4]
	strb r1, [r0, 0x3]
	ldr r0, [r4]
	strb r1, [r0, 0xC]
	bl Random
	ldr r4, [r4]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	strb r0, [r4, 0xD]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E604

	thumb_func_start SetLilycoveContestLady
SetLilycoveContestLady: @ 818E638
	push {r4,lr}
	ldr r4, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r4]
	movs r2, 0
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	strb r2, [r0, 0x1]
	bl sub_818E604
	ldr r1, [r4]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r1, 0xE]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetLilycoveContestLady

	thumb_func_start sub_818E674
sub_818E674: @ 818E674
	push {lr}
	ldr r2, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r2]
	movs r3, 0
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	ldr r2, [r2]
	ldrb r0, [r2, 0x2]
	cmp r0, 0x5
	beq _0818E69A
	ldrb r0, [r2, 0x3]
	cmp r0, 0x5
	bne _0818E69E
_0818E69A:
	bl sub_818E604
_0818E69E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E674

	thumb_func_start sub_818E6B0
sub_818E6B0: @ 818E6B0
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r4, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003b58
	adds r1, r0, r3
	str r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, r2
	bhi _0818E6EA
	strb r2, [r1, 0xC]
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0xFF
	movs r2, 0x8
	bl memset
	ldr r1, [r4]
	ldr r0, =gSaveBlock2Ptr
	adds r1, 0x4
	ldr r0, [r0]
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	ldr r1, [r4]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r1, 0xE]
_0818E6EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E6B0

	thumb_func_start sub_818E704
sub_818E704: @ 818E704
	push {r4,r5,lr}
	adds r2, r0, 0
	movs r3, 0
	movs r4, 0
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r5, =0x00003b58
	adds r0, r5
	str r0, [r1]
	ldrb r0, [r0, 0xD]
	adds r5, r1, 0
	cmp r0, 0x4
	bhi _0818E76A
	lsls r0, 2
	ldr r1, =_0818E73C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0818E73C:
	.4byte _0818E750
	.4byte _0818E754
	.4byte _0818E758
	.4byte _0818E75C
	.4byte _0818E760
_0818E750:
	ldrb r0, [r2, 0x1]
	b _0818E762
_0818E754:
	ldrb r0, [r2, 0x2]
	b _0818E762
_0818E758:
	ldrb r0, [r2, 0x3]
	b _0818E762
_0818E75C:
	ldrb r0, [r2, 0x4]
	b _0818E762
_0818E760:
	ldrb r0, [r2, 0x5]
_0818E762:
	cmp r0, 0
	beq _0818E76A
	adds r3, r0, 0
	movs r4, 0x1
_0818E76A:
	cmp r4, 0x1
	bne _0818E784
	adds r0, r3, 0
	bl sub_818E6B0
	ldr r0, =gUnknown_0203CD6C
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	b _0818E78C
	.pool
_0818E784:
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
_0818E78C:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818E704

	thumb_func_start sub_818E794
sub_818E794: @ 818E794
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003b58
	adds r1, r2
	str r1, [r4]
	ldr r2, =gUnknown_0860B324
	ldrb r1, [r1, 0xD]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r1, =gUnknown_0860B310
	ldr r0, [r4]
	ldrb r0, [r0, 0xD]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E794

	thumb_func_start sub_818E7E0
sub_818E7E0: @ 818E7E0
	push {r4,lr}
	adds r3, r1, 0
	ldr r2, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r4, =0x00003b58
	adds r1, r4
	str r1, [r2]
	ldrb r2, [r1, 0xD]
	strb r2, [r0]
	ldr r2, =gUnknown_0860B310
	ldrb r0, [r1, 0xD]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	adds r0, r3, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E7E0

	thumb_func_start sub_818E81C
sub_818E81C: @ 818E81C
	push {r4,lr}
	ldr r3, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r4, =0x00003b58
	adds r2, r1, r4
	str r2, [r3]
	ldr r2, =0x00003b5c
	adds r1, r2
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E81C

	thumb_func_start sub_818E848
sub_818E848: @ 818E848
	ldr r2, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r3, =0x00003b58
	adds r1, r3
	str r1, [r2]
	ldrb r1, [r1, 0xE]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_818E848

	thumb_func_start sub_818E868
sub_818E868: @ 818E868
	push {lr}
	lsls r1, 24
	ldr r2, =gUnknown_0860B338
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E868

	thumb_func_start sub_818E880
sub_818E880: @ 818E880
	push {lr}
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bls _0818E8A4
	movs r0, 0x1
	b _0818E8AE
	.pool
_0818E8A4:
	cmp r0, 0
	beq _0818E8AC
	movs r0, 0
	b _0818E8AE
_0818E8AC:
	movs r0, 0x2
_0818E8AE:
	pop {r1}
	bx r1
	thumb_func_end sub_818E880

	thumb_func_start sub_818E8B4
sub_818E8B4: @ 818E8B4
	push {lr}
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _0818E8D8
	movs r0, 0
	b _0818E8DA
	.pool
_0818E8D8:
	movs r0, 0x1
_0818E8DA:
	pop {r1}
	bx r1
	thumb_func_end sub_818E8B4

	thumb_func_start sub_818E8E0
sub_818E8E0: @ 818E8E0
	push {r4,lr}
	movs r3, 0
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r4, =0x00003b58
	adds r2, r0, r4
	str r2, [r1]
	ldrb r0, [r2, 0x2]
	cmp r0, 0x4
	bhi _0818E8FC
	ldrb r0, [r2, 0x3]
	cmp r0, 0x4
	bls _0818E8FE
_0818E8FC:
	movs r3, 0x1
_0818E8FE:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E8E0

	thumb_func_start sub_818E914
sub_818E914: @ 818E914
	push {lr}
	ldr r0, =gStringVar2
	ldr r1, =gStringVar1
	bl sub_818E794
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E914

	thumb_func_start sub_818E92C
sub_818E92C: @ 818E92C
	push {lr}
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0x3
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E92C

	thumb_func_start sub_818E940
sub_818E940: @ 818E940
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_818E940

	thumb_func_start sub_818E960
sub_818E960: @ 818E960
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldr r2, =gSpecialVar_0x8005
	ldr r1, =gUnknown_0860B34C
	ldrb r0, [r0, 0xD]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_818E960

	thumb_func_start sub_818E990
sub_818E990: @ 818E990
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0xD]
	bx lr
	.pool
	thumb_func_end sub_818E990


.align 2, 0 @ Don't pad with nop.
