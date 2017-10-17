	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_80730D4
sub_80730D4: @ 80730D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	ldr r1, =gUnknown_0832C3C4
	mov r0, sp
	movs r2, 0x14
	bl memcpy
	ldr r1, =gSprites
	ldr r2, [sp, 0x14]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankIdentity
	ldr r1, =gMonSpritesGfxPtr
	ldr r2, [r1]
	movs r3, 0xBA
	lsls r3, 1
	adds r2, r3
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 7
	movs r0, 0xA4
	lsls r0, 3
	adds r1, r0
	ldr r0, [r2]
	adds r6, r0, r1
	movs r1, 0x5
	mov r8, r1
	adds r0, r4, 0
	bl GetNature
	lsls r0, 24
	mov r4, sp
	adds r4, 0x6
	ldr r1, =gNatureNamePointers
	lsrs r0, 22
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	adds r0, r6, 0
	movs r1, 0x9
	mov r2, sp
	bl RenderTextFont9
	movs r7, 0x6
	movs r5, 0
	mov r2, sp
	adds r2, 0x9
	str r2, [sp, 0x1C]
_08073158:
	mov r3, sp
	adds r0, r3, r7
	ldrb r1, [r0]
	adds r0, r1, 0
	subs r0, 0x37
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _08073176
	adds r0, r1, 0
	adds r0, 0x79
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _0807318C
_08073176:
	movs r0, 0x2C
	b _080731AA
	.pool
_0807318C:
	adds r0, r1, 0
	subs r0, 0x4B
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080731A4
	adds r0, r1, 0
	adds r0, 0x65
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _080731A8
_080731A4:
	movs r0, 0x2D
	b _080731AA
_080731A8:
	movs r0, 0x2B
_080731AA:
	bl GetHealthboxElementGfxPtr
	lsls r1, r5, 6
	adds r1, r6, r1
	ldr r2, =0x04000008
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, 0x1
	cmp r5, r8
	bcc _08073158
	movs r7, 0x1
	ldr r0, [sp, 0x14]
	lsls r0, 4
	str r0, [sp, 0x18]
	movs r1, 0x1
	add r1, r8
	mov r9, r1
	cmp r7, r9
	bge _08073236
	ldr r1, =gSprites
	ldr r2, =0x04000008
	mov r10, r2
	ldr r3, [sp, 0x14]
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	mov r8, r0
_080731E6:
	mov r1, r8
	ldrh r0, [r1, 0x4]
	lsls r0, 22
	lsrs r0, 22
	adds r5, r7, 0
	cmp r7, 0
	bge _080731F6
	adds r5, r7, 0x7
_080731F6:
	asrs r5, 3
	lsls r4, r5, 3
	subs r4, r7, r4
	adds r0, r4
	lsls r5, 6
	adds r0, r5
	lsls r0, 5
	ldr r2, =0x06010000
	adds r1, r0, r2
	adds r0, r6, 0
	mov r2, r10
	bl CpuSet
	adds r6, 0x20
	mov r3, r8
	ldrh r0, [r3, 0x4]
	lsls r0, 22
	lsrs r0, 22
	adds r4, 0x8
	adds r0, r4
	adds r0, r5
	lsls r0, 5
	ldr r2, =0x06010000
	adds r1, r0, r2
	adds r0, r6, 0
	mov r2, r10
	bl CpuSet
	adds r6, 0x20
	adds r7, 0x1
	cmp r7, r9
	blt _080731E6
_08073236:
	ldr r6, =gSprites
	ldr r3, [sp, 0x18]
	ldr r1, [sp, 0x14]
	adds r0, r3, r1
	lsls r0, 2
	adds r0, r6
	ldrh r4, [r0, 0x38]
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x7C
	ldrb r1, [r0]
	mov r0, sp
	adds r0, 0x6
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, [r5]
	adds r0, 0x7B
	ldrb r1, [r0]
	ldr r0, [sp, 0x1C]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x5]
	movs r0, 0xBA
	strb r0, [r1, 0x8]
	ldr r5, =gMonSpritesGfxPtr
	ldr r0, [r5]
	movs r2, 0xBA
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	movs r1, 0x9
	mov r2, sp
	bl RenderTextFont9
	movs r7, 0
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r6, r0, r6
	movs r4, 0x20
