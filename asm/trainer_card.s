	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80C2690
sub_80C2690: @ 80C2690
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_80C48C8
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080C26C0
	ldr r1, =0x040000d4
	ldr r0, =gScanlineEffectRegBuffers
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_080C26C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2690

	thumb_func_start sub_80C26D4
sub_80C26D4: @ 80C26D4
	push {r4,lr}
	ldr r4, =0x04000208
	ldrh r3, [r4]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gScanlineEffectRegBuffers
	ldr r0, =0x04000006
	ldrh r2, [r0]
	movs r0, 0xFF
	ands r0, r2
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000012
	strh r1, [r0]
	strh r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C26D4

	thumb_func_start sub_80C2710
sub_80C2710: @ 80C2710
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_80C2710

	thumb_func_start sub_80C2728
sub_80C2728: @ 80C2728
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_02039CE8
	ldr r0, [r5]
	movs r1, 0xA6
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	bl SetMainCallback2
	bl FreeAllWindowBuffers
	ldr r0, [r5]
	bl Free
	movs r0, 0
	str r0, [r5]
	adds r0, r4, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2728

	thumb_func_start sub_80C2760
sub_80C2760: @ 80C2760
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_02039CE8
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _080C2776
	b _080C2ACA
_080C2776:
	lsls r0, 2
	ldr r1, =_080C2788
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2788:
	.4byte _080C27CC
	.4byte _080C27E2
	.4byte _080C27F0
	.4byte _080C27F8
	.4byte _080C280C
	.4byte _080C2820
	.4byte _080C2830
	.4byte _080C2836
	.4byte _080C289C
	.4byte _080C28C8
	.4byte _080C28E4
	.4byte _080C299C
	.4byte _080C2970
	.4byte _080C2AAA
	.4byte _080C2A98
	.4byte _080C2A2C
	.4byte _080C2A68
_080C27CC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _080C27D8
	b _080C2ACA
_080C27D8:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	b _080C28D4
_080C27E2:
	bl sub_80C3438
	lsls r0, 24
	cmp r0, 0
	bne _080C27EE
	b _080C2ACA
_080C27EE:
	b _080C28D4
_080C27F0:
	movs r0, 0x1
	bl sub_80C438C
	b _080C28D4
_080C27F8:
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	bl sub_80C4FF0
	movs r0, 0x2
	bl sub_80C438C
	b _080C28D4
_080C280C:
	ldr r0, [r4]
	ldr r1, =0x00000ef8
	adds r0, r1
	bl sub_80C4550
	ldr r1, [r4]
	b _080C28D8
	.pool
_080C2820:
	ldr r0, [r4]
	movs r2, 0xB3
	lsls r2, 3
	adds r0, r2
	bl sub_80C45C0
	ldr r1, [r4]
	b _080C28D8
_080C2830:
	bl sub_80C4630
	b _080C28D4
_080C2836:
	ldr r0, =gWirelessCommType
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080C2852
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080C2852
	bl sub_800E0E8
	movs r0, 0xE6
	movs r1, 0x96
	bl CreateWirelessStatusIndicatorSprite
_080C2852:
	movs r6, 0x1
	negs r6, r6
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	ldr r5, =0x0000052c
	adds r0, r5
	ldrh r2, [r0]
	adds r0, r6, 0
	movs r1, 0x10
	bl BlendPalettes
	ldr r0, [r4]
	adds r0, r5
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_80C2690
	bl SetVBlankCallback
	ldr r1, [r4]
	b _080C28D8
	.pool
_080C289C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _080C28A8
	b _080C2ACA
_080C28A8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _080C28B4
	b _080C2ACA
_080C28B4:
	movs r0, 0xFB
	bl PlaySE
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0xA
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C28C8:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _080C28D4
	b _080C2ACA
_080C28D4:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
_080C28D8:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C28E4:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r5, [r0]
	cmp r5, 0
	bne _080C290A
	ldr r0, [r4]
	ldr r1, =0x00000529
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C290A
	bl sub_80C3880
	movs r0, 0x1
	bl sub_80C438C
	ldr r0, [r4]
	ldr r2, =0x00000529
	adds r0, r2
	strb r5, [r0]
_080C290A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C293C
	bl sub_80C4918
	movs r0, 0xF9
	bl PlaySE
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0xC
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C293C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080C2946
	b _080C2ACA
_080C2946:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2960
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	beq _080C2960
	bl InUnionRoom
	cmp r0, 0x1
	beq _080C2A14
_080C2960:
	movs r0, 0x1
	negs r0, r0
	ldr r4, =gUnknown_02039CE8
	b _080C2A74
	.pool
_080C2970:
	bl sub_80C4940
	lsls r0, 24
	cmp r0, 0
	bne _080C297C
	b _080C2ACA
_080C297C:
	bl sub_8087598
	cmp r0, 0x1
	bne _080C2986
	b _080C2ACA
_080C2986:
	movs r0, 0xFB
	bl PlaySE
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0xB
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C299C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C29F4
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C29DC
	ldr r0, [r4]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	beq _080C29C0
	bl InUnionRoom
	cmp r0, 0x1
	beq _080C2A14
_080C29C0:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C29DC
	movs r0, 0x1
	negs r0, r0
	ldr r4, =gUnknown_02039CE8
	b _080C2A74
	.pool
_080C29DC:
	bl sub_80C4918
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0xD
	strb r0, [r1]
	movs r0, 0xF9
	bl PlaySE
	b _080C2ACA
	.pool
_080C29F4:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C2ACA
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2A20
	ldr r0, [r4]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	beq _080C2A20
	bl InUnionRoom
	cmp r0, 0x1
	bne _080C2A20
_080C2A14:
	ldr r1, [r4]
	movs r0, 0xF
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C2A20:
	movs r0, 0x1
	negs r0, r0
	ldr r4, =gUnknown_02039CE8
	b _080C2A74
	.pool
_080C2A2C:
	bl sub_800AC34
	movs r0, 0
	movs r1, 0x1
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_WaitingTrainerFinishReading
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0x10
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C2A68:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C2ACA
	movs r0, 0x1
	negs r0, r0
_080C2A74:
	ldr r1, [r4]
	ldr r2, =0x0000052c
	adds r1, r2
	ldrh r1, [r1]
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	movs r0, 0xE
	strb r0, [r1]
	b _080C2ACA
	.pool
_080C2A98:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C2ACA
	adds r0, r5, 0
	bl sub_80C2728
	b _080C2ACA
_080C2AAA:
	bl sub_80C4940
	lsls r0, 24
	cmp r0, 0
	beq _080C2ACA
	bl sub_8087598
	cmp r0, 0x1
	beq _080C2ACA
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0xA
	strb r0, [r1]
	movs r0, 0xFB
	bl PlaySE
_080C2ACA:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C2760

	thumb_func_start sub_80C2AD8
sub_80C2AD8: @ 80C2AD8
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0x5
	bls _080C2AE6
	b _080C2C64
_080C2AE6:
	lsls r0, 2
	ldr r1, =_080C2AF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2AF8:
	.4byte _080C2B10
	.4byte _080C2B44
	.4byte _080C2B78
	.4byte _080C2BD0
	.4byte _080C2C04
	.4byte _080C2C38
_080C2B10:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2B34
	ldr r0, =gUnknown_08DD1F78
	ldr r2, =0x00000ef8
	b _080C2C4A
	.pool
_080C2B34:
	ldr r0, =gUnknown_08DD2AE0
	ldr r2, =0x00000ef8
	b _080C2C4A
	.pool
_080C2B44:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2B68
	ldr r0, =gUnknown_08DD21B0
	ldr r2, =0x00000a48
	b _080C2C4A
	.pool
_080C2B68:
	ldr r0, =gUnknown_08DD2D30
	ldr r2, =0x00000a48
	b _080C2C4A
	.pool
_080C2B78:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	bne _080C2BAC
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2BA0
	ldr r0, =gUnknown_08DD2010
	adds r2, 0x6E
	b _080C2C4A
	.pool
_080C2BA0:
	ldr r0, =gUnknown_08DD2B78
	movs r2, 0xB3
	lsls r2, 3
	b _080C2C4A
	.pool
_080C2BAC:
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2BC4
	ldr r0, =gUnknown_08DD228C
	adds r2, 0x6E
	b _080C2C4A
	.pool
_080C2BC4:
	ldr r0, =gUnknown_08DD2E5C
	movs r2, 0xB3
	lsls r2, 3
	b _080C2C4A
	.pool
_080C2BD0:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2BF4
	ldr r0, =gUnknown_0856F5CC
	ldr r2, =0x000013a8
	b _080C2C4A
	.pool
_080C2BF4:
	ldr r0, =gUnknown_0856F814
	ldr r2, =0x000013a8
	b _080C2C4A
	.pool
_080C2C04:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C2C28
	ldr r0, =gEmeraldTrainerCard_Gfx
	ldr r2, =0x000019a8
	b _080C2C4A
	.pool
_080C2C28:
	ldr r0, =gFireRedTrainerCard_Gfx
	ldr r2, =0x000019a8
	b _080C2C4A
	.pool
_080C2C38:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C2C6C
	ldr r0, =gUnknown_0856F018
	ldr r2, =0x000017a8
_080C2C4A:
	adds r1, r2
	bl LZ77UnCompWram
	b _080C2C6C
	.pool
_080C2C64:
	movs r0, 0
	strb r0, [r1, 0x2]
	movs r0, 0x1
	b _080C2C78
_080C2C6C:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0
_080C2C78:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C2AD8

	thumb_func_start sub_80C2C80
sub_80C2C80: @ 80C2C80
	push {lr}
	sub sp, 0x8
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r3, r1, 0
	cmp r0, 0xA
	bls _080C2C96
	b _080C2DD8
_080C2C96:
	lsls r0, 2
	ldr r1, =_080C2CA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C2CA8:
	.4byte _080C2CD4
	.4byte _080C2CEC
	.4byte _080C2D14
	.4byte _080C2D50
	.4byte _080C2D6A
	.4byte _080C2D74
	.4byte _080C2D88
	.4byte _080C2D8E
	.4byte _080C2DA0
	.4byte _080C2DA6
	.4byte _080C2DB8
_080C2CD4:
	bl sub_80C334C
	bl sub_80C3414
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080C2DCC
	.pool
_080C2CEC:
	movs r1, 0xE0
	lsls r1, 19
	movs r0, 0
	str r0, [sp]
	ldr r0, =0x040000d4
	mov r2, sp
	str r2, [r0]
	str r1, [r0, 0x4]
	ldr r1, =0x85000100
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	movs r0, 0x87
	lsls r0, 3
	adds r1, r3, r0
	b _080C2DCC
	.pool
_080C2D14:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052c
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080C2D36
	movs r2, 0xA0
	lsls r2, 19
	add r1, sp, 0x4
	strh r0, [r1]
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x81000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
_080C2D36:
	movs r2, 0x87
	lsls r2, 3
	adds r1, r3, r2
	b _080C2DCC
	.pool
_080C2D50:
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C2D6A:
	bl sub_80C3388
	b _080C2DC4
	.pool
_080C2D74:
	bl sub_80C41D8
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080C2DCC
	.pool
_080C2D88:
	bl sub_80C2AD8
	b _080C2DBC
_080C2D8E:
	bl sub_80C4330
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080C2DCC
	.pool
_080C2DA0:
	bl sub_80C3278
	b _080C2DC4
_080C2DA6:
	bl sub_80C3548
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _080C2DCC
	.pool
_080C2DB8:
	bl sub_80C43A8
_080C2DBC:
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080C2DDC
_080C2DC4:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
_080C2DCC:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _080C2DDC
	.pool
_080C2DD8:
	bl sub_80C3404
_080C2DDC:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80C2C80

	thumb_func_start sav12_xor_get_clamped_above
sav12_xor_get_clamped_above: @ 80C2DE4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl GetGameStat
	cmp r0, r4
	bls _080C2DF6
	adds r0, r4, 0
_080C2DF6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sav12_xor_get_clamped_above

	thumb_func_start sub_80C2DFC
sub_80C2DFC: @ 80C2DFC
	push {r4,r5,lr}
	movs r5, 0
_080C2E00:
	lsls r4, r5, 1
	ldr r1, =0x000008c4
	adds r0, r4, r1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C2E1E
	ldr r1, =0x000008c5
	adds r0, r4, r1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080C2E2C
_080C2E1E:
	movs r0, 0
	b _080C2E38
	.pool
_080C2E2C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080C2E00
	movs r0, 0x1
_080C2E38:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80C2DFC

	thumb_func_start sub_80C2E40
sub_80C2E40: @ 80C2E40
	push {r4,lr}
	movs r0, 0xA
	bl GetGameStat
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	bl sub_80C08E4
	lsls r0, 16
	cmp r0, 0
	beq _080C2E5A
	adds r4, 0x1
_080C2E5A:
	bl sub_80F8940
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080C2E6C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080C2E6C:
	bl sub_80C2DFC
	lsls r0, 24
	cmp r0, 0
	beq _080C2E7C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080C2E7C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C2E40

	thumb_func_start sub_80C2E84
sub_80C2E84: @ 80C2E84
	push {lr}
	adds r1, r0, 0
	movs r2, 0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	bne _080C2E96
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _080C2E98
_080C2E96:
	movs r2, 0x1
_080C2E98:
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _080C2EA4
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080C2EA4:
	ldrh r0, [r1, 0x1A]
	cmp r0, 0x31
	bls _080C2EB0
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080C2EB0:
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080C2EBC
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080C2EBC:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80C2E84

	thumb_func_start sub_80C2EC4
sub_80C2EC4: @ 80C2EC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r6, =gSaveBlock2Ptr
	ldr r1, [r6]
	ldrb r0, [r1, 0x8]
	strb r0, [r5]
	ldrh r0, [r1, 0xE]
	strh r0, [r5, 0x10]
	ldrb r0, [r1, 0x10]
	strh r0, [r5, 0x12]
	movs r0, 0x1
	bl GetGameStat
	adds r4, r0, 0
	movs r0, 0xA
	bl GetGameStat
	cmp r0, 0
	bne _080C2EF6
	movs r4, 0
_080C2EF6:
	lsrs r0, r4, 16
	strh r0, [r5, 0x6]
	lsrs r1, r4, 8
	movs r2, 0xFF
	ands r1, r2
	strh r1, [r5, 0x8]
	ands r4, r2
	strh r4, [r5, 0xA]
	ldr r1, =0x000003e7
	cmp r0, r1
	bls _080C2F14
	strh r1, [r5, 0x6]
	movs r0, 0x3B
	strh r0, [r5, 0x8]
	strh r0, [r5, 0xA]
