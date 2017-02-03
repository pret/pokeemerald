	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_806957C
sub_806957C: @ 806957C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x54]
	ldr r2, [sp, 0x58]
	ldr r4, [sp, 0x5C]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0xC]
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x14]
	movs r5, 0
	cmp r3, 0
	bne _080695D4
	ldr r2, =gUnknown_020244E0
	ldr r1, =gBattleMoves
	ldr r3, [sp, 0x8]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	strh r0, [r2]
	b _080695D8
	.pool
_080695D4:
	ldr r0, =gUnknown_020244E0
	strh r3, [r0]
_080695D8:
	cmp r7, 0
	bne _080695F8
	ldr r1, =gBattleMoves
	ldr r7, [sp, 0x8]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	mov r10, r0
	b _08069602
	.pool
_080695F8:
	movs r0, 0x3F
	mov r10, r0
	mov r1, r10
	ands r1, r7
	mov r10, r1
_08069602:
	ldrh r7, [r6, 0x2]
	ldr r2, [sp, 0x4]
	ldrh r2, [r2, 0x4]
	str r2, [sp, 0x18]
	ldrh r3, [r6, 0x8]
	mov r8, r3
	ldr r0, [sp, 0x4]
	ldrh r0, [r0, 0xA]
	str r0, [sp, 0x1C]
	ldrh r0, [r6, 0x2E]
	cmp r0, 0xAF
	bne _08069634
	ldr r1, =gUnknown_02024404
	ldr r2, [sp, 0x10]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r3, [r0, 0x7]
	mov r9, r3
	ldrb r0, [r0, 0x1A]
	b _0806964A
	.pool
_08069634:
	ldrh r0, [r6, 0x2E]
	bl itemid_get_x12
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrh r0, [r6, 0x2E]
	bl itemid_get_quality
	lsls r0, 24
	lsrs r0, 24
_0806964A:
	str r0, [sp, 0x24]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0806967E
	ldr r1, =gUnknown_02024404
	ldr r2, [sp, 0x14]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x7]
	str r0, [sp, 0x20]
	b _08069694
	.pool
_0806966C:
	ldr r0, [sp, 0x24]
	adds r0, 0x64
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
	b _0806977C
_0806967E:
	ldr r3, [sp, 0x4]
	ldrh r0, [r3, 0x2E]
	bl itemid_get_x12
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1, 0x2E]
	bl itemid_get_quality
_08069694:
	adds r0, r6, 0
	adds r0, 0x20
	ldrb r1, [r0]
	str r0, [sp, 0x28]
	cmp r1, 0x25
	beq _080696A4
	cmp r1, 0x4A
	bne _080696A8
_080696A4:
	lsls r0, r7, 17
	lsrs r7, r0, 16
_080696A8:
	ldr r0, =0x00000867
	ldr r1, [sp, 0x10]
	bl sub_8069ED8
	lsls r0, 24
	cmp r0, 0
	beq _080696C4
	movs r0, 0x6E
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
_080696C4:
	ldr r0, =0x0000086b
	ldr r1, [sp, 0x14]
	bl sub_8069ED8
	lsls r0, 24
	cmp r0, 0
	beq _080696E4
	movs r0, 0x6E
	ldr r2, [sp, 0x18]
	muls r0, r2
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
_080696E4:
	ldr r4, =0x0000086d
	adds r0, r4, 0
	ldr r1, [sp, 0x10]
	bl sub_8069ED8
	lsls r0, 24
	cmp r0, 0
	beq _08069708
	movs r0, 0x6E
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_08069708:
	adds r0, r4, 0
	ldr r1, [sp, 0x14]
	bl sub_8069ED8
	lsls r0, 24
	cmp r0, 0
	beq _08069728
	movs r0, 0x6E
	ldr r1, [sp, 0x1C]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x1C]
_08069728:
	movs r2, 0
	ldr r4, =gUnknown_08329D74
	ldr r3, [sp, 0x4]
	adds r3, 0x20
	str r3, [sp, 0x2C]
	adds r3, r4, 0
_08069734:
	lsls r1, r2, 1
	ldrb r0, [r3]
	cmp r9, r0
	bne _08069774
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r10, r0
	bne _08069774
	mov r1, r10
	cmp r1, 0x8
	bls _0806966C
	ldr r0, [sp, 0x24]
	adds r0, 0x64
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	b _0806977C
	.pool
_08069774:
	adds r3, 0x2
	adds r2, 0x1
	cmp r2, 0x10
	bls _08069734
