	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(6)

	thumb_func_start sub_81CB260
sub_81CB260: @ 81CB260
	push {r4,lr}
	ldr r1, =0x00002048
	movs r0, 0x6
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CB294
	movs r0, 0
	strb r0, [r4, 0x19]
	ldr r0, =sub_81CB324
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CB310
	str r0, [r4]
	movs r0, 0x1
	b _081CB296
	.pool
_081CB294:
	movs r0, 0
_081CB296:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB260

	thumb_func_start sub_81CB29C
sub_81CB29C: @ 81CB29C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_08622798
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5, 0x4]
	ldr r0, =sub_81CB310
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CB29C

	thumb_func_start sub_81CB2CC
sub_81CB2CC: @ 81CB2CC
	push {lr}
	movs r0, 0x6
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CB2CC

	thumb_func_start sub_81CB2E0
sub_81CB2E0: @ 81CB2E0
	push {r4,lr}
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_81CC2B4
	bl sub_81CBC1C
	ldrb r0, [r4, 0x12]
	bl RemoveWindow
	ldrb r0, [r4, 0x10]
	bl RemoveWindow
	ldrb r0, [r4, 0x14]
	bl RemoveWindow
	movs r0, 0x6
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB2E0

	thumb_func_start sub_81CB310
sub_81CB310: @ 81CB310
	push {lr}
	movs r0, 0x6
	bl GetSubstructPtr
	ldr r0, [r0, 0x4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81CB310

	thumb_func_start sub_81CB324
sub_81CB324: @ 81CB324
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x7
	bls _081CB338
	b _081CB504
_081CB338:
	lsls r0, r4, 2
	ldr r1, =_081CB348
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB348:
	.4byte _081CB368
	.4byte _081CB3D4
	.4byte _081CB424
	.4byte _081CB468
	.4byte _081CB482
	.4byte _081CB494
	.4byte _081CB4A6
	.4byte _081CB4EA
_081CB368:
	ldr r0, =gUnknown_0862278C
	movs r1, 0x3
	bl InitBgTemplates
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r1, =gUnknown_08622530
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =0x00001024
	adds r1, r5, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086225D4
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08622510
	movs r1, 0x20
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x2
	b _081CB418
	.pool
_081CB3D4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CB3E0
	b _081CB4FA
_081CB3E0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	adds r1, r5, 0
	adds r1, 0x24
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =gUnknown_086226E0
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x1
_081CB418:
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081CB506
	.pool
_081CB424:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081CB4FA
	adds r0, r5, 0
	bl sub_81CC034
	ldr r1, =gUnknown_08622760
	str r4, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_08622700
	movs r1, 0x30
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, =gUnknown_08622720
	movs r1, 0x50
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0
	b _081CB506
	.pool
_081CB468:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CB4FA
	bl sub_81CAE28
	cmp r0, 0
	beq _081CB4FA
	bl sub_81CBBB8
	movs r0, 0
	b _081CB506
_081CB482:
	bl sub_81C8224
	cmp r0, 0
	bne _081CB4FA
	adds r0, r5, 0
	bl sub_81CBD78
	movs r0, 0
	b _081CB506
_081CB494:
	adds r0, r5, 0
	bl sub_81CBDC0
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CB506
_081CB4A6:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	bl sub_81CC214
	movs r0, 0x3
	bl LoadLeftHeaderGfxForIndex
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081CB506
_081CB4EA:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CB4FA
	bl sub_81C8010
	cmp r0, 0
	beq _081CB4FE
_081CB4FA:
	movs r0, 0x2
	b _081CB506
_081CB4FE:
	movs r0, 0x1
	bl sub_81CBC38
_081CB504:
	movs r0, 0x4
_081CB506:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB324

	thumb_func_start sub_81CB510
sub_81CB510: @ 81CB510
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB55E
	cmp r4, 0x1
	bgt _081CB52A
	cmp r4, 0
	beq _081CB534
	b _081CB580
_081CB52A:
	cmp r4, 0x2
	beq _081CB566
	cmp r4, 0x3
	beq _081CB572
	b _081CB580
_081CB534:
	bl MatchCall_MoveCursorDown
	cmp r0, 0x1
	beq _081CB54C
	cmp r0, 0x1
	bgt _081CB546
	cmp r0, 0
	beq _081CB580
	b _081CB56E
_081CB546:
	cmp r0, 0x2
	beq _081CB556
	b _081CB56E
_081CB54C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CB582
_081CB556:
	movs r0, 0x5
	bl PlaySE
	b _081CB56E
_081CB55E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB57C
_081CB566:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB56E:
	movs r0, 0
	b _081CB582
_081CB572:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB580
_081CB57C:
	movs r0, 0x2
	b _081CB582
_081CB580:
	movs r0, 0x4
_081CB582:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB510

	thumb_func_start sub_81CB588
sub_81CB588: @ 81CB588
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB5D6
	cmp r4, 0x1
	bgt _081CB5A2
	cmp r4, 0
	beq _081CB5AC
	b _081CB5F8
_081CB5A2:
	cmp r4, 0x2
	beq _081CB5DE
	cmp r4, 0x3
	beq _081CB5EA
	b _081CB5F8
_081CB5AC:
	bl MatchCall_MoveCursorUp
	cmp r0, 0x1
	beq _081CB5C4
	cmp r0, 0x1
	bgt _081CB5BE
	cmp r0, 0
	beq _081CB5F8
	b _081CB5E6
_081CB5BE:
	cmp r0, 0x2
	beq _081CB5CE
	b _081CB5E6
_081CB5C4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CB5FA
_081CB5CE:
	movs r0, 0x5
	bl PlaySE
	b _081CB5E6
_081CB5D6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB5F4
_081CB5DE:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB5E6:
	movs r0, 0
	b _081CB5FA
_081CB5EA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB5F8
_081CB5F4:
	movs r0, 0x2
	b _081CB5FA
_081CB5F8:
	movs r0, 0x4
_081CB5FA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB588

	thumb_func_start sub_81CB600
sub_81CB600: @ 81CB600
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB64E
	cmp r4, 0x1
	bgt _081CB61A
	cmp r4, 0
	beq _081CB624
	b _081CB670
_081CB61A:
	cmp r4, 0x2
	beq _081CB656
	cmp r4, 0x3
	beq _081CB662
	b _081CB670
_081CB624:
	bl MatchCall_PageDown
	cmp r0, 0x1
	beq _081CB63C
	cmp r0, 0x1
	bgt _081CB636
	cmp r0, 0
	beq _081CB670
	b _081CB65E
_081CB636:
	cmp r0, 0x2
	beq _081CB646
	b _081CB65E
_081CB63C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CB672
_081CB646:
	movs r0, 0x5
	bl PlaySE
	b _081CB65E
_081CB64E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB66C
_081CB656:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB65E:
	movs r0, 0
	b _081CB672
_081CB662:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB670
_081CB66C:
	movs r0, 0x2
	b _081CB672
_081CB670:
	movs r0, 0x4
_081CB672:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB600

	thumb_func_start sub_81CB678
sub_81CB678: @ 81CB678
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB6C6
	cmp r4, 0x1
	bgt _081CB692
	cmp r4, 0
	beq _081CB69C
	b _081CB6E8
_081CB692:
	cmp r4, 0x2
	beq _081CB6CE
	cmp r4, 0x3
	beq _081CB6DA
	b _081CB6E8
_081CB69C:
	bl MatchCall_PageUp
	cmp r0, 0x1
	beq _081CB6B4
	cmp r0, 0x1
	bgt _081CB6AE
	cmp r0, 0
	beq _081CB6E8
	b _081CB6D6
_081CB6AE:
	cmp r0, 0x2
	beq _081CB6BE
	b _081CB6D6
_081CB6B4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CB6EA
_081CB6BE:
	movs r0, 0x5
	bl PlaySE
	b _081CB6D6
_081CB6C6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CB6E4
_081CB6CE:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81CBEF8
_081CB6D6:
	movs r0, 0
	b _081CB6EA
_081CB6DA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CB6E8
_081CB6E4:
	movs r0, 0x2
	b _081CB6EA
_081CB6E8:
	movs r0, 0x4
_081CB6EA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB678

	thumb_func_start sub_81CB6F0
sub_81CB6F0: @ 81CB6F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0
	beq _081CB706
	cmp r4, 0x1
	beq _081CB71C
	b _081CB72A
_081CB706:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CBF60
	movs r0, 0x7
	bl sub_81C7BA4
	movs r0, 0
	b _081CB72C
_081CB71C:
	adds r0, r5, 0
	bl sub_81CBFC4
	cmp r0, 0
	beq _081CB72A
	movs r0, 0x2
	b _081CB72C
_081CB72A:
	movs r0, 0x4
_081CB72C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB6F0

	thumb_func_start sub_81CB734
sub_81CB734: @ 81CB734
	push {r4,lr}
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_81CB01C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_81CC344
	movs r0, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB734

	thumb_func_start sub_81CB75C
sub_81CB75C: @ 81CB75C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0
	beq _081CB772
	cmp r4, 0x1
	beq _081CB788
	b _081CB796
_081CB772:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CBFF0
	movs r0, 0x6
	bl sub_81C7BA4
	movs r0, 0
	b _081CB798
_081CB788:
	adds r0, r5, 0
	bl sub_81CC004
	cmp r0, 0
	beq _081CB796
	movs r0, 0x2
	b _081CB798
_081CB796:
	movs r0, 0x4
_081CB798:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB75C

	thumb_func_start sub_81CB7A0
sub_81CB7A0: @ 81CB7A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB7D4
	cmp r4, 0x1
	bgt _081CB7BA
	cmp r4, 0
	beq _081CB7C4
	b _081CB81A
_081CB7BA:
	cmp r4, 0x2
	beq _081CB7F8
	cmp r4, 0x3
	beq _081CB80C
	b _081CB81A
_081CB7C4:
	movs r0, 0x1
	bl ToggleMatchCallVerticalArrows
	adds r0, r5, 0
	bl sub_81CC058
	movs r0, 0
	b _081CB81C
_081CB7D4:
	adds r0, r5, 0
	bl sub_81CC0D0
	adds r4, r0, 0
	cmp r4, 0
	bne _081CB816
	adds r0, r5, 0
	bl sub_81CC0E0
	ldr r0, =0x00000107
	bl PlaySE
	strb r4, [r5, 0xE]
	movs r0, 0
	b _081CB81C
	.pool
_081CB7F8:
	adds r0, r5, 0
	bl sub_81CC104
	cmp r0, 0
	bne _081CB816
	adds r0, r5, 0
	bl sub_81CC158
	movs r0, 0
	b _081CB81C
_081CB80C:
	adds r0, r5, 0
	bl sub_81CC194
	cmp r0, 0
	beq _081CB81A
_081CB816:
	movs r0, 0x2
	b _081CB81C
_081CB81A:
	movs r0, 0x4
_081CB81C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB7A0

	thumb_func_start sub_81CB824
sub_81CB824: @ 81CB824
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB85E
	cmp r4, 0x1
	bgt _081CB83E
	cmp r4, 0
	beq _081CB844
	b _081CB880
_081CB83E:
	cmp r4, 0x2
	beq _081CB872
	b _081CB880
_081CB844:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CC09C
	movs r0, 0x1
	bl ToggleMatchCallVerticalArrows
	movs r0, 0x1
	strb r0, [r5, 0xE]
	movs r0, 0
	b _081CB882
_081CB85E:
	adds r0, r5, 0
	bl sub_81CC0D0
	cmp r0, 0
	bne _081CB87C
	adds r0, r5, 0
	bl sub_81CC11C
	movs r0, 0
	b _081CB882
_081CB872:
	adds r0, r5, 0
	bl sub_81CC140
	cmp r0, 0
	beq _081CB880
_081CB87C:
	movs r0, 0x2
	b _081CB882
_081CB880:
	movs r0, 0x4
_081CB882:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB824

	thumb_func_start sub_81CB888
sub_81CB888: @ 81CB888
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r6, 0
	cmp r5, 0x6
	bhi _081CB934
	lsls r0, r5, 2
	ldr r1, =_081CB8A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB8A8:
	.4byte _081CB8C4
	.4byte _081CB8DA
	.4byte _081CB8E2
	.4byte _081CB8F0
	.4byte _081CB8F8
	.4byte _081CB90C
	.4byte _081CB922
_081CB8C4:
	ldrb r0, [r4, 0xE]
	cmp r0, 0
	bne _081CB8D2
	movs r0, 0x84
	lsls r0, 1
	bl PlaySE
_081CB8D2:
	movs r0, 0x5
	bl PlaySE
	b _081CB934
_081CB8DA:
	adds r0, r4, 0
	bl sub_81CC1DC
	b _081CB934
_081CB8E2:
	adds r0, r4, 0
	bl sub_81CC204
	cmp r0, 0
	beq _081CB934
_081CB8EC:
	movs r6, 0x2
	b _081CB934
_081CB8F0:
	adds r0, r4, 0
	bl sub_81CBFF0
	b _081CB934
_081CB8F8:
	adds r0, r4, 0
	bl sub_81CC004
	cmp r0, 0
	beq _081CB904
	movs r6, 0x2
_081CB904:
	movs r0, 0x6
	bl sub_81C7BA4
	b _081CB934
_081CB90C:
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0
	bne _081CB8EC
	ldrb r0, [r4, 0xF]
	cmp r0, 0
	beq _081CB92C
	bl sub_81C8838
	movs r6, 0x1
	b _081CB934
_081CB922:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081CB8EC
_081CB92C:
	movs r0, 0
	bl ToggleMatchCallVerticalArrows
	movs r6, 0x4
_081CB934:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB888

	thumb_func_start sub_81CB93C
sub_81CB93C: @ 81CB93C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CB974
	cmp r4, 0x1
	bgt _081CB956
	cmp r4, 0
	beq _081CB960
	b _081CB9BE
_081CB956:
	cmp r4, 0x2
	beq _081CB990
	cmp r4, 0x3
	beq _081CB9A0
	b _081CB9BE
_081CB960:
	movs r0, 0x5
	bl PlaySE
	bl sub_81C877C
	adds r0, r5, 0
	bl sub_81CC014
	movs r0, 0
	b _081CB9C0
_081CB974:
	bl sub_81C8820
	cmp r0, 0
	bne _081CB9BA
	adds r0, r5, 0
	bl sub_81CC004
	cmp r0, 0
	bne _081CB9BA
	movs r0, 0x8
	bl sub_81C7BA4
	movs r0, 0
	b _081CB9C0
_081CB990:
	movs r0, 0
	bl sub_81C87AC
	adds r0, r5, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CB9C0
_081CB9A0:
	bl sub_81C8820
	cmp r0, 0
	bne _081CB9BA
	adds r0, r5, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CB9BA
	bl IsDma3ManagerBusyWithBgCopy_
	cmp r0, 0
	beq _081CB9BE
_081CB9BA:
	movs r0, 0x2
	b _081CB9C0
_081CB9BE:
	movs r0, 0x4
_081CB9C0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB93C

	thumb_func_start sub_81CB9C8
sub_81CB9C8: @ 81CB9C8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081CBA60
	lsls r0, r5, 2
	ldr r1, =_081CB9E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CB9E8:
	.4byte _081CB9FC
	.4byte _081CBA1C
	.4byte _081CBA34
	.4byte _081CBA40
	.4byte _081CBA4A
_081CB9FC:
	bl GetMatchCallListTopIndex
	bl sub_81CB0E4
	adds r5, r0, 0
	cmp r5, 0
	beq _081CBA60
	movs r0, 0x5
	bl PlaySE
	strh r5, [r4, 0x16]
	adds r0, r4, 0
	bl sub_81CC420
	movs r0, 0
	b _081CBA62
_081CBA1C:
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBA5C
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CBA62
_081CBA34:
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	bl sub_81C87AC
	movs r0, 0
	b _081CBA62
_081CBA40:
	adds r0, r4, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CBA62
_081CBA4A:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBA5C
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	beq _081CBA60
_081CBA5C:
	movs r0, 0x2
	b _081CBA62
_081CBA60:
	movs r0, 0x4
_081CBA62:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB9C8

	thumb_func_start sub_81CBA68
sub_81CBA68: @ 81CBA68
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CBA9C
	cmp r4, 0x1
	bgt _081CBA82
	cmp r4, 0
	beq _081CBA88
	b _081CBACC
_081CBA82:
	cmp r4, 0x2
	beq _081CBABE
	b _081CBACC
_081CBA88:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CC420
	bl sub_81C87F0
	movs r0, 0
	b _081CBACE
_081CBA9C:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBAC8
	adds r0, r5, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBAC8
	movs r0, 0x6
	bl sub_81C7BA4
	adds r0, r5, 0
	bl sub_81CBDC0
	movs r0, 0
	b _081CBACE
_081CBABE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CBACC
_081CBAC8:
	movs r0, 0x2
	b _081CBACE
_081CBACC:
	movs r0, 0x4
_081CBACE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBA68

	thumb_func_start sub_81CBAD4
sub_81CBAD4: @ 81CBAD4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081CBB6C
	lsls r0, r5, 2
	ldr r1, =_081CBAF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CBAF4:
	.4byte _081CBB08
	.4byte _081CBB28
	.4byte _081CBB40
	.4byte _081CBB4C
	.4byte _081CBB56
_081CBB08:
	bl GetMatchCallListTopIndex
	bl sub_81CB128
	adds r5, r0, 0
	cmp r5, 0
	beq _081CBB6C
	movs r0, 0x5
	bl PlaySE
	strh r5, [r4, 0x16]
	adds r0, r4, 0
	bl sub_81CC420
	movs r0, 0
	b _081CBB6E
_081CBB28:
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	bne _081CBB68
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, 0
	bl sub_81CBEF8
	movs r0, 0
	b _081CBB6E
_081CBB40:
	movs r1, 0x16
	ldrsh r0, [r4, r1]
	bl sub_81C87AC
	movs r0, 0
	b _081CBB6E
_081CBB4C:
	adds r0, r4, 0
	bl sub_81CC39C
	movs r0, 0
	b _081CBB6E
_081CBB56:
	bl sub_81C8820
	cmp r0, 0
	bne _081CBB68
	adds r0, r4, 0
	bl sub_81CC42C
	cmp r0, 0
	beq _081CBB6C
_081CBB68:
	movs r0, 0x2
	b _081CBB6E
_081CBB6C:
	movs r0, 0x4
_081CBB6E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBAD4

	thumb_func_start sub_81CBB74
sub_81CBB74: @ 81CBB74
	push {lr}
	cmp r0, 0
	beq _081CBB80
	cmp r0, 0x1
	beq _081CBB9A
	b _081CBBB2
_081CBB80:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81CBC38
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081CBBB4
_081CBB9A:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CBBAA
	bl MainMenuLoopedTaskIsBusy
	cmp r0, 0
	beq _081CBBAE
_081CBBAA:
	movs r0, 0x2
	b _081CBBB4
_081CBBAE:
	bl sub_81C7FDC
_081CBBB2:
	movs r0, 0x4
_081CBBB4:
	pop {r1}
	bx r1
	thumb_func_end sub_81CBB74

	thumb_func_start sub_81CBBB8
sub_81CBBB8: @ 81CBBB8
	push {lr}
	sub sp, 0x18
	bl sub_81CAE94
	str r0, [sp]
	bl sub_81CAE38
	mov r1, sp
	movs r2, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	mov r0, sp
	strh r2, [r0, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x10
	strb r0, [r1, 0xA]
	movs r0, 0x1
	strb r0, [r1, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x3
	strb r0, [r1, 0xD]
	movs r0, 0x7
	strb r0, [r1, 0xE]
	ldr r0, =sub_81CB050
	str r0, [sp, 0x10]
	ldr r0, =sub_81CBCEC
	str r0, [sp, 0x14]
	ldr r0, =gUnknown_08622794
	movs r2, 0x2
	bl sub_81C81D4
	ldr r0, =sub_81CBC64
	movs r1, 0x7
	bl CreateTask
	add sp, 0x18
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBBB8

	thumb_func_start sub_81CBC1C
sub_81CBC1C: @ 81CBC1C
	push {lr}
	bl sub_81C8234
	ldr r0, =sub_81CBC64
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC1C

	thumb_func_start sub_81CBC38
sub_81CBC38: @ 81CBC38
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_81CBC64
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081CBC56
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x26]
_081CBC56:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC38

	thumb_func_start sub_81CBC64
sub_81CBC64: @ 81CBC64
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	movs r1, 0x1E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _081CBCC8
	ldrh r0, [r2]
	adds r0, 0x4
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, =gSineTable
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x2]
	ldr r0, =gUnknown_08622720
	adds r1, r0, 0
	adds r1, 0x20
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	str r2, [sp]
	ldr r4, =gPlttBufferUnfaded + 0xA0
	str r4, [sp, 0x4]
	movs r2, 0x10
	movs r3, 0x10
	bl sub_81C79BC
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081CBCC8
	ldr r1, =gPlttBufferFaded + 0xA0
	ldr r2, =0x04000008
	adds r0, r4, 0
	bl CpuSet
_081CBCC8:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBC64

	thumb_func_start sub_81CBCEC
sub_81CBCEC: @ 81CBCEC
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	adds r6, r0, 0
	lsls r4, 7
	adds r4, 0x3A
	adds r6, r4
	adds r0, r5, 0
	bl sub_81CAEBC
	cmp r0, 0
	beq _081CBD30
	movs r1, 0xA0
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r6]
	adds r1, r6, 0
	adds r1, 0x40
	ldr r2, =0x00005001
	adds r0, r2, 0
	strh r0, [r1]
	b _081CBD3C
	.pool