_080C2F14:
	ldr r0, =0x00000861
	bl FlagGet
	strb r0, [r5, 0x2]
	bl sub_80C08E4
	strb r0, [r5, 0x3]
	bl sub_80C376C
	strh r0, [r5, 0xC]
	ldr r0, [r6]
	ldrb r1, [r0, 0xB]
	lsls r1, 8
	ldrb r0, [r0, 0xA]
	orrs r0, r1
	strh r0, [r5, 0xE]
	ldr r4, =0x0000270f
	movs r0, 0x17
	adds r1, r4, 0
	bl sav12_xor_get_clamped_above
	strh r0, [r5, 0x14]
	movs r0, 0x18
	adds r1, r4, 0
	bl sav12_xor_get_clamped_above
	strh r0, [r5, 0x16]
	ldr r1, =0x0000ffff
	movs r0, 0x15
	bl sav12_xor_get_clamped_above
	strh r0, [r5, 0x20]
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	bl GetMoney
	str r0, [r5, 0x24]
	movs r2, 0
	adds r7, r5, 0
	adds r7, 0x30
	adds r6, r5, 0
	adds r6, 0x28
	ldr r0, [r4]
	ldr r1, =0x00002bb0
	adds r3, r0, r1
_080C2F74:
	lsls r0, r2, 1
	adds r1, r6, r0
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080C2F74
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r7, 0
	bl StringCopy
	mov r0, r8
	cmp r0, 0x1
	beq _080C3004
	cmp r0, 0x1
	bgt _080C2FC0
	cmp r0, 0
	beq _080C2FCC
	b _080C3014
	.pool
_080C2FC0:
	mov r1, r8
	cmp r1, 0x2
	bne _080C3014
	movs r0, 0
	strh r0, [r5, 0x18]
	strh r0, [r5, 0x1A]
_080C2FCC:
	ldr r1, =0x000003e7
	movs r0, 0x23
	bl sav12_xor_get_clamped_above
	strh r0, [r5, 0x1C]
	ldr r1, =0x0000ffff
	movs r0, 0x22
	bl sav12_xor_get_clamped_above
	strh r0, [r5, 0x1E]
	bl sub_80F8940
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _080C2FF0
	movs r0, 0x1
	strb r0, [r5, 0x4]
_080C2FF0:
	adds r0, r5, 0
	bl sub_80C2E84
	strb r0, [r5, 0x1]
	b _080C3014
	.pool
_080C3004:
	movs r1, 0
	movs r0, 0
	strh r0, [r5, 0x18]
	strh r0, [r5, 0x1A]
	strh r0, [r5, 0x1C]
	strh r0, [r5, 0x1E]
	strb r1, [r5, 0x4]
	strb r1, [r5, 0x1]
_080C3014:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C2EC4

	thumb_func_start sub_80C3020
sub_80C3020: @ 80C3020
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	movs r2, 0x64
	bl memset
	adds r1, r4, 0
	adds r1, 0x38
	movs r0, 0x3
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80C2EC4
	bl sub_80C2DFC
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r1, 0x60
	strh r0, [r1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000eba
	adds r0, r2
	ldrh r0, [r0]
	adds r2, r4, 0
	adds r2, 0x62
	strh r0, [r2]
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C3066
	ldrb r0, [r4, 0x1]
	adds r0, 0x1
	strb r0, [r4, 0x1]
_080C3066:
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _080C3084
	ldr r2, =gUnknown_08329D54
	ldrh r0, [r4, 0xE]
	movs r1, 0x7
	ands r0, r1
	adds r0, 0x8
	b _080C308C
	.pool
_080C3084:
	ldr r2, =gUnknown_08329D54
	ldrh r0, [r4, 0xE]
	movs r1, 0x7
	ands r0, r1
_080C308C:
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	adds r0, r4, 0
	adds r0, 0x4F
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3020

	thumb_func_start TrainerCard_GenerateCardForPlayer
TrainerCard_GenerateCardForPlayer: @ 80C30A4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	adds r1, r4, 0
	adds r1, 0x38
	movs r0, 0x3
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80C2EC4
	bl sub_80C2DFC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x3A]
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r2, =0x00000eba
	adds r1, r2
	ldrh r1, [r1]
	strh r1, [r4, 0x3C]
	cmp r0, 0
	beq _080C30E0
	ldrb r0, [r4, 0x1]
	adds r0, 0x1
	strb r0, [r4, 0x1]
_080C30E0:
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _080C3100
	ldr r2, =gUnknown_08329D54
	ldrh r0, [r4, 0xE]
	movs r1, 0x7
	ands r0, r1
	adds r0, 0x8
	b _080C3108
	.pool
_080C3100:
	ldr r2, =gUnknown_08329D54
	ldrh r0, [r4, 0xE]
	movs r1, 0x7
	ands r0, r1
_080C3108:
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	adds r0, r4, 0
	adds r0, 0x4F
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TrainerCard_GenerateCardForPlayer

	thumb_func_start sub_80C3120
sub_80C3120: @ 80C3120
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	movs r1, 0
	movs r2, 0x64
	bl memset
	adds r0, r5, 0
	adds r0, 0x38
	strb r4, [r0]
	adds r0, r4, 0
	bl sub_80C4FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080C3162
	cmp r0, 0x1
	bgt _080C3150
	cmp r0, 0
	beq _080C3156
	b _080C318A
_080C3150:
	cmp r0, 0x2
	beq _080C316E
	b _080C318A
_080C3156:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x60
	bl memcpy
	b _080C318A
_080C3162:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x38
	bl memcpy
	b _080C318A
_080C316E:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x60
	bl memcpy
	movs r0, 0
	str r0, [r5, 0x3C]
	ldrh r1, [r6, 0x3A]
	adds r0, r5, 0
	adds r0, 0x60
	strh r1, [r0]
	ldrh r1, [r6, 0x3C]
	adds r0, 0x2
	strh r1, [r0]
_080C318A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80C3120

	thumb_func_start sub_80C3190
sub_80C3190: @ 80C3190
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0xA]
	ldr r0, [r4]
	strb r1, [r0, 0xB]
	ldr r0, [r4]
	strb r1, [r0, 0xC]
	ldr r0, [r4]
	strb r1, [r0, 0xD]
	ldr r0, [r4]
	strb r1, [r0, 0xE]
	ldr r0, [r4]
	strb r1, [r0, 0xF]
	ldr r0, [r4]
	strb r1, [r0, 0x10]
	ldr r0, [r4]
	adds r0, 0x11
	movs r2, 0x8
	bl memset
	ldr r1, [r4]
	ldr r2, =0x00000536
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C31CE
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
_080C31CE:
	ldr r1, [r4]
	ldr r3, =0x0000053a
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, 0
	bne _080C31E4
	ldr r2, =0x0000053c
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _080C31EA
_080C31E4:
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	strb r0, [r1, 0xB]
_080C31EA:
	ldr r2, =gUnknown_02039CE8
	ldr r1, [r2]
	movs r3, 0xA9
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, 0
	beq _080C3200
	ldrb r0, [r1, 0xC]
	adds r0, 0x1
	strb r0, [r1, 0xC]
_080C3200:
	ldr r1, [r2]
	ldr r3, =0x00000554
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C3212
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
_080C3212:
	ldr r1, [r2]
	ldr r2, =0x0000054c
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _080C3224
	ldrb r0, [r1, 0xD]
	adds r0, 0x1
	strb r0, [r1, 0xD]
_080C3224:
	movs r5, 0
	ldr r4, =0x00000867
_080C3228:
	lsls r0, r4, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C3244
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	adds r1, 0x11
	adds r1, r5
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C3244:
	adds r4, 0x1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =0x0000086e
	cmp r4, r0
	bls _080C3228
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3190

	thumb_func_start sub_80C3278
sub_80C3278: @ 80C3278
	push {lr}
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0xC1
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x1E
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0xA0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C32E0
	movs r0, 0xC7
	bl EnableInterrupts
	b _080C32E6
	.pool
_080C32E0:
	movs r0, 0x3
	bl EnableInterrupts
_080C32E6:
	pop {r0}
	bx r0
	thumb_func_end sub_80C3278

	thumb_func_start sub_80C32EC
sub_80C32EC: @ 80C32EC
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0x28
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bgt _080C3306
	movs r2, 0
_080C3306:
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x54
	bl SetGpuReg
	ldr r0, [r4]
	ldr r1, =0x00007ca8
	adds r0, r1
	ldrh r2, [r0]
	lsls r1, r2, 8
	movs r0, 0xA0
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x44
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C32EC

	thumb_func_start sub_80C334C
sub_80C334C: @ 80C334C
	push {lr}
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_80C334C

	thumb_func_start sub_80C3388
sub_80C3388: @ 80C3388
	push {lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0856FAB4
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
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_0856FAC4
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl sub_81973A4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3388

	thumb_func_start sub_80C3404
sub_80C3404: @ 80C3404
	push {lr}
	ldr r0, =sub_80C2710
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3404

	thumb_func_start sub_80C3414
sub_80C3414: @ 80C3414
	push {lr}
	bl ResetTasks
	bl ScanlineEffect_Stop
	ldr r0, =sub_80C2760
	movs r1, 0
	bl CreateTask
	bl sub_80C4EE4
	bl sub_80C3190
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3414

	thumb_func_start sub_80C3438
sub_80C3438: @ 80C3438
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x5
	bhi _080C3494
	lsls r0, 2
	ldr r1, =_080C3458
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C3458:
	.4byte _080C3470
	.4byte _080C3476
	.4byte _080C347C
	.4byte _080C3482
	.4byte _080C3488
	.4byte _080C348E
_080C3470:
	bl sub_80C3574
	b _080C349C
_080C3476:
	bl sub_80C3608
	b _080C349C
_080C347C:
	bl sub_80C3684
	b _080C349C
_080C3482:
	bl sub_80C378C
	b _080C349C
_080C3488:
	bl sub_80C3880
	b _080C349C
_080C348E:
	bl sub_80C3A18
	b _080C349C
_080C3494:
	movs r0, 0
	strb r0, [r1, 0x1]
	movs r0, 0x1
	b _080C34A8
_080C349C:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0
_080C34A8:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C3438

	thumb_func_start sub_80C34B0
sub_80C34B0: @ 80C34B0
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x7
	bhi _080C352C
	lsls r0, 2
	ldr r1, =_080C34D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C34D0:
	.4byte _080C34F0
	.4byte _080C34F6
	.4byte _080C34FC
	.4byte _080C3502
	.4byte _080C3508
	.4byte _080C3512
	.4byte _080C351C
	.4byte _080C3526
_080C34F0:
	bl sub_80C3B50
	b _080C3534
_080C34F6:
	bl sub_80C3CCC
	b _080C3534
_080C34FC:
	bl sub_80C3D60
	b _080C3534
_080C3502:
	bl sub_80C3DF0
	b _080C3534
_080C3508:
	bl sub_80C3E58
	bl sub_80C3F64
	b _080C3534
_080C3512:
	bl sub_80C3ED4
	bl sub_80C3FE0
	b _080C3534
_080C351C:
	bl sub_80C4140
	bl sub_80C40CC
	b _080C3534
_080C3526:
	bl sub_80C42A4
	b _080C3534
_080C352C:
	movs r0, 0
	strb r0, [r1, 0x1]
	movs r0, 0x1
	b _080C3540
_080C3534:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0
_080C3540:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C34B0

	thumb_func_start sub_80C3548
sub_80C3548: @ 80C3548
	push {lr}
	bl sub_80C3AF0
	bl sub_80C3BC4
	bl sub_80C3CF4
	bl sub_80C3DC0
	bl sub_80C3E20
	bl sub_80C3E98
	bl sub_80C3F14
	bl sub_80C3FA4
	bl sub_80C4020
	pop {r0}
	bx r0
	thumb_func_end sub_80C3548

	thumb_func_start sub_80C3574
sub_80C3574: @ 80C3574
	push {r4,r5,lr}
	sub sp, 0x2C
	ldr r1, =gText_TrainerCardName
	add r0, sp, 0xC
	bl StringCopy
	adds r5, r0, 0
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r0, =0x00000564
	adds r1, r0
	adds r0, r5, 0
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00007caa
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl ConvertInternationalString
	ldr r0, [r4]
	ldr r1, =0x0000052a
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C35E0
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x14
	movs r3, 0x1C
	bl AddTextPrinterParameterized3
	b _080C35FA
	.pool
_080C35E0:
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x21
	bl AddTextPrinterParameterized3
_080C35FA:
	add sp, 0x2C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3574

	thumb_func_start sub_80C3608
sub_80C3608: @ 80C3608
	push {r4,lr}
	sub sp, 0x2C
	ldr r1, =gText_TrainerCardIDNo
	add r0, sp, 0xC
	bl StringCopy
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r2, =0x00000542
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	ldr r1, =0x0000052a
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3650
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x50
	bl GetStringCenterAlignXOffset
	adds r0, 0x84
	b _080C365C
	.pool
_080C3650:
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x60
	bl GetStringCenterAlignXOffset
	adds r0, 0x78
_080C365C:
	movs r3, 0x9
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x2C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3608

	thumb_func_start sub_80C3684
sub_80C3684: @ 80C3684
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C36C4
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardMoney
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x14
	movs r3, 0x38
	bl AddTextPrinterParameterized3
	b _080C36DE
	.pool
_080C36C4:
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardMoney
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x39
	bl AddTextPrinterParameterized3
_080C36DE:
	ldr r0, =gStringVar1
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	movs r2, 0xAB
	lsls r2, 3
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar4
	ldr r1, =gText_PokedollarVar1
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r0, [r4]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3734
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x90
	bl GetStringRightAlignXOffset
	movs r3, 0x38
	b _080C3740
	.pool
_080C3734:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringRightAlignXOffset
	movs r3, 0x39
_080C3740:
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gStringVar4
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3684

	thumb_func_start sub_80C376C
sub_80C376C: @ 80C376C
	push {lr}
	bl IsNationalPokedexEnabled
	cmp r0, 0
	bne _080C377E
	movs r0, 0x1
	bl GetHoennPokedexCount
	b _080C3784
_080C377E:
	movs r0, 0x1
	bl GetNationalPokedexCount
_080C3784:
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_80C376C

	thumb_func_start sub_80C378C
sub_80C378C: @ 80C378C
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =0x00000861
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C386E
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C37DC
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardPokedex
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x14
	movs r3, 0x48
	bl AddTextPrinterParameterized3
	b _080C37F6
	.pool
_080C37DC:
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardPokedex
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x49
	bl AddTextPrinterParameterized3
_080C37F6:
	ldr r5, =gStringVar4
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	movs r1, 0xA8
	lsls r1, 3
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r1, =gText_EmptyString6
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3848
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x90
	bl GetStringRightAlignXOffset
	movs r3, 0x48
	b _080C3854
	.pool
_080C3848:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringRightAlignXOffset
	movs r3, 0x49
_080C3854:
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gStringVar4
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl AddTextPrinterParameterized3
_080C386E:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C378C

	thumb_func_start sub_80C3880
sub_80C3880: @ 80C3880
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C38C8
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardTime
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x14
	movs r3, 0x58
	bl AddTextPrinterParameterized3
	b _080C38E2
	.pool
_080C38C8:
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, =gText_TrainerCardTime
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x59
	bl AddTextPrinterParameterized3
_080C38E2:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _080C390C
	ldr r2, =0x00000544
	adds r0, r1, r2
	ldrh r5, [r0]
	adds r2, 0x2
	adds r0, r1, r2
	ldrh r6, [r0]
	b _080C3914
	.pool
_080C390C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrh r5, [r0, 0xE]
	ldrb r6, [r0, 0x10]
_080C3914:
	ldr r0, =0x000003e7
	cmp r5, r0
	bls _080C391C
	adds r5, r0, 0
_080C391C:
	cmp r6, 0x3B
	bls _080C3922
	movs r6, 0x3B
_080C3922:
	ldr r1, =gText_Colon2
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	mov r10, r0
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052b
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3958
	movs r7, 0x90
	movs r4, 0x58
	b _080C395C
	.pool
_080C3958:
	movs r7, 0x80
	movs r4, 0x59
_080C395C:
	mov r0, r10
	adds r0, 0x1E
	subs r7, r0
	lsls r2, r7, 16
	lsrs r2, 16
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	adds r3, r4, 0
	bl FillWindowPixelRect
	ldr r2, =gStringVar4
	mov r9, r2
	mov r0, r9
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	lsls r2, r7, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0856FB0C
	mov r8, r0
	str r0, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	adds r7, 0x12
	lsls r2, r7, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0856FB40
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp]
	str r5, [sp, 0x4]
	ldr r0, =gText_Colon2
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add r7, r10
	mov r0, r9
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r2, r7, 24
	lsrs r2, 24
	mov r0, r8
	str r0, [sp]
	str r5, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3880

	thumb_func_start sub_80C3A18
