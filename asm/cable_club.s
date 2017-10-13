	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80B236C
sub_80B236C: @ 80B236C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, =sub_80B2634
	adds r0, r4, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080B23A0
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0xA]
	strh r5, [r1, 0xC]
_080B23A0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B236C

	thumb_func_start sub_80B23B0
sub_80B23B0: @ 80B23B0
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gStringVar1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r5, =gStringVar4
	ldr r1, =gText_XPLink
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x58
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
	bl PrintTextOnWindow
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B23B0

	thumb_func_start sub_80B241C
sub_80B241C: @ 80B241C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_819746C
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B241C

	thumb_func_start sub_80B243C
sub_80B243C: @ 80B243C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r5, r0
	beq _080B2472
	cmp r5, 0x1
	bhi _080B2468
	ldrh r0, [r4, 0xA]
	bl sub_80B241C
	b _080B2470
	.pool
_080B2468:
	ldrh r0, [r4, 0xA]
	adds r1, r5, 0
	bl sub_80B23B0
_080B2470:
	strh r5, [r4, 0x6]
_080B2472:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B243C

	thumb_func_start sub_80B2478
sub_80B2478: @ 80B2478
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl sub_800A0C8
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x6
	bhi _080B24F0
	lsls r0, 2
	ldr r1, =_080B24A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B24A0:
	.4byte _080B24BC
	.4byte _080B24F0
	.4byte _080B24C0
	.4byte _080B24C4
	.4byte _080B24C8
	.4byte _080B24CC
	.4byte _080B24EC
_080B24BC:
	movs r0, 0x1
	b _080B24F2
_080B24C0:
	movs r0, 0x3
	b _080B24F2
_080B24C4:
	movs r0, 0x7
	b _080B24F2
_080B24C8:
	movs r0, 0x9
	b _080B24F2
_080B24CC:
	ldr r4, =gStringVar1
	bl sub_800ABAC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	b _080B24F2
	.pool
_080B24EC:
	movs r0, 0xA
	b _080B24F2
_080B24F0:
	movs r0, 0
_080B24F2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B2478

	thumb_func_start sub_80B24F8
sub_80B24F8: @ 80B24F8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800B33C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B250E
	movs r0, 0
	b _080B251E
_080B250E:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B2D2C
	str r0, [r1]
	movs r0, 0x1
_080B251E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B24F8

	thumb_func_start sub_80B252C
sub_80B252C: @ 80B252C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080B2570
	bl sub_800B320
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080B2570
	ldr r0, =gUnknown_020229C6
	strh r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B2CEC
	str r1, [r0]
	movs r0, 0x1
	b _080B2572
	.pool
_080B2570:
	movs r0, 0
_080B2572:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B252C

	thumb_func_start sub_80B2578
sub_80B2578: @ 80B2578
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800B320
	lsls r0, 24
	cmp r0, 0
	beq _080B258E
	movs r0, 0x1
	bl sub_800B330
_080B258E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080B25A4
	movs r0, 0
	b _080B25BA
	.pool
_080B25A4:
	ldr r1, =gUnknown_020229C6
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B2CEC
	str r1, [r0]
	movs r0, 0x1
_080B25BA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2578

	thumb_func_start sub_80B25CC
sub_80B25CC: @ 80B25CC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800B2E8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B25E2
	movs r0, 0
	b _080B25F2
_080B25E2:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B2D2C
	str r0, [r1]
	movs r0, 0x1
_080B25F2:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B25CC

	thumb_func_start sub_80B2600
sub_80B2600: @ 80B2600
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _080B262A
	movs r0, 0x2
	bl sub_800A4D8
	adds r0, r4, 0
	bl DestroyTask
_080B262A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2600

	thumb_func_start sub_80B2634
sub_80B2634: @ 80B2634
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r3, 0
	ldrsh r2, [r4, r3]
	cmp r2, 0
	bne _080B266C
	bl sub_800A0AC
	bl sub_800AB98
	bl sub_800A2BC
	ldr r0, =gUnknown_08550594
	bl AddWindow
	strh r0, [r4, 0xA]
	b _080B2678
	.pool
_080B266C:
	cmp r2, 0x9
	ble _080B2678
	subs r0, 0x8
	adds r0, r1, r0
	ldr r1, =sub_80B2688
	str r1, [r0]
_080B2678:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2634

	thumb_func_start sub_80B2688
sub_80B2688: @ 80B2688
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_800ABAC
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl sub_80B252C
	cmp r0, 0x1
	beq _080B26FC
	adds r0, r4, 0
	bl sub_80B2578
	cmp r0, 0x1
	beq _080B26FC
	cmp r5, 0x1
	bls _080B26FC
	movs r0, 0x1
	bl sub_800B330
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0
	strh r0, [r4, 0xE]
	bl sub_800ABBC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B26EC
	movs r0, 0x15
	bl PlaySE
	ldr r0, =gUnknown_082780B3
	bl box_related_two__3
	ldr r0, =sub_80B270C
	b _080B26FA
	.pool
_080B26EC:
	movs r0, 0x16
	bl PlaySE
	ldr r0, =gUnknown_08278131
	bl box_related_two__3
	ldr r0, =sub_80B2918
