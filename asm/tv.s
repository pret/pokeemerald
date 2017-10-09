	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	thumb_func_start DoTVShowPokemonAngler
DoTVShowPokemonAngler: @ 80F3828
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r0, =gScriptResult
	movs r1, 0
	strh r1, [r0]
	ldrb r0, [r4, 0x2]
	ldrb r2, [r4, 0x3]
	cmp r0, r2
	bcs _080F3868
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F3870
	.pool
_080F3868:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r1, 0
_080F3870:
	ldrb r5, [r0]
	cmp r5, 0
	beq _080F3880
	cmp r5, 0x1
	beq _080F38B8
	b _080F38E0
	.pool
_080F3880:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x6]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r4, 0x3]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	bl TVShowDone
	b _080F38E0
	.pool
_080F38B8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x6]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	bl TVShowDone
_080F38E0:
	ldr r0, =gUnknown_0858D3B0
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonAngler

	thumb_func_start DoTVShowTheWorldOfMasters
DoTVShowTheWorldOfMasters: @ 80F3904
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r6, =sTVShowState
	ldrb r5, [r6]
	cmp r5, 0x1
	beq _080F3974
	cmp r5, 0x1
	bgt _080F3948
	cmp r5, 0
	beq _080F394E
	b _080F39BE
	.pool
_080F3948:
	cmp r5, 0x2
	beq _080F3994
	b _080F39BE
_080F394E:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xB]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x6]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldrh r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	movs r0, 0x1
	strb r0, [r6]
	b _080F39BE
	.pool
_080F3974:
	ldr r0, =gStringVar1
	ldrh r2, [r4, 0x8]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	movs r0, 0x2
	strb r0, [r6]
	b _080F39BE
	.pool
_080F3994:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xB]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r4, 0xA]
	movs r2, 0
	bl GetMapName
	ldr r0, =gStringVar3
	ldrh r2, [r4, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	bl TVShowDone
_080F39BE:
	ldr r0, =gUnknown_0858D3B8
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTheWorldOfMasters

	thumb_func_start DoTVShowTodaysRivalTrainer
DoTVShowTodaysRivalTrainer: @ 80F39E4
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xA
	bls _080F3A0C
	b _080F3BE8
_080F3A0C:
	lsls r0, r5, 2
	ldr r1, =_080F3A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3A30:
	.4byte _080F3A5C
	.4byte _080F3B30
	.4byte _080F3B58
	.4byte _080F3B90
	.4byte _080F3BA2
	.4byte _080F3BC4
	.4byte _080F3BD8
	.4byte _080F3A92
	.4byte _080F3AC0
	.4byte _080F3ADC
	.4byte _080F3AF8
_080F3A5C:
	ldrb r0, [r4, 0x7]
	cmp r0, 0x56
	beq _080F3A6C
	cmp r0, 0x57
	beq _080F3A72
	movs r0, 0x7
	strb r0, [r2]
	b _080F3BE8
_080F3A6C:
	movs r0, 0x8
	strb r0, [r2]
	b _080F3BE8
_080F3A72:
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00000117
	cmp r1, r0
	bgt _080F3A8C
	subs r0, 0x2
	cmp r1, r0
	blt _080F3A8C
	movs r0, 0xA
	strb r0, [r2]
	b _080F3BE8
	.pool
_080F3A8C:
	movs r0, 0x9
	strb r0, [r2]
	b _080F3BE8
_080F3A92:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r0, =gStringVar3
	ldrb r1, [r4, 0x7]
	movs r2, 0
	bl GetMapName
_080F3AB0:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _080F3B12
	b _080F3B24
	.pool
_080F3AC0:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	b _080F3AB0
	.pool
_080F3ADC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	b _080F3AB0
	.pool
_080F3AF8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _080F3B24
_080F3B12:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B24:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B30:
	ldrb r1, [r4, 0x4]
	movs r0, 0
	bl TV_PrintIntToStringVar
	ldr r0, =0x000008a8
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080F3BCC
	ldr r0, [r4, 0x4]
	ldr r1, =0x00ffff00
	ands r0, r1
	cmp r0, 0
	bne _080F3B6E
	b _080F3B84
	.pool
_080F3B58:
	ldr r0, =0x000008a8
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080F3BCC
	ldr r0, [r4, 0x4]
	ldr r1, =0x00ffff00
	ands r0, r1
	cmp r0, 0
	beq _080F3B84
_080F3B6E:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B84:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3B90:
	ldrh r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3B9C
	movs r0, 0x6
	strb r0, [r2]
	b _080F3BE8
_080F3B9C:
	movs r0, 0x5
	strb r0, [r2]
	b _080F3BE8
_080F3BA2:
	ldrb r1, [r4, 0x6]
	movs r0, 0
	bl TV_PrintIntToStringVar
	ldrb r1, [r4, 0x5]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldrh r0, [r4, 0x8]
	cmp r0, 0
	beq _080F3BCC
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3BC4:
	ldrh r1, [r4, 0x8]
	movs r0, 0
	bl TV_PrintIntToStringVar
_080F3BCC:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F3BE8
	.pool
_080F3BD8:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xC]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F3BE8:
	ldr r0, =gUnknown_0858D3C4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTodaysRivalTrainer

	thumb_func_start DoTVShowDewfordTrendWatcherNetwork