sub_80C3A18: @ 80C3A18
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r7, =gUnknown_02039CE8
	ldr r1, [r7]
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _080C3ACE
	ldr r0, =gUnknown_0856FB48
	mov r8, r0
	ldr r4, =0x0000052b
	adds r0, r1, r4
	ldrb r0, [r0]
	add r0, r8
	ldrb r3, [r0]
	ldr r6, =gUnknown_0856FB0C
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0x19
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x8
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r1, 0x19
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r2, r0, 0
	adds r2, 0xE
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [r7]
	adds r0, r1, r4
	ldrb r0, [r0]
	add r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	adds r1, 0x26
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	ldr r0, =gUnknown_0856FB4A
	mov r8, r0
	ldr r1, [r7]
	adds r0, r1, r4
	ldrb r0, [r0]
	add r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	adds r1, 0x33
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x8
	bl AddTextPrinterParameterized3
	ldr r1, [r7]
	adds r1, 0x33
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r2, r0, 0
	adds r2, 0xE
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [r7]
	adds r4, r1, r4
	ldrb r0, [r4]
	add r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	str r5, [sp, 0x4]
	adds r1, 0x40
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl AddTextPrinterParameterized3
_080C3ACE:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3A18

	thumb_func_start sub_80C3AF0
sub_80C3AF0: @ 80C3AF0
	push {r4,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4D
	ldr r2, =0x00000564
	adds r1, r2
	bl StringCopy
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4D
	ldr r2, =0x00007caa
	adds r1, r2
	ldrb r1, [r1]
	bl ConvertInternationalString
	ldr r1, [r4]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C3B30
	ldr r0, =gStringVar1
	adds r1, 0x4D
	bl StringCopy
	ldr r0, [r4]
	adds r0, 0x4D
	ldr r1, =gText_Var1sTrainerCard
	bl StringExpandPlaceholders
_080C3B30:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3AF0

	thumb_func_start sub_80C3B50
sub_80C3B50: @ 80C3B50
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r2, =0x0000052b
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3B8C
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0x4D
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x88
	movs r3, 0x9
	bl AddTextPrinterParameterized3
	b _080C3BB6
	.pool
_080C3B8C:
	adds r1, 0x4D
	movs r0, 0x1
	movs r2, 0xD8
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, [r4]
	adds r0, 0x4D
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x9
	bl AddTextPrinterParameterized3
_080C3BB6:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3B50

	thumb_func_start sub_80C3BC4
sub_80C3BC4: @ 80C3BC4
	push {r4,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldrb r0, [r1, 0xB]
	cmp r0, 0
	beq _080C3C0E
	ldr r0, =gStringVar1
	ldr r2, =0x0000053a
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	ldr r1, [r4]
	ldr r2, =0x0000053c
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar3
	ldr r1, [r4]
	ldr r2, =0x0000053e
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x93
	ldr r1, =gUnknown_0856FB4C
	bl StringExpandPlaceholders
_080C3C0E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3BC4

	thumb_func_start sub_80C3C34
sub_80C3C34: @ 80C3C34
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0xC
	adds r4, r0, 0
	mov r9, r2
	mov r10, r3
	ldr r2, =gUnknown_0856FB55
	ldr r6, =gUnknown_02039CE8
	ldr r0, [r6]
	ldr r5, =0x0000052b
	adds r0, r5
	ldrb r0, [r0]
	adds r0, r2
	ldrb r2, [r0]
	lsls r4, 28
	movs r0, 0x84
	lsls r0, 22
	adds r4, r0
	lsrs r4, 24
	ldr r0, =gUnknown_0856FB0C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	ldr r1, =gUnknown_0856FB57
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	movs r0, 0x1
	mov r1, r9
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r0, r10
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3C34

	thumb_func_start sub_80C3CCC
sub_80C3CCC: @ 80C3CCC
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _080C3CE4
	ldr r1, =gText_HallOfFameDebut
	adds r2, 0x93
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0
	bl sub_80C3C34
_080C3CE4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3CCC

	thumb_func_start sub_80C3CF4
sub_80C3CF4: @ 80C3CF4
	push {r4,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _080C3D40
	adds r0, r1, 0
	adds r0, 0xD9
	ldr r2, =gUnknown_0856FB5C
	ldr r3, =0x0000052a
	adds r1, r3
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r1, [r4]
	ldr r2, =0x00000165
	adds r0, r1, r2
	movs r3, 0xA9
	lsls r3, 3
	adds r1, r3
	ldrh r1, [r1]
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r1, [r4]
	ldr r2, =0x000001ab
	adds r0, r1, r2
	ldr r3, =0x0000054a
	adds r1, r3
	ldrh r1, [r1]
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
_080C3D40:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3CF4

	thumb_func_start sub_80C3D60
sub_80C3D60: @ 80C3D60
	push {r4,r5,lr}
	ldr r5, =gUnknown_02039CE8
	ldr r1, [r5]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _080C3D9A
	ldr r0, =gStringVar1
	ldr r2, =0x00000165
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r1, [r5]
	ldr r2, =0x000001ab
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_WinsLosses
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r1, [r5]
	adds r1, 0xD9
	ldr r3, =gUnknown_0856FB0C
	movs r0, 0x1
	adds r2, r4, 0
	bl sub_80C3C34
_080C3D9A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3D60

	thumb_func_start sub_80C3DC0
sub_80C3DC0: @ 80C3DC0
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _080C3DDE
	ldr r2, =0x00000237
	adds r0, r1, r2
	ldr r2, =0x00000554
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
_080C3DDE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3DC0

	thumb_func_start sub_80C3DF0
sub_80C3DF0: @ 80C3DF0
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldrb r0, [r2, 0x10]
	cmp r0, 0
	beq _080C3E0A
	ldr r1, =gText_PokemonTrades
	ldr r0, =0x00000237
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x2
	bl sub_80C3C34
_080C3E0A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3DF0

	thumb_func_start sub_80C3E20
sub_80C3E20: @ 80C3E20
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3E48
	movs r3, 0xAE
	lsls r3, 3
	adds r0, r2, r3
	ldr r1, [r0]
	cmp r1, 0
	beq _080C3E48
	ldr r3, =0x000002c3
	adds r0, r2, r3
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
_080C3E48:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3E20

	thumb_func_start sub_80C3E58
sub_80C3E58: @ 80C3E58
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3E80
	adds r1, 0x46
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080C3E80
	ldr r1, =gText_BerryCrush
	ldr r0, =0x000002c3
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x4
	bl sub_80C3C34
_080C3E80:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3E58

	thumb_func_start sub_80C3E98
sub_80C3E98: @ 80C3E98
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3EBE
	ldr r3, =0x00000574
	adds r0, r2, r3
	ldr r1, [r0]
	cmp r1, 0
	beq _080C3EBE
	ldr r3, =0x0000034f
	adds r0, r2, r3
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
_080C3EBE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3E98

	thumb_func_start sub_80C3ED4
sub_80C3ED4: @ 80C3ED4
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C3EFC
	adds r1, 0x4A
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080C3EFC
	ldr r1, =gText_UnionTradesAndBattles
	ldr r0, =0x0000034f
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x3
	bl sub_80C3C34
_080C3EFC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3ED4

	thumb_func_start sub_80C3F14
sub_80C3F14: @ 80C3F14
	push {r4,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C3F46
	ldr r0, =0x00000552
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C3F46
	ldr r0, =gStringVar1
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	ldr r1, =0x00000395
	adds r0, r1
	ldr r1, =gText_Var1DarkGreyShadowLightGrey
	bl StringExpandPlaceholders
_080C3F46:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3F14

	thumb_func_start sub_80C3F64
sub_80C3F64: @ 80C3F64
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C3F8C
	adds r1, 0x28
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C3F8C
	ldr r1, =gText_PokeblocksWithFriends
	ldr r0, =0x00000395
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x3
	bl sub_80C3C34
_080C3F8C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3F64

	thumb_func_start sub_80C3FA4
sub_80C3FA4: @ 80C3FA4
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C3FCE
	movs r3, 0xAA
	lsls r3, 3
	adds r2, r1, r3
	ldrh r0, [r2]
	cmp r0, 0
	beq _080C3FCE
	ldr r3, =0x000003db
	adds r0, r1, r3
	ldrh r1, [r2]
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
_080C3FCE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3FA4

	thumb_func_start sub_80C3FE0
sub_80C3FE0: @ 80C3FE0
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C4008
	adds r1, 0x26
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C4008
	ldr r1, =gText_WonContestsWFriends
	ldr r0, =0x000003db
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x4
	bl sub_80C3C34
_080C4008:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C3FE0

	thumb_func_start sub_80C4020
sub_80C4020: @ 80C4020
	push {r4,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C4044
	cmp r0, 0x1
	ble _080C40B6
	cmp r0, 0x2
	beq _080C4094
	b _080C40B6
	.pool
_080C4044:
	ldrb r0, [r1, 0xD]
	cmp r0, 0
	beq _080C40B6
	ldr r0, =gStringVar1
	ldr r2, =0x0000054c
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gStringVar2
	ldr r1, [r4]
	ldr r2, =0x0000054e
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	ldr r1, =0x00000421
	adds r0, r1
	ldr r1, =gText_WSlashStraightSlash
	bl StringExpandPlaceholders
	b _080C40B6
	.pool
_080C4094:
	ldr r2, =0x00000596
	adds r1, r2
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C40B6
	ldr r0, =gStringVar1
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	ldr r1, =0x00000421
	adds r0, r1
	ldr r1, =gText_Var1DarkLightGreyBP
	bl StringExpandPlaceholders
_080C40B6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4020

	thumb_func_start sub_80C40CC
sub_80C40CC: @ 80C40CC
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r2, [r0]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C40F0
	cmp r0, 0x1
	ble _080C412C
	cmp r0, 0x2
	beq _080C4114
	b _080C412C
	.pool
_080C40F0:
	ldrb r0, [r2, 0xD]
	cmp r0, 0
	beq _080C412C
	ldr r1, =gText_BattleTower
	ldr r0, =0x00000421
	adds r2, r0
	ldr r3, =gUnknown_0856FB0C
	movs r0, 0x5
	bl sub_80C3C34
	b _080C412C
	.pool
_080C4114:
	ldr r1, =0x00000596
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C412C
	ldr r1, =gText_BattlePtsWon
	ldr r0, =0x00000421
	adds r2, r0
	ldr r3, =gUnknown_0856FB0F
	movs r0, 0x5
	bl sub_80C3C34
_080C412C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C40CC

	thumb_func_start sub_80C4140
sub_80C4140: @ 80C4140
	push {r4,r5,lr}
	sub sp, 0x20
	ldr r1, =gUnknown_0856FB68
	add r0, sp, 0x10
	movs r2, 0x6
	bl memcpy
	add r4, sp, 0x18
	ldr r1, =gUnknown_0856FB6E
	adds r0, r4, 0
	movs r2, 0x6
	bl memcpy
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x0000052a
	adds r0, r1
	ldrb r0, [r0]
	adds r5, r4, 0
	cmp r0, 0
	bne _080C41C0
	movs r4, 0
_080C416C:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	lsls r1, r4, 1
	movs r2, 0xB1
	lsls r2, 3
	adds r0, r2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C41B6
	bl sub_80D30A0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 20
	movs r2, 0xE0
	lsls r2, 16
	adds r1, r2
	lsrs r1, 16
	adds r2, r5, r4
	ldrb r2, [r2]
	adds r2, 0x3
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0x4
	str r3, [sp]
	str r3, [sp, 0x4]
	add r0, sp
	adds r0, 0x10
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x3
	movs r3, 0xF
	bl WriteSequenceToBgTilemapBuffer
_080C41B6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _080C416C
_080C41C0:
	add sp, 0x20
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4140

	thumb_func_start sub_80C41D8
sub_80C41D8: @ 80C41D8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gMonIconPalettes
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	movs r5, 0x8D
	lsls r5, 3
	adds r1, r5
	movs r2, 0x60
	bl CpuSet
	ldr r4, [r4]
	ldr r1, =0x00000582
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080C4214
	cmp r0, 0x1
	ble _080C424A
	cmp r0, 0x2
	beq _080C422A
	cmp r0, 0x3
	beq _080C4242
	b _080C424A
	.pool
_080C4214:
	movs r2, 0x8D
	lsls r2, 3
	adds r0, r4, r2
	movs r1, 0
	str r1, [sp]
	movs r1, 0x60
	movs r2, 0
	movs r3, 0
	bl TintPalette_CustomTone
	b _080C424A
_080C422A:
	adds r0, r4, r5
	movs r2, 0xFA
	lsls r2, 1
	movs r3, 0xA5
	lsls r3, 1
	movs r1, 0x9B
	lsls r1, 1
	str r1, [sp]
	movs r1, 0x60
	bl TintPalette_CustomTone
	b _080C424A
_080C4242:
	adds r0, r4, r5
	movs r1, 0x60
	bl TintPalette_SepiaTone
_080C424A:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	movs r1, 0x8D
	lsls r1, 3
	adds r0, r1
	movs r1, 0x50
	movs r2, 0xC0
	bl LoadPalette
	movs r4, 0
_080C425E:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	lsls r1, r4, 1
	movs r2, 0xB1
	lsls r2, 3
	adds r0, r2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	beq _080C428E
	movs r1, 0
	bl GetMonIconTiles
	adds r1, r0, 0
	lsls r3, r4, 20
	movs r0, 0x80
	lsls r0, 14
	adds r3, r0
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x80
	lsls r2, 2
	bl LoadBgTiles
_080C428E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _080C425E
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C41D8

	thumb_func_start sub_80C42A4
sub_80C42A4: @ 80C42A4
	push {r4,lr}
	sub sp, 0x14
	ldr r1, =gUnknown_0856FB74
	add r0, sp, 0x10
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C4316
	adds r2, 0x56
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080C4316
	movs r4, 0
_080C42CC:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x00000584
	adds r0, r1
	adds r0, r4
	ldrb r3, [r0]
	cmp r3, 0
	beq _080C430C
	lsls r1, r4, 18
	movs r2, 0xA0
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	lsls r2, r4, 1
	adds r2, r4
	adds r2, 0x2
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x2
	str r0, [sp]
	str r0, [sp, 0x4]
	subs r0, r3, 0x1
	add r0, sp
	adds r0, 0x10
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x3
	movs r3, 0x2
	bl WriteSequenceToBgTilemapBuffer
_080C430C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C42CC
_080C4316:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C42A4

	thumb_func_start sub_80C4330
sub_80C4330: @ 80C4330
	push {lr}
	ldr r0, =gUnknown_0856F54C
	movs r1, 0xB0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0856F56C
	movs r1, 0xC0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0856F58C
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0856F5AC
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r0, =0x000017a8
	adds r1, r0
	movs r2, 0x80
	lsls r2, 3
	movs r0, 0x3
	movs r3, 0x80
	bl LoadBgTiles
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4330

	thumb_func_start sub_80C438C
sub_80C438C: @ 80C438C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80C438C

	thumb_func_start sub_80C43A8
sub_80C43A8: @ 80C43A8
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0x4
	bls _080C43B8
	b _080C4532
_080C43B8:
	lsls r0, 2
	ldr r1, =_080C43CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C43CC:
	.4byte _080C43E0
	.4byte _080C43F8
	.4byte _080C4418
	.4byte _080C44D8
	.4byte _080C4500
_080C43E0:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r0, =0x000013a8
	adds r1, r0
	movs r2, 0x80
	lsls r2, 3
	movs r0, 0x3
	b _080C4406
	.pool
_080C43F8:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldr r3, =0x000019a8
	adds r1, r3
	movs r2, 0xC0
	lsls r2, 5
	movs r0, 0
_080C4406:
	movs r3, 0
	bl LoadBgTiles
	b _080C4536
	.pool
_080C4418:
	ldr r4, =gUnknown_02039CE8
	ldr r2, [r4]
	ldr r1, =0x0000052a
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C447C
	ldr r1, =gEmeraldTrainerCardStarPals
	ldr r3, =0x00000535
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x60
	bl LoadPalette
	ldr r0, =gUnknown_0856F4EC
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r0, [r4]
	ldr r1, =0x00000534
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C44B2
	ldr r0, =gUnknown_0856F4AC
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	b _080C44B2
	.pool
_080C447C:
	ldr r1, =gFireRedTrainerCardStarPals
	ldr r3, =0x00000535
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x60
	bl LoadPalette
	ldr r0, =gUnknown_0856F50C
	movs r1, 0x30
	movs r2, 0x20
	bl LoadPalette
	ldr r0, [r4]
	ldr r1, =0x00000534
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C44B2
	ldr r0, =gUnknown_0856F4CC
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
_080C44B2:
	ldr r0, =gUnknown_0856F52C
	movs r1, 0x40
	movs r2, 0x20
	bl LoadPalette
	b _080C4536
	.pool
_080C44D8:
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r3, =0x00003ca8
	adds r1, r3
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00005ca8
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	b _080C4536
	.pool
_080C4500:
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
_080C4532:
	movs r0, 0x1
	b _080C4542
_080C4536:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
	movs r0, 0
_080C4542:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C43A8

	thumb_func_start sub_80C4550
sub_80C4550: @ 80C4550
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x00005ca8
	adds r6, r0, r1
	movs r1, 0
_080C455E:
	movs r2, 0
	lsls r5, r1, 16
	asrs r1, r5, 16
	lsls r3, r1, 5
	lsls r0, r1, 4
	subs r0, r1
	lsls r4, r0, 1
_080C456C:
	lsls r0, r2, 16
	asrs r1, r0, 16
	adds r2, r0, 0
	cmp r1, 0x1D
	bgt _080C4590
	adds r0, r3, r1
	lsls r0, 1
	adds r0, r6
	adds r1, r4, r1
	lsls r1, 1
	adds r1, r7
	ldrh r1, [r1]
	b _080C4598
	.pool
_080C4590:
	adds r0, r3, r1
	lsls r0, 1
	adds r0, r6
	ldrh r1, [r7]
_080C4598:
	strh r1, [r0]
	movs r1, 0x80
	lsls r1, 9
	adds r0, r2, r1
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	ble _080C456C
	adds r0, r5, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080C455E
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C4550

	thumb_func_start sub_80C45C0
sub_80C45C0: @ 80C45C0
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldr r1, =0x00003ca8
	adds r6, r0, r1
	movs r1, 0
_080C45CE:
	movs r2, 0
	lsls r5, r1, 16
	asrs r1, r5, 16
	lsls r3, r1, 5
	lsls r0, r1, 4
	subs r0, r1
	lsls r4, r0, 1
_080C45DC:
	lsls r0, r2, 16
	asrs r1, r0, 16
	adds r2, r0, 0
	cmp r1, 0x1D
	bgt _080C4600
	adds r0, r3, r1
	lsls r0, 1
	adds r0, r6
	adds r1, r4, r1
	lsls r1, 1
	adds r1, r7
	ldrh r1, [r1]
	b _080C4608
	.pool
_080C4600:
	adds r0, r3, r1
	lsls r0, 1
	adds r0, r6
	ldrh r1, [r7]
_080C4608:
	strh r1, [r0]
	movs r1, 0x80
	lsls r1, 9
	adds r0, r2, r1
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	ble _080C45DC
	adds r0, r5, r1
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080C45CE
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80C45C0

	thumb_func_start sub_80C4630
sub_80C4630: @ 80C4630
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0xC0
	mov r8, r0
	movs r2, 0x3
	mov r10, r2
	ldr r2, =gUnknown_0856FB78
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	ldr r3, =0x0000052b
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r0, r2
	ldrb r3, [r0]
	ldr r0, =0x00000535
	adds r1, r0
	ldrb r0, [r1]
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x4
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8F
	movs r2, 0xF
	bl FillBgTilemapBufferRect
	ldr r0, [r4]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	bne _080C4724
	movs r2, 0x4
	mov r9, r2
	movs r2, 0
	movs r6, 0x1
_080C467E:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	lsls r0, r2, 16
	asrs r7, r0, 16
	adds r1, 0x11
	adds r1, r7
	ldrb r0, [r1]
	cmp r0, 0
	beq _080C4700
	mov r3, r9
	lsls r5, r3, 24
	lsrs r5, 24
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	movs r0, 0x3
	mov r1, r8
	adds r2, r5, 0
	movs r3, 0xF
	bl FillBgTilemapBufferRect
	mov r1, r8
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	mov r4, r9
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	movs r0, 0x3
	adds r2, r4, 0
	movs r3, 0xF
	bl FillBgTilemapBufferRect
	mov r1, r8
	adds r1, 0x10
	lsls r1, 16
	lsrs r1, 16
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r3, r10
	str r3, [sp, 0x8]
	movs r0, 0x3
	adds r2, r5, 0
	movs r3, 0x10
	bl FillBgTilemapBufferRect
	mov r1, r8
	adds r1, 0x11
	lsls r1, 16
	lsrs r1, 16
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	movs r0, 0x3
	adds r2, r4, 0
	movs r3, 0x10
	bl FillBgTilemapBufferRect
_080C4700:
	adds r0, r7, 0x1
	lsls r0, 16
	mov r1, r8
	adds r1, 0x2
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	mov r2, r9
	lsls r1, r2, 16
	movs r3, 0xC0
	lsls r3, 10
	adds r1, r3
	lsrs r1, 16
	mov r9, r1
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080C467E
_080C4724:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4630

	thumb_func_start sub_80C474C
sub_80C474C: @ 80C474C
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r6, =gUnknown_02039CE8
	ldr r1, [r6]
	ldr r2, =0x0000052a
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080C4800
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _080C478A
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x1B
	movs r3, 0x9
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x1B
	movs r3, 0xA
	bl FillBgTilemapBufferRect
_080C478A:
	ldr r0, [r6]
	movs r1, 0xAE
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080C47BE
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x15
	movs r3, 0xD
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x15
	movs r3, 0xE
	bl FillBgTilemapBufferRect
_080C47BE:
	ldr r0, [r6]
	ldr r2, =0x00000574
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _080C48B8
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x1B
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x1B
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	b _080C48B8
	.pool
_080C4800:
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _080C482E
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x1B
	movs r3, 0x9
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x1B
	movs r3, 0xA
	bl FillBgTilemapBufferRect
_080C482E:
	ldr r0, [r6]
	movs r1, 0xAA
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _080C4864
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x1B
	movs r3, 0xD
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x1B
	movs r3, 0xE
	bl FillBgTilemapBufferRect
_080C4864:
	ldr r0, [r6]
	ldrb r0, [r0, 0xD]
	cmp r0, 0
	beq _080C48B8
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8D
	movs r2, 0x11
	movs r3, 0xF
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9D
	movs r2, 0x11
	movs r3, 0x10
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x8C
	movs r2, 0x1B
	movs r3, 0xF
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x9C
	movs r2, 0x1B
	movs r3, 0x10
	bl FillBgTilemapBufferRect
_080C48B8:
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80C474C

	thumb_func_start sub_80C48C8
sub_80C48C8: @ 80C48C8
	push {lr}
	ldr r3, =gUnknown_02039CE8
	ldr r1, [r3]
	ldrb r0, [r1, 0x6]
	adds r0, 0x1
	strb r0, [r1, 0x6]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3C
	bls _080C48F6
	ldr r1, [r3]
	movs r0, 0
	strb r0, [r1, 0x6]
	ldr r2, [r3]
	ldrb r0, [r2, 0x7]
	movs r1, 0x1
	eors r0, r1
	strb r0, [r2, 0x7]
	ldr r0, [r3]
	ldr r1, =0x00000529
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080C48F6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C48C8

	thumb_func_start sub_80C4904
sub_80C4904: @ 80C4904
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTrainerCards
	movs r1, 0x64
	muls r0, r1
	adds r0, r2
	ldrb r0, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_80C4904

	thumb_func_start sub_80C4918
sub_80C4918: @ 80C4918
	push {r4,lr}
	ldr r4, =sub_80C4960
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	ldr r0, =sub_80C26D4
	bl SetHBlankCallback
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4918

	thumb_func_start sub_80C4940
sub_80C4940: @ 80C4940
	push {lr}
	ldr r0, =sub_80C4960
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080C4958
	movs r0, 0
	b _080C495A
	.pool
_080C4958:
	movs r0, 0x1
_080C495A:
	pop {r1}
	bx r1
	thumb_func_end sub_80C4940

	thumb_func_start sub_80C4960
sub_80C4960: @ 80C4960
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0856FB28
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080C4972:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080C4972
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4960

	thumb_func_start sub_80C4998
sub_80C4998: @ 80C4998
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl HideBg
	movs r0, 0x3
	bl HideBg
	bl ScanlineEffect_Stop
	bl ScanlineEffect_Clear
	movs r1, 0
	ldr r0, =gScanlineEffectRegBuffers
	movs r2, 0
	movs r3, 0xF0
	lsls r3, 3
	adds r0, r3
_080C49BC:
	strh r2, [r0]
	adds r0, 0x2
	adds r1, 0x1
	cmp r1, 0x9F
	bls _080C49BC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4998

	thumb_func_start sub_80C49D8
sub_80C49D8: @ 80C49D8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x9]
	mov r0, r8
	ldrh r1, [r0, 0xA]
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	cmp r0, 0x4C
	ble _080C4A08
	movs r0, 0x4D
	mov r3, r8
	strh r0, [r3, 0xA]
	b _080C4A0E
	.pool
_080C4A08:
	adds r0, r1, 0x7
	mov r4, r8
	strh r0, [r4, 0xA]
_080C4A0E:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	mov r2, r8
	ldrh r1, [r2, 0xA]
	ldr r3, =0x00007ca8
	adds r0, r3
	strh r1, [r0]
	ldrh r0, [r2, 0xA]
	bl sub_80C32EC
	mov r4, r8
	movs r0, 0xA
	ldrsh r7, [r4, r0]
	movs r0, 0xA0
	subs r0, r7
	mov r9, r0
	subs r4, r0, r7
	negs r0, r7
	lsls r6, r0, 16
	movs r0, 0xA0
	lsls r0, 16
	adds r1, r4, 0
	bl __udivsi3
	adds r5, r0, 0
	ldr r1, =0xffff0000
	adds r5, r1
	adds r0, r5, 0
	muls r0, r4
	adds r0, r6, r0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl __udivsi3
	mov r10, r0
	lsls r5, 1
	movs r2, 0
	cmp r2, r7
	bcs _080C4A78
	ldr r3, =gScanlineEffectRegBuffers
_080C4A60:
	lsls r0, r2, 16
	asrs r0, 16
	lsls r1, r0, 1
	adds r1, r3
	negs r2, r0
	strh r2, [r1]
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, r7
	bcc _080C4A60
_080C4A78:
	lsls r1, r2, 16
	mov r3, r9
	lsls r0, r3, 16
	asrs r3, r0, 16
	ldr r4, =gUnknown_02039CE8
	mov r9, r4
	ldr r4, [sp]
	lsrs r7, r4, 16
	cmp r1, r0
	bge _080C4AB0
	ldr r0, =gScanlineEffectRegBuffers
	mov r12, r0
	adds r4, r3, 0
_080C4A92:
	lsrs r3, r6, 16
	adds r6, r5
	mov r2, r10
	subs r5, r2
	asrs r0, r1, 16
	lsls r1, r0, 1
	add r1, r12
	strh r3, [r1]
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, r4
	blt _080C4A92
_080C4AB0:
	adds r3, r7, 0
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _080C4ACE
	ldr r2, =gScanlineEffectRegBuffers
_080C4ABC:
	asrs r0, r1, 16
	lsls r1, r0, 1
	adds r1, r2
	strh r3, [r1]
	adds r0, 0x1
	lsls r1, r0, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _080C4ABC
_080C4ACE:
	mov r3, r9
	ldr r0, [r3]
	movs r1, 0x1
	strb r1, [r0, 0x9]
	mov r4, r8
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x4C
	ble _080C4AE6
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080C4AE6:
	movs r0, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C49D8

	thumb_func_start sub_80C4B08
sub_80C4B08: @ 80C4B08
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x9]
	bl sub_8087598
	adds r2, r4, 0
	cmp r0, 0x1
	beq _080C4C08
_080C4B20:
	ldr r3, [r2]
	ldrb r0, [r3, 0x4]
	cmp r0, 0x4
	bhi _080C4BE4
	lsls r0, 2
	ldr r1, =_080C4B3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C4B3C:
	.4byte _080C4B50
	.4byte _080C4B6C
	.4byte _080C4B8C
	.4byte _080C4BB0
	.4byte _080C4BCE
_080C4B50:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	b _080C4BF6
_080C4B6C:
	ldr r0, [r2]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _080C4B80
	bl sub_80C34B0
	lsls r0, 24
	cmp r0, 0
	bne _080C4BF6
	b _080C4C08
_080C4B80:
	bl sub_80C3438
	lsls r0, 24
	cmp r0, 0
	bne _080C4BF6
	b _080C4C08
_080C4B8C:
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _080C4BA8
	ldr r2, =0x00000a48
	adds r0, r1, r2
	bl sub_80C45C0
	b _080C4BF6
	.pool
_080C4BA8:
	movs r0, 0x1
	bl sub_80C438C
	b _080C4BF6
_080C4BB0:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _080C4BC4
	bl sub_80C474C
	b _080C4BF6
	.pool
_080C4BC4:
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	b _080C4BF6
_080C4BCE:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _080C4BF6
	bl sub_80C4FF0
	b _080C4BF6
	.pool
_080C4BE4:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x8]
	movs r0, 0x1
	strb r0, [r3, 0x9]
	ldr r0, [r2]
	strb r1, [r0, 0x4]
	b _080C4C08
_080C4BF6:
	ldr r2, =gUnknown_02039CE8
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	adds r0, 0x1
	strb r0, [r1, 0x4]
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C4B20
_080C4C08:
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4B08

	thumb_func_start sub_80C4C1C
sub_80C4C1C: @ 80C4C1C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02039CE8
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x9]
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _080C4C50
	movs r0, 0x2
	bl sub_80C438C
	ldr r0, [r4]
	ldr r1, =0x00000ef8
	adds r0, r1
	bl sub_80C4550
	ldr r0, [r4]
	movs r1, 0xB3
	lsls r1, 3
	adds r0, r1
	bl sub_80C45C0
	bl sub_80C4630
_080C4C50:
	movs r0, 0x1
	bl sub_80C438C
	ldr r2, [r4]
	ldrb r0, [r2, 0x8]
	movs r1, 0x1
	eors r0, r1
	strb r0, [r2, 0x8]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0xFA
	bl PlaySE
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4C1C

	thumb_func_start sub_80C4C84
sub_80C4C84: @ 80C4C84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	movs r2, 0
	strb r2, [r0, 0x9]
	mov r0, r8
	ldrh r1, [r0, 0xA]
	movs r3, 0xA
	ldrsh r0, [r0, r3]
	cmp r0, 0x5
	bgt _080C4CB0
	mov r4, r8
	strh r2, [r4, 0xA]
	b _080C4CB6
	.pool
_080C4CB0:
	subs r0, r1, 0x5
	mov r1, r8
	strh r0, [r1, 0xA]
_080C4CB6:
	ldr r0, =gUnknown_02039CE8
	ldr r0, [r0]
	mov r2, r8
	ldrh r1, [r2, 0xA]
	ldr r3, =0x00007ca8
	adds r0, r3
	strh r1, [r0]
	ldrh r0, [r2, 0xA]
	bl sub_80C32EC
	mov r4, r8
	movs r0, 0xA
	ldrsh r7, [r4, r0]
	movs r0, 0xA0
	subs r0, r7
	mov r9, r0
	subs r4, r0, r7
	negs r0, r7
	lsls r6, r0, 16
	movs r0, 0xA0
	lsls r0, 16
	adds r1, r4, 0
	bl __udivsi3
	adds r5, r0, 0
	ldr r1, =0xffff0000
	adds r5, r1
	adds r0, r5, 0
	muls r0, r4
	adds r0, r6, r0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl __udivsi3
	mov r10, r0
	lsrs r5, 1
	movs r2, 0
	cmp r2, r7
	bcs _080C4D20
	ldr r3, =gScanlineEffectRegBuffers
_080C4D08:
	lsls r0, r2, 16
	asrs r0, 16
	lsls r1, r0, 1
	adds r1, r3
	negs r2, r0
	strh r2, [r1]
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, r7
	bcc _080C4D08
_080C4D20:
	lsls r1, r2, 16
	mov r3, r9
	lsls r0, r3, 16
	asrs r3, r0, 16
	ldr r4, =gUnknown_02039CE8
	mov r9, r4
	ldr r4, [sp]
	lsrs r7, r4, 16
	cmp r1, r0
	bge _080C4D56
	ldr r0, =gScanlineEffectRegBuffers
	mov r12, r0
	adds r4, r3, 0
_080C4D3A:
	lsrs r3, r6, 16
	adds r6, r5
	add r5, r10
	asrs r0, r1, 16
	lsls r1, r0, 1
	add r1, r12
	strh r3, [r1]
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, r4
	blt _080C4D3A
_080C4D56:
	adds r3, r7, 0
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _080C4D74
	ldr r2, =gScanlineEffectRegBuffers
_080C4D62:
	asrs r0, r1, 16
	lsls r1, r0, 1
	adds r1, r2
	strh r3, [r1]
	adds r0, 0x1
	lsls r1, r0, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _080C4D62
_080C4D74:
	mov r1, r9
	ldr r0, [r1]
	movs r1, 0x1
	strb r1, [r0, 0x9]
	mov r2, r8
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bgt _080C4D8C
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_080C4D8C:
	movs r0, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4C84

	thumb_func_start sub_80C4DB0
sub_80C4DB0: @ 80C4DB0
	push {lr}
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0
	bl SetHBlankCallback
	ldr r0, =sub_80C4960
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4DB0

	thumb_func_start sub_80C4DDC
sub_80C4DDC: @ 80C4DDC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_02039CE8
	ldr r0, =0x00007cac
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4]
	movs r2, 0xA6
	lsls r2, 3
	adds r0, r1, r2
	str r5, [r0]
	ldr r0, =sub_80C5868
	cmp r5, r0
	bne _080C4E18
	ldr r0, =0x0000052c
	adds r1, r0
	ldr r0, =0x00007fff
	b _080C4E1E
	.pool
