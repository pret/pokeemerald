	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_812A0E8
sub_812A0E8: @ 812A0E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_0203AAC4
	movs r0, 0
	strb r0, [r4]
	adds r0, r6, 0
	bl sub_8129FC8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0812A18C
	movs r5, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcs _0812A15A
	adds r7, r4, 0
_0812A10E:
	ldr r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	cmp r1, 0
	beq _0812A14C
	ldr r4, =gUnknown_0203AA44
	adds r0, r1, 0
	adds r1, r4, 0
	bl sub_8129D8C
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8129E74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A14C
	strb r5, [r4]
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _0812A15A
	.pool
_0812A14C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcc _0812A10E
_0812A15A:
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812A18C
	ldr r0, =gUnknown_0203A17C
	ldr r2, =gUnknown_0203AA44
	ldrb r1, [r2]
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldrb r1, [r0]
	lsrs r0, r1, 4
	movs r3, 0xF
	ands r3, r1
	ldrb r1, [r2, 0x2]
	subs r1, r3, r1
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r2, 0x1]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	bl sub_812A040
_0812A18C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A0E8

	thumb_func_start sub_812A1A0
sub_812A1A0: @ 812A1A0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7348
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1A0

	thumb_func_start sub_812A1C0
sub_812A1C0: @ 812A1C0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_81298EC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1C0

	thumb_func_start sub_812A1F0
sub_812A1F0: @ 812A1F0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7350
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1F0

	thumb_func_start sub_812A210
sub_812A210: @ 812A210
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_812A22C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812A210

	thumb_func_start sub_812A22C
sub_812A22C: @ 812A22C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_812A25C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A22C

	thumb_func_start sub_812A25C
sub_812A25C: @ 812A25C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0812A280
	cmp r0, 0x1
	beq _0812A29C
	b _0812A2B2
	.pool
_0812A280:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812A2B2
	adds r0, r4, 0
	bl sub_8127B04
	movs r0, 0x1
	strh r0, [r5, 0xC]
	b _0812A2B2
	.pool
_0812A29C:
	bl sub_812A3C8
	ldr r0, =gFieldCallback
	ldr r1, =sub_812A334
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_0812A2B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A25C

	thumb_func_start sub_812A2C4
sub_812A2C4: @ 812A2C4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0812A2FC
	cmp r0, 0x1
	bgt _0812A2EC
	cmp r0, 0
	beq _0812A2F6
	b _0812A32A
	.pool
_0812A2EC:
	cmp r0, 0x2
	beq _0812A308
	cmp r0, 0x3
	beq _0812A314
	b _0812A32A
_0812A2F6:
	bl sub_80E9578
	b _0812A30C
_0812A2FC:
	ldr r0, =gUnknown_08275D0C
	bl ScriptContext1_SetupScript
	b _0812A30C
	.pool
_0812A308:
	bl ScriptContext2_Enable
_0812A30C:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _0812A32A
_0812A314:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A32A
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_8126B80
	str r1, [r0]
_0812A32A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A2C4

	thumb_func_start sub_812A334
sub_812A334: @ 812A334
	push {lr}
	bl pal_fill_black
	movs r0, 0
	movs r1, 0x1
	bl sub_81973C4
	bl sub_8126ABC
	ldr r0, =sub_812A2C4
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xC]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A334

	thumb_func_start sub_812A36C
sub_812A36C: @ 812A36C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r2, 0x2E]
	cmp r0, 0xF
	ble _0812A38C
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0812A398
_0812A38C:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812A398:
	pop {r0}
	bx r0
	thumb_func_end sub_812A36C

	thumb_func_start sub_812A39C
sub_812A39C: @ 812A39C
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0812A3B8
	ldr r0, =gUnknown_085A73D8
	bl LoadSpritePalette
	b _0812A3BE
	.pool
_0812A3B8:
	ldr r0, =gUnknown_085A73E0
	bl LoadSpritePalette
_0812A3BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A39C

	thumb_func_start sub_812A3C8
sub_812A3C8: @ 812A3C8
	push {lr}
	movs r0, 0x8
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_812A3C8

	thumb_func_start sub_812A3D4
sub_812A3D4: @ 812A3D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81279C4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A430
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_0203A172
	ldrb r2, [r1]
	ldr r1, =gUnknown_0203A14C
	ldr r1, [r1]
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_DecorationWillBeDiscarded
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A458
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _0812A444
	.pool
_0812A430:
	ldr r4, =gStringVar4
	ldr r1, =gText_CantThrowAwayInUse
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_0812A444:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A3D4

	thumb_func_start sub_812A458
sub_812A458: @ 812A458
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A741C
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A458

	thumb_func_start sub_812A478
sub_812A478: @ 812A478
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r5, =gUnknown_0203A173
	ldrb r0, [r5]
	bl CountDecorationCategoryN
	ldr r1, =gUnknown_0203A151
	strb r0, [r1]
	ldrb r0, [r5]
	bl CondenseDecorationCategoryN
	adds r0, r4, 0
	bl sub_8127814
	ldr r5, =gStringVar4
	ldr r1, =gText_DecorationThrownAway
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A478

	.align 2, 0 @ Don't pad with nop.