DoTVShowDewfordTrendWatcherNetwork: @ 80F3C04
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x6
	bls _080F3C2A
	b _080F3D54
_080F3C2A:
	lsls r0, r5, 2
	ldr r1, =_080F3C4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F3C4C:
	.4byte _080F3C68
	.4byte _080F3CA0
	.4byte _080F3CA0
	.4byte _080F3CD4
	.4byte _080F3D0C
	.4byte _080F3D0C
	.4byte _080F3D40
_080F3C68:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3C94
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3C94:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3CA0:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x9]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3CD4:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _080F3D00
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D00:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D0C:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x9]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F3D54
	.pool
_080F3D40:
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F3D54:
	ldr r0, =gUnknown_0858D3F0
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowDewfordTrendWatcherNetwork

	thumb_func_start DoTVShowHoennTreasureInvestigators
DoTVShowHoennTreasureInvestigators: @ 80F3D74
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r7, =sTVShowState
	ldrb r6, [r7]
	cmp r6, 0x1
	beq _080F3E02
	cmp r6, 0x1
	bgt _080F3DB8
	cmp r6, 0
	beq _080F3DBE
	b _080F3E5C
	.pool
_080F3DB8:
	cmp r6, 0x2
	beq _080F3E3C
	b _080F3E5C
_080F3DBE:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r0, [r5, 0x4]
	cmp r0, 0x57
	bne _080F3DFC
	ldrh r1, [r5, 0x6]
	ldr r0, =0x00000117
	cmp r1, r0
	bgt _080F3DF0
	subs r0, 0x2
	cmp r1, r0
	blt _080F3DF0
	movs r0, 0x2
	strb r0, [r7]
	b _080F3E5C
	.pool
_080F3DF0:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F3E5C
	.pool
_080F3DFC:
	movs r0, 0x1
	strb r0, [r7]
	b _080F3E5C
_080F3E02:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrb r1, [r5, 0x4]
	movs r2, 0
	bl GetMapName
	bl TVShowDone
	b _080F3E5C
	.pool
_080F3E3C:
	ldr r4, =gStringVar1
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F3E5C:
	ldr r0, =gUnknown_0858D40C
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowHoennTreasureInvestigators

	thumb_func_start DoTVShowFindThatGamer
DoTVShowFindThatGamer: @ 80F3E7C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x1
	beq _080F3F28
	cmp r5, 0x1
	bgt _080F3EC0
	cmp r5, 0
	beq _080F3ECC
	b _080F4008
	.pool
_080F3EC0:
	cmp r5, 0x2
	beq _080F3F78
	cmp r5, 0x3
	bne _080F3ECA
	b _080F3FCC
_080F3ECA:
	b _080F4008
_080F3ECC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3EE8
	cmp r0, 0x1
	beq _080F3EFC
	b _080F3F04
	.pool
_080F3EE8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3F04
	.pool
_080F3EFC:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3F04:
	ldrb r1, [r4, 0x2]
	cmp r1, 0x1
	bne _080F3F1C
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F4008
	.pool
_080F3F1C:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4008
	.pool
_080F3F28:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3F44
	cmp r0, 0x1
	beq _080F3F58
	b _080F3F60
	.pool
_080F3F44:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3F60
	.pool
_080F3F58:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3F60:
	ldrh r1, [r4, 0x4]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	bl TVShowDone
	b _080F4008
	.pool
_080F3F78:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F3F94
	cmp r0, 0x1
	beq _080F3FA8
	b _080F3FB0
	.pool
_080F3F94:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
	b _080F3FB0
	.pool
_080F3FA8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
_080F3FB0:
	ldrh r1, [r4, 0x4]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4008
	.pool
_080F3FCC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x3]
	cmp r1, 0
	beq _080F3FE8
	cmp r1, 0x1
	beq _080F3FFC
	b _080F4004
	.pool
_080F3FE8:
	ldr r0, =gStringVar2
	ldr r1, =gText_Roulette
	bl StringCopy
	b _080F4004
	.pool
_080F3FFC:
	ldr r0, =gStringVar2
	ldr r1, =gText_Slots
	bl StringCopy