_080B26FA:
	str r0, [r4]
_080B26FC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2688

	thumb_func_start sub_80B270C
sub_80B270C: @ 80B270C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80B252C
	cmp r0, 0x1
	beq _080B274C
	adds r0, r4, 0
	bl sub_80B25CC
	cmp r0, 0x1
	beq _080B274C
	adds r0, r4, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B274C
	bl textbox_any_visible
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080B274C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0xE]
	ldr r0, =sub_80B275C
	str r0, [r1]
_080B274C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B270C

	thumb_func_start sub_80B275C
sub_80B275C: @ 80B275C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r9, r0
	mov r7, r8
	add r7, r9
	bl sub_800ABAC
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl sub_80B252C
	cmp r0, 0x1
	beq _080B27E4
	adds r0, r4, 0
	bl sub_80B25CC
	cmp r0, 0x1
	beq _080B27E4
	adds r0, r4, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B27E4
	adds r6, r5, 0
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80B243C
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B27E4
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r5, r0
	blt _080B27E4
	adds r0, r6, 0
	bl sub_800AA04
	ldrh r0, [r7, 0xA]
	bl sub_80B241C
	ldr r0, =gStringVar1
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_082780F2
	bl box_related_two__3
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_80B2804
	str r1, [r0]
_080B27E4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B275C

	thumb_func_start sub_80B2804
sub_80B2804: @ 80B2804
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	adds r0, r5, 0
	bl sub_80B252C
	cmp r0, 0x1
	beq _080B2898
	adds r0, r5, 0
	bl sub_80B25CC
	cmp r0, 0x1
	beq _080B2898
	adds r0, r5, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B2898
	bl textbox_any_visible
	lsls r0, 24
	cmp r0, 0
	bne _080B2898
	bl sub_800AA48
	adds r4, r0, 0
	bl sub_800ABAC
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080B2852
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080B2878
_080B2852:
	ldr r0, =gUnknown_082780B3
	bl box_related_two__3
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B270C
	str r1, [r0]
	b _080B2898
	.pool
_080B2878:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B2898
	movs r0, 0x5
	bl PlaySE
	bl sub_800A620
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B28A8
	str r0, [r1]
_080B2898:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2804

	thumb_func_start sub_80B28A8
sub_80B28A8: @ 80B28A8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrb r7, [r5, 0xA]
	ldrb r6, [r5, 0xC]
	adds r0, r4, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B290A
	adds r0, r4, 0
	bl sub_80B2D6C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080B290A
	bl sub_800ABAC
	adds r4, r0, 0
	bl sub_800AA48
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080B28F4
	ldr r0, =sub_80B2D2C
	b _080B2908
	.pool
_080B28F4:
	ldr r4, =gScriptResult
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80B2478
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	beq _080B290A
	ldr r0, =sub_80B2A08
_080B2908:
	str r0, [r5]
_080B290A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B28A8

	thumb_func_start sub_80B2918
sub_80B2918: @ 80B2918
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r7, r0, r1
	ldrb r6, [r7, 0xA]
	ldrb r5, [r7, 0xC]
	adds r0, r4, 0
	bl sub_80B252C
	cmp r0, 0x1
	beq _080B29E6
	adds r0, r4, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B29E6
	ldr r4, =gScriptResult
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80B2478
	adds r1, r0, 0
	strh r1, [r4]
	lsls r0, r1, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _080B29E6
	subs r0, r1, 0x3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080B297C
	bl sub_800AC34
	bl textbox_close
	ldr r0, =sub_80B2CB0
	b _080B29E4
	.pool
_080B297C:
	cmp r2, 0x7
	beq _080B2984
	cmp r2, 0x9
	bne _080B2994
_080B2984:
	bl sub_80097E8
	bl textbox_close
	ldr r0, =sub_80B2CB0
	b _080B29E4
	.pool
_080B2994:
	bl sub_800ABAC
	ldr r4, =gUnknown_03005DB8
	strb r0, [r4]
	bl GetMultiplayerId
	ldr r1, =gUnknown_03005DB4
	strb r0, [r1]
	ldrb r0, [r4]
	bl sub_800AA04
	ldr r4, =gUnknown_020228C4
	adds r0, r4, 0
	bl sub_80C30A4
	ldr r0, =gUnknown_0203CEF8
	mov r8, r0
	ldrb r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gBattleScripting + 0x14
	adds r0, r5
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r4, 0
	adds r1, 0x54
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1, 0x1]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, 0x56
	strh r0, [r4]
	ldr r0, =sub_80B2C30
_080B29E4:
	str r0, [r7]
_080B29E6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2918

	thumb_func_start sub_80B2A08
sub_80B2A08: @ 80B2A08
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r7, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B2ACE
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x4
	bne _080B2A38
	bl sub_800A064
	cmp r0, 0
	bne _080B2A4A
	bl sub_800AC34
	b _080B2A4E
	.pool
_080B2A38:
	cmp r0, 0x3
	bne _080B2A42
	bl sub_800AC34
	b _080B2A4E