_081CBD30:
	ldr r0, =0x00005002
	adds r1, r0, 0
	strh r1, [r6]
	adds r0, r6, 0
	adds r0, 0x40
	strh r1, [r0]
_081CBD3C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBCEC

	thumb_func_start sub_81CBD48
sub_81CBD48: @ 81CBD48
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	lsls r4, 7
	adds r4, 0x3A
	adds r0, r4
	ldr r2, =0x00005002
	adds r1, r2, 0
	strh r1, [r0]
	adds r0, 0x40
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBD48

	thumb_func_start sub_81CBD78
sub_81CBD78: @ 81CBD78
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086227D8
	bl AddWindow
	strh r0, [r4, 0x10]
	ldr r0, =gUnknown_086227E0
	bl AddWindow
	strh r0, [r4, 0x12]
	ldrb r0, [r4, 0x10]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x10]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x12]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x10]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBD78

	thumb_func_start sub_81CBDC0
sub_81CBDC0: @ 81CBDC0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x12]
	bl sub_81CBDF4
	ldrh r0, [r4, 0x12]
	bl sub_81CBE0C
	ldrh r0, [r4, 0x12]
	bl sub_81CBE38
	ldrh r0, [r4, 0x12]
	bl sub_81CBE50
	ldrb r0, [r4, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBDC0

	thumb_func_start sub_81CBDF4
sub_81CBDF4: @ 81CBDF4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gText_NumberRegistered
	movs r2, 0
	bl sub_81CBE88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBDF4

	thumb_func_start sub_81CBE0C
sub_81CBE0C: @ 81CBE0C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CAE38
	adds r1, r0, 0
	mov r0, sp
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_81CBEB4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBE0C

	thumb_func_start sub_81CBE38
sub_81CBE38: @ 81CBE38
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gText_NumberOfBattles
	movs r2, 0x2
	bl sub_81CBE88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBE38

	thumb_func_start sub_81CBE50
sub_81CBE50: @ 81CBE50
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x9
	bl GetGameStat
	adds r1, r0, 0
	ldr r0, =0x0001869f @ Note to decompiler: See UNKNOWN_OFFSET
	cmp r1, r0
	ble _081CBE68
	adds r1, r0, 0
_081CBE68:
	mov r0, sp
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x3
	bl sub_81CBEB4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBE50

	thumb_func_start sub_81CBE88
sub_81CBE88: @ 81CBE88
	push {lr}
	sub sp, 0xC
	adds r3, r1, 0
	lsls r2, 4
	adds r2, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r3, 0
	movs r3, 0x2
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_81CBE88

	thumb_func_start sub_81CBEB4
sub_81CBEB4: @ 81CBEB4
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x7
	movs r2, 0x56
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r4, 4
	adds r4, 0x1
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x7
	adds r2, r6, 0
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBEB4

	thumb_func_start sub_81CBEF8
sub_81CBEF8: @ 81CBEF8
	push {r4,r5,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	adds r4, r1, 0
	bl GetSelectedMatchCall
	adds r0, r4
	bl sub_81CAEA4
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xD5
	beq _081CBF1C
	add r0, sp, 0xC
	movs r2, 0
	bl GetMapName
	b _081CBF24
_081CBF1C:
	ldr r1, =gText_Unknown
	add r0, sp, 0xC
	bl StringCopy
_081CBF24:
	movs r0, 0x7
	add r1, sp, 0xC
	movs r2, 0x58
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	ldrb r0, [r5, 0x10]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x10]
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x7
	add r2, sp, 0xC
	adds r3, r4, 0
	bl AddTextPrinterParameterized
	add sp, 0x2C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBEF8

	thumb_func_start sub_81CBF60
sub_81CBF60: @ 81CBF60
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldrb r0, [r5, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r4, 0
	movs r6, 0x80
	lsls r6, 17
	b _081CBF9C
_081CBF76:
	ldrb r0, [r5, 0x12]
	ldr r2, =gUnknown_086227E8
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	lsrs r1, r6, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0x10
	bl AddTextPrinterParameterized
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r4, 0x1
_081CBF9C:
	cmp r4, 0x2
	bhi _081CBFAE
	adds r0, r4, 0
	bl sub_81CB02C
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bne _081CBF76
_081CBFAE:
	ldrb r0, [r5, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CBF60

	thumb_func_start sub_81CBFC4
sub_81CBFC4: @ 81CBFC4
	push {r4,lr}
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CBFD6
	movs r0, 0x1
	b _081CBFE8
_081CBFD6:
	bl sub_81CB01C
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_81CC2F0
	movs r0, 0
_081CBFE8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CBFC4

	thumb_func_start sub_81CBFF0
sub_81CBFF0: @ 81CBFF0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CC330
	adds r0, r4, 0
	bl sub_81CBDC0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CBFF0

	thumb_func_start sub_81CC004
sub_81CC004: @ 81CC004
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC004

	thumb_func_start sub_81CC014
sub_81CC014: @ 81CC014
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CC330
	ldrb r0, [r4, 0x12]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x12]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC014

	thumb_func_start sub_81CC034
sub_81CC034: @ 81CC034
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08622808
	bl AddWindow
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_8197184
	bl sub_81C7B40
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC034

	thumb_func_start sub_81CC058
sub_81CC058: @ 81CC058
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_8197184
	ldrh r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl sub_81971C4
	ldrb r0, [r4, 0x14]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x14]
	movs r1, 0x3
	bl CopyWindowToVram
	bl PauseSpinningPokenavSprite
	movs r2, 0
	movs r1, 0x18
	strh r1, [r0, 0x20]
	movs r1, 0x70
	strh r1, [r0, 0x22]
	strh r2, [r0, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC058

	thumb_func_start sub_81CC09C
sub_81CC09C: @ 81CC09C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x40
	bl LoadUserWindowBorderGfx
	ldrb r0, [r4, 0x14]
	movs r1, 0x1
	movs r2, 0x4
	bl DrawTextBorderOuter
	ldrb r0, [r4, 0x14]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x14]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC09C

	thumb_func_start sub_81CC0D0
sub_81CC0D0: @ 81CC0D0
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC0D0

	thumb_func_start sub_81CC0E0
sub_81CC0E0: @ 81CC0E0
	push {lr}
	sub sp, 0xC
	ldrb r0, [r0, 0x14]
	ldr r2, =gUnknown_086227F4
	movs r1, 0x1
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x20
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC0E0

	thumb_func_start sub_81CC104
sub_81CC104: @ 81CC104
	push {r4,lr}
	adds r4, r0, 0
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC104

	thumb_func_start sub_81CC11C
sub_81CC11C: @ 81CC11C
	push {lr}
	sub sp, 0xC
	ldrb r0, [r0, 0x14]
	ldr r2, =gText_TrainerCloseBy
	movs r1, 0x1
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC11C

	thumb_func_start sub_81CC140
sub_81CC140: @ 81CC140
	push {r4,lr}
	adds r4, r0, 0
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC140

	thumb_func_start sub_81CC158
sub_81CC158: @ 81CC158
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl GetSelectedMatchCall
	adds r1, r4, 0
	adds r1, 0xF
	bl sub_81CAF78
	adds r5, r0, 0
	bl GetPlayerTextSpeedDelay
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x14]
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r2, 0
	adds r2, r5, 0
	movs r3, 0x20
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC158

	thumb_func_start sub_81CC194
