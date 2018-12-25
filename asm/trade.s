	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/misc_constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_807A8D0
sub_807A8D0: @ 807A8D0
	push {r4-r6,lr}
	lsls r1, 16
	lsrs r5, r1, 16
	adds r6, r5, 0
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 23
	lsrs r4, r0, 31
	adds r0, r2, 0
	adds r1, r3, 0
	bl sub_807A7BC
	cmp r0, 0
	bne _0807A90A
	cmp r4, 0
	bne _0807A90E
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	bne _0807A900
	movs r0, 0x2
	b _0807A910
_0807A900:
	adds r0, r6, 0
	bl IsSpeciesInHoennDex
	cmp r0, 0
	bne _0807A90E
_0807A90A:
	movs r0, 0x1
	b _0807A910
_0807A90E:
	movs r0, 0
_0807A910:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_807A8D0

	thumb_func_start sub_807A918
sub_807A918: @ 807A918
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	movs r5, 0
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	bge _0807A95A
	mov r4, sp
_0807A934:
	movs r0, 0x64
	muls r0, r5
	adds r0, r6, r0
	movs r1, 0x41
	bl GetMonData
	str r0, [r4]
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0807A94E
	movs r0, 0
	str r0, [r4]
_0807A94E:
	adds r4, 0x4
	adds r5, 0x1
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	blt _0807A934
_0807A95A:
	movs r7, 0
	movs r6, 0x1
	movs r5, 0
	ldr r4, =gLinkPlayers
	b _0807A980
	.pool
_0807A96C:
	ldrb r0, [r4]
	subs r0, 0x4
	cmp r0, 0x1
	bhi _0807A978
	movs r7, 0
	b _0807A97C
_0807A978:
	movs r0, 0x1
	orrs r7, r0
_0807A97C:
	adds r4, 0x1C
	adds r5, 0x1
_0807A980:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _0807A96C
	movs r5, 0
	movs r4, 0
	b _0807A9B4
_0807A992:
	ldr r0, =gLinkPlayers
	adds r2, r4, r0
	ldrb r1, [r2, 0x10]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _0807A9A2
	movs r6, 0
_0807A9A2:
	cmp r7, 0
	beq _0807A9B0
	ldrb r0, [r2, 0x10]
	lsrs r0, 4
	cmp r0, 0
	beq _0807A9B0
	movs r6, 0
_0807A9B0:
	adds r4, 0x1C
	adds r5, 0x1
_0807A9B4:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _0807A992
	cmp r6, 0
	bne _0807A9EA
	mov r1, r8
	lsls r0, r1, 2
	mov r1, sp
	adds r4, r1, r0
	ldrh r0, [r4]
	bl IsSpeciesInHoennDex
	cmp r0, 0
	bne _0807A9E0
	movs r0, 0x2
	b _0807AA1A
	.pool
_0807A9E0:
	ldr r0, [r4]
	cmp r0, 0
	bne _0807A9EA
	movs r0, 0x3
	b _0807AA1A
_0807A9EA:
	movs r2, 0
	movs r5, 0
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r2, r0
	bge _0807AA0A
	adds r3, r0, 0
	mov r1, sp
_0807A9FA:
	cmp r8, r5
	beq _0807AA02
	ldr r0, [r1]
	adds r2, r0
_0807AA02:
	adds r1, 0x4
	adds r5, 0x1
	cmp r5, r3
	blt _0807A9FA
_0807AA0A:
	cmp r2, 0
	beq _0807AA18
	movs r0, 0
	b _0807AA1A
	.pool
_0807AA18:
	movs r0, 0x1
_0807AA1A:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807A918

	thumb_func_start sub_807AA28
sub_807AA28: @ 807AA28
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0807AA44
	movs r0, 0x17
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2E]
_0807AA44:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_807AA28

	thumb_func_start sub_807AA4C
sub_807AA4C: @ 807AA4C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0807AA76
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0807AA76
	movs r0, 0xC2
	bl PlaySE
	strh r5, [r4, 0x2E]
_0807AA76:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_807AA4C

	thumb_func_start sub_807AA7C
sub_807AA7C: @ 807AA7C
	push {lr}
	adds r2, r0, 0
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r1, 0
	bne _0807AAB2
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0807AA98
	strh r1, [r2, 0x2E]
