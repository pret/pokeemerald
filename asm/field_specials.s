	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_813B21C
sub_813B21C: @ 813B21C
	push {r4,r5,lr}
	ldr r5, =0x000008d7
	adds r0, r5, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _0813B258
	bl StorageGetCurrentBox
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	beq _0813B258
	adds r0, r5, 0
	bl FlagSet
	movs r0, 0x1
	b _0813B25A
	.pool
_0813B258:
	movs r0, 0
_0813B25A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_813B21C

	thumb_func_start sub_813B260
sub_813B260: @ 813B260
	push {r4-r7,lr}
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl set_unknown_box_id
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r4, r0, 24
_0813B278:
	movs r5, 0
	lsls r6, r4, 24
	lsls r7, r4, 16
_0813B27E:
	lsls r1, r5, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	bl GetBoxedMonPtr
	movs r1, 0xB
	movs r2, 0
	bl GetBoxMonData
	cmp r0, 0
	bne _0813B2C0
	bl get_unknown_box_id
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	beq _0813B2A6
	ldr r0, =0x000008d7
	bl FlagClear
_0813B2A6:
	ldr r0, =0x00004036
	lsrs r1, r7, 16
	bl VarSet
	bl sub_813B21C
	lsls r0, 24
	lsrs r0, 24
	b _0813B2DC
	.pool
_0813B2C0:
	adds r5, 0x1
	cmp r5, 0x1D
	ble _0813B27E
	adds r4, 0x1
	cmp r4, 0xE
	bne _0813B2CE
	movs r4, 0
_0813B2CE:
	bl StorageGetCurrentBox
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0813B278
	movs r0, 0
_0813B2DC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B260

	thumb_func_start sub_813B2E4
sub_813B2E4: @ 813B2E4
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004038
	movs r1, 0
	bl VarSet
	movs r0, 0xDF
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B340
	ldr r0, =0x000001bf
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B330
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
	b _0813B36A
	.pool
_0813B330:
	movs r0, 0x1
	ands r4, r0
	cmp r4, 0
	bne _0813B354
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
_0813B340:
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0x1
	bl VarSet
	b _0813B36A
	.pool
_0813B354:
	bl Random
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	movs r1, 0x7
	ands r4, r1
	adds r1, r4, 0
	adds r1, 0x9
	bl VarSet
_0813B36A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B2E4

	thumb_func_start sub_813B374
sub_813B374: @ 813B374
	push {r4,lr}
	ldr r0, =0x00004037
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085B3400
	subs r1, r4, 0x1
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl GetMapName
	cmp r4, 0x8
	bls _0813B3A8
	movs r0, 0x1
	b _0813B3AA
	.pool
_0813B3A8:
	movs r0, 0
_0813B3AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B374

	thumb_func_start sub_813B3B0
sub_813B3B0: @ 813B3B0
	push {r4-r6,lr}
	ldr r5, =0x00004038
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x00004037
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	beq _0813B47C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x000003e7
	cmp r4, r0
	bls _0813B474
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	cmp r0, 0x18
	bne _0813B414
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0x69
	bgt _0813B414
	cmp r0, 0x65
	blt _0813B414
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B414:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r1, 0x4
	ldrsb r1, [r2, r1]
	adds r3, r0, 0
	cmp r1, 0
	bne _0813B444
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, 0x34
	beq _0813B436
	cmp r0, 0x34
	blt _0813B444
	cmp r0, 0x38
	bgt _0813B444
	cmp r0, 0x36
	blt _0813B444
_0813B436:
	ldr r0, =0x00004039
	movs r1, 0x1
	b _0813B478
	.pool
_0813B444:
	ldr r3, [r3]
	movs r2, 0x5
	ldrsb r2, [r3, r2]
	ldr r1, =gUnknown_085B3410
	subs r0, r6, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0813B468
	movs r0, 0x4
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bne _0813B468
	movs r0, 0x1
	b _0813B47E
	.pool
_0813B468:
	ldr r0, =0x00004037
	movs r1, 0
	b _0813B478
	.pool
_0813B474:
	adds r0, r5, 0
	adds r1, r4, 0
_0813B478:
	bl VarSet
_0813B47C:
	movs r0, 0
_0813B47E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_813B3B0

	thumb_func_start sub_813B484
sub_813B484: @ 813B484
	push {lr}
	movs r0, 0x2
	bl sub_80AB104
	pop {r0}
	bx r0
	thumb_func_end sub_813B484

	thumb_func_start sub_813B490
sub_813B490: @ 813B490
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	movs r6, 0x4
	ldrsb r6, [r4, r6]
	ldr r5, =gUnknown_085B3420
	adds r0, r5, 0x2
	mov r12, r0
	adds r7, r5, 0x1
