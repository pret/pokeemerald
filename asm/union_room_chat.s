	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_801DD98
sub_801DD98: @ 801DD98
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	movs r0, 0xDE
	lsls r0, 1
	bl Alloc
	str r0, [r4]
	bl sub_801DDD0
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =c2_081284E0
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DD98

	thumb_func_start sub_801DDD0
sub_801DDD0: @ 801DDD0
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r5, [r4, 0x10]
	strb r5, [r4, 0x11]
	strb r5, [r4, 0x12]
	strb r5, [r4, 0x14]
	strb r5, [r4, 0x15]
	strb r5, [r4, 0x16]
	movs r0, 0xFF
	strb r0, [r4, 0x1A]
	bl GetLinkPlayerCount
	strb r0, [r4, 0xD]
	bl GetMultiplayerId
	strb r0, [r4, 0x13]
	strb r5, [r4, 0x17]
	strb r5, [r4, 0x18]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	bl sub_801EF1C
	ldr r7, =gSaveBlock1Ptr
	ldr r6, =0x00003c88
	adds r4, 0xB9
	movs r5, 0x9
_0801DE0E:
	ldr r1, [r7]
	adds r1, r6
	adds r0, r4, 0
	bl StringCopy
	adds r6, 0x15
	adds r4, 0x15
	subs r5, 0x1
	cmp r5, 0
	bge _0801DE0E
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DDD0

	thumb_func_start sub_801DE30
sub_801DE30: @ 801DE30
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	bl DestroyTask
	ldr r0, [r4]
	ldrb r0, [r0, 0xF]
	bl DestroyTask
	ldr r0, [r4]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DE30

	thumb_func_start c2_081284E0
c2_081284E0: @ 801DE54
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801DE8C
	cmp r0, 0x1
	bgt _0801DE74
	cmp r0, 0
	beq _0801DE7A
	b _0801DF04
	.pool
_0801DE74:
	cmp r0, 0x2
	beq _0801DEC8
	b _0801DF04
_0801DE7A:
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl sub_801F4D0
	b _0801DEBC
_0801DE8C:
	bl sub_801F5B8
	bl sub_801F534
	adds r5, r0, 0
	cmp r5, 0
	bne _0801DF04
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_801DF20
	bl SetVBlankCallback
_0801DEBC:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _0801DF04
	.pool
_0801DEC8:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801DF04
	ldr r0, =sub_801DF38
	bl SetMainCallback2
	ldr r0, =sub_801DF54
	movs r1, 0x8
	bl CreateTask
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	strb r0, [r1, 0xE]
	ldr r0, =sub_801F2B4
	movs r1, 0x7
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, 0xF]
	bl sub_800E0E8
	movs r0, 0xE8
	movs r1, 0x96
	bl CreateWirelessStatusIndicatorSprite
_0801DF04:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_081284E0

	thumb_func_start sub_801DF20
sub_801DF20: @ 801DF20
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	thumb_func_end sub_801DF20

	thumb_func_start sub_801DF38
sub_801DF38: @ 801DF38
	push {lr}
	bl RunTasks
	bl sub_801F5B8
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_801DF38

	thumb_func_start sub_801DF54
sub_801DF54: @ 801DF54
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x17]
	cmp r0, 0x2
	beq _0801DF7A
	cmp r0, 0x2
	bgt _0801DF70
	cmp r0, 0x1
	beq _0801DF76
	b _0801DF8A
	.pool
_0801DF70:
	cmp r0, 0x3
	beq _0801DF7E
	b _0801DF8A
_0801DF76:
	movs r0, 0x6
	b _0801DF80
_0801DF7A:
	movs r0, 0x7
	b _0801DF80
_0801DF7E:
	movs r0, 0x8
_0801DF80:
	bl sub_801EBD4
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x17]
_0801DF8A:
	ldr r1, =gUnknown_082F2A7C
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DF54

	thumb_func_start sub_801DFAC
sub_801DFAC: @ 801DFAC
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrh r1, [r0, 0x6]
	cmp r1, 0x1
	beq _0801DFE0
	cmp r1, 0x1
	bgt _0801DFC8
	cmp r1, 0
	beq _0801DFCE
	b _0801E028
	.pool
_0801DFC8:
	cmp r1, 0x2
	beq _0801E018
	b _0801E028
_0801DFCE:
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EF24
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
_0801DFE0:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E028
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E028
	.pool
_0801E018:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E028
	movs r0, 0x1
	bl sub_801EBD4
_0801E028:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DFAC

	thumb_func_start sub_801E030
sub_801E030: @ 801E030
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C84
	ldr r3, [r5]
	ldrh r0, [r3, 0x6]
	cmp r0, 0
	beq _0801E048
	cmp r0, 0x1
	beq _0801E0F6
	b _0801E118
	.pool
_0801E048:
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0801E068
	ldrb r0, [r3, 0x15]
	cmp r0, 0
	beq _0801E118
	movs r0, 0x4
	bl sub_801EBD4
	b _0801E118
	.pool
_0801E068:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _0801E078
	movs r0, 0x2
	bl sub_801EBD4
	b _0801E118
_0801E078:
	ldrh r1, [r1, 0x30]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801E0A4
	ldrb r0, [r3, 0x15]
	cmp r0, 0
	beq _0801E09C
	bl sub_801ED68
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r5]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E118
_0801E09C:
	movs r0, 0x3
	bl sub_801EBD4
	b _0801E118
_0801E0A4:
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _0801E0C0
	bl sub_801EC94
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	movs r0, 0x2
	movs r1, 0x1
	b _0801E0EC
_0801E0C0:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0801E0E0
	ldrb r0, [r3, 0x10]
	cmp r0, 0x3
	beq _0801E0D8
	bl sub_801ED94
	movs r0, 0x8
	b _0801E0EA
_0801E0D8:
	movs r0, 0x5
	bl sub_801EBD4
	b _0801E118
_0801E0E0:
	bl sub_801EBE4
	cmp r0, 0
	beq _0801E118
	movs r0, 0x1
_0801E0EA:
	movs r1, 0
_0801E0EC:
	bl sub_801F5EC
	ldr r0, [r5]
	strh r4, [r0, 0x6]
	b _0801E118
_0801E0F6:
	movs r0, 0
	bl sub_801F644
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_801F644
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	bne _0801E118
	cmp r1, 0
	bne _0801E118
	ldr r0, [r5]
	strh r1, [r0, 0x6]
_0801E118:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E030

	thumb_func_start sub_801E120
sub_801E120: @ 801E120
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x6]
	cmp r0, 0x4
	bls _0801E12E
	b _0801E23A
_0801E12E:
	lsls r0, 2
	ldr r1, =_0801E140
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E140:
	.4byte _0801E154
	.4byte _0801E15E
	.4byte _0801E17C
	.4byte _0801E208
	.4byte _0801E21C
_0801E154:
	movs r0, 0x3
	movs r1, 0
	bl sub_801F5EC
	b _0801E16A
_0801E15E:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
_0801E16A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E23A
	.pool
_0801E17C:
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r0, 8
	lsrs r6, r0, 16
	asrs r4, r0, 16
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0801E1B4
	adds r0, 0x1
	cmp r4, r0
	beq _0801E1D4
	movs r0, 0x4
	movs r1, 0
	bl sub_801F5EC
	ldr r5, =gUnknown_02022C84
	ldr r2, [r5]
	ldrb r0, [r2, 0x10]
	cmp r0, r4
	beq _0801E1DC
	cmp r4, 0x3
	ble _0801E1EC
	b _0801E1DC
	.pool
_0801E1B4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0801E23A
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl Menu_MoveCursor
	b _0801E23A
	.pool
_0801E1D4:
	movs r0, 0x4
	movs r1, 0
	bl sub_801F5EC
_0801E1DC:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801E23A
	.pool
_0801E1EC:
	movs r1, 0
	strb r1, [r2, 0x11]
	ldr r0, [r5]
	strb r1, [r0, 0x12]
	movs r0, 0x5
	movs r1, 0x1
	bl sub_801F5EC
	ldr r0, [r5]
	strb r6, [r0, 0x10]
	ldr r1, [r5]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801E23A
_0801E208:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E23A
_0801E21C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E23A
	movs r0, 0x1
	bl sub_801EBD4
_0801E23A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801E120

	thumb_func_start sub_801E240
sub_801E240: @ 801E240
	push {r4,r5,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0xA
	bls _0801E250
	b _0801E458
_0801E250:
	lsls r0, 2
	ldr r1, =_0801E264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E264:
	.4byte _0801E290
	.4byte _0801E2A8
	.4byte _0801E2C4
	.4byte _0801E322
	.4byte _0801E3D4
	.4byte _0801E424
	.4byte _0801E458
	.4byte _0801E458
	.4byte _0801E378
	.4byte _0801E338
	.4byte _0801E35C
_0801E290:
	movs r0, 0x6
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E2A8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E2B6
	b _0801E458
_0801E2B6:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E2C4:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801E2E6
	cmp r1, 0
	bgt _0801E2DE
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801E396
	b _0801E458
_0801E2DE:
	cmp r1, 0x1
	beq _0801E2E4
	b _0801E458
_0801E2E4:
	b _0801E396
_0801E2E6:
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801E310
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_801EFD0
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r4]
	movs r0, 0x9
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E310:
	movs r2, 0xC8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_801EF7C
	ldr r1, [r4]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801E458
_0801E322:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E330
	b _0801E458
_0801E330:
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E458
_0801E338:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E346
	b _0801E458
_0801E346:
	movs r0, 0x14
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xA
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E35C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E36A
	b _0801E458
