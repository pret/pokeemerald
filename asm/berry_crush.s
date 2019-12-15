	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8023BC0
sub_8023BC0: @ 8023BC0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _08023C04
	cmp r0, 0x1
	bgt _08023BD8
	cmp r0, 0
	beq _08023BE2
	b _08023C9C
_08023BD8:
	cmp r0, 0x2
	beq _08023C2A
	cmp r0, 0x3
	beq _08023C5C
	b _08023C9C
_08023BE2:
	movs r0, 0x9
	strh r0, [r5, 0x12]
	movs r0, 0x20
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x8
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	strb r0, [r1]
	b _08023C9C
_08023C04:
	movs r0, 0x9C
	lsls r0, 1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08023CA2
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	movs r2, 0x1F
	bl BlendPalettes
	movs r0, 0
	strb r0, [r4]
	b _08023C9C
_08023C2A:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_80218D4
	cmp r0, 0
	beq _08023CA2
	bl sub_8010434
	movs r0, 0
	strh r0, [r5, 0x10]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	b _08023C9C
_08023C5C:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08023CA2
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x7
	movs r2, 0x1
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x10]
	b _08023CA0
	.pool
_08023C9C:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08023CA0:
	strb r0, [r5, 0xC]
_08023CA2:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8023BC0

	thumb_func_start sub_8023CAC
sub_8023CAC: @ 8023CAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r0, 0
	ldrb r0, [r7, 0xC]
	cmp r0, 0x7
	bls _08023CC2
	b _0802402E
_08023CC2:
	lsls r0, 2
	ldr r1, =_08023CD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08023CD0:
	.4byte _08023CF0
	.4byte _08023D2A
	.4byte _08023D38
	.4byte _08023DA0
	.4byte _08023F20
	.4byte _08023FD0
	.4byte _08023FDC
	.4byte _08024010
_08023CF0:
	adds r4, r7, 0
	adds r4, 0x42
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x4
	bl memset
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r2, r0, 0
	adds r2, 0xB2
	ldrh r1, [r7, 0x28]
	ldrh r0, [r2]
	cmp r0, r1
	bls _08023D12
	strh r1, [r2]
_08023D12:
	ldrb r0, [r7, 0x8]
	lsls r0, 5
	adds r0, r7, r0
	adds r0, 0xB2
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl SendBlock
	b _0802402E
_08023D2A:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	bne _08023D36
	b _08024034
_08023D36:
	b _08024004
_08023D38:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r7, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _08023D50
	b _08024034
_08023D50:
	movs r0, 0
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x42
	cmp r8, r3
	bcs _08023D7E
	ldr r2, =gBlockRecvBuffer
_08023D5E:
	mov r3, r8
	lsls r1, r3, 5
	adds r1, r7, r1
	lsls r0, r3, 8
	adds r0, r2
	ldrh r0, [r0]
	adds r1, 0xB2
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r6, [r7, 0x9]
	cmp r8, r6
	bcc _08023D5E
_08023D7E:
	movs r0, 0
	strh r0, [r7, 0x10]
	strh r0, [r4]
	bl ResetBlockReceivedFlags
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _08023D9C
	movs r0, 0x3
	b _08024032
	.pool
_08023D9C:
	movs r0, 0x6
	b _08024032
_08023DA0:
	adds r0, r7, 0
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldrh r1, [r7, 0x28]
	adds r0, r7, 0
	adds r0, 0x6C
	strh r1, [r0]
	movs r0, 0x18
	ldrsh r4, [r7, r0]
	ldrh r0, [r7, 0x28]
	movs r1, 0x3C
	bl __udivsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl __divsi3
	adds r1, r7, 0
	adds r1, 0x6E
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r7, r1]
	lsls r0, 8
	movs r4, 0xC8
	lsls r4, 6
	adds r1, r4, 0
	bl sub_8151574
	adds r2, r0, 0
	movs r3, 0x32
	ldrsh r1, [r7, r3]
	lsls r1, 8
	bl sub_81515FC
	adds r2, r0, r4
	asrs r2, 8
	movs r1, 0x7F
	adds r0, r2, 0
	ands r0, r1
	adds r1, r7, 0
	adds r1, 0x70
	strh r0, [r1]
	lsls r2, 8
	movs r1, 0xC8
	lsls r1, 7
	adds r0, r2, 0
	bl sub_81515FC
	adds r2, r0, 0
	ldrb r1, [r7, 0x9]
	ldr r0, [r7, 0x1C]
	muls r0, r1
	lsls r4, r0, 8
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_8151574
	adds r4, r0, 0
	asrs r0, r4, 8
	str r0, [r7, 0x68]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r1, r7, 0
	adds r1, 0x8F
	strb r0, [r1]
	movs r6, 0
	mov r8, r6
	mov r9, r1
	ldrb r0, [r7, 0x9]
	cmp r8, r0
	bcc _08023E44
	b _0802402E
