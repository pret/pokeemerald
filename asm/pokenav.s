	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
	


	thumb_func_start sub_81C7078
sub_81C7078: @ 81C7078
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _081C7090
	ldr r0, =sub_81C7170
	b _081C7092
	.pool
_081C7090:
	ldr r0, =sub_81C71E4
_081C7092:
	lsls r1, r4, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =gUnknown_0203CF3C
	ldrb r1, [r2]
	strh r1, [r0, 0xE]
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	lsls r0, 24
	lsrs r0, 8
	orrs r0, r4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7078

	thumb_func_start sub_81C70D8
sub_81C70D8: @ 81C70D8
	push {lr}
	ldr r1, =0x0000ffff
	ands r1, r0
	lsrs r3, r0, 16
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _081C711C
	ldr r2, [r1]
	ldr r0, =sub_81C7170
	cmp r2, r0
	beq _081C70FE
	ldr r0, =sub_81C71E4
	cmp r2, r0
	bne _081C711C
_081C70FE:
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, r3
	bne _081C711C
	movs r0, 0x1
	b _081C711E
	.pool
_081C711C:
	movs r0, 0
_081C711E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C70D8

	thumb_func_start sub_81C7124
sub_81C7124: @ 81C7124
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gTasks
_081C712C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _081C7160
	ldr r1, [r4]
	ldr r0, =sub_81C7170
	cmp r1, r0
	beq _081C7140
	ldr r0, =sub_81C71E4
	cmp r1, r0
	bne _081C7160
_081C7140:
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x1
	bl GetWordTaskArg
	cmp r0, r6
	bne _081C7160
	movs r0, 0x1
	b _081C716A
	.pool
_081C7160:
	adds r4, 0x28
	adds r5, 0x1
	cmp r5, 0xF
	ble _081C712C
	movs r0, 0
_081C716A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7124

	thumb_func_start sub_81C7170
sub_81C7170: @ 81C7170
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r6, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r7, 0
_081C718C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r6
	cmp r0, 0x4
	bhi _081C71D6
	lsls r0, 2
	ldr r1, =_081C71AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C71AC:
	.4byte _081C71C6
	.4byte _081C71C0
	.4byte _081C71DE
	.4byte _081C71DA
	.4byte _081C71CE
_081C71C0:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C71D8
_081C71C6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081C71DE
_081C71CE:
	adds r0, r5, 0
	bl DestroyTask
	b _081C71DE
_081C71D6:
	subs r0, 0x5
_081C71D8:
	strh r0, [r4]
_081C71DA:
	cmp r7, 0
	beq _081C718C
_081C71DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7170

	thumb_func_start sub_81C71E4
sub_81C71E4: @ 81C71E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8087598
	cmp r0, 0
	bne _081C724A
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r2, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r2
	cmp r0, 0x4
	bhi _081C7246
	lsls r0, 2
	ldr r1, =_081C7224
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7224:
	.4byte _081C7238
	.4byte _081C7238
	.4byte _081C724A
	.4byte _081C724A
	.4byte _081C723E
_081C7238:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C7248
_081C723E:
	adds r0, r5, 0
	bl DestroyTask
	b _081C724A
_081C7246:
	subs r0, 0x5
_081C7248:
	strh r0, [r4]
_081C724A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C71E4

	thumb_func_start CB2_PokeNav
CB2_PokeNav: @ 81C7250
	push {r4,lr}
	ldr r4, =gUnknown_0203CF40
	movs r0, 0x5C
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081C7270
	ldr r0, =CB2_ReturnToFieldWithOpenMenu
	bl SetMainCallback2
	b _081C7292
	.pool
_081C7270:
	bl sub_81C7360
	bl ResetTasks
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81C742C
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81C7400
	bl SetMainCallback2
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
_081C7292:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_PokeNav

	thumb_func_start sub_81C72A4
sub_81C72A4: @ 81C72A4
	push {lr}
	ldr r0, =sub_81C72BC
	bl SetMainCallback2
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C72A4

	thumb_func_start sub_81C72BC
sub_81C72BC: @ 81C72BC
	push {r4,lr}
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C7320
	ldr r4, =gUnknown_0203CF40
	movs r0, 0x5C
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081C72F0
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	b _081C7320
	.pool
_081C72F0:
	bl sub_81C7360
	ldr r1, [r4]
	movs r0, 0x1
	strh r0, [r1, 0x8]
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81C742C
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81C7400
	bl SetMainCallback2
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
_081C7320:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C72BC

	thumb_func_start sub_81C7334
sub_81C7334: @ 81C7334
	push {r4,lr}
	movs r4, 0
_081C7338:
	adds r0, r4, 0
	bl sub_81C7650
	adds r4, 0x1
	cmp r4, 0x12
	ble _081C7338
	ldr r4, =gUnknown_0203CF40
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl InitKeys
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7334

	thumb_func_start sub_81C7360
sub_81C7360: @ 81C7360
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r2, 0
	movs r1, 0x12
	adds r0, 0x58
_081C736A:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _081C736A
	movs r4, 0
	strh r4, [r5, 0x8]
	str r4, [r5, 0x4]
	bl sub_81C7388
	str r0, [r5, 0xC]
	str r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7360

	thumb_func_start sub_81C7388
sub_81C7388: @ 81C7388
	push {r4-r6,lr}
	movs r5, 0
_081C738C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081C73BA
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081C73BA
	adds r0, r4, 0
	movs r1, 0x52
	bl GetMonData
	cmp r0, 0
	bne _081C73E2
_081C73BA:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081C738C
	movs r4, 0
_081C73C2:
	movs r5, 0
	lsls r6, r4, 24
_081C73C6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081C73EC
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	movs r2, 0x52
	bl GetBoxMonDataAt
	cmp r0, 0
	beq _081C73EC
_081C73E2:
	movs r0, 0x1
	b _081C73FA
	.pool
_081C73EC:
	adds r5, 0x1
	cmp r5, 0x1D
	ble _081C73C6
	adds r4, 0x1
	cmp r4, 0xD
	ble _081C73C2
	movs r0, 0
_081C73FA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7388

	thumb_func_start sub_81C7400
sub_81C7400: @ 81C7400
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81C7400

	thumb_func_start sub_81C7418
sub_81C7418: @ 81C7418
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	thumb_func_end sub_81C7418

	thumb_func_start sub_81C742C
sub_81C742C: @ 81C742C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r7, r1, r0
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x5
	bls _081C7446
	b _081C7562
_081C7446:
	lsls r0, 2
	ldr r1, =_081C7458
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7458:
	.4byte _081C7470
	.4byte _081C747A
	.4byte _081C7490
	.4byte _081C749C
	.4byte _081C751E
	.4byte _081C752C
_081C7470:
	bl sub_81C76C4
	movs r0, 0x1
	strh r0, [r7]
	b _081C7562
_081C747A:
	bl sub_81C76FC
	cmp r0, 0
	bne _081C7562
	ldr r0, =0x000186a0
	bl sub_81C756C
	b _081C74E8
	.pool
_081C7490:
	bl sub_81C786C
	cmp r0, 0
	bne _081C7562
	movs r0, 0x3
	strh r0, [r7]
_081C749C:
	bl sub_81C75E0
	adds r6, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _081C74FC
	ldr r0, =0x0001869f
	cmp r6, r0
	bls _081C7506
	ldr r4, =gUnknown_0861F3EC
	ldr r5, =gUnknown_0203CF40
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r4, 0x14
	adds r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	adds r0, r6, 0
	bl sub_81C756C
	cmp r0, 0
	beq _081C74FC
_081C74E8:
	movs r0, 0x4
	strh r0, [r7]
	b _081C7562
	.pool
_081C74FC:
	bl sub_81C7710
	movs r0, 0x5
	strh r0, [r7]
	b _081C7562
_081C7506:
	cmp r6, 0
	beq _081C7562
	adds r0, r6, 0
	bl sub_81C7850
	bl sub_81C786C
	cmp r0, 0
	beq _081C7562
	movs r0, 0x2
	strh r0, [r7]
	b _081C7562
_081C751E:
	bl sub_81C75D4
	cmp r0, 0
	bne _081C7562
	movs r0, 0x3
	strh r0, [r7]
	b _081C7562
_081C752C:
	bl sub_81C7738
	cmp r0, 0
	bne _081C7562
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_81C9430
	bl sub_81C7334
	cmp r4, 0
	beq _081C755C
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	b _081C7562
	.pool
_081C755C:
	ldr r0, =CB2_ReturnToFieldWithOpenMenu
	bl SetMainCallback2
_081C7562:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C742C

	thumb_func_start sub_81C756C
sub_81C756C: @ 81C756C
	push {r4-r6,lr}
	ldr r1, =0xfffe7960
	adds r6, r0, r1
	bl sub_81C75F4
	ldr r5, =gUnknown_0861F3EC
	lsls r0, r6, 3
	subs r0, r6
	lsls r4, r0, 2
	adds r0, r4, r5
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, 0
	beq _081C75CC
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, 0
	beq _081C75CC
	adds r0, r5, 0
	adds r0, 0xC
	adds r0, r4, r0
	ldr r0, [r0]
	adds r1, r5, 0
	adds r1, 0x10
	adds r1, r4, r1
	ldr r1, [r1]
	bl sub_81C7834
	ldr r0, =gUnknown_0203CF40
	ldr r1, [r0]
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1]
	str r6, [r1, 0x4]
	movs r0, 0x1
	b _081C75CE
	.pool
_081C75CC:
	movs r0, 0
_081C75CE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C756C

	thumb_func_start sub_81C75D4
sub_81C75D4: @ 81C75D4
	push {lr}
	bl sub_81C786C
	pop {r1}
	bx r1
	thumb_func_end sub_81C75D4

	thumb_func_start sub_81C75E0
sub_81C75E0: @ 81C75E0
	push {lr}
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C75E0

	thumb_func_start sub_81C75F4
sub_81C75F4: @ 81C75F4
	push {lr}
	bl InitKeys
	pop {r0}
	bx r0
	thumb_func_end sub_81C75F4

	thumb_func_start c3args_set_0toR1_1to0
c3args_set_0toR1_1to0: @ 81C7600
	push {lr}
	bl SetVBlankCallback
	pop {r0}
	bx r0
	thumb_func_end c3args_set_0toR1_1to0

	thumb_func_start sub_81C760C
sub_81C760C: @ 81C760C
	push {lr}
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C760C

	thumb_func_start sub_81C761C
sub_81C761C: @ 81C761C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl Alloc
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x10
	adds r1, r4
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C761C

	thumb_func_start sub_81C763C
sub_81C763C: @ 81C763C
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	lsls r0, 2
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C763C

	thumb_func_start sub_81C7650
sub_81C7650: @ 81C7650
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203CF40
	ldr r1, [r5]
	lsls r4, r0, 2
	adds r1, 0x10
	adds r1, r4
	ldr r0, [r1]
	cmp r0, 0
	beq _081C7670
	bl Free
	ldr r0, [r5]
	adds r0, 0x10
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_081C7670:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7650

	thumb_func_start sub_81C767C
sub_81C767C: @ 81C767C
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C767C

	thumb_func_start sub_81C7688
sub_81C7688: @ 81C7688
	ldr r1, =gUnknown_0203CF40
	ldr r1, [r1]
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C7688

	thumb_func_start sub_81C7694
sub_81C7694: @ 81C7694
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x4
	bls _081C769E
	movs r1, 0
_081C769E:
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	strh r1, [r0, 0xA]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7694

	thumb_func_start sub_81C76AC
sub_81C76AC: @ 81C76AC
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	bx lr
	.pool
	thumb_func_end sub_81C76AC

	thumb_func_start sub_81C76B8
sub_81C76B8: @ 81C76B8
	ldr r0, =gUnknown_0203CF40
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C76B8

	thumb_func_start sub_81C76C4
sub_81C76C4: @ 81C76C4
	push {r4,lr}
	ldr r1, =0x0000082c
	movs r0, 0
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C76F4
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =sub_81C7764
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C76F6
	.pool
_081C76F4:
	movs r0, 0
_081C76F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C76C4

	thumb_func_start sub_81C76FC
sub_81C76FC: @ 81C76FC
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C76FC

	thumb_func_start sub_81C7710
sub_81C7710: @ 81C7710
	push {lr}
	sub sp, 0x4
	movs r0, 0x6F
	bl PlaySE
	bl sub_81CAADC
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_81C7710

	thumb_func_start sub_81C7738
sub_81C7738: @ 81C7738
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C7750
	movs r0, 0x1
	b _081C775E
	.pool
_081C7750:
	bl sub_81C99D4
	bl sub_81C7C94
	bl FreeAllWindowBuffers
	movs r0, 0
_081C775E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C7738

	thumb_func_start sub_81C7764
sub_81C7764: @ 81C7764
	push {r4,lr}
	sub sp, 0x4
	cmp r0, 0x1
	beq _081C77B0
	cmp r0, 0x1
	bgt _081C7776
	cmp r0, 0
	beq _081C7780
	b _081C782A
_081C7776:
	cmp r0, 0x2
	beq _081C77FC
	cmp r0, 0x3
	beq _081C780E
	b _081C782A
_081C7780:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	bl FreeAllWindowBuffers
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0861FA04
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	bl sub_8199D98
	bl reset_temp_tile_data_buffers
	movs r0, 0x1
	b _081C782C
	.pool
_081C77B0:
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r1, =gPokenavHeader_Gfx
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r4, 0x2C
	movs r0, 0
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	ldr r1, =gPokenavHeader_Tilemap
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gPokenavHeader_Pal
	movs r1, 0
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081C782C
	.pool
_081C77FC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081C7818
	bl sub_81C7B74
	movs r0, 0
	b _081C782C
_081C780E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C781C
_081C7818:
	movs r0, 0x2
	b _081C782C
_081C781C:
	bl sub_81C7C28
	bl sub_81C7D28
	movs r0, 0
	bl ShowBg
_081C782A:
	movs r0, 0x4
_081C782C:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7764

	thumb_func_start sub_81C7834
sub_81C7834: @ 81C7834
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	bl sub_81C763C
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r1, 0
	str r1, [r0, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7834

	thumb_func_start sub_81C7850
sub_81C7850: @ 81C7850
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x8]
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7850

	thumb_func_start sub_81C786C
sub_81C786C: @ 81C786C
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81C786C

	thumb_func_start sub_81C7880
sub_81C7880: @ 81C7880
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =atk47_cmd47
	movs r1, 0x4
	bl sub_81C7078
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7880

	thumb_func_start sub_81C78A0
sub_81C78A0: @ 81C78A0
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =sub_81C791C
	movs r1, 0x4
	bl sub_81C7078
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C78A0

	thumb_func_start sub_81C78C0
sub_81C78C0: @ 81C78C0
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C78C0

	thumb_func_start atk47_cmd47
atk47_cmd47: @ 81C78D4
	push {lr}
	cmp r0, 0x1
	beq _081C78EA
	cmp r0, 0x1
	bgt _081C78E4
	cmp r0, 0
	beq _081C78EA
	b _081C7914
_081C78E4:
	cmp r0, 0x2
	beq _081C78EE
	b _081C7914
_081C78EA:
	movs r0, 0
	b _081C7916
_081C78EE:
	movs r1, 0xC0
	lsls r1, 1
	movs r0, 0
	movs r2, 0x1
	bl ChangeBgY
	ldr r1, =0x00001fff
	cmp r0, r1
	bhi _081C7908
	movs r0, 0x2
	b _081C7916
	.pool
_081C7908:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
_081C7914:
	movs r0, 0x4
_081C7916:
	pop {r1}
	bx r1
	thumb_func_end atk47_cmd47

	thumb_func_start sub_81C791C
sub_81C791C: @ 81C791C
	push {lr}
	movs r1, 0xC0
	lsls r1, 1
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	cmp r0, 0
	ble _081C7932
	movs r0, 0x2
	b _081C793E
_081C7932:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x4
_081C793E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C791C

	thumb_func_start sub_81C7944
sub_81C7944: @ 81C7944
	push {lr}
	lsls r1, 1
	ldr r3, =gPlttBufferUnfaded
	adds r1, r3
	lsls r2, 10
	lsrs r2, 11
	bl CpuSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7944

	thumb_func_start sub_81C795C
sub_81C795C: @ 81C795C
	push {r4,lr}
	adds r4, r0, 0
	b _081C7974
_081C7962:
	lsls r0, r1, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r0, r2
	ldr r0, [r4]
	movs r2, 0x20
	bl sub_81C7944
	adds r4, 0x8
_081C7974:
	ldr r0, [r4]
	cmp r0, 0
	beq _081C7988
	ldrh r0, [r4, 0x4]
	bl AllocSpritePalette
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	bne _081C7962
_081C7988:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C795C

	thumb_func_start sub_81C7990
sub_81C7990: @ 81C7990
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	strh r1, [r0]
	lsls r3, 5
	ldr r0, =gPlttBufferFaded + 0x200
	adds r3, r0
	ldr r2, =0x01000010
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7990

	thumb_func_start sub_81C79BC
sub_81C79BC: @ 81C79BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r10, r2
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x2C]
	cmp r0, 0
	bne _081C79E4
	ldr r2, =0x001fffff
	mov r1, r10
	ands r2, r1
	ldr r0, [sp]
	b _081C79F4
	.pool
_081C79E4:
	ldr r2, [sp, 0x2C]
	ldr r0, [sp, 0x8]
	cmp r2, r0
	blt _081C7A00
	ldr r2, =0x001fffff
	mov r1, r10
	ands r2, r1
	ldr r0, [sp, 0x4]
_081C79F4:
	ldr r1, [sp, 0x30]
	bl CpuSet
	b _081C7AAE
	.pool
_081C7A00:
	movs r2, 0x1
	negs r2, r2
	add r10, r2
	b _081C7AA6
_081C7A08:
	ldr r1, [sp]
	ldrh r0, [r1]
	movs r2, 0x1F
	mov r9, r2
	mov r1, r9
	ands r1, r0
	mov r9, r1
	lsls r0, 16
	lsrs r2, r0, 21
	movs r1, 0x1F
	ands r1, r2
	mov r8, r1
	lsrs r7, r0, 26
	movs r2, 0x1F
	ands r7, r2
	ldr r0, [sp, 0x4]
	ldrh r4, [r0]
	movs r0, 0x1F
	ands r0, r4
	mov r1, r9
	subs r0, r1
	lsls r0, 8
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r2, [sp, 0x2C]
	adds r6, r0, 0
	muls r6, r2
	asrs r6, 8
	lsls r4, 16
	lsrs r0, r4, 21
	movs r1, 0x1F
	ands r0, r1
	mov r2, r8
	subs r0, r2
	lsls r0, 8
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r1, [sp, 0x2C]
	adds r5, r0, 0
	muls r5, r1
	asrs r5, 8
	lsrs r4, 26
	movs r2, 0x1F
	ands r4, r2
	subs r4, r7
	lsls r4, 8
	adds r0, r4, 0
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r1, [sp, 0x2C]
	muls r0, r1
	asrs r0, 8
	add r6, r9
	movs r2, 0x1F
	ands r6, r2
	add r5, r8
	ands r5, r2
	adds r0, r7, r0
	ands r0, r2
	lsls r0, 10
	lsls r5, 5
	orrs r0, r5
	orrs r0, r6
	ldr r1, [sp, 0x30]
	strh r0, [r1]
	ldr r2, [sp]
	adds r2, 0x2
	str r2, [sp]
	ldr r0, [sp, 0x4]
	adds r0, 0x2
	str r0, [sp, 0x4]
	adds r1, 0x2
	str r1, [sp, 0x30]
	movs r1, 0x1
	negs r1, r1
	add r10, r1
_081C7AA6:
	movs r0, 0x1
	negs r0, r0
	cmp r10, r0
	bne _081C7A08
_081C7AAE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C79BC

	thumb_func_start sub_81C7AC0
sub_81C7AC0: @ 81C7AC0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0x1
	beq _081C7AF0
	cmp r4, 0x1
	bgt _081C7ADA
	cmp r4, 0
	beq _081C7AE4
	b _081C7B2C
_081C7ADA:
	cmp r4, 0x2
	beq _081C7B04
	cmp r4, 0x3
	beq _081C7B18
	b _081C7B2C
_081C7AE4:
	ldr r0, [r0, 0x14]
	movs r1, 0x2
	negs r1, r1
	str r4, [sp]
	movs r2, 0
	b _081C7B10
_081C7AF0:
	ldr r0, [r0, 0x14]
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _081C7B2C
_081C7B04:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
_081C7B10:
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _081C7B2C
_081C7B18:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x2
	negs r1, r1
	movs r2, 0
	str r2, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_081C7B2C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7AC0

	thumb_func_start sub_81C7B34
sub_81C7B34: @ 81C7B34
	ldr r0, =gPaletteFade
	ldrb r0, [r0, 0x7]
	lsrs r0, 7
	bx lr
	.pool
	thumb_func_end sub_81C7B34

	thumb_func_start sub_81C7B40
sub_81C7B40: @ 81C7B40
	push {lr}
	ldr r0, =0xfffefffe
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7B40

	thumb_func_start sub_81C7B54
sub_81C7B54: @ 81C7B54
	push {r4,r5,lr}
	adds r5, r0, 0
	cmp r1, 0
	ble _081C7B6C
	adds r4, r1, 0
_081C7B5E:
	adds r0, r5, 0
	adds r5, 0x4
	bl InitBgFromTemplate
	subs r4, 0x1
	cmp r4, 0
	bne _081C7B5E
_081C7B6C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7B54

	thumb_func_start sub_81C7B74
sub_81C7B74: @ 81C7B74
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_0861FA08
	bl InitWindows
	movs r0, 0
	str r0, [r4, 0x10]
	bl sub_81C7BF8
	ldrb r0, [r4, 0x10]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x10]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7B74

	thumb_func_start sub_81C7BA4
sub_81C7BA4: @ 81C7BA4
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, [r5, 0x10]
	bl sub_81C7BF8
	ldrb r0, [r5, 0x10]
	ldr r1, =gUnknown_0861FA48
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_0861FA18
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7BA4

	thumb_func_start sub_81C7BE8
sub_81C7BE8: @ 81C7BE8
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81C7BE8

	thumb_func_start sub_81C7BF8
sub_81C7BF8: @ 81C7BF8
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x44
	bl FillWindowPixelBuffer
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x55
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7BF8

	thumb_func_start sub_81C7C28
sub_81C7C28: @ 81C7C28
	push {r4-r6,lr}
	movs r0, 0
	bl sub_81C763C
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gUnknown_0861FA4C
_081C7C36:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081C7C36
	ldr r0, =gUnknown_0861FA54
	bl sub_81C795C
	movs r0, 0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	movs r0, 0x2
	negs r0, r0
	bics r0, r1
	str r0, [r6, 0x14]
	ldr r0, =gUnknown_0861FB04
	movs r1, 0xDC
	movs r2, 0xC
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r6, 0x18]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7C28

	thumb_func_start sub_81C7C94
sub_81C7C94: @ 81C7C94
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	bl DestroySprite
	movs r0, 0
	bl FreeSpriteTilesByTag
	movs r0, 0
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81C7C94

	thumb_func_start sub_81C7CB4
sub_81C7CB4: @ 81C7CB4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl GetBgY
	lsrs r0, 8
	negs r0, r0
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7CB4

	thumb_func_start sub_81C7CCC
sub_81C7CCC: @ 81C7CCC
	push {lr}
	movs r0, 0
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	ldr r1, =SpriteCallbackDummy
	str r1, [r0, 0x1C]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7CCC

	thumb_func_start sub_81C7CE4
sub_81C7CE4: @ 81C7CE4
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	ldr r2, [r0, 0x18]
	movs r4, 0
	movs r1, 0xDC
	strh r1, [r2, 0x20]
	ldr r2, [r0, 0x18]
	movs r1, 0xC
	strh r1, [r2, 0x22]
	ldr r2, [r0, 0x18]
	ldr r1, =sub_81C7CB4
	str r1, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	strb r1, [r2]
	ldr r3, [r0, 0x18]
	ldrb r2, [r3, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r3, 0x5]
	ldr r0, [r0, 0x18]
	adds r0, 0x43
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7CE4

	thumb_func_start sub_81C7D28
sub_81C7D28: @ 81C7D28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, =gUnknown_0861FA64
	bl LoadCompressedSpriteSheet
	movs r0, 0x1
	bl AllocSpritePalette
	movs r0, 0x2
	bl AllocSpritePalette
	movs r5, 0
	ldr r0, =gSprites
	mov r8, r0
	movs r7, 0x4
_081C7D50:
	ldr r0, =gUnknown_0861FB2C
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r4, r5, 2
	adds r2, r6, 0
	adds r2, 0x1C
	adds r2, r4
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r0, [r2]
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldr r1, [r2]
	lsls r0, r5, 6
	strh r0, [r1, 0x24]
	ldr r0, =gUnknown_0861FB44
	movs r1, 0
	movs r2, 0
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r6, 0
	adds r2, 0x24
	adds r2, r4
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	str r0, [r2]
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldr r1, [r2]
	lsls r0, r5, 5
	strh r0, [r1, 0x24]
	ldr r1, [r2]
	movs r0, 0x12
	strh r0, [r1, 0x26]
	ldr r3, [r2]
	ldrh r2, [r3, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	lsls r0, r5, 3
	adds r0, 0x40
	adds r1, r0
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x4]
	adds r5, 0x1
	cmp r5, 0x1
	ble _081C7D50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7D28

	thumb_func_start sub_81C7DFC
sub_81C7DFC: @ 81C7DFC
	push {lr}
	cmp r0, 0x5
	bhi _081C7E08
	bl sub_81C7E58
	b _081C7E0E
_081C7E08:
	subs r0, 0x6
	bl sub_81C7F24
_081C7E0E:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7DFC

	thumb_func_start sub_81C7E14
sub_81C7E14: @ 81C7E14
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x4
	bne _081C7E30
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r5, 0x20]
	adds r0, 0x20
	b _081C7E3A
_081C7E30:
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r5, 0x20]
	adds r0, 0x40
_081C7E3A:
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7E14

	thumb_func_start sub_81C7E58
sub_81C7E58: @ 81C7E58
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	cmp r0, 0x5
	bhi _081C7F16
	movs r0, 0
	bl sub_81C763C
	adds r7, r0, 0
	ldr r0, =gUnknown_0861FA6C
	mov r1, r9
	lsls r6, r1, 3
	adds r6, r0
	ldrh r4, [r6, 0x6]
	ldr r2, [r6]
	mov r8, r2
	mov r0, r8
	bl GetDecompressedDataSize
	adds r5, r0, 0
	lsls r4, 5
	ldr r0, =gPokenavLeftHeader_Pal
	adds r4, r0
	movs r0, 0x1
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r4, =gDecompressionBuffer
	mov r0, r8
	adds r1, r4, 0
	bl LZ77UnCompWram
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 11
	ldr r2, =0x06010000
	adds r1, r2
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	ldr r3, [r7, 0x20]
	ldrh r1, [r6, 0x4]
	adds r0, r1
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	mov r0, r9
	subs r0, 0x4
	cmp r0, 0x1
	bhi _081C7F10
	ldr r1, [r7, 0x20]
	movs r0, 0x38
	b _081C7F14
	.pool
_081C7F10:
	ldr r1, [r7, 0x20]
	movs r0, 0x40
_081C7F14:
	strh r0, [r1, 0x24]
_081C7F16:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7E58

	thumb_func_start sub_81C7F24
sub_81C7F24: @ 81C7F24
	push {r4-r6,lr}
	cmp r0, 0x6
	bhi _081C7F8A
	ldr r2, =gUnknown_0861FA9C
	lsls r1, r0, 3
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r4, [r0]
	adds r1, r2
	ldr r6, [r1]
	adds r0, r6, 0
	bl GetDecompressedDataSize
	adds r5, r0, 0
	lsls r4, 5
	ldr r0, =gPokenavLeftHeader_Pal
	adds r4, r0
	movs r0, 0x2
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r4, =gDecompressionBuffer+0x1000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZ77UnCompWram
	movs r0, 0x2
	bl GetSpriteTileStartByTag
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 11
	ldr r0, =0x06010800
	adds r1, r0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl RequestDma3Copy
_081C7F8A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7F24

	thumb_func_start sub_81C7FA0
sub_81C7FA0: @ 81C7FA0
	push {lr}
	adds r3, r0, 0
	movs r0, 0x10
	cmp r1, 0
	bne _081C7FAC
	movs r0, 0x30
_081C7FAC:
	cmp r3, 0x5
	bhi _081C7FB8
	adds r1, r2, 0
	bl sub_81C803C
	b _081C7FBE
_081C7FB8:
	adds r1, r2, 0
	bl sub_81C8088
_081C7FBE:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FA0

	thumb_func_start sub_81C7FC4
sub_81C7FC4: @ 81C7FC4
	push {lr}
	cmp r0, 0x5
	bhi _081C7FD2
	adds r0, r1, 0
	bl sub_81C80D4
	b _081C7FD8
_081C7FD2:
	adds r0, r1, 0
	bl sub_81C8110
_081C7FD8:
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FC4

	thumb_func_start sub_81C7FDC
sub_81C7FDC: @ 81C7FDC
	push {r4,lr}
	movs r0, 0
	bl sub_81C763C
	movs r4, 0x4
	adds r2, r0, 0
	adds r2, 0x1C
	movs r3, 0x1
_081C7FEC:
	ldr r1, [r2]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	ldr r1, [r2, 0x8]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _081C7FEC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7FDC

	thumb_func_start sub_81C8010
sub_81C8010: @ 81C8010
	push {lr}
	movs r0, 0
	bl sub_81C763C
	adds r1, r0, 0
	ldr r0, [r1, 0x1C]
	ldr r2, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r2, r0
	bne _081C8034
	ldr r0, [r1, 0x24]
	ldr r0, [r0, 0x1C]
	cmp r0, r2
	bne _081C8034
	movs r0, 0
	b _081C8036
	.pool
_081C8034:
	movs r0, 0x1
_081C8036:
	pop {r1}
	bx r1
	thumb_func_end sub_81C8010

	thumb_func_start sub_81C803C
sub_81C803C: @ 81C803C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C8058
	movs r7, 0x60
	negs r7, r7
	movs r6, 0x20
	b _081C805E
_081C8058:
	movs r7, 0x80
	lsls r7, 1
	movs r6, 0xA0
_081C805E:
	adds r4, r0, 0
	adds r4, 0x1C
	movs r5, 0x1
_081C8064:
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x22]
	ldm r4!, {r0}
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r5, 0x1
	cmp r5, 0
	bge _081C8064
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C803C

	thumb_func_start sub_81C8088
sub_81C8088: @ 81C8088
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C80A4
	movs r7, 0x60
	negs r7, r7
	movs r6, 0x10
	b _081C80AA
_081C80A4:
	movs r7, 0x80
	lsls r7, 1
	movs r6, 0xC0
_081C80AA:
	adds r4, r0, 0
	adds r4, 0x24
	movs r5, 0x1
_081C80B0:
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x22]
	ldm r4!, {r0}
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r5, 0x1
	cmp r5, 0
	bge _081C80B0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8088

	thumb_func_start sub_81C80D4
sub_81C80D4: @ 81C80D4
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C80EA
	movs r6, 0x20
	movs r5, 0x60
	negs r5, r5
	b _081C80F0
_081C80EA:
	movs r6, 0xC0
	movs r5, 0x80
	lsls r5, 1
_081C80F0:
	adds r7, r0, 0
	adds r7, 0x1C
	movs r4, 0x1
_081C80F6:
	ldm r7!, {r0}
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r4, 0x1
	cmp r4, 0
	bge _081C80F6
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C80D4

	thumb_func_start sub_81C8110
sub_81C8110: @ 81C8110
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r0, 0
	bl sub_81C763C
	cmp r4, 0
	bne _081C8126
	movs r6, 0x10
	movs r5, 0x60
	negs r5, r5
	b _081C812C
_081C8126:
	movs r6, 0xC0
	movs r5, 0x80
	lsls r5, 1
_081C812C:
	adds r7, r0, 0
	adds r7, 0x24
	movs r4, 0x1
_081C8132:
	ldm r7!, {r0}
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0xC
	bl sub_81C814C
	subs r4, 0x1
	cmp r4, 0
	bge _081C8132
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8110

	thumb_func_start sub_81C814C
sub_81C814C: @ 81C814C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	strh r0, [r4, 0x20]
	lsls r1, r0, 4
	strh r1, [r4, 0x2E]
	subs r0, r6, r0
	lsls r0, 4
	adds r1, r5, 0
	bl __divsi3
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r6, [r4, 0x3C]
	ldr r0, =sub_81C817C
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C814C

	thumb_func_start sub_81C817C
sub_81C817C: @ 81C817C
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x32]
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081C81C4
	subs r0, r1, 0x1
	strh r0, [r2, 0x32]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x2E]
	adds r0, r1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	adds r0, 0x10
	lsls r0, 16
	movs r1, 0x88
	lsls r1, 17
	cmp r0, r1
	bls _081C81B6
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081C81CC
_081C81B6:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _081C81CC
_081C81C4:
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081C81CC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C817C

	thumb_func_start sub_81C81D4
sub_81C81D4: @ 81C81D4
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	ldr r1, =0x000008a4
	movs r0, 0x11
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C821C
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r5, 0
	bl sub_81C9160
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_81C91AC
	cmp r0, 0
	beq _081C821C
	ldr r0, =sub_81C8254
	movs r1, 0x6
	bl sub_81C7078
	movs r0, 0x1
	b _081C821E
	.pool
_081C821C:
	movs r0, 0
_081C821E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C81D4

	thumb_func_start sub_81C8224
sub_81C8224: @ 81C8224
	push {lr}
	ldr r0, =sub_81C8254
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8224

	thumb_func_start sub_81C8234
sub_81C8234: @ 81C8234
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8FE0
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x11
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8234

	thumb_func_start sub_81C8254
sub_81C8254: @ 81C8254
	push {r4,lr}
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C82C0
	movs r0, 0x11
	bl sub_81C763C
	adds r2, r0, 0
	cmp r4, 0x4
	bhi _081C82D6
	lsls r0, r4, 2
	ldr r1, =_081C827C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C827C:
	.4byte _081C8290
	.4byte _081C829A
	.4byte _081C82A4
	.4byte _081C82B8
	.4byte _081C82CC
_081C8290:
	adds r0, r2, 0
	bl sub_81C82E4
	movs r0, 0
	b _081C82D8
_081C829A:
	adds r0, r2, 0
	bl sub_81C835C
	movs r0, 0
	b _081C82D8
_081C82A4:
	ldr r1, =0x00000888
	adds r0, r2, r1
	adds r1, r2, 0
	bl sub_81C837C
	movs r0, 0
	b _081C82D8
	.pool
_081C82B8:
	bl sub_81C83E0
	cmp r0, 0
	beq _081C82C4
_081C82C0:
	movs r0, 0x2
	b _081C82D8
_081C82C4:
	bl sub_81C8ED0
	movs r0, 0x1
	b _081C82D8
_081C82CC:
	ldr r1, =0x00000888
	adds r0, r2, r1
	adds r1, r2, 0
	bl sub_81C8EF8
_081C82D6:
	movs r0, 0x4
_081C82D8:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8254

	thumb_func_start sub_81C82E4
sub_81C82E4: @ 81C82E4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldrb r4, [r5, 0x1]
	lsls r4, 12
	ldrh r0, [r5, 0x6]
	orrs r4, r0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	ldrh r2, [r5, 0x6]
	movs r1, 0x11
	movs r3, 0x1
	bl sub_8199DF0
	ldrb r0, [r5]
	ldrh r2, [r5, 0x6]
	adds r2, 0x1
	movs r1, 0x44
	movs r3, 0x1
	bl sub_8199DF0
	ldrb r0, [r5]
	adds r1, r5, 0
	adds r1, 0x88
	bl SetBgTilemapBuffer
	ldrb r0, [r5]
	movs r1, 0x20
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldrb r0, [r5]
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldrb r0, [r5]
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldrb r0, [r5]
	ldrb r1, [r5, 0x3]
	lsls r1, 11
	movs r2, 0x2
	bl ChangeBgY
	ldrb r0, [r5]
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C82E4

	thumb_func_start sub_81C835C
sub_81C835C: @ 81C835C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C835C

	thumb_func_start sub_81C837C
sub_81C837C: @ 81C837C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r5, r1, 0
	ldrh r0, [r3, 0x2]
	ldrh r4, [r3]
	subs r2, r0, r4
	ldrh r0, [r3, 0x8]
	cmp r2, r0
	ble _081C8392
	adds r2, r0, 0
_081C8392:
	ldr r0, [r3, 0x10]
	ldr r3, [r3, 0xC]
	movs r1, 0
	str r1, [sp]
	str r5, [sp, 0x4]
	adds r1, r4, 0
	bl sub_81C83AC
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C837C

	thumb_func_start sub_81C83AC
sub_81C83AC: @ 81C83AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [sp, 0x10]
	cmp r2, 0
	beq _081C83D6
	adds r0, r5, 0
	muls r0, r3
	adds r0, r4, r0
	str r0, [r1, 0x1C]
	str r3, [r1, 0x18]
	movs r0, 0
	strh r0, [r1, 0xC]
	strh r2, [r1, 0xE]
	str r5, [r1, 0x14]
	ldr r0, [sp, 0xC]
	str r0, [r1, 0x10]
	ldr r0, =sub_81C83F0
	movs r1, 0x5
	bl sub_81C7078
_081C83D6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C83AC

	thumb_func_start sub_81C83E0
sub_81C83E0: @ 81C83E0
	push {lr}
	ldr r0, =sub_81C83F0
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C83E0

	thumb_func_start sub_81C83F0
sub_81C83F0: @ 81C83F0
	push {r4-r7,lr}
	sub sp, 0xC
	adds r6, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r6, 0
	beq _081C8408
	cmp r6, 0x1
	beq _081C848C
	b _081C849A
_081C8408:
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	ldr r1, [r4, 0x10]
	adds r5, r0, r1
	movs r0, 0xF
	ands r5, r0
	ldr r0, [r4, 0x1C]
	adds r7, r4, 0
	adds r7, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r7, 0
	bl _call_via_r2
	ldr r3, [r4, 0x38]
	cmp r3, 0
	beq _081C8434
	ldrh r0, [r4, 0x8]
	ldr r1, [r4, 0x14]
	adds r2, r5, 0
	bl _call_via_r3
_081C8434:
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	lsls r2, r5, 4
	movs r3, 0x1
	orrs r2, r3
	str r2, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r2, r7, 0
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0xE]
	cmp r0, r1
	bcc _081C847A
	ldr r0, [r4, 0x38]
	cmp r0, 0
	beq _081C846E
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081C8476
_081C846E:
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
_081C8476:
	movs r0, 0
	b _081C849C
_081C847A:
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r4, 0x1C]
	ldr r0, [r4, 0x14]
	adds r0, 0x1
	str r0, [r4, 0x14]
	movs r0, 0x3
	b _081C849C
_081C848C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C849A
	movs r0, 0x2
	b _081C849C
_081C849A:
	movs r0, 0x4
_081C849C:
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C83F0

	thumb_func_start sub_81C84A4
sub_81C84A4: @ 81C84A4
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	ldrh r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C84A4

	thumb_func_start sub_81C84C0
sub_81C84C0: @ 81C84C0
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	movs r3, 0
	ldrh r1, [r0]
	ldrh r2, [r0, 0x8]
	adds r1, r2
	ldrh r0, [r0, 0x2]
	cmp r1, r0
	bge _081C84DC
	movs r3, 0x1
_081C84DC:
	adds r0, r3, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C84C0

	thumb_func_start sub_81C84E8
sub_81C84E8: @ 81C84E8
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r4, r1, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r7, r0, 0
	ldr r0, =0x00000888
	adds r5, r7, r0
	cmp r6, 0
	bge _081C8524
	ldrh r1, [r5]
	adds r0, r1, r6
	cmp r0, 0
	bge _081C850A
	negs r6, r1
_081C850A:
	cmp r4, 0
	beq _081C854E
	ldr r0, [r5, 0x10]
	adds r1, r6
	negs r2, r6
	ldr r3, [r5, 0xC]
	str r6, [sp]
	str r7, [sp, 0x4]
	bl sub_81C83AC
	b _081C854E
	.pool
_081C8524:
	cmp r4, 0
	beq _081C854E
	ldr r2, =gUnknown_0203CF44
	ldrh r1, [r5]
	ldrh r0, [r5, 0x8]
	adds r4, r1, r0
	str r4, [r2]
	adds r0, r4, r6
	ldrh r1, [r5, 0x2]
	cmp r0, r1
	blt _081C853C
	subs r6, r1, r4
_081C853C:
	ldr r0, [r5, 0x10]
	ldr r3, [r5, 0xC]
	ldrh r1, [r5, 0x8]
	str r1, [sp]
	str r7, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81C83AC
_081C854E:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_81C8568
	ldrh r0, [r5]
	adds r0, r6
	strh r0, [r5]
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C84E8

	thumb_func_start sub_81C8568
sub_81C8568: @ 81C8568
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r4]
	bl GetBgY
	str r0, [r4, 0x20]
	lsls r1, r5, 12
	adds r0, r1
	str r0, [r4, 0x24]
	cmp r5, 0
	ble _081C8584
	movs r0, 0x1
	b _081C8586
_081C8584:
	movs r0, 0x2
_081C8586:
	str r0, [r4, 0x30]
	str r5, [r4, 0x2C]
	ldr r0, =sub_81C85A0
	movs r1, 0x6
	bl sub_81C7078
	str r0, [r4, 0x28]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8568

	thumb_func_start sub_81C85A0
sub_81C85A0: @ 81C85A0
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0
	beq _081C85B8
	cmp r5, 0x1
	beq _081C85C4
	movs r0, 0x4
	b _081C862A
_081C85B8:
	bl sub_81C83E0
	cmp r0, 0
	bne _081C8628
	movs r0, 0x1
	b _081C862A
_081C85C4:
	movs r6, 0
	ldrb r0, [r4]
	bl GetBgY
	adds r5, r0, 0
	ldrb r0, [r4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r4, 0x30]
	lsls r2, 24
	lsrs r2, 24
	bl ChangeBgY
	adds r1, r0, 0
	ldr r0, [r4, 0x30]
	cmp r0, 0x2
	bne _081C85F8
	ldr r2, [r4, 0x24]
	cmp r5, r2
	bgt _081C85F2
	ldr r0, [r4, 0x20]
	cmp r5, r0
	bgt _081C860A
_081C85F2:
	cmp r1, r2
	bgt _081C860A
	b _081C860E
_081C85F8:
	ldr r2, [r4, 0x24]
	cmp r5, r2
	blt _081C8604
	ldr r0, [r4, 0x20]
	cmp r5, r0
	blt _081C860A
_081C8604:
	cmp r1, r2
	blt _081C860A
	movs r6, 0x1
_081C860A:
	cmp r6, 0
	beq _081C8628
_081C860E:
	ldr r1, [r4, 0x2C]
	ldrh r0, [r4, 0xA]
	adds r0, r1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrb r0, [r4]
	adds r1, r2, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x4
	b _081C862A
_081C8628:
	movs r0, 0x2
_081C862A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C85A0

	thumb_func_start sub_81C8630
sub_81C8630: @ 81C8630
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r0, [r0, 0x28]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C8630

	thumb_func_start sub_81C8644
sub_81C8644: @ 81C8644
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x00000888
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8644

	thumb_func_start sub_81C8658
sub_81C8658: @ 81C8658
	push {lr}
	bl sub_81C8644
	adds r1, r0, 0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	beq _081C866E
	subs r0, 0x1
	strh r0, [r1, 0x6]
	movs r0, 0x1
	b _081C8686
_081C866E:
	bl sub_81C84A4
	cmp r0, 0
	bne _081C867A
	movs r0, 0
	b _081C8686
_081C867A:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
_081C8686:
	pop {r1}
	bx r1
	thumb_func_end sub_81C8658

	thumb_func_start sub_81C868C
sub_81C868C: @ 81C868C
	push {lr}
	bl sub_81C8644
	adds r2, r0, 0
	ldrh r1, [r2]
	ldrh r3, [r2, 0x6]
	adds r1, r3
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r1, r0
	bge _081C86BA
	ldrh r0, [r2, 0x8]
	subs r0, 0x1
	cmp r3, r0
	bge _081C86B2
	adds r0, r3, 0x1
	strh r0, [r2, 0x6]
	movs r0, 0x1
	b _081C86C8
_081C86B2:
	bl sub_81C84C0
	cmp r0, 0
	bne _081C86BE
_081C86BA:
	movs r0, 0
	b _081C86C8
_081C86BE:
	movs r0, 0x1
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
_081C86C8:
	pop {r1}
	bx r1
	thumb_func_end sub_81C868C

	thumb_func_start sub_81C86CC
sub_81C86CC: @ 81C86CC
	push {r4,lr}
	bl sub_81C8644
	adds r4, r0, 0
	bl sub_81C84A4
	adds r1, r0, 0
	cmp r1, 0
	beq _081C86F8
	ldrh r0, [r4]
	ldrh r1, [r4, 0x8]
	cmp r0, r1
	bcc _081C86EA
	ldrh r0, [r4, 0x8]
	b _081C86EC
_081C86EA:
	ldrh r0, [r4]
_081C86EC:
	negs r0, r0
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
	b _081C8706
_081C86F8:
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _081C8702
	movs r0, 0
	b _081C8706
_081C8702:
	strh r1, [r4, 0x6]
	movs r0, 0x1
_081C8706:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C86CC

	thumb_func_start sub_81C870C
sub_81C870C: @ 81C870C
	push {r4,lr}
	bl sub_81C8644
	adds r4, r0, 0
	bl sub_81C84C0
	cmp r0, 0
	beq _081C8736
	ldrh r0, [r4]
	ldrh r3, [r4, 0x8]
	adds r2, r0, r3
	ldrh r1, [r4, 0x4]
	subs r0, r1, r0
	cmp r2, r1
	bgt _081C872C
	adds r0, r3, 0
_081C872C:
	movs r1, 0x1
	bl sub_81C84E8
	movs r0, 0x2
	b _081C8756
_081C8736:
	ldrh r0, [r4, 0x2]
	ldrh r1, [r4, 0x8]
	cmp r0, r1
	bcc _081C8744
	ldrh r1, [r4, 0x6]
	ldrh r0, [r4, 0x8]
	b _081C8748
_081C8744:
	ldrh r1, [r4, 0x6]
	ldrh r0, [r4, 0x2]
_081C8748:
	subs r0, 0x1
	cmp r1, r0
	bge _081C8754
	strh r0, [r4, 0x6]
	movs r0, 0x1
	b _081C8756
_081C8754:
	movs r0, 0
_081C8756:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C870C

	thumb_func_start sub_81C875C
sub_81C875C: @ 81C875C
	push {lr}
	bl sub_81C8644
	adds r1, r0, 0
	ldrh r0, [r1]
	ldrh r1, [r1, 0x6]
	adds r0, r1
	pop {r1}
	bx r1
	thumb_func_end sub_81C875C

	thumb_func_start sub_81C8770
sub_81C8770: @ 81C8770
	push {lr}
	bl sub_81C8644
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81C8770

	thumb_func_start sub_81C877C
sub_81C877C: @ 81C877C
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x0000089c
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	ldr r0, =sub_81C8870
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r4, r1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C877C

	thumb_func_start sub_81C87AC
sub_81C87AC: @ 81C87AC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x11
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =0x00000888
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r4
	movs r2, 0
	strh r0, [r1]
	ldr r1, =0x0000089c
	adds r0, r5, r1
	str r2, [r0]
	ldr r0, =sub_81C8958
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r5, r1
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C87AC

	thumb_func_start sub_81C87F0
sub_81C87F0: @ 81C87F0
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x0000089c
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	ldr r0, =sub_81C8A28
	movs r1, 0x6
	bl sub_81C7078
	movs r1, 0x8A
	lsls r1, 4
	adds r4, r1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C87F0

	thumb_func_start sub_81C8820
sub_81C8820: @ 81C8820
	push {lr}
	movs r0, 0x11
	bl sub_81C763C
	movs r1, 0x8A
	lsls r1, 4
	adds r0, r1
	ldr r0, [r0]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C8820

	thumb_func_start sub_81C8838
sub_81C8838: @ 81C8838
	push {r4,lr}
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x00000888
	adds r2, r4, r0
	ldrh r0, [r4, 0x8]
	ldrh r1, [r2]
	ldrh r3, [r2, 0x6]
	adds r1, r3
	ldrh r2, [r4, 0xA]
	adds r2, r3
	movs r3, 0xF
	ands r2, r3
	ldr r3, [r4, 0x38]
	bl _call_via_r3
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8838

	thumb_func_start sub_81C8870
sub_81C8870: @ 81C8870
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x4
	bhi _081C894C
	lsls r0, r5, 2
	ldr r1, =_081C8890
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8890:
	.4byte _081C88A4
	.4byte _081C88AC
	.4byte _081C88D8
	.4byte _081C8918
	.4byte _081C8938
_081C88A4:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C9008
_081C88AC:
	ldr r0, =0x0000089c
	adds r5, r4, r0
	ldr r1, =0x0000088e
	adds r0, r4, r1
	ldr r1, [r5]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081C88C4
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_81C8B70
_081C88C4:
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
_081C88CA:
	movs r0, 0
	b _081C894E
	.pool
_081C88D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8942
	ldr r2, =0x0000089c
	adds r0, r4, r2
	subs r2, 0xC
	adds r1, r4, r2
	ldr r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	beq _081C88FC
	movs r0, 0x6
	b _081C894E
	.pool
_081C88FC:
	ldr r0, =0x0000088e
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C88CA
	adds r2, r0, 0
	adds r0, r4, 0
	adds r1, r3, 0
	bl sub_81C8B70
	b _081C88CA
	.pool
_081C8918:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8942
	ldr r2, =0x0000088e
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C894C
	movs r1, 0
	bl sub_81C84E8
	b _081C88CA
	.pool
_081C8938:
	bl sub_81C8630
	adds r1, r0, 0
	cmp r1, 0
	beq _081C8946
_081C8942:
	movs r0, 0x2
	b _081C894E
_081C8946:
	ldr r2, =0x0000088e
	adds r0, r4, r2
	strh r1, [r0]
_081C894C:
	movs r0, 0x4
_081C894E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C8870

	thumb_func_start sub_81C8958
sub_81C8958: @ 81C8958
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C8972
	movs r0, 0x2
	b _081C8A22
_081C8972:
	cmp r5, 0x7
	bhi _081C8A1C
	lsls r0, r5, 2
	ldr r1, =_081C8984
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8984:
	.4byte _081C89A4
	.4byte _081C89B4
	.4byte _081C89BE
	.4byte _081C89D0
	.4byte _081C89DA
	.4byte _081C89EC
	.4byte _081C89F6
	.4byte _081C8A08
_081C89A4:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	bl sub_81C8CB4
	b _081C8A20
	.pool
_081C89B4:
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C8DBC
	b _081C8A20
_081C89BE:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C89D0:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C8DBC
	b _081C8A20
_081C89DA:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C89EC:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_81C8DBC
	b _081C8A20
_081C89F6:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C8A08:
	ldr r1, =0x00000888
	adds r0, r4, r1
	adds r1, r4, 0
	movs r2, 0x3
	bl sub_81C8E54
	b _081C8A20
	.pool
_081C8A1C:
	movs r0, 0x4
	b _081C8A22
_081C8A20:
	movs r0, 0
_081C8A22:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C8958

	thumb_func_start sub_81C8A28
sub_81C8A28: @ 81C8A28
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081C8AA6
	movs r0, 0x11
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =0x00000888
	adds r6, r4, r0
	adds r2, r4, 0
	cmp r5, 0x6
	bls _081C8A4C
	b _081C8B64
_081C8A4C:
	lsls r0, r5, 2
	ldr r1, =_081C8A60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C8A60:
	.4byte _081C8A7C
	.4byte _081C8A88
	.4byte _081C8AE8
	.4byte _081C8AFC
	.4byte _081C8B14
	.4byte _081C8B34
	.4byte _081C8B5C
_081C8A7C:
	adds r0, r6, 0
	adds r1, r2, 0
	bl sub_81C8D4C
	movs r0, 0
	b _081C8B66
_081C8A88:
	ldr r1, =0x0000089c
	adds r7, r4, r1
	ldr r0, [r7]
	adds r1, r0, 0x1
	str r1, [r7]
	movs r3, 0x89
	lsls r3, 4
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _081C8AB0
	adds r0, r2, 0
	movs r2, 0x1
	bl sub_81C8B70
_081C8AA6:
	movs r0, 0x2
	b _081C8B66
	.pool
_081C8AB0:
	movs r0, 0
	str r0, [r7]
	ldrh r0, [r6, 0x2]
	ldrh r1, [r6, 0x8]
	cmp r0, r1
	bhi _081C8AC6
	ldrh r0, [r6]
	cmp r0, 0
	beq _081C8B52
	adds r4, r0, 0
	b _081C8AD4
_081C8AC6:
	ldrh r1, [r6]
	ldrh r0, [r6, 0x8]
	adds r4, r1, r0
	ldrh r1, [r6, 0x2]
	cmp r4, r1
	ble _081C8B52
	subs r4, r1
_081C8AD4:
	negs r5, r4
	adds r0, r2, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_81C8B70
	strh r4, [r6, 0x6]
	str r5, [r7]
	movs r0, 0
	b _081C8B66
_081C8AE8:
	ldr r2, =0x0000089c
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, 0
	bl sub_81C84E8
	movs r0, 0
	b _081C8B66
	.pool
_081C8AFC:
	bl sub_81C8630
	adds r1, r0, 0
	cmp r1, 0
	bne _081C8AA6
	ldr r3, =0x0000089c
	adds r0, r4, r3
	str r1, [r0]
_081C8B0C:
	movs r0, 0x1
	b _081C8B66
	.pool
_081C8B14:
	ldr r0, [r6, 0x10]
	ldrh r1, [r6]
	ldr r3, =0x0000089c
	adds r2, r4, r3
	ldr r2, [r2]
	adds r1, r2
	ldr r3, [r6, 0xC]
	str r2, [sp]
	str r4, [sp, 0x4]
	movs r2, 0x1
	bl sub_81C83AC
	movs r0, 0
	b _081C8B66
	.pool
_081C8B34:
	bl sub_81C83E0
	cmp r0, 0
	bne _081C8AA6
	ldr r0, =0x0000089c
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldrh r1, [r6, 0x2]
	cmp r0, r1
	bge _081C8B0C
	ldrh r6, [r6, 0x8]
	cmp r0, r6
	bge _081C8B0C
_081C8B52:
	movs r0, 0x9
	b _081C8B66
	.pool
_081C8B5C:
	adds r0, r2, 0
	movs r1, 0
	bl sub_81C9008
_081C8B64:
	movs r0, 0x4
_081C8B66:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C8A28

	thumb_func_start sub_81C8B70
sub_81C8B70: @ 81C8B70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r0
	adds r7, r1, 0
	adds r6, r2, 0
	ldrb r0, [r0, 0x8]
	movs r1, 0x7
	bl GetWindowAttribute
	mov r10, r0
	mov r1, r9
	ldrb r0, [r1, 0x4]
	lsls r3, r0, 6
	ldrh r0, [r1, 0xA]
	adds r7, r0, r7
	movs r0, 0xF
	ands r7, r0
	adds r0, r7, r6
	cmp r0, 0x10
	bgt _081C8BD4
	ldr r0, =0x11111111
	str r0, [sp]
	adds r1, r7, 0
	muls r1, r3
	add r1, r10
	adds r2, r6, 0
	muls r2, r3
	lsrs r2, 2
	ldr r0, =0x001fffff
	ands r2, r0
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	bl CpuFastSet
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	b _081C8C1E
	.pool
_081C8BD4:
	movs r2, 0x10
	subs r2, r7
	subs r0, r6, r2
	mov r8, r0
	ldr r1, =0x11111111
	str r1, [sp, 0x4]
	add r0, sp, 0x4
	adds r1, r7, 0
	muls r1, r3
	add r1, r10
	muls r2, r3
	lsrs r2, 2
	ldr r5, =0x001fffff
	ands r2, r5
	movs r4, 0x80
	lsls r4, 17
	orrs r2, r4
	str r3, [sp, 0xC]
	bl CpuFastSet
	ldr r0, =0x11111111
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r3, [sp, 0xC]
	mov r2, r8
	muls r2, r3
	lsrs r2, 2
	ands r2, r5
	orrs r2, r4
	mov r1, r10
	bl CpuFastSet
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
_081C8C1E:
	subs r6, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _081C8C40
	movs r5, 0xF
	adds r4, r0, 0
_081C8C2C:
	mov r1, r9
	ldrh r0, [r1, 0x8]
	adds r1, r7, 0
	bl sub_81CBD48
	adds r7, 0x1
	ands r7, r5
	subs r6, 0x1
	cmp r6, r4
	bne _081C8C2C
_081C8C40:
	mov r1, r9
	ldrb r0, [r1, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8B70

	thumb_func_start sub_81C8C64
sub_81C8C64: @ 81C8C64
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	adds r2, r0, 0
	ldrh r0, [r5, 0xA]
	lsls r0, 6
	ldrb r1, [r5, 0x2]
	adds r0, r1
	lsls r0, 1
	subs r0, 0x2
	adds r2, r0
	cmp r4, 0
	beq _081C8C98
	ldrb r0, [r5, 0x1]
	lsls r0, 12
	ldrh r1, [r5, 0x6]
	adds r1, 0x1
	b _081C8C9E
_081C8C98:
	ldrb r0, [r5, 0x1]
	lsls r0, 12
	ldrh r1, [r5, 0x6]
_081C8C9E:
	orrs r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	strh r1, [r2]
	adds r0, r2, 0
	adds r0, 0x40
	strh r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8C64

	thumb_func_start sub_81C8CB4
sub_81C8CB4: @ 81C8CB4
	push {r4-r6,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_0861FBE4
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldrh r1, [r5]
	ldr r0, [r5, 0xC]
	muls r1, r0
	ldr r0, [r5, 0x10]
	adds r0, r1
	adds r6, r4, 0
	adds r6, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r6, 0
	bl _call_via_r2
	ldrh r0, [r4, 0x8]
	ldrh r1, [r5]
	ldrh r2, [r4, 0xA]
	ldr r3, [r4, 0x38]
	bl _call_via_r3
	ldrb r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 20
	lsrs r3, 16
	ldrb r1, [r4, 0x4]
	lsls r1, 3
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x44
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	ldrh r3, [r4, 0xA]
	lsls r3, 4
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	add r2, sp, 0xC
	str r2, [sp]
	movs r2, 0x1
	negs r2, r2
	str r2, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r2, 0x8
	bl AddTextPrinterParameterized3
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C8C64
	ldrh r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 1
	ldrb r1, [r4, 0x4]
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r1, 0x3
	movs r2, 0
	bl CopyWindowRectToVram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8CB4

	thumb_func_start sub_81C8D4C
sub_81C8D4C: @ 81C8D4C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	ldrh r2, [r0]
	ldr r1, [r0, 0xC]
	muls r1, r2
	ldr r0, [r0, 0x10]
	adds r0, r1
	adds r5, r4, 0
	adds r5, 0x48
	ldr r2, [r4, 0x34]
	adds r1, r5, 0
	bl _call_via_r2
	ldrb r0, [r4, 0x8]
	ldrh r3, [r4, 0xA]
	lsls r3, 20
	lsrs r3, 16
	ldrb r1, [r4, 0x4]
	lsls r1, 3
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r4, 0x8]
	ldrb r1, [r4, 0x5]
	ldrh r2, [r4, 0xA]
	lsls r2, 4
	adds r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	adds r2, r5, 0
	movs r3, 0x8
	bl AddTextPrinterParameterized
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C8C64
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8D4C

	thumb_func_start sub_81C8DBC
sub_81C8DBC: @ 81C8DBC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x1C
	adds r6, r0, 0
	mov r8, r1
	add r1, sp, 0xC
	ldr r0, =gUnknown_0861FBE8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r0, sp, 0x18
	mov r9, r0
	ldr r1, =gUnknown_0861FBF4
	movs r2, 0x3
	bl memcpy
	ldrh r4, [r6, 0xA]
	mov r1, r8
	lsls r0, r1, 1
	adds r0, 0x1
	adds r4, r0
	movs r0, 0xF
	ands r4, r0
	ldrb r0, [r6, 0x8]
	lsls r5, r4, 4
	adds r3, r5, 0
	ldrb r1, [r6, 0x4]
	str r1, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	ldrb r0, [r6, 0x8]
	movs r1, 0x1
	orrs r5, r1
	mov r2, r9
	str r2, [sp]
	subs r1, 0x2
	str r1, [sp, 0x4]
	mov r3, r8
	lsls r3, 2
	mov r8, r3
	mov r1, sp
	add r1, r8
	adds r1, 0xC
	ldr r1, [r1]
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r2, 0x2
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	ldrh r0, [r6, 0x8]
	lsls r4, 1
	ldrb r1, [r6, 0x4]
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r2, 0
	adds r3, r4, 0
	bl CopyWindowRectToVram
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8DBC

	thumb_func_start sub_81C8E54
sub_81C8E54: @ 81C8E54
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	adds r1, r2, 0
	ldrh r3, [r7, 0xA]
	ldr r2, =gUnknown_0861FBF7
	adds r2, r1, r2
	ldrb r2, [r2]
	adds r6, r3, r2
	movs r2, 0xF
	ands r6, r2
	ldrh r0, [r0]
	bl sub_81CAFD8
	adds r5, r0, 0
	cmp r5, 0
	beq _081C8EC0
	ldrh r0, [r7, 0x8]
	lsls r4, r6, 1
	ldrb r3, [r7, 0x4]
	subs r3, 0x1
	movs r1, 0x2
	mov r8, r1
	str r1, [sp]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_81DB620
	ldrb r0, [r7, 0x8]
	lsls r1, r6, 4
	movs r2, 0x1
	orrs r1, r2
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0x2
	bl AddTextPrinterParameterized
	ldrh r0, [r7, 0x8]
	ldrb r1, [r7, 0x4]
	str r1, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	movs r1, 0x2
	movs r2, 0
	adds r3, r4, 0
	bl CopyWindowRectToVram
_081C8EC0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8E54

	thumb_func_start sub_81C8ED0
sub_81C8ED0: @ 81C8ED0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_0861FBFC
_081C8ED6:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081C8ED6
	ldr r0, =gUnknown_0861FC04
	bl sub_81C795C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8ED0

	thumb_func_start sub_81C8EF8
sub_81C8EF8: @ 81C8EF8
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_0861FC1C
	ldrb r1, [r5, 0x2]
	lsls r1, 3
	adds r1, 0x3
	ldrb r2, [r5, 0x3]
	adds r2, 0x1
	lsls r2, 3
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	mov r8, r1
	add r0, r8
	str r0, [r5, 0x3C]
	ldrb r6, [r5, 0x2]
	lsls r6, 3
	ldrb r0, [r5, 0x4]
	subs r0, 0x1
	lsls r0, 2
	ldr r3, =gUnknown_0861FC3C
	mov r10, r3
	adds r6, r0
	ldrb r2, [r5, 0x3]
	lsls r2, 3
	ldrh r0, [r4, 0x8]
	lsls r0, 4
	adds r2, r0
	lsls r2, 16
	asrs r2, 16
	mov r0, r10
	adds r1, r6, 0
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	add r2, r8
	str r2, [r5, 0x44]
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
	ldr r0, =0x000003ff
	mov r9, r0
	mov r0, r9
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldr r1, [r5, 0x44]
	ldr r0, =sub_81C90A0
	str r0, [r1, 0x1C]
	ldrb r2, [r5, 0x3]
	lsls r2, 3
	mov r0, r10
	adds r1, r6, 0
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	add r1, r8
	str r1, [r5, 0x40]
	ldrh r2, [r1, 0x4]
	lsls r0, r2, 22
	lsrs r0, 22
	adds r0, 0x4
	mov r3, r9
	ands r0, r3
	ands r4, r2
	orrs r4, r0
	strh r4, [r1, 0x4]
	ldr r1, [r5, 0x40]
	ldr r0, =sub_81C90F4
	str r0, [r1, 0x1C]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C8EF8

	thumb_func_start sub_81C8FE0
sub_81C8FE0: @ 81C8FE0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x3C]
	bl DestroySprite
	ldr r0, [r4, 0x40]
	bl DestroySprite
	ldr r0, [r4, 0x44]
	bl DestroySprite
	movs r0, 0xA
	bl FreeSpriteTilesByTag
	movs r0, 0x14
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C8FE0

	thumb_func_start sub_81C9008
sub_81C9008: @ 81C9008
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _081C9028
	ldr r2, [r5, 0x3C]
	ldr r1, =SpriteCallbackDummy
	str r1, [r2, 0x1C]
	ldr r0, [r5, 0x40]
	str r1, [r0, 0x1C]
	ldr r0, [r5, 0x44]
	str r1, [r0, 0x1C]
	b _081C903A
	.pool
_081C9028:
	ldr r2, [r5, 0x3C]
	ldr r0, =sub_81C9080
	str r0, [r2, 0x1C]
	ldr r1, [r5, 0x40]
	ldr r0, =sub_81C90F4
	str r0, [r1, 0x1C]
	ldr r1, [r5, 0x44]
	ldr r0, =sub_81C90A0
	str r0, [r1, 0x1C]
_081C903A:
	adds r3, r2, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r4, r0
	lsls r4, 2
	ldrb r2, [r3]
	movs r1, 0x5
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r3]
	ldr r2, [r5, 0x40]
	adds r2, 0x3E
	ldrb r3, [r2]
	adds r0, r1, 0
	ands r0, r3
	orrs r0, r4
	strb r0, [r2]
	ldr r0, [r5, 0x44]
	adds r0, 0x3E
	ldrb r2, [r0]
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9008

	thumb_func_start sub_81C9080
sub_81C9080: @ 81C9080
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, =0x0000088e
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 4
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9080

	thumb_func_start sub_81C90A0
sub_81C90A0: @ 81C90A0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C90C2
	bl sub_81C84C0
	cmp r0, 0
	beq _081C90C2
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _081C90CC
_081C90C2:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
_081C90CC:
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081C90EC
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x26]
_081C90EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C90A0

	thumb_func_start sub_81C90F4
sub_81C90F4: @ 81C90F4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C9116
	bl sub_81C84A4
	cmp r0, 0
	beq _081C9116
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _081C9120
_081C9116:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
_081C9120:
	strb r0, [r2]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _081C9142
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r4, 0x30]
	negs r0, r0
	strh r0, [r4, 0x26]
_081C9142:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C90F4

	thumb_func_start sub_81C9148
sub_81C9148: @ 81C9148
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x11
	bl sub_81C763C
	ldr r1, [r0, 0x40]
	strh r4, [r1, 0x3C]
	ldr r0, [r0, 0x44]
	strh r4, [r0, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C9148

	thumb_func_start sub_81C9160
sub_81C9160: @ 81C9160
	push {r4,r5,lr}
	adds r2, r0, 0
	ldr r0, [r1]
	str r0, [r2, 0x10]
	ldrh r4, [r1, 0x6]
	movs r5, 0
	strh r4, [r2]
	ldrh r3, [r1, 0x4]
	strh r3, [r2, 0x2]
	ldrb r0, [r1, 0x8]
	str r0, [r2, 0xC]
	ldrb r1, [r1, 0xC]
	strh r1, [r2, 0x8]
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r1, r0
	bcc _081C918A
	strh r5, [r2]
	strh r5, [r2, 0x4]
	strh r4, [r2, 0x6]
	b _081C91A6
_081C918A:
	subs r0, r3, r1
	strh r0, [r2, 0x4]
	ldrh r1, [r2]
	ldrh r0, [r2, 0x8]
	adds r1, r0
	ldrh r0, [r2, 0x2]
	cmp r1, r0
	ble _081C91A4
	subs r0, r1, r0
	strh r0, [r2, 0x6]
	subs r0, r4, r0
	strh r0, [r2]
	b _081C91A6
_081C91A4:
	strh r5, [r2, 0x6]
_081C91A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C9160

	thumb_func_start sub_81C91AC
sub_81C91AC: @ 81C91AC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	ldr r4, [r1]
	lsls r4, 30
	lsrs r0, r4, 30
	movs r1, 0
	mov r9, r1
	strb r0, [r7]
	strh r3, [r7, 0x6]
	ldr r0, [r2, 0x10]
	str r0, [r7, 0x34]
	ldr r0, [r2, 0x14]
	str r0, [r7, 0x38]
	ldrb r6, [r2, 0xD]
	strb r6, [r7, 0x1]
	ldrb r1, [r2, 0x9]
	strb r1, [r7, 0x2]
	ldrb r0, [r2, 0xB]
	strb r0, [r7, 0x3]
	ldrb r5, [r2, 0xA]
	strb r5, [r7, 0x4]
	ldrb r0, [r2, 0xE]
	strb r0, [r7, 0x5]
	lsrs r4, 30
	ldr r2, =0xffffff00
	mov r8, r2
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r4
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ands r0, r2
	orrs r0, r1
	ldr r1, =0xff00ffff
	ands r0, r1
	lsls r5, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r5
	str r0, [sp]
	ldr r0, [sp, 0x4]
	mov r1, r8
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	lsls r6, 24
	lsrs r6, 16
	ands r0, r2
	orrs r0, r6
	adds r3, 0x2
	lsls r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r3
	str r0, [sp, 0x4]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x8]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _081C9258
	mov r2, r9
	strh r2, [r7, 0xA]
	mov r0, r9
	str r0, [r7, 0x3C]
	str r0, [r7, 0x40]
	str r0, [r7, 0x44]
	movs r0, 0x1
	b _081C925A
	.pool
_081C9258:
	movs r0, 0
_081C925A:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C91AC

	thumb_func_start sub_81C9268
sub_81C9268: @ 81C9268
	push {r4,lr}
	movs r4, 0
	movs r0, 0x98
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x1
	ldr r0, =0x0000089b
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x2
_081C928A:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C9268

	thumb_func_start sub_81C9298
sub_81C9298: @ 81C9298
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92C4
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	strh r1, [r4, 0x2]
	strh r1, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92C6
_081C92C4:
	movs r0, 0
_081C92C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9298

	thumb_func_start sub_81C92CC
sub_81C92CC: @ 81C92CC
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92FA
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92FC
_081C92FA:
	movs r0, 0
_081C92FC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C92CC

	thumb_func_start sub_81C9304
sub_81C9304: @ 81C9304
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C932E
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x3
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9330
_081C932E:
	movs r0, 0
_081C9330:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9304

	thumb_func_start sub_81C9338
sub_81C9338: @ 81C9338
	push {lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r2, r0, 0
	cmp r2, 0
	beq _081C9360
	movs r0, 0
	movs r1, 0x3
	strh r1, [r2]
	strh r0, [r2, 0x2]
	movs r1, 0x5
	strh r1, [r2, 0x4]
	strh r0, [r2, 0x6]
	adds r0, r2, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9362
_081C9360:
	movs r0, 0
_081C9362:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9338

	thumb_func_start sub_81C9368
sub_81C9368: @ 81C9368
	push {r4,r5,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl sub_81C761C
	adds r5, r0, 0
	cmp r5, 0
	beq _081C9394
	movs r4, 0
	movs r0, 0x4
	strh r0, [r5]
	bl sub_81C76AC
	strh r0, [r5, 0x2]
	adds r0, 0x8
	strh r0, [r5, 0x4]
	strh r4, [r5, 0x6]
	adds r0, r5, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9396
_081C9394:
	movs r0, 0
_081C9396:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9368

	thumb_func_start sub_81C939C
sub_81C939C: @ 81C939C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4]
	cmp r0, 0x4
	bhi _081C93E0
	lsls r0, 2
	ldr r1, =_081C93B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C93B4:
	.4byte _081C93C8
	.4byte _081C93CE
	.4byte _081C93CE
	.4byte _081C93D4
	.4byte _081C93DC
_081C93C8:
	movs r0, 0
	bl sub_81C7688
_081C93CE:
	bl sub_81C93EC
	b _081C93DE
_081C93D4:
	ldr r0, =sub_81C963C
	b _081C93DE
	.pool
_081C93DC:
	ldr r0, =sub_81C96FC
_081C93DE:
	str r0, [r4, 0xC]
_081C93E0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C939C

	thumb_func_start sub_81C93EC
sub_81C93EC: @ 81C93EC
	push {lr}
	bl sub_81C767C
	cmp r0, 0x1
	beq _081C9408
	cmp r0, 0x1
	bcc _081C93FE
	cmp r0, 0x2
	beq _081C9410
_081C93FE:
	ldr r0, =sub_81C943C
	b _081C9412
	.pool
_081C9408:
	ldr r0, =sub_81C9520
	b _081C9412
	.pool
_081C9410:
	ldr r0, =c2_pre_battle_1
_081C9412:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C93EC

	thumb_func_start sub_81C941C
sub_81C941C: @ 81C941C
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldr r1, [r0, 0xC]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81C941C

	thumb_func_start sub_81C9430
sub_81C9430: @ 81C9430
	push {lr}
	movs r0, 0x1
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81C9430

	thumb_func_start sub_81C943C
sub_81C943C: @ 81C943C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C944C
	movs r0, 0x1
	b _081C951A
_081C944C:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _081C9508
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _081C9508
	lsls r0, 2
	ldr r1, =_081C9488
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C9488:
	.4byte _081C949C
	.4byte _081C94BC
	.4byte _081C94D4
	.4byte _081C94E0
	.4byte _081C9516
_081C949C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x15]
	movs r0, 0x8
	ands r0, r1
	movs r1, 0x1
	cmp r0, 0
	beq _081C94AE
	movs r1, 0x2
_081C94AE:
	strh r1, [r4, 0x6]
	ldr r1, =0x000186a6
	b _081C94EE
	.pool
_081C94BC:
	movs r1, 0
	movs r0, 0x3
	strh r0, [r4]
	strh r1, [r4, 0x2]
	ldrb r0, [r3, 0x12]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C963C
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _081C951A
	.pool
_081C94D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	b _081C94EE
	.pool
_081C94E0:
	bl sub_81C76B8
	cmp r0, 0
	beq _081C94FC
	movs r0, 0x9
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ac
_081C94EE:
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C951A
	.pool
_081C94FC:
	ldr r0, =sub_81C9600
	str r0, [r4, 0xC]
	movs r0, 0x6
	b _081C951A
	.pool
_081C9508:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C9516
	movs r0, 0
	b _081C951A
_081C9516:
	movs r0, 0x1
	negs r0, r0
_081C951A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C943C

	thumb_func_start sub_81C9520
sub_81C9520: @ 81C9520
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9530
	movs r0, 0x1
	b _081C9580
_081C9530:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9570
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _081C9578
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C9580
	.pool
_081C9570:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C957E
_081C9578:
	movs r0, 0x20
	bl PlaySE
_081C957E:
	movs r0, 0
_081C9580:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9520

	thumb_func_start c2_pre_battle_1
c2_pre_battle_1: @ 81C9588
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9598
	movs r0, 0x1
	b _081C95F8
_081C9598:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C95E8
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _081C95D4
	cmp r0, 0x4
	beq _081C95F4
	movs r0, 0x20
	bl PlaySE
	movs r0, 0
	b _081C95F8
	.pool
_081C95D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C95F8
	.pool
_081C95E8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C95F4
	movs r0, 0
	b _081C95F8
_081C95F4:
	movs r0, 0x1
	negs r0, r0
_081C95F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end c2_pre_battle_1

	thumb_func_start sub_81C9600
sub_81C9600: @ 81C9600
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9616
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9634
_081C9616:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081C962C
	movs r0, 0
	b _081C9634
	.pool
_081C962C:
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x7
_081C9634:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9600

	thumb_func_start sub_81C963C
sub_81C963C: @ 81C963C
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_81C9814
	adds r3, r0, 0
	cmp r3, 0
	beq _081C964E
	movs r0, 0x1
	b _081C96F6
_081C964E:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _081C96B8
	ldr r5, =gUnknown_0861FC59
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	ldrh r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 1
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _081C968E
	cmp r0, 0x6
	bgt _081C9688
	cmp r0, 0x5
	beq _081C96A4
	b _081C96B8
	.pool
_081C9688:
	cmp r0, 0x7
	beq _081C96E4
	b _081C96B8
_081C968E:
	movs r0, 0x4
	strh r0, [r4]
	strh r3, [r4, 0x2]
	ldrb r0, [r5, 0x18]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C96FC
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _081C96F6
	.pool
_081C96A4:
	strh r3, [r4, 0x6]
	ldr r1, =0x000186a7
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C96F6
	.pool
_081C96B8:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C96F4
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C96E4
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C9798
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C96F6
	.pool
_081C96E4:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C97C0
	movs r0, 0x3
	b _081C96F6
_081C96F4:
	movs r0, 0
_081C96F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C963C

	thumb_func_start sub_81C96FC
sub_81C96FC: @ 81C96FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C970C
	movs r0, 0x1
	b _081C9792
_081C970C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9754
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xD
	beq _081C9780
	subs r0, 0x8
	bl sub_81C7694
	ldr r1, =0x000186a8
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x3
	strh r0, [r4, 0x6]
	movs r0, 0x8
	b _081C9792
	.pool
_081C9754:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C9790
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C9780
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C97A4
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9792
	.pool
_081C9780:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C97F8
	movs r0, 0x5
	b _081C9792
_081C9790:
	movs r0, 0
_081C9792:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C96FC

	thumb_func_start sub_81C9798
sub_81C9798: @ 81C9798
	push {lr}
	bl sub_81C97C0
	movs r0, 0x3
	pop {r1}
	bx r1
	thumb_func_end sub_81C9798

	thumb_func_start sub_81C97A4
sub_81C97A4: @ 81C97A4
	push {lr}
	bl sub_81C97F8
	movs r0, 0x5
	pop {r1}
	bx r1
	thumb_func_end sub_81C97A4

	thumb_func_start sub_81C97B0
sub_81C97B0: @ 81C97B0
	str r1, [r0, 0x8]
	ldr r1, =sub_81C97BC
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97B0

	thumb_func_start sub_81C97BC
sub_81C97BC: @ 81C97BC
	ldr r0, [r0, 0x8]
	bx lr
	thumb_func_end sub_81C97BC

	thumb_func_start sub_81C97C0
sub_81C97C0: @ 81C97C0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, =gUnknown_0861FC59
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C943C
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C97C0

	thumb_func_start sub_81C97F8
sub_81C97F8: @ 81C97F8
	movs r1, 0x3
	strh r1, [r0]
	movs r1, 0x1
	strh r1, [r0, 0x2]
	ldr r1, =gUnknown_0861FC59
	ldrb r1, [r1, 0x13]
	strh r1, [r0, 0x4]
	ldr r1, =sub_81C963C
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97F8

	thumb_func_start sub_81C9814
sub_81C9814: @ 81C9814
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C9848
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	ldrh r3, [r4]
	cmp r0, 0
	bge _081C986A
	ldr r0, =gUnknown_0861FC54
	adds r0, r3, r0
	ldrb r0, [r0]
	strh r0, [r4, 0x2]
	b _081C986A
	.pool
_081C9848:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C988C
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, =gUnknown_0861FC54
	ldrh r1, [r4]
	adds r0, r1, r0
	adds r3, r1, 0
	ldrb r0, [r0]
	cmp r2, r0
	ble _081C986A
	strh r5, [r4, 0x2]
_081C986A:
	ldr r2, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 1
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	strh r0, [r4, 0x4]
	movs r0, 0x1
	b _081C988E
	.pool
_081C988C:
	movs r0, 0
_081C988E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9814

	thumb_func_start sub_81C9894
sub_81C9894: @ 81C9894
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81C9894

	thumb_func_start sub_81C98A4
sub_81C98A4: @ 81C98A4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98A4

	thumb_func_start sub_81C98B4
sub_81C98B4: @ 81C98B4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0, 0x4]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98B4

	thumb_func_start sub_81C98C4
sub_81C98C4: @ 81C98C4
	push {lr}
	movs r0, 0x1
	bl sub_81C763C
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98C4

	thumb_func_start sub_81C98D4
sub_81C98D4: @ 81C98D4
	push {r4,lr}
	movs r4, 0
_081C98D8:
	adds r0, r4, 0
	bl sub_81CB0C8
	ldr r1, =gMapHeader
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081C9914
	adds r0, r4, 0
	bl sub_81CAE08
	cmp r0, 0
	beq _081C9914
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C9914
	movs r0, 0x1
	b _081C991C
	.pool
_081C9914:
	adds r4, 0x1
	cmp r4, 0x4D
	ble _081C98D8
	movs r0, 0
_081C991C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C98D4

	thumb_func_start sub_81C9924
sub_81C9924: @ 81C9924
	push {lr}
	bl sub_81C9958
	adds r1, r0, 0
	cmp r1, 0
	beq _081C9938
	movs r0, 0
	strb r0, [r1, 0xD]
	movs r0, 0x1
	b _081C993A
_081C9938:
	movs r0, 0
_081C993A:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9924

	thumb_func_start sub_81C9940
sub_81C9940: @ 81C9940
	push {lr}
	bl sub_81C9958
	adds r1, r0, 0
	cmp r1, 0
	beq _081C9952
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _081C9954
_081C9952:
	movs r0, 0
_081C9954:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9940

	thumb_func_start sub_81C9958
sub_81C9958: @ 81C9958
	push {r4,lr}
	ldr r1, =0x0000088c
	movs r0, 0x2
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081C997A
	movs r0, 0
	strb r0, [r4, 0xC]
	ldr r0, =sub_81C9A10
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81C99FC
	str r0, [r4]
_081C997A:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C9958

	thumb_func_start sub_81C9990
sub_81C9990: @ 81C9990
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086201A0
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81C99FC
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9990

	thumb_func_start sub_81C99C0
sub_81C99C0: @ 81C99C0
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81C99C0

	thumb_func_start sub_81C99D4
sub_81C99D4: @ 81C99D4
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CA7F4
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	bl sub_81C9FEC
	bl sub_81CA994
	movs r0, 0x2
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C99D4

	thumb_func_start sub_81C99FC
sub_81C99FC: @ 81C99FC
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81C99FC

	thumb_func_start sub_81C9A10
sub_81C9A10: @ 81C9A10
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x9
	bls _081C9A24
	b _081C9C60
_081C9A24:
	lsls r0, r4, 2
	ldr r1, =_081C9A34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C9A34:
	.4byte _081C9A5C
	.4byte _081C9AEC
	.4byte _081C9B30
	.4byte _081C9B88
	.4byte _081C9B9E
	.4byte _081C9BA4
	.4byte _081C9BB6
	.4byte _081C9BC0
	.4byte _081C9C0E
	.4byte _081C9C4C
_081C9A5C:
	ldr r0, =gUnknown_08620194
	movs r1, 0x3
	bl sub_81C7B54
	ldr r1, =gPokenavMessageBox_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x8C
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gPokenavMessageBox_Tilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gPokenavMessageBox_Pal
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
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
_081C9AD6:
	movs r0, 0
	b _081C9C62
	.pool
_081C9AEC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C9AFA
	b _081C9C5C
_081C9AFA:
	ldr r1, =gUnknown_0861FD6C
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_0861FFF4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0861FD4C
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	b _081C9AD6
	.pool
_081C9B30:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C9B3E
	b _081C9C5C
_081C9B3E:
	ldr r1, =gUnknown_0861FC98
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_0861FCAC
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =gUnknown_0861FC78
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9B76
	bl sub_81C9894
	cmp r0, 0x4
	bne _081C9AD6
_081C9B76:
	bl sub_81CA850
	b _081C9AD6
	.pool
_081C9B88:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081C9C5C
	bl sub_81CA6E0
	bl sub_81CA7D4
_081C9B9A:
	movs r0, 0x1
	b _081C9C62
_081C9B9E:
	bl sub_81C9FC4
	b _081C9B9A
_081C9BA4:
	bl sub_81CA714
	bl sub_81CA02C
	bl sub_81CA640
	bl sub_81CA0C8
	b _081C9AD6
_081C9BB6:
	bl sub_81CA7C4
	cmp r0, 0
	bne _081C9C5C
	b _081C9B9A
_081C9BC0:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldrb r0, [r5, 0xD]
	cmp r0, 0
	beq _081C9BE0
	movs r0, 0x1
	bl sub_81C7AC0
	b _081C9BEC
_081C9BE0:
	movs r0, 0x6E
	bl PlaySE
	movs r0, 0x3
	bl sub_81C7AC0
_081C9BEC:
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9BFE
	cmp r0, 0x4
	bne _081C9C06
	movs r0, 0x7
	bl sub_81C7DFC
_081C9BFE:
	movs r0, 0x1
	bl sub_81C7DFC
	b _081C9AD6
_081C9C06:
	movs r0, 0
	bl sub_81C7DFC
	b _081C9AD6
_081C9C0E:
	bl sub_81C7B34
	cmp r0, 0
	bne _081C9C5C
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9C2C
	cmp r0, 0x4
	bne _081C9C38
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
_081C9C2C:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	b _081C9C42
_081C9C38:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
_081C9C42:
	bl sub_81CA20C
	bl titlescreen_0
	b _081C9B9A
_081C9C4C:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9C5C
	bl sub_81C8010
	cmp r0, 0
	beq _081C9C60
_081C9C5C:
	movs r0, 0x2
	b _081C9C62
_081C9C60:
	movs r0, 0x4
_081C9C62:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9A10

	thumb_func_start sub_81C9C6C
sub_81C9C6C: @ 81C9C6C
	push {lr}
	cmp r0, 0
	beq _081C9C78
	cmp r0, 0x1
	beq _081C9C8E
	b _081C9CA2
_081C9C78:
	bl sub_81CAA3C
	bl sub_81CA278
	bl sub_81CA714
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	b _081C9CA4
_081C9C8E:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9C9E
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9CA2
_081C9C9E:
	movs r0, 0x2
	b _081C9CA4
_081C9CA2:
	movs r0, 0x4
_081C9CA4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9C6C

	thumb_func_start sub_81C9CA8
sub_81C9CA8: @ 81C9CA8
	push {lr}
	cmp r0, 0x1
	beq _081C9CDC
	cmp r0, 0x1
	bgt _081C9CB8
	cmp r0, 0
	beq _081C9CC2
	b _081C9D3C
_081C9CB8:
	cmp r0, 0x2
	beq _081C9CFA
	cmp r0, 0x3
	beq _081C9D14
	b _081C9D3C
_081C9CC2:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	b _081C9D3E
_081C9CDC:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9D34
	bl sub_81C8010
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA0C8
	movs r0, 0x1
	bl sub_81C7DFC
	movs r0, 0
	b _081C9D3E
_081C9CFA:
	bl sub_81CA20C
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA818
	bl sub_81CA714
	movs r0, 0
	b _081C9D3E
_081C9D14:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9D34
	bl sub_81C8010
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA89C
	cmp r0, 0
	bne _081C9D34
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9D38
_081C9D34:
	movs r0, 0x2
	b _081C9D3E
_081C9D38:
	bl sub_81CA9D8
_081C9D3C:
	movs r0, 0x4
_081C9D3E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9CA8

	thumb_func_start sub_81C9D44
sub_81C9D44: @ 81C9D44
	push {lr}
	cmp r0, 0x1
	beq _081C9D72
	cmp r0, 0x1
	bgt _081C9D54
	cmp r0, 0
	beq _081C9D5E
	b _081C9DD2
_081C9D54:
	cmp r0, 0x2
	beq _081C9D90
	cmp r0, 0x3
	beq _081C9DAA
	b _081C9DD2
_081C9D5E:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x1
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0
	b _081C9DD4
_081C9D72:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9DCA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA0C8
	movs r0, 0
	bl sub_81C7DFC
	movs r0, 0
	b _081C9DD4
_081C9D90:
	bl sub_81CA20C
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA864
	bl sub_81CA714
	movs r0, 0
	b _081C9DD4
_081C9DAA:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9DCA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA89C
	cmp r0, 0
	bne _081C9DCA
	bl sub_81CA7C4
	cmp r0, 0
	beq _081C9DCE
_081C9DCA:
	movs r0, 0x2
	b _081C9DD4
_081C9DCE:
	bl sub_81CA9D8
_081C9DD2:
	movs r0, 0x4
_081C9DD4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9D44

	thumb_func_start sub_81C9DD8
sub_81C9DD8: @ 81C9DD8
	push {lr}
	cmp r0, 0x1
	beq _081C9E04
	cmp r0, 0x1
	bgt _081C9DE8
	cmp r0, 0
	beq _081C9DF2
	b _081C9E50
_081C9DE8:
	cmp r0, 0x2
	beq _081C9E1A
	cmp r0, 0x3
	beq _081C9E30
	b _081C9E50
_081C9DF2:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	b _081C9E52
_081C9E04:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9E48
	movs r0, 0x7
	bl sub_81C7DFC
	bl sub_81CA0C8
	movs r0, 0
	b _081C9E52
_081C9E1A:
	bl sub_81CA20C
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_81C7FA0
	bl sub_81CA714
	movs r0, 0
	b _081C9E52
_081C9E30:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9E48
	bl sub_81C8010
	cmp r0, 0
	bne _081C9E48
	bl sub_81CA89C
	cmp r0, 0
	beq _081C9E4C
_081C9E48:
	movs r0, 0x2
	b _081C9E52
_081C9E4C:
	bl sub_81CA9D8
_081C9E50:
	movs r0, 0x4
_081C9E52:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9DD8

	thumb_func_start sub_81C9E58
sub_81C9E58: @ 81C9E58
	push {lr}
	cmp r0, 0x1
	beq _081C9E86
	cmp r0, 0x1
	bgt _081C9E68
	cmp r0, 0
	beq _081C9E72
	b _081C9EC2
_081C9E68:
	cmp r0, 0x2
	beq _081C9E9E
	cmp r0, 0x3
	beq _081C9EAA
	b _081C9EC2
_081C9E72:
	bl sub_81CA9C8
	bl sub_81CA2DC
	movs r0, 0x7
	movs r1, 0
	bl sub_81C7FC4
	movs r0, 0
	b _081C9EC4
_081C9E86:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9EBA
	bl sub_81C8010
	cmp r0, 0
	bne _081C9EBA
	bl sub_81CA0C8
	movs r0, 0
	b _081C9EC4
_081C9E9E:
	bl sub_81CA20C
	bl sub_81CA714
	movs r0, 0
	b _081C9EC4
_081C9EAA:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9EBA
	bl sub_81CA89C
	cmp r0, 0
	beq _081C9EBE
_081C9EBA:
	movs r0, 0x2
	b _081C9EC4
_081C9EBE:
	bl sub_81CA9D8
_081C9EC2:
	movs r0, 0x4
_081C9EC4:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9E58

	thumb_func_start sub_81C9EC8
sub_81C9EC8: @ 81C9EC8
	push {lr}
	cmp r0, 0
	beq _081C9ED4
	cmp r0, 0x1
	beq _081C9EE2
	b _081C9EF0
_081C9ED4:
	movs r0, 0x20
	bl PlaySE
	bl sub_81CA770
	movs r0, 0
	b _081C9EF2
_081C9EE2:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C9EF0
	movs r0, 0x2
	b _081C9EF2
_081C9EF0:
	movs r0, 0x4
_081C9EF2:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9EC8

	thumb_func_start sub_81C9EF8
sub_81C9EF8: @ 81C9EF8
	push {lr}
	cmp r0, 0
	beq _081C9F04
	cmp r0, 0x1
	beq _081C9F12
	b _081C9F20
_081C9F04:
	movs r0, 0x5
	bl PlaySE
	bl sub_81CA714
	movs r0, 0
	b _081C9F22
_081C9F12:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081C9F20
	movs r0, 0x2
	b _081C9F22
_081C9F20:
	movs r0, 0x4
_081C9F22:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9EF8

	thumb_func_start sub_81C9F28
sub_81C9F28: @ 81C9F28
	push {lr}
	cmp r0, 0x1
	beq _081C9F52
	cmp r0, 0x1
	bgt _081C9F38
	cmp r0, 0
	beq _081C9F42
	b _081C9FBC
_081C9F38:
	cmp r0, 0x2
	beq _081C9F96
	cmp r0, 0x3
	beq _081C9FB0
	b _081C9FBC
_081C9F42:
	bl sub_81C98C4
	lsls r0, 16
	lsrs r0, 16
	bl sub_81C7BA4
	movs r0, 0
	b _081C9FBE
_081C9F52:
	bl sub_81C7BE8
	cmp r0, 0
	bne _081C9FB8
	bl sub_81C7880
	bl sub_81CA9C8
	bl sub_81CA2DC
	bl sub_81C9894
	cmp r0, 0x3
	beq _081C9F7A
	cmp r0, 0x4
	bne _081C9F84
	movs r0, 0x7
	movs r1, 0
	bl sub_81C7FC4
_081C9F7A:
	movs r0, 0x1
	movs r1, 0
	bl sub_81C7FC4
	b _081C9F8C
_081C9F84:
	movs r0, 0
	movs r1, 0
	bl sub_81C7FC4
_081C9F8C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	b _081C9FBE
_081C9F96:
	bl sub_81CA324
	cmp r0, 0
	bne _081C9FB8
	bl sub_81C8010
	cmp r0, 0
	bne _081C9FB8
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081C9FBE
_081C9FB0:
	bl sub_81C7B34
	cmp r0, 0
	beq _081C9FBC
_081C9FB8:
	movs r0, 0x2
	b _081C9FBE
_081C9FBC:
	movs r0, 0x4
_081C9FBE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9F28

	thumb_func_start sub_81C9FC4
sub_81C9FC4: @ 81C9FC4
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_086201C4
_081C9FCA:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x1
	bls _081C9FCA
	ldr r0, =gUnknown_086201D4
	bl sub_81C795C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C9FC4

	thumb_func_start sub_81C9FEC
sub_81C9FEC: @ 81C9FEC
	push {lr}
	movs r0, 0x3
	bl FreeSpriteTilesByTag
	movs r0, 0x1
	bl FreeSpriteTilesByTag
	movs r0, 0x4
	bl FreeSpritePaletteByTag
	movs r0, 0x5
	bl FreeSpritePaletteByTag
	movs r0, 0x6
	bl FreeSpritePaletteByTag
	movs r0, 0x7
	bl FreeSpritePaletteByTag
	movs r0, 0x8
	bl FreeSpritePaletteByTag
	movs r0, 0x3
	bl FreeSpritePaletteByTag
	bl sub_81CA094
	bl sub_81CA698
	pop {r0}
	bx r0
	thumb_func_end sub_81C9FEC

	thumb_func_start sub_81CA02C
sub_81CA02C: @ 81CA02C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x2
	bl sub_81C763C
	movs r2, 0
	adds r0, 0x2C
	mov r8, r0
_081CA03E:
	movs r4, 0
	lsls r0, r2, 2
	lsls r1, r2, 4
	adds r7, r2, 0x1
	adds r0, r2
	lsls r0, 18
	movs r2, 0xA0
	lsls r2, 14
	adds r5, r0, r2
	mov r0, r8
	adds r6, r1, r0
_081CA054:
	ldr r0, =gUnknown_0862034C
	movs r1, 0x8C
	asrs r2, r5, 16
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	stm r6!, {r1}
	lsls r0, r4, 5
	strh r0, [r1, 0x24]
	adds r4, 0x1
	cmp r4, 0x3
	ble _081CA054
	adds r2, r7, 0
	cmp r2, 0x5
	ble _081CA03E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA02C

	thumb_func_start sub_81CA094
sub_81CA094: @ 81CA094
	push {r4-r7,lr}
	movs r0, 0x2
	bl sub_81C763C
	movs r1, 0
	adds r7, r0, 0
	adds r7, 0x2C
_081CA0A2:
	lsls r0, r1, 4
	adds r6, r1, 0x1
	adds r4, r0, r7
	movs r5, 0x3
_081CA0AA:
	ldr r0, [r4]
	bl FreeSpriteOamMatrix
	ldm r4!, {r0}
	bl DestroySprite
	subs r5, 0x1
	cmp r5, 0
	bge _081CA0AA
	adds r1, r6, 0
	cmp r1, 0x5
	ble _081CA0A2
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA094

	thumb_func_start sub_81CA0C8
sub_81CA0C8: @ 81CA0C8
	push {lr}
	bl sub_81C9894
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	ldr r1, =gUnknown_08620244
	adds r0, r2, r1
	subs r1, 0x4
	adds r2, r1
	ldrh r1, [r2]
	ldrh r2, [r2, 0x2]
	bl sub_81CA0EC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA0C8

	thumb_func_start sub_81CA0EC
sub_81CA0EC: @ 81CA0EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	str r1, [sp, 0x14]
	str r2, [sp]
	movs r0, 0x2
	bl sub_81C763C
	mov r10, r0
	movs r0, 0x3
	bl GetSpriteTileStartByTag
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r1, 0
_081CA114:
	ldr r0, [r6]
	cmp r0, 0
	beq _081CA1B0
	movs r5, 0
	lsls r2, r1, 4
	mov r0, r10
	adds r0, 0x2C
	lsls r3, r1, 2
	mov r9, r3
	movs r4, 0x10
	add r4, r10
	mov r8, r4
	adds r7, r6, 0x4
	str r7, [sp, 0xC]
	ldr r3, [sp, 0x14]
	ldr r4, [sp]
	adds r3, r4
	str r3, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r4, r2, r0
_081CA13E:
	ldr r3, [r4]
	ldr r0, [r6]
	ldrh r2, [r0]
	ldr r7, [sp, 0x4]
	adds r2, r7
	lsls r0, r5, 3
	adds r2, r0
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r2, r0
	ldrh r0, [r3, 0x4]
	ldr r7, =0xfffffc00
	adds r1, r7, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x4]
	ldr r0, [r6]
	ldrh r0, [r0, 0x2]
	adds r0, 0x4
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	ldr r3, [r4]
	lsls r0, 4
	ldrb r2, [r3, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	ldr r2, [r4]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r4]
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0x22]
	ldr r1, [r4]
	movs r0, 0x8C
	strh r0, [r1, 0x20]
	ldm r4!, {r1}
	lsls r0, r5, 5
	strh r0, [r1, 0x24]
	adds r5, 0x1
	cmp r5, 0x3
	ble _081CA13E
	mov r1, r8
	add r1, r9
	movs r0, 0x1
	b _081CA1EC
	.pool
_081CA1B0:
	lsls r2, r1, 4
	mov r0, r10
	adds r0, 0x2C
	lsls r3, r1, 2
	mov r9, r3
	movs r4, 0x10
	add r4, r10
	mov r8, r4
	adds r6, 0x4
	str r6, [sp, 0xC]
	ldr r7, [sp, 0x14]
	ldr r3, [sp]
	adds r7, r3
	str r7, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	movs r3, 0x4
	adds r2, r0
	movs r5, 0x3
_081CA1D6:
	ldm r2!, {r1}
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _081CA1D6
	mov r1, r8
	add r1, r9
	movs r0, 0
_081CA1EC:
	str r0, [r1]
	ldr r6, [sp, 0xC]
	ldr r4, [sp, 0x8]
	str r4, [sp, 0x14]
	ldr r1, [sp, 0x10]
	cmp r1, 0x5
	ble _081CA114
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA0EC

	thumb_func_start sub_81CA20C
sub_81CA20C: @ 81CA20C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x2
	bl sub_81C763C
	adds r6, r0, 0
	bl sub_81C98A4
	mov r8, r0
	movs r7, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0x2C
_081CA228:
	lsls r0, r5, 2
	adds r1, r6, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA25C
	adds r0, r7, 0
	adds r7, 0x1
	cmp r0, r8
	bne _081CA244
	movs r2, 0x82
	strb r5, [r6, 0xB]
	b _081CA246
_081CA244:
	movs r2, 0x8C
_081CA246:
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 1
	movs r3, 0xC
	bl sub_81CA35C
	adds r0, r4, 0
	movs r1, 0
	bl sub_81CA448
	b _081CA264
_081CA25C:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81CA448
_081CA264:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CA228
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA20C

	thumb_func_start sub_81CA278
sub_81CA278: @ 81CA278
	push {r4,r5,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C98A4
	adds r3, r0, 0
	movs r2, 0
	movs r5, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _081CA298
	cmp r5, r3
	beq _081CA2B2
_081CA296:
	adds r5, 0x1
_081CA298:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _081CA2B2
	lsls r0, r2, 2
	adds r1, r4, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA298
	cmp r5, r3
	bne _081CA296
	adds r5, r2, 0
_081CA2B2:
	ldrb r0, [r4, 0xB]
	lsls r0, 4
	adds r0, 0x2C
	adds r0, r4, r0
	movs r1, 0x82
	movs r2, 0x8C
	movs r3, 0x4
	bl sub_81CA35C
	lsls r0, r5, 4
	adds r0, 0x2C
	adds r0, r4, r0
	movs r1, 0x8C
	movs r2, 0x82
	movs r3, 0x4
	bl sub_81CA35C
	strb r5, [r4, 0xB]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA278

	thumb_func_start sub_81CA2DC
sub_81CA2DC: @ 81CA2DC
	push {r4-r6,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r6, r0, 0
	movs r5, 0
	adds r4, r6, 0
	adds r4, 0x2C
_081CA2EC:
	lsls r0, r5, 2
	adds r1, r6, 0
	adds r1, 0x10
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _081CA316
	ldrb r0, [r6, 0xB]
	cmp r0, r5
	beq _081CA310
	adds r0, r4, 0
	movs r1, 0x8C
	movs r2, 0x80
	lsls r2, 1
	movs r3, 0x8
	bl sub_81CA35C
	b _081CA316
_081CA310:
	adds r0, r4, 0
	bl sub_81CA3B4
_081CA316:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CA2EC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA2DC

	thumb_func_start sub_81CA324
sub_81CA324: @ 81CA324
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r3, r0, 0
	movs r2, 0
	ldr r4, =SpriteCallbackDummy
	adds r1, r3, 0
	adds r1, 0x2C
_081CA336:
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	cmp r0, r4
	bne _081CA354
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x5
	ble _081CA336
	ldrb r0, [r3, 0xC]
	cmp r0, 0
	bne _081CA354
	movs r0, 0
	b _081CA356
	.pool
_081CA354:
	movs r0, 0x1
_081CA356:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CA324

	thumb_func_start sub_81CA35C
sub_81CA35C: @ 81CA35C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r9, r2
	adds r6, r3, 0
	ldr r0, =sub_81CA474
	mov r8, r0
	subs r0, r2, r5
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	adds r3, r0, 0
	movs r1, 0x3
	lsls r2, r5, 4
_081CA380:
	ldr r0, [r4]
	strh r5, [r0, 0x20]
	ldr r0, [r4]
	strh r6, [r0, 0x2E]
	ldr r0, [r4]
	strh r3, [r0, 0x30]
	ldr r0, [r4]
	strh r2, [r0, 0x32]
	ldr r0, [r4]
	mov r7, r9
	strh r7, [r0, 0x3C]
	ldm r4!, {r0}
	mov r7, r8
	str r7, [r0, 0x1C]
	subs r1, 0x1
	cmp r1, 0
	bge _081CA380
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA35C

	thumb_func_start sub_81CA3B4
sub_81CA3B4: @ 81CA3B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	movs r0, 0x2
	bl sub_81C763C
	adds r7, r0, 0
	movs r5, 0
	mov r8, r5
_081CA3C8:
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r2, 0x1]
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, [r4]
	ldr r0, =sub_81CA4AC
	str r0, [r1, 0x1C]
	movs r6, 0x8
	strh r6, [r1, 0x2E]
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x30]
	ldr r0, [r4]
	strh r5, [r0, 0x3C]
	ldr r0, [r4]
	bl InitSpriteAffineAnim
	ldm r4!, {r0}
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r5, 0x1
	cmp r5, 0x3
	ble _081CA3C8
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =sub_81CA580
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0x8]
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
	strb r0, [r7, 0xC]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA3B4

	thumb_func_start sub_81CA448
sub_81CA448: @ 81CA448
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x1
	ands r1, r0
	lsls r4, r1, 2
	movs r6, 0x5
	negs r6, r6
	movs r3, 0x3
_081CA458:
	ldm r5!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CA458
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA448

	thumb_func_start sub_81CA474
sub_81CA474: @ 81CA474
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081CA49A
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	b _081CA4A2
_081CA49A:
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081CA4A2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA474

	thumb_func_start sub_81CA4AC
sub_81CA4AC: @ 81CA4AC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081CA574
	movs r0, 0x30
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081CA4E2
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x24]
	b _081CA578
_081CA4E2:
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	asrs r1, r0, 3
	adds r0, r1, 0
	subs r0, 0x20
	lsrs r1, r0, 31
	adds r0, r1
	asrs r1, r0, 1
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _081CA518
	cmp r0, 0x1
	bgt _081CA50A
	cmp r0, 0
	beq _081CA514
	b _081CA526
_081CA50A:
	cmp r0, 0x2
	beq _081CA51C
	cmp r0, 0x3
	beq _081CA520
	b _081CA526
_081CA514:
	negs r1, r1
	b _081CA520
_081CA518:
	negs r0, r1
	b _081CA524
_081CA51C:
	strh r1, [r4, 0x24]
	b _081CA526
_081CA520:
	lsls r0, r1, 1
	adds r0, r1
_081CA524:
	strh r0, [r4, 0x24]
_081CA526:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CA578
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	lsrs r1, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	adds r0, r4, 0
	movs r3, 0
	bl CalcCenterToCornerVec
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0xD
	negs r1, r1
	ands r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	b _081CA578
	.pool
_081CA574:
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
_081CA578:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA4AC

	thumb_func_start sub_81CA580
sub_81CA580: @ 81CA580
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, 0
	ldrsh r2, [r4, r1]
	cmp r2, 0
	bne _081CA634
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _081CA5AC
	cmp r1, 0x1
	beq _081CA5CC
	b _081CA638
	.pool
_081CA5AC:
	movs r0, 0x10
	strh r0, [r4, 0x4]
	strh r2, [r4, 0x6]
	movs r1, 0xFC
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _081CA638
_081CA5CC:
	ldrh r0, [r4, 0x8]
	ands r1, r0
	cmp r1, 0
	beq _081CA5E4
	ldrh r0, [r4, 0x4]
	subs r0, 0x3
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	bge _081CA5F6
	strh r2, [r4, 0x4]
	b _081CA5F6
_081CA5E4:
	ldrh r0, [r4, 0x6]
	adds r0, 0x3
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081CA5F6
	movs r0, 0x10
	strh r0, [r4, 0x6]
_081CA5F6:
	ldrh r1, [r4, 0x6]
	lsls r1, 8
	ldrh r0, [r4, 0x4]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _081CA638
	movs r0, 0x2
	bl sub_81C763C
	ldrb r1, [r0, 0xC]
	subs r1, 0x1
	strb r1, [r0, 0xC]
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	b _081CA638
_081CA634:
	subs r0, 0x1
	strh r0, [r4]
_081CA638:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA580

	thumb_func_start sub_81CA640
sub_81CA640: @ 81CA640
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_0862036C
	movs r1, 0x10
	movs r2, 0x60
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x28]
	bl sub_81C98D4
	cmp r0, 0
	beq _081CA684
	ldr r1, [r4, 0x28]
	ldr r0, =sub_81CA6AC
	str r0, [r1, 0x1C]
	b _081CA690
	.pool
_081CA684:
	ldr r0, [r4, 0x28]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081CA690:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA640

	thumb_func_start sub_81CA698
sub_81CA698: @ 81CA698
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldr r0, [r0, 0x28]
	bl DestroySprite
	pop {r0}
	bx r0
	thumb_func_end sub_81CA698

	thumb_func_start sub_81CA6AC
sub_81CA6AC: @ 81CA6AC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081CA6DA
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
_081CA6DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81CA6AC

	thumb_func_start sub_81CA6E0
sub_81CA6E0: @ 81CA6E0
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =gUnknown_086202CC
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA6E0

	thumb_func_start sub_81CA714
sub_81CA714: @ 81CA714
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	bl sub_81C98B4
	ldr r1, =gUnknown_086202D4
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030C
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA714

	thumb_func_start sub_81CA770
sub_81CA770: @ 81CA770
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl sub_81C763C
	adds r5, r0, 0
	ldr r6, =gText_NoRibbonWinners
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030F
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA770

	thumb_func_start sub_81CA7C4
sub_81CA7C4: @ 81CA7C4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CA7C4

	thumb_func_start sub_81CA7D4
sub_81CA7D4: @ 81CA7D4
	push {r4,lr}
	movs r0, 0x2
	bl sub_81C763C
	adds r4, r0, 0
	ldr r0, =sub_81CA808
	movs r1, 0x2
	bl CreateTask
	strb r0, [r4, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA7D4

	thumb_func_start sub_81CA7F4
sub_81CA7F4: @ 81CA7F4
	push {lr}
	movs r0, 0x2
	bl sub_81C763C
	ldrb r0, [r0, 0xA]
	bl DestroyTask
	pop {r0}
	bx r0
	thumb_func_end sub_81CA7F4

	thumb_func_start sub_81CA808
sub_81CA808: @ 81CA808
	push {lr}
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgX
	pop {r0}
	bx r0
	thumb_func_end sub_81CA808

	thumb_func_start sub_81CA818
sub_81CA818: @ 81CA818
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC78 + 2
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	adds r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA818

	thumb_func_start sub_81CA850
sub_81CA850: @ 81CA850
	push {lr}
	ldr r0, =gUnknown_0861FC78 + 0xE
	movs r1, 0x31
	movs r2, 0x4
	bl sub_81C7944
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA850

	thumb_func_start sub_81CA864
sub_81CA864: @ 81CA864
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC78 + 0xE
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	subs r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA864

	thumb_func_start sub_81CA89C
sub_81CA89C: @ 81CA89C
	push {lr}
	ldr r0, =sub_81CA8B0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CA89C

	thumb_func_start sub_81CA8B0
sub_81CA8B0: @ 81CA8B0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r5, r0, 0
	adds r0, r6, 0
	movs r1, 0x3
	bl GetWordTaskArg
	adds r1, r0, 0
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0xC
	bl sub_81C79BC
	add r0, sp, 0x8
	movs r1, 0x31
	movs r2, 0x4
	bl LoadPalette
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _081CA908
	adds r0, r6, 0
	bl DestroyTask
_081CA908:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA8B0

	thumb_func_start sub_81CA914
sub_81CA914: @ 81CA914
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	thumb_func_end sub_81CA914

	thumb_func_start titlescreen_0
titlescreen_0: @ 81CA92C
	push {lr}
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuRegBits
	movs r0, 0x4A
	movs r1, 0x1F
	bl SetGpuRegBits
	movs r0, 0x44
	movs r1, 0xA0
	bl SetGpuRegBits
	bl ScanlineEffect_Stop
	bl sub_81CAA3C
	ldr r2, =gUnknown_08620384
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl ScanlineEffect_SetParams
	ldr r0, =sub_81CA914
	bl c3args_set_0toR1_1to0
	ldr r0, =sub_81CA9EC
	movs r1, 0x3
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end titlescreen_0

	thumb_func_start sub_81CA994
sub_81CA994: @ 81CA994
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	bl ScanlineEffect_Stop
	ldr r0, =sub_81CA9EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl sub_81C760C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA994

	thumb_func_start sub_81CA9C8
sub_81CA9C8: @ 81CA9C8
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9C8

	thumb_func_start sub_81CA9D8
sub_81CA9D8: @ 81CA9D8
	push {lr}
	bl sub_81CAA3C
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9D8

	thumb_func_start sub_81CA9EC
sub_81CA9EC: @ 81CA9EC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	ble _081CAA30
	movs r0, 0
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x3
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2, 0x2]
	ldr r1, =gSineTable
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 21
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x54
	bl SetGpuReg
_081CAA30:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA9EC

	thumb_func_start sub_81CAA3C
sub_81CAA3C: @ 81CAA3C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	bl sub_81C9894
	adds r4, r0, 0
	bl sub_81C98A4
	ldr r2, =gUnknown_08620240
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x2]
	adds r4, r2, 0
	muls r4, r0
	ldrh r1, [r1]
	adds r4, r1
	subs r4, 0x8
	mov r0, sp
	movs r6, 0
	strh r6, [r0]
	ldr r5, =gScanlineEffectRegBuffers
	ldr r0, =0x010000a0
	mov r8, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	strh r6, [r0]
	movs r1, 0xF0
	lsls r1, 3
	adds r1, r5
	mov r9, r1
	mov r2, r8
	bl CpuSet
	add r0, sp, 0x4
	ldr r1, =0x000072f0
	adds r6, r1, 0
	strh r6, [r0]
	lsls r4, 1
	adds r5, r4, r5
	ldr r1, =0x01000010
	mov r8, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	add r4, r9
	adds r1, r4, 0
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
	thumb_func_end sub_81CAA3C

	thumb_func_start sub_81CAADC
sub_81CAADC: @ 81CAADC
	push {lr}
	bl sub_81CA9C8
	pop {r0}
	bx r0
	thumb_func_end sub_81CAADC

	thumb_func_start sub_81CAAE8
sub_81CAAE8: @ 81CAAE8
	push {r4,lr}
	movs r1, 0xD4
	lsls r1, 1
	movs r0, 0x5
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CAB1C
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0
	strh r0, [r4, 0x8]
	str r0, [r4, 0x10]
	ldr r0, =sub_81CAD20
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CAB1E
	.pool
_081CAB1C:
	movs r0, 0
_081CAB1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAAE8

	thumb_func_start sub_81CAB24
sub_81CAB24: @ 81CAB24
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB24

	thumb_func_start sub_81CAB38
sub_81CAB38: @ 81CAB38
	push {lr}
	movs r0, 0x5
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CAB38

	thumb_func_start sub_81CAB44
sub_81CAB44: @ 81CAB44
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r3, =gMain
	ldrh r1, [r3, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAB5C
	movs r0, 0x2
	b _081CABF4
	.pool
_081CAB5C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAB68
	movs r0, 0x1
	b _081CABF4
_081CAB68:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CAB74
	movs r0, 0x4
	b _081CABF4
_081CAB74:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CAB84
	movs r0, 0x3
	b _081CABF4
_081CAB84:
	ldrh r1, [r3, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081CABD0
	ldr r0, =sub_81CAC04
	str r0, [r4, 0x18]
	strh r2, [r4]
	bl sub_81C875C
	lsls r0, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	beq _081CABAE
	ldrh r0, [r1, 0x1E]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CABC0
_081CABAE:
	ldr r0, =gUnknown_0862250A
	str r0, [r4, 0x4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	b _081CABC6
	.pool
_081CABC0:
	ldr r0, =gUnknown_08622508
	str r0, [r4, 0x4]
	strh r5, [r4, 0x2]
_081CABC6:
	movs r0, 0x5
	b _081CABF4
	.pool
_081CABD0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CABF2
	bl sub_81C767C
	cmp r0, 0x1
	beq _081CABEC
	ldr r0, =sub_81CABFC
	str r0, [r4, 0x18]
	movs r0, 0xF
	b _081CABF4
	.pool
_081CABEC:
	movs r0, 0x20
	bl PlaySE
_081CABF2:
	movs r0, 0
_081CABF4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAB44

	thumb_func_start sub_81CABFC
sub_81CABFC: @ 81CABFC
	ldr r0, =0x000186a4
	bx lr
	.pool
	thumb_func_end sub_81CABFC

	thumb_func_start sub_81CAC04
sub_81CAC04: @ 81CAC04
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CAC24
	ldrh r0, [r4]
	cmp r0, 0
	beq _081CAC24
	subs r0, 0x1
	b _081CAC38
	.pool
_081CAC24:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CAC3E
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	cmp r0, r1
	bcs _081CAC3E
	adds r0, 0x1
_081CAC38:
	strh r0, [r4]
	movs r0, 0x6
	b _081CACAC
_081CAC3E:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CAC98
	ldrh r1, [r4]
	ldr r0, [r4, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CAC8C
	cmp r0, 0x1
	bgt _081CAC5E
	cmp r0, 0
	beq _081CAC64
	b _081CAC98
_081CAC5E:
	cmp r0, 0x2
	bne _081CAC98
	b _081CACA6
_081CAC64:
	bl sub_81C767C
	cmp r0, 0x1
	bne _081CAC72
	movs r0, 0x2
	bl sub_81C7688
_081CAC72:
	ldr r0, =sub_81CACF8
	str r0, [r4, 0x18]
	bl sub_81CB1D0
	cmp r0, 0
	beq _081CAC88
	movs r0, 0x9
	b _081CACAC
	.pool
_081CAC88:
	movs r0, 0x8
	b _081CACAC
_081CAC8C:
	ldr r0, =sub_81CACB8
	str r0, [r4, 0x18]
	movs r0, 0xB
	b _081CACAC
	.pool
_081CAC98:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACA6
	movs r0, 0
	b _081CACAC
_081CACA6:
	ldr r0, =sub_81CAB44
	str r0, [r4, 0x18]
	movs r0, 0x7
_081CACAC:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAC04

	thumb_func_start sub_81CACB8
sub_81CACB8: @ 81CACB8
	push {lr}
	adds r3, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CACD0
	movs r0, 0xC
	b _081CACF0
	.pool
_081CACD0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CACDC
	movs r0, 0xD
	b _081CACF0
_081CACDC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CACEA
	movs r0, 0
	b _081CACF0
_081CACEA:
	ldr r0, =sub_81CAB44
	str r0, [r3, 0x18]
	movs r0, 0xE
_081CACF0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACB8

	thumb_func_start sub_81CACF8
sub_81CACF8: @ 81CACF8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081CAD10
	movs r0, 0
	b _081CAD16
	.pool
_081CAD10:
	ldr r0, =sub_81CAB44
	str r0, [r2, 0x18]
	movs r0, 0xA
_081CAD16:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CACF8

	thumb_func_start sub_81CAD20
sub_81CAD20: @ 81CAD20
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x1
	beq _081CAD4C
	cmp r5, 0x1
	bgt _081CAD3A
	cmp r5, 0
	beq _081CAD44
	b _081CAE00
_081CAD3A:
	cmp r5, 0x2
	beq _081CAD9C
	cmp r5, 0x3
	beq _081CADFC
	b _081CAE00
_081CAD44:
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
_081CAD48:
	movs r0, 0x1
	b _081CAE02
_081CAD4C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
_081CAD50:
	adds r0, r5, 0
	bl MatchCallFlagGetByIndex
	cmp r0, 0
	beq _081CAD80
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strh r5, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81D16DC
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CAD80:
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	movs r2, 0
	strh r1, [r4, 0x8]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x14
	bhi _081CADF6
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CAD50
	movs r0, 0x3
	b _081CAE02
_081CAD9C:
	movs r6, 0
	ldrh r5, [r4, 0x8]
	movs r7, 0
_081CADA2:
	ldrh r0, [r4, 0x8]
	bl sub_81D1BF8
	cmp r0, 0
	bne _081CADDC
	ldrh r0, [r4, 0x8]
	bl sub_81CAE08
	cmp r0, 0
	beq _081CADDC
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	ldrh r1, [r4, 0x8]
	strh r1, [r0, 0x1E]
	ldrh r0, [r4, 0xA]
	lsls r0, 2
	adds r0, r4, r0
	strb r7, [r0, 0x1C]
	adds r0, r5, 0
	bl sub_81CB0C8
	ldrh r1, [r4, 0xA]
	lsls r1, 2
	adds r1, r4, r1
	strb r0, [r1, 0x1D]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_081CADDC:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4D
	bhi _081CAD48
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, 0x1D
	ble _081CADA2
	movs r0, 0x3
	b _081CAE02
_081CADF6:
	strh r1, [r4, 0xC]
	strh r2, [r4, 0x8]
	b _081CAD48
_081CADFC:
	movs r0, 0x1
	str r0, [r4, 0x10]
_081CAE00:
	movs r0, 0x4
_081CAE02:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAD20

	thumb_func_start sub_81CAE08
sub_81CAE08: @ 81CAE08
	push {lr}
	cmp r0, 0x4D
	ble _081CAE12
	movs r0, 0
	b _081CAE24
_081CAE12:
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
_081CAE24:
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE08

	thumb_func_start sub_81CAE28
sub_81CAE28: @ 81CAE28
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldr r0, [r0, 0x10]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE28

	thumb_func_start sub_81CAE38
sub_81CAE38: @ 81CAE38
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0, 0xA]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE38

	thumb_func_start sub_81CAE48
sub_81CAE48: @ 81CAE48
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE48

	thumb_func_start sub_81CAE58
sub_81CAE58: @ 81CAE58
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	ldrh r1, [r1, 0xC]
	subs r0, r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE58

	thumb_func_start sub_81CAE6C
sub_81CAE6C: @ 81CAE6C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r4, r0
	ldrh r0, [r1, 0xA]
	cmp r4, r0
	bge _081CAE8A
	lsls r0, r4, 2
	adds r0, r1, r0
	ldrh r0, [r0, 0x1E]
	b _081CAE8C
_081CAE8A:
	movs r0, 0x4E
_081CAE8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE6C

	thumb_func_start sub_81CAE94
sub_81CAE94: @ 81CAE94
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r0, 0x1C
	pop {r1}
	bx r1
	thumb_func_end sub_81CAE94

	thumb_func_start sub_81CAEA4
sub_81CAEA4: @ 81CAEA4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r4, 2
	adds r0, r4
	ldrb r0, [r0, 0x1D]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEA4

	thumb_func_start sub_81CAEBC
sub_81CAEBC: @ 81CAEBC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAED4
	ldrh r4, [r1, 0x1E]
	b _081CAEDC
_081CAED4:
	ldrh r0, [r1, 0x1E]
	bl MatchCall_GetRematchTableIdx
	adds r4, r0, 0
_081CAEDC:
	cmp r4, 0x4E
	beq _081CAEFC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _081CAEFE
	.pool
_081CAEFC:
	movs r0, 0
_081CAEFE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CAEBC

	thumb_func_start sub_81CAF04
sub_81CAF04: @ 81CAF04
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r1, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAF34
	ldrh r0, [r1, 0x1E]
	bl GetTrainerIdxByRematchIdx
	adds r4, r0, 0
	ldr r1, =gTrainers
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x3]
	b _081CAF6C
	.pool
_081CAF34:
	ldrh r5, [r1, 0x1E]
	adds r0, r5, 0
	bl MatchCall_GetRematchTableIdx
	adds r4, r0, 0
	cmp r4, 0x4E
	bne _081CAF58
	adds r0, r5, 0
	bl sub_81D1BD0
	adds r4, r0, 0
	ldr r0, =gFacilityClassToPicIndex
	adds r0, r4, r0
	ldrb r0, [r0]
	b _081CAF6C
	.pool
_081CAF58:
	adds r0, r4, 0
	bl GetTrainerIdxByRematchIdx
	adds r4, r0, 0
	ldr r0, =gTrainers
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x3]
_081CAF6C:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF04

	thumb_func_start sub_81CAF78
sub_81CAF78: @ 81CAF78
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0
	strb r0, [r6]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	bl Overworld_MapTypeAllowsTeleportAndFly
	lsls r0, 24
	cmp r0, 0
	bne _081CAFA4
	ldr r0, =gText_CallCantBeMadeHere
	b _081CAFCE
	.pool
_081CAFA4:
	lsls r0, r5, 2
	adds r1, r4, r0
	ldrb r0, [r1, 0x1C]
	cmp r0, 0
	bne _081CAFC4
	ldrh r0, [r1, 0x1E]
	bl GetTrainerIdxByRematchIdx
	ldr r1, =gStringVar4
	bl SelectMatchCallMessage
	strb r0, [r6]
	b _081CAFCC
	.pool
_081CAFC4:
	ldrh r0, [r1, 0x1E]
	ldr r1, =gStringVar4
	bl MatchCall_GetMessage
_081CAFCC:
	ldr r0, =gStringVar4
_081CAFCE:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAF78

	thumb_func_start sub_81CAFD8
sub_81CAFD8: @ 81CAFD8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x5
	bl sub_81C763C
	lsls r4, 2
	adds r4, r0, r4
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CB004
	ldrh r0, [r4, 0x1E]
	bl MatchCall_GetRematchTableIdx
	adds r1, r0, 0
	cmp r1, 0x4E
	bne _081CB006
	ldrh r0, [r4, 0x1E]
	adds r1, r5, 0
	bl sub_81D1B40
	b _081CB012
_081CB004:
	ldrh r1, [r4, 0x1E]
_081CB006:
	ldr r2, =gUnknown_08622028
	lsls r0, r5, 2
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
_081CB012:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CAFD8

	thumb_func_start sub_81CB01C
sub_81CB01C: @ 81CB01C
	push {lr}
	movs r0, 0x5
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CB01C

	thumb_func_start sub_81CB02C
sub_81CB02C: @ 81CB02C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0x2]
	cmp r0, r4
	blt _081CB046
	ldr r0, [r1, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB048
_081CB046:
	movs r0, 0x3
_081CB048:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB02C

	thumb_func_start sub_81CB050
sub_81CB050: @ 81CB050
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _081CB088
	ldrh r0, [r2, 0x2]
	bl GetTrainerIdxByRematchIdx
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTrainers
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	muls r0, r2
	ldr r2, =gTrainerClassNames
	adds r0, r2
	str r0, [sp]
	adds r1, 0x4
	str r1, [sp, 0x4]
	b _081CB092
	.pool
_081CB088:
	ldrh r0, [r2, 0x2]
	add r2, sp, 0x4
	mov r1, sp
	bl sub_81D1A78
_081CB092:
	ldr r2, [sp]
	cmp r2, 0
	beq _081CB0B4
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _081CB0B4
	adds r0, r4, 0
	movs r1, 0x7
	movs r3, 0x45
	bl sub_81DB494
	ldr r2, [sp, 0x4]
	movs r1, 0x7
	movs r3, 0x33
	bl sub_81DB494
	b _081CB0C0
_081CB0B4:
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0
	movs r3, 0x78
	bl sub_81DB494
_081CB0C0:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB050

	thumb_func_start sub_81CB0C8
sub_81CB0C8: @ 81CB0C8
	push {lr}
	ldr r1, =gRematchTable
	lsls r0, 4
	adds r0, r1
	ldrh r2, [r0, 0xA]
	ldrh r1, [r0, 0xC]
	adds r0, r2, 0
	bl Overworld_GetMapHeaderByGroupAndId
	ldrb r0, [r0, 0x14]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CB0C8

	thumb_func_start sub_81CB0E4
sub_81CB0E4: @ 81CB0E4
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r7, r0, 0
	movs r6, 0x1
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	bge _081CB120
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r7
_081CB100:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB110
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB114
_081CB110:
	adds r0, r6, 0
	b _081CB122
_081CB114:
	adds r6, 0x1
	adds r4, 0x4
	adds r5, 0x1
	ldrh r0, [r7, 0xA]
	cmp r5, r0
	blt _081CB100
_081CB120:
	movs r0, 0
_081CB122:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB0E4

	thumb_func_start sub_81CB128
sub_81CB128: @ 81CB128
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x5
	bl sub_81C763C
	adds r1, r0, 0
	movs r6, 0x1
	negs r6, r6
	subs r5, 0x1
	cmp r5, 0
	blt _081CB162
	lsls r0, r5, 2
	adds r0, 0x1C
	adds r4, r0, r1
_081CB144:
	ldrb r0, [r4]
	cmp r0, 0
	beq _081CB154
	ldrh r0, [r4, 0x2]
	bl sub_81D17E8
	cmp r0, 0
	beq _081CB158
_081CB154:
	adds r0, r6, 0
	b _081CB164
_081CB158:
	subs r6, 0x1
	subs r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _081CB144
_081CB162:
	movs r0, 0
_081CB164:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB128

	thumb_func_start sub_81CB16C
sub_81CB16C: @ 81CB16C
	push {r4,lr}
	movs r4, 0
_081CB170:
	adds r0, r4, 0
	bl sub_81CAE08
	cmp r0, 0
	beq _081CB18A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CB1B2
_081CB18A:
	adds r4, 0x1
	cmp r4, 0x4D
	ble _081CB170
	movs r4, 0
_081CB192:
	adds r0, r4, 0
	bl MatchCallFlagGetByIndex
	cmp r0, 0
	beq _081CB1C0
	adds r0, r4, 0
	bl MatchCall_GetRematchTableIdx
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x000009ca
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _081CB1C0
_081CB1B2:
	movs r0, 0x1
	b _081CB1C8
	.pool
_081CB1C0:
	adds r4, 0x1
	cmp r4, 0x14
	ble _081CB192
	movs r0, 0
_081CB1C8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB16C

	thumb_func_start sub_81CB1D0
sub_81CB1D0: @ 81CB1D0
	push {r4,lr}
	movs r0, 0x5
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r4, r0
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _081CB218
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000009ca
	adds r0, r1
	ldrh r4, [r4, 0x1E]
	adds r0, r4
	ldrb r0, [r0]
	b _081CB246
	.pool
_081CB218:
	ldrh r0, [r4, 0x1E]
	cmp r0, 0xB
	bne _081CB258
	adds r0, r1, 0
	bl sub_81CAEA4
	ldr r1, =gMapHeader
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x14]
	cmp r0, r1
	bne _081CB258
	ldr r0, =0x0000086b
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081CB258
	movs r0, 0x5B
	bl FlagGet
	lsls r0, 24
_081CB246:
	cmp r0, 0
	bne _081CB258
	movs r0, 0x1
	b _081CB25A
	.pool
_081CB258:
	movs r0, 0
_081CB25A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CB1D0

	thumb_func_start sub_81CB260
sub_81CB260: @ 81CB260
	push {r4,lr}
	ldr r1, =0x00002048
	movs r0, 0x6
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CB294
	movs r0, 0
	strb r0, [r4, 0x19]
	ldr r0, =sub_81CB324
	movs r1, 0x1
	bl sub_81C7078
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
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08622798
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
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
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CB2CC

	thumb_func_start sub_81CB2E0
sub_81CB2E0: @ 81CB2E0
	push {r4,lr}
	movs r0, 0x6
	bl sub_81C763C
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
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CB2E0

	thumb_func_start sub_81CB310
sub_81CB310: @ 81CB310
	push {lr}
	movs r0, 0x6
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CB310

	thumb_func_start sub_81CB324
sub_81CB324: @ 81CB324
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_81C763C
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
	bl sub_81C7B54
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
	bl sub_81C7944
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
	bl sub_81C7944
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
	bl sub_81C7944
	ldr r0, =gUnknown_08622720
	movs r1, 0x50
	movs r2, 0x20
	bl sub_81C7944
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
	bl sub_81C7DFC
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081CB506
_081CB4EA:
	bl sub_81C7B34
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
	bl sub_81C763C
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
	bl sub_81C868C
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
	bl sub_81C763C
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
	bl sub_81C8658
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
	bl sub_81C763C
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
	bl sub_81C870C
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
	bl sub_81C763C
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
	bl sub_81C86CC
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
	bl sub_81C763C
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
	bl sub_81C763C
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
	bl sub_81C763C
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
	bl sub_81C763C
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
	bl sub_81C9148
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
	bl sub_81C763C
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
	bl sub_81C9148
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
	bl sub_81C763C
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
	bl sub_81C7BE8
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
	bl sub_81C9148
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
	bl sub_81C763C
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
	bl sub_81C7BE8
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
	bl sub_81C763C
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
	bl sub_81C8770
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
	bl sub_81C763C
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
	bl sub_81C763C
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
	bl sub_81C8770
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
	bl sub_81C7B34
	cmp r0, 0
	bne _081CBBAA
	bl sub_81C78C0
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
	ldr r0, =0x0001869f
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
	bl sub_81C875C
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
	bl sub_81C7CCC
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
	bl sub_8098858
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
	bl sub_81C875C
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
	bl sub_81C7CE4
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
	bl sub_81C763C
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
	bl sub_81C795C
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
	bl sub_81C763C
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
	bl sub_81C875C
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

	thumb_func_start sub_81CC4D4
sub_81CC4D4: @ 81CC4D4
	push {r4,lr}
	movs r0, 0x3
	movs r1, 0x14
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC4F0
	ldr r1, =0x00000884
	movs r0, 0x10
	bl sub_81C761C
	cmp r0, 0
	bne _081CC4F8
_081CC4F0:
	movs r0, 0
	b _081CC51A
	.pool
_081CC4F8:
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	bl sub_8124668
	str r0, [r4, 0xC]
	cmp r0, 0
	bne _081CC514
	ldr r0, =sub_81CC568
	b _081CC516
	.pool
_081CC514:
	ldr r0, =sub_81CC5B4
_081CC516:
	str r0, [r4, 0x10]
	movs r0, 0x1
_081CC51A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC4D4

	thumb_func_start sub_81CC524
sub_81CC524: @ 81CC524
	push {lr}
	bl sub_8124658
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3, 0x15]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x15]
	movs r0, 0x10
	bl sub_81C7650
	movs r0, 0x3
	bl sub_81C7650
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC524

	thumb_func_start sub_81CC554
sub_81CC554: @ 81CC554
	push {lr}
	movs r0, 0x3
	bl sub_81C763C
	ldr r1, [r0, 0x10]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CC554

	thumb_func_start sub_81CC568
sub_81CC568: @ 81CC568
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _081CC58C
	cmp r0, 0x4
	bgt _081CC582
	cmp r0, 0x3
	beq _081CC588
	b _081CC5AC
_081CC582:
	cmp r0, 0x5
	beq _081CC59E
	b _081CC5AC
_081CC588:
	movs r0, 0x1
	b _081CC5AE
_081CC58C:
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CC59A
	movs r0, 0x3
	b _081CC5AE
_081CC59A:
	movs r0, 0x2
	b _081CC5AE
_081CC59E:
	ldr r0, =sub_81CC5DC
	str r0, [r4, 0x10]
	movs r0, 0x4
	b _081CC5AE
	.pool
_081CC5AC:
	movs r0, 0
_081CC5AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC568

	thumb_func_start sub_81CC5B4
sub_81CC5B4: @ 81CC5B4
	push {lr}
	adds r2, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CC5CC
	movs r0, 0
	b _081CC5D2
	.pool
_081CC5CC:
	ldr r0, =sub_81CC5DC
	str r0, [r2, 0x10]
	movs r0, 0x4
_081CC5D2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CC5B4

	thumb_func_start sub_81CC5DC
sub_81CC5DC: @ 81CC5DC
	ldr r0, =0x000186a1
	bx lr
	.pool
	thumb_func_end sub_81CC5DC

	thumb_func_start sub_81CC5E4
sub_81CC5E4: @ 81CC5E4
	push {lr}
	movs r0, 0x3
	bl sub_81C763C
	ldr r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5E4

	thumb_func_start sub_81CC5F4
sub_81CC5F4: @ 81CC5F4
	push {r4,lr}
	ldr r1, =0x00001948
	movs r0, 0x4
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CC624
	ldr r0, =sub_81CC6F4
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r4]
	movs r0, 0x1
	b _081CC626
	.pool
_081CC624:
	movs r0, 0
_081CC626:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC5F4

	thumb_func_start sub_81CC62C
sub_81CC62C: @ 81CC62C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086230E4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CC6BC
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC62C

	thumb_func_start sub_81CC65C
sub_81CC65C: @ 81CC65C
	push {lr}
	movs r0, 0x4
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CC65C

	thumb_func_start sub_81CC670
sub_81CC670: @ 81CC670
	push {r4,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	bl FreeRegionMapIconResources
	bl sub_81CC9EC
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x10
	bl sub_81C7650
	movs r0, 0x4
	bl sub_81C7650
	bl sub_81C760C
	movs r0, 0
	bl SetBgMode
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC670

	thumb_func_start sub_81CC6A4
sub_81CC6A4: @ 81CC6A4
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl UpdateRegionMapVideoRegs
	pop {r0}
	bx r0
	thumb_func_end sub_81CC6A4

	thumb_func_start sub_81CC6BC
sub_81CC6BC: @ 81CC6BC
	push {lr}
	movs r0, 0x4
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6BC

	thumb_func_start sub_81CC6D0
sub_81CC6D0: @ 81CC6D0
	push {lr}
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC6EC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsrs r0, 3
	movs r1, 0x1
	ands r0, r1
	b _081CC6EE
	.pool
_081CC6EC:
	movs r0, 0
_081CC6EE:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6D0

	thumb_func_start sub_81CC6F4
sub_81CC6F4: @ 81CC6F4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x7
	bls _081CC706
	b _081CC83E
_081CC706:
	lsls r0, r4, 2
	ldr r1, =_081CC714
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CC714:
	.4byte _081CC734
	.4byte _081CC784
	.4byte _081CC7B6
	.4byte _081CC7BE
	.4byte _081CC7CE
	.4byte _081CC7E2
	.4byte _081CC804
	.4byte _081CC82A
_081CC734:
	movs r0, 0
	bl c3args_set_0toR1_1to0
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl SetBgMode
	ldr r4, =gUnknown_086230D8
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_81C7B54
	movs r0, 0x10
	bl sub_81C763C
	adds r5, r0, 0
	adds r4, 0x4
	bl sub_81CC6D0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8122CF8
	bl sub_81CC9C0
_081CC77C:
	movs r0, 0
	b _081CC840
	.pool
_081CC784:
	bl sub_8122DB0
	lsls r0, 24
	cmp r0, 0
	bne _081CC83A
	bl sub_81CC5E4
	cmp r0, 0
	bne _081CC7AC
	movs r0, 0x4
	movs r1, 0x9
	bl CreateRegionMapPlayerIcon
	movs r0, 0x5
	movs r1, 0xA
	bl CreateRegionMapCursor
	bl sub_812454C
	b _081CC77C
_081CC7AC:
	movs r0, 0
	movs r1, 0x6
	bl sub_8123030
	b _081CC77C
_081CC7B6:
	bl sub_81CCD10
_081CC7BA:
	movs r0, 0x1
	b _081CC840
_081CC7BE:
	bl sub_81CCD24
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCA1C
	b _081CC7BA
_081CC7CE:
	bl sub_81CCAFC
	cmp r0, 0
	bne _081CC83A
	adds r0, r5, 0
	bl sub_81CCB0C
	bl sub_81C7B40
	b _081CC77C
_081CC7E2:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC83A
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =sub_81CC6A4
	bl c3args_set_0toR1_1to0
	b _081CC77C
	.pool
_081CC804:
	bl sub_81CC6D0
	lsls r0, 24
	movs r4, 0x5
	cmp r0, 0
	bne _081CC812
	movs r4, 0x4
_081CC812:
	adds r0, r4, 0
	bl sub_81C7DFC
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_81C7FA0
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CC77C
_081CC82A:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CC83A
	bl sub_81C8010
	cmp r0, 0
	beq _081CC7BA
_081CC83A:
	movs r0, 0x2
	b _081CC840
_081CC83E:
	movs r0, 0x4
_081CC840:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC6F4

	thumb_func_start sub_81CC848
sub_81CC848: @ 81CC848
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	cmp r4, 0
	beq _081CC85C
	cmp r4, 0x1
	beq _081CC864
	b _081CC870
_081CC85C:
	bl sub_81CCB0C
	movs r0, 0
	b _081CC872
_081CC864:
	bl sub_81CCC4C
	cmp r0, 0
	beq _081CC870
	movs r0, 0x2
	b _081CC872
_081CC870:
	movs r0, 0x4
_081CC872:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC848

	thumb_func_start sub_81CC878
sub_81CC878: @ 81CC878
	push {lr}
	cmp r0, 0x1
	beq _081CC8A2
	cmp r0, 0x1
	bgt _081CC888
	cmp r0, 0
	beq _081CC88E
	b _081CC8D0
_081CC888:
	cmp r0, 0x2
	beq _081CC8BE
	b _081CC8D0
_081CC88E:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC8D2
_081CC8A2:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC8C6
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC8C6
	movs r0, 0x1
	bl sub_81C7BA4
	movs r0, 0
	b _081CC8D2
_081CC8BE:
	bl sub_81C7BE8
	cmp r0, 0
	beq _081CC8CA
_081CC8C6:
	movs r0, 0x2
	b _081CC8D2
_081CC8CA:
	movs r0, 0x4
	bl sub_81C7E14
_081CC8D0:
	movs r0, 0x4
_081CC8D2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC878

	thumb_func_start sub_81CC8D8
sub_81CC8D8: @ 81CC8D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CC90C
	cmp r4, 0x1
	bgt _081CC8F2
	cmp r4, 0
	beq _081CC8FC
	b _081CC952
_081CC8F2:
	cmp r4, 0x2
	beq _081CC924
	cmp r4, 0x3
	beq _081CC940
	b _081CC952
_081CC8FC:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81CCB0C
	movs r0, 0
	b _081CC954
_081CC90C:
	adds r0, r5, 0
	bl sub_81CCC4C
	cmp r0, 0
	bne _081CC948
	movs r0, 0x1
	bl sub_81CCC5C
	bl sub_8123418
	movs r0, 0
	b _081CC954
_081CC924:
	bl sub_8123514
	lsls r0, 24
	cmp r0, 0
	bne _081CC948
	bl sub_81CCC88
	cmp r0, 0
	bne _081CC948
	movs r0, 0x2
	bl sub_81C7BA4
	movs r0, 0
	b _081CC954
_081CC940:
	bl sub_81C7BE8
	cmp r0, 0
	beq _081CC94C
_081CC948:
	movs r0, 0x2
	b _081CC954
_081CC94C:
	movs r0, 0x5
	bl sub_81C7E14
_081CC952:
	movs r0, 0x4
_081CC954:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CC8D8

	thumb_func_start sub_81CC95C
sub_81CC95C: @ 81CC95C
	push {lr}
	cmp r0, 0x1
	beq _081CC982
	cmp r0, 0x1
	bgt _081CC96C
	cmp r0, 0
	beq _081CC972
	b _081CC9B8
_081CC96C:
	cmp r0, 0x2
	beq _081CC996
	b _081CC9B8
_081CC972:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CC9BA
_081CC982:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CC99E
	bl sub_81C7FDC
	bl sub_81C78A0
	movs r0, 0
	b _081CC9BA
_081CC996:
	bl sub_81C78C0
	cmp r0, 0
	beq _081CC9A2
_081CC99E:
	movs r0, 0x2
	b _081CC9BA
_081CC9A2:
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0
	b _081CC9BA
_081CC9B8:
	movs r0, 0x4
_081CC9BA:
	pop {r1}
	bx r1
	thumb_func_end sub_81CC95C

	thumb_func_start sub_81CC9C0
sub_81CC9C0: @ 81CC9C0
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_086230F8
_081CC9C6:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0
	beq _081CC9C6
	ldr r0, =gUnknown_08623100
	bl sub_81C795C
	bl sub_81CCE58
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CC9C0

	thumb_func_start sub_81CC9EC
sub_81CC9EC: @ 81CC9EC
	push {r4,r5,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x6
	bl FreeSpriteTilesByTag
	movs r0, 0xB
	bl FreeSpritePaletteByTag
	adds r5, r4, 0
	adds r5, 0xC
	movs r4, 0x2
_081CCA08:
	ldm r5!, {r0}
	bl DestroySprite
	subs r4, 0x1
	cmp r4, 0
	bge _081CCA08
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CC9EC

	thumb_func_start sub_81CCA1C
sub_81CCA1C: @ 81CCA1C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x40
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x41
	movs r3, 0x1
	bl sub_8199DF0
	add r1, sp, 0x4
	movs r2, 0x82
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	adds r4, r5, 0
	adds r4, 0x18
	ldr r2, =0x01000400
	adds r0, r1, 0
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_08623110
	bl AddWindow
	movs r4, 0
	strh r0, [r5, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x42
	movs r2, 0x40
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r5, 0x8]
	movs r1, 0x42
	movs r2, 0x4
	bl sub_8098858
	ldr r1, =gUnknown_08622888
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldrb r0, [r5, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r5, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_08622868
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =gHoennMapZoomIcons_Pal
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	bl sub_8124658
	lsls r0, 24
	cmp r0, 0
	bne _081CCAE0
	ldr r1, =0xffffa000
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	b _081CCAEA
	.pool
_081CCAE0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
_081CCAEA:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCA1C

	thumb_func_start sub_81CCAFC
sub_81CCAFC: @ 81CCAFC
	push {lr}
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCAFC

	thumb_func_start sub_81CCB0C
sub_81CCB0C: @ 81CCB0C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x10
	bl sub_81C763C
	adds r5, r0, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4
	bls _081CCB22
	b _081CCC40
_081CCB22:
	lsls r0, 2
	ldr r1, =_081CCB30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CCB30:
	.4byte _081CCC1C
	.4byte _081CCBDC
	.4byte _081CCB44
	.4byte _081CCB8E
	.4byte _081CCBDC
_081CCB44:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCD70
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl sub_81CCFA4
	b _081CCC40
_081CCB8E:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0xC
	bl PutWindowRectTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect
	b _081CCC0C
	.pool
_081CCBDC:
	ldrb r0, [r4, 0x8]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	adds r2, r5, 0x4
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrh r1, [r5]
	ldrb r2, [r5, 0x3]
	adds r0, r4, 0
	bl sub_81CCDE8
_081CCC0C:
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	bl sub_81CCFA4
	b _081CCC40
_081CCC1C:
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x4
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl sub_81CCFA4
_081CCC40:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCB0C

	thumb_func_start sub_81CCC4C
sub_81CCC4C: @ 81CCC4C
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CCC4C

	thumb_func_start sub_81CCC5C
sub_81CCC5C: @ 81CCC5C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =sub_81CCC9C
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCC5C

	thumb_func_start sub_81CCC88
sub_81CCC88: @ 81CCC88
	push {lr}
	ldr r0, =sub_81CCC9C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCC88

	thumb_func_start sub_81CCC9C
sub_81CCC9C: @ 81CCC9C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081CCCE0
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x1
	bl ChangeBgY
	cmp r0, 0
	blt _081CCCD6
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	adds r0, r4, 0
	bl DestroyTask
_081CCCD6:
	bl sub_81CCF78
	b _081CCD04
	.pool
_081CCCE0:
	movs r1, 0x90
	lsls r1, 3
	movs r0, 0x1
	movs r2, 0x2
	bl ChangeBgY
	ldr r1, =0xffffa000
	cmp r0, r1
	bgt _081CCD00
	movs r0, 0x1
	movs r2, 0
	bl ChangeBgY
	adds r0, r5, 0
	bl DestroyTask
_081CCD00:
	bl sub_81CCF78
_081CCD04:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCC9C

	thumb_func_start sub_81CCD10
sub_81CCD10: @ 81CCD10
	push {lr}
	ldr r0, =sub_81CCD34
	movs r1, 0x1
	bl sub_81C7078
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD10

	thumb_func_start sub_81CCD24
sub_81CCD24: @ 81CCD24
	push {lr}
	ldr r0, =sub_81CCD34
	bl sub_81C7124
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD24

	thumb_func_start sub_81CCD34
sub_81CCD34: @ 81CCD34
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	adds r2, r0, 0
	cmp r4, 0x15
	ble _081CCD48
	movs r0, 0x4
	b _081CCD62
_081CCD48:
	ldr r0, =gUnknown_08623118
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0xC8
	muls r1, r4
	ldr r3, =0x00000818
	adds r1, r3
	adds r1, r2, r1
	bl LZ77UnCompWram
	movs r0, 0x1
_081CCD62:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CCD34

	thumb_func_start sub_81CCD70
sub_81CCD70: @ 81CCD70
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r3, r1, 0
	movs r4, 0
	ldr r0, =gUnknown_08623118
	ldrh r1, [r0]
	adds r5, r0, 0
	cmp r1, r3
	bne _081CCD8A
	ldrh r0, [r5, 0x2]
	cmp r0, r2
	beq _081CCDA0
_081CCD8A:
	adds r4, 0x1
	cmp r4, 0x15
	bgt _081CCDA0
	lsls r0, r4, 3
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, r3
	bne _081CCD8A
	ldrh r0, [r1, 0x2]
	cmp r0, r2
	bne _081CCD8A
_081CCDA0:
	cmp r4, 0x16
	beq _081CCDD4
	ldr r1, =0x00001041
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x11
	movs r3, 0x6
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0xC8
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =0x00000818
	adds r1, r0
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x12
	movs r3, 0x6
	bl CopyToBgTilemapBufferRect
_081CCDD4:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCD70

	thumb_func_start sub_81CCDE8
sub_81CCDE8: @ 81CCDE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	mov r9, r0
	movs r5, 0
	ldr r6, =gStringVar1
	movs r4, 0x88
	lsls r4, 21
	lsls r1, 24
	mov r8, r1
	lsls r7, r2, 24
	b _081CCE34
	.pool
_081CCE08:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	mov r1, r9
	ldrb r0, [r1, 0x8]
	lsrs r1, r4, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x7
	adds r2, r6, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x80
	lsls r0, 21
	adds r4, r0
	adds r5, 0x1
_081CCE34:
	lsls r2, r5, 24
	lsrs r2, 24
	mov r1, r8
	lsrs r0, r1, 24
	lsrs r1, r7, 24
	bl GetLandmarkName
	adds r1, r0, 0
	cmp r1, 0
	bne _081CCE08
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCDE8

	thumb_func_start sub_81CCE58
sub_81CCE58: @ 81CCE58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_8124658
	lsls r0, 24
	movs r2, 0x84
	cmp r0, 0
	bne _081CCE74
	movs r2, 0xE4
_081CCE74:
	movs r5, 0
	lsls r7, r2, 16
	adds r4, 0xC
	mov r8, r4
	movs r6, 0x98
	lsls r6, 16
_081CCE80:
	asrs r1, r6, 16
	ldr r0, =gUnknown_086231D0
	asrs r2, r7, 16
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	movs r0, 0
	strh r0, [r2, 0x2E]
	lsls r4, r5, 2
	strh r4, [r2, 0x30]
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r0, r1, 22
	adds r1, r0, 0
	strh r0, [r2, 0x32]
	movs r0, 0x96
	strh r0, [r2, 0x34]
	strh r4, [r2, 0x36]
	adds r1, r4
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r4, =0xfffffc00
	adds r0, r4, 0
	ands r3, r0
	orrs r3, r1
	strh r3, [r2, 0x4]
	mov r0, r8
	adds r0, 0x4
	mov r8, r0
	subs r0, 0x4
	stm r0!, {r2}
	movs r4, 0x80
	lsls r4, 14
	adds r6, r4
	adds r5, 0x1
	cmp r5, 0x2
	ble _081CCE80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CCE58

	thumb_func_start sub_81CCEF4
sub_81CCEF4: @ 81CCEF4
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x34]
	movs r1, 0x34
	ldrsh r4, [r3, r1]
	cmp r4, 0
	beq _081CCF06
	subs r0, 0x1
	b _081CCF6E
_081CCF06:
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _081CCF16
	strh r4, [r3, 0x2E]
_081CCF16:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081CCF26
	strh r4, [r3, 0x30]
_081CCF26:
	ldrh r5, [r3, 0x30]
	ldrh r2, [r3, 0x32]
	adds r1, r5, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x38]
	movs r2, 0x38
	ldrsh r0, [r3, r2]
	cmp r0, 0x3
	bgt _081CCF5C
	movs r2, 0x2E
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _081CCF70
	adds r0, r1, 0x1
	strh r0, [r3, 0x38]
	b _081CCF6C
	.pool
_081CCF5C:
	lsls r0, r5, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bne _081CCF70
	strh r4, [r3, 0x38]
	strh r4, [r3, 0x2E]
_081CCF6C:
	movs r0, 0x78
_081CCF6E:
	strh r0, [r3, 0x34]
_081CCF70:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCEF4

	thumb_func_start sub_81CCF78
sub_81CCF78: @ 81CCF78
	push {r4,lr}
	movs r0, 0x4
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x1
	bl GetBgY
	asrs r0, 8
	movs r1, 0x84
	subs r1, r0
	adds r4, 0xC
	movs r2, 0x2
_081CCF92:
	ldm r4!, {r0}
	strh r1, [r0, 0x22]
	subs r2, 0x1
	cmp r2, 0
	bge _081CCF92
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCF78

	thumb_func_start sub_81CCFA4
sub_81CCFA4: @ 81CCFA4
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl sub_81C763C
	movs r1, 0x1
	ands r4, r1
	lsls r5, r4, 2
	movs r6, 0x5
	negs r6, r6
	adds r4, r0, 0
	adds r4, 0xC
	movs r3, 0x2
_081CCFBE:
	ldm r4!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r5
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CCFBE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CCFA4

	thumb_func_start sub_81CCFD8
sub_81CCFD8: @ 81CCFD8
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD01C
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD970
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD01E
	.pool
_081CD01C:
	movs r0, 0
_081CD01E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CCFD8

	thumb_func_start sub_81CD024
sub_81CD024: @ 81CD024
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD068
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD9F8
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD06A
	.pool
_081CD068:
	movs r0, 0
_081CD06A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD024

	thumb_func_start sub_81CD070
sub_81CD070: @ 81CD070
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r2, =0x00006304
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD070

	thumb_func_start sub_81CD08C
sub_81CD08C: @ 81CD08C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r5, r0, 0
	adds r0, r4, 0
	bl sub_81CD1E4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _081CD100
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CD0D0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CD100
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD0F0
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bne _081CD100
_081CD0D0:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD19C
	str r0, [r1]
	movs r2, 0x2
	b _081CD100
	.pool
_081CD0F0:
	movs r0, 0x5
	bl PlaySE
	movs r2, 0x5
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD110
	str r0, [r1]
_081CD100:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD08C

	thumb_func_start sub_81CD110
sub_81CD110: @ 81CD110
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	movs r4, 0
	bl sub_811FBA4
	lsls r0, 24
	cmp r0, 0
	bne _081CD18A
	bl sub_81CEF14
	ldr r1, =0x00006786
	adds r5, r6, r1
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, =0x00006783
	adds r4, r6, r2
	adds r1, r4, r1
	strb r0, [r1]
	movs r0, 0x12
	bl sub_81C763C
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	ldrb r3, [r0, 0x5]
	movs r0, 0
	ldrsb r0, [r5, r0]
	adds r4, r0
	ldrb r1, [r4]
	mov r0, sp
	strb r1, [r0]
	cmp r2, 0xE
	bne _081CD174
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
	b _081CD180
	.pool
_081CD174:
	adds r0, r2, 0
	adds r1, r3, 0
	movs r2, 0x8
	mov r3, sp
	bl SetBoxMonDataAt
_081CD180:
	ldr r0, =0x00006304
	adds r1, r6, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r4, 0x6
_081CD18A:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD110

	thumb_func_start sub_81CD19C
sub_81CD19C: @ 81CD19C
	push {lr}
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD1B4
	ldr r0, =0x000186aa
	b _081CD1B6
	.pool
_081CD1B4:
	ldr r0, =0x000186a2
_081CD1B6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD19C

	thumb_func_start sub_81CD1C0
sub_81CD1C0: @ 81CD1C0
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD1DA
	movs r0, 0x12
	bl sub_81C7650
_081CD1DA:
	movs r0, 0xB
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CD1C0

	thumb_func_start sub_81CD1E4
sub_81CD1E4: @ 81CD1E4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r2, r0, 0
	movs r3, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CD220
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD210
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	beq _081CD24E
_081CD210:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	b _081CD246
	.pool
_081CD220:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CD24E
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD23E
	ldrh r1, [r2, 0x2]
	ldrh r0, [r2]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD24E
_081CD23E:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
_081CD246:
	bl sub_81CD258
	lsls r0, 24
	lsrs r3, r0, 24
_081CD24E:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD1E4

	thumb_func_start sub_81CD258
sub_81CD258: @ 81CD258
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0xB
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r5, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD284
	ldr r1, =0x00006788
	adds r0, r4, r1
	b _081CD288
	.pool
_081CD284:
	ldr r2, =0x00006787
	adds r0, r4, r2
_081CD288:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	ldr r1, =0x00006428
	adds r0, r4, r1
	ldr r2, =0x00006786
	adds r1, r4, r2
	movs r2, 0
	ldrsb r2, [r1, r2]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	ldr r3, =0x0000643c
	adds r1, r3
	adds r1, r4, r1
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 2
	adds r2, r3
	adds r2, r4, r2
	bl sub_81D1F84
	ldrh r6, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD2D8
	ldrh r1, [r5]
	b _081CD2DC
	.pool
_081CD2D8:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD2DC:
	eors r1, r6
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	adds r6, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD332
	ldr r1, =0x00006787
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r1, 0x1
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r5, 0x2]
	cmp r0, 0
	bne _081CD312
	ldrh r0, [r5]
_081CD312:
	subs r1, r0, 0x1
	strh r1, [r5, 0x2]
	lsls r0, r1, 16
	cmp r0, 0
	beq _081CD32C
	subs r1, 0x1
	b _081CD384
	.pool
_081CD32C:
	ldrh r0, [r5]
	subs r1, r0, 0x1
	b _081CD384
_081CD332:
	ldr r0, =0x00006788
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r1, =0x00006787
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD370
	adds r0, r1, 0x1
	b _081CD372
	.pool
_081CD370:
	movs r0, 0
_081CD372:
	strh r0, [r5, 0x2]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD382
	adds r1, 0x1
	b _081CD384
_081CD382:
	movs r1, 0
_081CD384:
	ldr r2, =0x00006302
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r4, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD39C
	ldrh r1, [r5]
	b _081CD3A0
	.pool
_081CD39C:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD3A0:
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r6, 0
	bne _081CD3B0
	movs r0, 0x3
	b _081CD3BA
_081CD3B0:
	cmp r0, 0
	beq _081CD3B8
	movs r0, 0x1
	b _081CD3BA
_081CD3B8:
	movs r0, 0x4
_081CD3BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD258

	thumb_func_start sub_81CD3C4
sub_81CD3C4: @ 81CD3C4
	push {r4,lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r4, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r2, r0, 0
	ldr r1, =0x0000678a
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _081CD3E2
	b _081CD530
_081CD3E2:
	lsls r0, 2
	ldr r1, =_081CD3F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CD3F4:
	.4byte _081CD41C
	.4byte _081CD428
	.4byte _081CD434
	.4byte _081CD440
	.4byte _081CD490
	.4byte _081CD4A8
	.4byte _081CD4C0
	.4byte _081CD4D8
	.4byte _081CD4F0
	.4byte _081CD508
_081CD41C:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CD824
	b _081CD530
_081CD428:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDA1C
	b _081CD530
_081CD434:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDB98
	b _081CD530
_081CD440:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _081CD468
	ldr r2, =0x00006786
	adds r0, r4, r2
	movs r1, 0
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD468:
	ldr r0, =0x00006786
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x00006787
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x00006788
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _081CD530
	.pool
_081CD490:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD49C
	movs r0, 0
_081CD49C:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CD824
	b _081CD530
_081CD4A8:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4B4
	movs r0, 0
_081CD4B4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDA1C
	b _081CD530
_081CD4C0:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4CC
	movs r0, 0
_081CD4CC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDB98
	b _081CD530
_081CD4D8:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4E4
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4E4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CD824
	b _081CD530
_081CD4F0:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4FC
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4FC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDA1C
	b _081CD530
_081CD508:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD514
	ldrh r0, [r2]
	subs r0, 0x1
_081CD514:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDB98
	ldr r2, =0x0000678a
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD530:
	ldr r0, =0x0000678a
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
_081CD53C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD3C4

	thumb_func_start sub_81CD548
sub_81CD548: @ 81CD548
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0xB
	bl sub_81C763C
	adds r1, r0, 0
	cmp r4, 0x1
	beq _081CD588
	cmp r4, 0x1
	bgt _081CD566
	cmp r4, 0
	beq _081CD56C
	b _081CD5C4
_081CD566:
	cmp r5, 0x2
	beq _081CD5A4
	b _081CD5C4
_081CD56C:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CD824
	b _081CD5C4
	.pool
_081CD588:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDA1C
	b _081CD5C4
	.pool
_081CD5A4:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDB98
	movs r0, 0x1
	b _081CD5C6
	.pool
_081CD5C4:
	movs r0, 0
_081CD5C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD548

	thumb_func_start sub_81CD5CC
sub_81CD5CC: @ 81CD5CC
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081CD5E4
_081CD5D6:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081CD5E4:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081CD5D6
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081CD612
	movs r3, 0
_081CD5FE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081CD5FE
_081CD612:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD5CC

	thumb_func_start sub_81CD624
sub_81CD624: @ 81CD624
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0x12
	bl sub_81C763C
	lsls r4, 2
	adds r0, r4
	ldrb r4, [r0, 0x4]
	mov r8, r4
	ldrb r6, [r0, 0x5]
	mov r9, r6
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081CD690
	ldr r1, =gText_EggNickname
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081CD80E
	.pool
_081CD690:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081CD6E0
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081CD6FE
	.pool
_081CD6E0:
	mov r0, r8
	mov r1, r9
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081CD6FE:
	cmp r7, 0x1D
	beq _081CD706
	cmp r7, 0x20
	bne _081CD71C
_081CD706:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081CD71C
	movs r6, 0xFF
_081CD71C:
	adds r3, r5, 0
	b _081CD726
	.pool
_081CD724:
	adds r3, 0x1
_081CD726:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081CD724
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081CD74A
	cmp r6, 0xFE
	beq _081CD76E
	movs r0, 0x77
	b _081CD790
_081CD74A:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081CD790
_081CD76E:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081CD790:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r5, 0
	strb r5, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r4, r3, 0
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	subs r4, r3, r4
	lsls r4, 16
	lsrs r4, 16
	strb r5, [r3]
	adds r3, 0x1
	mov r0, r10
	cmp r0, 0
	bne _081CD808
	movs r0, 0x3
	subs r0, r4
	lsls r0, 16
	ldr r1, =0xffff0000
	adds r0, r1
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _081CD808
	movs r2, 0
	adds r1, r0, 0
_081CD7FA:
	strb r2, [r3]
	adds r3, 0x1
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r1
	bne _081CD7FA
_081CD808:
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081CD80E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD624

	thumb_func_start sub_81CD824
sub_81CD824: @ 81CD824
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0xB
	bl sub_81C763C
	adds r5, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r7, r0, 0
	mov r1, r8
	lsls r0, r1, 16
	asrs r4, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD85A
	ldrh r2, [r7]
	cmp r4, r2
	bne _081CD862
	b _081CD900
_081CD85A:
	ldrh r0, [r7]
	subs r0, 0x1
	cmp r4, r0
	beq _081CD900
_081CD862:
	lsls r0, r6, 6
	ldr r1, =0x00006368
	adds r0, r1
	adds r0, r5, r0
	mov r2, r8
	lsls r4, r2, 16
	lsrs r1, r4, 16
	movs r2, 0
	bl sub_81CD624
	asrs r4, 14
	adds r4, r7, r4
	ldrb r3, [r4, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r4, r0, 3
	ldr r1, =0x00006320
	adds r0, r5, r1
	adds r0, r4
	movs r2, 0
	movs r1, 0xFC
	strb r1, [r0]
	ldr r1, =0x00006321
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x4
	strb r1, [r0]
	ldr r1, =0x00006322
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =0x00006323
	adds r0, r5, r1
	adds r0, r4
	strb r2, [r0]
	ldr r2, =0x00006324
	adds r0, r5, r2
	adds r0, r4
	movs r1, 0x9
	strb r1, [r0]
	cmp r3, 0xE
	bne _081CD8E4
	adds r0, r4, r5
	ldr r1, =0x00006325
	adds r0, r1
	ldr r1, =gText_InParty
	b _081CD8F4
	.pool
_081CD8E4:
	adds r4, r5
	ldr r2, =0x00006325
	adds r4, r2
	adds r0, r3, 0
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
_081CD8F4:
	movs r2, 0x8
	bl sub_81CD5CC
	b _081CD95C
	.pool
_081CD900:
	movs r1, 0
	lsls r4, r6, 6
	lsls r0, r6, 1
	mov r8, r0
	adds r3, r4, 0
	ldr r0, =0x00006368
	adds r2, r5, r0
	movs r7, 0
_081CD910:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r7, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081CD910
	adds r1, r4
	ldr r2, =0x00006368
	adds r0, r5, r2
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r1, 0
	mov r2, r8
	adds r0, r2, r6
	lsls r3, r0, 3
	ldr r0, =0x00006320
	adds r2, r5, r0
	movs r4, 0
_081CD93A:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081CD93A
	mov r2, r8
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1, r0
	ldr r2, =0x00006320
	adds r1, r5, r2
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
_081CD95C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD824

	thumb_func_start sub_81CD970
sub_81CD970: @ 81CD970
	push {r4-r7,lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r7, r0, 0
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	adds r6, r0, 0
	movs r0, 0xC6
	lsls r0, 7
	adds r1, r7, r0
	movs r0, 0
	strb r0, [r1]
	movs r4, 0
	movs r5, 0
	b _081CD9C4
	.pool
_081CD998:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r2, r0, 0
	cmp r2, 0
	bne _081CD9BE
	lsls r1, r5, 2
	adds r1, r6, r1
	movs r0, 0xE
	strb r0, [r1, 0x4]
	strb r4, [r1, 0x5]
	strh r2, [r1, 0x6]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081CD9BE:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CD9C4:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _081CD998
	lsls r0, r5, 2
	adds r0, r6, r0
	movs r1, 0
	strb r1, [r0, 0x4]
	strb r1, [r0, 0x5]
	movs r2, 0
	strh r1, [r0, 0x6]
	strh r1, [r6, 0x2]
	adds r0, r5, 0x1
	strh r0, [r6]
	ldr r1, =0x0000678a
	adds r0, r7, r1
	strb r2, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD970

	thumb_func_start sub_81CD9F8
sub_81CD9F8: @ 81CD9F8
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r2, r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, =0x0000678a
	adds r0, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD9F8

	thumb_func_start sub_81CDA1C
sub_81CDA1C: @ 81CDA1C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl sub_81C763C
	mov r8, r0
	movs r0, 0x12
	bl sub_81C763C
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDA52
	ldrh r0, [r4]
	cmp r5, r0
	bne _081CDA5A
	b _081CDB48
_081CDA52:
	ldrh r0, [r4]
	subs r0, 0x1
	cmp r5, r0
	beq _081CDB48
_081CDA5A:
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r6, [r0, 0x4]
	ldrb r7, [r0, 0x5]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	ldr r1, =0x00006428
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x00006429
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642a
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642b
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x0000642c
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	movs r0, 0xCF
	lsls r0, 7
	add r0, r8
	mov r2, r9
	adds r4, r0, r2
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081CDB10
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081CDB12
	.pool
_081CDB10:
	movs r0, 0x9
_081CDB12:
	strb r0, [r4]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x8
	movs r3, 0
	bl sub_81D2C68
	ldr r1, =0x00006783
	add r1, r8
	add r1, r9
	strb r0, [r1]
	mov r0, r9
	adds r1, r5, r0
	ldr r2, =0x00006428
	adds r0, r1, r2
	add r0, r8
	lsls r1, 2
	adds r2, 0x14
	adds r1, r2
	add r1, r8
	bl sub_81D2754
	b _081CDB80
	.pool
_081CDB48:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	add r5, r9
	ldr r4, =0x00006428
	add r4, r8
	lsls r3, r5, 2
	mov r9, r2
	ldr r7, =0x0000643c
	movs r6, 0x9B
_081CDB5C:
	adds r0, r2, r5
	adds r0, r4, r0
	mov r1, r9
	strb r1, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	adds r1, r0, r7
	strh r6, [r1]
	ldr r1, =0x0000643e
	adds r0, r1
	movs r1, 0x5B
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081CDB5C
_081CDB80:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDA1C

	thumb_func_start sub_81CDB98
sub_81CDB98: @ 81CDB98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl sub_81C763C
	adds r7, r0, 0
	movs r0, 0x12
	bl sub_81C763C
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDBCC
	ldrh r0, [r4]
	b _081CDBD0
_081CDBCC:
	ldrh r0, [r4]
	subs r0, 0x1
_081CDBD0:
	cmp r5, r0
	beq _081CDC3E
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r5, [r0, 0x4]
	ldrb r6, [r0, 0x5]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	mov r8, r0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	mov r2, r9
	lsls r1, r2, 13
	movs r2, 0xC0
	lsls r2, 2
	adds r1, r2
	adds r1, r7, r1
	movs r2, 0x1
	str r2, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl LoadSpecialPokePic
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl GetFrontSpritePalFromSpeciesAndPersonality
	mov r2, r9
	lsls r1, r2, 7
	adds r1, r7, r1
	bl LZ77UnCompWram
_081CDC3E:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDB98

	thumb_func_start sub_81CDC50
sub_81CDC50: @ 81CDC50
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC50

	thumb_func_start sub_81CDC60
sub_81CDC60: @ 81CDC60
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC60

	thumb_func_start sub_81CDC70
sub_81CDC70: @ 81CDC70
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006428
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC70

	thumb_func_start sub_81CDC84
sub_81CDC84: @ 81CDC84
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006786
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC84

	thumb_func_start sub_81CDC9C
sub_81CDC9C: @ 81CDC9C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006302
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC9C

	thumb_func_start sub_81CDCB4
sub_81CDCB4: @ 81CDCB4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 13
	movs r1, 0xC0
	lsls r1, 2
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCB4

	thumb_func_start sub_81CDCD4
sub_81CDCD4: @ 81CDCD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 7
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCD4

	thumb_func_start sub_81CDCEC
sub_81CDCEC: @ 81CDCEC
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r1, =0x00006789
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDCEC

	thumb_func_start sub_81CDD04
sub_81CDD04: @ 81CDD04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r4, 6
	ldr r1, =0x00006368
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD04

	thumb_func_start sub_81CDD24
sub_81CDD24: @ 81CDD24
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl sub_81C763C
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	ldr r2, =0x00006320
	adds r1, r2
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD24

	thumb_func_start sub_81CDD48
sub_81CDD48: @ 81CDD48
	push {lr}
	movs r0, 0x12
	bl sub_81C763C
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD48

	thumb_func_start sub_81CDD5C
sub_81CDD5C: @ 81CDD5C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD74
	movs r0, 0
	b _081CDD76
_081CDD74:
	movs r0, 0x1
_081CDD76:
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD5C

	thumb_func_start sub_81CDD7C
sub_81CDD7C: @ 81CDD7C
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	adds r2, r0, 0
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD96
	movs r0, 0
	b _081CDDA6
_081CDD96:
	ldr r3, =0x00006786
	adds r0, r2, r3
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r3, 0x3
	adds r0, r2, r3
	adds r0, r1
	ldrb r0, [r0]
_081CDDA6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD7C

	thumb_func_start sub_81CDDB0
sub_81CDDB0: @ 81CDDB0
	push {lr}
	movs r0, 0xB
	bl sub_81C763C
	ldr r2, =0x00006786
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r2, 0x6
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDDB0

	thumb_func_start sub_81CDDD4
sub_81CDDD4: @ 81CDDD4
	push {r4,lr}
	ldr r1, =0x000038ac
	movs r0, 0xC
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CDE24
	ldr r0, =0x00001816
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, =sub_81CDE94
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4]
	ldr r0, =0x00001810
	adds r1, r4, r0
	ldr r0, =sub_81CDE80
	str r0, [r1]
	ldr r0, =0x00002908
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CDE26
	.pool
_081CDE24:
	movs r0, 0
_081CDE26:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDDD4

	thumb_func_start sub_81CDE2C
sub_81CDE2C: @ 81CDE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08623384
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5]
	ldr r0, =0x00001810
	adds r5, r0
	ldr r0, =sub_81CDE80
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDE2C

	thumb_func_start sub_81CDE64
sub_81CDE64: @ 81CDE64
	push {lr}
	movs r0, 0xC
	bl sub_81C763C
	ldr r1, =0x00001810
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDE64

	thumb_func_start sub_81CDE80
sub_81CDE80: @ 81CDE80
	push {lr}
	movs r0, 0xC
	bl sub_81C763C
	ldr r0, [r0]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE80

	thumb_func_start sub_81CDE94
sub_81CDE94: @ 81CDE94
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x14
	bls _081CDEA8
	b _081CE2C4
_081CDEA8:
	lsls r0, r4, 2
	ldr r1, =_081CDEB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CDEB8:
	.4byte _081CDF0C
	.4byte _081CDF18
	.4byte _081CDF94
	.4byte _081CDFB8
	.4byte _081CE030
	.4byte _081CE074
	.4byte _081CE0B0
	.4byte _081CE118
	.4byte _081CE120
	.4byte _081CE126
	.4byte _081CE136
	.4byte _081CE146
	.4byte _081CE156
	.4byte _081CE16C
	.4byte _081CE1C8
	.4byte _081CE1EC
	.4byte _081CE218
	.4byte _081CE23C
	.4byte _081CE24A
	.4byte _081CE25A
	.4byte _081CE262
_081CDF0C:
	bl sub_81CD3C4
	cmp r0, 0x1
	beq _081CDF16
	b _081CE2C0
_081CDF16:
	b _081CDFB0
_081CDF18:
	ldr r0, =gUnknown_08623358
	movs r1, 0x3
	bl sub_81C7B54
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
	ldr r1, =0x00007940
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00000844
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040b
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gPokenavCondition_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _081CDFA8
	.pool
_081CDF94:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081CDFA2
	b _081CE2C0
_081CDFA2:
	ldr r1, =gUnknown_08623228
	str r0, [sp]
	movs r0, 0x2
_081CDFA8:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_081CDFB0:
	movs r0, 0
	b _081CE2C6
	.pool
_081CDFB8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CDFC4
	b _081CE2C0
_081CDFC4:
	ldr r0, =gPokenavCondition_Tilemap
	adds r4, r5, 0x4
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x3
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CDFF2
	ldr r1, =gPokenavOptions_Tilemap
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0x5
	bl CopyToBgTilemapBufferRect
_081CDFF2:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	ldr r0, =gPokenavCondition_Pal
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =gUnknown_08623208
	movs r1, 0xF0
	movs r2, 0x20
	bl sub_81C7944
	ldr r0, =0x00001814
	adds r1, r5, r0
	ldr r0, =0x0000ffb0
	strh r0, [r1]
	b _081CDFB0
	.pool
_081CE030:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE03C
	b _081CE2C0
_081CE03C:
	ldr r0, =gUnknown_0862323C
	ldr r1, =0x00001004
	adds r4, r5, r1
	adds r1, r4, 0
	bl LZ77UnCompVram
	movs r0, 0x2
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086231E8
	movs r1, 0x30
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x2
	bl sub_81D21DC
	b _081CDFB0
	.pool
_081CE074:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0x1
	movs r1, 0x11
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8199DF0
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r2, =0x00000804
	adds r4, r5, r2
	ldr r2, =0x05000200
	add r0, sp, 0x8
	adds r1, r4, 0
	bl CpuSet
	movs r0, 0x1
	adds r1, r4, 0
	bl SetBgTilemapBuffer
	b _081CDFB0
	.pool
_081CE0B0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081CE0BC
	b _081CE2C0
_081CE0BC:
	ldr r0, =gUnknown_08623364
	bl AddWindow
	movs r2, 0xC1
	lsls r2, 5
	adds r1, r5, r2
	strb r0, [r1]
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE0F6
	ldr r0, =gUnknown_0862336C
	bl AddWindow
	ldr r2, =0x00001821
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_08623374
	bl AddWindow
	ldr r2, =0x00001822
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, =gUnknown_0862337C
	bl AddWindow
	ldr r2, =0x00001823
	adds r1, r5, r2
	strb r0, [r1]
_081CE0F6:
	bl DeactivateAllTextPrinters
	b _081CDFB0
	.pool
_081CE118:
	movs r0, 0
	bl sub_81CED30
	b _081CDFB0
_081CE120:
	bl sub_81CE9E4
	b _081CDFB0
_081CE126:
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE130
	b _081CDFB0
_081CE130:
	bl sub_81CE934
	b _081CDFB0
_081CE136:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE164
_081CE146:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE164
_081CE156:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE164:
	movs r2, 0x1
	bl sub_81CE754
	b _081CDFB0
_081CE16C:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0x1
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE186
	b _081CE2C0
_081CE186:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE19C
	b _081CDFB0
_081CE19C:
	ldr r2, =0x00001821
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r1, =0x00001822
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r2, =0x00001823
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	b _081CDFB0
	.pool
_081CE1C8:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl ShowBg
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE1E4
	b _081CDFB0
_081CE1E4:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CDFB0
_081CE1EC:
	movs r0, 0x1
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CE1FC
	b _081CDFB0
_081CE1FC:
	movs r0, 0x6
	bl sub_81C7DFC
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x6
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CDFB0
_081CE218:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CE2C0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE230
	bl sub_81C8010
	cmp r0, 0
	bne _081CE2C0
_081CE230:
	ldr r0, =sub_81CEE44
	bl c3args_set_0toR1_1to0
	b _081CDFB0
	.pool
_081CE23C:
	bl sub_81CEE90
	bl sub_81CDC70
	bl sub_81D20AC
	b _081CDFB0
_081CE24A:
	bl sub_81CDC70
	bl sub_81D20BC
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	b _081CDFB0
_081CE25A:
	movs r0, 0x1
	bl sub_81CEE74
	b _081CDFB0
_081CE262:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE2C0
	ldr r0, =0x000028e0
	adds r6, r5, r0
	adds r0, r6, 0
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE298
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE2C4
_081CE298:
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE2C4
	.pool
_081CE2C0:
	movs r0, 0x2
	b _081CE2C6
_081CE2C4:
	movs r0, 0x4
_081CE2C6:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDE94

	thumb_func_start sub_81CE2D0
sub_81CE2D0: @ 81CE2D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CE308
	cmp r4, 0x1
	bgt _081CE2EA
	cmp r4, 0
	beq _081CE2F4
	b _081CE374
_081CE2EA:
	cmp r4, 0x2
	beq _081CE328
	cmp r4, 0x3
	beq _081CE33E
	b _081CE374
_081CE2F4:
	bl sub_81CEEC8
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	movs r0, 0x1
	b _081CE376
	.pool
_081CE308:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _081CE34E
	movs r0, 0
	bl sub_81CEE74
	movs r0, 0x1
	b _081CE376
	.pool
_081CE328:
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CE33A
	bl sub_81C78A0
_081CE33A:
	movs r0, 0
	b _081CE376
_081CE33E:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CE34E
	bl sub_81C78C0
	cmp r0, 0
	beq _081CE352
_081CE34E:
	movs r0, 0x2
	b _081CE376
_081CE352:
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D354C
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	b _081CE376
	.pool
_081CE374:
	movs r0, 0x4
_081CE376:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE2D0

	thumb_func_start sub_81CE37C
sub_81CE37C: @ 81CE37C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	bl sub_81CDC70
	adds r2, r0, 0
	cmp r4, 0x9
	bls _081CE394
	b _081CE4D0
_081CE394:
	lsls r0, r4, 2
	ldr r1, =_081CE3A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE3A4:
	.4byte _081CE3CC
	.4byte _081CE3D0
	.4byte _081CE3DA
	.4byte _081CE3F0
	.4byte _081CE3F8
	.4byte _081CE418
	.4byte _081CE428
	.4byte _081CE438
	.4byte _081CE44E
	.4byte _081CE468
_081CE3CC:
	movs r0, 0
	b _081CE3D2
_081CE3D0:
	movs r0, 0x1
_081CE3D2:
	bl sub_81CD548
_081CE3D6:
	movs r0, 0x1
	b _081CE4D2
_081CE3DA:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3520
	b _081CE3D6
	.pool
_081CE3F0:
	adds r0, r2, 0
	bl sub_81D2074
	b _081CE3D6
_081CE3F8:
	ldr r1, =0x00001814
	adds r0, r6, r1
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	b _081CE3D6
	.pool
_081CE418:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE446
_081CE428:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE446
_081CE438:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE446:
	movs r2, 0
	bl sub_81CE754
	b _081CE3D6
_081CE44E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE3D6
	b _081CE4CC
_081CE468:
	bl sub_81CDC70
	adds r2, r0, 0
	ldr r0, =0x00001814
	adds r1, r6, r0
	adds r0, r2, 0
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE4CC
	ldr r1, =0x000028e0
	adds r0, r6, r1
	bl sub_81D3464
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE4A0
	bl sub_81CDC60
	adds r4, r0, 0
	bl sub_81CDC50
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _081CE3D6
_081CE4A0:
	ldr r0, =0x000028e0
	adds r5, r6, r0
	ldr r1, =0x00001816
	adds r0, r6, r1
	ldrb r4, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81D3480
	b _081CE3D6
	.pool
_081CE4CC:
	movs r0, 0x2
	b _081CE4D2
_081CE4D0:
	movs r0, 0x4
_081CE4D2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE37C

	thumb_func_start sub_81CE4D8
sub_81CE4D8: @ 81CE4D8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x8
	bhi _081CE5DC
	lsls r0, r4, 2
	ldr r1, =_081CE4F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE4F8:
	.4byte _081CE51C
	.4byte _081CE520
	.4byte _081CE524
	.4byte _081CE52E
	.4byte _081CE53E
	.4byte _081CE54E
	.4byte _081CE55E
	.4byte _081CE576
	.4byte _081CE592
_081CE51C:
	movs r0, 0
	b _081CE526
_081CE520:
	movs r0, 0x1
	b _081CE526
_081CE524:
	movs r0, 0x2
_081CE526:
	bl sub_81CD548
	movs r0, 0x1
	b _081CE5DE
_081CE52E:
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	bl sub_81CED30
	movs r0, 0x1
	b _081CE5DE
_081CE53E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE56C
_081CE54E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE56C
_081CE55E:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE56C:
	movs r2, 0
	bl sub_81CE754
	movs r0, 0x1
	b _081CE5DE
_081CE576:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	bne _081CE5D8
	movs r0, 0x1
	b _081CE5DE
_081CE592:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _081CE5D8
	ldr r0, =0x000028e0
	adds r4, r5, r0
	adds r0, r4, 0
	bl sub_81D3464
	ldr r1, =0x00001816
	adds r0, r5, r1
	ldrb r5, [r0]
	bl sub_81CDDB0
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3480
	movs r0, 0x1
	b _081CE5DE
	.pool
_081CE5D8:
	movs r0, 0x2
	b _081CE5DE
_081CE5DC:
	movs r0, 0x4
_081CE5DE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE4D8

	thumb_func_start sub_81CE5E4
sub_81CE5E4: @ 81CE5E4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x7
	bhi _081CE6B2
	lsls r0, r4, 2
	ldr r1, =_081CE604
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CE604:
	.4byte _081CE624
	.4byte _081CE628
	.4byte _081CE632
	.4byte _081CE648
	.4byte _081CE660
	.4byte _081CE670
	.4byte _081CE680
	.4byte _081CE696
_081CE624:
	movs r0, 0
	b _081CE62A
_081CE628:
	movs r0, 0x1
_081CE62A:
	bl sub_81CD548
_081CE62E:
	movs r0, 0x1
	b _081CE6B4
_081CE632:
	movs r0, 0x2
	bl sub_81CD548
	ldr r1, =0x000028e0
	adds r0, r5, r1
	bl sub_81D3520
	b _081CE62E
	.pool
_081CE648:
	bl sub_81CDC70
	ldr r2, =0x00001814
	adds r1, r5, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	beq _081CE62E
	b _081CE6AE
	.pool
_081CE660:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0
	b _081CE68E
_081CE670:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x1
	b _081CE68E
_081CE680:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x2
_081CE68E:
	movs r2, 0
	bl sub_81CE754
	b _081CE62E
_081CE696:
	bl sub_81CDC84
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 8
	lsrs r1, 16
	movs r0, 0x3
	movs r2, 0
	bl sub_81CE754
	cmp r0, 0x1
	beq _081CE62E
_081CE6AE:
	movs r0, 0x2
	b _081CE6B4
_081CE6B2:
	movs r0, 0x4
_081CE6B4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE5E4

	thumb_func_start sub_81CE6BC
sub_81CE6BC: @ 81CE6BC
	push {lr}
	cmp r0, 0x1
	beq _081CE6E6
	cmp r0, 0x1
	bgt _081CE6CC
	cmp r0, 0
	beq _081CE6D2
	b _081CE6FA
_081CE6CC:
	cmp r0, 0x2
	beq _081CE6EE
	b _081CE6FA
_081CE6D2:
	bl sub_81CDD7C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xB0
	movs r2, 0x20
	bl sub_811FAA4
_081CE6E2:
	movs r0, 0x1
	b _081CE6FC
_081CE6E6:
	movs r0, 0x5
	bl sub_81C7BA4
	b _081CE6E2
_081CE6EE:
	bl sub_81C7BE8
	cmp r0, 0x1
	bne _081CE6E2
	movs r0, 0x2
	b _081CE6FC
_081CE6FA:
	movs r0, 0x4
_081CE6FC:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE6BC

	thumb_func_start sub_81CE700
sub_81CE700: @ 81CE700
	push {lr}
	cmp r0, 0x1
	beq _081CE71E
	cmp r0, 0x1
	bgt _081CE710
	cmp r0, 0
	beq _081CE716
	b _081CE732
_081CE710:
	cmp r0, 0x2
	beq _081CE726
	b _081CE732
_081CE716:
	bl sub_811FAF8
_081CE71A:
	movs r0, 0x1
	b _081CE734
_081CE71E:
	movs r0, 0x4
	bl sub_81C7BA4
	b _081CE71A
_081CE726:
	bl sub_81C7BE8
	cmp r0, 0x1
	bne _081CE71A
	movs r0, 0x2
	b _081CE734
_081CE732:
	movs r0, 0x4
_081CE734:
	pop {r1}
	bx r1
	thumb_func_end sub_81CE700

	thumb_func_start sub_81CE738
sub_81CE738: @ 81CE738
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_Number2
	bl StringCopy
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CE738

	thumb_func_start sub_81CE754
sub_81CE754: @ 81CE754
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	cmp r4, 0x1
	beq _081CE7B8
	cmp r4, 0x1
	bgt _081CE782
	cmp r4, 0
	beq _081CE78E
	b _081CE924
_081CE782:
	cmp r4, 0x2
	beq _081CE800
	cmp r4, 0x3
	bne _081CE78C
	b _081CE89C
_081CE78C:
	b _081CE924
_081CE78E:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7A6
	b _081CE924
_081CE7A6:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0
	bl FillWindowPixelBuffer
	b _081CE924
	.pool
_081CE7B8:
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE7DA
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CE7DA
	b _081CE924
_081CE7DA:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD04
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	str r7, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	b _081CE924
_081CE800:
	bl sub_81CDD5C
	adds r7, r0, 0
	cmp r7, 0x1
	beq _081CE80C
	b _081CE924
_081CE80C:
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_81CDD24
	adds r2, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x11
	str r1, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	add r1, sp, 0xC
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	adds r0, r1, 0
	strb r4, [r0, 0x3]
	movs r0, 0x9
	strb r0, [r1, 0x4]
	mov r5, sp
	adds r5, 0x11
	ldr r1, =gText_Number2
	adds r0, r5, 0
	bl StringCopy
	ldr r0, =0x00001821
	adds r6, r0
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x4
	bl AddTextPrinterParameterized
	bl sub_81CDD48
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldrb r0, [r6]
	str r7, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	movs r3, 0x1C
	bl AddTextPrinterParameterized
	b _081CE924
	.pool
_081CE89C:
	ldr r1, =0x00002908
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CE8B0
	cmp r0, 0x1
	beq _081CE8EC
	b _081CE924
	.pool
_081CE8B0:
	cmp r5, 0
	beq _081CE8C4
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE8D2
_081CE8C4:
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE8D2:
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CE910
	ldr r0, =0x00002908
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081CE924
	.pool
_081CE8EC:
	cmp r5, 0
	beq _081CE904
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	b _081CE910
	.pool
_081CE904:
	ldr r1, =0x00001821
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
_081CE910:
	ldr r0, =0x00002908
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CE926
	.pool
_081CE924:
	movs r0, 0
_081CE926:
	add sp, 0x2C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CE754

	thumb_func_start sub_81CE934
sub_81CE934: @ 81CE934
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =0x00001823
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE934

	thumb_func_start sub_81CE964
sub_81CE964: @ 81CE964
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	bl sub_81CDC60
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	bne _081CE982
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnim
	b _081CE98A
_081CE982:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_081CE98A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE964

	thumb_func_start sub_81CE990
sub_81CE990: @ 81CE990
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	bne _081CE9B0
	movs r0, 0x65
	b _081CE9B2
_081CE9B0:
	movs r0, 0x66
_081CE9B2:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r5, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE990

	thumb_func_start sub_81CE9C8
sub_81CE9C8: @ 81CE9C8
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81CDD7C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CE9C8

	thumb_func_start sub_81CE9E4
sub_81CE9E4: @ 81CE9E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	movs r0, 0xC
	bl sub_81C763C
	adds r6, r0, 0
	add r4, sp, 0x20
	add r5, sp, 0x38
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81D321C
	bl sub_81CDD5C
	adds r7, r4, 0
	mov r10, r5
	cmp r0, 0x1
	bne _081CEA78
	ldr r1, =0x00001824
	adds r0, r6, r1
	movs r2, 0x6A
	strh r2, [r0]
	ldr r3, =0x00001826
	adds r1, r6, r3
	strh r2, [r1]
	bl sub_811F90C
	bl sub_811FA90
	ldr r2, =gUnknown_08623338
	movs r0, 0x69
	movs r1, 0x69
	bl sub_811FF94
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0xC0
	strh r1, [r0, 0x20]
	movs r1, 0x20
	strh r1, [r0, 0x22]
	ldr r1, =sub_81CE9C8
	str r1, [r0, 0x1C]
	ldr r2, =0x000028dc
	adds r1, r6, r2
	str r0, [r1]
	movs r0, 0x69
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81C7990
	add r3, sp, 0x50
	mov r8, r3
	b _081CEBC6
	.pool
_081CEA78:
	mov r0, sp
	bl LoadSpriteSheets
	mov r0, r10
	bl sub_81C795C
	movs r4, 0
	add r0, sp, 0x50
	mov r8, r0
	b _081CEAE8
_081CEA8C:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r1, 0x80
	lsls r1, 12
	adds r2, r1
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEAD8
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	strb r3, [r0]
	ldr r2, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r1, r0, r2
	strh r4, [r1, 0x2E]
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CE964
	str r1, [r0]
	b _081CEAE2
	.pool
_081CEAD8:
	ldr r3, =0x00001806
	adds r0, r6, r3
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEAE2:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CEAE8:
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	blt _081CEA8C
	movs r0, 0x67
	strh r0, [r7]
	ldr r0, =SpriteCallbackDummy
	str r0, [r7, 0x14]
	cmp r4, 0x5
	bhi _081CEB5C
	ldr r0, =0x00001806
	adds r5, r6, r0
	ldr r1, =gSprites
	mov r9, r1
_081CEB0A:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r3, 0x80
	lsls r3, 12
	adds r2, r3
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xE6
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEB4C
	adds r0, r5, r4
	strb r3, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x3]
	b _081CEB52
	.pool
_081CEB4C:
	adds r1, r5, r4
	movs r0, 0xFF
	strb r0, [r1]
_081CEB52:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x5
	bls _081CEB0A
_081CEB5C:
	movs r0, 0x66
	strh r0, [r7]
	ldr r0, =sub_81CE990
	str r0, [r7, 0x14]
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r1, 0xDE
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081CEBBC
	ldr r1, =0x00001806
	adds r0, r6, r1
	adds r0, r4
	strb r3, [r0]
	ldr r0, =gSprites
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r0
	ldrb r3, [r2, 0x1]
	movs r1, 0x3F
	adds r0, r1, 0
	ands r0, r3
	movs r3, 0x40
	orrs r0, r3
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2, 0x3]
	b _081CEBC6
	.pool
_081CEBBC:
	ldr r2, =0x00001806
	adds r0, r6, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081CEBC6:
	mov r0, r8
	mov r1, r10
	bl sub_81D32B0
	mov r0, r8
	bl LoadSpriteSheet
	movs r0, 0
	mov r3, r10
	str r0, [r3, 0x8]
	mov r0, r10
	bl sub_81C795C
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CE9E4

	thumb_func_start sub_81CEBF4
sub_81CEBF4: @ 81CEBF4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CEC28
	ldr r1, =0x000028dc
	adds r0, r5, r1
	ldr r0, [r0]
	bl DestroySprite
	movs r0, 0x6A
	bl FreeSpriteTilesByTag
	movs r0, 0x69
	bl FreeSpriteTilesByTag
	movs r0, 0x6A
	bl FreeSpritePaletteByTag
	movs r0, 0x69
	bl FreeSpritePaletteByTag
	b _081CEC68
	.pool
_081CEC28:
	movs r4, 0
_081CEC2A:
	ldr r1, =0x00001806
	adds r0, r5, r1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _081CEC2A
	movs r0, 0x65
	bl FreeSpriteTilesByTag
	movs r0, 0x66
	bl FreeSpriteTilesByTag
	movs r0, 0x67
	bl FreeSpriteTilesByTag
	movs r0, 0x65
	bl FreeSpritePaletteByTag
	movs r0, 0x66
	bl FreeSpritePaletteByTag
_081CEC68:
	ldr r0, =0x00001816
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081CEC8E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0x64
	bl FreeSpriteTilesByTag
	movs r0, 0x64
	bl FreeSpritePaletteByTag
_081CEC8E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEBF4

	thumb_func_start sub_81CECA0
sub_81CECA0: @ 81CECA0
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	movs r1, 0xC1
	lsls r1, 5
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	bl sub_81CDD5C
	cmp r0, 0x1
	bne _081CECEC
	ldr r1, =0x00001821
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001822
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, =0x00001823
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _081CECF0
	.pool
_081CECEC:
	bl sub_81C7FDC
_081CECF0:
	movs r1, 0x8A
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_81CEBF4
	bl sub_81CEE68
	movs r0, 0xC
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CECA0

	thumb_func_start sub_81CED10
sub_81CED10: @ 81CED10
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xC
	bl sub_81C763C
	ldr r1, =0x00001814
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x26
	strh r0, [r4, 0x20]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED10

	thumb_func_start sub_81CED30
sub_81CED30: @ 81CED30
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0xC
	bl sub_81C763C
	mov r8, r0
	ldr r7, =0x00001816
	add r7, r8
	ldrb r0, [r7]
	cmp r0, 0xFF
	bne _081CEDFC
	add r5, sp, 0x18
	add r4, sp, 0x20
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_81D31D0
	adds r0, r6, 0
	bl sub_81CDCB4
	str r0, [sp, 0x18]
	adds r0, r6, 0
	bl sub_81CDCD4
	str r0, [sp, 0x20]
	adds r0, r4, 0
	bl LoadSpritePalette
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x00001818
	add r4, r8
	strh r0, [r4]
	adds r0, r5, 0
	bl LoadSpriteSheet
	ldr r5, =0x0000181a
	add r5, r8
	strh r0, [r5]
	mov r0, sp
	movs r1, 0x26
	movs r2, 0x68
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r7]
	cmp r0, 0x40
	bne _081CEDBC
	movs r0, 0x64
	bl FreeSpriteTilesByTag
	movs r0, 0x64
	bl FreeSpritePaletteByTag
	movs r0, 0xFF
	strb r0, [r7]
	b _081CEE26
	.pool
_081CEDBC:
	strb r0, [r7]
	ldr r2, =gSprites
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_81CED10
	str r1, [r0]
	ldr r1, =0x0000181c
	add r1, r8
	ldrh r0, [r5]
	lsls r0, 5
	ldr r2, =0x06010000
	adds r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4]
	b _081CEE26
	.pool
_081CEDFC:
	adds r0, r6, 0
	bl sub_81CDCB4
	ldr r1, =0x0000181c
	add r1, r8
	ldr r2, [r1]
	ldr r1, =0x040000d4
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x80000400
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r0, r6, 0
	bl sub_81CDCD4
	ldr r1, =0x00001818
	add r1, r8
	ldrh r1, [r1]
	movs r2, 0x20
	bl LoadPalette
_081CEE26:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CED30

	thumb_func_start sub_81CEE44
sub_81CEE44: @ 81CEE44
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	adds r0, r4, 0
	bl sub_81D2108
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE44

	thumb_func_start sub_81CEE68
sub_81CEE68: @ 81CEE68
	push {lr}
	bl sub_81C760C
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE68

	thumb_func_start sub_81CEE74
sub_81CEE74: @ 81CEE74
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _081CEE84
	movs r0, 0x2
	bl ShowBg
	b _081CEE8A
_081CEE84:
	movs r0, 0x2
	bl HideBg
_081CEE8A:
	pop {r0}
	bx r0
	thumb_func_end sub_81CEE74

	thumb_func_start sub_81CEE90
sub_81CEE90: @ 81CEE90
	push {r4,lr}
	bl sub_81CDC70
	adds r4, r0, 0
	bl sub_81CDC84
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_030012BC
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x50
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r2, 0x14
	adds r2, r4, r2
	adds r0, r4, 0
	bl sub_81D1F84
	adds r0, r4, 0
	bl sub_81D2074
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CEE90

	thumb_func_start sub_81CEEC8
sub_81CEEC8: @ 81CEEC8
	push {r4,r5,lr}
	bl sub_81CDC70
	adds r5, r0, 0
	bl sub_81CDD5C
	cmp r0, 0
	bne _081CEEF0
	bl sub_81CDC60
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81CDC50
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r4, r0
	beq _081CEF0C
_081CEEF0:
	bl sub_81CDC84
	lsls r0, 24
	asrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x14
	adds r1, r5, r1
	adds r2, r5, 0
	adds r2, 0x50
	adds r0, r5, 0
	bl sub_81D1F84
_081CEF0C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CEEC8

	thumb_func_start sub_81CEF14
sub_81CEF14: @ 81CEF14
	push {r4,lr}
	movs r0, 0xC
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81CDD5C
	cmp r0, 0x1
	beq _081CEF2A
	movs r0, 0
	b _081CEF30
_081CEF2A:
	ldr r1, =0x00001828
	adds r0, r4, r1
	ldrb r0, [r0]
_081CEF30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CEF14

	thumb_func_start sub_81CEF3C
sub_81CEF3C: @ 81CEF3C
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEF90
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _081CEF90
	ldr r0, =sub_81CF010
	str r0, [r4]
	ldr r0, =sub_81CF11C
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEF92
	.pool
_081CEF90:
	movs r0, 0
_081CEF92:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF3C

	thumb_func_start sub_81CEF98
sub_81CEF98: @ 81CEF98
	push {r4,lr}
	movs r0, 0x7
	movs r1, 0x24
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CEFD4
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x20]
	ldr r0, =sub_81CF030
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x18]
	bl sub_81C76AC
	ldr r1, =gUnknown_086233A0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CEFD6
	.pool
_081CEFD4:
	movs r0, 0
_081CEFD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CEF98

	thumb_func_start sub_81CEFDC
sub_81CEFDC: @ 81CEFDC
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CEFDC

	thumb_func_start sub_81CEFF0
sub_81CEFF0: @ 81CEFF0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	cmp r0, 0
	bne _081CF004
	movs r0, 0x12
	bl sub_81C7650
_081CF004:
	movs r0, 0x7
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CEFF0

	thumb_func_start sub_81CF010
sub_81CF010: @ 81CF010
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl sub_81C70D8
	cmp r0, 0
	bne _081CF022
	ldr r0, =sub_81CF030
	str r0, [r4]
_081CF022:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF010

	thumb_func_start sub_81CF030
sub_81CF030: @ 81CF030
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CF048
	movs r0, 0x1
	b _081CF0A6
	.pool
_081CF048:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CF054
	movs r0, 0x2
	b _081CF0A6
_081CF054:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CF062
	movs r0, 0x3
	b _081CF0A6
_081CF062:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CF072
	movs r0, 0x4
	b _081CF0A6
_081CF072:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CF088
	str r2, [r4, 0x1C]
	ldr r0, =sub_81CF0B0
	str r0, [r4]
	movs r0, 0x5
	b _081CF0A6
	.pool
_081CF088:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CF096
	movs r0, 0
	b _081CF0A6
_081CF096:
	bl sub_81C875C
	ldr r1, [r4, 0x20]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x1C]
	ldr r0, =sub_81CF0B8
	str r0, [r4]
	movs r0, 0x6
_081CF0A6:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF030

	thumb_func_start sub_81CF0B0
sub_81CF0B0: @ 81CF0B0
	ldr r0, =0x000186a3
	bx lr
	.pool
	thumb_func_end sub_81CF0B0

	thumb_func_start sub_81CF0B8
sub_81CF0B8: @ 81CF0B8
	ldr r0, =0x000186a9
	bx lr
	.pool
	thumb_func_end sub_81CF0B8

	thumb_func_start sub_81CF0C0
sub_81CF0C0: @ 81CF0C0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0C0

	thumb_func_start sub_81CF0D0
sub_81CF0D0: @ 81CF0D0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0D0

	thumb_func_start sub_81CF0E0
sub_81CF0E0: @ 81CF0E0
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0E0

	thumb_func_start sub_81CF0F0
sub_81CF0F0: @ 81CF0F0
	push {r4,lr}
	movs r0, 0x7
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	ldr r1, [r4, 0x20]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF0F0

	thumb_func_start sub_81CF10C
sub_81CF10C: @ 81CF10C
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	ldr r0, [r0, 0x20]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CF10C

	thumb_func_start sub_81CF11C
sub_81CF11C: @ 81CF11C
	push {lr}
	ldr r2, =gUnknown_086233B4
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF11C

	thumb_func_start sub_81CF134
sub_81CF134: @ 81CF134
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x7
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, [r6, 0x20]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x20]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CF158:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CF1AA
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CF1A4
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r6, 0x14]
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF1A4:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CF158
_081CF1AA:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CF134

	thumb_func_start sub_81CF1C4
sub_81CF1C4: @ 81CF1C4
	push {lr}
	movs r0, 0x7
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1C4

	thumb_func_start sub_81CF1D8
sub_81CF1D8: @ 81CF1D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r0, 0x7
	bl sub_81C763C
	adds r6, r0, 0
	ldr r5, [r6, 0xC]
	ldr r4, [r6, 0x10]
	movs r0, 0
	mov r8, r0
	cmp r5, 0xD
	bgt _081CF268
_081CF1F4:
	cmp r4, 0x1D
	bgt _081CF260
	lsls r0, r5, 24
	lsrs r7, r0, 24
_081CF1FC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CF23A
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r7
	lsls r1, r4, 24
	lsrs r1, 24
	lsls r3, r1, 8
	ldr r2, =0xffff00ff
	ands r0, r2
	orrs r0, r3
	str r0, [sp]
	ldr r2, [r6, 0x14]
	adds r0, r7, 0
	bl GetBoxMonDataAt
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CF2C4
_081CF23A:
	movs r0, 0x1
	add r8, r0
	adds r4, 0x1
	mov r0, r8
	cmp r0, 0xE
	ble _081CF25C
	str r5, [r6, 0xC]
	str r4, [r6, 0x10]
	movs r0, 0x3
	b _081CF26A
	.pool
_081CF25C:
	cmp r4, 0x1D
	ble _081CF1FC
_081CF260:
	movs r4, 0
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CF1F4
_081CF268:
	movs r0, 0x1
_081CF26A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF1D8

	thumb_func_start sub_81CF278
sub_81CF278: @ 81CF278
	push {r4-r6,lr}
	movs r0, 0x7
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, [r5, 0x20]
	ldrh r6, [r0]
	ldrh r4, [r0, 0x6]
	movs r1, 0x1
	strh r1, [r0, 0x6]
	movs r3, 0x1
	cmp r3, r6
	bge _081CF2B8
_081CF292:
	ldr r2, [r5, 0x20]
	lsls r0, r3, 2
	adds r1, r2, r0
	ldrh r0, [r1, 0x6]
	cmp r0, r4
	bne _081CF2AC
	subs r0, r3, 0x1
	lsls r0, 2
	adds r0, r2, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r1, 0x6]
	adds r0, r3, 0x1
	b _081CF2B2
_081CF2AC:
	adds r4, r0, 0
	adds r0, r3, 0x1
	strh r0, [r1, 0x6]
_081CF2B2:
	adds r3, r0, 0
	cmp r3, r6
	blt _081CF292
_081CF2B8:
	movs r0, 0x1
	str r0, [r5, 0x18]
	movs r0, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF278

	thumb_func_start sub_81CF2C4
sub_81CF2C4: @ 81CF2C4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CF2F4
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CF2DA:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CF2E8
	adds r2, r3, 0
	b _081CF2EA
_081CF2E8:
	adds r1, r3, 0x1
_081CF2EA:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CF2DA
_081CF2F4:
	ldr r0, [r5, 0x20]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CF318
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CF302:
	ldr r0, [r5, 0x20]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CF302
_081CF318:
	ldr r0, [r5, 0x20]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x20]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF2C4

	thumb_func_start sub_81CF330
sub_81CF330: @ 81CF330
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF360
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CF362
	.pool
_081CF360:
	movs r0, 0
_081CF362:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF330

	thumb_func_start sub_81CF368
sub_81CF368: @ 81CF368
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0x8
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF398
	ldr r0, =sub_81CF418
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CF39A
	.pool
_081CF398:
	movs r0, 0
_081CF39A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF368

	thumb_func_start sub_81CF3A0
sub_81CF3A0: @ 81CF3A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08623598
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CF3E4
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF3A0

	thumb_func_start sub_81CF3D0
sub_81CF3D0: @ 81CF3D0
	push {lr}
	movs r0, 0x8
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3D0

	thumb_func_start sub_81CF3E4
sub_81CF3E4: @ 81CF3E4
	push {lr}
	movs r0, 0x8
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CF3E4

	thumb_func_start sub_81CF3F8
sub_81CF3F8: @ 81CF3F8
	push {r4,lr}
	movs r0, 0x8
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0x8
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CF3F8

	thumb_func_start sub_81CF418
sub_81CF418: @ 81CF418
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CF42C
	b _081CF56E
_081CF42C:
	lsls r0, r4, 2
	ldr r1, =_081CF43C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CF43C:
	.4byte _081CF454
	.4byte _081CF4AC
	.4byte _081CF4C0
	.4byte _081CF4E0
	.4byte _081CF4F6
	.4byte _081CF55A
_081CF454:
	ldr r0, =gUnknown_08623590
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_086233E4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086234AC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_086233C4
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CF498:
	movs r0, 0
	b _081CF570
	.pool
_081CF4AC:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	bl sub_81CF0C0
	cmp r0, 0
	beq _081CF56A
	b _081CF498
_081CF4C0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	ldr r0, =gUnknown_08623570
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81CF88C
	b _081CF498
	.pool
_081CF4E0:
	bl sub_81C8224
	cmp r0, 0
	bne _081CF56A
	adds r0, r5, 0
	bl sub_81CF7C8
	movs r0, 0x3
	bl sub_81C7BA4
	b _081CF498
_081CF4F6:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CF56A
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CF552
	bl sub_81C76AC
	adds r4, r0, 0
	adds r4, 0x8
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_81C7DFC
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
_081CF552:
	movs r0, 0x1
	bl sub_81C7AC0
	b _081CF498
_081CF55A:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CF56A
	bl sub_81C8010
	cmp r0, 0
	beq _081CF56E
_081CF56A:
	movs r0, 0x2
	b _081CF570
_081CF56E:
	movs r0, 0x4
_081CF570:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF418

	thumb_func_start sub_81CF578
sub_81CF578: @ 81CF578
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF5C6
	cmp r4, 0x1
	bgt _081CF592
	cmp r4, 0
	beq _081CF59C
	b _081CF5E6
_081CF592:
	cmp r4, 0x2
	beq _081CF5CE
	cmp r4, 0x3
	beq _081CF5D8
	b _081CF5E6
_081CF59C:
	bl sub_81C8658
	cmp r0, 0x1
	beq _081CF5B4
	cmp r0, 0x1
	bgt _081CF5AE
	cmp r0, 0
	beq _081CF5E6
	b _081CF5D4
_081CF5AE:
	cmp r0, 0x2
	beq _081CF5BE
	b _081CF5D4
_081CF5B4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF5E8
_081CF5BE:
	movs r0, 0x5
	bl PlaySE
	b _081CF5D4
_081CF5C6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF5E2
_081CF5CE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF5D4:
	movs r0, 0
	b _081CF5E8
_081CF5D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF5E6
_081CF5E2:
	movs r0, 0x2
	b _081CF5E8
_081CF5E6:
	movs r0, 0x4
_081CF5E8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF578

	thumb_func_start sub_81CF5F0
sub_81CF5F0: @ 81CF5F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF63E
	cmp r4, 0x1
	bgt _081CF60A
	cmp r4, 0
	beq _081CF614
	b _081CF65E
_081CF60A:
	cmp r4, 0x2
	beq _081CF646
	cmp r4, 0x3
	beq _081CF650
	b _081CF65E
_081CF614:
	bl sub_81C868C
	cmp r0, 0x1
	beq _081CF62C
	cmp r0, 0x1
	bgt _081CF626
	cmp r0, 0
	beq _081CF65E
	b _081CF64C
_081CF626:
	cmp r0, 0x2
	beq _081CF636
	b _081CF64C
_081CF62C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF660
_081CF636:
	movs r0, 0x5
	bl PlaySE
	b _081CF64C
_081CF63E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF65A
_081CF646:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF64C:
	movs r0, 0
	b _081CF660
_081CF650:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF65E
_081CF65A:
	movs r0, 0x2
	b _081CF660
_081CF65E:
	movs r0, 0x4
_081CF660:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF5F0

	thumb_func_start sub_81CF668
sub_81CF668: @ 81CF668
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF6B6
	cmp r4, 0x1
	bgt _081CF682
	cmp r4, 0
	beq _081CF68C
	b _081CF6D6
_081CF682:
	cmp r4, 0x2
	beq _081CF6BE
	cmp r4, 0x3
	beq _081CF6C8
	b _081CF6D6
_081CF68C:
	bl sub_81C86CC
	cmp r0, 0x1
	beq _081CF6A4
	cmp r0, 0x1
	bgt _081CF69E
	cmp r0, 0
	beq _081CF6D6
	b _081CF6C4
_081CF69E:
	cmp r0, 0x2
	beq _081CF6AE
	b _081CF6C4
_081CF6A4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF6D8
_081CF6AE:
	movs r0, 0x5
	bl PlaySE
	b _081CF6C4
_081CF6B6:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF6D2
_081CF6BE:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF6C4:
	movs r0, 0
	b _081CF6D8
_081CF6C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF6D6
_081CF6D2:
	movs r0, 0x2
	b _081CF6D8
_081CF6D6:
	movs r0, 0x4
_081CF6D8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF668

	thumb_func_start sub_81CF6E0
sub_81CF6E0: @ 81CF6E0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081CF72E
	cmp r4, 0x1
	bgt _081CF6FA
	cmp r4, 0
	beq _081CF704
	b _081CF74E
_081CF6FA:
	cmp r4, 0x2
	beq _081CF736
	cmp r4, 0x3
	beq _081CF740
	b _081CF74E
_081CF704:
	bl sub_81C870C
	cmp r0, 0x1
	beq _081CF71C
	cmp r0, 0x1
	bgt _081CF716
	cmp r0, 0
	beq _081CF74E
	b _081CF73C
_081CF716:
	cmp r0, 0x2
	beq _081CF726
	b _081CF73C
_081CF71C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081CF750
_081CF726:
	movs r0, 0x5
	bl PlaySE
	b _081CF73C
_081CF72E:
	bl sub_81C8630
	cmp r0, 0
	bne _081CF74A
_081CF736:
	adds r0, r5, 0
	bl sub_81CF7F4
_081CF73C:
	movs r0, 0
	b _081CF750
_081CF740:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081CF74E
_081CF74A:
	movs r0, 0x2
	b _081CF750
_081CF74E:
	movs r0, 0x4
_081CF750:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF6E0

	thumb_func_start sub_81CF758
sub_81CF758: @ 81CF758
	push {lr}
	cmp r0, 0
	beq _081CF764
	cmp r0, 0x1
	beq _081CF778
	b _081CF790
_081CF764:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081CF792
_081CF778:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CF788
	bl sub_81C78C0
	cmp r0, 0
	beq _081CF78C
_081CF788:
	movs r0, 0x2
	b _081CF792
_081CF78C:
	bl sub_81C7FDC
_081CF790:
	movs r0, 0x4
_081CF792:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF758

	thumb_func_start sub_81CF798
sub_81CF798: @ 81CF798
	push {lr}
	cmp r0, 0
	beq _081CF7A4
	cmp r0, 0x1
	beq _081CF7B4
	b _081CF7C0
_081CF7A4:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081CF7C2
_081CF7B4:
	bl sub_81C7B34
	cmp r0, 0
	beq _081CF7C0
	movs r0, 0x2
	b _081CF7C2
_081CF7C0:
	movs r0, 0x4
_081CF7C2:
	pop {r1}
	bx r1
	thumb_func_end sub_81CF798

	thumb_func_start sub_81CF7C8
sub_81CF7C8: @ 81CF7C8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086235B4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81CF7F4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7C8

	thumb_func_start sub_81CF7F4
sub_81CF7F4: @ 81CF7F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	bl sub_81CF0F0
	adds r7, r0, 0
	bl DynamicPlaceholderTextUtil_Reset
	ldr r4, =gStringVar1
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0xFF
	strb r0, [r4]
	ldr r5, =gStringVar2
	ldr r1, =gText_NumberF700
	adds r0, r5, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x1
	mov r10, r1
	str r1, [sp]
	movs r1, 0xFF
	mov r9, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	mov r1, r8
	ldrb r0, [r1, 0x8]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x22
	bl AddTextPrinterParameterized
	mov r1, r8
	ldrb r0, [r1, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF7F4

	thumb_func_start sub_81CF88C
sub_81CF88C: @ 81CF88C
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CF0D0
	str r0, [sp]
	bl sub_81CF0E0
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CF10C
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81CF8E4
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_08623594
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF88C

	thumb_func_start sub_81CF8E4
sub_81CF8E4: @ 81CF8E4
	push {r4-r7,lr}
	adds r2, r0, 0
	adds r6, r1, 0
	ldrb r0, [r2]
	cmp r0, 0xE
	bne _081CF924
	ldrb r1, [r2, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromMonExp
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081CF94A
	.pool
_081CF924:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBoxMonData
_081CF94A:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081CF974
	cmp r5, 0xFE
	beq _081CF97C
	ldr r1, =gUnknown_086235D4
	b _081CF97E
	.pool
_081CF974:
	ldr r1, =gUnknown_086235BC
	b _081CF97E
	.pool
_081CF97C:
	ldr r1, =gUnknown_086235C8
_081CF97E:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x28
	bl sub_81DB494
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CF8E4

	thumb_func_start sub_81CF9BC
sub_81CF9BC: @ 81CF9BC
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF9FC
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl sub_81C761C
	str r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CF9FC
	ldr r0, =sub_81CFA68
	str r0, [r4]
	ldr r0, =sub_81CFB74
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CF9FE
	.pool
_081CF9FC:
	movs r0, 0
_081CF9FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF9BC

	thumb_func_start sub_81CFA04
sub_81CFA04: @ 81CFA04
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFA2C
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x1C]
	ldr r0, =sub_81CFA88
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x14]
	b _081CFA2E
	.pool
_081CFA2C:
	movs r0, 0
_081CFA2E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA04

	thumb_func_start sub_81CFA34
sub_81CFA34: @ 81CFA34
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA34

	thumb_func_start sub_81CFA48
sub_81CFA48: @ 81CFA48
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x18]
	cmp r0, 0
	bne _081CFA5C
	movs r0, 0x12
	bl sub_81C7650
_081CFA5C:
	movs r0, 0x9
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81CFA48

	thumb_func_start sub_81CFA68
sub_81CFA68: @ 81CFA68
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl sub_81C70D8
	cmp r0, 0
	bne _081CFA7A
	ldr r0, =sub_81CFA88
	str r0, [r4]
_081CFA7A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA68

	thumb_func_start sub_81CFA88
sub_81CFA88: @ 81CFA88
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CFAA0
	movs r0, 0x1
	b _081CFAFE
	.pool
_081CFAA0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CFAAC
	movs r0, 0x2
	b _081CFAFE
_081CFAAC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CFABA
	movs r0, 0x3
	b _081CFAFE
_081CFABA:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CFACA
	movs r0, 0x4
	b _081CFAFE
_081CFACA:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CFAE0
	str r2, [r4, 0x18]
	ldr r0, =sub_81CFB08
	str r0, [r4]
	movs r0, 0x5
	b _081CFAFE
	.pool
_081CFAE0:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CFAEE
	movs r0, 0
	b _081CFAFE
_081CFAEE:
	bl sub_81C875C
	ldr r1, [r4, 0x1C]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x18]
	ldr r0, =sub_81CFB10
	str r0, [r4]
	movs r0, 0x6
_081CFAFE:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA88

	thumb_func_start sub_81CFB08
sub_81CFB08: @ 81CFB08
	ldr r0, =0x000186a5
	bx lr
	.pool
	thumb_func_end sub_81CFB08

	thumb_func_start sub_81CFB10
sub_81CFB10: @ 81CFB10
	ldr r0, =0x000186ad
	bx lr
	.pool
	thumb_func_end sub_81CFB10

	thumb_func_start sub_81CFB18
sub_81CFB18: @ 81CFB18
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x14]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB18

	thumb_func_start sub_81CFB28
sub_81CFB28: @ 81CFB28
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB28

	thumb_func_start sub_81CFB38
sub_81CFB38: @ 81CFB38
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB38

	thumb_func_start sub_81CFB48
sub_81CFB48: @ 81CFB48
	push {r4,lr}
	movs r0, 0x9
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C875C
	ldr r1, [r4, 0x1C]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB48

	thumb_func_start sub_81CFB64
sub_81CFB64: @ 81CFB64
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB64

	thumb_func_start sub_81CFB74
sub_81CFB74: @ 81CFB74
	push {lr}
	ldr r2, =gUnknown_086235D8
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB74

	thumb_func_start sub_81CFB8C
sub_81CFB8C: @ 81CFB8C
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x9
	bl sub_81C763C
	adds r6, r0, 0
	ldr r0, [r6, 0x1C]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x1C]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CFBB0:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFC10
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x52
	bl GetMonData
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFC0A
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CFCEC
_081CFC0A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFBB0
_081CFC10:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB8C

	thumb_func_start sub_81CFC2C
sub_81CFC2C: @ 81CFC2C
	push {lr}
	movs r0, 0x9
	bl sub_81C763C
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC2C

	thumb_func_start sub_81CFC40
sub_81CFC40: @ 81CFC40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0x9
	bl sub_81C763C
	mov r8, r0
	ldr r7, [r0, 0xC]
	ldr r6, [r0, 0x10]
	movs r0, 0
	mov r9, r0
	cmp r7, 0xD
	bgt _081CFCD4
	b _081CFCC8
_081CFC60:
	adds r0, r7, 0
	adds r1, r6, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CFCA6
	lsls r0, r7, 24
	lsrs r5, r0, 24
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x52
	bl GetBoxMonDataAt
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFCA6
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r5
	lsls r2, r4, 8
	ldr r1, =0xffff00ff
	ands r0, r1
	orrs r0, r2
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl sub_81CFCEC
_081CFCA6:
	movs r1, 0x1
	add r9, r1
	adds r6, 0x1
	mov r0, r9
	cmp r0, 0xE
	ble _081CFCC8
	mov r1, r8
	str r7, [r1, 0xC]
	str r6, [r1, 0x10]
	movs r0, 0x3
	b _081CFCDC
	.pool
_081CFCC8:
	cmp r6, 0x1D
	ble _081CFC60
	movs r6, 0
	adds r7, 0x1
	cmp r7, 0xD
	ble _081CFCC8
_081CFCD4:
	movs r0, 0x1
	mov r1, r8
	str r0, [r1, 0x14]
	movs r0, 0x4
_081CFCDC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC40

	thumb_func_start sub_81CFCEC
sub_81CFCEC: @ 81CFCEC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CFD1C
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CFD02:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CFD10
	adds r2, r3, 0
	b _081CFD12
_081CFD10:
	adds r1, r3, 0x1
_081CFD12:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CFD02
_081CFD1C:
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CFD40
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CFD2A:
	ldr r0, [r5, 0x1C]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CFD2A
_081CFD40:
	ldr r0, [r5, 0x1C]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x1C]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFCEC

	thumb_func_start sub_81CFD58
sub_81CFD58: @ 81CFD58
	push {r4-r6,lr}
	movs r5, 0
_081CFD5C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFD8A
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFD8A
	adds r0, r4, 0
	movs r1, 0x53
	bl GetMonData
	cmp r0, 0
	bne _081CFDB2
_081CFD8A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFD5C
	movs r5, 0
_081CFD92:
	movs r4, 0
	lsls r6, r5, 24
_081CFD96:
	adds r0, r5, 0
	adds r1, r4, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CFDBC
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	movs r2, 0x53
	bl GetBoxMonDataAt
	cmp r0, 0
	beq _081CFDBC
_081CFDB2:
	movs r0, 0x1
	b _081CFDCA
	.pool
_081CFDBC:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _081CFD96
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CFD92
	movs r0, 0
_081CFDCA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFD58

	thumb_func_start sub_81CFDD0
sub_81CFDD0: @ 81CFDD0
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE00
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CFE02
	.pool
_081CFE00:
	movs r0, 0
_081CFE02:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFDD0

	thumb_func_start sub_81CFE08
sub_81CFE08: @ 81CFE08
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE38
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CFE3A
	.pool
_081CFE38:
	movs r0, 0
_081CFE3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE08

	thumb_func_start sub_81CFE40
sub_81CFE40: @ 81CFE40
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_086237B8
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CFE40

	thumb_func_start sub_81CFE70
sub_81CFE70: @ 81CFE70
	push {lr}
	movs r0, 0xA
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE70

	thumb_func_start sub_81CFE84
sub_81CFE84: @ 81CFE84
	push {lr}
	movs r0, 0xA
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE84

	thumb_func_start sub_81CFE98
sub_81CFE98: @ 81CFE98
	push {r4,lr}
	movs r0, 0xA
	bl sub_81C763C
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0xA
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFE98

	thumb_func_start sub_81CFEB8
sub_81CFEB8: @ 81CFEB8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CFECC
	b _081CFFF2
_081CFECC:
	lsls r0, r4, 2
	ldr r1, =_081CFEDC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CFEDC:
	.4byte _081CFEF4
	.4byte _081CFF48
	.4byte _081CFF76
	.4byte _081CFF94
	.4byte _081CFFA4
	.4byte _081CFFDE
_081CFEF4:
	ldr r0, =gUnknown_086237B0
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_08623604
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086236CC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_086235E4
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CFF32:
	movs r0, 0
	b _081CFFF4
	.pool
_081CFF48:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	bl sub_81CFB18
	cmp r0, 0
	beq _081CFFEE
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	b _081CFF32
_081CFF76:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	ldr r0, =gUnknown_08623790
	movs r1, 0x20
	movs r2, 0x20
	bl sub_81C7944
	bl sub_81D0304
	b _081CFF32
	.pool
_081CFF94:
	bl sub_81C8224
	cmp r0, 0
	bne _081CFFEE
	adds r0, r5, 0
	bl sub_81D024C
	b _081CFF32
_081CFFA4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x9
	bl sub_81C7BA4
	movs r0, 0x1
	bl sub_81C7AC0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CFF32
	movs r0, 0x2
	bl sub_81C7DFC
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CFF32
_081CFFDE:
	bl sub_81C7B34
	cmp r0, 0
	bne _081CFFEE
	bl sub_81C8010
	cmp r0, 0
	beq _081CFFF2
_081CFFEE:
	movs r0, 0x2
	b _081CFFF4
_081CFFF2:
	movs r0, 0x4
_081CFFF4:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFEB8

	thumb_func_start sub_81CFFFC
sub_81CFFFC: @ 81CFFFC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D004A
	cmp r4, 0x1
	bgt _081D0016
	cmp r4, 0
	beq _081D0020
	b _081D006A
_081D0016:
	cmp r4, 0x2
	beq _081D0052
	cmp r4, 0x3
	beq _081D005C
	b _081D006A
_081D0020:
	bl sub_81C8658
	cmp r0, 0x1
	beq _081D0038
	cmp r0, 0x1
	bgt _081D0032
	cmp r0, 0
	beq _081D006A
	b _081D0058
_081D0032:
	cmp r0, 0x2
	beq _081D0042
	b _081D0058
_081D0038:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D006C
_081D0042:
	movs r0, 0x5
	bl PlaySE
	b _081D0058
_081D004A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0066
_081D0052:
	adds r0, r5, 0
	bl sub_81D0288
_081D0058:
	movs r0, 0
	b _081D006C
_081D005C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D006A
_081D0066:
	movs r0, 0x2
	b _081D006C
_081D006A:
	movs r0, 0x4
_081D006C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFFFC

	thumb_func_start sub_81D0074
sub_81D0074: @ 81D0074
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D00C2
	cmp r4, 0x1
	bgt _081D008E
	cmp r4, 0
	beq _081D0098
	b _081D00E2
_081D008E:
	cmp r4, 0x2
	beq _081D00CA
	cmp r4, 0x3
	beq _081D00D4
	b _081D00E2
_081D0098:
	bl sub_81C868C
	cmp r0, 0x1
	beq _081D00B0
	cmp r0, 0x1
	bgt _081D00AA
	cmp r0, 0
	beq _081D00E2
	b _081D00D0
_081D00AA:
	cmp r0, 0x2
	beq _081D00BA
	b _081D00D0
_081D00B0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D00E4
_081D00BA:
	movs r0, 0x5
	bl PlaySE
	b _081D00D0
_081D00C2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D00DE
_081D00CA:
	adds r0, r5, 0
	bl sub_81D0288
_081D00D0:
	movs r0, 0
	b _081D00E4
_081D00D4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D00E2
_081D00DE:
	movs r0, 0x2
	b _081D00E4
_081D00E2:
	movs r0, 0x4
_081D00E4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0074

	thumb_func_start sub_81D00EC
sub_81D00EC: @ 81D00EC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D013A
	cmp r4, 0x1
	bgt _081D0106
	cmp r4, 0
	beq _081D0110
	b _081D015A
_081D0106:
	cmp r4, 0x2
	beq _081D0142
	cmp r4, 0x3
	beq _081D014C
	b _081D015A
_081D0110:
	bl sub_81C86CC
	cmp r0, 0x1
	beq _081D0128
	cmp r0, 0x1
	bgt _081D0122
	cmp r0, 0
	beq _081D015A
	b _081D0148
_081D0122:
	cmp r0, 0x2
	beq _081D0132
	b _081D0148
_081D0128:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D015C
_081D0132:
	movs r0, 0x5
	bl PlaySE
	b _081D0148
_081D013A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0156
_081D0142:
	adds r0, r5, 0
	bl sub_81D0288
_081D0148:
	movs r0, 0
	b _081D015C
_081D014C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D015A
_081D0156:
	movs r0, 0x2
	b _081D015C
_081D015A:
	movs r0, 0x4
_081D015C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D00EC

	thumb_func_start sub_81D0164
sub_81D0164: @ 81D0164
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D01B2
	cmp r4, 0x1
	bgt _081D017E
	cmp r4, 0
	beq _081D0188
	b _081D01D2
_081D017E:
	cmp r4, 0x2
	beq _081D01BA
	cmp r4, 0x3
	beq _081D01C4
	b _081D01D2
_081D0188:
	bl sub_81C870C
	cmp r0, 0x1
	beq _081D01A0
	cmp r0, 0x1
	bgt _081D019A
	cmp r0, 0
	beq _081D01D2
	b _081D01C0
_081D019A:
	cmp r0, 0x2
	beq _081D01AA
	b _081D01C0
_081D01A0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D01D4
_081D01AA:
	movs r0, 0x5
	bl PlaySE
	b _081D01C0
_081D01B2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D01CE
_081D01BA:
	adds r0, r5, 0
	bl sub_81D0288
_081D01C0:
	movs r0, 0
	b _081D01D4
_081D01C4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D01D2
_081D01CE:
	movs r0, 0x2
	b _081D01D4
_081D01D2:
	movs r0, 0x4
_081D01D4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0164

	thumb_func_start sub_81D01DC
sub_81D01DC: @ 81D01DC
	push {lr}
	cmp r0, 0
	beq _081D01E8
	cmp r0, 0x1
	beq _081D01FC
	b _081D0214
_081D01E8:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081D0216
_081D01FC:
	bl sub_81C7B34
	cmp r0, 0
	bne _081D020C
	bl sub_81C78C0
	cmp r0, 0
	beq _081D0210
_081D020C:
	movs r0, 0x2
	b _081D0216
_081D0210:
	bl sub_81C7FDC
_081D0214:
	movs r0, 0x4
_081D0216:
	pop {r1}
	bx r1
	thumb_func_end sub_81D01DC

	thumb_func_start sub_81D021C
sub_81D021C: @ 81D021C
	push {lr}
	cmp r0, 0
	beq _081D0228
	cmp r0, 0x1
	beq _081D0238
	b _081D0244
_081D0228:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0246
_081D0238:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0244
	movs r0, 0x2
	b _081D0246
_081D0244:
	movs r0, 0x4
_081D0246:
	pop {r1}
	bx r1
	thumb_func_end sub_81D021C

	thumb_func_start sub_81D024C
sub_81D024C: @ 81D024C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086237D4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r4, 0x8]
	movs r1, 0
	bl sub_81D02B0
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81D0288
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D024C

	thumb_func_start sub_81D0288
sub_81D0288: @ 81D0288
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_81C875C
	adds r4, r0, 0
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r5, 0x8]
	adds r4, 0x1
	adds r1, r4, 0
	bl sub_81D02B0
	ldrb r0, [r5, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0288

	thumb_func_start sub_81D02B0
sub_81D02B0: @ 81D02B0
	push {r4,r5,lr}
	sub sp, 0x1C
	adds r4, r0, 0
	adds r5, r2, 0
	add r0, sp, 0xC
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r4, 24
	lsrs r4, 24
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
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	add sp, 0x1C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D02B0

	thumb_func_start sub_81D0304
sub_81D0304: @ 81D0304
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CFB28
	str r0, [sp]
	bl sub_81CFB38
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CFB64
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81D035C
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_086237B4
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0304

	thumb_func_start sub_81D035C
sub_81D035C: @ 81D035C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r1, 0
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0xE
	bne _081D03A4
	ldrb r1, [r7, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081D03CC
	.pool
_081D03A4:
	ldrb r0, [r7]
	ldrb r1, [r7, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBoxMonData
_081D03CC:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081D03F8
	cmp r5, 0xFE
	beq _081D0400
	ldr r1, =gUnknown_086237F4
	b _081D0402
	.pool
_081D03F8:
	ldr r1, =gUnknown_086237DC
	b _081D0402
	.pool
_081D0400:
	ldr r1, =gUnknown_086237E8
_081D0402:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x36
	bl sub_81DB494
	adds r6, r0, 0
	ldrh r1, [r7, 0x2]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D035C

	thumb_func_start sub_81D0450
sub_81D0450: @ 81D0450
	push {r4,lr}
	movs r0, 0xD
	movs r1, 0x9C
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081D0498
	movs r0, 0x12
	bl sub_81C763C
	str r0, [r4, 0x8]
	cmp r0, 0
	beq _081D0498
	adds r0, r4, 0
	bl sub_81D0814
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	ldr r1, =gKeyRepeatContinueDelay
	movs r0, 0x3
	strh r0, [r1]
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0xA
	strh r0, [r1]
	movs r0, 0x1
	b _081D049A
	.pool
_081D0498:
	movs r0, 0
_081D049A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0450

	thumb_func_start sub_81D04A0
sub_81D04A0: @ 81D04A0
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	adds r1, r0, 0
	adds r1, 0x98
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81D04A0

	thumb_func_start sub_81D04B8
sub_81D04B8: @ 81D04B8
	push {lr}
	movs r0, 0xD
	bl sub_81C7650
	pop {r0}
	bx r0
	thumb_func_end sub_81D04B8

	thumb_func_start sub_81D04C4
sub_81D04C4: @ 81D04C4
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D04E4
	ldr r3, [r4, 0x8]
	ldrh r0, [r3, 0x2]
	cmp r0, 0
	beq _081D04E4
	subs r0, 0x1
	b _081D04FC
	.pool
_081D04E4:
	ldrh r1, [r2, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D050C
	ldr r3, [r4, 0x8]
	ldrh r1, [r3, 0x2]
	ldrh r0, [r3]
	subs r0, 0x1
	cmp r1, r0
	bge _081D050C
	adds r0, r1, 0x1
_081D04FC:
	movs r1, 0
	strh r0, [r3, 0x2]
	strh r1, [r4, 0xC]
	adds r0, r4, 0
	bl sub_81D0814
	movs r0, 0x1
	b _081D053E
_081D050C:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _081D0528
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D0548
	str r0, [r1]
	movs r0, 0x2
	b _081D053E
	.pool
_081D0528:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _081D0534
	movs r0, 0
	b _081D053E
_081D0534:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D05D4
	str r0, [r1]
	movs r0, 0x5
_081D053E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D04C4

	thumb_func_start sub_81D0548
sub_81D0548: @ 81D0548
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D0562
	adds r0, r4, 0
	bl sub_81D05DC
	cmp r0, 0
	bne _081D05A4
_081D0562:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D0578
	adds r0, r4, 0
	bl sub_81D061C
	cmp r0, 0
	bne _081D05A4
_081D0578:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081D058E
	adds r0, r4, 0
	bl sub_81D0664
	cmp r0, 0
	bne _081D05A4
_081D058E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D05AC
	adds r0, r4, 0
	bl sub_81D0688
	cmp r0, 0
	beq _081D05AC
_081D05A4:
	movs r0, 0x3
	b _081D05CA
	.pool
_081D05AC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D05C0
	movs r0, 0
	b _081D05CA
	.pool
_081D05C0:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	movs r0, 0x4
_081D05CA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D0548

	thumb_func_start sub_81D05D4
sub_81D05D4: @ 81D05D4
	ldr r0, =0x000186ae
	bx lr
	.pool
	thumb_func_end sub_81D05D4

	thumb_func_start sub_81D05DC
sub_81D05DC: @ 81D05DC
	push {r4,lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r2, r0, 0
	cmp r2, 0x18
	bhi _081D05F0
	cmp r2, 0x8
	bls _081D0612
	subs r0, 0x9
	b _081D060C
_081D05F0:
	ldrh r3, [r1, 0x10]
	adds r2, r3, 0
	cmp r2, 0
	beq _081D0612
	ldrh r0, [r1, 0xC]
	subs r0, 0x1B
	ldrh r4, [r1, 0xE]
	adds r0, r4
	strh r0, [r1, 0xC]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r2
	bcc _081D060E
	subs r0, r3, 0x1
_081D060C:
	strh r0, [r1, 0xC]
_081D060E:
	movs r0, 0x1
	b _081D0614
_081D0612:
	movs r0, 0
_081D0614:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D05DC

	thumb_func_start sub_81D061C
sub_81D061C: @ 81D061C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0xC]
	adds r1, r0, 0
	cmp r1, 0x18
	bhi _081D065C
	ldrh r3, [r2, 0xE]
	cmp r1, r3
	bcs _081D0640
	adds r0, 0x9
	strh r0, [r2, 0xC]
	ldrh r1, [r2, 0x10]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bcc _081D0658
	subs r0, r1, 0x1
	b _081D0656
_081D0640:
	ldrh r0, [r2, 0x12]
	cmp r0, 0
	beq _081D065C
	ldrh r1, [r2, 0xC]
	ldrh r0, [r2, 0xE]
	subs r0, r1, r0
	ldrh r1, [r2, 0x12]
	cmp r0, r1
	blt _081D0654
	subs r0, r1, 0x1
_081D0654:
	adds r0, 0x1B
_081D0656:
	strh r0, [r2, 0xC]
_081D0658:
	movs r0, 0x1
	b _081D065E
_081D065C:
	movs r0, 0
_081D065E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D061C

	thumb_func_start sub_81D0664
sub_81D0664: @ 81D0664
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D067C
	movs r0, 0
	b _081D0682
_081D067C:
	subs r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
_081D0682:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0664

	thumb_func_start sub_81D0688
sub_81D0688: @ 81D0688
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bgt _081D06BC
	cmp r4, 0x1A
	bhi _081D06AC
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	cmp r4, r0
	bge _081D06BC
	b _081D06B4
_081D06AC:
	ldrh r0, [r5, 0x12]
	subs r0, 0x1
	cmp r1, r0
	bge _081D06BC
_081D06B4:
	adds r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
	b _081D06BE
_081D06BC:
	movs r0, 0
_081D06BE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0688

	thumb_func_start sub_81D06C4
sub_81D06C4: @ 81D06C4
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r0, [r0, 0x8]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06C4

	thumb_func_start sub_81D06D4
sub_81D06D4: @ 81D06D4
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06D4

	thumb_func_start sub_81D06E4
sub_81D06E4: @ 81D06E4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0730
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetMonData
	adds r0, r4, 0
	bl GetLevelFromMonExp
	strb r0, [r7]
	adds r0, r4, 0
	bl GetMonGender
	strb r0, [r6]
	b _081D0752
	.pool
_081D0730:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	strb r0, [r6]
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetBoxMonData
_081D0752:
	adds r0, r5, 0
	bl StringGetEnd10
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D06E4

	thumb_func_start sub_81D0760
sub_81D0760: @ 81D0760
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D07AC
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	b _081D07D0
	.pool
_081D07AC:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	movs r1, 0xB
	bl GetBoxMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetBoxMonData
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBoxMonData
_081D07D0:
	str r0, [r7]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0760

	thumb_func_start sub_81D07D8
sub_81D07D8: @ 81D07D8
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	beq _081D07FA
	ldrb r1, [r1, 0x1]
	movs r2, 0x52
	bl GetBoxMonDataAt
	b _081D080A
_081D07FA:
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x52
	bl GetMonData
_081D080A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D07D8

	thumb_func_start sub_81D0814
sub_81D0814: @ 81D0814
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r1, 0x4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0848
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x53
	bl GetMonData
	b _081D0852
	.pool
_081D0848:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	movs r2, 0x53
	bl GetBoxMonDataAt
_081D0852:
	mov r12, r0
	movs r0, 0
	strh r0, [r5, 0x10]
	strh r0, [r5, 0x12]
	movs r6, 0
	ldr r0, =gUnknown_086237F8
	mov r9, r0
	mov r10, r9
_081D0862:
	lsls r2, r6, 2
	mov r3, r9
	adds r1, r2, r3
	movs r0, 0x1
	ldrb r3, [r1]
	lsls r0, r3
	subs r4, r0, 0x1
	mov r0, r12
	ands r4, r0
	ldrb r0, [r1, 0x3]
	adds r7, r2, 0
	cmp r0, 0
	bne _081D08AC
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x14
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D0890:
	ldrh r0, [r5, 0x10]
	adds r1, r0, 0x1
	strh r1, [r5, 0x10]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D0890
	b _081D08D6
	.pool
_081D08AC:
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x78
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D08C0:
	ldrh r0, [r5, 0x12]
	adds r1, r0, 0x1
	strh r1, [r5, 0x12]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D08C0
_081D08D6:
	mov r3, r9
	adds r0, r7, r3
	mov r1, r12
	ldrb r0, [r0]
	lsrs r1, r0
	mov r12, r1
	mov r6, r8
	cmp r6, 0x10
	bls _081D0862
	ldrh r0, [r5, 0x10]
	cmp r0, 0
	beq _081D0900
	subs r0, 0x1
	movs r1, 0x9
	bl __divsi3
	lsls r1, r0, 3
	adds r1, r0
	movs r0, 0
	strh r1, [r5, 0xE]
	b _081D0904
_081D0900:
	strh r0, [r5, 0xE]
	movs r0, 0x1B
_081D0904:
	strh r0, [r5, 0xC]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0814

	thumb_func_start sub_81D0914
sub_81D0914: @ 81D0914
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl sub_81C763C
	ldrh r1, [r0, 0x10]
	str r1, [r4]
	adds r0, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0914

	thumb_func_start sub_81D092C
sub_81D092C: @ 81D092C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl sub_81C763C
	ldrh r1, [r0, 0x12]
	str r1, [r4]
	adds r0, 0x78
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D092C

	thumb_func_start sub_81D0944
sub_81D0944: @ 81D0944
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0944

	thumb_func_start sub_81D0954
sub_81D0954: @ 81D0954
	push {lr}
	movs r0, 0xD
	bl sub_81C763C
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	cmp r0, 0x18
	ble _081D096C
	subs r0, 0x1B
	lsls r0, 2
	adds r1, 0x78
	b _081D0970
_081D096C:
	lsls r0, 2
	adds r1, 0x14
_081D0970:
	adds r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0954

	thumb_func_start sub_81D0978
sub_81D0978: @ 81D0978
	push {r4,lr}
	ldr r1, =0x0000101c
	movs r0, 0xE
	bl sub_81C761C
	adds r4, r0, 0
	cmp r4, 0
	beq _081D09A8
	ldr r0, =sub_81D0A6C
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r4, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r4]
	movs r0, 0x1
	b _081D09AA
	.pool
_081D09A8:
	movs r0, 0
_081D09AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0978

	thumb_func_start sub_81D09B0
sub_81D09B0: @ 81D09B0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	ldr r0, =gUnknown_08624BA0
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_81C7078
	str r0, [r5, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D09B0

	thumb_func_start sub_81D09E0
sub_81D09E0: @ 81D09E0
	push {lr}
	movs r0, 0xE
	bl sub_81C763C
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81D09E0

	thumb_func_start sub_81D09F4
sub_81D09F4: @ 81D09F4
	push {r4,lr}
	movs r0, 0xE
	bl sub_81C763C
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl RemoveWindow
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	ldrb r0, [r4, 0xC]
	bl RemoveWindow
	ldrb r0, [r4, 0xE]
	bl RemoveWindow
	adds r0, r4, 0
	bl sub_81D1178
	movs r0, 0x9
	bl FreeSpriteTilesByTag
	movs r0, 0xF
	bl FreeSpritePaletteByTag
	movs r0, 0x10
	bl FreeSpritePaletteByTag
	movs r0, 0x11
	bl FreeSpritePaletteByTag
	movs r0, 0x12
	bl FreeSpritePaletteByTag
	movs r0, 0x13
	bl FreeSpritePaletteByTag
	ldr r0, [r4, 0x14]
	bl FreeSpriteOamMatrix
	ldr r0, [r4, 0x14]
	bl DestroySprite
	movs r0, 0xE
	bl sub_81C7650
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D09F4

	thumb_func_start sub_81D0A58
sub_81D0A58: @ 81D0A58
	push {lr}
	movs r0, 0xE
	bl sub_81C763C
	ldr r0, [r0, 0x4]
	bl sub_81C70D8
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A58

	thumb_func_start sub_81D0A6C
sub_81D0A6C: @ 81D0A6C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x9
	bls _081D0A80
	b _081D0C48
_081D0A80:
	lsls r0, r4, 2
	ldr r1, =_081D0A90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0A90:
	.4byte _081D0AB8
	.4byte _081D0B04
	.4byte _081D0B74
	.4byte _081D0B88
	.4byte _081D0B9C
	.4byte _081D0BB0
	.4byte _081D0BC4
	.4byte _081D0BD8
	.4byte _081D0BE8
	.4byte _081D0C3C
_081D0AB8:
	ldr r0, =gUnknown_08624B98
	movs r1, 0x2
	bl sub_81C7B54
	ldr r1, =gUnknown_08DDE030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x1C
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DDE12C
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_08DDE010
	movs r1, 0x10
	movs r2, 0x20
	bl sub_81C7944
	b _081D0BBA
	.pool
_081D0B04:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _081D0B12
	b _081D0C44
_081D0B12:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	ldr r1, =gUnknown_086240B8
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0x1
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =0x0000081c
	adds r1, r5, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =gUnknown_08623FF8
	movs r1, 0x20
	movs r2, 0xA0
	bl sub_81C7944
	ldr r0, =gUnknown_08624098
	movs r1, 0xA0
	movs r2, 0x20
	bl sub_81C7944
	movs r0, 0x1
	b _081D0BBC
	.pool
_081D0B74:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0E60
	movs r0, 0
	b _081D0C4A
_081D0B88:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0FCC
	movs r0, 0
	b _081D0C4A
_081D0B9C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D10A4
	movs r0, 0
	b _081D0C4A
_081D0BB0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
_081D0BBA:
	movs r0, 0x2
_081D0BBC:
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081D0C4A
_081D0BC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D1148
	movs r0, 0x1
	b _081D0C4A
_081D0BD8:
	adds r0, r5, 0
	bl sub_81D12D8
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0C4A
_081D0BE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D13FC
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
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C4A
_081D0C3C:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0C48
_081D0C44:
	movs r0, 0x2
	b _081D0C4A
_081D0C48:
	movs r0, 0x4
_081D0C4A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A6C

	thumb_func_start sub_81D0C54
sub_81D0C54: @ 81D0C54
	push {lr}
	cmp r0, 0
	beq _081D0C60
	cmp r0, 0x1
	beq _081D0C70
	b _081D0C7C
_081D0C60:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C7E
_081D0C70:
	bl sub_81C7B34
	cmp r0, 0
	beq _081D0C7C
	movs r0, 0x2
	b _081D0C7E
_081D0C7C:
	movs r0, 0x4
_081D0C7E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C54

	thumb_func_start sub_81D0C84
sub_81D0C84: @ 81D0C84
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r4, r0, 0
	cmp r5, 0x6
	bhi _081D0D24
	lsls r0, r5, 2
	ldr r1, =_081D0CA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0CA4:
	.4byte _081D0CC0
	.4byte _081D0CD0
	.4byte _081D0CE4
	.4byte _081D0CEE
	.4byte _081D0CF8
	.4byte _081D0D02
	.4byte _081D0D16
_081D0CC0:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81D11D8
	movs r0, 0
	b _081D0D26
_081D0CD0:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D0FF0
	movs r0, 0x1
	b _081D0D26
_081D0CE4:
	adds r0, r4, 0
	bl sub_81D12D8
	movs r0, 0x1
	b _081D0D26
_081D0CEE:
	adds r0, r4, 0
	bl sub_81D10D0
	movs r0, 0x1
	b _081D0D26
_081D0CF8:
	adds r0, r4, 0
	bl sub_81D0E84
	movs r0, 0x1
	b _081D0D26
_081D0D02:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D11FC
	movs r0, 0
	b _081D0D26
_081D0D16:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	beq _081D0D24
_081D0D20:
	movs r0, 0x2
	b _081D0D26
_081D0D24:
	movs r0, 0x4
_081D0D26:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C84

	thumb_func_start sub_81D0D2C
sub_81D0D2C: @ 81D0D2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0D5C
	cmp r4, 0x1
	bgt _081D0D46
	cmp r4, 0
	beq _081D0D4C
	b _081D0D84
_081D0D46:
	cmp r4, 0x2
	beq _081D0D76
	b _081D0D84
_081D0D4C:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0D86
_081D0D5C:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0D80
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0xB
	bl sub_81C7BA4
	movs r0, 0
	b _081D0D86
_081D0D76:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0D84
_081D0D80:
	movs r0, 0x2
	b _081D0D86
_081D0D84:
	movs r0, 0x4
_081D0D86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D2C

	thumb_func_start sub_81D0D8C
sub_81D0D8C: @ 81D0D8C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0DC0
	cmp r4, 0x1
	bgt _081D0DA6
	cmp r4, 0
	beq _081D0DB0
	b _081D0DF6
_081D0DA6:
	cmp r4, 0x2
	beq _081D0DD4
	cmp r4, 0x3
	beq _081D0DE8
	b _081D0DF6
_081D0DB0:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0DF8
_081D0DC0:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0DF8
_081D0DD4:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0
	b _081D0DF8
_081D0DE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0DF6
_081D0DF2:
	movs r0, 0x2
	b _081D0DF8
_081D0DF6:
	movs r0, 0x4
_081D0DF8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D8C

	thumb_func_start sub_81D0E00
sub_81D0E00: @ 81D0E00
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl sub_81C763C
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0E30
	cmp r4, 0x1
	bgt _081D0E1A
	cmp r4, 0
	beq _081D0E20
	b _081D0E58
_081D0E1A:
	cmp r4, 0x2
	beq _081D0E4A
	b _081D0E58
_081D0E20:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0E5A
_081D0E30:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0E54
	adds r0, r5, 0
	bl sub_81D0E84
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0E5A
_081D0E4A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0E58
_081D0E54:
	movs r0, 0x2
	b _081D0E5A
_081D0E58:
	movs r0, 0x4
_081D0E5A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0E00

	thumb_func_start sub_81D0E60
sub_81D0E60: @ 81D0E60
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BB8
	bl AddWindow
	strh r0, [r4, 0xA]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D0E84
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0E60

	thumb_func_start sub_81D0E84
sub_81D0E84: @ 81D0E84
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r1, =gUnknown_08624BC0
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldr r4, =gStringVar1
	bl sub_81D07D8
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r4, =gStringVar4
	ldr r1, =gText_RibbonsF700
	adds r0, r4, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldrb r0, [r5, 0xA]
	movs r1, 0x44
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0xA]
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	ldrb r0, [r5, 0xA]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0E84

	thumb_func_start sub_81D0EFC
sub_81D0EFC: @ 81D0EFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r7, r0, 0
	bl sub_81D0954
	adds r5, r0, 0
	ldr r1, =gUnknown_08624BC0
	add r0, sp, 0xC
	movs r2, 0x3
	bl memcpy
	ldrb r0, [r7, 0xA]
	movs r1, 0x44
	bl FillWindowPixelBuffer
	cmp r5, 0x18
	bhi _081D0F60
	lsls r1, r5, 3
	ldr r0, =gRibbonDescriptionPointers
	adds r6, r1, r0
	movs r5, 0x80
	lsls r5, 17
	movs r4, 0x1
_081D0F2E:
	ldrb r0, [r7, 0xA]
	lsrs r3, r5, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	ldm r6!, {r1}
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x80
	lsls r0, 21
	adds r5, r0
	subs r4, 0x1
	cmp r4, 0
	bge _081D0F2E
	b _081D0FAA
	.pool
_081D0F60:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	adds r0, r5
	ldr r1, =0x0000318f
	adds r0, r1
	ldrb r5, [r0]
	cmp r5, 0
	beq _081D0FB2
	subs r5, 0x1
	movs r4, 0
	ldr r0, =gGiftRibbonDescriptionPointers
	mov r8, r0
	movs r6, 0x80
	lsls r6, 17
_081D0F7C:
	ldrb r0, [r7, 0xA]
	lsrs r3, r6, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	lsls r1, r4, 2
	lsls r2, r5, 3
	adds r1, r2
	add r1, r8
	ldr r1, [r1]
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r4, 0x1
	cmp r4, 0x1
	ble _081D0F7C
_081D0FAA:
	ldrb r0, [r7, 0xA]
	movs r1, 0x2
	bl CopyWindowToVram
_081D0FB2:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0EFC

	thumb_func_start sub_81D0FCC
sub_81D0FCC: @ 81D0FCC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BC4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D0FF0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0FCC

	thumb_func_start sub_81D0FF0
sub_81D0FF0: @ 81D0FF0
	push {r4-r7,lr}
	sub sp, 0x10
	ldrh r7, [r0, 0x8]
	ldrb r5, [r0, 0x8]
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gStringVar3
	mov r6, sp
	adds r6, 0xD
	adds r0, r4, 0
	add r1, sp, 0xC
	adds r2, r6, 0
	bl sub_81D06E4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r6]
	cmp r0, 0
	beq _081D1040
	cmp r0, 0xFE
	beq _081D1048
	ldr r1, =gUnknown_08624BE4
	b _081D104A
	.pool
_081D1040:
	ldr r1, =gUnknown_08624BCC
	b _081D104A
	.pool
_081D1048:
	ldr r1, =gUnknown_08624BD8
_081D104A:
	ldr r5, =gStringVar1
	adds r0, r5, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	add r1, sp, 0xC
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	lsls r4, r7, 24
	lsrs r4, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x3C
	bl AddTextPrinterParameterized
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0FF0

	thumb_func_start sub_81D10A4
sub_81D10A4: @ 81D10A4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624BE8
	bl AddWindow
	strh r0, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0xC]
	bl PutWindowTilemap
	adds r0, r4, 0
	bl sub_81D10D0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D10A4

	thumb_func_start sub_81D10D0
sub_81D10D0: @ 81D10D0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r8, r0
	bl sub_81D06C4
	adds r4, r0, 0
	adds r4, 0x1
	bl sub_81D06D4
	adds r6, r0, 0
	ldr r5, =gStringVar1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	mov r1, r8
	ldrb r0, [r1, 0xC]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	mov r1, r8
	ldrb r0, [r1, 0xC]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D10D0

	thumb_func_start sub_81D1148
sub_81D1148: @ 81D1148
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r1, sp, 0x4
	add r2, sp, 0x8
	mov r0, sp
	bl sub_81D0760
	bl ResetAllPicSprites
	movs r0, 0x28
	movs r1, 0x68
	bl sub_81D1184
	strh r0, [r4, 0x10]
	movs r0, 0xF
	movs r1, 0
	bl sub_81C7990
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1148

	thumb_func_start sub_81D1178
sub_81D1178: @ 81D1178
	push {lr}
	ldrh r0, [r0, 0x10]
	bl FreeAndDestroyMonPicSprite
	pop {r0}
	bx r0
	thumb_func_end sub_81D1178

	thumb_func_start sub_81D1184
sub_81D1184: @ 81D1184
	push {lr}
	sub sp, 0x1C
	add r1, sp, 0x14
	add r2, sp, 0x18
	add r0, sp, 0x10
	bl sub_81D0760
	add r0, sp, 0x10
	ldrh r0, [r0]
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x14]
	movs r3, 0x28
	str r3, [sp]
	movs r3, 0x68
	str r3, [sp, 0x4]
	movs r3, 0xF
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl CreateMonPicSprite_HandleDeoxys
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x5]
	add sp, 0x1C
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1184

	thumb_func_start sub_81D11D8
sub_81D11D8: @ 81D11D8
	push {lr}
	ldrh r1, [r0, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0x20
	negs r2, r2
	movs r1, 0x28
	movs r3, 0x6
	bl sub_81D1258
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D11D8

	thumb_func_start sub_81D11FC
sub_81D11FC: @ 81D11FC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	bl FreeAndDestroyMonPicSprite
	movs r5, 0x20
	negs r5, r5
	adds r0, r5, 0
	movs r1, 0x68
	bl sub_81D1184
	strh r0, [r4, 0x10]
	ldrh r1, [r4, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r1, r5, 0
	movs r2, 0x28
	movs r3, 0x6
	bl sub_81D1258
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D11FC

	thumb_func_start sub_81D1234
sub_81D1234: @ 81D1234
	ldr r2, =gSprites
	ldrh r1, [r0, 0x10]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81D1234

	thumb_func_start sub_81D1258
sub_81D1258: @ 81D1258
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r2, 0
	adds r5, r3, 0
	subs r0, r6, r1
	strh r1, [r4, 0x20]
	lsls r1, 4
	strh r1, [r4, 0x2E]
	lsls r0, 4
	adds r1, r5, 0
	bl __udivsi3
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	strh r6, [r4, 0x34]
	ldr r0, =sub_81D1284
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1258

	thumb_func_start sub_81D1284
sub_81D1284: @ 81D1284
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x32]
	movs r3, 0x32
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081D12C8
	subs r0, r1, 0x1
	strh r0, [r2, 0x32]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x2E]
	adds r0, r1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bgt _081D12BA
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081D12D0
_081D12BA:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _081D12D0
_081D12C8:
	ldrh r0, [r2, 0x34]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081D12D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1284

	thumb_func_start sub_81D12D8
sub_81D12D8: @ 81D12D8
	push {r4-r6,lr}
	bl sub_81D1350
	ldr r5, =gUnknown_030012C0
	adds r0, r5, 0
	bl sub_81D0914
	adds r6, r0, 0
	ldr r2, =gUnknown_030012C4
	movs r1, 0
	str r1, [r2]
	ldr r0, [r5]
	cmp r1, r0
	bcs _081D130A
	adds r4, r2, 0
_081D12F6:
	ldr r0, [r4]
	ldm r6!, {r1}
	bl sub_81D1370
	ldr r1, [r4]
	adds r1, 0x1
	str r1, [r4]
	ldr r0, [r5]
	cmp r1, r0
	bcc _081D12F6
_081D130A:
	ldr r4, =gUnknown_030012C0
	adds r0, r4, 0
	bl sub_81D092C
	adds r6, r0, 0
	ldr r2, =gUnknown_030012C4
	movs r1, 0
	str r1, [r2]
	ldr r0, [r4]
	cmp r1, r0
	bcs _081D133A
	adds r4, r2, 0
_081D1322:
	ldr r0, [r4]
	adds r0, 0x1B
	ldm r6!, {r1}
	bl sub_81D1370
	ldr r1, [r4]
	adds r1, 0x1
	str r1, [r4]
	ldr r0, =gUnknown_030012C0
	ldr r0, [r0]
	cmp r1, r0
	bcc _081D1322
_081D133A:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D12D8

	thumb_func_start sub_81D1350
sub_81D1350: @ 81D1350
	push {lr}
	sub sp, 0x8
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81D1350

	thumb_func_start sub_81D1370
sub_81D1370: @ 81D1370
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r6, r1, 0
	movs r1, 0x9
	bl __umodsi3
	adds r5, r0, 0
	lsls r5, 1
	adds r5, 0xB
	adds r0, r4, 0
	movs r1, 0x9
	bl __udivsi3
	adds r4, r0, 0
	lsls r4, 1
	adds r4, 0x4
	add r0, sp, 0x8
	adds r1, r6, 0
	bl sub_81D13BC
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x1
	add r1, sp, 0x8
	adds r2, r5, 0
	adds r3, r4, 0
	bl CopyToBgTilemapBufferRect
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1370

	thumb_func_start sub_81D13BC
sub_81D13BC: @ 81D13BC
	push {r4,r5,lr}
	ldr r2, =gUnknown_08624BF8
	lsls r1, 2
	adds r1, r2
	ldrh r3, [r1, 0x2]
	adds r3, 0x2
	lsls r3, 16
	ldrh r1, [r1]
	lsls r1, 1
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	lsrs r3, 4
	adds r2, r1, 0
	orrs r2, r3
	strh r2, [r0]
	movs r5, 0x80
	lsls r5, 3
	adds r4, r5, 0
	orrs r2, r4
	strh r2, [r0, 0x2]
	adds r1, 0x1
	orrs r1, r3
	strh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D13BC

	thumb_func_start sub_81D13FC
sub_81D13FC: @ 81D13FC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_08624C78
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_08624C80
	bl sub_81C795C
	ldr r0, =gUnknown_08624D04
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x14]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D13FC

	thumb_func_start sub_81D1448
sub_81D1448: @ 81D1448
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	bl sub_81D0944
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x9
	bl __modsi3
	adds r5, r0, 0
	lsls r5, 4
	adds r5, 0x60
	adds r0, r4, 0
	movs r1, 0x9
	bl __divsi3
	lsls r0, 4
	adds r0, 0x28
	ldr r1, [r6, 0x14]
	movs r2, 0
	mov r8, r2
	strh r5, [r1, 0x20]
	ldr r1, [r6, 0x14]
	strh r0, [r1, 0x22]
	bl sub_81D0954
	adds r4, r0, 0
	movs r0, 0x9
	bl GetSpriteTileStartByTag
	ldr r3, [r6, 0x14]
	ldr r1, =gUnknown_08624BF8
	lsls r4, 2
	adds r4, r1
	ldrh r1, [r4]
	lsls r1, 4
	adds r0, r1
	ldr r2, =0x000003ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r2, [r3, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x4]
	ldrh r0, [r4, 0x2]
	adds r0, 0xF
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	ldr r3, [r6, 0x14]
	lsls r0, 4
	ldrb r2, [r3, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	ldr r0, [r6, 0x14]
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r1, [r6, 0x14]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r6, 0x14]
	mov r1, r8
	strh r1, [r0, 0x2E]
	ldr r1, [r6, 0x14]
	ldr r0, =sub_81D1538
	str r0, [r1, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1448

	thumb_func_start sub_81D1500
sub_81D1500: @ 81D1500
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4, 0x14]
	movs r0, 0x1
	strh r0, [r1, 0x2E]
	ldr r0, [r4, 0x14]
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldr r1, [r4, 0x14]
	ldr r0, =sub_81D1538
	str r0, [r1, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1500

	thumb_func_start sub_81D1524
sub_81D1524: @ 81D1524
	ldr r0, [r0, 0x14]
	ldr r1, [r0, 0x1C]
	ldr r0, =SpriteCallbackDummy
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	.pool
	thumb_func_end sub_81D1524

	thumb_func_start sub_81D1538
sub_81D1538: @ 81D1538
	push {lr}
	adds r3, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081D156A
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	movs r0, 0x1
	ldrh r1, [r3, 0x2E]
	ands r1, r0
	lsls r1, 2
	mov r0, r12
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_081D156A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1538

	.section .text.after.match.call

	thumb_func_start sub_81D1C44
sub_81D1C44: @ 81D1C44
	push {r4,lr}
	lsls r0, 24
	ldr r4, =gUnknown_0203CF4C
	lsrs r0, 21
	adds r0, 0x8
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081D1C60
	movs r0, 0
	b _081D1C7A
	.pool
_081D1C60:
	movs r2, 0
	ldr r4, =gUnknown_0203CF48
	movs r3, 0xFF
_081D1C66:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _081D1C66
	movs r0, 0x1
_081D1C7A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C44

	thumb_func_start sub_81D1C84
sub_81D1C84: @ 81D1C84
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203CF48
	adds r5, r4, r6
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081D1CEC
	cmp r4, 0x2
	bne _081D1CD4
	ldr r0, =gUnknown_086253E8
	ldr r1, [r0, 0x14]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gMailboxMailOptions
	movs r1, 0x4
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strb r0, [r6, 0x2]
	b _081D1CE0
	.pool
_081D1CD4:
	lsls r0, r4, 3
	ldr r1, =gUnknown_086253E8
	adds r0, r1
	bl AddWindow
	strb r0, [r5]
_081D1CE0:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	movs r1, 0
	bl SetStandardWindowBorderStyle
_081D1CEC:
	ldr r0, =gUnknown_0203CF48
	adds r0, r4, r0
	ldrb r0, [r0]
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1C84

	thumb_func_start sub_81D1D04
sub_81D1D04: @ 81D1D04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF48
	adds r4, r0
	ldrb r0, [r4]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D04

	thumb_func_start sub_81D1D34
sub_81D1D34: @ 81D1D34
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF48
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D1D34

	thumb_func_start sub_81D1D44
sub_81D1D44: @ 81D1D44
	push {r4,r5,lr}
	sub sp, 0x34
	adds r3, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081D1DAC
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r3, 3
	adds r1, r3
	lsls r1, 2
	ldr r0, [r0]
	adds r1, r0
	ldr r0, =0x00002cca
	adds r1, r0
	add r0, sp, 0x14
	bl StringCopy
	add r0, sp, 0x14
	bl sub_81DB52C
	add r0, sp, 0x14
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _081D1D8C
	add r0, sp, 0x14
	movs r1, 0x1
	bl ConvertInternationalString
_081D1D8C:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_08625400
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	add r0, sp, 0x14
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x8
	adds r3, r5, 0
	bl AddTextPrinterParameterized4
_081D1DAC:
	add sp, 0x34
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1D44

	thumb_func_start sub_81D1DC0
sub_81D1DC0: @ 81D1DC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	movs r3, 0
	ldr r7, =gUnknown_0203CF4C
	ldr r0, =gText_Cancel2
	mov r12, r0
	ldr r4, =gMultiuseListMenuTemplate
	ldr r1, =gUnknown_0203CF48
	mov r8, r1
	ldr r2, =sub_81D1E7C
	mov r9, r2
	ldr r0, =sub_81D1D44
	mov r10, r0
	ldrb r1, [r5, 0x5]
	cmp r3, r1
	bcs _081D1E02
	adds r6, r7, 0
	ldr r2, =gUnknown_08625403
_081D1DEC:
	ldr r1, [r6]
	lsls r0, r3, 3
	adds r0, r1
	str r2, [r0]
	str r3, [r0, 0x4]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	ldrb r0, [r5, 0x5]
	cmp r3, r0
	bcc _081D1DEC
_081D1E02:
	ldr r2, [r7]
	lsls r0, r3, 3
	adds r0, r2
	mov r1, r12
	str r1, [r0]
	movs r1, 0x2
	negs r1, r1
	str r1, [r0, 0x4]
	str r2, [r4]
	ldrb r0, [r5, 0x5]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0xC]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r4, 0x10]
	strb r1, [r4, 0x11]
	movs r0, 0x8
	strb r0, [r4, 0x12]
	strb r1, [r4, 0x13]
	strh r0, [r4, 0xE]
	movs r0, 0x29
	strb r0, [r4, 0x14]
	movs r0, 0x31
	strb r0, [r4, 0x15]
	mov r0, r9
	str r0, [r4, 0x4]
	mov r1, r10
	str r1, [r4, 0x8]
	movs r0, 0x1
	strb r0, [r4, 0x17]
	movs r0, 0
	strb r0, [r4, 0x16]
	ldrh r1, [r5, 0x2]
	ldrh r2, [r5]
	adds r0, r4, 0
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D1DC0

	thumb_func_start sub_81D1E7C
sub_81D1E7C: @ 81D1E7C
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D1E8C
	movs r0, 0x5
	bl PlaySE
_081D1E8C:
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E7C

	thumb_func_start sub_81D1E90
sub_81D1E90: @ 81D1E90
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldrb r0, [r4, 0x5]
	ldrb r1, [r4, 0x4]
	subs r0, r1
	adds r0, 0x1
	str r0, [sp]
	movs r0, 0x6E
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xC8
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParameterized
	strb r0, [r4, 0x9]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D1E90

	thumb_func_start sub_81D1EC0
sub_81D1EC0: @ 81D1EC0
	push {lr}
	ldr r0, =gUnknown_0203CF4C
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1EC0

	thumb_func_start sub_81D1ED4
sub_81D1ED4: @ 81D1ED4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r3, r0, 0
	movs r6, 0
	movs r7, 0
_081D1EE6:
	movs r2, 0
	lsls r5, r6, 2
	adds r0, r6, 0x1
	mov r10, r0
	adds r4, r5, 0
_081D1EF0:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r3, r0
	adds r1, r0, 0
	adds r1, 0x64
	strh r7, [r1]
	adds r0, 0x66
	strh r7, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9
	bls _081D1EF0
	movs r2, 0
	mov r9, r2
	str r5, [sp]
	movs r1, 0x9B
	mov r8, r1
	movs r4, 0x5B
	mov r12, r4
_081D1F1C:
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r6, r0
	adds r1, r3, r1
	mov r4, r9
	strb r4, [r1]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1, r0
	adds r0, r3, r0
	mov r4, r8
	strh r4, [r0, 0x14]
	mov r1, r12
	strh r1, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D1F1C
	adds r1, r3, r5
	movs r2, 0x96
	lsls r2, 1
	adds r0, r1, r2
	strh r7, [r0]
	movs r4, 0x97
	lsls r4, 1
	adds r0, r1, r4
	strh r7, [r0]
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bls _081D1EE6
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r3, r2
	movs r1, 0
	strb r1, [r0]
	ldr r4, =0x00000352
	adds r0, r3, r4
	strh r1, [r0]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1ED4

	thumb_func_start sub_81D1F84
sub_81D1F84: @ 81D1F84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	str r1, [sp]
	mov r9, r2
	movs r7, 0
_081D1F98:
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r5, r1, 8
	mov r2, r9
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	adds r7, 0x1
	mov r10, r7
	mov r12, r4
_081D1FBC:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	add r0, r12
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	movs r7, 0x1
	ands r1, r7
	adds r2, r1
	adds r0, 0x64
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D1FBC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r1, r9
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, 0x64
	strh r1, [r0]
	ldr r7, [sp]
	adds r0, r4, r7
	ldrh r1, [r0, 0x2]
	lsls r5, r1, 8
	ldrh r0, [r2, 0x2]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r12, r0
_081D2012:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	mov r7, r12
	ands r1, r7
	adds r2, r1
	adds r0, 0x66
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D2012
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r2, r9
	adds r1, r4, r2
	ldrh r1, [r1, 0x2]
	adds r0, 0x66
	strh r1, [r0]
	mov r7, r10
	lsls r0, r7, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _081D1F98
	ldr r1, =0x00000352
	add r1, r8
	movs r0, 0
	strh r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1F84

	thumb_func_start sub_81D2074
sub_81D2074: @ 81D2074
	push {r4,lr}
	adds r1, r0, 0
	ldr r0, =0x00000352
	adds r4, r1, r0
	ldrh r0, [r4]
	cmp r0, 0x9
	bls _081D208C
	movs r0, 0
	b _081D20A6
	.pool
_081D208C:
	adds r0, r1, 0
	bl sub_81D2230
	ldrh r1, [r4]
	adds r1, 0x1
	strh r1, [r4]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0xA
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_081D20A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2074

	thumb_func_start sub_81D20AC
sub_81D20AC: @ 81D20AC
	ldr r1, =0x00000355
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D20AC

	thumb_func_start sub_81D20BC
sub_81D20BC: @ 81D20BC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =0x00000355
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D20D4
	cmp r0, 0x1
	beq _081D20E2
	b _081D20FA
	.pool
_081D20D4:
	bl ScanlineEffect_Clear
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	b _081D20FC
_081D20E2:
	mov r0, sp
	ldr r1, =gUnknown_08625404
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_081D20FA:
	movs r0, 0
_081D20FC:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D20BC

	thumb_func_start sub_81D2108
sub_81D2108: @ 81D2108
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	movs r1, 0xD5
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D21BE
	adds r0, r6, 0
	bl sub_81D24A4
	adds r0, r6, 0
	bl sub_81D2634
	movs r7, 0
	ldr r5, =gScanlineEffectRegBuffers
	mov r12, r5
	movs r0, 0xF0
	lsls r0, 3
	add r0, r12
	mov r9, r0
	movs r1, 0xA0
	lsls r1, 1
	adds r1, r6, r1
	str r1, [sp]
	ldr r5, =0x0000ffff
	mov r8, r5
	movs r0, 0xA1
	lsls r0, 1
	adds r0, r6, r0
	str r0, [sp, 0x4]
	movs r1, 0x92
	lsls r1, 2
	adds r1, r6, r1
	str r1, [sp, 0x8]
	ldr r5, =0x0000024a
	adds r5, r6
	mov r10, r5
_081D215E:
	adds r2, r7, 0
	adds r2, 0x37
	lsls r3, r2, 2
	mov r0, r9
	adds r0, r3, r0
	str r0, [sp, 0xC]
	add r3, r12
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	ldr r5, [sp, 0x4]
	adds r1, r5, r4
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r3]
	mov r1, r8
	ands r0, r1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	lsls r2, 1
	adds r2, 0x1
	lsls r2, 1
	mov r0, r9
	adds r3, r2, r0
	add r2, r12
	ldr r1, [sp, 0x8]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	add r4, r10
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ands r0, r5
	strh r0, [r3]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x41
	bls _081D215E
	movs r0, 0xD5
	lsls r0, 2
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_081D21BE:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2108

	thumb_func_start sub_81D21DC
sub_81D21DC: @ 81D21DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D21E8
	movs r1, 0
_081D21E8:
	movs r0, 0x1
	lsls r0, r1
	movs r5, 0x1F
	bics r5, r0
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0x9B
	bl SetGpuReg
	ldr r4, =0x00003879
	movs r0, 0x44
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r4, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D21DC

	thumb_func_start sub_81D2230
sub_81D2230: @ 81D2230
	push {r4-r7,lr}
	mov r12, r0
	movs r4, 0
	movs r7, 0x96
	lsls r7, 1
	add r7, r12
	ldr r6, =0x00000352
	add r6, r12
	mov r5, r12
	adds r5, 0x64
_081D2244:
	lsls r2, r4, 2
	adds r3, r7, r2
	ldrh r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, r5, r2
	ldr r0, [r2]
	str r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _081D2244
	movs r1, 0xD5
	lsls r1, 2
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2230

	thumb_func_start sub_81D2278
sub_81D2278: @ 81D2278
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r6, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x38]
	ldr r7, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0xC]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r3, 0x2]
	cmp r0, r1
	bcs _081D22B2
	adds r2, r0, 0
	mov r10, r2
	ldrh r0, [r3, 0x2]
	ldrh r1, [r5]
	lsls r4, r1, 10
	ldrh r3, [r3]
	str r3, [sp, 0x8]
	b _081D22C6
_081D22B2:
	ldrh r0, [r5, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r1, [r1, 0x2]
	mov r10, r1
	ldr r2, [sp, 0x4]
	ldrh r1, [r2]
	lsls r4, r1, 10
	ldrh r3, [r5]
	str r3, [sp, 0x8]
	mov r2, r10
_081D22C6:
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	beq _081D22DE
	subs r0, r3, r1
	lsls r0, 10
	mov r1, r8
	bl __divsi3
	str r0, [sp, 0xC]
_081D22DE:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r7, 0
	bne _081D2328
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r7, r8
	bcs _081D23B6
	movs r7, 0x1
_081D2308:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r1, [sp, 0xC]
	adds r4, r1
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2308
	b _081D23B6
_081D2328:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	ble _081D23C0
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r5, r8
	bcs _081D237A
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D237A
	mov r1, r12
	str r1, [sp, 0x14]
_081D2352:
	ldr r3, [sp, 0x14]
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r3, 0x1
	ands r0, r3
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D237A
	ldr r1, =0x00026bff
	cmp r4, r1
	ble _081D2352
_081D237A:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	cmp r5, r8
	bcs _081D23B6
	mov r3, r12
	movs r7, 0x1
_081D2398:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2398
_081D23B6:
	subs r0, r6, 0x4
	b _081D248C
	.pool
_081D23C0:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bge _081D2464
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r2, r9
	lsls r2, 1
	mov r12, r2
	ldr r3, [sp, 0x8]
	add r3, r9
	str r3, [sp, 0x10]
	cmp r5, r8
	bcs _081D241E
	adds r3, r2, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r2, 0x1
	ands r0, r2
	adds r1, r0
	add r1, r9
	strh r1, [r3]
	b _081D2414
_081D23F2:
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D241E
	mov r1, r12
	adds r3, r1, r6
	asrs r2, r4, 10
	asrs r0, r4, 9
	movs r1, 0x1
	ands r0, r1
	adds r2, r0
	add r2, r9
	strh r2, [r3]
_081D2414:
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D23F2
	movs r0, 0x9B
	strh r0, [r3]
_081D241E:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	cmp r5, r8
	bcs _081D245A
	mov r3, r12
	movs r6, 0x1
_081D243C:
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r6
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D243C
_081D245A:
	subs r0, r7, 0x4
	b _081D248C
	.pool
_081D2464:
	ldr r1, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r1, r2
	mov r3, r10
	strh r3, [r0]
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	adds r7, r0
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1]
	strh r0, [r7]
	movs r0, 0x9B
	strh r0, [r7, 0x2]
	b _081D2494
_081D248C:
	add r0, r12
	mov r2, sp
	ldrh r2, [r2, 0x10]
	strh r2, [r0]
_081D2494:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2278

	thumb_func_start sub_81D24A4
sub_81D24A4: @ 81D24A4
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x99
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _081D24E0
	adds r7, r0, 0
	movs r0, 0xA0
	lsls r0, 1
	adds r1, r4, r0
	movs r3, 0x96
	lsls r3, 1
	adds r2, r4, r3
	subs r0, 0x10
	adds r3, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2500
_081D24E0:
	ldrh r7, [r1]
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x96
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2500:
	movs r1, 0xA0
	lsls r1, 1
	adds r5, r4, r1
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x9A
	lsls r0, 1
	adds r6, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_81D2278
	movs r2, 0
	movs r1, 0x9B
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0x9D
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D253C
	movs r2, 0x1
_081D253C:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	str r2, [sp]
	movs r1, 0x92
	lsls r1, 2
	adds r0, r4, r1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D2278
	movs r2, 0x38
	cmp r2, r7
	bcs _081D257E
	adds r6, r5, 0
	movs r3, 0
	movs r0, 0xA1
	lsls r0, 1
	adds r5, r4, r0
_081D2566:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r7
	bcc _081D2566
_081D257E:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r1, [r0]
	cmp r2, r1
	bhi _081D25B2
	movs r1, 0xA0
	lsls r1, 1
	adds r3, r4, r1
	movs r5, 0x9B
	adds r1, r0, 0
_081D259C:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r0, r3, r0
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1]
	cmp r2, r0
	bls _081D259C
_081D25B2:
	movs r2, 0x9B
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _081D25C8
	adds r0, r1, 0
_081D25C8:
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bhi _081D25F8
	movs r0, 0xA0
	lsls r0, 1
	adds r6, r4, r0
	movs r3, 0
	movs r1, 0xA1
	lsls r1, 1
	adds r5, r4, r1
_081D25E0:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D25E0
_081D25F8:
	movs r2, 0x38
	movs r3, 0xA0
	lsls r3, 1
	adds r5, r4, r3
	movs r0, 0xA1
	lsls r0, 1
	adds r4, r0
	movs r6, 0x9B
_081D2608:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r1, r0, 2
	adds r3, r5, r1
	ldrh r0, [r3]
	cmp r0, 0
	bne _081D2620
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D2620
	strh r6, [r3]
_081D2620:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D2608
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D24A4

	thumb_func_start sub_81D2634
sub_81D2634: @ 81D2634
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x9F
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r5, [r1]
	cmp r0, r5
	bcs _081D266E
	adds r6, r0, 0
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	subs r3, 0x12
	adds r2, r4, r3
	movs r5, 0x9E
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2690
_081D266E:
	ldrh r6, [r1]
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	movs r3, 0x9E
	lsls r3, 1
	adds r2, r4, r3
	movs r5, 0x96
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2690:
	movs r0, 0x92
	lsls r0, 2
	adds r5, r4, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r2, r4, r1
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D2278
	cmp r6, 0x38
	ble _081D26C8
	movs r0, 0
	adds r1, r5, 0
	adds r2, r6, 0
	subs r2, 0x38
_081D26BC:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _081D26BC
_081D26C8:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r5, [r0]
	cmp r2, r5
	bgt _081D26F6
	movs r3, 0x9B
	adds r1, r0, 0
	lsls r0, r2, 2
	movs r5, 0xB5
	lsls r5, 1
	adds r0, r5
	adds r0, r4
_081D26EA:
	strh r3, [r0]
	adds r0, 0x4
	adds r2, 0x1
	ldrh r5, [r1]
	cmp r2, r5
	ble _081D26EA
_081D26F6:
	movs r1, 0x9D
	lsls r1, 1
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r0, 0x1
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _081D270E
	adds r0, r1, 0
_081D270E:
	adds r2, r0, 0
	cmp r2, 0x79
	bgt _081D272C
	movs r1, 0
	lsls r0, r2, 2
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	adds r0, r4
_081D2720:
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x79
	ble _081D2720
_081D272C:
	movs r3, 0
	movs r5, 0x92
	lsls r5, 2
	adds r1, r4, r5
	movs r2, 0x41
_081D2736:
	ldrh r0, [r1]
	ldrh r4, [r1, 0x2]
	cmp r0, r4
	bcc _081D2742
	strh r3, [r1, 0x2]
	strh r3, [r1]
_081D2742:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _081D2736
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2634

	thumb_func_start sub_81D2754
sub_81D2754: @ 81D2754
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r1, =gUnknown_08625410
	ldrb r0, [r6]
	adds r0, r1
	ldrb r2, [r0]
	adds r6, 0x1
	movs r0, 0x9B
	mov r3, r8
	strh r0, [r3]
	movs r0, 0x5B
	subs r0, r2
	strh r0, [r3, 0x2]
	movs r7, 0x40
	movs r0, 0
	mov r12, r0
	movs r2, 0x1
	mov r9, r2
	ldr r3, =gSineTable
	mov r10, r3
_081D2786:
	adds r0, r7, 0
	adds r0, 0x33
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r12
	lsls r0, r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r3, r0, 24
	mov r12, r3
	cmp r0, 0
	bge _081D27A4
	movs r0, 0x4
	mov r12, r0
_081D27A4:
	mov r1, r12
	lsls r0, r1, 24
	asrs r4, r0, 24
	cmp r4, 0x2
	bne _081D27B4
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_081D27B4:
	ldrb r0, [r6]
	ldr r2, =gUnknown_08625410
	adds r0, r2
	ldrb r2, [r0]
	adds r6, 0x1
	lsls r0, r4, 2
	mov r1, r8
	adds r3, r0, r1
	adds r0, r7, 0
	adds r0, 0x40
	lsls r0, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r2
	asrs r5, r0, 8
	adds r0, r5, 0
	adds r0, 0x9B
	strh r0, [r3]
	lsls r0, r7, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r1, r2, 0
	muls r1, r0
	asrs r1, 8
	movs r0, 0x5B
	subs r0, r1
	strh r0, [r3, 0x2]
	cmp r4, 0x2
	bgt _081D2800
	cmp r2, 0x20
	bne _081D27FA
	cmp r4, 0x2
	beq _081D2800
_081D27FA:
	adds r0, r5, 0
	adds r0, 0x9C
	strh r0, [r3]
_081D2800:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0x4
	bls _081D2786
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2754

	thumb_func_start sub_81D2824
sub_81D2824: @ 81D2824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_08625510
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081D284A:
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081D284A
	cmp r5, 0
	bne _081D287C
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	b _081D288E
	.pool
_081D287C:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
_081D288E:
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	bl nullsub_79
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2824

	thumb_func_start nullsub_79
nullsub_79: @ 81D28C4
	bx lr
	thumb_func_end nullsub_79

	thumb_func_start sub_81D28C8
sub_81D28C8: @ 81D28C8
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gMultiuseListMenuTemplate
	adds r2, r3, 0
	ldr r1, =gUnknown_08625548
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	strh r4, [r3, 0xC]
	str r0, [r3]
	cmp r4, 0x5
	bhi _081D28F0
	strh r4, [r3, 0xE]
	b _081D28F4
	.pool
_081D28F0:
	movs r0, 0x6
	strh r0, [r3, 0xE]
_081D28F4:
	ldrb r0, [r3, 0xE]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D28C8

	thumb_func_start sub_81D28FC
sub_81D28FC: @ 81D28FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_BattleMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	mov r8, r0
	str r0, [sp, 0x4]
	movs r7, 0
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_PPSlash
	movs r1, 0x29
	mov r10, r1
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r5, =gText_PowerSlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r1, 0x19
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_AccuracySlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r9, r0
	bne _081D29C4
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2AB6
	.pool
_081D29C4:
	mov r1, r9
	lsls r0, r1, 4
	ldr r1, =gBattleMoves
	adds r6, r0, r1
	ldrb r1, [r6, 0x2]
	lsls r0, r1, 3
	subs r0, r1
	ldr r1, =gTypeNames
	adds r5, r0, r1
	movs r0, 0x19
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gText_PPSlash
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0x4
	ldrb r1, [r6, 0x4]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x1]
	cmp r0, 0x1
	bhi _081D2A3C
	ldr r5, =gText_ThreeDashes
	b _081D2A4A
	.pool
_081D2A3C:
	ldrb r1, [r6, 0x1]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A4A:
	movs r0, 0x19
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x3]
	cmp r0, 0
	bne _081D2A70
	ldr r5, =gText_ThreeDashes
	b _081D2A7E
	.pool
_081D2A70:
	ldrb r1, [r6, 0x3]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A7E:
	movs r0, 0x29
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldr r1, =gMoveDescriptionPointers
	mov r0, r9
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
_081D2AB6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D28FC

	thumb_func_start sub_81D2ACC
sub_81D2ACC: @ 81D2ACC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	bl ShowHideHearts
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_ContestMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Appeal2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x19
	mov r8, r0
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Jam2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x29
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081D2B6C
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2BB8
	.pool
_081D2B6C:
	lsls r4, 3
	ldr r0, =gContestMoves
	adds r4, r0
	ldr r1, =gContestMoveTypeTextPointers
	ldrb r0, [r4, 0x1]
	lsls r0, 29
	lsrs r0, 27
	adds r0, r1
	ldr r5, [r0]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gContestEffectDescriptionPointers
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_081D2BB8:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2ACC

	thumb_func_start sub_81D2BD0
sub_81D2BD0: @ 81D2BD0
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D2BE2
	movs r0, 0x5
	bl PlaySE
_081D2BE2:
	adds r0, r4, 0
	bl sub_81D28FC
	adds r0, r4, 0
	bl sub_81D2ACC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2BD0

	thumb_func_start sub_81D2BF4
sub_81D2BF4: @ 81D2BF4
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl GetPlayerTextSpeedDelay
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized2
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2BF4

	thumb_func_start sub_81D2C3C
sub_81D2C3C: @ 81D2C3C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x3
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C3C

	thumb_func_start sub_81D2C50
sub_81D2C50: @ 81D2C50
	push {lr}
	ldr r0, =gUnknown_08625540
	movs r1, 0x1
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2C50

	thumb_func_start sub_81D2C68
sub_81D2C68: @ 81D2C68
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0xE
	bne _081D2CA8
	cmp r2, 0x2
	beq _081D2C7E
	cmp r2, 0x7
	bne _081D2C94
_081D2C7E:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	adds r2, r3, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2C94:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2CA8:
	cmp r2, 0x2
	beq _081D2CB0
	cmp r2, 0x7
	bne _081D2CBE
_081D2CB0:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetAndCopyBoxMonDataAt
	b _081D2CCA
_081D2CBE:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetBoxMonDataAt
_081D2CCA:
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C68

	thumb_func_start sub_81D2CD0
sub_81D2CD0: @ 81D2CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081D2D20
	ldr r1, =gText_EggNickname
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081D2E70
	.pool
_081D2D20:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081D2D70
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081D2D92
	.pool
_081D2D70:
	lsls r0, r4, 24
	lsrs r0, 24
	lsls r1, r6, 24
	lsrs r1, 24
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081D2D92:
	cmp r7, 0x1D
	beq _081D2D9A
	cmp r7, 0x20
	bne _081D2DB0
_081D2D9A:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081D2DB0
	movs r6, 0xFF
_081D2DB0:
	adds r3, r5, 0
	b _081D2DBA
	.pool
_081D2DB8:
	adds r3, 0x1
_081D2DBA:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081D2DB8
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081D2DDE
	cmp r6, 0xFE
	beq _081D2E02
	movs r0, 0
	b _081D2E24
_081D2DDE:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081D2E24
_081D2E02:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081D2E24:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r4, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r0, r3, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081D2E70:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2CD0

	thumb_func_start sub_81D2E7C
sub_81D2E7C: @ 81D2E7C
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081D2E94
_081D2E86:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081D2E94:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081D2E86
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081D2EC2
	movs r3, 0
_081D2EAE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081D2EAE
_081D2EC2:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D2E7C

	thumb_func_start sub_81D2ED4
sub_81D2ED4: @ 81D2ED4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D2EFC
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2EFC:
	cmp r2, r0
	beq _081D2F42
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r3, 0
	bl sub_81D2CD0
	movs r0, 0xFC
	strb r0, [r5]
	movs r0, 0x4
	strb r0, [r5, 0x1]
	movs r0, 0x8
	strb r0, [r5, 0x2]
	movs r0, 0
	strb r0, [r5, 0x3]
	movs r0, 0x9
	strb r0, [r5, 0x4]
	cmp r7, 0xE
	bne _081D2F2C
	adds r0, r5, 0x5
	ldr r1, =gText_InParty
	b _081D2F3A
	.pool
_081D2F2C:
	adds r4, r5, 0x5
	lsls r0, r7, 24
	lsrs r0, 24
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
_081D2F3A:
	movs r2, 0x8
	bl sub_81D2E7C
	b _081D2F72
_081D2F42:
	movs r1, 0
	movs r2, 0
_081D2F46:
	adds r0, r6, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081D2F46
	adds r1, r6, r1
	movs r0, 0xFF
	strb r0, [r1]
	movs r1, 0
	movs r2, 0
_081D2F5E:
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081D2F5E
	adds r1, r5, r1
	movs r0, 0xFF
	strb r0, [r1]
_081D2F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2ED4

	thumb_func_start sub_81D2F78
sub_81D2F78: @ 81D2F78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r0, r4, 16
	lsls r5, 24
	cmp r5, 0
	bne _081D2FB0
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2FB0:
	cmp r2, r0
	beq _081D305C
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	mov r2, r8
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x2
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x4
	adds r1, r4
	strb r0, [r1]
	mov r4, r10
	add r4, r9
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081D3044
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081D3046
_081D3044:
	movs r0, 0x9
_081D3046:
	strb r0, [r4]
	mov r0, r9
	adds r1, r5, r0
	mov r2, r8
	adds r0, r2, r1
	lsls r1, 2
	adds r1, 0x14
	add r1, r8
	bl sub_81D2754
	b _081D3086
_081D305C:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	adds r1, r5, r0
	movs r6, 0
	lsls r3, r1, 2
	movs r5, 0x9B
	movs r4, 0x5B
_081D306C:
	adds r0, r2, r1
	add r0, r8
	strb r6, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	strh r5, [r0, 0x14]
	strh r4, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081D306C
_081D3086:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2F78

	thumb_func_start sub_81D3094
sub_81D3094: @ 81D3094
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	mov r9, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D30C4
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D30C4:
	cmp r2, r0
	beq _081D311A
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0x1
	str r1, [sp]
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl LoadSpecialPokePic
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GetFrontSpritePalFromSpeciesAndPersonality
	mov r1, r9
	bl LZ77UnCompWram
_081D311A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3094

	thumb_func_start sub_81D312C
sub_81D312C: @ 81D312C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	adds r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	ble _081D3140
	movs r0, 0
	strh r0, [r1]
_081D3140:
	movs r0, 0
	ldrsh r1, [r1, r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D312C

	thumb_func_start sub_81D3150
sub_81D3150: @ 81D3150
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	subs r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x50
	negs r2, r2
	cmp r0, r2
	bge _081D3168
	strh r2, [r1]
_081D3168:
	movs r0, 0
	ldrsh r1, [r1, r0]
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D3150

	thumb_func_start sub_81D3178
sub_81D3178: @ 81D3178
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D312C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D319A
	cmp r0, 0
	beq _081D319C
_081D319A:
	movs r1, 0x1
_081D319C:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3178

	thumb_func_start sub_81D31A4
sub_81D31A4: @ 81D31A4
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D3150
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D31C6
	cmp r0, 0
	beq _081D31C8
_081D31C6:
	movs r1, 0x1
_081D31C8:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D31A4

	thumb_func_start sub_81D31D0
sub_81D31D0: @ 81D31D0
	push {r4-r7,lr}
	sub sp, 0x20
	ldr r3, =gUnknown_08625A48
	ldr r4, [r3]
	ldr r5, [r3, 0x4]
	str r4, [sp, 0x18]
	str r5, [sp, 0x1C]
	mov r4, sp
	ldr r3, =gUnknown_08625A50
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldr r3, =gUnknown_08625A68
	ldr r4, [r3, 0x4]
	ldr r3, [r3]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	str r5, [r0]
	str r6, [r0, 0x4]
	mov r0, sp
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	str r3, [r2]
	str r4, [r2, 0x4]
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D31D0

	thumb_func_start sub_81D321C
sub_81D321C: @ 81D321C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r5, r0, 0
	mov r12, r1
	mov r8, r2
	mov r1, sp
	ldr r0, =gUnknown_08625A70
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	add r3, sp, 0x20
	adds r1, r3, 0
	ldr r0, =gUnknown_08625A90
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	add r2, sp, 0x38
	adds r1, r2, 0
	ldr r0, =gUnknown_08625AA8
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	movs r4, 0
_081D3258:
	lsls r0, r4, 3
	add r0, sp
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D3258
	mov r1, r12
	adds r0, r2, 0
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	movs r4, 0
_081D327A:
	lsls r0, r4, 3
	adds r0, r3, r0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r5, r8
	adds r5, 0x8
	mov r8, r5
	subs r5, 0x8
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081D327A
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D321C

	thumb_func_start sub_81D32B0
sub_81D32B0: @ 81D32B0
	push {r4,r5,lr}
	ldr r2, =gUnknown_08625AC0
	ldr r4, [r2]
	ldr r5, [r2, 0x4]
	ldr r2, =gUnknown_08625AC8
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r4, [r0]
	str r5, [r0, 0x4]
	str r2, [r1]
	str r3, [r1, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32B0

	thumb_func_start sub_81D32D4
sub_81D32D4: @ 81D32D4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081D32F0
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r0, r1, 0
	bl sub_81D3408
_081D32F0:
	pop {r0}
	bx r0
	thumb_func_end sub_81D32D4

	thumb_func_start sub_81D32F4
sub_81D32F4: @ 81D32F4
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D330C
	movs r0, 0
	strh r0, [r2, 0x30]
	ldr r0, =sub_81D32D4
	str r0, [r2, 0x1C]
_081D330C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32F4

	thumb_func_start sub_81D3314
sub_81D3314: @ 81D3314
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r3, r1, r0
	cmp r3, 0
	beq _081D3360
	ldrh r1, [r3, 0x24]
	ldrh r2, [r3, 0x20]
	adds r1, r2
	ldr r2, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r1, [r3, 0x26]
	ldrh r3, [r3, 0x22]
	adds r1, r3
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	b _081D337E
	.pool
_081D3360:
	ldr r1, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x28
	strh r0, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r1, 0x2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x68
_081D337E:
	strh r0, [r4, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3314

	thumb_func_start sub_81D338C
sub_81D338C: @ 81D338C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	movs r5, 0
_081D339E:
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D33F0
	strh r5, [r0, 0x2E]
	ldr r1, [r4]
	lsls r0, r5, 4
	adds r0, 0x1
	strh r0, [r1, 0x30]
	ldr r0, [r4]
	strh r6, [r0, 0x32]
	ldr r0, [r4]
	strh r5, [r0, 0x34]
	cmp r7, 0
	beq _081D33C4
	cmp r6, 0x9
	beq _081D33D0
_081D33C4:
	ldr r1, [r4]
	ldr r0, =sub_81D3564
	str r0, [r1, 0x1C]
	b _081D33F0
	.pool
_081D33D0:
	ldr r0, [r4]
	bl sub_81D3314
	ldr r0, [r4]
	bl sub_81D35E8
	ldr r2, [r4]
	ldr r0, =sub_81D32F4
	str r0, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r3, 0x5
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
_081D33F0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _081D339E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D338C

	thumb_func_start sub_81D3408
sub_81D3408: @ 81D3408
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	bge _081D3454
	ldr r5, =gSprites
	movs r7, 0x1C
	adds r7, r5
	mov r12, r7
	ldr r6, =sub_81D3564
_081D3428:
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r5
	movs r7, 0x2E
	ldrsh r0, [r2, r7]
	lsls r0, 4
	adds r0, 0x1
	strh r0, [r2, 0x30]
	add r1, r12
	str r6, [r1]
	ldrh r0, [r2, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	blt _081D3428
_081D3454:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3408

	thumb_func_start sub_81D3464
sub_81D3464: @ 81D3464
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0
_081D346C:
	lsls r0, r1, 2
	adds r0, r2
	str r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _081D346C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3464

	thumb_func_start sub_81D3480
sub_81D3480: @ 81D3480
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	movs r0, 0
	mov r9, r0
	lsrs r7, r2, 24
	movs r5, 0
	adds r0, r7, 0x1
	cmp r9, r0
	bge _081D34FE
_081D34A2:
	ldr r0, =gUnknown_08625B14
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	cmp r3, 0x40
	beq _081D34FE
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r4]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r1, r10
	strh r1, [r0, 0x36]
	cmp r5, 0
	beq _081D34F0
	subs r0, r4, 0x4
	ldr r0, [r0]
	strh r3, [r0, 0x38]
	b _081D34F2
	.pool
_081D34F0:
	mov r9, r6
_081D34F2:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r7, 0x1
	cmp r5, r0
	blt _081D34A2
_081D34FE:
	lsls r0, r7, 2
	add r0, r8
	ldr r0, [r0]
	mov r1, r9
	strh r1, [r0, 0x38]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_81D338C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3480

	thumb_func_start sub_81D3520
sub_81D3520: @ 81D3520
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
_081D3526:
	cmp r5, 0x9
	bhi _081D3544
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	beq _081D3544
	bl DestroySprite
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _081D3526
_081D3544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3520

	thumb_func_start sub_81D354C
sub_81D354C: @ 81D354C
	push {lr}
	bl sub_81D3520
	movs r0, 0x68
	bl FreeSpriteTilesByTag
	movs r0, 0x68
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81D354C

	thumb_func_start sub_81D3564
sub_81D3564: @ 81D3564
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081D3592
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _081D35DC
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081D3592:
	adds r0, r4, 0
	bl sub_81D3314
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D35DC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081D35D8
	cmp r1, 0x9
	bne _081D35D0
	adds r0, r4, 0
	bl sub_81D35E8
	ldr r0, =sub_81D32F4
	b _081D35DA
	.pool
_081D35D0:
	ldr r0, =sub_81D32D4
	b _081D35DA
	.pool
_081D35D8:
	ldr r0, =SpriteCallbackDummy
_081D35DA:
	str r0, [r4, 0x1C]
_081D35DC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3564

	thumb_func_start sub_81D35E8
sub_81D35E8: @ 81D35E8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r5, 0
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	bge _081D3636
	movs r0, 0x5
	negs r0, r0
	adds r7, r0, 0
_081D3604:
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	ands r0, r7
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	blt _081D3604
_081D3636:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D35E8

	thumb_func_start sub_81D3640
sub_81D3640: @ 81D3640
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r3, [sp, 0x4C]
	ldr r0, [sp, 0x50]
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r3, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r2, sp, 0xC
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r6, 0x2]
	subs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r6, 0x4]
	subs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r5, 0x8]
	ldrh r1, [r6, 0x8]
	subs r0, r1
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0xA]
	ldrh r1, [r6, 0xA]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldrh r0, [r5, 0x6]
	ldrh r1, [r6, 0x6]
	subs r0, r1
	strh r0, [r2, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	ldr r3, [sp, 0x28]
	strb r3, [r0, 0x1]
	mov r1, r9
	strb r1, [r0, 0x2]
	movs r7, 0
	mov r10, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	add r6, sp, 0x18
_081D36CA:
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	lsls r0, r7, 1
	mov r4, sp
	adds r4, r0
	adds r4, 0xC
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r1, =gText_Dash
	cmp r0, 0
	blt _081D3704
	ldr r1, =gText_UnkCtrlF904
_081D3704:
	adds r0, r6, 0
	bl StringCopy
	mov r0, r10
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0x38
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081D372C
	negs r0, r1
_081D372C:
	movs r4, 0xC
	cmp r0, 0x9
	bgt _081D3734
	movs r4, 0x12
_081D3734:
	cmp r1, 0
	bge _081D373A
	negs r1, r1
_081D373A:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
	adds r2, 0x38
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _081D36CA
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3640

	thumb_func_start sub_81D3784
sub_81D3784: @ 81D3784
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	ldr r2, [sp, 0x4C]
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r2, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r1, sp, 0xC
	ldrh r0, [r5]
	strh r0, [r1]
	ldrh r0, [r5, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r5, 0x4]
	strh r0, [r1, 0x4]
	ldrh r0, [r5, 0x8]
	strh r0, [r1, 0x6]
	ldrh r0, [r5, 0xA]
	strh r0, [r1, 0x8]
	ldrh r0, [r5, 0x6]
	strh r0, [r1, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	strb r6, [r0, 0x1]
	ldr r2, [sp, 0x28]
	strb r2, [r0, 0x2]
	movs r6, 0
	add r1, sp, 0x18
	mov r9, r1
	mov r7, r8
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
_081D37EE:
	lsls r1, r6, 1
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r4, 0x3
	cmp r0, 0x63
	bgt _081D3808
	movs r4, 0x1
	cmp r0, 0x9
	ble _081D3808
	movs r4, 0x2
_081D3808:
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0
	adds r3, r4, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	subs r0, r4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 17
	lsrs r4, 16
	lsls r5, r6, 4
	subs r5, r6
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	mov r2, r10
	str r2, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _081D37EE
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3784

	thumb_func_start sub_81D388C
sub_81D388C: @ 81D388C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r5, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D388C

	thumb_func_start sub_81D38D4
sub_81D38D4: @ 81D38D4
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6d
	adds r0, r1
	ldrb r1, [r0]
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 8
	lsls r0, 8
	subs r0, r2, r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D38D4

	thumb_func_start sub_81D38FC
sub_81D38FC: @ 81D38FC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x9C
	lsls r5, 2
	adds r1, r5, 0
	bl CalcByteArraySum
	adds r4, r5
	ldr r1, [r4]
	cmp r0, r1
	bne _081D3916
	movs r0, 0x1
	b _081D3918
_081D3916:
	movs r0, 0
_081D3918:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D38FC

	thumb_func_start sub_81D3920
sub_81D3920: @ 81D3920
	push {r4-r7,lr}
	adds r7, r0, 0
	ldrb r6, [r7]
	subs r0, r6, 0x1
	cmp r0, 0x7
	bhi _081D3964
	movs r5, 0
	cmp r5, r6
	bcs _081D394C
	adds r4, r7, 0
	adds r4, 0x8
_081D3936:
	adds r0, r4, 0
	bl sub_81D38FC
	cmp r0, 0
	beq _081D3964
	movs r0, 0x9D
	lsls r0, 2
	adds r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D3936
_081D394C:
	adds r0, r7, 0
	adds r0, 0x8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	bl CalcByteArraySum
	ldr r1, [r7, 0x4]
	cmp r0, r1
	bne _081D3964
	movs r0, 0x1
	b _081D3966
_081D3964:
	movs r0, 0
_081D3966:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3920

	thumb_func_start sub_81D396C
sub_81D396C: @ 81D396C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x7
	bhi _081D398E
	adds r0, r4, 0
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	ldr r1, [r4, 0x4]
	cmp r0, r1
	bne _081D398E
	movs r0, 0x1
	b _081D3990
_081D398E:
	movs r0, 0
_081D3990:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D396C

	thumb_func_start sub_81D3998
sub_81D3998: @ 81D3998
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r1
	movs r2, 0x80
	lsls r2, 5
	mov r0, r8
	movs r1, 0
	bl memset
	ldrb r0, [r7]
	mov r1, r8
	strb r0, [r1]
	bl sub_81D38D4
	mov r2, r8
	strb r0, [r2, 0x1]
	ldrb r0, [r7]
	adds r0, 0x1
	asrs r0, 1
	strb r0, [r2, 0x2]
	movs r6, 0
	b _081D3A42
_081D39C8:
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	bne _081D3A14
	lsrs r0, r6, 31
	adds r0, r6, r0
	asrs r0, 1
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 3
	subs r4, r0
	lsls r4, 3
	add r4, r8
	movs r0, 0x9D
	lsls r0, 2
	adds r5, r6, 0
	muls r5, r0
	adds r5, r7, r5
	ldrb r0, [r5, 0x8]
	strb r0, [r4, 0x8]
	movs r1, 0xA7
	lsls r1, 2
	adds r0, r4, r1
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	subs r2, 0x30
	bl memcpy
	adds r4, 0xC
	adds r5, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
	b _081D3A40
_081D3A14:
	lsrs r1, r6, 31
	adds r1, r6, r1
	asrs r1, 1
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	add r0, r8
	movs r1, 0x9D
	lsls r1, 2
	muls r1, r6
	adds r1, r7, r1
	ldrb r2, [r1, 0x8]
	strb r2, [r0, 0x9]
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	adds r1, 0xC
	subs r2, 0xC
	bl memcpy
_081D3A40:
	adds r6, 0x1
_081D3A42:
	ldrb r0, [r7]
	cmp r6, r0
	blt _081D39C8
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	beq _081D3A7E
	lsrs r2, r6, 31
	adds r2, r6, r2
	asrs r2, 1
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	lsls r0, 3
	add r0, r8
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	ldr r3, =gUnknown_08625B6C
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r2
	lsls r1, 3
	adds r1, r3
	movs r2, 0xA4
	lsls r2, 1
	bl memcpy
_081D3A7E:
	mov r0, r8
	adds r0, 0x8
	movs r1, 0xEE
	lsls r1, 4
	bl CalcByteArraySum
	mov r2, r8
	str r0, [r2, 0x4]
	movs r0, 0x1E
	mov r1, r8
	bl sub_8153634
	cmp r0, 0x1
	bne _081D3AA4
	movs r0, 0x1
	b _081D3AA6
	.pool
_081D3AA4:
	movs r0, 0
_081D3AA6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3998

	thumb_func_start sub_81D3AB0
sub_81D3AB0: @ 81D3AB0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3998
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AB0

	thumb_func_start sub_81D3AD8
sub_81D3AD8: @ 81D3AD8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0x1E
	bl TryCopySpecialSaveSection
	cmp r0, 0x1
	bne _081D3B04
	ldr r2, =0x00000ee8
	adds r0, r5, 0
	adds r1, r4, 0
	bl memcpy
	adds r0, r5, 0
	bl sub_81D396C
	cmp r0, 0
	beq _081D3B04
	movs r0, 0x1
	b _081D3B06
	.pool
_081D3B04:
	movs r0, 0
_081D3B06:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3AD8

	thumb_func_start sub_81D3B0C
sub_81D3B0C: @ 81D3B0C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r5, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D3AD8
	adds r4, r0, 0
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B0C

	thumb_func_start sub_81D3B34
sub_81D3B34: @ 81D3B34
	push {r4,r5,lr}
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	adds r4, r0, 0
	bl sub_81D3B0C
	adds r5, r0, 0
	adds r0, r4, 0
	bl Free
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3B34

	thumb_func_start sub_81D3B54
sub_81D3B54: @ 81D3B54
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_81D41A0
	movs r7, 0x2
	ldr r4, =gShouldAdvanceLinkState
_081D3B64:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3B76
	strb r7, [r4]
_081D3B76:
	movs r0, 0x1
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3BA0
	movs r4, 0
	b _081D3BC2
	.pool
_081D3BA0:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3BAC
	movs r4, 0x1
	b _081D3BC2
_081D3BAC:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3BC0
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3B64
_081D3BC0:
	movs r4, 0x2
_081D3BC2:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3B54

	thumb_func_start sub_81D3BE8
sub_81D3BE8: @ 81D3BE8
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	bl sub_81D41A0
	movs r6, 0x2
	ldr r4, =gShouldAdvanceLinkState
_081D3BF6:
	bl sub_81D4170
	ldr r0, =gUnknown_030012E2
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D3C08
	strb r6, [r4]
_081D3C08:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_81D3D70
	adds r1, r0, 0
	ldr r0, =gUnknown_030012E4
	strh r1, [r0]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D3C34
	movs r4, 0
	b _081D3C56
	.pool
_081D3C34:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D3C40
	movs r4, 0x1
	b _081D3C56
_081D3C40:
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081D3C54
	strb r0, [r4]
	bl VBlankIntrWait
	b _081D3BF6
_081D3C54:
	movs r4, 0x2
_081D3C56:
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	bl sub_81D41F4
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3BE8

	thumb_func_start sub_81D3C7C
sub_81D3C7C: @ 81D3C7C
	push {r4,lr}
	ldr r4, =0x04000208
	movs r3, 0
	strh r3, [r4]
	ldr r2, =0x04000200
	ldrh r1, [r2]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r4]
	ldr r0, =0x04000128
	strh r3, [r0]
	subs r0, 0x1A
	strh r3, [r0]
	ldr r1, =0x04000202
	movs r0, 0xC0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3C7C

	thumb_func_start sub_81D3CBC
sub_81D3CBC: @ 81D3CBC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r5, =0x04000208
	movs r4, 0
	strh r4, [r5]
	ldr r3, =0x04000200
	ldrh r1, [r3]
	ldr r0, =0x0000ff3f
	ands r0, r1
	strh r0, [r3]
	movs r6, 0x1
	strh r6, [r5]
	ldr r0, =0x04000134
	strh r4, [r0]
	ldr r2, =0x04000128
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r7, =0x00004003
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	ldrh r0, [r3]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r3]
	strh r6, [r5]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _081D3D0A
	str r0, [sp]
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
_081D3D0A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3CBC

	thumb_func_start sub_81D3D34
sub_81D3D34: @ 81D3D34
	ldr r0, =0x04000134
	movs r3, 0
	strh r3, [r0]
	ldr r2, =0x04000128
	movs r1, 0xA0
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, =gShouldAdvanceLinkState
	strb r3, [r0]
	ldr r0, =gUnknown_030012E6
	strh r3, [r0]
	ldr r1, =gUnknown_030012E8
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D3D34

	thumb_func_start sub_81D3D70
sub_81D3D70: @ 81D3D70
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0, 0x1]
	cmp r0, 0x6
	bls _081D3D86
	b _081D3ECC
_081D3D86:
	lsls r0, 2
	ldr r1, =_081D3D98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D3D98:
	.4byte _081D3DB4
	.4byte _081D3DC8
	.4byte _081D3DE8
	.4byte _081D3DFC
	.4byte _081D3E74
	.4byte _081D3E84
	.4byte _081D3EBC
_081D3DB4:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3DC8:
	adds r0, r2, 0
	bl sub_81D3EE8
	lsls r0, 16
	cmp r0, 0
	beq _081D3DD8
	bl sub_81D413C
_081D3DD8:
	ldr r0, =gShouldAdvanceLinkState
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081D3DE2
	b _081D3ECC
_081D3DE2:
	b _081D3E04
	.pool
_081D3DE8:
	bl sub_81D3D34
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D3F1C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x3
	strb r0, [r1, 0x1]
_081D3DFC:
	ldr r0, =gShouldAdvanceLinkState
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081D3E18
_081D3E04:
	ldr r1, =gUnknown_030012C8
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E18:
	ldr r2, =gUnknown_030012E6
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	ldr r1, =gUnknown_030012E8
	ldr r0, [r1]
	adds r3, r0, 0x1
	str r3, [r1]
	ldr r1, =gUnknown_030012C8
	ldrb r0, [r1]
	cmp r0, 0
	bne _081D3E3C
	cmp r3, 0x3C
	bls _081D3E3C
	movs r0, 0x1
	strb r0, [r1, 0x4]
	movs r0, 0x6
	strb r0, [r1, 0x1]
_081D3E3C:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _081D3ECC
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D3E64
	ldrh r0, [r2]
	cmp r0, 0x2
	bls _081D3E64
	bl sub_81D413C
	movs r0, 0x2
	b _081D3ECA
	.pool
_081D3E64:
	bl sub_81D413C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x2
	strb r0, [r1, 0x2]
	b _081D3ECC
	.pool
_081D3E74:
	bl sub_81D3CBC
	ldr r1, =gUnknown_030012C8
	movs r0, 0x5
	strb r0, [r1, 0x1]
	b _081D3ECC
	.pool
_081D3E84:
	ldr r0, =gUnknown_030012C8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081D3E98
	ldr r0, =gUnknown_030012E6
	ldrh r0, [r0]
	cmp r0, 0x2
	bls _081D3E98
	bl sub_81D413C
_081D3E98:
	ldr r1, =gUnknown_030012E6
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3C
	bls _081D3ECC
	ldr r0, =gUnknown_030012C8
	movs r1, 0x1
	strb r1, [r0, 0x4]
	movs r1, 0x6
	strb r1, [r0, 0x1]
	b _081D3ECC
	.pool
_081D3EBC:
	ldr r4, =gUnknown_030012C8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _081D3ECC
	bl sub_81D3C7C
	movs r0, 0
_081D3ECA:
	strb r0, [r4, 0x2]
_081D3ECC:
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x2]
	ldrb r1, [r2, 0x4]
	lsls r1, 2
	orrs r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 4
	orrs r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3D70

	thumb_func_start sub_81D3EE8
sub_81D3EE8: @ 81D3EE8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =0x04000128
	ldr r0, [r0]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0x8
	bne _081D3F0C
	cmp r2, 0
	beq _081D3F0C
	ldr r1, =gUnknown_030012C8
	movs r0, 0x1
	b _081D3F10
	.pool
_081D3F0C:
	ldr r1, =gUnknown_030012C8
	movs r0, 0
_081D3F10:
	strb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D3EE8

	thumb_func_start sub_81D3F1C
sub_81D3F1C: @ 81D3F1C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r3, =gUnknown_030012C8
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D3F54
	ldr r2, =0x04000128
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	str r5, [r3, 0x8]
	ldr r0, =0x04000120
	str r4, [r0]
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r3, 0x10]
	bl sub_81D3F68
	b _081D3F5C
	.pool
_081D3F54:
	ldr r1, =0x04000128
	ldrh r0, [r1]
	strh r0, [r1]
	str r2, [r3, 0x8]
_081D3F5C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3F1C

	thumb_func_start sub_81D3F68
sub_81D3F68: @ 81D3F68
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x0400010e
	movs r2, 0x40
	strh r2, [r0]
	ldr r3, =0x04000208
	movs r0, 0
	strh r0, [r3]
	adds r1, 0xF4
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	movs r0, 0x1
	strh r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_81D3F68

	thumb_func_start sub_81D3F9C
sub_81D3F9C: @ 81D3F9C
	push {lr}
	bl sub_81D414C
	bl sub_81D413C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3F9C

	thumb_func_start sub_81D3FAC
sub_81D3FAC: @ 81D3FAC
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r2, =gUnknown_030012C8
	ldrb r0, [r2, 0x1]
	adds r3, r2, 0
	cmp r0, 0x3
	beq _081D4034
	cmp r0, 0x3
	bgt _081D3FC8
	cmp r0, 0x1
	beq _081D3FD0
	b _081D412A
	.pool
_081D3FC8:
	cmp r0, 0x5
	bne _081D3FCE
	b _081D40FC
_081D3FCE:
	b _081D412A
_081D3FD0:
	ldr r1, =0x0400012a
	ldr r2, =0x0000ccd0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0
	movs r4, 0
	ldr r6, =0x0000ccd0
	ldr r5, =0x0000ffff
_081D3FEC:
	lsls r0, r1, 1
	add r0, sp
	ldrh r0, [r0]
	cmp r0, r6
	bne _081D4010
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	b _081D401A
	.pool
_081D4010:
	cmp r0, r5
	beq _081D401A
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081D401A:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _081D3FEC
	cmp r2, 0x2
	beq _081D402A
	b _081D412A
_081D402A:
	cmp r4, 0
	beq _081D4030
	b _081D412A
_081D4030:
	strb r2, [r3, 0x1]
	b _081D412A
_081D4034:
	ldr r0, =0x04000120
	ldr r4, [r0]
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _081D404A
	ldrb r0, [r2]
	cmp r0, 0
	bne _081D404A
	lsrs r0, r4, 2
	adds r0, 0x1
	str r0, [r2, 0x10]
_081D404A:
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _081D4080
	ldr r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	cmp r1, r0
	bge _081D4074
	ldr r2, =0x04000120
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r3, 0x14]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r3, 0x14]
	b _081D40BA
	.pool
_081D4074:
	ldr r1, =0x04000120
	ldr r0, [r3, 0x14]
	b _081D40B8
	.pool
_081D4080:
	ldr r1, [r3, 0xC]
	cmp r1, 0
	ble _081D40A0
	ldr r0, [r3, 0x10]
	adds r0, 0x1
	cmp r1, r0
	bge _081D40A0
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	subs r1, 0x4
	str r4, [r1]
	ldr r0, [r3, 0x14]
	adds r0, r4
	str r0, [r3, 0x14]
	b _081D40B4
_081D40A0:
	ldr r0, [r3, 0xC]
	cmp r0, 0
	beq _081D40B4
	ldr r0, [r3, 0x14]
	cmp r0, r4
	bne _081D40B0
	movs r0, 0x1
	b _081D40B2
_081D40B0:
	movs r0, 0x2
_081D40B2:
	strb r0, [r3, 0x3]
_081D40B4:
	ldr r1, =gUnknown_030012E8
	movs r0, 0
_081D40B8:
	str r0, [r1]
_081D40BA:
	ldr r1, [r3, 0xC]
	adds r1, 0x1
	str r1, [r3, 0xC]
	ldr r0, [r3, 0x10]
	adds r0, 0x2
	cmp r1, r0
	bge _081D40EA
	ldrb r0, [r3]
	cmp r0, 0
	beq _081D40E4
	ldr r0, =0x0400010e
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	b _081D412A
	.pool
_081D40E4:
	bl sub_81D413C
	b _081D412A
_081D40EA:
	movs r0, 0
	movs r1, 0x4
	strb r1, [r3, 0x1]
	ldr r1, =gUnknown_030012E6
	strh r0, [r1]
	b _081D412A
	.pool
_081D40FC:
	ldrb r3, [r2]
	cmp r3, 0
	bne _081D4108
	ldr r1, =0x0400012a
	ldrb r0, [r2, 0x3]
	strh r0, [r1]
_081D4108:
	ldr r0, =0x04000120
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r1, [r0, 0x2]
	subs r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D412A
	cmp r3, 0x1
	bne _081D4126
	strb r1, [r2, 0x3]
_081D4126:
	movs r0, 0x6
	strb r0, [r2, 0x1]
_081D412A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3FAC

	thumb_func_start sub_81D413C
sub_81D413C: @ 81D413C
	ldr r0, =0x04000128
	ldrh r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D413C

	thumb_func_start sub_81D414C
sub_81D414C: @ 81D414C
	ldr r2, =0x0400010e
	ldrh r1, [r2]
	ldr r0, =0x0000ff7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0400010c
	ldr r2, =0x0000fda7
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D414C

	thumb_func_start sub_81D4170
sub_81D4170: @ 81D4170
	push {r4,lr}
	ldr r0, =0x04000130
	ldrh r0, [r0]
	ldr r2, =0x000003ff
	adds r1, r2, 0
	eors r1, r0
	ldr r4, =gUnknown_030012E2
	ldr r3, =gUnknown_030012E0
	ldrh r2, [r3]
	adds r0, r1, 0
	bics r0, r2
	strh r0, [r4]
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4170

	thumb_func_start sub_81D41A0
sub_81D41A0: @ 81D41A0
	ldr r1, =gUnknown_030012EC
	ldr r0, =0x04000208
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012EE
	ldr r0, =0x04000200
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F0
	ldr r0, =0x0400010e
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F2
	ldr r0, =0x04000128
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, =gUnknown_030012F4
	ldr r0, =0x04000134
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41A0

	thumb_func_start sub_81D41F4
sub_81D41F4: @ 81D41F4
	ldr r1, =0x04000208
	ldr r0, =gUnknown_030012EC
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0x8
	ldr r0, =gUnknown_030012EE
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, 0xF2
	ldr r0, =gUnknown_030012F0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x1A
	ldr r0, =gUnknown_030012F2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0xC
	ldr r0, =gUnknown_030012F4
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D41F4

	thumb_func_start sub_81D4238
sub_81D4238: @ 81D4238
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r1, =gUnknown_030012C8
	ldr r2, =0x05000006
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4238

	thumb_func_start sub_81D4258
sub_81D4258: @ 81D4258
	push {lr}
	sub sp, 0x4
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x1
	mov r3, sp
	bl TryGetEventObjectIdByLocalIdAndMap
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4258

	thumb_func_start sub_81D427C
sub_81D427C: @ 81D427C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r2, =gEventObjects
	adds r5, r1, r2
	ldr r4, =gUnknown_030012F8
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x14]
	ldrh r1, [r5, 0x10]
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gUnknown_030012FA
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x16]
	ldrh r1, [r5, 0x12]
	subs r0, r1
	strh r0, [r4]
	movs r0, 0
	mov r8, r0
	ldr r2, =gUnknown_030012FC
	movs r1, 0
_081D42CA:
	mov r3, r8
	adds r0, r3, r2
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bls _081D42CA
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	movs r4, 0x14
	ldrsh r1, [r2, r4]
	movs r6, 0x10
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _081D4304
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _081D4356
_081D4304:
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	cmp r1, 0
	bne _081D4338
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	b _081D433E
	.pool
_081D4338:
	ldrb r0, [r5, 0x1]
	movs r1, 0x20
	orrs r0, r1
_081D433E:
	strb r0, [r5, 0x1]
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D4360
_081D4356:
	movs r0, 0
	b _081D4816
	.pool
_081D4360:
	movs r4, 0
	mov r8, r4
	ldr r6, =gEventObjects
	mov r10, r6
_081D4368:
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	mov r2, r8
	lsls r1, r2, 2
	ldr r6, =gUnknown_0862608C
	adds r0, r1, r6
	movs r6, 0x14
	ldrsh r2, [r4, r6]
	movs r6, 0
	ldrsh r0, [r0, r6]
	ldr r6, =gEventObjects
	mov r9, r6
	mov r12, r3
	adds r7, r1, 0
	cmp r2, r0
	beq _081D4394
	b _081D449E
_081D4394:
	movs r3, 0
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D43C0
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D43CA
	b _081D449E
	.pool
_081D43C0:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D43CA
	movs r3, 0x1
_081D43CA:
	cmp r3, 0
	bne _081D449E
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4410
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
_081D4408:
	movs r0, 0x4
	b _081D4816
	.pool
_081D4410:
	cmp r0, 0
	bge _081D4446
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
	b _081D45AA
_081D4446:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	movs r4, 0x14
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _081D449E
	ldr r0, =gUnknown_030012FA
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	ble _081D4488
	adds r0, r1, 0
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D449E
_081D447C:
	movs r0, 0x2
	b _081D4816
	.pool
_081D4488:
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	bne _081D4538
_081D449E:
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r3, r10
	adds r4, r0, r3
	ldr r6, =gUnknown_0862608C
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r3, =gEventObjects
	mov r9, r3
	mov r12, r2
	cmp r1, r0
	beq _081D44C6
	b _081D45D0
_081D44C6:
	movs r3, 0
	adds r0, r7, r6
	movs r6, 0x14
	ldrsh r1, [r4, r6]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D44F0
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D44FA
	b _081D45D0
	.pool
_081D44F0:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D44FA
	movs r3, 0x1
_081D44FA:
	cmp r3, 0
	bne _081D45D0
	ldr r0, =gUnknown_030012FA
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4540
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
_081D4538:
	movs r0, 0x1
	b _081D4816
	.pool
_081D4540:
	cmp r0, 0
	bge _081D4576
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
	b _081D447C
_081D4576:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	movs r3, 0x16
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _081D45D0
	ldr r0, =gUnknown_030012F8
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	ble _081D45B8
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
_081D45AA:
	movs r0, 0x3
	b _081D4816
	.pool
_081D45B8:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
	b _081D4408
_081D45D0:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bhi _081D45E0
	b _081D4368
_081D45E0:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D461C
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4604
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4604:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4614
	b _081D447C
_081D4614:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D461C:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	beq _081D4658
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4640
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4640:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4650
	b _081D4538
_081D4650:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4658:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4694
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D467C
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D467C:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D468C
	b _081D4408
_081D468C:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4694:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	beq _081D46D0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D46B8
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46B8:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D46C8
	b _081D45AA
_081D46C8:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46D0:
	ldr r0, =gUnknown_030012FA
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _081D476E
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r4, 0x12
	ldrsh r1, [r0, r4]
	ldrh r2, [r5, 0x12]
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D470C
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	subs r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D470C
	b _081D447C
_081D470C:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x12]
	movs r3, 0x12
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D473E
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	adds r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D473E
	b _081D4538
_081D473E:
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4756
	b _081D447C
_081D4756:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D476E
	b _081D4538
_081D476E:
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081D480C
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	ldrh r2, [r5, 0x10]
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	cmp r1, r0
	ble _081D47AA
	subs r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47AA
	b _081D45AA
_081D47AA:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D47DC
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r4, 0x12
	ldrsh r1, [r5, r4]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47DC
	b _081D4408
_081D47DC:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47F4
	b _081D4408
_081D47F4:
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D480C
	b _081D45AA
_081D480C:
	movs r0, 0
	bl sub_81D4890
_081D4812:
	lsls r0, 24
	lsrs r0, 24
_081D4816:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D427C

	thumb_func_start sub_81D4834
sub_81D4834: @ 81D4834
	push {r4,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gEventObjects
	ldr r1, =gPlayerAvatar
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r3
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0
	b _081D4888
	.pool
_081D4870:
	lsls r0, r3, 16
	asrs r0, 16
	lsls r1, r4, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	lsrs r0, 24
_081D4888:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4834

	thumb_func_start sub_81D4890
sub_81D4890: @ 81D4890
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r4, r1, r0
	movs r1, 0
	ldr r3, =gUnknown_030012FC
	movs r2, 0
_081D48B0:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D48B0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D48E8
	cmp r6, 0x2
	beq _081D48E8
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D48E8:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4912
	cmp r6, 0x4
	beq _081D4912
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4912:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _081D493A
	cmp r6, 0x1
	beq _081D493A
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D493A:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4964
	cmp r6, 0x3
	beq _081D4964
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4964:
	cmp r5, 0x1
	bhi _081D4974
	ldr r0, =gUnknown_030012FC
	b _081D4988
	.pool
_081D4974:
	ldr r4, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r0, r4
_081D4988:
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4890

	thumb_func_start sub_81D4998
sub_81D4998: @ 81D4998
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D49E0
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000270e
	cmp r2, r0
	bls _081D49D8
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _081D49E0
	.pool
_081D49D8:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_081D49E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D4998

	thumb_func_start EventObjectIsFarawayIslandMew
@ bool8 EventObjectIsFarawayIslandMew(struct npc_state *eventObject)
EventObjectIsFarawayIslandMew: @ 81D49E8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A0C
	ldrb r0, [r2, 0x5]
	cmp r0, 0xE5
	bne _081D4A0C
	movs r0, 0x1
	b _081D4A0E
	.pool
_081D4A0C:
	movs r0, 0
_081D4A0E:
	pop {r1}
	bx r1
	thumb_func_end EventObjectIsFarawayIslandMew

	thumb_func_start IsMewPlayingHideAndSeek
IsMewPlayingHideAndSeek: @ 81D4A14
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A50
	movs r0, 0xE5
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	ldr r0, =0x000002ce
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	movs r0, 0x1
	b _081D4A52
	.pool
_081D4A50:
	movs r0, 0
_081D4A52:
	pop {r1}
	bx r1
	thumb_func_end IsMewPlayingHideAndSeek

	thumb_func_start sub_81D4A58
sub_81D4A58: @ 81D4A58
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081D4A88
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _081D4A88
	movs r0, 0x1
	b _081D4A8A
	.pool
_081D4A88:
	movs r0, 0
_081D4A8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4A58

	thumb_func_start sub_81D4A90
sub_81D4A90: @ 81D4A90
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r0, =gSpecialVar_0x8004
	ldrh r4, [r0]
	cmp r4, 0x1
	bne _081D4AF8
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r3, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	strb r4, [r0]
	b _081D4BC4
	.pool
_081D4AF8:
	ldr r0, =0x0000403a
	ldr r1, =0x0000ffff
	bl VarSet
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r6, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gSpecialVar_Facing
	ldrh r0, [r0]
	cmp r0, 0x2
	beq _081D4B3A
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081D4B3A:
	ldr r4, =gFieldEffectObjectPaletteInfo1
	adds r0, r4, 0
	bl LoadSpritePalette
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	bl UpdateSpritePaletteWithWeather
	ldrh r1, [r5, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x3C]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	ldrb r4, [r5, 0x4]
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r3, r6
	adds r3, 0x43
	ldrb r3, [r3]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAtEnd
	ldr r1, =gUnknown_0203CF50
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081D4BC4
	ldrb r0, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_081D4BC4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4A90

	thumb_func_start sub_81D4BEC
sub_81D4BEC: @ 81D4BEC
	push {lr}
	ldr r1, =gUnknown_0203CF50
	ldrb r0, [r1]
	cmp r0, 0x40
	beq _081D4C06
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_081D4C06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4BEC

	thumb_func_start sub_81D4C14
sub_81D4C14: @ 81D4C14
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4C50
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C50
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C52
	.pool
_081D4C50:
	movs r0, 0
_081D4C52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C14

	thumb_func_start sub_81D4C58
sub_81D4C58: @ 81D4C58
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4C94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C94
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C96
	.pool
_081D4C94:
	movs r0, 0
_081D4C96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C58

	thumb_func_start sub_81D4C9C
sub_81D4C9C: @ 81D4C9C
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4CD8
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4CD8
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	b _081D4CDA
	.pool
_081D4CD8:
	movs r0, 0
_081D4CDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C9C

	thumb_func_start sub_81D4CE0
sub_81D4CE0: @ 81D4CE0
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4D1C
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4D1C
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x3
	strb r1, [r0]
	movs r0, 0x1
	b _081D4D1E
	.pool
_081D4D1C:
	movs r0, 0
_081D4D1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4CE0

	thumb_func_start sub_81D4D24
sub_81D4D24: @ 81D4D24
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	adds r0, r5
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4D24

	thumb_func_start sub_81D4D50
sub_81D4D50: @ 81D4D50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gIntrTable
	ldr r0, =sub_81D3FAC
	str r0, [r1, 0x4]
	ldr r0, =sub_81D3F9C
	str r0, [r1, 0x8]
	bl sub_81D41A0
	bl sub_81D4238
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	strh r0, [r5]
	str r6, [r5, 0x4]
	mov r0, r8
	str r0, [r5, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4D50

	thumb_func_start sub_81D4DB8
sub_81D4DB8: @ 81D4DB8
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	bl sub_81D4238
	bl sub_81D41F4
	bl RestoreSerialTimer3IntrHandlers
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4DB8

	thumb_func_start sub_81D4DE8
sub_81D4DE8: @ 81D4DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	movs r0, 0x1
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	strh r1, [r4]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D4E08
	movs r5, 0x1
_081D4E08:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D4E12
	movs r5, 0x2
_081D4E12:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D4E1C
	movs r5, 0x3
_081D4E1C:
	ldr r1, =gShouldAdvanceLinkState
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4DE8

	thumb_func_start sub_81D4E30
sub_81D4E30: @ 81D4E30
	push {lr}
	ldr r0, =gDecompressionBuffer
	movs r2, 0x80
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r1, =gLinkType
	ldr r2, =0x00005503
	adds r0, r2, 0
	strh r0, [r1]
	bl OpenLink
	movs r0, 0x1
	bl SetSuppressLinkErrorMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4E30

	thumb_func_start sub_81D4E60
sub_81D4E60: @ 81D4E60
	push {lr}
	sub sp, 0xC
	mov r1, sp
	ldr r2, =0x04000208
	ldrh r0, [r2]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r2]
	ldr r0, =gLink+0x4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	add r2, sp, 0x4
	ldrh r1, [r2]
	ldr r0, =0x0000b9a0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ccd0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x4]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081D4EB8
	ldrh r0, [r2, 0x6]
	cmp r0, r1
	bne _081D4EB8
	movs r0, 0x1
	b _081D4EBA
	.pool
_081D4EB8:
	movs r0, 0
_081D4EBA:
	add sp, 0xC
	pop {r1}
	bx r1
	thumb_func_end sub_81D4E60

	thumb_func_start sub_81D4EC0
sub_81D4EC0: @ 81D4EC0
	push {lr}
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4EDC
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4EDC
	movs r0, 0x1
	b _081D4EDE
_081D4EDC:
	movs r0, 0
_081D4EDE:
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EC0

	thumb_func_start sub_81D4EE4
sub_81D4EE4: @ 81D4EE4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081D4F08
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D4F08
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	b _081D500E
_081D4F08:
	ldrb r0, [r4]
	cmp r0, 0x5
	bls _081D4F10
	b _081D500C
_081D4F10:
	lsls r0, 2
	ldr r1, =_081D4F20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D4F20:
	.4byte _081D4F38
	.4byte _081D4F54
	.4byte _081D4F6C
	.4byte _081D4FA0
	.4byte _081D4FEC
	.4byte _081D4FF8
_081D4F38:
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4F88
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D4F88
	movs r0, 0x1
	strb r0, [r4]
	b _081D500C
_081D4F54:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _081D500C
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x2
	strb r0, [r4]
	b _081D500C
_081D4F6C:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4F88
	movs r0, 0x49
	bl PlaySE
	bl sub_800A620
	movs r0, 0
	strh r0, [r5]
	b _081D4FE6
_081D4F88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D500C
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _081D500E
	.pool
_081D4FA0:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081D4FB6
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x5
	b _081D500E
_081D4FB6:
	bl IsLinkConnectionEstablished
	lsls r0, 24
	cmp r0, 0
	beq _081D500C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D4FE6
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, 24
	cmp r0, 0
	beq _081D4FE0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x2
	b _081D500E
	.pool
_081D4FE0:
	movs r0, 0x4
	strb r0, [r4]
	b _081D500C
_081D4FE6:
	movs r0, 0x3
	strb r0, [r4]
	b _081D500C
_081D4FEC:
	movs r0, 0
	bl sub_800ABF4
	movs r0, 0x5
	strb r0, [r4]
	b _081D500C
_081D4FF8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D500C
	strb r0, [r4]
	movs r0, 0x4
	b _081D500E
	.pool
_081D500C:
	movs r0, 0
_081D500E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EE4

	thumb_func_start sub_81D5014
sub_81D5014: @ 81D5014
	push {r4,lr}
	ldr r0, =sub_81D5084
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
	thumb_func_end sub_81D5014

	thumb_func_start sub_81D505C
sub_81D505C: @ 81D505C
	movs r1, 0
	strh r1, [r0]
	bx lr
	thumb_func_end sub_81D505C

	thumb_func_start sub_81D5064
sub_81D5064: @ 81D5064
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, r1
	bhi _081D507A
	movs r0, 0
	b _081D5080
_081D507A:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
_081D5080:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5064

	thumb_func_start sub_81D5084
sub_81D5084: @ 81D5084
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1A
	bls _081D509C
	b _081D548A
_081D509C:
	lsls r0, 2
	ldr r1, =_081D50B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D50B0:
	.4byte _081D511C
	.4byte _081D5138
	.4byte _081D5148
	.4byte _081D515C
	.4byte _081D516C
	.4byte _081D5198
	.4byte _081D51D0
	.4byte _081D524C
	.4byte _081D5268
	.4byte _081D5290
	.4byte _081D52AC
	.4byte _081D52DC
	.4byte _081D52F2
	.4byte _081D5308
	.4byte _081D536A
	.4byte _081D5390
	.4byte _081D53A8
	.4byte _081D53C6
	.4byte _081D53F2
	.4byte _081D5418
	.4byte _081D5448
	.4byte _081D5454
	.4byte _081D5460
	.4byte _081D5430
	.4byte _081D548A
	.4byte _081D548A
	.4byte _081D5478
_081D511C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFD6
	bl mevent_0814257C
	cmp r0, 0
	bne _081D512C
	b _081D548A
_081D512C:
	movs r0, 0x1
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5138:
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _081D548A
_081D5148:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D5156
	b _081D548A
_081D5156:
	movs r0, 0x3
	strb r0, [r4, 0x8]
	b _081D548A
_081D515C:
	bl sub_81D4EC0
	cmp r0, 0
	beq _081D5166
	b _081D52FC
_081D5166:
	bl CloseLink
	b _081D525C
_081D516C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFF5
	bl mevent_0814257C
	cmp r0, 0
	bne _081D517C
	b _081D548A
_081D517C:
	ldr r0, =gUnknown_085EE014
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5198:
	adds r0, r4, 0
	movs r1, 0x5A
	bl sub_81D5064
	cmp r0, 0
	beq _081D51AE
	bl sub_81D4E30
	movs r0, 0x6
	strb r0, [r4, 0x8]
	b _081D548A
_081D51AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D51BC
	b _081D548A
_081D51BC:
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	bl PlaySE
	b _081D535A
	.pool
_081D51D0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D51F4
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	b _081D535A
	.pool
_081D51F4:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D5210
	adds r0, r4, 0
	bl sub_81D505C
	bl CloseLink
	movs r0, 0x7
	strb r0, [r4, 0x8]
	b _081D548A
_081D5210:
	bl sub_81D4E60
	cmp r0, 0
	beq _081D522E
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x8
	strb r0, [r4, 0x8]
	b _081D548A
_081D522E:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D523C
	b _081D548A
_081D523C:
	bl CloseLink
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	b _081D548A
_081D524C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE05C
	bl mevent_0814257C
	cmp r0, 0
	bne _081D525C
	b _081D548A
_081D525C:
	movs r0, 0x4
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5268:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	ldr r0, =gUnknown_03006370
	ldr r1, =gMultiBootProgram_BerryGlitchFix_Start
	ldr r2, =gUnknown_089A3470
	subs r1, r2
	bl sub_81D4D50
	movs r0, 0x9
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5290:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DE8
	strb r0, [r4, 0xE]
	lsls r0, 24
	cmp r0, 0
	bne _081D52A0
	b _081D548A
_081D52A0:
	movs r0, 0xA
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52AC:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DB8
	ldrb r0, [r4, 0xE]
	cmp r0, 0x3
	bne _081D52BA
	b _081D53C0
_081D52BA:
	cmp r0, 0x1
	beq _081D52C0
	b _081D546E
_081D52C0:
	adds r0, r4, 0
	bl sub_81D505C
	ldr r0, =gUnknown_085EE120
	bl sub_8018884
	movs r0, 0xB
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52DC:
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r4, 0
	bl sub_81D5064
	cmp r0, 0
	bne _081D52EC
	b _081D548A
_081D52EC:
	movs r0, 0xC
	strb r0, [r4, 0x8]
	b _081D548A
_081D52F2:
	bl sub_81D4E30
	ldr r0, =gUnknown_085EE0DC
	bl sub_8018884
_081D52FC:
	movs r0, 0xD
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5308:
	adds r0, r4, 0
	adds r0, 0x9
	adds r1, r4, 0
	bl sub_81D4EE4
	cmp r0, 0x5
	bls _081D5318
	b _081D548A
_081D5318:
	lsls r0, 2
	ldr r1, =_081D5328
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D5328:
	.4byte _081D548A
	.4byte _081D5350
	.4byte _081D5340
	.4byte _081D5374
	.4byte _081D5374
	.4byte _081D5360
_081D5340:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	movs r0, 0xE
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5350:
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
_081D535A:
	movs r0, 0x17
	strb r0, [r4, 0x8]
	b _081D548A
_081D5360:
	bl CloseLink
	movs r0, 0x15
	strb r0, [r4, 0x8]
	b _081D548A
_081D536A:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D537A
_081D5374:
	bl CloseLink
	b _081D53C0
_081D537A:
	bl GetBlockReceivedStatus
	lsls r0, 24
	cmp r0, 0
	bne _081D5386
	b _081D548A
_081D5386:
	bl ResetBlockReceivedFlags
	movs r0, 0xF
	strb r0, [r4, 0x8]
	b _081D548A
_081D5390:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3920
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0xE]
	bl sub_800ABF4
	movs r0, 0x10
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53A8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D548A
	ldrb r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081D53C0
	movs r0, 0x11
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53C0:
	movs r0, 0x14
	strb r0, [r4, 0x8]
	b _081D548A
_081D53C6:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3AB0
	cmp r0, 0
	beq _081D53EC
	ldr r0, =gUnknown_085EE0FA
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x12
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53EC:
	movs r0, 0x16
	strb r0, [r4, 0x8]
	b _081D548A
_081D53F2:
	adds r0, r4, 0
	movs r1, 0x78
	bl sub_81D5064
	cmp r0, 0
	beq _081D548A
	ldr r0, =gUnknown_085EE107
	bl sub_8018884
	movs r0, 0xB9
	lsls r0, 1
	bl PlayFanfare
	movs r0, 0x13
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5418:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _081D548A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	b _081D543A
	.pool
_081D5430:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE06B
	bl mevent_0814257C
_081D543A:
	cmp r0, 0
	beq _081D548A
	movs r0, 0x1A
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5448:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0A3
	b _081D5466
	.pool
_081D5454:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0BF
	b _081D5466
	.pool
_081D5460:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE12D
_081D5466:
	bl mevent_0814257C
	cmp r0, 0
	beq _081D548A
_081D546E:
	movs r0, 0
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5478:
	ldr r0, [r4, 0x10]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_081D548A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5084

	thumb_func_start sp194_trainer_tower
sp194_trainer_tower: @ 81D5494
	push {lr}
	bl sub_81D56B0
	ldr r1, =gUnknown_0862A618
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sp194_trainer_tower

	thumb_func_start sub_81D54BC
sub_81D54BC: @ 81D54BC
	push {r4-r6,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	ldr r3, =0x00000ef9
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x00003d68
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	adds r6, r2, 0
	ldr r5, =0x00003718
	movs r4, 0x3
_081D54EE:
	ldr r0, [r6]
	adds r0, r5
	ldr r1, =0x00034bbf
	bl sub_81D5DF4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _081D54EE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D54BC

	thumb_func_start sub_81D5520
sub_81D5520: @ 81D5520
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x12]
	adds r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_81D5520

	thumb_func_start GetTrainerHillOpponentClass
GetTrainerHillOpponentClass: @ 81D5530
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	ldr r2, =gFacilityClassToTrainerClass
	ldr r1, =gUnknown_0203CF58
	ldr r1, [r1]
	adds r1, 0x16
	adds r1, r0
	ldrb r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetTrainerHillOpponentClass

	thumb_func_start GetTrainerHillTrainerName
GetTrainerHillTrainerName: @ 81D5554
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	movs r0, 0xFF
	lsls r0, 24
	adds r1, r0
	lsrs r1, 24
	movs r3, 0
	ldr r0, =gUnknown_0203CF58
	ldr r2, [r0]
	movs r0, 0xB
	muls r0, r1
	adds r2, r0, r2
_081D556E:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, 0x1
	adds r3, 0x1
	cmp r3, 0xA
	ble _081D556E
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetTrainerHillTrainerName

	thumb_func_start GetTrainerHillTrainerFrontSpriteId
GetTrainerHillTrainerFrontSpriteId: @ 81D5588
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF54
	ldr r3, [r0]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	ldrb r2, [r3]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	ldrb r4, [r3, 0x1B]
	bl sub_81D5710
	ldr r0, =gFacilityClassToPicIndex
	adds r4, r0
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainerHillTrainerFrontSpriteId

	thumb_func_start sub_81D55D0
sub_81D55D0: @ 81D55D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D56B0
	ldr r4, =gUnknown_0203CF58
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r4]
	movs r6, 0
	ldr r0, =gUnknown_0203CF54
	mov r10, r0
_081D55EE:
	movs r5, 0
	lsls r1, r6, 2
	mov r8, r1
	adds r0, r6, 0x1
	mov r9, r0
	movs r0, 0xB
	adds r1, r6, 0
	muls r1, r0
	mov r12, r1
	mov r1, r8
	adds r0, r1, r6
	lsls r0, 3
	adds r0, r6
	lsls r7, r0, 3
_081D560A:
	ldr r0, =gUnknown_0203CF58
	ldr r4, [r0]
	mov r1, r12
	adds r0, r5, r1
	adds r4, r0
	mov r0, r10
	ldr r2, [r0]
	adds r3, r5, r7
	ldrb r1, [r2]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x10
	adds r2, r3
	ldrb r0, [r2]
	strb r0, [r4]
	adds r5, 0x1
	cmp r5, 0xA
	ble _081D560A
	ldr r1, =gUnknown_0203CF58
	ldr r4, [r1]
	adds r4, 0x16
	adds r4, r6
	mov r0, r10
	ldr r3, [r0]
	mov r1, r8
	adds r2, r1, r6
	lsls r2, 3
	adds r2, r6
	ldrb r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	adds r0, r2
	lsls r0, 3
	adds r3, r0
	ldrb r0, [r3, 0x1B]
	strb r0, [r4]
	mov r6, r9
	cmp r6, 0x1
	ble _081D55EE
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	ldr r1, =0x00003d64
	adds r0, r1
	bl sub_80008DC
	bl sub_81D5710
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D55D0

	thumb_func_start sub_81D5694
sub_81D5694: @ 81D5694
	push {r4,lr}
	ldr r4, =gUnknown_0203CF58
	ldr r0, [r4]
	cmp r0, 0
	beq _081D56A6
	bl Free
	movs r0, 0
	str r0, [r4]
_081D56A6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5694

	thumb_func_start sub_81D56B0
sub_81D56B0: @ 81D56B0
	push {r4,lr}
	ldr r4, =gUnknown_0203CF54
	ldr r0, [r4]
	cmp r0, 0
	bne _081D56EC
	ldr r0, =0x00000eec
	bl AllocZeroed
	str r0, [r4]
	ldr r1, =gMapHeader
	ldrb r1, [r1, 0x12]
	adds r1, 0x61
	strb r1, [r0]
	ldr r1, =gUnknown_0862A5F8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003d6e
	adds r0, r2
	ldrb r0, [r0]
	lsrs r0, 6
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r4]
	adds r1, 0x4
	ldr r2, =0x040003ba
	bl CpuSet
	bl nullsub_2
_081D56EC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D56B0

	thumb_func_start sub_81D5710
sub_81D5710: @ 81D5710
	push {r4,lr}
	ldr r4, =gUnknown_0203CF54
	ldr r0, [r4]
	cmp r0, 0
	beq _081D5722
	bl Free
	movs r0, 0
	str r0, [r4]
_081D5722:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5710

	thumb_func_start CopyTrainerHillTrainerText
CopyTrainerHillTrainerText: @ 81D572C
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	bl sub_81D5520
	lsls r0, 24
	lsrs r2, r0, 24
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	cmp r5, 0x3
	beq _081D5790
	cmp r5, 0x3
	bgt _081D575A
	cmp r5, 0x2
	beq _081D5764
	b _081D580E
_081D575A:
	cmp r6, 0x4
	beq _081D57BC
	cmp r6, 0x5
	beq _081D57E8
	b _081D580E
_081D5764:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x10
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D5790:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x1C
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D57BC:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x28
	bl FrontierSpeechToString
	b _081D580E
	.pool
_081D57E8:
	ldr r0, =gUnknown_0203CF54
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 3
	subs r1, r2
	lsls r1, 3
	adds r1, 0xC
	ldr r0, [r0]
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	lsls r1, 3
	adds r1, 0x4
	adds r0, r1
	adds r0, 0x34
	bl FrontierSpeechToString
_081D580E:
	bl sub_81D5710
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyTrainerHillTrainerText

	thumb_func_start sub_81D581C
sub_81D581C: @ 81D581C
	push {r4-r6,lr}
	bl nullsub_2
	bl sub_81D3B34
	cmp r0, 0
	bne _081D5844
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x20
	orrs r0, r2
	b _081D5854
	.pool
_081D5844:
	ldr r3, =gSaveBlock1Ptr
	ldr r1, [r3]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
_081D5854:
	strb r0, [r1]
	adds r6, r3, 0
	ldr r0, [r6]
	ldr r1, =0x00003d6c
	adds r0, r1
	movs r5, 0
	strb r5, [r0]
	ldr r0, [r6]
	ldr r4, =0x00003d64
	adds r0, r4
	bl sub_80008DC
	ldr r1, [r6]
	adds r4, r1, r4
	str r5, [r4]
	ldr r3, =0x00003d6e
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xEE
	lsls r1, 4
	adds r0, r1
	strb r5, [r0]
	ldr r0, =gBattleOutcome
	strb r5, [r0]
	ldr r1, [r6]
	adds r1, r3
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D581C

	thumb_func_start sub_81D58D8
sub_81D58D8: @ 81D58D8
	push {lr}
	bl sub_80008E8
	ldr r3, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r3]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D58FA
	movs r0, 0x1
	strh r0, [r3]
_081D58FA:
	ldrb r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x3
	bne _081D590A
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
_081D590A:
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D58D8

	thumb_func_start sub_81D5924
sub_81D5924: @ 81D5924
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_81D6640
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	cmp r0, 0x4
	bne _081D5952
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r0, [r0]
	ldr r7, =0x00003d6e
	adds r0, r7
	ldrb r0, [r0]
	movs r6, 0x1
	adds r4, r6, 0
	ands r4, r0
	cmp r4, 0
	beq _081D596C
_081D5952:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
	strh r0, [r1]
	b _081D59C0
	.pool
_081D596C:
	adds r0, r5, 0
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D59BC
	ldr r1, =gStringVar2
	adds r0, r5, 0
	bl CopyItemName
	mov r0, r8
	ldr r1, [r0]
	adds r1, r7
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, =gSpecialVar_Result
	strh r4, [r0]
	b _081D59C0
	.pool
_081D59BC:
	ldr r0, =gSpecialVar_Result
	strh r6, [r0]
_081D59C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5924

	thumb_func_start sub_81D59D0
sub_81D59D0: @ 81D59D0
	push {r4-r6,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	ldr r6, =0x00003d6e
	adds r0, r2, r6
	ldrb r1, [r0]
	movs r3, 0x2
	adds r0, r3, 0
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _081D59FC
	ldr r0, =gSpecialVar_Result
	strh r3, [r0]
	b _081D5A4E
	.pool
_081D59FC:
	ldr r1, =0x00003d68
	adds r0, r2, r1
	bl free_203F458
	ldr r2, [r4]
	ldr r3, =0x00003d64
	adds r1, r2, r3
	ldr r1, [r1]
	cmp r0, r1
	bls _081D5A48
	adds r3, 0x4
	adds r0, r2, r3
	bl sub_81D5DF4
	ldr r2, [r4]
	adds r0, r2, r6
	ldrb r0, [r0]
	lsrs r0, 6
	lsls r0, 2
	ldr r3, =0x00003718
	adds r1, r2, r3
	adds r1, r0
	ldr r0, =0x00003d68
	adds r2, r0
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	b _081D5A4E
	.pool
_081D5A48:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081D5A4E:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r3, =0x00003d6e
	adds r1, r3
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D59D0

	thumb_func_start sub_81D5A70
sub_81D5A70: @ 81D5A70
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x00003d6e
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081D5AAE
	ldr r0, =0x00003d64
	adds r2, r0
	ldr r1, [r2]
	ldr r0, =0x00034bbe
	cmp r1, r0
	bls _081D5AA8
	adds r0, 0x1
	str r0, [r2]
	b _081D5AAE
	.pool
_081D5AA8:
	adds r0, r2, 0
	bl sub_80008DC
_081D5AAE:
	pop {r0}
	bx r0
	thumb_func_end sub_81D5A70

	thumb_func_start sub_81D5AB4
sub_81D5AB4: @ 81D5AB4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003d6e
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D5AB4

	thumb_func_start sub_81D5AD0
sub_81D5AD0: @ 81D5AD0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D5B00
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D5B20
	.pool
_081D5B00:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D5B1C
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	b _081D5B20
	.pool
_081D5B1C:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
_081D5B20:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5AD0

	thumb_func_start sub_81D5B2C
sub_81D5B2C: @ 81D5B2C
	push {r4-r7,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d64
	adds r0, r1
	ldr r7, [r0]
	ldr r0, =0x00034bbe
	cmp r7, r0
	ble _081D5B40
	ldr r7, =0x00034bbf
_081D5B40:
	movs r4, 0xE1
	lsls r4, 4
	adds r0, r7, 0
	adds r1, r4, 0
	bl __divsi3
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r4, 0
	bl __modsi3
	adds r7, r0, 0
	movs r1, 0x3C
	bl __divsi3
	adds r5, r0, 0
	adds r0, r7, 0
	movs r1, 0x3C
	bl __modsi3
	adds r7, r0, 0
	movs r0, 0xA8
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	adds r4, r0, 0
	ldr r0, =gStringVar1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar3
	adds r1, r4, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5B2C

	thumb_func_start sub_81D5BBC
sub_81D5BBC: @ 81D5BBC
	push {lr}
	bl sub_81D56B0
	ldr r0, =gUnknown_0203CF54
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0x4
	beq _081D5BEC
	ldr r0, =gStringVar1
	ldrb r1, [r1, 0x6]
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D5BF0
	.pool
_081D5BEC:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
_081D5BF0:
	strh r0, [r1]
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5BBC

	thumb_func_start sub_81D5C00
sub_81D5C00: @ 81D5C00
	push {lr}
	bl sub_81D56B0
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	bl sub_81D5710
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5C00

	thumb_func_start sub_81D5C18
sub_81D5C18: @ 81D5C18
	push {lr}
	ldr r0, =0x000040d6
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _081D5C42
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081D5C42
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	cmp r0, 0
	bne _081D5C54
_081D5C42:
	movs r0, 0
	b _081D5C56
	.pool
_081D5C54:
	movs r0, 0x1
_081D5C56:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5C18

	thumb_func_start sub_81D5C5C
sub_81D5C5C: @ 81D5C5C
	push {lr}
	bl sub_81D5C18
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081D5C74
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	b _081D5C7A
	.pool
_081D5C74:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081D5C7A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5C5C

	thumb_func_start nullsub_129
nullsub_129: @ 81D5C84
	bx lr
	thumb_func_end nullsub_129

	thumb_func_start nullsub_2
nullsub_2: @ 81D5C88
	bx lr
	thumb_func_end nullsub_2

	thumb_func_start PrintOnTrainerHillRecordsWindow
PrintOnTrainerHillRecordsWindow: @ 81D5C8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	bl sub_81D56B0
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r5, =gText_TimeBoard
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_0862A5F4
	str r6, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x2
	bl AddTextPrinterParameterized3
	movs r7, 0x12
	movs r0, 0
	mov r8, r0
	mov r10, r4
	ldr r1, =gStringVar4
	mov r9, r1
_081D5CD6:
	lsls r3, r7, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0862A5F4
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_0862A660
	mov r1, r8
	lsls r4, r1, 2
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	adds r7, 0xF
	ldr r0, =gSaveBlock1Ptr
	ldr r1, =0x00003718
	adds r4, r1
	ldr r0, [r0]
	adds r0, r4
	bl free_203F458
	adds r4, r0, 0
	movs r5, 0xE1
	lsls r5, 4
	adds r1, r5, 0
	bl __udivsi3
	adds r6, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	adds r5, r0, 0
	ldr r0, =gStringVar1
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0
	movs r1, 0x3C
	bl __udivsi3
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x3C
	bl __umodsi3
	adds r5, r0, 0
	ldr r0, =gStringVar2
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0xA8
	muls r0, r5
	movs r1, 0x64
	bl __udivsi3
	adds r1, r0, 0
	ldr r0, =gStringVar3
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	mov r0, r9
	ldr r1, =gText_TimeCleared
	bl StringCopy
	ldr r1, =gText_XMinYDotZSec
	bl StringExpandPlaceholders
	movs r0, 0x1
	mov r1, r9
	movs r2, 0xD0
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	lsls r3, r7, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0862A5F4
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	adds r7, 0x11
	movs r1, 0x1
	add r8, r1
	mov r0, r8
	cmp r0, 0x3
	ble _081D5CD6
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	bl sub_81D5710
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrintOnTrainerHillRecordsWindow

	thumb_func_start free_203F458
free_203F458: @ 81D5DF0
	ldr r0, [r0]
	bx lr
	thumb_func_end free_203F458

	thumb_func_start sub_81D5DF4
sub_81D5DF4: @ 81D5DF4
	str r1, [r0]
	bx lr
	thumb_func_end sub_81D5DF4

	thumb_func_start sub_81D5DF8
sub_81D5DF8: @ 81D5DF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0, r1
	str r1, [sp, 0x4]
	bl sub_81D5F48
	cmp r0, 0
	beq _081D5F0E
	bl sub_81D56B0
	movs r7, 0
	ldr r4, =gSaveBlock2Ptr
	ldr r3, =0x00000cb4
	ldr r0, =0x0000ffff
	adds r2, r0, 0
_081D5E26:
	ldr r1, [r4]
	lsls r0, r7, 1
	adds r1, r3
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x1
	bls _081D5E26
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0xC7
	lsls r2, 4
	adds r1, r2
	ldr r2, =0x05000180
	mov r0, sp
	bl CpuSet
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r7, 0
	ldr r3, =gUnknown_0203CF54
	mov r10, r3
_081D5E64:
	lsls r4, r7, 1
	mov r8, r4
	adds r5, r4, r7
	lsls r5, 3
	ldr r0, [sp, 0x4]
	adds r5, r0
	adds r1, r5, 0
	ldr r0, =gUnknown_0862A670
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r6, r7, 0x1
	strb r6, [r5]
	mov r0, r10
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r7
	lsls r0, 3
	mov r2, r9
	lsls r4, r2, 4
	subs r4, r2
	lsls r4, 3
	subs r4, r2
	lsls r4, 3
	adds r0, r4
	adds r1, r0
	ldrb r0, [r1, 0x1B]
	bl sub_81660B8
	strb r0, [r5, 0x1]
	mov r0, r10
	ldr r3, [r0]
	adds r0, r7, r4
	movs r2, 0xF0
	lsls r2, 2
	adds r1, r3, r2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strh r0, [r5, 0x4]
	ldrb r0, [r1]
	lsrs r0, 4
	movs r1, 0xF
	ands r0, r1
	adds r0, 0x5
	strh r0, [r5, 0x6]
	lsls r1, r7, 26
	lsrs r1, 24
	adds r3, r4
	ldr r2, =0x000003c2
	adds r3, r2
	ldrb r0, [r3]
	asrs r0, r1
	movs r3, 0xF
	ands r0, r3
	adds r0, 0x7
	strb r0, [r5, 0x9]
	mov r2, r10
	ldr r0, [r2]
	adds r0, r4
	ldr r3, =0x000003c3
	adds r0, r3
	ldrb r0, [r0]
	asrs r0, r1
	movs r1, 0xF
	ands r0, r1
	strh r0, [r5, 0xE]
	ldr r0, =EventScript_2C83F0
	str r0, [r5, 0x10]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r4, =0x00000cb4
	adds r0, r4
	add r0, r8
	strh r6, [r0]
	lsls r6, 24
	lsrs r7, r6, 24
	cmp r7, 0x1
	bls _081D5E64
	bl sub_81D5710
_081D5F0E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5DF8

	thumb_func_start sub_81D5F48
sub_81D5F48: @ 81D5F48
	push {lr}
	bl sub_81D56B0
	bl sub_81D5710
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81D5F48

	thumb_func_start sub_81D5F58
sub_81D5F58: @ 81D5F58
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0203CF54
	ldr r4, [r4]
	mov r12, r4
	lsls r4, r2, 1
	lsls r5, r0, 4
	subs r5, r0
	lsls r5, 3
	subs r5, r0
	lsls r5, 3
	adds r4, r5
	movs r0, 0xE8
	lsls r0, 2
	add r0, r12
	adds r0, r4
	ldrh r0, [r0]
	movs r4, 0xF
	subs r4, r1
	asrs r0, r4
	movs r4, 0x1
	ands r0, r4
	muls r2, r3
	adds r2, r1
	adds r2, r5
	movs r1, 0xA8
	lsls r1, 2
	add r1, r12
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x80
	lsls r2, 2
	adds r3, r2, 0
	movs r2, 0xC0
	lsls r2, 6
	lsls r0, 10
	orrs r0, r2
	orrs r1, r3
	orrs r0, r1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D5F58

	thumb_func_start sub_81D5FB4
sub_81D5FB4: @ 81D5FB4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0x6
	bne _081D5FD2
	bl InitMapFromSavedGame
	b _081D605E
_081D5FD2:
	bl sub_81D56B0
	mov r0, r9
	cmp r0, 0x5
	bne _081D5FE6
	bl InitMapFromSavedGame
	bl sub_81D5710
	b _081D605E
_081D5FE6:
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r1, =gBackupMapLayout
	str r4, [r1, 0x8]
	movs r0, 0x1F
	str r0, [r1]
	movs r0, 0x23
	str r0, [r1, 0x4]
	movs r0, 0xE0
	lsls r0, 1
	adds r3, r4, r0
	movs r6, 0x4
_081D600A:
	adds r4, r2, 0
	adds r4, 0x20
	adds r1, r3, 0
	movs r5, 0xF
_081D6012:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _081D6012
	adds r3, 0x3E
	adds r2, r4, 0
	subs r6, 0x1
	cmp r6, 0
	bge _081D600A
	movs r6, 0
_081D602C:
	movs r5, 0
	adds r7, r3, 0
	adds r7, 0x3E
	adds r0, r6, 0x1
	mov r8, r0
	adds r4, r3, 0
_081D6038:
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x10
	bl sub_81D5F58
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0xF
	ble _081D6038
	adds r3, r7, 0
	mov r6, r8
	cmp r6, 0xF
	ble _081D602C
	bl mapheader_run_script_with_tag_x1
	bl sub_81D5710
_081D605E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5FB4

	thumb_func_start InTrainerHill
InTrainerHill: @ 81D6074
	push {lr}
	ldr r1, =gMapHeader
	ldr r2, =0xfffffe61
	adds r0, r2, 0
	ldrh r1, [r1, 0x12]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	cmp r0, 0x3
	bhi _081D608C
	movs r1, 0x1
_081D608C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end InTrainerHill

	thumb_func_start GetCurrentTrainerHillMapId
@ u8 GetCurrentTrainerHillMapId()
GetCurrentTrainerHillMapId: @ 81D609C
	push {lr}
	ldr r0, =gMapHeader
	ldrh r2, [r0, 0x12]
	ldr r0, =0x0000019f
	cmp r2, r0
	bne _081D60B4
	movs r1, 0x1
	b _081D60F8
	.pool
_081D60B4:
	movs r0, 0xD0
	lsls r0, 1
	cmp r2, r0
	bne _081D60C0
	movs r1, 0x2
	b _081D60F8
_081D60C0:
	ldr r0, =0x000001a1
	cmp r2, r0
	bne _081D60D0
	movs r1, 0x3
	b _081D60F8
	.pool
_081D60D0:
	movs r0, 0xD1
	lsls r0, 1
	cmp r2, r0
	bne _081D60DC
	movs r1, 0x4
	b _081D60F8
_081D60DC:
	ldr r0, =0x000001a3
	cmp r2, r0
	bne _081D60EC
	movs r1, 0x5
	b _081D60F8
	.pool
_081D60EC:
	movs r0, 0xCF
	lsls r0, 1
	movs r1, 0
	cmp r2, r0
	bne _081D60F8
	movs r1, 0x6
_081D60F8:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end GetCurrentTrainerHillMapId

	thumb_func_start sub_81D6100
sub_81D6100: @ 81D6100
	push {lr}
	ldr r0, =gMapHeader
	ldrh r1, [r0, 0x12]
	ldr r0, =0x000001a3
	movs r2, 0
	cmp r1, r0
	bne _081D6110
	movs r2, 0x1
_081D6110:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6100

	thumb_func_start sub_81D6120
sub_81D6120: @ 81D6120
	push {lr}
	movs r0, 0x1A
	movs r1, 0x40
	bl Overworld_GetMapHeaderByGroupAndId
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_81D6120

	thumb_func_start sub_81D6134
sub_81D6134: @ 81D6134
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D614C
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	b _081D6176
	.pool
_081D614C:
	bl sub_81D6490
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x3
	bls _081D6162
	movs r2, 0x4
_081D6162:
	ldr r1, =gUnknown_0862A688
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x1A
	bl Overworld_GetMapHeaderByGroupAndId
	ldr r0, [r0, 0x4]
	ldr r0, [r0, 0x8]
_081D6176:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6134

	thumb_func_start sub_81D6180
sub_81D6180: @ 81D6180
	lsls r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	lsrs r0, 23
	adds r1, r0
	ldr r0, =0x00000cb2
	adds r1, r0
	ldrh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D6180

	thumb_func_start GetTrainerHillTrainerFlag
@ u8 GetTrainerHillTrainerFlag(u8 eventObjectId)
GetTrainerHillTrainerFlag: @ 81D619C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 23
	ldr r2, =gEventObjects
	lsls r1, r4, 3
	adds r1, r4
	lsls r1, 2
	adds r1, r2
	adds r0, 0xFF
	ldrb r1, [r1, 0x8]
	adds r0, r1
	lsls r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	movs r2, 0xEE
	lsls r2, 4
	adds r1, r2
	ldr r2, =gBitTable
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrb r1, [r1]
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTrainerHillTrainerFlag

	thumb_func_start sub_81D61E8
sub_81D61E8: @ 81D61E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_81D5520
	lsls r0, 25
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gTrainerBattleOpponent_A
	mov r8, r0
	ldr r6, =gSaveBlock2Ptr
	ldr r1, =gBitTable
	mov r12, r1
	adds r5, r6, 0
_081D6204:
	ldr r2, [r5]
	lsls r0, r3, 1
	ldr r7, =0x00000cb4
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	mov r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D6240
	movs r7, 0xEE
	lsls r7, 4
	adds r2, r7
	adds r0, r4, r3
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _081D624A
	.pool
_081D6240:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _081D6204
_081D624A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _081D62A2
	movs r3, 0
	ldr r5, =gTrainerBattleOpponent_B
	ldr r0, =gBitTable
	mov r8, r0
_081D6260:
	ldr r2, [r6]
	lsls r0, r3, 1
	ldr r7, =0x00000cb4
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r5]
	cmp r0, r1
	bne _081D6298
	movs r7, 0xEE
	lsls r7, 4
	adds r2, r7
	adds r0, r4, r3
	lsls r0, 2
	add r0, r8
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _081D62A2
	.pool
_081D6298:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _081D6260
_081D62A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D61E8

	thumb_func_start sub_81D62AC
sub_81D62AC: @ 81D62AC
	ldr r0, =EventScript_2C83F0
	bx lr
	.pool
	thumb_func_end sub_81D62AC

	thumb_func_start sub_81D62B4
sub_81D62B4: @ 81D62B4
	push {lr}
	ldr r0, =gSpecialVar_LastTalked
	ldrh r1, [r0]
	movs r0, 0x5
	bl CopyTrainerHillTrainerText
	bl sub_80982B8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D62B4

	thumb_func_start sub_81D62CC
sub_81D62CC: @ 81D62CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	subs r1, r0, 0x1
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _081D636A
	lsls r0, r1, 24
	lsrs r6, r0, 24
	bl sub_81D56B0
	bl GetHighestLevelInPlayerParty
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl sub_81D5520
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r5, r9
	adds r0, r5, 0x3
	cmp r5, r0
	bge _081D6366
	ldr r1, =gUnknown_0862A698
	lsls r0, r6, 1
	adds r0, r6
	adds r7, r0, r1
_081D6316:
	ldrb r2, [r7]
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	mov r1, r8
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r0, 3
	adds r0, 0xC
	ldr r3, =gUnknown_0203CF54
	ldr r1, [r3]
	adds r1, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r6
	lsls r0, 3
	adds r0, 0x4
	adds r1, r0
	movs r0, 0x2C
	muls r0, r2
	adds r0, 0x40
	adds r1, r0
	adds r0, r4, 0
	bl sub_806819C
	adds r0, r4, 0
	mov r1, r10
	bl sub_81D642C
	adds r5, 0x1
	adds r7, 0x1
	mov r0, r9
	adds r0, 0x3
	cmp r5, r0
	blt _081D6316
_081D6366:
	bl sub_81D5710
_081D636A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D62CC

	thumb_func_start sub_81D6384
sub_81D6384: @ 81D6384
	push {lr}
	bl ZeroEnemyPartyMons
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81D62CC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6384

	thumb_func_start sub_81D639C
sub_81D639C: @ 81D639C
	push {lr}
	bl ZeroEnemyPartyMons
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	movs r1, 0
	bl sub_81D62CC
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	movs r1, 0x3
	bl sub_81D62CC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D639C

	thumb_func_start sub_81D63C4
sub_81D63C4: @ 81D63C4
	movs r0, 0x7
	bx lr
	thumb_func_end sub_81D63C4

	thumb_func_start sub_81D63C8
sub_81D63C8: @ 81D63C8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_81D56B0
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF54
	ldr r3, [r0]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r4
	ldrb r2, [r3]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	ldrb r4, [r3, 0x1B]
	bl sub_81D5710
	movs r2, 0
	ldr r0, =gFacilityClassToTrainerClass
	adds r4, r0
	ldrb r3, [r4]
	ldr r1, =gUnknown_0862A3B4
_081D6406:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081D641C
	ldrb r0, [r1, 0x1]
	b _081D6426
	.pool
_081D641C:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x35
	bls _081D6406
	movs r0, 0
_081D6426:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D63C8

	thumb_func_start sub_81D642C
sub_81D642C: @ 81D642C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	mov r0, sp
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gExperienceTables
	mov r1, sp
	ldrb r2, [r1]
	lsls r2, 2
	ldr r3, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r1, [r1, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r1
	adds r2, r0
	adds r2, r5
	ldr r0, [r2]
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r4, 0
	movs r1, 0x19
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x38
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	bl CalculateMonStats
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D642C

	thumb_func_start sub_81D6490
sub_81D6490: @ 81D6490
	push {r4,lr}
	bl sub_81D56B0
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r4, [r0, 0x6]
	bl sub_81D5710
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6490

	thumb_func_start sub_81D64AC
sub_81D64AC: @ 81D64AC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xEE
	lsls r1, 4
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D64AC

	thumb_func_start sub_81D64C0
sub_81D64C0: @ 81D64C0
	push {lr}
	bl sub_81D6534
	cmp r0, 0x1
	bne _081D64D4
	ldr r0, =gUnknown_0862A5D4
	movs r1, 0x70
	movs r2, 0x20
	bl LoadPalette
_081D64D4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D64C0

	thumb_func_start sub_81D64DC
sub_81D64DC: @ 81D64DC
	ldr r1, =gSpecialVar_Result
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000ef9
	adds r0, r2
	ldrb r0, [r0]
	lsrs r0, 7
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D64DC

	thumb_func_start sub_81D64FC
sub_81D64FC: @ 81D64FC
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D64FC

	thumb_func_start sub_81D6518
sub_81D6518: @ 81D6518
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ef9
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81D6518

	thumb_func_start sub_81D6534
sub_81D6534: @ 81D6534
	push {lr}
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	beq _081D6560
	bl GetCurrentTrainerHillMapId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _081D6560
	bl sub_81D5C00
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D6560
	movs r0, 0x1
	b _081D6562
	.pool
_081D6560:
	movs r0, 0
_081D6562:
	pop {r1}
	bx r1
	thumb_func_end sub_81D6534

	thumb_func_start sub_81D6568
sub_81D6568: @ 81D6568
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003d6e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D6590
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	b _081D6594
	.pool
_081D6590:
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
_081D6594:
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D6568

	thumb_func_start sub_81D65A0
sub_81D65A0: @ 81D65A0
	push {r4,r5,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	ldr r5, =gSpecialVar_0x8005
	ldr r0, =0x00003d6e
	adds r2, r0
	ldrb r1, [r5]
	lsls r1, 6
	ldrb r3, [r2]
	movs r0, 0x3F
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r4]
	ldr r3, =0x00003d68
	adds r2, r1, r3
	ldrh r0, [r5]
	lsls r0, 2
	ldr r3, =0x00003718
	adds r1, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D65A0

	thumb_func_start sub_81D65E8
sub_81D65E8: @ 81D65E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r3, 0
	movs r4, 0
	ldr r0, =gUnknown_0203CF54
	ldr r6, [r0]
	movs r5, 0x1F
_081D65F8:
	lsls r1, r4, 4
	subs r1, r4
	lsls r1, 3
	subs r1, r4
	lsls r1, 3
	adds r1, r6, r1
	ldrb r2, [r1, 0xC]
	adds r0, r5, 0
	ands r0, r2
	eors r3, r0
	ldrb r1, [r1, 0xD]
	adds r0, r5, 0
	ands r0, r1
	eors r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D65F8
	movs r1, 0x5
	cmp r7, 0
	beq _081D662A
	movs r1, 0xA
_081D662A:
	adds r0, r3, 0
	bl __umodsi3
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D65E8

	thumb_func_start sub_81D6640
sub_81D6640: @ 81D6640
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gUnknown_0203CF54
	ldr r4, [r0]
_081D664A:
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 3
	subs r0, r2
	lsls r0, 3
	adds r0, r4, r0
	ldrb r1, [r0, 0xC]
	adds r1, r3, r1
	ldrb r0, [r0, 0xD]
	adds r3, r1, r0
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D664A
	adds r0, r3, 0
	cmp r0, 0
	bge _081D6670
	adds r0, 0xFF
_081D6670:
	asrs r4, r0, 8
	lsrs r0, 31
	adds r0, r4, r0
	asrs r0, 1
	lsls r0, 1
	subs r4, r0
	ldr r0, =0x00000864 @ = FLAG_SYS_GAME_CLEAR
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081D66A0
	ldr r0, =gUnknown_0203CF54
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x8
	bne _081D66A0
	movs r0, 0x1
	b _081D66A2
	.pool
_081D66A0:
	movs r0, 0
_081D66A2:
	bl sub_81D65E8
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r5, [r0]
	ldr r1, =0x00003d6e
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0xC0
	bne _081D66C8
	adds r0, r2, 0x1
	movs r1, 0xA
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
_081D66C8:
	ldr r1, =gUnknown_0862A5CC
	lsls r0, r4, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldr r4, [r0]
	ldr r1, =0x00003d64
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0xE1
	lsls r1, 4
	bl __divsi3
	movs r1, 0
	cmp r0, 0xB
	ble _081D6704
	movs r1, 0x1
	cmp r0, 0xC
	ble _081D6704
	movs r1, 0x2
	cmp r0, 0xD
	ble _081D6704
	movs r1, 0x3
	cmp r0, 0xF
	ble _081D6704
	movs r1, 0x5
	cmp r0, 0x11
	bgt _081D6704
	movs r1, 0x4
_081D6704:
	lsls r0, r1, 1
	adds r0, r4
	ldrh r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D6640

	.align 2, 0 @ Don't pad with nop.