_080B2A42:
	cmp r0, 0x7
	beq _080B2A4A
	cmp r0, 0x9
	bne _080B2A6C
_080B2A4A:
	bl sub_80097E8
_080B2A4E:
	bl textbox_close
	ldr r0, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B2CB0
	str r0, [r1]
	b _080B2ACE
	.pool
_080B2A6C:
	bl sub_800ABAC
	ldr r4, =gUnknown_03005DB8
	strb r0, [r4]
	bl GetMultiplayerId
	ldr r1, =gUnknown_03005DB4
	strb r0, [r1]
	ldrb r0, [r4]
	bl sub_800AA04
	ldr r4, =gUnknown_020228C4
	adds r0, r4, 0
	bl sub_80C30A4
	ldr r0, =gUnknown_0203CEF8
	mov r8, r0
	ldrb r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gBattleScripting + 0x14
	adds r0, r5
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r4, 0
	adds r1, 0x54
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1, 0x1]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, 0x56
	strh r0, [r4]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B2C30
	str r1, [r0]
	movs r0, 0x2
	bl sub_800A4D8
_080B2ACE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2A08

	thumb_func_start sub_80B2AF4
sub_80B2AF4: @ 80B2AF4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r2, 0
	movs r7, 0
	ldr r1, =gStringVar1
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, =gStringVar2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0
	movs r0, 0xB
	mov r10, r0
	ldr r0, =gSpeciesNames
	mov r9, r0
_080B2B20:
	lsls r0, r1, 1
	adds r1, 0x1
	mov r8, r1
	ldr r1, [sp]
	adds r4, r0, r1
	ldr r5, [sp, 0x4]
	movs r6, 0x1
_080B2B2E:
	ldrh r0, [r4]
	ldrh r1, [r5]
	cmp r0, r1
	bne _080B2B5E
	cmp r7, 0
	bne _080B2B48
	mov r1, r10
	muls r1, r0
	add r1, r9
	ldr r0, =gStringVar1
	bl StringCopy
	movs r2, 0x1
_080B2B48:
	cmp r7, 0x1
	bne _080B2B5C
	ldrh r0, [r4]
	mov r1, r10
	muls r1, r0
	add r1, r9
	ldr r0, =gStringVar2
	bl StringCopy
	movs r2, 0x1
_080B2B5C:
	adds r7, 0x1
_080B2B5E:
	adds r5, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _080B2B2E
	mov r1, r8
	cmp r1, 0x1
	ble _080B2B20
	ldr r0, =gSpecialVar_0x8005
	strh r7, [r0]
	adds r0, r2, 0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2AF4

	thumb_func_start task_map_chg_seq_0807EC34
task_map_chg_seq_0807EC34: @ 80B2B94
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_02039B58
	ldrh r0, [r5]
	cmp r0, 0x1
	bne _080B2C10
	ldr r0, =gUnknown_020229C6
	ldrh r2, [r0]
	ldr r0, =0x00002266
	cmp r2, r0
	beq _080B2BB2
	adds r0, 0x11
	cmp r2, r0
	bne _080B2BEC
_080B2BB2:
	adds r0, r1, 0
	adds r0, 0x54
	adds r1, 0xB8
	bl sub_80B2AF4
	cmp r0, 0
	beq _080B2BEC
	movs r0, 0xB
	strh r0, [r5]
	bl sub_800AC34
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B2CB0
	str r1, [r0]
	b _080B2C22
	.pool
_080B2BEC:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x12]
	bl sub_80B241C
	bl EnableBothScriptContexts
	lsls r0, r4, 24
	lsrs r0, 24
	bl DestroyTask
	b _080B2C22
	.pool
_080B2C10:
	bl sub_800AC34
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B2CB0
	str r0, [r1]
_080B2C22:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_map_chg_seq_0807EC34

	thumb_func_start sub_80B2C30
sub_80B2C30: @ 80B2C30
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_80B24F8
	cmp r0, 0x1
	beq _080B2C9C
	bl GetBlockReceivedStatus
	adds r4, r0, 0
	bl sub_800A9A8
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080B2C9C
	movs r4, 0
	ldr r6, =gLinkPlayers
	b _080B2C7E
	.pool
_080B2C5C:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gUnknown_02039B58
	adds r0, r1
	lsls r1, r4, 8
	ldr r2, =gBlockRecvBuffer
	adds r1, r2
	lsls r2, r4, 3
	subs r2, r4
	lsls r2, 2
	adds r2, r6
	ldrb r2, [r2]
	bl sub_80C3120
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080B2C7E:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _080B2C5C
	movs r0, 0
	bl sub_800B330
	bl ResetBlockReceivedFlags
	ldr r0, =gScriptResult
	adds r1, r5, 0
	bl task_map_chg_seq_0807EC34
_080B2C9C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2C30

	thumb_func_start sub_80B2CB0
sub_80B2CB0: @ 80B2CB0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B2CDE
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x12]
	bl sub_80B241C
	bl EnableBothScriptContexts
	ldrb r0, [r4, 0x12]
	bl RemoveWindow
	adds r0, r5, 0
	bl DestroyTask