_080C4E18:
	ldr r2, =0x0000052c
	adds r1, r2
	movs r0, 0
_080C4E1E:
	strh r0, [r1]
	bl InUnionRoom
	adds r3, r0, 0
	cmp r3, 0x1
	bne _080C4E3C
	ldr r1, =gUnknown_02039CE8
	ldr r0, [r1]
	strb r3, [r0, 0x5]
	adds r2, r1, 0
	b _080C4E44
	.pool
_080C4E3C:
	ldr r2, =gUnknown_02039CE8
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x5]
_080C4E44:
	ldr r0, [r2]
	ldr r1, =0x00007caa
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x00000534
	adds r0, r2
	bl sub_80C3020
	ldr r0, =sub_80C2C80
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4DDC

	thumb_func_start TrainerCard_ShowLinkCard
TrainerCard_ShowLinkCard: @ 80C4E74
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_02039CE8
	ldr r0, =0x00007cac
	bl AllocZeroed
	str r0, [r5]
	movs r2, 0xA6
	lsls r2, 3
	adds r1, r0, r2
	str r6, [r1]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	ldr r0, [r5]
	ldr r1, =0x00000534
	adds r0, r1
	ldr r2, =gTrainerCards
	movs r1, 0x64
	muls r1, r4
	adds r1, r2
	movs r2, 0x64
	bl memcpy
	ldr r1, [r5]
	ldr r2, =gLinkPlayers
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x1A]
	ldr r2, =0x00007caa
	adds r1, r2
	strb r0, [r1]
	ldr r0, =sub_80C2C80
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TrainerCard_ShowLinkCard

	thumb_func_start sub_80C4EE4
