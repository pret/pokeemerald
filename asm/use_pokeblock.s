	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_8166564
sub_8166564: @ 8166564
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203BC90
	ldr r0, [r4]
	adds r0, 0x50
	ldrb r1, [r0]
	cmp r1, 0
	beq _08166580
	cmp r1, 0x1
	beq _081665C0
	b _08166610
	.pool
_08166580:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8166340
	bl SetVBlankCallback
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r1, [r4]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166610
	.pool
_081665C0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166610
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3464
	ldr r4, [r4]
	ldr r2, =0x00008041
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r3, =0x00008040
	adds r0, r4, r3
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _0816660A
	ldr r1, =0x00007fb3
	adds r0, r4, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x91
	adds r0, r4, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r3, =0x00007b1c
	adds r0, r4, r3
	subs r3, 0xC
	adds r1, r4, r3
	ldrb r1, [r1]
	bl sub_81D3480
_0816660A:
	ldr r0, =sub_8166634
	bl sub_816636C
_08166610:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166564

	thumb_func_start sub_8166634
sub_8166634: @ 8166634
	push {lr}
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _08166644
	b _0816680E
_08166644:
	lsls r0, 2
	ldr r1, =_08166658
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166658:
	.4byte _08166678
	.4byte _0816675C
	.4byte _0816680E
	.4byte _08166788
	.4byte _0816680E
	.4byte _08166794
	.4byte _081667AC
	.4byte _081667F4
_08166678:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081666B8
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl sub_8167CA0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3520
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x1
	b _0816680C
	.pool
_081666B8:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081666F0
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_8167CA0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007b1c
	adds r0, r2
	bl sub_81D3520
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x1
	b _0816680C
	.pool
_081666F0:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08166710
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x3
	b _0816680C
	.pool
_08166710:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816671A
	b _0816680E
_0816671A:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0816674C
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x3
	b _0816680C
	.pool
_0816674C:
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x5
	b _0816680C
	.pool
_0816675C:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0816680E
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	b _0816680C
	.pool
_08166788:
	ldr r0, =sub_8166BEC
	bl sub_816636C
	b _0816680E
	.pool
_08166794:
	bl sub_8166D44
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816680E
	.pool
_081667AC:
	bl sub_8166DE4
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _081667CC
	cmp r1, 0
	bgt _081667C6
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08166804
	b _0816680E
_081667C6:
	cmp r1, 0x1
	bne _0816680E
	b _08166804
_081667CC:
	bl sub_8167268
	lsls r0, 24
	cmp r0, 0
	beq _081667E8
	bl sub_8166F50
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0x7
	b _0816680C
	.pool
_081667E8:
	ldr r0, =sub_816681C
	bl sub_816636C
	b _0816680E
	.pool
_081667F4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816680E
	bl sub_8166F94
_08166804:
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	movs r1, 0
_0816680C:
	strb r1, [r0]
_0816680E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166634

	thumb_func_start sub_816681C
sub_816681C: @ 816681C
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_0203BC90
	ldr r0, [r5]
	adds r0, 0x50
	ldrb r4, [r0]
	cmp r4, 0
	beq _08166838
	cmp r4, 0x1
	beq _08166888
	b _081668D4
	.pool
_08166838:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	ldr r1, =gPokeblockMonId
	strb r0, [r1]
	ldr r1, =gUnknown_0203BC94
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, =gUnknown_0203BC98
	ldr r0, [r2, 0x8]
	str r0, [r1]
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r5]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081668D4
	.pool
_08166888:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081668D4
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCA0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	bl FreeAllWindowBuffers
	ldr r1, =gMain
	ldr r0, =CB2_ReturnAndChooseMonToGivePokeblock
	str r0, [r1, 0x8]
	bl CB2_PreparePokeblockFeedScene
_081668D4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816681C

	thumb_func_start sub_81668F8
sub_81668F8: @ 81668F8
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x50
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x6
	bls _0816690C
	b _08166A18
_0816690C:
	lsls r0, 2
	ldr r1, =_08166920
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166920:
	.4byte _0816693C
	.4byte _08166972
	.4byte _08166A18
	.4byte _081669A0
	.4byte _081669AE
	.4byte _081669C8
	.4byte _081669F4
_0816693C:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldr r1, =gPokeblockMonId
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08166968
	ldr r0, [r4]
	adds r0, 0x56
	ldrb r0, [r0]
	bl sub_8167CA0
	ldr r1, [r4]
	b _081669E2
	.pool
_08166968:
	ldr r0, [r4]
	adds r0, 0x50
	movs r1, 0x3
	strb r1, [r0]
	b _08166A18
_08166972:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08166A18
	ldr r0, =gUnknown_0203BC90
	ldr r0, [r0]
	adds r0, 0x50
	strb r1, [r0]
	b _08166A18
	.pool
_081669A0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	b _081669DE
_081669AE:
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	b _081669DE
_081669C8:
	ldr r0, =sub_8166340
	bl SetVBlankCallback
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_081669DE:
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
_081669E2:
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166A18
	.pool
_081669F4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166A18
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3464
	ldr r0, =sub_8166A34
	bl sub_816636C
	ldr r0, =sub_816631C
	bl SetMainCallback2
_08166A18:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81668F8

	thumb_func_start sub_8166A34
sub_8166A34: @ 8166A34
	push {r4-r6,lr}
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x50
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x5
	bls _08166A46
	b _08166BDA
_08166A46:
	lsls r0, 2
	ldr r1, =_08166A58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08166A58:
	.4byte _08166A70
	.4byte _08166AAC
	.4byte _08166AC0
	.4byte _08166B14
	.4byte _08166B94
	.4byte _08166BB6
