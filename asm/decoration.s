	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