_0807AA98:
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	lsls r0, 1
	ldr r1, =gUnknown_08338EA4
	adds r0, r1
	ldrb r1, [r2, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	lsls r1, 4
	adds r1, 0x4
	movs r2, 0x2
	bl LoadPalette
_0807AAB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807AA7C

	thumb_func_start sub_807AABC
sub_807AABC: @ 807AABC
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	adds r1, 0x1
	strh r1, [r2, 0x2E]
	ldrh r0, [r2, 0x26]
	adds r0, 0x1
	strh r0, [r2, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xA
	bne _0807AADA
	adds r0, r2, 0
	bl DestroySprite
_0807AADA:
	pop {r0}
	bx r0
	thumb_func_end sub_807AABC

	thumb_func_start sub_807AAE0
sub_807AAE0: @ 807AAE0
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	adds r1, 0x1
	strh r1, [r2, 0x2E]
	ldrh r0, [r2, 0x26]
	subs r0, 0x1
	strh r0, [r2, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xA
	bne _0807AAFE
	adds r0, r2, 0
	bl DestroySprite
_0807AAFE:
	pop {r0}
	bx r0
	thumb_func_end sub_807AAE0

	thumb_func_start sub_807AB04
sub_807AB04: @ 807AB04
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bne _0807AB20
	movs r0, 0xCC
	bl PlaySE
	movs r0, 0
	strh r0, [r4, 0x2E]
_0807AB20:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_807AB04

	thumb_func_start sub_807AB28
sub_807AB28: @ 807AB28
	push {r4,r5,lr}
	sub sp, 0x20
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xD4
	ldrh r1, [r0]
	lsls r1, 8
	adds r0, 0x2
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, 0x6
	movs r4, 0
	ldrsh r3, [r0, r4]
	adds r0, 0x2
	movs r5, 0
	ldrsh r0, [r0, r5]
	str r0, [sp]
	mov r4, r12
	adds r4, 0xE8
	movs r5, 0
	ldrsh r0, [r4, r5]
	str r0, [sp, 0x4]
	movs r5, 0
	ldrsh r0, [r4, r5]
	str r0, [sp, 0x8]
	mov r0, r12
	adds r0, 0xEC
	ldrh r0, [r0]
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	bl DoBgAffineSet
	add r0, sp, 0x10
	ldrh r1, [r0]
	movs r0, 0x20
	bl SetGpuReg
	add r0, sp, 0x10
	ldrh r1, [r0, 0x2]
	movs r0, 0x22
	bl SetGpuReg
	add r0, sp, 0x10
	ldrh r1, [r0, 0x4]
	movs r0, 0x24
	bl SetGpuReg
	add r0, sp, 0x10
	ldrh r1, [r0, 0x6]
	movs r0, 0x26
	bl SetGpuReg
	ldr r1, [sp, 0x18]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x28
	bl SetGpuReg
	ldr r1, [sp, 0x18]
	lsrs r1, 16
	movs r0, 0x2A
	bl SetGpuReg
	ldr r1, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x2C
	bl SetGpuReg
	ldr r1, [sp, 0x1C]
	lsrs r1, 16
	movs r0, 0x2E
	bl SetGpuReg
	add sp, 0x20
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807AB28

	thumb_func_start sub_807ABCC
sub_807ABCC: @ 807ABCC
	push {r4,lr}
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r0, 0xE0
	ldrh r1, [r0]
	movs r0, 0x16
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0xE2
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	cmp r1, 0
	bne _0807AC18
	ldr r0, [r4]
	adds r0, 0xE4
	ldrh r1, [r0]
	movs r0, 0x1A
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0xE6
	ldrh r1, [r0]
	movs r0, 0x18
	bl SetGpuReg
	b _0807AC1C
	.pool
_0807AC18:
	bl sub_807AB28
_0807AC1C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_807ABCC

	thumb_func_start sub_807AC24
sub_807AC24: @ 807AC24
	push {lr}
	bl sub_807ABCC
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_807AC24

	thumb_func_start sub_807AC3C
sub_807AC3C: @ 807AC3C
	push {r4,lr}
	ldr r3, =gUnknown_020322A0
	ldr r1, [r3]
	movs r0, 0x8A
	adds r0, r1
	mov r12, r0
	movs r2, 0
	movs r0, 0
	mov r4, r12
	strh r0, [r4]
	adds r1, 0x88
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, 0x89
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807AC3C

	thumb_func_start sub_807AC64
sub_807AC64: @ 807AC64
	push {r4,r5,lr}
	ldr r0, =gUnknown_020322A0
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x88
	adds r3, r2, 0
	adds r3, 0x89
	ldrb r1, [r1]
	adds r5, r0, 0
	ldrb r3, [r3]
	cmp r1, r3
	bne _0807AC8C
	adds r1, r2, 0
	adds r1, 0x8A
	ldrh r0, [r1]
	adds r0, 0x1
	b _0807AC92
	.pool
_0807AC8C:
	adds r1, r2, 0
	adds r1, 0x8A
	movs r0, 0
_0807AC92:
	strh r0, [r1]
	adds r4, r5, 0
	ldr r0, [r4]
	adds r0, 0x8A
	ldrh r1, [r0]
	movs r0, 0x96
	lsls r0, 1
	cmp r1, r0
	bls _0807ACC4
	bl CloseLink
	ldr r0, =CB2_LinkError
	bl SetMainCallback2
	ldr r1, [r4]
	adds r3, r1, 0
	adds r3, 0x8A
	movs r2, 0
	movs r0, 0
	strh r0, [r3]
	adds r1, 0x89
	strb r2, [r1]
	ldr r0, [r4]
	adds r0, 0x88
	strb r2, [r0]
_0807ACC4:
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x88
	ldrb r1, [r1]
	adds r0, 0x89
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807AC64

	thumb_func_start sub_807ACDC
sub_807ACDC: @ 807ACDC
	push {lr}
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807ACF0
	movs r0, 0
	b _0807ACF8
	.pool
_0807ACF0:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
_0807ACF8:
	pop {r1}
	bx r1
	thumb_func_end sub_807ACDC

	thumb_func_start sub_807ACFC
sub_807ACFC: @ 807ACFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	mov r8, r4
	cmp r6, 0
	bne _0807AD22
	ldr r0, =gUnknown_02032298
	ldrb r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	mov r8, r1
	movs r4, 0x1
_0807AD22:
	cmp r6, 0x1
	bne _0807AD40
	ldr r0, =gUnknown_02032298
	ldrb r0, [r0, 0x1]
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	mov r8, r1
	movs r4, 0x3
_0807AD40:
	cmp r5, 0
	beq _0807AD58
	cmp r5, 0x1
	beq _0807ADE0
	b _0807AE36
	.pool
_0807AD58:
	mov r0, r8
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, r8
	movs r1, 0
	bl GetMonData
	adds r7, r0, 0
	cmp r6, 0
	bne _0807AD94
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	adds r2, r5, 0
	adds r3, r7, 0
	bl HandleLoadSpecialPokePic_2
	movs r4, 0
	b _0807ADB2
	.pool
_0807AD94:
	lsls r0, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r2, [r1]
	lsls r4, r6, 1
	adds r1, r4, 0x1
	lsls r1, 2
	adds r2, 0x4
	adds r2, r1
	ldr r1, [r2]
	adds r2, r5, 0
	adds r3, r7, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
_0807ADB2:
	mov r0, r8
	bl GetMonSpritePalStruct
	bl LoadCompressedSpritePalette
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xF0
	adds r0, r4
	strh r5, [r0]
	lsls r0, r6, 2
	adds r1, 0x68
	adds r1, r0
	str r7, [r1]
	b _0807AE36
	.pool
_0807ADE0:
	mov r0, r8
	bl GetMonSpritePalStruct
	ldrh r0, [r0, 0x4]
	adds r1, r4, 0
	bl SetMultiuseSpriteTemplateToPokemon
	ldr r0, =gMultiuseSpriteTemplate
	movs r1, 0x78
	movs r2, 0x3C
	movs r3, 0x6
	bl CreateSprite
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	adds r1, 0x8E
	adds r1, r6
	strb r0, [r1]
	ldr r3, =gSprites
	ldr r0, [r4]
	adds r0, 0x8E
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x8E
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
_0807AE36:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807ACFC

	thumb_func_start sub_807AE50
sub_807AE50: @ 807AE50
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xC
	bls _0807AE66
	b _0807B116
_0807AE66:
	lsls r0, 2
	ldr r1, =_0807AE78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807AE78:
	.4byte _0807AEAC
	.4byte _0807AF58
	.4byte _0807AF9C
	.4byte _0807AFBC
	.4byte _0807B006
	.4byte _0807B034
	.4byte _0807B058
	.4byte _0807B070
	.4byte _0807B07A
	.4byte _0807B094
	.4byte _0807B0B0
	.4byte _0807B0D4
	.4byte _0807B0F0
_0807AEAC:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807AEC0
	ldr r1, =gLinkType
	ldr r2, =0x00001144
	adds r0, r2, 0
	strh r0, [r1]
	bl CloseLink
_0807AEC0:
	ldr r4, =gUnknown_020322A0
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4]
	bl AllocateMonSpritesGfx
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =sub_807AC24
	bl SetVBlankCallback
	bl sub_807B170
	bl sub_807AC3C
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8C
	strh r2, [r0]
	adds r0, 0x8
	strh r2, [r0]
	adds r1, 0xEE
	movs r0, 0x1
	strb r0, [r1]
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xD4
	movs r1, 0x40
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r0, 0x2
	strh r2, [r0]
	adds r0, 0x2
	strh r2, [r0]
	adds r1, r3, 0
	adds r1, 0xDC
	movs r0, 0x78
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x50
	strh r0, [r1]
	adds r0, r3, 0
	adds r0, 0xE8
	strh r5, [r0]
	adds r0, 0x4
	strh r2, [r0]
	b _0807B116
	.pool
_0807AF58:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r5, [r0]
	cmp r5, 0
	bne _0807AF90
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r0, 0xFA
	movs r1, 0x1
	strb r1, [r0]
	bl OpenLink
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	str r5, [r0, 0x64]
	b _0807B116
	.pool
_0807AF90:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x4
	strb r0, [r1]
	b _0807B116
_0807AF9C:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x3C
	bhi _0807AFAC
	b _0807B116
_0807AFAC:
	movs r0, 0
	str r0, [r1, 0x64]
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	b _0807B0E4
	.pool
_0807AFBC:
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	bne _0807AFC8
	b _0807B0DC
_0807AFC8:
	bl GetLinkPlayerCount_2
	adds r4, r0, 0
	bl sub_800AA48
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bcc _0807B000
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x1E
	bhi _0807AFEA
	b _0807B116
_0807AFEA:
	bl sub_800A620
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0807B0E4
	.pool
_0807B000:
	bl sub_807AC64
	b _0807B116
_0807B006:
	bl sub_807AC64
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807B014
	b _0807B116
_0807B014:
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0807B022
	b _0807B116
_0807B022:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0807B0E4
	.pool
_0807B034:
	ldr r2, =gUnknown_020322A0
	ldr r0, [r2]
	adds r0, 0x72
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0x73
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0x93
	strb r1, [r0]
	movs r0, 0
	bl sub_807ACFC
	b _0807B0DC
	.pool
_0807B058:
	movs r0, 0
	movs r1, 0x1
	bl sub_807ACFC
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0807B0E4
	.pool
_0807B070:
	movs r0, 0x1
	movs r1, 0
	bl sub_807ACFC
	b _0807B0DC
_0807B07A:
	movs r0, 0x1
	movs r1, 0x1
	bl sub_807ACFC
	bl sub_807B154
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0807B0E4
	.pool
_0807B094:
	bl sub_807BA94
	ldr r0, =gUnknown_08338D18
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338D20
	bl LoadSpritePalette
	b _0807B0DC
	.pool
_0807B0B0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0807B0E4
	.pool
_0807B0D4:
	bl sub_807B140
	bl sub_807BAD8
_0807B0DC:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_0807B0E4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0807B116
	.pool
_0807B0F0:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807B116
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B110
	bl sub_800E0E8
	movs r0, 0
	movs r1, 0
	bl CreateWirelessStatusIndicatorSprite
_0807B110:
	ldr r0, =sub_807EA2C
	bl SetMainCallback2
_0807B116:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807AE50

	thumb_func_start sub_807B140
sub_807B140: @ 807B140
	push {lr}
	movs r0, 0x5
	bl sub_807B62C
	movs r0, 0
	bl sub_807B62C
	pop {r0}
	bx r0
	thumb_func_end sub_807B140

	thumb_func_start sub_807B154
sub_807B154: @ 807B154
	push {lr}
	movs r0, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_807B154

	thumb_func_start sub_807B170
sub_807B170: @ 807B170
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x4
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08339014
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r5, 0x80
	lsls r5, 4
	adds r0, r5, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	adds r0, r5, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r5, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl DeactivateAllTextPrinters
	ldr r0, =gBattleTextboxTiles
	mov r10, r0
	movs r0, 0
	mov r9, r0
	str r0, [sp]
	mov r1, r10
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r0, =gBattleTextboxTilemap
	mov r8, r0
	ldr r4, =gDecompressionBuffer
	adds r1, r4, 0
	bl LZDecompressWram
	movs r0, 0
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r6, =gBattleTextboxPalette
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gUnknown_08338FFC
	bl InitWindows
	mov r0, r9
	str r0, [sp]
	movs r0, 0
	mov r1, r10
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	mov r0, r8
	adds r1, r4, 0
	bl LZDecompressWram
	movs r0, 0
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B170

	thumb_func_start sub_807B270
sub_807B270: @ 807B270
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xC
	bls _0807B288
	b _0807B43E
_0807B288:
	lsls r0, 2
	ldr r1, =_0807B29C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807B29C:
	.4byte _0807B2D0
	.4byte _0807B43E
	.4byte _0807B43E
	.4byte _0807B43E
	.4byte _0807B43E
	.4byte _0807B3AC
	.4byte _0807B3B6
	.4byte _0807B3C0
	.4byte _0807B3D0
	.4byte _0807B3F0
	.4byte _0807B40C
	.4byte _0807B414
	.4byte _0807B438
_0807B2D0:
	ldr r1, =gUnknown_02032298
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	movs r6, 0
	strb r0, [r1]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	ldr r4, =gLinkPlayers + 8
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringCopy
	ldr r5, =gEnemyParty
	adds r0, r5, 0
	movs r1, 0x7
	mov r2, sp
	bl GetMonData
	adds r0, r4, 0
	adds r0, 0x1C
	mov r1, sp
	bl StringCopy
	subs r4, 0x8
	movs r0, 0
	mov r8, r0
	movs r0, 0x2
	strh r0, [r4, 0x1A]
	adds r0, r5, 0
	movs r1, 0x3
	bl GetMonData
	strh r0, [r4, 0x36]
	ldr r4, =gUnknown_020322A0
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4]
	bl AllocateMonSpritesGfx
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, =sub_807AC24
	bl SetVBlankCallback
	bl sub_807B170
	ldr r0, [r4]
	adds r0, 0xEE
	mov r1, r8
	strb r1, [r0]
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x8C
	strh r6, [r0]
	adds r0, 0x8
	strh r6, [r0]
	adds r0, 0x40
	movs r1, 0x40
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r0, 0x2
	strh r6, [r0]
	adds r0, 0x2
	strh r6, [r0]
	adds r1, r2, 0
	adds r1, 0xDC
	movs r0, 0x78
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x50
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xE8
	strh r5, [r0]
	adds r0, 0x4
	strh r6, [r0]
	str r6, [r2, 0x64]
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	b _0807B43E
	.pool
_0807B3AC:
	movs r0, 0
	movs r1, 0
	bl sub_807ACFC
	b _0807B424
_0807B3B6:
	movs r0, 0
	movs r1, 0x1
	bl sub_807ACFC
	b _0807B424
_0807B3C0:
	movs r0, 0x1
	movs r1, 0
	bl sub_807ACFC
	movs r0, 0
	bl ShowBg
	b _0807B424
_0807B3D0:
	movs r0, 0x1
	movs r1, 0x1
	bl sub_807ACFC
	movs r0, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _0807B424
_0807B3F0:
	bl sub_807BA94
	ldr r0, =gUnknown_08338D18
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338D20
	bl LoadSpritePalette
	b _0807B424
	.pool
_0807B40C:
	movs r0, 0
	bl ShowBg
	b _0807B424
_0807B414:
	movs r0, 0x5
	bl sub_807B62C
	movs r0, 0
	bl sub_807B62C
	bl sub_807BAD8
_0807B424:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0807B43E
	.pool
_0807B438:
	ldr r0, =sub_807B60C
	bl SetMainCallback2
_0807B43E:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B270

	thumb_func_start sub_807B464
sub_807B464: @ 807B464
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0807B4B8
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r5, r0, 0
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x2
	bl GetSetPokedexFlag
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl HandleSetPokedexFlag
_0807B4B8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B464

	thumb_func_start sub_807B4C4
sub_807B4C4: @ 807B4C4
	push {lr}
	bl GetMultiplayerId
	pop {r0}
	bx r0
	thumb_func_end sub_807B4C4

	thumb_func_start sub_807B4D0
sub_807B4D0: @ 807B4D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	movs r5, 0x64
	mov r1, r9
	muls r1, r5
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r0, r7, 0
	movs r1, 0x40
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r1, r4, 0
	muls r1, r5
	ldr r0, =gEnemyParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x40
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r6, 0xFF
	beq _0807B52A
	ldr r0, =gSaveBlock1Ptr
	lsls r1, r6, 3
	adds r1, r6
	lsls r1, 2
	ldr r2, =0x00002be0
	adds r1, r2
	ldr r0, [r0]
	adds r0, r1
	bl ClearMailStruct
_0807B52A:
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r1, r7, 0
	movs r2, 0x64
	bl memcpy
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x64
	bl memcpy
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x64
	bl memcpy
	movs r1, 0x46
	mov r0, sp
	strb r1, [r0]
	adds r0, r7, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0807B566
	adds r0, r7, 0
	movs r1, 0x20
	mov r2, sp
	bl SetMonData
_0807B566:
	mov r0, r8
	cmp r0, 0xFF
	beq _0807B57C
	lsls r1, r0, 3
	add r1, r8
	lsls r1, 2
	ldr r0, =gUnknown_020321C0
	adds r1, r0
	adds r0, r7, 0
	bl GiveMailToMon2
_0807B57C:
	mov r0, r9
	bl sub_807B464
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B58E
	bl sub_807B4C4
_0807B58E:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B4D0

	thumb_func_start sub_807B5B8
sub_807B5B8: @ 807B5B8
	push {r4,lr}
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r0, 0x93
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807B5D0
	cmp r0, 0x2
	beq _0807B5F6
	b _0807B600
	.pool
_0807B5D0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0807B5F6
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	adds r1, 0x74
	movs r2, 0x14
	bl SendBlock
	ldr r1, [r4]
	adds r1, 0x93
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0807B5F6:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x93
	movs r1, 0
	strb r1, [r0]
_0807B600:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B5B8

	thumb_func_start sub_807B60C
sub_807B60C: @ 807B60C
	push {lr}
	bl sub_807BBC8
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_807B60C

	thumb_func_start sub_807B62C
sub_807B62C: @ 807B62C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	bls _0807B638
	b _0807BA68
_0807B638:
	lsls r0, 2
	ldr r1, =_0807B648
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807B648:
	.4byte _0807B668
	.4byte _0807B6DC
	.4byte _0807B784
	.4byte _0807B7F8
	.4byte _0807B840
	.4byte _0807B90C
	.4byte _0807B924
	.4byte _0807B9FC
_0807B668:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0xE4
	movs r0, 0
	strh r0, [r2]
	adds r1, 0xE6
	movs r0, 0xB4
	strh r0, [r1]
	movs r1, 0xAA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00005206
	movs r0, 0xC
	bl SetGpuReg
	ldr r0, =gTradeGba2_Pal
	movs r1, 0x10
	movs r2, 0x60
	bl LoadPalette
	ldr r3, =gTradeGba_Gfx
	ldr r4, =0x06004000
	movs r5, 0xA1
	lsls r5, 5
	ldr r1, =0x040000d4
	ldr r6, =0x80000800
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x80
	lsls r7, 24
_0807B6AA:
	str r3, [r1]
	str r4, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r2
	adds r4, r2
	subs r5, r2
	cmp r5, r2
	bhi _0807B6AA
	b _0807BA4C
	.pool
_0807B6DC:
	ldr r4, =gUnknown_020322A0
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xE2
	movs r0, 0
	strh r0, [r1]
	adds r2, 0xE0
	movs r1, 0xAE
	lsls r1, 1
	strh r1, [r2]
	movs r0, 0x16
	bl SetGpuReg
	ldr r1, =0x00008502
	movs r0, 0xA
	bl SetGpuReg
	ldr r1, =0x00009206
	movs r0, 0xC
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0xFA
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B724
	ldr r1, =gUnknown_083369A0
	b _0807B726
	.pool
_0807B724:
	ldr r1, =gUnknown_083359A0
_0807B726:
	ldr r2, =0x06002800
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000800
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	ldr r3, =gTradeGba_Gfx
	movs r4, 0xC0
	lsls r4, 19
	movs r5, 0xA1
	lsls r5, 5
	ldr r1, =0x040000d4
	ldr r6, =0x80000800
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x80
	lsls r7, 24
_0807B74A:
	str r3, [r1]
	str r4, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r2
	adds r4, r2
	subs r5, r2
	cmp r5, r2
	bhi _0807B74A
	str r3, [r1]
	str r4, [r1, 0x4]
	lsrs r0, r5, 1
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r1, 0x92
	lsls r1, 5
	b _0807B820
	.pool
_0807B784:
	ldr r0, =gUnknown_020322A0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xE0
	movs r1, 0
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r0, 0x18
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807B7C0
	ldr r1, =0x00001241
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gUnknown_083379A0
	ldr r1, =0x06002800
	bl LZ77UnCompVram
	movs r0, 0x8
	b _0807B7DA
	.pool
_0807B7C0:
	ldr r1, =0x00001241
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gUnknown_0832FFC0
	ldr r2, =0x06002800
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000400
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	movs r0, 0x1
_0807B7DA:
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	b _0807BA68
	.pool
_0807B7F8:
	ldr r0, =gUnknown_08337EA0
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08337EC0
	ldr r1, =0x06004000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_08338550
	ldr r1, =0x06009000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0xE4
	movs r1, 0x50
	strh r1, [r0]
	movs r1, 0xB2
	lsls r1, 5
_0807B820:
	movs r0, 0
	bl SetGpuReg
	b _0807BA68
	.pool
_0807B840:
	ldr r1, =0x00001441
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00001287
	movs r0, 0xC
	bl SetGpuReg
	ldr r0, =gUnknown_020322A0
	ldr r3, [r0]
	adds r1, r3, 0
	adds r1, 0xD4
	movs r2, 0
	movs r0, 0x40
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x5C
	strh r0, [r1]
	adds r1, 0x12
	movs r0, 0x20
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r1]
	adds r0, r3, 0
	adds r0, 0xEC
	strh r2, [r0]
	ldr r3, =gUnknown_08332F60
	ldr r4, =0x06004000
	movs r5, 0xA1
	lsls r5, 6
	ldr r1, =0x040000d4
	ldr r6, =0x80000800
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x80
	lsls r7, 24