_08023E44:
	adds r0, r7, 0
	adds r0, 0x88
	add r0, r8
	mov r1, r8
	strb r1, [r0]
	adds r0, r7, 0
	adds r0, 0x90
	add r0, r8
	strb r1, [r0]
	mov r3, r8
	lsls r2, r3, 1
	adds r1, r7, 0
	adds r1, 0x74
	adds r1, r2
	lsls r0, r3, 5
	adds r3, r7, r0
	adds r5, r3, 0
	adds r5, 0xAE
	ldrh r0, [r5]
	strh r0, [r1]
	adds r1, r7, 0
	adds r1, 0x72
	ldrh r6, [r1]
	adds r0, r6
	strh r0, [r1]
	mov r1, r9
	ldrb r0, [r1]
	adds r6, r2, 0
	cmp r0, 0x1
	beq _08023EAE
	cmp r0, 0x1
	bgt _08023E8A
	cmp r0, 0
	beq _08023E90
	b _08023F04
_08023E8A:
	cmp r0, 0x2
	beq _08023ECC
	b _08023F04
_08023E90:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xAC
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023EAE:
	ldrh r0, [r5]
	cmp r0, 0
	beq _08023ED2
	adds r0, r3, 0
	adds r0, 0xB0
	ldrh r2, [r0]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r5]
	b _08023EFA
_08023ECC:
	ldrh r0, [r5]
	cmp r0, 0
	bne _08023ED6
_08023ED2:
	movs r4, 0
	b _08023F04
_08023ED6:
	adds r1, r3, 0
	adds r1, 0xB2
	ldrh r0, [r1]
	ldrh r2, [r7, 0x28]
	cmp r0, r2
	bcc _08023EE8
	movs r4, 0xC8
	lsls r4, 7
	b _08023F04
_08023EE8:
	ldrh r2, [r1]
	lsls r2, 8
	adds r0, r2, 0
	movs r1, 0xC8
	lsls r1, 7
	bl sub_8151574
	adds r2, r0, 0
	ldrh r4, [r7, 0x28]
_08023EFA:
	lsls r4, 8
	adds r1, r4, 0
	bl sub_81515FC
	adds r4, r0, 0
_08023F04:
	asrs r4, 4
	adds r0, r7, 0
	adds r0, 0x7E
	adds r0, r6
	strh r4, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r7, 0x9]
	cmp r8, r3
	bcc _08023E44
	b _0802402E
_08023F20:
	movs r6, 0
	mov r8, r6
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	adds r1, r7, 0
	adds r1, 0x68
	str r1, [sp, 0xC]
	cmp r8, r0
	bge _08023FC4
_08023F32:
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r2, r8
	adds r2, 0x1
	str r2, [sp, 0x8]
	cmp r4, r8
	bls _08023FB4
	adds r3, r7, 0
	adds r3, 0x74
	str r3, [sp]
	adds r6, r7, 0
	adds r6, 0x88
	str r6, [sp, 0x4]
	movs r0, 0x90
	adds r0, r7
	mov r10, r0
	movs r1, 0x7E
	adds r1, r7
	mov r9, r1