_08073296:
	cmp r7, 0x1
	bgt _080732D4
	ldr r0, [r5]
	movs r3, 0xBA
	lsls r3, 1
	adds r0, r3
	ldr r0, [r0]
	adds r0, r4
	ldrh r1, [r6, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r2, r7, 0x2
	adds r1, r2
	lsls r1, 5
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _080732F4
	.pool
_080732D4:
	ldr r0, [r5]
	movs r3, 0xBA
	lsls r3, 1
	adds r0, r3
	ldr r0, [r0]
	adds r0, r4
	ldrh r1, [r6, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r1, r7, r1
	lsls r1, 5
	ldr r2, =0x060100c0
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_080732F4:
	adds r4, 0x40
	adds r7, 0x1
	cmp r7, 0x4
	ble _08073296
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80730D4

	thumb_func_start sub_8073314
sub_8073314: @ 8073314
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r9, r0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r9, r0
	blt _0807332E
	b _080735BA
_0807332E:
	ldr r1, =gSprites
	mov r10, r1
	ldr r2, =gBattlePartyID
	mov r8, r2
_08073336:
	ldr r0, =gHealthBoxesIds
	mov r1, r9
	adds r6, r1, r0
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _08073354
	b _080735A8
_08073354:
	mov r2, r9
	lsls r0, r2, 24
	lsrs r7, r0, 24
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807336A
	b _080735A8
_0807336A:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _08073382
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08073382
	b _080735A8
_08073382:
	ldr r5, =gBattleSpritesDataPtr
	ldr r0, [r5]
	ldr r3, [r0]
	mov r0, r9
	lsls r4, r0, 2
	adds r3, r4, r3
	ldr r0, [r3]
	lsls r0, 27
	lsrs r0, 31
	movs r2, 0x1
	eors r2, r0
	lsls r2, 4
	mov r12, r2
	ldrb r0, [r3]
	movs r2, 0x11
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	mov r1, r12
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r5]
	ldr r0, [r0]
	adds r4, r0
	ldr r0, [r4]
	lsls r0, 27
	lsrs r4, r0, 31
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080734B0
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _080733D0
	b _080735A8
_080733D0:
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	ands r2, r0
	cmp r2, 0
	beq _080733DE
	b _080735A8
_080733DE:
	cmp r4, 0x1
	bne _08073468
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrh r0, [r0, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	str r2, [sp]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r2, =0x06010000
	adds r1, r2
	mov r0, sp
	ldr r2, =0x05000040
	bl CpuSet
	ldrb r4, [r6]
	mov r1, r8
	ldrh r0, [r1]
	movs r2, 0x64
	muls r0, r2
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl UpdateHpTextInHealthboxInDoubles
	ldrb r4, [r6]
	mov r2, r8
	ldrh r0, [r2]
	movs r1, 0x64
	muls r0, r1
	ldr r2, =gPlayerParty
	b _08073536
	.pool
_08073468:
	ldrb r0, [r6]
	bl draw_status_ailment_maybe
	ldrb r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	movs r2, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0x5
	bl UpdateHealthboxAttribute
	movs r0, 0x75
	bl GetHealthboxElementGfxPtr
	ldrb r2, [r6]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r10
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r2, =0x06010680
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _08073592
	.pool
_080734B0:
	cmp r4, 0x1
	bne _0807355C
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	ands r2, r0
	cmp r2, 0
	beq _080734DC
	ldrb r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	movs r2, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	bl sub_80730D4
	b _08073592
	.pool
_080734DC:
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrh r0, [r0, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	str r2, [sp]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r0, =0x06010000
	adds r1, r0
	mov r0, sp
	ldr r2, =0x05000040
	bl CpuSet
	ldrb r4, [r6]
	mov r1, r8
	ldrh r0, [r1]
	movs r2, 0x64
	muls r0, r2
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl UpdateHpTextInHealthboxInDoubles
	ldrb r4, [r6]
	mov r2, r8
	ldrh r0, [r2]
	movs r1, 0x64
	muls r0, r1
	ldr r2, =gEnemyParty
_08073536:
	adds r0, r2
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0x1
	bl UpdateHpTextInHealthboxInDoubles
	b _08073592
	.pool
_0807355C:
	ldrb r0, [r6]
	bl draw_status_ailment_maybe
	ldrb r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	movs r5, 0x64
	muls r1, r5
	ldr r4, =gEnemyParty
	adds r1, r4
	movs r2, 0x5
	bl UpdateHealthboxAttribute
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08073592
	ldrb r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	muls r1, r5
	adds r1, r4
	movs r2, 0x4
	bl UpdateHealthboxAttribute
_08073592:
	ldr r0, =gHealthBoxesIds
	add r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrh r1, [r0, 0x3C]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0x3C]
_080735A8:
	movs r0, 0x2
	add r8, r0
	movs r1, 0x1
	add r9, r1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r9, r0
	bge _080735BA
	b _08073336
_080735BA:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8073314

	thumb_func_start sub_80735DC
sub_80735DC: @ 80735DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0xC]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	lsls r2, 24
	lsrs r2, 24
	adds r4, r2, 0
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	cmp r4, 0
	beq _0807360C
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0807365C
_0807360C:
	ldr r0, [sp, 0x8]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08073630
	movs r0, 0
	mov r9, r0
	movs r5, 0x88
	movs r4, 0x60
	movs r1, 0x64
	mov r10, r1
	ldr r2, =0x0000fffb
	mov r8, r2
	b _0807366C
	.pool
_08073630:
	movs r3, 0x1
	mov r9, r3
	cmp r4, 0
	beq _08073642
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _08073648
_08073642:
	movs r5, 0x68
	movs r4, 0x28
	b _0807364C
_08073648:
	movs r5, 0x68
	movs r4, 0x10
_0807364C:
	ldr r6, =0x0000ff9c
	mov r10, r6
	movs r0, 0x5
	mov r8, r0
	b _0807366C
	.pool
_0807365C:
	movs r1, 0x1
	mov r9, r1
	movs r5, 0x68
	movs r4, 0x28
	ldr r2, =0x0000ff9c
	mov r10, r2
	movs r3, 0x5
	mov r8, r3
_0807366C:
	ldr r0, =gUnknown_0832C334
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_0832C34C
	bl LoadSpriteSheet
	ldr r0, =gUnknown_0832C33C
	bl LoadSpritePalette
	ldr r0, =gUnknown_0832C344
	bl LoadSpritePalette
	mov r0, r9
	lsls r6, r0, 1
	adds r0, r6, r0
	lsls r0, 3
	ldr r1, =gUnknown_0832C364
	adds r0, r1
	lsls r5, 16
	asrs r1, r5, 16
	lsls r4, 16
	asrs r2, r4, 16
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	lsls r0, 4
	ldr r1, [sp, 0x14]
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r7, r0, r1
	ldr r1, =gUnknown_0832C2C4
	adds r0, r7, 0
	bl SetSubspriteTables
	mov r2, r10
	strh r2, [r7, 0x24]
	mov r3, r8
	strh r3, [r7, 0x2E]
	str r5, [sp, 0x1C]
	str r4, [sp, 0x20]
	mov r5, r9
	cmp r5, 0
	beq _08073700
	ldrh r0, [r7, 0x20]
	subs r0, 0x60
	strh r0, [r7, 0x20]
	ldrb r1, [r7, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r7, 0x3]
	b _08073706
	.pool
_08073700:
	ldrh r0, [r7, 0x20]
	adds r0, 0x60
	strh r0, [r7, 0x20]
_08073706:
	movs r0, 0
	mov r8, r0
	ldr r1, =gSprites
	mov r10, r1
	mov r7, sp
	mov r2, r9
	adds r0, r6, r2
	lsls r0, 3
	str r0, [sp, 0x18]
	movs r6, 0xA
	movs r5, 0
_0807371C:
	ldr r0, =gUnknown_0832C394
	ldr r3, [sp, 0x20]
	ldr r1, =0xfffc0000
	adds r2, r3, r1
	ldr r3, [sp, 0x18]
	adds r0, r3, r0
	ldr r3, [sp, 0x1C]
	asrs r1, r3, 16
	asrs r2, 16
	movs r3, 0x9
	bl CreateSpriteAtEnd
	strb r0, [r7]
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _0807374C
	ldrb r0, [r7]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r2, =gSprites + 0x1C
	adds r1, r2
	ldr r0, =sub_80741C8
	str r0, [r1]
_0807374C:
	ldr r4, =gSprites
	mov r3, r9
	cmp r3, 0
	bne _0807376E
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	strh r3, [r0, 0x24]
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r10
	mov r1, r9
	strh r1, [r0, 0x26]
_0807376E:
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	mov r2, sp
	ldrh r2, [r2, 0x14]
	strh r2, [r0, 0x2E]
	mov r3, r9
	cmp r3, 0
	bne _080737C8
	ldrb r0, [r7]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x20]
	adds r0, 0x18
	adds r0, r5
	strh r0, [r1, 0x20]
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r6, [r0, 0x30]
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x78
	b _0807380A
	.pool
_080737C8:
	ldrb r0, [r7]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrh r3, [r2, 0x20]
	subs r3, 0x18
	movs r1, 0x5
	mov r0, r8
	subs r1, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	subs r3, r0
	strh r3, [r2, 0x20]
	ldrb r0, [r7]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	movs r1, 0x6
	mov r3, r8
	subs r1, r3
	lsls r0, r1, 3
	subs r0, r1
	adds r0, 0xA
	strh r0, [r2, 0x30]
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff88
_0807380A:
	strh r1, [r0, 0x24]
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r9
	strh r1, [r0, 0x32]
	adds r7, 0x1
	adds r6, 0x7
	adds r5, 0xA
	movs r2, 0x1
	add r8, r2
	mov r3, r8
	cmp r3, 0x5
	bgt _0807382C
	b _0807371C
_0807382C:
	ldr r0, [sp, 0x8]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0807383A
	b _080739E8
_0807383A:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x40
	ands r1, r2
	cmp r1, 0
	beq _080738F4
	ldr r5, =0x0000ffff
	mov r10, r5
	ldr r6, =gSprites
	ldr r0, =0x000003ff
	adds r7, r0, 0
	ldr r1, =0xfffffc00
	mov r9, r1
	mov r4, sp
	ldr r5, [sp, 0xC]
	movs r2, 0x5
	mov r8, r2
_0807385C:
	ldrh r0, [r5]
	cmp r0, r10
	bne _080738A8
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x1
	ands r1, r7
	mov r0, r9
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	b _080738E2
	.pool
_080738A8:
	cmp r0, 0
	bne _080738C0
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _080738D8
_080738C0:
	ldr r0, [r5, 0x4]
	cmp r0, 0
	beq _080738E2
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
_080738D8:
	ands r1, r7
	mov r0, r9
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_080738E2:
	adds r4, 0x1
	adds r5, 0x8
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r0, r8
	cmp r0, 0
	bge _0807385C
	b _08073B9A
_080738F4:
	movs r1, 0x5
	mov r10, r1
	movs r7, 0
	ldr r2, =gSprites
	mov r8, r2
	ldr r3, =0x000003ff
	mov r9, r3
	ldr r5, =0xfffffc00
	mov r12, r5
	ldr r6, [sp, 0xC]
	mov r5, sp