sub_80C4EE4: @ 80C4EE4
	push {r4,r5,lr}
	ldr r4, =gUnknown_02039CE8
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0]
	ldr r2, [r4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x12]
	strb r0, [r2, 0x6]
	ldr r0, [r4]
	strb r1, [r0, 0x7]
	ldr r0, [r4]
	strb r1, [r0, 0x8]
	ldr r0, [r4]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	strb r1, [r0]
	bl sub_80C4F50
	ldr r1, [r4]
	ldr r3, =0x0000052a
	adds r1, r3
	strb r0, [r1]
	movs r5, 0
_080C4F18:
	movs r0, 0xD
	muls r0, r5
	adds r0, 0x19
	ldr r1, [r4]
	adds r0, r1, r0
	lsls r2, r5, 1
	ldr r3, =0x0000055c
	adds r1, r3
	adds r1, r2
	ldrh r1, [r1]
	bl CopyEasyChatWord
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080C4F18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4EE4

	thumb_func_start sub_80C4F50
sub_80C4F50: @ 80C4F50
	push {lr}
	ldr r0, =gUnknown_02039CE8
	ldr r1, [r0]
	cmp r1, 0
	bne _080C4F7C
	ldr r0, =gGameVersion
	ldrb r1, [r0]
	subs r0, r1, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080C4F74
	movs r0, 0
	b _080C4FC2
	.pool
_080C4F74:
	cmp r1, 0x3
	beq _080C4FC0
	movs r0, 0x1
	b _080C4FC2
_080C4F7C:
	ldr r2, =0x0000056c
	adds r0, r1, r2
	ldrb r2, [r0]
	subs r0, r2, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080C4FA0
	ldr r0, =0x0000052b
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	b _080C4FC2
	.pool
_080C4FA0:
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _080C4FB8
	ldr r2, =0x0000052b
	adds r1, r2
	movs r0, 0x1
	strb r0, [r1]
	b _080C4FC2
	.pool
_080C4FB8:
	ldr r0, =0x0000052b
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
_080C4FC0:
	movs r0, 0x2
_080C4FC2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C4F50

	thumb_func_start sub_80C4FCC
sub_80C4FCC: @ 80C4FCC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFC
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080C4FE2
	movs r0, 0
	b _080C4FEC
_080C4FE2:
	cmp r1, 0x3
	beq _080C4FEA
	movs r0, 0x1
	b _080C4FEC
_080C4FEA:
	movs r0, 0x2
_080C4FEC:
	pop {r1}
	bx r1
	thumb_func_end sub_80C4FCC

	thumb_func_start sub_80C4FF0
sub_80C4FF0: @ 80C4FF0
	push {r4-r6,lr}
	sub sp, 0x8
	bl InUnionRoom
	cmp r0, 0x1
	bne _080C5060
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080C5060
	ldr r5, =gUnknown_02039CE8
	ldr r0, [r5]
	ldr r1, =0x00000583
	adds r0, r1
	ldrb r0, [r0]
	bl FacilityClassToPicIndex
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_0856FB18
	ldr r1, [r5]
	ldr r3, =0x00000534
	adds r2, r1, r3
	ldrb r3, [r2]
	lsls r3, 1
	ldr r2, =0x0000052b
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r3, r1
	adds r1, r3, r4
	ldrb r2, [r1]
	adds r4, 0x1
	adds r3, r4
	ldrb r3, [r3]
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r1, 0x1
	bl sub_818D938
	b _080C50AE
	.pool
_080C5060:
	ldr r2, =gUnknown_0856FB20
	ldr r6, =gUnknown_02039CE8
	ldr r0, [r6]
	ldr r5, =0x00000534
	adds r1, r0, r5
	ldr r3, =0x0000052a
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 1
	ldrb r1, [r1]
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
	bl FacilityClassToPicIndex
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gUnknown_0856FB18
	ldr r1, [r6]
	adds r5, r1, r5
	ldrb r3, [r5]
	lsls r3, 1
	ldr r2, =0x0000052b
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r3, r1
	adds r1, r3, r4
	ldrb r2, [r1]
	adds r4, 0x1
	adds r3, r4
	ldrb r3, [r3]
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x2
	str r1, [sp, 0x4]
	movs r1, 0x1
	bl sub_818D938
_080C50AE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C4FF0

	thumb_func_start sub_80C50D0
sub_80C50D0: @ 80C50D0
	push {lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
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
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x46
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x0100c000
	mov r0, sp
	bl CpuSet
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x05000100
	bl CpuSet
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C50D0

	thumb_func_start sub_80C51C4
sub_80C51C4: @ 80C51C4
	push {lr}
	bl sub_80C51F0
	ldr r0, =sub_80C544C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C51C4

	thumb_func_start sub_80C51D8
sub_80C51D8: @ 80C51D8
	push {lr}
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldr r0, [r0]
	bl SetMainCallback2
	bl sub_80C52E4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C51D8

	thumb_func_start sub_80C51F0
sub_80C51F0: @ 80C51F0
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	cmp r0, 0
	beq _080C5204
	movs r0, 0x1
	b _080C52C8
	.pool
_080C5204:
	movs r0, 0x18
	bl AllocZeroed
	str r0, [r5]
	cmp r0, 0
	bne _080C5214
	movs r0, 0x2
	b _080C52C8
_080C5214:
	str r4, [r0]
	bl GetCurrentRegionMapSectionId
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3A
	beq _080C5232
	cmp r4, 0xCA
	beq _080C5232
	ldr r0, [r5]
	movs r1, 0xB0
	strh r1, [r0, 0x8]
	movs r1, 0x68
	strh r1, [r0, 0xA]
	b _080C5240
_080C5232:
	ldr r2, =gUnknown_02039CEC
	ldr r1, [r2]
	movs r0, 0xB0
	strh r0, [r1, 0x8]
	movs r0, 0x30
	strh r0, [r1, 0xA]
	adds r5, r2, 0
_080C5240:
	ldr r1, [r5]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000eb8
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1, 0x6]
	bl CanCopyRecordedBattleSaveData
	ldr r3, [r5]
	movs r1, 0x1
	ands r0, r1
	ldrb r2, [r3, 0xE]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xE]
	ldr r2, [r5]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	bl sub_80C2E40
	ldr r3, [r5]
	lsls r0, 4
	ldrb r2, [r3, 0xE]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xE]
	movs r4, 0
	adds r6, r5, 0
_080C5286:
	lsls r5, r4, 1
	ldr r1, =0x000008c4
	adds r0, r5, r1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C52A2
	ldr r1, [r6]
	adds r1, 0xF
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C52A2:
	ldr r2, =0x000008c5
	adds r0, r5, r2
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080C52BC
	ldr r1, [r6]
	adds r1, 0xF
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080C52BC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080C5286
	movs r0, 0
_080C52C8:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C51F0

	thumb_func_start sub_80C52E4
sub_80C52E4: @ 80C52E4
	push {r4,lr}
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	cmp r0, 0
	beq _080C5308
	movs r1, 0
	movs r2, 0x18
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	b _080C530A
	.pool
_080C5308:
	movs r0, 0x1
_080C530A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C52E4

	thumb_func_start sub_80C5310
sub_80C5310: @ 80C5310
	push {r4,lr}
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	cmp r0, 0
	beq _080C5324
	movs r0, 0x1
	b _080C533A
	.pool
_080C5324:
	ldr r0, =0x00002434
	bl AllocZeroed
	str r0, [r4]
	cmp r0, 0
	beq _080C5338
	movs r0, 0
	b _080C533A
	.pool
_080C5338:
	movs r0, 0x2
_080C533A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80C5310

	thumb_func_start sub_80C5340