_0801E36A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x8
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E378:
	bl sub_801FF08
	lsls r0, 24
	asrs r5, r0, 24
	cmp r5, 0
	beq _0801E3AC
	cmp r5, 0
	bgt _0801E392
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801E396
	b _0801E458
_0801E392:
	cmp r5, 0x1
	bne _0801E458
_0801E396:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801E458
	.pool
_0801E3AC:
	bl sub_80104B0
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EFD0
	ldr r0, [r4]
	movs r1, 0x4
	strh r1, [r0, 0x6]
	movs r2, 0xDC
	lsls r2, 1
	adds r0, r2
	strh r5, [r0]
	b _0801E458
	.pool
_0801E3D4:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E414
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E414
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E414
	ldr r1, [r4]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801E410
	movs r0, 0x6
	b _0801E412
	.pool
_0801E410:
	movs r0, 0x5
_0801E412:
	strh r0, [r1, 0x6]
_0801E414:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E458
	b _0801E42C
	.pool
_0801E424:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E438
_0801E42C:
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E458
	.pool
_0801E438:
	ldr r3, [r2]
	movs r1, 0xDC
	lsls r1, 1
	adds r2, r3, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	bls _0801E458
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x4
	strh r0, [r3, 0x6]
_0801E458:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E240

	thumb_func_start sub_801E460
sub_801E460: @ 801E460
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0x7
	bls _0801E470
	b _0801E5BC
_0801E470:
	lsls r0, 2
	ldr r1, =_0801E484
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E484:
	.4byte _0801E4A4
	.4byte _0801E4C8
	.4byte _0801E4E8
	.4byte _0801E50C
	.4byte _0801E540
	.4byte _0801E560
	.4byte _0801E584
	.4byte _0801E5A8
_0801E4A4:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _0801E4B2
	b _0801E5BC
_0801E4B2:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E4C8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E5BC
	movs r0, 0x12
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E4E8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E5BC
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EFA8
	ldr r1, [r4]
	b _0801E59A
	.pool
_0801E50C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E5BC
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	ldr r1, [r4]
	b _0801E59A
	.pool
_0801E540:
	bl GetBlockReceivedStatus
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801E5BC
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E5BC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801E59A
	.pool
_0801E560:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E5BC
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E5BC
	bl sub_800AC34
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	strh r4, [r1, 0xA]
	b _0801E59A
	.pool
_0801E584:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E590
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E590:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E5BC
	ldr r1, [r2]
_0801E59A:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E5BC
	.pool
_0801E5A8:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E5B8
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E5BC
_0801E5B8:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E5BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E460

	thumb_func_start sub_801E5C4
sub_801E5C4: @ 801E5C4
	push {r4,r5,lr}
	ldr r5, =gUnknown_02022C84
	ldr r1, [r5]
	ldrh r0, [r1, 0x6]
	cmp r0, 0x1
	beq _0801E604
	cmp r0, 0x1
	bgt _0801E5E0
	cmp r0, 0
	beq _0801E5EA
	b _0801E662
	.pool
_0801E5E0:
	cmp r0, 0x2
	beq _0801E62E
	cmp r0, 0x3
	beq _0801E650
	b _0801E662
_0801E5EA:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0801E662
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	b _0801E640
	.pool
_0801E604:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E662
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E662
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E662
	bl sub_800AC34
	ldr r1, [r5]
	strh r4, [r1, 0xA]
	b _0801E642
_0801E62E:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E638
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E638:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E662
_0801E640:
	ldr r1, [r5]
_0801E642:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E662
	.pool
_0801E650:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E65E
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E662
_0801E65E:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E662:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801E5C4

	thumb_func_start sub_801E668
sub_801E668: @ 801E668
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0801E75C
	lsls r0, 2
	ldr r1, =_0801E688
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E688:
	.4byte _0801E69C
	.4byte _0801E6C8
	.4byte _0801E6F0
	.4byte _0801E724
	.4byte _0801E748
_0801E69C:
	ldr r0, =sub_801F2B4
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0801E75C
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _0801E6BA
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
_0801E6BA:
	ldr r1, [r4]
	b _0801E73A
	.pool
_0801E6C8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E75C
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _0801E6E6
	movs r0, 0x13
	movs r1, 0
	bl sub_801F5EC
_0801E6E6:
	ldr r1, [r4]
	b _0801E73A
	.pool
_0801E6F0:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801E75C
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E75C
	bl sub_8011A9C
	adds r4, r0, 0
	cmp r4, 0
	bne _0801E75C
	bl sub_800AC34
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	strh r4, [r1, 0xA]
	b _0801E73A
	.pool
_0801E724:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bhi _0801E730
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E730:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E75C
	ldr r1, [r2]
_0801E73A:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E75C
	.pool
_0801E748:
	ldr r1, [r2]
	ldrh r0, [r1, 0xA]
	cmp r0, 0x95
	bls _0801E758
	movs r0, 0x9
	bl sub_801EBD4
	b _0801E75C
_0801E758:
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0801E75C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E668

	thumb_func_start sub_801E764
sub_801E764: @ 801E764
	push {r4,lr}
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0801E830
	lsls r0, 2
	ldr r1, =_0801E784
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E784:
	.4byte _0801E798
	.4byte _0801E7C0
	.4byte _0801E7F4
	.4byte _0801E802
	.4byte _0801E820
_0801E798:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801E7AC
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E830
	.pool
_0801E7AC:
	ldr r0, [r4]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bl sub_801EF4C
	ldr r1, [r4]
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
_0801E7C0:
	bl sub_800A520
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0801E830
	bl sub_8011A9C
	cmp r0, 0
	bne _0801E830
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	movs r2, 0x28
	bl SendBlock
	lsls r0, 24
	cmp r0, 0
	beq _0801E830
	ldr r1, [r4]
	b _0801E812
	.pool
_0801E7F4:
	bl sub_801EE10
	movs r0, 0x8
	movs r1, 0
	bl sub_801F5EC
	b _0801E80E
_0801E802:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E830
_0801E80E:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
_0801E812:
	ldrh r0, [r1, 0x6]
	adds r0, 0x1
	strh r0, [r1, 0x6]
	b _0801E830
	.pool
_0801E820:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801E830
	movs r0, 0x1
	bl sub_801EBD4
_0801E830:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E764

	thumb_func_start sub_801E838
sub_801E838: @ 801E838
	push {r4,lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrh r0, [r0, 0x6]
	cmp r0, 0x6
	bls _0801E846
	b _0801E968
_0801E846:
	lsls r0, 2
	ldr r1, =_0801E858
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E858:
	.4byte _0801E874
	.4byte _0801E8A4
	.4byte _0801E8F8
	.4byte _0801E910
	.4byte _0801E920
	.4byte _0801E934
	.4byte _0801E94C
_0801E874:
	bl sub_801EDC4
	cmp r0, 0
	beq _0801E890
	movs r0, 0x9
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	b _0801E966
	.pool
_0801E890:
	movs r0, 0xD
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x5
	b _0801E966
	.pool
_0801E8A4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801E8CC
	bl sub_801EDE0
	movs r0, 0xB
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	b _0801E966
	.pool
_0801E8CC:
	movs r4, 0x2
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0801E8DA
	movs r0, 0xA
	b _0801E95A
_0801E8DA:
	bl sub_801EBE4
	cmp r0, 0
	beq _0801E968
	movs r0, 0x1
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	strh r4, [r0, 0x6]
	b _0801E968
	.pool
_0801E8F8:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x1
	b _0801E966
	.pool
_0801E910:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	movs r0, 0xA
	b _0801E95A
_0801E920:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	movs r0, 0x1
	bl sub_801EBD4
	b _0801E968
_0801E934:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801E968
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x6
	b _0801E966
	.pool
_0801E94C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0801E968
	movs r0, 0x7
_0801E95A:
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x4
_0801E966:
	strh r0, [r1, 0x6]
_0801E968:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801E838

	thumb_func_start sub_801E978
sub_801E978: @ 801E978
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_02022C84
	ldr r0, [r1]
	ldrh r0, [r0, 0x6]
	adds r4, r1, 0
	cmp r0, 0xD
	bls _0801E98A
	b _0801EBC2
_0801E98A:
	lsls r0, 2
	ldr r1, =_0801E99C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801E99C:
	.4byte _0801E9D4
	.4byte _0801E9EE
	.4byte _0801EA14
	.4byte _0801EA58
	.4byte _0801EA7C
	.4byte _0801EA98
	.4byte _0801EADC
	.4byte _0801EB04
	.4byte _0801EB28
	.4byte _0801EB40
	.4byte _0801EB64
	.4byte _0801EB72
	.4byte _0801EB88
	.4byte _0801EBA8
_0801E9D4:
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	bne _0801E9DE
	b _0801EB82
_0801E9DE:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r1, [r4]
	movs r0, 0x1
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801E9EE:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801E9FC
	b _0801EBC2
_0801E9FC:
	movs r0, 0xE
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA14:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801EA40
	cmp r1, 0
	bgt _0801EA2E
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801EA34
	b _0801EBC2
_0801EA2E:
	cmp r1, 0x1
	beq _0801EA34
	b _0801EBC2
_0801EA34:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801EB82
	.pool
_0801EA40:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA58:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801EA66
	b _0801EBC2
_0801EA66:
	movs r0, 0xF
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x4
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA7C:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	beq _0801EA8A
	b _0801EBC2
_0801EA8A:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x5
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EA98:
	bl sub_801FF08
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0801EAC4
	cmp r1, 0
	bgt _0801EAB2
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801EAB8
	b _0801EBC2
_0801EAB2:
	cmp r1, 0x1
	beq _0801EAB8
	b _0801EBC2
_0801EAB8:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	b _0801EB82
	.pool
_0801EAC4:
	movs r0, 0x7
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x6
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EADC:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	movs r0, 0x10
	movs r1, 0
	bl sub_801F5EC
	bl sub_801EE2C
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x7
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB04:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	bl sub_8076D5C
	movs r0, 0
	bl TrySavingData
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x8
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB28:
	movs r0, 0x11
	movs r1, 0
	bl sub_801F5EC
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x9
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB40:
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801EBC2
	movs r0, 0x37
	bl PlaySE
	bl sav2_gender2_inplace_and_xFE
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xA
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EB64:
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x19]
	ldr r1, [r4]
	movs r0, 0xB
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801EB72:
	ldr r0, [r4]
	ldrb r1, [r0, 0x19]
	adds r1, 0x1
	strb r1, [r0, 0x19]
	ldr r1, [r4]
	ldrb r0, [r1, 0x19]
	cmp r0, 0x78
	bls _0801EBC2