_080F4004:
	bl TVShowDone
_080F4008:
	ldr r0, =gUnknown_0858D418
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowFindThatGamer

	thumb_func_start DoTVShowBreakingNewsTV
DoTVShowBreakingNewsTV: @ 80F4028
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0xC
	bls _080F4050
	b _080F4344
_080F4050:
	lsls r0, r7, 2
	ldr r1, =_080F4074
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4074:
	.4byte _080F40A8
	.4byte _080F40BA
	.4byte _080F40FC
	.4byte _080F4140
	.4byte _080F4168
	.4byte _080F418C
	.4byte _080F41D0
	.4byte _080F4254
	.4byte _080F42C8
	.4byte _080F42F4
	.4byte _080F42F4
	.4byte _080F4334
	.4byte _080F4284
_080F40A8:
	ldrb r0, [r6, 0x5]
	cmp r0, 0
	bne _080F40B4
	movs r0, 0x1
	strb r0, [r2]
	b _080F4344
_080F40B4:
	movs r0, 0x5
	strb r0, [r2]
	b _080F4344
_080F40BA:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4344
	.pool
_080F40FC:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4344
	.pool
_080F4140:
	ldrh r1, [r6, 0x8]
	movs r0, 0
	bl TV_PrintIntToStringVar
	ldr r4, =gStringVar2
	ldrh r0, [r6, 0x6]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4344
	.pool
_080F4168:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	bl TVShowDone
	b _080F4344
	.pool
_080F418C:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4344
	.pool
_080F41D0:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldrb r0, [r6, 0x5]
	cmp r0, 0x2
	beq _080F423C
	cmp r0, 0x2
	bgt _080F4218
	cmp r0, 0x1
	beq _080F421E
	b _080F4344
	.pool
_080F4218:
	cmp r0, 0x3
	beq _080F4248
	b _080F4344
_080F421E:
	ldrh r0, [r6, 0xC]
	cmp r0, 0
	bne _080F4230
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4344
	.pool
_080F4230:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4344
	.pool
_080F423C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4344
	.pool
_080F4248:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4344
	.pool
_080F4254:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0xC]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0xA]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	b _080F42A8
	.pool
_080F4284:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
_080F42A8:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4344
	.pool
_080F42C8:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4344
	.pool
_080F42F4:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	movs r4, 0xB
	muls r1, r4
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r6, 0x4]
	movs r2, 0
	bl GetMapName
	ldr r0, =sTVShowState
	strb r4, [r0]
	b _080F4344
	.pool
_080F4334:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xE]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F4344:
	ldr r0, =gUnknown_0858D428
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowBreakingNewsTV

	thumb_func_start DoTVShowSecretBaseVisit
DoTVShowSecretBaseVisit: @ 80F4360
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	adds r2, r0, 0
	cmp r6, 0xD
	bls _080F4388
	b _080F4588
_080F4388:
	lsls r0, r6, 2
	ldr r1, =_080F43AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F43AC:
	.4byte _080F43E4
	.4byte _080F4414
	.4byte _080F44E4
	.4byte _080F4448
	.4byte _080F44E4
	.4byte _080F449C
	.4byte _080F44C0
	.4byte _080F44E4
	.4byte _080F44EA
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4538
	.4byte _080F4584
_080F43E4:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0x3]
	cmp r0, 0
	bne _080F4408
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4588
	.pool
_080F4408:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4588
	.pool
_080F4414:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x4]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldrb r0, [r5, 0x3]
	cmp r0, 0x1
	bne _080F443C
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4588
	.pool
_080F443C:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4588
	.pool
_080F4448:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x5]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldrb r1, [r5, 0x3]
	cmp r1, 0x3
	beq _080F4484
	cmp r1, 0x3
	bgt _080F4470
	cmp r1, 0x2
	beq _080F4476
	b _080F4588
	.pool
_080F4470:
	cmp r1, 0x4
	beq _080F4490
	b _080F4588
_080F4476:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4588
	.pool
_080F4484:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4588
	.pool
_080F4490:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4588
	.pool
_080F449C:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x6]
	lsls r1, 5
	ldr r4, =gDecorations + 1
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrb r1, [r5, 0x7]
	lsls r1, 5
	adds r1, r4
	b _080F44CA
	.pool
_080F44C0:
	ldr r0, =gStringVar2
	ldrb r1, [r5, 0x6]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
_080F44CA:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4588
	.pool
_080F44E4:
	movs r0, 0x8
	strb r0, [r2]
	b _080F4588
_080F44EA:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldrb r1, [r5, 0x2]
	cmp r1, 0x18
	bhi _080F450C
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4588
	.pool
