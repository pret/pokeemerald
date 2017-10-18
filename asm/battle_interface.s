	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




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

	thumb_func_start UpdateStatusIconInHealthbox
UpdateStatusIconInHealthbox: @ 80743F8
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
	thumb_func_end UpdateStatusIconInHealthbox

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
	bl UpdateNickInHealthbox
_080749DE:
	cmp r7, 0x9
	beq _080749E6
	cmp r7, 0
	bne _080749EC
_080749E6:
	adds r0, r6, 0
	bl UpdateStatusIconInHealthbox
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
	bl UpdateNickInHealthbox
_08074A80:
	cmp r7, 0x9
	beq _08074A88
	cmp r7, 0
	bne _08074A8E
_08074A88:
	adds r0, r6, 0
	bl UpdateStatusIconInHealthbox
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