_08166A70:
	ldr r4, [r5]
	ldr r3, =gPlayerParty
	str r3, [r4, 0xC]
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0, r1
	subs r2, 0x88
	adds r1, r2
	ldrb r2, [r1]
	movs r1, 0x64
	muls r1, r2
	adds r1, r3
	str r1, [r4, 0xC]
	ldr r3, =0x00007b1c
	adds r0, r3
	bl sub_81D3520
	b _08166BAA
	.pool
_08166AAC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08166ABA
	b _08166BDA
_08166ABA:
	b _08166BAA
	.pool
_08166AC0:
	bl sub_8167104
	ldr r6, =gUnknown_0203BC90
	ldr r0, [r6]
	adds r0, 0x5C
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00007ca8
	adds r1, r5
	bl sub_81D2754
	ldr r2, [r4]
	ldr r4, =0x00007c58
	adds r0, r2, r4
	ldr r3, =0x00007fb3
	adds r1, r2, r3
	movs r3, 0
	ldrsb r3, [r1, r3]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r4, 0x14
	adds r1, r4
	adds r1, r2, r1
	adds r2, r5
	bl sub_81D1F84
	bl sub_8167338
	ldr r1, [r6]
	b _08166BAC
	.pool
_08166B14:
	ldr r5, =gUnknown_0203BCAC
	ldr r0, [r5]
	ldr r1, =0x00007c58
	adds r0, r1
	bl sub_81D2074
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08166BDA
	ldr r0, [r5]
	ldr r4, =0x00008041
	adds r0, r4
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	bl sub_81681F4
	ldr r3, [r5]
	adds r4, r3, r4
	ldrb r1, [r4]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08166B6C
	ldr r4, =0x00007fb3
	adds r0, r3, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r4, =0x00007b1c
	adds r0, r3, r4
	subs r4, 0xC
	adds r1, r3, r4
	ldrb r1, [r1]
	bl sub_81D3480
_08166B6C:
	ldr r1, =gUnknown_0203BC90
	ldr r0, [r1]
	adds r0, 0x52
	strb r6, [r0]
	ldr r1, [r1]
	b _08166BAC
	.pool
_08166B94:
	ldr r1, [r5]
	adds r1, 0x52
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bls _08166BDA
	bl sub_8166E24
_08166BAA:
	ldr r1, [r5]
_08166BAC:
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166BDA
_08166BB6:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08166BDA
	bl sub_8166EDC
	lsls r0, 24
	cmp r0, 0
	bne _08166BDA
	ldr r0, =gSpecialVar_ItemId
	ldrb r0, [r0]
	bl TryClearPokeblock
	ldr r0, =sub_8166BEC
	bl sub_816636C
_08166BDA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166A34

	thumb_func_start sub_8166BEC
sub_8166BEC: @ 8166BEC
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203BC90
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x50
	ldrb r1, [r2]
	cmp r1, 0x1
	beq _08166C28
	cmp r1, 0x1
	bgt _08166C0C
	cmp r1, 0
	beq _08166C16
	b _08166D18
	.pool
_08166C0C:
	cmp r1, 0x2
	beq _08166C40
	cmp r1, 0x3
	beq _08166C5C
	b _08166D18
_08166C16:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08166C4A
_08166C28:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08166D18
	movs r0, 0x2
	strb r0, [r2]
	b _08166D18
	.pool
_08166C40:
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
	bl ScanlineEffect_InitHBlankDmaTransfer
_08166C4A:
	ldr r1, [r4]
	adds r1, 0x50
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08166D18
	.pool
_08166C5C:
	ldr r0, [r0, 0x4]
	bl SetMainCallback2
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D354C
	movs r4, 0
_08166C70:
	ldr r5, =gUnknown_0203BCAC
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
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
	bls _08166C70
	movs r0, 0
	bl FreeSpriteTilesByTag
	movs r0, 0x1
	bl FreeSpriteTilesByTag
	movs r0, 0
	bl FreeSpritePaletteByTag
	movs r0, 0x1
	bl FreeSpritePaletteByTag
	movs r4, 0
_08166CAE:
	ldr r0, [r5]
	lsls r1, r4, 2
	ldr r2, =0x00007b44
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bls _08166CAE
	ldr r6, =gUnknown_0203BCAC
	ldr r0, [r6]
	ldr r2, =0x00007b10
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08166CE6
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_08166CE6:
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCA0
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203BCA8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, [r6]
	bl Free
	str r5, [r6]
	bl FreeAllWindowBuffers
_08166D18:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166BEC

	thumb_func_start sub_8166D44
sub_8166D44: @ 8166D44
	push {r4,lr}
	sub sp, 0x4C
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	add r2, sp, 0xC
	bl GetMonData
	add r0, sp, 0xC
	bl StringGetEnd10
	ldr r1, =gText_GetsAPokeBlockQuestion
	add r0, sp, 0xC
	bl StringAppend
	ldr r4, =gStringVar4
	adds r0, r4, 0
	add r1, sp, 0xC
	bl StringCopy
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sUsePokeblockYesNoWinTemplate
	movs r1, 0x97
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	add sp, 0x4C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166D44

	thumb_func_start sub_8166DE4