_080F450C:
	cmp r1, 0x31
	bhi _080F451C
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4588
	.pool
_080F451C:
	cmp r1, 0x45
	bhi _080F452C
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4588
	.pool
_080F452C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4588
	.pool
_080F4538:
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0xC]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r5, 0x8]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r5, 0xA]
	movs r4, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =sTVShowState
	strb r4, [r0]
	b _080F4588
	.pool
_080F4584:
	bl TVShowDone
_080F4588:
	ldr r0, =gUnknown_0858D45C
	lsls r1, r6, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSecretBaseVisit

	thumb_func_start DoTVShowPokemonLotterWinnerFlashReport
DoTVShowPokemonLotterWinnerFlashReport: @ 80F45A0
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r6, [r0]
	ldr r0, =gStringVar1
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x5]
	bl TVShowConvertInternationalString
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	bne _080F45FC
	ldr r0, =gStringVar2
	ldr r1, =gText_Jackpot
	bl StringCopy
	b _080F4634
	.pool
_080F45FC:
	cmp r0, 0x1
	bne _080F4614
	ldr r0, =gStringVar2
	ldr r1, =gText_First
	bl StringCopy
	b _080F4634
	.pool
_080F4614:
	cmp r0, 0x2
	bne _080F462C
	ldr r0, =gStringVar2
	ldr r1, =gText_Second
	bl StringCopy
	b _080F4634
	.pool
_080F462C:
	ldr r0, =gStringVar2
	ldr r1, =gText_Third
	bl StringCopy
_080F4634:
	ldr r4, =gStringVar3
	ldrh r0, [r5, 0x2]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	bl TVShowDone
	ldr r1, =gUnknown_0858D494
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonLotterWinnerFlashReport

	thumb_func_start DoTVShowThePokemonBattleSeminar
DoTVShowThePokemonBattleSeminar: @ 80F466C
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	cmp r7, 0x6
	bls _080F4692
	b _080F4858
_080F4692:
	lsls r0, r7, 2
	ldr r1, =_080F46B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F46B4:
	.4byte _080F46D0
	.4byte _080F4714
	.4byte _080F4760
	.4byte _080F47B4
	.4byte _080F47EC
	.4byte _080F4814
	.4byte _080F4838
_080F46D0:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0x11]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x4]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4858
	.pool
_080F4714:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0x11]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x4]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r2, [r6, 0x2]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4858
	.pool
_080F4760:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0x6]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	ldrb r1, [r6, 0x10]
	cmp r1, 0x2
	beq _080F479C
	cmp r1, 0x2
	bgt _080F4788
	cmp r1, 0x1
	beq _080F478E
	b _080F4824
	.pool
_080F4788:
	cmp r1, 0x3
	beq _080F47A8
	b _080F4824
_080F478E:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4858
	.pool
_080F479C:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4858
	.pool
_080F47A8:
	ldr r0, =sTVShowState
	strb r1, [r0]
	b _080F4858
	.pool
_080F47B4:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x8]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0xC]
	muls r1, r5
	adds r1, r4
	b _080F4820
	.pool
_080F47EC:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x8]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0xA]
	muls r1, r5
	adds r1, r4
	b _080F4820
	.pool
_080F4814:
	ldr r0, =gStringVar2
	ldrh r2, [r6, 0x8]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
_080F4820:
	bl StringCopy
_080F4824:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4858
	.pool
_080F4838:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0xE]
	movs r5, 0xD
	muls r1, r5
	ldr r4, =gMoveNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x2]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	bl TVShowDone
_080F4858:
	ldr r0, =gUnknown_0858D498
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowThePokemonBattleSeminar

	thumb_func_start DoTVShowTrainerFanClubSpecial
DoTVShowTrainerFanClubSpecial: @ 80F487C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x5
	bls _080F48A2
	b _080F499A
_080F48A2:
	lsls r0, r5, 2
	ldr r1, =_080F48C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F48C4:
	.4byte _080F48DC
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4944
	.4byte _080F4978
_080F48DC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x14]
	bl CopyEasyChatWord
	ldrb r1, [r4, 0x16]
	cmp r1, 0x59
	bls _080F4918
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F499A
	.pool
_080F4918:
	cmp r1, 0x45
	bls _080F4928
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F499A
	.pool
_080F4928:
	cmp r1, 0x1D
	bls _080F4938
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F499A
	.pool
_080F4938:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F499A
	.pool
_080F4944:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x16]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F499A
	.pool
_080F4978:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0xC
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x14]
	bl CopyEasyChatWord
	bl TVShowDone
_080F499A:
	ldr r0, =gUnknown_0858D320
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTrainerFanClubSpecial

	thumb_func_start DoTVShowTrainerFanClub