sub_81CC194: @ 81CC194
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CC1B8
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _081CC1C4
	.pool
_081CC1B8:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081CC1C4:
	bl RunTextPrinters
	ldrb r0, [r4, 0x14]
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC194

	thumb_func_start sub_81CC1DC
sub_81CC1DC: @ 81CC1DC
	push {lr}
	sub sp, 0x8
	bl ResumeSpinningPokenavSprite
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81CC1DC

	thumb_func_start sub_81CC204
sub_81CC204: @ 81CC204
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CC204

	thumb_func_start sub_81CC214
sub_81CC214: @ 81CC214
	push {r4-r6,lr}
	sub sp, 0x8
	movs r0, 0x6
	bl GetSubstructPtr
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_08622810
_081CC224:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081CC224
	ldr r0, =gUnknown_08622818
	bl Pokenav_AllocAndLoadPalettes
	movs r0, 0
	str r0, [r6, 0x1C]
	ldr r1, =0x00001828
	adds r0, r6, r1
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r2, =0x00001824
	adds r1, r6, r2
	lsls r0, 16
	lsrs r0, 11
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	movs r0, 0xD
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r6, 0x1A]
	bl sub_81CC370
	str r0, [r6, 0x20]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC214

	thumb_func_start sub_81CC2B4
sub_81CC2B4: @ 81CC2B4
	push {r4,lr}
	movs r0, 0x6
	bl GetSubstructPtr
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CC2C8
	bl DestroySprite