sub_8166DE4: @ 8166DE4
	push {r4,lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	lsrs r4, r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _08166E18
	cmp r1, 0
	bgt _08166E02
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08166E06
	b _08166E18
_08166E02:
	cmp r1, 0x1
	bne _08166E18
_08166E06:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x2
	bl rbox_fill_rectangle
	movs r0, 0x2
	bl ClearWindowTilemap
_08166E18:
	lsls r0, r4, 24
	asrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8166DE4

	thumb_func_start sub_8166E24
sub_8166E24: @ 8166E24
	push {r4,lr}
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r3, =gUnknown_0203BC90
	ldr r0, [r3]
	adds r0, 0x53
	movs r1, 0
	strb r1, [r0]
	ldr r2, [r3]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	adds r0, r2, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	adds r4, r3, 0
	cmp r0, 0
	bne _08166E84
	adds r2, r4, 0
_08166E60:
	ldr r0, [r2]
	adds r0, 0x53
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	adds r0, r3, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08166E60
_08166E84:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166EA8
	ldr r0, =gStringVar4
	ldrb r1, [r1]
	adds r2, 0x61
	adds r2, r1
	ldrb r2, [r2]
	bl sub_8166FD4
	b _08166EB8
	.pool
_08166EA8:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0203BC90
	ldr r1, [r1]
	adds r1, 0x53
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8166FD4
_08166EB8:
	ldr r0, =gStringVar4
	bl sub_8166FB0
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166E24

	thumb_func_start sub_8166EDC
sub_8166EDC: @ 8166EDC
	push {r4,r5,lr}
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_0203BC90
	adds r3, r5, 0
	movs r4, 0x5
_08166EEC:
	ldr r0, [r3]
	adds r0, 0x53
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r2, [r3]
	adds r1, r2, 0
	adds r1, 0x53
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _08166F18
	adds r0, r2, 0
	adds r0, 0x61
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08166F1E
	b _08166EEC
	.pool
_08166F18:
	strb r4, [r1]
	movs r0, 0
	b _08166F44
_08166F1E:
	ldr r4, =gStringVar4
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x53
	ldrb r1, [r1]
	adds r0, 0x61
	adds r0, r1
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8166FD4
	adds r0, r4, 0
	bl sub_8166FB0
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
_08166F44:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8166EDC

	thumb_func_start sub_8166F50
sub_8166F50: @ 8166F50
	push {lr}
	sub sp, 0xC
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0x97
	movs r2, 0xE
	bl sub_8098858
	ldr r2, =gText_WontEatAnymore
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166F50

	thumb_func_start sub_8166F94
sub_8166F94: @ 8166F94
	push {lr}
	movs r0, 0x2
	bl rbox_fill_rectangle
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_8166F94

	thumb_func_start sub_8166FB0
sub_8166FB0: @ 8166FB0
	push {lr}
	sub sp, 0xC
	ldr r2, =gStringVar4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166FB0

	thumb_func_start sub_8166FD4
sub_8166FD4: @ 8166FD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r2, 16
	lsrs r0, r2, 16
	asrs r2, 16
	cmp r2, 0
	beq _08167010
	cmp r2, 0
	ble _08166FEC
	movs r0, 0
_08166FEC:
	lsls r0, 16
	ldr r1, =sContestStatNames
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =gText_WasEnhanced
	adds r0, r4, 0
	bl StringAppend
	b _08167018
	.pool
_08167010:
	ldr r1, =gText_NothingChanged
	adds r0, r4, 0
	bl StringCopy
_08167018:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166FD4

	thumb_func_start sub_8167024
sub_8167024: @ 8167024
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
	ldr r7, =gUnknown_085DFCB0
_0816702E:
	lsls r0, r4, 2
	adds r0, r7
	ldr r1, [r0]
	adds r0, r6, 0
	bl GetMonData
	adds r1, r5, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _0816702E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167024

	thumb_func_start sub_8167054
sub_8167054: @ 8167054
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r5, r1, 0
	adds r0, r5, 0
	movs r1, 0x30
	bl GetMonData
	cmp r0, 0xFF
	beq _081670F0
	mov r0, r8
	adds r1, r5, 0
	bl sub_8167184
	movs r4, 0
	mov r7, sp
_08167078:
	ldr r1, =gUnknown_085DFCB0
	lsls r0, r4, 2
	adds r0, r1
	ldr r6, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r7]
	ldr r1, =gUnknown_0203BC90
	ldr r1, [r1]
	lsls r2, r4, 1
	adds r1, 0x66
	adds r1, r2
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r0, 0
	bge _081670A6
	movs r1, 0
_081670A6:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081670B0
	movs r1, 0xFF
_081670B0:
	strb r1, [r7]
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08167078
	adds r0, r5, 0
	movs r1, 0x30
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	ldrb r2, [r2, 0x6]
	adds r1, r0, r2
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081670E2
	movs r1, 0xFF
_081670E2:
	mov r0, sp
	strb r1, [r0]
	adds r0, r5, 0
	movs r1, 0x30
	mov r2, sp
	bl SetMonData
_081670F0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167054

	thumb_func_start sub_8167104
sub_8167104: @ 8167104
	push {r4,r5,lr}
	ldr r5, =gPlayerParty
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008041
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x00007fb9
	adds r1, r0
	ldrb r1, [r1]
	movs r0, 0x64
	muls r0, r1
	adds r5, r0, r5
	ldr r4, =gUnknown_0203BC90
	ldr r1, [r4]
	adds r1, 0x57
	adds r0, r5, 0
	bl sub_8167024
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r1, r5, 0
	bl sub_8167054
	ldr r1, [r4]
	adds r1, 0x5C
	adds r0, r5, 0
	bl sub_8167024
	movs r3, 0