_0806977C:
	mov r3, r9
	cmp r3, 0x1D
	bne _08069790
	movs r0, 0x96
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
_08069790:
	mov r0, r9
	cmp r0, 0x22
	bne _080697C6
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x003f0100
	ands r0, r1
	cmp r0, 0
	bne _080697C6
	ldr r1, =0xfffffe69
	adds r0, r1, 0
	ldrh r2, [r6]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080697C6
	movs r0, 0x96
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_080697C6:
	ldr r0, [sp, 0x20]
	cmp r0, 0x22
	bne _080697FC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x003f0100
	ands r0, r1
	cmp r0, 0
	bne _080697FC
	ldr r1, =0xfffffe69
	adds r0, r1, 0
	ldr r2, [sp, 0x4]
	ldrh r2, [r2]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080697FC
	movs r0, 0x96
	ldr r3, [sp, 0x1C]
	muls r0, r3
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x1C]
_080697FC:
	mov r0, r9
	cmp r0, 0x23
	bne _08069812
	ldrh r1, [r6]
	ldr r0, =0x00000175
	cmp r1, r0
	bne _08069812
	mov r1, r8
	lsls r0, r1, 17
	lsrs r0, 16
	mov r8, r0
_08069812:
	ldr r2, [sp, 0x20]
	cmp r2, 0x24
	bne _0806982A
	ldr r3, [sp, 0x4]
	ldrh r1, [r3]
	ldr r0, =0x00000175
	cmp r1, r0
	bne _0806982A
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 17
	lsrs r0, 16
	str r0, [sp, 0x1C]
_0806982A:
	mov r2, r9
	cmp r2, 0x2D
	bne _0806983E
	ldrh r0, [r6]
	cmp r0, 0x19
	bne _0806983E
	mov r3, r8
	lsls r0, r3, 17
	lsrs r0, 16
	mov r8, r0
_0806983E:
	ldr r0, [sp, 0x20]
	cmp r0, 0x40
	bne _08069854
	ldr r1, [sp, 0x4]
	ldrh r0, [r1]
	cmp r0, 0x84
	bne _08069854
	ldr r2, [sp, 0x18]
	lsls r0, r2, 17
	lsrs r0, 16
	str r0, [sp, 0x18]
_08069854:
	mov r3, r9
	cmp r3, 0x41
	bne _0806986A
	ldrh r0, [r6]
	subs r0, 0x68
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0806986A
	lsls r0, r7, 17
	lsrs r7, r0, 16
_0806986A:
	ldr r1, [sp, 0x2C]
	ldrb r0, [r1]
	cmp r0, 0x2F
	bne _08069882
	mov r2, r10
	cmp r2, 0xA
	beq _0806987C
	cmp r2, 0xF
	bne _08069882
_0806987C:
	mov r3, r8
	lsrs r3, 1
	mov r8, r3
_08069882:
	ldr r0, [sp, 0x28]
	ldrb r4, [r0]
	cmp r4, 0x37
	bne _08069898
	movs r0, 0x96
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
_08069898:
	cmp r4, 0x39
	bne _080698C6
	movs r0, 0
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x3A
	movs r3, 0
	bl ability_something
	lsls r0, 24
	cmp r0, 0
	beq _080698C6
	movs r0, 0x96
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_080698C6:
	ldr r2, [sp, 0x28]
	ldrb r0, [r2]
	cmp r0, 0x3A
	bne _080698F8
	movs r0, 0
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x39
	movs r3, 0
	bl ability_something
	lsls r0, 24
	cmp r0, 0
	beq _080698F8
	movs r0, 0x96
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
_080698F8:
	ldr r1, [sp, 0x28]
	ldrb r0, [r1]
	cmp r0, 0x3E
	bne _08069914
	ldr r0, [r6, 0x4C]
	cmp r0, 0
	beq _08069914
	movs r0, 0x96
	muls r0, r7
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
_08069914:
	ldr r2, [sp, 0x2C]
	ldrb r0, [r2]
	cmp r0, 0x3F
	bne _08069936
	ldr r3, [sp, 0x4]
	ldr r0, [r3, 0x4C]
	cmp r0, 0
	beq _08069936
	movs r0, 0x96
	ldr r1, [sp, 0x18]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x18]
_08069936:
	mov r2, r10
	cmp r2, 0xD
	bne _0806995A
	movs r0, 0
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0
	movs r3, 0xFD
	bl ability_something
	lsls r0, 24
	cmp r0, 0
	beq _0806995A
	ldr r1, =gUnknown_020244E0
	ldrh r0, [r1]
	lsrs r0, 1
	strh r0, [r1]
_0806995A:
	mov r3, r10
	cmp r3, 0xA
	bne _0806997E
	movs r0, 0
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0
	movs r3, 0xFE
	bl ability_something
	lsls r0, 24
	cmp r0, 0
	beq _0806997E
	ldr r1, =gUnknown_020244E0
	ldrh r0, [r1]
	lsrs r0, 1
	strh r0, [r1]