_0813B4A4:
	lsls r0, r3, 1
	adds r2, r0, r3
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r6, r0
	bne _0813B4CC
	movs r1, 0x5
	ldrsb r1, [r4, r1]
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r1, r0
	bne _0813B4CC
	mov r1, r12
	adds r0, r2, r1
	ldrb r0, [r0]
	b _0813B4D8
	.pool
_0813B4CC:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xB
	bls _0813B4A4
	movs r0, 0x1
_0813B4D8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_813B490

	thumb_func_start sub_813B4E0
sub_813B4E0: @ 813B4E0
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl GetRematchIdxByTrainerIdx
	cmp r0, 0
	blt _0813B50C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B50C
	movs r0, 0x1
	b _0813B50E
	.pool
_0813B50C:
	movs r0, 0
_0813B50E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B4E0

	thumb_func_start sub_813B514
sub_813B514: @ 813B514
	push {lr}
	ldr r0, =0x0000403f
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _0813B52C
	movs r0, 0x1
	b _0813B52E
	.pool
_0813B52C:
	movs r0, 0
_0813B52E:
	pop {r1}
	bx r1
	thumb_func_end sub_813B514

	thumb_func_start sub_813B534
sub_813B534: @ 813B534
	push {lr}
	ldr r2, =gUnknown_0203AB70
	ldr r1, =gBattleTypeFlags
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0
	str r0, [r1]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B552
	ldr r0, =sub_80B3AF8
	movs r1, 0x5
	bl CreateTask
_0813B552:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B534

	thumb_func_start sub_813B568
sub_813B568: @ 813B568
	push {lr}
	ldr r0, =sub_813B57C
	movs r1, 0x5
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B568

	thumb_func_start sub_813B57C
sub_813B57C: @ 813B57C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bls _0813B596
	b _0813B7C6
_0813B596:
	lsls r0, 2
	ldr r1, =_0813B5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813B5A8:
	.4byte _0813B5D0
	.4byte _0813B5E4
	.4byte _0813B614
	.4byte _0813B6B4
	.4byte _0813B6E4
	.4byte _0813B728
	.4byte _0813B764
	.4byte _0813B772
	.4byte _0813B784
	.4byte _0813B7A8
_0813B5D0:
	ldr r0, =sub_80B3AF8
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0813B5DE
	b _0813B7C6
_0813B5DE:
	b _0813B790
	.pool
_0813B5E4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B5F2
	b _0813B7C6
_0813B5F2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B5FE
	b _0813B790
_0813B5FE:
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_0x8004
	movs r2, 0x2
	bl SendBlock
	b _0813B708
	.pool
_0813B614:
	bl GetBlockReceivedStatus
	movs r1, 0x2
	ands r1, r0
	cmp r1, 0
	bne _0813B622
	b _0813B7C6
_0813B622:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B62E
	b _0813B790
_0813B62E:
	ldr r5, =gSpecialVar_0x8005
	ldr r0, =gBlockRecvBuffer
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, 0x1
	bl ResetBlockReceivedFlag
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B668
	ldrh r1, [r5]
	cmp r1, 0x1
	bne _0813B668
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	b _0813B790
	.pool
_0813B668:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	adds r2, r0, 0
	cmp r1, 0
	bne _0813B68C
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0813B68C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x2
	b _0813B6AC
	.pool
_0813B68C:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _0813B6A8
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B6A8
	ldr r1, =gSpecialVar_Result
	movs r0, 0x3
	b _0813B6AC
	.pool
_0813B6A8:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
_0813B6AC:
	strh r0, [r1]
	b _0813B790
	.pool
_0813B6B4:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813B6C2
	b _0813B7C6
_0813B6C2:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B790
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_Result
	movs r2, 0x2
	bl SendBlock
	b _0813B708
	.pool
_0813B6E4:
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0813B7C6
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	beq _0813B790
	ldr r1, =gSpecialVar_Result
	ldr r0, =gBlockRecvBuffer
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, 0
	bl ResetBlockReceivedFlag
_0813B708:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0813B7C6
	.pool
_0813B728:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0813B74C
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _0813B790
	ldr r0, =gText_YourPartnerHasRetired
	bl ShowFieldAutoScrollMessage
	b _0813B790
	.pool
_0813B74C:
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0x3
	bne _0813B790
	ldr r0, =gText_YourPartnerHasRetired
	bl ShowFieldAutoScrollMessage
	b _0813B790
	.pool
_0813B764:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0813B7C6
	b _0813B790
_0813B772:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
	bl sub_800ADF8
	b _0813B790