_0807390A:
	ldrh r0, [r6]
	ldr r1, =0x0000ffff
	cmp r0, r1
	bne _08073958
	mov r4, sp
	add r4, r10
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x1
	mov r0, r9
	ands r1, r0
	mov r0, r12
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	subs r1, 0x2
	add r10, r1
	b _080739DE
	.pool
_08073958:
	cmp r0, 0
	bne _08073970
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _080739D0
_08073970:
	ldr r1, =gBattleTypeFlags
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _080739B8
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	movs r2, 0xA8
	lsls r2, 2
	adds r0, r2
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r7, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080739B8
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _080739D0
	.pool
_080739B8:
	ldr r0, [r6, 0x4]
	cmp r0, 0
	beq _080739DC
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r8
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
_080739D0:
	mov r0, r9
	ands r1, r0
	mov r0, r12
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_080739DC:
	adds r5, 0x1
_080739DE:
	adds r6, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _0807390A
	b _08073B9A
_080739E8:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r2, =0x00008040
	ands r1, r2
	cmp r1, 0
	beq _08073AA4
	ldr r1, =0x0000ffff
	mov r10, r1
	ldr r6, =gSprites
	ldr r2, =0x000003ff
	adds r7, r2, 0
	ldr r3, =0xfffffc00
	mov r9, r3
	ldr r5, [sp, 0xC]
	mov r4, sp
	adds r4, 0x5
	movs r0, 0x5
	mov r8, r0
_08073A0C:
	ldrh r0, [r5]
	cmp r0, r10
	bne _08073A58
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x1
	ands r1, r7
	mov r0, r9
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	b _08073A92
	.pool
_08073A58:
	cmp r0, 0
	bne _08073A70
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _08073A88
_08073A70:
	ldr r0, [r5, 0x4]
	cmp r0, 0
	beq _08073A92
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
_08073A88:
	ands r1, r7
	mov r0, r9
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_08073A92:
	subs r4, 0x1
	adds r5, 0x8
	movs r1, 0x1
	negs r1, r1
	add r8, r1
	mov r2, r8
	cmp r2, 0
	bge _08073A0C
	b _08073B9A
_08073AA4:
	movs r3, 0
	mov r8, r3
	movs r7, 0
	ldr r5, =gSprites
	mov r9, r5
	ldr r6, =0x000003ff
	mov r12, r6
	ldr r0, =0xfffffc00
	mov r10, r0
	ldr r6, [sp, 0xC]
	mov r5, sp
	adds r5, 0x5
_08073ABC:
	ldrh r0, [r6]
	ldr r1, =0x0000ffff
	cmp r0, r1
	bne _08073B08
	mov r4, sp
	add r4, r8
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x1
	mov r0, r12
	ands r1, r0
	mov r0, r10
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r1, 0x1
	strh r1, [r0, 0x3C]
	add r8, r1
	b _08073B92
	.pool
_08073B08:
	cmp r0, 0
	bne _08073B20
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _08073B84
_08073B20:
	ldr r1, =gBattleTypeFlags
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _08073B6C
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	ldr r3, =0x000002a1
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r7, 2
	ldr r2, =gBitTable
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08073B6C
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x3
	b _08073B84
	.pool
_08073B6C:
	ldr r0, [r6, 0x4]
	cmp r0, 0
	beq _08073B90
	ldrb r0, [r5]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x2
_08073B84:
	mov r0, r12
	ands r1, r0
	mov r0, r10
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_08073B90:
	subs r5, 0x1
_08073B92:
	adds r6, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _08073ABC
_08073B9A:
	ldr r0, =TaskDummy
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gTasks
	lsls r3, r4, 2
	adds r1, r3, r4
	lsls r1, 3
	adds r0, r1, r2
	mov r5, sp
	ldrh r5, [r5, 0x8]
	strh r5, [r0, 0x8]
	mov r6, sp
	ldrh r6, [r6, 0x14]
	strh r6, [r0, 0xA]
	movs r0, 0
	mov r8, r0
	adds r0, r2, 0
	adds r0, 0xE
	adds r1, r0
_08073BC6:
	mov r0, sp
	add r0, r8
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, 0x2
	movs r5, 0x1
	add r8, r5
	mov r6, r8
	cmp r6, 0x5
	ble _08073BC6
	adds r0, r3, r4
	lsls r0, 3
	adds r0, r2
	mov r1, sp
	ldrh r1, [r1, 0x10]
	strh r1, [r0, 0x1C]
	ldr r2, [sp, 0x10]
	cmp r2, 0
	beq _08073C0A
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r3, [r0, 0x8]
	ldrb r2, [r3, 0x9]
	lsls r1, r2, 27
	lsrs r1, 29
	adds r1, 0x1
	movs r0, 0x7
	ands r1, r0
	lsls r1, 2
	movs r0, 0x1D
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x9]
_08073C0A:
	movs r0, 0x72
	movs r1, 0
	bl PlaySE12WithPanning
	adds r0, r4, 0
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80735DC

	thumb_func_start sub_8073C30
sub_8073C30: @ 8073C30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gTasks
	lsls r3, r0, 2
	adds r1, r3, r0
	lsls r1, 3
	adds r0, r1, r2
	ldrb r7, [r0, 0x1C]
	ldrb r4, [r0, 0xA]
	mov r10, r4
	ldrb r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r5, 0
	str r3, [sp, 0xC]
	adds r2, 0xE
	adds r2, r1, r2
_08073C5E:
	mov r0, sp
	adds r1, r0, r5
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x5
	ble _08073C5E
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r1, =gTasks
	ldr r0, [sp, 0xC]
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x10
	strh r1, [r0, 0x26]
	movs r5, 0
	mov r1, r10
	lsls r1, 4
	str r1, [sp, 0x10]
	ldr r3, =gSprites
	movs r6, 0xD
	negs r6, r6
	mov r12, r3
	movs r4, 0x4
_08073CA0:
	mov r2, sp
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, 0x1]
	adds r5, 0x1
	cmp r5, 0x5
	ble _08073CA0
	ldr r2, [sp, 0x10]
	add r2, r10
	lsls r2, 2
	add r2, r12
	ldrb r1, [r2, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x1]
	cmp r7, 0
	bne _08073CDA
	b _08073DE0
_08073CDA:
	movs r5, 0
	mov r6, r12
	mov r9, r5
	adds r3, r6, 0
	adds r3, 0x1C
	mov r4, sp
	movs r7, 0
_08073CE8:
	ldr r0, [sp, 0x8]
	str r3, [sp, 0x14]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, [sp, 0x14]
	cmp r2, 0
	beq _08073D4C
	movs r0, 0x5
	subs r0, r5
	mov r1, sp
	adds r2, r1, r0
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r7, [r0, 0x30]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r9
	strh r1, [r0, 0x34]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r9
	strh r1, [r0, 0x36]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =sub_8074158
	str r1, [r0]
	ldr r2, =gSprites
	mov r12, r2
	b _08073D82
	.pool
_08073D4C:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r7, [r0, 0x30]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x34]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r2, [r0, 0x36]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =sub_8074158
	str r1, [r0]
	ldr r0, =gSprites
	mov r12, r0