sub_80C5340: @ 80C5340
	push {r4,lr}
	bl FreeAllWindowBuffers
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	cmp r0, 0
	bne _080C5358
	movs r0, 0x1
	b _080C53A0
	.pool
_080C5358:
	ldr r0, [r0, 0x28]
	cmp r0, 0
	beq _080C5368
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x28]
_080C5368:
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	beq _080C537A
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x24]
_080C537A:
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0
	beq _080C538C
	bl Free
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x20]
_080C538C:
	ldr r0, [r4]
	ldr r2, =0x00002434
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_080C53A0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C5340

	thumb_func_start pokemon_details
pokemon_details: @ 80C53AC
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039CF0
	ldr r6, [r0]
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080C5416
	ldr r3, =gUnknown_085713E0
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r4, [r0, 0xE]
	lsls r4, 28
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r1, 8
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r5, r3, 0x2
	adds r0, r5
	movs r7, 0
	ldrsh r2, [r0, r7]
	lsls r2, 8
	lsrs r0, r4, 29
	subs r0, 0x1
	lsls r0, 2
	adds r0, r3
	movs r7, 0
	ldrsh r3, [r0, r7]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	adds r4, r5
	movs r5, 0
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r7, 0x2E
	ldrsh r0, [r6, r7]
	str r0, [sp, 0x4]
	movs r4, 0x30
	ldrsh r0, [r6, r4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
_080C5416:
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemon_details

	thumb_func_start sub_80C5438
sub_80C5438: @ 80C5438
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_80C5438

	thumb_func_start sub_80C544C
sub_80C544C: @ 80C544C
	push {lr}
	bl sub_80C5484
	cmp r0, 0
	beq _080C5464
	ldr r0, =sub_80C5A48
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_80C5438
	bl SetMainCallback2
_080C5464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C544C

	thumb_func_start sub_80C5470
sub_80C5470: @ 80C5470
	push {lr}
	bl sub_80C570C
	cmp r0, 0
	beq _080C547E
	bl sub_80C51D8
_080C547E:
	pop {r0}
	bx r0
	thumb_func_end sub_80C5470

	thumb_func_start sub_80C5484
sub_80C5484: @ 80C5484
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0xA
	bls _080C5498
	b _080C56F4
_080C5498:
	lsls r0, 2
	ldr r1, =_080C54AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C54AC:
	.4byte _080C54D8
	.4byte _080C54EE
	.4byte _080C54F4
	.4byte _080C550A
	.4byte _080C5510
	.4byte _080C5560
	.4byte _080C5570
	.4byte _080C55D0
	.4byte _080C5624
	.4byte _080C5684
	.4byte _080C56D0
_080C54D8:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	movs r0, 0x2
	bl DisableInterrupts
	b _080C56F4
_080C54EE:
	bl sub_80C50D0
	b _080C56F4
_080C54F4:
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl reset_temp_tile_data_buffers
	b _080C56F4
_080C550A:
	bl sub_80C5310
	b _080C56F4
_080C5510:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085713E8
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	adds r1, 0x32
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001032
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00002032
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	movs r0, 0x2
	movs r1, 0x6
	movs r2, 0x1
	bl SetBgAttribute
	b _080C56F4
	.pool
_080C5560:
	ldr r0, =gUnknown_08571400
	bl InitWindows
	bl DeactivateAllTextPrinters
	b _080C56F4
	.pool
_080C5570:
	ldr r0, =gUnknown_085712F8
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	str r0, [r1, 0x20]
	ldr r0, =gUnknown_08571060
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r1, [r4]
	str r0, [r1, 0x24]
	ldr r0, =gUnknown_085712C0
	add r1, sp, 0x8
	bl malloc_and_decompress
	ldr r1, [r4]
	str r0, [r1, 0x28]
	ldr r1, =gUnknown_08DE08C8
	movs r4, 0
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DE2084
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _080C56F4
	.pool
_080C55D0:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _080C55DC
	b _080C56FE
_080C55DC:
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _080C56F4
_080C5624:
	ldr r4, =gUnknown_08DE07C8
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r4, 0
	movs r1, 0
	bl LoadPalette
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	ldrb r0, [r0, 0xE]
	lsrs r0, 4
	lsls r0, 5
	adds r4, 0x20
	adds r0, r4
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl stdpal_get
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	bl sub_80C629C
	ldr r1, [r5]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
	ldr r5, [r5]
	ldrb r0, [r5, 0xE]
	movs r1, 0xE
	ands r1, r0
	cmp r1, 0x2
	beq _080C5674
	cmp r1, 0x4
	bne _080C56F4
_080C5674:
	movs r0, 0
	strh r0, [r5, 0x4]
	movs r0, 0x1
	b _080C5700
	.pool
_080C5684:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	bl sub_80C62DC
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _080C56F4
	.pool
_080C56D0:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C56FE
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	strh r1, [r0, 0x4]
	movs r0, 0x1
	b _080C5700
	.pool
_080C56F4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C56FE:
	movs r0, 0
_080C5700:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C5484

	thumb_func_start sub_80C570C
sub_80C570C: @ 80C570C
	push {lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02039CEC
	ldr r0, [r1]
	ldrh r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x5
	bhi _080C57E4
	lsls r0, 2
	ldr r1, =_080C5730
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C5730:
	.4byte _080C5748
	.4byte _080C5770
	.4byte _080C577C
	.4byte _080C57A6
	.4byte _080C57AC
	.4byte _080C57BE
_080C5748:
	ldr r0, [r2]
	ldrb r0, [r0, 0xE]
	movs r1, 0xE
	ands r1, r0
	cmp r1, 0x2
	beq _080C576A
	cmp r1, 0x4
	beq _080C576A
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C57E4
_080C576A:
	ldr r1, [r2]
	movs r0, 0x2
	b _080C57EC
_080C5770:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _080C57E4
	b _080C57EE
_080C577C:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C57E4
_080C57A6:
	bl sub_80C63FC
	b _080C57E4
_080C57AC:
	bl sub_80C50D0
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	b _080C57E4
_080C57BE:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	bl sub_80C5340
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x4]
	movs r0, 0x1
	b _080C57F0
	.pool
_080C57E4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
_080C57EC:
	strh r0, [r1, 0x4]
_080C57EE:
	movs r0, 0
_080C57F0:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C570C

	thumb_func_start sub_80C57FC
sub_80C57FC: @ 80C57FC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
	ldr r7, =gUnknown_08571454
	lsls r1, 16
	asrs r5, r1, 16
_080C580A:
	lsls r0, r4, 3
	adds r3, r0, r7
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, r5
	bgt _080C5854
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r5
	blt _080C5854
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	lsls r0, r6, 16
	asrs r2, r0, 16
	cmp r1, r2
	bgt _080C5854
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _080C5854
	cmp r4, 0x5
	bls _080C5842
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	beq _080C585E
_080C5842:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _080C5860
	.pool
_080C5854:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xC
	bls _080C580A
_080C585E:
	movs r0, 0
_080C5860:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80C57FC

	thumb_func_start sub_80C5868
sub_80C5868: @ 80C5868
	push {lr}
	bl sub_80C5484
	cmp r0, 0
	beq _080C58C6
	ldr r1, =gUnknown_02039CEC
	ldr r0, [r1]
	ldrb r0, [r0, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x1
	blt _080C58AC
	cmp r0, 0x2
	bgt _080C58AC
	ldr r0, =sub_80C5BD8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b _080C58C0
	.pool
_080C58AC:
	ldr r2, [r1]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	ldr r0, =sub_80C5A48
	movs r1, 0
	bl CreateTask
_080C58C0:
	ldr r0, =sub_80C5438
	bl SetMainCallback2
_080C58C6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5868

	thumb_func_start sub_80C58D4
sub_80C58D4: @ 80C58D4
	push {r4,lr}
	ldr r4, =gUnknown_02039CF8
	ldr r0, [r4]
	bl sub_80C51F0
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r4, 0x4]
	strh r0, [r1, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	bl InBattlePyramid
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080C5914
	cmp r0, 0x2
	beq _080C591C
	bl Overworld_PlaySpecialMapMusic
	b _080C5924
	.pool
_080C5914:
	ldr r0, =0x000001cd
	b _080C5920
	.pool
_080C591C:
	movs r0, 0xE7
	lsls r0, 1
_080C5920:
	bl PlayBGM
_080C5924:
	ldr r0, =sub_80C5868
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C58D4

	thumb_func_start sub_80C5934
sub_80C5934: @ 80C5934
	push {lr}
	bl sub_80C570C
	cmp r0, 0
	beq _080C599A
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldrb r0, [r2, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x2
	beq _080C5994
	cmp r0, 0x2
	bgt _080C595C
	cmp r0, 0x1
	beq _080C5962
	b _080C599A
	.pool
_080C595C:
	cmp r0, 0x3
	beq _080C5970
	b _080C599A
_080C5962:
	ldr r0, =sub_80C5868
	bl sub_80C6454
	b _080C599A
	.pool
_080C5970:
	ldr r1, =gUnknown_02039CF8
	ldr r0, [r2]
	str r0, [r1]
	ldrh r0, [r2, 0x8]
	strh r0, [r1, 0x4]
	ldrh r0, [r2, 0xA]
	strh r0, [r1, 0x6]
	bl sub_80C52E4
	ldr r0, =sub_80C58D4
	bl PlayRecordedBattle
	b _080C599A
	.pool
_080C5994:
	ldr r0, =sub_80C5868
	bl sub_80C4DDC
_080C599A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5934

	thumb_func_start sub_80C59A4
sub_80C59A4: @ 80C59A4
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r4, r3, 0
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x1
	blt _080C59CC
	cmp r1, 0x2
	ble _080C59F4
	cmp r1, 0x3
	bne _080C59CC
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldrb r1, [r2, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080C59D4
_080C59CC:
	movs r0, 0
	b _080C5A30
	.pool
_080C59D4:
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	movs r1, 0x6
	orrs r0, r1
	strb r0, [r2, 0xE]
	adds r0, r3, 0
	bl DestroyTask
	ldr r0, =sub_80C5934
	bl SetMainCallback2
	b _080C5A1A
	.pool
_080C59F4:
	ldr r0, =gUnknown_02039CEC
	ldr r3, [r0]
	movs r0, 0x7
	ands r2, r0
	lsls r2, 1
	ldrb r1, [r3, 0xE]
	subs r0, 0x16
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0xE]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80C5BD8
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0x8]
_080C5A1A:
	ldr r0, =gUnknown_02039CEC
	ldr r2, [r0]
	ldr r0, =gUnknown_02039CF0
	ldr r1, [r0]
	ldr r0, [r1]
	ldrh r0, [r0, 0x20]
	strh r0, [r2, 0x8]
	ldr r0, [r1]
	ldrh r0, [r0, 0x22]
	strh r0, [r2, 0xA]
	movs r0, 0x1
_080C5A30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C59A4

	thumb_func_start sub_80C5A48
sub_80C5A48: @ 80C5A48
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C5A80
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x22]
	movs r7, 0x22
	ldrsh r0, [r1, r7]
	cmp r0, 0x8
	ble _080C5A80
	subs r0, r3, 0x2
	strh r0, [r1, 0x22]
	ldr r1, [r4]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x7
	bgt _080C5A7E
	movs r0, 0x2
	strh r0, [r1, 0x22]
_080C5A7E:
	movs r5, 0x1
_080C5A80:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C5AAE
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x22]
	movs r7, 0x22
	ldrsh r0, [r1, r7]
	cmp r0, 0x87
	bgt _080C5AAE
	adds r0, r3, 0x2
	strh r0, [r1, 0x22]
	ldr r1, [r4]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x88
	ble _080C5AAC
	movs r0, 0x88
	strh r0, [r1, 0x22]
_080C5AAC:
	movs r5, 0x1
_080C5AAE:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080C5ADC
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x20]
	movs r7, 0x20
	ldrsh r0, [r1, r7]
	cmp r0, 0x5
	ble _080C5ADC
	subs r0, r3, 0x2
	strh r0, [r1, 0x20]
	ldr r1, [r4]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x4
	bgt _080C5ADA
	movs r0, 0x5
	strh r0, [r1, 0x20]
_080C5ADA:
	movs r5, 0x1
_080C5ADC:
	ldrh r1, [r2, 0x2C]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080C5B0A
	ldr r0, =gUnknown_02039CF0
	ldr r4, [r0]
	ldr r1, [r4]
	ldrh r3, [r1, 0x20]
	movs r7, 0x20
	ldrsh r0, [r1, r7]
	cmp r0, 0xE7
	bgt _080C5B0A
	adds r0, r3, 0x2
	strh r0, [r1, 0x20]
	ldr r1, [r4]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0xE8
	ble _080C5B08
	movs r0, 0xE8
	strh r0, [r1, 0x20]
_080C5B08:
	movs r5, 0x1
_080C5B0A:
	cmp r5, 0
	bne _080C5B88
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	ldrb r3, [r0, 0xC]
	cmp r3, 0
	beq _080C5B5E
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C5B5E
	cmp r3, 0x3
	bhi _080C5B48
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	adds r0, r6, 0
	bl sub_80C59A4
	cmp r0, 0
	bne _080C5BCA
	b _080C5B5E
	.pool
_080C5B48:
	cmp r3, 0x4
	bne _080C5B5E
	movs r0, 0x3
	bl PlaySE
	ldr r0, =sub_80C5470
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
_080C5B5E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080C5BCA
	movs r0, 0x3
	bl PlaySE
	ldr r0, =sub_80C5470
	bl SetMainCallback2
	adds r0, r6, 0
	bl DestroyTask
	b _080C5BCA
	.pool
_080C5B88:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0]
	ldrh r0, [r1, 0x20]
	subs r0, 0x5
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r1, 0x22]
	adds r1, 0x5
	lsls r1, 16
	asrs r1, 16
	bl sub_80C57FC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_02039CEC
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, r5
	beq _080C5BCA
	adds r0, r5, 0
	bl sub_80C5ED0
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	strb r0, [r1, 0xD]
	ldr r0, [r4]
	strb r5, [r0, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
_080C5BCA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5A48

	thumb_func_start sub_80C5BD8
sub_80C5BD8: @ 80C5BD8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r5, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r5, r0
	ldr r7, =gUnknown_02039CEC
	ldr r0, [r7]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x1
	beq _080C5CD4
	cmp r0, 0x1
	bgt _080C5C0C
	cmp r0, 0
	beq _080C5C14
	b _080C5D9C
	.pool
_080C5C0C:
	cmp r0, 0x2
	bne _080C5C12
	b _080C5D2A
_080C5C12:
	b _080C5D9C
_080C5C14:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5C4C
	movs r0, 0x1
	movs r1, 0
	bl sub_80C5F58
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r6, 0x2]
	strh r0, [r6, 0x4]
	movs r0, 0x15
	strh r0, [r6, 0x6]
	strh r0, [r6, 0x8]
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C5CA4
	.pool