_0807B88C:
	str r3, [r1]
	str r4, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r2
	adds r4, r2
	subs r5, r2
	cmp r5, r2
	bhi _0807B88C
	str r3, [r1]
	str r4, [r1, 0x4]
	lsrs r0, r5, 1
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0xFA
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B8EC
	ldr r1, =gUnknown_083357A0
	ldr r2, =0x06009000
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000080
	b _0807BA64
	.pool
_0807B8EC:
	ldr r1, =gUnknown_083358A0
	ldr r2, =0x06009000
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000080
	b _0807BA64
	.pool
_0807B90C:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xE0
	movs r2, 0
	strh r2, [r1]
	adds r0, 0xE2
	strh r2, [r0]
	b _0807BA68
	.pool
_0807B924:
	ldr r1, =0x00001441
	movs r0, 0
	bl SetGpuReg
	ldr r1, =0x00001287
	movs r0, 0xC
	bl SetGpuReg
	ldr r0, =gUnknown_020322A0
	ldr r3, [r0]
	adds r1, r3, 0
	adds r1, 0xD4
	movs r2, 0
	movs r0, 0x40
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x5C
	strh r0, [r1]
	adds r1, 0x12
	adds r0, 0xA4
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x80
	strh r0, [r1]
	subs r1, 0xE
	movs r0, 0x78
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x50
	strh r0, [r1]
	adds r0, r3, 0
	adds r0, 0xEC
	strh r2, [r0]
	ldr r3, =gUnknown_08332F60
	ldr r4, =0x06004000
	movs r5, 0xA1
	lsls r5, 6
	ldr r1, =0x040000d4
	ldr r6, =0x80000800
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x80
	lsls r7, 24
_0807B97A:
	str r3, [r1]
	str r4, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r2
	adds r4, r2
	subs r5, r2
	cmp r5, r2
	bhi _0807B97A
	str r3, [r1]
	str r4, [r1, 0x4]
	lsrs r0, r5, 1
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0xFA
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B9DC
	ldr r1, =gUnknown_083357A0
	ldr r2, =0x06009000
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000080
	b _0807BA64
	.pool
_0807B9DC:
	ldr r1, =gUnknown_083358A0
	ldr r2, =0x06009000
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000080
	b _0807BA64
	.pool
_0807B9FC:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xE4
	movs r2, 0
	strh r2, [r1]
	adds r0, 0xE6
	strh r2, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x00005206
	movs r0, 0xC
	bl SetGpuReg
	ldr r0, =gTradeGba2_Pal
	movs r1, 0x10
	movs r2, 0x60
	bl LoadPalette
	ldr r3, =gTradeGba_Gfx
	ldr r4, =0x06004000
	movs r5, 0xA1
	lsls r5, 5
	ldr r1, =0x040000d4
	ldr r6, =0x80000800
	movs r2, 0x80
	lsls r2, 5
	movs r7, 0x80
	lsls r7, 24
_0807BA3A:
	str r3, [r1]
	str r4, [r1, 0x4]
	str r6, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r2
	adds r4, r2
	subs r5, r2
	cmp r5, r2
	bhi _0807BA3A
_0807BA4C:
	str r3, [r1]
	str r4, [r1, 0x4]
	lsrs r0, r5, 1
	orrs r0, r7
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r1, =gUnknown_08331F60
	ldr r2, =0x06009000
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x80000800
_0807BA64:
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
_0807BA68:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807B62C

	thumb_func_start sub_807BA94
sub_807BA94: @ 807BA94
	push {lr}
	ldr r0, =gUnknown_08338D70
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338DC0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338DF4
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338E6C
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08338D78
	bl LoadSpritePalette
	ldr r0, =gUnknown_08338D80
	bl LoadSpritePalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807BA94

	thumb_func_start sub_807BAD8
sub_807BAD8: @ 807BAD8
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0xEE
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807BB68
	bl GetMultiplayerId
	lsls r0, 24
	ldr r3, =gStringVar1
	movs r2, 0x80
	lsls r2, 17
	eors r2, r0
	lsrs r2, 24
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, =gLinkPlayers + 8
	adds r1, r0
	adds r0, r3, 0
	bl StringCopy
	ldr r5, =gUnknown_02032298
	ldrb r0, [r5, 0x1]
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0x64
	muls r0, r4
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar3
	mov r1, sp
	bl StringCopy10
	ldrb r0, [r5]
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar2
	mov r1, sp
	bl StringCopy10
	b _0807BBA4
	.pool
_0807BB68:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 2
	ldr r0, =gIngameTrades
	adds r4, r0
	ldr r0, =gStringVar1
	adds r1, r4, 0
	adds r1, 0x2B
	bl StringCopy
	ldr r0, =gStringVar3
	adds r1, r4, 0
	bl StringCopy10
	ldr r0, =gSpecialVar_0x8005
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar2
	mov r1, sp
	bl StringCopy10
_0807BBA4:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807BAD8

	thumb_func_start sub_807BBC8
sub_807BBC8: @ 807BBC8
	push {lr}
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0xFA
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807BBE0
	bl sub_807CFC8
	b _0807BBE4
	.pool
_0807BBE0:
	bl sub_807BBEC
_0807BBE4:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_807BBC8

	thumb_func_start sub_807BBEC
sub_807BBEC: @ 807BBEC
	push {r4-r7,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r1, 0x94
	ldrh r5, [r1]
	ldr r1, =0x0000010b
	adds r7, r0, 0
	cmp r5, r1
	bls _0807BC04
	bl _0807CFB4
_0807BC04:
	lsls r0, r5, 2
	ldr r1, =_0807BC1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807BC1C:
	.4byte _0807C04C
	.4byte _0807C0C4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807C120
	.4byte _0807C168
	.4byte _0807C1DC
	.4byte _0807CFB4
	.4byte _0807C248
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807C26C
	.4byte _0807C29C
	.4byte _0807C2AE
	.4byte _0807C2D0
	.4byte _0807C318
	.4byte _0807C348
	.4byte _0807C390
	.4byte _0807C3E0
	.4byte _0807C434
	.4byte _0807C4B8
	.4byte _0807C4DC
	.4byte _0807C528
	.4byte _0807C574
	.4byte _0807C5D0
	.4byte _0807C630
	.4byte _0807C644
	.4byte _0807C658
	.4byte _0807C66C
	.4byte _0807C794
	.4byte _0807C864
	.4byte _0807C8EC
	.4byte _0807C964
	.4byte _0807C974
	.4byte _0807C994
	.4byte _0807C9E4
	.4byte _0807CA02
	.4byte _0807CA40
	.4byte _0807CA50
	.4byte _0807CAC8
	.4byte _0807CFB4
	.4byte _0807CAF0
	.4byte _0807CB30
	.4byte _0807CB70
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CB90
	.4byte _0807CBB8
	.4byte _0807CBD4
	.4byte _0807CBF4
	.4byte _0807CC9C
	.4byte _0807CCD0
	.4byte _0807CD1C
	.4byte _0807CDDC
	.4byte _0807CE54
	.4byte _0807CEA0
	.4byte _0807CEB0
	.4byte _0807CEB6
	.4byte _0807CEDC
	.4byte _0807CF38
	.4byte _0807CF5C
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CE18
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807C460
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CFB4
	.4byte _0807CE38
_0807C04C:
	ldr r3, =gSprites
	ldr r0, [r7]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r4, [r7]
	adds r2, r4, 0
	adds r2, 0x8E
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =0x0000ff4c
	strh r1, [r0, 0x24]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldr r2, =gMonFrontPicCoords
	adds r0, r4, 0
	adds r0, 0xF0
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	strh r0, [r1, 0x26]
	adds r1, r4, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	bl GetCurrentMapMusic
	ldr r1, [r7]
	adds r1, 0xF4
	strh r0, [r1]
	ldr r0, =0x00000179
	bl PlayNewMapMusic
	bl _0807CFB4
	.pool
_0807C0C4:
	ldr r5, [r7]
	adds r6, r5, 0
	adds r6, 0xE6
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	ble _0807C0F8
	ldr r2, =gSprites
	adds r0, r5, 0
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	adds r1, 0x3
	strh r1, [r0, 0x24]
	ldrh r0, [r6]
	subs r0, 0x3
	strh r0, [r6]
	bl _0807CFB4
	.pool
_0807C0F8:
	ldr r2, =gSprites
	adds r0, r5, 0
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	strh r1, [r6]
	adds r1, r5, 0
	adds r1, 0x94
	movs r0, 0xA
	strh r0, [r1]
	bl _0807CFB4
	.pool
_0807C120:
	ldr r4, =gStringVar4
	ldr r1, =gText_XWillBeSentToY
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF0
	ldrh r1, [r2]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _0807C14E
	adds r0, r1, 0
	movs r1, 0
	bl PlayCry1
_0807C14E:
	ldr r3, [r4]
	adds r1, r3, 0
	adds r1, 0x94
	movs r2, 0
	movs r0, 0xB
	bl _0807CE06
	.pool
_0807C168:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x50
	beq _0807C178
	bl _0807CFB4
_0807C178:
	adds r0, r1, 0
	adds r0, 0x8E
	ldrb r0, [r0]
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x14
	str r2, [sp, 0x8]
	ldr r2, =0x000fffff
	str r2, [sp, 0xC]
	movs r2, 0x78
	movs r3, 0x20
	bl sub_807671C
	ldr r1, [r7]
	adds r1, 0xD2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_ByeByeVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	bl _0807CFB4
	.pool
_0807C1DC:
	ldr r5, =gSprites
	ldr r0, [r7]
	adds r0, 0xD2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r5, 0
	adds r4, 0x1C
	adds r0, r4
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _0807C1FC
	bl _0807CFB4
_0807C1FC:
	ldr r0, =gSpriteTemplate_8338D28
	movs r1, 0x78
	movs r2, 0x20
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0xD3
	strb r0, [r1]
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_807E5D8
	str r1, [r0]
	adds r2, 0xD2
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	ldr r1, [r7]
	bl _0807CF4C
	.pool
_0807C248:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x14
	strh r1, [r0]
	bl _0807CFB4
	.pool
_0807C26C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807C27C
	bl _0807CFB4
_0807C27C:
	movs r0, 0x4
	bl sub_807B62C
	movs r0, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	bl _0807CF48
	.pool
_0807C29C:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl _0807CF44
_0807C2AE:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807C2BE
	bl _0807CFB4
_0807C2BE:
	ldr r0, [r7]
	adds r0, 0x94
	movs r1, 0x17
	strh r1, [r0]
	bl _0807CFB4
	.pool
_0807C2D0:
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0xEA
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bls _0807C2F0
	adds r0, r1, 0
	subs r0, 0x34
	strh r0, [r2]
	b _0807C30C
	.pool
_0807C2F0:
	movs r0, 0x1
	bl sub_807B62C
	ldr r3, [r4]
	adds r1, r3, 0
	adds r1, 0xEA
	movs r2, 0
	movs r0, 0x80
	strh r0, [r1]
	subs r1, 0x56
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	str r2, [r3, 0x64]
_0807C30C:
	ldr r0, =gUnknown_020322A0
	ldr r4, [r0]
	bl _0807CB5C
	.pool
_0807C318:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x14
	bhi _0807C328
	bl _0807CFB4
_0807C328:
	bl sub_807AB28
	ldr r0, =gSpriteTemplate_8338E74
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x91
	strb r0, [r1]
	ldr r1, [r7]
	bl _0807CF4C
	.pool
_0807C348:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	blt _0807C368
	bl _0807CFB4
_0807C368:
	adds r0, r1, 0
	bl DestroySprite
	movs r1, 0xC8
	lsls r1, 3
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000040c
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, [r7]
	bl _0807CF4C
	.pool
_0807C390:
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xE0
	ldrh r1, [r0]
	subs r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	movs r0, 0x9E
	lsls r0, 17
	cmp r1, r0
	bne _0807C3B0
	adds r1, r2, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807C3B0:
	ldr r0, [r7]
	adds r0, 0xE0
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	beq _0807C3C4
	bl _0807CFB4
_0807C3C4:
	ldr r0, =gSpriteTemplate_8338DFC
	movs r1, 0x80
	movs r2, 0x41
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x92
	strb r0, [r1]
	bl _0807CFB4
	.pool
_0807C3E0:
	ldr r0, =gUnknown_08338D88
	movs r1, 0x80
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	adds r1, 0x90
	strb r0, [r1]
	ldr r0, =gSpriteTemplate_8338DC8
	movs r1, 0x80
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, [r4]
	bl _0807CF4C
	.pool
_0807C434:
	ldr r2, [r7]
	adds r1, r2, 0
	adds r1, 0xE0
	ldrh r0, [r1]
	subs r0, 0x2
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA6
	bne _0807C44E
	subs r1, 0x4C
	movs r0, 0xC8
	strh r0, [r1]
_0807C44E:
	ldr r1, =0x00001241
	movs r0, 0
	bl SetGpuReg
	bl _0807CFB4
	.pool
_0807C460:
	ldr r2, =gSprites
	ldr r4, [r7]
	adds r3, r4, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x2
	strh r1, [r0, 0x22]
	adds r0, r4, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x2
	strh r1, [r0, 0x22]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x22
	ldrsh r1, [r0, r3]
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _0807C4A6
	bl _0807CFB4
_0807C4A6:
	adds r1, r4, 0
	adds r1, 0x94
	movs r0, 0x1D
	strh r0, [r1]
	bl _0807CFB4
	.pool
_0807C4B8:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x1E
	strh r1, [r0]
	bl _0807CFB4
	.pool
_0807C4DC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807C4EC
	bl _0807CFB4
_0807C4EC:
	ldr r0, [r7]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0x2
	bl sub_807B62C
	ldr r1, [r7]
	bl _0807CF4C
	.pool
_0807C528:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r5, =gSpriteTemplate_8338DC8
	adds r0, r5, 0
	movs r1, 0x6F
	movs r2, 0xAA
	movs r3, 0
	bl CreateSprite
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	adds r1, 0x90
	strb r0, [r1]
	movs r2, 0xA
	negs r2, r2
	adds r0, r5, 0
	movs r1, 0x81
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, 0x91
	strb r0, [r1]
	ldr r1, [r4]
	bl _0807CF4C
	.pool
_0807C574:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807C592
	movs r0, 0x2E
	bl PlaySE
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807C592:
	ldr r3, =gSprites
	ldr r0, =gUnknown_020322A0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r2, 0x91
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	bl _0807CFB4
	.pool
_0807C5D0:
	ldr r5, =gSprites
	ldr r4, [r7]
	adds r2, r4, 0
	adds r2, 0x90
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r6, r4, 0
	adds r6, 0x91
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r5
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	movs r0, 0x5A
	negs r0, r0
	cmp r1, r0
	ble _0807C616
	bl _0807CFB4
_0807C616:
	movs r2, 0x1
	strh r2, [r3, 0x30]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x30]
	adds r1, r4, 0
	bl _0807CF4C
	.pool