_08023F5C:
	subs r2, r4, 0x1
	mov r12, r2
	lsls r6, r2, 1
	ldr r0, [sp]
	adds r3, r0, r6
	lsls r5, r4, 1
	adds r1, r0, r5
	ldrh r2, [r3]
	ldrh r0, [r1]
	cmp r2, r0
	bcs _08023F86
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	ldr r1, [sp, 0x4]
	adds r2, r1, r4
	ldrb r3, [r2]
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023F86:
	mov r2, r9
	adds r3, r2, r6
	adds r1, r2, r5
	ldrh r2, [r3]
	ldrh r6, [r1]
	cmp r2, r6
	bcs _08023FAA
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	mov r0, r10
	adds r2, r0, r4
	ldrb r3, [r2]
	mov r1, r10
	add r1, r12
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023FAA:
	mov r1, r12
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r4, r8
	bhi _08023F5C
_08023FB4:
	ldr r2, [sp, 0x8]
	lsls r0, r2, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r7, 0x9]
	subs r0, 0x1
	cmp r8, r0
	blt _08023F32
_08023FC4:
	movs r0, 0
	ldr r1, [sp, 0xC]
	movs r2, 0x30
	bl SendBlock
	b _0802402E
_08023FD0:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _08024034
	b _08024004
_08023FDC:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08024034
	adds r4, r7, 0
	adds r4, 0x68
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r1, =gBlockRecvBuffer
	adds r0, r4, 0
	movs r2, 0x30
	bl memcpy
	bl ResetBlockReceivedFlags
_08024004:
	movs r0, 0
	strh r0, [r7, 0x10]
	b _0802402E
	.pool
_08024010:
	bl sub_8020E58
	movs r0, 0x12
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	movs r1, 0xB
	strh r1, [r7, 0x12]
	strb r0, [r7, 0xC]
	adds r1, r7, 0
	adds r1, 0x24
	strb r0, [r1]
	b _08024034
_0802402E:
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
_08024032:
	strb r0, [r7, 0xC]
_08024034:
	movs r0, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8023CAC

	thumb_func_start sub_8024048
sub_8024048: @ 8024048
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024124
	lsls r0, 2
	ldr r1, =_08024064
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024064:
	.4byte _08024078
	.4byte _0802408A
	.4byte _0802409C
	.4byte _080240CC
	.4byte _080240DC
_08024078:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	adds r0, r5, 0
	bl sub_8022070
	cmp r0, 0
	bne _08024124
	b _0802412A
_0802408A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1E
	strb r0, [r1]
	b _08024124
_0802409C:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080240AE
	subs r0, 0x1
	strb r0, [r1]
	b _0802412A
_080240AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0802412A
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_802222C
	b _08024124
	.pool
_080240CC:
	ldrh r0, [r5, 0x12]
	cmp r0, 0xC
	bhi _08024124
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802412A
_080240DC:
	ldr r0, =gStringVar1
	ldr r1, [r5, 0x1C]
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	bl GetBerryPowder
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x3
	movs r3, 0
	bl sub_8024644
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802412A
	.pool
_08024124:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802412A:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024048

	thumb_func_start sub_8024134
sub_8024134: @ 8024134
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x4
	bhi _08024218
	lsls r0, 2
	ldr r1, =_08024150
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08024150:
	.4byte _08024164
	.4byte _080241A0
	.4byte _080241A6
	.4byte _080241F0
	.4byte _08024204
_08024164:
	ldrh r1, [r5, 0x28]
	ldr r0, =0x00008c9f
	cmp r1, r0
	bls _08024176
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r5, r1
	bl sub_8022554
_08024176:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r4, 0
	movs r0, 0x13
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802421E
	.pool
_080241A0:
	bl sub_8010434
	b _08024218
_080241A6:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802421E
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized2
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _08024218
	.pool
_080241F0:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	beq _08024218
	b _0802421E
	.pool
_08024204:
	movs r0, 0x14
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r1, 0
	movs r0, 0xF
	strh r0, [r5, 0x12]
	strb r1, [r5, 0xC]
	b _0802421E
_08024218:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802421E:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024134

	thumb_func_start sub_8024228
sub_8024228: @ 8024228
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r0, [r5, 0xC]
	cmp r0, 0x1
	beq _0802426A
	cmp r0, 0x1
	bgt _08024240
	cmp r0, 0
	beq _08024246
	b _080242D0