_08167144:
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0x61
	adds r2, r3
	adds r1, r0, 0
	adds r1, 0x5C
	adds r1, r3
	adds r0, 0x57
	adds r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	subs r1, r0
	strb r1, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x4
	bls _08167144
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167104

	thumb_func_start sub_8167184
sub_8167184: @ 8167184
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	ldr r1, =gUnknown_0203BC90
	ldr r3, [r1]
	ldrb r1, [r0, 0x1]
	adds r2, r3, 0
	adds r2, 0x66
	strh r1, [r2]
	ldrb r2, [r0, 0x5]
	adds r1, r3, 0
	adds r1, 0x68
	strh r2, [r1]
	ldrb r1, [r0, 0x4]
	adds r2, r3, 0
	adds r2, 0x6A
	strh r1, [r2]
	ldrb r2, [r0, 0x3]
	adds r1, r3, 0
	adds r1, 0x6C
	strh r2, [r1]
	ldrb r1, [r0, 0x2]
	adds r0, r3, 0
	adds r0, 0x6E
	strh r1, [r0]
	ldr r0, =gPokeblockGain
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081671D4
	movs r0, 0x1
	b _081671DA
	.pool
_081671D4:
	cmp r0, 0
	bge _08167250
	movs r0, 0xFF
_081671DA:
	movs r2, 0
	lsls r0, 24
	mov r9, r0
	ldr r0, =gUnknown_0203BC90
	mov r8, r0
_081671E4:
	mov r0, r8
	ldr r1, [r0]
	lsls r0, r2, 24
	asrs r6, r0, 24
	lsls r7, r6, 1
	adds r1, 0x66
	adds r1, r7
	movs r2, 0
	ldrsh r4, [r1, r2]
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0816721C
	lsls r0, r5, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r5, r0, 24
_0816721C:
	ldr r0, =gUnknown_085DFCC4
	adds r0, r6, r0
	ldrb r1, [r0]
	mov r0, r10
	bl GetMonFlavorRelation
	lsls r0, 24
	asrs r2, r0, 24
	cmp r0, r9
	bne _08167244
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x66
	adds r0, r7
	lsls r1, r5, 24
	asrs r1, 24
	muls r1, r2
	ldrh r2, [r0]
	adds r1, r2
	strh r1, [r0]
_08167244:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x4
	ble _081671E4
_08167250:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167184

	thumb_func_start sub_8167268
sub_8167268: @ 8167268
	push {lr}
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008041
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	subs r2, 0x89
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _0816729C
	movs r0, 0
	b _0816729E
	.pool
_0816729C:
	movs r0, 0x1
_0816729E:
	pop {r1}
	bx r1
	thumb_func_end sub_8167268

	thumb_func_start sub_81672A4
sub_81672A4: @ 81672A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081672AC:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081672D2
	cmp r5, 0
	bne _081672CC
	adds r0, r4, 0
	b _081672DE
	.pool
_081672CC:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081672D2:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081672AC
	movs r0, 0
_081672DE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81672A4

	thumb_func_start sub_81672E4
sub_81672E4: @ 81672E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	movs r6, 0
	cmp r6, r5
	bcs _08167314
_081672F2:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	beq _0816730A
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0816730A:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081672F2
_08167314:
	subs r0, r5, r6
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81672E4

	thumb_func_start sub_8167324
sub_8167324: @ 8167324
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8167324

	thumb_func_start sub_8167338
sub_8167338: @ 8167338
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_085DFD18
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085DFD20
	bl LoadSpritePalette
	ldr r2, =gUnknown_0203BC90
	ldr r0, [r2]
	adds r0, 0x54
	movs r1, 0
	strb r1, [r0]
	movs r4, 0
	adds r5, r2, 0
	ldr r6, =gUnknown_085DFD28
	adds r0, r6, 0x2
	mov r8, r0
	ldr r7, =gSprites + 0x1C
_08167360:
	ldr r0, [r5]
	adds r0, 0x61
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081673AC
	lsls r2, r4, 2
	adds r0, r2, r6
	movs r3, 0
	ldrsh r1, [r0, r3]
	add r2, r8
	movs r0, 0
	ldrsh r2, [r2, r0]
	ldr r0, =gUnknown_085DFD5C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081673AC
	ldr r0, [r5]
	adds r0, 0x61
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _081673A2
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldr r1, =sub_81673DC
	str r1, [r0]
_081673A2:
	ldr r1, [r5]
	adds r1, 0x54
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081673AC:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08167360
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167338

	thumb_func_start sub_81673DC
sub_81673DC: @ 81673DC
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x5
	bgt _081673EE
	ldrh r0, [r1, 0x26]
	subs r0, 0x2
	b _081673F6
_081673EE:
	cmp r0, 0xB
	bgt _081673F8
	ldrh r0, [r1, 0x26]
	adds r0, 0x2
_081673F6:
	strh r0, [r1, 0x26]
_081673F8:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _08167418
	adds r0, r1, 0
	bl DestroySprite
	ldr r0, =gUnknown_0203BC90
	ldr r1, [r0]
	adds r1, 0x54
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_08167418:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81673DC

	thumb_func_start sub_8167420
sub_8167420: @ 8167420
	push {r4-r6,lr}
	movs r4, 0
	movs r5, 0
	ldr r6, =gUnknown_0203BCAC
	b _08167472
	.pool
