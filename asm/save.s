	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	
	thumb_func_start sub_815355C
sub_815355C: @ 815355C
	push {r4-r7,lr}
	ldr r5, =gFastSaveSection
	ldr r0, =gUnknown_0203ABBC
	str r0, [r5]
	adds r7, r0, 0
	ldr r0, =gFlashMemoryPresent
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0815358C
	b _081535C8
	.pool
_0815357C:
	ldrb r1, [r7, 0xA]
	ldrb r0, [r7, 0xB]
	adds r1, r0
	ldrb r0, [r7, 0xC]
	adds r1, r0
	ldrb r0, [r7, 0xD]
	adds r0, r1
	b _081535CA
_0815358C:
	bl UpdateSaveAddresses
	ldr r0, =gRamSaveSectionLocations
	bl GetSaveValidStatus
	ldr r0, =gSaveCounter
	ldr r1, [r0]
	ands r1, r4
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 17
	lsrs r6, r0, 16
	movs r4, 0
_081535A6:
	adds r0, r4, r6
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r5]
	bl DoReadFlashWholeSection
	ldr r0, [r5]
	ldr r1, =0x00000ff4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0815357C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xD
	bls _081535A6
_081535C8:
	movs r0, 0
_081535CA:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_815355C

	thumb_func_start sub_81535DC
sub_81535DC: @ 81535DC
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xE2
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08153608
	ldr r4, =gUnknown_0203ABBC
	movs r3, 0x80
	lsls r3, 5
	adds r0, r1, 0
	movs r1, 0
	adds r2, r4, 0
	bl ReadFlash
	ldr r1, [r4]
	ldr r0, =0x0000b39d
	cmp r1, r0
	beq _08153614
_08153608:
	movs r0, 0xFF
	b _0815362A
	.pool
_08153614:
	movs r3, 0
	ldr r5, =0x00000ffb
	adds r2, r4, 0x4
_0815361A:
	adds r0, r6, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r5
	ble _0815361A
	movs r0, 0x1
_0815362A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81535DC

	thumb_func_start sub_8153634
sub_8153634: @ 8153634
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0xE2
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08153680
	ldr r7, =gUnknown_0203ABBC
	ldr r0, =0x0000b39d
	adds r3, r7, 0
	stm r3!, {r0}
	movs r2, 0
	ldr r4, =0x00000ffb
_08153654:
	adds r0, r3, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r4
	ble _08153654
	adds r0, r6, 0
	adds r1, r7, 0
	bl ProgramFlashSectorAndVerify
	cmp r0, 0
	bne _08153680
	movs r0, 0x1
	b _08153682
	.pool
_08153680:
	movs r0, 0xFF
_08153682:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8153634

	thumb_func_start sub_8153688
sub_8153688: @ 8153688
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xB
	bls _081536A2
	b _081537C2
_081536A2:
	lsls r0, 2
	ldr r1, =_081536B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081536B4:
	.4byte _081536E4
	.4byte _081536F4
	.4byte _081536FE
	.4byte _0815371A
	.4byte _0815372C
	.4byte _08153742
	.4byte _08153758
	.4byte _08153762
	.4byte _08153778
	.4byte _0815378C
	.4byte _08153796
	.4byte _081537A8
_081536E4:
	ldr r0, =gSoftResetDisabled
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	strh r0, [r4]
	b _081537C2
	.pool
_081536F4:
	bl sub_800ADF8
	movs r0, 0x2
	strh r0, [r4]
	b _081537C2
_081536FE:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08153714
	bl save_serialize_map
_08153714:
	movs r0, 0x3
	strh r0, [r4]
	b _081537C2
_0815371A:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08153726
	bl sub_8076D5C
_08153726:
	bl sub_8153380
	b _08153752
_0815372C:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0x5
	bne _081537C2
	movs r0, 0
	strh r0, [r4, 0x2]
	strh r1, [r4]
	b _081537C2
_08153742:
	bl sub_81533AC
	lsls r0, 24
	cmp r0, 0
	beq _08153752
	movs r0, 0x6
	strh r0, [r4]
	b _081537C2
_08153752:
	movs r0, 0x4
	strh r0, [r4]
	b _081537C2
_08153758:
	bl sub_81533E0
	movs r0, 0x7
	strh r0, [r4]
	b _081537C2
_08153762:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815376E
	bl sav2_gender2_inplace_and_xFE
_0815376E:
	bl sub_800ADF8
	movs r0, 0x8
	strh r0, [r4]
	b _081537C2
_08153778:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	bl sub_8153408
	movs r0, 0x9
	strh r0, [r4]
	b _081537C2
_0815378C:
	bl sub_800ADF8
	movs r0, 0xA
	strh r0, [r4]
	b _081537C2
_08153796:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081537C2
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081537C2
_081537A8:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _081537C2
	ldr r1, =gSoftResetDisabled
	movs r0, 0
	strb r0, [r1]
	adds r0, r2, 0
	bl DestroyTask
_081537C2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8153688

	.align 2, 0 @ Don't pad with nop.