_0813B784:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0813B7C6
_0813B790:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0813B7C6
	.pool
_0813B7A8:
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	bne _0813B7B4
	bl sub_800AC34
_0813B7B4:
	ldr r0, =gBattleTypeFlags
	ldr r1, =gUnknown_0203AB70
	ldr r1, [r1]
	str r1, [r0]
	bl EnableBothScriptContexts
	adds r0, r4, 0
	bl DestroyTask
_0813B7C6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B57C

	thumb_func_start sub_813B7D8
sub_813B7D8: @ 813B7D8
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _0813B7F8
	ldr r2, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	movs r0, 0
	movs r1, 0x1
	bl DoRayquazaScene
	b _0813B802
	.pool
_0813B7F8:
	ldr r2, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	movs r0, 0x1
	movs r1, 0
	bl DoRayquazaScene
_0813B802:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B7D8

	thumb_func_start sub_813B80C
sub_813B80C: @ 813B80C
	push {lr}
	ldr r0, =sub_813B824
	movs r1, 0x8
	bl CreateTask
	movs r0, 0x9D
	bl PlaySE
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B80C

	thumb_func_start sub_813B824
sub_813B824: @ 813B824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r1, r0
	bne _0813B858
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x9D
	bl PlaySE
_0813B858:
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0813B86C
	adds r0, r5, 0
	bl DestroyTask
_0813B86C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B824

	thumb_func_start sub_813B880
sub_813B880: @ 813B880
	push {lr}
	ldr r0, =_fwalk
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0
	movs r0, 0x4
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r2, [r1, 0xE]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B880

	thumb_func_start _fwalk
_fwalk: @ 813B8B0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0813B94E
	movs r6, 0
_0813B8EA:
	movs r4, 0
	lsls r3, r6, 3
	mov r10, r3
	adds r7, r6, 0x1
	mov r8, r7
_0813B8F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, r4
	adds r0, 0x6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r1, r6
	adds r1, 0x4
	ldr r7, =0x00000201
	adds r2, r4, r7
	add r2, r10
	movs r7, 0x6
	ldrsh r3, [r5, r7]
	lsls r3, 5
	adds r2, r3
	lsls r2, 16
	lsrs r2, 16
	bl MapGridSetMetatileIdAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0813B8F4
	mov r1, r8
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0813B8EA
	bl DrawWholeMapView
	ldrh r0, [r5, 0x6]
	adds r0, 0x1
	strh r0, [r5, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0813B94E
	mov r0, r9
	bl DestroyTask
	bl EnableBothScriptContexts
_0813B94E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end _fwalk

	thumb_func_start sub_813B968
sub_813B968: @ 813B968
	push {r4,r5,lr}
	ldr r5, =gSpecialVar_Result
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	strh r0, [r5]
	ldrh r4, [r5]
	adds r0, r4, 0
	movs r1, 0x14
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	subs r4, r1
	strh r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B968

	thumb_func_start sub_813B9A0
sub_813B9A0: @ 813B9A0
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x1C]
	movs r0, 0xB0
	lsls r0, 4
	cmp r1, r0
	bne _0813B9B6
	movs r0, 0x3
	bl Overworld_SetHealLocationWarp
_0813B9B6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813B9A0

	thumb_func_start sub_813B9C0