DoTVShowTrainerFanClub: @ 80F49BC
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xB
	bls _080F49E4
	b _080F4B3A
_080F49E4:
	lsls r0, r5, 2
	ldr r1, =_080F4A08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4A08:
	.4byte _080F4A38
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B14
	.4byte _080F4B1A
_080F4A38:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	adds r0, r4, 0
	adds r0, 0x23
	ldrb r0, [r0]
	lsls r0, 8
	adds r1, r4, 0
	adds r1, 0x22
	ldrb r1, [r1]
	adds r0, r1
	movs r1, 0xA
	bl __umodsi3
	cmp r0, 0x9
	bls _080F4A60
	b _080F4B3A
_080F4A60:
	lsls r0, 2
	ldr r1, =_080F4A74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4A74:
	.4byte _080F4A9C
	.4byte _080F4AA8
	.4byte _080F4AB4
	.4byte _080F4AC0
	.4byte _080F4ACC
	.4byte _080F4AD8
	.4byte _080F4AE4
	.4byte _080F4AF0
	.4byte _080F4AFC
	.4byte _080F4B08
_080F4A9C:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AA8:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AB4:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AC0:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4ACC:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AD8:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AE4:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AF0:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4AFC:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4B08:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4B3A
	.pool
_080F4B14:
	movs r0, 0xB
	strb r0, [r2]
	b _080F4B3A
_080F4B1A:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x8]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0x4]
	bl CopyEasyChatWord
	ldr r0, =gStringVar3
	ldrh r1, [r4, 0x6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F4B3A:
	ldr r0, =gUnknown_0858D4B4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowTrainerFanClub

	thumb_func_start DoTVShowSpotTheCuties
DoTVShowSpotTheCuties: @ 80F4B5C
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0xF
	bls _080F4B82
	b _080F4D84
_080F4B82:
	lsls r0, r5, 2
	ldr r1, =_080F4BA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4BA4:
	.4byte _080F4BE4
	.4byte _080F4C30
	.4byte _080F4C30
	.4byte _080F4C30
	.4byte _080F4C64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D64
	.4byte _080F4D80
_080F4BE4:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xF]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	cmp r1, 0x9
	bhi _080F4C14
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C14:
	cmp r1, 0x13
	bhi _080F4C24
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C24:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C30:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0xF]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4C64:
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0x18
	bls _080F4C76
	b _080F4D84
_080F4C76:
	lsls r0, 2
	ldr r1, =_080F4C88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4C88:
	.4byte _080F4CEC
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4CF8
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D04
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D10
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D1C
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D28
	.4byte _080F4D34
	.4byte _080F4D40
	.4byte _080F4D4C
	.4byte _080F4D58
_080F4CEC:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4CF8:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D04:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D10:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D1C:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D28:
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D34:
	ldr r1, =sTVShowState
	movs r0, 0xB
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D40:
	ldr r1, =sTVShowState
	movs r0, 0xC
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D4C:
	ldr r1, =sTVShowState
	movs r0, 0xD
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D58:
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D64:
	ldr r0, =gStringVar2
	adds r1, r4, 0x4
	ldrb r2, [r4, 0x10]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0xF
	strb r0, [r1]
	b _080F4D84
	.pool
_080F4D80:
	bl TVShowDone
_080F4D84:
	ldr r0, =gUnknown_0858D4E4
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSpotTheCuties

	thumb_func_start DoTVShowPokemonNewsBattleFrontier