_0807C630:
	ldr r2, =0x0000ffff
	movs r0, 0x1
	movs r1, 0x10
	bl BlendPalettes
	bl _0807CF48
	.pool
_0807C644:
	ldr r2, =0x0000ffff
	movs r0, 0x1
	movs r1, 0
	bl BlendPalettes
	bl _0807CF48
	.pool
_0807C658:
	ldr r2, =0x0000ffff
	movs r0, 0x1
	movs r1, 0x10
	bl BlendPalettes
	bl _0807CF48
	.pool
_0807C66C:
	ldr r5, =gUnknown_020322A0
	ldr r0, [r5]
	adds r0, 0xF0
	ldrh r0, [r0]
	bl IsMonSpriteNotFlipped
	lsls r0, 24
	cmp r0, 0
	bne _0807C6E4
	ldr r4, =gSprites
	ldr r2, [r5]
	adds r2, 0x8E
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gSpriteAffineAnimTable_8338ECC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x3
	bl CalcCenterToCornerVec
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	b _0807C6FA
	.pool
_0807C6E4:
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAffineAnim
_0807C6FA:
	ldr r5, =gUnknown_020322A0
	ldr r0, [r5]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r2, [r5]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x3C
	strh r1, [r0, 0x20]
	adds r2, 0x8F
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xB4
	strh r1, [r0, 0x20]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xC0
	strh r1, [r0, 0x22]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x22]
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r1, [r5]
	bl _0807CF4C
	.pool
_0807C794:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	movs r5, 0
	strh r1, [r0, 0x26]
	adds r2, 0x8F
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x26]
	adds r0, 0xA3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0807C7DC
	movs r0, 0x2D
	bl PlaySE
_0807C7DC:
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0x26
	ldrsh r1, [r0, r6]
	movs r0, 0xDE
	negs r0, r0
	cmp r1, r0
	blt _0807C7FC
	bl _0807CFB4
_0807C7FC:
	adds r0, r2, 0
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x30]
	adds r0, r2, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x30]
	adds r1, r2, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldr r2, =0x0000ffff
	movs r0, 0x1
	movs r1, 0
	bl BlendPalettes
	b _0807CFB4
	.pool
_0807C864:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r2, 0x91
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	movs r0, 0xDE
	negs r0, r0
	cmp r1, r0
	ble _0807C8A6
	b _0807CFB4
_0807C8A6:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0x94
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x90
	ldrb r1, [r1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	b _0807CFB4
	.pool
_0807C8EC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807C8FA
	b _0807CFB4
_0807C8FA:
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x1
	bl sub_807B62C
	ldr r0, [r7]
	adds r0, 0xE0
	movs r1, 0xA6
	strh r1, [r0]
	ldr r0, =gUnknown_08338D88
	movs r4, 0x14
	negs r4, r4
	movs r1, 0x80
	adds r2, r4, 0
	movs r3, 0x3
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x90
	strb r0, [r1]
	ldr r0, =gSpriteTemplate_8338DC8
	movs r1, 0x80
	adds r2, r4, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	b _0807CFB4
	.pool
_0807C964:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	b _0807CF44
_0807C974:
	movs r1, 0x92
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807C98C
	b _0807CFB4
_0807C98C:
	b _0807CF48
	.pool
_0807C994:
	ldr r2, =gSprites
	ldr r4, [r7]
	adds r3, r4, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	adds r0, r4, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x26
	ldrsh r1, [r0, r3]
	movs r6, 0x22
	ldrsh r0, [r0, r6]
	adds r1, r0
	cmp r1, 0x40
	beq _0807C9DA
	b _0807CFB4
_0807C9DA:
	adds r1, r4, 0
	b _0807CF4C
	.pool
_0807C9E4:
	ldr r1, [r7]
	adds r5, r1, 0
	adds r5, 0xE0
	ldrh r0, [r5]
	adds r0, 0x2
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x9E
	lsls r6, 1
	cmp r0, r6
	bgt _0807C9FE
	b _0807CFB4
_0807C9FE:
	strh r6, [r5]
	b _0807CF4C
_0807CA02:
	ldr r0, [r7]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r3, [r7]
	adds r2, r3, 0
	adds r2, 0x94
	ldrh r0, [r2]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r2]
	str r1, [r3, 0x64]
	b _0807CFB4
	.pool
_0807CA40:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0xA
	beq _0807CA4E
	b _0807CFB4
_0807CA4E:
	b _0807CF4C
_0807CA50:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0xE0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0xAE
	lsls r3, 1
	cmp r0, r3
	ble _0807CA72
	strh r3, [r2]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807CA72:
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xE0
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	beq _0807CA86
	b _0807CFB4
_0807CA86:
	adds r0, r2, 0
	adds r0, 0xFA
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807CA92
	b _0807CFB4
_0807CA92:
	ldr r0, =gSpriteTemplate_8338DFC
	movs r1, 0x80
	movs r2, 0x41
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x92
	strb r0, [r1]
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0x92
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_807AAE0
	str r1, [r0]
	b _0807CFB4
	.pool
_0807CAC8:
	ldr r0, =gSpriteTemplate_8338E74
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_020322A0
	ldr r1, [r2]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, 0x94
	movs r1, 0x32
	strh r1, [r0]
	b _0807CFB4
	.pool
_0807CAF0:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	blt _0807CB0E
	b _0807CFB4
_0807CB0E:
	adds r0, r1, 0
	bl DestroySprite
	movs r0, 0x6
	bl sub_807B62C
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x9F
	bl PlaySE
	b _0807CFB4
	.pool
_0807CB30:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0xEA
	ldrh r3, [r2]
	ldr r0, =0x000003ff
	cmp r3, r0
	bhi _0807CB4C
	adds r0, r3, 0
	adds r0, 0x34
	strh r0, [r2]
	b _0807CB5A
	.pool
_0807CB4C:
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r2]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807CB5A:
	ldr r4, [r7]
_0807CB5C:
	adds r0, r4, 0
	adds r0, 0xEA
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	bl __divsi3
	adds r4, 0xE8
	strh r0, [r4]
	b _0807CFB4
_0807CB70:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x3C
	strh r1, [r0]
	b _0807CFB4
	.pool
_0807CB90:
	ldr r4, =gPaletteFade
	ldrb r1, [r4, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807CB9E
	b _0807CFB4
_0807CB9E:
	movs r0, 0x5
	bl sub_807B62C
	movs r0, 0x7
	bl sub_807B62C
	ldrb r0, [r4, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4, 0x8]
	b _0807CF48
	.pool
_0807CBB8:
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	b _0807CF44
	.pool
_0807CBD4:
	movs r1, 0xA2
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807CBEC
	b _0807CFB4
_0807CBEC:
	b _0807CF48
	.pool
_0807CBF4:
	ldr r0, =gSpriteTemplate_8338D28
	movs r2, 0x8
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	ldr r5, =gUnknown_020322A0
	ldr r1, [r5]
	adds r1, 0xD3
	movs r6, 0
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r2, [r5]
	adds r2, 0xD3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x4A
	strh r1, [r0, 0x34]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_807E6AC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldr r0, [r5]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	ldr r2, =0x0000ffff
	movs r1, 0x10
	bl BlendPalettes
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	str r6, [r2, 0x64]
	b _0807CFB4
	.pool
_0807CC9C:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	b _0807CF4C
	.pool
_0807CCD0:
	ldr r2, =gSprites
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _0807CCEE
	b _0807CFB4
_0807CCEE:
	adds r0, r3, 0
	adds r0, 0xF2
	ldrh r2, [r0]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x10]
	ldr r3, [r3, 0x6C]
	bl HandleLoadSpecialPokePic_2
	ldr r1, [r7]
	b _0807CF4C
	.pool
_0807CD1C:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r6, r2, 0
	adds r6, 0x8F
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r5, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	ldrb r0, [r6]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldr r3, =gMonFrontPicCoords
	adds r2, 0xF2
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	adds r0, 0x3C
	strh r0, [r1, 0x22]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x24]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x26]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAnim
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0x8F
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x14
	str r2, [sp, 0x8]
	ldr r2, =0x000fffff
	str r2, [sp, 0xC]
	adds r3, 0xF2
	ldrh r2, [r3]
	str r2, [sp, 0x10]
	movs r2, 0x78
	movs r3, 0x54
	bl CreatePokeballSpriteToReleaseMon
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, [r7]
	b _0807CF4C
	.pool
_0807CDDC:
	movs r1, 0xAA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gStringVar4
	ldr r1, =gText_XSentOverY
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r0, =gUnknown_020322A0
	ldr r3, [r0]
	adds r1, r3, 0
	adds r1, 0x94
	movs r2, 0
	movs r0, 0xA7
_0807CE06:
	strh r0, [r1]
	str r2, [r3, 0x64]
	b _0807CFB4
	.pool
_0807CE18:
	ldr r3, [r7]
	ldr r0, [r3, 0x64]
	adds r0, 0x1
	str r0, [r3, 0x64]
	cmp r0, 0x3C
	bhi _0807CE26
	b _0807CFB4
_0807CE26:
	adds r0, r3, 0
	adds r0, 0x94
	movs r2, 0
	ldr r1, =0x0000010b
	strh r1, [r0]
	str r2, [r3, 0x64]
	b _0807CFB4
	.pool
_0807CE38:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0807CE44
	b _0807CFB4
_0807CE44:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x44
	strh r1, [r0]
	b _0807CFB4
	.pool
_0807CE54:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0xA
	bne _0807CE66
	ldr r0, =0x00000173
	bl PlayFanfare