_08073D82:
	adds r4, 0x1
	adds r7, 0x7
	adds r5, 0x1
	cmp r5, 0x5
	ble _08073CE8
	ldr r3, [sp, 0x10]
	add r3, r10
	lsls r3, 2
	mov r1, r12
	adds r0, r3, r1
	movs r2, 0x2E
	ldrsh r1, [r0, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	movs r2, 0
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	mov r1, r12
	adds r1, 0x1C
	adds r3, r1
	ldr r1, =sub_8074090
	str r1, [r3]
	ldr r1, =gUnknown_0832C2CC
	bl SetSubspriteTables
	ldr r1, =gTasks
	ldr r0, [sp, 0xC]
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_battle_throw_own_ball
	str r1, [r0]
	b _08073DEE
	.pool
_08073DE0:
	ldr r0, =gTasks
	ldr r1, [sp, 0xC]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8073F98
	str r0, [r1]
_08073DEE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8073C30

	thumb_func_start task_battle_throw_own_ball
task_battle_throw_own_ball: @ 8073E08
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08073E48
	ldrh r0, [r4, 0x26]
	subs r1, r0, 0x1
	strh r1, [r4, 0x26]
	lsls r0, r1, 16
	cmp r0, 0
	blt _08073E54
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_08073E48:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08073E54
	ldr r0, =sub_8073E64
	str r0, [r4]
_08073E54:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_battle_throw_own_ball

	thumb_func_start sub_8073E64
sub_8073E64: @ 8073E64
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r7, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r3, r0, 3
	adds r4, r3, r7
	ldrb r2, [r4, 0x8]
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08073F54
	ldrb r5, [r4, 0xA]
	movs r4, 0
	ldr r6, =gBattleSpritesDataPtr
	adds r0, r7, 0
	adds r0, 0xE
	adds r2, r3, r0
_08073E96:
	mov r0, sp
	adds r1, r0, r4
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, 0x2
	adds r4, 0x1
	cmp r4, 0x5
	ble _08073E96
	ldr r0, [r6]
	ldr r3, [r0, 0x8]
	ldrb r2, [r3, 0x9]
	lsls r1, r2, 27
	lsrs r1, 29
	subs r1, 0x1
	movs r0, 0x7
	ands r1, r0
	lsls r1, 2
	movs r0, 0x1D
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x9]
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	movs r0, 0x1C
	ands r0, r1
	cmp r0, 0
	bne _08073EFC
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySpriteAndFreeResources
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySpriteAndFreeResources
	b _08073F32
	.pool
_08073EFC:
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	ldr r5, =gSprites
	adds r4, r5
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl FreeSpriteOamMatrix
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
_08073F32:
	movs r4, 0x1
	ldr r5, =gSprites
_08073F36:
	mov r1, sp
	adds r0, r1, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	adds r4, 0x1
	cmp r4, 0x5
	ble _08073F36
	b _08073F8A
	.pool
_08073F54:
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	bne _08073F8A
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
_08073F8A:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8073E64

	thumb_func_start sub_8073F98
sub_8073F98: @ 8073F98
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r7, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r6, r0, 3
	adds r3, r6, r7
	ldrb r5, [r3, 0x8]
	ldrh r0, [r3, 0x26]
	subs r1, r0, 0x1
	strh r1, [r3, 0x26]
	lsls r0, r1, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _08073FD4
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _0807406A
	.pool
_08073FD4:
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _08074034
	ldrb r3, [r3, 0xA]
	movs r5, 0
	adds r0, r7, 0
	adds r0, 0xE
	adds r2, r6, r0
_08073FE6:
	mov r0, sp
	adds r1, r0, r5
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x5
	ble _08073FE6
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySpriteAndFreeResources
	mov r0, sp
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySpriteAndFreeResources
	movs r5, 0x1
_08074016:
	mov r1, sp
	adds r0, r1, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	adds r5, 0x1
	cmp r5, 0x5
	ble _08074016
	b _0807406A
	.pool
_08074034:
	movs r0, 0x3
	negs r0, r0
	cmp r2, r0
	bne _0807406A
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl DestroyTask
_0807406A:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8073F98

	thumb_func_start sub_8074078
sub_8074078: @ 8074078
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x24]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0807408C
	ldrh r0, [r1, 0x2E]
	adds r0, r2, r0
	strh r0, [r1, 0x24]
_0807408C:
	pop {r0}
	bx r0
	thumb_func_end sub_8074078

	thumb_func_start sub_8074090
sub_8074090: @ 8074090
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0
	adds r1, 0x20
	strh r1, [r2, 0x30]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _080740AE
	lsls r0, r1, 16
	asrs r0, 20
	ldrh r1, [r2, 0x24]
	adds r0, r1
	b _080740B6
_080740AE:
	lsls r1, 16
	asrs r1, 20
	ldrh r0, [r2, 0x24]
	subs r0, r1
_080740B6:
	strh r0, [r2, 0x24]
	ldrh r1, [r2, 0x30]
	movs r0, 0xF
	ands r0, r1
	strh r0, [r2, 0x30]
	pop {r0}
	bx r0
	thumb_func_end sub_8074090

	thumb_func_start sub_80740C4
sub_80740C4: @ 80740C4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080740D8
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _0807414E
_080740D8:
	ldrh r0, [r4, 0x32]
	lsls r0, 24
	lsrs r3, r0, 24
	ldrh r2, [r4, 0x34]
	adds r0, r2, 0
	adds r0, 0x38
	lsls r1, r0, 16
	lsrs r2, r1, 16
	ldr r0, =0x0000fff0
	ands r2, r0
	strh r2, [r4, 0x34]
	cmp r3, 0
	beq _0807410C
	lsrs r0, r1, 20
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	ble _0807411C
	movs r0, 0
	strh r0, [r4, 0x24]
	b _0807411C
	.pool
_0807410C:
	lsrs r1, 20
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bge _0807411C
	strh r3, [r4, 0x24]
_0807411C:
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0807414E
	movs r1, 0x3F
	cmp r3, 0
	beq _0807412C
	movs r1, 0xC0
_0807412C:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08074140
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x74
	bl PlaySE2WithPanning
	b _0807414A
_08074140:
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x73
	bl PlaySE1WithPanning
_0807414A:
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_0807414E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80740C4

	thumb_func_start sub_8074158
sub_8074158: @ 8074158
	push {r4,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x30]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r0, 0
	ble _0807416C
	subs r0, r1, 0x1
	strh r0, [r3, 0x30]
	b _080741BC
_0807416C:
	ldrh r0, [r3, 0x32]
	lsls r0, 24
	ldrh r2, [r3, 0x34]
	adds r1, r2, 0
	adds r1, 0x38
	lsls r4, r1, 16
	lsrs r2, r4, 16
	ldr r1, =0x0000fff0
	ands r2, r1
	strh r2, [r3, 0x34]
	cmp r0, 0
	beq _08074190
	lsrs r0, r4, 20
	ldrh r1, [r3, 0x24]
	adds r0, r1
	b _08074196
	.pool
_08074190:
	lsrs r1, r4, 20
	ldrh r0, [r3, 0x24]
	subs r0, r1
_08074196:
	strh r0, [r3, 0x24]
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	movs r2, 0x20
	ldrsh r1, [r3, r2]
	adds r0, r1
	adds r0, 0x8
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	bls _080741BC
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_080741BC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8074158

	thumb_func_start sub_80741C8
sub_80741C8: @ 80741C8
	ldrh r2, [r0, 0x2E]
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrh r2, [r1, 0x24]
	strh r2, [r0, 0x24]
	ldrh r1, [r1, 0x26]
	strh r1, [r0, 0x26]
	bx lr
	.pool
	thumb_func_end sub_80741C8

	thumb_func_start sub_80741E8
sub_80741E8: @ 80741E8
	push {r4-r7,lr}
	sub sp, 0x14
	adds r4, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gDisplayedStringBattle
	ldr r1, =gText_HighlightDarkGrey
	adds r0, r5, 0
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0x2
	add r2, sp, 0x4
	bl GetMonData
	add r0, sp, 0x4
	bl StringGetEnd10
	adds r0, r5, 0
	add r1, sp, 0x4
	bl StringAppend
	adds r5, r0, 0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x1D
	beq _08074236
	cmp r0, 0x20
	bne _0807424A
_08074236:
	movs r0, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	add r0, sp, 0x4
	bl StringCompare
	cmp r0, 0
	bne _0807424A
	movs r6, 0x64
_0807424A:
	cmp r6, 0
	beq _08074268
	cmp r6, 0xFE
	beq _08074270
	ldr r1, =gText_DynColor2
	b _08074272
	.pool
_08074268:
	ldr r1, =gText_DynColor2Male
	b _08074272
	.pool