_0801EB82:
	movs r0, 0xC
	strh r0, [r1, 0x6]
	b _0801EBC2
_0801EB88:
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0xD
	strh r0, [r1, 0x6]
	b _0801EBC2
	.pool
_0801EBA8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801EBC2
	bl sub_801F544
	bl sub_801DE30
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
_0801EBC2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801E978

	thumb_func_start sub_801EBD4
sub_801EBD4: @ 801EBD4
	ldr r1, =gUnknown_02022C84
	ldr r1, [r1]
	movs r2, 0
	strh r0, [r1, 0x4]
	strh r2, [r1, 0x6]
	bx lr
	.pool
	thumb_func_end sub_801EBD4

	thumb_func_start sub_801EBE4
sub_801EBE4: @ 801EBE4
	push {lr}
	ldr r0, =gMain
	ldrh r2, [r0, 0x30]
	movs r0, 0x40
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _0801EC6E
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _0801EC24
	ldr r0, =gUnknown_02022C84
	ldr r2, [r0]
	ldr r1, =gUnknown_082F2AA4
	ldrb r0, [r2, 0x10]
	adds r0, r1
	ldrb r1, [r2, 0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0801EC20
	adds r0, r1, 0x1
	b _0801EC88
	.pool
_0801EC20:
	strb r3, [r2, 0x12]
	b _0801EC8A
_0801EC24:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x10]
	cmp r0, 0x3
	beq _0801EC6A
	movs r0, 0x20
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	beq _0801EC52
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _0801EC4C
	subs r0, 0x1
	strb r0, [r1, 0x11]
	b _0801EC8A
	.pool
_0801EC4C:
	movs r0, 0x4
	strb r0, [r1, 0x11]
	b _0801EC8A
_0801EC52:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _0801EC6A
	ldrb r0, [r1, 0x11]
	cmp r0, 0x3
	bhi _0801EC66
	adds r0, 0x1
	strb r0, [r1, 0x11]
	b _0801EC8A
_0801EC66:
	strb r3, [r1, 0x11]
	b _0801EC8A
_0801EC6A:
	movs r0, 0
	b _0801EC8C
_0801EC6E:
	ldr r0, =gUnknown_02022C84
	ldr r2, [r0]
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0801EC80
	subs r0, 0x1
	b _0801EC88
	.pool
_0801EC80:
	ldr r0, =gUnknown_082F2AA4
	ldrb r1, [r2, 0x10]
	adds r1, r0
	ldrb r0, [r1]
_0801EC88:
	strb r0, [r2, 0x12]
_0801EC8A:
	movs r0, 0x1
_0801EC8C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EBE4

	thumb_func_start sub_801EC94
sub_801EC94: @ 801EC94
	push {r4-r6,lr}
	sub sp, 0x18
	ldr r0, =gUnknown_02022C84
	ldr r5, [r0]
	ldrb r0, [r5, 0x10]
	cmp r0, 0x3
	beq _0801ECDC
	ldr r3, =gUnknown_082F2BA8
	ldrb r1, [r5, 0x12]
	lsls r1, 2
	adds r2, r0, 0
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r3
	ldr r4, [r1]
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _0801ECCE
	adds r1, r0, 0
_0801ECBE:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne _0801ECC6
	adds r4, 0x1
_0801ECC6:
	adds r4, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _0801ECBE
_0801ECCE:
	movs r5, 0x1
	b _0801ED02
	.pool
_0801ECDC:
	ldrb r0, [r5, 0x12]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r0
	adds r1, 0xB9
	adds r1, r5, r1
	mov r0, sp
	bl StringCopy
	movs r1, 0
	strb r1, [r0]
	movs r1, 0xFF
	strb r1, [r0, 0x1]
	mov r4, sp
	mov r0, sp
	bl StringLength_Multibyte
	adds r5, r0, 0
_0801ED02:
	ldr r6, =gUnknown_02022C84
	ldr r1, [r6]
	ldrb r0, [r1, 0x15]
	strb r0, [r1, 0x14]
	cmp r4, 0
	beq _0801ED5A
	bl sub_801EE84
	adds r2, r0, 0
	subs r5, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801ED56
	ldr r0, [r6]
	ldrb r0, [r0, 0x15]
	cmp r0, 0xE
	bhi _0801ED56
	adds r3, r6, 0
_0801ED28:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne _0801ED34
	strb r0, [r2]
	adds r4, 0x1
	adds r2, 0x1
_0801ED34:
	ldrb r0, [r4]
	strb r0, [r2]
	adds r4, 0x1
	adds r2, 0x1
	ldr r1, [r3]
	ldrb r0, [r1, 0x15]
	adds r0, 0x1
	strb r0, [r1, 0x15]
	subs r5, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0801ED56
	ldr r0, [r3]
	ldrb r0, [r0, 0x15]
	cmp r0, 0xE
	bls _0801ED28
_0801ED56:
	movs r0, 0xFF
	strb r0, [r2]
_0801ED5A:
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EC94

	thumb_func_start sub_801ED68
sub_801ED68: @ 801ED68
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	strb r0, [r1, 0x14]
	ldr r0, [r4]
	ldrb r0, [r0, 0x15]
	cmp r0, 0
	beq _0801ED8A
	bl sub_801EEA8
	movs r1, 0xFF
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	subs r0, 0x1
	strb r0, [r1, 0x15]
_0801ED8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801ED68

	thumb_func_start sub_801ED94
sub_801ED94: @ 801ED94
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x15]
	subs r0, 0x1
	strb r0, [r1, 0x14]
	bl sub_801EEA8
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0xF9
	beq _0801EDB8
	ldr r1, =gUnknown_082F2AA8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801EDB8
	strb r0, [r2]
_0801EDB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801ED94

	thumb_func_start sub_801EDC4
sub_801EDC4: @ 801EDC4
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	cmp r0, 0
	bne _0801EDD8
	movs r0, 0
	b _0801EDDA
	.pool
_0801EDD8:
	movs r0, 0x1
_0801EDDA:
	pop {r1}
	bx r1
	thumb_func_end sub_801EDC4

	thumb_func_start sub_801EDE0
sub_801EDE0: @ 801EDE0
	push {r4,lr}
	bl sub_801F114
	adds r1, r0, 0
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	ldrb r3, [r0, 0x12]
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 2
	adds r2, r3
	adds r2, 0xB9
	adds r0, r2
	bl StringCopy
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EDE0

	thumb_func_start sub_801EE10
sub_801EE10: @ 801EE10
	ldr r1, =gUnknown_02022C84
	ldr r2, [r1]
	movs r0, 0xFF
	strb r0, [r2, 0x1A]
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0xF
	strb r0, [r2, 0x14]
	ldr r0, [r1]
	strb r3, [r0, 0x15]
	bx lr
	.pool
	thumb_func_end sub_801EE10

	thumb_func_start sub_801EE2C
sub_801EE2C: @ 801EE2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gSaveBlock1Ptr
	mov r8, r0
	ldr r7, =gUnknown_02022C84
	movs r6, 0xB9
	ldr r5, =0x00003c88
	movs r4, 0x9
_0801EE3E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	ldr r1, [r7]
	adds r1, r6
	bl StringCopy
	adds r6, 0x15
	adds r5, 0x15
	subs r4, 0x1
	cmp r4, 0
	bge _0801EE3E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EE2C

	thumb_func_start sub_801EE6C
sub_801EE6C: @ 801EE6C
	ldr r2, =gUnknown_02022C84
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r0
	adds r1, 0xB9
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801EE6C

	thumb_func_start sub_801EE84
sub_801EE84: @ 801EE84
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	ldrb r0, [r0, 0x1A]
	cmp r0, 0xFF
	beq _0801EE9C
_0801EE94:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0801EE94
_0801EE9C:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EE84

	thumb_func_start sub_801EEA8
sub_801EEA8: @ 801EEA8
	push {lr}
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x1A
	adds r1, r2, 0
	ldrb r0, [r0, 0x1A]
	cmp r0, 0xFF
	beq _0801EECC
_0801EEBA:
	adds r2, r1, 0
	ldrb r0, [r2]
	cmp r0, 0xF9
	bne _0801EEC4
	adds r1, r2, 0x1
_0801EEC4:
	adds r1, 0x1
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0801EEBA
_0801EECC:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EEA8

	thumb_func_start sub_801EED8
sub_801EED8: @ 801EED8
	push {r4,lr}
	ldr r4, =gUnknown_02022C84
	ldr r0, [r4]
	adds r0, 0x1A
	bl StringLength_Multibyte
	adds r2, r0, 0
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x1A
	movs r4, 0
	cmp r2, 0xA
	bls _0801EF0C
	subs r2, 0xA
	movs r3, 0
	cmp r4, r2
	bcs _0801EF0C