_08024240:
	cmp r0, 0x2
	beq _08024270
	b _080242D0
_08024246:
	movs r0, 0x1
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0x4
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x14
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strb r0, [r5, 0xC]
	b _080242D8
_0802426A:
	bl DisplayYesNoMenuDefaultYes
	b _080242D0
_08024270:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _080242D6
	adds r0, r5, 0
	adds r0, 0x42
	movs r1, 0
	movs r2, 0xC
	bl memset
	cmp r4, 0
	bne _080242A2
	bl HasAtLeastOneBerry
	lsls r0, 24
	cmp r0, 0
	beq _0802429E
	strh r4, [r5, 0x14]
	b _080242A6
_0802429E:
	movs r0, 0x3
	b _080242A4
_080242A2:
	movs r0, 0x1
_080242A4:
	strh r0, [r5, 0x14]
_080242A6:
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_8024644
	movs r0, 0x15
	strb r0, [r5, 0xE]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080242D6
_080242D0:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080242D6:
	movs r0, 0
_080242D8:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8024228

	thumb_func_start sub_80242E0
sub_80242E0: @ 80242E0
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrb r0, [r4, 0xC]
	cmp r0, 0x1
	beq _08024306
	cmp r0, 0x1
	bgt _080242F6
	cmp r0, 0
	beq _08024300
	b _080243AC
_080242F6:
	cmp r0, 0x2
	beq _08024328
	cmp r0, 0x3
	beq _08024336
	b _080243AC
_08024300:
	bl sub_8010434
	b _080243AC
_08024306:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	ldrh r0, [r4, 0x14]
	adds r1, r4, 0
	adds r1, 0x42
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4E
	strh r5, [r0]
	movs r0, 0
	movs r2, 0x2
	bl SendBlock
	b _080243AC
_08024328:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _080243B2
	strh r5, [r4, 0x10]
	b _080243AC
_08024336:
	bl GetBlockReceivedStatus
	ldr r2, =gUnknown_082F4448
	ldrb r3, [r4, 0x9]
	subs r1, r3, 0x2
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _080243B2
	adds r7, r4, 0
	adds r7, 0x42
	adds r6, r4, 0
	adds r6, 0x4E
	cmp r5, r3
	bcs _08024374
	adds r1, r6, 0
	ldr r2, =gBlockRecvBuffer
_0802435C:
	lsls r0, r5, 8
	adds r0, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r4, 0x9]
	cmp r5, r0
	bcc _0802435C
_08024374:
	ldrh r0, [r6]
	cmp r0, 0
	beq _08024390
	movs r0, 0x17
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	b _0802439A
	.pool
_08024390:
	movs r0, 0x16
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
_0802439A:
	bl ResetBlockReceivedFlags
	movs r1, 0
	movs r0, 0
	strh r0, [r7]
	strh r0, [r6]
	strh r0, [r4, 0x10]
	strb r1, [r4, 0xC]
	b _080243B4
_080243AC:
	ldrb r0, [r4, 0xC]
	adds r0, 0x1
	strb r0, [r4, 0xC]
_080243B2:
	movs r0, 0
_080243B4:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80242E0

	thumb_func_start sub_80243BC
sub_80243BC: @ 80243BC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080243EA
	cmp r4, 0x1
	bgt _080243D2
	cmp r4, 0
	beq _080243DC
	b _08024434
_080243D2:
	cmp r4, 0x2
	beq _080243F6
	cmp r4, 0x3
	beq _0802441A
	b _08024434
_080243DC:
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	b _08024410
_080243EA:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _08024434
	b _0802443A
_080243F6:
	movs r0, 0
	movs r1, 0x1
	bl ClearDialogWindowAndFrame
	adds r0, r5, 0
	bl sub_8021488
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
_08024410:
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _08024434
_0802441A:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0802443A
	movs r0, 0x7
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	movs r0, 0
	strh r4, [r5, 0x12]
	b _08024438
_08024434:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
_08024438:
	strb r0, [r5, 0xC]
_0802443A:
	movs r0, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80243BC

	thumb_func_start sub_8024444