_08074270:
	ldr r1, =gText_DynColor1Female
_08074272:
	adds r0, r5, 0
	bl StringCopy
	ldr r0, =gDisplayedStringBattle
	add r1, sp, 0x10
	str r1, [sp]
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x2
	bl AddTextPrinterAndCreateWindowOnHealthbox
	adds r6, r0, 0
	ldr r0, =gSprites
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x4]
	lsls r0, 22
	lsrs r4, r0, 17
	ldrh r0, [r1, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080742F0
	ldr r1, =0x06010040
	adds r0, r4, r1
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_8075198
	bl IsDoubleBattle
	lsls r0, 24
	ldr r1, =0x06010400
	adds r5, r4, r1
	cmp r0, 0
	bne _080742C8
	ldr r0, =0x06010800
	adds r5, r4, r0
_080742C8:
	adds r1, r6, 0
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8075198
	b _080742FC
	.pool
_080742F0:
	ldr r1, =0x06010020
	adds r0, r4, r1
	adds r1, r6, 0
	movs r2, 0x7
	bl sub_8075198
_080742FC:
	ldr r0, [sp, 0x10]
	bl RemoveWindow_
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80741E8

	thumb_func_start sub_8074310
sub_8074310: @ 8074310
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _080743E6
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	bne _080743E6
	ldr r6, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r6
	ldrh r0, [r5, 0x3A]
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080743E6
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _080743E6
	ldrh r0, [r5, 0x38]
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r7, 0
	beq _080743C4
	movs r0, 0x46
	bl GetHealthboxElementGfxPtr
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 17
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _080743E6
	.pool
_080743C4:
	str r7, [sp]
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 17
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0
	ldr r0, =0x06010000
	adds r1, r0
	ldr r2, =0x05000008
	mov r0, sp
	bl CpuSet
_080743E6:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8074310

	thumb_func_start draw_status_ailment_maybe
draw_status_ailment_maybe: @ 80743F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gSprites
	mov r2, r9
	lsls r1, r2, 4
	add r1, r9
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x3A]
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r1, 0x38]
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08074468
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
	bl GetMonData
	adds r4, r0, 0
	bl IsDoubleBattle
	lsls r0, 24
	movs r3, 0x12
	mov r8, r3
	cmp r0, 0
	bne _08074484
	movs r0, 0x1A
	mov r8, r0
	b _08074484
	.pool
_08074468:
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
	bl GetMonData
	adds r4, r0, 0
	movs r1, 0x11
	mov r8, r1
_08074484:
	movs r0, 0x7
	ands r0, r4
	cmp r0, 0
	beq _080744AC
	movs r0, 0x1B
	adds r1, r7, 0
	bl sub_80746A8
	lsls r0, 24
	lsrs r0, 24
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r0, 0x2
	b _080745B8
	.pool
_080744AC:
	movs r0, 0x88
	ands r0, r4
	cmp r0, 0
	beq _080744CA
	movs r0, 0x15
	adds r1, r7, 0
	bl sub_80746A8
	lsls r0, 24
	lsrs r0, 24
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r0, 0
	b _080745B8
_080744CA:
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _080744E8
	movs r0, 0x21
	adds r1, r7, 0
	bl sub_80746A8
	lsls r0, 24
	lsrs r0, 24
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r0, 0x4
	b _080745B8
_080744E8:
	movs r0, 0x20
	ands r0, r4
	cmp r0, 0
	beq _08074506
	movs r0, 0x1E
	adds r1, r7, 0
	bl sub_80746A8
	lsls r0, 24
	lsrs r0, 24
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r0, 0x3
	b _080745B8
_08074506:
	movs r0, 0x40
	ands r0, r4
	cmp r0, 0
	beq _08074524
	movs r0, 0x18
	adds r1, r7, 0
	bl sub_80746A8
	lsls r0, 24
	lsrs r0, 24
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r0, 0x1
	b _080745B8
_08074524:
	movs r0, 0x27
	bl GetHealthboxElementGfxPtr
	adds r6, r0, 0
	movs r4, 0
	mov r2, r9
	lsls r0, r2, 4
	mov r3, r8
	lsls r3, 16
	mov r8, r3
	lsls r7, 2
	ldr r1, =gSprites
	add r0, r9
	lsls r0, 2
	adds r5, r0, r1
_08074542:
	ldrh r1, [r5, 0x4]
	lsls r1, 22
	lsrs r1, 22
	mov r2, r8
	asrs r0, r2, 16
	adds r1, r0
	adds r1, r4
	lsls r1, 5
	ldr r3, =0x06010000
	adds r1, r3
	adds r0, r6, 0
	ldr r2, =0x04000008
	bl CpuSet
	adds r4, 0x1
	cmp r4, 0x2
	ble _08074542
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, r7, r0
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08074598
	movs r0, 0x1
	bl GetHealthboxElementGfxPtr
	ldr r2, =gSprites
	mov r3, r10
	lsls r1, r3, 4
	add r1, r10
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000010
	bl CpuSet
_08074598:
	mov r0, r9
	movs r1, 0x1
	bl sub_8074310
	b _0807467A
	.pool
_080745B8:
	mov r1, r9
	lsls r5, r1, 4
	add r5, r9
	lsls r5, 2
	ldr r2, =gSprites
	adds r5, r2
	ldrb r4, [r5, 0x5]
	lsrs r4, 4
	lsls r4, 4
	adds r4, 0xC
	adds r4, r7
	ldr r1, =gUnknown_0832C3EC
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r4, r3
	movs r2, 0x2
	bl FillPalette
	lsls r4, 1
	ldr r0, =gPlttBufferUnfaded + 0x200
	adds r0, r4, r0
	ldr r1, =0x05000200
	adds r4, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl CpuSet
	ldrh r1, [r5, 0x4]
	lsls r1, 22
	lsrs r1, 22
	add r1, r8
	lsls r1, 5
	ldr r2, =0x06010000
	mov r8, r2
	add r1, r8
	ldr r2, =0x04000018
	adds r0, r6, 0
	bl CpuSet
	bl IsDoubleBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08074626
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08074672
_08074626:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08074672
	movs r0, 0
	bl GetHealthboxElementGfxPtr
	mov r3, r10
	lsls r4, r3, 4
	add r4, r10
	lsls r4, 2
	ldr r1, =gSprites
	adds r4, r1
	ldrh r1, [r4, 0x4]
	lsls r1, 22
	lsrs r1, 17
	add r1, r8
	ldr r5, =0x04000008
	adds r2, r5, 0
	bl CpuSet
	movs r0, 0x41
	bl GetHealthboxElementGfxPtr
	ldrh r1, [r4, 0x4]
	lsls r1, 22
	lsrs r1, 17
	adds r1, 0x20
	add r1, r8
	adds r2, r5, 0
	bl CpuSet
_08074672:
	mov r0, r9
	movs r1, 0
	bl sub_8074310
_0807467A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end draw_status_ailment_maybe

	thumb_func_start sub_80746A8
sub_80746A8: @ 80746A8
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsrs r2, r0, 24
	adds r0, r2, 0
	subs r0, 0x15
	cmp r0, 0xC
	bhi _08074768
	lsls r0, 2
	ldr r1, =_080746C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080746C8:
	.4byte _080746FC
	.4byte _08074768
	.4byte _08074768
	.4byte _08074712
	.4byte _08074768
	.4byte _08074768
	.4byte _08074728
	.4byte _08074768
	.4byte _08074768
	.4byte _0807473E
	.4byte _08074768
	.4byte _08074768
	.4byte _08074754
_080746FC:
	movs r2, 0x15
	cmp r3, 0
	beq _08074768
	movs r2, 0x47
	cmp r3, 0x1
	beq _08074768
	movs r2, 0x65
	cmp r3, 0x2
	bne _08074768
	movs r2, 0x56
	b _08074768