_0807CE66:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	cmp r0, 0xFA
	beq _0807CE70
	b _0807CFB4
_0807CE70:
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_TakeGoodCareOfX
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r0, [r7]
	str r5, [r0, 0x64]
	b _0807CFB4
	.pool
_0807CEA0:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x3C
	beq _0807CEAE
	b _0807CFB4
_0807CEAE:
	b _0807CF4C
_0807CEB0:
	bl sub_807F14C
	b _0807CF48
_0807CEB6:
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xEE
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807CEC6
	movs r0, 0x1
	b _0807CFB6
_0807CEC6:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807CFB4
	adds r1, r2, 0
	b _0807CF4C
	.pool
_0807CEDC:
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
	movs r1, 0
	bl sub_807B4D0
	ldr r1, =gCB2_AfterEvolution
	ldr r0, =sub_807B60C
	str r0, [r1]
	ldr r7, =gUnknown_02032298
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0807CF48
	ldrb r3, [r7]
	adds r0, r3, 0
	muls r0, r6
	adds r0, r5
	ldr r1, =gUnknown_020322A0
	ldr r1, [r1]
	adds r1, 0x8F
	ldrb r2, [r1]
	adds r1, r4, 0
	bl TradeEvolutionScene
	b _0807CF48
	.pool
_0807CF38:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
_0807CF44:
	bl BeginNormalPaletteFade
_0807CF48:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
_0807CF4C:
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0807CFB4
	.pool
_0807CF5C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0807CFB4
	ldr r0, [r7]
	adds r0, 0xF4
	ldrh r0, [r0]
	bl PlayNewMapMusic
	ldr r0, [r7]
	cmp r0, 0
	beq _0807CFAA
	bl FreeAllWindowBuffers
	movs r0, 0x3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r0, [r7]
	bl Free
	str r4, [r7]
_0807CFAA:
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	bl sub_807E784
_0807CFB4:
	movs r0, 0
_0807CFB6:
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_807BBEC

	thumb_func_start sub_807CFC8
sub_807CFC8: @ 807CFC8
	push {r4-r7,lr}
	sub sp, 0x14
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r1, 0x94
	ldrh r5, [r1]
	ldr r1, =0x0000010b
	adds r7, r0, 0
	cmp r5, r1
	bls _0807CFE0
	bl _0807E400
_0807CFE0:
	lsls r0, r5, 2
	ldr r1, =_0807CFF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807CFF8:
	.4byte _0807D428
	.4byte _0807D4A0
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807D4FC
	.4byte _0807D544
	.4byte _0807D5B8
	.4byte _0807E400
	.4byte _0807D624
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807D648
	.4byte _0807D678
	.4byte _0807D68A
	.4byte _0807D6AC
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807D7A4
	.4byte _0807D7C4
	.4byte _0807D830
	.4byte _0807D8B4
	.4byte _0807D8D8
	.4byte _0807D924
	.4byte _0807D970
	.4byte _0807D9CC
	.4byte _0807DA38
	.4byte _0807DA4C
	.4byte _0807DA60
	.4byte _0807DA74
	.4byte _0807DB9C
	.4byte _0807DC6C
	.4byte _0807DCF4
	.4byte _0807DD94
	.4byte _0807DDA4
	.4byte _0807DDC4
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807DEE8
	.4byte _0807DEF8
	.4byte _0807DF16
	.4byte _0807E400
	.4byte _0807DF3C
	.4byte _0807DF7C
	.4byte _0807DFBC
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807DFDC
	.4byte _0807E004
	.4byte _0807E020
	.4byte _0807E040
	.4byte _0807E0E8
	.4byte _0807E11C
	.4byte _0807E168
	.4byte _0807E228
	.4byte _0807E2A0
	.4byte _0807E2EC
	.4byte _0807E2FC
	.4byte _0807E302
	.4byte _0807E328
	.4byte _0807E384
	.4byte _0807E3A8
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807D6F4
	.4byte _0807D728
	.4byte _0807D77C
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807DE1C
	.4byte _0807DE84
	.4byte _0807DEC0
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E264
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807D85C
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E400
	.4byte _0807E284
_0807D428:
	ldr r3, =gSprites
	ldr r0, [r7]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r4, [r7]
	adds r2, r4, 0
	adds r2, 0x8E
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =0x0000ff4c
	strh r1, [r0, 0x24]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldr r2, =gMonFrontPicCoords
	adds r0, r4, 0
	adds r0, 0xF0
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	strh r0, [r1, 0x26]
	adds r1, r4, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	bl GetCurrentMapMusic
	ldr r1, [r7]
	adds r1, 0xF4
	strh r0, [r1]
	ldr r0, =0x00000179
	bl PlayNewMapMusic
	bl _0807E400
	.pool
_0807D4A0:
	ldr r5, [r7]
	adds r6, r5, 0
	adds r6, 0xE6
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	ble _0807D4D4
	ldr r2, =gSprites
	adds r0, r5, 0
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	adds r1, 0x3
	strh r1, [r0, 0x24]
	ldrh r0, [r6]
	subs r0, 0x3
	strh r0, [r6]
	bl _0807E400
	.pool
_0807D4D4:
	ldr r2, =gSprites
	adds r0, r5, 0
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	strh r1, [r6]
	adds r1, r5, 0
	adds r1, 0x94
	movs r0, 0xA
	strh r0, [r1]
	bl _0807E400
	.pool
_0807D4FC:
	ldr r4, =gStringVar4
	ldr r1, =gText_XWillBeSentToY
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF0
	ldrh r1, [r2]
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _0807D52A
	adds r0, r1, 0
	movs r1, 0
	bl PlayCry1
_0807D52A:
	ldr r3, [r4]
	adds r1, r3, 0
	adds r1, 0x94
	movs r2, 0
	movs r0, 0xB
	bl _0807E252
	.pool
_0807D544:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x50
	beq _0807D554
	bl _0807E400
_0807D554:
	adds r0, r1, 0
	adds r0, 0x8E
	ldrb r0, [r0]
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x14
	str r2, [sp, 0x8]
	ldr r2, =0x000fffff
	str r2, [sp, 0xC]
	movs r2, 0x78
	movs r3, 0x20
	bl sub_807671C
	ldr r1, [r7]
	adds r1, 0xD2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_ByeByeVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	bl _0807E400
	.pool
_0807D5B8:
	ldr r5, =gSprites
	ldr r0, [r7]
	adds r0, 0xD2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r5, 0
	adds r4, 0x1C
	adds r0, r4
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _0807D5D8
	bl _0807E400
_0807D5D8:
	ldr r0, =gSpriteTemplate_8338D28
	movs r1, 0x78
	movs r2, 0x20
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0xD3
	strb r0, [r1]
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_807E5D8
	str r1, [r0]
	adds r2, 0xD2
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	ldr r1, [r7]
	bl _0807E398
	.pool
_0807D624:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x14
	strh r1, [r0]
	bl _0807E400
	.pool
_0807D648:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807D658
	bl _0807E400
_0807D658:
	movs r0, 0x4
	bl sub_807B62C
	movs r0, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	bl _0807E394
	.pool
_0807D678:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl _0807E390
_0807D68A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807D69A
	bl _0807E400
_0807D69A:
	ldr r0, [r7]
	adds r0, 0x94
	movs r1, 0x17
	strh r1, [r0]
	bl _0807E400
	.pool
_0807D6AC:
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r2, r0, 0
	adds r2, 0xEA
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bls _0807D6CC
	adds r0, r1, 0
	subs r0, 0x34
	strh r0, [r2]
	b _0807D6E6
	.pool
_0807D6CC:
	movs r0, 0x1
	bl sub_807B62C
	ldr r3, [r4]
	adds r1, r3, 0
	adds r1, 0xEA
	movs r2, 0
	movs r0, 0x80
	strh r0, [r1]
	subs r1, 0x56
	movs r0, 0x7C
	strh r0, [r1]
	str r2, [r3, 0x64]
_0807D6E6:
	ldr r0, =gUnknown_020322A0
	ldr r4, [r0]
	bl _0807DFA8
	.pool
_0807D6F4:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x14
	bhi _0807D704
	bl _0807E400
_0807D704:
	movs r0, 0x3
	bl sub_807B62C
	ldr r0, =gSpriteTemplate_8338E8C
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x91
	strb r0, [r1]
	ldr r1, [r7]
	bl _0807E398
	.pool
_0807D728:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	blt _0807D748
	bl _0807E400
_0807D748:
	adds r0, r1, 0
	bl DestroySprite
	ldr r1, =0x00000452
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 3
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =c3_08054588
	movs r1, 0x5
	bl CreateTask
	ldr r1, [r7]
	bl _0807E398
	.pool
_0807D77C:
	ldr r0, =c3_08054588
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0807D78C
	bl _0807E400
_0807D78C:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x1A
	strh r1, [r0]
	bl _0807E400
	.pool
_0807D7A4:
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xE0
	ldrh r1, [r0]
	subs r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	movs r0, 0x9E
	lsls r0, 17
	cmp r1, r0
	beq _0807D7BE
	bl _0807E400
_0807D7BE:
	adds r1, r2, 0
	bl _0807E398
_0807D7C4:
	ldr r0, =gUnknown_08338D88
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	adds r1, 0x90
	strb r0, [r1]
	ldr r5, =gSprites
	ldr r0, [r4]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_807AA4C
	str r1, [r0]
	ldr r0, =gSpriteTemplate_8338DC8
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, [r4]
	bl _0807E398
	.pool
_0807D830:
	ldr r2, [r7]
	adds r1, r2, 0
	adds r1, 0xE0
	ldrh r0, [r1]
	subs r0, 0x3
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA6
	bne _0807D84A
	subs r1, 0x4C
	movs r0, 0xC8
	strh r0, [r1]
_0807D84A:
	ldr r1, =0x00001241
	movs r0, 0
	bl SetGpuReg
	bl _0807E400
	.pool
_0807D85C:
	ldr r2, =gSprites
	ldr r4, [r7]
	adds r3, r4, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x2
	strh r1, [r0, 0x22]
	adds r0, r4, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	subs r1, 0x2
	strh r1, [r0, 0x22]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x22
	ldrsh r1, [r0, r2]
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _0807D8A2
	bl _0807E400
_0807D8A2:
	adds r1, r4, 0
	adds r1, 0x94
	movs r0, 0x1D
	strh r0, [r1]
	bl _0807E400
	.pool
_0807D8B4:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x1E
	strh r1, [r0]
	bl _0807E400
	.pool
_0807D8D8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807D8E8
	bl _0807E400
_0807D8E8:
	ldr r0, [r7]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0x2
	bl sub_807B62C
	ldr r1, [r7]
	bl _0807E398
	.pool
_0807D924:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r5, =gSpriteTemplate_8338DC8
	adds r0, r5, 0
	movs r1, 0x6F
	movs r2, 0xAA
	movs r3, 0
	bl CreateSprite
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	adds r1, 0x90
	strb r0, [r1]
	movs r2, 0xA
	negs r2, r2
	adds r0, r5, 0
	movs r1, 0x81
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, 0x91
	strb r0, [r1]
	ldr r1, [r4]
	bl _0807E398
	.pool
_0807D970:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807D98E
	movs r0, 0x2E
	bl PlaySE
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807D98E:
	ldr r3, =gSprites
	ldr r0, =gUnknown_020322A0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r2, 0x91
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	bl _0807E400
	.pool
_0807D9CC:
	ldr r5, =gSprites
	ldr r4, [r7]
	adds r2, r4, 0
	adds r2, 0x90
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r6, r4, 0
	adds r6, 0x91
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r5
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	movs r0, 0x5A
	negs r0, r0
	cmp r1, r0
	ble _0807DA12
	bl _0807E400
_0807DA12:
	movs r2, 0x1
	strh r2, [r3, 0x30]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x30]
	adds r1, r4, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r0, =c3_0805465C
	b _0807DC5A
	.pool
_0807DA38:
	ldr r2, =0x0000ffff
	movs r0, 0x8
	movs r1, 0x10
	bl BlendPalettes
	bl _0807E394
	.pool
_0807DA4C:
	ldr r2, =0x0000ffff
	movs r0, 0x8
	movs r1, 0x10
	bl BlendPalettes
	bl _0807E394
	.pool
_0807DA60:
	ldr r2, =0x0000ffff
	movs r0, 0x8
	movs r1, 0x10
	bl BlendPalettes
	bl _0807E394
	.pool
_0807DA74:
	ldr r5, =gUnknown_020322A0
	ldr r0, [r5]
	adds r0, 0xF0
	ldrh r0, [r0]
	bl IsMonSpriteNotFlipped
	lsls r0, 24
	cmp r0, 0
	bne _0807DAEC
	ldr r4, =gSprites
	ldr r2, [r5]
	adds r2, 0x8E
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gSpriteAffineAnimTable_8338ECC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x3
	bl CalcCenterToCornerVec
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	b _0807DB02
	.pool