_0801EEFA:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801EF02
	adds r1, 0x1
_0801EF02:
	adds r1, 0x1
	adds r4, 0x1
	adds r3, 0x1
	cmp r3, r2
	bcc _0801EEFA
_0801EF0C:
	lsls r0, r4, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801EED8

	thumb_func_start sub_801EF1C
sub_801EF1C: @ 801EF1C
	movs r1, 0
	strb r1, [r0]
	bx lr
	thumb_func_end sub_801EF1C

	thumb_func_start sub_801EF24
sub_801EF24: @ 801EF24
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF24

	thumb_func_start sub_801EF4C
sub_801EF4C: @ 801EF4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	adds r4, 0x9
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	adds r1, 0x1A
	adds r0, r4, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF4C

	thumb_func_start sub_801EF7C
sub_801EF7C: @ 801EF7C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	bl sub_8011A50
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EF7C

	thumb_func_start sub_801EFA8
sub_801EFA8: @ 801EFA8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EFA8

	thumb_func_start sub_801EFD0
sub_801EFD0: @ 801EFD0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5
	strb r0, [r4]
	adds r0, r4, 0x1
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	bl StringCopy
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	strb r0, [r4, 0x9]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801EFD0

	thumb_func_start sub_801EFF8
sub_801EFF8: @ 801EFF8
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldrb r0, [r5]
	adds r1, r0, 0
	adds r4, r5, 0x1
	adds r5, r4, 0
	adds r5, 0x8
	cmp r0, 0x2
	beq _0801F020
	cmp r0, 0x2
	bgt _0801F016
	cmp r0, 0x1
	beq _0801F044
	b _0801F0A8
_0801F016:
	cmp r1, 0x3
	beq _0801F07A
	cmp r1, 0x5
	beq _0801F06E
	b _0801F0A8
_0801F020:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	ldrb r1, [r4, 0x8]
	cmp r0, r1
	beq _0801F0A8
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, =gText_F700JoinedChat
	b _0801F094
	.pool
_0801F044:
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringCopy
	movs r1, 0xFC
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x13
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x2A
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF0
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	bl StringCopy
	movs r0, 0x1
	b _0801F0AA
_0801F06E:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x79
	adds r1, r4, 0
	bl StringCopy
_0801F07A:
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	ldrb r5, [r5]
	cmp r0, r5
	beq _0801F0A8
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0
	adds r1, r4, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, =gText_F700LeftChat
_0801F094:
	adds r0, r6, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, 0x1
	b _0801F0AA
	.pool
_0801F0A8:
	movs r0, 0
_0801F0AA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801EFF8

	thumb_func_start sub_801F0B0
sub_801F0B0: @ 801F0B0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bx lr
	.pool
	thumb_func_end sub_801F0B0

	thumb_func_start sub_801F0BC
sub_801F0BC: @ 801F0BC
	ldr r2, =gUnknown_02022C84
	ldr r3, [r2]
	ldrb r2, [r3, 0x11]
	strb r2, [r0]
	ldrb r0, [r3, 0x12]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801F0BC

	thumb_func_start sub_801F0D0
sub_801F0D0: @ 801F0D0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x1A
	bx lr
	.pool
	thumb_func_end sub_801F0D0

	thumb_func_start sub_801F0DC
sub_801F0DC: @ 801F0DC
	push {lr}
	bl sub_801F0D0
	bl StringLength_Multibyte
	pop {r1}
	bx r1
	thumb_func_end sub_801F0DC

	thumb_func_start sub_801F0EC
sub_801F0EC: @ 801F0EC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r3, [r0, 0x15]
	ldrb r2, [r0, 0x14]
	subs r0, r3, r2
	cmp r0, 0
	bge _0801F108
	negs r0, r0
	str r3, [r4]
	b _0801F10A
	.pool
_0801F108:
	str r2, [r4]
_0801F10A:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801F0EC

	thumb_func_start sub_801F114
sub_801F114: @ 801F114
	push {lr}
	bl sub_801EED8
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	cmp r2, 0
	beq _0801F13A
_0801F12A:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801F132
	adds r1, 0x1
_0801F132:
	adds r1, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0801F12A
_0801F13A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801F114

	thumb_func_start sub_801F144
sub_801F144: @ 801F144
	push {r4,lr}
	bl sub_801EED8
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x1A
	movs r2, 0
	movs r3, 0
	cmp r2, r4
	bcs _0801F174
_0801F15E:
	ldrb r0, [r1]
	cmp r0, 0xF9
	bne _0801F166
	adds r1, 0x1
_0801F166:
	adds r1, 0x1
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, 0x1
	cmp r3, r4
	bcc _0801F15E
_0801F174:
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801F144

	thumb_func_start sub_801F180
sub_801F180: @ 801F180
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x39
	bx lr
	.pool
	thumb_func_end sub_801F180

	thumb_func_start sub_801F18C
sub_801F18C: @ 801F18C
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x16]
	bx lr
	.pool
	thumb_func_end sub_801F18C

	thumb_func_start sub_801F198
sub_801F198: @ 801F198
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	bx lr
	.pool
	thumb_func_end sub_801F198

	thumb_func_start sub_801F1A4
sub_801F1A4: @ 801F1A4
	push {lr}
	bl sub_801EEA8
	ldrb r1, [r0]
	cmp r1, 0xFF
	bhi _0801F1BE
	ldr r0, =gUnknown_082F2AA8
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, r1
	beq _0801F1BE
	cmp r0, 0
	bne _0801F1C8
_0801F1BE:
	movs r0, 0x3
	b _0801F1CA
	.pool
_0801F1C8:
	movs r0, 0
_0801F1CA:
	pop {r1}
	bx r1
	thumb_func_end sub_801F1A4

	thumb_func_start sub_801F1D0
sub_801F1D0: @ 801F1D0
	ldr r0, =gUnknown_02022C84
	ldr r0, [r0]
	adds r0, 0x79
	bx lr
	.pool
	thumb_func_end sub_801F1D0

	thumb_func_start copy_strings_to_sav1
copy_strings_to_sav1: @ 801F1DC
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003c88
	adds r0, r1
	ldr r1, =gText_Hello
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003c9d
	adds r0, r1
	ldr r1, =gText_Pokemon2
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cb2
	adds r0, r1
	ldr r1, =gText_Trade
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cc7
	adds r0, r1
	ldr r1, =gText_Battle
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cdc
	adds r0, r1
	ldr r1, =gText_Lets
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003cf1
	adds r0, r1
	ldr r1, =gText_Ok
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d06
	adds r0, r1
	ldr r1, =gText_Sorry
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d1b
	adds r0, r1
	ldr r1, =gText_YayUnkF9F9
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d30
	adds r0, r1
	ldr r1, =gText_ThankYou
	bl StringCopy
	ldr r0, [r4]
	ldr r1, =0x00003d45
	adds r0, r1
	ldr r1, =gText_ByeBye
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_strings_to_sav1

	thumb_func_start sub_801F2B4
sub_801F2B4: @ 801F2B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bls _0801F2CE
	b _0801F4C4
_0801F2CE:
	lsls r0, 2
	ldr r1, =_0801F2E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F2E0:
	.4byte _0801F300
	.4byte _0801F30E
	.4byte _0801F4A8
	.4byte _0801F35C
	.4byte _0801F448
	.4byte _0801F480
	.4byte _0801F494
	.4byte _0801F438
_0801F300:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801F30A
	b _0801F49C
_0801F30A:
	movs r0, 0x1
	strh r0, [r4]
_0801F30E:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	strh r0, [r4, 0x8]
	ldr r3, =gUnknown_02022C84
	ldr r0, [r3]
	ldrb r1, [r0, 0xD]
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	cmp r1, r0
	beq _0801F33C
	movs r0, 0x2
	strh r0, [r4]
	ldr r0, [r3]
	strb r2, [r0, 0xD]
	b _0801F4C4
	.pool
_0801F33C:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x6]
	cmp r0, 0
	bne _0801F354
	bl sub_8011A9C
	cmp r0, 0
	beq _0801F354
	b _0801F4C4
_0801F354:
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x3
	strh r0, [r4]
_0801F35C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bgt _0801F396
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801F396
	movs r2, 0x1
_0801F378:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _0801F396
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	ands r0, r2
	cmp r0, 0
	beq _0801F378
_0801F396:
	ldrh r1, [r4, 0x2]
	movs r5, 0x2
	ldrsh r0, [r4, r5]
	cmp r0, 0x5
	bne _0801F3A2
	b _0801F4C0
_0801F3A2:
	strh r1, [r4, 0x4]
	lsls r0, r1, 24
	lsrs r0, 24
	bl ResetBlockReceivedFlag
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	lsls r0, 8
	ldr r1, =gBlockRecvBuffer
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r0, 0x4
	bhi _0801F3E4
	lsls r0, 2
	ldr r1, =_0801F3D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F3D0:
	.4byte _0801F3E4
	.4byte _0801F3E8
	.4byte _0801F3EC
	.4byte _0801F3F0
	.4byte _0801F3F4
_0801F3E4:
	movs r0, 0x3
	b _0801F3F6
_0801F3E8:
	movs r0, 0x3
	b _0801F3F6
_0801F3EC:
	movs r0, 0x4
	b _0801F3F6
_0801F3F0:
	movs r0, 0x5
	b _0801F3F6
_0801F3F4:
	movs r0, 0x6