_08167430:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r3, r0, 0
	cmp r3, 0
	bne _0816746C
	ldr r1, [r6]
	lsls r2, r5, 2
	adds r1, r2
	ldr r0, =0x00007fb8
	adds r1, r0
	movs r0, 0xE
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r2
	ldr r1, =0x00007fb9
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r0, r2
	ldr r2, =0x00007fba
	adds r0, r2
	strh r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0816746C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08167472:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _08167430
	ldr r2, =gUnknown_0203BCAC
	ldr r0, [r2]
	ldr r1, =0x00008041
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r1, r5, 0x1
	ldr r2, =0x00008040
	adds r0, r2
	strb r1, [r0]
	bl sub_81674BC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167420

	thumb_func_start sub_81674BC
sub_81674BC: @ 81674BC
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r5, =0x00008041
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_816753C
	ldr r0, [r4]
	ldr r1, =0x00007fb3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, =0x00007fb4
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00007fb5
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	adds r5, r0, r5
	ldrb r3, [r5]
	adds r1, r3, 0x1
	adds r2, 0x8C
	adds r0, r2
	ldrb r2, [r0]
	cmp r1, r2
	blt _08167500
	movs r1, 0
_08167500:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r0, 0
	bge _08167510
	subs r0, r2, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08167510:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_816753C
	lsls r0, r4, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_816753C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81674BC

	thumb_func_start sub_816753C
sub_816753C: @ 816753C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203BCAC
	mov r9, r0
	ldr r1, [r0]
	lsls r5, 16
	asrs r0, r5, 14
	adds r0, r1, r0
	ldr r3, =0x00007fb8
	adds r2, r0, r3
	ldrb r7, [r2]
	ldr r2, =0x00007fb9
	adds r0, r2
	ldrb r0, [r0]
	mov r10, r0
	adds r3, 0x88
	adds r0, r1, r3
	ldrb r6, [r0]
	movs r0, 0
	mov r8, r0
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r2, =0x00007b4d
	adds r0, r2
	adds r0, r1, r0
	lsls r2, r4, 6
	ldr r3, =0x00007b95
	adds r2, r3
	adds r1, r2
	lsrs r5, 16
	str r5, [sp]
	str r6, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D2ED4
	mov r3, r9
	ldr r1, [r3]
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r3, =0x00007fb0
	adds r1, r3
	str r5, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r2, r8
	str r2, [sp, 0xC]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D2F78
	lsls r0, r4, 13
	movs r1, 0xC1
	lsls r1, 2
	adds r0, r1
	mov r3, r9
	ldr r1, [r3]
	adds r0, r1, r0
	lsls r4, 7
	adds r4, 0x4
	adds r1, r4
	str r5, [sp]
	str r6, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	adds r2, r7, 0
	mov r3, r10
	bl sub_81D3094
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816753C

	thumb_func_start sub_8167608
sub_8167608: @ 8167608
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gUnknown_0203BCAC
	ldr r3, [r1]
	ldr r0, =0x00007b10
	mov r8, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0xFF
	bne _08167714
	add r5, sp, 0x18
	add r4, sp, 0x20
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_81D31D0
	lsls r0, r6, 13
	movs r1, 0xC1
	lsls r1, 2
	adds r0, r1
	ldr r1, [r7]
	adds r0, r1, r0
	str r0, [sp, 0x18]
	lsls r0, r6, 7
	adds r0, 0x4
	adds r1, r0
	str r1, [sp, 0x20]
	adds r0, r4, 0
	bl LoadSpritePalette
	ldr r1, [r7]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x00007b12
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl LoadSpriteSheet
	ldr r1, [r7]
	ldr r3, =0x00007b14
	adds r1, r3
	strh r0, [r1]
	mov r0, sp
	movs r1, 0x26
	movs r2, 0x68
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, [r7]
	ldr r2, =0x00007b10
	adds r0, r2
	strb r1, [r0]
	cmp r1, 0x40
	bne _081676AC
	movs r0, 0x64
	bl FreeSpriteTilesByTag
	movs r0, 0x64
	bl FreeSpritePaletteByTag
	ldr r0, [r7]
	add r0, r8
	movs r1, 0xFF
	strb r1, [r0]
	b _08167742
	.pool
_081676AC:
	ldr r0, [r7]
	add r0, r8
	strb r1, [r0]
	ldr r4, =gSprites
	ldr r2, [r7]
	mov r0, r8
	adds r3, r2, r0
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8168168
	str r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x22
	strh r1, [r0, 0x26]
	ldr r3, =0x00007b18
	adds r1, r2, r3
	subs r3, 0x4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, 5
	ldr r3, =0x06010000
	adds r0, r3
	str r0, [r1]
	ldr r0, =0x00007b12
	adds r2, r0
	ldrh r0, [r2]
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r2]
	b _08167742
	.pool
_08167714:
	lsls r1, r6, 13
	movs r0, 0xC1
	lsls r0, 2
	adds r1, r0
	adds r1, r3, r1
	ldr r2, =0x00007b18
	adds r0, r3, r2
	ldr r2, [r0]
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000400
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	lsls r0, r6, 7
	adds r0, 0x4
	adds r0, r3, r0
	ldr r2, =0x00007b12
	adds r1, r3, r2
	ldrh r1, [r1]
	movs r2, 0x20
	bl LoadPalette
_08167742:
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167608

	thumb_func_start sub_8167760
sub_8167760: @ 8167760
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	add r5, sp, 0x20
	add r4, sp, 0x38
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_81D321C
	mov r0, sp
	bl LoadSpriteSheets
	adds r0, r4, 0
	bl LoadSpritePalettes
	movs r4, 0
	ldr r1, =gUnknown_0203BCAC
	ldr r0, [r1]
	ldr r2, =0x00008040
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r5, 0
	add r2, sp, 0x50
	mov r9, r2
	add r2, sp, 0x58
	mov r10, r2
	cmp r4, r0
	bge _0816781C
	adds r5, r1, 0
	ldr r7, =gSprites
	movs r0, 0x1C
	adds r0, r7
	mov r8, r0
