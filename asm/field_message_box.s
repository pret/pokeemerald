	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8098128
sub_8098128: @ 8098128
	ldr r1, =gUnknown_020375BC
	movs r0, 0
	strb r0, [r1]
	ldr r2, =gUnknown_03003014
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	movs r1, 0x3
	negs r1, r1
	ands r0, r1
	subs r1, 0x2
	ands r0, r1
	subs r1, 0x4
	ands r0, r1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8098128

	thumb_func_start sub_8098154
sub_8098154: @ 8098154
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08098188
	cmp r0, 0x1
	bgt _0809817C
	cmp r0, 0
	beq _08098182
	b _080981B0
	.pool
_0809817C:
	cmp r0, 0x2
	beq _08098198
	b _080981B0
_08098182:
	bl sub_81973A4
	b _08098190
_08098188:
	movs r0, 0
	movs r1, 0x1
	bl sub_81973C4
_08098190:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080981B0
_08098198:
	bl sub_8197224
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	beq _080981B0
	ldr r1, =gUnknown_020375BC
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	bl DestroyTask
_080981B0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098154

	thumb_func_start task_add_textbox
task_add_textbox: @ 80981BC
	push {lr}
	ldr r0, =sub_8098154
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_textbox

	thumb_func_start task_del_textbox
task_del_textbox: @ 80981D0
	push {lr}
	ldr r0, =sub_8098154
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080981E4
	bl DestroyTask
_080981E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_del_textbox

	thumb_func_start box_related_two__2
box_related_two__2: @ 80981EC
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gUnknown_020375BC
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809820C
	adds r0, r1, 0
	movs r1, 0x1
	bl textbox_fdecode_auto_and_task_add
	movs r0, 0x2
	strb r0, [r4]
	movs r0, 0x1
	b _0809820E
	.pool
_0809820C:
	movs r0, 0
_0809820E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end box_related_two__2

	thumb_func_start sub_8098214
sub_8098214: @ 8098214
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8196094
	adds r1, r0, 0
	cmp r1, 0
	bne _0809822E
	ldr r0, =gUnknown_020375BC
	strb r1, [r0]
	adds r0, r4, 0
	bl DestroyTask
_0809822E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098214

	thumb_func_start sub_8098238
sub_8098238: @ 8098238
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_020375BC
	ldrb r0, [r5]
	cmp r0, 0
	bne _08098270
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl StringExpandPlaceholders
	ldr r0, =sub_8098214
	movs r1, 0
	bl CreateTask
	adds r0, r4, 0
	bl sub_8196080
	movs r0, 0x2
	strb r0, [r5]
	movs r0, 0x1
	b _08098272
	.pool
_08098270:
	movs r0, 0
_08098272:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8098238

	thumb_func_start box_related_two__3
box_related_two__3: @ 8098278
	push {lr}
	adds r1, r0, 0
	ldr r2, =gUnknown_020375BC
	ldrb r0, [r2]
	cmp r0, 0
	bne _08098298
	movs r0, 0x3
	strb r0, [r2]
	adds r0, r1, 0
	movs r1, 0
	bl textbox_fdecode_auto_and_task_add
	movs r0, 0x1
	b _0809829A
	.pool
_08098298:
	movs r0, 0
_0809829A:
	pop {r1}
	bx r1
	thumb_func_end box_related_two__3

	thumb_func_start sub_80982A0
sub_80982A0: @ 80982A0
	push {lr}
	ldr r2, =gUnknown_020375BC
	movs r1, 0x3
	strb r1, [r2]
	movs r1, 0x1
	bl textbox_fdecode_auto_and_task_add
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80982A0

	thumb_func_start sub_80982B8
sub_80982B8: @ 80982B8
	push {lr}
	ldr r1, =gUnknown_020375BC
	ldrb r0, [r1]
	cmp r0, 0
	bne _080982D4
	movs r0, 0x2
	strb r0, [r1]
	bl textbox_auto_and_task_add
	movs r0, 0x1
	b _080982D6
	.pool
_080982D4:
	movs r0, 0
_080982D6:
	pop {r1}
	bx r1
	thumb_func_end sub_80982B8

	thumb_func_start textbox_fdecode_auto_and_task_add
textbox_fdecode_auto_and_task_add: @ 80982DC
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r0, =gStringVar4
	adds r1, r2, 0
	bl StringExpandPlaceholders
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl AddTextPrinterForMessage
	bl task_add_textbox
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end textbox_fdecode_auto_and_task_add

	thumb_func_start textbox_auto_and_task_add
textbox_auto_and_task_add: @ 8098304
	push {lr}
	movs r0, 0x1
	bl AddTextPrinterForMessage
	bl task_add_textbox
	pop {r0}
	bx r0
	thumb_func_end textbox_auto_and_task_add

	thumb_func_start textbox_close
textbox_close: @ 8098314
	push {lr}
	bl task_del_textbox
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r1, =gUnknown_020375BC
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end textbox_close

	thumb_func_start textbox_any_visible
textbox_any_visible: @ 8098330
	ldr r0, =gUnknown_020375BC
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end textbox_any_visible

	thumb_func_start sub_809833C
sub_809833C: @ 809833C
	push {lr}
	ldr r0, =gUnknown_020375BC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098350
	movs r0, 0
	b _08098352
	.pool
_08098350:
	movs r0, 0x1
_08098352:
	pop {r1}
	bx r1
	thumb_func_end sub_809833C

	thumb_func_start sub_8098358
sub_8098358: @ 8098358
	push {lr}
	bl task_del_textbox
	movs r0, 0
	movs r1, 0x1
	bl sub_81973FC
	ldr r1, =gUnknown_020375BC
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098358

	thumb_func_start sub_8098374
sub_8098374: @ 8098374
	push {lr}
	bl task_del_textbox
	ldr r1, =gUnknown_020375BC
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098374

	.align 2, 0 @ Don't pad with nop.