_0801F3F6:
	strh r0, [r4, 0xA]
	ldr r5, =gUnknown_02022C84
	ldr r0, [r5]
	adds r0, 0x39
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 8
	ldr r2, =gBlockRecvBuffer
	adds r1, r2
	bl sub_801EFF8
	cmp r0, 0
	beq _0801F42C
	ldr r0, [r5]
	ldrh r1, [r4, 0x2]
	strb r1, [r0, 0x16]
	movs r0, 0xC
	movs r1, 0x2
	bl sub_801F5EC
	movs r0, 0x7
	b _0801F42E
	.pool
_0801F42C:
	ldrh r0, [r4, 0xA]
_0801F42E:
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _0801F4C4
_0801F438:
	movs r0, 0x2
	bl sub_801F644
	lsls r0, 24
	cmp r0, 0
	bne _0801F4C4
	ldrh r0, [r4, 0xA]
	b _0801F4C2
_0801F448:
	ldr r6, =gUnknown_02022C84
	ldr r0, [r6]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	bne _0801F47C
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0801F47C
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0801F474
	bl sub_80104B0
	ldr r1, [r6]
	movs r0, 0x1
	b _0801F49A
	.pool
_0801F474:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	bl sub_8011DE0
_0801F47C:
	movs r0, 0x3
	b _0801F4C2
_0801F480:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _0801F49C
	movs r0, 0x2
	b _0801F49A
	.pool
_0801F494:
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	movs r0, 0x3
_0801F49A:
	strb r0, [r1, 0x17]
_0801F49C:
	adds r0, r5, 0
	bl DestroyTask
	b _0801F4C4
	.pool
_0801F4A8:
	bl sub_8011A9C
	cmp r0, 0
	bne _0801F4C4
	ldr r0, =gUnknown_02022C84
	ldr r1, [r0]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _0801F4C0
	ldrb r0, [r1, 0xD]
	bl sub_80110B8
_0801F4C0:
	movs r0, 0x1
_0801F4C2:
	strh r0, [r4]
_0801F4C4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F2B4

	thumb_func_start sub_801F4D0
sub_801F4D0: @ 801F4D0
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, =0x00002168
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _0801F52C
	bl sub_8020890
	cmp r0, 0
	beq _0801F52C
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F2C60
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_082F2C70
	bl InitWindows
	bl reset_temp_tile_data_buffers
	bl sub_8020770
	ldr r0, [r4]
	bl sub_801F574
	bl sub_801F580
	movs r0, 0
	movs r1, 0
	bl sub_801F5EC
	movs r0, 0x1
	b _0801F52E
	.pool
_0801F52C:
	movs r0, 0
_0801F52E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F4D0

	thumb_func_start sub_801F534
sub_801F534: @ 801F534
	push {lr}
	movs r0, 0
	bl sub_801F644
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_801F534

	thumb_func_start sub_801F544
sub_801F544: @ 801F544
	push {r4,lr}
	bl sub_80208D0
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	cmp r0, 0
	beq _0801F55A
	bl Free
	movs r0, 0
	str r0, [r4]
_0801F55A:
	bl FreeAllWindowBuffers
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F544

	thumb_func_start sub_801F574
sub_801F574: @ 801F574
	movs r2, 0
	movs r1, 0xFF
	strh r1, [r0, 0x18]
	strh r1, [r0, 0x1E]
	strh r2, [r0, 0x1A]
	bx lr
	thumb_func_end sub_801F574

	thumb_func_start sub_801F580
sub_801F580: @ 801F580
	push {r4,r5,lr}
	ldr r1, =gUnknown_02022C88
	ldr r0, [r1]
	cmp r0, 0
	beq _0801F5A8
	movs r2, 0
	adds r4, r1, 0
	ldr r5, =sub_801FDD8
	movs r3, 0
_0801F592:
	ldr r0, [r4]
	lsls r1, r2, 3
	adds r0, r1
	str r5, [r0]
	strb r3, [r0, 0x4]
	ldr r0, [r4]
	adds r0, r1
	strb r3, [r0, 0x5]
	adds r2, 0x1
	cmp r2, 0x2
	ble _0801F592
_0801F5A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F580

	thumb_func_start sub_801F5B8
sub_801F5B8: @ 801F5B8
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C88
	ldr r0, [r1]
	cmp r0, 0
	beq _0801F5E0
	movs r5, 0
	adds r6, r1, 0
_0801F5C6:
	ldr r1, [r6]
	lsls r4, r5, 3
	adds r1, r4
	adds r0, r1, 0x5
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, [r6]
	adds r1, r4
	strb r0, [r1, 0x4]
	adds r5, 0x1
	cmp r5, 0x2
	ble _0801F5C6
_0801F5E0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801F5B8

	thumb_func_start sub_801F5EC
sub_801F5EC: @ 801F5EC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	ldr r3, =gUnknown_02022C88
	ldr r0, [r3]
	lsrs r1, 21
	adds r0, r1
	ldr r2, =sub_801FDD8
	str r2, [r0]
	movs r4, 0
	adds r5, r3, 0
	adds r3, r1, 0
	mov r12, r4
	ldr r1, =gUnknown_082F2C98
	movs r7, 0x1
	adds r2, r1, 0x4
_0801F60E:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0801F634
	ldr r1, [r5]
	adds r1, r3
	ldr r0, [r2]
	str r0, [r1]
	strb r7, [r1, 0x4]
	ldr r0, [r5]
	adds r0, r3
	mov r1, r12
	strb r1, [r0, 0x5]
	b _0801F63E
	.pool
_0801F634:
	adds r1, 0x8
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x14
	bls _0801F60E
_0801F63E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801F5EC

	thumb_func_start sub_801F644
sub_801F644: @ 801F644
	lsls r0, 24
	ldr r1, =gUnknown_02022C88
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	ldrb r0, [r1, 0x4]
	bx lr
	.pool
	thumb_func_end sub_801F644

	thumb_func_start sub_801F658
sub_801F658: @ 801F658
	push {r4,lr}
	adds r4, r0, 0
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801F6EE
	ldrb r0, [r4]
	cmp r0, 0x6
	bhi _0801F6E4
	lsls r0, 2
	ldr r1, =_0801F67C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801F67C:
	.4byte _0801F698
	.4byte _0801F6A2
	.4byte _0801F6A8
	.4byte _0801F6AE
	.4byte _0801F6B4
	.4byte _0801F6BA
	.4byte _0801F6CC
_0801F698:
	bl sub_8020480
	bl sub_8020538
	b _0801F6E8
_0801F6A2:
	bl sub_8020584
	b _0801F6E8
_0801F6A8:
	bl sub_80205B4
	b _0801F6E8
_0801F6AE:
	bl task_tutorial_story_unknown
	b _0801F6E8
_0801F6B4:
	bl sub_8020680
	b _0801F6E8
_0801F6BA:
	bl sub_80206A4
	bl sub_80206D0
	bl sub_8020740
	bl sub_80206E8
	b _0801F6E8
_0801F6CC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F6E8
	bl sub_80208E8
	bl sub_8020A68
	bl sub_8020B20
	b _0801F6E8
_0801F6E4:
	movs r0, 0
	b _0801F6F0
_0801F6E8:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F6EE:
	movs r0, 0x1
_0801F6F0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F658

	thumb_func_start sub_801F6F8
sub_801F6F8: @ 801F6F8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F708
	cmp r0, 0x1
	beq _0801F716
	b _0801F720
_0801F708:
	bl sub_80203B0
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F720
_0801F716:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F728
_0801F720:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F728:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F6F8

	thumb_func_start sub_801F730
sub_801F730: @ 801F730
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F740
	cmp r0, 0x1
	beq _0801F74E
	b _0801F758
_0801F740:
	bl sub_802040C
	movs r0, 0x3
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F758
_0801F74E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F760
_0801F758:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F760:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F730

	thumb_func_start sub_801F768
sub_801F768: @ 801F768
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _0801F79E
	cmp r0, 0x1
	bgt _0801F77C
	cmp r0, 0
	beq _0801F782
	b _0801F7C4
_0801F77C:
	cmp r0, 0x2
	beq _0801F7AA
	b _0801F7C4
_0801F782:
	movs r0, 0x1
	bl sub_802091C
	bl sub_8020320
	cmp r0, 0
	bne _0801F7CA
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F7C4
_0801F79E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _0801F7C4
	b _0801F7CA
_0801F7AA:
	bl sub_8020368
	cmp r0, 0
	bne _0801F7CA
	bl sub_802093C
	movs r0, 0
	bl sub_802091C
	bl sub_8020B80
	movs r0, 0
	b _0801F7CC
_0801F7C4:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F7CA:
	movs r0, 0x1
_0801F7CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F768

	thumb_func_start sub_801F7D4
sub_801F7D4: @ 801F7D4
	push {lr}
	bl sub_802093C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_801F7D4

	thumb_func_start sub_801F7E0
sub_801F7E0: @ 801F7E0
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F7F0
	cmp r0, 0x1
	beq _0801F814
	b _0801F81E
_0801F7F0:
	movs r0, 0
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xB
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F81E
	.pool
_0801F814:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801F826
_0801F81E:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
_0801F826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F7E0

	thumb_func_start sub_801F82C
sub_801F82C: @ 801F82C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F83C
	cmp r0, 0x1
	beq _0801F84C
	b _0801F862
_0801F83C:
	bl sub_8020094
	bl sub_801FEBC
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	b _0801F862
_0801F84C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F868
	bl sub_80200C8
	bl sub_801FEE4
	movs r0, 0
	b _0801F86A
_0801F862:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F868:
	movs r0, 0x1
_0801F86A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F82C

	thumb_func_start sub_801F870