_080C5C4C:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r1, 0
	strh r0, [r6, 0x2]
	strh r0, [r6, 0x4]
	movs r1, 0x15
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r6, 0x6]
	strh r0, [r6, 0x8]
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	bl sub_80C62DC
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r5, 0x1
	negs r5, r5
	ldr r4, =0x00007fff
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl BlendPalettes
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_080C5CA4:
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	adds r0, 0x2C
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x2E]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x30]
	b _080C5D9C
	.pool
_080C5CD4:
	bl UpdatePaletteFade
	ldrh r0, [r6, 0x6]
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r6, 0x2]
	ldrh r0, [r6, 0x8]
	ldrh r1, [r6, 0x4]
	adds r0, r1
	strh r0, [r6, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r4, =gUnknown_02039CF0
	ldr r1, [r4]
	strh r0, [r1, 0x2E]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	bl sub_8151624
	ldr r1, [r4]
	strh r0, [r1, 0x30]
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5D1C
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	movs r0, 0xFE
	lsls r0, 1
	cmp r1, r0
	ble _080C5DA6
	b _080C5D9C
	.pool
_080C5D1C:
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bne _080C5DA6
	b _080C5D9C
_080C5D2A:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x2C
	ldrb r0, [r1]
	cmp r0, 0
	beq _080C5D3C
	movs r0, 0
	strb r0, [r1]
_080C5D3C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C5DA6
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _080C5D64
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_80C5934
	bl SetMainCallback2
	b _080C5D82
	.pool
_080C5D64:
	movs r0, 0
	movs r1, 0
	bl sub_80C5F58
	ldr r2, [r7]
	ldrb r1, [r2, 0xE]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0xE]
	mov r0, r8
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_80C5A48
	str r1, [r0]
_080C5D82:
	movs r0, 0x2
	movs r1, 0x6
	movs r2, 0
	bl SetBgAttribute
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	b _080C5DA4
	.pool
_080C5D9C:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
_080C5DA4:
	strh r0, [r1, 0x4]
_080C5DA6:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5BD8

	thumb_func_start sub_80C5DB8
sub_80C5DB8: @ 80C5DB8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	movs r4, 0
_080C5DC2:
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080C5DC2
	ldr r4, =gText_SymbolsEarned
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r6, =gUnknown_08571448
	str r6, [sp]
	movs r0, 0
	mov r8, r0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x5
	bl AddTextPrinterParameterized3
	ldr r4, =gText_BattleRecord
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x60
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x5
	bl AddTextPrinterParameterized3
	str r6, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldr r0, =gText_BattlePoints
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x8
	movs r2, 0x5
	movs r3, 0x4
	bl AddTextPrinterParameterized3
	ldr r4, =gStringVar4
	ldr r5, =gUnknown_02039CEC
	ldr r0, [r5]
	ldrh r1, [r0, 0x6]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	movs r0, 0x8
	adds r1, r4, 0
	movs r2, 0x5B
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x8
	movs r3, 0x10
	bl AddTextPrinterParameterized3
	ldr r1, [r5]
	ldrh r0, [r1, 0x8]
	subs r0, 0x5
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r1, 0xA]
	adds r1, 0x5
	lsls r1, 16
	asrs r1, 16
	bl sub_80C57FC
	ldr r1, [r5]
	strb r0, [r1, 0xC]
	ldr r0, [r5]
	mov r1, r8
	strb r1, [r0, 0xD]
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl sub_80C5ED0
	movs r4, 0
_080C5E92:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _080C5E92
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5DB8

	thumb_func_start sub_80C5ED0
sub_80C5ED0: @ 80C5ED0
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0x3
	bne _080C5F18
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _080C5F18
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_08571614
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0
	bl AddTextPrinterParameterized3
	b _080C5F3A
	.pool
_080C5F18:
	cmp r4, 0
	beq _080C5F3A
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08571614
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0
	bl AddTextPrinterParameterized3
_080C5F3A:
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5ED0

	thumb_func_start sub_80C5F58
sub_80C5F58: @ 80C5F58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	lsls r0, 28
	lsrs r0, 29
	cmp r0, 0x1
	beq _080C5F80
	cmp r0, 0x2
	beq _080C5FC2
	b _080C60EE
	.pool
_080C5F80:
	cmp r2, 0
	beq _080C5FA8
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x20]
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C6004
	.pool
_080C5FA8:
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x3
	bl FillBgTilemapBufferRect
	b _080C6004
_080C5FC2:
	cmp r2, 0
	beq _080C5FEC
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x20]
	adds r1, 0x54
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r2, 0x10
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C6004
	.pool
_080C5FEC:
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x10
	movs r3, 0xA
	bl FillBgTilemapBufferRect
_080C6004:
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	cmp r7, 0
	beq _080C6084
	movs r4, 0xFE
	lsls r4, 1
	adds r0, r4, 0
	bl sub_8151624
	adds r6, r0, 0
	lsls r6, 16
	asrs r6, 16
	adds r0, r4, 0
	bl sub_8151624
	lsls r0, 16
	asrs r0, 16
	ldr r5, =gUnknown_085713E0
	ldr r1, =gUnknown_02039CEC
	ldr r1, [r1]
	ldrb r4, [r1, 0xE]
	lsls r4, 28
	lsrs r1, r4, 29
	subs r1, 0x1
	lsls r1, 2
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 8
	lsrs r2, r4, 29
	subs r2, 0x1
	lsls r2, 2
	adds r3, r5, 0x2
	mov r8, r3
	add r2, r8
	movs r3, 0
	ldrsh r2, [r2, r3]
	lsls r2, 8
	lsrs r3, r4, 29
	subs r3, 0x1
	lsls r3, 2
	adds r3, r5
	movs r5, 0
	ldrsh r3, [r3, r5]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	add r4, r8
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	str r6, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
	b _080C60EE
	.pool
_080C6084:
	movs r4, 0x80
	lsls r4, 1
	adds r0, r4, 0
	bl sub_8151624
	adds r6, r0, 0
	lsls r6, 16
	asrs r6, 16
	adds r0, r4, 0
	bl sub_8151624
	lsls r0, 16
	asrs r0, 16
	ldr r5, =gUnknown_085713E0
	ldr r1, =gUnknown_02039CEC
	ldr r1, [r1]
	ldrb r4, [r1, 0xE]
	lsls r4, 28
	lsrs r1, r4, 29
	subs r1, 0x1
	lsls r1, 2
	adds r1, r5
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 8
	lsrs r2, r4, 29
	subs r2, 0x1
	lsls r2, 2
	adds r3, r5, 0x2
	mov r8, r3
	add r2, r8
	movs r3, 0
	ldrsh r2, [r2, r3]
	lsls r2, 8
	lsrs r3, r4, 29
	subs r3, 0x1
	lsls r3, 2
	adds r3, r5
	movs r5, 0
	ldrsh r3, [r3, r5]
	lsrs r4, 29
	subs r4, 0x1
	lsls r4, 2
	add r4, r8
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	str r6, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r0, 0x2
	bl SetBgAffine
_080C60EE:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C5F58

	thumb_func_start sub_80C6104
sub_80C6104: @ 80C6104
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r5, 0x2
	beq _080C614C
	cmp r5, 0x2
	bgt _080C611E
	cmp r5, 0x1
	beq _080C6128
	b _080C61C4
_080C611E:
	cmp r5, 0x3
	beq _080C6170
	cmp r5, 0x4
	beq _080C61A4
	b _080C61C4
_080C6128:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C614C:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xA8
	lsls r0, 1
	adds r1, r0
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	b _080C6192
	.pool
_080C6170:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C61C4
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x28]
	movs r0, 0xC
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x2
_080C6192:
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C61A4:
	ldr r1, =gUnknown_08DE3350
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x15
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C61CE
	.pool
_080C61C4:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080C6294
_080C61CE:
	cmp r4, 0x2
	beq _080C620C
	cmp r4, 0x2
	bgt _080C61DC
	cmp r4, 0x1
	beq _080C61E6
	b _080C6284
_080C61DC:
	cmp r4, 0x3
	beq _080C6230
	cmp r4, 0x4
	beq _080C6264
	b _080C6284
_080C61E6:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	adds r1, 0xA8
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	movs r3, 0x3
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C620C:
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x24]
	movs r0, 0xFC
	lsls r0, 1
	adds r1, r0
	movs r0, 0xC
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x10
	b _080C6254
	.pool
_080C6230:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrb r1, [r0, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080C6294
	ldr r0, =gUnknown_02039CF0
	ldr r0, [r0]
	ldr r1, [r0, 0x28]
	adds r1, 0x48
	movs r0, 0xC
	str r0, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x2
_080C6254:
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C6264:
	ldr r1, =gUnknown_08DE3374
	movs r0, 0x9
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x15
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _080C628E
	.pool
_080C6284:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _080C6294
_080C628E:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_080C6294:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80C6104

	thumb_func_start sub_80C629C
sub_80C629C: @ 80C629C
	push {r4,lr}
	ldr r1, =gUnknown_08DE3060
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r4, =gUnknown_02039CEC
	ldr r1, [r4]
	ldrb r0, [r1, 0xC]
	ldrb r1, [r1, 0xD]
	bl sub_80C6104
	ldr r0, [r4]
	ldrb r1, [r0, 0xE]
	lsls r1, 28
	lsrs r1, 29
	movs r0, 0x1
	bl sub_80C5F58
	bl sub_80C5DB8
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C629C

	thumb_func_start sub_80C62DC
sub_80C62DC: @ 80C62DC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	movs r5, 0
	bl FreeAllSpritePalettes
	bl ResetAffineAnimData
	ldr r0, =gUnknown_085714E4
	bl LoadSpritePalettes
	ldr r4, =gUnknown_085714BC
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x10
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085715B4
	ldr r1, =gUnknown_02039CEC
	ldr r2, [r1]
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	movs r6, 0xA
	ldrsh r2, [r2, r6]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_02039CF0
	ldr r2, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	mov r8, sp
	mov r9, r3
_080C633C:
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	adds r0, 0xF
	adds r2, r0, r5
	ldrb r0, [r2]
	adds r4, r5, 0x1
	cmp r0, 0
	beq _080C63C2
	mov r1, sp
	ldr r0, =gUnknown_085715E4
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	mov r7, r8
	ldrh r0, [r7, 0x2]
	ldr r1, =0x0000ffff
	adds r0, r1
	ldrb r2, [r2]
	adds r0, r2
	strh r0, [r7, 0x2]
	ldr r1, =gUnknown_08571454
	adds r0, r5, 0x6
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x4]
	adds r1, 0x8
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r0]
	adds r2, 0x6
	lsls r2, 16
	asrs r2, 16
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, sp
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r3, r9
	ldr r2, [r3]
	lsls r3, r5, 2
	adds r2, 0x4
	adds r2, r3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	ldrb r2, [r1, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r2, r0
	movs r0, 0x8
	orrs r2, r0
	strb r2, [r1, 0x5]
	mov r7, r9
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r3
	ldr r0, [r0]
	adds r1, r5, 0
	bl StartSpriteAnim
_080C63C2:
	lsls r0, r4, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080C633C
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C62DC

	thumb_func_start sub_80C63FC
sub_80C63FC: @ 80C63FC
	push {r4-r6,lr}
	movs r5, 0
	ldr r4, =gUnknown_02039CF0
	ldr r0, [r4]
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r4]
	str r5, [r0]
	adds r6, r4, 0
_080C6410:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0x4
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080C642C
	bl DestroySprite
	ldr r0, [r6]
	adds r0, 0x4
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080C642C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x6
	bls _080C6410
	bl FreeAllSpritePalettes
	movs r0, 0x2
	bl FreeSpriteTilesByTag
	movs r0, 0
	bl FreeSpriteTilesByTag
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C63FC

	thumb_func_start nullsub_39
nullsub_39: @ 80C6450
	bx lr
	thumb_func_end nullsub_39

	thumb_func_start sub_80C6454
sub_80C6454: @ 80C6454
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02039CF4
	ldr r0, [r5]
	cmp r0, 0
	beq _080C6466
	adds r0, r4, 0
	bl SetMainCallback2
_080C6466:
	ldr r0, =0x00003014
	bl AllocZeroed
	str r0, [r5]
	str r4, [r0]
	bl ResetTasks
	ldr r0, =sub_80C67BC
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_80C5438
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6454

	thumb_func_start sub_80C6498
sub_80C6498: @ 80C6498
	push {r4,lr}
	bl ResetTasks
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	ldr r2, =0x00003014
	movs r1, 0
	bl memset
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6498

	thumb_func_start sub_80C64CC
sub_80C64CC: @ 80C64CC
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x7
	bls _080C64DC
	b _080C6694
_080C64DC:
	lsls r0, 2
	ldr r1, =_080C64F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C64F0:
	.4byte _080C6510
	.4byte _080C6520
	.4byte _080C6526
	.4byte _080C6538
	.4byte _080C65C0
	.4byte _080C65E8
	.4byte _080C6628
	.4byte _080C6678
_080C6510:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C6694
_080C6520:
	bl sub_80C50D0
	b _080C6694
_080C6526:
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl reset_temp_tile_data_buffers
	b _080C6694
_080C6538:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085713F4
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_02039CF4
	ldr r1, [r4]
	adds r1, 0x12
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001012
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00002012
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	movs r5, 0x1E
	str r5, [sp]
	movs r4, 0x14
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _080C6618
	.pool
_080C65C0:
	ldr r0, =gUnknown_08571428
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl sub_80C6B94
	ldr r1, =gUnknown_0856FBBC
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _080C6694
	.pool
_080C65E8:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _080C669E
	ldr r0, =gUnknown_08DE07C8
	movs r2, 0xD0
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	movs r0, 0
	bl stdpal_get
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_08570E00
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
_080C6618:
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _080C6694
	.pool
_080C6628:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	bl sub_80C6974
	ldr r0, =pokemon_details
	bl SetVBlankCallback
	movs r5, 0x1
	negs r5, r5
	ldr r4, =0x00007fff
	adds r0, r5, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl BlendPalettes
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _080C6694
	.pool
_080C6678:
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080C669E
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	strh r1, [r0, 0x4]
	movs r0, 0x1
	b _080C66A0
	.pool
_080C6694:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C669E:
	movs r0, 0
_080C66A0:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C64CC

	thumb_func_start sub_80C66AC
sub_80C66AC: @ 80C66AC
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02039CEC
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x5
	bhi _080C67A4
	lsls r0, 2
	ldr r1, =_080C66CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C66CC:
	.4byte _080C66E4
	.4byte _080C66FC
	.4byte _080C6722
	.4byte _080C6732
	.4byte _080C6774
	.4byte _080C6782
_080C66E4:
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _080C67A4
	.pool
_080C66FC:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _080C67AE
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x2
	bl HideBg
	b _080C67A4
_080C6722:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	b _080C67A4
_080C6732:
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _080C6746
	bl DestroySprite
	movs r0, 0
	bl FreeSpriteTilesByTag
_080C6746:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	cmp r0, 0
	beq _080C6758
	bl DestroySprite
	movs r0, 0x1
	bl FreeSpriteTilesByTag
_080C6758:
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _080C676A
	bl DestroySprite
	movs r0, 0x4
	bl FreeSpriteTilesByTag
