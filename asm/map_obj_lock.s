	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start walkrun_is_standing_still
walkrun_is_standing_still: @ 8098388
	push {lr}
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x3]
	cmp r0, 0x1
	beq _0809839C
	movs r0, 0x1
	b _0809839E
	.pool
_0809839C:
	movs r0, 0
_0809839E:
	pop {r1}
	bx r1
	thumb_func_end walkrun_is_standing_still

	thumb_func_start sub_80983A4
sub_80983A4: @ 80983A4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl walkrun_is_standing_still
	lsls r0, 24
	cmp r0, 0
	beq _080983BE
	bl sub_808B864
	adds r0, r4, 0
	bl DestroyTask
_080983BE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80983A4

	thumb_func_start sub_80983C4
sub_80983C4: @ 80983C4
	push {lr}
	ldr r0, =sub_80983A4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080983E0
	bl sub_808BCF4
	movs r0, 0x1
	b _080983E2
	.pool
_080983E0:
	movs r0, 0
_080983E2:
	pop {r1}
	bx r1
	thumb_func_end sub_80983C4

	thumb_func_start sub_80983E8
sub_80983E8: @ 80983E8
	push {lr}
	bl player_bitmagic
	ldr r0, =sub_80983A4
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80983E8

	thumb_func_start sub_8098400
sub_8098400: @ 8098400
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0809842A
	bl walkrun_is_standing_still
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0809842A
	bl sub_808B864
	strh r4, [r5, 0x8]
_0809842A:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08098452
	ldr r2, =gMapObjects
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _08098452
	adds r0, r1, 0
	bl sub_8097404
	movs r0, 0x1
	strh r0, [r5, 0xA]
_08098452:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08098468
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08098468
	adds r0, r6, 0
	bl DestroyTask
_08098468:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098400

	thumb_func_start sub_809847C
sub_809847C: @ 809847C
	push {lr}
	ldr r0, =sub_8098400
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _08098498
	bl sub_808BCF4
	movs r0, 0x1
	b _0809849A
	.pool
_08098498:
	movs r0, 0
_0809849A:
	pop {r1}
	bx r1
	thumb_func_end sub_809847C

	thumb_func_start sub_80984A0
sub_80984A0: @ 80984A0
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005DF0
	ldrb r0, [r4]
	bl sub_80974D0
	ldr r0, =sub_8098400
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gMapObjects
	ldrb r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _080984DE
	adds r0, r1, 0
	bl sub_8097404
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0xA]
_080984DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80984A0

	thumb_func_start sub_80984F4
sub_80984F4: @ 80984F4
	push {lr}
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	bl sub_80D338C
	bl sub_809757C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80984F4

	thumb_func_start sub_8098524
sub_8098524: @ 8098524
	push {r4,lr}
	ldr r4, =gMapObjects
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _08098542
	adds r0, r1, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
_08098542:
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FieldObjectClearAnimIfSpecialAnimFinished
	bl sub_80D338C
	bl sub_809757C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098524

	thumb_func_start sub_8098574
sub_8098574: @ 8098574
	push {lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldr r1, =gScriptFacing
	ldrb r1, [r1]
	bl FieldObjectFaceOppositeDirection
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098574

	thumb_func_start sub_809859C
sub_809859C: @ 809859C
	push {lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimActive
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809859C

	thumb_func_start sub_80985BC
sub_80985BC: @ 80985BC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldrb r7, [r5, 0xC]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080985E8
	bl walkrun_is_standing_still
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _080985E8
	bl sub_808B864
	strh r4, [r5, 0x8]
_080985E8:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0809860C
	ldr r0, =gMapObjects
	lsls r1, r7, 3
	adds r1, r7
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _0809860C
	adds r0, r1, 0
	bl sub_8097404
	movs r0, 0x1
	strh r0, [r5, 0xA]
_0809860C:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08098622
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08098622
	adds r0, r6, 0
	bl DestroyTask
_08098622:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80985BC

	thumb_func_start sub_8098630
sub_8098630: @ 8098630
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	bl sub_80B47E0
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030060A8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080986E0
	movs r0, 0x1
	bl sub_80B47E0
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8098074
	ldr r7, =sub_80985BC
	adds r0, r7, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	mov r9, r0
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	mov r1, r9
	adds r6, r0, r1
	strh r4, [r6, 0xC]
	ldr r2, =gMapObjects
	mov r8, r2
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _0809869A
	adds r0, r1, 0
	bl sub_8097404
	movs r0, 0x1
	strh r0, [r6, 0xA]
_0809869A:
	adds r0, r7, 0
	movs r1, 0x51
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	mov r1, r9
	adds r4, r0, r1
	strh r5, [r4, 0xC]
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	mov r2, r8
	adds r1, r0, r2
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _0809871A
	adds r0, r1, 0
	bl sub_8097404
	movs r0, 0x1
	strh r0, [r4, 0xA]
	b _0809871A
	.pool
_080986E0:
	adds r0, r4, 0
	bl sub_80974D0
	ldr r0, =sub_80985BC
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r5, r0, r1
	strh r4, [r5, 0xC]
	ldr r1, =gMapObjects
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _0809871A
	adds r0, r1, 0
	bl sub_8097404
	movs r0, 0x1
	strh r0, [r5, 0xA]
_0809871A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098630

	thumb_func_start sub_8098734
sub_8098734: @ 8098734
	push {lr}
	ldr r0, =sub_80985BC
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _08098750
	bl sub_808BCF4
	movs r0, 0x1
	b _08098752
	.pool
_08098750:
	movs r0, 0
_08098752:
	pop {r1}
	bx r1
	thumb_func_end sub_8098734

	.align 2, 0 @ Don't pad with nop.
