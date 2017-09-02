	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_35
nullsub_35: @ 80A92F4
	bx lr
	thumb_func_end nullsub_35

	thumb_func_start sub_80A92F8
sub_80A92F8: @ 80A92F8
	push {lr}
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x8]
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gBattleScripting
	adds r2, r0, 0
	adds r2, 0x21
	movs r1, 0
	strb r1, [r2]
	adds r0, 0x22
	strb r1, [r0]
	ldr r0, =c2_80777E8
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A92F8

	thumb_func_start c2_80777E8
c2_80777E8: @ 80A933C
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r0, =gBattleScripting
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x13
	bls _080A934C
	b _080A95A4
_080A934C:
	lsls r0, 2
	ldr r1, =_080A9360
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080A9360:
	.4byte _080A93B0
	.4byte _080A942C
	.4byte _080A9444
	.4byte _080A944A
	.4byte _080A9450
	.4byte _080A9460
	.4byte _080A9466
	.4byte _080A948E
	.4byte _080A9492
	.4byte _080A9496
	.4byte _080A949A
	.4byte _080A94B8
	.4byte _080A94C0
	.4byte _080A94C8
	.4byte _080A94D0
	.4byte _080A94D8
	.4byte _080A94E0
	.4byte _080A94E8
	.4byte _080A94F0
	.4byte _080A94F8
_080A93B0:
	bl dp12_8087EA4
	bl trs_config
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	bl ResetPaletteFade
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r0, =gUnknown_02022E18
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1C
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r1, [r0]
	ldr r0, =gUnknown_02022E20
	strh r1, [r0]
	ldr r0, =gUnknown_02022E22
	strh r1, [r0]
	b _080A95D2
	.pool
_080A942C:
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x01006000
	add r0, sp, 0x4
	bl CpuFastSet
	b _080A95D2
	.pool
_080A9444:
	bl sub_8035AA4
	b _080A95D2
_080A944A:
	bl ResetSpriteData
	b _080A95D2
_080A9450:
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x4
	strb r0, [r1]
	b _080A95D2
	.pool
_080A9460:
	bl sub_805E350
	b _080A95D2
_080A9466:
	ldr r5, =gBattleScripting
	adds r4, r5, 0
	adds r4, 0x22
	ldrb r0, [r4]
	bl sub_805E08C
	lsls r0, 24
	cmp r0, 0
	beq _080A9484
	movs r0, 0
	strb r0, [r4]
	b _080A95D2
	.pool
_080A9484:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r1, r5, 0
	b _080A94AA
_080A948E:
	movs r0, 0
	b _080A949C
_080A9492:
	movs r0, 0x1
	b _080A949C
_080A9496:
	movs r0, 0x2
	b _080A949C
_080A949A:
	movs r0, 0x3
_080A949C:
	bl sub_80A9614
	lsls r0, 24
	cmp r0, 0
	beq _080A94A8
	b _080A95D2
_080A94A8:
	ldr r1, =gBattleScripting
_080A94AA:
	adds r1, 0x21
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	b _080A95D2
	.pool
_080A94B8:
	movs r0, 0
	bl sub_80A9708
	b _080A95D2
_080A94C0:
	movs r0, 0x1
	bl sub_80A9708
	b _080A95D2
_080A94C8:
	movs r0, 0x2
	bl sub_80A9708
	b _080A95D2
_080A94D0:
	movs r0, 0x3
	bl sub_80A9708
	b _080A95D2
_080A94D8:
	movs r0, 0
	bl sub_80A9ADC
	b _080A95D2
_080A94E0:
	movs r0, 0x1
	bl sub_80A9ADC
	b _080A95D2
_080A94E8:
	movs r0, 0x2
	bl sub_80A9ADC
	b _080A95D2
_080A94F0:
	movs r0, 0x3
	bl sub_80A9ADC
	b _080A95D2
_080A94F8:
	bl sub_805EC84
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r7, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080A955C
	movs r0, 0x3
	bl GetBankByPlayerAI
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
_080A955C:
	ldr r1, =gUnknown_020244AC
	ldr r0, =gUnknown_020244B8
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A95D2
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A95D2
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl sub_800DFB4
	b _080A95D2
	.pool
_080A95A4:
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	bl sub_80A95F4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginHardwarePaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	ldr r0, =sub_8038420
	bl SetMainCallback2
	bl sub_805EF14
_080A95D2:
	ldr r1, =gBattleScripting
	adds r1, 0x21
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_80777E8

	thumb_func_start sub_80A95F4
sub_80A95F4: @ 80A95F4
	ldr r3, =0x0400000a
	ldrb r2, [r3]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	ldr r2, =0x0400000c
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_80A95F4

	thumb_func_start sub_80A9614
sub_80A9614: @ 80A9614
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bcs _080A96FC
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080A9676
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A966C
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DC0C
	b _080A96F4
	.pool
_080A966C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_805E7DC
	b _080A96F4
_080A9676:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A9698
	cmp r4, 0
	bne _080A9698
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	b _080A96AA
	.pool
_080A9698:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A96B2
	cmp r4, 0
	bne _080A96B2
	movs r0, 0x6
_080A96AA:
	movs r1, 0
	bl sub_805DF84
	b _080A96F4
_080A96B2:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A96EC
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DD7C
	b _080A96F4
	.pool
_080A96EC:
	adds r0, r4, 0
	movs r1, 0
	bl sub_805E7DC