DoTVShowPokemonNewsBattleFrontier: @ 80F4D9C
	push {r4-r7,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r7, [r0]
	adds r2, r0, 0
	cmp r7, 0x12
	bls _080F4DC4
	b _080F5014
_080F4DC4:
	lsls r0, r7, 2
	ldr r1, =_080F4DE8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4DE8:
	.4byte _080F4E34
	.4byte _080F4F18
	.4byte _080F4ECE
	.4byte _080F4EF4
	.4byte _080F4EF4
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F18
	.4byte _080F4F3C
	.4byte _080F4F74
	.4byte _080F4F9C
	.4byte _080F4FE0
	.4byte _080F5004
_080F4E34:
	ldrb r0, [r6, 0xD]
	subs r0, 0x1
	cmp r0, 0xC
	bls _080F4E3E
	b _080F5014
_080F4E3E:
	lsls r0, 2
	ldr r1, =_080F4E4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F4E4C:
	.4byte _080F4E80
	.4byte _080F4E86
	.4byte _080F4E8C
	.4byte _080F4E92
	.4byte _080F4E98
	.4byte _080F4E9E
	.4byte _080F4EA4
	.4byte _080F4EAA
	.4byte _080F4EB0
	.4byte _080F4EB6
	.4byte _080F4EBC
	.4byte _080F4EC2
	.4byte _080F4EC8
_080F4E80:
	movs r0, 0x1
	strb r0, [r2]
	b _080F5014
_080F4E86:
	movs r0, 0x2
	strb r0, [r2]
	b _080F5014
_080F4E8C:
	movs r0, 0x3
	strb r0, [r2]
	b _080F5014
_080F4E92:
	movs r0, 0x4
	strb r0, [r2]
	b _080F5014
_080F4E98:
	movs r0, 0x5
	strb r0, [r2]
	b _080F5014
_080F4E9E:
	movs r0, 0x6
	strb r0, [r2]
	b _080F5014
_080F4EA4:
	movs r0, 0x7
	strb r0, [r2]
	b _080F5014
_080F4EAA:
	movs r0, 0x8
	strb r0, [r2]
	b _080F5014
_080F4EB0:
	movs r0, 0x9
	strb r0, [r2]
	b _080F5014
_080F4EB6:
	movs r0, 0xA
	strb r0, [r2]
	b _080F5014
_080F4EBC:
	movs r0, 0xB
	strb r0, [r2]
	b _080F5014
_080F4EC2:
	movs r0, 0xC
	strb r0, [r2]
	b _080F5014
_080F4EC8:
	movs r0, 0xD
	strb r0, [r2]
	b _080F5014
_080F4ECE:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x10
	strb r0, [r1]
	b _080F5014
	.pool
_080F4EF4:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0xF
	strb r0, [r1]
	b _080F5014
	.pool
_080F4F18:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0xE
	strb r0, [r1]
	b _080F5014
	.pool
_080F4F3C:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x8]
	muls r1, r5
	adds r1, r4
	b _080F4FEC
	.pool
_080F4F74:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	b _080F4FEC
	.pool
_080F4F9C:
	ldr r0, =gStringVar1
	ldrh r1, [r6, 0x4]
	movs r5, 0xB
	muls r1, r5
	ldr r4, =gSpeciesNames
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r6, 0x6]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar3
	ldrh r1, [r6, 0x8]
	muls r1, r5
	adds r1, r4
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x11
	strb r0, [r1]
	b _080F5014
	.pool
_080F4FE0:
	ldr r0, =gStringVar1
	ldrh r2, [r6, 0xA]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
_080F4FEC:
	bl StringCopy
	ldr r1, =sTVShowState
	movs r0, 0x12
	strb r0, [r1]
	b _080F5014
	.pool
_080F5004:
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x13
	ldrb r2, [r6, 0xC]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F5014:
	ldr r0, =gUnknown_0858D524
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonNewsBattleFrontier

	thumb_func_start DoTVShowWhatsNo1InHoennToday
DoTVShowWhatsNo1InHoennToday: @ 80F5030
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	cmp r5, 0x8
	bls _080F5056
	b _080F5164
_080F5056:
	lsls r0, r5, 2
	ldr r1, =_080F5078
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5078:
	.4byte _080F509C
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5130
	.4byte _080F5154
_080F509C:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x4]
	cmp r0, 0x6
	bhi _080F5164
	lsls r0, 2
	ldr r1, =_080F50C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F50C0:
	.4byte _080F50DC
	.4byte _080F50E8
	.4byte _080F50F4
	.4byte _080F5100
	.4byte _080F510C
	.4byte _080F5118
	.4byte _080F5124
_080F50DC:
	ldr r1, =sTVShowState
	movs r0, 0x1
	strb r0, [r1]
	b _080F5164
	.pool
_080F50E8:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F5164
	.pool
_080F50F4:
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F5164
	.pool
_080F5100:
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F5164
	.pool
_080F510C:
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F5164
	.pool
_080F5118:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F5164
	.pool
_080F5124:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F5164
	.pool
_080F5130:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F5164
	.pool
_080F5154:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x5]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F5164:
	ldr r0, =gUnknown_0858D570
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowWhatsNo1InHoennToday

	thumb_func_start sub_80F5180
sub_80F5180: @ 80F5180
	push {r4,lr}
	movs r1, 0
	movs r2, 0
	ldr r3, [r0, 0xC]
	movs r4, 0x1
_080F518A:
	adds r0, r3, 0
	lsrs r0, r1
	ands r0, r4
	cmp r0, 0
	beq _080F519A
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080F519A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1F
	bls _080F518A
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80F5180

	thumb_func_start sub_80F51AC
