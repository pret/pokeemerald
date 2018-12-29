	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/misc_constants.inc"

	.syntax unified

	.text

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
	bl IsLinkTaskFinished
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
	bl IsLinkTaskFinished
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
	bl IsLinkTaskFinished
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
	bl IsLinkTaskFinished
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