_0807DAEC:
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAffineAnim
_0807DB02:
	ldr r5, =gUnknown_020322A0
	ldr r0, [r5]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r2, [r5]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x28
	strh r1, [r0, 0x20]
	adds r2, 0x8F
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xC8
	strh r1, [r0, 0x20]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xC0
	strh r1, [r0, 0x22]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x22]
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r1, [r5]
	bl _0807E398
	.pool
_0807DB9C:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	movs r5, 0
	strh r1, [r0, 0x26]
	adds r2, 0x8F
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x26]
	adds r0, 0xA3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0807DBE4
	movs r0, 0x2D
	bl PlaySE
_0807DBE4:
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x8E
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0x26
	ldrsh r1, [r0, r6]
	movs r0, 0xDE
	negs r0, r0
	cmp r1, r0
	blt _0807DC04
	bl _0807E400
_0807DC04:
	adds r0, r2, 0
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x30]
	adds r0, r2, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x30]
	adds r1, r2, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =sub_807F39C
_0807DC5A:
	movs r1, 0x5
	bl CreateTask
	b _0807E400
	.pool
_0807DC6C:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r3, r2, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	subs r1, 0x3
	strh r1, [r0, 0x26]
	adds r2, 0x91
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x26]
	adds r1, 0x3
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	movs r0, 0xDE
	negs r0, r0
	cmp r1, r0
	ble _0807DCAE
	b _0807E400
_0807DCAE:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0x94
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x90
	ldrb r1, [r1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	b _0807E400
	.pool
_0807DCF4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807DD02
	b _0807E400
_0807DD02:
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x1
	bl sub_807B62C
	ldr r0, [r7]
	adds r0, 0xE0
	movs r1, 0xA6
	strh r1, [r0]
	movs r0, 0x3
	bl sub_807B62C
	ldr r0, [r7]
	adds r0, 0xE4
	movs r1, 0xCE
	lsls r1, 1
	strh r1, [r0]
	ldr r0, =gUnknown_08338D88
	movs r4, 0x14
	negs r4, r4
	movs r1, 0x78
	adds r2, r4, 0
	movs r3, 0x3
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x90
	strb r0, [r1]
	ldr r5, =gSprites
	ldr r0, [r7]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_807AA4C
	str r1, [r0]
	ldr r0, =gSpriteTemplate_8338DC8
	movs r1, 0x78
	adds r2, r4, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	bl StartSpriteAnim
	b _0807E400
	.pool
_0807DD94:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0x10
	movs r3, 0
	b _0807E390
_0807DDA4:
	movs r1, 0x92
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807DDBC
	b _0807E400
_0807DDBC:
	b _0807E394
	.pool
_0807DDC4:
	ldr r2, =gSprites
	ldr r4, [r7]
	adds r3, r4, 0
	adds r3, 0x90
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x4
	strh r1, [r0, 0x26]
	adds r0, r4, 0
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	adds r1, 0x4
	strh r1, [r0, 0x26]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r6, 0x26
	ldrsh r1, [r0, r6]
	movs r2, 0x22
	ldrsh r0, [r0, r2]
	adds r1, r0
	cmp r1, 0x40
	beq _0807DE0A
	b _0807E400
_0807DE0A:
	adds r0, r4, 0
	adds r0, 0x94
	movs r1, 0x90
	strh r1, [r0]
	movs r0, 0
	str r0, [r4, 0x64]
	b _0807E400
	.pool
_0807DE1C:
	movs r1, 0xB2
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gUnknown_020322A0
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xE0
	ldrh r0, [r1]
	adds r0, 0x3
	strh r0, [r1]
	adds r1, 0x4
	ldrh r0, [r1]
	adds r0, 0x3
	strh r0, [r1]
	ldr r0, [r2, 0x64]
	adds r0, 0x1
	str r0, [r2, 0x64]
	cmp r0, 0xA
	bne _0807DE60
	ldr r0, =c3_08054588
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0xC]
_0807DE60:
	ldr r1, [r4]
	adds r3, r1, 0
	adds r3, 0xE0
	movs r6, 0
	ldrsh r0, [r3, r6]
	movs r2, 0x9E
	lsls r2, 1
	cmp r0, r2
	bgt _0807DE74
	b _0807E400
_0807DE74:
	strh r2, [r3]
	b _0807E398
	.pool
_0807DE84:
	ldr r0, [r7]
	adds r0, 0x90
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r3, [r7]
	adds r2, r3, 0
	adds r2, 0x94
	ldrh r0, [r2]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r2]
	str r1, [r3, 0x64]
	b _0807E400
	.pool
_0807DEC0:
	ldr r0, =c3_08054588
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _0807DED0
	b _0807E400
_0807DED0:
	ldr r0, =gUnknown_020322A0
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x94
	movs r0, 0x2E
	strh r0, [r1]
	str r3, [r2, 0x64]
	b _0807E400
	.pool
_0807DEE8:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0xA
	beq _0807DEF6
	b _0807E400
_0807DEF6:
	b _0807E398
_0807DEF8:
	ldr r1, [r7]
	adds r5, r1, 0
	adds r5, 0xE0
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0xAE
	lsls r6, 1
	cmp r0, r6
	bgt _0807DF12
	b _0807E400
_0807DF12:
	strh r6, [r5]
	b _0807E398
_0807DF16:
	ldr r0, =gSpriteTemplate_8338E74
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_020322A0
	ldr r1, [r2]
	adds r1, 0x91
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, 0x94
	movs r1, 0x32
	strh r1, [r0]
	b _0807E400
	.pool
_0807DF3C:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0x91
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	blt _0807DF5A
	b _0807E400
_0807DF5A:
	adds r0, r1, 0
	bl DestroySprite
	movs r0, 0x6
	bl sub_807B62C
	ldr r1, [r7]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0x9F
	bl PlaySE
	b _0807E400
	.pool
_0807DF7C:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0xEA
	ldrh r3, [r2]
	ldr r0, =0x000003ff
	cmp r3, r0
	bhi _0807DF98
	adds r0, r3, 0
	adds r0, 0x34
	strh r0, [r2]
	b _0807DFA6
	.pool
_0807DF98:
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r2]
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0807DFA6:
	ldr r4, [r7]
_0807DFA8:
	adds r0, r4, 0
	adds r0, 0xEA
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	bl __divsi3
	adds r4, 0xE8
	strh r0, [r4]
	b _0807E400
_0807DFBC:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x3C
	strh r1, [r0]
	b _0807E400
	.pool
_0807DFDC:
	ldr r4, =gPaletteFade
	ldrb r1, [r4, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807DFEA
	b _0807E400
_0807DFEA:
	movs r0, 0x5
	bl sub_807B62C
	movs r0, 0x7
	bl sub_807B62C
	ldrb r0, [r4, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4, 0x8]
	b _0807E394
	.pool
_0807E004:
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x8]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	b _0807E390
	.pool
_0807E020:
	movs r1, 0xA2
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0807E038
	b _0807E400
_0807E038:
	b _0807E394
	.pool
_0807E040:
	ldr r0, =gSpriteTemplate_8338D28
	movs r2, 0x8
	negs r2, r2
	movs r1, 0x78
	movs r3, 0
	bl CreateSprite
	ldr r5, =gUnknown_020322A0
	ldr r1, [r5]
	adds r1, 0xD3
	movs r6, 0
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r2, [r5]
	adds r2, 0xD3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x4A
	strh r1, [r0, 0x34]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_807E6AC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
	bl StartSpriteAffineAnim
	ldr r0, [r5]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	ldr r2, =0x0000ffff
	movs r1, 0x10
	bl BlendPalettes
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	str r6, [r2, 0x64]
	b _0807E400
	.pool
_0807E0E8:
	ldr r2, =gSprites
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	b _0807E398
	.pool
_0807E11C:
	ldr r2, =gSprites
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _0807E13A
	b _0807E400
_0807E13A:
	adds r0, r3, 0
	adds r0, 0xF2
	ldrh r2, [r0]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gMonSpritesGfxPtr
	ldr r1, [r1]
	ldr r1, [r1, 0x10]
	ldr r3, [r3, 0x6C]
	bl HandleLoadSpecialPokePic_2
	ldr r1, [r7]
	b _0807E398
	.pool
_0807E168:
	ldr r4, =gSprites
	ldr r2, [r7]
	adds r6, r2, 0
	adds r6, 0x8F
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r5, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	ldrb r0, [r6]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldr r3, =gMonFrontPicCoords
	adds r2, 0xF2
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	adds r0, 0x3C
	strh r0, [r1, 0x22]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x24]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r5, [r0, 0x26]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAnim
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0x8F
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x14
	str r2, [sp, 0x8]
	ldr r2, =0x000fffff
	str r2, [sp, 0xC]
	adds r3, 0xF2
	ldrh r2, [r3]
	str r2, [sp, 0x10]
	movs r2, 0x78
	movs r3, 0x54
	bl CreatePokeballSpriteToReleaseMon
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, [r7]
	adds r0, 0xD3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r1, [r7]
	b _0807E398
	.pool
_0807E228:
	movs r1, 0xAA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gStringVar4
	ldr r1, =gText_XSentOverY
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r0, =gUnknown_020322A0
	ldr r3, [r0]
	adds r1, r3, 0
	adds r1, 0x94
	movs r2, 0
	movs r0, 0xA7
_0807E252:
	strh r0, [r1]
	str r2, [r3, 0x64]
	b _0807E400
	.pool
_0807E264:
	ldr r3, [r7]
	ldr r0, [r3, 0x64]
	adds r0, 0x1
	str r0, [r3, 0x64]
	cmp r0, 0x3C
	bhi _0807E272
	b _0807E400
_0807E272:
	adds r0, r3, 0
	adds r0, 0x94
	movs r2, 0
	ldr r1, =0x0000010b
	strh r1, [r0]
	str r2, [r3, 0x64]
	b _0807E400
	.pool
_0807E284:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0807E290
	b _0807E400
_0807E290:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0x44
	strh r1, [r0]
	b _0807E400
	.pool
_0807E2A0:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0xA
	bne _0807E2B2
	ldr r0, =0x00000173
	bl PlayFanfare
_0807E2B2:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	cmp r0, 0xFA
	beq _0807E2BC
	b _0807E400
_0807E2BC:
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_TakeGoodCareOfX
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	ldr r0, [r7]
	str r5, [r0, 0x64]
	b _0807E400
	.pool
_0807E2EC:
	ldr r1, [r7]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x3C
	beq _0807E2FA
	b _0807E400
_0807E2FA:
	b _0807E398
_0807E2FC:
	bl sub_807F14C
	b _0807E394
_0807E302:
	ldr r2, [r7]
	adds r0, r2, 0
	adds r0, 0xEE
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807E312
	movs r0, 0x1
	b _0807E402
_0807E312:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807E400
	adds r1, r2, 0
	b _0807E398
	.pool
_0807E328:
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
	movs r1, 0
	bl sub_807B4D0
	ldr r1, =gCB2_AfterEvolution
	ldr r0, =sub_807B60C
	str r0, [r1]
	ldr r7, =gUnknown_02032298
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0807E394
	ldrb r3, [r7]
	adds r0, r3, 0
	muls r0, r6
	adds r0, r5
	ldr r1, =gUnknown_020322A0
	ldr r1, [r1]
	adds r1, 0x8F
	ldrb r2, [r1]
	adds r1, r4, 0
	bl TradeEvolutionScene
	b _0807E394
	.pool
_0807E384:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
_0807E390:
	bl BeginNormalPaletteFade
_0807E394:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
_0807E398:
	adds r1, 0x94
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0807E400
	.pool
_0807E3A8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0807E400
	ldr r0, [r7]
	adds r0, 0xF4
	ldrh r0, [r0]
	bl PlayNewMapMusic
	ldr r0, [r7]
	cmp r0, 0
	beq _0807E3F6
	bl FreeAllWindowBuffers
	movs r0, 0x3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r0, [r7]
	bl Free
	str r4, [r7]
_0807E3F6:
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	bl sub_807E784
_0807E400:
	movs r0, 0
_0807E402:
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_807CFC8

	thumb_func_start c2_08053788
c2_08053788: @ 807E414
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807E434
	cmp r0, 0x4
	beq _0807E444
	b _0807E4B4
	.pool
_0807E434:
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, =gSoftResetDisabled
	movs r0, 0x1
	b _0807E4B2
	.pool
_0807E444:
	ldr r0, =gCB2_AfterEvolution
	ldr r1, =sub_807EB50
	mov r8, r1
	str r1, [r0]
	ldr r7, =gUnknown_02032298
	ldrb r0, [r7]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0807E494
	ldrb r3, [r7]
	adds r0, r3, 0
	muls r0, r6
	adds r0, r5
	ldr r1, =gUnknown_020322A0
	ldr r1, [r1]
	adds r1, 0x8F
	ldrb r2, [r1]
	adds r1, r4, 0
	bl TradeEvolutionScene
	b _0807E4AE
	.pool
_0807E494:
	bl sub_8077260
	cmp r0, 0
	beq _0807E4A8
	ldr r0, =sub_807F464
	bl SetMainCallback2
	b _0807E4AE
	.pool