sub_80F51AC: @ 80F51AC
	push {r4-r6,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	movs r2, 0
	movs r3, 0
	ldr r1, [r0, 0xC]
	movs r5, 0x1
	ldr r6, =gUnknown_0858D690
_080F51BC:
	adds r0, r1, 0
	lsrs r0, r2
	ands r0, r5
	cmp r0, 0
	beq _080F51DA
	cmp r3, r4
	bne _080F51D4
	adds r0, r2, r6
	ldrb r0, [r0]
	b _080F51E6
	.pool
_080F51D4:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_080F51DA:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _080F51BC
	movs r0, 0
_080F51E6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80F51AC

	thumb_func_start DoTVShowSecretBaseSecrets
DoTVShowSecretBaseSecrets: @ 80F51EC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r2, [r0]
	mov r9, r2
	adds r2, r0, 0
	mov r0, r9
	cmp r0, 0x2B
	bls _080F521E
	b _080F552A
_080F521E:
	lsls r0, 2
	ldr r1, =_080F5240
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5240:
	.4byte _080F52F0
	.4byte _080F5348
	.4byte _080F53C4
	.4byte _080F5444
	.4byte _080F5498
	.4byte _080F5498
	.4byte _080F5498
	.4byte _080F54C4
	.4byte _080F54E8
	.4byte _080F54EC
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F54F0
	.4byte _080F5510
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
	.4byte _080F5526
_080F52F0:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080F5328
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F552A
	.pool
_080F5328:
	movs r0, 0x1
	strb r0, [r5, 0x12]
	bl Random
	ldr r4, =gUnknown_0203A031
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	b _080F542A
	.pool
_080F5348:
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	beq _080F53DE
	cmp r6, 0x2
	beq _080F5370
	movs r4, 0
	b _080F538A
	.pool
_080F5370:
	strb r6, [r5, 0x12]
	ldr r0, =gUnknown_0203A031
	ldrb r0, [r0]
	cmp r0, 0
	bne _080F5384
	adds r0, r5, 0
	movs r1, 0x1
	b _080F542C
	.pool
_080F5384:
	adds r0, r5, 0
	movs r1, 0
	b _080F542C
_080F538A:
	bl Random
	ldr r7, =gUnknown_0203A031
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r7, 0x1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r7]
	cmp r0, r1
	bne _080F53B2
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000fffe
	cmp r4, r0
	bls _080F538A
_080F53B2:
	movs r0, 0x2
	strb r0, [r5, 0x12]
	ldrb r1, [r7, 0x1]
	b _080F542A
	.pool
_080F53C4:
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	adds r0, r5, 0
	bl sub_80F5180
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bne _080F53F0
_080F53DE:
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F552A
	.pool
_080F53F0:
	movs r4, 0
	ldr r7, =gUnknown_0203A031
	ldr r2, =0x0000fffe
	mov r8, r2
_080F53F8:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	strb r0, [r7, 0x2]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r7]
	cmp r0, r1
	beq _080F5418
	ldrb r2, [r7, 0x1]
	cmp r0, r2
	bne _080F5422
_080F5418:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r8
	bls _080F53F8
_080F5422:
	movs r0, 0x3
	strb r0, [r5, 0x12]
	ldr r0, =gUnknown_0203A031
	ldrb r1, [r0, 0x2]
_080F542A:
	adds r0, r5, 0
_080F542C:
	bl sub_80F51AC
	ldr r1, =sTVShowState
	strb r0, [r1]
	b _080F552A
	.pool
_080F5444:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	bl TV_PrintIntToStringVar
	ldrh r0, [r5, 0x2]
	cmp r0, 0x1E
	bhi _080F547C
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F552A
	.pool
_080F547C:
	cmp r0, 0x64
	bhi _080F548C
	ldr r1, =sTVShowState
	movs r0, 0x5
	strb r0, [r1]
	b _080F552A
	.pool
_080F548C:
	ldr r1, =sTVShowState
	movs r0, 0x6
	strb r0, [r1]
	b _080F552A
	.pool
_080F5498:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F552A
	.pool
_080F54C4:
	ldr r0, =gStringVar1
	adds r1, r5, 0x4
	ldrb r2, [r5, 0x1C]
	bl TVShowConvertInternationalString
	ldr r0, =gStringVar2
	adds r1, r5, 0
	adds r1, 0x13
	ldrb r2, [r5, 0x1B]
	bl TVShowConvertInternationalString
	bl TVShowDone
	b _080F552A
	.pool
_080F54E8:
	movs r0, 0x3
	b _080F5528
_080F54EC:
	movs r0, 0x3
	b _080F5528
_080F54F0:
	ldr r4, =gStringVar2
	ldrh r0, [r5, 0x10]
	bl ItemId_GetItem
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =sTVShowState
	ldrb r0, [r5, 0x12]
	strb r0, [r1]
	b _080F552A
	.pool
_080F5510:
	adds r0, r5, 0
	adds r0, 0x22
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080F5522
	movs r0, 0x16
	b _080F5528