_081CC2C8:
	ldr r0, [r4, 0x20]
	cmp r0, 0
	beq _081CC2D2
	bl DestroySprite
_081CC2D2:
	movs r0, 0x8
	bl FreeSpriteTilesByTag
	movs r0, 0x7
	bl FreeSpriteTilesByTag
	movs r0, 0xC
	bl FreeSpritePaletteByTag
	movs r0, 0xD
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC2B4

	thumb_func_start sub_81CC2F0
sub_81CC2F0: @ 81CC2F0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4, 0x1C]
	cmp r0, 0
	bne _081CC320
	ldr r0, =gUnknown_08622830
	movs r1, 0x4
	movs r2, 0x50
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81CC344
_081CC320:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC2F0

	thumb_func_start sub_81CC330
sub_81CC330: @ 81CC330
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x1C]
	bl DestroySprite
	movs r0, 0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC330

	thumb_func_start sub_81CC344
sub_81CC344: @ 81CC344
	ldr r0, [r0, 0x1C]
	lsls r1, 4
	strh r1, [r0, 0x26]
	bx lr
	thumb_func_end sub_81CC344

	thumb_func_start sub_81CC34C
sub_81CC34C: @ 81CC34C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081CC36C
	movs r0, 0
	strh r0, [r2, 0x2E]
	ldrh r0, [r2, 0x24]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r2, 0x24]