sub_801F870: @ 801F870
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801F882
	cmp r0, 0x1
	beq _0801F8BA
	b _0801F8CC
_0801F882:
	add r1, sp, 0x8
	add r0, sp, 0x4
	bl sub_801F0EC
	ldr r0, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x8]
	lsls r1, 16
	lsrs r1, 16
	movs r2, 0
	bl sub_80200EC
	bl sub_801F0D0
	adds r1, r0, 0
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F8CC
_0801F8BA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F8D2
	bl sub_8020B80
	movs r0, 0
	b _0801F8D4
_0801F8CC:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_0801F8D2:
	movs r0, 0x1
_0801F8D4:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801F870

	thumb_func_start sub_801F8DC
sub_801F8DC: @ 801F8DC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F938
	cmp r0, 0x1
	bgt _0801F8F2
	cmp r0, 0
	beq _0801F8FC
	b _0801F972
_0801F8F2:
	cmp r0, 0x2
	beq _0801F95C
	cmp r0, 0x3
	beq _0801F96E
	b _0801F972
_0801F8FC:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x66
	bl sub_80200EC
	movs r0, 0x5
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x4
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801F972
_0801F938:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801F972
	.pool
_0801F95C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801F978
	movs r0, 0x1
	bl sub_80209AC
	b _0801F972
_0801F96E:
	movs r0, 0
	b _0801F97A
_0801F972:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801F978:
	movs r0, 0x1
_0801F97A:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F8DC

	thumb_func_start sub_801F984
sub_801F984: @ 801F984
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0801F9E0
	cmp r0, 0x1
	bgt _0801F99A
	cmp r0, 0
	beq _0801F9A4
	b _0801FA1A
_0801F99A:
	cmp r0, 0x2
	beq _0801FA00
	cmp r0, 0x3
	beq _0801FA16
	b _0801FA1A
_0801F9A4:
	bl sub_801F144
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_801F114
	adds r5, r0, 0
	bl StringLength_Multibyte
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl sub_80200EC
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_8020118
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FA1A
_0801F9E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	bl sub_8020094
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	b _0801FA1A
	.pool
_0801FA00:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA20
	movs r0, 0
	bl sub_80209AC
	bl sub_80200C8
	b _0801FA1A
_0801FA16:
	movs r0, 0
	b _0801FA22
_0801FA1A:
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FA20:
	movs r0, 0x1
_0801FA22:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801F984

	thumb_func_start sub_801FA2C
sub_801FA2C: @ 801FA2C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FA3C
	cmp r0, 0x1
	beq _0801FA50
	b _0801FA5E
_0801FA3C:
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FA5E
_0801FA50:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FA5E
	movs r0, 0
	b _0801FA60
_0801FA5E:
	movs r0, 0x1
_0801FA60:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA2C

	thumb_func_start sub_801FA68
sub_801FA68: @ 801FA68
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrb r0, [r6]
	cmp r0, 0x4
	bhi _0801FB3A
	lsls r0, 2
	ldr r1, =_0801FA80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801FA80:
	.4byte _0801FA94
	.4byte _0801FAC0
	.4byte _0801FAF0
	.4byte _0801FB14
	.4byte _0801FADE
_0801FA94:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r5, [r0, 0x1A]
	bl sub_801F180
	adds r4, r0, 0
	bl sub_801F18C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8020420
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _0801FB34
	.pool
_0801FAC0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1A]
	cmp r0, 0x8
	bhi _0801FAE8
	adds r0, 0x1
	strh r0, [r1, 0x1A]
	movs r0, 0x4
	strb r0, [r6]
_0801FADE:
	movs r0, 0
	b _0801FB3C
	.pool
_0801FAE8:
	strh r2, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FAF0:
	movs r0, 0
	movs r1, 0
	movs r2, 0x5
	movs r3, 0x11
	bl ScrollWindow
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldrh r0, [r1, 0x1C]
	adds r0, 0x1
	strh r0, [r1, 0x1C]
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_0801FB14:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801FB3A
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrh r0, [r0, 0x1C]
	cmp r0, 0x2
	bhi _0801FB34
	ldrb r0, [r6]
	subs r0, 0x1
	b _0801FB38
	.pool
_0801FB34:
	ldrb r0, [r6]
	adds r0, 0x1
_0801FB38:
	strb r0, [r6]
_0801FB3A:
	movs r0, 0x1
_0801FB3C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801FA68

	thumb_func_start sub_801FB44
sub_801FB44: @ 801FB44
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB54
	cmp r0, 0x1
	beq _0801FB60
	b _0801FB66
_0801FB54:
	bl sub_80209E0
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FB66
_0801FB60:
	bl sub_8020A1C
	b _0801FB68
_0801FB66:
	movs r0, 0x1
_0801FB68:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB44

	thumb_func_start sub_801FB70
sub_801FB70: @ 801FB70
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FB80
	cmp r0, 0x1
	beq _0801FBA0
	b _0801FBAA
_0801FB80:
	movs r0, 0x3
	movs r1, 0x10
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBAA
	.pool
_0801FBA0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBAC
_0801FBAA:
	movs r0, 0x1
_0801FBAC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FB70

	thumb_func_start sub_801FBB4
sub_801FBB4: @ 801FBB4
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FBC4
	cmp r0, 0x1
	beq _0801FBE4
	b _0801FBEE
_0801FBC4:
	movs r0, 0x4
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FBEE
	.pool
_0801FBE4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FBF0
_0801FBEE:
	movs r0, 0x1
_0801FBF0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBB4

	thumb_func_start sub_801FBF8
sub_801FBF8: @ 801FBF8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC08
	cmp r0, 0x1
	beq _0801FC38
	b _0801FC42
_0801FC08:
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_801F1D0
	adds r1, r0, 0
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x5
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC42
	.pool
_0801FC38:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC44
_0801FC42:
	movs r0, 0x1
_0801FC44:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FBF8

	thumb_func_start sub_801FC4C
sub_801FC4C: @ 801FC4C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FC5C
	cmp r0, 0x1
	beq _0801FC88
	b _0801FC92
_0801FC5C:
	movs r0, 0x6
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FC92
	.pool
_0801FC88:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FC94
_0801FC92:
	movs r0, 0x1
_0801FC94:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC4C

	thumb_func_start sub_801FC9C
sub_801FC9C: @ 801FC9C
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCAC
	cmp r0, 0x1
	beq _0801FCD8
	b _0801FCE2
_0801FCAC:
	movs r0, 0x7
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FCE2
	.pool
_0801FCD8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FCE4
_0801FCE2:
	movs r0, 0x1
_0801FCE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FC9C

	thumb_func_start sub_801FCEC
sub_801FCEC: @ 801FCEC
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FCFC
	cmp r0, 0x1
	beq _0801FD1C
	b _0801FD26
_0801FCFC:
	movs r0, 0x8
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD26
	.pool
_0801FD1C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD28
_0801FD26:
	movs r0, 0x1
_0801FD28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FCEC

	thumb_func_start sub_801FD30
sub_801FD30: @ 801FD30
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD40
	cmp r0, 0x1
	beq _0801FD74
	b _0801FD7E
_0801FD40:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, 0x9
	movs r1, 0
	bl sub_801FF18
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FD7E
	.pool
_0801FD74:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FD80
_0801FD7E:
	movs r0, 0x1
_0801FD80:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD30

	thumb_func_start sub_801FD88
sub_801FD88: @ 801FD88
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _0801FD98
	cmp r0, 0x1
	beq _0801FDC4
	b _0801FDCE
_0801FD98:
	movs r0, 0xA
	movs r1, 0
	bl sub_801FF18
	movs r0, 0x17
	movs r1, 0xA
	movs r2, 0x1
	bl sub_801FDDC
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	ldrb r0, [r0, 0x1E]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0801FDCE
	.pool
_0801FDC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0801FDD0
_0801FDCE:
	movs r0, 0x1
_0801FDD0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801FD88

	thumb_func_start sub_801FDD8
sub_801FDD8: @ 801FDD8
	movs r0, 0
	bx lr
	thumb_func_end sub_801FDD8

	thumb_func_start sub_801FDDC
sub_801FDDC: @ 801FDDC
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsls r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r4, =0xffffff00
	ldr r2, [sp, 0xC]
	ands r2, r4
	lsrs r0, 16
	ldr r3, =0xffff00ff
	ands r2, r3
	orrs r2, r0
	lsrs r1, 8
	ldr r0, =0xff00ffff
	ands r2, r0
	orrs r2, r1
	ldr r0, =0x00ffffff
	ands r2, r0
	movs r0, 0xC0
	lsls r0, 19
	orrs r2, r0
	str r2, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r4
	movs r1, 0x4
	orrs r0, r1
	ands r0, r3
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xA4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl AddWindow
	adds r1, r0, 0
	ldr r5, =gUnknown_02022C88
	ldr r0, [r5]
	movs r6, 0
	strh r1, [r0, 0x18]
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, 0xFF
	beq _0801FE94
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r4, 0xFF
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	movs r1, 0x2
	adds r2, r7, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
_0801FE94:
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FDDC

	thumb_func_start sub_801FEBC
sub_801FEBC: @ 801FEBC
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEDA
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8198070
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl ClearWindowTilemap
_0801FEDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEBC

	thumb_func_start sub_801FEE4
sub_801FEE4: @ 801FEE4
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x18]
	cmp r0, 0xFF
	beq _0801FEFE
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x18]
_0801FEFE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FEE4

	thumb_func_start sub_801FF08
sub_801FF08: @ 801FF08
	push {lr}
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_801FF08

	thumb_func_start sub_801FF18