_0807E4A8:
	mov r0, r8
	bl SetMainCallback2
_0807E4AE:
	ldr r1, =gUnknown_02032298
	movs r0, 0xFF
_0807E4B2:
	strb r0, [r1]
_0807E4B4:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	bne _0807E4C2
	bl RunTasks
_0807E4C2:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_08053788

	thumb_func_start sub_807E4DC
sub_807E4DC: @ 807E4DC
	push {r4-r6,lr}
	bl sub_807ACDC
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0x1
	adds r0, r5, 0
	ands r0, r6
	cmp r0, 0
	beq _0807E51A
	ldr r4, =gBlockRecvBuffer
	ldrh r1, [r4]
	ldr r0, =0x0000dcba
	cmp r1, r0
	bne _0807E504
	ldr r0, =c2_08053788
	bl SetMainCallback2
_0807E504:
	ldrh r1, [r4]
	ldr r0, =0x0000abcd
	cmp r1, r0
	bne _0807E514
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x72
	strb r6, [r0]
_0807E514:
	movs r0, 0
	bl ResetBlockReceivedFlag
_0807E51A:
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _0807E542
	ldr r0, =gBlockRecvBuffer
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x0000abcd
	cmp r1, r0
	bne _0807E53C
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x73
	movs r1, 0x1
	strb r1, [r0]
_0807E53C:
	movs r0, 0x1
	bl ResetBlockReceivedFlag
_0807E542:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E4DC

	thumb_func_start sub_807E55C
sub_807E55C: @ 807E55C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r1, 0xA
	bl __divsi3
	ldrh r4, [r5, 0x22]
	adds r4, r0
	strh r4, [r5, 0x22]
	ldrh r0, [r5, 0x30]
	ldrh r2, [r5, 0x38]
	adds r0, r2
	strh r0, [r5, 0x38]
	movs r1, 0x38
	ldrsh r0, [r5, r1]
	movs r1, 0xA
	bl __divsi3
	strh r0, [r5, 0x20]
	lsls r4, 16
	asrs r4, 16
	cmp r4, 0x4C
	ble _0807E5AA
	movs r0, 0x4C
	strh r0, [r5, 0x22]
	movs r2, 0x2E
	ldrsh r1, [r5, r2]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	muls r0, r1
	negs r0, r0
	movs r1, 0x64
	bl __divsi3
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
_0807E5AA:
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0x78
	bne _0807E5B6
	movs r0, 0
	strh r0, [r5, 0x30]
_0807E5B6:
	ldrh r0, [r5, 0x36]
	ldrh r2, [r5, 0x2E]
	adds r0, r2
	strh r0, [r5, 0x2E]
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bne _0807E5CE
	movs r0, 0x1
	strh r0, [r5, 0x3C]
	ldr r0, =SpriteCallbackDummy
	str r0, [r5, 0x1C]
_0807E5CE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E55C

	thumb_func_start sub_807E5D8
sub_807E5D8: @ 807E5D8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_08339024
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x16
	bne _0807E600
	movs r0, 0x38
	bl PlaySE
_0807E600:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2C
	bne _0807E636
	movs r0, 0x8C
	bl PlaySE
	ldr r0, =sub_807E64C
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrb r1, [r4, 0x5]
	lsrs r1, 4
	adds r1, 0x10
	movs r0, 0x1
	lsls r0, r1
	movs r1, 0x1
	negs r1, r1
	ldr r2, =0x0000ffff
	str r2, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0807E636:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E5D8

	thumb_func_start sub_807E64C
sub_807E64C: @ 807E64C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x14
	bne _0807E660
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0807E660:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _0807E69E
	ldr r1, =gUnknown_08339024
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	bne _0807E69E
	adds r0, r4, 0
	bl DestroySprite
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	adds r0, 0x94
	movs r1, 0xE
	strh r1, [r0]
_0807E69E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E64C

	thumb_func_start sub_807E6AC
sub_807E6AC: @ 807E6AC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0807E6DC
	ldrh r0, [r4, 0x22]
	adds r0, 0x4
	strh r0, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _0807E72C
	adds r0, r2, 0x1
	strh r0, [r4, 0x32]
	movs r0, 0x16
	strh r0, [r4, 0x2E]
	movs r0, 0x38
	bl PlaySE
	b _0807E72C
_0807E6DC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x42
	bne _0807E6EA
	movs r0, 0x39
	bl PlaySE
_0807E6EA:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x5C
	bne _0807E6F8
	movs r0, 0x3A
	bl PlaySE
_0807E6F8:
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	cmp r0, 0x6B
	bne _0807E706
	movs r0, 0x3B
	bl PlaySE
_0807E706:
	ldr r1, =gUnknown_08339024
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r3, [r4, 0x26]
	adds r0, r3
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6C
	bne _0807E72C
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_0807E72C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E6AC

	thumb_func_start sub_807E73C
sub_807E73C: @ 807E73C
	push {r4-r6,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 2
	ldr r0, =gIngameTrades
	adds r4, r0
	ldr r0, =gStringVar1
	ldrh r1, [r4, 0x38]
	movs r6, 0xB
	muls r1, r6
	ldr r5, =gSpeciesNames
	adds r1, r5
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r4, 0xC]
	muls r1, r6
	adds r1, r5
	bl StringCopy
	ldrh r0, [r4, 0x38]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_807E73C

	thumb_func_start sub_807E784
sub_807E784: @ 807E784
	push {r4,lr}
	sub sp, 0x20
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 2
	ldr r0, =gIngameTrades
	adds r4, r0
	ldr r0, =gSpecialVar_0x8005
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar1
	mov r1, sp
	bl StringCopy10
	ldr r0, =gStringVar2
	ldrh r2, [r4, 0xC]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	add sp, 0x20
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E784

	thumb_func_start sub_807E7E8
sub_807E7E8: @ 807E7E8
	push {r4-r7,lr}
	sub sp, 0x38
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, r1, 4
	subs r2, r1
	lsls r2, 2
	ldr r1, =gIngameTrades
	adds r5, r2, r1
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	bl GetMonData
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	add r4, sp, 0x34
	movs r0, 0xFE
	strb r0, [r4]
	ldr r6, =gEnemyParty
	ldrh r1, [r5, 0xC]
	movs r3, 0x1
	str r3, [sp]
	ldr r0, [r5, 0x24]
	str r0, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r0, [r5, 0x18]
	str r0, [sp, 0xC]
	adds r0, r6, 0
	movs r3, 0x20
	bl CreateMon
	adds r2, r5, 0
	adds r2, 0xE
	adds r0, r6, 0
	movs r1, 0x27
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0xF
	adds r0, r6, 0
	movs r1, 0x28
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x10
	adds r0, r6, 0
	movs r1, 0x29
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x11
	adds r0, r6, 0
	movs r1, 0x2A
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x12
	adds r0, r6, 0
	movs r1, 0x2B
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x13
	adds r0, r6, 0
	movs r1, 0x2C
	bl SetMonData
	adds r0, r6, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x2B
	adds r0, r6, 0
	movs r1, 0x7
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x36
	adds r0, r6, 0
	movs r1, 0x31
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x14
	adds r0, r6, 0
	movs r1, 0x2E
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x1D
	adds r0, r6, 0
	movs r1, 0x17
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x1E
	adds r0, r6, 0
	movs r1, 0x18
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x1C
	adds r0, r6, 0
	movs r1, 0x16
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x1F
	adds r0, r6, 0
	movs r1, 0x21
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x20
	adds r0, r6, 0
	movs r1, 0x2F
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x37
	adds r0, r6, 0
	movs r1, 0x30
	bl SetMonData
	adds r0, r6, 0
	movs r1, 0x23
	adds r2, r4, 0
	bl SetMonData
	mov r4, sp
	adds r4, 0x35
	movs r0, 0
	strb r0, [r4]
	ldrh r0, [r5, 0x28]
	cmp r0, 0
	beq _0807E960
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _0807E954
	add r0, sp, 0x10
	adds r1, r5, 0
	bl sub_807E974
	ldr r0, =gUnknown_020321C0
	add r1, sp, 0x10
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	adds r0, r6, 0
	movs r1, 0x40
	adds r2, r4, 0
	bl SetMonData
	adds r2, r5, 0
	adds r2, 0x28
	adds r0, r6, 0
	movs r1, 0xC
	bl SetMonData
	b _0807E960
	.pool
_0807E954:
	adds r2, r5, 0
	adds r2, 0x28
	adds r0, r6, 0
	movs r1, 0xC
	bl SetMonData
_0807E960:
	ldr r0, =gEnemyParty
	bl CalculateMonStats
	add sp, 0x38
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E7E8

	thumb_func_start sub_807E974
sub_807E974: @ 807E974
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r2, =gUnknown_08338FC0
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	adds r1, r5, 0
	movs r3, 0x8
_0807E98E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0807E98E
	adds r4, r5, 0
	adds r4, 0x12
	adds r1, r6, 0
	adds r1, 0x2B
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0
	bl PadNameString
	ldr r1, [r6, 0x18]
	lsrs r0, r1, 24
	strb r0, [r5, 0x1A]
	lsrs r0, r1, 16
	strb r0, [r5, 0x1B]
	lsrs r0, r1, 8
	strb r0, [r5, 0x1C]
	strb r1, [r5, 0x1D]
	ldrh r0, [r6, 0xC]
	strh r0, [r5, 0x1E]
	ldrh r0, [r6, 0x28]
	strh r0, [r5, 0x20]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807E974

	thumb_func_start sub_807E9D4
sub_807E9D4: @ 807E9D4
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_0x8005
	ldrh r0, [r6]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0807EA08
	ldrh r0, [r6]
	muls r0, r5
	adds r0, r4
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	b _0807EA0A
	.pool
_0807EA08:
	movs r0, 0
_0807EA0A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_807E9D4

	thumb_func_start sub_807EA10
sub_807EA10: @ 807EA10
	push {lr}
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
	ldr r1, =gSpecialVar_0x8004
	ldrb r1, [r1]
	bl sub_807E7E8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807EA10

	thumb_func_start sub_807EA2C
sub_807EA2C: @ 807EA2C
	push {r4-r6,lr}
	bl sub_807BBC8
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bne _0807EA96
	ldr r5, =gUnknown_020322A0
	ldr r0, [r5]
	adds r0, 0x8E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldr r0, [r5]
	adds r0, 0x8F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, =gUnknown_02032298
	ldrb r4, [r0]
	ldrb r0, [r0, 0x1]
	movs r1, 0x6
	bl __umodsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_807B4D0
	bl sub_8077260
	cmp r0, 0
	bne _0807EA90
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x74
	ldr r1, =0x0000abcd
	strh r1, [r2]
	adds r0, 0x93
	strb r6, [r0]
_0807EA90:
	ldr r0, =sub_807EACC
	bl SetMainCallback2
_0807EA96:
	bl sub_807B5B8
	bl sub_807E4DC
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807EA2C

	thumb_func_start sub_807EACC
sub_807EACC: @ 807EACC
	push {r4,lr}
	bl sub_807ACDC
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8077260
	cmp r0, 0
	beq _0807EAEC
	ldr r0, =c2_08053788
	bl SetMainCallback2
	b _0807EB2C
	.pool
_0807EAEC:
	bl sub_807E4DC
	cmp r4, 0
	bne _0807EB2C
	ldr r4, =gUnknown_020322A0
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x72
	ldrh r1, [r0]
	ldr r0, =0x00000101
	cmp r1, r0
	bne _0807EB2C
	adds r1, r2, 0
	adds r1, 0x74
	ldr r0, =0x0000dcba
	strh r0, [r1]
	bl bitmask_all_link_players_but_self
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [r4]
	adds r1, 0x74
	movs r2, 0x14
	bl SendBlock
	ldr r0, [r4]
	adds r0, 0x72
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x73
	strb r1, [r0]
_0807EB2C:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807EACC

	thumb_func_start sub_807EB50
sub_807EB50: @ 807EB50
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x65
	bls _0807EB66
	b _0807F03A
_0807EB66:
	lsls r0, 2
	ldr r1, =_0807EB78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807EB78:
	.4byte _0807ED10
	.4byte _0807ED2C
	.4byte _0807ED98
	.4byte _0807F03A
	.4byte _0807EE78
	.4byte _0807EF3C
	.4byte _0807EF64
	.4byte _0807EF7E
	.4byte _0807EFA4
	.4byte _0807EFF0
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807EE9C
	.4byte _0807EEEC
	.4byte _0807EF1A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807EDC0
	.4byte _0807EE1C
	.4byte _0807EE38
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807F03A
	.4byte _0807ED44
	.4byte _0807ED7C
_0807ED10:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_CommunicationStandby5
	b _0807EDA6
	.pool
_0807ED2C:
	movs r0, 0
	bl sub_8077288
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x64
	b _0807EE88
	.pool