sub_813B9C0: @ 813B9C0
	push {r4,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gUnknown_085B3444
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0813BA06
	adds r4, r1, 0
	adds r1, r2, 0
_0813B9E6:
	ldrh r0, [r2]
	cmp r0, r3
	bne _0813B9FC
	movs r0, 0x1
	b _0813BA08
	.pool
_0813B9FC:
	adds r1, 0x2
	adds r2, 0x2
	ldrh r0, [r1]
	cmp r0, r4
	bne _0813B9E6
_0813BA06:
	movs r0, 0
_0813BA08:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_813B9C0

	thumb_func_start ResetFanClub
ResetFanClub: @ 813BA10
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r1, r0, r2
	movs r2, 0
	strh r2, [r1]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	strh r2, [r0]
	bx lr
	.pool
	thumb_func_end ResetFanClub

	thumb_func_start sub_813BA30
sub_813BA30: @ 813BA30
	push {lr}
	bl sub_813BF44
	lsls r0, 24
	cmp r0, 0
	beq _0813BA52
	bl sub_813BCE8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
_0813BA52:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA30

	thumb_func_start sub_813BA60
sub_813BA60: @ 813BA60
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0813BAB6
	bl sub_813BF60
	bl sub_813BD84
	ldr r1, [r4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	ldr r0, =0x00000315
	bl FlagClear
	ldr r0, =0x00000316
	bl FlagClear
	ldr r0, =0x00000317
	bl FlagClear
	movs r0, 0xC6
	lsls r0, 2
	bl FlagClear
	ldr r0, =0x000002da
	bl FlagClear
	ldr r0, =0x00004095
	movs r1, 0x1
	bl VarSet
_0813BAB6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BA60

	thumb_func_start sub_813BADC
sub_813BADC: @ 813BADC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BB58
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x0000141e
	adds r3, r0, r5
	ldrh r2, [r3]
	movs r1, 0x7F
	ands r1, r2
	ldr r0, =gUnknown_085B3470
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r1, r0
	cmp r1, 0x13
	ble _0813BB54
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0813BB3C
	bl sub_813BB74
	ldr r0, [r4]
	adds r0, r5
	ldrh r2, [r0]
	ldr r1, =0x0000ff80
	ands r1, r2
	strh r1, [r0]
	b _0813BB58
	.pool
_0813BB3C:
	ldr r2, [r4]
	adds r2, r5
	ldrh r1, [r2]
	ldr r0, =0x0000ff80
	ands r0, r1
	movs r1, 0x14
	orrs r0, r1
	strh r0, [r2]
	b _0813BB58
	.pool
_0813BB54:
	adds r0, r2, r0
	strh r0, [r3]
_0813BB58:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x7F
	ands r0, r1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BADC

	thumb_func_start sub_813BB74
sub_813BB74: @ 813BB74
	push {r4-r7,lr}
	sub sp, 0x8
	movs r3, 0
	movs r5, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r2, =0x0000141e
	movs r6, 0x1
_0813BB82:
	ldr r0, [r7]
	adds r0, r2
	ldrh r1, [r0]
	ldr r0, =gUnknown_085B3474
	adds r0, r5, r0
	ldrb r4, [r0]
	asrs r1, r4
	ands r1, r6
	cmp r1, 0
	bne _0813BBC8
	adds r3, r5, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	bl Random
	adds r1, r6, 0
	ands r1, r0
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r1, 0
	beq _0813BBC8
	ldr r0, [r7]
	adds r0, r2
	adds r1, r6, 0
	lsls r1, r4
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0813BBEA
	.pool
_0813BBC8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BB82
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldr r1, =gUnknown_085B3474
	adds r1, r3, r1
	movs r0, 0x1
	ldrb r1, [r1]
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813BBEA:
	adds r0, r3, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BB74

	thumb_func_start sub_813BC00
sub_813BC00: @ 813BC00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0813BC2E
	movs r0, 0
	b _0813BC8E
_0813BC1E:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	lsls r4, r6
	ldrh r1, [r0]
	eors r4, r1
	strh r4, [r0]
	b _0813BC8C
_0813BC2E:
	movs r5, 0
	ldr r2, =gSaveBlock1Ptr
	mov r8, r2
	ldr r0, =0x0000141e
	mov r9, r0
	movs r4, 0x1
_0813BC3A:
	mov r1, r8
	ldr r0, [r1]
	add r0, r9
	ldrh r1, [r0]
	ldr r7, =gUnknown_085B347C
	adds r0, r5, r7
	ldrb r6, [r0]
	asrs r1, r6
	ands r1, r4
	cmp r1, 0
	beq _0813BC5E
	mov r10, r5
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	bne _0813BC1E
_0813BC5E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _0813BC3A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x0000141e
	adds r4, r0, r2
	ldrh r1, [r4]
	mov r2, r10
	adds r0, r2, r7
	ldrb r2, [r0]
	adds r0, r1, 0
	asrs r0, r2
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0813BC8C
	adds r0, r3, 0
	lsls r0, r2
	eors r1, r0
	strh r1, [r4]
_0813BC8C:
	mov r0, r10
_0813BC8E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BC00

	thumb_func_start sub_813BCA8
sub_813BCA8: @ 813BCA8
	push {r4,r5,lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r4, [r0]
	movs r5, 0x1
_0813BCBA:
	adds r1, r2, 0
	adds r1, 0x8
	adds r0, r4, 0
	asrs r0, r1
	ands r0, r5
	cmp r0, 0
	beq _0813BCCE
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_0813BCCE:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0813BCBA
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BCA8

	thumb_func_start sub_813BCE8
sub_813BCE8: @ 813BCE8
	push {r4-r6,lr}
	movs r5, 0
	ldr r2, =gSaveBlock2Ptr
	ldr r0, [r2]
	ldrh r1, [r0, 0xE]
	ldr r0, =0x000003e6
	cmp r1, r0
	bhi _0813BD58
	adds r6, r2, 0
	b _0813BD32
	.pool
_0813BD04:
	ldr r0, [r6]
	ldrh r1, [r0, 0xE]
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r2, 0xA1
	lsls r2, 5
	adds r0, r2
	ldrh r0, [r0]
	subs r1, r0
	cmp r1, 0xB
	ble _0813BD58
	bl sub_813BC00
	ldr r0, [r4]
	movs r1, 0xA1
	lsls r1, 5
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0xC
	strh r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0813BD32:
	bl sub_813BCA8
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0813BD54
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r6]
	ldrh r0, [r0, 0xE]
	movs r2, 0xA1
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	b _0813BD58
	.pool
_0813BD54:
	cmp r5, 0x8
	bne _0813BD04
_0813BD58:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_813BCE8

	thumb_func_start sub_813BD60
sub_813BD60: @ 813BD60
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BD60

	thumb_func_start sub_813BD84
sub_813BD84: @ 813BD84
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x0000141e
	adds r2, r0
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_813BD84

	thumb_func_start sub_813BDB4
sub_813BDB4: @ 813BDB4
	push {lr}
	movs r3, 0
	movs r2, 0
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	subs r0, 0x8
	cmp r0, 0x7
	bhi _0813BE14
	lsls r0, 2
	ldr r1, =_0813BDD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BDD8:
	.4byte _0813BE14
	.4byte _0813BE14
	.4byte _0813BDF8
	.4byte _0813BDFE
	.4byte _0813BE04
	.4byte _0813BE0A
	.4byte _0813BE10
	.4byte _0813BE14
_0813BDF8:
	movs r3, 0
	movs r2, 0x3
	b _0813BE14
_0813BDFE:
	movs r3, 0
	movs r2, 0x1
	b _0813BE14
_0813BE04:
	movs r3, 0x1
	movs r2, 0
	b _0813BE14
_0813BE0A:
	movs r3, 0
	movs r2, 0x4
	b _0813BE14
_0813BE10:
	movs r3, 0x1
	movs r2, 0x5
_0813BE14:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003150
	adds r0, r1
	adds r1, r3, 0
	bl sub_813BE30
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BDB4

	thumb_func_start sub_813BE30
sub_813BE30: @ 813BE30
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, r5, 4
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0813BEE8
	cmp r2, 0x5
	bhi _0813BED4
	lsls r0, r2, 2
	ldr r1, =_0813BE58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813BE58:
	.4byte _0813BED4
	.4byte _0813BE70
	.4byte _0813BE84
	.4byte _0813BE98
	.4byte _0813BEAC
	.4byte _0813BEC0
_0813BE70:
	ldr r0, =gStringVar1
	ldr r1, =gText_Steven
	bl StringCopy
	b _0813BF04
	.pool
_0813BE84:
	ldr r0, =gStringVar1
	ldr r1, =gText_Brawly
	bl StringCopy
	b _0813BF04
	.pool
_0813BE98:
	ldr r0, =gStringVar1
	ldr r1, =gText_Winona
	bl StringCopy
	b _0813BF04
	.pool
_0813BEAC:
	ldr r0, =gStringVar1
	ldr r1, =gText_Phoebe
	bl StringCopy
	b _0813BF04
	.pool
_0813BEC0:
	ldr r0, =gStringVar1
	ldr r1, =gText_Glacia
	bl StringCopy
	b _0813BF04
	.pool
_0813BED4:
	ldr r0, =gStringVar1
	ldr r1, =gText_Wallace
	bl StringCopy
	b _0813BF04
	.pool
_0813BEE8:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x7
	bl StringCopyN
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	adds r0, r6, 0
	adds r0, 0x50
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	bl ConvertInternationalString
_0813BF04:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813BE30

	thumb_func_start sub_813BF10
sub_813BF10: @ 813BF10
	push {lr}
	ldr r0, =0x00004095
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bne _0813BF40
	bl sub_813BA30
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0813BF3C
	bl sub_813BB74
	b _0813BF40
	.pool
_0813BF3C:
	bl sub_813BC00
_0813BF40:
	pop {r0}
	bx r0
	thumb_func_end sub_813BF10

	thumb_func_start sub_813BF44
sub_813BF44: @ 813BF44
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000141e
	adds r0, r1
	ldrh r0, [r0]
	lsrs r0, 7
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_813BF44

	thumb_func_start sub_813BF60
sub_813BF60: @ 813BF60
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x0000141e
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x80
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_813BF60

	thumb_func_start sub_813BF7C
sub_813BF7C: @ 813BF7C
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl sub_813BADC
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_813BF7C

	.align 2, 0 @ Don't pad with nop.