_080B2CDE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2CB0

	thumb_func_start sub_80B2CEC
sub_80B2CEC: @ 80B2CEC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gScriptResult
	movs r0, 0x5
	strh r0, [r1]
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x12]
	bl sub_80B241C
	bl sub_8098374
	ldrb r0, [r4, 0x12]
	bl RemoveWindow
	bl EnableBothScriptContexts
	adds r0, r5, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2CEC

	thumb_func_start sub_80B2D2C
sub_80B2D2C: @ 80B2D2C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gScriptResult
	movs r0, 0x6
	strh r0, [r1]
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x12]
	bl sub_80B241C
	ldrb r0, [r4, 0x12]
	bl RemoveWindow
	bl textbox_close
	bl EnableBothScriptContexts
	adds r0, r5, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2D2C

	thumb_func_start sub_80B2D6C
sub_80B2D6C: @ 80B2D6C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	strh r0, [r2, 0x10]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 18
	cmp r0, r1
	bgt _080B2D94
	movs r0, 0
	b _080B2D9A
	.pool
_080B2D94:
	ldr r0, =sub_80B2D2C
	str r0, [r2]
	movs r0, 0x1
_080B2D9A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B2D6C

	thumb_func_start sub_80B2DA4
sub_80B2DA4: @ 80B2DA4
	push {r4,lr}
	movs r3, 0x2
	movs r2, 0x2
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x2
	beq _080B2DDC
	cmp r0, 0x2
	bgt _080B2DC0
	cmp r0, 0x1
	beq _080B2DCA
	b _080B2E34
	.pool
_080B2DC0:
	cmp r0, 0x5
	beq _080B2DEC
	cmp r0, 0x9
	beq _080B2E00
	b _080B2E34
_080B2DCA:
	movs r3, 0x2
	ldr r1, =gUnknown_020229C6
	ldr r4, =0x00002233
	b _080B2E30
	.pool
_080B2DDC:
	movs r3, 0x2
	ldr r1, =gUnknown_020229C6
	ldr r4, =0x00002244
	b _080B2E30
	.pool
_080B2DEC:
	movs r3, 0x4
	movs r2, 0x4
	ldr r1, =gUnknown_020229C6
	ldr r4, =0x00002255
	b _080B2E30
	.pool
_080B2E00:
	movs r3, 0x2
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B2E2C
	ldr r1, =gUnknown_020229C6
	ldr r4, =0x00002266
	b _080B2E30
	.pool
_080B2E2C:
	ldr r1, =gUnknown_020229C6
	ldr r4, =0x00002277
_080B2E30:
	adds r0, r4, 0
	strh r0, [r1]
_080B2E34:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_80B236C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2DA4

	thumb_func_start sub_80B2E4C
sub_80B2E4C: @ 80B2E4C
	push {lr}
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00001133
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	movs r0, 0x2
	movs r1, 0x2
	bl sub_80B236C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2E4C

	thumb_func_start sub_80B2E74
sub_80B2E74: @ 80B2E74
	push {lr}
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00003311
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	bl sub_80B236C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2E74

	thumb_func_start sub_80B2EA8
sub_80B2EA8: @ 80B2EA8
	push {r4,lr}
	ldr r4, =sub_80B2EE4
	adds r0, r4, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _080B2ED4
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x8]
_080B2ED4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2EA8

	thumb_func_start sub_80B2EE4
sub_80B2EE4: @ 80B2EE4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080B2F0C
	cmp r0, 0x1
	beq _080B2FB4
	b _080B2FC6
	.pool
_080B2F0C:
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _080B2FA8
	movs r7, 0
	movs r0, 0
	mov r8, r0
	mov r9, r0
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r7, r5
	bge _080B2F74
	ldr r0, =gLinkPlayers
	ldrb r2, [r0]
	ldrh r3, [r0, 0x1A]
	subs r1, r2, 0x1
	mov r12, r0
	cmp r1, 0x1
	bhi _080B2F4A
	b _080B2F6E
	.pool
_080B2F44:
	movs r1, 0x1
	mov r8, r1
	b _080B2F56
_080B2F4A:
	cmp r2, 0x3
	bne _080B2F56
	cmp r3, 0x1
	bne _080B2F56
	movs r0, 0x1
	mov r9, r0
_080B2F56:
	adds r4, 0x1
	cmp r4, r5
	bge _080B2F74
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	add r0, r12
	ldrb r2, [r0]
	ldrh r3, [r0, 0x1A]
	subs r0, r2, 0x1
	cmp r0, 0x1
	bhi _080B2F4A
_080B2F6E:
	cmp r3, 0x1
	bne _080B2F44
	movs r7, 0x1
_080B2F74:
	mov r1, r8
	cmp r1, 0
	beq _080B2F82
	mov r0, r9
	cmp r0, 0
	beq _080B2F82
	movs r7, 0x1
_080B2F82:
	cmp r7, 0
	beq _080B2FA8
	ldr r1, =gScriptResult
	movs r0, 0xC
	strh r0, [r1]
	bl sub_800AD10
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	b _080B2FC6
	.pool