sub_801FF18: @ 801FF18
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	adds r7, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r1, =0xffffff00
	ldr r3, [sp, 0x14]
	ands r3, r1
	ldr r2, =0xffff00ff
	ands r3, r2
	movs r0, 0x80
	lsls r0, 4
	orrs r3, r0
	ldr r0, =0xff00ffff
	ands r3, r0
	movs r0, 0x80
	lsls r0, 13
	orrs r3, r0
	ldr r5, =0x00ffffff
	ands r3, r5
	movs r0, 0xA8
	lsls r0, 21
	orrs r3, r0
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x18]
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	ands r0, r2
	movs r1, 0xE0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xD4
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x18]
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0801FF98
	lsls r0, r3, 16
	movs r1, 0xF9
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	ands r2, r3
	orrs r2, r0
	lsrs r1, r2, 24
	adds r1, 0x7
	lsls r1, 24
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
_0801FF98:
	add r0, sp, 0x14
	bl AddWindow
	ldr r5, =gUnknown_02022C88
	ldr r1, [r5]
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x1E]
	mov r8, r0
	cmp r0, 0xFF
	beq _08020082
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801FFE0
	adds r0, r1, 0
	adds r0, 0x22
	ldr r1, [r4]
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r5]
	adds r6, r0, 0
	adds r6, 0x22
	b _0801FFE2
	.pool
_0801FFE0:
	ldr r6, [r4]
_0801FFE2:
	mov r0, r9
	lsls r1, r0, 8
	movs r0, 0
	movs r2, 0
	bl ChangeBgY
	mov r1, r8
	lsls r0, r1, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	ldr r1, =gUnknown_082F2D40
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0x1
	bne _08020050
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_80989E0
	ldrb r3, [r4, 0x5]
	adds r3, 0x8
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x6]
	adds r0, 0x8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
	b _0802007A
	.pool
_08020050:
	adds r0, r5, 0
	movs r1, 0xA
	movs r2, 0x2
	bl sub_8098858
	ldrb r3, [r4, 0x5]
	ldrb r0, [r4, 0x6]
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x7]
	str r0, [sp, 0xC]
	ldrb r0, [r4, 0x8]
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized5
_0802007A:
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, 0x1E]
_08020082:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801FF18

	thumb_func_start sub_8020094
sub_8020094: @ 8020094
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200B2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_8198070
	ldr r0, [r4]
	ldrb r0, [r0, 0x1E]
	bl ClearWindowTilemap
_080200B2:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020094

	thumb_func_start sub_80200C8
sub_80200C8: @ 80200C8
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r0, [r4]
	ldrh r0, [r0, 0x1E]
	cmp r0, 0xFF
	beq _080200E2
	lsls r0, 24
	lsrs r0, 24
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, 0xFF
	strh r0, [r1, 0x1E]
_080200E2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80200C8

	thumb_func_start sub_80200EC
sub_80200EC: @ 80200EC
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 19
	lsrs r3, 16
	lsls r1, 19
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	movs r0, 0x1
	adds r1, r2, 0
	adds r2, r3, 0
	movs r3, 0x1
	bl FillWindowPixelRect
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_80200EC

	thumb_func_start sub_8020118
sub_8020118: @ 8020118
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r10, r1
	ldr r1, [sp, 0x54]
	lsls r0, 16
	lsrs r5, r0, 16
	mov r9, r5
	lsls r2, 24
	lsrs r4, r2, 24
	mov r8, r4
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0
	beq _08020154
	bl sub_801F198
	adds r1, r0, 0
	subs r1, r5
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_80200EC
_08020154:
	add r0, sp, 0xC
	mov r1, r8
	strb r1, [r0]
	strb r7, [r0, 0x1]
	strb r6, [r0, 0x2]
	add r4, sp, 0x10
	movs r0, 0xFC
	strb r0, [r4]
	movs r0, 0x14
	strb r0, [r4, 0x1]
	movs r0, 0x8
	strb r0, [r4, 0x2]
	mov r0, sp
	adds r0, 0x13
	mov r1, r10
	bl StringCopy
	mov r0, r9
	lsls r2, r0, 27
	lsrs r2, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8020118

	thumb_func_start sub_80201A4
sub_80201A4: @ 80201A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	movs r0, 0x2
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	bl sub_801F0B0
	lsls r0, 24
	lsrs r2, r0, 24
	add r1, sp, 0xC
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xE
	strb r0, [r1, 0x1]
	movs r0, 0xD
	strb r0, [r1, 0x2]
	cmp r2, 0x3
	beq _08020240
	add r1, sp, 0x10
	movs r0, 0xFC
	strb r0, [r1]
	movs r0, 0x14
	strb r0, [r1, 0x1]
	movs r0, 0x8
	strb r0, [r1, 0x2]
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	cmp r2, 0x2
	bne _080201EC
	movs r1, 0x6
	str r1, [sp, 0x40]
_080201EC:
	movs r7, 0
	movs r6, 0
	lsls r0, r2, 2
	ldr r1, =gUnknown_082F2BA8
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldr r0, [sp, 0x40]
	lsls r5, r0, 24
_080201FE:
	ldr r1, [r4]
	cmp r1, 0
	bne _08020206
	b _0802030C
_08020206:
	mov r0, sp
	adds r0, 0x13
	bl StringCopy
	lsls r3, r6, 24
	lsrs r3, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x44]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	lsrs r2, r5, 24
	bl AddTextPrinterParameterized3
	adds r4, 0x4
	adds r7, 0x1
	adds r0, r6, 0
	adds r0, 0xC
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _080201FE
	b _0802030C
	.pool
_08020240:
	movs r1, 0x4
	str r1, [sp, 0x40]
	movs r7, 0
	movs r6, 0
_08020248:
	adds r0, r7, 0
	bl sub_801EE6C
	adds r5, r0, 0
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x28
	bgt _08020286
	lsls r3, r6, 24
	lsrs r3, 24
	add r4, sp, 0xC
	str r4, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r4, 0x80
	lsls r4, 19
	lsrs r2, r4, 24
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	b _08020300
_08020286:
	adds r0, r5, 0
	bl StringLength_Multibyte
	adds r4, r0, 0
	mov r1, sp
	adds r1, 0x10
	str r1, [sp, 0x44]
	ldr r0, [sp, 0x40]
	lsls r0, 24
	mov r8, r0
	lsls r1, r6, 24
	mov r9, r1
	adds r0, r7, 0x1
	str r0, [sp, 0x48]
	adds r6, 0xC
	mov r10, r6
	ldr r7, [sp, 0x40]
	adds r7, 0x23
	ldr r6, [sp, 0x44]
_080202AC:
	subs r4, 0x1
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl StringCopyN_Multibyte
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	cmp r0, 0x23
	bgt _080202AC
	mov r1, r8
	lsrs r2, r1, 24
	mov r0, r9
	lsrs r4, r0, 24
	add r1, sp, 0xC
	str r1, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	str r1, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	adds r2, r7, 0
	add r0, sp, 0xC
	str r0, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	ldr r0, =gText_Ellipsis
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
_08020300:
	ldr r7, [sp, 0x48]
	mov r4, r10
	lsls r0, r4, 16
	lsrs r6, r0, 16
	cmp r7, 0x9
	ble _08020248
_0802030C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80201A4

	thumb_func_start sub_8020320
sub_8020320: @ 8020320
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0x37
	bgt _08020354
	adds r0, r3, 0
	adds r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x37
	ble _08020348
	movs r0, 0x38
	strh r0, [r2, 0x20]
	b _08020354
	.pool
_08020348:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _08020360
_08020354:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_08020360:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020320

	thumb_func_start sub_8020368
sub_8020368: @ 8020368
	push {r4,lr}
	ldr r1, =gUnknown_02022C88
	ldr r2, [r1]
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0
	ble _0802039C
	adds r0, r3, 0
	subs r0, 0xC
	strh r0, [r2, 0x20]
	lsls r0, 16
	cmp r0, 0
	bgt _08020390
	movs r0, 0
	strh r0, [r2, 0x20]
	b _0802039C
	.pool
_08020390:
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	bl sub_80207C0
	movs r0, 0x1
	b _080203A8
_0802039C:
	ldr r0, [r1]
	movs r4, 0x20
	ldrsh r0, [r0, r4]
	bl sub_8020818
	movs r0, 0
_080203A8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020368

	thumb_func_start sub_80203B0
sub_80203B0: @ 80203B0
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD
	bl sub_8098858
	movs r5, 0xE
	str r5, [sp]
	movs r4, 0x5
	str r4, [sp, 0x4]
	ldr r0, =gUnknown_082F2DC8
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0x8
	movs r3, 0x1
	bl PrintTextArray
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	str r5, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x1
	bl sub_81983AC
	movs r0, 0x3
	bl PutWindowTilemap
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80203B0

	thumb_func_start sub_802040C
sub_802040C: @ 802040C
	push {lr}
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	pop {r0}
	bx r0
	thumb_func_end sub_802040C

	thumb_func_start sub_8020420
sub_8020420: @ 8020420
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 24
	add r3, sp, 0xC
	movs r1, 0x1
	strb r1, [r3]
	lsrs r2, 23
	adds r1, r2, 0x2
	strb r1, [r3, 0x1]
	adds r1, r3, 0
	adds r2, 0x3
	strb r2, [r1, 0x2]
	lsls r4, r0, 4
	subs r4, r0
	lsls r3, r4, 16
	lsrs r3, 16
	movs r0, 0xA8
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	add r0, sp, 0xC
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	adds r3, r4, 0
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8020420

	thumb_func_start sub_8020480
sub_8020480: @ 8020480
	push {lr}
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
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0xE0
	lsls r1, 8
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x000040f0
	movs r0, 0x40
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0x3D
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020480

	thumb_func_start sub_8020538