_081CC36C:
	pop {r0}
	bx r0
	thumb_func_end sub_81CC34C

	thumb_func_start sub_81CC370
sub_81CC370: @ 81CC370
	push {lr}
	ldr r0, =gUnknown_08622850
	movs r1, 0x2C
	movs r2, 0x68
	movs r3, 0x6
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC370

	thumb_func_start sub_81CC39C
sub_81CC39C: @ 81CC39C
	push {r4-r7,lr}
	adds r7, r0, 0
	bl GetSelectedMatchCall
	bl sub_81CAF04
	cmp r0, 0
	blt _081CC400
	lsls r4, r0, 3
	ldr r0, =gTrainerFrontPicTable
	adds r0, r4, r0
	ldr r1, =0x00001828
	adds r5, r7, r1
	adds r1, r5, 0
	movs r2, 0
	bl DecompressPicFromTable
	ldr r0, =gTrainerFrontPicPaletteTable
	adds r4, r0
	ldr r0, [r4]
	ldr r1, =0x00002028
	adds r6, r7, r1
	adds r1, r6, 0
	bl LZ77UnCompWram
	ldr r1, =0x00001824
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrh r1, [r7, 0x1A]
	adds r0, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, [r7, 0x20]
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, [r7, 0x20]
	strh r4, [r0, 0x3C]
	ldr r1, [r7, 0x20]
	ldr r0, =sub_81CC440
	str r0, [r1, 0x1C]
_081CC400:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC39C

	thumb_func_start sub_81CC420
sub_81CC420: @ 81CC420
	ldr r1, [r0, 0x20]
	ldr r0, =sub_81CC4A4
	str r0, [r1, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_81CC420

	thumb_func_start sub_81CC42C
sub_81CC42C: @ 81CC42C
	ldr r0, [r0, 0x20]
	ldr r1, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81CC42C

	thumb_func_start sub_81CC440
sub_81CC440: @ 81CC440
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081CC452
	cmp r0, 0x1
	beq _081CC484
	b _081CC498
_081CC452:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	bl CheckForSpaceForDma3Request
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081CC498
	ldr r0, =0x0000ffb0
	strh r0, [r4, 0x24]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081CC498
	.pool
_081CC484:
	ldrh r0, [r4, 0x24]
	adds r0, 0x8
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	blt _081CC498
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081CC498:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC440

	thumb_func_start sub_81CC4A4
sub_81CC4A4: @ 81CC4A4
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x24]
	subs r0, 0x8
	strh r0, [r3, 0x24]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x50
	negs r1, r1
	cmp r0, r1
	bgt _081CC4CA
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_081CC4CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC4A4

	.align 2, 0 @ Don't pad with nop.