_080A96F4:
	ldr r0, =gBattleScripting
	adds r0, 0x22
	movs r1, 0
	strb r1, [r0]
_080A96FC:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A9614

	thumb_func_start sub_80A9708
sub_80A9708: @ 80A9708
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r7, r0
	bcc _080A9722
	b _080A9AA0
_080A9722:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r2, r7, 2
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	str r2, [sp]
	cmp r0, 0
	beq _080A9748
	adds r0, r7, 0
	bl sub_80A614C
	b _080A974E
	.pool
_080A9748:
	adds r0, r7, 0
	bl sub_80A6138
_080A974E:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080A9762
	b _080A986C
_080A9762:
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r6, r0, r1
	ldrh r0, [r6]
	movs r1, 0x64
	mov r10, r1
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	ldr r1, =gEnemyParty
	mov r9, r1
	add r0, r9
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080A9786
	b _080A9AA0
_080A9786:
	ldrh r0, [r6]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r5, =gUnknown_0202499C
	adds r0, r7, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl CreateSprite
	ldr r1, =gBankSpriteIds
	adds r4, r7, r1
	strb r0, [r4]
	ldr r5, =gSprites
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r7, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x2E]
	ldrh r0, [r6]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	strh r0, [r1, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartSpriteAnim
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r2, [sp]
	adds r0, r2, r0
	b _080A9A50
	.pool
_080A986C:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A98D0
	cmp r7, 0
	bne _080A98D0
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldrb r4, [r0, 0x8]
	movs r0, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 15
	adds r4, r0
	asrs r4, 16
	movs r0, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	b _080A9914
	.pool
_080A98D0:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A9968
	cmp r7, 0
	bne _080A9968
	movs r0, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x6
	bl template_build_for_pokemon_or_trainer
	ldr r5, =gUnknown_0202499C
	ldr r0, =gUnknown_08305D2C
	ldrb r0, [r0, 0x18]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r4, r1
	asrs r4, 16
	movs r0, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
_080A9914:
	movs r1, 0x50
	adds r2, r4, 0
	bl CreateSprite
	ldr r3, =gBankSpriteIds
	strb r0, [r3]
	ldr r4, =gSprites
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r7, [r0, 0x2E]
	b _080A9A70
	.pool
_080A9968:
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r6, r0, r1
	ldrh r0, [r6]
	movs r2, 0x64
	mov r10, r2
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	ldr r2, =gPlayerParty
	mov r9, r2
	add r0, r9
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080A998C
	b _080A9AA0
_080A998C:
	ldrh r0, [r6]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r5, =gUnknown_0202499C
	adds r0, r7, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl CreateSprite
	ldr r1, =gBankSpriteIds
	adds r4, r7, r1
	strb r0, [r4]
	ldr r5, =gSprites
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r7, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x2E]
	ldrh r0, [r6]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	ldrb r2, [r4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	strh r0, [r1, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartSpriteAnim
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r1, r0
_080A9A50:
	ldrh r1, [r0, 0x2]
	ldr r0, =0x00000181
	cmp r1, r0
	bne _080A9A70
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r1, r0
	ldr r0, =gUnknown_08309AAC
	ldr r2, =0x00000604
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
_080A9A70:
	ldr r1, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r1, r0
	ldr r1, [r0]
	lsls r1, 31
	adds r2, 0x3E
	lsrs r1, 31
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_080A9AA0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9708

	thumb_func_start sub_80A9ADC
sub_80A9ADC: @ 80A9ADC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bcc _080A9AEC
	b _080A9C5E
_080A9AEC:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x80
	ands r1, r2
	cmp r1, 0
	beq _080A9B0C
	cmp r5, 0
	bne _080A9B0C
	bl battle_make_oam_safari_battle
	b _080A9B24
	.pool
_080A9B0C:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080A9B1E
	cmp r5, 0
	bne _080A9B1E
	b _080A9C5E
_080A9B1E:
	adds r0, r5, 0
	bl battle_make_oam_normal_battle
_080A9B24:
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_03005D70
	adds r4, r5, r0
	strb r6, [r4]
	adds r0, r5, 0
	bl sub_8072B18
	adds r0, r6, 0
	bl sub_80729D0
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080A9B6C
	ldrb r0, [r4]
	ldr r1, =gBattlePartyID
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _080A9BB8
	.pool
_080A9B6C:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080A9BA0
	ldrb r0, [r4]
	ldr r1, =gBattlePartyID
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0xA
	bl healthbar_draw_field_maybe
	b _080A9BB8
	.pool
_080A9BA0:
	ldrb r0, [r4]
	ldr r1, =gBattlePartyID
	lsls r4, r5, 1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_080A9BB8:
	adds r0, r5, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _080A9BD4
	adds r0, r5, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080A9BF0
_080A9BD4:
	ldr r0, =gUnknown_03005D70
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x1
	bl nullsub_30
	b _080A9BFC
	.pool
_080A9BF0:
	ldr r0, =gUnknown_03005D70
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0
	bl nullsub_30
_080A9BFC:
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080A9C34
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080A9C5E
	adds r0, r6, 0
	bl sub_8072984
	b _080A9C5E
	.pool
_080A9C34:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080A9C5E
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080A9C5E
	adds r0, r6, 0
	bl sub_8072984
_080A9C5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A9ADC

	.align 2, 0 @ Don't pad with nop.