_080C676A:
	bl FreeAllWindowBuffers
	b _080C67A4
	.pool
_080C6774:
	bl sub_80C50D0
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	b _080C67A4
_080C6782:
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x4]
	movs r0, 0x1
	b _080C67B0
	.pool
_080C67A4:
	ldr r0, =gUnknown_02039CEC
	ldr r1, [r0]
	ldrh r0, [r1, 0x4]
	adds r0, 0x1
	strh r0, [r1, 0x4]
_080C67AE:
	movs r0, 0
_080C67B0:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80C66AC

	thumb_func_start sub_80C67BC
sub_80C67BC: @ 80C67BC
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
	cmp r0, 0x5
	bls _080C67D6
	b _080C68DA
_080C67D6:
	lsls r0, 2
	ldr r1, =_080C67E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080C67E8:
	.4byte _080C6800
	.4byte _080C6806
	.4byte _080C686C
	.4byte _080C6894
	.4byte _080C68C4
	.4byte _080C68CE
_080C6800:
	bl sub_80C64CC
	b _080C68C8
_080C6806:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080C6824
	movs r0, 0x3
	bl PlaySE
	movs r0, 0x4
	b _080C68DE
	.pool
_080C6824:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080C6848
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x5
	bls _080C6844
	movs r0, 0
	bl sub_80C6C70
	b _080C68E0
	.pool
_080C6844:
	strh r2, [r4]
	b _080C68E0
_080C6848:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080C68E0
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _080C6868
	movs r0, 0x1
	bl sub_80C6C70
	b _080C68E0
	.pool
_080C6868:
	movs r0, 0x3
	b _080C68DE
_080C686C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080C6882
	movs r0, 0
	bl sub_80C6C70
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	b _080C68DE
_080C6882:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldrh r0, [r1, 0x22]
	adds r0, 0x4
	b _080C68B4
	.pool
_080C6894:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080C68AA
	movs r0, 0x1
	bl sub_80C6C70
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	b _080C68DE
_080C68AA:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	ldrh r0, [r1, 0x22]
	subs r0, 0x4
_080C68B4:
	strh r0, [r1, 0x22]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _080C68E0
	.pool
_080C68C4:
	bl sub_80C66AC
_080C68C8:
	cmp r0, 0
	bne _080C68DA
	b _080C68E0
_080C68CE:
	adds r0, r2, 0
	bl DestroyTask
	bl sub_80C6498
	b _080C68E0
_080C68DA:
	ldrh r0, [r4]
	adds r0, 0x1
_080C68DE:
	strh r0, [r4]
_080C68E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80C67BC

	thumb_func_start sub_80C68E8
sub_80C68E8: @ 80C68E8
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xfffb0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x3
	bls _080C6904
	adds r0, r1, 0
	subs r0, 0xF
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C690C
_080C6904:
	movs r0, 0x1
	b _080C696E
	.pool
_080C690C:
	adds r0, r1, 0
	subs r0, 0x12
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080C691C
	movs r0, 0x2
	b _080C696E
_080C691C:
	adds r0, r1, 0
	subs r0, 0x16
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C692C
	movs r0, 0x3
	b _080C696E
_080C692C:
	adds r0, r1, 0
	subs r0, 0x1C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C693C
	movs r0, 0x4
	b _080C696E
_080C693C:
	adds r0, r1, 0
	subs r0, 0x1F
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080C694C
	movs r0, 0x5
	b _080C696E
_080C694C:
	adds r0, r1, 0
	subs r0, 0x22
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080C695C
	movs r0, 0x6
	b _080C696E
_080C695C:
	adds r0, r1, 0
	subs r0, 0x19
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080C696C
	movs r0, 0
	b _080C696E
_080C696C:
	movs r0, 0x7
_080C696E:
	pop {r1}
	bx r1
	thumb_func_end sub_80C68E8

	thumb_func_start sub_80C6974
sub_80C6974: @ 80C6974
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	movs r7, 0
	bl FreeAllSpritePalettes
	ldr r0, =gUnknown_085714E4
	bl LoadSpritePalettes
	ldr r6, =gUnknown_085714BC
	adds r0, r6, 0
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085715B4
	mov r8, r0
	ldr r4, =gUnknown_02039CF4
	ldr r0, [r4]
	ldrb r2, [r0, 0x10]
	lsls r2, 4
	adds r2, 0x8
	mov r0, r8
	movs r1, 0x9B
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, [r4]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	ldr r2, =gSprites
	mov r9, r2
	add r1, r9
	str r1, [r0, 0x4]
	ldrb r2, [r1, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r0, r5, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, 0x3F
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0x1
	bl StartSpriteAnim
	adds r6, 0x8
	adds r0, r6, 0
	bl LoadCompressedSpriteSheet
	movs r3, 0x18
	add r8, r3
	ldr r6, =gUnknown_08571650
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r0, r6
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r3, 0xA
	ldrsh r2, [r0, r3]
	mov r0, r8
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, [r4]
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	add r0, r9
	str r0, [r1, 0xC]
	ldrb r1, [r0, 0x5]
	ands r5, r1
	strb r5, [r0, 0x5]
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	ldrb r1, [r1, 0x10]
	lsls r1, 4
	adds r1, r6
	ldrb r1, [r1, 0xC]
	bl StartSpriteAnim
	bl GetCurrentRegionMapSectionId
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3A
	beq _080C6A40
	cmp r5, 0xCA
	beq _080C6A40
	b _080C6B7A
_080C6A40:
	ldr r4, =gSaveBlock1Ptr
	ldr r2, [r4]
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	beq _080C6A52
	cmp r0, 0xE
	bne _080C6A98
	movs r7, 0x37
_080C6A52:
	lsls r0, r7, 16
	asrs r0, 16
	ldrh r6, [r2]
	adds r0, r6
	ldrh r4, [r2, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6A66
	adds r0, 0x7
_080C6A66:
	lsls r0, 13
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6A74
	adds r0, 0x7
_080C6A74:
	lsls r0, 13
	lsrs r4, r0, 16
	movs r5, 0
	b _080C6AF2
	.pool
_080C6A98:
	lsls r0, 16
	lsrs r0, 16
	bl sub_80C68E8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _080C6AB4
	subs r0, r5, 0x1
	lsls r0, 4
	adds r0, r6
	ldrh r7, [r0, 0x8]
	ldrh r4, [r0, 0xA]
	b _080C6AF2
_080C6AB4:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x25
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xE
	bne _080C6ACE
	ldrh r0, [r1, 0x28]
	adds r0, 0x37
	lsls r0, 16
	lsrs r7, r0, 16
	b _080C6AD0
_080C6ACE:
	ldrh r7, [r1, 0x28]
_080C6AD0:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r4, [r0, 0x2A]
	lsls r0, r7, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6AE0
	adds r0, 0x7
_080C6AE0:
	lsls r0, 13
	lsrs r7, r0, 16
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	bge _080C6AEE
	adds r0, 0x7
_080C6AEE:
	lsls r0, 13
	lsrs r4, r0, 16
_080C6AF2:
	ldr r0, =gUnknown_085714D4
	bl LoadCompressedSpriteSheet
	mov r1, sp
	ldr r0, =gUnknown_085715FC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	mov r1, sp
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	adds r0, 0x4
	strh r0, [r1, 0x2]
	cmp r5, 0
	beq _080C6B2C
	lsls r1, r7, 16
	asrs r1, 16
	lsls r2, r4, 16
	b _080C6B3E
	.pool
_080C6B2C:
	lsls r1, r7, 19
	lsls r2, r4, 19
	movs r0, 0xA0
	lsls r0, 13
	adds r1, r0
	asrs r1, 16
	movs r3, 0x90
	lsls r3, 14
	adds r2, r3
_080C6B3E:
	asrs r2, 16
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =gUnknown_02039CF4
	ldr r2, [r4]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2, 0x8]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _080C6B7A
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r1, 0x1
	bl StartSpriteAnim
_080C6B7A:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6974

	thumb_func_start sub_80C6B94
sub_80C6B94: @ 80C6B94
	push {r4-r6,lr}
	sub sp, 0xC
	movs r4, 0
_080C6B9A:
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6B9A
	movs r4, 0
	movs r6, 0
	ldr r5, =gUnknown_08571650
_080C6BB8:
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	cmp r4, r0
	bne _080C6BF0
	lsls r1, r4, 4
	adds r3, r1, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0857144E
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	b _080C6C0E
	.pool
_080C6BF0:
	lsls r1, r4, 4
	adds r3, r1, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0857144B
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
_080C6C0E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080C6BB8
	ldr r0, =gUnknown_08571448
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08571650
	ldr r0, =gUnknown_02039CF4
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0
	bl AddTextPrinterParameterized3
	movs r4, 0
_080C6C40:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6C40
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6B94

	thumb_func_start sub_80C6C70
sub_80C6C70: @ 80C6C70
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	lsls r0, 24
	cmp r0, 0
	beq _080C6C8C
	ldr r0, =gUnknown_02039CF4
	ldr r4, [r0]
	ldrb r5, [r4, 0x10]
	adds r0, r5, 0x6
	b _080C6C94
	.pool
_080C6C8C:
	ldr r0, =gUnknown_02039CF4
	ldr r4, [r0]
	ldrb r5, [r4, 0x10]
	adds r0, r5, 0x1
_080C6C94:
	movs r1, 0x7
	bl __modsi3
	strb r0, [r4, 0x10]
	lsls r0, r5, 4
	adds r3, r0, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r6, =gUnknown_0857144B
	str r6, [sp]
	movs r1, 0
	mov r8, r1
	str r1, [sp, 0x4]
	ldr r4, =gUnknown_08571650
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	ldr r5, =gUnknown_02039CF4
	ldr r1, [r5]
	ldrb r3, [r1, 0x10]
	lsls r3, 4
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0x3
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x4
	bl AddTextPrinterParameterized3
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, 0x8
	strh r0, [r2, 0x22]
	ldr r0, [r1, 0xC]
	ldrb r1, [r1, 0x10]
	lsls r1, 4
	adds r1, r4
	ldrb r1, [r1, 0xC]
	bl StartSpriteAnim
	ldr r1, [r5]
	ldr r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldrh r0, [r0, 0x8]
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0xC]
	ldrb r0, [r1, 0x10]
	lsls r0, 4
	adds r0, r4
	ldrh r0, [r0, 0xA]
	strh r0, [r2, 0x22]
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	subs r6, 0x3
	str r6, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r0, [r5]
	ldrb r0, [r0, 0x10]
	lsls r0, 4
	adds r4, 0x4
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0
	bl AddTextPrinterParameterized3
	movs r4, 0
_080C6D4A:
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _080C6D4A
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x6C
	bl PlaySE
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6C70

	thumb_func_start sub_80C6D80
sub_80C6D80: @ 80C6D80
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0x24]
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x28]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x1C]
	str r1, [sp, 0x20]
	ldr r1, =0x00ffffff
	ldr r0, [sp, 0x1C]
	ands r0, r1
	movs r1, 0xC0
	lsls r1, 21
	orrs r0, r1
	str r0, [sp, 0x1C]
	ldr r1, =0xffffff00
	add r5, sp, 0x1C
	ldr r0, [r5, 0x4]
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	str r0, [r5, 0x4]
	adds r0, r5, 0
	bl AddWindow
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r4, r0, 24
	lsrs r4, 24
	mov r0, r9
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r6, r0, 0
	ldrb r0, [r5, 0x3]
	lsls r0, 5
	adds r0, r6
	mov r8, r0
	ldr r1, [sp, 0x28]
	cmp r1, 0
	bne _080C6E04
	add r0, sp, 0x14
	b _080C6E08
	.pool
_080C6E04:
	add r0, sp, 0x14
	mov r1, r9
_080C6E08:
	strb r1, [r0]
	add r1, sp, 0x14
	movs r2, 0
	movs r0, 0xF
	strb r0, [r1, 0x1]
	movs r0, 0xE
	strb r0, [r1, 0x2]
	mov r0, r10
	lsls r4, r0, 24
	lsrs r0, r4, 24
	str r2, [sp]
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0xC]
	ldr r1, [sp, 0x24]
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized4
	ldr r0, [sp, 0x4C]
	mov r10, r4
	cmp r0, 0x6
	bls _080C6E3E
	movs r0, 0x6
_080C6E3E:
	ldr r4, [sp, 0x4C]
	subs r4, 0x6
	cmp r0, 0
	ble _080C6E70
	adds r5, r0, 0
_080C6E48:
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x40
	bl CpuSet
	adds r1, r7, 0
	adds r1, 0x80
	mov r0, r8
	movs r2, 0x40
	bl CpuSet
	adds r6, 0x80
	movs r2, 0x80
	add r8, r2
	movs r0, 0x80
	lsls r0, 1
	adds r7, r0
	subs r5, 0x1
	cmp r5, 0
	bne _080C6E48
_080C6E70:
	cmp r4, 0
	ble _080C6E90
	add r0, sp, 0x18
	mov r2, r9
	lsls r1, r2, 4
	orrs r1, r2
	strh r1, [r0]
	lsls r2, r4, 7
	ldr r1, =0x001fffff
	ands r2, r1
	movs r1, 0x80
	lsls r1, 17
	orrs r2, r1
	adds r1, r7, 0
	bl CpuSet
_080C6E90:
	mov r1, r10
	lsrs r0, r1, 24
	bl RemoveWindow
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6D80

	thumb_func_start sub_80C6EAC
sub_80C6EAC: @ 80C6EAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	adds r6, r3, 0
	ldr r0, [sp, 0x4C]
	mov r9, r0
	ldr r1, [sp, 0x50]
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x28]
	lsls r6, 24
	lsrs r6, 24
	mov r2, r9
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	ldr r0, [sp, 0x20]
	bl StringLength_Multibyte
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp, 0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x18]
	ldr r1, =0xffffff00
	add r2, sp, 0x18
	mov r8, r2
	ldr r0, [r2, 0x4]
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r5, [sp, 0x18]
	lsrs r5, 24
	lsls r5, 5
	mov r0, r8
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, r6, 4
	orrs r1, r6
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	movs r1, 0x7
	bl GetWindowAttribute
	adds r7, r0, 0
	mov r0, r8
	ldrb r0, [r0, 0x3]
	lsls r0, 5
	mov r8, r0
	add r8, r7
	add r0, sp, 0x14
	movs r1, 0
	strb r6, [r0]
	mov r2, r9
	strb r2, [r0, 0x1]
	mov r2, r10
	strb r2, [r0, 0x2]
	str r1, [sp]
	str r1, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x20]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x2
	bl AddTextPrinterParameterized4
	lsrs r5, 1
	adds r0, r7, 0
	ldr r1, [sp, 0x24]
	adds r2, r5, 0
	bl CpuSet
	ldr r2, [sp, 0x24]
	ldr r0, [sp, 0x28]
	adds r1, r2, r0
	mov r0, r8
	adds r2, r5, 0
	bl CpuSet
	adds r0, r4, 0
	bl RemoveWindow
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80C6EAC

	.align 2, 0 @ Don't pad with nop.