sub_8020538: @ 8020538
	push {r4,lr}
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00000928
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001128
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001928
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020538

	thumb_func_start sub_8020584
sub_8020584: @ 8020584
	push {lr}
	sub sp, 0x8
	movs r1, 0xC0
	lsls r1, 19
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8020584

	thumb_func_start sub_80205B4
sub_80205B4: @ 80205B4
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_08DD4BD0
	movs r1, 0x70
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08DD4BB0
	movs r1, 0xC0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_08DD4BF0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gUnknown_08DD4C4C
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80205B4

	thumb_func_start task_tutorial_story_unknown
task_tutorial_story_unknown: @ 8020604
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gLinkMiscMenu_Pal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gLinkMiscMenu_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r5, r0, 0
	cmp r5, 0
	beq _0802064E
	movs r1, 0x88
	lsls r1, 2
	adds r0, r5, r1
	ldr r4, =gUnknown_02022C88
	ldr r1, [r4]
	ldr r2, =0x00002128
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
	movs r1, 0x84
	lsls r1, 3
	adds r0, r5, r1
	ldr r1, [r4]
	ldr r2, =0x00002148
	adds r1, r2
	movs r2, 0x8
	bl CpuFastSet
_0802064E:
	ldr r1, =gLinkMiscMenu_Tilemap
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_tutorial_story_unknown

	thumb_func_start sub_8020680
sub_8020680: @ 8020680
	push {lr}
	ldr r0, =gUnknown_082F2C20
	movs r1, 0x80
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0x06004020
	movs r0, 0
	movs r2, 0x20
	movs r3, 0x1
	bl RequestDma3Fill
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020680

	thumb_func_start sub_80206A4
sub_80206A4: @ 80206A4
	push {lr}
	ldr r0, =gUnknown_082F2C40
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206A4

	thumb_func_start sub_80206D0
sub_80206D0: @ 80206D0
	push {lr}
	movs r0, 0x2
	bl PutWindowTilemap
	bl sub_80201A4
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_80206D0

	thumb_func_start sub_80206E8
sub_80206E8: @ 80206E8
	push {r4,lr}
	sub sp, 0xC
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xFF
	strb r0, [r1, 0x1]
	movs r4, 0
_080206F8:
	ldr r0, =gUnknown_02022C88
	ldr r1, [r0]
	ldr r0, =0x00002128
	adds r1, r0
	lsls r2, r4, 19
	lsrs r2, 16
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r3, 0
	bl BlitBitmapToWindow
	adds r4, 0x1
	cmp r4, 0xE
	ble _080206F8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80206E8

	thumb_func_start sub_8020740
sub_8020740: @ 8020740
	push {lr}
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0x3
	movs r1, 0xA
	movs r2, 0x20
	bl LoadUserWindowBorderGfx_
	ldr r0, =gUnknown_0860F074
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020740

	thumb_func_start sub_8020770
sub_8020770: @ 8020770
	push {lr}
	sub sp, 0x10
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	ldr r0, =0x04000014
	str r0, [sp]
	mov r2, sp
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	mov r0, sp
	strb r1, [r0, 0x9]
	ldr r0, =gUnknown_02022C88
	ldr r0, [r0]
	strh r1, [r0, 0x20]
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	ldr r1, =gScanlineEffectRegBuffers
	ldr r2, =0x010003c0
	bl CpuFastSet
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020770

	thumb_func_start sub_80207C0
sub_80207C0: @ 80207C0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	ldr r5, =gScanlineEffect
	ldrb r0, [r5, 0x14]
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 7
	ldr r4, =gScanlineEffectRegBuffers
	adds r1, r4
	ldr r2, =0x01000090
	mov r0, sp
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r1, 0
	strh r1, [r0]
	ldrb r2, [r5, 0x14]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 7
	movs r2, 0x90
	lsls r2, 1
	adds r4, r2
	adds r1, r4
	ldr r2, =0x01000010
	bl CpuSet
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80207C0

	thumb_func_start sub_8020818
sub_8020818: @ 8020818
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, sp
	strh r4, [r0]
	ldr r5, =gScanlineEffectRegBuffers
	ldr r0, =0x01000090
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	movs r6, 0
	strh r6, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r1, r5, r2
	ldr r2, =0x01000010
	mov r8, r2
	bl CpuSet
	add r0, sp, 0x4
	strh r4, [r0]
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r5, r2
	mov r2, r9
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	movs r1, 0x8A
	lsls r1, 4
	adds r5, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020818

	thumb_func_start sub_8020890
sub_8020890: @ 8020890
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gUnknown_082F3134
_08020896:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	bls _08020896
	ldr r0, =gUnknown_082F315C
	bl LoadSpritePalette
	ldr r4, =gUnknown_02022C8C
	movs r0, 0x18
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _080208C8
	movs r0, 0x1
	b _080208CA
	.pool
_080208C8:
	movs r0, 0
_080208CA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8020890

	thumb_func_start sub_80208D0
sub_80208D0: @ 80208D0
	push {lr}
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	cmp r0, 0
	beq _080208DE
	bl Free
_080208DE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208D0

	thumb_func_start sub_80208E8
sub_80208E8: @ 80208E8
	push {lr}
	ldr r0, =gUnknown_082F319C
	movs r1, 0xA
	movs r2, 0x18
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C8C
	ldr r2, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80208E8

	thumb_func_start sub_802091C
sub_802091C: @ 802091C
	ldr r1, =gUnknown_02022C8C
	ldr r1, [r1]
	ldr r2, [r1]
	adds r2, 0x3E
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_802091C

	thumb_func_start sub_802093C
sub_802093C: @ 802093C
	push {r4,r5,lr}
	sub sp, 0x4
	bl sub_801F0B0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r5, sp
	adds r5, 0x1
	mov r0, sp
	adds r1, r5, 0
	bl sub_801F0BC
	cmp r4, 0x3
	beq _0802097C
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	ldr r1, [r4]
	ldr r2, [r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0xA
	strh r0, [r2, 0x20]
	ldr r2, [r1]
	b _08020992
	.pool
_0802097C:
	ldr r4, =gUnknown_02022C8C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r2, [r4]
	ldr r1, [r2]
	movs r0, 0x18
	strh r0, [r1, 0x20]
	ldr r2, [r2]
_08020992:
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x18
	strh r0, [r2, 0x22]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802093C

	thumb_func_start sub_80209AC
sub_80209AC: @ 80209AC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 2
	ldr r0, =gUnknown_082F2DF0+2
	adds r4, r0
	movs r0, 0
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	ldr r0, =0x01010000
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x4
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209E0
sub_80209E0: @ 80209E0
	push {lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A00
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _08020A0C
	.pool
_08020A00:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
_08020A0C:
	ldr r0, =gUnknown_02022C8C
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x14]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80209E0

	thumb_func_start sub_8020A1C
sub_8020A1C: @ 8020A1C
	push {r4,lr}
	ldr r4, =gUnknown_02022C8C
	ldr r1, [r4]
	ldrh r0, [r1, 0x14]
	cmp r0, 0x3
	bls _08020A30
_08020A28:
	movs r0, 0
	b _08020A62
	.pool
_08020A30:
	adds r0, 0x1
	strh r0, [r1, 0x14]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bls _08020A60
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08020A54
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	b _08020A28
_08020A54:
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
	b _08020A28
_08020A60:
	movs r0, 0x1
_08020A62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8020A1C

	thumb_func_start sub_8020A68
sub_8020A68: @ 8020A68
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F31BC
	movs r1, 0x4C
	movs r2, 0x98
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0x8]
	ldr r0, =gUnknown_082F31D4
	movs r1, 0x40
	movs r2, 0x98
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020A68

	thumb_func_start sub_8020ABC
sub_8020ABC: @ 8020ABC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_801F198
	adds r3, r0, 0
	cmp r3, 0xF
	bne _08020AD8
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08020AEC
_08020AD8:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	lsls r0, r3, 3
	adds r0, 0x4C
	strh r0, [r4, 0x20]
_08020AEC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020ABC

	thumb_func_start sub_8020AF4
sub_8020AF4: @ 8020AF4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x2E]
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _08020B1A
	strh r2, [r1, 0x24]
_08020B1A:
	pop {r0}
	bx r0
	thumb_func_end sub_8020AF4

	thumb_func_start sub_8020B20
sub_8020B20: @ 8020B20
	push {r4,r5,lr}
	ldr r0, =gUnknown_082F322C
	movs r1, 0x8
	movs r2, 0x98
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_02022C8C
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2, 0xC]
	ldr r0, =gUnknown_082F3244
	movs r1, 0x20
	movs r2, 0x98
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r2, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B20

	thumb_func_start sub_8020B80
sub_8020B80: @ 8020B80
	push {r4,lr}
	bl sub_801F0B0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _08020BB8
	bl sub_801F0DC
	cmp r0, 0
	beq _08020BC2
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	movs r1, 0x3
	bl StartSpriteAnim
	b _08020BF6
	.pool
_08020BB8:
	bl sub_801F1A4
	adds r4, r0, 0
	cmp r4, 0x3
	bne _08020BD8
_08020BC2:
	ldr r0, =gUnknown_02022C8C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	b _08020BF6
	.pool
_08020BD8:
	ldr r3, =gUnknown_02022C8C
	ldr r0, [r3]
	ldr r1, [r0, 0x10]
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, 0x10]
	lsls r1, r4, 24
	lsrs r1, 24
	bl StartSpriteAnim
_08020BF6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8020B80

	.align 2, 0 @ don't pad with nop