_0807ED44:
	ldr r0, =gUnknown_020322A0
	ldr r3, [r0]
	ldr r0, [r3, 0x64]
	adds r0, 0x1
	str r0, [r3, 0x64]
	cmp r0, 0xB4
	bls _0807ED60
	movs r1, 0x87
	lsls r1, 3
	adds r0, r2, r1
	movs r2, 0
	movs r1, 0x65
	strb r1, [r0]
	str r2, [r3, 0x64]
_0807ED60:
	bl sub_8077294
	cmp r0, 0
	bne _0807ED6A
	b _0807F03A
_0807ED6A:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	b _0807ED8E
	.pool
_0807ED7C:
	bl sub_8077294
	cmp r0, 0
	bne _0807ED86
	b _0807F03A
_0807ED86:
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
_0807ED8E:
	movs r1, 0x2
	strb r1, [r0]
	b _0807F03A
	.pool
_0807ED98:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x32
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_SavingDontTurnOffPower
_0807EDA6:
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	b _0807F03A
	.pool
_0807EDC0:
	bl InUnionRoom
	cmp r0, 0
	bne _0807EDCE
	movs r0, 0x15
	bl IncrementGameStat
_0807EDCE:
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807EDF6
	ldr r4, =gLinkPlayers
	bl GetMultiplayerId
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r4, 0x4
	adds r1, r4
	ldr r1, [r1]
	movs r0, 0x2
	bl sub_801B990
_0807EDF6:
	bl sub_8076D5C
	bl sub_8153380
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1]
	b _0807EE8A
	.pool
_0807EE1C:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x5
	beq _0807EE2C
	b _0807F03A
_0807EE2C:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	b _0807EFE4
	.pool
_0807EE38:
	bl sub_81533AC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0807EE5C
	bl sav2_gender2_inplace_and_xFE
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x4
	strb r1, [r0]
	b _0807F03A
	.pool
_0807EE5C:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	str r1, [r0, 0x64]
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x33
	strb r1, [r0]
	b _0807F03A
	.pool
_0807EE78:
	bl sub_81533E0
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x28
_0807EE88:
	strb r1, [r0]
_0807EE8A:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	str r2, [r0, 0x64]
	b _0807F03A
	.pool
_0807EE9C:
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x32
	bhi _0807EEAC
	b _0807F03A
_0807EEAC:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0807EED4
	bl Random
	ldr r4, [r4]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [r4, 0x64]
	b _0807EEDA
	.pool
_0807EED4:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x64]
_0807EEDA:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x29
	strb r1, [r0]
	b _0807F03A
	.pool
_0807EEEC:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	cmp r0, 0
	bne _0807EF14
	movs r0, 0x1
	bl sub_8077288
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x2A
	strb r1, [r0]
	b _0807F03A
	.pool
_0807EF14:
	subs r0, 0x1
	str r0, [r1, 0x64]
	b _0807F03A
_0807EF1A:
	bl sub_8077294
	cmp r0, 0
	bne _0807EF24
	b _0807F03A
_0807EF24:
	bl sub_8153408
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x5
	strb r1, [r0]
	b _0807F03A
	.pool
_0807EF3C:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x3C
	bls _0807F03A
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x2
	bl sub_8077288
	b _0807F03A
	.pool
_0807EF64:
	bl sub_8077294
	cmp r0, 0
	beq _0807F03A
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0807EFDC
_0807EF7E:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807F03A
	movs r0, 0x3
	bl FadeOutBGM
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0807EFE4
	.pool
_0807EFA4:
	bl IsBGMStopped
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807F03A
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807EFD8
	ldr r0, =gMain
	ldr r1, [r0, 0x8]
	ldr r0, =sub_80773AC
	cmp r1, r0
	bne _0807EFD8
	movs r0, 0x3
	bl sub_8077288
	b _0807EFDC
	.pool
_0807EFD8:
	bl sub_800AC34
_0807EFDC:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_0807EFE4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0807F03A
	.pool
_0807EFF0:
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807F028
	ldr r1, [r2, 0x8]
	ldr r0, =sub_80773AC
	cmp r1, r0
	bne _0807F028
	bl sub_8077294
	cmp r0, 0
	beq _0807F03A
	ldr r0, =gSoftResetDisabled
	movs r1, 0
	strb r1, [r0]
	ldr r0, =c2_080543C4
	bl SetMainCallback2
	b _0807F03A
	.pool
_0807F028:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r1, [r0]
	cmp r1, 0
	bne _0807F03A
	ldr r0, =gSoftResetDisabled
	strb r1, [r0]
	ldr r0, =c2_080543C4
	bl SetMainCallback2
_0807F03A:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	bne _0807F048
	bl RunTasks
_0807F048:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807EB50

	thumb_func_start c2_080543C4
c2_080543C4: @ 807F068
	push {r4,r5,lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0807F0BE
	bl FreeAllWindowBuffers
	movs r0, 0x3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0x1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, 0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807F0B6
	bl sub_800E084
_0807F0B6:
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_0807F0BE:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_080543C4

	thumb_func_start sub_807F0E4
sub_807F0E4: @ 807F0E4
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	ldr r0, =sub_807F110
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807F0E4

	thumb_func_start sub_807F110
sub_807F110: @ 807F110
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807F134
	ldr r0, =sub_807B270
	bl SetMainCallback2
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0807F134:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807F110

	thumb_func_start sub_807F14C
sub_807F14C: @ 807F14C
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0807F152:
	ldr r0, =gUnknown_02032298
	ldrb r0, [r0, 0x1]
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r1, r4, 0
	adds r1, 0x43
	bl GetMonData
	adds r0, r5, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xB
	bls _0807F152
	cmp r5, 0
	beq _0807F18A
	ldr r0, =0x0000089b
	bl FlagSet
_0807F18A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807F14C

	thumb_func_start sub_807F19C
sub_807F19C: @ 807F19C
	push {lr}
	bl sub_807B170
	pop {r0}
	bx r0
	thumb_func_end sub_807F19C

	thumb_func_start sub_807F1A8
sub_807F1A8: @ 807F1A8
	push {r4-r6,lr}
	sub sp, 0x14
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_020322A0
	ldr r0, [r2]
	adds r0, 0xF6
	movs r3, 0
	movs r1, 0xF
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xF7
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xF8
	movs r1, 0x6
	strb r1, [r0]
	str r3, [sp]
	str r3, [sp, 0x4]
	ldr r0, [r2]
	adds r0, 0xF6
	str r0, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r6, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x2
	bl AddTextPrinterParameterized4
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807F1A8

	thumb_func_start c3_08054588
c3_08054588: @ 807F210
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r1, =gUnknown_08339090
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r2, r1, 0
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0807F254
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _0807F25C
	lsls r0, r1, 1
	ldr r1, =gUnknown_08337AA0
	adds r0, r1
	b _0807F25E
	.pool
_0807F254:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _0807F26C
_0807F25C:
	ldr r0, =gUnknown_08337EA0
_0807F25E:
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	b _0807F27A
	.pool
_0807F26C:
	lsls r0, r2, 1
	ldr r1, =gUnknown_08337CA0
	adds r0, r1
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
_0807F27A:
	ldr r0, =gUnknown_08339090
	movs r2, 0
	ldrsh r1, [r4, r2]
	lsls r1, 1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807F298
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0807F298
	movs r0, 0xC3
	bl PlaySE
_0807F298:
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_08339090
	movs r3, 0
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0807F2D8
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0807F2DE
	adds r0, r5, 0
	bl DestroyTask
	b _0807F2DE
	.pool
_0807F2D8:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_0807F2DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end c3_08054588

	thumb_func_start c3_0805465C
c3_0805465C: @ 807F2E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0
	ldrsh r4, [r5, r0]
	cmp r4, 0
	bne _0807F336
	ldr r2, =gUnknown_020322A0
	ldr r0, [r2]
	adds r3, r0, 0
	adds r3, 0xFD
	movs r1, 0x78
	strb r1, [r3]
	adds r0, 0xFB
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xFC
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, 0xFE
	movs r1, 0xA0
	strb r1, [r0]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x4A
	movs r1, 0x10
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x13
	bl SetGpuReg
_0807F336:
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xFD
	ldrb r1, [r1]
	adds r0, 0xFB
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xFE
	ldrb r1, [r1]
	adds r0, 0xFC
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0x44
	bl SetGpuReg
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, 0xFB
	ldrb r0, [r1]
	subs r0, 0x5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, 0xFD
	ldrb r0, [r1]
	adds r0, 0x5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0x4F
	bhi _0807F38E
	adds r0, r6, 0
	bl DestroyTask
_0807F38E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0805465C

	thumb_func_start sub_807F39C
sub_807F39C: @ 807F39C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0807F3D8
	ldr r2, =gUnknown_020322A0
	ldr r0, [r2]
	adds r0, 0xFB
	movs r1, 0x50
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xFD
	movs r1, 0xA0
	strb r1, [r0]
	movs r0, 0x4A
	movs r1, 0x10
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x13
	bl SetGpuReg
_0807F3D8:
	ldr r4, =gUnknown_020322A0
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xFD
	ldrb r1, [r1]
	adds r0, 0xFB
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xFE
	ldrb r1, [r1]
	adds r0, 0xFC
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0x78
	beq _0807F44C
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, 0xFB
	ldrb r0, [r1]
	adds r0, 0x5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, 0xFD
	ldrb r0, [r1]
	subs r0, 0x5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0x73
	bls _0807F45C
	ldr r2, =0x0000ffff
	movs r0, 0x8
	movs r1, 0
	bl BlendPalettes
	b _0807F45C
	.pool
_0807F44C:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	adds r0, r6, 0
	bl DestroyTask
_0807F45C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_807F39C

	thumb_func_start sub_807F464
sub_807F464: @ 807F464
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xC
	bls _0807F47A
	b _0807F70C
_0807F47A:
	lsls r0, 2
	ldr r1, =_0807F48C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0807F48C:
	.4byte _0807F4C0
	.4byte _0807F4E8
	.4byte _0807F500
	.4byte _0807F550
	.4byte _0807F570
	.4byte _0807F5AC
	.4byte _0807F5D0
	.4byte _0807F620
	.4byte _0807F64E
	.4byte _0807F66C
	.4byte _0807F694
	.4byte _0807F6C4
	.4byte _0807F6F8
_0807F4C0:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gText_CommunicationStandby5
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	b _0807F70C
	.pool
_0807F4E8:
	movs r0, 0
	bl sub_8077288
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x2
	b _0807F5BC
	.pool
_0807F500:
	bl sub_8077294
	cmp r0, 0
	bne _0807F50A
	b _0807F70C
_0807F50A:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r5, 0
	movs r1, 0x3
	strb r1, [r0]
	ldr r4, =gStringVar4
	ldr r1, =gText_SavingDontTurnOffPower
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807F1A8
	movs r0, 0x15
	bl IncrementGameStat
	bl sub_8153380
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	str r5, [r0, 0x64]
	b _0807F70C
	.pool
_0807F550:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x5
	beq _0807F560
	b _0807F70C
_0807F560:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x4
	strb r0, [r1]
	b _0807F70C
	.pool
_0807F570:
	bl sub_81533AC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0807F590
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F590:
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	str r1, [r0, 0x64]
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F5AC:
	bl sub_81533E0
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x6
_0807F5BC:
	strb r1, [r0]
	ldr r0, =gUnknown_020322A0
	ldr r0, [r0]
	str r2, [r0, 0x64]
	b _0807F70C
	.pool
_0807F5D0:
	ldr r4, =gUnknown_020322A0
	ldr r1, [r4]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0xA
	bhi _0807F5E0
	b _0807F70C
_0807F5E0:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _0807F608
	bl Random
	ldr r4, [r4]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	str r0, [r4, 0x64]
	b _0807F60E
	.pool
_0807F608:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x64]
_0807F60E:
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x7
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F620:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	cmp r0, 0
	bne _0807F648
	movs r0, 0x1
	bl sub_8077288
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F648:
	subs r0, 0x1
	str r0, [r1, 0x64]
	b _0807F70C
_0807F64E:
	bl sub_8077294
	cmp r0, 0
	beq _0807F70C
	bl sub_8153408
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x9
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F66C:
	ldr r0, =gUnknown_020322A0
	ldr r1, [r0]
	ldr r0, [r1, 0x64]
	adds r0, 0x1
	str r0, [r1, 0x64]
	cmp r0, 0x3C
	bls _0807F70C
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x2
	bl sub_8077288
	b _0807F70C
	.pool
_0807F694:
	bl sub_8077294
	cmp r0, 0
	beq _0807F70C
	movs r0, 0x3
	bl FadeOutBGM
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0xB
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F6C4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0807F70C
	bl IsBGMStopped
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807F70C
	movs r0, 0x3
	bl sub_8077288
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0xC
	strb r1, [r0]
	b _0807F70C
	.pool
_0807F6F8:
	bl sub_8077294
	cmp r0, 0
	beq _0807F70C
	ldr r0, =gSoftResetDisabled
	movs r1, 0
	strb r1, [r0]
	ldr r0, =c2_080543C4
	bl SetMainCallback2
_0807F70C:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	bne _0807F71A
	bl RunTasks
_0807F71A:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_807F464

	.align 2, 0 @ Don't pad with nop.
