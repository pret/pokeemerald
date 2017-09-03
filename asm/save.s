	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


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