_081677AC:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r1, 0x80
	lsls r1, 12
	adds r2, r1
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xE2
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081677FC
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	strb r3, [r0]
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r1, r0, r7
	strh r4, [r1, 0x2E]
	add r0, r8
	ldr r1, =sub_8168180
	str r1, [r0]
	b _08167808
	.pool
_081677FC:
	ldr r0, [r5]
	ldr r1, =0x00007b06
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167808:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [r5]
	ldr r2, =0x00008040
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r4, r0
	blt _081677AC
_0816781C:
	movs r0, 0x67
	strh r0, [r6]
	cmp r4, 0x5
	bhi _0816788A
	ldr r5, =gUnknown_0203BCAC
	ldr r7, =gSprites
_08167828:
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xE6
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _08167874
	ldr r0, [r5]
	ldr r1, =0x00007b06
	adds r0, r1
	adds r0, r4
	strb r3, [r0]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x3]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x3]
	b _08167880
	.pool
_08167874:
	ldr r0, [r5]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167880:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x5
	bls _08167828
_0816788A:
	movs r0, 0x66
	strh r0, [r6]
	ldr r0, =sub_81681B4
	str r0, [r6, 0x14]
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 18
	movs r0, 0x80
	lsls r0, 12
	adds r2, r0
	asrs r2, 16
	adds r0, r6, 0
	movs r1, 0xDE
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _081678F4
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b06
	adds r0, r1
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
	b _08167902
	.pool
_081678F4:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007b06
	adds r0, r2
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_08167902:
	mov r0, r9
	mov r1, r10
	bl sub_81D32B0
	mov r0, r9
	bl LoadSpriteSheet
	mov r0, r10
	bl LoadSpritePalette
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167760

	thumb_func_start sub_8167930
sub_8167930: @ 8167930
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008048
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xB
	bls _08167944
	b _08167B78
_08167944:
	lsls r0, 2
	ldr r1, =_0816795C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816795C:
	.4byte _0816798C
	.4byte _08167A04
	.4byte _08167A38
	.4byte _08167A48
	.4byte _08167A5C
	.4byte _08167A74
	.4byte _08167A9C
	.4byte _08167AB0
	.4byte _08167AD4
	.4byte _08167AEC
	.4byte _08167B1C
	.4byte _08167B38
_0816798C:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
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
	movs r1, 0x88
	lsls r1, 6
	movs r0, 0x3
	movs r2, 0
	bl ChangeBgY
	ldr r1, =0x00007040
	movs r0, 0
	bl SetGpuReg
	movs r1, 0x91
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040b
	movs r0, 0x52
	bl SetGpuReg
	b _08167B7E
	.pool
_08167A04:
	ldr r4, =gUnknown_0203BCA4
	movs r0, 0xD0
	lsls r0, 5
	bl Alloc
	str r0, [r4]
	ldr r5, =gUnknown_0203BCA0
	movs r4, 0xA0
	lsls r4, 3
	adds r0, r4, 0
	bl Alloc
	str r0, [r5]
	ldr r5, =gUnknown_0203BCA8
	adds r0, r4, 0
	bl Alloc
	str r0, [r5]
	b _08167B7E
	.pool
_08167A38:
	ldr r0, =gUnknown_085DFB60
	ldr r1, =gUnknown_0203BCA8
	b _08167AA0
	.pool
_08167A48:
	ldr r1, =gUnknown_085DFA80
	movs r0, 0x3
	movs r2, 0xE0
	movs r3, 0
	bl LoadBgTiles
	b _08167B7E
	.pool
_08167A5C:
	ldr r0, =gUnknown_0203BCA8
	ldr r1, [r0]
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x3
	movs r3, 0
	bl LoadBgTilemap
	b _08167B7E
	.pool
_08167A74:
	ldr r0, =gUnknown_085DFA60
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b0e
	adds r0, r1
	ldr r1, =0x0000ffb0
	strh r1, [r0]
	b _08167B7E
	.pool
_08167A9C:
	ldr r0, =gUsePokeblockGraph_Gfx
	ldr r1, =gUnknown_0203BCA4
_08167AA0:
	ldr r1, [r1]
	bl LZ77UnCompVram
	b _08167B7E
	.pool
_08167AB0:
	ldr r0, =gUsePokeblockGraph_Tilemap
	ldr r1, =gUnknown_0203BCA0
	ldr r1, [r1]
	bl LZ77UnCompVram
	ldr r0, =gUsePokeblockGraph_Pal
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	b _08167B7E
	.pool
_08167AD4:
	ldr r0, =gUnknown_0203BCA4
	ldr r1, [r0]
	movs r2, 0xD0
	lsls r2, 5
	movs r3, 0xA0
	lsls r3, 2
	movs r0, 0x1
	bl LoadBgTiles
	b _08167B7E
	.pool
_08167AEC:
	ldr r0, =gUnknown_0203BCA0
	ldr r1, [r0]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUsePokeblockNatureWin_Pal
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0xD
	bl CopyToBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _08167B7E
	.pool
_08167B1C:
	ldr r0, =gUnknown_085DFC0C
	ldr r1, =gUnknown_0203BCAC
	ldr r1, [r1]
	ldr r2, =0x00007304
	adds r1, r2
	bl LZ77UnCompVram
	b _08167B7E
	.pool