_080F5522:
	movs r0, 0x15
	b _080F5528
_080F5526:
	ldrb r0, [r5, 0x12]
_080F5528:
	strb r0, [r2]
_080F552A:
	ldr r0, =gUnknown_0858D594
	mov r2, r9
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSecretBaseSecrets

	thumb_func_start DoTVShowSafariFanClub
DoTVShowSafariFanClub: @ 80F5548
	push {r4,r5,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r0, =sTVShowState
	ldrb r5, [r0]
	adds r2, r0, 0
	cmp r5, 0xA
	bls _080F5570
	b _080F56BC
_080F5570:
	lsls r0, r5, 2
	ldr r1, =_080F5594
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080F5594:
	.4byte _080F55C0
	.4byte _080F55DC
	.4byte _080F5614
	.4byte _080F5628
	.4byte _080F569A
	.4byte _080F562E
	.4byte _080F5650
	.4byte _080F5680
	.4byte _080F5694
	.4byte _080F569A
	.4byte _080F56B8
_080F55C0:
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080F55CC
	movs r0, 0x6
	strb r0, [r2]
	b _080F56BC
_080F55CC:
	cmp r1, 0x3
	bhi _080F55D6
	movs r0, 0x5
	strb r0, [r2]
	b _080F56BC
_080F55D6:
	movs r0, 0x1
	strb r0, [r2]
	b _080F56BC
_080F55DC:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _080F5608
	ldr r1, =sTVShowState
	movs r0, 0x3
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5608:
	ldr r1, =sTVShowState
	movs r0, 0x2
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5614:
	ldrb r1, [r4, 0x3]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x4
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5628:
	movs r0, 0x4
	strb r0, [r2]
	b _080F56BC
_080F562E:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r1, [r4, 0x2]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _080F5662
	b _080F5674
	.pool
_080F5650:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	bne _080F5674
_080F5662:
	ldr r1, =sTVShowState
	movs r0, 0x8
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5674:
	ldr r1, =sTVShowState
	movs r0, 0x7
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5680:
	ldrb r1, [r4, 0x3]
	movs r0, 0x1
	bl TV_PrintIntToStringVar
	ldr r1, =sTVShowState
	movs r0, 0x9
	strb r0, [r1]
	b _080F56BC
	.pool
_080F5694:
	movs r0, 0x9
	strb r0, [r2]
	b _080F56BC
_080F569A:
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x13
	ldrb r2, [r4, 0x4]
	bl TVShowConvertInternationalString
	ldr r1, =sTVShowState
	movs r0, 0xA
	strb r0, [r1]
	b _080F56BC
	.pool
_080F56B8:
	bl TVShowDone
_080F56BC:
	ldr r0, =gUnknown_0858D640
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowSafariFanClub

	thumb_func_start DoTVShowPokemonContestLiveUpdates2
DoTVShowPokemonContestLiveUpdates2: @ 80F56D4
	push {r4-r6,lr}
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x000027cc
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	ldr r6, =sTVShowState
	ldrb r5, [r6]
	cmp r5, 0x2
	bgt _080F5718
	cmp r5, 0x1
	bge _080F5744
	cmp r5, 0
	beq _080F571E
	b _080F575E
	.pool
_080F5718:
	cmp r5, 0x3
	beq _080F574E
	b _080F575E
_080F571E:
	ldr r0, =gStringVar1
	ldrb r1, [r4, 0xA]
	bl sub_818E868
	ldrb r1, [r4, 0x16]
	cmp r1, 0x1
	bne _080F5734
	strb r1, [r6]
	b _080F575E
	.pool
_080F5734:
	cmp r1, 0
	bne _080F573E
	movs r0, 0x2
	strb r0, [r6]
	b _080F575E
_080F573E:
	movs r0, 0x3
	strb r0, [r6]
	b _080F575E
_080F5744:
	ldr r0, =gStringVar3
	adds r1, r4, 0x2
	ldrb r2, [r4, 0x17]
	bl TVShowConvertInternationalString
_080F574E:
	ldr r0, =gStringVar2
	adds r1, r4, 0
	adds r1, 0xB
	ldrb r2, [r4, 0x18]
	bl TVShowConvertInternationalString
	bl TVShowDone
_080F575E:
	ldr r0, =gUnknown_0858D384
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoTVShowPokemonContestLiveUpdates2

	thumb_func_start TVShowDone
TVShowDone: @ 80F577C
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, =sTVShowState
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x000027cd
	adds r2, r0
	movs r0, 0
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end TVShowDone

	thumb_func_start ResetTVShowState
ResetTVShowState: @ 80F57B8
	ldr r1, =sTVShowState
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end ResetTVShowState

	.align 2, 0 @ Don't pad with nop.