sub_8024444: @ 8024444
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _080244BC
	cmp r4, 0x1
	bgt _0802445A
	cmp r4, 0
	beq _08024460
	b _080244F6
_0802445A:
	cmp r4, 0x2
	beq _080244D4
	b _080244F6
_08024460:
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldrh r1, [r5, 0x14]
	cmp r1, 0x3
	bne _08024490
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x14]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
	b _080244AC
	.pool
_08024490:
	ldr r0, =gUnknown_082F32A4
	ldr r2, [r0, 0x18]
	ldrb r3, [r5, 0xB]
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParameterized2
_080244AC:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _080244F6
	.pool
_080244BC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080244FC
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x78
	strb r0, [r1]
	b _080244F6
_080244D4:
	movs r0, 0x9C
	lsls r0, 1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, 0
	cmp r4, 0
	beq _080244E8
	subs r0, 0x1
	strb r0, [r1]
	b _080244FC
_080244E8:
	movs r0, 0x18
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _080244FC
_080244F6:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_080244FC:
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024444

	thumb_func_start sub_8024508
sub_8024508: @ 8024508
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r4, [r5, 0xC]
	cmp r4, 0x1
	beq _08024528
	cmp r4, 0x1
	bgt _0802451C
	cmp r4, 0
	beq _08024522
	b _08024558
_0802451C:
	cmp r4, 0x2
	beq _08024538
	b _08024558
_08024522:
	bl sub_8010434
	b _08024558
_08024528:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0802455E
	bl sub_800AC34
	b _08024558
_08024538:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802455E
	movs r0, 0x19
	strb r0, [r5, 0xE]
	movs r0, 0x5
	movs r1, 0x1
	movs r2, 0
	bl sub_8022BEC
	strb r4, [r5, 0xC]
	b _0802455E
	.pool
_08024558:
	ldrb r0, [r5, 0xC]
	adds r0, 0x1
	strb r0, [r5, 0xC]
_0802455E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024508

	thumb_func_start sub_8024568
sub_8024568: @ 8024568
	push {lr}
	movs r0, 0
	bl sub_8020C0C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8024568

	thumb_func_start sub_8024578
sub_8024578: @ 8024578
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r0, 0x33
	bl IncrementGameStat
	strb r5, [r4, 0xD]
	movs r1, 0
	strh r5, [r4, 0x10]
	movs r0, 0x2
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	str r5, [r4, 0x1C]
	strh r5, [r4, 0x18]
	strh r5, [r4, 0x1A]
	str r5, [r4, 0x20]
	adds r0, r4, 0
	adds r0, 0x24
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x25
	movs r0, 0
	strb r0, [r1]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x28]
	strh r5, [r4, 0x2E]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x32]
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x34]
	movs r6, 0
	movs r3, 0
_080245B8:
	lsls r0, r5, 5
	adds r2, r4, r0
	adds r1, r2, 0
	adds r1, 0xA4
	ldr r0, =0x0000ffff
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA6
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r1, 0x6
	movs r0, 0x1
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0xAC
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strh r3, [r0]
	adds r0, 0x2
	strb r6, [r0]
	adds r0, 0x1
	strb r6, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080245B8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024578

	thumb_func_start sub_8024604
sub_8024604: @ 8024604
	push {r4-r6,lr}
	sub sp, 0x8
	str r2, [sp, 0x4]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	ldr r4, [sp, 0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, 0x4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, 0x1]
	strb r2, [r0, 0x1]
	ldrb r2, [r4, 0x2]
	strb r2, [r0, 0x2]
	ldrb r2, [r4, 0x3]
	strb r2, [r0, 0x3]
	strb r3, [r0, 0x4]
	strb r5, [r0, 0x5]
	strb r6, [r0, 0x6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, 0x7]
	mov r2, sp
	ldrb r2, [r2, 0x1]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8024604

	thumb_func_start sub_8024644
sub_8024644: @ 8024644
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, [sp, 0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, 0x1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x2]
	mov r1, sp
	ldrb r1, [r1, 0x1]
	strb r1, [r0, 0x3]
	strb r5, [r0, 0x4]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8024644

	.align 2, 0 @ don't pad with nop