_08167B38:
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r0, =0x00007304
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	ldr r0, =gUnknown_086231E8
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08623208
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x2
	bl sub_81D21DC
	b _08167B7E
	.pool
_08167B78:
	movs r0, 0
	strb r0, [r1]
	b _08167B8E
_08167B7E:
	ldr r0, =gUnknown_0203BCAC
	ldr r1, [r0]
	ldr r2, =0x00008048
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_08167B8E:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8167930

	thumb_func_start sub_8167BA0
sub_8167BA0: @ 8167BA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r7, =gUnknown_0203BCAC
	ldr r3, [r7]
	ldr r1, =0x00008041
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167C46
	lsls r2, r4, 6
	ldr r0, =0x00007b95
	adds r2, r0
	adds r2, r3, r2
	movs r0, 0x1
	str r0, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, [r7]
	ldr r6, =0x0000804a
	adds r0, r6
	ldr r1, =gText_NatureSlash
	bl StringCopy
	ldr r1, =gNatureNamePointers
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	bl StringCopy
	ldr r0, =gUnknown_085DFCC9
	str r0, [sp]
	str r5, [sp, 0x4]
	ldr r0, [r7]
	adds r0, r6
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized3
_08167C46:
	mov r2, r8
	cmp r2, 0
	beq _08167C84
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	b _08167C94
	.pool
_08167C84:
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_08167C94:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8167BA0

	thumb_func_start sub_8167CA0
sub_8167CA0: @ 8167CA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08167CC0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007fb5
	adds r0, r1
	b _08167CC8
	.pool
_08167CC0:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007fb4
	adds r0, r2
_08167CC8:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r5, =gUnknown_0203BCAC
	ldr r2, [r5]
	ldr r3, =0x00007c58
	adds r0, r2, r3
	ldr r4, =0x00007fb3
	adds r1, r2, r4
	movs r3, 0
	ldrsb r3, [r1, r3]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	ldr r4, =0x00007c6c
	adds r1, r4
	adds r1, r2, r1
	lsls r3, r6, 2
	adds r3, r6
	lsls r3, 2
	adds r3, r4
	adds r2, r3
	bl sub_81D1F84
	ldr r4, [r5]
	ldr r1, =0x00008041
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	mov r12, r2
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	cmp r7, 0
	beq _08167D98
	ldr r3, =0x00007fb4
	adds r0, r4, r3
	ldrb r1, [r0]
	subs r2, 0x8B
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	adds r3, 0x8D
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08167D58
	mov r4, r12
	adds r0, r1, r4
	ldrb r0, [r0]
_08167D58:
	subs r2, r0, 0x1
	ldr r0, =0x00008041
	adds r1, r0
	strb r2, [r1]
	ldr r1, =gUnknown_0203BCAC
	ldr r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0
	bne _08167D74
	ldr r1, =0x00008040
	adds r0, r3, r1
	ldrb r0, [r0]
_08167D74:
	subs r1, r0, 0x1
	b _08167E1E
	.pool
_08167D98:
	ldr r3, =0x00007fb5
	adds r0, r4, r3
	ldrb r1, [r0]
	ldr r2, =0x00007fb4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r5]
	adds r3, 0x8C
	adds r0, r2, r3
	ldrb r1, [r0]
	adds r4, 0x8D
	adds r0, r2, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bge _08167DEC
	adds r3, r1, 0x1
	b _08167DEE
	.pool
_08167DEC:
	movs r3, 0
_08167DEE:
	ldr r1, =0x00008041
	adds r0, r2, r1
	strb r3, [r0]
	ldr r2, =gUnknown_0203BCAC
	ldr r3, [r2]
	adds r1, r3, r1
	ldrb r1, [r1]
	ldr r4, =0x00008040
	adds r0, r3, r4
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r2, 0
	cmp r1, r0
	bge _08167E1C
	adds r1, 0x1
	b _08167E1E
	.pool
_08167E1C:
	movs r1, 0
_08167E1E:
	ldr r2, =0x00007b4c
	adds r0, r3, r2
	strb r1, [r0]
	adds r5, r6, 0
	ldr r0, [r5]
	ldr r3, =0x00008041
	adds r1, r0, r3
	ldrb r2, [r1]
	ldr r4, =0x00008040
	adds r1, r0, r4
	ldrb r1, [r1]
	subs r1, 0x1
	eors r2, r1
	negs r1, r2
	orrs r1, r2
	lsrs r4, r1, 31
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3520
	mov r2, r8
	cmp r2, 0
	bne _08167E70
	ldr r0, [r5]
	ldr r3, =0x00008044
	adds r0, r3
	ldr r1, =sub_8167EA4
	b _08167E90
	.pool
_08167E70:
	cmp r4, 0
	bne _08167E88
	ldr r0, [r5]
	ldr r4, =0x00008044
	adds r0, r4
	ldr r1, =sub_8167FA4
	b _08167E90
	.pool
_08167E88:
	ldr r0, [r6]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r1, =sub_8168048
_08167E90:
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167CA0

	thumb_func_start sub_8167EA4
sub_8167EA4: @ 8167EA4
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08167EE4
	cmp r0, 0x1
	bgt _08167EC8
	cmp r0, 0
	beq _08167ED2
	b _08167F9C
	.pool
_08167EC8:
	cmp r0, 0x2
	beq _08167F08
	cmp r0, 0x3
	beq _08167F48
	b _08167F9C
_08167ED2:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_8167608
	b _08167F2C
	.pool
_08167EE4:
	ldr r6, =0x00007fb3
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08167F30
	.pool