_0806997E:
	mov r0, r10
	cmp r0, 0xC
	bne _080699AE
	ldr r1, [sp, 0x28]
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _080699AE
	ldrh r0, [r6, 0x2C]
	movs r1, 0x3
	bl __udivsi3
	ldrh r1, [r6, 0x28]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bhi _080699AE
	ldr r4, =gUnknown_020244E0
	ldrh r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4]
_080699AE:
	mov r2, r10
	cmp r2, 0xA
	bne _080699DE
	ldr r3, [sp, 0x28]
	ldrb r0, [r3]
	cmp r0, 0x42
	bne _080699DE
	ldrh r0, [r6, 0x2C]
	movs r1, 0x3
	bl __udivsi3
	ldrh r1, [r6, 0x28]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bhi _080699DE
	ldr r4, =gUnknown_020244E0
	ldrh r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4]
_080699DE:
	mov r0, r10
	cmp r0, 0xB
	bne _08069A0E
	ldr r1, [sp, 0x28]
	ldrb r0, [r1]
	cmp r0, 0x43
	bne _08069A0E
	ldrh r0, [r6, 0x2C]
	movs r1, 0x3
	bl __udivsi3
	ldrh r1, [r6, 0x28]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bhi _08069A0E
	ldr r4, =gUnknown_020244E0
	ldrh r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4]
_08069A0E:
	mov r2, r10
	cmp r2, 0x6
	bne _08069A3E
	ldr r3, [sp, 0x28]
	ldrb r0, [r3]
	cmp r0, 0x44
	bne _08069A3E
	ldrh r0, [r6, 0x2C]
	movs r1, 0x3
	bl __udivsi3
	ldrh r1, [r6, 0x28]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bhi _08069A3E
	ldr r4, =gUnknown_020244E0
	ldrh r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4]
_08069A3E:
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020241EA
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08069A58
	ldr r0, [sp, 0x18]
	lsrs r0, 1
	str r0, [sp, 0x18]
_08069A58:
	mov r1, r10
	cmp r1, 0x8
	bls _08069A60
	b _08069BC2
_08069A60:
	ldr r0, =gCritMultiplier
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x2
	bne _08069AA0
	movs r0, 0x19
	ldrsb r0, [r6, r0]
	cmp r0, 0x6
	ble _08069A9C
	ldr r2, =gUnknown_08329D2E
	b _08069AA6
	.pool
_08069A9C:
	adds r5, r7, 0
	b _08069ABE
_08069AA0:
	ldr r2, =gUnknown_08329D2E
	movs r0, 0x19
	ldrsb r0, [r6, r0]
_08069AA6:
	lsls r0, 1
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r7, 0
	muls r5, r1
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl __divsi3
	adds r5, r0, 0
_08069ABE:
	ldr r0, =gUnknown_020244E0
	ldrh r0, [r0]
	muls r5, r0
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x5
	bl __divsi3
	adds r0, 0x2
	muls r5, r0
	ldrb r0, [r4]
	cmp r0, 0x2
	bne _08069AFC
	ldr r2, [sp, 0x4]
	movs r0, 0x1A
	ldrsb r0, [r2, r0]
	cmp r0, 0x5
	bgt _08069AF8
	ldr r2, =gUnknown_08329D2E
	ldr r3, [sp, 0x4]
	movs r0, 0x1A
	ldrsb r0, [r3, r0]
	b _08069B04
	.pool
_08069AF8:
	ldr r3, [sp, 0x18]
	b _08069B1E
_08069AFC:
	ldr r2, =gUnknown_08329D2E
	ldr r1, [sp, 0x4]
	movs r0, 0x1A
	ldrsb r0, [r1, r0]
_08069B04:
	lsls r0, 1
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r7, [sp, 0x18]
	adds r3, r7, 0
	muls r3, r1
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r3, 0
	bl __divsi3
	adds r3, r0, 0
_08069B1E:
	adds r0, r5, 0
	adds r1, r3, 0
	bl __divsi3
	adds r5, r0, 0
	movs r1, 0x32
	bl __divsi3
	adds r5, r0, 0
	ldr r0, [r6, 0x4C]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08069B48
	ldr r1, [sp, 0x28]
	ldrb r0, [r1]
	cmp r0, 0x3E
	beq _08069B48
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069B48:
	movs r0, 0x1
	ldr r2, [sp, 0xC]
	ands r0, r2
	cmp r0, 0
	beq _08069B8A
	ldrb r1, [r4]
	cmp r1, 0x1
	bne _08069B8A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08069B84
	movs r0, 0x2
	bl sub_8069DEC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08069B84
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	lsls r5, r0, 1
	b _08069B8A
	.pool