_080B2FA8:
	bl EnableBothScriptContexts
	adds r0, r6, 0
	bl DestroyTask
	b _080B2FC6
_080B2FB4:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B2FC6
	bl EnableBothScriptContexts
	adds r0, r6, 0
	bl DestroyTask
_080B2FC6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2EE4

	thumb_func_start sub_80B2FD8
sub_80B2FD8: @ 80B2FD8
	push {lr}
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00004411
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	bl sub_80B236C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B2FD8

	thumb_func_start sub_80B3000
sub_80B3000: @ 80B3000
	push {lr}
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00006601
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	movs r0, 0x4
	movs r1, 0x4
	bl sub_80B236C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3000

	thumb_func_start sub_80B3028
sub_80B3028: @ 80B3028
	push {lr}
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00006602
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	movs r0, 0
	str r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	bl sub_80B236C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3028

	thumb_func_start sub_80B3050
sub_80B3050: @ 80B3050
	push {lr}
	ldr r0, =sub_80B3144
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _080B3068
	movs r0, 0xFF
	b _080B3134
	.pool
_080B3068:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r0, 0x8
	bhi _080B3128
	lsls r0, 2
	ldr r1, =_080B3084
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B3084:
	.4byte _080B30A8
	.4byte _080B30B8
	.4byte _080B3110
	.4byte _080B3120
	.4byte _080B30C8
	.4byte _080B3128
	.4byte _080B3128
	.4byte _080B3128
	.4byte _080B30D8
_080B30A8:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002233
	b _080B3124
	.pool
_080B30B8:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002244
	b _080B3124
	.pool
_080B30C8:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002255
	b _080B3124
	.pool
_080B30D8:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B3100
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002266
	b _080B3124
	.pool
_080B3100:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002277
	b _080B3124
	.pool
_080B3110:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00001111
	b _080B3124
	.pool
_080B3120:
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00003322
_080B3124:
	adds r0, r2, 0
	strh r0, [r1]
_080B3128:
	ldr r0, =sub_80B3144
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
_080B3134:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B3050

	thumb_func_start sub_80B3144
sub_80B3144: @ 80B3144
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r3, 0
	ldrsh r2, [r4, r3]
	cmp r2, 0
	bne _080B3178
	bl sub_8009734
	bl sub_800A2BC
	ldr r0, =task00_08081A90
	movs r1, 0x50
	bl CreateTask
	b _080B3184
	.pool
_080B3178:
	cmp r2, 0x9
	ble _080B3184
	subs r0, 0x8
	adds r0, r1, r0
	ldr r1, =sub_80B3194
	str r1, [r0]
_080B3184:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3144

	thumb_func_start sub_80B3194
sub_80B3194: @ 80B3194
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl sub_800ABAC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080B31DA
	bl sub_800ABBC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B31CC
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B31E8
	b _080B31D8
	.pool
_080B31CC:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B3220
_080B31D8:
	str r0, [r1]
_080B31DA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3194

	thumb_func_start sub_80B31E8
sub_80B31E8: @ 80B31E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_800AA48
	adds r4, r0, 0
	bl sub_800ABAC
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080B3212
	bl sub_800A620
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80B3220
	str r0, [r1]
_080B3212:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B31E8

	thumb_func_start sub_80B3220
sub_80B3220: @ 80B3220
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080B3248
	bl sub_800A23C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B3248
	bl sub_800AB18
	bl sub_8009F18
	adds r0, r4, 0
	bl DestroyTask
_080B3248:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3220

	thumb_func_start sub_80B3254
sub_80B3254: @ 80B3254
	push {lr}
	bl sub_809FF80
	pop {r0}
	bx r0
	thumb_func_end sub_80B3254

	thumb_func_start sub_80B3260
sub_80B3260: @ 80B3260
	push {lr}
	cmp r0, 0x2
	beq _080B3284
	cmp r0, 0x2
	bgt _080B3270
	cmp r0, 0x1
	beq _080B327A
	b _080B32A6
_080B3270:
	cmp r0, 0x5
	beq _080B3290
	cmp r0, 0x9
	beq _080B32A0
	b _080B32A6
_080B327A:
	ldr r1, =gBattleTypeFlags
	movs r0, 0xA
	b _080B32A4
	.pool
_080B3284:
	ldr r1, =gBattleTypeFlags
	movs r0, 0xB
	b _080B32A4
	.pool
_080B3290:
	bl sub_80F94E8
	ldr r1, =gBattleTypeFlags
	movs r0, 0x4B
	b _080B32A4
	.pool
_080B32A0:
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x0000014b
_080B32A4:
	str r0, [r1]
_080B32A6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3260

	thumb_func_start sub_80B32B4
sub_80B32B4: @ 80B32B4
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
	cmp r0, 0x5
	bhi _080B33A0
	lsls r0, 2
	ldr r1, =_080B32E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B32E0:
	.4byte _080B32F8
	.4byte _080B3318
	.4byte _080B3328
	.4byte _080B3338
	.4byte _080B333E
	.4byte _080B3354
_080B32F8:
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002211
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_8009FAC
	b _080B3346
	.pool