_08074712:
	movs r2, 0x18
	cmp r3, 0
	beq _08074768
	movs r2, 0x4A
	cmp r3, 0x1
	beq _08074768
	movs r2, 0x68
	cmp r3, 0x2
	bne _08074768
	movs r2, 0x59
	b _08074768
_08074728:
	movs r2, 0x1B
	cmp r3, 0
	beq _08074768
	movs r2, 0x4D
	cmp r3, 0x1
	beq _08074768
	movs r2, 0x6B
	cmp r3, 0x2
	bne _08074768
	movs r2, 0x5C
	b _08074768
_0807473E:
	movs r2, 0x1E
	cmp r3, 0
	beq _08074768
	movs r2, 0x50
	cmp r3, 0x1
	beq _08074768
	movs r2, 0x6E
	cmp r3, 0x2
	bne _08074768
	movs r2, 0x5F
	b _08074768
_08074754:
	movs r2, 0x21
	cmp r3, 0
	beq _08074768
	movs r2, 0x53
	cmp r3, 0x1
	beq _08074768
	movs r2, 0x71
	cmp r3, 0x2
	bne _08074768
	movs r2, 0x62
_08074768:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80746A8

	thumb_func_start sub_8074770
sub_8074770: @ 8074770
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gText_SafariBalls
	add r1, sp, 0x4
	str r1, [sp]
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x2
	bl AddTextPrinterAndCreateWindowOnHealthbox
	adds r5, r0, 0
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r4, [r0, 0x4]
	lsls r4, 22
	lsrs r4, 17
	ldr r1, =0x06010040
	adds r0, r4, r1
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_8075198
	ldr r0, =0x06010800
	adds r4, r0
	adds r5, 0xC0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_8075198
	ldr r0, [sp, 0x4]
	bl RemoveWindow_
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8074770

	thumb_func_start sub_80747D8
sub_80747D8: @ 80747D8
	push {r4,r5,lr}
	sub sp, 0x18
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gText_SafariBallLeft
	add r0, sp, 0x4
	bl StringCopy
	ldr r1, =gNumSafariBalls
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0
	add r1, sp, 0x4
	movs r2, 0x2F
	bl GetStringRightAlignXOffset
	adds r1, r0, 0
	add r0, sp, 0x14
	str r0, [sp]
	add r0, sp, 0x4
	movs r2, 0x3
	movs r3, 0x2
	bl AddTextPrinterAndCreateWindowOnHealthbox
	adds r5, r0, 0
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r4, [r0, 0x4]
	lsls r4, 22
	lsrs r4, 17
	ldr r1, =0x060102c0
	adds r0, r4, r1
	adds r1, r5, 0
	movs r2, 0x2
	bl sub_80751E4
	ldr r0, =0x06010a00
	adds r4, r0
	adds r5, 0x40
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x4
	bl sub_80751E4
	ldr r0, [sp, 0x14]
	bl RemoveWindow_
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80747D8

	thumb_func_start UpdateHealthboxAttribute
UpdateHealthboxAttribute: @ 8074860
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r1
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r1, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r7, 0
	bne _0807489C
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _0807489C
	mov r0, r9
	bl GetBankSide
_0807489C:
	ldr r1, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080748B8
	b _08074A18
_080748B8:
	cmp r7, 0x3
	beq _080748C0
	cmp r7, 0
	bne _080748D4
_080748C0:
	mov r0, r8
	movs r1, 0x38
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl UpdateLvlInHealthbox
_080748D4:
	cmp r7, 0x1
	bhi _080748EE
	mov r0, r8
	movs r1, 0x39
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r6, 0
	movs r2, 0
	bl UpdateHpTextInHealthbox
_080748EE:
	cmp r7, 0x2
	beq _080748F6
	cmp r7, 0
	bne _0807490C
_080748F6:
	mov r0, r8
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r6, 0
	movs r2, 0x1
	bl UpdateHpTextInHealthbox
_0807490C:
	cmp r7, 0x5
	beq _08074914
	cmp r7, 0
	bne _08074948
_08074914:
	movs r0, 0
	bl load_gfxc_health_bar
	mov r0, r8
	movs r1, 0x3A
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	mov r0, r9
	adds r1, r6, 0
	adds r2, r4, 0
	bl SetBattleBarStruct
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
_08074948:
	bl IsDoubleBattle
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0
	bne _080749CE
	cmp r7, 0x6
	beq _0807495E
	cmp r7, 0
	bne _080749CE
_0807495E:
	movs r0, 0x3
	bl load_gfxc_health_bar
	mov r0, r8
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	mov r0, r8
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	movs r1, 0x19
	bl GetMonData
	adds r3, r0, 0
	ldr r0, =gExperienceTables
	mov r12, r0
	lsls r1, r4, 2
	ldr r2, =gBaseStats
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r2
	adds r1, r0
	add r1, r12
	ldr r1, [r1]
	subs r3, r1
	adds r4, 0x1
	lsls r4, 2
	adds r4, r0
	add r4, r12
	ldr r2, [r4]
	subs r2, r1
	mov r0, r10
	str r0, [sp]
	mov r0, r9
	adds r1, r6, 0
	bl SetBattleBarStruct
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8074AA0
_080749CE:
	cmp r7, 0x4
	beq _080749D6
	cmp r7, 0
	bne _080749DE
_080749D6:
	adds r0, r6, 0
	mov r1, r8
	bl sub_80741E8
_080749DE:
	cmp r7, 0x9
	beq _080749E6
	cmp r7, 0
	bne _080749EC
_080749E6:
	adds r0, r6, 0
	bl draw_status_ailment_maybe
_080749EC:
	cmp r7, 0xA
	bne _080749F6
	adds r0, r6, 0
	bl sub_8074770
_080749F6:
	adds r0, r7, 0
	subs r0, 0xA
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08074A8E
	adds r0, r6, 0
	bl sub_80747D8
	b _08074A8E
	.pool
_08074A18:
	cmp r7, 0x3
	beq _08074A20
	cmp r7, 0
	bne _08074A34
_08074A20:
	mov r0, r8
	movs r1, 0x38
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl UpdateLvlInHealthbox
_08074A34:
	cmp r7, 0x5
	beq _08074A3C
	cmp r7, 0
	bne _08074A70
_08074A3C:
	movs r0, 0
	bl load_gfxc_health_bar
	mov r0, r8
	movs r1, 0x3A
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	mov r0, r9
	adds r1, r6, 0
	adds r2, r4, 0
	bl SetBattleBarStruct
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
_08074A70:
	cmp r7, 0x4
	beq _08074A78
	cmp r7, 0
	bne _08074A80
_08074A78:
	adds r0, r6, 0
	mov r1, r8
	bl sub_80741E8
_08074A80:
	cmp r7, 0x9
	beq _08074A88
	cmp r7, 0
	bne _08074A8E
_08074A88:
	adds r0, r6, 0
	bl draw_status_ailment_maybe
_08074A8E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end UpdateHealthboxAttribute

	thumb_func_start sub_8074AA0
sub_8074AA0: @ 8074AA0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	cmp r2, 0
	bne _08074AEC
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	mov r1, r8
	lsls r5, r1, 2
	adds r3, r5, r1
	lsls r3, 2
	adds r3, r0
	ldr r0, [r3, 0x4]
	ldr r1, [r3, 0x8]
	ldr r2, [r3, 0xC]
	adds r3, 0x10
	movs r4, 0x6
	str r4, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	bl sub_8074DB8
	adds r4, r0, 0
	adds r7, r5, 0
	b _08074B48
	.pool
_08074AEC:
	ldr r2, =gBattleSpritesDataPtr
	mov r10, r2
	ldr r0, [r2]
	ldr r2, [r0, 0xC]
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r6, r0, 2
	adds r2, r6, r2
	ldr r0, [r2, 0x8]
	ldr r1, [r2, 0xC]
	ldr r2, [r2, 0x4]
	movs r3, 0x8
	bl sub_8074FE8
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r4, 0
	cmp r5, 0
	bne _08074B16
	movs r5, 0x1