_08069B84:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069B8A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08069BBC
	ldr r0, =gBattleMoves
	ldr r3, [sp, 0x8]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x6]
	cmp r0, 0x8
	bne _08069BBC
	movs r0, 0x2
	bl sub_8069DEC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08069BBC
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069BBC:
	cmp r5, 0
	bne _08069BC2
	movs r5, 0x1
_08069BC2:
	mov r7, r10
	cmp r7, 0x9
	bne _08069BCA
	movs r5, 0
_08069BCA:
	mov r0, r10
	cmp r0, 0x9
	bhi _08069BD2
	b _08069DD4
_08069BD2:
	ldr r0, =gCritMultiplier
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x2
	bne _08069BFC
	movs r0, 0x1C
	ldrsb r0, [r6, r0]
	cmp r0, 0x6
	ble _08069BF8
	ldr r2, =gUnknown_08329D2E
	b _08069C02
	.pool
_08069BF8:
	mov r5, r8
	b _08069C1A
_08069BFC:
	ldr r2, =gUnknown_08329D2E
	movs r0, 0x1C
	ldrsb r0, [r6, r0]
_08069C02:
	lsls r0, 1
	adds r1, r0, r2
	ldrb r1, [r1]
	mov r5, r8
	muls r5, r1
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl __divsi3
	adds r5, r0, 0
_08069C1A:
	ldr r0, =gUnknown_020244E0
	ldrh r0, [r0]
	muls r5, r0
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x5
	bl __divsi3
	adds r0, 0x2
	muls r5, r0
	ldrb r0, [r4]
	cmp r0, 0x2
	bne _08069C54
	ldr r1, [sp, 0x4]
	movs r0, 0x1D
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _08069C50
	ldr r2, =gUnknown_08329D2E
	b _08069C5C
	.pool
_08069C50:
	ldr r3, [sp, 0x1C]
	b _08069C76
_08069C54:
	ldr r2, =gUnknown_08329D2E
	ldr r7, [sp, 0x4]
	movs r0, 0x1D
	ldrsb r0, [r7, r0]
_08069C5C:
	lsls r0, 1
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r6, [sp, 0x1C]
	adds r3, r6, 0
	muls r3, r1
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r3, 0
	bl __divsi3
	adds r3, r0, 0
_08069C76:
	adds r0, r5, 0
	adds r1, r3, 0
	bl __divsi3
	adds r5, r0, 0
	movs r1, 0x32
	bl __divsi3
	adds r5, r0, 0
	movs r0, 0x2
	ldr r7, [sp, 0xC]
	ands r0, r7
	cmp r0, 0
	beq _08069CCA
	ldrb r1, [r4]
	cmp r1, 0x1
	bne _08069CCA
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08069CC4
	movs r0, 0x2
	bl sub_8069DEC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08069CC4
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	lsls r5, r0, 1
	b _08069CCA
	.pool
_08069CC4:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069CCA:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08069CFC
	ldr r0, =gBattleMoves
	ldr r2, [sp, 0x8]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x6]
	cmp r0, 0x8
	bne _08069CFC
	movs r0, 0x2
	bl sub_8069DEC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08069CFC
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069CFC:
	movs r0, 0
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl ability_something
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08069DAC
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl ability_something
	lsls r0, 24
	cmp r0, 0
	bne _08069DAC
	ldr r2, =gUnknown_020243CC
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _08069D64
	mov r3, r10
	cmp r3, 0xA
	beq _08069D50
	cmp r3, 0xB
	beq _08069D58
	b _08069D64
	.pool
_08069D50:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
	b _08069D64
_08069D58:
	lsls r0, r5, 4
	subs r0, r5
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
_08069D64:
	ldrh r1, [r4]
	movs r0, 0x9F
	ands r0, r1
	cmp r0, 0
	beq _08069D7C
	ldr r0, =gUnknown_020241EA
	ldrh r0, [r0]
	cmp r0, 0x4C
	bne _08069D7C
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069D7C:
	ldrh r1, [r4]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08069DAC
	mov r6, r10
	cmp r6, 0xA
	beq _08069D98
	cmp r6, 0xB
	beq _08069DA6
	b _08069DAC
	.pool
_08069D98:
	lsls r0, r5, 4
	subs r0, r5
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
	b _08069DAC
_08069DA6:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_08069DAC:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r7, [sp, 0x10]
	lsls r1, r7, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08069DD4
	mov r0, r10
	cmp r0, 0xA
	bne _08069DD4
	lsls r0, r5, 4
	subs r0, r5
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
_08069DD4:
	adds r0, r5, 0x2
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806957C

	.align 2, 0 @ Don't pad with nop.