_080B3318:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	b _080B3342
	.pool
_080B3328:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080B33A0
	b _080B3346
_080B3338:
	bl sub_800AC34
	b _080B3346
_080B333E:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
_080B3342:
	cmp r0, 0
	bne _080B33A0
_080B3346:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080B33A0
	.pool
_080B3354:
	ldr r0, =gLinkPlayers
	ldr r0, [r0, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B3370
	ldr r0, =0x000001dd
	bl PlayMapChosenOrBattleBGM
	b _080B3378
	.pool
_080B3370:
	movs r0, 0xEE
	lsls r0, 1
	bl PlayMapChosenOrBattleBGM
_080B3378:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl sub_80B3260
	bl overworld_free_bg_tilemaps
	ldr r1, =gTrainerBattleOpponent_A
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =sub_80B360C
	str r0, [r1, 0x8]
	adds r0, r5, 0
	bl DestroyTask
_080B33A0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B32B4

	thumb_func_start sub_80B33BC
sub_80B33BC: @ 80B33BC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x7
	bls _080B33D6
	b _080B3532
_080B33D6:
	lsls r0, 2
	ldr r1, =_080B33E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080B33E8:
	.4byte _080B3408
	.4byte _080B342C
	.4byte _080B3444
	.4byte _080B3458
	.4byte _080B34B0
	.4byte _080B34C4
	.4byte _080B34CE
	.4byte _080B34DE
_080B3408:
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r0, =gUnknown_020229C6
	ldr r2, =0x00002211
	adds r1, r2, 0
	strh r1, [r0]
	bl sub_8009FAC
	movs r0, 0x1
	strh r0, [r6]
	b _080B3532
	.pool
_080B342C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080B343A
	b _080B3532
_080B343A:
	movs r0, 0x2
	strh r0, [r6]
	b _080B3532
	.pool
_080B3444:
	ldr r1, =gUnknown_020229CC
	movs r0, 0
	movs r2, 0x1C
	bl SendBlock
	movs r0, 0x3
	strh r0, [r6]
	b _080B3532
	.pool
_080B3458:
	bl GetBlockReceivedStatus
	adds r4, r0, 0
	bl sub_800A9D8
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080B3532
	movs r4, 0
	ldr r5, =gLinkPlayers
	b _080B349A
	.pool
_080B3474:
	lsls r1, r4, 8
	ldr r2, =gBlockRecvBuffer
	adds r0, r5, 0
	adds r1, r2
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r5, 0
	bl sub_800B524
	lsls r0, r4, 24
	lsrs r0, 24
	bl ResetBlockReceivedFlag
	adds r5, 0x1C
	adds r4, 0x1
_080B349A:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _080B3474
	movs r0, 0x4
	strh r0, [r6]
	b _080B3532
	.pool
_080B34B0:
	ldrh r0, [r6, 0x2]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080B3532
	movs r0, 0x5
	strh r0, [r6]
	b _080B3532
_080B34C4:
	bl sub_800ADF8
	movs r0, 0x6
	strh r0, [r6]
	b _080B3532
_080B34CE:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080B3532
	movs r0, 0x7
	strh r0, [r6]
	b _080B3532
_080B34DE:
	ldr r0, =gLinkPlayers
	ldr r0, [r0, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B34FC
	ldr r0, =0x000001dd
	bl PlayMapChosenOrBattleBGM
	b _080B3504
	.pool
_080B34FC:
	movs r0, 0xEE
	lsls r0, 1
	bl PlayMapChosenOrBattleBGM
_080B3504:
	ldr r1, =gLinkPlayers
	ldr r0, =0x00002211
	str r0, [r1, 0x14]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl sub_80B3260
	bl overworld_free_bg_tilemaps
	ldr r1, =gTrainerBattleOpponent_A
	movs r3, 0x80
	lsls r3, 4
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =sub_80B360C
	str r0, [r1, 0x8]
	adds r0, r4, 0
	bl DestroyTask
_080B3532:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B33BC

	thumb_func_start sub_80B3554
sub_80B3554: @ 80B3554
	push {r4,lr}
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080B35E0
	cmp r0, 0x1
	bgt _080B3574
	cmp r0, 0
	beq _080B357A
	b _080B35FE
	.pool
_080B3574:
	cmp r0, 0x2
	beq _080B35F8
	b _080B35FE
_080B357A:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r3, r0, 24
	movs r4, 0
	movs r2, 0
	cmp r4, r3
	bge _080B35AC
	ldr r1, =gLinkPlayers
	ldrb r0, [r1]
	subs r0, 0x4
	cmp r0, 0x1
	bls _080B35B0
_080B3594:
	adds r2, 0x1
	cmp r2, r3
	bge _080B35AC
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x4
	cmp r0, 0x1
	bhi _080B3594
	movs r4, 0x1
_080B35AC:
	cmp r4, 0
	beq _080B35C8
_080B35B0:
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	b _080B35FE
	.pool
_080B35C8:
	bl sub_800AC34
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _080B35FE
	.pool
_080B35E0:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B35FE
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	b _080B35FE
	.pool
_080B35F8:
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
_080B35FE:
	bl RunTasks
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3554

	thumb_func_start sub_80B360C
sub_80B360C: @ 80B360C
	push {r4,r5,lr}
	ldr r2, =gBattleTypeFlags
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	bl call_ResetMapMusic
	bl copy_player_party_from_sav1
	bl copy_bags_and_unk_data_to_save_blocks
	bl sub_813BF10
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080B36B2
	ldr r0, =gUnknown_03005DB4
	ldrb r0, [r0]
	movs r5, 0x1
	eors r0, r5
	bl sub_813C2A0
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B36B2
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080B3670
	cmp r0, 0x2
	beq _080B3694
	b _080B36B2
	.pool
_080B3670:
	ldr r4, =gLinkPlayers
	bl GetMultiplayerId
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r4, 0x4
	adds r1, r4
	ldr r1, [r1]
	movs r0, 0
	bl sub_801B990
	b _080B36B2
	.pool
_080B3694:
	ldr r4, =gLinkPlayers
	bl GetMultiplayerId
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r4, 0x4
	adds r1, r4
	ldr r1, [r1]
	movs r0, 0x1
	bl sub_801B990
_080B36B2:
	bl InUnionRoom
	cmp r0, 0x1
	bne _080B36CC
	ldr r1, =gMain
	ldr r0, =sub_80B3554
	b _080B36D0
	.pool
_080B36CC:
	ldr r1, =gMain
	ldr r0, =c2_8056854
_080B36D0:
	str r0, [r1, 0x8]
	ldr r0, =sub_80A0514
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B360C

	thumb_func_start sub_80B36EC
sub_80B36EC: @ 80B36EC
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080B3706
	adds r0, r1, 0
	cmp r0, 0x5
	beq _080B3706
	cmp r0, 0x9
	bne _080B370E
_080B3706:
	bl copy_player_party_from_sav1
	bl copy_bags_and_unk_data_to_save_blocks
_080B370E:
	movs r0, 0x7F
	bl copy_saved_warp2_bank_and_enter_x_to_warp1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B36EC

	thumb_func_start sub_80B371C
sub_80B371C: @ 80B371C
	push {lr}
	bl sub_80872B0
	pop {r0}
	bx r0
	thumb_func_end sub_80B371C

	thumb_func_start sub_80B3728
sub_80B3728: @ 80B3728
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080B376C
	cmp r0, 0x1
	bgt _080B3750
	cmp r0, 0
	beq _080B375A
	b _080B37CC
	.pool
_080B3750:
	cmp r0, 0x2
	beq _080B378C
	cmp r0, 0x3
	beq _080B37B8
	b _080B37CC
_080B375A:
	ldr r0, =gUnknown_08278091
	bl ShowFieldMessage
	movs r0, 0x1
	strh r0, [r5, 0x8]
	b _080B37CC
	.pool
_080B376C:
	bl sub_809833C
	lsls r0, 24
	cmp r0, 0
	beq _080B37CC
	bl sub_8087288
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
	bl sub_8009628
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080B37CC
	.pool
_080B378C:
	bl sub_8087214
	cmp r0, 0x1
	beq _080B379E
	cmp r0, 0x1
	bcc _080B37CC
	cmp r0, 0x2
	beq _080B37B2
	b _080B37CC
_080B379E:
	bl textbox_close
	movs r0, 0
	strh r0, [r5, 0x8]
	bl sub_80872C4
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
	b _080B37CC
_080B37B2:
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080B37CC
_080B37B8:
	bl sub_808729C
	movs r0, 0x1
	bl sub_8197AE8
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_080B37CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B3728

	thumb_func_start sub_80B37D4
sub_80B37D4: @ 80B37D4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =sub_80B3728
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl SetTaskFuncWithFollowupFunc
	bl ScriptContext1_Stop
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B37D4

	thumb_func_start sub_80B37FC
sub_80B37FC: @ 80B37FC
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
	beq _080B3840
	cmp r0, 0x1
	bgt _080B3824
	cmp r0, 0
	beq _080B382E
	b _080B3884
	.pool
_080B3824:
	cmp r0, 0x2
	beq _080B3854
	cmp r0, 0x3
	beq _080B3870
	b _080B3884
_080B382E:
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	bl sub_8009FAC
	b _080B3864
_080B3840:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B3884
	b _080B3864
	.pool
_080B3854:
	ldr r1, =gUnknown_02032298
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bl m4aMPlayAllStop
	bl sub_800AC34
_080B3864:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080B3884
	.pool
_080B3870:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B3884
	ldr r0, =sub_80773AC
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_080B3884:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B37FC

	thumb_func_start sub_80B3894
sub_80B3894: @ 80B3894
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
	cmp r0, 0x1
	beq _080B38D8
	cmp r0, 0x1
	bgt _080B38BC
	cmp r0, 0
	beq _080B38C6
	b _080B391C
	.pool
_080B38BC:
	cmp r0, 0x2
	beq _080B38EC
	cmp r0, 0x3
	beq _080B3908
	b _080B391C
_080B38C6:
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	bl Rfu_set_zero
	b _080B38FC
_080B38D8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B391C
	b _080B38FC
	.pool
_080B38EC:
	ldr r1, =gUnknown_02032298
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bl m4aMPlayAllStop
	bl sub_800ADF8
_080B38FC:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080B391C
	.pool
_080B3908:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _080B391C
	bl sub_8013F78
	adds r0, r5, 0
	bl DestroyTask
_080B391C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B3894

	thumb_func_start sub_80B3924
sub_80B3924: @ 80B3924
	push {lr}
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B3940
	ldr r0, =sub_80B3894
	bl sub_80B37D4
	b _080B3946
	.pool
_080B3940:
	ldr r0, =sub_80B37FC
	bl sub_80B37D4
_080B3946:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3924

	thumb_func_start sub_80B3950
sub_80B3950: @ 80B3950
	push {lr}
	ldr r0, =sub_80B37FC
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3950

	thumb_func_start nullsub_37
nullsub_37: @ 80B3964
	bx lr
	thumb_func_end nullsub_37

	thumb_func_start sub_80B3968
sub_80B3968: @ 80B3968
	push {lr}
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002211
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B3994
	ldr r0, =sub_80B33BC
	bl sub_80B37D4
	b _080B399A
	.pool
_080B3994:
	ldr r0, =sub_80B32B4
	bl sub_80B37D4
_080B399A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3968

	thumb_func_start sub_80B39A4
sub_80B39A4: @ 80B39A4
	push {lr}
	ldr r0, =sub_80B3728
	movs r1, 0x50
	bl CreateTask
	bl ScriptContext1_Stop
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B39A4

	thumb_func_start sp02A_crash_sound
sp02A_crash_sound: @ 80B39BC
	push {lr}
	ldr r0, =gSpecialVar_0x8006
	ldrb r0, [r0]
	ldr r1, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl sub_80C4E74
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp02A_crash_sound

	thumb_func_start sub_80B39D4
sub_80B39D4: @ 80B39D4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSpecialVar_0x8006
	strh r4, [r0]
	ldr r0, =gStringVar1
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	ldr r2, =gLinkPlayers + 8
	adds r1, r2
	bl StringCopy
	adds r0, r4, 0
	bl sub_80C4904
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080B3A28
	ldr r0, =gStringVar2
	ldr r2, =gUnknown_0855059C
	subs r1, 0x1
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	movs r0, 0x1
	b _080B3A2A
	.pool
_080B3A28:
	movs r0, 0
_080B3A2A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B39D4

	thumb_func_start task00_08081A90
task00_08081A90: @ 80B3A30
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	movs r0, 0x96
	lsls r0, 17
	cmp r1, r0
	ble _080B3A62
	bl sub_80097E8
	ldr r0, =c2_800ACD4
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_080B3A62:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B3AA6
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B3AA0
	bl sub_800AA60
	lsls r0, 24
	cmp r0, 0
	bne _080B3A86
	bl sub_80097E8
	ldr r0, =c2_800ACD4
	bl SetMainCallback2
_080B3A86:
	adds r0, r4, 0
	bl DestroyTask
	b _080B3AA6
	.pool
_080B3AA0:
	adds r0, r5, 0
	bl DestroyTask
_080B3AA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task00_08081A90

	thumb_func_start sub_80B3AAC
sub_80B3AAC: @ 80B3AAC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B3AC4
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_080B3AC4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3AAC

	thumb_func_start sub_80B3AD0
sub_80B3AD0: @ 80B3AD0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_800AC34
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80B3AAC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3AD0

	thumb_func_start sub_80B3AF8
sub_80B3AF8: @ 80B3AF8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080B3B54
	cmp r0, 0x1
	bgt _080B3B20
	cmp r0, 0
	beq _080B3B2A
	b _080B3BB8
	.pool
_080B3B20:
	cmp r0, 0x2
	beq _080B3B68
	cmp r0, 0x3
	beq _080B3B9E
	b _080B3BB8
_080B3B2A:
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B3B40
	adds r0, r4, 0
	bl DestroyTask
	b _080B3BB8
	.pool
_080B3B40:
	bl sub_8009734
	ldr r0, =task00_08081A90
	movs r1, 0x1
	bl CreateTask
	b _080B3B96
	.pool
_080B3B54:
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _080B3BB8
	movs r0, 0
	strh r0, [r5, 0x2]
	b _080B3B96
_080B3B68:
	bl sub_800ABAC
	adds r4, r0, 0
	bl sub_800AA48
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bcc _080B3BB8
	bl sub_800ABBC
	lsls r0, 24
	cmp r0, 0
	beq _080B3B96
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _080B3BB8
	bl sub_800A620
_080B3B96:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _080B3BB8
_080B3B9E:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080B3BB8
	bl sub_800A23C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B3BB8
	adds r0, r4, 0
	bl DestroyTask
_080B3BB8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3AF8

	thumb_func_start sub_80B3BC4
sub_80B3BC4: @ 80B3BC4
	push {lr}
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080B3BD6
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00002288
	adds r0, r2, 0
	strh r0, [r1]
_080B3BD6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B3BC4

	.align 2, 0 @ Don't pad with nop.