_08074B16:
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0, 0xC]
	adds r4, r6, r0
	ldr r6, [r4, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	bl __divsi3
	cmp r0, 0
	bge _08074B2E
	negs r0, r0
_08074B2E:
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [r4, 0x4]
	ldr r1, [r4, 0x8]
	adds r3, r4, 0
	adds r3, 0x10
	movs r2, 0x8
	str r2, [sp]
	str r5, [sp, 0x4]
	adds r2, r6, 0
	bl sub_8074DB8
	adds r4, r0, 0
_08074B48:
	mov r2, r9
	cmp r2, 0x1
	beq _08074B64
	cmp r2, 0
	bne _08074B6C
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, r7, r0
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08074B6C
_08074B64:
	mov r0, r8
	mov r1, r9
	bl sub_8074B9C
_08074B6C:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _08074B86
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	mov r2, r8
	adds r0, r7, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	str r1, [r0, 0x10]
_08074B86:
	adds r0, r4, 0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8074AA0

	thumb_func_start sub_8074B9C
sub_8074B9C: @ 8074B9C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	beq _08074BB8
	cmp r1, 0x1
	beq _08074CA0
	b _08074D9E
_08074BB8:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	lsls r5, r6, 2
	adds r3, r5, r6
	lsls r3, 2
	adds r3, r0
	ldr r0, [r3, 0x4]
	ldr r1, [r3, 0x8]
	ldr r2, [r3, 0xC]
	adds r3, 0x10
	add r4, sp, 0x8
	str r4, [sp]
	movs r4, 0x6
	str r4, [sp, 0x4]
	bl sub_8074E8C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	mov r9, r1
	adds r7, r5, 0
	cmp r0, 0x18
	bhi _08074BF4
	movs r2, 0x38
	mov r9, r2
	cmp r0, 0x9
	bls _08074BF4
	movs r4, 0x2F
	mov r9, r4
_08074BF4:
	movs r5, 0
	ldr r0, =gSprites
	mov r8, r0
_08074BFA:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	adds r0, r7, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrh r0, [r0, 0x38]
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r5, 0x1
	bhi _08074C5C
	mov r0, r9
	bl GetHealthboxElementGfxPtr
	mov r1, sp
	adds r1, r5
	adds r1, 0x8
	ldrb r1, [r1]
	lsls r1, 5
	adds r0, r1
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	add r1, r8
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r2, r5, 0x2
	adds r1, r2
	lsls r1, 5
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _08074C8A
	.pool
_08074C5C:
	mov r0, r9
	bl GetHealthboxElementGfxPtr
	mov r1, sp
	adds r1, r5
	adds r1, 0x8
	ldrb r1, [r1]
	lsls r1, 5
	adds r0, r1
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	add r1, r8
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r1, r5, r1
	lsls r1, 5
	ldr r4, =0x06010040
	adds r1, r4
	ldr r2, =0x04000008
	bl CpuSet
_08074C8A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08074BFA
	b _08074D9E
	.pool
_08074CA0:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	lsls r5, r6, 2
	adds r3, r5, r6
	lsls r3, 2
	adds r3, r0
	ldr r0, [r3, 0x4]
	ldr r1, [r3, 0x8]
	ldr r2, [r3, 0xC]
	adds r3, 0x10
	add r4, sp, 0x8
	str r4, [sp]
	movs r4, 0x8
	str r4, [sp, 0x4]
	bl sub_8074E8C
	ldr r1, =gBattlePartyID
	lsls r0, r6, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	adds r7, r5, 0
	cmp r0, 0x64
	bne _08074CF8
	movs r5, 0
	movs r1, 0
_08074CE6:
	mov r0, sp
	adds r0, r5
	adds r0, 0x8
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _08074CE6
_08074CF8:
	movs r5, 0
	ldr r0, =gSprites
	mov r8, r0
	adds r0, r7, r6
	lsls r4, r0, 2
_08074D02:
	cmp r5, 0x3
	bhi _08074D5C
	movs r0, 0xC
	bl GetHealthboxElementGfxPtr
	mov r1, sp
	adds r1, r5
	adds r1, 0x8
	ldrb r1, [r1]
	lsls r1, 5
	adds r0, r1
	ldr r1, =gBattleSpritesDataPtr
	ldr r1, [r1]
	ldr r1, [r1, 0xC]
	adds r1, r4, r1
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r2, r5, 0
	adds r2, 0x24
	adds r1, r2
	lsls r1, 5
	ldr r2, =0x06010000
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _08074D94
	.pool
_08074D5C:
	movs r0, 0xC
	bl GetHealthboxElementGfxPtr
	mov r1, sp
	adds r1, r5
	adds r1, 0x8
	ldrb r1, [r1]
	lsls r1, 5
	adds r0, r1
	ldr r1, =gBattleSpritesDataPtr
	ldr r1, [r1]
	ldr r1, [r1, 0xC]
	adds r1, r4, r1
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r1, r5, r1
	lsls r1, 5
	ldr r2, =0x06010b80
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_08074D94:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x7
	bls _08074D02
_08074D9E:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8074B9C

	thumb_func_start sub_8074DB8
sub_8074DB8: @ 8074DB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r4, r1, 0
	mov r8, r2
	adds r5, r3, 0
	ldr r1, [sp, 0x18]
	ldr r0, [sp, 0x1C]
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 27
	lsrs r2, r1, 24
	ldr r1, [r5]
	ldr r0, =0xffff8000
	cmp r1, r0
	bne _08074DEA
	cmp r7, r2
	bge _08074DE8
	lsls r0, r4, 8
	str r0, [r5]
	b _08074DEA
	.pool
_08074DE8:
	str r4, [r5]
_08074DEA:
	mov r0, r8
	subs r4, r0
	cmp r4, 0
	bge _08074DF6
	movs r4, 0
	b _08074DFC
_08074DF6:
	cmp r4, r7
	ble _08074DFC
	adds r4, r7, 0
_08074DFC:
	cmp r7, r2
	bge _08074E18
	ldr r0, [r5]
	asrs r1, r0, 8
	adds r6, r0, 0
	cmp r4, r1
	bne _08074E24
	movs r0, 0xFF
	ands r0, r6
	cmp r0, 0
	bne _08074E24
	movs r0, 0x1
	negs r0, r0
	b _08074E80
_08074E18:
	ldr r6, [r5]
	cmp r4, r6
	bne _08074E24
	movs r0, 0x1
	negs r0, r0
	b _08074E80
_08074E24:
	cmp r7, r2
	bge _08074E5E
	lsls r0, r7, 8
	adds r1, r2, 0
	bl __divsi3
	mov r1, r8
	cmp r1, 0
	bge _08074E42
	adds r0, r6, r0
	str r0, [r5]
	asrs r2, r0, 8
	cmp r2, r4
	blt _08074E7E
	b _08074E56
_08074E42:
	subs r0, r6, r0
	str r0, [r5]
	asrs r2, r0, 8
	movs r1, 0xFF
	ands r0, r1
	cmp r0, 0
	ble _08074E52
	adds r2, 0x1
_08074E52:
	cmp r2, r4
	bgt _08074E7E
_08074E56:
	lsls r0, r4, 8
	str r0, [r5]
	adds r2, r4, 0
	b _08074E7E
_08074E5E:
	mov r0, r8
	cmp r0, 0
	bge _08074E70
	ldr r0, [r5]
	adds r0, r3
	str r0, [r5]
	cmp r0, r4
	ble _08074E7C
	b _08074E7A
_08074E70:
	ldr r0, [r5]
	subs r0, r3
	str r0, [r5]
	cmp r0, r4
	bge _08074E7C
_08074E7A:
	str r4, [r5]
_08074E7C:
	ldr r2, [r5]
_08074E7E:
	adds r0, r2, 0
_08074E80:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8074DB8

	thumb_func_start sub_8074E8C
sub_8074E8C: @ 8074E8C
	push {r4-r7,lr}
	adds r4, r0, 0
	mov r12, r3
	ldr r7, [sp, 0x14]
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r6, r0, 24
	subs r5, r1, r2
	cmp r5, 0
	bge _08074EA4
	movs r5, 0
	b _08074EAA
_08074EA4:
	cmp r5, r4
	ble _08074EAA
	adds r5, r4, 0
_08074EAA:
	lsls r0, r6, 27
	lsrs r3, r0, 24
	movs r1, 0
	cmp r1, r6
	bcs _08074EC4
	movs r2, 0
_08074EB6:
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r6
	bcc _08074EB6
_08074EC4:
	cmp r4, r3
	bge _08074ED8
	mov r1, r12
	ldr r0, [r1]
	muls r0, r3
	adds r1, r4, 0
	bl __divsi3
	asrs r0, 8
	b _08074EE4
_08074ED8:
	mov r1, r12
	ldr r0, [r1]
	muls r0, r3
	adds r1, r4, 0
	bl __divsi3
_08074EE4:
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	cmp r3, 0
	bne _08074EFA
	cmp r5, 0
	ble _08074EFA
	movs r0, 0x1
	strb r0, [r7]
	movs r3, 0x1
	b _08074F1E
_08074EFA:
	movs r1, 0
	movs r4, 0x8
_08074EFE:
	cmp r1, r6
	bcs _08074F1E
	cmp r2, 0x7
	bls _08074F1A
	adds r0, r7, r1
	strb r4, [r0]
	adds r0, r2, 0
	subs r0, 0x8
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	b _08074EFE
_08074F1A:
	adds r0, r7, r1
	strb r2, [r0]
_08074F1E:
	adds r0, r3, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8074E8C

	thumb_func_start sub_8074F28
sub_8074F28: @ 8074F28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	movs r3, 0x6
	str r3, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	adds r3, r6, 0
	bl sub_8074DB8
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_8074F88
	ldr r0, [r5]
	cmp r0, 0x2F
	bgt _08074F68
	ldr r0, [r6]
	lsls r0, 8
	lsrs r1, r0, 16
	b _08074F6A
_08074F68:
	ldrh r1, [r6]
_08074F6A:
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r1, 16
	asrs r1, 16
	mov r2, r8
	bl sub_8072304
	lsls r0, r7, 16
	asrs r0, 16
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8074F28

	thumb_func_start sub_8074F88
sub_8074F88: @ 8074F88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x1C
	adds r5, r0, 0
	adds r3, r1, 0
	mov r8, r2
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	add r4, sp, 0x8
	str r4, [sp]
	movs r4, 0x6
	str r4, [sp, 0x4]
	bl sub_8074E8C
	movs r3, 0
	add r7, sp, 0x10
	mov r12, r7
	ldrb r0, [r5, 0xC]
	lsls r6, r0, 27
	ldr r4, [r5, 0x10]
_08074FB4:
	lsls r2, r3, 1
	add r2, r12
	lsrs r1, r6, 15
	mov r0, sp
	adds r0, r3
	adds r0, 0x8
	ldrb r0, [r0]
	adds r0, r4, r0
	orrs r1, r0
	strh r1, [r2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x5
	bls _08074FB4
	adds r0, r7, 0
	mov r1, r8
	movs r2, 0x6
	bl CpuSet
	add sp, 0x1C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8074F88

	thumb_func_start sub_8074FE8
sub_8074FE8: @ 8074FE8
	push {r4-r7,lr}
	adds r6, r2, 0
	lsls r3, 27
	lsrs r7, r3, 24
	subs r5, r0, r1
	cmp r5, 0
	bge _08074FFA
	movs r5, 0
	b _08075000
_08074FFA:
	cmp r5, r6
	ble _08075000
	adds r5, r6, 0
_08075000:
	muls r0, r7
	adds r1, r6, 0
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	muls r0, r7
	adds r1, r6, 0
	bl __divsi3
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	subs r0, r4, r0
	cmp r0, 0
	bge _08075028
	negs r0, r0
_08075028:
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8074FE8

	thumb_func_start GetScaledHPFraction
GetScaledHPFraction: @ 8075034
	push {r4,lr}
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	muls r0, r2
	lsls r1, 16
	asrs r1, 16
	bl __divsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08075058
	cmp r4, 0
	ble _08075058
	movs r0, 0x1
_08075058:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetScaledHPFraction

	thumb_func_start sub_8075060
sub_8075060: @ 8075060
	push {lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bne _08075072
	movs r0, 0x4
	b _0807508E
_08075072:
	movs r2, 0x30
	bl GetScaledHPFraction
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x3
	cmp r1, 0x18
	bhi _0807508E
	movs r0, 0x2
	cmp r1, 0x9
	bhi _0807508E
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_0807508E:
	pop {r1}
	bx r1
	thumb_func_end sub_8075060

	thumb_func_start AddTextPrinterAndCreateWindowOnHealthbox
AddTextPrinterAndCreateWindowOnHealthbox: @ 8075094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r10, r0
	mov r8, r1
	mov r9, r2
	adds r5, r3, 0
	ldr r7, [sp, 0x40]
	ldr r0, =gUnknown_0832C3F8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	add r0, sp, 0x18
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r6, r4, 24
	lsrs r6, 24
	lsls r1, r5, 4
	orrs r1, r5
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl FillWindowPixelBuffer
	add r0, sp, 0x14
	movs r2, 0
	strb r5, [r0]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	str r2, [sp]
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	mov r0, r10
	str r0, [sp, 0x10]
	adds r0, r6, 0
	movs r1, 0
	mov r2, r8
	mov r3, r9
	bl AddTextPrinterParametrized2
	str r4, [r7]
	adds r0, r6, 0
	movs r1, 0x7
	bl GetWindowAttribute
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddTextPrinterAndCreateWindowOnHealthbox

	thumb_func_start RemoveWindow_
RemoveWindow_: @ 807512C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	pop {r0}
	bx r0
	thumb_func_end RemoveWindow_

	thumb_func_start sub_807513C
sub_807513C: @ 807513C
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r1, r0, 8
	adds r0, r1
	lsls r1, r0, 16
	adds r0, r1
	str r0, [sp]
	lsls r2, 3
	ldr r0, =0x001fffff
	ands r2, r0
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807513C

	thumb_func_start sub_8075170
sub_8075170: @ 8075170
	push {lr}
	adds r3, r0, 0
	adds r0, r1, 0
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	lsls r2, 3
	ldr r1, =0x001fffff
	ands r2, r1
	movs r1, 0x80
	lsls r1, 19
	orrs r2, r1
	adds r1, r3, 0
	bl CpuSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075170

	thumb_func_start sub_8075198
sub_8075198: @ 8075198
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r1, 0x80
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r6, r1
	lsls r2, r4, 3
	ldr r3, =0x001fffff
	ands r2, r3
	movs r3, 0x80
	lsls r3, 19
	orrs r2, r3
	bl CpuSet
	cmp r4, 0
	ble _080751D4
_080751BC:
	adds r0, r5, 0
	adds r0, 0x14
	adds r1, r6, 0
	adds r1, 0x14
	ldr r2, =0x04000003
	bl CpuSet
	adds r6, 0x20
	adds r5, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _080751BC
_080751D4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8075198

	thumb_func_start sub_80751E4
sub_80751E4: @ 80751E4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 3
	ldr r0, =0x001fffff
	ands r4, r0
	movs r0, 0x80
	lsls r0, 19
	orrs r4, r0
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl CpuSet
	movs r0, 0x80
	lsls r0, 1
	adds r5, r0
	adds r6, r0
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl CpuSet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80751E4

	.align 2, 0 @ Don't pad with nop.