_08167F08:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08167F9C
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_08167F2C:
	ldr r1, [r4]
	adds r1, r5
_08167F30:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08167F9C
	.pool
_08167F48:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167F82
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08167F82:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08167F9E
	.pool
_08167F9C:
	movs r0, 0x1
_08167F9E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8167EA4

	thumb_func_start sub_8167FA4
sub_8167FA4: @ 8167FA4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r2, r1, r5
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08167FF0
	cmp r0, 0x1
	bgt _08167FC8
	cmp r0, 0
	beq _08167FD2
	b _0816803E
	.pool
_08167FC8:
	cmp r0, 0x2
	beq _08168014
	cmp r0, 0x3
	beq _08168038
	b _0816803E
_08167FD2:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r2, =0x00007b0e
	adds r1, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _0816803E
	b _08168024
	.pool
_08167FF0:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08168028
	.pool
_08168014:
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r2, =0x00007fb6
	adds r1, r2
	ldrb r1, [r1]
	bl sub_816753C
_08168024:
	ldr r1, [r4]
	adds r1, r5
_08168028:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816803E
	.pool
_08168038:
	movs r0, 0
	strb r0, [r2]
	b _08168040
_0816803E:
	movs r0, 0x1
_08168040:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8167FA4

	thumb_func_start sub_8168048
sub_8168048: @ 8168048
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081680A8
	cmp r0, 0x1
	bgt _0816806C
	cmp r0, 0
	beq _08168076
	b _08168160
	.pool
_0816806C:
	cmp r0, 0x2
	beq _081680CC
	cmp r0, 0x3
	beq _0816810C
	b _08168160
_08168076:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	bl sub_81D2074
	ldr r0, [r4]
	ldr r6, =0x00007b0e
	adds r0, r6
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r0, [r4]
	ldr r1, =0x00007fb3
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8167608
	b _081680F0
	.pool
_081680A8:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r6, =0x00008048
	adds r1, r6
	b _081680F4
	.pool
_081680CC:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_081680F0:
	ldr r1, [r4]
	adds r1, r5
_081680F4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08168160
	.pool
_0816810C:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08168146
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08168146:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08168162
	.pool
_08168160:
	movs r0, 0x1
_08168162:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8168048

	thumb_func_start sub_8168168
sub_8168168: @ 8168168
	ldr r1, =gUnknown_0203BCAC
	ldr r1, [r1]
	ldr r2, =0x00007b0e
	adds r1, r2
	ldrh r1, [r1]
	adds r1, 0x26
	strh r1, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_8168168

	thumb_func_start sub_8168180
sub_8168180: @ 8168180
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00008041
	adds r0, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _081681A8
	adds r0, r2, 0
	movs r1, 0
	bl StartSpriteAnim
	b _081681B0
	.pool
_081681A8:
	adds r0, r2, 0
	movs r1, 0x1
	bl StartSpriteAnim
_081681B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8168180

	thumb_func_start sub_81681B4
sub_81681B4: @ 81681B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _081681DC
	movs r0, 0x65
	b _081681DE
	.pool
_081681DC:
	movs r0, 0x66
_081681DE:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r4, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681B4

	thumb_func_start sub_81681F4
sub_81681F4: @ 81681F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	bl GetMonData
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00007fb3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r3, 0x3
	adds r0, r3
	adds r4, r0, r1
	cmp r2, 0xFF
	beq _0816823C
	adds r0, r2, 0
	movs r1, 0x1D
	bl __udivsi3
	b _0816823E
	.pool
_0816823C:
	movs r0, 0x9
_0816823E:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681F4

	thumb_func_start sub_8168248
sub_8168248: @ 8168248
	push {lr}
	sub sp, 0x10
	ldr r0, =gUnknown_085DFDB8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gUsePokeblockCondition_Gfx
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	adds r1, 0x1
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	add r0, sp, 0x8
	bl LoadSpritePalette
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168248

	thumb_func_start sub_8168294
sub_8168294: @ 8168294
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b44
	adds r7, r0, r1
	ldr r0, =gUnknown_085DFDA0
	mov r10, r0
	movs r6, 0
	movs r1, 0x40
	mov r9, r1
	movs r0, 0x60
	negs r0, r0
	mov r8, r0
_081682B6:
	mov r5, r9
	muls r5, r6
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x11
	lsls r2, r0, 16
	mov r0, r10
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081682FE
	ldr r0, =gSprites
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	movs r1, 0x8
	strh r1, [r4, 0x2E]
	movs r0, 0x20
	orrs r5, r0
	strh r5, [r4, 0x30]
	strh r6, [r4, 0x32]
	lsls r1, r6, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	lsls r0, r6, 2
	adds r0, r7
	str r4, [r0]
_081682FE:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _081682B6
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168294

	thumb_func_start sub_8168328
sub_8168328: @ 8168328
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r5, =0x00008048
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08168348
	cmp r0, 0x1
	beq _08168360
	b _0816836C
	.pool
_08168348:
	bl sub_8168248
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	b _0816836E
	.pool
_08168360:
	bl sub_8168294
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
_0816836C:
	movs r0, 0
_0816836E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8168328

	thumb_func_start sub_8168374
sub_8168374: @ 8168374
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	ldrh r1, [r2, 0x2E]
	adds r3, r0, r1
	strh r3, [r2, 0x20]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r4, r1
	bgt _08168398
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bge _081683A0
	cmp r4, r1
	blt _081683A8
_08168398:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bgt _081683A8
_081683A0:
	ldrh r0, [r2, 0x30]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081683A8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168374

	.align 2, 0 @ Don't pad with nop.
