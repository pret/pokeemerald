	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

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
	ldr r4, =sTVSecretBaseSecretsRandomValues
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
	ldr r0, =sTVSecretBaseSecretsRandomValues
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
	ldr r7, =sTVSecretBaseSecretsRandomValues
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
	ldr r7, =sTVSecretBaseSecretsRandomValues
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
	ldr r0, =sTVSecretBaseSecretsRandomValues
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
